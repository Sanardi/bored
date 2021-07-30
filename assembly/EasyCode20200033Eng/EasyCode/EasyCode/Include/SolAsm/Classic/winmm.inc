; ====================================================;
;                                                     ;
;     winmm.inc for EC v2 SolAsm classic projects     ;
;                   (version 1.0.3)                   ;
;                                                     ;
;         Copyright © Ramon Sala - 2018-2019          ;
;                                                     ;
; ====================================================;

#ifndef WINMM_INC
WINMM_INC equ 1

MAXERRORLENGTH                                  equ     256

#ifndef MM_MICROSOFT
    MM_MICROSOFT                                equ     1
#endif

#ifndef MM_MIDI_MAPPER
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
#endif

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

#ifndef MM_DRVM_OPEN
    MM_DRVM_OPEN                                equ     03D0H
    MM_DRVM_CLOSE                               equ     03D1H
    MM_DRVM_DATA                                equ     03D2H
    MM_DRVM_ERROR                               equ     03D3H
#endif

MM_STREAM_OPEN                                  equ     03D4H
MM_STREAM_CLOSE                                 equ     03D5H
MM_STREAM_DONE                                  equ     03D6H
MM_STREAM_ERROR                                 equ     03D7H

MM_MOM_POSITIONCB                               equ     03CAH

#ifndef MM_MCISIGNAL
    MM_MCISIGNAL                                equ     03CBH
#endif

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
MMSYSERR_ERROR                                  equ     (MMSYSERR_BASE+1)
MMSYSERR_BADDEVICEID                            equ     (MMSYSERR_BASE+2)
MMSYSERR_NOTENABLED                             equ     (MMSYSERR_BASE+3)
MMSYSERR_ALLOCATED                              equ     (MMSYSERR_BASE+4)
MMSYSERR_INVALHANDLE                            equ     (MMSYSERR_BASE+5)
MMSYSERR_NODRIVER                               equ     (MMSYSERR_BASE+6)
MMSYSERR_NOMEM                                  equ     (MMSYSERR_BASE+7)
MMSYSERR_NOTSUPPORTED                           equ     (MMSYSERR_BASE+8)
MMSYSERR_BADERRNUM                              equ     (MMSYSERR_BASE+9)
MMSYSERR_INVALFLAG                              equ     (MMSYSERR_BASE+10)
MMSYSERR_INVALPARAM                             equ     (MMSYSERR_BASE+11)
MMSYSERR_HANDLEBUSY                             equ     (MMSYSERR_BASE+12)

MMSYSERR_INVALIDALIAS                           equ     (MMSYSERR_BASE+13)
MMSYSERR_BADDB                                  equ     (MMSYSERR_BASE+14)
MMSYSERR_KEYNOTFOUND                            equ     (MMSYSERR_BASE+15)
MMSYSERR_READERROR                              equ     (MMSYSERR_BASE+16)
MMSYSERR_WRITEERROR                             equ     (MMSYSERR_BASE+17)
MMSYSERR_DELETEERROR                            equ     (MMSYSERR_BASE+18)
MMSYSERR_VALNOTFOUND                            equ     (MMSYSERR_BASE+19)
MMSYSERR_NODRIVERCB                             equ     (MMSYSERR_BASE+20)
MMSYSERR_MOREDATA                               equ     (MMSYSERR_BASE+21)
MMSYSERR_LASTERROR                              equ     (MMSYSERR_BASE+21)

#ifndef DRV_LOAD
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
    
    struc DRVCONFIGINFO
        dwDCISize                               dd    ?
        lpszDCISectionName                      xword ?
        lpszDCIAliasName                        xword ?
    ends
#endif

DRV_CANCEL                                     equ     DRVCNF_CANCEL
DRV_OK                                         equ     DRVCNF_OK
DRV_RESTART                                    equ     DRVCNF_RESTART

DRV_MCI_FIRST                                  equ     DRV_RESERVED
DRV_MCI_LAST                                   equ     (DRV_RESERVED+0FFFH)

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

SND_ALIAS_SYSTEMASTERISK                       equ     <((SND_ALIAS_START+53h+2Ah)+((53h+2Ah) shl 8))>
SND_ALIAS_SYSTEMQUESTION                       equ     <((SND_ALIAS_START+53h+3Fh)+((53h+3Fh) shl 8))>
SND_ALIAS_SYSTEMHAND                           equ     <((SND_ALIAS_START+53h+48h)+((53h+48h) shl 8))>
SND_ALIAS_SYSTEMEXIT                           equ     <((SND_ALIAS_START+53h+45h)+((53h+45h) shl 8))>
SND_ALIAS_SYSTEMSTART                          equ     <((SND_ALIAS_START+53h+53h)+((53h+53h) shl 8))>
SND_ALIAS_SYSTEMWELCOME                        equ     <((SND_ALIAS_START+53h+57h)+((53h+57h) shl 8))>
SND_ALIAS_SYSTEMEXCLAMATION                    equ     <((SND_ALIAS_START+53h+21h)+((53h+21h) shl 8))>
SND_ALIAS_SYSTEMDEFAULT                        equ     <((SND_ALIAS_START+53h+44h)+((53h+44h) shl 8))>

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
WAVE_FORMAT_DIRECT_QUERY                       equ     <WAVE_FORMAT_QUERY+WAVE_FORMAT_DIRECT>

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

