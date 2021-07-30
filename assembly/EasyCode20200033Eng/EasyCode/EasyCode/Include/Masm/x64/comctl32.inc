; ======================================================;
;                                                       ;
;  comctl32.inc for Easy Code 2.0 64-bit Masm projects  ;
;                   (version 1.0.12)                    ;
;                                                       ;
;         Copyright © Ramon Sala - 2015-2020            ;
;                                                       ;
; ======================================================;

IFNDEF COMCTL32_INC
COMCTL32_INC        EQU     1

ICC_LISTVIEW_CLASSES                            EQU     000000001H
ICC_TREEVIEW_CLASSES                            EQU     000000002H
ICC_BAR_CLASSES                                 EQU     000000004H
ICC_TAB_CLASSES                                 EQU     000000008H
ICC_UPDOWN_CLASS                                EQU     000000010H
ICC_PROGRESS_CLASS                              EQU     000000020H
ICC_HOTKEY_CLASS                                EQU     000000040H
ICC_ANIMATE_CLASS                               EQU     000000080H
ICC_WIN95_CLASSES                               EQU     0000000FFH
ICC_DATE_CLASSES                                EQU     000000100H
ICC_USEREX_CLASSES                              EQU     000000200H
ICC_COOL_CLASSES                                EQU     000000400H
ICC_INTERNET_CLASSES                            EQU     000000800H
ICC_PAGESCROLLER_CLASS                          EQU     000001000H
ICC_NATIVEFNTCTL_CLASS                          EQU     000002000H
ICC_STANDARD_CLASSES                            EQU     000004000H
ICC_LINK_CLASS                                  EQU     000008000H

ODT_HEADER                                      EQU     100
ODT_TAB                                         EQU     101
ODT_LISTVIEW                                    EQU     102

LVM_FIRST                                       EQU     01000H
TV_FIRST                                        EQU     01100H
HDM_FIRST                                       EQU     01200H
TCM_FIRST                                       EQU     01300H

PGM_FIRST                                       EQU     01400H
IFNDEF ECM_FIRST
    ECM_FIRST                                   EQU     01500H
ENDIF
BCM_FIRST                                       EQU     01600H
CBM_FIRST                                       EQU     01700H
CCM_FIRST                                       EQU     02000H
CCM_LAST                                        EQU     (CCM_FIRST + 0200H)

CCM_SETBKCOLOR                                  EQU     (CCM_FIRST + 1)

CCM_SETCOLORSCHEME                              EQU     (CCM_FIRST + 2)
CCM_GETCOLORSCHEME                              EQU     (CCM_FIRST + 3)
CCM_GETDROPTARGET                               EQU     (CCM_FIRST + 4)
CCM_SETUNICODEFORMAT                            EQU     (CCM_FIRST + 5)
CCM_GETUNICODEFORMAT                            EQU     (CCM_FIRST + 6)
CCM_SETVERSION                                  EQU     (CCM_FIRST + 7)
CCM_GETVERSION                                  EQU     (CCM_FIRST + 8)
CCM_SETNOTIFYWINDOW                             EQU     (CCM_FIRST + 9)
CCM_SETWINDOWTHEME                              EQU     (CCM_FIRST + 11)
CCM_DPISCALE                                    EQU     (CCM_FIRST + 12)

INFOTIPSIZE                                     EQU     1024

NM_FIRST                                        EQU     0
NM_LAST                                         EQU     (-99)

NM_OUTOFMEMORY                                  EQU     (NM_FIRST - 1)
NM_CLICK                                        EQU     (NM_FIRST - 2)
NM_DBLCLK                                       EQU     (NM_FIRST - 3)
NM_RETURN                                       EQU     (NM_FIRST - 4)
NM_RCLICK                                       EQU     (NM_FIRST - 5)
NM_RDBLCLK                                      EQU     (NM_FIRST - 6)
NM_SETFOCUS                                     EQU     (NM_FIRST - 7)
NM_KILLFOCUS                                    EQU     (NM_FIRST - 8)
NM_CUSTOMDRAW                                   EQU     (NM_FIRST - 12)
NM_HOVER                                        EQU     (NM_FIRST - 13)
NM_NCHITTEST                                    EQU     (NM_FIRST - 14)
NM_KEYDOWN                                      EQU     (NM_FIRST - 15)
NM_RELEASEDCAPTURE                              EQU     (NM_FIRST - 16)
NM_SETCURSOR                                    EQU     (NM_FIRST - 17)
NM_CHAR                                         EQU     (NM_FIRST - 18)
NM_TOOLTIPSCREATED                              EQU     (NM_FIRST - 19)
NM_LDOWN                                        EQU     (NM_FIRST - 20)
NM_RDOWN                                        EQU     (NM_FIRST - 21)
NM_THEMECHANGED                                 EQU     (NM_FIRST - 22)
NM_FONTCHANGED                                  EQU     (NM_FIRST - 23)
NM_CUSTOMTEXT                                   EQU     (NM_FIRST - 24)
NM_TVSTATEIMAGECHANGING                         EQU     (NM_FIRST - 24)

LVN_FIRST                                       EQU     (-100)
LVN_LAST                                        EQU     (-199)

HDN_FIRST                                       EQU     (-300)
HDN_LAST                                        EQU     (-399)

TVN_FIRST                                       EQU     (-400)
TVN_LAST                                        EQU     (-499)

TTN_FIRST                                       EQU     (-520)
TTN_LAST                                        EQU     (-549)

TCN_FIRST                                       EQU     (-550)
TCN_LAST                                        EQU     (-580)

CDN_FIRST                                       EQU     (-601)
CDN_LAST                                        EQU     (-699)

TBN_FIRST                                       EQU     (-700)
TBN_LAST                                        EQU     (-720)

UDN_FIRST                                       EQU     (-721)
UDN_LAST                                        EQU     (-740)

MCN_FIRST                                       EQU     (-750)
MCN_LAST                                        EQU     (-759)

DTN_FIRST                                       EQU     (-760)
DTN_LAST                                        EQU     (-799)

CBEN_FIRST                                      EQU     (-800)
CBEN_LAST                                       EQU     (-830)

RBN_FIRST                                       EQU     (-831)
RBN_LAST                                        EQU     (-859)

IPN_FIRST                                       EQU     (-860)
IPN_LAST                                        EQU     (-879)

SBN_FIRST                                       EQU     (-880)
SBN_LAST                                        EQU     (-899)

PGN_FIRST                                       EQU     (-900)
PGN_LAST                                        EQU     (-950)

MSGF_COMMCTRL_BEGINDRAG                         EQU     04200H
MSGF_COMMCTRL_SIZEHEADER                        EQU     04201H
MSGF_COMMCTRL_DRAGSELECT                        EQU     04202H
MSGF_COMMCTRL_TOOLBARCUST                       EQU     04203H

CDRF_DODEFAULT                                  EQU     000000000H
CDRF_NEWFONT                                    EQU     000000002H
CDRF_SKIPDEFAULT                                EQU     000000004H
CDRF_DOERASE                                    EQU     000000008H
CDRF_SKIPPOSTPAINT                              EQU     000000100H

CDRF_NOTIFYPOSTPAINT                            EQU     000000010H
CDRF_NOTIFYITEMDRAW                             EQU     000000020H
CDRF_NOTIFYSUBITEMDRAW                          EQU     000000020H
CDRF_NOTIFYPOSTERASE                            EQU     000000040H

CDDS_PREPAINT                                   EQU     000000001H
CDDS_POSTPAINT                                  EQU     000000002H
CDDS_PREERASE                                   EQU     000000003H
CDDS_POSTERASE                                  EQU     000000004H

CDDS_ITEM                                       EQU     000010000H
CDDS_ITEMPREPAINT                               EQU     (CDDS_ITEM OR CDDS_PREPAINT)
CDDS_ITEMPOSTPAINT                              EQU     (CDDS_ITEM OR CDDS_POSTPAINT)
CDDS_ITEMPREERASE                               EQU     (CDDS_ITEM OR CDDS_PREERASE)
CDDS_ITEMPOSTERASE                              EQU     (CDDS_ITEM OR CDDS_POSTERASE)
CDDS_SUBITEM                                    EQU     000020000H

CDIS_SELECTED                                   EQU     00001H
CDIS_GRAYED                                     EQU     00002H
CDIS_DISABLED                                   EQU     00004H
CDIS_CHECKED                                    EQU     00008H
CDIS_FOCUS                                      EQU     00010H
CDIS_DEFAULT                                    EQU     00020H
CDIS_HOT                                        EQU     00040H
CDIS_MARKED                                     EQU     00080H
CDIS_INDETERMINATE                              EQU     00100H
CDIS_SHOWKEYBOARDCUES                           EQU     00200H
CDIS_NEARHOT                                    EQU     00400H
CDIS_OTHERSIDEHOT                               EQU     00800H
CDIS_DROPHILITED                                EQU     01000H

CLR_NONE                                        EQU     0FFFFFFFFH
CLR_DEFAULT                                     EQU     0FF000000H

ILC_MASK                                        EQU     00001H
ILC_COLOR                                       EQU     00000H
ILC_COLORDDB                                    EQU     000FEH
ILC_COLOR4                                      EQU     00004H
ILC_COLOR8                                      EQU     00008H
ILC_COLOR16                                     EQU     00010H
ILC_COLOR24                                     EQU     00018H
ILC_COLOR32                                     EQU     00020H
ILC_PALETTE                                     EQU     00800H
ILC_MIRROR                                      EQU     000002000H
ILC_PERITEMMIRROR                               EQU     000008000H
ILC_ORIGINALSIZE                                EQU     000010000H
ILC_HIGHQUALITYSCALE                            EQU     000020000H

ILD_NORMAL                                      EQU     00000H
ILD_TRANSPARENT                                 EQU     00001H
ILD_MASK                                        EQU     00010H
ILD_IMAGE                                       EQU     00020H
ILD_ROP                                         EQU     00040H
ILD_BLEND25                                     EQU     00002H
ILD_BLEND50                                     EQU     00004H
ILD_OVERLAYMASK                                 EQU     00F00H
ILD_PRESERVEALPHA                               EQU     000001000H
ILD_SCALE                                       EQU     000002000H
ILD_DPISCALE                                    EQU     000004000H
ILD_ASYNC                                       EQU     000008000H

ILD_SELECTED                                    EQU     ILD_BLEND50
ILD_FOCUS                                       EQU     ILD_BLEND25
ILD_BLEND                                       EQU     ILD_BLEND50
CLR_HILIGHT                                     EQU     CLR_DEFAULT

ILS_NORMAL                                      EQU     000000000H
ILS_GLOW                                        EQU     000000001H
ILS_SHADOW                                      EQU     000000002H
ILS_SATURATE                                    EQU     000000004H
ILS_ALPHA                                       EQU     000000008H

ILGT_NORMAL                                     EQU     000000000H
ILGT_ASYNC                                      EQU     000000001H

ILIF_ALPHA                                      EQU     000000001H
ILIF_LOWQUALITY                                 EQU     000000002H
ILDRF_IMAGELOWQUALITY                           EQU     000000001H
ILDRF_OVERLAYLOWQUALITY                         EQU     000000010H

HBITMAP_CALLBACK                                EQU     (-1)

ILCF_MOVE                                       EQU     000000000H
ILCF_SWAP                                       EQU     000000001H

ILP_NORMAL                                      EQU     0
ILP_DOWNLEVEL                                   EQU     1

HIMAGELIST                                      TYPEDEF XWORD

IFNDEF ECM_FIRST
    ECM_FIRST                                   EQU     01500H
ENDIF
EM_SETCUEBANNER                                 EQU     (ECM_FIRST + 1)

;========================================== Header ========================================;
WC_HEADERA                                      EQU     <SysHeader32>
WC_HEADERW                                      EQU     L("SysHeader32")

HDS_HORZ                                        EQU     00000H
HDS_BUTTONS                                     EQU     00002H
HDS_HOTTRACK                                    EQU     00004H
HDS_HIDDEN                                      EQU     00008H

HDS_DRAGDROP                                    EQU     00040H
HDS_FULLDRAG                                    EQU     00080H
HDS_FILTERBAR                                   EQU     00100H
HDS_FLAT                                        EQU     00200H

HDS_CHECKBOXES                                  EQU     00400H
HDS_NOSIZING                                    EQU     00800H
HDS_OVERFLOW                                    EQU     01000H

HDFT_ISSTRING                                   EQU     00000H
HDFT_ISNUMBER                                   EQU     00001H
HDFT_ISDATE                                     EQU     00002H
HDFT_HASNOVALUE                                 EQU     08000H

HDI_WIDTH                                       EQU     00001H
HDI_HEIGHT                                      EQU     HDI_WIDTH
HDI_TEXT                                        EQU     00002H
HDI_FORMAT                                      EQU     00004H
HDI_LPARAM                                      EQU     00008H
HDI_BITMAP                                      EQU     00010H
HDI_IMAGE                                       EQU     00020H
HDI_DI_SETITEM                                  EQU     00040H
HDI_ORDER                                       EQU     00080H
HDI_FILTER                                      EQU     00100H
HDI_STATE                                       EQU     00200H

HDF_LEFT                                        EQU     0
HDF_RIGHT                                       EQU     1
HDF_CENTER                                      EQU     2
HDF_JUSTIFYMASK                                 EQU     00003H
HDF_RTLREADING                                  EQU     4

HDF_OWNERDRAW                                   EQU     08000H
HDF_STRING                                      EQU     04000H
HDF_BITMAP                                      EQU     02000H
HDF_BITMAP_ON_RIGHT                             EQU     01000H
HDF_IMAGE                                       EQU     00800H
HDF_SORTUP                                      EQU     00400H
HDF_SORTDOWN                                    EQU     00200H
HDF_CHECKBOX                                    EQU     00040H
HDF_CHECKED                                     EQU     00080H
HDF_FIXEDWIDTH                                  EQU     00100H
HDF_SPLITBUTTON                                 EQU     01000000H

HHT_NOWHERE                                     EQU     00001H
HHT_ONHEADER                                    EQU     00002H
HHT_ONDIVIDER                                   EQU     00004H
HHT_ONDIVOPEN                                   EQU     00008H
HHT_ONFILTER                                    EQU     00010H
HHT_ONFILTERBUTTON                              EQU     00020H
HHT_ABOVE                                       EQU     00100H
HHT_BELOW                                       EQU     00200H
HHT_TORIGHT                                     EQU     00400H
HHT_TOLEFT                                      EQU     00800H
HHT_ONITEMSTATEICON                             EQU     01000H
HHT_ONDROPDOWN                                  EQU     02000H
HHT_ONOVERFLOW                                  EQU     04000H

HDSIL_NORMAL                                    EQU  0
HDSIL_STATE                                     EQU  1

HDM_GETITEMCOUNT                                EQU     (HDM_FIRST + 0)
HDM_INSERTITEMA                                 EQU     (HDM_FIRST + 1)
HDM_INSERTITEMW                                 EQU     (HDM_FIRST + 10)
HDM_DELETEITEM                                  EQU     (HDM_FIRST + 2)
HDM_GETITEMA                                    EQU     (HDM_FIRST + 3)
HDM_GETITEMW                                    EQU     (HDM_FIRST + 11)
HDM_SETITEMA                                    EQU     (HDM_FIRST + 4)
HDM_SETITEMW                                    EQU     (HDM_FIRST + 12)
HDM_LAYOUT                                      EQU     (HDM_FIRST + 5)

HDM_HITTEST                                     EQU     (HDM_FIRST + 6)
HDM_GETITEMRECT                                 EQU     (HDM_FIRST + 7)
HDM_SETIMAGELIST                                EQU     (HDM_FIRST + 8)
HDM_GETIMAGELIST                                EQU     (HDM_FIRST + 9)
HDM_ORDERTOINDEX                                EQU     (HDM_FIRST + 15)
HDM_CREATEDRAGIMAGE                             EQU     (HDM_FIRST + 16)
HDM_GETORDERARRAY                               EQU     (HDM_FIRST + 17)
HDM_SETORDERARRAY                               EQU     (HDM_FIRST + 18)
HDM_SETHOTDIVIDER                               EQU     (HDM_FIRST + 19)
HDM_SETBITMAPMARGIN                             EQU     (HDM_FIRST + 20)
HDM_GETBITMAPMARGIN                             EQU     (HDM_FIRST + 21)
HDM_SETFILTERCHANGETIMEOUT                      EQU     (HDM_FIRST + 22)
HDM_EDITFILTER                                  EQU     (HDM_FIRST + 23)
HDM_CLEARFILTER                                 EQU     (HDM_FIRST + 24)
HDM_GETITEMDROPDOWNRECT                         EQU     (HDM_FIRST + 25)
HDM_GETOVERFLOWRECT                             EQU     (HDM_FIRST + 26)
HDM_GETFOCUSEDITEM                              EQU     (HDM_FIRST + 27)
HDM_SETFOCUSEDITEM                              EQU     (HDM_FIRST + 28)

;HDM_TRANSLATEACCELERATOR                        EQU     CCM_TRANSLATEACCELERATOR
HDM_SETUNICODEFORMAT                            EQU     CCM_SETUNICODEFORMAT
HDM_GETUNICODEFORMAT                            EQU     CCM_GETUNICODEFORMAT

HDN_ITEMCHANGINGA                               EQU     (HDN_FIRST - 0)
HDN_ITEMCHANGINGW                               EQU     (HDN_FIRST - 20)
HDN_ITEMCHANGEDA                                EQU     (HDN_FIRST - 1)
HDN_ITEMCHANGEDW                                EQU     (HDN_FIRST - 21)
HDN_ITEMCLICKA                                  EQU     (HDN_FIRST - 2)
HDN_ITEMCLICKW                                  EQU     (HDN_FIRST - 22)
HDN_ITEMDBLCLICKA                               EQU     (HDN_FIRST - 3)
HDN_ITEMDBLCLICKW                               EQU     (HDN_FIRST - 23)
HDN_DIVIDERDBLCLICKA                            EQU     (HDN_FIRST - 5)
HDN_DIVIDERDBLCLICKW                            EQU     (HDN_FIRST - 25)
HDN_BEGINTRACKA                                 EQU     (HDN_FIRST - 6)
HDN_BEGINTRACKW                                 EQU     (HDN_FIRST - 26)
HDN_ENDTRACKA                                   EQU     (HDN_FIRST - 7)
HDN_ENDTRACKW                                   EQU     (HDN_FIRST - 27)
HDN_TRACKA                                      EQU     (HDN_FIRST - 8)
HDN_TRACKW                                      EQU     (HDN_FIRST - 28)
HDN_GETDISPINFOA                                EQU     (HDN_FIRST - 9)
HDN_GETDISPINFOW                                EQU     (HDN_FIRST - 29)
HDN_BEGINDRAG                                   EQU     (HDN_FIRST - 10)
HDN_ENDDRAG                                     EQU     (HDN_FIRST - 11)
HDN_FILTERCHANGE                                EQU     (HDN_FIRST - 12)
HDN_FILTERBTNCLICK                              EQU     (HDN_FIRST - 13)
HDN_BEGINFILTEREDIT                             EQU     (HDN_FIRST - 14)
HDN_ENDFILTEREDIT                               EQU     (HDN_FIRST - 15)
HDN_ITEMSTATEICONCLICK                          EQU     (HDN_FIRST - 16)
HDN_ITEMKEYDOWN                                 EQU     (HDN_FIRST - 17)
HDN_DROPDOWN                                    EQU     (HDN_FIRST - 18)
HDN_OVERFLOWCLICK                               EQU     (HDN_FIRST - 19)

;========================================== ToolBar =======================================;
TOOLBARCLASSNAMEA                               EQU     <ToolbarWindow32>
TOOLBARCLASSNAMEW                               EQU     L("ToolbarWindow32")

CMB_MASKED                                      EQU     002H

TBSTATE_CHECKED                                 EQU     001H
TBSTATE_PRESSED                                 EQU     002H
TBSTATE_ENABLED                                 EQU     004H
TBSTATE_HIDDEN                                  EQU     008H
TBSTATE_INDETERMINATE                           EQU     010H
TBSTATE_WRAP                                    EQU     020H
TBSTATE_ELLIPSES                                EQU     040H
TBSTATE_MARKED                                  EQU     080H
TBSTATE_HIGHLIGHTED                             EQU     080H

TBSTYLE_BUTTON                                  EQU     00000H
TBSTYLE_SEP                                     EQU     00001H
TBSTYLE_CHECK                                   EQU     00002H
TBSTYLE_GROUP                                   EQU     00004H
TBSTYLE_CHECKGROUP                              EQU     (TBSTYLE_GROUP OR TBSTYLE_CHECK)
TBSTYLE_DROPDOWN                                EQU     00008H
TBSTYLE_AUTOSIZE                                EQU     00010H
TBSTYLE_NOPREFIX                                EQU     00020H

TBSTYLE_TOOLTIPS                                EQU     00100H
TBSTYLE_WRAPABLE                                EQU     00200H
TBSTYLE_ALTDRAG                                 EQU     00400H
TBSTYLE_FLAT                                    EQU     00800H
TBSTYLE_LIST                                    EQU     01000H
TBSTYLE_CUSTOMERASE                             EQU     02000H
TBSTYLE_REGISTERDROP                            EQU     04000H
TBSTYLE_TRANSPARENT                             EQU     08000H
TBSTYLE_EX_DRAWDDARROWS                         EQU     000000001H
TBSTYLE_EX_MIXEDBUTTONS                         EQU     000000008H
TBSTYLE_EX_HIDECLIPPEDBUTTONS                   EQU     000000010H
TBSTYLE_EX_DOUBLEBUFFER                         EQU     000000080H

TBCDRF_NOEDGES                                  EQU     000010000H
TBCDRF_HILITEHOTTRACK                           EQU     000020000H
TBCDRF_NOOFFSET                                 EQU     000040000H
TBCDRF_NOMARK                                   EQU     000080000H
TBCDRF_NOETCHEDEFFECT                           EQU     000100000H
TBCDRF_BLENDICON                                EQU     000200000H
TBCDRF_NOBACKGROUND                             EQU     000400000H
TBCDRF_USECDCOLORS                              EQU     000800000H

HINST_COMMCTRL                                  EQU     (-1)
IDB_STD_SMALL_COLOR                             EQU     0
IDB_STD_LARGE_COLOR                             EQU     1
IDB_VIEW_SMALL_COLOR                            EQU     4
IDB_VIEW_LARGE_COLOR                            EQU     5
IDB_HIST_SMALL_COLOR                            EQU     8
IDB_HIST_LARGE_COLOR                            EQU     9
IDB_HIST_NORMAL                                 EQU     12
IDB_HIST_HOT                                    EQU     13
IDB_HIST_DISABLED                               EQU     14
IDB_HIST_PRESSED                                EQU     15

STD_CUT                                         EQU     0
STD_COPY                                        EQU     1
STD_PASTE                                       EQU     2
STD_UNDO                                        EQU     3
STD_REDOW                                       EQU     4
STD_DELETE                                      EQU     5
STD_FILENEW                                     EQU     6
STD_FILEOPEN                                    EQU     7
STD_FILESAVE                                    EQU     8
STD_PRINTPRE                                    EQU     9
STD_PROPERTIES                                  EQU     10
STD_HELP                                        EQU     11
STD_FIND                                        EQU     12
STD_REPLACE                                     EQU     13
STD_PRINT                                       EQU     14

VIEW_LARGEICONS                                 EQU     0
VIEW_SMALLICONS                                 EQU     1
VIEW_LIST                                       EQU     2
VIEW_DETAILS                                    EQU     3
VIEW_SORTNAME                                   EQU     4
VIEW_SORTSIZE                                   EQU     5
VIEW_SORTDATE                                   EQU     6
VIEW_SORTTYPE                                   EQU     7
VIEW_PARENTFOLDER                               EQU     8
VIEW_NETCONNECT                                 EQU     9
VIEW_NETDISCONNECT                              EQU     10
VIEW_NEWFOLDER                                  EQU     11
VIEW_VIEWMENU                                   EQU     12

HIST_BACK                                       EQU     0
HIST_FORWARD                                    EQU     1
HIST_FAVORITES                                  EQU     2
HIST_ADDTOFAVORITES                             EQU     3
HIST_VIEWTREE                                   EQU     4

