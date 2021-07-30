;===================================================================;
;                                                                   ;
;  winioctl.inc for Easy Code 2.0 JWasm/Masm/PoAsm 32-bit drivers   ;
;                        (version 1.0.0)                            ;
;                                                                   ;
;                 Driver Development Kit (32-bit)                   ;
;                                                                   ;
;                  Copyright © Ramon Sala - 2015                    ;
;                                                                   ;
;===================================================================;

IFNDEF WINIOCTL_INC
WINIOCTL_INC Equ 1

IFNDEF MACRODRV_INC
    Include macrodrv.inc
ENDIF

IFNDEF WTYPES_INC
    Include wtypes.inc
ENDIF

FILE_DEVICE_BEEP                            Equ     000000001H
FILE_DEVICE_CD_ROM                          Equ     000000002H
FILE_DEVICE_CD_ROM_FILE_SYSTEM              Equ     000000003H
FILE_DEVICE_CONTROLLER                      Equ     000000004H
FILE_DEVICE_DATALINK                        Equ     000000005H
FILE_DEVICE_DFS                             Equ     000000006H
FILE_DEVICE_DISK                            Equ     000000007H
FILE_DEVICE_DISK_FILE_SYSTEM                Equ     000000008H
FILE_DEVICE_FILE_SYSTEM                     Equ     000000009H
FILE_DEVICE_INPORT_PORT                     Equ     00000000AH
FILE_DEVICE_KEYBOARD                        Equ     00000000BH
FILE_DEVICE_MAILSLOT                        Equ     00000000CH
FILE_DEVICE_MIDI_IN                         Equ     00000000DH
FILE_DEVICE_MIDI_OUT                        Equ     00000000EH
FILE_DEVICE_MOUSE                           Equ     00000000FH
FILE_DEVICE_MULTI_UNC_PROVIDER              Equ     000000010H
FILE_DEVICE_NAMED_PIPE                      Equ     000000011H
FILE_DEVICE_NETWORK                         Equ     000000012H
FILE_DEVICE_NETWORK_BROWSER                 Equ     000000013H
FILE_DEVICE_NETWORK_FILE_SYSTEM             Equ     000000014H
FILE_DEVICE_NULL                            Equ     000000015H
FILE_DEVICE_PARALLEL_PORT                   Equ     000000016H
FILE_DEVICE_PHYSICAL_NETCARD                Equ     000000017H
FILE_DEVICE_PRINTER                         Equ     000000018H
FILE_DEVICE_SCANNER                         Equ     000000019H
FILE_DEVICE_SERIAL_MOUSE_PORT               Equ     00000001AH
FILE_DEVICE_SERIAL_PORT                     Equ     00000001BH
FILE_DEVICE_SCREEN                          Equ     00000001CH
FILE_DEVICE_SOUND                           Equ     00000001DH
FILE_DEVICE_STREAMS                         Equ     00000001EH
FILE_DEVICE_TAPE                            Equ     00000001FH
FILE_DEVICE_TAPE_FILE_SYSTEM                Equ     000000020H
FILE_DEVICE_TRANSPORT                       Equ     000000021H
FILE_DEVICE_UNKNOWN                         Equ     000000022H
FILE_DEVICE_VIDEO                           Equ     000000023H
FILE_DEVICE_VIRTUAL_DISK                    Equ     000000024H
FILE_DEVICE_WAVE_IN                         Equ     000000025H
FILE_DEVICE_WAVE_OUT                        Equ     000000026H
FILE_DEVICE_8042_PORT                       Equ     000000027H
FILE_DEVICE_NETWORK_REDIRECTOR              Equ     000000028H
FILE_DEVICE_BATTERY                         Equ     000000029H
FILE_DEVICE_BUS_EXTENDER                    Equ     00000002AH
FILE_DEVICE_MODEM                           Equ     00000002BH
FILE_DEVICE_VDM                             Equ     00000002CH
FILE_DEVICE_MASS_STORAGE                    Equ     00000002DH
FILE_DEVICE_SMB                             Equ     00000002EH
FILE_DEVICE_KS                              Equ     00000002FH
FILE_DEVICE_CHANGER                         Equ     000000030H
FILE_DEVICE_SMARTCARD                       Equ     000000031H
FILE_DEVICE_ACPI                            Equ     000000032H
FILE_DEVICE_DVD                             Equ     000000033H
FILE_DEVICE_FULLSCREEN_VIDEO                Equ     000000034H
FILE_DEVICE_DFS_FILE_SYSTEM                 Equ     000000035H
FILE_DEVICE_DFS_VOLUME                      Equ     000000036H

METHOD_BUFFERED                             Equ     0
METHOD_IN_DIRECT                            Equ     1
METHOD_OUT_DIRECT                           Equ     2
METHOD_NEITHER                              Equ     3

FILE_ANY_ACCESS                             Equ     0
FILE_READ_ACCESS                            Equ     00001H
FILE_WRITE_ACCESS                           Equ     00002H

IOCTL_STORAGE_BASE                          Equ     FILE_DEVICE_MASS_STORAGE

