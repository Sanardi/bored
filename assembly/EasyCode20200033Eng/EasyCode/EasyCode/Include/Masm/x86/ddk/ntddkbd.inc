;===================================================================;
;                                                                   ;
;   ntddkbd.inc for Easy Code 2.0 JWasm/Masm/PoAsm 32-bit drivers   ;
;                        (version 1.0.0)                            ;
;                                                                   ;
;                 Driver Development Kit (32-bit)                   ;
;                                                                   ;
;                  Copyright © Ramon Sala - 2015                    ;
;                                                                   ;
;===================================================================;

IFNDEF NTDDKBD_INC
NTDDKBD_INC Equ 1

IFNDEF MACRODRV_INC
    Include macrodrv.inc
ENDIF

IOCTL_KEYBOARD_QUERY_ATTRIBUTES             Equ     CTL_CODE(FILE_DEVICE_KEYBOARD, 00000H, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_KEYBOARD_SET_TYPEMATIC                Equ     CTL_CODE(FILE_DEVICE_KEYBOARD, 00001H, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_KEYBOARD_SET_INDICATORS               Equ     CTL_CODE(FILE_DEVICE_KEYBOARD, 00002H, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_KEYBOARD_QUERY_TYPEMATIC              Equ     CTL_CODE(FILE_DEVICE_KEYBOARD, 00008H, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_KEYBOARD_QUERY_INDICATORS             Equ     CTL_CODE(FILE_DEVICE_KEYBOARD, 00010H, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_KEYBOARD_QUERY_INDICATOR_TRANSLATION  Equ     CTL_CODE(FILE_DEVICE_KEYBOARD, 00020H, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_KEYBOARD_INSERT_DATA                  Equ     CTL_CODE(FILE_DEVICE_KEYBOARD, 00040H, METHOD_BUFFERED, FILE_ANY_ACCESS)

IOCTL_KEYBOARD_QUERY_IME_STATUS             Equ     CTL_CODE(FILE_DEVICE_KEYBOARD, 00400H, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_KEYBOARD_SET_IME_STATUS               Equ     CTL_CODE(FILE_DEVICE_KEYBOARD, 00401H, METHOD_BUFFERED, FILE_ANY_ACCESS)

KEYBOARD_INPUT_DATA Struct
    UnitId                                  DW      ?
    MakeCode                                DW      ?
    Flags                                   DW      ?
    Reserved                                DW      ?
    ExtraInformation                        DD      ?
KEYBOARD_INPUT_DATA EndS
PKEYBOARD_INPUT_DATA                        TypeDef DWord

KEYBOARD_OVERRUN_MAKE_CODE                  Equ     0FFH

KEY_MAKE                                    Equ     0
KEY_BREAK                                   Equ     1
KEY_E0                                      Equ     2
KEY_E1                                      Equ     4
KEY_TERMSRV_SET_LED                         Equ     8
KEY_TERMSRV_SHADOW                          Equ     010H
KEY_TERMSRV_VKPACKET                        Equ     020H

KEYBOARD_TYPEMATIC_PARAMETERS Struct
    UnitId                                  DW      ?
    Rate                                    DW      ?
    Delay                                   DW      ?
KEYBOARD_TYPEMATIC_PARAMETERS EndS
PKEYBOARD_TYPEMATIC_PARAMETERS              TypeDef DWord

KEYBOARD_ID Struct
    _Type                                   DB      ?     ;Type
    Subtype                                 DB      ?
KEYBOARD_ID EndS
PKEYBOARD_ID                                TypeDef DWord

KEYBOARD_ATTRIBUTES Struct
    KeyboardIdentifier                      KEYBOARD_ID <>
    KeyboardMode                            DW      ?
    NumberOfFunctionKeys                    DW      ?
    NumberOfIndicators                      DW      ?
    NumberOfKeysTotal                       DW      ?
    InputDataQueueLength                    DD      ?
    KeyRepeatMinimum                        KEYBOARD_TYPEMATIC_PARAMETERS   <>
    KeyRepeatMaximum                        KEYBOARD_TYPEMATIC_PARAMETERS   <>
KEYBOARD_ATTRIBUTES EndS
PKEYBOARD_ATTRIBUTES                        TypeDef DWord

KEYBOARD_INDICATOR_PARAMETERS Struct
    UnitId                                  DW      ?
    LedFlags                                DW      ?
KEYBOARD_INDICATOR_PARAMETERS EndS
PKEYBOARD_INDICATOR_PARAMETERS              TypeDef DWord

INDICATOR_LIST Struct
    MakeCode                                DW      ?
    IndicatorFlags                          DW      ?
INDICATOR_LIST Ends
PINDICATOR_LIST                             TypeDef DWord

KEYBOARD_INDICATOR_TRANSLATION Struct
    NumberOfIndicatorKeys                   DW      ?
    IndicatorList                           INDICATOR_LIST  1 Dup(<>)
KEYBOARD_INDICATOR_TRANSLATION Ends
PKEYBOARD_INDICATOR_TRANSLATION             TypeDef DWord

KEYBOARD_LED_INJECTED                       Equ     08000H
KEYBOARD_SHADOW                             Equ     04000H

KEYBOARD_KANA_LOCK_ON                       Equ     8
KEYBOARD_CAPS_LOCK_ON                       Equ     4
KEYBOARD_NUM_LOCK_ON                        Equ     2
KEYBOARD_SCROLL_LOCK_ON                     Equ     1

KEYBOARD_UNIT_ID_PARAMETER Struct
    UnitId                                  DW      ?
KEYBOARD_UNIT_ID_PARAMETER EndS
PKEYBOARD_UNIT_ID_PARAMETER                 TypeDef DWord

KEYBOARD_ERROR_VALUE_BASE                   Equ     10000

KEYBOARD_IME_STATUS Struct
    UnitId                                  DW      ?
    ImeOpen                                 DD      ?
    ImeConvMode                             DD      ?
KEYBOARD_IME_STATUS EndS
PKEYBOARD_IME_STATUS                        TypeDef DWord

ENDIF ;NTDDKBD_INC
