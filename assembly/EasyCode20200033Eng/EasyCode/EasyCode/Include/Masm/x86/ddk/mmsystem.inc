;===================================================================;
;                                                                   ;
;  mmsystem.inc for Easy Code 2.0 JWasm/Masm/PoAsm 32-bit drivers   ;
;                        (version 1.0.1)                            ;
;                                                                   ;
;                 Driver Development Kit (32-bit)                   ;
;                                                                   ;
;                Copyright © Ramon Sala - 2015-2016                 ;
;                                                                   ;
;===================================================================;

IFNDEF MMSYSTEM_INC
MMSYSTEM_INC Equ 1

IFNDEF MACRODRV_INC
    Include macrodrv.inc
ENDIF

MMVERSION                                                   TypeDef     DWord
MAXPNAMELEN                                                 Equ         32
MAXERRORLENGTH                                              Equ         256
MAX_JOYSTICKOEMVXDNAME                                      Equ         260

IFNDEF MM_MICROSOFT
    MM_MICROSOFT                                            Equ         1
ENDIF

IFNDEF MM_MIDI_MAPPER
    MM_MIDI_MAPPER                                          Equ         1
    MM_WAVE_MAPPER                                          Equ         2
    MM_SNDBLST_MIDIOUT                                      Equ         3
    MM_SNDBLST_MIDIIN                                       Equ         4
    MM_SNDBLST_SYNTH                                        Equ         5
    MM_SNDBLST_WAVEOUT                                      Equ         6
    MM_SNDBLST_WAVEIN                                       Equ         7
    MM_ADLIB                                                Equ         9
    MM_MPU401_MIDIOUT                                       Equ         10
    MM_MPU401_MIDIIN                                        Equ         11
    MM_PC_JOYSTICK                                          Equ         12
ENDIF

MMTIME Struct
    wType                                                   DD          ?
    Union u
        ms                                                  DD          ?
        sample                                              DD          ?
        cb                                                  DD          ?
        ticks                                               DD          ?
        Struct smpte
            hour                                            DB          ?
            min                                             DB          ?
            sec                                             DB          ?
            frame                                           DB          ?
            fps                                             DB          ?
            dummy                                           DB          ?
            pad                                             DB          2 Dup(?)
        EndS
        songptrpos                                          DD          ?
    EndS
MMTIME EndS

TIME_MS                                                     Equ         00001H
TIME_SAMPLES                                                Equ         00002H
TIME_BYTES                                                  Equ         00004H
TIME_SMPTE                                                  Equ         00008H
TIME_MIDI                                                   Equ         00010H
TIME_TICKS                                                  Equ         00020H

MM_JOY1MOVE                                                 Equ         03A0H
MM_JOY2MOVE                                                 Equ         03A1H
MM_JOY1ZMOVE                                                Equ         03A2H
MM_JOY2ZMOVE                                                Equ         03A3H
MM_JOY1BUTTONDOWN                                           Equ         03B5H
MM_JOY2BUTTONDOWN                                           Equ         03B6H
MM_JOY1BUTTONUP                                             Equ         03B7H
MM_JOY2BUTTONUP                                             Equ         03B8H

MM_MCINOTIFY                                                Equ         03B9H

MM_WOM_OPEN                                                 Equ         03BBH
MM_WOM_CLOSE                                                Equ         03BCH
MM_WOM_DONE                                                 Equ         03BDH

MM_WIM_OPEN                                                 Equ         03BEH
MM_WIM_CLOSE                                                Equ         03BFH
MM_WIM_DATA                                                 Equ         03C0H

MM_MIM_OPEN                                                 Equ         03C1H
MM_MIM_CLOSE                                                Equ         03C2H
MM_MIM_DATA                                                 Equ         03C3H
MM_MIM_LONGDATA                                             Equ         03C4H
MM_MIM_ERROR                                                Equ         03C5H
MM_MIM_LONGERROR                                            Equ         03C6H

MM_MOM_OPEN                                                 Equ         03C7H
MM_MOM_CLOSE                                                Equ         03C8H
MM_MOM_DONE                                                 Equ         03C9H

IFNDEF MM_DRVM_OPEN
    MM_DRVM_OPEN                                            Equ         03D0H
    MM_DRVM_CLOSE                                           Equ         03D1H
    MM_DRVM_DATA                                            Equ         03D2H
    MM_DRVM_ERROR                                           Equ         03D3H
ENDIF

MM_STREAM_OPEN                                              Equ         03D4H
MM_STREAM_CLOSE                                             Equ         03D5H
MM_STREAM_DONE                                              Equ         03D6H
MM_STREAM_ERROR                                             Equ         03D7H

MM_MOM_POSITIONCB                                           Equ         03CAH

IFNDEF MM_MCISIGNAL
    MM_MCISIGNAL                                            Equ         03CBH
ENDIF

MM_MIM_MOREDATA                                             Equ         03CCH

MM_MIXM_LINE_CHANGE                                         Equ         03D0H
MM_MIXM_CONTROL_CHANGE                                      Equ         03D1H

MMSYSERR_BASE                                               Equ         0
WAVERR_BASE                                                 Equ         32
MIDIERR_BASE                                                Equ         64
TIMERR_BASE                                                 Equ         96
JOYERR_BASE                                                 Equ         160
MCIERR_BASE                                                 Equ         256
MIXERR_BASE                                                 Equ         1024

MCI_STRING_OFFSET                                           Equ         512
MCI_VD_OFFSET                                               Equ         1024
MCI_CD_OFFSET                                               Equ         1088
MCI_WAVE_OFFSET                                             Equ         1152
MCI_SEQ_OFFSET                                              Equ         1216

MMSYSERR_NOERROR                                            Equ         0
MMSYSERR_ERROR                                              Equ         (MMSYSERR_BASE + 1)
MMSYSERR_BADDEVICEID                                        Equ         (MMSYSERR_BASE + 2)
MMSYSERR_NOTENABLED                                         Equ         (MMSYSERR_BASE + 3)
MMSYSERR_ALLOCATED                                          Equ         (MMSYSERR_BASE + 4)
MMSYSERR_INVALHANDLE                                        Equ         (MMSYSERR_BASE + 5)
MMSYSERR_NODRIVER                                           Equ         (MMSYSERR_BASE + 6)
MMSYSERR_NOMEM                                              Equ         (MMSYSERR_BASE + 7)
MMSYSERR_NOTSUPPORTED                                       Equ         (MMSYSERR_BASE + 8)
MMSYSERR_BADERRNUM                                          Equ         (MMSYSERR_BASE + 9)
MMSYSERR_INVALFLAG                                          Equ         (MMSYSERR_BASE + 10)
MMSYSERR_INVALPARAM                                         Equ         (MMSYSERR_BASE + 11)
MMSYSERR_HANDLEBUSY                                         Equ         (MMSYSERR_BASE + 12)

MMSYSERR_INVALIDALIAS                                       Equ         (MMSYSERR_BASE + 13)
MMSYSERR_BADDB                                              Equ         (MMSYSERR_BASE + 14)
MMSYSERR_KEYNOTFOUND                                        Equ         (MMSYSERR_BASE + 15)
MMSYSERR_READERROR                                          Equ         (MMSYSERR_BASE + 16)
MMSYSERR_WRITEERROR                                         Equ         (MMSYSERR_BASE + 17)
MMSYSERR_DELETEERROR                                        Equ         (MMSYSERR_BASE + 18)
MMSYSERR_VALNOTFOUND                                        Equ         (MMSYSERR_BASE + 19)
MMSYSERR_NODRIVERCB                                         Equ         (MMSYSERR_BASE + 20)
MMSYSERR_MOREDATA                                           Equ         (MMSYSERR_BASE + 21)
MMSYSERR_LASTERROR                                          Equ         (MMSYSERR_BASE + 21)

DRVCONFIGINFOEX Struct
    dwDCISize                                               DD          ?
    lpszDCISectionName                                      DD          ?
    lpszDCIAliasName                                        DD          ?
    dnDevNode                                               DD          ?
DRVCONFIGINFOEX EndS

IFNDEF DRV_LOAD
    DRV_LOAD                                                Equ         00001H
    DRV_ENABLE                                              Equ         00002H
    DRV_OPEN                                                Equ         00003H
    DRV_CLOSE                                               Equ         00004H
    DRV_DISABLE                                             Equ         00005H
    DRV_FREE                                                Equ         00006H
    DRV_CONFIGURE                                           Equ         00007H
    DRV_QUERYCONFIGURE                                      Equ         00008H
    DRV_INSTALL                                             Equ         00009H
    DRV_REMOVE                                              Equ         0000AH
    DRV_EXITSESSION                                         Equ         0000BH
    DRV_POWER                                               Equ         0000FH
    DRV_RESERVED                                            Equ         00800H
    DRV_USER                                                Equ         04000H
    DRVCNF_CANCEL                                           Equ         00000H
    DRVCNF_OK                                               Equ         00001H
    DRVCNF_RESTART                                          Equ         00002H
    
    DRVCONFIGINFO Struct
        dwDCISize                                           DD          ?
        lpszDCISectionName                                  DD          ?
        lpszDCIAliasName                                    DD          ?
    DRVCONFIGINFO EndS
ENDIF

DRV_CANCEL                                                  Equ         DRVCNF_CANCEL
DRV_OK                                                      Equ         DRVCNF_OK
DRV_RESTART                                                 Equ         DRVCNF_RESTART

DRV_MCI_FIRST                                               Equ         DRV_RESERVED
DRV_MCI_LAST                                                Equ         (DRV_RESERVED + 0FFFH)


CALLBACK_TYPEMASK                                           Equ         000070000H
CALLBACK_NULL                                               Equ         000000000H
CALLBACK_WINDOW                                             Equ         000010000H
CALLBACK_TASK                                               Equ         000020000H
CALLBACK_FUNCTION                                           Equ         000030000H
CALLBACK_THREAD                                             Equ         CALLBACK_TASK
CALLBACK_EVENT                                              Equ         000050000H

SND_SYNC                                                    Equ         00000H
SND_ASYNC                                                   Equ         00001H
SND_NODEFAULT                                               Equ         00002H
SND_MEMORY                                                  Equ         00004H
SND_LOOP                                                    Equ         00008H
SND_NOSTOP                                                  Equ         00010H

SND_NOWAIT                                                  Equ         000002000H
SND_ALIAS                                                   Equ         000010000H
SND_ALIAS_ID                                                Equ         000110000H
SND_FILENAME                                                Equ         000020000H
SND_RESOURCE                                                Equ         000040004H
SND_PURGE                                                   Equ         00040H
SND_APPLICATION                                             Equ         00080H

SND_ALIAS_START                                             Equ         0

SND_ALIAS_SYSTEMASTERISK                                    Equ         ((SND_ALIAS_START + 53H + 2AH) Or ((53H + 2AH) Shl 8))
SND_ALIAS_SYSTEMQUESTION                                    Equ         ((SND_ALIAS_START + 53H + 3FH) Or ((53H + 3FH) Shl 8))
SND_ALIAS_SYSTEMHAND                                        Equ         ((SND_ALIAS_START + 53H + 48H) Or ((53H + 48H) Shl 8))
SND_ALIAS_SYSTEMEXIT                                        Equ         ((SND_ALIAS_START + 53H + 45H) Or ((53H + 45H) Shl 8))
SND_ALIAS_SYSTEMSTART                                       Equ         ((SND_ALIAS_START + 53H + 53H) Or ((53H + 53H) Shl 8))
SND_ALIAS_SYSTEMWELCOME                                     Equ         ((SND_ALIAS_START + 53H + 57H) Or ((53H + 57H) Shl 8))
SND_ALIAS_SYSTEMEXCLAMATION                                 Equ         ((SND_ALIAS_START + 53H + 21H) Or ((53H + 21H) Shl 8))
SND_ALIAS_SYSTEMDEFAULT                                     Equ         ((SND_ALIAS_START + 53H + 44H) Or ((53H + 44H) Shl 8))

IFDEF APP_UNICODE
    sndPlaySound                                            Equ         <sndPlaySoundW>
    PlaySound                                               Equ         <PlaySoundW>
ELSE
    sndPlaySound                                            Equ         <sndPlaySoundA>
    PlaySound                                               Equ         <PlaySoundA>
ENDIF

WAVERR_BADFORMAT                                            Equ         (WAVERR_BASE + 0)
WAVERR_STILLPLAYING                                         Equ         (WAVERR_BASE + 1)
WAVERR_UNPREPARED                                           Equ         (WAVERR_BASE + 2)
WAVERR_SYNC                                                 Equ         (WAVERR_BASE + 3)
WAVERR_LASTERROR                                            Equ         (WAVERR_BASE + 3)

WOM_OPEN                                                    Equ         MM_WOM_OPEN
WOM_CLOSE                                                   Equ         MM_WOM_CLOSE
WOM_DONE                                                    Equ         MM_WOM_DONE
WIM_OPEN                                                    Equ         MM_WIM_OPEN
WIM_CLOSE                                                   Equ         MM_WIM_CLOSE
WIM_DATA                                                    Equ         MM_WIM_DATA

WAVE_MAPPER                                                 Equ         (-1)

WAVE_FORMAT_QUERY                                           Equ         00001H
WAVE_ALLOWSYNC                                              Equ         00002H
WAVE_MAPPED                                                 Equ         00004H
WAVE_FORMAT_DIRECT                                          Equ         00008H
WAVE_FORMAT_DIRECT_QUERY                                    Equ         (WAVE_FORMAT_QUERY Or WAVE_FORMAT_DIRECT)

WHDR_DONE                                                   Equ         000000001H
WHDR_PREPARED                                               Equ         000000002H
WHDR_BEGINLOOP                                              Equ         000000004H
WHDR_ENDLOOP                                                Equ         000000008H
WHDR_INQUEUE                                                Equ         000000010H

WAVECAPS_PITCH                                              Equ         00001H
WAVECAPS_PLAYBACKRATE                                       Equ         00002H
WAVECAPS_VOLUME                                             Equ         00004H
WAVECAPS_LRVOLUME                                           Equ         00008H
WAVECAPS_SYNC                                               Equ         00010H
WAVECAPS_SAMPLEACCURATE                                     Equ         00020H

