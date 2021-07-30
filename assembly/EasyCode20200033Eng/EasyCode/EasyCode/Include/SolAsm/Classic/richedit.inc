; ====================================================;
;                                                     ;
;    richedit.inc for EC v2 SolAsm classic projects   ;
;                   (version 1.0.2)                   ;
;                                                     ;
;         Copyright © Ramon Sala - 2018-2019          ;
;                                                     ;
; ====================================================;

#ifndef RICHEDIT_INC
RICHEDIT_INC equ 1

#ifndef _RICHEDIT_VER
    _RICHEDIT_VER                               equ     0800H
#endif

cchTextLimitDefault                             equ     32767

#ifndef WM_CONTEXTMENU
    WM_CONTEXTMENU                              equ     007BH
#endif

#ifndef WM_UNICHAR
    WM_UNICHAR                                  equ     0109H
#endif

#ifndef WM_PRINTCLIENT
    WM_PRINTCLIENT                              equ     0318H
#endif

#ifndef EM_GETLIMITTEXT
    EM_GETLIMITTEXT                             equ     (WM_USER+37)
#endif

#ifndef EM_POSFROMCHAR
    EM_POSFROMCHAR                              equ     (WM_USER+38)
    EM_CHARFROMPOS                              equ     (WM_USER+39)
#endif

#ifndef EM_SCROLLCARET
    EM_SCROLLCARET                              equ     (WM_USER+49)
#endif

EM_CANPASTE                                     equ     (WM_USER+50)
EM_DISPLAYBAND                                  equ     (WM_USER+51)
EM_EXGETSEL                                     equ     (WM_USER+52)
EM_EXLIMITTEXT                                  equ     (WM_USER+53)
EM_EXLINEFROMCHAR                               equ     (WM_USER+54)
EM_EXSETSEL                                     equ     (WM_USER+55)
EM_FINDTEXT                                     equ     (WM_USER+56)
EM_FORMATRANGE                                  equ     (WM_USER+57)
EM_GETCHARFORMAT                                equ     (WM_USER+58)
EM_GETEVENTMASK                                 equ     (WM_USER+59)
EM_GETOLEINTERFACE                              equ     (WM_USER+60)
EM_GETPARAFORMAT                                equ     (WM_USER+61)
EM_GETSELTEXT                                   equ     (WM_USER+62)
EM_HIDESELECTION                                equ     (WM_USER+63)
EM_PASTESPECIAL                                 equ     (WM_USER+64)
EM_REQUESTRESIZE                                equ     (WM_USER+65)
EM_SELECTIONTYPE                                equ     (WM_USER+66)
EM_SETBKGNDCOLOR                                equ     (WM_USER+67)
EM_SETCHARFORMAT                                equ     (WM_USER+68)
EM_SETEVENTMASK                                 equ     (WM_USER+69)
EM_SETOLECALLBACK                               equ     (WM_USER+70)
EM_SETPARAFORMAT                                equ     (WM_USER+71)
EM_SETTARGETDEVICE                              equ     (WM_USER+72)
EM_STREAMIN                                     equ     (WM_USER+73)
EM_STREAMOUT                                    equ     (WM_USER+74)
EM_GETTEXTRANGE                                 equ     (WM_USER+75)
EM_FINDWORDBREAK                                equ     (WM_USER+76)
EM_SETOPTIONS                                   equ     (WM_USER+77)
EM_GETOPTIONS                                   equ     (WM_USER+78)
EM_FINDTEXTEX                                   equ     (WM_USER+79)
EM_GETWORDBREAKPROCEX                           equ     (WM_USER+80)
EM_SETWORDBREAKPROCEX                           equ     (WM_USER+81)
EM_SETUNDOLIMIT                                 equ     (WM_USER+82)
EM_REDO                                         equ     (WM_USER+84)
EM_CANREDO                                      equ     (WM_USER+85)
EM_GETUNDONAME                                  equ     (WM_USER+86)
EM_GETREDONAME                                  equ     (WM_USER+87)
EM_STOPGROUPTYPING                              equ     (WM_USER+88)
EM_SETTEXTMODE                                  equ     (WM_USER+89)
EM_GETTEXTMODE                                  equ     (WM_USER+90)
EM_AUTOURLDETECT                                equ     (WM_USER+91)
EM_GETAUTOURLDETECT                             equ     (WM_USER+92)
EM_SETPALETTE                                   equ     (WM_USER+93)
EM_GETTEXTEX                                    equ     (WM_USER+94)
EM_GETTEXTLENGTHEX                              equ     (WM_USER+95)
EM_SHOWSCROLLBAR                                equ     (WM_USER+96)
EM_SETTEXTEX                                    equ     (WM_USER+97)
EM_SETPUNCTUATION                               equ     (WM_USER+100)
EM_GETPUNCTUATION                               equ     (WM_USER+101)
EM_SETWORDWRAPMODE                              equ     (WM_USER+102)
EM_GETWORDWRAPMODE                              equ     (WM_USER+103)
EM_SETIMECOLOR                                  equ     (WM_USER+104)
EM_GETIMECOLOR                                  equ     (WM_USER+105)
EM_SETIMEOPTIONS                                equ     (WM_USER+106)
EM_GETIMEOPTIONS                                equ     (WM_USER+107)
EM_CONVPOSITION                                 equ     (WM_USER+108)
EM_SETLANGOPTIONS                               equ     (WM_USER+120)
EM_GETLANGOPTIONS                               equ     (WM_USER+121)
EM_GETIMECOMPMODE                               equ     (WM_USER+122)
EM_FINDTEXTW                                    equ     (WM_USER+123)
EM_FINDTEXTEXW                                  equ     (WM_USER+124)
EM_RECONVERSION                                 equ     (WM_USER+125)
EM_SETIMEMODEBIAS                               equ     (WM_USER+126)
EM_GETIMEMODEBIAS                               equ     (WM_USER+127)
EM_SETBIDIOPTIONS                               equ     (WM_USER+200)
EM_GETBIDIOPTIONS                               equ     (WM_USER+201)
EM_SETTYPOGRAPHYOPTIONS                         equ     (WM_USER+202)
EM_GETTYPOGRAPHYOPTIONS                         equ     (WM_USER+203)
EM_SETEDITSTYLE                                 equ     (WM_USER+204)
EM_GETEDITSTYLE                                 equ     (WM_USER+205)
EM_OUTLINE                                      equ     (WM_USER+220)
EM_GETSCROLLPOS                                 equ     (WM_USER+221)
EM_SETSCROLLPOS                                 equ     (WM_USER+222)
EM_SETFONTSIZE                                  equ     (WM_USER+223)
EM_GETZOOM                                      equ     (WM_USER+224)
EM_SETZOOM                                      equ     (WM_USER+225)
EM_GETVIEWKIND                                  equ     (WM_USER+226)
EM_SETVIEWKIND                                  equ     (WM_USER+227)

