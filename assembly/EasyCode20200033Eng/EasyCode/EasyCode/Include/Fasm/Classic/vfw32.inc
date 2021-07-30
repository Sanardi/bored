;====================================================;
;                                                    ;
;     vfw32.inc for EC v2 Fasm classic projects      ;
;                  (version 1.0.1)                   ;
;                                                    ;
;         Copyright © Ramon Sala - 2018-2020         ;
;                                                    ;
;====================================================;

if ~defined VFW32_INC
define VFW32_INC 1

if ~defined GDI32_INC
    include 'gdi32.inc'
end if

if ~defined WINMM_INC
    include 'winmm.inc'
end if

BI_1632                                         equ     032333631H

if ~defined ICTYPE_VIDEO
    ICTYPE_VIDEO                                equ    "cdiv"
    ICTYPE_AUDIO                                equ    "cdua"
end if

if ~defined ICERR_OK
    ICERR_OK                                    equ     0
    ICERR_DONTDRAW                              equ     1
    ICERR_NEWPALETTE                            equ     2
    ICERR_GOTOKEYFRAME                          equ     3
    ICERR_STOPDRAWING                           equ     4
    ICERR_UNSUPPORTED                           equ     (-1)
    ICERR_BADFORMAT                             equ     (-2)
    ICERR_MEMORY                                equ     (-3)
    ICERR_INTERNAL                              equ     (-4)
    ICERR_BADFLAGS                              equ     (-5)
    ICERR_BADPARAM                              equ     (-6)
    ICERR_BADSIZE                               equ     (-7)
    ICERR_BADHANDLE                             equ     (-8)
    ICERR_CANTUPDATE                            equ     (-9)
    ICERR_ABORT                                 equ     (-10)
    ICERR_ERROR                                 equ     (-100)
    ICERR_BADBITDEPTH                           equ     (-200)
    ICERR_BADIMAGESIZE                          equ     (-201)
    ICERR_CUSTOM                                equ     (-400)
end if

if ~defined ICMODE_COMPRESS
    ICMODE_COMPRESS                             equ     1
    ICMODE_DECOMPRESS                           equ     2
    ICMODE_FASTDECOMPRESS                       equ     3
    ICMODE_QUERY                                equ     4
    ICMODE_FASTCOMPRESS                         equ     5
    ICMODE_DRAW                                 equ     8
end if

AVIIF_LIST                                      equ     00000001H
AVIIF_TWOCC                                     equ     00000002H
AVIIF_KEYFRAME                                  equ     00000010H
AVIIF_FIRSTPART                                 equ     00000020H
AVIIF_LASTPART                                  equ     00000040H
AVIIF_MIDPART                                   equ     (AVIIF_LASTPART OR AVIIF_FIRSTPART)
AVIIF_NOTIME                                    equ     00000100H
AVIIF_COMPUSE                                   equ     0FFF0000H

ICQUALITY_LOW                                   equ     0
ICQUALITY_HIGH                                  equ     10000
ICQUALITY_DEFAULT                               equ     (-1)

ICM_USER                                        equ     (DRV_USER + 0000H)

ICM_RESERVED                                    equ     ICM_RESERVED_LOW
ICM_RESERVED_LOW                                equ     (DRV_USER + 01000H)
ICM_RESERVED_HIGH                               equ     (DRV_USER + 02000H)

ICM_GETSTATE                                    equ     (ICM_RESERVED + 0)
ICM_SETSTATE                                    equ     (ICM_RESERVED + 1)
ICM_GETINFO                                     equ     (ICM_RESERVED + 2)
ICM_CONFIGURE                                   equ     (ICM_RESERVED + 10)
ICM_ABOUT                                       equ     (ICM_RESERVED + 11)
ICM_GETERRORTEXT                                equ     (ICM_RESERVED + 12)
ICM_GETFORMATNAME                               equ     (ICM_RESERVED + 20)
ICM_ENUMFORMATS                                 equ     (ICM_RESERVED + 21)
ICM_GETDEFAULTQUALITY                           equ     (ICM_RESERVED + 30)
ICM_GETQUALITY                                  equ     (ICM_RESERVED + 31)
ICM_SETQUALITY                                  equ     (ICM_RESERVED + 32)
ICM_SET                                         equ     (ICM_RESERVED + 40)
ICM_GET                                         equ     (ICM_RESERVED + 41)

ICM_FRAMERATE                                   equ     "RmrF"
ICM_KEYFRAMERATE                                equ     "RyeK"

ICM_COMPRESS_GET_FORMAT                         equ     (ICM_USER + 4)
ICM_COMPRESS_GET_SIZE                           equ     (ICM_USER + 5)
ICM_COMPRESS_QUERY                              equ     (ICM_USER + 6)
ICM_COMPRESS_BEGIN                              equ     (ICM_USER + 7)
ICM_COMPRESS                                    equ     (ICM_USER + 8)
ICM_COMPRESS_END                                equ     (ICM_USER + 9)
ICM_DECOMPRESS_GET_FORMAT                       equ     (ICM_USER + 10)
ICM_DECOMPRESS_QUERY                            equ     (ICM_USER + 11)
ICM_DECOMPRESS_BEGIN                            equ     (ICM_USER + 12)
ICM_DECOMPRESS                                  equ     (ICM_USER + 13)
ICM_DECOMPRESS_END                              equ     (ICM_USER + 14)
ICM_DECOMPRESS_SET_PALETTE                      equ     (ICM_USER + 29)
ICM_DECOMPRESS_GET_PALETTE                      equ     (ICM_USER + 30)
ICM_DRAW_QUERY                                  equ     (ICM_USER + 31)
ICM_DRAW_BEGIN                                  equ     (ICM_USER + 15)
ICM_DRAW_GET_PALETTE                            equ     (ICM_USER + 16)
ICM_DRAW_UPDATE                                 equ     (ICM_USER + 17)
ICM_DRAW_START                                  equ     (ICM_USER + 18)
ICM_DRAW_STOP                                   equ     (ICM_USER + 19)
ICM_DRAW_BITS                                   equ     (ICM_USER + 20)
ICM_DRAW_END                                    equ     (ICM_USER + 21)
ICM_DRAW_GETTIME                                equ     (ICM_USER + 32)
ICM_DRAW                                        equ     (ICM_USER + 33)
ICM_DRAW_WINDOW                                 equ     (ICM_USER + 34)
ICM_DRAW_SETTIME                                equ     (ICM_USER + 35)
ICM_DRAW_REALIZE                                equ     (ICM_USER + 36)
ICM_DRAW_FLUSH                                  equ     (ICM_USER + 37)
ICM_DRAW_RENDERBUFFER                           equ     (ICM_USER + 38)
ICM_DRAW_START_PLAY                             equ     (ICM_USER + 39)
ICM_DRAW_STOP_PLAY                              equ     (ICM_USER + 40)
ICM_DRAW_SUGGESTFORMAT                          equ     (ICM_USER + 50)
ICM_DRAW_CHANGEPALETTE                          equ     (ICM_USER + 51)
ICM_DRAW_IDLE                                   equ     (ICM_USER + 52)
ICM_GETBUFFERSWANTED                            equ     (ICM_USER + 41)
ICM_GETDEFAULTKEYFRAMERATE                      equ     (ICM_USER + 42)
ICM_DECOMPRESSEX_BEGIN                          equ     (ICM_USER + 60)
ICM_DECOMPRESSEX_QUERY                          equ     (ICM_USER + 61)
ICM_DECOMPRESSEX                                equ     (ICM_USER + 62)
ICM_DECOMPRESSEX_END                            equ     (ICM_USER + 63)
ICM_COMPRESS_FRAMES_INFO                        equ     (ICM_USER + 70)
ICM_COMPRESS_FRAMES                             equ     (ICM_USER + 71)
ICM_SET_STATUS_PROC                             equ     (ICM_USER + 72)

VIDCF_QUALITY                                   equ     0001H
VIDCF_CRUNCH                                    equ     0002H
VIDCF_TEMPORAL                                  equ     0004H
VIDCF_COMPRESSFRAMES                            equ     0008H
VIDCF_DRAW                                      equ     0010H
VIDCF_FASTTEMPORALC                             equ     0020H
VIDCF_FASTTEMPORALD                             equ     0080H

ICCOMPRESS_KEYFRAME                             equ     00000001H

ICCOMPRESSFRAMES_PADDING                        equ     00000001H

