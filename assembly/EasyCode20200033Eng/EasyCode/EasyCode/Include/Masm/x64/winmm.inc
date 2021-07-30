; =======================================================;
;                                                        ;
;    winmm.inc for Easy Code 2.0 64-bit Masm projects    ;
;                  (version 1.0.6)                       ;
;                                                        ;
;         Copyright © Ramon Sala - 2015-2018             ;
;                                                        ;
; =======================================================;

IFNDEF WINMM_INC
WINMM_INC   EQU     1

MAXPNAMELEN                                     EQU     32
MAXERRORLENGTH                                  EQU     256
MAX_JOYSTICKOEMVXDNAME                          EQU     260

IFNDEF MM_MICROSOFT
    MM_MICROSOFT                                EQU     1
ENDIF

IFNDEF MM_MIDI_MAPPER
    MM_MIDI_MAPPER                              EQU     1
    MM_WAVE_MAPPER                              EQU     2
    MM_SNDBLST_MIDIOUT                          EQU     3
    MM_SNDBLST_MIDIIN                           EQU     4
    MM_SNDBLST_SYNTH                            EQU     5
    MM_SNDBLST_WAVEOUT                          EQU     6
    MM_SNDBLST_WAVEIN                           EQU     7
    MM_ADLIB                                    EQU     9
    MM_MPU401_MIDIOUT                           EQU     10
    MM_MPU401_MIDIIN                            EQU     11
    MM_PC_JOYSTICK                              EQU     12
ENDIF

TIME_MS                                         EQU     0001H
TIME_SAMPLES                                    EQU     0002H
TIME_BYTES                                      EQU     0004H
TIME_SMPTE                                      EQU     0008H
TIME_MIDI                                       EQU     0010H
TIME_TICKS                                      EQU     0020H

MM_JOY1MOVE                                     EQU     03A0H
MM_JOY2MOVE                                     EQU     03A1H
MM_JOY1ZMOVE                                    EQU     03A2H
MM_JOY2ZMOVE                                    EQU     03A3H
MM_JOY1BUTTONDOWN                               EQU     03B5H
MM_JOY2BUTTONDOWN                               EQU     03B6H
MM_JOY1BUTTONUP                                 EQU     03B7H
MM_JOY2BUTTONUP                                 EQU     03B8H

MM_MCINOTIFY                                    EQU     03B9H

MM_WOM_OPEN                                     EQU     03BBH
MM_WOM_CLOSE                                    EQU     03BCH
MM_WOM_DONE                                     EQU     03BDH

MM_WIM_OPEN                                     EQU     03BEH
MM_WIM_CLOSE                                    EQU     03BFH
MM_WIM_DATA                                     EQU     03C0H

MM_MIM_OPEN                                     EQU     03C1H
MM_MIM_CLOSE                                    EQU     03C2H
MM_MIM_DATA                                     EQU     03C3H
MM_MIM_LONGDATA                                 EQU     03C4H
MM_MIM_ERROR                                    EQU     03C5H
MM_MIM_LONGERROR                                EQU     03C6H

MM_MOM_OPEN                                     EQU     03C7H
MM_MOM_CLOSE                                    EQU     03C8H
MM_MOM_DONE                                     EQU     03C9H

IFNDEF MM_DRVM_OPEN
    MM_DRVM_OPEN                                EQU     03D0H
    MM_DRVM_CLOSE                               EQU     03D1H
    MM_DRVM_DATA                                EQU     03D2H
    MM_DRVM_ERROR                               EQU     03D3H
ENDIF

MM_STREAM_OPEN                                  EQU     03D4H
MM_STREAM_CLOSE                                 EQU     03D5H
MM_STREAM_DONE                                  EQU     03D6H
MM_STREAM_ERROR                                 EQU     03D7H

MM_MOM_POSITIONCB                               EQU     03CAH

IFNDEF MM_MCISIGNAL
    MM_MCISIGNAL                                EQU     03CBH
ENDIF

MM_MIM_MOREDATA                                 EQU     03CCH

MM_MIXM_LINE_CHANGE                             EQU     03D0H
MM_MIXM_CONTROL_CHANGE                          EQU     03D1H

MMSYSERR_BASE                                   EQU     0
WAVERR_BASE                                     EQU     32
MIDIERR_BASE                                    EQU     64
TIMERR_BASE                                     EQU     96
JOYERR_BASE                                     EQU     160
MCIERR_BASE                                     EQU     256
MIXERR_BASE                                     EQU     1024

MCI_STRING_OFFSET                               EQU     512
MCI_VD_OFFSET                                   EQU     1024
MCI_CD_OFFSET                                   EQU     1088
MCI_WAVE_OFFSET                                 EQU     1152
MCI_SEQ_OFFSET                                  EQU     1216

MMSYSERR_NOERROR                                EQU     0
MMSYSERR_ERROR                                  EQU     (MMSYSERR_BASE + 1)
MMSYSERR_BADDEVICEID                            EQU     (MMSYSERR_BASE + 2)
MMSYSERR_NOTENABLED                             EQU     (MMSYSERR_BASE + 3)
MMSYSERR_ALLOCATED                              EQU     (MMSYSERR_BASE + 4)
MMSYSERR_INVALHANDLE                            EQU     (MMSYSERR_BASE + 5)
MMSYSERR_NODRIVER                               EQU     (MMSYSERR_BASE + 6)
MMSYSERR_NOMEM                                  EQU     (MMSYSERR_BASE + 7)
MMSYSERR_NOTSUPPORTED                           EQU     (MMSYSERR_BASE + 8)
MMSYSERR_BADERRNUM                              EQU     (MMSYSERR_BASE + 9)
MMSYSERR_INVALFLAG                              EQU     (MMSYSERR_BASE + 10)
MMSYSERR_INVALPARAM                             EQU     (MMSYSERR_BASE + 11)
MMSYSERR_HANDLEBUSY                             EQU     (MMSYSERR_BASE + 12)

MMSYSERR_INVALIDALIAS                           EQU     (MMSYSERR_BASE + 13)
MMSYSERR_BADDB                                  EQU     (MMSYSERR_BASE + 14)
MMSYSERR_KEYNOTFOUND                            EQU     (MMSYSERR_BASE + 15)
MMSYSERR_READERROR                              EQU     (MMSYSERR_BASE + 16)
MMSYSERR_WRITEERROR                             EQU     (MMSYSERR_BASE + 17)
MMSYSERR_DELETEERROR                            EQU     (MMSYSERR_BASE + 18)
MMSYSERR_VALNOTFOUND                            EQU     (MMSYSERR_BASE + 19)
MMSYSERR_NODRIVERCB                             EQU     (MMSYSERR_BASE + 20)
MMSYSERR_MOREDATA                               EQU     (MMSYSERR_BASE + 21)
MMSYSERR_LASTERROR                              EQU     (MMSYSERR_BASE + 21)

IFNDEF DRV_LOAD
    DRV_LOAD                                    EQU     00001H
    DRV_ENABLE                                  EQU     00002H
    DRV_OPEN                                    EQU     00003H
    DRV_CLOSE                                   EQU     00004H
    DRV_DISABLE                                 EQU     00005H
    DRV_FREE                                    EQU     00006H
    DRV_CONFIGURE                               EQU     00007H
    DRV_QUERYCONFIGURE                          EQU     00008H
    DRV_INSTALL                                 EQU     00009H
    DRV_REMOVE                                  EQU     0000AH
    DRV_EXITSESSION                             EQU     0000BH
    DRV_POWER                                   EQU     0000FH
    DRV_RESERVED                                EQU     00800H
    DRV_USER                                    EQU     04000H
    
    DRVCNF_CANCEL                               EQU     00000H
    DRVCNF_OK                                   EQU     00001H
    DRVCNF_RESTART                              EQU     00002H
ENDIF

DRV_CANCEL                                     EQU     DRVCNF_CANCEL
DRV_OK                                         EQU     DRVCNF_OK
DRV_RESTART                                    EQU     DRVCNF_RESTART

DRV_MCI_FIRST                                  EQU     DRV_RESERVED
DRV_MCI_LAST                                   EQU     (DRV_RESERVED + 0FFFH)

CALLBACK_TYPEMASK                              EQU     000070000H
CALLBACK_NULL                                  EQU     000000000H
CALLBACK_WINDOW                                EQU     000010000H
CALLBACK_TASK                                  EQU     000020000H
CALLBACK_FUNCTION                              EQU     000030000H
CALLBACK_THREAD                                EQU     CALLBACK_TASK
CALLBACK_EVENT                                 EQU     000050000H

SND_SYNC                                       EQU     00000H
SND_ASYNC                                      EQU     00001H
SND_NODEFAULT                                  EQU     00002H
SND_MEMORY                                     EQU     00004H
SND_LOOP                                       EQU     00008H
SND_NOSTOP                                     EQU     00010H

SND_PURGE                                      EQU     00040H
SND_APPLICATION                                EQU     00080H

SND_NOWAIT                                     EQU     000002000H
SND_ALIAS                                      EQU     000010000H
SND_ALIAS_ID                                   EQU     000110000H
SND_FILENAME                                   EQU     000020000H
SND_RESOURCE                                   EQU     000040004H

SND_ALIAS_START                                EQU     0

SND_ALIAS_SYSTEMASTERISK                       EQU     ((SND_ALIAS_START + 53h+2Ah) or ((53h + 2Ah) shl 8))
SND_ALIAS_SYSTEMQUESTION                       EQU     ((SND_ALIAS_START + 53h+3Fh) or ((53h + 3Fh) shl 8))
SND_ALIAS_SYSTEMHAND                           EQU     ((SND_ALIAS_START + 53h+48h) or ((53h + 48h) shl 8))
SND_ALIAS_SYSTEMEXIT                           EQU     ((SND_ALIAS_START + 53h+45h) or ((53h + 45h) shl 8))
SND_ALIAS_SYSTEMSTART                          EQU     ((SND_ALIAS_START + 53h+53h) or ((53h + 53h) shl 8))
SND_ALIAS_SYSTEMWELCOME                        EQU     ((SND_ALIAS_START + 53h+57h) or ((53h + 57h) shl 8))
SND_ALIAS_SYSTEMEXCLAMATION                    EQU     ((SND_ALIAS_START + 53h+21h) or ((53h + 21h) shl 8))
SND_ALIAS_SYSTEMDEFAULT                        EQU     ((SND_ALIAS_START + 53h+44h) or ((53h + 44h) shl 8))

WAVERR_BADFORMAT                               EQU     (WAVERR_BASE+0)
WAVERR_STILLPLAYING                            EQU     (WAVERR_BASE+1)
WAVERR_UNPREPARED                              EQU     (WAVERR_BASE+2)
WAVERR_SYNC                                    EQU     (WAVERR_BASE+3)
WAVERR_LASTERROR                               EQU     (WAVERR_BASE+3)

WOM_OPEN                                       EQU     MM_WOM_OPEN
WOM_CLOSE                                      EQU     MM_WOM_CLOSE
WOM_DONE                                       EQU     MM_WOM_DONE
WIM_OPEN                                       EQU     MM_WIM_OPEN
WIM_CLOSE                                      EQU     MM_WIM_CLOSE
WIM_DATA                                       EQU     MM_WIM_DATA

WAVE_MAPPER                                    EQU     (-1)

WAVE_FORMAT_QUERY                              EQU     00001H
WAVE_ALLOWSYNC                                 EQU     00002H
WAVE_MAPPED                                    EQU     00004H
WAVE_FORMAT_DIRECT                             EQU     00008H
WAVE_FORMAT_DIRECT_QUERY                       EQU     (WAVE_FORMAT_QUERY or WAVE_FORMAT_DIRECT)

WHDR_DONE                                      EQU     000000001H
WHDR_PREPARED                                  EQU     000000002H
WHDR_BEGINLOOP                                 EQU     000000004H
WHDR_ENDLOOP                                   EQU     000000008H
WHDR_INQUEUE                                   EQU     000000010H

WAVECAPS_PITCH                                 EQU     00001H
WAVECAPS_PLAYBACKRATE                          EQU     00002H
WAVECAPS_VOLUME                                EQU     00004H
WAVECAPS_LRVOLUME                              EQU     00008H
WAVECAPS_SYNC                                  EQU     00010H
WAVECAPS_SAMPLEACCURATE                        EQU     00020H

WAVE_INVALIDFORMAT                             EQU     00000000H
WAVE_FORMAT_1M08                               EQU     00000001H
WAVE_FORMAT_1S08                               EQU     00000002H
WAVE_FORMAT_1M16                               EQU     00000004H
WAVE_FORMAT_1S16                               EQU     00000008H
WAVE_FORMAT_2M08                               EQU     00000010H
WAVE_FORMAT_2S08                               EQU     00000020H
WAVE_FORMAT_2M16                               EQU     00000040H
WAVE_FORMAT_2S16                               EQU     00000080H
WAVE_FORMAT_4M08                               EQU     00000100H
WAVE_FORMAT_4S08                               EQU     00000200H
WAVE_FORMAT_4M16                               EQU     00000400H
WAVE_FORMAT_4S16                               EQU     00000800H
WAVE_FORMAT_44M08                              EQU     00000100H
WAVE_FORMAT_44S08                              EQU     00000200H
WAVE_FORMAT_44M16                              EQU     00000400H
WAVE_FORMAT_44S16                              EQU     00000800H
WAVE_FORMAT_48M08                              EQU     00001000H
WAVE_FORMAT_48S08                              EQU     00002000H
WAVE_FORMAT_48M16                              EQU     00004000H
WAVE_FORMAT_48S16                              EQU     00008000H
WAVE_FORMAT_96M08                              EQU     00010000H
WAVE_FORMAT_96S08                              EQU     00020000H
WAVE_FORMAT_96M16                              EQU     00040000H
WAVE_FORMAT_96S16                              EQU     00080000H

MIDIERR_UNPREPARED                             EQU     (MIDIERR_BASE + 0)
MIDIERR_STILLPLAYING                           EQU     (MIDIERR_BASE + 1)
MIDIERR_NOMAP                                  EQU     (MIDIERR_BASE + 2)
MIDIERR_NOTREADY                               EQU     (MIDIERR_BASE + 3)
MIDIERR_NODEVICE                               EQU     (MIDIERR_BASE + 4)
MIDIERR_INVALIDSETUP                           EQU     (MIDIERR_BASE + 5)
MIDIERR_BADOPENMODE                            EQU     (MIDIERR_BASE + 6)
MIDIERR_DONT_CONTINUE                          EQU     (MIDIERR_BASE + 7)
MIDIERR_LASTERROR                              EQU     (MIDIERR_BASE + 7)

MIM_OPEN                                       EQU     MM_MIM_OPEN
MIM_CLOSE                                      EQU     MM_MIM_CLOSE
MIM_DATA                                       EQU     MM_MIM_DATA
MIM_LONGDATA                                   EQU     MM_MIM_LONGDATA
MIM_ERROR                                      EQU     MM_MIM_ERROR
MIM_LONGERROR                                  EQU     MM_MIM_LONGERROR
MOM_OPEN                                       EQU     MM_MOM_OPEN
MOM_CLOSE                                      EQU     MM_MOM_CLOSE
MOM_DONE                                       EQU     MM_MOM_DONE

MIM_MOREDATA                                   EQU     MM_MIM_MOREDATA
MOM_POSITIONCB                                 EQU     MM_MOM_POSITIONCB