#if _RICHEDIT_VER >= 0800H
    AURL_ENABLEURL                              equ     1
    AURL_ENABLEEMAILADDR                        equ     2
    AURL_ENABLETELNO                            equ     4
    AURL_ENABLEEAURLS                           equ     8
    AURL_ENABLEDRIVELETTERS                     equ     16
    AURL_DISABLEMIXEDLGC                        equ     32
#endif

SES_EMULATESYSEDIT                              equ     1
SES_BEEPONMAXTEXT                               equ     2
SES_EXTENDBACKCOLOR                             equ     4
SES_MAPCPS                                      equ     8
#if _RICHEDIT_VER >= 0500H
    SES_HYPERLINKTOOLTIPS                       equ     8
#endif
SES_EMULATE10                                   equ     16
#if _RICHEDIT_VER >= 0700H
    SES_DEFAULTLATINLIGA                        equ     16
#endif
SES_USECRLF                                     equ     32
SES_USEAIMM                                     equ     64
SES_NOIME                                       equ     128

SES_ALLOWBEEPS                                  equ     256
SES_UPPERCASE                                   equ     512
SES_LOWERCASE                                   equ     1024
SES_NOINPUTSEQUENCECHK                          equ     2048
SES_BIDI                                        equ     4096
SES_SCROLLONKILLFOCUS                           equ     8192
SES_XLTCRCRLFTOCR                               equ     16384
SES_DRAFTMODE                                   equ     32768

SES_USECTF                                      equ     00010000H
SES_HIDEGRIDLINES                               equ     00020000H
SES_USEATFONT                                   equ     00040000H
SES_CUSTOMLOOK                                  equ     00080000H
SES_LBSCROLLNOTIFY                              equ     00100000H
SES_CTFALLOWEMBED                               equ     00200000H
SES_CTFALLOWSMARTTAG                            equ     00400000H
SES_CTFALLOWPROOFING                            equ     00800000H
#if _RICHEDIT_VER >= 0500H
    SES_LOGICALCARET                            equ     01000000H
    SES_WORDDRAGDROP                            equ     02000000H
    SES_SMARTDRAGDROP                           equ     04000000H
    SES_MULTISELECT                             equ     08000000H
    SES_CTFNOLOCK                               equ     10000000H
    SES_NOEALINEHEIGHTADJUST                    equ     20000000H
    SES_MAX                                     equ     20000000H
#endif

IMF_AUTOKEYBOARD                                equ     0001H
IMF_AUTOFONT                                    equ     0002H
IMF_IMECANCELCOMPLETE                           equ     0004H
IMF_IMEALWAYSSENDNOTIFY                         equ     0008H
IMF_AUTOFONTSIZEADJUST                          equ     0010H
IMF_UIFONTS                                     equ     0020H
#if _RICHEDIT_VER >= 0800H
    IMF_NOIMPLICITLANG                          equ     0040H
#endif
IMF_DUALFONT                                    equ     0080H
#if _RICHEDIT_VER >= 0800H
    IMF_NOKBDLIDFIXUP                           equ     0200H
#endif
IMF_NORTFFONTSUBSTITUTE                         equ     0400H
#if _RICHEDIT_VER >= 0800H
    IMF_SPELLCHECKING                           equ     0800H
    IMF_TKBPREDICTION                           equ     1000H
#endif

ICM_NOTOPEN                                     equ     0000H
ICM_LEVEL3                                      equ     0001H
ICM_LEVEL2                                      equ     0002H
ICM_LEVEL2_5                                    equ     0003H
ICM_LEVEL2_SUI                                  equ     0004H
ICM_CTF                                         equ     0005H

TO_ADVANCEDTYPOGRAPHY                           equ     0001H
TO_SIMPLELINEBREAK                              equ     0002H
TO_DISABLECUSTOMTEXTOUT                         equ     0004H
TO_ADVANCEDLAYOUT                               equ     0008H

EM_GETPAGE                                      equ     (WM_USER+228)
EM_SETPAGE                                      equ     (WM_USER+229)
EM_GETHYPHENATEINFO                             equ     (WM_USER+230)
EM_SETHYPHENATEINFO                             equ     (WM_USER+231)

EM_GETPAGEROTATE                                equ     (WM_USER+235)
EM_SETPAGEROTATE                                equ     (WM_USER+236)
EM_GETCTFMODEBIAS                               equ     (WM_USER+237)
EM_SETCTFMODEBIAS                               equ     (WM_USER+238)
EM_GETCTFOPENSTATUS                             equ     (WM_USER+240)
EM_SETCTFOPENSTATUS                             equ     (WM_USER+241)
EM_GETIMECOMPTEXT                               equ     (WM_USER+242)
EM_ISIME                                        equ     (WM_USER+243)
EM_GETIMEPROPERTY                               equ     (WM_USER+244)

EM_GETQUERYRTFOBJ                               equ     (WM_USER+269)
EM_SETQUERYRTFOBJ                               equ     (WM_USER+270)

EPR_0                                           equ     0
EPR_270                                         equ     1
EPR_180                                         equ     2
EPR_90                                          equ     3
#if _RICHEDIT_VER >= 0800H
    EPR_SE                                      equ     5
#endif

