; ====================================================;
;                                                     ;
;     user32.inc for EC v2 SolAsm visual projects     ;
;                   (version 1.0.5)                   ;
;                                                     ;
;          Copyright © Ramon Sala - 2018-2020         ;
;                                                     ;
; ====================================================;

#ifndef USER32_INC
USER32_INC equ 1

MSGFLT_ADD                                      equ     1
MSGFLT_REMOVE                                   equ     2

RT_CURSOR                                       equ     1
RT_BITMAP                                       equ     2
RT_ICON                                         equ     3
RT_MENU                                         equ     4
RT_DIALOG                                       equ     5
RT_STRING                                       equ     6
RT_FONTDIR                                      equ     7
RT_FONT                                         equ     8
RT_ACCELERATOR                                  equ     9
RT_RCDATA                                       equ     10
RT_MESSAGETABLE                                 equ     11
DIFFERENCE                                      equ     11
RT_GROUP_CURSOR                                 equ     (RT_CURSOR+DIFFERENCE)
RT_GROUP_ICON                                   equ     (RT_ICON+DIFFERENCE)
#ifndef RT_VERSION
    RT_VERSION                                  equ     16
#endif
RT_DLGINCLUDE                                   equ     17
RT_PLUGPLAY                                     equ     19
RT_VXD                                          equ     20
RT_ANICURSOR                                    equ     21
RT_ANIICON                                      equ     22
RT_HTML                                         equ     23
RT_MANIFEST                                     equ     24

SETWALLPAPER_DEFAULT                            equ     (-1)

CREATEPROCESS_MANIFEST_RESOURCE_ID              equ     1
ISOLATIONAWARE_MANIFEST_RESOURCE_ID             equ     2
ISOLATIONAWARE_NOSTATICIMPORT_MANIFEST_RESOURCE_ID         equ     3
MINIMUM_RESERVED_MANIFEST_RESOURCE_ID           equ     1
MAXIMUM_RESERVED_MANIFEST_RESOURCE_ID           equ     16

MAPVK_VK_TO_VSC                                 equ     0
MAPVK_VSC_TO_VK                                 equ     1
MAPVK_VK_TO_CHAR                                equ     2
MAPVK_VSC_TO_VK_EX                              equ     3
MAPVK_VK_TO_VSC_EX                              equ     4

TIMERV_DEFAULT_COALESCING                       equ     0
TIMERV_NO_COALESCING                            equ     0FFFFFFFFH
TIMERV_COALESCING_MIN                           equ     1
TIMERV_COALESCING_MAX                           equ     0FFFH

SB_HORZ                                         equ     0
SB_VERT                                         equ     1
SB_CTL                                          equ     2
SB_BOTH                                         equ     3

SB_LINEUP                                       equ     0
SB_LINELEFT                                     equ     0
SB_LINEDOWN                                     equ     1
SB_LINERIGHT                                    equ     1
SB_PAGEUP                                       equ     2
SB_PAGELEFT                                     equ     2
SB_PAGEDOWN                                     equ     3
SB_PAGERIGHT                                    equ     3
SB_THUMBPOSITION                                equ     4
SB_THUMBTRACK                                   equ     5
SB_TOP                                          equ     6
SB_LEFT                                         equ     6
SB_BOTTOM                                       equ     7
SB_RIGHT                                        equ     7
SB_ENDSCROLL                                    equ     8

SW_HIDE                                         equ     0
SW_SHOWNORMAL                                   equ     1
SW_NORMAL                                       equ     1
SW_SHOWMINIMIZED                                equ     2
SW_SHOWMAXIMIZED                                equ     3
SW_MAXIMIZE                                     equ     3
SW_SHOWNOACTIVATE                               equ     4
SW_SHOW                                         equ     5
SW_MINIMIZE                                     equ     6
SW_SHOWMINNOACTIVE                              equ     7
SW_SHOWNA                                       equ     8
SW_RESTORE                                      equ     9
SW_SHOWDEFAULT                                  equ     10
SW_FORCEMINIMIZE                                equ     11
SW_MAX                                          equ     11

HIDE_WINDOW                                     equ     0
SHOW_OPENWINDOW                                 equ     1
SHOW_ICONWINDOW                                 equ     2
SHOW_FULLSCREEN                                 equ     3
SHOW_OPENNOACTIVATE                             equ     4

SW_PARENTCLOSING                                equ     1
SW_OTHERZOOM                                    equ     2
SW_PARENTOPENING                                equ     3
SW_OTHERUNZOOM                                  equ     4

AW_HOR_POSITIVE                                 equ     000000001H
AW_HOR_NEGATIVE                                 equ     000000002H
AW_VER_POSITIVE                                 equ     000000004H
AW_VER_NEGATIVE                                 equ     000000008H
AW_CENTER                                       equ     000000010H
AW_HIDE                                         equ     000010000H
AW_ACTIVATE                                     equ     000020000H
AW_SLIDE                                        equ     000040000H
AW_BLEND                                        equ     000080000H

KF_EXTENDED                                     equ     00100H
KF_DLGMODE                                      equ     00800H
KF_MENUMODE                                     equ     01000H
KF_ALTDOWN                                      equ     02000H
KF_REPEAT                                       equ     04000H
KF_UP                                           equ     08000H

VK_LBUTTON                                      equ     001H
VK_RBUTTON                                      equ     002H
VK_CANCEL                                       equ     003H
VK_MBUTTON                                      equ     004H

VK_BACK                                         equ     008H
VK_TAB                                          equ     009H

VK_CLEAR                                        equ     00CH
VK_RETURN                                       equ     00DH

VK_SHIFT                                        equ     010H
VK_CONTROL                                      equ     011H
VK_MENU                                         equ     012H
VK_PAUSE                                        equ     013H
VK_CAPITAL                                      equ     014H

VK_KANA                                         equ     015H
VK_HANGEUL                                      equ     015H
VK_HANGUL                                       equ     015H
VK_JUNJA                                        equ     017H
VK_FINAL                                        equ     018H
VK_HANJA                                        equ     019H
VK_KANJI                                        equ     019H

VK_ESCAPE                                       equ     01BH

VK_CONVERT                                      equ     01CH
VK_NONCONVERT                                   equ     01DH
VK_ACCEPT                                       equ     01EH
VK_MODECHANGE                                   equ     01FH

VK_SPACE                                        equ     020H
VK_PRIOR                                        equ     021H
VK_NEXT                                         equ     022H
VK_END                                          equ     023H
VK_HOME                                         equ     024H
VK_LEFT                                         equ     025H
VK_UP                                           equ     026H
VK_RIGHT                                        equ     027H
VK_DOWN                                         equ     028H
VK_SELECT                                       equ     029H
VK_PRINT                                        equ     02AH
VK_EXECUTE                                      equ     02BH
VK_SNAPSHOT                                     equ     02CH
VK_INSERT                                       equ     02DH
VK_DELETE                                       equ     02EH
VK_HELP                                         equ     02FH

VK_LWIN                                         equ     05BH
VK_RWIN                                         equ     05CH
VK_APPS                                         equ     05DH
VK_SLEEP                                        equ     05FH

VK_NUMPAD0                                      equ     060H
VK_NUMPAD1                                      equ     061H
VK_NUMPAD2                                      equ     062H
VK_NUMPAD3                                      equ     063H
VK_NUMPAD4                                      equ     064H
VK_NUMPAD5                                      equ     065H
VK_NUMPAD6                                      equ     066H
VK_NUMPAD7                                      equ     067H
VK_NUMPAD8                                      equ     068H
VK_NUMPAD9                                      equ     069H
VK_MULTIPLY                                     equ     06AH
VK_ADD                                          equ     06BH
VK_SEPARATOR                                    equ     06CH
VK_SUBTRACT                                     equ     06DH
VK_DECIMAL                                      equ     06EH
VK_DIVIDE                                       equ     06FH
VK_F1                                           equ     070H
VK_F2                                           equ     071H
VK_F3                                           equ     072H
VK_F4                                           equ     073H
VK_F5                                           equ     074H
VK_F6                                           equ     075H
VK_F7                                           equ     076H
VK_F8                                           equ     077H
VK_F9                                           equ     078H
VK_F10                                          equ     079H
VK_F11                                          equ     07AH
VK_F12                                          equ     07BH
VK_F13                                          equ     07CH
VK_F14                                          equ     07DH
VK_F15                                          equ     07EH
VK_F16                                          equ     07FH
VK_F17                                          equ     080H
VK_F18                                          equ     081H
VK_F19                                          equ     082H
VK_F20                                          equ     083H
VK_F21                                          equ     084H
VK_F22                                          equ     085H
VK_F23                                          equ     086H
VK_F24                                          equ     087H

VK_NUMLOCK                                      equ     090H
VK_SCROLL                                       equ     091H
VK_OEM_NEC_EQUAL                                equ     092H
VK_OEM_FJ_JISHO                                 equ     092H
VK_OEM_FJ_MASSHOU                               equ     093H
VK_OEM_FJ_TOUROKU                               equ     094H
VK_OEM_FJ_LOYA                                  equ     095H
VK_OEM_FJ_ROYA                                  equ     096H

VK_LSHIFT                                       equ     0A0H
VK_RSHIFT                                       equ     0A1H
VK_LCONTROL                                     equ     0A2H
VK_RCONTROL                                     equ     0A3H
VK_LMENU                                        equ     0A4H
VK_RMENU                                        equ     0A5H
VK_BROWSER_BACK                                 equ     0A6H
VK_BROWSER_FORWARD                              equ     0A7H
VK_BROWSER_REFRESH                              equ     0A8H
VK_BROWSER_STOP                                 equ     0A9H
VK_BROWSER_SEARCH                               equ     0AAH
VK_BROWSER_FAVORITES                            equ     0ABH
VK_BROWSER_HOME                                 equ     0ACH
VK_VOLUME_MUTE                                  equ     0ADH
VK_VOLUME_DOWN                                  equ     0AEH
VK_VOLUME_UP                                    equ     0AFH

VK_MEDIA_NEXT_TRACK                             equ     0B0H
VK_MEDIA_PREV_TRACK                             equ     0B1H
VK_MEDIA_STOP                                   equ     0B2H
VK_MEDIA_PLAY_PAUSE                             equ     0B3H
VK_LAUNCH_MAIL                                  equ     0B4H
VK_LAUNCH_MEDIA_SELECT                          equ     0B5H
VK_LAUNCH_APP1                                  equ     0B6H
VK_LAUNCH_APP2                                  equ     0B7H

VK_OEM_1                                        equ     0BAH
VK_OEM_PLUS                                     equ     0BBH
VK_OEM_COMMA                                    equ     0BCH
VK_OEM_MINUS                                    equ     0BDH
VK_OEM_PERIOD                                   equ     0BEH
VK_OEM_2                                        equ     0BFH
VK_OEM_3                                        equ     0C0H
VK_OEM_4                                        equ     0DBH
VK_OEM_5                                        equ     0DCH
VK_OEM_6                                        equ     0DDH
VK_OEM_7                                        equ     0DEH
VK_OEM_8                                        equ     0DFH

VK_OEM_AX                                       equ     0E1H
VK_OEM_102                                      equ     0E2H
VK_ICO_HELP                                     equ     0E3H
VK_ICO_00                                       equ     0E4H
VK_PROCESSKEY                                   equ     0E5H
VK_ICO_CLEAR                                    equ     0E6H
VK_PACKET                                       equ     0E7H
VK_OEM_RESET                                    equ     0E9H
VK_OEM_JUMP                                     equ     0EAH
VK_OEM_PA1                                      equ     0EBH
VK_OEM_PA2                                      equ     0ECH
VK_OEM_PA3                                      equ     0EDH
VK_OEM_WSCTRL                                   equ     0EEH
VK_OEM_CUSEL                                    equ     0EFH

VK_OEM_ATTN                                     equ     0F0H
VK_OEM_FINISH                                   equ     0F1H
VK_OEM_COPY                                     equ     0F2H
VK_OEM_AUTO                                     equ     0F3H
VK_OEM_ENLW                                     equ     0F4H
VK_OEM_BACKTAB                                  equ     0F5H
VK_ATTN                                         equ     0F6H
VK_CRSEL                                        equ     0F7H
VK_EXSEL                                        equ     0F8H
VK_EREOF                                        equ     0F9H
VK_PLAY                                         equ     0FAH
VK_ZOOM                                         equ     0FBH
VK_NONAME                                       equ     0FCH
VK_PA1                                          equ     0FDH
VK_OEM_CLEAR                                    equ     0FEH

WH_MIN                                          equ     (-1)
WH_MSGFILTER                                    equ     (-1)
WH_JOURNALRECORD                                equ     0
WH_JOURNALPLAYBACK                              equ     1
WH_KEYBOARD                                     equ     2
WH_GETMESSAGE                                   equ     3
WH_CALLWNDPROC                                  equ     4
WH_CBT                                          equ     5
WH_SYSMSGFILTER                                 equ     6
WH_MOUSE                                        equ     7
WH_HARDWARE                                     equ     8
WH_DEBUG                                        equ     9
WH_SHELL                                        equ     10
WH_FOREGROUNDIDLE                               equ     11
WH_CALLWNDPROCRET                               equ     12

WH_KEYBOARD_LL                                  equ     13
WH_MOUSE_LL                                     equ     14

#if NTDDI_VERSION == NTDDI_WINNT4
    WH_MAX                                      equ     14
#else
    WH_MAX                                      equ     12
#endif

WH_MINHOOK                                      equ     WH_MIN
WH_MAXHOOK                                      equ     WH_MAX

HC_ACTION                                       equ     0
HC_GETNEXT                                      equ     1
HC_SKIP                                         equ     2
HC_NOREMOVE                                     equ     3
HC_NOREM                                        equ     HC_NOREMOVE
HC_SYSMODALON                                   equ     4
HC_SYSMODALOFF                                  equ     5

HCBT_MOVESIZE                                   equ     0
HCBT_MINMAX                                     equ     1
HCBT_QS                                         equ     2
HCBT_CREATEWND                                  equ     3
HCBT_DESTROYWND                                 equ     4
HCBT_ACTIVATE                                   equ     5
HCBT_CLICKSKIPPED                               equ     6
HCBT_KEYSKIPPED                                 equ     7
HCBT_SYSCOMMAND                                 equ     8
HCBT_SETFOCUS                                   equ     9

MSGF_DIALOGBOX                                  equ     0
MSGF_MESSAGEBOX                                 equ     1
MSGF_MENU                                       equ     2
MSGF_SCROLLBAR                                  equ     5
MSGF_NEXTWINDOW                                 equ     6
MSGF_MAX                                        equ     8
MSGF_USER                                       equ     4096

HSHELL_WINDOWCREATED                            equ     1
HSHELL_WINDOWDESTROYED                          equ     2
HSHELL_ACTIVATESHELLWINDOW                      equ     3

HSHELL_WINDOWACTIVATED                          equ     4
HSHELL_GETMINRECT                               equ     5
HSHELL_REDRAW                                   equ     6
HSHELL_TASKMAN                                  equ     7
HSHELL_LANGUAGE                                 equ     8
HSHELL_ACCESSIBILITYSTATE                       equ     11
HSHELL_APPCOMMAND                               equ     12
HSHELL_WINDOWREPLACED                           equ     13
HSHELL_WINDOWREPLACING                          equ     14
HSHELL_MONITORCHANGED                           equ     16
HSHELL_HIGHBIT                                  equ     08000H
HSHELL_FLASH                                    equ     <HSHELL_REDRAW or HSHELL_HIGHBIT>
HSHELL_RUDEAPPACTIVATED                         equ     <HSHELL_WINDOWACTIVATED or HSHELL_HIGHBIT>

ACCESS_STICKYKEYS                               equ     00001H
ACCESS_FILTERKEYS                               equ     00002H
ACCESS_MOUSEKEYS                                equ     00003H

APPCOMMAND_BROWSER_BACKWARD                     equ     1
APPCOMMAND_BROWSER_FORWARD                      equ     2
APPCOMMAND_BROWSER_REFRESH                      equ     3
APPCOMMAND_BROWSER_STOP                         equ     4
APPCOMMAND_BROWSER_SEARCH                       equ     5
APPCOMMAND_BROWSER_FAVORITES                    equ     6
APPCOMMAND_BROWSER_HOME                         equ     7
APPCOMMAND_VOLUME_MUTE                          equ     8
APPCOMMAND_VOLUME_DOWN                          equ     9
APPCOMMAND_VOLUME_UP                            equ     10
APPCOMMAND_MEDIA_NEXTTRACK                      equ     11
APPCOMMAND_MEDIA_PREVIOUSTRACK                  equ     12
APPCOMMAND_MEDIA_STOP                           equ     13
APPCOMMAND_MEDIA_PLAY_PAUSE                     equ     14
APPCOMMAND_LAUNCH_MAIL                          equ     15
APPCOMMAND_LAUNCH_MEDIA_SELECT                  equ     16
APPCOMMAND_LAUNCH_APP1                          equ     17
APPCOMMAND_LAUNCH_APP2                          equ     18
APPCOMMAND_BASS_DOWN                            equ     19
APPCOMMAND_BASS_BOOST                           equ     20
APPCOMMAND_BASS_UP                              equ     21
APPCOMMAND_TREBLE_DOWN                          equ     22
APPCOMMAND_TREBLE_UP                            equ     23
APPCOMMAND_MICROPHONE_VOLUME_MUTE               equ     24
APPCOMMAND_MICROPHONE_VOLUME_DOWN               equ     25
APPCOMMAND_MICROPHONE_VOLUME_UP                 equ     26
APPCOMMAND_HELP                                 equ     27
APPCOMMAND_FIND                                 equ     28
APPCOMMAND_NEW                                  equ     29
APPCOMMAND_OPEN                                 equ     30
APPCOMMAND_CLOSE                                equ     31
APPCOMMAND_SAVE                                 equ     32
APPCOMMAND_PRINT                                equ     33
APPCOMMAND_UNDO                                 equ     34
APPCOMMAND_REDO                                 equ     35
APPCOMMAND_COPY                                 equ     36
APPCOMMAND_CUT                                  equ     37
APPCOMMAND_PASTE                                equ     38
APPCOMMAND_REPLY_TO_MAIL                        equ     39
APPCOMMAND_FORWARD_MAIL                         equ     40
APPCOMMAND_SEND_MAIL                            equ     41
APPCOMMAND_SPELL_CHECK                          equ     42
APPCOMMAND_DICTATE_OR_COMMAND_CONTROL_TOGGLE        equ     43
APPCOMMAND_MIC_ON_OFF_TOGGLE                    equ     44
APPCOMMAND_CORRECTION_LIST                      equ     45
APPCOMMAND_MEDIA_PLAY                           equ     46
APPCOMMAND_MEDIA_PAUSE                          equ     47
APPCOMMAND_MEDIA_RECORD                         equ     48
APPCOMMAND_MEDIA_FAST_FORWARD                   equ     49
APPCOMMAND_MEDIA_REWIND                         equ     50
APPCOMMAND_MEDIA_CHANNEL_UP                     equ     51
APPCOMMAND_MEDIA_CHANNEL_DOWN                   equ     52
APPCOMMAND_DELETE                               equ     53
APPCOMMAND_DWM_FLIP3D                           equ     54

FAPPCOMMAND_MOUSE                               equ     08000H
FAPPCOMMAND_KEY                                 equ     0
FAPPCOMMAND_OEM                                 equ     01000H
FAPPCOMMAND_MASK                                equ     0F000H

LLKHF_EXTENDED                                  equ     000000001H
LLKHF_INJECTED                                  equ     000000010H
LLKHF_ALTDOWN                                   equ     000000020H
LLKHF_UP                                        equ     000000080H

LLMHF_INJECTED                                  equ     000000001H

HKL_PREV                                        equ     0
HKL_NEXT                                        equ     1

KLF_ACTIVATE                                    equ     000000001H
KLF_SUBSTITUTE_OK                               equ     000000002H
KLF_UNLOADPREVIOUS                              equ     000000004H
KLF_REORDER                                     equ     000000008H
KLF_REPLACELANG                                 equ     000000010H
KLF_NOTELLSHELL                                 equ     000000080H
KLF_SETFORPROCESS                               equ     000000100H
KLF_SHIFTLOCK                                   equ     000010000H
KLF_RESET                                       equ     040000000H

INPUTLANGCHANGE_SYSCHARSET                      equ     00001H
INPUTLANGCHANGE_FORWARD                         equ     00002H
INPUTLANGCHANGE_BACKWARD                        equ     00004H

KL_NAMELENGTH                                   equ     9

GMMP_USE_DISPLAY_POINTS                         equ     1
GMMP_USE_DRIVER_POINTS                          equ     2

DESKTOP_READOBJECTS                             equ     00001H
DESKTOP_CREATEWINDOW                            equ     00002H
DESKTOP_CREATEMENU                              equ     00004H
DESKTOP_HOOKCONTROL                             equ     00008H
DESKTOP_JOURNALRECORD                           equ     00010H
DESKTOP_JOURNALPLAYBACK                         equ     00020H
DESKTOP_ENUMERATE                               equ     00040H
DESKTOP_WRITEOBJECTS                            equ     00080H
DESKTOP_SWITCHDESKTOP                           equ     00100H

DF_ALLOWOTHERACCOUNTHOOK                        equ     00001H

WINSTA_ENUMDESKTOPS                             equ     00001H
WINSTA_READATTRIBUTES                           equ     00002H
WINSTA_ACCESSCLIPBOARD                          equ     00004H
WINSTA_CREATEDESKTOP                            equ     00008H
WINSTA_WRITEATTRIBUTES                          equ     00010H
WINSTA_ACCESSGLOBALATOMS                        equ     00020H
WINSTA_EXITWINDOWS                              equ     00040H
WINSTA_ENUMERATE                                equ     00100H
WINSTA_READSCREEN                               equ     00200H
WINSTA_ALL_ACCESS                               equ     <WINSTA_ENUMDESKTOPS or WINSTA_READATTRIBUTES or WINSTA_ACCESSCLIPBOARD or WINSTA_CREATEDESKTOP or WINSTA_WRITEATTRIBUTES or WINSTA_ACCESSGLOBALATOMS or WINSTA_EXITWINDOWS or WINSTA_ENUMERATE or WINSTA_READSCREEN>

CWF_CREATE_ONLY                                 equ     00000001H

WSF_VISIBLE                                     equ     0001H

UOI_FLAGS                                       equ     1
UOI_NAME                                        equ     2
UOI_TYPE                                        equ     3
UOI_USER_SID                                    equ     4

GWL_WNDPROC                                     equ     (-4)
GWL_HINSTANCE                                   equ     (-6)
GWL_HWNDPARENT                                  equ     (-8)
GWL_STYLE                                       equ     (-16)
GWL_EXSTYLE                                     equ     (-20)
GWL_USERDATA                                    equ     (-21)
GWL_ID                                          equ     (-12)

GWLP_WNDPROC                                    equ     (-4)
GWLP_HINSTANCE                                  equ     (-6)
GWLP_HWNDPARENT                                 equ     (-8)
GWLP_USERDATA                                   equ     (-21)
GWLP_ID                                         equ     (-12)

GCL_MENUNAME                                    equ     (-8)
GCL_HBRBACKGROUND                               equ     (-10)
GCL_HCURSOR                                     equ     (-12)
GCL_HICON                                       equ     (-14)
GCL_HMODULE                                     equ     (-16)
GCL_CBWNDEXTRA                                  equ     (-18)
GCL_CBCLSEXTRA                                  equ     (-20)
GCL_WNDPROC                                     equ     (-24)
GCL_STYLE                                       equ     (-26)
GCW_ATOM                                        equ     (-32)

GCLP_MENUNAME                                   equ     (-8)
GCLP_HBRBACKGROUND                              equ     (-10)
GCLP_HCURSOR                                    equ     (-12)
GCLP_HICON                                      equ     (-14)
GCLP_HMODULE                                    equ     (-16)
GCLP_WNDPROC                                    equ     (-24)
GCLP_HICONSM                                    equ     (-34)

WA_INACTIVE                                     equ     0
WA_ACTIVE                                       equ     1
WA_CLICKACTIVE                                  equ     2

WM_NULL                                         equ     00000H
WM_CREATE                                       equ     00001H
WM_DESTROY                                      equ     00002H
WM_MOVE                                         equ     00003H
WM_SIZE                                         equ     00005H
WM_ACTIVATE                                     equ     00006H
WM_SETFOCUS                                     equ     00007H
WM_KILLFOCUS                                    equ     00008H
WM_ENABLE                                       equ     0000AH
WM_SETREDRAW                                    equ     0000BH
WM_SETTEXT                                      equ     0000CH
WM_GETTEXT                                      equ     0000DH
WM_GETTEXTLENGTH                                equ     0000EH
WM_PAINT                                        equ     0000FH

WM_CLOSE                                        equ     00010H
WM_QUERYENDSESSION                              equ     00011H
WM_QUIT                                         equ     00012H
WM_QUERYOPEN                                    equ     00013H
WM_ERASEBKGND                                   equ     00014H
WM_SYSCOLORCHANGE                               equ     00015H
WM_ENDSESSION                                   equ     00016H
WM_SHOWWINDOW                                   equ     00018H
WM_WININICHANGE                                 equ     0001AH
WM_SETTINGCHANGE                                equ     WM_WININICHANGE
WM_DEVMODECHANGE                                equ     0001BH
WM_ACTIVATEAPP                                  equ     0001CH
WM_FONTCHANGE                                   equ     0001DH
WM_TIMECHANGE                                   equ     0001EH
WM_CANCELMODE                                   equ     0001FH

WM_SETCURSOR                                    equ     00020H
WM_MOUSEACTIVATE                                equ     00021H
WM_CHILDACTIVATE                                equ     00022H
WM_QUEUESYNC                                    equ     00023H
WM_GETMINMAXINFO                                equ     00024H
WM_PAINTICON                                    equ     00026H
WM_ICONERASEBKGND                               equ     00027H
WM_NEXTDLGCTL                                   equ     00028H
WM_SPOOLERSTATUS                                equ     0002AH
WM_DRAWITEM                                     equ     0002BH
WM_MEASUREITEM                                  equ     0002CH
WM_DELETEITEM                                   equ     0002DH
WM_VKEYTOITEM                                   equ     0002EH
WM_CHARTOITEM                                   equ     0002FH

WM_SETFONT                                      equ     00030H
WM_GETFONT                                      equ     00031H
WM_SETHOTKEY                                    equ     00032H
WM_GETHOTKEY                                    equ     00033H
WM_QUERYDRAGICON                                equ     00037H
WM_COMPAREITEM                                  equ     00039H
WM_GETOBJECT                                    equ     0003DH

WM_COMPACTING                                   equ     00041H
WM_COMMNOTIFY                                   equ     00044H
WM_WINDOWPOSCHANGING                            equ     00046H
WM_WINDOWPOSCHANGED                             equ     00047H
WM_POWER                                        equ     00048H
WM_COPYGLOBALDATA                               equ     00049H
WM_COPYDATA                                     equ     0004AH
WM_CANCELJOURNAL                                equ     0004BH
WM_LOGONNOTIFY                                  equ     0004CH
WM_KEYF1                                        equ     0004DH
WM_NOTIFY                                       equ     0004EH
WM_ACCESS_WINDOW                                equ     0004FH

WM_INPUTLANGCHANGEREQUEST                       equ     00050H
WM_INPUTLANGCHANGE                              equ     00051H
WM_TCARD                                        equ     00052H
WM_HELP                                         equ     00053H
WM_USERCHANGED                                  equ     00054H
WM_NOTIFYFORMAT                                 equ     00055H

WM_QM_ACTIVATE                                  equ     00060H
WM_HOOK_DO_CALLBACK                             equ     00061H
WM_SYSCOPYDATA                                  equ     00062H

WM_FINALDESTROY                                 equ     00070H
WM_MEASUREITEM_CLIENTDATA                       equ     00071H
WM_CONTEXTMENU                                  equ     0007BH
WM_STYLECHANGING                                equ     0007CH
WM_STYLECHANGED                                 equ     0007DH
WM_DISPLAYCHANGE                                equ     0007EH
WM_GETICON                                      equ     0007FH

WM_SETICON                                      equ     00080H
WM_NCCREATE                                     equ     00081H
WM_NCDESTROY                                    equ     00082H
WM_NCCALCSIZE                                   equ     00083H
WM_NCHITTEST                                    equ     00084H
WM_NCPAINT                                      equ     00085H
WM_NCACTIVATE                                   equ     00086H
WM_GETDLGCODE                                   equ     00087H
WM_SYNCPAINT                                    equ     00088H
WM_SYNCTASK                                     equ     00089H
WM_KLUDGEMINRECT                                equ     0008BH
WM_LPKDRAWSWITCHWND                             equ     0008CH

WM_UAHDESTROYWINDOW                             equ     00090H
WM_UAHDRAWMENU                                  equ     00091H
WM_UAHDRAWMENUITEM                              equ     00092H
WM_UAHINITMENU                                  equ     00093H
WM_UAHMEASUREMENUITEM                           equ     00094H
WM_UAHNCPAINTMENUPOPUP                          equ     00095H

WM_NCMOUSEMOVE                                  equ     000A0H
WM_NCLBUTTONDOWN                                equ     000A1H
WM_NCLBUTTONUP                                  equ     000A2H
WM_NCLBUTTONDBLCLK                              equ     000A3H
WM_NCRBUTTONDOWN                                equ     000A4H
WM_NCRBUTTONUP                                  equ     000A5H
WM_NCRBUTTONDBLCLK                              equ     000A6H
WM_NCMBUTTONDOWN                                equ     000A7H
WM_NCMBUTTONUP                                  equ     000A8H
WM_NCMBUTTONDBLCLK                              equ     000A9H
WM_NCXBUTTONDOWN                                equ     000ABH
WM_NCXBUTTONUP                                  equ     000ACH
WM_NCXBUTTONDBLCLK                              equ     000ADH
WM_NCUAHDRAWCAPTION                             equ     000AEH
WM_NCUAHDRAWFRAME                               equ     000AFH

PWR_OK                                          equ     1
PWR_FAIL                                        equ     (-1)
PWR_SUSPENDREQUEST                              equ     1
PWR_SUSPENDRESUME                               equ     2
PWR_CRITICALRESUME                              equ     3

NFR_ANSI                                        equ     1
NFR_UNICODE                                     equ     2
NF_QUERY                                        equ     3
NF_REQUERY                                      equ     4

WM_KEYFIRST                                     equ     00100H
WM_KEYDOWN                                      equ     00100H
WM_KEYUP                                        equ     00101H
WM_CHAR                                         equ     00102H
WM_DEADCHAR                                     equ     00103H
WM_SYSKEYDOWN                                   equ     00104H
WM_SYSKEYUP                                     equ     00105H
WM_SYSCHAR                                      equ     00106H
WM_SYSDEADCHAR                                  equ     00107H
WM_KEYLAST                                      equ     00108H
WM_UNICHAR                                      equ     00109H
WM_CONVERTREQUEST                               equ     0010AH
WM_CONVERTRESULT                                equ     0010BH
WM_IM_INFO                                      equ     0010CH
WM_IME_STARTCOMPOSITION                         equ     0010DH
WM_IME_ENDCOMPOSITION                           equ     0010EH
WM_IME_COMPOSITION                              equ     0010FH
WM_IME_KEYLAST                                  equ     0010FH

WM_INITDIALOG                                   equ     00110H
WM_COMMAND                                      equ     00111H
WM_SYSCOMMAND                                   equ     00112H
WM_TIMER                                        equ     00113H
WM_HSCROLL                                      equ     00114H
WM_VSCROLL                                      equ     00115H
WM_INITMENU                                     equ     00116H
WM_INITMENUPOPUP                                equ     00117H
WM_SYSTIMER                                     equ     00118H
WM_GESTURE                                      equ     00119H
WM_GESTURENOTIFY                                equ     0011AH
WM_GESTUREINPUT                                 equ     0011BH
WM_GESTURENOTIFIED                              equ     0011CH
WM_MENUSELECT                                   equ     0011FH

WM_MENUCHAR                                     equ     00120H
WM_ENTERIDLE                                    equ     00121H
WM_MENURBUTTONUP                                equ     00122H
WM_MENUDRAG                                     equ     00123H
WM_MENUGETOBJECT                                equ     00124H
WM_UNINITMENUPOPUP                              equ     00125H
WM_MENUCOMMAND                                  equ     00126H
WM_CHANGEUISTATE                                equ     00127H
WM_UPDATEUISTATE                                equ     00128H
WM_QUERYUISTATE                                 equ     00129H

WM_LBTRACKPOINT                                 equ     00131H
WM_CTLCOLORMSGBOX                               equ     00132H
WM_CTLCOLOREDIT                                 equ     00133H
WM_CTLCOLORLISTBOX                              equ     00134H
WM_CTLCOLORBTN                                  equ     00135H
WM_CTLCOLORDLG                                  equ     00136H
WM_CTLCOLORSCROLLBAR                            equ     00137H
WM_CTLCOLORSTATIC                               equ     00138H

