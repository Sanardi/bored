; ====================================================;
;                                                     ;
;    richedit.inc for EC v2 Fasm classic projects     ;
;                   (version 1.0.4)                   ;
;                                                     ;
;         Copyright © Ramon Sala - 2018-2020          ;
;                                                     ;
; ====================================================;

if ~defined RICHEDIT_INC
define RICHEDIT_INC 1

if ~defined _RICHEDIT_VER
    define _RICHEDIT_VER                        0800H
end if

define cchTextLimitDefault                      32767

if ~defined LF_FACESIZE
    define LF_FACESIZE                          32
end if

if ~defined WM_CONTEXTMENU
    define WM_CONTEXTMENU                       007BH
end if

if ~defined WM_UNICHAR
    define WM_UNICHAR                           0109H
end if

if ~defined WM_PRINTCLIENT
    define WM_PRINTCLIENT                       0318H
end if

if ~defined EM_GETLIMITTEXT
    define EM_GETLIMITTEXT                      (WM_USER + 37)
end if

if ~defined EM_POSFROMCHAR
    define EM_POSFROMCHAR                       (WM_USER + 38)
    define EM_CHARFROMPOS                       (WM_USER + 39)
end if

if ~defined EM_SCROLLCARET
    define EM_SCROLLCARET                       (WM_USER + 49)
end if

RICHEDIT_CLASSA                                 db      'RichEdit20A', 0
RICHEDIT_CLASSW                                 du      'RichEdit20W', 0

define EM_CANPASTE                              (WM_USER + 50)
define EM_DISPLAYBAND                           (WM_USER + 51)
define EM_EXGETSEL                              (WM_USER + 52)
define EM_EXLIMITTEXT                           (WM_USER + 53)
define EM_EXLINEFROMCHAR                        (WM_USER + 54)
define EM_EXSETSEL                              (WM_USER + 55)
define EM_FINDTEXT                              (WM_USER + 56)
define EM_FORMATRANGE                           (WM_USER + 57)
define EM_GETCHARFORMAT                         (WM_USER + 58)
define EM_GETEVENTMASK                          (WM_USER + 59)
define EM_GETOLEINTERFACE                       (WM_USER + 60)
define EM_GETPARAFORMAT                         (WM_USER + 61)
define EM_GETSELTEXT                            (WM_USER + 62)
define EM_HIDESELECTION                         (WM_USER + 63)
define EM_PASTESPECIAL                          (WM_USER + 64)
define EM_REQUESTRESIZE                         (WM_USER + 65)
define EM_SELECTIONTYPE                         (WM_USER + 66)
define EM_SETBKGNDCOLOR                         (WM_USER + 67)
define EM_SETCHARFORMAT                         (WM_USER + 68)
define EM_SETEVENTMASK                          (WM_USER + 69)
define EM_SETOLECALLBACK                        (WM_USER + 70)
define EM_SETPARAFORMAT                         (WM_USER + 71)
define EM_SETTARGETDEVICE                       (WM_USER + 72)
define EM_STREAMIN                              (WM_USER + 73)
define EM_STREAMOUT                             (WM_USER + 74)
define EM_GETTEXTRANGE                          (WM_USER + 75)
define EM_FINDWORDBREAK                         (WM_USER + 76)
define EM_SETOPTIONS                            (WM_USER + 77)
define EM_GETOPTIONS                            (WM_USER + 78)
define EM_FINDTEXTEX                            (WM_USER + 79)
define EM_GETWORDBREAKPROCEX                    (WM_USER + 80)
define EM_SETWORDBREAKPROCEX                    (WM_USER + 81)
define EM_SETUNDOLIMIT                          (WM_USER + 82)
define EM_REDO                                  (WM_USER + 84)
define EM_CANREDO                               (WM_USER + 85)
define EM_GETUNDONAME                           (WM_USER + 86)
define EM_GETREDONAME                           (WM_USER + 87)
define EM_STOPGROUPTYPING                       (WM_USER + 88)
define EM_SETTEXTMODE                           (WM_USER + 89)
define EM_GETTEXTMODE                           (WM_USER + 90)
define EM_AUTOURLDETECT                         (WM_USER + 91)
define EM_GETAUTOURLDETECT                      (WM_USER + 92)
define EM_SETPALETTE                            (WM_USER + 93)
define EM_GETTEXTEX                             (WM_USER + 94)
define EM_GETTEXTLENGTHEX                       (WM_USER + 95)
define EM_SHOWSCROLLBAR                         (WM_USER + 96)
define EM_SETTEXTEX                             (WM_USER + 97)
define EM_SETPUNCTUATION                        (WM_USER + 100)
define EM_GETPUNCTUATION                        (WM_USER + 101)
define EM_SETWORDWRAPMODE                       (WM_USER + 102)
define EM_GETWORDWRAPMODE                       (WM_USER + 103)
define EM_SETIMECOLOR                           (WM_USER + 104)
define EM_GETIMECOLOR                           (WM_USER + 105)
define EM_SETIMEOPTIONS                         (WM_USER + 106)
define EM_GETIMEOPTIONS                         (WM_USER + 107)
define EM_CONVPOSITION                          (WM_USER + 108)
define EM_SETLANGOPTIONS                        (WM_USER + 120)
define EM_GETLANGOPTIONS                        (WM_USER + 121)
define EM_GETIMECOMPMODE                        (WM_USER + 122)
define EM_FINDTEXTW                             (WM_USER + 123)
define EM_FINDTEXTEXW                           (WM_USER + 124)
define EM_RECONVERSION                          (WM_USER + 125)
define EM_SETIMEMODEBIAS                        (WM_USER + 126)
define EM_GETIMEMODEBIAS                        (WM_USER + 127)
define EM_SETBIDIOPTIONS                        (WM_USER + 200)
define EM_GETBIDIOPTIONS                        (WM_USER + 201)
define EM_SETTYPOGRAPHYOPTIONS                  (WM_USER + 202)
define EM_GETTYPOGRAPHYOPTIONS                  (WM_USER + 203)
define EM_SETEDITSTYLE                          (WM_USER + 204)
define EM_GETEDITSTYLE                          (WM_USER + 205)
define EM_OUTLINE                               (WM_USER + 220)
define EM_GETSCROLLPOS                          (WM_USER + 221)
define EM_SETSCROLLPOS                          (WM_USER + 222)
define EM_SETFONTSIZE                           (WM_USER + 223)
define EM_GETZOOM                               (WM_USER + 224)
define EM_SETZOOM                               (WM_USER + 225)
define EM_GETVIEWKIND                           (WM_USER + 226)
define EM_SETVIEWKIND                           (WM_USER + 227)