CTFMODEBIAS_DEFAULT                             equ     0000H
CTFMODEBIAS_FILENAME                            equ     0001H
CTFMODEBIAS_NAME                                equ     0002H
CTFMODEBIAS_READING                             equ     0003H
CTFMODEBIAS_DATETIME                            equ     0004H
CTFMODEBIAS_CONVERSATION                        equ     0005H
CTFMODEBIAS_NUMERIC                             equ     0006H
CTFMODEBIAS_HIRAGANA                            equ     0007H
CTFMODEBIAS_KATAKANA                            equ     0008H
CTFMODEBIAS_HANGUL                              equ     0009H
CTFMODEBIAS_HALFWIDTHKATAKANA                   equ     000aH
CTFMODEBIAS_FULLWIDTHALPHANUMERIC               equ     000bH
CTFMODEBIAS_HALFWIDTHALPHANUMERIC               equ     000cH

IMF_SMODE_PLAURALCLAUSE                         equ     0001H
IMF_SMODE_NONE                                  equ     0002H

ICT_RESULTREADSTR                               equ     1

EMO_EXIT                                        equ     0
EMO_ENTER                                       equ     1
EMO_PROMOTE                                     equ     2
EMO_EXPAND                                      equ     3
EMO_MOVESELECTION                               equ     4
EMO_GETVIEWMODE                                 equ     5

EMO_EXPANDSELECTION                             equ     0
EMO_EXPANDDOCUMENT                              equ     1

VM_NORMAL                                       equ     4
VM_OUTLINE                                      equ     2
VM_PAGE                                         equ     9

#if _RICHEDIT_VER >= 0800H
    EM_INSERTTABLE                              equ     (WM_USER+232)

    EM_GETAUTOCORRECTPROC                       equ     (WM_USER+233)
    EM_SETAUTOCORRECTPROC                       equ     (WM_USER+234)
    EM_CALLAUTOCORRECTPROC                      equ     (WM_USER+255)

    ATP_NOCHANGE                                equ     0
    ATP_CHANGE                                  equ     1
    ATP_NODELIMITER                             equ     2
    ATP_REPLACEALLTEXT                          equ     4

    EM_GETTABLEPARMS                            equ     (WM_USER+265)

    EM_SETEDITSTYLEEX                           equ     (WM_USER+275)
    EM_GETEDITSTYLEEX                           equ     (WM_USER+276)

    SES_EX_NOTABLE                              equ     00000004H
    SES_EX_HANDLEFRIENDLYURL                    equ     00000100H
    SES_EX_NOTHEMING                            equ     00080000H
    SES_EX_NOACETATESELECTION                   equ     00100000H
    SES_EX_USESINGLELINE                        equ     00200000H
    SES_EX_MULTITOUCH                           equ     08000000H
    SES_EX_HIDETEMPFORMAT                       equ     10000000H
    SES_EX_USEMOUSEWPARAM                       equ     20000000H

    EM_GETSTORYTYPE                             equ     (WM_USER+290)
    EM_SETSTORYTYPE                             equ     (WM_USER+291)

    EM_GETELLIPSISMODE                          equ     (WM_USER+305)
    EM_SETELLIPSISMODE                          equ     (WM_USER+306)

    ELLIPSIS_MASK                               equ     00000003H
    ELLIPSIS_NONE                               equ     00000000H
    ELLIPSIS_END                                equ     00000001H
    ELLIPSIS_WORD                               equ     00000003H

    EM_SETTABLEPARMS                            equ     (WM_USER+307)

    EM_GETTOUCHOPTIONS                          equ     (WM_USER+310)
    EM_SETTOUCHOPTIONS                          equ     (WM_USER+311)
    EM_INSERTIMAGE                              equ     (WM_USER+314)
    EM_SETUIANAME                               equ     (WM_USER+320)
    EM_GETELLIPSISSTATE                         equ     (WM_USER+322)

    RTO_SHOWHANDLES                             equ     1
    RTO_DISABLEHANDLES                          equ     2
    RTO_READINGMODE                             equ     3
#endif

EN_MSGFILTER                                    equ     0700H
EN_REQUESTRESIZE                                equ     0701H
EN_SELCHANGE                                    equ     0702H
EN_DROPFILES                                    equ     0703H
EN_PROTECTED                                    equ     0704H
EN_CORRECTTEXT                                  equ     0705H
EN_STOPNOUNDO                                   equ     0706H
EN_IMECHANGE                                    equ     0707H
EN_SAVECLIPBOARD                                equ     0708H
EN_OLEOPFAILED                                  equ     0709H
EN_OBJECTPOSITIONS                              equ     070AH
EN_LINK                                         equ     070BH
EN_DRAGDROPDONE                                 equ     070CH
EN_PARAGRAPHEXPANDED                            equ     070DH
EN_PAGECHANGE                                   equ     070EH
EN_LOWFIRTF                                     equ     070FH
EN_ALIGNLTR                                     equ     0710H
EN_ALIGNRTL                                     equ     0711H
#if _RICHEDIT_VER >= 0800H
    EN_CLIPFORMAT                               equ     0712H
    EN_STARTCOMPOSITION                         equ     0713H
    EN_ENDCOMPOSITION                           equ     0714H
    ECN_ENDCOMPOSITION                          equ     0001H
    ECN_NEWTEXT                                 equ     0002H
#endif

ENM_NONE                                        equ     00000000H
ENM_CHANGE                                      equ     00000001H
ENM_UPDATE                                      equ     00000002H
ENM_SCROLL                                      equ     00000004H
ENM_SCROLLEVENTS                                equ     00000008H
ENM_DRAGDROPDONE                                equ     00000010H
ENM_PARAGRAPHEXPANDED                           equ     00000020H
ENM_PAGECHANGE                                  equ     00000040H
#if _RICHEDIT_VER >= 0800H
    ENM_CLIPFORMAT                              equ     00000080H
