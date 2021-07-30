; ====================================================;
;                                                     ;
;   comctl32.inc for EC v2 SolAsm classic projects    ;
;                   (version 1.0.4)                   ;
;                                                     ;
;         Copyright © Ramon Sala - 2018-2020          ;
;                                                     ;
; ====================================================;

#ifndef COMCTL32_INC
COMCTL32_INC equ 1

ICC_LISTVIEW_CLASSES                            equ     000000001H
ICC_TREEVIEW_CLASSES                            equ     000000002H
ICC_BAR_CLASSES                                 equ     000000004H
ICC_TAB_CLASSES                                 equ     000000008H
ICC_UPDOWN_CLASS                                equ     000000010H
ICC_PROGRESS_CLASS                              equ     000000020H
ICC_HOTKEY_CLASS                                equ     000000040H
ICC_ANIMATE_CLASS                               equ     000000080H
ICC_WIN95_CLASSES                               equ     0000000FFH
ICC_DATE_CLASSES                                equ     000000100H
ICC_USEREX_CLASSES                              equ     000000200H
ICC_COOL_CLASSES                                equ     000000400H
ICC_INTERNET_CLASSES                            equ     000000800H
ICC_PAGESCROLLER_CLASS                          equ     000001000H
ICC_NATIVEFNTCTL_CLASS                          equ     000002000H
ICC_STANDARD_CLASSES                            equ     000004000H
ICC_LINK_CLASS                                  equ     000008000H

ODT_HEADER                                      equ     100
ODT_TAB                                         equ     101
ODT_LISTVIEW                                    equ     102

LVM_FIRST                                       equ     01000H
TV_FIRST                                        equ     01100H
HDM_FIRST                                       equ     01200H
TCM_FIRST                                       equ     01300H

PGM_FIRST                                       equ     01400H
#ifndef ECM_FIRST
    ECM_FIRST                                   equ     01500H
#endif
BCM_FIRST                                       equ     01600H
CBM_FIRST                                       equ     01700H
CCM_FIRST                                       equ     02000H
CCM_LAST                                        equ     (CCM_FIRST+0200H)

CCM_SETBKCOLOR                                  equ     (CCM_FIRST+1)

CCM_SETCOLORSCHEME                              equ     (CCM_FIRST+2)
CCM_GETCOLORSCHEME                              equ     (CCM_FIRST+3)
CCM_GETDROPTARGET                               equ     (CCM_FIRST+4)
CCM_SETUNICODEFORMAT                            equ     (CCM_FIRST+5)
CCM_GETUNICODEFORMAT                            equ     (CCM_FIRST+6)
CCM_SETVERSION                                  equ     (CCM_FIRST+7)
CCM_GETVERSION                                  equ     (CCM_FIRST+8)
CCM_SETNOTIFYWINDOW                             equ     (CCM_FIRST+9)
CCM_SETWINDOWTHEME                              equ     (CCM_FIRST+11)
CCM_DPISCALE                                    equ     (CCM_FIRST+12)

INFOTIPSIZE                                     equ     1024

NM_FIRST                                        equ     0
NM_LAST                                         equ     (-99)

NM_OUTOFMEMORY                                  equ     (NM_FIRST-1)
NM_CLICK                                        equ     (NM_FIRST-2)
NM_DBLCLK                                       equ     (NM_FIRST-3)
NM_RETURN                                       equ     (NM_FIRST-4)
NM_RCLICK                                       equ     (NM_FIRST-5)
NM_RDBLCLK                                      equ     (NM_FIRST-6)
NM_SETFOCUS                                     equ     (NM_FIRST-7)
NM_KILLFOCUS                                    equ     (NM_FIRST-8)
NM_CUSTOMDRAW                                   equ     (NM_FIRST-12)
NM_HOVER                                        equ     (NM_FIRST-13)
NM_NCHITTEST                                    equ     (NM_FIRST-14)
NM_KEYDOWN                                      equ     (NM_FIRST-15)
NM_RELEASEDCAPTURE                              equ     (NM_FIRST-16)
NM_SETCURSOR                                    equ     (NM_FIRST-17)
NM_CHAR                                         equ     (NM_FIRST-18)
NM_TOOLTIPSCREATED                              equ     (NM_FIRST-19)
NM_LDOWN                                        equ     (NM_FIRST-20)
NM_RDOWN                                        equ     (NM_FIRST-21)
NM_THEMECHANGED                                 equ     (NM_FIRST-22)
NM_FONTCHANGED                                  equ     (NM_FIRST-23)
NM_CUSTOMTEXT                                   equ     (NM_FIRST-24)
NM_TVSTATEIMAGECHANGING                         equ     (NM_FIRST-24)

LVN_FIRST                                       equ     (-100)
LVN_LAST                                        equ     (-199)

HDN_FIRST                                       equ     (-300)
HDN_LAST                                        equ     (-399)

TVN_FIRST                                       equ     (-400)
TVN_LAST                                        equ     (-499)

TTN_FIRST                                       equ     (-520)
TTN_LAST                                        equ     (-549)

TCN_FIRST                                       equ     (-550)
TCN_LAST                                        equ     (-580)

TBN_FIRST                                       equ     (-700)
TBN_LAST                                        equ     (-720)

UDN_FIRST                                       equ     (-721)
UDN_LAST                                        equ     (-740)

MCN_FIRST                                       equ     (-750)
MCN_LAST                                        equ     (-759)

DTN_FIRST                                       equ     (-760)
DTN_LAST                                        equ     (-799)

CBEN_FIRST                                      equ     (-800)
CBEN_LAST                                       equ     (-830)

RBN_FIRST                                       equ     (-831)
RBN_LAST                                        equ     (-859)

IPN_FIRST                                       equ     (-860)
IPN_LAST                                        equ     (-879)

SBN_FIRST                                       equ     (-880)
SBN_LAST                                        equ     (-899)

PGN_FIRST                                       equ     (-900)
PGN_LAST                                        equ     (-950)

MSGF_COMMCTRL_BEGINDRAG                         equ     04200H
MSGF_COMMCTRL_SIZEHEADER                        equ     04201H
MSGF_COMMCTRL_DRAGSELECT                        equ     04202H
MSGF_COMMCTRL_TOOLBARCUST                       equ     04203H

CDRF_DODEFAULT                                  equ     000000000H
CDRF_NEWFONT                                    equ     000000002H
CDRF_SKIPDEFAULT                                equ     000000004H
CDRF_DOERASE                                    equ     000000008H
CDRF_SKIPPOSTPAINT                              equ     000000100H

CDRF_NOTIFYPOSTPAINT                            equ     000000010H
CDRF_NOTIFYITEMDRAW                             equ     000000020H
CDRF_NOTIFYSUBITEMDRAW                          equ     000000020H
CDRF_NOTIFYPOSTERASE                            equ     000000040H

CDDS_PREPAINT                                   equ     000000001H
CDDS_POSTPAINT                                  equ     000000002H
CDDS_PREERASE                                   equ     000000003H
CDDS_POSTERASE                                  equ     000000004H

CDDS_ITEM                                       equ     000010000H
CDDS_ITEMPREPAINT                               equ     <CDDS_ITEM or CDDS_PREPAINT>
CDDS_ITEMPOSTPAINT                              equ     <CDDS_ITEM or CDDS_POSTPAINT>
CDDS_ITEMPREERASE                               equ     <CDDS_ITEM or CDDS_PREERASE>
CDDS_ITEMPOSTERASE                              equ     <CDDS_ITEM or CDDS_POSTERASE>
CDDS_SUBITEM                                    equ     000020000H

CDIS_SELECTED                                   equ     00001H
CDIS_GRAYED                                     equ     00002H
CDIS_DISABLED                                   equ     00004H
CDIS_CHECKED                                    equ     00008H
CDIS_FOCUS                                      equ     00010H
CDIS_DEFAULT                                    equ     00020H
CDIS_HOT                                        equ     00040H
CDIS_MARKED                                     equ     00080H
CDIS_INDETERMINATE                              equ     00100H
CDIS_SHOWKEYBOARDCUES                           equ     00200H
CDIS_NEARHOT                                    equ     00400H
CDIS_OTHERSIDEHOT                               equ     00800H
CDIS_DROPHILITED                                equ     01000H

CLR_NONE                                        equ     0FFFFFFFFH
CLR_DEFAULT                                     equ     0FF000000H

ILC_MASK                                        equ     00001H
ILC_COLOR                                       equ     00000H
ILC_COLORDDB                                    equ     000FEH
ILC_COLOR4                                      equ     00004H
ILC_COLOR8                                      equ     00008H
ILC_COLOR16                                     equ     00010H
ILC_COLOR24                                     equ     00018H
ILC_COLOR32                                     equ     00020H
ILC_PALETTE                                     equ     00800H
ILC_MIRROR                                      equ     000002000H
ILC_PERITEMMIRROR                               equ     000008000H
ILC_ORIGINALSIZE                                equ     000010000H
ILC_HIGHQUALITYSCALE                            equ     000020000H

ILD_NORMAL                                      equ     00000H
ILD_TRANSPARENT                                 equ     00001H
ILD_MASK                                        equ     00010H
ILD_IMAGE                                       equ     00020H
ILD_ROP                                         equ     00040H
ILD_BLEND25                                     equ     00002H
ILD_BLEND50                                     equ     00004H
ILD_OVERLAYMASK                                 equ     00F00H
ILD_PRESERVEALPHA                               equ     000001000H
ILD_SCALE                                       equ     000002000H
ILD_DPISCALE                                    equ     000004000H
ILD_ASYNC                                       equ     000008000H

ILD_SELECTED                                    equ     ILD_BLEND50
ILD_FOCUS                                       equ     ILD_BLEND25
ILD_BLEND                                       equ     ILD_BLEND50
CLR_HILIGHT                                     equ     CLR_DEFAULT

ILS_NORMAL                                      equ     000000000H
ILS_GLOW                                        equ     000000001H
ILS_SHADOW                                      equ     000000002H
ILS_SATURATE                                    equ     000000004H
ILS_ALPHA                                       equ     000000008H

ILGT_NORMAL                                     equ     000000000H
ILGT_ASYNC                                      equ     000000001H

ILIF_ALPHA                                      equ     000000001H
ILIF_LOWQUALITY                                 equ     000000002H
ILDRF_IMAGELOWQUALITY                           equ     000000001H
ILDRF_OVERLAYLOWQUALITY                         equ     000000010H

HBITMAP_CALLBACK                                equ     (-1)

ILCF_MOVE                                       equ     000000000H
ILCF_SWAP                                       equ     000000001H

ILP_NORMAL                                      equ     0
ILP_DOWNLEVEL                                   equ     1

;========================================== Header ========================================;
HDS_HORZ                                        equ     00000H
HDS_BUTTONS                                     equ     00002H
HDS_HOTTRACK                                    equ     00004H
HDS_HIDDEN                                      equ     00008H

HDS_DRAGDROP                                    equ     00040H
HDS_FULLDRAG                                    equ     00080H
HDS_FILTERBAR                                   equ     00100H
HDS_FLAT                                        equ     00200H

HDS_CHECKBOXES                                  equ     00400H
HDS_NOSIZING                                    equ     00800H
HDS_OVERFLOW                                    equ     01000H

HDFT_ISSTRING                                   equ     00000H
HDFT_ISNUMBER                                   equ     00001H
HDFT_ISDATE                                     equ     00002H
HDFT_HASNOVALUE                                 equ     08000H

HDI_WIDTH                                       equ     00001H
HDI_HEIGHT                                      equ     HDI_WIDTH
HDI_TEXT                                        equ     00002H
HDI_FORMAT                                      equ     00004H
HDI_LPARAM                                      equ     00008H
HDI_BITMAP                                      equ     00010H
HDI_IMAGE                                       equ     00020H
HDI_DI_SETITEM                                  equ     00040H
HDI_ORDER                                       equ     00080H
HDI_FILTER                                      equ     00100H
HDI_STATE                                       equ     00200H

HDF_LEFT                                        equ     0
HDF_RIGHT                                       equ     1
HDF_CENTER                                      equ     2
HDF_JUSTIFYMASK                                 equ     00003H
HDF_RTLREADING                                  equ     4

HDF_OWNERDRAW                                   equ     08000H
HDF_STRING                                      equ     04000H
HDF_BITMAP                                      equ     02000H
HDF_BITMAP_ON_RIGHT                             equ     01000H
HDF_IMAGE                                       equ     00800H
HDF_SORTUP                                      equ     00400H
HDF_SORTDOWN                                    equ     00200H
HDF_CHECKBOX                                    equ     00040H
HDF_CHECKED                                     equ     00080H
HDF_FIXEDWIDTH                                  equ     00100H
HDF_SPLITBUTTON                                 equ     01000000H

HHT_NOWHERE                                     equ     00001H
HHT_ONHEADER                                    equ     00002H
HHT_ONDIVIDER                                   equ     00004H
HHT_ONDIVOPEN                                   equ     00008H
HHT_ONFILTER                                    equ     00010H
HHT_ONFILTERBUTTON                              equ     00020H
HHT_ABOVE                                       equ     00100H
HHT_BELOW                                       equ     00200H
HHT_TORIGHT                                     equ     00400H
HHT_TOLEFT                                      equ     00800H
HHT_ONITEMSTATEICON                             equ     01000H
HHT_ONDROPDOWN                                  equ     02000H
HHT_ONOVERFLOW                                  equ     04000H

HDSIL_NORMAL                                    equ  0
HDSIL_STATE                                     equ  1

HDM_GETITEMCOUNT                                equ     (HDM_FIRST+0)
HDM_INSERTITEMA                                 equ     (HDM_FIRST+1)
HDM_INSERTITEMW                                 equ     (HDM_FIRST+10)
HDM_DELETEITEM                                  equ     (HDM_FIRST+2)
HDM_GETITEMA                                    equ     (HDM_FIRST+3)
HDM_GETITEMW                                    equ     (HDM_FIRST+11)
HDM_SETITEMA                                    equ     (HDM_FIRST+4)
HDM_SETITEMW                                    equ     (HDM_FIRST+12)
HDM_LAYOUT                                      equ     (HDM_FIRST+5)

HDM_HITTEST                                     equ     (HDM_FIRST+6)
HDM_GETITEMRECT                                 equ     (HDM_FIRST+7)
HDM_SETIMAGELIST                                equ     (HDM_FIRST+8)
HDM_GETIMAGELIST                                equ     (HDM_FIRST+9)
HDM_ORDERTOINDEX                                equ     (HDM_FIRST+15)
HDM_CREATEDRAGIMAGE                             equ     (HDM_FIRST+16)
HDM_GETORDERARRAY                               equ     (HDM_FIRST+17)
HDM_SETORDERARRAY                               equ     (HDM_FIRST+18)
HDM_SETHOTDIVIDER                               equ     (HDM_FIRST+19)
HDM_SETBITMAPMARGIN                             equ     (HDM_FIRST+20)
HDM_GETBITMAPMARGIN                             equ     (HDM_FIRST+21)
HDM_SETFILTERCHANGETIMEOUT                      equ     (HDM_FIRST+22)
HDM_EDITFILTER                                  equ     (HDM_FIRST+23)
HDM_CLEARFILTER                                 equ     (HDM_FIRST+24)
HDM_GETITEMDROPDOWNRECT                         equ     (HDM_FIRST+25)
HDM_GETOVERFLOWRECT                             equ     (HDM_FIRST+26)
HDM_GETFOCUSEDITEM                              equ     (HDM_FIRST+27)
HDM_SETFOCUSEDITEM                              equ     (HDM_FIRST+28)

HDM_SETUNICODEFORMAT                            equ     CCM_SETUNICODEFORMAT
HDM_GETUNICODEFORMAT                            equ     CCM_GETUNICODEFORMAT

