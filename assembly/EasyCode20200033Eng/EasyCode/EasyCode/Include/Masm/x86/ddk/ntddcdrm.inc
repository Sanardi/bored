;===================================================================;
;                                                                   ;
;  ntddcdrm.inc for Easy Code 2.0 JWasm/Masm/PoAsm 32-bit drivers   ;
;                        (version 1.0.0)                            ;
;                                                                   ;
;                 Driver Development Kit (32-bit)                   ;
;                                                                   ;
;                  Copyright © Ramon Sala - 2015                    ;
;                                                                   ;
;===================================================================;

IFNDEF NTDDCDRM_INC
NTDDCDRM_INC Equ 1

IFNDEF MACRODRV_INC
    Include macrodrv.inc
ENDIF

IOCTL_CDROM_BASE                                            Equ         FILE_DEVICE_CD_ROM

IOCTL_CDROM_UNLOAD_DRIVER                                   Equ         CTL_CODE(IOCTL_CDROM_BASE, 0402H, METHOD_BUFFERED, FILE_READ_ACCESS)

IOCTL_CDROM_READ_TOC                                        Equ         CTL_CODE(IOCTL_CDROM_BASE, 0000H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CDROM_SEEK_AUDIO_MSF                                  Equ         CTL_CODE(IOCTL_CDROM_BASE, 0001H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CDROM_STOP_AUDIO                                      Equ         CTL_CODE(IOCTL_CDROM_BASE, 0002H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CDROM_PAUSE_AUDIO                                     Equ         CTL_CODE(IOCTL_CDROM_BASE, 0003H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CDROM_RESUME_AUDIO                                    Equ         CTL_CODE(IOCTL_CDROM_BASE, 0004H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CDROM_GET_VOLUME                                      Equ         CTL_CODE(IOCTL_CDROM_BASE, 0005H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CDROM_PLAY_AUDIO_MSF                                  Equ         CTL_CODE(IOCTL_CDROM_BASE, 0006H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CDROM_SET_VOLUME                                      Equ         CTL_CODE(IOCTL_CDROM_BASE, 000AH, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CDROM_READ_Q_CHANNEL                                  Equ         CTL_CODE(IOCTL_CDROM_BASE, 000BH, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CDROM_GET_CONTROL                                     Equ         CTL_CODE(IOCTL_CDROM_BASE, 000DH, METHOD_BUFFERED, FILE_READ_ACCESS)
OBSOLETE_IOCTL_CDROM_GET_CONTROL                            Equ         CTL_CODE(IOCTL_CDROM_BASE, 000DH, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CDROM_GET_LAST_SESSION                                Equ         CTL_CODE(IOCTL_CDROM_BASE, 000EH, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CDROM_RAW_READ                                        Equ         CTL_CODE(IOCTL_CDROM_BASE, 000FH, METHOD_OUT_DIRECT, FILE_READ_ACCESS)
IOCTL_CDROM_DISK_TYPE                                       Equ         CTL_CODE(IOCTL_CDROM_BASE, 0010H, METHOD_BUFFERED, FILE_ANY_ACCESS)

IOCTL_CDROM_GET_DRIVE_GEOMETRY                              Equ         CTL_CODE(IOCTL_CDROM_BASE, 0013H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CDROM_GET_DRIVE_GEOMETRY_EX                           Equ         CTL_CODE(IOCTL_CDROM_BASE, 0014H, METHOD_BUFFERED, FILE_READ_ACCESS)

IOCTL_CDROM_READ_TOC_EX                                     Equ         CTL_CODE(IOCTL_CDROM_BASE, 0015H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CDROM_GET_CONFIGURATION                               Equ         CTL_CODE(IOCTL_CDROM_BASE, 0016H, METHOD_BUFFERED, FILE_READ_ACCESS)

IOCTL_CDROM_EXCLUSIVE_ACCESS                                Equ         CTL_CODE(IOCTL_CDROM_BASE, 0017H, METHOD_BUFFERED, FILE_READ_ACCESS Or FILE_WRITE_ACCESS)
IOCTL_CDROM_SET_SPEED                                       Equ         CTL_CODE(IOCTL_CDROM_BASE, 0018H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CDROM_GET_INQUIRY_DATA                                Equ         CTL_CODE(IOCTL_CDROM_BASE, 0019H, METHOD_BUFFERED, FILE_READ_ACCESS)

IOCTL_CDROM_ENABLE_STREAMING                                Equ         CTL_CODE(IOCTL_CDROM_BASE, 001AH, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CDROM_SEND_OPC_INFORMATION                            Equ         CTL_CODE(IOCTL_CDROM_BASE, 001BH, METHOD_BUFFERED, FILE_READ_ACCESS Or FILE_WRITE_ACCESS)
IOCTL_CDROM_GET_PERFORMANCE                                 Equ         CTL_CODE(IOCTL_CDROM_BASE, 001CH, METHOD_BUFFERED, FILE_READ_ACCESS)

IOCTL_CDROM_CHECK_VERIFY                                    Equ         CTL_CODE(IOCTL_CDROM_BASE, 0200H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CDROM_MEDIA_REMOVAL                                   Equ         CTL_CODE(IOCTL_CDROM_BASE, 0201H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CDROM_EJECT_MEDIA                                     Equ         CTL_CODE(IOCTL_CDROM_BASE, 0202H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CDROM_LOAD_MEDIA                                      Equ         CTL_CODE(IOCTL_CDROM_BASE, 0203H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CDROM_RESERVE                                         Equ         CTL_CODE(IOCTL_CDROM_BASE, 0204H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CDROM_RELEASE                                         Equ         CTL_CODE(IOCTL_CDROM_BASE, 0205H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CDROM_FIND_NEW_DEVICES                                Equ         CTL_CODE(IOCTL_CDROM_BASE, 0206H, METHOD_BUFFERED, FILE_READ_ACCESS)

IFNDEF NTDDSTOR_INC
    Include ntddstor.inc
ENDIF


MINIMUM_CDROM_INQUIRY_SIZE                                  Equ         36
MAXIMUM_CDROM_INQUIRY_SIZE                                  Equ         260

IOCTL_CDROM_SIMBAD                                          Equ         CTL_CODE(IOCTL_CDROM_BASE, 1003H, METHOD_BUFFERED, FILE_READ_ACCESS)

MAXIMUM_NUMBER_TRACKS                                       Equ         100
MAXIMUM_CDROM_SIZE                                          Equ         804
MINIMUM_CDROM_READ_TOC_EX_SIZE                              Equ         2

CDROMREC Record                                             Format:4, Reserved1:3, Msf:1
CDROM_READ_TOC_EX Struct
    cdromrec                                                CDROMREC    <>
    SessionTrack                                            DB          ?
    Reserved2                                               DB          ?
    Reserved3                                               DB          ?
CDROM_READ_TOC_EX EndS
PCDROM_READ_TOC_EX                                          TypeDef     DWord

CDROM_READ_TOC_EX_FORMAT_TOC                                Equ         00H
CDROM_READ_TOC_EX_FORMAT_SESSION                            Equ         01H
CDROM_READ_TOC_EX_FORMAT_FULL_TOC                           Equ         02H
CDROM_READ_TOC_EX_FORMAT_PMA                                Equ         03H
CDROM_READ_TOC_EX_FORMAT_ATIP                               Equ         04H
CDROM_READ_TOC_EX_FORMAT_CDTEXT                             Equ         05H

TRACKREC Record                                             Control:4, _Adr:4
TRACK_DATA Struct
    Reserved                                                DB          ?
    trackrec                                                TRACKREC    <>
    TrackNumber                                             DB          ?
    Reserved1                                               DB          ?
    Address                                                 DB          4 Dup(?)
TRACK_DATA EndS
PTRACK_DATA                                                 TypeDef     DWord

CDROM_TOC Struct
    _Length                                                 DB          2 Dup(?)    ;Length
    FirstTrack                                              DB          ?
    LastTrack                                               DB          ?
    TrackData                                               TRACK_DATA  MAXIMUM_NUMBER_TRACKS Dup(<>)
CDROM_TOC EndS
PCDROM_TOC                                                  TypeDef     DWord

CDROM_TOC_SIZE                                              Equ         SizeOf CDROM_TOC

CDROM_TOC_SESSION_DATA Struct
    _Length                                                 DB          2 Dup(?)    ;Length
    FirstCompleteSession                                    DB          ?
    LastCompleteSession                                     DB          ?
    TrackData                                               TRACK_DATA  1 Dup(<>)
CDROM_TOC_SESSION_DATA EndS
PCDROM_TOC_SESSION_DATA                                     TypeDef     DWord

CDROM_TOC_FULL_TOC_DATA_BLOCK Struct
    SessionNumber                                           DB          ?
    trackrec                                                TRACKREC    <>
    Reserved1                                               DB          ?
    Point                                                   DB          ?
    MsfExtra                                                DB          3 Dup(?)
    Zero                                                    DB          ?
    Msf                                                     DB          3 Dup(?)
CDROM_TOC_FULL_TOC_DATA_BLOCK EndS
PCDROM_TOC_FULL_TOC_DATA_BLOCK                              TypeDef     DWord

CDROM_TOC_FULL_TOC_DATA Struct
    _Length                                                 DB          2 Dup(?)    ;Length
    FirstCompleteSession                                    DB          ?
    LastCompleteSession                                     DB          ?
    Descriptors                                             CDROM_TOC_FULL_TOC_DATA_BLOCK   0 Dup(<>)
CDROM_TOC_FULL_TOC_DATA EndS
PCDROM_TOC_FULL_TOC_DATA                                    TypeDef     DWord

CDROM_TOC_PMA_DATA sTRUCT
    _Length                                                 DB          2 Dup(?)    ;Length
    Reserved1                                               DB          ?
    Reserved2                                               DB          ?
    Descriptors                                             CDROM_TOC_FULL_TOC_DATA_BLOCK   0 Dup(<>)
CDROM_TOC_PMA_DATA EndS
PCDROM_TOC_PMA_DATA                                         TypeDef     DWord

CDROM_CD_TEXT_PACK_ALBUM_NAME                               Equ         80H
CDROM_CD_TEXT_PACK_PERFORMER                                Equ         81H
CDROM_CD_TEXT_PACK_SONGWRITER                               Equ         82H
CDROM_CD_TEXT_PACK_COMPOSER                                 Equ         83H
CDROM_CD_TEXT_PACK_ARRANGER                                 Equ         84H
CDROM_CD_TEXT_PACK_MESSAGES                                 Equ         85H
CDROM_CD_TEXT_PACK_DISC_ID                                  Equ         86H
CDROM_CD_TEXT_PACK_GENRE                                    Equ         87H
CDROM_CD_TEXT_PACK_TOC_INFO                                 Equ         88H
CDROM_CD_TEXT_PACK_TOC_INFO2                                Equ         89H
CDROM_CD_TEXT_PACK_UPC_EAN                                  Equ         8EH
CDROM_CD_TEXT_PACK_SIZE_INFO                                Equ         8FH

CDROM_PLAY_AUDIO_MSF Struct
    StartingM                                               DB          ?
    StartingS                                               DB          ?
    StartingF                                               DB          ?
    EndingM                                                 DB          ?
    EndingS                                                 DB          ?
    EndingF                                                 DB          ?
CDROM_PLAY_AUDIO_MSF EndS
PCDROM_PLAY_AUDIO_MSF                                       TypeDef     DWord

CDROM_SEEK_AUDIO_MSF Struct
    M                                                       DB          ?
    S                                                       DB          ?
    F                                                       DB          ?
CDROM_SEEK_AUDIO_MSF EndS
PCDROM_SEEK_AUDIO_MSF                                       TypeDef     DWord

CDROM_DISK_DATA Struct
    DiskData                                                DD          ?
CDROM_DISK_DATA EndS
PCDROM_DISK_DATA                                            TypeDef     DWord

CDROM_DISK_AUDIO_TRACK                                      Equ         (00000001H)
CDROM_DISK_DATA_TRACK                                       Equ         (00000002H)

IOCTL_CDROM_SUB_Q_CHANNEL                                   Equ         00H
IOCTL_CDROM_CURRENT_POSITION                                Equ         01H
IOCTL_CDROM_MEDIA_CATALOG                                   Equ         02H
IOCTL_CDROM_TRACK_ISRC                                      Equ         03H

CDROM_SUB_Q_DATA_FORMAT Struct
    Format                                                  DB          ?
    Track                                                   DB          ?
CDROM_SUB_Q_DATA_FORMAT EndS
PCDROM_SUB_Q_DATA_FORMAT                                    TypeDef     DWord

SUB_Q_HEADER Struct
    Reserved                                                DB          ?
    AudioStatus                                             DB          ?
    DataLength                                              DB          2 Dup(?)
SUB_Q_HEADER EndS
PSUB_Q_HEADER                                               TypeDef     DWord

SUB_Q_CURRENT_POSITION Struct
    Header                                                  SUB_Q_HEADER    <>
    FormatCode                                              DB          ?
    trackrec                                                TRACKREC    <>
    TrackNumber                                             DB          ?
    IndexNumber                                             DB          ?
    AbsoluteAddress                                         DB          4 Dup(?)
    TrackRelativeAddress                                    DB          4 Dup(?)
SUB_Q_CURRENT_POSITION EndS
PSUB_Q_CURRENT_POSITION                                     TypeDef     DWord

QMEDIAREC Record                                            reserved:7, Mcval:1
SUB_Q_MEDIA_CATALOG_NUMBER Struct
    Header                                                  SUB_Q_HEADER    <>
    FormatCode                                              DB          ?
    _Reserved                                               DB          3 Dup(?) ;Reserved
    qmediarec                                               QMEDIAREC   <>
    MediaCatalog                                            DB          15 Dup(?)
SUB_Q_MEDIA_CATALOG_NUMBER EndS
PSUB_Q_MEDIA_CATALOG_NUMBER                                 TypeDef     DWord

QTRACKREC Record                                            Reserved2:7, Tcval:1
SUB_Q_TRACK_ISRC Struct
    Header                                                  SUB_Q_HEADER    <>
    FormatCode                                              DB          ?
    Reserved0                                               DB          ?
    Track                                                   DB          ?
    Reserved1                                               DB          ?
    qtrackrec                                               QTRACKREC   <>
    TrackIsrc                                               DB          15 Dup(?)
SUB_Q_TRACK_ISRC EndS
PSUB_Q_TRACK_ISRC                                           TypeDef     DWord

SUB_Q_CHANNEL_DATA Struct
    CurrentPosition                                         SUB_Q_CURRENT_POSITION  <>
    MediaCatalog                                            SUB_Q_MEDIA_CATALOG_NUMBER  <>
    TrackIsrc                                               SUB_Q_TRACK_ISRC    <>
SUB_Q_CHANNEL_DATA EndS
PSUB_Q_CHANNEL_DATA                                         TypeDef     DWord

AUDIO_STATUS_NOT_SUPPORTED                                  Equ         00H
AUDIO_STATUS_IN_PROGRESS                                    Equ         11H
AUDIO_STATUS_PAUSED                                         Equ         12H
AUDIO_STATUS_PLAY_COMPLETE                                  Equ         13H
AUDIO_STATUS_PLAY_ERROR                                     Equ         14H
AUDIO_STATUS_NO_STATUS                                      Equ         15H

ADR_NO_MODE_INFORMATION                                     Equ         0H
ADR_ENCODES_CURRENT_POSITION                                Equ         1H
ADR_ENCODES_MEDIA_CATALOG                                   Equ         2H
ADR_ENCODES_ISRC                                            Equ         3H

AUDIO_WITH_PREEMPHASIS                                      Equ         1H
DIGITAL_COPY_PERMITTED                                      Equ         2H
AUDIO_DATA_TRACK                                            Equ         4H
TWO_FOUR_CHANNEL_AUDIO                                      Equ         8H

VOLUME_CONTROL Struct
    PortVolume                                              DB          4 Dup(?)
VOLUME_CONTROL EndS
PVOLUME_CONTROL                                             TypeDef     DWord

;TRACK_MODE_TYPE Enumeration
TRACK_MODE_TYPE                                             TypeDef     DWord
YellowMode2                                                 Equ         0
XAForm2                                                     Equ         1
CDDA                                                        Equ         2
RawWithC2AndSubCode                                         Equ         3
RawWithC2                                                   Equ         4
RawWithSubCode                                              Equ         5
PTRACK_MODE_TYPE                                            TypeDef     DWord

CD_RAW_READ_C2_SIZE                                         Equ         (296)
CD_RAW_READ_SUBCODE_SIZE                                    Equ         (96)
CD_RAW_SECTOR_WITH_C2_SIZE                                  Equ         (2352 + 296)
CD_RAW_SECTOR_WITH_SUBCODE_SIZE                             Equ         (2352 + 96)
CD_RAW_SECTOR_WITH_C2_AND_SUBCODE_SIZE                      Equ         (2352 + 296 + 96)

RAW_READ_INFO Struct
    DiskOffset                                              LARGE_INTEGER   <>
    SectorCount                                             DD          ?
    TrackMode                                               TRACK_MODE_TYPE ?
RAW_READ_INFO EndS
PRAW_READ_INFO                                              TypeDef     DWord

;MEDIA_BLANK_TYPE Enumeration
MEDIA_BLANK_TYPE                                            TypeDef     DWord
MediaBlankTypeFull                                          Equ         0
MediaBlankTypeMinimal                                       Equ         1
MediaBlankTypeIncompleteTrack                               Equ         2
MediaBlankTypeUnreserveLastTrack                            Equ         3
MediaBlankTypeTrackTail                                     Equ         4
MediaBlankTypeUncloseLastSession                            Equ         5
MediaBlankTypeEraseLastSession                              Equ         6
PMEDIA_BLANK_TYPE                                           TypeDef     DWord

CDROM_EXCLUSIVE_CALLER_LENGTH                               Equ         64

CDROM_LOCK_IGNORE_VOLUME                                    Equ         (1 Shl 0)
CDROM_NO_MEDIA_NOTIFICATIONS                                Equ         (1 Shl 1)

CDROM_NOT_IN_EXCLUSIVE_MODE                                 Equ         0
CDROM_IN_EXCLUSIVE_MODE                                     Equ         1

;EXCLUSIVE_ACCESS_REQUEST_TYPE Enumeration
EXCLUSIVE_ACCESS_REQUEST_TYPE                               TypeDef     DWord
ExclusiveAccessQueryState                                   Equ         0
ExclusiveAccessLockDevice                                   Equ         1
ExclusiveAccessUnlockDevice                                 Equ         2
PEXCLUSIVE_ACCESS_REQUEST_TYPE                              TypeDef     DWord

CDROM_EXCLUSIVE_ACCESS Struct
    RequestType                                             EXCLUSIVE_ACCESS_REQUEST_TYPE   ?
    Flags                                                   DD          ?
CDROM_EXCLUSIVE_ACCESS EndS
PCDROM_EXCLUSIVE_ACCESS                                     TypeDef     DWord

CDROM_EXCLUSIVE_LOCK Struct
    Access                                                  CDROM_EXCLUSIVE_ACCESS  <>
    CallerName                                              DB          CDROM_EXCLUSIVE_CALLER_LENGTH Dup(?)
CDROM_EXCLUSIVE_LOCK EndS
PCDROM_EXCLUSIVE_LOCK                                       TypeDef     DWord

CDROM_EXCLUSIVE_LOCK_STATE Struct
    LockState                                               BOOLEAN     ?
    CallerName                                              DB          CDROM_EXCLUSIVE_CALLER_LENGTH Dup(?)
CDROM_EXCLUSIVE_LOCK_STATE EndS
PCDROM_EXCLUSIVE_LOCK_STATE                                 TypeDef     DWord

;CDROM_SPEED_REQUEST Enumeration
CDROM_SPEED_REQUEST                                         TypeDef     DWord
CdromSetSpeed                                               Equ         0
CdromSetStreaming                                           Equ         1
PCDROM_SPEED_REQUEST                                        TypeDef     DWord

;WRITE_ROTATION Enumeration
WRITE_ROTATION                                              TypeDef     DWord
CdromDefaultRotation                                        Equ         0
CdromCAVRotation                                            Equ         1
PWRITE_ROTATION                                             TypeDef     DWord

CDROM_SET_SPEED Struct
    RequestType                                             CDROM_SPEED_REQUEST ?
    ReadSpeed                                               DW          ?
    WriteSpeed                                              DW          ?
    RotationControl                                         WRITE_ROTATION  ?
CDROM_SET_SPEED EndS
PCDROM_SET_SPEED                                            TypeDef     DWord

CDROM_SET_STREAMING Struct
    RequestType                                             CDROM_SPEED_REQUEST ?
    ReadSize                                                DD          ?
    ReadTime                                                DD          ?
    WriteSize                                               DD          ?
    WriteTime                                               DD          ?
    StartLba                                                DD          ?
    EndLba                                                  DD          ?
    RotationControl                                         WRITE_ROTATION  ?
    RestoreDefaults                                         BOOLEAN     ?
    SetExact                                                BOOLEAN     ?
    RandomAccess                                            BOOLEAN     ?
    Persistent                                              BOOLEAN     ?
CDROM_SET_STREAMING EndS
PCDROM_SET_STREAMING                                        TypeDef     DWord

;STREAMING_CONTROL_REQUEST_TYPE Enumeration
STREAMING_CONTROL_REQUEST_TYPE                              TypeDef     DWord
CdromStreamingDisable                                       Equ         1
CdromStreamingEnableForReadOnly                             Equ         2
CdromStreamingEnableForWriteOnly                            Equ         3
CdromStreamingEnableForReadWrite                            Equ         4
PSTREAMING_CONTROL_REQUEST_TYPE                             TypeDef     DWord

CDROM_STREAMING_CONTROL Struct
    RequestType                                             STREAMING_CONTROL_REQUEST_TYPE  ?
CDROM_STREAMING_CONTROL EndS
PCDROM_STREAMING_CONTROL                                    TypeDef     DWord

;CDROM_OPC_INFO_TYPE Enumeration
CDROM_OPC_INFO_TYPE                                         TypeDef     DWord
SimpleOpcInfo                                               Equ         1
PCDROM_OPC_INFO_TYPE                                        TypeDef     DWord

CDROM_SIMPLE_OPC_INFO Struct
    RequestType                                             CDROM_OPC_INFO_TYPE ?
    Exclude0                                                BOOLEAN     ?
    Exclude1                                                BOOLEAN     ?
CDROM_SIMPLE_OPC_INFO EndS
PCDROM_SIMPLE_OPC_INFO                                      TypeDef     DWord

;CDROM_PERFORMANCE_REQUEST_TYPE Enumeration
CDROM_PERFORMANCE_REQUEST_TYPE                              TypeDef     DWord
CdromPerformanceRequest                                     Equ         1
CdromWriteSpeedRequest                                      Equ         2
PCDROM_PERFORMANCE_REQUEST_TYPE                             TypeDef     DWord

;CDROM_PERFORMANCE_TYPE Enumeration
CDROM_PERFORMANCE_TYPE                                      TypeDef     DWord
CdromReadPerformance                                        Equ         1
CdromWritePerformance                                       Equ         2
PCDROM_PERFORMANCE_TYPE                                     TypeDef     DWord

;CDROM_PERFORMANCE_EXCEPTION_TYPE Enumeration
CDROM_PERFORMANCE_EXCEPTION_TYPE                            TypeDef     DWord
CdromNominalPerformance                                     Equ         1
CdromEntirePerformanceList                                  Equ         2
CdromPerformanceExceptionsOnly                              Equ         3
PCDROM_PERFORMANCE_EXCEPTION_TYPE                           TypeDef     DWord

;CDROM_PERFORMANCE_TOLERANCE_TYPE Enumeration
CDROM_PERFORMANCE_TOLERANCE_TYPE                            TypeDef     DWord
Cdrom10Nominal20Exceptions                                  Equ         1
PCDROM_PERFORMANCE_TOLERANCE_TYPE                           TypeDef     DWord

CDROM_PERFORMANCE_REQUEST Struct
    RequestType                                             CDROM_PERFORMANCE_REQUEST_TYPE  ?
    PerformanceType                                         CDROM_PERFORMANCE_TYPE  ?
    Exceptions                                              CDROM_PERFORMANCE_EXCEPTION_TYPE    ?
    Tolerance                                               CDROM_PERFORMANCE_TOLERANCE_TYPE    ?
    StaringLba                                              DD          ?
CDROM_PERFORMANCE_REQUEST EndS
PCDROM_PERFORMANCE_REQUEST                                  TypeDef     DWord

CDROM_WRITE_SPEED_REQUEST Struct
    RequestType                                             CDROM_PERFORMANCE_REQUEST_TYPE  ?
CDROM_WRITE_SPEED_REQUEST EndS
PCDROM_WRITE_SPEED_REQUEST                                  TypeDef     DWord

CDROM_NOMINAL_PERFORMANCE_DESCRIPTOR Struct
    StartLba                                                DB          4 Dup(?)
    StartPerformance                                        DB          4 Dup(?)
    EndLba                                                  DB          4 Dup(?)
    EndPerformance                                          DB          4 Dup(?)
CDROM_NOMINAL_PERFORMANCE_DESCRIPTOR EndS
PCDROM_NOMINAL_PERFORMANCE_DESCRIPTOR                       TypeDef     DWord

CDROM_EXCEPTION_PERFORMANCE_DESCRIPTOR Struct
    Lba                                                     DB          4 Dup(?)
    Time                                                    DB          2 Dup(?)
CDROM_EXCEPTION_PERFORMANCE_DESCRIPTOR EndS
PCDROM_EXCEPTION_PERFORMANCE_DESCRIPTOR                     TypeDef     DWord

ENDIF ;NTDDCDRM_INC