MIDIERR_UNPREPARED                             equ     (MIDIERR_BASE+0)
MIDIERR_STILLPLAYING                           equ     (MIDIERR_BASE+1)
MIDIERR_NOMAP                                  equ     (MIDIERR_BASE+2)
MIDIERR_NOTREADY                               equ     (MIDIERR_BASE+3)
MIDIERR_NODEVICE                               equ     (MIDIERR_BASE+4)
MIDIERR_INVALIDSETUP                           equ     (MIDIERR_BASE+5)
MIDIERR_BADOPENMODE                            equ     (MIDIERR_BASE+6)
MIDIERR_DONT_CONTINUE                          equ     (MIDIERR_BASE+7)
MIDIERR_LASTERROR                              equ     (MIDIERR_BASE+7)

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

MIXERR_INVALLINE                               equ     (MIXERR_BASE+0)
MIXERR_INVALCONTROL                            equ     (MIXERR_BASE+1)
MIXERR_INVALVALUE                              equ     (MIXERR_BASE+2)
MIXERR_LASTERROR                               equ     (MIXERR_BASE+2)

MIXER_OBJECTF_HANDLE                           equ     80000000H
MIXER_OBJECTF_MIXER                            equ     00000000H
MIXER_OBJECTF_HMIXER                           equ     <MIXER_OBJECTF_HANDLE+MIXER_OBJECTF_MIXER>
MIXER_OBJECTF_WAVEOUT                          equ     10000000H
MIXER_OBJECTF_HWAVEOUT                         equ     <MIXER_OBJECTF_HANDLE+MIXER_OBJECTF_WAVEOUT>
MIXER_OBJECTF_WAVEIN                           equ     20000000H
MIXER_OBJECTF_HWAVEIN                          equ     <MIXER_OBJECTF_HANDLE+MIXER_OBJECTF_WAVEIN>
MIXER_OBJECTF_MIDIOUT                          equ     30000000H
MIXER_OBJECTF_HMIDIOUT                         equ     <MIXER_OBJECTF_HANDLE+MIXER_OBJECTF_MIDIOUT>
MIXER_OBJECTF_MIDIIN                           equ     40000000H
MIXER_OBJECTF_HMIDIIN                          equ     <MIXER_OBJECTF_HANDLE+MIXER_OBJECTF_MIDIIN>
MIXER_OBJECTF_AUX                              equ     50000000H

MIXERLINE_LINEF_ACTIVE                         equ     00000001H
MIXERLINE_LINEF_DISCONNECTED                   equ     00008000H
MIXERLINE_LINEF_SOURCE                         equ     80000000H

MIXERLINE_COMPONENTTYPE_DST_FIRST              equ     000000000H
MIXERLINE_COMPONENTTYPE_DST_UNDEFINED          equ     (MIXERLINE_COMPONENTTYPE_DST_FIRST+0)
MIXERLINE_COMPONENTTYPE_DST_DIGITAL            equ     (MIXERLINE_COMPONENTTYPE_DST_FIRST+1)
MIXERLINE_COMPONENTTYPE_DST_LINE               equ     (MIXERLINE_COMPONENTTYPE_DST_FIRST+2)
MIXERLINE_COMPONENTTYPE_DST_MONITOR            equ     (MIXERLINE_COMPONENTTYPE_DST_FIRST+3)
MIXERLINE_COMPONENTTYPE_DST_SPEAKERS           equ     (MIXERLINE_COMPONENTTYPE_DST_FIRST+4)
MIXERLINE_COMPONENTTYPE_DST_HEADPHONES         equ     (MIXERLINE_COMPONENTTYPE_DST_FIRST+5)
MIXERLINE_COMPONENTTYPE_DST_TELEPHONE          equ     (MIXERLINE_COMPONENTTYPE_DST_FIRST+6)
MIXERLINE_COMPONENTTYPE_DST_WAVEIN             equ     (MIXERLINE_COMPONENTTYPE_DST_FIRST+7)
MIXERLINE_COMPONENTTYPE_DST_VOICEIN            equ     (MIXERLINE_COMPONENTTYPE_DST_FIRST+8)
MIXERLINE_COMPONENTTYPE_DST_LAST               equ     (MIXERLINE_COMPONENTTYPE_DST_FIRST+8)

