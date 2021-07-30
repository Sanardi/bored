;===========================================================;
;                                                           ;
;     ntdddisk.h for Easy Code 2.0 GoAsm 32-bit drivers     ;
;                     (version 1.0.0)                       ;
;                                                           ;
;             Driver Development Kit (32-bit)               ;
;                                                           ;
;              Copyright © Ramon Sala - 2015                ;
;                                                           ;
;===========================================================;

#IFNDEF NTDDDISK_H
#Define NTDDDISK_H 1

#Include diskguid.h
#Include ntddstor.h

#Define                                                     DD_DISK_DEVICE_NAME "\Device\UNKNOWN"

IOCTL_DISK_BASE                                             Equ         FILE_DEVICE_DISK
IOCTL_DISK_GET_DRIVE_GEOMETRY                               Equ         CTL_CODE(IOCTL_DISK_BASE, 0000H, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_DISK_GET_PARTITION_INFO                               Equ         CTL_CODE(IOCTL_DISK_BASE, 0001H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_DISK_SET_PARTITION_INFO                               Equ         CTL_CODE(IOCTL_DISK_BASE, 0002H, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
IOCTL_DISK_GET_DRIVE_LAYOUT                                 Equ         CTL_CODE(IOCTL_DISK_BASE, 0003H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_DISK_SET_DRIVE_LAYOUT                                 Equ         CTL_CODE(IOCTL_DISK_BASE, 0004H, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
IOCTL_DISK_VERIFY                                           Equ         CTL_CODE(IOCTL_DISK_BASE, 0005H, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_DISK_FORMAT_TRACKS                                    Equ         CTL_CODE(IOCTL_DISK_BASE, 0006H, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
IOCTL_DISK_REASSIGN_BLOCKS                                  Equ         CTL_CODE(IOCTL_DISK_BASE, 0007H, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
IOCTL_DISK_PERFORMANCE                                      Equ         CTL_CODE(IOCTL_DISK_BASE, 0008H, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_DISK_IS_WRITABLE                                      Equ         CTL_CODE(IOCTL_DISK_BASE, 0009H, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_DISK_LOGGING                                          Equ         CTL_CODE(IOCTL_DISK_BASE, 000AH, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_DISK_FORMAT_TRACKS_EX                                 Equ         CTL_CODE(IOCTL_DISK_BASE, 000BH, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
IOCTL_DISK_HISTOGRAM_STRUCTURE                              Equ         CTL_CODE(IOCTL_DISK_BASE, 000CH, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_DISK_HISTOGRAM_DATA                                   Equ         CTL_CODE(IOCTL_DISK_BASE, 000DH, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_DISK_HISTOGRAM_RESET                                  Equ         CTL_CODE(IOCTL_DISK_BASE, 000EH, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_DISK_REQUEST_STRUCTURE                                Equ         CTL_CODE(IOCTL_DISK_BASE, 000FH, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_DISK_REQUEST_DATA                                     Equ         CTL_CODE(IOCTL_DISK_BASE, 0010H, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_DISK_PERFORMANCE_OFF                                  Equ         CTL_CODE(IOCTL_DISK_BASE, 0018H, METHOD_BUFFERED, FILE_ANY_ACCESS)

IOCTL_DISK_CONTROLLER_NUMBER                                Equ         CTL_CODE(IOCTL_DISK_BASE, 0011H, METHOD_BUFFERED, FILE_ANY_ACCESS)

SMART_GET_VERSION                                           Equ         CTL_CODE(IOCTL_DISK_BASE, 0020H, METHOD_BUFFERED, FILE_READ_ACCESS)
SMART_SEND_DRIVE_COMMAND                                    Equ         CTL_CODE(IOCTL_DISK_BASE, 0021H, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
SMART_RCV_DRIVE_DATA                                        Equ         CTL_CODE(IOCTL_DISK_BASE, 0022H, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

IOCTL_DISK_GET_PARTITION_INFO_EX                            Equ         CTL_CODE(IOCTL_DISK_BASE, 0012H, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_DISK_SET_PARTITION_INFO_EX                            Equ         CTL_CODE(IOCTL_DISK_BASE, 0013H, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
IOCTL_DISK_GET_DRIVE_LAYOUT_EX                              Equ         CTL_CODE(IOCTL_DISK_BASE, 0014H, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_DISK_SET_DRIVE_LAYOUT_EX                              Equ         CTL_CODE(IOCTL_DISK_BASE, 0015H, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
IOCTL_DISK_CREATE_DISK                                      Equ         CTL_CODE(IOCTL_DISK_BASE, 0016H, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
IOCTL_DISK_GET_LENGTH_INFO                                  Equ         CTL_CODE(IOCTL_DISK_BASE, 0017H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_DISK_GET_DRIVE_GEOMETRY_EX                            Equ         CTL_CODE(IOCTL_DISK_BASE, 0028H, METHOD_BUFFERED, FILE_ANY_ACCESS)

IOCTL_DISK_REASSIGN_BLOCKS_EX                               Equ         CTL_CODE(IOCTL_DISK_BASE, 0029H, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

IOCTL_DISK_UPDATE_DRIVE_SIZE                                Equ         CTL_CODE(IOCTL_DISK_BASE, 0032H, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
IOCTL_DISK_GROW_PARTITION                                   Equ         CTL_CODE(IOCTL_DISK_BASE, 0034H, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

IOCTL_DISK_GET_CACHE_INFORMATION                            Equ         CTL_CODE(IOCTL_DISK_BASE, 0035H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_DISK_SET_CACHE_INFORMATION                            Equ         CTL_CODE(IOCTL_DISK_BASE, 0036H, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
IOCTL_DISK_GET_WRITE_CACHE_STATE                            Equ         CTL_CODE(IOCTL_DISK_BASE, 0037H, METHOD_BUFFERED, FILE_READ_ACCESS)
OBSOLETE_DISK_GET_WRITE_CACHE_STATE                         Equ         CTL_CODE(IOCTL_DISK_BASE, 0037H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_DISK_DELETE_DRIVE_LAYOUT                              Equ         CTL_CODE(IOCTL_DISK_BASE, 0040H, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

IOCTL_DISK_UPDATE_PROPERTIES                                Equ         CTL_CODE(IOCTL_DISK_BASE, 0050H, METHOD_BUFFERED, FILE_ANY_ACCESS)

IOCTL_DISK_FORMAT_DRIVE                                     Equ         CTL_CODE(IOCTL_DISK_BASE, 00F3H, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
IOCTL_DISK_SENSE_DEVICE                                     Equ         CTL_CODE(IOCTL_DISK_BASE, 00F8H, METHOD_BUFFERED, FILE_ANY_ACCESS)

IOCTL_DISK_GET_CACHE_SETTING                                Equ         CTL_CODE(IOCTL_DISK_BASE, 0038H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_DISK_SET_CACHE_SETTING                                Equ         CTL_CODE(IOCTL_DISK_BASE, 0039H, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

;DISK_CACHE_STATE Enumeration
DiskCacheNormal                                             Equ         0
DiskCacheWriteThroughNotSupported                           Equ         1
DiskCacheModifyUnsuccessful                                 Equ         2

DISK_CACHE_SETTING Struct
    Version                                                 DD
    State                                                   DD
    IsPowerProtected                                        DB
EndS

IOCTL_DISK_COPY_DATA                                        Equ         CTL_CODE(IOCTL_DISK_BASE, 0019H, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

DISK_COPY_DATA_PARAMETERS Struct
    SourceOffset                                            LARGE_INTEGER
    DestinationOffset                                       LARGE_INTEGER
    CopyLength                                              LARGE_INTEGER
    Reserved                                                DQ
EndS

IOCTL_DISK_INTERNAL_SET_VERIFY                              Equ         CTL_CODE(IOCTL_DISK_BASE, 0100H, METHOD_NEITHER, FILE_ANY_ACCESS)
IOCTL_DISK_INTERNAL_CLEAR_VERIFY                            Equ         CTL_CODE(IOCTL_DISK_BASE, 0101H, METHOD_NEITHER, FILE_ANY_ACCESS)

IOCTL_DISK_INTERNAL_SET_NOTIFY                              Equ         CTL_CODE(IOCTL_DISK_BASE, 0102H, METHOD_BUFFERED, FILE_ANY_ACCESS)

IOCTL_DISK_CHECK_VERIFY                                     Equ         CTL_CODE(IOCTL_DISK_BASE, 0200H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_DISK_MEDIA_REMOVAL                                    Equ         CTL_CODE(IOCTL_DISK_BASE, 0201H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_DISK_EJECT_MEDIA                                      Equ         CTL_CODE(IOCTL_DISK_BASE, 0202H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_DISK_LOAD_MEDIA                                       Equ         CTL_CODE(IOCTL_DISK_BASE, 0203H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_DISK_RESERVE                                          Equ         CTL_CODE(IOCTL_DISK_BASE, 0204H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_DISK_RELEASE                                          Equ         CTL_CODE(IOCTL_DISK_BASE, 0205H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_DISK_FIND_NEW_DEVICES                                 Equ         CTL_CODE(IOCTL_DISK_BASE, 0206H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_DISK_GET_MEDIA_TYPES                                  Equ         CTL_CODE(IOCTL_DISK_BASE, 0300H, METHOD_BUFFERED, FILE_ANY_ACCESS)

PARTITION_ENTRY_UNUSED                                      Equ         00H
PARTITION_FAT_12                                            Equ         01H
PARTITION_XENIX_1                                           Equ         02H
PARTITION_XENIX_2                                           Equ         03H
PARTITION_FAT_16                                            Equ         04H
PARTITION_EXTENDED                                          Equ         05H
PARTITION_HUGE                                              Equ         06H
PARTITION_IFS                                               Equ         07H
PARTITION_OS2BOOTMGR                                        Equ         0AH
PARTITION_FAT32                                             Equ         0BH
PARTITION_FAT32_XINT13                                      Equ         0CH
PARTITION_XINT13                                            Equ         0EH
PARTITION_XINT13_EXTENDED                                   Equ         0FH
PARTITION_PREP                                              Equ         41H
PARTITION_LDM                                               Equ         42H
PARTITION_UNIX                                              Equ         63H

VALID_NTFT                                                  Equ         C0H

PARTITION_NTFT                                              Equ         80H

;MEDIA_TYPE Enumeration
_Unknown                                                    Equ         0   ;Unknown
F5_1Pt2_512                                                 Equ         1
F3_1Pt44_512                                                Equ         2
F3_2Pt88_512                                                Equ         3
F3_20Pt8_512                                                Equ         4
F3_720_512                                                  Equ         5
F5_360_512                                                  Equ         6
F5_320_512                                                  Equ         7
F5_320_1024                                                 Equ         8
F5_180_512                                                  Equ         9
F5_160_512                                                  Equ         10
RemovableMedia                                              Equ         11
FixedMedia                                                  Equ         12
F3_120M_512                                                 Equ         13
F3_640_512                                                  Equ         14
F5_640_512                                                  Equ         15
F5_720_512                                                  Equ         16
F3_1Pt2_512                                                 Equ         17
F3_1Pt23_1024                                               Equ         18
F5_1Pt23_1024                                               Equ         19
F3_128Mb_512                                                Equ         20
F3_230Mb_512                                                Equ         21
F8_256_128                                                  Equ         22
F3_200Mb_512                                                Equ         23
F3_240M_512                                                 Equ         24
F3_32M_512                                                  Equ         25

FORMAT_PARAMETERS Struct
   MediaType                                                DD
   StartCylinderNumber                                      DD
   EndCylinderNumber                                        DD
   StartHeadNumber                                          DD
   EndHeadNumber                                            DD
EndS

FORMAT_EX_PARAMETERS Struct
    MediaType                                               DD
    StartCylinderNumber                                     DD
    EndCylinderNumber                                       DD
    StartHeadNumber                                         DD
    EndHeadNumber                                           DD
    FormatGapLength                                         DW
    SectorsPerTrack                                         DW
    SectorNumber                                            DW          1 Dup ?
EndS

DISK_GEOMETRY Struct
    Cylinders                                               LARGE_INTEGER
    MediaType                                               DD
    TracksPerCylinder                                       DD
    SectorsPerTrack                                         DD
    BytesPerSector                                          DD
EndS

PARTITION_INFORMATION Struct
    StartingOffset                                          LARGE_INTEGER
    PartitionLength                                         LARGE_INTEGER
    HiddenSectors                                           DD
    PartitionNumber                                         DD
    PartitionType                                           DB
    BootIndicator                                           DB
    RecognizedPartition                                     DB
    RewritePartition                                        DB
EndS

SET_PARTITION_INFORMATION Struct
    PartitionType                                           DB
EndS

DRIVE_LAYOUT_INFORMATION Struct
    PartitionCount                                          DD
    Signature                                               DD
    PartitionEntry                                          PARTITION_INFORMATION 1 Dup ?
EndS

VERIFY_INFORMATION Struct
    StartingOffset                                          LARGE_INTEGER
    Length                                                  DD
EndS

REASSIGN_BLOCKS Struct
    Reserved                                                DW
    Count                                                   DW
    BlockNumber                                             DD          1 Dup ?
EndS

REASSIGN_BLOCKS_EX Struct
    Reserved                                                DW
    Count                                                   DW
    BlockNumber                                             LARGE_INTEGER   1 Dup ?
EndS

;PARTITION_STYLE Enumeration
PARTITION_STYLE_MBR                                         Equ         0
PARTITION_STYLE_GPT                                         Equ         1
PARTITION_STYLE_RAW                                         Equ         2

PARTITION_INFORMATION_GPT Struct
    PartitionType                                           GUID
    PartitionId                                             GUID
    Attributes                                              DQ
    Name                                                    DW          36 Dup ?
EndS

GPT_ATTRIBUTE_PLATFORM_REQUIRED                             Equ         (0000000000000001H)

GPT_BASIC_DATA_ATTRIBUTE_NO_DRIVE_LETTER                    Equ         (8000000000000000H)
GPT_BASIC_DATA_ATTRIBUTE_HIDDEN                             Equ         (4000000000000000H)
GPT_BASIC_DATA_ATTRIBUTE_SHADOW_COPY                        Equ         (2000000000000000H)
GPT_BASIC_DATA_ATTRIBUTE_READ_ONLY                          Equ         (1000000000000000H)

PARTITION_INFORMATION_MBR Struct
    PartitionType                                           DB
    BootIndicator                                           DB
    RecognizedPartition                                     DB
    HiddenSectors                                           DD
EndS

#Define                                                     SET_PARTITION_INFORMATION_MBR SET_PARTITION_INFORMATION
#Define                                                     SET_PARTITION_INFORMATION_GPT PARTITION_INFORMATION_GPT

SET_PARTITION_INFORMATION_EX Struct
    PartitionStyle                                          DD
    DUMMYUNIONNAME Union
        Mbr                                                 SET_PARTITION_INFORMATION_MBR
        Gpt                                                 SET_PARTITION_INFORMATION_GPT
    EndUnion
EndS

CREATE_DISK_GPT Struct
    DiskId                                                  GUID
    MaxPartitionCount                                       DD
EndS

CREATE_DISK_MBR Struct
    Signature                                               DD
EndS

CREATE_DISK Struct
    PartitionStyle                                          DD
    DUMMYUNIONNAME Union
        Mbr                                                 CREATE_DISK_MBR
        Gpt                                                 CREATE_DISK_GPT
    EndUnion
EndS

GET_LENGTH_INFORMATION Struct
    Length                                                  LARGE_INTEGER
EndS

PARTITION_INFORMATION_EX Struct
    PartitionStyle                                          DD
    StartingOffset                                          LARGE_INTEGER
    PartitionLength                                         LARGE_INTEGER
    PartitionNumber                                         DD
    RewritePartition                                        DB
    DUMMYUNIONNAME Union
        Mbr                                                 PARTITION_INFORMATION_MBR
        Gpt                                                 PARTITION_INFORMATION_GPT
    EndUnion
EndS

DRIVE_LAYOUT_INFORMATION_GPT Struct
    DiskId                                                  GUID
    StartingUsableOffset                                    LARGE_INTEGER
    UsableLength                                            LARGE_INTEGER
    MaxPartitionCount                                       DD
EndS

DRIVE_LAYOUT_INFORMATION_MBR Struct
    Signature                                               DD
EndS

DRIVE_LAYOUT_INFORMATION_EX Struct
    PartitionStyle                                          DD
    PartitionCount                                          DD
    DUMMYUNIONNAME Union
        Mbr                                                 DRIVE_LAYOUT_INFORMATION_MBR
        Gpt                                                 DRIVE_LAYOUT_INFORMATION_GPT
    EndUnion
    PartitionEntry                                          PARTITION_INFORMATION_EX 1 Dup ?
EndS

;DETECTION_TYPE Enumeration
DetectNone                                                  Equ         0
DetectInt13                                                 Equ         1
DetectExInt13                                               Equ         2

DISK_INT13_INFO Struct
    DriveSelect                                             DW
    MaxCylinders                                            DD
    SectorsPerTrack                                         DW
    MaxHeads                                                DW
    NumberDrives                                            DW
EndS

DISK_EX_INT13_INFO Struct
    ExBufferSize                                            DW
    ExFlags                                                 DW
    ExCylinders                                             DD
    ExHeads                                                 DD
    ExSectorsPerTrack                                       DD
    ExSectorsPerDrive                                       DQ
    ExSectorSize                                            DW
    ExReserved                                              DW
EndS

DISK_DETECTION_INFO Struct
    SizeOfDetectInfo                                        DD
    DetectionType                                           DD
    DUMMYUNIONNAME Union
        DUMMYSTRUCTNAME Struct
            Int13                                           DISK_INT13_INFO
            ExInt13                                         DISK_EX_INT13_INFO
        EndS
    EndUnion
EndS

DISK_PARTITION_INFO Struct
    SizeOfPartitionInfo                                     DD
    PartitionStyle                                          DD
    DUMMYUNIONNAME Union
        Mbr Struct
            Signature                                       DD
            CheckSum                                        DD
        EndS
        Gpt Struct
            DiskId                                          GUID
        EndS
    EndUnion
EndS

DISK_GEOMETRY_EX Struct
    Geometry                                                DISK_GEOMETRY
    DiskSize                                                LARGE_INTEGER
    Data                                                    DB          1 Dup ?
EndS

DISK_CONTROLLER_NUMBER Struct
    ControllerNumber                                        DD
    DiskNumber                                              DD
EndS

;DISK_CACHE_RETENTION_PRIORITY Enumeration
EqualPriority                                               Equ         0
KeepPrefetchedData                                          Equ         1
KeepReadData                                                Equ         2

;DISK_WRITE_CACHE_STATE Enumeration
DiskWriteCacheNormal                                        Equ         0
DiskWriteCacheForceDisable                                  Equ         1
DiskWriteCacheDisableNotSupported                           Equ         2

DISK_CACHE_INFORMATION Struct
    ParametersSavable                                       DB
    ReadCacheEnabled                                        DB
    WriteCacheEnabled                                       DB
    ReadRetentionPriority                                   DD
    WriteRetentionPriority                                  DD
    DisablePrefetchTransferLength                           DW
    PrefetchScalar                                          DB
    DUMMYUNIONNAME Union
        ScalarPrefetch Struct
            Minimum                                         DW
            Maximum                                         DW
            MaximumBlocks                                   DW
        EndS
        BlockPrefetch Struct
            Minimum                                         DW
            Maximum                                         DW
        EndS
    EndUnion
EndS

DISK_GROW_PARTITION Struct
    PartitionNumber                                         DD
    BytesToGrow                                             LARGE_INTEGER
EndS

HIST_NO_OF_BUCKETS                                          Equ         24

HISTOGRAM_BUCKET Struct
    Reads                                                   DD
    Writes                                                  DD
EndS

HISTOGRAM_BUCKET_SIZE                                       Equ         SizeOf HISTOGRAM_BUCKET

DISK_HISTOGRAM Struct
    DiskSize                                                LARGE_INTEGER
    Start                                                   LARGE_INTEGER
    End                                                     LARGE_INTEGER
    Average                                                 LARGE_INTEGER
    AverageRead                                             LARGE_INTEGER
    AverageWrite                                            LARGE_INTEGER
    Granularity                                             DD
    Size                                                    DD
    ReadCount                                               DD
    WriteCount                                              DD
    Histogram                                               DD
EndS

DISK_HISTOGRAM_SIZE                                         Equ         SizeOf DISK_HISTOGRAM

DISK_PERFORMANCE Struct
    BytesRead                                               LARGE_INTEGER
    BytesWritten                                            LARGE_INTEGER
    ReadTime                                                LARGE_INTEGER
    WriteTime                                               LARGE_INTEGER
    IdleTime                                                LARGE_INTEGER
    ReadCount                                               DD
    WriteCount                                              DD
    QueueDepth                                              DD
    SplitCount                                              DD
    QueryTime                                               LARGE_INTEGER
    StorageDeviceNumber                                     DD
    StorageManagerName                                      DW          8 Dup ?
EndS

DISK_RECORD Struct
   ByteOffset                                               LARGE_INTEGER
   StartTime                                                LARGE_INTEGER
   EndTime                                                  LARGE_INTEGER
   VirtualAddress                                           DD
   NumberOfBytes                                            DD
   DeviceNumber                                             DB
   ReadRequest                                              DB
EndS

DISK_LOGGING Struct
    Function                                                DB
    BufferAddress                                           DD
    BufferSize                                              DD
EndS

DISK_LOGGING_START                                          Equ         0
DISK_LOGGING_STOP                                           Equ         1
DISK_LOGGING_DUMP                                           Equ         2
DISK_BINNING                                                Equ         3

;BIN_TYPES Enumeration
RequestSize                                                 Equ         1
RequestLocation                                             Equ         2

BIN_RANGE Struct
    StartValue                                              LARGE_INTEGER
    Length                                                  LARGE_INTEGER
EndS

PERF_BIN Struct
    NumberOfBins                                            DD
    TypeOfBin                                               DD
    BinsRanges                                              BIN_RANGE   1 Dup ?
EndS

BIN_COUNT Struct
    BinRange                                                BIN_RANGE
    BinCount                                                DD
EndS

BIN_RESULTS Struct
    NumberOfBins                                            DD
    BinCounts                                               BIN_COUNT   1 Dup ?
EndS

GETVERSIONINPARAMS Struct
    bVersion                                                DB
    bRevision                                               DB
    bReserved                                               DB
    bIDEDeviceMap                                           DB
    fCapabilities                                           DD
    dwReserved                                              DD          4 Dup ?
EndS

CAP_ATA_ID_CMD                                              Equ         1
CAP_ATAPI_ID_CMD                                            Equ         2
CAP_SMART_CMD                                               Equ         4

IDEREGS Struct
    bFeaturesReg                                            DB
    bSectorCountReg                                         DB
    bSectorNumberReg                                        DB
    bCylLowReg                                              DB
    bCylHighReg                                             DB
    bDriveHeadReg                                           DB
    bCommandReg                                             DB
    bReserved                                               DB
EndS

ATAPI_ID_CMD                                                Equ         0A1H
ID_CMD                                                      Equ         0ECH
SMART_CMD                                                   Equ         0B0H

SMART_CYL_LOW                                               Equ         04FH
SMART_CYL_HI                                                Equ         0C2H

SENDCMDINPARAMS Struct
    cBufferSize                                             DD
    irDriveRegs                                             IDEREGS
    bDriveNumber                                            DB
    bReserved                                               DB          3 Dup ?
    dwReserved                                              DD          4 Dup ?
    bBuffer                                                 DB          1 Dup ?
EndS

DRIVERSTATUS Struct
    bDriverError                                            DB
    bIDEError                                               DB
    bReserved                                               DB          2 Dup ?
    dwReserved                                              DD          2 Dup ?
EndS

SMART_NO_ERROR                                              Equ         0
SMART_IDE_ERROR                                             Equ         1
SMART_INVALID_FLAG                                          Equ         2
SMART_INVALID_COMMAND                                       Equ         3
SMART_INVALID_BUFFER                                        Equ         4
SMART_INVALID_DRIVE                                         Equ         5
SMART_INVALID_IOCTL                                         Equ         6
SMART_ERROR_NO_MEM                                          Equ         7
SMART_INVALID_REGISTER                                      Equ         8
SMART_NOT_SUPPORTED                                         Equ         9
SMART_NO_IDE_DEVICE                                         Equ         10

SMART_OFFLINE_ROUTINE_OFFLINE                               Equ         0
SMART_SHORT_SELFTEST_OFFLINE                                Equ         1
SMART_EXTENDED_SELFTEST_OFFLINE                             Equ         2
SMART_ABORT_OFFLINE_SELFTEST                                Equ         127
SMART_SHORT_SELFTEST_CAPTIVE                                Equ         129
SMART_EXTENDED_SELFTEST_CAPTIVE                             Equ         130

SENDCMDOUTPARAMS Struct
    cBufferSize                                             DD
    DriverStatus                                            DRIVERSTATUS
    bBuffer                                                 DB          1 Dup ?
EndS

READ_ATTRIBUTE_BUFFER_SIZE                                  Equ         512
IDENTIFY_BUFFER_SIZE                                        Equ         512
READ_THRESHOLD_BUFFER_SIZE                                  Equ         512
SMART_LOG_SECTOR_SIZE                                       Equ         512

READ_ATTRIBUTES                                             Equ         0D0H
READ_THRESHOLDS                                             Equ         0D1H
ENABLE_DISABLE_AUTOSAVE                                     Equ         0D2H
SAVE_ATTRIBUTE_VALUES                                       Equ         0D3H
EXECUTE_OFFLINE_DIAGS                                       Equ         0D4H
SMART_READ_LOG                                              Equ         0D5H
SMART_WRITE_LOG                                             Equ         0d6H
ENABLE_SMART                                                Equ         0D8H
DISABLE_SMART                                               Equ         0D9H
RETURN_SMART_STATUS                                         Equ         0DAH
ENABLE_DISABLE_AUTO_OFFLINE                                 Equ         0DBH

IOCTL_DISK_GET_PARTITION_ATTRIBUTES                         Equ         CTL_CODE(IOCTL_DISK_BASE, 003AH, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_DISK_SET_PARTITION_ATTRIBUTES                         Equ         CTL_CODE(IOCTL_DISK_BASE, 003BH, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

GET_PARTITION_ATTRIBUTES Struct
    Version                                                 DD
    Reserved1                                               DD
    Attributes                                              DQ
EndS

SET_PARTITION_ATTRIBUTES Struct
    Version                                                 DD
    Persist                                                 DB
    Reserved1                                               DB          3 Dup ?
    Attributes                                              DQ
    AttributesMask                                          DQ
EndS

IOCTL_DISK_GET_DISK_ATTRIBUTES                              Equ         CTL_CODE(IOCTL_DISK_BASE, 003CH, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_DISK_SET_DISK_ATTRIBUTES                              Equ         CTL_CODE(IOCTL_DISK_BASE, 003DH, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

DISK_ATTRIBUTE_OFFLINE                                      Equ         0000000000000001H
DISK_ATTRIBUTE_READ_ONLY                                    Equ         0000000000000002H

GET_DISK_ATTRIBUTES Struct
    Version                                                 DD
    Reserved1                                               DD
    Attributes                                              DQ
EndS

SET_DISK_ATTRIBUTES Struct
    Version                                                 DD
    Persist                                                 DB
    RelinquishOwnership                                     DB
    Reserved1                                               DB          2 Dup ?
    Attributes                                              DQ
    AttributesMask                                          DQ
    Owner                                                   GUID
EndS

IOCTL_DISK_IS_CLUSTERED                                     Equ         CTL_CODE(IOCTL_DISK_BASE, 003EH, METHOD_BUFFERED, FILE_ANY_ACCESS)

IOCTL_DISK_GET_SAN_SETTINGS                                 Equ         CTL_CODE(IOCTL_DISK_BASE, 0080H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_DISK_SET_SAN_SETTINGS                                 Equ         CTL_CODE(IOCTL_DISK_BASE, 0081H, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

;DISK_SAN_POLICY Enumeration
DiskSanPolicyUnknown                                        Equ         0
DiskSanPolicyOnline                                         Equ         1
DiskSanPolicyOfflineShared                                  Equ         2
DiskSanPolicyOffline                                        Equ         3
DiskSanPolicyMax                                            Equ         4

DISK_SAN_SETTINGS Struct
    Version                                                 DD
    SanPolicy                                               DD
EndS

IOCTL_DISK_GET_SNAPSHOT_INFO                                Equ         CTL_CODE(IOCTL_DISK_BASE, 0082H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_DISK_SET_SNAPSHOT_INFO                                Equ         CTL_CODE(IOCTL_DISK_BASE, 0083H, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

IOCTL_DISK_RESET_SNAPSHOT_INFO                              Equ         CTL_CODE(IOCTL_DISK_BASE, 0084H, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

;DISK_SNAPSHOT_STATE Enumeration
DiskSnapshotNormalDisk                                      Equ         0
DiskSnapshotSnapshotCheckRequired                           Equ         1
DiskSnapshotPreSnapshot                                     Equ         2
DiskSnapshotSnapshotDisk                                    Equ         3

DISK_SNAPSHOT_INFO Struct
    Version                                                 DD
    State                                                   DD
    SnapshotSetId                                           GUID
    SnapshotId                                              GUID
    LunId                                                   GUID
    CreationTimeStamp                                       LARGE_INTEGER
    ImportCount                                             DD
    Flags                                                   DD
    AdditionalDataSize                                      DD
    AdditionalData                                          DB          ANYSIZE_ARRAY Dup ?
EndS

IOCTL_DISK_SIMBAD                                           Equ         CTL_CODE(IOCTL_DISK_BASE, 0400H, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

MAPPED_ADDRESS Struct
    NextMappedAddress                                       DD
    MappedAddress                                           DD
    NumberOfBytes                                           DD
    IoAddress                                               LARGE_INTEGER
    BusNumber                                               DD
EndS

#ENDIF ;NTDDDISK_H
