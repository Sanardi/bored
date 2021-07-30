;===================================================================;
;                                                                   ;
;   usb200.inc for Easy Code 2.0 JWasm/Masm/PoAsm 32-bit drivers    ;
;                        (version 1.0.0)                            ;
;                                                                   ;
;                 Driver Development Kit (32-bit)                   ;
;                                                                   ;
;                  Copyright © Ramon Sala - 2015                    ;
;                                                                   ;
;===================================================================;

IFNDEF USB200_INC
USB200_INC Equ 1

Include usb100.inc

;USB_DEVICE_SPEED Enumeration
USB_DEVICE_SPEED                                            TypeDef     DWord
UsbLowSpeed                                                 Equ         0
UsbFullSpeed                                                Equ         1
UsbHighSpeed                                                Equ         2

;USB_DEVICE_TYPE Enumeration
Usb11Device                                                 Equ         0
Usb20Device                                                 Equ         1

USB_PORT_STATUS_CONNECT                                     Equ         0001H
USB_PORT_STATUS_ENABLE                                      Equ         0002H
USB_PORT_STATUS_SUSPEND                                     Equ         0004H
USB_PORT_STATUS_OVER_CURRENT                                Equ         0008H
USB_PORT_STATUS_RESET                                       Equ         0010H
USB_PORT_STATUS_POWER                                       Equ         0100H
USB_PORT_STATUS_LOW_SPEED                                   Equ         0200H
USB_PORT_STATUS_HIGH_SPEED                                  Equ         0400H

BMRQSTREC Record                                            Recipient:2, Reserved:3, _Type:2, Dir:1
BM_REQUEST_TYPE Union
    Struct _BM
        bmrqstrec                                           BMRQSTREC   <>
    EndS
    B                                                       DB          ?
BM_REQUEST_TYPE EndS
PBM_REQUEST_TYPE                                            TypeDef     DWord

USB_DEFAULT_PIPE_SETUP_PACKET Struct
    bmRequestType                                           BM_REQUEST_TYPE <>
    bRequest                                                DB          ?
    Union wValue
        Struct
            LowByte                                         DB          ?
            _HiByte                                         DB          ?   ;HiByte
        EndS
        W                                                   DW          ?
    EndS
    Union wIndex
        Struct
            LowByte                                         DB          ?
            _HiByte                                         DB          ?   ;HiByte
        EndS
        W                                                   DW          ?
    EndS
    wLength                                                 DW          ?
USB_DEFAULT_PIPE_SETUP_PACKET EndS
PUSB_DEFAULT_PIPE_SETUP_PACKET                              TypeDef     DWord

USB_DEVICE_QUALIFIER_DESCRIPTOR_TYPE                        Equ         06H
USB_OTHER_SPEED_CONFIGURATION_DESCRIPTOR_TYPE               Equ         07H

USB_DEVICE_QUALIFIER_DESCRIPTOR Struct
    bLength                                                 DB          ?
    bDescriptorType                                         DB          ?
    bcdUSB                                                  DW          ?
    bDeviceClass                                            DB          ?
    bDeviceSubClass                                         DB          ?
    bDeviceProtocol                                         DB          ?
    bMaxPacketSize0                                         DB          ?
    bNumConfigurations                                      DB          ?
    bReserved                                               DB          ?
USB_DEVICE_QUALIFIER_DESCRIPTOR EndS
PUSB_DEVICE_QUALIFIER_DESCRIPTOR                            TypeDef     DWord

USBHSPDREC Record                                           MaxPacket:11, HSmux:2, _Reserved:3
USB_HIGH_SPEED_MAXPACKET Union
    Struct _MP
    usbhspdrec                                              USBHSPDREC  <>
    EndS
    us                                                      DW          ?
USB_HIGH_SPEED_MAXPACKET EndS
PUSB_HIGH_SPEED_MAXPACKET                                   TypeDef     DWord

USB_INTERFACE_ASSOCIATION_DESCRIPTOR_TYPE                   Equ         0BH

USB_INTERFACE_ASSOCIATION_DESCRIPTOR Struct
    bLength                                                 DB          ?
    bDescriptorType                                         DB          ?
    bFirstInterface                                         DB          ?
    bInterfaceCount                                         DB          ?
    bFunctionClass                                          DB          ?
    bFunctionSubClass                                       DB          ?
    bFunctionProtocol                                       DB          ?
    iFunction                                               DB          ?
USB_INTERFACE_ASSOCIATION_DESCRIPTOR EndS
PUSB_INTERFACE_ASSOCIATION_DESCRIPTOR                       TypeDef     DWord

ENDIF ;USB200_INC