if _RICHEDIT_VER >= 0800H
    define AURL_ENABLEURL                       1
    define AURL_ENABLEEMAILADDR                 2
    define AURL_ENABLETELNO                     4
    define AURL_ENABLEEAURLS                    8
    define AURL_ENABLEDRIVELETTERS              16
    define AURL_DISABLEMIXEDLGC                 32
end if

define SES_EMULATESYSEDIT                       1
define SES_BEEPONMAXTEXT                        2
define SES_EXTENDBACKCOLOR                      4
define SES_MAPCPS                               8
if _RICHEDIT_VER >= 0500H
    define SES_HYPERLINKTOOLTIPS                8
end if
define SES_EMULATE10                            16
if _RICHEDIT_VER >= 0700H
    define SES_DEFAULTLATINLIGA                 16
end if
define SES_USECRLF                              32
define SES_USEAIMM                              64
define SES_NOIME                                128

define SES_ALLOWBEEPS                           256
define SES_UPPERCASE                            512
define SES_LOWERCASE                            1024
define SES_NOINPUTSEQUENCECHK                   2048
define SES_BIDI                                 4096
define SES_SCROLLONKILLFOCUS                    8192
define SES_XLTCRCRLFTOCR                        16384
define SES_DRAFTMODE                            32768

define SES_USECTF                               00010000H
define SES_HIDEGRIDLINES                        00020000H
define SES_USEATFONT                            00040000H
define SES_CUSTOMLOOK                           00080000H
define SES_LBSCROLLNOTIFY                       00100000H
define SES_CTFALLOWEMBED                        00200000H
define SES_CTFALLOWSMARTTAG                     00400000H
define SES_CTFALLOWPROOFING                     00800000H
if _RICHEDIT_VER >= 0500H
    define SES_LOGICALCARET                     01000000H
    define SES_WORDDRAGDROP                     02000000H
    define SES_SMARTDRAGDROP                    04000000H
    define SES_MULTISELECT                      08000000H
    define SES_CTFNOLOCK                        10000000H
    define SES_NOEALINEHEIGHTADJUST             20000000H
    define SES_MAX                              20000000H
end if

define IMF_AUTOKEYBOARD                         0001H
define IMF_AUTOFONT                             0002H
define IMF_IMECANCELCOMPLETE                    0004H
define IMF_IMEALWAYSSENDNOTIFY                  0008H
define IMF_AUTOFONTSIZEADJUST                   0010H
define IMF_UIFONTS                              0020H
if _RICHEDIT_VER >= 0800H
    define IMF_NOIMPLICITLANG                   0040H
end if
define IMF_DUALFONT                             0080H
if _RICHEDIT_VER >= 0800H
    define IMF_NOKBDLIDFIXUP                    0200H
end if
define IMF_NORTFFONTSUBSTITUTE                  0400H
if _RICHEDIT_VER >= 0800H
    define IMF_SPELLCHECKING                    0800H
    define IMF_TKBPREDICTION                    1000H
end if

define ICM_NOTOPEN                              0000H
define ICM_LEVEL3                               0001H
define ICM_LEVEL2                               0002H
define ICM_LEVEL2_5                             0003H
define ICM_LEVEL2_SUI                           0004H
define ICM_CTF                                  0005H

define TO_ADVANCEDTYPOGRAPHY                    0001H
define TO_SIMPLELINEBREAK                       0002H
define TO_DISABLECUSTOMTEXTOUT                  0004H
define TO_ADVANCEDLAYOUT                        0008H

define EM_GETPAGE                               (WM_USER + 228)
define EM_SETPAGE                               (WM_USER + 229)
define EM_GETHYPHENATEINFO                      (WM_USER + 230)
define EM_SETHYPHENATEINFO                      (WM_USER + 231)

define EM_GETPAGEROTATE                         (WM_USER + 235)
define EM_SETPAGEROTATE                         (WM_USER + 236)
define EM_GETCTFMODEBIAS                        (WM_USER + 237)
define EM_SETCTFMODEBIAS                        (WM_USER + 238)
define EM_GETCTFOPENSTATUS                      (WM_USER + 240)
define EM_SETCTFOPENSTATUS                      (WM_USER + 241)
define EM_GETIMECOMPTEXT                        (WM_USER + 242)
define EM_ISIME                                 (WM_USER + 243)
define EM_GETIMEPROPERTY                        (WM_USER + 244)

