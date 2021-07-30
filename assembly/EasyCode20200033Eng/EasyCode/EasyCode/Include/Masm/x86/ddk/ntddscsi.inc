;===================================================================;
;                                                                   ;
;  ntddscsi.inc for Easy Code 2.0 JWasm/Masm/PoAsm 32-bit drivers   ;
;                        (version 1.0.0)                            ;
;                                                                   ;
;                 Driver Development Kit (32-bit)                   ;
;                                                                   ;
;                  Copyright © Ramon Sala - 2015                    ;
;                                                                   ;
;===================================================================;

IFNDEF NTDDSCSI_INC
NTDDSCSI_INC Equ 1

IFNDEF MACRODRV_INC
    Include macrodrv.inc
ENDIF

IFNDEF WTYPES_INC
    Include wtypes.inc
ENDIF

IOCTL_SCSI_BASE                             Equ     FILE_DEVICE_CONTROLLER
FILE_DEVICE_SCSI                            Equ     00000001BH

DD_SCSI_DEVICE_NAME                         Equ     A("\Device\ScsiPort")

IOCTL_SCSI_PASS_THROUGH                     Equ     CTL_CODE(IOCTL_SCSI_BASE, 00401H, METHOD_BUFFERED, FILE_READ_ACCESS Or FILE_WRITE_ACCESS)
IOCTL_SCSI_MINIPORT                         Equ     CTL_CODE(IOCTL_SCSI_BASE, 00402H, METHOD_BUFFERED, FILE_READ_ACCESS Or FILE_WRITE_ACCESS)
IOCTL_SCSI_GET_INQUIRY_DATA                 Equ     CTL_CODE(IOCTL_SCSI_BASE, 00403H, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SCSI_GET_CAPABILITIES                 Equ     CTL_CODE(IOCTL_SCSI_BASE, 00404H, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SCSI_PASS_THROUGH_DIRECT              Equ     CTL_CODE(IOCTL_SCSI_BASE, 00405H, METHOD_BUFFERED, FILE_READ_ACCESS Or FILE_WRITE_ACCESS)
IOCTL_SCSI_GET_ADDRESS                      Equ     CTL_CODE(IOCTL_SCSI_BASE, 00406H, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SCSI_RESCAN_BUS                       Equ     CTL_CODE(IOCTL_SCSI_BASE, 00407H, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SCSI_GET_DUMP_POINTERS                Equ     CTL_CODE(IOCTL_SCSI_BASE, 00408H, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_SCSI_FREE_DUMP_POINTERS               Equ     CTL_CODE(IOCTL_SCSI_BASE, 00409H, METHOD_BUFFERED, FILE_ANY_ACCESS)
IOCTL_IDE_PASS_THROUGH                      Equ     CTL_CODE(IOCTL_SCSI_BASE, 0040AH, METHOD_BUFFERED, FILE_READ_ACCESS Or FILE_WRITE_ACCESS)
IOCTL_ATA_PASS_THROUGH                      Equ     CTL_CODE(IOCTL_SCSI_BASE, 0040BH, METHOD_BUFFERED, FILE_READ_ACCESS Or FILE_WRITE_ACCESS)
IOCTL_ATA_PASS_THROUGH_DIRECT               Equ     CTL_CODE(IOCTL_SCSI_BASE, 0040CH, METHOD_BUFFERED, FILE_READ_ACCESS Or FILE_WRITE_ACCESS)
IOCTL_ATA_MINIPORT                          Equ     CTL_CODE(IOCTL_SCSI_BASE, 0040DH, METHOD_BUFFERED, FILE_READ_ACCESS Or FILE_WRITE_ACCESS)
IOCTL_MINIPORT_PROCESS_SERVICE_IRP          Equ     CTL_CODE(IOCTL_SCSI_BASE, 0040EH, METHOD_BUFFERED, FILE_READ_ACCESS Or FILE_WRITE_ACCESS)
IOCTL_MPIO_PASS_THROUGH_PATH                Equ     CTL_CODE(IOCTL_SCSI_BASE, 0040FH, METHOD_BUFFERED, FILE_READ_ACCESS Or FILE_WRITE_ACCESS)
IOCTL_MPIO_PASS_THROUGH_PATH_DIRECT         Equ     CTL_CODE(IOCTL_SCSI_BASE, 00410H, METHOD_BUFFERED, FILE_READ_ACCESS Or FILE_WRITE_ACCESS)

IOCTL_SCSI_MINIPORT_NVCACHE                 Equ     ((FILE_DEVICE_SCSI Shl 16) + 0600H)

SCSI_PASS_THROUGH Struct
    _Length                                 DW      ?   ;Length
    ScsiStatus                              DB      ?
    PathId                                  DB      ?
    TargetId                                DB      ?
    Lun                                     DB      ?
    CdbLength                               DB      ?
    SenseInfoLength                         DB      ?
    DataIn                                  DB      ?
    DataTransferLength                      DD      ?
    TimeOutValue                            DD      ?
    DataBufferOffset                        DD      ?
    SenseInfoOffset                         DD      ?
    Cdb                                     DB      16 Dup(?)
SCSI_PASS_THROUGH EndS
PSCSI_PASS_THROUGH                          TypeDef DWord

SCSI_PASS_THROUGH_DIRECT Struct
    _Length                                 DW      ?   ;Length
    ScsiStatus                              DB      ?
    PathId                                  DB      ?
    TargetId                                DB      ?
    Lun                                     DB      ?
    CdbLength                               DB      ?
    SenseInfoLength                         DB      ?
    DataIn                                  DB      ?
    DataTransferLength                      DD      ?
    TimeOutValue                            DD      ?
    DataBuffer                              PVOID   ?
    SenseInfoOffset                         DD      ?
    Cdb                                     DB      16 Dup(?)
SCSI_PASS_THROUGH_DIRECT EndS
PSCSI_PASS_THROUGH_DIRECT                   TypeDef DWord

SCSI_PASS_THROUGH_DIRECT32 Struct
    _Length                                 DW      ?   ;Length
    ScsiStatus                              DB      ?
    PathId                                  DB      ?
    TargetId                                DB      ?
    Lun                                     DB      ?
    CdbLength                               DB      ?
    SenseInfoLength                         DB      ?
    DataIn                                  DB      ?
    DataTransferLength                      DD      ?
    TimeOutValue                            DD      ?
    DataBuffer                              PVOID   ?
    SenseInfoOffset                         DD      ?
    Cdb                                     DB      16 Dup(?)
SCSI_PASS_THROUGH_DIRECT32 EndS
PSCSI_PASS_THROUGH_DIRECT32                 TypeDef DWord

ATA_PASS_THROUGH_EX Struct
    _Length                                 DW      ?   ;Length
    AtaFlags                                DW      ?
    PathId                                  DB      ?
    TargetId                                DB      ?
    Lun                                     DB      ?
    ReservedAsUchar                         DB      ?
    DataTransferLength                      DD      ?
    TimeOutValue                            DD      ?
    ReservedAsUlong                         DD      ?
    DataBufferOffset                        DD      ?
    PreviousTaskFile                        DB      8 Dup(?)
    CurrentTaskFile                         DB      8 Dup(?)
ATA_PASS_THROUGH_EX EndS
PATA_PASS_THROUGH_EX                        TypeDef DWord

ATA_PASS_THROUGH_DIRECT Struct
    _Length                                 DW      ?   ;Length
    AtaFlags                                DW      ?
    PathId                                  DB      ?
    TargetId                                DB      ?
    Lun                                     DB      ?
    ReservedAsUchar                         DB      ?
    DataTransferLength                      DD      ?
    TimeOutValue                            DD      ?
    ReservedAsUlong                         DD      ?
    DataBuffer                              PVOID   ?
    PreviousTaskFile                        DB      8 Dup(?)
    CurrentTaskFile                         DB      8 Dup(?)
ATA_PASS_THROUGH_DIRECT EndS
PATA_PASS_THROUGH_DIRECT                    TypeDef DWord

ATA_PASS_THROUGH_DIRECT32 Struct
    _Length                                 DW      ?   ;Length
    AtaFlags                                DW      ?
    PathId                                  DB      ?
    TargetId                                DB      ?
    Lun                                     DB      ?
    ReservedAsUchar                         DB      ?
    DataTransferLength                      DD      ?
    TimeOutValue                            DD      ?
    ReservedAsUlong                         DD      ?
    DataBuffer                              PVOID   ?
    PreviousTaskFile                        DB      8 Dup(?)
    CurrentTaskFile                         DB      8 Dup(?)
ATA_PASS_THROUGH_DIRECT32 EndS
PATA_PASS_THROUGH_DIRECT32                  TypeDef DWord

ATA_FLAGS_DRDY_REQUIRED                     Equ     (1 Shl 0)
ATA_FLAGS_DATA_IN                           Equ     (1 Shl 1)
ATA_FLAGS_DATA_OUT                          Equ     (1 Shl 2)
ATA_FLAGS_48BIT_COMMAND                     Equ     (1 Shl 3)
ATA_FLAGS_USE_DMA                           Equ     (1 Shl 4)
ATA_FLAGS_NO_MULTIPLE                       Equ     (1 Shl 5)

IDE_IO_CONTROL Struct
    HeaderLength                            DD      ?
    Signature                               DB      8 Dup(?)
    Timeout                                 DD      ?
    ControlCode                             DD      ?
    ReturnStatus                            DD      ?
    DataLength                              DD      ?
IDE_IO_CONTROL EndS
PIDE_IO_CONTROL                             TypeDef DWord

MPIO_PASS_THROUGH_PATH Struct
    PassThrough                             SCSI_PASS_THROUGH <>
    Version                                 DD      ?
    _Length                                 DW      ?   ;Length
    Flags                                   DB      ?
    PortNumber                              DB      ?
    MpioPathId                              DQ      ?
MPIO_PASS_THROUGH_PATH EndS
PMPIO_PASS_THROUGH_PATH                     TypeDef DWord

MPIO_PASS_THROUGH_PATH_DIRECT Struct
    PassThrough                             SCSI_PASS_THROUGH_DIRECT    <>
    Version                                 DD      ?
    _Length                                 DW      ?   ;Length
    Flags                                   DB      ?
    PortNumber                              DB      ?
    MpioPathId                              DQ      ?
MPIO_PASS_THROUGH_PATH_DIRECT EndS
PMPIO_PASS_THROUGH_PATH_DIRECT              TypeDef DWord

SCSI_BUS_DATA Struct
    NumberOfLogicalUnits                    DB      ?
    InitiatorBusId                          DB      ?
    InquiryDataOffset                       DD      ?
SCSI_BUS_DATA EndS
PSCSI_BUS_DATA                              TypeDef DWord

SCSI_ADAPTER_BUS_INFO Struct
    NumberOfBuses                           DB      ?
    BusData                                 SCSI_BUS_DATA   1 Dup(<>)
SCSI_ADAPTER_BUS_INFO EndS
PSCSI_ADAPTER_BUS_INFO                      TypeDef DWord

SCSI_INQUIRY_DATA Struct
    PathId                                  DB      ?
    TargetId                                DB      ?
    Lun                                     DB      ?
    DeviceClaimed                           BOOLEAN ?
    InquiryDataLength                       DD      ?
    NextInquiryDataOffset                   DD      ?
    InquiryData                             DB      1 Dup(?)
SCSI_INQUIRY_DATA EndS
PSCSI_INQUIRY_DATA                          TypeDef DWord

SRB_IO_CONTROL Struct
    HeaderLength                            DD      ?
    Signature                               DB      8 Dup(?)
    Timeout                                 DD      ?
    ControlCode                             DD      ?
    ReturnCode                              DD      ?
    _Length                                 DD      ?   ;Length
SRB_IO_CONTROL EndS
PSRB_IO_CONTROL                             TypeDef DWord

NVCACHE_REQUEST_BLOCK Struct
    NRBSize                                 DD      ?
    Function                                DW      ?
    NRBFlags                                DD      ?
    NRBStatus                               DD      ?
    Count                                   DD      ?
    LBA                                     DQ      ?
    DataBufSize                             DD      ?
    NVCacheStatus                           DD      ?
    NVCacheSubStatus                        DD      ?
NVCACHE_REQUEST_BLOCK EndS
PNVCACHE_REQUEST_BLOCK                      TypeDef DWord

NRB_FUNCTION_NVCACHE_INFO                   Equ     0ECH
NRB_FUNCTION_SPINDLE_STATUS                 Equ     0E5H
NRB_FUNCTION_NVCACHE_POWER_MODE_SET         Equ     000H
NRB_FUNCTION_NVCACHE_POWER_MODE_RETURN      Equ     001H
NRB_FUNCTION_FLUSH_NVCACHE                  Equ     014H
NRB_FUNCTION_QUERY_PINNED_SET               Equ     012H
NRB_FUNCTION_QUERY_CACHE_MISS               Equ     013H
NRB_FUNCTION_ADD_LBAS_PINNED_SET            Equ     010H
NRB_FUNCTION_REMOVE_LBAS_PINNED_SET         Equ     011H
NRB_FUNCTION_QUERY_ASCENDER_STATUS          Equ     0D0H
NRB_FUNCTION_QUERY_HYBRID_DISK_STATUS       Equ     0D1H

NRB_SUCCESS                                 Equ     0
NRB_ILLEGAL_REQUEST                         Equ     1
NRB_INVALID_PARAMETER                       Equ     2
NRB_INPUT_DATA_OVERRUN                      Equ     3
NRB_INPUT_DATA_UNDERRUN                     Equ     4
NRB_OUTPUT_DATA_OVERRUN                     Equ     5
NRB_OUTPUT_DATA_UNDERRUN                    Equ     6

NV_FEATURE_PARAMETER Struct
    NVPowerModeEnabled                      DW      ?
    NVParameterReserv1                      DW      ?
    NVCmdEnabled                            DW      ?
    NVParameterReserv2                      DW      ?
    NVPowerModeVer                          DW      ?
    NVCmdVer                                DW      ?
    NVSize                                  DD      ?
    NVReadSpeed                             DW      ?
    NVWrtSpeed                              DW      ?
    DeviceSpinUpTime                        DD      ?
NV_FEATURE_PARAMETER EndS
PNV_FEATURE_PARAMETER                       TypeDef DWord

IO_SCSI_CAPABILITIES Struct
    _Length                                 DD      ?   ;Length
    MaximumTransferLength                   DD      ?
    MaximumPhysicalPages                    DD      ?
    SupportedAsynchronousEvents             DD      ?
    AlignmentMask                           DD      ?
    TaggedQueuing                           BOOLEAN ?
    AdapterScansDown                        BOOLEAN ?
    AdapterUsesPio                          BOOLEAN ?
                                            DB      ?
IO_SCSI_CAPABILITIES EndS
PIO_SCSI_CAPABILITIES                       TypeDef DWord

SCSI_ADDRESS Struct
    _Length                                 DD      ?   ;Length
    PortNumber                              DB      ?
    PathId                                  DB      ?
    TargetId                                DB      ?
    Lun                                     DB      ?
SCSI_ADDRESS EndS
PSCSI_ADDRESS                               TypeDef DWord

DUMP_POINTERS_VERSION_1                     Equ     1
DUMP_POINTERS_VERSION_2                     Equ     2
DUMP_DRIVER_NAME_LENGTH                     Equ     15

DUMP_POINTERS_VERSION Struct
    Version                                 DD      ?
    _Size                                   DD      ?
DUMP_POINTERS_VERSION EndS
PDUMP_POINTERS_VERSION                      TypeDef DWord

DUMP_DRIVER Struct
    DumpDriverList                          PVOID   ?
    DriverName                              DW      DUMP_DRIVER_NAME_LENGTH Dup(?)
    BaseName                                DW      DUMP_DRIVER_NAME_LENGTH Dup(?)
DUMP_DRIVER EndS
PDUMP_DRIVER                                TypeDef DWord

SCSI_IOCTL_DATA_OUT                         Equ     0
SCSI_IOCTL_DATA_IN                          Equ     1
SCSI_IOCTL_DATA_UNSPECIFIED                 Equ     2

MPIO_IOCTL_FLAG_USE_PATHID                  Equ     1
MPIO_IOCTL_FLAG_USE_SCSIADDRESS             Equ     2
MPIO_IOCTL_FLAG_INVOLVE_DSM                 Equ     4

ENDIF ;NTDDSCSI_INC