MIDIMAPPER                                     EQU     (-1)
MIDI_MAPPER                                    EQU     (-1)

MIDI_IO_STATUS                                 EQU     00000020H

MIDI_CACHE_ALL                                 EQU     1
MIDI_CACHE_BESTFIT                             EQU     2
MIDI_CACHE_QUERY                               EQU     3
MIDI_UNCACHE                                   EQU     4

MOD_MIDIPORT                                   EQU     1
MOD_SYNTH                                      EQU     2
MOD_SQSYNTH                                    EQU     3
MOD_FMSYNTH                                    EQU     4
MOD_MAPPER                                     EQU     5
MOD_WAVETABLE                                  EQU     6
MOD_SWSYNTH                                    EQU     7

MIDICAPS_VOLUME                                EQU     00001H
MIDICAPS_LRVOLUME                              EQU     00002H
MIDICAPS_CACHE                                 EQU     00004H
MIDICAPS_STREAM                                EQU     00008H

MHDR_DONE                                      EQU     00000001H
MHDR_PREPARED                                  EQU     00000002H
MHDR_INQUEUE                                   EQU     00000004H
MHDR_ISSTRM                                    EQU     00000008H

MEVT_F_SHORT                                   EQU     00000000H
MEVT_F_LONG                                    EQU     80000000H
MEVT_F_CALLBACK                                EQU     40000000H


MEVT_SHORTMSG                                  EQU     0
MEVT_TEMPO                                     EQU     1
MEVT_NO                                        EQU     2

MEVT_LONGMSG                                   EQU     080H
MEVT_COMMENT                                   EQU     082H
MEVT_VERSION                                   EQU     084H

MIDISTRM_ERROR                                 EQU     (-2)

MIDIPROP_SET                                   EQU     80000000H
MIDIPROP_GET                                   EQU     40000000H

MIDIPROP_TIMEDIV                               EQU     00000001H
MIDIPROP_TEMPO                                 EQU     00000002H

MIDIPATCHSIZE                                  EQU     128

AUX_MAPPER                                     EQU     (-1)

AUXCAPS_CDAUDIO                                EQU     1
AUXCAPS_AUXIN                                  EQU     2
AUXCAPS_VOLUME                                 EQU     00001H
AUXCAPS_LRVOLUME                               EQU     00002H

MIXER_SHORT_NAME_CHARS                         EQU     16
MIXER_LONG_NAME_CHARS                          EQU     64

MIXERR_INVALLINE                               EQU     (MIXERR_BASE+0)
MIXERR_INVALCONTROL                            EQU     (MIXERR_BASE+1)
MIXERR_INVALVALUE                              EQU     (MIXERR_BASE+2)
MIXERR_LASTERROR                               EQU     (MIXERR_BASE+2)

MIXER_OBJECTF_HANDLE                           EQU     80000000H
MIXER_OBJECTF_MIXER                            EQU     00000000H
MIXER_OBJECTF_HMIXER                           EQU     (MIXER_OBJECTF_HANDLE or MIXER_OBJECTF_MIXER)
MIXER_OBJECTF_WAVEOUT                          EQU     10000000H
MIXER_OBJECTF_HWAVEOUT                         EQU     (MIXER_OBJECTF_HANDLE or MIXER_OBJECTF_WAVEOUT)
MIXER_OBJECTF_WAVEIN                           EQU     20000000H
MIXER_OBJECTF_HWAVEIN                          EQU     (MIXER_OBJECTF_HANDLE or MIXER_OBJECTF_WAVEIN)
MIXER_OBJECTF_MIDIOUT                          EQU     30000000H
MIXER_OBJECTF_HMIDIOUT                         EQU     (MIXER_OBJECTF_HANDLE or MIXER_OBJECTF_MIDIOUT)
MIXER_OBJECTF_MIDIIN                           EQU     40000000H
MIXER_OBJECTF_HMIDIIN                          EQU     (MIXER_OBJECTF_HANDLE or MIXER_OBJECTF_MIDIIN)
MIXER_OBJECTF_AUX                              EQU     50000000H

MIXERLINE_LINEF_ACTIVE                         EQU     00000001H
MIXERLINE_LINEF_DISCONNECTED                   EQU     00008000H
MIXERLINE_LINEF_SOURCE                         EQU     80000000H

MIXERLINE_COMPONENTTYPE_DST_FIRST              EQU     000000000H
MIXERLINE_COMPONENTTYPE_DST_UNDEFINED          EQU     (MIXERLINE_COMPONENTTYPE_DST_FIRST + 0)
MIXERLINE_COMPONENTTYPE_DST_DIGITAL            EQU     (MIXERLINE_COMPONENTTYPE_DST_FIRST + 1)
MIXERLINE_COMPONENTTYPE_DST_LINE               EQU     (MIXERLINE_COMPONENTTYPE_DST_FIRST + 2)
MIXERLINE_COMPONENTTYPE_DST_MONITOR            EQU     (MIXERLINE_COMPONENTTYPE_DST_FIRST + 3)
MIXERLINE_COMPONENTTYPE_DST_SPEAKERS           EQU     (MIXERLINE_COMPONENTTYPE_DST_FIRST + 4)
MIXERLINE_COMPONENTTYPE_DST_HEADPHONES         EQU     (MIXERLINE_COMPONENTTYPE_DST_FIRST + 5)
MIXERLINE_COMPONENTTYPE_DST_TELEPHONE          EQU     (MIXERLINE_COMPONENTTYPE_DST_FIRST + 6)
MIXERLINE_COMPONENTTYPE_DST_WAVEIN             EQU     (MIXERLINE_COMPONENTTYPE_DST_FIRST + 7)
MIXERLINE_COMPONENTTYPE_DST_VOICEIN            EQU     (MIXERLINE_COMPONENTTYPE_DST_FIRST + 8)
MIXERLINE_COMPONENTTYPE_DST_LAST               EQU     (MIXERLINE_COMPONENTTYPE_DST_FIRST + 8)

MIXERLINE_COMPONENTTYPE_SRC_FIRST              EQU     00001000H
MIXERLINE_COMPONENTTYPE_SRC_UNDEFINED          EQU     (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 0)
MIXERLINE_COMPONENTTYPE_SRC_DIGITAL            EQU     (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 1)
MIXERLINE_COMPONENTTYPE_SRC_LINE               EQU     (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 2)
MIXERLINE_COMPONENTTYPE_SRC_MICROPHONE         EQU     (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 3)
MIXERLINE_COMPONENTTYPE_SRC_SYNTHESIZER        EQU     (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 4)
MIXERLINE_COMPONENTTYPE_SRC_COMPACTDISC        EQU     (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 5)
MIXERLINE_COMPONENTTYPE_SRC_TELEPHONE          EQU     (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 6)
MIXERLINE_COMPONENTTYPE_SRC_PCSPEAKER          EQU     (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 7)
MIXERLINE_COMPONENTTYPE_SRC_WAVEOUT            EQU     (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 8)
MIXERLINE_COMPONENTTYPE_SRC_AUXILIARY          EQU     (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 9)
MIXERLINE_COMPONENTTYPE_SRC_ANALOG             EQU     (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 10)
MIXERLINE_COMPONENTTYPE_SRC_LAST               EQU     (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 10)

MIXERLINE_TARGETTYPE_UNDEFINED                 EQU     0
MIXERLINE_TARGETTYPE_WAVEOUT                   EQU     1
MIXERLINE_TARGETTYPE_WAVEIN                    EQU     2
MIXERLINE_TARGETTYPE_MIDIOUT                   EQU     3
MIXERLINE_TARGETTYPE_MIDIIN                    EQU     4
MIXERLINE_TARGETTYPE_AUX                       EQU     5

MIXER_GETLINEINFOF_DESTINATION                 EQU     00000000H
MIXER_GETLINEINFOF_SOURCE                      EQU     00000001H
MIXER_GETLINEINFOF_LINEID                      EQU     00000002H
MIXER_GETLINEINFOF_COMPONENTTYPE               EQU     00000003H
MIXER_GETLINEINFOF_TARGETTYPE                  EQU     00000004H
MIXER_GETLINEINFOF_QUERYMASK                   EQU     0000000FH

MIXERCONTROL_CONTROLF_UNIFORM                  EQU     00000001H
MIXERCONTROL_CONTROLF_MULTIPLE                 EQU     00000002H
MIXERCONTROL_CONTROLF_DISABLED                 EQU     80000000H

MIXERCONTROL_CT_CLASS_MASK                     EQU     0F0000000H
MIXERCONTROL_CT_CLASS_CUSTOM                   EQU     00000000H
MIXERCONTROL_CT_CLASS_METER                    EQU     10000000H
MIXERCONTROL_CT_CLASS_SWITCH                   EQU     20000000H
MIXERCONTROL_CT_CLASS_NUMBER                   EQU     30000000H
MIXERCONTROL_CT_CLASS_SLIDER                   EQU     40000000H
MIXERCONTROL_CT_CLASS_FADER                    EQU     50000000H
MIXERCONTROL_CT_CLASS_TIME                     EQU     60000000H
MIXERCONTROL_CT_CLASS_LIST                     EQU     70000000H

MIXERCONTROL_CT_SUBCLASS_MASK                  EQU     0F000000H

MIXERCONTROL_CT_SC_SWITCH_BOOLEAN              EQU     00000000H
MIXERCONTROL_CT_SC_SWITCH_BUTTON               EQU     01000000H

MIXERCONTROL_CT_SC_METER_POLLED                EQU     00000000H

MIXERCONTROL_CT_SC_TIME_MICROSECS              EQU     00000000H
MIXERCONTROL_CT_SC_TIME_MILLISECS              EQU     01000000H

MIXERCONTROL_CT_SC_LIST_SINGLE                 EQU     00000000H
MIXERCONTROL_CT_SC_LIST_MULTIPLE               EQU     01000000H

MIXERCONTROL_CT_UNITS_MASK                     EQU     00FF0000H
MIXERCONTROL_CT_UNITS_CUSTOM                   EQU     00000000H
MIXERCONTROL_CT_UNITS_BOOLEAN                  EQU     00010000H
MIXERCONTROL_CT_UNITS_SIGNED                   EQU     00020000H
MIXERCONTROL_CT_UNITS_UNSIGNED                 EQU     00030000H
MIXERCONTROL_CT_UNITS_DECIBELS                 EQU     00040000H
MIXERCONTROL_CT_UNITS_PERCENT                  EQU     00050000H

MIXERCONTROL_CONTROLTYPE_CUSTOM                EQU     (MIXERCONTROL_CT_CLASS_CUSTOM or MIXERCONTROL_CT_UNITS_CUSTOM)
MIXERCONTROL_CONTROLTYPE_BOOLEANMETER          EQU     (MIXERCONTROL_CT_CLASS_METER or MIXERCONTROL_CT_SC_METER_POLLED or MIXERCONTROL_CT_UNITS_BOOLEAN)
MIXERCONTROL_CONTROLTYPE_SIGNEDMETER           EQU     (MIXERCONTROL_CT_CLASS_METER or MIXERCONTROL_CT_SC_METER_POLLED or MIXERCONTROL_CT_UNITS_SIGNED)
MIXERCONTROL_CONTROLTYPE_PEAKMETER             EQU     (MIXERCONTROL_CONTROLTYPE_SIGNEDMETER + 1)
MIXERCONTROL_CONTROLTYPE_UNSIGNEDMETER         EQU     (MIXERCONTROL_CT_CLASS_METER or MIXERCONTROL_CT_SC_METER_POLLED or MIXERCONTROL_CT_UNITS_UNSIGNED)
MIXERCONTROL_CONTROLTYPE_BOOLEAN               EQU     (MIXERCONTROL_CT_CLASS_SWITCH or MIXERCONTROL_CT_SC_SWITCH_BOOLEAN or MIXERCONTROL_CT_UNITS_BOOLEAN)
MIXERCONTROL_CONTROLTYPE_ONOFF                 EQU     (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 1)
MIXERCONTROL_CONTROLTYPE_MUTE                  EQU     (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 2)
MIXERCONTROL_CONTROLTYPE_MONO                  EQU     (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 3)
MIXERCONTROL_CONTROLTYPE_LOUDNESS              EQU     (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 4)
MIXERCONTROL_CONTROLTYPE_STEREOENH             EQU     (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 5)
MIXERCONTROL_CONTROLTYPE_BASS_BOOST            EQU     (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 00002277H)
MIXERCONTROL_CONTROLTYPE_BUTTON                EQU     (MIXERCONTROL_CT_CLASS_SWITCH or MIXERCONTROL_CT_SC_SWITCH_BUTTON or MIXERCONTROL_CT_UNITS_BOOLEAN)
MIXERCONTROL_CONTROLTYPE_DECIBELS              EQU     (MIXERCONTROL_CT_CLASS_NUMBER or MIXERCONTROL_CT_UNITS_DECIBELS)
MIXERCONTROL_CONTROLTYPE_SIGNED                EQU     (MIXERCONTROL_CT_CLASS_NUMBER or MIXERCONTROL_CT_UNITS_SIGNED)
MIXERCONTROL_CONTROLTYPE_UNSIGNED              EQU     (MIXERCONTROL_CT_CLASS_NUMBER or MIXERCONTROL_CT_UNITS_UNSIGNED)
MIXERCONTROL_CONTROLTYPE_PERCENT               EQU     (MIXERCONTROL_CT_CLASS_NUMBER or MIXERCONTROL_CT_UNITS_PERCENT)
MIXERCONTROL_CONTROLTYPE_SLIDER                EQU     (MIXERCONTROL_CT_CLASS_SLIDER or MIXERCONTROL_CT_UNITS_SIGNED)
MIXERCONTROL_CONTROLTYPE_PAN                   EQU     (MIXERCONTROL_CONTROLTYPE_SLIDER + 1)
MIXERCONTROL_CONTROLTYPE_QSOUNDPAN             EQU     (MIXERCONTROL_CONTROLTYPE_SLIDER + 2)
MIXERCONTROL_CONTROLTYPE_FADER                 EQU     (MIXERCONTROL_CT_CLASS_FADER or MIXERCONTROL_CT_UNITS_UNSIGNED)
MIXERCONTROL_CONTROLTYPE_VOLUME                EQU     (MIXERCONTROL_CONTROLTYPE_FADER + 1)
MIXERCONTROL_CONTROLTYPE_BASS                  EQU     (MIXERCONTROL_CONTROLTYPE_FADER + 2)
MIXERCONTROL_CONTROLTYPE_TREBLE                EQU     (MIXERCONTROL_CONTROLTYPE_FADER + 3)
MIXERCONTROL_CONTROLTYPE_EQUALIZER             EQU     (MIXERCONTROL_CONTROLTYPE_FADER + 4)
MIXERCONTROL_CONTROLTYPE_SINGLESELECT          EQU     (MIXERCONTROL_CT_CLASS_LIST or MIXERCONTROL_CT_SC_LIST_SINGLE or MIXERCONTROL_CT_UNITS_BOOLEAN)
MIXERCONTROL_CONTROLTYPE_MUX                   EQU     (MIXERCONTROL_CONTROLTYPE_SINGLESELECT + 1)
MIXERCONTROL_CONTROLTYPE_MULTIPLESELECT        EQU     (MIXERCONTROL_CT_CLASS_LIST or MIXERCONTROL_CT_SC_LIST_MULTIPLE or MIXERCONTROL_CT_UNITS_BOOLEAN)
MIXERCONTROL_CONTROLTYPE_MIXER                 EQU     (MIXERCONTROL_CONTROLTYPE_MULTIPLESELECT + 1)
MIXERCONTROL_CONTROLTYPE_MICROTIME             EQU     (MIXERCONTROL_CT_CLASS_TIME or MIXERCONTROL_CT_SC_TIME_MICROSECS or MIXERCONTROL_CT_UNITS_UNSIGNED)
MIXERCONTROL_CONTROLTYPE_MILLITIME             EQU     (MIXERCONTROL_CT_CLASS_TIME or MIXERCONTROL_CT_SC_TIME_MILLISECS or MIXERCONTROL_CT_UNITS_UNSIGNED)

