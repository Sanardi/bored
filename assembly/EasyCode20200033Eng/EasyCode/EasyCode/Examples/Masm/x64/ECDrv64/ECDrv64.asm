;EasyCodeName=ECDrv64,1
.Const

ECDrvName			TextEqu	<ECDrv64>
NT_DEVICE_NAME		CatStr	<"\Device\>,ECDrvName,<">
DOS_DEVICE_NAME		CatStr	<"\DosDevices\>,ECDrvName,<">

.Data?

DEVICE_EXTENSION Struct
    ;This structure is driver-defined.
    ;It must be filled depending on
    ;the driver to be programmed.

    ;Until filled with necessary
    ;data, define a DD value in
    ;order to avoid GoAsm errors
	DD		?
DEVICE_EXTENSION EndS

.Data

.Code

DriverEntry Proc pDriverObject:PDRIVER_OBJECT, pusRegistryPath:PUNICODE_STRING
	Local usDeviceName:UNICODE_STRING, usSymbolicLinkName:UNICODE_STRING
	Local pDeviceObject:PDEVICE_OBJECT

	Mov pDriverObject, Rcx
	Mov pusRegistryPath, Rdx

	ECInvoke RtlInitUnicodeString, Addr usDeviceName, TextStrW(%NT_DEVICE_NAME)
	ECInvoke RtlInitUnicodeString, Addr usSymbolicLinkName, TextStrW(%DOS_DEVICE_NAME)

	ECInvoke IoCreateDevice, pDriverObject, SizeOf DEVICE_EXTENSION, Addr usDeviceName, \
                           FILE_DEVICE_UNKNOWN, 0, TRUE, Addr pDeviceObject
	Cmp Rax, STATUS_SUCCESS
	Je @F
	ECInvoke MakeBeep, 500
L2:	Mov Rax, STATUS_DEVICE_CONFIGURATION_ERROR
	Jmp L4

@@:	ECInvoke IoCreateSymbolicLink, Addr usSymbolicLinkName, Addr usDeviceName
	Cmp Rax, STATUS_SUCCESS
	Je @F
	ECInvoke IoDeleteDevice, pDriverObject
	ECInvoke MakeBeep, 400
	Jmp L2

@@:	Mov Rax, pDriverObject
	Lea Rcx, DriverUnload
	Mov [Rax].DRIVER_OBJECT.DriverUnload, Rcx

	Mov Rcx, Offset DriverCreate
	Mov [Rax].DRIVER_OBJECT.MajorFunction [IRP_MJ_CREATE * 8], Rcx
	Mov Rcx, Offset DriverRead
	Mov [Rax].DRIVER_OBJECT.MajorFunction [IRP_MJ_READ * 8], Rcx

	Mov Rax, STATUS_SUCCESS
L4:	Ret
DriverEntry EndP

DriverCreate Proc pDeviceObject:PDEVICE_OBJECT, pIrp:PIRP
	Local Status:DWORD, Info:QWORD

	Mov pDeviceObject, Rcx
	Mov pIrp, Rdx

	;--------------------------
	ECInvoke MakeBeep, 800
	;--------------------------
	Mov Status, STATUS_SUCCESS
	Mov Info, 0H
	Mov Rdx, pIrp
	Mov Eax, Status
	Mov [Rdx]._IRP.IoStatus.Status, Eax
	Mov Rax, Info
	Mov [Rdx]._IRP.IoStatus.Information, Rax
	ECInvoke IoCompleteRequest, pIrp, IO_NO_INCREMENT

	Mov Eax, Status
	Ret
DriverCreate EndP

DriverRead Proc pDeviceObject:PDEVICE_OBJECT, pIrp:PIRP
	Local Status:DWORD, Info:QWORD

	Mov pDeviceObject, Rcx
	Mov pIrp, Rdx

	;--------------------------
	ECInvoke MakeBeep, 1200
	;--------------------------
	Mov Status, STATUS_SUCCESS
	Mov Info, 0H
	Mov Rdx, pIrp
	Mov Eax, Status
	Mov [Rdx]._IRP.IoStatus.Status, Eax
	Mov Rax, Info
	Mov [Rdx]._IRP.IoStatus.Information, Rax
	ECInvoke IoCompleteRequest, pIrp, IO_NO_INCREMENT

	Mov Eax, Status
	Ret
DriverRead EndP

DriverUnload Proc pDriverObject:PDRIVER_OBJECT
	Local usSymbolicLinkName:UNICODE_STRING

	Mov pDriverObject, Rcx

	ECInvoke MakeBeep, 1000

	ECInvoke RtlInitUnicodeString, Addr usSymbolicLinkName, TextStrW(%DOS_DEVICE_NAME)
	ECInvoke IoDeleteSymbolicLink, Addr usSymbolicLinkName

	Mov Rax, pDriverObject
	ECInvoke IoDeleteDevice, [Rax].DRIVER_OBJECT.DeviceObject
	Ret
DriverUnload EndP

MakeBeep Proc Freq:QWord
	Mov Freq, Rcx

	ECInvoke HalMakeBeep, Freq
	Mov Rax, 100000000
@@:	Dec Rax
	Jnz @B
	ECInvoke HalMakeBeep, 0
	Ret
MakeBeep EndP
