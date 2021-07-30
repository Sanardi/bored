; ======================================================;
;                                                       ;
;  richedit.inc for Easy Code 2.0 64-bit Masm projects  ;
;                  (version 1.0.3)                      ;
;                                                       ;
;          Copyright © Ramon Sala - 2017-2020           ;
;                                                       ;
; ======================================================;

IFNDEF RICHEDIT_INC
RICHEDIT_INC     EQU     1

IFNDEF MACROS_INC
    Include macros.inc
ENDIF

IFNDEF _RICHEDIT_VER
    _RICHEDIT_VER                               EQU     0800H
ENDIF

cchTextLimitDefault                             EQU     32767

MSFTEDIT_CLASS                                  EQU     L("RICHEDIT50W")

CERICHEDIT_CLASSA                               EQU     <RichEditCEA>
CERICHEDIT_CLASSW                               EQU     L("RichEditCEW")

RICHEDIT_CLASSA                                 EQU     <RichEdit20A>
RICHEDIT_CLASSW                                 EQU     L("RichEdit20W")

CF_RTF                                          EQU     <Rich Text Format>
CF_RTFNOOBJS                                    EQU     <Rich Text Format Without Objects>
CF_RETEXTOBJ                                    EQU     <RichEdit Text and Objects>

IFNDEF LF_FACESIZE
    LF_FACESIZE                                 EQU     32
ENDIF

IFNDEF WM_CONTEXTMENU
    WM_CONTEXTMENU                              EQU     007BH
ENDIF

IFNDEF WM_UNICHAR
    WM_UNICHAR                                  EQU     0109H
ENDIF

IFNDEF WM_PRINTCLIENT
    WM_PRINTCLIENT                              EQU     0318H
ENDIF

IFNDEF EM_GETLIMITTEXT
    EM_GETLIMITTEXT                             EQU     (WM_USER + 37)
ENDIF

IFNDEF EM_POSFROMCHAR
    EM_POSFROMCHAR                              EQU     (WM_USER + 38)
    EM_CHARFROMPOS                              EQU     (WM_USER + 39)
ENDIF

IFNDEF EM_SCROLLCARET
    EM_SCROLLCARET                              EQU     (WM_USER + 49)
ENDIF

EM_CANPASTE                                     EQU     (WM_USER + 50)
EM_DISPLAYBAND                                  EQU     (WM_USER + 51)
EM_EXGETSEL                                     EQU     (WM_USER + 52)
EM_EXLIMITTEXT                                  EQU     (WM_USER + 53)
EM_EXLINEFROMCHAR                               EQU     (WM_USER + 54)
EM_EXSETSEL                                     EQU     (WM_USER + 55)
EM_FINDTEXT                                     EQU     (WM_USER + 56)
EM_FORMATRANGE                                  EQU     (WM_USER + 57)
EM_GETCHARFORMAT                                EQU     (WM_USER + 58)
EM_GETEVENTMASK                                 EQU     (WM_USER + 59)
EM_GETOLEINTERFACE                              EQU     (WM_USER + 60)
EM_GETPARAFORMAT                                EQU     (WM_USER + 61)
EM_GETSELTEXT                                   EQU     (WM_USER + 62)
EM_HIDESELECTION                                EQU     (WM_USER + 63)
EM_PASTESPECIAL                                 EQU     (WM_USER + 64)
EM_REQUESTRESIZE                                EQU     (WM_USER + 65)
EM_SELECTIONTYPE                                EQU     (WM_USER + 66)
EM_SETBKGNDCOLOR                                EQU     (WM_USER + 67)
EM_SETCHARFORMAT                                EQU     (WM_USER + 68)
EM_SETEVENTMASK                                 EQU     (WM_USER + 69)
EM_SETOLECALLBACK                               EQU     (WM_USER + 70)
EM_SETPARAFORMAT                                EQU     (WM_USER + 71)
EM_SETTARGETDEVICE                              EQU     (WM_USER + 72)
EM_STREAMIN                                     EQU     (WM_USER + 73)
EM_STREAMOUT                                    EQU     (WM_USER + 74)
EM_GETTEXTRANGE                                 EQU     (WM_USER + 75)
EM_FINDWORDBREAK                                EQU     (WM_USER + 76)
EM_SETOPTIONS                                   EQU     (WM_USER + 77)
EM_GETOPTIONS                                   EQU     (WM_USER + 78)
EM_FINDTEXTEX                                   EQU     (WM_USER + 79)
EM_GETWORDBREAKPROCEX                           EQU     (WM_USER + 80)
EM_SETWORDBREAKPROCEX                           EQU     (WM_USER + 81)
EM_SETUNDOLIMIT                                 EQU     (WM_USER + 82)
EM_REDO                                         EQU     (WM_USER + 84)
EM_CANREDO                                      EQU     (WM_USER + 85)
EM_GETUNDONAME                                  EQU     (WM_USER + 86)
EM_GETREDONAME                                  EQU     (WM_USER + 87)
EM_STOPGROUPTYPING                              EQU     (WM_USER + 88)
EM_SETTEXTMODE                                  EQU     (WM_USER + 89)
EM_GETTEXTMODE                                  EQU     (WM_USER + 90)
EM_AUTOURLDETECT                                EQU     (WM_USER + 91)
EM_GETAUTOURLDETECT                             EQU     (WM_USER + 92)
EM_SETPALETTE                                   EQU     (WM_USER + 93)
EM_GETTEXTEX                                    EQU     (WM_USER + 94)
EM_GETTEXTLENGTHEX                              EQU     (WM_USER + 95)
EM_SHOWSCROLLBAR                                EQU     (WM_USER + 96)
EM_SETTEXTEX                                    EQU     (WM_USER + 97)
EM_SETPUNCTUATION                               EQU     (WM_USER + 100)
EM_GETPUNCTUATION                               EQU     (WM_USER + 101)
EM_SETWORDWRAPMODE                              EQU     (WM_USER + 102)
EM_GETWORDWRAPMODE                              EQU     (WM_USER + 103)
EM_SETIMECOLOR                                  EQU     (WM_USER + 104)
EM_GETIMECOLOR                                  EQU     (WM_USER + 105)
EM_SETIMEOPTIONS                                EQU     (WM_USER + 106)
EM_GETIMEOPTIONS                                EQU     (WM_USER + 107)
EM_CONVPOSITION                                 EQU     (WM_USER + 108)
EM_SETLANGOPTIONS                               EQU     (WM_USER + 120)
EM_GETLANGOPTIONS                               EQU     (WM_USER + 121)
EM_GETIMECOMPMODE                               EQU     (WM_USER + 122)
EM_FINDTEXTW                                    EQU     (WM_USER + 123)
EM_FINDTEXTEXW                                  EQU     (WM_USER + 124)
EM_RECONVERSION                                 EQU     (WM_USER + 125)
EM_SETIMEMODEBIAS                               EQU     (WM_USER + 126)
EM_GETIMEMODEBIAS                               EQU     (WM_USER + 127)
EM_SETBIDIOPTIONS                               EQU     (WM_USER + 200)
EM_GETBIDIOPTIONS                               EQU     (WM_USER + 201)
EM_SETTYPOGRAPHYOPTIONS                         EQU     (WM_USER + 202)
EM_GETTYPOGRAPHYOPTIONS                         EQU     (WM_USER + 203)
EM_SETEDITSTYLE                                 EQU     (WM_USER + 204)
EM_GETEDITSTYLE                                 EQU     (WM_USER + 205)
EM_OUTLINE                                      EQU     (WM_USER + 220)
EM_GETSCROLLPOS                                 EQU     (WM_USER + 221)
EM_SETSCROLLPOS                                 EQU     (WM_USER + 222)
EM_SETFONTSIZE                                  EQU     (WM_USER + 223)
EM_GETZOOM                                      EQU     (WM_USER + 224)
EM_SETZOOM                                      EQU     (WM_USER + 225)
EM_GETVIEWKIND                                  EQU     (WM_USER + 226)
EM_SETVIEWKIND                                  EQU     (WM_USER + 227)

