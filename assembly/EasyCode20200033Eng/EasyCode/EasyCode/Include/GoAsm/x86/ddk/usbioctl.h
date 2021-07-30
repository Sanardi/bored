;===========================================================;
;                                                           ;
;     usbioctl.h for Easy Code 2.0 GoAsm 32-bit drivers     ;
;                     (version 1.0.0)                       ;
;                                                           ;
;             Driver Development Kit (32-bit)               ;
;                                                           ;
;              Copyright © Ramon Sala - 2015                ;
;                                                           ;
;===========================================================;

#IFNDEF USBIOCTL_H
#Define USBIOCTL_H 1

#Include usb.h
#Include usbiodef.h

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
    LengthInBytes                                           DD
    NtStatus                                                DD
    UsbdStatus                                              DD
    ConnectStatus                                           DD
    DriverData                                              DB          4 Dup ?
EndS

IOCTL_INTERNAL_USB_RECORD_FAILURE                           Equ         CTL_CODE(FILE_DEVICE_USB, USB_RECORD_FAILURE, METHOD_NEITHER, FILE_ANY_ACCESS)
IOCTL_INTERNAL_USB_GET_DEVICE_HANDLE_EX                     Equ         CTL_CODE(FILE_DEVICE_USB, USB_GET_DEVICE_HANDLE_EX, METHOD_NEITHER, FILE_ANY_ACCESS)
IOCTL_INTERNAL_USB_GET_TT_DEVICE_HANDLE                     Equ         CTL_CODE(FILE_DEVICE_USB, USB_GET_TT_DEVICE_HANDLE, METHOD_NEITHER, FILE_ANY_ACCESS)

USB_TOPOLOGY_ADDRESS Struct
    PciBusNumber                                            DD
    PciDeviceNumber                                         DD
    PciFunctionNumber                                       DD
    Reserved                                                DD
    RootHubPortNumber                                       DW
    HubPortNumber                                           DW          5 Dup ?
    Reserved2                                               DW
EndS
        
IOCTL_INTERNAL_USB_GET_TOPOLOGY_ADDRESS                     Equ         CTL_CODE(FILE_DEVICE_USB, USB_GET_TOPOLOGY_ADDRESS, METHOD_NEITHER, FILE_ANY_ACCESS)

IOCTL_INTERNAL_USB_GET_DEVICE_CONFIG_INFO                   Equ         CTL_CODE(FILE_DEVICE_USB, USB_GET_HUB_CONFIG_INFO, METHOD_NEITHER, FILE_ANY_ACCESS)

#IFNDEF USB_KERNEL_IOCTL
    IOCTL_USB_HCD_GET_STATS_1                               Equ         CTL_CODE(FILE_DEVICE_USB, HCD_GET_STATS_1, METHOD_BUFFERED, FILE_ANY_ACCESS)
    IOCTL_USB_HCD_GET_STATS_2                               Equ         CTL_CODE(FILE_DEVICE_USB, HCD_GET_STATS_2, METHOD_BUFFERED, FILE_ANY_ACCESS)
    IOCTL_USB_HCD_DISABLE_PORT                              Equ         CTL_CODE(FILE_DEVICE_USB, HCD_DISABLE_PORT, METHOD_BUFFERED, FILE_ANY_ACCESS)
    IOCTL_USB_HCD_ENABLE_PORT                               Equ         CTL_CODE(FILE_DEVICE_USB, HCD_ENABLE_PORT, METHOD_BUFFERED, FILE_ANY_ACCESS)
    #IFNDEF IOCTL_USB_DIAGNOSTIC_MODE_ON
        IOCTL_USB_DIAGNOSTIC_MODE_ON                        Equ         CTL_CODE(FILE_DEVICE_USB, HCD_DIAGNOSTIC_MODE_ON, METHOD_BUFFERED, FILE_ANY_ACCESS)
    #ENDIF
    #IFNDEF IOCTL_USB_DIAGNOSTIC_MODE_OFF
        IOCTL_USB_DIAGNOSTIC_MODE_OFF                       Equ         CTL_CODE(FILE_DEVICE_USB, HCD_DIAGNOSTIC_MODE_OFF, METHOD_BUFFERED, FILE_ANY_ACCESS)
    #ENDIF
    #IFNDEF IOCTL_USB_GET_ROOT_HUB_NAME
        IOCTL_USB_GET_ROOT_HUB_NAME                         Equ         CTL_CODE(FILE_DEVICE_USB, HCD_GET_ROOT_HUB_NAME, METHOD_BUFFERED, FILE_ANY_ACCESS)
    #ENDIF
    #IFNDEF IOCTL_GET_HCD_DRIVERKEY_NAME
        IOCTL_GET_HCD_DRIVERKEY_NAME                        Equ         CTL_CODE(FILE_DEVICE_USB, HCD_GET_DRIVERKEY_NAME, METHOD_BUFFERED, FILE_ANY_ACCESS)
    #ENDIF
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
#ENDIF