TB_ENABLEBUTTON                                 EQU     (WM_USER + 1)
TB_CHECKBUTTON                                  EQU     (WM_USER + 2)
TB_PRESSBUTTON                                  EQU     (WM_USER + 3)
TB_HIDEBUTTON                                   EQU     (WM_USER + 4)
TB_INDETERMINATE                                EQU     (WM_USER + 5)
TB_MARKBUTTON                                   EQU     (WM_USER + 6)
TB_ISBUTTONENABLED                              EQU     (WM_USER + 9)
TB_ISBUTTONCHECKED                              EQU     (WM_USER + 10)
TB_ISBUTTONPRESSED                              EQU     (WM_USER + 11)
TB_ISBUTTONHIDDEN                               EQU     (WM_USER + 12)
TB_ISBUTTONINDETERMINATE                        EQU     (WM_USER + 13)
TB_ISBUTTONHIGHLIGHTED                          EQU     (WM_USER + 14)
TB_SETSTATE                                     EQU     (WM_USER + 17)
TB_GETSTATE                                     EQU     (WM_USER + 18)
TB_ADDBITMAP                                    EQU     (WM_USER + 19)
TB_ADDBUTTONSA                                  EQU     (WM_USER + 20)
TB_INSERTBUTTONA                                EQU     (WM_USER + 21)
TB_DELETEBUTTON                                 EQU     (WM_USER + 22)
TB_GETBUTTON                                    EQU     (WM_USER + 23)
TB_BUTTONCOUNT                                  EQU     (WM_USER + 24)
TB_COMMANDTOINDEX                               EQU     (WM_USER + 25)
TB_SAVERESTOREA                                 EQU     (WM_USER + 26)
TB_SAVERESTOREW                                 EQU     (WM_USER + 76)
TB_CUSTOMIZE                                    EQU     (WM_USER + 27)
TB_ADDSTRINGA                                   EQU     (WM_USER + 28)
TB_ADDSTRINGW                                   EQU     (WM_USER + 77)
TB_GETITEMRECT                                  EQU     (WM_USER + 29)
TB_BUTTONSTRUCTSIZE                             EQU     (WM_USER + 30)
TB_SETBUTTONSIZE                                EQU     (WM_USER + 31)
TB_SETBITMAPSIZE                                EQU     (WM_USER + 32)
TB_AUTOSIZE                                     EQU     (WM_USER + 33)
TB_GETTOOLTIPS                                  EQU     (WM_USER + 35)
TB_SETTOOLTIPS                                  EQU     (WM_USER + 36)
TB_SETPARENT                                    EQU     (WM_USER + 37)
TB_SETROWS                                      EQU     (WM_USER + 39)
TB_GETROWS                                      EQU     (WM_USER + 40)
TB_SETCMDID                                     EQU     (WM_USER + 42)
TB_CHANGEBITMAP                                 EQU     (WM_USER + 43)
TB_GETBITMAP                                    EQU     (WM_USER + 44)
TB_GETBUTTONTEXTA                               EQU     (WM_USER + 45)
TB_REPLACEBITMAP                                EQU     (WM_USER + 46)
TB_SETINDENT                                    EQU     (WM_USER + 47)
TB_SETIMAGELIST                                 EQU     (WM_USER + 48)
TB_GETIMAGELIST                                 EQU     (WM_USER + 49)
TB_LOADIMAGES                                   EQU     (WM_USER + 50)
TB_GETRECT                                      EQU     (WM_USER + 51)
TB_SETHOTIMAGELIST                              EQU     (WM_USER + 52)
TB_GETHOTIMAGELIST                              EQU     (WM_USER + 53)
TB_SETDISABLEDIMAGELIST                         EQU     (WM_USER + 54)
TB_GETDISABLEDIMAGELIST                         EQU     (WM_USER + 55)
TB_SETSTYLE                                     EQU     (WM_USER + 56)
TB_GETSTYLE                                     EQU     (WM_USER + 57)
TB_GETBUTTONSIZE                                EQU     (WM_USER + 58)
TB_SETBUTTONWIDTH                               EQU     (WM_USER + 59)
TB_SETMAXTEXTROWS                               EQU     (WM_USER + 60)
TB_GETTEXTROWS                                  EQU     (WM_USER + 61)
TB_GETOBJECT                                    EQU     (WM_USER + 62)
TB_GETBUTTONINFOW                               EQU     (WM_USER + 63)
TB_SETBUTTONINFOW                               EQU     (WM_USER + 64)
TB_GETBUTTONINFOA                               EQU     (WM_USER + 65)
TB_SETBUTTONINFOA                               EQU     (WM_USER + 66)
TB_INSERTBUTTONW                                EQU     (WM_USER + 67)
TB_ADDBUTTONSW                                  EQU     (WM_USER + 68)
TB_HITTEST                                      EQU     (WM_USER + 69)
TB_SETDRAWTEXTFLAGS                             EQU     (WM_USER + 70)
TB_GETHOTITEM                                   EQU     (WM_USER + 71)
TB_SETHOTITEM                                   EQU     (WM_USER + 72)
TB_SETANCHORHIGHLIGHT                           EQU     (WM_USER + 73)
TB_GETANCHORHIGHLIGHT                           EQU     (WM_USER + 74)
TB_GETBUTTONTEXTW                               EQU     (WM_USER + 75)
TB_MAPACCELERATORA                              EQU     (WM_USER + 78)
TB_GETINSERTMARK                                EQU     (WM_USER + 79)
TB_SETINSERTMARK                                EQU     (WM_USER + 80)
TB_INSERTMARKHITTEST                            EQU     (WM_USER + 81)
TB_MOVEBUTTON                                   EQU     (WM_USER + 82)
TB_GETMAXSIZE                                   EQU     (WM_USER + 83)
TB_SETEXTENDEDSTYLE                             EQU     (WM_USER + 84)
TB_GETEXTENDEDSTYLE                             EQU     (WM_USER + 85)
TB_GETPADDING                                   EQU     (WM_USER + 86)
TB_SETPADDING                                   EQU     (WM_USER + 87)
TB_SETINSERTMARKCOLOR                           EQU     (WM_USER + 88)
TB_GETINSERTMARKCOLOR                           EQU     (WM_USER + 89)
TB_SETCOLORSCHEME                               EQU     CCM_SETCOLORSCHEME
TB_GETCOLORSCHEME                               EQU     CCM_GETCOLORSCHEME
TB_SETUNICODEFORMAT                             EQU     CCM_SETUNICODEFORMAT
TB_GETUNICODEFORMAT                             EQU     CCM_GETUNICODEFORMAT
TB_MAPACCELERATORW                              EQU     (WM_USER + 90)
TB_GETSTRINGW                                   EQU     (WM_USER + 91)
TB_GETSTRINGA                                   EQU     (WM_USER + 92)
TB_GETMETRICS                                   EQU     (WM_USER + 101)
TB_SETMETRICS                                   EQU     (WM_USER + 102)
TB_SETPRESSEDIMAGELIST                          EQU     (WM_USER + 104)
TB_GETPRESSEDIMAGELIST                          EQU     (WM_USER + 105)

TB_SETWINDOWTHEME                               EQU     CCM_SETWINDOWTHEME

TBIMHT_AFTER                                    EQU     000000001H
TBIMHT_BACKGROUND                               EQU     000000002H

TBBF_LARGE                                      EQU     00001H

TBNRF_HIDEHELP                                  EQU     000000001H
TBNRF_ENDCUSTOMIZE                              EQU     000000002H

TB_GETBITMAPFLAGS                               EQU     (WM_USER + 41)

TBIF_IMAGE                                      EQU     000000001H
TBIF_TEXT                                       EQU     000000002H
TBIF_STATE                                      EQU     000000004H
TBIF_STYLE                                      EQU     000000008H
TBIF_LPARAM                                     EQU     000000010H
TBIF_COMMAND                                    EQU     000000020H
TBIF_SIZE                                       EQU     000000040H
TBIF_BYINDEX                                    EQU     080000000H

TBN_GETBUTTONINFOA                              EQU     (TBN_FIRST - 0)
TBN_BEGINDRAG                                   EQU     (TBN_FIRST - 1)
TBN_ENDDRAG                                     EQU     (TBN_FIRST - 2)
TBN_BEGINADJUST                                 EQU     (TBN_FIRST - 3)
TBN_ENDADJUST                                   EQU     (TBN_FIRST - 4)
TBN_RESET                                       EQU     (TBN_FIRST - 5)
TBN_QUERYINSERT                                 EQU     (TBN_FIRST - 6)
TBN_QUERYDELETE                                 EQU     (TBN_FIRST - 7)
TBN_TOOLBARCHANGE                               EQU     (TBN_FIRST - 8)
TBN_CUSTHELP                                    EQU     (TBN_FIRST - 9)
TBN_DROPDOWN                                    EQU     (TBN_FIRST - 10)
TBN_GETOBJECT                                   EQU     (TBN_FIRST - 12)
TBN_HOTITEMCHANGE                               EQU     (TBN_FIRST - 13)
TBN_DRAGOUT                                     EQU     (TBN_FIRST - 14)
TBN_DELETINGBUTTON                              EQU     (TBN_FIRST - 15)
TBN_GETDISPINFOA                                EQU     (TBN_FIRST - 16)
TBN_GETDISPINFOW                                EQU     (TBN_FIRST - 17)
TBN_GETINFOTIPA                                 EQU     (TBN_FIRST - 18)
TBN_GETINFOTIPW                                 EQU     (TBN_FIRST - 19)
TBN_GETBUTTONINFOW                              EQU     (TBN_FIRST - 20)
TBN_RESTORE                                     EQU     (TBN_FIRST - 21)
TBN_SAVE                                        EQU     (TBN_FIRST - 22)
TBN_INITCUSTOMIZE                               EQU     (TBN_FIRST - 23)

TBMF_PAD                                        EQU     000000001H
TBMF_BARPAD                                     EQU     000000002H
TBMF_BUTTONSPACING                              EQU     000000004H

HICF_OTHER                                      EQU     000000000H
HICF_MOUSE                                      EQU     000000001H
HICF_ARROWKEYS                                  EQU     000000002H
HICF_ACCELERATOR                                EQU     000000004H
HICF_DUPACCEL                                   EQU     000000008H
HICF_ENTERING                                   EQU     000000010H
HICF_LEAVING                                    EQU     000000020H
HICF_RESELECT                                   EQU     000000040H
HICF_LMOUSE                                     EQU     000000080H
HICF_TOGGLEDROPDOWN                             EQU     000000100H

TBNF_IMAGE                                      EQU     000000001H
TBNF_TEXT                                       EQU     000000002H
TBNF_DI_SETITEM                                 EQU     010000000H

TBDDRET_DEFAULT                                 EQU     0
TBDDRET_NODEFAULT                               EQU     1
TBDDRET_TREATPRESSED                            EQU     2

;=========================================== ReBar ========================================;
REBARCLASSNAMEA                                 EQU     <ReBarWindow32>
REBARCLASSNAMEW                                 EQU     L("ReBarWindow32")

RBIM_IMAGELIST                                  EQU     000000001H

RBS_TOOLTIPS                                    EQU     00100H
RBS_VARHEIGHT                                   EQU     00200H
RBS_BANDBORDERS                                 EQU     00400H
RBS_FIXEDORDER                                  EQU     00800H
RBS_REGISTERDROP                                EQU     01000H
RBS_AUTOSIZE                                    EQU     02000H
RBS_VERTICALGRIPPER                             EQU     04000H
RBS_DBLCLKTOGGLE                                EQU     08000H

RBBS_BREAK                                      EQU     000000001H
RBBS_FIXEDSIZE                                  EQU     000000002H
RBBS_CHILDEDGE                                  EQU     000000004H
RBBS_HIDDEN                                     EQU     000000008H
RBBS_NOVERT                                     EQU     000000010H
RBBS_FIXEDBMP                                   EQU     000000020H
RBBS_VARIABLEHEIGHT                             EQU     000000040H
RBBS_GRIPPERALWAYS                              EQU     000000080H
RBBS_NOGRIPPER                                  EQU     000000100H
RBBS_USECHEVRON                                 EQU     000000200H
RBBS_HIDETITLE                                  EQU     000000400H
RBBS_TOPALIGN                                   EQU     000000800H

RBBIM_STYLE                                     EQU     000000001H
RBBIM_COLORS                                    EQU     000000002H
RBBIM_TEXT                                      EQU     000000004H
RBBIM_IMAGE                                     EQU     000000008H
RBBIM_CHILD                                     EQU     000000010H
RBBIM_CHILDSIZE                                 EQU     000000020H
RBBIM_SIZE                                      EQU     000000040H
RBBIM_BACKGROUND                                EQU     000000080H
RBBIM_ID                                        EQU     000000100H
RBBIM_IDEALSIZE                                 EQU     000000200H
RBBIM_LPARAM                                    EQU     000000400H
RBBIM_HEADERSIZE                                EQU     000000800H
RBBIM_CHEVRONLOCATION                           EQU     000001000H
RBBIM_CHEVRONSTATE                              EQU     000002000H

RB_INSERTBANDA                                  EQU     (WM_USER + 1)
RB_DELETEBAND                                   EQU     (WM_USER + 2)
RB_GETBARINFO                                   EQU     (WM_USER + 3)
RB_SETBARINFO                                   EQU     (WM_USER + 4)
RB_SETBANDINFOA                                 EQU     (WM_USER + 6)
RB_SETPARENT                                    EQU     (WM_USER + 7)
RB_HITTEST                                      EQU     (WM_USER + 8)
RB_GETRECT                                      EQU     (WM_USER + 9)
RB_INSERTBANDW                                  EQU     (WM_USER + 10)
RB_SETBANDINFOW                                 EQU     (WM_USER + 11)
RB_GETBANDCOUNT                                 EQU     (WM_USER + 12)
RB_GETROWCOUNT                                  EQU     (WM_USER + 13)
RB_GETROWHEIGHT                                 EQU     (WM_USER + 14)
RB_IDTOINDEX                                    EQU     (WM_USER + 16)
RB_GETTOOLTIPS                                  EQU     (WM_USER + 17)
RB_SETTOOLTIPS                                  EQU     (WM_USER + 18)
RB_SETBKCOLOR                                   EQU     (WM_USER + 19)
RB_GETBKCOLOR                                   EQU     (WM_USER + 20)
RB_SETTEXTCOLOR                                 EQU     (WM_USER + 21)
RB_GETTEXTCOLOR                                 EQU     (WM_USER + 22)
RB_SIZETORECT                                   EQU     (WM_USER + 23)

RB_SETCOLORSCHEME                               EQU     CCM_SETCOLORSCHEME
RB_GETCOLORSCHEME                               EQU     CCM_GETCOLORSCHEME

RB_BEGINDRAG                                    EQU     (WM_USER + 24)
RB_ENDDRAG                                      EQU     (WM_USER + 25)
RB_DRAGMOVE                                     EQU     (WM_USER + 26)
RB_GETBARHEIGHT                                 EQU     (WM_USER + 27)
RB_GETBANDINFOW                                 EQU     (WM_USER + 28)
RB_GETBANDINFOA                                 EQU     (WM_USER + 29)
RB_MINIMIZEBAND                                 EQU     (WM_USER + 30)
RB_MAXIMIZEBAND                                 EQU     (WM_USER + 31)
RB_GETDROPTARGET                                EQU     (CCM_GETDROPTARGET)
RB_GETBANDBORDERS                               EQU     (WM_USER + 34)
RB_SHOWBAND                                     EQU     (WM_USER + 35)
RB_SETPALETTE                                   EQU     (WM_USER + 37)
RB_GETPALETTE                                   EQU     (WM_USER + 38)
RB_MOVEBAND                                     EQU     (WM_USER + 39)
RB_SETUNICODEFORMAT                             EQU     CCM_SETUNICODEFORMAT
RB_GETUNICODEFORMAT                             EQU     CCM_GETUNICODEFORMAT
RB_GETBANDMARGINS                               EQU     (WM_USER + 40)
RB_SETEXTENDEDSTYLE                             EQU     (WM_USER + 41)
RB_GETEXTENDEDSTYLE                             EQU     (WM_USER + 42)
RB_PUSHCHEVRON                                  EQU     (WM_USER + 43)
RB_SETBANDWIDTH                                 EQU     (WM_USER + 44)
RB_SETWINDOWTHEME                               EQU     CCM_SETWINDOWTHEME

RBN_HEIGHTCHANGE                                EQU     (RBN_FIRST - 0)
RBN_GETOBJECT                                   EQU     (RBN_FIRST - 1)
RBN_LAYOUTCHANGED                               EQU     (RBN_FIRST - 2)
RBN_AUTOSIZE                                    EQU     (RBN_FIRST - 3)
RBN_BEGINDRAG                                   EQU     (RBN_FIRST - 4)
RBN_ENDDRAG                                     EQU     (RBN_FIRST - 5)
RBN_DELETINGBAND                                EQU     (RBN_FIRST - 6)
RBN_DELETEDBAND                                 EQU     (RBN_FIRST - 7)
RBN_CHILDSIZE                                   EQU     (RBN_FIRST - 8)
RBN_CHEVRONPUSHED                               EQU     (RBN_FIRST - 10)
RBN_SPLITTERDRAG                                EQU     (RBN_FIRST - 11)
RBN_MINMAX                                      EQU     (RBN_FIRST - 21)
RBN_AUTOBREAK                                   EQU     (RBN_FIRST - 22)

RBNM_ID                                         EQU     000000001H
RBNM_STYLE                                      EQU     000000002H
RBNM_LPARAM                                     EQU     000000004H

RBHT_NOWHERE                                    EQU     00001H
RBHT_CAPTION                                    EQU     00002H
RBHT_CLIENT                                     EQU     00003H
RBHT_GRABBER                                    EQU     00004H
RBHT_CHEVRON                                    EQU     00008H
RBHT_SPLITTER                                   EQU     00010H

RBSTR_CHANGERECT                                EQU     00001H

RBAB_AUTOSIZE                                   EQU     00001H
RBAB_ADDBAND                                    EQU     00002H

;========================================= Tooltips =======================================;
TOOLTIPS_CLASSA                                 EQU     <tooltips_class32>
TOOLTIPS_CLASSW                                 EQU     L("tooltips_class32")

TTS_ALWAYSTIP                                   EQU     001H
TTS_NOPREFIX                                    EQU     002H
TTS_NOANIMATE                                   EQU     0010H
TTS_NOFADE                                      EQU     0020H
TTS_BALLOON                                     EQU     0040H
TTS_CLOSE                                       EQU     0080H
TTS_USEVISUALSTYLE                              EQU     0100H

TTF_IDISHWND                                    EQU     00001H

TTF_CENTERTIP                                   EQU     00002H
TTF_RTLREADING                                  EQU     00004H
TTF_SUBCLASS                                    EQU     00010H
TTF_TRACK                                       EQU     00020H
TTF_ABSOLUTE                                    EQU     00080H
TTF_TRANSPARENT                                 EQU     00100H
TTF_DI_SETITEM                                  EQU     08000H

TTDT_AUTOMATIC                                  EQU     0
TTDT_RESHOW                                     EQU     1
TTDT_AUTOPOP                                    EQU     2
TTDT_INITIAL                                    EQU     3

TTI_NONE                                        EQU     0
TTI_INFO                                        EQU     1
TTI_WARNING                                     EQU     2
TTI_ERROR                                       EQU     3
TTI_INFO_LARGE                                  EQU     4
TTI_WARNING_LARGE                               EQU     5
TTI_ERROR_LARGE                                 EQU     6

TTM_ACTIVATE                                    EQU     (WM_USER + 1)
TTM_SETDELAYTIME                                EQU     (WM_USER + 3)
TTM_ADDTOOLA                                    EQU     (WM_USER + 4)
TTM_DELTOOLA                                    EQU     (WM_USER + 5)
TTM_NEWTOOLRECTA                                EQU     (WM_USER + 6)
TTM_RELAYEVENT                                  EQU     (WM_USER + 7)
TTM_GETTOOLINFOA                                EQU     (WM_USER + 8)
TTM_SETTOOLINFOA                                EQU     (WM_USER + 9)
TTM_HITTESTA                                    EQU     (WM_USER + 10)
TTM_GETTEXTA                                    EQU     (WM_USER + 11)
TTM_UPDATETIPTEXTA                              EQU     (WM_USER + 12)
TTM_GETTOOLCOUNT                                EQU     (WM_USER + 13)
TTM_ENUMTOOLSA                                  EQU     (WM_USER + 14)
TTM_GETCURRENTTOOLA                             EQU     (WM_USER + 15)
TTM_WINDOWFROMPOINT                             EQU     (WM_USER + 16)
TTM_TRACKACTIVATE                               EQU     (WM_USER + 17)
TTM_TRACKPOSITION                               EQU     (WM_USER + 18)
TTM_SETTIPBKCOLOR                               EQU     (WM_USER + 19)
TTM_SETTIPTEXTCOLOR                             EQU     (WM_USER + 20)
TTM_GETDELAYTIME                                EQU     (WM_USER + 21)
TTM_GETTIPBKCOLOR                               EQU     (WM_USER + 22)
TTM_GETTIPTEXTCOLOR                             EQU     (WM_USER + 23)
TTM_SETMAXTIPWIDTH                              EQU     (WM_USER + 24)
TTM_GETMAXTIPWIDTH                              EQU     (WM_USER + 25)
TTM_SETMARGIN                                   EQU     (WM_USER + 26)
TTM_GETMARGIN                                   EQU     (WM_USER + 27)
TTM_POP                                         EQU     (WM_USER + 28)
TTM_UPDATE                                      EQU     (WM_USER + 29)
TTM_GETBUBBLESIZE                               EQU     (WM_USER + 30)
TTM_ADJUSTRECT                                  EQU     (WM_USER + 31)
TTM_SETTITLEA                                   EQU     (WM_USER + 32)
TTM_SETTITLEW                                   EQU     (WM_USER + 33)
TTM_POPUP                                       EQU     (WM_USER + 34)
TTM_GETTITLE                                    EQU     (WM_USER + 35)
TTM_SETWINDOWTHEME                              EQU     CCM_SETWINDOWTHEME

TTM_ADDTOOLW                                    EQU     (WM_USER + 50)
TTM_DELTOOLW                                    EQU     (WM_USER + 51)
TTM_NEWTOOLRECTW                                EQU     (WM_USER + 52)
TTM_GETTOOLINFOW                                EQU     (WM_USER + 53)
TTM_SETTOOLINFOW                                EQU     (WM_USER + 54)
TTM_HITTESTW                                    EQU     (WM_USER + 55)
TTM_GETTEXTW                                    EQU     (WM_USER + 56)
TTM_UPDATETIPTEXTW                              EQU     (WM_USER + 57)
TTM_ENUMTOOLSW                                  EQU     (WM_USER + 58)
TTM_GETCURRENTTOOLW                             EQU     (WM_USER + 59)

TTN_GETDISPINFOA                                EQU     (TTN_FIRST - 0)
TTN_GETDISPINFOW                                EQU     (TTN_FIRST - 10)
TTN_NEEDTEXTA                                   EQU     TTN_GETDISPINFOA
TTN_NEEDTEXTW                                   EQU     TTN_GETDISPINFOW
TTN_SHOW                                        EQU     (TTN_FIRST - 1)
TTN_POP                                         EQU     (TTN_FIRST - 2)
TTN_LINKCLICK                                   EQU     (TTN_FIRST - 3)

;======================================== StatusBar =======================================;
STATUSCLASSNAMEA                                EQU     <msctls_statusbar32>
STATUSCLASSNAMEW                                EQU     L("msctls_statusbar32")

SBARS_SIZEGRIP                                  EQU     0100H
SBARS_TOOLTIPS                                  EQU     0800H

SB_SETTEXTA                                     EQU     (WM_USER + 1)
SB_SETTEXTW                                     EQU     (WM_USER + 11)
SB_GETTEXTA                                     EQU     (WM_USER + 2)
SB_GETTEXTW                                     EQU     (WM_USER + 13)
SB_GETTEXTLENGTHA                               EQU     (WM_USER + 3)
SB_GETTEXTLENGTHW                               EQU     (WM_USER + 12)

SB_SETPARTS                                     EQU     (WM_USER + 4)
SB_GETPARTS                                     EQU     (WM_USER + 6)
SB_GETBORDERS                                   EQU     (WM_USER + 7)
SB_SETMINHEIGHT                                 EQU     (WM_USER + 8)
SB_SIMPLE                                       EQU     (WM_USER + 9)
SB_GETRECT                                      EQU     (WM_USER + 10)
SB_ISSIMPLE                                     EQU     (WM_USER + 14)
SB_SETICON                                      EQU     (WM_USER + 15)
SB_SETTIPTEXTA                                  EQU     (WM_USER + 16)
SB_SETTIPTEXTW                                  EQU     (WM_USER + 17)
SB_GETTIPTEXTA                                  EQU     (WM_USER + 18)
SB_GETTIPTEXTW                                  EQU     (WM_USER + 19)
SB_GETICON                                      EQU     (WM_USER + 20)
SB_SETUNICODEFORMAT                             EQU     CCM_SETUNICODEFORMAT
SB_GETUNICODEFORMAT                             EQU     CCM_GETUNICODEFORMAT

SBT_OWNERDRAW                                   EQU     1000H
SBT_NOBORDERS                                   EQU     0100H
SBT_POPOUT                                      EQU     0200H
SBT_RTLREADING                                  EQU     0400H
SBT_TOOLTIPS                                    EQU     0800H
SBT_NOTABPARSING                                EQU     0800H

SB_SETBKCOLOR                                   EQU     CCM_SETBKCOLOR

SBN_SIMPLEMODECHANGE                            EQU     (SBN_FIRST - 0)

SB_SIMPLEID                                     EQU     00FFH

MINSYSCOMMAND                                   EQU     0F000H

;======================================== TrackBar ========================================;
TRACKBAR_CLASSA                                 EQU     <msctls_trackbar32>
TRACKBAR_CLASSW                                 EQU     L("msctls_trackbar32")

TBS_AUTOTICKS                                   EQU     00001H
TBS_VERT                                        EQU     00002H
TBS_HORZ                                        EQU     00000H
TBS_TOP                                         EQU     00004H
TBS_BOTTOM                                      EQU     00000H
TBS_LEFT                                        EQU     00004H
TBS_RIGHT                                       EQU     00000H
TBS_BOTH                                        EQU     00008H
TBS_NOTICKS                                     EQU     00010H
TBS_ENABLESELRANGE                              EQU     00020H
TBS_FIXEDLENGTH                                 EQU     00040H
TBS_NOTHUMB                                     EQU     00080H
TBS_TOOLTIPS                                    EQU     00100H
TBS_REVERSED                                    EQU     00200H
TBS_DOWNISLEFT                                  EQU     00400H
TBS_NOTIFYBEFOREMOVE                            EQU     00800H
TBS_TRANSPARENTBKGND                            EQU     01000H

TBM_GETPOS                                      EQU     WM_USER
TBM_GETRANGEMIN                                 EQU     (WM_USER + 1)
TBM_GETRANGEMAX                                 EQU     (WM_USER + 2)
TBM_GETTIC                                      EQU     (WM_USER + 3)
TBM_SETTIC                                      EQU     (WM_USER + 4)
TBM_SETPOS                                      EQU     (WM_USER + 5)
TBM_SETRANGE                                    EQU     (WM_USER + 6)
TBM_SETRANGEMIN                                 EQU     (WM_USER + 7)
TBM_SETRANGEMAX                                 EQU     (WM_USER + 8)
TBM_CLEARTICS                                   EQU     (WM_USER + 9)
TBM_SETSEL                                      EQU     (WM_USER + 10)
TBM_SETSELSTART                                 EQU     (WM_USER + 11)
TBM_SETSELEND                                   EQU     (WM_USER + 12)
TBM_GETPTICS                                    EQU     (WM_USER + 14)
TBM_GETTICPOS                                   EQU     (WM_USER + 15)
TBM_GETNUMTICS                                  EQU     (WM_USER + 16)
TBM_GETSELSTART                                 EQU     (WM_USER + 17)
TBM_GETSELEND                                   EQU     (WM_USER + 18)
TBM_CLEARSEL                                    EQU     (WM_USER + 19)
TBM_SETTICFREQ                                  EQU     (WM_USER + 20)
TBM_SETPAGESIZE                                 EQU     (WM_USER + 21)
TBM_GETPAGESIZE                                 EQU     (WM_USER + 22)
TBM_SETLINESIZE                                 EQU     (WM_USER + 23)
TBM_GETLINESIZE                                 EQU     (WM_USER + 24)
TBM_GETTHUMBRECT                                EQU     (WM_USER + 25)
TBM_GETCHANNELRECT                              EQU     (WM_USER + 26)
TBM_SETTHUMBLENGTH                              EQU     (WM_USER + 27)
TBM_GETTHUMBLENGTH                              EQU     (WM_USER + 28)
TBM_SETTOOLTIPS                                 EQU     (WM_USER + 29)
TBM_GETTOOLTIPS                                 EQU     (WM_USER + 30)
TBM_SETTIPSIDE                                  EQU     (WM_USER + 31)
TBM_SETBUDDY                                    EQU     (WM_USER+32)
TBM_GETBUDDY                                    EQU     (WM_USER+33)
TBM_SETUNICODEFORMAT                            EQU     CCM_SETUNICODEFORMAT
TBM_GETUNICODEFORMAT                            EQU     CCM_GETUNICODEFORMAT

TBTS_TOP                                        EQU     0
TBTS_LEFT                                       EQU     1
TBTS_BOTTOM                                     EQU     2
TBTS_RIGHT                                      EQU     3

TB_LINEUP                                       EQU     0
TB_LINEDOWN                                     EQU     1
TB_PAGEUP                                       EQU     2
TB_PAGEDOWN                                     EQU     3
TB_THUMBPOSITION                                EQU     4
TB_THUMBTRACK                                   EQU     5
TB_TOP                                          EQU     6
TB_BOTTOM                                       EQU     7
TB_ENDTRACK                                     EQU     8

TBCD_TICS                                       EQU     00001H
TBCD_THUMB                                      EQU     00002H
TBCD_CHANNEL                                    EQU     00003H

TRBN_FIRST                                      EQU     (-1501)
TRBN_THUMBPOSCHANGING                           EQU     (TRBN_FIRST - 1)

DRAGLISTMSGSTRING                               EQU     <commctrl_DragListMsg>