HDN_ITEMCHANGINGA                               equ     (HDN_FIRST-0)
HDN_ITEMCHANGINGW                               equ     (HDN_FIRST-20)
HDN_ITEMCHANGEDA                                equ     (HDN_FIRST-1)
HDN_ITEMCHANGEDW                                equ     (HDN_FIRST-21)
HDN_ITEMCLICKA                                  equ     (HDN_FIRST-2)
HDN_ITEMCLICKW                                  equ     (HDN_FIRST-22)
HDN_ITEMDBLCLICKA                               equ     (HDN_FIRST-3)
HDN_ITEMDBLCLICKW                               equ     (HDN_FIRST-23)
HDN_DIVIDERDBLCLICKA                            equ     (HDN_FIRST-5)
HDN_DIVIDERDBLCLICKW                            equ     (HDN_FIRST-25)
HDN_BEGINTRACKA                                 equ     (HDN_FIRST-6)
HDN_BEGINTRACKW                                 equ     (HDN_FIRST-26)
HDN_ENDTRACKA                                   equ     (HDN_FIRST-7)
HDN_ENDTRACKW                                   equ     (HDN_FIRST-27)
HDN_TRACKA                                      equ     (HDN_FIRST-8)
HDN_TRACKW                                      equ     (HDN_FIRST-28)
HDN_GETDISPINFOA                                equ     (HDN_FIRST-9)
HDN_GETDISPINFOW                                equ     (HDN_FIRST-29)
HDN_BEGINDRAG                                   equ     (HDN_FIRST-10)
HDN_ENDDRAG                                     equ     (HDN_FIRST-11)
HDN_FILTERCHANGE                                equ     (HDN_FIRST-12)
HDN_FILTERBTNCLICK                              equ     (HDN_FIRST-13)
HDN_BEGINFILTEREDIT                             equ     (HDN_FIRST-14)
HDN_ENDFILTEREDIT                               equ     (HDN_FIRST-15)
HDN_ITEMSTATEICONCLICK                          equ     (HDN_FIRST-16)
HDN_ITEMKEYDOWN                                 equ     (HDN_FIRST-17)
HDN_DROPDOWN                                    equ     (HDN_FIRST-18)
HDN_OVERFLOWCLICK                               equ     (HDN_FIRST-19)

;========================================== ToolBar =======================================;
CMB_MASKED                                      equ     002H

TBSTATE_CHECKED                                 equ     001H
TBSTATE_PRESSED                                 equ     002H
TBSTATE_ENABLED                                 equ     004H
TBSTATE_HIDDEN                                  equ     008H
TBSTATE_INDETERMINATE                           equ     010H
TBSTATE_WRAP                                    equ     020H
TBSTATE_ELLIPSES                                equ     040H
TBSTATE_MARKED                                  equ     080H
TBSTATE_HIGHLIGHTED                             equ     080H

TBSTYLE_BUTTON                                  equ     00000H
TBSTYLE_SEP                                     equ     00001H
TBSTYLE_CHECK                                   equ     00002H
TBSTYLE_GROUP                                   equ     00004H
TBSTYLE_CHECKGROUP                              equ     <TBSTYLE_GROUP or TBSTYLE_CHECK>
TBSTYLE_DROPDOWN                                equ     00008H
TBSTYLE_AUTOSIZE                                equ     00010H
TBSTYLE_NOPREFIX                                equ     00020H

TBSTYLE_TOOLTIPS                                equ     00100H
TBSTYLE_WRAPABLE                                equ     00200H
TBSTYLE_ALTDRAG                                 equ     00400H
TBSTYLE_FLAT                                    equ     00800H
TBSTYLE_LIST                                    equ     01000H
TBSTYLE_CUSTOMERASE                             equ     02000H
TBSTYLE_REGISTERDROP                            equ     04000H
TBSTYLE_TRANSPARENT                             equ     08000H
TBSTYLE_EX_DRAWDDARROWS                         equ     000000001H
TBSTYLE_EX_MIXEDBUTTONS                         equ     000000008H
TBSTYLE_EX_HIDECLIPPEDBUTTONS                   equ     000000010H
TBSTYLE_EX_DOUBLEBUFFER                         equ     000000080H

TBCDRF_NOEDGES                                  equ     000010000H
TBCDRF_HILITEHOTTRACK                           equ     000020000H
TBCDRF_NOOFFSET                                 equ     000040000H
TBCDRF_NOMARK                                   equ     000080000H
TBCDRF_NOETCHEDEFFECT                           equ     000100000H
TBCDRF_BLENDICON                                equ     000200000H
TBCDRF_NOBACKGROUND                             equ     000400000H
TBCDRF_USECDCOLORS                              equ     000800000H

HINST_COMMCTRL                                  equ     (-1)
IDB_STD_SMALL_COLOR                             equ     0
IDB_STD_LARGE_COLOR                             equ     1
IDB_VIEW_SMALL_COLOR                            equ     4
IDB_VIEW_LARGE_COLOR                            equ     5
IDB_HIST_SMALL_COLOR                            equ     8
IDB_HIST_LARGE_COLOR                            equ     9
IDB_HIST_NORMAL                                 equ     12
IDB_HIST_HOT                                    equ     13
IDB_HIST_DISABLED                               equ     14
IDB_HIST_PRESSED                                equ     15

STD_CUT                                         equ     0
STD_COPY                                        equ     1
STD_PASTE                                       equ     2
STD_UNDO                                        equ     3
STD_REDOW                                       equ     4
STD_DELETE                                      equ     5
STD_FILENEW                                     equ     6
STD_FILEOPEN                                    equ     7
STD_FILESAVE                                    equ     8
STD_PRINTPRE                                    equ     9
STD_PROPERTIES                                  equ     10
STD_HELP                                        equ     11
STD_FIND                                        equ     12
STD_REPLACE                                     equ     13
STD_PRINT                                       equ     14

VIEW_LARGEICONS                                 equ     0
VIEW_SMALLICONS                                 equ     1
VIEW_LIST                                       equ     2
VIEW_DETAILS                                    equ     3
VIEW_SORTNAME                                   equ     4
VIEW_SORTSIZE                                   equ     5
VIEW_SORTDATE                                   equ     6
VIEW_SORTTYPE                                   equ     7
VIEW_PARENTFOLDER                               equ     8
VIEW_NETCONNECT                                 equ     9
VIEW_NETDISCONNECT                              equ     10
VIEW_NEWFOLDER                                  equ     11
VIEW_VIEWMENU                                   equ     12

HIST_BACK                                       equ     0
HIST_FORWARD                                    equ     1
HIST_FAVORITES                                  equ     2
HIST_ADDTOFAVORITES                             equ     3
HIST_VIEWTREE                                   equ     4

TB_ENABLEBUTTON                                 equ     (WM_USER+1)
TB_CHECKBUTTON                                  equ     (WM_USER+2)
TB_PRESSBUTTON                                  equ     (WM_USER+3)
TB_HIDEBUTTON                                   equ     (WM_USER+4)
TB_INDETERMINATE                                equ     (WM_USER+5)
TB_MARKBUTTON                                   equ     (WM_USER+6)
TB_ISBUTTONENABLED                              equ     (WM_USER+9)
TB_ISBUTTONCHECKED                              equ     (WM_USER+10)
TB_ISBUTTONPRESSED                              equ     (WM_USER+11)
TB_ISBUTTONHIDDEN                               equ     (WM_USER+12)
TB_ISBUTTONINDETERMINATE                        equ     (WM_USER+13)
TB_ISBUTTONHIGHLIGHTED                          equ     (WM_USER+14)
TB_SETSTATE                                     equ     (WM_USER+17)
TB_GETSTATE                                     equ     (WM_USER+18)
TB_ADDBITMAP                                    equ     (WM_USER+19)
TB_ADDBUTTONSA                                  equ     (WM_USER+20)
TB_INSERTBUTTONA                                equ     (WM_USER+21)
TB_DELETEBUTTON                                 equ     (WM_USER+22)
TB_GETBUTTON                                    equ     (WM_USER+23)
TB_BUTTONCOUNT                                  equ     (WM_USER+24)
TB_COMMANDTOINDEX                               equ     (WM_USER+25)
TB_SAVERESTOREA                                 equ     (WM_USER+26)
TB_SAVERESTOREW                                 equ     (WM_USER+76)
TB_CUSTOMIZE                                    equ     (WM_USER+27)
TB_ADDSTRINGA                                   equ     (WM_USER+28)
TB_ADDSTRINGW                                   equ     (WM_USER+77)
TB_GETITEMRECT                                  equ     (WM_USER+29)
TB_BUTTONSTRUCTSIZE                             equ     (WM_USER+30)
TB_SETBUTTONSIZE                                equ     (WM_USER+31)
TB_SETBITMAPSIZE                                equ     (WM_USER+32)
TB_AUTOSIZE                                     equ     (WM_USER+33)
TB_GETTOOLTIPS                                  equ     (WM_USER+35)
TB_SETTOOLTIPS                                  equ     (WM_USER+36)
TB_SETPARENT                                    equ     (WM_USER+37)
TB_SETROWS                                      equ     (WM_USER+39)
TB_GETROWS                                      equ     (WM_USER+40)
TB_SETCMDID                                     equ     (WM_USER+42)
TB_CHANGEBITMAP                                 equ     (WM_USER+43)
TB_GETBITMAP                                    equ     (WM_USER+44)
TB_GETBUTTONTEXTA                               equ     (WM_USER+45)
TB_REPLACEBITMAP                                equ     (WM_USER+46)
TB_SETINDENT                                    equ     (WM_USER+47)
TB_SETIMAGELIST                                 equ     (WM_USER+48)
TB_GETIMAGELIST                                 equ     (WM_USER+49)
TB_LOADIMAGES                                   equ     (WM_USER+50)
TB_GETRECT                                      equ     (WM_USER+51)
TB_SETHOTIMAGELIST                              equ     (WM_USER+52)
TB_GETHOTIMAGELIST                              equ     (WM_USER+53)
TB_SETDISABLEDIMAGELIST                         equ     (WM_USER+54)
TB_GETDISABLEDIMAGELIST                         equ     (WM_USER+55)
TB_SETSTYLE                                     equ     (WM_USER+56)
TB_GETSTYLE                                     equ     (WM_USER+57)
TB_GETBUTTONSIZE                                equ     (WM_USER+58)
TB_SETBUTTONWIDTH                               equ     (WM_USER+59)
TB_SETMAXTEXTROWS                               equ     (WM_USER+60)
TB_GETTEXTROWS                                  equ     (WM_USER+61)
TB_GETOBJECT                                    equ     (WM_USER+62)
TB_GETBUTTONINFOW                               equ     (WM_USER+63)
TB_SETBUTTONINFOW                               equ     (WM_USER+64)
TB_GETBUTTONINFOA                               equ     (WM_USER+65)
TB_SETBUTTONINFOA                               equ     (WM_USER+66)
TB_INSERTBUTTONW                                equ     (WM_USER+67)
TB_ADDBUTTONSW                                  equ     (WM_USER+68)
TB_HITTEST                                      equ     (WM_USER+69)
TB_SETDRAWTEXTFLAGS                             equ     (WM_USER+70)
TB_GETHOTITEM                                   equ     (WM_USER+71)
TB_SETHOTITEM                                   equ     (WM_USER+72)
TB_SETANCHORHIGHLIGHT                           equ     (WM_USER+73)
TB_GETANCHORHIGHLIGHT                           equ     (WM_USER+74)
TB_GETBUTTONTEXTW                               equ     (WM_USER+75)
TB_MAPACCELERATORA                              equ     (WM_USER+78)
TB_GETINSERTMARK                                equ     (WM_USER+79)
TB_SETINSERTMARK                                equ     (WM_USER+80)
TB_INSERTMARKHITTEST                            equ     (WM_USER+81)
TB_MOVEBUTTON                                   equ     (WM_USER+82)
TB_GETMAXSIZE                                   equ     (WM_USER+83)
TB_SETEXTENDEDSTYLE                             equ     (WM_USER+84)
TB_GETEXTENDEDSTYLE                             equ     (WM_USER+85)
TB_GETPADDING                                   equ     (WM_USER+86)
TB_SETPADDING                                   equ     (WM_USER+87)
TB_SETINSERTMARKCOLOR                           equ     (WM_USER+88)
TB_GETINSERTMARKCOLOR                           equ     (WM_USER+89)
TB_SETCOLORSCHEME                               equ     CCM_SETCOLORSCHEME
TB_GETCOLORSCHEME                               equ     CCM_GETCOLORSCHEME
TB_SETUNICODEFORMAT                             equ     CCM_SETUNICODEFORMAT
TB_GETUNICODEFORMAT                             equ     CCM_GETUNICODEFORMAT
TB_MAPACCELERATORW                              equ     (WM_USER+90)
TB_GETSTRINGW                                   equ     (WM_USER+91)
TB_GETSTRINGA                                   equ     (WM_USER+92)
TB_GETMETRICS                                   equ     (WM_USER+101)
TB_SETMETRICS                                   equ     (WM_USER+102)
TB_SETPRESSEDIMAGELIST                          equ     (WM_USER+104)
TB_GETPRESSEDIMAGELIST                          equ     (WM_USER+105)

TB_SETWINDOWTHEME                               equ     CCM_SETWINDOWTHEME

TBIMHT_AFTER                                    equ     000000001H
TBIMHT_BACKGROUND                               equ     000000002H

TBBF_LARGE                                      equ     00001H

TBNRF_HIDEHELP                                  equ     000000001H
TBNRF_ENDCUSTOMIZE                              equ     000000002H

TB_GETBITMAPFLAGS                               equ     (WM_USER+41)

TBIF_IMAGE                                      equ     000000001H
TBIF_TEXT                                       equ     000000002H
TBIF_STATE                                      equ     000000004H
TBIF_STYLE                                      equ     000000008H
TBIF_LPARAM                                     equ     000000010H
TBIF_COMMAND                                    equ     000000020H
TBIF_SIZE                                       equ     000000040H
TBIF_BYINDEX                                    equ     080000000H

TBN_GETBUTTONINFOA                              equ     (TBN_FIRST-0)
TBN_BEGINDRAG                                   equ     (TBN_FIRST-1)
TBN_ENDDRAG                                     equ     (TBN_FIRST-2)
TBN_BEGINADJUST                                 equ     (TBN_FIRST-3)
TBN_ENDADJUST                                   equ     (TBN_FIRST-4)
TBN_RESET                                       equ     (TBN_FIRST-5)
TBN_QUERYINSERT                                 equ     (TBN_FIRST-6)
TBN_QUERYDELETE                                 equ     (TBN_FIRST-7)
TBN_TOOLBARCHANGE                               equ     (TBN_FIRST-8)
TBN_CUSTHELP                                    equ     (TBN_FIRST-9)
TBN_DROPDOWN                                    equ     (TBN_FIRST-10)
TBN_GETOBJECT                                   equ     (TBN_FIRST-12)
TBN_HOTITEMCHANGE                               equ     (TBN_FIRST-13)
TBN_DRAGOUT                                     equ     (TBN_FIRST-14)
TBN_DELETINGBUTTON                              equ     (TBN_FIRST-15)
TBN_GETDISPINFOA                                equ     (TBN_FIRST-16)
TBN_GETDISPINFOW                                equ     (TBN_FIRST-17)
TBN_GETINFOTIPA                                 equ     (TBN_FIRST-18)
TBN_GETINFOTIPW                                 equ     (TBN_FIRST-19)
TBN_GETBUTTONINFOW                              equ     (TBN_FIRST-20)
TBN_RESTORE                                     equ     (TBN_FIRST-21)
TBN_SAVE                                        equ     (TBN_FIRST-22)
TBN_INITCUSTOMIZE                               equ     (TBN_FIRST-23)

TBMF_PAD                                        equ     000000001H
TBMF_BARPAD                                     equ     000000002H
TBMF_BUTTONSPACING                              equ     000000004H

