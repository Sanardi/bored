;===========================================================;
;                                                           ;
;     usbuser.h for Easy Code 2.0 GoAsm 32-bit drivers      ;
;                     (version 1.0.0)                       ;
;                                                           ;
;             Driver Development Kit (32-bit)               ;
;                                                           ;
;              Copyright © Ramon Sala - 2015                ;
;                                                           ;
;===========================================================;

#IFNDEF USBUSER_H
#Define USBUSER_H 1

#Include usbiodef.h
#IFNDEF USB_H
    #Include usb.h
#ENDIF

USBUSER_VERSION                                             Equ         00000004H

IOCTL_USB_USER_REQUEST                                      Equ         USB_CTL(HCD_USER_REQUEST)

#IFNDEF IOCTL_USB_DIAGNOSTIC_MODE_ON
    IOCTL_USB_DIAGNOSTIC_MODE_ON                            Equ         USB_CTL(HCD_DIAGNOSTIC_MODE_ON)
#ENDIF
#IFNDEF IOCTL_USB_DIAGNOSTIC_MODE_OFF
    IOCTL_USB_DIAGNOSTIC_MODE_OFF                           Equ         USB_CTL(HCD_DIAGNOSTIC_MODE_OFF)
#ENDIF

#IFNDEF IOCTL_USB_GET_ROOT_HUB_NAME
    IOCTL_USB_GET_ROOT_HUB_NAME                             Equ         USB_CTL(HCD_GET_ROOT_HUB_NAME)
#ENDIF
#IFNDEF IOCTL_GET_HCD_DRIVERKEY_NAME
    IOCTL_GET_HCD_DRIVERKEY_NAME                            Equ         USB_CTL(HCD_GET_DRIVERKEY_NAME)
#ENDIF

;USB_USER_ERROR_CODE Enumeration
UsbUserSuccess                                              Equ         0
UsbUserNotSupported                                         Equ         1
UsbUserInvalidRequestCode                                   Equ         2
UsbUserFeatureDisabled                                      Equ         3
UsbUserInvalidHeaderParameter                               Equ         4
UsbUserInvalidParameter                                     Equ         5
UsbUserMiniportError                                        Equ         6
UsbUserBufferTooSmall                                       Equ         7
UsbUserErrorNotMapped                                       Equ         8
UsbUserDeviceNotStarted                                     Equ         9
UsbUserNoDeviceConnected                                    Equ         10

USBUSER_GET_CONTROLLER_INFO_0                               Equ         00000001H
USBUSER_GET_CONTROLLER_DRIVER_KEY                           Equ         00000002H
USBUSER_PASS_THRU                                           Equ         00000003H
USBUSER_GET_POWER_STATE_MAP                                 Equ         00000004H
USBUSER_GET_BANDWIDTH_INFORMATION                           Equ         00000005H
USBUSER_GET_BUS_STATISTICS_0                                Equ         00000006H
USBUSER_GET_ROOTHUB_SYMBOLIC_NAME                           Equ         00000007H
USBUSER_GET_USB_DRIVER_VERSION                              Equ         00000008H
USBUSER_GET_USB2_HW_VERSION                                 Equ         00000009H
USBUSER_USB_REFRESH_HCT_REG                                 Equ         0000000AH

USBUSER_OP_SEND_ONE_PACKET                                  Equ         10000001H

USBUSER_OP_RAW_RESET_PORT                                   Equ         20000001H
USBUSER_OP_OPEN_RAW_DEVICE                                  Equ         20000002H
USBUSER_OP_CLOSE_RAW_DEVICE                                 Equ         20000003H
USBUSER_OP_SEND_RAW_COMMAND                                 Equ         20000004H

USBUSER_SET_ROOTPORT_FEATURE                                Equ         20000005H
USBUSER_CLEAR_ROOTPORT_FEATURE                              Equ         20000006H
USBUSER_GET_ROOTPORT_STATUS                                 Equ         20000007H

USBUSER_INVALID_REQUEST                                     Equ         0FFFFFFF0H

USBUSER_OP_MASK_DEVONLY_API                                 Equ         10000000H
USBUSER_OP_MASK_HCTEST_API                                  Equ         20000000H

USBUSER_REQUEST_HEADER Struct
    UsbUserRequest                                          DD
    UsbUserStatusCode                                       DD
    RequestBufferLength                                     DD
    ActualBufferLength                                      DD
EndS

USB_PACKETFLAG_LOW_SPEED                                    Equ         00000001H
USB_PACKETFLAG_FULL_SPEED                                   Equ         00000002H
USB_PACKETFLAG_HIGH_SPEED                                   Equ         00000004H