IF _RICHEDIT_VER GE 0800H
    AURL_ENABLEURL                              EQU     1
    AURL_ENABLEEMAILADDR                        EQU     2
    AURL_ENABLETELNO                            EQU     4
    AURL_ENABLEEAURLS                           EQU     8
    AURL_ENABLEDRIVELETTERS                     EQU     16
    AURL_DISABLEMIXEDLGC                        EQU     32
ENDIF

SES_EMULATESYSEDIT                              EQU     1
SES_BEEPONMAXTEXT                               EQU     2
SES_EXTENDBACKCOLOR                             EQU     4
SES_MAPCPS                                      EQU     8
IF _RICHEDIT_VER GE 0500H
    SES_HYPERLINKTOOLTIPS                       EQU     8
ENDIF
SES_EMULATE10                                   EQU     16
IF _RICHEDIT_VER GE 0700H
    SES_DEFAULTLATINLIGA                        EQU     16
ENDIF
SES_USECRLF                                     EQU     32
SES_USEAIMM                                     EQU     64
SES_NOIME                                       EQU     128

SES_ALLOWBEEPS                                  EQU     256
SES_UPPERCASE                                   EQU     512
SES_LOWERCASE                                   EQU     1024
SES_NOINPUTSEQUENCECHK                          EQU     2048
SES_BIDI                                        EQU     4096
SES_SCROLLONKILLFOCUS                           EQU     8192
SES_XLTCRCRLFTOCR                               EQU     16384
SES_DRAFTMODE                                   EQU     32768

SES_USECTF                                      EQU     00010000H
SES_HIDEGRIDLINES                               EQU     00020000H
SES_USEATFONT                                   EQU     00040000H
SES_CUSTOMLOOK                                  EQU     00080000H
SES_LBSCROLLNOTIFY                              EQU     00100000H
SES_CTFALLOWEMBED                               EQU     00200000H
SES_CTFALLOWSMARTTAG                            EQU     00400000H
SES_CTFALLOWPROOFING                            EQU     00800000H
IF _RICHEDIT_VER GE 0500H
    SES_LOGICALCARET                            EQU     01000000H
    SES_WORDDRAGDROP                            EQU     02000000H
    SES_SMARTDRAGDROP                           EQU     04000000H
    SES_MULTISELECT                             EQU     08000000H
    SES_CTFNOLOCK                               EQU     10000000H
    SES_NOEALINEHEIGHTADJUST                    EQU     20000000H
    SES_MAX                                     EQU     20000000H
ENDIF

IMF_AUTOKEYBOARD                                EQU     0001H
IMF_AUTOFONT                                    EQU     0002H
IMF_IMECANCELCOMPLETE                           EQU     0004H
IMF_IMEALWAYSSENDNOTIFY                         EQU     0008H
IMF_AUTOFONTSIZEADJUST                          EQU     0010H
IMF_UIFONTS                                     EQU     0020H
IF _RICHEDIT_VER GE 0800H
    IMF_NOIMPLICITLANG                          EQU     0040H
ENDIF
IMF_DUALFONT                                    EQU     0080H
IF _RICHEDIT_VER GE 0800H
    IMF_NOKBDLIDFIXUP                           EQU     0200H
ENDIF
IMF_NORTFFONTSUBSTITUTE                         EQU     0400H
IF _RICHEDIT_VER GE 0800H
    IMF_SPELLCHECKING                           EQU     0800H
    IMF_TKBPREDICTION                           EQU     1000H
ENDIF

ICM_NOTOPEN                                     EQU     0000H
ICM_LEVEL3                                      EQU     0001H
ICM_LEVEL2                                      EQU     0002H
ICM_LEVEL2_5                                    EQU     0003H
ICM_LEVEL2_SUI                                  EQU     0004H
ICM_CTF                                         EQU     0005H

TO_ADVANCEDTYPOGRAPHY                           EQU     0001H
TO_SIMPLELINEBREAK                              EQU     0002H
TO_DISABLECUSTOMTEXTOUT                         EQU     0004H
TO_ADVANCEDLAYOUT                               EQU     0008H

EM_GETPAGE                                      EQU     (WM_USER + 228)
EM_SETPAGE                                      EQU     (WM_USER + 229)
EM_GETHYPHENATEINFO                             EQU     (WM_USER + 230)
EM_SETHYPHENATEINFO                             EQU     (WM_USER + 231)

EM_GETPAGEROTATE                                EQU     (WM_USER + 235)
EM_SETPAGEROTATE                                EQU     (WM_USER + 236)
EM_GETCTFMODEBIAS                               EQU     (WM_USER + 237)
EM_SETCTFMODEBIAS                               EQU     (WM_USER + 238)
EM_GETCTFOPENSTATUS                             EQU     (WM_USER + 240)
EM_SETCTFOPENSTATUS                             EQU     (WM_USER + 241)
EM_GETIMECOMPTEXT                               EQU     (WM_USER + 242)
EM_ISIME                                        EQU     (WM_USER + 243)
EM_GETIMEPROPERTY                               EQU     (WM_USER + 244)

EM_GETQUERYRTFOBJ                               EQU     (WM_USER + 269)
EM_SETQUERYRTFOBJ                               EQU     (WM_USER + 270)

EPR_0                                           EQU     0
EPR_270                                         EQU     1
EPR_180                                         EQU     2
EPR_90                                          EQU     3
IF _RICHEDIT_VER GE 0800H
    EPR_SE                                      EQU     5
ENDIF

