;======================================================;
;                                                      ;
;   vfw32.inc for Easy Code 2.0 64-bit Masm projects   ;
;                   (version 1.0.0)                    ;
;                                                      ;
;              Copyright © Ramon Sala 2018             ;
;                                                      ;
;======================================================;

IFNDEF VFW32_INC
VFW32_INC       EQU        1

IFNDEF WINMM_INC
    Include winmm.inc
ENDIF

BI_1632                                         EQU     032333631H

IFNDEF ICTYPE_VIDEO
    ICTYPE_VIDEO                                EQU     "cdiv"
    ICTYPE_AUDIO                                EQU     "cdua"
ENDIF

IFNDEF ICERR_OK
    ICERR_OK                                    EQU     0
    ICERR_DONTDRAW                              EQU     1
    ICERR_NEWPALETTE                            EQU     2
    ICERR_GOTOKEYFRAME                          EQU     3
    ICERR_STOPDRAWING                           EQU     4
    ICERR_UNSUPPORTED                           EQU     (-1)
    ICERR_BADFORMAT                             EQU     (-2)
    ICERR_MEMORY                                EQU     (-3)
    ICERR_INTERNAL                              EQU     (-4)
    ICERR_BADFLAGS                              EQU     (-5)
    ICERR_BADPARAM                              EQU     (-6)
    ICERR_BADSIZE                               EQU     (-7)
    ICERR_BADHANDLE                             EQU     (-8)
    ICERR_CANTUPDATE                            EQU     (-9)
    ICERR_ABORT                                 EQU     (-10)
    ICERR_ERROR                                 EQU     (-100)
    ICERR_BADBITDEPTH                           EQU     (-200)
    ICERR_BADIMAGESIZE                          EQU     (-201)
    ICERR_CUSTOM                                EQU     (-400)
ENDIF

IFNDEF ICMODE_COMPRESS
    ICMODE_COMPRESS                             EQU     1
    ICMODE_DECOMPRESS                           EQU     2
    ICMODE_FASTDECOMPRESS                       EQU     3
    ICMODE_QUERY                                EQU     4
    ICMODE_FASTCOMPRESS                         EQU     5
    ICMODE_DRAW                                 EQU     8
ENDIF

AVIIF_LIST                                      EQU     00000001H
AVIIF_TWOCC                                     EQU     00000002H
AVIIF_KEYFRAME                                  EQU     00000010H
AVIIF_FIRSTPART                                 EQU     00000020H
AVIIF_LASTPART                                  EQU     00000040H
AVIIF_MIDPART                                   EQU     (AVIIF_LASTPART OR AVIIF_FIRSTPART)
AVIIF_NOTIME                                    EQU     00000100H
AVIIF_COMPUSE                                   EQU     0FFF0000H

ICQUALITY_LOW                                   EQU     0
ICQUALITY_HIGH                                  EQU     10000
ICQUALITY_DEFAULT                               EQU     (-1)

ICM_USER                                        EQU     (DRV_USER + 0000H)

ICM_RESERVED                                    EQU     ICM_RESERVED_LOW
ICM_RESERVED_LOW                                EQU     (DRV_USER + 01000H)
ICM_RESERVED_HIGH                               EQU     (DRV_USER + 02000H)

ICM_GETSTATE                                    EQU     (ICM_RESERVED + 0)
ICM_SETSTATE                                    EQU     (ICM_RESERVED + 1)
ICM_GETINFO                                     EQU     (ICM_RESERVED + 2)
ICM_CONFIGURE                                   EQU     (ICM_RESERVED + 10)
ICM_ABOUT                                       EQU     (ICM_RESERVED + 11)
ICM_GETERRORTEXT                                EQU     (ICM_RESERVED + 12)
ICM_GETFORMATNAME                               EQU     (ICM_RESERVED + 20)
ICM_ENUMFORMATS                                 EQU     (ICM_RESERVED + 21)
ICM_GETDEFAULTQUALITY                           EQU     (ICM_RESERVED + 30)
ICM_GETQUALITY                                  EQU     (ICM_RESERVED + 31)
ICM_SETQUALITY                                  EQU     (ICM_RESERVED + 32)
ICM_SET                                         EQU     (ICM_RESERVED + 40)
ICM_GET                                         EQU     (ICM_RESERVED + 41)

ICM_FRAMERATE                                   EQU     "RmrF"
ICM_KEYFRAMERATE                                EQU     "RyeK"

ICM_COMPRESS_GET_FORMAT                         EQU     (ICM_USER + 4)
ICM_COMPRESS_GET_SIZE                           EQU     (ICM_USER + 5)
ICM_COMPRESS_QUERY                              EQU     (ICM_USER + 6)
ICM_COMPRESS_BEGIN                              EQU     (ICM_USER + 7)
ICM_COMPRESS                                    EQU     (ICM_USER + 8)
ICM_COMPRESS_END                                EQU     (ICM_USER + 9)
ICM_DECOMPRESS_GET_FORMAT                       EQU     (ICM_USER + 10)
ICM_DECOMPRESS_QUERY                            EQU     (ICM_USER + 11)
ICM_DECOMPRESS_BEGIN                            EQU     (ICM_USER + 12)
ICM_DECOMPRESS                                  EQU     (ICM_USER + 13)
ICM_DECOMPRESS_END                              EQU     (ICM_USER + 14)
ICM_DECOMPRESS_SET_PALETTE                      EQU     (ICM_USER + 29)
ICM_DECOMPRESS_GET_PALETTE                      EQU     (ICM_USER + 30)
ICM_DRAW_QUERY                                  EQU     (ICM_USER + 31)
ICM_DRAW_BEGIN                                  EQU     (ICM_USER + 15)
ICM_DRAW_GET_PALETTE                            EQU     (ICM_USER + 16)
ICM_DRAW_UPDATE                                 EQU     (ICM_USER + 17)
ICM_DRAW_START                                  EQU     (ICM_USER + 18)
ICM_DRAW_STOP                                   EQU     (ICM_USER + 19)
ICM_DRAW_BITS                                   EQU     (ICM_USER + 20)
ICM_DRAW_END                                    EQU     (ICM_USER + 21)
ICM_DRAW_GETTIME                                EQU     (ICM_USER + 32)
ICM_DRAW                                        EQU     (ICM_USER + 33)
ICM_DRAW_WINDOW                                 EQU     (ICM_USER + 34)
ICM_DRAW_SETTIME                                EQU     (ICM_USER + 35)
ICM_DRAW_REALIZE                                EQU     (ICM_USER + 36)
ICM_DRAW_FLUSH                                  EQU     (ICM_USER + 37)
ICM_DRAW_RENDERBUFFER                           EQU     (ICM_USER + 38)
ICM_DRAW_START_PLAY                             EQU     (ICM_USER + 39)
ICM_DRAW_STOP_PLAY                              EQU     (ICM_USER + 40)
ICM_DRAW_SUGGESTFORMAT                          EQU     (ICM_USER + 50)
ICM_DRAW_CHANGEPALETTE                          EQU     (ICM_USER + 51)
ICM_DRAW_IDLE                                   EQU     (ICM_USER + 52)
ICM_GETBUFFERSWANTED                            EQU     (ICM_USER + 41)
ICM_GETDEFAULTKEYFRAMERATE                      EQU     (ICM_USER + 42)
ICM_DECOMPRESSEX_BEGIN                          EQU     (ICM_USER + 60)
ICM_DECOMPRESSEX_QUERY                          EQU     (ICM_USER + 61)
ICM_DECOMPRESSEX                                EQU     (ICM_USER + 62)
ICM_DECOMPRESSEX_END                            EQU     (ICM_USER + 63)
ICM_COMPRESS_FRAMES_INFO                        EQU     (ICM_USER + 70)
ICM_COMPRESS_FRAMES                             EQU     (ICM_USER + 71)
ICM_SET_STATUS_PROC                             EQU     (ICM_USER + 72)

VIDCF_QUALITY                                   EQU     0001H
VIDCF_CRUNCH                                    EQU     0002H
VIDCF_TEMPORAL                                  EQU     0004H
VIDCF_COMPRESSFRAMES                            EQU     0008H
VIDCF_DRAW                                      EQU     0010H
VIDCF_FASTTEMPORALC                             EQU     0020H
VIDCF_FASTTEMPORALD                             EQU     0080H

ICCOMPRESS_KEYFRAME                             EQU     00000001H

ICCOMPRESSFRAMES_PADDING                        EQU     00000001H

ICSTATUS_START                                  EQU     0
ICSTATUS_STATUS                                 EQU     1
ICSTATUS_END                                    EQU     2
ICSTATUS_ERROR                                  EQU     3
ICSTATUS_YIELD                                  EQU     4

ICDECOMPRESS_HURRYUP                            EQU     80000000H
ICDECOMPRESS_UPDATE                             EQU     40000000H
ICDECOMPRESS_PREROLL                            EQU     20000000H
ICDECOMPRESS_NULLFRAME                          EQU     10000000H
ICDECOMPRESS_NOTKEYFRAME                        EQU     08000000H