define EM_GETQUERYRTFOBJ                        (WM_USER + 269)
define EM_SETQUERYRTFOBJ                        (WM_USER + 270)

define EPR_0                                    0
define EPR_270                                  1
define EPR_180                                  2
define EPR_90                                   3

if _RICHEDIT_VER >= 0800H
    define EPR_SE                               5
end if

define CTFMODEBIAS_DEFAULT                      0000H
define CTFMODEBIAS_FILENAME                     0001H
define CTFMODEBIAS_NAME                         0002H
define CTFMODEBIAS_READING                      0003H
define CTFMODEBIAS_DATETIME                     0004H
define CTFMODEBIAS_CONVERSATION                 0005H
define CTFMODEBIAS_NUMERIC                      0006H
define CTFMODEBIAS_HIRAGANA                     0007H
define CTFMODEBIAS_KATAKANA                     0008H
define CTFMODEBIAS_HANGUL                       0009H
define CTFMODEBIAS_HALFWIDTHKATAKANA            000AH
define CTFMODEBIAS_FULLWIDTHALPHANUMERIC        000BH
define CTFMODEBIAS_HALFWIDTHALPHANUMERIC        000CH

define IMF_SMODE_PLAURALCLAUSE                  0001H
define IMF_SMODE_NONE                           0002H

define ICT_RESULTREADSTR                        1

define EMO_EXIT                                 0
define EMO_ENTER                                1
define EMO_PROMOTE                              2
define EMO_EXPAND                               3
define EMO_MOVESELECTION                        4
define EMO_GETVIEWMODE                          5

define EMO_EXPANDSELECTION                      0
define EMO_EXPANDDOCUMENT                       1

define VM_NORMAL                                4
define VM_OUTLINE                               2
define VM_PAGE                                  9

if _RICHEDIT_VER >= 0800H
    define EM_INSERTTABLE                       (WM_USER + 232)

    define EM_GETAUTOCORRECTPROC                (WM_USER + 233)
    define EM_SETAUTOCORRECTPROC                (WM_USER + 234)
    define EM_CALLAUTOCORRECTPROC               (WM_USER + 255)

    define ATP_NOCHANGE                         0
    define ATP_CHANGE                           1
    define ATP_NODELIMITER                      2
    define ATP_REPLACEALLTEXT                   4

    define EM_GETTABLEPARMS                     (WM_USER + 265)

    define EM_SETEDITSTYLEEX                    (WM_USER + 275)
    define EM_GETEDITSTYLEEX                    (WM_USER + 276)

    define SES_EX_NOTABLE                       00000004H
    define SES_EX_HANDLEFRIENDLYURL             00000100H
    define SES_EX_NOTHEMING                     00080000H
    define SES_EX_NOACETATESELECTION            00100000H
    define SES_EX_USESINGLELINE                 00200000H
    define SES_EX_MULTITOUCH                    08000000H
    define SES_EX_HIDETEMPFORMAT                10000000H
    define SES_EX_USEMOUSEWPARAM                20000000H

    define EM_GETSTORYTYPE                      (WM_USER + 290)
    define EM_SETSTORYTYPE                      (WM_USER + 291)

    define EM_GETELLIPSISMODE                   (WM_USER + 305)
    define EM_SETELLIPSISMODE                   (WM_USER + 306)

    define ELLIPSIS_MASK                        00000003H
    define ELLIPSIS_NONE                        00000000H
    define ELLIPSIS_END                         00000001H
    define ELLIPSIS_WORD                        00000003H

    define EM_SETTABLEPARMS                     (WM_USER + 307)

    define EM_GETTOUCHOPTIONS                   (WM_USER + 310)
    define EM_SETTOUCHOPTIONS                   (WM_USER + 311)
    define EM_INSERTIMAGE                       (WM_USER + 314)
    define EM_SETUIANAME                        (WM_USER + 320)
    define EM_GETELLIPSISSTATE                  (WM_USER + 322)

    define RTO_SHOWHANDLES                      1
    define RTO_DISABLEHANDLES                   2
    define RTO_READINGMODE                      3
end if

define EN_MSGFILTER                             0700H
define EN_REQUESTRESIZE                         0701H
define EN_SELCHANGE                             0702H
define EN_DROPFILES                             0703H
define EN_PROTECTED                             0704H
define EN_CORRECTTEXT                           0705H
define EN_STOPNOUNDO                            0706H
define EN_IMECHANGE                             0707H
define EN_SAVECLIPBOARD                         0708H
define EN_OLEOPFAILED                           0709H
define EN_OBJECTPOSITIONS                       070AH
define EN_LINK                                  070BH
define EN_DRAGDROPDONE                          070CH
define EN_PARAGRAPHEXPANDED                     070DH
define EN_PAGECHANGE                            070EH
define EN_LOWFIRTF                              070FH
define EN_ALIGNLTR                              0710H
define EN_ALIGNRTL                              0711H
if _RICHEDIT_VER >= 0800H
    define EN_CLIPFORMAT                        0712H
    define EN_STARTCOMPOSITION                  0713H
    define EN_ENDCOMPOSITION                    0714H
    define ECN_ENDCOMPOSITION                   0001H
    define ECN_NEWTEXT                          0002H
end if

define ENM_NONE                                 00000000H
define ENM_CHANGE                               00000001H
define ENM_UPDATE                               00000002H
define ENM_SCROLL                               00000004H
define ENM_SCROLLEVENTS                         00000008H
define ENM_DRAGDROPDONE                         00000010H
define ENM_PARAGRAPHEXPANDED                    00000020H
define ENM_PAGECHANGE                           00000040H
if _RICHEDIT_VER >= 0800H
    define ENM_CLIPFORMAT                       00000080H
