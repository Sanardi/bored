;===========================================================;
;                                                           ;
;      usb200.h for Easy Code 2.0 GoAsm 32-bit drivers      ;
;                     (version 1.0.0)                       ;
;                                                           ;
;             Driver Development Kit (32-bit)               ;
;                                                           ;
;              Copyright © Ramon Sala - 2015                ;
;                                                           ;
;===========================================================;

#IFNDEF USB200_H
#Define USB200_H 1

#Include usb100.h

;USB_DEVICE_SPEED Enumeration
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

BM_REQUEST_TYPE Union
    _BM Struct
        fbits                                               DB  ;Members Recipient to Dir ar included here
    EndS
    B                                                       DB
EndUnion

USB_DEFAULT_PIPE_SETUP_PACKET Struct
    bmRequestType                                           BM_REQUEST_TYPE
    bRequest                                                DB
    wValue Union
        Struct
            LowByte                                         DB
            HiByte                                          DB
        EndS
        W                                                   DW
    EndUnion
    wIndex Union
        Struct
            LowByte                                         DB
            HiByte                                          DB
        EndS
        W                                                   DW
    EndUnion
    wLength                                                 DW
EndS

USB_DEVICE_QUALIFIER_DESCRIPTOR_TYPE                        Equ         06H
USB_OTHER_SPEED_CONFIGURATION_DESCRIPTOR_TYPE               Equ         07H

USB_DEVICE_QUALIFIER_DESCRIPTOR Struct
    bLength                                                 DB
    bDescriptorType                                         DB
    bcdUSB                                                  DW
    bDeviceClass                                            DB
    bDeviceSubClass                                         DB
    bDeviceProtocol                                         DB
    bMaxPacketSize0                                         DB
    bNumConfigurations                                      DB
    bReserved                                               DB
EndS

USB_HIGH_SPEED_MAXPACKET Union
    _MP Struct
        fbits                                               DW  ;Members MaxPacket to Reserved are included here
    EndS
    us                                                      DW
EndUnion

USB_INTERFACE_ASSOCIATION_DESCRIPTOR_TYPE                   Equ         0BH

USB_INTERFACE_ASSOCIATION_DESCRIPTOR Struct
    bLength                                                 DB
    bDescriptorType                                         DB
    bFirstInterface                                         DB
    bInterfaceCount                                         DB
    bFunctionClass                                          DB
    bFunctionSubClass                                       DB
    bFunctionProtocol                                       DB
    iFunction                                               DB
EndS

#ENDIF ;USB200_H
