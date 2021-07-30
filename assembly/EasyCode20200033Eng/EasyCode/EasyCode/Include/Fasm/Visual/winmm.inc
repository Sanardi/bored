; ====================================================;
;                                                     ;
;      winmm.inc for EC v2 Fasm visual projects       ;
;                   (version 1.0.3)                   ;
;                                                     ;
;            Copyright © Ramon Sala - 2018            ;
;                                                     ;
; ====================================================;

if  ~defined WINMM_INC
define WINMM_INC 1

MAXPNAMELEN                                     equ     32
MAXERRORLENGTH                                  equ     256
MAX_JOYSTICKOEMVXDNAME                          equ     260

if ~defined MM_MICROSOFT
    MM_MICROSOFT                                equ     1
end if

if ~defined MM_MIDI_MAPPER
    MM_MIDI_MAPPER                              equ     1
    MM_WAVE_MAPPER                              equ     2
    MM_SNDBLST_MIDIOUT                          equ     3
    MM_SNDBLST_MIDIIN                           equ     4
    MM_SNDBLST_SYNTH                            equ     5
    MM_SNDBLST_WAVEOUT                          equ     6
    MM_SNDBLST_WAVEIN                           equ     7
    MM_ADLIB                                    equ     9
    MM_MPU401_MIDIOUT                           equ     10
    MM_MPU401_MIDIIN                            equ     11
    MM_PC_JOYSTICK                              equ     12
end if

TIME_MS                                         equ     0001H
TIME_SAMPLES                                    equ     0002H
TIME_BYTES                                      equ     0004H
TIME_SMPTE                                      equ     0008H
TIME_MIDI                                       equ     0010H
TIME_TICKS                                      equ     0020H

MM_JOY1MOVE                                     equ     03A0H
MM_JOY2MOVE                                     equ     03A1H
MM_JOY1ZMOVE                                    equ     03A2H
MM_JOY2ZMOVE                                    equ     03A3H
MM_JOY1BUTTONDOWN                               equ     03B5H
MM_JOY2BUTTONDOWN                               equ     03B6H
MM_JOY1BUTTONUP                                 equ     03B7H
MM_JOY2BUTTONUP                                 equ     03B8H

MM_MCINOTIFY                                    equ     03B9H

MM_WOM_OPEN                                     equ     03BBH
MM_WOM_CLOSE                                    equ     03BCH
MM_WOM_DONE                                     equ     03BDH

MM_WIM_OPEN                                     equ     03BEH
MM_WIM_CLOSE                                    equ     03BFH
MM_WIM_DATA                                     equ     03C0H

MM_MIM_OPEN                                     equ     03C1H
MM_MIM_CLOSE                                    equ     03C2H
MM_MIM_DATA                                     equ     03C3H
MM_MIM_LONGDATA                                 equ     03C4H
MM_MIM_ERROR                                    equ     03C5H
MM_MIM_LONGERROR                                equ     03C6H

MM_MOM_OPEN                                     equ     03C7H
MM_MOM_CLOSE                                    equ     03C8H
MM_MOM_DONE                                     equ     03C9H

if ~defined MM_DRVM_OPEN
    MM_DRVM_OPEN                                equ     03D0H
    MM_DRVM_CLOSE                               equ     03D1H
    MM_DRVM_DATA                                equ     03D2H
    MM_DRVM_ERROR                               equ     03D3H
end if

MM_STREAM_OPEN                                  equ     03D4H
MM_STREAM_CLOSE                                 equ     03D5H
MM_STREAM_DONE                                  equ     03D6H
MM_STREAM_ERROR                                 equ     03D7H

MM_MOM_POSITIONCB                               equ     03CAH

if ~defined MM_MCISIGNAL
    MM_MCISIGNAL                                equ     03CBH
end if

MM_MIM_MOREDATA                                 equ     03CCH

MM_MIXM_LINE_CHANGE                             equ     03D0H
MM_MIXM_CONTROL_CHANGE                          equ     03D1H

MMSYSERR_BASE                                   equ     0
WAVERR_BASE                                     equ     32
MIDIERR_BASE                                    equ     64
TIMERR_BASE                                     equ     96
JOYERR_BASE                                     equ     160
MCIERR_BASE                                     equ     256
MIXERR_BASE                                     equ     1024

MCI_STRING_OFFSET                               equ     512
MCI_VD_OFFSET                                   equ     1024
MCI_CD_OFFSET                                   equ     1088
MCI_WAVE_OFFSET                                 equ     1152
MCI_SEQ_OFFSET                                  equ     1216

MMSYSERR_NOERROR                                equ     0
MMSYSERR_ERROR                                  equ     (MMSYSERR_BASE + 1)
MMSYSERR_BADDEVICEID                            equ     (MMSYSERR_BASE + 2)
MMSYSERR_NOTENABLED                             equ     (MMSYSERR_BASE + 3)
MMSYSERR_ALLOCATED                              equ     (MMSYSERR_BASE + 4)
MMSYSERR_INVALHANDLE                            equ     (MMSYSERR_BASE + 5)
MMSYSERR_NODRIVER                               equ     (MMSYSERR_BASE + 6)
MMSYSERR_NOMEM                                  equ     (MMSYSERR_BASE + 7)
MMSYSERR_NOTSUPPORTED                           equ     (MMSYSERR_BASE + 8)
MMSYSERR_BADERRNUM                              equ     (MMSYSERR_BASE + 9)
MMSYSERR_INVALFLAG                              equ     (MMSYSERR_BASE + 10)
MMSYSERR_INVALPARAM                             equ     (MMSYSERR_BASE + 11)
MMSYSERR_HANDLEBUSY                             equ     (MMSYSERR_BASE + 12)

MMSYSERR_INVALIDALIAS                           equ     (MMSYSERR_BASE + 13)
MMSYSERR_BADDB                                  equ     (MMSYSERR_BASE + 14)
MMSYSERR_KEYNOTFOUND                            equ     (MMSYSERR_BASE + 15)
MMSYSERR_READERROR                              equ     (MMSYSERR_BASE + 16)
MMSYSERR_WRITEERROR                             equ     (MMSYSERR_BASE + 17)
MMSYSERR_DELETEERROR                            equ     (MMSYSERR_BASE + 18)
MMSYSERR_VALNOTFOUND                            equ     (MMSYSERR_BASE + 19)
MMSYSERR_NODRIVERCB                             equ     (MMSYSERR_BASE + 20)
MMSYSERR_MOREDATA                               equ     (MMSYSERR_BASE + 21)
MMSYSERR_LASTERROR                              equ     (MMSYSERR_BASE + 21)

if ~defined DRV_LOAD
    DRV_LOAD                                    equ     00001H
    DRV_ENABLE                                  equ     00002H
    DRV_OPEN                                    equ     00003H
    DRV_CLOSE                                   equ     00004H
    DRV_DISABLE                                 equ     00005H
    DRV_FREE                                    equ     00006H
    DRV_CONFIGURE                               equ     00007H
    DRV_QUERYCONFIGURE                          equ     00008H
    DRV_INSTALL                                 equ     00009H
    DRV_REMOVE                                  equ     0000AH
    DRV_EXITSESSION                             equ     0000BH
    DRV_POWER                                   equ     0000FH
    DRV_RESERVED                                equ     00800H
    DRV_USER                                    equ     04000H
    
    DRVCNF_CANCEL                               equ     00000H
    DRVCNF_OK                                   equ     00001H
    DRVCNF_RESTART                              equ     00002H
    
    struct DRVCONFIGINFO
        dwDCISize                               dd      ?
        lpszDCISectionName                      xptr    ?
        lpszDCIAliasName                        xptr    ?
    ends
end if

DRV_CANCEL                                     equ     DRVCNF_CANCEL
DRV_OK                                         equ     DRVCNF_OK
DRV_RESTART                                    equ     DRVCNF_RESTART

DRV_MCI_FIRST                                  equ     DRV_RESERVED
DRV_MCI_LAST                                   equ     (DRV_RESERVED + 0FFFH)

CALLBACK_TYPEMASK                              equ     000070000H
CALLBACK_NULL                                  equ     000000000H
CALLBACK_WINDOW                                equ     000010000H
CALLBACK_TASK                                  equ     000020000H
CALLBACK_FUNCTION                              equ     000030000H
CALLBACK_THREAD                                equ     CALLBACK_TASK
CALLBACK_EVENT                                 equ     000050000H

SND_SYNC                                       equ     00000H
SND_ASYNC                                      equ     00001H
SND_NODEFAULT                                  equ     00002H
SND_MEMORY                                     equ     00004H
SND_LOOP                                       equ     00008H
SND_NOSTOP                                     equ     00010H

SND_PURGE                                      equ     00040H
SND_APPLICATION                                equ     00080H

SND_NOWAIT                                     equ     000002000H
SND_ALIAS                                      equ     000010000H
SND_ALIAS_ID                                   equ     000110000H
SND_FILENAME                                   equ     000020000H
SND_RESOURCE                                   equ     000040004H

SND_ALIAS_START                                equ     0

SND_ALIAS_SYSTEMASTERISK                       equ     ((SND_ALIAS_START + 53h+2Ah) or ((53h + 2Ah) shl 8))
SND_ALIAS_SYSTEMQUESTION                       equ     ((SND_ALIAS_START + 53h+3Fh) or ((53h + 3Fh) shl 8))
SND_ALIAS_SYSTEMHAND                           equ     ((SND_ALIAS_START + 53h+48h) or ((53h + 48h) shl 8))
SND_ALIAS_SYSTEMEXIT                           equ     ((SND_ALIAS_START + 53h+45h) or ((53h + 45h) shl 8))
SND_ALIAS_SYSTEMSTART                          equ     ((SND_ALIAS_START + 53h+53h) or ((53h + 53h) shl 8))
SND_ALIAS_SYSTEMWELCOME                        equ     ((SND_ALIAS_START + 53h+57h) or ((53h + 57h) shl 8))
SND_ALIAS_SYSTEMEXCLAMATION                    equ     ((SND_ALIAS_START + 53h+21h) or ((53h + 21h) shl 8))
SND_ALIAS_SYSTEMDEFAULT                        equ     ((SND_ALIAS_START + 53h+44h) or ((53h + 44h) shl 8))

WAVERR_BADFORMAT                               equ     (WAVERR_BASE+0)
WAVERR_STILLPLAYING                            equ     (WAVERR_BASE+1)
WAVERR_UNPREPARED                              equ     (WAVERR_BASE+2)
WAVERR_SYNC                                    equ     (WAVERR_BASE+3)
WAVERR_LASTERROR                               equ     (WAVERR_BASE+3)

WOM_OPEN                                       equ     MM_WOM_OPEN
WOM_CLOSE                                      equ     MM_WOM_CLOSE
WOM_DONE                                       equ     MM_WOM_DONE
WIM_OPEN                                       equ     MM_WIM_OPEN
WIM_CLOSE                                      equ     MM_WIM_CLOSE
WIM_DATA                                       equ     MM_WIM_DATA

WAVE_MAPPER                                    equ     (-1)

WAVE_FORMAT_QUERY                              equ     00001H
WAVE_ALLOWSYNC                                 equ     00002H
WAVE_MAPPED                                    equ     00004H
WAVE_FORMAT_DIRECT                             equ     00008H
WAVE_FORMAT_DIRECT_QUERY                       equ     (WAVE_FORMAT_QUERY or WAVE_FORMAT_DIRECT)

WHDR_DONE                                      equ     000000001H
WHDR_PREPARED                                  equ     000000002H
WHDR_BEGINLOOP                                 equ     000000004H
WHDR_ENDLOOP                                   equ     000000008H
WHDR_INQUEUE                                   equ     000000010H

WAVECAPS_PITCH                                 equ     00001H
WAVECAPS_PLAYBACKRATE                          equ     00002H
WAVECAPS_VOLUME                                equ     00004H
WAVECAPS_LRVOLUME                              equ     00008H
WAVECAPS_SYNC                                  equ     00010H
WAVECAPS_SAMPLEACCURATE                        equ     00020H

WAVE_INVALIDFORMAT                             equ     00000000H
WAVE_FORMAT_1M08                               equ     00000001H
WAVE_FORMAT_1S08                               equ     00000002H
WAVE_FORMAT_1M16                               equ     00000004H
WAVE_FORMAT_1S16                               equ     00000008H
WAVE_FORMAT_2M08                               equ     00000010H
WAVE_FORMAT_2S08                               equ     00000020H
WAVE_FORMAT_2M16                               equ     00000040H
WAVE_FORMAT_2S16                               equ     00000080H
WAVE_FORMAT_4M08                               equ     00000100H
WAVE_FORMAT_4S08                               equ     00000200H
WAVE_FORMAT_4M16                               equ     00000400H
WAVE_FORMAT_4S16                               equ     00000800H
WAVE_FORMAT_44M08                              equ     00000100H
WAVE_FORMAT_44S08                              equ     00000200H
WAVE_FORMAT_44M16                              equ     00000400H
WAVE_FORMAT_44S16                              equ     00000800H
WAVE_FORMAT_48M08                              equ     00001000H
WAVE_FORMAT_48S08                              equ     00002000H
WAVE_FORMAT_48M16                              equ     00004000H
WAVE_FORMAT_48S16                              equ     00008000H
WAVE_FORMAT_96M08                              equ     00010000H
WAVE_FORMAT_96S08                              equ     00020000H
WAVE_FORMAT_96M16                              equ     00040000H
WAVE_FORMAT_96S16                              equ     00080000H

MIDIERR_UNPREPARED                             equ     (MIDIERR_BASE + 0)
MIDIERR_STILLPLAYING                           equ     (MIDIERR_BASE + 1)
MIDIERR_NOMAP                                  equ     (MIDIERR_BASE + 2)
MIDIERR_NOTREADY                               equ     (MIDIERR_BASE + 3)
MIDIERR_NODEVICE                               equ     (MIDIERR_BASE + 4)
MIDIERR_INVALIDSETUP                           equ     (MIDIERR_BASE + 5)
MIDIERR_BADOPENMODE                            equ     (MIDIERR_BASE + 6)
MIDIERR_DONT_CONTINUE                          equ     (MIDIERR_BASE + 7)
MIDIERR_LASTERROR                              equ     (MIDIERR_BASE + 7)

MIM_OPEN                                       equ     MM_MIM_OPEN
MIM_CLOSE                                      equ     MM_MIM_CLOSE
MIM_DATA                                       equ     MM_MIM_DATA
MIM_LONGDATA                                   equ     MM_MIM_LONGDATA
MIM_ERROR                                      equ     MM_MIM_ERROR
MIM_LONGERROR                                  equ     MM_MIM_LONGERROR
MOM_OPEN                                       equ     MM_MOM_OPEN
MOM_CLOSE                                      equ     MM_MOM_CLOSE
MOM_DONE                                       equ     MM_MOM_DONE

MIM_MOREDATA                                   equ     MM_MIM_MOREDATA
MOM_POSITIONCB                                 equ     MM_MOM_POSITIONCB

MIDIMAPPER                                     equ     (-1)
MIDI_MAPPER                                    equ     (-1)

MIDI_IO_STATUS                                 equ     00000020H

MIDI_CACHE_ALL                                 equ     1
MIDI_CACHE_BESTFIT                             equ     2
MIDI_CACHE_QUERY                               equ     3
MIDI_UNCACHE                                   equ     4

MOD_MIDIPORT                                   equ     1
MOD_SYNTH                                      equ     2
MOD_SQSYNTH                                    equ     3
MOD_FMSYNTH                                    equ     4
MOD_MAPPER                                     equ     5
MOD_WAVETABLE                                  equ     6
MOD_SWSYNTH                                    equ     7

MIDICAPS_VOLUME                                equ     00001H
MIDICAPS_LRVOLUME                              equ     00002H
MIDICAPS_CACHE                                 equ     00004H
MIDICAPS_STREAM                                equ     00008H

MHDR_DONE                                      equ     00000001H
MHDR_PREPARED                                  equ     00000002H
MHDR_INQUEUE                                   equ     00000004H
MHDR_ISSTRM                                    equ     00000008H

MEVT_F_SHORT                                   equ     00000000H
MEVT_F_LONG                                    equ     80000000H
MEVT_F_CALLBACK                                equ     40000000H


MEVT_SHORTMSG                                  equ     0
MEVT_TEMPO                                     equ     1
MEVT_NO                                        equ     2

MEVT_LONGMSG                                   equ     080H
MEVT_COMMENT                                   equ     082H
MEVT_VERSION                                   equ     084H

MIDISTRM_ERROR                                 equ     (-2)

MIDIPROP_SET                                   equ     80000000H
MIDIPROP_GET                                   equ     40000000H