MIXERLINE_COMPONENTTYPE_SRC_FIRST              equ     00001000H
MIXERLINE_COMPONENTTYPE_SRC_UNDEFINED          equ     (MIXERLINE_COMPONENTTYPE_SRC_FIRST+0)
MIXERLINE_COMPONENTTYPE_SRC_DIGITAL            equ     (MIXERLINE_COMPONENTTYPE_SRC_FIRST+1)
MIXERLINE_COMPONENTTYPE_SRC_LINE               equ     (MIXERLINE_COMPONENTTYPE_SRC_FIRST+2)
MIXERLINE_COMPONENTTYPE_SRC_MICROPHONE         equ     (MIXERLINE_COMPONENTTYPE_SRC_FIRST+3)
MIXERLINE_COMPONENTTYPE_SRC_SYNTHESIZER        equ     (MIXERLINE_COMPONENTTYPE_SRC_FIRST+4)
MIXERLINE_COMPONENTTYPE_SRC_COMPACTDISC        equ     (MIXERLINE_COMPONENTTYPE_SRC_FIRST+5)
MIXERLINE_COMPONENTTYPE_SRC_TELEPHONE          equ     (MIXERLINE_COMPONENTTYPE_SRC_FIRST+6)
MIXERLINE_COMPONENTTYPE_SRC_PCSPEAKER          equ     (MIXERLINE_COMPONENTTYPE_SRC_FIRST+7)
MIXERLINE_COMPONENTTYPE_SRC_WAVEOUT            equ     (MIXERLINE_COMPONENTTYPE_SRC_FIRST+8)
MIXERLINE_COMPONENTTYPE_SRC_AUXILIARY          equ     (MIXERLINE_COMPONENTTYPE_SRC_FIRST+9)
MIXERLINE_COMPONENTTYPE_SRC_ANALOG             equ     (MIXERLINE_COMPONENTTYPE_SRC_FIRST+10)
MIXERLINE_COMPONENTTYPE_SRC_LAST               equ     (MIXERLINE_COMPONENTTYPE_SRC_FIRST+10)

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

MIXERCONTROL_CONTROLTYPE_CUSTOM                equ     <MIXERCONTROL_CT_CLASS_CUSTOM+MIXERCONTROL_CT_UNITS_CUSTOM>
MIXERCONTROL_CONTROLTYPE_BOOLEANMETER          equ     <MIXERCONTROL_CT_CLASS_METER+MIXERCONTROL_CT_SC_METER_POLLED+MIXERCONTROL_CT_UNITS_BOOLEAN>
MIXERCONTROL_CONTROLTYPE_SIGNEDMETER           equ     <MIXERCONTROL_CT_CLASS_METER+MIXERCONTROL_CT_SC_METER_POLLED+MIXERCONTROL_CT_UNITS_SIGNED>
MIXERCONTROL_CONTROLTYPE_PEAKMETER             equ     (MIXERCONTROL_CONTROLTYPE_SIGNEDMETER+1)
MIXERCONTROL_CONTROLTYPE_UNSIGNEDMETER         equ     <MIXERCONTROL_CT_CLASS_METER+MIXERCONTROL_CT_SC_METER_POLLED+MIXERCONTROL_CT_UNITS_UNSIGNED>
MIXERCONTROL_CONTROLTYPE_BOOLEAN               equ     <MIXERCONTROL_CT_CLASS_SWITCH+MIXERCONTROL_CT_SC_SWITCH_BOOLEAN+MIXERCONTROL_CT_UNITS_BOOLEAN>
MIXERCONTROL_CONTROLTYPE_ONOFF                 equ     (MIXERCONTROL_CONTROLTYPE_BOOLEAN+1)
MIXERCONTROL_CONTROLTYPE_MUTE                  equ     (MIXERCONTROL_CONTROLTYPE_BOOLEAN+2)
MIXERCONTROL_CONTROLTYPE_MONO                  equ     (MIXERCONTROL_CONTROLTYPE_BOOLEAN+3)
MIXERCONTROL_CONTROLTYPE_LOUDNESS              equ     (MIXERCONTROL_CONTROLTYPE_BOOLEAN+4)
MIXERCONTROL_CONTROLTYPE_STEREOENH             equ     (MIXERCONTROL_CONTROLTYPE_BOOLEAN+5)
MIXERCONTROL_CONTROLTYPE_BASS_BOOST            equ     (MIXERCONTROL_CONTROLTYPE_BOOLEAN+00002277H)
MIXERCONTROL_CONTROLTYPE_BUTTON                equ     <MIXERCONTROL_CT_CLASS_SWITCH+MIXERCONTROL_CT_SC_SWITCH_BUTTON+MIXERCONTROL_CT_UNITS_BOOLEAN>
MIXERCONTROL_CONTROLTYPE_DECIBELS              equ     <MIXERCONTROL_CT_CLASS_NUMBER+MIXERCONTROL_CT_UNITS_DECIBELS>
MIXERCONTROL_CONTROLTYPE_SIGNED                equ     <MIXERCONTROL_CT_CLASS_NUMBER+MIXERCONTROL_CT_UNITS_SIGNED>
MIXERCONTROL_CONTROLTYPE_UNSIGNED              equ     <MIXERCONTROL_CT_CLASS_NUMBER+MIXERCONTROL_CT_UNITS_UNSIGNED>
MIXERCONTROL_CONTROLTYPE_PERCENT               equ     <MIXERCONTROL_CT_CLASS_NUMBER+MIXERCONTROL_CT_UNITS_PERCENT>
MIXERCONTROL_CONTROLTYPE_SLIDER                equ     <MIXERCONTROL_CT_CLASS_SLIDER+MIXERCONTROL_CT_UNITS_SIGNED>
MIXERCONTROL_CONTROLTYPE_PAN                   equ     (MIXERCONTROL_CONTROLTYPE_SLIDER+1)
MIXERCONTROL_CONTROLTYPE_QSOUNDPAN             equ     (MIXERCONTROL_CONTROLTYPE_SLIDER+2)
MIXERCONTROL_CONTROLTYPE_FADER                 equ     <MIXERCONTROL_CT_CLASS_FADER+MIXERCONTROL_CT_UNITS_UNSIGNED>
MIXERCONTROL_CONTROLTYPE_VOLUME                equ     (MIXERCONTROL_CONTROLTYPE_FADER+1)
MIXERCONTROL_CONTROLTYPE_BASS                  equ     (MIXERCONTROL_CONTROLTYPE_FADER+2)
MIXERCONTROL_CONTROLTYPE_TREBLE                equ     (MIXERCONTROL_CONTROLTYPE_FADER+3)
MIXERCONTROL_CONTROLTYPE_EQUALIZER             equ     (MIXERCONTROL_CONTROLTYPE_FADER+4)
MIXERCONTROL_CONTROLTYPE_SINGLESELECT          equ     <MIXERCONTROL_CT_CLASS_LIST+MIXERCONTROL_CT_SC_LIST_SINGLE+MIXERCONTROL_CT_UNITS_BOOLEAN>
MIXERCONTROL_CONTROLTYPE_MUX                   equ     (MIXERCONTROL_CONTROLTYPE_SINGLESELECT+1)
MIXERCONTROL_CONTROLTYPE_MULTIPLESELECT        equ     <MIXERCONTROL_CT_CLASS_LIST+MIXERCONTROL_CT_SC_LIST_MULTIPLE+MIXERCONTROL_CT_UNITS_BOOLEAN>
MIXERCONTROL_CONTROLTYPE_MIXER                 equ     (MIXERCONTROL_CONTROLTYPE_MULTIPLESELECT+1)
MIXERCONTROL_CONTROLTYPE_MICROTIME             equ     <MIXERCONTROL_CT_CLASS_TIME+MIXERCONTROL_CT_SC_TIME_MICROSECS+MIXERCONTROL_CT_UNITS_UNSIGNED>
MIXERCONTROL_CONTROLTYPE_MILLITIME             equ     <MIXERCONTROL_CT_CLASS_TIME+MIXERCONTROL_CT_SC_TIME_MILLISECS+MIXERCONTROL_CT_UNITS_UNSIGNED>

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
TIMERR_NOCANDO                                 equ     (TIMERR_BASE+1)
TIMERR_STRUCT                                  equ     (TIMERR_BASE+33)