#endif
ENM_KEYEVENTS                                   equ     00010000H
ENM_MOUSEEVENTS                                 equ     00020000H
ENM_REQUESTRESIZE                               equ     00040000H
ENM_SELCHANGE                                   equ     00080000H
ENM_DROPFILES                                   equ     00100000H
ENM_PROTECTED                                   equ     00200000H
ENM_CORRECTTEXT                                 equ     00400000H
ENM_IMECHANGE                                   equ     00800000H
ENM_LANGCHANGE                                  equ     01000000H
ENM_OBJECTPOSITIONS                             equ     02000000H
ENM_LINK                                        equ     04000000H
ENM_LOWFIRTF                                    equ     08000000H
#if _RICHEDIT_VER >= 0800H
    ENM_STARTCOMPOSITION                        equ     10000000H
    ENM_ENDCOMPOSITION                          equ     20000000H
    ENM_GROUPTYPINGCHANGE                       equ     40000000H
    ENM_HIDELINKTOOLTIP                         equ     80000000H
#endif

ES_SAVESEL                                      equ     00008000H
ES_SUNKEN                                       equ     00004000H
ES_DISABLENOSCROLL                              equ     00002000H
ES_SELECTIONBAR                                 equ     01000000H
ES_NOOLEDRAGDROP                                equ     00000008H
#if NTDDI_VERSION > NTDDI_WIN98_ME
    ES_EX_NOCALLOLEINIT                         equ     00000000H
#else
    ES_EX_NOCALLOLEINIT                         equ     01000000H
#endif
ES_VERTICAL                                     equ     00400000H
ES_NOIME                                        equ     00080000H
ES_SELFIME                                      equ     00040000H

ECO_AUTOWORDSELECTION                           equ     00000001H
ECO_AUTOVSCROLL                                 equ     00000040H
ECO_AUTOHSCROLL                                 equ     00000080H
ECO_NOHIDESEL                                   equ     00000100H
ECO_READONLY                                    equ     00000800H
ECO_WANTRETURN                                  equ     00001000H
ECO_SAVESEL                                     equ     00008000H
ECO_SELECTIONBAR                                equ     01000000H
ECO_VERTICAL                                    equ     00400000H

ECOOP_SET                                       equ     0001H
ECOOP_OR                                        equ     0002H
ECOOP_AND                                       equ     0003H
ECOOP_XOR                                       equ     0004H

WB_CLASSIFY                                     equ     3
WB_MOVEWORDLEFT                                 equ     4
WB_MOVEWORDRIGHT                                equ     5
WB_LEFTBREAK                                    equ     6
WB_RIGHTBREAK                                   equ     7

WB_MOVEWORDPREV                                 equ     4
WB_MOVEWORDNEXT                                 equ     5
WB_PREVBREAK                                    equ     6
WB_NEXTBREAK                                    equ     7

PC_FOLLOWING                                    equ     1
PC_LEADING                                      equ     2
PC_OVERFLOW                                     equ     3
PC_DELIMITER                                    equ     4

WBF_WORDWRAP                                    equ     0010H
WBF_WORDBREAK                                   equ     0020H
WBF_OVERFLOW                                    equ     0040H
WBF_LEVEL1                                      equ     0080H
WBF_LEVEL2                                      equ     0100H
WBF_CUSTOM                                      equ     0200H

IMF_FORCENONE                                   equ     0001H
IMF_FORCEENABLE                                 equ     0002H
IMF_FORCEDISABLE                                equ     0004H
IMF_CLOSESTATUSWINDOW                           equ     0008H
IMF_VERTICAL                                    equ     0020H
IMF_FORCEACTIVE                                 equ     0040H
IMF_FORCEINACTIVE                               equ     0080H
IMF_FORCEREMEMBER                               equ     0100H
IMF_MULTIPLEEDIT                                equ     0400H

WBF_CLASS                                       equ     0FH
WBF_ISWHITE                                     equ     10H
WBF_BREAKLINE                                   equ     20H
WBF_BREAKAFTER                                  equ     40H

CHARFORMATDELTA                                 equ     <size CHARFORMAT2-size CHARFORMAT>

CFM_BOLD                                        equ     00000001H
CFM_ITALIC                                      equ     00000002H
CFM_UNDERLINE                                   equ     00000004H
CFM_STRIKEOUT                                   equ     00000008H
CFM_PROTECTED                                   equ     00000010H
CFM_LINK                                        equ     00000020H
CFM_SIZE                                        equ     80000000H
CFM_COLOR                                       equ     40000000H
CFM_FACE                                        equ     20000000H
CFM_OFFSET                                      equ     10000000H
CFM_CHARSET                                     equ     08000000H

CFE_BOLD                                        equ     00000001H
CFE_ITALIC                                      equ     00000002H
CFE_UNDERLINE                                   equ     00000004H
CFE_STRIKEOUT                                   equ     00000008H
CFE_PROTECTED                                   equ     00000010H
CFE_LINK                                        equ     00000020H
CFE_AUTOCOLOR                                   equ     40000000H

CFM_SMALLCAPS                                   equ     00000040H
CFM_ALLCAPS                                     equ     00000080H
CFM_HIDDEN                                      equ     00000100H
CFM_OUTLINE                                     equ     00000200H
CFM_SHADOW                                      equ     00000400H
CFM_EMBOSS                                      equ     00000800H
CFM_IMPRINT                                     equ     00001000H
CFM_DISABLED                                    equ     00002000H
CFM_REVISED                                     equ     00004000H

CFM_REVAUTHOR                                   equ     00008000H
CFE_SUBSCRIPT                                   equ     00010000H
CFE_SUPERSCRIPT                                 equ     00020000H
CFM_ANIMATION                                   equ     00040000H
CFM_STYLE                                       equ     00080000H
CFM_KERNING                                     equ     00100000H
CFM_SPACING                                     equ     00200000H
CFM_WEIGHT                                      equ     00400000H
CFM_UNDERLINETYPE                               equ     00800000H
#if _RICHEDIT_VER >= 0600H
    CFM_COOKIE                                  equ     01000000H
#endif
CFM_LCID                                        equ     02000000H
CFM_BACKCOLOR                                   equ     04000000H

CFM_SUBSCRIPT                                   equ     <CFE_SUBSCRIPT or CFE_SUPERSCRIPT>
CFM_SUPERSCRIPT                                 equ     CFM_SUBSCRIPT

