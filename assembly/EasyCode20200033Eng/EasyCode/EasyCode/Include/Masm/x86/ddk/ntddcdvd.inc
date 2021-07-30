;===================================================================;
;                                                                   ;
;  ntddcdvd.inc for Easy Code 2.0 JWasm/Masm/PoAsm 32-bit drivers   ;
;                        (version 1.0.0)                            ;
;                                                                   ;
;                 Driver Development Kit (32-bit)                   ;
;                                                                   ;
;                  Copyright © Ramon Sala - 2015                    ;
;                                                                   ;
;===================================================================;

IFNDEF NTDDCDVD_INC
NTDDCDVD_INC Equ 1

Include ntddstor.inc

IOCTL_DVD_BASE                              Equ         FILE_DEVICE_DVD

IOCTL_DVD_END_SESSION                       Equ         CTL_CODE(IOCTL_DVD_BASE, 0403H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_DVD_GET_REGION                        Equ         CTL_CODE(IOCTL_DVD_BASE, 0405H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_DVD_READ_KEY                          Equ         CTL_CODE(IOCTL_DVD_BASE, 0401H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_DVD_READ_STRUCTURE                    Equ         CTL_CODE(IOCTL_DVD_BASE, 0450H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_DVD_SEND_KEY                          Equ         CTL_CODE(IOCTL_DVD_BASE, 0402H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_DVD_START_SESSION                     Equ         CTL_CODE(IOCTL_DVD_BASE, 0400H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_DVD_SET_READ_AHEAD                    Equ         CTL_CODE(IOCTL_DVD_BASE, 0404H, METHOD_BUFFERED, FILE_READ_ACCESS)

DVD_SESSION_ID                              TypeDef DWord
PDVD_SESSION_ID                             TypeDef DWord

STORAGE_SET_READ_AHEAD Struct
    TriggerAddress                          LARGE_INTEGER <>
    TargetAddress                           LARGE_INTEGER <>
STORAGE_SET_READ_AHEAD EndS
PSTORAGE_SET_READ_AHEAD                     TypeDef DWord

;DVD_STRUCTURE_FORMAT Enumeration
DVD_STRUCTURE_FORMAT                        TypeDef DWord
DvdPhysicalDescriptor                       Equ         0
DvdCopyrightDescriptor                      Equ         1
DvdDiskKeyDescriptor                        Equ         2
DvdBCADescriptor                            Equ         3
DvdManufacturerDescriptor                   Equ         4
DvdMaxDescriptor                            Equ         5
PDVD_STRUCTURE_FORMAT                       TypeDef DWord

DVD_READ_STRUCTURE Struct
  BlockByteOffset                           LARGE_INTEGER <>
  Format                                    DVD_STRUCTURE_FORMAT ?
  SessionId                                 DVD_SESSION_ID ?
  LayerNumber                               UCHAR       ?
DVD_READ_STRUCTURE EndS
PDVD_READ_STRUCTURE                         TypeDef DWord

DVD_DESCRIPTOR_HEADER Struct
    _Length                                 USHORT      ?   ;Length
    Reserved                                UCHAR       2 Dup(?)
    Data                                    UCHAR       0 Dup(?)
DVD_DESCRIPTOR_HEADER EndS
PDVD_DESCRIPTOR_HEADER                      TypeDef DWord

DVDLYRREC1 Record                            BookVersion:4, BookType:4, MinimumRate:4, DiskSize:4, LayerType:4, TrackPath:1, NumberOfLayers:2, _Reserved:1, TrackDensity:4, LinearDensity:4
DVDLYRREC2 Record                            Reserved5:7, BCAFlag:1
DVD_LAYER_DESCRIPTOR Struct
    dvdlayerec1                             DVDLYRREC1  <>
    StartingDataSector                      ULONG       ?
    EndDataSector                           ULONG       ?
    EndLayerZeroSector                      ULONG       ?
    dvdlayerec2                             DVDLYRREC2  <>
    Reserved6                               UCHAR       ?
DVD_LAYER_DESCRIPTOR EndS
PDVD_LAYER_DESCRIPTOR                       TypeDef     DWord

DVD_COPYRIGHT_DESCRIPTOR Struct
  CopyrightProtectionType                   UCHAR       ?
  RegionManagementInformation               UCHAR       ?
  Reserved                                  USHORT      ?
DVD_COPYRIGHT_DESCRIPTOR EndS
PDVD_COPYRIGHT_DESCRIPTOR                   TypeDef     DWord

DVD_DISK_KEY_DESCRIPTOR Struct
  DiskKeyData                               UCHAR       2048 Dup(?)
DVD_DISK_KEY_DESCRIPTOR EndS
PDVD_DISK_KEY_DESCRIPTOR                    TypeDef     DWord

;DVD_KEY_TYPE Enumeration
DVD_KEY_TYPE                                TypeDef     DWord
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
    KeyLength                               ULONG       ?
    SessionId                               DVD_SESSION_ID ?
    KeyType                                 DVD_KEY_TYPE ?
    KeyFlags                                ULONG       ?
    Union Parameters
        FileHandle                          HANDLE      ?
        TitleOffset                         LARGE_INTEGER <>
    EndS
    KeyData                                 UCHAR       0 Dup(?)
DVD_COPY_PROTECT_KEY EndS
PDVD_COPY_PROTECT_KEY                       TypeDef     DWord

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
  BCAInformation                            UCHAR       0 Dup(?)
DVD_BCA_DESCRIPTOR EndS
PDVD_BCA_DESCRIPTOR                         TypeDef     DWord

DVD_MANUFACTURER_DESCRIPTOR Struct
  ManufacturingInformation                  UCHAR       2048 Dup(?)
DVD_MANUFACTURER_DESCRIPTOR EndS
PDVD_MANUFACTURER_DESCRIPTOR                TypeDef     DWord

DVDRPCREC Record                            UserResetsAvailable:3, ManufacturerResetsAvailable:3, TypeCode:2
DVD_RPC_KEY Struct
    dvdrpcrec                               DVDRPCREC   <>
    RegionMask                              UCHAR       ?
    RpcScheme                               UCHAR       ?
    Reserved2                               UCHAR       1 Dup(?)
DVD_RPC_KEY EndS
PDVD_RPC_KEY                                TypeDef     DWord

DVD_SET_RPC_KEY Struct
    PreferredDriveRegionCode                UCHAR       ?
    Reserved                                UCHAR       3 Dup(?)
DVD_SET_RPC_KEY EndS
PDVD_SET_RPC_KEY                            TypeDef     DWord

DVDASFREC Record                            SuccessFlag :1, _Reserved1:7
DVD_ASF Struct
    Reserved0                               UCHAR       3 Dup(?)
    dvdasfrec                               DVDASFREC   <>
DVD_ASF EndS
PDVD_ASF                                    TypeDef     DWord

DVD_REGION Struct
    CopySystem                              UCHAR       ?
    RegionData                              UCHAR       ?
    SystemRegion                            UCHAR       ?
    ResetCount                              UCHAR       ?
DVD_REGION EndS
PDVD_REGION                                 TypeDef     DWord

ENDIF ;NTDDCDVD_INC