WAVE_INVALIDFORMAT                                          Equ         000000000H
WAVE_FORMAT_1M08                                            Equ         000000001H
WAVE_FORMAT_1S08                                            Equ         000000002H
WAVE_FORMAT_1M16                                            Equ         000000004H
WAVE_FORMAT_1S16                                            Equ         000000008H
WAVE_FORMAT_2M08                                            Equ         000000010H
WAVE_FORMAT_2S08                                            Equ         000000020H
WAVE_FORMAT_2M16                                            Equ         000000040H
WAVE_FORMAT_2S16                                            Equ         000000080H
WAVE_FORMAT_4M08                                            Equ         000000100H
WAVE_FORMAT_4S08                                            Equ         000000200H
WAVE_FORMAT_4M16                                            Equ         000000400H
WAVE_FORMAT_4S16                                            Equ         000000800H
WAVE_FORMAT_44M08                                           Equ         000000100H
WAVE_FORMAT_44S08                                           Equ         000000200H
WAVE_FORMAT_44M16                                           Equ         000000400H
WAVE_FORMAT_44S16                                           Equ         000000800H
WAVE_FORMAT_48M08                                           Equ         000001000H
WAVE_FORMAT_48S08                                           Equ         000002000H
WAVE_FORMAT_48M16                                           Equ         000004000H
WAVE_FORMAT_48S16                                           Equ         000008000H
WAVE_FORMAT_96M08                                           Equ         000010000H
WAVE_FORMAT_96S08                                           Equ         000020000H
WAVE_FORMAT_96M16                                           Equ         000040000H
WAVE_FORMAT_96S16                                           Equ         000080000H

WAVEHDR Struct
    lpData                                                  DD          ?
    dwBufferLength                                          DD          ?
    dwBytesRecorded                                         DD          ?
    dwUser                                                  DD          ?
    dwFlags                                                 DD          ?
    dwLoops                                                 DD          ?
    lpNext                                                  DD          ?
    reserved                                                DD          ?
WAVEHDR EndS

WAVEOUTCAPSA Struct
    wMid                                                    DW          ?
    wPid                                                    DW          ?
    vDriverVersion                                          DD          ?
    szPname                                                 DB          MAXPNAMELEN Dup(?)
    dwFormats                                               DD          ?
    wChannels                                               DW          ?
    wReserved1                                              DW          ?
    dwSupport                                               DD          ?
WAVEOUTCAPSA EndS

WAVEOUTCAPSW Struct
    wMid                                                    DW          ?
    wPid                                                    DW          ?
    vDriverVersion                                          DD          ?
    szPname                                                 DW          MAXPNAMELEN Dup(?)
    dwFormats                                               DD          ?
    wChannels                                               DW          ?
    wReserved1                                              DW          ?
    dwSupport                                               DD          ?
WAVEOUTCAPSW EndS

WAVEOUTCAPS2A Struct
    wMid                                                    DW          ?
    wPid                                                    DW          ?
    vDriverVersion                                          DD          ?
    szPname                                                 DB          MAXPNAMELEN Dup(?)
    dwFormats                                               DD          ?
    wChannels                                               DW          ?
    wReserved1                                              DW          ?
    dwSupport                                               DD          ?
    ManufacturerGuid                                        GUID        <>
    ProductGuid                                             GUID        <>
    NameGuid                                                GUID        <>
WAVEOUTCAPS2A EndS

WAVEOUTCAPS2W Struct
    wMid                                                    DW          ?
    wPid                                                    DW          ?
    vDriverVersion                                          DD          ?
    szPname                                                 DW          MAXPNAMELEN Dup(?)
    dwFormats                                               DD          ?
    wChannels                                               DW          ?
    wReserved1                                              DW          ?
    dwSupport                                               DD          ?
    ManufacturerGuid                                        GUID        <>
    ProductGuid                                             GUID        <>
    NameGuid                                                GUID        <>
WAVEOUTCAPS2W EndS

WAVEINCAPSA Struct
    wMid                                                    DW          ?
    wPid                                                    DW          ?
    vDriverVersion                                          DD          ?
    szPname                                                 DB          MAXPNAMELEN Dup(?)
    dwFormats                                               DD          ?
    wChannels                                               DW          ?
    wReserved1                                              DW          ?
WAVEINCAPSA EndS

WAVEINCAPSW Struct
    wMid                                                    DW          ?
    wPid                                                    DW          ?
    vDriverVersion                                          DD          ?
    szPname                                                 DW          MAXPNAMELEN Dup(?)
    dwFormats                                               DD          ?
    wChannels                                               DW          ?
    wReserved1                                              DW          ?
WAVEINCAPSW EndS

WAVEINCAPS2A Struct
    wMid                                                    DW          ?
    wPid                                                    DW          ?
    vDriverVersion                                          DD          ?
    szPname                                                 DB          MAXPNAMELEN Dup(?)
    dwFormats                                               DD          ?
    wChannels                                               DW          ?
    wReserved1                                              DW          ?
    ManufacturerGuid                                        GUID        <>
    ProductGuid                                             GUID        <>
    NameGuid                                                GUID        <>
WAVEINCAPS2A EndS

WAVEINCAPS2W Struct
    wMid                                                    DW          ?
    wPid                                                    DW          ?
    vDriverVersion                                          DD          ?
    szPname                                                 DW          MAXPNAMELEN Dup(?)
    dwFormats                                               DD          ?
    wChannels                                               DW          ?
    wReserved1                                              DW          ?
    ManufacturerGuid                                        GUID        <>
    ProductGuid                                             GUID        <>
    NameGuid                                                GUID        <>
WAVEINCAPS2W EndS

IFNDEF WAVE_FORMAT_PCM
    WAVE_FORMAT_PCM                                         Equ         1
    WAVEFORMAT Struct
        wFormatTag                                          DW          ?
        nChannels                                           DW          ?
        nSamplesPerSec                                      DD          ?
        nAvgBytesPerSec                                     DD          ?
        nBlockAlign                                         DW          ?
    WAVEFORMAT EndS
    PCMWAVEFORMAT Struct
        wf                                                  WAVEFORMAT  <>
        wBitsPerSample                                      DW          ?
    PCMWAVEFORMAT EndS
ENDIF

IFNDEF _WAVEFORMATEX
    WAVEFORMATEX Struct
        wFormatTag                                          DW          ?
        nChannels                                           DW          ?
        nSamplesPerSec                                      DD          ?
        nAvgBytesPerSec                                     DD          ?
        nBlockAlign                                         DW          ?
        wBitsPerSample                                      DW          ?
        cbSize                                              DW          ?
    WAVEFORMATEX EndS
    _WAVEFORMATEX                                           Equ         1
ENDIF

IFDEF APP_UNICODE
    waveOutGetDevCaps                                       Equ         <waveOutGetDevCapsW>
    waveOutGetErrorText                                     Equ         <waveOutGetErrorTextW>
    waveInGetDevCaps                                        Equ         <waveInGetDevCapsW>
    waveInGetErrorText                                      Equ         <waveInGetErrorTextW>
ELSE
    waveOutGetDevCaps                                       Equ         <waveOutGetDevCapsA>
    waveOutGetErrorText                                     Equ         <waveOutGetErrorTextA>
    waveInGetDevCaps                                        Equ         <waveInGetDevCapsA>
    waveInGetErrorText                                      Equ         <waveInGetErrorTextA>
ENDIF

MIDIERR_UNPREPARED                                          Equ         (MIDIERR_BASE + 0)
MIDIERR_STILLPLAYING                                        Equ         (MIDIERR_BASE + 1)
MIDIERR_NOMAP                                               Equ         (MIDIERR_BASE + 2)
MIDIERR_NOTREADY                                            Equ         (MIDIERR_BASE + 3)
MIDIERR_NODEVICE                                            Equ         (MIDIERR_BASE + 4)
MIDIERR_INVALIDSETUP                                        Equ         (MIDIERR_BASE + 5)
MIDIERR_BADOPENMODE                                         Equ         (MIDIERR_BASE + 6)
MIDIERR_DONT_CONTINUE                                       Equ         (MIDIERR_BASE + 7)
MIDIERR_LASTERROR                                           Equ         (MIDIERR_BASE + 7)

MIM_OPEN                                                    Equ         MM_MIM_OPEN
MIM_CLOSE                                                   Equ         MM_MIM_CLOSE
MIM_DATA                                                    Equ         MM_MIM_DATA
MIM_LONGDATA                                                Equ         MM_MIM_LONGDATA
MIM_ERROR                                                   Equ         MM_MIM_ERROR
MIM_LONGERROR                                               Equ         MM_MIM_LONGERROR
MOM_OPEN                                                    Equ         MM_MOM_OPEN
MOM_CLOSE                                                   Equ         MM_MOM_CLOSE
MOM_DONE                                                    Equ         MM_MOM_DONE

MIM_MOREDATA                                                Equ         MM_MIM_MOREDATA
MOM_POSITIONCB                                              Equ         MM_MOM_POSITIONCB

MIDIMAPPER                                                  Equ         (-1)
MIDI_MAPPER                                                 Equ         (-1)

MIDI_IO_STATUS                                              Equ         000000020H

MIDI_CACHE_ALL                                              Equ         1
MIDI_CACHE_BESTFIT                                          Equ         2
MIDI_CACHE_QUERY                                            Equ         3
MIDI_UNCACHE                                                Equ         4

MOD_MIDIPORT                                                Equ         1
MOD_SYNTH                                                   Equ         2
MOD_SQSYNTH                                                 Equ         3
MOD_FMSYNTH                                                 Equ         4
MOD_MAPPER                                                  Equ         5
MOD_WAVETABLE                                               Equ         6
MOD_SWSYNTH                                                 Equ         7

MIDICAPS_VOLUME                                             Equ         00001H
MIDICAPS_LRVOLUME                                           Equ         00002H
MIDICAPS_CACHE                                              Equ         00004H
MIDICAPS_STREAM                                             Equ         00008H

MHDR_DONE                                                   Equ         000000001H
MHDR_PREPARED                                               Equ         000000002H
MHDR_INQUEUE                                                Equ         000000004H
MHDR_ISSTRM                                                 Equ         000000008H

MEVT_F_SHORT                                                Equ         000000000H
MEVT_F_LONG                                                 Equ         080000000H
MEVT_F_CALLBACK                                             Equ         040000000H

MEVT_SHORTMSG                                               Equ         0
MEVT_TEMPO                                                  Equ         1
MEVT_NOP                                                    Equ         2

MEVT_LONGMSG                                                Equ         080H
MEVT_COMMENT                                                Equ         082H
MEVT_VERSION                                                Equ         084H

MIDISTRM_ERROR                                              Equ         (-2)

MIDIPROP_SET                                                Equ         080000000H
MIDIPROP_GET                                                Equ         040000000H

MIDIPROP_TIMEDIV                                            Equ         000000001H
MIDIPROP_TEMPO                                              Equ         000000002H

MIDIPATCHSIZE                                               Equ         128

MIDIOUTCAPSA Struct
    wMid                                                    DW          ?
    wPid                                                    DW          ?
    vDriverVersion                                          DD          ?
    szPname                                                 DB          MAXPNAMELEN Dup(?)
    wTechnology                                             DW          ?
    wVoices                                                 DW          ?
    wNotes                                                  DW          ?
    wChannelMask                                            DW          ?
    dwSupport                                               DD          ?
MIDIOUTCAPSA EndS

MIDIOUTCAPSW Struct
    wMid                                                    DW          ?
    wPid                                                    DW          ?
    vDriverVersion                                          DD          ?
    szPname                                                 DW          MAXPNAMELEN Dup(?)
    wTechnology                                             DW          ?
    wVoices                                                 DW          ?
    wNotes                                                  DW          ?
    wChannelMask                                            DW          ?
    dwSupport                                               DD          ?
MIDIOUTCAPSW EndS

MIDIOUTCAPS2A Struct
    wMid                                                    DW          ?
    wPid                                                    DW          ?
    vDriverVersion                                          DD          ?
    szPname                                                 DB          MAXPNAMELEN Dup(?)
    wTechnology                                             DW          ?
    wVoices                                                 DW          ?
    wNotes                                                  DW          ?
    wChannelMask                                            DW          ?
    dwSupport                                               DD          ?
    ManufacturerGuid                                        GUID        <>
    ProductGuid                                             GUID        <>
    NameGuid                                                GUID        <>
MIDIOUTCAPS2A EndS

MIDIOUTCAPS2W Struct
    wMid                                                    DW          ?
    wPid                                                    DW          ?
    vDriverVersion                                          DD          ?
    szPname                                                 DW          MAXPNAMELEN Dup(?)
    wTechnology                                             DW          ?
    wVoices                                                 DW          ?
    wNotes                                                  DW          ?
    wChannelMask                                            DW          ?
    dwSupport                                               DD          ?
    ManufacturerGuid                                        GUID        <>
    ProductGuid                                             GUID        <>
    NameGuid                                                GUID        <>
MIDIOUTCAPS2W EndS

MIDIINCAPSA Struct
    wMid                                                    DW          ?
    wPid                                                    DW          ?
    vDriverVersion                                          DD          ?
    szPname                                                 DB          MAXPNAMELEN Dup(?)
    dwSupport                                               DD          ?
MIDIINCAPSA EndS

MIDIINCAPSW Struct
    wMid                                                    DW          ?
    wPid                                                    DW          ?
    vDriverVersion                                          DD          ?
    szPname                                                 DW          MAXPNAMELEN Dup(?)
    dwSupport                                               DD          ?
MIDIINCAPSW EndS

MIDIINCAPS2A Struct
    wMid                                                    DW          ?
    wPid                                                    DW          ?
    vDriverVersion                                          DD          ?
    szPname                                                 DB          MAXPNAMELEN Dup(?)
    dwSupport                                               DD          ?
    ManufacturerGuid                                        GUID        <>
    ProductGuid                                             GUID        <>
    NameGuid                                                GUID        <>
MIDIINCAPS2A EndS

MIDIINCAPS2W Struct
    wMid                                                    DW          ?
    wPid                                                    DW          ?
    vDriverVersion                                          DD          ?
    szPname                                                 DW          MAXPNAMELEN Dup(?)
    dwSupport                                               DD          ?
    ManufacturerGuid                                        GUID        <>
    ProductGuid                                             GUID        <>
    NameGuid                                                GUID        <>
MIDIINCAPS2W EndS

MIDIHDR Struct
    lpData                                                  DD          ?
    dwBufferLength                                          DD          ?
    dwBytesRecorded                                         DD          ?
    dwUser                                                  DD          ?
    dwFlags                                                 DD          ?
    lpNext                                                  DD          ?
    reserved                                                DD          ?
    dwOffset                                                DD          ?
    dwReserved                                              DD          8 Dup(?)
MIDIHDR EndS

MIDIEVENT Struct
    dwDeltaTime                                             DD          ?
    dwStreamID                                              DD          ?
    dwEvent                                                 DD          ?
    dwParms                                                 DD          ?
MIDIEVENT EndS