CFM_EFFECTS                                     equ     <CFM_BOLD or CFM_ITALIC or CFM_UNDERLINE or CFM_COLOR or CFM_STRIKEOUT or CFE_PROTECTED or CFM_LINK>
CFM_ALL                                         equ     <CFM_EFFECTS or CFM_SIZE or CFM_FACE or CFM_OFFSET or CFM_CHARSET>

CFM_EFFECTS2                                    equ     <CFM_EFFECTS or CFM_DISABLED or CFM_SMALLCAPS or CFM_ALLCAPS or CFM_HIDDEN or CFM_OUTLINE or CFM_SHADOW or CFM_EMBOSS or CFM_IMPRINT or CFM_REVISED or CFM_SUBSCRIPT or CFM_SUPERSCRIPT or CFM_BACKCOLOR>

#if _RICHEDIT_VER >= 0600H
    CFM_ALL2                                    equ     <CFM_ALL or CFM_EFFECTS2 or CFM_BACKCOLOR or CFM_LCID or CFM_UNDERLINETYPE or CFM_WEIGHT or CFM_REVAUTHOR or CFM_SPACING or CFM_KERNING or CFM_STYLE or CFM_ANIMATION or CFM_COOKIE>
#else
    CFM_ALL2                                    equ     <CFM_ALL or CFM_EFFECTS2 or CFM_BACKCOLOR or CFM_LCID or CFM_UNDERLINETYPE or CFM_WEIGHT or CFM_REVAUTHOR or CFM_SPACING or CFM_KERNING or CFM_STYLE or CFM_ANIMATION>
#endif

CFE_SMALLCAPS                                   equ     CFM_SMALLCAPS
CFE_ALLCAPS                                     equ     CFM_ALLCAPS
CFE_HIDDEN                                      equ     CFM_HIDDEN
CFE_OUTLINE                                     equ     CFM_OUTLINE
CFE_SHADOW                                      equ     CFM_SHADOW
CFE_EMBOSS                                      equ     CFM_EMBOSS
CFE_IMPRINT                                     equ     CFM_IMPRINT
CFE_DISABLED                                    equ     CFM_DISABLED
CFE_REVISED                                     equ     CFM_REVISED

CFE_AUTOBACKCOLOR                               equ     CFM_BACKCOLOR

CFM_FONTBOUND                                   equ     00100000H
CFM_LINKPROTECTED                               equ     00800000H
CFM_EXTENDED                                    equ     02000000H
CFM_MATHNOBUILDUP                               equ     08000000H
CFM_MATH                                        equ     10000000H
CFM_MATHORDINARY                                equ     20000000H

CFM_ALLEFFECTS                                  equ     <CFM_EFFECTS2 or CFM_FONTBOUND or CFM_EXTENDED or CFM_MATHNOBUILDUP or CFM_MATH OR CFM_MATHORDINARY>

CFE_FONTBOUND                                   equ     00100000H
CFE_LINKPROTECTED                               equ     00800000H
CFE_EXTENDED                                    equ     02000000H
CFE_MATHNOBUILDUP                               equ     08000000H
CFE_MATH                                        equ     10000000H
CFE_MATHORDINARY                                equ     20000000H

CFU_CF1UNDERLINE                                equ     0FFH
CFU_INVERT                                      equ     0FEH
CFU_UNDERLINETHICKLONGDASH                      equ     18
CFU_UNDERLINETHICKDOTTED                        equ     17
CFU_UNDERLINETHICKDASHDOTDOT                    equ     16
CFU_UNDERLINETHICKDASHDOT                       equ     15
CFU_UNDERLINETHICKDASH                          equ     14
CFU_UNDERLINELONGDASH                           equ     13
CFU_UNDERLINEHEAVYWAVE                          equ     12
CFU_UNDERLINEDOUBLEWAVE                         equ     11
CFU_UNDERLINEHAIRLINE                           equ     10
CFU_UNDERLINETHICK                              equ     9
CFU_UNDERLINEWAVE                               equ     8
CFU_UNDERLINEDASHDOTDOT                         equ     7
CFU_UNDERLINEDASHDOT                            equ     6
CFU_UNDERLINEDASH                               equ     5
CFU_UNDERLINEDOTTED                             equ     4
CFU_UNDERLINEDOUBLE                             equ     3
CFU_UNDERLINEWORD                               equ     2
CFU_UNDERLINE                                   equ     1
CFU_UNDERLINENONE                               equ     0

yHeightCharPtsMost                              equ     1638

SCF_SELECTION                                   equ     0001H
SCF_WORD                                        equ     0002H
SCF_DEFAULT                                     equ     0000H
SCF_ALL                                         equ     0004H
SCF_USEUIRULES                                  equ     0008H

SCF_ASSOCIATEFONT                               equ     0010H

SCF_NOKBUPDATE                                  equ     0020H

SCF_ASSOCIATEFONT2                              equ     0040H
#if _RICHEDIT_VER >= 0500H
    SCF_SMARTFONT                               equ     0080H
    SCF_CHARREPFROMLCID                         equ     0100H

    SPF_DONTSETDEFAULT                          equ     0002H
    SPF_SETDEFAULT                              equ     0004H
#endif

SF_TEXT                                         equ     0001H
SF_RTF                                          equ     0002H
SF_RTFNOOBJS                                    equ     0003H
SF_TEXTIZED                                     equ     0004H

SF_UNICODE                                      equ     0010H
SF_USECODEPAGE                                  equ     0020H
SF_NCRFORNONASCII                               equ     0040H
SFF_WRITEXTRAPAR                                equ     0080H
SFF_SELECTION                                   equ     8000H
SFF_PLAINRTF                                    equ     4000H
SFF_PERSISTVIEWSCALE                            equ     2000H
SFF_KEEPDOCINFO                                 equ     1000H
SFF_PWD                                         equ     0800H
SF_RTFVAL                                       equ     0700H

MAX_TAB_STOPS                                   equ     32
lDefaultTab                                     equ     720
MAX_TABLE_CELLS                                 equ     63