ICDRAW_QUERY                                    EQU     00000001H
ICDRAW_FULLSCREEN                               EQU     00000002H
ICDRAW_HDC                                      EQU     00000004H
ICDRAW_ANIMATE                                  EQU     00000008H
ICDRAW_CONTINUE                                 EQU     00000010H
ICDRAW_MEMORYDC                                 EQU     00000020H
ICDRAW_UPDATING                                 EQU     00000040H
ICDRAW_RENDER                                   EQU     00000080H
ICDRAW_BUFFER                                   EQU     00000100H

ICDRAW_HURRYUP                                  EQU     80000000H
ICDRAW_UPDATE                                   EQU     40000000H
ICDRAW_PREROLL                                  EQU     20000000H
ICDRAW_NULLFRAME                                EQU     10000000H
ICDRAW_NOTKEYFRAME                              EQU     08000000H

ICINSTALL_UNICODE                               EQU     8000H
ICINSTALL_FUNCTION                              EQU     0001H
ICINSTALL_DRIVER                                EQU     0002H
ICINSTALL_HDRV                                  EQU     0004H
ICINSTALL_DRIVERW                               EQU     8002H

ICMF_CONFIGURE_QUERY                            EQU     00000001H
ICMF_ABOUT_QUERY                                EQU     00000001H

ICDECOMPRESS_HURRYUP                            EQU     80000000H

ICMF_COMPVARS_VALID                             EQU     00000001H

ICMF_CHOOSE_KEYFRAME                            EQU     0001H
ICMF_CHOOSE_DATARATE                            EQU     0002H
ICMF_CHOOSE_PREVIEW                             EQU     0004H
ICMF_CHOOSE_ALLCOMPRESSORS                      EQU     0008H

DDF_0001                                        EQU     0001H
DDF_UPDATE                                      EQU     0002H
DDF_SAME_HDC                                    EQU     0004H
DDF_SAME_DRAW                                   EQU     0008H
DDF_DONTDRAW                                    EQU     0010H
DDF_ANIMATE                                     EQU     0020H
DDF_BUFFER                                      EQU     0040H
DDF_JUSTDRAWIT                                  EQU     0080H
DDF_FULLSCREEN                                  EQU     0100H
DDF_BACKGROUNDPAL                               EQU     0200H
DDF_NOTKEYFRAME                                 EQU     0400H
DDF_HURRYUP                                     EQU     0800H
DDF_HALFTONE                                    EQU     1000H
DDF_2000                                        EQU     2000H

DDF_PREROLL                                     EQU     DDF_DONTDRAW
DDF_SAME_DIB                                    EQU     DDF_SAME_DRAW
DDF_SAME_SIZE                                   EQU     DDF_SAME_DRAW

PD_CAN_DRAW_DIB                                 EQU     0001H
PD_CAN_STRETCHDIB                               EQU     0002H
PD_STRETCHDIB_1_1_OK                            EQU     0004H
PD_STRETCHDIB_1_2_OK                            EQU     0008H
PD_STRETCHDIB_1_N_OK                            EQU     0010H

formtypeAVI                                     EQU     " IVA"
listtypeAVIHEADER                               EQU     "lrdh"
ckidAVIMAINHDR                                  EQU     "hiva"
listtypeSTREAMHEADER                            EQU     "lrts"
ckidSTREAMHEADER                                EQU     "hrts"
ckidSTREAMFORMAT                                EQU     "frts"
ckidSTREAMHANDLERDATA                           EQU     "drts"
ckidSTREAMNAME                                  EQU     "nrts"

listtypeAVIMOVIE                                EQU     "ivom"
listtypeAVIRECORD                               EQU     " cer"

ckidAVINEWINDEX                                 EQU     "1xdi"

streamtypeVIDEO                                 EQU     "sdiv"
streamtypeAUDIO                                 EQU     "sdua"
streamtypeMIDI                                  EQU     "sdim"
streamtypeTEXT                                  EQU     "stxt"

cktypeDIBbits                                   EQU     "bd"
cktypeDIBcompressed                             EQU     "cd"
cktypePALchange                                 EQU     "cp"
cktypeWAVEbytes                                 EQU     "bw"

ckidAVIPADDING                                  EQU     "KNUJ"

AVIF_HASINDEX                                   EQU     00000010H
AVIF_MUSTUSEINDEX                               EQU     00000020H
AVIF_ISINTERLEAVED                              EQU     00000100H
AVIF_WASCAPTUREFILE                             EQU     00010000H
AVIF_COPYRIGHTED                                EQU     00020000H

AVI_HEADERSIZE                                  EQU     2048

AVISF_DISABLED                                  EQU     00000001H
AVISF_VIDEO_PALCHANGES                          EQU     00010000H

AVIGETFRAMEF_BESTDISPLAYFMT                     EQU     1

AVISTREAMINFO_DISABLED                          EQU     00000001H
AVISTREAMINFO_FORMATCHANGES                     EQU     00010000H

AVIFILEINFO_HASINDEX                            EQU     00000010H
AVIFILEINFO_MUSTUSEINDEX                        EQU     00000020H
AVIFILEINFO_ISINTERLEAVED                       EQU     00000100H
AVIFILEINFO_WASCAPTUREFILE                      EQU     00010000H
AVIFILEINFO_COPYRIGHTED                         EQU     00020000H

AVIFILECAPS_CANREAD                             EQU     00000001H
AVIFILECAPS_CANWRITE                            EQU     00000002H
AVIFILECAPS_ALLKEYFRAMES                        EQU     00000010H
AVIFILECAPS_NOCOMPRESSION                       EQU     00000020H

AVICOMPRESSF_INTERLEAVE                         EQU     00000001H
AVICOMPRESSF_DATARATE                           EQU     00000002H
AVICOMPRESSF_KEYFRAMES                          EQU     00000004H
AVICOMPRESSF_VALID                              EQU     00000008H

GUID_IID_IAVIFile                               EQU     <00020020H,0,0,{0C0H,0,0,0,0,0,0,046H}>
GUID_IID_IAVIStream                             EQU     <00020021H,0,0,{0C0H,0,0,0,0,0,0,046H}>
GUID_IID_IAVIStreaming                          EQU     <00020022H,0,0,{0C0H,0,0,0,0,0,0,046H}>
GUID_IID_IGetFrame                              EQU     <00020023H,0,0,{0C0H,0,0,0,0,0,0,046H}>
GUID_IID_IAVIEditStream                         EQU     <00020024H,0,0,{0C0H,0,0,0,0,0,0,046H}>
GUID_CLSID_AVISimpleUnMarshal                   EQU     <00020009H,0,0,{0C0H,0,0,0,0,0,0,046H}>
GUID_CLSID_AVIFile                              EQU     <00020000H,0,0,{0C0H,0,0,0,0,0,0,046H}>

AVIFILEHANDLER_CANREAD                          EQU     0001H
AVIFILEHANDLER_CANWRITE                         EQU     0002H
AVIFILEHANDLER_CANACCEPTNONRGB                  EQU     0004H

AVISTREAMREAD_CONVENIENT                        EQU     (-1)

FIND_DIR                                        EQU     0000000FH
FIND_NEXT                                       EQU     00000001H
FIND_PREV                                       EQU     00000004H
FIND_FROM_START                                 EQU     00000008H

FIND_TYPE                                       EQU     000000F0H
FIND_KEY                                        EQU     00000010H
FIND_ANY                                        EQU     00000020H
FIND_FORMAT                                     EQU     00000040H

FIND_RET                                        EQU     0000F000H
FIND_POS                                        EQU     00000000H
FIND_LENGTH                                     EQU     00001000H
FIND_OFFSET                                     EQU     00002000H
FIND_SIZE                                       EQU     00003000H
FIND_INDEX                                      EQU     00004000H

SEARCH_NEAREST                                  EQU     FIND_PREV
SEARCH_BACKWARD                                 EQU     FIND_PREV
SEARCH_FORWARD                                  EQU     FIND_NEXT
SEARCH_KEY                                      EQU     FIND_KEY
SEARCH_ANY                                      EQU     FIND_ANY

IFNDEF AVIERR_OK
    AVIERR_OK                                   EQU     0
    AVIERR_UNSUPPORTED                          EQU     (1 SHL 31) OR (4 SHL 16) OR (101)
    AVIERR_BADFORMAT                            EQU     (1 SHL 31) OR (4 SHL 16) OR (102)
    AVIERR_MEMORY                               EQU     (1 SHL 31) OR (4 SHL 16) OR (103)
    AVIERR_INTERNAL                             EQU     (1 SHL 31) OR (4 SHL 16) OR (104)
    AVIERR_BADFLAGS                             EQU     (1 SHL 31) OR (4 SHL 16) OR (105)
    AVIERR_BADPARAM                             EQU     (1 SHL 31) OR (4 SHL 16) OR (106)
    AVIERR_BADSIZE                              EQU     (1 SHL 31) OR (4 SHL 16) OR (107)
    AVIERR_BADHANDLE                            EQU     (1 SHL 31) OR (4 SHL 16) OR (108)
    AVIERR_FILEREAD                             EQU     (1 SHL 31) OR (4 SHL 16) OR (109)
    AVIERR_FILEWRITE                            EQU     (1 SHL 31) OR (4 SHL 16) OR (110)
    AVIERR_FILEOPEN                             EQU     (1 SHL 31) OR (4 SHL 16) OR (111)
    AVIERR_COMPRESSOR                           EQU     (1 SHL 31) OR (4 SHL 16) OR (112)
    AVIERR_NOCOMPRESSOR                         EQU     (1 SHL 31) OR (4 SHL 16) OR (113)
    AVIERR_READONLY                             EQU     (1 SHL 31) OR (4 SHL 16) OR (114)
    AVIERR_NODATA                               EQU     (1 SHL 31) OR (4 SHL 16) OR (115)
    AVIERR_BUFFERTOOSMALL                       EQU     (1 SHL 31) OR (4 SHL 16) OR (116)
    AVIERR_CANTCOMPRESS                         EQU     (1 SHL 31) OR (4 SHL 16) OR (117)
    AVIERR_USERABORT                            EQU     (1 SHL 31) OR (4 SHL 16) OR (198)
    AVIERR_ERROR                                EQU     (1 SHL 31) OR (4 SHL 16) OR (199)
