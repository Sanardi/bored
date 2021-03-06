;EasyCodeName=ECDrv64,1
;EasyCodeName=ECDrv64,1
ECDrvName			equ		'ECDrv64'

section '.data' data readable writeable notpageable

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

proc DriverEntry pDriverObject:QWORD, pusRegistryPath:QWORD
	local usDeviceName:UNICODE_STRING, usSymbolicLinkName:UNICODE_STRING
	local pDeviceObject:QWORD

	mov [pDriverObject], rcx
	mov [pusRegistryPath], rdx

	invoke RtlInitUnicodeString, addr usDeviceName, addr pNT_DEVICE_NAME
	invoke RtlInitUnicodeString, addr usSymbolicLinkName, addr pDOS_DEVICE_NAME

	invoke IoCreateDevice, [pDriverObject], sizeof.DEVICE_EXTENSION, addr usDeviceName, \
							FILE_DEVICE_UNKNOWN, 0, TRUE, addr pDeviceObject
	.if rax <> STATUS_SUCCESS
		fastcall MakeBeep, 500
		mov rax, STATUS_DEVICE_CONFIGURATION_ERROR
		jmp @f
	.endif

	invoke IoCreateSymbolicLink, addr usSymbolicLinkName, addr usDeviceName
	.if rax <> STATUS_SUCCESS
		invoke IoDeleteDevice, [pDriverObject]
		fastcall MakeBeep, 400
		mov rax, STATUS_DEVICE_CONFIGURATION_ERROR
		jmp @f
	.endif
	mov rax, [pDriverObject]
    lea rcx, [DriverUnload]
	mov [rax + DRIVER_OBJECT.DriverUnload], rcx

	lea rcx, [DriverCreate]
	mov [rax + DRIVER_OBJECT.MajorFunction + IRP_MJ_CREATE * 8], rcx
	lea rcx, [DriverRead]
	mov [rax + DRIVER_OBJECT.MajorFunction + IRP_MJ_READ * 8], rcx

	mov rax, STATUS_SUCCESS
@@:	ret
endp

proc DriverUnload pDriverObject:QWORD  ;:PDRIVER_OBJECT
	local usSymbolicLinkName2:UNICODE_STRING

	mov [pDriverObject], rcx

	invoke RtlInitUnicodeString, addr usSymbolicLinkName2, addr pDOS_DEVICE_NAME
	invoke IoDeleteSymbolicLink, addr usSymbolicLinkName2

	fastcall MakeBeep, 1000

	mov rax, [pDriverObject]
	invoke IoDeleteDevice, [rax + DRIVER_OBJECT.DeviceObject]
	ret
endp

proc DriverCreate pDeviceObject:QWORD, ppIRP:QWORD
	local Status:DWORD, Info:QWORD

	mov [pDeviceObject], rcx
	mov [ppIRP], rdx

	;--------------------------
	fastcall MakeBeep, 800
	;--------------------------
	mov [Status], STATUS_SUCCESS
	mov [Info], 0H
	mov rdx, [ppIRP] 
	mov eax, [Status]
	mov [rdx + _IRP.IoStatus.Status], eax
	mov [rdx + 30H], rax
	mov rax, [Info]
	mov [rdx + _IRP.IoStatus.Information], rax
	mov [rdx + 38H], rax
	invoke IoCompleteRequest, [ppIRP], IO_NO_INCREMENT 
	mov eax, [Status]
	ret
endp

proc DriverRead pDeviceObject:QWORD, ppIRP:QWORD
	local Status:DWORD, Info:QWORD

	mov [pDeviceObject], rcx
	mov [ppIRP], rdx

	;--------------------------
	fastcall MakeBeep, 1200
	;--------------------------
	mov [Status], STATUS_SUCCESS
	mov [Info], 0H
	mov rdx, [ppIRP] 
	mov eax, [Status]
	mov [rdx + _IRP.IoStatus.Status], eax
	mov rax, [Info]
	mov [rdx + _IRP.IoStatus.Information], rax
	invoke IoCompleteRequest, [ppIRP], IO_NO_INCREMENT 
	mov eax, [Status]
	ret
endp

proc MakeBeep uses rcx, Freq:QWORD
	mov [Freq], rcx

	invoke HalMakeBeep, [Freq]
	mov rax, 100000000
@@:	dec rax
	jnz @b
	invoke HalMakeBeep, 0
	ret
endp

section '.reloc' fixups data readable discardable
	if $=$$
		dd 0,8          ; if there are no fixups, generate dummy entry
	end if