MIDIPROP_TIMEDIV                               equ     00000001H
MIDIPROP_TEMPO                                 equ     00000002H

MIDIPATCHSIZE                                  equ     128

AUX_MAPPER                                     equ     (-1)

AUXCAPS_CDAUDIO                                equ     1
AUXCAPS_AUXIN                                  equ     2
AUXCAPS_VOLUME                                 equ     00001H
AUXCAPS_LRVOLUME                               equ     00002H

MIXER_SHORT_NAME_CHARS                         equ     16
MIXER_LONG_NAME_CHARS                          equ     64

MIXERR_INVALLINE                               equ     (MIXERR_BASE+0)
MIXERR_INVALCONTROL                            equ     (MIXERR_BASE+1)
MIXERR_INVALVALUE                              equ     (MIXERR_BASE+2)
MIXERR_LASTERROR                               equ     (MIXERR_BASE+2)

MIXER_OBJECTF_HANDLE                           equ     80000000H
MIXER_OBJECTF_MIXER                            equ     00000000H
MIXER_OBJECTF_HMIXER                           equ     (MIXER_OBJECTF_HANDLE or MIXER_OBJECTF_MIXER)
MIXER_OBJECTF_WAVEOUT                          equ     10000000H
MIXER_OBJECTF_HWAVEOUT                         equ     (MIXER_OBJECTF_HANDLE or MIXER_OBJECTF_WAVEOUT)
MIXER_OBJECTF_WAVEIN                           equ     20000000H
MIXER_OBJECTF_HWAVEIN                          equ     (MIXER_OBJECTF_HANDLE or MIXER_OBJECTF_WAVEIN)
MIXER_OBJECTF_MIDIOUT                          equ     30000000H
MIXER_OBJECTF_HMIDIOUT                         equ     (MIXER_OBJECTF_HANDLE or MIXER_OBJECTF_MIDIOUT)
MIXER_OBJECTF_MIDIIN                           equ     40000000H
MIXER_OBJECTF_HMIDIIN                          equ     (MIXER_OBJECTF_HANDLE or MIXER_OBJECTF_MIDIIN)
MIXER_OBJECTF_AUX                              equ     50000000H

MIXERLINE_LINEF_ACTIVE                         equ     00000001H
MIXERLINE_LINEF_DISCONNECTED                   equ     00008000H
MIXERLINE_LINEF_SOURCE                         equ     80000000H

MIXERLINE_COMPONENTTYPE_DST_FIRST              equ     000000000H
MIXERLINE_COMPONENTTYPE_DST_UNDEFINED          equ     (MIXERLINE_COMPONENTTYPE_DST_FIRST + 0)
MIXERLINE_COMPONENTTYPE_DST_DIGITAL            equ     (MIXERLINE_COMPONENTTYPE_DST_FIRST + 1)
MIXERLINE_COMPONENTTYPE_DST_LINE               equ     (MIXERLINE_COMPONENTTYPE_DST_FIRST + 2)
MIXERLINE_COMPONENTTYPE_DST_MONITOR            equ     (MIXERLINE_COMPONENTTYPE_DST_FIRST + 3)
MIXERLINE_COMPONENTTYPE_DST_SPEAKERS           equ     (MIXERLINE_COMPONENTTYPE_DST_FIRST + 4)
MIXERLINE_COMPONENTTYPE_DST_HEADPHONES         equ     (MIXERLINE_COMPONENTTYPE_DST_FIRST + 5)
MIXERLINE_COMPONENTTYPE_DST_TELEPHONE          equ     (MIXERLINE_COMPONENTTYPE_DST_FIRST + 6)
MIXERLINE_COMPONENTTYPE_DST_WAVEIN             equ     (MIXERLINE_COMPONENTTYPE_DST_FIRST + 7)
MIXERLINE_COMPONENTTYPE_DST_VOICEIN            equ     (MIXERLINE_COMPONENTTYPE_DST_FIRST + 8)
MIXERLINE_COMPONENTTYPE_DST_LAST               equ     (MIXERLINE_COMPONENTTYPE_DST_FIRST + 8)

MIXERLINE_COMPONENTTYPE_SRC_FIRST              equ     00001000H
MIXERLINE_COMPONENTTYPE_SRC_UNDEFINED          equ     (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 0)
MIXERLINE_COMPONENTTYPE_SRC_DIGITAL            equ     (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 1)
MIXERLINE_COMPONENTTYPE_SRC_LINE               equ     (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 2)
MIXERLINE_COMPONENTTYPE_SRC_MICROPHONE         equ     (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 3)
MIXERLINE_COMPONENTTYPE_SRC_SYNTHESIZER        equ     (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 4)
MIXERLINE_COMPONENTTYPE_SRC_COMPACTDISC        equ     (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 5)
MIXERLINE_COMPONENTTYPE_SRC_TELEPHONE          equ     (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 6)
MIXERLINE_COMPONENTTYPE_SRC_PCSPEAKER          equ     (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 7)
MIXERLINE_COMPONENTTYPE_SRC_WAVEOUT            equ     (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 8)
MIXERLINE_COMPONENTTYPE_SRC_AUXILIARY          equ     (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 9)
MIXERLINE_COMPONENTTYPE_SRC_ANALOG             equ     (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 10)
MIXERLINE_COMPONENTTYPE_SRC_LAST               equ     (MIXERLINE_COMPONENTTYPE_SRC_FIRST + 10)

MIXERLINE_TARGETTYPE_UNDEFINED                 equ     0
MIXERLINE_TARGETTYPE_WAVEOUT                   equ     1
MIXERLINE_TARGETTYPE_WAVEIN                    equ     2
MIXERLINE_TARGETTYPE_MIDIOUT                   equ     3
MIXERLINE_TARGETTYPE_MIDIIN                    equ     4
MIXERLINE_TARGETTYPE_AUX                       equ     5

MIXER_GETLINEINFOF_DESTINATION                 equ     00000000H
MIXER_GETLINEINFOF_SOURCE                      equ     00000001H
MIXER_GETLINEINFOF_LINEID                      equ     00000002H
MIXER_GETLINEINFOF_COMPONENTTYPE               equ     00000003H
MIXER_GETLINEINFOF_TARGETTYPE                  equ     00000004H
MIXER_GETLINEINFOF_QUERYMASK                   equ     0000000FH

MIXERCONTROL_CONTROLF_UNIFORM                  equ     00000001H
MIXERCONTROL_CONTROLF_MULTIPLE                 equ     00000002H
MIXERCONTROL_CONTROLF_DISABLED                 equ     80000000H

MIXERCONTROL_CT_CLASS_MASK                     equ     0F0000000H
MIXERCONTROL_CT_CLASS_CUSTOM                   equ     00000000H
MIXERCONTROL_CT_CLASS_METER                    equ     10000000H
MIXERCONTROL_CT_CLASS_SWITCH                   equ     20000000H
MIXERCONTROL_CT_CLASS_NUMBER                   equ     30000000H
MIXERCONTROL_CT_CLASS_SLIDER                   equ     40000000H
MIXERCONTROL_CT_CLASS_FADER                    equ     50000000H
MIXERCONTROL_CT_CLASS_TIME                     equ     60000000H
MIXERCONTROL_CT_CLASS_LIST                     equ     70000000H

MIXERCONTROL_CT_SUBCLASS_MASK                  equ     0F000000H

MIXERCONTROL_CT_SC_SWITCH_BOOLEAN              equ     00000000H
MIXERCONTROL_CT_SC_SWITCH_BUTTON               equ     01000000H

MIXERCONTROL_CT_SC_METER_POLLED                equ     00000000H

MIXERCONTROL_CT_SC_TIME_MICROSECS              equ     00000000H
MIXERCONTROL_CT_SC_TIME_MILLISECS              equ     01000000H

MIXERCONTROL_CT_SC_LIST_SINGLE                 equ     00000000H
MIXERCONTROL_CT_SC_LIST_MULTIPLE               equ     01000000H

MIXERCONTROL_CT_UNITS_MASK                     equ     00FF0000H
MIXERCONTROL_CT_UNITS_CUSTOM                   equ     00000000H
MIXERCONTROL_CT_UNITS_BOOLEAN                  equ     00010000H
MIXERCONTROL_CT_UNITS_SIGNED                   equ     00020000H
MIXERCONTROL_CT_UNITS_UNSIGNED                 equ     00030000H
MIXERCONTROL_CT_UNITS_DECIBELS                 equ     00040000H
MIXERCONTROL_CT_UNITS_PERCENT                  equ     00050000H

MIXERCONTROL_CONTROLTYPE_CUSTOM                equ     (MIXERCONTROL_CT_CLASS_CUSTOM or MIXERCONTROL_CT_UNITS_CUSTOM)
MIXERCONTROL_CONTROLTYPE_BOOLEANMETER          equ     (MIXERCONTROL_CT_CLASS_METER or MIXERCONTROL_CT_SC_METER_POLLED or MIXERCONTROL_CT_UNITS_BOOLEAN)
MIXERCONTROL_CONTROLTYPE_SIGNEDMETER           equ     (MIXERCONTROL_CT_CLASS_METER or MIXERCONTROL_CT_SC_METER_POLLED or MIXERCONTROL_CT_UNITS_SIGNED)
MIXERCONTROL_CONTROLTYPE_PEAKMETER             equ     (MIXERCONTROL_CONTROLTYPE_SIGNEDMETER + 1)
MIXERCONTROL_CONTROLTYPE_UNSIGNEDMETER         equ     (MIXERCONTROL_CT_CLASS_METER or MIXERCONTROL_CT_SC_METER_POLLED or MIXERCONTROL_CT_UNITS_UNSIGNED)
MIXERCONTROL_CONTROLTYPE_BOOLEAN               equ     (MIXERCONTROL_CT_CLASS_SWITCH or MIXERCONTROL_CT_SC_SWITCH_BOOLEAN or MIXERCONTROL_CT_UNITS_BOOLEAN)
MIXERCONTROL_CONTROLTYPE_ONOFF                 equ     (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 1)
MIXERCONTROL_CONTROLTYPE_MUTE                  equ     (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 2)
MIXERCONTROL_CONTROLTYPE_MONO                  equ     (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 3)
MIXERCONTROL_CONTROLTYPE_LOUDNESS              equ     (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 4)
MIXERCONTROL_CONTROLTYPE_STEREOENH             equ     (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 5)
MIXERCONTROL_CONTROLTYPE_BASS_BOOST            equ     (MIXERCONTROL_CONTROLTYPE_BOOLEAN + 00002277H)
MIXERCONTROL_CONTROLTYPE_BUTTON                equ     (MIXERCONTROL_CT_CLASS_SWITCH or MIXERCONTROL_CT_SC_SWITCH_BUTTON or MIXERCONTROL_CT_UNITS_BOOLEAN)
MIXERCONTROL_CONTROLTYPE_DECIBELS              equ     (MIXERCONTROL_CT_CLASS_NUMBER or MIXERCONTROL_CT_UNITS_DECIBELS)
MIXERCONTROL_CONTROLTYPE_SIGNED                equ     (MIXERCONTROL_CT_CLASS_NUMBER or MIXERCONTROL_CT_UNITS_SIGNED)
MIXERCONTROL_CONTROLTYPE_UNSIGNED              equ     (MIXERCONTROL_CT_CLASS_NUMBER or MIXERCONTROL_CT_UNITS_UNSIGNED)
MIXERCONTROL_CONTROLTYPE_PERCENT               equ     (MIXERCONTROL_CT_CLASS_NUMBER or MIXERCONTROL_CT_UNITS_PERCENT)
MIXERCONTROL_CONTROLTYPE_SLIDER                equ     (MIXERCONTROL_CT_CLASS_SLIDER or MIXERCONTROL_CT_UNITS_SIGNED)
MIXERCONTROL_CONTROLTYPE_PAN                   equ     (MIXERCONTROL_CONTROLTYPE_SLIDER + 1)
MIXERCONTROL_CONTROLTYPE_QSOUNDPAN             equ     (MIXERCONTROL_CONTROLTYPE_SLIDER + 2)
MIXERCONTROL_CONTROLTYPE_FADER                 equ     (MIXERCONTROL_CT_CLASS_FADER or MIXERCONTROL_CT_UNITS_UNSIGNED)
MIXERCONTROL_CONTROLTYPE_VOLUME                equ     (MIXERCONTROL_CONTROLTYPE_FADER + 1)
MIXERCONTROL_CONTROLTYPE_BASS                  equ     (MIXERCONTROL_CONTROLTYPE_FADER + 2)
MIXERCONTROL_CONTROLTYPE_TREBLE                equ     (MIXERCONTROL_CONTROLTYPE_FADER + 3)
MIXERCONTROL_CONTROLTYPE_EQUALIZER             equ     (MIXERCONTROL_CONTROLTYPE_FADER + 4)
MIXERCONTROL_CONTROLTYPE_SINGLESELECT          equ     (MIXERCONTROL_CT_CLASS_LIST or MIXERCONTROL_CT_SC_LIST_SINGLE or MIXERCONTROL_CT_UNITS_BOOLEAN)
MIXERCONTROL_CONTROLTYPE_MUX                   equ     (MIXERCONTROL_CONTROLTYPE_SINGLESELECT + 1)
MIXERCONTROL_CONTROLTYPE_MULTIPLESELECT        equ     (MIXERCONTROL_CT_CLASS_LIST or MIXERCONTROL_CT_SC_LIST_MULTIPLE or MIXERCONTROL_CT_UNITS_BOOLEAN)
MIXERCONTROL_CONTROLTYPE_MIXER                 equ     (MIXERCONTROL_CONTROLTYPE_MULTIPLESELECT + 1)
MIXERCONTROL_CONTROLTYPE_MICROTIME             equ     (MIXERCONTROL_CT_CLASS_TIME or MIXERCONTROL_CT_SC_TIME_MICROSECS or MIXERCONTROL_CT_UNITS_UNSIGNED)
MIXERCONTROL_CONTROLTYPE_MILLITIME             equ     (MIXERCONTROL_CT_CLASS_TIME or MIXERCONTROL_CT_SC_TIME_MILLISECS or MIXERCONTROL_CT_UNITS_UNSIGNED)

MIXER_GETLINECONTROLSF_ALL                     equ     00000000H
MIXER_GETLINECONTROLSF_ONEBYID                 equ     00000001H
MIXER_GETLINECONTROLSF_ONEBYTYPE               equ     00000002H
MIXER_GETLINECONTROLSF_QUERYMASK               equ     0000000FH

MIXER_GETCONTROLDETAILSF_VALUE                 equ     00000000H
MIXER_GETCONTROLDETAILSF_LISTTEXT              equ     00000001H
MIXER_GETCONTROLDETAILSF_QUERYMASK             equ     0000000FH

MIXER_SETCONTROLDETAILSF_VALUE                 equ     00000000H
MIXER_SETCONTROLDETAILSF_CUSTOM                equ     00000001H
MIXER_SETCONTROLDETAILSF_QUERYMASK             equ     0000000FH

TIMERR_NOERROR                                 equ     0
TIMERR_NOCANDO                                 equ     (TIMERR_BASE + 1)
TIMERR_STRUCT                                  equ     (TIMERR_BASE + 33)

TIME_ONESHOT                                   equ     0000H
TIME_PERIODIC                                  equ     0001H

TIME_CALLBACK_FUNCTION                         equ     0000H
TIME_CALLBACK_EVENT_SET                        equ     0010H
TIME_CALLBACK_EVENT_PULSE                      equ     0020H

TIME_KILL_SYNCHRONOUS                          equ     0100H

JOYERR_NOERROR                                 equ     0
JOYERR_PARMS                                   equ     (JOYERR_BASE + 5)
JOYERR_NOCANDO                                 equ     (JOYERR_BASE + 6)
JOYERR_UNPLUGGED                               equ     (JOYERR_BASE + 7)

JOY_BUTTON1                                    equ     0001H
JOY_BUTTON2                                    equ     0002H
JOY_BUTTON3                                    equ     0004H
JOY_BUTTON4                                    equ     0008H
JOY_BUTTON1CHG                                 equ     0100H
JOY_BUTTON2CHG                                 equ     0200H
JOY_BUTTON3CHG                                 equ     0400H
JOY_BUTTON4CHG                                 equ     0800H

