;===========================================================;
;                                                           ;
;       usb.h for Easy Code 2.0 GoAsm 32-bit drivers        ;
;                     (version 1.0.0)                       ;
;                                                           ;
;             Driver Development Kit (32-bit)               ;
;                                                           ;
;              Copyright © Ramon Sala - 2015                ;
;                                                           ;
;===========================================================;

#IFNDEF USB_H
#Define USB_H 1

USBDI_VERSION                                               Equ         00000600H

#Include usb200.h
#IFNDEF MACRODRV_H
    #Include macrodrv.h
#ENDIF

USB_PORTATTR_NO_CONNECTOR                                   Equ         00000001H
USB_PORTATTR_SHARED_USB2                                    Equ         00000002H
USB_PORTATTR_MINI_CONNECTOR                                 Equ         00000004H
USB_PORTATTR_OEM_CONNECTOR                                  Equ         00000008H

USB_PORTATTR_OWNED_BY_CC                                    Equ         01000000H
USB_PORTATTR_NO_OVERCURRENT_UI                              Equ         02000000H

;USB_CONTROLLER_FLAVOR Enumeration
USB_HcGeneric                                               Equ         0
OHCI_Generic                                                Equ         100
OHCI_Hydra                                                  Equ         101
OHCI_NEC                                                    Equ         102
UHCI_Generic                                                Equ         200
UHCI_Piix4                                                  Equ         201
UHCI_Piix3                                                  Equ         202
UHCI_Ich2                                                   Equ         203
UHCI_Reserved204                                            Equ         204
UHCI_Ich1                                                   Equ         205
UHCI_Ich3m                                                  Equ         206
UHCI_Ich4                                                   Equ         207
UHCI_Ich5                                                   Equ         208
UHCI_Ich6                                                   Equ         209
UHCI_Intel                                                  Equ         249
UHCI_VIA                                                    Equ         250
UHCI_VIA_x01                                                Equ         251
UHCI_VIA_x02                                                Equ         252
UHCI_VIA_x03                                                Equ         253
UHCI_VIA_x04                                                Equ         254
UHCI_VIA_x0E_FIFO                                           Equ         264
EHCI_Generic                                                Equ         1000
EHCI_NEC                                                    Equ         2000
EHCI_Lucent                                                 Equ         3000

USB_DEFAULT_DEVICE_ADDRESS                                  Equ         0
USB_DEFAULT_ENDPOINT_ADDRESS                                Equ         0

USB_DEFAULT_MAX_PACKET                                      Equ         64