DL_BEGINDRAG                                    EQU     (WM_USER + 133)
DL_DRAGGING                                     EQU     (WM_USER + 134)
DL_DROPPED                                      EQU     (WM_USER + 135)
DL_CANCELDRAG                                   EQU     (WM_USER + 136)

DL_CURSORSET                                    EQU     0
DL_STOPCURSOR                                   EQU     1
DL_COPYCURSOR                                   EQU     2
DL_MOVECURSOR                                   EQU     3

;========================================== UpDown ========================================;
UPDOWN_CLASSA                                   EQU     <msctls_updown32>
UPDOWN_CLASSW                                   EQU     L("msctls_updown32")

UD_MAXVAL                                       EQU     07FFFH
UD_MINVAL                                       EQU     (-UD_MAXVAL)

UDS_WRAP                                        EQU     00001H
UDS_SETBUDDYINT                                 EQU     00002H
UDS_ALIGNRIGHT                                  EQU     00004H
UDS_ALIGNLEFT                                   EQU     00008H
UDS_AUTOBUDDY                                   EQU     00010H
UDS_ARROWKEYS                                   EQU     00020H
UDS_HORZ                                        EQU     00040H
UDS_NOTHOUSANDS                                 EQU     00080H
UDS_HOTTRACK                                    EQU     00100H

UDM_SETRANGE                                    EQU     (WM_USER + 101)
UDM_GETRANGE                                    EQU     (WM_USER + 102)
UDM_SETPOS                                      EQU     (WM_USER + 103)
UDM_GETPOS                                      EQU     (WM_USER + 104)
UDM_SETBUDDY                                    EQU     (WM_USER + 105)
UDM_GETBUDDY                                    EQU     (WM_USER + 106)
UDM_SETACCEL                                    EQU     (WM_USER + 107)
UDM_GETACCEL                                    EQU     (WM_USER + 108)
UDM_SETBASE                                     EQU     (WM_USER + 109)
UDM_GETBASE                                     EQU     (WM_USER + 110)
UDM_SETRANGE32                                  EQU     (WM_USER + 111)
UDM_GETRANGE32                                  EQU     (WM_USER + 112)
UDM_SETUNICODEFORMAT                            EQU     CCM_SETUNICODEFORMAT
UDM_GETUNICODEFORMAT                            EQU     CCM_GETUNICODEFORMAT
UDM_SETPOS32                                    EQU     (WM_USER + 113)
UDM_GETPOS32                                    EQU     (WM_USER + 114)

UDN_DELTAPOS                                    EQU     (UDN_FIRST - 1)

;======================================= ProgressBar ======================================;
PROGRESS_CLASSA                                 EQU     <msctls_progress32>
PROGRESS_CLASSW                                 EQU     L("msctls_progress32")

PBS_SMOOTH                                      EQU     001H
PBS_VERTICAL                                    EQU     004H
PBS_MARQUEE                                     EQU     008H
PBS_SMOOTHREVERSE                               EQU     010H

PBM_SETRANGE                                    EQU     (WM_USER + 1)
PBM_SETPOS                                      EQU     (WM_USER + 2)
PBM_DELTAPOS                                    EQU     (WM_USER + 3)
PBM_SETSTEP                                     EQU     (WM_USER + 4)
PBM_STEPIT                                      EQU     (WM_USER + 5)
PBM_SETRANGE32                                  EQU     (WM_USER + 6)
PBM_GETRANGE                                    EQU     (WM_USER + 7)
PBM_GETPOS                                      EQU     (WM_USER + 8)
PBM_SETBARCOLOR                                 EQU     (WM_USER + 9)
PBM_SETBKCOLOR                                  EQU     CCM_SETBKCOLOR
PBM_SETMARQUEE                                  EQU     (WM_USER + 10)
PBM_GETSTEP                                     EQU     (WM_USER + 13)
PBM_GETBKCOLOR                                  EQU     (WM_USER + 14)
PBM_GETBARCOLOR                                 EQU     (WM_USER + 15)
PBM_SETSTATE                                    EQU     (WM_USER + 16)
PBM_GETSTATE                                    EQU     (WM_USER + 17)

HOTKEY_CLASSA                                   EQU     <msctls_hotkey32>
HOTKEY_CLASSW                                   EQU     L("msctls_hotkey32")

HOTKEYF_SHIFT                                   EQU     001H
HOTKEYF_CONTROL                                 EQU     002H
HOTKEYF_ALT                                     EQU     004H
HOTKEYF_EXT                                     EQU     008H

HKCOMB_NONE                                     EQU     00001H
HKCOMB_S                                        EQU     00002H
HKCOMB_C                                        EQU     00004H
HKCOMB_A                                        EQU     00008H
HKCOMB_SC                                       EQU     00010H
HKCOMB_SA                                       EQU     00020H
HKCOMB_CA                                       EQU     00040H
HKCOMB_SCA                                      EQU     00080H

HKM_SETHOTKEY                                   EQU     (WM_USER + 1)
HKM_GETHOTKEY                                   EQU     (WM_USER + 2)
HKM_SETRULES                                    EQU     (WM_USER + 3)

CCS_TOP                                         EQU     000000001H
CCS_NOMOVEY                                     EQU     000000002H
CCS_BOTTOM                                      EQU     000000003H
CCS_NORESIZE                                    EQU     000000004H
CCS_NOPARENTALIGN                               EQU     000000008H
CCS_ADJUSTABLE                                  EQU     000000020H
CCS_NODIVIDER                                   EQU     000000040H
CCS_VERT                                        EQU     000000080H
CCS_LEFT                                        EQU     (CCS_VERT OR CCS_TOP)
CCS_RIGHT                                       EQU     (CCS_VERT OR CCS_BOTTOM)
CCS_NOMOVEX                                     EQU     (CCS_VERT OR CCS_NOMOVEY)

;========================================= ListView =======================================;
WC_LISTVIEWA                                    EQU     <SysListView32>
WC_LISTVIEWW                                    EQU     L("SysListView32")

LVS_ICON                                        EQU     00000H
LVS_REPORT                                      EQU     00001H
LVS_SMALLICON                                   EQU     00002H
LVS_LIST                                        EQU     00003H
LVS_TYPEMASK                                    EQU     00003H
LVS_SINGLESEL                                   EQU     00004H
LVS_SHOWSELALWAYS                               EQU     00008H
LVS_SORTASCENDING                               EQU     00010H
LVS_SORTDESCENDING                              EQU     00020H
LVS_SHAREIMAGELISTS                             EQU     00040H
LVS_NOLABELWRAP                                 EQU     00080H
LVS_AUTOARRANGE                                 EQU     00100H
LVS_EDITLABELS                                  EQU     00200H
LVS_OWNERDATA                                   EQU     01000H
LVS_NOSCROLL                                    EQU     02000H
LVS_TYPESTYLEMASK                               EQU     0FC00H
LVS_ALIGNTOP                                    EQU     00000H
LVS_ALIGNLEFT                                   EQU     00800H
LVS_ALIGNMASK                                   EQU     00C00H
LVS_OWNERDRAWFIXED                              EQU     00400H
LVS_NOCOLUMNHEADER                              EQU     04000H
LVS_NOSORTHEADER                                EQU     08000H

LVS_EX_GRIDLINES                                EQU     000000001H
LVS_EX_SUBITEMIMAGES                            EQU     000000002H
LVS_EX_CHECKBOXES                               EQU     000000004H
LVS_EX_TRACKSELECT                              EQU     000000008H
LVS_EX_HEADERDRAGDROP                           EQU     000000010H
LVS_EX_FULLROWSELECT                            EQU     000000020H
LVS_EX_ONECLICKACTIVATE                         EQU     000000040H
LVS_EX_TWOCLICKACTIVATE                         EQU     000000080H
LVS_EX_FLATSB                                   EQU     000000100H
LVS_EX_REGIONAL                                 EQU     000000200H
LVS_EX_INFOTIP                                  EQU     000000400H
LVS_EX_UNDERLINEHOT                             EQU     000000800H
LVS_EX_UNDERLINECOLD                            EQU     000001000H
LVS_EX_MULTIWORKAREAS                           EQU     000002000H
LVS_EX_LABELTIP                                 EQU     000004000H
LVS_EX_BORDERSELECT                             EQU     000008000H
LVS_EX_DOUBLEBUFFER                             EQU     000010000H
LVS_EX_HIDELABELS                               EQU     000020000H
LVS_EX_SINGLEROW                                EQU     000040000H
LVS_EX_SNAPTOGRID                               EQU     000080000H
LVS_EX_SIMPLESELECT                             EQU     000100000H
LVS_EX_JUSTIFYCOLUMNS                           EQU     000200000H
LVS_EX_TRANSPARENTBKGND                         EQU     000400000H
LVS_EX_TRANSPARENTSHADOWTEXT                    EQU     000800000H
LVS_EX_AUTOAUTOARRANGE                          EQU     001000000H
LVS_EX_HEADERINALLVIEWS                         EQU     002000000H
LVS_EX_AUTOCHECKSELECT                          EQU     008000000H
LVS_EX_AUTOSIZECOLUMNS                          EQU     010000000H
LVS_EX_COLUMNSNAPPOINTS                         EQU     040000000H
LVS_EX_COLUMNOVERFLOW                           EQU     080000000H

LVSIL_NORMAL                                    EQU     0
LVSIL_SMALL                                     EQU     1
LVSIL_STATE                                     EQU     2

LVIF_TEXT                                       EQU     00001H
LVIF_IMAGE                                      EQU     00002H
LVIF_PARAM                                      EQU     00004H
LVIF_STATE                                      EQU     00008H
LVIF_INDENT                                     EQU     00010H
LVIF_NORECOMPUTE                                EQU     00800H
LVIF_GROUPID                                    EQU     00100H
LVIF_COLUMNS                                    EQU     00200H
LVIF_COLFMT                                     EQU     000010000H

LVIS_FOCUSED                                    EQU     00001H
LVIS_SELECTED                                   EQU     00002H
LVIS_CUT                                        EQU     00004H
LVIS_DROPHILITED                                EQU     00008H
LVIS_ACTIVATING                                 EQU     00020H

LVIS_OVERLAYMASK                                EQU     00F00H
LVIS_STATEIMAGEMASK                             EQU     0F000H

LPSTR_TEXTCALLBACKW                             EQU     (-1)
LPSTR_TEXTCALLBACKA                             EQU     (-1)

I_INDENTCALLBACK                                EQU     (-1)
I_IMAGECALLBACK                                 EQU     (-1)
I_IMAGENONE                                     EQU     (-2)

I_GROUPIDCALLBACK                               EQU     (-1)
I_GROUPIDNONE                                   EQU     (-2)

LVM_GETBKCOLOR                                  EQU     (LVM_FIRST + 0)
LVM_SETBKCOLOR                                  EQU     (LVM_FIRST + 1)
LVM_GETIMAGELIST                                EQU     (LVM_FIRST + 2)
LVM_SETIMAGELIST                                EQU     (LVM_FIRST + 3)
LVM_GETITEMCOUNT                                EQU     (LVM_FIRST + 4)
LVM_GETITEMA                                    EQU     (LVM_FIRST + 5)
LVM_SETITEMA                                    EQU     (LVM_FIRST + 6)
LVM_INSERTITEMA                                 EQU     (LVM_FIRST + 7)
LVM_DELETEITEM                                  EQU     (LVM_FIRST + 8)
LVM_DELETEALLITEMS                              EQU     (LVM_FIRST + 9)
LVM_GETCALLBACKMASK                             EQU     (LVM_FIRST + 10)
LVM_SETCALLBACKMASK                             EQU     (LVM_FIRST + 11)
LVM_GETNEXTITEM                                 EQU     (LVM_FIRST + 12)
LVM_FINDITEMA                                   EQU     (LVM_FIRST + 13)
LVM_GETITEMRECT                                 EQU     (LVM_FIRST + 14)
LVM_SETITEMPOSITION                             EQU     (LVM_FIRST + 15)
LVM_GETITEMPOSITION                             EQU     (LVM_FIRST + 16)
LVM_GETSTRINGWIDTHA                             EQU     (LVM_FIRST + 17)
LVM_HITTEST                                     EQU     (LVM_FIRST + 18)
LVM_ENSUREVISIBLE                               EQU     (LVM_FIRST + 19)
LVM_SCROLL                                      EQU     (LVM_FIRST + 20)
LVM_REDRAWITEMS                                 EQU     (LVM_FIRST + 21)
LVM_ARRANGE                                     EQU     (LVM_FIRST + 22)
LVM_EDITLABELA                                  EQU     (LVM_FIRST + 23)
LVM_GETEDITCONTROL                              EQU     (LVM_FIRST + 24)
LVM_GETCOLUMNA                                  EQU     (LVM_FIRST + 25)
LVM_SETCOLUMNA                                  EQU     (LVM_FIRST + 26)
LVM_INSERTCOLUMNA                               EQU     (LVM_FIRST + 27)
LVM_DELETECOLUMN                                EQU     (LVM_FIRST + 28)
LVM_GETCOLUMNWIDTH                              EQU     (LVM_FIRST + 29)
LVM_SETCOLUMNWIDTH                              EQU     (LVM_FIRST + 30)
LVM_GETHEADER                                   EQU     (LVM_FIRST + 31)
LVM_CREATEDRAGIMAGE                             EQU     (LVM_FIRST + 33)
LVM_GETVIEWRECT                                 EQU     (LVM_FIRST + 34)
LVM_GETTEXTCOLOR                                EQU     (LVM_FIRST + 35)
LVM_SETTEXTCOLOR                                EQU     (LVM_FIRST + 36)
LVM_GETTEXTBKCOLOR                              EQU     (LVM_FIRST + 37)
LVM_SETTEXTBKCOLOR                              EQU     (LVM_FIRST + 38)
LVM_GETTOPINDEX                                 EQU     (LVM_FIRST + 39)
LVM_GETCOUNTPERPAGE                             EQU     (LVM_FIRST + 40)
LVM_GETORIGIN                                   EQU     (LVM_FIRST + 41)
LVM_UPDATE                                      EQU     (LVM_FIRST + 42)
LVM_SETITEMSTATE                                EQU     (LVM_FIRST + 43)
LVM_GETITEMSTATE                                EQU     (LVM_FIRST + 44)
LVM_GETITEMTEXTA                                EQU     (LVM_FIRST + 45)
LVM_SETITEMTEXTA                                EQU     (LVM_FIRST + 46)
LVM_SETITEMCOUNT                                EQU     (LVM_FIRST + 47)
LVM_SORTITEMS                                   EQU     (LVM_FIRST + 48)
LVM_SETITEMPOSITION32                           EQU     (LVM_FIRST + 49)
LVM_GETSELECTEDCOUNT                            EQU     (LVM_FIRST + 50)
LVM_GETITEMSPACING                              EQU     (LVM_FIRST + 51)
LVM_GETISEARCHSTRINGA                           EQU     (LVM_FIRST + 52)
LVM_SETICONSPACING                              EQU     (LVM_FIRST + 53)
LVM_SETEXTENDEDLISTVIEWSTYLE                    EQU     (LVM_FIRST + 54)
LVM_GETEXTENDEDLISTVIEWSTYLE                    EQU     (LVM_FIRST + 55)
LVM_GETSUBITEMRECT                              EQU     (LVM_FIRST + 56)
LVM_SUBITEMHITTEST                              EQU     (LVM_FIRST + 57)
LVM_SETCOLUMNORDERARRAY                         EQU     (LVM_FIRST + 58)
LVM_GETCOLUMNORDERARRAY                         EQU     (LVM_FIRST + 59)
LVM_SETHOTITEM                                  EQU     (LVM_FIRST + 60)
LVM_GETHOTITEM                                  EQU     (LVM_FIRST + 61)
LVM_SETHOTCURSOR                                EQU     (LVM_FIRST + 62)
LVM_GETHOTCURSOR                                EQU     (LVM_FIRST + 63)
LVM_APPROXIMATEVIEWRECT                         EQU     (LVM_FIRST + 64)
LVM_SETWORKAREAS                                EQU     (LVM_FIRST + 65)
LVM_GETSELECTIONMARK                            EQU     (LVM_FIRST + 66)
LVM_SETSELECTIONMARK                            EQU     (LVM_FIRST + 67)
LVM_SETBKIMAGEA                                 EQU     (LVM_FIRST + 68)
LVM_GETBKIMAGEA                                 EQU     (LVM_FIRST + 69)
LVM_GETWORKAREAS                                EQU     (LVM_FIRST + 70)
LVM_SETHOVERTIME                                EQU     (LVM_FIRST + 71)
LVM_GETHOVERTIME                                EQU     (LVM_FIRST + 72)
LVM_GETNUMBEROFWORKAREAS                        EQU     (LVM_FIRST + 73)
LVM_SETTOOLTIPS                                 EQU     (LVM_FIRST + 74)
LVM_GETITEMW                                    EQU     (LVM_FIRST + 75)
LVM_SETITEMW                                    EQU     (LVM_FIRST + 76)
LVM_INSERTITEMW                                 EQU     (LVM_FIRST + 77)
LVM_GETTOOLTIPS                                 EQU     (LVM_FIRST + 78)
LVM_SORTITEMSEX                                 EQU     (LVM_FIRST + 81)
LVM_FINDITEMW                                   EQU     (LVM_FIRST + 83)
LVM_GETSTRINGWIDTHW                             EQU     (LVM_FIRST + 87)
LVM_GETCOLUMNW                                  EQU     (LVM_FIRST + 95)
LVM_SETCOLUMNW                                  EQU     (LVM_FIRST + 96)
LVM_INSERTCOLUMNW                               EQU     (LVM_FIRST + 97)

LVM_GETITEMTEXTW                                EQU     (LVM_FIRST + 115)
LVM_SETITEMTEXTW                                EQU     (LVM_FIRST + 116)
LVM_GETISEARCHSTRINGW                           EQU     (LVM_FIRST + 117)
LVM_EDITLABELW                                  EQU     (LVM_FIRST + 118)
LVM_SETBKIMAGEW                                 EQU     (LVM_FIRST + 138)
LVM_GETBKIMAGEW                                 EQU     (LVM_FIRST + 139)
LVM_SETSELECTEDCOLUMN                           EQU     (LVM_FIRST + 140)
LVM_SETTILEWIDTH                                EQU     (LVM_FIRST + 141)
LVM_SETVIEW                                     EQU     (LVM_FIRST + 142)
LVM_GETVIEW                                     EQU     (LVM_FIRST + 143)
LVM_INSERTGROUP                                 EQU     (LVM_FIRST + 145)
LVM_SETGROUPINFO                                EQU     (LVM_FIRST + 147)
LVM_GETGROUPINFO                                EQU     (LVM_FIRST + 149)
LVM_REMOVEGROUP                                 EQU     (LVM_FIRST + 150)
LVM_MOVEGROUP                                   EQU     (LVM_FIRST + 151)
LVM_MOVEITEMTOGROUP                             EQU     (LVM_FIRST + 154)
LVM_SETGROUPMETRICS                             EQU     (LVM_FIRST + 155)
LVM_GETGROUPMETRICS                             EQU     (LVM_FIRST + 156)
LVM_ENABLEGROUPVIEW                             EQU     (LVM_FIRST + 157)
LVM_SORTGROUPS                                  EQU     (LVM_FIRST + 158)
LVM_INSERTGROUPSORTED                           EQU     (LVM_FIRST + 159)
LVM_REMOVEALLGROUPS                             EQU     (LVM_FIRST + 160)
LVM_HASGROUP                                    EQU     (LVM_FIRST + 161)
LVM_SETTILEVIEWINFO                             EQU     (LVM_FIRST + 162)
LVM_GETTILEVIEWINFO                             EQU     (LVM_FIRST + 163)
LVM_SETTILEINFO                                 EQU     (LVM_FIRST + 164)
LVM_GETTILEINFO                                 EQU     (LVM_FIRST + 165)
LVM_SETINSERTMARK                               EQU     (LVM_FIRST + 166)
LVM_GETINSERTMARK                               EQU     (LVM_FIRST + 167)
LVM_INSERTMARKHITTEST                           EQU     (LVM_FIRST + 168)
LVM_GETINSERTMARKRECT                           EQU     (LVM_FIRST + 169)
LVM_SETINSERTMARKCOLOR                          EQU     (LVM_FIRST + 170)
LVM_GETINSERTMARKCOLOR                          EQU     (LVM_FIRST + 171)
LVM_SETINFOTIP                                  EQU     (LVM_FIRST + 173)
LVM_GETSELECTEDCOLUMN                           EQU     (LVM_FIRST + 174)
LVM_ISGROUPVIEWENABLED                          EQU     (LVM_FIRST + 175)
LVM_GETOUTLINECOLOR                             EQU     (LVM_FIRST + 176)
LVM_SETOUTLINECOLOR                             EQU     (LVM_FIRST + 177)
LVM_CANCELEDITLABEL                             EQU     (LVM_FIRST + 179)
LVM_MAPINDEXTOID                                EQU     (LVM_FIRST + 180)
LVM_MAPIDTOINDEX                                EQU     (LVM_FIRST + 181)
LVM_ISITEMVISIBLE                               EQU     (LVM_FIRST + 182)
LVM_GETEMPTYTEXT                                EQU     (LVM_FIRST + 204)
LVM_GETFOOTERRECT                               EQU     (LVM_FIRST + 205)
LVM_GETFOOTERINFO                               EQU     (LVM_FIRST + 206)
LVM_GETFOOTERITEMRECT                           EQU     (LVM_FIRST + 207)
LVM_GETFOOTERITEM                               EQU     (LVM_FIRST + 208)
LVM_GETITEMINDEXRECT                            EQU     (LVM_FIRST + 209)
LVM_SETITEMINDEXSTATE                           EQU     (LVM_FIRST + 210)
LVM_GETNEXTITEMINDEX                            EQU     (LVM_FIRST + 211)
LVM_SETUNICODEFORMAT                            EQU     CCM_SETUNICODEFORMAT
LVM_GETUNICODEFORMAT                            EQU     CCM_GETUNICODEFORMAT

LVNI_ALL                                        EQU     00000H
LVNI_FOCUSED                                    EQU     00001H
LVNI_SELECTED                                   EQU     00002H
LVNI_CUT                                        EQU     00004H
LVNI_DROPHILITED                                EQU     00008H

LVNI_ABOVE                                      EQU     00100H
LVNI_BELOW                                      EQU     00200H
LVNI_TOLEFT                                     EQU     00400H
LVNI_TORIGHT                                    EQU     00800H

LVFI_PARAM                                      EQU     00001H
LVFI_STRING                                     EQU     00002H
LVFI_PARTIAL                                    EQU     00008H
LVFI_WRAP                                       EQU     00020H
LVFI_NEARESTXY                                  EQU     00040H

LVIR_BOUNDS                                     EQU     0
LVIR_ICON                                       EQU     1
LVIR_LABEL                                      EQU     2
LVIR_SELECTBOUNDS                               EQU     3

LVHT_NOWHERE                                    EQU     00001H
LVHT_ONITEMICON                                 EQU     00002H
LVHT_ONITEMLABEL                                EQU     00004H
LVHT_ONITEMSTATEICON                            EQU     00008H
LVHT_ONITEM                                     EQU     (LVHT_ONITEMICON OR LVHT_ONITEMLABEL OR LVHT_ONITEMSTATEICON)

LVHT_ABOVE                                      EQU     00008H
LVHT_BELOW                                      EQU     00010H
LVHT_TORIGHT                                    EQU     00020H
LVHT_TOLEFT                                     EQU     00040H

LVHT_EX_GROUP_HEADER                            EQU     010000000H
LVHT_EX_GROUP_FOOTER                            EQU     020000000H
LVHT_EX_GROUP_COLLAPSE                          EQU     040000000H
LVHT_EX_GROUP_BACKGROUND                        EQU     080000000H
LVHT_EX_GROUP_STATEICON                         EQU     001000000H
LVHT_EX_GROUP_SUBSETLINK                        EQU     002000000H
LVHT_EX_GROUP                                   EQU     (LVHT_EX_GROUP_BACKGROUND OR LVHT_EX_GROUP_COLLAPSE OR LVHT_EX_GROUP_FOOTER OR LVHT_EX_GROUP_HEADER OR LVHT_EX_GROUP_STATEICON OR LVHT_EX_GROUP_SUBSETLINK)
LVHT_EX_ONCONTENTS                              EQU     004000000H
LVHT_EX_FOOTER                                  EQU     008000000H

LVA_DEFAULT                                     EQU     00000H
LVA_ALIGNLEFT                                   EQU     00001H
LVA_ALIGNTOP                                    EQU     00002H
LVA_SNAPTOGRID                                  EQU     00005H

LVCF_FMT                                        EQU     00001H
LVCF_WIDTH                                      EQU     00002H
LVCF_TEXT                                       EQU     00004H
LVCF_SUBITEM                                    EQU     00008H
LVCF_IMAGE                                      EQU     00010H
LVCF_ORDER                                      EQU     00020H
LVCF_MINWIDTH                                   EQU     00040H
LVCF_DEFAULTWIDTH                               EQU     00080H
LVCF_IDEALWIDTH                                 EQU     00100H

LVCFMT_LEFT                                     EQU     00000H
LVCFMT_RIGHT                                    EQU     00001H
LVCFMT_CENTER                                   EQU     00002H
LVCFMT_JUSTIFYMASK                              EQU     00003H
LVCFMT_IMAGE                                    EQU     00800H
LVCFMT_FIXED_WIDTH                              EQU     00100H
LVCFMT_BITMAP_ON_RIGHT                          EQU     01000H
LVCFMT_COL_HAS_IMAGES                           EQU     08000H

LVCFMT_NO_DPI_SCALE                             EQU     0040000H
LVCFMT_FIXED_RATIO                              EQU     0080000H
LVCFMT_LINE_BREAK                               EQU     0100000H
LVCFMT_FILL                                     EQU     0200000H
LVCFMT_WRAP                                     EQU     0400000H
LVCFMT_NO_TITLE                                 EQU     0800000H
LVCFMT_TILE_PLACEMENTMASK                       EQU     (LVCFMT_LINE_BREAK OR LVCFMT_FILL)
LVCFMT_SPLITBUTTON                              EQU     01000000H

LVSCW_AUTOSIZE                                  EQU     (-1)
LVSCW_AUTOSIZE_USEHEADER                        EQU     (-2)

LVSICF_NOINVALIDATEALL                          EQU     000000001H
LVSICF_NOSCROLL                                 EQU     000000002H

LV_MAX_WORKAREAS                                EQU     16

LVBKIF_SOURCE_NONE                              EQU     000000000H
LVBKIF_SOURCE_HBITMAP                           EQU     000000001H
LVBKIF_SOURCE_URL                               EQU     000000002H
LVBKIF_SOURCE_MASK                              EQU     000000003H
LVBKIF_STYLE_NORMAL                             EQU     000000000H
LVBKIF_STYLE_TILE                               EQU     000000010H
LVBKIF_STYLE_MASK                               EQU     000000010H
LVBKIF_FLAG_TILEOFFSET                          EQU     000000100H
LVBKIF_TYPE_WATERMARK                           EQU     010000000H
LVBKIF_FLAG_ALPHABLEND                          EQU     020000000H

LVKF_ALT                                        EQU     00001H
LVKF_CONTROL                                    EQU     00002H
LVKF_SHIFT                                      EQU     00004H