IOCTL_STORAGE_CHECK_VERIFY                  Equ     CTL_CODE(IOCTL_STORAGE_BASE, 0200H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_STORAGE_MEDIA_REMOVAL                 Equ     CTL_CODE(IOCTL_STORAGE_BASE, 0201H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_STORAGE_EJECT_MEDIA                   Equ     CTL_CODE(IOCTL_STORAGE_BASE, 0202H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_STORAGE_LOAD_MEDIA                    Equ     CTL_CODE(IOCTL_STORAGE_BASE, 0203H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_STORAGE_RESERVE                       Equ     CTL_CODE(IOCTL_STORAGE_BASE, 0204H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_STORAGE_RELEASE                       Equ     CTL_CODE(IOCTL_STORAGE_BASE, 0205H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_STORAGE_FIND_NEW_DEVICES              Equ     CTL_CODE(IOCTL_STORAGE_BASE, 0206H, METHOD_BUFFERED, FILE_READ_ACCESS)

IOCTL_STORAGE_GET_MEDIA_TYPES               Equ     CTL_CODE(IOCTL_STORAGE_BASE, 0300H, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_STORAGE_GET_MEDIA_TYPES_EX            Equ     CTL_CODE(IOCTL_STORAGE_BASE, 0301H, METHOD_BUFFERED, FILE_ANY_ACCESS)

IOCTL_STORAGE_RESET_BUS                     Equ     CTL_CODE(IOCTL_STORAGE_BASE, 0400H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_STORAGE_RESET_DEVICE                  Equ     CTL_CODE(IOCTL_STORAGE_BASE, 0401H, METHOD_BUFFERED, FILE_READ_ACCESS)

IOCTL_STORAGE_GET_DEVICE_NUMBER             Equ     CTL_CODE(IOCTL_STORAGE_BASE, 0420H, METHOD_BUFFERED, FILE_ANY_ACCESS)

STORAGE_DEVICE_NUMBER Struct
    DeviceType                              DD      ?
    DeviceNumber                            DD      ?
    PartitionNumber                         DD      ?
STORAGE_DEVICE_NUMBER EndS

STORAGE_BUS_RESET_REQUEST Struct
    PathId                                  DB      ?
STORAGE_BUS_RESET_REQUEST EndS

PREVENT_MEDIA_REMOVAL Struct
    PreventMediaRemoval                     DD      ?
PREVENT_MEDIA_REMOVAL EndS

TAPE_STATISTICS Struct
    Version                                 DD      ?
    iFlags                                  DD      ?
    RecoveredWrites                         DQ      ?
    UnrecoveredWrites                       DQ      ?
    RecoveredReads                          DQ      ?
    UnrecoveredReads                        DQ      ?
    CompressionRatioReads                   DB      ?
    CompressionRatioWrites                  DB      ?
TAPE_STATISTICS EndS

RECOVERED_WRITES_VALID                      Equ     000000001H
UNRECOVERED_WRITES_VALID                    Equ     000000002H
RECOVERED_READS_VALID                       Equ     000000004H
UNRECOVERED_READS_VALID                     Equ     000000008H
WRITE_COMPRESSION_INFO_VALID                Equ     000000010H
READ_COMPRESSION_INFO_VALID                 Equ     000000020H

TAPE_GET_STATISTICS Struct
    Operation                               DD      ?
TAPE_GET_STATISTICS EndS

TAPE_RETURN_STATISTICS                      Equ     0
TAPE_RETURN_ENV_INFO                        Equ     1
TAPE_RESET_STATISTICS                       Equ     2

;STORAGE_MEDIA_TYPE Enumeration
STORAGE_MEDIA_TYPE                          TypeDef DWord
DDS_4mm                                     Equ     32
MiniQic                                     Equ     33
Travan                                      Equ     34
QIC                                         Equ     35
MP_8mm                                      Equ     36
AME_8mm                                     Equ     37
AIT1_8mm                                    Equ     38
DLT                                         Equ     39
NCTP                                        Equ     40
IBM_3480                                    Equ     41
IBM_3490E                                   Equ     42
IBM_Magstar_3590                            Equ     43
IBM_Magstar_MP                              Equ     44
STK_DATA_D3                                 Equ     45
SONY_DTF                                    Equ     46
DV_6mm                                      Equ     47
DMI                                         Equ     48
SONY_D2                                     Equ     49
CLEANER_CARTRIDGE                           Equ     50
CD_ROM                                      Equ     51
CD_R                                        Equ     52
CD_RW                                       Equ     53
DVD_ROM                                     Equ     54
DVD_R                                       Equ     55
DVD_RW                                      Equ     56
MO_3_RW                                     Equ     57
MO_5_WO                                     Equ     58
MO_5_RW                                     Equ     59
MO_5_LIMDOW                                 Equ     60
PC_5_WO                                     Equ     61
PC_5_RW                                     Equ     62
PD_5_RW                                     Equ     63
ABL_5_WO                                    Equ     64
PINNACLE_APEX_5_RW                          Equ     65
SONY_12_WO                                  Equ     66
PHILIPS_12_WO                               Equ     67
HITACHI_12_WO                               Equ     68
CYGNET_12_WO                                Equ     69
KODAK_14_WO                                 Equ     70
MO_NFR_525                                  Equ     71
NIKON_12_RW                                 Equ     72
IOMEGA_ZIP                                  Equ     73
IOMEGA_JAZ                                  Equ     74
SYQUEST_EZ135                               Equ     75
SYQUEST_EZFLYER                             Equ     76
SYQUEST_SYJET                               Equ     77
AVATAR_F2                                   Equ     78
MP2_8mm                                     Equ     79

MEDIA_ERASEABLE                             Equ     000000001H
MEDIA_WRITE_ONCE                            Equ     000000002H
MEDIA_READ_ONLY                             Equ     000000004H
MEDIA_READ_WRITE                            Equ     000000008H

MEDIA_WRITE_PROTECTED                       Equ     000000100H
MEDIA_CURRENTLY_MOUNTED                     Equ     080000000H

IFNDEF DEVICE_MEDIA_INFO
    DEVICE_MEDIA_INFO Struct
        Union DeviceSpecific
            Struct DiskInfo
                Cylinders                   LARGE_INTEGER   <>
                MediaType                   DD      ?
                TracksPerCylinder           DD      ?
                SectorsPerTrack             DD      ?
                BytesPerSector              DD      ?
                NumberMediaSides            DD      ?
                MediaCharacteristics        DD      ?
            EndS
            Struct RemovableDiskInfo
                Cylinders                   LARGE_INTEGER   <>
                MediaType                   DD      ?
                TracksPerCylinder           DD      ?
                SectorsPerTrack             DD      ?
                BytesPerSector              DD      ?
                NumberMediaSides            DD      ?
                MediaCharacteristics        DD      ?
            EndS
            Struct TapeInfo
                MediaType                   DD      ?
                MediaCharacteristics        DD      ?
                CurrentBlockSize            DD      ?
                BusType                     DD      ?
                Union BusSpecificData
                    Struct ScsiInformation
                        MediumType          DB      ?
                        DensityCode         DB      ?
                    EndS
                EndS
            EndS
        EndS
    DEVICE_MEDIA_INFO EndS
ENDIF

IFNDEF GET_MEDIA_TYPES
    GET_MEDIA_TYPES Struct
        DeviceType                          DD      ?
        MediaInfoCount                      DD      ?
        MediaInfo                           DEVICE_MEDIA_INFO   <>
    GET_MEDIA_TYPES EndS
ENDIF

IOCTL_DISK_BASE                             Equ     FILE_DEVICE_DISK

IOCTL_DISK_GET_DRIVE_GEOMETRY               Equ     CTL_CODE(IOCTL_DISK_BASE, 0000H, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_DISK_GET_PARTITION_INFO               Equ     CTL_CODE(IOCTL_DISK_BASE, 0001H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_DISK_SET_PARTITION_INFO               Equ     CTL_CODE(IOCTL_DISK_BASE, 0002H, METHOD_BUFFERED, FILE_READ_ACCESS Or FILE_WRITE_ACCESS)
IOCTL_DISK_GET_DRIVE_LAYOUT                 Equ     CTL_CODE(IOCTL_DISK_BASE, 0003H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_DISK_SET_DRIVE_LAYOUT                 Equ     CTL_CODE(IOCTL_DISK_BASE, 0004H, METHOD_BUFFERED, FILE_READ_ACCESS Or FILE_WRITE_ACCESS)
IOCTL_DISK_VERIFY                           Equ     CTL_CODE(IOCTL_DISK_BASE, 0005H, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_DISK_FORMAT_TRACKS                    Equ     CTL_CODE(IOCTL_DISK_BASE, 0006H, METHOD_BUFFERED, FILE_READ_ACCESS Or FILE_WRITE_ACCESS)
IOCTL_DISK_REASSIGN_BLOCKS                  Equ     CTL_CODE(IOCTL_DISK_BASE, 0007H, METHOD_BUFFERED, FILE_READ_ACCESS Or FILE_WRITE_ACCESS)
IOCTL_DISK_PERFORMANCE                      Equ     CTL_CODE(IOCTL_DISK_BASE, 0008H, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_DISK_IS_WRITABLE                      Equ     CTL_CODE(IOCTL_DISK_BASE, 0009H, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_DISK_LOGGING                          Equ     CTL_CODE(IOCTL_DISK_BASE, 000AH, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_DISK_FORMAT_TRACKS_EX                 Equ     CTL_CODE(IOCTL_DISK_BASE, 000BH, METHOD_BUFFERED, FILE_READ_ACCESS Or FILE_WRITE_ACCESS)
IOCTL_DISK_HISTOGRAM_STRUCTURE              Equ     CTL_CODE(IOCTL_DISK_BASE, 000CH, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_DISK_HISTOGRAM_DATA                   Equ     CTL_CODE(IOCTL_DISK_BASE, 000DH, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_DISK_HISTOGRAM_RESET                  Equ     CTL_CODE(IOCTL_DISK_BASE, 000EH, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_DISK_REQUEST_STRUCTURE                Equ     CTL_CODE(IOCTL_DISK_BASE, 000FH, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_DISK_REQUEST_DATA                     Equ     CTL_CODE(IOCTL_DISK_BASE, 0010H, METHOD_BUFFERED, FILE_ANY_ACCESS)

IOCTL_DISK_CONTROLLER_NUMBER                Equ     CTL_CODE(IOCTL_DISK_BASE, 0011H, METHOD_BUFFERED, FILE_ANY_ACCESS)

SMART_GET_VERSION                           Equ     CTL_CODE(IOCTL_DISK_BASE, 0020H, METHOD_BUFFERED, FILE_READ_ACCESS)
SMART_SEND_DRIVE_COMMAND                    Equ     CTL_CODE(IOCTL_DISK_BASE, 0021H, METHOD_BUFFERED, FILE_READ_ACCESS Or FILE_WRITE_ACCESS)
SMART_RCV_DRIVE_DATA                        Equ     CTL_CODE(IOCTL_DISK_BASE, 0022H, METHOD_BUFFERED, FILE_READ_ACCESS Or FILE_WRITE_ACCESS)

IOCTL_DISK_CHECK_VERIFY                     Equ     CTL_CODE(IOCTL_DISK_BASE, 0200H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_DISK_MEDIA_REMOVAL                    Equ     CTL_CODE(IOCTL_DISK_BASE, 0201H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_DISK_EJECT_MEDIA                      Equ     CTL_CODE(IOCTL_DISK_BASE, 0202H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_DISK_LOAD_MEDIA                       Equ     CTL_CODE(IOCTL_DISK_BASE, 0203H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_DISK_RESERVE                          Equ     CTL_CODE(IOCTL_DISK_BASE, 0204H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_DISK_RELEASE                          Equ     CTL_CODE(IOCTL_DISK_BASE, 0205H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_DISK_FIND_NEW_DEVICES                 Equ     CTL_CODE(IOCTL_DISK_BASE, 0206H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_DISK_GET_MEDIA_TYPES                  Equ     CTL_CODE(IOCTL_DISK_BASE, 0300H, METHOD_BUFFERED, FILE_ANY_ACCESS)

PARTITION_ENTRY_UNUSED                      Equ     000H
PARTITION_FAT_12                            Equ     001H
PARTITION_XENIX_1                           Equ     002H
PARTITION_XENIX_2                           Equ     003H
PARTITION_FAT_16                            Equ     004H
PARTITION_EXTENDED                          Equ     005H
PARTITION_HUGE                              Equ     006H
PARTITION_IFS                               Equ     007H
PARTITION_FAT32                             Equ     00BH
PARTITION_FAT32_XINT13                      Equ     00CH
PARTITION_XINT13                            Equ     00EH
PARTITION_XINT13_EXTENDED                   Equ     00FH
PARTITION_PREP                              Equ     041H
PARTITION_LDM                               Equ     042H
PARTITION_UNIX                              Equ     063H

VALID_NTFT                                  Equ     0C0H

PARTITION_NTFT                              Equ     080H

;MEDIA_TYPE Enumeration
MEDIA_TYPE                                  TypeDef DWord
Unknown                                     Equ     0
F5_1Pt2_512                                 Equ     1
F3_1Pt44_512                                Equ     2
F3_2Pt88_512                                Equ     3
F3_20Pt8_512                                Equ     4
F3_720_512                                  Equ     5
F5_360_512                                  Equ     6
F5_320_512                                  Equ     7
F5_320_1024                                 Equ     8
F5_180_512                                  Equ     9
F5_160_512                                  Equ     10
RemovableMedia                              Equ     11
FixedMedia                                  Equ     12
F3_120M_512                                 Equ     13
F3_640_512                                  Equ     14
F5_640_512                                  Equ     15
F5_720_512                                  Equ     16
F3_1Pt2_512                                 Equ     17
F3_1Pt23_1024                               Equ     18
F5_1Pt23_1024                               Equ     19
F3_128Mb_512                                Equ     20
F3_230Mb_512                                Equ     21
F8_256_128                                  Equ     22

FORMAT_PARAMETERS Struct
    MediaType                               DD      ?
    StartCylinderNumber                     DD      ?
    EndCylinderNumber                       DD      ?
    StartHeadNumber                         DD      ?
    EndHeadNumber                           DD      ?
FORMAT_PARAMETERS EndS

FORMAT_EX_PARAMETERS Struct
    MediaType                               DD      ?
    StartCylinderNumber                     DD      ?
    EndCylinderNumber                       DD      ?
    StartHeadNumber                         DD      ?
    EndHeadNumber                           DD      ?
    FormatGapLength                         DW      ?
    SectorsPerTrack                         DW      ?
    SectorNumber                            DW      ?
FORMAT_EX_PARAMETERS EndS

DISK_GEOMETRY Struct
    Cylinders                               DQ      ?
    MediaType                               DD      ?
    TracksPerCylinder                       DD      ?
    SectorsPerTrack                         DD      ?
    BytesPerSector                          DD      ?
DISK_GEOMETRY EndS

PARTITION_INFORMATION Struct
    StartingOffset                          DQ      ?
    PartitionLength                         DQ      ?
    HiddenSectors                           DD      ?
    PartitionNumber                         DD      ?
    PartitionType                           DB      ?
    BootIndicator                           DD      ?
    RecognizedPartition                     DD      ?
    RewritePartition                        DD      ?
PARTITION_INFORMATION EndS

SET_PARTITION_INFORMATION Struct
    PartitionType                           DB      ?
SET_PARTITION_INFORMATION EndS

DRIVE_LAYOUT_INFORMATION Struct
    PartitionCount                          DD      ?
    Signature                               DD      ?
    PartitionEntry                          PARTITION_INFORMATION   <>
DRIVE_LAYOUT_INFORMATION EndS

VERIFY_INFORMATION Struct
    StartingOffset                          DQ      ?
    _Length                                 DD      ?
VERIFY_INFORMATION EndS

REASSIGN_BLOCKS Struct
    Reserved                                DW      ?
    Count                                   DW      ?
    BlockNumber                             DD      ?
REASSIGN_BLOCKS EndS

DISK_CONTROLLER_NUMBER Struct
    ControllerNumber                        DD      ?
    DiskNumber                              DD      ?
DISK_CONTROLLER_NUMBER EndS

HIST_NO_OF_BUCKETS                          Equ     24

HISTOGRAM_BUCKET Struct
    Reads                                   DD      ?
    Writes                                  DD      ?
HISTOGRAM_BUCKET EndS

DISK_HISTOGRAM Struct
    DiskSize                                LARGE_INTEGER   <>
    iStart                                  LARGE_INTEGER   <>
    iEnd                                    LARGE_INTEGER   <>
    Average                                 LARGE_INTEGER   <>
    AverageRead                             LARGE_INTEGER   <>
    AverageWrite                            LARGE_INTEGER   <>
    Granularity                             DD      ?
    _Size                                   DD      ?
    ReadCount                               DD      ?
    WriteCount                              DD      ?
    Histogram                               DD      ?
DISK_HISTOGRAM EndS

HISTOGRAM_BUCKET_SIZE                       Equ     SizeOf(HISTOGRAM_BUCKET)

DISK_HISTOGRAM_SIZE                         Equ     SizeOf(DISK_HISTOGRAM)

DISK_PERFORMANCE Struct
    BytesRead                               LARGE_INTEGER   <>
    BytesWritten                            LARGE_INTEGER   <>
    ReadTime                                LARGE_INTEGER   <>
    WriteTime                               LARGE_INTEGER   <>
    IdleTime                                LARGE_INTEGER   <>
    ReadCount                               DD      ?
    WriteCount                              DD      ?
    QueueDepth                              DD      ?
    SplitCount                              DD      ?
    QueryTime                               LARGE_INTEGER   <>
    StorageDeviceNumber                     DD      ?
    StorageManagerName                      DW      8 Dup(?)
DISK_PERFORMANCE EndS

DISK_RECORD Struct
    ByteOffset                              LARGE_INTEGER   <>
    StartTime                               LARGE_INTEGER   <>
    EndTime                                 LARGE_INTEGER   <>
    VirtualAddress                          DD      ?
    NumberOfBytes                           DD      ?
    DeviceNumber                            DB      ?
    ReadRequest                             DD      ?
DISK_RECORD EndS

DISK_LOGGING Struct
    Function                                DB      ?
    BufferAddress                           DD      ?
    BufferSize                              DD      ?
DISK_LOGGING EndS

DISK_LOGGING_START                          Equ     0
DISK_LOGGING_STOP                           Equ     1
DISK_LOGGING_DUMP                           Equ     2
DISK_BINNING                                Equ     3

;BIN_TYPES Enumeration
BIN_TYPES                                   TypeDef DWord
RequestSize                                 Equ     0
RequestLocation                             Equ     1

BIN_RANGE Struct
    StartValue                              LARGE_INTEGER   <>
    _Length                                 LARGE_INTEGER   <>
BIN_RANGE EndS

PERF_BIN Struct
    NumberOfBins                            DD      ?
    TypeOfBin                               DD      ?
    BinsRanges                              BIN_RANGE   <>
PERF_BIN EndS

BIN_COUNT Struct
    BinRange                                BIN_RANGE   <>
    BinCount                                DD      ?
BIN_COUNT EndS

BIN_RESULTS Struct
    NumberOfBins                            DD      ?
    BinCounts                               BIN_RANGE   <>
BIN_RESULTS EndS

GETVERSIONINPARAMS Struct
    bVersion                                DB      ?
    bRevision                               DB      ?
    bReserved                               DB      ?
    bIDEDeviceMap                           DB      ?
    fCapabilities                           DD      ?
    dwReserved                              DD      4 Dup(?)
GETVERSIONINPARAMS EndS

CAP_ATA_ID_CMD                              Equ     1
CAP_ATAPI_ID_CMD                            Equ     2
CAP_SMART_CMD                               Equ     4

IDEREGS Struct
    bFeaturesReg                            DB      ?
    bSectorCountReg                         DB      ?
    bSectorNumberReg                        DB      ?
    bCylLowReg                              DB      ?
    bCylHighReg                             DB      ?
    bDriveHeadReg                           DB      ?
    bCommandReg                             DB      ?
    bReserved                               DB      ?
IDEREGS EndS

ATAPI_ID_CMD                                Equ     0A1H
ID_CMD                                      Equ     0ECH
SMART_CMD                                   Equ     0B0H

SMART_CYL_LOW                               Equ     04FH
SMART_CYL_HI                                Equ     0C2H

SENDCMDINPARAMS Struct
    cBufferSize                             DD      ?
    irDriveRegs                             IDEREGS <>
    bDriveNumber                            DB      ?
    bReserved                               DB      3 Dup(?)
    dwReserved                              DD      4 Dup(?)
    bBuffer                                 DB      ?
SENDCMDINPARAMS EndS

DRIVERSTATUS Struct
    bDriverError                            DB      ?
    bIDEError                               DB      ?
    bReserved                               DB      2 Dup(?)
    dwReserved                              DD      2 Dup(?)
DRIVERSTATUS EndS

SMART_NO_ERROR                              Equ     0
SMART_IDE_ERROR                             Equ     1
SMART_INVALID_FLAG                          Equ     2
SMART_INVALID_COMMAND                       Equ     3
SMART_INVALID_BUFFER                        Equ     4
SMART_INVALID_DRIVE                         Equ     5
SMART_INVALID_IOCTL                         Equ     6
SMART_ERROR_NO_MEM                          Equ     7
SMART_INVALID_REGISTER                      Equ     8
SMART_NOT_SUPPORTED                         Equ     9
SMART_NO_IDE_DEVICE                         Equ     10

SENDCMDOUTPARAMS Struct
    cBufferSize                             DD      ?
    DriverStatus                            DRIVERSTATUS    <>
    bBuffer                                 DB      ?
SENDCMDOUTPARAMS EndS

READ_ATTRIBUTE_BUFFER_SIZE                  Equ     512
IDENTIFY_BUFFER_SIZE                        Equ     512
READ_THRESHOLD_BUFFER_SIZE                  Equ     512

READ_ATTRIBUTES                             Equ     0D0H
READ_THRESHOLDS                             Equ     0D1H
ENABLE_DISABLE_AUTOSAVE                     Equ     0D2H
SAVE_ATTRIBUTE_VALUES                       Equ     0D3H
EXECUTE_OFFLINE_DIAGS                       Equ     0D4H
ENABLE_SMART                                Equ     0D8H
DISABLE_SMART                               Equ     0D9H
RETURN_SMART_STATUS                         Equ     0DAH

IOCTL_CHANGER_BASE                          Equ     FILE_DEVICE_CHANGER

IOCTL_CHANGER_GET_PARAMETERS                Equ     CTL_CODE(IOCTL_CHANGER_BASE, 0000H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CHANGER_GET_STATUS                    Equ     CTL_CODE(IOCTL_CHANGER_BASE, 0001H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CHANGER_GET_PRODUCT_DATA              Equ     CTL_CODE(IOCTL_CHANGER_BASE, 0002H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CHANGER_SET_ACCESS                    Equ     CTL_CODE(IOCTL_CHANGER_BASE, 0004H, METHOD_BUFFERED, FILE_READ_ACCESS Or FILE_WRITE_ACCESS)
IOCTL_CHANGER_GET_ELEMENT_STATUS            Equ     CTL_CODE(IOCTL_CHANGER_BASE, 0005H, METHOD_BUFFERED, FILE_READ_ACCESS Or FILE_WRITE_ACCESS)
IOCTL_CHANGER_INITIALIZE_ELEMENT_STATUS     Equ     CTL_CODE(IOCTL_CHANGER_BASE, 0006H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CHANGER_SET_POSITION                  Equ     CTL_CODE(IOCTL_CHANGER_BASE, 0007H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CHANGER_EXCHANGE_MEDIUM               Equ     CTL_CODE(IOCTL_CHANGER_BASE, 0008H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CHANGER_MOVE_MEDIUM                   Equ     CTL_CODE(IOCTL_CHANGER_BASE, 0009H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CHANGER_REINITIALIZE_TRANSPORT        Equ     CTL_CODE(IOCTL_CHANGER_BASE, 000AH, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CHANGER_QUERY_VOLUME_TAGS             Equ     CTL_CODE(IOCTL_CHANGER_BASE, 000BH, METHOD_BUFFERED, FILE_READ_ACCESS Or FILE_WRITE_ACCESS)

MAX_VOLUME_ID_SIZE                          Equ     36
MAX_VOLUME_TEMPLATE_SIZE                    Equ     40

VENDOR_ID_LENGTH                            Equ     8
PRODUCT_ID_LENGTH                           Equ     16
REVISION_LENGTH                             Equ     4
SERIAL_NUMBER_LENGTH                        Equ     32

;ELEMENT_TYPE Enumeration
ELEMENT_TYPE                                TypeDef DWord
AllElements                                 Equ     0
ChangerTransport                            Equ     1
ChangerSlot                                 Equ     2
ChangerIEPort                               Equ     3
ChangerDrive                                Equ     4
ChangerDoor                                 Equ     5
ChangerKeypad                               Equ     6
ChangerMaxElement                           Equ     7

CHANGER_ELEMENT Struct
    ElementType                             DD      ?
    ElementAddress                          DD      ?
CHANGER_ELEMENT EndS

CHANGER_ELEMENT_LIST Struct
    Element                                 CHANGER_ELEMENT <>
    NumberOfElements                        DD      ?
CHANGER_ELEMENT_LIST EndS

CHANGER_BAR_CODE_SCANNER_INSTALLED          Equ     000000001H
CHANGER_INIT_ELEM_STAT_WITH_RANGE           Equ     000000002H
CHANGER_CLOSE_IEPORT                        Equ     000000004H
CHANGER_OPEN_IEPORT                         Equ     000000008H

CHANGER_STATUS_NON_VOLATILE                 Equ     000000010H
CHANGER_EXCHANGE_MEDIA                      Equ     000000020H
CHANGER_CLEANER_SLOT                        Equ     000000040H
CHANGER_LOCK_UNLOCK                         Equ     000000080H

CHANGER_CARTRIDGE_MAGAZINE                  Equ     000000100H
CHANGER_MEDIUM_FLIP                         Equ     000000200H
CHANGER_POSITION_TO_ELEMENT                 Equ     000000400H
CHANGER_REPORT_IEPORT_STATE                 Equ     000000800H

CHANGER_STORAGE_DRIVE                       Equ     000001000H
CHANGER_STORAGE_IEPORT                      Equ     000002000H
CHANGER_STORAGE_SLOT                        Equ     000004000H
CHANGER_STORAGE_TRANSPORT                   Equ     000008000H

CHANGER_DRIVE_CLEANING_REQUIRED             Equ     000010000H
CHANGER_PREDISMOUNT_EJECT_REQUIRED          Equ     000020000H
CHANGER_CLEANER_EJECT_REQUIRED              Equ     000040000H
CHANGER_PREMOUNT_EJECT_REQUIRED             Equ     000080000H

CHANGER_VOLUME_IDENTIFICATION               Equ     000100000H
CHANGER_VOLUME_SEARCH                       Equ     000200000H
CHANGER_VOLUME_ASSERT                       Equ     000400000H
CHANGER_VOLUME_REPLACE                      Equ     000800000H
CHANGER_VOLUME_UNDEFINE                     Equ     001000000H

CHANGER_SERIAL_NUMBER_VALID                 Equ     004000000H

CHANGER_DEVICE_REINITIALIZE_CAPABLE         Equ     008000000H
CHANGER_KEYPAD_ENABLE_DISABLE               Equ     010000000H
CHANGER_DRIVE_EMPTY_ON_DOOR_ACCESS          Equ     020000000H
CHANGER_PREDISMOUNT_ALIGN_DRIVE_TO_SLOT     Equ     040000000H

IFNDEF CHANGER_CLEANER_AUTODISMOUNT
    CHANGER_CLEANER_AUTODISMOUNT            Equ     080000004H
ENDIF

CHANGER_TO_TRANSPORT                        Equ     001H
CHANGER_TO_SLOT                             Equ     002H
CHANGER_TO_IEPORT                           Equ     004H
CHANGER_TO_DRIVE                            Equ     008H

GET_CHANGER_PARAMETERS Struct
    _Size                                   DD      ?
    NumberTransportElements                 DW      ?
    NumberStorageElements                   DW      ?
    NumberCleanerSlots                      DW      ?
    NumberIEElements                        DW      ?
    NumberDataTransferElements              DW      ?
    NumberOfDoors                           DW      ?
    FirstSlotNumber                         DW      ?
    FirstDriveNumber                        DW      ?
    FirstTransportNumber                    DW      ?
    FirstIEPortNumber                       DW      ?
    FirstCleanerSlotAddress                 DW      ?
    MagazineSize                            DW      ?
    DriveCleanTimeout                       DD      ?
    Features0                               DD      ?
    Features1                               DD      ?
    MoveFromTransport                       DB      ?
    MoveFromSlot                            DB      ?
    MoveFromIePort                          DB      ?
    MoveFromDrive                           DB      ?
    ExchangeFromTransport                   DB      ?
    ExchangeFromSlot                        DB      ?
    ExchangeFromIePort                      DB      ?
    ExchangeFromDrive                       DB      ?
    LockUnlockCapabilities                  DB      ?
    PositionCapabilities                    DB      ?
    Reserved1                               DB      2 Dup(?)
    Reserved2                               DD      2 Dup(?)
GET_CHANGER_PARAMETERS EndS

CHANGER_PRODUCT_DATA Struct
    VendorId                                DB      VENDOR_ID_LENGTH Dup(?)
    ProductId                               DB      PRODUCT_ID_LENGTH Dup(?)
    Revision                                DB      REVISION_LENGTH  Dup(?)
    SerialNumber                            DB      SERIAL_NUMBER_LENGTH Dup(?)
    DeviceType                              DB      ?
CHANGER_PRODUCT_DATA EndS

LOCK_ELEMENT                                Equ     0
UNLOCK_ELEMENT                              Equ     1
EXTEND_IEPORT                               Equ     2
RETRACT_IEPORT                              Equ     3

CHANGER_SET_ACCESS Struct
    Element                                 CHANGER_ELEMENT <>
    Control                                 DD      ?
CHANGER_SET_ACCESS EndS

CHANGER_READ_ELEMENT_STATUS Struct
    ElementList                             CHANGER_ELEMENT_LIST    <>
    VolumeTagInfo                           DD      ?
CHANGER_READ_ELEMENT_STATUS EndS

CHANGER_ELEMENT_STATUS Struct
    Element                                 CHANGER_ELEMENT <>
    SrcElementAddress                       CHANGER_ELEMENT <>
    Flags                                   DD      ?
    ExceptionCode                           DD      ?
    TargetId                                DB      ?
    Lun                                     DB      ?
    Reserved                                DW      ?
    PrimaryVolumeID                         DB      MAX_VOLUME_ID_SIZE Dup(?)
    AlternateVolumeID                       DB      MAX_VOLUME_ID_SIZE Dup(?)
CHANGER_ELEMENT_STATUS EndS

ELEMENT_STATUS_FULL                         Equ     000000001H
ELEMENT_STATUS_IMPEXP                       Equ     000000002H
ELEMENT_STATUS_EXCEPT                       Equ     000000004H
ELEMENT_STATUS_ACCESS                       Equ     000000008H
ELEMENT_STATUS_EXENAB                       Equ     000000010H
ELEMENT_STATUS_INENAB                       Equ     000000020H

ELEMENT_STATUS_LUN_VALID                    Equ     000001000H
ELEMENT_STATUS_ID_VALID                     Equ     000002000H
ELEMENT_STATUS_NOT_BUS                      Equ     000008000H
ELEMENT_STATUS_INVERT                       Equ     000400000H
ELEMENT_STATUS_SVALID                       Equ     000800000H

ELEMENT_STATUS_PVOLTAG                      Equ     010000000H
ELEMENT_STATUS_AVOLTAG                      Equ     020000000H

ERROR_LABEL_UNREADABLE                      Equ     000000001H
ERROR_LABEL_QUESTIONABLE                    Equ     000000002H
ERROR_SLOT_NOT_PRESENT                      Equ     000000004H
ERROR_DRIVE_NOT_INSTALLED                   Equ     000000008H
ERROR_TRAY_MALFUNCTION                      Equ     000000010H
ERROR_INIT_STATUS_NEEDED                    Equ     000000011H
ERROR_UNHANDLED_ERROR                       Equ     0FFFFFFFFH

CHANGER_INITIALIZE_ELEMENT_STATUS Struct
    ElementList                             CHANGER_ELEMENT_LIST    <>
    BarCodeScan                             DD      ?
CHANGER_INITIALIZE_ELEMENT_STATUS EndS

CHANGER_SET_POSITION Struct
    Transport                               CHANGER_ELEMENT <>
    Destination                             CHANGER_ELEMENT <>
    Flip                                    DD      ?
CHANGER_SET_POSITION EndS

CHANGER_EXCHANGE_MEDIUM Struct
    Transport                               CHANGER_ELEMENT <>
    Source                                  CHANGER_ELEMENT <>
    Destination1                            CHANGER_ELEMENT <>
    Destination2                            CHANGER_ELEMENT <>
    Flip1                                   DD      ?
    Flip2                                   DD      ?
CHANGER_EXCHANGE_MEDIUM EndS

CHANGER_MOVE_MEDIUM Struct
    Transport                               CHANGER_ELEMENT <>
    Source                                  CHANGER_ELEMENT <>
    Destination                             CHANGER_ELEMENT <>
    Flip                                    DD      ?
CHANGER_MOVE_MEDIUM EndS

CHANGER_SEND_VOLUME_TAG_INFORMATION Struct
    StartingElement                         CHANGER_ELEMENT <>
    ActionCode                              DD      ?
    VolumeIDTemplate                        DB      MAX_VOLUME_TEMPLATE_SIZE Dup(?)
CHANGER_SEND_VOLUME_TAG_INFORMATION EndS

READ_ELEMENT_ADDRESS_INFO Struct
    NumberOfElements                        DD      ?
    ElementStatus                           CHANGER_ELEMENT_STATUS  <>
READ_ELEMENT_ADDRESS_INFO EndS

SEARCH_ALL                                  Equ     00H
SEARCH_PRIMARY                              Equ     01H
SEARCH_ALTERNATE                            Equ     02H
SEARCH_ALL_NO_SEQ                           Equ     04H
SEARCH_PRI_NO_SEQ                           Equ     05H
SEARCH_ALT_NO_SEQ                           Equ     06H

ASSERT_PRIMARY                              Equ     08H
ASSERT_ALTERNATE                            Equ     09H

REPLACE_PRIMARY                             Equ     0AH
REPLACE_ALTERANTE                           Equ     0BH

UNDEFINE_PRIMARY                            Equ     0CH
UNDEFINE_ALTERNATE                          Equ     0DH

IOCTL_SERIAL_LSRMST_INSERT                  Equ     CTL_CODE(FILE_DEVICE_SERIAL_PORT, 31, METHOD_BUFFERED, FILE_ANY_ACCESS)

SERIAL_LSRMST_ESCAPE                        Equ     000H
SERIAL_LSRMST_LSR_DATA                      Equ     001H
SERIAL_LSRMST_LSR_NODATA                    Equ     002H
SERIAL_LSRMST_MST                           Equ     003H

FSCTL_REQUEST_OPLOCK_LEVEL_1                Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 0, METHOD_BUFFERED, FILE_ANY_ACCESS)
FSCTL_REQUEST_OPLOCK_LEVEL_2                Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 1, METHOD_BUFFERED, FILE_ANY_ACCESS)
FSCTL_REQUEST_BATCH_OPLOCK                  Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 2, METHOD_BUFFERED, FILE_ANY_ACCESS)
FSCTL_OPLOCK_BREAK_ACKNOWLEDGE              Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 3, METHOD_BUFFERED, FILE_ANY_ACCESS)
FSCTL_OPBATCH_ACK_CLOSE_PENDING             Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 4, METHOD_BUFFERED, FILE_ANY_ACCESS)
FSCTL_OPLOCK_BREAK_NOTIFY                   Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 5, METHOD_BUFFERED, FILE_ANY_ACCESS)
FSCTL_LOCK_VOLUME                           Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 6, METHOD_BUFFERED, FILE_ANY_ACCESS)
FSCTL_UNLOCK_VOLUME                         Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 7, METHOD_BUFFERED, FILE_ANY_ACCESS)
FSCTL_DISMOUNT_VOLUME                       Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 8, METHOD_BUFFERED, FILE_ANY_ACCESS)
FSCTL_IS_VOLUME_MOUNTED                     Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 10, METHOD_BUFFERED, FILE_ANY_ACCESS)
FSCTL_IS_PATHNAME_VALID                     Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 11, METHOD_BUFFERED, FILE_ANY_ACCESS)
FSCTL_MARK_VOLUME_DIRTY                     Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 12, METHOD_BUFFERED, FILE_ANY_ACCESS)
FSCTL_QUERY_RETRIEVAL_POINTERS              Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 14, METHOD_NEITHER, FILE_ANY_ACCESS)
FSCTL_GET_COMPRESSION                       Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 15, METHOD_BUFFERED, FILE_ANY_ACCESS)
FSCTL_SET_COMPRESSION                       Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 16, METHOD_BUFFERED, FILE_READ_DATA Or FILE_WRITE_DATA)
FSCTL_MARK_AS_SYSTEM_HIVE                   Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 19, METHOD_NEITHER, FILE_ANY_ACCESS)
FSCTL_OPLOCK_BREAK_ACK_NO_2                 Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 20, METHOD_BUFFERED, FILE_ANY_ACCESS)
FSCTL_INVALIDATE_VOLUMES                    Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 21, METHOD_BUFFERED, FILE_ANY_ACCESS)
FSCTL_QUERY_FAT_BPB                         Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 22, METHOD_BUFFERED, FILE_ANY_ACCESS)
FSCTL_REQUEST_FILTER_OPLOCK                 Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 23, METHOD_BUFFERED, FILE_ANY_ACCESS)
FSCTL_FILESYSTEM_GET_STATISTICS             Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 24, METHOD_BUFFERED, FILE_ANY_ACCESS)
FSCTL_GET_NTFS_VOLUME_DATA                  Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 25, METHOD_BUFFERED, FILE_ANY_ACCESS)
FSCTL_GET_NTFS_FILE_RECORD                  Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 26, METHOD_BUFFERED, FILE_ANY_ACCESS)
FSCTL_GET_VOLUME_BITMAP                     Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 27, METHOD_NEITHER, FILE_ANY_ACCESS)
FSCTL_GET_RETRIEVAL_POINTERS                Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 28, METHOD_NEITHER, FILE_ANY_ACCESS)
FSCTL_MOVE_FILE                             Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 29, METHOD_BUFFERED, FILE_ANY_ACCESS)
FSCTL_IS_VOLUME_DIRTY                       Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 30, METHOD_BUFFERED, FILE_ANY_ACCESS)
FSCTL_GET_HFS_INFORMATION                   Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 31, METHOD_BUFFERED, FILE_ANY_ACCESS)
FSCTL_ALLOW_EXTENDED_DASD_IO                Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 32, METHOD_NEITHER,  FILE_ANY_ACCESS)

FSCTL_READ_PROPERTY_DATA                    Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 33, METHOD_NEITHER, FILE_ANY_ACCESS)
FSCTL_WRITE_PROPERTY_DATA                   Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 34, METHOD_NEITHER, FILE_ANY_ACCESS)
FSCTL_FIND_FILES_BY_SID                     Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 35, METHOD_NEITHER, FILE_ANY_ACCESS)
FSCTL_DUMP_PROPERTY_DATA                    Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 37, METHOD_NEITHER, FILE_ANY_ACCESS)
FSCTL_SET_OBJECT_ID                         Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 38, METHOD_BUFFERED, FILE_WRITE_DATA)
FSCTL_GET_OBJECT_ID                         Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 39, METHOD_BUFFERED, FILE_ANY_ACCESS)
FSCTL_DELETE_OBJECT_ID                      Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 40, METHOD_BUFFERED, FILE_WRITE_DATA)
FSCTL_SET_REPARSE_POINT                     Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 41, METHOD_BUFFERED, FILE_WRITE_DATA)
FSCTL_GET_REPARSE_POINT                     Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 42, METHOD_BUFFERED, FILE_ANY_ACCESS)
FSCTL_DELETE_REPARSE_POINT                  Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 43, METHOD_BUFFERED, FILE_WRITE_DATA)
FSCTL_ENUM_USN_DATA                         Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 44, METHOD_NEITHER, FILE_READ_DATA)
FSCTL_SECURITY_ID_CHECK                     Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 45, METHOD_NEITHER, FILE_READ_DATA)
FSCTL_READ_USN_JOURNAL                      Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 46, METHOD_NEITHER, FILE_READ_DATA)
FSCTL_SET_OBJECT_ID_EXTENDED                Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 47, METHOD_BUFFERED, FILE_WRITE_DATA)
FSCTL_CREATE_OR_GET_OBJECT_ID               Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 48, METHOD_BUFFERED, FILE_ANY_ACCESS)
FSCTL_SET_SPARSE                            Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 49, METHOD_BUFFERED, FILE_WRITE_DATA)
FSCTL_SET_ZERO_DATA                         Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 50, METHOD_BUFFERED, FILE_WRITE_DATA)
FSCTL_QUERY_ALLOCATED_RANGES                Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 51, METHOD_NEITHER, FILE_READ_DATA)
FSCTL_ENABLE_UPGRADE                        Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 52, METHOD_BUFFERED, FILE_WRITE_DATA)
FSCTL_SET_ENCRYPTION                        Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 53, METHOD_BUFFERED, FILE_ANY_ACCESS)
FSCTL_ENCRYPTION_FSCTL_IO                   Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 54, METHOD_NEITHER, FILE_ANY_ACCESS)
FSCTL_WRITE_RAW_ENCRYPTED                   Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 55, METHOD_NEITHER, FILE_ANY_ACCESS)
FSCTL_READ_RAW_ENCRYPTED                    Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 56, METHOD_NEITHER, FILE_ANY_ACCESS)
FSCTL_CREATE_USN_JOURNAL                    Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 57, METHOD_NEITHER, FILE_READ_DATA)
FSCTL_READ_FILE_USN_DATA                    Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 58, METHOD_NEITHER, FILE_READ_DATA)
FSCTL_WRITE_USN_CLOSE_RECORD                Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 59, METHOD_NEITHER, FILE_READ_DATA)
FSCTL_EXTEND_VOLUME                         Equ     CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 60, METHOD_BUFFERED, FILE_ANY_ACCESS)

