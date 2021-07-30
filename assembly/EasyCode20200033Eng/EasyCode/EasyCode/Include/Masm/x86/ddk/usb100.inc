;===================================================================;
;                                                                   ;
;   usb100.inc for Easy Code 2.0 JWasm/Masm/PoAsm 32-bit drivers    ;
;                        (version 1.0.0)                            ;
;                                                                   ;
;                 Driver Development Kit (32-bit)                   ;
;                                                                   ;
;                  Copyright © Ramon Sala - 2015                    ;
;                                                                   ;
;===================================================================;

IFNDEF USB100_INC
USB100_INC Equ 1

BMREQUEST_HOST_TO_DEVICE                                    Equ         0
BMREQUEST_DEVICE_TO_HOST                                    Equ         1

BMREQUEST_STANDARD                                          Equ         0
BMREQUEST_CLASS                                             Equ         1
BMREQUEST_VENDOR                                            Equ         2

BMREQUEST_TO_DEVICE                                         Equ         0
BMREQUEST_TO_INTERFACE                                      Equ         1
BMREQUEST_TO_ENDPOINT                                       Equ         2
BMREQUEST_TO_OTHER                                          Equ         3


MAXIMUM_USB_STRING_LENGTH                                   Equ         255

USB_GETSTATUS_SELF_POWERED                                  Equ         01H
USB_GETSTATUS_REMOTE_WAKEUP_ENABLED                         Equ         02H


USB_DEVICE_DESCRIPTOR_TYPE                                  Equ         01H
USB_CONFIGURATION_DESCRIPTOR_TYPE                           Equ         02H
USB_STRING_DESCRIPTOR_TYPE                                  Equ         03H
USB_INTERFACE_DESCRIPTOR_TYPE                               Equ         04H
USB_ENDPOINT_DESCRIPTOR_TYPE                                Equ         05H

USB_RESERVED_DESCRIPTOR_TYPE                                Equ         06H
USB_CONFIG_POWER_DESCRIPTOR_TYPE                            Equ         07H
USB_INTERFACE_POWER_DESCRIPTOR_TYPE                         Equ         08H

USB_ENDPOINT_TYPE_MASK                                      Equ         03H

USB_ENDPOINT_TYPE_CONTROL                                   Equ         00H
USB_ENDPOINT_TYPE_ISOCHRONOUS                               Equ         01H
USB_ENDPOINT_TYPE_BULK                                      Equ         02H
USB_ENDPOINT_TYPE_INTERRUPT                                 Equ         03H

USB_CONFIG_POWERED_MASK                                     Equ         0C0H

USB_CONFIG_BUS_POWERED                                      Equ         080H
USB_CONFIG_SELF_POWERED                                     Equ         040H
USB_CONFIG_REMOTE_WAKEUP                                    Equ         020H

USB_ENDPOINT_DIRECTION_MASK                                 Equ         080H

USB_REQUEST_GET_STATUS                                      Equ         00H
USB_REQUEST_CLEAR_FEATURE                                   Equ         01H

USB_REQUEST_SET_FEATURE                                     Equ         03H

USB_REQUEST_SET_ADDRESS                                     Equ         05H
USB_REQUEST_GET_DESCRIPTOR                                  Equ         06H
USB_REQUEST_SET_DESCRIPTOR                                  Equ         07H
USB_REQUEST_GET_CONFIGURATION                               Equ         08H
USB_REQUEST_SET_CONFIGURATION                               Equ         09H
USB_REQUEST_GET_INTERFACE                                   Equ         0AH
USB_REQUEST_SET_INTERFACE                                   Equ         0BH
USB_REQUEST_SYNC_FRAME                                      Equ         0CH

USB_DEVICE_CLASS_RESERVED                                   Equ         000H
USB_DEVICE_CLASS_AUDIO                                      Equ         001H
USB_DEVICE_CLASS_COMMUNICATIONS                             Equ         002H
USB_DEVICE_CLASS_HUMAN_INTERFACE                            Equ         003H
USB_DEVICE_CLASS_MONITOR                                    Equ         004H
USB_DEVICE_CLASS_PHYSICAL_INTERFACE                         Equ         005H
USB_DEVICE_CLASS_POWER                                      Equ         006H
USB_DEVICE_CLASS_PRINTER                                    Equ         007H
USB_DEVICE_CLASS_STORAGE                                    Equ         008H
USB_DEVICE_CLASS_HUB                                        Equ         009H
USB_DEVICE_CLASS_VENDOR_SPECIFIC                            Equ         0FFH

USB_FEATURE_ENDPOINT_STALL                                  Equ         0000H
USB_FEATURE_REMOTE_WAKEUP                                   Equ         0001H

USB_FEATURE_INTERFACE_POWER_D0                              Equ         0002H
USB_FEATURE_INTERFACE_POWER_D1                              Equ         0003H
USB_FEATURE_INTERFACE_POWER_D2                              Equ         0004H
USB_FEATURE_INTERFACE_POWER_D3                              Equ         0005H

USB_DEVICE_DESCRIPTOR Struct
    bLength                                                 DB          ?
    bDescriptorType                                         DB          ?
    bcdUSB                                                  DW          ?
    bDeviceClass                                            DB          ?
    bDeviceSubClass                                         DB          ?
    bDeviceProtocol                                         DB          ?
    bMaxPacketSize0                                         DB          ?
    idVendor                                                DW          ?
    idProduct                                               DW          ?
    bcdDevice                                               DW          ?
    iManufacturer                                           DB          ?
    iProduct                                                DB          ?
    iSerialNumber                                           DB          ?
    bNumConfigurations                                      DB          ?
