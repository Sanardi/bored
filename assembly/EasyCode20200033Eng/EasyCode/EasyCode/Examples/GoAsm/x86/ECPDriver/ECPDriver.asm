;EasyCodeName=ECPDriver,1
.Const

.Data

DEVICE_EXTENSION Struct
	;This structure is driver-defined.
	;It must be filled depending on
	;the driver to be programmed.

	;Until filled with necessary
	;data, define a DD value in
	;order to avoid GoAsm errors
	DD
EndS

.Code

DriverEntry Frame pDriverObject, pusRegistryPath
	Local usDeviceName:UNICODE_STRING, usSymbolicLinkName:UNICODE_STRING
	Local pDeviceObject:D

	Invoke RtlInitUnicodeString, Addr usDeviceName, L"\Device\ECPDriver"
	Invoke RtlInitUnicodeString, Addr usSymbolicLinkName, L"\DosDevices\ECPDriver"

	Invoke IoCreateDevice, [pDriverObject], SizeOf DEVICE_EXTENSION, Addr usDeviceName, \
						   FILE_DEVICE_UNKNOWN, 0, TRUE, Addr pDeviceObject
	Cmp Eax, STATUS_SUCCESS
	Je >
	Mov Eax, STATUS_DEVICE_CONFIGURATION_ERROR
	Ret

:	Invoke IoCreateSymbolicLink, Addr usSymbolicLinkName, Addr usDeviceName
	Cmp Eax, STATUS_SUCCESS
	Je >
	Invoke IoDeleteDevice, [pDriverObject]
	Mov Eax, STATUS_DEVICE_CONFIGURATION_ERROR
	Ret

:	Mov Eax, [pDriverObject]
	Mov [Eax + DRIVER_OBJECT.DriverUnload], Offset DriverUnload

	Mov [Eax + DRIVER_OBJECT.MajorFunction + (IRP_MJ_CREATE * 4)], Offset DriverDispatch
	Mov [Eax + DRIVER_OBJECT.MajorFunction + (IRP_MJ_CLOSE * 4)], Offset DriverDispatch
	Mov [Eax + DRIVER_OBJECT.MajorFunction + (IRP_MJ_DEVICE_CONTROL * 4)], Offset DriverDispatch
	Mov [Eax + DRIVER_OBJECT.MajorFunction + (IRP_MJ_READ * 4)], Offset DriverDispatch
	Mov [Eax + DRIVER_OBJECT.MajorFunction + (IRP_MJ_WRITE * 4)], Offset DriverDispatch

	Mov Eax, STATUS_SUCCESS
	Ret
EndF

GetProcess Frame RBufPtr, RBufLen
    Local BufLenReq:D, BufLen:D, BufPtr:D
    Local Result:D
           Mov D[Result], -1
           Mov D[BufLenReq], 0
           Invoke ZwQuerySystemInformation, SystemProcessInformation, NULL, NULL, Addr BufLenReq
           Cmp D[BufLenReq], 0
           Jg >
           Mov D[BufLenReq], 32768
:          Shl D[BufLenReq], 1

           Move ([BufLen], [BufLenReq])
    Invoke ExAllocatePool, NonPagedPool, [BufLen]
    Or Eax, Eax
    Jz > L2
    Mov [BufPtr], Eax
    Invoke ZwQuerySystemInformation, SystemProcessInformation, [BufPtr], [BufLen], Addr BufLenReq
    Cmp Eax, STATUS_INFO_LENGTH_MISMATCH
    Je >
	Or Eax, Eax
	Jnz >
   	Mov Eax, [BufLenReq]
   	Cmp Eax, [RBufLen]
   	Jge >
 	Mov [Result], Eax
    Invoke RtlMoveMemory, [RBufPtr], [BufPtr], [BufLenReq]
:   Invoke ExFreePool, [BufPtr]

L2: Mov Eax, [Result]
    Ret
EndF

DriverUnload Frame pDriverObject
	Local usSymbolicLinkName:UNICODE_STRING

	Invoke RtlInitUnicodeString, Addr usSymbolicLinkName, L"\DosDevices\ECPDriver"
	Invoke IoDeleteSymbolicLink, Addr usSymbolicLinkName

	Mov Eax, [pDriverObject]
	Invoke IoDeleteDevice, [Eax + DRIVER_OBJECT.DeviceObject]
	Ret
EndF

DriverDispatch Frame pDeviceObject, pIrp
	Uses Ecx, Edx
	Local Status:D, Info:D, IO_S_L:D

    Local RBufPtr:D ; Buffer
    Local RBufLen:D ; Buffer Len

	Mov D[Info], 0H
	Mov Eax, [pIrp]
	Mov Eax, [Eax + _IRP.Tail.Overlay.CurrentStackLocation]
	Mov [IO_S_L], Eax

	Movzx Eax, B[Eax + IO_STACK_LOCATION.MajorFunction]

	Cmp Eax, IRP_MJ_CREATE
	Jne >
L2:	Mov D[Status], STATUS_SUCCESS
	Jmp > L4
:	Cmp Eax, IRP_MJ_CLOSE
	Je < L2
	Cmp Eax, IRP_MJ_DEVICE_CONTROL
	Je < L2
	Cmp Eax, IRP_MJ_READ
	Jne > L3
            Mov Eax, [pIrp]
            Move([RBufPtr], [Eax + _IRP.UserBuffer])                   ; Buff Ptr
            Mov Eax, [IO_S_L]
            Move([RBufLen], [Eax + IO_STACK_LOCATION.Parameters.Read.dwLength])  ; READ Out Buff Len
            ;--
			Mov Edx, [RBufPtr]
			Mov Ecx, [RBufLen]
			Xor Eax, Eax
:			Cmp Ecx, 0
			jle >
			mov B[Edx], Al
			Inc Edx
			Dec Ecx
			Jmp <
			;--
:           Invoke GetProcess, [RBufPtr], [RBufLen]
            Mov [Info], Eax ; RBufLen
           ;--
	Jmp < L2
L3:	Cmp Eax, IRP_MJ_WRITE
	Je < L2
:	Mov D[Status], STATUS_NOT_IMPLEMENTED

L4:	Mov Eax, [pIrp]
	Push [Status]
	Pop [Eax + _IRP.IoStatus.Status]
	Push [Info]
	Pop [Eax + _IRP.IoStatus.Information]

	Invoke IoCompleteRequest, [pIrp], IO_NO_INCREMENT
	Mov Eax, [Status]
	Ret
EndF