MIDISTRMBUFFVER Struct
    dwVersion                                               DD          ?
    dwMid                                                   DD          ?
    dwOEMVersion                                            DD          ?
MIDISTRMBUFFVER EndS

MIDIPROPTIMEDIV Struct
    cbStruct                                                DD          ?
    dwTimeDiv                                               DD          ?
MIDIPROPTIMEDIV EndS

MIDIPROPTEMPO Struct
    cbStruct                                                DD          ?
    dwTempo                                                 DD          ?
MIDIPROPTEMPO EndS

IFDEF APP_UNICODE
    MIDIOUTCAPS                                             Equ         <MIDIOUTCAPSW>
    MIDIOUTCAPS2                                            Equ         <MIDIOUTCAPS2W>
    MIDIINCAPS                                              Equ         <MIDIINCAPSW>
    MIDIINCAPS2                                             Equ         <MIDIINCAPS2W>
    midiOutGetDevCaps                                       Equ         <midiOutGetDevCapsW>
    midiOutGetErrorText                                     Equ         <midiOutGetErrorTextW>
    midiInGetDevCaps                                        Equ         <midiInGetDevCapsW>
    midiInGetErrorText                                      Equ         <midiInGetErrorTextW>
ELSE
    MIDIOUTCAPS                                             Equ         <MIDIOUTCAPSA>
    MIDIOUTCAPS2                                            Equ         <MIDIOUTCAPS2A>
    MIDIINCAPS                                              Equ         <MIDIINCAPSA>
    MIDIINCAPS2                                             Equ         <MIDIINCAPS2A>
    midiOutGetDevCaps                                       Equ         <midiOutGetDevCapsA>
    midiOutGetErrorText                                     Equ         <midiOutGetErrorTextA>
    midiInGetDevCaps                                        Equ         <midiInGetDevCapsA>
    midiInGetErrorText                                      Equ         <midiInGetErrorTextA>
ENDIF

AUX_MAPPER                                                  Equ         (-1)

AUXCAPS_CDAUDIO                                             Equ         1
AUXCAPS_AUXIN                                               Equ         2
AUXCAPS_VOLUME                                              Equ         00001H
AUXCAPS_LRVOLUME                                            Equ         00002H

AUXCAPSA Struct
    wMid                                                    DW          ?
    wPid                                                    DW          ?
    vDriverVersion                                          DD          ?
    szPname                                                 DB          MAXPNAMELEN Dup(?)
    wTechnology                                             DW          ?
    wReserved1                                              DW          ?
    dwSupport                                               DD          ?
AUXCAPSA EndS

AUXCAPSW Struct
    wMid                                                    DW          ?
    wPid                                                    DW          ?
    vDriverVersion                                          DD          ?
    szPname                                                 DW          MAXPNAMELEN Dup(?)
    wTechnology                                             DW          ?
    wReserved1                                              DW          ?
    dwSupport                                               DD          ?
AUXCAPSW EndS

AUXCAPS2A Struct
    wMid                                                    DW          ?
    wPid                                                    DW          ?
    vDriverVersion                                          DD          ?
    szPname                                                 DB          MAXPNAMELEN Dup(?)
    wTechnology                                             DW          ?
    wReserved1                                              DW          ?
    dwSupport                                               DD          ?
    ManufacturerGuid                                        GUID        <>
    ProductGuid                                             GUID        <>
    NameGuid                                                GUID        <>
AUXCAPS2A EndS

AUXCAPS2W Struct
    wMid                                                    DW          ?
    wPid                                                    DW          ?
    vDriverVersion                                          DD          ?
    szPname                                                 DW          MAXPNAMELEN Dup(?)
    wTechnology                                             DW          ?
    wReserved1                                              DW          ?
    dwSupport                                               DD          ?
    ManufacturerGuid                                        GUID        <>
    ProductGuid                                             GUID        <>
    NameGuid                                                GUID        <>
AUXCAPS2W EndS

IFDEF APP_UNICODE
    AUXCAPS                                                 Equ         <AUXCAPSW>
    AUXCAPS2                                                Equ         <AUXCAPS2W>
    auxGetDevCaps                                           Equ         <auxGetDevCapsW>
ELSE
    AUXCAPS                                                 Equ         <AUXCAPSA>
    AUXCAPS2                                                Equ         <AUXCAPS2A>
    auxGetDevCaps                                           Equ         <auxGetDevCapsA>
ENDIF

MIXER_SHORT_NAME_CHARS                                      Equ         16
MIXER_LONG_NAME_CHARS                                       Equ         64

MIXERR_INVALLINE                                            Equ         (MIXERR_BASE + 0)
MIXERR_INVALCONTROL                                         Equ         (MIXERR_BASE + 1)
MIXERR_INVALVALUE                                           Equ         (MIXERR_BASE + 2)
MIXERR_LASTERROR                                            Equ         (MIXERR_BASE + 2)

MIXER_OBJECTF_HANDLE                                        Equ         080000000H
MIXER_OBJECTF_MIXER                                         Equ         000000000H
MIXER_OBJECTF_HMIXER                                        Equ         (MIXER_OBJECTF_HANDLE Or MIXER_OBJECTF_MIXER)
MIXER_OBJECTF_WAVEOUT                                       Equ         010000000H
MIXER_OBJECTF_HWAVEOUT                                      Equ         (MIXER_OBJECTF_HANDLE Or MIXER_OBJECTF_WAVEOUT)
MIXER_OBJECTF_WAVEIN                                        Equ         020000000H
MIXER_OBJECTF_HWAVEIN                                       Equ         (MIXER_OBJECTF_HANDLE Or MIXER_OBJECTF_WAVEIN)
MIXER_OBJECTF_MIDIOUT                                       Equ         030000000H
MIXER_OBJECTF_HMIDIOUT                                      Equ         (MIXER_OBJECTF_HANDLE Or MIXER_OBJECTF_MIDIOUT)
MIXER_OBJECTF_MIDIIN                                        Equ         040000000H
MIXER_OBJECTF_HMIDIIN                                       Equ         (MIXER_OBJECTF_HANDLE Or MIXER_OBJECTF_MIDIIN)
MIXER_OBJECTF_AUX                                           Equ         050000000H

MIXERLINE_LINEF_ACTIVE                                      Equ         000000001H
MIXERLINE_LINEF_DISCONNECTED                                Equ         000008000H
MIXERLINE_LINEF_SOURCE                                      Equ         080000000H

MIXERLINE_COMPONENTTYPE_DST_FIRST                           Equ         000000000H
MIXERLINE_COMPONENTTYPE_DST_UNDEFINED                       Equ         (MIXERLINE_COMPONENTTYPE_DST_FIRST + 0)
MIXERLINE_COMPONENTTYPE_DST_DIGITAL                         Equ         (MIXERLINE_COMPONENTTYPE_DST_FIRST + 1)
MIXERLINE_COMPONENTTYPE_DST_LINE                            Equ         (MIXERLINE_COMPONENTTYPE_DST_FIRST + 2)
MIXERLINE_COMPONENTTYPE_DST_MONITOR                         Equ         (MIXERLINE_COMPONENTTYPE_DST_FIRST + 3)
MIXERLINE_COMPONENTTYPE_DST_SPEAKERS                        Equ         (MIXERLINE_COMPONENTTYPE_DST_FIRST + 4)
MIXERLINE_COMPONENTTYPE_DST_HEADPHONES                      Equ         (MIXERLINE_COMPONENTTYPE_DST_FIRST + 5)
MIXERLINE_COMPONENTTYPE_DST_TELEPHONE                       Equ         (MIXERLINE_COMPONENTTYPE_DST_FIRST + 6)
MIXERLINE_COMPONENTTYPE_DST_WAVEIN                          Equ         (MIXERLINE_COMPONENTTYPE_DST_FIRST + 7)
MIXERLINE_COMPONENTTYPE_DST_VOICEIN                         Equ         (MIXERLINE_COMPONENTTYPE_DST_FIRST + 8)
MIXERLINE_COMPONENTTYPE_DST_LAST                            Equ         (MIXERLINE_COMPONENTTYPE_DST_FIRST + 8)

MIXERLINE_COMPONENTTYPE_SRC_FIRST                           Equ         000001000H
MIXERLINE_COMPONENTTYPE_SRC_UNDEFINED                       Equ         (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 0)
MIXERLINE_COMPONENTTYPE_SRC_DIGITAL                         Equ         (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 1)
MIXERLINE_COMPONENTTYPE_SRC_LINE                            Equ         (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 2)
MIXERLINE_COMPONENTTYPE_SRC_MICROPHONE                      Equ         (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 3)
MIXERLINE_COMPONENTTYPE_SRC_SYNTHESIZER                     Equ         (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 4)
MIXERLINE_COMPONENTTYPE_SRC_COMPACTDISC                     Equ         (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 5)
MIXERLINE_COMPONENTTYPE_SRC_TELEPHONE                       Equ         (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 6)
MIXERLINE_COMPONENTTYPE_SRC_PCSPEAKER                       Equ         (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 7)
MIXERLINE_COMPONENTTYPE_SRC_WAVEOUT                         Equ         (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 8)
MIXERLINE_COMPONENTTYPE_SRC_AUXILIARY                       Equ         (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 9)
MIXERLINE_COMPONENTTYPE_SRC_ANALOG                          Equ         (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 10)
MIXERLINE_COMPONENTTYPE_SRC_LAST                            Equ         (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 10)

MIXERLINE_TARGETTYPE_UNDEFINED                              Equ         0
MIXERLINE_TARGETTYPE_WAVEOUT                                Equ         1
MIXERLINE_TARGETTYPE_WAVEIN                                 Equ         2
MIXERLINE_TARGETTYPE_MIDIOUT                                Equ         3
MIXERLINE_TARGETTYPE_MIDIIN                                 Equ         4
MIXERLINE_TARGETTYPE_AUX                                    Equ         5

MIXER_GETLINEINFOF_DESTINATION                              Equ         000000000H
MIXER_GETLINEINFOF_SOURCE                                   Equ         000000001H
MIXER_GETLINEINFOF_LINEID                                   Equ         000000002H
MIXER_GETLINEINFOF_COMPONENTTYPE                            Equ         000000003H
MIXER_GETLINEINFOF_TARGETTYPE                               Equ         000000004H
MIXER_GETLINEINFOF_QUERYMASK                                Equ         00000000FH

MIXERCONTROL_CONTROLF_UNIFORM                               Equ         000000001H
MIXERCONTROL_CONTROLF_MULTIPLE                              Equ         000000002H
MIXERCONTROL_CONTROLF_DISABLED                              Equ         080000000H

MIXERCONTROL_CT_CLASS_MASK                                  Equ         0F0000000H
MIXERCONTROL_CT_CLASS_CUSTOM                                Equ         000000000H
MIXERCONTROL_CT_CLASS_METER                                 Equ         010000000H
MIXERCONTROL_CT_CLASS_SWITCH                                Equ         020000000H
MIXERCONTROL_CT_CLASS_NUMBER                                Equ         030000000H
MIXERCONTROL_CT_CLASS_SLIDER                                Equ         040000000H
MIXERCONTROL_CT_CLASS_FADER                                 Equ         050000000H
MIXERCONTROL_CT_CLASS_TIME                                  Equ         060000000H
MIXERCONTROL_CT_CLASS_LIST                                  Equ         070000000H

MIXERCONTROL_CT_SUBCLASS_MASK                               Equ         00F000000H

MIXERCONTROL_CT_SC_SWITCH_BOOLEAN                           Equ         000000000H
MIXERCONTROL_CT_SC_SWITCH_BUTTON                            Equ         001000000H

MIXERCONTROL_CT_SC_METER_POLLED                             Equ         000000000H

MIXERCONTROL_CT_SC_TIME_MICROSECS                           Equ         000000000H
MIXERCONTROL_CT_SC_TIME_MILLISECS                           Equ         001000000H

MIXERCONTROL_CT_SC_LIST_SINGLE                              Equ         000000000H
MIXERCONTROL_CT_SC_LIST_MULTIPLE                            Equ         001000000H

MIXERCONTROL_CT_UNITS_MASK                                  Equ         000FF0000H
MIXERCONTROL_CT_UNITS_CUSTOM                                Equ         000000000H
MIXERCONTROL_CT_UNITS_BOOLEAN                               Equ         000010000H
MIXERCONTROL_CT_UNITS_SIGNED                                Equ         000020000H
MIXERCONTROL_CT_UNITS_UNSIGNED                              Equ         000030000H
MIXERCONTROL_CT_UNITS_DECIBELS                              Equ         000040000H
MIXERCONTROL_CT_UNITS_PERCENT                               Equ         000050000H