ENDIF

IFNDEF comptypeDIB
    comptypeDIB                                 EQU     " BID"
ENDIF

MCIWNDOPENF_NEW                                 EQU     0001H

MCIWNDF_NOAUTOSIZEWINDOW                        EQU     0001H
MCIWNDF_NOPLAYBAR                               EQU     0002H
MCIWNDF_NOAUTOSIZEMOVIE                         EQU     0004H
MCIWNDF_NOMENU                                  EQU     0008H
MCIWNDF_SHOWNAME                                EQU     0010H
MCIWNDF_SHOWPOS                                 EQU     0020H
MCIWNDF_SHOWMODE                                EQU     0040H
MCIWNDF_SHOWALL                                 EQU     0070H
MCIWNDF_NOTIFYMODE                              EQU     0100H
MCIWNDF_NOTIFYPOS                               EQU     0200H
MCIWNDF_NOTIFYSIZE                              EQU     0400H
MCIWNDF_NOTIFYERROR                             EQU     1000H
MCIWNDF_NOTIFYALL                               EQU     1F00H
MCIWNDF_NOTIFYANSI                              EQU     0080H
MCIWNDF_NOTIFYMEDIAA                            EQU     0880H
MCIWNDF_NOTIFYMEDIAW                            EQU     0800H
MCIWNDF_RECORD                                  EQU     2000H
MCIWNDF_NOERRORDLG                              EQU     4000H
MCIWNDF_NOOPEN                                  EQU     8000H

MCIWNDM_GETDEVICEID                             EQU     (WM_USER + 100)
MCIWNDM_GETSTART                                EQU     (WM_USER + 103)
MCIWNDM_GETLENGTH                               EQU     (WM_USER + 104)
MCIWNDM_GETEND                                  EQU     (WM_USER + 105)
MCIWNDM_EJECT                                   EQU     (WM_USER + 107)
MCIWNDM_SETZOOM                                 EQU     (WM_USER + 108)
MCIWNDM_GETZOOM                                 EQU     (WM_USER + 109)
MCIWNDM_SETVOLUME                               EQU     (WM_USER + 110)
MCIWNDM_GETVOLUME                               EQU     (WM_USER + 111)
MCIWNDM_SETSPEED                                EQU     (WM_USER + 112)
MCIWNDM_GETSPEED                                EQU     (WM_USER + 113)
MCIWNDM_SETREPEAT                               EQU     (WM_USER + 114)
MCIWNDM_GETREPEAT                               EQU     (WM_USER + 115)
MCIWNDM_REALIZE                                 EQU     (WM_USER + 118)
MCIWNDM_VALIDATEMEDIA                           EQU     (WM_USER + 121)
MCIWNDM_PLAYFROM                                EQU     (WM_USER + 122)
MCIWNDM_PLAYTO                                  EQU     (WM_USER + 123)
MCIWNDM_GETPALETTE                              EQU     (WM_USER + 126)
MCIWNDM_SETPALETTE                              EQU     (WM_USER + 127)
MCIWNDM_SETTIMERS                               EQU     (WM_USER + 129)
MCIWNDM_SETACTIVETIMER                          EQU     (WM_USER + 130)
MCIWNDM_SETINACTIVETIMER                        EQU     (WM_USER + 131)
MCIWNDM_GETACTIVETIMER                          EQU     (WM_USER + 132)
MCIWNDM_GETINACTIVETIMER                        EQU     (WM_USER + 133)
MCIWNDM_CHANGESTYLES                            EQU     (WM_USER + 135)
MCIWNDM_GETSTYLES                               EQU     (WM_USER + 136)
MCIWNDM_GETALIAS                                EQU     (WM_USER + 137)
MCIWNDM_PLAYREVERSE                             EQU     (WM_USER + 139)
MCIWNDM_GET_SOURCE                              EQU     (WM_USER + 140)
MCIWNDM_PUT_SOURCE                              EQU     (WM_USER + 141)
MCIWNDM_GET_DEST                                EQU     (WM_USER + 142)
MCIWNDM_PUT_DEST                                EQU     (WM_USER + 143)
MCIWNDM_CAN_PLAY                                EQU     (WM_USER + 144)
MCIWNDM_CAN_WINDOW                              EQU     (WM_USER + 145)
MCIWNDM_CAN_RECORD                              EQU     (WM_USER + 146)
MCIWNDM_CAN_SAVE                                EQU     (WM_USER + 147)
MCIWNDM_CAN_EJECT                               EQU     (WM_USER + 148)
MCIWNDM_CAN_CONFIG                              EQU     (WM_USER + 149)
MCIWNDM_PALETTEKICK                             EQU     (WM_USER + 150)
MCIWNDM_OPENINTERFACE                           EQU     (WM_USER + 151)
MCIWNDM_SETOWNER                                EQU     (WM_USER + 152)

MCIWNDM_SENDSTRINGA                             EQU     (WM_USER + 101)
MCIWNDM_GETPOSITIONA                            EQU     (WM_USER + 102)
MCIWNDM_GETMODEA                                EQU     (WM_USER + 106)
MCIWNDM_SETTIMEFORMATA                          EQU     (WM_USER + 119)
MCIWNDM_GETTIMEFORMATA                          EQU     (WM_USER + 120)
MCIWNDM_GETFILENAMEA                            EQU     (WM_USER + 124)
MCIWNDM_GETDEVICEA                              EQU     (WM_USER + 125)
MCIWNDM_GETERRORA                               EQU     (WM_USER + 128)
MCIWNDM_NEWA                                    EQU     (WM_USER + 134)
MCIWNDM_RETURNSTRINGA                           EQU     (WM_USER + 138)
MCIWNDM_OPENA                                   EQU     (WM_USER + 153)

MCIWNDM_SENDSTRINGW                             EQU     (WM_USER + 201)
MCIWNDM_GETPOSITIONW                            EQU     (WM_USER + 202)
MCIWNDM_GETMODEW                                EQU     (WM_USER + 206)
MCIWNDM_SETTIMEFORMATW                          EQU     (WM_USER + 219)
MCIWNDM_GETTIMEFORMATW                          EQU     (WM_USER + 220)
MCIWNDM_GETFILENAMEW                            EQU     (WM_USER + 224)
MCIWNDM_GETDEVICEW                              EQU     (WM_USER + 225)
MCIWNDM_GETERRORW                               EQU     (WM_USER + 228)
MCIWNDM_NEWW                                    EQU     (WM_USER + 234)
MCIWNDM_RETURNSTRINGW                           EQU     (WM_USER + 238)
MCIWNDM_OPENW                                   EQU     (WM_USER + 252)

MCIWNDM_NOTIFYMODE                              EQU     (WM_USER + 200)
MCIWNDM_NOTIFYPOS                               EQU     (WM_USER + 201)
MCIWNDM_NOTIFYSIZE                              EQU     (WM_USER + 202)
MCIWNDM_NOTIFYMEDIA                             EQU     (WM_USER + 203)
MCIWNDM_NOTIFYERROR                             EQU     (WM_USER + 205)

MCIWND_START                                    EQU     (-1)
MCIWND_END                                      EQU     (-2)

IFNDEF MCI_PLAY
    MCI_CLOSE                                   EQU     0804H
    MCI_PLAY                                    EQU     0806H
    MCI_SEEK                                    EQU     0807H
    MCI_STOP                                    EQU     0808H
    MCI_PAUSE                                   EQU     0809H
    MCI_STEP                                    EQU     080EH
    MCI_RECORD                                  EQU     080FH
    MCI_SAVE                                    EQU     0813H
    MCI_CUT                                     EQU     0851H
    MCI_COPY                                    EQU     0852H
    MCI_PASTE                                   EQU     0853H
    MCI_RESUME                                  EQU     0855H
    MCI_DELETE                                  EQU     0856H
ENDIF

IFNDEF MCI_MODE_NOT_READY
    MCI_MODE_NOT_READY                          EQU     524
    MCI_MODE_STOP                               EQU     525
    MCI_MODE_PLAY                               EQU     526
    MCI_MODE_RECORD                             EQU     527
    MCI_MODE_SEEK                               EQU     528
    MCI_MODE_PAUSE                              EQU     529
    MCI_MODE_OPEN                               EQU     530
