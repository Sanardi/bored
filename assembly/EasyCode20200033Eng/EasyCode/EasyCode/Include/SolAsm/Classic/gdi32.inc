; ====================================================;
;                                                     ;
;     gdi32.inc for EC v2 SolAsm classic projects     ;
;                   (version 1.0.2)                   ;
;                                                     ;
;         Copyright © Ramon Sala - 2018-2019          ;
;                                                     ;
; ====================================================;

#ifndef GDI32_INC
GDI32_INC equ 1

R2_BLACK                                        equ     1
R2_NOTMERGEPEN                                  equ     2
R2_MASKNOTPEN                                   equ     3
R2_NOTCOPYPEN                                   equ     4
R2_MASKPENNOT                                   equ     5
R2_NOT                                          equ     6
R2_XORPEN                                       equ     7
R2_NOTMASKPEN                                   equ     8
R2_MASKPEN                                      equ     9
R2_NOTXORPEN                                    equ     10
R2_NOP                                          equ     11
R2_MERGENOTPEN                                  equ     12
R2_COPYPEN                                      equ     13
R2_MERGEPENNOT                                  equ     14
R2_MERGEPEN                                     equ     15
R2_WHITE                                        equ     16
R2_LAST                                         equ     16

SRCCOPY                                         equ     000CC0020H
SRCPAINT                                        equ     000EE0086H
SRCAND                                          equ     0008800C6H
SRCINVERT                                       equ     000660046H
SRCERASE                                        equ     000440328H
NOTSRCCOPY                                      equ     000330008H
NOTSRCERASE                                     equ     0001100A6H
MERGECOPY                                       equ     000C000CAH
MERGEPAINT                                      equ     000BB0226H
PATCOPY                                         equ     000F00021H
PATPAINT                                        equ     000FB0A09H
PATINVERT                                       equ     0005A0049H
DSTINVERT                                       equ     000550009H
BLACKNESS                                       equ     000000042H
WHITENESS                                       equ     000FF0062H

NOMIRRORBITMAP                                  equ     080000000H
CAPTUREBLT                                      equ     040000000H

GDI_ERROR                                       equ     0FFFFFFFFH
HGDI_ERROR                                      equ     0FFFFFFFFH

ERROR                                           equ     0
NULLREGION                                      equ     1
SIMPLEREGION                                    equ     2
COMPLEXREGION                                   equ     3
RGN_ERROR                                       equ     ERROR

RGN_AND                                         equ     1
RGN_OR                                          equ     2
RGN_XOR                                         equ     3
RGN_DIFF                                        equ     4
RGN_COPY                                        equ     5
RGN_MIN                                         equ     RGN_AND
RGN_MAX                                         equ     RGN_COPY

BLACKONWHITE                                    equ     1
WHITEONBLACK                                    equ     2
COLORONCOLOR                                    equ     3
HALFTONE                                        equ     4
MAXSTRETCHBLTMODE                               equ     4

STRETCH_ANDSCANS                                equ     BLACKONWHITE
STRETCH_ORSCANS                                 equ     WHITEONBLACK
STRETCH_DELETESCANS                             equ     COLORONCOLOR
STRETCH_HALFTONE                                equ     HALFTONE

ALTERNATE                                       equ     1
WINDING                                         equ     2
POLYFILL_LAST                                   equ     2

LAYOUT_RTL                                      equ     00000001H
LAYOUT_BTT                                      equ     00000002H
LAYOUT_VBH                                      equ     00000004H
LAYOUT_ORIENTATIONMASK                          equ     <LAYOUT_RTL or LAYOUT_BTT or LAYOUT_VBH>
LAYOUT_BITMAPORIENTATIONPRESERVED               equ     00000008H

TA_NOUPDATECP                                   equ     0
TA_UPDATECP                                     equ     1

TA_LEFT                                         equ     0
TA_RIGHT                                        equ     2
TA_CENTER                                       equ     6

TA_TOP                                          equ     0
TA_BOTTOM                                       equ     8
TA_BASELINE                                     equ     24
TA_RTLREADING                                   equ     256
TA_MASK                                         equ     <TA_BASELINE + TA_CENTER + TA_UPDATECP + TA_RTLREADING>

VTA_BASELINE                                    equ     TA_BASELINE
VTA_LEFT                                        equ     TA_BOTTOM
VTA_RIGHT                                       equ     TA_TOP
VTA_CENTER                                      equ     TA_CENTER
VTA_BOTTOM                                      equ     TA_RIGHT
VTA_TOP                                         equ     TA_LEFT

ETO_OPAQUE                                      equ     00002H
ETO_CLIPPED                                     equ     00004H
ETO_GLYPH_INDEX                                 equ     00010H
ETO_RTLREADING                                  equ     00080H
ETO_NUMERICSLOCAL                               equ     00400H
ETO_NUMERICSLATIN                               equ     00800H
ETO_IGNORELANGUAGE                              equ     01000H
ETO_PDY                                         equ     02000H
ETO_REVERSE_INDEX_MAP                           equ     10000H

ASPECT_FILTERING                                equ     00001H

DCB_RESET                                       equ     00001H
DCB_ACCUMULATE                                  equ     00002H
DCB_DIRTY                                       equ     DCB_ACCUMULATE
DCB_SET                                         equ     <DCB_RESET or DCB_ACCUMULATE>
DCB_ENABLE                                      equ     00004H
DCB_DISABLE                                     equ     00008H

META_SETBKCOLOR                                 equ     00201H
META_SETBKMODE                                  equ     00102H
META_SETMAPMODE                                 equ     00103H
META_SETROP2                                    equ     00104H
META_SETRELABS                                  equ     00105H
META_SETPOLYFILLMODE                            equ     00106H
META_SETSTRETCHBLTMODE                          equ     00107H
META_SETTEXTCHAREXTRA                           equ     00108H
META_SETTEXTCOLOR                               equ     00209H
META_SETTEXTJUSTIFICATION                       equ     0020AH
META_SETWINDOWORG                               equ     0020BH
META_SETWINDOWEXT                               equ     0020CH
META_SETVIEWPORTORG                             equ     0020DH
META_SETVIEWPORTEXT                             equ     0020EH
META_OFFSETWINDOWORG                            equ     0020FH
META_SCALEWINDOWEXT                             equ     00410H
META_OFFSETVIEWPORTORG                          equ     00211H
META_SCALEVIEWPORTEXT                           equ     00412H
META_LINETO                                     equ     00213H
META_MOVETO                                     equ     00214H
META_EXCLUDECLIPRECT                            equ     00415H
META_INTERSECTCLIPRECT                          equ     00416H
META_ARC                                        equ     00817H
META_ELLIPSE                                    equ     00418H
META_FLOODFILL                                  equ     00419H
META_PIE                                        equ     0081AH
META_RECTANGLE                                  equ     0041BH
META_ROUNDRECT                                  equ     0061CH
META_PATBLT                                     equ     0061DH
META_SAVEDC                                     equ     0001EH
META_SETPIXEL                                   equ     0041FH
META_OFFSETCLIPRGN                              equ     00220H
META_TEXTOUT                                    equ     00521H
META_BITBLT                                     equ     00922H
META_STRETCHBLT                                 equ     00B23H
META_POLYGON                                    equ     00324H
META_POLYLINE                                   equ     00325H
META_ESCAPE                                     equ     00626H
META_RESTOREDC                                  equ     00127H
META_FILLREGION                                 equ     00228H
META_FRAMEREGION                                equ     00429H
META_INVERTREGION                               equ     0012AH
META_PAINTREGION                                equ     0012BH
META_SELECTCLIPREGION                           equ     0012CH
META_SELECTOBJECT                               equ     0012DH
META_SETTEXTALIGN                               equ     0012EH
META_CHORD                                      equ     00830H
META_SETMAPPERFLAGS                             equ     00231H
META_EXTTEXTOUT                                 equ     00A32H
META_SETDIBTODEV                                equ     00D33H
META_SELECTPALETTE                              equ     00234H
META_REALIZEPALETTE                             equ     00035H
META_ANIMATEPALETTE                             equ     00436H
META_SETPALENTRIES                              equ     00037H
META_POLYPOLYGON                                equ     00538H
META_RESIZEPALETTE                              equ     00139H
META_DIBBITBLT                                  equ     00940H
META_DIBSTRETCHBLT                              equ     00B41H
META_DIBCREATEPATTERNBRUSH                      equ     00142H
META_STRETCHDIB                                 equ     00F43H
META_EXTFLOODFILL                               equ     00548H
META_DELETEOBJECT                               equ     001F0H
META_CREATEPALETTE                              equ     000F7H
META_CREATEPATTERNBRUSH                         equ     001F9H
META_CREATEPENINDIRECT                          equ     002FAH
META_CREATEFONTINDIRECT                         equ     002FBH
META_CREATEBRUSHINDIRECT                        equ     002FCH
META_CREATEREGION                               equ     006FFH

NEWFRAME                                        equ     1
ABORTDOC                                        equ     2
NEXTBAND                                        equ     3
SETCOLORTABLE                                   equ     4
GETCOLORTABLE                                   equ     5
FLUSHOUTPUT                                     equ     6
DRAFTMODE                                       equ     7
QUERYESCSUPPORT                                 equ     8
SETABORTPROC                                    equ     9
STARTDOC                                        equ     10
ENDDOC                                          equ     11
GETPHYSPAGESIZE                                 equ     12
GETPRINTINGOFFSET                               equ     13
GETSCALINGFACTOR                                equ     14
MFCOMMENT                                       equ     15
GETPENWIDTH                                     equ     16
SETCOPYCOUNT                                    equ     17
SELECTPAPERSOURCE                               equ     18
DEVICEDATA                                      equ     19
PASSTHROUGH                                     equ     19
GETTECHNOLGY                                    equ     20
GETTECHNOLOGY                                   equ     20
SETLINECAP                                      equ     21
SETLINEJOIN                                     equ     22
SETMITERLIMIT                                   equ     23
BANDINFO                                        equ     24
DRAWPATTERNRECT                                 equ     25
GETVECTORPENSIZE                                equ     26
GETVECTORBRUSHSIZE                              equ     27
ENABLEDUPLEX                                    equ     28
GETSETPAPERBINS                                 equ     29
GETSETPRINTORIENT                               equ     30
ENUMPAPERBINS                                   equ     31
SETDIBSCALING                                   equ     32
EPSPRINTING                                     equ     33
ENUMPAPERMETRICS                                equ     34
GETSETPAPERMETRICS                              equ     35
POSTSCRIPT_DATA                                 equ     37
POSTSCRIPT_IGNORE                               equ     38
MOUSETRAILS                                     equ     39
GETDEVICEUNITS                                  equ     42

GETEXTENDEDTEXTMETRICS                          equ     256
GETEXTENTTABLE                                  equ     257
GETPAIRKERNTABLE                                equ     258
GETTRACKKERNTABLE                               equ     259
EXTTEXTOUT                                      equ     512
GETFACENAME                                     equ     513
DOWNLOADFACE                                    equ     514
ENABLERELATIVEWIDTHS                            equ     768
ENABLEPAIRKERNING                               equ     769
SETKERNTRACK                                    equ     770
SETALLJUSTVALUES                                equ     771
SETCHARSET                                      equ     772

STRETCHBLT                                      equ     2048
GETSETSCREENPARAMS                              equ     3072
QUERYDIBSUPPORT                                 equ     3073
BEGIN_PATH                                      equ     4096
CLIP_TO_PATH                                    equ     4097
END_PATH                                        equ     4098
EXT_DEVICE_CAPS                                 equ     4099
RESTORE_CTM                                     equ     4100
SAVE_CTM                                        equ     4101
SET_ARC_DIRECTION                               equ     4102
SET_BACKGROUND_COLOR                            equ     4103
SET_POLY_MODE                                   equ     4104
SET_SCREEN_ANGLE                                equ     4105
SET_SPREAD                                      equ     4106
TRANSFORM_CTM                                   equ     4107
SET_CLIP_BOX                                    equ     4108
SET_BOUNDS                                      equ     4109
SET_MIRROR_MODE                                 equ     4110
OPENCHANNEL                                     equ     4110
DOWNLOADHEADER                                  equ     4111
CLOSECHANNEL                                    equ     4112
POSTSCRIPT_PASSTHROUGH                          equ     4115
ENCAPSULATED_POSTSCRIPT                         equ     4116

POSTSCRIPT_IDENTIFY                             equ     4117
POSTSCRIPT_INJECTION                            equ     4118

CHECKJPEGFORMAT                                 equ     4119
CHECKPNGFORMAT                                  equ     4120
GET_PS_FEATURESETTING                           equ     4121

SPCLPASSTHROUGH2                                equ     4568

PSIDENT_GDICENTRIC                              equ     0
PSIDENT_PSCENTRIC                               equ     1

PSINJECT_APPEND                                 equ     0
PSINJECT_REPLACE                                equ     1

PSINJECT_BEGINSTREAM                            equ     1
PSINJECT_PSADOBE                                equ     2
PSINJECT_PAGESATEND                             equ     3
PSINJECT_PAGES                                  equ     4
PSINJECT_DOCNEEDEDRES                           equ     5
PSINJECT_DOCSUPPLIEDRES                         equ     6
PSINJECT_PAGEORDER                              equ     7
PSINJECT_ORIENTATION                            equ     8
PSINJECT_BOUNDINGBOX                            equ     9
PSINJECT_DOCUMENTPROCESSCOLORS                  equ     10
PSINJECT_COMMENTS                               equ     11
PSINJECT_BEGINDEFAULTS                          equ     12
PSINJECT_ENDDEFAULTS                            equ     13
PSINJECT_BEGINPROLOG                            equ     14
PSINJECT_ENDPROLOG                              equ     15
PSINJECT_BEGINSETUP                             equ     16
PSINJECT_ENDSETUP                               equ     17
PSINJECT_TRAILER                                equ     18
PSINJECT_EOF                                    equ     19
PSINJECT_ENDSTREAM                              equ     20
PSINJECT_DOCUMENTPROCESSCOLORSATEND             equ     21
PSINJECT_PAGENUMBER                             equ     100
PSINJECT_BEGINPAGESETUP                         equ     101
PSINJECT_ENDPAGESETUP                           equ     102
PSINJECT_PAGETRAILER                            equ     103
PSINJECT_PLATECOLOR                             equ     104
PSINJECT_SHOWPAGE                               equ     105
PSINJECT_PAGEBBOX                               equ     106
PSINJECT_ENDPAGECOMMENTS                        equ     107
PSINJECT_VMSAVE                                 equ     200
PSINJECT_VMRESTORE                              equ     201
PSINJECT_DLFONT                                 equ     0DDDDDDDDH