LV_VIEW_ICON                                    EQU     00000H
LV_VIEW_DETAILS                                 EQU     00001H
LV_VIEW_SMALLICON                               EQU     00002H
LV_VIEW_LIST                                    EQU     00003H
LV_VIEW_TILE                                    EQU     00004H
LV_VIEW_MAX                                     EQU     00004H

LVGF_NONE                                       EQU     000000000H
LVGF_HEADER                                     EQU     000000001H
LVGF_FOOTER                                     EQU     000000002H
LVGF_STATE                                      EQU     000000004H
LVGF_ALIGN                                      EQU     000000008H
LVGF_GROUPID                                    EQU     000000010H
LVGF_SUBTITLE                                   EQU     000000100H
LVGF_TASK                                       EQU     000000200H
LVGF_DESCRIPTIONTOP                             EQU     000000400H
LVGF_DESCRIPTIONBOTTOM                          EQU     000000800H
LVGF_TITLEIMAGE                                 EQU     000001000H
LVGF_EXTENDEDIMAGE                              EQU     000002000H
LVGF_ITEMS                                      EQU     000004000H
LVGF_SUBSET                                     EQU     000008000H
LVGF_SUBSETITEMS                                EQU     000010000H

LVGS_NORMAL                                     EQU     000000000H
LVGS_COLLAPSED                                  EQU     000000001H
LVGS_HIDDEN                                     EQU     000000002H
LVGS_NOHEADER                                   EQU     000000004H
LVGS_COLLAPSIBLE                                EQU     000000008H
LVGS_FOCUSED                                    EQU     000000010H
LVGS_SELECTED                                   EQU     000000020H
LVGS_SUBSETED                                   EQU     000000040H
LVGS_SUBSETLINKFOCUSED                          EQU     000000080H

LVGA_HEADER_LEFT                                EQU     000000001H
LVGA_HEADER_CENTER                              EQU     000000002H
LVGA_HEADER_RIGHT                               EQU     000000004H
LVGA_FOOTER_LEFT                                EQU     000000008H
LVGA_FOOTER_CENTER                              EQU     000000010H
LVGA_FOOTER_RIGHT                               EQU     000000020H

LVGMF_NONE                                      EQU     000000000H
LVGMF_BORDERSIZE                                EQU     000000001H
LVGMF_BORDERCOLOR                               EQU     000000002H
LVGMF_TEXTCOLOR                                 EQU     000000004H

LVTVIF_AUTOSIZE                                 EQU     000000000H
LVTVIF_FIXEDWIDTH                               EQU     000000001H
LVTVIF_FIXEDHEIGHT                              EQU     000000002H
LVTVIF_FIXEDSIZE                                EQU     000000003H
LVTVIF_EXTENDED                                 EQU     000000004H

LVTVIM_TILESIZE                                 EQU     000000001H
LVTVIM_COLUMNS                                  EQU     000000002H
LVTVIM_LABELMARGIN                              EQU     000000004H

LVN_ITEMCHANGING                                EQU     (LVN_FIRST - 0)
LVN_ITEMCHANGED                                 EQU     (LVN_FIRST - 1)
LVN_INSERTITEM                                  EQU     (LVN_FIRST - 2)
LVN_DELETEITEM                                  EQU     (LVN_FIRST - 3)
LVN_DELETEALLITEMS                              EQU     (LVN_FIRST - 4)
LVN_BEGINLABELEDITA                             EQU     (LVN_FIRST - 5)
LVN_ENDLABELEDITA                               EQU     (LVN_FIRST - 6)
LVN_COLUMNCLICK                                 EQU     (LVN_FIRST - 8)
LVN_BEGINDRAG                                   EQU     (LVN_FIRST - 9)
LVN_BEGINRDRAG                                  EQU     (LVN_FIRST - 11)
LVN_ODCACHEHINT                                 EQU     (LVN_FIRST - 13)
LVN_ITEMACTIVATE                                EQU     (LVN_FIRST - 14)
LVN_ODSTATECHANGED                              EQU     (LVN_FIRST - 15)
LVN_HOTTRACK                                    EQU     (LVN_FIRST - 21)
LVN_GETDISPINFOA                                EQU     (LVN_FIRST - 50)
LVN_SETDISPINFOA                                EQU     (LVN_FIRST - 51)
LVN_ODFINDITEMA                                 EQU     (LVN_FIRST - 52)
LVN_KEYDOWN                                     EQU     (LVN_FIRST - 55)
LVN_MARQUEEBEGIN                                EQU     (LVN_FIRST - 56)
LVN_GETINFOTIPA                                 EQU     (LVN_FIRST - 57)
LVN_GETINFOTIPW                                 EQU     (LVN_FIRST - 58)
LVN_INCREMENTALSEARCHA                          EQU     (LVN_FIRST - 62)
LVN_INCREMENTALSEARCHW                          EQU     (LVN_FIRST - 63)
LVN_COLUMNDROPDOWN                              EQU     (LVN_FIRST - 64)
LVN_COLUMNOVERFLOWCLICK                         EQU     (LVN_FIRST - 66)
LVN_BEGINLABELEDITW                             EQU     (LVN_FIRST - 75)
LVN_ENDLABELEDITW                               EQU     (LVN_FIRST - 76)
LVN_GETDISPINFOW                                EQU     (LVN_FIRST - 77)
LVN_SETDISPINFOW                                EQU     (LVN_FIRST - 78)
LVN_ODFINDITEMW                                 EQU     (LVN_FIRST - 79)
LVN_BEGINSCROLL                                 EQU     (LVN_FIRST - 80)
LVN_ENDSCROLL                                   EQU     (LVN_FIRST - 81)
LVN_LINKCLICK                                   EQU     (LVN_FIRST - 84)
LVN_GETEMPTYMARKUP                              EQU     (LVN_FIRST - 87)

LVIM_AFTER                                      EQU     000000001H

LVIF_DI_SETITEM                                 EQU     01000H

LVGIT_UNFOLDED                                  EQU     00001H

LVNSCH_DEFAULT                                  EQU     (-1)
LVNSCH_ERROR                                    EQU     (-2)
LVNSCH_IGNORE                                   EQU     (-3)

LVFIS_FOCUSED                                   EQU     00001H

LVFF_ITEMCOUNT                                  EQU     000000001H

LVCDI_ITEM                                      EQU     000000000H
LVCDI_GROUP                                     EQU     000000001H

LVCDRF_NOSELECT                                 EQU     000010000H
LVCDRF_NOGROUPFRAME                             EQU     000020000H

EMF_CENTERED                                    EQU     000000001H

LVFIF_TEXT                                      EQU     000000001H
LVFIF_STATE                                     EQU     000000002H

;========================================= TreeView =======================================;
WC_TREEVIEWA                                    EQU     <SysTreeView32>
WC_TREEVIEWW                                    EQU     L("SysTreeView32")

HTREEITEM                                       TYPEDEF XWORD

TVS_HASBUTTONS                                  EQU     00001H
TVS_HASLINES                                    EQU     00002H
TVS_LINESATROOT                                 EQU     00004H
TVS_EDITLABELS                                  EQU     00008H
TVS_DISABLEDRAGDROP                             EQU     00010H
TVS_SHOWSELALWAYS                               EQU     00020H
TVS_RTLREADING                                  EQU     00040H

TVS_NOTOOLTIPS                                  EQU     00080H
TVS_CHECKBOXES                                  EQU     00100H
TVS_TRACKSELECT                                 EQU     00200H
TVS_SINGLEEXPAND                                EQU     00400H
TVS_INFOTIP                                     EQU     00800H
TVS_FULLROWSELECT                               EQU     01000H
TVS_NOSCROLL                                    EQU     02000H
TVS_NONEVENHEIGHT                               EQU     04000H
TVS_NOHSCROLL                                   EQU     08000H

TVS_EX_MULTISELECT                              EQU     00002H
TVS_EX_DOUBLEBUFFER                             EQU     00004H
TVS_EX_NOINDENTSTATE                            EQU     00008H
TVS_EX_RICHTOOLTIP                              EQU     00010H
TVS_EX_AUTOHSCROLL                              EQU     00020H
TVS_EX_FADEINOUTEXPANDOS                        EQU     00040H
TVS_EX_PARTIALCHECKBOXES                        EQU     00080H
TVS_EX_EXCLUSIONCHECKBOXES                      EQU     00100H
TVS_EX_DIMMEDCHECKBOXES                         EQU     00200H
TVS_EX_DRAWIMAGEASYNC                           EQU     00400H

TVIF_TEXT                                       EQU     00001H
TVIF_IMAGE                                      EQU     00002H
TVIF_PARAM                                      EQU     00004H
TVIF_STATE                                      EQU     00008H
TVIF_HANDLE                                     EQU     00010H
TVIF_SELECTEDIMAGE                              EQU     00020H
TVIF_CHILDREN                                   EQU     00040H
TVIF_INTEGRAL                                   EQU     00080H

TVIS_SELECTED                                   EQU     00002H
TVIS_CUT                                        EQU     00004H
TVIS_DROPHILITED                                EQU     00008H
TVIS_BOLD                                       EQU     00010H
TVIS_EXPANDED                                   EQU     00020H
TVIS_EXPANDEDONCE                               EQU     00040H
TVIS_EXPANDPARTIAL                              EQU     00080H

TVIS_OVERLAYMASK                                EQU     00F00H
TVIS_STATEIMAGEMASK                             EQU     0F000H
TVIS_USERMASK                                   EQU     0F000H

TVIS_EX_FLAT                                    EQU     00001H
TVIS_EX_DISABLED                                EQU     00002H
TVIS_EX_ALL                                     EQU     00002H

I_CHILDRENCALLBACK                              EQU     (-1)

TVI_ROOT                                        EQU     (-010000H)
TVI_FIRST                                       EQU     (-00FFFFH)
TVI_LAST                                        EQU     (-00FFFEH)
TVI_SORT                                        EQU     (-00FFFDH)

TVE_COLLAPSE                                    EQU     00001H
TVE_EXPAND                                      EQU     00002H
TVE_TOGGLE                                      EQU     00003H
TVE_EXPANDPARTIAL                               EQU     04000H
TVE_COLLAPSERESET                               EQU     08000H

TVSIL_NORMAL                                    EQU     0
TVSIL_STATE                                     EQU     2

TVGN_ROOT                                       EQU     00000H
TVGN_NEXT                                       EQU     00001H
TVGN_PREVIOUS                                   EQU     00002H
TVGN_PARENT                                     EQU     00003H
TVGN_CHILD                                      EQU     00004H
TVGN_FIRSTVISIBLE                               EQU     00005H
TVGN_NEXTVISIBLE                                EQU     00006H
TVGN_PREVIOUSVISIBLE                            EQU     00007H
TVGN_DROPHILITE                                 EQU     00008H
TVGN_CARET                                      EQU     00009H
TVGN_LASTVISIBLE                                EQU     0000AH
TVGN_NEXTSELECTED                               EQU     0000BH

TV_HITTESTINFO                                  EQU     TVHITTESTINFO

TVSI_NOSINGLEEXPAND                             EQU     08000H

TVHT_NOWHERE                                    EQU     00001H
TVHT_ONITEMICON                                 EQU     00002H
TVHT_ONITEMLABEL                                EQU     00004H
TVHT_ONITEM                                     EQU     (TVHT_ONITEMICON OR TVHT_ONITEMLABEL OR TVHT_ONITEMSTATEICON)
TVHT_ONITEMINDENT                               EQU     00008H
TVHT_ONITEMBUTTON                               EQU     00010H
TVHT_ONITEMRIGHT                                EQU     00020H
TVHT_ONITEMSTATEICON                            EQU     00040H

TVHT_ABOVE                                      EQU     00100H
TVHT_BELOW                                      EQU     00200H
TVHT_TORIGHT                                    EQU     00400H
TVHT_TOLEFT                                     EQU     00800H

TVGIPR_BUTTON                                   EQU     00001H

TVIF_DI_SETITEM                                 EQU     01000H

TVM_INSERTITEMA                                 EQU     (TV_FIRST + 0)
TVM_DELETEITEM                                  EQU     (TV_FIRST + 1)
TVM_EXPAND                                      EQU     (TV_FIRST + 2)
TVM_GETITEMRECT                                 EQU     (TV_FIRST + 4)
TVM_GETCOUNT                                    EQU     (TV_FIRST + 5)
TVM_GETINDENT                                   EQU     (TV_FIRST + 6)
TVM_SETINDENT                                   EQU     (TV_FIRST + 7)
TVM_GETIMAGELIST                                EQU     (TV_FIRST + 8)
TVM_SETIMAGELIST                                EQU     (TV_FIRST + 9)
TVM_GETNEXTITEM                                 EQU     (TV_FIRST + 10)
TVM_SELECTITEM                                  EQU     (TV_FIRST + 11)
TVM_GETITEMA                                    EQU     (TV_FIRST + 12)
TVM_SETITEMA                                    EQU     (TV_FIRST + 13)
TVM_EDITLABELA                                  EQU     (TV_FIRST + 14)
TVM_GETEDITCONTROL                              EQU     (TV_FIRST + 15)
TVM_GETVISIBLECOUNT                             EQU     (TV_FIRST + 16)
TVM_HITTEST                                     EQU     (TV_FIRST + 17)
TVM_CREATEDRAGIMAGE                             EQU     (TV_FIRST + 18)
TVM_SORTCHILDREN                                EQU     (TV_FIRST + 19)
TVM_ENSUREVISIBLE                               EQU     (TV_FIRST + 20)
TVM_SORTCHILDRENCB                              EQU     (TV_FIRST + 21)
TVM_ENDEDITLABELNOW                             EQU     (TV_FIRST + 22)
TVM_GETISEARCHSTRINGA                           EQU     (TV_FIRST + 23)
TVM_SETTOOLTIPS                                 EQU     (TV_FIRST + 24)
TVM_GETTOOLTIPS                                 EQU     (TV_FIRST + 25)
TVM_SETINSERTMARK                               EQU     (TV_FIRST + 26)
TVM_SETITEMHEIGHT                               EQU     (TV_FIRST + 27)
TVM_GETITEMHEIGHT                               EQU     (TV_FIRST + 28)
TVM_SETBKCOLOR                                  EQU     (TV_FIRST + 29)
TVM_SETTEXTCOLOR                                EQU     (TV_FIRST + 30)
TVM_GETBKCOLOR                                  EQU     (TV_FIRST + 31)
TVM_GETTEXTCOLOR                                EQU     (TV_FIRST + 32)
TVM_SETSCROLLTIME                               EQU     (TV_FIRST + 33)
TVM_GETSCROLLTIME                               EQU     (TV_FIRST + 34)
TVM_SETINSERTMARKCOLOR                          EQU     (TV_FIRST + 37)
TVM_GETINSERTMARKCOLOR                          EQU     (TV_FIRST + 38)
TVM_GETITEMSTATE                                EQU     (TV_FIRST + 39)
TVM_SETLINECOLOR                                EQU     (TV_FIRST + 40)
TVM_GETLINECOLOR                                EQU     (TV_FIRST + 41)
TVM_MAPACCIDTOHTREEITEM                         EQU     (TV_FIRST + 42)
TVM_MAPHTREEITEMTOACCID                         EQU     (TV_FIRST + 43)
TVM_SETEXTENDEDSTYLE                            EQU     (TV_FIRST + 44)
TVM_GETEXTENDEDSTYLE                            EQU     (TV_FIRST + 45)
TVM_INSERTITEMW                                 EQU     (TV_FIRST + 50)
TVM_SETAUTOSCROLLINFO                           EQU     (TV_FIRST + 59)
TVM_GETITEMW                                    EQU     (TV_FIRST + 62)
TVM_SETITEMW                                    EQU     (TV_FIRST + 63)
TVM_GETISEARCHSTRINGW                           EQU     (TV_FIRST + 64)
TVM_EDITLABELW                                  EQU     (TV_FIRST + 65)
TVM_GETSELECTEDCOUNT                            EQU     (TV_FIRST + 70)
TVM_SHOWINFOTIP                                 EQU     (TV_FIRST + 71)
TVM_GETITEMPARTRECT                             EQU     (TV_FIRST + 72)
TVM_SETUNICODEFORMAT                            EQU     CCM_SETUNICODEFORMAT
TVM_GETUNICODEFORMAT                            EQU     CCM_GETUNICODEFORMAT

TVN_SELCHANGINGA                                EQU     (TVN_FIRST - 1)
TVN_SELCHANGEDA                                 EQU     (TVN_FIRST - 2)
TVN_GETDISPINFOA                                EQU     (TVN_FIRST - 3)
TVN_SETDISPINFOA                                EQU     (TVN_FIRST - 4)
TVN_ITEMEXPANDINGA                              EQU     (TVN_FIRST - 5)
TVN_ITEMEXPANDEDA                               EQU     (TVN_FIRST - 6)
TVN_BEGINDRAGA                                  EQU     (TVN_FIRST - 7)
TVN_BEGINRDRAGA                                 EQU     (TVN_FIRST - 8)
TVN_DELETEITEMA                                 EQU     (TVN_FIRST - 9)
TVN_BEGINLABELEDITA                             EQU     (TVN_FIRST - 10)
TVN_ENDLABELEDITA                               EQU     (TVN_FIRST - 11)
TVN_KEYDOWN                                     EQU     (TVN_FIRST - 12)
TVN_GETINFOTIPA                                 EQU     (TVN_FIRST - 13)
TVN_GETINFOTIPW                                 EQU     (TVN_FIRST - 14)
TVN_SINGLEEXPAND                                EQU     (TVN_FIRST - 15)
TVN_ITEMCHANGINGA                               EQU     (TVN_FIRST - 16)
TVN_ITEMCHANGINGW                               EQU     (TVN_FIRST - 17)
TVN_ITEMCHANGEDA                                EQU     (TVN_FIRST - 18)
TVN_ITEMCHANGEDW                                EQU     (TVN_FIRST - 19)
TVN_ASYNCDRAW                                   EQU     (TVN_FIRST - 20)
TVN_SELCHANGINGW                                EQU     (TVN_FIRST - 50)
TVN_SELCHANGEDW                                 EQU     (TVN_FIRST - 51)
TVN_GETDISPINFOW                                EQU     (TVN_FIRST - 52)
TVN_SETDISPINFOW                                EQU     (TVN_FIRST - 53)
TVN_ITEMEXPANDINGW                              EQU     (TVN_FIRST - 54)
TVN_ITEMEXPANDEDW                               EQU     (TVN_FIRST - 55)
TVN_BEGINDRAGW                                  EQU     (TVN_FIRST - 56)
TVN_BEGINRDRAGW                                 EQU     (TVN_FIRST - 57)
TVN_DELETEITEMW                                 EQU     (TVN_FIRST - 58)
TVN_BEGINLABELEDITW                             EQU     (TVN_FIRST - 59)
TVN_ENDLABELEDITW                               EQU     (TVN_FIRST - 60)

TVC_UNKNOWN                                     EQU     00000H
TVC_BYMOUSE                                     EQU     00001H
TVC_BYKEYBOARD                                  EQU     00002H

TVNRET_DEFAULT                                  EQU     0
TVNRET_SKIPOLD                                  EQU     1
TVNRET_SKIPNEW                                  EQU     2

TVCDRF_NOIMAGES                                 EQU     000010000H

;======================================== ComboBoxEx ======================================;
WC_COMBOBOXEXA                                  EQU     <ComboBoxEx32>
WC_COMBOBOXEXW                                  EQU     L("ComboBoxEx32")

CB_DELETESTRING                                 EQU     0144H

CBEIF_TEXT                                      EQU     000000001H
CBEIF_IMAGE                                     EQU     000000002H
CBEIF_SELECTEDIMAGE                             EQU     000000004H
CBEIF_OVERLAY                                   EQU     000000008H
CBEIF_INDENT                                    EQU     000000010H
CBEIF_LPARAM                                    EQU     000000020H

CBEIF_DI_SETITEM                                EQU     010000000H

CBEM_INSERTITEMA                                EQU     (WM_USER + 1)
CBEM_SETIMAGELIST                               EQU     (WM_USER + 2)
CBEM_GETIMAGELIST                               EQU     (WM_USER + 3)
CBEM_GETITEMA                                   EQU     (WM_USER + 4)
CBEM_SETITEMA                                   EQU     (WM_USER + 5)
CBEM_DELETEITEM                                 EQU     CB_DELETESTRING
CBEM_GETCOMBOCONTROL                            EQU     (WM_USER + 6)
CBEM_GETEDITCONTROL                             EQU     (WM_USER + 7)
CBEM_SETEXSTYLE                                 EQU     (WM_USER + 8)
CBEM_GETEXSTYLE                                 EQU     (WM_USER + 9)
CBEM_GETEXTENDEDSTYLE                           EQU     (WM_USER + 9)
CBEM_HASEDITCHANGED                             EQU     (WM_USER + 10)
CBEM_INSERTITEMW                                EQU     (WM_USER + 11)
CBEM_SETITEMW                                   EQU     (WM_USER + 12)
CBEM_GETITEMW                                   EQU     (WM_USER + 13)
CBEM_SETEXTENDEDSTYLE                           EQU     (WM_USER + 14)
CBEM_SETUNICODEFORMAT                           EQU     CCM_SETUNICODEFORMAT
CBEM_GETUNICODEFORMAT                           EQU     CCM_GETUNICODEFORMAT
CBEM_SETWINDOWTHEME                             EQU     CCM_SETWINDOWTHEME

CBES_EX_NOEDITIMAGE                             EQU     000000001H
CBES_EX_NOEDITIMAGEINDENT                       EQU     000000002H
CBES_EX_PATHWORDBREAKPROC                       EQU     000000004H
CBES_EX_NOSIZELIMIT                             EQU     000000008H
CBES_EX_CASESENSITIVE                           EQU     000000010H
CBES_EX_TEXTENDELLIPSIS                         EQU     000000020H

CBEN_GETDISPINFOA                               EQU     (CBEN_FIRST - 0)
CBEN_INSERTITEM                                 EQU     (CBEN_FIRST - 1)
CBEN_DELETEITEM                                 EQU     (CBEN_FIRST - 2)
CBEN_BEGINEDIT                                  EQU     (CBEN_FIRST - 4)
CBEN_ENDEDITA                                   EQU     (CBEN_FIRST - 5)
CBEN_ENDEDITW                                   EQU     (CBEN_FIRST - 6)
CBEN_GETDISPINFOW                               EQU     (CBEN_FIRST - 7)
CBEN_DRAGBEGINA                                 EQU     (CBEN_FIRST - 8)
CBEN_DRAGBEGINW                                 EQU     (CBEN_FIRST - 9)

CBENF_KILLFOCUS                                 EQU     1
CBENF_RETURN                                    EQU     2
CBENF_ESCAPE                                    EQU     3
CBENF_DROPDOWN                                  EQU     4

CBEMAXSTRLEN                                    EQU     260

;=========================================== Tab ==========================================;
WC_TABCONTROLA                                  EQU     <SysTabControl32>
WC_TABCONTROLW                                  EQU     L("SysTabControl32")

TCS_SCROLLOPPOSITE                              EQU     00001H
TCS_BOTTOM                                      EQU     00002H
TCS_RIGHT                                       EQU     00002H
TCS_MULTISELECT                                 EQU     00004H
TCS_FLATBUTTONS                                 EQU     00008H
TCS_FORCEICONLEFT                               EQU     00010H
TCS_FORCELABELLEFT                              EQU     00020H
TCS_HOTTRACK                                    EQU     00040H
TCS_VERTICAL                                    EQU     00080H
TCS_TABS                                        EQU     00000H
TCS_BUTTONS                                     EQU     00100H
TCS_SINGLELINE                                  EQU     00000H
TCS_MULTILINE                                   EQU     00200H
TCS_RIGHTJUSTIFY                                EQU     00000H
TCS_FIXEDWIDTH                                  EQU     00400H
TCS_RAGGEDRIGHT                                 EQU     00800H
TCS_FOCUSONBUTTONDOWN                           EQU     01000H
TCS_OWNERDRAWFIXED                              EQU     02000H
TCS_TOOLTIPS                                    EQU     04000H
TCS_FOCUSNEVER                                  EQU     08000H

TCS_EX_FLATSEPARATORS                           EQU     000000001H
TCS_EX_REGISTERDROP                             EQU     000000002H

TCIF_TEXT                                       EQU     00001H
TCIF_IMAGE                                      EQU     00002H
TCIF_RTLREADING                                 EQU     00004H
TCIF_PARAM                                      EQU     00008H
TCIF_STATE                                      EQU     00010H

TCIS_BUTTONPRESSED                              EQU     00001H
TCIS_HIGHLIGHTED                                EQU     00002H

TCHT_NOWHERE                                    EQU     00001H
TCHT_ONITEMICON                                 EQU     00002H
TCHT_ONITEMLABEL                                EQU     00004H
TCHT_ONITEM                                     EQU     (TCHT_ONITEMICON OR TCHT_ONITEMLABEL)
TCM_GETIMAGELIST                                EQU     (TCM_FIRST + 2)
TCM_SETIMAGELIST                                EQU     (TCM_FIRST + 3)
TCM_GETITEMCOUNT                                EQU     (TCM_FIRST + 4)
TCM_GETITEMA                                    EQU     (TCM_FIRST + 5)
TCM_SETITEMA                                    EQU     (TCM_FIRST + 6)
TCM_INSERTITEMA                                 EQU     (TCM_FIRST + 7)
TCM_DELETEITEM                                  EQU     (TCM_FIRST + 8)
TCM_DELETEALLITEMS                              EQU     (TCM_FIRST + 9)
TCM_GETITEMRECT                                 EQU     (TCM_FIRST + 10)
TCM_GETCURSEL                                   EQU     (TCM_FIRST + 11)
TCM_SETCURSEL                                   EQU     (TCM_FIRST + 12)
TCM_HITTEST                                     EQU     (TCM_FIRST + 13)
TCM_SETITEMEXTRA                                EQU     (TCM_FIRST + 14)
TCM_ADJUSTRECT                                  EQU     (TCM_FIRST + 40)
TCM_SETITEMSIZE                                 EQU     (TCM_FIRST + 41)
TCM_REMOVEIMAGE                                 EQU     (TCM_FIRST + 42)
TCM_SETPADDING                                  EQU     (TCM_FIRST + 43)
TCM_GETROWCOUNT                                 EQU     (TCM_FIRST + 44)
TCM_GETTOOLTIPS                                 EQU     (TCM_FIRST + 45)
TCM_SETTOOLTIPS                                 EQU     (TCM_FIRST + 46)
TCM_GETCURFOCUS                                 EQU     (TCM_FIRST + 47)
TCM_SETCURFOCUS                                 EQU     (TCM_FIRST + 48)
TCM_SETMINTABWIDTH                              EQU     (TCM_FIRST + 49)
TCM_DESELECTALL                                 EQU     (TCM_FIRST + 50)
TCM_HIGHLIGHTITEM                               EQU     (TCM_FIRST + 51)
TCM_SETEXTENDEDSTYLE                            EQU     (TCM_FIRST + 52)
TCM_GETEXTENDEDSTYLE                            EQU     (TCM_FIRST + 53)
TCM_GETITEMW                                    EQU     (TCM_FIRST + 60)
TCM_SETITEMW                                    EQU     (TCM_FIRST + 61)
TCM_INSERTITEMW                                 EQU     (TCM_FIRST + 62)
TCM_SETUNICODEFORMAT                            EQU     CCM_SETUNICODEFORMAT
TCM_GETUNICODEFORMAT                            EQU     CCM_GETUNICODEFORMAT