HICF_OTHER                                      equ     000000000H
HICF_MOUSE                                      equ     000000001H
HICF_ARROWKEYS                                  equ     000000002H
HICF_ACCELERATOR                                equ     000000004H
HICF_DUPACCEL                                   equ     000000008H
HICF_ENTERING                                   equ     000000010H
HICF_LEAVING                                    equ     000000020H
HICF_RESELECT                                   equ     000000040H
HICF_LMOUSE                                     equ     000000080H
HICF_TOGGLEDROPDOWN                             equ     000000100H

TBNF_IMAGE                                      equ     000000001H
TBNF_TEXT                                       equ     000000002H
TBNF_DI_SETITEM                                 equ     010000000H

TBDDRET_DEFAULT                                 equ     0
TBDDRET_NODEFAULT                               equ     1
TBDDRET_TREATPRESSED                            equ     2

;=========================================== ReBar ========================================;
RBIM_IMAGELIST                                  equ     000000001H

RBS_TOOLTIPS                                    equ     00100H
RBS_VARHEIGHT                                   equ     00200H
RBS_BANDBORDERS                                 equ     00400H
RBS_FIXEDORDER                                  equ     00800H
RBS_REGISTERDROP                                equ     01000H
RBS_AUTOSIZE                                    equ     02000H
RBS_VERTICALGRIPPER                             equ     04000H
RBS_DBLCLKTOGGLE                                equ     08000H

RBBS_BREAK                                      equ     000000001H
RBBS_FIXEDSIZE                                  equ     000000002H
RBBS_CHILDEDGE                                  equ     000000004H
RBBS_HIDDEN                                     equ     000000008H
RBBS_NOVERT                                     equ     000000010H
RBBS_FIXEDBMP                                   equ     000000020H
RBBS_VARIABLEHEIGHT                             equ     000000040H
RBBS_GRIPPERALWAYS                              equ     000000080H
RBBS_NOGRIPPER                                  equ     000000100H
RBBS_USECHEVRON                                 equ     000000200H
RBBS_HIDETITLE                                  equ     000000400H
RBBS_TOPALIGN                                   equ     000000800H

RBBIM_STYLE                                     equ     000000001H
RBBIM_COLORS                                    equ     000000002H
RBBIM_TEXT                                      equ     000000004H
RBBIM_IMAGE                                     equ     000000008H
RBBIM_CHILD                                     equ     000000010H
RBBIM_CHILDSIZE                                 equ     000000020H
RBBIM_SIZE                                      equ     000000040H
RBBIM_BACKGROUND                                equ     000000080H
RBBIM_ID                                        equ     000000100H
RBBIM_IDEALSIZE                                 equ     000000200H
RBBIM_LPARAM                                    equ     000000400H
RBBIM_HEADERSIZE                                equ     000000800H
RBBIM_CHEVRONLOCATION                           equ     000001000H
RBBIM_CHEVRONSTATE                              equ     000002000H

RB_INSERTBANDA                                  equ     (WM_USER+1)
RB_DELETEBAND                                   equ     (WM_USER+2)
RB_GETBARINFO                                   equ     (WM_USER+3)
RB_SETBARINFO                                   equ     (WM_USER+4)
RB_SETBANDINFOA                                 equ     (WM_USER+6)
RB_SETPARENT                                    equ     (WM_USER+7)
RB_HITTEST                                      equ     (WM_USER+8)
RB_GETRECT                                      equ     (WM_USER+9)
RB_INSERTBANDW                                  equ     (WM_USER+10)
RB_SETBANDINFOW                                 equ     (WM_USER+11)
RB_GETBANDCOUNT                                 equ     (WM_USER+12)
RB_GETROWCOUNT                                  equ     (WM_USER+13)
RB_GETROWHEIGHT                                 equ     (WM_USER+14)
RB_IDTOINDEX                                    equ     (WM_USER+16)
RB_GETTOOLTIPS                                  equ     (WM_USER+17)
RB_SETTOOLTIPS                                  equ     (WM_USER+18)
RB_SETBKCOLOR                                   equ     (WM_USER+19)
RB_GETBKCOLOR                                   equ     (WM_USER+20)
RB_SETTEXTCOLOR                                 equ     (WM_USER+21)
RB_GETTEXTCOLOR                                 equ     (WM_USER+22)
RB_SIZETORECT                                   equ     (WM_USER+23)

RB_SETCOLORSCHEME                               equ     CCM_SETCOLORSCHEME
RB_GETCOLORSCHEME                               equ     CCM_GETCOLORSCHEME

RB_BEGINDRAG                                    equ     (WM_USER+24)
RB_ENDDRAG                                      equ     (WM_USER+25)
RB_DRAGMOVE                                     equ     (WM_USER+26)
RB_GETBARHEIGHT                                 equ     (WM_USER+27)
RB_GETBANDINFOW                                 equ     (WM_USER+28)
RB_GETBANDINFOA                                 equ     (WM_USER+29)
RB_MINIMIZEBAND                                 equ     (WM_USER+30)
RB_MAXIMIZEBAND                                 equ     (WM_USER+31)
RB_GETDROPTARGET                                equ     (CCM_GETDROPTARGET)
RB_GETBANDBORDERS                               equ     (WM_USER+34)
RB_SHOWBAND                                     equ     (WM_USER+35)
RB_SETPALETTE                                   equ     (WM_USER+37)
RB_GETPALETTE                                   equ     (WM_USER+38)
RB_MOVEBAND                                     equ     (WM_USER+39)
RB_SETUNICODEFORMAT                             equ     CCM_SETUNICODEFORMAT
RB_GETUNICODEFORMAT                             equ     CCM_GETUNICODEFORMAT
RB_GETBANDMARGINS                               equ     (WM_USER+40)
RB_SETEXTENDEDSTYLE                             equ     (WM_USER+41)
RB_GETEXTENDEDSTYLE                             equ     (WM_USER+42)
RB_PUSHCHEVRON                                  equ     (WM_USER+43)
RB_SETBANDWIDTH                                 equ     (WM_USER+44)
RB_SETWINDOWTHEME                               equ     CCM_SETWINDOWTHEME

RBN_HEIGHTCHANGE                                equ     (RBN_FIRST-0)
RBN_GETOBJECT                                   equ     (RBN_FIRST-1)
RBN_LAYOUTCHANGED                               equ     (RBN_FIRST-2)
RBN_AUTOSIZE                                    equ     (RBN_FIRST-3)
RBN_BEGINDRAG                                   equ     (RBN_FIRST-4)
RBN_ENDDRAG                                     equ     (RBN_FIRST-5)
RBN_DELETINGBAND                                equ     (RBN_FIRST-6)
RBN_DELETEDBAND                                 equ     (RBN_FIRST-7)
RBN_CHILDSIZE                                   equ     (RBN_FIRST-8)
RBN_CHEVRONPUSHED                               equ     (RBN_FIRST-10)
RBN_SPLITTERDRAG                                equ     (RBN_FIRST-11)
RBN_MINMAX                                      equ     (RBN_FIRST-21)
RBN_AUTOBREAK                                   equ     (RBN_FIRST-22)

RBNM_ID                                         equ     000000001H
RBNM_STYLE                                      equ     000000002H
RBNM_LPARAM                                     equ     000000004H

RBHT_NOWHERE                                    equ     00001H
RBHT_CAPTION                                    equ     00002H
RBHT_CLIENT                                     equ     00003H
RBHT_GRABBER                                    equ     00004H
RBHT_CHEVRON                                    equ     00008H
RBHT_SPLITTER                                   equ     00010H

RBSTR_CHANGERECT                                equ     00001H

RBAB_AUTOSIZE                                   equ     00001H
RBAB_ADDBAND                                    equ     00002H

;========================================= Tooltips =======================================;
TTS_ALWAYSTIP                                   equ     001H
TTS_NOPREFIX                                    equ     002H
TTS_NOANIMATE                                   equ     0010H
TTS_NOFADE                                      equ     0020H
TTS_BALLOON                                     equ     0040H
TTS_CLOSE                                       equ     0080H
TTS_USEVISUALSTYLE                              equ     0100H

TTF_IDISHWND                                    equ     00001H

TTF_CENTERTIP                                   equ     00002H
TTF_RTLREADING                                  equ     00004H
TTF_SUBCLASS                                    equ     00010H
TTF_TRACK                                       equ     00020H
TTF_ABSOLUTE                                    equ     00080H
TTF_TRANSPARENT                                 equ     00100H
TTF_DI_SETITEM                                  equ     08000H

TTDT_AUTOMATIC                                  equ     0
TTDT_RESHOW                                     equ     1
TTDT_AUTOPOP                                    equ     2
TTDT_INITIAL                                    equ     3

TTI_NONE                                        equ     0
TTI_INFO                                        equ     1
TTI_WARNING                                     equ     2
TTI_ERROR                                       equ     3
TTI_INFO_LARGE                                  equ     4
TTI_WARNING_LARGE                               equ     5
TTI_ERROR_LARGE                                 equ     6

TTM_ACTIVATE                                    equ     (WM_USER+1)
TTM_SETDELAYTIME                                equ     (WM_USER+3)
TTM_ADDTOOLA                                    equ     (WM_USER+4)
TTM_DELTOOLA                                    equ     (WM_USER+5)
TTM_NEWTOOLRECTA                                equ     (WM_USER+6)
TTM_RELAYEVENT                                  equ     (WM_USER+7)
TTM_GETTOOLINFOA                                equ     (WM_USER+8)
TTM_SETTOOLINFOA                                equ     (WM_USER+9)
TTM_HITTESTA                                    equ     (WM_USER+10)
TTM_GETTEXTA                                    equ     (WM_USER+11)
TTM_UPDATETIPTEXTA                              equ     (WM_USER+12)
TTM_GETTOOLCOUNT                                equ     (WM_USER+13)
TTM_ENUMTOOLSA                                  equ     (WM_USER+14)
TTM_GETCURRENTTOOLA                             equ     (WM_USER+15)
TTM_WINDOWFROMPOINT                             equ     (WM_USER+16)
TTM_TRACKACTIVATE                               equ     (WM_USER+17)
TTM_TRACKPOSITION                               equ     (WM_USER+18)
TTM_SETTIPBKCOLOR                               equ     (WM_USER+19)
TTM_SETTIPTEXTCOLOR                             equ     (WM_USER+20)
TTM_GETDELAYTIME                                equ     (WM_USER+21)
TTM_GETTIPBKCOLOR                               equ     (WM_USER+22)
TTM_GETTIPTEXTCOLOR                             equ     (WM_USER+23)
TTM_SETMAXTIPWIDTH                              equ     (WM_USER+24)
TTM_GETMAXTIPWIDTH                              equ     (WM_USER+25)
TTM_SETMARGIN                                   equ     (WM_USER+26)
TTM_GETMARGIN                                   equ     (WM_USER+27)
TTM_POP                                         equ     (WM_USER+28)
TTM_UPDATE                                      equ     (WM_USER+29)
TTM_GETBUBBLESIZE                               equ     (WM_USER+30)
TTM_ADJUSTRECT                                  equ     (WM_USER+31)
TTM_SETTITLEA                                   equ     (WM_USER+32)
TTM_SETTITLEW                                   equ     (WM_USER+33)
TTM_POPUP                                       equ     (WM_USER+34)
TTM_GETTITLE                                    equ     (WM_USER+35)
TTM_SETWINDOWTHEME                              equ     CCM_SETWINDOWTHEME

TTM_ADDTOOLW                                    equ     (WM_USER+50)
TTM_DELTOOLW                                    equ     (WM_USER+51)
TTM_NEWTOOLRECTW                                equ     (WM_USER+52)
TTM_GETTOOLINFOW                                equ     (WM_USER+53)
TTM_SETTOOLINFOW                                equ     (WM_USER+54)
TTM_HITTESTW                                    equ     (WM_USER+55)
TTM_GETTEXTW                                    equ     (WM_USER+56)
TTM_UPDATETIPTEXTW                              equ     (WM_USER+57)
TTM_ENUMTOOLSW                                  equ     (WM_USER+58)
TTM_GETCURRENTTOOLW                             equ     (WM_USER+59)

TTN_GETDISPINFOA                                equ     (TTN_FIRST-0)
TTN_GETDISPINFOW                                equ     (TTN_FIRST-10)
TTN_NEEDTEXTA                                   equ     TTN_GETDISPINFOA
TTN_NEEDTEXTW                                   equ     TTN_GETDISPINFOW
TTN_SHOW                                        equ     (TTN_FIRST-1)
TTN_POP                                         equ     (TTN_FIRST-2)
TTN_LINKCLICK                                   equ     (TTN_FIRST-3)

;======================================== StatusBar =======================================;
SBARS_SIZEGRIP                                  equ     0100H
SBARS_TOOLTIPS                                  equ     0800H

SB_SETTEXTA                                     equ     (WM_USER+1)
SB_SETTEXTW                                     equ     (WM_USER+11)
SB_GETTEXTA                                     equ     (WM_USER+2)
SB_GETTEXTW                                     equ     (WM_USER+13)
SB_GETTEXTLENGTHA                               equ     (WM_USER+3)
SB_GETTEXTLENGTHW                               equ     (WM_USER+12)

SB_SETPARTS                                     equ     (WM_USER+4)
SB_GETPARTS                                     equ     (WM_USER+6)
SB_GETBORDERS                                   equ     (WM_USER+7)
SB_SETMINHEIGHT                                 equ     (WM_USER+8)
SB_SIMPLE                                       equ     (WM_USER+9)
SB_GETRECT                                      equ     (WM_USER+10)
SB_ISSIMPLE                                     equ     (WM_USER+14)
SB_SETICON                                      equ     (WM_USER+15)
SB_SETTIPTEXTA                                  equ     (WM_USER+16)
SB_SETTIPTEXTW                                  equ     (WM_USER+17)
SB_GETTIPTEXTA                                  equ     (WM_USER+18)
SB_GETTIPTEXTW                                  equ     (WM_USER+19)
SB_GETICON                                      equ     (WM_USER+20)
SB_SETUNICODEFORMAT                             equ     CCM_SETUNICODEFORMAT
SB_GETUNICODEFORMAT                             equ     CCM_GETUNICODEFORMAT

SBT_OWNERDRAW                                   equ     1000H
SBT_NOBORDERS                                   equ     0100H
SBT_POPOUT                                      equ     0200H
SBT_RTLREADING                                  equ     0400H
SBT_TOOLTIPS                                    equ     0800H
SBT_NOTABPARSING                                equ     0800H

SB_SETBKCOLOR                                   equ     CCM_SETBKCOLOR

SBN_SIMPLEMODECHANGE                            equ     (SBN_FIRST-0)

SB_SIMPLEID                                     equ     00FFH

MINSYSCOMMAND                                   equ     0F000H

;======================================== TrackBar ========================================;
TBS_AUTOTICKS                                   equ     00001H
TBS_VERT                                        equ     00002H
TBS_HORZ                                        equ     00000H
TBS_TOP                                         equ     00004H
TBS_BOTTOM                                      equ     00000H
TBS_LEFT                                        equ     00004H
TBS_RIGHT                                       equ     00000H
TBS_BOTH                                        equ     00008H
TBS_NOTICKS                                     equ     00010H
TBS_ENABLESELRANGE                              equ     00020H
TBS_FIXEDLENGTH                                 equ     00040H
TBS_NOTHUMB                                     equ     00080H
TBS_TOOLTIPS                                    equ     00100H
TBS_REVERSED                                    equ     00200H
TBS_DOWNISLEFT                                  equ     00400H
TBS_NOTIFYBEFOREMOVE                            equ     00800H
TBS_TRANSPARENTBKGND                            equ     01000H