MIXER_GETLINECONTROLSF_ALL                     EQU     00000000H
MIXER_GETLINECONTROLSF_ONEBYID                 EQU     00000001H
MIXER_GETLINECONTROLSF_ONEBYTYPE               EQU     00000002H
MIXER_GETLINECONTROLSF_QUERYMASK               EQU     0000000FH

MIXER_GETCONTROLDETAILSF_VALUE                 EQU     00000000H
MIXER_GETCONTROLDETAILSF_LISTTEXT              EQU     00000001H
MIXER_GETCONTROLDETAILSF_QUERYMASK             EQU     0000000FH

MIXER_SETCONTROLDETAILSF_VALUE                 EQU     00000000H
MIXER_SETCONTROLDETAILSF_CUSTOM                EQU     00000001H
MIXER_SETCONTROLDETAILSF_QUERYMASK             EQU     0000000FH

TIMERR_NOERROR                                 EQU     0
TIMERR_NOCANDO                                 EQU     (TIMERR_BASE + 1)
TIMERR_STRUCT                                  EQU     (TIMERR_BASE + 33)

TIME_ONESHOT                                   EQU     0000H
TIME_PERIODIC                                  EQU     0001H

TIME_CALLBACK_FUNCTION                         EQU     0000H
TIME_CALLBACK_EVENT_SET                        EQU     0010H
TIME_CALLBACK_EVENT_PULSE                      EQU     0020H

TIME_KILL_SYNCHRONOUS                          EQU     0100H

JOYERR_NOERROR                                 EQU     0
JOYERR_PARMS                                   EQU     (JOYERR_BASE + 5)
JOYERR_NOCANDO                                 EQU     (JOYERR_BASE + 6)
JOYERR_UNPLUGGED                               EQU     (JOYERR_BASE + 7)

JOY_BUTTON1                                    EQU     0001H
JOY_BUTTON2                                    EQU     0002H
JOY_BUTTON3                                    EQU     0004H
JOY_BUTTON4                                    EQU     0008H
JOY_BUTTON1CHG                                 EQU     0100H
JOY_BUTTON2CHG                                 EQU     0200H
JOY_BUTTON3CHG                                 EQU     0400H
JOY_BUTTON4CHG                                 EQU     0800H

JOY_BUTTON5                                    EQU     00000010H
JOY_BUTTON6                                    EQU     00000020H
JOY_BUTTON7                                    EQU     00000040H
JOY_BUTTON8                                    EQU     00000080H
JOY_BUTTON9                                    EQU     00000100H
JOY_BUTTON10                                   EQU     00000200H
JOY_BUTTON11                                   EQU     00000400H
JOY_BUTTON12                                   EQU     00000800H
JOY_BUTTON13                                   EQU     00001000H
JOY_BUTTON14                                   EQU     00002000H
JOY_BUTTON15                                   EQU     00004000H
JOY_BUTTON16                                   EQU     00008000H
JOY_BUTTON17                                   EQU     00010000H
JOY_BUTTON18                                   EQU     00020000H
JOY_BUTTON19                                   EQU     00040000H
JOY_BUTTON20                                   EQU     00080000H
JOY_BUTTON21                                   EQU     00100000H
JOY_BUTTON22                                   EQU     00200000H
JOY_BUTTON23                                   EQU     00400000H
JOY_BUTTON24                                   EQU     00800000H
JOY_BUTTON25                                   EQU     01000000H
JOY_BUTTON26                                   EQU     02000000H
JOY_BUTTON27                                   EQU     04000000H
JOY_BUTTON28                                   EQU     08000000H
JOY_BUTTON29                                   EQU     10000000H
JOY_BUTTON30                                   EQU     20000000H
JOY_BUTTON31                                   EQU     40000000H
JOY_BUTTON32                                   EQU     80000000H

JOY_POVCENTERED                                EQU     (-1)
JOY_POVFORWARD                                 EQU     0
JOY_POVRIGHT                                   EQU     9000
JOY_POVBACKWARD                                EQU     18000
JOY_POVLEFT                                    EQU     27000

JOY_RETURNX                                    EQU     00000001H
JOY_RETURNY                                    EQU     00000002H
JOY_RETURNZ                                    EQU     00000004H
JOY_RETURNR                                    EQU     00000008H
JOY_RETURNU                                    EQU     00000010H
JOY_RETURNV                                    EQU     00000020H
JOY_RETURNPOV                                  EQU     00000040H
JOY_RETURNBUTTONS                              EQU     00000080H
JOY_RETURNRAWDATA                              EQU     00000100H
JOY_RETURNPOVCTS                               EQU     00000200H
JOY_RETURNCENTERED                             EQU     00000400H
JOY_USEDEADZONE                                EQU     00000800H
JOY_RETURNALL                                  EQU     (JOY_RETURNX or JOY_RETURNY or JOY_RETURNZ or JOY_RETURNR or JOY_RETURNU or JOY_RETURNV or JOY_RETURNPOV or JOY_RETURNBUTTONS)
JOY_CAL_READALWAYS                             EQU     00010000H
JOY_CAL_READXYONLY                             EQU     00020000H
JOY_CAL_READ3                                  EQU     00040000H
JOY_CAL_READ4                                  EQU     00080000H
JOY_CAL_READXONLY                              EQU     00100000H
JOY_CAL_READYONLY                              EQU     00200000H
JOY_CAL_READ5                                  EQU     00400000H
JOY_CAL_READ6                                  EQU     00800000H
JOY_CAL_READZONLY                              EQU     01000000H
JOY_CAL_READRONLY                              EQU     02000000H
JOY_CAL_READUONLY                              EQU     04000000H
JOY_CAL_READVONLY                              EQU     08000000H

JOYSTICKID1                                    EQU     0
JOYSTICKID2                                    EQU     1

JOYCAPS_HASZ                                   EQU     0001H
JOYCAPS_HASR                                   EQU     0002H
JOYCAPS_HASU                                   EQU     0004H
JOYCAPS_HASV                                   EQU     0008H
JOYCAPS_HASPOV                                 EQU     0010H
JOYCAPS_POV4DIR                                EQU     0020H
JOYCAPS_POVCTS                                 EQU     0040H

MMIOERR_BASE                                   EQU     256
MMIOERR_FILENOTFOUND                           EQU     (MMIOERR_BASE + 1)
MMIOERR_OUTOFMEMORY                            EQU     (MMIOERR_BASE + 2)
MMIOERR_CANNOTOPEN                             EQU     (MMIOERR_BASE + 3)
MMIOERR_CANNOTCLOSE                            EQU     (MMIOERR_BASE + 4)
MMIOERR_CANNOTREAD                             EQU     (MMIOERR_BASE + 5)
MMIOERR_CANNOTWRITE                            EQU     (MMIOERR_BASE + 6)
MMIOERR_CANNOTSEEK                             EQU     (MMIOERR_BASE + 7)
MMIOERR_CANNOTEXPAND                           EQU     (MMIOERR_BASE + 8)
MMIOERR_CHUNKNOTFOUND                          EQU     (MMIOERR_BASE + 9)
MMIOERR_UNBUFFERED                             EQU     (MMIOERR_BASE + 10)
MMIOERR_PATHNOTFOUND                           EQU     (MMIOERR_BASE + 11)
MMIOERR_ACCESSDENIED                           EQU     (MMIOERR_BASE + 12)
MMIOERR_SHARINGVIOLATION                       EQU     (MMIOERR_BASE + 13)
MMIOERR_NETWORKERROR                           EQU     (MMIOERR_BASE + 14)
MMIOERR_TOOMANYOPENFILES                       EQU     (MMIOERR_BASE + 15)
MMIOERR_INVALIDFILE                            EQU     (MMIOERR_BASE + 16)

CFSEPCHAR                                      EQU     '+'

MMIO_RWMODE                                    EQU     00000003H
MMIO_SHAREMODE                                 EQU     00000070H

MMIO_CREATE                                    EQU     00001000H
MMIO_PARSE                                     EQU     00000100H
MMIO_DELETE                                    EQU     00000200H
MMIO_EXIST                                     EQU     00004000H
MMIO_ALLOCBUF                                  EQU     00010000H
MMIO_GETTEMP                                   EQU     00020000H

MMIO_DIRTY                                     EQU     10000000H

MMIO_READ                                      EQU     00000000H
MMIO_WRITE                                     EQU     00000001H
MMIO_READWRITE                                 EQU     00000002H

MMIO_COMPAT                                    EQU     00000000H
MMIO_EXCLUSIVE                                 EQU     00000010H
MMIO_DENYWRITE                                 EQU     00000020H
MMIO_DENYREAD                                  EQU     00000030H
MMIO_DENYNONE                                  EQU     00000040H

MMIO_FHOPEN                                    EQU     0010H
MMIO_EMPTYBUF                                  EQU     0010H
MMIO_TOUPPER                                   EQU     0010H
MMIO_INSTALLPROC                               EQU     00010000H
MMIO_GLOBALPROC                                EQU     10000000H
MMIO_REMOVEPROC                                EQU     00020000H
MMIO_UNICODEPROC                               EQU     01000000H
MMIO_FINDPROC                                  EQU     00040000H
MMIO_FINDCHUNK                                 EQU     0010H
MMIO_FINDRIFF                                  EQU     0020H
MMIO_FINDLIST                                  EQU     0040H
MMIO_CREATERIFF                                EQU     0020H
MMIO_CREATELIST                                EQU     0040H

MMIOM_READ                                     EQU     MMIO_READ
MMIOM_WRITE                                    EQU     MMIO_WRITE
MMIOM_SEEK                                     EQU     2
MMIOM_OPEN                                     EQU     3
MMIOM_CLOSE                                    EQU     4
MMIOM_WRITEFLUSH                               EQU     5

MMIOM_RENAME                                   EQU     6

MMIOM_USER                                     EQU     0x8000

FOURCC_RIFF                                    EQU     'RIFF'
FOURCC_LIST                                    EQU     'LIST'
FOURCC_DOS                                     EQU     'DOS '
FOURCC_MEM                                     EQU     'MEM '

IFNDEF SEEK_SET
    SEEK_SET                                   EQU     0
    SEEK_CUR                                   EQU     1
    SEEK_END                                   EQU     2
ENDIF

MMIO_DEFAULTBUFFER                             EQU     8192
MCIERR_INVALID_DEVICE_ID                       EQU     (MCIERR_BASE + 1)
MCIERR_UNRECOGNIZED_KEYWORD                    EQU     (MCIERR_BASE + 3)
MCIERR_UNRECOGNIZED_COMMAND                    EQU     (MCIERR_BASE + 5)
MCIERR_HARDWARE                                EQU     (MCIERR_BASE + 6)
MCIERR_INVALID_DEVICE_NAME                     EQU     (MCIERR_BASE + 7)
MCIERR_OUT_OF_MEMORY                           EQU     (MCIERR_BASE + 8)
MCIERR_DEVICE_OPEN                             EQU     (MCIERR_BASE + 9)
MCIERR_CANNOT_LOAD_DRIVER                      EQU     (MCIERR_BASE + 10)
MCIERR_MISSING_COMMAND_STRING                  EQU     (MCIERR_BASE + 11)
MCIERR_PARAM_OVERFLOW                          EQU     (MCIERR_BASE + 12)
MCIERR_MISSING_STRING_ARGUMENT                 EQU     (MCIERR_BASE + 13)
MCIERR_BAD_INTEGER                             EQU     (MCIERR_BASE + 14)
MCIERR_PARSER_INTERNAL                         EQU     (MCIERR_BASE + 15)
MCIERR_DRIVER_INTERNAL                         EQU     (MCIERR_BASE + 16)
MCIERR_MISSING_PARAMETER                       EQU     (MCIERR_BASE + 17)
MCIERR_UNSUPPORTED_FUNCTION                    EQU     (MCIERR_BASE + 18)
MCIERR_FILE_NOT_FOUND                          EQU     (MCIERR_BASE + 19)
MCIERR_DEVICE_NOT_READY                        EQU     (MCIERR_BASE + 20)
MCIERR_INTERNAL                                EQU     (MCIERR_BASE + 21)
MCIERR_DRIVER                                  EQU     (MCIERR_BASE + 22)
MCIERR_CANNOT_USE_ALL                          EQU     (MCIERR_BASE + 23)
MCIERR_MULTIPLE                                EQU     (MCIERR_BASE + 24)
MCIERR_EXTENSION_NOT_FOUND                     EQU     (MCIERR_BASE + 25)
MCIERR_OUTOFRANGE                              EQU     (MCIERR_BASE + 26)
MCIERR_FLAGS_NOT_COMPATIBLE                    EQU     (MCIERR_BASE + 28)
MCIERR_FILE_NOT_SAVED                          EQU     (MCIERR_BASE + 30)
MCIERR_DEVICE_TYPE_REQUIRED                    EQU     (MCIERR_BASE + 31)
MCIERR_DEVICE_LOCKED                           EQU     (MCIERR_BASE + 32)
MCIERR_DUPLICATE_ALIAS                         EQU     (MCIERR_BASE + 33)
MCIERR_BAD_CONSTANT                            EQU     (MCIERR_BASE + 34)
MCIERR_MUST_USE_SHAREABLE                      EQU     (MCIERR_BASE + 35)
MCIERR_MISSING_DEVICE_NAME                     EQU     (MCIERR_BASE + 36)
MCIERR_BAD_TIME_FORMAT                         EQU     (MCIERR_BASE + 37)
MCIERR_NO_CLOSING_QUOTE                        EQU     (MCIERR_BASE + 38)
MCIERR_DUPLICATE_FLAGS                         EQU     (MCIERR_BASE + 39)
MCIERR_INVALID_FILE                            EQU     (MCIERR_BASE + 40)
MCIERR_NULL_PARAMETER_BLOCK                    EQU     (MCIERR_BASE + 41)
MCIERR_UNNAMED_RESOURCE                        EQU     (MCIERR_BASE + 42)
MCIERR_NEW_REQUIRES_ALIAS                      EQU     (MCIERR_BASE + 43)
MCIERR_NOTIFY_ON_AUTO_OPEN                     EQU     (MCIERR_BASE + 44)
MCIERR_NO_ELEMENT_ALLOWED                      EQU     (MCIERR_BASE + 45)
MCIERR_NONAPPLICABLE_FUNCTION                  EQU     (MCIERR_BASE + 46)
MCIERR_ILLEGAL_FOR_AUTO_OPEN                   EQU     (MCIERR_BASE + 47)
MCIERR_FILENAME_REQUIRED                       EQU     (MCIERR_BASE + 48)
MCIERR_EXTRA_CHARACTERS                        EQU     (MCIERR_BASE + 49)
MCIERR_DEVICE_NOT_INSTALLED                    EQU     (MCIERR_BASE + 50)
MCIERR_GET_CD                                  EQU     (MCIERR_BASE + 51)
MCIERR_SET_CD                                  EQU     (MCIERR_BASE + 52)
MCIERR_SET_DRIVE                               EQU     (MCIERR_BASE + 53)
MCIERR_DEVICE_LENGTH                           EQU     (MCIERR_BASE + 54)
MCIERR_DEVICE_ORD_LENGTH                       EQU     (MCIERR_BASE + 55)
MCIERR_NO_INTEGER                              EQU     (MCIERR_BASE + 56)
MCIERR_WAVE_OUTPUTSINUSE                       EQU     (MCIERR_BASE + 64)
MCIERR_WAVE_SETOUTPUTINUSE                     EQU     (MCIERR_BASE + 65)
MCIERR_WAVE_INPUTSINUSE                        EQU     (MCIERR_BASE + 66)
MCIERR_WAVE_SETINPUTINUSE                      EQU     (MCIERR_BASE + 67)
MCIERR_WAVE_OUTPUTUNSPECIFIED                  EQU     (MCIERR_BASE + 68)
MCIERR_WAVE_INPUTUNSPECIFIED                   EQU     (MCIERR_BASE + 69)
MCIERR_WAVE_OUTPUTSUNSUITABLE                  EQU     (MCIERR_BASE + 70)
MCIERR_WAVE_SETOUTPUTUNSUITABLE                EQU     (MCIERR_BASE + 71)
MCIERR_WAVE_INPUTSUNSUITABLE                   EQU     (MCIERR_BASE + 72)
MCIERR_WAVE_SETINPUTUNSUITABLE                 EQU     (MCIERR_BASE + 73)
MCIERR_SEQ_DIV_INCOMPATIBLE                    EQU     (MCIERR_BASE + 80)
MCIERR_SEQ_PORT_INUSE                          EQU     (MCIERR_BASE + 81)
MCIERR_SEQ_PORT_NONEXISTENT                    EQU     (MCIERR_BASE + 82)
MCIERR_SEQ_PORT_MAPNODEVICE                    EQU     (MCIERR_BASE + 83)
MCIERR_SEQ_PORT_MISCERROR                      EQU     (MCIERR_BASE + 84)
MCIERR_SEQ_TIMER                               EQU     (MCIERR_BASE + 85)
MCIERR_SEQ_PORTUNSPECIFIED                     EQU     (MCIERR_BASE + 86)
MCIERR_SEQ_NOMIDIPRESENT                       EQU     (MCIERR_BASE + 87)
MCIERR_NO_WINDOW                               EQU     (MCIERR_BASE + 90)
MCIERR_CREATEWINDOW                            EQU     (MCIERR_BASE + 91)
MCIERR_FILE_READ                               EQU     (MCIERR_BASE + 92)
MCIERR_FILE_WRITE                              EQU     (MCIERR_BASE + 93)
MCIERR_NO_IDENTITY                             EQU     (MCIERR_BASE + 94)
MCIERR_CUSTOM_DRIVER_BASE                      EQU     (MCIERR_BASE + 256)