USB_DEVICE_DESCRIPTOR EndS
PUSB_DEVICE_DESCRIPTOR                                      TypeDef     DWord

USB_ENDPOINT_DESCRIPTOR Struct
    bLength                                                 DB          ?
    bDescriptorType                                         DB          ?
    bEndpointAddress                                        DB          ?
    bmAttributes                                            DB          ?
    wMaxPacketSize                                          DW          ?
    bInterval                                               DB          ?
USB_ENDPOINT_DESCRIPTOR EndS
PUSB_ENDPOINT_DESCRIPTOR                                    TypeDef     DWord

USB_CONFIGURATION_DESCRIPTOR Struct
    bLength                                                 DB          ?
    bDescriptorType                                         DB          ?
    wTotalLength                                            DW          ?
    bNumInterfaces                                          DB          ?
    bConfigurationValue                                     DB          ?
    iConfiguration                                          DB          ?
    bmAttributes                                            DB          ?
    MaxPower                                                DB          ?
USB_CONFIGURATION_DESCRIPTOR EndS
PUSB_CONFIGURATION_DESCRIPTOR                               TypeDef     DWord

USB_INTERFACE_DESCRIPTOR Struct
    bLength                                                 DB          ?
    bDescriptorType                                         DB          ?
    bInterfaceNumber                                        DB          ?
    bAlternateSetting                                       DB          ?
    bNumEndpoints                                           DB          ?
    bInterfaceClass                                         DB          ?
    bInterfaceSubClass                                      DB          ?
    bInterfaceProtocol                                      DB          ?
    iInterface                                              DB          ?
USB_INTERFACE_DESCRIPTOR EndS
PUSB_INTERFACE_DESCRIPTOR                                   TypeDef     DWord

USB_STRING_DESCRIPTOR Struct
    bLength                                                 DB          ?
    bDescriptorType                                         DB          ?
    bString                                                 DW          1 Dup(?)
USB_STRING_DESCRIPTOR EndS
PUSB_STRING_DESCRIPTOR                                      TypeDef     DWord

USB_COMMON_DESCRIPTOR Struct
    bLength                                                 DB          ?
    bDescriptorType                                         DB          ?
USB_COMMON_DESCRIPTOR EndS
PUSB_COMMON_DESCRIPTOR                                      TypeDef     DWord

USB_HUB_DESCRIPTOR Struct
    bDescriptorLength                                       DB          ?
    bDescriptorType                                         DB          ?
    bNumberOfPorts                                          DB          ?
    wHubCharacteristics                                     DW          ?
    bPowerOnToPowerGood                                     DB          ?
    bHubControlCurrent                                      DB          ?
    bRemoveAndPowerMask                                     DB          64 Dup(?)
USB_HUB_DESCRIPTOR EndS
PUSB_HUB_DESCRIPTOR                                         TypeDef     DWord

USB_SUPPORT_D0_COMMAND                                      Equ         01H
USB_SUPPORT_D1_COMMAND                                      Equ         02H
USB_SUPPORT_D2_COMMAND                                      Equ         04H
USB_SUPPORT_D3_COMMAND                                      Equ         08H

USB_SUPPORT_D1_WAKEUP                                       Equ         10H
USB_SUPPORT_D2_WAKEUP                                       Equ         20H

USB_CONFIGURATION_POWER_DESCRIPTOR Struct
    bLength                                                 DB          ?
    bDescriptorType                                         DB          ?
    SelfPowerConsumedD0                                     DB          3 Dup(?)
    bPowerSummaryId                                         DB          ?
    bBusPowerSavingD1                                       DB          ?
    bSelfPowerSavingD1                                      DB          ?
    bBusPowerSavingD2                                       DB          ?
    bSelfPowerSavingD2                                      DB          ?
    bBusPowerSavingD3                                       DB          ?
    bSelfPowerSavingD3                                      DB          ?
    TransitionTimeFromD1                                    DW          ?
    TransitionTimeFromD2                                    DW          ?
    TransitionTimeFromD3                                    DW          ?
USB_CONFIGURATION_POWER_DESCRIPTOR EndS
PUSB_CONFIGURATION_POWER_DESCRIPTOR                         TypeDef     DWord

USB_INTERFACE_POWER_DESCRIPTOR Struct
    bLength                                                 DB          ?
    bDescriptorType                                         DB          ?
    bmCapabilitiesFlags                                     DB          ?
    bBusPowerSavingD1                                       DB          ?
    bSelfPowerSavingD1                                      DB          ?
    bBusPowerSavingD2                                       DB          ?
    bSelfPowerSavingD2                                      DB          ?
    bBusPowerSavingD3                                       DB          ?
    bSelfPowerSavingD3                                      DB          ?
    TransitionTimeFromD1                                    DW          ?
    TransitionTimeFromD2                                    DW          ?
    TransitionTimeFromD3                                    DW          ?
USB_INTERFACE_POWER_DESCRIPTOR EndS
PUSB_INTERFACE_POWER_DESCRIPTOR                             TypeDef     DWord

ENDIF ;USB100_INC
