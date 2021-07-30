; =====================================================;
;                                                      ;
;   gdi32.inc for Easy Code 2.0 64-bit Masm projects   ;
;                  (version 1.0.5)                     ;
;                                                      ;
;          Copyright © Ramon Sala 2015-2020            ;
;                                                      ;
; =====================================================;

IFNDEF GDI32_INC
GDI32_INC   EQU     1

R2_BLACK                                        EQU     1
R2_NOTMERGEPEN                                  EQU     2
R2_MASKNOTPEN                                   EQU     3
R2_NOTCOPYPEN                                   EQU     4
R2_MASKPENNOT                                   EQU     5
R2_NOT                                          EQU     6
R2_XORPEN                                       EQU     7
R2_NOTMASKPEN                                   EQU     8
R2_MASKPEN                                      EQU     9
R2_NOTXORPEN                                    EQU     10
R2_NOP                                          EQU     11
R2_MERGENOTPEN                                  EQU     12
R2_COPYPEN                                      EQU     13
R2_MERGEPENNOT                                  EQU     14
R2_MERGEPEN                                     EQU     15
R2_WHITE                                        EQU     16
R2_LAST                                         EQU     16

SRCCOPY                                         EQU     000CC0020H
SRCPAINT                                        EQU     000EE0086H
SRCAND                                          EQU     0008800C6H
SRCINVERT                                       EQU     000660046H
SRCERASE                                        EQU     000440328H
NOTSRCCOPY                                      EQU     000330008H
NOTSRCERASE                                     EQU     0001100A6H
MERGECOPY                                       EQU     000C000CAH
MERGEPAINT                                      EQU     000BB0226H
PATCOPY                                         EQU     000F00021H
PATPAINT                                        EQU     000FB0A09H
PATINVERT                                       EQU     0005A0049H
DSTINVERT                                       EQU     000550009H
BLACKNESS                                       EQU     000000042H
WHITENESS                                       EQU     000FF0062H

NOMIRRORBITMAP                                  EQU     080000000H
CAPTUREBLT                                      EQU     040000000H

GDI_ERROR                                       EQU     0FFFFFFFFH
HGDI_ERROR                                      EQU     0FFFFFFFFH

ERROR                                           EQU     0
NULLREGION                                      EQU     1
SIMPLEREGION                                    EQU     2
COMPLEXREGION                                   EQU     3
RGN_ERROR                                       EQU     ERROR

RGN_AND                                         EQU     1
RGN_OR                                          EQU     2
RGN_XOR                                         EQU     3
RGN_DIFF                                        EQU     4
RGN_COPY                                        EQU     5
RGN_MIN                                         EQU     RGN_AND
RGN_MAX                                         EQU     RGN_COPY

BLACKONWHITE                                    EQU     1
WHITEONBLACK                                    EQU     2
COLORONCOLOR                                    EQU     3
HALFTONE                                        EQU     4
MAXSTRETCHBLTMODE                               EQU     4

STRETCH_ANDSCANS                                EQU     BLACKONWHITE
STRETCH_ORSCANS                                 EQU     WHITEONBLACK
STRETCH_DELETESCANS                             EQU     COLORONCOLOR
STRETCH_HALFTONE                                EQU     HALFTONE

ALTERNATE                                       EQU     1
WINDING                                         EQU     2
POLYFILL_LAST                                   EQU     2

LAYOUT_RTL                                      EQU     00000001H
LAYOUT_BTT                                      EQU     00000002H
LAYOUT_VBH                                      EQU     00000004H
LAYOUT_ORIENTATIONMASK                          EQU     (LAYOUT_RTL OR LAYOUT_BTT OR LAYOUT_VBH)
LAYOUT_BITMAPORIENTATIONPRESERVED               EQU     00000008H

TA_NOUPDATECP                                   EQU     0
TA_UPDATECP                                     EQU     1

TA_LEFT                                         EQU     0
TA_RIGHT                                        EQU     2
TA_CENTER                                       EQU     6

TA_TOP                                          EQU     0
TA_BOTTOM                                       EQU     8
TA_BASELINE                                     EQU     24
TA_RTLREADING                                   EQU     256
TA_MASK                                         EQU     (TA_BASELINE + TA_CENTER + TA_UPDATECP + TA_RTLREADING)

VTA_BASELINE                                    EQU     TA_BASELINE
VTA_LEFT                                        EQU     TA_BOTTOM
VTA_RIGHT                                       EQU     TA_TOP
VTA_CENTER                                      EQU     TA_CENTER
VTA_BOTTOM                                      EQU     TA_RIGHT
VTA_TOP                                         EQU     TA_LEFT

ETO_OPAQUE                                      EQU     00002H
ETO_CLIPPED                                     EQU     00004H
ETO_GLYPH_INDEX                                 EQU     00010H
ETO_RTLREADING                                  EQU     00080H
ETO_NUMERICSLOCAL                               EQU     00400H
ETO_NUMERICSLATIN                               EQU     00800H
ETO_IGNORELANGUAGE                              EQU     01000H
ETO_PDY                                         EQU     02000H
ETO_REVERSE_INDEX_MAP                           EQU     10000H

ASPECT_FILTERING                                EQU     00001H

DCB_RESET                                       EQU     00001H
DCB_ACCUMULATE                                  EQU     00002H
DCB_DIRTY                                       EQU     DCB_ACCUMULATE
DCB_SET                                         EQU     (DCB_RESET OR DCB_ACCUMULATE)
DCB_ENABLE                                      EQU     00004H
DCB_DISABLE                                     EQU     00008H

META_SETBKCOLOR                                 EQU     00201H
META_SETBKMODE                                  EQU     00102H
META_SETMAPMODE                                 EQU     00103H
META_SETROP2                                    EQU     00104H
META_SETRELABS                                  EQU     00105H
META_SETPOLYFILLMODE                            EQU     00106H
META_SETSTRETCHBLTMODE                          EQU     00107H
META_SETTEXTCHAREXTRA                           EQU     00108H
META_SETTEXTCOLOR                               EQU     00209H
META_SETTEXTJUSTIFICATION                       EQU     0020AH
META_SETWINDOWORG                               EQU     0020BH
META_SETWINDOWEXT                               EQU     0020CH
META_SETVIEWPORTORG                             EQU     0020DH
META_SETVIEWPORTEXT                             EQU     0020EH
META_OFFSETWINDOWORG                            EQU     0020FH
META_SCALEWINDOWEXT                             EQU     00410H
META_OFFSETVIEWPORTORG                          EQU     00211H
META_SCALEVIEWPORTEXT                           EQU     00412H
META_LINETO                                     EQU     00213H
META_MOVETO                                     EQU     00214H
META_EXCLUDECLIPRECT                            EQU     00415H
META_INTERSECTCLIPRECT                          EQU     00416H
META_ARC                                        EQU     00817H
META_ELLIPSE                                    EQU     00418H
META_FLOODFILL                                  EQU     00419H
META_PIE                                        EQU     0081AH
META_RECTANGLE                                  EQU     0041BH
META_ROUNDRECT                                  EQU     0061CH
META_PATBLT                                     EQU     0061DH
META_SAVEDC                                     EQU     0001EH
META_SETPIXEL                                   EQU     0041FH
META_OFFSETCLIPRGN                              EQU     00220H
META_TEXTOUT                                    EQU     00521H
META_BITBLT                                     EQU     00922H
META_STRETCHBLT                                 EQU     00B23H
META_POLYGON                                    EQU     00324H
META_POLYLINE                                   EQU     00325H
META_ESCAPE                                     EQU     00626H
META_RESTOREDC                                  EQU     00127H
META_FILLREGION                                 EQU     00228H
META_FRAMEREGION                                EQU     00429H
META_INVERTREGION                               EQU     0012AH
META_PAINTREGION                                EQU     0012BH
META_SELECTCLIPREGION                           EQU     0012CH
META_SELECTOBJECT                               EQU     0012DH
META_SETTEXTALIGN                               EQU     0012EH
META_CHORD                                      EQU     00830H
META_SETMAPPERFLAGS                             EQU     00231H
META_EXTTEXTOUT                                 EQU     00A32H
META_SETDIBTODEV                                EQU     00D33H
META_SELECTPALETTE                              EQU     00234H
META_REALIZEPALETTE                             EQU     00035H
META_ANIMATEPALETTE                             EQU     00436H
META_SETPALENTRIES                              EQU     00037H
META_POLYPOLYGON                                EQU     00538H
META_RESIZEPALETTE                              EQU     00139H
META_DIBBITBLT                                  EQU     00940H
META_DIBSTRETCHBLT                              EQU     00B41H
META_DIBCREATEPATTERNBRUSH                      EQU     00142H
META_STRETCHDIB                                 EQU     00F43H
META_EXTFLOODFILL                               EQU     00548H
META_DELETEOBJECT                               EQU     001F0H
META_CREATEPALETTE                              EQU     000F7H
META_CREATEPATTERNBRUSH                         EQU     001F9H
META_CREATEPENINDIRECT                          EQU     002FAH
META_CREATEFONTINDIRECT                         EQU     002FBH
META_CREATEBRUSHINDIRECT                        EQU     002FCH
META_CREATEREGION                               EQU     006FFH

NEWFRAME                                        EQU     1
ABORTDOC                                        EQU     2
NEXTBAND                                        EQU     3
SETCOLORTABLE                                   EQU     4
GETCOLORTABLE                                   EQU     5
FLUSHOUTPUT                                     EQU     6
DRAFTMODE                                       EQU     7
QUERYESCSUPPORT                                 EQU     8
SETABORTPROC                                    EQU     9
STARTDOC                                        EQU     10
ENDDOC                                          EQU     11
GETPHYSPAGESIZE                                 EQU     12
GETPRINTINGOFFSET                               EQU     13
GETSCALINGFACTOR                                EQU     14
MFCOMMENT                                       EQU     15
GETPENWIDTH                                     EQU     16
SETCOPYCOUNT                                    EQU     17
SELECTPAPERSOURCE                               EQU     18
DEVICEDATA                                      EQU     19
PASSTHROUGH                                     EQU     19
GETTECHNOLGY                                    EQU     20
GETTECHNOLOGY                                   EQU     20
SETLINECAP                                      EQU     21
SETLINEJOIN                                     EQU     22
SETMITERLIMIT                                   EQU     23
BANDINFO                                        EQU     24
DRAWPATTERNRECT                                 EQU     25
GETVECTORPENSIZE                                EQU     26
GETVECTORBRUSHSIZE                              EQU     27
ENABLEDUPLEX                                    EQU     28
GETSETPAPERBINS                                 EQU     29
GETSETPRINTORIENT                               EQU     30
ENUMPAPERBINS                                   EQU     31
SETDIBSCALING                                   EQU     32
EPSPRINTING                                     EQU     33
ENUMPAPERMETRICS                                EQU     34
GETSETPAPERMETRICS                              EQU     35
POSTSCRIPT_DATA                                 EQU     37
POSTSCRIPT_IGNORE                               EQU     38
MOUSETRAILS                                     EQU     39
GETDEVICEUNITS                                  EQU     42

GETEXTENDEDTEXTMETRICS                          EQU     256
GETEXTENTTABLE                                  EQU     257
GETPAIRKERNTABLE                                EQU     258
GETTRACKKERNTABLE                               EQU     259
EXTTEXTOUT                                      EQU     512
GETFACENAME                                     EQU     513
DOWNLOADFACE                                    EQU     514
ENABLERELATIVEWIDTHS                            EQU     768
ENABLEPAIRKERNING                               EQU     769
SETKERNTRACK                                    EQU     770
SETALLJUSTVALUES                                EQU     771
SETCHARSET                                      EQU     772

STRETCHBLT                                      EQU     2048
GETSETSCREENPARAMS                              EQU     3072
QUERYDIBSUPPORT                                 EQU     3073
BEGIN_PATH                                      EQU     4096
CLIP_TO_PATH                                    EQU     4097
END_PATH                                        EQU     4098
EXT_DEVICE_CAPS                                 EQU     4099
RESTORE_CTM                                     EQU     4100
SAVE_CTM                                        EQU     4101
SET_ARC_DIRECTION                               EQU     4102
SET_BACKGROUND_COLOR                            EQU     4103
SET_POLY_MODE                                   EQU     4104
SET_SCREEN_ANGLE                                EQU     4105
SET_SPREAD                                      EQU     4106
TRANSFORM_CTM                                   EQU     4107
SET_CLIP_BOX                                    EQU     4108
SET_BOUNDS                                      EQU     4109
SET_MIRROR_MODE                                 EQU     4110
OPENCHANNEL                                     EQU     4110
DOWNLOADHEADER                                  EQU     4111
CLOSECHANNEL                                    EQU     4112
POSTSCRIPT_PASSTHROUGH                          EQU     4115
ENCAPSULATED_POSTSCRIPT                         EQU     4116

POSTSCRIPT_IDENTIFY                             EQU     4117
POSTSCRIPT_INJECTION                            EQU     4118

CHECKJPEGFORMAT                                 EQU     4119
CHECKPNGFORMAT                                  EQU     4120
GET_PS_FEATURESETTING                           EQU     4121

SPCLPASSTHROUGH2                                EQU     4568

PSIDENT_GDICENTRIC                              EQU     0
PSIDENT_PSCENTRIC                               EQU     1

PSINJECT_APPEND                                 EQU     0
PSINJECT_REPLACE                                EQU     1

PSINJECT_BEGINSTREAM                            EQU     1
PSINJECT_PSADOBE                                EQU     2
PSINJECT_PAGESATEND                             EQU     3
PSINJECT_PAGES                                  EQU     4
PSINJECT_DOCNEEDEDRES                           EQU     5
PSINJECT_DOCSUPPLIEDRES                         EQU     6
PSINJECT_PAGEORDER                              EQU     7
PSINJECT_ORIENTATION                            EQU     8
PSINJECT_BOUNDINGBOX                            EQU     9
PSINJECT_DOCUMENTPROCESSCOLORS                  EQU     10
PSINJECT_COMMENTS                               EQU     11
PSINJECT_BEGINDEFAULTS                          EQU     12
PSINJECT_ENDDEFAULTS                            EQU     13
PSINJECT_BEGINPROLOG                            EQU     14
PSINJECT_ENDPROLOG                              EQU     15
PSINJECT_BEGINSETUP                             EQU     16
PSINJECT_ENDSETUP                               EQU     17
PSINJECT_TRAILER                                EQU     18
PSINJECT_EOF                                    EQU     19
PSINJECT_ENDSTREAM                              EQU     20
PSINJECT_DOCUMENTPROCESSCOLORSATEND             EQU     21
PSINJECT_PAGENUMBER                             EQU     100
PSINJECT_BEGINPAGESETUP                         EQU     101
PSINJECT_ENDPAGESETUP                           EQU     102
PSINJECT_PAGETRAILER                            EQU     103
PSINJECT_PLATECOLOR                             EQU     104
PSINJECT_SHOWPAGE                               EQU     105
PSINJECT_PAGEBBOX                               EQU     106
PSINJECT_ENDPAGECOMMENTS                        EQU     107
PSINJECT_VMSAVE                                 EQU     200
PSINJECT_VMRESTORE                              EQU     201
PSINJECT_DLFONT                                 EQU     0DDDDDDDDH

FEATURESETTING_NUP                              EQU     0
FEATURESETTING_OUTPUT                           EQU     1
FEATURESETTING_PSLEVEL                          EQU     2
FEATURESETTING_CUSTPAPER                        EQU     3
FEATURESETTING_MIRROR                           EQU     4
FEATURESETTING_NEGATIVE                         EQU     5
FEATURESETTING_PROTOCOL                         EQU     6
IF (NTDDI_VERSION GE NTDDI_WINXP)
    FEATURESETTING_PRIVATE_BEGIN                EQU     01000H
    FEATURESETTING_PRIVATE_END                  EQU     01FFFH
ENDIF

PSPROTOCOL_ASCII                                EQU     0
PSPROTOCOL_BCP                                  EQU     1
PSPROTOCOL_TBCP                                 EQU     2
PSPROTOCOL_BINARY                               EQU     3

QDI_SETDIBITS                                   EQU     1
QDI_GETDIBITS                                   EQU     2
QDI_DIBTOSCREEN                                 EQU     4
QDI_STRETCHDIB                                  EQU     8

SP_NOTREPORTED                                  EQU     04000H
SP_ERROR                                        EQU     (-1)
SP_APPABORT                                     EQU     (-2)
SP_USERABORT                                    EQU     (-3)
SP_OUTOFDISK                                    EQU     (-4)
SP_OUTOFMEMORY                                  EQU     (-5)

PR_JOBSTATUS                                    EQU     00000H

OBJ_PEN                                         EQU     1
OBJ_BRUSH                                       EQU     2
OBJ_DC                                          EQU     3
OBJ_METADC                                      EQU     4
OBJ_PAL                                         EQU     5
OBJ_FONT                                        EQU     6
OBJ_BITMAP                                      EQU     7
OBJ_REGION                                      EQU     8
OBJ_METAFILE                                    EQU     9
OBJ_MEMDC                                       EQU     10
OBJ_EXTPEN                                      EQU     11
OBJ_ENHMETADC                                   EQU     12
OBJ_ENHMETAFILE                                 EQU     13
OBJ_COLORSPACE                                  EQU     14
GDI_OBJ_LAST                                    EQU     OBJ_COLORSPACE

MWT_IDENTITY                                    EQU     1
MWT_LEFTMULTIPLY                                EQU     2
MWT_RIGHTMULTIPLY                               EQU     3

MWT_MIN                                         EQU     MWT_IDENTITY
MWT_MAX                                         EQU     MWT_RIGHTMULTIPLY

CS_ENABLE                                       EQU     000000001H
CS_DISABLE                                      EQU     000000002H
CS_DELETE_TRANSFORM                             EQU     000000003H

LCS_SIGNATURE                                   EQU     <PSOC>

LCS_sRGB                                        EQU     <sRGB>
LCS_WINDOWS_COLOR_SPACE                         EQU     <Win >

LCS_CALIBRATED_RGB                              EQU     000000000H
LCS_DEVICE_RGB                                  EQU     000000001H
LCS_DEVICE_CMYK                                 EQU     000000002H

LCS_GM_BUSINESS                                 EQU     000000001H
LCS_GM_GRAPHICS                                 EQU     000000002H
LCS_GM_IMAGES                                   EQU     000000004H
LCS_GM_ABS_COLORIMETRIC                         EQU     000000008H

CM_OUT_OF_GAMUT                                 EQU     255
CM_IN_GAMUT                                     EQU     0

ICM_ADDPROFILE                                  EQU     1
ICM_DELETEPROFILE                               EQU     2
ICM_QUERYPROFILE                                EQU     3
ICM_SETDEFAULTPROFILE                           EQU     4
ICM_REGISTERICMATCHER                           EQU     5
ICM_UNREGISTERICMATCHER                         EQU     6
ICM_QUERYMATCH                                  EQU     7

PROFILE_LINKED                                  EQU     <LINK>
PROFILE_EMBEDDED                                EQU     <MBED>

BI_RGB                                          EQU     0
BI_RLE8                                         EQU     1
BI_RLE4                                         EQU     2
BI_BITFIELDS                                    EQU     3
BI_JPEG                                         EQU     4
BI_PNG                                          EQU     5

TCI_SRCCHARSET                                  EQU     1
TCI_SRCCODEPAGE                                 EQU     2
TCI_SRCFONTSIG                                  EQU     3
IF (NTDDI_VERSION GE NTDDI_WINXP)
    TCI_SRCLOCALE                               EQU     1000H
ENDIF

TMPF_FIXED_PITCH                                EQU     001H
TMPF_VECTOR                                     EQU     002H
TMPF_DEVICE                                     EQU     008H
TMPF_TRUETYPE                                   EQU     004H

NTM_REGULAR                                     EQU     000000040H
NTM_BOLD                                        EQU     000000020H
NTM_ITALIC                                      EQU     000000001H

NTM_NONNEGATIVE_AC                              EQU     000010000H
NTM_PS_OPENTYPE                                 EQU     000020000H
NTM_TT_OPENTYPE                                 EQU     000040000H
NTM_MULTIPLEMASTER                              EQU     000040000H
NTM_MM_INSTANCE                                 EQU     000080000H
NTM_TYPE1                                       EQU     000100000H
NTM_DSIG                                        EQU     000200000H

IFNDEF LF_FACESIZE
    LF_FACESIZE                                 EQU     32
ENDIF
LF_FULLFACESIZE                                 EQU     64

OUT_DEFAULT_PRECIS                              EQU     0
OUT_STRING_PRECIS                               EQU     1
OUT_CHARACTER_PRECIS                            EQU     2
OUT_STROKE_PRECIS                               EQU     3
OUT_TT_PRECIS                                   EQU     4
OUT_DEVICE_PRECIS                               EQU     5
OUT_RASTER_PRECIS                               EQU     6
OUT_TT_ONLY_PRECIS                              EQU     7
OUT_OUTLINE_PRECIS                              EQU     8
OUT_SCREEN_OUTLINE_PRECIS                       EQU     9
OUT_PS_ONLY_PRECIS                              EQU     10

CLIP_DEFAULT_PRECIS                             EQU     0
CLIP_CHARACTER_PRECIS                           EQU     1
CLIP_STROKE_PRECIS                              EQU     2
CLIP_MASK                                       EQU     0FH
CLIP_LH_ANGLES                                  EQU     (1 SHL 4)
CLIP_TT_ALWAYS                                  EQU     (2 SHL 4)
CLIP_EMBEDDED                                   EQU     (8 SHL 4)
IF (NTDDI_VERSION GE NTDDI_VISTA)
    CLIP_DFA_DISABLE                            EQU     (4 SHL 4)
ENDIF

DEFAULT_QUALITY                                 EQU     0
DRAFT_QUALITY                                   EQU     1
PROOF_QUALITY                                   EQU     2
NONANTIALIASED_QUALITY                          EQU     3
ANTIALIASED_QUALITY                             EQU     4
IF (NTDDI_VERSION GE NTDDI_WINXP)
    CLEARTYPE_QUALITY                           EQU     5
    CLEARTYPE_NATURAL_QUALITY                   EQU     6
ENDIF

DEFAULT_PITCH                                   EQU     0
FIXED_PITCH                                     EQU     1
VARIABLE_PITCH                                  EQU     2
MONO_FONT                                       EQU     8

ANSI_CHARSET                                    EQU     0
DEFAULT_CHARSET                                 EQU     1
SYMBOL_CHARSET                                  EQU     2
MAC_CHARSET                                     EQU     77
SHIFTJIS_CHARSET                                EQU     128
HANGEUL_CHARSET                                 EQU     129
HANGUL_CHARSET                                  EQU     129
GB2312_CHARSET                                  EQU     134
CHINESEBIG5_CHARSET                             EQU     136
JOHAB_CHARSET                                   EQU     130
HEBREW_CHARSET                                  EQU     177
ARABIC_CHARSET                                  EQU     178
GREEK_CHARSET                                   EQU     161
TURKISH_CHARSET                                 EQU     162
VIETNAMESE_CHARSET                              EQU     163
BALTIC_CHARSET                                  EQU     186
RUSSIAN_CHARSET                                 EQU     204
THAI_CHARSET                                    EQU     222
EASTEUROPE_CHARSET                              EQU     238
OEM_CHARSET                                     EQU     255

FS_LATIN1                                       EQU     000000001H
FS_LATIN2                                       EQU     000000002H
FS_CYRILLIC                                     EQU     000000004H
FS_GREEK                                        EQU     000000008H
FS_TURKISH                                      EQU     000000010H
FS_HEBREW                                       EQU     000000020H
FS_ARABIC                                       EQU     000000040H
FS_BALTIC                                       EQU     000000080H
FS_VIETNAMESE                                   EQU     000000100H
FS_THAI                                         EQU     000010000H
FS_JISJAPAN                                     EQU     000020000H
FS_CHINESESIMP                                  EQU     000040000H
FS_WANSUNG                                      EQU     000080000H
FS_CHINESETRAD                                  EQU     000100000H
FS_JOHAB                                        EQU     000200000H
FS_SYMBOL                                       EQU     080000000H

FF_DONTCARE                                     EQU     (0 SHL 4)
FF_ROMAN                                        EQU     (1 SHL 4)
FF_SWISS                                        EQU     (2 SHL 4)
FF_MODERN                                       EQU     (3 SHL 4)
FF_SCRIPT                                       EQU     (4 SHL 4)
FF_DECORATIVE                                   EQU     (5 SHL 4)

FW_DONTCARE                                     EQU     0
FW_THIN                                         EQU     100
FW_EXTRALIGHT                                   EQU     200
FW_LIGHT                                        EQU     300
FW_NORMAL                                       EQU     400
FW_MEDIUM                                       EQU     500
FW_SEMIBOLD                                     EQU     600
FW_BOLD                                         EQU     700
FW_EXTRABOLD                                    EQU     800
FW_HEAVY                                        EQU     900

FW_ULTRALIGHT                                   EQU     FW_EXTRALIGHT
FW_REGULAR                                      EQU     FW_NORMAL
FW_DEMIBOLD                                     EQU     FW_SEMIBOLD
FW_ULTRABOLD                                    EQU     FW_EXTRABOLD
FW_BLACK                                        EQU     FW_HEAVY

PANOSE_COUNT                                    EQU     10

PAN_FAMILYTYPE_INDEX                            EQU     0
PAN_SERIFSTYLE_INDEX                            EQU     1
PAN_WEIGHT_INDEX                                EQU     2
PAN_PROPORTION_INDEX                            EQU     3
PAN_CONTRAST_INDEX                              EQU     4
PAN_STROKEVARIATION_INDEX                       EQU     5
PAN_ARMSTYLE_INDEX                              EQU     6
PAN_LETTERFORM_INDEX                            EQU     7
PAN_MIDLINE_INDEX                               EQU     8
PAN_XHEIGHT_INDEX                               EQU     9

PAN_CULTURE_LATIN                               EQU     0

PAN_ANY                                         EQU     0
PAN_NO_FIT                                      EQU     1

PAN_FAMILY_TEXT_DISPLAY                         EQU     2
PAN_FAMILY_SCRIPT                               EQU     3
PAN_FAMILY_DECORATIVE                           EQU     4
PAN_FAMILY_PICTORIAL                            EQU     5

PAN_SERIF_COVE                                  EQU     2
PAN_SERIF_OBTUSE_COVE                           EQU     3
PAN_SERIF_SQUARE_COVE                           EQU     4
PAN_SERIF_OBTUSE_SQUARE_COVE                    EQU     5
PAN_SERIF_SQUARE                                EQU     6
PAN_SERIF_THIN                                  EQU     7
PAN_SERIF_BONE                                  EQU     8
PAN_SERIF_EXAGGERATED                           EQU     9
PAN_SERIF_TRIANGLE                              EQU     10
PAN_SERIF_NORMAL_SANS                           EQU     11
PAN_SERIF_OBTUSE_SANS                           EQU     12
PAN_SERIF_PERP_SANS                             EQU     13
PAN_SERIF_FLARED                                EQU     14
PAN_SERIF_ROUNDED                               EQU     15

PAN_WEIGHT_VERY_LIGHT                           EQU     2
PAN_WEIGHT_LIGHT                                EQU     3
PAN_WEIGHT_THIN                                 EQU     4
PAN_WEIGHT_BOOK                                 EQU     5
PAN_WEIGHT_MEDIUM                               EQU     6
PAN_WEIGHT_DEMI                                 EQU     7
PAN_WEIGHT_BOLD                                 EQU     8
PAN_WEIGHT_HEAVY                                EQU     9
PAN_WEIGHT_BLACK                                EQU     10
PAN_WEIGHT_NORD                                 EQU     11

PAN_PROP_OLD_STYLE                              EQU     2
PAN_PROP_MODERN                                 EQU     3
PAN_PROP_EVEN_WIDTH                             EQU     4
PAN_PROP_EXPANDED                               EQU     5
PAN_PROP_CONDENSED                              EQU     6
PAN_PROP_VERY_EXPANDED                          EQU     7
PAN_PROP_VERY_CONDENSED                         EQU     8
PAN_PROP_MONOSPACED                             EQU     9