PFM_STARTINDENT                                 equ     00000001H
PFM_RIGHTINDENT                                 equ     00000002H
PFM_OFFSET                                      equ     00000004H
PFM_ALIGNMENT                                   equ     00000008H
PFM_TABSTOPS                                    equ     00000010H
PFM_NUMBERING                                   equ     00000020H
PFM_OFFSETINDENT                                equ     80000000H

PFM_SPACEBEFORE                                 equ     00000040H
PFM_SPACEAFTER                                  equ     00000080H
PFM_LINESPACING                                 equ     00000100H
PFM_STYLE                                       equ     00000400H
PFM_BORDER                                      equ     00000800H
PFM_SHADING                                     equ     00001000H
PFM_NUMBERINGSTYLE                              equ     00002000H
PFM_NUMBERINGTAB                                equ     00004000H
PFM_NUMBERINGSTART                              equ     00008000H

PFM_RTLPARA                                     equ     00010000H
PFM_KEEP                                        equ     00020000H
PFM_KEEPNEXT                                    equ     00040000H
PFM_PAGEBREAKBEFORE                             equ     00080000H
PFM_NOLINENUMBER                                equ     00100000H
PFM_NOWIDOWCONTROL                              equ     00200000H
PFM_DONOTHYPHEN                                 equ     00400000H
PFM_SIDEBYSIDE                                  equ     00800000H

PFM_COLLAPSED                                   equ     01000000H
PFM_OUTLINELEVEL                                equ     02000000H
PFM_BOX                                         equ     04000000H
PFM_RESERVED2                                   equ     08000000H
PFM_TABLEROWDELIMITER                           equ     10000000H
PFM_TEXTWRAPPINGBREAK                           equ     20000000H
PFM_TABLE                                       equ     40000000H

PFM_ALL                                         equ     <PFM_STARTINDENT or PFM_RIGHTINDENT or PFM_OFFSET or PFM_ALIGNMENT or PFM_TABSTOPS or PFM_NUMBERING or PFM_OFFSETINDENT or PFM_RTLPARA>

PFM_EFFECTS                                     equ     <PFM_RTLPARA or PFM_KEEP or PFM_KEEPNEXT or PFM_TABLE or PFM_PAGEBREAKBEFORE or PFM_NOLINENUMBER or PFM_NOWIDOWCONTROL or PFM_DONOTHYPHEN or PFM_SIDEBYSIDE or PFM_TABLE or PFM_TABLEROWDELIMITER>

PFM_ALL2                                        equ     <PFM_ALL or PFM_EFFECTS or PFM_SPACEBEFORE or PFM_SPACEAFTER or PFM_LINESPACING or PFM_STYLE or PFM_SHADING or PFM_BORDER or PFM_NUMBERINGTAB or PFM_NUMBERINGSTART or PFM_NUMBERINGSTYLE>

PFE_RTLPARA                                     equ     <PFM_RTLPARA shr 16>
PFE_KEEP                                        equ     <PFM_KEEP shr 16>
PFE_KEEPNEXT                                    equ     <PFM_KEEPNEXT shr 16>
PFE_PAGEBREAKBEFORE                             equ     <PFM_PAGEBREAKBEFORE shr 16>
PFE_NOLINENUMBER                                equ     <PFM_NOLINENUMBER shr 16>
PFE_NOWIDOWCONTROL                              equ     <PFM_NOWIDOWCONTROL shr 16>
PFE_DONOTHYPHEN                                 equ     <PFM_DONOTHYPHEN shr 16>
PFE_SIDEBYSIDE                                  equ     <PFM_SIDEBYSIDE shr 16>

PFE_TEXTWRAPPINGBREAK                           equ     <PFM_TEXTWRAPPINGBREAK shr 16>

PFE_COLLAPSED                                   equ     <PFM_COLLAPSED shr 16>
PFE_BOX                                         equ     <PFM_BOX shr 16>
PFE_TABLE                                       equ     <PFM_TABLE shr 16>
PFE_TABLEROWDELIMITER                           equ     <PFM_TABLEROWDELIMITER shr 16>

PFN_BULLET                                      equ     1

PFN_ARABIC                                      equ     2
PFN_LCLETTER                                    equ     3
PFN_UCLETTER                                    equ     4
PFN_LCROMAN                                     equ     5
PFN_UCROMAN                                     equ     6

PFNS_PAREN                                      equ     000H
PFNS_PARENS                                     equ     100H
PFNS_PERIOD                                     equ     200H
PFNS_PLAIN                                      equ     300H
PFNS_NONUMBER                                   equ     400H

PFNS_NEWNUMBER                                  equ     8000H

PFA_LEFT                                        equ     1
PFA_RIGHT                                       equ     2
PFA_CENTER                                      equ     3

PFA_JUSTIFY                                     equ     4
PFA_FULL_INTERWORD                              equ     4

#ifndef WM_NOTIFY
    WM_NOTIFY                                   equ     004EH
#endif

SEL_EMPTY                                       equ     0000H
SEL_TEXT                                        equ     0001H
SEL_OBJECT                                      equ     0002H
SEL_MULTICHAR                                   equ     0004H
SEL_MULTIOBJECT                                 equ     0008H

GCM_RIGHTMOUSEDROP                              equ     8000H

#if _RICHEDIT_VER >= 0800H
    GCMF_GRIPPER                                equ     00000001H
    GCMF_SPELLING                               equ     00000002H
    GCMF_TOUCHMENU                              equ     00004000H
    GCMF_MOUSEMENU                              equ     00002000H
#endif

OLEOP_DOVERB                                    equ     1

ST_DEFAULT                                      equ     0
ST_KEEPUNDO                                     equ     1
ST_SELECTION                                    equ     2
ST_NEWCHARS                                     equ     4
#if _RICHEDIT_VER >= 0500H
    ST_UNICODE                                  equ     8
#endif

GT_DEFAULT                                      equ     0
GT_USECRLF                                      equ     1
GT_SELECTION                                    equ     2
GT_RAWTEXT                                      equ     4
GT_NOHIDDENTEXT                                 equ     8