PATHNAME_BUFFER Struct
    PathNameLength                          DD      ?
    _Name                                   DW      ?
PATHNAME_BUFFER EndS

FSCTL_QUERY_FAT_BPB_BUFFER Struct
    First0x24BytesOfBootSector              DB      024H Dup(?)
FSCTL_QUERY_FAT_BPB_BUFFER EndS

NTFS_VOLUME_DATA_BUFFER Struct
    VolumeSerialNumber                      LARGE_INTEGER   <>
    NumberSectors                           LARGE_INTEGER   <>
    TotalClusters                           LARGE_INTEGER   <>
    FreeClusters                            LARGE_INTEGER   <>
    TotalReserved                           LARGE_INTEGER   <>
    BytesPerSector                          DD      ?
    BytesPerCluster                         DD      ?
    BytesPerFileRecordSegment               DD      ?
    ClustersPerFileRecordSegment            DD      ?
    MftValidDataLength                      LARGE_INTEGER   <>
    MftStartLcn                             LARGE_INTEGER   <>
    Mft2StartLcn                            LARGE_INTEGER   <>
    MftZoneStart                            LARGE_INTEGER   <>
    MftZoneEnd                              LARGE_INTEGER   <>
NTFS_VOLUME_DATA_BUFFER EndS

STARTING_LCN_INPUT_BUFFER Struct
    StartingLcn                             LARGE_INTEGER   <>