FEATURESETTING_NUP                              equ     0
FEATURESETTING_OUTPUT                           equ     1
FEATURESETTING_PSLEVEL                          equ     2
FEATURESETTING_CUSTPAPER                        equ     3
FEATURESETTING_MIRROR                           equ     4
FEATURESETTING_NEGATIVE                         equ     5
FEATURESETTING_PROTOCOL                         equ     6
#if NTDDI_VERSION >= NTDDI_WINXP
    FEATURESETTING_PRIVATE_BEGIN                equ     01000H
    FEATURESETTING_PRIVATE_END                  equ     01FFFH
#endif

PSPROTOCOL_ASCII                                equ     0
PSPROTOCOL_BCP                                  equ     1
PSPROTOCOL_TBCP                                 equ     2
PSPROTOCOL_BINARY                               equ     3

QDI_SETDIBITS                                   equ     1
QDI_GETDIBITS                                   equ     2
QDI_DIBTOSCREEN                                 equ     4
QDI_STRETCHDIB                                  equ     8

SP_NOTREPORTED                                  equ     04000H
SP_ERROR                                        equ     (-1)
SP_APPABORT                                     equ     (-2)
SP_USERABORT                                    equ     (-3)
SP_OUTOFDISK                                    equ     (-4)
SP_OUTOFMEMORY                                  equ     (-5)

PR_JOBSTATUS                                    equ     00000H

OBJ_PEN                                         equ     1
OBJ_BRUSH                                       equ     2
OBJ_DC                                          equ     3
OBJ_METADC                                      equ     4
OBJ_PAL                                         equ     5
OBJ_FONT                                        equ     6
OBJ_BITMAP                                      equ     7
OBJ_REGION                                      equ     8
OBJ_METAFILE                                    equ     9
OBJ_MEMDC                                       equ     10
OBJ_EXTPEN                                      equ     11
OBJ_ENHMETADC                                   equ     12
OBJ_ENHMETAFILE                                 equ     13
OBJ_COLORSPACE                                  equ     14
GDI_OBJ_LAST                                    equ     OBJ_COLORSPACE

MWT_IDENTITY                                    equ     1
MWT_LEFTMULTIPLY                                equ     2
MWT_RIGHTMULTIPLY                               equ     3

MWT_MIN                                         equ     MWT_IDENTITY
MWT_MAX                                         equ     MWT_RIGHTMULTIPLY

CS_ENABLE                                       equ     000000001H
CS_DISABLE                                      equ     000000002H
CS_DELETE_TRANSFORM                             equ     000000003H

LCS_CALIBRATED_RGB                              equ     000000000H
LCS_DEVICE_RGB                                  equ     000000001H
LCS_DEVICE_CMYK                                 equ     000000002H

LCS_GM_BUSINESS                                 equ     000000001H
LCS_GM_GRAPHICS                                 equ     000000002H
LCS_GM_IMAGES                                   equ     000000004H
LCS_GM_ABS_COLORIMETRIC                         equ     000000008H

CM_OUT_OF_GAMUT                                 equ     255
CM_IN_GAMUT                                     equ     0

ICM_ADDPROFILE                                  equ     1
ICM_DELETEPROFILE                               equ     2
ICM_QUERYPROFILE                                equ     3
ICM_SETDEFAULTPROFILE                           equ     4
ICM_REGISTERICMATCHER                           equ     5
ICM_UNREGISTERICMATCHER                         equ     6
ICM_QUERYMATCH                                  equ     7

BI_RGB                                          equ     0
BI_RLE8                                         equ     1
BI_RLE4                                         equ     2
BI_BITFIELDS                                    equ     3
BI_JPEG                                         equ     4
BI_PNG                                          equ     5

TCI_SRCCHARSET                                  equ     1
TCI_SRCCODEPAGE                                 equ     2
TCI_SRCFONTSIG                                  equ     3
#if NTDDI_VERSION >= NTDDI_WINXP
    TCI_SRCLOCALE                               equ     1000H
#endif

TMPF_FIXED_PITCH                                equ     001H
TMPF_VECTOR                                     equ     002H
TMPF_DEVICE                                     equ     008H
TMPF_TRUETYPE                                   equ     004H

NTM_REGULAR                                     equ     000000040H
NTM_BOLD                                        equ     000000020H
NTM_ITALIC                                      equ     000000001H

NTM_NONNEGATIVE_AC                              equ     000010000H
NTM_PS_OPENTYPE                                 equ     000020000H
NTM_TT_OPENTYPE                                 equ     000040000H
NTM_MULTIPLEMASTER                              equ     000040000H
NTM_MM_INSTANCE                                 equ     000080000H
NTM_TYPE1                                       equ     000100000H
NTM_DSIG                                        equ     000200000H

OUT_DEFAULT_PRECIS                              equ     0
OUT_STRING_PRECIS                               equ     1
OUT_CHARACTER_PRECIS                            equ     2
OUT_STROKE_PRECIS                               equ     3
OUT_TT_PRECIS                                   equ     4
OUT_DEVICE_PRECIS                               equ     5
OUT_RASTER_PRECIS                               equ     6
OUT_TT_ONLY_PRECIS                              equ     7
OUT_OUTLINE_PRECIS                              equ     8
OUT_SCREEN_OUTLINE_PRECIS                       equ     9
OUT_PS_ONLY_PRECIS                              equ     10

CLIP_DEFAULT_PRECIS                             equ     0
CLIP_CHARACTER_PRECIS                           equ     1
CLIP_STROKE_PRECIS                              equ     2
CLIP_MASK                                       equ     0FH
CLIP_LH_ANGLES                                  equ     <1 shl 4>
CLIP_TT_ALWAYS                                  equ     <2 shl 4>
CLIP_EMBEDDED                                   equ     <8 shl 4>
#if NTDDI_VERSION >= NTDDI_VISTA
    CLIP_DFA_DISABLE                            equ     <4 shl 4>
#endif

DEFAULT_QUALITY                                 equ     0
DRAFT_QUALITY                                   equ     1
PROOF_QUALITY                                   equ     2
NONANTIALIASED_QUALITY                          equ     3
ANTIALIASED_QUALITY                             equ     4
#if NTDDI_VERSION >= NTDDI_WINXP
    CLEARTYPE_QUALITY                           equ     5
    CLEARTYPE_NATURAL_QUALITY                   equ     6
#endif

DEFAULT_PITCH                                   equ     0
FIXED_PITCH                                     equ     1
VARIABLE_PITCH                                  equ     2
MONO_FONT                                       equ     8

ANSI_CHARSET                                    equ     0
DEFAULT_CHARSET                                 equ     1
SYMBOL_CHARSET                                  equ     2
MAC_CHARSET                                     equ     77
SHIFTJIS_CHARSET                                equ     128
HANGEUL_CHARSET                                 equ     129
HANGUL_CHARSET                                  equ     129
GB2312_CHARSET                                  equ     134
CHINESEBIG5_CHARSET                             equ     136
JOHAB_CHARSET                                   equ     130
HEBREW_CHARSET                                  equ     177
ARABIC_CHARSET                                  equ     178
GREEK_CHARSET                                   equ     161
TURKISH_CHARSET                                 equ     162
VIETNAMESE_CHARSET                              equ     163
BALTIC_CHARSET                                  equ     186
RUSSIAN_CHARSET                                 equ     204
THAI_CHARSET                                    equ     222
EASTEUROPE_CHARSET                              equ     238
OEM_CHARSET                                     equ     255

FS_LATIN1                                       equ     000000001H
FS_LATIN2                                       equ     000000002H
FS_CYRILLIC                                     equ     000000004H
FS_GREEK                                        equ     000000008H
FS_TURKISH                                      equ     000000010H
FS_HEBREW                                       equ     000000020H
FS_ARABIC                                       equ     000000040H
FS_BALTIC                                       equ     000000080H
FS_VIETNAMESE                                   equ     000000100H
FS_THAI                                         equ     000010000H
FS_JISJAPAN                                     equ     000020000H
FS_CHINESESIMP                                  equ     000040000H
FS_WANSUNG                                      equ     000080000H
FS_CHINESETRAD                                  equ     000100000H
FS_JOHAB                                        equ     000200000H
FS_SYMBOL                                       equ     080000000H

FF_DONTCARE                                     equ     <0 shl 4>
FF_ROMAN                                        equ     <1 shl 4>
FF_SWISS                                        equ     <2 shl 4>
FF_MODERN                                       equ     <3 shl 4>
FF_SCRIPT                                       equ     <4 shl 4>
FF_DECORATIVE                                   equ     <5 shl 4>

FW_DONTCARE                                     equ     0
FW_THIN                                         equ     100
FW_EXTRALIGHT                                   equ     200
FW_LIGHT                                        equ     300
FW_NORMAL                                       equ     400
FW_MEDIUM                                       equ     500
FW_SEMIBOLD                                     equ     600
FW_BOLD                                         equ     700
FW_EXTRABOLD                                    equ     800
FW_HEAVY                                        equ     900

FW_ULTRALIGHT                                   equ     FW_EXTRALIGHT
FW_REGULAR                                      equ     FW_NORMAL
FW_DEMIBOLD                                     equ     FW_SEMIBOLD
FW_ULTRABOLD                                    equ     FW_EXTRABOLD
FW_BLACK                                        equ     FW_HEAVY

PANOSE_COUNT                                    equ     10

PAN_FAMILYTYPE_INDEX                            equ     0
PAN_SERIFSTYLE_INDEX                            equ     1
PAN_WEIGHT_INDEX                                equ     2
PAN_PROPORTION_INDEX                            equ     3
PAN_CONTRAST_INDEX                              equ     4
PAN_STROKEVARIATION_INDEX                       equ     5
PAN_ARMSTYLE_INDEX                              equ     6
PAN_LETTERFORM_INDEX                            equ     7
PAN_MIDLINE_INDEX                               equ     8
PAN_XHEIGHT_INDEX                               equ     9

PAN_CULTURE_LATIN                               equ     0

PAN_ANY                                         equ     0
PAN_NO_FIT                                      equ     1

PAN_FAMILY_TEXT_DISPLAY                         equ     2
PAN_FAMILY_SCRIPT                               equ     3
PAN_FAMILY_DECORATIVE                           equ     4
PAN_FAMILY_PICTORIAL                            equ     5

PAN_SERIF_COVE                                  equ     2
PAN_SERIF_OBTUSE_COVE                           equ     3
PAN_SERIF_SQUARE_COVE                           equ     4
PAN_SERIF_OBTUSE_SQUARE_COVE                    equ     5
PAN_SERIF_SQUARE                                equ     6
PAN_SERIF_THIN                                  equ     7
PAN_SERIF_BONE                                  equ     8
PAN_SERIF_EXAGGERATED                           equ     9
PAN_SERIF_TRIANGLE                              equ     10
PAN_SERIF_NORMAL_SANS                           equ     11
PAN_SERIF_OBTUSE_SANS                           equ     12
PAN_SERIF_PERP_SANS                             equ     13
PAN_SERIF_FLARED                                equ     14
PAN_SERIF_ROUNDED                               equ     15

PAN_WEIGHT_VERY_LIGHT                           equ     2
PAN_WEIGHT_LIGHT                                equ     3
PAN_WEIGHT_THIN                                 equ     4
PAN_WEIGHT_BOOK                                 equ     5
PAN_WEIGHT_MEDIUM                               equ     6
PAN_WEIGHT_DEMI                                 equ     7
PAN_WEIGHT_BOLD                                 equ     8
PAN_WEIGHT_HEAVY                                equ     9
PAN_WEIGHT_BLACK                                equ     10
PAN_WEIGHT_NORD                                 equ     11

PAN_PROP_OLD_STYLE                              equ     2
PAN_PROP_MODERN                                 equ     3
PAN_PROP_EVEN_WIDTH                             equ     4
PAN_PROP_EXPANDED                               equ     5
PAN_PROP_CONDENSED                              equ     6
PAN_PROP_VERY_EXPANDED                          equ     7
PAN_PROP_VERY_CONDENSED                         equ     8
PAN_PROP_MONOSPACED                             equ     9

PAN_CONTRAST_NONE                               equ     2
PAN_CONTRAST_VERY_LOW                           equ     3
PAN_CONTRAST_LOW                                equ     4
PAN_CONTRAST_MEDIUM_LOW                         equ     5
PAN_CONTRAST_MEDIUM                             equ     6
PAN_CONTRAST_MEDIUM_HIGH                        equ     7
PAN_CONTRAST_HIGH                               equ     8
PAN_CONTRAST_VERY_HIGH                          equ     9

PAN_STROKE_GRADUAL_DIAG                         equ     2
PAN_STROKE_GRADUAL_TRAN                         equ     3
PAN_STROKE_GRADUAL_VERT                         equ     4
PAN_STROKE_GRADUAL_HORZ                         equ     5
PAN_STROKE_RAPID_VERT                           equ     6
PAN_STROKE_RAPID_HORZ                           equ     7
PAN_STROKE_INSTANT_VERT                         equ     8

PAN_STRAIGHT_ARMS_HORZ                          equ     2
PAN_STRAIGHT_ARMS_WEDGE                         equ     3
PAN_STRAIGHT_ARMS_VERT                          equ     4
PAN_STRAIGHT_ARMS_SINGLE_SERIF                  equ     5
PAN_STRAIGHT_ARMS_DOUBLE_SERIF                  equ     6
PAN_BENT_ARMS_HORZ                              equ     7
PAN_BENT_ARMS_WEDGE                             equ     8
PAN_BENT_ARMS_VERT                              equ     9
PAN_BENT_ARMS_SINGLE_SERIF                      equ     10
PAN_BENT_ARMS_DOUBLE_SERIF                      equ     11

PAN_LETT_NORMAL_CONTACT                         equ     2
PAN_LETT_NORMAL_WEIGHTED                        equ     3
PAN_LETT_NORMAL_BOXED                           equ     4
PAN_LETT_NORMAL_FLATTENED                       equ     5
PAN_LETT_NORMAL_ROUNDED                         equ     6
PAN_LETT_NORMAL_OFF_CENTER                      equ     7
PAN_LETT_NORMAL_SQUARE                          equ     8
PAN_LETT_OBLIQUE_CONTACT                        equ     9
PAN_LETT_OBLIQUE_WEIGHTED                       equ     10
PAN_LETT_OBLIQUE_BOXED                          equ     11
PAN_LETT_OBLIQUE_FLATTENED                      equ     12
PAN_LETT_OBLIQUE_ROUNDED                        equ     13
PAN_LETT_OBLIQUE_OFF_CENTER                     equ     14
PAN_LETT_OBLIQUE_SQUARE                         equ     15