JOY_BUTTON5                                    equ     00000010H
JOY_BUTTON6                                    equ     00000020H
JOY_BUTTON7                                    equ     00000040H
JOY_BUTTON8                                    equ     00000080H
JOY_BUTTON9                                    equ     00000100H
JOY_BUTTON10                                   equ     00000200H
JOY_BUTTON11                                   equ     00000400H
JOY_BUTTON12                                   equ     00000800H
JOY_BUTTON13                                   equ     00001000H
JOY_BUTTON14                                   equ     00002000H
JOY_BUTTON15                                   equ     00004000H
JOY_BUTTON16                                   equ     00008000H
JOY_BUTTON17                                   equ     00010000H
JOY_BUTTON18                                   equ     00020000H
JOY_BUTTON19                                   equ     00040000H
JOY_BUTTON20                                   equ     00080000H
JOY_BUTTON21                                   equ     00100000H
JOY_BUTTON22                                   equ     00200000H
JOY_BUTTON23                                   equ     00400000H
JOY_BUTTON24                                   equ     00800000H
JOY_BUTTON25                                   equ     01000000H
JOY_BUTTON26                                   equ     02000000H
JOY_BUTTON27                                   equ     04000000H
JOY_BUTTON28                                   equ     08000000H
JOY_BUTTON29                                   equ     10000000H
JOY_BUTTON30                                   equ     20000000H
JOY_BUTTON31                                   equ     40000000H
JOY_BUTTON32                                   equ     80000000H

JOY_POVCENTERED                                equ     (-1)
JOY_POVFORWARD                                 equ     0
JOY_POVRIGHT                                   equ     9000
JOY_POVBACKWARD                                equ     18000
JOY_POVLEFT                                    equ     27000

JOY_RETURNX                                    equ     00000001H
JOY_RETURNY                                    equ     00000002H
JOY_RETURNZ                                    equ     00000004H
JOY_RETURNR                                    equ     00000008H
JOY_RETURNU                                    equ     00000010H
JOY_RETURNV                                    equ     00000020H
JOY_RETURNPOV                                  equ     00000040H
JOY_RETURNBUTTONS                              equ     00000080H
JOY_RETURNRAWDATA                              equ     00000100H
JOY_RETURNPOVCTS                               equ     00000200H
JOY_RETURNCENTERED                             equ     00000400H
JOY_USEDEADZONE                                equ     00000800H
JOY_RETURNALL                                  equ     (JOY_RETURNX or JOY_RETURNY or JOY_RETURNZ or JOY_RETURNR or JOY_RETURNU or JOY_RETURNV or JOY_RETURNPOV or JOY_RETURNBUTTONS)
JOY_CAL_READALWAYS                             equ     00010000H
JOY_CAL_READXYONLY                             equ     00020000H
JOY_CAL_READ3                                  equ     00040000H
JOY_CAL_READ4                                  equ     00080000H
JOY_CAL_READXONLY                              equ     00100000H
JOY_CAL_READYONLY                              equ     00200000H
JOY_CAL_READ5                                  equ     00400000H
JOY_CAL_READ6                                  equ     00800000H
JOY_CAL_READZONLY                              equ     01000000H
JOY_CAL_READRONLY                              equ     02000000H
JOY_CAL_READUONLY                              equ     04000000H
JOY_CAL_READVONLY                              equ     08000000H

JOYSTICKID1                                    equ     0
JOYSTICKID2                                    equ     1

JOYCAPS_HASZ                                   equ     0001H
JOYCAPS_HASR                                   equ     0002H
JOYCAPS_HASU                                   equ     0004H
JOYCAPS_HASV                                   equ     0008H
JOYCAPS_HASPOV                                 equ     0010H
JOYCAPS_POV4DIR                                equ     0020H
JOYCAPS_POVCTS                                 equ     0040H

MMIOERR_BASE                                   equ     256
MMIOERR_FILENOTFOUND                           equ     (MMIOERR_BASE + 1)
MMIOERR_OUTOFMEMORY                            equ     (MMIOERR_BASE + 2)
MMIOERR_CANNOTOPEN                             equ     (MMIOERR_BASE + 3)
MMIOERR_CANNOTCLOSE                            equ     (MMIOERR_BASE + 4)
MMIOERR_CANNOTREAD                             equ     (MMIOERR_BASE + 5)
MMIOERR_CANNOTWRITE                            equ     (MMIOERR_BASE + 6)
MMIOERR_CANNOTSEEK                             equ     (MMIOERR_BASE + 7)
MMIOERR_CANNOTEXPAND                           equ     (MMIOERR_BASE + 8)
MMIOERR_CHUNKNOTFOUND                          equ     (MMIOERR_BASE + 9)
MMIOERR_UNBUFFERED                             equ     (MMIOERR_BASE + 10)
MMIOERR_PATHNOTFOUND                           equ     (MMIOERR_BASE + 11)
MMIOERR_ACCESSDENIED                           equ     (MMIOERR_BASE + 12)
MMIOERR_SHARINGVIOLATION                       equ     (MMIOERR_BASE + 13)
MMIOERR_NETWORKERROR                           equ     (MMIOERR_BASE + 14)
MMIOERR_TOOMANYOPENFILES                       equ     (MMIOERR_BASE + 15)
MMIOERR_INVALIDFILE                            equ     (MMIOERR_BASE + 16)

CFSEPCHAR                                      equ     '+'

MMIO_RWMODE                                    equ     00000003H
MMIO_SHAREMODE                                 equ     00000070H

MMIO_CREATE                                    equ     00001000H
MMIO_PARSE                                     equ     00000100H
MMIO_DELETE                                    equ     00000200H
MMIO_EXIST                                     equ     00004000H
MMIO_ALLOCBUF                                  equ     00010000H
MMIO_GETTEMP                                   equ     00020000H

MMIO_DIRTY                                     equ     10000000H

MMIO_READ                                      equ     00000000H
MMIO_WRITE                                     equ     00000001H
MMIO_READWRITE                                 equ     00000002H

MMIO_COMPAT                                    equ     00000000H
MMIO_EXCLUSIVE                                 equ     00000010H
MMIO_DENYWRITE                                 equ     00000020H
MMIO_DENYREAD                                  equ     00000030H
MMIO_DENYNONE                                  equ     00000040H

MMIO_FHOPEN                                    equ     0010H
MMIO_EMPTYBUF                                  equ     0010H
MMIO_TOUPPER                                   equ     0010H
MMIO_INSTALLPROC                               equ     00010000H
MMIO_GLOBALPROC                                equ     10000000H
MMIO_REMOVEPROC                                equ     00020000H
MMIO_UNICODEPROC                               equ     01000000H
MMIO_FINDPROC                                  equ     00040000H
MMIO_FINDCHUNK                                 equ     0010H
MMIO_FINDRIFF                                  equ     0020H
MMIO_FINDLIST                                  equ     0040H
MMIO_CREATERIFF                                equ     0020H
MMIO_CREATELIST                                equ     0040H

MMIOM_READ                                     equ     MMIO_READ
MMIOM_WRITE                                    equ     MMIO_WRITE
MMIOM_SEEK                                     equ     2
MMIOM_OPEN                                     equ     3
MMIOM_CLOSE                                    equ     4
MMIOM_WRITEFLUSH                               equ     5

MMIOM_RENAME                                   equ     6

MMIOM_USER                                     equ     0x8000

FOURCC_RIFF                                    equ     'RIFF'
FOURCC_LIST                                    equ     'LIST'
FOURCC_DOS                                     equ     'DOS '
FOURCC_MEM                                     equ     'MEM '

if ~defined SEEK_SET
    SEEK_SET                                   equ     0
    SEEK_CUR                                   equ     1
    SEEK_END                                   equ     2
end if

MMIO_DEFAULTBUFFER                             equ     8192
MCIERR_INVALID_DEVICE_ID                       equ     (MCIERR_BASE + 1)
MCIERR_UNRECOGNIZED_KEYWORD                    equ     (MCIERR_BASE + 3)
MCIERR_UNRECOGNIZED_COMMAND                    equ     (MCIERR_BASE + 5)
MCIERR_HARDWARE                                equ     (MCIERR_BASE + 6)
MCIERR_INVALID_DEVICE_NAME                     equ     (MCIERR_BASE + 7)
MCIERR_OUT_OF_MEMORY                           equ     (MCIERR_BASE + 8)
MCIERR_DEVICE_OPEN                             equ     (MCIERR_BASE + 9)
MCIERR_CANNOT_LOAD_DRIVER                      equ     (MCIERR_BASE + 10)
MCIERR_MISSING_COMMAND_STRING                  equ     (MCIERR_BASE + 11)
MCIERR_PARAM_OVERFLOW                          equ     (MCIERR_BASE + 12)
MCIERR_MISSING_STRING_ARGUMENT                 equ     (MCIERR_BASE + 13)
MCIERR_BAD_INTEGER                             equ     (MCIERR_BASE + 14)
MCIERR_PARSER_INTERNAL                         equ     (MCIERR_BASE + 15)
MCIERR_DRIVER_INTERNAL                         equ     (MCIERR_BASE + 16)
MCIERR_MISSING_PARAMETER                       equ     (MCIERR_BASE + 17)
MCIERR_UNSUPPORTED_FUNCTION                    equ     (MCIERR_BASE + 18)
MCIERR_FILE_NOT_FOUND                          equ     (MCIERR_BASE + 19)
MCIERR_DEVICE_NOT_READY                        equ     (MCIERR_BASE + 20)
MCIERR_INTERNAL                                equ     (MCIERR_BASE + 21)
MCIERR_DRIVER                                  equ     (MCIERR_BASE + 22)
MCIERR_CANNOT_USE_ALL                          equ     (MCIERR_BASE + 23)
MCIERR_MULTIPLE                                equ     (MCIERR_BASE + 24)
MCIERR_EXTENSION_NOT_FOUND                     equ     (MCIERR_BASE + 25)
MCIERR_OUTOFRANGE                              equ     (MCIERR_BASE + 26)
MCIERR_FLAGS_NOT_COMPATIBLE                    equ     (MCIERR_BASE + 28)
MCIERR_FILE_NOT_SAVED                          equ     (MCIERR_BASE + 30)
MCIERR_DEVICE_TYPE_REQUIRED                    equ     (MCIERR_BASE + 31)
MCIERR_DEVICE_LOCKED                           equ     (MCIERR_BASE + 32)
MCIERR_DUPLICATE_ALIAS                         equ     (MCIERR_BASE + 33)
MCIERR_BAD_CONSTANT                            equ     (MCIERR_BASE + 34)
MCIERR_MUST_USE_SHAREABLE                      equ     (MCIERR_BASE + 35)
MCIERR_MISSING_DEVICE_NAME                     equ     (MCIERR_BASE + 36)
MCIERR_BAD_TIME_FORMAT                         equ     (MCIERR_BASE + 37)
MCIERR_NO_CLOSING_QUOTE                        equ     (MCIERR_BASE + 38)
MCIERR_DUPLICATE_FLAGS                         equ     (MCIERR_BASE + 39)
MCIERR_INVALID_FILE                            equ     (MCIERR_BASE + 40)
MCIERR_NULL_PARAMETER_BLOCK                    equ     (MCIERR_BASE + 41)
MCIERR_UNNAMED_RESOURCE                        equ     (MCIERR_BASE + 42)
MCIERR_NEW_REQUIRES_ALIAS                      equ     (MCIERR_BASE + 43)
MCIERR_NOTIFY_ON_AUTO_OPEN                     equ     (MCIERR_BASE + 44)
MCIERR_NO_ELEMENT_ALLOWED                      equ     (MCIERR_BASE + 45)
MCIERR_NONAPPLICABLE_FUNCTION                  equ     (MCIERR_BASE + 46)
MCIERR_ILLEGAL_FOR_AUTO_OPEN                   equ     (MCIERR_BASE + 47)
MCIERR_FILENAME_REQUIRED                       equ     (MCIERR_BASE + 48)
MCIERR_EXTRA_CHARACTERS                        equ     (MCIERR_BASE + 49)
MCIERR_DEVICE_NOT_INSTALLED                    equ     (MCIERR_BASE + 50)
MCIERR_GET_CD                                  equ     (MCIERR_BASE + 51)
MCIERR_SET_CD                                  equ     (MCIERR_BASE + 52)
MCIERR_SET_DRIVE                               equ     (MCIERR_BASE + 53)
MCIERR_DEVICE_LENGTH                           equ     (MCIERR_BASE + 54)
MCIERR_DEVICE_ORD_LENGTH                       equ     (MCIERR_BASE + 55)
MCIERR_NO_INTEGER                              equ     (MCIERR_BASE + 56)
MCIERR_WAVE_OUTPUTSINUSE                       equ     (MCIERR_BASE + 64)
MCIERR_WAVE_SETOUTPUTINUSE                     equ     (MCIERR_BASE + 65)
MCIERR_WAVE_INPUTSINUSE                        equ     (MCIERR_BASE + 66)
MCIERR_WAVE_SETINPUTINUSE                      equ     (MCIERR_BASE + 67)
MCIERR_WAVE_OUTPUTUNSPECIFIED                  equ     (MCIERR_BASE + 68)
MCIERR_WAVE_INPUTUNSPECIFIED                   equ     (MCIERR_BASE + 69)
MCIERR_WAVE_OUTPUTSUNSUITABLE                  equ     (MCIERR_BASE + 70)
MCIERR_WAVE_SETOUTPUTUNSUITABLE                equ     (MCIERR_BASE + 71)
MCIERR_WAVE_INPUTSUNSUITABLE                   equ     (MCIERR_BASE + 72)
MCIERR_WAVE_SETINPUTUNSUITABLE                 equ     (MCIERR_BASE + 73)
MCIERR_SEQ_DIV_INCOMPATIBLE                    equ     (MCIERR_BASE + 80)
MCIERR_SEQ_PORT_INUSE                          equ     (MCIERR_BASE + 81)
MCIERR_SEQ_PORT_NONEXISTENT                    equ     (MCIERR_BASE + 82)
MCIERR_SEQ_PORT_MAPNODEVICE                    equ     (MCIERR_BASE + 83)
MCIERR_SEQ_PORT_MISCERROR                      equ     (MCIERR_BASE + 84)
MCIERR_SEQ_TIMER                               equ     (MCIERR_BASE + 85)
MCIERR_SEQ_PORTUNSPECIFIED                     equ     (MCIERR_BASE + 86)
MCIERR_SEQ_NOMIDIPRESENT                       equ     (MCIERR_BASE + 87)
MCIERR_NO_WINDOW                               equ     (MCIERR_BASE + 90)
MCIERR_CREATEWINDOW                            equ     (MCIERR_BASE + 91)
MCIERR_FILE_READ                               equ     (MCIERR_BASE + 92)
MCIERR_FILE_WRITE                              equ     (MCIERR_BASE + 93)
MCIERR_NO_IDENTITY                             equ     (MCIERR_BASE + 94)
MCIERR_CUSTOM_DRIVER_BASE                      equ     (MCIERR_BASE + 256)

MCI_FIRST                                      equ     DRV_MCI_FIRST

MCI_OPEN                                       equ     0803H
MCI_CLOSE                                      equ     0804H
MCI_ESCAPE                                     equ     0805H
MCI_PLAY                                       equ     0806H
MCI_SEEK                                       equ     0807H
MCI_STOP                                       equ     0808H
MCI_PAUSE                                      equ     0809H
MCI_INFO                                       equ     080AH
MCI_GETDEVCAPS                                 equ     080BH
MCI_SPIN                                       equ     080CH
MCI_SET                                        equ     080DH
MCI_STEP                                       equ     080EH
MCI_RECORD                                     equ     080FH
MCI_SYSINFO                                    equ     0810H
MCI_BREAK                                      equ     0811H
MCI_SAVE                                       equ     0813H
MCI_STATUS                                     equ     0814H
MCI_CUE                                        equ     0830H
MCI_REALIZE                                    equ     0840H
MCI_WINDOW                                     equ     0841H
MCI_PUT                                        equ     0842H
MCI_WHERE                                      equ     0843H
MCI_FREEZE                                     equ     0844H
MCI_UNFREEZE                                   equ     0845H
MCI_LOAD                                       equ     0850H
MCI_CUT                                        equ     0851H
MCI_COPY                                       equ     0852H
MCI_PASTE                                      equ     0853H
MCI_UPDATE                                     equ     0854H
MCI_RESUME                                     equ     0855H
MCI_DELETE                                     equ     0856H

MCI_USER_MESSAGES                              equ     (DRV_MCI_FIRST + 400)
MCI_LAST                                       equ     0FFFH

;MCI_ALL_DEVICE_ID                             equ     (MCIDEVICEID - 1)

MCI_DEVTYPE_VCR                                equ     513
MCI_DEVTYPE_VIDEODISC                          equ     514
MCI_DEVTYPE_OVERLAY                            equ     515
MCI_DEVTYPE_CD_AUDIO                           equ     516
MCI_DEVTYPE_DAT                                equ     517
MCI_DEVTYPE_SCANNER                            equ     518
MCI_DEVTYPE_ANIMATION                          equ     519
MCI_DEVTYPE_DIGITAL_VIDEO                      equ     520
MCI_DEVTYPE_OTHER                              equ     521
MCI_DEVTYPE_WAVEFORM_AUDIO                     equ     522
MCI_DEVTYPE_SEQUENCER                          equ     523