WM_MOUSEFIRST                                   equ     00200H
WM_MOUSEMOVE                                    equ     00200H
WM_LBUTTONDOWN                                  equ     00201H
WM_LBUTTONUP                                    equ     00202H
WM_LBUTTONDBLCLK                                equ     00203H
WM_RBUTTONDOWN                                  equ     00204H
WM_RBUTTONUP                                    equ     00205H
WM_RBUTTONDBLCLK                                equ     00206H
WM_MBUTTONDOWN                                  equ     00207H
WM_MBUTTONUP                                    equ     00208H
WM_MBUTTONDBLCLK                                equ     00209H
WM_MOUSEWHEEL                                   equ     0020AH
WM_XBUTTONDOWN                                  equ     0020BH
WM_XBUTTONUP                                    equ     0020CH
WM_XBUTTONDBLCLK                                equ     0020DH
WM_MOUSEHWHEEL                                  equ     0020EH
WM_MOUSELAST                                    equ     0020EH

WM_PARENTNOTIFY                                 equ     00210H
WM_ENTERMENULOOP                                equ     00211H
WM_EXITMENULOOP                                 equ     00212H
WM_NEXTMENU                                     equ     00213H
WM_SIZING                                       equ     00214H
WM_CAPTURECHANGED                               equ     00215H
WM_MOVING                                       equ     00216H
WM_POWERBROADCAST                               equ     00218H
WM_DEVICECHANGE                                 equ     00219H

WM_MDICREATE                                    equ     00220H
WM_MDIDESTROY                                   equ     00221H
WM_MDIACTIVATE                                  equ     00222H
WM_MDIRESTORE                                   equ     00223H
WM_MDINEXT                                      equ     00224H
WM_MDIMAXIMIZE                                  equ     00225H
WM_MDITILE                                      equ     00226H
WM_MDICASCADE                                   equ     00227H
WM_MDIICONARRANGE                               equ     00228H
WM_MDIGETACTIVE                                 equ     00229H

WM_MDISETMENU                                   equ     00230H
WM_ENTERSIZEMOVE                                equ     00231H
WM_EXITSIZEMOVE                                 equ     00232H
WM_DROPFILES                                    equ     00233H
WM_MDIREFRESHMENU                               equ     00234H
WM_POINTERDEVICECHANGE                          equ     00238H
WM_POINTERDEVICEINRANGE                         equ     00239H
WM_POINTERDEVICEOUTOFRANGE                      equ     0023AH

WM_TOUCH                                        equ     00240H
WM_NCPOINTERUPDATE                              equ     00241H
WM_NCPOINTERDOWN                                equ     00242H
WM_NCPOINTERUP                                  equ     00243H
WM_NCPOINTERCANCEL                              equ     00244H
WM_POINTERUPDATE                                equ     00245H
WM_POINTERDOWN                                  equ     00246H
WM_POINTERUP                                    equ     00247H
WM_POINTERCANCEL                                equ     00248H
WM_POINTERENTER                                 equ     00249H
WM_POINTERLEAVE                                 equ     0024AH
WM_POINTERACTIVATE                              equ     0024BH
WM_POINTERCAPTURECHANGED                        equ     0024CH
WM_TOUCHHITTESTING                              equ     0024DH
WM_POINTERWHEEL                                 equ     0024EH
WM_POINTERHWHEEL                                equ     0024FH
WM_TOUCHLAST                                    equ     0024FH

WM_KANJIFIRST                                   equ     00280H
WM_IME_SETCONTEXT                               equ     00281H
WM_IME_NOTIFY                                   equ     00282H
WM_IME_CONTROL                                  equ     00283H
WM_IME_COMPOSITIONFULL                          equ     00284H
WM_IME_SELECT                                   equ     00285H
WM_IME_CHAR                                     equ     00286H
WM_IME_SYSTEM                                   equ     00287H
WM_IME_REQUEST                                  equ     00288H

WM_IME_KEYDOWN                                  equ     00290H
WM_IME_KEYUP                                    equ     00291H
WM_KANJILAST                                    equ     0029FH

WM_NCMOUSEHOVER                                 equ     002A0H
WM_NCMOUSELEAVE                                 equ     002A2H
WM_WTSSESSION_CHANGE                            equ     002B1H

WM_DPICHANGED                                   equ     002E0H

WM_CUT                                          equ     00300H
WM_COPY                                         equ     00301H
WM_PASTE                                        equ     00302H
WM_CLEAR                                        equ     00303H
WM_UNDO                                         equ     00304H
WM_RENDERFORMAT                                 equ     00305H
WM_RENDERALLFORMATS                             equ     00306H
WM_DESTROYCLIPBOARD                             equ     00307H
WM_DRAWCLIPBOARD                                equ     00308H
WM_PAINTCLIPBOARD                               equ     00309H
WM_VSCROLLCLIPBOARD                             equ     0030AH
WM_SIZECLIPBOARD                                equ     0030BH
WM_ASKCBFORMATNAME                              equ     0030CH
WM_CHANGECBCHAIN                                equ     0030DH
WM_HSCROLLCLIPBOARD                             equ     0030EH
WM_QUERYNEWPALETTE                              equ     0030FH

WM_PALETTEISCHANGING                            equ     00310H
WM_PALETTECHANGED                               equ     00311H
WM_HOTKEY                                       equ     00312H
WM_SYSMENU                                      equ     00313H
WM_HOOKMSG                                      equ     00314H
WM_EXITPROCESS                                  equ     00315H
WM_WAKETHREAD                                   equ     00316H
WM_PRINT                                        equ     00317H
WM_PRINTCLIENT                                  equ     00318H
WM_APPCOMMAND                                   equ     00319H
WM_THEMECHANGED                                 equ     0031AH
WM_UAHINIT                                      equ     0031BH
WM_DESKTOPNOTIFY                                equ     0031CH
WM_CLIPBOARDUPDATE                              equ     0031DH
WM_DWMCOMPOSITIONCHANGED                        equ     0031EH
WM_DWMNCRENDERINGCHANGED                        equ     0031FH

WM_DWMCOLORIZATIONCOLORCHANGED                  equ     00320H
WM_DWMWINDOWMAXIMIZEDCHANGE                     equ     00321H
WM_DWMEXILEFRAME                                equ     00322H
WM_DWMSENDICONICTHUMBNAIL                       equ     00323H
WM_DWMSENDICONICLIVEPREVIEWBITMAP               equ     00326H
WM_DWMTHUMBNAILSIZECHANGED                      equ     00327H
WM_MAGNIFICATION_OUTPUT                         equ     00328H

WM_MEASURECONTROL                               equ     00330H
WM_GETACTIONTEXT                                equ     00331H
WM_FORWARDKEYDOWN                               equ     00333H
WM_FORWARDKEYUP                                 equ     00334H
WM_GETTITLEBARINFOEX                            equ     0033FH

WM_NOTIFYWOW                                    equ     00340H

WM_HANDHELDFIRST                                equ     00358H
WM_HANDHELDLAST                                 equ     0035FH

WM_AFXFIRST                                     equ     00360H
WM_AFXLAST                                      equ     0037FH

WM_PENWINFIRST                                  equ     00380H
WM_PENWINLAST                                   equ     0038FH

WM_COALESCE_FIRST                               equ     00390H
WM_COALESCE_LAST                                equ     0039FH

WM_MM_RESERVED_FIRST                            equ     003A0H

WM_MM_RESERVED_LAST                             equ     003DFH

WM_DDE_INITIATE                                 equ     003E0H
WM_DDE_TERMINATE                                equ     003E1H
WM_DDE_ADVISE                                   equ     003E2H
WM_DDE_UNADVISE                                 equ     003E3H
WM_DDE_ACK                                      equ     003E4H
WM_DDE_DATA                                     equ     003E5H
WM_DDE_REQUEST                                  equ     003E6H
WM_DDE_POKE                                     equ     003E7H
WM_DDE_EXECUTE                                  equ     003E8H

WM_DBNOTIFICATION                               equ     003FDH
WM_NETCONNECT                                   equ     003FEH
WM_HIBERNATE                                    equ     003FFH

#ifndef WM_USER
    WM_USER                                     equ     00400H
#endif

WM_APP                                          equ     08000H

WM_GRAPHNOTIFY                                  equ     <WM_APP + 1>

UIS_SET                                         equ     1
UIS_CLEAR                                       equ     2
UIS_INITIALIZE                                  equ     3

UISF_HIDEFOCUS                                  equ     01H
UISF_HIDEACCEL                                  equ     02H

MN_SETHMENU                                     equ     001E0H
MN_GETHMENU                                     equ     001E1H
MN_SIZEWINDOW                                   equ     001E2H
MN_OPENHIERARCHY                                equ     001E3H
MN_CLOSEHIERARCHY                               equ     001E4H
MN_SELECTITEM                                   equ     001E5H
MN_CANCELMENUS                                  equ     001E6H
MN_SELECTFIRSTVALIDITEM                         equ     001E7H
MN_GETPPOPUPMENU                                equ     001EAH
MN_FINDMENUWINDOWFROMPOINT                      equ     001EBH
MN_SHOWPOPUPWINDOW                              equ     001ECH
MN_BUTTONDOWN                                   equ     001EDH
MN_MOUSEMOVE                                    equ     001EEH
MN_BUTTONUP                                     equ     001EFH
MN_SETTIMERTOOPENHIERARCHY                      equ     001F0H
MN_DBLCLK                                       equ     001F1H

WHEEL_DELTA                                     equ     120
WHEEL_PAGESCROLL                                equ     0FFFFFFFFH

XBUTTON1                                        equ     00001H
XBUTTON2                                        equ     00002H

PBT_APMQUERYSUSPEND                             equ     00000H
PBT_APMQUERYSTANDBY                             equ     00001H

PBT_APMQUERYSUSPENDFAILED                       equ     00002H
PBT_APMQUERYSTANDBYFAILED                       equ     00003H

PBT_APMSUSPEND                                  equ     00004H
PBT_APMSTANDBY                                  equ     00005H

PBT_APMRESUMECRITICAL                           equ     00006H
PBT_APMRESUMESUSPEND                            equ     00007H
PBT_APMRESUMESTANDBY                            equ     00008H

PBTF_APMRESUMEFROMFAILURE                       equ     000000001H
PBT_POWERSETTINGCHANGE                          equ     08013H

PBT_APMBATTERYLOW                               equ     00009H
PBT_APMPOWERSTATUSCHANGE                        equ     0000AH

PBT_APMOEMEVENT                                 equ     0000BH
PBT_APMRESUMEAUTOMATIC                          equ     00012H

WMSZ_LEFT                                       equ     1
WMSZ_RIGHT                                      equ     2
WMSZ_TOP                                        equ     3
WMSZ_TOPLEFT                                    equ     4
WMSZ_TOPRIGHT                                   equ     5
WMSZ_BOTTOM                                     equ     6
WMSZ_BOTTOMLEFT                                 equ     7
WMSZ_BOTTOMRIGHT                                equ     8

HTERROR                                         equ     (-2)
HTTRANSPARENT                                   equ     (-1)
HTNOWHERE                                       equ     0
HTCLIENT                                        equ     1
HTCAPTION                                       equ     2
HTSYSMENU                                       equ     3
HTGROWBOX                                       equ     4
HTSIZE                                          equ     HTGROWBOX
HTMENU                                          equ     5
HTHSCROLL                                       equ     6
HTVSCROLL                                       equ     7
HTMINBUTTON                                     equ     8
HTMAXBUTTON                                     equ     9
HTLEFT                                          equ     10
HTRIGHT                                         equ     11
HTTOP                                           equ     12
HTTOPLEFT                                       equ     13
HTTOPRIGHT                                      equ     14
HTBOTTOM                                        equ     15
HTBOTTOMLEFT                                    equ     16
HTBOTTOMRIGHT                                   equ     17
HTBORDER                                        equ     18
HTREDUCE                                        equ     HTMINBUTTON
HTZOOM                                          equ     HTMAXBUTTON
HTSIZEFIRST                                     equ     HTLEFT
HTSIZELAST                                      equ     HTBOTTOMRIGHT
HTOBJECT                                        equ     19
HTCLOSE                                         equ     20
HTHELP                                          equ     21

SMTO_NORMAL                                     equ     00000H
SMTO_BLOCK                                      equ     00001H
SMTO_ABORTIFHUNG                                equ     00002H
SMTO_NOTIMEOUTIFNOTHUNG                         equ     00008H

MA_ACTIVATE                                     equ     1
MA_ACTIVATEANDEAT                               equ     2
MA_NOACTIVATE                                   equ     3
MA_NOACTIVATEANDEAT                             equ     4

ICON_SMALL                                      equ     0
ICON_BIG                                        equ     1

SIZE_RESTORED                                   equ     0
SIZE_MINIMIZED                                  equ     1
SIZE_MAXIMIZED                                  equ     2
SIZE_MAXSHOW                                    equ     3
SIZE_MAXHIDE                                    equ     4

SIZENORMAL                                      equ     SIZE_RESTORED
SIZEICONIC                                      equ     SIZE_MINIMIZED
SIZEFULLSCREEN                                  equ     SIZE_MAXIMIZED
SIZEZOOMSHOW                                    equ     SIZE_MAXSHOW
SIZEZOOMHIDE                                    equ     SIZE_MAXHIDE

WVR_ALIGNTOP                                    equ     00010H
WVR_ALIGNLEFT                                   equ     00020H
WVR_ALIGNBOTTOM                                 equ     00040H
WVR_ALIGNRIGHT                                  equ     00080H
WVR_HREDRAW                                     equ     00100H
WVR_VREDRAW                                     equ     00200H
WVR_REDRAW                                      equ     <WVR_HREDRAW or WVR_VREDRAW>
WVR_VALIDRECTS                                  equ     00400H

MK_LBUTTON                                      equ     00001H
MK_RBUTTON                                      equ     00002H
MK_SHIFT                                        equ     00004H
MK_CONTROL                                      equ     00008H
MK_MBUTTON                                      equ     00010H

WS_OVERLAPPED                                   equ     000000000H
WS_POPUP                                        equ     080000000H
WS_CHILD                                        equ     040000000H
WS_MINIMIZE                                     equ     020000000H
WS_VISIBLE                                      equ     010000000H
WS_DISABLED                                     equ     008000000H
WS_CLIPSIBLINGS                                 equ     004000000H
WS_CLIPCHILDREN                                 equ     002000000H
WS_MAXIMIZE                                     equ     001000000H
WS_CAPTION                                      equ     000C00000H
WS_BORDER                                       equ     000800000H
WS_DLGFRAME                                     equ     000400000H
WS_VSCROLL                                      equ     000200000H
WS_HSCROLL                                      equ     000100000H
WS_SYSMENU                                      equ     000080000H
WS_THICKFRAME                                   equ     000040000H
WS_GROUP                                        equ     000020000H
WS_TABSTOP                                      equ     000010000H

WS_MAXIMIZEBOX                                  equ     000010000H
WS_MINIMIZEBOX                                  equ     000020000H

WS_OVERLAPPEDWINDOW                             equ     <WS_OVERLAPPED or WS_CAPTION or WS_SYSMENU or WS_THICKFRAME or WS_MINIMIZEBOX or WS_MAXIMIZEBOX>

WS_TILED                                        equ     WS_OVERLAPPED
WS_ICONIC                                       equ     WS_MINIMIZE
WS_SIZEBOX                                      equ     WS_THICKFRAME

WS_POPUPWINDOW                                  equ     <WS_POPUP or WS_BORDER or WS_SYSMENU>

WS_CHILDWINDOW                                  equ     WS_CHILD

WS_EX_DLGMODALFRAME                             equ     000000001H
WS_EX_NOPARENTNOTIFY                            equ     000000004H
WS_EX_TOPMOST                                   equ     000000008H
WS_EX_ACCEPTFILES                               equ     000000010H
WS_EX_TRANSPARENT                               equ     000000020H
WS_EX_MDICHILD                                  equ     000000040H
WS_EX_TOOLWINDOW                                equ     000000080H
WS_EX_WINDOWEDGE                                equ     000000100H
WS_EX_CLIENTEDGE                                equ     000000200H
WS_EX_CONTEXTHELP                               equ     000000400H
WS_EX_RIGHT                                     equ     000001000H
WS_EX_LEFT                                      equ     000000000H
WS_EX_RTLREADING                                equ     000002000H
WS_EX_LTRREADING                                equ     000000000H
WS_EX_LEFTSCROLLBAR                             equ     000004000H
WS_EX_RIGHTSCROLLBAR                            equ     000000000H
WS_EX_CONTROLPARENT                             equ     000010000H
WS_EX_STATICEDGE                                equ     000020000H
WS_EX_APPWINDOW                                 equ     000040000H

WS_EX_OVERLAPPEDWINDOW                          equ     <WS_EX_WINDOWEDGE or WS_EX_CLIENTEDGE>
WS_EX_PALETTEWINDOW                             equ     <WS_EX_WINDOWEDGE or WS_EX_TOOLWINDOW or WS_EX_TOPMOST>

WS_EX_NOINHERITLAYOUT                           equ     000100000H
WS_EX_LAYOUTRTL                                 equ     000400000H
WS_EX_LAYERED                                   equ     000080000H
WS_EX_NOACTIVATE                                equ     008000000H
WS_EX_COMPOSITED                                equ     002000000H

CS_VREDRAW                                      equ     00001H
CS_HREDRAW                                      equ     00002H
CS_DBLCLKS                                      equ     00008H
CS_OWNDC                                        equ     00020H
CS_CLASSDC                                      equ     00040H
CS_PARENTDC                                     equ     00080H
CS_NOCLOSE                                      equ     00200H
CS_SAVEBITS                                     equ     00800H
CS_BYTEALIGNCLIENT                              equ     01000H
CS_BYTEALIGNWINDOW                              equ     02000H
CS_GLOBALCLASS                                  equ     04000H

CS_IME                                          equ     000010000H
CS_DROPSHADOW                                   equ     000020000H

PRF_CHECKVISIBLE                                equ     000000001H
PRF_NONCLIENT                                   equ     000000002H
PRF_CLIENT                                      equ     000000004H
PRF_ERASEBKGND                                  equ     000000008H
PRF_CHILDREN                                    equ     000000010H
PRF_OWNED                                       equ     000000020H

BDR_RAISEDOUTER                                 equ     00001H
BDR_SUNKENOUTER                                 equ     00002H
BDR_RAISEDINNER                                 equ     00004H
BDR_SUNKENINNER                                 equ     00008H

BDR_OUTER                                       equ     00003H
BDR_INNER                                       equ     0000CH
BDR_RAISED                                      equ     <BDR_RAISEDOUTER or BDR_RAISEDINNER>
BDR_SUNKEN                                      equ     <BDR_SUNKENOUTER or BDR_SUNKENINNER>

EDGE_RAISED                                     equ     <BDR_RAISEDOUTER or BDR_RAISEDINNER>
EDGE_SUNKEN                                     equ     <BDR_SUNKENOUTER or BDR_SUNKENINNER>
EDGE_ETCHED                                     equ     <BDR_SUNKENOUTER or BDR_RAISEDINNER>
EDGE_BUMP                                       equ     <BDR_RAISEDOUTER or BDR_SUNKENINNER>

BF_LEFT                                         equ     00001H
BF_TOP                                          equ     00002H
BF_RIGHT                                        equ     00004H
BF_BOTTOM                                       equ     00008H

BF_TOPLEFT                                      equ     <BF_TOP or BF_LEFT>
BF_TOPRIGHT                                     equ     <BF_TOP or BF_RIGHT>
BF_BOTTOMLEFT                                   equ     <BF_BOTTOM or BF_LEFT>
BF_BOTTOMRIGHT                                  equ     <BF_BOTTOM or BF_RIGHT>
BF_RECT                                         equ     <BF_LEFT or BF_TOP or BF_RIGHT or BF_BOTTOM>

BF_DIAGONAL                                     equ     00010H

BF_DIAGONAL_ENDTOPRIGHT                         equ     <BF_DIAGONAL or BF_TOP or BF_RIGHT>
BF_DIAGONAL_ENDTOPLEFT                          equ     <BF_DIAGONAL or BF_TOP or BF_LEFT>
BF_DIAGONAL_ENDBOTTOMLEFT                       equ     <BF_DIAGONAL or BF_BOTTOM or BF_LEFT>
BF_DIAGONAL_ENDBOTTOMRIGHT                      equ     <BF_DIAGONAL or BF_BOTTOM or BF_RIGHT>

BF_MIDDLE                                       equ     00800H
BF_SOFT                                         equ     01000H
BF_ADJUST                                       equ     02000H
BF_FLAT                                         equ     04000H
BF_MONO                                         equ     08000H

DFC_CAPTION                                     equ     1
DFC_MENU                                        equ     2
DFC_SCROLL                                      equ     3
DFC_BUTTON                                      equ     4
DFC_POPUPMENU                                   equ     5

DFCS_CAPTIONCLOSE                               equ     00000H
DFCS_CAPTIONMIN                                 equ     00001H
DFCS_CAPTIONMAX                                 equ     00002H
DFCS_CAPTIONRESTORE                             equ     00003H
DFCS_CAPTIONHELP                                equ     00004H

DFCS_MENUARROW                                  equ     00000H
DFCS_MENUCHECK                                  equ     00001H
DFCS_MENUBULLET                                 equ     00002H
DFCS_MENUARROWRIGHT                             equ     00004H
DFCS_SCROLLUP                                   equ     00000H
DFCS_SCROLLDOWN                                 equ     00001H
DFCS_SCROLLLEFT                                 equ     00002H
DFCS_SCROLLRIGHT                                equ     00003H
DFCS_SCROLLCOMBOBOX                             equ     00005H
DFCS_SCROLLSIZEGRIP                             equ     00008H
DFCS_SCROLLSIZEGRIPRIGHT                        equ     00010H

DFCS_BUTTONCHECK                                equ     00000H
DFCS_BUTTONRADIOIMAGE                           equ     00001H
DFCS_BUTTONRADIOMASK                            equ     00002H
DFCS_BUTTONRADIO                                equ     00004H
DFCS_BUTTON3STATE                               equ     00008H
DFCS_BUTTONPUSH                                 equ     00010H

DFCS_INACTIVE                                   equ     00100H
DFCS_PUSHED                                     equ     00200H
DFCS_CHECKED                                    equ     00400H

DFCS_TRANSPARENT                                equ     00800H
DFCS_HOT                                        equ     01000H

DFCS_ADJUSTRECT                                 equ     02000H
DFCS_FLAT                                       equ     04000H
DFCS_MONO                                       equ     08000H

DC_ACTIVE                                       equ     00001H
DC_SMALLCAP                                     equ     00002H
DC_ICON                                         equ     00004H
DC_TEXT                                         equ     00008H
DC_INBUTTON                                     equ     00010H
DC_GRADIENT                                     equ     00020H
DC_BUTTONS                                      equ     01000H

IDANI_OPEN                                      equ     1
IDANI_CLOSE                                     equ     2
IDANI_CAPTION                                   equ     3

CF_TEXT                                         equ     1
CF_BITMAP                                       equ     2
CF_METAFILEPICT                                 equ     3
CF_SYLK                                         equ     4
CF_DIF                                          equ     5
CF_TIFF                                         equ     6
CF_OEMTEXT                                      equ     7
CF_DIB                                          equ     8
CF_PALETTE                                      equ     9
CF_PENDATA                                      equ     10
CF_RIFF                                         equ     11
CF_WAVE                                         equ     12
CF_UNICODETEXT                                  equ     13
CF_ENHMETAFILE                                  equ     14
CF_HDROP                                        equ     15
CF_LOCALE                                       equ     16
CF_DIBV5                                        equ     17
#if NTDDI_VERSION <= NTDDI_WINNT4
    CF_MAX                                      equ     17
#else
    CF_MAX                                      equ     18
#endif

CF_OWNERDISPLAY                                 equ     00080H
CF_DSPTEXT                                      equ     00081H
CF_DSPBITMAP                                    equ     00082H
CF_DSPMETAFILEPICT                              equ     00083H
CF_DSPENHMETAFILE                               equ     0008EH

CF_PRIVATEFIRST                                 equ     00200H
CF_PRIVATELAST                                  equ     002FFH

CF_GDIOBJFIRST                                  equ     00300H
CF_GDIOBJLAST                                   equ     003FFH

FVIRTKEY                                        equ     TRUE
FNOINVERT                                       equ     002H
FSHIFT                                          equ     004H
FCONTROL                                        equ     008H
FALT                                            equ     010H

WPF_SETMINPOSITION                              equ     00001H
WPF_RESTORETOMAXIMIZED                          equ     00002H
WPF_ASYNCWINDOWPLACEMENT                        equ     00004H

ODT_MENU                                        equ     1
ODT_LISTBOX                                     equ     2
ODT_COMBOBOX                                    equ     3
ODT_BUTTON                                      equ     4
ODT_STATIC                                      equ     5

ODA_DRAWENTIRE                                  equ     00001H
ODA_SELECT                                      equ     00002H
ODA_FOCUS                                       equ     00004H

ODS_SELECTED                                    equ     00001H
ODS_GRAYED                                      equ     00002H
ODS_DISABLED                                    equ     00004H
ODS_CHECKED                                     equ     00008H
ODS_FOCUS                                       equ     00010H
ODS_DEFAULT                                     equ     00020H
ODS_COMBOBOXEDIT                                equ     01000H
ODS_HOTLIGHT                                    equ     00040H
ODS_INACTIVE                                    equ     00080H
ODS_NOACCEL                                     equ     00100H
ODS_NOFOCUSRECT                                 equ     00200H

QS_KEY                                          equ     00001H
QS_MOUSEMOVE                                    equ     00002H
QS_MOUSEBUTTON                                  equ     00004H
QS_POSTMESSAGE                                  equ     00008H
QS_TIMER                                        equ     00010H
QS_PAINT                                        equ     00020H
QS_SENDMESSAGE                                  equ     00040H
QS_HOTKEY                                       equ     00080H
QS_ALLPOSTMESSAGE                               equ     00100H
QS_MOUSE                                        equ     <QS_MOUSEMOVE or QS_MOUSEBUTTON>
QS_TOUCH                                        equ     00800H
QS_POINTER                                      equ     01000H
#if NTDDI_VERSION >= NTDDI_WIN8
    QS_INPUT                                    equ     <QS_MOUSE or QS_KEY or QS_RAWINPUT or QS_TOUCH or QS_POINTER>
#endif
#if NTDDI_VERSION >= NTDDI_WIN2K
    QS_INPUT                                    equ     <QS_MOUSE or QS_KEY or QS_RAWINPUT>
#else
    QS_INPUT                                    equ     <QS_MOUSE or QS_KEY>
#endif

QS_ALLEVENTS                                    equ     <QS_INPUT or QS_POSTMESSAGE or QS_TIMER or QS_PAINT or QS_HOTKEY>
QS_ALLINPUT                                     equ     <QS_INPUT or QS_POSTMESSAGE or QS_TIMER or QS_PAINT or QS_HOTKEY or QS_SENDMESSAGE>

PM_NOREMOVE                                     equ     00000H
PM_REMOVE                                       equ     00001H
PM_NOYIELD                                      equ     00002H
PM_QS_INPUT                                     equ     <QS_INPUT shl 16>
PM_QS_POSTMESSAGE                               equ     <(QS_POSTMESSAGE or QS_HOTKEY or QS_TIMER) shl 16>
PM_QS_PAINT                                     equ     <QS_PAINT shl 16>
PM_QS_SENDMESSAGE                               equ     <QS_SENDMESSAGE shl 16>

MOD_ALT                                         equ     00001H
MOD_CONTROL                                     equ     00002H
MOD_SHIFT                                       equ     00004H
MOD_WIN                                         equ     00008H
MOD_NOREPEAT                                    equ     04000H

IDHOT_SNAPWINDOW                                equ     (-1)
IDHOT_SNAPDESKTOP                               equ     (-2)

ENDSESSION_LOGOFF                               equ     080000000H

EWX_LOGOFF                                      equ     0
EWX_SHUTDOWN                                    equ     000000001H
EWX_REBOOT                                      equ     000000002H
EWX_FORCE                                       equ     000000004H
EWX_POWEROFF                                    equ     000000008H
EWX_FORCEIFHUNG                                 equ     000000010H
EWX_QUICKRESOLVE                                equ     000000020H
EWX_RESTARTAPPS                                 equ     000000040H
EWX_SHUTDOWN_FULL                               equ     000400000H

BSM_ALLCOMPONENTS                               equ     000000000H
BSM_VXDS                                        equ     000000001H
BSM_NETDRIVER                                   equ     000000002H
BSM_INSTALLABLEDRIVERS                          equ     000000004H
BSM_APPLICATIONS                                equ     000000008H
BSM_ALLDESKTOPS                                 equ     000000010H

BSF_QUERY                                       equ     000000001H
BSF_IGNORECURRENTTASK                           equ     000000002H
BSF_FLUSHDISK                                   equ     000000004H
BSF_NOHANG                                      equ     000000008H
BSF_POSTMESSAGE                                 equ     000000010H
BSF_FORCEIFHUNG                                 equ     000000020H
BSF_NOTIMEOUTIFNOTHUNG                          equ     000000040H
BSF_ALLOWSFW                                    equ     000000080H
BSF_SENDNOTIFYMESSAGE                           equ     000000100H
BSF_RETURNHDESK                                 equ     000000200H
BSF_LUID                                        equ     000000400H

BROADCAST_QUERY_DENY                            equ     0424D5144H

DEVICE_NOTIFY_WINDOW_HANDLE                     equ     000000000H
DEVICE_NOTIFY_SERVICE_HANDLE                    equ     000000001H

HWND_BROADCAST                                  equ     0FFFFH

HWND_MESSAGE                                    equ     (-3)

ISMEX_NOSEND                                    equ     000000000H
ISMEX_SEND                                      equ     000000001H
ISMEX_NOTIFY                                    equ     000000002H
ISMEX_CALLBACK                                  equ     000000004H
ISMEX_REPLIED                                   equ     000000008H

CW_USEDEFAULT                                   equ     080000000H

HWND_DESKTOP                                    equ     0

LWA_COLORKEY                                    equ     000000001H
LWA_ALPHA                                       equ     000000002H

ULW_COLORKEY                                    equ     000000001H
ULW_ALPHA                                       equ     000000002H
ULW_OPAQUE                                      equ     000000004H

FLASHW_STOP                                     equ     0
FLASHW_CAPTION                                  equ     000000001H
FLASHW_TRAY                                     equ     000000002H
FLASHW_ALL                                      equ     <FLASHW_CAPTION or FLASHW_TRAY>
FLASHW_TIMER                                    equ     000000004H
FLASHW_TIMERNOFG                                equ     00000000CH

SWP_NOSIZE                                      equ     00001H
SWP_NOMOVE                                      equ     00002H
SWP_NOZORDER                                    equ     00004H
SWP_NOREDRAW                                    equ     00008H
SWP_NOACTIVATE                                  equ     00010H
SWP_FRAMECHANGED                                equ     00020H
SWP_SHOWWINDOW                                  equ     00040H
SWP_HIDEWINDOW                                  equ     00080H
SWP_NOCOPYBITS                                  equ     00100H
SWP_NOOWNERZORDER                               equ     00200H
SWP_NOSENDCHANGING                              equ     00400H

SWP_DRAWFRAME                                   equ     SWP_FRAMECHANGED
SWP_NOREPOSITION                                equ     SWP_NOOWNERZORDER

SWP_DEFERERASE                                  equ     02000H
SWP_ASYNCWINDOWPOS                              equ     04000H

HWND_TOP                                        equ     0
HWND_BOTTOM                                     equ     1
HWND_TOPMOST                                    equ     (-1)
HWND_NOTOPMOST                                  equ     (-2)

DLGWINDOWEXTRA                                  equ     30

KEYEVENTF_EXTENDEDKEY                           equ     00001H
KEYEVENTF_KEYUP                                 equ     00002H
KEYEVENTF_UNICODE                               equ     00004H
KEYEVENTF_SCANCODE                              equ     00008H

MOUSEEVENTF_MOVE                                equ     00001H
MOUSEEVENTF_LEFTDOWN                            equ     00002H
MOUSEEVENTF_LEFTUP                              equ     00004H
MOUSEEVENTF_RIGHTDOWN                           equ     00008H
MOUSEEVENTF_RIGHTUP                             equ     00010H
MOUSEEVENTF_MIDDLEDOWN                          equ     00020H
MOUSEEVENTF_MIDDLEUP                            equ     00040H
MOUSEEVENTF_XDOWN                               equ     00080H
MOUSEEVENTF_XUP                                 equ     00100H
MOUSEEVENTF_WHEEL                               equ     00800H
MOUSEEVENTF_HWHEEL                              equ     01000H
MOUSEEVENTF_MOVE_NOCOALESCE                     equ     02000H
MOUSEEVENTF_VIRTUALDESK                         equ     04000H
MOUSEEVENTF_ABSOLUTE                            equ     08000H

INPUT_MOUSE                                     equ     0
INPUT_KEYBOARD                                  equ     1
INPUT_HARDWARE                                  equ     2

MWMO_WAITALL                                    equ     00001H
MWMO_ALERTABLE                                  equ     00002H
MWMO_INPUTAVAILABLE                             equ     00004H

USER_TIMER_MAXIMUM                              equ     07FFFFFFFH
USER_TIMER_MINIMUM                              equ     00000000AH