URB_FUNCTION_SELECT_CONFIGURATION                           Equ         0000H
URB_FUNCTION_SELECT_INTERFACE                               Equ         0001H
URB_FUNCTION_ABORT_PIPE                                     Equ         0002H
URB_FUNCTION_TAKE_FRAME_LENGTH_CONTROL                      Equ         0003H
URB_FUNCTION_RELEASE_FRAME_LENGTH_CONTROL                   Equ         0004H
URB_FUNCTION_GET_FRAME_LENGTH                               Equ         0005H
URB_FUNCTION_SET_FRAME_LENGTH                               Equ         0006H
URB_FUNCTION_GET_CURRENT_FRAME_NUMBER                       Equ         0007H
URB_FUNCTION_CONTROL_TRANSFER                               Equ         0008H
URB_FUNCTION_BULK_OR_INTERRUPT_TRANSFER                     Equ         0009H
URB_FUNCTION_ISOCH_TRANSFER                                 Equ         000AH
URB_FUNCTION_GET_DESCRIPTOR_FROM_DEVICE                     Equ         000BH
URB_FUNCTION_SET_DESCRIPTOR_TO_DEVICE                       Equ         000CH
URB_FUNCTION_SET_FEATURE_TO_DEVICE                          Equ         000DH
URB_FUNCTION_SET_FEATURE_TO_INTERFACE                       Equ         000EH
URB_FUNCTION_SET_FEATURE_TO_ENDPOINT                        Equ         000FH
URB_FUNCTION_CLEAR_FEATURE_TO_DEVICE                        Equ         0010H
URB_FUNCTION_CLEAR_FEATURE_TO_INTERFACE                     Equ         0011H
URB_FUNCTION_CLEAR_FEATURE_TO_ENDPOINT                      Equ         0012H
URB_FUNCTION_GET_STATUS_FROM_DEVICE                         Equ         0013H
URB_FUNCTION_GET_STATUS_FROM_INTERFACE                      Equ         0014H
URB_FUNCTION_GET_STATUS_FROM_ENDPOINT                       Equ         0015H
URB_FUNCTION_RESERVED_0X0016                                Equ         0016H
URB_FUNCTION_VENDOR_DEVICE                                  Equ         0017H
URB_FUNCTION_VENDOR_INTERFACE                               Equ         0018H
URB_FUNCTION_VENDOR_ENDPOINT                                Equ         0019H
URB_FUNCTION_CLASS_DEVICE                                   Equ         001AH
URB_FUNCTION_CLASS_INTERFACE                                Equ         001BH
URB_FUNCTION_CLASS_ENDPOINT                                 Equ         001CH
URB_FUNCTION_RESERVE_0X001D                                 Equ         001DH
URB_FUNCTION_SYNC_RESET_PIPE_AND_CLEAR_STALL                Equ         001EH
URB_FUNCTION_CLASS_OTHER                                    Equ         001FH
URB_FUNCTION_VENDOR_OTHER                                   Equ         0020H
URB_FUNCTION_GET_STATUS_FROM_OTHER                          Equ         0021H
URB_FUNCTION_CLEAR_FEATURE_TO_OTHER                         Equ         0022H
URB_FUNCTION_SET_FEATURE_TO_OTHER                           Equ         0023H
URB_FUNCTION_GET_DESCRIPTOR_FROM_ENDPOINT                   Equ         0024H
URB_FUNCTION_SET_DESCRIPTOR_TO_ENDPOINT                     Equ         0025H
URB_FUNCTION_GET_CONFIGURATION                              Equ         0026H
URB_FUNCTION_GET_INTERFACE                                  Equ         0027H
URB_FUNCTION_GET_DESCRIPTOR_FROM_INTERFACE                  Equ         0028H
URB_FUNCTION_SET_DESCRIPTOR_TO_INTERFACE                    Equ         0029H

URB_FUNCTION_GET_MS_FEATURE_DESCRIPTOR                      Equ         002AH
URB_FUNCTION_SYNC_RESET_PIPE                                Equ         0030H
URB_FUNCTION_SYNC_CLEAR_STALL                               Equ         0031H

URB_FUNCTION_CONTROL_TRANSFER_EX                            Equ         0032H
URB_FUNCTION_RESERVE_0X0033                                 Equ         0033H
URB_FUNCTION_RESERVE_0X0034                                 Equ         0034H

URB_FUNCTION_RESERVE_0X002B                                 Equ         002BH
URB_FUNCTION_RESERVE_0X002C                                 Equ         002CH
URB_FUNCTION_RESERVE_0X002D                                 Equ         002DH
URB_FUNCTION_RESERVE_0X002E                                 Equ         002EH
URB_FUNCTION_RESERVE_0X002F                                 Equ         002FH

URB_FUNCTION_RESET_PIPE                                     Equ         URB_FUNCTION_SYNC_RESET_PIPE_AND_CLEAR_STALL

USBD_TRANSFER_DIRECTION                                     Equ         00000001H

USBD_SHORT_TRANSFER_OK                                      Equ         00000002H

USBD_START_ISO_TRANSFER_ASAP                                Equ         00000004H
USBD_DEFAULT_PIPE_TRANSFER                                  Equ         00000008H

USBD_TRANSFER_DIRECTION_OUT                                 Equ         0
USBD_TRANSFER_DIRECTION_IN                                  Equ         1

VALID_TRANSFER_FLAGS_MASK                                   Equ         (USBD_SHORT_TRANSFER_OK | USBD_TRANSFER_DIRECTION | USBD_START_ISO_TRANSFER_ASAP | USBD_DEFAULT_PIPE_TRANSFER)

USBD_ISO_START_FRAME_RANGE                                  Equ         1024

USBD_STATUS_SUCCESS                                         Equ         (00000000H)
USBD_STATUS_PENDING                                         Equ         (40000000H)