TBM_GETPOS                                      equ     WM_USER
TBM_GETRANGEMIN                                 equ     (WM_USER+1)
TBM_GETRANGEMAX                                 equ     (WM_USER+2)
TBM_GETTIC                                      equ     (WM_USER+3)
TBM_SETTIC                                      equ     (WM_USER+4)
TBM_SETPOS                                      equ     (WM_USER+5)
TBM_SETRANGE                                    equ     (WM_USER+6)
TBM_SETRANGEMIN                                 equ     (WM_USER+7)
TBM_SETRANGEMAX                                 equ     (WM_USER+8)
TBM_CLEARTICS                                   equ     (WM_USER+9)
TBM_SETSEL                                      equ     (WM_USER+10)
TBM_SETSELSTART                                 equ     (WM_USER+11)
TBM_SETSELEND                                   equ     (WM_USER+12)
TBM_GETPTICS                                    equ     (WM_USER+14)
TBM_GETTICPOS                                   equ     (WM_USER+15)
TBM_GETNUMTICS                                  equ     (WM_USER+16)
TBM_GETSELSTART                                 equ     (WM_USER+17)
TBM_GETSELEND                                   equ     (WM_USER+18)
TBM_CLEARSEL                                    equ     (WM_USER+19)
TBM_SETTICFREQ                                  equ     (WM_USER+20)
TBM_SETPAGESIZE                                 equ     (WM_USER+21)
TBM_GETPAGESIZE                                 equ     (WM_USER+22)
TBM_SETLINESIZE                                 equ     (WM_USER+23)
TBM_GETLINESIZE                                 equ     (WM_USER+24)
TBM_GETTHUMBRECT                                equ     (WM_USER+25)
TBM_GETCHANNELRECT                              equ     (WM_USER+26)
TBM_SETTHUMBLENGTH                              equ     (WM_USER+27)
TBM_GETTHUMBLENGTH                              equ     (WM_USER+28)
TBM_SETTOOLTIPS                                 equ     (WM_USER+29)
TBM_GETTOOLTIPS                                 equ     (WM_USER+30)
TBM_SETTIPSIDE                                  equ     (WM_USER+31)
TBM_SETBUDDY                                    equ     (WM_USER+32)
TBM_GETBUDDY                                    equ     (WM_USER+33)
TBM_SETUNICODEFORMAT                            equ     CCM_SETUNICODEFORMAT
TBM_GETUNICODEFORMAT                            equ     CCM_GETUNICODEFORMAT

TBTS_TOP                                        equ     0
TBTS_LEFT                                       equ     1
TBTS_BOTTOM                                     equ     2
TBTS_RIGHT                                      equ     3

TB_LINEUP                                       equ     0
TB_LINEDOWN                                     equ     1
TB_PAGEUP                                       equ     2
TB_PAGEDOWN                                     equ     3
TB_THUMBPOSITION                                equ     4
TB_THUMBTRACK                                   equ     5
TB_TOP                                          equ     6
TB_BOTTOM                                       equ     7
TB_ENDTRACK                                     equ     8

TBCD_TICS                                       equ     00001H
TBCD_THUMB                                      equ     00002H
TBCD_CHANNEL                                    equ     00003H

TRBN_FIRST                                      equ     (-1501)
TRBN_THUMBPOSCHANGING                           equ     (TRBN_FIRST-1)

DL_BEGINDRAG                                    equ     (WM_USER+133)
DL_DRAGGING                                     equ     (WM_USER+134)
DL_DROPPED                                      equ     (WM_USER+135)
DL_CANCELDRAG                                   equ     (WM_USER+136)

DL_CURSORSET                                    equ     0
DL_STOPCURSOR                                   equ     1
DL_COPYCURSOR                                   equ     2
DL_MOVECURSOR                                   equ     3

;========================================== UpDown ========================================;
UD_MAXVAL                                       equ     07FFFH
UD_MINVAL                                       equ     (-UD_MAXVAL)

UDS_WRAP                                        equ     00001H
UDS_SETBUDDYINT                                 equ     00002H
UDS_ALIGNRIGHT                                  equ     00004H
UDS_ALIGNLEFT                                   equ     00008H
UDS_AUTOBUDDY                                   equ     00010H
UDS_ARROWKEYS                                   equ     00020H
UDS_HORZ                                        equ     00040H
UDS_NOTHOUSANDS                                 equ     00080H
UDS_HOTTRACK                                    equ     00100H

UDM_SETRANGE                                    equ     (WM_USER+101)
UDM_GETRANGE                                    equ     (WM_USER+102)
UDM_SETPOS                                      equ     (WM_USER+103)
UDM_GETPOS                                      equ     (WM_USER+104)
UDM_SETBUDDY                                    equ     (WM_USER+105)
UDM_GETBUDDY                                    equ     (WM_USER+106)
UDM_SETACCEL                                    equ     (WM_USER+107)
UDM_GETACCEL                                    equ     (WM_USER+108)
UDM_SETBASE                                     equ     (WM_USER+109)
UDM_GETBASE                                     equ     (WM_USER+110)
UDM_SETRANGE32                                  equ     (WM_USER+111)
UDM_GETRANGE32                                  equ     (WM_USER+112)
UDM_SETUNICODEFORMAT                            equ     CCM_SETUNICODEFORMAT
UDM_GETUNICODEFORMAT                            equ     CCM_GETUNICODEFORMAT
UDM_SETPOS32                                    equ     (WM_USER+113)
UDM_GETPOS32                                    equ     (WM_USER+114)

UDN_DELTAPOS                                    equ     (UDN_FIRST-1)

;======================================= ProgressBar ======================================;
PBS_SMOOTH                                      equ     001H
PBS_VERTICAL                                    equ     004H
PBS_MARQUEE                                     equ     008H
PBS_SMOOTHREVERSE                               equ     010H

PBM_SETRANGE                                    equ     (WM_USER+1)
PBM_SETPOS                                      equ     (WM_USER+2)
PBM_DELTAPOS                                    equ     (WM_USER+3)
PBM_SETSTEP                                     equ     (WM_USER+4)
PBM_STEPIT                                      equ     (WM_USER+5)
PBM_SETRANGE32                                  equ     (WM_USER+6)
PBM_GETRANGE                                    equ     (WM_USER+7)
PBM_GETPOS                                      equ     (WM_USER+8)
PBM_SETBARCOLOR                                 equ     (WM_USER+9)
PBM_SETBKCOLOR                                  equ     CCM_SETBKCOLOR
PBM_SETMARQUEE                                  equ     (WM_USER+10)
PBM_GETSTEP                                     equ     (WM_USER+13)
PBM_GETBKCOLOR                                  equ     (WM_USER+14)
PBM_GETBARCOLOR                                 equ     (WM_USER+15)
PBM_SETSTATE                                    equ     (WM_USER+16)
PBM_GETSTATE                                    equ     (WM_USER+17)

;======================================= HotKey ======================================;
HOTKEYF_SHIFT                                   equ     001H
HOTKEYF_CONTROL                                 equ     002H
HOTKEYF_ALT                                     equ     004H
HOTKEYF_EXT                                     equ     008H

HKCOMB_NONE                                     equ     00001H
HKCOMB_S                                        equ     00002H
HKCOMB_C                                        equ     00004H
HKCOMB_A                                        equ     00008H
HKCOMB_SC                                       equ     00010H
HKCOMB_SA                                       equ     00020H
HKCOMB_CA                                       equ     00040H
HKCOMB_SCA                                      equ     00080H

HKM_SETHOTKEY                                   equ     (WM_USER+1)
HKM_GETHOTKEY                                   equ     (WM_USER+2)
HKM_SETRULES                                    equ     (WM_USER+3)

CCS_TOP                                         equ     000000001H
CCS_NOMOVEY                                     equ     000000002H
CCS_BOTTOM                                      equ     000000003H
CCS_NORESIZE                                    equ     000000004H
CCS_NOPARENTALIGN                               equ     000000008H
CCS_ADJUSTABLE                                  equ     000000020H
CCS_NODIVIDER                                   equ     000000040H
CCS_VERT                                        equ     000000080H
CCS_LEFT                                        equ     <CCS_VERT or CCS_TOP>
CCS_RIGHT                                       equ     <CCS_VERT or CCS_BOTTOM>
CCS_NOMOVEX                                     equ     <CCS_VERT or CCS_NOMOVEY>

;========================================= ListView =======================================;
LVS_ICON                                        equ     00000H
LVS_REPORT                                      equ     00001H
LVS_SMALLICON                                   equ     00002H
LVS_LIST                                        equ     00003H
LVS_TYPEMASK                                    equ     00003H
LVS_SINGLESEL                                   equ     00004H
LVS_SHOWSELALWAYS                               equ     00008H
LVS_SORTASCENDING                               equ     00010H
LVS_SORTDESCENDING                              equ     00020H
LVS_SHAREIMAGELISTS                             equ     00040H
LVS_NOLABELWRAP                                 equ     00080H
LVS_AUTOARRANGE                                 equ     00100H
LVS_EDITLABELS                                  equ     00200H
LVS_OWNERDATA                                   equ     01000H
LVS_NOSCROLL                                    equ     02000H
LVS_TYPESTYLEMASK                               equ     0FC00H
LVS_ALIGNTOP                                    equ     00000H
LVS_ALIGNLEFT                                   equ     00800H
LVS_ALIGNMASK                                   equ     00C00H
LVS_OWNERDRAWFIXED                              equ     00400H
LVS_NOCOLUMNHEADER                              equ     04000H
LVS_NOSORTHEADER                                equ     08000H

LVS_EX_GRIDLINES                                equ     000000001H
LVS_EX_SUBITEMIMAGES                            equ     000000002H
LVS_EX_CHECKBOXES                               equ     000000004H
LVS_EX_TRACKSELECT                              equ     000000008H
LVS_EX_HEADERDRAGDROP                           equ     000000010H
LVS_EX_FULLROWSELECT                            equ     000000020H
LVS_EX_ONECLICKACTIVATE                         equ     000000040H
LVS_EX_TWOCLICKACTIVATE                         equ     000000080H
LVS_EX_FLATSB                                   equ     000000100H
LVS_EX_REGIONAL                                 equ     000000200H
LVS_EX_INFOTIP                                  equ     000000400H
LVS_EX_UNDERLINEHOT                             equ     000000800H
LVS_EX_UNDERLINECOLD                            equ     000001000H
LVS_EX_MULTIWORKAREAS                           equ     000002000H
LVS_EX_LABELTIP                                 equ     000004000H
LVS_EX_BORDERSELECT                             equ     000008000H
LVS_EX_DOUBLEBUFFER                             equ     000010000H
LVS_EX_HIDELABELS                               equ     000020000H
LVS_EX_SINGLEROW                                equ     000040000H
LVS_EX_SNAPTOGRID                               equ     000080000H
LVS_EX_SIMPLESELECT                             equ     000100000H
LVS_EX_JUSTIFYCOLUMNS                           equ     000200000H
LVS_EX_TRANSPARENTBKGND                         equ     000400000H
LVS_EX_TRANSPARENTSHADOWTEXT                    equ     000800000H
LVS_EX_AUTOAUTOARRANGE                          equ     001000000H
LVS_EX_HEADERINALLVIEWS                         equ     002000000H
LVS_EX_AUTOCHECKSELECT                          equ     008000000H
LVS_EX_AUTOSIZECOLUMNS                          equ     010000000H
LVS_EX_COLUMNSNAPPOINTS                         equ     040000000H
LVS_EX_COLUMNOVERFLOW                           equ     080000000H

LVSIL_NORMAL                                    equ     0
LVSIL_SMALL                                     equ     1
LVSIL_STATE                                     equ     2

LVIF_TEXT                                       equ     00001H
LVIF_IMAGE                                      equ     00002H
LVIF_PARAM                                      equ     00004H
LVIF_STATE                                      equ     00008H
LVIF_INDENT                                     equ     00010H
LVIF_NORECOMPUTE                                equ     00800H
LVIF_GROUPID                                    equ     00100H
LVIF_COLUMNS                                    equ     00200H
LVIF_COLFMT                                     equ     000010000H

LVIS_FOCUSED                                    equ     00001H
LVIS_SELECTED                                   equ     00002H
LVIS_CUT                                        equ     00004H
LVIS_DROPHILITED                                equ     00008H
LVIS_ACTIVATING                                 equ     00020H

LVIS_OVERLAYMASK                                equ     00F00H
LVIS_STATEIMAGEMASK                             equ     0F000H

LPSTR_TEXTCALLBACKW                             equ     (-1)
LPSTR_TEXTCALLBACKA                             equ     (-1)

I_INDENTCALLBACK                                equ     (-1)
I_IMAGECALLBACK                                 equ     (-1)
I_IMAGENONE                                     equ     (-2)

I_GROUPIDCALLBACK                               equ     (-1)
I_GROUPIDNONE                                   equ     (-2)

LVM_GETBKCOLOR                                  equ     (LVM_FIRST+0)
LVM_SETBKCOLOR                                  equ     (LVM_FIRST+1)
LVM_GETIMAGELIST                                equ     (LVM_FIRST+2)
LVM_SETIMAGELIST                                equ     (LVM_FIRST+3)
LVM_GETITEMCOUNT                                equ     (LVM_FIRST+4)
LVM_GETITEMA                                    equ     (LVM_FIRST+5)
LVM_SETITEMA                                    equ     (LVM_FIRST+6)
LVM_INSERTITEMA                                 equ     (LVM_FIRST+7)
LVM_DELETEITEM                                  equ     (LVM_FIRST+8)
LVM_DELETEALLITEMS                              equ     (LVM_FIRST+9)
LVM_GETCALLBACKMASK                             equ     (LVM_FIRST+10)
LVM_SETCALLBACKMASK                             equ     (LVM_FIRST+11)
LVM_GETNEXTITEM                                 equ     (LVM_FIRST+12)
LVM_FINDITEMA                                   equ     (LVM_FIRST+13)
LVM_GETITEMRECT                                 equ     (LVM_FIRST+14)
LVM_SETITEMPOSITION                             equ     (LVM_FIRST+15)
LVM_GETITEMPOSITION                             equ     (LVM_FIRST+16)
LVM_GETSTRINGWIDTHA                             equ     (LVM_FIRST+17)
LVM_HITTEST                                     equ     (LVM_FIRST+18)
LVM_ENSUREVISIBLE                               equ     (LVM_FIRST+19)
LVM_SCROLL                                      equ     (LVM_FIRST+20)
LVM_REDRAWITEMS                                 equ     (LVM_FIRST+21)
LVM_ARRANGE                                     equ     (LVM_FIRST+22)
LVM_EDITLABELA                                  equ     (LVM_FIRST+23)
LVM_GETEDITCONTROL                              equ     (LVM_FIRST+24)
LVM_GETCOLUMNA                                  equ     (LVM_FIRST+25)
LVM_SETCOLUMNA                                  equ     (LVM_FIRST+26)
LVM_INSERTCOLUMNA                               equ     (LVM_FIRST+27)
LVM_DELETECOLUMN                                equ     (LVM_FIRST+28)
LVM_GETCOLUMNWIDTH                              equ     (LVM_FIRST+29)
LVM_SETCOLUMNWIDTH                              equ     (LVM_FIRST+30)
LVM_GETHEADER                                   equ     (LVM_FIRST+31)
LVM_CREATEDRAGIMAGE                             equ     (LVM_FIRST+33)
LVM_GETVIEWRECT                                 equ     (LVM_FIRST+34)
LVM_GETTEXTCOLOR                                equ     (LVM_FIRST+35)
LVM_SETTEXTCOLOR                                equ     (LVM_FIRST+36)
LVM_GETTEXTBKCOLOR                              equ     (LVM_FIRST+37)
LVM_SETTEXTBKCOLOR                              equ     (LVM_FIRST+38)
LVM_GETTOPINDEX                                 equ     (LVM_FIRST+39)
LVM_GETCOUNTPERPAGE                             equ     (LVM_FIRST+40)
LVM_GETORIGIN                                   equ     (LVM_FIRST+41)
LVM_UPDATE                                      equ     (LVM_FIRST+42)
LVM_SETITEMSTATE                                equ     (LVM_FIRST+43)
LVM_GETITEMSTATE                                equ     (LVM_FIRST+44)
LVM_GETITEMTEXTA                                equ     (LVM_FIRST+45)
LVM_SETITEMTEXTA                                equ     (LVM_FIRST+46)
LVM_SETITEMCOUNT                                equ     (LVM_FIRST+47)
LVM_SORTITEMS                                   equ     (LVM_FIRST+48)
LVM_SETITEMPOSITION32                           equ     (LVM_FIRST+49)
LVM_GETSELECTEDCOUNT                            equ     (LVM_FIRST+50)
LVM_GETITEMSPACING                              equ     (LVM_FIRST+51)
LVM_GETISEARCHSTRINGA                           equ     (LVM_FIRST+52)
LVM_SETICONSPACING                              equ     (LVM_FIRST+53)
LVM_SETEXTENDEDLISTVIEWSTYLE                    equ     (LVM_FIRST+54)
LVM_GETEXTENDEDLISTVIEWSTYLE                    equ     (LVM_FIRST+55)
LVM_GETSUBITEMRECT                              equ     (LVM_FIRST+56)
LVM_SUBITEMHITTEST                              equ     (LVM_FIRST+57)
LVM_SETCOLUMNORDERARRAY                         equ     (LVM_FIRST+58)
LVM_GETCOLUMNORDERARRAY                         equ     (LVM_FIRST+59)
LVM_SETHOTITEM                                  equ     (LVM_FIRST+60)
LVM_GETHOTITEM                                  equ     (LVM_FIRST+61)
LVM_SETHOTCURSOR                                equ     (LVM_FIRST+62)
LVM_GETHOTCURSOR                                equ     (LVM_FIRST+63)
LVM_APPROXIMATEVIEWRECT                         equ     (LVM_FIRST+64)
LVM_SETWORKAREAS                                equ     (LVM_FIRST+65)
LVM_GETSELECTIONMARK                            equ     (LVM_FIRST+66)
LVM_SETSELECTIONMARK                            equ     (LVM_FIRST+67)
LVM_SETBKIMAGEA                                 equ     (LVM_FIRST+68)
LVM_GETBKIMAGEA                                 equ     (LVM_FIRST+69)
LVM_GETWORKAREAS                                equ     (LVM_FIRST+70)
LVM_SETHOVERTIME                                equ     (LVM_FIRST+71)
LVM_GETHOVERTIME                                equ     (LVM_FIRST+72)
LVM_GETNUMBEROFWORKAREAS                        equ     (LVM_FIRST+73)
LVM_SETTOOLTIPS                                 equ     (LVM_FIRST+74)
LVM_GETITEMW                                    equ     (LVM_FIRST+75)
LVM_SETITEMW                                    equ     (LVM_FIRST+76)
LVM_INSERTITEMW                                 equ     (LVM_FIRST+77)
LVM_GETTOOLTIPS                                 equ     (LVM_FIRST+78)
LVM_SORTITEMSEX                                 equ     (LVM_FIRST+81)
LVM_FINDITEMW                                   equ     (LVM_FIRST+83)
LVM_GETSTRINGWIDTHW                             equ     (LVM_FIRST+87)
LVM_GETCOLUMNW                                  equ     (LVM_FIRST+95)
LVM_SETCOLUMNW                                  equ     (LVM_FIRST+96)
LVM_INSERTCOLUMNW                               equ     (LVM_FIRST+97)