TIME_ONESHOT                                   equ     0000H
TIME_PERIODIC                                  equ     0001H

TIME_CALLBACK_FUNCTION                         equ     0000H
TIME_CALLBACK_EVENT_SET                        equ     0010H
TIME_CALLBACK_EVENT_PULSE                      equ     0020H

TIME_KILL_SYNCHRONOUS                          equ     0100H

JOYERR_NOERROR                                 equ     0
JOYERR_PARMS                                   equ     (JOYERR_BASE+5)
JOYERR_NOCANDO                                 equ     (JOYERR_BASE+6)
JOYERR_UNPLUGGED                               equ     (JOYERR_BASE+7)

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
JOY_RETURNALL                                  equ     <JOY_RETURNX+JOY_RETURNY+JOY_RETURNZ+JOY_RETURNR+JOY_RETURNU+JOY_RETURNV+JOY_RETURNPOV+JOY_RETURNBUTTONS>
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
MMIOERR_FILENOTFOUND                           equ     (MMIOERR_BASE+1)
MMIOERR_OUTOFMEMORY                            equ     (MMIOERR_BASE+2)
MMIOERR_CANNOTOPEN                             equ     (MMIOERR_BASE+3)
MMIOERR_CANNOTCLOSE                            equ     (MMIOERR_BASE+4)
MMIOERR_CANNOTREAD                             equ     (MMIOERR_BASE+5)
MMIOERR_CANNOTWRITE                            equ     (MMIOERR_BASE+6)
MMIOERR_CANNOTSEEK                             equ     (MMIOERR_BASE+7)
MMIOERR_CANNOTEXPAND                           equ     (MMIOERR_BASE+8)
MMIOERR_CHUNKNOTFOUND                          equ     (MMIOERR_BASE+9)
MMIOERR_UNBUFFERED                             equ     (MMIOERR_BASE+10)
MMIOERR_PATHNOTFOUND                           equ     (MMIOERR_BASE+11)
MMIOERR_ACCESSDENIED                           equ     (MMIOERR_BASE+12)
MMIOERR_SHARINGVIOLATION                       equ     (MMIOERR_BASE+13)
MMIOERR_NETWORKERROR                           equ     (MMIOERR_BASE+14)
MMIOERR_TOOMANYOPENFILES                       equ     (MMIOERR_BASE+15)
MMIOERR_INVALIDFILE                            equ     (MMIOERR_BASE+16)