end if
define ENM_KEYEVENTS                            00010000H
define ENM_MOUSEEVENTS                          00020000H
define ENM_REQUESTRESIZE                        00040000H
define ENM_SELCHANGE                            00080000H
define ENM_DROPFILES                            00100000H
define ENM_PROTECTED                            00200000H
define ENM_CORRECTTEXT                          00400000H
define ENM_IMECHANGE                            00800000H
define ENM_LANGCHANGE                           01000000H
define ENM_OBJECTPOSITIONS                      02000000H
define ENM_LINK                                 04000000H
define ENM_LOWFIRTF                             08000000H
if _RICHEDIT_VER >= 0800H
    define ENM_STARTCOMPOSITION                 10000000H
    define ENM_ENDCOMPOSITION                   20000000H
    define ENM_GROUPTYPINGCHANGE                40000000H
    define ENM_HIDELINKTOOLTIP                  80000000H
end if

define ES_SAVESEL                               00008000H
define ES_SUNKEN                                00004000H
define ES_DISABLENOSCROLL                       00002000H
define ES_SELECTIONBAR                          01000000H
define ES_NOOLEDRAGDROP                         00000008H
if (NTDDI_VERSION > NTDDI_WIN98_ME)
    define ES_EX_NOCALLOLEINIT                  00000000H
else
    define ES_EX_NOCALLOLEINIT                  01000000H
end if
define ES_VERTICAL                              00400000H
define ES_NOIME                                 00080000H
define ES_SELFIME                               00040000H

define ECO_AUTOWORDSELECTION                    00000001H
define ECO_AUTOVSCROLL                          00000040H
define ECO_AUTOHSCROLL                          00000080H
define ECO_NOHIDESEL                            00000100H
define ECO_READONLY                             00000800H
define ECO_WANTRETURN                           00001000H
define ECO_SAVESEL                              00008000H
define ECO_SELECTIONBAR                         01000000H
define ECO_VERTICAL                             00400000H

define ECOOP_SET                                0001H
define ECOOP_OR                                 0002H
define ECOOP_AND                                0003H
define ECOOP_XOR                                0004H

define WB_CLASSIFY                              3
define WB_MOVEWORDLEFT                          4
define WB_MOVEWORDRIGHT                         5
define WB_LEFTBREAK                             6
define WB_RIGHTBREAK                            7

define WB_MOVEWORDPREV                          4
define WB_MOVEWORDNEXT                          5
define WB_PREVBREAK                             6
define WB_NEXTBREAK                             7

define PC_FOLLOWING                             1
define PC_LEADING                               2
define PC_OVERFLOW                              3
define PC_DELIMITER                             4

define WBF_WORDWRAP                             0010H
define WBF_WORDBREAK                            0020H
define WBF_OVERFLOW                             0040H
define WBF_LEVEL1                               0080H
define WBF_LEVEL2                               0100H
define WBF_CUSTOM                               0200H

define IMF_FORCENONE                            0001H
define IMF_FORCEENABLE                          0002H
define IMF_FORCEDISABLE                         0004H
define IMF_CLOSESTATUSWINDOW                    0008H
define IMF_VERTICAL                             0020H
define IMF_FORCEACTIVE                          0040H
define IMF_FORCEINACTIVE                        0080H
define IMF_FORCEREMEMBER                        0100H
define IMF_MULTIPLEEDIT                         0400H

define WBF_CLASS                                0FH
define WBF_ISWHITE                              10H
define WBF_BREAKLINE                            20H
define WBF_BREAKAFTER                           40H

define CFM_BOLD                                 00000001H
define CFM_ITALIC                               00000002H
define CFM_UNDERLINE                            00000004H
define CFM_STRIKEOUT                            00000008H
define CFM_PROTECTED                            00000010H
define CFM_LINK                                 00000020H
define CFM_SIZE                                 80000000H
define CFM_COLOR                                40000000H
define CFM_FACE                                 20000000H
define CFM_OFFSET                               10000000H
define CFM_CHARSET                              08000000H

define CFE_BOLD                                 00000001H
define CFE_ITALIC                               00000002H
define CFE_UNDERLINE                            00000004H
define CFE_STRIKEOUT                            00000008H
define CFE_PROTECTED                            00000010H
define CFE_LINK                                 00000020H
define CFE_AUTOCOLOR                            40000000H

define CFM_SMALLCAPS                            00000040H
define CFM_ALLCAPS                              00000080H
define CFM_HIDDEN                               00000100H
define CFM_OUTLINE                              00000200H
define CFM_SHADOW                               00000400H
define CFM_EMBOSS                               00000800H
define CFM_IMPRINT                              00001000H
define CFM_DISABLED                             00002000H
define CFM_REVISED                              00004000H

define CFM_REVAUTHOR                            00008000H
define CFE_SUBSCRIPT                            00010000H
define CFE_SUPERSCRIPT                          00020000H
define CFM_ANIMATION                            00040000H
define CFM_STYLE                                00080000H
define CFM_KERNING                              00100000H
define CFM_SPACING                              00200000H
define CFM_WEIGHT                               00400000H
define CFM_UNDERLINETYPE                        00800000H
if _RICHEDIT_VER >= 0600H
    define CFM_COOKIE                           01000000H
end if
define CFM_LCID                                 02000000H
define CFM_BACKCOLOR                            04000000H