PAN_CONTRAST_NONE                               EQU     2
PAN_CONTRAST_VERY_LOW                           EQU     3
PAN_CONTRAST_LOW                                EQU     4
PAN_CONTRAST_MEDIUM_LOW                         EQU     5
PAN_CONTRAST_MEDIUM                             EQU     6
PAN_CONTRAST_MEDIUM_HIGH                        EQU     7
PAN_CONTRAST_HIGH                               EQU     8
PAN_CONTRAST_VERY_HIGH                          EQU     9

PAN_STROKE_GRADUAL_DIAG                         EQU     2
PAN_STROKE_GRADUAL_TRAN                         EQU     3
PAN_STROKE_GRADUAL_VERT                         EQU     4
PAN_STROKE_GRADUAL_HORZ                         EQU     5
PAN_STROKE_RAPID_VERT                           EQU     6
PAN_STROKE_RAPID_HORZ                           EQU     7
PAN_STROKE_INSTANT_VERT                         EQU     8

PAN_STRAIGHT_ARMS_HORZ                          EQU     2
PAN_STRAIGHT_ARMS_WEDGE                         EQU     3
PAN_STRAIGHT_ARMS_VERT                          EQU     4
PAN_STRAIGHT_ARMS_SINGLE_SERIF                  EQU     5
PAN_STRAIGHT_ARMS_DOUBLE_SERIF                  EQU     6
PAN_BENT_ARMS_HORZ                              EQU     7
PAN_BENT_ARMS_WEDGE                             EQU     8
PAN_BENT_ARMS_VERT                              EQU     9
PAN_BENT_ARMS_SINGLE_SERIF                      EQU     10
PAN_BENT_ARMS_DOUBLE_SERIF                      EQU     11

PAN_LETT_NORMAL_CONTACT                         EQU     2
PAN_LETT_NORMAL_WEIGHTED                        EQU     3
PAN_LETT_NORMAL_BOXED                           EQU     4
PAN_LETT_NORMAL_FLATTENED                       EQU     5
PAN_LETT_NORMAL_ROUNDED                         EQU     6
PAN_LETT_NORMAL_OFF_CENTER                      EQU     7
PAN_LETT_NORMAL_SQUARE                          EQU     8
PAN_LETT_OBLIQUE_CONTACT                        EQU     9
PAN_LETT_OBLIQUE_WEIGHTED                       EQU     10
PAN_LETT_OBLIQUE_BOXED                          EQU     11
PAN_LETT_OBLIQUE_FLATTENED                      EQU     12
PAN_LETT_OBLIQUE_ROUNDED                        EQU     13
PAN_LETT_OBLIQUE_OFF_CENTER                     EQU     14
PAN_LETT_OBLIQUE_SQUARE                         EQU     15

PAN_MIDLINE_STANDARD_TRIMMED                    EQU     2
PAN_MIDLINE_STANDARD_POINTED                    EQU     3
PAN_MIDLINE_STANDARD_SERIFED                    EQU     4
PAN_MIDLINE_HIGH_TRIMMED                        EQU     5
PAN_MIDLINE_HIGH_POINTED                        EQU     6
PAN_MIDLINE_HIGH_SERIFED                        EQU     7
PAN_MIDLINE_CONSTANT_TRIMMED                    EQU     8
PAN_MIDLINE_CONSTANT_POINTED                    EQU     9
PAN_MIDLINE_CONSTANT_SERIFED                    EQU     10
PAN_MIDLINE_LOW_TRIMMED                         EQU     11
PAN_MIDLINE_LOW_POINTED                         EQU     12
PAN_MIDLINE_LOW_SERIFED                         EQU     13

PAN_XHEIGHT_CONSTANT_SMALL                      EQU     2
PAN_XHEIGHT_CONSTANT_STD                        EQU     3
PAN_XHEIGHT_CONSTANT_LARGE                      EQU     4
PAN_XHEIGHT_DUCKING_SMALL                       EQU     5
PAN_XHEIGHT_DUCKING_STD                         EQU     6
PAN_XHEIGHT_DUCKING_LARGE                       EQU     7

ELF_VENDOR_SIZE                                 EQU     4

ELF_VERSION                                     EQU     0
ELF_CULTURE_LATIN                               EQU     0

RASTER_FONTTYPE                                 EQU     00001H
DEVICE_FONTTYPE                                 EQU     0002H
TRUETYPE_FONTTYPE                               EQU     0004H

PC_RESERVED                                     EQU     001H
PC_EXPLICIT                                     EQU     002H
PC_NOCOLLAPSE                                   EQU     004H

TRANSPARENT                                     EQU     1
OPAQUE                                          EQU     2
BKMODE_LAST                                     EQU     2

GM_COMPATIBLE                                   EQU     1
GM_ADVANCED                                     EQU     2
GM_LAST                                         EQU     2

PT_CLOSEFIGURE                                  EQU     001H
PT_LINETO                                       EQU     002H
PT_BEZIERTO                                     EQU     004H
PT_MOVETO                                       EQU     006H

MM_TEXT                                         EQU     1
MM_LOMETRIC                                     EQU     2
MM_HIMETRIC                                     EQU     3
MM_LOENGLISH                                    EQU     4
MM_HIENGLISH                                    EQU     5
MM_TWIPS                                        EQU     6
MM_ISOTROPIC                                    EQU     7
MM_ANISOTROPIC                                  EQU     8

MM_MIN                                          EQU     MM_TEXT
MM_MAX                                          EQU     MM_ANISOTROPIC
MM_MAX_FIXEDSCALE                               EQU     MM_TWIPS

ABSOLUTE                                        EQU     1
RELATIVE                                        EQU     2

WHITE_BRUSH                                     EQU     0
LTGRAY_BRUSH                                    EQU     1
GRAY_BRUSH                                      EQU     2
DKGRAY_BRUSH                                    EQU     3
BLACK_BRUSH                                     EQU     4
NULL_BRUSH                                      EQU     5
HOLLOW_BRUSH                                    EQU     NULL_BRUSH
WHITE_PEN                                       EQU     6
BLACK_PEN                                       EQU     7
NULL_PEN                                        EQU     8
OEM_FIXED_FONT                                  EQU     10
ANSI_FIXED_FONT                                 EQU     11
ANSI_VAR_FONT                                   EQU     12
SYSTEM_FONT                                     EQU     13
DEVICE_DEFAULT_FONT                             EQU     14
DEFAULT_PALETTE                                 EQU     15
SYSTEM_FIXED_FONT                               EQU     16

DEFAULT_GUI_FONT                                EQU     17

DC_BRUSH                                        EQU     18
DC_PEN                                          EQU     19

IF (NTDDI_VERSION LE NTDDI_WINNT4)
    STOCK_LAST                                  EQU     17
ELSE
    STOCK_LAST                                  EQU     19
ENDIF

CLR_INVALID                                     EQU     0FFFFFFFFH

BS_SOLID                                        EQU     0
BS_NULL                                         EQU     1
BS_HOLLOW                                       EQU     BS_NULL
BS_HATCHED                                      EQU     2
BS_PATTERN                                      EQU     3
BS_INDEXED                                      EQU     4
BS_DIBPATTERN                                   EQU     5
BS_DIBPATTERNPT                                 EQU     6
BS_PATTERN8X8                                   EQU     7
BS_DIBPATTERN8X8                                EQU     8
BS_MONOPATTERN                                  EQU     9

HS_HORIZONTAL                                   EQU     0
HS_VERTICAL                                     EQU     1
HS_FDIAGONAL                                    EQU     2
HS_BDIAGONAL                                    EQU     3
HS_CROSS                                        EQU     4
HS_DIAGCROSS                                    EQU     5

PS_SOLID                                        EQU     0
PS_DASH                                         EQU     1
PS_DOT                                          EQU     2
PS_DASHDOT                                      EQU     3
PS_DASHDOTDOT                                   EQU     4
PS_NULL                                         EQU     5
PS_INSIDEFRAME                                  EQU     6
PS_USERSTYLE                                    EQU     7
PS_ALTERNATE                                    EQU     8
PS_STYLE_MASK                                   EQU     00000000FH

PS_ENDCAP_ROUND                                 EQU     000000000H
PS_ENDCAP_SQUARE                                EQU     000000100H
PS_ENDCAP_FLAT                                  EQU     000000200H
PS_ENDCAP_MASK                                  EQU     000000F00H

PS_JOIN_ROUND                                   EQU     000000000H
PS_JOIN_BEVEL                                   EQU     000001000H
PS_JOIN_MITER                                   EQU     000002000H
PS_JOIN_MASK                                    EQU     00000F000H

PS_COSMETIC                                     EQU     000000000H
PS_GEOMETRIC                                    EQU     000010000H
PS_TYPE_MASK                                    EQU     0000F0000H

AD_COUNTERCLOCKWISE                             EQU     1
AD_CLOCKWISE                                    EQU     2

DRIVERVERSION                                   EQU     0
TECHNOLOGY                                      EQU     2
HORZSIZE                                        EQU     4
VERTSIZE                                        EQU     6
HORZRES                                         EQU     8
VERTRES                                         EQU     10
BITSPIXEL                                       EQU     12
PLANES                                          EQU     14
NUMBRUSHES                                      EQU     16
NUMPENS                                         EQU     18
NUMMARKERS                                      EQU     20
NUMFONTS                                        EQU     22
NUMCOLORS                                       EQU     24
PDEVICESIZE                                     EQU     26
CURVECAPS                                       EQU     28
LINECAPS                                        EQU     30
POLYGONALCAPS                                   EQU     32
TEXTCAPS                                        EQU     34
CLIPCAPS                                        EQU     36
RASTERCAPS                                      EQU     38
ASPECTX                                         EQU     40
ASPECTY                                         EQU     42
ASPECTXY                                        EQU     44

IF (NTDDI_VERSION GE NTDDI_WIN2K)
    SHADEBLENDCAPS                              EQU     120
    COLORMGMTCAPS                               EQU     121
ENDIF

LOGPIXELSX                                      EQU     88
LOGPIXELSY                                      EQU     90

SIZEPALETTE                                     EQU     104
NUMRESERVED                                     EQU     106
COLORRES                                        EQU     108

PHYSICALWIDTH                                   EQU     110
PHYSICALHEIGHT                                  EQU     111
PHYSICALOFFSETX                                 EQU     112
PHYSICALOFFSETY                                 EQU     113
SCALINGFACTORX                                  EQU     114
SCALINGFACTORY                                  EQU     115

VREFRESH                                        EQU     116
DESKTOPVERTRES                                  EQU     117
DESKTOPHORZRES                                  EQU     118
BLTALIGNMENT                                    EQU     119

DT_PLOTTER                                      EQU     0
DT_RASDISPLAY                                   EQU     1
DT_RASPRINTER                                   EQU     2
DT_RASCAMERA                                    EQU     3
DT_CHARSTREAM                                   EQU     4
DT_METAFILE                                     EQU     5
DT_DISPFILE                                     EQU     6

CC_NONE                                         EQU     0
CC_CIRCLES                                      EQU     1
CC_PIE                                          EQU     2
CC_CHORD                                        EQU     4
CC_ELLIPSES                                     EQU     8
CC_WIDE                                         EQU     16
CC_STYLED                                       EQU     32
CC_WIDESTYLED                                   EQU     64
CC_INTERIORS                                    EQU     128
CC_ROUNDRECT                                    EQU     256

LC_NONE                                         EQU     0
LC_POLYLINE                                     EQU     2
LC_MARKER                                       EQU     4
LC_POLYMARKER                                   EQU     8
LC_WIDE                                         EQU     16
LC_STYLED                                       EQU     32
LC_WIDESTYLED                                   EQU     64
LC_INTERIORS                                    EQU     128

PC_NONE                                         EQU     0
PC_POLYGON                                      EQU     1
PC_RECTANGLE                                    EQU     2
PC_WINDPOLYGON                                  EQU     4
PC_TRAPEZOID                                    EQU     4
PC_SCANLINE                                     EQU     8
PC_WIDE                                         EQU     16
PC_STYLED                                       EQU     32
PC_WIDESTYLED                                   EQU     64
PC_INTERIORS                                    EQU     128
PC_POLYPOLYGON                                  EQU     256
PC_PATHS                                        EQU     512

CP_NONE                                         EQU     0
CP_RECTANGLE                                    EQU     1
CP_REGION                                       EQU     2

TC_OP_CHARACTER                                 EQU     000000001H
TC_OP_STROKE                                    EQU     000000002H
TC_CP_STROKE                                    EQU     000000004H
TC_CR_90                                        EQU     000000008H
TC_CR_ANY                                       EQU     000000010H
TC_SF_X_YINDEP                                  EQU     000000020H
TC_SA_DOUBLE                                    EQU     000000040H
TC_SA_INTEGER                                   EQU     000000080H
TC_SA_CONTIN                                    EQU     000000100H
TC_EA_DOUBLE                                    EQU     000000200H
TC_IA_ABLE                                      EQU     000000400H
TC_UA_ABLE                                      EQU     000000800H
TC_SO_ABLE                                      EQU     000001000H
TC_RA_ABLE                                      EQU     000002000H
TC_VA_ABLE                                      EQU     000004000H
TC_RESERVED                                     EQU     000008000H
TC_SCROLLBLT                                    EQU     000010000H

RC_NONE                                         EQU     0
RC_BITBLT                                       EQU     1
RC_BANDING                                      EQU     2
RC_SCALING                                      EQU     4
RC_BITMAP64                                     EQU     8
RC_GDI20_OUTPUT                                 EQU     00010H
RC_GDI20_STATE                                  EQU     00020H
RC_SAVEBITMAP                                   EQU     00040H
RC_DI_BITMAP                                    EQU     00080H
RC_PALETTE                                      EQU     00100H
RC_DIBTODEV                                     EQU     00200H
RC_BIGFONT                                      EQU     00400H
RC_STRETCHBLT                                   EQU     00800H
RC_FLOODFILL                                    EQU     01000H
RC_STRETCHDIB                                   EQU     02000H
RC_OP_DX_OUTPUT                                 EQU     04000H
RC_DEVBITS                                      EQU     08000H

SB_NONE                                         EQU     000000000H
SB_CONST_ALPHA                                  EQU     000000001H
SB_PIXEL_ALPHA                                  EQU     000000002H
SB_PREMULT_ALPHA                                EQU     000000004H

SB_GRAD_RECT                                    EQU     000000010H
SB_GRAD_TRI                                     EQU     000000020H

CM_NONE                                         EQU     00000000H
CM_DEVICE_ICM                                   EQU     00000001H
CM_GAMMA_RAMP                                   EQU     00000002H
CM_CMYK_COLOR                                   EQU     00000004H

DIB_RGB_COLORS                                  EQU     0
DIB_PAL_COLORS                                  EQU     1

SYSPAL_ERROR                                    EQU     0
SYSPAL_STATIC                                   EQU     1
SYSPAL_NOSTATIC                                 EQU     2
SYSPAL_NOSTATIC256                              EQU     3

CBM_INIT                                        EQU     004H

FLOODFILLBORDER                                 EQU     0
FLOODFILLSURFACE                                EQU     1

CCHDEVICENAME                                   EQU     32

CCHFORMNAME                                     EQU     32

IF (NTDDI_VERSION LT NTDDI_WINNT4)
    DM_SPECVERSION                              EQU     00400H
ELSE
    DM_SPECVERSION                              EQU     00401H
ENDIF

DM_ORIENTATION                                  EQU     000000001H
DM_PAPERSIZE                                    EQU     000000002H
DM_PAPERLENGTH                                  EQU     000000004H
DM_PAPERWIDTH                                   EQU     000000008H
DM_SCALE                                        EQU     000000010H
DM_POSITION                                     EQU     000000020H
DM_COPIES                                       EQU     000000100H
DM_DEFAULTSOURCE                                EQU     000000200H
DM_PRINTQUALITY                                 EQU     000000400H
DM_COLOR                                        EQU     000000800H
DM_DUPLEX                                       EQU     000001000H
DM_YRESOLUTION                                  EQU     000002000H
DM_TTOPTION                                     EQU     000004000H
DM_COLLATE                                      EQU     000008000H
DM_FORMNAME                                     EQU     000010000H
DM_LOGPIXELS                                    EQU     000020000H
DM_BITSPERPEL                                   EQU     000040000H
DM_PELSWIDTH                                    EQU     000080000H
DM_PELSHEIGHT                                   EQU     000100000H
DM_DISPLAYFLAGS                                 EQU     000200000H
DM_DISPLAYFREQUENCY                             EQU     000400000H
DM_ICMMETHOD                                    EQU     000800000H
DM_ICMINTENT                                    EQU     001000000H
DM_MEDIATYPE                                    EQU     002000000H
DM_DITHERTYPE                                   EQU     004000000H
DM_PANNINGWIDTH                                 EQU     008000000H
DM_PANNINGHEIGHT                                EQU     010000000H
DM_DISPLAYFIXEDOUTPUT                           EQU     020000000H

DMORIENT_PORTRAIT                               EQU     1
DMORIENT_LANDSCAPE                              EQU     2

DMPAPER_FIRST                                   EQU     DMPAPER_LETTER
DMPAPER_LETTER                                  EQU     1
DMPAPER_LETTERSMALL                             EQU     2
DMPAPER_TABLOID                                 EQU     3
DMPAPER_LEDGER                                  EQU     4
DMPAPER_LEGAL                                   EQU     5
DMPAPER_STATEMENT                               EQU     6
DMPAPER_EXECUTIVE                               EQU     7
DMPAPER_A3                                      EQU     8
DMPAPER_A4                                      EQU     9
DMPAPER_A4SMALL                                 EQU     10
DMPAPER_A5                                      EQU     11
DMPAPER_B4                                      EQU     12
DMPAPER_B5                                      EQU     13
DMPAPER_FOLIO                                   EQU     14
DMPAPER_QUARTO                                  EQU     15
DMPAPER_10X14                                   EQU     16
DMPAPER_11X17                                   EQU     17
DMPAPER_NOTE                                    EQU     18
DMPAPER_ENV_9                                   EQU     19
DMPAPER_ENV_10                                  EQU     20
DMPAPER_ENV_11                                  EQU     21
DMPAPER_ENV_12                                  EQU     22
DMPAPER_ENV_14                                  EQU     23
DMPAPER_CSHEET                                  EQU     24
DMPAPER_DSHEET                                  EQU     25
DMPAPER_ESHEET                                  EQU     26
DMPAPER_ENV_DL                                  EQU     27
DMPAPER_ENV_C5                                  EQU     28
DMPAPER_ENV_C3                                  EQU     29
DMPAPER_ENV_C4                                  EQU     30
DMPAPER_ENV_C6                                  EQU     31
DMPAPER_ENV_C65                                 EQU     32
DMPAPER_ENV_B4                                  EQU     33
DMPAPER_ENV_B5                                  EQU     34
DMPAPER_ENV_B6                                  EQU     35
DMPAPER_ENV_ITALY                               EQU     36
DMPAPER_ENV_MONARCH                             EQU     37
DMPAPER_ENV_PERSONAL                            EQU     38
DMPAPER_FANFOLD_US                              EQU     39
DMPAPER_FANFOLD_STD_GERMAN                      EQU     40
DMPAPER_FANFOLD_LGL_GERMAN                      EQU     41
DMPAPER_ISO_B4                                  EQU     42
DMPAPER_JAPANESE_POSTCARD                       EQU     43
DMPAPER_9X11                                    EQU     44
DMPAPER_10X11                                   EQU     45
DMPAPER_15X11                                   EQU     46
DMPAPER_ENV_INVITE                              EQU     47
DMPAPER_RESERVED_48                             EQU     48
DMPAPER_RESERVED_49                             EQU     49
DMPAPER_LETTER_EXTRA                            EQU     50
DMPAPER_LEGAL_EXTRA                             EQU     51
DMPAPER_TABLOID_EXTRA                           EQU     52
DMPAPER_A4_EXTRA                                EQU     53
DMPAPER_LETTER_TRANSVERSE                       EQU     54
DMPAPER_A4_TRANSVERSE                           EQU     55
DMPAPER_LETTER_EXTRA_TRANSVERSE                 EQU     56
DMPAPER_A_PLUS                                  EQU     57
DMPAPER_B_PLUS                                  EQU     58
DMPAPER_LETTER_PLUS                             EQU     59
DMPAPER_A4_PLUS                                 EQU     60
DMPAPER_A5_TRANSVERSE                           EQU     61
DMPAPER_B5_TRANSVERSE                           EQU     62
DMPAPER_A3_EXTRA                                EQU     63
DMPAPER_A5_EXTRA                                EQU     64
DMPAPER_B5_EXTRA                                EQU     65
DMPAPER_A2                                      EQU     66
DMPAPER_A3_TRANSVERSE                           EQU     67
DMPAPER_A3_EXTRA_TRANSVERSE                     EQU     68
DMPAPER_DBL_JAPANESE_POSTCARD                   EQU     69
DMPAPER_A6                                      EQU     70
DMPAPER_JENV_KAKU2                              EQU     71
DMPAPER_JENV_KAKU3                              EQU     72
DMPAPER_JENV_CHOU3                              EQU     73
DMPAPER_JENV_CHOU4                              EQU     74
DMPAPER_LETTER_ROTATED                          EQU     75
DMPAPER_A3_ROTATED                              EQU     76
DMPAPER_A4_ROTATED                              EQU     77
DMPAPER_A5_ROTATED                              EQU     78
DMPAPER_B4_JIS_ROTATED                          EQU     79
DMPAPER_B5_JIS_ROTATED                          EQU     80
DMPAPER_JAPANESE_POSTCARD_ROTATED               EQU     81
DMPAPER_DBL_JAPANESE_POSTCARD_ROTATED           EQU     82
DMPAPER_A6_ROTATED                              EQU     83
DMPAPER_JENV_KAKU2_ROTATED                      EQU     84
DMPAPER_JENV_KAKU3_ROTATED                      EQU     85
DMPAPER_JENV_CHOU3_ROTATED                      EQU     86
DMPAPER_JENV_CHOU4_ROTATED                      EQU     87
DMPAPER_B6_JIS                                  EQU     88
DMPAPER_B6_JIS_ROTATED                          EQU     89
DMPAPER_12X11                                   EQU     90
DMPAPER_JENV_YOU4                               EQU     91
DMPAPER_JENV_YOU4_ROTATED                       EQU     92
DMPAPER_P16K                                    EQU     93
DMPAPER_P32K                                    EQU     94
DMPAPER_P32KBIG                                 EQU     95
DMPAPER_PENV_1                                  EQU     96
DMPAPER_PENV_2                                  EQU     97
DMPAPER_PENV_3                                  EQU     98
DMPAPER_PENV_4                                  EQU     99
DMPAPER_PENV_5                                  EQU     100
DMPAPER_PENV_6                                  EQU     101
DMPAPER_PENV_7                                  EQU     102
DMPAPER_PENV_8                                  EQU     103
DMPAPER_PENV_9                                  EQU     104
DMPAPER_PENV_10                                 EQU     105
DMPAPER_P16K_ROTATED                            EQU     106
DMPAPER_P32K_ROTATED                            EQU     107
DMPAPER_P32KBIG_ROTATED                         EQU     108
DMPAPER_PENV_1_ROTATED                          EQU     109
DMPAPER_PENV_2_ROTATED                          EQU     110
DMPAPER_PENV_3_ROTATED                          EQU     111
DMPAPER_PENV_4_ROTATED                          EQU     112
DMPAPER_PENV_5_ROTATED                          EQU     113
DMPAPER_PENV_6_ROTATED                          EQU     114
DMPAPER_PENV_7_ROTATED                          EQU     115
DMPAPER_PENV_8_ROTATED                          EQU     116
DMPAPER_PENV_9_ROTATED                          EQU     117
DMPAPER_PENV_10_ROTATED                         EQU     118

IF (NTDDI_VERSION GE NTDDI_WIN2K)
    DMPAPER_LAST                                EQU     DMPAPER_PENV_10_ROTATED
ELSEIF (NTDDI_VERSION GE NTDDI_WINNT4)
    DMPAPER_LAST                                EQU     DMPAPER_A3_EXTRA_TRANSVERSE
ELSE
    DMPAPER_LAST                                EQU     DMPAPER_FANFOLD_LGL_GERMAN
ENDIF

IF (NTDDI_VERSION GE NTDDI_WINXP)
    DMDO_DEFAULT                                EQU     0
    DMDO_90                                     EQU     1
    DMDO_180                                    EQU     2
    DMDO_270                                    EQU     3
    DMDFO_DEFAULT                               EQU     0
    DMDFO_STRETCH                               EQU     1
    DMDFO_CENTER                                EQU     2
ENDIF

DMPAPER_USER                                    EQU     256

DMBIN_FIRST                                     EQU     DMBIN_UPPER
DMBIN_UPPER                                     EQU     1
DMBIN_ONLYONE                                   EQU     1
DMBIN_LOWER                                     EQU     2
DMBIN_MIDDLE                                    EQU     3
DMBIN_MANUAL                                    EQU     4
DMBIN_ENVELOPE                                  EQU     5
DMBIN_ENVMANUAL                                 EQU     6
DMBIN_AUTO                                      EQU     7
DMBIN_TRACTOR                                   EQU     8
DMBIN_SMALLFMT                                  EQU     9
DMBIN_LARGEFMT                                  EQU     10
DMBIN_LARGECAPACITY                             EQU     11
DMBIN_CASSETTE                                  EQU     14
DMBIN_FORMSOURCE                                EQU     15
DMBIN_LAST                                      EQU     DMBIN_FORMSOURCE

DMBIN_USER                                      EQU     256

DMRES_DRAFT                                     EQU     (-1)
DMRES_LOW                                       EQU     (-2)
DMRES_MEDIUM                                    EQU     (-3)
DMRES_HIGH                                      EQU     (-4)

DMCOLOR_MONOCHROME                              EQU     1
DMCOLOR_COLOR                                   EQU     2

DMDUP_SIMPLEX                                   EQU     1
DMDUP_VERTICAL                                  EQU     2
DMDUP_HORIZONTAL                                EQU     3

DMTT_BITMAP                                     EQU     1
DMTT_DOWNLOAD                                   EQU     2
DMTT_SUBDEV                                     EQU     3
DMTT_DOWNLOAD_OUTLINE                           EQU     4

DMCOLLATE_FALSE                                 EQU     0
DMCOLLATE_TRUE                                  EQU     1

DMDISPLAYFLAGS_TEXTMODE                         EQU     000000004H

DMNUP_SYSTEM                                    EQU     1
DMNUP_ONEUP                                     EQU     2

DMICMMETHOD_NONE                                EQU     1
DMICMMETHOD_SYSTEM                              EQU     2
DMICMMETHOD_DRIVER                              EQU     3
DMICMMETHOD_DEVICE                              EQU     4

DMICMMETHOD_USER                                EQU     256

DMICM_SATURATE                                  EQU     1
DMICM_CONTRAST                                  EQU     2
DMICM_COLORIMETRIC                              EQU     3
DMICM_ABS_COLORIMETRIC                          EQU     4

DMICM_USER                                      EQU     256

DMMEDIA_STANDARD                                EQU     1
DMMEDIA_TRANSPARENCY                            EQU     2
DMMEDIA_GLOSSY                                  EQU     3

DMMEDIA_USER                                    EQU     256

DMDITHER_NONE                                   EQU     1
DMDITHER_COARSE                                 EQU     2
DMDITHER_FINE                                   EQU     3
DMDITHER_LINEART                                EQU     4
DMDITHER_ERRORDIFFUSION                         EQU     5
DMDITHER_RESERVED6                              EQU     6
DMDITHER_RESERVED7                              EQU     7
DMDITHER_RESERVED8                              EQU     8
DMDITHER_RESERVED9                              EQU     9
DMDITHER_GRAYSCALE                              EQU     10

DMDITHER_USER                                   EQU     256

