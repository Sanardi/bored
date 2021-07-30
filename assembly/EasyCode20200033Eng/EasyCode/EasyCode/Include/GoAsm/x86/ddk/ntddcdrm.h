;===========================================================;
;                                                           ;
;     ntddcdrm.h for Easy Code 2.0 GoAsm 32-bit drivers     ;
;                     (version 1.0.0)                       ;
;                                                           ;
;             Driver Development Kit (32-bit)               ;
;                                                           ;
;              Copyright © Ramon Sala - 2015                ;
;                                                           ;
;===========================================================;

#IFNDEF NTDDCDRM_H
#Define NTDDCDRM_H 1

#IFNDEF MACRODRV_H
    #Include macrodrv.h
#ENDIF

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

IOCTL_CDROM_EXCLUSIVE_ACCESS                                Equ         CTL_CODE(IOCTL_CDROM_BASE, 0017H, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
IOCTL_CDROM_SET_SPEED                                       Equ         CTL_CODE(IOCTL_CDROM_BASE, 0018H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CDROM_GET_INQUIRY_DATA                                Equ         CTL_CODE(IOCTL_CDROM_BASE, 0019H, METHOD_BUFFERED, FILE_READ_ACCESS)

IOCTL_CDROM_ENABLE_STREAMING                                Equ         CTL_CODE(IOCTL_CDROM_BASE, 001AH, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CDROM_SEND_OPC_INFORMATION                            Equ         CTL_CODE(IOCTL_CDROM_BASE, 001BH, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)
IOCTL_CDROM_GET_PERFORMANCE                                 Equ         CTL_CODE(IOCTL_CDROM_BASE, 001CH, METHOD_BUFFERED, FILE_READ_ACCESS)

IOCTL_CDROM_CHECK_VERIFY                                    Equ         CTL_CODE(IOCTL_CDROM_BASE, 0200H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CDROM_MEDIA_REMOVAL                                   Equ         CTL_CODE(IOCTL_CDROM_BASE, 0201H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CDROM_EJECT_MEDIA                                     Equ         CTL_CODE(IOCTL_CDROM_BASE, 0202H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CDROM_LOAD_MEDIA                                      Equ         CTL_CODE(IOCTL_CDROM_BASE, 0203H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CDROM_RESERVE                                         Equ         CTL_CODE(IOCTL_CDROM_BASE, 0204H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CDROM_RELEASE                                         Equ         CTL_CODE(IOCTL_CDROM_BASE, 0205H, METHOD_BUFFERED, FILE_READ_ACCESS)
IOCTL_CDROM_FIND_NEW_DEVICES                                Equ         CTL_CODE(IOCTL_CDROM_BASE, 0206H, METHOD_BUFFERED, FILE_READ_ACCESS)

#IFNDEF NTDDSTOR_H
    #Include ntddstor.h
#ENDIF

MINIMUM_CDROM_INQUIRY_SIZE                                  Equ         36
MAXIMUM_CDROM_INQUIRY_SIZE                                  Equ         260

IOCTL_CDROM_SIMBAD                                          Equ         CTL_CODE(IOCTL_CDROM_BASE, 1003H, METHOD_BUFFERED, FILE_READ_ACCESS)

MAXIMUM_NUMBER_TRACKS                                       Equ         100
MAXIMUM_CDROM_SIZE                                          Equ         804
MINIMUM_CDROM_READ_TOC_EX_SIZE                              Equ         2

CDROM_READ_TOC_EX Struct
    fBits                                                   DB  ;Members Format to Msf are included here
    SessionTrack                                            DB
    Reserved2                                               DB
    Reserved3                                               DB
EndS

CDROM_READ_TOC_EX_FORMAT_TOC                                Equ         00H
CDROM_READ_TOC_EX_FORMAT_SESSION                            Equ         01H
CDROM_READ_TOC_EX_FORMAT_FULL_TOC                           Equ         02H
CDROM_READ_TOC_EX_FORMAT_PMA                                Equ         03H
CDROM_READ_TOC_EX_FORMAT_ATIP                               Equ         04H
CDROM_READ_TOC_EX_FORMAT_CDTEXT                             Equ         05H

TRACK_DATA Struct
    Reserved                                                DB
    fBits                                                   DB  ;Members Control to Adr are included here
    TrackNumber                                             DB
    Reserved1                                               DB
    Address                                                 DB          4 Dup ?
EndS

CDROM_TOC Struct
    Length                                                  DB          2 Dup ?
    FirstTrack                                              DB
    LastTrack                                               DB
    TrackData                                               TRACK_DATA  MAXIMUM_NUMBER_TRACKS Dup ?
EndS

CDROM_TOC_SIZE                                              Equ         SizeOf CDROM_TOC

CDROM_TOC_SESSION_DATA Struct
    Length                                                  DB          2 Dup ?
    FirstCompleteSession                                    DB
    LastCompleteSession                                     DB
    TrackData                                               TRACK_DATA  1 Dup ?
EndS

CDROM_TOC_FULL_TOC_DATA_BLOCK Struct
    SessionNumber                                           DB
    fBits                                                   DB  ;Members Control to Adr are included here
    Reserved1                                               DB
    Point                                                   DB
    MsfExtra                                                DB          3 Dup ?
    Zero                                                    DB
    Msf                                                     DB          3 Dup ?
EndS

CDROM_TOC_FULL_TOC_DATA Struct
    Length                                                  DB          2 Dup ?
    FirstCompleteSession                                    DB
    LastCompleteSession                                     DB
    Descriptors                                             CDROM_TOC_FULL_TOC_DATA_BLOCK 0 Dup ?
EndS

CDROM_TOC_PMA_DATA sTRUCT
    Length                                                  DB          2 Dup ?
    Reserved1                                               DB
    Reserved2                                               DB
    Descriptors                                             CDROM_TOC_FULL_TOC_DATA_BLOCK 0 Dup ?
EndS

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
    StartingM                                               DB
    StartingS                                               DB
    StartingF                                               DB
    EndingM                                                 DB
    EndingS                                                 DB
    EndingF                                                 DB
EndS

CDROM_SEEK_AUDIO_MSF Struct
    M                                                       DB
    S                                                       DB
    F                                                       DB
EndS

CDROM_DISK_DATA Struct
    DiskData                                                DD
EndS

CDROM_DISK_AUDIO_TRACK                                      Equ         (00000001H)
CDROM_DISK_DATA_TRACK                                       Equ         (00000002H)

IOCTL_CDROM_SUB_Q_CHANNEL                                   Equ         00H
IOCTL_CDROM_CURRENT_POSITION                                Equ         01H
IOCTL_CDROM_MEDIA_CATALOG                                   Equ         02H
IOCTL_CDROM_TRACK_ISRC                                      Equ         03H

CDROM_SUB_Q_DATA_FORMAT Struct
    Format                                                  DB
    Track                                                   DB
EndS

SUB_Q_HEADER Struct
    Reserved                                                DB
    AudioStatus                                             DB
    DataLength                                              DB          2 Dup ?
EndS

SUB_Q_CURRENT_POSITION Struct
    Header                                                  SUB_Q_HEADER
    FormatCode                                              DB
    fBits                                                   DB  ;Members Control to Adr are included here
    TrackNumber                                             DB
    IndexNumber                                             DB
    AbsoluteAddress                                         DB          4 Dup ?
    TrackRelativeAddress                                    DB          4 Dup ?
EndS

SUB_Q_MEDIA_CATALOG_NUMBER Struct
    Header                                                  SUB_Q_HEADER
    FormatCode                                              DB
    Reserved                                                DB          3 Dup ?
    fbits                                                   DB  ;Members Reserved to Mcval are included here
    MediaCatalog                                            DB          15 Dup ?
EndS

SUB_Q_TRACK_ISRC Struct
    Header                                                  SUB_Q_HEADER
    FormatCode                                              DB
    Reserved0                                               DB
    Track                                                   DB
    Reserved1                                               DB
    fbits                                                   DB ;Memebers Reserved2 to Tcval are included here
    TrackIsrc                                               DB          15 Dup ?
EndS

SUB_Q_CHANNEL_DATA Struct
    CurrentPosition                                         SUB_Q_CURRENT_POSITION
    MediaCatalog                                            SUB_Q_MEDIA_CATALOG_NUMBER
    TrackIsrc                                               SUB_Q_TRACK_ISRC
EndS

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
    PortVolume                                              DB          4 Dup ?
EndS

;TRACK_MODE_TYPE Enumeration
YellowMode2                                                 Equ         0
XAForm2                                                     Equ         1
CDDA                                                        Equ         2
RawWithC2AndSubCode                                         Equ         3
RawWithC2                                                   Equ         4
RawWithSubCode                                              Equ         5

CD_RAW_READ_C2_SIZE                                         Equ         (296)
CD_RAW_READ_SUBCODE_SIZE                                    Equ         (96)
CD_RAW_SECTOR_WITH_C2_SIZE                                  Equ         (2352 + 296)
CD_RAW_SECTOR_WITH_SUBCODE_SIZE                             Equ         (2352 + 96)
CD_RAW_SECTOR_WITH_C2_AND_SUBCODE_SIZE                      Equ         (2352 + 296 + 96)

RAW_READ_INFO Struct
    DiskOffset                                              LARGE_INTEGER
    SectorCount                                             DD
    TrackMode                                               DD
EndS

;MEDIA_BLANK_TYPE Enumeration
MediaBlankTypeFull                                          Equ         0
MediaBlankTypeMinimal                                       Equ         1
MediaBlankTypeIncompleteTrack                               Equ         2
MediaBlankTypeUnreserveLastTrack                            Equ         3
MediaBlankTypeTrackTail                                     Equ         4
MediaBlankTypeUncloseLastSession                            Equ         5
MediaBlankTypeEraseLastSession                              Equ         6

CDROM_EXCLUSIVE_CALLER_LENGTH                               Equ         64

CDROM_LOCK_IGNORE_VOLUME                                    Equ         (1 << 0)
CDROM_NO_MEDIA_NOTIFICATIONS                                Equ         (1 << 1)

CDROM_NOT_IN_EXCLUSIVE_MODE                                 Equ         0
CDROM_IN_EXCLUSIVE_MODE                                     Equ         1

;EXCLUSIVE_ACCESS_REQUEST_TYPE Enumeration
ExclusiveAccessQueryState                                   Equ         0
ExclusiveAccessLockDevice                                   Equ         1
ExclusiveAccessUnlockDevice                                 Equ         2

CDROM_EXCLUSIVE_ACCESS Struct
    RequestType                                             DD
    Flags                                                   DD
EndS

CDROM_EXCLUSIVE_LOCK Struct
    Access                                                  CDROM_EXCLUSIVE_ACCESS
    CallerName                                              DB          CDROM_EXCLUSIVE_CALLER_LENGTH Dup ?
EndS

CDROM_EXCLUSIVE_LOCK_STATE Struct
    LockState                                               DB
    CallerName                                              DB          CDROM_EXCLUSIVE_CALLER_LENGTH Dup ?
EndS

;CDROM_SPEED_REQUEST Enumeration
CdromSetSpeed                                               Equ         0
CdromSetStreaming                                           Equ         1

;WRITE_ROTATION Enumeration
CdromDefaultRotation                                        Equ         0
CdromCAVRotation                                            Equ         1

CDROM_SET_SPEED Struct
    RequestType                                             DD
    ReadSpeed                                               DW
    WriteSpeed                                              DW
    RotationControl                                         DD
EndS

CDROM_SET_STREAMING Struct
    RequestType                                             DD
    ReadSize                                                DD
    ReadTime                                                DD
    WriteSize                                               DD
    WriteTime                                               DD
    StartLba                                                DD
    EndLba                                                  DD
    RotationControl                                         DD
    RestoreDefaults                                         DB
    SetExact                                                DB
    RandomAccess                                            DB
    Persistent                                              DB
EndS

;STREAMING_CONTROL_REQUEST_TYPE Enumeration
CdromStreamingDisable                                       Equ         1
CdromStreamingEnableForReadOnly                             Equ         2
CdromStreamingEnableForWriteOnly                            Equ         3
CdromStreamingEnableForReadWrite                            Equ         4

CDROM_STREAMING_CONTROL Struct
    RequestType                                             DD
EndS

;CDROM_OPC_INFO_TYPE Enumeration
SimpleOpcInfo                                               Equ         1

CDROM_SIMPLE_OPC_INFO Struct
    RequestType                                             DD
    Exclude0                                                DB
    Exclude1                                                DB
EndS

;CDROM_PERFORMANCE_REQUEST_TYPE Enumeration
CdromPerformanceRequest                                     Equ         1
CdromWriteSpeedRequest                                      Equ         2

;CDROM_PERFORMANCE_TYPE Enumeration
CdromReadPerformance                                        Equ         1
CdromWritePerformance                                       Equ         2

;CDROM_PERFORMANCE_EXCEPTION_TYPE Enumeration
CdromNominalPerformance                                     Equ         1
CdromEntirePerformanceList                                  Equ         2
CdromPerformanceExceptionsOnly                              Equ         3

;CDROM_PERFORMANCE_TOLERANCE_TYPE Enumeration
Cdrom10Nominal20Exceptions                                  Equ         1

CDROM_PERFORMANCE_REQUEST Struct
    RequestType                                             DD
    PerformanceType                                         DD
    Exceptions                                              DD
    Tolerance                                               DD
    StaringLba                                              DD
EndS

CDROM_WRITE_SPEED_REQUEST Struct
    RequestType                                             DD
EndS

CDROM_NOMINAL_PERFORMANCE_DESCRIPTOR Struct
    StartLba                                                DB          4 Dup ?
    StartPerformance                                        DB          4 Dup ?
    EndLba                                                  DB          4 Dup ?
    EndPerformance                                          DB          4 Dup ?
EndS

CDROM_EXCEPTION_PERFORMANCE_DESCRIPTOR Struct
    Lba                                                     DB          4 Dup ?
    Time                                                    DB          2 Dup ?
EndS

#ENDIF ;NTDDCDRM_H