define CFM_SUBSCRIPT                            (CFE_SUBSCRIPT or CFE_SUPERSCRIPT)
define CFM_SUPERSCRIPT                          CFM_SUBSCRIPT

define CFM_EFFECTS                              (CFM_BOLD or CFM_ITALIC or CFM_UNDERLINE or CFM_COLOR or CFM_STRIKEOUT or CFE_PROTECTED or CFM_LINK)
define CFM_ALL                                  (CFM_EFFECTS or CFM_SIZE or CFM_FACE or CFM_OFFSET or CFM_CHARSET)

define CFM_EFFECTS2                             (CFM_EFFECTS or CFM_DISABLED or CFM_SMALLCAPS or CFM_ALLCAPS or CFM_HIDDEN or CFM_OUTLINE or CFM_SHADOW or CFM_EMBOSS or CFM_IMPRINT or CFM_REVISED or CFM_SUBSCRIPT or CFM_SUPERSCRIPT or CFM_BACKCOLOR)

if _RICHEDIT_VER >= 0600H
    define CFM_ALL2                             (CFM_ALL or CFM_EFFECTS2 or CFM_BACKCOLOR or CFM_LCID or CFM_UNDERLINETYPE or CFM_WEIGHT or CFM_REVAUTHOR or CFM_SPACING or CFM_KERNING or CFM_STYLE or CFM_ANIMATION or CFM_COOKIE)
else
    define CFM_ALL2                             (CFM_ALL or CFM_EFFECTS2 or CFM_BACKCOLOR or CFM_LCID or CFM_UNDERLINETYPE or CFM_WEIGHT or CFM_REVAUTHOR or CFM_SPACING or CFM_KERNING or CFM_STYLE or CFM_ANIMATION)
end if

define CFE_SMALLCAPS                            CFM_SMALLCAPS
define CFE_ALLCAPS                              CFM_ALLCAPS
define CFE_HIDDEN                               CFM_HIDDEN
define CFE_OUTLINE                              CFM_OUTLINE
define CFE_SHADOW                               CFM_SHADOW
define CFE_EMBOSS                               CFM_EMBOSS
define CFE_IMPRINT                              CFM_IMPRINT
define CFE_DISABLED                             CFM_DISABLED
define CFE_REVISED                              CFM_REVISED

define CFE_AUTOBACKCOLOR                        CFM_BACKCOLOR

define CFM_FONTBOUND                            00100000H
define CFM_LINKPROTECTED                        00800000H
define CFM_EXTENDED                             02000000H
define CFM_MATHNOBUILDUP                        08000000H
define CFM_MATH                                 10000000H
define CFM_MATHORDINARY                         20000000H

define CFM_ALLEFFECTS                           (CFM_EFFECTS2 or CFM_FONTBOUND or CFM_EXTENDED or CFM_MATHNOBUILDUP or CFM_MATH or CFM_MATHORDINARY)

define CFE_FONTBOUND                            00100000H
define CFE_LINKPROTECTED                        00800000H
define CFE_EXTENDED                             02000000H
define CFE_MATHNOBUILDUP                        08000000H
define CFE_MATH                                 10000000H
define CFE_MATHORDINARY                         20000000H

define CFU_CF1UNDERLINE                         0FFH
define CFU_INVERT                               0FEH
define CFU_UNDERLINETHICKLONGDASH               18
define CFU_UNDERLINETHICKDOTTED                 17
define CFU_UNDERLINETHICKDASHDOTDOT             16
define CFU_UNDERLINETHICKDASHDOT                15
define CFU_UNDERLINETHICKDASH                   14
define CFU_UNDERLINELONGDASH                    13
define CFU_UNDERLINEHEAVYWAVE                   12
define CFU_UNDERLINEDOUBLEWAVE                  11
define CFU_UNDERLINEHAIRLINE                    10
define CFU_UNDERLINETHICK                       9
define CFU_UNDERLINEWAVE                        8
define CFU_UNDERLINEDASHDOTDOT                  7
define CFU_UNDERLINEDASHDOT                     6
define CFU_UNDERLINEDASH                        5
define CFU_UNDERLINEDOTTED                      4
define CFU_UNDERLINEDOUBLE                      3
define CFU_UNDERLINEWORD                        2
define CFU_UNDERLINE                            1
define CFU_UNDERLINENONE                        0

define yHeightCharPtsMost                       1638

define SCF_SELECTION                            0001H
define SCF_WORD                                 0002H
define SCF_DEFAULT                              0000H
define SCF_ALL                                  0004H
define SCF_USEUIRULES                           0008H

define SCF_ASSOCIATEFONT                        0010H

define SCF_NOKBUPDATE                           0020H

define SCF_ASSOCIATEFONT2                       0040H
if _RICHEDIT_VER >= 0500H
    define SCF_SMARTFONT                        0080H
    define SCF_CHARREPFROMLCID                  0100H

    define SPF_DONTSETDEFAULT                   0002H
    define SPF_SETDEFAULT                       0004H
end if

define SF_TEXT                                  0001H
define SF_RTF                                   0002H
define SF_RTFNOOBJS                             0003H
define SF_TEXTIZED                              0004H

define SF_UNICODE                               0010H
define SF_USECODEPAGE                           0020H
define SF_NCRFORNONASCII                        0040H
define SFF_WRITEXTRAPAR                         0080H
define SFF_SELECTION                            8000H
define SFF_PLAINRTF                             4000H
define SFF_PERSISTVIEWSCALE                     2000H
define SFF_KEEPDOCINFO                          1000H
define SFF_PWD                                  0800H
define SF_RTFVAL                                0700H