SM_CXSCREEN                                     equ     0
SM_CYSCREEN                                     equ     1
SM_CXVSCROLL                                    equ     2
SM_CYHSCROLL                                    equ     3
SM_CYCAPTION                                    equ     4
SM_CXBORDER                                     equ     5
SM_CYBORDER                                     equ     6
SM_CXDLGFRAME                                   equ     7
SM_CYDLGFRAME                                   equ     8
SM_CYVTHUMB                                     equ     9
SM_CXHTHUMB                                     equ     10
SM_CXICON                                       equ     11
SM_CYICON                                       equ     12
SM_CXCURSOR                                     equ     13
SM_CYCURSOR                                     equ     14
SM_CYMENU                                       equ     15
SM_CXFULLSCREEN                                 equ     16
SM_CYFULLSCREEN                                 equ     17
SM_CYKANJIWINDOW                                equ     18
SM_MOUSEPRESENT                                 equ     19
SM_CYVSCROLL                                    equ     20
SM_CXHSCROLL                                    equ     21
SM_DEBUG                                        equ     22
SM_SWAPBUTTON                                   equ     23
SM_RESERVED1                                    equ     24
SM_RESERVED2                                    equ     25
SM_RESERVED3                                    equ     26
SM_RESERVED4                                    equ     27
SM_CXMIN                                        equ     28
SM_CYMIN                                        equ     29
SM_CXSIZE                                       equ     30
SM_CYSIZE                                       equ     31
SM_CXFRAME                                      equ     32
SM_CYFRAME                                      equ     33
SM_CXMINTRACK                                   equ     34
SM_CYMINTRACK                                   equ     35
SM_CXDOUBLECLK                                  equ     36
SM_CYDOUBLECLK                                  equ     37
SM_CXICONSPACING                                equ     38
SM_CYICONSPACING                                equ     39
SM_MENUDROPALIGNMENT                            equ     40
SM_PENWINDOWS                                   equ     41
SM_DBCSENABLED                                  equ     42
SM_CMOUSEBUTTONS                                equ     43

SM_CXFIXEDFRAME                                 equ     SM_CXDLGFRAME
SM_CYFIXEDFRAME                                 equ     SM_CYDLGFRAME
SM_CXSIZEFRAME                                  equ     SM_CXFRAME
SM_CYSIZEFRAME                                  equ     SM_CYFRAME

SM_SECURE                                       equ     44
SM_CXEDGE                                       equ     45
SM_CYEDGE                                       equ     46
SM_CXMINSPACING                                 equ     47
SM_CYMINSPACING                                 equ     48
SM_CXSMICON                                     equ     49
SM_CYSMICON                                     equ     50
SM_CYSMCAPTION                                  equ     51
SM_CXSMSIZE                                     equ     52
SM_CYSMSIZE                                     equ     53
SM_CXMENUSIZE                                   equ     54
SM_CYMENUSIZE                                   equ     55
SM_ARRANGE                                      equ     56
SM_CXMINIMIZED                                  equ     57
SM_CYMINIMIZED                                  equ     58
SM_CXMAXTRACK                                   equ     59
SM_CYMAXTRACK                                   equ     60
SM_CXMAXIMIZED                                  equ     61
SM_CYMAXIMIZED                                  equ     62
SM_NETWORK                                      equ     63
SM_CLEANBOOT                                    equ     67
SM_CXDRAG                                       equ     68
SM_CYDRAG                                       equ     69
SM_SHOWSOUNDS                                   equ     70
SM_CXMENUCHECK                                  equ     71
SM_CYMENUCHECK                                  equ     72
SM_SLOWMACHINE                                  equ     73
SM_MIDEASTENABLED                               equ     74
SM_MOUSEWHEELPRESENT                            equ     75
SM_XVIRTUALSCREEN                               equ     76
SM_YVIRTUALSCREEN                               equ     77
SM_CXVIRTUALSCREEN                              equ     78
SM_CYVIRTUALSCREEN                              equ     79
SM_CMONITORS                                    equ     80
SM_SAMEDISPLAYFORMAT                            equ     81
SM_IMMENABLED                                   equ     82
SM_CXFOCUSBORDER                                equ     83
SM_CYFOCUSBORDER                                equ     84
SM_TABLETPC                                     equ     86
SM_MEDIACENTER                                  equ     87
SM_STARTER                                      equ     88
SM_SERVERR2                                     equ     89
SM_MOUSEHORIZONTALWHEELPRESENT                  equ     91
SM_CXPADDEDBORDER                               equ     92
SM_DIGITIZER                                    equ     94
SM_MAXIMUMTOUCHES                               equ     95
SM_REMOTESESSION                                equ     01000H
SM_SHUTTINGDOWN                                 equ     02000H
SM_REMOTECONTROL                                equ     02001H
SM_CARETBLINKINGENABLED                         equ     02002H
#ifndef SM_CMETRICS
    #if NTDDI_VERSION >= NTDDI_WIN7
        SM_CMETRICS                             equ     97
    #else
        #if NTDDI_VERSION >= NTDDI_VISTA
            SM_CMETRICS                         equ     93
        #else
            #if NTDDI_VERSION >= NTDDI_WINXP
                SM_CMETRICS                     equ     90
            #else
                #if NTDDI_VERSION == NTDDI_WIN2K
                    SM_CMETRICS                 equ     83
                #else
                    #if NTDDI_VERSION < NTDDI_WIN2K
                    SM_CMETRICS                 equ     76
                #endif
            #endif
        #endif
    #endif
#endif

PMB_ACTIVE                                      equ     00000001H

MNC_IGNORE                                      equ     0
MNC_CLOSE                                       equ     1
MNC_EXECUTE                                     equ     2
MNC_SELECT                                      equ     3

MNS_NOCHECK                                     equ     080000000H
MNS_MODELESS                                    equ     040000000H
MNS_DRAGDROP                                    equ     020000000H
MNS_AUTODISMISS                                 equ     010000000H
MNS_NOTIFYBYPOS                                 equ     008000000H
MNS_CHECKORBMP                                  equ     004000000H

MIM_MAXHEIGHT                                   equ     000000001H
MIM_BACKGROUND                                  equ     000000002H
MIM_HELPID                                      equ     000000004H
MIM_MENUDATA                                    equ     000000008H
MIM_STYLE                                       equ     000000010H
MIM_APPLYTOSUBMENUS                             equ     080000000H

MND_CONTINUE                                    equ     0
MND_ENDMENU                                     equ     1

MNGOF_TOPGAP                                    equ     000000001H
MNGOF_BOTTOMGAP                                 equ     000000002H

MNGO_NOINTERFACE                                equ     000000000H
MNGO_NOERROR                                    equ     000000001H

MIIM_STATE                                      equ     000000001H
MIIM_ID                                         equ     000000002H
MIIM_SUBMENU                                    equ     000000004H
MIIM_CHECKMARKS                                 equ     000000008H
MIIM_TYPE                                       equ     000000010H
MIIM_DATA                                       equ     000000020H

MIIM_STRING                                     equ     000000040H
MIIM_BITMAP                                     equ     000000080H
MIIM_FTYPE                                      equ     000000100H

HBMMENU_CALLBACK                                equ     (-1)
HBMMENU_SYSTEM                                  equ     1
HBMMENU_MBAR_RESTORE                            equ     2
HBMMENU_MBAR_MINIMIZE                           equ     3
HBMMENU_MBAR_CLOSE                              equ     5
HBMMENU_MBAR_CLOSE_D                            equ     6
HBMMENU_MBAR_MINIMIZE_D                         equ     7
HBMMENU_POPUP_CLOSE                             equ     8
HBMMENU_POPUP_RESTORE                           equ     9
HBMMENU_POPUP_MAXIMIZE                          equ     10
HBMMENU_POPUP_MINIMIZE                          equ     11

GMDI_USEDISABLED                                equ     00001H
GMDI_GOINTOPOPUPS                               equ     00002H

TPM_LEFTBUTTON                                  equ     00000H
TPM_RIGHTBUTTON                                 equ     00002H
TPM_LEFTALIGN                                   equ     00000H
TPM_CENTERALIGN                                 equ     00004H
TPM_RIGHTALIGN                                  equ     00008H
TPM_TOPALIGN                                    equ     00000H
TPM_VCENTERALIGN                                equ     00010H
TPM_BOTTOMALIGN                                 equ     00020H

TPM_HORIZONTAL                                  equ     00000H
TPM_VERTICAL                                    equ     00040H
TPM_NONOTIFY                                    equ     00080H
TPM_RETURNCMD                                   equ     00100H
TPM_RECURSE                                     equ     00001H

TPM_HORPOSANIMATION                             equ     00400H
TPM_HORNEGANIMATION                             equ     00800H
TPM_VERPOSANIMATION                             equ     01000H
TPM_VERNEGANIMATION                             equ     02000H
TPM_NOANIMATION                                 equ     04000H
TPM_LAYOUTRTL                                   equ     08000H
TPM_WORKAREA                                    equ     10000H

DOF_EXECUTABLE                                  equ     08001H
DOF_DOCUMENT                                    equ     08002H
DOF_DIRECTORY                                   equ     08003H
DOF_MULTIPLE                                    equ     08004H
DOF_PROGMAN                                     equ     00001H
DOF_SHELLDATA                                   equ     00002H

DO_DROPFILE                                     equ     0454C4946H
DO_PRINTFILE                                    equ     0544E5250H

DT_TOP                                          equ     000000000H
DT_LEFT                                         equ     000000000H
DT_CENTER                                       equ     000000001H
DT_RIGHT                                        equ     000000002H
DT_VCENTER                                      equ     000000004H
DT_BOTTOM                                       equ     000000008H
DT_WORDBREAK                                    equ     000000010H
DT_SINGLELINE                                   equ     000000020H
DT_EXPANDTABS                                   equ     000000040H
DT_TABSTOP                                      equ     000000080H
DT_NOCLIP                                       equ     000000100H
DT_EXTERNALLEADING                              equ     000000200H
DT_CALCRECT                                     equ     000000400H
DT_NOPREFIX                                     equ     000000800H
DT_INTERNAL                                     equ     000001000H

DT_EDITCONTROL                                  equ     000002000H
DT_PATH_ELLIPSIS                                equ     000004000H
DT_END_ELLIPSIS                                 equ     000008000H
DT_MODIFYSTRING                                 equ     000010000H
DT_RTLREADING                                   equ     000020000H
DT_WORD_ELLIPSIS                                equ     000040000H
DT_NOFULLWIDTHCHARBREAK                         equ     000080000H
DT_HIDEPREFIX                                   equ     000100000H
DT_PREFIXONLY                                   equ     000200000H

DST_COMPLEX                                     equ     00000H
DST_TEXT                                        equ     00001H
DST_PREFIXTEXT                                  equ     00002H
DST_ICON                                        equ     00003H
DST_BITMAP                                      equ     00004H

DSS_NORMAL                                      equ     00000H
DSS_UNION                                       equ     00010H
DSS_DISABLED                                    equ     00020H
DSS_MONO                                        equ     00080H
DSS_HIDEPREFIX                                  equ     00200H
DSS_PREFIXONLY                                  equ     00400H
DSS_RIGHT                                       equ     08000H

ASFW_ANY                                        equ     (-1)
LSFW_LOCK                                       equ     1
LSFW_UNLOCK                                     equ     2

DCX_WINDOW                                      equ     000000001H
DCX_CACHE                                       equ     000000002H
DCX_NORESETATTRS                                equ     000000004H
DCX_CLIPCHILDREN                                equ     000000008H
DCX_CLIPSIBLINGS                                equ     000000010H
DCX_PARENTCLIP                                  equ     000000020H
DCX_EXCLUDERGN                                  equ     000000040H
DCX_INTERSECTRGN                                equ     000000080H
DCX_EXCLUDEUPDATE                               equ     000000100H
DCX_INTERSECTUPDATE                             equ     000000200H
DCX_LOCKWINDOWUPDATE                            equ     000000400H
DCX_VALIDATE                                    equ     000200000H

CUDR_NORMAL                                     equ     00000H
CUDR_NOSNAPTOGRID                               equ     00001H
CUDR_NORESOLVEPOSITIONS                         equ     00002H
CUDR_NOCLOSEGAPS                                equ     00004H
CUDR_NEGATIVECOORDS                             equ     00008H
CUDR_NOPRIMARY                                  equ     00010H

RDW_INVALIDATE                                  equ     00001H
RDW_INTERNALPAINT                               equ     00002H
RDW_ERASE                                       equ     00004H
RDW_VALIDATE                                    equ     00008H
RDW_NOINTERNALPAINT                             equ     00010H
RDW_NOERASE                                     equ     00020H
RDW_NOCHILDREN                                  equ     00040H
RDW_ALLCHILDREN                                 equ     00080H
RDW_UPDATENOW                                   equ     00100H
RDW_ERASENOW                                    equ     00200H
RDW_FRAME                                       equ     00400H
RDW_NOFRAME                                     equ     00800H

SW_SCROLLCHILDREN                               equ     00001H
SW_INVALIDATE                                   equ     00002H
SW_ERASE                                        equ     00004H
SW_SMOOTHSCROLL                                 equ     00010H

ESB_ENABLE_BOTH                                 equ     00000H
ESB_DISABLE_BOTH                                equ     00003H

ESB_DISABLE_LEFT                                equ     00001H
ESB_DISABLE_RIGHT                               equ     00002H

ESB_DISABLE_UP                                  equ     00001H
ESB_DISABLE_DOWN                                equ     00002H

ESB_DISABLE_LTUP                                equ     ESB_DISABLE_LEFT
ESB_DISABLE_RTDN                                equ     ESB_DISABLE_RIGHT

HELPINFO_WINDOW                                 equ     00001H
HELPINFO_MENUITEM                               equ     00002H

MB_OK                                           equ     000000000H
MB_OKCANCEL                                     equ     000000001H
MB_ABORTRETRYIGNORE                             equ     000000002H
MB_YESNOCANCEL                                  equ     000000003H
MB_YESNO                                        equ     000000004H
MB_RETRYCANCEL                                  equ     000000005H
MB_CANCELTRYCONTINUE                            equ     000000006H
MB_ICONHAND                                     equ     000000010H
MB_ICONQUESTION                                 equ     000000020H
MB_ICONEXCLAMATION                              equ     000000030H
MB_ICONASTERISK                                 equ     000000040H
MB_USERICON                                     equ     000000080H
MB_ICONWARNING                                  equ     MB_ICONEXCLAMATION
MB_ICONERROR                                    equ     MB_ICONHAND
MB_ICONINFORMATION                              equ     MB_ICONASTERISK
MB_ICONSTOP                                     equ     MB_ICONHAND
MB_DEFBUTTON1                                   equ     000000000H
MB_DEFBUTTON2                                   equ     000000100H
MB_DEFBUTTON3                                   equ     000000200H
MB_DEFBUTTON4                                   equ     000000300H
MB_APPLMODAL                                    equ     000000000H
MB_SYSTEMMODAL                                  equ     000001000H
MB_TASKMODAL                                    equ     000002000H
MB_HELP                                         equ     000004000H
MB_NOFOCUS                                      equ     000008000H
MB_SETFOREGROUND                                equ     000010000H
MB_DEFAULT_DESKTOP_ONLY                         equ     000020000H
MB_TOPMOST                                      equ     000040000H
MB_RIGHT                                        equ     000080000H
MB_RTLREADING                                   equ     000100000H
#if NTDDI_VERSION == NTDDI_WINNT4
    MB_SERVICE_NOTIFICATION                     equ     000040000H
#else
    MB_SERVICE_NOTIFICATION                     equ     000200000H
#endif

MB_SERVICE_NOTIFICATION_NT3X                    equ     000040000H

MB_TYPEMASK                                     equ     00000000FH
MB_ICONMASK                                     equ     0000000F0H
MB_DEFMASK                                      equ     000000F00H
MB_MODEMASK                                     equ     000003000H
MB_MISCMASK                                     equ     00000C000H

CWP_ALL                                         equ     00000H
CWP_SKIPINVISIBLE                               equ     00001H
CWP_SKIPDISABLED                                equ     00002H
CWP_SKIPTRANSPARENT                             equ     00004H

CTLCOLOR_MSGBOX                                 equ     0
CTLCOLOR_EDIT                                   equ     1
CTLCOLOR_LISTBOX                                equ     2
CTLCOLOR_BTN                                    equ     3
CTLCOLOR_DLG                                    equ     4
CTLCOLOR_SCROLLBAR                              equ     5
CTLCOLOR_STATIC                                 equ     6
CTLCOLOR_MAX                                    equ     7

SYS_COLOR_INDEX_FLAG                            equ     0

COLOR_SCROLLBAR                                 equ     0
COLOR_BACKGROUND                                equ     1
COLOR_ACTIVECAPTION                             equ     2
COLOR_INACTIVECAPTION                           equ     3
COLOR_MENU                                      equ     4
COLOR_WINDOW                                    equ     5
COLOR_WINDOWFRAME                               equ     6
COLOR_MENUTEXT                                  equ     7
COLOR_WINDOWTEXT                                equ     8
COLOR_CAPTIONTEXT                               equ     9
COLOR_ACTIVEBORDER                              equ     10
COLOR_INACTIVEBORDER                            equ     11
COLOR_APPWORKSPACE                              equ     12
COLOR_HIGHLIGHT                                 equ     13
COLOR_HIGHLIGHTTEXT                             equ     14
COLOR_BTNFACE                                   equ     15
COLOR_BTNSHADOW                                 equ     16
COLOR_GRAYTEXT                                  equ     17
COLOR_BTNTEXT                                   equ     18
COLOR_INACTIVECAPTIONTEXT                       equ     19
COLOR_BTNHIGHLIGHT                              equ     20
COLOR_3DDKSHADOW                                equ     21
COLOR_3DLIGHT                                   equ     22
COLOR_INFOTEXT                                  equ     23
COLOR_INFOBK                                    equ     24

COLOR_HOTLIGHT                                  equ     26
COLOR_GRADIENTACTIVECAPTION                     equ     27
COLOR_GRADIENTINACTIVECAPTION                   equ     28
COLOR_MENUHILIGHT                               equ     29
COLOR_MENUBAR                                   equ     30

COLOR_DESKTOP                                   equ     COLOR_BACKGROUND
COLOR_3DFACE                                    equ     COLOR_BTNFACE
COLOR_3DSHADOW                                  equ     COLOR_BTNSHADOW
COLOR_3DHIGHLIGHT                               equ     COLOR_BTNHIGHLIGHT
COLOR_3DHILIGHT                                 equ     COLOR_BTNHIGHLIGHT
COLOR_BTNHILIGHT                                equ     COLOR_BTNHIGHLIGHT

GW_HWNDFIRST                                    equ     0
GW_HWNDLAST                                     equ     1
GW_HWNDNEXT                                     equ     2
GW_HWNDPREV                                     equ     3
GW_OWNER                                        equ     4
GW_CHILD                                        equ     5

#if NTDDI_VERSION == NTDDI_WINNT4
    GW_MAX                                      equ     5
#else
    GW_ENABLEDPOPUP                             equ     6
    GW_MAX                                      equ     6
#endif

MF_INSERT                                       equ     000000000H
MF_CHANGE                                       equ     000000080H
MF_APPEND                                       equ     000000100H
MF_DELETE                                       equ     000000200H
MF_REMOVE                                       equ     000001000H
MF_BYCOMMAND                                    equ     000000000H
MF_BYPOSITION                                   equ     000000400H
MF_SEPARATOR                                    equ     000000800H
MF_ENABLED                                      equ     000000000H
MF_GRAYED                                       equ     000000001H
MF_DISABLED                                     equ     000000002H
MF_UNCHECKED                                    equ     000000000H
MF_CHECKED                                      equ     000000008H
MF_USECHECKBITMAPS                              equ     000000200H
MF_STRING                                       equ     000000000H
MF_BITMAP                                       equ     000000004H
MF_OWNERDRAW                                    equ     000000100H
MF_POPUP                                        equ     000000010H
MF_MENUBARBREAK                                 equ     000000020H
MF_MENUBREAK                                    equ     000000040H
MF_UNHILITE                                     equ     000000000H
MF_HILITE                                       equ     000000080H
MF_DEFAULT                                      equ     000001000H
MF_SYSMENU                                      equ     000002000H
MF_HELP                                         equ     000004000H
MF_RIGHTJUSTIFY                                 equ     000004000H
MF_MOUSESELECT                                  equ     000008000H
MF_END                                          equ     000000080H

MFT_STRING                                      equ     MF_STRING
MFT_BITMAP                                      equ     MF_BITMAP
MFT_MENUBARBREAK                                equ     MF_MENUBARBREAK
MFT_MENUBREAK                                   equ     MF_MENUBREAK
MFT_OWNERDRAW                                   equ     MF_OWNERDRAW
MFT_RADIOCHECK                                  equ     000000200H
MFT_SEPARATOR                                   equ     MF_SEPARATOR
MFT_RIGHTORDER                                  equ     000002000H
MFT_RIGHTJUSTIFY                                equ     MF_RIGHTJUSTIFY

MFS_GRAYED                                      equ     000000003H
MFS_DISABLED                                    equ     MFS_GRAYED
MFS_CHECKED                                     equ     MF_CHECKED
MFS_HILITE                                      equ     MF_HILITE
MFS_ENABLED                                     equ     MF_ENABLED
MFS_UNCHECKED                                   equ     MF_UNCHECKED
MFS_UNHILITE                                    equ     MF_UNHILITE
MFS_DEFAULT                                     equ     MF_DEFAULT
MFS_MASK                                        equ     00000108BH
MFS_HOTTRACKDRAWN                               equ     010000000H
MFS_CACHEDBMP                                   equ     020000000H
MFS_BOTTOMGAPDROP                               equ     040000000H
MFS_TOPGAPDROP                                  equ     080000000H
MFS_GAPDROP                                     equ     0C0000000H

SC_SIZE                                         equ     0F000H
SC_MOVE                                         equ     0F010H
SC_MINIMIZE                                     equ     0F020H
SC_MAXIMIZE                                     equ     0F030H
SC_NEXTWINDOW                                   equ     0F040H
SC_PREVWINDOW                                   equ     0F050H
SC_CLOSE                                        equ     0F060H
SC_VSCROLL                                      equ     0F070H
SC_HSCROLL                                      equ     0F080H
SC_MOUSEMENU                                    equ     0F090H
SC_KEYMENU                                      equ     0F100H
SC_ARRANGE                                      equ     0F110H
SC_RESTORE                                      equ     0F120H
SC_TASKLIST                                     equ     0F130H
SC_SCREENSAVE                                   equ     0F140H
SC_HOTKEY                                       equ     0F150H
SC_DEFAULT                                      equ     0F160H
SC_MONITORPOWER                                 equ     0F170H
SC_CONTEXTHELP                                  equ     0F180H
SC_SEPARATOR                                    equ     0F00FH

SCF_ISSECURE                                    equ     000000001H

SC_ICON                                         equ     SC_MINIMIZE
SC_ZOOM                                         equ     SC_MAXIMIZE

IDC_ARROW                                       equ     32512
IDC_IBEAM                                       equ     32513
IDC_WAIT                                        equ     32514
IDC_CROSS                                       equ     32515
IDC_UPARROW                                     equ     32516
IDC_SIZE                                        equ     32640
IDC_ICON                                        equ     32641
IDC_SIZENWSE                                    equ     32642
IDC_SIZENESW                                    equ     32643
IDC_SIZEWE                                      equ     32644
IDC_SIZENS                                      equ     32645
IDC_SIZEALL                                     equ     32646
IDC_NO                                          equ     32648
IDC_HAND                                        equ     32649
IDC_APPSTARTING                                 equ     32650
IDC_HELP                                        equ     32651

IMAGE_BITMAP                                    equ     0
IMAGE_ICON                                      equ     1
IMAGE_CURSOR                                    equ     2
IMAGE_ENHMETAFILE                               equ     3

LR_DEFAULTCOLOR                                 equ     00000H
LR_MONOCHROME                                   equ     00001H
LR_COLOR                                        equ     00002H
LR_COPYRETURNORG                                equ     00004H
LR_COPYDELETEORG                                equ     00008H
LR_LOADFROMFILE                                 equ     00010H
LR_LOADTRANSPARENT                              equ     00020H
LR_DEFAULTSIZE                                  equ     00040H
LR_VGACOLOR                                     equ     00080H
LR_LOADMAP3DCOLORS                              equ     01000H
LR_CREATEDIBSECTION                             equ     02000H
LR_COPYFROMRESOURCE                             equ     04000H
LR_SHARED                                       equ     08000H

DI_MASK                                         equ     00001H
DI_IMAGE                                        equ     00002H
DI_NORMAL                                       equ     00003H
DI_COMPAT                                       equ     00004H
DI_DEFAULTSIZE                                  equ     00008H
DI_NOMIRROR                                     equ     00010H

RES_ICON                                        equ     1
RES_CURSOR                                      equ     2

OBM_CLOSE                                       equ     32754
OBM_UPARROW                                     equ     32753
OBM_DNARROW                                     equ     32752
OBM_RGARROW                                     equ     32751
OBM_LFARROW                                     equ     32750
OBM_REDUCE                                      equ     32749
OBM_ZOOM                                        equ     32748
OBM_RESTORE                                     equ     32747
OBM_REDUCED                                     equ     32746
OBM_ZOOMD                                       equ     32745
OBM_RESTORED                                    equ     32744
OBM_UPARROWD                                    equ     32743
OBM_DNARROWD                                    equ     32742
OBM_RGARROWD                                    equ     32741
OBM_LFARROWD                                    equ     32740
OBM_MNARROW                                     equ     32739
OBM_COMBO                                       equ     32738
OBM_UPARROWI                                    equ     32737
OBM_DNARROWI                                    equ     32736
OBM_RGARROWI                                    equ     32735
OBM_LFARROWI                                    equ     32734

OBM_OLD_CLOSE                                   equ     32767
OBM_SIZE                                        equ     32766
OBM_OLD_UPARROW                                 equ     32765
OBM_OLD_DNARROW                                 equ     32764
OBM_OLD_RGARROW                                 equ     32763
OBM_OLD_LFARROW                                 equ     32762
OBM_BTSIZE                                      equ     32761
OBM_CHECK                                       equ     32760
OBM_CHECKBOXES                                  equ     32759
OBM_BTNCORNERS                                  equ     32758
OBM_OLD_REDUCE                                  equ     32757
OBM_OLD_ZOOM                                    equ     32756
OBM_OLD_RESTORE                                 equ     32755

OCR_NORMAL                                      equ     32512
OCR_IBEAM                                       equ     32513
OCR_WAIT                                        equ     32514
OCR_CROSS                                       equ     32515
OCR_UP                                          equ     32516
OCR_SIZE                                        equ     32640
OCR_ICON                                        equ     32641
OCR_SIZENWSE                                    equ     32642
OCR_SIZENESW                                    equ     32643
OCR_SIZEWE                                      equ     32644
OCR_SIZENS                                      equ     32645
OCR_SIZEALL                                     equ     32646
OCR_ICOCUR                                      equ     32647
OCR_NO                                          equ     32648
OCR_HAND                                        equ     32649
OCR_APPSTARTING                                 equ     32650

OIC_SAMPLE                                      equ     32512
OIC_HAND                                        equ     32513
OIC_QUES                                        equ     32514
OIC_BANG                                        equ     32515
OIC_NOTE                                        equ     32516
OIC_WINLOGO                                     equ     32517
OIC_WARNING                                     equ     OIC_BANG
OIC_ERROR                                       equ     OIC_HAND
OIC_INFORMATION                                 equ     OIC_NOTE
OIC_SHIELD                                      equ     32518

ORD_LANGDRIVER                                  equ     1

IDI_APPLICATION                                 equ     32512
IDI_HAND                                        equ     32513
IDI_QUESTION                                    equ     32514
IDI_EXCLAMATION                                 equ     32515
IDI_ASTERISK                                    equ     32516
IDI_WINLOGO                                     equ     32517
IDI_SHIELD                                      equ     32518

IDI_WARNING                                     equ     IDI_EXCLAMATION
IDI_ERROR                                       equ     IDI_HAND
IDI_INFORMATION                                 equ     IDI_ASTERISK

IDOK                                            equ     1
IDCANCEL                                        equ     2
IDABORT                                         equ     3
IDRETRY                                         equ     4
IDIGNORE                                        equ     5
IDYES                                           equ     6
IDNO                                            equ     7
IDCLOSE                                         equ     8
IDHELP                                          equ     9
IDTRYAGAIN                                      equ     10
IDCONTINUE                                      equ     11
IDTIMEOUT                                       equ     32000

ES_LEFT                                         equ     00000H
ES_CENTER                                       equ     00001H
ES_RIGHT                                        equ     00002H
ES_MULTILINE                                    equ     00004H
ES_UPPERCASE                                    equ     00008H
ES_LOWERCASE                                    equ     00010H
ES_PASSWORD                                     equ     00020H
ES_AUTOVSCROLL                                  equ     00040H
ES_AUTOHSCROLL                                  equ     00080H
ES_NOHIDESEL                                    equ     00100H
ES_OEMCONVERT                                   equ     00400H
ES_READONLY                                     equ     00800H
ES_WANTRETURN                                   equ     01000H
ES_NUMBER                                       equ     02000H

EN_SETFOCUS                                     equ     00100H
EN_KILLFOCUS                                    equ     00200H
EN_CHANGE                                       equ     00300H
EN_UPDATE                                       equ     00400H
EN_ERRSPACE                                     equ     00500H
EN_MAXTEXT                                      equ     00501H
EN_HSCROLL                                      equ     00601H
EN_VSCROLL                                      equ     00602H

EN_ALIGN_LTR_EC                                 equ     00700H
EN_ALIGN_RTL_EC                                 equ     00701H

EC_LEFTMARGIN                                   equ     00001H
EC_RIGHTMARGIN                                  equ     00002H
EC_USEFONTINFO                                  equ     0FFFFH

EMSIS_COMPOSITIONSTRING                         equ     00001H

EIMES_GETCOMPSTRATONCE                          equ     00001H
EIMES_CANCELCOMPSTRINFOCUS                      equ     00002H
EIMES_COMPLETECOMPSTRKILLFOCUS                  equ     00004H

#ifndef ECM_FIRST
    ECM_FIRST                                   EQU     01500H
#endif

EM_GETSEL                                       equ     000B0H
EM_SETSEL                                       equ     000B1H
EM_GETRECT                                      equ     000B2H
EM_SETRECT                                      equ     000B3H
EM_SETRECTNP                                    equ     000B4H
EM_SCROLL                                       equ     000B5H
EM_LINESCROLL                                   equ     000B6H
EM_SCROLLCARET                                  equ     000B7H
EM_GETMODIFY                                    equ     000B8H
EM_SETMODIFY                                    equ     000B9H
EM_GETLINECOUNT                                 equ     000BAH
EM_LINEINDEX                                    equ     000BBH
EM_SETHANDLE                                    equ     000BCH
EM_GETHANDLE                                    equ     000BDH
EM_GETTHUMB                                     equ     000BEH
EM_LINELENGTH                                   equ     000C1H
EM_REPLACESEL                                   equ     000C2H
EM_SETFONT                                      equ     000C3H
EM_GETLINE                                      equ     000C4H
EM_LIMITTEXT                                    equ     000C5H
EM_CANUNDO                                      equ     000C6H
EM_UNDO                                         equ     000C7H
EM_FMTLINES                                     equ     000C8H
EM_LINEFROMCHAR                                 equ     000C9H
EM_SETWORDBREAK                                 equ     000CAH
EM_SETTABSTOPS                                  equ     000CBH
EM_SETPASSWORDCHAR                              equ     000CCH
EM_EMPTYUNDOBUFFER                              equ     000CDH
EM_GETFIRSTVISIBLELINE                          equ     000CEH
EM_SETREADONLY                                  equ     000CFH
EM_SETWORDBREAKPROC                             equ     000D0H
EM_GETWORDBREAKPROC                             equ     000D1H
EM_GETPASSWORDCHAR                              equ     000D2H
EM_SETMARGINS                                   equ     000D3H
EM_GETMARGINS                                   equ     000D4H
EM_SETLIMITTEXT                                 equ     EM_LIMITTEXT
EM_GETLIMITTEXT                                 equ     000D5H
EM_POSFROMCHAR                                  equ     000D6H
EM_CHARFROMPOS                                  equ     000D7H
EM_SETIMESTATUS                                 equ     000D8H
EM_GETIMESTATUS                                 equ     000D9H
EM_SETCUEBANNER                                 equ     (ECM_FIRST+1)

WB_LEFT                                         equ     0
WB_RIGHT                                        equ     1
WB_ISDELIMITER                                  equ     2

BS_PUSHBUTTON                                   equ     000000000H
BS_DEFPUSHBUTTON                                equ     000000001H
BS_CHECKBOX                                     equ     000000002H
BS_AUTOCHECKBOX                                 equ     000000003H
BS_RADIOBUTTON                                  equ     000000004H
BS_3STATE                                       equ     000000005H
BS_AUTO3STATE                                   equ     000000006H
BS_GROUPBOX                                     equ     000000007H
BS_USERBUTTON                                   equ     000000008H
BS_AUTORADIOBUTTON                              equ     000000009H
BS_OWNERDRAW                                    equ     00000000BH
BS_LEFTTEXT                                     equ     000000020H
BS_TEXT                                         equ     000000000H
BS_ICON                                         equ     000000040H
BS_BITMAP                                       equ     000000080H
BS_LEFT                                         equ     000000100H
BS_RIGHT                                        equ     000000200H
BS_CENTER                                       equ     000000300H
BS_TOP                                          equ     000000400H
BS_BOTTOM                                       equ     000000800H
BS_VCENTER                                      equ     000000C00H
BS_PUSHLIKE                                     equ     000001000H
BS_MULTILINE                                    equ     000002000H
BS_NOTIFY                                       equ     000004000H
BS_FLAT                                         equ     000008000H
BS_RIGHTBUTTON                                  equ     BS_LEFTTEXT