DISPLAY_DEVICE_ATTACHED_TO_DESKTOP              EQU     000000001H
DISPLAY_DEVICE_MULTI_DRIVER                     EQU     000000002H
DISPLAY_DEVICE_PRIMARY_DEVICE                   EQU     000000004H
DISPLAY_DEVICE_MIRRORING_DRIVER                 EQU     000000008H
DISPLAY_DEVICE_VGA_COMPATIBLE                   EQU     000000010H
DISPLAY_DEVICE_MODESPRUNED                      EQU     008000000H
IF (NTDDI_VERSION GE NTDDI_WIN2K)
    DISPLAY_DEVICE_ACTIVE                       EQU     000000001H
    DISPLAY_DEVICE_ATTACHED                     EQU     000000002H
    DISPLAY_DEVICE_REMOVABLE                    EQU     000000020H
    DISPLAY_DEVICE_REMOTE                       EQU     004000000H
    DISPLAY_DEVICE_DISCONNECT                   EQU     002000000H
ENDIF
DISPLAY_DEVICE_TS_COMPATIBLE                    EQU     000200000H
IF (NTDDI_VERSION GE NTDDI_VISTA)
    DISPLAY_DEVICE_UNSAFE_MODES_ON              EQU     000080000H
ENDIF

RDH_RECTANGLES                                  EQU     1

SYSRGN                                          EQU     4

GGO_METRICS                                     EQU     0
GGO_BITMAP                                      EQU     1
GGO_NATIVE                                      EQU     2
GGO_BEZIER                                      EQU     3

GGO_GRAY2_BITMAP                                EQU     4
GGO_GRAY4_BITMAP                                EQU     5
GGO_GRAY8_BITMAP                                EQU     6
GGO_GLYPH_INDEX                                 EQU     00080H
GGO_UNHINTED                                    EQU     00100H

TT_POLYGON_TYPE                                 EQU     24

TT_PRIM_LINE                                    EQU     1
TT_PRIM_QSPLINE                                 EQU     2
TT_PRIM_CSPLINE                                 EQU     3

GCP_DBCS                                        EQU     00001H
GCP_REORDER                                     EQU     00002H
GCP_USEKERNING                                  EQU     00008H
GCP_GLYPHSHAPE                                  EQU     00010H
GCP_LIGATE                                      EQU     00020H

GCP_DIACRITIC                                   EQU     00100H
GCP_KASHIDA                                     EQU     00400H
GCP_ERROR                                       EQU     08000H
FLI_MASK                                        EQU     0103BH

GCP_JUSTIFY                                     EQU     000010000H
FLI_GLYPHS                                      EQU     000040000H
GCP_CLASSIN                                     EQU     000080000H
GCP_MAXEXTENT                                   EQU     000100000H
GCP_JUSTIFYIN                                   EQU     000200000H
GCP_DISPLAYZWG                                  EQU     000400000H
GCP_SYMSWAPOFF                                  EQU     000800000H
GCP_NUMERICOVERRIDE                             EQU     001000000H
GCP_NEUTRALOVERRIDE                             EQU     002000000H
GCP_NUMERICSLATIN                               EQU     004000000H
GCP_NUMERICSLOCAL                               EQU     008000000H

GCPCLASS_LATIN                                  EQU     1
GCPCLASS_HEBREW                                 EQU     2
GCPCLASS_ARABIC                                 EQU     2
GCPCLASS_NEUTRAL                                EQU     3
GCPCLASS_LOCALNUMBER                            EQU     4
GCPCLASS_LATINNUMBER                            EQU     5
GCPCLASS_LATINNUMERICTERMINATOR                 EQU     6
GCPCLASS_LATINNUMERICSEPARATOR                  EQU     7
GCPCLASS_NUMERICSEPARATOR                       EQU     8
GCPCLASS_PREBOUNDLTR                            EQU     080H
GCPCLASS_PREBOUNDRTL                            EQU     040H
GCPCLASS_POSTBOUNDLTR                           EQU     020H
GCPCLASS_POSTBOUNDRTL                           EQU     010H

GCPGLYPH_LINKBEFORE                             EQU     08000H
GCPGLYPH_LINKAFTER                              EQU     04000H

TT_AVAILABLE                                    EQU     00001H
TT_ENABLED                                      EQU     00002H

PFD_TYPE_RGBA                                   EQU     0
PFD_TYPE_COLORINDEX                             EQU     1

PFD_MAIN_PLANE                                  EQU     0
PFD_OVERLAY_PLANE                               EQU     1
PFD_UNDERLAY_PLANE                              EQU     (-1)

PFD_DOUBLEBUFFER                                EQU     000000001H
PFD_STEREO                                      EQU     000000002H
PFD_DRAW_TO_WINDOW                              EQU     000000004H
PFD_DRAW_TO_BITMAP                              EQU     000000008H
PFD_SUPPORT_GDI                                 EQU     000000010H
PFD_SUPPORT_OPENGL                              EQU     000000020H
PFD_GENERIC_FORMAT                              EQU     000000040H
PFD_NEED_PALETTE                                EQU     000000080H
PFD_NEED_SYSTEM_PALETTE                         EQU     000000100H
PFD_SWAP_EXCHANGE                               EQU     000000200H
PFD_SWAP_COPY                                   EQU     000000400H
PFD_SWAP_LAYER_BUFFERS                          EQU     000000800H
PFD_GENERIC_ACCELERATED                         EQU     000001000H
PFD_SUPPORT_DIRECTDRAW                          EQU     000002000H

PFD_DEPTH_DONTCARE                              EQU     020000000H
PFD_DOUBLEBUFFER_DONTCARE                       EQU     040000000H
PFD_STEREO_DONTCARE                             EQU     080000000H

DM_UPDATE                                       EQU     1
DM_COPY                                         EQU     2
DM_PROMPT                                       EQU     4
DM_MODIFY                                       EQU     8

DM_IN_BUFFER                                    EQU     DM_MODIFY
DM_IN_PROMPT                                    EQU     DM_PROMPT
DM_OUT_BUFFER                                   EQU     DM_COPY
DM_OUT_DEFAULT                                  EQU     DM_UPDATE

DC_FIELDS                                       EQU     1
DC_PAPERS                                       EQU     2
DC_PAPERSIZE                                    EQU     3
DC_MINEXTENT                                    EQU     4
DC_MAXEXTENT                                    EQU     5
DC_BINS                                         EQU     6
DC_DUPLEX                                       EQU     7
DC_SIZE                                         EQU     8
DC_EXTRA                                        EQU     9
DC_VERSION                                      EQU     10
DC_DRIVER                                       EQU     11
DC_BINNAMES                                     EQU     12
DC_ENUMRESOLUTIONS                              EQU     13
DC_FILEDEPENDENCIES                             EQU     14
DC_TRUETYPE                                     EQU     15
DC_PAPERNAMES                                   EQU     16
DC_ORIENTATION                                  EQU     17
DC_COPIES                                       EQU     18
DC_BINADJUST                                    EQU     19
DC_EMF_COMPLIANT                                EQU     20
DC_DATATYPE_PRODUCED                            EQU     21
DC_COLLATE                                      EQU     22
DC_MANUFACTURER                                 EQU     23
DC_MODEL                                        EQU     24
DC_PERSONALITY                                  EQU     25
DC_PRINTRATE                                    EQU     26
DC_PRINTRATEUNIT                                EQU     27

PRINTRATEUNIT_PPM                               EQU     1
PRINTRATEUNIT_CPS                               EQU     2
PRINTRATEUNIT_LPM                               EQU     3
PRINTRATEUNIT_IPM                               EQU     4

DC_PRINTERMEM                                   EQU     28
DC_MEDIAREADY                                   EQU     29
DC_STAPLE                                       EQU     30
DC_PRINTRATEPPM                                 EQU     31
DC_COLORDEVICE                                  EQU     32
DC_NUP                                          EQU     33

IF (NTDDI_VERSION GE NTDDI_WIN2K)
    DC_MEDIATYPENAMES                           EQU     34
    DC_MEDIATYPES                               EQU     35
ENDIF

DCTT_BITMAP                                     EQU     00000001H
DCTT_DOWNLOAD                                   EQU     00000002H
DCTT_SUBDEV                                     EQU     00000004H
DCTT_DOWNLOAD_OUTLINE                           EQU     00000008H

DCBA_FACEUPNONE                                 EQU     00000H
DCBA_FACEUPCENTER                               EQU     00001H
DCBA_FACEUPLEFT                                 EQU     00002H
DCBA_FACEUPRIGHT                                EQU     00003H
DCBA_FACEDOWNNONE                               EQU     00100H
DCBA_FACEDOWNCENTER                             EQU     00101H
DCBA_FACEDOWNLEFT                               EQU     00102H
DCBA_FACEDOWNRIGHT                              EQU     00103H

GS_8BIT_INDICES                                 EQU     000000001H

GGI_MARK_NONEXISTING_GLYPHS                     EQU     00001H

STAMP_DESIGNVECTOR                              EQU     (8000000H + 64H + 07600H)
STAMP_AXESLIST                                  EQU     (8000000H + 61H + 03100H)
MM_MAX_NUMAXES                                  EQU     16

FR_PRIVATE                                      EQU     010H
FR_NOT_ENUM                                     EQU     020H

MM_MAX_AXES_NAMELEN                             EQU     16

AC_SRC_OVER                                     EQU     000H
AC_SRC_ALPHA                                    EQU     001H

GRADIENT_FILL_RECT_H                            EQU     000000000H
GRADIENT_FILL_RECT_V                            EQU     000000001H
GRADIENT_FILL_TRIANGLE                          EQU     000000002H
GRADIENT_FILL_OP_FLAG                           EQU     0000000FFH

CA_NEGATIVE                                     EQU     00001H
CA_LOG_FILTER                                   EQU     00002H

ILLUMINANT_DEVICE_DEFAULT                       EQU     0
ILLUMINANT_A                                    EQU     1
ILLUMINANT_B                                    EQU     2
ILLUMINANT_C                                    EQU     3
ILLUMINANT_D50                                  EQU     4
ILLUMINANT_D55                                  EQU     5
ILLUMINANT_D65                                  EQU     6
ILLUMINANT_D75                                  EQU     7
ILLUMINANT_F2                                   EQU     8
ILLUMINANT_MAX_INDEX                            EQU     ILLUMINANT_F2

ILLUMINANT_TUNGSTEN                             EQU     ILLUMINANT_A
ILLUMINANT_DAYLIGHT                             EQU     ILLUMINANT_C
ILLUMINANT_FLUORESCENT                          EQU     ILLUMINANT_F2
ILLUMINANT_NTSC                                 EQU     ILLUMINANT_C

RGB_GAMMA_MIN                                   EQU     2500
RGB_GAMMA_MAX                                   EQU     65000

REFERENCE_WHITE_MIN                             EQU     6000
REFERENCE_WHITE_MAX                             EQU     10000
REFERENCE_BLACK_MIN                             EQU     0
REFERENCE_BLACK_MAX                             EQU     4000

COLOR_ADJ_MIN                                   EQU     (-100)
COLOR_ADJ_MAX                                   EQU     100

DI_APPBANDING                                   EQU     000000001H
DI_ROPS_READ_DESTINATION                        EQU     000000002H

FONTMAPPER_MAX                                  EQU     10

ICM_OFF                                         EQU     1
ICM_ON                                          EQU     2
ICM_QUERY                                       EQU     3
ICM_DONE_OUTSIDEDC                              EQU     4

ENHMETA_SIGNATURE                               EQU     0464D4520H
ENHMETA_STOCK_OBJECT                            EQU     080000000H

EMR_HEADER                                      EQU     1
EMR_POLYBEZIER                                  EQU     2
EMR_POLYGON                                     EQU     3
EMR_POLYLINE                                    EQU     4
EMR_POLYBEZIERTO                                EQU     5
EMR_POLYLINETO                                  EQU     6
EMR_POLYPOLYLINE                                EQU     7
EMR_POLYPOLYGON                                 EQU     8
EMR_SETWINDOWEXTEX                              EQU     9
EMR_SETWINDOWORGEX                              EQU     10
EMR_SETVIEWPORTEXTEX                            EQU     11
EMR_SETVIEWPORTORGEX                            EQU     12
EMR_SETBRUSHORGEX                               EQU     13
EMR_EOF                                         EQU     14
EMR_SETPIXELV                                   EQU     15
EMR_SETMAPPERFLAGS                              EQU     16
EMR_SETMAPMODE                                  EQU     17
EMR_SETBKMODE                                   EQU     18
EMR_SETPOLYFILLMODE                             EQU     19
EMR_SETROP2                                     EQU     20
EMR_SETSTRETCHBLTMODE                           EQU     21
EMR_SETTEXTALIGN                                EQU     22
EMR_SETCOLORADJUSTMENT                          EQU     23
EMR_SETTEXTCOLOR                                EQU     24
EMR_SETBKCOLOR                                  EQU     25
EMR_OFFSETCLIPRGN                               EQU     26
EMR_MOVETOEX                                    EQU     27
EMR_SETMETARGN                                  EQU     28
EMR_EXCLUDECLIPRECT                             EQU     29
EMR_INTERSECTCLIPRECT                           EQU     30
EMR_SCALEVIEWPORTEXTEX                          EQU     31
EMR_SCALEWINDOWEXTEX                            EQU     32
EMR_SAVEDC                                      EQU     33
EMR_RESTOREDC                                   EQU     34
EMR_SETWORLDTRANSFORM                           EQU     35
EMR_MODIFYWORLDTRANSFORM                        EQU     36
EMR_SELECTOBJECT                                EQU     37
EMR_CREATEPEN                                   EQU     38
EMR_CREATEBRUSHINDIRECT                         EQU     39
EMR_DELETEOBJECT                                EQU     40
EMR_ANGLEARC                                    EQU     41
EMR_ELLIPSE                                     EQU     42
EMR_RECTANGLE                                   EQU     43
EMR_ROUNDRECT                                   EQU     44
EMR_ARC                                         EQU     45
EMR_CHORD                                       EQU     46
EMR_PIE                                         EQU     47
EMR_SELECTPALETTE                               EQU     48
EMR_CREATEPALETTE                               EQU     49
EMR_SETPALETTEENTRIES                           EQU     50
EMR_RESIZEPALETTE                               EQU     51
EMR_REALIZEPALETTE                              EQU     52
EMR_EXTFLOODFILL                                EQU     53
EMR_LINETO                                      EQU     54
EMR_ARCTO                                       EQU     55
EMR_POLYDRAW                                    EQU     56
EMR_SETARCDIRECTION                             EQU     57
EMR_SETMITERLIMIT                               EQU     58
EMR_BEGINPATH                                   EQU     59
EMR_ENDPATH                                     EQU     60
EMR_CLOSEFIGURE                                 EQU     61
EMR_FILLPATH                                    EQU     62
EMR_STROKEANDFILLPATH                           EQU     63
EMR_STROKEPATH                                  EQU     64
EMR_FLATTENPATH                                 EQU     65
EMR_WIDENPATH                                   EQU     66
EMR_SELECTCLIPPATH                              EQU     67
EMR_ABORTPATH                                   EQU     68

EMR_GDICOMMENT                                  EQU     70
EMR_FILLRGN                                     EQU     71
EMR_FRAMERGN                                    EQU     72
EMR_INVERTRGN                                   EQU     73
EMR_PAINTRGN                                    EQU     74
EMR_EXTSELECTCLIPRGN                            EQU     75
EMR_BITBLT                                      EQU     76
EMR_STRETCHBLT                                  EQU     77
EMR_MASKBLT                                     EQU     78
EMR_PLGBLT                                      EQU     79
EMR_SETDIBITSTODEVICE                           EQU     80
EMR_STRETCHDIBITS                               EQU     81
EMR_EXTCREATEFONTINDIRECTW                      EQU     82
EMR_EXTTEXTOUTA                                 EQU     83
EMR_EXTTEXTOUTW                                 EQU     84
EMR_POLYBEZIER16                                EQU     85
EMR_POLYGON16                                   EQU     86
EMR_POLYLINE16                                  EQU     87
EMR_POLYBEZIERTO16                              EQU     88
EMR_POLYLINETO16                                EQU     89
EMR_POLYPOLYLINE16                              EQU     90
EMR_POLYPOLYGON16                               EQU     91
EMR_POLYDRAW16                                  EQU     92
EMR_CREATEMONOBRUSH                             EQU     93
EMR_CREATEDIBPATTERNBRUSHPT                     EQU     94
EMR_EXTCREATEPEN                                EQU     95
EMR_POLYTEXTOUTA                                EQU     96
EMR_POLYTEXTOUTW                                EQU     97

EMR_SETICMMODE                                  EQU     98
EMR_CREATECOLORSPACE                            EQU     99
EMR_SETCOLORSPACE                               EQU     100
EMR_DELETECOLORSPACE                            EQU     101
EMR_GLSRECORD                                   EQU     102
EMR_GLSBOUNDEDRECORD                            EQU     103
EMR_PIXELFORMAT                                 EQU     104
EMR_RESERVED_105                                EQU     105
EMR_RESERVED_106                                EQU     106
EMR_RESERVED_107                                EQU     107
EMR_RESERVED_108                                EQU     108
EMR_RESERVED_109                                EQU     109
EMR_RESERVED_110                                EQU     110

EMR_DRAWESCAPE                                  EQU     105
EMR_EXTESCAPE                                   EQU     106
EMR_STARTDOC                                    EQU     107
EMR_SMALLTEXTOUT                                EQU     108
EMR_FORCEUFIMAPPING                             EQU     109
EMR_NAMEDESCAPE                                 EQU     110
EMR_COLORCORRECTPALETTE                         EQU     111
EMR_SETICMPROFILEA                              EQU     112
EMR_SETICMPROFILEW                              EQU     113
EMR_ALPHABLEND                                  EQU     114
EMR_ALPHADIBBLEND                               EQU     115
EMR_TRANSPARENTBLT                              EQU     116
EMR_TRANSPARENTDIB                              EQU     117
EMR_GRADIENTFILL                                EQU     118
EMR_RESERVED_119                                EQU     119
EMR_RESERVED_120                                EQU     120
EMR_SETLINKEDUFIS                               EQU     119
EMR_SETTEXTJUSTIFICATION                        EQU     120
EMR_COLORMATCHTOTARGETW                         EQU     121
EMR_CREATECOLORSPACEW                           EQU     122

EMR_MIN                                         EQU     1
EMR_MAX                                         EQU     122

SETICMPROFILE_EMBEDED                           EQU     000000001H
CREATECOLORSPACE_EMBEDED                        EQU     000000001H
COLORMATCHTOTARGET_EMBEDED                      EQU     000000001H

GDICOMMENT_IDENTIFIER                           EQU     043494447H
GDICOMMENT_WINDOWS_METAFILE                     EQU     080000001H
GDICOMMENT_BEGINGROUP                           EQU     000000002H
GDICOMMENT_ENDGROUP                             EQU     000000003H
GDICOMMENT_MULTIFORMATS                         EQU     040000004H
GDICOMMENT_UNICODE_STRING                       EQU     000000040H
GDICOMMENT_UNICODE_END                          EQU     000000080H
EPS_SIGNATURE                                   EQU     046535045H

WGL_FONT_LINES                                  EQU     0
WGL_FONT_POLYGONS                               EQU     1

LPD_DOUBLEBUFFER                                EQU     000000001H
LPD_STEREO                                      EQU     000000002H
LPD_SUPPORT_GDI                                 EQU     000000010H
LPD_SUPPORT_OPENGL                              EQU     000000020H
LPD_SHARE_DEPTH                                 EQU     000000040H
LPD_SHARE_STENCIL                               EQU     000000080H
LPD_SHARE_ACCUM                                 EQU     000000100H
LPD_SWAP_EXCHANGE                               EQU     000000200H
LPD_SWAP_COPY                                   EQU     000000400H
LPD_TRANSPARENT                                 EQU     000001000H

LPD_TYPE_RGBA                                   EQU     0
LPD_TYPE_COLORINDEX                             EQU     1

WGL_SWAP_MAIN_PLANE                             EQU     000000001H
WGL_SWAP_OVERLAY1                               EQU     000000002H
WGL_SWAP_OVERLAY2                               EQU     000000004H
WGL_SWAP_OVERLAY3                               EQU     000000008H
WGL_SWAP_OVERLAY4                               EQU     000000010H
WGL_SWAP_OVERLAY5                               EQU     000000020H
WGL_SWAP_OVERLAY6                               EQU     000000040H
WGL_SWAP_OVERLAY7                               EQU     000000080H
WGL_SWAP_OVERLAY8                               EQU     000000100H
WGL_SWAP_OVERLAY9                               EQU     000000200H
WGL_SWAP_OVERLAY10                              EQU     000000400H
WGL_SWAP_OVERLAY11                              EQU     000000800H
WGL_SWAP_OVERLAY12                              EQU     000001000H
WGL_SWAP_OVERLAY13                              EQU     000002000H
WGL_SWAP_OVERLAY14                              EQU     000004000H
WGL_SWAP_OVERLAY15                              EQU     000008000H
WGL_SWAP_UNDERLAY1                              EQU     000010000H
WGL_SWAP_UNDERLAY2                              EQU     000020000H
WGL_SWAP_UNDERLAY3                              EQU     000040000H
WGL_SWAP_UNDERLAY4                              EQU     000080000H
WGL_SWAP_UNDERLAY5                              EQU     000100000H
WGL_SWAP_UNDERLAY6                              EQU     000200000H
WGL_SWAP_UNDERLAY7                              EQU     000400000H
WGL_SWAP_UNDERLAY8                              EQU     000800000H
WGL_SWAP_UNDERLAY9                              EQU     001000000H
WGL_SWAP_UNDERLAY10                             EQU     002000000H
WGL_SWAP_UNDERLAY11                             EQU     004000000H
WGL_SWAP_UNDERLAY12                             EQU     008000000H
WGL_SWAP_UNDERLAY13                             EQU     010000000H
WGL_SWAP_UNDERLAY14                             EQU     020000000H
WGL_SWAP_UNDERLAY15                             EQU     040000000H

WGL_SWAPMULTIPLE_MAX                            EQU     16

DISPLAYCONFIG_MAXPATH                           EQU     1024

DISPLAYCONFIG_OUTPUT_TECHNOLOGY_OTHER           EQU     (-1)
DISPLAYCONFIG_OUTPUT_TECHNOLOGY_HD15            EQU     0
DISPLAYCONFIG_OUTPUT_TECHNOLOGY_SVIDEO          EQU     1
DISPLAYCONFIG_OUTPUT_TECHNOLOGY_COMPOSITE_VIDEO EQU     2
DISPLAYCONFIG_OUTPUT_TECHNOLOGY_COMPONENT_VIDEO EQU     3
DISPLAYCONFIG_OUTPUT_TECHNOLOGY_DVI             EQU     4
DISPLAYCONFIG_OUTPUT_TECHNOLOGY_HDMI            EQU     5
DISPLAYCONFIG_OUTPUT_TECHNOLOGY_LVDS            EQU     6
DISPLAYCONFIG_OUTPUT_TECHNOLOGY_D_JPN           EQU     8
DISPLAYCONFIG_OUTPUT_TECHNOLOGY_SDI             EQU     9
DISPLAYCONFIG_OUTPUT_TECHNOLOGY_DISPLAYPORT_EXTERNAL EQU 10
DISPLAYCONFIG_OUTPUT_TECHNOLOGY_DISPLAYPORT_EMBEDDED EQU 11
DISPLAYCONFIG_OUTPUT_TECHNOLOGY_UDI_EXTERNAL    EQU     12
DISPLAYCONFIG_OUTPUT_TECHNOLOGY_UDI_EMBEDDED    EQU     13
DISPLAYCONFIG_OUTPUT_TECHNOLOGY_SDTVDONGLE      EQU     14
DISPLAYCONFIG_OUTPUT_TECHNOLOGY_INTERNAL        EQU     080000000H
DISPLAYCONFIG_OUTPUT_TECHNOLOGY_FORCE_UINT32    EQU     0FFFFFFFFH

DISPLAYCONFIG_SCANLINE_ORDERING_UNSPECIFIED     EQU     0
DISPLAYCONFIG_SCANLINE_ORDERING_PROGRESSIVE     EQU     1
DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED      EQU     2
DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED_UPPERFIELDFIRST EQU DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED
DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED_LOWERFIELDFIRST EQU 3
DISPLAYCONFIG_SCANLINE_ORDERING_FORCE_UINT32    EQU     0FFFFFFFFH

DISPLAYCONFIG_SCALING_IDENTITY                  EQU     1
DISPLAYCONFIG_SCALING_CENTERED                  EQU     2
DISPLAYCONFIG_SCALING_STRETCHED                 EQU     3
DISPLAYCONFIG_SCALING_ASPECTRATIOCENTEREDMAX    EQU     4
DISPLAYCONFIG_SCALING_CUSTOM                    EQU     5
DISPLAYCONFIG_SCALING_PREFERRED                 EQU     128
DISPLAYCONFIG_SCALING_FORCE_UINT32              EQU     0FFFFFFFFH

DISPLAYCONFIG_ROTATION_IDENTITY                 EQU     1
DISPLAYCONFIG_ROTATION_ROTATE90                 EQU     2
DISPLAYCONFIG_ROTATION_ROTATE180                EQU     3
DISPLAYCONFIG_ROTATION_ROTATE270                EQU     4
DISPLAYCONFIG_ROTATION_FORCE_UINT32             EQU     0FFFFFFFFH

DISPLAYCONFIG_MODE_INFO_TYPE_SOURCE             EQU     1
DISPLAYCONFIG_MODE_INFO_TYPE_TARGET             EQU     2
DISPLAYCONFIG_MODE_INFO_TYPE_FORCE_UINT32       EQU     0FFFFFFFFH

DISPLAYCONFIG_PIXELFORMAT_8BPP                  EQU     1
DISPLAYCONFIG_PIXELFORMAT_16BPP                 EQU     2
DISPLAYCONFIG_PIXELFORMAT_24BPP                 EQU     3
DISPLAYCONFIG_PIXELFORMAT_32BPP                 EQU     4
DISPLAYCONFIG_PIXELFORMAT_NONGDI                EQU     5
DISPLAYCONFIG_PIXELFORMAT_FORCE_UINT32          EQU     0FFFFFFFFH

DISPLAYCONFIG_PATH_MODE_IDX_INVALID             EQU     0FFFFFFFFH

DISPLAYCONFIG_SOURCE_IN_USE                     EQU     000000001H

DISPLAYCONFIG_TARGET_IN_USE                     EQU     000000001H
DISPLAYCONFIG_TARGET_FORCIBLE                   EQU     000000002H
DISPLAYCONFIG_TARGET_FORCED_AVAILABILITY_BOOT   EQU     000000004H
DISPLAYCONFIG_TARGET_FORCED_AVAILABILITY_PATH   EQU     000000008H
DISPLAYCONFIG_TARGET_FORCED_AVAILABILITY_SYSTEM EQU     000000010H

DISPLAYCONFIG_PATH_ACTIVE                       EQU     000000001H

DISPLAYCONFIG_TOPOLOGY_INTERNAL                 EQU     000000001H
DISPLAYCONFIG_TOPOLOGY_CLONE                    EQU     000000002H
DISPLAYCONFIG_TOPOLOGY_EXTEND                   EQU     000000004H
DISPLAYCONFIG_TOPOLOGY_EXTERNAL                 EQU     000000008H
DISPLAYCONFIG_TOPOLOGY_FORCE_UINT32             EQU     0FFFFFFFFH

DISPLAYCONFIG_DEVICE_INFO_GET_SOURCE_NAME       EQU     1
DISPLAYCONFIG_DEVICE_INFO_GET_TARGET_NAME       EQU     2
DISPLAYCONFIG_DEVICE_INFO_GET_TARGET_PREFERRED_MODE EQU 3
DISPLAYCONFIG_DEVICE_INFO_GET_ADAPTER_NAME      EQU     4
DISPLAYCONFIG_DEVICE_INFO_SET_TARGET_PERSISTENCE EQU    5
DISPLAYCONFIG_DEVICE_INFO_FORCE_UINT32          EQU     0FFFFFFFFH

QDC_ALL_PATHS                                   EQU     000000001H
QDC_ONLY_ACTIVE_PATHS                           EQU     000000002H
QDC_DATABASE_CURRENT                            EQU     000000004H