TCN_KEYDOWN                                     EQU     (TCN_FIRST - 0)
TCN_SELCHANGE                                   EQU     (TCN_FIRST - 1)
TCN_SELCHANGING                                 EQU     (TCN_FIRST - 2)
TCN_GETOBJECT                                   EQU     (TCN_FIRST - 3)
TCN_FOCUSCHANGE                                 EQU     (TCN_FIRST - 4)

;========================================= Animate ========================================;
ANIMATE_CLASSA                                  EQU     <SysAnimate32>
ANIMATE_CLASSW                                  EQU     L("SysAnimate32")

ACS_CENTER                                      EQU     00001H
ACS_TRANSPARENT                                 EQU     00002H
ACS_AUTOPLAY                                    EQU     00004H
ACS_TIMER                                       EQU     00008H

ACM_OPENA                                       EQU     (WM_USER + 100)
ACM_PLAY                                        EQU     (WM_USER + 101)
ACM_STOP                                        EQU     (WM_USER + 102)
ACM_OPENW                                       EQU     (WM_USER + 103)

ACN_START                                       EQU     1
ACN_STOP                                        EQU     2

;======================================== MonthCal ========================================;
MONTHCAL_CLASSA                                 EQU     <SysMonthCal32>
MONTHCAL_CLASSW                                 EQU     L("SysMonthCal32")

MCM_FIRST                                       EQU     01000H
MCM_GETCURSEL                                   EQU     (MCM_FIRST + 1)
MCM_SETCURSEL                                   EQU     (MCM_FIRST + 2)
MCM_GETMAXSELCOUNT                              EQU     (MCM_FIRST + 3)
MCM_SETMAXSELCOUNT                              EQU     (MCM_FIRST + 4)
MCM_GETSELRANGE                                 EQU     (MCM_FIRST + 5)
MCM_SETSELRANGE                                 EQU     (MCM_FIRST + 6)
MCM_GETMONTHRANGE                               EQU     (MCM_FIRST + 7)
MCM_SETDAYSTATE                                 EQU     (MCM_FIRST + 8)
MCM_GETMINREQRECT                               EQU     (MCM_FIRST + 9)
MCM_SETCOLOR                                    EQU     (MCM_FIRST + 10)
MCM_GETCOLOR                                    EQU     (MCM_FIRST + 11)
MCM_SETTODAY                                    EQU     (MCM_FIRST + 12)
MCM_GETTODAY                                    EQU     (MCM_FIRST + 13)
MCM_HITTEST                                     EQU     (MCM_FIRST + 14)
MCM_SETFIRSTDAYOFWEEK                           EQU     (MCM_FIRST + 15)
MCM_GETFIRSTDAYOFWEEK                           EQU     (MCM_FIRST + 16)
MCM_GETRANGE                                    EQU     (MCM_FIRST + 17)
MCM_SETRANGE                                    EQU     (MCM_FIRST + 18)
MCM_GETMONTHDELTA                               EQU     (MCM_FIRST + 19)
MCM_SETMONTHDELTA                               EQU     (MCM_FIRST + 20)
MCM_GETMAXTODAYWIDTH                            EQU     (MCM_FIRST + 21)
MCM_GETCURRENTVIEW                              EQU     (MCM_FIRST + 22)
MCM_GETCALENDARCOUNT                            EQU     (MCM_FIRST + 23)
MCM_GETCALENDARGRIDINFO                         EQU     (MCM_FIRST + 24)
MCM_GETCALID                                    EQU     (MCM_FIRST + 27)
MCM_SETCALID                                    EQU     (MCM_FIRST + 28)
MCM_SIZERECTTOMIN                               EQU     (MCM_FIRST + 29)
MCM_SETCALENDARBORDER                           EQU     (MCM_FIRST + 30)
MCM_GETCALENDARBORDER                           EQU     (MCM_FIRST + 31)
MCM_SETCURRENTVIEW                              EQU     (MCM_FIRST + 32)
MCM_SETUNICODEFORMAT                            EQU     CCM_SETUNICODEFORMAT
MCM_GETUNICODEFORMAT                            EQU     CCM_GETUNICODEFORMAT

MCSC_BACKGROUND                                 EQU     0
MCSC_TEXT                                       EQU     1
MCSC_TITLEBK                                    EQU     2
MCSC_TITLETEXT                                  EQU     3
MCSC_MONTHBK                                    EQU     4
MCSC_TRAILINGTEXT                               EQU     5

MCHT_TITLE                                      EQU     000010000H
MCHT_CALENDAR                                   EQU     000020000H
MCHT_TODAYLINK                                  EQU     000030000H
MCHT_NEXT                                       EQU     001000000H
MCHT_PREV                                       EQU     002000000H
MCHT_NOWHERE                                    EQU     000000000H
MCHT_TITLEBK                                    EQU     (MCHT_TITLE)
MCHT_TITLEMONTH                                 EQU     (MCHT_TITLE OR 00001H)
MCHT_TITLEYEAR                                  EQU     (MCHT_TITLE OR 00002H)
MCHT_TITLEBTNNEXT                               EQU     (MCHT_TITLE OR MCHT_NEXT OR 00003H)
MCHT_TITLEBTNPREV                               EQU     (MCHT_TITLE OR MCHT_PREV OR 00003H)

MCHT_CALENDARBK                                 EQU     MCHT_CALENDAR
MCHT_CALENDARDATE                               EQU     (MCHT_CALENDAR OR 00001H)
MCHT_CALENDARDATENEXT                           EQU     (MCHT_CALENDARDATE OR MCHT_NEXT)
MCHT_CALENDARDATEPREV                           EQU     (MCHT_CALENDARDATE OR MCHT_PREV)
MCHT_CALENDARDAY                                EQU     (MCHT_CALENDAR OR 00002H)
MCHT_CALENDARWEEKNUM                            EQU     (MCHT_CALENDAR OR 00003H)
MCHT_CALENDARDATEMIN                            EQU     (MCHT_CALENDAR OR 0004H)
MCHT_CALENDARDATEMAX                            EQU     (MCHT_CALENDAR OR 0005H)
MCHT_CALENDARCONTROL                            EQU     000100000H

MCN_VIEWCHANGE                                  EQU     (MCN_FIRST - 4)
MCN_SELCHANGE                                   EQU     (MCN_FIRST + 1)
MCN_GETDAYSTATE                                 EQU     (MCN_FIRST + 3)
MCN_SELECT                                      EQU     (MCN_FIRST + 4)

MCS_DAYSTATE                                    EQU     00001H
MCS_MULTISELECT                                 EQU     00002H
MCS_WEEKNUMBERS                                 EQU     00004H
MCS_NOTODAYCIRCLE                               EQU     00008H
MCS_NOTODAY                                     EQU     00010H
MCS_NOTRAILINGDATES                             EQU     00040H
MCS_SHORTDAYSOFWEEK                             EQU     00080H
MCS_NOSELCHANGEONNAV                            EQU     00100H

MCMV_MONTH                                      EQU     0
MCMV_YEAR                                       EQU     1
MCMV_DECADE                                     EQU     2
MCMV_CENTURY                                    EQU     3
MCMV_MAX                                        EQU     MCMV_CENTURY

MCGIP_CALENDARCONTROL                           EQU     0
MCGIP_NEXT                                      EQU     1
MCGIP_PREV                                      EQU     2
MCGIP_FOOTER                                    EQU     3
MCGIP_CALENDAR                                  EQU     4
MCGIP_CALENDARHEADER                            EQU     5
MCGIP_CALENDARBODY                              EQU     6
MCGIP_CALENDARROW                               EQU     7
MCGIP_CALENDARCELL                              EQU     8

MCGIF_DATE                                      EQU     000000001H
MCGIF_RECT                                      EQU     000000002H
MCGIF_NAME                                      EQU     000000004H

GMR_VISIBLE                                     EQU     0
GMR_DAYSTATE                                    EQU     1

;======================================== DateTime ========================================;
DATETIMEPICK_CLASSA                             EQU     <SysDateTimePick32>
DATETIMEPICK_CLASSW                             EQU     L("SysDateTimePick32")

DTM_FIRST                                       EQU     01000H
DTM_GETSYSTEMTIME                               EQU     (DTM_FIRST + 1)
DTM_SETSYSTEMTIME                               EQU     (DTM_FIRST + 2)
DTM_GETRANGE                                    EQU     (DTM_FIRST + 3)
DTM_SETRANGE                                    EQU     (DTM_FIRST + 4)
DTM_SETFORMATA                                  EQU     (DTM_FIRST + 5)
DTM_SETMCCOLOR                                  EQU     (DTM_FIRST + 6)
DTM_GETMCCOLOR                                  EQU     (DTM_FIRST + 7)
DTM_GETMONTHCAL                                 EQU     (DTM_FIRST + 8)
DTM_SETMCFONT                                   EQU     (DTM_FIRST + 9)
DTM_GETMCFONT                                   EQU     (DTM_FIRST + 10)
DTM_SETMCSTYLE                                  EQU     (DTM_FIRST + 11)
DTM_GETMCSTYLE                                  EQU     (DTM_FIRST + 12)
DTM_CLOSEMONTHCAL                               EQU     (DTM_FIRST + 13)
DTM_GETDATETIMEPICKERINFO                       EQU     (DTM_FIRST + 14)
DTM_GETIDEALSIZE                                EQU     (DTM_FIRST + 15)
DTM_SETFORMATW                                  EQU     (DTM_FIRST + 50)

DTS_UPDOWN                                      EQU     00001H
DTS_SHOWNONE                                    EQU     00002H
DTS_SHORTDATEFORMAT                             EQU     00000H
DTS_LONGDATEFORMAT                              EQU     00004H
DTS_TIMEFORMAT                                  EQU     00009H
DTS_APPCANPARSE                                 EQU     00010H
DTS_RIGHTALIGN                                  EQU     00020H

DTN_DATETIMECHANGE                              EQU     (DTN_FIRST + 1)
DTN_USERSTRINGA                                 EQU     (DTN_FIRST + 2)
DTN_WMKEYDOWNA                                  EQU     (DTN_FIRST + 3)
DTN_FORMATA                                     EQU     (DTN_FIRST + 4)
DTN_FORMATQUERYA                                EQU     (DTN_FIRST + 5)
DTN_DROPDOWN                                    EQU     (DTN_FIRST + 6)
DTN_CLOSEUP                                     EQU     (DTN_FIRST + 7)
DTN_USERSTRINGW                                 EQU     (DTN_FIRST + 15)
DTN_WMKEYDOWNW                                  EQU     (DTN_FIRST + 16)
DTN_FORMATW                                     EQU     (DTN_FIRST + 17)
DTN_FORMATQUERYW                                EQU     (DTN_FIRST + 18)

GDTR_MIN                                        EQU     00001H
GDTR_MAX                                        EQU     00002H

GDT_ERROR                                       EQU     (-1)
GDT_VALID                                       EQU     0
GDT_NONE                                        EQU     1

;======================================== IpAddress =======================================;
WC_IPADDRESSA                                   EQU     <SysIPAddress32>
WC_IPADDRESSW                                   EQU     L("SysIPAddress32")

IPM_CLEARADDRESS                                EQU     (WM_USER + 100)
IPM_SETADDRESS                                  EQU     (WM_USER + 101)
IPM_GETADDRESS                                  EQU     (WM_USER + 102)
IPM_SETRANGE                                    EQU     (WM_USER + 103)
IPM_SETFOCUS                                    EQU     (WM_USER + 104)
IPM_ISBLANK                                     EQU     (WM_USER + 105)

IPN_FIELDCHANGED                                EQU     (IPN_FIRST - 0)

;========================================== Pager =========================================;
WC_PAGESCROLLERA                                EQU     <SysPager>
WC_PAGESCROLLERW                                EQU     L("SysPager")

PGS_VERT                                        EQU     000000000H
PGS_HORZ                                        EQU     000000001H
PGS_AUTOSCROLL                                  EQU     000000002H
PGS_DRAGNDROP                                   EQU     000000004H

PGF_INVISIBLE                                   EQU     0
PGF_NORMAL                                      EQU     1
PGF_GRAYED                                      EQU     2
PGF_DEPRESSED                                   EQU     4
PGF_HOT                                         EQU     8

PGB_TOPORLEFT                                   EQU     0
PGB_BOTTOMORRIGHT                               EQU     1

PGM_SETCHILD                                    EQU     (PGM_FIRST + 1)
PGM_RECALCSIZE                                  EQU     (PGM_FIRST + 2)
PGM_FORWARDMOUSE                                EQU     (PGM_FIRST + 3)
PGM_SETBKCOLOR                                  EQU     (PGM_FIRST + 4)
PGM_GETBKCOLOR                                  EQU     (PGM_FIRST + 5)
PGM_SETBORDER                                   EQU     (PGM_FIRST + 6)
PGM_GETBORDER                                   EQU     (PGM_FIRST + 7)
PGM_SETPOS                                      EQU     (PGM_FIRST + 8)
PGM_GETPOS                                      EQU     (PGM_FIRST + 9)
PGM_SETBUTTONSIZE                               EQU     (PGM_FIRST + 10)
PGM_GETBUTTONSIZE                               EQU     (PGM_FIRST + 11)
PGM_GETBUTTONSTATE                              EQU     (PGM_FIRST + 12)
PGM_GETDROPTARGET                               EQU     CCM_GETDROPTARGET

PGN_SCROLL                                      EQU     (PGN_FIRST - 1)
PGN_CALCSIZE                                    EQU     (PGN_FIRST - 2)
PGN_HOTITEMCHANGE                               EQU     (PGN_FIRST - 3)

PGF_SCROLLUP                                    EQU     1
PGF_SCROLLDOWN                                  EQU     2
PGF_SCROLLLEFT                                  EQU     4
PGF_SCROLLRIGHT                                 EQU     8

PGK_SHIFT                                       EQU     1
PGK_CONTROL                                     EQU     2
PGK_MENU                                        EQU     4

PGF_CALCWIDTH                                   EQU     1
PGF_CALCHEIGHT                                  EQU     2

;======================================== NativeFont ======================================;
WC_NATIVEFONTCTLA                               EQU     <NativeFontCtl>
WC_NATIVEFONTCTLW                               EQU     L("NativeFontCtl")

NFS_EDIT                                        EQU     00001H
NFS_STATIC                                      EQU     00002H
NFS_LISTCOMBO                                   EQU     00004H
NFS_BUTTON                                      EQU     00008H
NFS_ALL                                         EQU     00010H
NFS_USEFONTASSOC                                EQU     00020H

WSB_PROP_CYVSCROLL                              EQU     000000001H
WSB_PROP_CXHSCROLL                              EQU     000000002H
WSB_PROP_CYHSCROLL                              EQU     000000004H
WSB_PROP_CXVSCROLL                              EQU     000000008H
WSB_PROP_CXHTHUMB                               EQU     000000010H
WSB_PROP_CYVTHUMB                               EQU     000000020H
WSB_PROP_VBKGCOLOR                              EQU     000000040H
WSB_PROP_HBKGCOLOR                              EQU     000000080H
WSB_PROP_VSTYLE                                 EQU     000000100H
WSB_PROP_HSTYLE                                 EQU     000000200H
WSB_PROP_WINSTYLE                               EQU     000000400H
WSB_PROP_PALETTE                                EQU     000000800H
WSB_PROP_MASK                                   EQU     000000FFFH

FSB_FLAT_MODE                                   EQU     2
FSB_ENCARTA_MODE                                EQU     1
FSB_REGULAR_MODE                                EQU     0

;========================================== SysLink =======================================;
WC_LINK                                         EQU     L("SysLink")

INVALID_LINK_INDEX                              EQU     (-1)
MAX_LINKID_TEXT                                 EQU     48
L_MAX_URL_LENGTH                                EQU     (2048 + 32 + 3)

LWS_TRANSPARENT                                 EQU     00001H
LWS_IGNORERETURN                                EQU     00002H
LWS_NOPREFIX                                    EQU     00004H
LWS_USEVISUALSTYLE                              EQU     00008H
LWS_USECUSTOMTEXT                               EQU     00010H
LWS_RIGHT                                       EQU     00020H

LIF_ITEMINDEX                                   EQU     000000001H
LIF_STATE                                       EQU     000000002H
LIF_ITEMID                                      EQU     000000004H
LIF_URL                                         EQU     000000008H

LIS_FOCUSED                                     EQU     000000001H
LIS_ENABLED                                     EQU     000000002H
LIS_VISITED                                     EQU     000000004H
LIS_HOTTRACK                                    EQU     000000008H
LIS_DEFAULTCOLORS                               EQU     000000010H

LM_HITTEST                                      EQU     (WM_USER + 0300H)
LM_GETIDEALHEIGHT                               EQU     (WM_USER + 0301H)
LM_SETITEM                                      EQU     (WM_USER + 0302H)
LM_GETITEM                                      EQU     (WM_USER + 0303H)
LM_GETIDEALSIZE                                 EQU     LM_GETIDEALHEIGHT

;======================================== Task dialog =====================================;
TDF_ENABLE_HYPERLINKS                           EQU     00001H
TDF_USE_HICON_MAIN                              EQU     00002H
TDF_USE_HICON_FOOTER                            EQU     00004H
TDF_ALLOW_DIALOG_CANCELLATION                   EQU     00008H
TDF_USE_COMMAND_LINKS                           EQU     00010H
TDF_USE_COMMAND_LINKS_NO_ICON                   EQU     00020H
TDF_EXPAND_FOOTER_AREA                          EQU     00040H
TDF_EXPANDED_BY_DEFAULT                         EQU     00080H
TDF_VERIFICATION_FLAG_CHECKED                   EQU     00100H
TDF_SHOW_PROGRESS_BAR                           EQU     00200H
TDF_SHOW_MARQUEE_PROGRESS_BAR                   EQU     00400H
TDF_CALLBACK_TIMER                              EQU     00800H
TDF_POSITION_RELATIVE_TO_WINDOW                 EQU     01000H
TDF_RTL_LAYOUT                                  EQU     02000H
TDF_NO_DEFAULT_RADIO_BUTTON                     EQU     04000H
TDF_CAN_BE_MINIMIZED                            EQU     08000H

TDM_NAVIGATE_PAGE                               EQU     (WM_USER + 101)
TDM_CLICK_BUTTON                                EQU     (WM_USER + 102)
TDM_SET_MARQUEE_PROGRESS_BAR                    EQU     (WM_USER + 103)
TDM_SET_PROGRESS_BAR_STATE                      EQU     (WM_USER + 104)
TDM_SET_PROGRESS_BAR_RANGE                      EQU     (WM_USER + 105)
TDM_SET_PROGRESS_BAR_POS                        EQU     (WM_USER + 106)
TDM_SET_PROGRESS_BAR_MARQUEE                    EQU     (WM_USER + 107)
TDM_SET_ELEMENT_TEXT                            EQU     (WM_USER + 108)
TDM_CLICK_RADIO_BUTTON                          EQU     (WM_USER + 110)
TDM_ENABLE_BUTTON                               EQU     (WM_USER + 111)
TDM_ENABLE_RADIO_BUTTON                         EQU     (WM_USER + 112)
TDM_CLICK_VERIFICATION                          EQU     (WM_USER + 113)
TDM_UPDATE_ELEMENT_TEXT                         EQU     (WM_USER + 114)
TDM_SET_BUTTON_ELEVATION_REQUIRED_STATE         EQU     (WM_USER + 115)
TDM_UPDATE_ICON                                 EQU     (WM_USER + 116)

TDN_CREATED                                     EQU     0
TDN_NAVIGATED                                   EQU     1
TDN_BUTTON_CLICKED                              EQU     2
TDN_HYPERLINK_CLICKED                           EQU     3
TDN_TIMER                                       EQU     4
TDN_DESTROYED                                   EQU     5
TDN_RADIO_BUTTON_CLICKED                        EQU     6
TDN_DIALOG_CONSTRUCTED                          EQU     7
TDN_VERIFICATION_CLICKED                        EQU     8
TDN_HELP                                        EQU     9
TDN_EXPANDO_BUTTON_CLICKED                      EQU     10

TDE_CONTENT                                     EQU     0
TDE_EXPANDED_INFORMATION                        EQU     1
TDE_FOOTER                                      EQU     2
TDE_MAIN_INSTRUCTION                            EQU     3

TD_WARNING_ICON                                 EQU     (-1)
TD_ERROR_ICON                                   EQU     (-2)
TD_INFORMATION_ICON                             EQU     (-3)
TD_SHIELD_ICON                                  EQU     (-4)

TDIE_ICON_MAIN                                  EQU     0
TDIE_ICON_FOOTER                                EQU     1

TDCBF_OK_BUTTON                                 EQU     00001H
TDCBF_YES_BUTTON                                EQU     00002H
TDCBF_NO_BUTTON                                 EQU     00004H
TDCBF_CANCEL_BUTTON                             EQU     00008H
TDCBF_RETRY_BUTTON                              EQU     00010H
TDCBF_CLOSE_BUTTON                              EQU     00020H

;====================================== TrackMouseEvent ===================================;
IFNDEF WM_MOUSEHOVER
    WM_MOUSEHOVER                               EQU     002A1H
    WM_MOUSELEAVE                               EQU     002A3H
ENDIF

IFNDEF TME_HOVER
    TME_HOVER                                   EQU     000000001H
    TME_LEAVE                                   EQU     000000002H
    TME_QUERY                                   EQU     040000000H
    TME_CANCEL                                  EQU     080000000H

    HOVER_DEFAULT                               EQU     0FFFFFFFFH
ENDIF

IFNDEF TRACKMOUSEEVENT
    TRACKMOUSEEVENT STRUCT ALIGNMODE
        cbSize      DD   ?
        dwFlags     DD   ?
        hwndTrack   HWND ?
        dwHoverTime DD   ?
    TRACKMOUSEEVENT ENDS
ENDIF

;======================================== Structures ======================================;
IFNDEF NMTVSTATEIMAGECHANGING
    NMTVSTATEIMAGECHANGING STRUCT ALIGNMODE
        hdr                 NMHDR     <> 
        hti                 HTREEITEM ?
        iOldStateImageIndex DWORD     ?
        iNewStateImageIndex DWORD     ?
    NMTVSTATEIMAGECHANGING ENDS
ENDIF

PSHNOTIFY STRUCT ALIGNMODE
    hdr    NMHDR  <>
    lParam LPARAM ?
PSHNOTIFY ENDS

IFNDEF SYSTEMTIME
    SYSTEMTIME STRUCT ALIGNMODE
        wYear         DW  ?
        wMonth        DW  ?
        wDayOfWeek    DW  ?
        wDay          DW  ?
        wHour         DW  ?
        wMinute       DW  ?
        wSecond       DW  ?
        wMilliseconds DW  ?
    SYSTEMTIME ENDS
ENDIF

INITCOMMONCONTROLSEX STRUCT ALIGNMODE
    dwSize DD  ?
    dwICC  DD  ?
INITCOMMONCONTROLSEX ENDS

COLORSCHEME STRUCT ALIGNMODE
    dwSize          DD       ?
    clrBtnHighlight COLORREF ?
    clrBtnShadow    COLORREF ?
COLORSCHEME ENDS

NMTOOLTIPSCREATED STRUCT ALIGNMODE
    hdr          NMHDR <>
    hwndToolTips HWND  ?
NMTOOLTIPSCREATED ENDS

NMMOUSE STRUCT ALIGNMODE
    hdr        NMHDR <>
    dwItemSpec DD    ?
    dwItemData DD    ?
    pt         POINT <>
    dwHitInfo  DD    ?
NMMOUSE ENDS

NMCLICK STRUCT ALIGNMODE
    hdr         NMHDR <>
    dwItemSpec  DD    ?
    dwItemData  DD    ?
    pt          POINT <>
    dwHitInfo   DD    ?
NMCLICK ENDS

NMOBJECTNOTIFY STRUCT ALIGNMODE
    hdr     NMHDR   <>
    iItem   DD      ?
    piid    XPTR    ?
    pObject XPTR    ?
    hResult HRESULT ?
    dwFlags DD      ?
NMOBJECTNOTIFY ENDS

NMKEY STRUCT ALIGNMODE
    hdr     NMHDR <>
    nVKey   UINT  ?
    uFlags  UINT  ?
NMKEY ENDS

NMCHAR STRUCT ALIGNMODE
    hdr        NMHDR <>
    chr        UINT  ?
    dwItemPrev DD    ?
    dwItemNext DD    ?
NMCHAR ENDS

NMCUSTOMTEXT STRUCT ALIGNMODE
    hdr      NMHDR   <>
    hDC      HDC     ?
    lpString LPCWSTR ?
    nCount   DD      ?
    lpRect   XPTR    ?
    uFormat  UINT    ?
    fLink    BOOL    ?
NMCUSTOMTEXT ENDS

NMCUSTOMDRAW STRUCT ALIGNMODE
    hdr         NMHDR     <>
    dwDrawStage DD        ?
    hdc         HDC       ?
    rc          RECT      <>
    dwItemSpec  DWORD_PTR ?
    uItemState  UINT      ?
    lItemlParam LPARAM    ?
NMCUSTOMDRAW ENDS

NMTTCUSTOMDRAW STRUCT ALIGNMODE
    nmcd       NMCUSTOMDRAW <>
    uDrawFlags UINT         ?
NMTTCUSTOMDRAW ENDS

IMAGELISTDRAWPARAMS STRUCT ALIGNMODE
    cbSize   DD       ?
    himl     HANDLE   ?
    i        DD       ?
    hdcDst   HDC      ?
    x        DD       ?
    y        DD       ?
    _cx      DD       ?
    cy       DD       ?
    xBitmap  DD       ?
    yBitmap  DD       ?
    rgbBk    COLORREF ?
    rgbFg    COLORREF ?
    fStyle   UINT     ?
    dwRop    DD       ?
    fState   DD       ?
    _Frame   DD       ?
    crEffect COLORREF ?
IMAGELISTDRAWPARAMS ENDS

IMAGEINFO STRUCT ALIGNMODE
    hbmImage HBITMAP ?
    hbmMask  HBITMAP ?
    Unused1  DD      ?
    Unused2  DD      ?
    rcImage  RECT    <>
IMAGEINFO ENDS

HDTEXTFILTERA STRUCT ALIGNMODE
    pszText     LPTSTR ?
    cchTextMax  DD     ?
HDTEXTFILTERA ENDS

HDTEXTFILTERW STRUCT ALIGNMODE
    pszText     LPWSTR ?
    cchTextMax  DD     ?
HDTEXTFILTERW ENDS

HDITEMA STRUCT ALIGNMODE
    _mask        UINT    ?
    cxy          DD      ?
    pszText      LPTSTR  ?
    hbm          HBITMAP ?
    cchTextMax   DD      ?
    fmt          DD      ?
    lParam       LPARAM  ?
    iImage       DD      ?
    iOrder       DD      ?
    IF (NTDDI_VERSION GE NTDDI_WIN2K)
        _type    UINT    ?
        pvFilter LPVOID  ?
    ENDIF
    IF (NTDDI_VERSION GE NTDDI_VISTA)
        state    UINT    ?
    ENDIF
