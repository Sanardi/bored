;===================================================================;
;                                                                   ;
;  ntdskreg.inc for Easy Code 2.0 JWasm/Masm/PoAsm 32-bit drivers   ;
;                        (version 1.0.0)                            ;
;                                                                   ;
;                 Driver Development Kit (32-bit)                   ;
;                                                                   ;
;                  Copyright © Ramon Sala - 2015                    ;
;                                                                   ;
;===================================================================;

IFNDEF NTDSKREG_INC
NTDSKREG_INC Equ 1

IFNDEF WTYPES_INC
    Include wtypes.inc
ENDIF

;FT_TYPE Enumeration
FT_TYPE                                                     TypeDef     DWord
Mirror                                                      Equ         0
Stripe                                                      Equ         1
StripeWithParity                                            Equ         2
VolumeSet                                                   Equ         3
NotAnFtMember                                               Equ         4
WholeDisk                                                   Equ         5

;FT_PARTITION_STATE Enumeration
FT_PARTITION_STATE                                          TypeDef     DWord
Healthy                                                     Equ         0
Orphaned                                                    Equ         1
Regenerating                                                Equ         2
Initializing                                                Equ         3
SyncRedundantCopy                                           Equ         4
PFT_PARTITION_STATE                                         TypeDef     DWord

DISK_PARTITION Struct
    FtType                                                  FT_TYPE     ?
    FtState                                                 FT_PARTITION_STATE  ?
    StartingOffset                                          LARGE_INTEGER   <>
    _Length                                                 LARGE_INTEGER   <>  ;Length
    FtLength                                                LARGE_INTEGER   <>
    ReservedTwoLongs                                        DD          2 Dup(?)
    DriveLetter                                             DB          ?
    AssignDriveLetter                                       BOOLEAN     ?
    LogicalNumber                                           DW          ?
    FtGroup                                                 DW          ?
    FtMember                                                DW          ?
    Modified                                                BOOLEAN     ?
    ReservedChars                                           DB          3 Dup(?)
DISK_PARTITION EndS
PDISK_PARTITION                                             TypeDef     DWord

DISK_DESCRIPTION Struct
    NumberOfPartitions                                      DW          ?
    ReservedShort                                           DW          ?
    Signature                                               DD          ?
    Partitions                                              DISK_PARTITION  1 Dup(<>)
DISK_DESCRIPTION EndS
PDISK_DESCRIPTION                                           TypeDef     DWord

DISK_REGISTRY Struct
    NumberOfDisks                                           DW          ?
    ReservedShort                                           DW          ?
    Disks                                                   DISK_DESCRIPTION    1 Dup(<>)
DISK_REGISTRY EndS
PDISK_REGISTRY                                              TypeDef     DWord

ENDIF ;NTDSKREG_INC