BN_CLICKED                                      equ     0
BN_PAINT                                        equ     1
BN_HILITE                                       equ     2
BN_UNHILITE                                     equ     3
BN_DISABLE                                      equ     4
BN_DOUBLECLICKED                                equ     5
BN_PUSHED                                       equ     BN_HILITE
BN_UNPUSHED                                     equ     BN_UNHILITE
BN_DBLCLK                                       equ     BN_DOUBLECLICKED
BN_SETFOCUS                                     equ     6
BN_KILLFOCUS                                    equ     7

BM_GETCHECK                                     equ     000F0H
BM_SETCHECK                                     equ     000F1H
BM_GETSTATE                                     equ     000F2H
BM_SETSTATE                                     equ     000F3H
BM_SETSTYLE                                     equ     000F4H
BM_CLICK                                        equ     000F5H
BM_GETIMAGE                                     equ     000F6H
BM_SETIMAGE                                     equ     000F7H
BM_SETDONTCLICK                                 equ     000F8H

BST_UNCHECKED                                   equ     00000H
BST_CHECKED                                     equ     00001H
BST_INDETERMINATE                               equ     00002H
BST_PUSHED                                      equ     00004H
BST_FOCUS                                       equ     00008H

SS_LEFT                                         equ     000000000H
SS_CENTER                                       equ     000000001H
SS_RIGHT                                        equ     000000002H
SS_ICON                                         equ     000000003H
SS_BLACKRECT                                    equ     000000004H
SS_GRAYRECT                                     equ     000000005H
SS_WHITERECT                                    equ     000000006H
SS_BLACKFRAME                                   equ     000000007H
SS_GRAYFRAME                                    equ     000000008H
SS_WHITEFRAME                                   equ     000000009H
SS_USERITEM                                     equ     00000000AH
SS_SIMPLE                                       equ     00000000BH
SS_LEFTNOWORDWRAP                               equ     00000000CH
SS_OWNERDRAW                                    equ     00000000DH
SS_BITMAP                                       equ     00000000EH
SS_ENHMETAFILE                                  equ     00000000FH
SS_ETCHEDHORZ                                   equ     000000010H
SS_ETCHEDVERT                                   equ     000000011H
SS_ETCHEDFRAME                                  equ     000000012H
SS_TYPEMASK                                     equ     00000001FH
SS_REALSIZECONTROL                              equ     000000040H
SS_NOPREFIX                                     equ     000000080H
SS_NOTIFY                                       equ     000000100H
SS_CENTERIMAGE                                  equ     000000200H
SS_RIGHTJUST                                    equ     000000400H
SS_REALSIZEIMAGE                                equ     000000800H
SS_SUNKEN                                       equ     000001000H
SS_ENDELLIPSIS                                  equ     000004000H
SS_PATHELLIPSIS                                 equ     000008000H
SS_WORDELLIPSIS                                 equ     00000C000H
SS_ELLIPSISMASK                                 equ     00000C000H

STM_SETICON                                     equ     00170H
STM_GETICON                                     equ     00171H
STM_SETIMAGE                                    equ     00172H
STM_GETIMAGE                                    equ     00173H

STN_CLICKED                                     equ     0
STN_DBLCLK                                      equ     1
STN_ENABLE                                      equ     2
STN_DISABLE                                     equ     3
STM_MSGMAX                                      equ     00174H

WC_DIALOG                                       equ     08002H

DWL_MSGRESULT                                   equ     0
DWL_DLGPROC                                     equ     4
DWL_USER                                        equ     8

DWLP_MSGRESULT                                  equ     0

DDL_READWRITE                                   equ     00000H
DDL_READONLY                                    equ     00001H
DDL_HIDDEN                                      equ     00002H
DDL_SYSTEM                                      equ     00004H
DDL_DIRECTORY                                   equ     00010H
DDL_ARCHIVE                                     equ     00020H

DDL_POSTMSGS                                    equ     02000H
DDL_DRIVES                                      equ     04000H
DDL_EXCLUSIVE                                   equ     08000H

DS_ABSALIGN                                     equ     001H
DS_SYSMODAL                                     equ     002H
DS_LOCALEDIT                                    equ     020H
DS_SETFONT                                      equ     040H
DS_MODALFRAME                                   equ     080H
DS_NOIDLEMSG                                    equ     0100H
DS_SETFOREGROUND                                equ     0200H

DS_3DLOOK                                       equ     00004H
DS_FIXEDSYS                                     equ     00008H
DS_NOFAILCREATE                                 equ     00010H
DS_CONTROL                                      equ     00400H
DS_CENTER                                       equ     00800H
DS_CENTERMOUSE                                  equ     01000H
DS_CONTEXTHELP                                  equ     02000H

DS_SHELLFONT                                    equ     <DS_SETFONT or DS_FIXEDSYS>

DM_GETDEFID                                     equ     (WM_USER+0)
DM_SETDEFID                                     equ     (WM_USER+1)
DM_REPOSITION                                   equ     (WM_USER+2)

DC_HASDEFID                                     equ     0534BH

DLGC_WANTARROWS                                 equ     00001H
DLGC_WANTTAB                                    equ     00002H
DLGC_WANTALLKEYS                                equ     00004H
DLGC_WANTMESSAGE                                equ     00004H
DLGC_HASSETSEL                                  equ     00008H
DLGC_DEFPUSHBUTTON                              equ     00010H
DLGC_UNDEFPUSHBUTTON                            equ     00020H
DLGC_RADIOBUTTON                                equ     00040H
DLGC_WANTCHARS                                  equ     00080H
DLGC_STATIC                                     equ     00100H
DLGC_BUTTON                                     equ     02000H

LB_CTLCODE                                      equ     0

LB_OKAY                                         equ     0
LB_ERR                                          equ     (-1)
LB_ERRSPACE                                     equ     (-2)

LBN_ERRSPACE                                    equ     (-2)
LBN_SELCHANGE                                   equ     1
LBN_DBLCLK                                      equ     2
LBN_SELCANCEL                                   equ     3
LBN_SETFOCUS                                    equ     4
LBN_KILLFOCUS                                   equ     5

LB_ADDSTRING                                    equ     00180H
LB_INSERTSTRING                                 equ     00181H
LB_DELETESTRING                                 equ     00182H
LB_SELITEMRANGEEX                               equ     00183H
LB_RESETCONTENT                                 equ     00184H
LB_SETSEL                                       equ     00185H
LB_SETCURSEL                                    equ     00186H
LB_GETSEL                                       equ     00187H
LB_GETCURSEL                                    equ     00188H
LB_GETTEXT                                      equ     00189H
LB_GETTEXTLEN                                   equ     0018AH
LB_GETCOUNT                                     equ     0018BH
LB_SELECTSTRING                                 equ     0018CH
LB_DIR                                          equ     0018DH
LB_GETTOPINDEX                                  equ     0018EH
LB_FINDSTRING                                   equ     0018FH
LB_GETSELCOUNT                                  equ     00190H
LB_GETSELITEMS                                  equ     00191H
LB_SETTABSTOPS                                  equ     00192H
LB_GETHORIZONTALEXTENT                          equ     00193H
LB_SETHORIZONTALEXTENT                          equ     00194H
LB_SETCOLUMNWIDTH                               equ     00195H
LB_ADDFILE                                      equ     00196H
LB_SETTOPINDEX                                  equ     00197H
LB_GETITEMRECT                                  equ     00198H
LB_GETITEMDATA                                  equ     00199H
LB_SETITEMDATA                                  equ     0019AH
LB_SELITEMRANGE                                 equ     0019BH
LB_SETANCHORINDEX                               equ     0019CH
LB_GETANCHORINDEX                               equ     0019DH
LB_SETCARETINDEX                                equ     0019EH
LB_GETCARETINDEX                                equ     0019FH
LB_SETITEMHEIGHT                                equ     001A0H
LB_GETITEMHEIGHT                                equ     001A1H
LB_FINDSTRINGEXACT                              equ     001A2H
LBCB_CARETON                                    equ     001A3H
LBCB_CARETOFF                                   equ     001A4H
LB_SETLOCALE                                    equ     001A5H
LB_GETLOCALE                                    equ     001A6H
LB_SETCOUNT                                     equ     001A7H
LB_INITSTORAGE                                  equ     001A8H
LB_ITEMFROMPOINT                                equ     001A9H
LB_INSERTSTRINGUPPER                            equ     001AAH
LB_INSERTSTRINGLOWER                            equ     001ABH
LB_ADDSTRINGUPPER                               equ     001ACH
LB_ADDSTRINGLOWER                               equ     001ADH
LBCB_STARTTRACK                                 equ     001AEH
LBCB_ENDTRACK                                   equ     001AFH
LB_MULTIPLEADDSTRING                            equ     001B1H
LB_GETLISTBOXINFO                               equ     001B2H
LB_MSGMAX                                       equ     001B3H

LBS_NOTIFY                                      equ     00001H
LBS_SORT                                        equ     00002H
LBS_NOREDRAW                                    equ     00004H
LBS_MULTIPLESEL                                 equ     00008H
LBS_OWNERDRAWFIXED                              equ     00010H
LBS_OWNERDRAWVARIABLE                           equ     00020H
LBS_HASSTRINGS                                  equ     00040H
LBS_USETABSTOPS                                 equ     00080H
LBS_NOINTEGRALHEIGHT                            equ     00100H
LBS_MULTICOLUMN                                 equ     00200H
LBS_WANTKEYBOARDINPUT                           equ     00400H
LBS_EXTENDEDSEL                                 equ     00800H
LBS_DISABLENOSCROLL                             equ     01000H
LBS_NODATA                                      equ     02000H
LBS_NOSEL                                       equ     04000H
LBS_STANDARD                                    equ     <LBS_NOTIFY or LBS_SORT or WS_VSCROLL or WS_BORDER>

CB_OKAY                                         equ     0
CB_ERR                                          equ     (-1)
CB_ERRSPACE                                     equ     (-2)

CBN_ERRSPACE                                    equ     (-1)
CBN_SELCHANGE                                   equ     1
CBN_DBLCLK                                      equ     2
CBN_SETFOCUS                                    equ     3
CBN_KILLFOCUS                                   equ     4
CBN_EDITCHANGE                                  equ     5
CBN_EDITUPDATE                                  equ     6
CBN_DROPDOWN                                    equ     7
CBN_CLOSEUP                                     equ     8
CBN_SELENDOK                                    equ     9
CBN_SELENDCANCEL                                equ     10

CBS_SIMPLE                                      equ     00001H
CBS_DROPDOWN                                    equ     00002H
CBS_DROPDOWNLIST                                equ     00003H
CBS_OWNERDRAWFIXED                              equ     00010H
CBS_OWNERDRAWVARIABLE                           equ     00020H
CBS_AUTOHSCROLL                                 equ     00040H
CBS_OEMCONVERT                                  equ     00080H
CBS_SORT                                        equ     00100H
CBS_HASSTRINGS                                  equ     00200H
CBS_NOINTEGRALHEIGHT                            equ     00400H
CBS_DISABLENOSCROLL                             equ     00800H
CBS_UPPERCASE                                   equ     02000H
CBS_LOWERCASE                                   equ     04000H

CB_GETEDITSEL                                   equ     00140H
CB_LIMITTEXT                                    equ     00141H
CB_SETEDITSEL                                   equ     00142H
CB_ADDSTRING                                    equ     00143H
CB_DIR                                          equ     00145H
CB_GETCOUNT                                     equ     00146H
CB_GETCURSEL                                    equ     00147H
CB_GETLBTEXT                                    equ     00148H
CB_GETLBTEXTLEN                                 equ     00149H
CB_INSERTSTRING                                 equ     0014AH
CB_RESETCONTENT                                 equ     0014BH
CB_FINDSTRING                                   equ     0014CH
CB_SELECTSTRING                                 equ     0014DH
CB_SETCURSEL                                    equ     0014EH
CB_SHOWDROPDOWN                                 equ     0014FH
CB_GETITEMDATA                                  equ     00150H
CB_SETITEMDATA                                  equ     00151H
CB_GETDROPPEDCONTROLRECT                        equ     00152H
CB_SETITEMHEIGHT                                equ     00153H
CB_GETITEMHEIGHT                                equ     00154H
CB_SETEXTENDEDUI                                equ     00155H
CB_GETEXTENDEDUI                                equ     00156H
CB_GETDROPPEDSTATE                              equ     00157H
CB_FINDSTRINGEXACT                              equ     00158H
CB_SETLOCALE                                    equ     00159H
CB_GETLOCALE                                    equ     0015AH
CB_GETTOPINDEX                                  equ     0015BH
CB_SETTOPINDEX                                  equ     0015CH
CB_GETHORIZONTALEXTENT                          equ     0015DH
CB_SETHORIZONTALEXTENT                          equ     0015EH
CB_GETDROPPEDWIDTH                              equ     0015FH
CB_SETDROPPEDWIDTH                              equ     00160H
CB_INITSTORAGE                                  equ     00161H
CB_MULTIPLEADDSTRING                            equ     00163H
CB_GETCOMBOBOXINFO                              equ     00164H
CB_MSGMAX                                       equ     00165H

SBS_HORZ                                        equ     00000H
SBS_VERT                                        equ     00001H
SBS_TOPALIGN                                    equ     00002H
SBS_LEFTALIGN                                   equ     00002H
SBS_BOTTOMALIGN                                 equ     00004H
SBS_RIGHTALIGN                                  equ     00004H
SBS_SIZEBOXTOPLEFTALIGN                         equ     00002H
SBS_SIZEBOXBOTTOMRIGHTALIGN                     equ     00004H
SBS_SIZEBOX                                     equ     00008H
SBS_SIZEGRIP                                    equ     00010H

SBM_SETPOS                                      equ     000E0H
SBM_GETPOS                                      equ     000E1H
SBM_SETRANGE                                    equ     000E2H
SBM_SETRANGEREDRAW                              equ     000E6H
SBM_GETRANGE                                    equ     000E3H
SBM_ENABLE_ARROWS                               equ     000E4H
SBM_SETSCROLLINFO                               equ     000E9H
SBM_GETSCROLLINFO                               equ     000EAH
SBM_GETSCROLLBARINFO                            equ     000EBH

SIF_RANGE                                       equ     00001H
SIF_PAGE                                        equ     00002H
SIF_POS                                         equ     00004H
SIF_DISABLENOSCROLL                             equ     00008H
SIF_TRACKPOS                                    equ     00010H
SIF_ALL                                         equ     <SIF_RANGE or SIF_PAGE or SIF_POS or SIF_TRACKPOS>

MDIS_ALLCHILDSTYLES                             equ     00001H

MDITILE_VERTICAL                                equ     00000H
MDITILE_HORIZONTAL                              equ     00001H
MDITILE_SKIPDISABLED                            equ     00002H
MDITILE_ZORDER                                  equ     00004H

HELP_CONTEXT                                    equ     00001H
HELP_QUIT                                       equ     00002H
HELP_INDEX                                      equ     00003H
HELP_CONTENTS                                   equ     00003H
HELP_HELPONHELP                                 equ     00004H
HELP_SETINDEX                                   equ     00005H
HELP_SETCONTENTS                                equ     00005H
HELP_CONTEXTPOPUP                               equ     00008H
HELP_FORCEFILE                                  equ     00009H
HELP_KEY                                        equ     00101H
HELP_COMMAND                                    equ     00102H
HELP_PARTIALKEY                                 equ     00105H
HELP_MULTIKEY                                   equ     00201H
HELP_SETWINPOS                                  equ     00203H
HELP_CONTEXTMENU                                equ     0000AH
HELP_FINDER                                     equ     0000BH
HELP_WM_HELP                                    equ     0000CH
HELP_SETPOPUP_POS                               equ     0000DH

HELP_TCARD                                      equ     08000H
HELP_TCARD_DATA                                 equ     00010H
HELP_TCARD_OTHER_CALLER                         equ     00011H

IDH_NO_HELP                                     equ     28440
IDH_MISSING_CONTEXT                             equ     28441
IDH_GENERIC_HELP_BUTTON                         equ     28442
IDH_OK                                          equ     28443
IDH_CANCEL                                      equ     28444
IDH_HELP                                        equ     28445

GR_GDIOBJECTS                                   equ     0
GR_USEROBJECTS                                  equ     1
GR_GDIOBJECTS_PEAK                              equ     2
GR_USEROBJECTS_PEAK                             equ     4

GR_GLOBAL                                       equ     (-2)

SPI_GETBEEP                                     equ     1
SPI_SETBEEP                                     equ     2
SPI_GETMOUSE                                    equ     3
SPI_SETMOUSE                                    equ     4
SPI_GETBORDER                                   equ     5
SPI_SETBORDER                                   equ     6
SPI_GETKEYBOARDSPEED                            equ     10
SPI_SETKEYBOARDSPEED                            equ     11
SPI_LANGDRIVER                                  equ     12
SPI_ICONHORIZONTALSPACING                       equ     13
SPI_GETSCREENSAVETIMEOUT                        equ     14
SPI_SETSCREENSAVETIMEOUT                        equ     15
SPI_GETSCREENSAVEACTIVE                         equ     16
SPI_SETSCREENSAVEACTIVE                         equ     17
SPI_GETGRIDGRANULARITY                          equ     18
SPI_SETGRIDGRANULARITY                          equ     19
SPI_SETDESKWALLPAPER                            equ     20
SPI_SETDESKPATTERN                              equ     21
SPI_GETKEYBOARDDELAY                            equ     22
SPI_SETKEYBOARDDELAY                            equ     23
SPI_ICONVERTICALSPACING                         equ     24
SPI_GETICONTITLEWRAP                            equ     25
SPI_SETICONTITLEWRAP                            equ     26
SPI_GETMENUDROPALIGNMENT                        equ     27
SPI_SETMENUDROPALIGNMENT                        equ     28
SPI_SETDOUBLECLKWIDTH                           equ     29
SPI_SETDOUBLECLKHEIGHT                          equ     30
SPI_GETICONTITLELOGFONT                         equ     31
SPI_SETDOUBLECLICKTIME                          equ     32
SPI_SETMOUSEBUTTONSWAP                          equ     33
SPI_SETICONTITLELOGFONT                         equ     34
SPI_GETFASTTASKSWITCH                           equ     35
SPI_SETFASTTASKSWITCH                           equ     36
SPI_SETDRAGFULLWINDOWS                          equ     37
SPI_GETDRAGFULLWINDOWS                          equ     38
SPI_GETNONCLIENTMETRICS                         equ     41
SPI_SETNONCLIENTMETRICS                         equ     42
SPI_GETMINIMIZEDMETRICS                         equ     43
SPI_SETMINIMIZEDMETRICS                         equ     44
SPI_GETICONMETRICS                              equ     45
SPI_SETICONMETRICS                              equ     46
SPI_SETWORKAREA                                 equ     47
SPI_GETWORKAREA                                 equ     48
SPI_SETPENWINDOWS                               equ     49
SPI_GETFILTERKEYS                               equ     50
SPI_SETFILTERKEYS                               equ     51
SPI_GETTOGGLEKEYS                               equ     52
SPI_SETTOGGLEKEYS                               equ     53
SPI_GETMOUSEKEYS                                equ     54
SPI_SETMOUSEKEYS                                equ     55
SPI_GETSHOWSOUNDS                               equ     56
SPI_SETSHOWSOUNDS                               equ     57
SPI_GETSTICKYKEYS                               equ     58
SPI_SETSTICKYKEYS                               equ     59
SPI_GETACCESSTIMEOUT                            equ     60
SPI_SETACCESSTIMEOUT                            equ     61
SPI_GETSERIALKEYS                               equ     62
SPI_SETSERIALKEYS                               equ     63
SPI_GETSOUNDSENTRY                              equ     64
SPI_SETSOUNDSENTRY                              equ     65
SPI_GETHIGHCONTRAST                             equ     66
SPI_SETHIGHCONTRAST                             equ     67
SPI_GETKEYBOARDPREF                             equ     68
SPI_SETKEYBOARDPREF                             equ     69
SPI_GETSCREENREADER                             equ     70
SPI_SETSCREENREADER                             equ     71
SPI_GETANIMATION                                equ     72
SPI_SETANIMATION                                equ     73
SPI_GETFONTSMOOTHING                            equ     74
SPI_SETFONTSMOOTHING                            equ     75
SPI_SETDRAGWIDTH                                equ     76
SPI_SETDRAGHEIGHT                               equ     77
SPI_SETHANDHELD                                 equ     78
SPI_GETLOWPOWERTIMEOUT                          equ     79
SPI_GETPOWEROFFTIMEOUT                          equ     80
SPI_SETLOWPOWERTIMEOUT                          equ     81
SPI_SETPOWEROFFTIMEOUT                          equ     82
SPI_GETLOWPOWERACTIVE                           equ     83
SPI_GETPOWEROFFACTIVE                           equ     84
SPI_SETLOWPOWERACTIVE                           equ     85
SPI_SETPOWEROFFACTIVE                           equ     86
SPI_SETCURSORS                                  equ     87
SPI_SETICONS                                    equ     88
SPI_GETDEFAULTINPUTLANG                         equ     89
SPI_SETDEFAULTINPUTLANG                         equ     90
SPI_SETLANGTOGGLE                               equ     91
SPI_GETWINDOWSEXTENSION                         equ     92
SPI_SETMOUSETRAILS                              equ     93
SPI_GETMOUSETRAILS                              equ     94
SPI_GETSNAPTODEFBUTTON                          equ     95
SPI_SETSNAPTODEFBUTTON                          equ     96
SPI_SETSCREENSAVERRUNNING                       equ     97
SPI_SCREENSAVERRUNNING                          equ     SPI_SETSCREENSAVERRUNNING
SPI_GETMOUSEHOVERWIDTH                          equ     98
SPI_SETMOUSEHOVERWIDTH                          equ     99
SPI_GETMOUSEHOVERHEIGHT                         equ     100
SPI_SETMOUSEHOVERHEIGHT                         equ     101
SPI_GETMOUSEHOVERTIME                           equ     102
SPI_SETMOUSEHOVERTIME                           equ     103
SPI_GETWHEELSCROLLLINES                         equ     104
SPI_SETWHEELSCROLLLINES                         equ     105
SPI_GETMENUSHOWDELAY                            equ     106
SPI_SETMENUSHOWDELAY                            equ     107
SPI_GETSHOWIMEUI                                equ     110
SPI_SETSHOWIMEUI                                equ     111
SPI_GETMOUSESPEED                               equ     112
SPI_SETMOUSESPEED                               equ     113
SPI_GETSCREENSAVERRUNNING                       equ     114
SPI_GETDESKWALLPAPER                            equ     115
SPI_GETACTIVEWINDOWTRACKING                     equ     01000H
SPI_SETACTIVEWINDOWTRACKING                     equ     01001H
SPI_GETMENUANIMATION                            equ     01002H
SPI_SETMENUANIMATION                            equ     01003H
SPI_GETCOMBOBOXANIMATION                        equ     01004H
SPI_SETCOMBOBOXANIMATION                        equ     01005H
SPI_GETLISTBOXSMOOTHSCROLLING                   equ     01006H
SPI_SETLISTBOXSMOOTHSCROLLING                   equ     01007H
SPI_GETGRADIENTCAPTIONS                         equ     01008H
SPI_SETGRADIENTCAPTIONS                         equ     01009H
SPI_GETKEYBOARDCUES                             equ     0100AH
SPI_SETKEYBOARDCUES                             equ     0100BH
SPI_GETMENUUNDERLINES                           equ     SPI_GETKEYBOARDCUES
SPI_SETMENUUNDERLINES                           equ     SPI_SETKEYBOARDCUES
SPI_GETACTIVEWNDTRKZORDER                       equ     0100CH
SPI_SETACTIVEWNDTRKZORDER                       equ     0100DH
SPI_GETHOTTRACKING                              equ     0100EH
SPI_SETHOTTRACKING                              equ     0100FH
SPI_GETMENUFADE                                 equ     01012H
SPI_SETMENUFADE                                 equ     01013H
SPI_GETSELECTIONFADE                            equ     01014H
SPI_SETSELECTIONFADE                            equ     01015H
SPI_GETTOOLTIPANIMATION                         equ     01016H
SPI_SETTOOLTIPANIMATION                         equ     01017H
SPI_GETTOOLTIPFADE                              equ     01018H
SPI_SETTOOLTIPFADE                              equ     01019H
SPI_GETCURSORSHADOW                             equ     0101AH
SPI_SETCURSORSHADOW                             equ     0101BH
SPI_GETMOUSESONAR                               equ     0101CH
SPI_SETMOUSESONAR                               equ     0101DH
SPI_GETMOUSECLICKLOCK                           equ     0101EH
SPI_SETMOUSECLICKLOCK                           equ     0101FH
SPI_GETMOUSEVANISH                              equ     01020H
SPI_SETMOUSEVANISH                              equ     01021H
SPI_GETFLATMENU                                 equ     01022H
SPI_SETFLATMENU                                 equ     01023H
SPI_GETDROPSHADOW                               equ     01024H
SPI_SETDROPSHADOW                               equ     01025H
SPI_GETBLOCKSENDINPUTRESETS                     equ     01026H
SPI_SETBLOCKSENDINPUTRESETS                     equ     01027H
SPI_GETUIEFFECTS                                equ     0103EH
SPI_SETUIEFFECTS                                equ     0103FH
SPI_GETDISABLEOVERLAPPEDCONTENT                 equ     01040H
SPI_SETDISABLEOVERLAPPEDCONTENT                 equ     01041H
SPI_GETCLIENTAREAANIMATION                      equ     01042H
SPI_SETCLIENTAREAANIMATION                      equ     01043H
SPI_GETCLEARTYPE                                equ     01048H
SPI_SETCLEARTYPE                                equ     01049H
SPI_GETSPEECHRECOGNITION                        equ     0104AH
SPI_SETSPEECHRECOGNITION                        equ     0104BH
SPI_GETCARETBROWSING                            equ     0104CH
SPI_SETCARETBROWSING                            equ     0104DH
SPI_GETTHREADLOCALINPUTSETTINGS                 equ     0104EH
SPI_SETTHREADLOCALINPUTSETTINGS                 equ     0104FH
SPI_GETSYSTEMLANGUAGEBAR                        equ     01050H
SPI_SETSYSTEMLANGUAGEBAR                        equ     01051H
SPI_GETFOREGROUNDLOCKTIMEOUT                    equ     02000H
SPI_SETFOREGROUNDLOCKTIMEOUT                    equ     02001H
SPI_GETACTIVEWNDTRKTIMEOUT                      equ     02002H
SPI_SETACTIVEWNDTRKTIMEOUT                      equ     02003H
SPI_GETFOREGROUNDFLASHCOUNT                     equ     02004H
SPI_SETFOREGROUNDFLASHCOUNT                     equ     02005H
SPI_GETCARETWIDTH                               equ     02006H
SPI_SETCARETWIDTH                               equ     02007H
SPI_GETMOUSECLICKLOCKTIME                       equ     02008H
SPI_SETMOUSECLICKLOCKTIME                       equ     02009H
SPI_GETFONTSMOOTHINGTYPE                        equ     0200AH
SPI_SETFONTSMOOTHINGTYPE                        equ     0200BH
SPI_GETFONTSMOOTHINGCONTRAST                    equ     0200CH
SPI_SETFONTSMOOTHINGCONTRAST                    equ     0200DH
SPI_GETFOCUSBORDERWIDTH                         equ     0200EH
SPI_SETFOCUSBORDERWIDTH                         equ     0200FH
SPI_GETFOCUSBORDERHEIGHT                        equ     02010H
SPI_SETFOCUSBORDERHEIGHT                        equ     02011H
SPI_GETFONTSMOOTHINGORIENTATION                 equ     02012H
SPI_SETFONTSMOOTHINGORIENTATION                 equ     02013H
SPI_GETMINIMUMHITRADIUS                         equ     02014H
SPI_SETMINIMUMHITRADIUS                         equ     02015H
SPI_GETMESSAGEDURATION                          equ     02016H
SPI_SETMESSAGEDURATION                          equ     02017H
SPI_GETCONTACTVISUALIZATION                     equ     02018H
SPI_SETCONTACTVISUALIZATION                     equ     02019H

SPIF_UPDATEINIFILE                              equ     00001H
SPIF_SENDWININICHANGE                           equ     00002H
SPIF_SENDCHANGE                                 equ     SPIF_SENDWININICHANGE

MAX_TOUCH_PREDICTION_FILTER_TAPS                equ     3

METRICS_USEDEFAULT                              equ     (-1)

ARW_BOTTOMLEFT                                  equ     00000H
ARW_BOTTOMRIGHT                                 equ     00001H
ARW_TOPLEFT                                     equ     00002H
ARW_TOPRIGHT                                    equ     00003H
ARW_STARTMASK                                   equ     00003H
ARW_STARTRIGHT                                  equ     00001H
ARW_STARTTOP                                    equ     00002H

ARW_LEFT                                        equ     00000H
ARW_RIGHT                                       equ     00000H
ARW_UP                                          equ     00004H
ARW_DOWN                                        equ     00004H
ARW_HIDE                                        equ     00008H

SERKF_SERIALKEYSON                              equ     000000001H
SERKF_AVAILABLE                                 equ     000000002H
SERKF_INDICATOR                                 equ     000000004H

HCF_HIGHCONTRASTON                              equ     000000001H
HCF_AVAILABLE                                   equ     000000002H
HCF_HOTKEYACTIVE                                equ     000000004H
HCF_CONFIRMHOTKEY                               equ     000000008H
HCF_HOTKEYSOUND                                 equ     000000010H
HCF_INDICATOR                                   equ     000000020H
HCF_HOTKEYAVAILABLE                             equ     000000040H

CDS_UPDATEREGISTRY                              equ     000000001H
CDS_TEST                                        equ     000000002H
CDS_FULLSCREEN                                  equ     000000004H
CDS_GLOBAL                                      equ     000000008H
CDS_SET_PRIMARY                                 equ     000000010H
CDS_VIDEOPARAMETERS                             equ     000000020H
CDS_ENABLE_UNSAFE_MODES                         equ     000000100H
CDS_DISABLE_UNSAFE_MODES                        equ     000000200H

CDS_RESET                                       equ     040000000H
CDS_SETRECT                                     equ     020000000H
CDS_NORESET                                     equ     010000000H

DISP_CHANGE_SUCCESSFUL                          equ     0
DISP_CHANGE_RESTART                             equ     1
DISP_CHANGE_FAILED                              equ     (-1)
DISP_CHANGE_BADMODE                             equ     (-2)
DISP_CHANGE_NOTUPDATED                          equ     (-3)
DISP_CHANGE_BADFLAGS                            equ     (-4)
DISP_CHANGE_BADPARAM                            equ     (-5)
DISP_CHANGE_BADDUALVIEW                         equ     (-6)

ENUM_CURRENT_SETTINGS                           equ     (-1)
ENUM_REGISTRY_SETTINGS                          equ     (-2)

FKF_FILTERKEYSON                                equ     000000001H
FKF_AVAILABLE                                   equ     000000002H
FKF_HOTKEYACTIVE                                equ     000000004H
FKF_CONFIRMHOTKEY                               equ     000000008H
FKF_HOTKEYSOUND                                 equ     000000010H
FKF_INDICATOR                                   equ     000000020H
FKF_CLICKON                                     equ     000000040H

SKF_STICKYKEYSON                                equ     000000001H
SKF_AVAILABLE                                   equ     000000002H
SKF_HOTKEYACTIVE                                equ     000000004H
SKF_CONFIRMHOTKEY                               equ     000000008H
SKF_HOTKEYSOUND                                 equ     000000010H
SKF_INDICATOR                                   equ     000000020H
SKF_AUDIBLEFEEDBACK                             equ     000000040H
SKF_TRISTATE                                    equ     000000080H
SKF_TWOKEYSOFF                                  equ     000000100H
SKF_LALTLATCHED                                 equ     010000000H
SKF_LCTLLATCHED                                 equ     004000000H
SKF_LSHIFTLATCHED                               equ     001000000H
SKF_RALTLATCHED                                 equ     020000000H
SKF_RCTLLATCHED                                 equ     008000000H
SKF_RSHIFTLATCHED                               equ     002000000H
SKF_LWINLATCHED                                 equ     040000000H
SKF_RWINLATCHED                                 equ     080000000H
SKF_LALTLOCKED                                  equ     000100000H
SKF_LCTLLOCKED                                  equ     000040000H
SKF_LSHIFTLOCKED                                equ     000010000H
SKF_RALTLOCKED                                  equ     000200000H
SKF_RCTLLOCKED                                  equ     000080000H
SKF_RSHIFTLOCKED                                equ     000020000H
SKF_LWINLOCKED                                  equ     000400000H
SKF_RWINLOCKED                                  equ     000800000H