ENDIF

DV_ERR_OK                                       EQU     0
DV_ERR_BASE                                     EQU     1
DV_ERR_NONSPECIFIC                              EQU     (DV_ERR_BASE)
DV_ERR_BADFORMAT                                EQU     (DV_ERR_BASE + 1)
DV_ERR_STILLPLAYING                             EQU     (DV_ERR_BASE + 2)
DV_ERR_UNPREPARED                               EQU     (DV_ERR_BASE + 3)
DV_ERR_SYNC                                     EQU     (DV_ERR_BASE + 4)
DV_ERR_TOOMANYCHANNELS                          EQU     (DV_ERR_BASE + 5)
DV_ERR_NOTDETECTED                              EQU     (DV_ERR_BASE + 6)
DV_ERR_BADINSTALL                               EQU     (DV_ERR_BASE + 7)
DV_ERR_CREATEPALETTE                            EQU     (DV_ERR_BASE + 8)
DV_ERR_SIZEFIELD                                EQU     (DV_ERR_BASE + 9)
DV_ERR_PARAM1                                   EQU     (DV_ERR_BASE + 10)
DV_ERR_PARAM2                                   EQU     (DV_ERR_BASE + 11)
DV_ERR_CONFIG1                                  EQU     (DV_ERR_BASE + 12)
DV_ERR_CONFIG2                                  EQU     (DV_ERR_BASE + 13)
DV_ERR_FLAGS                                    EQU     (DV_ERR_BASE + 14)
DV_ERR_13                                       EQU     (DV_ERR_BASE + 15)
DV_ERR_NOTSUPPORTED                             EQU     (DV_ERR_BASE + 16)
DV_ERR_NOMEM                                    EQU     (DV_ERR_BASE + 17)
DV_ERR_ALLOCATED                                EQU     (DV_ERR_BASE + 18)
DV_ERR_BADDEVICEID                              EQU     (DV_ERR_BASE + 19)
DV_ERR_INVALHANDLE                              EQU     (DV_ERR_BASE + 20)
DV_ERR_BADERRNUM                                EQU     (DV_ERR_BASE + 21)
DV_ERR_NO_BUFFERS                               EQU     (DV_ERR_BASE + 22)
DV_ERR_MEM_CONFLICT                             EQU     (DV_ERR_BASE + 23)
DV_ERR_IO_CONFLICT                              EQU     (DV_ERR_BASE + 24)
DV_ERR_DMA_CONFLICT                             EQU     (DV_ERR_BASE + 25)
DV_ERR_INT_CONFLICT                             EQU     (DV_ERR_BASE + 26)
DV_ERR_PROTECT_ONLY                             EQU     (DV_ERR_BASE + 27)
DV_ERR_LASTERROR                                EQU     (DV_ERR_BASE + 27)
DV_ERR_USER_MSG                                 EQU     (DV_ERR_BASE + 1000)

IFNDEF MM_DRVM_OPEN
    MM_DRVM_OPEN                                EQU     3D0H
    MM_DRVM_CLOSE                               EQU     3D1H
    MM_DRVM_DATA                                EQU     3D2H
    MM_DRVM_ERROR                               EQU     3D3H
ENDIF

DV_VM_OPEN                                      EQU     MM_DRVM_OPEN
DV_VM_CLOSE                                     EQU     MM_DRVM_CLOSE
DV_VM_DATA                                      EQU     MM_DRVM_DATA
DV_VM_ERROR                                     EQU     MM_DRVM_ERROR

VHDR_DONE                                       EQU     00000001H
VHDR_PREPARED                                   EQU     00000002H
VHDR_INQUEUE                                    EQU     00000004H
VHDR_KEYFRAME                                   EQU     00000008H
VHDR_VALID                                      EQU     0000000FH

VCAPS_OVERLAY                                   EQU     00000001H
VCAPS_SRC_CAN_CLIP                              EQU     00000002H
VCAPS_DST_CAN_CLIP                              EQU     00000004H
VCAPS_CAN_SCALE                                 EQU     00000008H

VIDEO_EXTERNALIN                                EQU     0001H
VIDEO_EXTERNALOUT                               EQU     0002H
VIDEO_IN                                        EQU     0004H
VIDEO_OUT                                       EQU     0008H

VIDEO_DLG_QUERY                                 EQU     0010H

VIDEO_CONFIGURE_QUERY                           EQU     8000H
VIDEO_CONFIGURE_SET                             EQU     1000H
VIDEO_CONFIGURE_GET                             EQU     2000H
VIDEO_CONFIGURE_QUERYSIZE                       EQU     0001H
VIDEO_CONFIGURE_CURRENT                         EQU     0010H
VIDEO_CONFIGURE_NOMINAL                         EQU     0020H
VIDEO_CONFIGURE_MIN                             EQU     0040H
VIDEO_CONFIGURE_MAX                             EQU     0080H

DVM_USER                                        EQU     4000H

DVM_CONFIGURE_START                             EQU     1000H
DVM_CONFIGURE_END                               EQU     1FFFH

DVM_PALETTE                                     EQU     (DVM_CONFIGURE_START + 1)
DVM_FORMAT                                      EQU     (DVM_CONFIGURE_START + 2)
DVM_PALETTERGB555                               EQU     (DVM_CONFIGURE_START + 3)
DVM_SRC_RECT                                    EQU     (DVM_CONFIGURE_START + 4)
DVM_DST_RECT                                    EQU     (DVM_CONFIGURE_START + 5)

WM_CAP_START                                    EQU     WM_USER
WM_CAP_UNICODE_START                            EQU     (WM_USER + 100)
WM_CAP_GET_CAPSTREAMPTR                         EQU     (WM_CAP_START + 1)
WM_CAP_SET_CALLBACK_ERRORW                      EQU     (WM_CAP_UNICODE_START + 2)
WM_CAP_SET_CALLBACK_STATUSW                     EQU     (WM_CAP_UNICODE_START + 3)
WM_CAP_SET_CALLBACK_ERRORA                      EQU     (WM_CAP_START + 2)
WM_CAP_SET_CALLBACK_STATUSA                     EQU     (WM_CAP_START + 3)
WM_CAP_SET_CALLBACK_YIELD                       EQU     (WM_CAP_START + 4)
WM_CAP_SET_CALLBACK_FRAME                       EQU     (WM_CAP_START + 5)
WM_CAP_SET_CALLBACK_VIDEOSTREAM                 EQU     (WM_CAP_START + 6)
WM_CAP_SET_CALLBACK_WAVESTREAM                  EQU     (WM_CAP_START + 7)
WM_CAP_GET_USER_DATA                            EQU     (WM_CAP_START + 8)
WM_CAP_SET_USER_DATA                            EQU     (WM_CAP_START + 9)
WM_CAP_DRIVER_CONNECT                           EQU     (WM_CAP_START + 10)
WM_CAP_DRIVER_DISCONNECT                        EQU     (WM_CAP_START + 11)
WM_CAP_DRIVER_GET_NAMEA                         EQU     (WM_CAP_START + 12)
WM_CAP_DRIVER_GET_VERSIONA                      EQU     (WM_CAP_START + 13)
WM_CAP_DRIVER_GET_NAMEW                         EQU     (WM_CAP_UNICODE_START + 12)
WM_CAP_DRIVER_GET_VERSIONW                      EQU     (WM_CAP_UNICODE_START + 13)
WM_CAP_DRIVER_GET_CAPS                          EQU     (WM_CAP_START + 14)
WM_CAP_FILE_SET_CAPTURE_FILEA                   EQU     (WM_CAP_START + 20)
WM_CAP_FILE_GET_CAPTURE_FILEA                   EQU     (WM_CAP_START + 21)
WM_CAP_FILE_SAVEASA                             EQU     (WM_CAP_START + 23)
WM_CAP_FILE_SAVEDIBA                            EQU     (WM_CAP_START + 25)
WM_CAP_FILE_SET_CAPTURE_FILEW                   EQU     (WM_CAP_UNICODE_START + 20)
WM_CAP_FILE_GET_CAPTURE_FILEW                   EQU     (WM_CAP_UNICODE_START + 21)
WM_CAP_FILE_SAVEASW                             EQU     (WM_CAP_UNICODE_START + 23)
WM_CAP_FILE_SAVEDIBW                            EQU     (WM_CAP_UNICODE_START + 25)
WM_CAP_FILE_ALLOCATE                            EQU     (WM_CAP_START + 22)
WM_CAP_FILE_SET_INFOCHUNK                       EQU     (WM_CAP_START + 24)
WM_CAP_EDIT_COPY                                EQU     (WM_CAP_START + 30)
WM_CAP_SET_AUDIOFORMAT                          EQU     (WM_CAP_START + 35)
WM_CAP_GET_AUDIOFORMAT                          EQU     (WM_CAP_START + 36)
WM_CAP_DLG_VIDEOFORMAT                          EQU     (WM_CAP_START + 41)
WM_CAP_DLG_VIDEOSOURCE                          EQU     (WM_CAP_START + 42)
WM_CAP_DLG_VIDEODISPLAY                         EQU     (WM_CAP_START + 43)
WM_CAP_GET_VIDEOFORMAT                          EQU     (WM_CAP_START + 44)
WM_CAP_SET_VIDEOFORMAT                          EQU     (WM_CAP_START + 45)
WM_CAP_DLG_VIDEOCOMPRESSION                     EQU     (WM_CAP_START + 46)
WM_CAP_SET_PREVIEW                              EQU     (WM_CAP_START + 50)
WM_CAP_SET_OVERLAY                              EQU     (WM_CAP_START + 51)
WM_CAP_SET_PREVIEWRATE                          EQU     (WM_CAP_START + 52)
WM_CAP_SET_SCALE                                EQU     (WM_CAP_START + 53)
WM_CAP_GET_STATUS                               EQU     (WM_CAP_START + 54)
WM_CAP_SET_SCROLL                               EQU     (WM_CAP_START + 55)
WM_CAP_GRAB_FRAME                               EQU     (WM_CAP_START + 60)
WM_CAP_GRAB_FRAME_NOSTOP                        EQU     (WM_CAP_START + 61)
WM_CAP_SEQUENCE                                 EQU     (WM_CAP_START + 62)
WM_CAP_SEQUENCE_NOFILE                          EQU     (WM_CAP_START + 63)
WM_CAP_SET_SEQUENCE_SETUP                       EQU     (WM_CAP_START + 64)
WM_CAP_GET_SEQUENCE_SETUP                       EQU     (WM_CAP_START + 65)
WM_CAP_SET_MCI_DEVICEA                          EQU     (WM_CAP_START + 66)
WM_CAP_GET_MCI_DEVICEA                          EQU     (WM_CAP_START + 67)
WM_CAP_SET_MCI_DEVICEW                          EQU     (WM_CAP_UNICODE_START + 66)
WM_CAP_GET_MCI_DEVICEW                          EQU     (WM_CAP_UNICODE_START + 67)
WM_CAP_STOP                                     EQU     (WM_CAP_START + 68)
WM_CAP_ABORT                                    EQU     (WM_CAP_START + 69)
WM_CAP_SINGLE_FRAME_OPEN                        EQU     (WM_CAP_START + 70)
WM_CAP_SINGLE_FRAME_CLOSE                       EQU     (WM_CAP_START + 71)
WM_CAP_SINGLE_FRAME                             EQU     (WM_CAP_START + 72)
WM_CAP_PAL_OPENA                                EQU     (WM_CAP_START + 80)
WM_CAP_PAL_SAVEA                                EQU     (WM_CAP_START + 81)
WM_CAP_PAL_OPENW                                EQU     (WM_CAP_UNICODE_START + 80)
WM_CAP_PAL_SAVEW                                EQU     (WM_CAP_UNICODE_START + 81)
WM_CAP_PAL_PASTE                                EQU     (WM_CAP_START + 82)
WM_CAP_PAL_AUTOCREATE                           EQU     (WM_CAP_START + 83)
WM_CAP_PAL_MANUALCREATE                         EQU     (WM_CAP_START + 84)
WM_CAP_SET_CALLBACK_CAPCONTROL                  EQU     (WM_CAP_START + 85)
WM_CAP_UNICODE_END                              EQU     WM_CAP_PAL_SAVEW
WM_CAP_END                                      EQU     WM_CAP_UNICODE_END