CTFMODEBIAS_DEFAULT                             EQU     0000H
CTFMODEBIAS_FILENAME                            EQU     0001H
CTFMODEBIAS_NAME                                EQU     0002H
CTFMODEBIAS_READING                             EQU     0003H
CTFMODEBIAS_DATETIME                            EQU     0004H
CTFMODEBIAS_CONVERSATION                        EQU     0005H
CTFMODEBIAS_NUMERIC                             EQU     0006H
CTFMODEBIAS_HIRAGANA                            EQU     0007H
CTFMODEBIAS_KATAKANA                            EQU     0008H
CTFMODEBIAS_HANGUL                              EQU     0009H
CTFMODEBIAS_HALFWIDTHKATAKANA                   EQU     000aH
CTFMODEBIAS_FULLWIDTHALPHANUMERIC               EQU     000bH
CTFMODEBIAS_HALFWIDTHALPHANUMERIC               EQU     000cH

IMF_SMODE_PLAURALCLAUSE                         EQU     0001H
IMF_SMODE_NONE                                  EQU     0002H

ICT_RESULTREADSTR                               EQU     1

EMO_EXIT                                        EQU     0
EMO_ENTER                                       EQU     1
EMO_PROMOTE                                     EQU     2
EMO_EXPAND                                      EQU     3
EMO_MOVESELECTION                               EQU     4
EMO_GETVIEWMODE                                 EQU     5

EMO_EXPANDSELECTION                             EQU     0
EMO_EXPANDDOCUMENT                              EQU     1

VM_NORMAL                                       EQU     4
VM_OUTLINE                                      EQU     2
VM_PAGE                                         EQU     9

IF _RICHEDIT_VER GE 0800H
    EM_INSERTTABLE                              EQU     (WM_USER + 232)

    EM_GETAUTOCORRECTPROC                       EQU     (WM_USER + 233)
    EM_SETAUTOCORRECTPROC                       EQU     (WM_USER + 234)
    EM_CALLAUTOCORRECTPROC                      EQU     (WM_USER + 255)

    ATP_NOCHANGE                                EQU     0
    ATP_CHANGE                                  EQU     1
    ATP_NODELIMITER                             EQU     2
    ATP_REPLACEALLTEXT                          EQU     4

    EM_GETTABLEPARMS                            EQU     (WM_USER + 265)

    EM_SETEDITSTYLEEX                           EQU     (WM_USER + 275)
    EM_GETEDITSTYLEEX                           EQU     (WM_USER + 276)

    SES_EX_NOTABLE                              EQU     00000004H
    SES_EX_HANDLEFRIENDLYURL                    EQU     00000100H
    SES_EX_NOTHEMING                            EQU     00080000H
    SES_EX_NOACETATESELECTION                   EQU     00100000H
    SES_EX_USESINGLELINE                        EQU     00200000H
    SES_EX_MULTITOUCH                           EQU     08000000H
    SES_EX_HIDETEMPFORMAT                       EQU     10000000H
    SES_EX_USEMOUSEWPARAM                       EQU     20000000H

    EM_GETSTORYTYPE                             EQU     (WM_USER + 290)
    EM_SETSTORYTYPE                             EQU     (WM_USER + 291)

    EM_GETELLIPSISMODE                          EQU     (WM_USER + 305)
    EM_SETELLIPSISMODE                          EQU     (WM_USER + 306)

    ELLIPSIS_MASK                               EQU     00000003H
    ELLIPSIS_NONE                               EQU     00000000H
    ELLIPSIS_END                                EQU     00000001H
    ELLIPSIS_WORD                               EQU     00000003H

    EM_SETTABLEPARMS                            EQU     (WM_USER + 307)

    EM_GETTOUCHOPTIONS                          EQU     (WM_USER + 310)
    EM_SETTOUCHOPTIONS                          EQU     (WM_USER + 311)
    EM_INSERTIMAGE                              EQU     (WM_USER + 314)
    EM_SETUIANAME                               EQU     (WM_USER + 320)
    EM_GETELLIPSISSTATE                         EQU     (WM_USER + 322)

    RTO_SHOWHANDLES                             EQU     1
    RTO_DISABLEHANDLES                          EQU     2
    RTO_READINGMODE                             EQU     3
ENDIF

EN_MSGFILTER                                    EQU     0700H
EN_REQUESTRESIZE                                EQU     0701H
EN_SELCHANGE                                    EQU     0702H
EN_DROPFILES                                    EQU     0703H
EN_PROTECTED                                    EQU     0704H
EN_CORRECTTEXT                                  EQU     0705H
EN_STOPNOUNDO                                   EQU     0706H
EN_IMECHANGE                                    EQU     0707H
EN_SAVECLIPBOARD                                EQU     0708H
EN_OLEOPFAILED                                  EQU     0709H
EN_OBJECTPOSITIONS                              EQU     070AH
EN_LINK                                         EQU     070BH
EN_DRAGDROPDONE                                 EQU     070CH
EN_PARAGRAPHEXPANDED                            EQU     070DH
EN_PAGECHANGE                                   EQU     070EH
EN_LOWFIRTF                                     EQU     070FH
EN_ALIGNLTR                                     EQU     0710H
EN_ALIGNRTL                                     EQU     0711H
IF _RICHEDIT_VER GE 0800H
    EN_CLIPFORMAT                               EQU     0712H
    EN_STARTCOMPOSITION                         EQU     0713H
    EN_ENDCOMPOSITION                           EQU     0714H
    ECN_ENDCOMPOSITION                          EQU     0001H
    ECN_NEWTEXT                                 EQU     0002H
ENDIF

ENM_NONE                                        EQU     00000000H
ENM_CHANGE                                      EQU     00000001H
ENM_UPDATE                                      EQU     00000002H
ENM_SCROLL                                      EQU     00000004H
ENM_SCROLLEVENTS                                EQU     00000008H
ENM_DRAGDROPDONE                                EQU     00000010H
ENM_PARAGRAPHEXPANDED                           EQU     00000020H
ENM_PAGECHANGE                                  EQU     00000040H
IF _RICHEDIT_VER GE 0800H
    ENM_CLIPFORMAT                              EQU     00000080H
ENDIF
ENM_KEYEVENTS                                   EQU     00010000H
ENM_MOUSEEVENTS                                 EQU     00020000H
ENM_REQUESTRESIZE                               EQU     00040000H
ENM_SELCHANGE                                   EQU     00080000H
ENM_DROPFILES                                   EQU     00100000H
ENM_PROTECTED                                   EQU     00200000H
ENM_CORRECTTEXT                                 EQU     00400000H
ENM_IMECHANGE                                   EQU     00800000H
ENM_LANGCHANGE                                  EQU     01000000H
ENM_OBJECTPOSITIONS                             EQU     02000000H
ENM_LINK                                        EQU     04000000H
ENM_LOWFIRTF                                    EQU     08000000H
IF _RICHEDIT_VER GE 0800H
    ENM_STARTCOMPOSITION                        EQU     10000000H
    ENM_ENDCOMPOSITION                          EQU     20000000H
    ENM_GROUPTYPINGCHANGE                       EQU     40000000H
    ENM_HIDELINKTOOLTIP                         EQU     80000000H
ENDIF