ICSTATUS_START                                  equ     0
ICSTATUS_STATUS                                 equ     1
ICSTATUS_END                                    equ     2
ICSTATUS_ERROR                                  equ     3
ICSTATUS_YIELD                                  equ     4

ICDECOMPRESS_HURRYUP                            equ     80000000H
ICDECOMPRESS_UPDATE                             equ     40000000H
ICDECOMPRESS_PREROLL                            equ     20000000H
ICDECOMPRESS_NULLFRAME                          equ     10000000H
ICDECOMPRESS_NOTKEYFRAME                        equ     08000000H

ICDRAW_QUERY                                    equ     00000001H
ICDRAW_FULLSCREEN                               equ     00000002H
ICDRAW_HDC                                      equ     00000004H
ICDRAW_ANIMATE                                  equ     00000008H
ICDRAW_CONTINUE                                 equ     00000010H
ICDRAW_MEMORYDC                                 equ     00000020H
ICDRAW_UPDATING                                 equ     00000040H
ICDRAW_RENDER                                   equ     00000080H
ICDRAW_BUFFER                                   equ     00000100H

ICDRAW_HURRYUP                                  equ     80000000H
ICDRAW_UPDATE                                   equ     40000000H
ICDRAW_PREROLL                                  equ     20000000H
ICDRAW_NULLFRAME                                equ     10000000H
ICDRAW_NOTKEYFRAME                              equ     08000000H

ICINSTALL_UNICODE                               equ     8000H
ICINSTALL_FUNCTION                              equ     0001H
ICINSTALL_DRIVER                                equ     0002H
ICINSTALL_HDRV                                  equ     0004H
ICINSTALL_DRIVERW                               equ     8002H

ICMF_CONFIGURE_QUERY                            equ     00000001H
ICMF_ABOUT_QUERY                                equ     00000001H

ICDECOMPRESS_HURRYUP                            equ     80000000H

ICMF_COMPVARS_VALID                             equ     00000001H

ICMF_CHOOSE_KEYFRAME                            equ     0001H
ICMF_CHOOSE_DATARATE                            equ     0002H
ICMF_CHOOSE_PREVIEW                             equ     0004H
ICMF_CHOOSE_ALLCOMPRESSORS                      equ     0008H

DDF_0001                                        equ     0001H
DDF_UPDATE                                      equ     0002H
DDF_SAME_HDC                                    equ     0004H
DDF_SAME_DRAW                                   equ     0008H
DDF_DONTDRAW                                    equ     0010H
DDF_ANIMATE                                     equ     0020H
DDF_BUFFER                                      equ     0040H
DDF_JUSTDRAWIT                                  equ     0080H
DDF_FULLSCREEN                                  equ     0100H
DDF_BACKGROUNDPAL                               equ     0200H
DDF_NOTKEYFRAME                                 equ     0400H
DDF_HURRYUP                                     equ     0800H
DDF_HALFTONE                                    equ     1000H
DDF_2000                                        equ     2000H

DDF_PREROLL                                     equ     DDF_DONTDRAW
DDF_SAME_DIB                                    equ     DDF_SAME_DRAW
DDF_SAME_SIZE                                   equ     DDF_SAME_DRAW

PD_CAN_DRAW_DIB                                 equ     0001H
PD_CAN_STRETCHDIB                               equ     0002H
PD_STRETCHDIB_1_1_OK                            equ     0004H
PD_STRETCHDIB_1_2_OK                            equ     0008H
PD_STRETCHDIB_1_N_OK                            equ     0010H

formtypeAVI                                     equ     " IVA"
listtypeAVIHEADER                               equ     "lrdh"
ckidAVIMAINHDR                                  equ     "hiva"
listtypeSTREAMHEADER                            equ     "lrts"
ckidSTREAMHEADER                                equ     "hrts"
ckidSTREAMFORMAT                                equ     "frts"
ckidSTREAMHANDLERDATA                           equ     "drts"
ckidSTREAMNAME                                  equ     "nrts"

listtypeAVIMOVIE                                equ     "ivom"
listtypeAVIRECORD                               equ     " cer"

ckidAVINEWINDEX                                 equ     "1xdi"

streamtypeVIDEO                                 equ     "sdiv"
streamtypeAUDIO                                 equ     "sdua"
streamtypeMIDI                                  equ     "sdim"
streamtypeTEXT                                  equ     "stxt"

cktypeDIBbits                                   equ     "bd"
cktypeDIBcompressed                             equ     "cd"
cktypePALchange                                 equ     "cp"
cktypeWAVEbytes                                 equ     "bw"

ckidAVIPADDING                                  equ     "KNUJ"

AVIF_HASINDEX                                   equ     00000010H
AVIF_MUSTUSEINDEX                               equ     00000020H
AVIF_ISINTERLEAVED                              equ     00000100H
AVIF_WASCAPTUREFILE                             equ     00010000H
AVIF_COPYRIGHTED                                equ     00020000H

AVI_HEADERSIZE                                  equ     2048

AVISF_DISABLED                                  equ     00000001H
AVISF_VIDEO_PALCHANGES                          equ     00010000H

AVIGETFRAMEF_BESTDISPLAYFMT                     equ     1

AVISTREAMINFO_DISABLED                          equ     00000001H
AVISTREAMINFO_FORMATCHANGES                     equ     00010000H

AVIFILEINFO_HASINDEX                            equ     00000010H
AVIFILEINFO_MUSTUSEINDEX                        equ     00000020H
AVIFILEINFO_ISINTERLEAVED                       equ     00000100H
AVIFILEINFO_WASCAPTUREFILE                      equ     00010000H
AVIFILEINFO_COPYRIGHTED                         equ     00020000H

AVIFILECAPS_CANREAD                             equ     00000001H
AVIFILECAPS_CANWRITE                            equ     00000002H
AVIFILECAPS_ALLKEYFRAMES                        equ     00000010H
AVIFILECAPS_NOCOMPRESSION                       equ     00000020H

AVICOMPRESSF_INTERLEAVE                         equ     00000001H
AVICOMPRESSF_DATARATE                           equ     00000002H
AVICOMPRESSF_KEYFRAMES                          equ     00000004H
AVICOMPRESSF_VALID                              equ     00000008H

AVIFILEHANDLER_CANREAD                          equ     0001H
AVIFILEHANDLER_CANWRITE                         equ     0002H
AVIFILEHANDLER_CANACCEPTNONRGB                  equ     0004H

AVISTREAMREAD_CONVENIENT                        equ     (-1)

FIND_DIR                                        equ     0000000FH
FIND_NEXT                                       equ     00000001H
FIND_PREV                                       equ     00000004H
FIND_FROM_START                                 equ     00000008H

FIND_TYPE                                       equ     000000F0H
FIND_KEY                                        equ     00000010H
FIND_ANY                                        equ     00000020H
FIND_FORMAT                                     equ     00000040H

FIND_RET                                        equ     0000F000H
FIND_POS                                        equ     00000000H
FIND_LENGTH                                     equ     00001000H
FIND_OFFSET                                     equ     00002000H
FIND_SIZE                                       equ     00003000H
FIND_INDEX                                      equ     00004000H

SEARCH_NEAREST                                  equ     FIND_PREV
SEARCH_BACKWARD                                 equ     FIND_PREV
SEARCH_FORWARD                                  equ     FIND_NEXT
SEARCH_KEY                                      equ     FIND_KEY
SEARCH_ANY                                      equ     FIND_ANY

if ~defined AVIERR_OK
    AVIERR_OK                                   equ     0
    AVIERR_UNSUPPORTED                          equ     (1 SHL 31) OR (4 SHL 16) OR (101)
    AVIERR_BADFORMAT                            equ     (1 SHL 31) OR (4 SHL 16) OR (102)
    AVIERR_MEMORY                               equ     (1 SHL 31) OR (4 SHL 16) OR (103)
    AVIERR_INTERNAL                             equ     (1 SHL 31) OR (4 SHL 16) OR (104)
    AVIERR_BADFLAGS                             equ     (1 SHL 31) OR (4 SHL 16) OR (105)
    AVIERR_BADPARAM                             equ     (1 SHL 31) OR (4 SHL 16) OR (106)
    AVIERR_BADSIZE                              equ     (1 SHL 31) OR (4 SHL 16) OR (107)
    AVIERR_BADHANDLE                            equ     (1 SHL 31) OR (4 SHL 16) OR (108)
    AVIERR_FILEREAD                             equ     (1 SHL 31) OR (4 SHL 16) OR (109)
    AVIERR_FILEWRITE                            equ     (1 SHL 31) OR (4 SHL 16) OR (110)
    AVIERR_FILEOPEN                             equ     (1 SHL 31) OR (4 SHL 16) OR (111)
    AVIERR_COMPRESSOR                           equ     (1 SHL 31) OR (4 SHL 16) OR (112)
    AVIERR_NOCOMPRESSOR                         equ     (1 SHL 31) OR (4 SHL 16) OR (113)
    AVIERR_READONLY                             equ     (1 SHL 31) OR (4 SHL 16) OR (114)
    AVIERR_NODATA                               equ     (1 SHL 31) OR (4 SHL 16) OR (115)
    AVIERR_BUFFERTOOSMALL                       equ     (1 SHL 31) OR (4 SHL 16) OR (116)
    AVIERR_CANTCOMPRESS                         equ     (1 SHL 31) OR (4 SHL 16) OR (117)
    AVIERR_USERABORT                            equ     (1 SHL 31) OR (4 SHL 16) OR (198)
    AVIERR_ERROR                                equ     (1 SHL 31) OR (4 SHL 16) OR (199)