PAN_MIDLINE_STANDARD_TRIMMED                    equ     2
PAN_MIDLINE_STANDARD_POINTED                    equ     3
PAN_MIDLINE_STANDARD_SERIFED                    equ     4
PAN_MIDLINE_HIGH_TRIMMED                        equ     5
PAN_MIDLINE_HIGH_POINTED                        equ     6
PAN_MIDLINE_HIGH_SERIFED                        equ     7
PAN_MIDLINE_CONSTANT_TRIMMED                    equ     8
PAN_MIDLINE_CONSTANT_POINTED                    equ     9
PAN_MIDLINE_CONSTANT_SERIFED                    equ     10
PAN_MIDLINE_LOW_TRIMMED                         equ     11
PAN_MIDLINE_LOW_POINTED                         equ     12
PAN_MIDLINE_LOW_SERIFED                         equ     13

PAN_XHEIGHT_CONSTANT_SMALL                      equ     2
PAN_XHEIGHT_CONSTANT_STD                        equ     3
PAN_XHEIGHT_CONSTANT_LARGE                      equ     4
PAN_XHEIGHT_DUCKING_SMALL                       equ     5
PAN_XHEIGHT_DUCKING_STD                         equ     6
PAN_XHEIGHT_DUCKING_LARGE                       equ     7

ELF_VERSION                                     equ     0
ELF_CULTURE_LATIN                               equ     0

RASTER_FONTTYPE                                 equ     00001H
DEVICE_FONTTYPE                                 equ     0002H
TRUETYPE_FONTTYPE                               equ     0004H

PC_RESERVED                                     equ     001H
PC_EXPLICIT                                     equ     002H
PC_NOCOLLAPSE                                   equ     004H

TRANSPARENT                                     equ     1
OPAQUE                                          equ     2
BKMODE_LAST                                     equ     2

GM_COMPATIBLE                                   equ     1
GM_ADVANCED                                     equ     2
GM_LAST                                         equ     2

PT_CLOSEFIGURE                                  equ     001H
PT_LINETO                                       equ     002H
PT_BEZIERTO                                     equ     004H
PT_MOVETO                                       equ     006H

MM_TEXT                                         equ     1
MM_LOMETRIC                                     equ     2
MM_HIMETRIC                                     equ     3
MM_LOENGLISH                                    equ     4
MM_HIENGLISH                                    equ     5
MM_TWIPS                                        equ     6
MM_ISOTROPIC                                    equ     7
MM_ANISOTROPIC                                  equ     8

MM_MIN                                          equ     MM_TEXT
MM_MAX                                          equ     MM_ANISOTROPIC
MM_MAX_FIXEDSCALE                               equ     MM_TWIPS

ABSOLUTE                                        equ     1
RELATIVE                                        equ     2

WHITE_BRUSH                                     equ     0
LTGRAY_BRUSH                                    equ     1
GRAY_BRUSH                                      equ     2
DKGRAY_BRUSH                                    equ     3
BLACK_BRUSH                                     equ     4
NULL_BRUSH                                      equ     5
HOLLOW_BRUSH                                    equ     NULL_BRUSH
WHITE_PEN                                       equ     6
BLACK_PEN                                       equ     7
NULL_PEN                                        equ     8
OEM_FIXED_FONT                                  equ     10
ANSI_FIXED_FONT                                 equ     11
ANSI_VAR_FONT                                   equ     12
SYSTEM_FONT                                     equ     13
DEVICE_DEFAULT_FONT                             equ     14
DEFAULT_PALETTE                                 equ     15
SYSTEM_FIXED_FONT                               equ     16

DEFAULT_GUI_FONT                                equ     17

DC_BRUSH                                        equ     18
DC_PEN                                          equ     19

#if NTDDI_VERSION <= NTDDI_WINNT4
    STOCK_LAST                                  equ     17
#else
    STOCK_LAST                                  equ     19
#endif

CLR_INVALID                                     equ     0FFFFFFFFH

BS_SOLID                                        equ     0
BS_NULL                                         equ     1
BS_HOLLOW                                       equ     BS_NULL
BS_HATCHED                                      equ     2
BS_PATTERN                                      equ     3
BS_INDEXED                                      equ     4
BS_DIBPATTERN                                   equ     5
BS_DIBPATTERNPT                                 equ     6
BS_PATTERN8X8                                   equ     7
BS_DIBPATTERN8X8                                equ     8
BS_MONOPATTERN                                  equ     9

HS_HORIZONTAL                                   equ     0
HS_VERTICAL                                     equ     1
HS_FDIAGONAL                                    equ     2
HS_BDIAGONAL                                    equ     3
HS_CROSS                                        equ     4
HS_DIAGCROSS                                    equ     5

PS_SOLID                                        equ     0
PS_DASH                                         equ     1
PS_DOT                                          equ     2
PS_DASHDOT                                      equ     3
PS_DASHDOTDOT                                   equ     4
PS_NULL                                         equ     5
PS_INSIDEFRAME                                  equ     6
PS_USERSTYLE                                    equ     7
PS_ALTERNATE                                    equ     8
PS_STYLE_MASK                                   equ     00000000FH

PS_ENDCAP_ROUND                                 equ     000000000H
PS_ENDCAP_SQUARE                                equ     000000100H
PS_ENDCAP_FLAT                                  equ     000000200H
PS_ENDCAP_MASK                                  equ     000000F00H

PS_JOIN_ROUND                                   equ     000000000H
PS_JOIN_BEVEL                                   equ     000001000H
PS_JOIN_MITER                                   equ     000002000H
PS_JOIN_MASK                                    equ     00000F000H

PS_COSMETIC                                     equ     000000000H
PS_GEOMETRIC                                    equ     000010000H
PS_TYPE_MASK                                    equ     0000F0000H

AD_COUNTERCLOCKWISE                             equ     1
AD_CLOCKWISE                                    equ     2

DRIVERVERSION                                   equ     0
TECHNOLOGY                                      equ     2
HORZSIZE                                        equ     4
VERTSIZE                                        equ     6
HORZRES                                         equ     8
VERTRES                                         equ     10
BITSPIXEL                                       equ     12
PLANES                                          equ     14
NUMBRUSHES                                      equ     16
NUMPENS                                         equ     18
NUMMARKERS                                      equ     20
NUMFONTS                                        equ     22
NUMCOLORS                                       equ     24
PDEVICESIZE                                     equ     26
CURVECAPS                                       equ     28
LINECAPS                                        equ     30
POLYGONALCAPS                                   equ     32
TEXTCAPS                                        equ     34
CLIPCAPS                                        equ     36
RASTERCAPS                                      equ     38
ASPECTX                                         equ     40
ASPECTY                                         equ     42
ASPECTXY                                        equ     44

#if NTDDI_VERSION >= NTDDI_WIN2K
    SHADEBLENDCAPS                              equ     120
    COLORMGMTCAPS                               equ     121
#endif

LOGPIXELSX                                      equ     88
LOGPIXELSY                                      equ     90

SIZEPALETTE                                     equ     104
NUMRESERVED                                     equ     106
COLORRES                                        equ     108

PHYSICALWIDTH                                   equ     110
PHYSICALHEIGHT                                  equ     111
PHYSICALOFFSETX                                 equ     112
PHYSICALOFFSETY                                 equ     113
SCALINGFACTORX                                  equ     114
SCALINGFACTORY                                  equ     115

VREFRESH                                        equ     116
DESKTOPVERTRES                                  equ     117
DESKTOPHORZRES                                  equ     118
BLTALIGNMENT                                    equ     119

DT_PLOTTER                                      equ     0
DT_RASDISPLAY                                   equ     1
DT_RASPRINTER                                   equ     2
DT_RASCAMERA                                    equ     3
DT_CHARSTREAM                                   equ     4
DT_METAFILE                                     equ     5
DT_DISPFILE                                     equ     6

CC_NONE                                         equ     0
CC_CIRCLES                                      equ     1
CC_PIE                                          equ     2
CC_CHORD                                        equ     4
CC_ELLIPSES                                     equ     8
CC_WIDE                                         equ     16
CC_STYLED                                       equ     32
CC_WIDESTYLED                                   equ     64
CC_INTERIORS                                    equ     128
CC_ROUNDRECT                                    equ     256

LC_NONE                                         equ     0
LC_POLYLINE                                     equ     2
LC_MARKER                                       equ     4
LC_POLYMARKER                                   equ     8
LC_WIDE                                         equ     16
LC_STYLED                                       equ     32
LC_WIDESTYLED                                   equ     64
LC_INTERIORS                                    equ     128

PC_NONE                                         equ     0
PC_POLYGON                                      equ     1
PC_RECTANGLE                                    equ     2
PC_WINDPOLYGON                                  equ     4
PC_TRAPEZOID                                    equ     4
PC_SCANLINE                                     equ     8
PC_WIDE                                         equ     16
PC_STYLED                                       equ     32
PC_WIDESTYLED                                   equ     64
PC_INTERIORS                                    equ     128
PC_POLYPOLYGON                                  equ     256
PC_PATHS                                        equ     512

CP_NONE                                         equ     0
CP_RECTANGLE                                    equ     1
CP_REGION                                       equ     2

TC_OP_CHARACTER                                 equ     000000001H
TC_OP_STROKE                                    equ     000000002H
TC_CP_STROKE                                    equ     000000004H
TC_CR_90                                        equ     000000008H
TC_CR_ANY                                       equ     000000010H
TC_SF_X_YINDEP                                  equ     000000020H
TC_SA_DOUBLE                                    equ     000000040H
TC_SA_INTEGER                                   equ     000000080H
TC_SA_CONTIN                                    equ     000000100H
TC_EA_DOUBLE                                    equ     000000200H
TC_IA_ABLE                                      equ     000000400H
TC_UA_ABLE                                      equ     000000800H
TC_SO_ABLE                                      equ     000001000H
TC_RA_ABLE                                      equ     000002000H
TC_VA_ABLE                                      equ     000004000H
TC_RESERVED                                     equ     000008000H
TC_SCROLLBLT                                    equ     000010000H

RC_NONE                                         equ     0
RC_BITBLT                                       equ     1
RC_BANDING                                      equ     2
RC_SCALING                                      equ     4
RC_BITMAP64                                     equ     8
RC_GDI20_OUTPUT                                 equ     00010H
RC_GDI20_STATE                                  equ     00020H
RC_SAVEBITMAP                                   equ     00040H
RC_DI_BITMAP                                    equ     00080H
RC_PALETTE                                      equ     00100H
RC_DIBTODEV                                     equ     00200H
RC_BIGFONT                                      equ     00400H
RC_STRETCHBLT                                   equ     00800H
RC_FLOODFILL                                    equ     01000H
RC_STRETCHDIB                                   equ     02000H
RC_OP_DX_OUTPUT                                 equ     04000H
RC_DEVBITS                                      equ     08000H

SB_NONE                                         equ     000000000H
SB_CONST_ALPHA                                  equ     000000001H
SB_PIXEL_ALPHA                                  equ     000000002H
SB_PREMULT_ALPHA                                equ     000000004H

SB_GRAD_RECT                                    equ     000000010H
SB_GRAD_TRI                                     equ     000000020H

CM_NONE                                         equ     00000000H
CM_DEVICE_ICM                                   equ     00000001H
CM_GAMMA_RAMP                                   equ     00000002H
CM_CMYK_COLOR                                   equ     00000004H

DIB_RGB_COLORS                                  equ     0
DIB_PAL_COLORS                                  equ     1

SYSPAL_ERROR                                    equ     0
SYSPAL_STATIC                                   equ     1
SYSPAL_NOSTATIC                                 equ     2
SYSPAL_NOSTATIC256                              equ     3

CBM_INIT                                        equ     004H

FLOODFILLBORDER                                 equ     0
FLOODFILLSURFACE                                equ     1

CCHFORMNAME                                     equ     32

#if NTDDI_VERSION < NTDDI_WINNT4
    DM_SPECVERSION                              equ     00400H
#else
    DM_SPECVERSION                              equ     00401H
#endif

DM_ORIENTATION                                  equ     000000001H
DM_PAPERSIZE                                    equ     000000002H
DM_PAPERLENGTH                                  equ     000000004H
DM_PAPERWIDTH                                   equ     000000008H
DM_SCALE                                        equ     000000010H
DM_POSITION                                     equ     000000020H
DM_DEFAULTSOURCE                                equ     000000200H
DM_PRINTQUALITY                                 equ     000000400H
DM_COLOR                                        equ     000000800H
DM_DUPLEX                                       equ     000001000H
DM_YRESOLUTION                                  equ     000002000H
DM_TTOPTION                                     equ     000004000H
DM_FORMNAME                                     equ     000010000H
DM_LOGPIXELS                                    equ     000020000H
DM_BITSPERPEL                                   equ     000040000H
DM_PELSWIDTH                                    equ     000080000H
DM_PELSHEIGHT                                   equ     000100000H
DM_DISPLAYFLAGS                                 equ     000200000H
DM_DISPLAYFREQUENCY                             equ     000400000H
DM_ICMMETHOD                                    equ     000800000H
DM_ICMINTENT                                    equ     001000000H
DM_MEDIATYPE                                    equ     002000000H
DM_DITHERTYPE                                   equ     004000000H
DM_PANNINGWIDTH                                 equ     008000000H
DM_PANNINGHEIGHT                                equ     010000000H
DM_DISPLAYFIXEDOUTPUT                           equ     020000000H

DMORIENT_PORTRAIT                               equ     1
DMORIENT_LANDSCAPE                              equ     2