GTL_DEFAULT                                     equ     0
GTL_USECRLF                                     equ     1
GTL_PRECISE                                     equ     2
GTL_CLOSE                                       equ     4
GTL_NUMCHARS                                    equ     8
GTL_NUMBYTES                                    equ     16


#if _RICHEDIT_VER == 0100H
    BOM_DEFPARADIR                              equ     0001H
    BOM_PLAINTEXT                               equ     0002H
#endif
BOM_NEUTRALOVERRIDE                             equ     0004H
BOM_CONTEXTREADING                              equ     0008H
BOM_CONTEXTALIGNMENT                            equ     0010H
BOM_LEGACYBIDICLASS                             equ     0040H
#if _RICHEDIT_VER >= 0600H
    BOM_UNICODEBIDI                             equ     0080H
#endif

#if _RICHEDIT_VER == 0100H
    BOE_RTLDIR                                  equ     0001H
    BOE_PLAINTEXT                               equ     0002H
#endif
BOE_NEUTRALOVERRIDE                             equ     0004H
BOE_CONTEXTREADING                              equ     0008H
BOE_CONTEXTALIGNMENT                            equ     0010H
#if _RICHEDIT_VER >= 0800H
    BOE_FORCERECALC                             equ     0020H
#endif
BOE_LEGACYBIDICLASS                             equ     0040H
#if _RICHEDIT_VER >= 0600H
    BOE_UNICODEBIDI                             equ     0080H
#endif

#ifndef FR_MATCHDIAC_DEF
    FR_MATCHDIAC_DEF equ 1
    FR_MATCHDIAC                                equ     20000000H
    FR_MATCHKASHIDA                             equ     40000000H
    FR_MATCHALEFHAMZA                           equ     80000000H
#endif

#ifndef WCH_EMBEDDING
    WCH_EMBEDDING                               equ     0FFFCH
#endif

PFA_FULL_NEWSPAPER                              equ     5
PFA_FULL_INTERLETTER                            equ     6
PFA_FULL_SCALED                                 equ     7
PFA_FULL_GLYPHS                                 equ     8

AURL_ENABLEEA                                   equ     1

GCM_TOUCHMENU                                   equ     4000H
GCM_MOUSEMENU                                   equ     2000H

TM_PLAINTEXT                                    equ     1
TM_RICHTEXT                                     equ     2
TM_SINGLELEVELUNDO                              equ     4
TM_MULTILEVELUNDO                               equ     8
TM_SINGLECODEPAGE                               equ     16
TM_MULTICODEPAGE                                equ     32

UID_UNKNOWN                                     equ     0
UID_TYPING                                      equ     1
UID_DELETE                                      equ     2
UID_DRAGDROP                                    equ     3
UID_CUT                                         equ     4
UID_PASTE                                       equ     5
UID_AUTOTABLE                                   equ     6

khyphNil                                        equ     0
khyphNormal                                     equ     1
khyphAddBefore                                  equ     2
khyphChangeBefore                               equ     3
khyphDeleteBefore                               equ     4
khyphChangeAfter                                equ     5
khyphDelAndChange                               equ     6

;======================================== Structures ======================================;
struc CHARFORMATA
    cbSize          dd       ?
    dwMask          dd       ?
    dwEffects       dd       ?
    yHeight         dd       ?
    yOffset         dd       ?
    crTextColor     dd       ?
    bCharSet        db       ?
    bPitchAndFamily db       ?
    szFaceName      rb       LF_FACESIZE
ends

struc CHARFORMATW
    cbSize          dd       ?
    dwMask          dd       ?
    dwEffects       dd       ?
    yHeight         dd       ?
    yOffset         dd       ?
    crTextColor     dd       ?
    bCharSet        db       ?
    bPitchAndFamily db       ?
    szFaceName      rw       LF_FACESIZE
ends

struc CHARFORMAT2A
    cbSize          dd       ?
    dwMask          dd       ?
    dwEffects       dd       ?
    yHeight         dd       ?
    yOffset         dd       ?
    crTextColor     dd       ?
    bCharSet        db       ?
    bPitchAndFamily db       ?
    szFaceName      rb       LF_FACESIZE
    wWeight         dw       ?
    sSpacing        dw       ?
    crBackColor     dd       ?
    lcid            dd       ?
    dwReserved      dd       ?
    sStyle          dw       ?
    wKerning        dw       ?
    bUnderlineType  db       ?
    bAnimation      db       ?
    bRevAuthor      db       ?
    bUnderlineColor db       ?
ends

struc CHARFORMAT2W
    cbSize          dd       ?
    dwMask          dd       ?
    dwEffects       dd       ?
    yHeight         dd       ?
    yOffset         dd       ?
    crTextColor     dd       ?
    bCharSet        db       ?
    bPitchAndFamily db       ?
    szFaceName      rw       LF_FACESIZE
    wWeight         dw       ?
    sSpacing        dw       ?
    crBackColor     dd       ?
    lcid            dd       ?
    dwReserved      dd       ?
    sStyle          dw       ?
    wKerning        dw       ?
    bUnderlineType  db       ?
    bAnimation      db       ?
    bRevAuthor      db       ?
    bUnderlineColor db       ?
ends

struc CHARRANGE
    cpMin dd ?
    cpMax dd ?
ends

struc COMPCOLOR
    crText       dd ?
    crBackground dd ?
    dwEffects    dd ?
ends

struc TEXTRANGEA
    chrg      CHARRANGE ?
    lpstrText xword     ?
ends

struc TEXTRANGEW
    chrg      CHARRANGE ?
    lpstrText xword     ?
ends

struc EDITSTREAM
    dwCookie    dd    ?
    dwError     dd    ?
    pfnCallback xword ?
ends

struc FINDTEXTA
    chrg      CHARRANGE ?
    lpstrText xword     ?
ends

struc FINDTEXTW
    chrg      CHARRANGE ?
    lpstrText xword     ?
ends

struc FINDTEXTEXA
    chrg      CHARRANGE ?
    lpstrText xword     ?
    chrgText  CHARRANGE ?
ends