MCI_DEVTYPE_FIRST                              equ     MCI_DEVTYPE_VCR
MCI_DEVTYPE_LAST                               equ     MCI_DEVTYPE_SEQUENCER

MCI_DEVTYPE_FIRST_USER                         equ     1000H

MCI_MODE_NOT_READY                             equ     (MCI_STRING_OFFSET + 12)
MCI_MODE_STOP                                  equ     (MCI_STRING_OFFSET + 13)
MCI_MODE_PLAY                                  equ     (MCI_STRING_OFFSET + 14)
MCI_MODE_RECORD                                equ     (MCI_STRING_OFFSET + 15)
MCI_MODE_SEEK                                  equ     (MCI_STRING_OFFSET + 16)
MCI_MODE_PAUSE                                 equ     (MCI_STRING_OFFSET + 17)
MCI_MODE_OPEN                                  equ     (MCI_STRING_OFFSET + 18)

MCI_FORMAT_MILLISECONDS                        equ     0
MCI_FORMAT_HMS                                 equ     1
MCI_FORMAT_MSF                                 equ     2
MCI_FORMAT_FRAMES                              equ     3
MCI_FORMAT_SMPTE_24                            equ     4
MCI_FORMAT_SMPTE_25                            equ     5
MCI_FORMAT_SMPTE_30                            equ     6
MCI_FORMAT_SMPTE_30DROP                        equ     7
MCI_FORMAT_BYTES                               equ     8
MCI_FORMAT_SAMPLES                             equ     9
MCI_FORMAT_TMSF                                equ     10


MCI_NOTIFY_SUCCESSFUL                          equ     0001H
MCI_NOTIFY_SUPERSEDED                          equ     0002H
MCI_NOTIFY_ABORTED                             equ     0004H
MCI_NOTIFY_FAILURE                             equ     0008H

MCI_NOTIFY                                     equ     00000001H
MCI_WAIT                                       equ     00000002H
MCI_FROM                                       equ     00000004H
MCI_TO                                         equ     00000008H
MCI_TRACK                                      equ     00000010H

MCI_OPEN_SHAREABLE                             equ     00000100H
MCI_OPEN_ELEMENT                               equ     00000200H
MCI_OPEN_ALIAS                                 equ     00000400H
MCI_OPEN_ELEMENT_ID                            equ     00000800H
MCI_OPEN_TYPE_ID                               equ     00001000H
MCI_OPEN_TYPE                                  equ     00002000H

MCI_SEEK_TO_START                              equ     00000100H
MCI_SEEK_TO_END                                equ     00000200H

MCI_STATUS_ITEM                                equ     00000100H
MCI_STATUS_START                               equ     00000200H

MCI_STATUS_LENGTH                              equ     00000001H
MCI_STATUS_POSITION                            equ     00000002H
MCI_STATUS_NUMBER_OF_TRACKS                    equ     00000003H
MCI_STATUS_MODE                                equ     00000004H
MCI_STATUS_MEDIA_PRESENT                       equ     00000005H
MCI_STATUS_TIME_FORMAT                         equ     00000006H
MCI_STATUS_READY                               equ     00000007H
MCI_STATUS_CURRENT_TRACK                       equ     00000008H

MCI_INFO_PRODUCT                               equ     00000100H
MCI_INFO_FILE                                  equ     00000200H
MCI_INFO_MEDIA_UPC                             equ     00000400H
MCI_INFO_MEDIA_IDENTITY                        equ     00000800H
MCI_INFO_NAME                                  equ     00001000H
MCI_INFO_COPYRIGHT                             equ     00002000H

MCI_GETDEVCAPS_ITEM                            equ     00000100H

MCI_GETDEVCAPS_CAN_RECORD                      equ     00000001H
MCI_GETDEVCAPS_HAS_AUDIO                       equ     00000002H
MCI_GETDEVCAPS_HAS_VIDEO                       equ     00000003H
MCI_GETDEVCAPS_DEVICE_TYPE                     equ     00000004H
MCI_GETDEVCAPS_USES_FILES                      equ     00000005H
MCI_GETDEVCAPS_COMPOUND_DEVICE                 equ     00000006H
MCI_GETDEVCAPS_CAN_EJECT                       equ     00000007H
MCI_GETDEVCAPS_CAN_PLAY                        equ     00000008H
MCI_GETDEVCAPS_CAN_SAVE                        equ     00000009H

MCI_SYSINFO_QUANTITY                           equ     00000100H
MCI_SYSINFO_OPEN                               equ     00000200H
MCI_SYSINFO_NAME                               equ     00000400H
MCI_SYSINFO_INSTALLNAME                        equ     00000800H

MCI_SET_DOOR_OPEN                              equ     00000100H
MCI_SET_DOOR_CLOSED                            equ     00000200H
MCI_SET_TIME_FORMAT                            equ     00000400H
MCI_SET_AUDIO                                  equ     00000800H
MCI_SET_VIDEO                                  equ     00001000H
MCI_SET_ON                                     equ     00002000H
MCI_SET_OFF                                    equ     00004000H

MCI_SET_AUDIO_ALL                              equ     00000000H
MCI_SET_AUDIO_LEFT                             equ     00000001H
MCI_SET_AUDIO_RIGHT                            equ     00000002H

MCI_BREAK_KEY                                  equ     00000100H
MCI_BREAK_HWND                                 equ     00000200H
MCI_BREAK_OFF                                  equ     00000400H

MCI_RECORD_INSERT                              equ     00000100H
MCI_RECORD_OVERWRITE                           equ     00000200H

MCI_SAVE_FILE                                  equ     00000100H

MCI_LOAD_FILE                                  equ     00000100H

MCI_VD_MODE_PARK                               equ     (MCI_VD_OFFSET + 1)

MCI_VD_MEDIA_CLV                               equ     (MCI_VD_OFFSET + 2)
MCI_VD_MEDIA_CAV                               equ     (MCI_VD_OFFSET + 3)
MCI_VD_MEDIA_OTHER                             equ     (MCI_VD_OFFSET + 4)

MCI_VD_FORMAT_TRACK                            equ     4001H

MCI_VD_PLAY_REVERSE                            equ     00010000H
MCI_VD_PLAY_FAST                               equ     00020000H
MCI_VD_PLAY_SPEED                              equ     00040000H
MCI_VD_PLAY_SCAN                               equ     00080000H
MCI_VD_PLAY_SLOW                               equ     00100000H

MCI_VD_SEEK_REVERSE                            equ     00010000H

MCI_VD_STATUS_SPEED                            equ     00004002H
MCI_VD_STATUS_FORWARD                          equ     00004003H
MCI_VD_STATUS_MEDIA_TYPE                       equ     00004004H
MCI_VD_STATUS_SIDE                             equ     00004005H
MCI_VD_STATUS_DISC_SIZE                        equ     00004006H

MCI_VD_GETDEVCAPS_CLV                          equ     00010000H
MCI_VD_GETDEVCAPS_CAV                          equ     00020000H

MCI_VD_SPIN_UP                                 equ     00010000H
MCI_VD_SPIN_DOWN                               equ     00020000H

MCI_VD_GETDEVCAPS_CAN_REVERSE                  equ     00004002H
MCI_VD_GETDEVCAPS_FAST_RATE                    equ     00004003H
MCI_VD_GETDEVCAPS_SLOW_RATE                    equ     00004004H
MCI_VD_GETDEVCAPS_NORMAL_RATE                  equ     00004005H

MCI_VD_STEP_FRAMES                             equ     00010000H
MCI_VD_STEP_REVERSE                            equ     00020000H

MCI_VD_ESCAPE_STRING                           equ     00000100H

MCI_CDA_STATUS_TYPE_TRACK                      equ     00004001H

MCI_CDA_TRACK_AUDIO                            equ     (MCI_CD_OFFSET + 0)
MCI_CDA_TRACK_OTHER                            equ     (MCI_CD_OFFSET + 1)

MCI_WAVE_PCM                                   equ     (MCI_WAVE_OFFSET + 0)
MCI_WAVE_MAPPER                                equ     (MCI_WAVE_OFFSET + 1)

MCI_WAVE_OPEN_BUFFER                           equ     00010000H

MCI_WAVE_SET_FORMATTAG                         equ     00010000H
MCI_WAVE_SET_CHANNELS                          equ     00020000H
MCI_WAVE_SET_SAMPLESPERSEC                     equ     00040000H
MCI_WAVE_SET_AVGBYTESPERSEC                    equ     00080000H
MCI_WAVE_SET_BLOCKALIGN                        equ     00100000H
MCI_WAVE_SET_BITSPERSAMPLE                     equ     00200000H

MCI_WAVE_INPUT                                 equ     00400000H
MCI_WAVE_OUTPUT                                equ     00800000H

MCI_WAVE_STATUS_FORMATTAG                      equ     00004001H
MCI_WAVE_STATUS_CHANNELS                       equ     00004002H
MCI_WAVE_STATUS_SAMPLESPERSEC                  equ     00004003H
MCI_WAVE_STATUS_AVGBYTESPERSEC                 equ     00004004H
MCI_WAVE_STATUS_BLOCKALIGN                     equ     00004005H
MCI_WAVE_STATUS_BITSPERSAMPLE                  equ     00004006H
MCI_WAVE_STATUS_LEVEL                          equ     00004007H

MCI_WAVE_SET_ANYINPUT                          equ     04000000H
MCI_WAVE_SET_ANYOUTPUT                         equ     08000000H

MCI_WAVE_GETDEVCAPS_INPUTS                     equ     00004001H
MCI_WAVE_GETDEVCAPS_OUTPUTS                    equ     00004002H

MCI_SEQ_DIV_PPQN                               equ     (0 + MCI_SEQ_OFFSET)
MCI_SEQ_DIV_SMPTE_24                           equ     (1 + MCI_SEQ_OFFSET)
MCI_SEQ_DIV_SMPTE_25                           equ     (2 + MCI_SEQ_OFFSET)
MCI_SEQ_DIV_SMPTE_30DROP                       equ     (3 + MCI_SEQ_OFFSET)
MCI_SEQ_DIV_SMPTE_30                           equ     (4 + MCI_SEQ_OFFSET)

MCI_SEQ_FORMAT_SONGPTR                         equ     4001H
MCI_SEQ_FILE                                   equ     4002H
MCI_SEQ_MIDI                                   equ     4003H
MCI_SEQ_SMPTE                                  equ     4004H
MCI_SEQ_NONE                                   equ     65533
MCI_SEQ_MAPPER                                 equ     65535

MCI_SEQ_STATUS_TEMPO                           equ     00004002H
MCI_SEQ_STATUS_PORT                            equ     00004003H
MCI_SEQ_STATUS_SLAVE                           equ     00004007H
MCI_SEQ_STATUS_MASTER                          equ     00004008H
MCI_SEQ_STATUS_OFFSET                          equ     00004009H
MCI_SEQ_STATUS_DIVTYPE                         equ     0000400AH
MCI_SEQ_STATUS_NAME                            equ     0000400BH
MCI_SEQ_STATUS_COPYRIGHT                       equ     0000400CH

MCI_SEQ_SET_TEMPO                              equ     00010000H
MCI_SEQ_SET_PORT                               equ     00020000H
MCI_SEQ_SET_SLAVE                              equ     00040000H
MCI_SEQ_SET_MASTER                             equ     00080000H
MCI_SEQ_SET_OFFSET                             equ     01000000H

MCI_ANIM_OPEN_WS                               equ     00010000H
MCI_ANIM_OPEN_PARENT                           equ     00020000H
MCI_ANIM_OPEN_NOSTATIC                         equ     00040000H

MCI_ANIM_PLAY_SPEED                            equ     00010000H
MCI_ANIM_PLAY_REVERSE                          equ     00020000H
MCI_ANIM_PLAY_FAST                             equ     00040000H
MCI_ANIM_PLAY_SLOW                             equ     00080000H
MCI_ANIM_PLAY_SCAN                             equ     00100000H

MCI_ANIM_STEP_REVERSE                          equ     00010000H
MCI_ANIM_STEP_FRAMES                           equ     00020000H

MCI_ANIM_STATUS_SPEED                          equ     00004001H
MCI_ANIM_STATUS_FORWARD                        equ     00004002H
MCI_ANIM_STATUS_HWND                           equ     00004003H
MCI_ANIM_STATUS_HPAL                           equ     00004004H
MCI_ANIM_STATUS_STRETCH                        equ     00004005H

MCI_ANIM_INFO_TEXT                             equ     00010000H

MCI_ANIM_GETDEVCAPS_CAN_REVERSE                equ     00004001H
MCI_ANIM_GETDEVCAPS_FAST_RATE                  equ     00004002H
MCI_ANIM_GETDEVCAPS_SLOW_RATE                  equ     00004003H
MCI_ANIM_GETDEVCAPS_NORMAL_RATE                equ     00004004H
MCI_ANIM_GETDEVCAPS_PALETTES                   equ     00004006H
MCI_ANIM_GETDEVCAPS_CAN_STRETCH                equ     00004007H
MCI_ANIM_GETDEVCAPS_MAX_WINDOWS                equ     00004008H

MCI_ANIM_REALIZE_NORM                          equ     00010000H
MCI_ANIM_REALIZE_BKGD                          equ     00020000H

MCI_ANIM_WINDOW_HWND                           equ     00010000H
MCI_ANIM_WINDOW_STATE                          equ     00040000H
MCI_ANIM_WINDOW_TEXT                           equ     00080000H
MCI_ANIM_WINDOW_ENABLE_STRETCH                 equ     00100000H
MCI_ANIM_WINDOW_DISABLE_STRETCH                equ     00200000H

MCI_ANIM_WINDOW_DEFAULT                        equ     00000000H

MCI_ANIM_RECT                                  equ     00010000H
MCI_ANIM_PUT_SOURCE                            equ     00020000H
MCI_ANIM_PUT_DESTINATION                       equ     00040000H

MCI_ANIM_WHERE_SOURCE                          equ     00020000H
MCI_ANIM_WHERE_DESTINATION                     equ     00040000H

MCI_ANIM_UPDATE_HDC                            equ     00020000H

MCI_OVLY_OPEN_WS                               equ     00010000H
MCI_OVLY_OPEN_PARENT                           equ     00020000H

MCI_OVLY_STATUS_HWND                           equ     00004001H
MCI_OVLY_STATUS_STRETCH                        equ     00004002H

MCI_OVLY_INFO_TEXT                             equ     00010000H

MCI_OVLY_GETDEVCAPS_CAN_STRETCH                equ     00004001H
MCI_OVLY_GETDEVCAPS_CAN_FREEZE                 equ     00004002H
MCI_OVLY_GETDEVCAPS_MAX_WINDOWS                equ     00004003H

MCI_OVLY_WINDOW_HWND                           equ     00010000H
MCI_OVLY_WINDOW_STATE                          equ     00040000H
MCI_OVLY_WINDOW_TEXT                           equ     00080000H
MCI_OVLY_WINDOW_ENABLE_STRETCH                 equ     00100000H
MCI_OVLY_WINDOW_DISABLE_STRETCH                equ     00200000H

MCI_OVLY_WINDOW_DEFAULT                        equ     00000000H

MCI_OVLY_RECT                                  equ     00010000H
MCI_OVLY_PUT_SOURCE                            equ     00020000H
MCI_OVLY_PUT_DESTINATION                       equ     00040000H
MCI_OVLY_PUT_FRAME                             equ     00080000H
MCI_OVLY_PUT_VIDEO                             equ     00100000H

MCI_OVLY_WHERE_SOURCE                          equ     00020000H
MCI_OVLY_WHERE_DESTINATION                     equ     00040000H
MCI_OVLY_WHERE_FRAME                           equ     00080000H
MCI_OVLY_WHERE_VIDEO                           equ     00100000H

NEWTRANSPARENT                                 equ     3
QUERYROPSUPPORT                                equ     40
SELECTDIB                                      equ     41


;======================================== Structures ======================================;
struct MIXERCONTROLA
    cbStruct          dd ?
    dwControlID       dd ?
    dwControlType     dd ?
    fdwControl        dd ?
    cMultipleItems    dd ?
    szShortName       db MIXER_SHORT_NAME_CHARS dup(?)
    szName            db MIXER_LONG_NAME_CHARS dup(?)
    union
        struct
            dwMinimum dd ?
            dwMaximum dd ?
        ends
        struct
            lMinimum  dd ?
            lMaximum  dd ?
        ends
        dwReserved    dd 6 dup(?)
    ends
    union
        cSteps        dd ?
        cbCustomData  dd ?
        _dwReserved   dd 6 dup(?)
    ends