ES_SAVESEL                                      EQU     00008000H
ES_SUNKEN                                       EQU     00004000H
ES_DISABLENOSCROLL                              EQU     00002000H
ES_SELECTIONBAR                                 EQU     01000000H
ES_NOOLEDRAGDROP                                EQU     00000008H
IF (NTDDI_VERSION GT NTDDI_WIN98_ME)
    ES_EX_NOCALLOLEINIT                         EQU     00000000H
ELSE
    ES_EX_NOCALLOLEINIT                         EQU     01000000H
ENDIF
ES_VERTICAL                                     EQU     00400000H
ES_NOIME                                        EQU     00080000H
ES_SELFIME                                      EQU     00040000H

ECO_AUTOWORDSELECTION                           EQU     00000001H
ECO_AUTOVSCROLL                                 EQU     00000040H
ECO_AUTOHSCROLL                                 EQU     00000080H
ECO_NOHIDESEL                                   EQU     00000100H
ECO_READONLY                                    EQU     00000800H
ECO_WANTRETURN                                  EQU     00001000H
ECO_SAVESEL                                     EQU     00008000H
ECO_SELECTIONBAR                                EQU     01000000H
ECO_VERTICAL                                    EQU     00400000H

ECOOP_SET                                       EQU     0001H
ECOOP_OR                                        EQU     0002H
ECOOP_AND                                       EQU     0003H
ECOOP_XOR                                       EQU     0004H

WB_CLASSIFY                                     EQU     3
WB_MOVEWORDLEFT                                 EQU     4
WB_MOVEWORDRIGHT                                EQU     5
WB_LEFTBREAK                                    EQU     6
WB_RIGHTBREAK                                   EQU     7

WB_MOVEWORDPREV                                 EQU     4
WB_MOVEWORDNEXT                                 EQU     5
WB_PREVBREAK                                    EQU     6
WB_NEXTBREAK                                    EQU     7

PC_FOLLOWING                                    EQU     1
PC_LEADING                                      EQU     2
PC_OVERFLOW                                     EQU     3
PC_DELIMITER                                    EQU     4

WBF_WORDWRAP                                    EQU     0010H
WBF_WORDBREAK                                   EQU     0020H
WBF_OVERFLOW                                    EQU     0040H
WBF_LEVEL1                                      EQU     0080H
WBF_LEVEL2                                      EQU     0100H
WBF_CUSTOM                                      EQU     0200H

IMF_FORCENONE                                   EQU     0001H
IMF_FORCEENABLE                                 EQU     0002H
IMF_FORCEDISABLE                                EQU     0004H
IMF_CLOSESTATUSWINDOW                           EQU     0008H
IMF_VERTICAL                                    EQU     0020H
IMF_FORCEACTIVE                                 EQU     0040H
IMF_FORCEINACTIVE                               EQU     0080H
IMF_FORCEREMEMBER                               EQU     0100H
IMF_MULTIPLEEDIT                                EQU     0400H

WBF_CLASS                                       EQU     0FH
WBF_ISWHITE                                     EQU     10H
WBF_BREAKLINE                                   EQU     20H
WBF_BREAKAFTER                                  EQU     40H

CHARFORMATDELTA                                 EQU     (SizeOf CHARFORMAT2 - SizeOf CHARFORMAT)

CFM_BOLD                                        EQU     00000001H
CFM_ITALIC                                      EQU     00000002H
CFM_UNDERLINE                                   EQU     00000004H
CFM_STRIKEOUT                                   EQU     00000008H
CFM_PROTECTED                                   EQU     00000010H
CFM_LINK                                        EQU     00000020H
CFM_SIZE                                        EQU     80000000H
CFM_COLOR                                       EQU     40000000H
CFM_FACE                                        EQU     20000000H
CFM_OFFSET                                      EQU     10000000H
CFM_CHARSET                                     EQU     08000000H

CFE_BOLD                                        EQU     00000001H
CFE_ITALIC                                      EQU     00000002H
CFE_UNDERLINE                                   EQU     00000004H
CFE_STRIKEOUT                                   EQU     00000008H
CFE_PROTECTED                                   EQU     00000010H
CFE_LINK                                        EQU     00000020H
CFE_AUTOCOLOR                                   EQU     40000000H

CFM_SMALLCAPS                                   EQU     00000040H
CFM_ALLCAPS                                     EQU     00000080H
CFM_HIDDEN                                      EQU     00000100H
CFM_OUTLINE                                     EQU     00000200H
CFM_SHADOW                                      EQU     00000400H
CFM_EMBOSS                                      EQU     00000800H
CFM_IMPRINT                                     EQU     00001000H
CFM_DISABLED                                    EQU     00002000H
CFM_REVISED                                     EQU     00004000H

CFM_REVAUTHOR                                   EQU     00008000H
CFE_SUBSCRIPT                                   EQU     00010000H
CFE_SUPERSCRIPT                                 EQU     00020000H
CFM_ANIMATION                                   EQU     00040000H
CFM_STYLE                                       EQU     00080000H
CFM_KERNING                                     EQU     00100000H
CFM_SPACING                                     EQU     00200000H
CFM_WEIGHT                                      EQU     00400000H
CFM_UNDERLINETYPE                               EQU     00800000H
IF _RICHEDIT_VER GE 0600H
    CFM_COOKIE                                  EQU     01000000H
ENDIF
CFM_LCID                                        EQU     02000000H
CFM_BACKCOLOR                                   EQU     04000000H

CFM_SUBSCRIPT                                   EQU     (CFE_SUBSCRIPT OR CFE_SUPERSCRIPT)
CFM_SUPERSCRIPT                                 EQU     CFM_SUBSCRIPT

CFM_EFFECTS                                     EQU     (CFM_BOLD OR CFM_ITALIC OR CFM_UNDERLINE OR CFM_COLOR OR CFM_STRIKEOUT OR CFE_PROTECTED OR CFM_LINK)
CFM_ALL                                         EQU     (CFM_EFFECTS OR CFM_SIZE OR CFM_FACE OR CFM_OFFSET OR CFM_CHARSET)

CFM_EFFECTS2                                    EQU     (CFM_EFFECTS OR CFM_DISABLED OR CFM_SMALLCAPS OR CFM_ALLCAPS OR CFM_HIDDEN OR CFM_OUTLINE OR CFM_SHADOW OR CFM_EMBOSS OR CFM_IMPRINT OR CFM_REVISED OR CFM_SUBSCRIPT OR CFM_SUPERSCRIPT OR CFM_BACKCOLOR)

IF _RICHEDIT_VER GE 0600H
    CFM_ALL2                                    EQU     (CFM_ALL OR CFM_EFFECTS2 OR CFM_BACKCOLOR OR CFM_LCID OR CFM_UNDERLINETYPE OR CFM_WEIGHT OR CFM_REVAUTHOR OR CFM_SPACING OR CFM_KERNING OR CFM_STYLE OR CFM_ANIMATION OR CFM_COOKIE)