MIXERCONTROL_CONTROLTYPE_CUSTOM                             Equ         (MIXERCONTROL_CT_CLASS_CUSTOM Or MIXERCONTROL_CT_UNITS_CUSTOM)
MIXERCONTROL_CONTROLTYPE_BOOLEANMETER                       Equ         (MIXERCONTROL_CT_CLASS_METER Or MIXERCONTROL_CT_SC_METER_POLLED Or MIXERCONTROL_CT_UNITS_BOOLEAN)
MIXERCONTROL_CONTROLTYPE_SIGNEDMETER                        Equ         (MIXERCONTROL_CT_CLASS_METER Or MIXERCONTROL_CT_SC_METER_POLLED Or MIXERCONTROL_CT_UNITS_SIGNED)
MIXERCONTROL_CONTROLTYPE_PEAKMETER                          Equ         (MIXERCONTROL_CONTROLTYPE_SIGNEDMETER + 1)
MIXERCONTROL_CONTROLTYPE_UNSIGNEDMETER                      Equ         (MIXERCONTROL_CT_CLASS_METER Or MIXERCONTROL_CT_SC_METER_POLLED Or MIXERCONTROL_CT_UNITS_UNSIGNED)
MIXERCONTROL_CONTROLTYPE_BOOLEAN                            Equ         (MIXERCONTROL_CT_CLASS_SWITCH Or MIXERCONTROL_CT_SC_SWITCH_BOOLEAN Or MIXERCONTROL_CT_UNITS_BOOLEAN)
MIXERCONTROL_CONTROLTYPE_ONOFF                              Equ         (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 1)
MIXERCONTROL_CONTROLTYPE_MUTE                               Equ         (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 2)
MIXERCONTROL_CONTROLTYPE_MONO                               Equ         (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 3)
MIXERCONTROL_CONTROLTYPE_LOUDNESS                           Equ         (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 4)
MIXERCONTROL_CONTROLTYPE_STEREOENH                          Equ         (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 5)
MIXERCONTROL_CONTROLTYPE_BASS_BOOST                         Equ         (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 000002277H)
MIXERCONTROL_CONTROLTYPE_BUTTON                             Equ         (MIXERCONTROL_CT_CLASS_SWITCH Or MIXERCONTROL_CT_SC_SWITCH_BUTTON Or MIXERCONTROL_CT_UNITS_BOOLEAN)
MIXERCONTROL_CONTROLTYPE_DECIBELS                           Equ         (MIXERCONTROL_CT_CLASS_NUMBER Or MIXERCONTROL_CT_UNITS_DECIBELS)
MIXERCONTROL_CONTROLTYPE_SIGNED                             Equ         (MIXERCONTROL_CT_CLASS_NUMBER Or MIXERCONTROL_CT_UNITS_SIGNED)
MIXERCONTROL_CONTROLTYPE_UNSIGNED                           Equ         (MIXERCONTROL_CT_CLASS_NUMBER Or MIXERCONTROL_CT_UNITS_UNSIGNED)
MIXERCONTROL_CONTROLTYPE_PERCENT                            Equ         (MIXERCONTROL_CT_CLASS_NUMBER Or MIXERCONTROL_CT_UNITS_PERCENT)
MIXERCONTROL_CONTROLTYPE_SLIDER                             Equ         (MIXERCONTROL_CT_CLASS_SLIDER Or MIXERCONTROL_CT_UNITS_SIGNED)
MIXERCONTROL_CONTROLTYPE_PAN                                Equ         (MIXERCONTROL_CONTROLTYPE_SLIDER + 1)
MIXERCONTROL_CONTROLTYPE_QSOUNDPAN                          Equ         (MIXERCONTROL_CONTROLTYPE_SLIDER + 2)
MIXERCONTROL_CONTROLTYPE_FADER                              Equ         (MIXERCONTROL_CT_CLASS_FADER Or MIXERCONTROL_CT_UNITS_UNSIGNED)
MIXERCONTROL_CONTROLTYPE_VOLUME                             Equ         (MIXERCONTROL_CONTROLTYPE_FADER + 1)
MIXERCONTROL_CONTROLTYPE_BASS                               Equ         (MIXERCONTROL_CONTROLTYPE_FADER + 2)
MIXERCONTROL_CONTROLTYPE_TREBLE                             Equ         (MIXERCONTROL_CONTROLTYPE_FADER + 3)
MIXERCONTROL_CONTROLTYPE_EQUALIZER                          Equ         (MIXERCONTROL_CONTROLTYPE_FADER + 4)
MIXERCONTROL_CONTROLTYPE_SINGLESELECT                       Equ         (MIXERCONTROL_CT_CLASS_LIST Or MIXERCONTROL_CT_SC_LIST_SINGLE Or MIXERCONTROL_CT_UNITS_BOOLEAN)
MIXERCONTROL_CONTROLTYPE_MUX                                Equ         (MIXERCONTROL_CONTROLTYPE_SINGLESELECT + 1)
MIXERCONTROL_CONTROLTYPE_MULTIPLESELECT                     Equ         (MIXERCONTROL_CT_CLASS_LIST Or MIXERCONTROL_CT_SC_LIST_MULTIPLE Or MIXERCONTROL_CT_UNITS_BOOLEAN)
MIXERCONTROL_CONTROLTYPE_MIXER                              Equ         (MIXERCONTROL_CONTROLTYPE_MULTIPLESELECT + 1)
MIXERCONTROL_CONTROLTYPE_MICROTIME                          Equ         (MIXERCONTROL_CT_CLASS_TIME Or MIXERCONTROL_CT_SC_TIME_MICROSECS Or MIXERCONTROL_CT_UNITS_UNSIGNED)
MIXERCONTROL_CONTROLTYPE_MILLITIME                          Equ         (MIXERCONTROL_CT_CLASS_TIME Or MIXERCONTROL_CT_SC_TIME_MILLISECS Or MIXERCONTROL_CT_UNITS_UNSIGNED)

MIXER_GETLINECONTROLSF_ALL                                  Equ         000000000H
MIXER_GETLINECONTROLSF_ONEBYID                              Equ         000000001H
MIXER_GETLINECONTROLSF_ONEBYTYPE                            Equ         000000002H
MIXER_GETLINECONTROLSF_QUERYMASK                            Equ         00000000FH

MIXER_GETCONTROLDETAILSF_VALUE                              Equ         000000000H
MIXER_GETCONTROLDETAILSF_LISTTEXT                           Equ         000000001H
MIXER_GETCONTROLDETAILSF_QUERYMASK                          Equ         00000000FH

MIXER_SETCONTROLDETAILSF_VALUE                              Equ         000000000H
MIXER_SETCONTROLDETAILSF_CUSTOM                             Equ         000000001H
MIXER_SETCONTROLDETAILSF_QUERYMASK                          Equ         00000000FH

MIXERCAPSA Struct
    wMid                                                    DW          ?
    wPid                                                    DW          ?
    vDriverVersion                                          DD          ?
    szPname                                                 DB          MAXPNAMELEN Dup(?)
    fdwSupport                                              DD          ?
    cDestinations                                           DD          ?
MIXERCAPSA EndS

MIXERCAPSW Struct
    wMid                                                    DW          ?
    wPid                                                    DW          ?
    vDriverVersion                                          DD          ?
    szPname                                                 DW          MAXPNAMELEN Dup(?)
    fdwSupport                                              DD          ?
    cDestinations                                           DD          ?
MIXERCAPSW EndS

MIXERCAPS2A Struct
    wMid                                                    DW          ?
    wPid                                                    DW          ?
    vDriverVersion                                          DD          ?
    szPname                                                 DB          MAXPNAMELEN Dup(?)
    fdwSupport                                              DD          ?
    cDestinations                                           DD          ?
    ManufacturerGuid                                        GUID        <>
    ProductGuid                                             GUID        <>
    NameGuid                                                GUID        <>
MIXERCAPS2A EndS

MIXERCAPS2W Struct
    wMid                                                    DW          ?
    wPid                                                    DW          ?
    vDriverVersion                                          DD          ?
    szPname                                                 DW          MAXPNAMELEN Dup(?)
    fdwSupport                                              DD          ?
    cDestinations                                           DD          ?
    ManufacturerGuid                                        GUID        <>
    ProductGuid                                             GUID        <>
    NameGuid                                                GUID        <>
MIXERCAPS2W EndS

MIXERLINEA Struct
    cbStruct                                                DD          ?
    dwDestination                                           DD          ?
    dwSource                                                DD          ?
    dwLineID                                                DD          ?
    fdwLine                                                 DD          ?
    dwUser                                                  DD          ?
    dwComponentType                                         DD          ?
    cChannels                                               DD          ?
    cConnections                                            DD          ?
    cControls                                               DD          ?
    szShortName                                             DB          MIXER_SHORT_NAME_CHARS Dup(?)
    szName                                                  DB          MIXER_LONG_NAME_CHARS Dup(?)
    Struct Target
        dwType                                              DD          ?
        dwDeviceID                                          DD          ?
        wMid                                                DW          ?
        wPid                                                DW          ?
        vDriverVersion                                      MMVERSION   ?
        szPname                                             DB          MAXPNAMELEN Dup(?)
    EndS
MIXERLINEA EndS

MIXERLINEW Struct
    cbStruct                                                DD          ?
    dwDestination                                           DD          ?
    dwSource                                                DD          ?
    dwLineID                                                DD          ?
    fdwLine                                                 DD          ?
    dwUser                                                  DD          ?
    dwComponentType                                         DD          ?
    cChannels                                               DD          ?
    cConnections                                            DD          ?
    cControls                                               DD          ?
    szShortName                                             DW          MIXER_SHORT_NAME_CHARS Dup(?)
    szName                                                  DW          MIXER_LONG_NAME_CHARS Dup(?)
    Struct Target
        dwType                                              DD          ?
        dwDeviceID                                          DD          ?
        wMid                                                DW          ?
        wPid                                                DW          ?
        vDriverVersion                                      MMVERSION   ?
        szPname                                             DW          MAXPNAMELEN Dup(?)
    EndS
MIXERLINEW EndS

MIXERCONTROLA Struct
    cbStruct                                                DD          ?
    dwControlID                                             DD          ?
    dwControlType                                           DD          ?
    fdwControl                                              DD          ?
    cMultipleItems                                          DD          ?
    szShortName                                             DB          MIXER_SHORT_NAME_CHARS Dup(?)
    szName                                                  DB          MIXER_LONG_NAME_CHARS Dup(?)
    Union
        Struct
            dwMinimum                                       DD          ?
            dwMaximum                                       DD          ?
        EndS
        Struct
            lMinimum                                        DD          ?
            lMaximum                                        DD          ?
        EndS
    EndS
    Union
        cSteps                                              DD          ?
        cbCustomData                                        DD          ?
        dwReserved                                          DD          6 Dup(?)
    EndS
MIXERCONTROLA EndS

MIXERCONTROLW Struct
    cbStruct                                                DD          ?
    dwControlID                                             DD          ?
    dwControlType                                           DD          ?
    fdwControl                                              DD          ?
    cMultipleItems                                          DD          ?
    szShortName                                             DW          MIXER_SHORT_NAME_CHARS Dup(?)
    szName                                                  DW          MIXER_LONG_NAME_CHARS Dup(?)
    Union
        Struct
            dwMinimum                                       DD          ?
            dwMaximum                                       DD          ?
        EndS
        Struct
            lMinimum                                        DD          ?
            lMaximum                                        DD          ?
        EndS
    EndS
    Union
        cSteps                                              DD          ?
        cbCustomData                                        DD          ?
        dwReserved                                          DD          6 Dup(?)
    EndS
MIXERCONTROLW EndS


MIXERLINECONTROLSA Struct
    cbStruct                                                DD          ?
    dwLineID                                                DD          ?
    Union
        dwControlID                                         DD          ?
        dwControlType                                       DD          ?
    EndS
    cControls                                               DD          ?
    cbmxctrl                                                DD          ?
    pamxctrl                                                DD          ?
MIXERLINECONTROLSA EndS

MIXERLINECONTROLSW Struct
    cbStruct                                                DD          ?
    dwLineID                                                DD          ?
    Union
        dwControlID                                         DD          ?
        dwControlType                                       DD          ?
    EndS
    cControls                                               DD          ?
    cbmxctrl                                                DD          ?
    pamxctrl                                                DD          ?
MIXERLINECONTROLSW EndS

MIXERCONTROLDETAILS Struct
    cbStruct                                                DD          ?
    dwControlID                                             DD          ?
    cChannels                                               DD          ?
    Union
        hwndOwner                                           HANDLE      ?
        cMultipleItems                                      DD          ?
    EndS
    cbDetails                                               DD          ?
    paDetails                                               DD          ?
MIXERCONTROLDETAILS EndS

MIXERCONTROLDETAILS_LISTTEXTA Struct
    dwParam1                                                DD          ?
    dwParam2                                                DD          ?
    szName                                                  DB          MIXER_LONG_NAME_CHARS Dup(?)
MIXERCONTROLDETAILS_LISTTEXTA EndS

MIXERCONTROLDETAILS_LISTTEXTW Struct
    dwParam1                                                DD          ?
    dwParam2                                                DD          ?
    szName                                                  DW          MIXER_LONG_NAME_CHARS Dup(?)
MIXERCONTROLDETAILS_LISTTEXTW EndS

MIXERCONTROLDETAILS_BOOLEAN Struct
    fValue                                                  DD          ?
MIXERCONTROLDETAILS_BOOLEAN EndS

MIXERCONTROLDETAILS_SIGNED Struct
    lValue                                                  DD          ?
MIXERCONTROLDETAILS_SIGNED EndS

MIXERCONTROLDETAILS_UNSIGNED Struct
    dwValue                                                 DD          ?
MIXERCONTROLDETAILS_UNSIGNED EndS

IFDEF APP_UNICODE
    MIXERCAPS                                               Equ         <MIXERCAPSW>
    MIXERCAPS2                                              Equ         <MIXERCAPS2W>
    MIXERLINE                                               Equ         <MIXERLINEW>
    MIXERCONTROL                                            Equ         <MIXERCONTROLW>
    MIXERLINECONTROLS                                       Equ         <MIXERLINECONTROLSW>
    MIXERCONTROLDETAILS_LISTTEXT                            Equ         <MIXERCONTROLDETAILS_LISTTEXTW>
    mixerGetDevCaps                                         Equ         <mixerGetDevCapsW>
    mixerGetLineInfo                                        Equ         <mixerGetLineInfoW>
    mixerGetLineControls                                    Equ         <mixerGetLineControlsW>
    mixerGetControlDetails                                  Equ         <mixerGetControlDetailsW>
ELSE
    MIXERCAPS                                               Equ         <MIXERCAPSA>
    MIXERCAPS2                                              Equ         <MIXERCAPS2A>
    MIXERLINE                                               Equ         <MIXERLINEA>
    MIXERCONTROL                                            Equ         <MIXERCONTROLA>
    MIXERLINECONTROLS                                       Equ         <MIXERLINECONTROLSA>
    MIXERCONTROLDETAILS_LISTTEXT                            Equ         <MIXERCONTROLDETAILS_LISTTEXTA>
    mixerGetDevCaps                                         Equ         <mixerGetDevCapsA>
    mixerGetLineInfo                                        Equ         <mixerGetLineInfoA>
    mixerGetLineControls                                    Equ         <mixerGetLineControlsA>
    mixerGetControlDetails                                  Equ         <mixerGetControlDetailsA>
ENDIF

TIMERR_NOERROR                                              Equ         0
TIMERR_NOCANDO                                              Equ         (TIMERR_BASE + 1)
TIMERR_STRUCT                                               Equ         (TIMERR_BASE + 33)

TIME_ONESHOT                                                Equ         00000H
TIME_PERIODIC                                               Equ         00001H

TIME_CALLBACK_FUNCTION                                      Equ         00000H
TIME_CALLBACK_EVENT_SET                                     Equ         00010H
TIME_CALLBACK_EVENT_PULSE                                   Equ         00020H

TIME_KILL_SYNCHRONOUS                                       Equ         00100H

TIMECAPS Struct
    wPeriodMin                                              DD          ?
    wPeriodMax                                              DD          ?
TIMECAPS EndS

JOYERR_NOERROR                                              Equ         0
JOYERR_PARMS                                                Equ         (JOYERR_BASE + 5)
JOYERR_NOCANDO                                              Equ         (JOYERR_BASE + 6)
JOYERR_UNPLUGGED                                            Equ         (JOYERR_BASE + 7)

