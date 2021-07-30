;===================================================================;
;                                                                   ;
;  ntddstor.inc for Easy Code 2.0 JWasm/Masm/PoAsm 32-bit drivers   ;
;                        (version 1.0.0)                            ;
;                                                                   ;
;                 Driver Development Kit (32-bit)                   ;
;                                                                   ;
;                  Copyright © Ramon Sala - 2015                    ;
;                                                                   ;
;===================================================================;

IFNDEF NTDDSTOR_INC
NTDDSTOR_INC Equ 1

IFNDEF MACRODRV_INC
    Include macrodrv.inc
ENDIF

IFNDEF GUID_DEFINED
    Include guiddef.inc
ENDIF

IFNDEF NTDEF_INC
    Include ntdef.inc
ENDIF

METHOD_BUFFERED                                 Equ     0
METHOD_IN_DIRECT                                Equ     1
METHOD_OUT_DIRECT                               Equ     2
METHOD_NEITHER                                  Equ     3

FILE_ANY_ACCESS                                 Equ     0
FILE_SPECIAL_ACCESS                             Equ     FILE_ANY_ACCESS
FILE_READ_ACCESS                                Equ     00001H
FILE_WRITE_ACCESS                               Equ     00002H

IOCTL_STORAGE_BASE                              Equ     FILE_DEVICE_MASS_STORAGE
IOCTL_STORAGE_CHECK_VERIFY                      Equ     ((IOCTL_STORAGE_BASE Shl 16) Or (00200H Shl 2) Or METHOD_BUFFERED Or (FILE_READ_ACCESS Shl 14))
IOCTL_STORAGE_CHECK_VERIFY2                     Equ     ((IOCTL_STORAGE_BASE Shl 16) Or (00200H Shl 2) Or METHOD_BUFFERED Or (FILE_ANY_ACCESS Shl 14))
IOCTL_STORAGE_MEDIA_REMOVAL                     Equ     ((IOCTL_STORAGE_BASE Shl 16) Or (00201H Shl 2) Or METHOD_BUFFERED Or (FILE_READ_ACCESS Shl 14))
IOCTL_STORAGE_EJECT_MEDIA                       Equ     ((IOCTL_STORAGE_BASE Shl 16) Or (00202H Shl 2) Or METHOD_BUFFERED Or (FILE_READ_ACCESS Shl 14))
IOCTL_STORAGE_LOAD_MEDIA                        Equ     ((IOCTL_STORAGE_BASE Shl 16) Or (00203H Shl 2) Or METHOD_BUFFERED Or (FILE_READ_ACCESS Shl 14))
IOCTL_STORAGE_LOAD_MEDIA2                       Equ     ((IOCTL_STORAGE_BASE Shl 16) Or (00203H Shl 2) Or METHOD_BUFFERED Or (FILE_ANY_ACCESS Shl 14))
IOCTL_STORAGE_RESERVE                           Equ     ((IOCTL_STORAGE_BASE Shl 16) Or (00204H Shl 2) Or METHOD_BUFFERED Or (FILE_READ_ACCESS Shl 14))
IOCTL_STORAGE_RELEASE                           Equ     ((IOCTL_STORAGE_BASE Shl 16) Or (00205H Shl 2) Or METHOD_BUFFERED Or (FILE_READ_ACCESS Shl 14))
IOCTL_STORAGE_FIND_NEW_DEVICES                  Equ     ((IOCTL_STORAGE_BASE Shl 16) Or (00206H Shl 2) Or METHOD_BUFFERED Or (FILE_READ_ACCESS Shl 14))
IOCTL_STORAGE_EJECTION_CONTROL                  Equ     ((IOCTL_STORAGE_BASE Shl 16) Or (00250H Shl 2) Or METHOD_BUFFERED Or (FILE_ANY_ACCESS Shl 14))
IOCTL_STORAGE_MCN_CONTROL                       Equ     ((IOCTL_STORAGE_BASE Shl 16) Or (00251H Shl 2) Or METHOD_BUFFERED Or (FILE_ANY_ACCESS Shl 14))
IOCTL_STORAGE_GET_MEDIA_TYPES                   Equ     ((IOCTL_STORAGE_BASE Shl 16) Or (00300H Shl 2) Or METHOD_BUFFERED Or (FILE_ANY_ACCESS Shl 14))
IOCTL_STORAGE_GET_MEDIA_TYPES_EX                Equ     ((IOCTL_STORAGE_BASE Shl 16) Or (00301H Shl 2) Or METHOD_BUFFERED Or (FILE_ANY_ACCESS Shl 14))
IOCTL_STORAGE_RESET_BUS                         Equ     ((IOCTL_STORAGE_BASE Shl 16) Or (00400H Shl 2) Or METHOD_BUFFERED Or (FILE_READ_ACCESS Shl 14))
IOCTL_STORAGE_RESET_DEVICE                      Equ     ((IOCTL_STORAGE_BASE Shl 16) Or (00401H Shl 2) Or METHOD_BUFFERED Or (FILE_READ_ACCESS Shl 14))
IOCTL_STORAGE_GET_DEVICE_NUMBER                 Equ     ((IOCTL_STORAGE_BASE Shl 16) Or (00420H Shl 2) Or METHOD_BUFFERED Or (FILE_ANY_ACCESS Shl 14))
IOCTL_STORAGE_PREDICT_FAILURE                   Equ     ((IOCTL_STORAGE_BASE Shl 16) Or (00440H Shl 2) Or METHOD_BUFFERED Or (FILE_ANY_ACCESS Shl 14))
IOCTL_STORAGE_BREAK_RESERVATION                 Equ     ((IOCTL_STORAGE_BASE Shl 16) Or (00405H Shl 2) Or METHOD_BUFFERED Or (FILE_READWRITE_ACCESS Shl 14))
IOCTL_STORAGE_PERSISTENT_RESERVE_IN             Equ     ((IOCTL_STORAGE_BASE Shl 16) Or (00406H Shl 2) Or METHOD_BUFFERED Or (FILE_READWRITE_ACCESS Shl 14))
IOCTL_STORAGE_PERSISTENT_RESERVE_OUT            Equ     ((IOCTL_STORAGE_BASE Shl 16) Or (00407H Shl 2) Or METHOD_BUFFERED Or (FILE_READWRITE_ACCESS Shl 14))
IOCTL_STORAGE_READ_CAPACITY                     Equ     ((IOCTL_STORAGE_BASE Shl 16) Or (00450H Shl 2) Or METHOD_BUFFERED Or (FILE_ANY_ACCESS Shl 14))
IOCTL_STORAGE_QUERY_PROPERTY                    Equ     CTL_CODE(IOCTL_STORAGE_BASE, 00500H, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_STORAGE_GET_BC_PROPERTIES                 Equ     ((IOCTL_STORAGE_BASE Shl 16) Or (00600H Shl 2) Or METHOD_BUFFERED Or (FILE_READ_ACCESS Shl 14))
IOCTL_STORAGE_ALLOCATE_BC_STREAM                Equ     ((IOCTL_STORAGE_BASE Shl 16) Or (00601H Shl 2) Or METHOD_BUFFERED Or ((FILE_READ_ACCESS  Or  FILE_WRITE_ACCESS) Shl 14))
IOCTL_STORAGE_FREE_BC_STREAM                    Equ     ((IOCTL_STORAGE_BASE Shl 16) Or (00602H Shl 2) Or METHOD_BUFFERED Or ((FILE_READ_ACCESS  Or  FILE_WRITE_ACCESS) Shl 14))
IOCTL_STORAGE_CHECK_PRIORITY_HINT_SUPPORT       Equ     ((IOCTL_STORAGE_BASE Shl 16) Or (00620H Shl 2) Or METHOD_BUFFERED Or (FILE_ANY_ACCESS Shl 14))

DEFINE_GUID GUID_DEVINTERFACE_DISK,             053F56307H, 0B6BFH, 011D0H, 094H, 0F2H, 000H, 0A0H, 0C9H, 01EH, 0FBH, 08BH
DEFINE_GUID GUID_DEVINTERFACE_CDROM,            053F56308H, 0B6BFH, 011D0H, 094H, 0F2H, 000H, 0A0H, 0C9H, 01EH, 0FBH, 08BH
DEFINE_GUID GUID_DEVINTERFACE_PARTITION,        053F5630aH, 0B6BFH, 011D0H, 094H, 0F2H, 000H, 0A0H, 0C9H, 01EH, 0FBH, 08BH
DEFINE_GUID GUID_DEVINTERFACE_TAPE,             053F5630bH, 0B6BFH, 011D0H, 094H, 0F2H, 000H, 0A0H, 0C9H, 01EH, 0FBH, 08BH
DEFINE_GUID GUID_DEVINTERFACE_WRITEONCEDISK,    053F5630cH, 0B6BFH, 011D0H, 094H, 0F2H, 000H, 0A0H, 0C9H, 01EH, 0FBH, 08BH
DEFINE_GUID GUID_DEVINTERFACE_VOLUME,           053F5630dH, 0B6BFH, 011D0H, 094H, 0F2H, 000H, 0A0H, 0C9H, 01EH, 0FBH, 08BH
DEFINE_GUID GUID_DEVINTERFACE_MEDIUMCHANGER,    053F56310H, 0B6BFH, 011D0H, 094H, 0F2H, 000H, 0A0H, 0C9H, 01EH, 0FBH, 08BH
DEFINE_GUID GUID_DEVINTERFACE_FLOPPY,           053F56311H, 0B6BFH, 011D0H, 094H, 0F2H, 000H, 0A0H, 0C9H, 01EH, 0FBH, 08BH
DEFINE_GUID GUID_DEVINTERFACE_CDCHANGER,        053F56312H, 0B6BFH, 011D0H, 094H, 0F2H, 000H, 0A0H, 0C9H, 01EH, 0FBH, 08BH
DEFINE_GUID GUID_DEVINTERFACE_STORAGEPORT,      02ACCFE60H, 0C130H, 011D2H, 0B0H, 082H, 000H, 0A0H, 0C9H, 01EH, 0FBH, 08BH

STORAGE_MEDIA_TYPE                              TypeDef DWord
STORAGE_BUS_TYPE                                TypeDef DWord

DDS_4mm                                         Equ     32
MiniQic                                         Equ     33
Travan                                          Equ     34
QIC                                             Equ     35
MP_8mm                                          Equ     36
AME_8mm                                         Equ     37
AIT1_8mm                                        Equ     38
DLT                                             Equ     39
NCTP                                            Equ     40
IBM_3480                                        Equ     41
IBM_3490E                                       Equ     42
IBM_Magstar_3590                                Equ     43
IBM_Magstar_MP                                  Equ     44
STK_DATA_D3                                     Equ     45
SONY_DTF                                        Equ     46
DV_6mm                                          Equ     47
DMI                                             Equ     48
SONY_D2                                         Equ     49
CLEANER_CARTRIDGE                               Equ     50
CD_ROM                                          Equ     51
CD_R                                            Equ     52
CD_RW                                           Equ     53
DVD_ROM                                         Equ     54
DVD_R                                           Equ     55
DVD_RW                                          Equ     56
MO_3_RW                                         Equ     57
MO_5_WO                                         Equ     58
MO_5_RW                                         Equ     59
MO_5_LIMDOW                                     Equ     60
PC_5_WO                                         Equ     61
PC_5_RW                                         Equ     62
PD_5_RW                                         Equ     63
ABL_5_WO                                        Equ     64
PINNACLE_APEX_5_RW                              Equ     65
SONY_12_WO                                      Equ     66
PHILIPS_12_WO                                   Equ     67
HITACHI_12_WO                                   Equ     68
CYGNET_12_WO                                    Equ     69
KODAK_14_WO                                     Equ     70
MO_NFR_525                                      Equ     71
NIKON_12_RW                                     Equ     72
IOMEGA_ZIP                                      Equ     73
IOMEGA_JAZ                                      Equ     74
SYQUEST_EZ135                                   Equ     75
SYQUEST_EZFLYER                                 Equ     76
SYQUEST_SYJET                                   Equ     77
AVATAR_F2                                       Equ     78
MP2_8mm                                         Equ     79
DST_S                                           Equ     80
DST_M                                           Equ     81
DST_L                                           Equ     82
VXATape_1                                       Equ     83
VXATape_2                                       Equ     84
STK_9840                                        Equ     85
STK_EAGLE                                       Equ     85
LTO_Ultrium                                     Equ     86
LTO_Accelis                                     Equ     87
DVD_RAM                                         Equ     88
AIT_8mm                                         Equ     89
ADR_1                                           Equ     90
ADR_2                                           Equ     91
STK_9940                                        Equ     92
SAIT                                            Equ     93
VXATape                                         Equ     94

;STORAGE_BUS_TYPE Enum
STORAGE_BUS_TYPE                                TypeDef DWord
BusTypeUnknown                                  Equ     0
BusTypeScsi                                     Equ     1
BusTypeAtapi                                    Equ     2
BusTypeAta                                      Equ     3
BusType1394                                     Equ     4
BusTypeSsa                                      Equ     5
BusTypeFibre                                    Equ     6
BusTypeUsb                                      Equ     7
BusTypeRAID                                     Equ     8
BusTypeiScsi                                    Equ     9
BusTypeSas                                      Equ     10
BusTypeSata                                     Equ     11
BusTypeSd                                       Equ     12
BusTypeMmc                                      Equ     13
BusTypeMax                                      Equ     14
BusTypeMaxReserved                              Equ     07FH

MEDIA_ERASEABLE                                 Equ     000000001H
MEDIA_WRITE_ONCE                                Equ     000000002H
MEDIA_READ_ONLY                                 Equ     000000004H
MEDIA_READ_WRITE                                Equ     000000008H
MEDIA_WRITE_PROTECTED                           Equ     000000100H
MEDIA_CURRENTLY_MOUNTED                         Equ     080000000H

IFNDEF DEVICE_MEDIA_INFO
    DEVICE_MEDIA_INFO Struct
        Union DeviceSpecific
            Struct DiskInfo
                Cylinders                       LARGE_INTEGER   <>
                MediaType                       DD      ?
                TracksPerCylinder               DD      ?
                SectorsPerTrack                 DD      ?
                BytesPerSector                  DD      ?
                NumberMediaSides                DD      ?
                MediaCharacteristics            DD      ?
            EndS
            Struct RemovableDiskInfo
                Cylinders                       LARGE_INTEGER   <>
                MediaType                       DD      ?
                TracksPerCylinder               DD      ?
                SectorsPerTrack                 DD      ?
                BytesPerSector                  DD      ?
                NumberMediaSides                DD      ?
                MediaCharacteristics            DD      ?
            EndS
            Struct TapeInfo
                MediaType                       DD      ?
                MediaCharacteristics            DD      ?
                CurrentBlockSize                DD      ?
                BusType                         DD      ?
                Union BusSpecificData
                    Struct ScsiInformation
                        MediumType              DB      ?
                        DensityCode             DB      ?
                    EndS
                EndS
            EndS
        EndS
    DEVICE_MEDIA_INFO EndS
ENDIF

IFNDEF GET_MEDIA_TYPES
    GET_MEDIA_TYPES Struct
        DeviceType                              DD      ?
        MediaInfoCount                          DD      ?
        MediaInfo                               DEVICE_MEDIA_INFO   <>
    GET_MEDIA_TYPES EndS
ENDIF

STORAGE_PREDICT_FAILURE Struct
    PredictFailure                              DD      ?
    VendorSpecific                              DB      512 Dup(?)
STORAGE_PREDICT_FAILURE EndS

STORAGE_ADAPTER_DESCRIPTOR Struct
    Version                                     DD      ?
    _Size                                       DD      ?
    MaximumTransferLength                       DD      ?
    MaximumPhysicalPages                        DD      ?
    AlignmentMask                               DD      ?
    AdapterUsesPio                              BOOLEAN ?
    AdapterScansDown                            BOOLEAN ?
    CommandQueueing                             BOOLEAN ?
    AcceleratedTransfer                         BOOLEAN ?
    BusType                                     STORAGE_BUS_TYPE    ?
    BusMajorVersion                             DW      ?
    BusMinorVersion                             DW      ?
STORAGE_ADAPTER_DESCRIPTOR EndS

STORAGE_ACCESS_ALIGNMENT_DESCRIPTOR Struct
    Version                                     DD      ?
    _Size                                       DD      ?
    BytesPerCacheLine                           DD      ?
    BytesOffsetForCacheAlignment                DD      ?
    BytesPerLogicalSector                       DD      ?
    BytesPerPhysicalSector                      DD      ?
    BytesOffsetForSectorAlignment               DD      ?
STORAGE_ACCESS_ALIGNMENT_DESCRIPTOR EndS

STORAGE_BUS_RESET_REQUEST Struct
    PathId                                      DB      ?
STORAGE_BUS_RESET_REQUEST EndS

STORAGE_DESCRIPTOR_HEADER Struct
    Version                                     DD      ?
    _Size                                       DD      ?
STORAGE_DESCRIPTOR_HEADER EndS

STORAGE_DEVICE_DESCRIPTOR Struct
    Version                                     DD      ?
    _Size                                       DD      ?
    DeviceType                                  DB      ?
    DeviceTypeModifier                          DB      ?
    RemovableMedia                              BOOLEAN ?
    CommandQueueing                             BOOLEAN ?
    VendorIdOffset                              DD      ?
    ProductIdOffset                             DD      ?
    ProductRevisionOffset                       DD      ?
    SerialNumberOffset                          DD      ?
    BusType                                     STORAGE_BUS_TYPE    ?
    RawPropertiesLength                         DD      ?
    RawDeviceProperties                         DB      ?
STORAGE_DEVICE_DESCRIPTOR EndS

STORAGE_DEVICE_ID_DESCRIPTOR Struct
    Version                                     DD      ?
    _Size                                       DD      ?
    NumberOfIdentifiers                         DD      ?
    Identifiers                                 DB      ?
STORAGE_DEVICE_ID_DESCRIPTOR EndS

STORAGE_DEVICE_NUMBER Struct
    DeviceType                                  DD      ?
    DeviceNumber                                DD      ?
    PartitionNumber                             DD      ?
STORAGE_DEVICE_NUMBER EndS

StorageDeviceProperty                           Equ     0
StorageAdapterProperty                          Equ     1
StorageDeviceIdProperty                         Equ     2

PropertyStandardQuery                           Equ     0
PropertyExistsQuery                             Equ     1
PropertyMaskQuery                               Equ     2
PropertyQueryMaxDefined                         Equ     3

STORAGE_PROPERTY_QUERY Struct
    PropertyId                                  DD      ?
    QueryType                                   DD      ?
    AdditionalParameters                        DB      ?
STORAGE_PROPERTY_QUERY EndS

ENDIF ;NTDDSTOR_INC