struc FINDTEXTEXW
    chrg      CHARRANGE ?
    lpstrText xword     ?
    chrgText  CHARRANGE ?
ends

struc FORMATRANGE
    hdc       xword     ?
    hdcTarget xword     ?
    rc        RECT      ?
    rcPage    RECT      ?
    chrg      CHARRANGE ?
ends

struc HYPHENATEINFO
    cbSize          dw   ?
    dxHyphenateZone dw   ?
    pfnHyphenate    xword ?
ends

struc PARAFORMAT
    cbSize        dd ?
    dwMask        dd ?
    wNumbering    dw ?
    wReserved     dw ?
    dxStartIndent dd ?
    dxRightIndent dd ?
    dxOffset      dd ?
    wAlignment    dw ?
    cTabCount     dw ?
    rgxTabs       rd MAX_TAB_STOPS
ends

struc PARAFORMAT2
    cbSize           dd ?
    dwMask           dd ?
    wNumbering       dw ?
    wEffects         dw ?
    dxStartIndent    dd ?
    dxRightIndent    dd ?
    dxOffset         dd ?
    wAlignment       dw ?
    cTabCount        dw ?
    rgxTabs          rd MAX_TAB_STOPS
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

struc IMECOMPTEXT
    cb    dd ?
    flags dd ?
ends

#if _RICHEDIT_VER >= 0800H
    struc TABLEROWPARMS
        cbRow              db ?
        cbCell             db ?
        cCell              db ?
        cRow               db ?
        dxCellMargin       dd ?
        dxIndent           dd ?
        dyHeight           dd ?
                           dd ?
        cpStartRow         dd ?
        bTableLevel        db ?
        iCell              db ?
    ends

    struc TABLECELLPARMS
        dxWidth          dd ?
                         dd ?
        wShading         dw ?
        dxBrdrLeft       dw ?
        dyBrdrTop        dw ?
        dxBrdrRight      dw ?
        dyBrdrBottom     dw ?
        crBrdrLeft       dd ?
        crBrdrTop        dd ?
        crBrdrRight      dd ?
        crBrdrBottom     dd ?
        crBackPat        dd ?
        crForePat        dd ?
    ends

    struc RICHEDIT_IMAGE_PARAMETERS
        xWidth            dd    ?
        xHeight           dd    ?
        Ascent            dd    ?
        Type              dd    ?
        pwszAlternateText xword ?
        pIStream          xword ?
    ends

    struc ENDCOMPOSITIONNOTIFY
        nmhdr  NMHDR ?
        dwCode dd    ?
    ends
#endif

struc MSGFILTER
    nmhdr   NMHDR ?
    msg     dd    ?
    wParam  xword ?
    lParam  xword ?
ends

struc REQRESIZE
    nmhdr NMHDR ?
    rc    RECT  ?
ends

struc SELCHANGE
    nmhdr  NMHDR     ?
    chrg   CHARRANGE ?
    seltyp dw        ?
ends

struc ENDROPFILES
    nmhdr       NMHDR ?
    hDrop       xword ?
    cp          dd    ?
    fProtected  dd    ?
ends

struc ENPROTECTED
    nmhdr   NMHDR     ?
    msg     dd        ?
    wParam  xword     ?
    lParam  xword     ?
    chrg    CHARRANGE ?
ends

struc ENSAVECLIPBOARD
    nmhdr        NMHDR ?
    cObjectCount dd    ?
    cch          dd    ?
ends

struc ENOLEOPFAILED
    nmhdr NMHDR ?
    iob   dd    ?
    lOper dd    ?
    hr    dd    ?
ends

struc OBJECTPOSITIONS
    nmhdr        NMHDR ?
    cObjectCount dd    ?
    pcpPositions xword ?
ends

struc ENLINK
    nmhdr  NMHDR     ?
    msg    dd        ?
    wParam xword     ?
    lParam xword     ?
    chrg   CHARRANGE ?
ends

struc ENCORRECTTEXT
    nmhdr  NMHDR     ?
    chrg   CHARRANGE ?
    seltyp dw        ?
ends

struc PUNCTUATION
    iSize         dd    ?
    szPunctuation xword ?
ends

struc REPASTESPECIAL
    dwAspect dd ?
    #if NTDDI_VERSION >= NTDDI_WIN2K
        dwParam dq ?
    #else
        dwParam dd ?
    #endif
ends

struc SETTEXTEX
    flags    dd ?
    codepage dd ?
ends

struc GETTEXTEX
    cb            dd ?
    flags         dd ?
    codepage      dd ?
    lpDefaultChar xword ?
    lpUsedDefChar xword ?
ends

struc GETTEXTLENGTHEX
    flags    dd ?
    codepage dd ?
ends

struc BIDIOPTIONS
    cbSize   dd ?
    wMask    dw ?
    wEffects dw ?
ends

struc CLIPBOARDFORMAT
    nmhdr NMHDR ?
    cf    dw    ?
ends

struc ENLOWFIRTF
    nmhdr     NMHDR ?
    szControl xword ?
ends

struc HYPHRESULT
    khyph   dd    ?
    ichHyph xword ?
    chHyph  dw    ?
ends

#if _RICHEDIT_VER >= 0800H
    struc GROUPTYPINGCHANGE
        nmhdr        NMHDR ?
        fGroupTyping dd    ?
    ends

    struc GETCONTEXTMENUEX
        chrg       CHARRANGE ?
        dwFlags    dd        ?
        pt         POINT     ?
        pvReserved xword     ?
    ends
#endif

#ifdef APP_UNICODE
    define CHARFORMAT CHARFORMATW
    define CHARFORMAT2 CHARFORMAT2W
    define TEXTRANGE TEXTRANGEW
    define FINDTEXT FINDTEXTW
    define FINDTEXTEX FINDTEXTEXW
#else
    define CHARFORMAT CHARFORMATA
    define CHARFORMAT2 CHARFORMAT2A
    define TEXTRANGE TEXTRANGEA
    define FINDTEXT FINDTEXTA
    define FINDTEXTEX FINDTEXTEXA
#endif

#endif ;RICHEDIT_INC