JOY_BUTTON1                                                 Equ         00001H
JOY_BUTTON2                                                 Equ         00002H
JOY_BUTTON3                                                 Equ         00004H
JOY_BUTTON4                                                 Equ         00008H
JOY_BUTTON1CHG                                              Equ         00100H
JOY_BUTTON2CHG                                              Equ         00200H
JOY_BUTTON3CHG                                              Equ         00400H
JOY_BUTTON4CHG                                              Equ         00800H

JOY_BUTTON5                                                 Equ         000000010H
JOY_BUTTON6                                                 Equ         000000020H
JOY_BUTTON7                                                 Equ         000000040H
JOY_BUTTON8                                                 Equ         000000080H
JOY_BUTTON9                                                 Equ         000000100H
JOY_BUTTON10                                                Equ         000000200H
JOY_BUTTON11                                                Equ         000000400H
JOY_BUTTON12                                                Equ         000000800H
JOY_BUTTON13                                                Equ         000001000H
JOY_BUTTON14                                                Equ         000002000H
JOY_BUTTON15                                                Equ         000004000H
JOY_BUTTON16                                                Equ         000008000H
JOY_BUTTON17                                                Equ         000010000H
JOY_BUTTON18                                                Equ         000020000H
JOY_BUTTON19                                                Equ         000040000H
JOY_BUTTON20                                                Equ         000080000H
JOY_BUTTON21                                                Equ         000100000H
JOY_BUTTON22                                                Equ         000200000H
JOY_BUTTON23                                                Equ         000400000H
JOY_BUTTON24                                                Equ         000800000H
JOY_BUTTON25                                                Equ         001000000H
JOY_BUTTON26                                                Equ         002000000H
JOY_BUTTON27                                                Equ         004000000H
JOY_BUTTON28                                                Equ         008000000H
JOY_BUTTON29                                                Equ         010000000H
JOY_BUTTON30                                                Equ         020000000H
JOY_BUTTON31                                                Equ         040000000H
JOY_BUTTON32                                                Equ         080000000H

JOY_POVCENTERED                                             Equ         (-1)
JOY_POVFORWARD                                              Equ         0
JOY_POVRIGHT                                                Equ         9000
JOY_POVBACKWARD                                             Equ         18000
JOY_POVLEFT                                                 Equ         27000

JOY_RETURNX                                                 Equ         000000001H
JOY_RETURNY                                                 Equ         000000002H
JOY_RETURNZ                                                 Equ         000000004H
JOY_RETURNR                                                 Equ         000000008H
JOY_RETURNU                                                 Equ         000000010H
JOY_RETURNV                                                 Equ         000000020H
JOY_RETURNPOV                                               Equ         000000040H
JOY_RETURNBUTTONS                                           Equ         000000080H
JOY_RETURNRAWDATA                                           Equ         000000100H
JOY_RETURNPOVCTS                                            Equ         000000200H
JOY_RETURNCENTERED                                          Equ         000000400H
JOY_USEDEADZONE                                             Equ         000000800H
JOY_RETURNALL                                               Equ         (JOY_RETURNX Or JOY_RETURNY Or JOY_RETURNZ Or JOY_RETURNR Or JOY_RETURNU Or JOY_RETURNV Or JOY_RETURNPOV Or JOY_RETURNBUTTONS)
JOY_CAL_READALWAYS                                          Equ         000010000H
JOY_CAL_READXYONLY                                          Equ         000020000H
JOY_CAL_READ3                                               Equ         000040000H
JOY_CAL_READ4                                               Equ         000080000H
JOY_CAL_READXONLY                                           Equ         000100000H
JOY_CAL_READYONLY                                           Equ         000200000H
JOY_CAL_READ5                                               Equ         000400000H
JOY_CAL_READ6                                               Equ         000800000H
JOY_CAL_READZONLY                                           Equ         001000000H
JOY_CAL_READRONLY                                           Equ         002000000H
JOY_CAL_READUONLY                                           Equ         004000000H
JOY_CAL_READVONLY                                           Equ         008000000H

JOYSTICKID1                                                 Equ         0
JOYSTICKID2                                                 Equ         1

JOYCAPS_HASZ                                                Equ         00001H
JOYCAPS_HASR                                                Equ         00002H
JOYCAPS_HASU                                                Equ         00004H
JOYCAPS_HASV                                                Equ         00008H
JOYCAPS_HASPOV                                              Equ         00010H
JOYCAPS_POV4DIR                                             Equ         00020H
JOYCAPS_POVCTS                                              Equ         00040H

JOYCAPSA Struct
    wMid                                                    DW          ?
    wPid                                                    DW          ?
    szPname                                                 DB          MAXPNAMELEN Dup(?)
    wXmin                                                   DD          ?
    wXmax                                                   DD          ?
    wYmin                                                   DD          ?
    wYmax                                                   DD          ?
    wZmin                                                   DD          ?
    wZmax                                                   DD          ?
    wNumButtons                                             DD          ?
    wPeriodMin                                              DD          ?
    wPeriodMax                                              DD          ?
    wRmin                                                   DD          ?
    wRmax                                                   DD          ?
    wUmin                                                   DD          ?
    wUmax                                                   DD          ?
    wVmin                                                   DD          ?
    wVmax                                                   DD          ?
    wCaps                                                   DD          ?
    wMaxAxes                                                DD          ?
    wNumAxes                                                DD          ?
    wMaxButtons                                             DD          ?
    szRegKey                                                DB          MAXPNAMELEN Dup(?)
    szOEMVxD                                                DB          MAX_JOYSTICKOEMVXDNAME Dup(?)
JOYCAPSA EndS

JOYCAPSW Struct
    wMid                                                    DW          ?
    wPid                                                    DW          ?
    szPname                                                 DW          MAXPNAMELEN Dup(?)
    wXmin                                                   DD          ?
    wXmax                                                   DD          ?
    wYmin                                                   DD          ?
    wYmax                                                   DD          ?
    wZmin                                                   DD          ?
    wZmax                                                   DD          ?
    wNumButtons                                             DD          ?
    wPeriodMin                                              DD          ?
    wPeriodMax                                              DD          ?
    wRmin                                                   DD          ?
    wRmax                                                   DD          ?
    wUmin                                                   DD          ?
    wUmax                                                   DD          ?
    wVmin                                                   DD          ?
    wVmax                                                   DD          ?
    wCaps                                                   DD          ?
    wMaxAxes                                                DD          ?
    wNumAxes                                                DD          ?
    wMaxButtons                                             DD          ?
    szRegKey                                                DW          MAXPNAMELEN Dup(?)
    szOEMVxD                                                DW          MAX_JOYSTICKOEMVXDNAME Dup(?)
JOYCAPSW EndS

JOYCAPS2A Struct
    wMid                                                    DW          ?
    wPid                                                    DW          ?
    szPname                                                 DB          MAXPNAMELEN Dup(?)
    wXmin                                                   DD          ?
    wXmax                                                   DD          ?
    wYmin                                                   DD          ?
    wYmax                                                   DD          ?
    wZmin                                                   DD          ?
    wZmax                                                   DD          ?
    wNumButtons                                             DD          ?
    wPeriodMin                                              DD          ?
    wPeriodMax                                              DD          ?
    wRmin                                                   DD          ?
    wRmax                                                   DD          ?
    wUmin                                                   DD          ?
    wUmax                                                   DD          ?
    wVmin                                                   DD          ?
    wVmax                                                   DD          ?
    wCaps                                                   DD          ?
    wMaxAxes                                                DD          ?
    wNumAxes                                                DD          ?
    wMaxButtons                                             DD          ?
    szRegKey                                                DB          MAXPNAMELEN Dup(?)
    szOEMVxD                                                DB          MAX_JOYSTICKOEMVXDNAME Dup(?)
    ManufacturerGuid                                        GUID        <>
    ProductGuid                                             GUID        <>
    NameGuid                                                GUID        <>
JOYCAPS2A EndS

JOYCAPS2W Struct
    wMid                                                    DW          ?
    wPid                                                    DW          ?
    szPname                                                 DW          MAXPNAMELEN Dup(?)
    wXmin                                                   DD          ?
    wXmax                                                   DD          ?
    wYmin                                                   DD          ?
    wYmax                                                   DD          ?
    wZmin                                                   DD          ?
    wZmax                                                   DD          ?
    wNumButtons                                             DD          ?
    wPeriodMin                                              DD          ?
    wPeriodMax                                              DD          ?
    wRmin                                                   DD          ?
    wRmax                                                   DD          ?
    wUmin                                                   DD          ?
    wUmax                                                   DD          ?
    wVmin                                                   DD          ?
    wVmax                                                   DD          ?
    wCaps                                                   DD          ?
    wMaxAxes                                                DD          ?
    wNumAxes                                                DD          ?
    wMaxButtons                                             DD          ?
    szRegKey                                                DW          MAXPNAMELEN Dup(?)
    szOEMVxD                                                DW          MAX_JOYSTICKOEMVXDNAME Dup(?)
    ManufacturerGuid                                        GUID        <>
    ProductGuid                                             GUID        <>
    NameGuid                                                GUID        <>
JOYCAPS2W EndS

JOYINFO Struct
    wXpos                                                   DD          ?
    wYpos                                                   DD          ?
    wZpos                                                   DD          ?
    wButtons                                                DD          ?
JOYINFO EndS

JOYINFOEX Struct
    dwSize                                                  DD          ?
    dwFlags                                                 DD          ?
    dwXpos                                                  DD          ?
    dwYpos                                                  DD          ?
    dwZpos                                                  DD          ?
    dwRpos                                                  DD          ?
    dwUpos                                                  DD          ?
    dwVpos                                                  DD          ?
    dwButtons                                               DD          ?
    dwButtonNumber                                          DD          ?
    dwPOV                                                   DD          ?
    dwReserved1                                             DD          ?
    dwReserved2                                             DD          ?
JOYINFOEX EndS

IFDEF APP_UNICODE
    JOYCAPS                                                 Equ     <JOYCAPSW>
    JOYCAPS2                                                Equ     <JOYCAPS2W>
    joyGetDevCaps                                           Equ     <joyGetDevCapsW>
ELSE
    JOYCAPS                                                 Equ     <JOYCAPSA>
    JOYCAPS2                                                Equ     <JOYCAPS2A>
    joyGetDevCaps                                           Equ     <joyGetDevCapsA>
ENDIF

MMIOERR_BASE                                                Equ         256
MMIOERR_FILENOTFOUND                                        Equ         (MMIOERR_BASE + 1)
MMIOERR_OUTOFMEMORY                                         Equ         (MMIOERR_BASE + 2)
MMIOERR_CANNOTOPEN                                          Equ         (MMIOERR_BASE + 3)
MMIOERR_CANNOTCLOSE                                         Equ         (MMIOERR_BASE + 4)
MMIOERR_CANNOTREAD                                          Equ         (MMIOERR_BASE + 5)
MMIOERR_CANNOTWRITE                                         Equ         (MMIOERR_BASE + 6)
MMIOERR_CANNOTSEEK                                          Equ         (MMIOERR_BASE + 7)
MMIOERR_CANNOTEXPAND                                        Equ         (MMIOERR_BASE + 8)
MMIOERR_CHUNKNOTFOUND                                       Equ         (MMIOERR_BASE + 9)
MMIOERR_UNBUFFERED                                          Equ         (MMIOERR_BASE + 10)
MMIOERR_PATHNOTFOUND                                        Equ         (MMIOERR_BASE + 11)
MMIOERR_ACCESSDENIED                                        Equ         (MMIOERR_BASE + 12)
MMIOERR_SHARINGVIOLATION                                    Equ         (MMIOERR_BASE + 13)
MMIOERR_NETWORKERROR                                        Equ         (MMIOERR_BASE + 14)
MMIOERR_TOOMANYOPENFILES                                    Equ         (MMIOERR_BASE + 15)
MMIOERR_INVALIDFILE                                         Equ         (MMIOERR_BASE + 16)

CFSEPCHAR                                                   Equ         A("+")

MMIO_RWMODE                                                 Equ         000000003H
MMIO_SHAREMODE                                              Equ         000000070H

MMIO_CREATE                                                 Equ         000001000H
MMIO_PARSE                                                  Equ         000000100H
MMIO_DELETE                                                 Equ         000000200H
MMIO_EXIST                                                  Equ         000004000H
MMIO_ALLOCBUF                                               Equ         000010000H
MMIO_GETTEMP                                                Equ         000020000H

MMIO_DIRTY                                                  Equ         010000000H

MMIO_READ                                                   Equ         000000000H
MMIO_WRITE                                                  Equ         000000001H
MMIO_READWRITE                                              Equ         000000002H

MMIO_COMPAT                                                 Equ         000000000H
MMIO_EXCLUSIVE                                              Equ         000000010H
MMIO_DENYWRITE                                              Equ         000000020H
MMIO_DENYREAD                                               Equ         000000030H
MMIO_DENYNONE                                               Equ         000000040H

MMIO_FHOPEN                                                 Equ         00010H
MMIO_EMPTYBUF                                               Equ         00010H
MMIO_TOUPPER                                                Equ         00010H
MMIO_INSTALLPROC                                            Equ         000010000H
MMIO_GLOBALPROC                                             Equ         010000000H
MMIO_REMOVEPROC                                             Equ         000020000H
MMIO_UNICODEPROC                                            Equ         001000000H
MMIO_FINDPROC                                               Equ         000040000H
MMIO_FINDCHUNK                                              Equ         00010H
MMIO_FINDRIFF                                               Equ         00020H
MMIO_FINDLIST                                               Equ         00040H
MMIO_CREATERIFF                                             Equ         00020H
MMIO_CREATELIST                                             Equ         00040H

MMIOM_READ                                                  Equ         MMIO_READ
MMIOM_WRITE                                                 Equ         MMIO_WRITE
MMIOM_SEEK                                                  Equ         2
MMIOM_OPEN                                                  Equ         3
MMIOM_CLOSE                                                 Equ         4
MMIOM_WRITEFLUSH                                            Equ         5

MMIOM_RENAME                                                Equ         6

MMIOM_USER                                                  Equ         08000H

FOURCC_RIFF                                                 Equ         A("RIFF")
FOURCC_LIST                                                 Equ         A("LIST")
FOURCC_DOS                                                  Equ         A("DOS ")
FOURCC_MEM                                                  Equ         A("MEM ")

IFNDEF SEEK_SET
    SEEK_SET                                                Equ         0
    SEEK_CUR                                                Equ         1
    SEEK_END                                                Equ         2
ENDIF

MMIO_DEFAULTBUFFER                                          Equ         8192

