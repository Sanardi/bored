;EasyCodeName=ECDrv64,1
.Const

ECDrvName			Equ		<"ECDrv64">

.Data?

IFNDEF DEVICE_EXTENSION
	DEVICE_EXTENSION Struct
	    ;This structure is driver-defined.
	    ;It must be filled depending on
	    ;the driver to be programmed.

	    ;Until filled with necessary
	    ;data, define a DD value in
	    ;order to avoid GoAsm errors
		DD		?
	DEVICE_EXTENSION EndS
ENDIF

.Data

pNT_DEVICE_NAME		DW		"\Device\", ECDrvName, 0
pDOS_DEVICE_NAME	DW		"\DosDevices\", ECDrvName, 0

.Code

DriverEntry Proc pDriverObject_:PDRIVER_OBJECT, pusRegistryPath_:PUNICODE_STRING Parmarea = 128
	Local pDriverObject:PDRIVER_OBJECT, pusRegistryPath:PUNICODE_STRING
	Local usDeviceName:UNICODE_STRING, usSymbolicLinkName:UNICODE_STRING
	Local pDeviceObject:PDEVICE_OBJECT

	Mov pDriverObject, pDriverObject_
	Mov pusRegistryPath, pusRegistryPath_

	Invoke RtlInitUnicodeString, Addr usDeviceName, Addr pNT_DEVICE_NAME
	Invoke RtlInitUnicodeString, Addr usSymbolicLinkName, Addr pDOS_DEVICE_NAME

	Invoke IoCreateDevice, pDriverObject, SizeOf DEVICE_EXTENSION, Addr usDeviceName, \
							FILE_DEVICE_UNKNOWN, 0, TRUE, Addr pDeviceObject
	.If Rax != STATUS_SUCCESS
		Invoke MakeBeep, 500
		Mov Rax, STATUS_DEVICE_CONFIGURATION_ERROR
		Jmp L2
	.EndIf

	Invoke IoCreateSymbolicLink, Addr usSymbolicLinkName, Addr usDeviceName
	.If Rax != STATUS_SUCCESS
		Invoke IoDeleteDevice, pDriverObject

		Invoke MakeBeep, 400
		Mov Rax, STATUS_DEVICE_CONFIGURATION_ERROR
		Jmp L2
	.EndIf

	Mov Rax, pDriverObject
	Mov Rcx, Offset DriverUnload
	Mov [Rax].DRIVER_OBJECT.DriverUnload, Rcx
	Mov Rcx, Offset DriverCreate
	Mov [Rax].DRIVER_OBJECT.MajorFunction + [IRP_MJ_CREATE * 8], Rcx
	Mov Rcx, Offset DriverRead
	Mov [Rax].DRIVER_OBJECT.MajorFunction + [IRP_MJ_READ * 8], Rcx

	Mov Rax, STATUS_SUCCESS
L2:	Ret
DriverEntry EndP

DriverUnload Proc pDriverObject_:PDRIVER_OBJECT Parmarea = 128
	Local pDriverObject:PDRIVER_OBJECT
	Local usSymbolicLinkName:UNICODE_STRING

	Mov pDriverObject, pDriverObject_

	Invoke MakeBeep, 1000

	Invoke RtlInitUnicodeString, Addr usSymbolicLinkName, Addr pDOS_DEVICE_NAME
	Invoke IoDeleteSymbolicLink, Addr usSymbolicLinkName

	Mov Rax, pDriverObject
	Invoke IoDeleteDevice, [Rax].DRIVER_OBJECT.DeviceObject
	Ret
DriverUnload EndP

DriverCreate Proc pDeviceObject_:PDEVICE_OBJECT, pIrp_:PIRP Parmarea = 128
	Local pDeviceObject:PDEVICE_OBJECT, ppIrp:PIRP
	Local Status:DWORD, Info:QWORD

	Mov pDeviceObject, pDeviceObject_
	Mov ppIrp, pIrp_

	;--------------------------
	Invoke MakeBeep, 800
	;--------------------------
	Mov Status, STATUS_SUCCESS
	Mov Info, 0H
	Mov Rdx, ppIrp
	Mov Eax, Status
	Mov [Rdx]._IRP.IoStatus.Status, Eax
	Mov Rax, Info
	Mov [Rdx]._IRP.IoStatus.Information, Rax
	Invoke IoCompleteRequest, ppIrp, IO_NO_INCREMENT

	Mov Eax, Status
	Ret
DriverCreate EndP

DriverRead Proc pDeviceObject_:PDEVICE_OBJECT, pIrp_:PIRP Parmarea = 128
	Local pDeviceObject:PDEVICE_OBJECT, pIrp:PIRP
	Local Status:DWORD, Info:QWORD

	Mov pDeviceObject, pDeviceObject_
	Mov pIrp, pIrp_

	;--------------------------
	Invoke MakeBeep, 1200
	;--------------------------
	Mov Status, STATUS_SUCCESS
	Mov Info, 0H
	Mov Rdx, pIrp
	Mov Eax, Status
	Mov [Rdx]._IRP.IoStatus.Status, Eax
	Mov Rax, Info
	Mov [Rdx]._IRP.IoStatus.Information, Rax
	Invoke IoCompleteRequest, pIrp, IO_NO_INCREMENT

	Mov Eax, Status
	Ret
DriverRead EndP

MakeBeep Proc Freq_:QWORD Parmarea = 128
	Local Freq:QWORD

	Mov Freq, Freq_

	Invoke HalMakeBeep, Freq
	Mov Rax, 100000000
@@:	Dec Rax
	Jnz @B
	Invoke HalMakeBeep, 0
	Ret
MakeBeep EndP