STARTING_LCN_INPUT_BUFFER EndS

VOLUME_BITMAP_BUFFER Struct
    StartingLcn                             LARGE_INTEGER   <>
    BitmapSize                              LARGE_INTEGER   <>
    Buffer                                  DB      ?
VOLUME_BITMAP_BUFFER EndS

STARTING_VCN_INPUT_BUFFER Struct
    StartingVcn                             LARGE_INTEGER   <>
STARTING_VCN_INPUT_BUFFER EndS


_Extents Struct
    NextVcn                                 LARGE_INTEGER   <>
    Lcn                                     LARGE_INTEGER   <>
_Extents EndS

RETRIEVAL_POINTERS_BUFFER Struct
    ExtentCount                             DD      ?
    StartingVcn                             LARGE_INTEGER   <>
    Extents                                 _Extents    <>
RETRIEVAL_POINTERS_BUFFER EndS

NTFS_FILE_RECORD_INPUT_BUFFER Struct
    FileReferenceNumber                     LARGE_INTEGER   <>
NTFS_FILE_RECORD_INPUT_BUFFER EndS

NTFS_FILE_RECORD_OUTPUT_BUFFER Struct
    FileReferenceNumber                     LARGE_INTEGER   <>
    FileRecordLength                        DD      ?
    FileRecordBuffer                        DB      ?