MMIOINFO Struct
    dwFlags                                                 DD          ?
    fccIOProc                                               DD          ?
    pIOProc                                                 DD          ?
    wErrorRet                                               DD          ?
    htask                                                   HANDLE      ?
    cchBuffer                                               DD          ?
    pchBuffer                                               DD          ?
    pchNext                                                 DD          ?
    pchEndRead                                              DD          ?
    pchEndWrite                                             DD          ?
    lBufOffset                                              DD          ?
    lDiskOffset                                             DD          ?
    adwInfo                                                 DD          3 Dup(?)
    dwReserved1                                             DD          ?
    dwReserved2                                             DD          ?
    hmmio                                                   HANDLE      ?
MMIOINFO EndS

MMCKINFO Struct
    ckid                                                    DD          ?
    cksize                                                  DD          ?
    fccType                                                 DD          ?
    dwDataOffset                                            DD          ?
    dwFlags                                                 DD          ?
MMCKINFO EndS

IFDEF APP_UNICODE
    mmioStringToFOURCC                                      Equ         <mmioStringToFOURCCW>
    mmioInstallIOProc                                       Equ         <mmioInstallIOProcW>
    mmioOpen                                                Equ         <mmioOpenW>
    mmioRename                                              Equ         <mmioRenameW>
ELSE
    mmioStringToFOURCC                                      Equ         <mmioStringToFOURCCA>
    mmioInstallIOProc                                       Equ         <mmioInstallIOProcA>
    mmioOpen                                                Equ         <mmioOpenA>
    mmioRename                                              Equ         <mmioRenameA>
ENDIF

MCIERR_INVALID_DEVICE_ID                                    Equ         (MCIERR_BASE + 1)
MCIERR_UNRECOGNIZED_KEYWORD                                 Equ         (MCIERR_BASE + 3)
MCIERR_UNRECOGNIZED_COMMAND                                 Equ         (MCIERR_BASE + 5)
MCIERR_HARDWARE                                             Equ         (MCIERR_BASE + 6)
MCIERR_INVALID_DEVICE_NAME                                  Equ         (MCIERR_BASE + 7)
MCIERR_OUT_OF_MEMORY                                        Equ         (MCIERR_BASE + 8)
MCIERR_DEVICE_OPEN                                          Equ         (MCIERR_BASE + 9)
MCIERR_CANNOT_LOAD_DRIVER                                   Equ         (MCIERR_BASE + 10)
MCIERR_MISSING_COMMAND_STRING                               Equ         (MCIERR_BASE + 11)
MCIERR_PARAM_OVERFLOW                                       Equ         (MCIERR_BASE + 12)
MCIERR_MISSING_STRING_ARGUMENT                              Equ         (MCIERR_BASE + 13)
MCIERR_BAD_INTEGER                                          Equ         (MCIERR_BASE + 14)
MCIERR_PARSER_INTERNAL                                      Equ         (MCIERR_BASE + 15)
MCIERR_DRIVER_INTERNAL                                      Equ         (MCIERR_BASE + 16)
MCIERR_MISSING_PARAMETER                                    Equ         (MCIERR_BASE + 17)
MCIERR_UNSUPPORTED_FUNCTION                                 Equ         (MCIERR_BASE + 18)
MCIERR_FILE_NOT_FOUND                                       Equ         (MCIERR_BASE + 19)
MCIERR_DEVICE_NOT_READY                                     Equ         (MCIERR_BASE + 20)
MCIERR_INTERNAL                                             Equ         (MCIERR_BASE + 21)
MCIERR_DRIVER                                               Equ         (MCIERR_BASE + 22)
MCIERR_CANNOT_USE_ALL                                       Equ         (MCIERR_BASE + 23)
MCIERR_MULTIPLE                                             Equ         (MCIERR_BASE + 24)
MCIERR_EXTENSION_NOT_FOUND                                  Equ         (MCIERR_BASE + 25)
MCIERR_OUTOFRANGE                                           Equ         (MCIERR_BASE + 26)
MCIERR_FLAGS_NOT_COMPATIBLE                                 Equ         (MCIERR_BASE + 28)
MCIERR_FILE_NOT_SAVED                                       Equ         (MCIERR_BASE + 30)
MCIERR_DEVICE_TYPE_REQUIRED                                 Equ         (MCIERR_BASE + 31)
MCIERR_DEVICE_LOCKED                                        Equ         (MCIERR_BASE + 32)
MCIERR_DUPLICATE_ALIAS                                      Equ         (MCIERR_BASE + 33)
MCIERR_BAD_CONSTANT                                         Equ         (MCIERR_BASE + 34)
MCIERR_MUST_USE_SHAREABLE                                   Equ         (MCIERR_BASE + 35)
MCIERR_MISSING_DEVICE_NAME                                  Equ         (MCIERR_BASE + 36)
MCIERR_BAD_TIME_FORMAT                                      Equ         (MCIERR_BASE + 37)
MCIERR_NO_CLOSING_QUOTE                                     Equ         (MCIERR_BASE + 38)
MCIERR_DUPLICATE_FLAGS                                      Equ         (MCIERR_BASE + 39)
MCIERR_INVALID_FILE                                         Equ         (MCIERR_BASE + 40)
MCIERR_NULL_PARAMETER_BLOCK                                 Equ         (MCIERR_BASE + 41)
MCIERR_UNNAMED_RESOURCE                                     Equ         (MCIERR_BASE + 42)
MCIERR_NEW_REQUIRES_ALIAS                                   Equ         (MCIERR_BASE + 43)
MCIERR_NOTIFY_ON_AUTO_OPEN                                  Equ         (MCIERR_BASE + 44)
MCIERR_NO_ELEMENT_ALLOWED                                   Equ         (MCIERR_BASE + 45)
MCIERR_NONAPPLICABLE_FUNCTION                               Equ         (MCIERR_BASE + 46)
MCIERR_ILLEGAL_FOR_AUTO_OPEN                                Equ         (MCIERR_BASE + 47)
MCIERR_FILENAME_REQUIRED                                    Equ         (MCIERR_BASE + 48)
MCIERR_EXTRA_CHARACTERS                                     Equ         (MCIERR_BASE + 49)
MCIERR_DEVICE_NOT_INSTALLED                                 Equ         (MCIERR_BASE + 50)
MCIERR_GET_CD                                               Equ         (MCIERR_BASE + 51)
MCIERR_SET_CD                                               Equ         (MCIERR_BASE + 52)
MCIERR_SET_DRIVE                                            Equ         (MCIERR_BASE + 53)
MCIERR_DEVICE_LENGTH                                        Equ         (MCIERR_BASE + 54)
MCIERR_DEVICE_ORD_LENGTH                                    Equ         (MCIERR_BASE + 55)
MCIERR_NO_INTEGER                                           Equ         (MCIERR_BASE + 56)
MCIERR_WAVE_OUTPUTSINUSE                                    Equ         (MCIERR_BASE + 64)
MCIERR_WAVE_SETOUTPUTINUSE                                  Equ         (MCIERR_BASE + 65)
MCIERR_WAVE_INPUTSINUSE                                     Equ         (MCIERR_BASE + 66)
MCIERR_WAVE_SETINPUTINUSE                                   Equ         (MCIERR_BASE + 67)
MCIERR_WAVE_OUTPUTUNSPECIFIED                               Equ         (MCIERR_BASE + 68)
MCIERR_WAVE_INPUTUNSPECIFIED                                Equ         (MCIERR_BASE + 69)
MCIERR_WAVE_OUTPUTSUNSUITABLE                               Equ         (MCIERR_BASE + 70)
MCIERR_WAVE_SETOUTPUTUNSUITABLE                             Equ         (MCIERR_BASE + 71)
MCIERR_WAVE_INPUTSUNSUITABLE                                Equ         (MCIERR_BASE + 72)
MCIERR_WAVE_SETINPUTUNSUITABLE                              Equ         (MCIERR_BASE + 73)
MCIERR_SEQ_DIV_INCOMPATIBLE                                 Equ         (MCIERR_BASE + 80)
MCIERR_SEQ_PORT_INUSE                                       Equ         (MCIERR_BASE + 81)
MCIERR_SEQ_PORT_NONEXISTENT                                 Equ         (MCIERR_BASE + 82)
MCIERR_SEQ_PORT_MAPNODEVICE                                 Equ         (MCIERR_BASE + 83)
MCIERR_SEQ_PORT_MISCERROR                                   Equ         (MCIERR_BASE + 84)
MCIERR_SEQ_TIMER                                            Equ         (MCIERR_BASE + 85)
MCIERR_SEQ_PORTUNSPECIFIED                                  Equ         (MCIERR_BASE + 86)
MCIERR_SEQ_NOMIDIPRESENT                                    Equ         (MCIERR_BASE + 87)
MCIERR_NO_WINDOW                                            Equ         (MCIERR_BASE + 90)
MCIERR_CREATEWINDOW                                         Equ         (MCIERR_BASE + 91)
MCIERR_FILE_READ                                            Equ         (MCIERR_BASE + 92)
MCIERR_FILE_WRITE                                           Equ         (MCIERR_BASE + 93)
MCIERR_NO_IDENTITY                                          Equ         (MCIERR_BASE + 94)
MCIERR_CUSTOM_DRIVER_BASE                                   Equ         (MCIERR_BASE + 256)

MCI_FIRST                                                   Equ         DRV_MCI_FIRST

MCI_OPEN                                                    Equ         00803H
MCI_CLOSE                                                   Equ         00804H
MCI_ESCAPE                                                  Equ         00805H
MCI_PLAY                                                    Equ         00806H
MCI_SEEK                                                    Equ         00807H
MCI_STOP                                                    Equ         00808H
MCI_PAUSE                                                   Equ         00809H
MCI_INFO                                                    Equ         0080AH
MCI_GETDEVCAPS                                              Equ         0080BH
MCI_SPIN                                                    Equ         0080CH
MCI_SET                                                     Equ         0080DH
MCI_STEP                                                    Equ         0080EH
MCI_RECORD                                                  Equ         0080FH
MCI_SYSINFO                                                 Equ         00810H
MCI_BREAK                                                   Equ         00811H
MCI_SAVE                                                    Equ         00813H
MCI_STATUS                                                  Equ         00814H
MCI_CUE                                                     Equ         00830H
MCI_REALIZE                                                 Equ         00840H
MCI_WINDOW                                                  Equ         00841H
MCI_PUT                                                     Equ         00842H
MCI_WHERE                                                   Equ         00843H
MCI_FREEZE                                                  Equ         00844H
MCI_UNFREEZE                                                Equ         00845H
MCI_LOAD                                                    Equ         00850H
MCI_CUT                                                     Equ         00851H
MCI_COPY                                                    Equ         00852H
MCI_PASTE                                                   Equ         00853H
MCI_UPDATE                                                  Equ         00854H
MCI_RESUME                                                  Equ         00855H
MCI_DELETE                                                  Equ         00856H

MCI_USER_MESSAGES                                           Equ         (DRV_MCI_FIRST + 0400H)
MCI_LAST                                                    Equ         00FFFH

MCI_ALL_DEVICE_ID                                           Equ         (MCIDEVICEID-1)

MCI_DEVTYPE_VCR                                             Equ         513
MCI_DEVTYPE_VIDEODISC                                       Equ         514
MCI_DEVTYPE_OVERLAY                                         Equ         515
MCI_DEVTYPE_CD_AUDIO                                        Equ         516
MCI_DEVTYPE_DAT                                             Equ         517
MCI_DEVTYPE_SCANNER                                         Equ         518
MCI_DEVTYPE_ANIMATION                                       Equ         519
MCI_DEVTYPE_DIGITAL_VIDEO                                   Equ         520
MCI_DEVTYPE_OTHER                                           Equ         521
MCI_DEVTYPE_WAVEFORM_AUDIO                                  Equ         522
MCI_DEVTYPE_SEQUENCER                                       Equ         523

MCI_DEVTYPE_FIRST                                           Equ         MCI_DEVTYPE_VCR
MCI_DEVTYPE_LAST                                            Equ         MCI_DEVTYPE_SEQUENCER

MCI_DEVTYPE_FIRST_USER                                      Equ         01000H

MCI_MODE_NOT_READY                                          Equ         (MCI_STRING_OFFSET + 12)
MCI_MODE_STOP                                               Equ         (MCI_STRING_OFFSET + 13)
MCI_MODE_PLAY                                               Equ         (MCI_STRING_OFFSET + 14)
MCI_MODE_RECORD                                             Equ         (MCI_STRING_OFFSET + 15)
MCI_MODE_SEEK                                               Equ         (MCI_STRING_OFFSET + 16)
MCI_MODE_PAUSE                                              Equ         (MCI_STRING_OFFSET + 17)
MCI_MODE_OPEN                                               Equ         (MCI_STRING_OFFSET + 18)

MCI_FORMAT_MILLISECONDS                                     Equ         0
MCI_FORMAT_HMS                                              Equ         1
MCI_FORMAT_MSF                                              Equ         2
MCI_FORMAT_FRAMES                                           Equ         3
MCI_FORMAT_SMPTE_24                                         Equ         4
MCI_FORMAT_SMPTE_25                                         Equ         5
MCI_FORMAT_SMPTE_30                                         Equ         6
MCI_FORMAT_SMPTE_30DROP                                     Equ         7
MCI_FORMAT_BYTES                                            Equ         8
MCI_FORMAT_SAMPLES                                          Equ         9
MCI_FORMAT_TMSF                                             Equ         10


MCI_NOTIFY_SUCCESSFUL                                       Equ         00001H
MCI_NOTIFY_SUPERSEDED                                       Equ         00002H
MCI_NOTIFY_ABORTED                                          Equ         00004H
MCI_NOTIFY_FAILURE                                          Equ         00008H

MCI_NOTIFY                                                  Equ         000000001H
MCI_WAIT                                                    Equ         000000002H
MCI_FROM                                                    Equ         000000004H
MCI_TO                                                      Equ         000000008H
MCI_TRACK                                                   Equ         000000010H

MCI_OPEN_SHAREABLE                                          Equ         000000100H
MCI_OPEN_ELEMENT                                            Equ         000000200H
MCI_OPEN_ALIAS                                              Equ         000000400H
MCI_OPEN_ELEMENT_ID                                         Equ         000000800H
MCI_OPEN_TYPE_ID                                            Equ         000001000H
MCI_OPEN_TYPE                                               Equ         000002000H

MCI_SEEK_TO_START                                           Equ         000000100H
MCI_SEEK_TO_END                                             Equ         000000200H

MCI_STATUS_ITEM                                             Equ         000000100H
MCI_STATUS_START                                            Equ         000000200H