DMPAPER_FIRST                                   equ     DMPAPER_LETTER
DMPAPER_LETTER                                  equ     1
DMPAPER_LETTERSMALL                             equ     2
DMPAPER_TABLOID                                 equ     3
DMPAPER_LEDGER                                  equ     4
DMPAPER_LEGAL                                   equ     5
DMPAPER_STATEMENT                               equ     6
DMPAPER_EXECUTIVE                               equ     7
DMPAPER_A3                                      equ     8
DMPAPER_A4                                      equ     9
DMPAPER_A4SMALL                                 equ     10
DMPAPER_A5                                      equ     11
DMPAPER_B4                                      equ     12
DMPAPER_B5                                      equ     13
DMPAPER_FOLIO                                   equ     14
DMPAPER_QUARTO                                  equ     15
DMPAPER_10X14                                   equ     16
DMPAPER_11X17                                   equ     17
DMPAPER_NOTE                                    equ     18
DMPAPER_ENV_9                                   equ     19
DMPAPER_ENV_10                                  equ     20
DMPAPER_ENV_11                                  equ     21
DMPAPER_ENV_12                                  equ     22
DMPAPER_ENV_14                                  equ     23
DMPAPER_CSHEET                                  equ     24
DMPAPER_DSHEET                                  equ     25
DMPAPER_ESHEET                                  equ     26
DMPAPER_ENV_DL                                  equ     27
DMPAPER_ENV_C5                                  equ     28
DMPAPER_ENV_C3                                  equ     29
DMPAPER_ENV_C4                                  equ     30
DMPAPER_ENV_C6                                  equ     31
DMPAPER_ENV_C65                                 equ     32
DMPAPER_ENV_B4                                  equ     33
DMPAPER_ENV_B5                                  equ     34
DMPAPER_ENV_B6                                  equ     35
DMPAPER_ENV_ITALY                               equ     36
DMPAPER_ENV_MONARCH                             equ     37
DMPAPER_ENV_PERSONAL                            equ     38
DMPAPER_FANFOLD_US                              equ     39
DMPAPER_FANFOLD_STD_GERMAN                      equ     40
DMPAPER_FANFOLD_LGL_GERMAN                      equ     41
DMPAPER_ISO_B4                                  equ     42
DMPAPER_JAPANESE_POSTCARD                       equ     43
DMPAPER_9X11                                    equ     44
DMPAPER_10X11                                   equ     45
DMPAPER_15X11                                   equ     46
DMPAPER_ENV_INVITE                              equ     47
DMPAPER_RESERVED_48                             equ     48
DMPAPER_RESERVED_49                             equ     49
DMPAPER_LETTER_EXTRA                            equ     50
DMPAPER_LEGAL_EXTRA                             equ     51
DMPAPER_TABLOID_EXTRA                           equ     52
DMPAPER_A4_EXTRA                                equ     53
DMPAPER_LETTER_TRANSVERSE                       equ     54
DMPAPER_A4_TRANSVERSE                           equ     55
DMPAPER_LETTER_EXTRA_TRANSVERSE                 equ     56
DMPAPER_A_PLUS                                  equ     57
DMPAPER_B_PLUS                                  equ     58
DMPAPER_LETTER_PLUS                             equ     59
DMPAPER_A4_PLUS                                 equ     60
DMPAPER_A5_TRANSVERSE                           equ     61
DMPAPER_B5_TRANSVERSE                           equ     62
DMPAPER_A3_EXTRA                                equ     63
DMPAPER_A5_EXTRA                                equ     64
DMPAPER_B5_EXTRA                                equ     65
DMPAPER_A2                                      equ     66
DMPAPER_A3_TRANSVERSE                           equ     67
DMPAPER_A3_EXTRA_TRANSVERSE                     equ     68
DMPAPER_DBL_JAPANESE_POSTCARD                   equ     69
DMPAPER_A6                                      equ     70
DMPAPER_JENV_KAKU2                              equ     71
DMPAPER_JENV_KAKU3                              equ     72
DMPAPER_JENV_CHOU3                              equ     73
DMPAPER_JENV_CHOU4                              equ     74
DMPAPER_LETTER_ROTATED                          equ     75
DMPAPER_A3_ROTATED                              equ     76
DMPAPER_A4_ROTATED                              equ     77
DMPAPER_A5_ROTATED                              equ     78
DMPAPER_B4_JIS_ROTATED                          equ     79
DMPAPER_B5_JIS_ROTATED                          equ     80
DMPAPER_JAPANESE_POSTCARD_ROTATED               equ     81
DMPAPER_DBL_JAPANESE_POSTCARD_ROTATED           equ     82
DMPAPER_A6_ROTATED                              equ     83
DMPAPER_JENV_KAKU2_ROTATED                      equ     84
DMPAPER_JENV_KAKU3_ROTATED                      equ     85
DMPAPER_JENV_CHOU3_ROTATED                      equ     86
DMPAPER_JENV_CHOU4_ROTATED                      equ     87
DMPAPER_B6_JIS                                  equ     88
DMPAPER_B6_JIS_ROTATED                          equ     89
DMPAPER_12X11                                   equ     90
DMPAPER_JENV_YOU4                               equ     91
DMPAPER_JENV_YOU4_ROTATED                       equ     92
DMPAPER_P16K                                    equ     93
DMPAPER_P32K                                    equ     94
DMPAPER_P32KBIG                                 equ     95
DMPAPER_PENV_1                                  equ     96
DMPAPER_PENV_2                                  equ     97
DMPAPER_PENV_3                                  equ     98
DMPAPER_PENV_4                                  equ     99
DMPAPER_PENV_5                                  equ     100
DMPAPER_PENV_6                                  equ     101
DMPAPER_PENV_7                                  equ     102
DMPAPER_PENV_8                                  equ     103
DMPAPER_PENV_9                                  equ     104
DMPAPER_PENV_10                                 equ     105
DMPAPER_P16K_ROTATED                            equ     106
DMPAPER_P32K_ROTATED                            equ     107
DMPAPER_P32KBIG_ROTATED                         equ     108
DMPAPER_PENV_1_ROTATED                          equ     109
DMPAPER_PENV_2_ROTATED                          equ     110
DMPAPER_PENV_3_ROTATED                          equ     111
DMPAPER_PENV_4_ROTATED                          equ     112
DMPAPER_PENV_5_ROTATED                          equ     113
DMPAPER_PENV_6_ROTATED                          equ     114
DMPAPER_PENV_7_ROTATED                          equ     115
DMPAPER_PENV_8_ROTATED                          equ     116
DMPAPER_PENV_9_ROTATED                          equ     117
DMPAPER_PENV_10_ROTATED                         equ     118

#if NTDDI_VERSION >= NTDDI_WINNT4
    DMPAPER_LAST                                equ     DMPAPER_A3_EXTRA_TRANSVERSE
#else
    #if NTDDI_VERSION >= NTDDI_WIN2K
        DMPAPER_LAST                            equ     DMPAPER_PENV_10_ROTATED
    #else
        DMPAPER_LAST                            equ     DMPAPER_FANFOLD_LGL_GERMAN
    #endif
#endif

#if NTDDI_VERSION >= NTDDI_WINXP
    DMDO_DEFAULT                                equ     0
    DMDO_90                                     equ     1
    DMDO_180                                    equ     2
    DMDO_270                                    equ     3
    DMDFO_DEFAULT                               equ     0
    DMDFO_STRETCH                               equ     1
    DMDFO_CENTER                                equ     2
#endif

DMPAPER_USER                                    equ     256

DMBIN_FIRST                                     equ     DMBIN_UPPER
DMBIN_UPPER                                     equ     1
DMBIN_ONLYONE                                   equ     1
DMBIN_LOWER                                     equ     2
DMBIN_MIDDLE                                    equ     3
DMBIN_MANUAL                                    equ     4
DMBIN_ENVELOPE                                  equ     5
DMBIN_ENVMANUAL                                 equ     6
DMBIN_AUTO                                      equ     7
DMBIN_TRACTOR                                   equ     8
DMBIN_SMALLFMT                                  equ     9
DMBIN_LARGEFMT                                  equ     10
DMBIN_LARGECAPACITY                             equ     11
DMBIN_CASSETTE                                  equ     14
DMBIN_FORMSOURCE                                equ     15
DMBIN_LAST                                      equ     DMBIN_FORMSOURCE

DMBIN_USER                                      equ     256

DMRES_DRAFT                                     equ     (-1)
DMRES_LOW                                       equ     (-2)
DMRES_MEDIUM                                    equ     (-3)
DMRES_HIGH                                      equ     (-4)

DMCOLOR_MONOCHROME                              equ     1
DMCOLOR_COLOR                                   equ     2

DMDUP_SIMPLEX                                   equ     1
DMDUP_VERTICAL                                  equ     2
DMDUP_HORIZONTAL                                equ     3

DMTT_BITMAP                                     equ     1
DMTT_DOWNLOAD                                   equ     2
DMTT_SUBDEV                                     equ     3
DMTT_DOWNLOAD_OUTLINE                           equ     4

DMCOLLATE_FALSE                                 equ     0
DMCOLLATE_TRUE                                  equ     1

DMDISPLAYFLAGS_TEXTMODE                         equ     000000004H

DMNUP_SYSTEM                                    equ     1
DMNUP_ONEUP                                     equ     2

DMICMMETHOD_NONE                                equ     1
DMICMMETHOD_SYSTEM                              equ     2
DMICMMETHOD_DRIVER                              equ     3
DMICMMETHOD_DEVICE                              equ     4

DMICMMETHOD_USER                                equ     256

DMICM_SATURATE                                  equ     1
DMICM_CONTRAST                                  equ     2
DMICM_COLORIMETRIC                              equ     3
DMICM_ABS_COLORIMETRIC                          equ     4

DMICM_USER                                      equ     256

DMMEDIA_STANDARD                                equ     1
DMMEDIA_TRANSPARENCY                            equ     2
DMMEDIA_GLOSSY                                  equ     3

DMMEDIA_USER                                    equ     256

DMDITHER_NONE                                   equ     1
DMDITHER_COARSE                                 equ     2
DMDITHER_FINE                                   equ     3
DMDITHER_LINEART                                equ     4
DMDITHER_ERRORDIFFUSION                         equ     5
DMDITHER_RESERVED6                              equ     6
DMDITHER_RESERVED7                              equ     7
DMDITHER_RESERVED8                              equ     8
DMDITHER_RESERVED9                              equ     9
DMDITHER_GRAYSCALE                              equ     10

DMDITHER_USER                                   equ     256

DISPLAY_DEVICE_ATTACHED_TO_DESKTOP              equ     000000001H
DISPLAY_DEVICE_MULTI_DRIVER                     equ     000000002H
DISPLAY_DEVICE_PRIMARY_DEVICE                   equ     000000004H
DISPLAY_DEVICE_MIRRORING_DRIVER                 equ     000000008H
DISPLAY_DEVICE_VGA_COMPATIBLE                   equ     000000010H
DISPLAY_DEVICE_MODESPRUNED                      equ     008000000H
#if NTDDI_VERSION >= NTDDI_WIN2K
    DISPLAY_DEVICE_ACTIVE                       equ     000000001H
    DISPLAY_DEVICE_ATTACHED                     equ     000000002H
    DISPLAY_DEVICE_REMOVABLE                    equ     000000020H
    DISPLAY_DEVICE_REMOTE                       equ     004000000H
    DISPLAY_DEVICE_DISCONNECT                   equ     002000000H
#endif
DISPLAY_DEVICE_TS_COMPATIBLE                    equ     000200000H
#if NTDDI_VERSION >= NTDDI_VISTA
    DISPLAY_DEVICE_UNSAFE_MODES_ON              equ     000080000H
#endif

RDH_RECTANGLES                                  equ     1

SYSRGN                                          equ     4

GGO_METRICS                                     equ     0
GGO_BITMAP                                      equ     1
GGO_NATIVE                                      equ     2
GGO_BEZIER                                      equ     3

GGO_GRAY2_BITMAP                                equ     4
GGO_GRAY4_BITMAP                                equ     5
GGO_GRAY8_BITMAP                                equ     6
GGO_GLYPH_INDEX                                 equ     00080H
GGO_UNHINTED                                    equ     00100H

TT_POLYGON_TYPE                                 equ     24

TT_PRIM_LINE                                    equ     1
TT_PRIM_QSPLINE                                 equ     2
TT_PRIM_CSPLINE                                 equ     3

GCP_DBCS                                        equ     00001H
GCP_REORDER                                     equ     00002H
GCP_USEKERNING                                  equ     00008H
GCP_GLYPHSHAPE                                  equ     00010H
GCP_LIGATE                                      equ     00020H

GCP_DIACRITIC                                   equ     00100H
GCP_KASHIDA                                     equ     00400H
GCP_ERROR                                       equ     08000H
FLI_MASK                                        equ     0103BH

GCP_JUSTIFY                                     equ     000010000H
FLI_GLYPHS                                      equ     000040000H
GCP_CLASSIN                                     equ     000080000H
GCP_MAXEXTENT                                   equ     000100000H
GCP_JUSTIFYIN                                   equ     000200000H
GCP_DISPLAYZWG                                  equ     000400000H
GCP_SYMSWAPOFF                                  equ     000800000H
GCP_NUMERICOVERRIDE                             equ     001000000H
GCP_NEUTRALOVERRIDE                             equ     002000000H
GCP_NUMERICSLATIN                               equ     004000000H
GCP_NUMERICSLOCAL                               equ     008000000H

GCPCLASS_LATIN                                  equ     1
GCPCLASS_HEBREW                                 equ     2
GCPCLASS_ARABIC                                 equ     2
GCPCLASS_NEUTRAL                                equ     3
GCPCLASS_LOCALNUMBER                            equ     4
GCPCLASS_LATINNUMBER                            equ     5
GCPCLASS_LATINNUMERICTERMINATOR                 equ     6
GCPCLASS_LATINNUMERICSEPARATOR                  equ     7
GCPCLASS_NUMERICSEPARATOR                       equ     8
GCPCLASS_PREBOUNDLTR                            equ     080H
GCPCLASS_PREBOUNDRTL                            equ     040H
GCPCLASS_POSTBOUNDLTR                           equ     020H
GCPCLASS_POSTBOUNDRTL                           equ     010H

GCPGLYPH_LINKBEFORE                             equ     08000H
GCPGLYPH_LINKAFTER                              equ     04000H

TT_AVAILABLE                                    equ     00001H
TT_ENABLED                                      equ     00002H

PFD_TYPE_RGBA                                   equ     0
PFD_TYPE_COLORINDEX                             equ     1

PFD_MAIN_PLANE                                  equ     0
PFD_OVERLAY_PLANE                               equ     1
PFD_UNDERLAY_PLANE                              equ     (-1)

PFD_DOUBLEBUFFER                                equ     000000001H
PFD_STEREO                                      equ     000000002H
PFD_DRAW_TO_WINDOW                              equ     000000004H
PFD_DRAW_TO_BITMAP                              equ     000000008H
PFD_SUPPORT_GDI                                 equ     000000010H
PFD_SUPPORT_OPENGL                              equ     000000020H
PFD_GENERIC_FORMAT                              equ     000000040H
PFD_NEED_PALETTE                                equ     000000080H
PFD_NEED_SYSTEM_PALETTE                         equ     000000100H
PFD_SWAP_EXCHANGE                               equ     000000200H
PFD_SWAP_COPY                                   equ     000000400H
PFD_SWAP_LAYER_BUFFERS                          equ     000000800H
PFD_GENERIC_ACCELERATED                         equ     000001000H
PFD_SUPPORT_DIRECTDRAW                          equ     000002000H