NTFS_FILE_RECORD_OUTPUT_BUFFER EndS

MOVE_FILE_DATA Struct
    FileHandle                              DD      ?
    StartingVcn                             LARGE_INTEGER   <>
    StartingLcn                             LARGE_INTEGER   <>
    ClusterCount                            DD      ?
MOVE_FILE_DATA EndS

HFS_INFORMATION_BUFFER Struct
    FinderInfo                              DB      32 Dup(?)
HFS_INFORMATION_BUFFER EndS

MFT_ENUM_DATA Struct
    StartFileReferenceNumber                DQ      ?
    LowUsn                                  DQ      ?
    HighUsn                                 DQ      ?
MFT_ENUM_DATA EndS

FIND_BY_SID_DATA Struct
    Restart                                 DD      ?
    Sid                                     SID     <>
FIND_BY_SID_DATA EndS

CREATE_USN_JOURNAL_DATA Struct
    MaximumSize                             DQ      ?
    AllocationDelta                         DQ      ?
CREATE_USN_JOURNAL_DATA EndS

READ_USN_JOURNAL_DATA Struct
    StartUsn                                DQ      ?
    ReasonMask                              DD      ?
    ReturnOnlyOnClose                       DD      ?
    Timeout                                 DQ      ?
    BytesToWaitFor                          DQ      ?
    UsnJournalID                            DQ      ?