end if

if ~defined comptypeDIB
    comptypeDIB                                 equ     " BID"
end if

MCIWNDOPENF_NEW                                 equ     0001H

MCIWNDF_NOAUTOSIZEWINDOW                        equ     0001H
MCIWNDF_NOPLAYBAR                               equ     0002H
MCIWNDF_NOAUTOSIZEMOVIE                         equ     0004H
MCIWNDF_NOMENU                                  equ     0008H
MCIWNDF_SHOWNAME                                equ     0010H
MCIWNDF_SHOWPOS                                 equ     0020H
MCIWNDF_SHOWMODE                                equ     0040H
MCIWNDF_SHOWALL                                 equ     0070H
MCIWNDF_NOTIFYMODE                              equ     0100H
MCIWNDF_NOTIFYPOS                               equ     0200H
MCIWNDF_NOTIFYSIZE                              equ     0400H
MCIWNDF_NOTIFYERROR                             equ     1000H
MCIWNDF_NOTIFYALL                               equ     1F00H
MCIWNDF_NOTIFYANSI                              equ     0080H
MCIWNDF_NOTIFYMEDIAA                            equ     0880H
MCIWNDF_NOTIFYMEDIAW                            equ     0800H
MCIWNDF_RECORD                                  equ     2000H
MCIWNDF_NOERRORDLG                              equ     4000H
MCIWNDF_NOOPEN                                  equ     8000H

MCIWNDM_GETDEVICEID                             equ     (WM_USER + 100)
MCIWNDM_GETSTART                                equ     (WM_USER + 103)
MCIWNDM_GETLENGTH                               equ     (WM_USER + 104)
MCIWNDM_GETEND                                  equ     (WM_USER + 105)
MCIWNDM_EJECT                                   equ     (WM_USER + 107)
MCIWNDM_SETZOOM                                 equ     (WM_USER + 108)
MCIWNDM_GETZOOM                                 equ     (WM_USER + 109)
MCIWNDM_SETVOLUME                               equ     (WM_USER + 110)
MCIWNDM_GETVOLUME                               equ     (WM_USER + 111)
MCIWNDM_SETSPEED                                equ     (WM_USER + 112)
MCIWNDM_GETSPEED                                equ     (WM_USER + 113)
MCIWNDM_SETREPEAT                               equ     (WM_USER + 114)
MCIWNDM_GETREPEAT                               equ     (WM_USER + 115)
MCIWNDM_REALIZE                                 equ     (WM_USER + 118)
MCIWNDM_VALIDATEMEDIA                           equ     (WM_USER + 121)
MCIWNDM_PLAYFROM                                equ     (WM_USER + 122)
MCIWNDM_PLAYTO                                  equ     (WM_USER + 123)
MCIWNDM_GETPALETTE                              equ     (WM_USER + 126)
MCIWNDM_SETPALETTE                              equ     (WM_USER + 127)
MCIWNDM_SETTIMERS                               equ     (WM_USER + 129)
MCIWNDM_SETACTIVETIMER                          equ     (WM_USER + 130)
MCIWNDM_SETINACTIVETIMER                        equ     (WM_USER + 131)
MCIWNDM_GETACTIVETIMER                          equ     (WM_USER + 132)
MCIWNDM_GETINACTIVETIMER                        equ     (WM_USER + 133)
MCIWNDM_CHANGESTYLES                            equ     (WM_USER + 135)
MCIWNDM_GETSTYLES                               equ     (WM_USER + 136)
MCIWNDM_GETALIAS                                equ     (WM_USER + 137)
MCIWNDM_PLAYREVERSE                             equ     (WM_USER + 139)
MCIWNDM_GET_SOURCE                              equ     (WM_USER + 140)
MCIWNDM_PUT_SOURCE                              equ     (WM_USER + 141)
MCIWNDM_GET_DEST                                equ     (WM_USER + 142)
MCIWNDM_PUT_DEST                                equ     (WM_USER + 143)
MCIWNDM_CAN_PLAY                                equ     (WM_USER + 144)
MCIWNDM_CAN_WINDOW                              equ     (WM_USER + 145)
MCIWNDM_CAN_RECORD                              equ     (WM_USER + 146)
MCIWNDM_CAN_SAVE                                equ     (WM_USER + 147)
MCIWNDM_CAN_EJECT                               equ     (WM_USER + 148)
MCIWNDM_CAN_CONFIG                              equ     (WM_USER + 149)
MCIWNDM_PALETTEKICK                             equ     (WM_USER + 150)
MCIWNDM_OPENINTERFACE                           equ     (WM_USER + 151)
MCIWNDM_SETOWNER                                equ     (WM_USER + 152)

MCIWNDM_SENDSTRINGA                             equ     (WM_USER + 101)
MCIWNDM_GETPOSITIONA                            equ     (WM_USER + 102)
MCIWNDM_GETMODEA                                equ     (WM_USER + 106)
MCIWNDM_SETTIMEFORMATA                          equ     (WM_USER + 119)
MCIWNDM_GETTIMEFORMATA                          equ     (WM_USER + 120)
MCIWNDM_GETFILENAMEA                            equ     (WM_USER + 124)
MCIWNDM_GETDEVICEA                              equ     (WM_USER + 125)
MCIWNDM_GETERRORA                               equ     (WM_USER + 128)
MCIWNDM_NEWA                                    equ     (WM_USER + 134)
MCIWNDM_RETURNSTRINGA                           equ     (WM_USER + 138)
MCIWNDM_OPENA                                   equ     (WM_USER + 153)

MCIWNDM_SENDSTRINGW                             equ     (WM_USER + 201)
MCIWNDM_GETPOSITIONW                            equ     (WM_USER + 202)
MCIWNDM_GETMODEW                                equ     (WM_USER + 206)
MCIWNDM_SETTIMEFORMATW                          equ     (WM_USER + 219)
MCIWNDM_GETTIMEFORMATW                          equ     (WM_USER + 220)
MCIWNDM_GETFILENAMEW                            equ     (WM_USER + 224)
MCIWNDM_GETDEVICEW                              equ     (WM_USER + 225)
MCIWNDM_GETERRORW                               equ     (WM_USER + 228)
MCIWNDM_NEWW                                    equ     (WM_USER + 234)
MCIWNDM_RETURNSTRINGW                           equ     (WM_USER + 238)
MCIWNDM_OPENW                                   equ     (WM_USER + 252)

MCIWNDM_NOTIFYMODE                              equ     (WM_USER + 200)
MCIWNDM_NOTIFYPOS                               equ     (WM_USER + 201)
MCIWNDM_NOTIFYSIZE                              equ     (WM_USER + 202)
MCIWNDM_NOTIFYMEDIA                             equ     (WM_USER + 203)
MCIWNDM_NOTIFYERROR                             equ     (WM_USER + 205)

MCIWND_START                                    equ     (-1)
MCIWND_END                                      equ     (-2)

if ~defined MCI_PLAY
    MCI_CLOSE                                   equ     0804H
    MCI_PLAY                                    equ     0806H
    MCI_SEEK                                    equ     0807H
    MCI_STOP                                    equ     0808H
    MCI_PAUSE                                   equ     0809H
    MCI_STEP                                    equ     080EH
    MCI_RECORD                                  equ     080FH
    MCI_SAVE                                    equ     0813H
    MCI_CUT                                     equ     0851H
    MCI_COPY                                    equ     0852H
    MCI_PASTE                                   equ     0853H
    MCI_RESUME                                  equ     0855H
    MCI_DELETE                                  equ     0856H