AVSTREAMMASTER_AUDIO                            EQU     0
AVSTREAMMASTER_NONE                             EQU     1

CONTROLCALLBACK_PREROLL                         EQU     1
CONTROLCALLBACK_CAPTURING                       EQU     2

infotypeDIGITIZATION_TIME                       EQU     "TIDI"
infotypeSMPTE_TIME                              EQU     "PMSI"

IDS_CAP_BEGIN                                   EQU     300
IDS_CAP_END                                     EQU     301
IDS_CAP_INFO                                    EQU     401
IDS_CAP_OUTOFMEM                                EQU     402
IDS_CAP_FILEEXISTS                              EQU     403
IDS_CAP_ERRORPALOPEN                            EQU     404
IDS_CAP_ERRORPALSAVE                            EQU     405
IDS_CAP_ERRORDIBSAVE                            EQU     406
IDS_CAP_DEFAVIEXT                               EQU     407
IDS_CAP_DEFPALEXT                               EQU     408
IDS_CAP_CANTOPEN                                EQU     409
IDS_CAP_SEQ_MSGSTART                            EQU     410
IDS_CAP_SEQ_MSGSTOP                             EQU     411
IDS_CAP_VIDEDITERR                              EQU     412
IDS_CAP_READONLYFILE                            EQU     413
IDS_CAP_WRITEERROR                              EQU     414
IDS_CAP_NODISKSPACE                             EQU     415
IDS_CAP_SETFILESIZE                             EQU     416
IDS_CAP_SAVEASPERCENT                           EQU     417
IDS_CAP_DRIVER_ERROR                            EQU     418
IDS_CAP_WAVE_OPEN_ERROR                         EQU     419
IDS_CAP_WAVE_ALLOC_ERROR                        EQU     420
IDS_CAP_WAVE_PREPARE_ERROR                      EQU     421
IDS_CAP_WAVE_ADD_ERROR                          EQU     422
IDS_CAP_WAVE_SIZE_ERROR                         EQU     423
IDS_CAP_VIDEO_OPEN_ERROR                        EQU     424
IDS_CAP_VIDEO_ALLOC_ERROR                       EQU     425
IDS_CAP_VIDEO_PREPARE_ERROR                     EQU     426
IDS_CAP_VIDEO_ADD_ERROR                         EQU     427
IDS_CAP_VIDEO_SIZE_ERROR                        EQU     428
IDS_CAP_FILE_OPEN_ERROR                         EQU     429
IDS_CAP_FILE_WRITE_ERROR                        EQU     430
IDS_CAP_RECORDING_ERROR                         EQU     431
IDS_CAP_RECORDING_ERROR2                        EQU     432
IDS_CAP_AVI_INIT_ERROR                          EQU     433
IDS_CAP_NO_FRAME_CAP_ERROR                      EQU     434
IDS_CAP_NO_PALETTE_WARN                         EQU     435
IDS_CAP_MCI_CONTROL_ERROR                       EQU     436
IDS_CAP_MCI_CANT_STEP_ERROR                     EQU     437
IDS_CAP_NO_AUDIO_CAP_ERROR                      EQU     438
IDS_CAP_AVI_DRAWDIB_ERROR                       EQU     439
IDS_CAP_COMPRESSOR_ERROR                        EQU     440
IDS_CAP_AUDIO_DROP_ERROR                        EQU     441
IDS_CAP_AUDIO_DROP_COMPERROR                    EQU     442
IDS_CAP_STAT_LIVE_MODE                          EQU     500
IDS_CAP_STAT_OVERLAY_MODE                       EQU     501
IDS_CAP_STAT_CAP_INIT                           EQU     502
IDS_CAP_STAT_CAP_FINI                           EQU     503
IDS_CAP_STAT_PALETTE_BUILD                      EQU     504
IDS_CAP_STAT_OPTPAL_BUILD                       EQU     505
IDS_CAP_STAT_I_FRAMES                           EQU     506
IDS_CAP_STAT_L_FRAMES                           EQU     507
IDS_CAP_STAT_CAP_L_FRAMES                       EQU     508
IDS_CAP_STAT_CAP_AUDIO                          EQU     509
IDS_CAP_STAT_VIDEOCURRENT                       EQU     510
IDS_CAP_STAT_VIDEOAUDIO                         EQU     511
IDS_CAP_STAT_VIDEOONLY                          EQU     512
IDS_CAP_STAT_FRAMESDROPPED                      EQU     513

IFDEF APP_UNICODE
    MCIWNDF_NOTIFYMEDIA EQU MCIWNDF_NOTIFYMEDIAW
    MCIWNDM_SENDSTRING EQU MCIWNDM_SENDSTRINGW
    MCIWNDM_GETPOSITION EQU MCIWNDM_GETPOSITIONW
    MCIWNDM_GETMODE Equ MCIWNDM_GETMODEW
    MCIWNDM_SETTIMEFORMAT EQU MCIWNDM_SETTIMEFORMATW
    MCIWNDM_GETTIMEFORMAT EQU MCIWNDM_GETTIMEFORMATW
    MCIWNDM_GETFILENAME EQU MCIWNDM_GETFILENAMEW
    MCIWNDM_GETDEVICE EQU MCIWNDM_GETDEVICEW
    MCIWNDM_GETERROR EQU MCIWNDM_GETERRORW
    MCIWNDM_NEW EQU MCIWNDM_NEWW
    MCIWNDM_RETURNSTRING EQU MCIWNDM_RETURNSTRINGW
    MCIWNDM_OPEN EQU MCIWNDM_OPENW
    WM_CAP_SET_CALLBACK_ERROR EQU WM_CAP_SET_CALLBACK_ERRORW
    WM_CAP_SET_CALLBACK_STATUS EQU WM_CAP_SET_CALLBACK_STATUSW
    WM_CAP_DRIVER_GET_NAME EQU WM_CAP_DRIVER_GET_NAMEW
    WM_CAP_DRIVER_GET_VERSION EQU WM_CAP_DRIVER_GET_VERSIONW
    WM_CAP_FILE_SET_CAPTURE_FILE EQU WM_CAP_FILE_SET_CAPTURE_FILEW
    WM_CAP_FILE_GET_CAPTURE_FILE EQU WM_CAP_FILE_GET_CAPTURE_FILEW
    WM_CAP_FILE_SAVEAS EQU WM_CAP_FILE_SAVEASW
    WM_CAP_FILE_SAVEDIB EQU WM_CAP_FILE_SAVEDIBW
    WM_CAP_SET_MCI_DEVICE EQU WM_CAP_SET_MCI_DEVICEW
    WM_CAP_GET_MCI_DEVICE EQU WM_CAP_GET_MCI_DEVICEW
    WM_CAP_PAL_OPEN EQU WM_CAP_PAL_OPENW
    WM_CAP_PAL_SAVE EQU WM_CAP_PAL_SAVEW