READ_USN_JOURNAL_DATA EndS

USN_RECORD Struct
    RecordLength                            DD      ?
    MajorVersion                            DW      ?
    MinorVersion                            DW      ?
    FileReferenceNumber                     DQ      ?
    ParentFileReferenceNumber               DQ      ?
    Usn                                     DQ      ?
    TimeStamp                               LARGE_INTEGER   <>
    Reason                                  DD      ?
    SourceInfo                              DD      ?
    SecurityId                              DD      ?
    FileAttributes                          DD      ?
    FileNameLength                          DQ      ?
    FileNameOffset                          DW      ?
    FileName                                DW      ?
USN_RECORD EndS

USN_PAGE_SIZE                               Equ     01000H

USN_REASON_DATA_OVERWRITE                   Equ     000000001H
USN_REASON_DATA_EXTEND                      Equ     000000002H
USN_REASON_DATA_TRUNCATION                  Equ     000000004H
USN_REASON_NAMED_DATA_OVERWRITE             Equ     000000010H
USN_REASON_NAMED_DATA_EXTEND                Equ     000000020H
USN_REASON_NAMED_DATA_TRUNCATION            Equ     000000040H
USN_REASON_FILE_CREATE                      Equ     000000100H
USN_REASON_FILE_DELETE                      Equ     000000200H
USN_REASON_PROPERTY_CHANGE                  Equ     000000400H
USN_REASON_SECURITY_CHANGE                  Equ     000000800H
USN_REASON_RENAME_OLD_NAME                  Equ     000001000H
USN_REASON_RENAME_NEW_NAME                  Equ     000002000H
USN_REASON_INDEXABLE_CHANGE                 Equ     000004000H
USN_REASON_BASIC_INFO_CHANGE                Equ     000008000H
USN_REASON_HARD_LINK_CHANGE                 Equ     000010000H
USN_REASON_COMPRESSION_CHANGE               Equ     000020000H
USN_REASON_ENCRYPTION_CHANGE                Equ     000040000H
USN_REASON_OBJECT_ID_CHANGE                 Equ     000080000H
USN_REASON_REPARSE_POINT_CHANGE             Equ     000100000H
USN_REASON_MOUNT_TABLE_CHANGE               Equ     000200000H