;USB_HUB_NODE Enumeration
UsbHub                                                      Equ         0
UsbMIParent                                                 Equ         1

USB_HUB_INFORMATION Struct
    HubDescriptor                                           USB_HUB_DESCRIPTOR
    HubIsBusPowered                                         DB
EndS

USB_MI_PARENT_INFORMATION Struct
    NumberOfInterfaces                                      DD
EndS

USB_NODE_INFORMATION Struct
    NodeType                                                DD
    u Union
        HubInformation                                      USB_HUB_INFORMATION
        MiParentInformation                                 USB_MI_PARENT_INFORMATION
    EndUnion
EndS

USB_PIPE_INFO Struct
    EndpointDescriptor                                      USB_ENDPOINT_DESCRIPTOR
    ScheduleOffset                                          DD
EndS

;USB_CONNECTION_STATUS Enumeration
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

USB_NODE_CONNECTION_INFORMATION Struct
    ConnectionIndex                                         DD
    DeviceDescriptor                                        USB_DEVICE_DESCRIPTOR
    CurrentConfigurationValue                               DB
    LowSpeed                                                DB
    DeviceIsHub                                             DB
    DeviceAddress                                           DW
    NumberOfOpenPipes                                       DD
    ConnectionStatus                                        DD
    PipeList                                                USB_PIPE_INFO 0 Dup
EndS

USB_NODE_CONNECTION_DRIVERKEY_NAME Struct
    ConnectionIndex                                         DD
    ActualLength                                            DD
    DriverKeyName                                           DW          1 Dup ?
EndS

USB_NODE_CONNECTION_NAME Struct
    ConnectionIndex                                         DD
    ActualLength                                            DD
    NodeName                                                DW          1 Dup ?
EndS

USB_HUB_NAME Struct
    ActualLength                                            DD
    HubName                                                 DW          1 Dup ?
EndS

USB_ROOT_HUB_NAME Struct
    ActualLength                                            DD
    RootHubName                                             DW          1 Dup ?
EndS

USB_HCD_DRIVERKEY_NAME Struct
    ActualLength                                            DD
    DriverKeyName                                           DW          1 Dup ?
EndS

USB_DESCRIPTOR_REQUEST Struct
    ConnectionIndex                                         DD
    Struct SetupPacket
        bmRequest                                           DB
        bRequest                                            DB
        wValue                                              DW
        wIndex                                              DW
        wLength                                             DW
    EndS
    Data                                                    DB          0 Dup ?
EndS

USB_HUB_CAPABILITIES Struct
    fbits                                                   DB  ;Member HubIs2xCapable is included here
EndS

USB_NODE_CONNECTION_ATTRIBUTES Struct
    ConnectionIndex                                         DD
    ConnectionStatus                                        DD
    PortAttributes                                          DD
EndS

USB_NODE_CONNECTION_INFORMATION_EX Struct
    ConnectionIndex                                         DD
    DeviceDescriptor                                        USB_DEVICE_DESCRIPTOR
    CurrentConfigurationValue                               DB
    Speed                                                   DB
    DeviceIsHub                                             DB
    DeviceAddress                                           DW
    NumberOfOpenPipes                                       DD
    ConnectionStatus                                        DD
    PipeList                                                USB_PIPE_INFO 0 Dup
EndS

USB_HUB_CAP_FLAGS Union
    ul                                                      DD
    Struct
        fbits                                               DD  ;Members HubIsHighSpeedCapable to ReservedMBZ are included here
    EndS
EndUnion

USB_HUB_CAPABILITIES_EX Struct
    CapabilityFlags                                         USB_HUB_CAP_FLAGS
EndS

USB_CYCLE_PORT_PARAMS Struct
    ConnectionIndex                                         DD
    StatusReturned                                          DD
EndS