ELSE
    CFM_ALL2                                    EQU     (CFM_ALL OR CFM_EFFECTS2 OR CFM_BACKCOLOR OR CFM_LCID OR CFM_UNDERLINETYPE OR CFM_WEIGHT OR CFM_REVAUTHOR OR CFM_SPACING OR CFM_KERNING OR CFM_STYLE OR CFM_ANIMATION)
ENDIF

CFE_SMALLCAPS                                   EQU     CFM_SMALLCAPS
CFE_ALLCAPS                                     EQU     CFM_ALLCAPS
CFE_HIDDEN                                      EQU     CFM_HIDDEN
CFE_OUTLINE                                     EQU     CFM_OUTLINE
CFE_SHADOW                                      EQU     CFM_SHADOW
CFE_EMBOSS                                      EQU     CFM_EMBOSS
CFE_IMPRINT                                     EQU     CFM_IMPRINT
CFE_DISABLED                                    EQU     CFM_DISABLED
CFE_REVISED                                     EQU     CFM_REVISED

CFE_AUTOBACKCOLOR                               EQU     CFM_BACKCOLOR

CFM_FONTBOUND                                   EQU     00100000H
CFM_LINKPROTECTED                               EQU     00800000H
CFM_EXTENDED                                    EQU     02000000H
CFM_MATHNOBUILDUP                               EQU     08000000H
CFM_MATH                                        EQU     10000000H
CFM_MATHORDINARY                                EQU     20000000H

CFM_ALLEFFECTS                                  EQU     (CFM_EFFECTS2 OR CFM_FONTBOUND OR CFM_EXTENDED OR CFM_MATHNOBUILDUP OR CFM_MATH OR CFM_MATHORDINARY)

CFE_FONTBOUND                                   EQU     00100000H
CFE_LINKPROTECTED                               EQU     00800000H
CFE_EXTENDED                                    EQU     02000000H
CFE_MATHNOBUILDUP                               EQU     08000000H
CFE_MATH                                        EQU     10000000H
CFE_MATHORDINARY                                EQU     20000000H

CFU_CF1UNDERLINE                                EQU     0FFH
CFU_INVERT                                      EQU     0FEH
CFU_UNDERLINETHICKLONGDASH                      EQU     18
CFU_UNDERLINETHICKDOTTED                        EQU     17
CFU_UNDERLINETHICKDASHDOTDOT                    EQU     16
CFU_UNDERLINETHICKDASHDOT                       EQU     15
CFU_UNDERLINETHICKDASH                          EQU     14
CFU_UNDERLINELONGDASH                           EQU     13
CFU_UNDERLINEHEAVYWAVE                          EQU     12
CFU_UNDERLINEDOUBLEWAVE                         EQU     11
CFU_UNDERLINEHAIRLINE                           EQU     10
CFU_UNDERLINETHICK                              EQU     9
CFU_UNDERLINEWAVE                               EQU     8
CFU_UNDERLINEDASHDOTDOT                         EQU     7
CFU_UNDERLINEDASHDOT                            EQU     6
CFU_UNDERLINEDASH                               EQU     5
CFU_UNDERLINEDOTTED                             EQU     4
CFU_UNDERLINEDOUBLE                             EQU     3
CFU_UNDERLINEWORD                               EQU     2
CFU_UNDERLINE                                   EQU     1
CFU_UNDERLINENONE                               EQU     0

yHeightCharPtsMost                              EQU     1638

SCF_SELECTION                                   EQU     0001H
SCF_WORD                                        EQU     0002H
SCF_DEFAULT                                     EQU     0000H
SCF_ALL                                         EQU     0004H
SCF_USEUIRULES                                  EQU     0008H

SCF_ASSOCIATEFONT                               EQU     0010H

SCF_NOKBUPDATE                                  EQU     0020H

SCF_ASSOCIATEFONT2                              EQU     0040H
IF _RICHEDIT_VER GE 0500H
    SCF_SMARTFONT                               EQU     0080H
    SCF_CHARREPFROMLCID                         EQU     0100H

    SPF_DONTSETDEFAULT                          EQU     0002H
    SPF_SETDEFAULT                              EQU     0004H
ENDIF

SF_TEXT                                         EQU     0001H
SF_RTF                                          EQU     0002H
SF_RTFNOOBJS                                    EQU     0003H
SF_TEXTIZED                                     EQU     0004H

SF_UNICODE                                      EQU     0010H
SF_USECODEPAGE                                  EQU     0020H
SF_NCRFORNONASCII                               EQU     0040H
SFF_WRITEXTRAPAR                                EQU     0080H
SFF_SELECTION                                   EQU     8000H
SFF_PLAINRTF                                    EQU     4000H
SFF_PERSISTVIEWSCALE                            EQU     2000H
SFF_KEEPDOCINFO                                 EQU     1000H
SFF_PWD                                         EQU     0800H
SF_RTFVAL                                       EQU     0700H

MAX_TAB_STOPS                                   EQU     32
lDefaultTab                                     EQU     720
MAX_TABLE_CELLS                                 EQU     63

PFM_STARTINDENT                                 EQU     00000001H
PFM_RIGHTINDENT                                 EQU     00000002H
PFM_OFFSET                                      EQU     00000004H
PFM_ALIGNMENT                                   EQU     00000008H
PFM_TABSTOPS                                    EQU     00000010H
PFM_NUMBERING                                   EQU     00000020H
PFM_OFFSETINDENT                                EQU     80000000H

PFM_SPACEBEFORE                                 EQU     00000040H
PFM_SPACEAFTER                                  EQU     00000080H
PFM_LINESPACING                                 EQU     00000100H
PFM_STYLE                                       EQU     00000400H
PFM_BORDER                                      EQU     00000800H
PFM_SHADING                                     EQU     00001000H
PFM_NUMBERINGSTYLE                              EQU     00002000H
PFM_NUMBERINGTAB                                EQU     00004000H
PFM_NUMBERINGSTART                              EQU     00008000H

PFM_RTLPARA                                     EQU     00010000H
PFM_KEEP                                        EQU     00020000H
PFM_KEEPNEXT                                    EQU     00040000H
PFM_PAGEBREAKBEFORE                             EQU     00080000H
PFM_NOLINENUMBER                                EQU     00100000H
PFM_NOWIDOWCONTROL                              EQU     00200000H
PFM_DONOTHYPHEN                                 EQU     00400000H
PFM_SIDEBYSIDE                                  EQU     00800000H

PFM_COLLAPSED                                   EQU     01000000H
PFM_OUTLINELEVEL                                EQU     02000000H
PFM_BOX                                         EQU     04000000H
PFM_RESERVED2                                   EQU     08000000H
PFM_TABLEROWDELIMITER                           EQU     10000000H
PFM_TEXTWRAPPINGBREAK                           EQU     20000000H
PFM_TABLE                                       EQU     40000000H