ELSE
    MCIWNDF_NOTIFYMEDIA EQU MCIWNDF_NOTIFYMEDIAA
    MCIWNDM_SENDSTRING EQU MCIWNDM_SENDSTRINGA
    MCIWNDM_GETPOSITION EQU MCIWNDM_GETPOSITIONA
    MCIWNDM_GETMODE EQU MCIWNDM_GETMODEA
    MCIWNDM_SETTIMEFORMAT Equ MCIWNDM_SETTIMEFORMATA
    MCIWNDM_GETTIMEFORMAT EQU MCIWNDM_GETTIMEFORMATA
    MCIWNDM_GETFILENAME EQU MCIWNDM_GETFILENAMEA
    MCIWNDM_GETDEVICE EQU MCIWNDM_GETDEVICEA
    MCIWNDM_GETERROR EQU MCIWNDM_GETERRORA
    MCIWNDM_NEW EQU MCIWNDM_NEWA
    MCIWNDM_RETURNSTRING EQU MCIWNDM_RETURNSTRINGA
    MCIWNDM_OPEN EQU MCIWNDM_OPENA
    WM_CAP_SET_CALLBACK_ERROR EQU WM_CAP_SET_CALLBACK_ERRORA
    WM_CAP_SET_CALLBACK_STATUS EQU WM_CAP_SET_CALLBACK_STATUSA
    WM_CAP_DRIVER_GET_NAME EQU WM_CAP_DRIVER_GET_NAMEA
    WM_CAP_DRIVER_GET_VERSION EQU WM_CAP_DRIVER_GET_VERSIONA
    WM_CAP_FILE_SET_CAPTURE_FILE EQU WM_CAP_FILE_SET_CAPTURE_FILEA
    WM_CAP_FILE_GET_CAPTURE_FILE EQU WM_CAP_FILE_GET_CAPTURE_FILEA
    WM_CAP_FILE_SAVEAS EQU WM_CAP_FILE_SAVEASA
    WM_CAP_FILE_SAVEDIB EQU WM_CAP_FILE_SAVEDIBA
    WM_CAP_SET_MCI_DEVICE EQU WM_CAP_SET_MCI_DEVICEA
    WM_CAP_GET_MCI_DEVICE EQU WM_CAP_GET_MCI_DEVICEA
    WM_CAP_PAL_OPEN EQU WM_CAP_PAL_OPENA
    WM_CAP_PAL_SAVE EQU WM_CAP_PAL_SAVEA
ENDIF


;======================================== Structures ======================================;

ICOPEN STRUCT ALIGNMODE
    dwSize      DD   ?
    fccType     DD   ?
    fccHandler  DD   ?
    dwVersion   DD   ?
    dwFlags     DD   ?
    dwError     DD   ?
    pV1Reserved XPTR ?
    pV2Reserved XPTR ?
    dnDevNode   DD   ?
ICOPEN ENDS

ICINFO STRUCT ALIGNMODE
    dwSize        DD ?
    fccType       DD ?
    fccHandler    DD ?
    dwFlags       DD ?
    dwVersion     DD ?
    dwVersionICM  DD ?
    szName        DW 16 DUP(?)
    szDescription DW 128 DUP(?)
    szDriver      DW 128 DUP(?)
ICINFO ENDS

ICCOMPRESS STRUCT ALIGNMODE
    dwFlags     DD   ?
    lpbiOutput  XPTR ?
    lpOutput    XPTR ?
    lpbiInput   XPTR ?
    lpInput     XPTR ?
    lpckid      XPTR ?
    lpdwFlags   XPTR ?
    lFrameNum   DD   ?
    dwFrameSize DD   ?
    dwQuality   DD   ?
    lpbiPrev    XPTR ?
    lpPrev      XPTR ?
ICCOMPRESS ENDS

ICCOMPRESSFRAMES STRUCT ALIGNMODE
    dwFlags            DD     ?
    lpbiOutput         XPTR   ?
    lOutput            LPARAM ?
    lpbiInput          XPTR   ?
    lInput             LPARAM ?
    lStartFrame        DD     ?
    lFrameCount        DD     ?
    lQuality           DD     ?
    lDataRate          DD     ?
    lKeyRate           DD     ?
    dwRate             DD     ?
    dwScale            DD     ?
    dwOverheadPerFrame DD     ?
    dwReserved2        DD     ?
    GetData            XPTR   ?
    PutData            XPTR   ?
ICCOMPRESSFRAMES ENDS

ICSETSTATUSPROC STRUCT ALIGNMODE
    dwFlags    DD     ?
    lParam     LPARAM ?
    fpfnStatus XPTR   ?
ICSETSTATUSPROC ENDS

ICDECOMPRESS STRUCT ALIGNMODE
    dwFlags    DD   ?
    lpbiInput  XPTR ?
    lpInput    XPTR ?
    lpbiOutput XPTR ?
    lpOutput   XPTR ?
    ckid       DD   ?
ICDECOMPRESS ENDS

ICDECOMPRESSEX STRUCT ALIGNMODE
    dwFlags DD   ?
    lpbiSrc XPTR ?
    lpSrc   XPTR ?
    lpbiDst XPTR ?
    lpDst   XPTR ?
    xDst    DD   ?
    yDst    DD   ?
    dxDst   DD   ?
    dyDst   DD   ?
    xSrc    DD   ?
    ySrc    DD   ?
    dxSrc   DD   ?
    dySrc   DD   ?
ICDECOMPRESSEX ENDS

ICDRAWBEGIN STRUCT ALIGNMODE
    dwFlags DD     ?
    hpal    HANDLE ?
    hwnd    HANDLE ?
    hdc     HANDLE ?
    xDst    DD     ?
    yDst    DD     ?
    dxDst   DD     ?
    dyDst   DD     ?
    lpbi    XPTR   ?
    xSrc    DD     ?
    ySrc    DD     ?
    dxSrc   DD     ?
    dySrc   DD     ?
    dwRate  DD     ?
    dwScale DD     ?
ICDRAWBEGIN ENDS

ICDRAW STRUCT ALIGNMODE
    dwFlags  DD   ?
    lpFormat XPTR ?
    lpData   XPTR ?
    cbData   DD   ?
    lTime    DD   ?
ICDRAW ENDS

ICDRAWSUGGEST STRUCT ALIGNMODE
    lpbiIn          XPTR   ?
    lpbiSuggest     XPTR   ?
    dxSrc           DD     ?
    dySrc           DD     ?
    dxDst           DD     ?
    dyDst           DD     ?
    hicDecompressor HANDLE ?
ICDRAWSUGGEST ENDS

ICPALETTE STRUCT ALIGNMODE
    dwFlags DD   ?
    iStart  DD   ?
    iLen    DD   ?
    lppe    XPTR ?
ICPALETTE ENDS

COMPVARS STRUCT ALIGNMODE
    cbSize     DD     ?
    dwFlags    DD     ?
    hic        HANDLE ?
    fccType    DD     ?
    fccHandler DD     ?
    lpbiIn     XPTR   ?
    lpbiOut    XPTR   ?
    lpBitsOut  XPTR   ?
    lpBitsPrev XPTR   ?
    lFrame     DD     ?
    lKey       DD     ?
    lDataRate  DD     ?
    lQ         DD     ?
    lKeyCount  DD     ?
    lpState    XPTR   ?
    cbState    DD     ?
COMPVARS ENDS

DRAWDIBTIME STRUCT ALIGNMODE
    timeCount      DD ?
    timeDraw       DD ?
    timeDecompress DD ?
    timeDither     DD ?
    timeStretch    DD ?
    timeBlt        DD ?
    timeSetDIBits  DD ?
DRAWDIBTIME ENDS

MainAVIHeader STRUCT ALIGNMODE
    dwMicroSecPerFrame    DD ?
    dwMaxBytesPerSec      DD ?
    dwPaddingGranularity  DD ?
    dwFlags               DD ?
    dwTotalFrames         DD ?
    dwInitialFrames       DD ?
    dwStreams             DD ?
    dwSuggestedBufferSize DD ?
    dwWidth               DD ?
    dwHeight              DD ?
    dwReserved            DD 4 DUP(?)