LVM_GETITEMTEXTW                                equ     (LVM_FIRST+115)
LVM_SETITEMTEXTW                                equ     (LVM_FIRST+116)
LVM_GETISEARCHSTRINGW                           equ     (LVM_FIRST+117)
LVM_EDITLABELW                                  equ     (LVM_FIRST+118)
LVM_SETBKIMAGEW                                 equ     (LVM_FIRST+138)
LVM_GETBKIMAGEW                                 equ     (LVM_FIRST+139)
LVM_SETSELECTEDCOLUMN                           equ     (LVM_FIRST+140)
LVM_SETTILEWIDTH                                equ     (LVM_FIRST+141)
LVM_SETVIEW                                     equ     (LVM_FIRST+142)
LVM_GETVIEW                                     equ     (LVM_FIRST+143)
LVM_INSERTGROUP                                 equ     (LVM_FIRST+145)
LVM_SETGROUPINFO                                equ     (LVM_FIRST+147)
LVM_GETGROUPINFO                                equ     (LVM_FIRST+149)
LVM_REMOVEGROUP                                 equ     (LVM_FIRST+150)
LVM_MOVEGROUP                                   equ     (LVM_FIRST+151)
LVM_MOVEITEMTOGROUP                             equ     (LVM_FIRST+154)
LVM_SETGROUPMETRICS                             equ     (LVM_FIRST+155)
LVM_GETGROUPMETRICS                             equ     (LVM_FIRST+156)
LVM_ENABLEGROUPVIEW                             equ     (LVM_FIRST+157)
LVM_SORTGROUPS                                  equ     (LVM_FIRST+158)
LVM_INSERTGROUPSORTED                           equ     (LVM_FIRST+159)
LVM_REMOVEALLGROUPS                             equ     (LVM_FIRST+160)
LVM_HASGROUP                                    equ     (LVM_FIRST+161)
LVM_SETTILEVIEWINFO                             equ     (LVM_FIRST+162)
LVM_GETTILEVIEWINFO                             equ     (LVM_FIRST+163)
LVM_SETTILEINFO                                 equ     (LVM_FIRST+164)
LVM_GETTILEINFO                                 equ     (LVM_FIRST+165)
LVM_SETINSERTMARK                               equ     (LVM_FIRST+166)
LVM_GETINSERTMARK                               equ     (LVM_FIRST+167)
LVM_INSERTMARKHITTEST                           equ     (LVM_FIRST+168)
LVM_GETINSERTMARKRECT                           equ     (LVM_FIRST+169)
LVM_SETINSERTMARKCOLOR                          equ     (LVM_FIRST+170)
LVM_GETINSERTMARKCOLOR                          equ     (LVM_FIRST+171)
LVM_SETINFOTIP                                  equ     (LVM_FIRST+173)
LVM_GETSELECTEDCOLUMN                           equ     (LVM_FIRST+174)
LVM_ISGROUPVIEWENABLED                          equ     (LVM_FIRST+175)
LVM_GETOUTLINECOLOR                             equ     (LVM_FIRST+176)
LVM_SETOUTLINECOLOR                             equ     (LVM_FIRST+177)
LVM_CANCELEDITLABEL                             equ     (LVM_FIRST+179)
LVM_MAPINDEXTOID                                equ     (LVM_FIRST+180)
LVM_MAPIDTOINDEX                                equ     (LVM_FIRST+181)
LVM_ISITEMVISIBLE                               equ     (LVM_FIRST+182)
LVM_GETEMPTYTEXT                                equ     (LVM_FIRST+204)
LVM_GETFOOTERRECT                               equ     (LVM_FIRST+205)
LVM_GETFOOTERINFO                               equ     (LVM_FIRST+206)
LVM_GETFOOTERITEMRECT                           equ     (LVM_FIRST+207)
LVM_GETFOOTERITEM                               equ     (LVM_FIRST+208)
LVM_GETITEMINDEXRECT                            equ     (LVM_FIRST+209)
LVM_SETITEMINDEXSTATE                           equ     (LVM_FIRST+210)
LVM_GETNEXTITEMINDEX                            equ     (LVM_FIRST+211)
LVM_SETUNICODEFORMAT                            equ     CCM_SETUNICODEFORMAT
LVM_GETUNICODEFORMAT                            equ     CCM_GETUNICODEFORMAT

LVNI_ALL                                        equ     00000H
LVNI_FOCUSED                                    equ     00001H
LVNI_SELECTED                                   equ     00002H
LVNI_CUT                                        equ     00004H
LVNI_DROPHILITED                                equ     00008H

LVNI_ABOVE                                      equ     00100H
LVNI_BELOW                                      equ     00200H
LVNI_TOLEFT                                     equ     00400H
LVNI_TORIGHT                                    equ     00800H

LVFI_PARAM                                      equ     00001H
LVFI_STRING                                     equ     00002H
LVFI_PARTIAL                                    equ     00008H
LVFI_WRAP                                       equ     00020H
LVFI_NEARESTXY                                  equ     00040H

LVIR_BOUNDS                                     equ     0
LVIR_ICON                                       equ     1
LVIR_LABEL                                      equ     2
LVIR_SELECTBOUNDS                               equ     3

LVHT_NOWHERE                                    equ     00001H
LVHT_ONITEMICON                                 equ     00002H
LVHT_ONITEMLABEL                                equ     00004H
LVHT_ONITEMSTATEICON                            equ     00008H
LVHT_ONITEM                                     equ     <LVHT_ONITEMICON or LVHT_ONITEMLABEL or LVHT_ONITEMSTATEICON>

LVHT_ABOVE                                      equ     00008H
LVHT_BELOW                                      equ     00010H
LVHT_TORIGHT                                    equ     00020H
LVHT_TOLEFT                                     equ     00040H

LVHT_EX_GROUP_HEADER                            equ     010000000H
LVHT_EX_GROUP_FOOTER                            equ     020000000H
LVHT_EX_GROUP_COLLAPSE                          equ     040000000H
LVHT_EX_GROUP_BACKGROUND                        equ     080000000H
LVHT_EX_GROUP_STATEICON                         equ     001000000H
LVHT_EX_GROUP_SUBSETLINK                        equ     002000000H
LVHT_EX_GROUP                                   equ     <LVHT_EX_GROUP_BACKGROUND or LVHT_EX_GROUP_COLLAPSE or LVHT_EX_GROUP_FOOTER or LVHT_EX_GROUP_HEADER or LVHT_EX_GROUP_STATEICON or LVHT_EX_GROUP_SUBSETLINK>
LVHT_EX_ONCONTENTS                              equ     004000000H
LVHT_EX_FOOTER                                  equ     008000000H

LVA_DEFAULT                                     equ     00000H
LVA_ALIGNLEFT                                   equ     00001H
LVA_ALIGNTOP                                    equ     00002H
LVA_SNAPTOGRID                                  equ     00005H

LVCF_FMT                                        equ     00001H
LVCF_WIDTH                                      equ     00002H
LVCF_TEXT                                       equ     00004H
LVCF_SUBITEM                                    equ     00008H
LVCF_IMAGE                                      equ     00010H
LVCF_ORDER                                      equ     00020H
LVCF_MINWIDTH                                   equ     00040H
LVCF_DEFAULTWIDTH                               equ     00080H
LVCF_IDEALWIDTH                                 equ     00100H

LVCFMT_LEFT                                     equ     00000H
LVCFMT_RIGHT                                    equ     00001H
LVCFMT_CENTER                                   equ     00002H
LVCFMT_JUSTIFYMASK                              equ     00003H
LVCFMT_IMAGE                                    equ     00800H
LVCFMT_FIXED_WIDTH                              equ     00100H
LVCFMT_BITMAP_ON_RIGHT                          equ     01000H
LVCFMT_COL_HAS_IMAGES                           equ     08000H

LVCFMT_NO_DPI_SCALE                             equ     0040000H
LVCFMT_FIXED_RATIO                              equ     0080000H
LVCFMT_LINE_BREAK                               equ     0100000H
LVCFMT_FILL                                     equ     0200000H
LVCFMT_WRAP                                     equ     0400000H
LVCFMT_NO_TITLE                                 equ     0800000H
LVCFMT_TILE_PLACEMENTMASK                       equ     <LVCFMT_LINE_BREAK or LVCFMT_FILL>
LVCFMT_SPLITBUTTON                              equ     01000000H

LVSCW_AUTOSIZE                                  equ     (-1)
LVSCW_AUTOSIZE_USEHEADER                        equ     (-2)

LVSICF_NOINVALIDATEALL                          equ     000000001H
LVSICF_NOSCROLL                                 equ     000000002H

LV_MAX_WORKAREAS                                equ     16

LVBKIF_SOURCE_NONE                              equ     000000000H
LVBKIF_SOURCE_HBITMAP                           equ     000000001H
LVBKIF_SOURCE_URL                               equ     000000002H
LVBKIF_SOURCE_MASK                              equ     000000003H
LVBKIF_STYLE_NORMAL                             equ     000000000H
LVBKIF_STYLE_TILE                               equ     000000010H
LVBKIF_STYLE_MASK                               equ     000000010H
LVBKIF_FLAG_TILEOFFSET                          equ     000000100H
LVBKIF_TYPE_WATERMARK                           equ     010000000H
LVBKIF_FLAG_ALPHABLEND                          equ     020000000H

LVKF_ALT                                        equ     00001H
LVKF_CONTROL                                    equ     00002H
LVKF_SHIFT                                      equ     00004H

LV_VIEW_ICON                                    equ     00000H
LV_VIEW_DETAILS                                 equ     00001H
LV_VIEW_SMALLICON                               equ     00002H
LV_VIEW_LIST                                    equ     00003H
LV_VIEW_TILE                                    equ     00004H
LV_VIEW_MAX                                     equ     00004H

LVGF_NONE                                       equ     000000000H
LVGF_HEADER                                     equ     000000001H
LVGF_FOOTER                                     equ     000000002H
LVGF_STATE                                      equ     000000004H
LVGF_ALIGN                                      equ     000000008H
LVGF_GROUPID                                    equ     000000010H
LVGF_SUBTITLE                                   equ     000000100H
LVGF_TASK                                       equ     000000200H
LVGF_DESCRIPTIONTOP                             equ     000000400H
LVGF_DESCRIPTIONBOTTOM                          equ     000000800H
LVGF_TITLEIMAGE                                 equ     000001000H
LVGF_EXTENDEDIMAGE                              equ     000002000H
LVGF_ITEMS                                      equ     000004000H
LVGF_SUBSET                                     equ     000008000H
LVGF_SUBSETITEMS                                equ     000010000H

LVGS_NORMAL                                     equ     000000000H
LVGS_COLLAPSED                                  equ     000000001H
LVGS_HIDDEN                                     equ     000000002H
LVGS_NOHEADER                                   equ     000000004H
LVGS_COLLAPSIBLE                                equ     000000008H
LVGS_FOCUSED                                    equ     000000010H
LVGS_SELECTED                                   equ     000000020H
LVGS_SUBSETED                                   equ     000000040H
LVGS_SUBSETLINKFOCUSED                          equ     000000080H

LVGA_HEADER_LEFT                                equ     000000001H
LVGA_HEADER_CENTER                              equ     000000002H
LVGA_HEADER_RIGHT                               equ     000000004H
LVGA_FOOTER_LEFT                                equ     000000008H
LVGA_FOOTER_CENTER                              equ     000000010H
LVGA_FOOTER_RIGHT                               equ     000000020H

LVGMF_NONE                                      equ     000000000H
LVGMF_BORDERSIZE                                equ     000000001H
LVGMF_BORDERCOLOR                               equ     000000002H
LVGMF_TEXTCOLOR                                 equ     000000004H

LVTVIF_AUTOSIZE                                 equ     000000000H
LVTVIF_FIXEDWIDTH                               equ     000000001H
LVTVIF_FIXEDHEIGHT                              equ     000000002H
LVTVIF_FIXEDSIZE                                equ     000000003H
LVTVIF_EXTENDED                                 equ     000000004H

LVTVIM_TILESIZE                                 equ     000000001H
LVTVIM_COLUMNS                                  equ     000000002H
LVTVIM_LABELMARGIN                              equ     000000004H

