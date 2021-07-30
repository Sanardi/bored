;===========================================================;
;                                                           ;
;     ntddmou.h for Easy Code 2.0 GoAsm 32-bit drivers      ;
;                     (version 1.0.0)                       ;
;                                                           ;
;             Driver Development Kit (32-bit)               ;
;                                                           ;
;              Copyright © Ramon Sala - 2015                ;
;                                                           ;
;===========================================================;

#IFNDEF NTDDMOU_H
#Define NTDDMOU_H 1

#IFNDEF MACRODRV_H
    #Include macrodrv.h
#ENDIF

#Define                                                     DD_MOUSE_DEVICE_NAME    "\Device\PointerClass"
#Define                                                     DD_MOUSE_DEVICE_NAME_U  L"\Device\PointerClass"

IOCTL_MOUSE_QUERY_ATTRIBUTES                                Equ         CTL_CODE(FILE_DEVICE_MOUSE, 0, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_MOUSE_INSERT_DATA                                     Equ         CTL_CODE(FILE_DEVICE_MOUSE, 1, METHOD_BUFFERED, FILE_ANY_ACCESS)

DEFINE_GUID     (GUID_DEVINTERFACE_MOUSE,                   378DE44CH, 56EFH, 11D1H, 0BCH, 8CH, 00H, 0A0H, 0C9H, 14H, 05H, 0DDH)

GUID_CLASS_MOUSE                                            Equ         GUID_DEVINTERFACE_MOUSE

MOUSE_INPUT_DATA Struct
    UnitId                                                  DW
    Flags                                                   DW
    Union
        Buttons                                             DD
        Struct
            ButtonFlags                                     DW
            ButtonData                                      DW
        EndS
    EndUnion
    RawButtons                                              DD
    LastX                                                   DD
    LastY                                                   DD
    ExtraInformation                                        DD
EndS

MOUSE_LEFT_BUTTON_DOWN                                      Equ         0001H
MOUSE_LEFT_BUTTON_UP                                        Equ         0002H
MOUSE_RIGHT_BUTTON_DOWN                                     Equ         0004H
MOUSE_RIGHT_BUTTON_UP                                       Equ         0008H
MOUSE_MIDDLE_BUTTON_DOWN                                    Equ         0010H
MOUSE_MIDDLE_BUTTON_UP                                      Equ         0020H

MOUSE_BUTTON_1_DOWN                                         Equ         MOUSE_LEFT_BUTTON_DOWN
MOUSE_BUTTON_1_UP                                           Equ         MOUSE_LEFT_BUTTON_UP
MOUSE_BUTTON_2_DOWN                                         Equ         MOUSE_RIGHT_BUTTON_DOWN
MOUSE_BUTTON_2_UP                                           Equ         MOUSE_RIGHT_BUTTON_UP
MOUSE_BUTTON_3_DOWN                                         Equ         MOUSE_MIDDLE_BUTTON_DOWN
MOUSE_BUTTON_3_UP                                           Equ         MOUSE_MIDDLE_BUTTON_UP

MOUSE_BUTTON_4_DOWN                                         Equ         0040H
MOUSE_BUTTON_4_UP                                           Equ         0080H
MOUSE_BUTTON_5_DOWN                                         Equ         0100H
MOUSE_BUTTON_5_UP                                           Equ         0200H

MOUSE_WHEEL                                                 Equ         0400H
MOUSE_HWHEEL                                                Equ         0800H

MOUSE_MOVE_RELATIVE                                         Equ         0
MOUSE_MOVE_ABSOLUTE                                         Equ         1
MOUSE_VIRTUAL_DESKTOP                                       Equ         02H
MOUSE_ATTRIBUTES_CHANGED                                    Equ         04H
MOUSE_MOVE_NOCOALESCE                                       Equ         08H

MOUSE_TERMSRV_SRC_SHADOW                                    Equ         0100H

MOUSE_ATTRIBUTES Struct
    MouseIdentifier                                         DW
    NumberOfButtons                                         DW
    SampleRate                                              DW
    InputDataQueueLength                                    DD
EndS

MOUSE_INPORT_HARDWARE                                       Equ         0001H
MOUSE_I8042_HARDWARE                                        Equ         0002H
MOUSE_SERIAL_HARDWARE                                       Equ         0004H
BALLPOINT_I8042_HARDWARE                                    Equ         0008H
BALLPOINT_SERIAL_HARDWARE                                   Equ         0010H
WHEELMOUSE_I8042_HARDWARE                                   Equ         0020H
WHEELMOUSE_SERIAL_HARDWARE                                  Equ         0040H
MOUSE_HID_HARDWARE                                          Equ         0080H
WHEELMOUSE_HID_HARDWARE                                     Equ         0100H
HORIZONTAL_WHEEL_PRESENT                                    Equ         8000H

MOUSE_UNIT_ID_PARAMETER Struct
    UnitId                                                  DW
EndS

MOUSE_ERROR_VALUE_BASE                                      Equ         20000

#ENDIF ;NTDDMOU_H