HDITEMA ENDS

HDITEMW STRUCT ALIGNMODE
    _mask        UINT    ?
    cxy          DD      ?
    pszText      LPWSTR  ?
    hbm          HBITMAP ?
    cchTextMax   DD      ?
    fmt          DD      ?
    lParam       LPARAM  ?
    iImage       DD      ?
    iOrder       DD      ?
    IF (NTDDI_VERSION GE NTDDI_WIN2K)
        _type    UINT    ?
        pvFilter LPVOID  ?
    ENDIF
    IF (NTDDI_VERSION GE NTDDI_VISTA)
        state    UINT    ?
    ENDIF
HDITEMW ENDS

IFDEF APP_UNICODE
    HDITEMW_V1_SIZE EQU SIZEOF HDITEMW
ELSE
    HDITEMA_V1_SIZE EQU SIZEOF HDITEMA
ENDIF

HDLAYOUT STRUCT ALIGNMODE
    prc   XPTR ?
    pwpos XPTR ?
HDLAYOUT ENDS
HD_LAYOUT   EQU <HDLAYOUT>

HDHITTESTINFO STRUCT ALIGNMODE
    pt    POINT <>
    flags UINT  ?
    iItem DD    ?
HDHITTESTINFO ENDS
HD_HITTESTINFO  EQU <HDHITTESTINFO>

NMHEADERA STRUCT ALIGNMODE
    hdr     NMHDR <>
    iItem   DD    ?
    iButton DD    ?
    pitem   XPTR  ?
NMHEADERA ENDS

NMHEADERW STRUCT ALIGNMODE
    hdr     NMHDR <>
    iItem   DD    ?
    iButton DD    ?
    pitem   XPTR  ?
NMHEADERW ENDS

NMHDDISPINFOA STRUCT ALIGNMODE
    hdr        NMHDR  <>
    iItem      DD     ?
    _mask      UINT   ?
    pszText    LPTSTR ?
    cchTextMax DD     ?
    iImage     DD     ?
    lParam     LPARAM ?
NMHDDISPINFOA ENDS

NMHDDISPINFOW STRUCT ALIGNMODE
    hdr        NMHDR  <>
    iItem      DD     ?
    _mask      UINT   ?
    pszText    LPWSTR ?
    cchTextMax DD     ?
    iImage     DD     ?
    lParam     LPARAM ?
NMHDDISPINFOW ENDS

NMHDFILTERBTNCLICK STRUCT ALIGNMODE
    hdr     NMHDR <>
    iItem   DD    ?
    rc      RECT  <>
NMHDFILTERBTNCLICK ENDS

TBBUTTON STRUCT ALIGNMODE
    iBitmap       DD       ?
    idCommand     DD       ?
    fsState       DB       ?
    fsStyle       DB       ?
    IFDEF APP_WIN64
        bReserved DB 6 DUP(?)
    ELSE
        bReserved DB 2 DUP(?)
    ENDIF
    dwData        DWORD_PTR ?
    iString       INT_PTR  ?
TBBUTTON ENDS

COLORMAP STRUCT ALIGNMODE
    from COLORREF ?
    to   COLORREF ?
COLORMAP ENDS

NMTBCUSTOMDRAW STRUCT ALIGNMODE
    nmcd                 NMCUSTOMDRAW <>
    hbrMonoDither        HBRUSH       ?
    hbrLines             HBRUSH       ?
    hpenLines            HPEN         ?
    clrText              COLORREF     ?
    clrMark              COLORREF     ?
    clrTextHighlight     COLORREF     ?
    clrBtnFace           COLORREF     ?
    clrBtnHighlight      COLORREF     ?
    clrHighlightHotTrack COLORREF     ?
    rcText               RECT         <>
    nStringBkMode        DD           ?
    nHLStringBkMode      DD           ?
    iListGap             DD           ?
NMTBCUSTOMDRAW ENDS

TBADDBITMAP STRUCT ALIGNMODE
    hInst  HINSTANCE ?
    nID    UINT_PTR  ?
TBADDBITMAP ENDS

TBSAVEPARAMSA STRUCT ALIGNMODE
    hkr          HKEY   ?
    pszSubKey    LPCSTR ?
    pszValueName LPCSTR ?
TBSAVEPARAMSA ENDS

TBSAVEPARAMSW STRUCT ALIGNMODE
    hkr          HKEY   ?
    pszSubKey    LPWSTR ?
    pszValueName LPWSTR ?
TBSAVEPARAMSW ENDS

TBINSERTMARK STRUCT ALIGNMODE
    iButton DD  ?
    dwFlags DD  ?
TBINSERTMARK ENDS

TBREPLACEBITMAP STRUCT ALIGNMODE
    hInstOld HINSTANCE ?
    nIDOld   UINT_PTR  ?
    hInstNew HINSTANCE ?
    nIDNew   UINT_PTR  ?
    nButtons DD        ?
TBREPLACEBITMAP ENDS

TBBUTTONINFOA STRUCT ALIGNMODE
    cbSize     UINT      ?
    dwMask     DD        ?
    idCommand  DD        ?
    iImage     DD        ?
    fsState    DB        ?
    fsStyle    DB        ?
    lx         DW        ?
    lParam     DWORD_PTR ?
    pszText    LPTSTR    ?
    cchText    DD        ?
    IF (NTDDI_VERSION GE NTDDI_VISTA)
        iImageLabel DD   ?
    ENDIF
TBBUTTONINFOA ENDS

TBBUTTONINFOW STRUCT ALIGNMODE
    cbSize     UINT      ?
    dwMask     DD        ?
    idCommand  DD        ?
    iImage     DD        ?
    fsState    DB        ?
    fsStyle    DB        ?
    lx         DW        ?
    lParam     DWORD_PTR ?
    pszText    LPWSTR    ?
    cchText    DD        ?
    IF (NTDDI_VERSION GE NTDDI_VISTA)
        iImageLabel DD   ?
    ENDIF
TBBUTTONINFOW ENDS

NMTBSAVE STRUCT ALIGNMODE
    hdr      NMHDR    <>
    pData    LPDWORD  ?
    pCurrent LPDWORD  ?
    cbData   UINT     ?
    iItem    DD       ?
    cButtons DD       ?
    tbButton TBBUTTON <>
NMTBSAVE ENDS

NMTBRESTORE STRUCT
    hdr      NMHDR      <>
    pData    LPDWORD    ?
    pCurrent LPDWORD    ?
    cbData   UINT       ?
    iItem    DD         ?
    cButtons DD         ?
    cbBytesPerRecord DD ?
    tbButton TBBUTTON   <>
NMTBRESTORE ENDS

NMTBHOTITEM STRUCT ALIGNMODE
    hdr     NMHDR <>
    idOld   DD    ?
    idNew   DD    ?
    dwFlags DD    ?
NMTBHOTITEM ENDS

NMTBGETINFOTIPA STRUCT ALIGNMODE
    hdr        NMHDR  <>
    pszText    LPTSTR ?
    cchTextMax DD     ?
    iItem      DD     ?
    lParam     LPARAM ?
NMTBGETINFOTIPA ENDS

NMTBGETINFOTIPW STRUCT ALIGNMODE
    hdr        NMHDR  <>
    pszText    LPWSTR ?
    cchTextMax DD     ?
    iItem      DD     ?
    lParam     LPARAM ?
NMTBGETINFOTIPW ENDS

NMTBDISPINFOA STRUCT ALIGNMODE
    hdr       NMHDR     <>
    dwMask    DD        ?
    idCommand DD        ?
    lParam    DWORD_PTR ?
    iImage    DD        ?
    pszText   LPTSTR    ?
    cchText   DD        ?
NMTBDISPINFOA ENDS

NMTBDISPINFOW STRUCT ALIGNMODE
    hdr       NMHDR     <>
    dwMask    DD        ?
    idCommand DD        ?
    lParam    DWORD_PTR ?
    iImage    DD        ?
    pszText   LPWSTR    ?
    cchText   DD        ?
NMTBDISPINFOW ENDS

NMTOOLBARA STRUCT ALIGNMODE
    hdr      NMHDR    <>
    iItem    DD       ?
    tbButton TBBUTTON <>
    cchText  DD       ?
    pszText  LPTSTR   ?
    rcButton RECT     <>
NMTOOLBARA ENDS

NMTOOLBARW STRUCT ALIGNMODE
    hdr      NMHDR    <>
    iItem    DD       ?
    tbButton TBBUTTON <>
    cchText  DD       ?
    pszText  LPWSTR   ?
    rcButton RECT     <>
NMTOOLBARW ENDS

TBMETRICS STRUCT ALIGNMODE
    cbSize          UINT ?
    dwMask          DD   ?
    cxPad           DD   ?
    cyPad           DD   ?
    cxBarPad        DD   ?
    cyBarPad        DD   ?
    cxButtonSpacing DD   ?
    cyButtonSpacing DD   ?
TBMETRICS ENDS

REBARINFO STRUCT ALIGNMODE
    cbSize UINT   ?
    fMask  UINT   ?
    himl   HANDLE ?
REBARINFO ENDS

REBARBANDINFOA STRUCT ALIGNMODE
    cbSize      UINT     ?
    fMask       UINT     ?
    fStyle      UINT     ?
    clrFore     COLORREF ?
    clrBack     COLORREF ?
    lpText      LPTSTR   ?
    cch         UINT     ?
    iImage      DD       ?
    hwndChild   HWND     ?
    cxMinChild  UINT     ?
    cyMinChild  UINT     ?
    _cx         UINT     ?
    hbmBack     HBITMAP  ?
    wID         UINT     ?
    cyChild     UINT   ?
    cyMaxChild  UINT   ?
    cyIntegral  UINT   ?
    cxIdeal     UINT   ?
    lParam      LPARAM ?
    cxHeader    UINT   ?
    rcChevronLocation RECT <>
    uChevronState     UINT ?
REBARBANDINFOA ENDS
REBARBANDINFOA_V3_SIZE  EQU SIZEOF REBARBANDINFOA

REBARBANDINFOW STRUCT ALIGNMODE
    cbSize      UINT     ?
    fMask       UINT     ?
    fStyle      UINT     ?
    clrFore     COLORREF ?
    clrBack     COLORREF ?
    lpText      LPWSTR   ?
    cch         UINT     ?
    iImage      DD       ?
    hwndChild   HWND     ?
    cxMinChild  UINT     ?
    cyMinChild  UINT     ?
    _cx         UINT     ?
    hbmBack     HBITMAP  ?
    wID         UINT     ?
    cyChild     UINT   ?
    cyMaxChild  UINT   ?
    cyIntegral  UINT   ?
    cxIdeal     UINT   ?
    lParam      LPARAM ?
    cxHeader    UINT   ?
    rcChevronLocation RECT <>
    uChevronState     UINT ?
REBARBANDINFOW ENDS
REBARBANDINFOW_V3_SIZE  EQU SIZEOF REBARBANDINFOW

NMREBARCHILDSIZE STRUCT ALIGNMODE
    hdr     NMHDR <>
    uBand   UINT  ?
    wID     UINT  ?
    rcChild RECT  <>
    rcBand  RECT  <>
NMREBARCHILDSIZE ENDS

NMREBAR STRUCT ALIGNMODE
    hdr    NMHDR  <>
    dwMask DD     ?
    uBand  UINT   ?
    fStyle UINT   ?
    wID    UINT   ?
    lParam LPARAM ?
NMREBAR ENDS

NMRBAUTOSIZE STRUCT ALIGNMODE
    hdr      NMHDR <>
    fChanged BOOL  ?
    rcTarget RECT  <>
    rcActual RECT  <>
NMRBAUTOSIZE ENDS

RBHITTESTINFO STRUCT ALIGNMODE
    pt    POINT <>
    flags UINT  ?
    iBand DD    ?
RBHITTESTINFO ENDS
RB_HITTESTINFO  EQU <RBHITTESTINFO>

NMREBARAUTOBREAK STRUCT ALIGNMODE
    hdr           NMHDR  <>
    uBand         UINT   ?
    wID           UINT   ?
    lParam        LPARAM ?
    uMsg          UINT   ?
    fStyleCurrent UINT   ?
    fAutoBreak    BOOL   ?
NMREBARAUTOBREAK ENDS

NMREBARSPLITTER STRUCT ALIGNMODE
    hdr      NMHDR <>
    rcSizing RECT  <>
NMREBARSPLITTER ENDS

TTTOOLINFOA STRUCT ALIGNMODE
    cbSize     UINT      ?
    uFlags     UINT      ?
    hwnd       HWND      ?
    uId        UINT_PTR  ?
    rect       RECT      <>
    hInst      HINSTANCE ?
    lpszText   LPTSTR    ?
    lParam     LPARAM    ?
    lpReserved LPVOID    ?
TTTOOLINFOA EndS
IFNDEF TOOLINFOA
    TOOLINFOA Equ <TTTOOLINFOA>
ENDIF
TOOLINFOA_V1_SIZE   EQU SIZEOF TTTOOLINFOA

TTTOOLINFOW STRUCT ALIGNMODE
    cbSize     UINT      ?
    uFlags     UINT      ?
    hwnd       HWND      ?
    uId        UINT_PTR  ?
    rect       RECT      <>
    hInst      HINSTANCE ?
    lpszText   LPWSTR    ?
    lParam     LPARAM    ?
    lpReserved LPVOID    ?
TTTOOLINFOW ENDS
IFNDEF TOOLINFOW
    TOOLINFOW Equ <TTTOOLINFOW>
ENDIF
TOOLINFOW_V1_SIZE   EQU SIZEOF TTTOOLINFOW

TTHITTESTINFOA STRUCT ALIGNMODE
    hwnd HWND        ?
    pt   POINT       <>
    ti   TTTOOLINFOA <>
TTHITTESTINFOA ENDS

TTHITTESTINFOW STRUCT ALIGNMODE
    hwnd HWND        ?
    pt   POINT       <>
    ti   TTTOOLINFOW <>
TTHITTESTINFOW ENDS

NMTTDISPINFOA STRUCT ALIGNMODE
    hdr      NMHDR     <>
    lpszText LPTSTR    ?
    _szText  CHAR      80 DUP(?)
    hInst    HINSTANCE ?
    uFlags   UINT      ?
    lParam   LPARAM    ?
NMTTDISPINFOA ENDS
TOOLTIPTEXTA EQU <NMTTDISPINFOA>
NMTTDISPINFOA_V1_SIZE   EQU SIZEOF NMTTDISPINFOA

NMTTDISPINFOW STRUCT ALIGNMODE
    hdr      NMHDR     <>
    lpszText LPWSTR    ?
    _szText  WCHAR     80 DUP(?)
    hInst    HINSTANCE ?
    uFlags   UINT      ?
    lParam   LPARAM    ?
NMTTDISPINFOW ENDS
TOOLTIPTEXTW EQU <NMTTDISPINFOW>
NMTTDISPINFOW_V1_SIZE   EQU SIZEOF NMTTDISPINFOW

TTGETTITLE STRUCT ALIGNMODE
    dwSize       DD   ?
    uTitleBitmap UINT ?
    cch          UINT ?
    pszTitle     XPTR ?
TTGETTITLE ENDS

NMTRBTHUMBPOSCHANGING STRUCT ALIGNMODE
    hdr     NMHDR <>
    dwPos   DD    ?
    nReason DD    ?
NMTRBTHUMBPOSCHANGING ENDS

DRAGLISTINFO STRUCT ALIGNMODE
    uNotification UINT  ?
    hWnd          HWND  ?
    ptCursor      POINT <>
DRAGLISTINFO ENDS

UDACCEL STRUCT ALIGNMODE
    nSec UINT ?
    nInc UINT ?
UDACCEL ENDS

NMUPDOWN STRUCT ALIGNMODE
    hdr     NMHDR <>
    iPos    DD    ?
    iDelta  DD    ?
NMUPDOWN ENDS
NM_UPDOWN   EQU <NMUPDOWN>

PBRANGE STRUCT ALIGNMODE
    iLow  DD  ?
    iHigh DD  ?
PBRANGE ENDS

NMLVEMPTYMARKUP STRUCT ALIGNMODE
    hdr      NMHDR <>
    dwFlags  DD    ?
    szMarkup WCHAR L_MAX_URL_LENGTH DUP(?)
NMLVEMPTYMARKUP ENDS

LVFOOTERITEM STRUCT ALIGNMODE
    _mask       UINT   ?
    iItem       DD     ?
    pszText     LPWSTR ?
    cchTextMax  UINT   ?
    state       UINT   ?
    stateMask   UINT   ?
LVFOOTERITEM ENDS

LVFOOTERINFO STRUCT ALIGNMODE
    _mask       UINT   ?
    pszText     LPWSTR ?
    cchTextMax  DD     ?
    cItems      UINT   ?
LVFOOTERINFO ENDS

LVITEMA STRUCT ALIGNMODE
    _mask       UINT   ?
    iItem       DD     ?
    iSubItem    DD     ?
    state       UINT   ?
    stateMask   UINT   ?
    pszText     LPTSTR ?
    cchTextMax  DD     ?
    iImage      DD     ?
    lParam      LPARAM ?
    iIndent     DD     ?
    IF (NTDDI_VERSION GE NTDDI_WINXP)
        iGroupId  DD   ?
        cColumns  UINT ?
        puColumns UINT ?
    ENDIF
    IF (NTDDI_VERSION GE NTDDI_VISTA)
        piColFmt  DD   ?
        iGroup    DD   ?
    ENDIF
LVITEMA ENDS

LVITEMW STRUCT ALIGNMODE
    _mask       UINT   ?
    iItem       DD     ?
    iSubItem    DD     ?
    state       UINT   ?
    stateMask   UINT   ?
    pszText     LPWSTR ?
    cchTextMax  DD     ?
    iImage      DD     ?
    lParam      LPARAM ?
    iIndent     DD     ?
    IF (NTDDI_VERSION GE NTDDI_WINXP)
        iGroupId  DD   ?
        cColumns  UINT ?
        puColumns UINT ?
    ENDIF
    IF (NTDDI_VERSION GE NTDDI_VISTA)
        piColFmt  DD   ?
        iGroup    DD   ?
    ENDIF
LVITEMW ENDS

LVFINDINFOA STRUCT ALIGNMODE
    flags       UINT    ?
    psz         LPCTSTR ?
    lParam      LPARAM  ?
    pt          POINT   <>
    vkDirection DD      ?
LVFINDINFOA ENDS

LVFINDINFOW STRUCT ALIGNMODE
    flags       UINT    ?
    psz         LPCWSTR ?
    lParam      LPARAM  ?
    pt          POINT   <>
    vkDirection DD      ?
LVFINDINFOW ENDS

LVHITTESTINFO STRUCT ALIGNMODE
    pt       POINT <>
    flags    UINT  ?
    iItem    DD    ?
    iSubItem DD    ?
    iGroup   DD    ?
LVHITTESTINFO ENDS
LV_HITTESTINFO  EQU <LVHITTESTINFO>

LVCOLUMNA STRUCT ALIGNMODE
    _mask       UINT   ?
    fmt         DD     ?
    _cx         DD     ?
    pszText     LPTSTR ?
    cchTextMax  DD     ?
    iSubItem    DD     ?
    iImage      DD     ?
    iOrder      DD     ?
    IF (NTDDI_VERSION GE NTDDI_VISTA)
        cxMin     DD  ?
        cxDefault DD  ?
        cxIdeal   DD  ?
    ENDIF
LVCOLUMNA ENDS

LVCOLUMNW STRUCT ALIGNMODE
    _mask       UINT   ?
    fmt         DD     ?
    _cx         DD     ?
    pszText     LPTSTR ?
    cchTextMax  DD     ?
    iSubItem    DD     ?
    iImage      DD     ?
    iOrder      DD     ?
    IF (NTDDI_VERSION GE NTDDI_VISTA)
        cxMin     DD  ?
        cxDefault DD  ?
        cxIdeal   DD  ?
    ENDIF
LVCOLUMNW ENDS

LVBKIMAGEA STRUCT ALIGNMODE
    ulFlags         ULONG   ?
    hbm             HBITMAP ?
    pszImage        LPTSTR  ?
    cchImageMax     UINT    ?
    xOffsetPercent  DD      ?
    yOffsetPercent  DD      ?
LVBKIMAGEA ENDS

LVBKIMAGEW STRUCT ALIGNMODE
    ulFlags         ULONG   ?
    hbm             HBITMAP ?
    pszImage        LPWSTR  ?
    cchImageMax     UINT    ?
    xOffsetPercent  DD      ?
    yOffsetPercent  DD      ?
LVBKIMAGEW ENDS

NMLISTVIEW STRUCT ALIGNMODE
    hdr       NMHDR  <>
    iItem     DD     ?
    iSubItem  DD     ?
    uNewState UINT   ?
    uOldState UINT   ?
    uChanged  UINT   ?
    ptAction  POINT  <>
    lParam    LPARAM ?
NMLISTVIEW ENDS
NM_LISTVIEW EQU <NMLISTVIEW>

NMITEMACTIVATE STRUCT ALIGNMODE
    hdr       NMHDR <>
    iItem     DD     ?
    iSubItem  DD     ?
    uNewState UINT   ?
    uOldState UINT   ?
    uChanged  UINT   ?
    ptAction  POINT  <>
    lParam    LPARAM ?
    uKeyFlags UINT   ?
NMITEMACTIVATE ENDS

NMLVCUSTOMDRAW STRUCT ALIGNMODE
    nmcd      NMCUSTOMDRAW <>
    clrText   COLORREF ?
    clrTextBk COLORREF ?
    iSubItem  DD       ?
NMLVCUSTOMDRAW ENDS

NMLVCACHEHINT STRUCT ALIGNMODE
    hdr   NMHDR <>
    iFrom DD    ?
    iTo   DD    ?
NMLVCACHEHINT ENDS
NM_CACHEHINT    EQU <NMLVCACHEHINT>

NMLVFINDITEMA STRUCT ALIGNMODE
    hdr     NMHDR <>
    iStart  DD    ?
    lvfi    LVFINDINFOA <>
NMLVFINDITEMA ENDS

NMLVFINDITEMW STRUCT ALIGNMODE
    hdr     NMHDR <>
    iStart  DD    ?
    lvfi    LVFINDINFOW <>
NMLVFINDITEMW ENDS

NMLVODSTATECHANGE STRUCT ALIGNMODE
    hdr       NMHDR <>
    iFrom     DD    ?
    iTo       DD    ?
    uNewState UINT  ?
    uOldState UINT  ?
NMLVODSTATECHANGE ENDS
NM_ODSTATECHANGE    EQU <NMLVODSTATECHANGE>

NMLVDISPINFOA STRUCT ALIGNMODE
    hdr  NMHDR   <>
    item LVITEMA <>
NMLVDISPINFOA ENDS

NMLVDISPINFOW STRUCT ALIGNMODE
    hdr  NMHDR   <>
    item LVITEMW <>
NMLVDISPINFOW ENDS

NMLVKEYDOWN STRUCT ALIGNMODE
    hdr   NMHDR <>
    wVKey DW    ?
    flags UINT  ?
NMLVKEYDOWN ENDS
LV_KEYDOWN  EQU <NMLVKEYDOWN>

NMLVGETINFOTIPA STRUCT ALIGNMODE
    hdr        NMHDR  <>
    dwFlags    DD     ?
    pszText    LPTSTR ?
    cchTextMax DD     ?
    iItem      DD     ?
    iSubItem   DD     ?
    lParam     LPARAM ?
NMLVGETINFOTIPA ENDS

NMLVGETINFOTIPW STRUCT ALIGNMODE
    hdr        NMHDR  <>
    dwFlags    DD     ?
    pszText    LPWSTR ?
    cchTextMax DD     ?
    iItem      DD     ?
    iSubItem   DD     ?
    lParam     LPARAM ?
NMLVGETINFOTIPW ENDS

TVITEMA STRUCT ALIGNMODE
    _mask           UINT      ?
    hItem           HTREEITEM ?
    state           UINT      ?
    stateMask       UINT      ?
    pszText         LPTSTR    ?
    cchTextMax      DD        ? 
    iImage          DD        ?
    iSelectedImage  DD        ?
    cChildren       DD        ?
    lParam          LPARAM    ?
TVITEMA ENDS
TV_ITEMA            EQU <TVITEMA>

TVITEMW STRUCT ALIGNMODE
    _mask           UINT      ?
    hItem           HTREEITEM ?
    state           UINT      ?
    stateMask       UINT      ?
    pszText         LPWSTR    ?
    cchTextMax      DD        ? 
    iImage          DD        ?
    iSelectedImage  DD        ?
    cChildren       DD        ?
    lParam          LPARAM    ?
TVITEMW ENDS
TV_ITEMW            EQU <TVITEMW>

TVITEMEXA STRUCT ALIGNMODE
    _mask           UINT      ?
    hItem           HTREEITEM ?
    state           UINT      ?
    stateMask       UINT      ?
    pszText         LPTSTR    ?
    cchTextMax      DD        ? 
    iImage          DD        ?
    iSelectedImage  DD        ?
    cChildren       DD        ?
    lParam          LPARAM    ?
    iIntegral       DD        ?
    IF (NTDDI_VERSION GE NTDDI_VISTA)
        uStateEx    UINT      ?
        hwnd        HWND      ?
        iExpandedImage DD     ?
    ENDIF
    IF (NTDDI_VERSION GE NTDDI_WIN7)
        iReserved   DD        ?
    ENDIF
TVITEMEXA ENDS
TV_ITEMEXA          EQU <TVITEMEXA>

TVITEMEXW STRUCT ALIGNMODE
    _mask           UINT      ?
    hItem           HTREEITEM ?
    state           UINT      ?
    stateMask       UINT      ?
    pszText         LPWSTR    ?
    cchTextMax      DD        ? 
    iImage          DD        ?
    iSelectedImage  DD        ?
    cChildren       DD        ?
    lParam          LPARAM    ?
    iIntegral       DD        ?
    IF (NTDDI_VERSION GE NTDDI_VISTA)
        uStateEx    UINT      ?
        hwnd        HWND      ?
        iExpandedImage DD     ?
    ENDIF
    IF (NTDDI_VERSION GE NTDDI_WIN7)
        iReserved   DD        ?
    ENDIF
TVITEMEXW ENDS
TV_ITEMEXW          EQU <TVITEMEXW>

TVGETITEMPARTRECTINFO STRUCT ALIGNMODE
    hti     HANDLE ?
    prc     XPTR   ?
    partID  DD     ?
TVGETITEMPARTRECTINFO ENDS

TVINSERTSTRUCTA STRUCT ALIGNMODE
    hParent      HTREEITEM ?
    hInsertAfter HTREEITEM ?
    UNION
        itemex  TVITEMEXA <>
        item    TVITEMA   <>
    ENDS
TVINSERTSTRUCTA ENDS
TV_INSERTSTRUCTA    EQU <TVINSERTSTRUCTA>

TVINSERTSTRUCTW STRUCT ALIGNMODE
    hParent      HTREEITEM ?
    hInsertAfter HTREEITEM ?
    UNION
        itemex  TVITEMEXW <>
        item    TVITEMW   <>
    ENDS
TVINSERTSTRUCTW ENDS
TV_INSERTSTRUCTW    EQU <TVINSERTSTRUCTW>

TVHITTESTINFO STRUCT ALIGNMODE
    pt    POINT  <>
    flags UINT   ?
    hItem HANDLE ?
