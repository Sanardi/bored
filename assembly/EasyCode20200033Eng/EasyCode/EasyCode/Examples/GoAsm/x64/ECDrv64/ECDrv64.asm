;EasyCodeName=ECDrv64,1
.Const

ECDrvName			Equ		 'ECDrv64'

.Data

pNT_DEVICE_NAME		DUS      '\Device\', ECDrvName, 0
pDOS_DEVICE_NAME	DUS      '\DosDevices\', ECDrvName, 0

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
    Local pDeviceObject:Q

    Invoke RtlInitUnicodeString, Addr usDeviceName, Addr pNT_DEVICE_NAME
    Invoke RtlInitUnicodeString, Addr usSymbolicLinkName, Addr pDOS_DEVICE_NAME

    Invoke IoCreateDevice, [pDriverObject], SizeOf DEVICE_EXTENSION, Addr usDeviceName, \
                           FILE_DEVICE_UNKNOWN, 0, TRUE, Addr pDeviceObject
    Cmp Rax, STATUS_SUCCESS
    Je >
	Invoke MakeBeep, 500
    Mov Rax, STATUS_DEVICE_CONFIGURATION_ERROR
	Jmp >> L2

:   Invoke IoCreateSymbolicLink, Addr usSymbolicLinkName, Addr usDeviceName
    Cmp Rax, STATUS_SUCCESS
    Je >
    Invoke IoDeleteDevice, [pDriverObject]
	Invoke MakeBeep, 400
    Mov Rax, STATUS_DEVICE_CONFIGURATION_ERROR
    Jmp > L2

:   Mov Rax, [pDriverObject]
	Lea Rcx, DriverUnload
    Mov [Rax + DRIVER_OBJECT.DriverUnload], Rcx

	Lea Rcx, DriverCreate
	Mov [Rax + DRIVER_OBJECT.MajorFunction + (IRP_MJ_CREATE * 8)], Rcx
	Lea Rcx, DriverRead
	Mov [Rax + DRIVER_OBJECT.MajorFunction + (IRP_MJ_READ * 8)], Rcx

    Mov Rax, STATUS_SUCCESS
L2:	Ret
EndF

DriverUnload Frame pDriverObject
    Local usSymbolicLinkName:UNICODE_STRING

    Invoke RtlInitUnicodeString, Addr usSymbolicLinkName, Addr pDOS_DEVICE_NAME
    Invoke IoDeleteSymbolicLink, Addr usSymbolicLinkName

	Invoke MakeBeep, 1000

    Mov Rax, [pDriverObject]
    Invoke IoDeleteDevice, [Rax + DRIVER_OBJECT.DeviceObject]
    Ret
EndF

DriverCreate Frame pDeviceObject, ppIRP
	Local Status:D, Info:Q
	;--------------------------
	Invoke MakeBeep, 800
	;--------------------------
	Mov Q[Status], STATUS_SUCCESS
	Mov Q[Info], 0H
	Mov Rdx, [ppIRP] 
	Mov Eax, [Status]
	Mov [Rdx + _IRP.IoStatus.Status], Eax
	Mov Rax, [Info]
	Mov [Rdx + _IRP.IoStatus.Information], Rax
	Invoke IoCompleteRequest, [ppIRP], IO_NO_INCREMENT 
	Mov Eax, [Status]
	Ret
EndF

DriverRead Frame pDeviceObject, pIRP
	Local Status:D, Info:Q
	;--------------------------
	Invoke MakeBeep, 1200
	;--------------------------
	Mov Q[Status], STATUS_SUCCESS
	Mov Q[Info], 0H
	Mov Rdx, [pIRP]
	Mov Eax, [Status]
	Mov [Rdx + _IRP.IoStatus.Status], Eax
	Mov Rax, [Info]
	Mov [Rdx + _IRP.IoStatus.Information], Rax
	Invoke IoCompleteRequest, [pIRP], IO_NO_INCREMENT
	Mov Eax, [Status]
	Ret
EndF

MakeBeep Frame Freq
	Invoke HalMakeBeep, [Freq]
	Mov Rax, 100000000
:	Dec Rax
	Jnz <
	Invoke HalMakeBeep, 0
	Ret
EndF