;CFSEPCHAR                                      db      '+',0

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

;FOURCC_RIFF                                    db      'RIFF',0
;FOURCC_LIST                                    db      'LIST',0
;FOURCC_DOS                                     db      'DOS ',0
;FOURCC_MEM                                     db      'MEM ',0

#ifndef SEEK_SET
    SEEK_SET                                   equ     0
    SEEK_CUR                                   equ     1
    SEEK_END                                   equ     2
#endif

MMIO_DEFAULTBUFFER                             equ     8192
MCIERR_INVALID_DEVICE_ID                       equ     (MCIERR_BASE+1)
MCIERR_UNRECOGNIZED_KEYWORD                    equ     (MCIERR_BASE+3)
MCIERR_UNRECOGNIZED_COMMAND                    equ     (MCIERR_BASE+5)
MCIERR_HARDWARE                                equ     (MCIERR_BASE+6)
MCIERR_INVALID_DEVICE_NAME                     equ     (MCIERR_BASE+7)
MCIERR_OUT_OF_MEMORY                           equ     (MCIERR_BASE+8)
MCIERR_DEVICE_OPEN                             equ     (MCIERR_BASE+9)
MCIERR_CANNOT_LOAD_DRIVER                      equ     (MCIERR_BASE+10)
MCIERR_MISSING_COMMAND_STRING                  equ     (MCIERR_BASE+11)
MCIERR_PARAM_OVERFLOW                          equ     (MCIERR_BASE+12)
MCIERR_MISSING_STRING_ARGUMENT                 equ     (MCIERR_BASE+13)
MCIERR_BAD_INTEGER                             equ     (MCIERR_BASE+14)
MCIERR_PARSER_INTERNAL                         equ     (MCIERR_BASE+15)
MCIERR_DRIVER_INTERNAL                         equ     (MCIERR_BASE+16)
MCIERR_MISSING_PARAMETER                       equ     (MCIERR_BASE+17)
MCIERR_UNSUPPORTED_FUNCTION                    equ     (MCIERR_BASE+18)
MCIERR_FILE_NOT_FOUND                          equ     (MCIERR_BASE+19)
MCIERR_DEVICE_NOT_READY                        equ     (MCIERR_BASE+20)
MCIERR_INTERNAL                                equ     (MCIERR_BASE+21)
MCIERR_DRIVER                                  equ     (MCIERR_BASE+22)
MCIERR_CANNOT_USE_ALL                          equ     (MCIERR_BASE+23)
MCIERR_MULTIPLE                                equ     (MCIERR_BASE+24)
MCIERR_EXTENSION_NOT_FOUND                     equ     (MCIERR_BASE+25)
MCIERR_OUTOFRANGE                              equ     (MCIERR_BASE+26)
MCIERR_FLAGS_NOT_COMPATIBLE                    equ     (MCIERR_BASE+28)
MCIERR_FILE_NOT_SAVED                          equ     (MCIERR_BASE+30)
MCIERR_DEVICE_TYPE_REQUIRED                    equ     (MCIERR_BASE+31)
MCIERR_DEVICE_LOCKED                           equ     (MCIERR_BASE+32)
MCIERR_DUPLICATE_ALIAS                         equ     (MCIERR_BASE+33)
MCIERR_BAD_CONSTANT                            equ     (MCIERR_BASE+34)
MCIERR_MUST_USE_SHAREABLE                      equ     (MCIERR_BASE+35)
MCIERR_MISSING_DEVICE_NAME                     equ     (MCIERR_BASE+36)
MCIERR_BAD_TIME_FORMAT                         equ     (MCIERR_BASE+37)
MCIERR_NO_CLOSING_QUOTE                        equ     (MCIERR_BASE+38)
MCIERR_DUPLICATE_FLAGS                         equ     (MCIERR_BASE+39)
MCIERR_INVALID_FILE                            equ     (MCIERR_BASE+40)
MCIERR_NULL_PARAMETER_BLOCK                    equ     (MCIERR_BASE+41)
MCIERR_UNNAMED_RESOURCE                        equ     (MCIERR_BASE+42)
MCIERR_NEW_REQUIRES_ALIAS                      equ     (MCIERR_BASE+43)
MCIERR_NOTIFY_ON_AUTO_OPEN                     equ     (MCIERR_BASE+44)
MCIERR_NO_ELEMENT_ALLOWED                      equ     (MCIERR_BASE+45)
MCIERR_NONAPPLICABLE_FUNCTION                  equ     (MCIERR_BASE+46)
MCIERR_ILLEGAL_FOR_AUTO_OPEN                   equ     (MCIERR_BASE+47)
MCIERR_FILENAME_REQUIRED                       equ     (MCIERR_BASE+48)
MCIERR_EXTRA_CHARACTERS                        equ     (MCIERR_BASE+49)
MCIERR_DEVICE_NOT_INSTALLED                    equ     (MCIERR_BASE+50)
MCIERR_GET_CD                                  equ     (MCIERR_BASE+51)
MCIERR_SET_CD                                  equ     (MCIERR_BASE+52)
MCIERR_SET_DRIVE                               equ     (MCIERR_BASE+53)
MCIERR_DEVICE_LENGTH                           equ     (MCIERR_BASE+54)
MCIERR_DEVICE_ORD_LENGTH                       equ     (MCIERR_BASE+55)
MCIERR_NO_INTEGER                              equ     (MCIERR_BASE+56)
MCIERR_WAVE_OUTPUTSINUSE                       equ     (MCIERR_BASE+64)
MCIERR_WAVE_SETOUTPUTINUSE                     equ     (MCIERR_BASE+65)
MCIERR_WAVE_INPUTSINUSE                        equ     (MCIERR_BASE+66)
MCIERR_WAVE_SETINPUTINUSE                      equ     (MCIERR_BASE+67)
MCIERR_WAVE_OUTPUTUNSPECIFIED                  equ     (MCIERR_BASE+68)
MCIERR_WAVE_INPUTUNSPECIFIED                   equ     (MCIERR_BASE+69)
MCIERR_WAVE_OUTPUTSUNSUITABLE                  equ     (MCIERR_BASE+70)
MCIERR_WAVE_SETOUTPUTUNSUITABLE                equ     (MCIERR_BASE+71)
MCIERR_WAVE_INPUTSUNSUITABLE                   equ     (MCIERR_BASE+72)
MCIERR_WAVE_SETINPUTUNSUITABLE                 equ     (MCIERR_BASE+73)
MCIERR_SEQ_DIV_INCOMPATIBLE                    equ     (MCIERR_BASE+80)
MCIERR_SEQ_PORT_INUSE                          equ     (MCIERR_BASE+81)
MCIERR_SEQ_PORT_NONEXISTENT                    equ     (MCIERR_BASE+82)
MCIERR_SEQ_PORT_MAPNODEVICE                    equ     (MCIERR_BASE+83)
MCIERR_SEQ_PORT_MISCERROR                      equ     (MCIERR_BASE+84)
MCIERR_SEQ_TIMER                               equ     (MCIERR_BASE+85)
MCIERR_SEQ_PORTUNSPECIFIED                     equ     (MCIERR_BASE+86)
MCIERR_SEQ_NOMIDIPRESENT                       equ     (MCIERR_BASE+87)
MCIERR_NO_WINDOW                               equ     (MCIERR_BASE+90)
MCIERR_CREATEWINDOW                            equ     (MCIERR_BASE+91)
MCIERR_FILE_READ                               equ     (MCIERR_BASE+92)
MCIERR_FILE_WRITE                              equ     (MCIERR_BASE+93)
MCIERR_NO_IDENTITY                             equ     (MCIERR_BASE+94)
MCIERR_CUSTOM_DRIVER_BASE                      equ     (MCIERR_BASE+256)

