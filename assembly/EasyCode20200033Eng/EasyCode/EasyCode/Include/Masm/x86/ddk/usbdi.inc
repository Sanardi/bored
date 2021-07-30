;===================================================================;
;                                                                   ;
;    usbdi.inc for Easy Code 2.0 JWasm/Masm/PoAsm 32-bit drivers    ;
;                        (version 1.0.0)                            ;
;                                                                   ;
;                 Driver Development Kit (32-bit)                   ;
;                                                                   ;
;                  Copyright © Ramon Sala - 2015                    ;
;                                                                   ;
;===================================================================;

IFNDEF USBDI_INC
USBDI_INC Equ 1

Include usb.inc
Include usbioctl.inc

USBD_STATUS_CANCELLING                                      Equ         (000020000H)
USBD_STATUS_CANCELING                                       Equ         (000020000H)
USBD_STATUS_NO_MEMORY                                       Equ         (080000100H)
USBD_STATUS_ERROR                                           Equ         (080000000H)
USBD_STATUS_REQUEST_FAILED                                  Equ         (080000500H)
USBD_STATUS_HALTED                                          Equ         (0C0000000H)

URB_FUNCTION_RESERVED0                                      Equ         0016H
URB_FUNCTION_RESERVED                                       Equ         001DH
URB_FUNCTION_LAST                                           Equ         0029H

USBD_PF_DOUBLE_BUFFER                                       Equ         00000002H

USBD_TRANSFER_DIRECTION_BIT                                 Equ         0
USBD_SHORT_TRANSFER_OK_BIT                                  Equ         1
USBD_START_ISO_TRANSFER_ASAP_BIT                            Equ         2

ENDIF ;USBDI_INC