define MAX_TAB_STOPS                            32
define lDefaultTab                              720
define MAX_TABLE_CELLS                          63

define PFM_STARTINDENT                          00000001H
define PFM_RIGHTINDENT                          00000002H
define PFM_OFFSET                               00000004H
define PFM_ALIGNMENT                            00000008H
define PFM_TABSTOPS                             00000010H
define PFM_NUMBERING                            00000020H
define PFM_OFFSETINDENT                         80000000H

define PFM_SPACEBEFORE                          00000040H
define PFM_SPACEAFTER                           00000080H
define PFM_LINESPACING                          00000100H
define PFM_STYLE                                00000400H
define PFM_BORDER                               00000800H
define PFM_SHADING                              00001000H
define PFM_NUMBERINGSTYLE                       00002000H
define PFM_NUMBERINGTAB                         00004000H
define PFM_NUMBERINGSTART                       00008000H

define PFM_RTLPARA                              00010000H
define PFM_KEEP                                 00020000H
define PFM_KEEPNEXT                             00040000H
define PFM_PAGEBREAKBEFORE                      00080000H
define PFM_NOLINENUMBER                         00100000H
define PFM_NOWIDOWCONTROL                       00200000H
define PFM_DONOTHYPHEN                          00400000H
define PFM_SIDEBYSIDE                           00800000H

define PFM_COLLAPSED                            01000000H
define PFM_OUTLINELEVEL                         02000000H
define PFM_BOX                                  04000000H
define PFM_RESERVED2                            08000000H
define PFM_TABLEROWDELIMITER                    10000000H
define PFM_TEXTWRAPPINGBREAK                    20000000H
define PFM_TABLE                                40000000H

define PFM_ALL                                  (PFM_STARTINDENT or PFM_RIGHTINDENT or PFM_OFFSET or PFM_ALIGNMENT or PFM_TABSTOPS or PFM_NUMBERING or PFM_OFFSETINDENT or PFM_RTLPARA)

define PFM_EFFECTS                              (PFM_RTLPARA or PFM_KEEP or PFM_KEEPNEXT or PFM_TABLE or PFM_PAGEBREAKBEFORE or PFM_NOLINENUMBER or PFM_NOWIDOWCONTROL or PFM_DONOTHYPHEN or PFM_SIDEBYSIDE or PFM_TABLE or PFM_TABLEROWDELIMITER)

define PFM_ALL2                                 (PFM_ALL or PFM_EFFECTS or PFM_SPACEBEFORE or PFM_SPACEAFTER or PFM_LINESPACING or PFM_STYLE or PFM_SHADING or PFM_BORDER or PFM_NUMBERINGTAB or PFM_NUMBERINGSTART or PFM_NUMBERINGSTYLE)

define PFE_RTLPARA                              (PFM_RTLPARA shr 16)
define PFE_KEEP                                 (PFM_KEEP shr 16)
define PFE_KEEPNEXT                             (PFM_KEEPNEXT shr 16)
define PFE_PAGEBREAKBEFORE                      (PFM_PAGEBREAKBEFORE shr 16)
define PFE_NOLINENUMBER                         (PFM_NOLINENUMBER shr 16)
define PFE_NOWIDOWCONTROL                       (PFM_NOWIDOWCONTROL shr 16)
define PFE_DONOTHYPHEN                          (PFM_DONOTHYPHEN shr 16)
define PFE_SIDEBYSIDE                           (PFM_SIDEBYSIDE shr 16)

define PFE_TEXTWRAPPINGBREAK                    (PFM_TEXTWRAPPINGBREAK shr 16)

define PFE_COLLAPSED                            (PFM_COLLAPSED shr 16)
define PFE_BOX                                  (PFM_BOX shr 16)
define PFE_TABLE                                (PFM_TABLE shr 16)
define PFE_TABLEROWDELIMITER                    (PFM_TABLEROWDELIMITER shr 16)

define PFN_BULLET                               1

define PFN_ARABIC                               2
define PFN_LCLETTER                             3
define PFN_UCLETTER                             4
define PFN_LCROMAN                              5
define PFN_UCROMAN                              6

define PFNS_PAREN                               000H
define PFNS_PARENS                              100H
define PFNS_PERIOD                              200H
define PFNS_PLAIN                               300H
define PFNS_NONUMBER                            400H

define PFNS_NEWNUMBER                           8000H

define PFA_LEFT                                 1
define PFA_RIGHT                                2
define PFA_CENTER                               3

define PFA_JUSTIFY                              4
define PFA_FULL_INTERWORD                       4

if ~defined WM_NOTIFY
    define WM_NOTIFY                            004EH
end if

define SEL_EMPTY                                0000H
define SEL_TEXT                                 0001H
define SEL_OBJECT                               0002H
define SEL_MULTICHAR                            0004H
define SEL_MULTIOBJECT                          0008H

define GCM_RIGHTMOUSEDROP                       8000H

if _RICHEDIT_VER >= 0800H
    define GCMF_GRIPPER                         00000001H
    define GCMF_SPELLING                        00000002H
    define GCMF_TOUCHMENU                       00004000H
    define GCMF_MOUSEMENU                       00002000H
end if

define OLEOP_DOVERB                             1

define ST_DEFAULT                               0
define ST_KEEPUNDO                              1
define ST_SELECTION                             2
define ST_NEWCHARS                              4
if _RICHEDIT_VER >= 0500H
    define ST_UNICODE                           8