end if

if ~defined MCI_MODE_NOT_READY
    MCI_MODE_NOT_READY                          equ     524
    MCI_MODE_STOP                               equ     525
    MCI_MODE_PLAY                               equ     526
    MCI_MODE_RECORD                             equ     527
    MCI_MODE_SEEK                               equ     528
    MCI_MODE_PAUSE                              equ     529
    MCI_MODE_OPEN                               equ     530
end if

DV_ERR_OK                                       equ     0
DV_ERR_BASE                                     equ     1
DV_ERR_NONSPECIFIC                              equ     (DV_ERR_BASE)
DV_ERR_BADFORMAT                                equ     (DV_ERR_BASE + 1)
DV_ERR_STILLPLAYING                             equ     (DV_ERR_BASE + 2)
DV_ERR_UNPREPARED                               equ     (DV_ERR_BASE + 3)
DV_ERR_SYNC                                     equ     (DV_ERR_BASE + 4)
DV_ERR_TOOMANYCHANNELS                          equ     (DV_ERR_BASE + 5)
DV_ERR_NOTDETECTED                              equ     (DV_ERR_BASE + 6)
DV_ERR_BADINSTALL                               equ     (DV_ERR_BASE + 7)
DV_ERR_CREATEPALETTE                            equ     (DV_ERR_BASE + 8)
DV_ERR_SIZEFIELD                                equ     (DV_ERR_BASE + 9)
DV_ERR_PARAM1                                   equ     (DV_ERR_BASE + 10)
DV_ERR_PARAM2                                   equ     (DV_ERR_BASE + 11)
DV_ERR_CONFIG1                                  equ     (DV_ERR_BASE + 12)
DV_ERR_CONFIG2                                  equ     (DV_ERR_BASE + 13)
DV_ERR_FLAGS                                    equ     (DV_ERR_BASE + 14)
DV_ERR_13                                       equ     (DV_ERR_BASE + 15)
DV_ERR_NOTSUPPORTED                             equ     (DV_ERR_BASE + 16)
DV_ERR_NOMEM                                    equ     (DV_ERR_BASE + 17)
DV_ERR_ALLOCATED                                equ     (DV_ERR_BASE + 18)
DV_ERR_BADDEVICEID                              equ     (DV_ERR_BASE + 19)
DV_ERR_INVALHANDLE                              equ     (DV_ERR_BASE + 20)
DV_ERR_BADERRNUM                                equ     (DV_ERR_BASE + 21)
DV_ERR_NO_BUFFERS                               equ     (DV_ERR_BASE + 22)
DV_ERR_MEM_CONFLICT                             equ     (DV_ERR_BASE + 23)
DV_ERR_IO_CONFLICT                              equ     (DV_ERR_BASE + 24)
DV_ERR_DMA_CONFLICT                             equ     (DV_ERR_BASE + 25)
DV_ERR_INT_CONFLICT                             equ     (DV_ERR_BASE + 26)
DV_ERR_PROTECT_ONLY                             equ     (DV_ERR_BASE + 27)
DV_ERR_LASTERROR                                equ     (DV_ERR_BASE + 27)
DV_ERR_USER_MSG                                 equ     (DV_ERR_BASE + 1000)

if ~defined MM_DRVM_OPEN
    MM_DRVM_OPEN                                equ     3D0H
    MM_DRVM_CLOSE                               equ     3D1H
    MM_DRVM_DATA                                equ     3D2H
    MM_DRVM_ERROR                               equ     3D3H
end if

DV_VM_OPEN                                      equ     MM_DRVM_OPEN
DV_VM_CLOSE                                     equ     MM_DRVM_CLOSE
DV_VM_DATA                                      equ     MM_DRVM_DATA
DV_VM_ERROR                                     equ     MM_DRVM_ERROR

VHDR_DONE                                       equ     00000001H
VHDR_PREPARED                                   equ     00000002H
VHDR_INQUEUE                                    equ     00000004H
VHDR_KEYFRAME                                   equ     00000008H
VHDR_VALID                                      equ     0000000FH

VCAPS_OVERLAY                                   equ     00000001H
VCAPS_SRC_CAN_CLIP                              equ     00000002H
VCAPS_DST_CAN_CLIP                              equ     00000004H
VCAPS_CAN_SCALE                                 equ     00000008H

VIDEO_EXTERNALIN                                equ     0001H
VIDEO_EXTERNALOUT                               equ     0002H
VIDEO_IN                                        equ     0004H
VIDEO_OUT                                       equ     0008H

VIDEO_DLG_QUERY                                 equ     0010H

VIDEO_CONFIGURE_QUERY                           equ     8000H
VIDEO_CONFIGURE_SET                             equ     1000H
VIDEO_CONFIGURE_GET                             equ     2000H
VIDEO_CONFIGURE_QUERYSIZE                       equ     0001H
VIDEO_CONFIGURE_CURRENT                         equ     0010H
VIDEO_CONFIGURE_NOMINAL                         equ     0020H
VIDEO_CONFIGURE_MIN                             equ     0040H
VIDEO_CONFIGURE_MAX                             equ     0080H

DVM_USER                                        equ     4000H

DVM_CONFIGURE_START                             equ     1000H
DVM_CONFIGURE_END                               equ     1FFFH

DVM_PALETTE                                     equ     (DVM_CONFIGURE_START + 1)
DVM_FORMAT                                      equ     (DVM_CONFIGURE_START + 2)
DVM_PALETTERGB555                               equ     (DVM_CONFIGURE_START + 3)
DVM_SRC_RECT                                    equ     (DVM_CONFIGURE_START + 4)
DVM_DST_RECT                                    equ     (DVM_CONFIGURE_START + 5)