USBD_STATUS_CRC                                             Equ         (0C0000001H)
USBD_STATUS_BTSTUFF                                         Equ         (0C0000002H)
USBD_STATUS_DATA_TOGGLE_MISMATCH                            Equ         (0C0000003H)
USBD_STATUS_STALL_PID                                       Equ         (0C0000004H)
USBD_STATUS_DEV_NOT_RESPONDING                              Equ         (0C0000005H)
USBD_STATUS_PID_CHECK_FAILURE                               Equ         (0C0000006H)
USBD_STATUS_UNEXPECTED_PID                                  Equ         (0C0000007H)
USBD_STATUS_DATA_OVERRUN                                    Equ         (0C0000008H)
USBD_STATUS_DATA_UNDERRUN                                   Equ         (0C0000009H)
USBD_STATUS_RESERVED1                                       Equ         (0C000000AH)
USBD_STATUS_RESERVED2                                       Equ         (0C000000BH)
USBD_STATUS_BUFFER_OVERRUN                                  Equ         (0C000000CH)
USBD_STATUS_BUFFER_UNDERRUN                                 Equ         (0C000000DH)
USBD_STATUS_NOT_ACCESSED                                    Equ         (0C000000FH)
USBD_STATUS_FIFO                                            Equ         (0C0000010H)

USBD_STATUS_XACT_ERROR                                      Equ         (0C0000011H)
USBD_STATUS_BABBLE_DETECTED                                 Equ         (0C0000012H)
USBD_STATUS_DATA_BUFFER_ERROR                               Equ         (0C0000013H)

USBD_STATUS_ENDPOINT_HALTED                                 Equ         (0C0000030H)

USBD_STATUS_INVALID_URB_FUNCTION                            Equ         (080000200H)
USBD_STATUS_INVALID_PARAMETER                               Equ         (080000300H)

USBD_STATUS_ERROR_BUSY                                      Equ         (080000400H)

USBD_STATUS_INVALID_PIPE_HANDLE                             Equ         (080000600H)

USBD_STATUS_NO_BANDWIDTH                                    Equ         (080000700H)

USBD_STATUS_INTERNAL_HC_ERROR                               Equ         (080000800H)

USBD_STATUS_ERROR_SHORT_TRANSFER                            Equ         (080000900H)

USBD_STATUS_BAD_START_FRAME                                 Equ         (0C0000A00H)

USBD_STATUS_ISOCH_REQUEST_FAILED                            Equ         (0C0000B00H)

USBD_STATUS_FRAME_CONTROL_OWNED                             Equ         (0C0000C00H)

USBD_STATUS_FRAME_CONTROL_NOT_OWNED                         Equ         (0C0000D00H)

USBD_STATUS_NOT_SUPPORTED                                   Equ         (0C0000E00H)

USBD_STATUS_INAVLID_CONFIGURATION_DESCRIPTOR                Equ         (0C0000F00H)

USBD_STATUS_INVALID_CONFIGURATION_DESCRIPTOR                Equ         (0C0000F00H)

USBD_STATUS_INSUFFICIENT_RESOURCES                          Equ         (0C0001000H)

USBD_STATUS_SET_CONFIG_FAILED                               Equ         (0C0002000H)

USBD_STATUS_BUFFER_TOO_SMALL                                Equ         (0C0003000H)

USBD_STATUS_INTERFACE_NOT_FOUND                             Equ         (0C0004000H)

USBD_STATUS_INAVLID_PIPE_FLAGS                              Equ         (0C0005000H)

USBD_STATUS_TIMEOUT                                         Equ         (0C0006000H)

USBD_STATUS_DEVICE_GONE                                     Equ         (0C0007000H)

USBD_STATUS_STATUS_NOT_MAPPED                               Equ         (0C0008000H)

USBD_STATUS_HUB_INTERNAL_ERROR                              Equ         (0C0009000H)

USBD_STATUS_CANCELED                                        Equ         (0C0010000H)

USBD_STATUS_ISO_NOT_ACCESSED_BY_HW                          Equ         (0C0020000H)

USBD_STATUS_ISO_TD_ERROR                                    Equ         (0C0030000H)

USBD_STATUS_ISO_NA_LATE_USBPORT                             Equ         (0C0040000H)

USBD_STATUS_ISO_NOT_ACCESSED_LATE                           Equ         (0C0050000H)