USN_REASON_CLOSE                            Equ     080000000H

BULK_SECURITY_TEST_DATA STRUCT
    DesiredAccess                           DD      ?
    SecurityIds                             DD      ?
BULK_SECURITY_TEST_DATA ENDS

VOLUME_IS_DIRTY                             Equ     000000001H
VOLUME_UPGRADE_SCHEDULED                    Equ     000000002H

_MftWritesUserLevel Struct
    Write                                   DW      ?
    Create                                  DW      ?
    SetInfo                                 DW      ?
    Flush                                   DW      ?
_MftWritesUserLevel EndS

_BitmapWritesUserLevel Struct
    Write                                   DW      ?
    Create                                  DW      ?
    SetInfo                                 DW      ?
_BitmapWritesUserLevel EndS

_Allocate Struct
    Calls                                   DD      ?
    Clusters                                DD      ?
    Hints                                   DD      ?
    RunsReturned                            DD      ?
    HintsHonored                            DD      ?
    HintsClusters                           DD      ?
    Cache                                   DD      ?
    CacheClusters                           DD      ?
    CacheMiss                               DD      ?
    CacheMissClusters                       DD      ?
_Allocate EndS

NTFS_STATISTICS Struct
    LogFileFullExceptions                   DD      ?
    OtherExceptions                         DD      ?
    MftReads                                DD      ?
    MftReadBytes                            DD      ?
    MftWrites                               DD      ?
    MftWriteBytes                           DD      ?
    MftWritesUserLevel                      _MftWritesUserLevel <>
    MftWritesFlushForLogFileFull            DW      ?
    MftWritesLazyWriter                     DW      ?
    MftWritesUserRequest                    DW      ?
    Mft2Writes                              DD      ?
    Mft2WriteBytes                          DD      ?
    Mft2WritesUserLevel                     _MftWritesUserLevel <>
    Mft2WritesFlushForLogFileFull           DW      ?
    Mft2WritesLazyWriter                    DW      ?
    Mft2WritesUserRequest                   DW      ?
    RootIndexReads                          DD      ?
    RootIndexReadBytes                      DD      ?
    RootIndexWrites                         DD      ?
    RootIndexWriteBytes                     DD      ?
    BitmapReads                             DD      ?
    BitmapReadBytes                         DD      ?
    BitmapWrites                            DD      ?
    BitmapWriteBytes                        DD      ?
    BitmapWritesFlushForLogFileFull         DW      ?
    BitmapWritesLazyWriter                  DW      ?
    BitmapWritesUserRequest                 DW      ?
    BitmapWritesUserLevel                   _BitmapWritesUserLevel  <>
    MftBitmapReads                          DD      ?
    MftBitmapReadBytes                      DD      ?
    MftBitmapWrites                         DD      ?
    MftBitmapWriteBytes                     DD      ?
    MftBitmapWritesFlushForLogFileFull      DW      ?
    MftBitmapWritesLazyWriter               DW      ?
    MftBitmapWritesUserRequest              DW      ?
    MftBitmapWritesUserLevel                _MftWritesUserLevel <>
    UserIndexReads                          DD      ?
    UserIndexReadBytes                      DD      ?
    UserIndexWrites                         DD      ?
    UserIndexWriteBytes                     DD      ?
    LogFileReads                            DD      ?
    LogFileReadBytes                        DD      ?
    LogFileWrites                           DD      ?
    LogFileWriteBytes                       DD      ?
    Allocate                                _Allocate   <>