SDC_TOPOLOGY_INTERNAL                           EQU     000000001H
SDC_TOPOLOGY_CLONE                              EQU     000000002H
SDC_TOPOLOGY_EXTEND                             EQU     000000004H
SDC_TOPOLOGY_EXTERNAL                           EQU     000000008H
SDC_TOPOLOGY_SUPPLIED                           EQU     000000010H
SDC_USE_DATABASE_CURRENT                        EQU     (SDC_TOPOLOGY_INTERNAL OR SDC_TOPOLOGY_CLONE OR SDC_TOPOLOGY_EXTEND OR SDC_TOPOLOGY_EXTERNAL)

SDC_USE_SUPPLIED_DISPLAY_CONFIG                 EQU     000000020H
SDC_VALIDATE                                    EQU     000000040H
SDC_APPLY                                       EQU     000000080H
SDC_NO_OPTIMIZATION                             EQU     000000100H
SDC_SAVE_TO_DATABASE                            EQU     000000200H
SDC_ALLOW_CHANGES                               EQU     000000400H
SDC_PATH_PERSIST_IF_REQUIRED                    EQU     000000800H
SDC_FORCE_MODE_ENUMERATION                      EQU     000001000H
SDC_ALLOW_PATH_ORDER_CHANGES                    EQU     000002000H

;======================================== Structures ======================================;
IFNDEF MAX_PATH
    MAX_PATH                                    EQU     260
ENDIF

DRAWPATRECT STRUCT ALIGNMODE
    ptPosition  POINT <>
    ptSize      POINT <>
    wStyle      DW  ?
    wPattern    DW  ?
DRAWPATRECT ENDS

PSINJECTDATA STRUCT ALIGNMODE 
    DataBytes       DD  ?
    InjectionPoint  DD  ?
    Flags           DD  ?
    Reserved        DD  ?
PSINJECTDATA ENDS

PSFEATURE_OUTPUT STRUCT ALIGNMODE 
    bPageIndependent DD ?
    bSetPageDevice   DD ?
PSFEATURE_OUTPUT ENDS

PSFEATURE_CUSTPAPER STRUCT ALIGNMODE 
    lOrientation    DD  ?
    lWidth          DD  ?
    lHeight         DD  ?
    lWidthOffset    DD  ?
    lHeightOffset   DD  ?
PSFEATURE_CUSTPAPER ENDS

XFORM STRUCT ALIGNMODE
    eM11    DD  ?
    eM12    DD  ?
    eM21    DD  ?
    eM22    DD  ?
    elx     DD  ?
    eDy     DD  ?
XFORM ENDS

BITMAP STRUCT ALIGNMODE
    bmType       DD   ?
    bmWidth      DD   ?
    bmHeight     DD   ?
    bmWidthBytes DD   ?
    bmPlanes     DW   ?
    bmBitsPixel  DW   ?
    bmBits       XPTR ?
BITMAP ENDS

RGBTRIPLE STRUCT ALIGNMODE
    rgbtBlue    DB  ?
    rgbtGreen   DB  ?
    rgbtRed     DB  ?
RGBTRIPLE ENDS

RGBQUAD STRUCT ALIGNMODE
    rgbBlue     DB  ?
    rgbGreen    DB  ?
    rgbRed      DB  ?
    rgbReserved DB  ?
RGBQUAD ENDS

CIEXYZ STRUCT ALIGNMODE
    ciexyzX DD  ?
    ciexyzY DD  ?
    ciexyzZ DD  ?
CIEXYZ ENDS

CIEXYZTRIPLE STRUCT ALIGNMODE
    ciexyzRed   CIEXYZ <>
    ciexyzGreen CIEXYZ <>
    ciexyzBlue  CIEXYZ <>
CIEXYZTRIPLE ENDS

LOGCOLORSPACEA STRUCT ALIGNMODE
    lcsSignature  DD ?
    lcsVersion    DD ?
    lcsSize       DD ?
    lcsCSType     DD ?
    lcsIntent     DD ?
    lcsEndpoints  CIEXYZTRIPLE <>
    lcsGammaRed   DD ?
    lcsGammaGreen DD ?
    lcsGammaBlue  DD ?
    lcsFilename   DB MAX_PATH DUP(?)
LOGCOLORSPACEA ENDS

LOGCOLORSPACEW STRUCT ALIGNMODE
    lcsSignature  DD ?
    lcsVersion    DD ?
    lcsSize       DD ?
    lcsCSType     DD ?
    lcsIntent     DD ?
    lcsEndpoints  CIEXYZTRIPLE <>
    lcsGammaRed   DD ?
    lcsGammaGreen DD ?
    lcsGammaBlue  DD ?
    lcsFilename   DW MAX_PATH DUP(?)
LOGCOLORSPACEW ENDS

BITMAPCOREHEADER STRUCT ALIGNMODE
    bcSize      DD  ?
    bcWidth     DW  ?
    bcHeight    DW  ?
    bcPlanes    DW  ?
    bcBitCount  DW  ?
BITMAPCOREHEADER ENDS

BITMAPINFOHEADER STRUCT ALIGNMODE
    biSize          DD  ?
    biWidth         DD  ?
    biHeight        DD  ?
    biPlanes        DW  ?
    biBitCount      DW  ?
    biCompression   DD  ?
    biSizeImage     DD  ?
    biXPelsPerMeter DD  ?
    biYPelsPerMeter DD  ?
    biClrUsed       DD  ?
    biClrImportant  DD  ?
BITMAPINFOHEADER ENDS

BITMAPV4HEADER STRUCT ALIGNMODE
    bV4Size          DD ?
    bV4Width         DD ?
    bV4Height        DD ?
    bV4Planes        DW ?
    bV4BitCount      DW ?
    bV4V4Compression DD ?
    bV4SizeImage     DD ?
    bV4XPelsPerMeter DD ?
    bV4YPelsPerMeter DD ?
    bV4ClrUsed       DD ?
    bV4ClrImportant  DD ?
    bV4RedMask       DD ?
    bV4GreenMask     DD ?
    bV4BlueMask      DD ?
    bV4AlphaMask     DD ?
    bV4CSType        DD ?
    bV4Endpoints     CIEXYZTRIPLE <>
    bV4GammaRed      DD ?
    bV4GammaGreen    DD ?
    bV4GammaBlue     DD ?
BITMAPV4HEADER ENDS

BITMAPV5HEADER STRUCT ALIGNMODE
    bV5Size          DD ?
    bV5Width         DD ?
    bV5Height        DD ?
    bV5Planes        DW ?
    bV5BitCount      DW ?
    bV5Compression   DD ?
    bV5SizeImage     DD ?
    bV5XPelsPerMeter DD ?
    bV5YPelsPerMeter DD ?
    bV5ClrUsed       DD ?
    bV5ClrImportant  DD ?
    bV5RedMask       DD ?
    bV5GreenMask     DD ?
    bV5BlueMask      DD ?
    bV5AlphaMask     DD ?
    bV5CSType        DD ?
    bV5Endpoints     CIEXYZTRIPLE <>
    bV5GammaRed      DD ?
    bV5GammaGreen    DD ?
    bV5GammaBlue     DD ?
    bV5Intent        DD ?
    bV5ProfileData   DD ?
    bV5ProfileSize   DD ?
    bV5Reserved      DD ?
BITMAPV5HEADER ENDS

BITMAPINFO STRUCT ALIGNMODE
    bmiHeader BITMAPINFOHEADER <>
    bmiColors RGBQUAD <>
BITMAPINFO ENDS

BITMAPCOREINFO STRUCT ALIGNMODE
    bmciHeader BITMAPCOREHEADER <>
    bmciColors RGBTRIPLE <>
BITMAPCOREINFO ENDS

BITMAPFILEHEADER STRUCT ALIGNMODE
    bfType      DW  ?
    bfSize      DD  ?
    bfReserved1 DW  ?
    bfReserved2 DW  ?
    bfOffBits   DD  ?
BITMAPFILEHEADER ENDS

FONTSIGNATURE STRUCT ALIGNMODE
    fsUsb   DD 4 DUP(?)
    fsCsb   DD 2 DUP(?)
FONTSIGNATURE ENDS

CHARSETINFO STRUCT ALIGNMODE
    ciCharset       DD  ?
    ciACP           DD  ?
    _fs             FONTSIGNATURE <>
CHARSETINFO ENDS

LOCALESIGNATURE STRUCT ALIGNMODE
    lsUsb           DD 4 DUP(?)
    lsCsbDefault    DD 2 DUP(?)
    lsCsbSupported  DD 2 DUP(?)
LOCALESIGNATURE ENDS

HANDLETABLE STRUCT ALIGNMODE
    objectHandle    DD 1 DUP(?)
HANDLETABLE ENDS

METARECORD STRUCT ALIGNMODE
    rdSize      DD  ?
    rdFunction  DW  ?
    rdParm      DW 1 DUP(?)
METARECORD ENDS

METAFILEPICT STRUCT ALIGNMODE
    mm   DD ?
    xExt DD ?
    yExt DD ?
    hMF  DD ?
METAFILEPICT ENDS

METAHEADER STRUCT ALIGNMODE
    mtType          DW  ?
    mtHeaderSize    DW  ?
    mtVersion       DW  ?
    mtSize          DD  ?
    mtNoObjects     DW  ?
    mtMaxRecord     DD  ?
    mtNoParameters  DW  ?
METAHEADER ENDS

ENHMETARECORD STRUCT ALIGNMODE
    iType   DD  ?
    nSize   DD  ?
    dParm   DD 1 DUP(?)
ENHMETARECORD ENDS

ENHMETAHEADER STRUCT ALIGNMODE
    iType           DD  ?
    nSize           DD  ?
    rclBounds       RECTL <>
    rclFrame        RECTL <>
    dSignature      DD  ?
    nVersion        DD  ?
    nBytes          DD  ?
    nRecords        DD  ?
    nHandles        DW  ?
    sReserved       DW  ?
    nDescription    DD  ?
    offDescription  DD  ?
    nPalEntries     DD  ?
    szlDevice       SIZEL <>
    szlMillimeters  SIZEL <>
    IF (NTDDI_VERSION GE NTDDI_WINNT4)
        cbPixelFormat   DD  ?
        offPixelFormat  DD  ?
        bOpenGL         DD  ?
    ENDIF
    IF (NTDDI_VERSION GE NTDDI_WIN2K)
        szlMicrometers SIZEL <>
    ENDIF
ENHMETAHEADER ENDS

IFNDEF ENHMETAHEADER3
	ENHMETAHEADER3 STRUCT ALIGNMODE
	    iType           DD  ?
	    nSize           DD  ?
	    rclBounds       RECTL <>
	    rclFrame        RECTL <>
	    dSignature      DD  ?
	    nVersion        DD  ?
	    nBytes          DD  ?
	    nRecords        DD  ?
	    nHandles        DW  ?
	    sReserved       DW  ?
	    nDescription    DD  ?
	    offDescription  DD  ?
	    nPalEntries     DD  ?
	    szlDevice       SIZEL <>
	    szlMillimeters  SIZEL <>
	ENHMETAHEADER3 ENDS
ENDIF

TEXTMETRICA STRUCT ALIGNMODE
    tmHeight            DD  ?
    tmAscent            DD  ?
    tmDescent           DD  ?
    tmInternalLeading   DD  ?
    tmExternalLeading   DD  ?
    tmAveCharWidth      DD  ?
    tmMaxCharWidth      DD  ?
    tmWeight            DD  ?
    tmOverhang          DD  ?
    tmDigitizedAspectX  DD  ?
    tmDigitizedAspectY  DD  ?
    tmFirstChar         DB  ?
    tmLastChar          DB  ?
    tmDefaultChar       DB  ?
    tmBreakChar         DB  ?
    tmItalic            DB  ?
    tmUnderlined        DB  ?
    tmStruckOut         DB  ?
    tmPitchAndFamily    DB  ?
    tmCharSet           DB  ?
TEXTMETRICA ENDS

TEXTMETRICW STRUCT ALIGNMODE
    tmHeight            DD  ?
    tmAscent            DD  ?
    tmDescent           DD  ?
    tmInternalLeading   DD  ?
    tmExternalLeading   DD  ?
    tmAveCharWidth      DD  ?
    tmMaxCharWidth      DD  ?
    tmWeight            DD  ?
    tmOverhang          DD  ?
    tmDigitizedAspectX  DD  ?
    tmDigitizedAspectY  DD  ?
    tmFirstChar         DW  ?
    tmLastChar          DW  ?
    tmDefaultChar       DW  ?
    tmBreakChar         DW  ?
    tmItalic            DB  ?
    tmUnderlined        DB  ?
    tmStruckOut         DB  ?
    tmPitchAndFamily    DB  ?
    tmCharSet           DB  ?
TEXTMETRICW ENDS

NEWTEXTMETRICA STRUCT ALIGNMODE
    tmHeight            DD  ?
    tmAscent            DD  ?
    tmDescent           DD  ?
    tmInternalLeading   DD  ?
    tmExternalLeading   DD  ?
    tmAveCharWidth      DD  ?
    tmMaxCharWidth      DD  ?
    tmWeight            DD  ?
    tmOverhang          DD  ?
    tmDigitizedAspectX  DD  ?
    tmDigitizedAspectY  DD  ?
    tmFirstChar         DB  ?
    tmLastChar          DB  ?
    tmDefaultChar       DB  ?
    tmBreakChar         DB  ?
    tmItalic            DB  ?
    tmUnderlined        DB  ?
    tmStruckOut         DB  ?
    tmPitchAndFamily    DB  ?
    tmCharSet           DB  ?
    ntmFlags            DD  ?
    ntmSizeEM           DD  ?
    ntmCellHeight       DD  ?
    ntmAvgWidth         DD  ?
NEWTEXTMETRICA ENDS

NEWTEXTMETRICW STRUCT ALIGNMODE
    tmHeight            DD  ?
    tmAscent            DD  ?
    tmDescent           DD  ?
    tmInternalLeading   DD  ?
    tmExternalLeading   DD  ?
    tmAveCharWidth      DD  ?
    tmMaxCharWidth      DD  ?
    tmWeight            DD  ?
    tmOverhang          DD  ?
    tmDigitizedAspectX  DD  ?
    tmDigitizedAspectY  DD  ?
    tmFirstChar         DW  ?
    tmLastChar          DW  ?
    tmDefaultChar       DW  ?
    tmBreakChar         DW  ?
    tmItalic            DB  ?
    tmUnderlined        DB  ?
    tmStruckOut         DB  ?
    tmPitchAndFamily    DB  ?
    tmCharSet           DB  ?
    ntmFlags            DD  ?
    ntmSizeEM           DD  ?
    ntmCellHeight       DD  ?
    ntmAvgWidth         DD  ?
NEWTEXTMETRICW ENDS

NEWTEXTMETRICEXA STRUCT ALIGNMODE
    ntmTm       NEWTEXTMETRICA <>
    ntmFontSig  FONTSIGNATURE <>
NEWTEXTMETRICEXA ENDS

NEWTEXTMETRICEXW STRUCT ALIGNMODE
    ntmTm       NEWTEXTMETRICW <>
    ntmFontSig  FONTSIGNATURE <>
NEWTEXTMETRICEXW ENDS

PELARRAY STRUCT ALIGNMODE
    paXCount DD ?
    paYCount DD ?
    paXExt   DD ?
    paYExt   DD ?
    paRGBs   DB ?
PELARRAY ENDS

LOGBRUSH STRUCT ALIGNMODE
    lbStyle DD        ?
    lbColor COLORREF  ?
    lbHatch ULONG_PTR ?
LOGBRUSH ENDS

LOGPEN STRUCT ALIGNMODE
    lopnStyle DD       ?
    lopnWidth POINT    <>
    lopnColor COLORREF ?
LOGPEN ENDS

EXTLOGPEN STRUCT ALIGNMODE
    elpPenStyle   DD ?
    elpWidth      DD ?
    elpBrushStyle DD ?
    elpColor      COLORREF  ?
    elpHatch      ULONG_PTR ?
    elpNumEntries DD ?
    elpStyleEntry DD 1 DUP(?)
EXTLOGPEN ENDS

PALETTEENTRY STRUCT ALIGNMODE
    peRed   DB  ?
    peGreen DB  ?
    peBlue  DB  ?
    peFlags DB  ?
PALETTEENTRY ENDS

LOGPALETTE STRUCT ALIGNMODE
    palVersion      DW  ?
    palNumEntries   DW  ?
    palPalEntry     PALETTEENTRY <>
LOGPALETTE ENDS

IFNDEF LOGFONTA
    LOGFONTA STRUCT ALIGNMODE
        lfHeight         LONG ?
        lfWidth          LONG ?
        lfEscapement     LONG ?
        lfOrientation    LONG ?
        lfWeight         LONG ?
        lfItalic         DB   ?
        lfUnderline      DB   ?
        lfStrikeOut      DB   ?
        lfCharSet        DB   ?
        lfOutPrecision   DB   ?
        lfClipPrecision  DB   ?
        lfQuality        DB   ?
        lfPitchAndFamily DB   ?
        lfFaceName       DB   LF_FACESIZE DUP(?)
    LOGFONTA ENDS
ENDIF

IFNDEF LOGFONTW
    LOGFONTW STRUCT ALIGNMODE
        lfHeight         LONG ?
        lfWidth          LONG ?
        lfEscapement     LONG ?
        lfOrientation    LONG ?
        lfWeight         LONG ?
        lfItalic         DB   ?
        lfUnderline      DB   ?
        lfStrikeOut      DB   ?
        lfCharSet        DB   ?
        lfOutPrecision   DB   ?
        lfClipPrecision  DB   ?
        lfQuality        DB   ?
        lfPitchAndFamily DB   ?
        lfFaceName       DW   LF_FACESIZE DUP(?)
    LOGFONTW ENDS
ENDIF

ENUMLOGFONTA STRUCT ALIGNMODE
    elfLogFont  LOGFONTA <>
    elfFullName DB LF_FULLFACESIZE DUP(?)
    elfStyle    DB LF_FACESIZE DUP(?)
ENUMLOGFONTA ENDS

ENUMLOGFONTW STRUCT ALIGNMODE
    elfLogFont  LOGFONTW <>
    elfFullName DW LF_FULLFACESIZE DUP(?)
    elfStyle    DW LF_FACESIZE DUP(?)
ENUMLOGFONTW ENDS

ENUMLOGFONTEXA STRUCT ALIGNMODE
    elfLogFont  LOGFONTA <>
    elfFullName DB LF_FULLFACESIZE DUP(?)
    elfStyle    DB LF_FACESIZE DUP(?)
    elfScript   DB LF_FACESIZE DUP(?)
ENUMLOGFONTEXA ENDS

ENUMLOGFONTEXW STRUCT ALIGNMODE
    elfLogFont  LOGFONTW <>
    elfFullName DW LF_FULLFACESIZE DUP(?)
    elfStyle    DW LF_FACESIZE DUP(?)
    elfScript   DW LF_FACESIZE DUP(?)
ENUMLOGFONTEXW ENDS

PANOSE STRUCT ALIGNMODE
    bFamilyType      DB ?
    bSerifStyle      DB ?
    bWeight          DB ?
    bProportion      DB ?
    bContrast        DB ?
    bStrokeVariation DB ?
    bArmStyle        DB ?
    bLetterform      DB ?
    bMidline         DB ?
    bXHeight         DB ?
PANOSE ENDS

EXTLOGFONTA STRUCT ALIGNMODE
    elfLogFont   LOGFONTA <>
    elfFullName  DB LF_FULLFACESIZE DUP(?)
    elfStyle     DB LF_FACESIZE DUP(?)
    elfVersion   DD ?
    elfStyleSize DD ?
    elfMatch     DD ?
    elfReserved  DD ?
    elfVendorId  DB ELF_VENDOR_SIZE DUP(?)
    elfCulture   DD ?
    elfPanose    PANOSE <>
EXTLOGFONTA ENDS

EXTLOGFONTW STRUCT ALIGNMODE
    elfLogFont   LOGFONTW <>
    elfFullName  DW LF_FULLFACESIZE DUP(?)
    elfStyle     DW LF_FACESIZE DUP(?)
    elfVersion   DD ?
    elfStyleSize DD ?
    elfMatch     DD ?
    elfReserved  DD ?
    elfVendorId  DB ELF_VENDOR_SIZE DUP(?)
    elfCulture   DD ?
    elfPanose    PANOSE <>
EXTLOGFONTW ENDS

DEVMODEA STRUCT ALIGNMODE
    dmDeviceName    CHAR CCHDEVICENAME DUP(?)
    dmSpecVersion   DW   ?
    dmDriverVersion DW   ?
    dmSize          DW   ?
    dmDriverExtra   DW   ?
    dmFields        DD   ?
    UNION
        STRUCT
            dmOrientation   DW  ?
            dmPaperSize     DW  ?
            dmPaperLength   DW  ?
            dmPaperWidth    DW  ?
            dmScale         DW  ?
            dmCopies        DW  ?
            dmDefaultSource DW  ?
            dmPrintQuality  DW  ?
        ENDS
        STRUCT
            dmPosition           POINTL <>
            dmDisplayOrientation DD     ?
            dmDisplayFixedOutput DD     ?
        ENDS
    ENDS
    dmColor         DW   ?
    dmDuplex        DW   ?
    dmYResolution   DW   ?
    dmTTOption      DW   ?
    dmCollate       DW   ?
    dmFormName      CHAR CCHFORMNAME DUP(?)
    dmLogPixels     DW   ?
    dmBitsPerPel    DD   ?
    dmPelsWidth     DD   ?
    dmPelsHeight    DD   ?
    UNION
        dmDisplayFlags  DD ?
        dmNup           DD ?
    ENDS
    dmDisplayFrequency  DD ?
    dmICMMethod         DD ?
    dmICMIntent         DD ?
    dmMediaType         DD ?
    dmDitherType        DD ?
    dmReserved1         DD ?
    dmReserved2         DD ?
    IF (NTDDI_VERSION GE NTDDI_WINNT4)
        dmPanningWidth  DD ?
        dmPanningHeight DD ?
    ENDIF
DEVMODEA ENDS

DEVMODEW STRUCT ALIGNMODE
    dmDeviceName    WCHAR CCHDEVICENAME DUP(?)
    dmSpecVersion   DW    ?
    dmDriverVersion DW    ?
    dmSize          DW    ?
    dmDriverExtra   DW    ?
    dmFields        DD    ?
    UNION
        STRUCT
            dmOrientation   DW  ?
            dmPaperSize     DW  ?
            dmPaperLength   DW  ?
            dmPaperWidth    DW  ?
            dmScale         DW  ?
            dmCopies        DW  ?
            dmDefaultSource DW  ?
            dmPrintQuality  DW  ?
        ENDS
        STRUCT
            dmPosition           POINTL <>
            dmDisplayOrientation DD     ?
            dmDisplayFixedOutput DD     ?
        ENDS
    ENDS
    dmColor         DW    ?
    dmDuplex        DW    ?
    dmYResolution   DW    ?
    dmTTOption      DW    ?
    dmCollate       DW    ?
    dmFormName      WCHAR CCHFORMNAME DUP(?)
    dmLogPixels     DW    ?
    dmBitsPerPel    DD    ?
    dmPelsWidth     DD    ?
    dmPelsHeight    DD    ?
    UNION
        dmDisplayFlags  DD ?
        dmNup           DD ?
    ENDS
    dmDisplayFrequency  DD ?
    dmICMMethod         DD ?
    dmICMIntent         DD ?
    dmMediaType         DD ?
    dmDitherType        DD ?
    dmReserved1         DD ?
    dmReserved2         DD ?
    IF (NTDDI_VERSION GE NTDDI_WINNT4)
        dmPanningWidth  DD ?
        dmPanningHeight DD ?
    ENDIF
DEVMODEW ENDS

DISPLAY_DEVICEA STRUCT ALIGNMODE
    cb           DD ?
    DeviceName   DB 32 DUP(?)
    DeviceString DB 128 DUP(?)
    StateFlags   DD ?
DISPLAY_DEVICEA ENDS

DISPLAY_DEVICEW STRUCT ALIGNMODE
    cb           DD ?
    DeviceName   DW 32 DUP(?)
    DeviceString DW 128 DUP(?)
    StateFlags   DD ?
DISPLAY_DEVICEW ENDS

RGNDATAHEADER STRUCT ALIGNMODE
    dwSize   DD ?
    iType    DD ?
    nCount   DD ?
    nRgnSize DD ?
    rcBound  RECT <>
RGNDATAHEADER ENDS

RGNDATA STRUCT ALIGNMODE
    rdh     RGNDATAHEADER <>
    Buffer  DB 1 DUP(?)
RGNDATA ENDS

ABC STRUCT ALIGNMODE
    abcA DD ?
    abcB DD ?
    abcC DD ?
ABC ENDS

ABCFLOAT STRUCT ALIGNMODE
    abcfA DD ?
    abcfB DD ?
    abcfC DD ?
ABCFLOAT ENDS

OUTLINETEXTMETRICA STRUCT ALIGNMODE
    otmSize                 DD  ?
    otmTextMetrics          TEXTMETRICA <>
    otmFiller               DB  ?
    otmPanoseNumber         PANOSE <>
    otmfsSelection          DD  ?
    otmfsType               DD  ?
    otmsCharSlopeRise       DD  ?
    otmsCharSlopeRun        DD  ?
    otmItalicAngle          DD  ?
    otmEMSquare             DD  ?
    otmAscent               DD  ?
    otmDescent              DD  ?
    otmLineGap              DD  ?
    otmsCapEmHeight         DD  ?
    otmsXHeight             DD  ?
    otmrcFontBox            RECT <>
    otmMacAscent            DD  ?
    otmMacDescent           DD  ?
    otmMacLineGap           DD  ?
    otmusMinimumPPEM        DD  ?
    otmptSubscriptSize      POINT <>
    otmptSubscriptOffset    POINT <>
    otmptSuperscriptSize    POINT <>
    otmptSuperscriptOffset  POINT <>
    otmsStrikeoutSize       DD  ?
    otmsStrikeoutPosition   DD  ?
    otmsUnderscoreSize      DD  ?
    otmsUnderscorePosition  DD  ?
    otmpFamilyName          DD  ?
    otmpFaceName            DD  ?
    otmpStyleName           DD  ?
    otmpFullName            DD  ?
OUTLINETEXTMETRICA ENDS

OUTLINETEXTMETRICW STRUCT ALIGNMODE
    otmSize                 DD  ?
    otmTextMetrics          TEXTMETRICW <>
    otmFiller               DB  ?
    otmPanoseNumber         PANOSE <>
    otmfsSelection          DD  ?
    otmfsType               DD  ?
    otmsCharSlopeRise       DD  ?
    otmsCharSlopeRun        DD  ?
    otmItalicAngle          DD  ?
    otmEMSquare             DD  ?
    otmAscent               DD  ?
    otmDescent              DD  ?
    otmLineGap              DD  ?
    otmsCapEmHeight         DD  ?
    otmsXHeight             DD  ?
    otmrcFontBox            RECT <>
    otmMacAscent            DD  ?
    otmMacDescent           DD  ?
    otmMacLineGap           DD  ?
    otmusMinimumPPEM        DD  ?
    otmptSubscriptSize      POINT <>
    otmptSubscriptOffset    POINT <>
    otmptSuperscriptSize    POINT <>
    otmptSuperscriptOffset  POINT <>
    otmsStrikeoutSize       DD  ?
    otmsStrikeoutPosition   DD  ?
    otmsUnderscoreSize      DD  ?
    otmsUnderscorePosition  DD  ?
    otmpFamilyName          DD  ?
    otmpFaceName            DD  ?
    otmpStyleName           DD  ?
    otmpFullName            DD  ?
OUTLINETEXTMETRICW ENDS

POLYTEXTA STRUCT ALIGNMODE
    x       DD  ?
    y       DD  ?
    n       DD  ?
    lpstr   DD  ?
    uiFlags DD  ?
    _rcl    RECT <>
    pdx     DD  ?
POLYTEXTA ENDS