MKF_MOUSEKEYSON                                 equ     000000001H
MKF_AVAILABLE                                   equ     000000002H
MKF_HOTKEYACTIVE                                equ     000000004H
MKF_CONFIRMHOTKEY                               equ     000000008H
MKF_HOTKEYSOUND                                 equ     000000010H
MKF_INDICATOR                                   equ     000000020H
MKF_MODIFIERS                                   equ     000000040H
MKF_REPLACENUMBERS                              equ     000000080H
MKF_LEFTBUTTONSEL                               equ     010000000H
MKF_RIGHTBUTTONSEL                              equ     020000000H
MKF_LEFTBUTTONDOWN                              equ     001000000H
MKF_RIGHTBUTTONDOWN                             equ     002000000H
MKF_MOUSEMODE                                   equ     080000000H

ATF_TIMEOUTON                                   equ     000000001H
ATF_ONOFFFEEDBACK                               equ     000000002H

SSGF_NONE                                       equ     0
SSGF_DISPLAY                                    equ     3

SSTF_NONE                                       equ     0
SSTF_CHARS                                      equ     1
SSTF_BORDER                                     equ     2
SSTF_DISPLAY                                    equ     3

SSWF_NONE                                       equ     0
SSWF_TITLE                                      equ     1
SSWF_WINDOW                                     equ     2
SSWF_DISPLAY                                    equ     3
SSWF_CUSTOM                                     equ     4

SSF_SOUNDSENTRYON                               equ     000000001H
SSF_AVAILABLE                                   equ     000000002H
SSF_INDICATOR                                   equ     000000004H

TKF_TOGGLEKEYSON                                equ     000000001H
TKF_AVAILABLE                                   equ     000000002H
TKF_HOTKEYACTIVE                                equ     000000004H
TKF_CONFIRMHOTKEY                               equ     000000008H
TKF_HOTKEYSOUND                                 equ     000000010H
TKF_INDICATOR                                   equ     000000020H

SLE_ERROR                                       equ     000000001H
SLE_MINORERROR                                  equ     000000002H
SLE_WARNING                                     equ     000000003H

MONITOR_DEFAULTTONULL                           equ     000000000H
MONITOR_DEFAULTTOPRIMARY                        equ     000000001H
MONITOR_DEFAULTTONEAREST                        equ     000000002H
MONITORINFOF_PRIMARY                            equ     000000001H

WINEVENT_OUTOFCONTEXT                           equ     00000H
WINEVENT_SKIPOWNTHREAD                          equ     00001H
WINEVENT_SKIPOWNPROCESS                         equ     00002H
WINEVENT_INCONTEXT                              equ     00004H

CHILDID_SELF                                    equ     0
INDEXID_OBJECT                                  equ     0
INDEXID_CONTAINER                               equ     0

OBJID_WINDOW                                    equ     000000000H
OBJID_SYSMENU                                   equ     0FFFFFFFFH
OBJID_TITLEBAR                                  equ     0FFFFFFFEH
OBJID_MENU                                      equ     0FFFFFFFDH
OBJID_CLIENT                                    equ     0FFFFFFFCH
OBJID_VSCROLL                                   equ     0FFFFFFFBH
OBJID_HSCROLL                                   equ     0FFFFFFFAH
OBJID_SIZEGRIP                                  equ     0FFFFFFF9H
OBJID_CARET                                     equ     0FFFFFFF8H
OBJID_CURSOR                                    equ     0FFFFFFF7H
OBJID_ALERT                                     equ     0FFFFFFF6H
OBJID_SOUND                                     equ     0FFFFFFF5H
OBJID_QUERYCLASSNAMEIDX                         equ     0FFFFFFF4H
OBJID_NATIVEOM                                  equ     0FFFFFFF0H

EVENT_MIN                                       equ     000000001H
EVENT_MAX                                       equ     07FFFFFFFH

EVENT_SYSTEM_SOUND                              equ     00001H
EVENT_SYSTEM_ALERT                              equ     00002H
EVENT_SYSTEM_FOREGROUND                         equ     00003H
EVENT_SYSTEM_MENUSTART                          equ     00004H
EVENT_SYSTEM_MENUEND                            equ     00005H
EVENT_SYSTEM_MENUPOPUPSTART                     equ     00006H
EVENT_SYSTEM_MENUPOPUPEND                       equ     00007H
EVENT_SYSTEM_CAPTURESTART                       equ     00008H
EVENT_SYSTEM_CAPTUREEND                         equ     00009H
EVENT_SYSTEM_MOVESIZESTART                      equ     0000AH
EVENT_SYSTEM_MOVESIZEEND                        equ     0000BH
EVENT_SYSTEM_CONTEXTHELPSTART                   equ     0000CH
EVENT_SYSTEM_CONTEXTHELPEND                     equ     0000DH
EVENT_SYSTEM_DRAGDROPSTART                      equ     0000EH
EVENT_SYSTEM_DRAGDROPEND                        equ     0000FH
EVENT_SYSTEM_DIALOGSTART                        equ     00010H
EVENT_SYSTEM_DIALOGEND                          equ     00011H
EVENT_SYSTEM_SCROLLINGSTART                     equ     00012H
EVENT_SYSTEM_SCROLLINGEND                       equ     00013H
EVENT_SYSTEM_SWITCHSTART                        equ     00014H
EVENT_SYSTEM_SWITCHEND                          equ     00015H
EVENT_SYSTEM_MINIMIZESTART                      equ     00016H
EVENT_SYSTEM_MINIMIZEEND                        equ     00017H
EVENT_SYSTEM_DESKTOPSWITCH                      equ     00020H
EVENT_SYSTEM_END                                equ     000FFH

EVENT_OEM_DEFINED_START                         equ     00101H
EVENT_OEM_DEFINED_END                           equ     001FFH

EVENT_UIA_EVENTID_START                         equ     04E00H
EVENT_UIA_EVENTID_END                           equ     04EFFH
EVENT_UIA_PROPID_START                          equ     07500H
EVENT_UIA_PROPID_END                            equ     075FFH

EVENT_CONSOLE_CARET                             equ     04001H
EVENT_CONSOLE_UPDATE_REGION                     equ     04002H
EVENT_CONSOLE_UPDATE_SIMPLE                     equ     04003H
EVENT_CONSOLE_UPDATE_SCROLL                     equ     04004H
EVENT_CONSOLE_LAYOUT                            equ     04005H
EVENT_CONSOLE_START_APPLICATION                 equ     04006H
EVENT_CONSOLE_END_APPLICATION                   equ     04007H
EVENT_CONSOLE_END                               equ     040FFH

#ifdef APP_WIN64
    CONSOLE_APPLICATION_16BIT                   equ     00000H
#else
    CONSOLE_APPLICATION_16BIT                   equ     00001H
#endif

EVENT_OBJECT_CREATE                             equ     08000H
EVENT_OBJECT_DESTROY                            equ     08001H
EVENT_OBJECT_SHOW                               equ     08002H
EVENT_OBJECT_HIDE                               equ     08003H
EVENT_OBJECT_REORDER                            equ     08004H
EVENT_OBJECT_FOCUS                              equ     08005H
EVENT_OBJECT_SELECTION                          equ     08006H
EVENT_OBJECT_SELECTIONADD                       equ     08007H
EVENT_OBJECT_SELECTIONREMOVE                    equ     08008H
EVENT_OBJECT_SELECTIONWITHIN                    equ     08009H
EVENT_OBJECT_STATECHANGE                        equ     0800AH
EVENT_OBJECT_LOCATIONCHANGE                     equ     0800BH
EVENT_OBJECT_NAMECHANGE                         equ     0800CH
EVENT_OBJECT_DESCRIPTIONCHANGE                  equ     0800DH
EVENT_OBJECT_VALUECHANGE                        equ     0800EH
EVENT_OBJECT_PARENTCHANGE                       equ     0800FH
EVENT_OBJECT_HELPCHANGE                         equ     08010H
EVENT_OBJECT_DEFACTIONCHANGE                    equ     08011H
EVENT_OBJECT_ACCELERATORCHANGE                  equ     08012H
EVENT_OBJECT_INVOKED                            equ     08013H
EVENT_OBJECT_TEXTSELECTIONCHANGED               equ     08014H
EVENT_OBJECT_CONTENTSCROLLED                    equ     08015H
EVENT_SYSTEM_ARRANGMENTPREVIEW                  equ     08016H

EVENT_OBJECT_CLOAKED                            equ     08017H
EVENT_OBJECT_UNCLOAKED                          equ     08018H
EVENT_OBJECT_LIVEREGIONCHANGED                  equ     08019H
EVENT_OBJECT_HOSTEDOBJECTSINVALIDATED           equ     08020H

EVENT_OBJECT_END                                equ     080FFH

EVENT_AIA_START                                 equ     0A000H
EVENT_AIA_END                                   equ     0AFFFH

SOUND_SYSTEM_STARTUP                            equ     1
SOUND_SYSTEM_SHUTDOWN                           equ     2
SOUND_SYSTEM_BEEP                               equ     3
SOUND_SYSTEM_ERROR                              equ     4
SOUND_SYSTEM_QUESTION                           equ     5
SOUND_SYSTEM_WARNING                            equ     6
SOUND_SYSTEM_INFORMATION                        equ     7
SOUND_SYSTEM_MAXIMIZE                           equ     8
SOUND_SYSTEM_MINIMIZE                           equ     9
SOUND_SYSTEM_RESTOREUP                          equ     10
SOUND_SYSTEM_RESTOREDOWN                        equ     11
SOUND_SYSTEM_APPSTART                           equ     12
SOUND_SYSTEM_FAULT                              equ     13
SOUND_SYSTEM_APPEND                             equ     14
SOUND_SYSTEM_MENUCOMMAND                        equ     15
SOUND_SYSTEM_MENUPOPUP                          equ     16
CSOUND_SYSTEM                                   equ     16

ALERT_SYSTEM_INFORMATIONAL                      equ     1
ALERT_SYSTEM_WARNING                            equ     2
ALERT_SYSTEM_ERROR                              equ     3
ALERT_SYSTEM_QUERY                              equ     4
ALERT_SYSTEM_CRITICAL                           equ     5
CALERT_SYSTEM                                   equ     6

USER_DEFAULT_SCREEN_DPI                         equ     96

GUI_CARETBLINKING                               equ     000000001H
GUI_INMOVESIZE                                  equ     000000002H
GUI_INMENUMODE                                  equ     000000004H
GUI_SYSTEMMENUMODE                              equ     000000008H
GUI_POPUPMENUMODE                               equ     000000010H

#ifdef APP_WIN64
    GUI_16BITTASK                               equ     000000000H
#else
    GUI_16BITTASK                               equ     000000020H
#endif

STATE_SYSTEM_UNAVAILABLE                        equ     000000001H
STATE_SYSTEM_SELECTED                           equ     000000002H
STATE_SYSTEM_FOCUSED                            equ     000000004H
STATE_SYSTEM_PRESSED                            equ     000000008H
STATE_SYSTEM_CHECKED                            equ     000000010H
STATE_SYSTEM_MIXED                              equ     000000020H
STATE_SYSTEM_INDETERMINATE                      equ     000000020H
STATE_SYSTEM_READONLY                           equ     000000040H
STATE_SYSTEM_HOTTRACKED                         equ     000000080H
STATE_SYSTEM_DEFAULT                            equ     000000100H
STATE_SYSTEM_EXPANDED                           equ     000000200H
STATE_SYSTEM_COLLAPSED                          equ     000000400H
STATE_SYSTEM_BUSY                               equ     000000800H
STATE_SYSTEM_FLOATING                           equ     000001000H
STATE_SYSTEM_MARQUEED                           equ     000002000H
STATE_SYSTEM_ANIMATED                           equ     000004000H
STATE_SYSTEM_INVISIBLE                          equ     000008000H
STATE_SYSTEM_OFFSCREEN                          equ     000010000H
STATE_SYSTEM_SIZEABLE                           equ     000020000H
STATE_SYSTEM_MOVEABLE                           equ     000040000H
STATE_SYSTEM_SELFVOICING                        equ     000080000H
STATE_SYSTEM_FOCUSABLE                          equ     000100000H
STATE_SYSTEM_SELECTABLE                         equ     000200000H
STATE_SYSTEM_LINKED                             equ     000400000H
STATE_SYSTEM_TRAVERSED                          equ     000800000H
STATE_SYSTEM_MULTISELECTABLE                    equ     001000000H
STATE_SYSTEM_EXTSELECTABLE                      equ     002000000H
STATE_SYSTEM_ALERT_LOW                          equ     004000000H
STATE_SYSTEM_ALERT_MEDIUM                       equ     008000000H
STATE_SYSTEM_ALERT_HIGH                         equ     010000000H
STATE_SYSTEM_PROTECTED                          equ     020000000H
STATE_SYSTEM_VALID                              equ     01FFFFFFFH

CURSOR_SHOWING                                  equ     000000001H
CURSOR_SUPPRESSED                               equ     000000002H

WS_ACTIVECAPTION                                equ     00001H

WTS_CONSOLE_CONNECT                             equ     01H
WTS_CONSOLE_DISCONNECT                          equ     02H
WTS_REMOTE_CONNECT                              equ     03H
WTS_REMOTE_DISCONNECT                           equ     04H
WTS_SESSION_LOGON                               equ     05H
WTS_SESSION_LOGOFF                              equ     06H
WTS_SESSION_LOCK                                equ     07H
WTS_SESSION_UNLOCK                              equ     08H
WTS_SESSION_REMOTE_CONTROL                      equ     09H

GA_MIC                                          equ     1
GA_PARENT                                       equ     1
GA_ROOT                                         equ     2
GA_ROOTOWNER                                    equ     3
GA_MAC                                          equ     4

RIM_INPUT                                       equ     0
RIM_INPUTSINK                                   equ     1
RIM_TYPEMOUSE                                   equ     0
RIM_TYPEKEYBOARD                                equ     1
RIM_TYPEHID                                     equ     2

RI_MOUSE_LEFT_BUTTON_DOWN                       equ     00001H
RI_MOUSE_LEFT_BUTTON_UP                         equ     00002H
RI_MOUSE_RIGHT_BUTTON_DOWN                      equ     00004H
RI_MOUSE_RIGHT_BUTTON_UP                        equ     00008H
RI_MOUSE_MIDDLE_BUTTON_DOWN                     equ     00010H
RI_MOUSE_MIDDLE_BUTTON_UP                       equ     00020H

RI_MOUSE_BUTTON_1_DOWN                          equ     RI_MOUSE_LEFT_BUTTON_DOWN
RI_MOUSE_BUTTON_1_UP                            equ     RI_MOUSE_LEFT_BUTTON_UP
RI_MOUSE_BUTTON_2_DOWN                          equ     RI_MOUSE_RIGHT_BUTTON_DOWN
RI_MOUSE_BUTTON_2_UP                            equ     RI_MOUSE_RIGHT_BUTTON_UP
RI_MOUSE_BUTTON_3_DOWN                          equ     RI_MOUSE_MIDDLE_BUTTON_DOWN
RI_MOUSE_BUTTON_3_UP                            equ     RI_MOUSE_MIDDLE_BUTTON_UP

RI_MOUSE_BUTTON_4_DOWN                          equ     00040H
RI_MOUSE_BUTTON_4_UP                            equ     00080H
RI_MOUSE_BUTTON_5_DOWN                          equ     00100H
RI_MOUSE_BUTTON_5_UP                            equ     00200H

RI_MOUSE_WHEEL                                  equ     00400H

MOUSE_MOVE_RELATIVE                             equ     0
MOUSE_MOVE_ABSOLUTE                             equ     1
MOUSE_VIRTUAL_DESKTOP                           equ     002H
MOUSE_ATTRIBUTES_CHANGED                        equ     004H
MOUSE_MOVE_NOCOALESCE                           equ     008H

KEYBOARD_OVERRUN_MAKE_CODE                      equ     0FFH

RI_KEY_MAKE                                     equ     0
RI_KEY_BREAK                                    equ     1
RI_KEY_E0                                       equ     2
RI_KEY_E1                                       equ     4
RI_KEY_TERMSRV_SET_LED                          equ     8
RI_KEY_TERMSRV_SHADOW                           equ     010H

RID_INPUT                                       equ     010000003H
RID_HEADER                                      equ     010000005H

RIDI_PREPARSEDDATA                              equ     020000005H
RIDI_DEVICENAME                                 equ     020000007H
RIDI_DEVICEINFO                                 equ     02000000BH

RIDEV_REMOVE                                    equ     000000001H
RIDEV_EXCLUDE                                   equ     000000010H
RIDEV_PAGEONLY                                  equ     000000020H
RIDEV_NOLEGACY                                  equ     000000030H
RIDEV_INPUTSINK                                 equ     000000100H
RIDEV_CAPTUREMOUSE                              equ     000000200H
RIDEV_NOHOTKEYS                                 equ     000000200H
RIDEV_APPKEYS                                   equ     000000400H
RIDEV_EXINPUTSINK                               equ     000001000H
RIDEV_DEVNOTIFY                                 equ     000002000H
RIDEV_EXMODEMASK                                equ     0000000F0H

GIDC_ARRIVAL                                    equ     1
GIDC_REMOVAL                                    equ     2

PDC_ARRIVAL                                     equ     0001H
PDC_REMOVAL                                     equ     0002H
PDC_ORIENTATION_0                               equ     0004H
PDC_ORIENTATION_90                              equ     0008H
PDC_ORIENTATION_180                             equ     0010H
PDC_ORIENTATION_270                             equ     0020H
PDC_MODE_DEFAULT                                equ     0040H
PDC_MODE_CENTERED                               equ     0080H
PDC_MAPPING_CHANGE                              equ     0100H
PDC_RESOLUTION                                  equ     0200H
PDC_ORIGIN                                      equ     0400H

POINTER_DEVICE_TYPE_INTEGRATED_PEN              equ     000000001H
POINTER_DEVICE_TYPE_EXTERNAL_PEN                equ     000000002H
POINTER_DEVICE_TYPE_TOUCH                       equ     000000003H
POINTER_DEVICE_TYPE_MAX                         equ     0FFFFFFFFH

POINTER_DEVICE_CURSOR_TYPE_UNKNOWN              equ     000000000H
POINTER_DEVICE_CURSOR_TYPE_TIP                  equ     000000001H
POINTER_DEVICE_CURSOR_TYPE_ERASER               equ     000000002H
POINTER_DEVICE_CURSOR_TYPE_MAX                  equ     0FFFFFFFFH

TOUCHEVENTF_MOVE                                equ     00001H
TOUCHEVENTF_DOWN                                equ     00002H
TOUCHEVENTF_UP                                  equ     00004H
TOUCHEVENTF_INRANGE                             equ     00008H
TOUCHEVENTF_PRIMARY                             equ     00010H
TOUCHEVENTF_NOCOALESCE                          equ     00020H
TOUCHEVENTF_PEN                                 equ     00040H
TOUCHEVENTF_PALM                                equ     00080H

TOUCHINPUTMASKF_TIMEFROMSYSTEM                  equ     00001H
TOUCHINPUTMASKF_EXTRAINFO                       equ     00002H
TOUCHINPUTMASKF_CONTACTAREA                     equ     00004H

TWF_FINETOUCH                                   equ     000000001H
TWF_WANTPALM                                    equ     000000002H

PT_POINTER                                      equ     000000001H
PT_TOUCH                                        equ     000000002H
PT_PEN                                          equ     000000003H
PT_MOUSE                                        equ     000000004H

POINTER_FLAG_NONE                               equ     000000000H
POINTER_FLAG_NEW                                equ     000000001H
POINTER_FLAG_INRANGE                            equ     000000002H
POINTER_FLAG_INCONTACT                          equ     000000004H
POINTER_FLAG_FIRSTBUTTON                        equ     000000010H
POINTER_FLAG_SECONDBUTTON                       equ     000000020H
POINTER_FLAG_OTHERBUTTON                        equ     000000040H
POINTER_FLAG_THIRDBUTTON                        equ     000000080H
POINTER_FLAG_PRIMARY                            equ     000000100H
POINTER_FLAG_CONFIDENCE                         equ     000000200H
POINTER_FLAG_CANCELED                           equ     000000400H
POINTER_FLAG_DOWN                               equ     000010000H
POINTER_FLAG_UPDATE                             equ     000020000H
POINTER_FLAG_UP                                 equ     000040000H
POINTER_FLAG_WHEEL                              equ     000080000H
POINTER_FLAG_HWHEEL                             equ     000100000H
POINTER_FLAG_CAPTURECHANGED                     equ     000200000H

POINTER_MOD_SHIFT                               equ     00004H
POINTER_MOD_CTRL                                equ     00008H

TOUCH_FLAG_NONE                                 equ     000000000H

TOUCH_MASK_NONE                                 equ     000000000H
TOUCH_MASK_CONTACTAREA                          equ     000000001H
TOUCH_MASK_ORIENTATION                          equ     000000002H
TOUCH_MASK_PRESSURE                             equ     000000004H

PEN_FLAG_NONE                                   equ     000000000H
PEN_FLAG_BARREL                                 equ     000000001H
PEN_FLAG_INVERTED                               equ     000000002H
PEN_FLAG_ERASER                                 equ     000000004H

PEN_MASK_NONE                                   equ     000000000H
PEN_MASK_PRESSURE                               equ     000000001H
PEN_MASK_ROTATION                               equ     000000002H
PEN_MASK_TILT_X                                 equ     000000004H
PEN_MASK_TILT_Y                                 equ     000000008H

POINTER_MESSAGE_FLAG_NEW                        equ     000000001H
POINTER_MESSAGE_FLAG_INRANGE                    equ     000000002H
POINTER_MESSAGE_FLAG_INCONTACT                  equ     000000004H
POINTER_MESSAGE_FLAG_FIRSTBUTTON                equ     000000010H
POINTER_MESSAGE_FLAG_SECONDBUTTON               equ     000000020H
POINTER_MESSAGE_FLAG_OTHERBUTTON                equ     000000040H
POINTER_MESSAGE_FLAG_THIRDBUTTON                equ     000000080H
POINTER_MESSAGE_FLAG_PRIMARY                    equ     000000100H
POINTER_MESSAGE_FLAG_CONFIDENCE                 equ     000000200H
POINTER_MESSAGE_FLAG_CANCELED                   equ     000000400H

PA_ACTIVATE                                     equ     MA_ACTIVATE
PA_NOACTIVATE                                   equ     MA_NOACTIVATE

MAX_TOUCH_COUNT                                 equ     256

TOUCH_FEEDBACK_DEFAULT                          equ     01H
TOUCH_FEEDBACK_INDIRECT                         equ     02H
TOUCH_FEEDBACK_NONE                             equ     03H

TOUCH_HIT_TESTING_DEFAULT                       equ     00H
TOUCH_HIT_TESTING_CLIENT                        equ     01H
TOUCH_HIT_TESTING_NONE                          equ     02H

TOUCH_HIT_TESTING_PROXIMITY_CLOSEST             equ     0000H
TOUCH_HIT_TESTING_PROXIMITY_FARTHEST            equ     0FFFH

FEEDBACK_TOUCH_CONTACTVISUALIZATION             equ     1
FEEDBACK_PEN_BARRELVISUALIZATION                equ     2
FEEDBACK_PEN_TAP                                equ     3
FEEDBACK_PEN_DOUBLETAP                          equ     4
FEEDBACK_PEN_PRESSANDHOLD                       equ     5
FEEDBACK_PEN_RIGHTTAP                           equ     6
FEEDBACK_TOUCH_TAP                              equ     7
FEEDBACK_TOUCH_DOUBLETAP                        equ     8
FEEDBACK_TOUCH_PRESSANDHOLD                     equ     9
FEEDBACK_TOUCH_RIGHTTAP                         equ     10
FEEDBACK_GESTURE_PRESSANDTAP                    equ     11
FEEDBACK_MAX                                    equ     0FFFFFFFFH

GWFS_INCLUDE_ANCESTORS                          equ     000000001H

MSGFLTINFO_NONE                                 equ     0
MSGFLTINFO_ALREADYALLOWED_FORWND                equ     1
MSGFLTINFO_ALREADYDISALLOWED_FORWND             equ     2
MSGFLTINFO_ALLOWED_HIGHER                       equ     3

MSGFLT_RESET                                    equ     0
MSGFLT_ALLOW                                    equ     1
MSGFLT_DISALLOW                                 equ     2

GF_BEGIN                                        equ     000000001H
GF_INERTIA                                      equ     000000002H
GF_END                                          equ     000000004H

GID_BEGIN                                       equ     1
GID_END                                         equ     2
GID_ZOOM                                        equ     3
GID_PAN                                         equ     4
GID_ROTATE                                      equ     5
GID_TWOFINGERTAP                                equ     6
GID_PRESSANDTAP                                 equ     7
GID_ROLLOVER                                    equ     GID_PRESSANDTAP

GC_ALLGESTURES                                  equ     000000001H
GC_ZOOM                                         equ     000000001H
GC_PAN                                          equ     000000001H
GC_PAN_WITH_SINGLE_FINGER_VERTICALLY            equ     000000002H
GC_PAN_WITH_SINGLE_FINGER_HORIZONTALLY          equ     000000004H
GC_PAN_WITH_GUTTER                              equ     000000008H
GC_PAN_WITH_INERTIA                             equ     000000010H
GC_ROTATE                                       equ     000000001H
GC_TWOFINGERTAP                                 equ     000000001H
GC_PRESSANDTAP                                  equ     000000001H
GC_ROLLOVER                                     equ     GC_PRESSANDTAP
GESTURECONFIGMAXCOUNT                           equ     256

GCF_INCLUDE_ANCESTORS                           equ     000000001H

NID_INTEGRATED_TOUCH                            equ     000000001H
NID_EXTERNAL_TOUCH                              equ     000000002H
NID_INTEGRATED_PEN                              equ     000000004H
NID_EXTERNAL_PEN                                equ     000000008H
NID_MULTI_INPUT                                 equ     000000040H
NID_READY                                       equ     000000080H

MAX_STR_BLOCKREASON                             equ     256

WDA_NONE                                        equ     0
WDA_MONITOR                                     equ     1

;======================================== Functions =======================================;
#if COFF_FORMAT == 1
    from_lib user32.lib
#else
    from_dll user32.dll
#endif