WM_CAP_START                                    equ     WM_USER
WM_CAP_UNICODE_START                            equ     (WM_USER + 100)
WM_CAP_GET_CAPSTREAMPTR                         equ     (WM_CAP_START + 1)
WM_CAP_SET_CALLBACK_ERRORW                      equ     (WM_CAP_UNICODE_START + 2)
WM_CAP_SET_CALLBACK_STATUSW                     equ     (WM_CAP_UNICODE_START + 3)
WM_CAP_SET_CALLBACK_ERRORA                      equ     (WM_CAP_START + 2)
WM_CAP_SET_CALLBACK_STATUSA                     equ     (WM_CAP_START + 3)
WM_CAP_SET_CALLBACK_YIELD                       equ     (WM_CAP_START + 4)
WM_CAP_SET_CALLBACK_FRAME                       equ     (WM_CAP_START + 5)
WM_CAP_SET_CALLBACK_VIDEOSTREAM                 equ     (WM_CAP_START + 6)
WM_CAP_SET_CALLBACK_WAVESTREAM                  equ     (WM_CAP_START + 7)
WM_CAP_GET_USER_DATA                            equ     (WM_CAP_START + 8)
WM_CAP_SET_USER_DATA                            equ     (WM_CAP_START + 9)
WM_CAP_DRIVER_CONNECT                           equ     (WM_CAP_START + 10)
WM_CAP_DRIVER_DISCONNECT                        equ     (WM_CAP_START + 11)
WM_CAP_DRIVER_GET_NAMEA                         equ     (WM_CAP_START + 12)
WM_CAP_DRIVER_GET_VERSIONA                      equ     (WM_CAP_START + 13)
WM_CAP_DRIVER_GET_NAMEW                         equ     (WM_CAP_UNICODE_START + 12)
WM_CAP_DRIVER_GET_VERSIONW                      equ     (WM_CAP_UNICODE_START + 13)
WM_CAP_DRIVER_GET_CAPS                          equ     (WM_CAP_START + 14)
WM_CAP_FILE_SET_CAPTURE_FILEA                   equ     (WM_CAP_START + 20)
WM_CAP_FILE_GET_CAPTURE_FILEA                   equ     (WM_CAP_START + 21)
WM_CAP_FILE_SAVEASA                             equ     (WM_CAP_START + 23)
WM_CAP_FILE_SAVEDIBA                            equ     (WM_CAP_START + 25)
WM_CAP_FILE_SET_CAPTURE_FILEW                   equ     (WM_CAP_UNICODE_START + 20)
WM_CAP_FILE_GET_CAPTURE_FILEW                   equ     (WM_CAP_UNICODE_START + 21)
WM_CAP_FILE_SAVEASW                             equ     (WM_CAP_UNICODE_START + 23)
WM_CAP_FILE_SAVEDIBW                            equ     (WM_CAP_UNICODE_START + 25)
WM_CAP_FILE_ALLOCATE                            equ     (WM_CAP_START + 22)
WM_CAP_FILE_SET_INFOCHUNK                       equ     (WM_CAP_START + 24)
WM_CAP_EDIT_COPY                                equ     (WM_CAP_START + 30)
WM_CAP_SET_AUDIOFORMAT                          equ     (WM_CAP_START + 35)
WM_CAP_GET_AUDIOFORMAT                          equ     (WM_CAP_START + 36)
WM_CAP_DLG_VIDEOFORMAT                          equ     (WM_CAP_START + 41)
WM_CAP_DLG_VIDEOSOURCE                          equ     (WM_CAP_START + 42)
WM_CAP_DLG_VIDEODISPLAY                         equ     (WM_CAP_START + 43)
WM_CAP_GET_VIDEOFORMAT                          equ     (WM_CAP_START + 44)
WM_CAP_SET_VIDEOFORMAT                          equ     (WM_CAP_START + 45)
WM_CAP_DLG_VIDEOCOMPRESSION                     equ     (WM_CAP_START + 46)
WM_CAP_SET_PREVIEW                              equ     (WM_CAP_START + 50)
WM_CAP_SET_OVERLAY                              equ     (WM_CAP_START + 51)
WM_CAP_SET_PREVIEWRATE                          equ     (WM_CAP_START + 52)
WM_CAP_SET_SCALE                                equ     (WM_CAP_START + 53)
WM_CAP_GET_STATUS                               equ     (WM_CAP_START + 54)
WM_CAP_SET_SCROLL                               equ     (WM_CAP_START + 55)
WM_CAP_GRAB_FRAME                               equ     (WM_CAP_START + 60)
WM_CAP_GRAB_FRAME_NOSTOP                        equ     (WM_CAP_START + 61)
WM_CAP_SEQUENCE                                 equ     (WM_CAP_START + 62)
WM_CAP_SEQUENCE_NOFILE                          equ     (WM_CAP_START + 63)
WM_CAP_SET_SEQUENCE_SETUP                       equ     (WM_CAP_START + 64)
WM_CAP_GET_SEQUENCE_SETUP                       equ     (WM_CAP_START + 65)
WM_CAP_SET_MCI_DEVICEA                          equ     (WM_CAP_START + 66)
WM_CAP_GET_MCI_DEVICEA                          equ     (WM_CAP_START + 67)
WM_CAP_SET_MCI_DEVICEW                          equ     (WM_CAP_UNICODE_START + 66)
WM_CAP_GET_MCI_DEVICEW                          equ     (WM_CAP_UNICODE_START + 67)
WM_CAP_STOP                                     equ     (WM_CAP_START + 68)
WM_CAP_ABORT                                    equ     (WM_CAP_START + 69)
WM_CAP_SINGLE_FRAME_OPEN                        equ     (WM_CAP_START + 70)
WM_CAP_SINGLE_FRAME_CLOSE                       equ     (WM_CAP_START + 71)
WM_CAP_SINGLE_FRAME                             equ     (WM_CAP_START + 72)
WM_CAP_PAL_OPENA                                equ     (WM_CAP_START + 80)
WM_CAP_PAL_SAVEA                                equ     (WM_CAP_START + 81)
WM_CAP_PAL_OPENW                                equ     (WM_CAP_UNICODE_START + 80)
WM_CAP_PAL_SAVEW                                equ     (WM_CAP_UNICODE_START + 81)
WM_CAP_PAL_PASTE                                equ     (WM_CAP_START + 82)
WM_CAP_PAL_AUTOCREATE                           equ     (WM_CAP_START + 83)
WM_CAP_PAL_MANUALCREATE                         equ     (WM_CAP_START + 84)
WM_CAP_SET_CALLBACK_CAPCONTROL                  equ     (WM_CAP_START + 85)
WM_CAP_UNICODE_END                              equ     WM_CAP_PAL_SAVEW
WM_CAP_END                                      equ     WM_CAP_UNICODE_END

AVSTREAMMASTER_AUDIO                            equ     0
AVSTREAMMASTER_NONE                             equ     1

CONTROLCALLBACK_PREROLL                         equ     1
CONTROLCALLBACK_CAPTURING                       equ     2

infotypeDIGITIZATION_TIME                       equ     "TIDI"
infotypeSMPTE_TIME                              equ     "PMSI"

IDS_CAP_BEGIN                                   equ     300
IDS_CAP_END                                     equ     301
IDS_CAP_INFO                                    equ     401
IDS_CAP_OUTOFMEM                                equ     402
IDS_CAP_FILEEXISTS                              equ     403
IDS_CAP_ERRORPALOPEN                            equ     404
IDS_CAP_ERRORPALSAVE                            equ     405
IDS_CAP_ERRORDIBSAVE                            equ     406
IDS_CAP_DEFAVIEXT                               equ     407
IDS_CAP_DEFPALEXT                               equ     408
IDS_CAP_CANTOPEN                                equ     409
IDS_CAP_SEQ_MSGSTART                            equ     410
IDS_CAP_SEQ_MSGSTOP                             equ     411
IDS_CAP_VIDEDITERR                              equ     412
IDS_CAP_READONLYFILE                            equ     413
IDS_CAP_WRITEERROR                              equ     414
IDS_CAP_NODISKSPACE                             equ     415
IDS_CAP_SETFILESIZE                             equ     416
IDS_CAP_SAVEASPERCENT                           equ     417
IDS_CAP_DRIVER_ERROR                            equ     418
IDS_CAP_WAVE_OPEN_ERROR                         equ     419
IDS_CAP_WAVE_ALLOC_ERROR                        equ     420
IDS_CAP_WAVE_PREPARE_ERROR                      equ     421
IDS_CAP_WAVE_ADD_ERROR                          equ     422
IDS_CAP_WAVE_SIZE_ERROR                         equ     423
IDS_CAP_VIDEO_OPEN_ERROR                        equ     424
IDS_CAP_VIDEO_ALLOC_ERROR                       equ     425
IDS_CAP_VIDEO_PREPARE_ERROR                     equ     426
IDS_CAP_VIDEO_ADD_ERROR                         equ     427
IDS_CAP_VIDEO_SIZE_ERROR                        equ     428
IDS_CAP_FILE_OPEN_ERROR                         equ     429
IDS_CAP_FILE_WRITE_ERROR                        equ     430
IDS_CAP_RECORDING_ERROR                         equ     431
IDS_CAP_RECORDING_ERROR2                        equ     432
IDS_CAP_AVI_INIT_ERROR                          equ     433
IDS_CAP_NO_FRAME_CAP_ERROR                      equ     434
IDS_CAP_NO_PALETTE_WARN                         equ     435
IDS_CAP_MCI_CONTROL_ERROR                       equ     436
IDS_CAP_MCI_CANT_STEP_ERROR                     equ     437
IDS_CAP_NO_AUDIO_CAP_ERROR                      equ     438
IDS_CAP_AVI_DRAWDIB_ERROR                       equ     439
IDS_CAP_COMPRESSOR_ERROR                        equ     440
IDS_CAP_AUDIO_DROP_ERROR                        equ     441
IDS_CAP_AUDIO_DROP_COMPERROR                    equ     442
IDS_CAP_STAT_LIVE_MODE                          equ     500
IDS_CAP_STAT_OVERLAY_MODE                       equ     501
IDS_CAP_STAT_CAP_INIT                           equ     502
IDS_CAP_STAT_CAP_FINI                           equ     503
IDS_CAP_STAT_PALETTE_BUILD                      equ     504
IDS_CAP_STAT_OPTPAL_BUILD                       equ     505
IDS_CAP_STAT_I_FRAMES                           equ     506
IDS_CAP_STAT_L_FRAMES                           equ     507
IDS_CAP_STAT_CAP_L_FRAMES                       equ     508
IDS_CAP_STAT_CAP_AUDIO                          equ     509
IDS_CAP_STAT_VIDEOCURRENT                       equ     510
IDS_CAP_STAT_VIDEOAUDIO                         equ     511
IDS_CAP_STAT_VIDEOONLY                          equ     512
IDS_CAP_STAT_FRAMESDROPPED                      equ     513