USBD_STATUS_BAD_DESCRIPTOR                                  Equ         (0C0100000H)
USBD_STATUS_BAD_DESCRIPTOR_BLEN                             Equ         (0C0100001H)
USBD_STATUS_BAD_DESCRIPTOR_TYPE                             Equ         (0C0100002H)
USBD_STATUS_BAD_INTERFACE_DESCRIPTOR                        Equ         (0C0100003H)
USBD_STATUS_BAD_ENDPOINT_DESCRIPTOR                         Equ         (0C0100004H)
USBD_STATUS_BAD_INTERFACE_ASSOC_DESCRIPTOR                  Equ         (0C0100005H)
USBD_STATUS_BAD_CONFIG_DESC_LENGTH                          Equ         (0C0100006H)
USBD_STATUS_BAD_NUMBER_OF_INTERFACES                        Equ         (0C0100007H)
USBD_STATUS_BAD_NUMBER_OF_ENDPOINTS                         Equ         (0C0100008H)
USBD_STATUS_BAD_ENDPOINT_ADDRESS                            Equ         (0C0100009H)

USBD_VERSION_INFORMATION Struct
    USBDI_Version                                           DD
    Supported_USB_Version                                   DD
EndS

;USBD_PIPE_TYPE Eumeration
UsbdPipeTypeControl                                         Equ         0
UsbdPipeTypeIsochronous                                     Equ         1
UsbdPipeTypeBulk                                            Equ         2
UsbdPipeTypeInterrupt                                       Equ         3

USBD_DEVICE_INFORMATION Struct
    OffsetNext                                              DD
    UsbdDeviceHandle                                        DD
    DeviceDescriptor                                        USB_DEVICE_DESCRIPTOR
EndS

USBD_PIPE_INFORMATION Struct
    MaximumPacketSize                                       DW
    EndpointAddress                                         DB
    Interval                                                DB
    PipeType                                                DD
    PipeHandle                                              DD
    MaximumTransferSize                                     DD
    PipeFlags                                               DD
EndS

USBD_PF_CHANGE_MAX_PACKET                                   Equ         00000001H

USBD_PF_SHORT_PACKET_OPT                                    Equ         00000002H

USBD_PF_ENABLE_RT_THREAD_ACCESS                             Equ         00000004H

USBD_PF_MAP_ADD_TRANSFERS                                   Equ         00000008H

USBD_PF_VALID_MASK                                          Equ         (USBD_PF_CHANGE_MAX_PACKET | USBD_PF_SHORT_PACKET_OPT | USBD_PF_ENABLE_RT_THREAD_ACCESS | USBD_PF_MAP_ADD_TRANSFERS)

USBD_INTERFACE_INFORMATION Struct
    _Length                                                 DW
    InterfaceNumber                                         DB
    AlternateSetting                                        DB
    Class                                                   DB
    SubClass                                                DB
    Protocol                                                DB
    Reserved                                                DB
    InterfaceHandle                                         USBD_INTERFACE_HANDLE
    NumberOfPipes                                           DD
    Pipes                                                   USBD_PIPE_INFORMATION   1 Dup ?
EndS

URB_HCD_AREA Struct
    Reserved8                                               DD          8 Dup ?
EndS

URB_HEADER Struct
    Length                                                  DW
    Function                                                DW
    Status                                                  DD
    UsbdDeviceHandle                                        DD
    UsbdFlags                                               DD
EndS

URB_SELECT_INTERFACE Struct
    Hdr                                                     URB_HEADER
    ConfigurationHandle                                     USBD_CONFIGURATION_HANDLE
    Interface                                               USBD_INTERFACE_INFORMATION
EndS

URB_SELECT_CONFIGURATION Struct
    Hdr                                                     URB_HEADER
    ConfigurationDescriptor                                 PUSB_CONFIGURATION_DESCRIPTOR
    ConfigurationHandle                                     USBD_CONFIGURATION_HANDLE
    Interface                                               USBD_INTERFACE_INFORMATION
EndS

URB_PIPE_REQUEST Struct
    Hdr                                                     URB_HEADER
    PipeHandle                                              USBD_PIPE_HANDLE
    Reserved                                                DD
EndS

URB_FRAME_LENGTH_CONTROL Struct
    Hdr                                                     URB_HEADER
EndS

