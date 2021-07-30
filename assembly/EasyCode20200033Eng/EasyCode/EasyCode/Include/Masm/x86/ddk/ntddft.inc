;===================================================================;
;                                                                   ;
;   ntddft.inc for Easy Code 2.0 JWasm/Masm/PoAsm 32-bit drivers    ;
;                        (version 1.0.0)                            ;
;                                                                   ;
;                 Driver Development Kit (32-bit)                   ;
;                                                                   ;
;                  Copyright © Ramon Sala - 2015                    ;
;                                                                   ;
;===================================================================;

IFNDEF NTDDFT_INC
NTDDFT_INC Equ 1

IFNDEF MACRODRV_INC
    Include macrodrv.inc
ENDIF

Include ntdskreg.inc

FTTYPE                                                      Equ         A("f")

FT_SECONDARY_READ                                           Equ         CTL_CODE(FTTYPE, 4, METHOD_OUT_DIRECT, FILE_READ_ACCESS)
FT_PRIMARY_READ                                             Equ         CTL_CODE(FTTYPE, 5, METHOD_OUT_DIRECT, FILE_READ_ACCESS)
FT_BALANCED_READ_MODE                                       Equ         CTL_CODE(FTTYPE, 6, METHOD_NEITHER, FILE_ANY_ACCESS)
FT_SYNC_REDUNDANT_COPY                                      Equ         CTL_CODE(FTTYPE, 7, METHOD_BUFFERED, FILE_ANY_ACCESS)

FT_SPECIAL_READ Struct
    ByteOffset                                              LARGE_INTEGER   <>
    _Length                                                 ULONG       ?   ;Length
FT_SPECIAL_READ EndS
PFT_SPECIAL_READ                                            TypeDef     DWord

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
    _Type                                                   DW          ?   ;Type
    FtGroup                                                 DW          ?
FT_CONTROL_BLOCK EndS
PFT_CONTROL_BLOCK                                           TypeDef     DWord

FT_SYNC_INFORMATION Struct
    ByteOffset                                              LARGE_INTEGER   <>
    ByteCount                                               LARGE_INTEGER   <>
FT_SYNC_INFORMATION EndS
PFT_SYNC_INFORMATION                                        TypeDef     DWord

DISK_REGISTRY_KEY                                           Equ         A("\REGISTRY\MACHINE\SYSTEM\DISK")

DISK_REGISTRY_VALUE                                         Equ         A("Information")

DISK_CONFIG_HEADER Struct
    Version                                                 DD          ?
    CheckSum                                                DD          ?
    DirtyShutdown                                           BOOLEAN     ?
    Reserved                                                DB          3 Dup(?)
    DiskInformationOffset                                   DD          ?
    DiskInformationSize                                     DD          ?
    FtInformationOffset                                     DD          ?
    FtInformationSize                                       DD          ?
    FtStripeWidth                                           DD          ?
    FtPoolSize                                              DD          ?
    NameOffset                                              DD          ?
    NameSize                                                DD          ?
DISK_CONFIG_HEADER EndS
PDISK_CONFIG_HEADER                                         TypeDef     DWord

DISK_INFORMATION_VERSION                                    Equ         03H

;FT_STATE Enumeration
FT_STATE                                                    TypeDef     DWord
FtStateOk                                                   Equ         0
FtHasOrphan                                                 Equ         1
FtDisabled                                                  Equ         2
FtRegenerating                                              Equ         3
FtInitializing                                              Equ         4
FtCheckParity                                               Equ         5
FtNoCheckData                                               Equ         6
PFT_STATE                                                   TypeDef     DWord

FT_SET_INFORMATION Struct
    NumberOfMembers                                         DD          ?
    _Type                                                   FT_TYPE     ?   ;Type
    SetState                                                FT_STATE    ?
FT_SET_INFORMATION EndS
PFT_SET_INFORMATION                                         TypeDef     DWord

FT_MEMBER_DESCRIPTION Struct
    State                                                   DW          ?
    ReservedShort                                           DW          ?
    Signature                                               DD          ?
    OffsetToPartitionInfo                                   DD          ?
    LogicalNumber                                           DD          ?
FT_MEMBER_DESCRIPTION EndS
PFT_MEMBER_DESCRIPTION                                      TypeDef     DWord

FT_VOLUME_INITIALIZING                                      Equ         0001H
FT_VOLUME_REGENERATING                                      Equ         0002H

FT_DESCRIPTION Struct
    NumberOfMembers                                         DW          ?
    _Type                                                   DW          ?   ;Type
    Reserved                                                DD          ?
    FtVolumeState                                           FT_STATE    ?
    FtMemberDescription                                     FT_MEMBER_DESCRIPTION   1 Dup(<>)
FT_DESCRIPTION EndS
PFT_DESCRIPTION                                             TypeDef     DWord

FT_REGISTRY Struct
    NumberOfComponents                                      DW          ?
    ReservedShort                                           DW          ?
    FtDescription                                           FT_DESCRIPTION  1 Dup(<>)
FT_REGISTRY EndS
PFT_REGISTRY                                                TypeDef     DWord

ENDIF ;NTDDFT_INC