PFM_ALL                                         EQU     (PFM_STARTINDENT OR PFM_RIGHTINDENT OR PFM_OFFSET OR PFM_ALIGNMENT OR PFM_TABSTOPS OR PFM_NUMBERING OR PFM_OFFSETINDENT OR PFM_RTLPARA)

PFM_EFFECTS                                     EQU     (PFM_RTLPARA OR PFM_KEEP OR PFM_KEEPNEXT OR PFM_TABLE OR PFM_PAGEBREAKBEFORE OR PFM_NOLINENUMBER OR PFM_NOWIDOWCONTROL OR PFM_DONOTHYPHEN OR PFM_SIDEBYSIDE OR PFM_TABLE OR PFM_TABLEROWDELIMITER)

PFM_ALL2                                        EQU     (PFM_ALL OR PFM_EFFECTS OR PFM_SPACEBEFORE OR PFM_SPACEAFTER OR PFM_LINESPACING OR PFM_STYLE OR PFM_SHADING OR PFM_BORDER OR PFM_NUMBERINGTAB OR PFM_NUMBERINGSTART OR PFM_NUMBERINGSTYLE)

PFE_RTLPARA                                     EQU     (PFM_RTLPARA SHR 16)
PFE_KEEP                                        EQU     (PFM_KEEP SHR 16)
PFE_KEEPNEXT                                    EQU     (PFM_KEEPNEXT SHR 16)
PFE_PAGEBREAKBEFORE                             EQU     (PFM_PAGEBREAKBEFORE SHR 16)
PFE_NOLINENUMBER                                EQU     (PFM_NOLINENUMBER SHR 16)
PFE_NOWIDOWCONTROL                              EQU     (PFM_NOWIDOWCONTROL SHR 16)
PFE_DONOTHYPHEN                                 EQU     (PFM_DONOTHYPHEN SHR 16)
PFE_SIDEBYSIDE                                  EQU     (PFM_SIDEBYSIDE SHR 16)

PFE_TEXTWRAPPINGBREAK                           EQU     (PFM_TEXTWRAPPINGBREAK SHR 16)

PFE_COLLAPSED                                   EQU     (PFM_COLLAPSED SHR 16)
PFE_BOX                                         EQU     (PFM_BOX SHR 16)
PFE_TABLE                                       EQU     (PFM_TABLE SHR 16)
PFE_TABLEROWDELIMITER                           EQU     (PFM_TABLEROWDELIMITER SHR 16)

PFN_BULLET                                      EQU     1

PFN_ARABIC                                      EQU     2
PFN_LCLETTER                                    EQU     3
PFN_UCLETTER                                    EQU     4
PFN_LCROMAN                                     EQU     5
PFN_UCROMAN                                     EQU     6

PFNS_PAREN                                      EQU     000H
PFNS_PARENS                                     EQU     100H
PFNS_PERIOD                                     EQU     200H
PFNS_PLAIN                                      EQU     300H
PFNS_NONUMBER                                   EQU     400H

PFNS_NEWNUMBER                                  EQU     8000H

PFA_LEFT                                        EQU     1
PFA_RIGHT                                       EQU     2
PFA_CENTER                                      EQU     3

PFA_JUSTIFY                                     EQU     4
PFA_FULL_INTERWORD                              EQU     4

IFNDEF WM_NOTIFY
    WM_NOTIFY                                   EQU     004EH
ENDIF

SEL_EMPTY                                       EQU     0000H
SEL_TEXT                                        EQU     0001H
SEL_OBJECT                                      EQU     0002H
SEL_MULTICHAR                                   EQU     0004H
SEL_MULTIOBJECT                                 EQU     0008H

GCM_RIGHTMOUSEDROP                              EQU     8000H

IF _RICHEDIT_VER GE 0800H
    GCMF_GRIPPER                                EQU     00000001H
    GCMF_SPELLING                               EQU     00000002H
    GCMF_TOUCHMENU                              EQU     00004000H
    GCMF_MOUSEMENU                              EQU     00002000H
ENDIF

OLEOP_DOVERB                                    EQU     1

ST_DEFAULT                                      EQU     0
ST_KEEPUNDO                                     EQU     1
ST_SELECTION                                    EQU     2
ST_NEWCHARS                                     EQU     4
IF _RICHEDIT_VER GE 0500H
    ST_UNICODE                                  EQU     8
ENDIF

GT_DEFAULT                                      EQU     0
GT_USECRLF                                      EQU     1
GT_SELECTION                                    EQU     2
GT_RAWTEXT                                      EQU     4
GT_NOHIDDENTEXT                                 EQU     8

GTL_DEFAULT                                     EQU     0
GTL_USECRLF                                     EQU     1
GTL_PRECISE                                     EQU     2
GTL_CLOSE                                       EQU     4
GTL_NUMCHARS                                    EQU     8
GTL_NUMBYTES                                    EQU     16


IF _RICHEDIT_VER EQ 0100H
    BOM_DEFPARADIR                              EQU     0001H
    BOM_PLAINTEXT                               EQU     0002H
ENDIF
BOM_NEUTRALOVERRIDE                             EQU     0004H
BOM_CONTEXTREADING                              EQU     0008H
BOM_CONTEXTALIGNMENT                            EQU     0010H
BOM_LEGACYBIDICLASS                             EQU     0040H
IF _RICHEDIT_VER GE 0600H
    BOM_UNICODEBIDI                             EQU     0080H
ENDIF

IF _RICHEDIT_VER EQ 0100H
    BOE_RTLDIR                                  EQU     0001H
    BOE_PLAINTEXT                               EQU     0002H
ENDIF
BOE_NEUTRALOVERRIDE                             EQU     0004H
BOE_CONTEXTREADING                              EQU     0008H
BOE_CONTEXTALIGNMENT                            EQU     0010H
IF _RICHEDIT_VER GE 0800H
    BOE_FORCERECALC                             EQU     0020H
ENDIF
BOE_LEGACYBIDICLASS                             EQU     0040H
IF _RICHEDIT_VER GE 0600H
    BOE_UNICODEBIDI                             EQU     0080H
ENDIF

FR_MATCHDIAC                                    EQU     20000000H
FR_MATCHKASHIDA                                 EQU     40000000H
FR_MATCHALEFHAMZA                               EQU     80000000H

IFNDEF WCH_EMBEDDING
    WCH_EMBEDDING                               EQU     0FFFCH
ENDIF

IF _RICHEDIT_VER GE 0600H
    IFNDEF RICHEDIT60_CLASS
        RICHEDIT60_CLASS                        EQU     L("RICHEDIT60W")
    ENDIF
ENDIF

PFA_FULL_NEWSPAPER                              EQU     5
PFA_FULL_INTERLETTER                            EQU     6
PFA_FULL_SCALED                                 EQU     7
PFA_FULL_GLYPHS                                 EQU     8

AURL_ENABLEEA                                   EQU     1

GCM_TOUCHMENU                                   EQU     4000H
GCM_MOUSEMENU                                   EQU     2000H