MCI_FIRST                                      equ     DRV_MCI_FIRST

MCI_OPEN                                       equ     0803H
MCI_ESCAPE                                     equ     0805H
MCI_INFO                                       equ     080AH
MCI_GETDEVCAPS                                 equ     080BH
MCI_SPIN                                       equ     080CH
MCI_SET                                        equ     080DH
MCI_SYSINFO                                    equ     0810H
MCI_BREAK                                      equ     0811H
MCI_STATUS                                     equ     0814H
MCI_CUE                                        equ     0830H
MCI_REALIZE                                    equ     0840H
MCI_WINDOW                                     equ     0841H
MCI_PUT                                        equ     0842H
MCI_WHERE                                      equ     0843H
MCI_FREEZE                                     equ     0844H
MCI_UNFREEZE                                   equ     0845H
MCI_LOAD                                       equ     0850H
MCI_UPDATE                                     equ     0854H

MCI_USER_MESSAGES                              equ     (DRV_MCI_FIRST+400)
MCI_LAST                                       equ     0FFFH

;MCI_ALL_DEVICE_ID                             equ     (MCIDEVICEID-1)

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

MCI_VD_MODE_PARK                               equ     (MCI_VD_OFFSET+1)

MCI_VD_MEDIA_CLV                               equ     (MCI_VD_OFFSET+2)
MCI_VD_MEDIA_CAV                               equ     (MCI_VD_OFFSET+3)
MCI_VD_MEDIA_OTHER                             equ     (MCI_VD_OFFSET+4)

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

MCI_CDA_TRACK_AUDIO                            equ     (MCI_CD_OFFSET+0)
MCI_CDA_TRACK_OTHER                            equ     (MCI_CD_OFFSET+1)

