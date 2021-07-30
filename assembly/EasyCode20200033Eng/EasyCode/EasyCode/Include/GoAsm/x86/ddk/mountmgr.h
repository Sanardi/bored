;===========================================================;
;                                                           ;
;     mountmgr.h for Easy Code 2.0 GoAsm 32-bit drivers     ;
;                     (version 1.0.0)                       ;
;                                                           ;
;             Driver Development Kit (32-bit)               ;
;                                                           ;
;              Copyright © Ramon Sala - 2015                ;
;                                                           ;
;===========================================================;

#IFNDEF MOUNTMGR_H
#Define MOUNTMGR_H 1

MOUNTMGRCONTROLTYPE                         Equ     00000006DH
MOUNTDEVCONTROLTYPE                         Equ     00000004DH

#IFNDEF MACRODRV_H
    #Include macrodrv.h
#ENDIF

#IFNDEF WTYPES_H
    #Include wtypes.h
#ENDIF

#IFNDEF GUID
    #Define                                 GUID_DEFINED 1
    GUID Struct
        Data1                               DD
        Data2                               DW
        Data3                               DW
        Data4                               DB          8 Dup ?
    EndS
    #Define                                 CLSID GUID
    #Define                                 IID   GUID
    #Define                                 FMTID GUID
#ENDIF

IOCTL_MOUNTMGR_CREATE_POINT                 Equ     CTL_CODE(MOUNTMGRCONTROLTYPE, 0, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
IOCTL_MOUNTMGR_DELETE_POINTS                Equ     CTL_CODE(MOUNTMGRCONTROLTYPE, 1, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
IOCTL_MOUNTMGR_QUERY_POINTS                 Equ     CTL_CODE(MOUNTMGRCONTROLTYPE, 2, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_MOUNTMGR_DELETE_POINTS_DBONLY         Equ     CTL_CODE(MOUNTMGRCONTROLTYPE, 3, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
IOCTL_MOUNTMGR_NEXT_DRIVE_LETTER            Equ     CTL_CODE(MOUNTMGRCONTROLTYPE, 4, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
IOCTL_MOUNTMGR_AUTO_DL_ASSIGNMENTS          Equ     CTL_CODE(MOUNTMGRCONTROLTYPE, 5, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
IOCTL_MOUNTMGR_VOLUME_MOUNT_POINT_CREATED   Equ     CTL_CODE(MOUNTMGRCONTROLTYPE, 6, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
IOCTL_MOUNTMGR_VOLUME_MOUNT_POINT_DELETED   Equ     CTL_CODE(MOUNTMGRCONTROLTYPE, 7, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
IOCTL_MOUNTMGR_CHANGE_NOTIFY                Equ     CTL_CODE(MOUNTMGRCONTROLTYPE, 8, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_MOUNTMGR_KEEP_LINKS_WHEN_OFFLINE      Equ     CTL_CODE(MOUNTMGRCONTROLTYPE, 9, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
IOCTL_MOUNTMGR_CHECK_UNPROCESSED_VOLUMES    Equ     CTL_CODE(MOUNTMGRCONTROLTYPE, 10, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_MOUNTMGR_VOLUME_ARRIVAL_NOTIFICATION  Equ     CTL_CODE(MOUNTMGRCONTROLTYPE, 11, METHOD_BUFFERED, FILE_READ_ACCESS)

MOUNTMGR_CREATE_POINT_INPUT Struct
    SymbolicLinkNameOffset                  DW
    SymbolicLinkNameLength                  DW
    DeviceNameOffset                        DW
    DeviceNameLength                        DW
EndS

MOUNTMGR_MOUNT_POINT Struct
    SymbolicLinkNameOffset                  DD
    SymbolicLinkNameLength                  DW
    UniqueIdOffset                          DD
    UniqueIdLength                          DW
    DeviceNameOffset                        DD
    DeviceNameLength                        DW
EndS

MOUNTMGR_MOUNT_POINTS Struct
    _Size                                   DD
    NumberOfMountPoints                     DD
    MountPoints                             MOUNTMGR_MOUNT_POINT 1 Dup ?
EndS

MOUNTMGR_DRIVE_LETTER_TARGET Struct
    DeviceNameLength                        DW
    DeviceName                              DW      1 Dup ?
EndS

MOUNTMGR_DRIVE_LETTER_INFORMATION Struct
    DriveLetterWasAssigned                  DB
    CurrentDriveLetter                      DB
EndS

MOUNTMGR_VOLUME_MOUNT_POINT Struct
    SourceVolumeNameOffset                  DW
    SourceVolumeNameLength                  DW
    TargetVolumeNameOffset                  DW
    TargetVolumeNameLength                  DW
EndS

MOUNTMGR_CHANGE_NOTIFY_INFO Struct
    EpicNumber                              DD
EndS

MOUNTMGR_TARGET_NAME Struct
    DeviceNameLength                        DW
    DeviceName                              DW      1 Dup ?
EndS

IOCTL_MOUNTDEV_QUERY_DEVICE_NAME            Equ     CTL_CODE(MOUNTDEVCONTROLTYPE, 2, METHOD_BUFFERED, FILE_ANY_ACCESS)

MOUNTDEV_NAME Struct
    NameLength                              DW
    Name                                    DW      1 Dup ?
EndS

IOCTL_MOUNTMGR_QUERY_DOS_VOLUME_PATH        Equ     CTL_CODE(MOUNTMGRCONTROLTYPE, 12, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_MOUNTMGR_QUERY_DOS_VOLUME_PATHS       Equ     CTL_CODE(MOUNTMGRCONTROLTYPE, 13, METHOD_BUFFERED, FILE_ANY_ACCESS)

MOUNTMGR_VOLUME_PATHS Struct
    MultiSzLength                           Equ     DD
    MultiSz                                 Equ     DW      1 Dup ?
EndS

IOCTL_MOUNTMGR_SCRUB_REGISTRY               Equ     CTL_CODE(MOUNTMGRCONTROLTYPE, 14, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
IOCTL_MOUNTMGR_QUERY_AUTO_MOUNT             Equ     CTL_CODE(MOUNTMGRCONTROLTYPE, 15, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_MOUNTMGR_SET_AUTO_MOUNT               Equ     CTL_CODE(MOUNTMGRCONTROLTYPE, 16, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

;MOUNTMGR_AUTO_MOUNT_STATE Enumeration
Disabled                                    Equ     0
Enabled                                     Equ     1

MOUNTMGR_QUERY_AUTO_MOUNT Struct
    CurrentState                            DD
EndS

MOUNTMGR_SET_AUTO_MOUNT Struct
    NewState                                DD
EndS

IOCTL_MOUNTMGR_BOOT_DL_ASSIGNMENT           Equ     CTL_CODE(MOUNTMGRCONTROLTYPE, 17, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
IOCTL_MOUNTMGR_TRACELOG_CACHE               Equ     CTL_CODE(MOUNTMGRCONTROLTYPE, 18, METHOD_BUFFERED, FILE_READ_ACCESS)

#ENDIF ;MOUNTMGR_H