LVN_ITEMCHANGING                                equ     (LVN_FIRST-0)
LVN_ITEMCHANGED                                 equ     (LVN_FIRST-1)
LVN_INSERTITEM                                  equ     (LVN_FIRST-2)
LVN_DELETEITEM                                  equ     (LVN_FIRST-3)
LVN_DELETEALLITEMS                              equ     (LVN_FIRST-4)
LVN_BEGINLABELEDITA                             equ     (LVN_FIRST-5)
LVN_ENDLABELEDITA                               equ     (LVN_FIRST-6)
LVN_COLUMNCLICK                                 equ     (LVN_FIRST-8)
LVN_BEGINDRAG                                   equ     (LVN_FIRST-9)
LVN_BEGINRDRAG                                  equ     (LVN_FIRST-11)
LVN_ODCACHEHINT                                 equ     (LVN_FIRST-13)
LVN_ITEMACTIVATE                                equ     (LVN_FIRST-14)
LVN_ODSTATECHANGED                              equ     (LVN_FIRST-15)
LVN_HOTTRACK                                    equ     (LVN_FIRST-21)
LVN_GETDISPINFOA                                equ     (LVN_FIRST-50)
LVN_SETDISPINFOA                                equ     (LVN_FIRST-51)
LVN_ODFINDITEMA                                 equ     (LVN_FIRST-52)
LVN_KEYDOWN                                     equ     (LVN_FIRST-55)
LVN_MARQUEEBEGIN                                equ     (LVN_FIRST-56)
LVN_GETINFOTIPA                                 equ     (LVN_FIRST-57)
LVN_GETINFOTIPW                                 equ     (LVN_FIRST-58)
LVN_INCREMENTALSEARCHA                          equ     (LVN_FIRST-62)
LVN_INCREMENTALSEARCHW                          equ     (LVN_FIRST-63)
LVN_COLUMNDROPDOWN                              equ     (LVN_FIRST-64)
LVN_COLUMNOVERFLOWCLICK                         equ     (LVN_FIRST-66)
LVN_BEGINLABELEDITW                             equ     (LVN_FIRST-75)
LVN_ENDLABELEDITW                               equ     (LVN_FIRST-76)
LVN_GETDISPINFOW                                equ     (LVN_FIRST-77)
LVN_SETDISPINFOW                                equ     (LVN_FIRST-78)
LVN_ODFINDITEMW                                 equ     (LVN_FIRST-79)
LVN_BEGINSCROLL                                 equ     (LVN_FIRST-80)
LVN_ENDSCROLL                                   equ     (LVN_FIRST-81)
LVN_LINKCLICK                                   equ     (LVN_FIRST-84)
LVN_GETEMPTYMARKUP                              equ     (LVN_FIRST-87)

LVIM_AFTER                                      equ     000000001H

LVIF_DI_SETITEM                                 equ     01000H

LVGIT_UNFOLDED                                  equ     00001H

LVNSCH_DEFAULT                                  equ     (-1)
LVNSCH_ERROR                                    equ     (-2)
LVNSCH_IGNORE                                   equ     (-3)

LVFIS_FOCUSED                                   equ     00001H

LVFF_ITEMCOUNT                                  equ     000000001H

LVCDI_ITEM                                      equ     000000000H
LVCDI_GROUP                                     equ     000000001H

LVCDRF_NOSELECT                                 equ     000010000H
LVCDRF_NOGROUPFRAME                             equ     000020000H

EMF_CENTERED                                    equ     000000001H

LVFIF_TEXT                                      equ     000000001H
LVFIF_STATE                                     equ     000000002H

;========================================= TreeView =======================================;
TVS_HASBUTTONS                                  equ     00001H
TVS_HASLINES                                    equ     00002H
TVS_LINESATROOT                                 equ     00004H
TVS_EDITLABELS                                  equ     00008H
TVS_DISABLEDRAGDROP                             equ     00010H
TVS_SHOWSELALWAYS                               equ     00020H
TVS_RTLREADING                                  equ     00040H

TVS_NOTOOLTIPS                                  equ     00080H
TVS_CHECKBOXES                                  equ     00100H
TVS_TRACKSELECT                                 equ     00200H
TVS_SINGLEEXPAND                                equ     00400H
TVS_INFOTIP                                     equ     00800H
TVS_FULLROWSELECT                               equ     01000H
TVS_NOSCROLL                                    equ     02000H
TVS_NONEVENHEIGHT                               equ     04000H
TVS_NOHSCROLL                                   equ     08000H

TVS_EX_MULTISELECT                              equ     00002H
TVS_EX_DOUBLEBUFFER                             equ     00004H
TVS_EX_NOINDENTSTATE                            equ     00008H
TVS_EX_RICHTOOLTIP                              equ     00010H
TVS_EX_AUTOHSCROLL                              equ     00020H
TVS_EX_FADEINOUTEXPANDOS                        equ     00040H
TVS_EX_PARTIALCHECKBOXES                        equ     00080H
TVS_EX_EXCLUSIONCHECKBOXES                      equ     00100H
TVS_EX_DIMMEDCHECKBOXES                         equ     00200H
TVS_EX_DRAWIMAGEASYNC                           equ     00400H

TVIF_TEXT                                       equ     00001H
TVIF_IMAGE                                      equ     00002H
TVIF_PARAM                                      equ     00004H
TVIF_STATE                                      equ     00008H
TVIF_HANDLE                                     equ     00010H
TVIF_SELECTEDIMAGE                              equ     00020H
TVIF_CHILDREN                                   equ     00040H
TVIF_INTEGRAL                                   equ     00080H

TVIS_SELECTED                                   equ     00002H
TVIS_CUT                                        equ     00004H
TVIS_DROPHILITED                                equ     00008H
TVIS_BOLD                                       equ     00010H
TVIS_EXPANDED                                   equ     00020H
TVIS_EXPANDEDONCE                               equ     00040H
TVIS_EXPANDPARTIAL                              equ     00080H

TVIS_OVERLAYMASK                                equ     00F00H
TVIS_STATEIMAGEMASK                             equ     0F000H
TVIS_USERMASK                                   equ     0F000H

TVIS_EX_FLAT                                    equ     00001H
TVIS_EX_DISABLED                                equ     00002H
TVIS_EX_ALL                                     equ     00002H

I_CHILDRENCALLBACK                              equ     (-1)

TVI_ROOT                                        equ     (-010000H)
TVI_FIRST                                       equ     (-00FFFFH)
TVI_LAST                                        equ     (-00FFFEH)
TVI_SORT                                        equ     (-00FFFDH)

TVE_COLLAPSE                                    equ     00001H
TVE_EXPAND                                      equ     00002H
TVE_TOGGLE                                      equ     00003H
TVE_EXPANDPARTIAL                               equ     04000H
TVE_COLLAPSERESET                               equ     08000H

TVSIL_NORMAL                                    equ     0
TVSIL_STATE                                     equ     2

TVGN_ROOT                                       equ     00000H
TVGN_NEXT                                       equ     00001H
TVGN_PREVIOUS                                   equ     00002H
TVGN_PARENT                                     equ     00003H
TVGN_CHILD                                      equ     00004H
TVGN_FIRSTVISIBLE                               equ     00005H
TVGN_NEXTVISIBLE                                equ     00006H
TVGN_PREVIOUSVISIBLE                            equ     00007H
TVGN_DROPHILITE                                 equ     00008H
TVGN_CARET                                      equ     00009H
TVGN_LASTVISIBLE                                equ     0000AH
TVGN_NEXTSELECTED                               equ     0000BH

TV_HITTESTINFO                                  equ     TVHITTESTINFO

TVSI_NOSINGLEEXPAND                             equ     08000H

TVHT_NOWHERE                                    equ     00001H
TVHT_ONITEMICON                                 equ     00002H
TVHT_ONITEMLABEL                                equ     00004H
TVHT_ONITEM                                     equ     <TVHT_ONITEMICON or TVHT_ONITEMLABEL or TVHT_ONITEMSTATEICON>
TVHT_ONITEMINDENT                               equ     00008H
TVHT_ONITEMBUTTON                               equ     00010H
TVHT_ONITEMRIGHT                                equ     00020H
TVHT_ONITEMSTATEICON                            equ     00040H

TVHT_ABOVE                                      equ     00100H
TVHT_BELOW                                      equ     00200H
TVHT_TORIGHT                                    equ     00400H
TVHT_TOLEFT                                     equ     00800H

TVGIPR_BUTTON                                   equ     00001H

TVIF_DI_SETITEM                                 equ     01000H

TVM_INSERTITEMA                                 equ     (TV_FIRST+0)
TVM_DELETEITEM                                  equ     (TV_FIRST+1)
TVM_EXPAND                                      equ     (TV_FIRST+2)
TVM_GETITEMRECT                                 equ     (TV_FIRST+4)
TVM_GETCOUNT                                    equ     (TV_FIRST+5)
TVM_GETINDENT                                   equ     (TV_FIRST+6)
TVM_SETINDENT                                   equ     (TV_FIRST+7)
TVM_GETIMAGELIST                                equ     (TV_FIRST+8)
TVM_SETIMAGELIST                                equ     (TV_FIRST+9)
TVM_GETNEXTITEM                                 equ     (TV_FIRST+10)
TVM_SELECTITEM                                  equ     (TV_FIRST+11)
TVM_GETITEMA                                    equ     (TV_FIRST+12)
TVM_SETITEMA                                    equ     (TV_FIRST+13)
TVM_EDITLABELA                                  equ     (TV_FIRST+14)
TVM_GETEDITCONTROL                              equ     (TV_FIRST+15)
TVM_GETVISIBLECOUNT                             equ     (TV_FIRST+16)
TVM_HITTEST                                     equ     (TV_FIRST+17)
TVM_CREATEDRAGIMAGE                             equ     (TV_FIRST+18)
TVM_SORTCHILDREN                                equ     (TV_FIRST+19)
TVM_ENSUREVISIBLE                               equ     (TV_FIRST+20)
TVM_SORTCHILDRENCB                              equ     (TV_FIRST+21)
TVM_ENDEDITLABELNOW                             equ     (TV_FIRST+22)
TVM_GETISEARCHSTRINGA                           equ     (TV_FIRST+23)
TVM_SETTOOLTIPS                                 equ     (TV_FIRST+24)
TVM_GETTOOLTIPS                                 equ     (TV_FIRST+25)
TVM_SETINSERTMARK                               equ     (TV_FIRST+26)
TVM_SETITEMHEIGHT                               equ     (TV_FIRST+27)
TVM_GETITEMHEIGHT                               equ     (TV_FIRST+28)
TVM_SETBKCOLOR                                  equ     (TV_FIRST+29)
TVM_SETTEXTCOLOR                                equ     (TV_FIRST+30)
TVM_GETBKCOLOR                                  equ     (TV_FIRST+31)
TVM_GETTEXTCOLOR                                equ     (TV_FIRST+32)
TVM_SETSCROLLTIME                               equ     (TV_FIRST+33)
TVM_GETSCROLLTIME                               equ     (TV_FIRST+34)
TVM_SETINSERTMARKCOLOR                          equ     (TV_FIRST+37)
TVM_GETINSERTMARKCOLOR                          equ     (TV_FIRST+38)
TVM_GETITEMSTATE                                equ     (TV_FIRST+39)
TVM_SETLINECOLOR                                equ     (TV_FIRST+40)
TVM_GETLINECOLOR                                equ     (TV_FIRST+41)
TVM_MAPACCIDTOHTREEITEM                         equ     (TV_FIRST+42)
TVM_MAPHTREEITEMTOACCID                         equ     (TV_FIRST+43)
TVM_SETEXTENDEDSTYLE                            equ     (TV_FIRST+44)
TVM_GETEXTENDEDSTYLE                            equ     (TV_FIRST+45)
TVM_INSERTITEMW                                 equ     (TV_FIRST+50)
TVM_SETAUTOSCROLLINFO                           equ     (TV_FIRST+59)
TVM_GETITEMW                                    equ     (TV_FIRST+62)
TVM_SETITEMW                                    equ     (TV_FIRST+63)
TVM_GETISEARCHSTRINGW                           equ     (TV_FIRST+64)
TVM_EDITLABELW                                  equ     (TV_FIRST+65)
TVM_GETSELECTEDCOUNT                            equ     (TV_FIRST+70)
TVM_SHOWINFOTIP                                 equ     (TV_FIRST+71)
TVM_GETITEMPARTRECT                             equ     (TV_FIRST+72)
TVM_SETUNICODEFORMAT                            equ     CCM_SETUNICODEFORMAT
TVM_GETUNICODEFORMAT                            equ     CCM_GETUNICODEFORMAT

TVN_SELCHANGINGA                                equ     (TVN_FIRST-1)
TVN_SELCHANGEDA                                 equ     (TVN_FIRST-2)
TVN_GETDISPINFOA                                equ     (TVN_FIRST-3)
TVN_SETDISPINFOA                                equ     (TVN_FIRST-4)
TVN_ITEMEXPANDINGA                              equ     (TVN_FIRST-5)
TVN_ITEMEXPANDEDA                               equ     (TVN_FIRST-6)
TVN_BEGINDRAGA                                  equ     (TVN_FIRST-7)
TVN_BEGINRDRAGA                                 equ     (TVN_FIRST-8)
TVN_DELETEITEMA                                 equ     (TVN_FIRST-9)
TVN_BEGINLABELEDITA                             equ     (TVN_FIRST-10)
TVN_ENDLABELEDITA                               equ     (TVN_FIRST-11)
TVN_KEYDOWN                                     equ     (TVN_FIRST-12)
TVN_GETINFOTIPA                                 equ     (TVN_FIRST-13)
TVN_GETINFOTIPW                                 equ     (TVN_FIRST-14)
TVN_SINGLEEXPAND                                equ     (TVN_FIRST-15)
TVN_ITEMCHANGINGA                               equ     (TVN_FIRST-16)
TVN_ITEMCHANGINGW                               equ     (TVN_FIRST-17)
TVN_ITEMCHANGEDA                                equ     (TVN_FIRST-18)
TVN_ITEMCHANGEDW                                equ     (TVN_FIRST-19)
TVN_ASYNCDRAW                                   equ     (TVN_FIRST-20)
TVN_SELCHANGINGW                                equ     (TVN_FIRST-50)
TVN_SELCHANGEDW                                 equ     (TVN_FIRST-51)
TVN_GETDISPINFOW                                equ     (TVN_FIRST-52)
TVN_SETDISPINFOW                                equ     (TVN_FIRST-53)
TVN_ITEMEXPANDINGW                              equ     (TVN_FIRST-54)
TVN_ITEMEXPANDEDW                               equ     (TVN_FIRST-55)
TVN_BEGINDRAGW                                  equ     (TVN_FIRST-56)
TVN_BEGINRDRAGW                                 equ     (TVN_FIRST-57)
TVN_DELETEITEMW                                 equ     (TVN_FIRST-58)
TVN_BEGINLABELEDITW                             equ     (TVN_FIRST-59)
TVN_ENDLABELEDITW                               equ     (TVN_FIRST-60)

TVC_UNKNOWN                                     equ     00000H
TVC_BYMOUSE                                     equ     00001H
TVC_BYKEYBOARD                                  equ     00002H

TVNRET_DEFAULT                                  equ     0
TVNRET_SKIPOLD                                  equ     1
TVNRET_SKIPNEW                                  equ     2

TVCDRF_NOIMAGES                                 equ     000010000H

;======================================== ComboBoxEx ======================================;
CB_DELETESTRING                                 equ     0144H

CBEIF_TEXT                                      equ     000000001H
CBEIF_IMAGE                                     equ     000000002H
CBEIF_SELECTEDIMAGE                             equ     000000004H
CBEIF_OVERLAY                                   equ     000000008H
CBEIF_INDENT                                    equ     000000010H
CBEIF_LPARAM                                    equ     000000020H

CBEIF_DI_SETITEM                                equ     010000000H

CBEM_INSERTITEMA                                equ     (WM_USER+1)
CBEM_SETIMAGELIST                               equ     (WM_USER+2)
CBEM_GETIMAGELIST                               equ     (WM_USER+3)
CBEM_GETITEMA                                   equ     (WM_USER+4)
CBEM_SETITEMA                                   equ     (WM_USER+5)
CBEM_DELETEITEM                                 equ     CB_DELETESTRING
CBEM_GETCOMBOCONTROL                            equ     (WM_USER+6)
CBEM_GETEDITCONTROL                             equ     (WM_USER+7)
CBEM_SETEXSTYLE                                 equ     (WM_USER+8)
CBEM_GETEXSTYLE                                 equ     (WM_USER+9)
CBEM_GETEXTENDEDSTYLE                           equ     (WM_USER+9)
CBEM_HASEDITCHANGED                             equ     (WM_USER+10)
CBEM_INSERTITEMW                                equ     (WM_USER+11)
CBEM_SETITEMW                                   equ     (WM_USER+12)
CBEM_GETITEMW                                   equ     (WM_USER+13)
CBEM_SETEXTENDEDSTYLE                           equ     (WM_USER+14)
CBEM_SETUNICODEFORMAT                           equ     CCM_SETUNICODEFORMAT
CBEM_GETUNICODEFORMAT                           equ     CCM_GETUNICODEFORMAT
CBEM_SETWINDOWTHEME                             equ     CCM_SETWINDOWTHEME