POLYTEXTW STRUCT ALIGNMODE
    x       DD  ?
    y       DD  ?
    n       DD  ?
    lpstr   DD  ?
    uiFlags DD  ?
    _rcl    RECT <>
    pdx     DD  ?
POLYTEXTW ENDS

FIXED STRUCT ALIGNMODE
    fract   DW  ?
    value   DW  ?
FIXED ENDS

MAT2 STRUCT ALIGNMODE
    eM11 FIXED <>
    eM12 FIXED <>
    eM21 FIXED <>
    eM22 FIXED <>
MAT2 ENDS

GLYPHMETRICS STRUCT ALIGNMODE
    gmBlackBoxX     DD  ?
    gmBlackBoxY     DD  ?
    gmptGlyphOrigin POINT <>
    gmCellIncX      DW  ?
    gmCellIncY      DW  ?
GLYPHMETRICS ENDS

POINTFX STRUCT ALIGNMODE
    x FIXED <>
    y FIXED <>
POINTFX ENDS

TTPOLYCURVE STRUCT ALIGNMODE
    wType   DW  ?
    cpfx    DW  ?
    apfx    POINTFX <>
TTPOLYCURVE ENDS

TTPOLYGONHEADER STRUCT ALIGNMODE
    cb       DD  ?
    dwType   DD  ?
    pfxStart POINTFX <>
TTPOLYGONHEADER ENDS

GCP_RESULTSA STRUCT ALIGNMODE
    lStructSize DD  ?
    lpOutString DD  ?
    lpOrder     DD  ?
    lpDx        DD  ?
    lpCaretPos  DD  ?
    lpClass     DD  ?
    lpGlyphs    DD  ?
    nGlyphs     DD  ?
    nMaxFit     DD  ?
GCP_RESULTSA ENDS

GCP_RESULTSW STRUCT ALIGNMODE
    lStructSize DD  ?
    lpOutString DD  ?
    lpOrder     DD  ?
    lpDx        DD  ?
    lpCaretPos  DD  ?
    lpClass     DD  ?
    lpGlyphs    DD  ?
    nGlyphs     DD  ?
    nMaxFit     DD  ?
GCP_RESULTSW ENDS

RASTERIZER_STATUS STRUCT ALIGNMODE
    nSize       DW  ?
    wFlags      DW  ?
    nLanguageID DW  ?
RASTERIZER_STATUS ENDS

PIXELFORMATDESCRIPTOR STRUCT ALIGNMODE
    nSize           DW  ?
    nVersion        DW  ?
    dwFlags         DD  ?
    iPixelType      DB  ?
    cColorBits      DB  ?
    cRedBits        DB  ?
    cRedShift       DB  ?
    cGreenBits      DB  ?
    cGreenShift     DB  ?
    cBlueBits       DB  ?
    cBlueShift      DB  ?
    cAlphaBits      DB  ?
    cAlphaShift     DB  ?
    cAccumBits      DB  ?
    cAccumRedBits   DB  ?
    cAccumGreenBits DB  ?
    cAccumBlueBits  DB  ?
    cAccumAlphaBits DB  ?
    cDepthBits      DB  ?
    cStencilBits    DB  ?
    cAuxBuffers     DB  ?
    iLayerType      DB  ?
    bReserved       DB  ?
    dwLayerMask     DD  ?
    dwVisibleMask   DD  ?
    dwDamageMask    DD  ?
PIXELFORMATDESCRIPTOR ENDS

WCRANGE STRUCT ALIGNMODE
    wcLow   DW  ?
    cGlyphs DW  ?
WCRANGE ENDS

GLYPHSET STRUCT ALIGNMODE
    cbThis           DD ?
    flAccel          DD ?
    cGlyphsSupported DD ?
    cRanges          DD ?
    ranges           WCRANGE <>
GLYPHSET ENDS

DESIGNVECTOR STRUCT ALIGNMODE
    dvReserved  DD  ?
    dvNumAxes   DD  ?
    dvValues    DD MM_MAX_NUMAXES DUP(?)
DESIGNVECTOR ENDS

AXISINFOA STRUCT ALIGNMODE
    axMinValue  DD  ?
    axMaxValue  DD  ?
    axAxisName  DB MM_MAX_AXES_NAMELEN DUP(?)
AXISINFOA ENDS

AXISINFOW STRUCT ALIGNMODE
    axMinValue  DD  ?
    axMaxValue  DD  ?
    axAxisName  DW MM_MAX_AXES_NAMELEN DUP(?)
AXISINFOW ENDS

AXESLISTA STRUCT ALIGNMODE
    axlReserved DD  ?
    axlNumAxes  DD  ?
    axlAxisInfo AXISINFOA MM_MAX_NUMAXES DUP(<>)
AXESLISTA ENDS

AXESLISTW STRUCT ALIGNMODE
    axlReserved DD  ?
    axlNumAxes  DD  ?
    axlAxisInfo AXISINFOW MM_MAX_NUMAXES DUP(<>)
AXESLISTW ENDS

ENUMLOGFONTEXDVA STRUCT ALIGNMODE
    elfEnumLogfontEx ENUMLOGFONTEXA <>
    elfDesignVector  DESIGNVECTOR <>
ENUMLOGFONTEXDVA ENDS

ENUMLOGFONTEXDVW STRUCT ALIGNMODE
    elfEnumLogfontEx ENUMLOGFONTEXW <>
    elfDesignVector  DESIGNVECTOR <>
ENUMLOGFONTEXDVW ENDS

ENUMTEXTMETRICA STRUCT ALIGNMODE
    etmNewTextMetricEx NEWTEXTMETRICEXA <>
    etmAxesList        AXESLISTA <>
ENUMTEXTMETRICA ENDS

ENUMTEXTMETRICW STRUCT ALIGNMODE
    etmNewTextMetricEx NEWTEXTMETRICEXW <>
    etmAxesList        AXESLISTW <>
ENUMTEXTMETRICW ENDS

TRIVERTEX STRUCT ALIGNMODE
    x       DD  ?
    y       DD  ?
    _Red    DW  ?
    _Green  DW  ?
    _Blue   DW  ?
    Alpha   DW  ?
TRIVERTEX ENDS

GRADIENT_TRIANGLE STRUCT ALIGNMODE
    Vertex1 DD  ?
    Vertex2 DD  ?
    Vertex3 DD  ?
GRADIENT_TRIANGLE ENDS

GRADIENT_RECT STRUCT ALIGNMODE
    UpperLeft   DD  ?
    LowerRight  DD  ?
GRADIENT_RECT ENDS

BLENDFUNCTION STRUCT ALIGNMODE
    BlendOp             DB  ?
    BlendFlags          DB  ?
    SourceConstantAlpha DB  ?
    AlphaFormat         DB  ?
BLENDFUNCTION ENDS

DIBSECTION STRUCT ALIGNMODE
    dsBm        BITMAP <>
    dsBmih      BITMAPINFOHEADER <>
    dsBitfields DD 3 DUP(?)
    dshSection  XWORD  ?
    dsOffset    DD     ?
DIBSECTION ENDS

COLORADJUSTMENT STRUCT ALIGNMODE
    caSize              DW  ?
    caFlags             DW  ?
    caIlluminantIndex   DW  ?
    caRedGamma          DW  ?
    caGreenGamma        DW  ?
    caBlueGamma         DW  ?
    caReferenceBlack    DW  ?
    caReferenceWhite    DW  ?
    caContrast          DW  ?
    caBrightness        DW  ?
    caColorfulness      DW  ?
    caRedGreenTint      DW  ?
COLORADJUSTMENT ENDS

DOCINFOA STRUCT ALIGNMODE
    cbSize       DD  ?
    lpszDocName  DD  ?
    lpszOutput   DD  ?
    IF (NTDDI_VERSION GE NTDDI_WINNT4)
        lpszDatatype DD  ?
        fwType       DD  ?
    ENDIF
DOCINFOA ENDS

DOCINFOW STRUCT ALIGNMODE
    cbSize       DD  ?
    lpszDocName  DD  ?
    lpszOutput   DD  ?
    IF (NTDDI_VERSION GE NTDDI_WINNT4)
        lpszDatatype DD  ?
        fwType       DD  ?
    ENDIF
DOCINFOW ENDS

KERNINGPAIR STRUCT ALIGNMODE
    wFirst      DW  ?
    wSecond     DW  ?
    iKernAmount DD  ?
KERNINGPAIR ENDS

EMR STRUCT ALIGNMODE
    iType DD  ?
    nSize DD  ?
EMR ENDS

ABORTPATH STRUCT ALIGNMODE
    emr EMR <>
ABORTPATH ENDS

EMRTEXT STRUCT ALIGNMODE
    ptlReference POINTL <>
    nChars       DD  ?
    offString    DD  ?
    fOptions     DD  ?
    _rcl         RECTL <>
    offDx        DD  ?
EMRTEXT ENDS

EMRABORTPATH STRUCT ALIGNMODE
    emr EMR <>
EMRABORTPATH ENDS

EMRBEGINPATH STRUCT ALIGNMODE
    emr EMR <>
EMRBEGINPATH ENDS

EMRENDPATH STRUCT ALIGNMODE
    emr EMR <>
EMRENDPATH ENDS

EMRCLOSEFIGURE STRUCT ALIGNMODE
    emr EMR <>
EMRCLOSEFIGURE ENDS

EMRFLATTENPATH STRUCT ALIGNMODE
    emr EMR <>
EMRFLATTENPATH ENDS

EMRWIDENPATH STRUCT ALIGNMODE
    emr EMR <>
EMRWIDENPATH ENDS

EMRSETMETARGN STRUCT ALIGNMODE
    emr EMR <>
EMRSETMETARGN ENDS

EMRSAVEDC STRUCT ALIGNMODE
    emr EMR <>
EMRSAVEDC ENDS

EMRREALIZEPALETTE STRUCT ALIGNMODE
    emr EMR <>
EMRREALIZEPALETTE ENDS

EMRSELECTCLIPPATH STRUCT ALIGNMODE
    emr     EMR <>
    iMode   DD  ?
EMRSELECTCLIPPATH ENDS

EMRSETMITERLIMIT STRUCT ALIGNMODE
    emr         EMR <>
    eMiterLimit DD  ?
EMRSETMITERLIMIT ENDS

EMRRESTOREDC STRUCT ALIGNMODE
    emr         EMR <>
    iRelative   DD  ?
EMRRESTOREDC ENDS

EMRSETARCDIRECTION STRUCT ALIGNMODE
    emr             EMR <>
    iArcDirection   DD  ?
EMRSETARCDIRECTION ENDS

EMRSETMAPPERFLAGS STRUCT ALIGNMODE
    emr     EMR <>
    dwFlags DD  ?
EMRSETMAPPERFLAGS ENDS

EMRSETBKCOLOR STRUCT ALIGNMODE
    emr     EMR <>
    crColor DD  ?
EMRSETBKCOLOR ENDS

EMRSETTEXTCOLOR STRUCT ALIGNMODE
    emr     EMR <>
    crColor DD  ?
EMRSETTEXTCOLOR ENDS

EMRSELECTOBJECT STRUCT ALIGNMODE
    emr      EMR <>
    ihObject DD  ?
EMRSELECTOBJECT ENDS

EMRDELETEOBJECT STRUCT ALIGNMODE
    emr      EMR <>
    ihObject DD  ?
EMRDELETEOBJECT ENDS

EMRSELECTCOLORSPACE STRUCT ALIGNMODE
    emr     EMR <>
    ihCS    DD  ?
EMRSELECTCOLORSPACE ENDS

EMRDELETECOLORSPACE STRUCT ALIGNMODE
    emr     EMR <>
    ihCS    DD  ?
EMRDELETECOLORSPACE ENDS

EMRSELECTPALETTE STRUCT ALIGNMODE
    emr     EMR <>
    ihPal   DD  ?
EMRSELECTPALETTE ENDS

EMRRESIZEPALETTE STRUCT ALIGNMODE
    emr      EMR <>
    ihPal    DD  ?
    cEntries DD  ?
EMRRESIZEPALETTE ENDS

EMRSETPALETTEENTRIES STRUCT ALIGNMODE
    emr         EMR <>
    ihPal       DD  ?
    iStart      DD  ?
    cEntries    DD  ?
    aPalEntries PALETTEENTRY <>
EMRSETPALETTEENTRIES ENDS

EMRSETCOLORADJUSTMENT STRUCT ALIGNMODE
    emr             EMR <>
    ColorAdjustment COLORADJUSTMENT <>
EMRSETCOLORADJUSTMENT ENDS

EMRGDICOMMENT STRUCT ALIGNMODE
    emr     EMR <>
    cbData  DD  ?
    Data    DB 1 DUP(?)
EMRGDICOMMENT ENDS

EMREOF STRUCT ALIGNMODE
    emr             EMR <>
    nPalEntries     DD  ?
    offPalEntries   DD  ?
    nSizeLast       DD  ?
EMREOF ENDS

EMRLINETO STRUCT ALIGNMODE
    emr EMR <>
    ptl POINTL <>
EMRLINETO ENDS

EMRMOVETOEX STRUCT ALIGNMODE
    emr EMR <>
    ptl POINTL <>
EMRMOVETOEX ENDS

EMROFFSETCLIPRGN STRUCT ALIGNMODE
    emr       EMR <>
    ptlOffset POINTL <>
EMROFFSETCLIPRGN ENDS

EMRFILLPATH STRUCT ALIGNMODE
    emr         EMR <>
    rclBounds   RECTL <>
EMRFILLPATH ENDS

EMRSTROKEANDFILLPATH STRUCT ALIGNMODE
    emr         EMR <>
    rclBounds   RECTL <>
EMRSTROKEANDFILLPATH ENDS

EMRSTROKEPATH STRUCT ALIGNMODE
    emr         EMR <>
    rclBounds   RECTL <>
EMRSTROKEPATH ENDS

EMREXCLUDECLIPRECT STRUCT ALIGNMODE
    emr     EMR <>
    rclClip RECTL <>
EMREXCLUDECLIPRECT ENDS

EMRINTERSECTCLIPRECT STRUCT ALIGNMODE
    emr     EMR <>
    rclClip RECTL <>
EMRINTERSECTCLIPRECT ENDS

EMRSETVIEWPORTORGEX STRUCT ALIGNMODE
    emr       EMR <>
    ptlOrigin POINTL <>
EMRSETVIEWPORTORGEX ENDS

EMRSETWINDOWORGEX STRUCT ALIGNMODE
    emr       EMR <>
    ptlOrigin POINTL <>
EMRSETWINDOWORGEX ENDS

EMRSETBRUSHORGEX STRUCT ALIGNMODE
    emr       EMR <>
    ptlOrigin POINTL <>
EMRSETBRUSHORGEX ENDS

EMRSETVIEWPORTEXTEX STRUCT ALIGNMODE
    emr       EMR <>
    szlExtent SIZEL <>
EMRSETVIEWPORTEXTEX ENDS

EMRSETWINDOWEXTEX STRUCT ALIGNMODE
    emr       EMR <>
    szlExtent SIZEL <>
EMRSETWINDOWEXTEX ENDS

EMRSCALEVIEWPORTEXTEX STRUCT ALIGNMODE
    emr     EMR <>
    xNum    DD  ?
    xDenom  DD  ?
    yNum    DD  ?
    yDenom  DD  ?
EMRSCALEVIEWPORTEXTEX ENDS

EMRSCALEWINDOWEXTEX STRUCT ALIGNMODE
    emr     EMR <>
    xNum    DD  ?
    xDenom  DD  ?
    yNum    DD  ?
    yDenom  DD  ?
EMRSCALEWINDOWEXTEX ENDS

EMRSETWORLDTRANSFORM STRUCT ALIGNMODE
    emr     EMR <>
    xform   XFORM <>
EMRSETWORLDTRANSFORM ENDS

EMRMODIFYWORLDTRANSFORM STRUCT ALIGNMODE
    emr     EMR <>
    xform   XFORM <>
    iMode   DD  ?
EMRMODIFYWORLDTRANSFORM ENDS

EMRSETPIXELV STRUCT ALIGNMODE
    emr      EMR <>
    ptlPixel POINTL <>
    crColor  DD  ?
EMRSETPIXELV ENDS

EMREXTFLOODFILL STRUCT ALIGNMODE
    emr      EMR <>
    ptlStart POINTL <>
    crColor  DD  ?
    iMode    DD  ?
EMREXTFLOODFILL ENDS

EMRELLIPSE STRUCT ALIGNMODE
    emr    EMR <>
    rclBox RECTL <>
EMRELLIPSE ENDS

EMRRECTANGLE STRUCT ALIGNMODE
    emr    EMR <>
    rclBox RECTL <>
EMRRECTANGLE ENDS

EMRROUNDRECT STRUCT ALIGNMODE
    emr       EMR <>
    rclBox    RECTL <>
    szlCorner SIZEL <>
EMRROUNDRECT ENDS

EMRARC STRUCT ALIGNMODE
    emr      EMR <>
    rclBox   RECTL <>
    ptlStart POINTL <>
    ptlEnd   POINTL <>
EMRARC ENDS

EMRARCTO STRUCT ALIGNMODE
    emr      EMR <>
    rclBox   RECTL <>
    ptlStart POINTL <>
    ptlEnd   POINTL <>
EMRARCTO ENDS

EMRCHORD STRUCT ALIGNMODE
    emr      EMR <>
    rclBox   RECTL <>
    ptlStart POINTL <>
    ptlEnd   POINTL <>
EMRCHORD ENDS

EMRPIE STRUCT ALIGNMODE
    emr      EMR <>
    rclBox   RECTL <>
    ptlStart POINTL <>
    ptlEnd   POINTL <>
EMRPIE ENDS

EMRANGLEARC STRUCT ALIGNMODE
    emr         EMR <>
    ptlCenter   POINTL <>
    nRadius     DD  ?
    eStartAngle DD  ?
    eSweepAngle DD  ?
EMRANGLEARC ENDS

EMRPOLYLINE STRUCT ALIGNMODE
    emr         EMR <>
    rclBounds   RECTL <>
    cptl        DD  ?
    aptl        POINTL <>
EMRPOLYLINE ENDS

EMRPOLYBEZIER STRUCT ALIGNMODE
    emr         EMR <>
    rclBounds   RECTL <>
    cptl        DD  ?
    aptl        POINTL <>
EMRPOLYBEZIER ENDS

EMRPOLYGON STRUCT ALIGNMODE
    emr         EMR <>
    rclBounds   RECTL <>
    cptl        DD  ?
    aptl        POINTL <>
EMRPOLYGON ENDS

EMRPOLYBEZIERTO STRUCT ALIGNMODE
    emr         EMR <>
    rclBounds   RECTL <>
    cptl        DD  ?
    aptl        POINTL <>
EMRPOLYBEZIERTO ENDS

EMRPOLYLINETO STRUCT ALIGNMODE
    emr         EMR <>
    rclBounds   RECTL <>
    cptl        DD  ?
    aptl        POINTL <>
EMRPOLYLINETO ENDS

EMRPOLYLINE16 STRUCT ALIGNMODE
    emr         EMR <>
    rclBounds   RECTL <>
    cpts        DD  ?
    apts        POINTS <>
EMRPOLYLINE16 ENDS

EMRPOLYBEZIER16 STRUCT ALIGNMODE
    emr         EMR <>
    rclBounds   RECTL <>
    cpts        DD  ?
    apts        POINTS <>
EMRPOLYBEZIER16 ENDS

EMRPOLYGON16 STRUCT ALIGNMODE
    emr         EMR <>
    rclBounds   RECTL <>
    cpts        DD  ?
    apts        POINTS <>
EMRPOLYGON16 ENDS

EMRPOLYBEZIERTO16 STRUCT ALIGNMODE
    emr         EMR <>
    rclBounds   RECTL <>
    cpts        DD  ?
    apts        POINTS <>
EMRPOLYBEZIERTO16 ENDS

EMRPOLYLINETO16 STRUCT ALIGNMODE
    emr         EMR <>
    rclBounds   RECTL <>
    cpts        DD  ?
    apts        POINTS <>
EMRPOLYLINETO16 ENDS

EMRPOLYDRAW STRUCT ALIGNMODE
    emr         EMR <>
    rclBounds   RECTL <>
    cptl        DD  ?
    aptl        POINTL <>
    abTypes     DB  1 DUP(?)
EMRPOLYDRAW ENDS

EMRPOLYDRAW16 STRUCT ALIGNMODE
    emr         EMR <>
    rclBounds   RECTL <>
    cpts        DD  ?
    apts        POINTS <>
    abTypes     DB  1 DUP(?)
EMRPOLYDRAW16 ENDS

EMRPOLYPOLYLINE STRUCT ALIGNMODE
    emr         EMR <>
    rclBounds   RECTL <>
    nPolys      DD  ?
    cptl        DD  ?
    aPolyCounts DD 1 DUP(?)
    aptl        POINTL <>
EMRPOLYPOLYLINE ENDS

EMRPOLYPOLYGON STRUCT ALIGNMODE
    emr         EMR <>
    rclBounds   RECTL <>
    nPolys      DD  ?
    cptl        DD  ?
    aPolyCounts DD 1 DUP(?)
    aptl        POINTL <>
EMRPOLYPOLYGON ENDS

EMRPOLYPOLYLINE16 STRUCT ALIGNMODE
    emr         EMR <>
    rclBounds   RECTL <>
    nPolys      DD  ?
    cpts        DD  ?
    aPolyCounts DD 1 DUP(?)
    apts        POINTS <>
EMRPOLYPOLYLINE16 ENDS

EMRPOLYPOLYGON16 STRUCT ALIGNMODE
    emr         EMR <>
    rclBounds   RECTL <>
    nPolys      DD  ?
    cpts        DD  ?
    aPolyCounts DD 1 DUP(?)
    apts        POINTS <>
EMRPOLYPOLYGON16 ENDS

EMRINVERTRGN STRUCT ALIGNMODE
    emr         EMR <>
    rclBounds   RECTL <>
    cbRgnData   DD  ?
    RgnData     DB 1 DUP(?)
EMRINVERTRGN ENDS

EMRPAINTRGN STRUCT ALIGNMODE
    emr         EMR <>
    rclBounds   RECTL <>
    cbRgnData   DD  ?
    RgnData     DB 1 DUP(?)
EMRPAINTRGN ENDS

EMRFILLRGN STRUCT ALIGNMODE
    emr         EMR <>
    rclBounds   RECTL <>
    cbRgnData   DD  ?
    ihBrush     DD  ?
    RgnData     DB 1 DUP(?)
EMRFILLRGN ENDS

EMRFRAMERGN STRUCT ALIGNMODE
    emr         EMR <>
    rclBounds   RECTL <>
    cbRgnData   DD  ?
    ihBrush     DD  ?
    szlStroke   SIZEL <>
    RgnData     DB 1 DUP(?)
EMRFRAMERGN ENDS

EMRGRADIENTFILL STRUCT ALIGNMODE
    emr         EMR <>
    rclBounds   RECTL <>
    nVer        DD  ?
    nTri        DD  ?
    ulMode      DD  ?
    Ver         TRIVERTEX <>
EMRGRADIENTFILL ENDS

EMRTRANSPARENTBLT STRUCT ALIGNMODE
    emr          EMR <>
    rclBounds    RECTL <>
    xDest        DD ?
    yDest        DD ?
    cxDest       DD ?
    cyDest       DD ?
    dwRop        DD ?
    xSrc         DD ?
    ySrc         DD ?
    xformSrc     XFORM <>
    crBkColorSrc DD ?
    iUsageSrc    DD ?
    offBmiSrc    DD ?
    cbBmiSrc     DD ?
    offBitsSrc   DD ?
    cbBitsSrc    DD ?
    cxSrc        DD ?
    cySrc        DD ?
EMRTRANSPARENTBLT ENDS

EMREXTSELECTCLIPRGN STRUCT ALIGNMODE
    emr         EMR <>
    cbRgnData   DD  ?
    iMode       DD  ?
    RgnData     DB 1 DUP(?)
EMREXTSELECTCLIPRGN ENDS

EMREXTTEXTOUTA STRUCT ALIGNMODE
    emr           EMR <>
    rclBounds     RECTL <>
    iGraphicsMode DD ?
    exScale       DD ?
    eyScale       DD ?
    emrtext       EMRTEXT <>
EMREXTTEXTOUTA ENDS

EMREXTTEXTOUTW STRUCT ALIGNMODE
    emr           EMR <>
    rclBounds     RECTL <>
    iGraphicsMode DD    ?
    exScale       DD    ?
    eyScale       DD    ?
    emrtext       EMRTEXT <>
EMREXTTEXTOUTW ENDS

EMRPOLYTEXTOUTA STRUCT ALIGNMODE
    emr           EMR <>
    rclBounds     RECTL <>
    iGraphicsMode DD  ?
    exScale       DD  ?
    eyScale       DD  ?
    cStrings      DD  ?
    aemrtext      EMRTEXT <>
EMRPOLYTEXTOUTA ENDS

EMRPOLYTEXTOUTW STRUCT ALIGNMODE
    emr           EMR <>
    rclBounds     RECTL <>
    iGraphicsMode DD  ?
    exScale       DD  ?
    eyScale       DD  ?
    cStrings      DD  ?
    aemrtext      EMRTEXT <>
EMRPOLYTEXTOUTW ENDS

EMRBITBLT STRUCT ALIGNMODE
    emr          EMR <>
    rclBounds    RECTL <>
    xDest        DD ?
    yDest        DD ?
    cxDest       DD ?
    cyDest       DD ?
    dwRop        DD ?
    xSrc         DD ?
    ySrc         DD ?
    xformSrc     XFORM <>
    crBkColorSrc DD ?
    iUsageSrc    DD ?
    offBmiSrc    DD ?
    cbBmiSrc     DD ?
    offBitsSrc   DD ?
    cbBitsSrc    DD ?
EMRBITBLT ENDS

EMRSTRETCHBLT STRUCT ALIGNMODE
    emr          EMR <>
    rclBounds    RECTL <>
    xDest        DD ?
    yDest        DD ?
    cxDest       DD ?
    cyDest       DD ?
    dwRop        DD ?
    xSrc         DD ?
    ySrc         DD ?
    xformSrc     XFORM <>
    crBkColorSrc DD ?
    iUsageSrc    DD ?
    offBmiSrc    DD ?
    cbBmiSrc     DD ?
    offBitsSrc   DD ?
    cbBitsSrc    DD ?
    cxSrc        DD ?
    cySrc        DD ?
EMRSTRETCHBLT ENDS

EMRMASKBLT STRUCT ALIGNMODE
    emr          EMR <>
    rclBounds    RECTL <>
    xDest        DD ?
    yDest        DD ?
    cxDest       DD ?
    cyDest       DD ?
    dwRop        DD ?
    xSrc         DD ?
    ySrc         DD ?
    xformSrc     XFORM <>
    crBkColorSrc DD ?
    iUsageSrc    DD ?
    offBmiSrc    DD ?
    cbBmiSrc     DD ?
    offBitsSrc   DD ?
    cbBitsSrc    DD ?
    xMask        DD ?
    yMask        DD ?
    iUsageMask   DD ?
    offBmiMask   DD ?
    cbBmiMask    DD ?
    offBitsMask  DD ?
    cbBitsMask   DD ?
EMRMASKBLT ENDS

EMRPLGBLT STRUCT ALIGNMODE
    emr          EMR <>
    rclBounds    RECTL <>
    aptlDest     POINTL 3 DUP(<>)
    xSrc         DD ?
    ySrc         DD ?
    cxSrc        DD ?
    cySrc        DD ?
    xformSrc     XFORM <>
    crBkColorSrc DD ?
    iUsageSrc    DD ?
    offBmiSrc    DD ?
    cbBmiSrc     DD ?
    offBitsSrc   DD ?
    cbBitsSrc    DD ?
    xMask        DD ?
    yMask        DD ?
    iUsageMask   DD ?
    offBmiMask   DD ?
    cbBmiMask    DD ?
    offBitsMask  DD ?
    cbBitsMask   DD ?
EMRPLGBLT ENDS