ends

struct MIXERCONTROLW
    cbStruct          dd ?
    dwControlID       dd ?
    dwControlType     dd ?
    fdwControl        dd ?
    cMultipleItems    dd ?
    szShortName       dw MIXER_SHORT_NAME_CHARS dup(?)
    szName            dw MIXER_LONG_NAME_CHARS dup(?)
    union
        struct
            dwMinimum dd ?
            dwMaximum dd ?
        ends
        struct
            lMinimum  dd ?
            lMaximum  dd ?
        ends
        dwReserved    dd 6 dup(?)
    ends
    union
        cSteps        dd ?
        cbCustomData  dd ?
        _dwReserved   dd 6 dup(?)
    ends
ends

struct SMPTE
    hour   db ?
    min    db ?
    sec    db ?
    _frame db ?
    fps    db ?
    dummy  db ?
    pad    db 2 dup(?)
ends

struct MMTIME
    wType          dd ?
    union
        ms         dd ?
        sample     dd ?
        cb         dd ?
        ticks      dd ?
        smpte      SMPTE
        songptrpos dd ?
    ends
ends

struct DRVCONFIGINFOEX
    dwDCISize          dd   ?
    lpszDCISectionName xptr ?
    lpszDCIAliasName   xptr ?
    dnDevNode          dd   ?
ends

struct WAVEHDR
    lpData          xptr ?
    dwBufferLength  dd ?
    dwBytesRecorded dd ?
    dwUser          xptr ?
    dwFlags         dd ?
    dwLoops         dd ?
    lpNext          xptr ?
    reserved        dd ?
ends

struct WAVEOUTCAPSA
    wMid           dw ?
    wPid           dw ?
    vDriverVersion dd ?
    szPname        db MAXPNAMELEN dup(?)
    dwFormats      dd ?
    wChannels      dw ?
    wReserved1     dw ?
    dwSupport      dd ?
ends

struct WAVEOUTCAPSW
    wMid           dw ?
    wPid           dw ?
    vDriverVersion dd ?
    szPname        dw MAXPNAMELEN dup(?)
    dwFormats      dd ?
    wChannels      dw ?
    wReserved1     dw ?
    dwSupport      dd ?
ends

struct WAVEOUTCAPS2A
    wMid             dw ?
    wPid             dw ?
    vDriverVersion   dd ?
    szPname          db MAXPNAMELEN dup(?)
    dwFormats        dd ?
    wChannels        dw ?
    wReserved1       dw ?
    dwSupport        dd ?
    ManufacturerGuid GUID
    ProductGuid      GUID
    NameGuid         GUID
ends

struct WAVEOUTCAPS2W
    wMid             dw ?
    wPid             dw ?
    vDriverVersion   dd ?
    szPname          dw MAXPNAMELEN dup(?)
    dwFormats        dd ?
    wChannels        dw ?
    wReserved1       dw ?
    dwSupport        dd ?
    ManufacturerGuid GUID
    ProductGuid      GUID
    NameGuid         GUID
ends

struct WAVEINCAPSA
    wMid           dw ?
    wPid           dw ?
    vDriverVersion dd ?
    szPname        db MAXPNAMELEN dup(?)
    dwFormats      dd ?
    wChannels      dw ?
    wReserved1     dw ?
ends

struct WAVEINCAPSW
    wMid           dw ?
    wPid           dw ?
    vDriverVersion dd ?
    szPname        dw MAXPNAMELEN dup(?)
    dwFormats      dd ?
    wChannels      dw ?
    wReserved1     dw ?
ends

struct WAVEINCAPS2A
    wMid             dw ?
    wPid             dw ?
    vDriverVersion   dd ?
    szPname          db MAXPNAMELEN dup(?)
    dwFormats        dd ?
    wChannels        dw ?
    wReserved1       dw ?
    ManufacturerGuid GUID
    ProductGuid      GUID
    NameGuid         GUID
ends

struct WAVEINCAPS2W
    wMid             dw ?
    wPid             dw ?
    vDriverVersion   dd ?
    szPname          dw MAXPNAMELEN dup(?)
    dwFormats        dd ?
    wChannels        dw ?
    wReserved1       dw ?
    ManufacturerGuid GUID
    ProductGuid      GUID
    NameGuid         GUID
ends

if ~defined WAVE_FORMAT_PCM
    WAVE_FORMAT_PCM     equ 1
    
    struct WAVEFORMAT
        wFormatTag      dw  ?
        nChannels       dw  ?
        nSamplesPerSec  dd  ?
        nAvgBytesPerSec dd  ?
        nBlockAlign     dw  ?
    ends
    
    struct PCMWAVEFORMAT
        wf              WAVEFORMAT
        wBitsPerSample  dw  ?
    ends
end if

if ~defined WAVEFORMATEX_DEF
    WAVEFORMATEX_DEF equ 1
    struct WAVEFORMATEX
        wFormatTag      dw  ?
        nChannels       dw  ?
        nSamplesPerSec  dd  ?
        nAvgBytesPerSec dd  ?
        nBlockAlign     dw  ?
        wBitsPerSample  dw  ?
        cbSize          dw  ?
    ends
    _WAVEFORMATEX       equ 1
end if

struct MIDIOUTCAPSA
    wMid           dw ?
    wPid           dw ?
    vDriverVersion dd ?
    szPname        db MAXPNAMELEN dup(?)
    wTechnology    dw ?
    wVoices        dw ?
    wNotes         dw ?
    wChannelMask   dw ?
    dwSupport      dd ?
ends

struct MIDIOUTCAPSW
    wMid           dw ?
    wPid           dw ?
    vDriverVersion dd ?
    szPname        dw MAXPNAMELEN dup(?)
    wTechnology    dw ?
    wVoices        dw ?
    wNotes         dw ?
    wChannelMask   dw ?
    dwSupport      dd ?
ends

struct MIDIOUTCAPS2A
    wMid             dw ?
    wPid             dw ?
    vDriverVersion   dd ?
    szPname          db MAXPNAMELEN dup(?)
    wTechnology      dw ?
    wVoices          dw ?
    wNotes           dw ?
    wChannelMask     dw ?
    dwSupport        dd ?
    ManufacturerGuid GUID
    ProductGuid      GUID
    NameGuid         GUID
ends

struct MIDIOUTCAPS2W
    wMid             dw ?
    wPid             dw ?
    vDriverVersion   dd ?
    szPname          dw MAXPNAMELEN dup(?)
    wTechnology      dw ?
    wVoices          dw ?
    wNotes           dw ?
    wChannelMask     dw ?
    dwSupport        dd ?
    ManufacturerGuid GUID
    ProductGuid      GUID
    NameGuid         GUID
ends

struct MIDIINCAPSA
    wMid           dw ?
    wPid           dw ?
    vDriverVersion dd ?
    szPname        db MAXPNAMELEN dup(?)
    dwSupport      dd ?
ends

struct MIDIINCAPSW
    wMid           dw ?
    wPid           dw ?
    vDriverVersion dd ?
    szPname        dw MAXPNAMELEN dup(?)
    dwSupport      dd ?
ends

struct MIDIINCAPS2A
    wMid             dw ?
    wPid             dw ?
    vDriverVersion   dd ?
    szPname          db MAXPNAMELEN dup(?)
    dwSupport        dd ?
    ManufacturerGuid GUID
    ProductGuid      GUID
    NameGuid         GUID
ends

struct MIDIINCAPS2W
    wMid             dw ?
    wPid             dw ?
    vDriverVersion   dd ?
    szPname          dw MAXPNAMELEN dup(?)
    dwSupport        dd ?
    ManufacturerGuid GUID
    ProductGuid      GUID
    NameGuid         GUID
ends

struct MIDIHDR
    lpData          xptr ?
    dwBufferLength  dd ?
    dwBytesRecorded dd ?
    dwUser          xptr ?
    dwFlags         dd ?
    lpNext          dd ?
    reserved        xptr ?
    dwOffset        dd ?
    dwReserved      xptr 8 dup(?)
ends

struct MIDIEVENT
    dwDeltaTime     dd ?
    dwStreamID      dd ?
    dwEvent         dd ?
    dwParms         dd ?
ends

struct MIDISTRMBUFFVER
    dwVersion       dd ?
    dwMid           dd ?
    dwOEMVersion    dd ?
ends

struct MIDIPROPTIMEDIV
    cbStruct        dd ?
    dwTimeDiv       dd ?
ends

struct MIDIPROPTEMPO
    cbStruct        dd ?
    dwTempo         dd ?
ends

struct AUXCAPSA
    wMid           dw ?
    wPid           dw ?
    vDriverVersion dd ?
    szPname        db MAXPNAMELEN dup(?)
    wTechnology    dw ?
    wReserved1     dw ?
    dwSupport      dd ?
ends

struct AUXCAPSW
    wMid           dw ?
    wPid           dw ?
    vDriverVersion dd ?
    szPname        dw MAXPNAMELEN dup(?)
    wTechnology    dw ?
    wReserved1     dw ?
    dwSupport      dd ?
ends

struct AUXCAPS2A
    wMid             dw ?
    wPid             dw ?
    vDriverVersion   dd ?
    szPname          db MAXPNAMELEN dup(?)
    wTechnology      dw ?
    wReserved1       dw ?
    dwSupport        dd ?
    ManufacturerGuid GUID
    ProductGuid      GUID
    NameGuid         GUID
ends

struct AUXCAPS2W
    wMid             dw ?
    wPid             dw ?
    vDriverVersion   dd ?
    szPname          dw MAXPNAMELEN dup(?)
    wTechnology      dw ?
    wReserved1       dw ?
    dwSupport        dd ?
    ManufacturerGuid GUID
    ProductGuid      GUID
    NameGuid         GUID
ends

struct MIXERCAPSA
    wMid           dw ?
    wPid           dw ?
    vDriverVersion dd ?
    szPname        db MAXPNAMELEN dup(?)
    fdwSupport     dd ?
    cDestinations  dd ?
ends

struct MIXERCAPSW
    wMid           dw ?
    wPid           dw ?
    vDriverVersion dd ?
    szPname        dw MAXPNAMELEN dup(?)
    fdwSupport     dd ?
    cDestinations  dd ?
ends

struct MIXERCAPS2A
    wMid             dw ?
    wPid             dw ?
    vDriverVersion   dd ?
    szPname          db MAXPNAMELEN dup(?)
    fdwSupport       dd ?
    cDestinations    dd ?
    ManufacturerGuid GUID
    ProductGuid      GUID
    NameGuid         GUID
ends

struct MIXERCAPS2W
    wMid             dw ?
    wPid             dw ?
    vDriverVersion   dd ?
    szPname          dw MAXPNAMELEN dup(?)
    fdwSupport       dd ?
    cDestinations    dd ?
    ManufacturerGuid GUID
    ProductGuid      GUID
    NameGuid         GUID
ends

struct TARGETA
    dwType         dd ?
    dwDeviceID     dd ?
    wMid           dw ?
    wPid           dw ?
    vDriverVersion dd ?
    szPname        db MAXPNAMELEN dup(?)
ends

struct TARGETW
    dwType         dd ?
    dwDeviceID     dd ?
    wMid           dw ?
    wPid           dw ?
    vDriverVersion dd ?
    szPname        dw MAXPNAMELEN dup(?)
ends

struct MIXERLINEA
    cbStruct        dd   ?
    dwDestination   dd   ?
    dwSource        dd   ?
    dwLineID        dd   ?
    fdwLine         dd   ?
    dwUser          xptr ?
    dwComponentType dd   ?
    cChannels       dd   ?
    cConnections    dd   ?
    cControls       dd   ?
    szShortName     db   MIXER_SHORT_NAME_CHARS dup(?)
    szName          db   MIXER_LONG_NAME_CHARS dup(?)
    Target          TARGETA
ends

struct MIXERLINEW
    cbStruct        dd   ?
    dwDestination   dd   ?
    dwSource        dd   ?
    dwLineID        dd   ?
    fdwLine         dd   ?
    dwUser          xptr ?
    dwComponentType dd   ?
    cChannels       dd   ?
    cConnections    dd   ?
    cControls       dd   ?
    szShortName     dw   MIXER_SHORT_NAME_CHARS dup(?)
    szName          dw   MIXER_LONG_NAME_CHARS dup(?)
    Target          TARGETW
ends

struct MIXERLINECONTROLSA
    cbStruct          dd ?
    dwLineID          dd ?
    union
        dwControlID   dd ?
        dwControlType dd ?
    ends
    cControls         dd ?
    cbmxctrl          dd ?
    pamxctrl          xptr ?
ends

struct MIXERLINECONTROLSW
    cbStruct          dd ?
    dwLineID          dd ?
    union
        dwControlID   dd ?
        dwControlType dd ?
    ends
    cControls         dd ?
    cbmxctrl          dd ?
    pamxctrl          xptr ?
ends

struct MIXERCONTROLDETAILS
    cbStruct           dd ?
    dwControlID        dd ?
    cChannels          dd ?
    union
        hwndOwner      xptr ?
        cMultipleItems dd ?
    ends
    cbDetails          dd ?
    paDetails          xptr ?
ends

struct MIXERCONTROLDETAILS_LISTTEXTA
    dwParam1           dd ?
    dwParam2           dd ?
    szName             db MIXER_LONG_NAME_CHARS dup(?)
ends

struct MIXERCONTROLDETAILS_LISTTEXTW
    dwParam1           dd ?
    dwParam2           dd ?
    szName             dw MIXER_LONG_NAME_CHARS dup(?)
ends

struct MIXERCONTROLDETAILS_BOOLEAN
    fValue  dd ?
ends

struct MIXERCONTROLDETAILS_SIGNED
    lValue  dd ?
ends

struct MIXERCONTROLDETAILS_UNSIGNED
    dwValue dd ?
ends

struct TIMECAPS
    wPeriodMin dd ?
    wPeriodMax dd ?
ends

struct JOYCAPSA
    wMid        dw ?
    wPid        dw ?
    szPname     db MAXPNAMELEN dup(?)
    wXmin       dd ?
    wXmax       dd ?
    wYmin       dd ?
    wYmax       dd ?
    wZmin       dd ?
    wZmax       dd ?
    wNumButtons dd ?
    wPeriodMin  dd ?
    wPeriodMax  dd ?
    wRmin       dd ?
    wRmax       dd ?
    wUmin       dd ?
    wUmax       dd ?
    wVmin       dd ?
    wVmax       dd ?
    wCaps       dd ?
    wMaxAxes    dd ?
    wNumAxes    dd ?
    wMaxButtons dd ?
    szRegKey    db MAXPNAMELEN dup(?)
    szOEMVxD    db MAX_JOYSTICKOEMVXDNAME dup(?)
ends

struct JOYCAPSW
    wMid        dw ?
    wPid        dw ?
    szPname     dw MAXPNAMELEN dup(?)
    wXmin       dd ?
    wXmax       dd ?
    wYmin       dd ?
    wYmax       dd ?
    wZmin       dd ?
    wZmax       dd ?
    wNumButtons dd ?
    wPeriodMin  dd ?
    wPeriodMax  dd ?
    wRmin       dd ?
    wRmax       dd ?
    wUmin       dd ?
    wUmax       dd ?
    wVmin       dd ?
    wVmax       dd ?
    wCaps       dd ?
    wMaxAxes    dd ?
    wNumAxes    dd ?
    wMaxButtons dd ?
    szRegKey    dw MAXPNAMELEN dup(?)
    szOEMVxD    dw MAX_JOYSTICKOEMVXDNAME dup(?)
ends

struct JOYCAPS2A
    wMid             dw ?
    wPid             dw ?
    szPname          db MAXPNAMELEN dup(?)
    wXmin            dd ?
    wXmax            dd ?
    wYmin            dd ?
    wYmax            dd ?
    wZmin            dd ?
    wZmax            dd ?
    wNumButtons      dd ?
    wPeriodMin       dd ?
    wPeriodMax       dd ?
    wRmin            dd ?
    wRmax            dd ?
    wUmin            dd ?
    wUmax            dd ?
    wVmin            dd ?
    wVmax            dd ?
    wCaps            dd ?
    wMaxAxes         dd ?
    wNumAxes         dd ?
    wMaxButtons      dd ?
    szRegKey         db MAXPNAMELEN dup(?)
    szOEMVxD         db MAX_JOYSTICKOEMVXDNAME dup(?)
    ManufacturerGuid GUID
    ProductGuid      GUID
    NameGuid         GUID
ends