TM_PLAINTEXT                                    EQU     1
TM_RICHTEXT                                     EQU     2
TM_SINGLELEVELUNDO                              EQU     4
TM_MULTILEVELUNDO                               EQU     8
TM_SINGLECODEPAGE                               EQU     16
TM_MULTICODEPAGE                                EQU     32

UID_UNKNOWN                                     EQU     0
UID_TYPING                                      EQU     1
UID_DELETE                                      EQU     2
UID_DRAGDROP                                    EQU     3
UID_CUT                                         EQU     4
UID_PASTE                                       EQU     5
UID_AUTOTABLE                                   EQU     6

khyphNil                                        EQU     0
khyphNormal                                     EQU     1
khyphAddBefore                                  EQU     2
khyphChangeBefore                               EQU     3
khyphDeleteBefore                               EQU     4
khyphChangeAfter                                EQU     5
khyphDelAndChange                               EQU     6

;======================================== Structures ======================================;

CHARFORMATA STRUCT ALIGNMODE
    cbSize          DD       ?
    dwMask          DD       ?
    dwEffects       DD       ?
    yHeight         DD       ?
    yOffset         DD       ?
    crTextColor     DD       ?
    bCharSet        DB       ?
    bPitchAndFamily DB       ?
    szFaceName      DB       LF_FACESIZE DUP(?)
CHARFORMATA ENDS

CHARFORMATW STRUCT ALIGNMODE
    cbSize          DD       ?
    dwMask          DD       ?
    dwEffects       DD       ?
    yHeight         DD       ?
    yOffset         DD       ?
    crTextColor     DD       ?
    bCharSet        DB       ?
    bPitchAndFamily DB       ?
    szFaceName      DW       LF_FACESIZE DUP(?)
CHARFORMATW ENDS

CHARFORMAT2A STRUCT ALIGNMODE
    cbSize          DD       ?
    dwMask          DD       ?
    dwEffects       DD       ?
    yHeight         DD       ?
    yOffset         DD       ?
    crTextColor     DD       ?
    bCharSet        DB       ?
    bPitchAndFamily DB       ?
    szFaceName      DB       LF_FACESIZE DUP(?)
    wWeight         DW       ?
    sSpacing        DW       ?
    crBackColor     DD       ?
    lcid            DD       ?
    dwReserved      DD       ?
    sStyle          DW       ?
    wKerning        DW       ?
    bUnderlineType  DB       ?
    bAnimation      DB       ?
    bRevAuthor      DB       ?
    bUnderlineColor DB       ?
CHARFORMAT2A ENDS

CHARFORMAT2W STRUCT ALIGNMODE
    cbSize          DD       ?
    dwMask          DD       ?
    dwEffects       DD       ?
    yHeight         DD       ?
    yOffset         DD       ?
    crTextColor     DD       ?
    bCharSet        DB       ?
    bPitchAndFamily DB       ?
    szFaceName      DW       LF_FACESIZE DUP(?)
    wWeight         DW       ?
    sSpacing        DW       ?
    crBackColor     DD       ?
    lcid            DD       ?
    dwReserved      DD       ?
    sStyle          DW       ?
    wKerning        DW       ?
    bUnderlineType  DB       ?
    bAnimation      DB       ?
    bRevAuthor      DB       ?
    bUnderlineColor DB       ?
CHARFORMAT2W ENDS

CHARRANGE STRUCT ALIGNMODE
    cpMin DD ?
    cpMax DD ?
CHARRANGE ENDS

COMPCOLOR STRUCT ALIGNMODE
    crText       DD ?
    crBackground DD ?
    dwEffects    DD ?
COMPCOLOR ENDS

TEXTRANGEA STRUCT ALIGNMODE
    chrg      CHARRANGE <>
    lpstrText XPTR      ?
TEXTRANGEA ENDS

TEXTRANGEW STRUCT ALIGNMODE
    chrg      CHARRANGE <>
    lpstrText XPTR      ?
TEXTRANGEW ENDS

EDITSTREAM STRUCT ALIGNMODE
    dwCookie    DD   ?
    dwError     DD   ?
    pfnCallback XPTR ?
EDITSTREAM ENDS

FINDTEXTA STRUCT ALIGNMODE
    chrg      CHARRANGE <>
    lpstrText XPTR ?
FINDTEXTA ENDS

FINDTEXTW STRUCT ALIGNMODE
    chrg      CHARRANGE <>
    lpstrText XPTR ?
FINDTEXTW ENDS

FINDTEXTEXA STRUCT ALIGNMODE
    chrg      CHARRANGE <>
    lpstrText XPTR ?
    chrgText  CHARRANGE <>
FINDTEXTEXA ENDS

FINDTEXTEXW STRUCT ALIGNMODE
    chrg      CHARRANGE <>
    lpstrText XPTR ?
    chrgText  CHARRANGE <>
FINDTEXTEXW ENDS

FORMATRANGE STRUCT ALIGNMODE
    hdc       HDC       ?
    hdcTarget HDC       ?
    rc        RECT      <>
    rcPage    RECT      <>
    chrg      CHARRANGE <>
FORMATRANGE ENDS

HYPHENATEINFO STRUCT ALIGNMODE
    cbSize          DW   ?
    dxHyphenateZone DW   ?
    pfnHyphenate    XPTR ?
HYPHENATEINFO ENDS

PARAFORMAT STRUCT ALIGNMODE
    cbSize        DD ?
    dwMask        DD ?
    wNumbering    DW ?
    wReserved     DW ?
    dxStartIndent DD ?
    dxRightIndent DD ?
    dxOffset      DD ?
    wAlignment    DW ?
    cTabCount     DW ?
    rgxTabs       DD MAX_TAB_STOPS DUP(?)
PARAFORMAT ENDS

PARAFORMAT2 STRUCT ALIGNMODE
    cbSize           DD ?
    dwMask           DD ?
    wNumbering       DW ?
    wEffects         DW ?
    dxStartIndent    DD ?
    dxRightIndent    DD ?
    dxOffset         DD ?
    wAlignment       DW ?
    cTabCount        DW ?
    rgxTabs          DD MAX_TAB_STOPS DUP(?)
    dySpaceBefore    DD ?
    dySpaceAfter     DD ?
    dyLineSpacing    DD ?
    sStyle           DW ?
    bLineSpacingRule DB ?
    bOutlineLevel    DB ?
    wShadingWeight   DW ?
    wShadingStyle    DW ?
    wNumberingStart  DW ?
    wNumberingStyle  DW ?
    wNumberingTab    DW ?
    wBorderSpace     DW ?
    wBorderWidth     DW ?
    wBorders         DW ?
PARAFORMAT2 ENDS

IMECOMPTEXT STRUCT ALIGNMODE
    cb    DD ?
    flags DD ?
IMECOMPTEXT ENDS