TVHITTESTINFO ENDS

TVSORTCB STRUCT ALIGNMODE
    hParent     HANDLE ?
    lpfnCompare XPTR   ?
    lParam      LPARAM ?
TVSORTCB ENDS
TV_SORTCB   EQU <TVSORTCB>

NMTREEVIEWA STRUCT ALIGNMODE
    hdr     NMHDR   <>
    action  UINT    ?
    itemOld TVITEMA <>
    itemNew TVITEMA <>
    ptDrag  POINT   <>
NMTREEVIEWA ENDS

NMTREEVIEWW STRUCT ALIGNMODE
    hdr     NMHDR   <>
    action  UINT    ?
    itemOld TVITEMW <>
    itemNew TVITEMW <>
    ptDrag  POINT   <>
NMTREEVIEWW ENDS

NMTVDISPINFOA STRUCT ALIGNMODE
    hdr  NMHDR   <>
    item TVITEMA <>
NMTVDISPINFOA ENDS

NMTVDISPINFOW STRUCT ALIGNMODE
    hdr  NMHDR   <>
    item TVITEMW <>
NMTVDISPINFOW ENDS

NMTVDISPINFOEXA STRUCT ALIGNMODE
    hdr  NMHDR     <>
    item TVITEMEXA <>
NMTVDISPINFOEXA ENDS

NMTVDISPINFOEXW STRUCT ALIGNMODE
    hdr  NMHDR     <>
    item TVITEMEXW <>
NMTVDISPINFOEXW ENDS

NMTVKEYDOWN STRUCT ALIGNMODE
    hdr   NMHDR <>
    wVKey DW    ?
    flags UINT  ?
NMTVKEYDOWN ENDS
TV_KEYDOWN  EQU <NMTVKEYDOWN>

NMTVCUSTOMDRAW STRUCT ALIGNMODE
    nmcd      NMCUSTOMDRAW <>
    clrText   COLORREF     ?
    clrTextBk COLORREF     ?
    iLevel    DD           ?
NMTVCUSTOMDRAW ENDS

NMTVGETINFOTIPA STRUCT ALIGNMODE
    hdr         NMHDR  <>
    pszText     LPTSTR ?
    cchTextMax  DD     ?
    hItem       HANDLE ?
    lParam      LPARAM ?
NMTVGETINFOTIPA ENDS

NMTVGETINFOTIPW STRUCT ALIGNMODE
    hdr         NMHDR  <>
    pszText     LPWSTR ?
    cchTextMax  DD     ?
    hItem       HANDLE ?
    lParam      LPARAM ?
NMTVGETINFOTIPW ENDS

NMTVITEMCHANGE STRUCT ALIGNMODE
    hdr        NMHDR  <>
    uChanged   UINT   ?
    hItem      HANDLE ?
    uStateNew  UINT   ?
    uStateOld  UINT   ?
    lParam     LPARAM ?
NMTVITEMCHANGE ENDS

NMTVASYNCDRAW STRUCT ALIGNMODE
    hdr            NMHDR   <>
    pimldp         XPTR    ?
    hr             HRESULT ?
    hItem          HANDLE  ?
    lParam         LPARAM  ?
    dwRetFlags     DD      ?
    iRetImageIndex DD      ?
NMTVASYNCDRAW ENDS

COMBOBOXEXITEMA STRUCT ALIGNMODE
    _mask           DD      ?
    iItem           INT_PTR ?
    pszText         LPTSTR  ?
    cchTextMax      DD      ?
    iImage          DD      ?
    iSelectedImage  DD      ?
    iOverlay        DD      ?
    iIndent         DD      ?
    lParam          LPARAM  ?
COMBOBOXEXITEMA ENDS

COMBOBOXEXITEMW STRUCT ALIGNMODE
    _mask           DD      ?
    iItem           INT_PTR ?
    pszText         LPWSTR  ?
    cchTextMax      DD      ?
    iImage          DD      ?
    iSelectedImage  DD      ?
    iOverlay        DD      ?
    iIndent         DD      ?
    lParam          LPARAM  ?
COMBOBOXEXITEMW ENDS

NMCOMBOBOXEXA STRUCT ALIGNMODE
    hdr     NMHDR <>
    ceItem  COMBOBOXEXITEMA <>
NMCOMBOBOXEXA ENDS

NMCOMBOBOXEXW STRUCT ALIGNMODE
    hdr     NMHDR <>
    ceItem  COMBOBOXEXITEMW <>
NMCOMBOBOXEXW ENDS

NMCBEDRAGBEGINA STRUCT ALIGNMODE
    hdr     NMHDR <>
    iItemid DD    ?
    _szText DB    CBEMAXSTRLEN DUP(?)
NMCBEDRAGBEGINA ENDS

NMCBEDRAGBEGINW STRUCT ALIGNMODE
    hdr     NMHDR <>
    iItemid DD    ?
    _szText DW    CBEMAXSTRLEN DUP(?)
NMCBEDRAGBEGINW ENDS

NMCBEENDEDITA STRUCT ALIGNMODE
    hdr           NMHDR <>
    fChanged      BOOL  ?
    iNewSelection DD    ?
    _szText       CHAR  CBEMAXSTRLEN DUP(?)
    iWhy          DD    ?
NMCBEENDEDITA ENDS

NMCBEENDEDITW STRUCT ALIGNMODE
    hdr           NMHDR <>
    fChanged      BOOL  ?
    iNewSelection DD    ?
    _szText       WCHAR CBEMAXSTRLEN DUP(?)
    iWhy          DD    ?
NMCBEENDEDITW ENDS

TCITEMHEADERA STRUCT ALIGNMODE
    _mask       UINT   ?
    lpReserved1 UINT   ?
    lpReserved2 UINT   ?
    pszText     LPTSTR ?
    cchTextMax  DD     ?
    iImage      DD     ?
TCITEMHEADERA ENDS

TCITEMHEADERW STRUCT ALIGNMODE
    _mask       UINT   ?
    lpReserved1 UINT   ?
    lpReserved2 UINT   ?
    pszText     LPWSTR ?
    cchTextMax  DD     ?
    iImage      DD     ?
TCITEMHEADERW ENDS

TCITEMA STRUCT ALIGNMODE
    _mask       UINT   ?
    dwState     DD     ?
    dwStateMask DD     ?
    pszText     LPTSTR ?
    cchTextMax  DD     ?
    iImage      DD     ?
    lParam      LPARAM ?
TCITEMA ENDS

TCITEMW STRUCT ALIGNMODE
    _mask       UINT   ?
    dwState     DD     ?
    dwStateMask DD     ?
    pszText     LPWSTR ?
    cchTextMax  DD     ?
    iImage      DD     ?
    lParam      LPARAM ?
TCITEMW ENDS

TCHITTESTINFO STRUCT ALIGNMODE
    pt    POINT <>
    flags UINT  ?
TCHITTESTINFO ENDS
TC_HITTESTINFO  EQU <TCHITTESTINFO>

NMTCKEYDOWN STRUCT ALIGNMODE
    hdr   NMHDR <>
    wVKey DW    ?
    flags UINT  ?
NMTCKEYDOWN ENDS
TC_KEYDOWN  EQU <NMTCKEYDOWN>

MCGRIDINFO STRUCT ALIGNMODE
    cbSize     UINT   ?
    dwPart     DD     ?
    dwFlags    DD     ?
    iCalendar  DD     ?
    iRow       DD     ?
    iCol       DD     ?
    bSelected  BOOL   ?
    stStart    SYSTEMTIME <>
    stEnd      SYSTEMTIME <>
    rc         RECT   <>
    pszName    LPWSTR ?
    cchName    size_t ?
MCGRIDINFO ENDS

MCHITTESTINFO STRUCT ALIGNMODE
    cbSize  UINT  ?
    pt      POINT <>
    uHit    DD    ?
    _st     SYSTEMTIME <>
    IF (NTDDI_VERSION GE NTDDI_VISTA)
        rc      RECT <>
        iOffset DD   ?
        iRow    DD   ?
        iCol    DD   ?
    ENDIF
MCHITTESTINFO ENDS

NMSELCHANGE STRUCT ALIGNMODE
    nmhdr       NMHDR <>
    stSelStart  SYSTEMTIME <>
    stSelEnd    SYSTEMTIME <>
NMSELCHANGE ENDS

NMDAYSTATE STRUCT ALIGNMODE
    nmhdr       NMHDR <>
    stStart     SYSTEMTIME <>
    cDayState   DD    ?
    prgDayState XPTR  ?
NMDAYSTATE ENDS

IF (NTDDI_VERSION GE NTDDI_VISTA)
    DATETIMEPICKERINFO STRUCT ALIGNMODE
        cbSize       DD   ?
        rcCheck      RECT <>
        stateCheck   DD   ?
        rcButton     RECT <>
        stateButton  DD   ?
        hwndEdit     HWND ?
        hwndUD       HWND ?
        hwndDropDown HWND ?
    DATETIMEPICKERINFO ENDS
ENDIF

NMDATETIMECHANGE STRUCT ALIGNMODE
    nmhdr   NMHDR <>
    dwFlags DD    ?
    _st     SYSTEMTIME <>
NMDATETIMECHANGE ENDS

NMDATETIMESTRINGA STRUCT ALIGNMODE
    nmhdr         NMHDR   <>
    pszUserString LPCTSTR ?
    _st           SYSTEMTIME <>
    dwFlags       DD      ?
NMDATETIMESTRINGA ENDS

NMDATETIMESTRINGW STRUCT ALIGNMODE
    nmhdr         NMHDR   <>
    pszUserString LPCWSTR ?
    _st           SYSTEMTIME <>
    dwFlags       DD      ?
NMDATETIMESTRINGW ENDS

NMDATETIMEWMKEYDOWNA STRUCT ALIGNMODE
    nmhdr     NMHDR   <>
    nVirtKey  DD      ?
    pszFormat LPCTSTR ?
    _st       SYSTEMTIME <>
NMDATETIMEWMKEYDOWNA ENDS

NMDATETIMEWMKEYDOWNW STRUCT ALIGNMODE
    nmhdr     NMHDR   <>
    nVirtKey  DD      ?
    pszFormat LPCWSTR ?
    _st       SYSTEMTIME <>
NMDATETIMEWMKEYDOWNW ENDS

NMDATETIMEFORMATA STRUCT ALIGNMODE
    nmhdr         NMHDR   <>
    pszFormat     LPCTSTR ?
    _st           SYSTEMTIME <>
    pszDisplay    LPCTSTR ?
    szDisplay     CHAR    64 DUP(?)
NMDATETIMEFORMATA ENDS

NMDATETIMEFORMATW STRUCT ALIGNMODE
    nmhdr         NMHDR   <>
    pszFormat     LPCWSTR ?
    _st           SYSTEMTIME <>
    pszDisplay    LPCWSTR ?
    szDisplay     WCHAR   64 DUP(?)
NMDATETIMEFORMATW ENDS

NMDATETIMEFORMATQUERYA STRUCT ALIGNMODE
    nmhdr     NMHDR   <>
    pszFormat LPCTSTR ?
    szMax     SIZEL   <>
NMDATETIMEFORMATQUERYA ENDS

NMDATETIMEFORMATQUERYW STRUCT ALIGNMODE
    nmhdr     NMHDR   <>
    pszFormat LPCWSTR ?
    szMax     SIZEL   <>
NMDATETIMEFORMATQUERYW ENDS

NMIPADDRESS STRUCT ALIGNMODE
    hdr     NMHDR <>
    iField  DD    ?
    iValue  DD    ?
NMIPADDRESS ENDS

NMPGSCROLL STRUCT ALIGNMODE
    hdr      NMHDR <>
    fwKeys   BOOL  ?
    rcParent RECT  <>
    iDir     DD    ?
    iXpos    DD    ?
    iYpos    DD    ?
    iScroll  DD    ?
NMPGSCROLL ENDS

NMPGCALCSIZE STRUCT ALIGNMODE
    hdr     NMHDR <>
    dwFlag  DD    ?
    iWidth  DD    ?
    iHeight DD    ?
NMPGCALCSIZE ENDS

LITEM STRUCT ALIGNMODE
    _mask       UINT  ?
    iLink       DD    ?
    state       UINT  ?
    stateMask   UINT  ?
    szID        WCHAR MAX_LINKID_TEXT DUP(?)
    szUrl       WCHAR L_MAX_URL_LENGTH DUP(?)
LITEM ENDS

LHITTESTINFO STRUCT ALIGNMODE
    pt   POINT <>
    item LITEM <>
LHITTESTINFO ENDS

NMLINK STRUCT ALIGNMODE
    hdr  NMHDR <>
    item LITEM <>
NMLINK ENDS

TASKDIALOG_BUTTON STRUCT ALIGNMODE
    ButtonID     DD      ?
    szButtonText LPCWSTR ?
TASKDIALOG_BUTTON ENDS

TASKDIALOGCONFIG STRUCT ALIGNMODE
    cbSize          DD        ?
    hwndParent      HWND      ?
    hInstance       HINSTANCE ?
    dwFlags         ENUM      ?
    dwCommonButtons ENUM      ?
    pszWindowTitle  LPCWSTR   ?
    UNION
        hMainIcon   HICON     ?
        pszMainIcon LPCWSTR   ?
    ENDS
    pszMainInstruction      LPCWSTR ?
    pszContent              LPCWSTR ?
    cButtons                UINT    ?
    pButtons                XPTR    ?
    nDefaultButton          DD      ?
    cRadioButtons           UINT    ?
    pRadioButtons           XPTR    ?
    nDefaultRadioButton     DD      ?
    pszVerificationText     LPCWSTR ?
    pszExpandedInformation  LPCWSTR ?
    pszExpandedControlText  LPCWSTR ?
    pszCollapsedControlText LPCWSTR ?
    UNION
        hFooterIcon     HICON   ?
        pszFooterIcon   LPCWSTR ?
    ENDS
    pszFooter       LPCWSTR  ?
    pfCallback      XPTR     ?
    lpCallbackData  LONG_PTR ?
    cxWidth         UINT     ?
TASKDIALOGCONFIG ENDS

MRUINFO STRUCT ALIGNMODE
    cbSize      DD      ?
    uMax        UINT    ?
    fFlags      UINT    ?
    hKey        HKEY    ?
    lpszSubKey  LPCTSTR ?
    lpfnCompare XPTR    ?
MRUINFO ENDS

PROPSHEETHEADERA STRUCT ALIGNMODE
    dwSize              DD        ?
    dwFlags             DD        ?
    hwndParent          HWND      ?
    hInstance           HINSTANCE ?
    UNION
        hIcon           HICON     ?
        pszIcon         LPCTSTR   ?
    ENDS
    pszCaption          LPCTSTR   ?
    nPages              UINT      ?
    UNION
        nStartPage      UINT      ?
        pStartPage      LPCTSTR   ?
    ENDS
    UNION
        ppsp            XPTR      ?
        phpage          XPTR      ?
    ENDS
    pfnCallback         XPTR      ?
    UNION
        hbmWatermark    HBITMAP   ?
        pszbmWatermark  LPCTSTR   ?
    ENDS
    hplWatermark        HPALETTE  ?
    UNION
        hbmHeader       HBITMAP   ?
        pszbmHeader     LPCSTR    ?
    ENDS
PROPSHEETHEADERA ENDS

PROPSHEETHEADERW STRUCT ALIGNMODE
    dwSize              DD        ?
    dwFlags             DD        ?
    hwndParent          HWND      ?
    hInstance           HINSTANCE ?
    UNION
        hIcon           HICON     ?
        pszIcon         LPCWSTR   ?
    ENDS
    pszCaption          LPCWSTR   ?
    nPages              UINT      ?
    UNION
        nStartPage      UINT      ?
        pStartPage      LPCWSTR   ?
    ENDS
    UNION
        ppsp            XPTR      ?
        phpage          XPTR      ?
    ENDS
    pfnCallback         XPTR      ?
    UNION
        hbmWatermark    HBITMAP   ?
        pszbmWatermark  LPCWSTR   ?
    ENDS
    hplWatermark        HPALETTE  ?
    UNION
        hbmHeader       HBITMAP   ?
        pszbmHeader     LPWSTR    ?
    ENDS
PROPSHEETHEADERW ENDS

PROPSHEETPAGEA STRUCT ALIGNMODE
    dwSize           DD      ?
    dwFlags          DD      ?
    hInstance        HINSTANCE ?
    UNION
        pszTemplate  LPCSTR  ?
        pResource    XPTR    ?
    ENDS
    UNION
        hIcon        HICON   ?
        pszIcon      LPCSTR  ?
    ENDS
    pszTitle         LPCSTR  ?
    pfnDlgProc       XPTR    ?
    lParam           LPARAM  ?
    pfnCallback      XPTR    ?
    pcRefParent      UINT    ?
    IF (NTDDI_VERSION GE NTDDI_WIN2K)
        pszHeaderTitle    DD ?
        pszHeaderSubTitle DD ?
    ENDIF
    IF (NTDDI_VERSION GE NTDDI_WINXP)
        hActCtx      HANDLE  ?
    ENDIF
PROPSHEETPAGEA ENDS

PROPSHEETPAGEW STRUCT ALIGNMODE
    dwSize           DD      ?
    dwFlags          DD      ?
    hInstance        HINSTANCE ?
    UNION
        pszTemplate  LPWSTR  ?
        pResource    XPTR    ?
    ENDS
    UNION
        hIcon        HICON   ?
        pszIcon      LPWSTR  ?
    ENDS
    pszTitle         LPWSTR  ?
    pfnDlgProc       XPTR    ?
    lParam           LPARAM  ?
    pfnCallback      XPTR    ?
    pcRefParent      UINT    ?
    IF (NTDDI_VERSION GE NTDDI_WIN2K)
        pszHeaderTitle    DD ?
        pszHeaderSubTitle DD ?
    ENDIF
    IF (NTDDI_VERSION GE NTDDI_WINXP)
        hActCtx      HANDLE  ?
    ENDIF
PROPSHEETPAGEW ENDS

PROPSHEETHEADER_V1_SIZEA EQU SIZEOF PROPSHEETHEADERA
PROPSHEETHEADER_V1_SIZEW EQU SIZEOF PROPSHEETHEADERW

;======================================== Functions =======================================;
CreateMappedBitmap PROTO :HINSTANCE, :XPTR, :XWORD, :XPTR, :XWORD
CreatePropertySheetPageA PROTO :XPTR
CreatePropertySheetPageW PROTO :XPTR
CreateStatusWindowA PROTO :XWORD, :LPCTSTR, :HWND, :XWORD
CreateStatusWindowW PROTO :XWORD, :LPCWSTR, :HWND, :XWORD
CreateToolbarEx PROTO :HWND, :XWORD, :XWORD, :XWORD, :HINSTANCE, :UINT_PTR, :XPTR, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CreateUpDownControl PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :HWND, :XWORD, :HINSTANCE, :HWND, :XWORD, :XWORD, :XWORD
DestroyPropertySheetPage PROTO :HANDLE
DrawInsert PROTO :HWND, :HWND, :XWORD
DrawStatusTextA PROTO :HDC, :XPTR, :LPCTSTR, :XWORD
DrawStatusTextW PROTO :HDC, :XPTR, :LPCWSTR, :XWORD
FlatSB_EnableScrollBar PROTO :HWND, :XWORD, :XWORD
FlatSB_GetScrollInfo PROTO :HWND, :XWORD, :XPTR
FlatSB_GetScrollPos PROTO :HWND, :XWORD
FlatSB_GetScrollProp PROTO :HWND, :XWORD, :XPTR
FlatSB_GetScrollRange PROTO :HWND, :XWORD, :XPTR, :XPTR
FlatSB_SetScrollInfo PROTO :HWND, :XWORD, :XPTR, :XWORD
FlatSB_SetScrollPos PROTO :HWND, :XWORD, :XWORD, :XWORD
FlatSB_SetScrollProp PROTO :HWND, :XWORD, :INT_PTR, :XWORD
FlatSB_SetScrollRange PROTO :HWND, :XWORD, :XWORD, :XWORD, :XWORD
FlatSB_ShowScrollBar PROTO :HWND, :XWORD, :XWORD
GetEffectiveClientRect PROTO :HWND, :XPTR, :XPTR
GetMUILanguage PROTO
ImageList_Add PROTO :HANDLE, :HBITMAP, :HBITMAP
ImageList_AddIcon PROTO :HANDLE, :HICON
ImageList_AddMasked PROTO :HANDLE, :HBITMAP, :XWORD
ImageList_BeginDrag PROTO :HANDLE, :XWORD, :XWORD, :XWORD
ImageList_Copy PROTO :HANDLE, :XWORD, :HANDLE, :XWORD, :XWORD
ImageList_Create PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
ImageList_Destroy PROTO :HANDLE
ImageList_DragEnter PROTO :HWND, :XWORD, :XWORD
ImageList_DragLeave PROTO :HWND
ImageList_DragMove PROTO :XWORD, :XWORD
ImageList_DragShowNolock PROTO :XWORD
ImageList_Draw PROTO :HANDLE, :XWORD, :HDC, :XWORD, :XWORD, :XWORD
ImageList_DrawEx PROTO :HANDLE, :XWORD, :HDC, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
ImageList_DrawIndirect PROTO :XPTR
ImageList_Duplicate PROTO :HANDLE
ImageList_EndDrag PROTO
ImageList_GetBkColor PROTO :HANDLE
ImageList_GetDragImage PROTO :XPTR, :XPTR
ImageList_GetFlags PROTO :HANDLE
ImageList_GetIcon PROTO :HANDLE, :XWORD, :XWORD
ImageList_GetIconSize PROTO :HANDLE, :XPTR, :XPTR
ImageList_GetImageCount PROTO :HANDLE
ImageList_GetImageInfo PROTO :HANDLE, :XWORD, :XPTR
ImageList_GetImageRect PROTO :HANDLE, :XWORD, :XPTR
ImageList_LoadImageA PROTO :HINSTANCE, :LPCTSTR, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
ImageList_LoadImageW PROTO :HINSTANCE, :LPCWSTR, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
ImageList_Merge PROTO :HANDLE, :XWORD, :HANDLE, :XWORD, :XWORD, :XWORD
ImageList_Read PROTO :XPTR
ImageList_Remove PROTO :HANDLE, :XWORD
ImageList_Replace PROTO :HANDLE, :XWORD, :HBITMAP, :HBITMAP
ImageList_ReplaceIcon PROTO :HANDLE, :XWORD, :HICON
ImageList_SetBkColor PROTO :HANDLE, :XWORD
ImageList_SetDragCursorImage PROTO :HANDLE, :XWORD, :XWORD, :XWORD
ImageList_SetFilter PROTO :HANDLE, :XWORD, :XWORD
ImageList_SetFlags PROTO :HANDLE, :XWORD
ImageList_SetIconSize PROTO :HANDLE, :XWORD, :XWORD
ImageList_SetImageCount PROTO :HANDLE, :XWORD
ImageList_SetOverlayImage PROTO :HANDLE, :XWORD, :XWORD
ImageList_Write PROTO :HANDLE, :XPTR
InitCommonControls PROTO
InitCommonControlsEx PROTO :XPTR
InitializeFlatSB PROTO :HWND
InitMUILanguage PROTO :XWORD
LBItemFromPt PROTO :HWND, :XPTR, :XWORD
MakeDragList PROTO :HWND
MenuHelp PROTO :XWORD, :WPARAM, :LPARAM, :HMENU, :HINSTANCE, :HWND, :XPTR
PropertySheetA PROTO :XPTR
PropertySheetW PROTO :XPTR
ShowHideMenuCtl PROTO :HWND, :UINT_PTR, :XPTR
UninitializeFlatSB PROTO :HWND
_TrackMouseEvent PROTO :XPTR

IF (NTDDI_VERSION GE NTDDI_WINXP)
    AddMRUStringW PROTO :HANDLE, :LPCTSTR
    CreateMRUListW PROTO :XPTR
    DefSubclassProc PROTO :HWND, :XWORD, :WPARAM, :LPARAM
    DPA_Create PROTO :XWORD
    DPA_DeleteAllPtrs PROTO :XWORD
    DPA_DeletePtr PROTO :XWORD, :XPTR, :XPTR
    DPA_Destroy PROTO :XWORD
    DPA_DestroyCallback PROTO :XWORD, :XPTR, :XPTR
    DPA_EnumCallback PROTO :XWORD, :XPTR, :XPTR
    DPA_GetPtr PROTO :XWORD, :XWORD
    DPA_InsertPtr PROTO :XWORD, :XWORD, :XPTR
    DPA_Search PROTO :XWORD, :XPTR, :XWORD, :XPTR, :LPARAM,:XWORD
    DPA_SetPtr PROTO :XWORD, :XWORD, :XPTR
    DPA_Sort PROTO :XWORD, :XPTR, :LPARAM
    DSA_Create PROTO :XWORD, :XWORD
    DSA_DeleteAllItems PROTO :XWORD
    DSA_Destroy PROTO :XWORD
    DSA_DestroyCallback PROTO :XWORD, :XPTR, :XPTR
    DSA_GetItemPtr PROTO :XWORD, :XWORD
    DSA_InsertItem PROTO :XWORD, :XWORD, :XPTR
    EnumMRUListW PROTO :HANDLE, :XWORD, :XPTR, :XWORD
    FlatSB_GetScrollPropPtr PROTO :HWND, :XWORD, :XPTR
    FreeMRUList PROTO :HANDLE
    RegisterClassNameW PROTO :LPCWSTR
    RemoveWindowSubclass PROTO :HWND, :XPTR, :UINT_PTR
    SetWindowSubclass PROTO :HWND, :XPTR, :UINT_PTR, :XWORD
ENDIF

IF (NTDDI_VERSION GE NTDDI_VISTA)
    DPA_Clone PROTO :XWORD, :XWORD
    DPA_CreateEx PROTO :XWORD, :HANDLE
    DPA_GetPtrIndex PROTO :XWORD, :XPTR
    DPA_Grow PROTO :XWORD, :XWORD
    DPA_LoadStream PROTO :XPTR, :XPTR, :XPTR, :XPTR
    DPA_Merge PROTO :XWORD, :XWORD, :XWORD, :XPTR, :XPTR, :LPARAM
    DPA_SaveStream PROTO :XWORD, :XPTR, :XPTR, :XPTR
    DSA_DeleteItem PROTO :XWORD, :XWORD
    DSA_EnumCallback PROTO :XWORD, :XPTR, :XPTR
    DSA_GetItem PROTO :XWORD, :XWORD, :XPTR
    DSA_SetItem PROTO :XWORD, :XWORD, :XPTR
    Str_SetPtrA PROTO :LPWSTR, :LPCWSTR
    Str_SetPtrW PROTO :LPWSTR, :LPCWSTR
ENDIF

