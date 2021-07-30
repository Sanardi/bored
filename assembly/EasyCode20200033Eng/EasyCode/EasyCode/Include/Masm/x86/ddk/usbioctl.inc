;===================================================================;
;                                                                   ;
;  usbioctl.inc for Easy Code 2.0 JWasm/Masm/PoAsm 32-bit drivers   ;
;                        (version 1.0.0)                            ;
;                                                                   ;
;                 Driver Development Kit (32-bit)                   ;
;                                                                   ;
;                  Copyright © Ramon Sala - 2015                    ;
;                                                                   ;
;===================================================================;

IFNDEF USBIOCTL_INC
USBIOCTL_INC Equ 1

Include usb.inc
Include usbiodef.inc

IOCTL_INTERNAL_USB_SUBMIT_URB                               Equ         CTL_CODE(FILE_DEVICE_USB, USB_SUBMIT_URB, METHOD_NEITHER, FILE_ANY_ACCESS)
IOCTL_INTERNAL_USB_RESET_PORT                               Equ         CTL_CODE(FILE_DEVICE_USB, USB_RESET_PORT, METHOD_NEITHER, FILE_ANY_ACCESS)
IOCTL_INTERNAL_USB_GET_ROOTHUB_PDO                          Equ         CTL_CODE(FILE_DEVICE_USB, USB_GET_ROOTHUB_PDO, METHOD_NEITHER, FILE_ANY_ACCESS)

USBD_PORT_ENABLED                                           Equ         00000001H
USBD_PORT_CONNECTED                                         Equ         00000002H