PFD_DEPTH_DONTCARE                              equ     020000000H
PFD_DOUBLEBUFFER_DONTCARE                       equ     040000000H
PFD_STEREO_DONTCARE                             equ     080000000H

#ifndef DM_UPDATE
    DM_UPDATE                                   equ     1
    DM_COPY                                     equ     2
    DM_PROMPT                                   equ     4
    DM_MODIFY                                   equ     8

    DM_IN_BUFFER                                equ     DM_MODIFY
    DM_IN_PROMPT                                equ     DM_PROMPT
    DM_OUT_BUFFER                               equ     DM_COPY
    DM_OUT_DEFAULT                              equ     DM_UPDATE
#endif

DC_FIELDS                                       equ     1
DC_PAPERS                                       equ     2
DC_PAPERSIZE                                    equ     3
DC_MINEXTENT                                    equ     4
DC_MAXEXTENT                                    equ     5
DC_BINS                                         equ     6
DC_DUPLEX                                       equ     7
DC_SIZE                                         equ     8
DC_EXTRA                                        equ     9
DC_VERSION                                      equ     10
DC_DRIVER                                       equ     11
DC_BINNAMES                                     equ     12
DC_ENUMRESOLUTIONS                              equ     13
DC_FILEDEPENDENCIES                             equ     14
DC_TRUETYPE                                     equ     15
DC_PAPERNAMES                                   equ     16
DC_ORIENTATION                                  equ     17
DC_COPIES                                       equ     18
DC_BINADJUST                                    equ     19
DC_EMF_COMPLIANT                                equ     20
DC_DATATYPE_PRODUCED                            equ     21
DC_COLLATE                                      equ     22
DC_MANUFACTURER                                 equ     23
DC_MODEL                                        equ     24
DC_PERSONALITY                                  equ     25
DC_PRINTRATE                                    equ     26
DC_PRINTRATEUNIT                                equ     27

PRINTRATEUNIT_PPM                               equ     1
PRINTRATEUNIT_CPS                               equ     2
PRINTRATEUNIT_LPM                               equ     3
PRINTRATEUNIT_IPM                               equ     4

DC_PRINTERMEM                                   equ     28
DC_MEDIAREADY                                   equ     29
DC_STAPLE                                       equ     30
DC_PRINTRATEPPM                                 equ     31
DC_COLORDEVICE                                  equ     32
DC_NUP                                          equ     33

#if NTDDI_VERSION >= NTDDI_WIN2K
    DC_MEDIATYPENAMES                           equ     34
    DC_MEDIATYPES                               equ     35
#endif

DCTT_BITMAP                                     equ     00000001H
DCTT_DOWNLOAD                                   equ     00000002H
DCTT_SUBDEV                                     equ     00000004H
DCTT_DOWNLOAD_OUTLINE                           equ     00000008H

DCBA_FACEUPNONE                                 equ     00000H
DCBA_FACEUPCENTER                               equ     00001H
DCBA_FACEUPLEFT                                 equ     00002H
DCBA_FACEUPRIGHT                                equ     00003H
DCBA_FACEDOWNNONE                               equ     00100H
DCBA_FACEDOWNCENTER                             equ     00101H
DCBA_FACEDOWNLEFT                               equ     00102H
DCBA_FACEDOWNRIGHT                              equ     00103H

GS_8BIT_INDICES                                 equ     000000001H

GGI_MARK_NONEXISTING_GLYPHS                     equ     00001H

STAMP_DESIGNVECTOR                              equ     <8000000H + 64H + 07600H>
STAMP_AXESLIST                                  equ     <8000000H + 61H + 03100H>

FR_PRIVATE                                      equ     010H
FR_NOT_ENUM                                     equ     020H

AC_SRC_OVER                                     equ     000H
AC_SRC_ALPHA                                    equ     001H

GRADIENT_FILL_RECT_H                            equ     000000000H
GRADIENT_FILL_RECT_V                            equ     000000001H
GRADIENT_FILL_TRIANGLE                          equ     000000002H
GRADIENT_FILL_OP_FLAG                           equ     0000000FFH

CA_NEGATIVE                                     equ     00001H
CA_LOG_FILTER                                   equ     00002H

ILLUMINANT_DEVICE_DEFAULT                       equ     0
ILLUMINANT_A                                    equ     1
ILLUMINANT_B                                    equ     2
ILLUMINANT_C                                    equ     3
ILLUMINANT_D50                                  equ     4
ILLUMINANT_D55                                  equ     5
ILLUMINANT_D65                                  equ     6
ILLUMINANT_D75                                  equ     7
ILLUMINANT_F2                                   equ     8
ILLUMINANT_MAX_INDEX                            equ     ILLUMINANT_F2

ILLUMINANT_TUNGSTEN                             equ     ILLUMINANT_A
ILLUMINANT_DAYLIGHT                             equ     ILLUMINANT_C
ILLUMINANT_FLUORESCENT                          equ     ILLUMINANT_F2
ILLUMINANT_NTSC                                 equ     ILLUMINANT_C

RGB_GAMMA_MIN                                   equ     2500
RGB_GAMMA_MAX                                   equ     65000

REFERENCE_WHITE_MIN                             equ     6000
REFERENCE_WHITE_MAX                             equ     10000
REFERENCE_BLACK_MIN                             equ     0
REFERENCE_BLACK_MAX                             equ     4000

COLOR_ADJ_MIN                                   equ     (-100)
COLOR_ADJ_MAX                                   equ     100

DI_APPBANDING                                   equ     000000001H
DI_ROPS_READ_DESTINATION                        equ     000000002H

FONTMAPPER_MAX                                  equ     10

ICM_OFF                                         equ     1
ICM_ON                                          equ     2
ICM_QUERY                                       equ     3
ICM_DONE_OUTSIDEDC                              equ     4

ENHMETA_SIGNATURE                               equ     0464D4520H
ENHMETA_STOCK_OBJECT                            equ     080000000H

EMR_HEADER                                      equ     1
EMR_POLYBEZIER                                  equ     2
EMR_POLYGON                                     equ     3
EMR_POLYLINE                                    equ     4
EMR_POLYBEZIERTO                                equ     5
EMR_POLYLINETO                                  equ     6
EMR_POLYPOLYLINE                                equ     7
EMR_POLYPOLYGON                                 equ     8
EMR_SETWINDOWEXTEX                              equ     9
EMR_SETWINDOWORGEX                              equ     10
EMR_SETVIEWPORTEXTEX                            equ     11
EMR_SETVIEWPORTORGEX                            equ     12
EMR_SETBRUSHORGEX                               equ     13
EMR_EOF                                         equ     14
EMR_SETPIXELV                                   equ     15
EMR_SETMAPPERFLAGS                              equ     16
EMR_SETMAPMODE                                  equ     17
EMR_SETBKMODE                                   equ     18
EMR_SETPOLYFILLMODE                             equ     19
EMR_SETROP2                                     equ     20
EMR_SETSTRETCHBLTMODE                           equ     21
EMR_SETTEXTALIGN                                equ     22
EMR_SETCOLORADJUSTMENT                          equ     23
EMR_SETTEXTCOLOR                                equ     24
EMR_SETBKCOLOR                                  equ     25
EMR_OFFSETCLIPRGN                               equ     26
EMR_MOVETOEX                                    equ     27
EMR_SETMETARGN                                  equ     28
EMR_EXCLUDECLIPRECT                             equ     29
EMR_INTERSECTCLIPRECT                           equ     30
EMR_SCALEVIEWPORTEXTEX                          equ     31
EMR_SCALEWINDOWEXTEX                            equ     32
EMR_SAVEDC                                      equ     33
EMR_RESTOREDC                                   equ     34
EMR_SETWORLDTRANSFORM                           equ     35
EMR_MODIFYWORLDTRANSFORM                        equ     36
EMR_SELECTOBJECT                                equ     37
EMR_CREATEPEN                                   equ     38
EMR_CREATEBRUSHINDIRECT                         equ     39
EMR_DELETEOBJECT                                equ     40
EMR_ANGLEARC                                    equ     41
EMR_ELLIPSE                                     equ     42
EMR_RECTANGLE                                   equ     43
EMR_ROUNDRECT                                   equ     44
EMR_ARC                                         equ     45
EMR_CHORD                                       equ     46
EMR_PIE                                         equ     47
EMR_SELECTPALETTE                               equ     48
EMR_CREATEPALETTE                               equ     49
EMR_SETPALETTEENTRIES                           equ     50
EMR_RESIZEPALETTE                               equ     51
EMR_REALIZEPALETTE                              equ     52
EMR_EXTFLOODFILL                                equ     53
EMR_LINETO                                      equ     54
EMR_ARCTO                                       equ     55
EMR_POLYDRAW                                    equ     56
EMR_SETARCDIRECTION                             equ     57
EMR_SETMITERLIMIT                               equ     58
EMR_BEGINPATH                                   equ     59
EMR_ENDPATH                                     equ     60
EMR_CLOSEFIGURE                                 equ     61
EMR_FILLPATH                                    equ     62
EMR_STROKEANDFILLPATH                           equ     63
EMR_STROKEPATH                                  equ     64
EMR_FLATTENPATH                                 equ     65
EMR_WIDENPATH                                   equ     66
EMR_SELECTCLIPPATH                              equ     67
EMR_ABORTPATH                                   equ     68

EMR_GDICOMMENT                                  equ     70
EMR_FILLRGN                                     equ     71
EMR_FRAMERGN                                    equ     72
EMR_INVERTRGN                                   equ     73
EMR_PAINTRGN                                    equ     74
EMR_EXTSELECTCLIPRGN                            equ     75
EMR_BITBLT                                      equ     76
EMR_STRETCHBLT                                  equ     77
EMR_MASKBLT                                     equ     78
EMR_PLGBLT                                      equ     79
EMR_SETDIBITSTODEVICE                           equ     80
EMR_STRETCHDIBITS                               equ     81
EMR_EXTCREATEFONTINDIRECTW                      equ     82
EMR_EXTTEXTOUTA                                 equ     83
EMR_EXTTEXTOUTW                                 equ     84
EMR_POLYBEZIER16                                equ     85
EMR_POLYGON16                                   equ     86
EMR_POLYLINE16                                  equ     87
EMR_POLYBEZIERTO16                              equ     88
EMR_POLYLINETO16                                equ     89
EMR_POLYPOLYLINE16                              equ     90
EMR_POLYPOLYGON16                               equ     91
EMR_POLYDRAW16                                  equ     92
EMR_CREATEMONOBRUSH                             equ     93
EMR_CREATEDIBPATTERNBRUSHPT                     equ     94
EMR_EXTCREATEPEN                                equ     95
EMR_POLYTEXTOUTA                                equ     96
EMR_POLYTEXTOUTW                                equ     97

EMR_SETICMMODE                                  equ     98
EMR_CREATECOLORSPACE                            equ     99
EMR_SETCOLORSPACE                               equ     100
EMR_DELETECOLORSPACE                            equ     101
EMR_GLSRECORD                                   equ     102
EMR_GLSBOUNDEDRECORD                            equ     103
EMR_PIXELFORMAT                                 equ     104
EMR_RESERVED_105                                equ     105
EMR_RESERVED_106                                equ     106
EMR_RESERVED_107                                equ     107
EMR_RESERVED_108                                equ     108
EMR_RESERVED_109                                equ     109
EMR_RESERVED_110                                equ     110

EMR_DRAWESCAPE                                  equ     105
EMR_EXTESCAPE                                   equ     106
EMR_STARTDOC                                    equ     107
EMR_SMALLTEXTOUT                                equ     108
EMR_FORCEUFIMAPPING                             equ     109
EMR_NAMEDESCAPE                                 equ     110
EMR_COLORCORRECTPALETTE                         equ     111
EMR_SETICMPROFILEA                              equ     112
EMR_SETICMPROFILEW                              equ     113
EMR_ALPHABLEND                                  equ     114
EMR_ALPHADIBBLEND                               equ     115
EMR_TRANSPARENTBLT                              equ     116
EMR_TRANSPARENTDIB                              equ     117
EMR_GRADIENTFILL                                equ     118
EMR_RESERVED_119                                equ     119
EMR_RESERVED_120                                equ     120
EMR_SETLINKEDUFIS                               equ     119
EMR_SETTEXTJUSTIFICATION                        equ     120
EMR_COLORMATCHTOTARGETW                         equ     121
EMR_CREATECOLORSPACEW                           equ     122

EMR_MIN                                         equ     1
EMR_MAX                                         equ     122

SETICMPROFILE_EMBEDED                           equ     000000001H
CREATECOLORSPACE_EMBEDED                        equ     000000001H
COLORMATCHTOTARGET_EMBEDED                      equ     000000001H

GDICOMMENT_IDENTIFIER                           equ     043494447H
GDICOMMENT_WINDOWS_METAFILE                     equ     080000001H
GDICOMMENT_BEGINGROUP                           equ     000000002H
GDICOMMENT_ENDGROUP                             equ     000000003H
GDICOMMENT_MULTIFORMATS                         equ     040000004H
GDICOMMENT_UNICODE_STRING                       equ     000000040H
GDICOMMENT_UNICODE_END                          equ     000000080H
EPS_SIGNATURE                                   equ     046535045H

WGL_FONT_LINES                                  equ     0
WGL_FONT_POLYGONS                               equ     1

LPD_DOUBLEBUFFER                                equ     000000001H
LPD_STEREO                                      equ     000000002H
LPD_SUPPORT_GDI                                 equ     000000010H
LPD_SUPPORT_OPENGL                              equ     000000020H
LPD_SHARE_DEPTH                                 equ     000000040H
LPD_SHARE_STENCIL                               equ     000000080H
LPD_SHARE_ACCUM                                 equ     000000100H
LPD_SWAP_EXCHANGE                               equ     000000200H
LPD_SWAP_COPY                                   equ     000000400H
LPD_TRANSPARENT                                 equ     000001000H

LPD_TYPE_RGBA                                   equ     0
LPD_TYPE_COLORINDEX                             equ     1