struct JOYCAPS2W
    wMid             dw ?
    wPid             dw ?
    szPname          dw MAXPNAMELEN dup(?)
    wXmin            dd ?
    wXmax            dd ?
    wYmin            dd ?
    wYmax            dd ?
    wZmin            dd ?
    wZmax            dd ?
    wNumButtons      dd ?
    wPeriodMin       dd ?
    wPeriodMax       dd ?
    wRmin            dd ?
    wRmax            dd ?
    wUmin            dd ?
    wUmax            dd ?
    wVmin            dd ?
    wVmax            dd ?
    wCaps            dd ?
    wMaxAxes         dd ?
    wNumAxes         dd ?
    wMaxButtons      dd ?
    szRegKey         dw MAXPNAMELEN dup(?)
    szOEMVxD         dw MAX_JOYSTICKOEMVXDNAME dup(?)
    ManufacturerGuid GUID
    ProductGuid      GUID
    NameGuid         GUID
ends

struct JOYINFO
    wXpos    dd ?
    wYpos    dd ?
    wZpos    dd ?
    wButtons dd ?
ends

struct JOYINFOEX
    dwSize         dd ?
    dwFlags        dd ?
    dwXpos         dd ?
    dwYpos         dd ?
    dwZpos         dd ?
    dwRpos         dd ?
    dwUpos         dd ?
    dwVpos         dd ?
    dwButtons      dd ?
    dwButtonNumber dd ?
    dwPOV          dd ?
    dwReserved1    dd ?
    dwReserved2    dd ?
ends

struct MMIOINFO
    dwFlags     dd ?
    fccIOProc   dd ?
    pIOProc     xptr ?
    wErrorRet   dd ?
    htask       xptr ?
    cchBuffer   dd ?
    pchBuffer   xptr ?
    pchNext     xptr ?
    pchEndRead  xptr ?
    pchEndWrite xptr ?
    lBufOffset  dd ?
    lDiskOffset dd ?
    adwInfo     dd 3 dup(?)
    dwReserved1 dd ?
    dwReserved2 dd ?
    hmmio       xptr ?
ends

struct MMCKINFO
    ckid         dd ?
    cksize       dd ?
    fccType      dd ?
    dwDataOffset dd ?
    dwFlags      dd ?
ends

struct MCI_GENERIC_PARMS
    dwCallback xptr ?
ends

struct MCI_OPEN_PARMSA
    dwCallback       xptr ?
    wDeviceID        dd ?
    lpstrDeviceType  xptr ?
    lpstrElementName xptr ?
    lpstrAlias       xptr ?
ends

struct MCI_OPEN_PARMSW
    dwCallback       xptr ?
    wDeviceID        dd   ?
    lpstrDeviceType  xptr ?
    lpstrElementName xptr ?
    lpstrAlias       xptr ?
ends

struct MCI_PLAY_PARMS
    dwCallback xptr ?
    dwFrom     dd   ?
    dwTo       dd   ?
ends

struct MCI_SEEK_PARMS
    dwCallback xptr ?
    dwTo       dd   ?
ends

struct MCI_STATUS_PARMS
    dwCallback xptr ?
    dwReturn   xptr ?
    dwItem     dd   ?
    dwTrack    dd   ?
ends

struct MCI_INFO_PARMSA
    dwCallback  xptr ?
    lpstrReturn xptr ?
    dwRetSize   dd   ?
ends

struct MCI_INFO_PARMSW
    dwCallback  xptr ?
    lpstrReturn xptr ?
    dwRetSize   dd   ?
ends

struct MCI_GETDEVCAPS_PARMS
    dwCallback xptr ?
    dwReturn   dd   ?
    dwItem     dd   ?
ends

struct MCI_SYSINFO_PARMSA
    dwCallback  xptr ?
    lpstrReturn xptr ?
    dwRetSize   dd   ?
    dwNumber    dd   ?
    wDeviceType dd   ?
ends

struct MCI_SYSINFO_PARMSW
    dwCallback  xptr ?
    lpstrReturn xptr ?
    dwRetSize   dd   ?
    dwNumber    dd   ?
    wDeviceType dd   ?
ends

struct MCI_SET_PARMS
    dwCallback   xptr ?
    dwTimeFormat dd   ?
    dwAudio      dd   ?
ends

struct MCI_BREAK_PARMS
    dwCallback xptr ?
    nVirtKey   dd   ?
    hwndBreak  xptr ?
ends

struct MCI_SAVE_PARMSA
    dwCallback xptr ?
    lpfilename xptr ?
ends

struct MCI_SAVE_PARMSW
    dwCallback xptr ?
    lpfilename xptr ?
ends

struct MCI_LOAD_PARMSA
    dwCallback xptr ?
    lpfilename xptr ?
ends

struct MCI_LOAD_PARMSW
    dwCallback xptr ?
    lpfilename xptr ?
ends

struct MCI_RECORD_PARMS
    dwCallback xptr ?
    dwFrom     dd   ?
    dwTo       dd   ?
ends

struct MCI_VD_PLAY_PARMS
    dwCallback xptr ?
    dwFrom     dd   ?
    dwTo       dd   ?
    dwSpeed    dd   ?
ends

struct MCI_VD_STEP_PARMS
    dwCallback xptr ?
    dwFrames   dd   ?
ends

struct MCI_VD_ESCAPE_PARMSA
    dwCallback   xptr ?
    lpstrCommand xptr ?
ends

struct MCI_VD_ESCAPE_PARMSW
    dwCallback   xptr ?
    lpstrCommand xptr ?
ends

struct MCI_WAVE_OPEN_PARMSA
    dwCallback       xptr ?
    wDeviceID        dd   ?
    lpstrDeviceType  xptr ?
    lpstrElementName xptr ?
    lpstrAlias       xptr ?
    dwBufferSeconds  dd   ?
ends

struct MCI_WAVE_OPEN_PARMSW
    dwCallback       xptr ?
    wDeviceID        dd   ?
    lpstrDeviceType  xptr ?
    lpstrElementName xptr ?
    lpstrAlias       xptr ?
    dwBufferSeconds  dd   ?
ends

struct MCI_WAVE_DELETE_PARMS
    dwCallback xptr ?
    dwFrom     dd   ?
    dwTo       dd   ?
ends

struct MCI_WAVE_SET_PARMS
    dwCallback      xptr ?
    dwTimeFormat    dd   ?
    dwAudio         dd   ?
    wInput          dd   ?
    wOutput         dd   ?
    wFormatTag      dw   ?
    wReserved2      dw   ?
    nChannels       dw   ?
    wReserved3      dw   ?
    nSamplesPerSec  dd   ?
    nAvgBytesPerSec dd   ?
    nBlockAlign     dw   ?
    wReserved4      dw   ?
    wBitsPerSample  dw   ?
    wReserved5      dw   ?
ends

struct MCI_SEQ_SET_PARMS
    dwCallback   xptr ?
    dwTimeFormat dd   ?
    dwAudio      dd   ?
    dwTempo      dd   ?
    dwPort       dd   ?
    dwSlave      dd   ?
    dwMaster     dd   ?
    dwOffset     dd   ?
ends

struct MCI_ANIM_OPEN_PARMSA
    dwCallback       xptr ?
    wDeviceID        dd   ?
    lpstrDeviceType  xptr ?
    lpstrElementName xptr ?
    lpstrAlias       xptr ?
    dwStyle          dd   ?
    hWndParent       xptr ?
ends

struct MCI_ANIM_OPEN_PARMSW
    dwCallback       xptr ?
    wDeviceID        dd   ?
    lpstrDeviceType  xptr ?
    lpstrElementName xptr ?
    lpstrAlias       xptr ?
    dwStyle          dd   ?
    hWndParent       xptr ?
ends

struct MCI_ANIM_PLAY_PARMS
    dwCallback xptr ?
    dwFrom     dd   ?
    dwTo       dd   ?
    dwSpeed    dd   ?
ends

struct MCI_ANIM_STEP_PARMS
    dwCallback xptr ?
    dwFrames   dd   ?
ends

struct MCI_ANIM_WINDOW_PARMSA
    dwCallback xptr ?
    union
        hWnd   xptr ?
        hwnd   xptr ?
    ends
    nCmdShow   dd   ?
    lpstrText  xptr ?
ends

struct MCI_ANIM_WINDOW_PARMSW
    dwCallback xptr ?
    union
        hWnd   xptr ?
        hwnd   xptr ?
    ends
    nCmdShow   dd   ?
    lpstrText  xptr ?
ends

struct MCI_ANIM_RECT_PARMS
    dwCallback   xptr  ?
    if defined MCI_USE_OFFEXT
        ptOffset POINT
        ptExtent POINT
    else
        rc       RECT
    end if
ends

struct MCI_ANIM_UPDATE_PARMS
    dwCallback xptr ?
    rc         RECT
    hDC        xptr ?
ends

struct MCI_OVLY_OPEN_PARMSA
    dwCallback       xptr ?
    wDeviceID        dd   ?
    lpstrDeviceType  xptr ?
    lpstrElementName xptr ?
    lpstrAlias       xptr ?
    dwStyle          dd   ?
    hWndParent       xptr ?
ends

struct MCI_OVLY_OPEN_PARMSW
    dwCallback       xptr ?
    wDeviceID        dd   ?
    lpstrDeviceType  xptr ?
    lpstrElementName xptr ?
    lpstrAlias       xptr ?
    dwStyle          dd   ?
    hWndParent       xptr ?
ends

struct MCI_OVLY_WINDOW_PARMSA
    dwCallback xptr ?
    hWnd       xptr ?
    nCmdShow   dd   ?
    lpstrText  xptr ?
ends

struct MCI_OVLY_WINDOW_PARMSW
    dwCallback xptr ?
    hWnd       xptr ?
    nCmdShow   dd   ?
    lpstrText  xptr ?
ends

struct MCI_OVLY_RECT_PARMS
    dwCallback   xptr  ?
    rc           RECT
ends

struct MCI_OVLY_SAVE_PARMSA
    dwCallback xptr ?
    lpfilename xptr ?
    rc         RECT
ends

struct MCI_OVLY_SAVE_PARMSW
    dwCallback xptr ?
    lpfilename xptr ?
    rc         RECT
ends

struct MCI_OVLY_LOAD_PARMSA
    dwCallback xptr ?
    lpfilename xptr ?
    rc         RECT
ends

struct MCI_OVLY_LOAD_PARMSW
    dwCallback xptr ?
    lpfilename xptr ?
    rc         RECT
ends


;======================================== Functions =======================================;