#ifdef APP_WIN64
    import ActivateKeyboardLayout
    import AdjustWindowRect
    import AdjustWindowRectEx
    import AnyPopup
    import AppendMenuA
    import AppendMenuW
    import ArrangeIconicWindows
    import AttachThreadInput
    import BeginDeferWindowPos
    import BeginPaint
    import BringWindowToTop
    import BroadcastSystemMessageA
    import BroadcastSystemMessageW
    import GetAltTabInfoA
    import GetAltTabInfoW
    import RealGetWindowClassA
    import RealGetWindowClassW
    #ifdef APP_UNICODE
        define BroadcastSystemMessage BroadcastSystemMessageW
        define GetAltTabInfo GetAltTabInfoW
        define RealGetWindowClass RealGetWindowClassW
    #else
        define BroadcastSystemMessage BroadcastSystemMessageA
        define GetAltTabInfo GetAltTabInfoA
        define RealGetWindowClass RealGetWindowClassA
    #endif
    import CallMsgFilter
    import CallMsgFilterA
    import CallMsgFilterW
    import CallNextHookEx
    import CallWindowProcA
    import CallWindowProcW
    import CascadeChildWindows
    import CascadeWindows
    import ChangeClipboardChain
    import ChangeDisplaySettingsA
    import ChangeDisplaySettingsW
    import ChangeMenuA
    import ChangeMenuW
    import CharLowerA
    import CharLowerBuffA
    import CharLowerBuffW
    import CharLowerW
    import CharNextA
    import CharNextExA
    import CharNextW
    import CharPrevA
    import CharPrevExA
    import CharPrevW
    import CharToOemA
    import CharToOemBuffA
    import CharToOemBuffW
    import CharToOemW
    import CharUpperA
    import CharUpperBuffA
    import CharUpperBuffW
    import CharUpperW
    import CheckDlgButton
    import CheckMenuItem
    import CheckMenuRadioItem
    import CheckRadioButton
    import ChildWindowFromPoint
    import ChildWindowFromPointEx
    import ClientToScreen
    import ClipCursor
    import CloseClipboard
    import CloseDesktop
    import CloseWindow
    import CloseWindowStation
    import CopyAcceleratorTableA
    import CopyAcceleratorTableW
    import CopyIcon
    import CopyImage
    import CopyRect
    import CountClipboardFormats
    import CreateAcceleratorTableA
    import CreateAcceleratorTableW
    import CreateCaret
    import CreateCursor
    import CreateDesktopA
    import CreateDesktopW
    import CreateDialogIndirectParamA
    import CreateDialogIndirectParamW
    import CreateDialogParamA
    import CreateDialogParamW
    import CreateIcon
    import CreateIconFromResource
    import CreateIconFromResourceEx
    import CreateIconIndirect
    import CreateMDIWindowA
    import CreateMDIWindowW
    import CreateMenu
    import CreatePopupMenu
    import CreateWindowExA
    import CreateWindowExW
    import CreateWindowStationA
    import CreateWindowStationW
    import DdeAbandonTransaction
    import DdeAccessData
    import DdeAddData
    import DdeClientTransaction
    import DdeCmpStringHandles
    import DdeConnect
    import DdeConnectList
    import DdeCreateDataHandle
    import DdeCreateStringHandleA
    import DdeCreateStringHandleW
    import DdeDisconnect
    import DdeDisconnectList
    import DdeEnableCallback
    import DdeFreeDataHandle
    import DdeFreeStringHandle
    import DdeGetData
    import DdeGetLastError
    import DdeImpersonateClient
    import DdeInitializeA
    import DdeInitializeW
    import DdeKeepStringHandle
    import DdeNameService
    import DdePostAdvise
    import DdeQueryConvInfo
    import DdeQueryNextServer
    import DdeQueryStringA
    import DdeQueryStringW
    import DdeReconnect
    import DdeSetQualityOfService
    import DdeSetUserHandle
    import DdeUnaccessData
    import DdeUninitialize
    import DefDlgProcA
    import DefDlgProcW
    import DeferWindowPos
    import DefFrameProcA
    import DefFrameProcW
    import DefMDIChildProcA
    import DefMDIChildProcW
    import DefWindowProcA
    import DefWindowProcW
    import DeleteMenu
    import DestroyAcceleratorTable
    import DestroyCaret
    import DestroyCursor
    import DestroyIcon
    import DestroyMenu
    import DestroyWindow
    import DialogBoxIndirectParamA
    import DialogBoxIndirectParamW
    import DialogBoxParamA
    import DialogBoxParamW
    import DispatchMessageA
    import DispatchMessageW
    import DlgDirListA
    import DlgDirListComboBoxA
    import DlgDirListComboBoxW
    import DlgDirListW
    import DlgDirSelectComboBoxExA
    import DlgDirSelectComboBoxExW
    import DlgDirSelectExA
    import DlgDirSelectExW
    import DragDetect
    import DragObject
    import DrawAnimatedRects
    import DrawCaption
    import DrawCaptionTempA
    import DrawCaptionTempW
    import DrawEdge
    import DrawFocusRect
    import DrawFrame
    import DrawFrameControl
    import DrawIcon
    import DrawIconEx
    import DrawMenuBar
    import DrawStateA
    import DrawStateW
    import DrawTextA
    import DrawTextExA
    import DrawTextExW
    import DrawTextW
    import EditWndProc
    import EmptyClipboard
    import EnableMenuItem
    import EnableScrollBar
    import EnableWindow
    import EndDeferWindowPos
    import EndDialog
    import EndPaint
    import EndTask
    import EnumChildWindows
    import EnumClipboardFormats
    import EnumDesktopsA
    import EnumDesktopsW
    import EnumDesktopWindows
    import EnumDisplayDevicesA
    import EnumDisplayDevicesW
    import EnumDisplaySettingsA
    import EnumDisplaySettingsW
    import EnumPropsA
    import EnumPropsExA
    import EnumPropsExW
    import EnumPropsW
    import EnumThreadWindows
    import EnumWindows
    import EnumWindowStationsA
    import EnumWindowStationsW
    import EqualRect
    import ExcludeUpdateRgn
    import ExitWindowsEx
    import FillRect
    import FindWindowA
    import FindWindowExA
    import FindWindowExW
    import FindWindowW
    import FlashWindow
    import FrameRect
    import FreeDDElParam
    import GetActiveWindow
    import GetAsyncKeyState
    import GetCapture
    import GetCaretBlinkTime
    import GetCaretPos
    import GetClassInfoA
    import GetClassInfoExA
    import GetClassInfoExW
    import GetClassInfoW
    import GetClassLongA
    import GetClassLongW
    import GetClassNameA
    import GetClassNameW
    import GetClassWord
    import GetClientRect
    import GetClipboardData
    import GetClipboardFormatNameA
    import GetClipboardFormatNameW
    import GetClipboardOwner
    import GetClipboardViewer
    import GetClipCursor
    import GetCursor
    import GetCursorPos
    import GetDC
    import GetDCEx
    import GetDesktopWindow
    import GetDialogBaseUnits
    import GetDlgCtrlID
    import GetDlgItem
    import GetDlgItemInt
    import GetDlgItemTextA
    import GetDlgItemTextW
    import GetDoubleClickTime
    import GetFocus
    import GetForegroundWindow
    #if NTDDI_VERSION != NTDDI_WIN95
        #if NTDDI_VERSION != NTDDI_WINNT4
            import GetGuiResources
        #endif
    #endif
    import GetIconInfo
    import GetInputDesktop
    import GetInputState
    import GetInternalWindowPos
    import GetKBCodePage
    import GetKeyboardLayout
    import GetKeyboardLayoutList
    import GetKeyboardLayoutNameA
    import GetKeyboardLayoutNameW
    import GetKeyboardState
    import GetKeyboardType
    import GetKeyNameTextA
    import GetKeyNameTextW
    import GetKeyState
    import GetLastActivePopup
    import GetMenu
    import GetMenuCheckMarkDimensions
    import GetMenuContextHelpId
    import GetMenuDefaultItem
    import GetMenuItemCount
    import GetMenuItemID
    import GetMenuItemInfoA
    import GetMenuItemInfoW
    import GetMenuItemRect
    import GetMenuState
    import GetMenuStringA
    import GetMenuStringW
    import GetMessageA
    import GetMessageExtraInfo
    import GetMessagePos
    import GetMessageTime
    import GetMessageW
    import GetNextDlgGroupItem
    import GetNextDlgTabItem
    import GetOpenClipboardWindow
    import GetParent
    import GetPriorityClipboardFormat
    import GetProcessWindowStation
    import GetPropA
    import GetPropW
    import GetQueueStatus
    import GetScrollInfo
    import GetScrollPos
    import GetScrollRange
    import GetShellWindow
    import GetSubMenu
    import GetSysColor
    import GetSysColorBrush
    import GetSystemMenu
    import GetSystemMetrics
    import GetTabbedTextExtentA
    import GetTabbedTextExtentW
    import GetThreadDesktop
    import GetTopWindow
    import GetUpdateRect
    import GetUpdateRgn
    import GetUserObjectInformationA
    import GetUserObjectInformationW
    import GetUserObjectSecurity
    import GetWindow
    import GetWindowContextHelpId
    import GetWindowDC
    import GetWindowLongA
    import GetWindowLongW
    import GetWindowPlacement
    import GetWindowRect
    import GetWindowRgn
    import GetWindowTextA
    import GetWindowTextLengthA
    import GetWindowTextLengthW
    import GetWindowTextW
    import GetWindowThreadProcessId
    import GetWindowWord
    import GrayStringA
    import GrayStringW
    import HideCaret
    import HiliteMenuItem
    import ImpersonateDdeClientWindow
    import InflateRect
    import InSendMessage
    import InsertMenuA
    import InsertMenuItemA
    import InsertMenuItemW
    import InsertMenuW
    import InternalGetWindowText
    import IntersectRect
    import InvalidateRect
    import InvalidateRgn
    import InvertRect
    import IsCharAlphaA
    import IsCharAlphaNumericA
    import IsCharAlphaNumericW
    import IsCharAlphaW
    import IsCharLowerA
    import IsCharLowerW
    import IsCharUpperA
    import IsCharUpperW
    import IsChild
    import IsClipboardFormatAvailable
    import IsDialogMessage
    import IsDialogMessageA
    import IsDialogMessageW
    import IsDlgButtonChecked
    import IsIconic
    import IsMenu
    import IsRectEmpty
    import IsWindow
    import IsWindowEnabled
    import IsWindowUnicode
    import IsWindowVisible
    import IsZoomed
    import KillTimer
    import LoadAcceleratorsA
    import LoadAcceleratorsW
    import LoadBitmapA
    import LoadBitmapW
    import LoadCursorA
    import LoadCursorFromFileA
    import LoadCursorFromFileW
    import LoadCursorW
    import LoadIconA
    import LoadIconW
    import LoadImageA
    import LoadImageW
    import LoadKeyboardLayoutA
    import LoadKeyboardLayoutW
    import LoadMenuA
    import LoadMenuIndirectA
    import LoadMenuIndirectW
    import LoadMenuW
    import LoadStringA
    import LoadStringW
    import LockWindowStation
    import LockWindowUpdate
    import LookupIconIdFromDirectory
    import LookupIconIdFromDirectoryEx
    import MapDialogRect
    import MapVirtualKeyA
    import MapVirtualKeyExA
    import MapVirtualKeyExW
    import MapVirtualKeyW
    import MapWindowPoints
    import MenuItemFromPoint
    import MessageBeep
    import MessageBoxA
    import MessageBoxExA
    import MessageBoxExW
    import MessageBoxIndirectA
    import MessageBoxIndirectW
    import MessageBoxW
    import ModifyMenuA
    import ModifyMenuW
    import MoveWindow
    import MsgWaitForMultipleObjects
    import OemKeyScan
    import OemToCharA
    import OemToCharBuffA
    import OemToCharBuffW
    import OemToCharW
    import OffsetRect
    import OpenClipboard
    import OpenDesktopA
    import OpenDesktopW
    import OpenIcon
    import OpenInputDesktop
    import OpenWindowStationA
    import OpenWindowStationW
    import PackDDElParam
    import PaintDesktop
    import PeekMessageA
    import PeekMessageW
    import PostMessageA
    import PostMessageW
    import PostQuitMessage
    import PostThreadMessageA
    import PostThreadMessageW
    import PtInRect
    import RedrawWindow
    import RegisterClassA
    import RegisterClassExA
    import RegisterClassExW
    import RegisterClassW
    import RegisterClipboardFormatA
    import RegisterClipboardFormatW
    import RegisterHotKey
    import RegisterLogonProcess
    import RegisterSystemThread
    import RegisterTasklist
    import RegisterWindowMessageA
    import RegisterWindowMessageW
    import ReleaseCapture
    import ReleaseDC
    import RemoveMenu
    import RemovePropA
    import RemovePropW
    import ReplyMessage
    import ReuseDDElParam
    import ScreenToClient
    import ScrollDC
    import ScrollWindow
    import ScrollWindowEx
    import SendDlgItemMessageA
    import SendDlgItemMessageW
    import SendMessageA
    import SendMessageCallbackA
    import SendMessageCallbackW
    import SendMessageTimeoutA
    import SendMessageTimeoutW
    import SendMessageW
    import SendNotifyMessageA
    import SendNotifyMessageW
    import SetActiveWindow
    import SetCapture
    import SetCaretBlinkTime
    import SetCaretPos
    import SetClassLongA
    import SetClassLongW
    import SetClassWord
    import SetClipboardData
    import SetClipboardViewer
    import SetCursor
    import SetCursorPos
    import SetDebugErrorLevel
    import SetDlgItemInt
    import SetDlgItemTextA
    import SetDlgItemTextW
    import SetDoubleClickTime
    import SetFocus
    import SetForegroundWindow
    import SetInternalWindowPos
    import SetKeyboardState
    import SetLastErrorEx
    import SetMenu
    import SetMenuContextHelpId
    import SetMenuDefaultItem
    import SetMenuItemBitmaps
    import SetMenuItemInfoA
    import SetMenuItemInfoW
    import SetMessageExtraInfo
    import SetMessageQueue
    import SetParent
    import SetProcessWindowStation
    import SetPropA
    import SetPropW
    import SetRect
    import SetRectEmpty
    import SetScrollInfo
    import SetScrollPos
    import SetScrollRange
    import SetShellWindow
    import SetSysColors
    import SetSysColorsTemp
    import SetSystemCursor
    import SetThreadDesktop
    import SetTimer
    import SetUserObjectInformationA
    import SetUserObjectInformationW
    import SetUserObjectSecurity
    import SetWindowContextHelpId
    import SetWindowLongA
    import SetWindowLongW
    import SetWindowPlacement
    import SetWindowPos
    import SetWindowRgn
    import SetWindowsHookA
    import SetWindowsHookExA
    import SetWindowsHookExW
    import SetWindowsHookW
    import SetWindowTextA
    import SetWindowTextW
    import SetWindowWord
    import ShowCaret
    import ShowCursor
    import ShowOwnedPopups
    import ShowScrollBar
    import ShowWindow
    import ShowWindowAsync
    import SubtractRect
    import SwapMouseButton
    import SwitchDesktop
    import SwitchToThisWindow
    import SystemParametersInfoA
    import SystemParametersInfoW
    import TabbedTextOutA
    import TabbedTextOutW
    import TileChildWindows
    import TileWindows
    import ToAscii
    import ToAsciiEx
    import ToUnicode
    import TrackPopupMenu
    import TrackPopupMenuEx
    import TranslateAccelerator
    import TranslateAcceleratorA
    import TranslateAcceleratorW
    import TranslateMDISysAccel
    import TranslateMessage
    import UnhookWindowsHook
    import UnhookWindowsHookEx
    import UnionRect
    import UnloadKeyboardLayout
    import UnlockWindowStation
    import UnpackDDElParam
    import UnregisterClassA
    import UnregisterClassW
    import UnregisterHotKey
    import UpdateWindow
    import ValidateRect
    import ValidateRgn
    import VkKeyScanA
    import VkKeyScanExA
    import VkKeyScanExW
    import VkKeyScanW
    import WaitForInputIdle
    import WaitMessage
    import WindowFromDC
    import WindowFromPoint
    import WinHelpA
    import WinHelpW
    import keybd_event
    import mouse_event
    import wsprintfA
    import wsprintfW
    import wvsprintfA
    import wvsprintfW

    #if NTDDI_VERSION >= NTDDI_WIN98_ME
        import GetNextQueueWindow
        import IsHungThread
        import ModifyAccess
        import RegisterNetworkCapabilities
        import SetDesktopBitmap
        import SetWindowFullScreenState
        import UserSignalProc
        import WNDPROC_CALLBACK
    #endif
    #if NTDDI_VERSION != NTDDI_WINNT4
        import UnhookWinEvent
        import WINNLSEnableIME
    #endif

    #if NTDDI_VERSION >= NTDDI_WIN98_ME
        import BlockInput
        import ChangeDisplaySettingsExA
        import ChangeDisplaySettingsExW
        import EndMenu
        import EnumDisplayMonitors
        import EnumDisplaySettingsExA
        import EnumDisplaySettingsExW
        import FlashWindowEx
        import GetAncestor
        import GetClipboardSequenceNumber
        import GetComboBoxInfo
        import GetCursorInfo
        import GetGUIThreadInfo
        import GetListBoxInfo
        import GetMenuBarInfo
        import GetMenuInfo
        import GetProcessDefaultLayout
        import GetScrollBarInfo
        import GetTitleBarInfo
        import GetWindowInfo
        import GetWindowModuleFileName
        import GetWindowModuleFileNameA
        import GetWindowModuleFileNameW
        import IMPGetIMEA
        import IMPGetIMEW
        import IMPQueryIMEA
        import IMPQueryIMEW
        import IMPSetIMEA
        import IMPSetIMEW
        import MsgWaitForMultipleObjectsEx
        import NotifyWinEvent
        import RealChildWindowFromPoint
        import SendIMEMessageExA
        import SendIMEMessageExW
        import SendInput
        import SetWinEventHook
        import ToUnicodeEx
        import TrackMouseEvent

        #if NTDDI_VERSION != NTDDI_WINNT4
            import GetMonitorInfoA
            import GetMonitorInfoW
            import InSendMessageEx
            import MonitorFromPoint
            import MonitorFromRect
            import MonitorFromWindow
            import RegisterDeviceNotificationA
            import RegisterDeviceNotificationW
            import SetMenuInfo
            import SetProcessDefaultLayout
            import UnregisterDeviceNotification
            #ifdef APP_UNICODE
                define GetMonitorInfo GetMonitorInfoW
                define RegisterDeviceNotification RegisterDeviceNotificationW
            #else
                define GetMonitorInfo GetMonitorInfoA
                define RegisterDeviceNotification RegisterDeviceNotificationA
            #endif
        #endif

        #ifdef APP_UNICODE
            define ChangeDisplaySettingsEx ChangeDisplaySettingsExW
            define EnumDisplaySettingsEx EnumDisplaySettingsExW
            define IMPGetIME IMPGetIMEW
            define IMPQueryIME IMPQueryIMEW
            define IMPSetIME IMPSetIMEW
            define SendIMEMessageEx SendIMEMessageExW
        #else
            define ChangeDisplaySettingsEx ChangeDisplaySettingsExA
            define EnumDisplaySettingsEx EnumDisplaySettingsExA
            define IMPGetIME IMPGetIMEA
            define IMPQueryIME IMPQueryIMEA
            define IMPSetIME IMPSetIMEA
            define SendIMEMessageEx SendIMEMessageExA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WINNT4
        import ClientThreadSetup
        import CreateDialogIndirectParamAorW
        import DdeGetQualityOfService
        import DeregisterShellHookWindow
        import DrawMenuBarTemp
        import GetAppCompatFlags
        import GetProgmanWindow
        import GetTaskmanWindow
        import IsHungAppWindow
        import LoadKeyboardLayoutEx
        import LoadLocalFonts
        import LoadRemoteFonts
        import MBToWCSEx
        import MB_GetString
        import MenuWindowProcA
        import MenuWindowProcW
        import PrivateExtractIconExA
        import PrivateExtractIconExW
        import PrivateExtractIconsA
        import PrivateExtractIconsW
        import QuerySendMessage
        import RegisterServicesProcess
        import RegisterShellHookWindow
        import SetProgmanWindow
        import SetShellWindowEx
        import SetSystemMenu
        import SetTaskmanWindow
        import SetWindowStationUser
        import ShowStartGlass
        import TranslateMessageEx
        import UserRealizePalette
        import UserRegisterWowHandlers
        #ifdef APP_UNICODE
            define MenuWindowProc MenuWindowProcW
            define PrivateExtractIconEx PrivateExtractIconExW
            define PrivateExtractIcons PrivateExtractIconsW
        #else
            define MenuWindowProc MenuWindowProcA
            define PrivateExtractIconEx PrivateExtractIconExA
            define PrivateExtractIcons PrivateExtractIconsA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WIN2K
        import AllowSetForegroundWindow
        import AnimateWindow
        import CliImmSetHotKey
        import CtxInitUser32
        import DeviceEventWorker
        import GetAppCompatFlags2
        import GetClassLongPtrA
        import GetClassLongPtrW
        import GetLastInputInfo
        import GetMouseMovePointsEx
        import GetWindowLongPtrA
        import GetWindowLongPtrW
        import InitializeLpkHooks
        import LockSetForegroundWindow
        import LockWorkStation
        import SetClassLongPtrA
        import SetClassLongPtrW
        import SetWindowLongPtrA
        import SetWindowLongPtrW
        import SetLayeredWindowAttributes
        import UpdateLayeredWindow
        import UserHandleGrantAccess
        #ifdef APP_UNICODE
            define GetClassLongPtr GetClassLongPtrW
            define GetWindowLongPtr GetWindowLongPtrW
            define SetClassLongPtr SetClassLongPtrW
            define SetWindowLongPtr SetWindowLongPtrW
        #else
            define GetClassLongPtr GetClassLongPtrA
            define GetWindowLongPtr GetWindowLongPtrA
            define SetClassLongPtr SetClassLongPtrA
            define SetWindowLongPtr SetWindowLongPtrA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WINXP
        import AllowForegroundActivation
        import BroadcastSystemMessageExA
        import BroadcastSystemMessageExW
        import BuildReasonArray
        import CreateSystemThreads
        import CsrBroadcastSystemMessageExW
        import DefRawInputProc
        import DestroyReasons
        import DisableProcessWindowsGhosting
        import GetLayeredWindowAttributes
        import GetRawInputBuffer
        import GetRawInputData
        import GetRawInputDeviceInfoA
        import GetRawInputDeviceInfoW
        import GetRawInputDeviceList
        import GetReasonTitleFromReasonCode
        import GetRegisteredRawInputDevices
        import GetWindowRgnBox
        import IsGUIThread
        #if NTDDI_VERSION <= NTDDI_WINXPALL
            import IsProcess16Bit
            import SetLogonNotifyWindow
        #endif
        import IsServerSideWindow
        import IsWinEventHookInstalled
        import IsWindowInDestroy
        import MessageBoxTimeoutA
        import MessageBoxTimeoutW
        import PrintWindow
        import RecordShutdownReason
        import RegisterMessagePumpHook
        import RegisterRawInputDevices
        import RegisterUserApiHook
        import UnregisterMessagePumpHook
        import UnregisterUserApiHook
        #ifdef APP_UNICODE
            define BroadcastSystemMessageEx BroadcastSystemMessageExW
            define GetRawInputDeviceInfo GetRawInputDeviceInfoW
            define MessageBoxTimeout MessageBoxTimeoutW
        #else
            define BroadcastSystemMessageEx BroadcastSystemMessageExA
            define GetRawInputDeviceInfo GetRawInputDeviceInfoA
            define MessageBoxTimeout MessageBoxTimeoutA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WS03SP1
        import IsWow64Message
    #endif

    #if NTDDI_VERSION >= NTDDI_VISTA
        import AddClipboardFormatListener
        import CancelShutdown
        import ChangeWindowMessageFilter
        import CreateDesktopExA
        import CreateDesktopExW
        import DisplayConfigGetDeviceInfo
        import DisplayConfigSetDeviceInfo
        import FrostCrashedWindow
        import GetIconInfoExA
        import GetIconInfoExW
        import GetPhysicalCursorPos
        import GetSendMessageReceiver
        import GetUpdatedClipboardFormats
        import GetWindowMinimizeRect
        import GhostWindowFromHungWindow
        import HungWindowFromGhostWindow
        import IsProcessDPIAware
        import IsSETEnabled
        import IsThreadDesktopComposited
        import IsWindowRedirectedForPrint
        import LogicalToPhysicalPoint
        import PhysicalToLogicalPoint
        import RegisterPowerSettingNotification
        import RemoveClipboardFormatListener
        import SetPhysicalCursorPos
        import SetProcessDPIAware
        import ShutdownBlockReasonCreate
        import ShutdownBlockReasonDestroy
        import ShutdownBlockReasonQuery
        import SoundSentry
        import UnregisterPowerSettingNotification
        import UpdateLayeredWindowIndirect
        import UpdateWindowTransform
        #ifdef APP_UNICODE
            define CreateDesktopEx CreateDesktopExW
            define GetIconInfoEx GetIconInfoExW
        #else
            define CreateDesktopEx CreateDesktopExA
            define GetIconInfoEx GetIconInfoExA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WIN7
        import CalculatePopupWindowPosition
        import ChangeWindowMessageFilterEx
        import CloseGestureInfoHandle
        import CloseTouchInputHandle
        import DwmGetDxSharedSurface
        import GetDisplayConfigBufferSizes
        import GetGestureConfig
        import GetGestureExtraArgs
        import GetGestureInfo
        import GetTouchInputInfo
        import GetWindowCompositionAttribute
        import GetWindowDisplayAffinity
        import IsTopLevelWindow
        import IsTouchWindow
        import QueryDisplayConfig
        import RegisterTouchWindow
        import SetDisplayConfig
        import SetGestureConfig
        import SetWindowCompositionAttribute
        import SetWindowDisplayAffinity
        import UnregisterTouchWindow
    #endif

    #if NTDDI_VERSION >= NTDDI_WIN8
        import CreateWindowInBand
        import EnableMouseInPointer
        import EvaluateProximityToPolygon
        import EvaluateProximityToRect
        import GetAutoRotationState
        import GetCIMSSM
        import GetCurrentInputMessageSource
        import GetDisplayAutoRotationPreferences
        import GetPointerCursorId
        import GetPointerDevice
        import GetPointerDeviceCursors
        import GetPointerDeviceProperties
        import GetPointerDeviceRects
        import GetPointerDevices
        import GetPointerFrameInfo
        import GetPointerFrameInfoHistory
        import GetPointerFramePenInfo
        import GetPointerFramePenInfoHistory
        import GetPointerFrameTouchInfo
        import GetPointerFrameTouchInfoHistory
        import GetPointerInfo
        import GetPointerInfoHistory
        import GetPointerPenInfo
        import GetPointerPenInfoHistory
        import GetPointerTouchInfo
        import GetPointerTouchInfoHistory
        import GetPointerType
        import GetRawPointerDeviceData
        import GetUnpredictedMessagePos
        import GetWindowFeedbackSetting
        import InitializeTouchInjection
        import InjectTouchInput
        import IsImmersiveProcess
        import IsMouseInPointerEnabled
        import PackTouchHitTestingProximityEvaluation
        import RegisterPointerDeviceNotifications
        import RegisterPointerInputTarget
        import RegisterSuspendResumeNotification
        import RegisterTouchHitTestingWindow
        import SetCoalescableTimer
        import SetDisplayAutoRotationPreferences
        import SetProcessRestrictionExemption
        import SetWindowFeedbackSetting
        import ShowSystemCursor
        import SkipPointerFrameMessages
        import UnregisterPointerInputTarget
        import UnregisterSuspendResumeNotification
    #endif

    #if NTDDI_VERSION >= NTDDI_WIN81
        import PhysicalToLogicalPointForPerMonitorDPI
    #endif

    #ifdef APP_UNICODE
        define AppendMenu AppendMenuW
        define CallWindowProc CallWindowProcW
        define ChangeDisplaySettings ChangeDisplaySettingsW
        define ChangeMenu ChangeMenuW
        define CharLower CharLowerW
        define CharNext CharNextW
        define CharPrev CharPrevW
        define CharToOem CharToOemW
        define CharToOemBuff CharToOemBuffW
        define CharUpper CharUpperW
        define CharUpperBuff CharUpperBuffW
        define CopyAcceleratorTable CopyAcceleratorTableW
        define CreateAcceleratorTable CreateAcceleratorTableW
        define CreateDesktop CreateDesktopW
        define CreateDialogIndirectParam CreateDialogIndirectParamW
        define CreateDialogParam CreateDialogParamW
        define CreateMDIWindow CreateMDIWindowW
        define CreateWindowEx CreateWindowExW
        define CreateWindowStation CreateWindowStationW
        define DdeCreateStringHandle DdeCreateStringHandleW
        define DdeInitialize DdeInitializeW
        define DdeQueryString DdeQueryStringW
        define DefDlgProc DefDlgProcW
        define DefFrameProc DefFrameProcW
        define DefMDIChildProc DefMDIChildProcW
        define DefWindowProc DefWindowProcW
        define DialogBoxIndirectParam DialogBoxIndirectParamW
        define DialogBoxParam DialogBoxParamW
        define DispatchMessage DispatchMessageW
        define DlgDirList DlgDirListW
        define DlgDirListComboBox DlgDirListComboBoxW
        define DlgDirSelectComboBoxEx DlgDirSelectComboBoxExW
        define DlgDirSelectEx DlgDirSelectExW
        define DrawCaptionTemp DrawCaptionTempW
        define DrawState DrawStateW
        define DrawText DrawTextW
        define DrawTextEx DrawTextExW
        define EnumDesktops EnumDesktopsW
        define EnumDisplayDevices EnumDisplayDevicesW
        define EnumDisplaySettings EnumDisplaySettingsW
        define EnumProps EnumPropsW
        define EnumPropsEx EnumPropsExW
        define EnumWindowStations EnumWindowStationsW
        define FindWindow FindWindowW
        define FindWindowEx FindWindowExW
        define GetClassInfo GetClassInfoW
        define GetClassInfoEx GetClassInfoExW
        define GetClassLong GetClassLongW
        define GetClassName GetClassNameW
        define GetClipboardFormatName GetClipboardFormatNameW
        define GetDlgItemText GetDlgItemTextW
        define GetKeyboardLayoutName GetKeyboardLayoutNameW
        define GetKeyNameText GetKeyNameTextW
        define GetMenuItemInfo GetMenuItemInfoW
        define GetMenuString GetMenuStringW
        define GetMessage GetMessageW
        define GetProp GetPropW
        define GetTabbedTextExtent GetTabbedTextExtentW
        define GetUserObjectInformation GetUserObjectInformationW
        define GetWindowLong GetWindowLongW
        define GetWindowText GetWindowTextW
        define GetWindowTextLength GetWindowTextLengthW
        define GrayString GrayStringW
        define InsertMenu InsertMenuW
        define InsertMenuItem InsertMenuItemW
        define IsCharAlpha IsCharAlphaW
        define IsCharAlphaNumeric IsCharAlphaNumericW
        define IsCharLower IsCharLowerW
        define IsCharUpper IsCharUpperW
        define LoadAccelerators LoadAcceleratorsW
        define LoadBitmap LoadBitmapW
        define LoadCursor LoadCursorW
        define LoadCursorFromFile LoadCursorFromFileW
        define LoadIcon LoadIconW
        define LoadImage LoadImageW
        define LoadKeyboardLayout LoadKeyboardLayoutW
        define LoadMenu LoadMenuW
        define LoadMenuIndirect LoadMenuIndirectW
        define LoadString LoadStringW
        define MapVirtualKey MapVirtualKeyW
        define MapVirtualKeyEx MapVirtualKeyExW
        define MessageBox MessageBoxW
        define MessageBoxEx MessageBoxExW
        define MessageBoxIndirect MessageBoxIndirectW
        define ModifyMenu ModifyMenuW
        define OemToChar OemToCharW
        define OemToCharBuff OemToCharBuffW
        define OpenDesktop OpenDesktopW
        define OpenWindowStation OpenWindowStationW
        define PeekMessage PeekMessageW
        define PostMessage PostMessageW
        define PostThreadMessage PostThreadMessageW
        define RegisterClass RegisterClassW
        define RegisterClassEx RegisterClassExW
        define RegisterClipboardFormat RegisterClipboardFormatW
        define RegisterWindowMessage RegisterWindowMessageW
        define RemoveProp RemovePropW
        define SendDlgItemMessage SendDlgItemMessageW
        define SendMessage SendMessageW
        define SendMessageCallback SendMessageCallbackW
        define SendMessageTimeout SendMessageTimeoutW
        define SendNotifyMessage SendNotifyMessageW
        define SetClassLong SetClassLongW
        define SetDlgItemText SetDlgItemTextW
        define SetMenuItemInfo SetMenuItemInfoW
        define SetProp SetPropW
        define SetUserObjectInformation SetUserObjectInformationW
        define SetWindowLong SetWindowLongW
        define SetWindowsHook SetWindowsHookW
        define SetWindowsHookEx SetWindowsHookExW
        define SetWindowText SetWindowTextW
        define SystemParametersInfo SystemParametersInfoW
        define TabbedTextOut TabbedTextOutW
        define UnregisterClass UnregisterClassW
        define VkKeyScan VkKeyScanW
        define VkKeyScanEx VkKeyScanExW
        define WinHelp WinHelpW
        define wsprintf wsprintfW
        define wvsprintf wvsprintfW
    #else
        define AppendMenu AppendMenuA
        define CallWindowProc CallWindowProcA
        define ChangeDisplaySettings ChangeDisplaySettingsA
        define ChangeMenu ChangeMenuA
        define CharLower CharLowerA
        define CharNext CharNextA
        define CharNextEx CharNextExA
        define CharPrev CharPrevA
        define CharPrevEx CharPrevExA
        define CharToOem CharToOemA
        define CharToOemBuff CharToOemBuffA
        define CharUpper CharUpperA
        define CharUpperBuff CharUpperBuffA
        define CopyAcceleratorTable CopyAcceleratorTableA
        define CreateAcceleratorTable CreateAcceleratorTableA
        define CreateDesktop CreateDesktopA
        define CreateDialogIndirectParam CreateDialogIndirectParamA
        define CreateDialogParam CreateDialogParamA
        define CreateMDIWindow CreateMDIWindowA
        define CreateWindowEx CreateWindowExA
        define CreateWindowStation CreateWindowStationA
        define DdeCreateStringHandle DdeCreateStringHandleA
        define DdeInitialize DdeInitializeA
        define DdeQueryString DdeQueryStringA
        define DefDlgProc DefDlgProcA
        define DefFrameProc DefFrameProcA
        define DefMDIChildProc DefMDIChildProcA
        define DefWindowProc DefWindowProcA
        define DialogBoxIndirectParam DialogBoxIndirectParamA
        define DialogBoxParam DialogBoxParamA
        define DispatchMessage DispatchMessageA
        define DlgDirList DlgDirListA
        define DlgDirListComboBox DlgDirListComboBoxA
        define DlgDirSelectComboBoxEx DlgDirSelectComboBoxExA
        define DlgDirSelectEx DlgDirSelectExA
        define DrawCaptionTemp DrawCaptionTempA
        define DrawState DrawStateA
        define DrawText DrawTextA
        define DrawTextEx DrawTextExA
        define EnumDesktops EnumDesktopsA
        define EnumDisplayDevices EnumDisplayDevicesA
        define EnumDisplaySettings EnumDisplaySettingsA
        define EnumProps EnumPropsA
        define EnumPropsEx EnumPropsExA
        define EnumWindowStations EnumWindowStationsA
        define FindWindow FindWindowA
        define FindWindowEx FindWindowExA
        define GetClassInfo GetClassInfoA
        define GetClassInfoEx GetClassInfoExA
        define GetClassLong GetClassLongA
        define GetClassName GetClassNameA
        define GetClipboardFormatName GetClipboardFormatNameA
        define GetDlgItemText GetDlgItemTextA
        define GetKeyboardLayoutName GetKeyboardLayoutNameA
        define GetKeyNameText GetKeyNameTextA
        define GetMenuItemInfo GetMenuItemInfoA
        define GetMenuString GetMenuStringA
        define GetMessage GetMessageA
        define GetProp GetPropA
        define GetTabbedTextExtent GetTabbedTextExtentA
        define GetUserObjectInformation GetUserObjectInformationA
        define GetWindowLong GetWindowLongA
        define GetWindowText GetWindowTextA
        define GetWindowTextLength GetWindowTextLengthA
        define GrayString GrayStringA
        define InsertMenu InsertMenuA
        define InsertMenuItem InsertMenuItemA
        define IsCharAlpha IsCharAlphaA
        define IsCharAlphaNumeric IsCharAlphaNumericA
        define IsCharLower IsCharLowerA
        define IsCharUpper IsCharUpperA
        define LoadAccelerators LoadAcceleratorsA
        define LoadBitmap LoadBitmapA
        define LoadCursor LoadCursorA
        define LoadCursorFromFile LoadCursorFromFileA
        define LoadIcon LoadIconA
        define LoadImage LoadImageA
        define LoadKeyboardLayout LoadKeyboardLayoutA
        define LoadMenu LoadMenuA
        define LoadMenuIndirect LoadMenuIndirectA
        define LoadString LoadStringA
        define MapVirtualKey MapVirtualKeyA
        define MapVirtualKeyEx MapVirtualKeyExA
        define MessageBox MessageBoxA
        define MessageBoxEx MessageBoxExA
        define MessageBoxIndirect MessageBoxIndirectA
        define ModifyMenu ModifyMenuA
        define OemToChar OemToCharA
        define OemToCharBuff OemToCharBuffA
        define OpenDesktop OpenDesktopA
        define OpenWindowStation OpenWindowStationA
        define PeekMessage PeekMessageA
        define PostMessage PostMessageA
        define PostThreadMessage PostThreadMessageA
        define RegisterClass RegisterClassA
        define RegisterClassEx RegisterClassExA
        define RegisterClipboardFormat RegisterClipboardFormatA
        define RegisterWindowMessage RegisterWindowMessageA
        define RemoveProp RemovePropA
        define SendDlgItemMessage SendDlgItemMessageA
        define SendMessage SendMessageA
        define SendMessageCallback SendMessageCallbackA
        define SendMessageTimeout SendMessageTimeoutA
        define SendNotifyMessage SendNotifyMessageA
        define SetClassLong SetClassLongA
        define SetDlgItemText SetDlgItemTextA
        define SetMenuItemInfo SetMenuItemInfoA
        define SetProp SetPropA
        define SetUserObjectInformation SetUserObjectInformationA
        define SetWindowLong SetWindowLongA
        define SetWindowsHook SetWindowsHookA
        define SetWindowsHookEx SetWindowsHookExA
        define SetWindowText SetWindowTextA
        define SystemParametersInfo SystemParametersInfoA
        define TabbedTextOut TabbedTextOutA
        define UnregisterClass UnregisterClassA
        define VkKeyScan VkKeyScanA
        define VkKeyScanEx VkKeyScanExA
        define WinHelp WinHelpA
        define wsprintf wsprintfA
        define wvsprintf wvsprintfA
    #endif