MCI_FIRST                                      EQU     DRV_MCI_FIRST

MCI_OPEN                                       EQU     0803H
MCI_CLOSE                                      EQU     0804H
MCI_ESCAPE                                     EQU     0805H
MCI_PLAY                                       EQU     0806H
MCI_SEEK                                       EQU     0807H
MCI_STOP                                       EQU     0808H
MCI_PAUSE                                      EQU     0809H
MCI_INFO                                       EQU     080AH
MCI_GETDEVCAPS                                 EQU     080BH
MCI_SPIN                                       EQU     080CH
MCI_SET                                        EQU     080DH
MCI_STEP                                       EQU     080EH
MCI_RECORD                                     EQU     080FH
MCI_SYSINFO                                    EQU     0810H
MCI_BREAK                                      EQU     0811H
MCI_SAVE                                       EQU     0813H
MCI_STATUS                                     EQU     0814H
MCI_CUE                                        EQU     0830H
MCI_REALIZE                                    EQU     0840H
MCI_WINDOW                                     EQU     0841H
MCI_PUT                                        EQU     0842H
MCI_WHERE                                      EQU     0843H
MCI_FREEZE                                     EQU     0844H
MCI_UNFREEZE                                   EQU     0845H
MCI_LOAD                                       EQU     0850H
MCI_CUT                                        EQU     0851H
MCI_COPY                                       EQU     0852H
MCI_PASTE                                      EQU     0853H
MCI_UPDATE                                     EQU     0854H
MCI_RESUME                                     EQU     0855H
MCI_DELETE                                     EQU     0856H

MCI_USER_MESSAGES                              EQU     (DRV_MCI_FIRST + 400)
MCI_LAST                                       EQU     0FFFH

;MCI_ALL_DEVICE_ID                             EQU     (MCIDEVICEID - 1)

MCI_DEVTYPE_VCR                                EQU     513
MCI_DEVTYPE_VIDEODISC                          EQU     514
MCI_DEVTYPE_OVERLAY                            EQU     515
MCI_DEVTYPE_CD_AUDIO                           EQU     516
MCI_DEVTYPE_DAT                                EQU     517
MCI_DEVTYPE_SCANNER                            EQU     518
MCI_DEVTYPE_ANIMATION                          EQU     519
MCI_DEVTYPE_DIGITAL_VIDEO                      EQU     520
MCI_DEVTYPE_OTHER                              EQU     521
MCI_DEVTYPE_WAVEFORM_AUDIO                     EQU     522
MCI_DEVTYPE_SEQUENCER                          EQU     523

MCI_DEVTYPE_FIRST                              EQU     MCI_DEVTYPE_VCR
MCI_DEVTYPE_LAST                               EQU     MCI_DEVTYPE_SEQUENCER

MCI_DEVTYPE_FIRST_USER                         EQU     1000H

MCI_MODE_NOT_READY                             EQU     (MCI_STRING_OFFSET + 12)
MCI_MODE_STOP                                  EQU     (MCI_STRING_OFFSET + 13)
MCI_MODE_PLAY                                  EQU     (MCI_STRING_OFFSET + 14)
MCI_MODE_RECORD                                EQU     (MCI_STRING_OFFSET + 15)
MCI_MODE_SEEK                                  EQU     (MCI_STRING_OFFSET + 16)
MCI_MODE_PAUSE                                 EQU     (MCI_STRING_OFFSET + 17)
MCI_MODE_OPEN                                  EQU     (MCI_STRING_OFFSET + 18)

MCI_FORMAT_MILLISECONDS                        EQU     0
MCI_FORMAT_HMS                                 EQU     1
MCI_FORMAT_MSF                                 EQU     2
MCI_FORMAT_FRAMES                              EQU     3
MCI_FORMAT_SMPTE_24                            EQU     4
MCI_FORMAT_SMPTE_25                            EQU     5
MCI_FORMAT_SMPTE_30                            EQU     6
MCI_FORMAT_SMPTE_30DROP                        EQU     7
MCI_FORMAT_BYTES                               EQU     8
MCI_FORMAT_SAMPLES                             EQU     9
MCI_FORMAT_TMSF                                EQU     10


MCI_NOTIFY_SUCCESSFUL                          EQU     0001H
MCI_NOTIFY_SUPERSEDED                          EQU     0002H
MCI_NOTIFY_ABORTED                             EQU     0004H
MCI_NOTIFY_FAILURE                             EQU     0008H

MCI_NOTIFY                                     EQU     00000001H
MCI_WAIT                                       EQU     00000002H
MCI_FROM                                       EQU     00000004H
MCI_TO                                         EQU     00000008H
MCI_TRACK                                      EQU     00000010H

MCI_OPEN_SHAREABLE                             EQU     00000100H
MCI_OPEN_ELEMENT                               EQU     00000200H
MCI_OPEN_ALIAS                                 EQU     00000400H
MCI_OPEN_ELEMENT_ID                            EQU     00000800H
MCI_OPEN_TYPE_ID                               EQU     00001000H
MCI_OPEN_TYPE                                  EQU     00002000H

MCI_SEEK_TO_START                              EQU     00000100H
MCI_SEEK_TO_END                                EQU     00000200H

MCI_STATUS_ITEM                                EQU     00000100H
MCI_STATUS_START                               EQU     00000200H

MCI_STATUS_LENGTH                              EQU     00000001H
MCI_STATUS_POSITION                            EQU     00000002H
MCI_STATUS_NUMBER_OF_TRACKS                    EQU     00000003H
MCI_STATUS_MODE                                EQU     00000004H
MCI_STATUS_MEDIA_PRESENT                       EQU     00000005H
MCI_STATUS_TIME_FORMAT                         EQU     00000006H
MCI_STATUS_READY                               EQU     00000007H
MCI_STATUS_CURRENT_TRACK                       EQU     00000008H

MCI_INFO_PRODUCT                               EQU     00000100H
MCI_INFO_FILE                                  EQU     00000200H
MCI_INFO_MEDIA_UPC                             EQU     00000400H
MCI_INFO_MEDIA_IDENTITY                        EQU     00000800H
MCI_INFO_NAME                                  EQU     00001000H
MCI_INFO_COPYRIGHT                             EQU     00002000H

MCI_GETDEVCAPS_ITEM                            EQU     00000100H

MCI_GETDEVCAPS_CAN_RECORD                      EQU     00000001H
MCI_GETDEVCAPS_HAS_AUDIO                       EQU     00000002H
MCI_GETDEVCAPS_HAS_VIDEO                       EQU     00000003H
MCI_GETDEVCAPS_DEVICE_TYPE                     EQU     00000004H
MCI_GETDEVCAPS_USES_FILES                      EQU     00000005H
MCI_GETDEVCAPS_COMPOUND_DEVICE                 EQU     00000006H
MCI_GETDEVCAPS_CAN_EJECT                       EQU     00000007H
MCI_GETDEVCAPS_CAN_PLAY                        EQU     00000008H
MCI_GETDEVCAPS_CAN_SAVE                        EQU     00000009H

MCI_SYSINFO_QUANTITY                           EQU     00000100H
MCI_SYSINFO_OPEN                               EQU     00000200H
MCI_SYSINFO_NAME                               EQU     00000400H
MCI_SYSINFO_INSTALLNAME                        EQU     00000800H

MCI_SET_DOOR_OPEN                              EQU     00000100H
MCI_SET_DOOR_CLOSED                            EQU     00000200H
MCI_SET_TIME_FORMAT                            EQU     00000400H
MCI_SET_AUDIO                                  EQU     00000800H
MCI_SET_VIDEO                                  EQU     00001000H
MCI_SET_ON                                     EQU     00002000H
MCI_SET_OFF                                    EQU     00004000H

MCI_SET_AUDIO_ALL                              EQU     00000000H
MCI_SET_AUDIO_LEFT                             EQU     00000001H
MCI_SET_AUDIO_RIGHT                            EQU     00000002H

MCI_BREAK_KEY                                  EQU     00000100H
MCI_BREAK_HWND                                 EQU     00000200H
MCI_BREAK_OFF                                  EQU     00000400H

MCI_RECORD_INSERT                              EQU     00000100H
MCI_RECORD_OVERWRITE                           EQU     00000200H

MCI_SAVE_FILE                                  EQU     00000100H

MCI_LOAD_FILE                                  EQU     00000100H

MCI_VD_MODE_PARK                               EQU     (MCI_VD_OFFSET + 1)

MCI_VD_MEDIA_CLV                               EQU     (MCI_VD_OFFSET + 2)
MCI_VD_MEDIA_CAV                               EQU     (MCI_VD_OFFSET + 3)
MCI_VD_MEDIA_OTHER                             EQU     (MCI_VD_OFFSET + 4)

MCI_VD_FORMAT_TRACK                            EQU     4001H

MCI_VD_PLAY_REVERSE                            EQU     00010000H
MCI_VD_PLAY_FAST                               EQU     00020000H
MCI_VD_PLAY_SPEED                              EQU     00040000H
MCI_VD_PLAY_SCAN                               EQU     00080000H
MCI_VD_PLAY_SLOW                               EQU     00100000H

MCI_VD_SEEK_REVERSE                            EQU     00010000H

MCI_VD_STATUS_SPEED                            EQU     00004002H
MCI_VD_STATUS_FORWARD                          EQU     00004003H
MCI_VD_STATUS_MEDIA_TYPE                       EQU     00004004H
MCI_VD_STATUS_SIDE                             EQU     00004005H
MCI_VD_STATUS_DISC_SIZE                        EQU     00004006H

MCI_VD_GETDEVCAPS_CLV                          EQU     00010000H
MCI_VD_GETDEVCAPS_CAV                          EQU     00020000H

MCI_VD_SPIN_UP                                 EQU     00010000H
MCI_VD_SPIN_DOWN                               EQU     00020000H

MCI_VD_GETDEVCAPS_CAN_REVERSE                  EQU     00004002H
MCI_VD_GETDEVCAPS_FAST_RATE                    EQU     00004003H
MCI_VD_GETDEVCAPS_SLOW_RATE                    EQU     00004004H
MCI_VD_GETDEVCAPS_NORMAL_RATE                  EQU     00004005H

MCI_VD_STEP_FRAMES                             EQU     00010000H
MCI_VD_STEP_REVERSE                            EQU     00020000H

MCI_VD_ESCAPE_STRING                           EQU     00000100H

MCI_CDA_STATUS_TYPE_TRACK                      EQU     00004001H

MCI_CDA_TRACK_AUDIO                            EQU     (MCI_CD_OFFSET + 0)
MCI_CDA_TRACK_OTHER                            EQU     (MCI_CD_OFFSET + 1)

MCI_WAVE_PCM                                   EQU     (MCI_WAVE_OFFSET + 0)
MCI_WAVE_MAPPER                                EQU     (MCI_WAVE_OFFSET + 1)

MCI_WAVE_OPEN_BUFFER                           EQU     00010000H

MCI_WAVE_SET_FORMATTAG                         EQU     00010000H
MCI_WAVE_SET_CHANNELS                          EQU     00020000H
MCI_WAVE_SET_SAMPLESPERSEC                     EQU     00040000H
MCI_WAVE_SET_AVGBYTESPERSEC                    EQU     00080000H
MCI_WAVE_SET_BLOCKALIGN                        EQU     00100000H
MCI_WAVE_SET_BITSPERSAMPLE                     EQU     00200000H

MCI_WAVE_INPUT                                 EQU     00400000H
MCI_WAVE_OUTPUT                                EQU     00800000H

MCI_WAVE_STATUS_FORMATTAG                      EQU     00004001H
MCI_WAVE_STATUS_CHANNELS                       EQU     00004002H
MCI_WAVE_STATUS_SAMPLESPERSEC                  EQU     00004003H
MCI_WAVE_STATUS_AVGBYTESPERSEC                 EQU     00004004H
MCI_WAVE_STATUS_BLOCKALIGN                     EQU     00004005H
MCI_WAVE_STATUS_BITSPERSAMPLE                  EQU     00004006H
MCI_WAVE_STATUS_LEVEL                          EQU     00004007H

MCI_WAVE_SET_ANYINPUT                          EQU     04000000H
MCI_WAVE_SET_ANYOUTPUT                         EQU     08000000H

MCI_WAVE_GETDEVCAPS_INPUTS                     EQU     00004001H
MCI_WAVE_GETDEVCAPS_OUTPUTS                    EQU     00004002H