if defined APP_UNICODE
    MCIWNDF_NOTIFYMEDIA equ MCIWNDF_NOTIFYMEDIAW
    MCIWNDM_SENDSTRING equ MCIWNDM_SENDSTRINGW
    MCIWNDM_GETPOSITION equ MCIWNDM_GETPOSITIONW
    MCIWNDM_GETMODE equ MCIWNDM_GETMODEW
    MCIWNDM_SETTIMEFORMAT equ MCIWNDM_SETTIMEFORMATW
    MCIWNDM_GETTIMEFORMAT equ MCIWNDM_GETTIMEFORMATW
    MCIWNDM_GETFILENAME equ MCIWNDM_GETFILENAMEW
    MCIWNDM_GETDEVICE equ MCIWNDM_GETDEVICEW
    MCIWNDM_GETERROR equ MCIWNDM_GETERRORW
    MCIWNDM_NEW equ MCIWNDM_NEWW
    MCIWNDM_RETURNSTRING equ MCIWNDM_RETURNSTRINGW
    MCIWNDM_OPEN equ MCIWNDM_OPENW
    WM_CAP_SET_CALLBACK_ERROR equ WM_CAP_SET_CALLBACK_ERRORW
    WM_CAP_SET_CALLBACK_STATUS equ WM_CAP_SET_CALLBACK_STATUSW
    WM_CAP_DRIVER_GET_NAME equ WM_CAP_DRIVER_GET_NAMEW
    WM_CAP_DRIVER_GET_VERSION equ WM_CAP_DRIVER_GET_VERSIONW
    WM_CAP_FILE_SET_CAPTURE_FILE equ WM_CAP_FILE_SET_CAPTURE_FILEW
    WM_CAP_FILE_GET_CAPTURE_FILE equ WM_CAP_FILE_GET_CAPTURE_FILEW
    WM_CAP_FILE_SAVEAS equ WM_CAP_FILE_SAVEASW
    WM_CAP_FILE_SAVEDIB equ WM_CAP_FILE_SAVEDIBW
    WM_CAP_SET_MCI_DEVICE equ WM_CAP_SET_MCI_DEVICEW
    WM_CAP_GET_MCI_DEVICE equ WM_CAP_GET_MCI_DEVICEW
    WM_CAP_PAL_OPEN equ WM_CAP_PAL_OPENW
    WM_CAP_PAL_SAVE equ WM_CAP_PAL_SAVEW
else
    MCIWNDF_NOTIFYMEDIA equ MCIWNDF_NOTIFYMEDIAA
    MCIWNDM_SENDSTRING equ MCIWNDM_SENDSTRINGA
    MCIWNDM_GETPOSITION equ MCIWNDM_GETPOSITIONA
    MCIWNDM_GETMODE equ MCIWNDM_GETMODEA
    MCIWNDM_SETTIMEFORMAT equ MCIWNDM_SETTIMEFORMATA
    MCIWNDM_GETTIMEFORMAT equ MCIWNDM_GETTIMEFORMATA
    MCIWNDM_GETFILENAME equ MCIWNDM_GETFILENAMEA
    MCIWNDM_GETDEVICE equ MCIWNDM_GETDEVICEA
    MCIWNDM_GETERROR equ MCIWNDM_GETERRORA
    MCIWNDM_NEW equ MCIWNDM_NEWA
    MCIWNDM_RETURNSTRING equ MCIWNDM_RETURNSTRINGA
    MCIWNDM_OPEN equ MCIWNDM_OPENA
    WM_CAP_SET_CALLBACK_ERROR equ WM_CAP_SET_CALLBACK_ERRORA
    WM_CAP_SET_CALLBACK_STATUS equ WM_CAP_SET_CALLBACK_STATUSA
    WM_CAP_DRIVER_GET_NAME equ WM_CAP_DRIVER_GET_NAMEA
    WM_CAP_DRIVER_GET_VERSION equ WM_CAP_DRIVER_GET_VERSIONA
    WM_CAP_FILE_SET_CAPTURE_FILE equ WM_CAP_FILE_SET_CAPTURE_FILEA
    WM_CAP_FILE_GET_CAPTURE_FILE equ WM_CAP_FILE_GET_CAPTURE_FILEA
    WM_CAP_FILE_SAVEAS equ WM_CAP_FILE_SAVEASA
    WM_CAP_FILE_SAVEDIB equ WM_CAP_FILE_SAVEDIBA
    WM_CAP_SET_MCI_DEVICE equ WM_CAP_SET_MCI_DEVICEA
    WM_CAP_GET_MCI_DEVICE equ WM_CAP_GET_MCI_DEVICEA
    WM_CAP_PAL_OPEN equ WM_CAP_PAL_OPENA
    WM_CAP_PAL_SAVE equ WM_CAP_PAL_SAVEA
end if


;======================================== Structures ======================================;

struct ICOPEN
    dwSize      dd   ?
    fccType     dd   ?
    fccHandler  dd   ?
    dwVersion   dd   ?
    dwFlags     dd   ?
    dwError     dd   ?
    pV1Reserved xptr ?
    pV2Reserved xptr ?
    dnDevNode   dd   ?
ends

struct ICINFO
    dwSize        dd ?
    fccType       dd ?
    fccHandler    dd ?
    dwFlags       dd ?
    dwVersion     dd ?
    dwVersionICM  dd ?
    szName        dw 16 dup(?)
    szDescription dw 128 dup(?)
    szDriver      dw 128 dup(?)
ends

struct ICCOMPRESS
    dwFlags     dd   ?
    lpbiOutput  xptr ?
    lpOutput    xptr ?
    lpbiInput   xptr ?
    lpInput     xptr ?
    lpckid      xptr ?
    lpdwFlags   xptr ?
    lFrameNum   dd   ?
    dwFrameSize dd   ?
    dwQuality   dd   ?
    lpbiPrev    xptr ?
    lpPrev      xptr ?
ends

struct ICCOMPRESSFRAMES
    dwFlags            dd   ?
    lpbiOutput         xptr ?
    lOutput            xptr ?
    lpbiInput          xptr ?
    lInput             xptr ?
    lStartFrame        dd   ?
    lFrameCount        dd   ?
    lQuality           dd   ?
    lDataRate          dd   ?
    lKeyRate           dd   ?
    dwRate             dd   ?
    dwScale            dd   ?
    dwOverheadPerFrame dd   ?
    dwReserved2        dd   ?
    GetData            xptr ?
    PutData            xptr ?
ends

struct ICSETSTATUSPROC
    dwFlags    dd   ?
    lParam     xptr ?
    fpfnStatus xptr ?
ends

struct ICDECOMPRESS
    dwFlags    dd   ?
    lpbiInput  xptr ?
    lpInput    xptr ?
    lpbiOutput xptr ?
    lpOutput   xptr ?
    ckid       dd   ?
ends

struct ICDECOMPRESSEX
    dwFlags dd   ?
    lpbiSrc xptr ?
    lpSrc   xptr ?
    lpbiDst xptr ?
    lpDst   xptr ?
    xDst    dd   ?
    yDst    dd   ?
    dxDst   dd   ?
    dyDst   dd   ?
    xSrc    dd   ?
    ySrc    dd   ?
    dxSrc   dd   ?
    dySrc   dd   ?
ends

struct ICDRAWBEGIN
    dwFlags dd   ?
    hpal    xptr ?
    hwnd    xptr ?
    hdc     xptr ?
    xDst    dd   ?
    yDst    dd   ?
    dxDst   dd   ?
    dyDst   dd   ?
    lpbi    xptr ?
    xSrc    dd   ?
    ySrc    dd   ?
    dxSrc   dd   ?
    dySrc   dd   ?
    dwRate  dd   ?
    dwScale dd   ?
ends

struct ICDRAW
    dwFlags  dd   ?
    lpFormat xptr ?
    lpData   xptr ?
    cbData   dd   ?
    lTime    dd   ?
ends

struct ICDRAWSUGGEST
    lpbiIn          xptr ?
    lpbiSuggest     xptr ?
    dxSrc           dd   ?
    dySrc           dd   ?
    dxDst           dd   ?
    dyDst           dd   ?
    hicDecompressor xptr ?
ends

struct ICPALETTE
    dwFlags dd   ?
    iStart  dd   ?
    iLen    dd   ?
    lppe    xptr ?
ends

struct COMPVARS
    cbSize     dd   ?
    dwFlags    dd   ?
    hic        xptr ?
    fccType    dd   ?
    fccHandler dd   ?
    lpbiIn     xptr ?
    lpbiOut    xptr ?
    lpBitsOut  xptr ?
    lpBitsPrev xptr ?
    lFrame     dd   ?
    lKey       dd   ?
    lDataRate  dd   ?
    lQ         dd   ?
    lKeyCount  dd   ?
    lpState    xptr ?
    cbState    dd   ?