EMRSETDIBITSTODEVICE STRUCT ALIGNMODE
    emr         EMR <>
    rclBounds   RECTL <>
    xDest       DD  ?
    yDest       DD  ?
    xSrc        DD  ?
    ySrc        DD  ?
    cxSrc       DD  ?
    cySrc       DD  ?
    offBmiSrc   DD  ?
    cbBmiSrc    DD  ?
    offBitsSrc  DD  ?
    cbBitsSrc   DD  ?
    iUsageSrc   DD  ?
    iStartScan  DD  ?
    cScans      DD  ?
EMRSETDIBITSTODEVICE ENDS

EMRSTRETCHDIBITS STRUCT ALIGNMODE
    emr         EMR <>
    rclBounds   RECTL <>
    xDest       DD  ?
    yDest       DD  ?
    xSrc        DD  ?
    ySrc        DD  ?
    cxSrc       DD  ?
    cySrc       DD  ?
    offBmiSrc   DD  ?
    cbBmiSrc    DD  ?
    offBitsSrc  DD  ?
    cbBitsSrc   DD  ?
    iUsageSrc   DD  ?
    dwRop       DD  ?
    cxDest      DD  ?
    cyDest      DD  ?
EMRSTRETCHDIBITS ENDS

EMRALPHABLE STRUCT ALIGNMODE
    emr          EMR <>
    rclBounds    RECTL <>
    xDest        DD  ?
    yDest        DD  ?
    cxDest       DD  ?
    cyDest       DD  ?
    dwRop        DD  ?
    xSrc         DD  ?
    ySrc         DD  ?
    xformSrc     XFORM <>
    crBkColorSrc DD  ?
    iUsageSrc    DD  ?
    offBmiSrc    DD  ?
    cbBmiSrc     DD  ?
    offBitsSrc   DD  ?
    cbBitsSrc    DD  ?
    cxSrc        DD  ?
    cySrc        DD  ?
EMRALPHABLE ENDS

EMREMRTRANSPARENTBLT STRUCT ALIGNMODE
    emr          EMR <>
    rclBounds    RECTL <>
    xDest        DD  ?
    yDest        DD  ?
    cxDest       DD  ?
    cyDest       DD  ?
    dwRop        DD  ?
    xSrc         DD  ?
    ySrc         DD  ?
    xformSrc     XFORM <>
    crBkColorSrc DD  ?
    iUsageSrc    DD  ?
    offBmiSrc    DD  ?
    cbBmiSrc     DD  ?
    offBitsSrc   DD  ?
    cbBitsSrc    DD  ?
    cxSrc        DD  ?
    cySrc        DD  ?
EMREMRTRANSPARENTBLT ENDS

EMREXTCREATEFONTINDIRECTA STRUCT ALIGNMODE
    emr     EMR <>
    ihFont  DD  ?
    elfw    EXTLOGFONTA <>
EMREXTCREATEFONTINDIRECTA ENDS

EMREXTCREATEFONTINDIRECTW STRUCT ALIGNMODE
    emr     EMR <>
    ihFont  DD  ?
    elfw    EXTLOGFONTW <>
EMREXTCREATEFONTINDIRECTW ENDS

EMRCREATEPALETTE STRUCT ALIGNMODE
    emr     EMR <>
    ihPal   DD  ?
    lgpl    LOGPALETTE <>
EMRCREATEPALETTE ENDS

EMRCREATECOLORSPACE STRUCT ALIGNMODE
    emr  EMR <>
    ihCS DD  ?
    lcs  LOGCOLORSPACEW <>
EMRCREATECOLORSPACE ENDS

EMRSETCOLORSPACE STRUCT ALIGNMODE
    emr  EMR <>
    ihCS DD  ?
EMRSETCOLORSPACE ENDS

EMREXTESCAPE STRUCT ALIGNMODE
    emr         EMR <>
    iEscape     DD  ?
    cbEscData   DD  ?
    EscData     DB  ?
EMREXTESCAPE ENDS

EMRNAMEDESCAPE STRUCT ALIGNMODE
    emr         EMR <>
    iEscape     DD  ?
    cbDriver    DD  ?
    cbEscData   DD  ?
    EscData     DB  ?
EMRNAMEDESCAPE ENDS

EMRCREATEPEN STRUCT ALIGNMODE
    emr     EMR <>
    ihPen   DD  ?
    lopn    LOGPEN <>
EMRCREATEPEN ENDS

EMREXTCREATEPEN STRUCT ALIGNMODE
    emr     EMR <>
    ihPen   DD  ?
    offBmi  DD  ?
    cbBmi   DD  ?
    offBits DD  ?
    cbBits  DD  ?
    elp     EXTLOGPEN <>
EMREXTCREATEPEN ENDS

EMRCREATEBRUSHINDIRECT STRUCT ALIGNMODE
    emr     EMR <>
    ihBrush DD  ?
    lb      LOGBRUSH <>
EMRCREATEBRUSHINDIRECT ENDS

EMRCREATEMONOBRUSH STRUCT ALIGNMODE
    emr     EMR <>
    ihBrush DD  ?
    iUsage  DD  ?
    offBmi  DD  ?
    cbBmi   DD  ?
    offBits DD  ?
    cbBits  DD  ?
EMRCREATEMONOBRUSH ENDS

EMRCREATEDIBPATTERNBRUSHPT STRUCT ALIGNMODE
    emr     EMR <>
    ihBrush DD  ?
    iUsage  DD  ?
    offBmi  DD  ?
    cbBmi   DD  ?
    offBits DD  ?
    cbBits  DD  ?
EMRCREATEDIBPATTERNBRUSHPT ENDS

EMRFORMAT STRUCT ALIGNMODE
    dSignature  DD  ?
    nVersion    DD  ?
    cbData      DD  ?
    offData     DD  ?
EMRFORMAT ENDS

EMRGLSRECORD STRUCT ALIGNMODE
    emr     EMR <>
    cbData  DD  ?
    Data    DB 1 DUP(?)
EMRGLSRECORD ENDS

EMRGLSBOUNDEDRECORD STRUCT ALIGNMODE
    emr         EMR <>
    rclBounds   RECTL <>
    cbData      DD  ?
    Data        DB 1 DUP(?)
EMRGLSBOUNDEDRECORD ENDS

EMRPIXELFORMAT STRUCT ALIGNMODE
    emr EMR <>
    pfd PIXELFORMATDESCRIPTOR <>
EMRPIXELFORMAT ENDS

EMRSETICMPROFILE STRUCT ALIGNMODE
    emr     EMR <>
    dwFlags DD  ?
    cbName  DD  ?
    cbData  DD  ?
    Data    DB 1 DUP(?)
EMRSETICMPROFILE ENDS

EMRCREATECOLORSPACEW STRUCT ALIGNMODE
    emr     EMR <>
    ihCS    DD  ?
    lcs     LOGCOLORSPACEW <>
    dwFlags DD  ?
    cbData  DD  ?
    Data    DB  ?
EMRCREATECOLORSPACEW ENDS

COLORMATCHTOTARGET STRUCT ALIGNMODE
    emr      EMR <>
    dwAction DD ?
    dwFlags  DD ?
    cbName   DD ?
    cbData   DD ?
    Data     DB ?
COLORMATCHTOTARGET ENDS

COLORCORRECTPALETTE STRUCT ALIGNMODE
    emr         EMR <>
    ihPalette   DD  ?
    nFirstEntry DD  ?
    nPalEntries DD  ?
    nReserved   DD  ?
COLORCORRECTPALETTE ENDS

EMRALPHABLEND STRUCT ALIGNMODE
    emr          EMR <>
    rclBounds    RECTL <>
    xDest        DD ?
    yDest        DD ?
    cxDest       DD ?
    cyDest       DD ?
    dwRop        DD ?
    xSrc         DD ?
    ySrc         DD ?
    xformSrc     XFORM <>
    crBkColorSrc DD ?
    iUsageSrc    DD ?
    offBmiSrc    DD ?
    cbBmiSrc     DD ?
    offBitsSrc   DD ?
    cbBitsSrc    DD ?
    cxSrc        DD ?
    cySrc        DD ?
EMRALPHABLEND ENDS

POINTFLOAT STRUCT ALIGNMODE
    x DD  ?
    y DD  ?
POINTFLOAT ENDS

GLYPHMETRICSFLOAT STRUCT ALIGNMODE
    gmfBlackBoxX     DD ?
    gmfBlackBoxY     DD ?
    gmfptGlyphOrigin POINTFLOAT <>
    gmfCellIncX      DD ?
    gmfCellIncY      DD ?
GLYPHMETRICSFLOAT ENDS

LAYERPLANEDESCRIPTOR STRUCT ALIGNMODE
    nSize           DW  ?
    nVersion        DW  ?
    dwFlags         DD  ?
    iPixelType      DB  ?
    cColorBits      DB  ?
    cRedBits        DB  ?
    cRedShift       DB  ?
    cGreenBits      DB  ?
    cGreenShift     DB  ?
    cBlueBits       DB  ?
    cBlueShift      DB  ?
    cAlphaBits      DB  ?
    cAlphaShift     DB  ?
    cAccumBits      DB  ?
    cAccumRedBits   DB  ?
    cAccumGreenBits DB  ?
    cAccumBlueBits  DB  ?
    cAccumAlphaBits DB  ?
    cDepthBits      DB  ?
    cStencilBits    DB  ?
    cAuxBuffers     DB  ?
    iLayerPlane     DB  ?
    bReserved       DB  ?
    crTransparent   DD  ?
LAYERPLANEDESCRIPTOR ENDS

WGLSWAP STRUCT ALIGNMODE
    hdc     DD  ?
    uiFlags DD  ?
WGLSWAP ENDS

IF (NTDDI_VERSION GE NTDDI_VISTA)
    GDIREGISTERDDRAWPACKETVERSION               EQU     01H

    GDIREGISTERDDRAWPACKET STRUCT ALIGNMODE
        dwSize          DD   ?
        dwVersion       DD   ?
        pfnDdMarshal    XPTR ?
        pfnDdUnmarshal  XPTR ?
        pfnDdRelease    XPTR ?
    GDIREGISTERDDRAWPACKET ENDS
ENDIF

DISPLAYCONFIG_RATIONAL STRUCT ALIGNMODE
    Numerator   DD  ?
    Denominator DD  ?
DISPLAYCONFIG_RATIONAL ENDS

DISPLAYCONFIG_2DREGION STRUCT ALIGNMODE
    _cx DD  ?
    cy  DD  ?
DISPLAYCONFIG_2DREGION ENDS

DISPLAYCONFIG_VIDEO_SIGNAL_INFO STRUCT ALIGNMODE
    pixelRate        DWORD64 ?
    hSyncFreq        DISPLAYCONFIG_RATIONAL <>
    vSyncFreq        DISPLAYCONFIG_RATIONAL <>
    activeSize       DISPLAYCONFIG_2DREGION <>
    totalSize        DISPLAYCONFIG_2DREGION <>
    videoStandard    DWORD32 ?
    scanLineOrdering DD      ?
DISPLAYCONFIG_VIDEO_SIGNAL_INFO ENDS

DISPLAYCONFIG_SOURCE_MODE STRUCT ALIGNMODE
    _width      DD  ?
    height      DD  ?
    pixelFormat DD  ?
    position    POINTL <>
DISPLAYCONFIG_SOURCE_MODE ENDS

DISPLAYCONFIG_TARGET_MODE STRUCT ALIGNMODE
    targetVideoSignalInfo DISPLAYCONFIG_VIDEO_SIGNAL_INFO <>
DISPLAYCONFIG_TARGET_MODE ENDS

DISPLAYCONFIG_MODE_INFO STRUCT ALIGNMODE
    infoType    DD  ?
    id          DD  ?
    adapterId   LUID <>
    UNION
        targetMode DISPLAYCONFIG_TARGET_MODE <>
        sourceMode DISPLAYCONFIG_SOURCE_MODE <>
    ENDS
DISPLAYCONFIG_MODE_INFO ENDS

DISPLAYCONFIG_PATH_SOURCE_INFO STRUCT ALIGNMODE
    adapterId   LUID <>
    id          DD  ?
    modeInfoIdx DD  ?
    statusFlags DD  ?
DISPLAYCONFIG_PATH_SOURCE_INFO ENDS

DISPLAYCONFIG_PATH_TARGET_INFO STRUCT ALIGNMODE
    adapterId        LUID   <>
    id               DD     ?
    modeInfoIdx      DD     ?
    outputTechnology DD     ?
    rotation         DD     ?
    scaling          DD     ?
    refreshRate      DISPLAYCONFIG_RATIONAL <>
    scanLineOrdering DD     ?
    targetAvailable  BOOL   ?
    statusFlags      DD     ?
DISPLAYCONFIG_PATH_TARGET_INFO ENDS

DISPLAYCONFIG_PATH_INFO STRUCT ALIGNMODE
    sourceInfo DISPLAYCONFIG_PATH_SOURCE_INFO <>
    targetInfo DISPLAYCONFIG_PATH_SOURCE_INFO <>
    flags      DD   ?
DISPLAYCONFIG_PATH_INFO ENDS

DISPLAYCONFIG_DEVICE_INFO_HEADER STRUCT ALIGNMODE
    _type     DD   ?
    _size     DD   ?
    adapterId LUID <>
    id        DD   ?
DISPLAYCONFIG_DEVICE_INFO_HEADER ENDS

DISPLAYCONFIG_SOURCE_DEVICE_NAME STRUCT ALIGNMODE
    header            DISPLAYCONFIG_DEVICE_INFO_HEADER <>
    viewGdiDeviceName WCHAR CCHDEVICENAME DUP(?)
DISPLAYCONFIG_SOURCE_DEVICE_NAME ENDS

DISPLAYCONFIG_TARGET_DEVICE_NAME_FLAGS UNION ALIGNMODE
        STRUCT
            friendlyNameFromEdid DD ?
            friendlyNameForced   DD ?
            edidIdsValid         DD ?
            reserved             DD ?
        ENDS
        value                    DD ?
DISPLAYCONFIG_TARGET_DEVICE_NAME_FLAGS ENDS

DISPLAYCONFIG_TARGET_DEVICE_NAME STRUCT ALIGNMODE
    header                    DISPLAYCONFIG_DEVICE_INFO_HEADER <>
    flags                     DD    ?
    outputTechnology          DD    ?
    edidManufactureId         DW    ?
    edidProductCodeId         DW    ?
    connectorInstance         DD    ?
    monitorFriendlyDeviceName WCHAR 64 DUP(?)
    monitorDevicePath         WCHAR 128 DUP(?)
DISPLAYCONFIG_TARGET_DEVICE_NAME ENDS

DISPLAYCONFIG_TARGET_PREFERRED_MODE STRUCT ALIGNMODE
    header      DISPLAYCONFIG_DEVICE_INFO_HEADER <>
    _width      DD    ?
    height      DD    ?
    targetMode  DD    ?
DISPLAYCONFIG_TARGET_PREFERRED_MODE ENDS

DISPLAYCONFIG_ADAPTER_NAME STRUCT ALIGNMODE
    header            DISPLAYCONFIG_DEVICE_INFO_HEADER <>
    adapterDevicePath WCHAR 128 DUP(?)
DISPLAYCONFIG_ADAPTER_NAME ENDS

DISPLAYCONFIG_SET_TARGET_PERSISTENCE STRUCT ALIGNMODE
    header      DISPLAYCONFIG_DEVICE_INFO_HEADER <>
    UNION
        STRUCT
            bootPersistenceOn   DWORD32 ?
            reserved            DWORD32 ?
        ENDS
        value   DWORD32 ?
    ENDS
DISPLAYCONFIG_SET_TARGET_PERSISTENCE ENDS

;======================================== Functions =======================================;
AbortDoc PROTO :HDC
AbortPath PROTO :HDC
AddFontResourceA PROTO :LPCTSTR
AddFontResourceW PROTO :LPCWSTR
AngleArc PROTO :HDC, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
AnimatePalette PROTO :HPALETTE, :XWORD, :XWORD, :XPTR
Arc PROTO :HDC, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
ArcTo PROTO :HDC, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
BeginPath PROTO :HDC
BitBlt PROTO :HDC, :XWORD, :XWORD, :XWORD, :XWORD, :HDC, :XWORD, :XWORD, :XWORD
CancelDC PROTO :HDC
CheckColorsInGamut PROTO :HDC, :LPVOID, :LPVOID, :XWORD
ChoosePixelFormat PROTO :HDC, :XPTR
Chord PROTO :HDC, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CloseEnhMetaFile PROTO :HDC
CloseFigure PROTO :HDC
CloseMetaFile PROTO :HDC
ColorMatchToTarget PROTO :HDC, :HDC, :XWORD
CombineRgn PROTO :HRGN, :HRGN, :HRGN, :XWORD
CombineTransform PROTO :XPTR, :XPTR, :XPTR
CopyEnhMetaFileA PROTO :HENHMETAFILE, :LPCTSTR
CopyEnhMetaFileW PROTO :HENHMETAFILE, :LPCWSTR
CopyMetaFileA PROTO :HMETAFILE, :LPCTSTR
CopyMetaFileW PROTO :HMETAFILE, :LPCWSTR
CreateBitmap PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XPTR
CreateBitmapIndirect PROTO :XPTR
CreateBrushIndirect PROTO :XPTR
CreateColorSpaceA PROTO :XPTR
CreateColorSpaceW PROTO :XPTR
CreateCompatibleBitmap PROTO :HDC, :XWORD, :XWORD
CreateCompatibleDC PROTO :HDC
CreateDCA PROTO :LPCTSTR, :LPCTSTR, :LPCTSTR, :XPTR
CreateDCW PROTO :LPCWSTR, :LPCWSTR, :LPCWSTR, :XPTR
CreateDIBitmap PROTO :HDC, :XPTR, :XWORD, :XPTR, :XPTR, :XWORD
CreateDIBPatternBrush PROTO :HGLOBAL, :XWORD
CreateDIBPatternBrushPt PROTO :XPTR, :XWORD
CreateDIBSection PROTO :HDC, :XPTR, :XWORD, :XPTR, :HANDLE, :XWORD
CreateDiscardableBitmap PROTO :HDC, :XWORD, :XWORD
CreateEllipticRgn PROTO :XWORD, :XWORD, :XWORD, :XWORD
CreateEllipticRgnIndirect PROTO :XPTR
CreateEnhMetaFileA PROTO :HDC, :LPCTSTR, :XPTR, :LPCTSTR
CreateEnhMetaFileW PROTO :HDC, :LPCWSTR, :XPTR, :LPCWSTR
CreateFontA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :LPCTSTR
CreateFontIndirectA PROTO :XPTR
CreateFontIndirectW PROTO :XPTR
CreateFontW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :LPCWSTR
CreateHalftonePalette PROTO :HDC
CreateHatchBrush PROTO :XWORD, :XWORD
CreateICA PROTO :LPCTSTR, :LPCTSTR, :LPCTSTR, :XPTR
CreateICW PROTO :LPCWSTR, :LPCWSTR, :LPCWSTR, :XPTR
CreateMetaFileA PROTO :LPCTSTR
CreateMetaFileW PROTO :LPCWSTR
CreatePalette PROTO :XPTR
CreatePatternBrush PROTO :HBITMAP
CreatePen PROTO :XWORD, :XWORD, :XWORD
CreatePenIndirect PROTO :XPTR
CreatePolygonRgn PROTO :XPTR, :XWORD, :XWORD
CreatePolyPolygonRgn PROTO :XPTR, :XPTR, :XWORD, :XWORD
CreateRectRgn PROTO :XWORD, :XWORD, :XWORD, :XWORD
CreateRectRgnIndirect PROTO :XPTR
CreateRoundRectRgn PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CreateScalableFontResourceA PROTO :XWORD, :LPCTSTR, :LPCTSTR, :LPCTSTR
CreateScalableFontResourceW PROTO :XWORD, :LPCWSTR, :LPCWSTR, :LPCWSTR
CreateSolidBrush PROTO :XWORD
DeleteColorSpace PROTO :HCOLORSPACE
DeleteDC PROTO :HDC
DeleteEnhMetaFile PROTO :HENHMETAFILE
DeleteMetaFile PROTO :HMETAFILE
DeleteObject PROTO :HGDIOBJ
DescribePixelFormat PROTO :HDC, :XWORD, :XWORD, :XPTR
DeviceCapabilitiesExA PROTO :LPCSTR, :LPCSTR, :LPCSTR, :XWORD, :LPSTR, :XPTR
DeviceCapabilitiesExW PROTO :LPWSTR, :LPWSTR, :LPWSTR, :XWORD, :LPWSTR, :XPTR
DPtoLP PROTO :HDC, :XPTR, :XWORD
DrawEscape PROTO :HDC, :XWORD, :XWORD, :LPCSTR
Ellipse PROTO :HDC, :XWORD, :XWORD, :XWORD, :XWORD
EndDoc PROTO :HDC
EndPage PROTO :HDC
EndPath PROTO :HDC
EnumEnhMetaFile PROTO :HDC, :HENHMETAFILE, :XPTR, :LPVOID, :XPTR
EnumFontFamiliesA PROTO :HDC, :LPCTSTR, :XPTR, :LPARAM
EnumFontFamiliesExA PROTO :HDC, :XPTR, :XPTR, :LPARAM, :XWORD
EnumFontFamiliesExW PROTO :HDC, :XPTR, :XPTR, :LPARAM, :XWORD
EnumFontFamiliesW PROTO :HDC, :LPCWSTR, :XPTR, :LPARAM
EnumFontsA PROTO :HDC, :LPCTSTR, :XPTR, :LPARAM
EnumFontsW PROTO :HDC, :LPCWSTR, :XPTR, :LPARAM
EnumICMProfilesA PROTO :HDC, :XPTR, :LPARAM
EnumICMProfilesW PROTO :HDC, :XPTR, :LPARAM
EnumMetaFile PROTO :HDC, :HMETAFILE, :XPTR, :LPARAM
EnumObjects PROTO :HDC, :XWORD, :XPTR, :LPARAM
EqualRgn PROTO :HRGN, :HRGN
Escape PROTO :HDC, :XWORD, :XWORD, :LPCSTR, :LPVOID
ExcludeClipRect PROTO :HDC, :XWORD, :XWORD, :XWORD, :XWORD
ExtCreatePen PROTO :XWORD, :XWORD, :XPTR, :XWORD, :XPTR
ExtCreateRegion PROTO :XPTR, :XWORD, :XPTR
ExtEscape PROTO :HDC, :XWORD, :XWORD, :LPCSTR, :XWORD, :LPTSTR
ExtFloodFill PROTO :HDC, :XWORD, :XWORD, :XWORD, :XWORD
ExtSelectClipRgn PROTO :HDC, :HRGN, :XWORD
ExtTextOutA PROTO :HDC, :XWORD, :XWORD, :XWORD, :XPTR, :LPCTSTR, :XWORD, :XPTR
ExtTextOutW PROTO :HDC, :XWORD, :XWORD, :XWORD, :XPTR, :LPCWSTR, :XWORD, :XPTR
FillPath PROTO :HDC
FillRgn PROTO :HDC, :HRGN, :HBRUSH
FixBrushOrgEx PROTO :HDC, :XWORD, :XWORD, :XPTR
FlattenPath PROTO :HDC
FloodFill PROTO :HDC, :XWORD, :XWORD, :XWORD
FrameRgn PROTO :HDC, :HRGN, :HBRUSH, :XWORD, :XWORD
GdiComment PROTO :HDC, :XWORD, :XPTR
GdiFlush PROTO
GdiGetBatchLimit PROTO
GdiPlayDCScript PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
GdiPlayJournal PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
GdiPlayScript PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
gdiPlaySpoolStream PROTO :LPSTR, :LPSTR, :LPSTR, :XWORD, :LPDWORD, :HDC
GdiSetBatchLimit PROTO :XWORD
GetArcDirection PROTO :HDC
GetAspectRatioFilterEx PROTO :HDC, :XWORD
GetBitmapBits PROTO :HBITMAP, :XWORD, :LPVOID
GetBitmapDimensionEx PROTO :HBITMAP, :XWORD
GetBkColor PROTO :HDC
GetBkMode PROTO :HDC
GetBoundsRect PROTO :HDC, :XPTR, :XWORD
GetBrushOrgEx PROTO :HDC, :XPTR
GetCharABCWidthsA PROTO :HDC, :XWORD, :XWORD, :XPTR
GetCharABCWidthsW PROTO :HDC, :XWORD, :XWORD, :XPTR
GetCharABCWidthsFloatA PROTO :HDC, :XWORD, :XWORD, :XPTR
GetCharABCWidthsFloatW PROTO :HDC, :XWORD, :XWORD, :XPTR
GetCharWidth32A PROTO :HDC, :XWORD, :XWORD, :XPTR
GetCharWidth32W PROTO :HDC, :XWORD, :XWORD, :XPTR
GetCharWidthA PROTO :HDC, :XWORD, :XWORD, :XPTR
GetCharWidthW PROTO :HDC, :XWORD, :XWORD, :XPTR
GetCharWidthFloatA PROTO :HDC, :XWORD, :XWORD, :XPTR
GetCharWidthFloatW PROTO :HDC, :XWORD, :XWORD, :XPTR
GetCharacterPlacementA PROTO :HDC, :LPCTSTR, :XWORD, :XWORD, :XPTR, :XWORD
GetCharacterPlacementW PROTO :HDC, :LPCWSTR, :XWORD, :XWORD, :XPTR, :XWORD
GetClipBox PROTO :HDC, :XPTR
GetClipRgn PROTO :HRGN, :XPTR
GetColorAdjustment PROTO :HDC, :XPTR
GetColorSpace PROTO :HDC
GetCurrentObject PROTO :HDC, :XWORD
GetCurrentPositionEx PROTO :HDC, :XPTR
GetDCOrgEx PROTO :HDC, :XPTR
GetDeviceCaps PROTO :HDC, :XWORD
GetDeviceGammaRamp PROTO :HDC, :XPTR
GetDIBColorTable PROTO :HDC, :XWORD, :XWORD, :XPTR
GetDIBits PROTO :HDC, :HBITMAP, :XWORD, :XWORD, :LPVOID, :XPTR, :XWORD
GetEnhMetaFileA PROTO :LPCTSTR
GetEnhMetaFileBits PROTO :HENHMETAFILE, :XWORD, :XPTR
GetEnhMetaFileDescriptionA PROTO :HENHMETAFILE, :XWORD, :LPTSTR
GetEnhMetaFileDescriptionW PROTO :HENHMETAFILE, :XWORD, :LPWSTR
GetEnhMetaFileHeader PROTO :HENHMETAFILE, :XWORD, :XPTR
GetEnhMetaFilePaletteEntries PROTO :HENHMETAFILE, :XWORD, :XPTR
GetEnhMetaFileW PROTO :LPCWSTR
GetFontData PROTO :HDC, :XWORD, :XWORD, :LPVOID, :XWORD
GetFontLanguageInfo PROTO :HDC
GetGlyphOutlineA PROTO :HDC, :XWORD, :XWORD, :XPTR, :XWORD, :LPVOID, :XPTR
GetGlyphOutlineW PROTO :HDC, :XWORD, :XWORD, :XPTR, :XWORD, :LPVOID, :XPTR
GetGraphicsMode PROTO :HDC
GetICMProfileA PROTO :HDC, :LPDWORD, :LPTSTR
GetICMProfileW PROTO :HDC, :LPDWORD, :LPWSTR
GetKerningPairsA PROTO :HDC, :XWORD, :XPTR
GetKerningPairsW PROTO :HDC, :XWORD, :XPTR
GetLogColorSpaceA PROTO :HANDLE, :XPTR, :XWORD
GetLogColorSpaceW PROTO :HANDLE, :XPTR, :XWORD
GetMapMode PROTO :HDC
GetMetaFileA PROTO :LPCTSTR
GetMetaFileBitsEx PROTO :HMETAFILE, :XWORD, :LPVOID
GetMetaFileW PROTO :LPCWSTR
GetMetaRgn PROTO :HDC, :HRGN
GetMiterLimit PROTO :HDC, :XPTR
GetNearestColor PROTO :HDC, :XWORD
GetNearestPaletteIndex PROTO :HPALETTE, :XWORD
GetObjectA PROTO :HGDIOBJ, :XWORD, :LPVOID
GetObjectType PROTO :HGDIOBJ
GetObjectW PROTO :HGDIOBJ, :XWORD, :LPVOID
GetOutlineTextMetricsA PROTO :HDC, :XWORD, :XPTR
GetOutlineTextMetricsW PROTO :HDC, :XWORD, :XPTR
GetPaletteEntries PROTO :HPALETTE, :XWORD, :XWORD, :XPTR
GetPath PROTO :HDC, :XPTR, :XPTR, :XWORD
GetPixel PROTO :HDC, :XWORD, :XWORD
GetPixelFormat PROTO :HDC
GetPolyFillMode PROTO :HDC
GetROP2 PROTO :HDC
GetRandomRgn PROTO :HDC, :HRGN, :XWORD
GetRasterizerCaps PROTO :XPTR, :XWORD
GetRegionData PROTO :HRGN, :XWORD, :XPTR
GetRgnBox PROTO :HRGN, :XPTR
GetStockObject PROTO :XWORD
GetStretchBltMode PROTO :HDC
GetSystemPaletteEntries PROTO :HDC, :XWORD, :XWORD, :XPTR
GetSystemPaletteUse PROTO :HDC
GetTextAlign PROTO :HDC
GetTextCharacterExtra PROTO :HDC
GetTextCharset PROTO :HDC
GetTextCharsetInfo PROTO :HDC, :XPTR, :XWORD
GetTextColor PROTO :HDC
GetTextExtentExPointA PROTO :HDC, :LPCTSTR, :XWORD, :XWORD, :XPTR, :XPTR, :XPTR
GetTextExtentExPointW PROTO :HDC, :LPCWSTR, :XWORD, :XWORD, :XPTR, :XPTR, :XPTR
GetTextExtentPoint32A PROTO :HDC, :LPCTSTR, :XWORD, :XPTR
GetTextExtentPoint32W PROTO :HDC, :LPCWSTR, :XWORD, :XPTR
GetTextExtentPointA PROTO :HDC, :LPCTSTR, :XWORD, :XPTR
GetTextExtentPointW PROTO :HDC, :LPCWSTR, :XWORD, :XPTR
GetTextFaceA PROTO :HDC, :XWORD, :LPTSTR
GetTextFaceW PROTO :HDC, :XWORD, :LPWSTR
GetTextMetricsA PROTO :HDC, :XPTR
GetTextMetricsW PROTO :HDC, :XPTR
GetViewportExtEx PROTO :HDC, :XPTR
GetViewportOrgEx PROTO :HDC, :XPTR
GetWindowExtEx PROTO :HDC, :XPTR
GetWindowOrgEx PROTO :HDC, :XPTR
GetWinMetaFileBits PROTO :HENHMETAFILE, :XWORD, :LPBYTE, :XWORD, :HDC
GetWorldTransform PROTO :HDC, :XPTR
IntersectClipRect PROTO :HDC, :XWORD, :XWORD, :XWORD, :XWORD
InvertRgn PROTO :HDC, :HRGN
LineDDA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XPTR, :LPARAM
LineTo PROTO :HDC, :XWORD, :XWORD
LPtoDP PROTO :HDC, :XPTR, :XWORD
MaskBlt PROTO :HDC, :XWORD, :XWORD, :XWORD, :XWORD, :HDC, :XWORD, :XWORD, :HBITMAP, :XWORD, :XWORD, :XWORD
ModifyWorldTransform PROTO :HDC, :XPTR, :XWORD
MoveToEx PROTO :HDC, :XWORD, :XWORD, :XPTR
OffsetClipRgn PROTO :HDC, :XWORD, :XWORD
OffsetRgn PROTO :HRGN, :XWORD, :XWORD
OffsetViewportOrgEx PROTO :HDC, :XWORD, :XWORD, :XPTR
OffsetWindowOrgEx PROTO :HDC, :XWORD, :XWORD, :XPTR
PaintRgn PROTO :HDC, :HRGN
PatBlt PROTO :HDC, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
PathToRegion PROTO :HDC
Pie PROTO :HDC, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
PlayEnhMetaFile PROTO :HDC, :HENHMETAFILE, :XPTR
PlayEnhMetaFileRecord PROTO :HDC, :XPTR, :XPTR, :XWORD
PlayMetaFile PROTO :HDC, :HMETAFILE
PlayMetaFileRecord PROTO :HDC, :XPTR, :XPTR, :XWORD
PlgBlt PROTO :HDC, :XPTR, :HDC, :XWORD, :XWORD, :XWORD, :XWORD, :HBITMAP, :XWORD, :XWORD
PolyBezier PROTO :HDC, :XPTR, :XWORD
PolyBezierTo PROTO :HDC, :XPTR, :XWORD
PolyDraw PROTO :HDC, :XPTR, :XPTR, :XWORD
Polygon PROTO :HDC, :XPTR, :XWORD
Polyline PROTO :HDC, :XPTR, :XWORD
PolylineTo PROTO :HDC, :XPTR, :XWORD
PolyPolygon PROTO :HDC, :XPTR, :XPTR, :XWORD
PolyPolyline PROTO :HDC, :XPTR, :XPTR, :XWORD
PolyTextOutA PROTO :HDC, :XPTR, :XWORD
PolyTextOutW PROTO :HDC, :XPTR, :XWORD
PtInRegion PROTO :HRGN, :XWORD, :XWORD
PtVisible PROTO :HDC, :XWORD, :XWORD
RealizePalette PROTO :HDC
Rectangle PROTO :HDC, :XWORD, :XWORD, :XWORD, :XWORD
RectInRegion PROTO :HRGN, :XPTR
RectVisible PROTO :HDC, :XPTR
RemoveFontResourceA PROTO :LPCTSTR
RemoveFontResourceW PROTO :LPCWSTR
ResetDCA PROTO :HDC, :XPTR
ResetDCW PROTO :HDC, :XPTR
ResizePalette PROTO :HPALETTE, :XWORD
RestoreDC PROTO :HDC, :XWORD
RoundRect PROTO :HDC, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
SaveDC PROTO :HDC
ScaleViewportExtEx PROTO :HDC, :XWORD, :XWORD, :XWORD, :XWORD, :XPTR
ScaleWindowExtEx PROTO :HDC, :XWORD, :XWORD, :XWORD, :XWORD, :XPTR
SelectClipPath PROTO :HDC, :XWORD
SelectClipRgn PROTO :HDC, :HRGN
SelectObject PROTO :HDC, :HGDIOBJ
SelectPalette PROTO :HDC, :HPALETTE, :XWORD
SetAbortProc PROTO :HDC, :XPTR
SetArcDirection PROTO :HDC, :XWORD
SetBitmapBits PROTO :HBITMAP, :XWORD, :XPTR
SetBitmapDimensionEx PROTO :HBITMAP, :XWORD, :XWORD, :XPTR
SetBkColor PROTO :HDC, :XWORD
SetBkMode PROTO :HDC, :XWORD
SetBoundsRect PROTO :HDC, :XPTR, :XWORD
SetBrushOrgEx PROTO :HDC, :XWORD, :XWORD, :XPTR
SetColorAdjustment PROTO :HDC, :XPTR
SetColorSpace PROTO :HDC, :HANDLE
SetDeviceGammaRamp PROTO :HDC, :LPVOID
SetDIBColorTable PROTO :HDC, :XWORD, :XWORD, :XPTR
SetDIBits PROTO :HDC, :HBITMAP, :XWORD, :XWORD, :XPTR, :XPTR, :XWORD
SetDIBitsToDevice PROTO :HDC, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XPTR, :XPTR, :XWORD
SetEnhMetaFileBits PROTO :XWORD, :XPTR
SetFontEnumeration PROTO :XWORD
SetGraphicsMode PROTO :HDC, :XWORD
SetICMMode PROTO :HDC, :XWORD
SetICMProfileA PROTO :HDC, :LPTSTR
SetICMProfileW PROTO :HDC, :LPWSTR
SetMapMode PROTO :HDC, :XWORD
SetMapperFlags PROTO :HDC, :XWORD
SetMetaFileBitsEx PROTO :XWORD, :XPTR
SetMetaRgn PROTO :HDC
SetMiterLimit PROTO :HDC, :XWORD, :XPTR
SetPaletteEntries PROTO :HPALETTE, :XWORD, :XWORD, :XPTR
SetPixel PROTO :HDC, :XWORD, :XWORD, :XWORD
SetPixelFormat PROTO :HDC, :XWORD, :XPTR
SetPixelV PROTO :HDC, :XWORD, :XWORD, :XWORD
SetPolyFillMode PROTO :HDC, :XWORD
SetRectRgn PROTO :HRGN, :XWORD, :XWORD, :XWORD, :XWORD
SetROP2 PROTO :HDC, :XWORD
SetStretchBltMode PROTO :HDC, :XWORD
SetSystemPaletteUse PROTO :HDC, :XWORD
SetTextAlign PROTO :HDC, :XWORD
SetTextCharacterExtra PROTO :HDC, :XWORD
SetTextColor PROTO :HDC, :XWORD
SetTextJustification PROTO :HDC, :XWORD, :XWORD
SetViewportExtEx PROTO :HDC, :XWORD, :XWORD, :XPTR
SetViewportOrgEx PROTO :HDC, :XWORD, :XWORD, :XPTR
SetWindowExtEx PROTO :HDC, :XWORD, :XWORD, :XPTR
SetWindowOrgEx PROTO :HDC, :XWORD, :XWORD, :XPTR
SetWinMetaFileBits PROTO :XWORD, :XPTR, :HDC, :XPTR
SetWorldTransform PROTO :HDC, :XPTR
StartDocA PROTO :HDC, :XPTR
StartDocW PROTO :HDC, :XPTR
StartPage PROTO :HDC
StretchBlt PROTO :HDC, :XWORD, :XWORD, :XWORD, :XWORD, :HDC, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
StretchDIBits PROTO :HDC, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XPTR, :XPTR, :XWORD, :XWORD
StrokeAndFillPath PROTO :HDC
StrokePath PROTO :HDC
SwapBuffers PROTO :HDC
TextOutA PROTO :HDC, :XWORD, :XWORD, :LPCTSTR, :XWORD
TextOutW PROTO :HDC, :XWORD, :XWORD, :LPCWSTR, :XWORD
TranslateCharsetInfo PROTO :XPTR, :XPTR, :XWORD
UnrealizeObject PROTO :HGDIOBJ
UpdateColors PROTO :HDC
UpdateICMRegKeyA PROTO :XWORD, :LPTSTR, :LPTSTR, :XWORD
UpdateICMRegKeyW PROTO :XWORD, :LPWSTR, :LPTSTR, :XWORD
WidenPath PROTO :HDC