if defined APP_WIN64
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp_aux32Message' as aux32Message:qword
    end if
    extrn '__imp_auxGetDevCapsA' as auxGetDevCapsA:qword
    extrn '__imp_auxGetDevCapsW' as auxGetDevCapsW:qword
    extrn '__imp_auxGetNumDevs' as auxGetNumDevs:qword
    extrn '__imp_auxGetVolume' as auxGetVolume:qword
    extrn '__imp_auxOutMessage' as auxOutMessage:qword
    extrn '__imp_auxSetVolume' as auxSetVolume:qword
    extrn '__imp_CloseDriver' as CloseDriver:qword
    extrn '__imp_DefDriverProc' as DefDriverProc:qword
    extrn '__imp_DriverCallback' as DriverCallback:qword
    extrn '__imp_DrvGetModuleHandle' as DrvGetModuleHandle:qword
    extrn '__imp_GetDriverModuleHandle' as GetDriverModuleHandle:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp_joy32Message' as joy32Message:qword
    end if
    extrn '__imp_joyConfigChanged' as joyConfigChanged:qword
    extrn '__imp_joyGetDevCapsA' as joyGetDevCapsA:qword
    extrn '__imp_joyGetDevCapsW' as joyGetDevCapsW:qword
    extrn '__imp_joyGetNumDevs' as joyGetNumDevs:qword
    extrn '__imp_joyGetPos' as joyGetPos:qword
    extrn '__imp_joyGetPosEx' as joyGetPosEx:qword
    extrn '__imp_joyGetThreshold' as joyGetThreshold:qword
    extrn '__imp_joyReleaseCapture' as joyReleaseCapture:qword
    extrn '__imp_joySetCapture' as joySetCapture:qword
    extrn '__imp_joySetThreshold' as joySetThreshold:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp_mci32Message' as mci32Message:qword
    end if
    extrn '__imp_mciDriverNotify' as mciDriverNotify:qword
    extrn '__imp_mciDriverYield' as mciDriverYield:qword
    extrn '__imp_mciExecute' as mciExecute:qword
    extrn '__imp_mciFreeCommandResource' as mciFreeCommandResource:qword
    extrn '__imp_mciGetCreatorTask' as mciGetCreatorTask:qword
    extrn '__imp_mciGetDeviceIDA' as mciGetDeviceIDA:qword
    extrn '__imp_mciGetDeviceIDFromElementIDA' as mciGetDeviceIDFromElementIDA:qword
    extrn '__imp_mciGetDeviceIDFromElementIDW' as mciGetDeviceIDFromElementIDW:qword
    extrn '__imp_mciGetDeviceIDW' as mciGetDeviceIDW:qword
    extrn '__imp_mciGetDriverData' as mciGetDriverData:qword
    extrn '__imp_mciGetErrorStringA' as mciGetErrorStringA:qword
    extrn '__imp_mciGetErrorStringW' as mciGetErrorStringW:qword
    extrn '__imp_mciGetYieldProc' as mciGetYieldProc:qword
    extrn '__imp_mciLoadCommandResource' as mciLoadCommandResource:qword
    extrn '__imp_mciSendCommandA' as mciSendCommandA:qword
    extrn '__imp_mciSendCommandW' as mciSendCommandW:qword
    extrn '__imp_mciSendStringA' as mciSendStringA:qword
    extrn '__imp_mciSendStringW' as mciSendStringW:qword
    extrn '__imp_mciSetDriverData' as mciSetDriverData:qword
    extrn '__imp_mciSetYieldProc' as mciSetYieldProc:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp_mid32Message' as mid32Message:qword
    end if
    extrn '__imp_midiConnect' as midiConnect:qword
    extrn '__imp_midiDisconnect' as midiDisconnect:qword
    extrn '__imp_midiInAddBuffer' as midiInAddBuffer:qword
    extrn '__imp_midiInClose' as midiInClose:qword
    extrn '__imp_midiInGetDevCapsA' as midiInGetDevCapsA:qword
    extrn '__imp_midiInGetDevCapsW' as midiInGetDevCapsW:qword
    extrn '__imp_midiInGetErrorTextA' as midiInGetErrorTextA:qword
    extrn '__imp_midiInGetErrorTextW' as midiInGetErrorTextW:qword
    extrn '__imp_midiInGetID' as midiInGetID:qword
    extrn '__imp_midiInGetNumDevs' as midiInGetNumDevs:qword
    extrn '__imp_midiInMessage' as midiInMessage:qword
    extrn '__imp_midiInOpen' as midiInOpen:qword
    extrn '__imp_midiInPrepareHeader' as midiInPrepareHeader:qword
    extrn '__imp_midiInReset' as midiInReset:qword
    extrn '__imp_midiInStart' as midiInStart:qword
    extrn '__imp_midiInStop' as midiInStop:qword
    extrn '__imp_midiInUnprepareHeader' as midiInUnprepareHeader:qword
    extrn '__imp_midiOutCacheDrumPatches' as midiOutCacheDrumPatches:qword
    extrn '__imp_midiOutCachePatches' as midiOutCachePatches:qword
    extrn '__imp_midiOutClose' as midiOutClose:qword
    extrn '__imp_midiOutGetDevCapsA' as midiOutGetDevCapsA:qword
    extrn '__imp_midiOutGetDevCapsW' as midiOutGetDevCapsW:qword
    extrn '__imp_midiOutGetErrorTextA' as midiOutGetErrorTextA:qword
    extrn '__imp_midiOutGetErrorTextW' as midiOutGetErrorTextW:qword
    extrn '__imp_midiOutGetID' as midiOutGetID:qword
    extrn '__imp_midiOutGetNumDevs' as midiOutGetNumDevs:qword
    extrn '__imp_midiOutGetVolume' as midiOutGetVolume:qword
    extrn '__imp_midiOutLongMsg' as midiOutLongMsg:qword
    extrn '__imp_midiOutMessage' as midiOutMessage:qword
    extrn '__imp_midiOutOpen' as midiOutOpen:qword
    extrn '__imp_midiOutPrepareHeader' as midiOutPrepareHeader:qword
    extrn '__imp_midiOutReset' as midiOutReset:qword
    extrn '__imp_midiOutSetVolume' as midiOutSetVolume:qword
    extrn '__imp_midiOutShortMsg' as midiOutShortMsg:qword
    extrn '__imp_midiOutUnprepareHeader' as midiOutUnprepareHeader:qword
    extrn '__imp_midiStreamClose' as midiStreamClose:qword
    extrn '__imp_midiStreamOpen' as midiStreamOpen:qword
    extrn '__imp_midiStreamOut' as midiStreamOut:qword
    extrn '__imp_midiStreamPause' as midiStreamPause:qword
    extrn '__imp_midiStreamPosition' as midiStreamPosition:qword
    extrn '__imp_midiStreamProperty' as midiStreamProperty:qword
    extrn '__imp_midiStreamRestart' as midiStreamRestart:qword
    extrn '__imp_midiStreamStop' as midiStreamStop:qword
    extrn '__imp_mixerClose' as mixerClose:qword
    extrn '__imp_mixerGetControlDetailsA' as mixerGetControlDetailsA:qword
    extrn '__imp_mixerGetControlDetailsW' as mixerGetControlDetailsW:qword
    extrn '__imp_mixerGetDevCapsA' as mixerGetDevCapsA:qword
    extrn '__imp_mixerGetDevCapsW' as mixerGetDevCapsW:qword
    extrn '__imp_mixerGetID' as mixerGetID:qword
    extrn '__imp_mixerGetLineControlsA' as mixerGetLineControlsA:qword
    extrn '__imp_mixerGetLineControlsW' as mixerGetLineControlsW:qword
    extrn '__imp_mixerGetLineInfoA' as mixerGetLineInfoA:qword
    extrn '__imp_mixerGetLineInfoW' as mixerGetLineInfoW:qword
    extrn '__imp_mixerGetNumDevs' as mixerGetNumDevs:qword
    extrn '__imp_mixerMessage' as mixerMessage:qword
    extrn '__imp_mixerOpen' as mixerOpen:qword
    extrn '__imp_mixerSetControlDetails' as mixerSetControlDetails:qword
    extrn '__imp_mmDrvInstall' as mmDrvInstall:qword
    extrn '__imp_mmGetCurrentTask' as mmGetCurrentTask:qword
    extrn '__imp_mmioAdvance' as mmioAdvance:qword
    extrn '__imp_mmioAscend' as mmioAscend:qword
    extrn '__imp_mmioClose' as mmioClose:qword
    extrn '__imp_mmioCreateChunk' as mmioCreateChunk:qword
    extrn '__imp_mmioDescend' as mmioDescend:qword
    extrn '__imp_mmioFlush' as mmioFlush:qword
    extrn '__imp_mmioGetInfo' as mmioGetInfo:qword
    extrn '__imp_mmioInstallIOProcA' as mmioInstallIOProcA:qword
    extrn '__imp_mmioInstallIOProcW' as mmioInstallIOProcW:qword
    extrn '__imp_mmioOpenA' as mmioOpenA:qword
    extrn '__imp_mmioOpenW' as mmioOpenW:qword
    extrn '__imp_mmioRead' as mmioRead:qword
    extrn '__imp_mmioRenameA' as mmioRenameA:qword
    extrn '__imp_mmioRenameW' as mmioRenameW:qword
    extrn '__imp_mmioSeek' as mmioSeek:qword
    extrn '__imp_mmioSendMessage' as mmioSendMessage:qword
    extrn '__imp_mmioSetBuffer' as mmioSetBuffer:qword
    extrn '__imp_mmioSetInfo' as mmioSetInfo:qword
    extrn '__imp_mmioStringToFOURCCA' as mmioStringToFOURCCA:qword
    extrn '__imp_mmioStringToFOURCCW' as mmioStringToFOURCCW:qword
    extrn '__imp_mmioWrite' as mmioWrite:qword
    extrn '__imp_mmsystemGetVersion' as mmsystemGetVersion:qword
    extrn '__imp_mmTaskBlock' as mmTaskBlock:qword
    extrn '__imp_mmTaskCreate' as mmTaskCreate:qword
    extrn '__imp_mmTaskSignal' as mmTaskSignal:qword
    extrn '__imp_mmTaskYield' as mmTaskYield:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp_mod32Message' as mod32Message:qword
        extrn '__imp_mxd32Message' as mxd32Message:qword
        extrn '__imp_NotifyCallbackData' as NotifyCallbackData:qword
    end if
    extrn '__imp_OpenDriver' as OpenDriver:qword
    extrn '__imp_PlaySoundA' as PlaySoundA:qword
    extrn '__imp_PlaySoundW' as PlaySoundW:qword
    extrn '__imp_SendDriverMessage' as SendDriverMessage:qword
    extrn '__imp_sndPlaySoundA' as sndPlaySoundA:qword
    extrn '__imp_sndPlaySoundW' as sndPlaySoundW:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp_tid32Message' as tid32Message:qword
    end if
    extrn '__imp_timeBeginPeriod' as timeBeginPeriod:qword
    extrn '__imp_timeEndPeriod' as timeEndPeriod:qword
    extrn '__imp_timeGetDevCaps' as timeGetDevCaps:qword
    extrn '__imp_timeGetSystemTime' as timeGetSystemTime:qword
    extrn '__imp_timeGetTime' as timeGetTime:qword
    extrn '__imp_timeKillEvent' as timeKillEvent:qword
    extrn '__imp_timeSetEvent' as timeSetEvent:qword
    extrn '__imp_waveInAddBuffer' as waveInAddBuffer:qword
    extrn '__imp_waveInClose' as waveInClose:qword
    extrn '__imp_waveInGetDevCapsA' as waveInGetDevCapsA:qword
    extrn '__imp_waveInGetDevCapsW' as waveInGetDevCapsW:qword
    extrn '__imp_waveInGetErrorTextA' as waveInGetErrorTextA:qword
    extrn '__imp_waveInGetErrorTextW' as waveInGetErrorTextW:qword
    extrn '__imp_waveInGetID' as waveInGetID:qword
    extrn '__imp_waveInGetNumDevs' as waveInGetNumDevs:qword
    extrn '__imp_waveInGetPosition' as waveInGetPosition:qword
    extrn '__imp_waveInMessage' as waveInMessage:qword
    extrn '__imp_waveInOpen' as waveInOpen:qword
    extrn '__imp_waveInPrepareHeader' as waveInPrepareHeader:qword
    extrn '__imp_waveInReset' as waveInReset:qword
    extrn '__imp_waveInStart' as waveInStart:qword
    extrn '__imp_waveInStop' as waveInStop:qword
    extrn '__imp_waveInUnprepareHeader' as waveInUnprepareHeader:qword
    extrn '__imp_waveOutBreakLoop' as waveOutBreakLoop:qword
    extrn '__imp_waveOutClose' as waveOutClose:qword
    extrn '__imp_waveOutGetDevCapsA' as waveOutGetDevCapsA:qword
    extrn '__imp_waveOutGetDevCapsW' as waveOutGetDevCapsW:qword
    extrn '__imp_waveOutGetErrorTextA' as waveOutGetErrorTextA:qword
    extrn '__imp_waveOutGetErrorTextW' as waveOutGetErrorTextW:qword
    extrn '__imp_waveOutGetID' as waveOutGetID:qword
    extrn '__imp_waveOutGetNumDevs' as waveOutGetNumDevs:qword
    extrn '__imp_waveOutGetPitch' as waveOutGetPitch:qword
    extrn '__imp_waveOutGetPlaybackRate' as waveOutGetPlaybackRate:qword
    extrn '__imp_waveOutGetPosition' as waveOutGetPosition:qword
    extrn '__imp_waveOutGetVolume' as waveOutGetVolume:qword
    extrn '__imp_waveOutMessage' as waveOutMessage:qword
    extrn '__imp_waveOutOpen' as waveOutOpen:qword
    extrn '__imp_waveOutPause' as waveOutPause:qword
    extrn '__imp_waveOutPrepareHeader' as waveOutPrepareHeader:qword
    extrn '__imp_waveOutReset' as waveOutReset:qword
    extrn '__imp_waveOutRestart' as waveOutRestart:qword
    extrn '__imp_waveOutSetPitch' as waveOutSetPitch:qword
    extrn '__imp_waveOutSetPlaybackRate' as waveOutSetPlaybackRate:qword
    extrn '__imp_waveOutSetVolume' as waveOutSetVolume:qword
    extrn '__imp_waveOutUnprepareHeader' as waveOutUnprepareHeader:qword
    extrn '__imp_waveOutWrite' as waveOutWrite:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp_wid32Message' as wid32Message:qword
        extrn '__imp_wod32Message' as wod32Message:qword
        extrn '__imp_WOW32DriverCallback' as WOW32DriverCallback:qword
        extrn '__imp_WOW32ResolveMultiMediaHandle' as WOW32ResolveMultiMediaHandle:qword
    end if
    extrn '__imp_WOWAppExit' as WOWAppExit:qword
else
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp__aux32Message@20' as aux32Message:dword
    end if
    extrn '__imp__auxGetDevCapsA@12' as auxGetDevCapsA:dword
    extrn '__imp__auxGetDevCapsW@12' as auxGetDevCapsW:dword
    extrn '__imp__auxGetNumDevs@0' as auxGetNumDevs:dword
    extrn '__imp__auxGetVolume@8' as auxGetVolume:dword
    extrn '__imp__auxOutMessage@16' as auxOutMessage:dword
    extrn '__imp__auxSetVolume@8' as auxSetVolume:dword
    extrn '__imp__CloseDriver@12' as CloseDriver:dword
    extrn '__imp__DefDriverProc@20' as DefDriverProc:dword
    extrn '__imp__DriverCallback@28' as DriverCallback:dword
    extrn '__imp__DrvGetModuleHandle@4' as DrvGetModuleHandle:dword
    extrn '__imp__GetDriverModuleHandle@4' as GetDriverModuleHandle:dword
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp__joy32Message@20' as joy32Message:dword
    end if
    extrn '__imp__joyConfigChanged@4' as joyConfigChanged:dword
    extrn '__imp__joyGetDevCapsA@12' as joyGetDevCapsA:dword
    extrn '__imp__joyGetDevCapsW@12' as joyGetDevCapsW:dword
    extrn '__imp__joyGetNumDevs@0' as joyGetNumDevs:dword
    extrn '__imp__joyGetPos@8' as joyGetPos:dword
    extrn '__imp__joyGetPosEx@8' as joyGetPosEx:dword
    extrn '__imp__joyGetThreshold@8' as joyGetThreshold:dword
    extrn '__imp__joyReleaseCapture@4' as joyReleaseCapture:dword
    extrn '__imp__joySetCapture@16' as joySetCapture:dword
    extrn '__imp__joySetThreshold@8' as joySetThreshold:dword
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp__mci32Message@20' as mci32Message:dword
    end if
    extrn '__imp__mciDriverNotify@12' as mciDriverNotify:dword
    extrn '__imp__mciDriverYield@4' as mciDriverYield:dword
    extrn '__imp__mciExecute@4' as mciExecute:dword
    extrn '__imp__mciFreeCommandResource@4' as mciFreeCommandResource:dword
    extrn '__imp__mciGetCreatorTask@4' as mciGetCreatorTask:dword
    extrn '__imp__mciGetDeviceIDA@4' as mciGetDeviceIDA:dword
    extrn '__imp__mciGetDeviceIDFromElementIDA@8' as mciGetDeviceIDFromElementIDA:dword
    extrn '__imp__mciGetDeviceIDFromElementIDW@8' as mciGetDeviceIDFromElementIDW:dword
    extrn '__imp__mciGetDeviceIDW@4' as mciGetDeviceIDW:dword
    extrn '__imp__mciGetDriverData@4' as mciGetDriverData:dword
    extrn '__imp__mciGetErrorStringA@12' as mciGetErrorStringA:dword
    extrn '__imp__mciGetErrorStringW@12' as mciGetErrorStringW:dword
    extrn '__imp__mciGetYieldProc@8' as mciGetYieldProc:dword
    extrn '__imp__mciLoadCommandResource@12' as mciLoadCommandResource:dword
    extrn '__imp__mciSendCommandA@16' as mciSendCommandA:dword
    extrn '__imp__mciSendCommandW@16' as mciSendCommandW:dword
    extrn '__imp__mciSendStringA@16' as mciSendStringA:dword
    extrn '__imp__mciSendStringW@16' as mciSendStringW:dword
    extrn '__imp__mciSetDriverData@8' as mciSetDriverData:dword
    extrn '__imp__mciSetYieldProc@12' as mciSetYieldProc:dword
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp__mid32Message@20' as mid32Message:dword
    end if
    extrn '__imp__midiConnect@12' as midiConnect:dword
    extrn '__imp__midiDisconnect@12' as midiDisconnect:dword
    extrn '__imp__midiInAddBuffer@12' as midiInAddBuffer:dword
    extrn '__imp__midiInClose@4' as midiInClose:dword
    extrn '__imp__midiInGetDevCapsA@12' as midiInGetDevCapsA:dword
    extrn '__imp__midiInGetDevCapsW@12' as midiInGetDevCapsW:dword
    extrn '__imp__midiInGetErrorTextA@12' as midiInGetErrorTextA:dword
    extrn '__imp__midiInGetErrorTextW@12' as midiInGetErrorTextW:dword
    extrn '__imp__midiInGetID@8' as midiInGetID:dword
    extrn '__imp__midiInGetNumDevs@0' as midiInGetNumDevs:dword
    extrn '__imp__midiInMessage@16' as midiInMessage:dword
    extrn '__imp__midiInOpen@20' as midiInOpen:dword
    extrn '__imp__midiInPrepareHeader@12' as midiInPrepareHeader:dword
    extrn '__imp__midiInReset@4' as midiInReset:dword
    extrn '__imp__midiInStart@4' as midiInStart:dword
    extrn '__imp__midiInStop@4' as midiInStop:dword
    extrn '__imp__midiInUnprepareHeader@12' as midiInUnprepareHeader:dword
    extrn '__imp__midiOutCacheDrumPatches@16' as midiOutCacheDrumPatches:dword
    extrn '__imp__midiOutCachePatches@16' as midiOutCachePatches:dword
    extrn '__imp__midiOutClose@4' as midiOutClose:dword
    extrn '__imp__midiOutGetDevCapsA@12' as midiOutGetDevCapsA:dword
    extrn '__imp__midiOutGetDevCapsW@12' as midiOutGetDevCapsW:dword
    extrn '__imp__midiOutGetErrorTextA@12' as midiOutGetErrorTextA:dword
    extrn '__imp__midiOutGetErrorTextW@12' as midiOutGetErrorTextW:dword
    extrn '__imp__midiOutGetID@8' as midiOutGetID:dword
    extrn '__imp__midiOutGetNumDevs@0' as midiOutGetNumDevs:dword
    extrn '__imp__midiOutGetVolume@8' as midiOutGetVolume:dword
    extrn '__imp__midiOutLongMsg@12' as midiOutLongMsg:dword
    extrn '__imp__midiOutMessage@16' as midiOutMessage:dword
    extrn '__imp__midiOutOpen@20' as midiOutOpen:dword
    extrn '__imp__midiOutPrepareHeader@12' as midiOutPrepareHeader:dword
    extrn '__imp__midiOutReset@4' as midiOutReset:dword
    extrn '__imp__midiOutSetVolume@8' as midiOutSetVolume:dword
    extrn '__imp__midiOutShortMsg@8' as midiOutShortMsg:dword
    extrn '__imp__midiOutUnprepareHeader@12' as midiOutUnprepareHeader:dword
    extrn '__imp__midiStreamClose@4' as midiStreamClose:dword
    extrn '__imp__midiStreamOpen@24' as midiStreamOpen:dword
    extrn '__imp__midiStreamOut@12' as midiStreamOut:dword
    extrn '__imp__midiStreamPause@4' as midiStreamPause:dword
    extrn '__imp__midiStreamPosition@12' as midiStreamPosition:dword
    extrn '__imp__midiStreamProperty@12' as midiStreamProperty:dword
    extrn '__imp__midiStreamRestart@4' as midiStreamRestart:dword
    extrn '__imp__midiStreamStop@4' as midiStreamStop:dword
    extrn '__imp__mixerClose@4' as mixerClose:dword
    extrn '__imp__mixerGetControlDetailsA@12' as mixerGetControlDetailsA:dword
    extrn '__imp__mixerGetControlDetailsW@12' as mixerGetControlDetailsW:dword
    extrn '__imp__mixerGetDevCapsA@12' as mixerGetDevCapsA:dword
    extrn '__imp__mixerGetDevCapsW@12' as mixerGetDevCapsW:dword
    extrn '__imp__mixerGetID@12' as mixerGetID:dword
    extrn '__imp__mixerGetLineControlsA@12' as mixerGetLineControlsA:dword
    extrn '__imp__mixerGetLineControlsW@12' as mixerGetLineControlsW:dword
    extrn '__imp__mixerGetLineInfoA@12' as mixerGetLineInfoA:dword
    extrn '__imp__mixerGetLineInfoW@12' as mixerGetLineInfoW:dword
    extrn '__imp__mixerGetNumDevs@0' as mixerGetNumDevs:dword
    extrn '__imp__mixerMessage@16' as mixerMessage:dword
    extrn '__imp__mixerOpen@20' as mixerOpen:dword
    extrn '__imp__mixerSetControlDetails@12' as mixerSetControlDetails:dword
    extrn '__imp__mmDrvInstall@16' as mmDrvInstall:dword
    extrn '__imp__mmGetCurrentTask@0' as mmGetCurrentTask:dword
    extrn '__imp__mmioAdvance@12' as mmioAdvance:dword
    extrn '__imp__mmioAscend@12' as mmioAscend:dword
    extrn '__imp__mmioClose@8' as mmioClose:dword
    extrn '__imp__mmioCreateChunk@12' as mmioCreateChunk:dword
    extrn '__imp__mmioDescend@16' as mmioDescend:dword
    extrn '__imp__mmioFlush@8' as mmioFlush:dword
    extrn '__imp__mmioGetInfo@12' as mmioGetInfo:dword
    extrn '__imp__mmioInstallIOProcA@12' as mmioInstallIOProcA:dword
    extrn '__imp__mmioInstallIOProcW@12' as mmioInstallIOProcW:dword
    extrn '__imp__mmioOpenA@12' as mmioOpenA:dword
    extrn '__imp__mmioOpenW@12' as mmioOpenW:dword
    extrn '__imp__mmioRead@12' as mmioRead:dword
    extrn '__imp__mmioRenameA@16' as mmioRenameA:dword
    extrn '__imp__mmioRenameW@16' as mmioRenameW:dword
    extrn '__imp__mmioSeek@12' as mmioSeek:dword
    extrn '__imp__mmioSendMessage@16' as mmioSendMessage:dword
    extrn '__imp__mmioSetBuffer@16' as mmioSetBuffer:dword
    extrn '__imp__mmioSetInfo@12' as mmioSetInfo:dword
    extrn '__imp__mmioStringToFOURCCA@8' as mmioStringToFOURCCA:dword
    extrn '__imp__mmioStringToFOURCCW@8' as mmioStringToFOURCCW:dword
    extrn '__imp__mmioWrite@12' as mmioWrite:dword
    extrn '__imp__mmsystemGetVersion@0' as mmsystemGetVersion:dword
    extrn '__imp__mmTaskBlock@4' as mmTaskBlock:dword
    extrn '__imp__mmTaskCreate@12' as mmTaskCreate:dword
    extrn '__imp__mmTaskSignal@4' as mmTaskSignal:dword
    extrn '__imp__mmTaskYield@0' as mmTaskYield:dword
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp__mod32Message@20' as mod32Message:dword
        extrn '__imp__mxd32Message@20' as mxd32Message:dword
        extrn '__imp__NotifyCallbackData@20' as NotifyCallbackData:dword
    end if
    extrn '__imp__OpenDriver@12' as OpenDriver:dword
    extrn '__imp__PlaySoundA@12' as PlaySoundA:dword
    extrn '__imp__PlaySoundW@12' as PlaySoundW:dword
    extrn '__imp__SendDriverMessage@16' as SendDriverMessage:dword
    extrn '__imp__sndPlaySoundA@8' as sndPlaySoundA:dword
    extrn '__imp__sndPlaySoundW@8' as sndPlaySoundW:dword
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp__tid32Message@20' as tid32Message:dword
    end if
    extrn '__imp__timeBeginPeriod@4' as timeBeginPeriod:dword
    extrn '__imp__timeEndPeriod@4' as timeEndPeriod:dword
    extrn '__imp__timeGetDevCaps@8' as timeGetDevCaps:dword
    extrn '__imp__timeGetSystemTime@8' as timeGetSystemTime:dword
    extrn '__imp__timeGetTime@0' as timeGetTime:dword
    extrn '__imp__timeKillEvent@4' as timeKillEvent:dword
    extrn '__imp__timeSetEvent@20' as timeSetEvent:dword
    extrn '__imp__waveInAddBuffer@12' as waveInAddBuffer:dword
    extrn '__imp__waveInClose@4' as waveInClose:dword
    extrn '__imp__waveInGetDevCapsA@12' as waveInGetDevCapsA:dword
    extrn '__imp__waveInGetDevCapsW@12' as waveInGetDevCapsW:dword
    extrn '__imp__waveInGetErrorTextA@12' as waveInGetErrorTextA:dword
    extrn '__imp__waveInGetErrorTextW@12' as waveInGetErrorTextW:dword
    extrn '__imp__waveInGetID@8' as waveInGetID:dword
    extrn '__imp__waveInGetNumDevs@0' as waveInGetNumDevs:dword
    extrn '__imp__waveInGetPosition@12' as waveInGetPosition:dword
    extrn '__imp__waveInMessage@16' as waveInMessage:dword
    extrn '__imp__waveInOpen@24' as waveInOpen:dword
    extrn '__imp__waveInPrepareHeader@12' as waveInPrepareHeader:dword
    extrn '__imp__waveInReset@4' as waveInReset:dword
    extrn '__imp__waveInStart@4' as waveInStart:dword
    extrn '__imp__waveInStop@4' as waveInStop:dword
    extrn '__imp__waveInUnprepareHeader@12' as waveInUnprepareHeader:dword
    extrn '__imp__waveOutBreakLoop@4' as waveOutBreakLoop:dword
    extrn '__imp__waveOutClose@4' as waveOutClose:dword
    extrn '__imp__waveOutGetDevCapsA@12' as waveOutGetDevCapsA:dword
    extrn '__imp__waveOutGetDevCapsW@12' as waveOutGetDevCapsW:dword
    extrn '__imp__waveOutGetErrorTextA@12' as waveOutGetErrorTextA:dword
    extrn '__imp__waveOutGetErrorTextW@12' as waveOutGetErrorTextW:dword
    extrn '__imp__waveOutGetID@8' as waveOutGetID:dword
    extrn '__imp__waveOutGetNumDevs@0' as waveOutGetNumDevs:dword
    extrn '__imp__waveOutGetPitch@8' as waveOutGetPitch:dword
    extrn '__imp__waveOutGetPlaybackRate@8' as waveOutGetPlaybackRate:dword
    extrn '__imp__waveOutGetPosition@12' as waveOutGetPosition:dword
    extrn '__imp__waveOutGetVolume@8' as waveOutGetVolume:dword
    extrn '__imp__waveOutMessage@16' as waveOutMessage:dword
    extrn '__imp__waveOutOpen@24' as waveOutOpen:dword
    extrn '__imp__waveOutPause@4' as waveOutPause:dword
    extrn '__imp__waveOutPrepareHeader@12' as waveOutPrepareHeader:dword
    extrn '__imp__waveOutReset@4' as waveOutReset:dword
    extrn '__imp__waveOutRestart@4' as waveOutRestart:dword
    extrn '__imp__waveOutSetPitch@8' as waveOutSetPitch:dword
    extrn '__imp__waveOutSetPlaybackRate@8' as waveOutSetPlaybackRate:dword
    extrn '__imp__waveOutSetVolume@8' as waveOutSetVolume:dword
    extrn '__imp__waveOutUnprepareHeader@12' as waveOutUnprepareHeader:dword
    extrn '__imp__waveOutWrite@12' as waveOutWrite:dword
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp__wid32Message@20' as wid32Message:dword
        extrn '__imp__wod32Message@20' as wod32Message:dword
        extrn '__imp__WOW32DriverCallback@28' as WOW32DriverCallback:dword
        extrn '__imp__WOW32ResolveMultiMediaHandle@24' as WOW32ResolveMultiMediaHandle:dword
    end if
    extrn '__imp__WOWAppExit@4' as WOWAppExit:dword