MCI_SEQ_DIV_PPQN                               EQU     (0 + MCI_SEQ_OFFSET)
MCI_SEQ_DIV_SMPTE_24                           EQU     (1 + MCI_SEQ_OFFSET)
MCI_SEQ_DIV_SMPTE_25                           EQU     (2 + MCI_SEQ_OFFSET)
MCI_SEQ_DIV_SMPTE_30DROP                       EQU     (3 + MCI_SEQ_OFFSET)
MCI_SEQ_DIV_SMPTE_30                           EQU     (4 + MCI_SEQ_OFFSET)

MCI_SEQ_FORMAT_SONGPTR                         EQU     4001H
MCI_SEQ_FILE                                   EQU     4002H
MCI_SEQ_MIDI                                   EQU     4003H
MCI_SEQ_SMPTE                                  EQU     4004H
MCI_SEQ_NONE                                   EQU     65533
MCI_SEQ_MAPPER                                 EQU     65535

MCI_SEQ_STATUS_TEMPO                           EQU     00004002H
MCI_SEQ_STATUS_PORT                            EQU     00004003H
MCI_SEQ_STATUS_SLAVE                           EQU     00004007H
MCI_SEQ_STATUS_MASTER                          EQU     00004008H
MCI_SEQ_STATUS_OFFSET                          EQU     00004009H
MCI_SEQ_STATUS_DIVTYPE                         EQU     0000400AH
MCI_SEQ_STATUS_NAME                            EQU     0000400BH
MCI_SEQ_STATUS_COPYRIGHT                       EQU     0000400CH

MCI_SEQ_SET_TEMPO                              EQU     00010000H
MCI_SEQ_SET_PORT                               EQU     00020000H
MCI_SEQ_SET_SLAVE                              EQU     00040000H
MCI_SEQ_SET_MASTER                             EQU     00080000H
MCI_SEQ_SET_OFFSET                             EQU     01000000H

MCI_ANIM_OPEN_WS                               EQU     00010000H
MCI_ANIM_OPEN_PARENT                           EQU     00020000H
MCI_ANIM_OPEN_NOSTATIC                         EQU     00040000H

MCI_ANIM_PLAY_SPEED                            EQU     00010000H
MCI_ANIM_PLAY_REVERSE                          EQU     00020000H
MCI_ANIM_PLAY_FAST                             EQU     00040000H
MCI_ANIM_PLAY_SLOW                             EQU     00080000H
MCI_ANIM_PLAY_SCAN                             EQU     00100000H

MCI_ANIM_STEP_REVERSE                          EQU     00010000H
MCI_ANIM_STEP_FRAMES                           EQU     00020000H

MCI_ANIM_STATUS_SPEED                          EQU     00004001H
MCI_ANIM_STATUS_FORWARD                        EQU     00004002H
MCI_ANIM_STATUS_HWND                           EQU     00004003H
MCI_ANIM_STATUS_HPAL                           EQU     00004004H
MCI_ANIM_STATUS_STRETCH                        EQU     00004005H

MCI_ANIM_INFO_TEXT                             EQU     00010000H

MCI_ANIM_GETDEVCAPS_CAN_REVERSE                EQU     00004001H
MCI_ANIM_GETDEVCAPS_FAST_RATE                  EQU     00004002H
MCI_ANIM_GETDEVCAPS_SLOW_RATE                  EQU     00004003H
MCI_ANIM_GETDEVCAPS_NORMAL_RATE                EQU     00004004H
MCI_ANIM_GETDEVCAPS_PALETTES                   EQU     00004006H
MCI_ANIM_GETDEVCAPS_CAN_STRETCH                EQU     00004007H
MCI_ANIM_GETDEVCAPS_MAX_WINDOWS                EQU     00004008H

MCI_ANIM_REALIZE_NORM                          EQU     00010000H
MCI_ANIM_REALIZE_BKGD                          EQU     00020000H

MCI_ANIM_WINDOW_HWND                           EQU     00010000H
MCI_ANIM_WINDOW_STATE                          EQU     00040000H
MCI_ANIM_WINDOW_TEXT                           EQU     00080000H
MCI_ANIM_WINDOW_ENABLE_STRETCH                 EQU     00100000H
MCI_ANIM_WINDOW_DISABLE_STRETCH                EQU     00200000H

MCI_ANIM_WINDOW_DEFAULT                        EQU     00000000H

MCI_ANIM_RECT                                  EQU     00010000H
MCI_ANIM_PUT_SOURCE                            EQU     00020000H
MCI_ANIM_PUT_DESTINATION                       EQU     00040000H

MCI_ANIM_WHERE_SOURCE                          EQU     00020000H
MCI_ANIM_WHERE_DESTINATION                     EQU     00040000H

MCI_ANIM_UPDATE_HDC                            EQU     00020000H

MCI_OVLY_OPEN_WS                               EQU     00010000H
MCI_OVLY_OPEN_PARENT                           EQU     00020000H

MCI_OVLY_STATUS_HWND                           EQU     00004001H
MCI_OVLY_STATUS_STRETCH                        EQU     00004002H

MCI_OVLY_INFO_TEXT                             EQU     00010000H

MCI_OVLY_GETDEVCAPS_CAN_STRETCH                EQU     00004001H
MCI_OVLY_GETDEVCAPS_CAN_FREEZE                 EQU     00004002H
MCI_OVLY_GETDEVCAPS_MAX_WINDOWS                EQU     00004003H

MCI_OVLY_WINDOW_HWND                           EQU     00010000H
MCI_OVLY_WINDOW_STATE                          EQU     00040000H
MCI_OVLY_WINDOW_TEXT                           EQU     00080000H
MCI_OVLY_WINDOW_ENABLE_STRETCH                 EQU     00100000H
MCI_OVLY_WINDOW_DISABLE_STRETCH                EQU     00200000H

MCI_OVLY_WINDOW_DEFAULT                        EQU     00000000H

MCI_OVLY_RECT                                  EQU     00010000H
MCI_OVLY_PUT_SOURCE                            EQU     00020000H
MCI_OVLY_PUT_DESTINATION                       EQU     00040000H
MCI_OVLY_PUT_FRAME                             EQU     00080000H
MCI_OVLY_PUT_VIDEO                             EQU     00100000H

MCI_OVLY_WHERE_SOURCE                          EQU     00020000H
MCI_OVLY_WHERE_DESTINATION                     EQU     00040000H
MCI_OVLY_WHERE_FRAME                           EQU     00080000H
MCI_OVLY_WHERE_VIDEO                           EQU     00100000H

NEWTRANSPARENT                                 EQU     3
QUERYROPSUPPORT                                EQU     40
SELECTDIB                                      EQU     41


;======================================== Structures ======================================;

MIXERCONTROLA STRUCT
    cbStruct          DD ?
    dwControlID       DD ?
    dwControlType     DD ?
    fdwControl        DD ?
    cMultipleItems    DD ?
    szShortName       DB MIXER_SHORT_NAME_CHARS dup(?)
    szName            DB MIXER_LONG_NAME_CHARS dup(?)
    UNION Bounds
        STRUCT
            lMinimum  DD ?
            lMaximum  DD ?
        ENDS
        STRUCT
            dwMinimum DD ?
            dwMaximum DD ?
        ENDS
        dwReserved    DD 6 dup(?)
    ENDS
    UNION Metrics
        cSteps        DD ?
        cbCustomData  DD ?
        dwReserved    DD 6 dup(?)
    ENDS
MIXERCONTROLA ENDS

MIXERCONTROLW STRUCT
    cbStruct          DD ?
    dwControlID       DD ?
    dwControlType     DD ?
    fdwControl        DD ?
    cMultipleItems    DD ?
    szShortName       DW MIXER_SHORT_NAME_CHARS dup(?)
    szName            DW MIXER_LONG_NAME_CHARS dup(?)
    UNION Bounds
        STRUCT
            lMinimum  DD ?
            lMaximum  DD ?
        ENDS
        STRUCT
            dwMinimum DD ?
            dwMaximum DD ?
        ENDS
        dwReserved    DD 6 dup(?)
    ENDS
    UNION Metrics
        cSteps        DD ?
        cbCustomData  DD ?
        dwReserved    DD 6 dup(?)
    ENDS
MIXERCONTROLW ENDS

SMPTE STRUCT
    hour   DB ?
    min    DB ?
    sec    DB ?
    _frame DB ?
    fps    DB ?
    dummy  DB ?
    pad    DB 2 dup(?)
SMPTE ENDS

MMTIME STRUCT
    wType          DD ?
    UNION
        ms         DD ?
        sample     DD ?
        cb         DD ?
        ticks      DD ?
        smpte      SMPTE <>
        songptrpos DD ?
    ENDS
MMTIME ENDS

DRVCONFIGINFO STRUCT
    dwDCISize          DD   ?
    lpszDCISectionName XPTR ?
    lpszDCIAliasName   XPTR ?
DRVCONFIGINFO ENDS

DRVCONFIGINFOEX STRUCT
    dwDCISize          DD   ?
    lpszDCISectionName XPTR ?
    lpszDCIAliasName   XPTR ?
    dnDevNode          DD   ?
DRVCONFIGINFOEX ENDS

WAVEHDR STRUCT
    lpData          XPTR ?
    dwBufferLength  DD ?
    dwBytesRecorded DD ?
    dwUser          XPTR ?
    dwFlags         DD ?
    dwLoops         DD ?
    lpNext          XPTR ?
    reserved        DD ?
WAVEHDR ENDS

WAVEOUTCAPSA STRUCT
    wMid           DW ?
    wPid           DW ?
    vDriverVersion DD ?
    szPname        DB MAXPNAMELEN dup(?)
    dwFormats      DD ?
    wChannels      DW ?
    wReserved1     DW ?
    dwSupport      DD ?
WAVEOUTCAPSA ENDS

WAVEOUTCAPSW STRUCT
    wMid           DW ?
    wPid           DW ?
    vDriverVersion DD ?
    szPname        DW MAXPNAMELEN dup(?)
    dwFormats      DD ?
    wChannels      DW ?
    wReserved1     DW ?
    dwSupport      DD ?
WAVEOUTCAPSW ENDS

WAVEOUTCAPS2A STRUCT
    wMid             DW ?
    wPid             DW ?
    vDriverVersion   DD ?
    szPname          DB MAXPNAMELEN dup(?)
    dwFormats        DD ?
    wChannels        DW ?
    wReserved1       DW ?
    dwSupport        DD ?
    ManufacturerGuid GUID <>
    ProductGuid      GUID <>
    NameGuid         GUID <>
WAVEOUTCAPS2A ENDS

WAVEOUTCAPS2W STRUCT
    wMid             DW ?
    wPid             DW ?
    vDriverVersion   DD ?
    szPname          DW MAXPNAMELEN dup(?)
    dwFormats        DD ?
    wChannels        DW ?
    wReserved1       DW ?
    dwSupport        DD ?
    ManufacturerGuid GUID <>
    ProductGuid      GUID <>
    NameGuid         GUID <>
WAVEOUTCAPS2W ENDS

WAVEINCAPSA STRUCT
    wMid           DW ?
    wPid           DW ?
    vDriverVersion DD ?
    szPname        DB MAXPNAMELEN dup(?)
    dwFormats      DD ?
    wChannels      DW ?
    wReserved1     DW ?
WAVEINCAPSA ENDS

WAVEINCAPSW STRUCT
    wMid           DW ?
    wPid           DW ?
    vDriverVersion DD ?
    szPname        DW MAXPNAMELEN dup(?)
    dwFormats      DD ?
    wChannels      DW ?
    wReserved1     DW ?
WAVEINCAPSW ENDS

WAVEINCAPS2A STRUCT
    wMid             DW ?
    wPid             DW ?
    vDriverVersion   DD ?
    szPname          DB MAXPNAMELEN dup(?)
    dwFormats        DD ?
    wChannels        DW ?
    wReserved1       DW ?
    ManufacturerGuid GUID <>
    ProductGuid      GUID <>
    NameGuid         GUID <>
WAVEINCAPS2A ENDS

WAVEINCAPS2W STRUCT
    wMid             DW ?
    wPid             DW ?
    vDriverVersion   DD ?
    szPname          DW MAXPNAMELEN dup(?)
    dwFormats        DD ?
    wChannels        DW ?
    wReserved1       DW ?
    ManufacturerGuid GUID <>
    ProductGuid      GUID <>
    NameGuid         GUID <>
WAVEINCAPS2W ENDS

IFNDEF WAVE_FORMAT_PCM
    WAVE_FORMAT_PCM     EQU 1
    
    WAVEFORMAT STRUCT
        wFormatTag      DW  ?
        nChannels       DW  ?
        nSamplesPerSec  DD  ?
        nAvgBytesPerSec DD  ?
        nBlockAlign     DW  ?
    WAVEFORMAT ENDS
    
    PCMWAVEFORMAT STRUCT
        wf              WAVEFORMAT <>
        wBitsPerSample  DW  ?
    PCMWAVEFORMAT ENDS
ENDIF

IFNDEF _WAVEFORMATEX
    WAVEFORMATEX STRUCT
        wFormatTag      DW  ?
        nChannels       DW  ?
        nSamplesPerSec  DD  ?
        nAvgBytesPerSec DD  ?
        nBlockAlign     DW  ?
        wBitsPerSample  DW  ?
        cbSize          DW  ?
    WAVEFORMATEX ENDS
    _WAVEFORMATEX       EQU 1
ENDIF

MIDIOUTCAPSA STRUCT
    wMid           DW ?
    wPid           DW ?
    vDriverVersion DD ?
    szPname        DB MAXPNAMELEN dup(?)
    wTechnology    DW ?
    wVoices        DW ?
    wNotes         DW ?
    wChannelMask   DW ?
    dwSupport      DD ?
MIDIOUTCAPSA ENDS

MIDIOUTCAPSW STRUCT
    wMid           DW ?
    wPid           DW ?
    vDriverVersion DD ?
    szPname        DW MAXPNAMELEN dup(?)
    wTechnology    DW ?
    wVoices        DW ?
    wNotes         DW ?
    wChannelMask   DW ?
    dwSupport      DD ?
MIDIOUTCAPSW ENDS

MIDIOUTCAPS2A STRUCT
    wMid             DW ?
    wPid             DW ?
    vDriverVersion   DD ?
    szPname          DB MAXPNAMELEN dup(?)
    wTechnology      DW ?
    wVoices          DW ?
    wNotes           DW ?
    wChannelMask     DW ?
    dwSupport        DD ?
    ManufacturerGuid GUID <>
    ProductGuid      GUID <>
    NameGuid         GUID <>
MIDIOUTCAPS2A ENDS

MIDIOUTCAPS2W STRUCT
    wMid             DW ?
    wPid             DW ?
    vDriverVersion   DD ?
    szPname          DW MAXPNAMELEN dup(?)
    wTechnology      DW ?
    wVoices          DW ?
    wNotes           DW ?
    wChannelMask     DW ?
    dwSupport        DD ?
    ManufacturerGuid GUID <>
    ProductGuid      GUID <>
    NameGuid         GUID <>
MIDIOUTCAPS2W ENDS

MIDIINCAPSA STRUCT
    wMid           DW ?
    wPid           DW ?
    vDriverVersion DD ?
    szPname        DB MAXPNAMELEN dup(?)
    dwSupport      DD ?
MIDIINCAPSA ENDS

