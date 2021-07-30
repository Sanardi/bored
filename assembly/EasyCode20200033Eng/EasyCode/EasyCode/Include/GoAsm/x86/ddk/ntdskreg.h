;===========================================================;
;                                                           ;
;     ntdskreg.h for Easy Code 2.0 GoAsm 32-bit drivers     ;
;                     (version 1.0.0)                       ;
;                                                           ;
;             Driver Development Kit (32-bit)               ;
;                                                           ;
;              Copyright © Ramon Sala - 2015                ;
;                                                           ;
;===========================================================;

#IFNDEF NTDSKREG_H
#Define NTDSKREG_H 1

#IFNDEF WTYPES_H
    #Include wtypes.h
#ENDIF

;FT_TYPE Enumeration
Mirror                                                      Equ         0
Stripe                                                      Equ         1
StripeWithParity                                            Equ         2
VolumeSet                                                   Equ         3
NotAnFtMember                                               Equ         4
WholeDisk                                                   Equ         5

;FT_PARTITION_STATE Enumeration
Healthy                                                     Equ         0
Orphaned                                                    Equ         1
Regenerating                                                Equ         2
Initializing                                                Equ         3
SyncRedundantCopy                                           Equ         4

DISK_PARTITION Struct
    FtType                                                  DD
    FtState                                                 DD
    StartingOffset                                          LARGE_INTEGER
    Length                                                  LARGE_INTEGER
    FtLength                                                LARGE_INTEGER
    ReservedTwoLongs                                        DD          2 Dup ?
    DriveLetter                                             DB
    AssignDriveLetter                                       DB
    LogicalNumber                                           DW
    FtGroup                                                 DW
    FtMember                                                DW
    Modified                                                DB
    ReservedChars                                           DB          3 Dup ?
EndS

DISK_DESCRIPTION Struct
    NumberOfPartitions                                      DW
    ReservedShort                                           DW
    Signature                                               DD
    Partitions                                              DISK_PARTITION 1 Dup ?
EndS

DISK_REGISTRY Struct
    NumberOfDisks                                           DW
    ReservedShort                                           DW
    Disks                                                   DISK_DESCRIPTION 1 Dup ?
EndS

#ENDIF ;NTDSKREG_H