end if

if defined APP_UNICODE
    MIXERCONTROL fix MIXERCONTROLW
    WAVEOUTCAPS fix WAVEOUTCAPSW
    WAVEOUTCAPS2 fix WAVEOUTCAPS2W
    WAVEINCAPS fix WAVEINCAPSW
    WAVEINCAPS2 fix WAVEINCAPS2W
    MIDIOUTCAPS fix MIDIOUTCAPSW
    MIDIOUTCAPS2 fix MIDIOUTCAPS2W
    MIDIINCAPS fix MIDIINCAPSW
    MIDIINCAPS2 fix MIDIINCAPS2W
    AUXCAPS fix AUXCAPSW
    AUXCAPS2 fix AUXCAPS2W
    MIXERCAPS fix MIXERCAPSW
    MIXERCAPS2 fix MIXERCAPS2W
    TARGET fix TARGETW
    MIXERLINE fix MIXERLINEW
    MIXERLINECONTROLS fix MIXERLINECONTROLSW
    MIXERCONTROLDETAILS_LISTTEXT fix MIXERCONTROLDETAILS_LISTTEXTW
    JOYCAPS fix JOYCAPSW
    JOYCAPS2 fix JOYCAPS2W
    MCI_OPEN_PARMS fix MCI_OPEN_PARMSW
    MCI_INFO_PARMS fix MCI_INFO_PARMSW
    MCI_SYSINFO_PARMS fix MCI_SYSINFO_PARMSW
    MCI_SAVE_PARMS fix MCI_SAVE_PARMSW
    MCI_LOAD_PARMS fix MCI_LOAD_PARMSW
    MCI_VD_ESCAPE_PARMS fix MCI_VD_ESCAPE_PARMSW
    MCI_WAVE_OPEN_PARMS fix MCI_WAVE_OPEN_PARMSW
    MCI_ANIM_OPEN_PARMS fix MCI_ANIM_OPEN_PARMSW
    MCI_ANIM_WINDOW_PARMS fix MCI_ANIM_WINDOW_PARMSW
    MCI_OVLY_OPEN_PARMS fix MCI_OVLY_OPEN_PARMSW
    MCI_OVLY_WINDOW_PARMS fix MCI_OVLY_WINDOW_PARMSW
    MCI_OVLY_SAVE_PARMS fix MCI_OVLY_SAVE_PARMSW
    MCI_OVLY_LOAD_PARMS fix MCI_OVLY_LOAD_PARMSW
else
    MIXERCONTROL fix MIXERCONTROLA
    WAVEOUTCAPS fix WAVEOUTCAPSA
    WAVEOUTCAPS2 fix WAVEOUTCAPS2A
    WAVEINCAPS fix WAVEINCAPSA
    WAVEINCAPS2 fix WAVEINCAPS2A
    MIDIOUTCAPS fix MIDIOUTCAPSA
    MIDIOUTCAPS2 fix MIDIOUTCAPS2A
    MIDIINCAPS fix MIDIINCAPSA
    MIDIINCAPS2 fix MIDIINCAPS2A
    AUXCAPS fix AUXCAPSA
    AUXCAPS2 fix AUXCAPS2A
    MIXERCAPS fix MIXERCAPSA
    MIXERCAPS2 fix MIXERCAPS2A
    TARGET fix TARGETA
    MIXERLINE fix MIXERLINEA
    MIXERLINECONTROLS fix MIXERLINECONTROLSA
    MIXERCONTROLDETAILS_LISTTEXT fix MIXERCONTROLDETAILS_LISTTEXTA
    JOYCAPS fix JOYCAPSA
    JOYCAPS2 fix JOYCAPS2A
    MCI_OPEN_PARMS fix MCI_OPEN_PARMSA
    MCI_INFO_PARMS fix MCI_INFO_PARMSA
    MCI_SYSINFO_PARMS fix MCI_SYSINFO_PARMSA
    MCI_SAVE_PARMS fix MCI_SAVE_PARMSA
    MCI_LOAD_PARMS fix MCI_LOAD_PARMSA
    MCI_VD_ESCAPE_PARMS fix MCI_VD_ESCAPE_PARMSA
    MCI_WAVE_OPEN_PARMS fix MCI_WAVE_OPEN_PARMSA
    MCI_ANIM_OPEN_PARMS fix MCI_ANIM_OPEN_PARMSA
    MCI_ANIM_WINDOW_PARMS fix MCI_ANIM_WINDOW_PARMSA
    MCI_OVLY_OPEN_PARMS fix MCI_OVLY_OPEN_PARMSA
    MCI_OVLY_WINDOW_PARMS fix MCI_OVLY_WINDOW_PARMSA
    MCI_OVLY_SAVE_PARMS fix MCI_OVLY_SAVE_PARMSA
    MCI_OVLY_LOAD_PARMS fix MCI_OVLY_LOAD_PARMSA
end if

api auxGetDevCaps,\
    joyGetDevCaps,\
    mciGetDeviceID,\
    mciGetDeviceIDFromElementID,\
    mciGetErrorString,\
    mciSendCommand,\
    mciSendString,\
    midiInGetDevCaps,\
    midiInGetErrorText,\
    midiOutGetDevCaps,\
    midiOutGetErrorText,\
    mixerGetControlDetails,\
    mixerGetDevCaps,\
    mixerGetLineControls,\
    mixerGetLineInfo,\
    mmioInstallIOProc,\
    mmioOpen,\
    mmioRename,\
    mmioStringToFOURCC,\
    PlaySound,\
    sndPlaySound,\
    waveInGetDevCaps,\
    waveInGetErrorText,\
    waveOutGetDevCaps,\
    waveOutGetErrorText


;======================= Undocumented functions (unknown arguments) =======================;

;if (NTDDI_VERSION < NTDDI_VISTA)
;    if defined APP_WIN64
;        extrn '__imp_gfxAddGfx' as gfxAddGfx:qword
;        extrn '__imp_gfxBatchChange' as gfxBatchChange:qword
;        extrn '__imp_gfxCreateGfxFactoriesList' as gfxCreateGfxFactoriesList:qword
;        extrn '__imp_gfxCreateZoneFactoriesList' as gfxCreateZoneFactoriesList:qword
;        extrn '__imp_gfxDestroyDeviceInterfaceList' as gfxDestroyDeviceInterfaceList:qword
;        extrn '__imp_gfxEnumerateGfxs' as gfxEnumerateGfxs:qword
;        extrn '__imp_gfxLogoff' as gfxLogoff:qword
;        extrn '__imp_gfxLogon' as gfxLogon:qword
;        extrn '__imp_gfxModifyGfx' as gfxModifyGfx:qword
;        extrn '__imp_gfxOpenGfx' as gfxOpenGfx:qword
;        extrn '__imp_gfxRemoveGfx' as gfxRemoveGfx:qword
;        extrn '__imp_MigrateAllDrivers' as MigrateAllDrivers:qword
;        extrn '__imp_MigrateSoundEvents' as MigrateSoundEvents:qword
;        extrn '__imp_winmmDbgOut' as winmmDbgOut:qword
;        extrn '__imp_WinmmLogoff' as WinmmLogoff:qword
;        extrn '__imp_WinmmLogon' as WinmmLogon:qword
;        extrn '__imp_winmmSetDebugLevel' as winmmSetDebugLevel:QWORD
;    else
;        extrn '__imp__gfxAddGfx@??' as gfxAddGfx:dword
;        extrn '__imp__gfxBatchChange@??' as gfxBatchChange:dword
;        extrn '__imp__gfxCreateGfxFactoriesList@??' as gfxCreateGfxFactoriesList:dword
;        extrn '__imp__gfxCreateZoneFactoriesList@??' as gfxCreateZoneFactoriesList:dword
;        extrn '__imp__gfxDestroyDeviceInterfaceList@??' as gfxDestroyDeviceInterfaceList:dword
;        extrn '__imp__gfxEnumerateGfxs@??' as gfxEnumerateGfxs:dword
;        extrn '__imp__gfxLogoff@??' as gfxLogoff:dword
;        extrn '__imp__gfxLogon@??' as gfxLogon:dword
;        extrn '__imp__gfxModifyGfx@??' as gfxModifyGfx:dword
;        extrn '__imp__gfxOpenGfx@??' as gfxOpenGfx:dword
;        extrn '__imp__gfxRemoveGfx@??' as gfxRemoveGfx:dword
;        extrn '__imp__MigrateAllDrivers@??' as MigrateAllDrivers:dword
;        extrn '__imp__MigrateSoundEvents@??' as MigrateSoundEvents:dword
;        extrn '__imp__winmmDbgOut@??' as winmmDbgOut:dword
;        extrn '__imp__WinmmLogoff@??' as WinmmLogoff:dword
;        extrn '__imp__WinmmLogon@??' as WinmmLogon:dword
;        extrn '__imp__winmmSetDebugLevel@??' as winmmSetDebugLevel:dword
;    end if
;end if

end if ;WINMM_INC