MIDIINCAPSW STRUCT
    wMid           DW ?
    wPid           DW ?
    vDriverVersion DD ?
    szPname        DW MAXPNAMELEN dup(?)
    dwSupport      DD ?
MIDIINCAPSW ENDS

MIDIINCAPS2A STRUCT
    wMid             DW ?
    wPid             DW ?
    vDriverVersion   DD ?
    szPname          DB MAXPNAMELEN dup(?)
    dwSupport        DD ?
    ManufacturerGuid GUID <>
    ProductGuid      GUID <>
    NameGuid         GUID <>
MIDIINCAPS2A ENDS

MIDIINCAPS2W STRUCT
    wMid             DW ?
    wPid             DW ?
    vDriverVersion   DD ?
    szPname          DW MAXPNAMELEN dup(?)
    dwSupport        DD ?
    ManufacturerGuid GUID <>
    ProductGuid      GUID <>
    NameGuid         GUID <>
MIDIINCAPS2W ENDS

MIDIHDR STRUCT
    lpData          XPTR ?
    dwBufferLength  DD ?
    dwBytesRecorded DD ?
    dwUser          XPTR ?
    dwFlags         DD ?
    lpNext          DD ?
    reserved        XPTR ?
    dwOffset        DD ?
    dwReserved      XPTR 8 dup(?)
MIDIHDR ENDS

MIDIEVENT STRUCT
    dwDeltaTime     DD ?
    dwStreamID      DD ?
    dwEvent         DD ?
    dwParms         DD ?
MIDIEVENT ENDS

MIDISTRMBUFFVER STRUCT
    dwVersion       DD ?
    dwMid           DD ?
    dwOEMVersion    DD ?
MIDISTRMBUFFVER ENDS

MIDIPROPTIMEDIV STRUCT
    cbStruct        DD ?
    dwTimeDiv       DD ?
MIDIPROPTIMEDIV ENDS

MIDIPROPTEMPO STRUCT
    cbStruct        DD ?
    dwTempo         DD ?
MIDIPROPTEMPO ENDS

AUXCAPSA STRUCT
    wMid           DW ?
    wPid           DW ?
    vDriverVersion DD ?
    szPname        DB MAXPNAMELEN dup(?)
    wTechnology    DW ?
    wReserved1     DW ?
    dwSupport      DD ?
AUXCAPSA ENDS

AUXCAPSW STRUCT
    wMid           DW ?
    wPid           DW ?
    vDriverVersion DD ?
    szPname        DW MAXPNAMELEN dup(?)
    wTechnology    DW ?
    wReserved1     DW ?
    dwSupport      DD ?
AUXCAPSW ENDS

AUXCAPS2A STRUCT
    wMid             DW ?
    wPid             DW ?
    vDriverVersion   DD ?
    szPname          DB MAXPNAMELEN dup(?)
    wTechnology      DW ?
    wReserved1       DW ?
    dwSupport        DD ?
    ManufacturerGuid GUID <>
    ProductGuid      GUID <>
    NameGuid         GUID <>
AUXCAPS2A ENDS

AUXCAPS2W STRUCT
    wMid             DW ?
    wPid             DW ?
    vDriverVersion   DD ?
    szPname          DW MAXPNAMELEN dup(?)
    wTechnology      DW ?
    wReserved1       DW ?
    dwSupport        DD ?
    ManufacturerGuid GUID <>
    ProductGuid      GUID <>
    NameGuid         GUID <>
AUXCAPS2W ENDS

MIXERCAPSA STRUCT
    wMid           DW ?
    wPid           DW ?
    vDriverVersion DD ?
    szPname        DB MAXPNAMELEN dup(?)
    fdwSupport     DD ?
    cDestinations  DD ?
MIXERCAPSA ENDS

MIXERCAPSW STRUCT
    wMid           DW ?
    wPid           DW ?
    vDriverVersion DD ?
    szPname        DW MAXPNAMELEN dup(?)
    fdwSupport     DD ?
    cDestinations  DD ?
MIXERCAPSW ENDS

MIXERCAPS2A STRUCT
    wMid             DW ?
    wPid             DW ?
    vDriverVersion   DD ?
    szPname          DB MAXPNAMELEN dup(?)
    fdwSupport       DD ?
    cDestinations    DD ?
    ManufacturerGuid GUID <>
    ProductGuid      GUID <>
    NameGuid         GUID <>
MIXERCAPS2A ENDS

MIXERCAPS2W STRUCT
    wMid             DW ?
    wPid             DW ?
    vDriverVersion   DD ?
    szPname          DW MAXPNAMELEN dup(?)
    fdwSupport       DD ?
    cDestinations    DD ?
    ManufacturerGuid GUID <>
    ProductGuid      GUID <>
    NameGuid         GUID <>
MIXERCAPS2W ENDS

TARGETA STRUCT
    dwType         DD ?
    dwDeviceID     DD ?
    wMid           DW ?
    wPid           DW ?
    vDriverVersion DD ?
    szPname        DB MAXPNAMELEN dup(?)
TARGETA ENDS

TARGETW STRUCT
    dwType         DD ?
    dwDeviceID     DD ?
    wMid           DW ?
    wPid           DW ?
    vDriverVersion DD ?
    szPname        DW MAXPNAMELEN dup(?)
TARGETW ENDS

MIXERLINEA STRUCT
    cbStruct        DD   ?
    dwDestination   DD   ?
    dwSource        DD   ?
    dwLineID        DD   ?
    fdwLine         DD   ?
    dwUser          XPTR ?
    dwComponentType DD   ?
    cChannels       DD   ?
    cConnections    DD   ?
    cControls       DD   ?
    szShortName     DB   MIXER_SHORT_NAME_CHARS dup(?)
    szName          DB   MIXER_LONG_NAME_CHARS dup(?)
    Target          TARGETA <>
MIXERLINEA ENDS

MIXERLINEW STRUCT
    cbStruct        DD   ?
    dwDestination   DD   ?
    dwSource        DD   ?
    dwLineID        DD   ?
    fdwLine         DD   ?
    dwUser          XPTR ?
    dwComponentType DD   ?
    cChannels       DD   ?
    cConnections    DD   ?
    cControls       DD   ?
    szShortName     DW   MIXER_SHORT_NAME_CHARS dup(?)
    szName          DW   MIXER_LONG_NAME_CHARS dup(?)
    Target          TARGETW <>
MIXERLINEW ENDS

MIXERLINECONTROLSA STRUCT
    cbStruct          DD ?
    dwLineID          DD ?
    UNION
        dwControlID   DD ?
        dwControlType DD ?
    ENDS
    cControls         DD ?
    cbmxctrl          DD ?
    pamxctrl          XPTR ?
MIXERLINECONTROLSA ENDS

MIXERLINECONTROLSW STRUCT
    cbStruct          DD ?
    dwLineID          DD ?
    UNION
        dwControlID   DD ?
        dwControlType DD ?
    ENDS
    cControls         DD ?
    cbmxctrl          DD ?
    pamxctrl          XPTR ?
MIXERLINECONTROLSW ENDS

MIXERCONTROLDETAILS STRUCT
    cbStruct           DD ?
    dwControlID        DD ?
    cChannels          DD ?
    UNION
        hwndOwner      XPTR ?
        cMultipleItems DD ?
    ENDS
    cbDetails          DD ?
    paDetails          XPTR ?
MIXERCONTROLDETAILS ENDS

MIXERCONTROLDETAILS_LISTTEXTA STRUCT
    dwParam1           DD ?
    dwParam2           DD ?
    szName             DB MIXER_LONG_NAME_CHARS dup(?)
MIXERCONTROLDETAILS_LISTTEXTA ENDS

MIXERCONTROLDETAILS_LISTTEXTW STRUCT
    dwParam1           DD ?
    dwParam2           DD ?
    szName             DW MIXER_LONG_NAME_CHARS dup(?)
MIXERCONTROLDETAILS_LISTTEXTW ENDS

MIXERCONTROLDETAILS_BOOLEAN STRUCT
    fValue  DD ?
MIXERCONTROLDETAILS_BOOLEAN ENDS

MIXERCONTROLDETAILS_SIGNED STRUCT
    lValue  DD ?
MIXERCONTROLDETAILS_SIGNED ENDS

MIXERCONTROLDETAILS_UNSIGNED STRUCT
    dwValue DD ?
MIXERCONTROLDETAILS_UNSIGNED ENDS

TIMECAPS STRUCT
    wPeriodMin DD ?
    wPeriodMax DD ?
TIMECAPS ENDS

JOYCAPSA STRUCT
    wMid        DW ?
    wPid        DW ?
    szPname     DB MAXPNAMELEN dup(?)
    wXmin       DD ?
    wXmax       DD ?
    wYmin       DD ?
    wYmax       DD ?
    wZmin       DD ?
    wZmax       DD ?
    wNumButtons DD ?
    wPeriodMin  DD ?
    wPeriodMax  DD ?
    wRmin       DD ?
    wRmax       DD ?
    wUmin       DD ?
    wUmax       DD ?
    wVmin       DD ?
    wVmax       DD ?
    wCaps       DD ?
    wMaxAxes    DD ?
    wNumAxes    DD ?
    wMaxButtons DD ?
    szRegKey    DB MAXPNAMELEN dup(?)
    szOEMVxD    DB MAX_JOYSTICKOEMVXDNAME dup(?)
JOYCAPSA ENDS

JOYCAPSW STRUCT
    wMid        DW ?
    wPid        DW ?
    szPname     DW MAXPNAMELEN dup(?)
    wXmin       DD ?
    wXmax       DD ?
    wYmin       DD ?
    wYmax       DD ?
    wZmin       DD ?
    wZmax       DD ?
    wNumButtons DD ?
    wPeriodMin  DD ?
    wPeriodMax  DD ?
    wRmin       DD ?
    wRmax       DD ?
    wUmin       DD ?
    wUmax       DD ?
    wVmin       DD ?
    wVmax       DD ?
    wCaps       DD ?
    wMaxAxes    DD ?
    wNumAxes    DD ?
    wMaxButtons DD ?
    szRegKey    DW MAXPNAMELEN dup(?)
    szOEMVxD    DW MAX_JOYSTICKOEMVXDNAME dup(?)
JOYCAPSW ENDS

JOYCAPS2A STRUCT
    wMid             DW ?
    wPid             DW ?
    szPname          DB MAXPNAMELEN dup(?)
    wXmin            DD ?
    wXmax            DD ?
    wYmin            DD ?
    wYmax            DD ?
    wZmin            DD ?
    wZmax            DD ?
    wNumButtons      DD ?
    wPeriodMin       DD ?
    wPeriodMax       DD ?
    wRmin            DD ?
    wRmax            DD ?
    wUmin            DD ?
    wUmax            DD ?
    wVmin            DD ?
    wVmax            DD ?
    wCaps            DD ?
    wMaxAxes         DD ?
    wNumAxes         DD ?
    wMaxButtons      DD ?
    szRegKey         DB MAXPNAMELEN dup(?)
    szOEMVxD         DB MAX_JOYSTICKOEMVXDNAME dup(?)
    ManufacturerGuid GUID <>
    ProductGuid      GUID <>
    NameGuid         GUID <>
JOYCAPS2A ENDS

JOYCAPS2W STRUCT
    wMid             DW ?
    wPid             DW ?
    szPname          DW MAXPNAMELEN dup(?)
    wXmin            DD ?
    wXmax            DD ?
    wYmin            DD ?
    wYmax            DD ?
    wZmin            DD ?
    wZmax            DD ?
    wNumButtons      DD ?
    wPeriodMin       DD ?
    wPeriodMax       DD ?
    wRmin            DD ?
    wRmax            DD ?
    wUmin            DD ?
    wUmax            DD ?
    wVmin            DD ?
    wVmax            DD ?
    wCaps            DD ?
    wMaxAxes         DD ?
    wNumAxes         DD ?
    wMaxButtons      DD ?
    szRegKey         DW MAXPNAMELEN dup(?)
    szOEMVxD         DW MAX_JOYSTICKOEMVXDNAME dup(?)
    ManufacturerGuid GUID <>
    ProductGuid      GUID <>
    NameGuid         GUID <>
JOYCAPS2W ENDS

JOYINFO STRUCT
    wXpos    DD ?
    wYpos    DD ?
    wZpos    DD ?
    wButtons DD ?
JOYINFO ENDS

JOYINFOEX STRUCT
    dwSize         DD ?
    dwFlags        DD ?
    dwXpos         DD ?
    dwYpos         DD ?
    dwZpos         DD ?
    dwRpos         DD ?
    dwUpos         DD ?
    dwVpos         DD ?
    dwButtons      DD ?
    dwButtonNumber DD ?
    dwPOV          DD ?
    dwReserved1    DD ?
    dwReserved2    DD ?
JOYINFOEX ENDS

MMIOINFO STRUCT
    dwFlags     DD ?
    fccIOProc   DD ?
    pIOProc     XPTR ?
    wErrorRet   DD ?
    htask       XPTR ?
    cchBuffer   DD ?
    pchBuffer   XPTR ?
    pchNext     XPTR ?
    pchEndRead  XPTR ?
    pchEndWrite XPTR ?
    lBufOffset  DD ?
    lDiskOffset DD ?
    adwInfo     DD 3 dup(?)
    dwReserved1 DD ?
    dwReserved2 DD ?
    hmmio       XPTR ?
MMIOINFO ENDS

MMCKINFO STRUCT
    ckid         DD ?
    cksize       DD ?
    fccType      DD ?
    dwDataOffset DD ?
    dwFlags      DD ?
MMCKINFO ENDS

MCI_GENERIC_PARMS STRUCT
    dwCallback XPTR ?
MCI_GENERIC_PARMS ENDS

MCI_OPEN_PARMSA STRUCT
    dwCallback       XPTR ?
    wDeviceID        DD   ?
    lpstrDeviceType  XPTR ?
    lpstrElementName XPTR ?
    lpstrAlias       XPTR ?
MCI_OPEN_PARMSA ENDS

MCI_OPEN_PARMSW STRUCT
    dwCallback       XPTR ?
    wDeviceID        DD   ?
    lpstrDeviceType  XPTR ?
    lpstrElementName XPTR ?
    lpstrAlias       XPTR ?
MCI_OPEN_PARMSW ENDS

MCI_PLAY_PARMS STRUCT
    dwCallback XPTR ?
    dwFrom     DD   ?
    dwTo       DD   ?
MCI_PLAY_PARMS ENDS

MCI_SEEK_PARMS STRUCT
    dwCallback XPTR ?
    dwTo       DD   ?
MCI_SEEK_PARMS ENDS

MCI_STATUS_PARMS STRUCT
    dwCallback XPTR ?
    dwReturn   XPTR ?
    dwItem     DD   ?
    dwTrack    DD   ?
MCI_STATUS_PARMS ENDS

MCI_INFO_PARMSA STRUCT
    dwCallback  XPTR ?
    lpstrReturn XPTR ?
    dwRetSize   DD   ?
MCI_INFO_PARMSA ENDS

MCI_INFO_PARMSW STRUCT
    dwCallback  XPTR ?
    lpstrReturn XPTR ?
    dwRetSize   DD   ?
MCI_INFO_PARMSW ENDS

MCI_GETDEVCAPS_PARMS STRUCT
    dwCallback XPTR ?
    dwReturn   DD   ?
    dwItem     DD   ?
MCI_GETDEVCAPS_PARMS ENDS