IOCTL_INTERNAL_USB_GET_PORT_STATUS                          Equ         CTL_CODE(FILE_DEVICE_USB, USB_GET_PORT_STATUS, METHOD_NEITHER, FILE_ANY_ACCESS)
IOCTL_INTERNAL_USB_ENABLE_PORT                              Equ         CTL_CODE(FILE_DEVICE_USB, USB_ENABLE_PORT, METHOD_NEITHER, FILE_ANY_ACCESS)
IOCTL_INTERNAL_USB_GET_HUB_COUNT                            Equ         CTL_CODE(FILE_DEVICE_USB, USB_GET_HUB_COUNT, METHOD_NEITHER, FILE_ANY_ACCESS)
IOCTL_INTERNAL_USB_CYCLE_PORT                               Equ         CTL_CODE(FILE_DEVICE_USB, USB_CYCLE_PORT, METHOD_NEITHER, FILE_ANY_ACCESS)
IOCTL_INTERNAL_USB_GET_HUB_NAME                             Equ         CTL_CODE(FILE_DEVICE_USB, USB_GET_HUB_NAME, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_INTERNAL_USB_GET_BUS_INFO                             Equ         CTL_CODE(FILE_DEVICE_USB, USB_GET_BUS_INFO, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_INTERNAL_USB_GET_CONTROLLER_NAME                      Equ         CTL_CODE(FILE_DEVICE_USB, USB_GET_CONTROLLER_NAME, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_INTERNAL_USB_GET_BUSGUID_INFO                         Equ         CTL_CODE(FILE_DEVICE_USB, USB_GET_BUSGUID_INFO, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_INTERNAL_USB_GET_PARENT_HUB_INFO                      Equ         CTL_CODE(FILE_DEVICE_USB, USB_GET_PARENT_HUB_INFO, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_INTERNAL_USB_SUBMIT_IDLE_NOTIFICATION                 Equ         CTL_CODE(FILE_DEVICE_USB, USB_IDLE_NOTIFICATION, METHOD_NEITHER, FILE_ANY_ACCESS)
IOCTL_INTERNAL_USB_GET_DEVICE_HANDLE                        Equ         CTL_CODE(FILE_DEVICE_USB, USB_GET_DEVICE_HANDLE, METHOD_NEITHER, FILE_ANY_ACCESS)
IOCTL_INTERNAL_USB_NOTIFY_IDLE_READY                        Equ         CTL_CODE(FILE_DEVICE_USB, USB_IDLE_NOTIFICATION_EX, METHOD_NEITHER, FILE_ANY_ACCESS)
IOCTL_INTERNAL_USB_REQ_GLOBAL_SUSPEND                       Equ         CTL_CODE(FILE_DEVICE_USB, USB_REQ_GLOBAL_SUSPEND, METHOD_NEITHER, FILE_ANY_ACCESS)
IOCTL_INTERNAL_USB_REQ_GLOBAL_RESUME                        Equ         CTL_CODE(FILE_DEVICE_USB, USB_REQ_GLOBAL_RESUME, METHOD_NEITHER, FILE_ANY_ACCESS)

USB_START_FAILDATA Struct
    LengthInBytes                                           DD          ?
    NtStatus                                                NTSTATUS    ?
    UsbdStatus                                              USBD_STATUS ?
    ConnectStatus                                           DD          ?
    DriverData                                              DB          4 Dup(?)
USB_START_FAILDATA ENdS
PUSB_START_FAILDATA                                         TypeDef     DWord

IOCTL_INTERNAL_USB_RECORD_FAILURE                           Equ         CTL_CODE(FILE_DEVICE_USB, USB_RECORD_FAILURE, METHOD_NEITHER, FILE_ANY_ACCESS)
IOCTL_INTERNAL_USB_GET_DEVICE_HANDLE_EX                     Equ         CTL_CODE(FILE_DEVICE_USB, USB_GET_DEVICE_HANDLE_EX, METHOD_NEITHER, FILE_ANY_ACCESS)
IOCTL_INTERNAL_USB_GET_TT_DEVICE_HANDLE                     Equ         CTL_CODE(FILE_DEVICE_USB, USB_GET_TT_DEVICE_HANDLE, METHOD_NEITHER, FILE_ANY_ACCESS)

USB_TOPOLOGY_ADDRESS Struct
    PciBusNumber                                            DD          ?
    PciDeviceNumber                                         DD          ?
    PciFunctionNumber                                       DD          ?
    Reserved                                                DD          ?
    RootHubPortNumber                                       DW          ?
    HubPortNumber                                           DW          5 Dup(?)
    Reserved2                                               DW          ?
USB_TOPOLOGY_ADDRESS EndS
PUSB_TOPOLOGY_ADDRESS                                       TypeDef     DWord
        
IOCTL_INTERNAL_USB_GET_TOPOLOGY_ADDRESS                     Equ         CTL_CODE(FILE_DEVICE_USB, USB_GET_TOPOLOGY_ADDRESS, METHOD_NEITHER, FILE_ANY_ACCESS)

IOCTL_INTERNAL_USB_GET_DEVICE_CONFIG_INFO                   Equ         CTL_CODE(FILE_DEVICE_USB, USB_GET_HUB_CONFIG_INFO, METHOD_NEITHER, FILE_ANY_ACCESS)

IFNDEF USB_KERNEL_IOCTL
    IOCTL_USB_HCD_GET_STATS_1                               Equ         CTL_CODE(FILE_DEVICE_USB, HCD_GET_STATS_1, METHOD_BUFFERED, FILE_ANY_ACCESS)
    IOCTL_USB_HCD_GET_STATS_2                               Equ         CTL_CODE(FILE_DEVICE_USB, HCD_GET_STATS_2, METHOD_BUFFERED, FILE_ANY_ACCESS)
    IOCTL_USB_HCD_DISABLE_PORT                              Equ         CTL_CODE(FILE_DEVICE_USB, HCD_DISABLE_PORT, METHOD_BUFFERED, FILE_ANY_ACCESS)
    IOCTL_USB_HCD_ENABLE_PORT                               Equ         CTL_CODE(FILE_DEVICE_USB, HCD_ENABLE_PORT, METHOD_BUFFERED, FILE_ANY_ACCESS)
    IFNDEF IOCTL_USB_DIAGNOSTIC_MODE_ON
        IOCTL_USB_DIAGNOSTIC_MODE_ON                        Equ         CTL_CODE(FILE_DEVICE_USB, HCD_DIAGNOSTIC_MODE_ON, METHOD_BUFFERED, FILE_ANY_ACCESS)
    ENDIF
    IFNDEF IOCTL_USB_DIAGNOSTIC_MODE_OFF
        IOCTL_USB_DIAGNOSTIC_MODE_OFF                       Equ         CTL_CODE(FILE_DEVICE_USB, HCD_DIAGNOSTIC_MODE_OFF, METHOD_BUFFERED, FILE_ANY_ACCESS)
    ENDIF
    IFNDEF IOCTL_USB_GET_ROOT_HUB_NAME
        IOCTL_USB_GET_ROOT_HUB_NAME                         Equ         CTL_CODE(FILE_DEVICE_USB, HCD_GET_ROOT_HUB_NAME, METHOD_BUFFERED, FILE_ANY_ACCESS)
    ENDIF
    IFNDEF IOCTL_GET_HCD_DRIVERKEY_NAME
        IOCTL_GET_HCD_DRIVERKEY_NAME                        Equ         CTL_CODE(FILE_DEVICE_USB, HCD_GET_DRIVERKEY_NAME, METHOD_BUFFERED, FILE_ANY_ACCESS)
    ENDIF
    IOCTL_USB_GET_NODE_INFORMATION                          Equ         CTL_CODE(FILE_DEVICE_USB, USB_GET_NODE_INFORMATION, METHOD_BUFFERED, FILE_ANY_ACCESS)
    IOCTL_USB_GET_NODE_CONNECTION_INFORMATION               Equ         CTL_CODE(FILE_DEVICE_USB, USB_GET_NODE_CONNECTION_INFORMATION, METHOD_BUFFERED, FILE_ANY_ACCESS)
    IOCTL_USB_GET_DESCRIPTOR_FROM_NODE_CONNECTION           Equ         CTL_CODE(FILE_DEVICE_USB, USB_GET_DESCRIPTOR_FROM_NODE_CONNECTION, METHOD_BUFFERED, FILE_ANY_ACCESS)
    IOCTL_USB_GET_NODE_CONNECTION_NAME                      Equ         CTL_CODE(FILE_DEVICE_USB, USB_GET_NODE_CONNECTION_NAME, METHOD_BUFFERED, FILE_ANY_ACCESS)
    IOCTL_USB_DIAG_IGNORE_HUBS_ON                           Equ         CTL_CODE(FILE_DEVICE_USB, USB_DIAG_IGNORE_HUBS_ON, METHOD_BUFFERED, FILE_ANY_ACCESS)
    IOCTL_USB_DIAG_IGNORE_HUBS_OFF                          Equ         CTL_CODE(FILE_DEVICE_USB, USB_DIAG_IGNORE_HUBS_OFF, METHOD_BUFFERED, FILE_ANY_ACCESS)
    IOCTL_USB_GET_NODE_CONNECTION_DRIVERKEY_NAME            Equ         CTL_CODE(FILE_DEVICE_USB, USB_GET_NODE_CONNECTION_DRIVERKEY_NAME, METHOD_BUFFERED, FILE_ANY_ACCESS)
    IOCTL_USB_GET_HUB_CAPABILITIES                          Equ         CTL_CODE(FILE_DEVICE_USB, USB_GET_HUB_CAPABILITIES, METHOD_BUFFERED, FILE_ANY_ACCESS)
    IOCTL_USB_HUB_CYCLE_PORT                                Equ         CTL_CODE(FILE_DEVICE_USB, USB_HUB_CYCLE_PORT, METHOD_BUFFERED, FILE_ANY_ACCESS)
    IOCTL_USB_GET_NODE_CONNECTION_ATTRIBUTES                Equ         CTL_CODE(FILE_DEVICE_USB, USB_GET_NODE_CONNECTION_ATTRIBUTES, METHOD_BUFFERED, FILE_ANY_ACCESS)
    IOCTL_USB_GET_NODE_CONNECTION_INFORMATION_EX            Equ         CTL_CODE(FILE_DEVICE_USB, USB_GET_NODE_CONNECTION_INFORMATION_EX, METHOD_BUFFERED, FILE_ANY_ACCESS)
    IOCTL_USB_RESET_HUB                                     Equ         CTL_CODE(FILE_DEVICE_USB, USB_RESET_HUB, METHOD_BUFFERED, FILE_ANY_ACCESS)
    IOCTL_USB_GET_HUB_CAPABILITIES_EX                       Equ         CTL_CODE(FILE_DEVICE_USB, USB_GET_HUB_CAPABILITIES_EX, METHOD_BUFFERED, FILE_ANY_ACCESS)
ENDIF

;USB_HUB_NODE Enumeration
USB_HUB_NODE                                                TypeDef     DWord
UsbHub                                                      Equ         0
UsbMIParent                                                 Equ         1

USB_HUB_INFORMATION Struct
    HubDescriptor                                           USB_HUB_DESCRIPTOR  <>
    HubIsBusPowered                                         BOOLEAN     ?
USB_HUB_INFORMATION EndS
PUSB_HUB_INFORMATION                                        TypeDef     DWord

USB_MI_PARENT_INFORMATION Struct
    NumberOfInterfaces                                      DD          ?
USB_MI_PARENT_INFORMATION EndS
PUSB_MI_PARENT_INFORMATION                                  TypeDef     DWord

USB_NODE_INFORMATION Struct
    NodeType                                                USB_HUB_NODE    ?
    Union u
        HubInformation                                      USB_HUB_INFORMATION <>
        MiParentInformation                                 USB_MI_PARENT_INFORMATION   <>
    EndS
USB_NODE_INFORMATION EndS
PUSB_NODE_INFORMATION                                       TypeDef     DWord

USB_PIPE_INFO Struct
    EndpointDescriptor                                      USB_ENDPOINT_DESCRIPTOR <>
    ScheduleOffset                                          DD          ?
USB_PIPE_INFO EndS
PUSB_PIPE_INFO                                              TypeDef     DWord

;USB_CONNECTION_STATUS Enumeration
USB_CONNECTION_STATUS                                       TypeDef     DWord
NoDeviceConnected                                           Equ         0
DeviceConnected                                             Equ         1
DeviceFailedEnumeration                                     Equ         2
DeviceGeneralFailure                                        Equ         3
DeviceCausedOvercurrent                                     Equ         4
DeviceNotEnoughPower                                        Equ         5
DeviceNotEnoughBandwidth                                    Equ         6
DeviceHubNestedTooDeeply                                    Equ         7
DeviceInLegacyHub                                           Equ         8
DeviceEnumerating                                           Equ         9
DeviceReset                                                 Equ         10
PUSB_CONNECTION_STATUS                                      TypeDef     DWord

USB_NODE_CONNECTION_INFORMATION Struct
    ConnectionIndex                                         DD          ?
    DeviceDescriptor                                        USB_DEVICE_DESCRIPTOR   <>
    CurrentConfigurationValue                               DB          ?
    LowSpeed                                                BOOLEAN     ?
    DeviceIsHub                                             BOOLEAN     ?
    DeviceAddress                                           DW          ?
    NumberOfOpenPipes                                       DD          ?
    ConnectionStatus                                        USB_CONNECTION_STATUS   ?
    PipeList                                                USB_PIPE_INFO   0 Dup(<>)
USB_NODE_CONNECTION_INFORMATION EndS
PUSB_NODE_CONNECTION_INFORMATION                            TypeDef     DWord

USB_NODE_CONNECTION_DRIVERKEY_NAME Struct
    ConnectionIndex                                         DD          ?
    ActualLength                                            DD          ?
    DriverKeyName                                           DW          1 Dup(?)
USB_NODE_CONNECTION_DRIVERKEY_NAME EndS
PUSB_NODE_CONNECTION_DRIVERKEY_NAME                         TypeDef     DWord

USB_NODE_CONNECTION_NAME Struct
    ConnectionIndex                                         DD          ?
    ActualLength                                            DD          ?
    NodeName                                                DW          1 Dup(?)
USB_NODE_CONNECTION_NAME EndS
PUSB_NODE_CONNECTION_NAME                                   TypeDef     DWord

USB_HUB_NAME Struct
    ActualLength                                            DD          ?
    HubName                                                 DW          1 Dup(?)
USB_HUB_NAME EndS
PUSB_HUB_NAME                                               TypeDef     DWord

USB_ROOT_HUB_NAME Struct
    ActualLength                                            DD          ?
    RootHubName                                             DW          1 Dup(?)
USB_ROOT_HUB_NAME EndS
PUSB_ROOT_HUB_NAME                                          TypeDef     DWord

USB_HCD_DRIVERKEY_NAME Struct
    ActualLength                                            DD          ?
    DriverKeyName                                           DW          1 Dup(?)
USB_HCD_DRIVERKEY_NAME EndS
PUSB_HCD_DRIVERKEY_NAME                                     TypeDef     DWord

USB_DESCRIPTOR_REQUEST Struct
    ConnectionIndex                                         DD          ?
    Struct SetupPacket
        bmRequest                                           DB          ?
        bRequest                                            DB          ?
        wValue                                              DW          ?
        wIndex                                              DW          ?
        wLength                                             DW          ?
    EndS
    Data                                                    DB          0 Dup(?)
USB_DESCRIPTOR_REQUEST EndS
PUSB_DESCRIPTOR_REQUEST                                     TypeDef     DWord

HUBCAPSREC Record                                           HubIs2xCapable:1
USB_HUB_CAPABILITIES Struct
    hubcapsrec                                              HUBCAPSREC  <>
USB_HUB_CAPABILITIES EndS
PUSB_HUB_CAPABILITIES                                       TypeDef     DWord

USB_NODE_CONNECTION_ATTRIBUTES Struct
    ConnectionIndex                                         DD          ?
    ConnectionStatus                                        USB_CONNECTION_STATUS   ?
    PortAttributes                                          DD          ?
USB_NODE_CONNECTION_ATTRIBUTES EndS
PUSB_NODE_CONNECTION_ATTRIBUTES                             TypeDef     DWord

USB_NODE_CONNECTION_INFORMATION_EX Struct
    ConnectionIndex                                         DD          ?
    DeviceDescriptor                                        USB_DEVICE_DESCRIPTOR   <>
    CurrentConfigurationValue                               DB          ?
    Speed                                                   DB          ?
    DeviceIsHub                                             BOOLEAN     ?
    DeviceAddress                                           DW          ?
    NumberOfOpenPipes                                       DD          ?
    ConnectionStatus                                        USB_CONNECTION_STATUS   ?
    PipeList                                                USB_PIPE_INFO   0 Dup(<>)
USB_NODE_CONNECTION_INFORMATION_EX EndS
PUSB_NODE_CONNECTION_INFORMATION_EX                         TypeDef     DWord

HUBFLAGSREC Record                                          HubIsHighSpeedCapable:1, HubIsHighSpeed:1, HubIsMultiTtCapable:1, HubIsMultiTt:1, HubIsRoot:1, HubIsArmedWakeOnConnect:1, HubIsBusPowered:1, ReservedMBZ:25
USB_HUB_CAP_FLAGS Union
    ul                                                      DD          ?
    Struct
    hubflagsrec                                             HUBFLAGSREC <>
    EndS
USB_HUB_CAP_FLAGS EndS
PUSB_HUB_CAP_FLAGS                                          TypeDef     DWord

USB_HUB_CAPABILITIES_EX Struct
    CapabilityFlags                                         USB_HUB_CAP_FLAGS   <>
USB_HUB_CAPABILITIES_EX EndS
PUSB_HUB_CAPABILITIES_EX                                    TypeDef     DWord

USB_CYCLE_PORT_PARAMS Struct
    ConnectionIndex                                         DD          ?
    StatusReturned                                          DD          ?
USB_CYCLE_PORT_PARAMS EndS
PUSB_CYCLE_PORT_PARAMS                                      TypeDef     DWord

USB_ID_STRING Struct
    LanguageId                                              DW          ?
    Pad                                                     DW          ?
    LengthInBytes                                           DD          ?
    Buffer                                                  PWCHAR      ?
USB_ID_STRING EndS
PUSB_ID_STRING                                              TypeDef     DWord

USB_HUB_DEVICE_UXD_SETTINGS Struct
    Version                                                 DD          ?
    PnpGuid                                                 GUID        <>
    OwnerGuid                                               GUID        <>
    DeleteOnShutdown                                        DD          ?
    DeleteOnReload                                          DD          ?
    DeleteOnDisconnect                                      DD          ?
    Reserved                                                DD          5 Dup(?)
USB_HUB_DEVICE_UXD_SETTINGS EndS
PUSB_HUB_DEVICE_UXD_SETTINGS                                TypeDef     DWord

HUB_DEVICE_CONFIG_INFO Struct
    Version                                                 DD          ?
    _Length                                                 DD          ?   ;Length
    HubFlags                                                USB_HUB_CAP_FLAGS   <>
    HardwareIds                                             USB_ID_STRING   <>
    CompatibleIds                                           USB_ID_STRING   <>
    DeviceDescription                                       USB_ID_STRING   <>
    Reserved                                                DD          19 Dup(?)
    UxdSettings                                             USB_HUB_DEVICE_UXD_SETTINGS <>
HUB_DEVICE_CONFIG_INFO EndS
PHUB_DEVICE_CONFIG_INFO                                     TypeDef     DWord

HCD_STAT_COUNTERS Struct
    BytesTransferred                                        DD          ?
    IsoMissedCount                                          DW          ?
    DataOverrunErrorCount                                   DW          ?
    CrcErrorCount                                           DW          ?
    ScheduleOverrunCount                                    DW          ?
    TimeoutErrorCount                                       DW          ?
    InternalHcErrorCount                                    DW          ?
    BufferOverrunErrorCount                                 DW          ?
    SWErrorCount                                            DW          ?
    StallPidCount                                           DW          ?
    PortDisableCount                                        DW          ?
HCD_STAT_COUNTERS EndS
PHCD_STAT_COUNTERS                                          TypeDef     DWord

HCD_ISO_STAT_COUNTERS Struct
    LateUrbs                                                DW          ?
    DoubleBufferedPackets                                   DW          ?
    TransfersCF_5ms                                         DW          ?
    TransfersCF_2ms                                         DW          ?
    TransfersCF_1ms                                         DW          ?
    MaxInterruptLatency                                     DW          ?
    BadStartFrame                                           DW          ?
    StaleUrbs                                               DW          ?
    IsoPacketNotAccesed                                     DW          ?
    IsoPacketHWError                                        DW          ?
    SmallestUrbPacketCount                                  DW          ?
    LargestUrbPacketCount                                   DW          ?
    IsoCRC_Error                                            DW          ?
    IsoOVERRUN_Error                                        DW          ?
    IsoINTERNAL_Error                                       DW          ?
    IsoUNKNOWN_Error                                        DW          ?
    IsoBytesTransferred                                     DD          ?
    LateMissedCount                                         DW          ?
    HWIsoMissedCount                                        DW          ?
    Reserved7                                               DD          8 Dup(?)
HCD_ISO_STAT_COUNTERS EndS
PHCD_ISO_STAT_COUNTERS                                      TypeDef     DWord

HCD_STAT_INFORMATION_1 Struct
    Reserved1                                               DD          ?
    Reserved2                                               DD          ?
    ResetCounters                                           DD          ?
    TimeRead                                                LARGE_INTEGER   <>
    Counters                                                HCD_STAT_COUNTERS   <>
HCD_STAT_INFORMATION_1 EndS
PHCD_STAT_INFORMATION_1                                     TypeDef     DWord

HCD_STAT_INFORMATION_2 Struct
    Reserved1                                               DD          ?
    Reserved2                                               DD          ?
    ResetCounters                                           DD          ?
    TimeRead                                                LARGE_INTEGER   <>
    LockedMemoryUsed                                        DD          ?
    Counters                                                HCD_STAT_COUNTERS   <>
    IsoCounters                                             HCD_ISO_STAT_COUNTERS   <>
HCD_STAT_INFORMATION_2 EndS
PHCD_STAT_INFORMATION_2                                     TypeDef     DWord

WMI_USB_DRIVER_INFORMATION                                  Equ         0
WMI_USB_DRIVER_NOTIFICATION                                 Equ         1
WMI_USB_POWER_DEVICE_ENABLE                                 Equ         2
WMI_USB_HUB_NODE_INFORMATION                                Equ         4

WMI_USB_PERFORMANCE_INFORMATION                             Equ         1
WMI_USB_DEVICE_NODE_INFORMATION                             Equ         2

;USB_NOTIFICATION_TYPE Enumeration
USB_NOTIFICATION_TYPE                                       TypeDef     DWord
EnumerationFailure                                          Equ         0
InsufficentBandwidth                                        Equ         1
InsufficentPower                                            Equ         2
OverCurrent                                                 Equ         3
ResetOvercurrent                                            Equ         4
AcquireBusInfo                                              Equ         5
AcquireHubName                                              Equ         6
AcquireControllerName                                       Equ         7
HubOvercurrent                                              Equ         8
HubPowerChange                                              Equ         9
HubNestedTooDeeply                                          Equ         10
ModernDeviceInLegacyHub                                     Equ         11

USB_NOTIFICATION Struct
    NotificationType                                        USB_NOTIFICATION_TYPE   ?
USB_NOTIFICATION EndS
PUSB_NOTIFICATION                                           TypeDef     DWord

USB_CONNECTION_NOTIFICATION Struct
    NotificationType                                        USB_NOTIFICATION_TYPE   ?
    ConnectionNumber                                        DD          ?
    RequestedBandwidth                                      DD          ?
    EnumerationFailReason                                   DD          ?
    PowerRequested                                          DD          ?
    HubNameLength                                           DD          ?
USB_CONNECTION_NOTIFICATION EndS
PUSB_CONNECTION_NOTIFICATION                                TypeDef     DWord

USB_BUS_NOTIFICATION Struct
    NotificationType                                        USB_NOTIFICATION_TYPE   ?
    TotalBandwidth                                          DD          ?
    ConsumedBandwidth                                       DD          ?
    ControllerNameLength                                    DD          ?
USB_BUS_NOTIFICATION EndS
PUSB_BUS_NOTIFICATION                                       TypeDef     DWord

USB_ACQUIRE_INFO Struct
    NotificationType                                        USB_NOTIFICATION_TYPE   ?
    TotalSize                                               DD          ?
    Buffer                                                  DW          1 Dup(?)
USB_ACQUIRE_INFO EndS
PUSB_ACQUIRE_INFO                                           TypeDef     DWord

USB_NODE_INFO_SIG                                           Equ         A("USBN")

;USB_WMI_DEVICE_NODE_TYPE Enumeration
USB_WMI_DEVICE_NODE_TYPE                                    TypeDef     DWord
UsbDevice                                                   Equ         0
HubDevice                                                   Equ         1
CompositeDevice                                             Equ         2
UsbController                                               Equ         3
PUSB_WMI_DEVICE_NODE_TYPE                                   TypeDef     DWord

USBDSTATREC Record                                          _DeviceConnected:1, DeviceStarted:1
USB_DEVICE_STATE Struct
    usbstatrec                                              USBDSTATREC <>
USB_DEVICE_STATE EndS
PUSB_DEVICE_STATE                                           TypeDef     DWord

USB_HUB_PORT_INFORMATION Struct
    DeviceState                                             USB_DEVICE_STATE    <>
    PortNumber                                              DW          ?
    DeviceAddress                                           DW          ?
    ConnectionIndex                                         DD          ?
    ConnectionStatus                                        USB_CONNECTION_STATUS   ?
USB_HUB_PORT_INFORMATION EndS
PUSB_HUB_PORT_INFORMATION                                   TypeDef     DWord

USB_HUB_DEVICE_INFO Struct
    HubDescriptor                                           USB_HUB_DESCRIPTOR  <>
    HubNumber                                               DD          ?
    DeviceAddress                                           DW          ?
    HubIsSelfPowered                                        BOOLEAN     ?
    HubIsRootHub                                            BOOLEAN     ?
    HubCapabilities                                         USB_HUB_CAPABILITIES    <>
    NumberOfHubPorts                                        DD          ?
    PortInfo                                                USB_HUB_PORT_INFORMATION    1 Dup(<>)
USB_HUB_DEVICE_INFO EndS
PUSB_HUB_DEVICE_INFO                                        TypeDef     DWord

USB_COMPOSITE_FUNCTION_INFO Struct
    FunctionNumber                                          DB          ?
    BaseInterfaceNumber                                     DB          ?
    NumberOfInterfaces                                      DB          ?
    FunctionIsIdle                                          BOOLEAN     ?
USB_COMPOSITE_FUNCTION_INFO EndS
PUSB_COMPOSITE_FUNCTION_INFO                                TypeDef     DWord

USB_COMPOSITE_DEVICE_INFO Struct
    DeviceDescriptor                                        USB_DEVICE_DESCRIPTOR   <>
    CurrentConfigDescriptor                                 USB_CONFIGURATION_DESCRIPTOR    <>
    CurrentConfigurationValue                               DB          ?
    NumberOfFunctions                                       DB          ?
    FunctionInfo                                            USB_COMPOSITE_FUNCTION_INFO 1 Dup(<>)
USB_COMPOSITE_DEVICE_INFO EndS
PUSB_COMPOSITE_DEVICE_INFO                                  TypeDef     DWord

USB_CONTROLLER_DEVICE_INFO Struct
    PciVendorId                                             DD          ?
    PciDeviceId                                             DD          ?
    PciRevision                                             DD          ?
    NumberOfRootPorts                                       DD          ?
    HcFeatureFlags                                          DD          ?
USB_CONTROLLER_DEVICE_INFO EndS
PUSB_CONTROLLER_DEVICE_INFO                                 TypeDef     DWord

USB_DEVICE_INFO Struct
    DeviceState                                             USB_DEVICE_STATE    <>
    PortNumber                                              DW          ?
    DeviceDescriptor                                        USB_DEVICE_DESCRIPTOR   <>
    CurrentConfigurationValue                               DB          ?
    Speed                                                   USB_DEVICE_SPEED    ?
    DeviceAddress                                           DW          ?
    ConnectionIndex                                         DD          ?
    ConnectionStatus                                        USB_CONNECTION_STATUS   ?
    PnpHardwareId                                           DW          128 Dup(?)
    PnpCompatibleId                                         DW          128 Dup(?)
    SerialNumberId                                          DW          128 Dup(?)
    PnpDeviceDescription                                    DW          128 Dup(?)
    NumberOfOpenPipes                                       DD          ?
    PipeList                                                USB_PIPE_INFO   1 Dup(<>)
USB_DEVICE_INFO EndS
PUSB_DEVICE_INFO                                            TypeDef     DWord

USB_DEVICE_NODE_INFO Struct
    Sig                                                     DD          ?
    LengthInBytes                                           DD          ?
    DeviceDescription                                       DW          40 Dup(?)
    NodeType                                                USB_WMI_DEVICE_NODE_TYPE    ?
    BusAddress                                              USB_TOPOLOGY_ADDRESS    <>
    Union
        UsbDeviceInfo                                       USB_DEVICE_INFO <>
        HubDeviceInfo                                       USB_HUB_DEVICE_INFO <>
        CompositeDeviceInfo                                 USB_COMPOSITE_DEVICE_INFO   <>
        ControllerDeviceInfo                                USB_CONTROLLER_DEVICE_INFO  <>
        DeviceInformation                                   DB          4 Dup(?)
    EndS
USB_DEVICE_NODE_INFO EndS
PUSB_DEVICE_NODE_INFO                                       TypeDef     DWord

USB_DEVICE_PERFORMANCE_INFO Struct
    BulkBytes                                               DD          ?
    ControlDataBytes                                        DD          ?
    IsoBytes                                                DD          ?
    InterruptBytes                                          DD          ?
    BulkUrbCount                                            DD          ?
    ControlUrbCount                                         DD          ?
    IsoUrbCount                                             DD          ?
    InterruptUrbCount                                       DD          ?
    AllocedInterrupt                                        DD          6 Dup(?)
    AllocedIso                                              DD          ?
    Total32secBandwidth                                     DD          ?
    TotalTtBandwidth                                        DD          ?
    DeviceDescription                                       DW          60 Dup(?)
    DeviceSpeed                                             USB_DEVICE_SPEED    ?
    TotalIsoLatency                                         DD          ?
    DroppedIsoPackets                                       DD          ?
    TransferErrors                                          DD          ?
    PciInterruptCount                                       DD          ?
    HcIdleState                                             DD          ?
    HcAsyncIdleState                                        DD          ?
    HcAsyncCacheFlushCount                                  DD          ?
    HcPeriodicIdleState                                     DD          ?
    HcPeriodicCacheFlushCount                               DD          ?
USB_DEVICE_PERFORMANCE_INFO EndS
PUSB_DEVICE_PERFORMANCE_INFO                                TypeDef     DWord

ENDIF ;USBIOCTL_INC
