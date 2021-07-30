;===========================================================;
;                                                           ;
;     macrodrv.h for Easy Code 2.0 GoAsm 32-bit drivers     ;
;                     (version 1.0.0)                       ;
;                                                           ;
;             Driver Development Kit (32-bit)               ;
;                                                           ;
;              Copyright © Ramon Sala - 2015                ;
;                                                           ;
;===========================================================;

#IFNDEF MACRODRV_H
#Define MACRODRV_H 1

CTL_CODE(%DeviceType, %Function, %Method, %Access ) Macro
    ((%DeviceType << 16) | (%Access << 14) | (%Function << 2) | (%Method))
EndM

DEVICE_TYPE_FROM_CTL_CODE(%ctrlCode) Macro
    ((%ctrlCode & 0xFFFF0000) >> 16)
EndM

METHOD_FROM_CTL_CODE(%ctrlCode) Macro
    (%ctrlCode & 3)
EndM

DEFINE_GUID (%name, %l, %w1, %w2, %b1, %b2, %b3, %b4, %b5, %b6, %b7, %b8) Macro
    .Const
        ALIGN 4
        %name                               DD          %l
                                            DW          %w1
                                            DW          %w2
                                            DB          %b1
                                            DB          %b2
                                            DB          %b3
                                            DB          %b4
                                            DB          %b5
                                            DB          %b6
                                            DB          %b7
                                            DB          %b8
EndM

MAKEFOURCC(%1,%2,%3,%4,%5) Macro
    %1 equ  %2|(%3 << 8)|(%4 << 16)|(%5 << 24)
EndM

MANDATORY_LEVEL_TO_MANDATORY_RID(%IL) Macro
    (%IL << 12)
EndM

USBD_TRANSFER_DIRECTION_FLAG(%flags) Macro
    (%flags & USBD_TRANSFER_DIRECTION)
EndM

USBD_SUCCESS(%Status) Macro
    (%Status >= 0)
EndM

USBD_PENDING(%Status) Macro
    ((%Status >> 30) == 1)
EndM

USBD_ERROR(%Status) Macro
    (%Status < 0)
EndM

USB_ENDPOINT_DIRECTION_OUT(%addr) Macro
    (!(%addr & USB_ENDPOINT_DIRECTION_MASK))
EndM

USB_ENDPOINT_DIRECTION_IN(%addr) Macro
    (%addr & USB_ENDPOINT_DIRECTION_MASK)
EndM

USBD_HALTED(%Status) Macro
    ((%Status >> 30) == 3)
EndM

USB_CTL(%id) Macro
    CTL_CODE(FILE_DEVICE_USB, (%id), METHOD_BUFFERED, FILE_ANY_ACCESS)
EndM

USB_KERNEL_CTL(%id) Macro
    CTL_CODE(FILE_DEVICE_USB, (%id), METHOD_NEITHER, FILE_ANY_ACCESS)
EndM

USB_KERNEL_CTL_BUFFERED(%id) Macro
    CTL_CODE(FILE_DEVICE_USB, (%id), METHOD_BUFFERED, FILE_ANY_ACCESS)
EndM

#IFNDEF TEXT
    #IF STRINGS UNICODE
        #Define TEXT(x) L##x
    #ELSE
        #Define TEXT(x) x
    #ENDIF
#ENDIF

#ENDIF ;MACRODRV_H