USB_PACKETFLAG_ASYNC_IN                                     Equ         00000008H
USB_PACKETFLAG_ASYNC_OUT                                    Equ         00000010H
USB_PACKETFLAG_ISO_IN                                       Equ         00000020H
USB_PACKETFLAG_ISO_OUT                                      Equ         00000040H
USB_PACKETFLAG_SETUP                                        Equ         00000080H

USB_PACKETFLAG_TOGGLE0                                      Equ         00000100H
USB_PACKETFLAG_TOGGLE1                                      Equ         00000200H

PACKET_PARAMETERS Struct
    DeviceAddress                                           DB
    EndpointAddress                                         DB
    MaximumPacketSize                                       DW
    Timeout                                                 DD
    Flags                                                   DD
    DataLength                                              DD
    HubDeviceAddress                                        DW
    PortTTNumber                                            DW
    ErrorCount                                              DB
    Pad                                                     DB          3 Dup ?
    UsbdStatusCode                                          DD
    Data                                                    DB          4 Dup ?
EndS

USBUSER_SEND_ONE_PACKET Struct
    Header                                                  USBUSER_REQUEST_HEADER
    PacketParameters                                        PACKET_PARAMETERS
EndS

RAW_RESET_PORT_PARAMETERS Struct
    PortNumber                                              DW
    PortStatus                                              DW
EndS

USBUSER_RAW_RESET_ROOT_PORT Struct
    Header                                                  USBUSER_REQUEST_HEADER
    Parameters                                              RAW_RESET_PORT_PARAMETERS
EndS

RAW_ROOTPORT_FEATURE Struct
    PortNumber                                              DW
    PortFeature                                             DW
    PortStatus                                              DW
EndS

USBUSER_ROOTPORT_FEATURE_REQUEST Struct
    Header                                                  USBUSER_REQUEST_HEADER
    Parameters                                              RAW_ROOTPORT_FEATURE
EndS

RAW_ROOTPORT_PARAMETERS Struct
    PortNumber                                              DW
    PortStatus                                              DW
EndS

USBUSER_ROOTPORT_PARAMETERS Struct
    Header                                                  USBUSER_REQUEST_HEADER
    Parameters                                              RAW_ROOTPORT_PARAMETERS
EndS

USB_HC_FEATURE_FLAG_PORT_POWER_SWITCHING                    Equ         00000001H
USB_HC_FEATURE_FLAG_SEL_SUSPEND                             Equ         00000002H
USB_HC_FEATURE_LEGACY_BIOS                                  Equ         00000004H

USB_CONTROLLER_INFO_0 Struct
    PciVendorId                                             DD
    PciDeviceId                                             DD
    PciRevision                                             DD
    NumberOfRootPorts                                       DD
    ControllerFlavor                                        USB_CONTROLLER_FLAVOR ?
    HcFeatureFlags                                          DD
EndS

USBUSER_CONTROLLER_INFO_0 Struct
    Header                                                  USBUSER_REQUEST_HEADER
    Info0                                                   USB_CONTROLLER_INFO_0
USBUSER_CONTROLLER_INFO_0 EndS

USB_UNICODE_NAME Struct
    Length                                                  DD
    String                                                  DW          1 Dup ?
EndS

USBUSER_CONTROLLER_UNICODE_NAME Struct
    Header                                                  USBUSER_REQUEST_HEADER
    UnicodeName                                             USB_UNICODE_NAME
EndS

USB_PASS_THRU_PARAMETERS Struct
    FunctionGUID                                            GUID
    ParameterLength                                         DD
    Parameters                                              DB          4 Dup ?
EndS

USBUSER_PASS_THRU_REQUEST Struct
    Header                                                  USBUSER_REQUEST_HEADER
    PassThru                                                USB_PASS_THRU_PARAMETERS
EndS

;WDMUSB_POWER_STATE Enumeration
WdmUsbPowerNotMapped                                        Equ         0
WdmUsbPowerSystemUnspecified                                Equ         100
WdmUsbPowerSystemWorking                                    Equ         101
WdmUsbPowerSystemSleeping1                                  Equ         102
WdmUsbPowerSystemSleeping2                                  Equ         103
WdmUsbPowerSystemSleeping3                                  Equ         104
WdmUsbPowerSystemHibernate                                  Equ         105
WdmUsbPowerSystemShutdown                                   Equ         106
WdmUsbPowerDeviceUnspecified                                Equ         200
WdmUsbPowerDeviceD0                                         Equ         201
WdmUsbPowerDeviceD1                                         Equ         202
WdmUsbPowerDeviceD2                                         Equ         203
WdmUsbPowerDeviceD3                                         Equ         204