CBES_EX_NOEDITIMAGE                             equ     000000001H
CBES_EX_NOEDITIMAGEINDENT                       equ     000000002H
CBES_EX_PATHWORDBREAKPROC                       equ     000000004H
CBES_EX_NOSIZELIMIT                             equ     000000008H
CBES_EX_CASESENSITIVE                           equ     000000010H
CBES_EX_TEXTENDELLIPSIS                         equ     000000020H

CBEN_GETDISPINFOA                               equ     (CBEN_FIRST-0)
CBEN_INSERTITEM                                 equ     (CBEN_FIRST-1)
CBEN_DELETEITEM                                 equ     (CBEN_FIRST-2)
CBEN_BEGINEDIT                                  equ     (CBEN_FIRST-4)
CBEN_ENDEDITA                                   equ     (CBEN_FIRST-5)
CBEN_ENDEDITW                                   equ     (CBEN_FIRST-6)
CBEN_GETDISPINFOW                               equ     (CBEN_FIRST-7)
CBEN_DRAGBEGINA                                 equ     (CBEN_FIRST-8)
CBEN_DRAGBEGINW                                 equ     (CBEN_FIRST-9)

CBENF_KILLFOCUS                                 equ     1
CBENF_RETURN                                    equ     2
CBENF_ESCAPE                                    equ     3
CBENF_DROPDOWN                                  equ     4

;=========================================== Tab ==========================================;
TCS_SCROLLOPPOSITE                              equ     00001H
TCS_BOTTOM                                      equ     00002H
TCS_RIGHT                                       equ     00002H
TCS_MULTISELECT                                 equ     00004H
TCS_FLATBUTTONS                                 equ     00008H
TCS_FORCEICONLEFT                               equ     00010H
TCS_FORCELABELLEFT                              equ     00020H
TCS_HOTTRACK                                    equ     00040H
TCS_VERTICAL                                    equ     00080H
TCS_TABS                                        equ     00000H
TCS_BUTTONS                                     equ     00100H
TCS_SINGLELINE                                  equ     00000H
TCS_MULTILINE                                   equ     00200H
TCS_RIGHTJUSTIFY                                equ     00000H
TCS_FIXEDWIDTH                                  equ     00400H
TCS_RAGGEDRIGHT                                 equ     00800H
TCS_FOCUSONBUTTONDOWN                           equ     01000H
TCS_OWNERDRAWFIXED                              equ     02000H
TCS_TOOLTIPS                                    equ     04000H
TCS_FOCUSNEVER                                  equ     08000H

TCS_EX_FLATSEPARATORS                           equ     000000001H
TCS_EX_REGISTERDROP                             equ     000000002H

TCIF_TEXT                                       equ     00001H
TCIF_IMAGE                                      equ     00002H
TCIF_RTLREADING                                 equ     00004H
TCIF_PARAM                                      equ     00008H
TCIF_STATE                                      equ     00010H

TCIS_BUTTONPRESSED                              equ     00001H
TCIS_HIGHLIGHTED                                equ     00002H

TCHT_NOWHERE                                    equ     00001H
TCHT_ONITEMICON                                 equ     00002H
TCHT_ONITEMLABEL                                equ     00004H
TCHT_ONITEM                                     equ     <TCHT_ONITEMICON or TCHT_ONITEMLABEL>
TCM_GETIMAGELIST                                equ     (TCM_FIRST+2)
TCM_SETIMAGELIST                                equ     (TCM_FIRST+3)
TCM_GETITEMCOUNT                                equ     (TCM_FIRST+4)
TCM_GETITEMA                                    equ     (TCM_FIRST+5)
TCM_SETITEMA                                    equ     (TCM_FIRST+6)
TCM_INSERTITEMA                                 equ     (TCM_FIRST+7)
TCM_DELETEITEM                                  equ     (TCM_FIRST+8)
TCM_DELETEALLITEMS                              equ     (TCM_FIRST+9)
TCM_GETITEMRECT                                 equ     (TCM_FIRST+10)
TCM_GETCURSEL                                   equ     (TCM_FIRST+11)
TCM_SETCURSEL                                   equ     (TCM_FIRST+12)
TCM_HITTEST                                     equ     (TCM_FIRST+13)
TCM_SETITEMEXTRA                                equ     (TCM_FIRST+14)
TCM_ADJUSTRECT                                  equ     (TCM_FIRST+40)
TCM_SETITEMSIZE                                 equ     (TCM_FIRST+41)
TCM_REMOVEIMAGE                                 equ     (TCM_FIRST+42)
TCM_SETPADDING                                  equ     (TCM_FIRST+43)
TCM_GETROWCOUNT                                 equ     (TCM_FIRST+44)
TCM_GETTOOLTIPS                                 equ     (TCM_FIRST+45)
TCM_SETTOOLTIPS                                 equ     (TCM_FIRST+46)
TCM_GETCURFOCUS                                 equ     (TCM_FIRST+47)
TCM_SETCURFOCUS                                 equ     (TCM_FIRST+48)
TCM_SETMINTABWIDTH                              equ     (TCM_FIRST+49)
TCM_DESELECTALL                                 equ     (TCM_FIRST+50)
TCM_HIGHLIGHTITEM                               equ     (TCM_FIRST+51)
TCM_SETEXTENDEDSTYLE                            equ     (TCM_FIRST+52)
TCM_GETEXTENDEDSTYLE                            equ     (TCM_FIRST+53)
TCM_GETITEMW                                    equ     (TCM_FIRST+60)
TCM_SETITEMW                                    equ     (TCM_FIRST+61)
TCM_INSERTITEMW                                 equ     (TCM_FIRST+62)
TCM_SETUNICODEFORMAT                            equ     CCM_SETUNICODEFORMAT
TCM_GETUNICODEFORMAT                            equ     CCM_GETUNICODEFORMAT

TCN_KEYDOWN                                     equ     (TCN_FIRST-0)
TCN_SELCHANGE                                   equ     (TCN_FIRST-1)
TCN_SELCHANGING                                 equ     (TCN_FIRST-2)
TCN_GETOBJECT                                   equ     (TCN_FIRST-3)
TCN_FOCUSCHANGE                                 equ     (TCN_FIRST-4)

;========================================= Animate ========================================;
ACS_CENTER                                      equ     00001H
ACS_TRANSPARENT                                 equ     00002H
ACS_AUTOPLAY                                    equ     00004H
ACS_TIMER                                       equ     00008H

ACM_OPENA                                       equ     (WM_USER+100)
ACM_PLAY                                        equ     (WM_USER+101)
ACM_STOP                                        equ     (WM_USER+102)
ACM_OPENW                                       equ     (WM_USER+103)

ACN_START                                       equ     1
ACN_STOP                                        equ     2

;======================================== MonthCal ========================================;
MCM_FIRST                                       equ     01000H
MCM_GETCURSEL                                   equ     (MCM_FIRST+1)
MCM_SETCURSEL                                   equ     (MCM_FIRST+2)
MCM_GETMAXSELCOUNT                              equ     (MCM_FIRST+3)
MCM_SETMAXSELCOUNT                              equ     (MCM_FIRST+4)
MCM_GETSELRANGE                                 equ     (MCM_FIRST+5)
MCM_SETSELRANGE                                 equ     (MCM_FIRST+6)
MCM_GETMONTHRANGE                               equ     (MCM_FIRST+7)
MCM_SETDAYSTATE                                 equ     (MCM_FIRST+8)
MCM_GETMINREQRECT                               equ     (MCM_FIRST+9)
MCM_SETCOLOR                                    equ     (MCM_FIRST+10)
MCM_GETCOLOR                                    equ     (MCM_FIRST+11)
MCM_SETTODAY                                    equ     (MCM_FIRST+12)
MCM_GETTODAY                                    equ     (MCM_FIRST+13)
MCM_HITTEST                                     equ     (MCM_FIRST+14)
MCM_SETFIRSTDAYOFWEEK                           equ     (MCM_FIRST+15)
MCM_GETFIRSTDAYOFWEEK                           equ     (MCM_FIRST+16)
MCM_GETRANGE                                    equ     (MCM_FIRST+17)
MCM_SETRANGE                                    equ     (MCM_FIRST+18)
MCM_GETMONTHDELTA                               equ     (MCM_FIRST+19)
MCM_SETMONTHDELTA                               equ     (MCM_FIRST+20)
MCM_GETMAXTODAYWIDTH                            equ     (MCM_FIRST+21)
MCM_GETCURRENTVIEW                              equ     (MCM_FIRST+22)
MCM_GETCALENDARCOUNT                            equ     (MCM_FIRST+23)
MCM_GETCALENDARGRIDINFO                         equ     (MCM_FIRST+24)
MCM_GETCALID                                    equ     (MCM_FIRST+27)
MCM_SETCALID                                    equ     (MCM_FIRST+28)
MCM_SIZERECTTOMIN                               equ     (MCM_FIRST+29)
MCM_SETCALENDARBORDER                           equ     (MCM_FIRST+30)
MCM_GETCALENDARBORDER                           equ     (MCM_FIRST+31)
MCM_SETCURRENTVIEW                              equ     (MCM_FIRST+32)
MCM_SETUNICODEFORMAT                            equ     CCM_SETUNICODEFORMAT
MCM_GETUNICODEFORMAT                            equ     CCM_GETUNICODEFORMAT

MCSC_BACKGROUND                                 equ     0
MCSC_TEXT                                       equ     1
MCSC_TITLEBK                                    equ     2
MCSC_TITLETEXT                                  equ     3
MCSC_MONTHBK                                    equ     4
MCSC_TRAILINGTEXT                               equ     5

MCHT_TITLE                                      equ     000010000H
MCHT_CALENDAR                                   equ     000020000H
MCHT_TODAYLINK                                  equ     000030000H
MCHT_NEXT                                       equ     001000000H
MCHT_PREV                                       equ     002000000H
MCHT_NOWHERE                                    equ     000000000H
MCHT_TITLEBK                                    equ     MCHT_TITLE
MCHT_TITLEMONTH                                 equ     <MCHT_TITLE or 00001H>
MCHT_TITLEYEAR                                  equ     <MCHT_TITLE or 00002H>
MCHT_TITLEBTNNEXT                               equ     <MCHT_TITLE or MCHT_NEXT or 00003H>
MCHT_TITLEBTNPREV                               equ     <MCHT_TITLE or MCHT_PREV or 00003H>

MCHT_CALENDARBK                                 equ     MCHT_CALENDAR
MCHT_CALENDARDATE                               equ     <MCHT_CALENDAR or 00001H>
MCHT_CALENDARDATENEXT                           equ     <MCHT_CALENDARDATE or MCHT_NEXT>
MCHT_CALENDARDATEPREV                           equ     <MCHT_CALENDARDATE or MCHT_PREV>
MCHT_CALENDARDAY                                equ     <MCHT_CALENDAR or 00002H>
MCHT_CALENDARWEEKNUM                            equ     <MCHT_CALENDAR or 00003H>
MCHT_CALENDARDATEMIN                            equ     <MCHT_CALENDAR or 0004H>
MCHT_CALENDARDATEMAX                            equ     <MCHT_CALENDAR or 0005H>
MCHT_CALENDARCONTROL                            equ     000100000H

MCN_VIEWCHANGE                                  equ     (MCN_FIRST-4)
MCN_SELCHANGE                                   equ     (MCN_FIRST+1)
MCN_GETDAYSTATE                                 equ     (MCN_FIRST+3)
MCN_SELECT                                      equ     (MCN_FIRST+4)

MCS_DAYSTATE                                    equ     00001H
MCS_MULTISELECT                                 equ     00002H
MCS_WEEKNUMBERS                                 equ     00004H
MCS_NOTODAYCIRCLE                               equ     00008H
MCS_NOTODAY                                     equ     00010H
MCS_NOTRAILINGDATES                             equ     00040H
MCS_SHORTDAYSOFWEEK                             equ     00080H
MCS_NOSELCHANGEONNAV                            equ     00100H

MCMV_MONTH                                      equ     0
MCMV_YEAR                                       equ     1
MCMV_DECADE                                     equ     2
MCMV_CENTURY                                    equ     3
MCMV_MAX                                        equ     MCMV_CENTURY

MCGIP_CALENDARCONTROL                           equ     0
MCGIP_NEXT                                      equ     1
MCGIP_PREV                                      equ     2
MCGIP_FOOTER                                    equ     3
MCGIP_CALENDAR                                  equ     4
MCGIP_CALENDARHEADER                            equ     5
MCGIP_CALENDARBODY                              equ     6
MCGIP_CALENDARROW                               equ     7
MCGIP_CALENDARCELL                              equ     8

MCGIF_DATE                                      equ     000000001H
MCGIF_RECT                                      equ     000000002H
MCGIF_NAME                                      equ     000000004H

GMR_VISIBLE                                     equ     0
GMR_DAYSTATE                                    equ     1

;======================================== DateTime ========================================;
DTM_FIRST                                       equ     01000H
DTM_GETSYSTEMTIME                               equ     (DTM_FIRST+1)
DTM_SETSYSTEMTIME                               equ     (DTM_FIRST+2)
DTM_GETRANGE                                    equ     (DTM_FIRST+3)
DTM_SETRANGE                                    equ     (DTM_FIRST+4)
DTM_SETFORMATA                                  equ     (DTM_FIRST+5)
DTM_SETMCCOLOR                                  equ     (DTM_FIRST+6)
DTM_GETMCCOLOR                                  equ     (DTM_FIRST+7)
DTM_GETMONTHCAL                                 equ     (DTM_FIRST+8)
DTM_SETMCFONT                                   equ     (DTM_FIRST+9)
DTM_GETMCFONT                                   equ     (DTM_FIRST+10)
DTM_SETMCSTYLE                                  equ     (DTM_FIRST+11)
DTM_GETMCSTYLE                                  equ     (DTM_FIRST+12)
DTM_CLOSEMONTHCAL                               equ     (DTM_FIRST+13)
DTM_GETDATETIMEPICKERINFO                       equ     (DTM_FIRST+14)
DTM_GETIDEALSIZE                                equ     (DTM_FIRST+15)
DTM_SETFORMATW                                  equ     (DTM_FIRST+50)

DTS_UPDOWN                                      equ     00001H
DTS_SHOWNONE                                    equ     00002H
DTS_SHORTDATEFORMAT                             equ     00000H
DTS_LONGDATEFORMAT                              equ     00004H
DTS_TIMEFORMAT                                  equ     00009H
DTS_APPCANPARSE                                 equ     00010H
DTS_RIGHTALIGN                                  equ     00020H

DTN_DATETIMECHANGE                              equ     (DTN_FIRST+1)
DTN_USERSTRINGA                                 equ     (DTN_FIRST+2)
DTN_WMKEYDOWNA                                  equ     (DTN_FIRST+3)
DTN_FORMATA                                     equ     (DTN_FIRST+4)
DTN_FORMATQUERYA                                equ     (DTN_FIRST+5)
DTN_DROPDOWN                                    equ     (DTN_FIRST+6)
DTN_CLOSEUP                                     equ     (DTN_FIRST+7)
DTN_USERSTRINGW                                 equ     (DTN_FIRST+15)
DTN_WMKEYDOWNW                                  equ     (DTN_FIRST+16)
DTN_FORMATW                                     equ     (DTN_FIRST+17)
DTN_FORMATQUERYW                                equ     (DTN_FIRST+18)

