;===========================================================;
;                                                           ;
;     ntddcdvd.h for Easy Code 2.0 GoAsm 32-bit drivers     ;
;                     (version 1.0.0)                       ;
;                                                           ;
;             Driver Development Kit (32-bit)               ;
;                                                           ;
;              Copyright © Ramon Sala - 2015                ;
;                                                           ;
;===========================================================;

#IFNDEF NTDDCDVD_H
#Define NTDDCDVD_H 1

#Include ntddstor.h

IOCTL_DVD_BASE                              Equ         FILE_DEVICE_DVD

IOCTL_DVD_END_SESSION                       Equ         CTL_CODE(IOCTL_DVD_BASE, 0403H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_DVD_GET_REGION                        Equ         CTL_CODE(IOCTL_DVD_BASE, 0405H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_DVD_READ_KEY                          Equ         CTL_CODE(IOCTL_DVD_BASE, 0401H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_DVD_READ_STRUCTURE                    Equ         CTL_CODE(IOCTL_DVD_BASE, 0450H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_DVD_SEND_KEY                          Equ         CTL_CODE(IOCTL_DVD_BASE, 0402H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_DVD_START_SESSION                     Equ         CTL_CODE(IOCTL_DVD_BASE, 0400H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_DVD_SET_READ_AHEAD                    Equ         CTL_CODE(IOCTL_DVD_BASE, 0404H, METHOD_BUFFERED, FILE_READ_ACCESS)

STORAGE_SET_READ_AHEAD Struct
    TriggerAddress                          LARGE_INTEGER
    TargetAddress                           LARGE_INTEGER
EndS

;DVD_STRUCTURE_FORMAT Enumeration
DvdPhysicalDescriptor                       Equ         0
DvdCopyrightDescriptor                      Equ         1
DvdDiskKeyDescriptor                        Equ         2
DvdBCADescriptor                            Equ         3
DvdManufacturerDescriptor                   Equ         4
DvdMaxDescriptor                            Equ         5

DVD_READ_STRUCTURE Struct
  BlockByteOffset                           LARGE_INTEGER
  Format                                    DD
  SessionId                                 DD
  LayerNumber                               DB
EndS

DVD_DESCRIPTOR_HEADER Struct
    Length                                  DW
    Reserved                                DB          2 Dup ?
    Data                                    DB          0 Dup ?
EndS

DVD_LAYER_DESCRIPTOR Struct
    fbits                                   DD  ;Members BookVersionto LinearDensity are included here
    StartingDataSector                      DD
    EndDataSector                           DD
    EndLayerZeroSector                      DD
    fBits2                                  DB  ;Members Reserved5 to BCAFlag are included here
    Reserved6                               DB
EndS

DVD_COPYRIGHT_DESCRIPTOR Struct
  CopyrightProtectionType                   DB
  RegionManagementInformation               DB
  Reserved                                  DW
EndS

DVD_DISK_KEY_DESCRIPTOR Struct
  DiskKeyData                               DB          2048 Dup ?
EndS

;DVD_KEY_TYPE Enumeration
DvdChallengeKey                             Equ         001H
DvdBusKey1                                  Equ         002H
DvdBusKey2                                  Equ         003H
DvdTitleKey                                 Equ         004H
DvdAsf                                      Equ         005H
DvdSetRpcKey                                Equ         006H
DvdGetRpcKey                                Equ         008H
DvdDiskKey                                  Equ         080H
DvdInvalidateAGID                           Equ         03FH

DVD_COPY_PROTECT_KEY Struct
    KeyLength                               DD
    SessionId                               DD
    KeyType                                 DD
    KeyFlags                                DD
    Parameters Union
        FileHandle                          DD
        TitleOffset                         LARGE_INTEGER
    EndUnion
    KeyData                                 DB          0 Dup ?
EndS

DVD_CHALLENGE_KEY_LENGTH                    Equ         (12 + SizeOf DVD_COPY_PROTECT_KEY)
DVD_BUS_KEY_LENGTH                          Equ         (8 + SizeOf DVD_COPY_PROTECT_KEY)
DVD_TITLE_KEY_LENGTH                        Equ         (8 + SizeOf DVD_COPY_PROTECT_KEY)
DVD_DISK_KEY_LENGTH                         Equ         (2048 + SizeOf DVD_COPY_PROTECT_KEY)
DVD_RPC_KEY_LENGTH                          Equ         (SizeOf DVD_RPC_KEY + SizeOf DVD_COPY_PROTECT_KEY)
DVD_SET_RPC_KEY_LENGTH                      Equ         (SizeOf DVD_SET_RPC_KEY + SizeOf DVD_COPY_PROTECT_KEY)
DVD_ASF_LENGTH                              Equ         (SizeOf DVD_ASF + SizeOf DVD_COPY_PROTECT_KEY)

DVD_END_ALL_SESSIONS                        Equ         (0FFFFFFFFH)

DVD_CGMS_RESERVED_MASK                      Equ         00000078H

DVD_CGMS_COPY_PROTECT_MASK                  Equ         00000018H
DVD_CGMS_COPY_PERMITTED                     Equ         00000000H
DVD_CGMS_COPY_ONCE                          Equ         00000010H
DVD_CGMS_NO_COPY                            Equ         00000018H

DVD_COPYRIGHT_MASK                          Equ         00000040H
DVD_NOT_COPYRIGHTED                         Equ         00000000H
DVD_COPYRIGHTED                             Equ         00000040H

DVD_SECTOR_PROTECT_MASK                     Equ         00000020H
DVD_SECTOR_NOT_PROTECTED                    Equ         00000000H
DVD_SECTOR_PROTECTED                        Equ         00000020H

DVD_BCA_DESCRIPTOR Struct
  BCAInformation                            DB          0 Dup ?
EndS

DVD_MANUFACTURER_DESCRIPTOR Struct
  ManufacturingInformation                  DB          2048 Dup ?
EndS

DVD_RPC_KEY Struct
    fbits                                   DB  ;Members UserResetsAvailable to TypeCode are included here
    RegionMask                              DB
    RpcScheme                               DB
    Reserved2                               DB          1 Dup ?
EndS

DVD_SET_RPC_KEY Struct
    PreferredDriveRegionCode                DB
    Reserved                                DB          3 Dup ?
EndS

DVD_ASF Struct
    Reserved0                               DB          3 Dup ?
    fbits                                   DB  ;Members SuccessFlag to Reserved1 are included here
EndS

DVD_REGION Struct
    CopySystem                              DB
    RegionData                              DB
    SystemRegion                            DB
    ResetCount                              DB
EndS

#ENDIF ;NTDDCDVD_H