MCI_WAVE_PCM                                   equ     (MCI_WAVE_OFFSET+0)
MCI_WAVE_MAPPER                                equ     (MCI_WAVE_OFFSET+1)

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

MCI_SEQ_DIV_PPQN                               equ     (0+MCI_SEQ_OFFSET)
MCI_SEQ_DIV_SMPTE_24                           equ     (1+MCI_SEQ_OFFSET)
MCI_SEQ_DIV_SMPTE_25                           equ     (2+MCI_SEQ_OFFSET)
MCI_SEQ_DIV_SMPTE_30DROP                       equ     (3+MCI_SEQ_OFFSET)
MCI_SEQ_DIV_SMPTE_30                           equ     (4+MCI_SEQ_OFFSET)

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

;======================================== Functions =======================================;

#if NTDDI_VERSION == NTDDI_VISTA
    import aux32Message
#endif
import auxGetDevCapsA
import auxGetDevCapsW
import auxGetNumDevs
import auxGetVolume
import auxOutMessage
import auxSetVolume
import CloseDriver
import DefDriverProc
import DriverCallback
import DrvGetModuleHandle
import GetDriverModuleHandle
#if NTDDI_VERSION == NTDDI_VISTA
    import joy32Message
#endif
import joyConfigChanged
import joyGetDevCapsA
import joyGetDevCapsW
import joyGetNumDevs
import joyGetPos
import joyGetPosEx
import joyGetThreshold
import joyReleaseCapture
import joySetCapture
import joySetThreshold
#if NTDDI_VERSION == NTDDI_VISTA
    import mci32Message
#endif
import mciDriverNotify
import mciDriverYield
import mciExecute
import mciFreeCommandResource
import mciGetCreatorTask
import mciGetDeviceIDA
import mciGetDeviceIDFromElementIDA
import mciGetDeviceIDFromElementIDW
import mciGetDeviceIDW
import mciGetDriverData
import mciGetErrorStringA
import mciGetErrorStringW
import mciGetYieldProc
import mciLoadCommandResource
import mciSendCommandA
import mciSendCommandW
import mciSendStringA
import mciSendStringW
import mciSetDriverData
import mciSetYieldProc
#if NTDDI_VERSION == NTDDI_VISTA
    import mid32Message
#endif
import midiConnect
import midiDisconnect
import midiInAddBuffer
import midiInClose
import midiInGetDevCapsA
import midiInGetDevCapsW
import midiInGetErrorTextA
import midiInGetErrorTextW
import midiInGetID
import midiInGetNumDevs
import midiInMessage
import midiInOpen
import midiInPrepareHeader
import midiInReset
import midiInStart
import midiInStop
import midiInUnprepareHeader
import midiOutCacheDrumPatches
import midiOutCachePatches
import midiOutClose
import midiOutGetDevCapsA
import midiOutGetDevCapsW
import midiOutGetErrorTextA
import midiOutGetErrorTextW
import midiOutGetID
import midiOutGetNumDevs
import midiOutGetVolume
import midiOutLongMsg
import midiOutMessage
import midiOutOpen
import midiOutPrepareHeader
import midiOutReset
import midiOutSetVolume
import midiOutShortMsg
import midiOutUnprepareHeader
import midiStreamClose
import midiStreamOpen
import midiStreamOut
import midiStreamPause
import midiStreamPosition
import midiStreamProperty
import midiStreamRestart
import midiStreamStop
import mixerClose
import mixerGetControlDetailsA
import mixerGetControlDetailsW
import mixerGetDevCapsA
import mixerGetDevCapsW
import mixerGetID
import mixerGetLineControlsA
import mixerGetLineControlsW
import mixerGetLineInfoA
import mixerGetLineInfoW
import mixerGetNumDevs
import mixerMessage
import mixerOpen
import mixerSetControlDetails
import mmDrvInstall
import mmGetCurrentTask
import mmioAdvance
import mmioAscend
import mmioClose
import mmioCreateChunk
import mmioDescend
import mmioFlush
import mmioGetInfo
import mmioInstallIOProcA
import mmioInstallIOProcW
import mmioOpenA
import mmioOpenW
import mmioRead
import mmioRenameA
import mmioRenameW
import mmioSeek
import mmioSendMessage
import mmioSetBuffer
import mmioSetInfo
import mmioStringToFOURCCA
import mmioStringToFOURCCW
import mmioWrite
import mmsystemGetVersion
import mmTaskBlock
import mmTaskCreate
import mmTaskSignal
import mmTaskYield
#if NTDDI_VERSION == NTDDI_VISTA
    import mod32Message
    import mxd32Message
    import NotifyCallbackData
#endif
import OpenDriver
import PlaySoundA
import PlaySoundW
import SendDriverMessage
import sndPlaySoundA
import sndPlaySoundW
#if NTDDI_VERSION == NTDDI_VISTA
    import tid32Message