GDTR_MIN                                        equ     00001H
GDTR_MAX                                        equ     00002H

GDT_ERROR                                       equ     (-1)
GDT_VALID                                       equ     0
GDT_NONE                                        equ     1

;======================================== IpAddress =======================================;
IPM_CLEARADDRESS                                equ     (WM_USER+100)
IPM_SETADDRESS                                  equ     (WM_USER+101)
IPM_GETADDRESS                                  equ     (WM_USER+102)
IPM_SETRANGE                                    equ     (WM_USER+103)
IPM_SETFOCUS                                    equ     (WM_USER+104)
IPM_ISBLANK                                     equ     (WM_USER+105)

IPN_FIELDCHANGED                                equ     (IPN_FIRST-0)

;========================================== Pager =========================================;
PGS_VERT                                        equ     000000000H
PGS_HORZ                                        equ     000000001H
PGS_AUTOSCROLL                                  equ     000000002H
PGS_DRAGNDROP                                   equ     000000004H

PGF_INVISIBLE                                   equ     0
PGF_NORMAL                                      equ     1
PGF_GRAYED                                      equ     2
PGF_DEPRESSED                                   equ     4
PGF_HOT                                         equ     8

PGB_TOPORLEFT                                   equ     0
PGB_BOTTOMORRIGHT                               equ     1

PGM_SETCHILD                                    equ     (PGM_FIRST+1)
PGM_RECALCSIZE                                  equ     (PGM_FIRST+2)
PGM_FORWARDMOUSE                                equ     (PGM_FIRST+3)
PGM_SETBKCOLOR                                  equ     (PGM_FIRST+4)
PGM_GETBKCOLOR                                  equ     (PGM_FIRST+5)
PGM_SETBORDER                                   equ     (PGM_FIRST+6)
PGM_GETBORDER                                   equ     (PGM_FIRST+7)
PGM_SETPOS                                      equ     (PGM_FIRST+8)
PGM_GETPOS                                      equ     (PGM_FIRST+9)
PGM_SETBUTTONSIZE                               equ     (PGM_FIRST+10)
PGM_GETBUTTONSIZE                               equ     (PGM_FIRST+11)
PGM_GETBUTTONSTATE                              equ     (PGM_FIRST+12)
PGM_GETDROPTARGET                               equ     CCM_GETDROPTARGET

PGN_SCROLL                                      equ     (PGN_FIRST-1)
PGN_CALCSIZE                                    equ     (PGN_FIRST-2)
PGN_HOTITEMCHANGE                               equ     (PGN_FIRST-3)

PGF_SCROLLUP                                    equ     1
PGF_SCROLLDOWN                                  equ     2
PGF_SCROLLLEFT                                  equ     4
PGF_SCROLLRIGHT                                 equ     8

PGK_SHIFT                                       equ     1
PGK_CONTROL                                     equ     2
PGK_MENU                                        equ     4

PGF_CALCWIDTH                                   equ     1
PGF_CALCHEIGHT                                  equ     2

;======================================== NativeFont ======================================;
NFS_EDIT                                        equ     00001H
NFS_STATIC                                      equ     00002H
NFS_LISTCOMBO                                   equ     00004H
NFS_BUTTON                                      equ     00008H
NFS_ALL                                         equ     00010H
NFS_USEFONTASSOC                                equ     00020H

WSB_PROP_CYVSCROLL                              equ     000000001H
WSB_PROP_CXHSCROLL                              equ     000000002H
WSB_PROP_CYHSCROLL                              equ     000000004H
WSB_PROP_CXVSCROLL                              equ     000000008H
WSB_PROP_CXHTHUMB                               equ     000000010H
WSB_PROP_CYVTHUMB                               equ     000000020H
WSB_PROP_VBKGCOLOR                              equ     000000040H
WSB_PROP_HBKGCOLOR                              equ     000000080H
WSB_PROP_VSTYLE                                 equ     000000100H
WSB_PROP_HSTYLE                                 equ     000000200H
WSB_PROP_WINSTYLE                               equ     000000400H
WSB_PROP_PALETTE                                equ     000000800H
WSB_PROP_MASK                                   equ     000000FFFH

FSB_FLAT_MODE                                   equ     2
FSB_ENCARTA_MODE                                equ     1
FSB_REGULAR_MODE                                equ     0

;========================================== SysLink =======================================;
INVALID_LINK_INDEX                              equ     (-1)

LWS_TRANSPARENT                                 equ     00001H
LWS_IGNORERETURN                                equ     00002H
LWS_NOPREFIX                                    equ     00004H
LWS_USEVISUALSTYLE                              equ     00008H
LWS_USECUSTOMTEXT                               equ     00010H
LWS_RIGHT                                       equ     00020H

LIF_ITEMINDEX                                   equ     000000001H
LIF_STATE                                       equ     000000002H
LIF_ITEMID                                      equ     000000004H
LIF_URL                                         equ     000000008H

LIS_FOCUSED                                     equ     000000001H
LIS_ENABLED                                     equ     000000002H
LIS_VISITED                                     equ     000000004H
LIS_HOTTRACK                                    equ     000000008H
LIS_DEFAULTCOLORS                               equ     000000010H

LM_HITTEST                                      equ     (WM_USER+0300H)
LM_GETIDEALHEIGHT                               equ     (WM_USER+0301H)
LM_SETITEM                                      equ     (WM_USER+0302H)
LM_GETITEM                                      equ     (WM_USER+0303H)
LM_GETIDEALSIZE                                 equ     LM_GETIDEALHEIGHT

;======================================== Task dialog =====================================;
TDF_ENABLE_HYPERLINKS                           equ     00001H
TDF_USE_HICON_MAIN                              equ     00002H
TDF_USE_HICON_FOOTER                            equ     00004H
TDF_ALLOW_DIALOG_CANCELLATION                   equ     00008H
TDF_USE_COMMAND_LINKS                           equ     00010H
TDF_USE_COMMAND_LINKS_NO_ICON                   equ     00020H
TDF_EXPAND_FOOTER_AREA                          equ     00040H
TDF_EXPANDED_BY_DEFAULT                         equ     00080H
TDF_VERIFICATION_FLAG_CHECKED                   equ     00100H
TDF_SHOW_PROGRESS_BAR                           equ     00200H
TDF_SHOW_MARQUEE_PROGRESS_BAR                   equ     00400H
TDF_CALLBACK_TIMER                              equ     00800H
TDF_POSITION_RELATIVE_TO_WINDOW                 equ     01000H
TDF_RTL_LAYOUT                                  equ     02000H
TDF_NO_DEFAULT_RADIO_BUTTON                     equ     04000H
TDF_CAN_BE_MINIMIZED                            equ     08000H

TDM_NAVIGATE_PAGE                               equ     (WM_USER+101)
TDM_CLICK_BUTTON                                equ     (WM_USER+102)
TDM_SET_MARQUEE_PROGRESS_BAR                    equ     (WM_USER+103)
TDM_SET_PROGRESS_BAR_STATE                      equ     (WM_USER+104)
TDM_SET_PROGRESS_BAR_RANGE                      equ     (WM_USER+105)
TDM_SET_PROGRESS_BAR_POS                        equ     (WM_USER+106)
TDM_SET_PROGRESS_BAR_MARQUEE                    equ     (WM_USER+107)
TDM_SET_ELEMENT_TEXT                            equ     (WM_USER+108)
TDM_CLICK_RADIO_BUTTON                          equ     (WM_USER+110)
TDM_ENABLE_BUTTON                               equ     (WM_USER+111)
TDM_ENABLE_RADIO_BUTTON                         equ     (WM_USER+112)
TDM_CLICK_VERIFICATION                          equ     (WM_USER+113)
TDM_UPDATE_ELEMENT_TEXT                         equ     (WM_USER+114)
TDM_SET_BUTTON_ELEVATION_REQUIRED_STATE         equ     (WM_USER+115)
TDM_UPDATE_ICON                                 equ     (WM_USER+116)

TDN_CREATED                                     equ     0
TDN_NAVIGATED                                   equ     1
TDN_BUTTON_CLICKED                              equ     2
TDN_HYPERLINK_CLICKED                           equ     3
TDN_TIMER                                       equ     4
TDN_DESTROYED                                   equ     5
TDN_RADIO_BUTTON_CLICKED                        equ     6
TDN_DIALOG_CONSTRUCTED                          equ     7
TDN_VERIFICATION_CLICKED                        equ     8
TDN_HELP                                        equ     9
TDN_EXPANDO_BUTTON_CLICKED                      equ     10

TDE_CONTENT                                     equ     0
TDE_EXPANDED_INFORMATION                        equ     1
TDE_FOOTER                                      equ     2
TDE_MAIN_INSTRUCTION                            equ     3

TD_WARNING_ICON                                 equ     (-1)
TD_ERROR_ICON                                   equ     (-2)
TD_INFORMATION_ICON                             equ     (-3)
TD_SHIELD_ICON                                  equ     (-4)

TDIE_ICON_MAIN                                  equ     0
TDIE_ICON_FOOTER                                equ     1

TDCBF_OK_BUTTON                                 equ     00001H
TDCBF_YES_BUTTON                                equ     00002H
TDCBF_NO_BUTTON                                 equ     00004H
TDCBF_CANCEL_BUTTON                             equ     00008H
TDCBF_RETRY_BUTTON                              equ     00010H
TDCBF_CLOSE_BUTTON                              equ     00020H

;====================================== TrackMouseEvent ===================================;
WM_MOUSEHOVER_DEF                               equ     1
WM_MOUSEHOVER                                   equ     002A1H
WM_MOUSELEAVE_DEF                               equ     1
WM_MOUSELEAVE                                   equ     002A3H

TME_HOVER_DEF                                   equ     1
TME_HOVER                                       equ     000000001H
TME_LEAVE                                       equ     000000002H
TME_QUERY                                       equ     040000000H
TME_CANCEL                                      equ     080000000H

HOVER_DEFAULT                                   equ     0FFFFFFFFH

;======================================== Functions =======================================;
#if COFF_FORMAT == 1
    from_lib comctl32.lib
#else
    from_dll comctl32.dll
#endif

import CreateMappedBitmap
import CreatePropertySheetPageA
import CreatePropertySheetPageW
import CreateStatusWindowA
import CreateStatusWindowW
import CreateToolbarEx
import CreateUpDownControl
import DestroyPropertySheetPage
import DrawInsert
import DrawStatusTextA
import DrawStatusTextW
import FlatSB_EnableScrollBar
import FlatSB_GetScrollInfo
import FlatSB_GetScrollPos
import FlatSB_GetScrollProp
import FlatSB_GetScrollRange
import FlatSB_SetScrollInfo
import FlatSB_SetScrollPos
import FlatSB_SetScrollProp
import FlatSB_SetScrollRange
import FlatSB_ShowScrollBar
import GetEffectiveClientRect
import GetMUILanguage
import ImageList_Add
import ImageList_AddIcon
import ImageList_AddMasked
import ImageList_BeginDrag
import ImageList_Copy
import ImageList_Create
import ImageList_Destroy
import ImageList_DragEnter
import ImageList_DragLeave
import ImageList_DragMove
import ImageList_DragShowNolock
import ImageList_Draw
import ImageList_DrawEx
import ImageList_DrawIndirect
import ImageList_Duplicate
import ImageList_EndDrag
import ImageList_GetBkColor
import ImageList_GetDragImage
import ImageList_GetFlags
import ImageList_GetIcon
import ImageList_GetIconSize
import ImageList_GetImageCount
import ImageList_GetImageInfo
import ImageList_GetImageRect
import ImageList_LoadImageA
import ImageList_LoadImageW
import ImageList_Merge
import ImageList_Read
import ImageList_Remove
import ImageList_Replace
import ImageList_ReplaceIcon
import ImageList_SetBkColor
import ImageList_SetDragCursorImage
import ImageList_SetFilter
import ImageList_SetFlags
import ImageList_SetIconSize
import ImageList_SetImageCount
import ImageList_SetOverlayImage
import ImageList_Write
import InitCommonControls
import InitCommonControlsEx
import InitializeFlatSB
import InitMUILanguage
import LBItemFromPt
import MakeDragList
import MenuHelp
import PropertySheetA
import PropertySheetW
import ShowHideMenuCtl
import UninitializeFlatSB
import _TrackMouseEvent

#if NTDDI_VERSION >= NTDDI_WINXP
    import AddMRUStringW
    import CreateMRUListW
    import DefSubclassProc
    import DPA_Create
    import DPA_DeleteAllPtrs
    import DPA_DeletePtr
    import DPA_Destroy
    import DPA_DestroyCallback
    import DPA_EnumCallback
    import DPA_GetPtr
    import DPA_InsertPtr
    import DPA_Search
    import DPA_SetPtr
    import DPA_Sort
    import DSA_Create
    import DSA_DeleteAllItems
    import DSA_Destroy
    import DSA_DestroyCallback
    import DSA_GetItemPtr
    import DSA_InsertItem
    import EnumMRUListW
    import FlatSB_GetScrollPropPtr
    import FreeMRUList
    import GetWindowSubclass
    import RegisterClassNameW
    import RemoveWindowSubclass
    import SetWindowSubclass
#endif

#if NTDDI_VERSION >= NTDDI_VISTA
    import DPA_Clone
    import DPA_CreateEx
    import DPA_GetPtrIndex
    import DPA_Grow
    import DPA_LoadStream
    import DPA_Merge
    import DPA_SaveStream
    import DSA_DeleteItem
    import DSA_EnumCallback
    import DSA_GetItem
    import DSA_SetItem
    import HIMAGELIST_QueryInterface
    import ImageList_WriteEx
    import Str_SetPtrA
    import Str_SetPtrW
#endif

#ifdef APP_UNICODE
    define ACM_OPEN ACM_OPENW
    define CBEM_GETITEM CBEM_GETITEMW
    define CBEM_INSERTITEM CBEM_INSERTITEMW
    define CBEM_SETITEM CBEM_SETITEMW
    define CBEN_DRAGBEGIN CBEN_DRAGBEGINW
    define CBEN_ENDEDIT CBEN_ENDEDITW
    define CBEN_GETDISPINFO CBEN_GETDISPINFOW
    define DTM_SETFORMAT DTM_SETFORMATW
    define DTN_FORMAT DTN_FORMATW
    define DTN_FORMATQUERY DTN_FORMATQUERYW
    define DTN_USERSTRING DTN_USERSTRINGW
    define DTN_WMKEYDOWN DTN_WMKEYDOWNW
    define CreatePropertySheetPage CreatePropertySheetPageW
    define CreateStatusWindow CreateStatusWindowW
    define DrawStatusText DrawStatusTextW
    define ImageList_LoadImage ImageList_LoadImageW
    define PropertySheet PropertySheetW
    define Str_SetPtr Str_SetPtrW
#else
    define ACM_OPEN ACM_OPENA
    define CBEM_GETITEM CBEM_GETITEMA
    define CBEM_INSERTITEM CBEM_INSERTITEMA
    define CBEM_SETITEM CBEM_SETITEMA
    define CBEN_DRAGBEGIN CBEN_DRAGBEGINA
    define CBEN_ENDEDIT CBEN_ENDEDITA
    define CBEN_GETDISPINFO CBEN_GETDISPINFOA
    define DTM_SETFORMAT DTM_SETFORMATA
    define DTN_FORMAT DTN_FORMATA
    define DTN_FORMATQUERY DTN_FORMATQUERYA
    define DTN_USERSTRING DTN_USERSTRINGA
    define DTN_WMKEYDOWN DTN_WMKEYDOWNA
    define CreatePropertySheetPage CreatePropertySheetPageA
    define CreateStatusWindow CreateStatusWindowA
    define DrawStatusText DrawStatusTextA
    define ImageList_LoadImage ImageList_LoadImageA
    define PropertySheet PropertySheetA
    define Str_SetPtr Str_SetPtrA
#endif

;======================= Undocumented functions (unknown arguments) =======================;
;import CreateToolbar

#endif ;COMCTL32_INC
