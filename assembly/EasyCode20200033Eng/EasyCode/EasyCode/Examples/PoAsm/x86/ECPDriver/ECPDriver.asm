;EasyCodeName=ECPDriver,1
.Const

ECDrvName			Equ		<"ECPDriver">

.Data?

IFNDEF DEVICE_EXTENSION
	DEVICE_EXTENSION Struct
		;This structure is driver-defined.
		;It must be filled depending on
		;the driver to be programmed.

		;Until filled with necessary
		;data, define a DD value in
		;order to avoid compiler errors
		DD	?
	DEVICE_EXTENSION EndS
ENDIF

.Data

pNT_DEVICE_NAME		DW		"\Device\", ECDrvName, 0
pDOS_DEVICE_NAME	DW		"\DosDevices\", ECDrvName, 0

.Code

DriverEntry Proc pDriverObject:PDRIVER_OBJECT, pusRegistryPath:PUNICODE_STRING
	Local usDeviceName:UNICODE_STRING, usSymbolicLinkName:UNICODE_STRING
	Local pDeviceObject:PDEVICE_OBJECT

	Invoke RtlInitUnicodeString, Addr usDeviceName, Addr pNT_DEVICE_NAME
	Invoke RtlInitUnicodeString, Addr usSymbolicLinkName, Addr pDOS_DEVICE_NAME

	Invoke IoCreateDevice, pDriverObject, SizeOf DEVICE_EXTENSION, Addr usDeviceName,
						   FILE_DEVICE_UNKNOWN, 0, TRUE, Addr pDeviceObject
	.If Eax != STATUS_SUCCESS
		Mov Eax, STATUS_DEVICE_CONFIGURATION_ERROR
		Ret
	.EndIf

	Invoke IoCreateSymbolicLink, Addr usSymbolicLinkName, Addr usDeviceName
	.If Eax != STATUS_SUCCESS
		Invoke IoDeleteDevice, pDriverObject
		Mov Eax, STATUS_DEVICE_CONFIGURATION_ERROR
		Ret
	.EndIf

	Mov Eax, pDriverObject
	Mov [Eax].DRIVER_OBJECT.DriverUnload, Offset DriverUnload

	Mov [Eax].DRIVER_OBJECT.MajorFunction + [IRP_MJ_CREATE * 4], Offset DriverDispatch
	Mov [Eax].DRIVER_OBJECT.MajorFunction + [IRP_MJ_CLOSE * 4], Offset DriverDispatch
	Mov [Eax].DRIVER_OBJECT.MajorFunction + [IRP_MJ_DEVICE_CONTROL * 4], Offset DriverDispatch
	Mov [Eax].DRIVER_OBJECT.MajorFunction + [IRP_MJ_READ * 4], Offset DriverDispatch
	Mov [Eax].DRIVER_OBJECT.MajorFunction + [IRP_MJ_WRITE * 4], Offset DriverDispatch

	Mov Eax, STATUS_SUCCESS
	Ret
DriverEntry EndP

DriverUnload Proc pDriverObject:PDRIVER_OBJECT
	Local usSymbolicLinkName:UNICODE_STRING

	Invoke RtlInitUnicodeString, Addr usSymbolicLinkName, Addr pDOS_DEVICE_NAME
	Invoke IoDeleteSymbolicLink, Addr usSymbolicLinkName

	Mov Eax, pDriverObject
	Invoke IoDeleteDevice, [Eax].DRIVER_OBJECT.DeviceObject
	Ret
DriverUnload EndP

DriverDispatch Proc Uses Ecx Edx pDeviceObject:PDEVICE_OBJECT, pIrp:PIRP
	Local Status:NTSTATUS, Info:DWord, IO_S_L:DWord
	Local RBufPtr:DWord           ; Buffer
	Local RBufLen:SDWord          ; Buffer Len

	Mov Info, 0H
	Mov Eax, pIrp
	Mov Eax, [Eax]._IRP.Tail.Overlay.CurrentStackLocation
	Mov IO_S_L, Eax

	Movzx Eax, [Eax].IO_STACK_LOCATION.MajorFunction

	.If Eax == IRP_MJ_CREATE
		Mov Status, STATUS_SUCCESS
	.ElseIf Eax == IRP_MJ_CLOSE
		Mov Status, STATUS_SUCCESS
	.ElseIf Eax == IRP_MJ_DEVICE_CONTROL
		Mov Status, STATUS_SUCCESS
	.ElseIf Eax == IRP_MJ_READ
		Mov Eax, pIrp
		Move RBufPtr, [Eax]._IRP.UserBuffer                   ; Buff Ptr
		Mov Eax, IO_S_L
		Move RBufLen, [Eax].IO_STACK_LOCATION.Parameters.Read.dwLength  ; READ Out Buff Len
		Mov Edx, RBufPtr
		Mov Ecx, RBufLen
		Xor Eax, Eax
		.While (Ecx > SDWord Ptr 0)
			Mov Byte Ptr [Edx], Al
			Inc Edx
			Dec Ecx
		.EndW
		Invoke GetProcess, RBufPtr, RBufLen
		Mov Info, Eax ; RBufLen
		Mov Status, STATUS_SUCCESS
	.ElseIf Eax == IRP_MJ_WRITE
		Mov Status, STATUS_SUCCESS
	.Else
		Mov Status, STATUS_NOT_IMPLEMENTED
	.EndIf

	Mov Eax, pIrp
	Mov Ecx, Status
	Mov [Eax]._IRP.IoStatus.Status, Ecx
	Mov Ecx, Info
	Mov [Eax]._IRP.IoStatus.Information, Ecx

    Mov Edx, IO_NO_INCREMENT
    Mov Ecx, pIrp
    Call IoCompleteRequest
	Mov Eax, Status
	Ret
DriverDispatch EndP

GetProcess Proc RBufPtr:DWord, RBufLen:DWord
	Local BufLenReq:SDWord, BufLen:SDWord, BufPtr:DWord
	Local Result:SDWord

	Mov Result, -1
	Mov BufLenReq, 0
	Invoke ZwQuerySystemInformation, SystemProcessInformation, NULL, NULL, Addr BufLenReq
	.If (BufLenReq <= 0)
		Mov BufLenReq, 32768
	.EndIf
	Shl BufLenReq, 1    ;BufLenReq * 2 (Por seguridad)
	Move BufLen, BufLenReq
	Invoke ExAllocatePool, NonPagedPool, BufLen
	.If Eax != 0
		Mov BufPtr, Eax
		Invoke ZwQuerySystemInformation, SystemProcessInformation, BufPtr, BufLen, Addr BufLenReq
		.If Eax == STATUS_INFO_LENGTH_MISMATCH

		.ElseIf Eax != 0

		.Else
			Mov Eax, BufLenReq
			.If Eax < RBufLen
				Mov Result, Eax
				Invoke RtlMoveMemory, RBufPtr, BufPtr, BufLenReq
			.EndIf
		.EndIf
		Invoke ExFreePool, BufPtr
	.EndIf
	Mov Eax, Result
	Ret
GetProcess EndP

End DriverEntry