USB_ID_STRING Struct
    LanguageId                                              DW
    Pad                                                     DW
    LengthInBytes                                           DD
    Buffer                                                  DD
EndS

USB_HUB_DEVICE_UXD_SETTINGS Struct
    Version                                                 DD
    PnpGuid                                                 GUID
    OwnerGuid                                               GUID
    DeleteOnShutdown                                        DD
    DeleteOnReload                                          DD
    DeleteOnDisconnect                                      DD
    Reserved                                                DD          5 Dup ?
EndS

HUB_DEVICE_CONFIG_INFO Struct
    Version                                                 DD
    Length                                                  DD
    HubFlags                                                USB_HUB_CAP_FLAGS
    HardwareIds                                             USB_ID_STRING
    CompatibleIds                                           USB_ID_STRING
    DeviceDescription                                       USB_ID_STRING
    Reserved                                                DD          19 Dup ?
    UxdSettings                                             USB_HUB_DEVICE_UXD_SETTINGS
EndS

HCD_STAT_COUNTERS Struct
    BytesTransferred                                        DD
    IsoMissedCount                                          DW
    DataOverrunErrorCount                                   DW
    CrcErrorCount                                           DW
    ScheduleOverrunCount                                    DW
    TimeoutErrorCount                                       DW
    InternalHcErrorCount                                    DW
    BufferOverrunErrorCount                                 DW
    SWErrorCount                                            DW
    StallPidCount                                           DW
    PortDisableCount                                        DW
EndS

HCD_ISO_STAT_COUNTERS Struct
    LateUrbs                                                DW
    DoubleBufferedPackets                                   DW
    TransfersCF_5ms                                         DW
    TransfersCF_2ms                                         DW
    TransfersCF_1ms                                         DW
    MaxInterruptLatency                                     DW
    BadStartFrame                                           DW
    StaleUrbs                                               DW
    IsoPacketNotAccesed                                     DW
    IsoPacketHWError                                        DW
    SmallestUrbPacketCount                                  DW
    LargestUrbPacketCount                                   DW
    IsoCRC_Error                                            DW
    IsoOVERRUN_Error                                        DW
    IsoINTERNAL_Error                                       DW
    IsoUNKNOWN_Error                                        DW
    IsoBytesTransferred                                     DD
    LateMissedCount                                         DW
    HWIsoMissedCount                                        DW
    Reserved7                                               DD          8 Dup ?
EndS

HCD_STAT_INFORMATION_1 Struct
    Reserved1                                               DD
    Reserved2                                               DD
    ResetCounters                                           DD
    TimeRead                                                LARGE_INTEGER
    Counters                                                HCD_STAT_COUNTERS
EndS

HCD_STAT_INFORMATION_2 Struct
    Reserved1                                               DD
    Reserved2                                               DD
    ResetCounters                                           DD
    TimeRead                                                LARGE_INTEGER
    LockedMemoryUsed                                        DD
    Counters                                                HCD_STAT_COUNTERS
    IsoCounters                                             HCD_ISO_STAT_COUNTERS
EndS

WMI_USB_DRIVER_INFORMATION                                  Equ         0
WMI_USB_DRIVER_NOTIFICATION                                 Equ         1
WMI_USB_POWER_DEVICE_ENABLE                                 Equ         2
WMI_USB_HUB_NODE_INFORMATION                                Equ         4

WMI_USB_PERFORMANCE_INFORMATION                             Equ         1
WMI_USB_DEVICE_NODE_INFORMATION                             Equ         2

;USB_NOTIFICATION_TYPE Enumeration
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
    NotificationType                                        DD
EndS

USB_CONNECTION_NOTIFICATION Struct
    NotificationType                                        DD
    ConnectionNumber                                        DD
    RequestedBandwidth                                      DD
    EnumerationFailReason                                   DD
    PowerRequested                                          DD
    HubNameLength                                           DD
EndS

USB_BUS_NOTIFICATION Struct
    NotificationType                                        DD
    TotalBandwidth                                          DD
    ConsumedBandwidth                                       DD
    ControllerNameLength                                    DD
EndS

USB_ACQUIRE_INFO Struct
    NotificationType                                        DD
    TotalSize                                               DD
    Buffer                                                  DW          1 Dup ?
EndS

#Define                                                     USB_NODE_INFO_SIG "USBN"