WGL_SWAP_MAIN_PLANE                             equ     000000001H
WGL_SWAP_OVERLAY1                               equ     000000002H
WGL_SWAP_OVERLAY2                               equ     000000004H
WGL_SWAP_OVERLAY3                               equ     000000008H
WGL_SWAP_OVERLAY4                               equ     000000010H
WGL_SWAP_OVERLAY5                               equ     000000020H
WGL_SWAP_OVERLAY6                               equ     000000040H
WGL_SWAP_OVERLAY7                               equ     000000080H
WGL_SWAP_OVERLAY8                               equ     000000100H
WGL_SWAP_OVERLAY9                               equ     000000200H
WGL_SWAP_OVERLAY10                              equ     000000400H
WGL_SWAP_OVERLAY11                              equ     000000800H
WGL_SWAP_OVERLAY12                              equ     000001000H
WGL_SWAP_OVERLAY13                              equ     000002000H
WGL_SWAP_OVERLAY14                              equ     000004000H
WGL_SWAP_OVERLAY15                              equ     000008000H
WGL_SWAP_UNDERLAY1                              equ     000010000H
WGL_SWAP_UNDERLAY2                              equ     000020000H
WGL_SWAP_UNDERLAY3                              equ     000040000H
WGL_SWAP_UNDERLAY4                              equ     000080000H
WGL_SWAP_UNDERLAY5                              equ     000100000H
WGL_SWAP_UNDERLAY6                              equ     000200000H
WGL_SWAP_UNDERLAY7                              equ     000400000H
WGL_SWAP_UNDERLAY8                              equ     000800000H
WGL_SWAP_UNDERLAY9                              equ     001000000H
WGL_SWAP_UNDERLAY10                             equ     002000000H
WGL_SWAP_UNDERLAY11                             equ     004000000H
WGL_SWAP_UNDERLAY12                             equ     008000000H
WGL_SWAP_UNDERLAY13                             equ     010000000H
WGL_SWAP_UNDERLAY14                             equ     020000000H
WGL_SWAP_UNDERLAY15                             equ     040000000H

WGL_SWAPMULTIPLE_MAX                            equ     16

DISPLAYCONFIG_MAXPATH                           equ     1024

DISPLAYCONFIG_OUTPUT_TECHNOLOGY_OTHER           equ     (-1)
DISPLAYCONFIG_OUTPUT_TECHNOLOGY_HD15            equ     0
DISPLAYCONFIG_OUTPUT_TECHNOLOGY_SVIDEO          equ     1
DISPLAYCONFIG_OUTPUT_TECHNOLOGY_COMPOSITE_VIDEO equ     2
DISPLAYCONFIG_OUTPUT_TECHNOLOGY_COMPONENT_VIDEO equ     3
DISPLAYCONFIG_OUTPUT_TECHNOLOGY_DVI             equ     4
DISPLAYCONFIG_OUTPUT_TECHNOLOGY_HDMI            equ     5
DISPLAYCONFIG_OUTPUT_TECHNOLOGY_LVDS            equ     6
DISPLAYCONFIG_OUTPUT_TECHNOLOGY_D_JPN           equ     8
DISPLAYCONFIG_OUTPUT_TECHNOLOGY_SDI             equ     9
DISPLAYCONFIG_OUTPUT_TECHNOLOGY_DISPLAYPORT_EXTERNAL equ 10
DISPLAYCONFIG_OUTPUT_TECHNOLOGY_DISPLAYPORT_EMBEDDED equ 11
DISPLAYCONFIG_OUTPUT_TECHNOLOGY_UDI_EXTERNAL    equ     12
DISPLAYCONFIG_OUTPUT_TECHNOLOGY_UDI_EMBEDDED    equ     13
DISPLAYCONFIG_OUTPUT_TECHNOLOGY_SDTVDONGLE      equ     14
DISPLAYCONFIG_OUTPUT_TECHNOLOGY_INTERNAL        equ     080000000H
DISPLAYCONFIG_OUTPUT_TECHNOLOGY_FORCE_UINT32    equ     0FFFFFFFFH

DISPLAYCONFIG_SCANLINE_ORDERING_UNSPECIFIED     equ     0
DISPLAYCONFIG_SCANLINE_ORDERING_PROGRESSIVE     equ     1
DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED      equ     2
DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED_UPPERFIELDFIRST equ DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED
DISPLAYCONFIG_SCANLINE_ORDERING_INTERLACED_LOWERFIELDFIRST equ 3
DISPLAYCONFIG_SCANLINE_ORDERING_FORCE_UINT32    equ     0FFFFFFFFH

DISPLAYCONFIG_SCALING_IDENTITY                  equ     1
DISPLAYCONFIG_SCALING_CENTERED                  equ     2
DISPLAYCONFIG_SCALING_STRETCHED                 equ     3
DISPLAYCONFIG_SCALING_ASPECTRATIOCENTEREDMAX    equ     4
DISPLAYCONFIG_SCALING_CUSTOM                    equ     5
DISPLAYCONFIG_SCALING_PREFERRED                 equ     128
DISPLAYCONFIG_SCALING_FORCE_UINT32              equ     0FFFFFFFFH

DISPLAYCONFIG_ROTATION_IDENTITY                 equ     1
DISPLAYCONFIG_ROTATION_ROTATE90                 equ     2
DISPLAYCONFIG_ROTATION_ROTATE180                equ     3
DISPLAYCONFIG_ROTATION_ROTATE270                equ     4
DISPLAYCONFIG_ROTATION_FORCE_UINT32             equ     0FFFFFFFFH

DISPLAYCONFIG_MODE_INFO_TYPE_SOURCE             equ     1
DISPLAYCONFIG_MODE_INFO_TYPE_TARGET             equ     2
DISPLAYCONFIG_MODE_INFO_TYPE_FORCE_UINT32       equ     0FFFFFFFFH

DISPLAYCONFIG_PIXELFORMAT_8BPP                  equ     1
DISPLAYCONFIG_PIXELFORMAT_16BPP                 equ     2
DISPLAYCONFIG_PIXELFORMAT_24BPP                 equ     3
DISPLAYCONFIG_PIXELFORMAT_32BPP                 equ     4
DISPLAYCONFIG_PIXELFORMAT_NONGDI                equ     5
DISPLAYCONFIG_PIXELFORMAT_FORCE_UINT32          equ     0FFFFFFFFH

DISPLAYCONFIG_PATH_MODE_IDX_INVALID             equ     0FFFFFFFFH

DISPLAYCONFIG_SOURCE_IN_USE                     equ     000000001H

DISPLAYCONFIG_TARGET_IN_USE                     equ     000000001H
DISPLAYCONFIG_TARGET_FORCIBLE                   equ     000000002H
DISPLAYCONFIG_TARGET_FORCED_AVAILABILITY_BOOT   equ     000000004H
DISPLAYCONFIG_TARGET_FORCED_AVAILABILITY_PATH   equ     000000008H
DISPLAYCONFIG_TARGET_FORCED_AVAILABILITY_SYSTEM equ     000000010H

DISPLAYCONFIG_PATH_ACTIVE                       equ     000000001H

DISPLAYCONFIG_TOPOLOGY_INTERNAL                 equ     000000001H
DISPLAYCONFIG_TOPOLOGY_CLONE                    equ     000000002H
DISPLAYCONFIG_TOPOLOGY_EXTEND                   equ     000000004H
DISPLAYCONFIG_TOPOLOGY_EXTERNAL                 equ     000000008H
DISPLAYCONFIG_TOPOLOGY_FORCE_UINT32             equ     0FFFFFFFFH

DISPLAYCONFIG_DEVICE_INFO_GET_SOURCE_NAME       equ     1
DISPLAYCONFIG_DEVICE_INFO_GET_TARGET_NAME       equ     2
DISPLAYCONFIG_DEVICE_INFO_GET_TARGET_PREFERRED_MODE equ 3
DISPLAYCONFIG_DEVICE_INFO_GET_ADAPTER_NAME      equ     4
DISPLAYCONFIG_DEVICE_INFO_SET_TARGET_PERSISTENCE equ    5
DISPLAYCONFIG_DEVICE_INFO_FORCE_UINT32          equ     0FFFFFFFFH

QDC_ALL_PATHS                                   equ     000000001H
QDC_ONLY_ACTIVE_PATHS                           equ     000000002H
QDC_DATABASE_CURRENT                            equ     000000004H

SDC_TOPOLOGY_INTERNAL                           equ     000000001H
SDC_TOPOLOGY_CLONE                              equ     000000002H
SDC_TOPOLOGY_EXTEND                             equ     000000004H
SDC_TOPOLOGY_EXTERNAL                           equ     000000008H
SDC_TOPOLOGY_SUPPLIED                           equ     000000010H
SDC_USE_DATABASE_CURRENT                        equ     <SDC_TOPOLOGY_INTERNAL or SDC_TOPOLOGY_CLONE or SDC_TOPOLOGY_EXTEND or SDC_TOPOLOGY_EXTERNAL>

SDC_USE_SUPPLIED_DISPLAY_CONFIG                 equ     000000020H
SDC_VALIDATE                                    equ     000000040H
SDC_APPLY                                       equ     000000080H
SDC_NO_OPTIMIZATION                             equ     000000100H
SDC_SAVE_TO_DATABASE                            equ     000000200H
SDC_ALLOW_CHANGES                               equ     000000400H
SDC_PATH_PERSIST_IF_REQUIRED                    equ     000000800H
SDC_FORCE_MODE_ENUMERATION                      equ     000001000H
SDC_ALLOW_PATH_ORDER_CHANGES                    equ     000002000H

;======================================== Functions =======================================;
#if COFF_FORMAT == 1
    from_lib gdi32.lib
#else
    from_dll gdi32.dll
#endif

import AbortDoc
import AbortPath
import AddFontResourceA
import AddFontResourceW
import AngleArc
import AnimatePalette
import Arc
import ArcTo
import BeginPath
import BitBlt
import CancelDC
import CheckColorsInGamut
import ChoosePixelFormat
import Chord
import CloseEnhMetaFile
import CloseFigure
import CloseMetaFile
import ColorMatchToTarget
import CombineRgn
import CombineTransform
import CopyEnhMetaFileA
import CopyEnhMetaFileW
import CopyMetaFileA
import CopyMetaFileW
import CreateBitmap
import CreateBitmapIndirect
import CreateBrushIndirect
import CreateColorSpaceA
import CreateColorSpaceW
import CreateCompatibleBitmap
import CreateCompatibleDC
import CreateDCA
import CreateDCW
import CreateDIBitmap
import CreateDIBPatternBrush
import CreateDIBPatternBrushPt
import CreateDIBSection
import CreateDiscardableBitmap
import CreateEllipticRgn
import CreateEllipticRgnIndirect
import CreateEnhMetaFileA
import CreateEnhMetaFileW
import CreateFontA
import CreateFontIndirectA
import CreateFontIndirectW
import CreateFontW
import CreateHalftonePalette
import CreateHatchBrush
import CreateICA
import CreateICW
import CreateMetaFileA
import CreateMetaFileW
import CreatePalette
import CreatePatternBrush
import CreatePen
import CreatePenIndirect
import CreatePolygonRgn
import CreatePolyPolygonRgn
import CreateRectRgn
import CreateRectRgnIndirect
import CreateRoundRectRgn
import CreateScalableFontResourceA
import CreateScalableFontResourceW
import CreateSolidBrush
import DeleteColorSpace
import DeleteDC
import DeleteEnhMetaFile
import DeleteMetaFile
import DeleteObject
import DescribePixelFormat
import DeviceCapabilitiesExA
import DeviceCapabilitiesExW
import DPtoLP
import DrawEscape
import Ellipse
import EndDoc
import EndPage
import EndPath
import EnumEnhMetaFile
import EnumFontFamiliesA
import EnumFontFamiliesExA
import EnumFontFamiliesExW
import EnumFontFamiliesW
import EnumFontsA
import EnumFontsW
import EnumICMProfilesA
import EnumICMProfilesW
import EnumMetaFile
import EnumObjects
import EqualRgn
import Escape
import ExcludeClipRect
import ExtCreatePen
import ExtCreateRegion
import ExtEscape
import ExtFloodFill
import ExtSelectClipRgn
import ExtTextOutA
import ExtTextOutW
import FillPath
import FillRgn
import FixBrushOrgEx
import FlattenPath
import FloodFill
import FrameRgn
import GdiComment
import GdiFlush
import GdiGetBatchLimit
import GdiPlayDCScript
import GdiPlayJournal
import GdiPlayScript
import gdiPlaySpoolStream
import GdiSetBatchLimit
import GetArcDirection
import GetAspectRatioFilterEx
import GetBitmapBits
import GetBitmapDimensionEx
import GetBkColor
import GetBkMode
import GetBoundsRect
import GetBrushOrgEx
import GetCharABCWidthsA
import GetCharABCWidthsW
import GetCharABCWidthsFloatA
import GetCharABCWidthsFloatW
import GetCharWidth32A
import GetCharWidth32W
import GetCharWidthA
import GetCharWidthW
import GetCharWidthFloatA
import GetCharWidthFloatW
import GetCharacterPlacementA
import GetCharacterPlacementW
import GetClipBox
import GetClipRgn
import GetColorAdjustment
import GetColorSpace
import GetCurrentObject
import GetCurrentPositionEx
import GetDCOrgEx
import GetDeviceCaps
import GetDeviceGammaRamp
import GetDIBColorTable
import GetDIBits
import GetEnhMetaFileA
import GetEnhMetaFileBits
import GetEnhMetaFileDescriptionA
import GetEnhMetaFileDescriptionW
import GetEnhMetaFileHeader
import GetEnhMetaFilePaletteEntries
import GetEnhMetaFileW
import GetFontData
import GetFontLanguageInfo
import GetGlyphOutlineA
import GetGlyphOutlineW
import GetGraphicsMode
import GetICMProfileA
import GetICMProfileW
import GetKerningPairsA
import GetKerningPairsW
import GetLogColorSpaceA
import GetLogColorSpaceW
import GetMapMode
import GetMetaFileA
import GetMetaFileBitsEx
import GetMetaFileW
import GetMetaRgn
import GetMiterLimit
import GetNearestColor
import GetNearestPaletteIndex
import GetObjectA
import GetObjectType
import GetObjectW
import GetOutlineTextMetricsA
import GetOutlineTextMetricsW
import GetPaletteEntries
import GetPath
import GetPixel
import GetPixelFormat
import GetPolyFillMode
import GetROP2
import GetRandomRgn
import GetRasterizerCaps
import GetRegionData
import GetRgnBox
import GetStockObject
import GetStretchBltMode
import GetSystemPaletteEntries
import GetSystemPaletteUse
import GetTextAlign
import GetTextCharacterExtra
import GetTextCharset
import GetTextCharsetInfo
import GetTextColor
import GetTextExtentExPointA
import GetTextExtentExPointW
import GetTextExtentPoint32A
import GetTextExtentPoint32W
import GetTextExtentPointA
import GetTextExtentPointW
import GetTextFaceA
import GetTextFaceW
import GetTextMetricsA
import GetTextMetricsW
import GetViewportExtEx
import GetViewportOrgEx
import GetWindowExtEx
import GetWindowOrgEx
import GetWinMetaFileBits
import GetWorldTransform
import IntersectClipRect
import InvertRgn
import LineDDA
import LineTo
import LPtoDP
import MaskBlt
import ModifyWorldTransform
import MoveToEx
import OffsetClipRgn
import OffsetRgn
import OffsetViewportOrgEx
import OffsetWindowOrgEx
import PaintRgn
import PatBlt
import PathToRegion
import Pie
import PlayEnhMetaFile
import PlayEnhMetaFileRecord
import PlayMetaFile
import PlayMetaFileRecord
import PlgBlt
import PolyBezier
import PolyBezierTo
import PolyDraw
import Polygon
import Polyline
import PolylineTo
import PolyPolygon
import PolyPolyline
import PolyTextOutA
import PolyTextOutW
import PtInRegion
import PtVisible
import RealizePalette
import Rectangle
import RectInRegion
import RectVisible
import RemoveFontResourceA
import RemoveFontResourceW
import ResetDCA
import ResetDCW
import ResizePalette
import RestoreDC
import RoundRect
import SaveDC
import ScaleViewportExtEx
import ScaleWindowExtEx
import SelectClipPath
import SelectClipRgn
import SelectObject
import SelectPalette
import SetAbortProc
import SetArcDirection
import SetBitmapBits
import SetBitmapDimensionEx
import SetBkColor
import SetBkMode
import SetBoundsRect
import SetBrushOrgEx
import SetColorAdjustment
import SetColorSpace
import SetDeviceGammaRamp
import SetDIBColorTable
import SetDIBits
import SetDIBitsToDevice
import SetEnhMetaFileBits
import SetFontEnumeration
import SetGraphicsMode
import SetICMMode
import SetICMProfileA
import SetICMProfileW
import SetMapMode
import SetMapperFlags
import SetMetaFileBitsEx
import SetMetaRgn
import SetMiterLimit
import SetPaletteEntries
import SetPixel
import SetPixelFormat
import SetPixelV
import SetPolyFillMode
import SetRectRgn
import SetROP2
import SetStretchBltMode
import SetSystemPaletteUse
import SetTextAlign
import SetTextCharacterExtra
import SetTextColor
import SetTextJustification
import SetViewportExtEx
import SetViewportOrgEx
import SetWindowExtEx
import SetWindowOrgEx
import SetWinMetaFileBits
import SetWorldTransform
import StartDocA
import StartDocW
import StartPage
import StretchBlt
import StretchDIBits
import StrokeAndFillPath
import StrokePath
import SwapBuffers
import TextOutA
import TextOutW
import TranslateCharsetInfo
import UnrealizeObject
import UpdateColors
import UpdateICMRegKeyA
import UpdateICMRegKeyW
import WidenPath