IF (NTDDI_VERSION GE NTDDI_WIN98_ME)
    ColorCorrectPalette PROTO :HDC, :HPALETTE, :XWORD, :XWORD
    EnableEUDC PROTO :XWORD
    GetLayout PROTO :HDC
    IF (NTDDI_VERSION NE NTDDI_WINNT4)
        SetLayout PROTO :HDC, :XWORD
    ENDIF
ENDIF

IF (NTDDI_VERSION GE NTDDI_WINNT4)
    GdiAddFontResourceW PROTO :LPCWSTR, :XWORD, :PVOID
    GdiAddGlsBounds PROTO :HDC, :XPTR
    GdiCleanCacheDC PROTO :HDC
    GdiConsoleTextOut PROTO :HDC, :XPTR, :XWORD, :XPTR
    GdiConvertAndCheckDC PROTO :HDC
    GdiConvertBitmap PROTO :HDC
    GdiConvertBrush PROTO :HBRUSH
    GdiConvertDC PROTO :HDC
    GdiConvertEnhMetaFile PROTO :HENHMETAFILE
    GdiConvertFont PROTO :HFONT
    GdiConvertPalette PROTO :HPALETTE
    GdiConvertRegion PROTO :HRGN
    GdiDeleteLocalDC PROTO
    GdiDescribePixelFormat PROTO :HDC, :XWORD, :XWORD, :XPTR
    GdiDllInitialize PROTO :HANDLE, :XWORD, :LPVOID
    GdiFixUpHandle PROTO :HGDIOBJ
    GdiGetCharDimensions PROTO :HDC, :XPTR, :XPTR
    GdiGetCodePage PROTO :HDC
    GdiGetLocalBrush PROTO :HBRUSH
    GdiGetLocalDC PROTO :HDC
    GdiGetLocalFont PROTO :HFONT
    GdiGetSpoolMessage PROTO :LPVOID, :XWORD, :LPVOID, :XWORD
    GdiInitSpool PROTO
    GdiIsMetaFileDC PROTO :HDC
    GdiIsMetaPrintDC PROTO :HDC
    GdiProcessSetup PROTO
    GdiQueryFonts PROTO :XPTR, :XWORD, :XPTR
    GdiQueryTable PROTO
    GdiReleaseLocalDC PROTO :HDC
    GdiSetAttrs PROTO :HDC
    GdiSetPixelFormat PROTO :HDC, :XWORD, :XPTR
    GdiSetServerAttr PROTO :HDC, :XWORD
    GdiValidateHandle PROTO :HGDIOBJ
    GetCharWidthInfo PROTO :HDC, :XPTR
    GetETM PROTO :HDC, :XPTR
    GetEnhMetaFilePixelFormat PROTO :HENHMETAFILE, :XWORD, :XPTR
    GetFontResourceInfoW PROTO :LPCWSTR, :LPDWORD, :LPVOID, :XWORD
    GetGlyphOutlineWow PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    GetHFONT PROTO :HDC
    HT_Get8BPPFormatPalette PROTO :XPTR, :XWORD, :XWORD, :XWORD
    HT_Get8BPPMaskPalette PROTO :XPTR, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    IsValidEnhMetaRecord PROTO :XWORD, :XWORD
    IsValidEnhMetaRecordOffExt PROTO :XWORD, :XWORD, :XWORD, :XWORD
    PolyPatBlt PROTO :HDC, :XWORD, :XPTR, :XWORD, :XWORD
    SelectBrushLocal PROTO :HBRUSH, :HBRUSH
    SelectFontLocal PROTO :HFONT, :HFONT
    SetMagicColors PROTO :HDC, :XPTR, :XWORD
    GetFontResourceInfo EQU <GetFontResourceInfoW>
ENDIF

IF (NTDDI_VERSION GE NTDDI_WIN2K)
    AddFontMemResourceEx PROTO :PVOID, :XWORD, :PVOID, :XPTR
    AddFontResourceExA PROTO :LPCTSTR, :XWORD, :PVOID
    AddFontResourceExW PROTO :LPCWSTR, :XWORD, :PVOID
    BRUSHOBJ_hGetColorTransform PROTO :XPTR
    BRUSHOBJ_pvAllocRbrush PROTO :XPTR, :XWORD
    BRUSHOBJ_pvGetRbrush PROTO :XPTR
    BRUSHOBJ_ulGetBrushColor PROTO :XPTR
    CLIPOBJ_bEnum PROTO :XPTR, :XWORD, :XPTR
    CLIPOBJ_cEnumStart PROTO :XPTR, :XWORD, :XWORD, :XWORD, :XWORD
    CLIPOBJ_ppoGetPath PROTO :XPTR
    CreateFontIndirectExA PROTO :XPTR
    CreateFontIndirectExW PROTO :XPTR
    EngAcquireSemaphore PROTO :HANDLE
    EngAlphaBlend PROTO :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR
    EngAssociateSurface PROTO :HANDLE, :HANDLE, :XWORD
    EngBitBlt PROTO :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XWORD
    EngCheckAbort PROTO :XPTR
    EngComputeGlyphSet PROTO :XWORD, :XWORD, :XWORD
    EngCopyBits PROTO :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR
    EngCreateBitmap PROTO :XPTR, :XWORD, :XWORD, :XWORD, :PVOID
    EngCreateClip PROTO
    EngCreateDeviceBitmap PROTO :HANDLE, :XWORD, :XWORD
    EngCreateDeviceSurface PROTO :HANDLE, :XWORD
    EngCreatePalette PROTO :XWORD, :XWORD, :XPTR, :XWORD, :XWORD, :XWORD
    EngCreateSemaphore PROTO
    EngDeleteClip PROTO :XPTR
    EngDeletePalette PROTO :HPALETTE
    EngDeletePath PROTO :XPTR
    EngDeleteSemaphore PROTO :HANDLE
    EngDeleteSurface PROTO :HANDLE
    EngEraseSurface PROTO :XPTR, :XPTR, :XWORD
    EngFillPath PROTO :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XWORD, :XWORD
    EngFindResource PROTO :HANDLE, :XWORD, :XWORD, :PULONG
    EngFreeModule PROTO :HANDLE
    EngGetCurrentCodePage PROTO :XPTR, :XPTR
    EngGetDriverName PROTO :HANDLE
    EngGetPrinterDataFileName PROTO :HANDLE
    EngGradientFill PROTO :XPTR, :XPTR, :XPTR, :XPTR, :XWORD, :XPTR, :XWORD, :XPTR, :XPTR, :XWORD
    EngLineTo PROTO :XPTR, :XPTR, :XPTR, :XWORD, :XWORD, :XWORD, :XWORD, :XPTR, :XWORD
    EngLoadModule PROTO :LPWSTR
    EngLockSurface PROTO :HANDLE
    EngMarkBandingSurface PROTO :HANDLE
    EngMultiByteToUnicodeN PROTO :LPWSTR, :XWORD, :PULONG, :XPTR, :XWORD
    EngMultiByteToWideChar PROTO :XWORD, :LPWSTR, :XWORD, :LPSTR, :XWORD
    EngPaint PROTO :XPTR, :XPTR, :XPTR, :XPTR, :XWORD
    EngPlgBlt PROTO :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XWORD
    EngQueryLocalTime PROTO :XPTR
    EngReleaseSemaphore PROTO :HANDLE
    EngStretchBlt PROTO :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XWORD
    EngStretchBltROP PROTO :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XWORD, :XPTR, :XWORD
    EngStrokeAndFillPath PROTO :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XWORD, :XWORD
    EngStrokePath PROTO :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XWORD
    EngTextOut PROTO :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XWORD
    EngTransparentBlt PROTO :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XWORD, :XWORD
    EngUnicodeToMultiByteN PROTO :XPTR, :XWORD, :XPTR, :XPTR, :XWORD
    EngUnlockSurface PROTO :XPTR
    EngWideCharToMultiByte PROTO :XWORD, :LPWSTR, :XWORD, :LPSTR, :XWORD
    FONTOBJ_cGetAllGlyphHandles PROTO :XPTR, :XPTR
    FONTOBJ_cGetGlyphs PROTO :XPTR, :XWORD, :XWORD, :XPTR, :XPTR
    FONTOBJ_pQueryGlyphAttrs PROTO :XPTR, :XWORD
    FONTOBJ_pfdg PROTO :XPTR
    FONTOBJ_pifi PROTO :XPTR
    FONTOBJ_pvTrueTypeFontFile PROTO :XPTR, :XPTR
    FONTOBJ_pxoGetXform PROTO :XPTR
    FONTOBJ_vGetInfo PROTO :XPTR, :XWORD, :XPTR
    GdiAlphaBlend PROTO :HDC, :XWORD, :XWORD, :XWORD, :XWORD, :HDC, :XWORD, :XWORD, :XWORD, :XWORD, :XPTR
    GdiArtificialDecrementDriver PROTO :LPWSTR, :XWORD
    GdiConvertBitmapV5 PROTO :HBITMAP, :HBITMAP, :XWORD, :XWORD
    GdiDeleteSpoolFileHandle PROTO :HANDLE
    GdiEndDocEMF PROTO :HANDLE
    GdiEndPageEMF PROTO :HANDLE, :XWORD
    GdiFullscreenControl PROTO
    GdiGetBitmapBitsSize PROTO :XPTR
    GdiGetDC PROTO :HANDLE
    GetDCBrushColor PROTO :HDC
    GetDCPenColor PROTO :HDC
    GdiGetDevmodeForPage PROTO :HANDLE, :XWORD, :XPTR, :XPTR
    GdiGetPageCount PROTO :HANDLE
    GdiGetPageHandle PROTO :HANDLE, :XWORD, :XPTR
    GdiGetSpoolFileHandle PROTO :LPWSTR, :XPTR, :LPWSTR
    GdiGradientFill PROTO :HDC, :XPTR, :XWORD, :PVOID, :XWORD, :XWORD
    GdiInitializeLanguagePack PROTO :XWORD
    GdiIsPlayMetafileDC PROTO :HDC
    GdiPlayEMF PROTO :LPWSTR, :XPTR, :LPWSTR, :XPTR, :HANDLE
    GdiPlayPageEMF PROTO :HANDLE, :HANDLE, :XPTR, :XPTR, :XPTR
    GdiPrinterThunk PROTO :HANDLE, :XPTR, :XPTR
    GdiRealizationInfo PROTO :HDC, :XPTR
    GdiReleaseDC PROTO :HDC
    GdiResetDCEMF PROTO :HANDLE, :XPTR
    GdiSetLastError PROTO :XWORD
    GdiStartDocEMF PROTO :HANDLE, :XPTR
    GdiStartPageEMF PROTO :HANDLE
    GdiTransparentBlt PROTO :HDC, :XWORD, :XWORD, :XWORD, :XWORD, :HDC, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    GetCharABCWidthsI PROTO :HDC, :XWORD, :XWORD, :LPWORD, :XPTR
    GetCharWidthI PROTO :HDC, :XWORD, :XWORD, :LPWORD, :XPTR
    GetEUDCTimeStamp PROTO
    GetEUDCTimeStampExW PROTO :LPCWSTR
    GetFontAssocStatus PROTO :HDC
    GetFontUnicodeRanges PROTO :HDC, :XPTR
    GetGlyphIndicesA PROTO :HDC, :LPCTSTR, :XWORD, :LPWORD, :XWORD
    GetGlyphIndicesW PROTO :HDC, :LPCWSTR, :XWORD, :LPWORD, :XWORD
    GetTextExtentExPointI PROTO :HDC, :LPWORD, :XWORD, :XWORD, :XPTR, :XPTR, :XPTR
    GetTextExtentExPointWPri PROTO :HDC, :LPWSTR, :XWORD, :XWORD, :XPTR, :PULONG, :XPTR
    GetTextExtentPointI PROTO :HDC, :LPWORD, :XWORD, :XPTR
    GetTextFaceAliasW PROTO :HDC, :XWORD, :LPWSTR
    MirrorRgn PROTO :HWND, :HRGN
    PATHOBJ_bEnum PROTO :XPTR, :XPTR
    PATHOBJ_bEnumClipLines PROTO :XPTR, :XWORD, :XPTR
    PATHOBJ_vEnumStart PROTO :XPTR
    PATHOBJ_vEnumStartClipLines PROTO :XPTR, :XPTR, :XPTR, :XPTR
    PATHOBJ_vGetBounds PROTO :XPTR, :XPTR
    QueryFontAssocStatus PROTO
    RemoveFontMemResourceEx PROTO :HANDLE
    RemoveFontResourceExA PROTO :LPCTSTR, :XWORD, :PVOID
    RemoveFontResourceExW PROTO :LPCWSTR, :XWORD, :PVOID
    SetDCBrushColor PROTO :HDC, :XWORD
    SetDCPenColor PROTO :HDC, :XWORD
    SetLayoutWidth PROTO :HDC, :XWORD, :XWORD
    StartFormPage PROTO :HDC
    STROBJ_bEnum PROTO :XPTR, :XPTR, :XPTR
    STROBJ_bEnumPositionsOnly PROTO :XPTR, :XPTR, :XPTR
    STROBJ_bGetAdvanceWidths PROTO :XPTR, :XWORD, :XWORD, :XPTR
    STROBJ_dwGetCodePage PROTO :XPTR
    STROBJ_vEnumStart PROTO :XPTR
    XFORMOBJ_bApplyXform PROTO :XPTR, :XWORD, :XWORD, :PVOID, :PVOID
    XFORMOBJ_iGetXform PROTO :XPTR, :XPTR
    XLATEOBJ_cGetPalette PROTO :XPTR, :XWORD, :XWORD, :XPTR
    XLATEOBJ_hGetColorTransform PROTO :XPTR
    XLATEOBJ_iXlate PROTO :XPTR, :XWORD
    XLATEOBJ_piVector PROTO :XPTR
    IFDEF APP_UNICODE
        AddFontResourceEx EQU <AddFontResourceExW>
        CreateFontIndirectEx EQU <CreateFontIndirectExW>
        GetGlyphIndices EQU <GetGlyphIndicesW>
        RemoveFontResourceEx EQU <RemoveFontResourceExW>
    ELSE
        AddFontResourceEx EQU <AddFontResourceExA>
        CreateFontIndirectEx EQU <CreateFontIndirectExA>
        GetGlyphIndices EQU <GetGlyphIndicesA>
        RemoveFontResourceEx EQU <RemoveFontResourceExA>
    ENDIF
ENDIF

IF (NTDDI_VERSION GE NTDDI_WINXP)
    GetBrushAttributes PROTO :HBRUSH
    SetBitmapAttributes PROTO :HBITMAP, :XWORD
ENDIF

IF (NTDDI_VERSION GE NTDDI_VISTA)
    ConfigureOPMProtectedOutput PROTO :HANDLE, :XPTR, :XWORD, :XPTR
    CreateOPMProtectedOutputs PROTO :XPTR, :XWORD, :XWORD, :XPTR, :XPTR
    D3DKMTCheckExclusiveOwnership PROTO
    D3DKMTCheckMonitorPowerState PROTO :XPTR
    D3DKMTCheckOcclusion PROTO :XPTR
    D3DKMTCloseAdapter PROTO :XPTR
    D3DKMTCreateAllocation PROTO :XPTR
    D3DKMTCreateContext PROTO :XPTR
    D3DKMTCreateDCFromMemory PROTO :XPTR
    D3DKMTCreateDevice PROTO :XPTR
    D3DKMTCreateOverlay PROTO :XPTR
    D3DKMTCreateSynchronizationObject PROTO :XPTR
    D3DKMTDestroyAllocation PROTO :XPTR
    D3DKMTDestroyContext PROTO :XPTR
    D3DKMTDestroyDCFromMemory PROTO :XPTR
    D3DKMTDestroyDevice PROTO :XPTR
    D3DKMTDestroyOverlay PROTO :XPTR
    D3DKMTDestroySynchronizationObject PROTO :XPTR
    D3DKMTEscape PROTO :XPTR
    D3DKMTFlipOverlay PROTO :XPTR
    D3DKMTGetContextSchedulingPriority PROTO :XPTR
    D3DKMTGetDeviceState PROTO :XPTR
    D3DKMTGetDisplayModeList PROTO :XPTR
    D3DKMTGetMultisampleMethodList PROTO :XPTR
    D3DKMTGetPresentHistory PROTO :XPTR
    D3DKMTGetProcessSchedulingPriorityClass PROTO :HANDLE, :XPTR
    D3DKMTGetRuntimeData PROTO :XPTR
    D3DKMTGetScanLine PROTO :XPTR
    D3DKMTGetSharedPrimaryHandle PROTO :XPTR
    D3DKMTInvalidateActiveVidPn PROTO :XPTR
    D3DKMTLock PROTO :XPTR
    D3DKMTOpenAdapterFromDeviceName PROTO :XPTR
    D3DKMTOpenAdapterFromGdiDisplayName PROTO :XPTR
    D3DKMTOpenAdapterFromHdc PROTO :XPTR
    D3DKMTOpenResource PROTO :XPTR
    D3DKMTPollDisplayChildren PROTO :XPTR
    D3DKMTPresent PROTO :XPTR
    D3DKMTQueryAdapterInfo PROTO :XPTR
    D3DKMTQueryAllocationResidency PROTO :XPTR
    D3DKMTQueryResourceInfo PROTO :XPTR
    D3DKMTReleaseProcessVidPnSourceOwners PROTO :HANDLE
    D3DKMTRender PROTO :XPTR
    D3DKMTSetAllocationPriority PROTO :XPTR
    D3DKMTSetContextSchedulingPriority PROTO :XPTR
    D3DKMTSetDisplayMode PROTO :XPTR
    D3DKMTSetDisplayPrivateDriverFormat PROTO :XPTR
    D3DKMTSetGammaRamp PROTO :XPTR
    D3DKMTSetProcessSchedulingPriorityClass PROTO :HANDLE, :XWORD
    D3DKMTSetQueuedLimit PROTO :XPTR
    D3DKMTSetVidPnSourceOwner PROTO :XPTR
    D3DKMTSharedPrimaryLockNotification PROTO :XPTR
    D3DKMTSharedPrimaryUnLockNotification PROTO :XPTR
    D3DKMTSignalSynchronizationObject PROTO :XPTR
    D3DKMTUnlock PROTO :XPTR
    D3DKMTUpdateOverlay PROTO :XPTR
    D3DKMTWaitForIdle PROTO :XPTR
    D3DKMTWaitForSynchronizationObject PROTO :XPTR
    D3DKMTWaitForVerticalBlankEvent PROTO :XPTR
    DDCCIGetCapabilitiesString PROTO :HANDLE, :LPSTR, :XWORD
    DDCCIGetCapabilitiesStringLength PROTO :HANDLE, :XPTR
    DDCCIGetTimingReport PROTO :HANDLE, :XPTR
    DDCCIGetVCPFeature PROTO :HANDLE, :XWORD, :XPTR, :XPTR, :XPTR
    DDCCISaveCurrentSettings PROTO :HANDLE
    DDCCISetVCPFeature PROTO :HANDLE, :XWORD, :XWORD
    DestroyOPMProtectedOutput PROTO :HANDLE
    DestroyPhysicalMonitorInternal PROTO :HANDLE
    GdiIsScreenDC PROTO :HDC
    GetCOPPCompatibleOPMInformation PROTO :HANDLE, :XPTR, :XPTR
    GetNumberOfPhysicalMonitors PROTO :XPTR, :LPDWORD
    GetOPMInformation PROTO :HANDLE, :XPTR, :XPTR
    GetOPMRandomNumber PROTO :HANDLE, :XPTR
    GetPhysicalMonitorDescription PROTO :HANDLE, :XWORD, :LPWSTR
    GetPhysicalMonitors PROTO :XPTR, :XWORD, :XPTR, :XPTR
    GetSuggestedOPMProtectedOutputArraySize PROTO :XPTR, :XPTR
    SetOPMSigningKeyAndSequenceNumbers PROTO :HANDLE, :XPTR