MCI_STATUS_LENGTH                                           Equ         000000001H
MCI_STATUS_POSITION                                         Equ         000000002H
MCI_STATUS_NUMBER_OF_TRACKS                                 Equ         000000003H
MCI_STATUS_MODE                                             Equ         000000004H
MCI_STATUS_MEDIA_PRESENT                                    Equ         000000005H
MCI_STATUS_TIME_FORMAT                                      Equ         000000006H
MCI_STATUS_READY                                            Equ         000000007H
MCI_STATUS_CURRENT_TRACK                                    Equ         000000008H

MCI_INFO_PRODUCT                                            Equ         000000100H
MCI_INFO_FILE                                               Equ         000000200H
MCI_INFO_MEDIA_UPC                                          Equ         000000400H
MCI_INFO_MEDIA_IDENTITY                                     Equ         000000800H
MCI_INFO_NAME                                               Equ         000001000H
MCI_INFO_COPYRIGHT                                          Equ         000002000H

MCI_GETDEVCAPS_ITEM                                         Equ         000000100H

MCI_GETDEVCAPS_CAN_RECORD                                   Equ         000000001H
MCI_GETDEVCAPS_HAS_AUDIO                                    Equ         000000002H
MCI_GETDEVCAPS_HAS_VIDEO                                    Equ         000000003H
MCI_GETDEVCAPS_DEVICE_TYPE                                  Equ         000000004H
MCI_GETDEVCAPS_USES_FILES                                   Equ         000000005H
MCI_GETDEVCAPS_COMPOUND_DEVICE                              Equ         000000006H
MCI_GETDEVCAPS_CAN_EJECT                                    Equ         000000007H
MCI_GETDEVCAPS_CAN_PLAY                                     Equ         000000008H
MCI_GETDEVCAPS_CAN_SAVE                                     Equ         000000009H

MCI_SYSINFO_QUANTITY                                        Equ         000000100H
MCI_SYSINFO_OPEN                                            Equ         000000200H
MCI_SYSINFO_NAME                                            Equ         000000400H
MCI_SYSINFO_INSTALLNAME                                     Equ         000000800H

MCI_SET_DOOR_OPEN                                           Equ         000000100H
MCI_SET_DOOR_CLOSED                                         Equ         000000200H
MCI_SET_TIME_FORMAT                                         Equ         000000400H
MCI_SET_AUDIO                                               Equ         000000800H
MCI_SET_VIDEO                                               Equ         000001000H
MCI_SET_ON                                                  Equ         000002000H
MCI_SET_OFF                                                 Equ         000004000H

MCI_SET_AUDIO_ALL                                           Equ         000000000H
MCI_SET_AUDIO_LEFT                                          Equ         000000001H
MCI_SET_AUDIO_RIGHT                                         Equ         000000002H

MCI_BREAK_KEY                                               Equ         000000100H
MCI_BREAK_HWND                                              Equ         000000200H
MCI_BREAK_OFF                                               Equ         000000400H

MCI_RECORD_INSERT                                           Equ         000000100H
MCI_RECORD_OVERWRITE                                        Equ         000000200H

MCI_SAVE_FILE                                               Equ         000000100H

MCI_LOAD_FILE                                               Equ         000000100H

MCI_VD_MODE_PARK                                            Equ         (MCI_VD_OFFSET + 1)

MCI_VD_MEDIA_CLV                                            Equ         (MCI_VD_OFFSET + 2)
MCI_VD_MEDIA_CAV                                            Equ         (MCI_VD_OFFSET + 3)
MCI_VD_MEDIA_OTHER                                          Equ         (MCI_VD_OFFSET + 4)

MCI_VD_FORMAT_TRACK                                         Equ         04001H

MCI_VD_PLAY_REVERSE                                         Equ         000010000H
MCI_VD_PLAY_FAST                                            Equ         000020000H
MCI_VD_PLAY_SPEED                                           Equ         000040000H
MCI_VD_PLAY_SCAN                                            Equ         000080000H
MCI_VD_PLAY_SLOW                                            Equ         000100000H

MCI_VD_SEEK_REVERSE                                         Equ         000010000H

MCI_VD_STATUS_SPEED                                         Equ         000004002H
MCI_VD_STATUS_FORWARD                                       Equ         000004003H
MCI_VD_STATUS_MEDIA_TYPE                                    Equ         000004004H
MCI_VD_STATUS_SIDE                                          Equ         000004005H
MCI_VD_STATUS_DISC_SIZE                                     Equ         000004006H

MCI_VD_GETDEVCAPS_CLV                                       Equ         000010000H
MCI_VD_GETDEVCAPS_CAV                                       Equ         000020000H

MCI_VD_SPIN_UP                                              Equ         000010000H
MCI_VD_SPIN_DOWN                                            Equ         000020000H

MCI_VD_GETDEVCAPS_CAN_REVERSE                               Equ         000004002H
MCI_VD_GETDEVCAPS_FAST_RATE                                 Equ         000004003H
MCI_VD_GETDEVCAPS_SLOW_RATE                                 Equ         000004004H
MCI_VD_GETDEVCAPS_NORMAL_RATE                               Equ         000004005H

MCI_VD_STEP_FRAMES                                          Equ         000010000H
MCI_VD_STEP_REVERSE                                         Equ         000020000H

MCI_VD_ESCAPE_STRING                                        Equ         000000100H

MCI_CDA_STATUS_TYPE_TRACK                                   Equ         000004001H

MCI_CDA_TRACK_AUDIO                                         Equ         (MCI_CD_OFFSET + 0)
MCI_CDA_TRACK_OTHER                                         Equ         (MCI_CD_OFFSET + 1)

MCI_WAVE_PCM                                                Equ         (MCI_WAVE_OFFSET + 0)
MCI_WAVE_MAPPER                                             Equ         (MCI_WAVE_OFFSET + 1)

MCI_WAVE_OPEN_BUFFER                                        Equ         000010000H

MCI_WAVE_SET_FORMATTAG                                      Equ         000010000H
MCI_WAVE_SET_CHANNELS                                       Equ         000020000H
MCI_WAVE_SET_SAMPLESPERSEC                                  Equ         000040000H
MCI_WAVE_SET_AVGBYTESPERSEC                                 Equ         000080000H
MCI_WAVE_SET_BLOCKALIGN                                     Equ         000100000H
MCI_WAVE_SET_BITSPERSAMPLE                                  Equ         000200000H

MCI_WAVE_INPUT                                              Equ         000400000H
MCI_WAVE_OUTPUT                                             Equ         000800000H

MCI_WAVE_STATUS_FORMATTAG                                   Equ         000004001H
MCI_WAVE_STATUS_CHANNELS                                    Equ         000004002H
MCI_WAVE_STATUS_SAMPLESPERSEC                               Equ         000004003H
MCI_WAVE_STATUS_AVGBYTESPERSEC                              Equ         000004004H
MCI_WAVE_STATUS_BLOCKALIGN                                  Equ         000004005H
MCI_WAVE_STATUS_BITSPERSAMPLE                               Equ         000004006H
MCI_WAVE_STATUS_LEVEL                                       Equ         000004007H

MCI_WAVE_SET_ANYINPUT                                       Equ         004000000H
MCI_WAVE_SET_ANYOUTPUT                                      Equ         008000000H

MCI_WAVE_GETDEVCAPS_INPUTS                                  Equ         000004001H
MCI_WAVE_GETDEVCAPS_OUTPUTS                                 Equ         000004002H

MCI_SEQ_DIV_PPQN                                            Equ         (0 + MCI_SEQ_OFFSET)
MCI_SEQ_DIV_SMPTE_24                                        Equ         (1 + MCI_SEQ_OFFSET)
MCI_SEQ_DIV_SMPTE_25                                        Equ         (2 + MCI_SEQ_OFFSET)
MCI_SEQ_DIV_SMPTE_30DROP                                    Equ         (3 + MCI_SEQ_OFFSET)
MCI_SEQ_DIV_SMPTE_30                                        Equ         (4 + MCI_SEQ_OFFSET)

MCI_SEQ_FORMAT_SONGPTR                                      Equ         04001H
MCI_SEQ_FILE                                                Equ         04002H
MCI_SEQ_MIDI                                                Equ         04003H
MCI_SEQ_SMPTE                                               Equ         04004H
MCI_SEQ_NONE                                                Equ         65533
MCI_SEQ_MAPPER                                              Equ         65535

MCI_SEQ_STATUS_TEMPO                                        Equ         000004002H
MCI_SEQ_STATUS_PORT                                         Equ         000004003H
MCI_SEQ_STATUS_SLAVE                                        Equ         000004007H
MCI_SEQ_STATUS_MASTER                                       Equ         000004008H
MCI_SEQ_STATUS_OFFSET                                       Equ         000004009H
MCI_SEQ_STATUS_DIVTYPE                                      Equ         00000400AH
MCI_SEQ_STATUS_NAME                                         Equ         00000400BH
MCI_SEQ_STATUS_COPYRIGHT                                    Equ         00000400CH

MCI_SEQ_SET_TEMPO                                           Equ         000010000H
MCI_SEQ_SET_PORT                                            Equ         000020000H
MCI_SEQ_SET_SLAVE                                           Equ         000040000H
MCI_SEQ_SET_MASTER                                          Equ         000080000H
MCI_SEQ_SET_OFFSET                                          Equ         001000000H

MCI_ANIM_OPEN_WS                                            Equ         000010000H
MCI_ANIM_OPEN_PARENT                                        Equ         000020000H
MCI_ANIM_OPEN_NOSTATIC                                      Equ         000040000H

MCI_ANIM_PLAY_SPEED                                         Equ         000010000H
MCI_ANIM_PLAY_REVERSE                                       Equ         000020000H
MCI_ANIM_PLAY_FAST                                          Equ         000040000H
MCI_ANIM_PLAY_SLOW                                          Equ         000080000H
MCI_ANIM_PLAY_SCAN                                          Equ         000100000H

MCI_ANIM_STEP_REVERSE                                       Equ         000010000H
MCI_ANIM_STEP_FRAMES                                        Equ         000020000H

MCI_ANIM_STATUS_SPEED                                       Equ         000004001H
MCI_ANIM_STATUS_FORWARD                                     Equ         000004002H
MCI_ANIM_STATUS_HWND                                        Equ         000004003H
MCI_ANIM_STATUS_HPAL                                        Equ         000004004H
MCI_ANIM_STATUS_STRETCH                                     Equ         000004005H

MCI_ANIM_INFO_TEXT                                          Equ         000010000H

MCI_ANIM_GETDEVCAPS_CAN_REVERSE                             Equ         000004001H
MCI_ANIM_GETDEVCAPS_FAST_RATE                               Equ         000004002H
MCI_ANIM_GETDEVCAPS_SLOW_RATE                               Equ         000004003H
MCI_ANIM_GETDEVCAPS_NORMAL_RATE                             Equ         000004004H
MCI_ANIM_GETDEVCAPS_PALETTES                                Equ         000004006H
MCI_ANIM_GETDEVCAPS_CAN_STRETCH                             Equ         000004007H
MCI_ANIM_GETDEVCAPS_MAX_WINDOWS                             Equ         000004008H

MCI_ANIM_REALIZE_NORM                                       Equ         000010000H
MCI_ANIM_REALIZE_BKGD                                       Equ         000020000H

MCI_ANIM_WINDOW_HWND                                        Equ         000010000H
MCI_ANIM_WINDOW_STATE                                       Equ         000040000H
MCI_ANIM_WINDOW_TEXT                                        Equ         000080000H
MCI_ANIM_WINDOW_ENABLE_STRETCH                              Equ         000100000H
MCI_ANIM_WINDOW_DISABLE_STRETCH                             Equ         000200000H

MCI_ANIM_WINDOW_DEFAULT                                     Equ         000000000H

MCI_ANIM_RECT                                               Equ         000010000H
MCI_ANIM_PUT_SOURCE                                         Equ         000020000H
MCI_ANIM_PUT_DESTINATION                                    Equ         000040000H

MCI_ANIM_WHERE_SOURCE                                       Equ         000020000H
MCI_ANIM_WHERE_DESTINATION                                  Equ         000040000H

MCI_ANIM_UPDATE_HDC                                         Equ         000020000H

MCI_OVLY_OPEN_WS                                            Equ         000010000H
MCI_OVLY_OPEN_PARENT                                        Equ         000020000H

MCI_OVLY_STATUS_HWND                                        Equ         000004001H
MCI_OVLY_STATUS_STRETCH                                     Equ         000004002H

MCI_OVLY_INFO_TEXT                                          Equ         000010000H

MCI_OVLY_GETDEVCAPS_CAN_STRETCH                             Equ         000004001H
MCI_OVLY_GETDEVCAPS_CAN_FREEZE                              Equ         000004002H
MCI_OVLY_GETDEVCAPS_MAX_WINDOWS                             Equ         000004003H

MCI_OVLY_WINDOW_HWND                                        Equ         000010000H
MCI_OVLY_WINDOW_STATE                                       Equ         000040000H
MCI_OVLY_WINDOW_TEXT                                        Equ         000080000H
MCI_OVLY_WINDOW_ENABLE_STRETCH                              Equ         000100000H
MCI_OVLY_WINDOW_DISABLE_STRETCH                             Equ         000200000H

MCI_OVLY_WINDOW_DEFAULT                                     Equ         000000000H

MCI_OVLY_RECT                                               Equ         000010000H
MCI_OVLY_PUT_SOURCE                                         Equ         000020000H
MCI_OVLY_PUT_DESTINATION                                    Equ         000040000H
MCI_OVLY_PUT_FRAME                                          Equ         000080000H
MCI_OVLY_PUT_VIDEO                                          Equ         000100000H

MCI_OVLY_WHERE_SOURCE                                       Equ         000020000H
MCI_OVLY_WHERE_DESTINATION                                  Equ         000040000H
MCI_OVLY_WHERE_FRAME                                        Equ         000080000H
MCI_OVLY_WHERE_VIDEO                                        Equ         000100000H

MCI_GENERIC_PARMS Struct
    dwCallback                                              DD          ?
MCI_GENERIC_PARMS EndS

MCI_OPEN_PARMSA Struct
    dwCallback                                              DD          ?
    wDeviceID                                               DD          ?
    lpstrDeviceType                                         DD          ?
    lpstrElementName                                        DD          ?
    lpstrAlias                                              DD          ?
MCI_OPEN_PARMSA EndS

MCI_OPEN_PARMSW Struct
    dwCallback                                              DD          ?
    wDeviceID                                               DD          ?
    lpstrDeviceType                                         DD          ?
    lpstrElementName                                        DD          ?
    lpstrAlias                                              DD          ?
MCI_OPEN_PARMSW EndS

