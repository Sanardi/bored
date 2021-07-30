;===========================================================;
;                                                           ;
;      ntddft.h for Easy Code 2.0 GoAsm 32-bit drivers      ;
;                     (version 1.0.0)                       ;
;                                                           ;
;             Driver Development Kit (32-bit)               ;
;                                                           ;
;              Copyright © Ramon Sala - 2015                ;
;                                                           ;
;===========================================================;

#IFNDEF NTDDFT_H
#Define NTDDFT_H 1

#IFNDEF MACRODRV_H
    #Include macrodrv.h
#ENDIF

#Include ntdskreg.h

#Define                                                     FTTYPE "f"

FT_SECONDARY_READ                                           Equ         CTL_CODE(FTTYPE, 4, METHOD_OUT_DIRECT, FILE_READ_ACCESS)
FT_PRIMARY_READ                                             Equ         CTL_CODE(FTTYPE, 5, METHOD_OUT_DIRECT, FILE_READ_ACCESS)
FT_BALANCED_READ_MODE                                       Equ         CTL_CODE(FTTYPE, 6, METHOD_NEITHER, FILE_ANY_ACCESS)
FT_SYNC_REDUNDANT_COPY                                      Equ         CTL_CODE(FTTYPE, 7, METHOD_BUFFERED, FILE_ANY_ACCESS)

FT_SPECIAL_READ Struct
    ByteOffset                                              LARGE_INTEGER
    Length                                                  DD
EndS

FT_INITIALIZE_SET                                           Equ         CTL_CODE(FTTYPE, 0, METHOD_BUFFERED, FILE_ANY_ACCESS)
FT_REGENERATE                                               Equ         CTL_CODE(FTTYPE, 1, METHOD_BUFFERED, FILE_ANY_ACCESS)
FT_CONFIGURE                                                Equ         CTL_CODE(FTTYPE, 2, METHOD_NEITHER, FILE_ANY_ACCESS)
FT_VERIFY                                                   Equ         CTL_CODE(FTTYPE, 3, METHOD_BUFFERED, FILE_ANY_ACCESS)
FT_SEQUENTIAL_WRITE_MODE                                    Equ         CTL_CODE(FTTYPE, 8, METHOD_NEITHER, FILE_ANY_ACCESS)
FT_PARALLEL_WRITE_MODE                                      Equ         CTL_CODE(FTTYPE, 9, METHOD_NEITHER, FILE_ANY_ACCESS)
FT_QUERY_SET_STATE                                          Equ         TL_CODE(FTTYPE, 10, METHOD_BUFFERED, FILE_ANY_ACCESS)
FT_CLUSTER_SET_MEMBER_STATE                                 Equ         CTL_CODE(FTTYPE, 11, METHOD_BUFFERED, FILE_ANY_ACCESS)
FT_CLUSTER_GET_MEMBER_STATE                                 Equ         CTL_CODE(FTTYPE, 12, METHOD_BUFFERED, FILE_ANY_ACCESS)

FT_CONTROL_BLOCK Struct
    Type                                                    DW
    FtGroup                                                 DW
EndS

FT_SYNC_INFORMATION Struct
    ByteOffset                                              LARGE_INTEGER
    ByteCount                                               LARGE_INTEGER
EndS

#Define                                                     DISK_REGISTRY_KEY   "\REGISTRY\MACHINE\SYSTEM\DISK"

#Define                                                     DISK_REGISTRY_VALUE "Information"

DISK_CONFIG_HEADER Struct
    Version                                                 DD
    CheckSum                                                DD
    DirtyShutdown                                           DB
    Reserved                                                DB          3 Dup ?
    DiskInformationOffset                                   DD
    DiskInformationSize                                     DD
    FtInformationOffset                                     DD
    FtInformationSize                                       DD
    FtStripeWidth                                           DD
    FtPoolSize                                              DD
    NameOffset                                              DD
    NameSize                                                DD
EndS

DISK_INFORMATION_VERSION                                    Equ         03H

;FT_STATE Enumeration
FtStateOk                                                   Equ         0
FtHasOrphan                                                 Equ         1
FtDisabled                                                  Equ         2
FtRegenerating                                              Equ         3
FtInitializing                                              Equ         4
FtCheckParity                                               Equ         5
FtNoCheckData                                               Equ         6

FT_SET_INFORMATION Struct
    NumberOfMembers                                         DD
    Type                                                    DD
    SetState                                                DD
EndS

FT_MEMBER_DESCRIPTION Struct
    State                                                   DW
    ReservedShort                                           DW
    Signature                                               DD
    OffsetToPartitionInfo                                   DD
    LogicalNumber                                           DD
EndS

FT_VOLUME_INITIALIZING                                      Equ         0001H
FT_VOLUME_REGENERATING                                      Equ         0002H

FT_DESCRIPTION Struct
    NumberOfMembers                                         DW
    Type                                                    DW
    Reserved                                                DD
    FtVolumeState                                           DD
    FtMemberDescription                                     FT_MEMBER_DESCRIPTION 1 Dup ?
EndS

FT_REGISTRY Struct
    NumberOfComponents                                      DW
    ReservedShort                                           DW
    FtDescription                                           FT_DESCRIPTION 1 Dup ?
EndS

#ENDIF ;NTDDFT_H