MCI_SYSINFO_PARMSA STRUCT
    dwCallback  XPTR ?
    lpstrReturn XPTR ?
    dwRetSize   DD   ?
    dwNumber    DD   ?
    wDeviceType DD   ?
MCI_SYSINFO_PARMSA ENDS

MCI_SYSINFO_PARMSW STRUCT
    dwCallback  XPTR ?
    lpstrReturn XPTR ?
    dwRetSize   DD   ?
    dwNumber    DD   ?
    wDeviceType DD   ?
MCI_SYSINFO_PARMSW ENDS

MCI_SET_PARMS STRUCT
    dwCallback   XPTR ?
    dwTimeFormat DD   ?
    dwAudio      DD   ?
MCI_SET_PARMS ENDS

MCI_BREAK_PARMS STRUCT
    dwCallback XPTR ?
    nVirtKey   DD   ?
    hwndBreak  XPTR ?
MCI_BREAK_PARMS ENDS

MCI_SAVE_PARMSA STRUCT
    dwCallback XPTR ?
    lpfilename XPTR ?
MCI_SAVE_PARMSA ENDS

MCI_SAVE_PARMSW STRUCT
    dwCallback XPTR ?
    lpfilename XPTR ?
MCI_SAVE_PARMSW ENDS

MCI_LOAD_PARMSA STRUCT
    dwCallback XPTR ?
    lpfilename XPTR ?
MCI_LOAD_PARMSA ENDS

MCI_LOAD_PARMSW STRUCT
    dwCallback XPTR ?
    lpfilename XPTR ?
MCI_LOAD_PARMSW ENDS

MCI_RECORD_PARMS STRUCT
    dwCallback XPTR ?
    dwFrom     DD   ?
    dwTo       DD   ?
MCI_RECORD_PARMS ENDS

MCI_VD_PLAY_PARMS STRUCT
    dwCallback XPTR ?
    dwFrom     DD   ?
    dwTo       DD   ?
    dwSpeed    DD   ?
MCI_VD_PLAY_PARMS ENDS

MCI_VD_STEP_PARMS STRUCT
    dwCallback XPTR ?
    dwFrames   DD   ?
MCI_VD_STEP_PARMS ENDS

MCI_VD_ESCAPE_PARMSA STRUCT
    dwCallback   XPTR ?
    lpstrCommand XPTR ?
MCI_VD_ESCAPE_PARMSA ENDS

MCI_VD_ESCAPE_PARMSW STRUCT
    dwCallback   XPTR ?
    lpstrCommand XPTR ?
MCI_VD_ESCAPE_PARMSW ENDS

MCI_WAVE_OPEN_PARMSA STRUCT
    dwCallback       XPTR ?
    wDeviceID        DD   ?
    lpstrDeviceType  XPTR ?
    lpstrElementName XPTR ?
    lpstrAlias       XPTR ?
    dwBufferSeconds  DD   ?
MCI_WAVE_OPEN_PARMSA ENDS

MCI_WAVE_OPEN_PARMSW STRUCT
    dwCallback       XPTR ?
    wDeviceID        DD   ?
    lpstrDeviceType  XPTR ?
    lpstrElementName XPTR ?
    lpstrAlias       XPTR ?
    dwBufferSeconds  DD   ?
MCI_WAVE_OPEN_PARMSW ENDS

MCI_WAVE_DELETE_PARMS STRUCT
    dwCallback XPTR ?
    dwFrom     DD   ?
    dwTo       DD   ?
MCI_WAVE_DELETE_PARMS ENDS

MCI_WAVE_SET_PARMS STRUCT
    dwCallback      XPTR ?
    dwTimeFormat    DD   ?
    dwAudio         DD   ?
    wInput          DD   ?
    wOutput         DD   ?
    wFormatTag      DW   ?
    wReserved2      DW   ?
    nChannels       DW   ?
    wReserved3      DW   ?
    nSamplesPerSec  DD   ?
    nAvgBytesPerSec DD   ?
    nBlockAlign     DW   ?
    wReserved4      DW   ?
    wBitsPerSample  DW   ?
    wReserved5      DW   ?
MCI_WAVE_SET_PARMS ENDS

MCI_SEQ_SET_PARMS STRUCT
    dwCallback   XPTR ?
    dwTimeFormat DD   ?
    dwAudio      DD   ?
    dwTempo      DD   ?
    dwPort       DD   ?
    dwSlave      DD   ?
    dwMaster     DD   ?
    dwOffset     DD   ?
MCI_SEQ_SET_PARMS ENDS

MCI_ANIM_OPEN_PARMSA STRUCT
    dwCallback       XPTR ?
    wDeviceID        DD   ?
    lpstrDeviceType  XPTR ?
    lpstrElementName XPTR ?
    lpstrAlias       XPTR ?
    dwStyle          DD   ?
    hWndParent       XPTR ?
MCI_ANIM_OPEN_PARMSA ENDS

MCI_ANIM_OPEN_PARMSW STRUCT
    dwCallback       XPTR ?
    wDeviceID        DD   ?
    lpstrDeviceType  XPTR ?
    lpstrElementName XPTR ?
    lpstrAlias       XPTR ?
    dwStyle          DD   ?
    hWndParent       XPTR ?
MCI_ANIM_OPEN_PARMSW ENDS

MCI_ANIM_PLAY_PARMS STRUCT
    dwCallback XPTR ?
    dwFrom     DD   ?
    dwTo       DD   ?
    dwSpeed    DD   ?
MCI_ANIM_PLAY_PARMS ENDS

MCI_ANIM_STEP_PARMS STRUCT
    dwCallback XPTR ?
    dwFrames   DD   ?
MCI_ANIM_STEP_PARMS ENDS

MCI_ANIM_WINDOW_PARMSA STRUCT
    dwCallback XPTR ?
    UNION
        hWnd   XPTR ?
        hwnd   XPTR ?
    ENDS
    nCmdShow   DD   ?
    lpstrText  XPTR ?
MCI_ANIM_WINDOW_PARMSA ENDS

MCI_ANIM_WINDOW_PARMSW STRUCT
    dwCallback XPTR ?
    UNION
        hWnd   XPTR ?
        hwnd   XPTR ?
    ENDS
    nCmdShow   DD   ?
    lpstrText  XPTR ?
MCI_ANIM_WINDOW_PARMSW ENDS

MCI_ANIM_RECT_PARMS STRUCT
    dwCallback   XPTR  ?
    rc           RECT <>
MCI_ANIM_RECT_PARMS ENDS

MCI_ANIM_UPDATE_PARMS STRUCT
    dwCallback XPTR ?
    rc         RECT <>
    hDC        XPTR ?
MCI_ANIM_UPDATE_PARMS ENDS

MCI_OVLY_OPEN_PARMSA STRUCT
    dwCallback       XPTR ?
    wDeviceID        DD   ?
    lpstrDeviceType  XPTR ?
    lpstrElementName XPTR ?
    lpstrAlias       XPTR ?
    dwStyle          DD   ?
    hWndParent       XPTR ?
MCI_OVLY_OPEN_PARMSA ENDS

MCI_OVLY_OPEN_PARMSW STRUCT
    dwCallback       XPTR ?
    wDeviceID        DD   ?
    lpstrDeviceType  XPTR ?
    lpstrElementName XPTR ?
    lpstrAlias       XPTR ?
    dwStyle          DD   ?
    hWndParent       XPTR ?
MCI_OVLY_OPEN_PARMSW ENDS

MCI_OVLY_WINDOW_PARMSA STRUCT
    dwCallback XPTR ?
    hWnd       XPTR ?
    nCmdShow   DD   ?
    lpstrText  XPTR ?
MCI_OVLY_WINDOW_PARMSA ENDS

MCI_OVLY_WINDOW_PARMSW STRUCT
    dwCallback XPTR ?
    hWnd       XPTR ?
    nCmdShow   DD   ?
    lpstrText  XPTR ?
MCI_OVLY_WINDOW_PARMSW ENDS

MCI_OVLY_RECT_PARMS STRUCT
    dwCallback   XPTR  ?
    rc           RECT  <>
MCI_OVLY_RECT_PARMS ENDS

MCI_OVLY_SAVE_PARMSA STRUCT
    dwCallback XPTR ?
    lpfilename XPTR ?
    rc         RECT <>
MCI_OVLY_SAVE_PARMSA ENDS

MCI_OVLY_SAVE_PARMSW STRUCT
    dwCallback XPTR ?
    lpfilename XPTR ?
    rc         RECT <>
MCI_OVLY_SAVE_PARMSW ENDS

MCI_OVLY_LOAD_PARMSA STRUCT
    dwCallback XPTR ?
    lpfilename XPTR ?
    rc         RECT <>
MCI_OVLY_LOAD_PARMSA ENDS

MCI_OVLY_LOAD_PARMSW STRUCT
    dwCallback XPTR ?
    lpfilename XPTR ?
    rc         RECT <>
MCI_OVLY_LOAD_PARMSW ENDS

IFDEF APP_UNICODE
    MIXERCONTROL EQU <MIXERCONTROLW>
    WAVEOUTCAPS EQU <WAVEOUTCAPSW>
    WAVEOUTCAPS2 EQU <WAVEOUTCAPS2W>
    WAVEINCAPS EQU <WAVEINCAPSW>
    WAVEINCAPS2 EQU <WAVEINCAPS2W>
    MIDIOUTCAPS EQU <MIDIOUTCAPSW>
    MIDIOUTCAPS2 EQU <MIDIOUTCAPS2W>
    MIDIINCAPS EQU <MIDIINCAPSW>
    MIDIINCAPS2 EQU <MIDIINCAPS2W>
    AUXCAPS EQU <AUXCAPSW>
    AUXCAPS2 EQU <AUXCAPS2W>
    MIXERCAPS EQU <MIXERCAPSW>
    MIXERCAPS2 EQU <MIXERCAPS2W>
    TARGET EQU <TARGETW>
    MIXERLINE EQU <MIXERLINEW>
    MIXERLINECONTROLS EQU <MIXERLINECONTROLSW>
    MIXERCONTROLDETAILS_LISTTEXT EQU <MIXERCONTROLDETAILS_LISTTEXTW>
    JOYCAPS EQU <JOYCAPSW>
    JOYCAPS2 EQU <JOYCAPS2W>
    MCI_OPEN_PARMS EQU <MCI_OPEN_PARMSW>
    MCI_INFO_PARMS EQU <MCI_INFO_PARMSW>
    MCI_SYSINFO_PARMS EQU <MCI_SYSINFO_PARMSW>
    MCI_SAVE_PARMS EQU <MCI_SAVE_PARMSW>
    MCI_LOAD_PARMS EQU <MCI_LOAD_PARMSW>
    MCI_VD_ESCAPE_PARMS EQU <MCI_VD_ESCAPE_PARMSW>
    MCI_WAVE_OPEN_PARMS EQU <MCI_WAVE_OPEN_PARMSW>
    MCI_ANIM_OPEN_PARMS EQU <MCI_ANIM_OPEN_PARMSW>
    MCI_ANIM_WINDOW_PARMS EQU <MCI_ANIM_WINDOW_PARMSW>
    MCI_OVLY_OPEN_PARMS EQU <MCI_OVLY_OPEN_PARMSW>
    MCI_OVLY_WINDOW_PARMS EQU <MCI_OVLY_WINDOW_PARMSW>
    MCI_OVLY_SAVE_PARMS EQU <MCI_OVLY_SAVE_PARMSW>
    MCI_OVLY_LOAD_PARMS EQU <MCI_OVLY_LOAD_PARMSW>
ELSE
    MIXERCONTROL EQU <MIXERCONTROLA>
    WAVEOUTCAPS EQU <WAVEOUTCAPSA>
    WAVEOUTCAPS2 EQU <WAVEOUTCAPS2A>
    WAVEINCAPS EQU <WAVEINCAPSA>
    WAVEINCAPS2 EQU <WAVEINCAPS2A>
    MIDIOUTCAPS EQU <MIDIOUTCAPSA>
    MIDIOUTCAPS2 EQU <MIDIOUTCAPS2A>
    MIDIINCAPS EQU <MIDIINCAPSA>
    MIDIINCAPS2 EQU <MIDIINCAPS2A>
    AUXCAPS EQU <AUXCAPSA>
    AUXCAPS2 EQU <AUXCAPS2A>
    MIXERCAPS EQU <MIXERCAPSA>
    MIXERCAPS2 EQU <MIXERCAPS2A>
    TARGET EQU <TARGETA>
    MIXERLINE EQU <MIXERLINEA>
    MIXERLINECONTROLS EQU <MIXERLINECONTROLSA>
    MIXERCONTROLDETAILS_LISTTEXT EQU <MIXERCONTROLDETAILS_LISTTEXTA>
    JOYCAPS EQU <JOYCAPSA>
    JOYCAPS2 EQU <JOYCAPS2A>
    MCI_OPEN_PARMS EQU <MCI_OPEN_PARMSA>
    MCI_INFO_PARMS EQU <MCI_INFO_PARMSA>
    MCI_SYSINFO_PARMS EQU <MCI_SYSINFO_PARMSA>
    MCI_SAVE_PARMS EQU <MCI_SAVE_PARMSA>
    MCI_LOAD_PARMS EQU <MCI_LOAD_PARMSA>
    MCI_VD_ESCAPE_PARMS EQU <MCI_VD_ESCAPE_PARMSA>
    MCI_WAVE_OPEN_PARMS EQU <MCI_WAVE_OPEN_PARMSA>
    MCI_ANIM_OPEN_PARMS EQU <MCI_ANIM_OPEN_PARMSA>
    MCI_ANIM_WINDOW_PARMS EQU <MCI_ANIM_WINDOW_PARMSA>
    MCI_OVLY_OPEN_PARMS EQU <MCI_OVLY_OPEN_PARMSA>
    MCI_OVLY_WINDOW_PARMS EQU <MCI_OVLY_WINDOW_PARMSA>
    MCI_OVLY_SAVE_PARMS EQU <MCI_OVLY_SAVE_PARMSA>
    MCI_OVLY_LOAD_PARMS EQU <MCI_OVLY_LOAD_PARMSA>
ENDIF

;======================================== Functions =======================================;

IF (NTDDI_VERSION EQ NTDDI_VISTA)
    aux32Message PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
ENDIF
auxGetDevCapsA PROTO :XWORD,:XWORD,:XWORD
auxGetDevCapsW PROTO :XWORD,:XWORD,:XWORD
auxGetNumDevs PROTO
auxGetVolume PROTO :XWORD,:XWORD
auxOutMessage PROTO :XWORD,:XWORD,:XWORD,:XWORD
auxSetVolume PROTO :XWORD,:XWORD
CloseDriver PROTO :XWORD,:XWORD,:XWORD
DefDriverProc PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
DriverCallback PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
DrvGetModuleHandle PROTO :XWORD
GetDriverModuleHandle PROTO :XWORD
IF (NTDDI_VERSION EQ NTDDI_VISTA)
    joy32Message PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
ENDIF
joyConfigChanged PROTO :XWORD
joyGetDevCapsA PROTO :XWORD,:XWORD,:XWORD
joyGetDevCapsW PROTO :XWORD,:XWORD,:XWORD
joyGetNumDevs PROTO
joyGetPos PROTO :XWORD,:XWORD
joyGetPosEx PROTO :XWORD,:XWORD
joyGetThreshold PROTO :XWORD,:XWORD
joyReleaseCapture PROTO :XWORD
joySetCapture PROTO :XWORD,:XWORD,:XWORD,:XWORD
joySetThreshold PROTO :XWORD,:XWORD
IF (NTDDI_VERSION EQ NTDDI_VISTA)
    mci32Message PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
