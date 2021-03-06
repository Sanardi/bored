;EasyCodeName=ECPDriver,1
ECDrvName			equ		'ECPDriver'

section '.data' data readable writeable

pNT_DEVICE_NAME		du		'\Device\', ECDrvName, 0
pDOS_DEVICE_NAME	du		'\DosDevices\', ECDrvName, 0

struct DEVICE_EXTENSION
	;This structure is driver-defined.
	;It must be filled depending on
	;the driver to be programmed.

	;Until filled with necessary
	;data, define a DD value in
	;order to avoid compile errors
    dd		0
ends

section '.text' code readable executable

proc DriverEntry pDriverObject:DWORD, pusRegistryPath:DWORD
	local usDeviceName:UNICODE_STRING, usSymbolicLinkName:UNICODE_STRING
	local pDeviceObject:DWORD

	invoke RtlInitUnicodeString, addr usDeviceName, addr pNT_DEVICE_NAME
	invoke RtlInitUnicodeString, addr usSymbolicLinkName, addr pDOS_DEVICE_NAME

	invoke IoCreateDevice, [pDriverObject], sizeof.DEVICE_EXTENSION, addr usDeviceName, \
							FILE_DEVICE_UNKNOWN, 0, TRUE, addr pDeviceObject
	.if eax <> STATUS_SUCCESS
		mov eax, STATUS_DEVICE_CONFIGURATION_ERROR
@@:		ret
	.endif

	invoke IoCreateSymbolicLink, addr usSymbolicLinkName, addr usDeviceName
	.if eax <> STATUS_SUCCESS
		invoke IoDeleteDevice, [pDriverObject]
		mov eax, STATUS_DEVICE_CONFIGURATION_ERROR
		jmp @b
	.endif
	mov eax, [pDriverObject]
	lea ecx, [DriverUnload]
	mov [eax + DRIVER_OBJECT.DriverUnload], ecx

	lea ecx, [DriverDispatch]
	mov [eax + DRIVER_OBJECT.MajorFunction + (IRP_MJ_CREATE * 4)], ecx
	mov [eax + DRIVER_OBJECT.MajorFunction + (IRP_MJ_CLOSE * 4)], ecx
	mov [eax + DRIVER_OBJECT.MajorFunction + (IRP_MJ_DEVICE_CONTROL * 4)], ecx
	mov [eax + DRIVER_OBJECT.MajorFunction + (IRP_MJ_READ * 4)], ecx
	mov [eax + DRIVER_OBJECT.MajorFunction + (IRP_MJ_WRITE * 4)], ecx

	mov eax, STATUS_SUCCESS
	jmp @b
endp

proc DriverUnload pDriverObject:DWORD
	local usSymbolicLinkName:UNICODE_STRING

	invoke RtlInitUnicodeString, addr usSymbolicLinkName, addr pDOS_DEVICE_NAME
	invoke IoDeleteSymbolicLink, addr usSymbolicLinkName

	mov eax, [pDriverObject]
	invoke IoDeleteDevice, [eax + DRIVER_OBJECT.DeviceObject]
	ret
endp

proc DriverDispatch pDeviceObject:DWORD, pIrp:DWORD
	local Status:DWORD, Info:DWORD, IO_S_L:DWORD
	local RBufPtr:DWORD           ; Buffer
	local RBufLen:DWORD           ; Buffer Len

    mov [Status], STATUS_SUCCESS
	mov [Info], 0H
	mov eax, [pIrp]
	mov eax, [eax + _IRP.Tail.Overlay.CurrentStackLocation]
	mov [IO_S_L], eax

	movzx eax, BYTE [eax + IO_STACK_LOCATION.MajorFunction]

	.if (eax = IRP_MJ_CREATE | eax = IRP_MJ_CLOSE | eax = IRP_MJ_DEVICE_CONTROL | eax = IRP_MJ_WRITE)
		mov [Status], STATUS_SUCCESS
	.elseif (eax = IRP_MJ_READ)
		mov edx, [pIrp]
		mov eax, [edx + _IRP.UserBuffer]                 ; Buff Ptr
		mov [RBufPtr], eax
		mov edx, [IO_S_L]
		mov eax, [edx + IO_STACK_LOCATION.Parameters.Read.dwLength] ; READ Out Buff Len
		mov [RBufLen], eax
		mov ecx, eax
		mov edx, [RBufPtr]
		xor eax, eax
@@:		cmp ecx, 0
		jle @f
		mov [edx], al
		inc edx
		dec ecx
		jmp @b
@@:		stdcall GetProcess, [RBufPtr], [RBufLen]
		mov [Info], eax ; RBufLen
		mov [Status], STATUS_SUCCESS
	.else
		mov eax, STATUS_NOT_IMPLEMENTED
		mov [Status], eax
	.endif
	mov edx, [pIrp]
	mov eax, [Status]
	mov [edx + _IRP.IoStatus.Status], eax
	mov eax, [Info]
	mov [edx + _IRP.IoStatus.Information], eax
	invoke IoCompleteRequest, [pIrp], IO_NO_INCREMENT
	mov eax, [Status]
	ret
endp

proc GetProcess RBufPtr:DWORD, RBufLen:DWORD
	local BufLenReq:DWORD, BufLen:DWORD, BufPtr:DWORD
	local Result:DWORD

	mov [Result], -1
	mov [BufLenReq], 0
	invoke ZwQuerySystemInformation, SystemProcessInformation, NULL, NULL, addr BufLenReq
	cmp [BufLenReq], 0
	je @f
	mov [BufLenReq], 32768
@@:	shl [BufLenReq], 1    ;BufLenReq * 2 (Por seguridad)
	mov eax, [BufLenReq]
	mov [BufLen], eax
	invoke ExAllocatePool, NonPagedPool, [BufLen]
	.if eax <> 0
		mov [BufPtr], eax
		invoke ZwQuerySystemInformation, SystemProcessInformation, [BufPtr], [BufLen], addr BufLenReq
		.if eax = STATUS_INFO_LENGTH_MISMATCH

		.elseif eax <> 0

		.else
			mov eax, [BufLenReq]
			.if eax < [RBufLen]
				mov [Result], eax
				invoke RtlMoveMemory, [RBufPtr], [BufPtr], [BufLenReq]
			.endif
		.endif
		invoke ExFreePool, [BufPtr]
	.endif
	mov eax, [Result]
	ret
endp

section '.reloc' fixups data readable discardable