ends

struct DRAWDIBTIME
    timeCount      dd ?
    timeDraw       dd ?
    timeDecompress dd ?
    timeDither     dd ?
    timeStretch    dd ?
    timeBlt        dd ?
    timeSetDIBits  dd ?
ends

struct MainAVIHeader
    dwMicroSecPerFrame    dd ?
    dwMaxBytesPerSec      dd ?
    dwPaddingGranularity  dd ?
    dwFlags               dd ?
    dwTotalFrames         dd ?
    dwInitialFrames       dd ?
    dwStreams             dd ?
    dwSuggestedBufferSize dd ?
    dwWidth               dd ?
    dwHeight              dd ?
    dwReserved            dd 4 dup(?)
ends

struct AVIStreamHeader
    fccType               dd ?
    fccHandler            dd ?
    dwFlags               dd ?
    wPriority             dw ?
    wLanguage             dw ?
    dwInitialFrames       dd ?
    dwScale               dd ?
    dwRate                dd ?
    dwStart               dd ?
    dwLength              dd ?
    dwSuggestedBufferSize dd ?
    dwQuality             dd ?
    dwSampleSize          dd ?
    rcFrame               RECT
ends

struct AVIINDEXENTRY
    ckid          dd ?
    dwFlags       dd ?
    dwChunkOffset dd ?
    dwChunkLength dd ?
ends

struct AVIPALCHANGE
    bFirstEntry db ?
    bNumEntries db ?
    wFlags      dw ?
    peNew       PALETTEENTRY
ends

struct AVISTREAMINFOA
    fccType               dd ?
    fccHandler            dd ?
    dwFlags               dd ?
    dwCaps                dd ?
    wPriority             dw ?
    wLanguage             dw ?
    dwScale               dd ?
    dwRate                dd ?
    dwStart               dd ?
    dwLength              dd ?
    dwInitialFrames       dd ?
    dwSuggestedBufferSize dd ?
    dwQuality             dd ?
    dwSampleSize          dd ?
    rcFrame               RECT
    dwEditCount           dd ?
    dwFormatChangeCount   dd ?
    szName                db 64 dup(?)
ends

struct AVISTREAMINFOW
    fccType               dd ?
    fccHandler            dd ?
    dwFlags               dd ?
    dwCaps                dd ?
    wPriority             dw ?
    wLanguage             dw ?
    dwScale               dd ?
    dwRate                dd ?
    dwStart               dd ?
    dwLength              dd ?
    dwInitialFrames       dd ?
    dwSuggestedBufferSize dd ?
    dwQuality             dd ?
    dwSampleSize          dd ?
    rcFrame               RECT
    dwEditCount           dd ?
    dwFormatChangeCount   dd ?
    szName                dw 64 dup(?)
ends

struct AVIFILEINFOA
    dwMaxBytesPerSec      dd ?
    dwFlags               dd ?
    dwCaps                dd ?
    dwStreams             dd ?
    dwSuggestedBufferSize dd ?
    dwWidth               dd ?
    dwHeight              dd ?
    dwScale               dd ?
    dwRate                dd ?
    dwLength              dd ?
    dwEditCount           dd ?
    szFileType            db 64 dup(?)
ends

struct AVIFILEINFOW
    dwMaxBytesPerSec      dd ?
    dwFlags               dd ?
    dwCaps                dd ?
    dwStreams             dd ?
    dwSuggestedBufferSize dd ?
    dwWidth               dd ?
    dwHeight              dd ?
    dwScale               dd ?
    dwRate                dd ?
    dwLength              dd ?
    dwEditCount           dd ?
    szFileType            dw 64 dup(?)
ends

struct AVICOMPRESSOPTIONS
    fccType           dd   ?
    fccHandler        dd   ?
    dwKeyFrameEvery   dd   ?
    dwQuality         dd   ?
    dwBytesPerSecond  dd   ?
    dwFlags           dd   ?
    lpFormat          xptr ?
    cbFormat          dd   ?
    lpParms           xptr ?
    cbParms           dd   ?
    dwInterleaveEvery dd   ?
ends

if defined APP_UNICODE
    AVISTREAMINFO equ AVISTREAMINFOW
    AVIFILEINFO equ AVIFILEINFOW
else
    AVISTREAMINFO equ AVISTREAMINFOA
    AVIFILEINFO equ AVIFILEINFOA
end if

struct IAVIStream
    union
        struct
            QueryInterface  xptr    ?
            AddRef          xptr    ?
            Release         xptr    ?
        ends
        IUnknown            Unknown
    ends
    Create                  xptr    ?
    Info                    xptr    ?
    FindSample              xptr    ?
    ReadFormat              xptr    ?
    SetFormat               xptr    ?
    Read                    xptr    ?
    Write                   xptr    ?
    Delete                  xptr    ?
    ReadData                xptr    ?
    WriteData               xptr    ?
    SetInfo                 xptr    ?
ends

struct IAVIStreaming
    union
        struct
            QueryInterface      xptr ?
            AddRef              xptr ?
            Release             xptr ?
        ends
        IUnknown                Unknown
    ends
    Begin                       xptr ?
    _End                        xptr ?
ends

struct IAVIEditStream
    union
        struct
            QueryInterface      xptr ?
            AddRef              xptr ?
            Release             xptr ?
        ends
        IUnknown                Unknown
    ends
    Cut                         xptr ?
    Copy                        xptr ?
    Paste                       xptr ?
    Clone                       xptr ?
    SetInfo                     xptr ?
ends

struct IAVIFile
    union
        struct
            QueryInterface      xptr ?
            AddRef              xptr ?
            Release             xptr ?
        ends
        IUnknown                Unknown
    ends
    Info                        xptr ?
    GetStream                   xptr ?
    CreateStream                xptr ?
    WriteData                   xptr ?
    ReadData                    xptr ?
    EndRecord                   xptr ?
    DeleteStream                xptr ?
ends

struct IGetFrame
    union
        struct
            QueryInterface      xptr ?
            AddRef              xptr ?
            Release             xptr ?
        ends
        IUnknown                Unknown
    ends
    GetFrame                    xptr ?
    Begin                       xptr ?
    _End                        xptr ?
    SetFormat                   xptr ?
ends

struct VIDEOHDR
    lpData         xptr ?
    dwBufferLength dd   ?
    dwBytesUsed    dd   ?
    dwTimeCaptured dd   ?
    dwUser         dd   ?
    dwFlags        dd   ?
    dwReserved     xptr 4 dup(?)
ends

struct CHANNEL_CAPS
    dwFlags            dd ?
    dwSrcRectXMod      dd ?
    dwSrcRectYMod      dd ?
    dwSrcRectWidthMod  dd ?
    dwSrcRectHeightMod dd ?
    dwDstRectXMod      dd ?
    dwDstRectYMod      dd ?
    dwDstRectWidthMod  dd ?
    dwDstRectHeightMod dd ?
ends

struct CAPDRIVERCAPS
    wDeviceIndex            dd   ?
    fHasOverlay             dd   ?
    fHasDlgVideoSource      dd   ?
    fHasDlgVideoFormat      dd   ?
    fHasDlgVideoDisplay     dd   ?
    fCaptureInitialized     dd   ?
    fDriverSuppliesPalettes dd   ?
    hVideoIn                xptr ?
    hVideoOut               xptr ?
    hVideoExtIn             xptr ?
    hVideoExtOut            xptr ?
ends

struct CAPSTATUS
    uiImageWidth                dd    ?
    uiImageHeight               dd    ?
    fLiveWindow                 dd    ?
    fOverlayWindow              dd    ?
    _fScale                     dd    ?
    ptScroll                    POINT
    fUsingDefaultPalette        dd    ?
    fAudioHardware              dd    ?
    fCapFileExists              dd    ?
    dwCurrentVideoFrame         dd    ?
    dwCurrentVideoFramesDropped dd    ?
    dwCurrentWaveSamples        dd    ?
    dwCurrentTimeElapsedMS      dd    ?
    hPalCurrent                 xptr  ?
    fCapturingNow               dd    ?
    dwReturn                    dd    ?
    wNumVideoAllocated          dd    ?
    wNumAudioAllocated          dd    ?
ends