NTFS_STATISTICS EndS

FAT_STATISTICS Struct
    CreateHits                              DD      ?
    SuccessfulCreates                       DD      ?
    FailedCreates                           DD      ?
    NonCachedReads                          DD      ?
    NonCachedReadBytes                      DD      ?
    NonCachedWrites                         DD      ?
    NonCachedWriteBytes                     DD      ?
    NonCachedDiskReads                      DD      ?
    NonCachedDiskWrites                     DD      ?
FAT_STATISTICS EndS

FILESYSTEM_STATISTICS_TYPE_NTFS             Equ     1
FILESYSTEM_STATISTICS_TYPE_FAT              Equ     2

FILESYSTEM_STATISTICS Struct
    _FileSystemType                         DW      ?   ;FileSystemType
    Version                                 DW      ?
    SizeOfCompleteStructure                 DD      ?
    UserFileReads                           DD      ?
    UserFileReadBytes                       DD      ?
    UserDiskReads                           DD      ?
    UserFileWrites                          DD      ?
    UserFileWriteBytes                      DD      ?
    UserDiskWrites                          DD      ?
    MetaDataReads                           DD      ?
    MetaDataReadBytes                       DD      ?
    MetaDataDiskReads                       DD      ?
    MetaDataWrites                          DD      ?
    MetaDataWriteBytes                      DD      ?
    MetaDataDiskWrites                      DD      ?
FILESYSTEM_STATISTICS EndS

_ExtendedInfo4union Struct
    BirthVolumeId                           DB      16 Dup(?)
    BirthObjectId                           DB      16 Dup(?)
    DomainId                                DB      16 Dup(?)
_ExtendedInfo4union EndS

FILE_OBJECTID_BUFFER Struct
    ObjectId                                DB      16 Dup(?)
    Union
        ExtendedInfostruct                  _ExtendedInfo4union <>
        ExtendedInfo                        DB      48 Dup(?)
    EndS
FILE_OBJECTID_BUFFER EndS

FILE_ZERO_DATA_INFORMATION Struct
    FileOffset                              LARGE_INTEGER   <>
    BeyondFinalZero                         LARGE_INTEGER   <>
FILE_ZERO_DATA_INFORMATION EndS

FILE_ALLOCATED_RANGE_BUFFER Struct
    FileOffset                              LARGE_INTEGER   <>
    _Length                                 LARGE_INTEGER   <>
FILE_ALLOCATED_RANGE_BUFFER EndS

ENCRYPTION_BUFFER Struct
    EncryptionOperation                     DD      ?
    _Private                                DB      ?   ;Private
ENCRYPTION_BUFFER EndS

FILE_SET_ENCRYPTION                         Equ     000000001H
FILE_CLEAR_ENCRYPTION                       Equ     000000002H
STREAM_SET_ENCRYPTION                       Equ     000000003H
STREAM_CLEAR_ENCRYPTION                     Equ     000000004H

MAXIMUM_ENCRYPTION_VALUE                    Equ     000000004H

INFO_NO_ENCRYPTED_STREAMS                   Equ     01H

ENCRYPTION_FORMAT_DEFAULT                   Equ     001H

COMPRESSION_FORMAT_SPARSE                   Equ     04000H

REQUEST_RAW_ENCRYPTED_DATA Struct
    FileOffset                              DQ      ?
    _Length                                 DD      ?
REQUEST_RAW_ENCRYPTED_DATA EndS

ENCRYPTED_DATA_INFO Struct
    StartingFileOffset                      DQ      ?
    OutputBufferOffset                      DD      ?
    BytesWithinFileSize                     DD      ?
    BytesWithinValidDataLength              DD      ?
    CompressionFormat                       DW      ?
    DataUnitShift                           DB      ?
    ChunkShift                              DB      ?
    ClusterShift                            DB      ?
    EncryptionFormat                        DB      ?
    NumberOfDataBlocks                      DW      ?
    DataBlockSize                           DD      ?
ENCRYPTED_DATA_INFO EndS

ENDIF ;WINIOCTL_INC

  