MainAVIHeader ENDS

AVIStreamHeader STRUCT ALIGNMODE
    fccType               DD ?
    fccHandler            DD ?
    dwFlags               DD ?
    wPriority             DW ?
    wLanguage             DW ?
    dwInitialFrames       DD ?
    dwScale               DD ?
    dwRate                DD ?
    dwStart               DD ?
    dwLength              DD ?
    dwSuggestedBufferSize DD ?
    dwQuality             DD ?
    dwSampleSize          DD ?
    rcFrame               RECT <>
AVIStreamHeader ENDS

AVIINDEXENTRY STRUCT ALIGNMODE
    ckid          DD ?
    dwFlags       DD ?
    dwChunkOffset DD ?
    dwChunkLength DD ?
AVIINDEXENTRY ENDS

AVIPALCHANGE STRUCT ALIGNMODE
    bFirstEntry DB ?
    bNumEntries DB ?
    wFlags      DW ?
    peNew       PALETTEENTRY <>
AVIPALCHANGE ENDS

AVISTREAMINFOA STRUCT ALIGNMODE
    fccType               DD ?
    fccHandler            DD ?
    dwFlags               DD ?
    dwCaps                DD ?
    wPriority             DW ?
    wLanguage             DW ?
    dwScale               DD ?
    dwRate                DD ?
    dwStart               DD ?
    dwLength              DD ?
    dwInitialFrames       DD ?
    dwSuggestedBufferSize DD ?
    dwQuality             DD ?
    dwSampleSize          DD ?
    rcFrame               RECT <>
    dwEditCount           DD ?
    dwFormatChangeCount   DD ?
    szName                DB 64 DUP(?)
AVISTREAMINFOA ENDS

AVISTREAMINFOW STRUCT ALIGNMODE
    fccType               DD ?
    fccHandler            DD ?
    dwFlags               DD ?
    dwCaps                DD ?
    wPriority             DW ?
    wLanguage             DW ?
    dwScale               DD ?
    dwRate                DD ?
    dwStart               DD ?
    dwLength              DD ?
    dwInitialFrames       DD ?
    dwSuggestedBufferSize DD ?
    dwQuality             DD ?
    dwSampleSize          DD ?
    rcFrame               RECT <>
    dwEditCount           DD ?
    dwFormatChangeCount   DD ?
    szName                DW 64 DUP(?)
AVISTREAMINFOW ENDS

AVIFILEINFOA STRUCT ALIGNMODE
    dwMaxBytesPerSec      DD ?
    dwFlags               DD ?
    dwCaps                DD ?
    dwStreams             DD ?
    dwSuggestedBufferSize DD ?
    dwWidth               DD ?
    dwHeight              DD ?
    dwScale               DD ?
    dwRate                DD ?
    dwLength              DD ?
    dwEditCount           DD ?
    szFileType            DB 64 DUP(?)
AVIFILEINFOA ENDS

AVIFILEINFOW STRUCT ALIGNMODE
    dwMaxBytesPerSec      DD ?
    dwFlags               DD ?
    dwCaps                DD ?
    dwStreams             DD ?
    dwSuggestedBufferSize DD ?
    dwWidth               DD ?
    dwHeight              DD ?
    dwScale               DD ?
    dwRate                DD ?
    dwLength              DD ?
    dwEditCount           DD ?
    szFileType            DW 64 DUP(?)
AVIFILEINFOW ENDS

AVICOMPRESSOPTIONS STRUCT ALIGNMODE
    fccType           DD   ?
    fccHandler        DD   ?
    dwKeyFrameEvery   DD   ?
    dwQuality         DD   ?
    dwBytesPerSecond  DD   ?
    dwFlags           DD   ?
    lpFormat          XPTR ?
    cbFormat          DD   ?
    lpParms           XPTR ?
    cbParms           DD   ?
    dwInterleaveEvery DD   ?
AVICOMPRESSOPTIONS ENDS

IFDEF APP_UNICODE
    AVISTREAMINFO EQU <AVISTREAMINFOW>
    AVIFILEINFO EQU <AVIFILEINFOW>
ELSE
    AVISTREAMINFO EQU <AVISTREAMINFOA>
    AVIFILEINFO EQU <AVIFILEINFOA>
ENDIF

IAVIStream STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR    ?
            AddRef          XPTR    ?
            Release         XPTR    ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    Create                  XPTR    ?
    Info                    XPTR    ?
    FindSample              XPTR    ?
    ReadFormat              XPTR    ?
    SetFormat               XPTR    ?
    Read                    XPTR    ?
    Write                   XPTR    ?
    Delete                  XPTR    ?
    ReadData                XPTR    ?
    WriteData               XPTR    ?
    SetInfo                 XPTR    ?
IAVIStream ENDS

IAVIStreaming STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    Begin                       XPTR ?
    _End                        XPTR ?
IAVIStreaming ENDS

IAVIEditStream STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    Cut                         XPTR ?
    Copy                        XPTR ?
    Paste                       XPTR ?
    Clone                       XPTR ?
    SetInfo                     XPTR ?
IAVIEditStream ENDS

IAVIFile STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    Info                        XPTR ?
    GetStream                   XPTR ?
    CreateStream                XPTR ?
    WriteData                   XPTR ?
    ReadData                    XPTR ?
    EndRecord                   XPTR ?
    DeleteStream                XPTR ?
IAVIFile ENDS

IGetFrame STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    GetFrame                    XPTR ?
    Begin                       XPTR ?
    _End                        XPTR ?
    SetFormat                   XPTR ?
IGetFrame ENDS

VIDEOHDR STRUCT ALIGNMODE
    lpData         XPTR ?
    dwBufferLength DD   ?
    dwBytesUsed    DD   ?
    dwTimeCaptured DD   ?
    dwUser         DD   ?
    dwFlags        DD   ?
    dwReserved     XPTR 4 DUP(?)
VIDEOHDR ENDS

CHANNEL_CAPS STRUCT ALIGNMODE
    dwFlags            DD ?
    dwSrcRectXMod      DD ?
    dwSrcRectYMod      DD ?
    dwSrcRectWidthMod  DD ?
    dwSrcRectHeightMod DD ?
    dwDstRectXMod      DD ?
    dwDstRectYMod      DD ?
    dwDstRectWidthMod  DD ?
    dwDstRectHeightMod DD ?
CHANNEL_CAPS ENDS

CAPDRIVERCAPS STRUCT ALIGNMODE
    wDeviceIndex            DD     ?
    fHasOverlay             DD     ?
    fHasDlgVideoSource      DD     ?
    fHasDlgVideoFormat      DD     ?
    fHasDlgVideoDisplay     DD     ?
    fCaptureInitialized     DD     ?
    fDriverSuppliesPalettes DD     ?
    hVideoIn                HANDLE ?
    hVideoOut               HANDLE ?
    hVideoExtIn             HANDLE ?
    hVideoExtOut            HANDLE ?
CAPDRIVERCAPS ENDS

CAPSTATUS STRUCT ALIGNMODE
    uiImageWidth                DD     ?
    uiImageHeight               DD     ?
    fLiveWindow                 DD     ?
    fOverlayWindow              DD     ?
    _fScale                     DD     ?
    ptScroll                    POINT  <>
    fUsingDefaultPalette        DD     ?
    fAudioHardware              DD     ?
    fCapFileExists              DD     ?
    dwCurrentVideoFrame         DD     ?
    dwCurrentVideoFramesDropped DD     ?
    dwCurrentWaveSamples        DD     ?
    dwCurrentTimeElapsedMS      DD     ?
    hPalCurrent                 HANDLE ?
    fCapturingNow               DD     ?
    dwReturn                    DD     ?
    wNumVideoAllocated          DD     ?
    wNumAudioAllocated          DD     ?
CAPSTATUS ENDS

CAPTUREPARMS STRUCT ALIGNMODE
    dwRequestMicroSecPerFrame DD ?
    fMakeUserHitOKToCapture   DD ?
    wPercentDropForError      DD ?
    fYield                    DD ?
    dwIndexSize               DD ?
    wChunkGranularity         DD ?
    fUsingDOSMemory           DD ?
    wNumVideoRequested        DD ?
    fCaptureAudio             DD ?
    wNumAudioRequested        DD ?
    vKeyAbort                 DD ?
    fAbortLeftMouse           DD ?
    fAbortRightMouse          DD ?
    fLimitEnabled             DD ?
    wTimeLimit                DD ?
    fMCIControl               DD ?
    fStepMCIDevice            DD ?
    dwMCIStartTime            DD ?
    dwMCIStopTime             DD ?
    fStepCaptureAt2x          DD ?
    wStepCaptureAverageFrames DD ?
    dwAudioBufferSize         DD ?
    fDisableWriteCache        DD ?
    AVStreamMaster            DD ?
CAPTUREPARMS ENDS

CAPINFOCHUNK STRUCT ALIGNMODE
    fccInfoID DD   ?
    lpData    XPTR ?
    cbData    DD   ?