ENDIF
mciDriverNotify PROTO :XWORD,:XWORD,:XWORD
mciDriverYield PROTO :XWORD
mciExecute PROTO :XWORD
mciFreeCommandResource PROTO :XWORD
mciGetCreatorTask PROTO :XWORD
mciGetDeviceIDA PROTO :XWORD
mciGetDeviceIDFromElementIDA PROTO :XWORD,:XWORD
mciGetDeviceIDFromElementIDW PROTO :XWORD,:XWORD
mciGetDeviceIDW PROTO :XWORD
mciGetDriverData PROTO :XWORD
mciGetErrorStringA PROTO :XWORD,:XWORD,:XWORD
mciGetErrorStringW PROTO :XWORD,:XWORD,:XWORD
mciGetYieldProc PROTO :XWORD,:XWORD
mciLoadCommandResource PROTO :XWORD,:XWORD,:XWORD
mciSendCommandA PROTO :XWORD,:XWORD,:XWORD,:XWORD
mciSendCommandW PROTO :XWORD,:XWORD,:XWORD,:XWORD
mciSendStringA PROTO :XWORD,:XWORD,:XWORD,:XWORD
mciSendStringW PROTO :XWORD,:XWORD,:XWORD,:XWORD
mciSetDriverData PROTO :XWORD,:XWORD
mciSetYieldProc PROTO :XWORD,:XWORD,:XWORD
IF (NTDDI_VERSION EQ NTDDI_VISTA)
    mid32Message PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
ENDIF
midiConnect PROTO :XWORD,:XWORD,:XWORD
midiDisconnect PROTO :XWORD,:XWORD,:XWORD
midiInAddBuffer PROTO :XWORD,:XWORD,:XWORD
midiInClose PROTO :XWORD
midiInGetDevCapsA PROTO :XWORD,:XWORD,:XWORD
midiInGetDevCapsW PROTO :XWORD,:XWORD,:XWORD
midiInGetErrorTextA PROTO :XWORD,:XWORD,:XWORD
midiInGetErrorTextW PROTO :XWORD,:XWORD,:XWORD
midiInGetID PROTO :XWORD,:XWORD
midiInGetNumDevs PROTO
midiInMessage PROTO :XWORD,:XWORD,:XWORD,:XWORD
midiInOpen PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
midiInPrepareHeader PROTO :XWORD,:XWORD,:XWORD
midiInReset PROTO :XWORD
midiInStart PROTO :XWORD
midiInStop PROTO :XWORD
midiInUnprepareHeader PROTO :XWORD,:XWORD,:XWORD
midiOutCacheDrumPatches PROTO :XWORD,:XWORD,:XWORD,:XWORD
midiOutCachePatches PROTO :XWORD,:XWORD,:XWORD,:XWORD
midiOutClose PROTO :XWORD
midiOutGetDevCapsA PROTO :XWORD,:XWORD,:XWORD
midiOutGetDevCapsW PROTO :XWORD,:XWORD,:XWORD
midiOutGetErrorTextA PROTO :XWORD,:XWORD,:XWORD
midiOutGetErrorTextW PROTO :XWORD,:XWORD,:XWORD
midiOutGetID PROTO :XWORD,:XWORD
midiOutGetNumDevs PROTO
midiOutGetVolume PROTO :XWORD,:XWORD
midiOutLongMsg PROTO :XWORD,:XWORD,:XWORD
midiOutMessage PROTO :XWORD,:XWORD,:XWORD,:XWORD
midiOutOpen PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
midiOutPrepareHeader PROTO :XWORD,:XWORD,:XWORD
midiOutReset PROTO :XWORD
midiOutSetVolume PROTO :XWORD,:XWORD
midiOutShortMsg PROTO :XWORD,:XWORD
midiOutUnprepareHeader PROTO :XWORD,:XWORD,:XWORD
midiStreamClose PROTO :XWORD
midiStreamOpen PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
midiStreamOut PROTO :XWORD,:XWORD,:XWORD
midiStreamPause PROTO :XWORD
midiStreamPosition PROTO :XWORD,:XWORD,:XWORD
midiStreamProperty PROTO :XWORD,:XWORD,:XWORD
midiStreamRestart PROTO :XWORD
midiStreamStop PROTO :XWORD
mixerClose PROTO :XWORD
mixerGetControlDetailsA PROTO :XWORD,:XWORD,:XWORD
mixerGetControlDetailsW PROTO :XWORD,:XWORD,:XWORD
mixerGetDevCapsA PROTO :XWORD,:XWORD,:XWORD
mixerGetDevCapsW PROTO :XWORD,:XWORD,:XWORD
mixerGetID PROTO :XWORD,:XWORD,:XWORD
mixerGetLineControlsA PROTO :XWORD,:XWORD,:XWORD
mixerGetLineControlsW PROTO :XWORD,:XWORD,:XWORD
mixerGetLineInfoA PROTO :XWORD,:XWORD,:XWORD
mixerGetLineInfoW PROTO :XWORD,:XWORD,:XWORD
mixerGetNumDevs PROTO
mixerMessage PROTO :XWORD,:XWORD,:XWORD,:XWORD
mixerOpen PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
mixerSetControlDetails PROTO :XWORD,:XWORD,:XWORD
mmDrvInstall PROTO :XWORD,:XWORD,:XWORD,:XWORD
mmGetCurrentTask PROTO
mmioAdvance PROTO :XWORD,:XWORD,:XWORD
mmioAscend PROTO :XWORD,:XWORD,:XWORD
mmioClose PROTO :XWORD,:XWORD
mmioCreateChunk PROTO :XWORD,:XWORD,:XWORD
mmioDescend PROTO :XWORD,:XWORD,:XWORD,:XWORD
mmioFlush PROTO :XWORD,:XWORD
mmioGetInfo PROTO :XWORD,:XWORD,:XWORD
mmioInstallIOProcA PROTO :XWORD,:XWORD,:XWORD
mmioInstallIOProcW PROTO :XWORD,:XWORD,:XWORD
mmioOpenA PROTO :XWORD,:XWORD,:XWORD
mmioOpenW PROTO :XWORD,:XWORD,:XWORD
mmioRead PROTO :XWORD,:XWORD,:XWORD
mmioRenameA PROTO :XWORD,:XWORD,:XWORD,:XWORD
mmioRenameW PROTO :XWORD,:XWORD,:XWORD,:XWORD
mmioSeek PROTO :XWORD,:XWORD,:XWORD
mmioSendMessage PROTO :XWORD,:XWORD,:XWORD,:XWORD
mmioSetBuffer PROTO :XWORD,:XWORD,:XWORD,:XWORD
mmioSetInfo PROTO :XWORD,:XWORD,:XWORD
mmioStringToFOURCCA PROTO :XWORD,:XWORD
mmioStringToFOURCCW PROTO :XWORD,:XWORD
mmioWrite PROTO :XWORD,:XWORD,:XWORD
mmsystemGetVersion PROTO
mmTaskBlock PROTO :XWORD
mmTaskCreate PROTO :XWORD,:XWORD,:XWORD
mmTaskSignal PROTO :XWORD
mmTaskYield PROTO
IF (NTDDI_VERSION EQ NTDDI_VISTA)
    mod32Message PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
    mxd32Message PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
    NotifyCallbackData PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
ENDIF
OpenDriver PROTO :XWORD,:XWORD,:XWORD
PlaySoundA PROTO :XWORD,:XWORD,:XWORD
PlaySoundW PROTO :XWORD,:XWORD,:XWORD
SendDriverMessage PROTO :XWORD,:XWORD,:XWORD,:XWORD
sndPlaySoundA PROTO :XWORD,:XWORD
sndPlaySoundW PROTO :XWORD,:XWORD
IF (NTDDI_VERSION EQ NTDDI_VISTA)
    tid32Message PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
ENDIF
timeBeginPeriod PROTO :XWORD
timeEndPeriod PROTO :XWORD
timeGetDevCaps PROTO :XWORD,:XWORD
timeGetSystemTime PROTO :XWORD,:XWORD
timeGetTime PROTO
timeKillEvent PROTO :XWORD
timeSetEvent PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
waveInAddBuffer PROTO :XWORD,:XWORD,:XWORD
waveInClose PROTO :XWORD
waveInGetDevCapsA PROTO :XWORD,:XWORD,:XWORD
waveInGetDevCapsW PROTO :XWORD,:XWORD,:XWORD
waveInGetErrorTextA PROTO :XWORD,:XWORD,:XWORD
waveInGetErrorTextW PROTO :XWORD,:XWORD,:XWORD
waveInGetID PROTO :XWORD,:XWORD
waveInGetNumDevs PROTO
waveInGetPosition PROTO :XWORD,:XWORD,:XWORD
waveInMessage PROTO :XWORD,:XWORD,:XWORD,:XWORD
waveInOpen PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
waveInPrepareHeader PROTO :XWORD,:XWORD,:XWORD
waveInReset PROTO :XWORD
waveInStart PROTO :XWORD
waveInStop PROTO :XWORD
waveInUnprepareHeader PROTO :XWORD,:XWORD,:XWORD
waveOutBreakLoop PROTO :XWORD
waveOutClose PROTO :XWORD
waveOutGetDevCapsA PROTO :XWORD,:XWORD,:XWORD
waveOutGetDevCapsW PROTO :XWORD,:XWORD,:XWORD
waveOutGetErrorTextA PROTO :XWORD,:XWORD,:XWORD
waveOutGetErrorTextW PROTO :XWORD,:XWORD,:XWORD
waveOutGetID PROTO :XWORD,:XWORD
waveOutGetNumDevs PROTO
waveOutGetPitch PROTO :XWORD,:XWORD
waveOutGetPlaybackRate PROTO :XWORD,:XWORD
waveOutGetPosition PROTO :XWORD,:XWORD,:XWORD
waveOutGetVolume PROTO :XWORD,:XWORD
waveOutMessage PROTO :XWORD,:XWORD,:XWORD,:XWORD
waveOutOpen PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
waveOutPause PROTO :XWORD
waveOutPrepareHeader PROTO :XWORD,:XWORD,:XWORD
waveOutReset PROTO :XWORD
waveOutRestart PROTO :XWORD
waveOutSetPitch PROTO :XWORD,:XWORD
waveOutSetPlaybackRate PROTO :XWORD,:XWORD
waveOutSetVolume PROTO :XWORD,:XWORD
waveOutUnprepareHeader PROTO :XWORD,:XWORD,:XWORD
waveOutWrite PROTO :XWORD,:XWORD,:XWORD
IF (NTDDI_VERSION EQ NTDDI_VISTA)
    wid32Message PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
    wod32Message PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
    WOW32DriverCallback PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
    WOW32ResolveMultiMediaHandle PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
ENDIF
WOWAppExit PROTO :XWORD

IFDEF APP_UNICODE
    auxGetDevCaps EQU <auxGetDevCapsW>
    joyGetDevCaps EQU <joyGetDevCapsW>
    mciGetDeviceID EQU <mciGetDeviceIDW>
    mciGetDeviceIDFromElementID EQU <mciGetDeviceIDFromElementIDW>
    mciGetErrorString EQU <mciGetErrorStringW>
    mciSendCommand EQU <mciSendCommandW>
    mciSendString EQU <mciSendStringW>
    midiInGetDevCaps EQU <midiInGetDevCapsW>
    midiInGetErrorText EQU <midiInGetErrorTextW>
    midiOutGetDevCaps EQU <midiOutGetDevCapsW>
    midiOutGetErrorText EQU <midiOutGetErrorTextW>
    mixerGetControlDetails EQU <mixerGetControlDetailsW>
    mixerGetDevCaps EQU <mixerGetDevCapsW>
    mixerGetLineControls EQU <mixerGetLineControlsW>
    mixerGetLineInfo EQU <mixerGetLineInfoW>
    mmioInstallIOProc EQU <mmioInstallIOProcW>
    mmioOpen EQU <mmioOpenW>
    mmioRename EQU <mmioRenameW>
    mmioStringToFOURCC EQU <mmioStringToFOURCCW>
    PlaySound EQU <PlaySoundW>
    sndPlaySound EQU <sndPlaySoundW>
    waveInGetDevCaps EQU <waveInGetDevCapsW>
    waveInGetErrorText EQU <waveInGetErrorTextW>
    waveOutGetDevCaps EQU <waveOutGetDevCapsW>
    waveOutGetErrorText EQU <waveOutGetErrorTextW>
ELSE
    auxGetDevCaps EQU <auxGetDevCapsA>
    joyGetDevCaps EQU <joyGetDevCapsA>
    mciGetDeviceID EQU <mciGetDeviceIDA>
    mciGetDeviceIDFromElementID EQU <mciGetDeviceIDFromElementIDA>
    mciGetErrorString EQU <mciGetErrorStringA>
    mciSendCommand EQU <mciSendCommandA>
    mciSendString EQU <mciSendStringA>
    midiInGetDevCaps EQU <midiInGetDevCapsA>
    midiInGetErrorText EQU <midiInGetErrorTextA>
    midiOutGetDevCaps EQU <midiOutGetDevCapsA>
    midiOutGetErrorText EQU <midiOutGetErrorTextA>
    mixerGetControlDetails EQU <mixerGetControlDetailsA>
    mixerGetDevCaps EQU <mixerGetDevCapsA>
    mixerGetLineControls EQU <mixerGetLineControlsA>
    mixerGetLineInfo EQU <mixerGetLineInfoA>
    mmioInstallIOProc EQU <mmioInstallIOProcA>
    mmioOpen EQU <mmioOpenA>
    mmioRename EQU <mmioRenameA>
    mmioStringToFOURCC EQU <mmioStringToFOURCCA>
    PlaySound EQU <PlaySoundA>
    sndPlaySound EQU <sndPlaySoundA>
    waveInGetDevCaps EQU <waveInGetDevCapsA>
    waveInGetErrorText EQU <waveInGetErrorTextA>
    waveOutGetDevCaps EQU <waveOutGetDevCapsA>
    waveOutGetErrorText EQU <waveOutGetErrorTextA>
ENDIF


;======================= Undocumented functions (unknown arguments) =======================;
;IF (NTDDI_VERSION LT NTDDI_VISTA)
;    gfxAddGfx PROTO :VARARG
;    gfxBatchChange PROTO :VARARG
;    gfxCreateGfxFactoriesList PROTO :VARARG
;    gfxCreateZoneFactoriesList PROTO :VARARG
;    gfxDestroyDeviceInterfaceList PROTO :VARARG
;    gfxEnumerateGfxs PROTO :VARARG
;    gfxLogoff PROTO :VARARG
;    gfxLogon PROTO :VARARG
;    gfxModifyGfx PROTO :VARARG
;    gfxOpenGfx PROTO :VARARG
;    gfxRemoveGfx PROTO :VARARG
;    MigrateAllDrivers PROTO :VARARG
;    MigrateSoundEvents PROTO :VARARG
;    winmmDbgOut PROTO :VARARG
;    WinmmLogoff PROTO :VARARG
;    WinmmLogon PROTO :VARARG
;    winmmSetDebugLevel PROTO :VARARG
;ENDIF

ENDIF ;WINMM_INC
