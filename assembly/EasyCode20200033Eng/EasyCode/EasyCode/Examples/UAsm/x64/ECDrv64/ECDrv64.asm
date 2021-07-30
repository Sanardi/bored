;EasyCodeName=ECDrv64,1
.Const

ECDrvName           TextEqu <ECDrv64>
NT_DEVICE_NAME      CatStr  <"\Device\>,ECDrvName,<">
DOS_DEVICE_NAME     CatStr  <"\DosDevices\>,ECDrvName,<">

.Data?

DEVICE_EXTENSION Struct
    ;This structure is driver-defined.
    ;It must be filled depending on
    ;the driver to be programmed.

    ;Until filled with necessary
    ;data, define a DD value in
    ;order to avoid GoAsm errors
    DD      ?
DEVICE_EXTENSION EndS

.Data

.Code

DriverEntry Proc FastCall Frame pDriverObject:PDRIVER_OBJECT, pusRegistryPath:PUNICODE_STRING
    Local usDeviceName:UNICODE_STRING, usSymbolicLinkName:UNICODE_STRING
    Local pDeviceObject:PDEVICE_OBJECT

    Mov pDriverObject, Rcx
    Mov pusRegistryPath, Rdx

    Invoke RtlInitUnicodeString, Addr usDeviceName, TextStrW(%NT_DEVICE_NAME)
    Invoke RtlInitUnicodeString, Addr usSymbolicLinkName, TextStrW(%DOS_DEVICE_NAME)

    Invoke IoCreateDevice, pDriverObject, SizeOf DEVICE_EXTENSION, Addr usDeviceName, \
                           FILE_DEVICE_UNKNOWN, 0, TRUE, Addr pDeviceObject
    .If Eax != STATUS_SUCCESS
        Invoke MakeBeep, 500
L2:     Mov Eax, STATUS_DEVICE_CONFIGURATION_ERROR
        Jmp L4
    .EndIf

    Invoke IoCreateSymbolicLink, Addr usSymbolicLinkName, Addr usDeviceName
    .If Eax != STATUS_SUCCESS
        Invoke IoDeleteDevice, pDriverObject
        Invoke MakeBeep, 400
        Jmp L2
    .EndIf

    Mov Rax, pDriverObject
    Lea Rcx, DriverUnload
    Mov [Rax].DRIVER_OBJECT.DriverUnload, Rcx
    Mov Rcx, Offset DriverCreate
    Mov [Rax].DRIVER_OBJECT.MajorFunction [IRP_MJ_CREATE * 8], Rcx
    Mov Rcx, Offset DriverRead
    Mov [Rax].DRIVER_OBJECT.MajorFunction [IRP_MJ_READ * 8], Rcx

    Mov Rax, STATUS_SUCCESS
L4: Ret
DriverEntry EndP

DriverUnload Proc FastCall Frame pDriverObject:PDRIVER_OBJECT
    Local usSymbolicLinkName:UNICODE_STRING

    Mov pDriverObject, Rcx

    Invoke MakeBeep, 1000

    Invoke RtlInitUnicodeString, Addr usSymbolicLinkName, TextStrW(%DOS_DEVICE_NAME)
    Invoke IoDeleteSymbolicLink, Addr usSymbolicLinkName

    Mov Rax, pDriverObject
    Invoke IoDeleteDevice, [Rax].DRIVER_OBJECT.DeviceObject
    Ret
DriverUnload EndP

DriverCreate Proc FastCall Frame pDeviceObject:PDEVICE_OBJECT, pIrp:PIRP
    Local Status:DWORD, Info:QWORD

    Mov pDeviceObject, Rcx
    Mov pIrp, Rdx

    ;--------------------------
    Invoke MakeBeep, 800
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
DriverCreate EndP

DriverRead Proc FastCall Frame pDeviceObject:PDEVICE_OBJECT, pIrp:PIRP
    Local Status:DWORD, Info:QWORD

    Mov pDeviceObject, Rcx
    Mov pIrp, Rdx

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

MakeBeep Proc FastCall Frame Freq:QWord
    Mov Freq, Rcx

    Invoke HalMakeBeep, Freq
    Mov Rax, 100000000
@@: Dec Rax
    Jnz @B
    Invoke HalMakeBeep, 0
    Ret
MakeBeep EndP