CAPINFOCHUNK ENDS


;======================================== Functions =======================================;
AVIBuildFilterA PROTO :XPTR, :XWORD, :XWORD
AVIBuildFilterW PROTO :XPTR, :XWORD, :XWORD
AVIClearClipboard PROTO
AVIFileAddRef PROTO :XPTR
AVIFileCreateStreamA PROTO :XPTR, :XPTR, :XPTR
AVIFileCreateStreamW PROTO :XPTR, :XPTR, :XPTR
AVIFileEndRecord PROTO :XPTR
AVIFileExit PROTO
AVIFileGetStream PROTO :XPTR, :XPTR, :XWORD, :XWORD
AVIFileInfoA PROTO :XPTR, :XPTR, :XWORD
AVIFileInfoW PROTO :XPTR, :XPTR, :XWORD
AVIFileInit PROTO
AVIFileOpenA PROTO :XPTR, :XPTR, :XWORD, :XPTR
AVIFileOpenW PROTO :XPTR, :XPTR, :XWORD, :XPTR
AVIFileReadData PROTO :XWORD, :XWORD, :XWORD, :XWORD
AVIFileRelease PROTO :XWORD
AVIFileWriteData PROTO :XWORD, :XWORD, :XWORD, :XWORD
AVIGetFromClipboard PROTO :XWORD
AVIMakeCompressedStream PROTO :XWORD, :XWORD, :XWORD, :XWORD
AVIMakeFileFromStreams PROTO :XWORD, :XWORD, :XWORD
AVIMakeStreamFromClipboard PROTO :XWORD, :XWORD, :XWORD
AVIPutFileOnClipboard PROTO :XWORD
AVISaveA PROTO :XPTR, :XPTR, :XPTR, :XWORD, :XPTR, :XPTR
AVISaveOptions PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
AVISaveOptionsFree PROTO :XWORD, :XWORD
AVISaveVA PROTO :XPTR, :XPTR, :XPTR, :XWORD, :XPTR, :XPTR
AVISaveVW PROTO :XPTR, :XPTR, :XPTR, :XWORD, :XPTR, :XPTR
AVISaveW PROTO :XPTR, :XPTR, :XPTR, :XWORD, :XPTR, :XPTR
AVIStreamAddRef PROTO :XWORD
AVIStreamBeginStreaming PROTO :XWORD, :XWORD, :XWORD, :XWORD
AVIStreamCreate PROTO :XWORD, :XWORD, :XWORD, :XWORD
AVIStreamEndStreaming PROTO :XWORD
AVIStreamGetFrame PROTO :XWORD, :XWORD
AVIStreamGetFrameClose PROTO :XWORD
AVIStreamGetFrameOpen PROTO :XWORD, :XWORD
AVIStreamFindSample PROTO :XWORD, :XWORD, :XWORD
AVIStreamInfoA PROTO :XPTR, :XPTR, :XWORD
AVIStreamInfoW PROTO :XPTR, :XPTR, :XWORD
AVIStreamLength PROTO :XWORD
AVIStreamOpenFromFileA PROTO :XPTR, :XPTR, :XWORD, :XWORD, :XWORD, :XPTR
AVIStreamOpenFromFileW PROTO :XPTR, :XPTR, :XWORD, :XWORD, :XWORD, :XPTR
AVIStreamRead PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
AVIStreamReadData PROTO :XWORD,:XWORD,:XWORD,:XWORD
AVIStreamReadFormat PROTO :XWORD,:XWORD,:XWORD,:XWORD
AVIStreamRelease PROTO :XWORD
AVIStreamSampleToTime PROTO :XWORD,:XWORD
AVIStreamSetFormat PROTO :XWORD,:XWORD,:XWORD,:XWORD
EditStreamSetInfoA PROTO :XPTR, :XPTR, :XWORD
EditStreamSetInfoW PROTO :XPTR, :XPTR, :XWORD
EditStreamSetNameA PROTO :XPTR, :XPTR
EditStreamSetNameW PROTO :XPTR, :XPTR
AVIStreamStart PROTO :XWORD
AVIStreamTimeToSample PROTO :XWORD,:XWORD
AVIStreamWrite PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
AVIStreamWriteData PROTO :XWORD,:XWORD,:XWORD,:XWORD
CreateEditableStream PROTO :XWORD, :XWORD
DrawDibBegin PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
DrawDibChangePalette PROTO :XWORD, :XWORD, :XWORD, :XWORD
DrawDibClose PROTO :XWORD
DrawDibDraw PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
DrawDibEnd PROTO :XWORD
DrawDibGetBuffer PROTO :XWORD, :XWORD, :XWORD, :XWORD
DrawDibGetPalette PROTO :XWORD
DrawDibOpen PROTO
DrawDibProfileDisplay PROTO :XWORD
DrawDibRealize PROTO :XWORD, :XWORD, :XWORD
DrawDibSetPalette PROTO :XWORD, :XWORD
DrawDibStart PROTO :XWORD, :XWORD
DrawDibStop PROTO :XWORD
DrawDibTime PROTO :XWORD, :XWORD
EditStreamClone PROTO :XWORD, :XWORD
EditStreamCopy PROTO :XWORD, :XWORD, :XWORD, :XWORD
EditStreamCut PROTO :XWORD, :XWORD, :XWORD, :XWORD
EditStreamPaste PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
GetOpenFileNamePreviewA PROTO :XPTR
GetOpenFileNamePreviewW PROTO :XPTR
GetSaveFileNamePreviewA PROTO :XPTR
GetSaveFileNamePreviewW PROTO :XPTR
ICClose PROTO :XWORD
ICCompress PROTO :VARARG
ICCompressorChoose PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
ICCompressorFree PROTO :XWORD
ICDecompress PROTO :VARARG
ICDraw PROTO :VARARG
ICDrawBegin PROTO :VARARG
ICGetDisplayFormat PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
ICGetInfo PROTO :XWORD, :XWORD, :XWORD
ICImageCompress PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
ICImageDecompress PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
ICInfo PROTO :XWORD, :XWORD, :XWORD
ICInstall PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
ICLocate PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
ICMThunk32 PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
ICOpen PROTO :XWORD, :XWORD, :XWORD
ICOpenFunction PROTO :XWORD, :XWORD, :XWORD, :XWORD
ICRemove PROTO :XWORD, :XWORD, :XWORD
ICSendMessage PROTO :XWORD, :XWORD, :XWORD, :XWORD
ICSeqCompressFrame PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
ICSeqCompressFrameEnd PROTO :XWORD
ICSeqCompressFrameStart PROTO :XWORD, :XWORD
IID_IAVIEditStream PROTO :VARARG
IID_IAVIFile PROTO :VARARG
IID_IAVIStream PROTO :VARARG
IID_IGetFrame PROTO :VARARG
MCIWndCreateA PROTO :XWORD, :XWORD, :XWORD, :XPTR
MCIWndCreateW PROTO :XWORD, :XWORD, :XWORD, :XPTR
MCIWndRegisterClass PROTO :VARARG
StretchDIB PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
VideoForWindowsVersion PROTO

AVIFileClose EQU <AVIFileRelease>
AVIStreamClose EQU <AVIStreamRelease>
AVIStreamExit EQU <AVIFileExit>
AVIStreamFindKeyFrame EQU <AVIStreamFindSample>
AVIStreamInit EQU <AVIFileInit>

IFDEF APP_UNICODE
    MCIWndCreate EQU <MCIWndCreateW>
    AVIFileOpen EQU <AVIFileOpenW>
    AVIFileInfo EQU <AVIFileInfoW>
    AVIFileCreateStream EQU <AVIFileCreateStreamW>
    AVIStreamInfo EQU <AVIStreamInfoW>
    AVIStreamOpenFromFile EQU <AVIStreamOpenFromFileW>
    AVISave EQU <AVISaveW>
    AVISaveV EQU <AVISaveVW>
    AVIBuildFilter EQU <AVIBuildFilterW>
    EditStreamSetInfo EQU <EditStreamSetInfoW>
    EditStreamSetName EQU <EditStreamSetNameW>
    GetOpenFileNamePreview EQU <GetOpenFileNamePreviewW>
    GetSaveFileNamePreview EQU <GetSaveFileNamePreviewW>
ELSE
    MCIWndCreate EQU <MCIWndCreateA>
    AVIFileOpen EQU <AVIFileOpenA>
    AVIFileInfo EQU <AVIFileInfoA>
    AVIFileCreateStream EQU <AVIFileCreateStreamA>
    AVIStreamInfo EQU <AVIStreamInfoA>
    AVIStreamOpenFromFile EQU <AVIStreamOpenFromFileA>
    AVISave EQU <AVISaveA>
    AVISaveV EQU <AVISaveVA>
    AVIBuildFilter EQU <AVIBuildFilterA>
    EditStreamSetInfo EQU <EditStreamSetInfoA>
    EditStreamSetName EQU <EditStreamSetNameA>
    GetOpenFileNamePreview EQU <GetOpenFileNamePreviewA>
    GetSaveFileNamePreview EQU <GetSaveFileNamePreviewA>
ENDIF

ENDIF ;VFW32_INC