ENDIF

IF (NTDDI_VERSION GE NTDDI_WIN7)
    D3DKMTAcquireKeyedMutex PROTO :XPTR
    D3DKMTCheckSharedResourceAccess PROTO :XPTR
    D3DKMTCheckVidPnExclusiveOwnership PROTO :XPTR
    D3DKMTConfigureSharedResource PROTO :XPTR
    D3DKMTCreateAllocation2 PROTO :XPTR
    D3DKMTCreateKeyedMutex PROTO :XPTR
    D3DKMTCreateSynchronizationObject2 PROTO :XPTR
    D3DKMTDestroyKeyedMutex PROTO :XPTR
    D3DKMTGetOverlayState PROTO :XPTR
    D3DKMTOpenKeyedMutex PROTO :XPTR
    D3DKMTOpenResource2 PROTO :XPTR
    D3DKMTOpenSynchronizationObject PROTO :XPTR
    D3DKMTReleaseKeyedMutex PROTO :XPTR
    D3DKMTSignalSynchronizationObject2 PROTO :XPTR
    D3DKMTWaitForSynchronizationObject2 PROTO :XPTR
ENDIF

IF (NTDDI_VERSION GE NTDDI_WIN8)
    D3DKMTAcquireKeyedMutex2 PROTO :XPTR
	D3DKMTCreateKeyedMutex2 PROTO :XPTR
    D3DKMTCreateOutputDupl PROTO :XPTR
    D3DKMTDestroyOutputDupl PROTO :XPTR
    D3DKMTEnumAdapters PROTO :XPTR
	D3DKMTGetContextInProcessSchedulingPriority PROTO :XPTR
    D3DKMTGetSharedResourceAdapterLuid PROTO :XPTR
    D3DKMTOfferAllocations PROTO :XPTR
    D3DKMTOpenAdapterFromLuid PROTO :XPTR
    D3DKMTOpenKeyedMutex2 PROTO :XPTR
    D3DKMTOpenNtHandleFromName PROTO :XPTR
    D3DKMTOpenResourceFromNtHandle PROTO :XPTR
    D3DKMTOpenSyncObjectFromNtHandle PROTO :XPTR
    D3DKMTOutputDuplGetFrameInfo PROTO :XPTR
    D3DKMTOutputDuplGetMetaData PROTO :XPTR
    D3DKMTOutputDuplGetPointerShapeData PROTO :XPTR
    D3DKMTOutputDuplPresent PROTO :XPTR
    D3DKMTOutputDuplReleaseFrame PROTO :XPTR
    D3DKMTPinDirectFlipResources PROTO :XPTR
	D3DKMTPresentMultiPlaneOverlay PROTO :XPTR
    D3DKMTQueryRemoteVidPnSourceFromGdiDisplayName PROTO :XPTR
    D3DKMTQueryResourceInfoFromNtHandle PROTO :XPTR
    D3DKMTReclaimAllocations PROTO :XPTR
    D3DKMTReleaseKeyedMutex2 PROTO :XPTR
    D3DKMTSetContextInProcessSchedulingPriority PROTO :XPTR
    D3DKMTSetStereoEnabled PROTO :XWORD
    D3DKMTSetVidPnSourceOwner1 PROTO :XPTR
    D3DKMTShareObjects PROTO :XWORD, :XPTR, :XPTR, :XWORD, :XPTR
    D3DKMTUnpinDirectFlipResources PROTO :XPTR
    D3DKMTWaitForVerticalBlankEvent2 PROTO :XPTR
    GetCertificateSize PROTO :HANDLE, :XPTR, :XPTR
    ScriptApplyDigitSubstitution PROTO :XPTR, :XPTR, :XPTR
    ScriptApplyLogicalWidth PROTO :XPTR, :XWORD, :XWORD, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR
    ScriptBreak PROTO :XPTR, :XWORD, :XPTR, :XPTR
    ScriptCPtoX PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR
    ScriptCacheGetHeight PROTO :HDC, :XPTR, :XPTR
    ScriptFreeCache PROTO :XPTR
    ScriptGetCMap PROTO :HDC, :XPTR, :XPTR, :XWORD, :XWORD, :XPTR
    ScriptGetFontAlternateGlyphs PROTO :HDC, :XPTR, :XPTR, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XPTR, :XPTR
    ScriptGetFontFeatureTags PROTO :HDC, :XPTR, :XPTR, :XWORD, :XWORD, :XWORD, :XPTR, :XPTR
    ScriptGetFontLanguageTags PROTO :HDC, :XPTR, :XPTR, :XWORD, :XWORD, :XPTR, :XPTR
    ScriptGetFontProperties PROTO :HDC, :XPTR, :XPTR
    ScriptGetFontScriptTags PROTO :HDC, :XPTR, :XPTR, :XWORD, :XPTR, :XPTR
    ScriptGetGlyphABCWidth PROTO :HDC, :XPTR, :XPTR, :XPTR
    ScriptGetLogicalWidths PROTO :XPTR, :XWORD, :XWORD, :XPTR, :XPTR, :XPTR, :XPTR
    ScriptGetProperties PROTO :XPTR, :XPTR
    ScriptIsComplex PROTO :XPTR, :XWORD, :XWORD
    ScriptItemize PROTO :XPTR, :XWORD, :XWORD, :XPTR, :XPTR, :XPTR, :XPTR
    ScriptItemizeOpenType PROTO :XPTR, :XWORD, :XWORD, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR
    ScriptJustify PROTO :XPTR, :XPTR, :XWORD, :XWORD, :XWORD, :XPTR
    ScriptLayout PROTO :XWORD, :XPTR, :XPTR, :XPTR
    ScriptPlace PROTO :HDC, :XPTR, :XPTR, :XWORD, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR
    ScriptPlaceOpenType PROTO :HDC, :XPTR, :XPTR, :XWORD, :XWORD, :XPTR, :XPTR, :XWORD, :XPTR, :XPTR, :XPTR, :XWORD, :XPTR, :XPTR, :XWORD, :XPTR, :XPTR, :XPTR
    ScriptPositionSingleGlyph PROTO :HDC, :XPTR, :XPTR, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XPTR, :XPTR
    ScriptRecordDigitSubstitution PROTO :XWORD, :XPTR
    ScriptShape PROTO :HDC, :XPTR, :XPTR, :XWORD, :XWORD, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR
    ScriptShapeOpenType PROTO :HDC, :XPTR, :XPTR, :XWORD, :XWORD, :XPTR, :XPTR, :XWORD, :XPTR, :XWORD, :XWORD, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR
    ScriptStringAnalyse PROTO :HDC, :XPTR, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR
    ScriptStringCPtoX PROTO :XPTR, :XWORD, :XWORD, :XPTR
    ScriptStringFree PROTO :XPTR
    ScriptStringGetLogicalWidths PROTO :XPTR, :XPTR
    ScriptStringGetOrder PROTO :XPTR, :XPTR
    ScriptStringOut PROTO :XPTR, :XWORD, :XWORD, :XWORD, :XPTR, :XWORD, :XWORD, :XWORD
    ScriptStringValidate PROTO :XPTR
    ScriptStringXtoCP PROTO :XPTR, :XWORD, :XPTR, :XPTR
    ScriptString_pLogAttr PROTO :XPTR
    ScriptString_pSize PROTO :XPTR
    ScriptString_pcOutChars PROTO :XPTR
    ScriptSubstituteSingleGlyph PROTO :HDC, :XPTR, :XPTR, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XPTR
    ScriptTextOut PROTO :HDC, :XPTR, :XWORD, :XWORD, :XWORD, :XPTR, :XPTR, :XPTR, :XWORD, :XPTR, :XWORD, :XPTR, :XPTR, :XPTR
    ScriptXtoCP PROTO :XWORD, :XWORD, :XWORD, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR
ENDIF

IF (NTDDI_VERSION GE NTDDI_WIN81)
	D3DKMTCheckMultiPlaneOverlaySupport PROTO :XPTR
	D3DKMTCheckMultiPlaneOverlaySupport2 PROTO :XPTR
ENDIF

IF (NTDDI_VERSION GE NTDDI_WIN10)
	D3DKMTCreateContextVirtual PROTO :XPTR
    D3DKMTCreatePagingQueue PROTO :XPTR
	D3DKMTDestroyAllocation2 PROTO :XPTR
	D3DKMTDestroyPagingQueue PROTO :XPTR
	D3DKMTEvict PROTO :XPTR
	D3DKMTFreeGpuVirtualAddress PROTO :XPTR
	D3DKMTLock2 PROTO :XPTR
	D3DKMTMakeResident PROTO :XPTR
	D3DKMTMapGpuVirtualAddress PROTO :XPTR
	D3DKMTOpenSyncObjectFromNtHandle2 PROTO :XPTR
	D3DKMTOpenSyncObjectNtHandleFromName PROTO :XPTR
	D3DKMTReclaimAllocations2 PROTO :XPTR
	D3DKMTRegisterTrimNotification PROTO :XPTR
	D3DKMTReserveGpuVirtualAddress PROTO :XPTR
	D3DKMTSignalSynchronizationObjectFromCpu PROTO :XPTR
	D3DKMTSignalSynchronizationObjectFromGpu PROTO :XPTR
	D3DKMTSignalSynchronizationObjectFromGpu2 PROTO :XPTR
	D3DKMTSubmitCommand PROTO :XPTR
	D3DKMTUnlock2 PROTO :XPTR
	D3DKMTUnregisterTrimNotification PROTO :XPTR
	D3DKMTUpdateGpuVirtualAddress PROTO :XPTR
	D3DKMTWaitForSynchronizationObjectFromCpu PROTO :XPTR
	D3DKMTWaitForSynchronizationObjectFromGpu PROTO :XPTR
ENDIF

IFDEF APP_UNICODE
    AXESLIST EQU <AXESLISTW>
    AXISINFO EQU <AXISINFOW>
    DEVMODE EQU <DEVMODEW>
    DISPLAY_DEVICE EQU <DISPLAY_DEVICEW>
    DOCINFO EQU <DOCINFOW>
    EMREXTTEXTOUT EQU <EMREXTTEXTOUTW>
    EMRPOLYTEXTOUT EQU <EMRPOLYTEXTOUTW>
    EMREXTCREATEFONTINDIRECT EQU <EMREXTCREATEFONTINDIRECTW>
    ENUMLOGFONT EQU <ENUMLOGFONTW>
    ENUMLOGFONTEX EQU <ENUMLOGFONTEXW>
    ENUMLOGFONTEXDV EQU <ENUMLOGFONTEXDVW>
    ENUMTEXTMETRIC EQU <ENUMTEXTMETRICW>
    EXTLOGFONT EQU <EXTLOGFONTW>
    GCP_RESULTS EQU <GCP_RESULTSW>
    LOGCOLORSPACE EQU <LOGCOLORSPACEW>
    IFNDEF LOGFONT
        LOGFONT EQU <LOGFONTW>
    ENDIF
    NEWTEXTMETRIC EQU <NEWTEXTMETRICW>
    NEWTEXTMETRICEX EQU <NEWTEXTMETRICEXW>
    OUTLINETEXTMETRIC EQU <OUTLINETEXTMETRICW>
    TEXTMETRIC EQU <TEXTMETRICW>
    POLYTEXT EQU <POLYTEXTW>
    AddFontResource EQU <AddFontResourceW>
    CopyEnhMetaFile EQU <CopyEnhMetaFileW>
    CopyMetaFile EQU <CopyMetaFileW>
    CreateColorSpace EQU <CreateColorSpaceW>
    CreateDC EQU <CreateDCW>
    CreateEnhMetaFile EQU <CreateEnhMetaFileW>
    CreateFont EQU <CreateFontW>
    CreateFontIndirect EQU <CreateFontIndirectW>
    CreateIC EQU <CreateICW>
    CreateMetaFile EQU <CreateMetaFileW>
    CreateScalableFontResource EQU <CreateScalableFontResourceW>
    DeviceCapabilitiesEx EQU <DeviceCapabilitiesExW>
    EnumFontFamilies EQU <EnumFontFamiliesW>
    EnumFontFamiliesEx EQU <EnumFontFamiliesExW>
    EnumFonts EQU <EnumFontsW>
    EnumICMProfiles EQU <EnumICMProfilesW>
    ExtTextOut EQU <ExtTextOutW>
    GetCharABCWidths EQU <GetCharABCWidthsW>
    GetCharABCWidthsFloat EQU <GetCharABCWidthsFloatW>
    GetCharWidth EQU <GetCharWidthW>
    GetCharWidth32 EQU <GetCharWidth32W>
    GetCharWidthFloat EQU <GetCharWidthFloatW>
    GetCharacterPlacement EQU <GetCharacterPlacementW>
    GetEnhMetaFile EQU <GetEnhMetaFileW>
    GetEnhMetaFileDescription EQU <GetEnhMetaFileDescriptionW>
    GetGlyphOutline EQU <GetGlyphOutlineW>
    GetICMProfile EQU <GetICMProfileW>
    GetKerningPairs EQU <GetKerningPairsW>
    GetLogColorSpace EQU <GetLogColorSpaceW>
    GetMetaFile EQU <GetMetaFileW>
    GetObject EQU <GetObjectW>
    GetOutlineTextMetrics EQU <GetOutlineTextMetricsW>
    GetTextExtentExPoint EQU <GetTextExtentExPointW>
    GetTextExtentPoint32 EQU <GetTextExtentPoint32W>
    GetTextExtentPoint EQU <GetTextExtentPointW>
    GetTextFace EQU <GetTextFaceW>
    GetTextMetrics EQU <GetTextMetricsW>
    PolyTextOut EQU <PolyTextOutW>
    RemoveFontResource EQU <RemoveFontResourceW>
    ResetDC EQU <ResetDCW>
    SetICMProfile EQU <SetICMProfileW>
    StartDoc EQU <StartDocW>
    TextOut EQU <TextOutW>
    UpdateICMRegKey EQU <UpdateICMRegKeyW>
ELSE
    AXESLIST EQU <AXESLISTA>
    AXISINFO EQU <AXISINFOA>
    DEVMODE EQU <DEVMODEA>
    DISPLAY_DEVICE EQU <DISPLAY_DEVICEA>
    DOCINFO EQU <DOCINFOA>
    EMREXTTEXTOUT EQU <EMREXTTEXTOUTA>
    EMRPOLYTEXTOUT EQU <EMRPOLYTEXTOUTA>
    EMREXTCREATEFONTINDIRECT EQU <EMREXTCREATEFONTINDIRECTA>
    ENUMLOGFONT EQU <ENUMLOGFONTA>
    ENUMLOGFONTEX EQU <ENUMLOGFONTEXA>
    ENUMLOGFONTEXDV EQU <ENUMLOGFONTEXDVA>
    ENUMTEXTMETRIC EQU <ENUMTEXTMETRICA>
    EXTLOGFONT EQU <EXTLOGFONTA>
    GCP_RESULTS EQU <GCP_RESULTSA>
    LOGCOLORSPACE EQU <LOGCOLORSPACEA>
    IFNDEF LOGFONT
        LOGFONT EQU <LOGFONTA>
    ENDIF
    NEWTEXTMETRIC EQU <NEWTEXTMETRICA>
    NEWTEXTMETRICEX EQU <NEWTEXTMETRICEXA>
    OUTLINETEXTMETRIC EQU <OUTLINETEXTMETRICA>
    TEXTMETRIC EQU <TEXTMETRICA>
    POLYTEXT EQU <POLYTEXTA>
    AddFontResource EQU <AddFontResourceA>
    CopyEnhMetaFile EQU <CopyEnhMetaFileA>
    CopyMetaFile EQU <CopyMetaFileA>
    CreateColorSpace EQU <CreateColorSpaceA>
    CreateDC EQU <CreateDCA>
    CreateEnhMetaFile EQU <CreateEnhMetaFileA>
    CreateFont EQU <CreateFontA>
    CreateFontIndirect EQU <CreateFontIndirectA>
    CreateIC EQU <CreateICA>
    CreateMetaFile EQU <CreateMetaFileA>
    CreateScalableFontResource EQU <CreateScalableFontResourceA>
    DeviceCapabilitiesEx EQU <DeviceCapabilitiesExA>
    EnumFontFamilies EQU <EnumFontFamiliesA>
    EnumFontFamiliesEx EQU <EnumFontFamiliesExA>
    EnumFonts EQU <EnumFontsA>
    EnumICMProfiles EQU <EnumICMProfilesA>
    ExtTextOut EQU <ExtTextOutA>
    GetCharABCWidths EQU <GetCharABCWidthsA>
    GetCharABCWidthsFloat EQU <GetCharABCWidthsFloatA>
    GetCharWidth EQU <GetCharWidthA>
    GetCharWidth32 EQU <GetCharWidth32A>
    GetCharWidthFloat EQU <GetCharWidthFloatA>
    GetCharacterPlacement EQU <GetCharacterPlacementA>
    GetEnhMetaFile EQU <GetEnhMetaFileA>
    GetEnhMetaFileDescription EQU <GetEnhMetaFileDescriptionA>
    GetGlyphOutline EQU <GetGlyphOutlineA>
    GetICMProfile EQU <GetICMProfileA>
    GetKerningPairs EQU <GetKerningPairsA>
    GetLogColorSpace EQU <GetLogColorSpaceA>
    GetMetaFile EQU <GetMetaFileA>
    GetObject EQU <GetObjectA>
    GetOutlineTextMetrics EQU <GetOutlineTextMetricsA>
    GetTextExtentExPoint EQU <GetTextExtentExPointA>
    GetTextExtentPoint32 EQU <GetTextExtentPoint32A>
    GetTextExtentPoint EQU <GetTextExtentPointA>
    GetTextFace EQU <GetTextFaceA>
    GetTextMetrics EQU <GetTextMetricsA>
    PolyTextOut EQU <PolyTextOutA>
    RemoveFontResource EQU <RemoveFontResourceA>
    ResetDC EQU <ResetDCA>
    SetICMProfile EQU <SetICMProfileA>
    StartDoc EQU <StartDocA>
    TextOut EQU <TextOutA>
    UpdateICMRegKey EQU <UpdateICMRegKeyA>
ENDIF

;======================= Undocumented functions (unknown arguments) =======================;
;AddFontResourceTracking PROTO
;AnyLinkedFonts PROTO
;BeginGdiRendering PROTO
;ClearBitmapAttributes PROTO
;ClearBrushAttributes PROTO
;CreateBitmapFromDxSurface PROTO
;CreateBitmapFromDxSurface2 PROTO
;CreateSessionMappedDIBSection PROTO
;D3DKMTAbandonSwapChain PROTO
;D3DKMTAcquireSwapChain PROTO
;D3DKMTAdjustFullscreenGamma PROTO
;D3DKMTCacheHybridQueryValue PROTO
;D3DKMTChangeVideoMemoryReservation PROTO
;D3DKMTCreateSwapChain PROTO
;D3DKMTEnumAdapters2 PROTO
;D3DKMTFlushHeapTransitions PROTO
;D3DKMTGetCachedHybridQueryValue PROTO
;D3DKMTGetDWMVerticalBlankEvent PROTO
;D3DKMTGetPresentQueueEvent PROTO
;D3DKMTGetResourcePresentPrivateDriverData PROTO
;D3DKMTGetSetSwapChainMetadata PROTO
;D3DKMTInvalidateCache PROTO
;D3DKMTMarkDeviceAsError PROTO
;D3DKMTNetDispGetNextChunkInfo PROTO
;D3DKMTNetDispQueryMiracastDisplayDeviceStatus PROTO
;D3DKMTNetDispQueryMiracastDisplayDeviceSupport PROTO
;D3DKMTNetDispStartMiracastDisplayDevice PROTO
;D3DKMTNetDispStartMiracastDisplayDevice2 PROTO
;D3DKMTNetDispStartMiracastDisplayDeviceEx PROTO
;D3DKMTNetDispStopMiracastDisplayDevice PROTO
;D3DKMTNetDispStopSessions PROTO
;D3DKMTOpenSwapChain PROTO
;D3DKMTPresentMultiPlaneOverlay2 PROTO
;D3DKMTQueryClockCalibration PROTO
;D3DKMTQueryStatistics PROTO
;D3DKMTQueryVideoMemoryInfo PROTO
;D3DKMTQueryVidPnExclusiveOwnership PROTO
;D3DKMTReleaseSwapChain PROTO
;D3DKMTSetDodIndirectSwapchain PROTO
;D3DKMTSetHwProtectionTeardownRecovery PROTO
;D3DKMTSetStablePowerState PROTO
;D3DKMTSetSyncRefreshCountWaitTarget PROTO
;D3DKMTSetVidPnSourceHwProtection PROTO
;DdCreateFullscreenSprite PROTO
;DdDestroyFullscreenSprite PROTO
;DdEntry0 PROTO
;DdEntry1 PROTO
;DdEntry10 PROTO
;DdEntry11 PROTO
;DdEntry12 PROTO
;DdEntry13 PROTO
;DdEntry14 PROTO
;DdEntry15 PROTO
;DdEntry16 PROTO
;DdEntry17 PROTO
;DdEntry18 PROTO
;DdEntry19 PROTO
;DdEntry2 PROTO
;DdEntry20 PROTO
;DdEntry21 PROTO
;DdEntry22 PROTO
;DdEntry23 PROTO
;DdEntry24 PROTO
;DdEntry25 PROTO
;DdEntry26 PROTO
;DdEntry27 PROTO
;DdEntry28 PROTO
;DdEntry29 PROTO
;DdEntry3 PROTO
;DdEntry30 PROTO
;DdEntry31 PROTO
;DdEntry32 PROTO
;DdEntry33 PROTO
;DdEntry34 PROTO
;DdEntry35 PROTO
;DdEntry36 PROTO
;DdEntry37 PROTO
;DdEntry38 PROTO
;DdEntry39 PROTO
;DdEntry4 PROTO
;DdEntry40 PROTO
;DdEntry41 PROTO
;DdEntry42 PROTO
;DdEntry43 PROTO
;DdEntry44 PROTO
;DdEntry45 PROTO
;DdEntry46 PROTO
;DdEntry47 PROTO
;DdEntry48 PROTO
;DdEntry49 PROTO
;DdEntry5 PROTO
;DdEntry50 PROTO
;DdEntry51 PROTO
;DdEntry52 PROTO
;DdEntry53 PROTO
;DdEntry54 PROTO
;DdEntry55 PROTO
;DdEntry56 PROTO
;DdEntry6 PROTO
;DdEntry7 PROTO
;DdEntry8 PROTO
;DdEntry9 PROTO
;DdNotifyFullscreenSpriteUpdate PROTO
;DdQueryVisRgnUniqueness PROTO
;DwmGetDirtyRgn PROTO
;DwmGetSurfaceData
;EndFormPage PROTO
;EndGdiRendering PROTO
;EngQueryEMFInfo PROTO
;EudcLoadLinkW PROTO
;EudcUnloadLinkW PROTO
;FontIsLinked PROTO
;ftsWordBreak
;GdiAddGlsRecord PROTO
;GdiClearStockObjectCache PROTO
;GdiConvertMetaFilePict PROTO
;GdiConvertToDevmodeW PROTO
;GdiCreateLocalEnhMetaFile PROTO
;GdiCreateLocalMetaFilePict PROTO
;GdiDrawStream PROTO
;GdiIsUMPDSandboxingEnabled PROTO
;GdiEntry1 PROTO
;GdiEntry10 PROTO
;GdiEntry11 PROTO
;GdiEntry12 PROTO
;GdiEntry13 PROTO
;GdiEntry14 PROTO
;GdiEntry15 PROTO
;GdiEntry16 PROTO
;GdiEntry2 PROTO
;GdiEntry3 PROTO
;GdiEntry4 PROTO
;GdiEntry5 PROTO
;GdiEntry6 PROTO
;GdiEntry7 PROTO
;GdiEntry8 PROTO
;GdiEntry9 PROTO
;GdiLoadType1Fonts PROTO
;GdiPlayPrivatePageEMF PROTO
;GdiSupportsFontChangeEvent PROTO
;GdiSwapBuffers PROTO
;GetBitmapAttributes PROTO
;GetCertificate PROTO
;GetCertificateByHandle PROTO
;GetCertificateSizeByHandle PROTO
;GetCurrentDpiInfo PROTO
;GetFontFileData PROTO
;GetFontFileInfo PROTO
;GetFontRealizationInfo PROTO
;GetRelAbs PROTO
;GetStringBitmapA PROTO
;GetStringBitmapW PROTO
;GetTransform PROTO
;LpkDrawTextEx PROTO
;LpkEditControl PROTO
;LpkExtTextOut PROTO
;LpkGetCharacterPlacement PROTO
;LpkGetTextExtentExPoint PROTO
;LpkInitialize PROTO
;LpkPSMTextOut PROTO
;LpkPresent PROTO
;LpkTabbedTextOut PROTO
;LpkUseGDIWidthCache PROTO
;NamedEscape PROTO
;RemoveFontResourceTracking PROTO
;SetBrushAttributes PROTO
;SetRelAbs PROTO
;SetVirtualResolution PROTO
;UnloadNetworkFonts PROTO
;UspAllocCache PROTO
;UspAllocTemp PROTO
;UspFreeMem PROTO
;bInitSystemAndFontsDirectoriesW PROTO
;bMakePathNameW PROTO
;cGetTTFFromFOT PROTO
;pfnRealizePalette PROTO
;pfnSelectPalette PROTO

;IFDEF APP_UNICODE
;    GetStringBitmap EQU <GetStringBitmapW>
;ELSE
;    GetStringBitmap EQU <GetStringBitmapA>
;ENDIF

ENDIF ;GDI32_INC