URB_GET_FRAME_LENGTH Struct
    Hdr                                                     URB_HEADER
    FrameLength                                             DD
    FrameNumber                                             DD
EndS

URB_SET_FRAME_LENGTH Struct
    Hdr                                                     URB_HEADER
    FrameLengthDelta                                        DD
EndS

URB_GET_CURRENT_FRAME_NUMBER Struct
    Hdr                                                     URB_HEADER
    FrameNumber                                             DD
EndS

URB_CONTROL_DESCRIPTOR_REQUEST Struct
    Hdr                                                     URB_HEADER
    Reserved                                                DD
    Reserved0                                               DD
    TransferBufferLength                                    DD
    TransferBuffer                                          DD
    TransferBufferMDL                                       DD
    UrbLink                                                 DD
    hca                                                     URB_HCD_AREA
    Reserved1                                               DW
    Index                                                   DB
    DescriptorType                                          DB
    LanguageId                                              DW
    Reserved2                                               DW
EndS

URB_CONTROL_GET_STATUS_REQUEST Struct
    Hdr                                                     URB_HEADER
    Reserved                                                DD
    Reserved0                                               DD
    TransferBufferLength                                    DD
    TransferBuffer                                          DD
    TransferBufferMDL                                       DD
    UrbLink                                                 DD
    hca                                                     URB_HCD_AREA
    Reserved1                                               DB          4 Dup ?
    Index                                                   DW
    Reserved2                                               DW
EndS

URB_CONTROL_FEATURE_REQUEST Struct
    Hdr                                                     URB_HEADER
    Reserved                                                DD
    Reserved2                                               DD
    Reserved3                                               DD
    Reserved4                                               DD
    Reserved5                                               DD
    UrbLink                                                 DD
    hca                                                     URB_HCD_AREA
    Reserved0                                               DW
    FeatureSelector                                         DW
    Index                                                   DW
    Reserved1                                               DW
EndS

URB_CONTROL_VENDOR_OR_CLASS_REQUEST Struct
    Hdr                                                     URB_HEADER
    Reserved                                                DD
    TransferFlags                                           DD
    TransferBufferLength                                    DD
    TransferBuffer                                          DD
    TransferBufferMDL                                       DD
    UrbLink                                                 DD
    hca                                                     URB_HCD_AREA
    RequestTypeReservedBits                                 DB
    Request                                                 DB
    Value                                                   DW
    Index                                                   DW
    Reserved1                                               DW
EndS

URB_CONTROL_GET_INTERFACE_REQUEST Struct
    Hdr                                                     URB_HEADER
    Reserved                                                DD
    Reserved0                                               DD
    TransferBufferLength                                    DD
    TransferBuffer                                          DD
    TransferBufferMDL                                       DD
    UrbLink                                                 DD
    hca                                                     URB_HCD_AREA
    Reserved1                                               DB          4 Dup ?
    Interface                                               DW
    Reserved2                                               DW
EndS

URB_CONTROL_GET_CONFIGURATION_REQUEST Struct
    Hdr                                                     URB_HEADER
    Reserved                                                DD
    Reserved0                                               DD
    TransferBufferLength                                    DD
    TransferBuffer                                          DD
    TransferBufferMDL                                       DD
    UrbLink                                                 DD
    hca                                                     URB_HCD_AREA
    Reserved1                                               DB          8 Dup ?
EndS

OS_STRING_DESCRIPTOR_INDEX                                  Equ         0EEH

MS_GENRE_DESCRIPTOR_INDEX                                   Equ         0001H
MS_POWER_DESCRIPTOR_INDEX                                   Equ         0002H

#Define                                                     MS_OS_STRING_SIGNATURE L"MSFT100"

MS_OS_FLAGS_CONTAINERID                                     Equ         02H

OS_STRING Struct
    bLength                                                 DB
    bDescriptorType                                         DB
    MicrosoftString                                         DW          7 Dup ?
    bVendorCode                                             DB
    Union
        bPad                                                DB
        bFlags                                              DB
    EndUnion
EndS

