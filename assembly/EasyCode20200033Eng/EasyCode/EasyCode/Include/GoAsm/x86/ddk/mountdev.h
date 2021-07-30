;===========================================================;
;                                                           ;
;     mountdev.h for Easy Code 2.0 GoAsm 32-bit drivers     ;
;                     (version 1.0.0)                       ;
;                                                           ;
;             Driver Development Kit (32-bit)               ;
;                                                           ;
;              Copyright © Ramon Sala - 2015                ;
;                                                           ;
;===========================================================;

#IFNDEF MOUNTDEV_H
#Define MOUNTDEV_H 1

#Include mountmgr.h

IOCTL_MOUNTDEV_QUERY_UNIQUE_ID              Equ     CTL_CODE(MOUNTDEVCONTROLTYPE, 0, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_MOUNTDEV_UNIQUE_ID_CHANGE_NOTIFY      Equ     CTL_CODE(MOUNTDEVCONTROLTYPE, 1, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_MOUNTDEV_QUERY_SUGGESTED_LINK_NAME    Equ     CTL_CODE(MOUNTDEVCONTROLTYPE, 3, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_MOUNTDEV_LINK_CREATED                 Equ     CTL_CODE(MOUNTDEVCONTROLTYPE, 4, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_MOUNTDEV_LINK_DELETED                 Equ     CTL_CODE(MOUNTDEVCONTROLTYPE, 5, METHOD_BUFFERED, FILE_ANY_ACCESS)

MOUNTDEV_UNIQUE_ID Struct
    UniqueIdLength                          DW
    UniqueId                                DB      1 Dup ?
EndS

MOUNTDEV_SUGGESTED_LINK_NAME Struct
    UseOnlyIfThereAreNoOtherLinks           DB
    NameLength                              DW
    Name                                    DW      2 Dup ?
EndS

IOCTL_MOUNTDEV_QUERY_STABLE_GUID            Equ     CTL_CODE(MOUNTDEVCONTROLTYPE, 6, METHOD_BUFFERED, FILE_ANY_ACCESS)

MOUNTDEV_STABLE_GUID Struct
    StableGuid                              GUID
EndS

#ENDIF ;MOUNTDEV_H