IFDEF APP_UNICODE
    ACM_OPEN EQU <ACM_OPENW>
    ANIMATE_CLASS EQU <ANIMATE_CLASSW>
    CBEM_GETITEM EQU <CBEM_GETITEMW>
    CBEM_INSERTITEM EQU <CBEM_INSERTITEMW>
    CBEM_SETITEM EQU <CBEM_SETITEMW>
    CBEN_DRAGBEGIN EQU <CBEN_DRAGBEGINW>
    CBEN_ENDEDIT EQU <CBEN_ENDEDITW>
    CBEN_GETDISPINFO EQU <CBEN_GETDISPINFOW>
    COMBOBOXEXITEM EQU <COMBOBOXEXITEMW>
    DATETIMEPICK_CLASS EQU <DATETIMEPICK_CLASSW>
    DTM_SETFORMAT EQU <DTM_SETFORMATW>
    DTN_FORMAT EQU <DTN_FORMATW>
    DTN_FORMATQUERY EQU <DTN_FORMATQUERYW>
    DTN_USERSTRING EQU <DTN_USERSTRINGW>
    DTN_WMKEYDOWN EQU <DTN_WMKEYDOWNW>
    HD_ITEM EQU <HDITEMW>
    HD_NOTIFY EQU <NMHEADERW>
    HD_TEXTFILTER EQU <HDTEXTFILTERW>
    HDITEM EQU <HDITEMW>
    HDITEM_V1_SIZE EQU <HDITEMW_V1_SIZE>
    HDM_GETITEM EQU <HDM_GETITEMW>
    HDM_INSERTITEM EQU <HDM_INSERTITEMW>
    HDM_SETITEM EQU <HDM_SETITEMW>
    HDN_BEGINTRACK EQU <HDN_BEGINTRACKW>
    HDN_DIVIDERDBLCLICK EQU <HDN_DIVIDERDBLCLICKW>
    HDN_ENDTRACK EQU <HDN_ENDTRACKW>
    HDN_GETDISPINFO EQU <HDN_GETDISPINFOW>
    HDN_ITEMCHANGED EQU <HDN_ITEMCHANGEDW>
    HDN_ITEMCHANGING EQU <HDN_ITEMCHANGINGW>
    HDN_ITEMCLICK EQU <HDN_ITEMCLICKW>
    HDN_ITEMDBLCLICK EQU <HDN_ITEMDBLCLICKW>
    HDN_TRACK EQU <HDN_TRACKW>
    HOTKEY_CLASS EQU <HOTKEY_CLASSW>
    HDTEXTFILTER  EQU <HDTEXTFILTERW>
    LV_COLUMN EQU <LVCOLUMNW>
    LV_DISPINFO EQU <NMLVDISPINFOW>
    LV_FINDINFO EQU <LVFINDINFOW>
    LV_ITEM EQU <LVITEMW>
    LVBKIMAGE EQU <LVBKIMAGEW>
    LVCOLUMN EQU <LVCOLUMNW>
    LVFINDINFO EQU <LVFINDINFOW>
    LVITEM EQU <LVITEMW>
    LVM_EDITLABEL EQU <LVM_EDITLABELW>
    LVM_FINDITEM EQU <LVM_FINDITEMW>
    LVM_GETBKIMAGE EQU <LVM_GETBKIMAGEW>
    LVM_GETCOLUMN EQU <LVM_GETCOLUMNW>
    LVM_GETISEARCHSTRING EQU <LVM_GETISEARCHSTRINGW>
    LVM_GETITEM EQU <LVM_GETITEMW>
    LVM_GETITEMTEXT EQU <LVM_GETITEMTEXTW>
    LVM_GETSTRINGWIDTH EQU <LVM_GETSTRINGWIDTHW>
    LVM_INSERTCOLUMN EQU <LVM_INSERTCOLUMNW>
    LVM_INSERTITEM EQU <LVM_INSERTITEMW>
    LVM_SETBKIMAGE EQU <LVM_SETBKIMAGEW>
    LVM_SETCOLUMN EQU <LVM_SETCOLUMNW>
    LVM_SETITEM EQU <LVM_SETITEMW>
    LVM_SETITEMTEXT EQU <LVM_SETITEMTEXTW>
    LVN_BEGINLABELEDIT EQU <LVN_BEGINLABELEDITW>
    LVN_ENDLABELEDIT EQU <LVN_ENDLABELEDITW>
    LVN_GETDISPINFO EQU <LVN_GETDISPINFOW>
    LVN_GETINFOTIP EQU <LVN_GETINFOTIPW>
    LVN_INCREMENTALSEARCH EQU <LVN_INCREMENTALSEARCHW>
    LVN_ODFINDITEM EQU <LVN_ODFINDITEMW>
    LVN_SETDISPINFO EQU <LVN_SETDISPINFOW>
    MONTHCAL_CLASS EQU <MONTHCAL_CLASSW>
    NM_FINDITEM EQU <NMLVFINDITEMW>
    NM_TREEVIEW EQU <NMTREEVIEWW>
    NMCBEDRAGBEGIN EQU <NMCBEDRAGBEGINW>
    NMCBEENDEDIT EQU <NMCBEENDEDITW>
    NMCOMBOBOXEX EQU <NMCOMBOBOXEXW>
    NMDATETIMEFORMAT EQU <NMDATETIMEFORMATW>
    NMDATETIMEFORMATQUERY EQU <NMDATETIMEFORMATQUERYW>
    NMDATETIMESTRING EQU <NMDATETIMESTRINGW>
    NMHDDISPINFO EQU <NMHDDISPINFOW>
    NMHEADER EQU <NMHEADERW>
    NMLVDISPINFO EQU <NMLVDISPINFOW>
    NMLVGETINFOTIP EQU <NMLVGETINFOTIPW>
    NMTBDISPINFO EQU <NMTBDISPINFOW>
    NMTBGETINFOTIP EQU <NMTBGETINFOTIPW>
    NMTOOLBAR EQU <NMTOOLBARW>
    NMTREEVIEW EQU <NMTREEVIEWW>
    NMTTDISPINFO EQU <NMTTDISPINFOW>
    NMTTDISPINFO_V1_SIZE EQU <NMTTDISPINFOW_V1_SIZE>
    NMTVDISPINFO EQU <NMTVDISPINFOW>
    NMTVDISPINFOEX EQU <NMTVDISPINFOEXW>
    NMTVGETINFOTIP EQU <NMTVGETINFOTIPW>
    PROGRESS_CLASS EQU <PROGRESS_CLASSW>
    PROPSHEETHEADER EQU <PROPSHEETHEADERW>
    PROPSHEETPAGE EQU <PROPSHEETPAGEW>
    PROPSHEETHEADER_V1_SIZE EQU <PROPSHEETHEADERW_V1_SIZEW>
    RB_GETBANDINFO EQU <RB_GETBANDINFOW>
    RB_INSERTBAND EQU <RB_INSERTBANDW>
    RB_SETBANDINFO EQU <RB_SETBANDINFOW>
    REBARBANDINFO EQU <REBARBANDINFOW>
    REBARBANDINFO_V3_SIZE EQU <REBARBANDINFOW_V3_SIZE>
    REBARCLASSNAME EQU <REBARCLASSNAMEW>
    SB_GETTEXT EQU <SB_GETTEXTW>
    SB_GETTEXTLENGTH EQU <SB_GETTEXTLENGTHW>
    SB_GETTIPTEXT EQU <SB_GETTIPTEXTW>
    SB_SETTEXT EQU <SB_SETTEXTW>
    SB_SETTIPTEXT EQU <SB_SETTIPTEXTW>
    STATUSCLASSNAME EQU <STATUSCLASSNAMEW>
    TB_ADDBUTTONS EQU <TB_ADDBUTTONSW>
    TB_ADDSTRING EQU <TB_ADDSTRINGW>
    TB_GETBUTTONINFO EQU <TB_GETBUTTONINFOW>
    TB_GETBUTTONTEXT EQU <TB_GETBUTTONTEXTW>
    TB_GETSTRING EQU <TB_GETSTRINGW>
    TB_INSERTBUTTON EQU <TB_INSERTBUTTONW>
    TB_MAPACCELERATOR EQU <TB_MAPACCELERATORW>
    TB_SAVERESTORE EQU <TB_SAVERESTOREW>
    TB_SETBUTTONINFO EQU <TB_SETBUTTONINFOW>
    TBBUTTONINFO EQU <TBBUTTONINFOW>
    TBN_GETBUTTONINFO EQU <TBN_GETBUTTONINFOW>
    TBN_GETDISPINFO EQU <TBN_GETDISPINFOW>
    TBN_GETINFOTIP EQU <TBN_GETINFOTIPW>
    TBNOTIFY EQU <NMTOOLBARW>
    TBSAVEPARAMS EQU <TBSAVEPARAMSW>
    TC_ITEM EQU <TCITEMW>
    TC_ITEMHEADER EQU <TCITEMHEADERW>
    TCITEM EQU <TCITEMW>
    TCITEMHEADER EQU <TCITEMHEADERW>
    TCM_GETITEM EQU <TCM_GETITEMW>
    TCM_INSERTITEM EQU <TCM_INSERTITEMW>
    TCM_SETITEM EQU <TCM_SETITEMW>
    TOOLBARCLASSNAME EQU <TOOLBARCLASSNAMEW>
    TOOLINFO EQU <TTTOOLINFOW>
    TOOLINFO_V1_SIZE EQU <TOOLINFOW_V1_SIZE>
    TOOLTIPS_CLASS EQU <TOOLTIPS_CLASSW>
    TOOLTIPTEXT EQU <NMTTDISPINFOW>
    TRACKBAR_CLASS EQU <TRACKBAR_CLASSW>
    TTHITTESTINFO EQU <TTHITTESTINFOW>
    TTM_ADDTOOL EQU <TTM_ADDTOOLW>
    TTM_DELTOOL EQU <TTM_DELTOOLW>
    TTM_ENUMTOOLS EQU <TTM_ENUMTOOLSW>
    TTM_GETCURRENTTOOL EQU <TTM_GETCURRENTTOOLW>
    TTM_GETTEXT EQU <TTM_GETTEXTW>
    TTM_GETTOOLINFO EQU <TTM_GETTOOLINFOW>
    TTM_HITTEST EQU <TTM_HITTESTW>
    TTM_NEWTOOLRECT EQU <TTM_NEWTOOLRECTW>
    TTM_SETTITLE EQU <TTM_SETTITLEW>
    TTM_SETTOOLINFO EQU <TTM_SETTOOLINFOW>
    TTM_UPDATETIPTEXT EQU <TTM_UPDATETIPTEXTW>
    TTN_GETDISPINFO EQU <TTN_GETDISPINFOW>
    TTN_NEEDTEXT EQU <TTN_GETDISPINFOW>
    TTTOOLINFO EQU <TTTOOLINFOW>
    TT_HITTESTINFO EQU <TTHITTESTINFOW>
    TV_DISPINFO EQU <NMTVDISPINFOW>
    TV_DISPINFOEX EQU <NMTVDISPINFOEXW>
    TV_INSERTSTRUCT EQU <TVINSERTSTRUCTW>
    TV_ITEM EQU <TVITEMW>
    TV_ITEMEX EQU <TVITEMEXW>
    TVINSERTSTRUCT EQU <TVINSERTSTRUCTW>
    TVITEM EQU <TVITEMW>
    TVITEMEX EQU <TVITEMEXW>
    TVM_EDITLABEL EQU <TVM_EDITLABELW>
    TVM_GETISEARCHSTRING EQU <TVM_GETISEARCHSTRINGW>
    TVM_GETITEM EQU <TVM_GETITEMW>
    TVM_INSERTITEM EQU <TVM_INSERTITEMW>
    TVM_SETITEM EQU <TVM_SETITEMW>
    TVN_BEGINDRAG EQU <TVN_BEGINDRAGW>
    TVN_BEGINLABELEDIT EQU <TVN_BEGINLABELEDITW>
    TVN_BEGINRDRAG EQU <TVN_BEGINRDRAGW>
    TVN_DELETEITEM EQU <TVN_DELETEITEMW>
    TVN_ENDLABELEDIT EQU <TVN_ENDLABELEDITW>
    TVN_GETDISPINFO EQU <TVN_GETDISPINFOW>
    TVN_GETINFOTIP EQU <TVN_GETINFOTIPW>
    TVN_ITEMCHANGED EQU <TVN_ITEMCHANGEDW>
    TVN_ITEMCHANGING EQU <TVN_ITEMCHANGINGW>
    TVN_ITEMEXPANDED EQU <TVN_ITEMEXPANDEDW>
    TVN_ITEMEXPANDING EQU <TVN_ITEMEXPANDINGW>
    TVN_SELCHANGED EQU <TVN_SELCHANGEDW>
    TVN_SELCHANGING EQU <TVN_SELCHANGINGW>
    TVN_SETDISPINFO EQU <TVN_SETDISPINFOW>
    UPDOWN_CLASS EQU <UPDOWN_CLASSW>
    WC_COMBOBOXEX EQU <WC_COMBOBOXEXW>
    WC_HEADER EQU <WC_HEADERW>
    WC_IPADDRESS EQU <WC_IPADDRESSW>
    WC_LISTVIEW EQU <WC_LISTVIEWW>
    WC_NATIVEFONTCTL EQU <WC_NATIVEFONTCTLW>
    WC_PAGESCROLLER EQU <WC_PAGESCROLLERW>
    WC_TABCONTROL EQU <WC_TABCONTROLW>
    WC_TREEVIEW EQU <WC_TREEVIEWW>
    CreatePropertySheetPage EQU <CreatePropertySheetPageW>
    CreateStatusWindow EQU <CreateStatusWindowW>
    DrawStatusText EQU <DrawStatusTextW>
    ImageList_LoadImage EQU <ImageList_LoadImageW>
    PropertySheet EQU <PropertySheetW>
    IF (NTDDI_VERSION GE NTDDI_VISTA)
        Str_SetPtr EQU <Str_SetPtrW>
    ENDIF
ELSE
    ACM_OPEN EQU <ACM_OPENA>
    ANIMATE_CLASS EQU <ANIMATE_CLASSA>
    CBEM_GETITEM EQU <CBEM_GETITEMA>
    CBEM_INSERTITEM EQU <CBEM_INSERTITEMA>
    CBEM_SETITEM EQU <CBEM_SETITEMA>
    CBEN_DRAGBEGIN EQU <CBEN_DRAGBEGINA>
    CBEN_ENDEDIT EQU <CBEN_ENDEDITA>
    CBEN_GETDISPINFO EQU <CBEN_GETDISPINFOA>
    COMBOBOXEXITEM EQU <COMBOBOXEXITEMA>
    DATETIMEPICK_CLASS EQU <DATETIMEPICK_CLASSA>
    DTM_SETFORMAT EQU <DTM_SETFORMATA>
    DTN_FORMAT EQU <DTN_FORMATA>
    DTN_FORMATQUERY EQU <DTN_FORMATQUERYA>
    DTN_USERSTRING EQU <DTN_USERSTRINGA>
    DTN_WMKEYDOWN EQU <DTN_WMKEYDOWNA>
    HD_ITEM EQU <HDITEMA>
    HD_NOTIFY EQU <NMHEADERA>
    HD_TEXTFILTER EQU <HDTEXTFILTERA>
    HDITEM EQU <HDITEMA>
    HDITEM_V1_SIZE EQU <HDITEMA_V1_SIZE>
    HDM_GETITEM EQU <HDM_GETITEMA>
    HDM_INSERTITEM EQU <HDM_INSERTITEMA>
    HDM_SETITEM EQU <HDM_SETITEMA>
    HDN_BEGINTRACK EQU <HDN_BEGINTRACKA>
    HDN_DIVIDERDBLCLICK EQU <HDN_DIVIDERDBLCLICKA>
    HDN_ENDTRACK EQU <HDN_ENDTRACKA>
    HDN_GETDISPINFO EQU <HDN_GETDISPINFOA>
    HDN_ITEMCHANGED EQU <HDN_ITEMCHANGEDA>
    HDN_ITEMCHANGING EQU <HDN_ITEMCHANGINGA>
    HDN_ITEMCLICK EQU <HDN_ITEMCLICKA>
    HDN_ITEMDBLCLICK EQU <HDN_ITEMDBLCLICKA>
    HDN_TRACK EQU <HDN_TRACKA>
    HOTKEY_CLASS EQU <HOTKEY_CLASSA>
    HDTEXTFILTER  EQU <HDTEXTFILTERA>
    LV_COLUMN EQU <LVCOLUMNA>
    LV_DISPINFO EQU <NMLVDISPINFOA>
    LV_FINDINFO EQU <LVFINDINFOA>
    LV_ITEM EQU <LVITEMA>
    LVBKIMAGE EQU <LVBKIMAGEA>
    LVCOLUMN EQU <LVCOLUMNA>
    LVFINDINFO EQU <LVFINDINFOA>
    LVITEM EQU <LVITEMA>
    LVM_EDITLABEL EQU <LVM_EDITLABELA>
    LVM_FINDITEM EQU <LVM_FINDITEMA>
    LVM_GETBKIMAGE EQU <LVM_GETBKIMAGEA>
    LVM_GETCOLUMN EQU <LVM_GETCOLUMNA>
    LVM_GETISEARCHSTRING EQU <LVM_GETISEARCHSTRINGA>
    LVM_GETITEM EQU <LVM_GETITEMA>
    LVM_GETITEMTEXT EQU <LVM_GETITEMTEXTA>
    LVM_GETSTRINGWIDTH EQU <LVM_GETSTRINGWIDTHA>
    LVM_INSERTCOLUMN EQU <LVM_INSERTCOLUMNA>
    LVM_INSERTITEM EQU <LVM_INSERTITEMA>
    LVM_SETBKIMAGE EQU <LVM_SETBKIMAGEA>
    LVM_SETCOLUMN EQU <LVM_SETCOLUMNA>
    LVM_SETITEM EQU <LVM_SETITEMA>
    LVM_SETITEMTEXT EQU <LVM_SETITEMTEXTA>
    LVN_BEGINLABELEDIT EQU <LVN_BEGINLABELEDITA>
    LVN_ENDLABELEDIT EQU <LVN_ENDLABELEDITA>
    LVN_GETDISPINFO EQU <LVN_GETDISPINFOA>
    LVN_GETINFOTIP EQU <LVN_GETINFOTIPA>
    LVN_INCREMENTALSEARCH EQU <LVN_INCREMENTALSEARCHA>
    LVN_ODFINDITEM EQU <LVN_ODFINDITEMA>
    LVN_SETDISPINFO EQU <LVN_SETDISPINFOA>
    MONTHCAL_CLASS EQU <MONTHCAL_CLASSA>
    NM_FINDITEM EQU <NMLVFINDITEMA>
    NM_TREEVIEW EQU <NMTREEVIEWA>
    NMCBEDRAGBEGIN EQU <NMCBEDRAGBEGINA>
    NMCBEENDEDIT EQU <NMCBEENDEDITA>
    NMCOMBOBOXEX EQU <NMCOMBOBOXEXA>
    NMDATETIMEFORMAT EQU <NMDATETIMEFORMATA>
    NMDATETIMEFORMATQUERY EQU <NMDATETIMEFORMATQUERYA>
    NMDATETIMESTRING EQU <NMDATETIMESTRINGA>
    NMHDDISPINFO EQU <NMHDDISPINFOA>
    NMHEADER EQU <NMHEADERA>
    NMLVDISPINFO EQU <NMLVDISPINFOA>
    NMLVGETINFOTIP EQU <NMLVGETINFOTIPA>
    NMTBDISPINFO EQU <NMTBDISPINFOA>
    NMTBGETINFOTIP EQU <NMTBGETINFOTIPA>
    NMTOOLBAR EQU <NMTOOLBARA>
    NMTREEVIEW EQU <NMTREEVIEWA>
    NMTTDISPINFO EQU <NMTTDISPINFOA>
    NMTTDISPINFO_V1_SIZE EQU <NMTTDISPINFOA_V1_SIZE>
    NMTVDISPINFO EQU <NMTVDISPINFOA>
    NMTVDISPINFOEX EQU <NMTVDISPINFOEXA>
    NMTVGETINFOTIP EQU <NMTVGETINFOTIPA>
    PROGRESS_CLASS EQU <PROGRESS_CLASSA>
    PROPSHEETHEADER EQU <PROPSHEETHEADERA>
    PROPSHEETPAGE EQU <PROPSHEETPAGEA>
    PROPSHEETHEADER_V1_SIZE EQU <PROPSHEETHEADERW_V1_SIZEA>
    RB_GETBANDINFO EQU <RB_GETBANDINFOA>
    RB_INSERTBAND EQU <RB_INSERTBANDA>
    RB_SETBANDINFO EQU <RB_SETBANDINFOA>
    REBARBANDINFO EQU <REBARBANDINFOA>
    REBARBANDINFO_V3_SIZE EQU <REBARBANDINFOA_V3_SIZE>
    REBARCLASSNAME EQU <REBARCLASSNAMEA>
    SB_GETTEXT EQU <SB_GETTEXTA>
    SB_GETTEXTLENGTH EQU <SB_GETTEXTLENGTHA>
    SB_GETTIPTEXT EQU <SB_GETTIPTEXTA>
    SB_SETTEXT EQU <SB_SETTEXTA>
    SB_SETTIPTEXT EQU <SB_SETTIPTEXTA>
    STATUSCLASSNAME EQU <STATUSCLASSNAMEA>
    TB_ADDBUTTONS EQU <TB_ADDBUTTONSA>
    TB_ADDSTRING EQU <TB_ADDSTRINGA>
    TB_GETBUTTONINFO EQU <TB_GETBUTTONINFOA>
    TB_GETBUTTONTEXT EQU <TB_GETBUTTONTEXTA>
    TB_GETSTRING EQU <TB_GETSTRINGA>
    TB_INSERTBUTTON EQU <TB_INSERTBUTTONA>
    TB_MAPACCELERATOR EQU <TB_MAPACCELERATORA>
    TB_SAVERESTORE EQU <TB_SAVERESTOREA>
    TB_SETBUTTONINFO EQU <TB_SETBUTTONINFOA>
    TBBUTTONINFO EQU <TBBUTTONINFOA>
    TBN_GETBUTTONINFO EQU <TBN_GETBUTTONINFOA>
    TBN_GETDISPINFO EQU <TBN_GETDISPINFOA>
    TBN_GETINFOTIP EQU <TBN_GETINFOTIPA>
    TBNOTIFY EQU <NMTOOLBARA>
    TBSAVEPARAMS EQU <TBSAVEPARAMSA>
    TC_ITEM EQU <TCITEMA>
    TC_ITEMHEADER EQU <TCITEMHEADERA>
    TCITEM EQU <TCITEMA>
    TCITEMHEADER EQU <TCITEMHEADERA>
    TCM_GETITEM EQU <TCM_GETITEMA>
    TCM_INSERTITEM EQU <TCM_INSERTITEMA>
    TCM_SETITEM EQU <TCM_SETITEMA>
    TOOLBARCLASSNAME EQU <TOOLBARCLASSNAMEA>
    TOOLINFO EQU <TTTOOLINFOA>
    TOOLINFO_V1_SIZE EQU <TOOLINFOA_V1_SIZE>
    TOOLTIPS_CLASS EQU <TOOLTIPS_CLASSA>
    TOOLTIPTEXT EQU <NMTTDISPINFOA>
    TRACKBAR_CLASS EQU <TRACKBAR_CLASSA>
    TTHITTESTINFO EQU <TTHITTESTINFOA>
    TTM_ADDTOOL EQU <TTM_ADDTOOLA>
    TTM_DELTOOL EQU <TTM_DELTOOLA>
    TTM_ENUMTOOLS EQU <TTM_ENUMTOOLSA>
    TTM_GETCURRENTTOOL EQU <TTM_GETCURRENTTOOLA>
    TTM_GETTEXT EQU <TTM_GETTEXTA>
    TTM_GETTOOLINFO EQU <TTM_GETTOOLINFOA>
    TTM_HITTEST EQU <TTM_HITTESTA>
    TTM_NEWTOOLRECT EQU <TTM_NEWTOOLRECTA>
    TTM_SETTITLE EQU <TTM_SETTITLEA>
    TTM_SETTOOLINFO EQU <TTM_SETTOOLINFOA>
    TTM_UPDATETIPTEXT EQU <TTM_UPDATETIPTEXTA>
    TTN_GETDISPINFO EQU <TTN_GETDISPINFOA>
    TTN_NEEDTEXT EQU <TTN_GETDISPINFOA>
    TTTOOLINFO EQU <TTTOOLINFOA>
    TT_HITTESTINFO EQU <TTHITTESTINFOA>
    TV_DISPINFO EQU <NMTVDISPINFOA>
    TV_DISPINFOEX EQU <NMTVDISPINFOEXA>
    TV_INSERTSTRUCT EQU <TVINSERTSTRUCTA>
    TV_ITEM EQU <TVITEMA>
    TV_ITEMEX EQU <TVITEMEXA>
    TVINSERTSTRUCT EQU <TVINSERTSTRUCTA>
    TVITEM EQU <TVITEMA>
    TVITEMEX EQU <TVITEMEXA>
    TVM_EDITLABEL EQU <TVM_EDITLABELA>
    TVM_GETISEARCHSTRING EQU <TVM_GETISEARCHSTRINGA>
    TVM_GETITEM EQU <TVM_GETITEMA>
    TVM_INSERTITEM EQU <TVM_INSERTITEMA>
    TVM_SETITEM EQU <TVM_SETITEMA>
    TVN_BEGINDRAG EQU <TVN_BEGINDRAGA>
    TVN_BEGINLABELEDIT EQU <TVN_BEGINLABELEDITA>
    TVN_BEGINRDRAG EQU <TVN_BEGINRDRAGA>
    TVN_DELETEITEM EQU <TVN_DELETEITEMA>
    TVN_ENDLABELEDIT EQU <TVN_ENDLABELEDITA>
    TVN_GETDISPINFO EQU <TVN_GETDISPINFOA>
    TVN_GETINFOTIP EQU <TVN_GETINFOTIPA>
    TVN_ITEMCHANGED EQU <TVN_ITEMCHANGEDA>
    TVN_ITEMCHANGING EQU <TVN_ITEMCHANGINGA>
    TVN_ITEMEXPANDED EQU <TVN_ITEMEXPANDEDA>
    TVN_ITEMEXPANDING EQU <TVN_ITEMEXPANDINGA>
    TVN_SELCHANGED EQU <TVN_SELCHANGEDA>
    TVN_SELCHANGING EQU <TVN_SELCHANGINGA>
    TVN_SETDISPINFO EQU <TVN_SETDISPINFOA>
    UPDOWN_CLASS EQU <UPDOWN_CLASSA>
    WC_COMBOBOXEX EQU <WC_COMBOBOXEXA>
    WC_HEADER EQU <WC_HEADERA>
    WC_IPADDRESS EQU <WC_IPADDRESSA>
    WC_LISTVIEW EQU <WC_LISTVIEWA>
    WC_NATIVEFONTCTL EQU <WC_NATIVEFONTCTLA>
    WC_PAGESCROLLER EQU <WC_PAGESCROLLERA>
    WC_TABCONTROL EQU <WC_TABCONTROLA>
    WC_TREEVIEW EQU <WC_TREEVIEWA>
    CreatePropertySheetPage EQU <CreatePropertySheetPageA>
    CreateStatusWindow EQU <CreateStatusWindowA>
    DrawStatusText EQU <DrawStatusTextA>
    ImageList_LoadImage EQU <ImageList_LoadImageA>
    PropertySheet EQU <PropertySheetA>
    IF (NTDDI_VERSION GE NTDDI_VISTA)
        Str_SetPtr EQU <Str_SetPtrA>
    ENDIF
ENDIF

;======================= Undocumented functions (unknown arguments) =======================;
;CreateToolbar PROTO

ENDIF ;COMCTL32_INC