URB_OS_FEATURE_DESCRIPTOR_REQUEST Struct
    Hdr                                                     URB_HEADER
    Reserved                                                DD
    Reserved0                                               DD
    TransferBufferLength                                    DD
    TransferBuffer                                          DD
    TransferBufferMDL                                       DD
    UrbLink                                                 DD
    hca                                                     URB_HCD_AREA
    fbits                                                   DB  ;Members Recipient to Reserved1 are included here
    Reserved2                                               DB
    InterfaceNumber                                         DB
    MS_PageIndex                                            DB
    MS_FeatureDescriptorIndex                               DW
    Reserved3                                               DW
EndS

URB_CONTROL_TRANSFER Struct
    Hdr                                                     URB_HEADER
    PipeHandle                                              USBD_PIPE_HANDLE
    TransferFlags                                           DD
    TransferBufferLength                                    DD
    TransferBuffer                                          DD
    TransferBufferMDL                                       DD
    UrbLink                                                 DD
    hca                                                     URB_HCD_AREA
    SetupPacket                                             DB          8 Dup ?
EndS

URB_CONTROL_TRANSFER_EX Struct
    Hdr                                                     URB_HEADER
    PipeHandle                                              USBD_PIPE_HANDLE    ?
    TransferFlags                                           DD
    TransferBufferLength                                    DD
    TransferBuffer                                          DD
    TransferBufferMDL                                       DD
    Timeout                                                 DD
    #IFDEF WIN64
        Pad                                                 DD
    #ENDIF
    hca                                                     URB_HCD_AREA
    SetupPacket                                             DB          8 Dup ?
EndS

URB_BULK_OR_INTERRUPT_TRANSFER Struct
    Hdr                                                     URB_HEADER
    PipeHandle                                              USBD_PIPE_HANDLE
    TransferFlags                                           DD
    TransferBufferLength                                    DD
    TransferBuffer                                          DD
    TransferBufferMDL                                       DD
    UrbLink                                                 DD
    hca                                                     URB_HCD_AREA
EndS

USBD_ISO_PACKET_DESCRIPTOR Struct
    _Offset                                                 DD  ;Offset
    Length                                                  DD
    Status                                                  DD
EndS

URB_ISOCH_TRANSFER Struct
    Hdr                                                     URB_HEADER
    PipeHandle                                              USBD_PIPE_HANDLE
    TransferFlags                                           DD
    TransferBufferLength                                    DD
    TransferBuffer                                          DD
    TransferBufferMDL                                       DD
    UrbLink                                                 DD
    hca                                                     URB_HCD_AREA
    StartFrame                                              DD
    NumberOfPackets                                         DD
    ErrorCount                                              DD
    IsoPacket                                               USBD_ISO_PACKET_DESCRIPTOR  1 Dup ?
EndS

URB Struct
    Union
        UrbHeader                                           URB_HEADER
        UrbSelectInterface                                  URB_SELECT_INTERFACE
        UrbSelectConfiguration                              URB_SELECT_CONFIGURATION
        UrbPipeRequest                                      URB_PIPE_REQUEST
        UrbFrameLengthControl                               URB_FRAME_LENGTH_CONTROL
        UrbGetFrameLength                                   URB_GET_FRAME_LENGTH
        UrbSetFrameLength                                   URB_SET_FRAME_LENGTH
        UrbGetCurrentFrameNumber                            URB_GET_CURRENT_FRAME_NUMBER
        UrbControlTransfer                                  URB_CONTROL_TRANSFER
        UrbControlTransferEx                                URB_CONTROL_TRANSFER_EX
        UrbBulkOrInterruptTransfer                          URB_BULK_OR_INTERRUPT_TRANSFER
        UrbIsochronousTransfer                              URB_ISOCH_TRANSFER
        UrbControlDescriptorRequest                         URB_CONTROL_DESCRIPTOR_REQUEST
        UrbControlGetStatusRequest                          URB_CONTROL_GET_STATUS_REQUEST
        UrbControlFeatureRequest                            URB_CONTROL_FEATURE_REQUEST
        UrbControlVendorClassRequest                        URB_CONTROL_VENDOR_OR_CLASS_REQUEST
        UrbControlGetInterfaceRequest                       URB_CONTROL_GET_INTERFACE_REQUEST
        UrbControlGetConfigurationRequest                   URB_CONTROL_GET_CONFIGURATION_REQUEST
        UrbOSFeatureDescriptorRequest                       URB_OS_FEATURE_DESCRIPTOR_REQUEST
    EndUnion
EndS

#ENDIF ;USB_H