;USB_WMI_DEVICE_NODE_TYPE Enumeration
UsbDevice                                                   Equ         0
HubDevice                                                   Equ         1
CompositeDevice                                             Equ         2
UsbController                                               Equ         3

USB_DEVICE_STATE Struct
    fbits                                                   DB  ;Members DeviceConnected to DeviceStarted are included here
EndS

USB_HUB_PORT_INFORMATION Struct
    DeviceState                                             USB_DEVICE_STATE
    PortNumber                                              DW
    DeviceAddress                                           DW
    ConnectionIndex                                         DD
    ConnectionStatus                                        DD
EndS

USB_HUB_DEVICE_INFO Struct
    HubDescriptor                                           USB_HUB_DESCRIPTOR
    HubNumber                                               DD
    DeviceAddress                                           DW
    HubIsSelfPowered                                        DB
    HubIsRootHub                                            DB
    HubCapabilities                                         USB_HUB_CAPABILITIES
    NumberOfHubPorts                                        DD
    PortInfo                                                USB_HUB_PORT_INFORMATION    1 Dup
EndS

USB_COMPOSITE_FUNCTION_INFO Struct
    FunctionNumber                                          DB
    BaseInterfaceNumber                                     DB
    NumberOfInterfaces                                      DB
    FunctionIsIdle                                          DB
EndS

USB_COMPOSITE_DEVICE_INFO Struct
    DeviceDescriptor                                        USB_DEVICE_DESCRIPTOR
    CurrentConfigDescriptor                                 USB_CONFIGURATION_DESCRIPTOR
    CurrentConfigurationValue                               DB
    NumberOfFunctions                                       DB
    FunctionInfo                                            USB_COMPOSITE_FUNCTION_INFO 1 Dup
EndS

USB_CONTROLLER_DEVICE_INFO Struct
    PciVendorId                                             DD
    PciDeviceId                                             DD
    PciRevision                                             DD
    NumberOfRootPorts                                       DD
    HcFeatureFlags                                          DD
EndS

USB_DEVICE_INFO Struct
    DeviceState                                             USB_DEVICE_STATE
    PortNumber                                              DW
    DeviceDescriptor                                        USB_DEVICE_DESCRIPTOR
    CurrentConfigurationValue                               DB
    Speed                                                   DD
    DeviceAddress                                           DW
    ConnectionIndex                                         DD
    ConnectionStatus                                        DD
    PnpHardwareId                                           DW          128 Dup ?
    PnpCompatibleId                                         DW          128 Dup ?
    SerialNumberId                                          DW          128 Dup ?
    PnpDeviceDescription                                    DW          128 Dup ?
    NumberOfOpenPipes                                       DD          ?
    PipeList                                                USB_PIPE_INFO   1 Dup
EndS

USB_DEVICE_NODE_INFO Struct
    Sig                                                     DD
    LengthInBytes                                           DD
    DeviceDescription                                       DW          40 Dup ?
    NodeType                                                DD
    BusAddress                                              USB_TOPOLOGY_ADDRESS
    Union
        UsbDeviceInfo                                       USB_DEVICE_INFO
        HubDeviceInfo                                       USB_HUB_DEVICE_INFO
        CompositeDeviceInfo                                 USB_COMPOSITE_DEVICE_INFO
        ControllerDeviceInfo                                USB_CONTROLLER_DEVICE_INFO
        DeviceInformation                                   DB          4 Dup ?
    EndUnion
EndS

USB_DEVICE_PERFORMANCE_INFO Struct
    BulkBytes                                               DD
    ControlDataBytes                                        DD
    IsoBytes                                                DD
    InterruptBytes                                          DD
    BulkUrbCount                                            DD
    ControlUrbCount                                         DD
    IsoUrbCount                                             DD
    InterruptUrbCount                                       DD
    AllocedInterrupt                                        DD          6 Dup ?
    AllocedIso                                              DD
    Total32secBandwidth                                     DD
    TotalTtBandwidth                                        DD
    DeviceDescription                                       DW          60 Dup ?
    DeviceSpeed                                             DD
    TotalIsoLatency                                         DD
    DroppedIsoPackets                                       DD
    TransferErrors                                          DD
    PciInterruptCount                                       DD
    HcIdleState                                             DD
    HcAsyncIdleState                                        DD
    HcAsyncCacheFlushCount                                  DD
    HcPeriodicIdleState                                     DD
    HcPeriodicCacheFlushCount                               DD
EndS

#ENDIF ;USBIOCTL_H