end if

define GT_DEFAULT                               0
define GT_USECRLF                               1
define GT_SELECTION                             2
define GT_RAWTEXT                               4
define GT_NOHIDDENTEXT                          8

define GTL_DEFAULT                              0
define GTL_USECRLF                              1
define GTL_PRECISE                              2
define GTL_CLOSE                                4
define GTL_NUMCHARS                             8
define GTL_NUMBYTES                             16

if _RICHEDIT_VER = 0100H
    define BOM_DEFPARADIR                       0001H
    define BOM_PLAINTEXT                        0002H
end if
define BOM_NEUTRALOVERRIDE                      0004H
define BOM_CONTEXTREADING                       0008H
define BOM_CONTEXTALIGNMENT                     0010H
define BOM_LEGACYBIDICLASS                      0040H
if _RICHEDIT_VER >= 0600H
    define BOM_UNICODEBIDI                      0080H
end if

if _RICHEDIT_VER = 0100H
    define BOE_RTLDIR                           0001H
    define BOE_PLAINTEXT                        0002H
end if
define BOE_NEUTRALOVERRIDE                      0004H
define BOE_CONTEXTREADING                       0008H
define BOE_CONTEXTALIGNMENT                     0010H
if _RICHEDIT_VER >= 0800H
    define BOE_FORCERECALC                      0020H
end if
define BOE_LEGACYBIDICLASS                      0040H
if _RICHEDIT_VER >= 0600H
    define BOE_UNICODEBIDI                      0080H
end if

define FR_MATCHDIAC                             20000000H
define FR_MATCHKASHIDA                          40000000H
define FR_MATCHALEFHAMZA                        80000000H

if ~defined WCH_EMBEDDING
    define WCH_EMBEDDING                        0FFFCH
end if

define PFA_FULL_NEWSPAPER                       5
define PFA_FULL_INTERLETTER                     6
define PFA_FULL_SCALED                          7
define PFA_FULL_GLYPHS                          8

define AURL_ENABLEEA                            1

define GCM_TOUCHMENU                            4000H
define GCM_MOUSEMENU                            2000H

define TM_PLAINTEXT                             1
define TM_RICHTEXT                              2
define TM_SINGLELEVELUNDO                       4
define TM_MULTILEVELUNDO                        8
define TM_SINGLECODEPAGE                        16
define TM_MULTICODEPAGE                         32

define UID_UNKNOWN                              0
define UID_TYPING                               1
define UID_DELETE                               2
define UID_DRAGDROP                             3
define UID_CUT                                  4
define UID_PASTE                                5
define UID_AUTOTABLE                            6

define khyphNil                                 0
define khyphNormal                              1
define khyphAddBefore                           2
define khyphChangeBefore                        3
define khyphDeleteBefore                        4
define khyphChangeAfter                         5
define khyphDelAndChange                        6

;======================================== Structures ======================================;
struct CHARFORMATA
    cbSize          dd ?
    dwMask          dd ?
    dwEffects       dd ?
    yHeight         dd ?
    yOffset         dd ?
    crTextColor     dd ?
    bCharSet        db ?
    bPitchAndFamily db ?
    szFaceName      db LF_FACESIZE dup(?)
ends

struct CHARFORMATW
    cbSize          dd ?
    dwMask          dd ?
    dwEffects       dd ?
    yHeight         dd ?
    yOffset         dd ?
    crTextColor     dd ?
    bCharSet        db ?
    bPitchAndFamily db ?
    szFaceName      dw LF_FACESIZE dup(?)
ends

struct CHARFORMAT2A
    cbSize          dd ?
    dwMask          dd ?
    dwEffects       dd ?
    yHeight         dd ?
    yOffset         dd ?
    crTextColor     dd ?
    bCharSet        db ?
    bPitchAndFamily db ?
    szFaceName      db LF_FACESIZE dup(?)
    wWeight         dw ?
    sSpacing        dw ?
    crBackColor     dd ?
    lcid            dd ?
    dwReserved      dd ?
    sStyle          dw ?
    wKerning        dw ?
    bUnderlineType  db ?
    bAnimation      db ?
    bRevAuthor      db ?
    bReserved1      db ?
ends

struct CHARFORMAT2W
    cbSize          dd ?
    dwMask          dd ?
    dwEffects       dd ?
    yHeight         dd ?
    yOffset         dd ?
    crTextColor     dd ?
    bCharSet        db ?
    bPitchAndFamily db ?
    szFaceName      dw LF_FACESIZE dup(?)
    wWeight         dw ?
    sSpacing        dw ?
    crBackColor     dd ?
    lcid            dd ?
    dwReserved      dd ?
    sStyle          dw ?
    wKerning        dw ?
    bUnderlineType  db ?
    bAnimation      db ?
    bRevAuthor      db ?
    bReserved1      db ?
ends

struct CHARRANGE
    cpMin dd ?
    cpMax dd ?
ends

struct COMPCOLOR
    crText       dd ?
    crBackground dd ?
    dwEffects    dd ?
ends

struct TEXTRANGEA
    chrg      CHARRANGE
    lpstrText xptr ?
ends

struct TEXTRANGEW
    chrg      CHARRANGE
    lpstrText xptr ?
ends

struct EDITSTREAM
    dwCookie    dd ?
    dwError     dd ?
    pfnCallback xptr ?
ends

struct FINDTEXTA
    chrg      CHARRANGE
    lpstrText xptr ?
ends

struct FINDTEXTW
    chrg      CHARRANGE
    lpstrText xptr ?