MCI_PLAY_PARMS Struct
    dwCallback                                              DD          ?
    dwFrom                                                  DD          ?
    dwTo                                                    DD          ?
MCI_PLAY_PARMS EndS

MCI_SEEK_PARMS Struct
    dwCallback                                              DD          ?
    dwTo                                                    DD          ?
MCI_SEEK_PARMS EndS

MCI_STATUS_PARMS Struct
    dwCallback                                              DD          ?
    dwReturn                                                DD          ?
    dwItem                                                  DD          ?
    dwTrack                                                 DD          ?
MCI_STATUS_PARMS EndS

MCI_INFO_PARMSA Struct
    dwCallback                                              DD          ?
    lpstrReturn                                             DD          ?
    dwRetSize                                               DD          ?
MCI_INFO_PARMSA EndS

MCI_INFO_PARMSW Struct
    dwCallback                                              DD          ?
    lpstrReturn                                             DD          ?
    dwRetSize                                               DD          ?
MCI_INFO_PARMSW EndS

MCI_GETDEVCAPS_PARMS Struct
    dwCallback                                              DD          ?
    dwReturn                                                DD          ?
    dwItem                                                  DD          ?
MCI_GETDEVCAPS_PARMS EndS

MCI_SYSINFO_PARMSA Struct
    dwCallback                                              DD          ?
    lpstrReturn                                             DD          ?
    dwRetSize                                               DD          ?
    dwNumber                                                DD          ?
    wDeviceType                                             DD          ?
MCI_SYSINFO_PARMSA EndS

MCI_SYSINFO_PARMSW Struct
    dwCallback                                              DD          ?
    lpstrReturn                                             DD          ?
    dwRetSize                                               DD          ?
    dwNumber                                                DD          ?
    wDeviceType                                             DD          ?
MCI_SYSINFO_PARMSW EndS

MCI_SET_PARMS Struct
    dwCallback                                              DD          ?
    dwTimeFormat                                            DD          ?
    dwAudio                                                 DD          ?
MCI_SET_PARMS EndS

MCI_BREAK_PARMS Struct
    dwCallback                                              DD          ?
    nVirtKey                                                DD          ?
    hwndBreak                                               HANDLE      ?
MCI_BREAK_PARMS EndS

MCI_SAVE_PARMSA Struct
    dwCallback                                              DD          ?
    lpfilename                                              DD          ?
MCI_SAVE_PARMSA EndS

MCI_SAVE_PARMSW Struct
    dwCallback                                              DD          ?
    lpfilename                                              DD          ?
MCI_SAVE_PARMSW EndS

MCI_LOAD_PARMSA Struct
    dwCallback                                              DD          ?
    lpfilename                                              DD          ?
MCI_LOAD_PARMSA EndS

MCI_LOAD_PARMSW Struct
    dwCallback                                              DD          ?
    lpfilename                                              DD          ?
MCI_LOAD_PARMSW EndS

MCI_RECORD_PARMSA Struct
    dwCallback                                              DD          ?
    dwFrom                                                  DD          ?
    dwTo                                                    DD          ?
MCI_RECORD_PARMSA EndS

MCI_RECORD_PARMSW Struct
    dwCallback                                              DD          ?
    dwFrom                                                  DD          ?
    dwTo                                                    DD          ?
MCI_RECORD_PARMSW EndS

MCI_VD_PLAY_PARMS Struct
    dwCallback                                              DD          ?
    dwFrom                                                  DD          ?
    dwTo                                                    DD          ?
    dwSpeed                                                 DD          ?
MCI_VD_PLAY_PARMS EndS

MCI_VD_STEP_PARMS Struct
    dwCallback                                              DD          ?
    dwFrames                                                DD          ?
MCI_VD_STEP_PARMS EndS

MCI_VD_ESCAPE_PARMSA Struct
    dwCallback                                              DD          ?
    lpstrCommand                                            DD          ?
MCI_VD_ESCAPE_PARMSA EndS

MCI_VD_ESCAPE_PARMSW Struct
    dwCallback                                              DD          ?
    lpstrCommand                                            DD          ?
MCI_VD_ESCAPE_PARMSW EndS

MCI_WAVE_OPEN_PARMSA Struct
    dwCallback                                              DD          ?
    wDeviceID                                               DD          ?
    lpstrDeviceType                                         DD          ?
    lpstrElementName                                        DD          ?
    lpstrAlias                                              DD          ?
    dwBufferSeconds                                         DD          ?
MCI_WAVE_OPEN_PARMSA EndS

MCI_WAVE_OPEN_PARMSW Struct
    dwCallback                                              DD          ?
    wDeviceID                                               DD          ?
    lpstrDeviceType                                         DD          ?
    lpstrElementName                                        DD          ?
    lpstrAlias                                              DD          ?
    dwBufferSeconds                                         DD          ?
MCI_WAVE_OPEN_PARMSW EndS

MCI_WAVE_DELETE_PARMS Struct
    dwCallback                                              DD          ?
    dwFrom                                                  DD          ?
    dwTo                                                    DD          ?
MCI_WAVE_DELETE_PARMS EndS

MCI_WAVE_SET_PARMS Struct
    dwCallback                                              DD          ?
    dwTimeFormat                                            DD          ?
    dwAudio                                                 DD          ?
    wInput                                                  DD          ?
    wOutput                                                 DD          ?
    wFormatTag                                              DW          ?
    wReserved2                                              DW          ?
    nChannels                                               DW          ?
    wReserved3                                              DW          ?
    nSamplesPerSec                                          DD          ?
    nAvgBytesPerSec                                         DD          ?
    nBlockAlign                                             DW          ?
    wReserved4                                              DW          ?
    wBitsPerSample                                          DW          ?
    wReserved5                                              DW          ?
MCI_WAVE_SET_PARMS EndS

MCI_SEQ_SET_PARMS Struct
    dwCallback                                              DD          ?
    dwTimeFormat                                            DD          ?
    dwAudio                                                 DD          ?
    dwTempo                                                 DD          ?
    dwPort                                                  DD          ?
    dwSlave                                                 DD          ?
    dwMaster                                                DD          ?
    dwOffset                                                DD          ?
MCI_SEQ_SET_PARMS EndS

MCI_ANIM_OPEN_PARMSA Struct
    dwCallback                                              DD          ?
    wDeviceID                                               DD          ?
    lpstrDeviceType                                         DD          ?
    lpstrElementName                                        DD          ?
    lpstrAlias                                              DD          ?
    dwStyle                                                 DD          ?
    hWndParent                                              HANDLE      ?
MCI_ANIM_OPEN_PARMSA EndS

MCI_ANIM_OPEN_PARMSW Struct
    dwCallback                                              DD          ?
    wDeviceID                                               DD          ?
    lpstrDeviceType                                         DD          ?
    lpstrElementName                                        DD          ?
    lpstrAlias                                              DD          ?
    dwStyle                                                 DD          ?
    hWndParent                                              HANDLE      ?
MCI_ANIM_OPEN_PARMSW EndS

MCI_ANIM_PLAY_PARMS Struct
    dwCallback                                              DD          ?
    dwFrom                                                  DD          ?
    dwTo                                                    DD          ?
    dwSpeed                                                 DD          ?
MCI_ANIM_PLAY_PARMS EndS

MCI_ANIM_STEP_PARMS Struct
    dwCallback                                              DD          ?
    dwFrames                                                DD          ?
MCI_ANIM_STEP_PARMS EndS

MCI_ANIM_WINDOW_PARMSA Struct
    dwCallback                                              DD          ?
    Union
        hWnd                                                HANDLE      ?
        hwnd                                                HANDLE      ?
    EndS
    nCmdShow                                                DD          ?
    lpstrText                                               DD          ?
MCI_ANIM_WINDOW_PARMSA EndS

MCI_ANIM_WINDOW_PARMSW Struct
    dwCallback                                              DD          ?
    Union
        hWnd                                                HANDLE      ?
        hwnd                                                HANDLE      ?
    EndS
    nCmdShow                                                DD          ?
    lpstrText                                               DD          ?
MCI_ANIM_WINDOW_PARMSW EndS

MCI_ANIM_RECT_PARMS Struct
    dwCallback                                              DD          ?
    rc                                                      RECT        <>
    ENDIF
MCI_ANIM_RECT_PARMS EndS

MCI_ANIM_UPDATE_PARMS Struct
    dwCallback                                              DD          ?
    rc                                                      RECT        <>
    hDC                                                     HANDLE      ?
MCI_ANIM_UPDATE_PARMS EndS

MCI_OVLY_OPEN_PARMSA Struct
    dwCallback                                              DD          ?
    wDeviceID                                               DD          ?
    lpstrDeviceType                                         DD          ?
    lpstrElementName                                        DD          ?
    lpstrAlias                                              DD          ?
    dwStyle                                                 DD          ?
    hWndParent                                              HANDLE      ?
MCI_OVLY_OPEN_PARMSA EndS

MCI_OVLY_OPEN_PARMSW Struct
    dwCallback                                              DD          ?
    wDeviceID                                               DD          ?
    lpstrDeviceType                                         DD          ?
    lpstrElementName                                        DD          ?
    lpstrAlias                                              DD          ?
    dwStyle                                                 DD          ?
    hWndParent                                              HANDLE      ?
MCI_OVLY_OPEN_PARMSW EndS

MCI_OVLY_WINDOW_PARMSA Struct
    dwCallback                                              DD          ?
    hWnd                                                    HANDLE      ?
    nCmdShow                                                DD          ?
    lpstrText                                               DD          ?
MCI_OVLY_WINDOW_PARMSA EndS

MCI_OVLY_WINDOW_PARMSW Struct
    dwCallback                                              DD          ?
    hWnd                                                    HANDLE      ?
    nCmdShow                                                DD          ?
    lpstrText                                               DD          ?
MCI_OVLY_WINDOW_PARMSW EndS

MCI_OVLY_RECT_PARMS Struct
    dwCallback                                              DD          ?
    rc                                                      RECT        <>
    ENDIF
MCI_OVLY_RECT_PARMS EndS

MCI_OVLY_SAVE_PARMSA Struct
    dwCallback                                              DD          ?
    lpfilename                                              DD          ?
    rc                                                      RECT        <>
MCI_OVLY_SAVE_PARMSA EndS

MCI_OVLY_SAVE_PARMSW Struct
    dwCallback                                              DD          ?
    lpfilename                                              DD          ?
    rc                                                      RECT        <>
MCI_OVLY_SAVE_PARMSW EndS

MCI_OVLY_LOAD_PARMSA Struct
    dwCallback                                              DD          ?
    lpfilename                                              DD          ?
    rc                                                      RECT        <>
MCI_OVLY_LOAD_PARMSA EndS

MCI_OVLY_LOAD_PARMSW Struct
    dwCallback                                              DD          ?
    lpfilename                                              DD          ?
    rc                                                      RECT        <>
MCI_OVLY_LOAD_PARMSW EndS

IFDEF APP_UNICODE
    mciSendCommand                                          Equ         <mciSendCommandW>
    mciSendString                                           Equ         <mciSendStringW>
    mciGetDeviceID                                          Equ         <mciGetDeviceIDW>
    mciGetErrorString                                       Equ         <mciGetErrorStringW>
    MCI_OPEN_PARMS                                          Equ         <MCI_OPEN_PARMSW>
    MCI_INFO_PARMS                                          Equ         <MCI_INFO_PARMSW>
    MCI_SYSINFO_PARMS                                       Equ         <MCI_SYSINFO_PARMSW>
    MCI_SAVE_PARMS                                          Equ         <MCI_SAVE_PARMSW>
    MCI_LOAD_PARMS                                          Equ         <MCI_LOAD_PARMSW>
    MCI_RECORD_PARMS                                        Equ         <MCI_RECORD_PARMSW>
    MCI_VD_ESCAPE_PARMS                                     Equ         <MCI_VD_ESCAPE_PARMSW>
    MCI_WAVE_OPEN_PARMS                                     Equ         <MCI_WAVE_OPEN_PARMSW>
    MCI_ANIM_OPEN_PARMS                                     Equ         <MCI_ANIM_OPEN_PARMSW>
    MCI_ANIM_WINDOW_PARMS                                   Equ         <MCI_ANIM_WINDOW_PARMSW>
    MCI_OVLY_OPEN_PARMS                                     Equ         <MCI_OVLY_OPEN_PARMSW>
    MCI_OVLY_WINDOW_PARMS                                   Equ         <MCI_OVLY_WINDOW_PARMSW>
    MCI_OVLY_SAVE_PARMS                                     Equ         <MCI_OVLY_SAVE_PARMSW>
    MCI_OVLY_LOAD_PARMS                                     Equ         <MCI_OVLY_LOAD_PARMSW>
ELSE
    mciSendCommand                                          Equ         <mciSendCommandA>
    mciSendString                                           Equ         <mciSendStringA>
    mciGetDeviceID                                          Equ         <mciGetDeviceIDA>
    mciGetErrorString                                       Equ         <mciGetErrorStringA>
    MCI_OPEN_PARMS                                          Equ         <MCI_OPEN_PARMSA>
    MCI_INFO_PARMS                                          Equ         <MCI_INFO_PARMSA>
    MCI_SYSINFO_PARMS                                       Equ         <MCI_SYSINFO_PARMSA>
    MCI_SAVE_PARMS                                          Equ         <MCI_SAVE_PARMSA>
    MCI_LOAD_PARMS                                          Equ         <MCI_LOAD_PARMSA>
    MCI_RECORD_PARMS                                        Equ         <MCI_RECORD_PARMSA>
    MCI_VD_ESCAPE_PARMS                                     Equ         <MCI_VD_ESCAPE_PARMSA>
    MCI_WAVE_OPEN_PARMS                                     Equ         <MCI_WAVE_OPEN_PARMSA>
    MCI_ANIM_OPEN_PARMS                                     Equ         <MCI_ANIM_OPEN_PARMSA>
    MCI_ANIM_WINDOW_PARMS                                   Equ         <MCI_ANIM_WINDOW_PARMSA>
    MCI_OVLY_OPEN_PARMS                                     Equ         <MCI_OVLY_OPEN_PARMSA>
    MCI_OVLY_WINDOW_PARMS                                   Equ         <MCI_OVLY_WINDOW_PARMSA>
    MCI_OVLY_SAVE_PARMS                                     Equ         <MCI_OVLY_SAVE_PARMSA>
    MCI_OVLY_LOAD_PARMS                                     Equ         <MCI_OVLY_LOAD_PARMSA>
ENDIF

NEWTRANSPARENT                                              Equ         3
QUERYROPSUPPORT                                             Equ         40
SELECTDIB                                                   Equ         41

ENDIF ;MMSYSTEM_INC