#if NTDDI_VERSION >= NTDDI_WIN98_ME
    import ColorCorrectPalette
    import EnableEUDC
    import GetLayout
    #if NTDDI_VERSION != NTDDI_WINNT4
        import SetLayout
    #endif
#endif

#if NTDDI_VERSION >= NTDDI_WINNT4
    import GdiAddFontResourceW
    import GdiAddGlsBounds
    import GdiCleanCacheDC
    import GdiConsoleTextOut
    import GdiConvertAndCheckDC
    import GdiConvertBitmap
    import GdiConvertBrush
    import GdiConvertDC
    import GdiConvertEnhMetaFile
    import GdiConvertFont
    import GdiConvertPalette
    import GdiConvertRegion
    import GdiDeleteLocalDC
    import GdiDescribePixelFormat
    import GdiDllInitialize
    import GdiFixUpHandle
    import GdiGetCharDimensions
    import GdiGetCodePage
    import GdiGetLocalBrush
    import GdiGetLocalDC
    import GdiGetLocalFont
    import GdiGetSpoolMessage
    import GdiInitSpool
    import GdiIsMetaFileDC
    import GdiIsMetaPrintDC
    import GdiProcessSetup
    import GdiQueryFonts
    import GdiQueryTable
    import GdiReleaseLocalDC
    import GdiSetAttrs
    import GdiSetPixelFormat
    import GdiSetServerAttr
    import GdiValidateHandle
    import GetCharWidthInfo
    import GetETM
    import GetEnhMetaFilePixelFormat
    import GetFontResourceInfoW
    import GetGlyphOutlineWow
    import GetHFONT
    import HT_Get8BPPFormatPalette
    import HT_Get8BPPMaskPalette
    import IsValidEnhMetaRecord
    import IsValidEnhMetaRecordOffExt
    import PolyPatBlt
    import SelectBrushLocal
    import SelectFontLocal
    import SetMagicColors
    define GetFontResourceInfo GetFontResourceInfoW
#endif

#if NTDDI_VERSION >= NTDDI_WIN2K
    import AddFontMemResourceEx
    import AddFontResourceExA
    import AddFontResourceExW
    import BRUSHOBJ_hGetColorTransform
    import BRUSHOBJ_pvAllocRbrush
    import BRUSHOBJ_pvGetRbrush
    import BRUSHOBJ_ulGetBrushColor
    import CLIPOBJ_bEnum
    import CLIPOBJ_cEnumStart
    import CLIPOBJ_ppoGetPath
    import CreateFontIndirectExA
    import CreateFontIndirectExW
    import EngAcquireSemaphore
    import EngAlphaBlend
    import EngAssociateSurface
    import EngBitBlt
    import EngCheckAbort
    import EngComputeGlyphSet
    import EngCopyBits
    import EngCreateBitmap
    import EngCreateClip
    import EngCreateDeviceBitmap
    import EngCreateDeviceSurface
    import EngCreatePalette
    import EngCreateSemaphore
    import EngDeleteClip
    import EngDeletePalette
    import EngDeletePath
    import EngDeleteSemaphore
    import EngDeleteSurface
    import EngEraseSurface
    import EngFillPath
    import EngFindResource
    import EngFreeModule
    import EngGetCurrentCodePage
    import EngGetDriverName
    import EngGetPrinterDataFileName
    import EngGradientFill
    import EngLineTo
    import EngLoadModule
    import EngLockSurface
    import EngMarkBandingSurface
    import EngMultiByteToUnicodeN
    import EngMultiByteToWideChar
    import EngPaint
    import EngPlgBlt
    import EngQueryLocalTime
    import EngReleaseSemaphore
    import EngStretchBlt
    import EngStretchBltROP
    import EngStrokeAndFillPath
    import EngStrokePath
    import EngTextOut
    import EngTransparentBlt
    import EngUnicodeToMultiByteN
    import EngUnlockSurface
    import EngWideCharToMultiByte
    import FONTOBJ_cGetAllGlyphHandles
    import FONTOBJ_cGetGlyphs
    import FONTOBJ_pQueryGlyphAttrs
    import FONTOBJ_pfdg
    import FONTOBJ_pifi
    import FONTOBJ_pvTrueTypeFontFile
    import FONTOBJ_pxoGetXform
    import FONTOBJ_vGetInfo
    import GdiAlphaBlend
    import GdiArtificialDecrementDriver
    import GdiConvertBitmapV5
    import GdiDeleteSpoolFileHandle
    import GdiEndDocEMF
    import GdiEndPageEMF
    import GdiFullscreenControl
    import GdiGetBitmapBitsSize
    import GdiGetDC
    import GetDCBrushColor
    import GetDCPenColor
    import GdiGetDevmodeForPage
    import GdiGetPageCount
    import GdiGetPageHandle
    import GdiGetSpoolFileHandle
    import GdiGradientFill
    import GdiInitializeLanguagePack
    import GdiIsPlayMetafileDC
    import GdiPlayEMF
    import GdiPlayPageEMF
    import GdiPrinterThunk
    import GdiRealizationInfo
    import GdiReleaseDC
    import GdiResetDCEMF
    import GdiSetLastError
    import GdiStartDocEMF
    import GdiStartPageEMF
    import GdiTransparentBlt
    import GetCharABCWidthsI
    import GetCharWidthI
    import GetEUDCTimeStamp
    import GetEUDCTimeStampExW
    import GetFontAssocStatus
    import GetFontUnicodeRanges
    import GetGlyphIndicesA
    import GetGlyphIndicesW
    import GetTextExtentExPointI
    import GetTextExtentExPointWPri
    import GetTextExtentPointI
    import GetTextFaceAliasW
    import MirrorRgn
    import PATHOBJ_bEnum
    import PATHOBJ_bEnumClipLines
    import PATHOBJ_vEnumStart
    import PATHOBJ_vEnumStartClipLines
    import PATHOBJ_vGetBounds
    import QueryFontAssocStatus
    import RemoveFontMemResourceEx
    import RemoveFontResourceExA
    import RemoveFontResourceExW
    import SetDCBrushColor
    import SetDCPenColor
    import SetLayoutWidth
    import StartFormPage
    import STROBJ_bEnum
    import STROBJ_bEnumPositionsOnly
    import STROBJ_bGetAdvanceWidths
    import STROBJ_dwGetCodePage
    import STROBJ_vEnumStart
    import XFORMOBJ_bApplyXform
    import XFORMOBJ_iGetXform
    import XLATEOBJ_cGetPalette
    import XLATEOBJ_hGetColorTransform
    import XLATEOBJ_iXlate
    import XLATEOBJ_piVector
    #ifdef APP_UNICODE
        define AddFontResourceEx AddFontResourceExW
        define CreateFontIndirectEx CreateFontIndirectExW
        define GetGlyphIndices GetGlyphIndicesW
        define RemoveFontResourceEx RemoveFontResourceExW
    #else
        define AddFontResourceEx AddFontResourceExA
        define CreateFontIndirectEx CreateFontIndirectExA
        define GetGlyphIndices GetGlyphIndicesA
        define RemoveFontResourceEx RemoveFontResourceExA
    #endif
#endif

#if NTDDI_VERSION >= NTDDI_WINXP
    import GetBrushAttributes
    import SetBitmapAttributes
#endif

#if NTDDI_VERSION >= NTDDI_VISTA
    import ConfigureOPMProtectedOutput
    import CreateOPMProtectedOutputs
    import D3DKMTCheckExclusiveOwnership
    import D3DKMTCheckMonitorPowerState
    import D3DKMTCheckOcclusion
    import D3DKMTCloseAdapter
    import D3DKMTCreateAllocation
    import D3DKMTCreateContext
    import D3DKMTCreateDCFromMemory
    import D3DKMTCreateDevice
    import D3DKMTCreateOverlay
    import D3DKMTCreateSynchronizationObject
    import D3DKMTDestroyAllocation
    import D3DKMTDestroyContext
    import D3DKMTDestroyDCFromMemory
    import D3DKMTDestroyDevice
    import D3DKMTDestroyOverlay
    import D3DKMTDestroySynchronizationObject
    import D3DKMTEscape
    import D3DKMTFlipOverlay
    import D3DKMTGetContextSchedulingPriority
    import D3DKMTGetDeviceState
    import D3DKMTGetDisplayModeList
    import D3DKMTGetMultisampleMethodList
    import D3DKMTGetPresentHistory
    import D3DKMTGetProcessSchedulingPriorityClass
    import D3DKMTGetRuntimeData
    import D3DKMTGetScanLine
    import D3DKMTGetSharedPrimaryHandle
    import D3DKMTInvalidateActiveVidPn
    import D3DKMTLock
    import D3DKMTOpenAdapterFromDeviceName
    import D3DKMTOpenAdapterFromGdiDisplayName
    import D3DKMTOpenAdapterFromHdc
    import D3DKMTOpenResource
    import D3DKMTPollDisplayChildren
    import D3DKMTPresent
    import D3DKMTQueryAdapterInfo
    import D3DKMTQueryAllocationResidency
    import D3DKMTQueryResourceInfo
    import D3DKMTReleaseProcessVidPnSourceOwners
    import D3DKMTRender
    import D3DKMTSetAllocationPriority
    import D3DKMTSetContextSchedulingPriority
    import D3DKMTSetDisplayMode
    import D3DKMTSetDisplayPrivateDriverFormat
    import D3DKMTSetGammaRamp
    import D3DKMTSetProcessSchedulingPriorityClass
    import D3DKMTSetQueuedLimit
    import D3DKMTSetVidPnSourceOwner
    import D3DKMTSharedPrimaryLockNotification
    import D3DKMTSharedPrimaryUnLockNotification
    import D3DKMTSignalSynchronizationObject
    import D3DKMTUnlock
    import D3DKMTUpdateOverlay
    import D3DKMTWaitForIdle
    import D3DKMTWaitForSynchronizationObject
    import D3DKMTWaitForVerticalBlankEvent
    import DDCCIGetCapabilitiesString
    import DDCCIGetCapabilitiesStringLength
    import DDCCIGetTimingReport
    import DDCCIGetVCPFeature
    import DDCCISaveCurrentSettings
    import DDCCISetVCPFeature
    import DestroyOPMProtectedOutput
    import DestroyPhysicalMonitorInternal
    import GdiIsScreenDC
    import GetCOPPCompatibleOPMInformation
    import GetNumberOfPhysicalMonitors
    import GetOPMInformation
    import GetOPMRandomNumber
    import GetPhysicalMonitorDescription
    import GetPhysicalMonitors
    import GetSuggestedOPMProtectedOutputArraySize
    import SetOPMSigningKeyAndSequenceNumbers
#endif

#if NTDDI_VERSION >= NTDDI_WIN7
    import D3DKMTAcquireKeyedMutex
    import D3DKMTCheckSharedResourceAccess
    import D3DKMTCheckVidPnExclusiveOwnership
    import D3DKMTConfigureSharedResource
    import D3DKMTCreateAllocation2
    import D3DKMTCreateKeyedMutex
    import D3DKMTCreateSynchronizationObject2
    import D3DKMTDestroyKeyedMutex
    import D3DKMTGetOverlayState
    import D3DKMTOpenKeyedMutex
    import D3DKMTOpenResource2
    import D3DKMTOpenSynchronizationObject
    import D3DKMTReleaseKeyedMutex
    import D3DKMTSignalSynchronizationObject2
    import D3DKMTWaitForSynchronizationObject2
#endif