IF _RICHEDIT_VER GE 0800H
    RECA_TABLEROWPARMS RECORD   nAlignment:3, fRTL:1, fKeep:1, fKeepFollow:1, fWrap:1, fIdentCells:1
    TABLEROWPARMS STRUCT ALIGNMODE
        cbRow              DB ?
        cbCell             DB ?
        cCell              DB ?
        cRow               DB ?
        dxCellMargin       DD ?
        dxIndent           DD ?
        dyHeight           DD ?
        RECA_TABLEROWPARMS <>
        cpStartRow         DD ?
        bTableLevel        DB ?
        iCell              DB ?
    TABLEROWPARMS ENDS

    RECA_TABLECELLPARMS RECORD  nVertAlign:2, fMergeTop:1, fMergePrev:1, fVertical:1, fMergeStart:1, fMergeCont:1
    TABLECELLPARMS STRUCT ALIGNMODE
        dxWidth          DD ?
        RECA_TABLECELLPARMS <>
        wShading         DW ?
        dxBrdrLeft       DW ?
        dyBrdrTop        DW ?
        dxBrdrRight      DW ?
        dyBrdrBottom     DW ?
        crBrdrLeft       DD ?
        crBrdrTop        DD ?
        crBrdrRight      DD ?
        crBrdrBottom     DD ?
        crBackPat        DD ?
        crForePat        DD ?
    TABLECELLPARMS ENDS

    RICHEDIT_IMAGE_PARAMETERS STRUCT ALIGNMODE
        xWidth            DD ?
        xHeight           DD ?
        Ascent            DD ?
        _Type             DD ?
        pwszAlternateText LPCWSTR ?
        pIStream          XPTR    ?
    RICHEDIT_IMAGE_PARAMETERS ENDS

    ENDCOMPOSITIONNOTIFY STRUCT ALIGNMODE
        nmhdr  NMHDR <>
        dwCode DD    ?
    ENDCOMPOSITIONNOTIFY ENDS
ENDIF

MSGFILTER STRUCT ALIGNMODE
    nmhdr   NMHDR  <>
    msg     DD     ?
    wParam  WPARAM ?
    lParam  LPARAM ?
MSGFILTER ENDS

REQRESIZE STRUCT ALIGNMODE
    nmhdr NMHDR <>
    rc    RECT  <>
REQRESIZE ENDS

SELCHANGE STRUCT ALIGNMODE
    nmhdr  NMHDR     <>
    chrg   CHARRANGE <>
    seltyp DW        ?
SELCHANGE ENDS

ENDROPFILES STRUCT ALIGNMODE
    nmhdr       NMHDR  <>
    hDrop       HANDLE ?
    cp          DD     ?
    fProtected  DD     ?
ENDROPFILES ENDS

ENPROTECTED STRUCT ALIGNMODE
    nmhdr   NMHDR     <>
    msg     DD        ?
    wParam  WPARAM    ?
    lParam  LPARAM    ?
    chrg    CHARRANGE <>
ENPROTECTED ENDS

ENSAVECLIPBOARD STRUCT ALIGNMODE
    nmhdr        NMHDR <>
    cObjectCount DD    ?
    cch          DD    ?
ENSAVECLIPBOARD ENDS

ENOLEOPFAILED STRUCT ALIGNMODE
    nmhdr NMHDR <>
    iob   DD    ?
    lOper DD    ?
    hr    DD    ?
ENOLEOPFAILED ENDS

OBJECTPOSITIONS STRUCT ALIGNMODE
    nmhdr        NMHDR <>
    cObjectCount DD    ?
    pcpPositions XPTR  ?
OBJECTPOSITIONS ENDS

ENLINK STRUCT ALIGNMODE
    nmhdr  NMHDR     <>
    msg    DD        ?
    wParam WPARAM    ?
    lParam LPARAM    ?
    chrg   CHARRANGE <>
ENLINK ENDS

ENCORRECTTEXT STRUCT ALIGNMODE
    nmhdr  NMHDR     <>
    chrg   CHARRANGE <>
    seltyp DW        ?
ENCORRECTTEXT ENDS

PUNCTUATION STRUCT ALIGNMODE
    iSize         DD   ?
    szPunctuation XPTR ?
PUNCTUATION ENDS

REPASTESPECIAL STRUCT ALIGNMODE
    dwAspect DD ?
    IF (NTDDI_VERSION GE NTDDI_WIN2K)
        dwParam DQ ?
    ELSE
        dwParam DD ?
    ENDIF
REPASTESPECIAL ENDS

SETTEXTEX STRUCT ALIGNMODE
    flags    DD ?
    codepage DD ?
SETTEXTEX ENDS

GETTEXTEX STRUCT ALIGNMODE
    cb            DD ?
    flags         DD ?
    codepage      DD ?
    lpDefaultChar XPTR ?
    lpUsedDefChar XPTR ?
GETTEXTEX ENDS

GETTEXTLENGTHEX STRUCT ALIGNMODE
    flags    DD ?
    codepage DD ?
GETTEXTLENGTHEX ENDS

BIDIOPTIONS STRUCT ALIGNMODE
    cbSize   DD ?
    wMask    DW ?
    wEffects DW ?
BIDIOPTIONS ENDS

CLIPBOARDFORMAT STRUCT ALIGNMODE
    nmhdr NMHDR <>
    cf    DW    ?
CLIPBOARDFORMAT ENDS

ENLOWFIRTF STRUCT ALIGNMODE
    nmhdr     NMHDR <>
    szControl XPTR  ?
ENLOWFIRTF ENDS

HYPHRESULT STRUCT ALIGNMODE
    khyph   DD    ?
    ichHyph XWORD ?
    chHyph  DW    ?
HYPHRESULT ENDS

IF _RICHEDIT_VER GE 0800H
    GROUPTYPINGCHANGE STRUCT ALIGNMODE
        nmhdr        NMHDR <>
        fGroupTyping DD    ?
    GROUPTYPINGCHANGE ENDS

    GETCONTEXTMENUEX STRUCT ALIGNMODE
        chrg       CHARRANGE <>
        dwFlags    DD        ?
        pt         POINT     <>
        pvReserved XPTR      ?
    GETCONTEXTMENUEX ENDS
ENDIF

IFDEF APP_UNICODE
    RICHEDIT_CLASS EQU <RICHEDIT_CLASSW>
    CHARFORMAT EQU <CHARFORMATW>
    CHARFORMAT2 EQU <CHARFORMAT2W>
    TEXTRANGE EQU <TEXTRANGEW>
    FINDTEXT EQU <FINDTEXTW>
    FINDTEXTEX EQU <FINDTEXTEXW>
ELSE
    RICHEDIT_CLASS EQU <RICHEDIT_CLASSA>
    CHARFORMAT EQU <CHARFORMATA>
    CHARFORMAT2 EQU <CHARFORMAT2A>
    TEXTRANGE EQU <TEXTRANGEA>
    FINDTEXT EQU <FINDTEXTA>
    FINDTEXTEX EQU <FINDTEXTEXA>
ENDIF

ENDIF ;RICHEDIT_INC