ends

struct FINDTEXTEXA
    chrg      CHARRANGE
    lpstrText xptr ?
    chrgText  CHARRANGE
ends

struct FINDTEXTEXW
    chrg      CHARRANGE
    lpstrText xptr ?
    chrgText  CHARRANGE
ends

struct FORMATRANGE
    hdc       xptr ?
    hdcTarget xptr ?
    rc        RECT
    rcPage    RECT
    chrg      CHARRANGE
ends

struct HYPHENATEINFO
    cbSize          dw   ?
    dxHyphenateZone dw   ?
    pfnHyphenate    xptr ?
ends

struct PARAFORMAT
    cbSize        dd ?
    dwMask        dd ?
    wNumbering    dw ?
    wEffects      dw ?
    dxStartIndent dd ?
    dxRightIndent dd ?
    dxOffset      dd ?
    wAlignment    dw ?
    cTabCount     dw ?
    rgxTabs       dd MAX_TAB_STOPS dup(?)
ends

struct PARAFORMAT2
    cbSize           dd ?
    dwMask           dd ?
    wNumbering       dw ?
    wReserved        dw ?
    dxStartIndent    dd ?
    dxRightIndent    dd ?
    dxOffset         dd ?
    wAlignment       dw ?
    cTabCount        dw ?
    rgxTabs          dd MAX_TAB_STOPS dup(?)
    dySpaceBefore    dd ?
    dySpaceAfter     dd ?
    dyLineSpacing    dd ?
    sStyle           dw ?
    bLineSpacingRule db ?
    bOutlineLevel    db ?
    wShadingWeight   dw ?
    wShadingStyle    dw ?
    wNumberingStart  dw ?
    wNumberingStyle  dw ?
    wNumberingTab    dw ?
    wBorderSpace     dw ?
    wBorderWidth     dw ?
    wBorders         dw ?
ends

struct IMECOMPTEXT
    cb    dd ?
    flags dd ?
ends

if _RICHEDIT_VER >= 0800H
    struct RICHEDIT_IMAGE_PARAMETERS
        xWidth            dd   ?
        xHeight           dd   ?
        Ascent            dd   ?
        Type              dd   ?
        pwszAlternateText xptr ?
        pIStream          xptr ?
    ends

    struct ENDCOMPOSITIONNOTIFY
        nmhdr  NMHDR
        dwCode dd    ?
    ends
end if

struct MSGFILTER
    nmhdr   NMHDR
    msg     dd    ?
    wParam  dd    ?
    lParam  dd    ?
ends

struct REQRESIZE
    nmhdr NMHDR
    rc    RECT 
ends

struct SELCHANGE
    nmhdr  NMHDR    
    chrg   CHARRANGE
    seltyp dw        ?
ends

struct ENDROPFILES
    nmhdr       NMHDR
    hDrop       xptr  ?
    cp          dd    ?
    fProtected  dd    ?
ends

struct ENPROTECTED
    nmhdr   NMHDR    
    msg     dd        ?
    wParam  xptr      ?
    lParam  xptr      ?
    chrg    CHARRANGE
ends

struct ENSAVECLIPBOARD
    nmhdr        NMHDR
    cObjectCount dd    ?
    cch          dd    ?
ends

struct ENOLEOPFAILED
    nmhdr NMHDR
    iob   dd    ?
    lOper dd    ?
    hr    dd    ?
ends

struct OBJECTPOSITIONS
    nmhdr        NMHDR
    cObjectCount dd    ?
    pcpPositions xptr  ?
ends

struct ENLINK
    nmhdr  NMHDR    
    msg    dd        ?
    wParam xptr      ?
    lParam xptr      ?
    chrg   CHARRANGE
ends

struct ENCORRECTTEXT
    nmhdr  NMHDR    
    chrg   CHARRANGE
    seltyp dw        ?
ends

struct PUNCTUATION
    iSize         dd   ?
    szPunctuation xptr ?
ends

struc REPASTESPECIAL
{
    dwAspect    dd ?
    if (NTDDI_VERSION >= NTDDI_WIN2K)
        dwParam dq ?
    else
        dwParam dd ?
    end if
}

struct SETTEXTEX
    flags    dd ?
    codepage dd ?
ends

struct GETTEXTEX
    cb            dd   ?
    flags         dd   ?
    codepage      dd   ?
    lpDefaultChar xptr ?
    lpUsedDefChar xptr ?
ends

struct GETTEXTLENGTHEX
    flags    dd ?
    codepage dd ?
ends

struct BIDIOPTIONS
    cbSize   dd ?
    wMask    dw ?
    wEffects dw ?
ends

struct CLIPBOARDFORMAT
    nmhdr NMHDR
    cf    dw    ?
ends

struct ENLOWFIRTF
    nmhdr     NMHDR
    szControl xptr  ?
ends

struct HYPHRESULT
    khyph   dd    ?
    ichHyph xptr  ?
    chHyph  dw    ?
ends

if _RICHEDIT_VER >= 0800H
    struct GROUPTYPINGCHANGE
        nmhdr        NMHDR
        fGroupTyping dd    ?
    ends

    struct GETCONTEXTMENUEX
        chrg       CHARRANGE
        dwFlags    dd        ?
        pt         POINT    
        pvReserved xptr      ?
    ends
end if

api RICHEDIT_CLASS,\
    CHARFORMAT,\
    CHARFORMAT2,\
    TEXTRANGE,\
    FINDTEXT,\
    FINDTEXTEX

end if ;RICHEDIT_INC