struct CAPTUREPARMS
    dwRequestMicroSecPerFrame dd ?
    fMakeUserHitOKToCapture   dd ?
    wPercentDropForError      dd ?
    fYield                    dd ?
    dwIndexSize               dd ?
    wChunkGranularity         dd ?
    fUsingDOSMemory           dd ?
    wNumVideoRequested        dd ?
    fCaptureAudio             dd ?
    wNumAudioRequested        dd ?
    vKeyAbort                 dd ?
    fAbortLeftMouse           dd ?
    fAbortRightMouse          dd ?
    fLimitEnabled             dd ?
    wTimeLimit                dd ?
    fMCIControl               dd ?
    fStepMCIDevice            dd ?
    dwMCIStartTime            dd ?
    dwMCIStopTime             dd ?
    fStepCaptureAt2x          dd ?
    wStepCaptureAverageFrames dd ?
    dwAudioBufferSize         dd ?
    fDisableWriteCache        dd ?
    AVStreamMaster            dd ?
ends

struct CAPINFOCHUNK
    fccInfoID dd   ?
    lpData    xptr ?
    cbData    dd   ?
ends


;======================================== Functions =======================================;
import vfwwdm32,\
    AVIBuildFilterA,'AVIBuildFilterA',\
    AVIBuildFilterW,'AVIBuildFilterW',\
    AVIClearClipboard,'AVIClearClipboard',\
    AVIFileAddRef,'AVIFileAddRef',\
    AVIFileCreateStreamA,'AVIFileCreateStreamA',\
    AVIFileCreateStreamW,'AVIFileCreateStreamW',\
    AVIFileEndRecord,'AVIFileEndRecord',\
    AVIFileExit,'AVIFileExit',\
    AVIFileGetStream,'AVIFileGetStream',\
    AVIFileInfoA,'AVIFileInfoA',\
    AVIFileInfoW,'AVIFileInfoW',\
    AVIFileInit,'AVIFileInit',\
    AVIFileOpenA,'AVIFileOpenA',\
    AVIFileOpenW,'AVIFileOpenW',\
    AVIFileReadData,'AVIFileReadData',\
    AVIFileRelease,'AVIFileRelease',\
    AVIFileWriteData,'AVIFileWriteData',\
    AVIGetFromClipboard,'AVIGetFromClipboard',\
    AVIMakeCompressedStream,'AVIMakeCompressedStream',\
    AVIMakeFileFromStreams,'AVIMakeFileFromStreams',\
    AVIMakeStreamFromClipboard,'AVIMakeStreamFromClipboard',\
    AVIPutFileOnClipboard,'AVIPutFileOnClipboard',\
    AVISaveA,'AVISaveA',\
    AVISaveOptions,'AVISaveOptions',\
    AVISaveOptionsFree,'AVISaveOptionsFree',\
    AVISaveVA,'AVISaveVA',\
    AVISaveVW,'AVISaveVW',\
    AVISaveW,'AVISaveW',\
    AVIStreamAddRef,'AVIStreamAddRef',\
    AVIStreamBeginStreaming,'AVIStreamBeginStreaming',\
    AVIStreamCreate,'AVIStreamCreate',\
    AVIStreamEndStreaming,'AVIStreamEndStreaming',\
    AVIStreamGetFrame,'AVIStreamGetFrame',\
    AVIStreamGetFrameClose,'AVIStreamGetFrameClose',\
    AVIStreamGetFrameOpen,'AVIStreamGetFrameOpen',\
    AVIStreamFindSample,'AVIStreamFindSample',\
    AVIStreamInfoA,'AVIStreamInfoA',\
    AVIStreamInfoW,'AVIStreamInfoW',\
    AVIStreamLength,'AVIStreamLength',\
    AVIStreamOpenFromFileA,'AVIStreamOpenFromFileA',\
    AVIStreamOpenFromFileW,'AVIStreamOpenFromFileW',\
    AVIStreamRead,'AVIStreamRead',\
    AVIStreamReadData,'AVIStreamReadData',\
    AVIStreamReadFormat,'AVIStreamReadFormat',\
    AVIStreamRelease,'AVIStreamRelease',\
    AVIStreamSampleToTime,'AVIStreamSampleToTime',\
    AVIStreamSetFormat,'AVIStreamSetFormat',\
    EditStreamSetInfoA,'EditStreamSetInfoA',\
    EditStreamSetInfoW,'EditStreamSetInfoW',\
    EditStreamSetNameA,'EditStreamSetNameA',\
    EditStreamSetNameW,'EditStreamSetNameW',\
    AVIStreamStart,'AVIStreamStart',\
    AVIStreamTimeToSample,'AVIStreamTimeToSample',\
    AVIStreamWrite,'AVIStreamWrite',\
    AVIStreamWriteData,'AVIStreamWriteData',\
    CreateEditableStream,'CreateEditableStream',\
    DrawDibBegin,'DrawDibBegin',\
    DrawDibChangePalette,'DrawDibChangePalette',\
    DrawDibClose,'DrawDibClose',\
    DrawDibDraw,'DrawDibDraw',\
    DrawDibEnd,'DrawDibEnd',\
    DrawDibGetBuffer,'DrawDibGetBuffer',\
    DrawDibGetPalette,'DrawDibGetPalette',\
    DrawDibOpen,'DrawDibOpen',\
    DrawDibProfileDisplay,'DrawDibProfileDisplay',\
    DrawDibRealize,'DrawDibRealize',\
    DrawDibSetPalette,'DrawDibSetPalette',\
    DrawDibStart,'DrawDibStart',\
    DrawDibStop,'DrawDibStop',\
    DrawDibTime,'DrawDibTime',\
    EditStreamClone,'EditStreamClone',\
    EditStreamCopy,'EditStreamCopy',\
    EditStreamCut,'EditStreamCut',\
    EditStreamPaste,'EditStreamPaste',\
    GetOpenFileNamePreviewA,'GetOpenFileNamePreviewA',\
    GetOpenFileNamePreviewW,'GetOpenFileNamePreviewW',\
    GetSaveFileNamePreviewA,'GetSaveFileNamePreviewA',\
    GetSaveFileNamePreviewW,'GetSaveFileNamePreviewW',\
    ICClose,'ICClose',\
    ICCompress,'ICCompress',\
    ICCompressorChoose,'ICCompressorChoose',\
    ICCompressorFree,'ICCompressorFree',\
    ICDecompress,'ICDecompress',\
    ICDraw,'ICDraw',\
    ICDrawBegin,'ICDrawBegin',\
    ICGetDisplayFormat,'ICGetDisplayFormat',\
    ICGetInfo,'ICGetInfo',\
    ICImageCompress,'ICImageCompress',\
    ICImageDecompress,'ICImageDecompress',\
    ICInfo,'ICInfo',\
    ICInstall,'ICInstall',\
    ICLocate,'ICLocate',\
    ICMThunk32,'ICMThunk32',\
    ICOpen,'ICOpen',\
    ICOpenFunction,'ICOpenFunction',\
    ICRemove,'ICRemove',\
    ICSendMessage,'ICSendMessage',\
    ICSeqCompressFrame,'ICSeqCompressFrame',\
    ICSeqCompressFrameEnd,'ICSeqCompressFrameEnd',\
    ICSeqCompressFrameStart,'ICSeqCompressFrameStart',\
    IID_IAVIEditStream,'IID_IAVIEditStream',\
    IID_IAVIFile,'IID_IAVIFile',\
    IID_IAVIStream,'IID_IAVIStream',\
    IID_IGetFrame,'IID_IGetFrame',\
    MCIWndCreateA,'MCIWndCreateA',\
    MCIWndCreateW,'MCIWndCreateW',\
    MCIWndRegisterClass,'MCIWndRegisterClass',\
    StretchDIB,'StretchDIB',\
    VideoForWindowsVersion,'VideoForWindowsVersion'

api MCIWndCreate,\
    AVIFileOpen,\
    AVIFileInfo,\
    AVIFileCreateStream,\
    AVIStreamInfo,\
    AVIStreamOpenFromFile,\
    AVISave,\
    AVISaveV,\
    AVIBuildFilter,\
    EditStreamSetInfo,\
    EditStreamSetName,\
    GetOpenFileNamePreview,\
    GetSaveFileNamePreview

AVIFileClose equ AVIFileRelease
AVIStreamClose equ AVIStreamRelease
AVIStreamExit equ AVIFileExit
AVIStreamFindKeyFrame equ AVIStreamFindSample
AVIStreamInit equ AVIFileInit

end if ;VFW32_INC