USB_POWER_INFO Struct
    SystemState                                             DD
    HcDevicePowerState                                      DD
    HcDeviceWake                                            DD
    HcSystemWake                                            DD
    RhDevicePowerState                                      DD
    RhDeviceWake                                            DD
    RhSystemWake                                            DD
    LastSystemSleepState                                    DD
    CanWakeup                                               DB
    IsPowered                                               DB
EndS

USBUSER_POWER_INFO_REQUEST Struct
    Header                                                  USBUSER_REQUEST_HEADER
    PowerInformation                                        USB_POWER_INFO
EndS

USB_OPEN_RAW_DEVICE_PARAMETERS  Struct
    PortStatus                                              DW
    MaxPacketEp0                                            DW
EndS

USBUSER_OPEN_RAW_DEVICE Struct
    Header                                                  USBUSER_REQUEST_HEADER
    Parameters                                              USB_OPEN_RAW_DEVICE_PARAMETERS
EndS

USB_CLOSE_RAW_DEVICE_PARAMETERS  Struct
    xxx                                                     DD
EndS

USBUSER_CLOSE_RAW_DEVICE Struct
    Header                                                  USBUSER_REQUEST_HEADER
    Parameters                                              USB_CLOSE_RAW_DEVICE_PARAMETERS
EndS

USB_SEND_RAW_COMMAND_PARAMETERS Struct
    Usb_bmRequest                                           DB
    Usb_bRequest                                            DB
    Usb_wVlaue                                              DW
    Usb_wIndex                                              DW
    Usb_wLength                                             DW
    DeviceAddress                                           DW
    MaximumPacketSize                                       DW
    Timeout                                                 DD
    DataLength                                              DD
    UsbdStatusCode                                          DD
    Data                                                    DB          4 Dup ?
EndS

USBUSER_SEND_RAW_COMMAND Struct
    Header                                                  USBUSER_REQUEST_HEADER
    Parameters                                              USB_SEND_RAW_COMMAND_PARAMETERS
EndS

USB_BANDWIDTH_INFO Struct
    DeviceCount                                             DD
    TotalBusBandwidth                                       DD
    Total32secBandwidth                                     DD
    AllocedBulkAndControl                                   DD
    AllocedIso                                              DD
    AllocedInterrupt_1ms                                    DD
    AllocedInterrupt_2ms                                    DD
    AllocedInterrupt_4ms                                    DD
    AllocedInterrupt_8ms                                    DD
    AllocedInterrupt_16ms                                   DD
    AllocedInterrupt_32ms                                   DD
EndS

USBUSER_BANDWIDTH_INFO_REQUEST Struct
    Header                                                  USBUSER_REQUEST_HEADER
    BandwidthInformation                                    USB_BANDWIDTH_INFO
EndS

USB_BUS_STATISTICS_0 Struct
    DeviceCount                                             DD
    CurrentSystemTime                                       LARGE_INTEGER
    CurrentUsbFrame                                         DD
    BulkBytes                                               DD
    IsoBytes                                                DD
    InterruptBytes                                          DD
    ControlDataBytes                                        DD
    PciInterruptCount                                       DD
    HardResetCount                                          DD
    WorkerSignalCount                                       DD
    CommonBufferBytes                                       DD
    WorkerIdleTimeMs                                        DD
    RootHubEnabled                                          DB
    RootHubDevicePowerState                                 DB
    Unused                                                  DB
    NameIndex                                               DB
EndS

USBUSER_BUS_STATISTICS_0_REQUEST Struct
    Header                                                  USBUSER_REQUEST_HEADER
    BusStatistics0                                          USB_BUS_STATISTICS_0
EndS

USB_DRIVER_VERSION_PARAMETERS Struct
    DriverTrackingCode                                      DD
    USBDI_Version                                           DD
    USBUSER_Version                                         DD
    CheckedPortDriver                                       DB
    CheckedMiniportDriver                                   DB
    USB_Version                                             DW
EndS

USBUSER_GET_DRIVER_VERSION Struct
    Header                                                  USBUSER_REQUEST_HEADER
    Parameters                                              USB_DRIVER_VERSION_PARAMETERS
EndS

USB_USB2HW_VERSION_PARAMETERS Struct
    Usb2HwRevision                                          DB
EndS

USBUSER_GET_USB2HW_VERSION Struct
    Header                                                  USBUSER_REQUEST_HEADER
    Parameters                                              USB_USB2HW_VERSION_PARAMETERS
EndS

USBUSER_REFRESH_HCT_REG Struct
    Header                                                  USBUSER_REQUEST_HEADER
    Flags                                                   DD
Ends

#ENDIF ;USBUSER_H