#if NTDDI_VERSION >= NTDDI_WIN8
    import D3DKMTAcquireKeyedMutex2
    import D3DKMTCreateKeyedMutex2
    import D3DKMTCreateOutputDupl
    import D3DKMTDestroyOutputDupl
    import D3DKMTEnumAdapters
    import D3DKMTGetContextInProcessSchedulingPriority
    import D3DKMTGetSharedResourceAdapterLuid
    import D3DKMTOfferAllocations
    import D3DKMTOpenAdapterFromLuid
    import D3DKMTOpenKeyedMutex2
    import D3DKMTOpenNtHandleFromName
    import D3DKMTOpenResourceFromNtHandle
    import D3DKMTOpenSyncObjectFromNtHandle
    import D3DKMTOutputDuplGetFrameInfo
    import D3DKMTOutputDuplGetMetaData
    import D3DKMTOutputDuplGetPointerShapeData
    import D3DKMTOutputDuplPresent
    import D3DKMTOutputDuplReleaseFrame
    import D3DKMTPinDirectFlipResources
    import D3DKMTPresentMultiPlaneOverlay
    import D3DKMTQueryRemoteVidPnSourceFromGdiDisplayName
    import D3DKMTQueryResourceInfoFromNtHandle
    import D3DKMTReclaimAllocations
    import D3DKMTReleaseKeyedMutex2
    import D3DKMTSetContextInProcessSchedulingPriority
    import D3DKMTSetStereoEnabled
    import D3DKMTSetVidPnSourceOwner1
    import D3DKMTShareObjects
    import D3DKMTUnpinDirectFlipResources
    import D3DKMTWaitForVerticalBlankEvent2
    import GetCertificateSize
    import ScriptApplyDigitSubstitution
    import ScriptApplyLogicalWidth
    import ScriptBreak
    import ScriptCPtoX
    import ScriptCacheGetHeight
    import ScriptFreeCache
    import ScriptGetCMap
    import ScriptGetFontAlternateGlyphs
    import ScriptGetFontFeatureTags
    import ScriptGetFontLanguageTags
    import ScriptGetFontProperties
    import ScriptGetFontScriptTags
    import ScriptGetGlyphABCWidth
    import ScriptGetLogicalWidths
    import ScriptGetProperties
    import ScriptIsComplex
    import ScriptItemize
    import ScriptItemizeOpenType
    import ScriptJustify
    import ScriptLayout
    import ScriptPlace
    import ScriptPlaceOpenType
    import ScriptPositionSingleGlyph
    import ScriptRecordDigitSubstitution
    import ScriptShape
    import ScriptShapeOpenType
    import ScriptStringAnalyse
    import ScriptStringCPtoX
    import ScriptStringFree
    import ScriptStringGetLogicalWidths
    import ScriptStringGetOrder
    import ScriptStringOut
    import ScriptStringValidate
    import ScriptStringXtoCP
    import ScriptString_pLogAttr
    import ScriptString_pSize
    import ScriptString_pcOutChars
    import ScriptSubstituteSingleGlyph
    import ScriptTextOut
    import ScriptXtoCP
#endif

#if NTDDI_VERSION >= NTDDI_WIN81
    import D3DKMTCheckMultiPlaneOverlaySupport
    import D3DKMTCheckMultiPlaneOverlaySupport2
#endif

#if NTDDI_VERSION >= NTDDI_WIN10
    import D3DKMTCreateContextVirtual
    import D3DKMTCreatePagingQueue
    import D3DKMTDestroyAllocation2
    import D3DKMTDestroyPagingQueue
    import D3DKMTEvict
    import D3DKMTFreeGpuVirtualAddress
    import D3DKMTLock2
    import D3DKMTMakeResident
    import D3DKMTMapGpuVirtualAddress
    import D3DKMTOpenSyncObjectFromNtHandle2
    import D3DKMTOpenSyncObjectNtHandleFromName
    import D3DKMTReclaimAllocations2
    import D3DKMTRegisterTrimNotification
    import D3DKMTReserveGpuVirtualAddress
    import D3DKMTSignalSynchronizationObjectFromCpu
    import D3DKMTSignalSynchronizationObjectFromGpu
    import D3DKMTSignalSynchronizationObjectFromGpu2
    import D3DKMTSubmitCommand
    import D3DKMTUnlock2
    import D3DKMTUnregisterTrimNotification
    import D3DKMTUpdateGpuVirtualAddress
    import D3DKMTWaitForSynchronizationObjectFromCpu
    import D3DKMTWaitForSynchronizationObjectFromGpu
#endif

#ifdef APP_UNICODE
    define AddFontResource AddFontResourceW
    define CopyEnhMetaFile CopyEnhMetaFileW
    define CopyMetaFile CopyMetaFileW
    define CreateColorSpace CreateColorSpaceW
    define CreateDC CreateDCW
    define CreateEnhMetaFile CreateEnhMetaFileW
    define CreateFont CreateFontW
    define CreateFontIndirect CreateFontIndirectW
    define CreateIC CreateICW
    define CreateMetaFile CreateMetaFileW
    define CreateScalableFontResource CreateScalableFontResourceW
    define DeviceCapabilitiesEx DeviceCapabilitiesExW
    define EnumFontFamilies EnumFontFamiliesW
    define EnumFontFamiliesEx EnumFontFamiliesExW
    define EnumFonts EnumFontsW
    define EnumICMProfiles EnumICMProfilesW
    define ExtTextOut ExtTextOutW
    define GetCharABCWidths GetCharABCWidthsW
    define GetCharABCWidthsFloat GetCharABCWidthsFloatW
    define GetCharWidth GetCharWidthW
    define GetCharWidth32 GetCharWidth32W
    define GetCharWidthFloat GetCharWidthFloatW
    define GetCharacterPlacement GetCharacterPlacementW
    define GetEnhMetaFile GetEnhMetaFileW
    define GetEnhMetaFileDescription GetEnhMetaFileDescriptionW
    define GetGlyphOutline GetGlyphOutlineW
    define GetICMProfile GetICMProfileW
    define GetKerningPairs GetKerningPairsW
    define GetLogColorSpace GetLogColorSpaceW
    define GetMetaFile GetMetaFileW
    define GetObject GetObjectW
    define GetOutlineTextMetrics GetOutlineTextMetricsW
    define GetTextExtentExPoint GetTextExtentExPointW
    define GetTextExtentPoint32 GetTextExtentPoint32W
    define GetTextExtentPoint GetTextExtentPointW
    define GetTextFace GetTextFaceW
    define GetTextMetrics GetTextMetricsW
    define PolyTextOut PolyTextOutW
    define RemoveFontResource RemoveFontResourceW
    define ResetDC ResetDCW
    define SetICMProfile SetICMProfileW
    define StartDoc StartDocW
    define TextOut TextOutW
    define UpdateICMRegKey UpdateICMRegKeyW
#else
    define AddFontResource AddFontResourceA
    define CopyEnhMetaFile CopyEnhMetaFileA
    define CopyMetaFile CopyMetaFileA
    define CreateColorSpace CreateColorSpaceA
    define CreateDC CreateDCA
    define CreateEnhMetaFile CreateEnhMetaFileA
    define CreateFont CreateFontA
    define CreateFontIndirect CreateFontIndirectA
    define CreateIC CreateICA
    define CreateMetaFile CreateMetaFileA
    define CreateScalableFontResource CreateScalableFontResourceA
    define DeviceCapabilitiesEx DeviceCapabilitiesExA
    define EnumFontFamilies EnumFontFamiliesA
    define EnumFontFamiliesEx EnumFontFamiliesExA
    define EnumFonts EnumFontsA
    define EnumICMProfiles EnumICMProfilesA
    define ExtTextOut ExtTextOutA
    define GetCharABCWidths GetCharABCWidthsA
    define GetCharABCWidthsFloat GetCharABCWidthsFloatA
    define GetCharWidth GetCharWidthA
    define GetCharWidth32 GetCharWidth32A
    define GetCharWidthFloat GetCharWidthFloatA
    define GetCharacterPlacement GetCharacterPlacementA
    define GetEnhMetaFile GetEnhMetaFileA
    define GetEnhMetaFileDescription GetEnhMetaFileDescriptionA
    define GetGlyphOutline GetGlyphOutlineA
    define GetICMProfile GetICMProfileA
    define GetKerningPairs GetKerningPairsA
    define GetLogColorSpace GetLogColorSpaceA
    define GetMetaFile GetMetaFileA
    define GetObject GetObjectA
    define GetOutlineTextMetrics GetOutlineTextMetricsA
    define GetTextExtentExPoint GetTextExtentExPointA
    define GetTextExtentPoint32 GetTextExtentPoint32A
    define GetTextExtentPoint GetTextExtentPointA
    define GetTextFace GetTextFaceA
    define GetTextMetrics GetTextMetricsA
    define PolyTextOut PolyTextOutA
    define RemoveFontResource RemoveFontResourceA
    define ResetDC ResetDCA
    define SetICMProfile SetICMProfileA
    define StartDoc StartDocA
    define TextOut TextOutA
    define UpdateICMRegKey UpdateICMRegKeyA
#endif

;======================= Undocumented functions (unknown arguments) =======================;
;import AddFontResourceTracking
;import AnyLinkedFonts
;import BeginGdiRendering
;import ClearBitmapAttributes
;import ClearBrushAttributes
;import CreateBitmapFromDxSurface
;import CreateBitmapFromDxSurface2
;import CreateSessionMappedDIBSection
;import D3DKMTAbandonSwapChain
;import D3DKMTAcquireSwapChain
;import D3DKMTAdjustFullscreenGamma
;import D3DKMTCacheHybridQueryValue
;import D3DKMTChangeVideoMemoryReservation
;import D3DKMTCreateSwapChain
;import D3DKMTEnumAdapters2
;import D3DKMTFlushHeapTransitions
;import D3DKMTGetCachedHybridQueryValue
;import D3DKMTGetDWMVerticalBlankEvent
;import D3DKMTGetPresentQueueEvent
;import D3DKMTGetResourcePresentPrivateDriverData
;import D3DKMTGetSetSwapChainMetadata
;import D3DKMTInvalidateCache
;import D3DKMTMarkDeviceAsError
;import D3DKMTNetDispGetNextChunkInfo
;import D3DKMTNetDispQueryMiracastDisplayDeviceStatus
;import D3DKMTNetDispQueryMiracastDisplayDeviceSupport
;import D3DKMTNetDispStartMiracastDisplayDevice
;import D3DKMTNetDispStartMiracastDisplayDevice2
;import D3DKMTNetDispStartMiracastDisplayDeviceEx
;import D3DKMTNetDispStopMiracastDisplayDevice
;import D3DKMTNetDispStopSessions
;import D3DKMTOpenSwapChain
;import D3DKMTPresentMultiPlaneOverlay2
;import D3DKMTQueryClockCalibration
;import D3DKMTQueryStatistics
;import D3DKMTQueryVideoMemoryInfo
;import D3DKMTQueryVidPnExclusiveOwnership
;import D3DKMTReleaseSwapChain
;import D3DKMTSetDodIndirectSwapchain
;import D3DKMTSetHwProtectionTeardownRecovery
;import D3DKMTSetStablePowerState
;import D3DKMTSetSyncRefreshCountWaitTarget
;import D3DKMTSetVidPnSourceHwProtection
;import DdCreateFullscreenSprite
;import DdDestroyFullscreenSprite
;import DdEntry0
;import DdEntry1
;import DdEntry10
;import DdEntry11
;import DdEntry12
;import DdEntry13
;import DdEntry14
;import DdEntry15
;import DdEntry16
;import DdEntry17
;import DdEntry18
;import DdEntry19
;import DdEntry2
;import DdEntry20
;import DdEntry21
;import DdEntry22
;import DdEntry23
;import DdEntry24
;import DdEntry25
;import DdEntry26
;import DdEntry27
;import DdEntry28
;import DdEntry29
;import DdEntry3
;import DdEntry30
;import DdEntry31
;import DdEntry32
;import DdEntry33
;import DdEntry34
;import DdEntry35
;import DdEntry36
;import DdEntry37
;import DdEntry38
;import DdEntry39
;import DdEntry4
;import DdEntry40
;import DdEntry41
;import DdEntry42
;import DdEntry43
;import DdEntry44
;import DdEntry45
;import DdEntry46
;import DdEntry47
;import DdEntry48
;import DdEntry49
;import DdEntry5
;import DdEntry50
;import DdEntry51
;import DdEntry52
;import DdEntry53
;import DdEntry54
;import DdEntry55
;import DdEntry56
;import DdEntry6
;import DdEntry7
;import DdEntry8
;import DdEntry9
;import DdNotifyFullscreenSpriteUpdate
;import DdQueryVisRgnUniqueness
;import DwmGetDirtyRgn
;DwmGetSurfaceData
;import EndFormPage
;import EndGdiRendering
;import EngQueryEMFInfo
;import EudcLoadLinkW
;import EudcUnloadLinkW
;import FontIsLinked
;ftsWordBreak
;import GdiAddGlsRecord
;import GdiClearStockObjectCache
;import GdiConvertMetaFilePict
;import GdiConvertToDevmodeW
;import GdiCreateLocalEnhMetaFile
;import GdiCreateLocalMetaFilePict
;import GdiDrawStream
;import GdiIsUMPDSandboxingEnabled
;import GdiEntry1
;import GdiEntry10
;import GdiEntry11
;import GdiEntry12
;import GdiEntry13
;import GdiEntry14
;import GdiEntry15
;import GdiEntry16
;import GdiEntry2
;import GdiEntry3
;import GdiEntry4
;import GdiEntry5
;import GdiEntry6
;import GdiEntry7
;import GdiEntry8
;import GdiEntry9
;import GdiLoadType1Fonts
;import GdiPlayPrivatePageEMF
;import GdiSupportsFontChangeEvent
;import GdiSwapBuffers
;import GetBitmapAttributes
;import GetCertificate
;import GetCertificateByHandle
;import GetCertificateSizeByHandle
;import GetCurrentDpiInfo
;import GetFontFileData
;import GetFontFileInfo
;import GetFontRealizationInfo
;import GetRelAbs
;import GetStringBitmapA
;import GetStringBitmapW
;import GetTransform
;import LpkDrawTextEx
;import LpkEditControl
;import LpkExtTextOut
;import LpkGetCharacterPlacement
;import LpkGetTextExtentExPoint
;import LpkInitialize
;import LpkPSMTextOut
;import LpkPresent
;import LpkTabbedTextOut
;import LpkUseGDIWidthCache
;import NamedEscape
;import RemoveFontResourceTracking
;import SetBrushAttributes
;import SetRelAbs
;import SetVirtualResolution
;import UnloadNetworkFonts
;import UspAllocCache
;import UspAllocTemp
;import UspFreeMem
;import bInitSystemAndFontsDirectoriesW
;import bMakePathNameW
;import cGetTTFFromFOT
;import pfnRealizePalette
;import pfnSelectPalette

;#ifdef APP_UNICODE
;    define GetStringBitmap GetStringBitmapW
;#else
;    define GetStringBitmap GetStringBitmapA
;#endif

#endif ;GDI32_INC