#else
    extern ActivateKeyboardLayout alias _ActivateKeyboardLayout@8
    extern AdjustWindowRect alias _AdjustWindowRect@12
    extern AdjustWindowRectEx alias _AdjustWindowRectEx@16
    extern AnyPopup alias _AnyPopup@0
    extern AppendMenuA alias _AppendMenuA@16
    extern AppendMenuW alias _AppendMenuW@16
    extern ArrangeIconicWindows alias _ArrangeIconicWindows@4
    extern AttachThreadInput alias _AttachThreadInput@12
    extern BeginDeferWindowPos alias _BeginDeferWindowPos@4
    extern BeginPaint alias _BeginPaint@8
    extern BringWindowToTop alias _BringWindowToTop@4
    extern BroadcastSystemMessageA alias _BroadcastSystemMessageA@20
    extern BroadcastSystemMessageW alias _BroadcastSystemMessageW@20
    extern GetAltTabInfoA alias _GetAltTabInfoA@20
    extern GetAltTabInfoW alias _GetAltTabInfoW@20
    #ifdef APP_UNICODE
        define BroadcastSystemMessage BroadcastSystemMessageW
        define GetAltTabInfo GetAltTabInfoW
    #else
        define BroadcastSystemMessage BroadcastSystemMessageA
        define GetAltTabInfo GetAltTabInfoA
    #endif
    #if NTDDI_VERSION > NTDDI_WIN98_ME
        extern RealGetWindowClassA alias _RealGetWindowClassA
        extern RealGetWindowClassW alias _RealGetWindowClassW
        #ifdef APP_UNICODE
            define RealGetWindowClass RealGetWindowClassW
        #else
            define RealGetWindowClass RealGetWindowClassA
        #endif
    #endif
    extern CallMsgFilterA alias _CallMsgFilterA@8
    extern CallMsgFilterW alias _CallMsgFilterW@8
    extern CallNextHookEx alias _CallNextHookEx@16
    extern CallWindowProcA alias _CallWindowProcA@20
    extern CallWindowProcW alias _CallWindowProcW@20
    extern CascadeChildWindows alias _CascadeChildWindows@8
    extern CascadeWindows alias _CascadeWindows@20
    extern ChangeClipboardChain alias _ChangeClipboardChain@8
    extern ChangeDisplaySettingsA alias _ChangeDisplaySettingsA@8
    extern ChangeDisplaySettingsW alias _ChangeDisplaySettingsW@8
    extern ChangeMenuA alias _ChangeMenuA@20
    extern ChangeMenuW alias _ChangeMenuW@20
    extern CharLowerA alias _CharLowerA@4
    extern CharLowerBuffA alias _CharLowerBuffA@8
    extern CharLowerBuffW alias _CharLowerBuffW@8
    extern CharLowerW alias _CharLowerW@4
    extern CharNextA alias _CharNextA@4
    extern CharNextExA alias _CharNextExA@12
    extern CharNextW alias _CharNextW@4
    extern CharPrevA alias _CharPrevA@8
    extern CharPrevExA alias _CharPrevExA@16
    extern CharPrevW alias _CharPrevW@8
    extern CharToOemA alias _CharToOemA@8
    extern CharToOemBuffA alias _CharToOemBuffA@12
    extern CharToOemBuffW alias _CharToOemBuffW@12
    extern CharToOemW alias _CharToOemW@8
    extern CharUpperA alias _CharUpperA@4
    extern CharUpperBuffA alias _CharUpperBuffA@8
    extern CharUpperBuffW alias _CharUpperBuffW@8
    extern CharUpperW alias _CharUpperW@4
    extern CheckDlgButton alias _CheckDlgButton@12
    extern CheckMenuItem alias _CheckMenuItem@12
    extern CheckMenuRadioItem alias _CheckMenuRadioItem@20
    extern CheckRadioButton alias _CheckRadioButton@16
    extern ChildWindowFromPoint alias _ChildWindowFromPoint@12
    extern ChildWindowFromPointEx alias _ChildWindowFromPointEx@16
    extern ClientToScreen alias _ClientToScreen@8
    extern ClipCursor alias _ClipCursor@4
    extern CloseClipboard alias _CloseClipboard@0
    extern CloseDesktop alias _CloseDesktop@4
    extern CloseWindow alias _CloseWindow@4
    extern CloseWindowStation alias _CloseWindowStation@4
    extern CopyAcceleratorTableA alias _CopyAcceleratorTableA@12
    extern CopyAcceleratorTableW alias _CopyAcceleratorTableW@12
    extern CopyIcon alias _CopyIcon@4
    extern CopyImage alias _CopyImage@20
    extern CopyRect alias _CopyRect@8
    extern CountClipboardFormats alias _CountClipboardFormats@0
    extern CreateAcceleratorTableA alias _CreateAcceleratorTableA@8
    extern CreateAcceleratorTableW alias _CreateAcceleratorTableW@8
    extern CreateCaret alias _CreateCaret@16
    extern CreateCursor alias _CreateCursor@28
    extern CreateDesktopA alias _CreateDesktopA@24
    extern CreateDesktopW alias _CreateDesktopW@24
    extern CreateDialogIndirectParamA alias _CreateDialogIndirectParamA@20
    extern CreateDialogIndirectParamW alias _CreateDialogIndirectParamW@20
    extern CreateDialogParamA alias _CreateDialogParamA@20
    extern CreateDialogParamW alias _CreateDialogParamW@20
    extern CreateIcon alias _CreateIcon@28
    extern CreateIconFromResource alias _CreateIconFromResource@16
    extern CreateIconFromResourceEx alias _CreateIconFromResourceEx@28
    extern CreateIconIndirect alias _CreateIconIndirect@4
    extern CreateMDIWindowA alias _CreateMDIWindowA@40
    extern CreateMDIWindowW alias _CreateMDIWindowW@40
    extern CreateMenu alias _CreateMenu@0
    extern CreatePopupMenu alias _CreatePopupMenu@0
    extern CreateWindowExA alias _CreateWindowExA@48
    extern CreateWindowExW alias _CreateWindowExW@48
    extern CreateWindowStationA alias _CreateWindowStationA@16
    extern CreateWindowStationW alias _CreateWindowStationW@16
    extern DdeAbandonTransaction alias _DdeAbandonTransaction@12
    extern DdeAccessData alias _DdeAccessData@8
    extern DdeAddData alias _DdeAddData@16
    extern DdeClientTransaction alias _DdeClientTransaction@32
    extern DdeCmpStringHandles alias _DdeCmpStringHandles@8
    extern DdeConnect alias _DdeConnect@16
    extern DdeConnectList alias _DdeConnectList@20
    extern DdeCreateDataHandle alias _DdeCreateDataHandle@28
    extern DdeCreateStringHandleA alias _DdeCreateStringHandleA@12
    extern DdeCreateStringHandleW alias _DdeCreateStringHandleW@12
    extern DdeDisconnect alias _DdeDisconnect@4
    extern DdeDisconnectList alias _DdeDisconnectList@4
    extern DdeEnableCallback alias _DdeEnableCallback@12
    extern DdeFreeDataHandle alias _DdeFreeDataHandle@4
    extern DdeFreeStringHandle alias _DdeFreeStringHandle@8
    extern DdeGetData alias _DdeGetData@16
    extern DdeGetLastError alias _DdeGetLastError@4
    extern DdeImpersonateClient alias _DdeImpersonateClient@4
    extern DdeInitializeA alias _DdeInitializeA@16
    extern DdeInitializeW alias _DdeInitializeW@16
    extern DdeKeepStringHandle alias _DdeKeepStringHandle@8
    extern DdeNameService alias _DdeNameService@16
    extern DdePostAdvise alias _DdePostAdvise@12
    extern DdeQueryConvInfo alias _DdeQueryConvInfo@12
    extern DdeQueryNextServer alias _DdeQueryNextServer@8
    extern DdeQueryStringA alias _DdeQueryStringA@20
    extern DdeQueryStringW alias _DdeQueryStringW@20
    extern DdeReconnect alias _DdeReconnect@4
    extern DdeSetQualityOfService alias _DdeSetQualityOfService@12
    extern DdeSetUserHandle alias _DdeSetUserHandle@12
    extern DdeUnaccessData alias _DdeUnaccessData@4
    extern DdeUninitialize alias _DdeUninitialize@4
    extern DefDlgProcA alias _DefDlgProcA@16
    extern DefDlgProcW alias _DefDlgProcW@16
    extern DeferWindowPos alias _DeferWindowPos@32
    extern DefFrameProcA alias _DefFrameProcA@20
    extern DefFrameProcW alias _DefFrameProcW@20
    extern DefMDIChildProcA alias _DefMDIChildProcA@16
    extern DefMDIChildProcW alias _DefMDIChildProcW@16
    extern DefWindowProcA alias _DefWindowProcA@16
    extern DefWindowProcW alias _DefWindowProcW@16
    extern DeleteMenu alias _DeleteMenu@12
    extern DestroyAcceleratorTable alias _DestroyAcceleratorTable@4
    extern DestroyCaret alias _DestroyCaret@0
    extern DestroyCursor alias _DestroyCursor@4
    extern DestroyIcon alias _DestroyIcon@4
    extern DestroyMenu alias _DestroyMenu@4
    extern DestroyWindow alias _DestroyWindow@4
    extern DialogBoxIndirectParamA alias _DialogBoxIndirectParamA@20
    extern DialogBoxIndirectParamW alias _DialogBoxIndirectParamW@20
    extern DialogBoxParamA alias _DialogBoxParamA@20
    extern DialogBoxParamW alias _DialogBoxParamW@20
    extern DispatchMessageA alias _DispatchMessageA@4
    extern DispatchMessageW alias _DispatchMessageW@4
    extern DlgDirListA alias _DlgDirListA@20
    extern DlgDirListComboBoxA alias _DlgDirListComboBoxA@20
    extern DlgDirListComboBoxW alias _DlgDirListComboBoxW@20
    extern DlgDirListW alias _DlgDirListW@20
    extern DlgDirSelectComboBoxExA alias _DlgDirSelectComboBoxExA@16
    extern DlgDirSelectComboBoxExW alias _DlgDirSelectComboBoxExW@16
    extern DlgDirSelectExA alias _DlgDirSelectExA@16
    extern DlgDirSelectExW alias _DlgDirSelectExW@16
    extern DragDetect alias _DragDetect@12
    extern DragObject alias _DragObject@20
    extern DrawAnimatedRects alias _DrawAnimatedRects@16
    extern DrawCaption alias _DrawCaption@16
    extern DrawEdge alias _DrawEdge@16
    extern DrawFocusRect alias _DrawFocusRect@8
    extern DrawFrame alias _DrawFrame@16
    extern DrawFrameControl alias _DrawFrameControl@16
    extern DrawIcon alias _DrawIcon@16
    extern DrawIconEx alias _DrawIconEx@36
    extern DrawMenuBar alias _DrawMenuBar@4
    extern DrawStateA alias _DrawStateA@40
    extern DrawStateW alias _DrawStateW@40
    extern DrawTextA alias _DrawTextA@20
    extern DrawTextExA alias _DrawTextExA@24
    extern DrawTextExW alias _DrawTextExW@24
    extern DrawTextW alias _DrawTextW@20
    extern EditWndProc alias _EditWndProc@16
    extern EmptyClipboard alias _EmptyClipboard@0
    extern EnableMenuItem alias _EnableMenuItem@12
    extern EnableScrollBar alias _EnableScrollBar@12
    extern EnableWindow alias _EnableWindow@8
    extern EndDeferWindowPos alias _EndDeferWindowPos@4
    extern EndDialog alias _EndDialog@8
    extern EndPaint alias _EndPaint@8
    extern EndTask alias _EndTask@12
    extern EnumChildWindows alias _EnumChildWindows@12
    extern EnumClipboardFormats alias _EnumClipboardFormats@4
    extern EnumDesktopsA alias _EnumDesktopsA@12
    extern EnumDesktopsW alias _EnumDesktopsW@12
    extern EnumDesktopWindows alias _EnumDesktopWindows@12
    extern EnumDisplayDevicesA alias _EnumDisplayDevicesA@16
    extern EnumDisplayDevicesW alias _EnumDisplayDevicesW@16
    extern EnumDisplaySettingsA alias _EnumDisplaySettingsA@12
    extern EnumDisplaySettingsW alias _EnumDisplaySettingsW@12
    extern EnumPropsA alias _EnumPropsA@8
    extern EnumPropsExA alias _EnumPropsExA@12
    extern EnumPropsExW alias _EnumPropsExW@12
    extern EnumPropsW alias _EnumPropsW@8
    extern EnumThreadWindows alias _EnumThreadWindows@12
    extern EnumWindows alias _EnumWindows@8
    extern EnumWindowStationsA alias _EnumWindowStationsA@8
    extern EnumWindowStationsW alias _EnumWindowStationsW@8
    extern EqualRect alias _EqualRect@8
    extern ExcludeUpdateRgn alias _ExcludeUpdateRgn@8
    extern ExitWindowsEx alias _ExitWindowsEx@8
    extern FillRect alias _FillRect@12
    extern FindWindowA alias _FindWindowA@8
    extern FindWindowExA alias _FindWindowExA@16
    extern FindWindowExW alias _FindWindowExW@16
    extern FindWindowW alias _FindWindowW@8
    extern FlashWindow alias _FlashWindow@8
    extern FrameRect alias _FrameRect@12
    extern FreeDDElParam alias _FreeDDElParam@8
    extern GetActiveWindow alias _GetActiveWindow@0
    extern GetAsyncKeyState alias _GetAsyncKeyState@4
    extern GetCapture alias _GetCapture@0
    extern GetCaretBlinkTime alias _GetCaretBlinkTime@0
    extern GetCaretPos alias _GetCaretPos@4
    extern GetClassInfoA alias _GetClassInfoA@12
    extern GetClassInfoExA alias _GetClassInfoExA@12
    extern GetClassInfoExW alias _GetClassInfoExW@12
    extern GetClassInfoW alias _GetClassInfoW@12
    extern GetClassLongA alias _GetClassLongA@8
    extern GetClassLongW alias _GetClassLongW@8
    extern GetClassNameA alias _GetClassNameA@12
    extern GetClassNameW alias _GetClassNameW@12
    extern GetClassWord alias _GetClassWord@8
    extern GetClientRect alias _GetClientRect@8
    extern GetClipboardData alias _GetClipboardData@4
    extern GetClipboardFormatNameA alias _GetClipboardFormatNameA@12
    extern GetClipboardFormatNameW alias _GetClipboardFormatNameW@12
    extern GetClipboardOwner alias _GetClipboardOwner@0
    extern GetClipboardViewer alias _GetClipboardViewer@0
    extern GetClipCursor alias _GetClipCursor@4
    extern GetCursor alias _GetCursor@0
    extern GetCursorPos alias _GetCursorPos@4
    extern GetDC alias _GetDC@4
    extern GetDCEx alias _GetDCEx@12
    extern GetDesktopWindow alias _GetDesktopWindow@0
    extern GetDialogBaseUnits alias _GetDialogBaseUnits@0
    extern GetDlgCtrlID alias _GetDlgCtrlID@4
    extern GetDlgItem alias _GetDlgItem@8
    extern GetDlgItemInt alias _GetDlgItemInt@16
    extern GetDlgItemTextA alias _GetDlgItemTextA@16
    extern GetDlgItemTextW alias _GetDlgItemTextW@16
    extern GetDoubleClickTime alias _GetDoubleClickTime@0
    extern GetFocus alias _GetFocus@0
    extern GetForegroundWindow alias _GetForegroundWindow@0
    #if NTDDI_VERSION != NTDDI_WIN95
        #if NTDDI_VERSION != NTDDI_WINNT4
            extern GetGuiResources alias _GetGuiResources@8
        #endif
    #endif
    extern GetIconInfo alias _GetIconInfo@8
    extern GetInputDesktop alias _GetInputDesktop@0
    extern GetInputState alias _GetInputState@0
    extern GetKBCodePage alias _GetKBCodePage@0
    extern GetKeyboardLayout alias _GetKeyboardLayout@4
    extern GetKeyboardLayoutList alias _GetKeyboardLayoutList@8
    extern GetKeyboardLayoutNameA alias _GetKeyboardLayoutNameA@4
    extern GetKeyboardLayoutNameW alias _GetKeyboardLayoutNameW@4
    extern GetKeyboardState alias _GetKeyboardState@4
    extern GetKeyboardType alias _GetKeyboardType@4
    extern GetKeyNameTextA alias _GetKeyNameTextA@12
    extern GetKeyNameTextW alias _GetKeyNameTextW@12
    extern GetKeyState alias _GetKeyState@4
    extern GetLastActivePopup alias _GetLastActivePopup@4
    extern GetMenu alias _GetMenu@4
    extern GetMenuCheckMarkDimensions alias _GetMenuCheckMarkDimensions@0
    extern GetMenuContextHelpId alias _GetMenuContextHelpId@4
    extern GetMenuDefaultItem alias _GetMenuDefaultItem@12
    extern GetMenuItemCount alias _GetMenuItemCount@4
    extern GetMenuItemID alias _GetMenuItemID@8
    extern GetMenuItemInfoA alias _GetMenuItemInfoA@16
    extern GetMenuItemInfoW alias _GetMenuItemInfoW@16
    extern GetMenuItemRect alias _GetMenuItemRect@16
    extern GetMenuState alias _GetMenuState@12
    extern GetMenuStringA alias _GetMenuStringA@20
    extern GetMenuStringW alias _GetMenuStringW@20
    extern GetMessageA alias _GetMessageA@16
    extern GetMessageExtraInfo alias _GetMessageExtraInfo@0
    extern GetMessagePos alias _GetMessagePos@0
    extern GetMessageTime alias _GetMessageTime@0
    extern GetMessageW alias _GetMessageW@16
    extern GetNextDlgGroupItem alias _GetNextDlgGroupItem@12
    extern GetNextDlgTabItem alias _GetNextDlgTabItem@12
    extern GetOpenClipboardWindow alias _GetOpenClipboardWindow@0
    extern GetParent alias _GetParent@4
    extern GetPriorityClipboardFormat alias _GetPriorityClipboardFormat@8
    extern GetProcessWindowStation alias _GetProcessWindowStation@0
    extern GetPropA alias _GetPropA@8
    extern GetPropW alias _GetPropW@8
    extern GetQueueStatus alias _GetQueueStatus@4
    extern GetScrollInfo alias _GetScrollInfo@12
    extern GetScrollPos alias _GetScrollPos@8
    extern GetScrollRange alias _GetScrollRange@16
    extern GetShellWindow alias _GetShellWindow@0
    extern GetSubMenu alias _GetSubMenu@8
    extern GetSysColor alias _GetSysColor@4
    extern GetSysColorBrush alias _GetSysColorBrush@4
    extern GetSystemMenu alias _GetSystemMenu@8
    extern GetSystemMetrics alias _GetSystemMetrics@4
    extern GetTabbedTextExtentA alias _GetTabbedTextExtentA@20
    extern GetTabbedTextExtentW alias _GetTabbedTextExtentW@20
    extern GetThreadDesktop alias _GetThreadDesktop@4
    extern GetTopWindow alias _GetTopWindow@4
    extern GetUpdateRect alias _GetUpdateRect@12
    extern GetUpdateRgn alias _GetUpdateRgn@12
    extern GetUserObjectInformationA alias _GetUserObjectInformationA@20
    extern GetUserObjectInformationW alias _GetUserObjectInformationW@20
    extern GetUserObjectSecurity alias _GetUserObjectSecurity@20
    extern GetWindow alias _GetWindow@8
    extern GetWindowContextHelpId alias _GetWindowContextHelpId@4
    extern GetWindowDC alias _GetWindowDC@4
    extern GetWindowLongA alias _GetWindowLongA@8
    extern GetWindowLongW alias _GetWindowLongW@8
    extern GetWindowPlacement alias _GetWindowPlacement@8
    extern GetWindowRect alias _GetWindowRect@8
    extern GetWindowRgn alias _GetWindowRgn@8
    extern GetWindowTextA alias _GetWindowTextA@12
    extern GetWindowTextLengthA alias _GetWindowTextLengthA@4
    extern GetWindowTextLengthW alias _GetWindowTextLengthW@4
    extern GetWindowTextW alias _GetWindowTextW@12
    extern GetWindowThreadProcessId alias _GetWindowThreadProcessId@8
    extern GetWindowWord alias _GetWindowWord@8
    extern GrayStringA alias _GrayStringA@36
    extern GrayStringW alias _GrayStringW@36
    extern HideCaret alias _HideCaret@4
    extern HiliteMenuItem alias _HiliteMenuItem@16
    extern ImpersonateDdeClientWindow alias _ImpersonateDdeClientWindow@8
    extern InflateRect alias _InflateRect@12
    extern InSendMessage alias _InSendMessage@0
    extern InsertMenuA alias _InsertMenuA@20
    extern InsertMenuItemA alias _InsertMenuItemA@16
    extern InsertMenuItemW alias _InsertMenuItemW@16
    extern InsertMenuW alias _InsertMenuW@20
    extern InternalGetWindowText alias _InternalGetWindowText@12
    extern IntersectRect alias _IntersectRect@12
    extern InvalidateRect alias _InvalidateRect@12
    extern InvalidateRgn alias _InvalidateRgn@12
    extern InvertRect alias _InvertRect@8
    extern IsCharAlphaA alias _IsCharAlphaA@4
    extern IsCharAlphaNumericA alias _IsCharAlphaNumericA@4
    extern IsCharAlphaNumericW alias _IsCharAlphaNumericW@4
    extern IsCharAlphaW alias _IsCharAlphaW@4
    extern IsCharLowerA alias _IsCharLowerA@4
    extern IsCharLowerW alias _IsCharLowerW@4
    extern IsCharUpperA alias _IsCharUpperA@4
    extern IsCharUpperW alias _IsCharUpperW@4
    extern IsChild alias _IsChild@8
    extern IsClipboardFormatAvailable alias _IsClipboardFormatAvailable@4
    extern IsDialogMessageA alias _IsDialogMessageA@8
    extern IsDialogMessageW alias _IsDialogMessageW@8
    extern IsDlgButtonChecked alias _IsDlgButtonChecked@8
    extern IsIconic alias _IsIconic@4
    extern IsMenu alias _IsMenu@4
    extern IsRectEmpty alias _IsRectEmpty@4
    extern IsWindow alias _IsWindow@4
    extern IsWindowEnabled alias _IsWindowEnabled@4
    extern IsWindowUnicode alias _IsWindowUnicode@4
    extern IsWindowVisible alias _IsWindowVisible@4
    extern IsZoomed alias _IsZoomed@4
    extern KillTimer alias _KillTimer@8
    extern LoadAcceleratorsA alias _LoadAcceleratorsA@8
    extern LoadAcceleratorsW alias _LoadAcceleratorsW@8
    extern LoadBitmapA alias _LoadBitmapA@8
    extern LoadBitmapW alias _LoadBitmapW@8
    extern LoadCursorA alias _LoadCursorA@8
    extern LoadCursorFromFileA alias _LoadCursorFromFileA@4
    extern LoadCursorFromFileW alias _LoadCursorFromFileW@4
    extern LoadCursorW alias _LoadCursorW@8
    extern LoadIconA alias _LoadIconA@8
    extern LoadIconW alias _LoadIconW@8
    extern LoadImageA alias _LoadImageA@24
    extern LoadImageW alias _LoadImageW@24
    extern LoadKeyboardLayoutA alias _LoadKeyboardLayoutA@8
    extern LoadKeyboardLayoutW alias _LoadKeyboardLayoutW@8
    extern LoadMenuA alias _LoadMenuA@8
    extern LoadMenuIndirectA alias _LoadMenuIndirectA@4
    extern LoadMenuIndirectW alias _LoadMenuIndirectW@4
    extern LoadMenuW alias _LoadMenuW@8
    extern LoadStringA alias _LoadStringA@16
    extern LoadStringW alias _LoadStringW@16
    extern LockWindowUpdate alias _LockWindowUpdate@4
    extern LookupIconIdFromDirectory alias _LookupIconIdFromDirectory@8
    extern LookupIconIdFromDirectoryEx alias _LookupIconIdFromDirectoryEx@20
    extern MapDialogRect alias _MapDialogRect@8
    extern MapVirtualKeyA alias _MapVirtualKeyA@8
    extern MapVirtualKeyExA alias _MapVirtualKeyExA@12
    extern MapVirtualKeyExW alias _MapVirtualKeyExW@12
    extern MapVirtualKeyW alias _MapVirtualKeyW@8
    extern MapWindowPoints alias _MapWindowPoints@16
    extern MenuItemFromPoint alias _MenuItemFromPoint@16
    extern MessageBeep alias _MessageBeep@4
    extern MessageBoxA alias _MessageBoxA@16
    extern MessageBoxExA alias _MessageBoxExA@20
    extern MessageBoxExW alias _MessageBoxExW@20
    extern MessageBoxIndirectA alias _MessageBoxIndirectA@4
    extern MessageBoxIndirectW alias _MessageBoxIndirectW@4
    extern MessageBoxW alias _MessageBoxW@16
    extern ModifyMenuA alias _ModifyMenuA@20
    extern ModifyMenuW alias _ModifyMenuW@20
    extern MoveWindow alias _MoveWindow@24
    extern MsgWaitForMultipleObjects alias _MsgWaitForMultipleObjects@20
    extern OemKeyScan alias _OemKeyScan@4
    extern OemToCharA alias _OemToCharA@8
    extern OemToCharBuffA alias _OemToCharBuffA@12
    extern OemToCharBuffW alias _OemToCharBuffW@12
    extern OemToCharW alias _OemToCharW@8
    extern OffsetRect alias _OffsetRect@12
    extern OpenClipboard alias _OpenClipboard@4
    extern OpenDesktopA alias _OpenDesktopA@16
    extern OpenDesktopW alias _OpenDesktopW@16
    extern OpenIcon alias _OpenIcon@4
    extern OpenInputDesktop alias _OpenInputDesktop@12
    extern OpenWindowStationA alias _OpenWindowStationA@12
    extern OpenWindowStationW alias _OpenWindowStationW@12
    extern PackDDElParam alias _PackDDElParam@12
    extern PaintDesktop alias _PaintDesktop@4
    extern PeekMessageA alias _PeekMessageA@20
    extern PeekMessageW alias _PeekMessageW@20
    extern PostMessageA alias _PostMessageA@16
    extern PostMessageW alias _PostMessageW@16
    extern PostQuitMessage alias _PostQuitMessage@4
    extern PostThreadMessageA alias _PostThreadMessageA@16
    extern PostThreadMessageW alias _PostThreadMessageW@16
    extern PtInRect alias _PtInRect@12
    extern RedrawWindow alias _RedrawWindow@16
    extern RegisterClassA alias _RegisterClassA@4
    extern RegisterClassExA alias _RegisterClassExA@4
    extern RegisterClassExW alias _RegisterClassExW@4
    extern RegisterClassW alias _RegisterClassW@4
    extern RegisterClipboardFormatA alias _RegisterClipboardFormatA@4
    extern RegisterClipboardFormatW alias _RegisterClipboardFormatW@4
    extern RegisterHotKey alias _RegisterHotKey@16
    extern RegisterWindowMessageA alias _RegisterWindowMessageA@4
    extern RegisterWindowMessageW alias _RegisterWindowMessageW@4
    extern ReleaseCapture alias _ReleaseCapture@0
    extern ReleaseDC alias _ReleaseDC@8
    extern RemoveMenu alias _RemoveMenu@12
    extern RemovePropA alias _RemovePropA@8
    extern RemovePropW alias _RemovePropW@8
    extern ReplyMessage alias _ReplyMessage@4
    extern ReuseDDElParam alias _ReuseDDElParam@20
    extern ScreenToClient alias _ScreenToClient@8
    extern ScrollDC alias _ScrollDC@28
    extern ScrollWindow alias _ScrollWindow@20
    extern ScrollWindowEx alias _ScrollWindowEx@32
    extern SendDlgItemMessageA alias _SendDlgItemMessageA@20
    extern SendDlgItemMessageW alias _SendDlgItemMessageW@20
    extern SendMessageA alias _SendMessageA@16
    extern SendMessageCallbackA alias _SendMessageCallbackA@24
    extern SendMessageCallbackW alias _SendMessageCallbackW@24
    extern SendMessageTimeoutA alias _SendMessageTimeoutA@28
    extern SendMessageTimeoutW alias _SendMessageTimeoutW@28
    extern SendMessageW alias _SendMessageW@16
    extern SendNotifyMessageA alias _SendNotifyMessageA@16
    extern SendNotifyMessageW alias _SendNotifyMessageW@16
    extern SetActiveWindow alias _SetActiveWindow@4
    extern SetCapture alias _SetCapture@4
    extern SetCaretBlinkTime alias _SetCaretBlinkTime@4
    extern SetCaretPos alias _SetCaretPos@8
    extern SetClassLongA alias _SetClassLongA@12
    extern SetClassLongW alias _SetClassLongW@12
    extern SetClassWord alias _SetClassWord@12
    extern SetClipboardData alias _SetClipboardData@8
    extern SetClipboardViewer alias _SetClipboardViewer@4
    extern SetCursor alias _SetCursor@4
    extern SetCursorPos alias _SetCursorPos@8
    extern SetDebugErrorLevel alias _SetDebugErrorLevel@4
    extern SetDlgItemInt alias _SetDlgItemInt@16
    extern SetDlgItemTextA alias _SetDlgItemTextA@12
    extern SetDlgItemTextW alias _SetDlgItemTextW@12
    extern SetDoubleClickTime alias _SetDoubleClickTime@4
    extern SetFocus alias _SetFocus@4
    extern SetForegroundWindow alias _SetForegroundWindow@4
    extern SetKeyboardState alias _SetKeyboardState@4
    extern SetLastErrorEx alias _SetLastErrorEx@8
    extern SetMenu alias _SetMenu@8
    extern SetMenuContextHelpId alias _SetMenuContextHelpId@8
    extern SetMenuDefaultItem alias _SetMenuDefaultItem@12
    extern SetMenuItemBitmaps alias _SetMenuItemBitmaps@20
    extern SetMenuItemInfoA alias _SetMenuItemInfoA@16
    extern SetMenuItemInfoW alias _SetMenuItemInfoW@16
    extern SetMessageExtraInfo alias _SetMessageExtraInfo@4
    extern SetMessageQueue alias _SetMessageQueue@4
    extern SetParent alias _SetParent@8
    extern SetProcessWindowStation alias _SetProcessWindowStation@4
    extern SetPropA alias _SetPropA@12
    extern SetPropW alias _SetPropW@12
    extern SetRect alias _SetRect@20
    extern SetRectEmpty alias _SetRectEmpty@4
    extern SetScrollInfo alias _SetScrollInfo@16
    extern SetScrollPos alias _SetScrollPos@16
    extern SetScrollRange alias _SetScrollRange@20
    extern SetShellWindow alias _SetShellWindow@4
    extern SetSysColors alias _SetSysColors@12
    extern SetSystemCursor alias _SetSystemCursor@8
    extern SetThreadDesktop alias _SetThreadDesktop@4
    extern SetTimer alias _SetTimer@16
    extern SetUserObjectInformationA alias _SetUserObjectInformationA@16
    extern SetUserObjectInformationW alias _SetUserObjectInformationW@16
    extern SetUserObjectSecurity alias _SetUserObjectSecurity@12
    extern SetWindowContextHelpId alias _SetWindowContextHelpId@8
    extern SetWindowLongA alias _SetWindowLongA@12
    extern SetWindowLongW alias _SetWindowLongW@12
    extern SetWindowPlacement alias _SetWindowPlacement@8
    extern SetWindowPos alias _SetWindowPos@28
    extern SetWindowRgn alias _SetWindowRgn@12
    extern SetWindowsHookA alias _SetWindowsHookA@8
    extern SetWindowsHookExA alias _SetWindowsHookExA@16
    extern SetWindowsHookExW alias _SetWindowsHookExW@16
    extern SetWindowsHookW alias _SetWindowsHookW@8
    extern SetWindowTextA alias _SetWindowTextA@8
    extern SetWindowTextW alias _SetWindowTextW@8
    extern SetWindowWord alias _SetWindowWord@12
    extern ShowCaret alias _ShowCaret@4
    extern ShowCursor alias _ShowCursor@4
    extern ShowOwnedPopups alias _ShowOwnedPopups@8
    extern ShowScrollBar alias _ShowScrollBar@12
    extern ShowWindow alias _ShowWindow@8
    extern ShowWindowAsync alias _ShowWindowAsync@8
    extern SubtractRect alias _SubtractRect@12
    extern SwapMouseButton alias _SwapMouseButton@4
    extern SwitchDesktop alias _SwitchDesktop@4
    extern SwitchToThisWindow alias _SwitchToThisWindow@8
    extern SystemParametersInfoA alias _SystemParametersInfoA@16
    extern SystemParametersInfoW alias _SystemParametersInfoW@16
    extern TabbedTextOutA alias _TabbedTextOutA@32
    extern TabbedTextOutW alias _TabbedTextOutW@32
    extern TileChildWindows alias _TileChildWindows@8
    extern TileWindows alias _TileWindows@20
    extern ToAscii alias _ToAscii@20
    extern ToAsciiEx alias _ToAsciiEx@24
    extern ToUnicode alias _ToUnicode@24
    extern TrackPopupMenu alias _TrackPopupMenu@28
    extern TrackPopupMenuEx alias _TrackPopupMenuEx@24
    extern TranslateAcceleratorA alias _TranslateAcceleratorA@12
    extern TranslateAcceleratorW alias _TranslateAcceleratorW@12
    extern TranslateMDISysAccel alias _TranslateMDISysAccel@8
    extern TranslateMessage alias _TranslateMessage@4
    extern UnhookWindowsHook alias _UnhookWindowsHook@8
    extern UnhookWindowsHookEx alias _UnhookWindowsHookEx@4
    extern UnionRect alias _UnionRect@12
    extern UnloadKeyboardLayout alias _UnloadKeyboardLayout@4
    extern UnpackDDElParam alias _UnpackDDElParam@16
    extern UnregisterClassA alias _UnregisterClassA@8
    extern UnregisterClassW alias _UnregisterClassW@8
    extern UnregisterHotKey alias _UnregisterHotKey@8
    extern UpdateWindow alias _UpdateWindow@4
    extern ValidateRect alias _ValidateRect@8
    extern ValidateRgn alias _ValidateRgn@8
    extern VkKeyScanA alias _VkKeyScanA@4
    extern VkKeyScanExA alias _VkKeyScanExA@8
    extern VkKeyScanExW alias _VkKeyScanExW@8
    extern VkKeyScanW alias _VkKeyScanW@4
    extern WaitForInputIdle alias _WaitForInputIdle@8
    extern WaitMessage alias _WaitMessage@0
    extern WindowFromDC alias _WindowFromDC@4
    extern WindowFromPoint alias _WindowFromPoint@8
    extern WinHelpA alias _WinHelpA@16
    extern WinHelpW alias _WinHelpW@16
    extern keybd_event alias _keybd_event@16
    extern mouse_event alias _mouse_event@20
    extern wsprintfA alias _wsprintfA
    extern wsprintfW alias _wsprintfW
    extern wvsprintfA alias _wvsprintfA@12
    extern wvsprintfW alias _wvsprintfW@12

    #if NTDDI_VERSION != NTDDI_WINNT4
        extern UnhookWinEvent alias _UnhookWinEvent@4
        extern WINNLSEnableIME alias _WINNLSEnableIME@8
    #endif

    #if NTDDI_VERSION >= NTDDI_WIN98_ME
        extern BlockInput alias _BlockInput@4
        extern ChangeDisplaySettingsExA alias _ChangeDisplaySettingsExA@20
        extern ChangeDisplaySettingsExW alias _ChangeDisplaySettingsExW@20
        extern EndMenu alias _EndMenu@0
        extern EnumDisplayMonitors alias _EnumDisplayMonitors@16
        extern EnumDisplaySettingsExA alias _EnumDisplaySettingsExA@16
        extern EnumDisplaySettingsExW alias _EnumDisplaySettingsExW@16
        extern FlashWindowEx alias _FlashWindowEx@4
        extern GetAncestor alias _GetAncestor@8
        extern GetClipboardSequenceNumber alias _GetClipboardSequenceNumber@0
        extern GetComboBoxInfo alias _GetComboBoxInfo@8
        extern GetCursorInfo alias _GetCursorInfo@4
        extern GetGUIThreadInfo alias _GetGUIThreadInfo@8
        extern GetListBoxInfo alias _GetListBoxInfo@4
        extern GetMenuBarInfo alias _GetMenuBarInfo@16
        extern GetMenuInfo alias _GetMenuInfo@8
        extern GetProcessDefaultLayout alias _GetProcessDefaultLayout@4
        extern GetScrollBarInfo alias _GetScrollBarInfo@12
        extern GetTitleBarInfo alias _GetTitleBarInfo@8
        extern GetWindowInfo alias _GetWindowInfo@8
        extern GetWindowModuleFileName alias _GetWindowModuleFileName@12
        extern GetWindowModuleFileNameA alias _GetWindowModuleFileNameA@12
        extern GetWindowModuleFileNameW alias _GetWindowModuleFileNameW@12
        extern IMPGetIMEA alias _IMPGetIMEA@8
        extern IMPGetIMEW alias _IMPGetIMEW@8
        extern IMPQueryIMEA alias _IMPQueryIMEA@4
        extern IMPQueryIMEW alias _IMPQueryIMEW@4
        extern IMPSetIMEA alias _IMPSetIMEA@8
        extern IMPSetIMEW alias _IMPSetIMEW@8
        extern MsgWaitForMultipleObjectsEx alias _MsgWaitForMultipleObjectsEx@20
        extern NotifyWinEvent alias _NotifyWinEvent@16
        extern RealChildWindowFromPoint alias _RealChildWindowFromPoint@12
        extern SendIMEMessageExA alias _SendIMEMessageExA@8
        extern SendIMEMessageExW alias _SendIMEMessageExW@8
        extern SendInput alias _SendInput@12
        extern SetWinEventHook alias _SetWinEventHook@28
        extern ToUnicodeEx alias _ToUnicodeEx@28
        extern TrackMouseEvent alias _TrackMouseEvent@4

        #if NTDDI_VERSION != NTDDI_WINNT4
            extern GetMonitorInfoA alias _GetMonitorInfoA@8
            extern GetMonitorInfoW alias _GetMonitorInfoW@8
            extern InSendMessageEx alias _InSendMessageEx@4
            extern MonitorFromPoint alias _MonitorFromPoint@12
            extern MonitorFromRect alias _MonitorFromRect@8
            extern MonitorFromWindow alias _MonitorFromWindow@8
            extern RegisterDeviceNotificationA alias _RegisterDeviceNotificationA@12
            extern RegisterDeviceNotificationW alias _RegisterDeviceNotificationW@12
            extern SetMenuInfo alias _SetMenuInfo@8
            extern SetProcessDefaultLayout alias _SetProcessDefaultLayout@4
            extern UnregisterDeviceNotification alias _UnregisterDeviceNotification@4
            #ifdef APP_UNICODE
                define GetMonitorInfo GetMonitorInfoW
                define RegisterDeviceNotification RegisterDeviceNotificationW
            #else
                define GetMonitorInfo GetMonitorInfoA
                define RegisterDeviceNotification RegisterDeviceNotificationA
            #endif
        #endif

        #ifdef APP_UNICODE
            define ChangeDisplaySettingsEx ChangeDisplaySettingsExW
            define EnumDisplaySettingsEx EnumDisplaySettingsExW
            define IMPGetIME IMPGetIMEW
            define IMPQueryIME IMPQueryIMEW
            define IMPSetIME IMPSetIMEW
            define SendIMEMessageEx SendIMEMessageExW
        #else
            define ChangeDisplaySettingsEx ChangeDisplaySettingsExA
            define EnumDisplaySettingsEx EnumDisplaySettingsExA
            define IMPGetIME IMPGetIMEA
            define IMPQueryIME IMPQueryIMEA
            define IMPSetIME IMPSetIMEA
            define SendIMEMessageEx SendIMEMessageExA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WINNT4
        extern ClientThreadSetup alias _ClientThreadSetup@0
        extern CreateDialogIndirectParamAorW alias _CreateDialogIndirectParamAorW@24
        extern DdeGetQualityOfService alias _DdeGetQualityOfService@12
        extern DeregisterShellHookWindow alias _DeregisterShellHookWindow@4
        extern DrawMenuBarTemp alias _DrawMenuBarTemp@20
        extern GetAppCompatFlags alias _GetAppCompatFlags@4
        extern GetProgmanWindow alias _GetProgmanWindow@0
        extern GetTaskmanWindow alias _GetTaskmanWindow@0
        extern IsHungAppWindow alias _IsHungAppWindow@4
        extern LoadKeyboardLayoutEx alias _LoadKeyboardLayoutEx@12
        extern LoadLocalFonts alias _LoadLocalFonts@0
        extern LoadRemoteFonts alias _LoadRemoteFonts@0
        extern MBToWCSEx alias _MBToWCSEx@24
        extern MB_GetString alias _MB_GetString@4
        extern MenuWindowProcA alias _MenuWindowProcA@20
        extern MenuWindowProcW alias _MenuWindowProcW@20
        extern PrivateExtractIconExA alias _PrivateExtractIconExA@20
        extern PrivateExtractIconExW alias _PrivateExtractIconExW@20
        extern PrivateExtractIconsA alias _PrivateExtractIconsA@32
        extern PrivateExtractIconsW alias _PrivateExtractIconsW@32
        extern QuerySendMessage alias _QuerySendMessage@4
        extern RegisterServicesProcess alias _RegisterServicesProcess@4
        extern RegisterShellHookWindow alias _RegisterShellHookWindow@4
        extern SetProgmanWindow alias _SetProgmanWindow@4
        extern SetShellWindowEx alias _SetShellWindowEx@8
        extern SetSystemMenu alias _SetSystemMenu@8
        extern SetTaskmanWindow alias _SetTaskmanWindow@4
        extern SetWindowStationUser alias _SetWindowStationUser@16
        extern ShowStartGlass alias _ShowStartGlass@4
        extern TranslateMessageEx alias _TranslateMessageEx@8
        extern UserRealizePalette alias _UserRealizePalette@4
        extern UserRegisterWowHandlers alias _UserRegisterWowHandlers@8
        #ifdef APP_UNICODE
            define MenuWindowProc MenuWindowProcW
            define PrivateExtractIconEx PrivateExtractIconExW
            define PrivateExtractIcons PrivateExtractIconsW
        #else
            define MenuWindowProc MenuWindowProcA
            define PrivateExtractIconEx PrivateExtractIconExA
            define PrivateExtractIcons PrivateExtractIconsA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WIN2K
        extern CliImmSetHotKey alias _CliImmSetHotKey@16
        extern CtxInitUser32 alias _CtxInitUser32@0
        extern DeviceEventWorker alias _DeviceEventWorker@20
        extern GetAppCompatFlags2 alias _GetAppCompatFlags2@4
        extern GetLastInputInfo alias _GetLastInputInfo@4
        extern GetMouseMovePointsEx alias _GetMouseMovePointsEx@20
        extern InitializeLpkHooks alias _InitializeLpkHooks@4
        extern LockSetForegroundWindow alias _LockSetForegroundWindow@4
        extern LockWorkStation alias _LockWorkStation@0
        extern SetLayeredWindowAttributes alias _SetLayeredWindowAttributes@16
        extern UpdateLayeredWindow alias _UpdateLayeredWindow@36
        extern UserHandleGrantAccess alias _UserHandleGrantAccess@12
        extern AllowSetForegroundWindow alias _AllowSetForegroundWindow@4
        extern AnimateWindow alias _AnimateWindow@12
    #endif

    #if NTDDI_VERSION >= NTDDI_WINXP
        extern AllowForegroundActivation alias _AllowForegroundActivation@0
        extern BroadcastSystemMessageExA alias _BroadcastSystemMessageExA@24
        extern BroadcastSystemMessageExW alias _BroadcastSystemMessageExW@24
        extern BuildReasonArray alias _BuildReasonArray@4
        extern CreateSystemThreads alias _CreateSystemThreads@4
        extern CsrBroadcastSystemMessageExW alias _CsrBroadcastSystemMessageExW@20
        extern DefRawInputProc alias _DefRawInputProc@12
        extern DestroyReasons alias _DestroyReasons@4
        extern DisableProcessWindowsGhosting alias _DisableProcessWindowsGhosting@0
        extern GetLayeredWindowAttributes alias _GetLayeredWindowAttributes@16
        extern GetRawInputBuffer alias _GetRawInputBuffer@12
        extern GetRawInputData alias _GetRawInputData@20
        extern GetRawInputDeviceInfoA alias _GetRawInputDeviceInfoA@16
        extern GetRawInputDeviceInfoW alias _GetRawInputDeviceInfoW@16
        extern GetRawInputDeviceList alias _GetRawInputDeviceList@12
        extern GetReasonTitleFromReasonCode alias _GetReasonTitleFromReasonCode@12
        extern GetRegisteredRawInputDevices alias _GetRegisteredRawInputDevices@12
        extern GetWindowRgnBox alias _GetWindowRgnBox@8
        extern IsGUIThread alias _IsGUIThread@4
        #if NTDDI_VERSION < NTDDI_WINXPALL
            extern IsProcess16Bit alias _IsProcess16Bit@0
            extern SetLogonNotifyWindow alias _SetLogonNotifyWindow@8
        #endif
        extern IsServerSideWindow alias _IsServerSideWindow@4
        extern IsWinEventHookInstalled alias _IsWinEventHookInstalled@4
        extern IsWindowInDestroy alias _IsWindowInDestroy@4
        extern MessageBoxTimeoutA alias _MessageBoxTimeoutA@24
        extern MessageBoxTimeoutW alias _MessageBoxTimeoutW@24
        extern PrintWindow alias _PrintWindow@12
        extern RecordShutdownReason alias _RecordShutdownReason@4
        extern RegisterMessagePumpHook alias _RegisterMessagePumpHook@4
        extern RegisterRawInputDevices alias _RegisterRawInputDevices@12
        extern RegisterUserApiHook alias _RegisterUserApiHook@8
        extern UnregisterMessagePumpHook alias _UnregisterMessagePumpHook@0
        extern UnregisterUserApiHook alias _UnregisterUserApiHook@0
        #ifdef APP_UNICODE
            define GetRawInputDeviceInfo GetRawInputDeviceInfoW
            define MessageBoxTimeout MessageBoxTimeoutW
        #else
            define GetRawInputDeviceInfo GetRawInputDeviceInfoA
            define MessageBoxTimeout MessageBoxTimeoutA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_VISTA
        extern AddClipboardFormatListener alias _AddClipboardFormatListener@4
        extern CancelShutdown alias _CancelShutdown@0
        extern ChangeWindowMessageFilter alias _ChangeWindowMessageFilter@8
        extern CreateDesktopExA alias _CreateDesktopExA@32
        extern CreateDesktopExW alias _CreateDesktopExW@32
        extern DisplayConfigGetDeviceInfo alias _DisplayConfigGetDeviceInfo@4
        extern DisplayConfigSetDeviceInfo alias _DisplayConfigSetDeviceInfo@4
        extern FrostCrashedWindow alias _FrostCrashedWindow@8
        extern GetIconInfoExA alias _GetIconInfoExA@8
        extern GetIconInfoExW alias _GetIconInfoExW@8
        extern GetPhysicalCursorPos alias _GetPhysicalCursorPos@4
        extern GetSendMessageReceiver alias _GetSendMessageReceiver@4
        extern GetUpdatedClipboardFormats alias _GetUpdatedClipboardFormats@12
        extern GetWindowMinimizeRect alias _GetWindowMinimizeRect@8
        extern GhostWindowFromHungWindow alias _GhostWindowFromHungWindow@4
        extern HungWindowFromGhostWindow alias _HungWindowFromGhostWindow@4
        extern IsProcessDPIAware alias _IsProcessDPIAware@0
        extern IsSETEnabled alias _IsSETEnabled@0
        extern IsThreadDesktopComposited alias _IsThreadDesktopComposited@0
        extern IsWindowRedirectedForPrint alias _IsWindowRedirectedForPrint@4
        extern LogicalToPhysicalPoint alias _LogicalToPhysicalPoint@8
        extern PhysicalToLogicalPoint alias _PhysicalToLogicalPoint@8
        extern RegisterPowerSettingNotification alias _RegisterPowerSettingNotification@12
        extern RemoveClipboardFormatListener alias _RemoveClipboardFormatListener@4
        extern SetPhysicalCursorPos alias _SetPhysicalCursorPos@8
        extern SetProcessDPIAware alias _SetProcessDPIAware@0
        extern ShutdownBlockReasonCreate alias _ShutdownBlockReasonCreate@8
        extern ShutdownBlockReasonDestroy alias _ShutdownBlockReasonDestroy@4
        extern ShutdownBlockReasonQuery alias _ShutdownBlockReasonQuery@12
        extern SoundSentry alias _SoundSentry@0
        extern UnregisterPowerSettingNotification alias _UnregisterPowerSettingNotification@4
        extern UpdateLayeredWindowIndirect alias _UpdateLayeredWindowIndirect@8
        extern UpdateWindowTransform alias _UpdateWindowTransform@12
        #ifdef APP_UNICODE
            define CreateDesktopEx CreateDesktopExW
            define GetIconInfoEx GetIconInfoExW
        #else
            define CreateDesktopEx CreateDesktopExA
            define GetIconInfoEx GetIconInfoExA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WIN7
        extern CalculatePopupWindowPosition alias _CalculatePopupWindowPosition@20
        extern ChangeWindowMessageFilterEx alias _ChangeWindowMessageFilterEx@16
        extern CloseGestureInfoHandle alias _CloseGestureInfoHandle@4
        extern CloseTouchInputHandle alias _CloseTouchInputHandle@4
        extern DwmGetDxSharedSurface alias _DwmGetDxSharedSurface@24
        extern GetDisplayConfigBufferSizes alias _GetDisplayConfigBufferSizes@12
        extern GetGestureConfig alias _GetGestureConfig@24
        extern GetGestureExtraArgs alias _GetGestureExtraArgs@12
        extern GetGestureInfo alias _GetGestureInfo@8
        extern GetTouchInputInfo alias _GetTouchInputInfo@16
        extern GetWindowCompositionAttribute alias _GetWindowCompositionAttribute@8
        extern GetWindowDisplayAffinity alias _GetWindowDisplayAffinity@8
        extern IsTopLevelWindow alias _IsTopLevelWindow@4
        extern IsTouchWindow alias _IsTouchWindow@8
        extern QueryDisplayConfig alias _QueryDisplayConfig@24
        extern RegisterTouchWindow alias _RegisterTouchWindow@8
        extern SetDisplayConfig alias _SetDisplayConfig@20
        extern SetGestureConfig alias _SetGestureConfig@20
        extern SetWindowCompositionAttribute alias _SetWindowCompositionAttribute@8
        extern SetWindowDisplayAffinity alias _SetWindowDisplayAffinity@8
        extern UnregisterTouchWindow alias _UnregisterTouchWindow@4
    #endif

    #if NTDDI_VERSION >= NTDDI_WIN8
        extern CreateWindowInBand alias _CreateWindowInBand@52
        extern EnableMouseInPointer alias _EnableMouseInPointer@4
        extern EvaluateProximityToPolygon alias _EvaluateProximityToPolygon@16
        extern EvaluateProximityToRect alias _EvaluateProximityToRect@12
        extern GetAutoRotationState alias _GetAutoRotationState@4
        extern GetCIMSSM alias _GetCIMSSM@4
        extern GetCurrentInputMessageSource alias _GetCurrentInputMessageSource@4
        extern GetDisplayAutoRotationPreferences alias _GetDisplayAutoRotationPreferences@4
        extern GetPointerCursorId alias _GetPointerCursorId@8
        extern GetPointerDevice alias _GetPointerDevice@8
        extern GetPointerDeviceCursors alias _GetPointerDeviceCursors@12
        extern GetPointerDeviceProperties alias _GetPointerDeviceProperties@12
        extern GetPointerDeviceRects alias _GetPointerDeviceRects@12
        extern GetPointerDevices alias _GetPointerDevices@8
        extern GetPointerFrameInfo alias _GetPointerFrameInfo@12
        extern GetPointerFrameInfoHistory alias _GetPointerFrameInfoHistory@16
        extern GetPointerFramePenInfo alias _GetPointerFramePenInfo@12
        extern GetPointerFramePenInfoHistory alias _GetPointerFramePenInfoHistory@16
        extern GetPointerFrameTouchInfo alias _GetPointerFrameTouchInfo@12
        extern GetPointerFrameTouchInfoHistory alias _GetPointerFrameTouchInfoHistory@16
        extern GetPointerInfo alias _GetPointerInfo@8
        extern GetPointerInfoHistory alias _GetPointerInfoHistory@12
        extern GetPointerPenInfo alias _GetPointerPenInfo@8
        extern GetPointerPenInfoHistory alias _GetPointerPenInfoHistory@12
        extern GetPointerTouchInfo alias _GetPointerTouchInfo@8
        extern GetPointerTouchInfoHistory alias _GetPointerTouchInfoHistory@12
        extern GetPointerType alias _GetPointerType@8
        extern GetRawPointerDeviceData alias _GetRawPointerDeviceData@20
        extern GetUnpredictedMessagePos alias _GetUnpredictedMessagePos@0
        extern GetWindowFeedbackSetting alias _GetWindowFeedbackSetting@20
        extern InitializeTouchInjection alias _InitializeTouchInjection@8
        extern InjectTouchInput alias _InjectTouchInput@8
        extern IsImmersiveProcess alias _IsImmersiveProcess@4
        extern IsMouseInPointerEnabled alias _IsMouseInPointerEnabled@0
        extern PackTouchHitTestingProximityEvaluation alias _PackTouchHitTestingProximityEvaluation@8
        extern RegisterPointerDeviceNotifications alias _RegisterPointerDeviceNotifications@8
        extern RegisterPointerInputTarget alias _RegisterPointerInputTarget@8
        extern RegisterSuspendResumeNotification alias _RegisterSuspendResumeNotification@8
        extern RegisterTouchHitTestingWindow alias _RegisterTouchHitTestingWindow@8
        extern SetCoalescableTimer alias _SetCoalescableTimer@20
        extern SetDisplayAutoRotationPreferences alias _SetDisplayAutoRotationPreferences@4
        extern SetProcessRestrictionExemption alias _SetProcessRestrictionExemption@4
        extern SetWindowFeedbackSetting alias _SetWindowFeedbackSetting@20
        extern ShowSystemCursor alias _ShowSystemCursor@4
        extern SkipPointerFrameMessages alias _SkipPointerFrameMessages@4
        extern UnregisterPointerInputTarget alias _UnregisterPointerInputTarget@8
        extern UnregisterSuspendResumeNotification alias _UnregisterSuspendResumeNotification@4
    #endif

    #if NTDDI_VERSION >= NTDDI_WIN81
        extern PhysicalToLogicalPointForPerMonitorDPI alias _PhysicalToLogicalPointForPerMonitorDPI@8
    #endif

    #ifdef APP_UNICODE
        define AppendMenu AppendMenuW
        define CallMsgFilter CallMsgFilterW
        define CallWindowProc CallWindowProcW
        define ChangeDisplaySettings ChangeDisplaySettingsW
        define ChangeMenu ChangeMenuW
        define CharLower CharLowerW
        define CharNext CharNextW
        define CharPrev CharPrevW
        define CharToOem CharToOemW
        define CharToOemBuff CharToOemBuffW
        define CharUpper CharUpperW
        define CharUpperBuff CharUpperBuffW
        define CopyAcceleratorTable CopyAcceleratorTableW
        define CreateAcceleratorTable CreateAcceleratorTableW
        define CreateDesktop CreateDesktopW
        define CreateDialogIndirectParam CreateDialogIndirectParamW
        define CreateDialogParam CreateDialogParamW
        define CreateMDIWindow CreateMDIWindowW
        define CreateWindowEx CreateWindowExW
        define CreateWindowStation CreateWindowStationW
        define DdeCreateStringHandle DdeCreateStringHandleW
        define DdeInitialize DdeInitializeW
        define DdeQueryString DdeQueryStringW
        define DefDlgProc DefDlgProcW
        define DefFrameProc DefFrameProcW
        define DefMDIChildProc DefMDIChildProcW
        define DefWindowProc DefWindowProcW
        define DialogBoxIndirectParam DialogBoxIndirectParamW
        define DialogBoxParam DialogBoxParamW
        define DispatchMessage DispatchMessageW
        define DlgDirList DlgDirListW
        define DlgDirListComboBox DlgDirListComboBoxW
        define DlgDirSelectComboBoxEx DlgDirSelectComboBoxExW
        define DlgDirSelectEx DlgDirSelectExW
        define DrawState DrawStateW
        define DrawText DrawTextW
        define DrawTextEx DrawTextExW
        define EnumDesktops EnumDesktopsW
        define EnumDisplayDevices EnumDisplayDevicesW
        define EnumDisplaySettings EnumDisplaySettingsW
        define EnumProps EnumPropsW
        define EnumPropsEx EnumPropsExW
        define EnumWindowStations EnumWindowStationsW
        define FindWindow FindWindowW
        define FindWindowEx FindWindowExW
        define GetClassInfo GetClassInfoW
        define GetClassInfoEx GetClassInfoExW
        define GetClassLong GetClassLongW
        define GetClassName GetClassNameW
        define GetClipboardFormatName GetClipboardFormatNameW
        define GetDlgItemText GetDlgItemTextW
        define GetKeyboardLayoutName GetKeyboardLayoutNameW
        define GetKeyNameText GetKeyNameTextW
        define GetMenuItemInfo GetMenuItemInfoW
        define GetMenuString GetMenuStringW
        define GetMessage GetMessageW
        define GetProp GetPropW
        define GetTabbedTextExtent GetTabbedTextExtentW
        define GetUserObjectInformation GetUserObjectInformationW
        define GetWindowLong GetWindowLongW
        define GetWindowText GetWindowTextW
        define GetWindowTextLength GetWindowTextLengthW
        define GrayString GrayStringW
        define InsertMenu InsertMenuW
        define InsertMenuItem InsertMenuItemW
        define IsCharAlpha IsCharAlphaW
        define IsCharAlphaNumeric IsCharAlphaNumericW
        define IsCharLower IsCharLowerW
        define IsCharUpper IsCharUpperW
        define IsDialogMessage IsDialogMessageW
        define LoadAccelerators LoadAcceleratorsW
        define LoadBitmap LoadBitmapW
        define LoadCursor LoadCursorW
        define LoadCursorFromFile LoadCursorFromFileW
        define LoadIcon LoadIconW
        define LoadImage LoadImageW
        define LoadKeyboardLayout LoadKeyboardLayoutW
        define LoadMenu LoadMenuW
        define LoadMenuIndirect LoadMenuIndirectW
        define LoadString LoadStringW
        define MapVirtualKey MapVirtualKeyW
        define MapVirtualKeyEx MapVirtualKeyExW
        define MessageBox MessageBoxW
        define MessageBoxEx MessageBoxExW
        define MessageBoxIndirect MessageBoxIndirectW
        define ModifyMenu ModifyMenuW
        define OemToChar OemToCharW
        define OemToCharBuff OemToCharBuffW
        define OpenDesktop OpenDesktopW
        define OpenWindowStation OpenWindowStationW
        define PeekMessage PeekMessageW
        define PostMessage PostMessageW
        define PostThreadMessage PostThreadMessageW
        define RegisterClass RegisterClassW
        define RegisterClassEx RegisterClassExW
        define RegisterClipboardFormat RegisterClipboardFormatW
        define RegisterWindowMessage RegisterWindowMessageW
        define RemoveProp RemovePropW
        define SendDlgItemMessage SendDlgItemMessageW
        define SendMessage SendMessageW
        define SendMessageCallback SendMessageCallbackW
        define SendMessageTimeout SendMessageTimeoutW
        define SendNotifyMessage SendNotifyMessageW
        define SetClassLong SetClassLongW
        define SetDlgItemText SetDlgItemTextW
        define SetMenuItemInfo SetMenuItemInfoW
        define SetProp SetPropW
        define SetUserObjectInformation SetUserObjectInformationW
        define SetWindowLong SetWindowLongW
        define SetWindowsHook SetWindowsHookW
        define SetWindowsHookEx SetWindowsHookExW
        define SetWindowText SetWindowTextW
        define SystemParametersInfo SystemParametersInfoW
        define TabbedTextOut TabbedTextOutW
        define TranslateAccelerator TranslateAcceleratorW
        define UnregisterClass UnregisterClassW
        define VkKeyScan VkKeyScanW
        define VkKeyScanEx VkKeyScanExW
        define WinHelp WinHelpW
        define wsprintf wsprintfW
        define wvsprintf wvsprintfW
    #else
        define AppendMenu AppendMenuA
        define CallMsgFilter CallMsgFilterA
        define CallWindowProc CallWindowProcA
        define ChangeDisplaySettings ChangeDisplaySettingsA
        define ChangeMenu ChangeMenuA
        define CharLower CharLowerA
        define CharNext CharNextA
        define CharNextEx CharNextExA
        define CharPrev CharPrevA
        define CharPrevEx CharPrevExA
        define CharToOem CharToOemA
        define CharToOemBuff CharToOemBuffA
        define CharUpper CharUpperA
        define CharUpperBuff CharUpperBuffA
        define CopyAcceleratorTable CopyAcceleratorTableA
        define CreateAcceleratorTable CreateAcceleratorTableA
        define CreateDesktop CreateDesktopA
        define CreateDialogIndirectParam CreateDialogIndirectParamA
        define CreateDialogParam CreateDialogParamA
        define CreateMDIWindow CreateMDIWindowA
        define CreateWindowEx CreateWindowExA
        define CreateWindowStation CreateWindowStationA
        define DdeCreateStringHandle DdeCreateStringHandleA
        define DdeInitialize DdeInitializeA
        define DdeQueryString DdeQueryStringA
        define DefDlgProc DefDlgProcA
        define DefFrameProc DefFrameProcA
        define DefMDIChildProc DefMDIChildProcA
        define DefWindowProc DefWindowProcA
        define DialogBoxIndirectParam DialogBoxIndirectParamA
        define DialogBoxParam DialogBoxParamA
        define DispatchMessage DispatchMessageA
        define DlgDirList DlgDirListA
        define DlgDirListComboBox DlgDirListComboBoxA
        define DlgDirSelectComboBoxEx DlgDirSelectComboBoxExA
        define DlgDirSelectEx DlgDirSelectExA
        define DrawState DrawStateA
        define DrawText DrawTextA
        define DrawTextEx DrawTextExA
        define EnumDesktops EnumDesktopsA
        define EnumDisplayDevices EnumDisplayDevicesA
        define EnumDisplaySettings EnumDisplaySettingsA
        define EnumProps EnumPropsA
        define EnumPropsEx EnumPropsExA
        define EnumWindowStations EnumWindowStationsA
        define FindWindow FindWindowA
        define FindWindowEx FindWindowExA
        define GetClassInfo GetClassInfoA
        define GetClassInfoEx GetClassInfoExA
        define GetClassLong GetClassLongA
        define GetClassName GetClassNameA
        define GetClipboardFormatName GetClipboardFormatNameA
        define GetDlgItemText GetDlgItemTextA
        define GetKeyboardLayoutName GetKeyboardLayoutNameA
        define GetKeyNameText GetKeyNameTextA
        define GetMenuItemInfo GetMenuItemInfoA
        define GetMenuString GetMenuStringA
        define GetMessage GetMessageA
        define GetProp GetPropA
        define GetTabbedTextExtent GetTabbedTextExtentA
        define GetUserObjectInformation GetUserObjectInformationA
        define GetWindowLong GetWindowLongA
        define GetWindowText GetWindowTextA
        define GetWindowTextLength GetWindowTextLengthA
        define GrayString GrayStringA
        define InsertMenu InsertMenuA
        define InsertMenuItem InsertMenuItemA
        define IsCharAlpha IsCharAlphaA
        define IsCharAlphaNumeric IsCharAlphaNumericA
        define IsCharLower IsCharLowerA
        define IsCharUpper IsCharUpperA
        define IsDialogMessage IsDialogMessageA
        define LoadAccelerators LoadAcceleratorsA
        define LoadBitmap LoadBitmapA
        define LoadCursor LoadCursorA
        define LoadCursorFromFile LoadCursorFromFileA
        define LoadIcon LoadIconA
        define LoadImage LoadImageA
        define LoadKeyboardLayout LoadKeyboardLayoutA
        define LoadMenu LoadMenuA
        define LoadMenuIndirect LoadMenuIndirectA
        define LoadString LoadStringA
        define MapVirtualKey MapVirtualKeyA
        define MapVirtualKeyEx MapVirtualKeyExA
        define MessageBox MessageBoxA
        define MessageBoxEx MessageBoxExA
        define MessageBoxIndirect MessageBoxIndirectA
        define ModifyMenu ModifyMenuA
        define OemToChar OemToCharA
        define OemToCharBuff OemToCharBuffA
        define OpenDesktop OpenDesktopA
        define OpenWindowStation OpenWindowStationA
        define PeekMessage PeekMessageA
        define PostMessage PostMessageA
        define PostThreadMessage PostThreadMessageA
        define RegisterClass RegisterClassA
        define RegisterClassEx RegisterClassExA
        define RegisterClipboardFormat RegisterClipboardFormatA
        define RegisterWindowMessage RegisterWindowMessageA
        define RemoveProp RemovePropA
        define SendDlgItemMessage SendDlgItemMessageA
        define SendMessage SendMessageA
        define SendMessageCallback SendMessageCallbackA
        define SendMessageTimeout SendMessageTimeoutA
        define SendNotifyMessage SendNotifyMessageA
        define SetClassLong SetClassLongA
        define SetDlgItemText SetDlgItemTextA
        define SetMenuItemInfo SetMenuItemInfoA
        define SetProp SetPropA
        define SetUserObjectInformation SetUserObjectInformationA
        define SetWindowLong SetWindowLongA
        define SetWindowsHook SetWindowsHookA
        define SetWindowsHookEx SetWindowsHookExA
        define SetWindowText SetWindowTextA
        define SystemParametersInfo SystemParametersInfoA
        define TabbedTextOut TabbedTextOutA
        define TranslateAccelerator TranslateAcceleratorA
        define UnregisterClass UnregisterClassA
        define VkKeyScan VkKeyScanA
        define VkKeyScanEx VkKeyScanExA
        define WinHelp WinHelpA
        define wsprintf wsprintfA
        define wvsprintf wvsprintfA
    #endif

    define GetClassLongPtrA GetClassLongA
    define GetClassLongPtrW GetClassLongW
    define GetWindowLongPtrA GetWindowLongA
    define GetWindowLongPtrW GetWindowLongW
    define SetClassLongPtrA SetClassLongA
    define SetClassLongPtrW SetClassLongW
    define SetWindowLongPtrA SetWindowLongA
    define SetWindowLongPtrW SetWindowLongW
    #ifdef APP_UNICODE
        define GetClassLongPtr GetClassLongW
        define GetWindowLongPtr GetWindowLongW
        define SetClassLongPtr SetClassLongW
        define SetWindowLongPtr SetWindowLongW
    #else
        define GetClassLongPtr GetClassLongA
        define GetWindowLongPtr GetWindowLongA
        define SetClassLongPtr SetClassLongA
        define SetWindowLongPtr SetWindowLongA
    #endif
#endif

define PostAppMessage PostThreadMessage
define PostAppMessageA PostThreadMessageA
define PostAppMessageW PostThreadMessageW
define AnsiToOem CharToOemA
define OemToAnsi OemToCharA
define AnsiToOemBuff CharToOemBuffA
define OemToAnsiBuff OemToCharBuffA
define AnsiUpper CharUpperA
define AnsiUpperBuff CharUpperBuffA
define AnsiLower CharLowerA
define AnsiLowerBuff CharLowerBuffA
define AnsiNext CharNextA
define AnsiPrev CharPrevA

#endif ;USER32_INC