#endif
import timeBeginPeriod
import timeEndPeriod
import timeGetDevCaps
import timeGetSystemTime
import timeGetTime
import timeKillEvent
import timeSetEvent
import waveInAddBuffer
import waveInClose
import waveInGetDevCapsA
import waveInGetDevCapsW
import waveInGetErrorTextA
import waveInGetErrorTextW
import waveInGetID
import waveInGetNumDevs
import waveInGetPosition
import waveInMessage
import waveInOpen
import waveInPrepareHeader
import waveInReset
import waveInStart
import waveInStop
import waveInUnprepareHeader
import waveOutBreakLoop
import waveOutClose
import waveOutGetDevCapsA
import waveOutGetDevCapsW
import waveOutGetErrorTextA
import waveOutGetErrorTextW
import waveOutGetID
import waveOutGetNumDevs
import waveOutGetPitch
import waveOutGetPlaybackRate
import waveOutGetPosition
import waveOutGetVolume
import waveOutMessage
import waveOutOpen
import waveOutPause
import waveOutPrepareHeader
import waveOutReset
import waveOutRestart
import waveOutSetPitch
import waveOutSetPlaybackRate
import waveOutSetVolume
import waveOutUnprepareHeader
import waveOutWrite
#if NTDDI_VERSION == NTDDI_VISTA
    import wid32Message
    import wod32Message
    import WOW32DriverCallback
    import WOW32ResolveMultiMediaHandle
#endif
import WOWAppExit

#ifdef APP_UNICODE
    define auxGetDevCaps auxGetDevCapsW
    define joyGetDevCaps joyGetDevCapsW
    define mciGetDeviceID mciGetDeviceIDW
    define mciGetDeviceIDFromElementID mciGetDeviceIDFromElementIDW
    define mciGetErrorString mciGetErrorStringW
    define mciSendCommand mciSendCommandW
    define mciSendString mciSendStringW
    define midiInGetDevCaps midiInGetDevCapsW
    define midiInGetErrorText midiInGetErrorTextW
    define midiOutGetDevCaps midiOutGetDevCapsW
    define midiOutGetErrorText midiOutGetErrorTextW
    define mixerGetControlDetails mixerGetControlDetailsW
    define mixerGetDevCaps mixerGetDevCapsW
    define mixerGetLineControls mixerGetLineControlsW
    define mixerGetLineInfo mixerGetLineInfoW
    define mmioInstallIOProc mmioInstallIOProcW
    define mmioOpen mmioOpenW
    define mmioRename mmioRenameW
    define mmioStringToFOURCC mmioStringToFOURCCW
    define PlaySound PlaySoundW
    define sndPlaySound sndPlaySoundW
    define waveInGetDevCaps waveInGetDevCapsW
    define waveInGetErrorText waveInGetErrorTextW
    define waveOutGetDevCaps waveOutGetDevCapsW
    define waveOutGetErrorText waveOutGetErrorTextW
#else
    define auxGetDevCaps auxGetDevCapsA
    define joyGetDevCaps joyGetDevCapsA
    define mciGetDeviceID mciGetDeviceIDA
    define mciGetDeviceIDFromElementID mciGetDeviceIDFromElementIDA
    define mciGetErrorString mciGetErrorStringA
    define mciSendCommand mciSendCommandA
    define mciSendString mciSendStringA
    define midiInGetDevCaps midiInGetDevCapsA
    define midiInGetErrorText midiInGetErrorTextA
    define midiOutGetDevCaps midiOutGetDevCapsA
    define midiOutGetErrorText midiOutGetErrorTextA
    define mixerGetControlDetails mixerGetControlDetailsA
    define mixerGetDevCaps mixerGetDevCapsA
    define mixerGetLineControls mixerGetLineControlsA
    define mixerGetLineInfo mixerGetLineInfoA
    define mmioInstallIOProc mmioInstallIOProcA
    define mmioOpen mmioOpenA
    define mmioRename mmioRenameA
    define mmioStringToFOURCC mmioStringToFOURCCA
    define PlaySound PlaySoundA
    define sndPlaySound sndPlaySoundA
    define waveInGetDevCaps waveInGetDevCapsA
    define waveInGetErrorText waveInGetErrorTextA
    define waveOutGetDevCaps waveOutGetDevCapsA
    define waveOutGetErrorText waveOutGetErrorTextA
#endif


;======================= Undocumented functions (unknown arguments) =======================;

;#if NTDDI_VERSION < NTDDI_VISTA
;    import gfxAddGfx
;    import gfxBatchChange
;    import gfxCreateGfxFactoriesList
;    import gfxCreateZoneFactoriesList
;    import gfxDestroyDeviceInterfaceList
;    import gfxEnumerateGfxs
;    import gfxLogoff
;    import gfxLogon
;    import gfxModifyGfx
;    import gfxOpenGfx
;    import gfxRemoveGfx
;    import MigrateAllDrivers
;    import MigrateSoundEvents
;    import winmmDbgOut
;    import WinmmLogoff
;    import WinmmLogon
;    import winmmSetDebugLevel
;#endif

#endif ;WINMM_INC
