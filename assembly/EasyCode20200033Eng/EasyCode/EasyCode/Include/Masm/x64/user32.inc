; ======================================================;
;                                                       ;
;   user32.inc for Easy Code 2.0 64-bit Masm projects   ;
;                   (version 1.0.10)                    ;
;                                                       ;
;          Copyright © Ramon Sala 2015-2020             ;
;                                                       ;
; ======================================================;

IFNDEF USER32_INC
USER32_INC   EQU     1

IFNDEF LF_FACESIZE
    LF_FACESIZE                                 EQU     32
ENDIF

MSGFLT_ADD                                      EQU     1
MSGFLT_REMOVE                                   EQU     2

RT_CURSOR                                       EQU     1
RT_BITMAP                                       EQU     2
RT_ICON                                         EQU     3
RT_MENU                                         EQU     4
RT_DIALOG                                       EQU     5
RT_STRING                                       EQU     6
RT_FONTDIR                                      EQU     7
RT_FONT                                         EQU     8
RT_ACCELERATOR                                  EQU     9
RT_RCDATA                                       EQU     10
RT_MESSAGETABLE                                 EQU     11
DIFFERENCE                                      EQU     11
RT_GROUP_CURSOR                                 EQU     (RT_CURSOR + DIFFERENCE)
RT_GROUP_ICON                                   EQU     (RT_ICON + DIFFERENCE)
RT_VERSION                                      EQU     16
RT_DLGINCLUDE                                   EQU     17
RT_PLUGPLAY                                     EQU     19
RT_VXD                                          EQU     20
RT_ANICURSOR                                    EQU     21
RT_ANIICON                                      EQU     22
RT_HTML                                         EQU     23
RT_MANIFEST                                     EQU     24

SETWALLPAPER_DEFAULT                            EQU     (-1)

CREATEPROCESS_MANIFEST_RESOURCE_ID              EQU     1
ISOLATIONAWARE_MANIFEST_RESOURCE_ID             EQU     2
ISOLATIONAWARE_NOSTATICIMPORT_MANIFEST_RESOURCE_ID  EQU 3
MINIMUM_RESERVED_MANIFEST_RESOURCE_ID           EQU     1
MAXIMUM_RESERVED_MANIFEST_RESOURCE_ID           EQU     16

MAPVK_VK_TO_VSC                                 EQU     0
MAPVK_VSC_TO_VK                                 EQU     1
MAPVK_VK_TO_CHAR                                EQU     2
MAPVK_VSC_TO_VK_EX                              EQU     3
MAPVK_VK_TO_VSC_EX                              EQU     4

TIMERV_DEFAULT_COALESCING                       EQU     0
TIMERV_NO_COALESCING                            EQU     0FFFFFFFFH
TIMERV_COALESCING_MIN                           EQU     1
TIMERV_COALESCING_MAX                           EQU     0FFFH

SB_HORZ                                         EQU     0
SB_VERT                                         EQU     1
SB_CTL                                          EQU     2
SB_BOTH                                         EQU     3

SB_LINEUP                                       EQU     0
SB_LINELEFT                                     EQU     0
SB_LINEDOWN                                     EQU     1
SB_LINERIGHT                                    EQU     1
SB_PAGEUP                                       EQU     2
SB_PAGELEFT                                     EQU     2
SB_PAGEDOWN                                     EQU     3
SB_PAGERIGHT                                    EQU     3
SB_THUMBPOSITION                                EQU     4
SB_THUMBTRACK                                   EQU     5
SB_TOP                                          EQU     6
SB_LEFT                                         EQU     6
SB_BOTTOM                                       EQU     7
SB_RIGHT                                        EQU     7
SB_ENDSCROLL                                    EQU     8

SW_HIDE                                         EQU     0
SW_SHOWNORMAL                                   EQU     1
SW_NORMAL                                       EQU     1
SW_SHOWMINIMIZED                                EQU     2
SW_SHOWMAXIMIZED                                EQU     3
SW_MAXIMIZE                                     EQU     3
SW_SHOWNOACTIVATE                               EQU     4
SW_SHOW                                         EQU     5
SW_MINIMIZE                                     EQU     6
SW_SHOWMINNOACTIVE                              EQU     7
SW_SHOWNA                                       EQU     8
SW_RESTORE                                      EQU     9
SW_SHOWDEFAULT                                  EQU     10
SW_FORCEMINIMIZE                                EQU     11
SW_MAX                                          EQU     11

HIDE_WINDOW                                     EQU     0
SHOW_OPENWINDOW                                 EQU     1
SHOW_ICONWINDOW                                 EQU     2
SHOW_FULLSCREEN                                 EQU     3
SHOW_OPENNOACTIVATE                             EQU     4

SW_PARENTCLOSING                                EQU     1
SW_OTHERZOOM                                    EQU     2
SW_PARENTOPENING                                EQU     3
SW_OTHERUNZOOM                                  EQU     4

AW_HOR_POSITIVE                                 EQU     000000001H
AW_HOR_NEGATIVE                                 EQU     000000002H
AW_VER_POSITIVE                                 EQU     000000004H
AW_VER_NEGATIVE                                 EQU     000000008H
AW_CENTER                                       EQU     000000010H
AW_HIDE                                         EQU     000010000H
AW_ACTIVATE                                     EQU     000020000H
AW_SLIDE                                        EQU     000040000H
AW_BLEND                                        EQU     000080000H

KF_EXTENDED                                     EQU     00100H
KF_DLGMODE                                      EQU     00800H
KF_MENUMODE                                     EQU     01000H
KF_ALTDOWN                                      EQU     02000H
KF_REPEAT                                       EQU     04000H
KF_UP                                           EQU     08000H

VK_LBUTTON                                      EQU     001H
VK_RBUTTON                                      EQU     002H
VK_CANCEL                                       EQU     003H
VK_MBUTTON                                      EQU     004H

VK_BACK                                         EQU     008H
VK_TAB                                          EQU     009H

VK_CLEAR                                        EQU     00CH
VK_RETURN                                       EQU     00DH

VK_SHIFT                                        EQU     010H
VK_CONTROL                                      EQU     011H
VK_MENU                                         EQU     012H
VK_PAUSE                                        EQU     013H
VK_CAPITAL                                      EQU     014H

VK_KANA                                         EQU     015H
VK_HANGEUL                                      EQU     015H
VK_HANGUL                                       EQU     015H
VK_JUNJA                                        EQU     017H
VK_FINAL                                        EQU     018H
VK_HANJA                                        EQU     019H
VK_KANJI                                        EQU     019H

VK_ESCAPE                                       EQU     01BH

VK_CONVERT                                      EQU     01CH
VK_NONCONVERT                                   EQU     01DH
VK_ACCEPT                                       EQU     01EH
VK_MODECHANGE                                   EQU     01FH

VK_SPACE                                        EQU     020H
VK_PRIOR                                        EQU     021H
VK_NEXT                                         EQU     022H
VK_END                                          EQU     023H
VK_HOME                                         EQU     024H
VK_LEFT                                         EQU     025H
VK_UP                                           EQU     026H
VK_RIGHT                                        EQU     027H
VK_DOWN                                         EQU     028H
VK_SELECT                                       EQU     029H
VK_PRINT                                        EQU     02AH
VK_EXECUTE                                      EQU     02BH
VK_SNAPSHOT                                     EQU     02CH
VK_INSERT                                       EQU     02DH
VK_DELETE                                       EQU     02EH
VK_HELP                                         EQU     02FH

VK_LWIN                                         EQU     05BH
VK_RWIN                                         EQU     05CH
VK_APPS                                         EQU     05DH
VK_SLEEP                                        EQU     05FH

VK_NUMPAD0                                      EQU     060H
VK_NUMPAD1                                      EQU     061H
VK_NUMPAD2                                      EQU     062H
VK_NUMPAD3                                      EQU     063H
VK_NUMPAD4                                      EQU     064H
VK_NUMPAD5                                      EQU     065H
VK_NUMPAD6                                      EQU     066H
VK_NUMPAD7                                      EQU     067H
VK_NUMPAD8                                      EQU     068H
VK_NUMPAD9                                      EQU     069H
VK_MULTIPLY                                     EQU     06AH
VK_ADD                                          EQU     06BH
VK_SEPARATOR                                    EQU     06CH
VK_SUBTRACT                                     EQU     06DH
VK_DECIMAL                                      EQU     06EH
VK_DIVIDE                                       EQU     06FH
VK_F1                                           EQU     070H
VK_F2                                           EQU     071H
VK_F3                                           EQU     072H
VK_F4                                           EQU     073H
VK_F5                                           EQU     074H
VK_F6                                           EQU     075H
VK_F7                                           EQU     076H
VK_F8                                           EQU     077H
VK_F9                                           EQU     078H
VK_F10                                          EQU     079H
VK_F11                                          EQU     07AH
VK_F12                                          EQU     07BH
VK_F13                                          EQU     07CH
VK_F14                                          EQU     07DH
VK_F15                                          EQU     07EH
VK_F16                                          EQU     07FH
VK_F17                                          EQU     080H
VK_F18                                          EQU     081H
VK_F19                                          EQU     082H
VK_F20                                          EQU     083H
VK_F21                                          EQU     084H
VK_F22                                          EQU     085H
VK_F23                                          EQU     086H
VK_F24                                          EQU     087H

VK_NUMLOCK                                      EQU     090H
VK_SCROLL                                       EQU     091H
VK_OEM_NEC_EQUAL                                EQU     092H
VK_OEM_FJ_JISHO                                 EQU     092H
VK_OEM_FJ_MASSHOU                               EQU     093H
VK_OEM_FJ_TOUROKU                               EQU     094H
VK_OEM_FJ_LOYA                                  EQU     095H
VK_OEM_FJ_ROYA                                  EQU     096H

VK_LSHIFT                                       EQU     0A0H
VK_RSHIFT                                       EQU     0A1H
VK_LCONTROL                                     EQU     0A2H
VK_RCONTROL                                     EQU     0A3H
VK_LMENU                                        EQU     0A4H
VK_RMENU                                        EQU     0A5H
VK_BROWSER_BACK                                 EQU     0A6H
VK_BROWSER_FORWARD                              EQU     0A7H
VK_BROWSER_REFRESH                              EQU     0A8H
VK_BROWSER_STOP                                 EQU     0A9H
VK_BROWSER_SEARCH                               EQU     0AAH
VK_BROWSER_FAVORITES                            EQU     0ABH
VK_BROWSER_HOME                                 EQU     0ACH
VK_VOLUME_MUTE                                  EQU     0ADH
VK_VOLUME_DOWN                                  EQU     0AEH
VK_VOLUME_UP                                    EQU     0AFH

VK_MEDIA_NEXT_TRACK                             EQU     0B0H
VK_MEDIA_PREV_TRACK                             EQU     0B1H
VK_MEDIA_STOP                                   EQU     0B2H
VK_MEDIA_PLAY_PAUSE                             EQU     0B3H
VK_LAUNCH_MAIL                                  EQU     0B4H
VK_LAUNCH_MEDIA_SELECT                          EQU     0B5H
VK_LAUNCH_APP1                                  EQU     0B6H
VK_LAUNCH_APP2                                  EQU     0B7H

VK_OEM_1                                        EQU     0BAH
VK_OEM_PLUS                                     EQU     0BBH
VK_OEM_COMMA                                    EQU     0BCH
VK_OEM_MINUS                                    EQU     0BDH
VK_OEM_PERIOD                                   EQU     0BEH
VK_OEM_2                                        EQU     0BFH
VK_OEM_3                                        EQU     0C0H
VK_OEM_4                                        EQU     0DBH
VK_OEM_5                                        EQU     0DCH
VK_OEM_6                                        EQU     0DDH
VK_OEM_7                                        EQU     0DEH
VK_OEM_8                                        EQU     0DFH

VK_OEM_AX                                       EQU     0E1H
VK_OEM_102                                      EQU     0E2H
VK_ICO_HELP                                     EQU     0E3H
VK_ICO_00                                       EQU     0E4H
VK_PROCESSKEY                                   EQU     0E5H
VK_ICO_CLEAR                                    EQU     0E6H
VK_PACKET                                       EQU     0E7H
VK_OEM_RESET                                    EQU     0E9H
VK_OEM_JUMP                                     EQU     0EAH
VK_OEM_PA1                                      EQU     0EBH
VK_OEM_PA2                                      EQU     0ECH
VK_OEM_PA3                                      EQU     0EDH
VK_OEM_WSCTRL                                   EQU     0EEH
VK_OEM_CUSEL                                    EQU     0EFH

VK_OEM_ATTN                                     EQU     0F0H
VK_OEM_FINISH                                   EQU     0F1H
VK_OEM_COPY                                     EQU     0F2H
VK_OEM_AUTO                                     EQU     0F3H
VK_OEM_ENLW                                     EQU     0F4H
VK_OEM_BACKTAB                                  EQU     0F5H
VK_ATTN                                         EQU     0F6H
VK_CRSEL                                        EQU     0F7H
VK_EXSEL                                        EQU     0F8H
VK_EREOF                                        EQU     0F9H
VK_PLAY                                         EQU     0FAH
VK_ZOOM                                         EQU     0FBH
VK_NONAME                                       EQU     0FCH
VK_PA1                                          EQU     0FDH
VK_OEM_CLEAR                                    EQU     0FEH

WH_MIN                                          EQU     (-1)
WH_MSGFILTER                                    EQU     (-1)
WH_JOURNALRECORD                                EQU     0
WH_JOURNALPLAYBACK                              EQU     1
WH_KEYBOARD                                     EQU     2
WH_GETMESSAGE                                   EQU     3
WH_CALLWNDPROC                                  EQU     4
WH_CBT                                          EQU     5
WH_SYSMSGFILTER                                 EQU     6
WH_MOUSE                                        EQU     7
WH_HARDWARE                                     EQU     8
WH_DEBUG                                        EQU     9
WH_SHELL                                        EQU     10
WH_FOREGROUNDIDLE                               EQU     11
WH_CALLWNDPROCRET                               EQU     12

WH_KEYBOARD_LL                                  EQU     13
WH_MOUSE_LL                                     EQU     14

IF (NTDDI_VERSION EQ NTDDI_WINNT4)
    WH_MAX                                      EQU     14
ELSE
    WH_MAX                                      EQU     12
ENDIF

WH_MINHOOK                                      EQU     WH_MIN
WH_MAXHOOK                                      EQU     WH_MAX

HC_ACTION                                       EQU     0
HC_GETNEXT                                      EQU     1
HC_SKIP                                         EQU     2
HC_NOREMOVE                                     EQU     3
HC_NOREM                                        EQU     HC_NOREMOVE
HC_SYSMODALON                                   EQU     4
HC_SYSMODALOFF                                  EQU     5

HCBT_MOVESIZE                                   EQU     0
HCBT_MINMAX                                     EQU     1
HCBT_QS                                         EQU     2
HCBT_CREATEWND                                  EQU     3
HCBT_DESTROYWND                                 EQU     4
HCBT_ACTIVATE                                   EQU     5
HCBT_CLICKSKIPPED                               EQU     6
HCBT_KEYSKIPPED                                 EQU     7
HCBT_SYSCOMMAND                                 EQU     8
HCBT_SETFOCUS                                   EQU     9

MSGF_DIALOGBOX                                  EQU     0
MSGF_MESSAGEBOX                                 EQU     1
MSGF_MENU                                       EQU     2
MSGF_SCROLLBAR                                  EQU     5
MSGF_NEXTWINDOW                                 EQU     6
MSGF_MAX                                        EQU     8
MSGF_USER                                       EQU     4096

HSHELL_WINDOWCREATED                            EQU     1
HSHELL_WINDOWDESTROYED                          EQU     2
HSHELL_ACTIVATESHELLWINDOW                      EQU     3

HSHELL_WINDOWACTIVATED                          EQU     4
HSHELL_GETMINRECT                               EQU     5
HSHELL_REDRAW                                   EQU     6
HSHELL_TASKMAN                                  EQU     7
HSHELL_LANGUAGE                                 EQU     8
HSHELL_ACCESSIBILITYSTATE                       EQU     11
HSHELL_APPCOMMAND                               EQU     12
HSHELL_WINDOWREPLACED                           EQU     13
HSHELL_WINDOWREPLACING                          EQU     14
HSHELL_MONITORCHANGED                           EQU     16
HSHELL_HIGHBIT                                  EQU     08000H
HSHELL_FLASH                                    EQU     (HSHELL_REDRAW OR HSHELL_HIGHBIT)
HSHELL_RUDEAPPACTIVATED                         EQU     (HSHELL_WINDOWACTIVATED OR HSHELL_HIGHBIT)

ACCESS_STICKYKEYS                               EQU     00001H
ACCESS_FILTERKEYS                               EQU     00002H
ACCESS_MOUSEKEYS                                EQU     00003H

APPCOMMAND_BROWSER_BACKWARD                     EQU     1
APPCOMMAND_BROWSER_FORWARD                      EQU     2
APPCOMMAND_BROWSER_REFRESH                      EQU     3
APPCOMMAND_BROWSER_STOP                         EQU     4
APPCOMMAND_BROWSER_SEARCH                       EQU     5
APPCOMMAND_BROWSER_FAVORITES                    EQU     6
APPCOMMAND_BROWSER_HOME                         EQU     7
APPCOMMAND_VOLUME_MUTE                          EQU     8
APPCOMMAND_VOLUME_DOWN                          EQU     9
APPCOMMAND_VOLUME_UP                            EQU     10
APPCOMMAND_MEDIA_NEXTTRACK                      EQU     11
APPCOMMAND_MEDIA_PREVIOUSTRACK                  EQU     12
APPCOMMAND_MEDIA_STOP                           EQU     13
APPCOMMAND_MEDIA_PLAY_PAUSE                     EQU     14
APPCOMMAND_LAUNCH_MAIL                          EQU     15
APPCOMMAND_LAUNCH_MEDIA_SELECT                  EQU     16
APPCOMMAND_LAUNCH_APP1                          EQU     17
APPCOMMAND_LAUNCH_APP2                          EQU     18
APPCOMMAND_BASS_DOWN                            EQU     19
APPCOMMAND_BASS_BOOST                           EQU     20
APPCOMMAND_BASS_UP                              EQU     21
APPCOMMAND_TREBLE_DOWN                          EQU     22
APPCOMMAND_TREBLE_UP                            EQU     23
APPCOMMAND_MICROPHONE_VOLUME_MUTE               EQU     24
APPCOMMAND_MICROPHONE_VOLUME_DOWN               EQU     25
APPCOMMAND_MICROPHONE_VOLUME_UP                 EQU     26
APPCOMMAND_HELP                                 EQU     27
APPCOMMAND_FIND                                 EQU     28
APPCOMMAND_NEW                                  EQU     29
APPCOMMAND_OPEN                                 EQU     30
APPCOMMAND_CLOSE                                EQU     31
APPCOMMAND_SAVE                                 EQU     32
APPCOMMAND_PRINT                                EQU     33
APPCOMMAND_UNDO                                 EQU     34
APPCOMMAND_REDO                                 EQU     35
APPCOMMAND_COPY                                 EQU     36
APPCOMMAND_CUT                                  EQU     37
APPCOMMAND_PASTE                                EQU     38
APPCOMMAND_REPLY_TO_MAIL                        EQU     39
APPCOMMAND_FORWARD_MAIL                         EQU     40
APPCOMMAND_SEND_MAIL                            EQU     41
APPCOMMAND_SPELL_CHECK                          EQU     42
APPCOMMAND_DICTATE_OR_COMMAND_CONTROL_TOGGLE    EQU     43
APPCOMMAND_MIC_ON_OFF_TOGGLE                    EQU     44
APPCOMMAND_CORRECTION_LIST                      EQU     45
APPCOMMAND_MEDIA_PLAY                           EQU     46
APPCOMMAND_MEDIA_PAUSE                          EQU     47
APPCOMMAND_MEDIA_RECORD                         EQU     48
APPCOMMAND_MEDIA_FAST_FORWARD                   EQU     49
APPCOMMAND_MEDIA_REWIND                         EQU     50
APPCOMMAND_MEDIA_CHANNEL_UP                     EQU     51
APPCOMMAND_MEDIA_CHANNEL_DOWN                   EQU     52
APPCOMMAND_DELETE                               EQU     53
APPCOMMAND_DWM_FLIP3D                           EQU     54

FAPPCOMMAND_MOUSE                               EQU     08000H
FAPPCOMMAND_KEY                                 EQU     0
FAPPCOMMAND_OEM                                 EQU     01000H
FAPPCOMMAND_MASK                                EQU     0F000H

LLKHF_EXTENDED                                  EQU     000000001H
LLKHF_INJECTED                                  EQU     000000010H
LLKHF_ALTDOWN                                   EQU     000000020H
LLKHF_UP                                        EQU     000000080H

LLMHF_INJECTED                                  EQU     000000001H

HKL_PREV                                        EQU     0
HKL_NEXT                                        EQU     1

KLF_ACTIVATE                                    EQU     000000001H
KLF_SUBSTITUTE_OK                               EQU     000000002H
KLF_UNLOADPREVIOUS                              EQU     000000004H
KLF_REORDER                                     EQU     000000008H
KLF_REPLACELANG                                 EQU     000000010H
KLF_NOTELLSHELL                                 EQU     000000080H
KLF_SETFORPROCESS                               EQU     000000100H
KLF_SHIFTLOCK                                   EQU     000010000H
KLF_RESET                                       EQU     040000000H

INPUTLANGCHANGE_SYSCHARSET                      EQU     00001H
INPUTLANGCHANGE_FORWARD                         EQU     00002H
INPUTLANGCHANGE_BACKWARD                        EQU     00004H

KL_NAMELENGTH                                   EQU     9

GMMP_USE_DISPLAY_POINTS                         EQU     1
GMMP_USE_DRIVER_POINTS                          EQU     2

DESKTOP_READOBJECTS                             EQU     00001H
DESKTOP_CREATEWINDOW                            EQU     00002H
DESKTOP_CREATEMENU                              EQU     00004H
DESKTOP_HOOKCONTROL                             EQU     00008H
DESKTOP_JOURNALRECORD                           EQU     00010H
DESKTOP_JOURNALPLAYBACK                         EQU     00020H
DESKTOP_ENUMERATE                               EQU     00040H
DESKTOP_WRITEOBJECTS                            EQU     00080H
DESKTOP_SWITCHDESKTOP                           EQU     00100H

DF_ALLOWOTHERACCOUNTHOOK                        EQU     00001H

WINSTA_ENUMDESKTOPS                             EQU     00001H
WINSTA_READATTRIBUTES                           EQU     00002H
WINSTA_ACCESSCLIPBOARD                          EQU     00004H
WINSTA_CREATEDESKTOP                            EQU     00008H
WINSTA_WRITEATTRIBUTES                          EQU     00010H
WINSTA_ACCESSGLOBALATOMS                        EQU     00020H
WINSTA_EXITWINDOWS                              EQU     00040H
WINSTA_ENUMERATE                                EQU     00100H
WINSTA_READSCREEN                               EQU     00200H
WINSTA_ALL_ACCESS                               EQU     (WINSTA_ENUMDESKTOPS OR WINSTA_READATTRIBUTES OR WINSTA_ACCESSCLIPBOARD OR WINSTA_CREATEDESKTOP OR \
                                                        WINSTA_WRITEATTRIBUTES OR WINSTA_ACCESSGLOBALATOMS OR WINSTA_EXITWINDOWS OR WINSTA_ENUMERATE OR WINSTA_READSCREEN)

CWF_CREATE_ONLY                                 EQU     00000001H

WSF_VISIBLE                                     EQU     0001H

UOI_FLAGS                                       EQU     1
UOI_NAME                                        EQU     2
UOI_TYPE                                        EQU     3
UOI_USER_SID                                    EQU     4

GWL_WNDPROC                                     EQU     (-4)
GWL_HINSTANCE                                   EQU     (-6)
GWL_HWNDPARENT                                  EQU     (-8)
GWL_STYLE                                       EQU     (-16)
GWL_EXSTYLE                                     EQU     (-20)
GWL_USERDATA                                    EQU     (-21)
GWL_ID                                          EQU     (-12)

GWLP_WNDPROC                                    EQU     (-4)
GWLP_HINSTANCE                                  EQU     (-6)
GWLP_HWNDPARENT                                 EQU     (-8)
GWLP_USERDATA                                   EQU     (-21)
GWLP_ID                                         EQU     (-12)

GCL_MENUNAME                                    EQU     (-8)
GCL_HBRBACKGROUND                               EQU     (-10)
GCL_HCURSOR                                     EQU     (-12)
GCL_HICON                                       EQU     (-14)
GCL_HMODULE                                     EQU     (-16)
GCL_CBWNDEXTRA                                  EQU     (-18)
GCL_CBCLSEXTRA                                  EQU     (-20)
GCL_WNDPROC                                     EQU     (-24)
GCL_STYLE                                       EQU     (-26)
GCW_ATOM                                        EQU     (-32)

GCLP_MENUNAME                                   EQU     (-8)
GCLP_HBRBACKGROUND                              EQU     (-10)
GCLP_HCURSOR                                    EQU     (-12)
GCLP_HICON                                      EQU     (-14)
GCLP_HMODULE                                    EQU     (-16)
GCLP_WNDPROC                                    EQU     (-24)
GCLP_HICONSM                                    EQU     (-34)

WA_INACTIVE                                     EQU     0
WA_ACTIVE                                       EQU     1
WA_CLICKACTIVE                                  EQU     2

WM_NULL                                         EQU     00000H
WM_CREATE                                       EQU     00001H
WM_DESTROY                                      EQU     00002H
WM_MOVE                                         EQU     00003H
WM_SIZE                                         EQU     00005H
WM_ACTIVATE                                     EQU     00006H
WM_SETFOCUS                                     EQU     00007H
WM_KILLFOCUS                                    EQU     00008H
WM_ENABLE                                       EQU     0000AH
WM_SETREDRAW                                    EQU     0000BH
WM_SETTEXT                                      EQU     0000CH
WM_GETTEXT                                      EQU     0000DH
WM_GETTEXTLENGTH                                EQU     0000EH
WM_PAINT                                        EQU     0000FH

WM_CLOSE                                        EQU     00010H
WM_QUERYENDSESSION                              EQU     00011H
WM_QUIT                                         EQU     00012H
WM_QUERYOPEN                                    EQU     00013H
WM_ERASEBKGND                                   EQU     00014H
WM_SYSCOLORCHANGE                               EQU     00015H
WM_ENDSESSION                                   EQU     00016H
WM_SHOWWINDOW                                   EQU     00018H
WM_WININICHANGE                                 EQU     0001AH
WM_SETTINGCHANGE                                EQU     WM_WININICHANGE
WM_DEVMODECHANGE                                EQU     0001BH
WM_ACTIVATEAPP                                  EQU     0001CH
WM_FONTCHANGE                                   EQU     0001DH
WM_TIMECHANGE                                   EQU     0001EH
WM_CANCELMODE                                   EQU     0001FH

WM_SETCURSOR                                    EQU     00020H
WM_MOUSEACTIVATE                                EQU     00021H
WM_CHILDACTIVATE                                EQU     00022H
WM_QUEUESYNC                                    EQU     00023H
WM_GETMINMAXINFO                                EQU     00024H
WM_PAINTICON                                    EQU     00026H
WM_ICONERASEBKGND                               EQU     00027H
WM_NEXTDLGCTL                                   EQU     00028H
WM_SPOOLERSTATUS                                EQU     0002AH
WM_DRAWITEM                                     EQU     0002BH
WM_MEASUREITEM                                  EQU     0002CH
WM_DELETEITEM                                   EQU     0002DH
WM_VKEYTOITEM                                   EQU     0002EH
WM_CHARTOITEM                                   EQU     0002FH

WM_SETFONT                                      EQU     00030H
WM_GETFONT                                      EQU     00031H
WM_SETHOTKEY                                    EQU     00032H
WM_GETHOTKEY                                    EQU     00033H
WM_QUERYDRAGICON                                EQU     00037H
WM_COMPAREITEM                                  EQU     00039H
WM_GETOBJECT                                    EQU     0003DH

WM_COMPACTING                                   EQU     00041H
WM_COMMNOTIFY                                   EQU     00044H
WM_WINDOWPOSCHANGING                            EQU     00046H
WM_WINDOWPOSCHANGED                             EQU     00047H
WM_POWER                                        EQU     00048H
WM_COPYGLOBALDATA                               EQU     00049H
WM_COPYDATA                                     EQU     0004AH
WM_CANCELJOURNAL                                EQU     0004BH
WM_LOGONNOTIFY                                  EQU     0004CH
WM_KEYF1                                        EQU     0004DH
WM_NOTIFY                                       EQU     0004EH
WM_ACCESS_WINDOW                                EQU     0004FH

WM_INPUTLANGCHANGEREQUEST                       EQU     00050H
WM_INPUTLANGCHANGE                              EQU     00051H
WM_TCARD                                        EQU     00052H
WM_HELP                                         EQU     00053H
WM_USERCHANGED                                  EQU     00054H
WM_NOTIFYFORMAT                                 EQU     00055H

WM_QM_ACTIVATE                                  EQU     00060H
WM_HOOK_DO_CALLBACK                             EQU     00061H
WM_SYSCOPYDATA                                  EQU     00062H

WM_FINALDESTROY                                 EQU     00070H
WM_MEASUREITEM_CLIENTDATA                       EQU     00071H
WM_CONTEXTMENU                                  EQU     0007BH
WM_STYLECHANGING                                EQU     0007CH
WM_STYLECHANGED                                 EQU     0007DH
WM_DISPLAYCHANGE                                EQU     0007EH
WM_GETICON                                      EQU     0007FH

WM_SETICON                                      EQU     00080H
WM_NCCREATE                                     EQU     00081H
WM_NCDESTROY                                    EQU     00082H
WM_NCCALCSIZE                                   EQU     00083H
WM_NCHITTEST                                    EQU     00084H
WM_NCPAINT                                      EQU     00085H
WM_NCACTIVATE                                   EQU     00086H
WM_GETDLGCODE                                   EQU     00087H
WM_SYNCPAINT                                    EQU     00088H
WM_SYNCTASK                                     EQU     00089H
WM_KLUDGEMINRECT                                EQU     0008BH
WM_LPKDRAWSWITCHWND                             EQU     0008CH

WM_UAHDESTROYWINDOW                             EQU     00090H
WM_UAHDRAWMENU                                  EQU     00091H
WM_UAHDRAWMENUITEM                              EQU     00092H
WM_UAHINITMENU                                  EQU     00093H
WM_UAHMEASUREMENUITEM                           EQU     00094H
WM_UAHNCPAINTMENUPOPUP                          EQU     00095H

WM_NCMOUSEMOVE                                  EQU     000A0H
WM_NCLBUTTONDOWN                                EQU     000A1H
WM_NCLBUTTONUP                                  EQU     000A2H
WM_NCLBUTTONDBLCLK                              EQU     000A3H
WM_NCRBUTTONDOWN                                EQU     000A4H
WM_NCRBUTTONUP                                  EQU     000A5H
WM_NCRBUTTONDBLCLK                              EQU     000A6H
WM_NCMBUTTONDOWN                                EQU     000A7H
WM_NCMBUTTONUP                                  EQU     000A8H
WM_NCMBUTTONDBLCLK                              EQU     000A9H
WM_NCXBUTTONDOWN                                EQU     000ABH
WM_NCXBUTTONUP                                  EQU     000ACH
WM_NCXBUTTONDBLCLK                              EQU     000ADH
WM_NCUAHDRAWCAPTION                             EQU     000AEH
WM_NCUAHDRAWFRAME                               EQU     000AFH

PWR_OK                                          EQU     1
PWR_FAIL                                        EQU     (-1)
PWR_SUSPENDREQUEST                              EQU     1
PWR_SUSPENDRESUME                               EQU     2
PWR_CRITICALRESUME                              EQU     3

NFR_ANSI                                        EQU     1
NFR_UNICODE                                     EQU     2
NF_QUERY                                        EQU     3
NF_REQUERY                                      EQU     4

WM_KEYFIRST                                     EQU     00100H
WM_KEYDOWN                                      EQU     00100H
WM_KEYUP                                        EQU     00101H
WM_CHAR                                         EQU     00102H
WM_DEADCHAR                                     EQU     00103H
WM_SYSKEYDOWN                                   EQU     00104H
WM_SYSKEYUP                                     EQU     00105H
WM_SYSCHAR                                      EQU     00106H
WM_SYSDEADCHAR                                  EQU     00107H
WM_KEYLAST                                      EQU     00108H
WM_UNICHAR                                      EQU     00109H
WM_CONVERTREQUEST                               EQU     0010AH
WM_CONVERTRESULT                                EQU     0010BH
WM_IM_INFO                                      EQU     0010CH
WM_IME_STARTCOMPOSITION                         EQU     0010DH
WM_IME_ENDCOMPOSITION                           EQU     0010EH
WM_IME_COMPOSITION                              EQU     0010FH
WM_IME_KEYLAST                                  EQU     0010FH

WM_INITDIALOG                                   EQU     00110H
WM_COMMAND                                      EQU     00111H
WM_SYSCOMMAND                                   EQU     00112H
WM_TIMER                                        EQU     00113H
WM_HSCROLL                                      EQU     00114H
WM_VSCROLL                                      EQU     00115H
WM_INITMENU                                     EQU     00116H
WM_INITMENUPOPUP                                EQU     00117H
WM_SYSTIMER                                     EQU     00118H
WM_GESTURE                                      EQU     00119H
WM_GESTURENOTIFY                                EQU     0011AH
WM_GESTUREINPUT                                 EQU     0011BH
WM_GESTURENOTIFIED                              EQU     0011CH
WM_MENUSELECT                                   EQU     0011FH

WM_MENUCHAR                                     EQU     00120H
WM_ENTERIDLE                                    EQU     00121H
WM_MENURBUTTONUP                                EQU     00122H
WM_MENUDRAG                                     EQU     00123H
WM_MENUGETOBJECT                                EQU     00124H
WM_UNINITMENUPOPUP                              EQU     00125H
WM_MENUCOMMAND                                  EQU     00126H
WM_CHANGEUISTATE                                EQU     00127H
WM_UPDATEUISTATE                                EQU     00128H
WM_QUERYUISTATE                                 EQU     00129H

WM_LBTRACKPOINT                                 EQU     00131H
WM_CTLCOLORMSGBOX                               EQU     00132H
WM_CTLCOLOREDIT                                 EQU     00133H
WM_CTLCOLORLISTBOX                              EQU     00134H
WM_CTLCOLORBTN                                  EQU     00135H
WM_CTLCOLORDLG                                  EQU     00136H
WM_CTLCOLORSCROLLBAR                            EQU     00137H
WM_CTLCOLORSTATIC                               EQU     00138H

WM_MOUSEFIRST                                   EQU     00200H
WM_MOUSEMOVE                                    EQU     00200H
WM_LBUTTONDOWN                                  EQU     00201H
WM_LBUTTONUP                                    EQU     00202H
WM_LBUTTONDBLCLK                                EQU     00203H
WM_RBUTTONDOWN                                  EQU     00204H
WM_RBUTTONUP                                    EQU     00205H
WM_RBUTTONDBLCLK                                EQU     00206H
WM_MBUTTONDOWN                                  EQU     00207H
WM_MBUTTONUP                                    EQU     00208H
WM_MBUTTONDBLCLK                                EQU     00209H
WM_MOUSEWHEEL                                   EQU     0020AH
WM_XBUTTONDOWN                                  EQU     0020BH
WM_XBUTTONUP                                    EQU     0020CH
WM_XBUTTONDBLCLK                                EQU     0020DH
WM_MOUSEHWHEEL                                  EQU     0020EH
WM_MOUSELAST                                    EQU     0020EH

WM_PARENTNOTIFY                                 EQU     00210H
WM_ENTERMENULOOP                                EQU     00211H
WM_EXITMENULOOP                                 EQU     00212H
WM_NEXTMENU                                     EQU     00213H
WM_SIZING                                       EQU     00214H
WM_CAPTURECHANGED                               EQU     00215H
WM_MOVING                                       EQU     00216H
WM_POWERBROADCAST                               EQU     00218H
WM_DEVICECHANGE                                 EQU     00219H

WM_MDICREATE                                    EQU     00220H
WM_MDIDESTROY                                   EQU     00221H
WM_MDIACTIVATE                                  EQU     00222H
WM_MDIRESTORE                                   EQU     00223H
WM_MDINEXT                                      EQU     00224H
WM_MDIMAXIMIZE                                  EQU     00225H
WM_MDITILE                                      EQU     00226H
WM_MDICASCADE                                   EQU     00227H
WM_MDIICONARRANGE                               EQU     00228H
WM_MDIGETACTIVE                                 EQU     00229H

WM_MDISETMENU                                   EQU     00230H
WM_ENTERSIZEMOVE                                EQU     00231H
WM_EXITSIZEMOVE                                 EQU     00232H
WM_DROPFILES                                    EQU     00233H
WM_MDIREFRESHMENU                               EQU     00234H
WM_POINTERDEVICECHANGE                          EQU     00238H
WM_POINTERDEVICEINRANGE                         EQU     00239H
WM_POINTERDEVICEOUTOFRANGE                      EQU     0023AH

WM_TOUCH                                        EQU     00240H
WM_NCPOINTERUPDATE                              EQU     00241H
WM_NCPOINTERDOWN                                EQU     00242H
WM_NCPOINTERUP                                  EQU     00243H
WM_NCPOINTERCANCEL                              EQU     00244H
WM_POINTERUPDATE                                EQU     00245H
WM_POINTERDOWN                                  EQU     00246H
WM_POINTERUP                                    EQU     00247H
WM_POINTERCANCEL                                EQU     00248H
WM_POINTERENTER                                 EQU     00249H
WM_POINTERLEAVE                                 EQU     0024AH
WM_POINTERACTIVATE                              EQU     0024BH
WM_POINTERCAPTURECHANGED                        EQU     0024CH
WM_TOUCHHITTESTING                              EQU     0024DH
WM_POINTERWHEEL                                 EQU     0024EH
WM_POINTERHWHEEL                                EQU     0024FH
WM_TOUCHLAST                                    EQU     0024FH

WM_KANJIFIRST                                   EQU     00280H
WM_IME_SETCONTEXT                               EQU     00281H
WM_IME_NOTIFY                                   EQU     00282H
WM_IME_CONTROL                                  EQU     00283H
WM_IME_COMPOSITIONFULL                          EQU     00284H
WM_IME_SELECT                                   EQU     00285H
WM_IME_CHAR                                     EQU     00286H
WM_IME_SYSTEM                                   EQU     00287H
WM_IME_REQUEST                                  EQU     00288H

WM_IME_KEYDOWN                                  EQU     00290H
WM_IME_KEYUP                                    EQU     00291H
WM_KANJILAST                                    EQU     0029FH

WM_NCMOUSEHOVER                                 EQU     002A0H
WM_MOUSEHOVER                                   EQU     002A1H
WM_NCMOUSELEAVE                                 EQU     002A2H
WM_MOUSELEAVE                                   EQU     002A3H

WM_WTSSESSION_CHANGE                            EQU     002B1H

WM_DPICHANGED                                   EQU     002E0H

WM_CUT                                          EQU     00300H
WM_COPY                                         EQU     00301H
WM_PASTE                                        EQU     00302H
WM_CLEAR                                        EQU     00303H
WM_UNDO                                         EQU     00304H
WM_RENDERFORMAT                                 EQU     00305H
WM_RENDERALLFORMATS                             EQU     00306H
WM_DESTROYCLIPBOARD                             EQU     00307H
WM_DRAWCLIPBOARD                                EQU     00308H
WM_PAINTCLIPBOARD                               EQU     00309H
WM_VSCROLLCLIPBOARD                             EQU     0030AH
WM_SIZECLIPBOARD                                EQU     0030BH
WM_ASKCBFORMATNAME                              EQU     0030CH
WM_CHANGECBCHAIN                                EQU     0030DH
WM_HSCROLLCLIPBOARD                             EQU     0030EH
WM_QUERYNEWPALETTE                              EQU     0030FH

WM_PALETTEISCHANGING                            EQU     00310H
WM_PALETTECHANGED                               EQU     00311H
WM_HOTKEY                                       EQU     00312H
WM_SYSMENU                                      EQU     00313H
WM_HOOKMSG                                      EQU     00314H
WM_EXITPROCESS                                  EQU     00315H
WM_WAKETHREAD                                   EQU     00316H
WM_PRINT                                        EQU     00317H
WM_PRINTCLIENT                                  EQU     00318H
WM_APPCOMMAND                                   EQU     00319H
WM_THEMECHANGED                                 EQU     0031AH
WM_UAHINIT                                      EQU     0031BH
WM_DESKTOPNOTIFY                                EQU     0031CH
WM_CLIPBOARDUPDATE                              EQU     0031DH
WM_DWMCOMPOSITIONCHANGED                        EQU     0031EH
WM_DWMNCRENDERINGCHANGED                        EQU     0031FH

WM_DWMCOLORIZATIONCOLORCHANGED                  EQU     00320H
WM_DWMWINDOWMAXIMIZEDCHANGE                     EQU     00321H
WM_DWMEXILEFRAME                                EQU     00322H
WM_DWMSENDICONICTHUMBNAIL                       EQU     00323H
WM_DWMSENDICONICLIVEPREVIEWBITMAP               EQU     00326H
WM_DWMTHUMBNAILSIZECHANGED                      EQU     00327H
WM_MAGNIFICATION_OUTPUT                         EQU     00328H

WM_MEASURECONTROL                               EQU     00330H
WM_GETACTIONTEXT                                EQU     00331H
WM_FORWARDKEYDOWN                               EQU     00333H
WM_FORWARDKEYUP                                 EQU     00334H
WM_GETTITLEBARINFOEX                            EQU     0033FH

WM_NOTIFYWOW                                    EQU     00340H

WM_HANDHELDFIRST                                EQU     00358H
WM_HANDHELDLAST                                 EQU     0035FH

WM_AFXFIRST                                     EQU     00360H
WM_AFXLAST                                      EQU     0037FH

WM_PENWINFIRST                                  EQU     00380H
WM_PENWINLAST                                   EQU     0038FH

WM_COALESCE_FIRST                               EQU     00390H
WM_COALESCE_LAST                                EQU     0039FH

WM_MM_RESERVED_FIRST                            EQU     003A0H

WM_MM_RESERVED_LAST                             EQU     003DFH

WM_DDE_INITIATE                                 EQU     003E0H
WM_DDE_TERMINATE                                EQU     003E1H
WM_DDE_ADVISE                                   EQU     003E2H
WM_DDE_UNADVISE                                 EQU     003E3H
WM_DDE_ACK                                      EQU     003E4H
WM_DDE_DATA                                     EQU     003E5H
WM_DDE_REQUEST                                  EQU     003E6H
WM_DDE_POKE                                     EQU     003E7H
WM_DDE_EXECUTE                                  EQU     003E8H

WM_DBNOTIFICATION                               EQU     003FDH
WM_NETCONNECT                                   EQU     003FEH
WM_HIBERNATE                                    EQU     003FFH

WM_USER                                         EQU     00400H

WM_APP                                          EQU     08000H

WM_GRAPHNOTIFY                                  EQU     (WM_APP + 1)

UIS_SET                                         EQU     1
UIS_CLEAR                                       EQU     2
UIS_INITIALIZE                                  EQU     3

UISF_HIDEFOCUS                                  EQU     01H
UISF_HIDEACCEL                                  EQU     02H

MN_SETHMENU                                     EQU     001E0H
MN_GETHMENU                                     EQU     001E1H
MN_SIZEWINDOW                                   EQU     001E2H
MN_OPENHIERARCHY                                EQU     001E3H
MN_CLOSEHIERARCHY                               EQU     001E4H
MN_SELECTITEM                                   EQU     001E5H
MN_CANCELMENUS                                  EQU     001E6H
MN_SELECTFIRSTVALIDITEM                         EQU     001E7H
MN_GETPPOPUPMENU                                EQU     001EAH
MN_FINDMENUWINDOWFROMPOINT                      EQU     001EBH
MN_SHOWPOPUPWINDOW                              EQU     001ECH
MN_BUTTONDOWN                                   EQU     001EDH
MN_MOUSEMOVE                                    EQU     001EEH
MN_BUTTONUP                                     EQU     001EFH
MN_SETTIMERTOOPENHIERARCHY                      EQU     001F0H
MN_DBLCLK                                       EQU     001F1H

WHEEL_DELTA                                     EQU     120
WHEEL_PAGESCROLL                                EQU     0FFFFFFFFH

XBUTTON1                                        EQU     00001H
XBUTTON2                                        EQU     00002H

PBT_APMQUERYSUSPEND                             EQU     00000H
PBT_APMQUERYSTANDBY                             EQU     00001H

PBT_APMQUERYSUSPENDFAILED                       EQU     00002H
PBT_APMQUERYSTANDBYFAILED                       EQU     00003H

PBT_APMSUSPEND                                  EQU     00004H
PBT_APMSTANDBY                                  EQU     00005H

PBT_APMRESUMECRITICAL                           EQU     00006H
PBT_APMRESUMESUSPEND                            EQU     00007H
PBT_APMRESUMESTANDBY                            EQU     00008H

PBTF_APMRESUMEFROMFAILURE                       EQU     000000001H
PBT_POWERSETTINGCHANGE                          EQU     08013H

PBT_APMBATTERYLOW                               EQU     00009H
PBT_APMPOWERSTATUSCHANGE                        EQU     0000AH

PBT_APMOEMEVENT                                 EQU     0000BH
PBT_APMRESUMEAUTOMATIC                          EQU     00012H

WMSZ_LEFT                                       EQU     1
WMSZ_RIGHT                                      EQU     2
WMSZ_TOP                                        EQU     3
WMSZ_TOPLEFT                                    EQU     4
WMSZ_TOPRIGHT                                   EQU     5
WMSZ_BOTTOM                                     EQU     6
WMSZ_BOTTOMLEFT                                 EQU     7
WMSZ_BOTTOMRIGHT                                EQU     8

HTERROR                                         EQU     (-2)
HTTRANSPARENT                                   EQU     (-1)
HTNOWHERE                                       EQU     0
HTCLIENT                                        EQU     1
HTCAPTION                                       EQU     2
HTSYSMENU                                       EQU     3
HTGROWBOX                                       EQU     4
HTSIZE                                          EQU     HTGROWBOX
HTMENU                                          EQU     5
HTHSCROLL                                       EQU     6
HTVSCROLL                                       EQU     7
HTMINBUTTON                                     EQU     8
HTMAXBUTTON                                     EQU     9
HTLEFT                                          EQU     10
HTRIGHT                                         EQU     11
HTTOP                                           EQU     12
HTTOPLEFT                                       EQU     13
HTTOPRIGHT                                      EQU     14
HTBOTTOM                                        EQU     15
HTBOTTOMLEFT                                    EQU     16
HTBOTTOMRIGHT                                   EQU     17
HTBORDER                                        EQU     18
HTREDUCE                                        EQU     HTMINBUTTON
HTZOOM                                          EQU     HTMAXBUTTON
HTSIZEFIRST                                     EQU     HTLEFT
HTSIZELAST                                      EQU     HTBOTTOMRIGHT
HTOBJECT                                        EQU     19
HTCLOSE                                         EQU     20
HTHELP                                          EQU     21

SMTO_NORMAL                                     EQU     00000H
SMTO_BLOCK                                      EQU     00001H
SMTO_ABORTIFHUNG                                EQU     00002H
SMTO_NOTIMEOUTIFNOTHUNG                         EQU     00008H

MA_ACTIVATE                                     EQU     1
MA_ACTIVATEANDEAT                               EQU     2
MA_NOACTIVATE                                   EQU     3
MA_NOACTIVATEANDEAT                             EQU     4

ICON_SMALL                                      EQU     0
ICON_BIG                                        EQU     1

SIZE_RESTORED                                   EQU     0
SIZE_MINIMIZED                                  EQU     1
SIZE_MAXIMIZED                                  EQU     2
SIZE_MAXSHOW                                    EQU     3
SIZE_MAXHIDE                                    EQU     4

SIZENORMAL                                      EQU     SIZE_RESTORED
SIZEICONIC                                      EQU     SIZE_MINIMIZED
SIZEFULLSCREEN                                  EQU     SIZE_MAXIMIZED
SIZEZOOMSHOW                                    EQU     SIZE_MAXSHOW
SIZEZOOMHIDE                                    EQU     SIZE_MAXHIDE

WVR_ALIGNTOP                                    EQU     00010H
WVR_ALIGNLEFT                                   EQU     00020H
WVR_ALIGNBOTTOM                                 EQU     00040H
WVR_ALIGNRIGHT                                  EQU     00080H
WVR_HREDRAW                                     EQU     00100H
WVR_VREDRAW                                     EQU     00200H
WVR_REDRAW                                      EQU     (WVR_HREDRAW OR WVR_VREDRAW)
WVR_VALIDRECTS                                  EQU     00400H

MK_LBUTTON                                      EQU     00001H
MK_RBUTTON                                      EQU     00002H
MK_SHIFT                                        EQU     00004H
MK_CONTROL                                      EQU     00008H
MK_MBUTTON                                      EQU     00010H

TME_HOVER                                       EQU     000000001H
TME_LEAVE                                       EQU     000000002H
TME_QUERY                                       EQU     040000000H
TME_CANCEL                                      EQU     080000000H

HOVER_DEFAULT                                   EQU     0FFFFFFFFH

WS_OVERLAPPED                                   EQU     000000000H
WS_POPUP                                        EQU     080000000H
WS_CHILD                                        EQU     040000000H
WS_MINIMIZE                                     EQU     020000000H
WS_VISIBLE                                      EQU     010000000H
WS_DISABLED                                     EQU     008000000H
WS_CLIPSIBLINGS                                 EQU     004000000H
WS_CLIPCHILDREN                                 EQU     002000000H
WS_MAXIMIZE                                     EQU     001000000H
WS_CAPTION                                      EQU     000C00000H
WS_BORDER                                       EQU     000800000H
WS_DLGFRAME                                     EQU     000400000H
WS_VSCROLL                                      EQU     000200000H
WS_HSCROLL                                      EQU     000100000H
WS_SYSMENU                                      EQU     000080000H
WS_THICKFRAME                                   EQU     000040000H
WS_GROUP                                        EQU     000020000H
WS_TABSTOP                                      EQU     000010000H

WS_MAXIMIZEBOX                                  EQU     000010000H
WS_MINIMIZEBOX                                  EQU     000020000H

WS_TILED                                        EQU     WS_OVERLAPPED
WS_ICONIC                                       EQU     WS_MINIMIZE
WS_SIZEBOX                                      EQU     WS_THICKFRAME
WS_TILEDWINDOW                                  EQU     WS_OVERLAPPEDWINDOW

WS_OVERLAPPEDWINDOW                             EQU     (WS_OVERLAPPED OR WS_CAPTION OR WS_SYSMENU OR WS_THICKFRAME OR WS_MINIMIZEBOX OR WS_MAXIMIZEBOX)

WS_POPUPWINDOW                                  EQU     (WS_POPUP OR WS_BORDER OR WS_SYSMENU)

WS_CHILDWINDOW                                  EQU     WS_CHILD

WS_EX_DLGMODALFRAME                             EQU     000000001H
WS_EX_NOPARENTNOTIFY                            EQU     000000004H
WS_EX_TOPMOST                                   EQU     000000008H
WS_EX_ACCEPTFILES                               EQU     000000010H
WS_EX_TRANSPARENT                               EQU     000000020H
WS_EX_MDICHILD                                  EQU     000000040H
WS_EX_TOOLWINDOW                                EQU     000000080H
WS_EX_WINDOWEDGE                                EQU     000000100H
WS_EX_CLIENTEDGE                                EQU     000000200H
WS_EX_CONTEXTHELP                               EQU     000000400H
WS_EX_RIGHT                                     EQU     000001000H
WS_EX_LEFT                                      EQU     000000000H
WS_EX_RTLREADING                                EQU     000002000H
WS_EX_LTRREADING                                EQU     000000000H
WS_EX_LEFTSCROLLBAR                             EQU     000004000H
WS_EX_RIGHTSCROLLBAR                            EQU     000000000H
WS_EX_CONTROLPARENT                             EQU     000010000H
WS_EX_STATICEDGE                                EQU     000020000H
WS_EX_APPWINDOW                                 EQU     000040000H

WS_EX_OVERLAPPEDWINDOW                          EQU     (WS_EX_WINDOWEDGE OR WS_EX_CLIENTEDGE)
WS_EX_PALETTEWINDOW                             EQU     (WS_EX_WINDOWEDGE OR WS_EX_TOOLWINDOW OR WS_EX_TOPMOST)

WS_EX_NOINHERITLAYOUT                           EQU     000100000H
WS_EX_LAYOUTRTL                                 EQU     000400000H
WS_EX_LAYERED                                   EQU     000080000H
WS_EX_NOACTIVATE                                EQU     008000000H
WS_EX_COMPOSITED                                EQU     002000000H

CS_VREDRAW                                      EQU     00001H
CS_HREDRAW                                      EQU     00002H
CS_DBLCLKS                                      EQU     00008H
CS_OWNDC                                        EQU     00020H
CS_CLASSDC                                      EQU     00040H
CS_PARENTDC                                     EQU     00080H
CS_NOCLOSE                                      EQU     00200H
CS_SAVEBITS                                     EQU     00800H
CS_BYTEALIGNCLIENT                              EQU     01000H
CS_BYTEALIGNWINDOW                              EQU     02000H
CS_GLOBALCLASS                                  EQU     04000H

CS_IME                                          EQU     000010000H
CS_DROPSHADOW                                   EQU     000020000H

PRF_CHECKVISIBLE                                EQU     000000001H
PRF_NONCLIENT                                   EQU     000000002H
PRF_CLIENT                                      EQU     000000004H
PRF_ERASEBKGND                                  EQU     000000008H
PRF_CHILDREN                                    EQU     000000010H
PRF_OWNED                                       EQU     000000020H

BDR_RAISEDOUTER                                 EQU     00001H
BDR_SUNKENOUTER                                 EQU     00002H
BDR_RAISEDINNER                                 EQU     00004H
BDR_SUNKENINNER                                 EQU     00008H

BDR_OUTER                                       EQU     00003H
BDR_INNER                                       EQU     0000CH
BDR_RAISED                                      EQU     (BDR_RAISEDOUTER OR BDR_RAISEDINNER)
BDR_SUNKEN                                      EQU     (BDR_SUNKENOUTER OR BDR_SUNKENINNER)

EDGE_RAISED                                     EQU     (BDR_RAISEDOUTER OR BDR_RAISEDINNER)
EDGE_SUNKEN                                     EQU     (BDR_SUNKENOUTER OR BDR_SUNKENINNER)
EDGE_ETCHED                                     EQU     (BDR_SUNKENOUTER OR BDR_RAISEDINNER)
EDGE_BUMP                                       EQU     (BDR_RAISEDOUTER OR BDR_SUNKENINNER)

BF_LEFT                                         EQU     00001H
BF_TOP                                          EQU     00002H
BF_RIGHT                                        EQU     00004H
BF_BOTTOM                                       EQU     00008H

BF_TOPLEFT                                      EQU     (BF_TOP OR BF_LEFT)
BF_TOPRIGHT                                     EQU     (BF_TOP OR BF_RIGHT)
BF_BOTTOMLEFT                                   EQU     (BF_BOTTOM OR BF_LEFT)
BF_BOTTOMRIGHT                                  EQU     (BF_BOTTOM OR BF_RIGHT)
BF_RECT                                         EQU     (BF_LEFT OR BF_TOP OR BF_RIGHT OR BF_BOTTOM)

BF_DIAGONAL                                     EQU     00010H

BF_DIAGONAL_ENDTOPRIGHT                         EQU     (BF_DIAGONAL OR BF_TOP OR BF_RIGHT)
BF_DIAGONAL_ENDTOPLEFT                          EQU     (BF_DIAGONAL OR BF_TOP OR BF_LEFT)
BF_DIAGONAL_ENDBOTTOMLEFT                       EQU     (BF_DIAGONAL OR BF_BOTTOM OR BF_LEFT)
BF_DIAGONAL_ENDBOTTOMRIGHT                      EQU     (BF_DIAGONAL OR BF_BOTTOM OR BF_RIGHT)

BF_MIDDLE                                       EQU     00800H
BF_SOFT                                         EQU     01000H
BF_ADJUST                                       EQU     02000H
BF_FLAT                                         EQU     04000H
BF_MONO                                         EQU     08000H

DFC_CAPTION                                     EQU     1
DFC_MENU                                        EQU     2
DFC_SCROLL                                      EQU     3
DFC_BUTTON                                      EQU     4
DFC_POPUPMENU                                   EQU     5

DFCS_CAPTIONCLOSE                               EQU     00000H
DFCS_CAPTIONMIN                                 EQU     00001H
DFCS_CAPTIONMAX                                 EQU     00002H
DFCS_CAPTIONRESTORE                             EQU     00003H
DFCS_CAPTIONHELP                                EQU     00004H

DFCS_MENUARROW                                  EQU     00000H
DFCS_MENUCHECK                                  EQU     00001H
DFCS_MENUBULLET                                 EQU     00002H
DFCS_MENUARROWRIGHT                             EQU     00004H
DFCS_SCROLLUP                                   EQU     00000H
DFCS_SCROLLDOWN                                 EQU     00001H
DFCS_SCROLLLEFT                                 EQU     00002H
DFCS_SCROLLRIGHT                                EQU     00003H
DFCS_SCROLLCOMBOBOX                             EQU     00005H
DFCS_SCROLLSIZEGRIP                             EQU     00008H
DFCS_SCROLLSIZEGRIPRIGHT                        EQU     00010H

DFCS_BUTTONCHECK                                EQU     00000H
DFCS_BUTTONRADIOIMAGE                           EQU     00001H
DFCS_BUTTONRADIOMASK                            EQU     00002H
DFCS_BUTTONRADIO                                EQU     00004H
DFCS_BUTTON3STATE                               EQU     00008H
DFCS_BUTTONPUSH                                 EQU     00010H

DFCS_INACTIVE                                   EQU     00100H
DFCS_PUSHED                                     EQU     00200H
DFCS_CHECKED                                    EQU     00400H

DFCS_TRANSPARENT                                EQU     00800H
DFCS_HOT                                        EQU     01000H

DFCS_ADJUSTRECT                                 EQU     02000H
DFCS_FLAT                                       EQU     04000H
DFCS_MONO                                       EQU     08000H

DC_ACTIVE                                       EQU     00001H
DC_SMALLCAP                                     EQU     00002H
DC_ICON                                         EQU     00004H
DC_TEXT                                         EQU     00008H
DC_INBUTTON                                     EQU     00010H
DC_GRADIENT                                     EQU     00020H
DC_BUTTONS                                      EQU     01000H

IDANI_OPEN                                      EQU     1
IDANI_CLOSE                                     EQU     2
IDANI_CAPTION                                   EQU     3

CF_TEXT                                         EQU     1
CF_BITMAP                                       EQU     2
CF_METAFILEPICT                                 EQU     3
CF_SYLK                                         EQU     4
CF_DIF                                          EQU     5
CF_TIFF                                         EQU     6
CF_OEMTEXT                                      EQU     7
CF_DIB                                          EQU     8
CF_PALETTE                                      EQU     9
CF_PENDATA                                      EQU     10
CF_RIFF                                         EQU     11
CF_WAVE                                         EQU     12
CF_UNICODETEXT                                  EQU     13
CF_ENHMETAFILE                                  EQU     14
CF_HDROP                                        EQU     15
CF_LOCALE                                       EQU     16
CF_DIBV5                                        EQU     17
IF (NTDDI_VERSION LE NTDDI_WINNT4)
    CF_MAX                                      EQU     17
ELSE
    CF_MAX                                      EQU     18
ENDIF

CF_OWNERDISPLAY                                 EQU     00080H
CF_DSPTEXT                                      EQU     00081H
CF_DSPBITMAP                                    EQU     00082H
CF_DSPMETAFILEPICT                              EQU     00083H
CF_DSPENHMETAFILE                               EQU     0008EH

CF_PRIVATEFIRST                                 EQU     00200H
CF_PRIVATELAST                                  EQU     002FFH

CF_GDIOBJFIRST                                  EQU     00300H
CF_GDIOBJLAST                                   EQU     003FFH

FVIRTKEY                                        EQU     TRUE
FNOINVERT                                       EQU     002H
FSHIFT                                          EQU     004H
FCONTROL                                        EQU     008H
FALT                                            EQU     010H

WPF_SETMINPOSITION                              EQU     00001H
WPF_RESTORETOMAXIMIZED                          EQU     00002H
WPF_ASYNCWINDOWPLACEMENT                        EQU     00004H

ODT_MENU                                        EQU     1
ODT_LISTBOX                                     EQU     2
ODT_COMBOBOX                                    EQU     3
ODT_BUTTON                                      EQU     4
ODT_STATIC                                      EQU     5

ODA_DRAWENTIRE                                  EQU     00001H
ODA_SELECT                                      EQU     00002H
ODA_FOCUS                                       EQU     00004H

ODS_SELECTED                                    EQU     00001H
ODS_GRAYED                                      EQU     00002H
ODS_DISABLED                                    EQU     00004H
ODS_CHECKED                                     EQU     00008H
ODS_FOCUS                                       EQU     00010H
ODS_DEFAULT                                     EQU     00020H
ODS_COMBOBOXEDIT                                EQU     01000H
ODS_HOTLIGHT                                    EQU     00040H
ODS_INACTIVE                                    EQU     00080H
ODS_NOACCEL                                     EQU     00100H
ODS_NOFOCUSRECT                                 EQU     00200H

QS_KEY                                          EQU     00001H
QS_MOUSEMOVE                                    EQU     00002H
QS_MOUSEBUTTON                                  EQU     00004H
QS_POSTMESSAGE                                  EQU     00008H
QS_TIMER                                        EQU     00010H
QS_PAINT                                        EQU     00020H
QS_SENDMESSAGE                                  EQU     00040H
QS_HOTKEY                                       EQU     00080H
QS_ALLPOSTMESSAGE                               EQU     00100H
QS_MOUSE                                        EQU     (QS_MOUSEMOVE OR QS_MOUSEBUTTON)
QS_TOUCH                                        EQU     00800H
QS_POINTER                                      EQU     01000H
IF (NTDDI_VERSION GE NTDDI_WIN8)
    QS_INPUT                                    EQU     (QS_MOUSE OR QS_KEY OR QS_RAWINPUT OR QS_TOUCH OR QS_POINTER)
ELSEIF (NTDDI_VERSION GE NTDDI_WIN2K)
    QS_INPUT                                    EQU     (QS_MOUSE OR QS_KEY OR QS_RAWINPUT)
ELSE
    QS_INPUT                                    EQU     (QS_MOUSE OR QS_KEY)
ENDIF

QS_ALLEVENTS                                    EQU     (QS_INPUT OR QS_POSTMESSAGE OR QS_TIMER OR QS_PAINT OR QS_HOTKEY)
QS_ALLINPUT                                     EQU     (QS_INPUT OR QS_POSTMESSAGE OR QS_TIMER OR QS_PAINT OR QS_HOTKEY OR QS_SENDMESSAGE)

PM_NOREMOVE                                     EQU     00000H
PM_REMOVE                                       EQU     00001H
PM_NOYIELD                                      EQU     00002H
PM_QS_INPUT                                     EQU     (QS_INPUT SHL 16)
PM_QS_POSTMESSAGE                               EQU     ((QS_POSTMESSAGE OR QS_HOTKEY OR QS_TIMER) SHL 16)
PM_QS_PAINT                                     EQU     (QS_PAINT SHL 16)
PM_QS_SENDMESSAGE                               EQU     (QS_SENDMESSAGE SHL 16)

MOD_ALT                                         EQU     00001H
MOD_CONTROL                                     EQU     00002H
MOD_SHIFT                                       EQU     00004H
MOD_WIN                                         EQU     00008H
MOD_NOREPEAT                                    EQU     04000H

IDHOT_SNAPWINDOW                                EQU     (-1)
IDHOT_SNAPDESKTOP                               EQU     (-2)

ENDSESSION_LOGOFF                               EQU     080000000H

EWX_LOGOFF                                      EQU     0
EWX_SHUTDOWN                                    EQU     000000001H
EWX_REBOOT                                      EQU     000000002H
EWX_FORCE                                       EQU     000000004H
EWX_POWEROFF                                    EQU     000000008H
EWX_FORCEIFHUNG                                 EQU     000000010H
EWX_QUICKRESOLVE                                EQU     000000020H
EWX_RESTARTAPPS                                 EQU     000000040H
EWX_SHUTDOWN_FULL                               EQU     000400000H

BSM_ALLCOMPONENTS                               EQU     000000000H
BSM_VXDS                                        EQU     000000001H
BSM_NETDRIVER                                   EQU     000000002H
BSM_INSTALLABLEDRIVERS                          EQU     000000004H
BSM_APPLICATIONS                                EQU     000000008H
BSM_ALLDESKTOPS                                 EQU     000000010H

BSF_QUERY                                       EQU     000000001H
BSF_IGNORECURRENTTASK                           EQU     000000002H
BSF_FLUSHDISK                                   EQU     000000004H
BSF_NOHANG                                      EQU     000000008H
BSF_POSTMESSAGE                                 EQU     000000010H
BSF_FORCEIFHUNG                                 EQU     000000020H
BSF_NOTIMEOUTIFNOTHUNG                          EQU     000000040H
BSF_ALLOWSFW                                    EQU     000000080H
BSF_SENDNOTIFYMESSAGE                           EQU     000000100H
BSF_RETURNHDESK                                 EQU     000000200H
BSF_LUID                                        EQU     000000400H

BROADCAST_QUERY_DENY                            EQU     0424D5144H

DEVICE_NOTIFY_WINDOW_HANDLE                     EQU     000000000H
DEVICE_NOTIFY_SERVICE_HANDLE                    EQU     000000001H

HWND_BROADCAST                                  EQU     0FFFFH

HWND_MESSAGE                                    EQU     (-3)

ISMEX_NOSEND                                    EQU     000000000H
ISMEX_SEND                                      EQU     000000001H
ISMEX_NOTIFY                                    EQU     000000002H
ISMEX_CALLBACK                                  EQU     000000004H
ISMEX_REPLIED                                   EQU     000000008H

CW_USEDEFAULT                                   EQU     080000000H

HWND_DESKTOP                                    EQU     0

LWA_COLORKEY                                    EQU     000000001H
LWA_ALPHA                                       EQU     000000002H

ULW_COLORKEY                                    EQU     000000001H
ULW_ALPHA                                       EQU     000000002H
ULW_OPAQUE                                      EQU     000000004H

FLASHW_STOP                                     EQU     0
FLASHW_CAPTION                                  EQU     000000001H
FLASHW_TRAY                                     EQU     000000002H
FLASHW_ALL                                      EQU     (FLASHW_CAPTION OR FLASHW_TRAY)
FLASHW_TIMER                                    EQU     000000004H
FLASHW_TIMERNOFG                                EQU     00000000CH

SWP_NOSIZE                                      EQU     00001H
SWP_NOMOVE                                      EQU     00002H
SWP_NOZORDER                                    EQU     00004H
SWP_NOREDRAW                                    EQU     00008H
SWP_NOACTIVATE                                  EQU     00010H
SWP_FRAMECHANGED                                EQU     00020H
SWP_SHOWWINDOW                                  EQU     00040H
SWP_HIDEWINDOW                                  EQU     00080H
SWP_NOCOPYBITS                                  EQU     00100H
SWP_NOOWNERZORDER                               EQU     00200H
SWP_NOSENDCHANGING                              EQU     00400H

SWP_DRAWFRAME                                   EQU     SWP_FRAMECHANGED
SWP_NOREPOSITION                                EQU     SWP_NOOWNERZORDER

SWP_DEFERERASE                                  EQU     02000H
SWP_ASYNCWINDOWPOS                              EQU     04000H

HWND_TOP                                        EQU     0
HWND_BOTTOM                                     EQU     1
HWND_TOPMOST                                    EQU     (-1)
HWND_NOTOPMOST                                  EQU     (-2)

DLGWINDOWEXTRA                                  EQU     30

KEYEVENTF_EXTENDEDKEY                           EQU     00001H
KEYEVENTF_KEYUP                                 EQU     00002H
KEYEVENTF_UNICODE                               EQU     00004H
KEYEVENTF_SCANCODE                              EQU     00008H

MOUSEEVENTF_MOVE                                EQU     00001H
MOUSEEVENTF_LEFTDOWN                            EQU     00002H
MOUSEEVENTF_LEFTUP                              EQU     00004H
MOUSEEVENTF_RIGHTDOWN                           EQU     00008H
MOUSEEVENTF_RIGHTUP                             EQU     00010H
MOUSEEVENTF_MIDDLEDOWN                          EQU     00020H
MOUSEEVENTF_MIDDLEUP                            EQU     00040H
MOUSEEVENTF_XDOWN                               EQU     00080H
MOUSEEVENTF_XUP                                 EQU     00100H
MOUSEEVENTF_WHEEL                               EQU     00800H
MOUSEEVENTF_HWHEEL                              EQU     01000H
MOUSEEVENTF_MOVE_NOCOALESCE                     EQU     02000H
MOUSEEVENTF_VIRTUALDESK                         EQU     04000H
MOUSEEVENTF_ABSOLUTE                            EQU     08000H

INPUT_MOUSE                                     EQU     0
INPUT_KEYBOARD                                  EQU     1
INPUT_HARDWARE                                  EQU     2

MWMO_WAITALL                                    EQU     00001H
MWMO_ALERTABLE                                  EQU     00002H
MWMO_INPUTAVAILABLE                             EQU     00004H

USER_TIMER_MAXIMUM                              EQU     07FFFFFFFH
USER_TIMER_MINIMUM                              EQU     00000000AH

SM_CXSCREEN                                     EQU     0
SM_CYSCREEN                                     EQU     1
SM_CXVSCROLL                                    EQU     2
SM_CYHSCROLL                                    EQU     3
SM_CYCAPTION                                    EQU     4
SM_CXBORDER                                     EQU     5
SM_CYBORDER                                     EQU     6
SM_CXDLGFRAME                                   EQU     7
SM_CYDLGFRAME                                   EQU     8
SM_CYVTHUMB                                     EQU     9
SM_CXHTHUMB                                     EQU     10
SM_CXICON                                       EQU     11
SM_CYICON                                       EQU     12
SM_CXCURSOR                                     EQU     13
SM_CYCURSOR                                     EQU     14
SM_CYMENU                                       EQU     15
SM_CXFULLSCREEN                                 EQU     16
SM_CYFULLSCREEN                                 EQU     17
SM_CYKANJIWINDOW                                EQU     18
SM_MOUSEPRESENT                                 EQU     19
SM_CYVSCROLL                                    EQU     20
SM_CXHSCROLL                                    EQU     21
SM_DEBUG                                        EQU     22
SM_SWAPBUTTON                                   EQU     23
SM_RESERVED1                                    EQU     24
SM_RESERVED2                                    EQU     25
SM_RESERVED3                                    EQU     26
SM_RESERVED4                                    EQU     27
SM_CXMIN                                        EQU     28
SM_CYMIN                                        EQU     29
SM_CXSIZE                                       EQU     30
SM_CYSIZE                                       EQU     31
SM_CXFRAME                                      EQU     32
SM_CYFRAME                                      EQU     33
SM_CXMINTRACK                                   EQU     34
SM_CYMINTRACK                                   EQU     35
SM_CXDOUBLECLK                                  EQU     36
SM_CYDOUBLECLK                                  EQU     37
SM_CXICONSPACING                                EQU     38
SM_CYICONSPACING                                EQU     39
SM_MENUDROPALIGNMENT                            EQU     40
SM_PENWINDOWS                                   EQU     41
SM_DBCSENABLED                                  EQU     42
SM_CMOUSEBUTTONS                                EQU     43

SM_CXFIXEDFRAME                                 EQU     SM_CXDLGFRAME
SM_CYFIXEDFRAME                                 EQU     SM_CYDLGFRAME
SM_CXSIZEFRAME                                  EQU     SM_CXFRAME
SM_CYSIZEFRAME                                  EQU     SM_CYFRAME

SM_SECURE                                       EQU     44
SM_CXEDGE                                       EQU     45
SM_CYEDGE                                       EQU     46
SM_CXMINSPACING                                 EQU     47
SM_CYMINSPACING                                 EQU     48
SM_CXSMICON                                     EQU     49
SM_CYSMICON                                     EQU     50
SM_CYSMCAPTION                                  EQU     51
SM_CXSMSIZE                                     EQU     52
SM_CYSMSIZE                                     EQU     53
SM_CXMENUSIZE                                   EQU     54
SM_CYMENUSIZE                                   EQU     55
SM_ARRANGE                                      EQU     56
SM_CXMINIMIZED                                  EQU     57
SM_CYMINIMIZED                                  EQU     58
SM_CXMAXTRACK                                   EQU     59
SM_CYMAXTRACK                                   EQU     60
SM_CXMAXIMIZED                                  EQU     61
SM_CYMAXIMIZED                                  EQU     62
SM_NETWORK                                      EQU     63
SM_CLEANBOOT                                    EQU     67
SM_CXDRAG                                       EQU     68
SM_CYDRAG                                       EQU     69
SM_SHOWSOUNDS                                   EQU     70
SM_CXMENUCHECK                                  EQU     71
SM_CYMENUCHECK                                  EQU     72
SM_SLOWMACHINE                                  EQU     73
SM_MIDEASTENABLED                               EQU     74
SM_MOUSEWHEELPRESENT                            EQU     75
SM_XVIRTUALSCREEN                               EQU     76
SM_YVIRTUALSCREEN                               EQU     77
SM_CXVIRTUALSCREEN                              EQU     78
SM_CYVIRTUALSCREEN                              EQU     79
SM_CMONITORS                                    EQU     80
SM_SAMEDISPLAYFORMAT                            EQU     81
SM_IMMENABLED                                   EQU     82
SM_CXFOCUSBORDER                                EQU     83
SM_CYFOCUSBORDER                                EQU     84
SM_TABLETPC                                     EQU     86
SM_MEDIACENTER                                  EQU     87
SM_STARTER                                      EQU     88
SM_SERVERR2                                     EQU     89
SM_MOUSEHORIZONTALWHEELPRESENT                  EQU     91
SM_CXPADDEDBORDER                               EQU     92
SM_DIGITIZER                                    EQU     94
SM_MAXIMUMTOUCHES                               EQU     95
SM_REMOTESESSION                                EQU     01000H
SM_SHUTTINGDOWN                                 EQU     02000H
SM_REMOTECONTROL                                EQU     02001H
SM_CARETBLINKINGENABLED                         EQU     02002H
IF (NTDDI_VERSION GE NTDDI_WIN7)
    SM_CMETRICS                                 EQU     97
ELSEIF (NTDDI_VERSION GE NTDDI_VISTA)
    SM_CMETRICS                                 EQU     93
ELSEIF (NTDDI_VERSION GE NTDDI_WINXP)
    SM_CMETRICS                                 EQU     90
ELSEIF (NTDDI_VERSION EQ NTDDI_WIN2K)
    SM_CMETRICS                                 EQU     83
ELSE
    SM_CMETRICS                                 EQU     76
ENDIF

PMB_ACTIVE                                      EQU     00000001H

MNC_IGNORE                                      EQU     0
MNC_CLOSE                                       EQU     1
MNC_EXECUTE                                     EQU     2
MNC_SELECT                                      EQU     3

MNS_NOCHECK                                     EQU     080000000H
MNS_MODELESS                                    EQU     040000000H
MNS_DRAGDROP                                    EQU     020000000H
MNS_AUTODISMISS                                 EQU     010000000H
MNS_NOTIFYBYPOS                                 EQU     008000000H
MNS_CHECKORBMP                                  EQU     004000000H

MIM_MAXHEIGHT                                   EQU     000000001H
MIM_BACKGROUND                                  EQU     000000002H
MIM_HELPID                                      EQU     000000004H
MIM_MENUDATA                                    EQU     000000008H
MIM_STYLE                                       EQU     000000010H
MIM_APPLYTOSUBMENUS                             EQU     080000000H

MND_CONTINUE                                    EQU     0
MND_ENDMENU                                     EQU     1

MNGOF_TOPGAP                                    EQU     000000001H
MNGOF_BOTTOMGAP                                 EQU     000000002H

MNGO_NOINTERFACE                                EQU     000000000H
MNGO_NOERROR                                    EQU     000000001H

MIIM_STATE                                      EQU     000000001H
MIIM_ID                                         EQU     000000002H
MIIM_SUBMENU                                    EQU     000000004H
MIIM_CHECKMARKS                                 EQU     000000008H
MIIM_TYPE                                       EQU     000000010H
MIIM_DATA                                       EQU     000000020H

MIIM_STRING                                     EQU     000000040H
MIIM_BITMAP                                     EQU     000000080H
MIIM_FTYPE                                      EQU     000000100H

HBMMENU_CALLBACK                                EQU     (-1)
HBMMENU_SYSTEM                                  EQU     1
HBMMENU_MBAR_RESTORE                            EQU     2
HBMMENU_MBAR_MINIMIZE                           EQU     3
HBMMENU_MBAR_CLOSE                              EQU     5
HBMMENU_MBAR_CLOSE_D                            EQU     6
HBMMENU_MBAR_MINIMIZE_D                         EQU     7
HBMMENU_POPUP_CLOSE                             EQU     8
HBMMENU_POPUP_RESTORE                           EQU     9
HBMMENU_POPUP_MAXIMIZE                          EQU     10
HBMMENU_POPUP_MINIMIZE                          EQU     11

GMDI_USEDISABLED                                EQU     00001H
GMDI_GOINTOPOPUPS                               EQU     00002H

TPM_LEFTBUTTON                                  EQU     00000H
TPM_RIGHTBUTTON                                 EQU     00002H
TPM_LEFTALIGN                                   EQU     00000H
TPM_CENTERALIGN                                 EQU     00004H
TPM_RIGHTALIGN                                  EQU     00008H
TPM_TOPALIGN                                    EQU     00000H
TPM_VCENTERALIGN                                EQU     00010H
TPM_BOTTOMALIGN                                 EQU     00020H

TPM_HORIZONTAL                                  EQU     00000H
TPM_VERTICAL                                    EQU     00040H
TPM_NONOTIFY                                    EQU     00080H
TPM_RETURNCMD                                   EQU     00100H
TPM_RECURSE                                     EQU     00001H

TPM_HORPOSANIMATION                             EQU     00400H
TPM_HORNEGANIMATION                             EQU     00800H
TPM_VERPOSANIMATION                             EQU     01000H
TPM_VERNEGANIMATION                             EQU     02000H
TPM_NOANIMATION                                 EQU     04000H
TPM_LAYOUTRTL                                   EQU     08000H
TPM_WORKAREA                                    EQU     10000H

DOF_EXECUTABLE                                  EQU     08001H
DOF_DOCUMENT                                    EQU     08002H
DOF_DIRECTORY                                   EQU     08003H
DOF_MULTIPLE                                    EQU     08004H
DOF_PROGMAN                                     EQU     00001H
DOF_SHELLDATA                                   EQU     00002H

DO_DROPFILE                                     EQU     0454C4946H
DO_PRINTFILE                                    EQU     0544E5250H

DT_TOP                                          EQU     000000000H
DT_LEFT                                         EQU     000000000H
DT_CENTER                                       EQU     000000001H
DT_RIGHT                                        EQU     000000002H
DT_VCENTER                                      EQU     000000004H
DT_BOTTOM                                       EQU     000000008H
DT_WORDBREAK                                    EQU     000000010H
DT_SINGLELINE                                   EQU     000000020H
DT_EXPANDTABS                                   EQU     000000040H
DT_TABSTOP                                      EQU     000000080H
DT_NOCLIP                                       EQU     000000100H
DT_EXTERNALLEADING                              EQU     000000200H
DT_CALCRECT                                     EQU     000000400H
DT_NOPREFIX                                     EQU     000000800H
DT_INTERNAL                                     EQU     000001000H

DT_EDITCONTROL                                  EQU     000002000H
DT_PATH_ELLIPSIS                                EQU     000004000H
DT_END_ELLIPSIS                                 EQU     000008000H
DT_MODIFYSTRING                                 EQU     000010000H
DT_RTLREADING                                   EQU     000020000H
DT_WORD_ELLIPSIS                                EQU     000040000H
DT_NOFULLWIDTHCHARBREAK                         EQU     000080000H
DT_HIDEPREFIX                                   EQU     000100000H
DT_PREFIXONLY                                   EQU     000200000H

DST_COMPLEX                                     EQU     00000H
DST_TEXT                                        EQU     00001H
DST_PREFIXTEXT                                  EQU     00002H
DST_ICON                                        EQU     00003H
DST_BITMAP                                      EQU     00004H

DSS_NORMAL                                      EQU     00000H
DSS_UNION                                       EQU     00010H
DSS_DISABLED                                    EQU     00020H
DSS_MONO                                        EQU     00080H
DSS_HIDEPREFIX                                  EQU     00200H
DSS_PREFIXONLY                                  EQU     00400H
DSS_RIGHT                                       EQU     08000H

ASFW_ANY                                        EQU     (-1)
LSFW_LOCK                                       EQU     1
LSFW_UNLOCK                                     EQU     2

DCX_WINDOW                                      EQU     000000001H
DCX_CACHE                                       EQU     000000002H
DCX_NORESETATTRS                                EQU     000000004H
DCX_CLIPCHILDREN                                EQU     000000008H
DCX_CLIPSIBLINGS                                EQU     000000010H
DCX_PARENTCLIP                                  EQU     000000020H
DCX_EXCLUDERGN                                  EQU     000000040H
DCX_INTERSECTRGN                                EQU     000000080H
DCX_EXCLUDEUPDATE                               EQU     000000100H
DCX_INTERSECTUPDATE                             EQU     000000200H
DCX_LOCKWINDOWUPDATE                            EQU     000000400H
DCX_VALIDATE                                    EQU     000200000H

CUDR_NORMAL                                     EQU     00000H
CUDR_NOSNAPTOGRID                               EQU     00001H
CUDR_NORESOLVEPOSITIONS                         EQU     00002H
CUDR_NOCLOSEGAPS                                EQU     00004H
CUDR_NEGATIVECOORDS                             EQU     00008H
CUDR_NOPRIMARY                                  EQU     00010H

RDW_INVALIDATE                                  EQU     00001H
RDW_INTERNALPAINT                               EQU     00002H
RDW_ERASE                                       EQU     00004H
RDW_VALIDATE                                    EQU     00008H
RDW_NOINTERNALPAINT                             EQU     00010H
RDW_NOERASE                                     EQU     00020H
RDW_NOCHILDREN                                  EQU     00040H
RDW_ALLCHILDREN                                 EQU     00080H
RDW_UPDATENOW                                   EQU     00100H
RDW_ERASENOW                                    EQU     00200H
RDW_FRAME                                       EQU     00400H
RDW_NOFRAME                                     EQU     00800H

SW_SCROLLCHILDREN                               EQU     00001H
SW_INVALIDATE                                   EQU     00002H
SW_ERASE                                        EQU     00004H
SW_SMOOTHSCROLL                                 EQU     00010H

ESB_ENABLE_BOTH                                 EQU     00000H
ESB_DISABLE_BOTH                                EQU     00003H

ESB_DISABLE_LEFT                                EQU     00001H
ESB_DISABLE_RIGHT                               EQU     00002H

ESB_DISABLE_UP                                  EQU     00001H
ESB_DISABLE_DOWN                                EQU     00002H

ESB_DISABLE_LTUP                                EQU     ESB_DISABLE_LEFT
ESB_DISABLE_RTDN                                EQU     ESB_DISABLE_RIGHT

HELPINFO_WINDOW                                 EQU     00001H
HELPINFO_MENUITEM                               EQU     00002H

MB_OK                                           EQU     000000000H
MB_OKCANCEL                                     EQU     000000001H
MB_ABORTRETRYIGNORE                             EQU     000000002H
MB_YESNOCANCEL                                  EQU     000000003H
MB_YESNO                                        EQU     000000004H
MB_RETRYCANCEL                                  EQU     000000005H
MB_CANCELTRYCONTINUE                            EQU     000000006H
MB_ICONHAND                                     EQU     000000010H
MB_ICONQUESTION                                 EQU     000000020H
MB_ICONEXCLAMATION                              EQU     000000030H
MB_ICONASTERISK                                 EQU     000000040H
MB_USERICON                                     EQU     000000080H
MB_ICONWARNING                                  EQU     MB_ICONEXCLAMATION
MB_ICONERROR                                    EQU     MB_ICONHAND
MB_ICONINFORMATION                              EQU     MB_ICONASTERISK
MB_ICONSTOP                                     EQU     MB_ICONHAND
MB_DEFBUTTON1                                   EQU     000000000H
MB_DEFBUTTON2                                   EQU     000000100H
MB_DEFBUTTON3                                   EQU     000000200H
MB_DEFBUTTON4                                   EQU     000000300H
MB_APPLMODAL                                    EQU     000000000H
MB_SYSTEMMODAL                                  EQU     000001000H
MB_TASKMODAL                                    EQU     000002000H
MB_HELP                                         EQU     000004000H
MB_NOFOCUS                                      EQU     000008000H
MB_SETFOREGROUND                                EQU     000010000H
MB_DEFAULT_DESKTOP_ONLY                         EQU     000020000H
MB_TOPMOST                                      EQU     000040000H
MB_RIGHT                                        EQU     000080000H
MB_RTLREADING                                   EQU     000100000H
IF (NTDDI_VERSION EQ NTDDI_WINNT4)
    MB_SERVICE_NOTIFICATION                     EQU     000040000H
ELSE
    MB_SERVICE_NOTIFICATION                     EQU     000200000H
ENDIF

MB_SERVICE_NOTIFICATION_NT3X                    EQU     000040000H

MB_TYPEMASK                                     EQU     00000000FH
MB_ICONMASK                                     EQU     0000000F0H
MB_DEFMASK                                      EQU     000000F00H
MB_MODEMASK                                     EQU     000003000H
MB_MISCMASK                                     EQU     00000C000H

CWP_ALL                                         EQU     00000H
CWP_SKIPINVISIBLE                               EQU     00001H
CWP_SKIPDISABLED                                EQU     00002H
CWP_SKIPTRANSPARENT                             EQU     00004H

CTLCOLOR_MSGBOX                                 EQU     0
CTLCOLOR_EDIT                                   EQU     1
CTLCOLOR_LISTBOX                                EQU     2
CTLCOLOR_BTN                                    EQU     3
CTLCOLOR_DLG                                    EQU     4
CTLCOLOR_SCROLLBAR                              EQU     5
CTLCOLOR_STATIC                                 EQU     6
CTLCOLOR_MAX                                    EQU     7

SYS_COLOR_INDEX_FLAG                            EQU     0

COLOR_SCROLLBAR                                 EQU     0
COLOR_BACKGROUND                                EQU     1
COLOR_ACTIVECAPTION                             EQU     2
COLOR_INACTIVECAPTION                           EQU     3
COLOR_MENU                                      EQU     4
COLOR_WINDOW                                    EQU     5
COLOR_WINDOWFRAME                               EQU     6
COLOR_MENUTEXT                                  EQU     7
COLOR_WINDOWTEXT                                EQU     8
COLOR_CAPTIONTEXT                               EQU     9
COLOR_ACTIVEBORDER                              EQU     10
COLOR_INACTIVEBORDER                            EQU     11
COLOR_APPWORKSPACE                              EQU     12
COLOR_HIGHLIGHT                                 EQU     13
COLOR_HIGHLIGHTTEXT                             EQU     14
COLOR_BTNFACE                                   EQU     15
COLOR_BTNSHADOW                                 EQU     16
COLOR_GRAYTEXT                                  EQU     17
COLOR_BTNTEXT                                   EQU     18
COLOR_INACTIVECAPTIONTEXT                       EQU     19
COLOR_BTNHIGHLIGHT                              EQU     20
COLOR_3DDKSHADOW                                EQU     21
COLOR_3DLIGHT                                   EQU     22
COLOR_INFOTEXT                                  EQU     23
COLOR_INFOBK                                    EQU     24

COLOR_HOTLIGHT                                  EQU     26
COLOR_GRADIENTACTIVECAPTION                     EQU     27
COLOR_GRADIENTINACTIVECAPTION                   EQU     28
COLOR_MENUHILIGHT                               EQU     29
COLOR_MENUBAR                                   EQU     30

COLOR_DESKTOP                                   EQU     COLOR_BACKGROUND
COLOR_3DFACE                                    EQU     COLOR_BTNFACE
COLOR_3DSHADOW                                  EQU     COLOR_BTNSHADOW
COLOR_3DHIGHLIGHT                               EQU     COLOR_BTNHIGHLIGHT
COLOR_3DHILIGHT                                 EQU     COLOR_BTNHIGHLIGHT
COLOR_BTNHILIGHT                                EQU     COLOR_BTNHIGHLIGHT

GW_HWNDFIRST                                    EQU     0
GW_HWNDLAST                                     EQU     1
GW_HWNDNEXT                                     EQU     2
GW_HWNDPREV                                     EQU     3
GW_OWNER                                        EQU     4
GW_CHILD                                        EQU     5

IF (NTDDI_VERSION EQ NTDDI_WINNT4)
    GW_MAX                                      EQU     5
ELSE
    GW_ENABLEDPOPUP                             EQU     6
    GW_MAX                                      EQU     6
ENDIF

MF_INSERT                                       EQU     000000000H
MF_CHANGE                                       EQU     000000080H
MF_APPEND                                       EQU     000000100H
MF_DELETE                                       EQU     000000200H
MF_REMOVE                                       EQU     000001000H
MF_BYCOMMAND                                    EQU     000000000H
MF_BYPOSITION                                   EQU     000000400H
MF_SEPARATOR                                    EQU     000000800H
MF_ENABLED                                      EQU     000000000H
MF_GRAYED                                       EQU     000000001H
MF_DISABLED                                     EQU     000000002H
MF_UNCHECKED                                    EQU     000000000H
MF_CHECKED                                      EQU     000000008H
MF_USECHECKBITMAPS                              EQU     000000200H
MF_STRING                                       EQU     000000000H
MF_BITMAP                                       EQU     000000004H
MF_OWNERDRAW                                    EQU     000000100H
MF_POPUP                                        EQU     000000010H
MF_MENUBARBREAK                                 EQU     000000020H
MF_MENUBREAK                                    EQU     000000040H
MF_UNHILITE                                     EQU     000000000H
MF_HILITE                                       EQU     000000080H
MF_DEFAULT                                      EQU     000001000H
MF_SYSMENU                                      EQU     000002000H
MF_HELP                                         EQU     000004000H
MF_RIGHTJUSTIFY                                 EQU     000004000H
MF_MOUSESELECT                                  EQU     000008000H
MF_END                                          EQU     000000080H

MFT_STRING                                      EQU     MF_STRING
MFT_BITMAP                                      EQU     MF_BITMAP
MFT_MENUBARBREAK                                EQU     MF_MENUBARBREAK
MFT_MENUBREAK                                   EQU     MF_MENUBREAK
MFT_OWNERDRAW                                   EQU     MF_OWNERDRAW
MFT_RADIOCHECK                                  EQU     000000200H
MFT_SEPARATOR                                   EQU     MF_SEPARATOR
MFT_RIGHTORDER                                  EQU     000002000H
MFT_RIGHTJUSTIFY                                EQU     MF_RIGHTJUSTIFY

MFS_GRAYED                                      EQU     000000003H
MFS_DISABLED                                    EQU     MFS_GRAYED
MFS_CHECKED                                     EQU     MF_CHECKED
MFS_HILITE                                      EQU     MF_HILITE
MFS_ENABLED                                     EQU     MF_ENABLED
MFS_UNCHECKED                                   EQU     MF_UNCHECKED
MFS_UNHILITE                                    EQU     MF_UNHILITE
MFS_DEFAULT                                     EQU     MF_DEFAULT
MFS_MASK                                        EQU     00000108BH
MFS_HOTTRACKDRAWN                               EQU     010000000H
MFS_CACHEDBMP                                   EQU     020000000H
MFS_BOTTOMGAPDROP                               EQU     040000000H
MFS_TOPGAPDROP                                  EQU     080000000H
MFS_GAPDROP                                     EQU     0C0000000H

SC_SIZE                                         EQU     0F000H
SC_MOVE                                         EQU     0F010H
SC_MINIMIZE                                     EQU     0F020H
SC_MAXIMIZE                                     EQU     0F030H
SC_NEXTWINDOW                                   EQU     0F040H
SC_PREVWINDOW                                   EQU     0F050H
SC_CLOSE                                        EQU     0F060H
SC_VSCROLL                                      EQU     0F070H
SC_HSCROLL                                      EQU     0F080H
SC_MOUSEMENU                                    EQU     0F090H
SC_KEYMENU                                      EQU     0F100H
SC_ARRANGE                                      EQU     0F110H
SC_RESTORE                                      EQU     0F120H
SC_TASKLIST                                     EQU     0F130H
SC_SCREENSAVE                                   EQU     0F140H
SC_HOTKEY                                       EQU     0F150H
SC_DEFAULT                                      EQU     0F160H
SC_MONITORPOWER                                 EQU     0F170H
SC_CONTEXTHELP                                  EQU     0F180H
SC_SEPARATOR                                    EQU     0F00FH

SCF_ISSECURE                                    EQU     000000001H

SC_ICON                                         EQU     SC_MINIMIZE
SC_ZOOM                                         EQU     SC_MAXIMIZE

IDC_ARROW                                       EQU     32512
IDC_IBEAM                                       EQU     32513
IDC_WAIT                                        EQU     32514
IDC_CROSS                                       EQU     32515
IDC_UPARROW                                     EQU     32516
IDC_SIZE                                        EQU     32640
IDC_ICON                                        EQU     32641
IDC_SIZENWSE                                    EQU     32642
IDC_SIZENESW                                    EQU     32643
IDC_SIZEWE                                      EQU     32644
IDC_SIZENS                                      EQU     32645
IDC_SIZEALL                                     EQU     32646
IDC_NO                                          EQU     32648
IDC_HAND                                        EQU     32649
IDC_APPSTARTING                                 EQU     32650
IDC_HELP                                        EQU     32651

IMAGE_BITMAP                                    EQU     0
IMAGE_ICON                                      EQU     1
IMAGE_CURSOR                                    EQU     2
IMAGE_ENHMETAFILE                               EQU     3

LR_DEFAULTCOLOR                                 EQU     00000H
LR_MONOCHROME                                   EQU     00001H
LR_COLOR                                        EQU     00002H
LR_COPYRETURNORG                                EQU     00004H
LR_COPYDELETEORG                                EQU     00008H
LR_LOADFROMFILE                                 EQU     00010H
LR_LOADTRANSPARENT                              EQU     00020H
LR_DEFAULTSIZE                                  EQU     00040H
LR_VGACOLOR                                     EQU     00080H
LR_LOADMAP3DCOLORS                              EQU     01000H
LR_CREATEDIBSECTION                             EQU     02000H
LR_COPYFROMRESOURCE                             EQU     04000H
LR_SHARED                                       EQU     08000H

DI_MASK                                         EQU     00001H
DI_IMAGE                                        EQU     00002H
DI_NORMAL                                       EQU     00003H
DI_COMPAT                                       EQU     00004H
DI_DEFAULTSIZE                                  EQU     00008H
DI_NOMIRROR                                     EQU     00010H

RES_ICON                                        EQU     1
RES_CURSOR                                      EQU     2

OBM_CLOSE                                       EQU     32754
OBM_UPARROW                                     EQU     32753
OBM_DNARROW                                     EQU     32752
OBM_RGARROW                                     EQU     32751
OBM_LFARROW                                     EQU     32750
OBM_REDUCE                                      EQU     32749
OBM_ZOOM                                        EQU     32748
OBM_RESTORE                                     EQU     32747
OBM_REDUCED                                     EQU     32746
OBM_ZOOMD                                       EQU     32745
OBM_RESTORED                                    EQU     32744
OBM_UPARROWD                                    EQU     32743
OBM_DNARROWD                                    EQU     32742
OBM_RGARROWD                                    EQU     32741
OBM_LFARROWD                                    EQU     32740
OBM_MNARROW                                     EQU     32739
OBM_COMBO                                       EQU     32738
OBM_UPARROWI                                    EQU     32737
OBM_DNARROWI                                    EQU     32736
OBM_RGARROWI                                    EQU     32735
OBM_LFARROWI                                    EQU     32734

OBM_OLD_CLOSE                                   EQU     32767
OBM_SIZE                                        EQU     32766
OBM_OLD_UPARROW                                 EQU     32765
OBM_OLD_DNARROW                                 EQU     32764
OBM_OLD_RGARROW                                 EQU     32763
OBM_OLD_LFARROW                                 EQU     32762
OBM_BTSIZE                                      EQU     32761
OBM_CHECK                                       EQU     32760
OBM_CHECKBOXES                                  EQU     32759
OBM_BTNCORNERS                                  EQU     32758
OBM_OLD_REDUCE                                  EQU     32757
OBM_OLD_ZOOM                                    EQU     32756
OBM_OLD_RESTORE                                 EQU     32755

OCR_NORMAL                                      EQU     32512
OCR_IBEAM                                       EQU     32513
OCR_WAIT                                        EQU     32514
OCR_CROSS                                       EQU     32515
OCR_UP                                          EQU     32516
OCR_SIZE                                        EQU     32640
OCR_ICON                                        EQU     32641
OCR_SIZENWSE                                    EQU     32642
OCR_SIZENESW                                    EQU     32643
OCR_SIZEWE                                      EQU     32644
OCR_SIZENS                                      EQU     32645
OCR_SIZEALL                                     EQU     32646
OCR_ICOCUR                                      EQU     32647
OCR_NO                                          EQU     32648
OCR_HAND                                        EQU     32649
OCR_APPSTARTING                                 EQU     32650

OIC_SAMPLE                                      EQU     32512
OIC_HAND                                        EQU     32513
OIC_QUES                                        EQU     32514
OIC_BANG                                        EQU     32515
OIC_NOTE                                        EQU     32516
OIC_WINLOGO                                     EQU     32517
OIC_WARNING                                     EQU     OIC_BANG
OIC_ERROR                                       EQU     OIC_HAND
OIC_INFORMATION                                 EQU     OIC_NOTE
OIC_SHIELD                                      EQU     32518

ORD_LANGDRIVER                                  EQU     1

IDI_APPLICATION                                 EQU     32512
IDI_HAND                                        EQU     32513
IDI_QUESTION                                    EQU     32514
IDI_EXCLAMATION                                 EQU     32515
IDI_ASTERISK                                    EQU     32516
IDI_WINLOGO                                     EQU     32517
IDI_SHIELD                                      EQU     32518

IDI_WARNING                                     EQU     IDI_EXCLAMATION
IDI_ERROR                                       EQU     IDI_HAND
IDI_INFORMATION                                 EQU     IDI_ASTERISK

IDOK                                            EQU     1
IDCANCEL                                        EQU     2
IDABORT                                         EQU     3
IDRETRY                                         EQU     4
IDIGNORE                                        EQU     5
IDYES                                           EQU     6
IDNO                                            EQU     7
IDCLOSE                                         EQU     8
IDHELP                                          EQU     9
IDTRYAGAIN                                      EQU     10
IDCONTINUE                                      EQU     11
IDTIMEOUT                                       EQU     32000

ES_LEFT                                         EQU     00000H
ES_CENTER                                       EQU     00001H
ES_RIGHT                                        EQU     00002H
ES_MULTILINE                                    EQU     00004H
ES_UPPERCASE                                    EQU     00008H
ES_LOWERCASE                                    EQU     00010H
ES_PASSWORD                                     EQU     00020H
ES_AUTOVSCROLL                                  EQU     00040H
ES_AUTOHSCROLL                                  EQU     00080H
ES_NOHIDESEL                                    EQU     00100H
ES_OEMCONVERT                                   EQU     00400H
ES_READONLY                                     EQU     00800H
ES_WANTRETURN                                   EQU     01000H
ES_NUMBER                                       EQU     02000H

EN_SETFOCUS                                     EQU     00100H
EN_KILLFOCUS                                    EQU     00200H
EN_CHANGE                                       EQU     00300H
EN_UPDATE                                       EQU     00400H
EN_ERRSPACE                                     EQU     00500H
EN_MAXTEXT                                      EQU     00501H
EN_HSCROLL                                      EQU     00601H
EN_VSCROLL                                      EQU     00602H

EN_ALIGN_LTR_EC                                 EQU     00700H
EN_ALIGN_RTL_EC                                 EQU     00701H

EC_LEFTMARGIN                                   EQU     00001H
EC_RIGHTMARGIN                                  EQU     00002H
EC_USEFONTINFO                                  EQU     0FFFFH

EMSIS_COMPOSITIONSTRING                         EQU     00001H

EIMES_GETCOMPSTRATONCE                          EQU     00001H
EIMES_CANCELCOMPSTRINFOCUS                      EQU     00002H
EIMES_COMPLETECOMPSTRKILLFOCUS                  EQU     00004H

IFNDEF ECM_FIRST
    ECM_FIRST                                   EQU     01500H
ENDIF

EM_GETSEL                                       EQU     000B0H
EM_SETSEL                                       EQU     000B1H
EM_GETRECT                                      EQU     000B2H
EM_SETRECT                                      EQU     000B3H
EM_SETRECTNP                                    EQU     000B4H
EM_SCROLL                                       EQU     000B5H
EM_LINESCROLL                                   EQU     000B6H
EM_SCROLLCARET                                  EQU     000B7H
EM_GETMODIFY                                    EQU     000B8H
EM_SETMODIFY                                    EQU     000B9H
EM_GETLINECOUNT                                 EQU     000BAH
EM_LINEINDEX                                    EQU     000BBH
EM_SETHANDLE                                    EQU     000BCH
EM_GETHANDLE                                    EQU     000BDH
EM_GETTHUMB                                     EQU     000BEH
EM_LINELENGTH                                   EQU     000C1H
EM_REPLACESEL                                   EQU     000C2H
EM_SETFONT                                      EQU     000C3H
EM_GETLINE                                      EQU     000C4H
EM_LIMITTEXT                                    EQU     000C5H
EM_CANUNDO                                      EQU     000C6H
EM_UNDO                                         EQU     000C7H
EM_FMTLINES                                     EQU     000C8H
EM_LINEFROMCHAR                                 EQU     000C9H
EM_SETWORDBREAK                                 EQU     000CAH
EM_SETTABSTOPS                                  EQU     000CBH
EM_SETPASSWORDCHAR                              EQU     000CCH
EM_EMPTYUNDOBUFFER                              EQU     000CDH
EM_GETFIRSTVISIBLELINE                          EQU     000CEH
EM_SETREADONLY                                  EQU     000CFH
EM_SETWORDBREAKPROC                             EQU     000D0H
EM_GETWORDBREAKPROC                             EQU     000D1H
EM_GETPASSWORDCHAR                              EQU     000D2H
EM_SETMARGINS                                   EQU     000D3H
EM_GETMARGINS                                   EQU     000D4H
EM_SETLIMITTEXT                                 EQU     EM_LIMITTEXT
EM_GETLIMITTEXT                                 EQU     000D5H
EM_POSFROMCHAR                                  EQU     000D6H
EM_CHARFROMPOS                                  EQU     000D7H
EM_SETIMESTATUS                                 EQU     000D8H
EM_GETIMESTATUS                                 EQU     000D9H
EM_SETCUEBANNER                                 EQU     (ECM_FIRST + 1)

WB_LEFT                                         EQU     0
WB_RIGHT                                        EQU     1
WB_ISDELIMITER                                  EQU     2

BS_PUSHBUTTON                                   EQU     000000000H
BS_DEFPUSHBUTTON                                EQU     000000001H
BS_CHECKBOX                                     EQU     000000002H
BS_AUTOCHECKBOX                                 EQU     000000003H
BS_RADIOBUTTON                                  EQU     000000004H
BS_3STATE                                       EQU     000000005H
BS_AUTO3STATE                                   EQU     000000006H
BS_GROUPBOX                                     EQU     000000007H
BS_USERBUTTON                                   EQU     000000008H
BS_AUTORADIOBUTTON                              EQU     000000009H
BS_OWNERDRAW                                    EQU     00000000BH
BS_LEFTTEXT                                     EQU     000000020H
BS_TEXT                                         EQU     000000000H
BS_ICON                                         EQU     000000040H
BS_BITMAP                                       EQU     000000080H
BS_LEFT                                         EQU     000000100H
BS_RIGHT                                        EQU     000000200H
BS_CENTER                                       EQU     000000300H
BS_TOP                                          EQU     000000400H
BS_BOTTOM                                       EQU     000000800H
BS_VCENTER                                      EQU     000000C00H
BS_PUSHLIKE                                     EQU     000001000H
BS_MULTILINE                                    EQU     000002000H
BS_NOTIFY                                       EQU     000004000H
BS_FLAT                                         EQU     000008000H
BS_RIGHTBUTTON                                  EQU     BS_LEFTTEXT

BN_CLICKED                                      EQU     0
BN_PAINT                                        EQU     1
BN_HILITE                                       EQU     2
BN_UNHILITE                                     EQU     3
BN_DISABLE                                      EQU     4
BN_DOUBLECLICKED                                EQU     5
BN_PUSHED                                       EQU     BN_HILITE
BN_UNPUSHED                                     EQU     BN_UNHILITE
BN_DBLCLK                                       EQU     BN_DOUBLECLICKED
BN_SETFOCUS                                     EQU     6
BN_KILLFOCUS                                    EQU     7

BM_GETCHECK                                     EQU     000F0H
BM_SETCHECK                                     EQU     000F1H
BM_GETSTATE                                     EQU     000F2H
BM_SETSTATE                                     EQU     000F3H
BM_SETSTYLE                                     EQU     000F4H
BM_CLICK                                        EQU     000F5H
BM_GETIMAGE                                     EQU     000F6H
BM_SETIMAGE                                     EQU     000F7H
BM_SETDONTCLICK                                 EQU     000F8H

BST_UNCHECKED                                   EQU     00000H
BST_CHECKED                                     EQU     00001H
BST_INDETERMINATE                               EQU     00002H
BST_PUSHED                                      EQU     00004H
BST_FOCUS                                       EQU     00008H

SS_LEFT                                         EQU     000000000H
SS_CENTER                                       EQU     000000001H
SS_RIGHT                                        EQU     000000002H
SS_ICON                                         EQU     000000003H
SS_BLACKRECT                                    EQU     000000004H
SS_GRAYRECT                                     EQU     000000005H
SS_WHITERECT                                    EQU     000000006H
SS_BLACKFRAME                                   EQU     000000007H
SS_GRAYFRAME                                    EQU     000000008H
SS_WHITEFRAME                                   EQU     000000009H
SS_USERITEM                                     EQU     00000000AH
SS_SIMPLE                                       EQU     00000000BH
SS_LEFTNOWORDWRAP                               EQU     00000000CH
SS_OWNERDRAW                                    EQU     00000000DH
SS_BITMAP                                       EQU     00000000EH
SS_ENHMETAFILE                                  EQU     00000000FH
SS_ETCHEDHORZ                                   EQU     000000010H
SS_ETCHEDVERT                                   EQU     000000011H
SS_ETCHEDFRAME                                  EQU     000000012H
SS_TYPEMASK                                     EQU     00000001FH
SS_REALSIZECONTROL                              EQU     000000040H
SS_NOPREFIX                                     EQU     000000080H
SS_NOTIFY                                       EQU     000000100H
SS_CENTERIMAGE                                  EQU     000000200H
SS_RIGHTJUST                                    EQU     000000400H
SS_REALSIZEIMAGE                                EQU     000000800H
SS_SUNKEN                                       EQU     000001000H
SS_ENDELLIPSIS                                  EQU     000004000H
SS_PATHELLIPSIS                                 EQU     000008000H
SS_WORDELLIPSIS                                 EQU     00000C000H
SS_ELLIPSISMASK                                 EQU     00000C000H

STM_SETICON                                     EQU     00170H
STM_GETICON                                     EQU     00171H
STM_SETIMAGE                                    EQU     00172H
STM_GETIMAGE                                    EQU     00173H

STN_CLICKED                                     EQU     0
STN_DBLCLK                                      EQU     1
STN_ENABLE                                      EQU     2
STN_DISABLE                                     EQU     3
STM_MSGMAX                                      EQU     00174H

WC_DIALOG                                       EQU     08002H

DWL_MSGRESULT                                   EQU     0
DWL_DLGPROC                                     EQU     4
DWL_USER                                        EQU     8

DWLP_MSGRESULT                                  EQU     0

DDL_READWRITE                                   EQU     00000H
DDL_READONLY                                    EQU     00001H
DDL_HIDDEN                                      EQU     00002H
DDL_SYSTEM                                      EQU     00004H
DDL_DIRECTORY                                   EQU     00010H
DDL_ARCHIVE                                     EQU     00020H

DDL_POSTMSGS                                    EQU     02000H
DDL_DRIVES                                      EQU     04000H
DDL_EXCLUSIVE                                   EQU     08000H

DS_ABSALIGN                                     EQU     001H
DS_SYSMODAL                                     EQU     002H
DS_LOCALEDIT                                    EQU     020H
DS_SETFONT                                      EQU     040H
DS_MODALFRAME                                   EQU     080H
DS_NOIDLEMSG                                    EQU     0100H
DS_SETFOREGROUND                                EQU     0200H

DS_3DLOOK                                       EQU     00004H
DS_FIXEDSYS                                     EQU     00008H
DS_NOFAILCREATE                                 EQU     00010H
DS_CONTROL                                      EQU     00400H
DS_CENTER                                       EQU     00800H
DS_CENTERMOUSE                                  EQU     01000H
DS_CONTEXTHELP                                  EQU     02000H

DS_SHELLFONT                                    EQU     (DS_SETFONT OR DS_FIXEDSYS)

DM_GETDEFID                                     EQU     (WM_USER + 0)
DM_SETDEFID                                     EQU     (WM_USER + 1)
DM_REPOSITION                                   EQU     (WM_USER + 2)

DC_HASDEFID                                     EQU     0534BH

DLGC_WANTARROWS                                 EQU     00001H
DLGC_WANTTAB                                    EQU     00002H
DLGC_WANTALLKEYS                                EQU     00004H
DLGC_WANTMESSAGE                                EQU     00004H
DLGC_HASSETSEL                                  EQU     00008H
DLGC_DEFPUSHBUTTON                              EQU     00010H
DLGC_UNDEFPUSHBUTTON                            EQU     00020H
DLGC_RADIOBUTTON                                EQU     00040H
DLGC_WANTCHARS                                  EQU     00080H
DLGC_STATIC                                     EQU     00100H
DLGC_BUTTON                                     EQU     02000H

LB_CTLCODE                                      EQU     0

LB_OKAY                                         EQU     0
LB_ERR                                          EQU     (-1)
LB_ERRSPACE                                     EQU     (-2)

LBN_ERRSPACE                                    EQU     (-2)
LBN_SELCHANGE                                   EQU     1
LBN_DBLCLK                                      EQU     2
LBN_SELCANCEL                                   EQU     3
LBN_SETFOCUS                                    EQU     4
LBN_KILLFOCUS                                   EQU     5

LB_ADDSTRING                                    EQU     00180H
LB_INSERTSTRING                                 EQU     00181H
LB_DELETESTRING                                 EQU     00182H
LB_SELITEMRANGEEX                               EQU     00183H
LB_RESETCONTENT                                 EQU     00184H
LB_SETSEL                                       EQU     00185H
LB_SETCURSEL                                    EQU     00186H
LB_GETSEL                                       EQU     00187H
LB_GETCURSEL                                    EQU     00188H
LB_GETTEXT                                      EQU     00189H
LB_GETTEXTLEN                                   EQU     0018AH
LB_GETCOUNT                                     EQU     0018BH
LB_SELECTSTRING                                 EQU     0018CH
LB_DIR                                          EQU     0018DH
LB_GETTOPINDEX                                  EQU     0018EH
LB_FINDSTRING                                   EQU     0018FH
LB_GETSELCOUNT                                  EQU     00190H
LB_GETSELITEMS                                  EQU     00191H
LB_SETTABSTOPS                                  EQU     00192H
LB_GETHORIZONTALEXTENT                          EQU     00193H
LB_SETHORIZONTALEXTENT                          EQU     00194H
LB_SETCOLUMNWIDTH                               EQU     00195H
LB_ADDFILE                                      EQU     00196H
LB_SETTOPINDEX                                  EQU     00197H
LB_GETITEMRECT                                  EQU     00198H
LB_GETITEMDATA                                  EQU     00199H
LB_SETITEMDATA                                  EQU     0019AH
LB_SELITEMRANGE                                 EQU     0019BH
LB_SETANCHORINDEX                               EQU     0019CH
LB_GETANCHORINDEX                               EQU     0019DH
LB_SETCARETINDEX                                EQU     0019EH
LB_GETCARETINDEX                                EQU     0019FH
LB_SETITEMHEIGHT                                EQU     001A0H
LB_GETITEMHEIGHT                                EQU     001A1H
LB_FINDSTRINGEXACT                              EQU     001A2H
LBCB_CARETON                                    EQU     001A3H
LBCB_CARETOFF                                   EQU     001A4H
LB_SETLOCALE                                    EQU     001A5H
LB_GETLOCALE                                    EQU     001A6H
LB_SETCOUNT                                     EQU     001A7H
LB_INITSTORAGE                                  EQU     001A8H
LB_ITEMFROMPOINT                                EQU     001A9H
LB_INSERTSTRINGUPPER                            EQU     001AAH
LB_INSERTSTRINGLOWER                            EQU     001ABH
LB_ADDSTRINGUPPER                               EQU     001ACH
LB_ADDSTRINGLOWER                               EQU     001ADH
LBCB_STARTTRACK                                 EQU     001AEH
LBCB_ENDTRACK                                   EQU     001AFH
LB_MULTIPLEADDSTRING                            EQU     001B1H
LB_GETLISTBOXINFO                               EQU     001B2H
LB_MSGMAX                                       EQU     001B3H

LBS_NOTIFY                                      EQU     00001H
LBS_SORT                                        EQU     00002H
LBS_NOREDRAW                                    EQU     00004H
LBS_MULTIPLESEL                                 EQU     00008H
LBS_OWNERDRAWFIXED                              EQU     00010H
LBS_OWNERDRAWVARIABLE                           EQU     00020H
LBS_HASSTRINGS                                  EQU     00040H
LBS_USETABSTOPS                                 EQU     00080H
LBS_NOINTEGRALHEIGHT                            EQU     00100H
LBS_MULTICOLUMN                                 EQU     00200H
LBS_WANTKEYBOARDINPUT                           EQU     00400H
LBS_EXTENDEDSEL                                 EQU     00800H
LBS_DISABLENOSCROLL                             EQU     01000H
LBS_NODATA                                      EQU     02000H
LBS_NOSEL                                       EQU     04000H
LBS_STANDARD                                    EQU     (LBS_NOTIFY OR LBS_SORT OR WS_VSCROLL OR WS_BORDER)

CB_OKAY                                         EQU     0
CB_ERR                                          EQU     (-1)
CB_ERRSPACE                                     EQU     (-2)

CBN_ERRSPACE                                    EQU     (-1)
CBN_SELCHANGE                                   EQU     1
CBN_DBLCLK                                      EQU     2
CBN_SETFOCUS                                    EQU     3
CBN_KILLFOCUS                                   EQU     4
CBN_EDITCHANGE                                  EQU     5
CBN_EDITUPDATE                                  EQU     6
CBN_DROPDOWN                                    EQU     7
CBN_CLOSEUP                                     EQU     8
CBN_SELENDOK                                    EQU     9
CBN_SELENDCANCEL                                EQU     10

CBS_SIMPLE                                      EQU     00001H
CBS_DROPDOWN                                    EQU     00002H
CBS_DROPDOWNLIST                                EQU     00003H
CBS_OWNERDRAWFIXED                              EQU     00010H
CBS_OWNERDRAWVARIABLE                           EQU     00020H
CBS_AUTOHSCROLL                                 EQU     00040H
CBS_OEMCONVERT                                  EQU     00080H
CBS_SORT                                        EQU     00100H
CBS_HASSTRINGS                                  EQU     00200H
CBS_NOINTEGRALHEIGHT                            EQU     00400H
CBS_DISABLENOSCROLL                             EQU     00800H
CBS_UPPERCASE                                   EQU     02000H
CBS_LOWERCASE                                   EQU     04000H

CB_GETEDITSEL                                   EQU     00140H
CB_LIMITTEXT                                    EQU     00141H
CB_SETEDITSEL                                   EQU     00142H
CB_ADDSTRING                                    EQU     00143H
CB_DELETESTRING                                 EQU     00144H
CB_DIR                                          EQU     00145H
CB_GETCOUNT                                     EQU     00146H
CB_GETCURSEL                                    EQU     00147H
CB_GETLBTEXT                                    EQU     00148H
CB_GETLBTEXTLEN                                 EQU     00149H
CB_INSERTSTRING                                 EQU     0014AH
CB_RESETCONTENT                                 EQU     0014BH
CB_FINDSTRING                                   EQU     0014CH
CB_SELECTSTRING                                 EQU     0014DH
CB_SETCURSEL                                    EQU     0014EH
CB_SHOWDROPDOWN                                 EQU     0014FH
CB_GETITEMDATA                                  EQU     00150H
CB_SETITEMDATA                                  EQU     00151H
CB_GETDROPPEDCONTROLRECT                        EQU     00152H
CB_SETITEMHEIGHT                                EQU     00153H
CB_GETITEMHEIGHT                                EQU     00154H
CB_SETEXTENDEDUI                                EQU     00155H
CB_GETEXTENDEDUI                                EQU     00156H
CB_GETDROPPEDSTATE                              EQU     00157H
CB_FINDSTRINGEXACT                              EQU     00158H
CB_SETLOCALE                                    EQU     00159H
CB_GETLOCALE                                    EQU     0015AH
CB_GETTOPINDEX                                  EQU     0015BH
CB_SETTOPINDEX                                  EQU     0015CH
CB_GETHORIZONTALEXTENT                          EQU     0015DH
CB_SETHORIZONTALEXTENT                          EQU     0015EH
CB_GETDROPPEDWIDTH                              EQU     0015FH
CB_SETDROPPEDWIDTH                              EQU     00160H
CB_INITSTORAGE                                  EQU     00161H
CB_MULTIPLEADDSTRING                            EQU     00163H
CB_GETCOMBOBOXINFO                              EQU     00164H
CB_MSGMAX                                       EQU     00165H

SBS_HORZ                                        EQU     00000H
SBS_VERT                                        EQU     00001H
SBS_TOPALIGN                                    EQU     00002H
SBS_LEFTALIGN                                   EQU     00002H
SBS_BOTTOMALIGN                                 EQU     00004H
SBS_RIGHTALIGN                                  EQU     00004H
SBS_SIZEBOXTOPLEFTALIGN                         EQU     00002H
SBS_SIZEBOXBOTTOMRIGHTALIGN                     EQU     00004H
SBS_SIZEBOX                                     EQU     00008H
SBS_SIZEGRIP                                    EQU     00010H

SBM_SETPOS                                      EQU     000E0H
SBM_GETPOS                                      EQU     000E1H
SBM_SETRANGE                                    EQU     000E2H
SBM_SETRANGEREDRAW                              EQU     000E6H
SBM_GETRANGE                                    EQU     000E3H
SBM_ENABLE_ARROWS                               EQU     000E4H
SBM_SETSCROLLINFO                               EQU     000E9H
SBM_GETSCROLLINFO                               EQU     000EAH
SBM_GETSCROLLBARINFO                            EQU     000EBH

SIF_RANGE                                       EQU     00001H
SIF_PAGE                                        EQU     00002H
SIF_POS                                         EQU     00004H
SIF_DISABLENOSCROLL                             EQU     00008H
SIF_TRACKPOS                                    EQU     00010H
SIF_ALL                                         EQU     (SIF_RANGE OR SIF_PAGE OR SIF_POS OR SIF_TRACKPOS)

MDIS_ALLCHILDSTYLES                             EQU     00001H

MDITILE_VERTICAL                                EQU     00000H
MDITILE_HORIZONTAL                              EQU     00001H
MDITILE_SKIPDISABLED                            EQU     00002H
MDITILE_ZORDER                                  EQU     00004H

HELP_CONTEXT                                    EQU     00001H
HELP_QUIT                                       EQU     00002H
HELP_INDEX                                      EQU     00003H
HELP_CONTENTS                                   EQU     00003H
HELP_HELPONHELP                                 EQU     00004H
HELP_SETINDEX                                   EQU     00005H
HELP_SETCONTENTS                                EQU     00005H
HELP_CONTEXTPOPUP                               EQU     00008H
HELP_FORCEFILE                                  EQU     00009H
HELP_KEY                                        EQU     00101H
HELP_COMMAND                                    EQU     00102H
HELP_PARTIALKEY                                 EQU     00105H
HELP_MULTIKEY                                   EQU     00201H
HELP_SETWINPOS                                  EQU     00203H
HELP_CONTEXTMENU                                EQU     0000AH
HELP_FINDER                                     EQU     0000BH
HELP_WM_HELP                                    EQU     0000CH
HELP_SETPOPUP_POS                               EQU     0000DH

HELP_TCARD                                      EQU     08000H
HELP_TCARD_DATA                                 EQU     00010H
HELP_TCARD_OTHER_CALLER                         EQU     00011H

IDH_NO_HELP                                     EQU     28440
IDH_MISSING_CONTEXT                             EQU     28441
IDH_GENERIC_HELP_BUTTON                         EQU     28442
IDH_OK                                          EQU     28443
IDH_CANCEL                                      EQU     28444
IDH_HELP                                        EQU     28445

GR_GDIOBJECTS                                   EQU     0
GR_USEROBJECTS                                  EQU     1
GR_GDIOBJECTS_PEAK                              EQU     2
GR_USEROBJECTS_PEAK                             EQU     4

GR_GLOBAL                                       EQU     (-2)

SPI_GETBEEP                                     EQU     1
SPI_SETBEEP                                     EQU     2
SPI_GETMOUSE                                    EQU     3
SPI_SETMOUSE                                    EQU     4
SPI_GETBORDER                                   EQU     5
SPI_SETBORDER                                   EQU     6
SPI_GETKEYBOARDSPEED                            EQU     10
SPI_SETKEYBOARDSPEED                            EQU     11
SPI_LANGDRIVER                                  EQU     12
SPI_ICONHORIZONTALSPACING                       EQU     13
SPI_GETSCREENSAVETIMEOUT                        EQU     14
SPI_SETSCREENSAVETIMEOUT                        EQU     15
SPI_GETSCREENSAVEACTIVE                         EQU     16
SPI_SETSCREENSAVEACTIVE                         EQU     17
SPI_GETGRIDGRANULARITY                          EQU     18
SPI_SETGRIDGRANULARITY                          EQU     19
SPI_SETDESKWALLPAPER                            EQU     20
SPI_SETDESKPATTERN                              EQU     21
SPI_GETKEYBOARDDELAY                            EQU     22
SPI_SETKEYBOARDDELAY                            EQU     23
SPI_ICONVERTICALSPACING                         EQU     24
SPI_GETICONTITLEWRAP                            EQU     25
SPI_SETICONTITLEWRAP                            EQU     26
SPI_GETMENUDROPALIGNMENT                        EQU     27
SPI_SETMENUDROPALIGNMENT                        EQU     28
SPI_SETDOUBLECLKWIDTH                           EQU     29
SPI_SETDOUBLECLKHEIGHT                          EQU     30
SPI_GETICONTITLELOGFONT                         EQU     31
SPI_SETDOUBLECLICKTIME                          EQU     32
SPI_SETMOUSEBUTTONSWAP                          EQU     33
SPI_SETICONTITLELOGFONT                         EQU     34
SPI_GETFASTTASKSWITCH                           EQU     35
SPI_SETFASTTASKSWITCH                           EQU     36
SPI_SETDRAGFULLWINDOWS                          EQU     37
SPI_GETDRAGFULLWINDOWS                          EQU     38
SPI_GETNONCLIENTMETRICS                         EQU     41
SPI_SETNONCLIENTMETRICS                         EQU     42
SPI_GETMINIMIZEDMETRICS                         EQU     43
SPI_SETMINIMIZEDMETRICS                         EQU     44
SPI_GETICONMETRICS                              EQU     45
SPI_SETICONMETRICS                              EQU     46
SPI_SETWORKAREA                                 EQU     47
SPI_GETWORKAREA                                 EQU     48
SPI_SETPENWINDOWS                               EQU     49
SPI_GETFILTERKEYS                               EQU     50
SPI_SETFILTERKEYS                               EQU     51
SPI_GETTOGGLEKEYS                               EQU     52
SPI_SETTOGGLEKEYS                               EQU     53
SPI_GETMOUSEKEYS                                EQU     54
SPI_SETMOUSEKEYS                                EQU     55
SPI_GETSHOWSOUNDS                               EQU     56
SPI_SETSHOWSOUNDS                               EQU     57
SPI_GETSTICKYKEYS                               EQU     58
SPI_SETSTICKYKEYS                               EQU     59
SPI_GETACCESSTIMEOUT                            EQU     60
SPI_SETACCESSTIMEOUT                            EQU     61
SPI_GETSERIALKEYS                               EQU     62
SPI_SETSERIALKEYS                               EQU     63
SPI_GETSOUNDSENTRY                              EQU     64
SPI_SETSOUNDSENTRY                              EQU     65
SPI_GETHIGHCONTRAST                             EQU     66
SPI_SETHIGHCONTRAST                             EQU     67
SPI_GETKEYBOARDPREF                             EQU     68
SPI_SETKEYBOARDPREF                             EQU     69
SPI_GETSCREENREADER                             EQU     70
SPI_SETSCREENREADER                             EQU     71
SPI_GETANIMATION                                EQU     72
SPI_SETANIMATION                                EQU     73
SPI_GETFONTSMOOTHING                            EQU     74
SPI_SETFONTSMOOTHING                            EQU     75
SPI_SETDRAGWIDTH                                EQU     76
SPI_SETDRAGHEIGHT                               EQU     77
SPI_SETHANDHELD                                 EQU     78
SPI_GETLOWPOWERTIMEOUT                          EQU     79
SPI_GETPOWEROFFTIMEOUT                          EQU     80
SPI_SETLOWPOWERTIMEOUT                          EQU     81
SPI_SETPOWEROFFTIMEOUT                          EQU     82
SPI_GETLOWPOWERACTIVE                           EQU     83
SPI_GETPOWEROFFACTIVE                           EQU     84
SPI_SETLOWPOWERACTIVE                           EQU     85
SPI_SETPOWEROFFACTIVE                           EQU     86
SPI_SETCURSORS                                  EQU     87
SPI_SETICONS                                    EQU     88
SPI_GETDEFAULTINPUTLANG                         EQU     89
SPI_SETDEFAULTINPUTLANG                         EQU     90
SPI_SETLANGTOGGLE                               EQU     91
SPI_GETWINDOWSEXTENSION                         EQU     92
SPI_SETMOUSETRAILS                              EQU     93
SPI_GETMOUSETRAILS                              EQU     94
SPI_GETSNAPTODEFBUTTON                          EQU     95
SPI_SETSNAPTODEFBUTTON                          EQU     96
SPI_SETSCREENSAVERRUNNING                       EQU     97
SPI_SCREENSAVERRUNNING                          EQU     SPI_SETSCREENSAVERRUNNING
SPI_GETMOUSEHOVERWIDTH                          EQU     98
SPI_SETMOUSEHOVERWIDTH                          EQU     99
SPI_GETMOUSEHOVERHEIGHT                         EQU     100
SPI_SETMOUSEHOVERHEIGHT                         EQU     101
SPI_GETMOUSEHOVERTIME                           EQU     102
SPI_SETMOUSEHOVERTIME                           EQU     103
SPI_GETWHEELSCROLLLINES                         EQU     104
SPI_SETWHEELSCROLLLINES                         EQU     105
SPI_GETMENUSHOWDELAY                            EQU     106
SPI_SETMENUSHOWDELAY                            EQU     107
SPI_GETSHOWIMEUI                                EQU     110
SPI_SETSHOWIMEUI                                EQU     111
SPI_GETMOUSESPEED                               EQU     112
SPI_SETMOUSESPEED                               EQU     113
SPI_GETSCREENSAVERRUNNING                       EQU     114
SPI_GETDESKWALLPAPER                            EQU     115
SPI_GETACTIVEWINDOWTRACKING                     EQU     01000H
SPI_SETACTIVEWINDOWTRACKING                     EQU     01001H
SPI_GETMENUANIMATION                            EQU     01002H
SPI_SETMENUANIMATION                            EQU     01003H
SPI_GETCOMBOBOXANIMATION                        EQU     01004H
SPI_SETCOMBOBOXANIMATION                        EQU     01005H
SPI_GETLISTBOXSMOOTHSCROLLING                   EQU     01006H
SPI_SETLISTBOXSMOOTHSCROLLING                   EQU     01007H
SPI_GETGRADIENTCAPTIONS                         EQU     01008H
SPI_SETGRADIENTCAPTIONS                         EQU     01009H
SPI_GETKEYBOARDCUES                             EQU     0100AH
SPI_SETKEYBOARDCUES                             EQU     0100BH
SPI_GETMENUUNDERLINES                           EQU     SPI_GETKEYBOARDCUES
SPI_SETMENUUNDERLINES                           EQU     SPI_SETKEYBOARDCUES
SPI_GETACTIVEWNDTRKZORDER                       EQU     0100CH
SPI_SETACTIVEWNDTRKZORDER                       EQU     0100DH
SPI_GETHOTTRACKING                              EQU     0100EH
SPI_SETHOTTRACKING                              EQU     0100FH
SPI_GETMENUFADE                                 EQU     01012H
SPI_SETMENUFADE                                 EQU     01013H
SPI_GETSELECTIONFADE                            EQU     01014H
SPI_SETSELECTIONFADE                            EQU     01015H
SPI_GETTOOLTIPANIMATION                         EQU     01016H
SPI_SETTOOLTIPANIMATION                         EQU     01017H
SPI_GETTOOLTIPFADE                              EQU     01018H
SPI_SETTOOLTIPFADE                              EQU     01019H
SPI_GETCURSORSHADOW                             EQU     0101AH
SPI_SETCURSORSHADOW                             EQU     0101BH
SPI_GETMOUSESONAR                               EQU     0101CH
SPI_SETMOUSESONAR                               EQU     0101DH
SPI_GETMOUSECLICKLOCK                           EQU     0101EH
SPI_SETMOUSECLICKLOCK                           EQU     0101FH
SPI_GETMOUSEVANISH                              EQU     01020H
SPI_SETMOUSEVANISH                              EQU     01021H
SPI_GETFLATMENU                                 EQU     01022H
SPI_SETFLATMENU                                 EQU     01023H
SPI_GETDROPSHADOW                               EQU     01024H
SPI_SETDROPSHADOW                               EQU     01025H
SPI_GETBLOCKSENDINPUTRESETS                     EQU     01026H
SPI_SETBLOCKSENDINPUTRESETS                     EQU     01027H
SPI_GETUIEFFECTS                                EQU     0103EH
SPI_SETUIEFFECTS                                EQU     0103FH
SPI_GETDISABLEOVERLAPPEDCONTENT                 EQU     01040H
SPI_SETDISABLEOVERLAPPEDCONTENT                 EQU     01041H
SPI_GETCLIENTAREAANIMATION                      EQU     01042H
SPI_SETCLIENTAREAANIMATION                      EQU     01043H
SPI_GETCLEARTYPE                                EQU     01048H
SPI_SETCLEARTYPE                                EQU     01049H
SPI_GETSPEECHRECOGNITION                        EQU     0104AH
SPI_SETSPEECHRECOGNITION                        EQU     0104BH
SPI_GETCARETBROWSING                            EQU     0104CH
SPI_SETCARETBROWSING                            EQU     0104DH
SPI_GETTHREADLOCALINPUTSETTINGS                 EQU     0104EH
SPI_SETTHREADLOCALINPUTSETTINGS                 EQU     0104FH
SPI_GETSYSTEMLANGUAGEBAR                        EQU     01050H
SPI_SETSYSTEMLANGUAGEBAR                        EQU     01051H
SPI_GETFOREGROUNDLOCKTIMEOUT                    EQU     02000H
SPI_SETFOREGROUNDLOCKTIMEOUT                    EQU     02001H
SPI_GETACTIVEWNDTRKTIMEOUT                      EQU     02002H
SPI_SETACTIVEWNDTRKTIMEOUT                      EQU     02003H
SPI_GETFOREGROUNDFLASHCOUNT                     EQU     02004H
SPI_SETFOREGROUNDFLASHCOUNT                     EQU     02005H
SPI_GETCARETWIDTH                               EQU     02006H
SPI_SETCARETWIDTH                               EQU     02007H
SPI_GETMOUSECLICKLOCKTIME                       EQU     02008H
SPI_SETMOUSECLICKLOCKTIME                       EQU     02009H
SPI_GETFONTSMOOTHINGTYPE                        EQU     0200AH
SPI_SETFONTSMOOTHINGTYPE                        EQU     0200BH
SPI_GETFONTSMOOTHINGCONTRAST                    EQU     0200CH
SPI_SETFONTSMOOTHINGCONTRAST                    EQU     0200DH
SPI_GETFOCUSBORDERWIDTH                         EQU     0200EH
SPI_SETFOCUSBORDERWIDTH                         EQU     0200FH
SPI_GETFOCUSBORDERHEIGHT                        EQU     02010H
SPI_SETFOCUSBORDERHEIGHT                        EQU     02011H
SPI_GETFONTSMOOTHINGORIENTATION                 EQU     02012H
SPI_SETFONTSMOOTHINGORIENTATION                 EQU     02013H
SPI_GETMINIMUMHITRADIUS                         EQU     02014H
SPI_SETMINIMUMHITRADIUS                         EQU     02015H
SPI_GETMESSAGEDURATION                          EQU     02016H
SPI_SETMESSAGEDURATION                          EQU     02017H
SPI_GETCONTACTVISUALIZATION                     EQU     02018H
SPI_SETCONTACTVISUALIZATION                     EQU     02019H

SPIF_UPDATEINIFILE                              EQU     00001H
SPIF_SENDWININICHANGE                           EQU     00002H
SPIF_SENDCHANGE                                 EQU     SPIF_SENDWININICHANGE

MAX_TOUCH_PREDICTION_FILTER_TAPS                EQU     3

METRICS_USEDEFAULT                              EQU     (-1)

ARW_BOTTOMLEFT                                  EQU     00000H
ARW_BOTTOMRIGHT                                 EQU     00001H
ARW_TOPLEFT                                     EQU     00002H
ARW_TOPRIGHT                                    EQU     00003H
ARW_STARTMASK                                   EQU     00003H
ARW_STARTRIGHT                                  EQU     00001H
ARW_STARTTOP                                    EQU     00002H

ARW_LEFT                                        EQU     00000H
ARW_RIGHT                                       EQU     00000H
ARW_UP                                          EQU     00004H
ARW_DOWN                                        EQU     00004H
ARW_HIDE                                        EQU     00008H

SERKF_SERIALKEYSON                              EQU     000000001H
SERKF_AVAILABLE                                 EQU     000000002H
SERKF_INDICATOR                                 EQU     000000004H

HCF_HIGHCONTRASTON                              EQU     000000001H
HCF_AVAILABLE                                   EQU     000000002H
HCF_HOTKEYACTIVE                                EQU     000000004H
HCF_CONFIRMHOTKEY                               EQU     000000008H
HCF_HOTKEYSOUND                                 EQU     000000010H
HCF_INDICATOR                                   EQU     000000020H
HCF_HOTKEYAVAILABLE                             EQU     000000040H

CDS_UPDATEREGISTRY                              EQU     000000001H
CDS_TEST                                        EQU     000000002H
CDS_FULLSCREEN                                  EQU     000000004H
CDS_GLOBAL                                      EQU     000000008H
CDS_SET_PRIMARY                                 EQU     000000010H
CDS_VIDEOPARAMETERS                             EQU     000000020H
CDS_ENABLE_UNSAFE_MODES                         EQU     000000100H
CDS_DISABLE_UNSAFE_MODES                        EQU     000000200H

CDS_RESET                                       EQU     040000000H
CDS_SETRECT                                     EQU     020000000H
CDS_NORESET                                     EQU     010000000H

DISP_CHANGE_SUCCESSFUL                          EQU     0
DISP_CHANGE_RESTART                             EQU     1
DISP_CHANGE_FAILED                              EQU     (-1)
DISP_CHANGE_BADMODE                             EQU     (-2)
DISP_CHANGE_NOTUPDATED                          EQU     (-3)
DISP_CHANGE_BADFLAGS                            EQU     (-4)
DISP_CHANGE_BADPARAM                            EQU     (-5)
DISP_CHANGE_BADDUALVIEW                         EQU     (-6)

ENUM_CURRENT_SETTINGS                           EQU     (-1)
ENUM_REGISTRY_SETTINGS                          EQU     (-2)

FKF_FILTERKEYSON                                EQU     000000001H
FKF_AVAILABLE                                   EQU     000000002H
FKF_HOTKEYACTIVE                                EQU     000000004H
FKF_CONFIRMHOTKEY                               EQU     000000008H
FKF_HOTKEYSOUND                                 EQU     000000010H
FKF_INDICATOR                                   EQU     000000020H
FKF_CLICKON                                     EQU     000000040H

SKF_STICKYKEYSON                                EQU     000000001H
SKF_AVAILABLE                                   EQU     000000002H
SKF_HOTKEYACTIVE                                EQU     000000004H
SKF_CONFIRMHOTKEY                               EQU     000000008H
SKF_HOTKEYSOUND                                 EQU     000000010H
SKF_INDICATOR                                   EQU     000000020H
SKF_AUDIBLEFEEDBACK                             EQU     000000040H
SKF_TRISTATE                                    EQU     000000080H
SKF_TWOKEYSOFF                                  EQU     000000100H
SKF_LALTLATCHED                                 EQU     010000000H
SKF_LCTLLATCHED                                 EQU     004000000H
SKF_LSHIFTLATCHED                               EQU     001000000H
SKF_RALTLATCHED                                 EQU     020000000H
SKF_RCTLLATCHED                                 EQU     008000000H
SKF_RSHIFTLATCHED                               EQU     002000000H
SKF_LWINLATCHED                                 EQU     040000000H
SKF_RWINLATCHED                                 EQU     080000000H
SKF_LALTLOCKED                                  EQU     000100000H
SKF_LCTLLOCKED                                  EQU     000040000H
SKF_LSHIFTLOCKED                                EQU     000010000H
SKF_RALTLOCKED                                  EQU     000200000H
SKF_RCTLLOCKED                                  EQU     000080000H
SKF_RSHIFTLOCKED                                EQU     000020000H
SKF_LWINLOCKED                                  EQU     000400000H
SKF_RWINLOCKED                                  EQU     000800000H

MKF_MOUSEKEYSON                                 EQU     000000001H
MKF_AVAILABLE                                   EQU     000000002H
MKF_HOTKEYACTIVE                                EQU     000000004H
MKF_CONFIRMHOTKEY                               EQU     000000008H
MKF_HOTKEYSOUND                                 EQU     000000010H
MKF_INDICATOR                                   EQU     000000020H
MKF_MODIFIERS                                   EQU     000000040H
MKF_REPLACENUMBERS                              EQU     000000080H
MKF_LEFTBUTTONSEL                               EQU     010000000H
MKF_RIGHTBUTTONSEL                              EQU     020000000H
MKF_LEFTBUTTONDOWN                              EQU     001000000H
MKF_RIGHTBUTTONDOWN                             EQU     002000000H
MKF_MOUSEMODE                                   EQU     080000000H

ATF_TIMEOUTON                                   EQU     000000001H
ATF_ONOFFFEEDBACK                               EQU     000000002H

SSGF_NONE                                       EQU     0
SSGF_DISPLAY                                    EQU     3

SSTF_NONE                                       EQU     0
SSTF_CHARS                                      EQU     1
SSTF_BORDER                                     EQU     2
SSTF_DISPLAY                                    EQU     3

SSWF_NONE                                       EQU     0
SSWF_TITLE                                      EQU     1
SSWF_WINDOW                                     EQU     2
SSWF_DISPLAY                                    EQU     3
SSWF_CUSTOM                                     EQU     4

SSF_SOUNDSENTRYON                               EQU     000000001H
SSF_AVAILABLE                                   EQU     000000002H
SSF_INDICATOR                                   EQU     000000004H

TKF_TOGGLEKEYSON                                EQU     000000001H
TKF_AVAILABLE                                   EQU     000000002H
TKF_HOTKEYACTIVE                                EQU     000000004H
TKF_CONFIRMHOTKEY                               EQU     000000008H
TKF_HOTKEYSOUND                                 EQU     000000010H
TKF_INDICATOR                                   EQU     000000020H

SLE_ERROR                                       EQU     000000001H
SLE_MINORERROR                                  EQU     000000002H
SLE_WARNING                                     EQU     000000003H

MONITOR_DEFAULTTONULL                           EQU     000000000H
MONITOR_DEFAULTTOPRIMARY                        EQU     000000001H
MONITOR_DEFAULTTONEAREST                        EQU     000000002H
MONITORINFOF_PRIMARY                            EQU     000000001H

IFNDEF CCHDEVICENAME
    CCHDEVICENAME                               EQU     32
ENDIF

WINEVENT_OUTOFCONTEXT                           EQU     00000H
WINEVENT_SKIPOWNTHREAD                          EQU     00001H
WINEVENT_SKIPOWNPROCESS                         EQU     00002H
WINEVENT_INCONTEXT                              EQU     00004H

CHILDID_SELF                                    EQU     0
INDEXID_OBJECT                                  EQU     0
INDEXID_CONTAINER                               EQU     0

OBJID_WINDOW                                    EQU     000000000H
OBJID_SYSMENU                                   EQU     0FFFFFFFFH
OBJID_TITLEBAR                                  EQU     0FFFFFFFEH
OBJID_MENU                                      EQU     0FFFFFFFDH
OBJID_CLIENT                                    EQU     0FFFFFFFCH
OBJID_VSCROLL                                   EQU     0FFFFFFFBH
OBJID_HSCROLL                                   EQU     0FFFFFFFAH
OBJID_SIZEGRIP                                  EQU     0FFFFFFF9H
OBJID_CARET                                     EQU     0FFFFFFF8H
OBJID_CURSOR                                    EQU     0FFFFFFF7H
OBJID_ALERT                                     EQU     0FFFFFFF6H
OBJID_SOUND                                     EQU     0FFFFFFF5H
OBJID_QUERYCLASSNAMEIDX                         EQU     0FFFFFFF4H
OBJID_NATIVEOM                                  EQU     0FFFFFFF0H

EVENT_MIN                                       EQU     000000001H
EVENT_MAX                                       EQU     07FFFFFFFH

EVENT_SYSTEM_SOUND                              EQU     00001H
EVENT_SYSTEM_ALERT                              EQU     00002H
EVENT_SYSTEM_FOREGROUND                         EQU     00003H
EVENT_SYSTEM_MENUSTART                          EQU     00004H
EVENT_SYSTEM_MENUEND                            EQU     00005H
EVENT_SYSTEM_MENUPOPUPSTART                     EQU     00006H
EVENT_SYSTEM_MENUPOPUPEND                       EQU     00007H
EVENT_SYSTEM_CAPTURESTART                       EQU     00008H
EVENT_SYSTEM_CAPTUREEND                         EQU     00009H
EVENT_SYSTEM_MOVESIZESTART                      EQU     0000AH
EVENT_SYSTEM_MOVESIZEEND                        EQU     0000BH
EVENT_SYSTEM_CONTEXTHELPSTART                   EQU     0000CH
EVENT_SYSTEM_CONTEXTHELPEND                     EQU     0000DH
EVENT_SYSTEM_DRAGDROPSTART                      EQU     0000EH
EVENT_SYSTEM_DRAGDROPEND                        EQU     0000FH
EVENT_SYSTEM_DIALOGSTART                        EQU     00010H
EVENT_SYSTEM_DIALOGEND                          EQU     00011H
EVENT_SYSTEM_SCROLLINGSTART                     EQU     00012H
EVENT_SYSTEM_SCROLLINGEND                       EQU     00013H
EVENT_SYSTEM_SWITCHSTART                        EQU     00014H
EVENT_SYSTEM_SWITCHEND                          EQU     00015H
EVENT_SYSTEM_MINIMIZESTART                      EQU     00016H
EVENT_SYSTEM_MINIMIZEEND                        EQU     00017H
EVENT_SYSTEM_DESKTOPSWITCH                      EQU     00020H
EVENT_SYSTEM_END                                EQU     000FFH

EVENT_OEM_DEFINED_START                         EQU     00101H
EVENT_OEM_DEFINED_END                           EQU     001FFH

EVENT_UIA_EVENTID_START                         EQU     04E00H
EVENT_UIA_EVENTID_END                           EQU     04EFFH
EVENT_UIA_PROPID_START                          EQU     07500H
EVENT_UIA_PROPID_END                            EQU     075FFH

EVENT_CONSOLE_CARET                             EQU     04001H
EVENT_CONSOLE_UPDATE_REGION                     EQU     04002H
EVENT_CONSOLE_UPDATE_SIMPLE                     EQU     04003H
EVENT_CONSOLE_UPDATE_SCROLL                     EQU     04004H
EVENT_CONSOLE_LAYOUT                            EQU     04005H
EVENT_CONSOLE_START_APPLICATION                 EQU     04006H
EVENT_CONSOLE_END_APPLICATION                   EQU     04007H
EVENT_CONSOLE_END                               EQU     040FFH

IFDEF APP_WIN64
    CONSOLE_APPLICATION_16BIT                   EQU     00000H
ELSE
    CONSOLE_APPLICATION_16BIT                   EQU     00001H
ENDIF

EVENT_OBJECT_CREATE                             EQU     08000H
EVENT_OBJECT_DESTROY                            EQU     08001H
EVENT_OBJECT_SHOW                               EQU     08002H
EVENT_OBJECT_HIDE                               EQU     08003H
EVENT_OBJECT_REORDER                            EQU     08004H
EVENT_OBJECT_FOCUS                              EQU     08005H
EVENT_OBJECT_SELECTION                          EQU     08006H
EVENT_OBJECT_SELECTIONADD                       EQU     08007H
EVENT_OBJECT_SELECTIONREMOVE                    EQU     08008H
EVENT_OBJECT_SELECTIONWITHIN                    EQU     08009H
EVENT_OBJECT_STATECHANGE                        EQU     0800AH
EVENT_OBJECT_LOCATIONCHANGE                     EQU     0800BH
EVENT_OBJECT_NAMECHANGE                         EQU     0800CH
EVENT_OBJECT_DESCRIPTIONCHANGE                  EQU     0800DH
EVENT_OBJECT_VALUECHANGE                        EQU     0800EH
EVENT_OBJECT_PARENTCHANGE                       EQU     0800FH
EVENT_OBJECT_HELPCHANGE                         EQU     08010H
EVENT_OBJECT_DEFACTIONCHANGE                    EQU     08011H
EVENT_OBJECT_ACCELERATORCHANGE                  EQU     08012H
EVENT_OBJECT_INVOKED                            EQU     08013H
EVENT_OBJECT_TEXTSELECTIONCHANGED               EQU     08014H
EVENT_OBJECT_CONTENTSCROLLED                    EQU     08015H
EVENT_SYSTEM_ARRANGMENTPREVIEW                  EQU     08016H

EVENT_OBJECT_CLOAKED                            EQU     08017H
EVENT_OBJECT_UNCLOAKED                          EQU     08018H
EVENT_OBJECT_LIVEREGIONCHANGED                  EQU     08019H
EVENT_OBJECT_HOSTEDOBJECTSINVALIDATED           EQU     08020H

EVENT_OBJECT_END                                EQU     080FFH

EVENT_AIA_START                                 EQU     0A000H
EVENT_AIA_END                                   EQU     0AFFFH

SOUND_SYSTEM_STARTUP                            EQU     1
SOUND_SYSTEM_SHUTDOWN                           EQU     2
SOUND_SYSTEM_BEEP                               EQU     3
SOUND_SYSTEM_ERROR                              EQU     4
SOUND_SYSTEM_QUESTION                           EQU     5
SOUND_SYSTEM_WARNING                            EQU     6
SOUND_SYSTEM_INFORMATION                        EQU     7
SOUND_SYSTEM_MAXIMIZE                           EQU     8
SOUND_SYSTEM_MINIMIZE                           EQU     9
SOUND_SYSTEM_RESTOREUP                          EQU     10
SOUND_SYSTEM_RESTOREDOWN                        EQU     11
SOUND_SYSTEM_APPSTART                           EQU     12
SOUND_SYSTEM_FAULT                              EQU     13
SOUND_SYSTEM_APPEND                             EQU     14
SOUND_SYSTEM_MENUCOMMAND                        EQU     15
SOUND_SYSTEM_MENUPOPUP                          EQU     16
CSOUND_SYSTEM                                   EQU     16

ALERT_SYSTEM_INFORMATIONAL                      EQU     1
ALERT_SYSTEM_WARNING                            EQU     2
ALERT_SYSTEM_ERROR                              EQU     3
ALERT_SYSTEM_QUERY                              EQU     4
ALERT_SYSTEM_CRITICAL                           EQU     5
CALERT_SYSTEM                                   EQU     6

USER_DEFAULT_SCREEN_DPI                         EQU     96

GUI_CARETBLINKING                               EQU     000000001H
GUI_INMOVESIZE                                  EQU     000000002H
GUI_INMENUMODE                                  EQU     000000004H
GUI_SYSTEMMENUMODE                              EQU     000000008H
GUI_POPUPMENUMODE                               EQU     000000010H

IFDEF APP_WIN64
    GUI_16BITTASK                               EQU     000000000H
ELSE
    GUI_16BITTASK                               EQU     000000020H
ENDIF

STATE_SYSTEM_UNAVAILABLE                        EQU     000000001H
STATE_SYSTEM_SELECTED                           EQU     000000002H
STATE_SYSTEM_FOCUSED                            EQU     000000004H
STATE_SYSTEM_PRESSED                            EQU     000000008H
STATE_SYSTEM_CHECKED                            EQU     000000010H
STATE_SYSTEM_MIXED                              EQU     000000020H
STATE_SYSTEM_INDETERMINATE                      EQU     000000020H
STATE_SYSTEM_READONLY                           EQU     000000040H
STATE_SYSTEM_HOTTRACKED                         EQU     000000080H
STATE_SYSTEM_DEFAULT                            EQU     000000100H
STATE_SYSTEM_EXPANDED                           EQU     000000200H
STATE_SYSTEM_COLLAPSED                          EQU     000000400H
STATE_SYSTEM_BUSY                               EQU     000000800H
STATE_SYSTEM_FLOATING                           EQU     000001000H
STATE_SYSTEM_MARQUEED                           EQU     000002000H
STATE_SYSTEM_ANIMATED                           EQU     000004000H
STATE_SYSTEM_INVISIBLE                          EQU     000008000H
STATE_SYSTEM_OFFSCREEN                          EQU     000010000H
STATE_SYSTEM_SIZEABLE                           EQU     000020000H
STATE_SYSTEM_MOVEABLE                           EQU     000040000H
STATE_SYSTEM_SELFVOICING                        EQU     000080000H
STATE_SYSTEM_FOCUSABLE                          EQU     000100000H
STATE_SYSTEM_SELECTABLE                         EQU     000200000H
STATE_SYSTEM_LINKED                             EQU     000400000H
STATE_SYSTEM_TRAVERSED                          EQU     000800000H
STATE_SYSTEM_MULTISELECTABLE                    EQU     001000000H
STATE_SYSTEM_EXTSELECTABLE                      EQU     002000000H
STATE_SYSTEM_ALERT_LOW                          EQU     004000000H
STATE_SYSTEM_ALERT_MEDIUM                       EQU     008000000H
STATE_SYSTEM_ALERT_HIGH                         EQU     010000000H
STATE_SYSTEM_PROTECTED                          EQU     020000000H
STATE_SYSTEM_VALID                              EQU     01FFFFFFFH

CCHILDREN_TITLEBAR                              EQU     5
CCHILDREN_SCROLLBAR                             EQU     5

CURSOR_SHOWING                                  EQU     000000001H
CURSOR_SUPPRESSED                               EQU     000000002H

WS_ACTIVECAPTION                                EQU     00001H

WTS_CONSOLE_CONNECT                             EQU     01H
WTS_CONSOLE_DISCONNECT                          EQU     02H
WTS_REMOTE_CONNECT                              EQU     03H
WTS_REMOTE_DISCONNECT                           EQU     04H
WTS_SESSION_LOGON                               EQU     05H
WTS_SESSION_LOGOFF                              EQU     06H
WTS_SESSION_LOCK                                EQU     07H
WTS_SESSION_UNLOCK                              EQU     08H
WTS_SESSION_REMOTE_CONTROL                      EQU     09H

GA_MIC                                          EQU     1
GA_PARENT                                       EQU     1
GA_ROOT                                         EQU     2
GA_ROOTOWNER                                    EQU     3
GA_MAC                                          EQU     4

RIM_INPUT                                       EQU     0
RIM_INPUTSINK                                   EQU     1
RIM_TYPEMOUSE                                   EQU     0
RIM_TYPEKEYBOARD                                EQU     1
RIM_TYPEHID                                     EQU     2

RI_MOUSE_LEFT_BUTTON_DOWN                       EQU     00001H
RI_MOUSE_LEFT_BUTTON_UP                         EQU     00002H
RI_MOUSE_RIGHT_BUTTON_DOWN                      EQU     00004H
RI_MOUSE_RIGHT_BUTTON_UP                        EQU     00008H
RI_MOUSE_MIDDLE_BUTTON_DOWN                     EQU     00010H
RI_MOUSE_MIDDLE_BUTTON_UP                       EQU     00020H

RI_MOUSE_BUTTON_1_DOWN                          EQU     RI_MOUSE_LEFT_BUTTON_DOWN
RI_MOUSE_BUTTON_1_UP                            EQU     RI_MOUSE_LEFT_BUTTON_UP
RI_MOUSE_BUTTON_2_DOWN                          EQU     RI_MOUSE_RIGHT_BUTTON_DOWN
RI_MOUSE_BUTTON_2_UP                            EQU     RI_MOUSE_RIGHT_BUTTON_UP
RI_MOUSE_BUTTON_3_DOWN                          EQU     RI_MOUSE_MIDDLE_BUTTON_DOWN
RI_MOUSE_BUTTON_3_UP                            EQU     RI_MOUSE_MIDDLE_BUTTON_UP

RI_MOUSE_BUTTON_4_DOWN                          EQU     00040H
RI_MOUSE_BUTTON_4_UP                            EQU     00080H
RI_MOUSE_BUTTON_5_DOWN                          EQU     00100H
RI_MOUSE_BUTTON_5_UP                            EQU     00200H

RI_MOUSE_WHEEL                                  EQU     00400H

MOUSE_MOVE_RELATIVE                             EQU     0
MOUSE_MOVE_ABSOLUTE                             EQU     1
MOUSE_VIRTUAL_DESKTOP                           EQU     002H
MOUSE_ATTRIBUTES_CHANGED                        EQU     004H
MOUSE_MOVE_NOCOALESCE                           EQU     008H

KEYBOARD_OVERRUN_MAKE_CODE                      EQU     0FFH

RI_KEY_MAKE                                     EQU     0
RI_KEY_BREAK                                    EQU     1
RI_KEY_E0                                       EQU     2
RI_KEY_E1                                       EQU     4
RI_KEY_TERMSRV_SET_LED                          EQU     8
RI_KEY_TERMSRV_SHADOW                           EQU     010H

RID_INPUT                                       EQU     010000003H
RID_HEADER                                      EQU     010000005H

RIDI_PREPARSEDDATA                              EQU     020000005H
RIDI_DEVICENAME                                 EQU     020000007H
RIDI_DEVICEINFO                                 EQU     02000000BH

RIDEV_REMOVE                                    EQU     000000001H
RIDEV_EXCLUDE                                   EQU     000000010H
RIDEV_PAGEONLY                                  EQU     000000020H
RIDEV_NOLEGACY                                  EQU     000000030H
RIDEV_INPUTSINK                                 EQU     000000100H
RIDEV_CAPTUREMOUSE                              EQU     000000200H
RIDEV_NOHOTKEYS                                 EQU     000000200H
RIDEV_APPKEYS                                   EQU     000000400H
RIDEV_EXINPUTSINK                               EQU     000001000H
RIDEV_DEVNOTIFY                                 EQU     000002000H
RIDEV_EXMODEMASK                                EQU     0000000F0H

GIDC_ARRIVAL                                    EQU     1
GIDC_REMOVAL                                    EQU     2

POINTER_DEVICE_PRODUCT_STRING_MAX               EQU     520

PDC_ARRIVAL                                     EQU     0001H
PDC_REMOVAL                                     EQU     0002H
PDC_ORIENTATION_0                               EQU     0004H
PDC_ORIENTATION_90                              EQU     0008H
PDC_ORIENTATION_180                             EQU     0010H
PDC_ORIENTATION_270                             EQU     0020H
PDC_MODE_DEFAULT                                EQU     0040H
PDC_MODE_CENTERED                               EQU     0080H
PDC_MAPPING_CHANGE                              EQU     0100H
PDC_RESOLUTION                                  EQU     0200H
PDC_ORIGIN                                      EQU     0400H

POINTER_DEVICE_TYPE_INTEGRATED_PEN              EQU     000000001H
POINTER_DEVICE_TYPE_EXTERNAL_PEN                EQU     000000002H
POINTER_DEVICE_TYPE_TOUCH                       EQU     000000003H
POINTER_DEVICE_TYPE_MAX                         EQU     0FFFFFFFFH

POINTER_DEVICE_CURSOR_TYPE_UNKNOWN              EQU     000000000H
POINTER_DEVICE_CURSOR_TYPE_TIP                  EQU     000000001H
POINTER_DEVICE_CURSOR_TYPE_ERASER               EQU     000000002H
POINTER_DEVICE_CURSOR_TYPE_MAX                  EQU     0FFFFFFFFH

TOUCHEVENTF_MOVE                                EQU     00001H
TOUCHEVENTF_DOWN                                EQU     00002H
TOUCHEVENTF_UP                                  EQU     00004H
TOUCHEVENTF_INRANGE                             EQU     00008H
TOUCHEVENTF_PRIMARY                             EQU     00010H
TOUCHEVENTF_NOCOALESCE                          EQU     00020H
TOUCHEVENTF_PEN                                 EQU     00040H
TOUCHEVENTF_PALM                                EQU     00080H

TOUCHINPUTMASKF_TIMEFROMSYSTEM                  EQU     00001H
TOUCHINPUTMASKF_EXTRAINFO                       EQU     00002H
TOUCHINPUTMASKF_CONTACTAREA                     EQU     00004H

TWF_FINETOUCH                                   EQU     000000001H
TWF_WANTPALM                                    EQU     000000002H

PT_POINTER                                      EQU     000000001H
PT_TOUCH                                        EQU     000000002H
PT_PEN                                          EQU     000000003H
PT_MOUSE                                        EQU     000000004H

POINTER_FLAG_NONE                               EQU     000000000H
POINTER_FLAG_NEW                                EQU     000000001H
POINTER_FLAG_INRANGE                            EQU     000000002H
POINTER_FLAG_INCONTACT                          EQU     000000004H
POINTER_FLAG_FIRSTBUTTON                        EQU     000000010H
POINTER_FLAG_SECONDBUTTON                       EQU     000000020H
POINTER_FLAG_OTHERBUTTON                        EQU     000000040H
POINTER_FLAG_THIRDBUTTON                        EQU     000000080H
POINTER_FLAG_PRIMARY                            EQU     000000100H
POINTER_FLAG_CONFIDENCE                         EQU     000000200H
POINTER_FLAG_CANCELED                           EQU     000000400H
POINTER_FLAG_DOWN                               EQU     000010000H
POINTER_FLAG_UPDATE                             EQU     000020000H
POINTER_FLAG_UP                                 EQU     000040000H
POINTER_FLAG_WHEEL                              EQU     000080000H
POINTER_FLAG_HWHEEL                             EQU     000100000H
POINTER_FLAG_CAPTURECHANGED                     EQU     000200000H

POINTER_MOD_SHIFT                               EQU     00004H
POINTER_MOD_CTRL                                EQU     00008H

TOUCH_FLAG_NONE                                 EQU     000000000H

TOUCH_MASK_NONE                                 EQU     000000000H
TOUCH_MASK_CONTACTAREA                          EQU     000000001H
TOUCH_MASK_ORIENTATION                          EQU     000000002H
TOUCH_MASK_PRESSURE                             EQU     000000004H

PEN_FLAG_NONE                                   EQU     000000000H
PEN_FLAG_BARREL                                 EQU     000000001H
PEN_FLAG_INVERTED                               EQU     000000002H
PEN_FLAG_ERASER                                 EQU     000000004H

PEN_MASK_NONE                                   EQU     000000000H
PEN_MASK_PRESSURE                               EQU     000000001H
PEN_MASK_ROTATION                               EQU     000000002H
PEN_MASK_TILT_X                                 EQU     000000004H
PEN_MASK_TILT_Y                                 EQU     000000008H

POINTER_MESSAGE_FLAG_NEW                        EQU     000000001H
POINTER_MESSAGE_FLAG_INRANGE                    EQU     000000002H
POINTER_MESSAGE_FLAG_INCONTACT                  EQU     000000004H
POINTER_MESSAGE_FLAG_FIRSTBUTTON                EQU     000000010H
POINTER_MESSAGE_FLAG_SECONDBUTTON               EQU     000000020H
POINTER_MESSAGE_FLAG_OTHERBUTTON                EQU     000000040H
POINTER_MESSAGE_FLAG_THIRDBUTTON                EQU     000000080H
POINTER_MESSAGE_FLAG_PRIMARY                    EQU     000000100H
POINTER_MESSAGE_FLAG_CONFIDENCE                 EQU     000000200H
POINTER_MESSAGE_FLAG_CANCELED                   EQU     000000400H

PA_ACTIVATE                                     EQU     MA_ACTIVATE
PA_NOACTIVATE                                   EQU     MA_NOACTIVATE

MAX_TOUCH_COUNT                                 EQU     256

TOUCH_FEEDBACK_DEFAULT                          EQU     01H
TOUCH_FEEDBACK_INDIRECT                         EQU     02H
TOUCH_FEEDBACK_NONE                             EQU     03H

TOUCH_HIT_TESTING_DEFAULT                       EQU     00H
TOUCH_HIT_TESTING_CLIENT                        EQU     01H
TOUCH_HIT_TESTING_NONE                          EQU     02H

TOUCH_HIT_TESTING_PROXIMITY_CLOSEST             EQU     0000H
TOUCH_HIT_TESTING_PROXIMITY_FARTHEST            EQU     0FFFH

FEEDBACK_TOUCH_CONTACTVISUALIZATION             EQU     1
FEEDBACK_PEN_BARRELVISUALIZATION                EQU     2
FEEDBACK_PEN_TAP                                EQU     3
FEEDBACK_PEN_DOUBLETAP                          EQU     4
FEEDBACK_PEN_PRESSANDHOLD                       EQU     5
FEEDBACK_PEN_RIGHTTAP                           EQU     6
FEEDBACK_TOUCH_TAP                              EQU     7
FEEDBACK_TOUCH_DOUBLETAP                        EQU     8
FEEDBACK_TOUCH_PRESSANDHOLD                     EQU     9
FEEDBACK_TOUCH_RIGHTTAP                         EQU     10
FEEDBACK_GESTURE_PRESSANDTAP                    EQU     11
FEEDBACK_MAX                                    EQU     0FFFFFFFFH

GWFS_INCLUDE_ANCESTORS                          EQU     000000001H

MSGFLTINFO_NONE                                 EQU     0
MSGFLTINFO_ALREADYALLOWED_FORWND                EQU     1
MSGFLTINFO_ALREADYDISALLOWED_FORWND             EQU     2
MSGFLTINFO_ALLOWED_HIGHER                       EQU     3

MSGFLT_RESET                                    EQU     0
MSGFLT_ALLOW                                    EQU     1
MSGFLT_DISALLOW                                 EQU     2

GF_BEGIN                                        EQU     000000001H
GF_INERTIA                                      EQU     000000002H
GF_END                                          EQU     000000004H

GID_BEGIN                                       EQU     1
GID_END                                         EQU     2
GID_ZOOM                                        EQU     3
GID_PAN                                         EQU     4
GID_ROTATE                                      EQU     5
GID_TWOFINGERTAP                                EQU     6
GID_PRESSANDTAP                                 EQU     7
GID_ROLLOVER                                    EQU     GID_PRESSANDTAP

GC_ALLGESTURES                                  EQU     000000001H
GC_ZOOM                                         EQU     000000001H
GC_PAN                                          EQU     000000001H
GC_PAN_WITH_SINGLE_FINGER_VERTICALLY            EQU     000000002H
GC_PAN_WITH_SINGLE_FINGER_HORIZONTALLY          EQU     000000004H
GC_PAN_WITH_GUTTER                              EQU     000000008H
GC_PAN_WITH_INERTIA                             EQU     000000010H
GC_ROTATE                                       EQU     000000001H
GC_TWOFINGERTAP                                 EQU     000000001H
GC_PRESSANDTAP                                  EQU     000000001H
GC_ROLLOVER                                     EQU     GC_PRESSANDTAP
GESTURECONFIGMAXCOUNT                           EQU     256

GCF_INCLUDE_ANCESTORS                           EQU     000000001H

NID_INTEGRATED_TOUCH                            EQU     000000001H
NID_EXTERNAL_TOUCH                              EQU     000000002H
NID_INTEGRATED_PEN                              EQU     000000004H
NID_EXTERNAL_PEN                                EQU     000000008H
NID_MULTI_INPUT                                 EQU     000000040H
NID_READY                                       EQU     000000080H

MAX_STR_BLOCKREASON                             EQU     256

WDA_NONE                                        EQU     0
WDA_MONITOR                                     EQU     1


;======================================== Structures ======================================;
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

POINTER_DEVICE_INFO STRUCT ALIGNMODE
    displayOrientation  DD       ?
    device              HANDLE   ?
    pointerDeviceType   ENUM     ?
    _monitor            HMONITOR ?
    startingCursorId    ULONG    ?
    maxActiveContacts   USHORT   ?
    productString       WCHAR    POINTER_DEVICE_PRODUCT_STRING_MAX DUP(?)
POINTER_DEVICE_INFO ENDS

POINTER_DEVICE_PROPERTY STRUCT ALIGNMODE
    logicalMin   INT32  ?
    logicalMax   INT32  ?
    physicalMin  INT32  ?
    physicalMax  INT32  ?
    unit         UINT32 ?
    unitExponent UINT32 ?
    usagePageId  USHORT ?
    usageId      USHORT ?
POINTER_DEVICE_PROPERTY ENDS

POINTER_DEVICE_CURSOR_INFO STRUCT ALIGNMODE
    cursorId UINT32 ?
    cursor   ENUM   ?
POINTER_DEVICE_CURSOR_INFO ENDS

POWERBROADCAST_SETTING STRUCT ALIGNMODE
    PowerSetting GUID  <>
    DataLength   DD    ?
    Data         UCHAR ?
POWERBROADCAST_SETTING ENDS

TOUCHPREDICTIONPARAMETERS STRUCT ALIGNMODE
    cbSize          UINT ?
    dwLatency       UINT ?
    dwSampleTime    UINT ?
    bUseHWTimeStamp UINT ?
TOUCHPREDICTIONPARAMETERS ENDS

ICONINFOEXA STRUCT ALIGNMODE
    cbSize      DD      ?
    fIcon       BOOL    ?
    xHotspot    DD      ?
    yHotspot    DD      ?
    hbmMask     HBITMAP ?
    hbmColor    HBITMAP ?
    wResID      DW      ?
    szModName   CHAR    MAX_PATH DUP(?)
    szResName   CHAR    MAX_PATH DUP(?)
ICONINFOEXA ENDS

ICONINFOEXW STRUCT ALIGNMODE
    cbSize      DD      ?
    fIcon       BOOL    ?
    xHotspot    DD      ?
    yHotspot    DD      ?
    hbmMask     HBITMAP ?
    hbmColor    HBITMAP ?
    wResID      DW      ?
    szModName   WCHAR   MAX_PATH DUP(?)
    szResName   WCHAR   MAX_PATH DUP(?)
ICONINFOEXW ENDS

RAWINPUTDEVICELIST STRUCT ALIGNMODE
    hDevice HANDLE ?
    dwType  DD     ?
RAWINPUTDEVICELIST ENDS

RAWINPUTDEVICE STRUCT ALIGNMODE
    usUsagePage DW   ?
    usUsage     DW   ?
    dwFlags     DD   ?
    hwndTarget  HWND ?
RAWINPUTDEVICE ENDS

RAWHID STRUCT ALIGNMODE
    dwSizeHid   DD  ?
    dwCount     DD  ?
    bRawData    DB  1 DUP(?)
RAWHID ENDS

RAWINPUTHEADER STRUCT ALIGNMODE
    dwType  DD     ?
    dwSize  DD     ?
    hDevice HANDLE ?
    wParam  WPARAM ?
RAWINPUTHEADER ENDS

RAWMOUSE STRUCT ALIGNMODE
    usFlags DW  ?
    UNION
        ulButtons ULONG ?
        STRUCT
            usButtonFlags DW  ?
            usButtonData  DW  ?
        ENDS
    ENDS
    ulRawButtons        ULONG ?
    lLastX              LONG  ?
    lLastY              LONG  ?
    ulExtraInformation  ULONG ?
RAWMOUSE ENDS

RAWKEYBOARD STRUCT ALIGNMODE
    MakeCode         DW    ?
    Flags            DW    ?
    Reserved         DW    ?
    VKey             DW    ?
    Message          UINT  ?
    ExtraInformation ULONG ?
RAWKEYBOARD ENDS

RAWINPUT STRUCT ALIGNMODE
    header RAWINPUTHEADER <>
    UNION data
        mouse    RAWMOUSE <>
        keyboard RAWKEYBOARD <>
        hid      RAWHID <>
    ENDS
RAWINPUT ENDS

RID_DEVICE_INFO_MOUSE STRUCT ALIGNMODE
    dwId                DD   ?
    dwNumberOfButtons   DD   ?
    dwSampleRate        DD   ?
    fHasHorizontalWheel BOOL ?
RID_DEVICE_INFO_MOUSE ENDS

RID_DEVICE_INFO_KEYBOARD STRUCT ALIGNMODE
    dwType                  DD  ?
    dwSubType               DD  ?
    dwKeyboardMode          DD  ?
    dwNumberOfFunctionKeys  DD  ?
    dwNumberOfIndicators    DD  ?
    dwNumberOfKeysTotal     DD  ?
RID_DEVICE_INFO_KEYBOARD ENDS

RID_DEVICE_INFO_HID STRUCT ALIGNMODE
    dwVendorId      DD  ?
    dwProductId     DD  ?
    dwVersionNumber DD  ?
    usUsagePage     DW  ?
    usUsage         DW  ?
RID_DEVICE_INFO_HID ENDS

RID_DEVICE_INFO STRUCT ALIGNMODE
    cbSize  DD  ?
    dwType  DD  ?
    UNION
        mouse    RID_DEVICE_INFO_MOUSE <>
        keyboard RID_DEVICE_INFO_KEYBOARD <>
        hid      RID_DEVICE_INFO_HID <>
    ENDS
RID_DEVICE_INFO ENDS

AUDIODESCRIPTION STRUCT ALIGNMODE
    cbSize  UINT  ?
    Enabled BOOL  ?
    Locale  LCID  ?
AUDIODESCRIPTION ENDS

CBT_CREATEWNDA STRUCT ALIGNMODE
    lpcs            XPTR ?
    hwndInsertAfter HWND ?
CBT_CREATEWNDA ENDS

CBT_CREATEWNDW STRUCT ALIGNMODE
    lpcs            XPTR ?
    hwndInsertAfter HWND ?
CBT_CREATEWNDW ENDS

CBTACTIVATESTRUCT STRUCT ALIGNMODE
    fMouse      BOOL ?
    hWndActive  HWND ?
CBTACTIVATESTRUCT ENDS

WTSSESSION_NOTIFICATION STRUCT ALIGNMODE
    cbSize      DD  ?
    dwSessionId DD  ?
WTSSESSION_NOTIFICATION ENDS

SHELLHOOKINFO STRUCT ALIGNMODE
    hwnd HANDLE ?
    rc   RECT <>
SHELLHOOKINFO ENDS

EVENTMSG STRUCT ALIGNMODE
    message UINT ?
    paramL  UINT ?
    paramH  UINT ?
    time    DD   ?
    hwnd    HWND ?
EVENTMSG ENDS

CWPSTRUCT STRUCT ALIGNMODE
    lParam  LPARAM ?
    wParam  WPARAM ?
    message UINT   ?
    hwnd    HWND   ?
CWPSTRUCT ENDS

CWPRETSTRUCT STRUCT ALIGNMODE
    lResult LRESULT ?
    lParam  LPARAM  ?
    wParam  WPARAM  ?
    message UINT    ?
    hwnd    HWND    ?
CWPRETSTRUCT ENDS

KBDLLHOOKSTRUCT STRUCT ALIGNMODE
    vkCode      DD        ?
    scanCode    DD        ?
    flags       DD        ?
    time        DD        ?
    dwExtraInfo ULONG_PTR ?
KBDLLHOOKSTRUCT ENDS

MSLLHOOKSTRUCT STRUCT ALIGNMODE
    pt          POINT     <>
    mouseData   DD        ?
    flags       DD        ?
    time        DD        ?
    dwExtraInfo ULONG_PTR ?
MSLLHOOKSTRUCT ENDS

DEBUGHOOKINFO STRUCT ALIGNMODE
    idThread            DD     ?
    idThreadInstaller   DD     ?
    lParam              LPARAM ?
    wParam              WPARAM ?
    _code               DD     ?
DEBUGHOOKINFO ENDS

MOUSEHOOKSTRUCT STRUCT ALIGNMODE
    pt              POINT     <>
    hwnd            HWND      ?
    wHitTestCode    UINT      ?
    dwExtraInfo     ULONG_PTR ?
MOUSEHOOKSTRUCT ENDS

MOUSEHOOKSTRUCTEX STRUCT ALIGNMODE
    MouseHookStruct MOUSEHOOKSTRUCT <>
    mouseData       DD  ?
MOUSEHOOKSTRUCTEX ENDS

HARDWAREHOOKSTRUCT STRUCT ALIGNMODE
    hwnd    HWND   ?
    message UINT   ?
    wParam  WPARAM ?
    lParam  LPARAM ?
HARDWAREHOOKSTRUCT ENDS

MOUSEMOVEPOINT STRUCT ALIGNMODE
    x           DD        ?
    y           DD        ?
    time        DD        ?
    dwExtraInfo ULONG_PTR ?
MOUSEMOVEPOINT ENDS

USEROBJECTFLAGS STRUCT ALIGNMODE
    fInherit    BOOL ?
    fReserved   BOOL ?
    dwFlags     DD   ?
USEROBJECTFLAGS ENDS

WNDCLASSEXA STRUCT
    cbSize          UINT      ?
    style           UINT      ?
    lpfnWndProc     WNDPROC   ?
    cbClsExtra      DD        ?
    cbWndExtra      DD        ?
    hInstance       HINSTANCE ?
    hIcon           HICON     ?
    hCursor         HCURSOR   ?
    hbrBackground   HBRUSH    ?
    lpszMenuName    LPCTSTR   ?
    lpszClassName   LPCTSTR   ?
    hIconSm         HICON     ?
WNDCLASSEXA ENDS

WNDCLASSEXW STRUCT
    cbSize          UINT      ?
    style           UINT      ?
    lpfnWndProc     WNDPROC   ?
    cbClsExtra      DD        ?
    cbWndExtra      DD        ?
    hInstance       HINSTANCE ?
    hIcon           HICON     ?
    hCursor         HCURSOR   ?
    hbrBackground   HBRUSH    ?
    lpszMenuName    LPCTSTR   ?
    lpszClassName   LPCTSTR   ?
    hIconSm         HICON     ?
WNDCLASSEXW ENDS

WNDCLASSA STRUCT ALIGNMODE
    style           UINT    ?
    lpfnWndProc     WNDPROC ?
    cbClsExtra      DD      ?
    cbWndExtra      DD      ?
    hInstance       HINSTANCE ?
    hIcon           HICON   ?
    hCursor         HCURSOR ?
    hbrBackground   HBRUSH  ?
    lpszMenuName    LPCTSTR ?
    lpszClassName   LPCTSTR ?
WNDCLASSA ENDS

WNDCLASSW STRUCT ALIGNMODE
    style           UINT    ?
    lpfnWndProc     WNDPROC ?
    cbClsExtra      DD      ?
    cbWndExtra      DD      ?
    hInstance       HINSTANCE ?
    hIcon           HICON   ?
    hCursor         HCURSOR ?
    hbrBackground   HBRUSH  ?
    lpszMenuName    LPCWSTR ?
    lpszClassName   LPCWSTR ?
WNDCLASSW ENDS

MSG STRUCT ALIGNMODE
    hwnd    HWND   ?
    message UINT   ?
    wParam  WPARAM ?
    lParam  LPARAM ?
    time    DD     ?
    pt      POINT  <>
MSG ENDS

MINMAXINFO STRUCT ALIGNMODE
    ptReserved      POINT <>
    ptMaxSize       POINT <>
    ptMaxPosition   POINT <>
    ptMinTrackSize  POINT <>
    ptMaxTrackSize  POINT <>
MINMAXINFO ENDS

COPYDATASTRUCT STRUCT ALIGNMODE
    dwData ULONG_PTR ?
    cbData DD        ?
    lpData PVOID     ?
COPYDATASTRUCT ENDS

MDINEXTMENU STRUCT ALIGNMODE
    hmenuIn     HMENU ?
    hmenuNext   HMENU ?
    hwndNext    HWND  ?
MDINEXTMENU ENDS

WINDOWPOS STRUCT ALIGNMODE
    hwnd            HWND ?
    hwndInsertAfter HWND ?
    x               DD   ?
    y               DD   ?
    lx              DD   ?
    cy              DD   ?
    flags           UINT ?
WINDOWPOS ENDS

NCCALCSIZE_PARAMS STRUCT ALIGNMODE
    rgrc  RECT 3 DUP(<>)
    lppos XPTR ?
NCCALCSIZE_PARAMS ENDS

TRACKMOUSEEVENT STRUCT ALIGNMODE
    cbSize      DD   ?
    dwFlags     DD   ?
    hwndTrack   HWND ?
    dwHoverTime DD   ?
TRACKMOUSEEVENT ENDS

ACCEL STRUCT ALIGNMODE
    fVirt DB  ?
    key   DW  ?
    cmd   DW  ?
ACCEL ENDS

PAINTSTRUCT STRUCT ALIGNMODE
    hdc         HDC  ?
    fErase      BOOL ?
    rcPaint     RECT <>
    fRestore    BOOL ?
    fIncUpdate  BOOL ?
    rgbReserved DB   32 DUP(?)
PAINTSTRUCT ENDS

CREATESTRUCTA STRUCT ALIGNMODE
    lpCreateParams  LPVOID    ?
    hInstance       HINSTANCE ?
    hMenu           HMENU     ?
    hwndParent      HWND      ?
    cy              DD        ?
    _cx             DD        ?
    y               DD        ?
    x               DD        ?
    style           LONG      ?
    lpszName        LPCTSTR   ?
    lpszClass       LPCTSTR   ?
    dwExStyle       DD        ?
CREATESTRUCTA ENDS

CREATESTRUCTW STRUCT ALIGNMODE
    lpCreateParams  LPVOID    ?
    hInstance       HINSTANCE ?
    hMenu           HMENU     ?
    hwndParent      HWND      ?
    cy              DD        ?
    _cx             DD        ?
    y               DD        ?
    x               DD        ?
    style           LONG      ?
    lpszName        LPCWSTR   ?
    lpszClass       LPCWSTR   ?
    dwExStyle       DD        ?
CREATESTRUCTW ENDS

WINDOWPLACEMENT STRUCT ALIGNMODE
    _length          UINT  ?
    flags            UINT  ?
    showCmd          UINT  ?
    ptMinPosition    POINT <>
    ptMaxPosition    POINT <>
    rcNormalPosition RECT  <>
WINDOWPLACEMENT ENDS

STYLESTRUCT STRUCT ALIGNMODE
    styleOld DD ?
    styleNew DD ?
STYLESTRUCT ENDS

MEASUREITEMSTRUCT STRUCT ALIGNMODE
    CtlType     UINT      ?
    CtlID       UINT      ?
    itemID      UINT      ?
    itemWidth   UINT      ?
    itemHeight  UINT      ?
    itemData    ULONG_PTR ?
MEASUREITEMSTRUCT ENDS

DRAWITEMSTRUCT STRUCT ALIGNMODE
    CtlType     UINT      ?
    CtlID       UINT      ?
    itemID      UINT      ?
    itemAction  UINT      ?
    itemState   UINT      ?
                DD        ? ;pad
    hwndItem    HWND      ?
    hDC         HDC       ?
    rcItem      RECT      <>
    itemData    ULONG_PTR ?
DRAWITEMSTRUCT ENDS

DELETEITEMSTRUCT STRUCT ALIGNMODE
    CtlType     UINT      ?
    CtlID       UINT      ?
    itemID      UINT      ?
    hwndItem    HWND      ?
    itemData    ULONG_PTR ?
DELETEITEMSTRUCT ENDS

COMPAREITEMSTRUCT STRUCT ALIGNMODE
    CtlType     UINT      ?
    CtlID       UINT      ?
    hwndItem    HWND      ?
    itemID1     UINT      ?
    itemData1   ULONG_PTR ?
    itemID2     UINT      ?
    itemData2   ULONG_PTR ?
    dwLocaleId  DD        ?
COMPAREITEMSTRUCT ENDS

FLASHWINFO STRUCT ALIGNMODE
    cbSize      UINT ?
    hwnd        HWND ?
    dwFlags     DD   ?
    uCount      UINT ?
    dwTimeout   DD   ?
FLASHWINFO ENDS

DLGTEMPLATE STRUCT ALIGNMODE
    style           DD  ?
    dwExtendedStyle DD  ?
    cdit            DW  ?
    x               DW  ?
    y               DW  ?
    _cx             DW  ?
    cy              DW  ?
DLGTEMPLATE ENDS

DLGITEMTEMPLATE STRUCT ALIGNMODE
    style           DD  ?
    dwExtendedStyle DD  ?
    x               DW  ?
    y               DW  ?
    _cx             DW  ?
    cy              DW  ?
    id              DW  ?
DLGITEMTEMPLATE ENDS

MOUSEINPUT STRUCT ALIGNMODE
    _dx         LONG      ?
    dy          LONG      ?
    mouseData   DD        ?
    dwFlags     DD        ?
    time        DD        ?
    dwExtraInfo ULONG_PTR ?
MOUSEINPUT ENDS

KEYBDINPUT STRUCT ALIGNMODE
    wVk         DW        ?
    wScan       DW        ?
    dwFlags     DD        ?
    time        DD        ?
    dwExtraInfo ULONG_PTR ?
KEYBDINPUT ENDS

HARDWAREINPUT STRUCT ALIGNMODE
    uMsg    DD  ?
    wParamL DW  ?
    wParamH DW  ?
HARDWAREINPUT ENDS

INPUT STRUCT ALIGNMODE
    _type  DD  ?
    UNION
        mi MOUSEINPUT    <>
        ki KEYBDINPUT    <>
        hi HARDWAREINPUT <>
    ENDS
INPUT ENDS

LASTINPUTINFO STRUCT ALIGNMODE
    cbSize UINT ?
    dwTime DD   ?
LASTINPUTINFO ENDS

TPMPARAMS STRUCT ALIGNMODE
    cbSize    UINT ?
    rcExclude RECT <>
TPMPARAMS ENDS

MENUINFO STRUCT ALIGNMODE
    cbSize          DD        ?
    fMask           DD        ?
    dwStyle         DD        ?
    cyMax           UINT      ?
    hbrBack         HBRUSH    ?
    dwContextHelpID DD        ?
    dwMenuData      ULONG_PTR ?
MENUINFO ENDS

MENUGETOBJECTINFO STRUCT ALIGNMODE
    dwFlags DD    ?
    uPos    UINT  ?
    hmenu   HMENU ?
    riid    PVOID ?
    pvObj   PVOID ?
MENUGETOBJECTINFO ENDS

MENUITEMINFOA STRUCT ALIGNMODE
    cbSize          UINT      ?
    fMask           UINT      ?
    fType           UINT      ?
    fState          UINT      ?
    wID             UINT      ?
                    UINT      ? ;Padding
    hSubMenu        HMENU     ?
    hbmpChecked     HBITMAP   ?
    hbmpUnchecked   HBITMAP   ?
    dwItemData      ULONG_PTR ?
    dwTypeData      LPTSTR    ?
    cch             UINT      ?
                    UINT      ? ;Padding
    hbmpItem        HBITMAP   ?
MENUITEMINFOA ENDS

MENUITEMINFOW STRUCT ALIGNMODE
    cbSize          UINT      ?
    fMask           UINT      ?
    fType           UINT      ?
    fState          UINT      ?
    wID             UINT      ?
                    UINT      ? ;Padding
    hSubMenu        HMENU     ?
    hbmpChecked     HBITMAP   ?
    hbmpUnchecked   HBITMAP   ?
    dwItemData      ULONG_PTR ?
    dwTypeData      LPWSTR    ?
    cch             UINT      ?
                    UINT      ? ;Padding
    hbmpItem        HBITMAP   ?
MENUITEMINFOW ENDS

DROPSTRUCT STRUCT ALIGNMODE
    hwndSource      HWND  ?
    hwndSink        HWND  ?
    wFmt            DD    ?
    dwData          XPTR  ?
    ptDrop          POINT <>
    dwControlData   DD    ?
DROPSTRUCT ENDS

DRAWTEXTPARAMS STRUCT ALIGNMODE
    cbSize        UINT ?
    iTabLength    DD   ?
    iLeftMargin   DD   ?
    iRightMargin  DD   ?
    uiLengthDrawn UINT ?
DRAWTEXTPARAMS ENDS

HELPINFO STRUCT ALIGNMODE
    cbSize       UINT   ?
    iContextType DD     ?
    iCtrlId      DD     ?
    hItemHandle  HANDLE ?
    dwContextId  DD     ?
    MousePos     POINT  <>
HELPINFO ENDS

MSGBOXPARAMSA STRUCT ALIGNMODE
    cbSize              UINT      ?
    hwndOwner           HWND      ?
    hInstance           HINSTANCE ?
    lpszText            LPCTSTR   ?
    lpszCaption         LPCTSTR   ?
    dwStyle             DD        ?
    lpszIcon            LPCTSTR   ?
    dwContextHelpId     DWORD_PTR ?
    lpfnMsgBoxCallback  XPTR      ?
    dwLanguageId        DD        ?
MSGBOXPARAMSA ENDS

MSGBOXPARAMSW STRUCT ALIGNMODE
    cbSize              UINT      ?
    hwndOwner           HWND      ?
    hInstance           HINSTANCE ?
    lpszText            LPCWSTR   ?
    lpszCaption         LPCWSTR   ?
    dwStyle             DD        ?
    lpszIcon            LPCWSTR   ?
    dwContextHelpId     DWORD_PTR ?
    lpfnMsgBoxCallback  XPTR      ?
    dwLanguageId        DD        ?
MSGBOXPARAMSW ENDS

MENUITEMTEMPLATEHEADER STRUCT ALIGNMODE
    versionNumber DW  ?
    _offset       DW  ?
MENUITEMTEMPLATEHEADER ENDS

MENUITEMTEMPLATE STRUCT ALIGNMODE
    mtOption DW    ? 
    mtID     DW    ?
    mtString WCHAR ?
MENUITEMTEMPLATE ENDS

ICONINFO STRUCT ALIGNMODE
    fIcon    BOOL    ?
    xHotspot DD      ?
    yHotspot DD      ?
    hbmMask  HBITMAP ?
    hbmColor HBITMAP ?
ICONINFO ENDS

CURSORSHAPE STRUCT ALIGNMODE
    xHotSpot  DD  ?
    yHotSpot  DD  ?
    _cx       DD  ?
    cy        DD  ?
    cbWidth   DD  ?
    Planes    DB  ?
    BitsPixel DB  ?
CURSORSHAPE ENDS

SCROLLINFO STRUCT ALIGNMODE
    cbSize    UINT ?
    fMask     UINT ?
    nMin      DD   ?
    nMax      DD   ?
    nPage     UINT ?
    nPos      DD   ?
    nTrackPos DD   ?
SCROLLINFO ENDS

MDICREATESTRUCTA STRUCT ALIGNMODE
    szClass LPCTSTR ?
    szTitle LPCTSTR ?
    hOwner  HANDLE  ?
    x       DD      ?
    y       DD      ?
    _cx     DD      ?
    cy      DD      ?
    style   DD      ?
    lParam  LPARAM  ?
MDICREATESTRUCTA ENDS

MDICREATESTRUCTW STRUCT ALIGNMODE
    szClass LPCWSTR ?
    szTitle LPCWSTR ?
    hOwner  HANDLE  ?
    x       DD      ?
    y       DD      ?
    _cx     DD      ?
    cy      DD      ?
    style   DD      ?
    lParam  LPARAM  ?
MDICREATESTRUCTW ENDS

CLIENTCREATESTRUCT STRUCT ALIGNMODE
    hWindowMenu  HANDLE ?
    idFirstChild UINT   ?
CLIENTCREATESTRUCT ENDS

MULTIKEYHELPA STRUCT ALIGNMODE
    mkSize      DD   ?
    mkKeylist   CHAR ?
    szKeyphrase CHAR ?
MULTIKEYHELPA ENDS

MULTIKEYHELPW STRUCT ALIGNMODE
    mkSize      DD    ?
    mkKeylist   WCHAR ?
    szKeyphrase WCHAR ?
MULTIKEYHELPW ENDS

HELPWININFOA STRUCT ALIGNMODE
    wStructSize DD   ?
    x           DD   ?
    y           DD   ?
    _dx         DD   ?
    dy          DD   ?
    wMax        DD   ?
    rgchMember  CHAR 2 DUP(?)
HELPWININFOA ENDS

HELPWININFOW STRUCT ALIGNMODE
    wStructSize DD    ?
    x           DD    ?
    y           DD    ?
    _dx         DD    ?
    dy          DD    ?
    wMax        DD    ?
    rgchMember  WCHAR 2 DUP(?)
HELPWININFOW ENDS

NONCLIENTMETRICSA STRUCT ALIGNMODE
    cbSize           UINT     ?
    iBorderWidth     DD       ?
    iScrollWidth     DD       ?
    iScrollHeight    DD       ?
    iCaptionWidth    DD       ?
    iCaptionHeight   DD       ?
    lfCaptionFont    LOGFONTA <>
    iSmCaptionWidth  DD       ?
    iSmCaptionHeight DD       ?
    lfSmCaptionFont  LOGFONTA <>
    iMenuWidth       DD       ?
    iMenuHeight      DD       ?
    lfMenuFont       LOGFONTA <>
    lfStatusFont     LOGFONTA <>
    lfMessageFont    LOGFONTA <>
    IF (NTDDI_VERSION GE NTDDI_VISTA)
        iPaddedBorderWidth DD ?
    ENDIF
NONCLIENTMETRICSA ENDS

NONCLIENTMETRICSW STRUCT ALIGNMODE
    cbSize           UINT     ?
    iBorderWidth     DD       ?
    iScrollWidth     DD       ?
    iScrollHeight    DD       ?
    iCaptionWidth    DD       ?
    iCaptionHeight   DD       ?
    lfCaptionFont    LOGFONTW <>
    iSmCaptionWidth  DD       ?
    iSmCaptionHeight DD       ?
    lfSmCaptionFont  LOGFONTW <>
    iMenuWidth       DD       ?
    iMenuHeight      DD       ?
    lfMenuFont       LOGFONTW <>
    lfStatusFont     LOGFONTW <>
    lfMessageFont    LOGFONTW <>
    IF (NTDDI_VERSION GE NTDDI_VISTA)
        iPaddedBorderWidth DD ?
    ENDIF
NONCLIENTMETRICSW ENDS

MINIMIZEDMETRICS STRUCT ALIGNMODE
    cbSize   UINT ?
    iWidth   DD   ?
    iHorzGap DD   ?
    iVertGap DD   ?
    iArrange DD   ?
MINIMIZEDMETRICS ENDS

ICONMETRICSA STRUCT ALIGNMODE
    cbSize       UINT ?
    iHorzSpacing DD   ?
    iVertSpacing DD   ?
    iTitleWrap   DD   ?
    lfFont       LOGFONTA <>
ICONMETRICSA ENDS

ICONMETRICSW STRUCT ALIGNMODE
    cbSize       UINT ?
    iHorzSpacing DD   ?
    iVertSpacing DD   ?
    iTitleWrap   DD   ?
    lfFont       LOGFONTW <>
ICONMETRICSW ENDS

ANIMATIONINFO STRUCT ALIGNMODE
    cbSize      UINT ?
    iMinAnimate DD   ?
ANIMATIONINFO ENDS

SERIALKEYSA STRUCT ALIGNMODE
    cbSize          UINT  ?
    dwFlags         DD    ?
    lpszActivePort  LPSTR ?
    lpszPort        LPSTR ?
    iBaudRate       UINT  ?
    iPortState      UINT  ?
    iActive         UINT  ?
SERIALKEYSA ENDS

SERIALKEYSW STRUCT ALIGNMODE
    cbSize          UINT   ?
    dwFlags         DD     ?
    lpszActivePort  LPWSTR ?
    lpszPort        LPWSTR ?
    iBaudRate       UINT   ?
    iPortState      UINT   ?
    iActive         UINT  ? 
SERIALKEYSW ENDS

HIGHCONTRASTA STRUCT ALIGNMODE
    cbSize            UINT   ?
    dwFlags           DD     ?
    lpszDefaultScheme LPTSTR ?
HIGHCONTRASTA ENDS

HIGHCONTRASTW STRUCT ALIGNMODE
    cbSize            UINT   ?
    dwFlags           DD     ?
    lpszDefaultScheme LPWSTR ?
HIGHCONTRASTW ENDS

FILTERKEYS STRUCT ALIGNMODE
    cbSize      UINT ?
    dwFlags     DD   ?
    iWaitMSec   DD   ?
    iDelayMSec  DD   ?
    iRepeatMSec DD   ?
    iBounceMSec DD   ?
FILTERKEYS ENDS

STICKYKEYS STRUCT ALIGNMODE
    cbSize  DD  ?
    dwFlags DD  ?
STICKYKEYS ENDS

MOUSEKEYS STRUCT ALIGNMODE
    cbSize          DD  ?
    dwFlags         DD  ?
    iMaxSpeed       DD  ?
    iTimeToMaxSpeed DD  ?
    iCtrlSpeed      DD  ?
    dwReserved1     DD  ?
    dwReserved2     DD  ?
MOUSEKEYS ENDS

TOGGLEKEYS STRUCT ALIGNMODE
    cbSize  DD  ?
    dwFlags DD  ?
TOGGLEKEYS ENDS

ACCESSTIMEOUT STRUCT ALIGNMODE
    cbSize       UINT ?
    dwFlags      DD   ?
    iTimeOutMSec DD   ?
ACCESSTIMEOUT ENDS

SOUNDSENTRYA STRUCT ALIGNMODE
    cbSize                  UINT   ?
    dwFlags                 DD     ?
    iFSTextEffect           DD     ?
    iFSTextEffectMSec       DD     ?
    iFSTextEffectColorBits  DD     ?
    iFSGrafEffect           DD     ?
    iFSGrafEffectMSec       DD     ?
    iFSGrafEffectColor      DD     ?
    iWindowsEffect          DD     ?
    iWindowsEffectMSec      DD     ?
    lpszWindowsEffectDLL    LPTSTR ?
    iWindowsEffectOrdinal   DD     ?
SOUNDSENTRYA ENDS

SOUNDSENTRYW STRUCT ALIGNMODE
    cbSize                  UINT   ?
    dwFlags                 DD     ?
    iFSTextEffect           DD     ?
    iFSTextEffectMSec       DD     ?
    iFSTextEffectColorBits  DD     ?
    iFSGrafEffect           DD     ?
    iFSGrafEffectMSec       DD     ?
    iFSGrafEffectColor      DD     ?
    iWindowsEffect          DD     ?
    iWindowsEffectMSec      DD     ?
    lpszWindowsEffectDLL    LPWSTR ?
    iWindowsEffectOrdinal   DD     ?
SOUNDSENTRYW ENDS

MONITORINFO STRUCT ALIGNMODE
    cbSize      DD  ?
    rcMonitor   RECT <>
    rcWork      RECT <>
    dwFlags     DD  ?
MONITORINFO ENDS

MONITORINFOEXA STRUCT ALIGNMODE
    cbSize      DD   ?
    rcMonitor   RECT <>
    rcWork      RECT <>
    dwFlags     DD   ?
    szDevice    DB   CCHDEVICENAME DUP(?)
MONITORINFOEXA ENDS

MONITORINFOEXW STRUCT ALIGNMODE
    cbSize      DD   ?
    rcMonitor   RECT <>
    rcWork      RECT <>
    dwFlags     DD   ?
    szDevice    DW   CCHDEVICENAME DUP(?)
MONITORINFOEXW ENDS

GUITHREADINFO STRUCT ALIGNMODE
    cbSize          DD   ?
    flags           DD   ?
    hwndActive      HWND ?
    hwndFocus       HWND ?
    hwndCapture     HWND ?
    hwndMenuOwner   HWND ?
    hwndMoveSize    HWND ?
    hwndCaret       HWND ?
    rcCaret         RECT <>
GUITHREADINFO ENDS

CURSORINFO STRUCT ALIGNMODE
    cbSize      DD      ?
    flags       DD      ?
    hCursor     HCURSOR ?
    ptScreenPos POINT   <>
CURSORINFO ENDS

WINDOWINFO STRUCT ALIGNMODE
    cbSize          DD   ?
    rcWindow        RECT <>
    rcClient        RECT <>
    dwStyle         DD   ?
    dwExStyle       DD   ?
    dwOtherStuff    DD   ?
    cxWindowBorders UINT ?
    cyWindowBorders UINT ?
    atomWindowType  ATOM ?
    wCreatorVersion DW   ?
WINDOWINFO ENDS

TITLEBARINFO STRUCT ALIGNMODE
    cbSize      DD   ?
    rcTitleBar  RECT <>
    rgstate     DD (CCHILDREN_TITLEBAR + 1) DUP(?)
TITLEBARINFO ENDS

TITLEBARINFOEX STRUCT ALIGNMODE
    cbSize      DD   ?
    rcTitleBar  RECT <>
    rgstate     DD   (CCHILDREN_TITLEBAR + 1) DUP(?)
    rgrect      RECT (CCHILDREN_TITLEBAR + 1) DUP(<>)
TITLEBARINFOEX ENDS

MENUBARINFO STRUCT ALIGNMODE
    cbSize      DD    ?
    rcBar       RECT  <>
    hMenu       HMENU ?
    hwndMenu    HWND  ?
    fBarFocused BOOL  ?
    fFocused    BOOL  ?
MENUBARINFO ENDS

SCROLLBARINFO STRUCT ALIGNMODE
    cbSize        DD   ?
    rcScrollBar   RECT <>
    dxyLineButton DD   ?
    xyThumbTop    DD   ?
    xyThumbBottom DD   ?
    bogus         DD   ?
    rgstate       DD   (CCHILDREN_SCROLLBAR + 1) DUP(?)
SCROLLBARINFO ENDS

COMBOBOXINFO STRUCT ALIGNMODE
    cbSize      DD   ?
    rcItem      RECT <>
    rcButton    RECT <>
    stateButton DD   ?
    hwndCombo   HWND ?
    hwndItem    HWND ?
    hwndList    HWND ?
COMBOBOXINFO ENDS

ALTTABINFO STRUCT ALIGNMODE
    cbSize    DD    ?
    cItems    DD    ?
    cColumns  DD    ?
    cRows     DD    ?
    iColFocus DD    ?
    iRowFocus DD    ?
    cxItem    DD    ?
    cyItem    DD    ?
    ptStart   POINT <>
ALTTABINFO ENDS

TOUCHINPUT STRUCT ALIGNMODE
    x           LONG      ?
    y           LONG      ?
    hSource     HANDLE    ?
    dwID        DD        ?
    dwFlags     DD        ?
    dwMask      DD        ?
    dwTime      DD        ?
    dwExtraInfo ULONG_PTR ?
    cxContact   DD        ?
    cyContact   DD        ?
TOUCHINPUT ENDS

POINTER_INFO STRUCT ALIGNMODE
    pointerType            ENUM   ?
    pointerId              UINT32 ?
    frameId                UINT32 ?
    pointerFlags           ENUM   ?
    sourceDevice           HANDLE ?
    hwndTarget             HWND   ?
    ptPixelLocation        POINT  <>
    ptHimetricLocation     POINT  <>
    ptPixelLocationRaw     POINT  <>
    ptHimetricLocationRaw  POINT  <>
    dwTime                 DD     ?
    historyCount           UINT32 ?
    InputData              INT32  ?
    dwKeyStates            DD     ?
    PerformanceCount       UINT64 ?
    ButtonChangeType       ENUM   ?
POINTER_INFO ENDS

POINTER_TOUCH_INFO STRUCT ALIGNMODE
    pointerInfo  POINTER_INFO <>
    touchFlags   ENUM   ?
    touchMask    ENUM   ?
    rcContact    RECT   <>
    rcContactRaw RECT   <>
    orientation  UINT32 ?
    pressure     UINT32 ?
POINTER_TOUCH_INFO ENDS

POINTER_PEN_INFO STRUCT ALIGNMODE
    pointerInfo POINTER_INFO <>
    penFlags    ENUM   ?
    penMask     ENUM   ?
    pressure    UINT32 ?
    rotation    UINT32 ?
    tiltX       INT32  ?
    tiltY       INT32  ?
POINTER_PEN_INFO ENDS

TOUCH_HIT_TESTING_PROXIMITY_EVALUATION STRUCT ALIGNMODE
    score         UINT16 ?
    adjustedPoint POINT  <>
TOUCH_HIT_TESTING_PROXIMITY_EVALUATION ENDS

TOUCH_HIT_TESTING_INPUT STRUCT ALIGNMODE
    pointerId               UINT32 ?
    point                   POINT  <>
    boundingBox             RECT   <>
    nonOccludedBoundingBox  RECT   <>
    orientation             UINT32 ?
TOUCH_HIT_TESTING_INPUT ENDS

CHANGEFILTERSTRUCT STRUCT ALIGNMODE
    cbSize    DD  ?
    ExtStatus DD  ?
CHANGEFILTERSTRUCT ENDS

GESTUREINFO STRUCT ALIGNMODE
    cbSize       UINT   ?
    dwFlags      DD     ?
    dwID         DD     ?
    hwndTarget   HWND   ?
    ptsLocation  POINTS <>
    dwInstanceID DD     ?
    dwSequenceID DD     ?
    ullArguments ULONGLONG ?
    cbExtraArgs  UINT   ?
GESTUREINFO ENDS

GESTURENOTIFYSTRUCT STRUCT ALIGNMODE
    cbSize       UINT   ?
    dwFlags      DD     ?
    hwndTarget   HWND   ?
    ptsLocation  POINTS <>
    dwInstanceID DD     ?
GESTURENOTIFYSTRUCT ENDS

GESTURECONFIG STRUCT ALIGNMODE
    dwID    DD  ?
    dwWant  DD  ?
    dwBlock DD  ?
GESTURECONFIG ENDS


;======================================== Functions =======================================;
ActivateKeyboardLayout PROTO :HKL, :XWORD
AdjustWindowRect PROTO :XPTR, :XWORD, :XWORD
AdjustWindowRectEx PROTO :XPTR, :XWORD, :XWORD, :XWORD
AnyPopup PROTO
AppendMenuA PROTO :HMENU, :XWORD, :UINT_PTR, :LPCTSTR
AppendMenuW PROTO :HMENU, :XWORD, :UINT_PTR, :LPCWSTR
ArrangeIconicWindows PROTO :HWND
AttachThreadInput PROTO :XWORD, :XWORD, :XWORD
BeginDeferWindowPos PROTO :XWORD
BeginPaint PROTO :HWND, :XPTR
BringWindowToTop PROTO :HWND
IF (NTDDI_VERSION EQ NTDDI_WIN95)
    BroadcastSystemMessage PROTO :XWORD, :LPDWORD, :XWORD, :WPARAM, :LPARAM
    GetAltTabInfo PROTO :HWND, :XWORD, :XPTR, :LPTSTR, :XWORD
    RealGetWindowClass PROTO :HWND, :LPTSTR, :XWORD
ELSE
    BroadcastSystemMessageA PROTO :XWORD, :LPDWORD, :XWORD, :WPARAM, :LPARAM
    BroadcastSystemMessageW PROTO :XWORD, :LPDWORD, :XWORD, :WPARAM, :LPARAM
    GetAltTabInfoA PROTO :HWND, :XWORD, :XPTR, :LPTSTR, :XWORD
    GetAltTabInfoW PROTO :HWND, :XWORD, :XPTR, :LPWSTR, :XWORD
    RealGetWindowClassA PROTO :HWND, :LPTSTR, :XWORD
    RealGetWindowClassW PROTO :HWND, :LPWSTR, :XWORD
    IFDEF APP_UNICODE
        BroadcastSystemMessage EQU <BroadcastSystemMessageW>
        GetAltTabInfo EQU <GetAltTabInfoW>
        RealGetWindowClass EQU <RealGetWindowClassW>
    ELSE
        BroadcastSystemMessage EQU <BroadcastSystemMessageA>
        GetAltTabInfo EQU <GetAltTabInfoA>
        RealGetWindowClass EQU <RealGetWindowClassA>
    ENDIF
ENDIF
CallMsgFilter PROTO :XPTR, :XWORD
CallMsgFilterA PROTO :XPTR, :XWORD
CallMsgFilterW PROTO :XPTR, :XWORD
CallNextHookEx PROTO :HHOOK, :XWORD, :WPARAM, :LPARAM
CallWindowProcA PROTO :WNDPROC, :HWND, :XWORD, :WPARAM, :LPARAM
CallWindowProcW PROTO :WNDPROC, :HWND, :XWORD, :WPARAM, :LPARAM
CascadeChildWindows PROTO :HWND, :XWORD
CascadeWindows PROTO :HWND, :XWORD, :XPTR, :XWORD, :XPTR
ChangeClipboardChain PROTO :HWND, :HWND
ChangeDisplaySettingsA PROTO :XPTR, :XWORD
ChangeDisplaySettingsW PROTO :XPTR, :XWORD
ChangeMenuA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
ChangeMenuW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CharLowerA PROTO :LPTSTR
CharLowerBuffA PROTO :LPTSTR, :XWORD
CharLowerBuffW PROTO :LPWSTR, :XWORD
CharLowerW PROTO :LPWSTR
CharNextA PROTO :LPCTSTR
CharNextExA PROTO :XWORD, :LPCSTR, :XWORD
CharNextW PROTO :LPCWSTR
CharPrevA PROTO :LPCTSTR, :LPCTSTR
CharPrevExA PROTO :XWORD, :LPCTSTR, :LPCTSTR, :XWORD
CharPrevW PROTO :LPCWSTR, :LPCWSTR
CharToOemA PROTO :LPCTSTR, :LPSTR
CharToOemBuffA PROTO :LPCTSTR, :LPSTR, :XWORD
CharToOemBuffW PROTO :LPCWSTR, :LPWSTR, :XWORD
CharToOemW PROTO :LPCWSTR, :LPWSTR
CharUpperA PROTO :LPTSTR
CharUpperBuffA PROTO :LPTSTR, :XWORD
CharUpperBuffW PROTO :LPWSTR, :XWORD
CharUpperW PROTO :LPWSTR
CheckDlgButton PROTO :HWND, :XWORD, :XWORD
CheckMenuItem PROTO :HMENU, :XWORD, :XWORD
CheckMenuRadioItem PROTO :HMENU, :XWORD, :XWORD, :XWORD, :XWORD
CheckRadioButton PROTO :HWND, :XWORD, :XWORD, :XWORD
ChildWindowFromPoint PROTO :HWND, :XWORD, :XWORD
ChildWindowFromPointEx PROTO :HWND, :XWORD, :XWORD, :XWORD
ClientToScreen PROTO :HWND, :XPTR
ClipCursor PROTO :XPTR
CloseClipboard PROTO
CloseDesktop PROTO :HDESK
CloseWindow PROTO :HWND
CloseWindowStation PROTO :HWINSTA
CopyAcceleratorTableA PROTO :HACCEL, :XPTR, :XWORD
CopyAcceleratorTableW PROTO :HACCEL, :XPTR, :XWORD
CopyIcon PROTO :HICON
CopyImage PROTO :HANDLE, :XWORD, :XWORD, :XWORD, :XWORD
CopyRect PROTO :XPTR, :XPTR
CountClipboardFormats PROTO
CreateAcceleratorTableA PROTO :XPTR, :XWORD
CreateAcceleratorTableW PROTO :XPTR, :XWORD
CreateCaret PROTO :HWND, :HBITMAP, :XWORD, :XWORD
CreateCursor PROTO :HINSTANCE, :XWORD, :XWORD, :XWORD, :XWORD, :XPTR, :XPTR
CreateDesktopA PROTO :LPCTSTR, :LPCTSTR, :XPTR, :XWORD, :XWORD, :XPTR
CreateDesktopW PROTO :LPCWSTR, :LPCWSTR, :XPTR, :XWORD, :XWORD, :XPTR
CreateDialogIndirectParamA PROTO :HINSTANCE, :XPTR, :HWND, :XPTR, :LPARAM
CreateDialogIndirectParamW PROTO :HINSTANCE, :XPTR, :HWND, :XPTR, :LPARAM
CreateDialogParamA PROTO :HINSTANCE, :LPCTSTR, :HWND, :XPTR, :LPARAM
CreateDialogParamW PROTO :HINSTANCE, :LPCWSTR, :HWND, :XPTR, :LPARAM
CreateIcon PROTO :HINSTANCE, :XWORD, :XWORD, :XWORD, :XWORD, :XPTR, :XPTR
CreateIconFromResource PROTO :XPTR, :XWORD, :XWORD, :XWORD
CreateIconFromResourceEx PROTO :XPTR, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
CreateIconIndirect PROTO :XPTR
CreateMDIWindowA PROTO :LPCTSTR, :LPCTSTR, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :HWND, :HINSTANCE, :LPARAM
CreateMDIWindowW PROTO :LPCWSTR, :LPCWSTR, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :HWND, :HINSTANCE, :LPARAM
CreateMenu PROTO
CreatePopupMenu PROTO
CreateWindowExA PROTO :XWORD, :LPCTSTR, :LPCTSTR, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :HWND, :HMENU, :HINSTANCE, :LPVOID
CreateWindowExW PROTO :XWORD, :LPCWSTR, :LPCWSTR, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :HWND, :HMENU, :HINSTANCE, :LPVOID
CreateWindowStationA PROTO :LPTSTR, :XWORD, :XWORD, :XPTR
CreateWindowStationW PROTO :LPWSTR, :XWORD, :XWORD, :XPTR
DdeAbandonTransaction PROTO :XWORD, :HCONV, :XWORD
DdeAccessData PROTO :HDDEDATA, :LPDWORD
DdeAddData PROTO :HDDEDATA, :XPTR, :XWORD, :XWORD
DdeClientTransaction PROTO :XPTR, :XWORD, :HCONV, :HSZ, :XWORD, :XWORD, :XWORD, :LPDWORD
DdeCmpStringHandles PROTO :HSZ, :HSZ
DdeConnect PROTO :XWORD, :HSZ, :HSZ, :XPTR
DdeConnectList PROTO :XWORD, :HSZ, :HSZ, :HCONVLIST, :XPTR
DdeCreateDataHandle PROTO :XWORD, :XPTR, :XWORD, :XWORD, :HSZ, :XWORD, :XWORD
DdeCreateStringHandleA PROTO :XWORD, :LPTSTR, :XWORD
DdeCreateStringHandleW PROTO :XWORD, :LPWSTR, :XWORD
DdeDisconnect PROTO :HCONV
DdeDisconnectList PROTO :HCONVLIST
DdeEnableCallback PROTO :XWORD, :HCONV, :XWORD
DdeFreeDataHandle PROTO :HDDEDATA
DdeFreeStringHandle PROTO :XWORD, :HSZ
DdeGetData PROTO :HDDEDATA, :XPTR, :XWORD, :XWORD
DdeGetLastError PROTO :XWORD
DdeImpersonateClient PROTO :HCONV
DdeInitializeA PROTO :LPDWORD, :XPTR, :XWORD, :XWORD
DdeInitializeW PROTO :LPDWORD, :XPTR, :XWORD, :XWORD
DdeKeepStringHandle PROTO :XWORD, :HSZ
DdeNameService PROTO :XWORD, :HSZ, :HSZ, :XWORD
DdePostAdvise PROTO :XWORD, :HSZ, :HSZ
DdeQueryConvInfo PROTO :HCONV, :XWORD, :XPTR
DdeQueryNextServer PROTO :HCONVLIST, :HCONV
DdeQueryStringA PROTO :XWORD, :HSZ, :LPTSTR, :XWORD, :XWORD
DdeQueryStringW PROTO :XWORD, :HSZ, :LPWSTR, :XWORD, :XWORD
DdeReconnect PROTO :HCONV
DdeSetQualityOfService PROTO :HWND, :XPTR, :XPTR
DdeSetUserHandle PROTO :HCONV, :XWORD, :DWORD_PTR
DdeUnaccessData PROTO :HDDEDATA
DdeUninitialize PROTO :XWORD
DefDlgProcA PROTO :HWND, :XWORD, :WPARAM, :LPARAM
DefDlgProcW PROTO :HWND, :XWORD, :WPARAM, :LPARAM
DeferWindowPos PROTO :HDWP, :HWND, :HWND, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
DefFrameProcA PROTO :HWND, :HWND, :XWORD, :WPARAM, :LPARAM
DefFrameProcW PROTO :HWND, :HWND, :XWORD, :WPARAM, :LPARAM
DefMDIChildProcA PROTO :HWND, :XWORD, :WPARAM, :LPARAM
DefMDIChildProcW PROTO :HWND, :XWORD, :WPARAM, :LPARAM
DefWindowProcA PROTO :HWND, :XWORD, :WPARAM, :LPARAM
DefWindowProcW PROTO :HWND, :XWORD, :WPARAM, :LPARAM
DeleteMenu PROTO :HMENU, :XWORD, :XWORD
DestroyAcceleratorTable PROTO :HACCEL
DestroyCaret PROTO
DestroyCursor PROTO :HCURSOR
DestroyIcon PROTO :HICON
DestroyMenu PROTO :HMENU
DestroyWindow PROTO :HWND
DialogBoxIndirectParamA PROTO :HINSTANCE, :XPTR, :HWND, :XPTR, :LPARAM
DialogBoxIndirectParamW PROTO :HINSTANCE, :XPTR, :HWND, :XPTR, :LPARAM
DialogBoxParamA PROTO :HINSTANCE, :LPCTSTR, :HWND, :XPTR, :LPARAM
DialogBoxParamW PROTO :HINSTANCE, :LPCWSTR, :HWND, :XPTR, :LPARAM
DispatchMessageA PROTO :XPTR
DispatchMessageW PROTO :XPTR
DlgDirListA PROTO :HWND, :LPTSTR, :XWORD, :XWORD, :XWORD
DlgDirListComboBoxA PROTO :HWND, :LPTSTR, :XWORD, :XWORD, :XWORD
DlgDirListComboBoxW PROTO :HWND, :LPWSTR, :XWORD, :XWORD, :XWORD
DlgDirListW PROTO :HWND, :LPWSTR, :XWORD, :XWORD, :XWORD
DlgDirSelectComboBoxExA PROTO :HWND, :LPTSTR, :XWORD, :XWORD
DlgDirSelectComboBoxExW PROTO :HWND, :LPWSTR, :XWORD, :XWORD
DlgDirSelectExA PROTO :HWND, :LPTSTR, :XWORD, :XWORD
DlgDirSelectExW PROTO :HWND, :LPWSTR, :XWORD, :XWORD
DragDetect PROTO :HWND, :XWORD, :XWORD
DragObject PROTO :HWND, :XWORD, :XWORD
DrawAnimatedRects PROTO :HWND, :XWORD, :XPTR, :XPTR
DrawCaption PROTO :HWND, :HDC, :XPTR, :XWORD
DrawCaptionTempA PROTO :HWND, :HDC, :XPTR, :HFONT, :HICON, :LPCTSTR, :XWORD
DrawCaptionTempW PROTO :HWND, :HDC, :XPTR, :HFONT, :HICON, :LPCWSTR, :XWORD
DrawEdge PROTO :HDC, :XPTR, :XWORD, :XWORD
DrawFocusRect PROTO :HDC, :XPTR
DrawFrame PROTO :XWORD, :XPTR, :XWORD, :XWORD
DrawFrameControl PROTO :HDC, :XPTR, :XWORD, :XWORD
DrawIcon PROTO :HDC, :XWORD, :XWORD, :HICON
DrawIconEx PROTO :HDC, :XWORD, :XWORD, :HICON, :XWORD, :XWORD, :XWORD, :HBRUSH, :XWORD
DrawMenuBar PROTO :HWND
DrawStateA PROTO :HDC, :HBRUSH, :XPTR, :LPARAM, :WPARAM, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
DrawStateW PROTO :HDC, :HBRUSH, :XPTR, :LPARAM, :WPARAM, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
DrawTextA PROTO :HDC, :LPCTSTR, :XWORD, :XPTR, :XWORD
DrawTextExA PROTO :HDC, :LPTSTR, :XWORD, :XPTR, :XWORD, :XPTR
DrawTextExW PROTO :HDC, :LPWSTR, :XWORD, :XPTR, :XWORD, :XPTR
DrawTextW PROTO :HDC, :LPCWSTR, :XWORD, :XPTR, :XWORD
EditWndProc PROTO :HWND, :XWORD, :WPARAM, :LPARAM
EmptyClipboard PROTO
EnableMenuItem PROTO :HMENU, :XWORD, :XWORD
EnableScrollBar PROTO :HWND, :XWORD, :XWORD
EnableWindow PROTO :HWND, :XWORD
EndDeferWindowPos PROTO :HDWP
EndDialog PROTO :HWND, :INT_PTR
EndPaint PROTO :HWND, :XPTR
EndTask PROTO :HWND, :XWORD, :XWORD
EnumChildWindows PROTO :HWND, :XPTR, :LPARAM
EnumClipboardFormats PROTO :XWORD
EnumDesktopsA PROTO :HWINSTA, :XPTR, :LPARAM
EnumDesktopsW PROTO :HWINSTA, :XPTR, :LPARAM
EnumDesktopWindows PROTO :HDESK, :XPTR, :LPARAM
EnumDisplayDevicesA PROTO :LPCTSTR, :XWORD, :XPTR, :XWORD
EnumDisplayDevicesW PROTO :LPCWSTR, :XWORD, :XPTR, :XWORD
EnumDisplaySettingsA PROTO :LPCTSTR, :XWORD, :XPTR
EnumDisplaySettingsW PROTO :LPCWSTR, :XWORD, :XPTR
EnumPropsA PROTO :HWND, :XPTR
EnumPropsExA PROTO :HWND, :XPTR, :LPARAM
EnumPropsExW PROTO :HWND, :XPTR, :LPARAM
EnumPropsW PROTO :HWND, :XPTR
EnumThreadWindows PROTO :XWORD, :XPTR, :LPARAM
EnumWindows PROTO :XPTR, :LPARAM
EnumWindowStationsA PROTO :XPTR, :LPARAM
EnumWindowStationsW PROTO :XPTR, :LPARAM
EqualRect PROTO :XPTR, :XPTR
ExcludeUpdateRgn PROTO :HDC, :HWND
ExitWindowsEx PROTO :XWORD, :XWORD
FillRect PROTO :HDC, :XPTR, :HBRUSH
FindWindowA PROTO :LPCTSTR, :LPCTSTR
FindWindowExA PROTO :HWND, :HWND, :LPCTSTR, :LPCTSTR
FindWindowExW PROTO :HWND, :HWND, :LPCWSTR, :LPCWSTR
FindWindowW PROTO :LPCWSTR, :LPCWSTR
FlashWindow PROTO :HWND, :XWORD
FrameRect PROTO :HDC, :XPTR, :HBRUSH
FreeDDElParam PROTO :XWORD, :LPARAM
GetActiveWindow PROTO
GetAsyncKeyState PROTO :XWORD
GetCapture PROTO
GetCaretBlinkTime PROTO
GetCaretPos PROTO :XPTR
GetClassInfoA PROTO :HINSTANCE, :LPCTSTR, :XPTR
GetClassInfoExA PROTO :HINSTANCE, :LPCTSTR, :XPTR
GetClassInfoExW PROTO :HINSTANCE, :LPCWSTR, :XPTR
GetClassInfoW PROTO :HINSTANCE, :LPCWSTR, :XPTR
GetClassLongA PROTO :HWND, :XWORD
GetClassLongW PROTO :HWND, :XWORD
GetClassNameA PROTO :HWND, :LPTSTR, :XWORD
GetClassNameW PROTO :HWND, :LPWSTR, :XWORD
GetClassWord PROTO :HWND, :XWORD
GetClientRect PROTO :HWND, :XPTR
GetClipboardData PROTO :XWORD
GetClipboardFormatNameA PROTO :XWORD, :LPTSTR, :XWORD
GetClipboardFormatNameW PROTO :XWORD, :LPWSTR, :XWORD
GetClipboardOwner PROTO
GetClipboardViewer PROTO
GetClipCursor PROTO :XPTR, :XWORD
GetCursor PROTO
GetCursorPos PROTO :XPTR
GetDC PROTO :HWND
GetDCEx PROTO :HWND, :HRGN, :XWORD
GetDesktopWindow PROTO
GetDialogBaseUnits PROTO
GetDlgCtrlID PROTO :HWND
GetDlgItem PROTO :HWND, :XWORD
GetDlgItemInt PROTO :HWND, :XWORD, :XWORD, :XWORD
GetDlgItemTextA PROTO :HWND, :XWORD, :LPTSTR, :XWORD
GetDlgItemTextW PROTO :HWND, :XWORD, :LPWSTR, :XWORD
GetDoubleClickTime PROTO
GetFocus PROTO
GetForegroundWindow PROTO
IF (NTDDI_VERSION NE NTDDI_WIN95 AND NTDDI_VERSION NE NTDDI_WINNT4)
    GetGuiResources PROTO :HANDLE, :XWORD
ENDIF
GetIconInfo PROTO :HICON, :XPTR
GetInputDesktop PROTO
GetInputState PROTO
GetInternalWindowPos PROTO :HWND, :XPTR, :XPTR
GetKBCodePage PROTO
GetKeyboardLayout PROTO :XWORD
GetKeyboardLayoutList PROTO :XWORD, :XPTR
GetKeyboardLayoutNameA PROTO :LPTSTR
GetKeyboardLayoutNameW PROTO :LPWSTR
GetKeyboardState PROTO :XPTR
GetKeyboardType PROTO :XWORD
GetKeyNameTextA PROTO :XWORD, :LPTSTR, :XWORD
GetKeyNameTextW PROTO :XWORD, :LPWSTR, :XWORD
GetKeyState PROTO :XWORD
GetLastActivePopup PROTO :HWND
GetMenu PROTO :HWND
GetMenuCheckMarkDimensions PROTO
GetMenuContextHelpId PROTO :HMENU
GetMenuDefaultItem PROTO :HMENU, :XWORD, :XWORD
GetMenuItemCount PROTO :HMENU
GetMenuItemID PROTO :HMENU, :XWORD
GetMenuItemInfoA PROTO :HMENU, :XWORD, :XWORD, :XPTR
GetMenuItemInfoW PROTO :HMENU, :XWORD, :XWORD, :XPTR
GetMenuItemRect PROTO :HWND, :HMENU, :XWORD, :XPTR
GetMenuState PROTO :HMENU, :XWORD, :XWORD
GetMenuStringA PROTO :HMENU, :XWORD, :LPTSTR, :XWORD, :XWORD
GetMenuStringW PROTO :HMENU, :XWORD, :LPWSTR, :XWORD, :XWORD
GetMessageA PROTO :XPTR, :HWND, :XWORD, :XWORD
GetMessageExtraInfo PROTO
GetMessagePos PROTO
GetMessageTime PROTO
GetMessageW PROTO :XPTR, :HWND, :XWORD, :XWORD
GetNextDlgGroupItem PROTO :HWND, :HWND, :XWORD
GetNextDlgTabItem PROTO :HWND, :HWND, :XWORD
GetOpenClipboardWindow PROTO
GetParent PROTO :HWND
GetPriorityClipboardFormat PROTO :XPTR, :XWORD
GetProcessWindowStation PROTO
GetPropA PROTO :HWND, :LPCTSTR
GetPropW PROTO :HWND, :LPCWSTR
GetQueueStatus PROTO :XWORD
GetScrollInfo PROTO :HWND, :XWORD, :XPTR
GetScrollPos PROTO :HWND, :XWORD
GetScrollRange PROTO :HWND, :XWORD, :XPTR, :XPTR
GetShellWindow PROTO
GetSubMenu PROTO :HMENU, :XWORD
GetSysColor PROTO :XWORD
GetSysColorBrush PROTO :XWORD
GetSystemMenu PROTO :HWND, :XWORD
GetSystemMetrics PROTO :XWORD
GetTabbedTextExtentA PROTO :HDC, :LPCTSTR, :XWORD, :XWORD, :XPTR
GetTabbedTextExtentW PROTO :HDC, :LPCWSTR, :XWORD, :XWORD, :XPTR
GetThreadDesktop PROTO :XWORD
GetTopWindow PROTO :HWND
GetUpdateRect PROTO :HWND, :XPTR, :XWORD
GetUpdateRgn PROTO :HWND, :HRGN, :XWORD
GetUserObjectInformationA PROTO :HANDLE, :XWORD, :PVOID, :XWORD, :XPTR
GetUserObjectInformationW PROTO :HANDLE, :XWORD, :PVOID, :XWORD, :XPTR
GetUserObjectSecurity PROTO :HANDLE, :XPTR, :XPTR, :XWORD, :XPTR
GetWindow PROTO :HWND, :XWORD
GetWindowContextHelpId PROTO :HWND
GetWindowDC PROTO :HWND
GetWindowLongA PROTO :HWND, :XWORD
GetWindowLongW PROTO :HWND, :XWORD
GetWindowPlacement PROTO :HWND, :XPTR
GetWindowRect PROTO :HWND, :XPTR
GetWindowRgn PROTO :HWND, :HRGN
GetWindowTextA PROTO :HWND, :LPTSTR, :XWORD
GetWindowTextLengthA PROTO :HWND
GetWindowTextLengthW PROTO :HWND
GetWindowTextW PROTO :HWND, :LPWSTR, :XWORD
GetWindowThreadProcessId PROTO :HWND, :LPDWORD
GetWindowWord PROTO :HWND, :XWORD
GrayStringA PROTO :HDC, :HBRUSH, :XPTR, :LPARAM, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
GrayStringW PROTO :HDC, :HBRUSH, :XPTR, :LPARAM, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
HideCaret PROTO :HWND
HiliteMenuItem PROTO :HWND, :HMENU, :XWORD, :XWORD
ImpersonateDdeClientWindow PROTO :HWND, :HWND
InflateRect PROTO :XPTR, :XWORD, :XWORD
InSendMessage PROTO
InsertMenuA PROTO :HMENU, :XWORD, :XWORD, :UINT_PTR, :LPCTSTR
InsertMenuItemA PROTO :HMENU, :XWORD, :XWORD, :XPTR
InsertMenuItemW PROTO :HMENU, :XWORD, :XWORD, :XPTR
InsertMenuW PROTO :HMENU, :XWORD, :XWORD, :UINT_PTR, :LPCWSTR
InternalGetWindowText PROTO :HWND, :LPWSTR, :XWORD
IntersectRect PROTO :XPTR, :XPTR, :XPTR
InvalidateRect PROTO :HWND, :XPTR, :XWORD
InvalidateRgn PROTO :HWND, :HRGN, :XWORD
InvertRect PROTO :HDC, :XPTR
IsCharAlphaA PROTO :XWORD
IsCharAlphaNumericA PROTO :XWORD
IsCharAlphaNumericW PROTO :XWORD
IsCharAlphaW PROTO :XWORD
IsCharLowerA PROTO :XWORD
IsCharLowerW PROTO :XWORD
IsCharUpperA PROTO :XWORD
IsCharUpperW PROTO :XWORD
IsChild PROTO :HWND, :HWND
IsClipboardFormatAvailable PROTO :XWORD
IsDialogMessage PROTO :HWND, :XPTR
IsDialogMessageA PROTO :HWND, :XPTR
IsDialogMessageW PROTO :HWND, :XPTR
IsDlgButtonChecked PROTO :HWND, :XWORD
IsIconic PROTO :HWND
IsMenu PROTO :HMENU
IsRectEmpty PROTO :XPTR
IsWindow PROTO :HWND
IsWindowEnabled PROTO :HWND
IsWindowUnicode PROTO :HWND
IsWindowVisible PROTO :HWND
IsZoomed PROTO :HWND
KillTimer PROTO :HWND, :UINT_PTR
LoadAcceleratorsA PROTO :HINSTANCE, :LPCTSTR
LoadAcceleratorsW PROTO :HINSTANCE, :LPCWSTR
LoadBitmapA PROTO :HINSTANCE, :LPCTSTR
LoadBitmapW PROTO :HINSTANCE, :LPCWSTR
LoadCursorA PROTO :HINSTANCE, :LPCTSTR
LoadCursorFromFileA PROTO :LPCTSTR
LoadCursorFromFileW PROTO :LPCWSTR
LoadCursorW PROTO :HINSTANCE, :LPCWSTR
LoadIconA PROTO :HINSTANCE, :LPCTSTR
LoadIconW PROTO :HINSTANCE, :LPCWSTR
LoadImageA PROTO :HINSTANCE, :LPCTSTR, :XWORD, :XWORD, :XWORD, :XWORD
LoadImageW PROTO :HINSTANCE, :LPCWSTR, :XWORD, :XWORD, :XWORD, :XWORD
LoadKeyboardLayoutA PROTO :LPCTSTR, :XWORD
LoadKeyboardLayoutW PROTO :LPCWSTR, :XWORD
LoadMenuA PROTO :HINSTANCE, :LPCTSTR
LoadMenuIndirectA PROTO :XPTR
LoadMenuIndirectW PROTO :XPTR
LoadMenuW PROTO :HINSTANCE, :LPCWSTR
LoadStringA PROTO :HINSTANCE, :XWORD, :LPTSTR, :XWORD
LoadStringW PROTO :HINSTANCE, :XWORD, :LPWSTR, :XWORD
LockWindowStation PROTO :HWINSTA
LockWindowUpdate PROTO :HWND
LookupIconIdFromDirectory PROTO :XPTR, :XWORD
LookupIconIdFromDirectoryEx PROTO :XPTR, :XWORD, :XWORD, :XWORD, :XWORD
MapDialogRect PROTO :HWND, :XPTR
MapVirtualKeyA PROTO :XWORD, :XWORD
MapVirtualKeyExA PROTO :XWORD, :XWORD, :HKL
MapVirtualKeyExW PROTO :XWORD, :XWORD, :HKL
MapVirtualKeyW PROTO :XWORD, :XWORD
MapWindowPoints PROTO :HWND, :HWND, :XPTR, :XWORD
MenuItemFromPoint PROTO :HWND, :HMENU, :XWORD, :XWORD
MessageBeep PROTO :XWORD
MessageBoxA PROTO :HWND, :LPCTSTR, :LPCTSTR, :XWORD
MessageBoxExA PROTO :HWND, :LPCTSTR, :LPCTSTR, :XWORD, :XWORD
MessageBoxExW PROTO :HWND, :LPCWSTR, :LPCWSTR, :XWORD, :XWORD
MessageBoxIndirectA PROTO :XPTR
MessageBoxIndirectW PROTO :XPTR
MessageBoxW PROTO :HWND, :LPCWSTR, :LPCWSTR, :XWORD
ModifyMenuA PROTO :HMENU, :XWORD, :XWORD, :UINT_PTR, :LPCTSTR
ModifyMenuW PROTO :HMENU, :XWORD, :XWORD, :UINT_PTR, :LPCWSTR
MoveWindow PROTO :HWND, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
MsgWaitForMultipleObjects PROTO :XWORD, :XPTR, :XWORD, :XWORD, :XWORD
OemKeyScan PROTO :XWORD
OemToCharA PROTO :LPCSTR, :LPTSTR
OemToCharBuffA PROTO :LPCTSTR, :LPTSTR, :XWORD
OemToCharBuffW PROTO :LPCWSTR, :LPWSTR, :XWORD
OemToCharW PROTO :LPWSTR, :LPWSTR
OffsetRect PROTO :XPTR, :XWORD, :XWORD
OpenClipboard PROTO :HWND
OpenDesktopA PROTO :LPTSTR, :XWORD, :XWORD, :XWORD
OpenDesktopW PROTO :LPWSTR, :XWORD, :XWORD, :XWORD
OpenIcon PROTO :HWND
OpenInputDesktop PROTO :XWORD, :XWORD, :XWORD
OpenWindowStationA PROTO :LPTSTR, :XWORD, :XWORD
OpenWindowStationW PROTO :LPWSTR, :XWORD, :XWORD
PackDDElParam PROTO :XWORD, :UINT_PTR, :UINT_PTR
PaintDesktop PROTO :HDC
PeekMessageA PROTO :XPTR, :HWND, :XWORD, :XWORD, :XWORD
PeekMessageW PROTO :XPTR, :HWND, :XWORD, :XWORD, :XWORD
PostMessageA PROTO :HWND, :XWORD, :WPARAM, :LPARAM
PostMessageW PROTO :HWND, :XWORD, :WPARAM, :LPARAM
PostQuitMessage PROTO :XWORD
PostThreadMessageA PROTO :XWORD, :XWORD, :WPARAM, :LPARAM
PostThreadMessageW PROTO :XWORD, :XWORD, :WPARAM, :LPARAM
PtInRect PROTO :XPTR, :XPTR
RedrawWindow PROTO :HWND, :XPTR, :HRGN, :XWORD
RegisterClassA PROTO :XPTR
RegisterClassExA PROTO :XPTR
RegisterClassExW PROTO :XPTR
RegisterClassW PROTO :XPTR
RegisterClipboardFormatA PROTO :LPCTSTR
RegisterClipboardFormatW PROTO :LPCWSTR
RegisterHotKey PROTO :HWND, :XWORD, :XWORD, :XWORD
RegisterLogonProcess PROTO :HANDLE, :XWORD
RegisterSystemThread PROTO :XWORD, :XWORD
RegisterTasklist PROTO :XWORD
RegisterWindowMessageA PROTO :LPCTSTR
RegisterWindowMessageW PROTO :LPCWSTR
ReleaseCapture PROTO
ReleaseDC PROTO :HWND, :HDC
RemoveMenu PROTO :HMENU, :XWORD, :XWORD
RemovePropA PROTO :HWND, :LPCTSTR
RemovePropW PROTO :HWND, :LPCWSTR
ReplyMessage PROTO :LRESULT
ReuseDDElParam PROTO :LPARAM, :XWORD, :XWORD, :UINT_PTR, :UINT_PTR
ScreenToClient PROTO :HWND, :XPTR
ScrollDC PROTO :HDC, :XWORD, :XWORD, :XPTR, :XPTR, :HRGN, :XPTR
ScrollWindow PROTO :HWND, :XWORD, :XWORD, :XPTR, :XPTR
ScrollWindowEx PROTO :HWND, :XWORD, :XWORD, :XPTR, :XPTR, :HRGN, :XPTR, :XWORD
SendDlgItemMessageA PROTO :HWND, :XWORD, :XWORD, :WPARAM, :LPARAM
SendDlgItemMessageW PROTO :HWND, :XWORD, :XWORD, :WPARAM, :LPARAM
SendMessageA PROTO :HWND, :XWORD, :WPARAM, :LPARAM
SendMessageCallbackA PROTO :HWND, :XWORD, :WPARAM, :LPARAM, :XPTR, :ULONG_PTR
SendMessageCallbackW PROTO :HWND, :XWORD, :WPARAM, :LPARAM, :XPTR, :ULONG_PTR
SendMessageTimeoutA PROTO :HWND, :XWORD, :WPARAM, :LPARAM, :XWORD, :XWORD, :LPDWORD
SendMessageTimeoutW PROTO :HWND, :XWORD, :WPARAM, :LPARAM, :XWORD, :XWORD, :LPDWORD
SendMessageW PROTO :HWND, :XWORD, :WPARAM, :LPARAM
SendNotifyMessageA PROTO :HWND, :XWORD, :WPARAM, :LPARAM
SendNotifyMessageW PROTO :HWND, :XWORD, :WPARAM, :LPARAM
SetActiveWindow PROTO :HWND
SetCapture PROTO :HWND
SetCaretBlinkTime PROTO :XWORD
SetCaretPos PROTO :XWORD, :XWORD
SetClassLongA PROTO :HWND, :XWORD, :XWORD
SetClassLongW PROTO :HWND, :XWORD, :XWORD
SetClassWord PROTO :HWND, :XWORD, :XWORD
SetClipboardData PROTO :XWORD, :HANDLE
SetClipboardViewer PROTO :HWND
SetCursor PROTO :HCURSOR
SetCursorPos PROTO :XWORD, :XWORD
SetDebugErrorLevel PROTO :XWORD
SetDlgItemInt PROTO :HWND, :XWORD, :XWORD, :XWORD
SetDlgItemTextA PROTO :HWND, :XWORD, :LPCTSTR
SetDlgItemTextW PROTO :HWND, :XWORD, :LPCWSTR
SetDoubleClickTime PROTO :XWORD
SetFocus PROTO :HWND
SetForegroundWindow PROTO :HWND
SetInternalWindowPos PROTO :HWND, :XWORD, :XPTR, :XPTR
SetKeyboardState PROTO :LPBYTE
SetLastErrorEx PROTO :XWORD, :XWORD
SetMenu PROTO :HWND, :HMENU
SetMenuContextHelpId PROTO :HMENU, :XWORD
SetMenuDefaultItem PROTO :HMENU, :XWORD, :XWORD
SetMenuItemBitmaps PROTO :HMENU, :XWORD, :XWORD, :HBITMAP, :HBITMAP
SetMenuItemInfoA PROTO :HMENU, :XWORD, :XWORD, :XPTR
SetMenuItemInfoW PROTO :HMENU, :XWORD, :XWORD, :XPTR
SetMessageExtraInfo PROTO :LPARAM
SetMessageQueue PROTO :XPTR
SetParent PROTO :HWND, :HWND
SetProcessWindowStation PROTO :HWINSTA
SetPropA PROTO :HWND, :LPCTSTR, :HANDLE
SetPropW PROTO :HWND, :LPCWSTR, :HANDLE
SetRect PROTO :XPTR, :XWORD, :XWORD, :XWORD, :XWORD
SetRectEmpty PROTO :XPTR
SetScrollInfo PROTO :HWND, :XWORD, :XPTR, :XWORD
SetScrollPos PROTO :HWND, :XWORD, :XWORD, :XWORD
SetScrollRange PROTO :HWND, :XWORD, :XWORD, :XWORD, :XWORD
SetShellWindow PROTO :HWND
SetSysColors PROTO :XWORD, :XPTR, :XPTR
SetSysColorsTemp PROTO :XPTR, :XPTR, :XWORD
SetSystemCursor PROTO :HCURSOR, :XWORD
SetThreadDesktop PROTO :HDESK
SetTimer PROTO :HWND, :UINT_PTR, :XWORD, :XPTR
SetUserObjectInformationA PROTO :HANDLE, :XWORD, :PVOID, :XWORD
SetUserObjectInformationW PROTO :HANDLE, :XWORD, :PVOID, :XWORD
SetUserObjectSecurity PROTO :HANDLE, :XPTR, :XPTR
SetWindowContextHelpId PROTO :HWND, :XWORD
SetWindowLongA PROTO :HWND, :XWORD, :XWORD
SetWindowLongW PROTO :HWND, :XWORD, :XWORD
SetWindowPlacement PROTO :HWND, :XPTR
SetWindowPos PROTO :HWND, :HWND, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
SetWindowRgn PROTO :HWND, :HRGN, :XWORD
SetWindowsHookA PROTO :XWORD, :XPTR, :HINSTANCE, :XWORD
SetWindowsHookExA PROTO :XWORD, :XPTR, :HINSTANCE, :XWORD
SetWindowsHookExW PROTO :XWORD, :XPTR, :HINSTANCE, :XWORD
SetWindowsHookW PROTO :XWORD, :XPTR, :HINSTANCE, :XWORD
SetWindowTextA PROTO :HWND, :LPCTSTR
SetWindowTextW PROTO :HWND, :LPCWSTR
SetWindowWord PROTO :HWND, :XWORD, :XWORD
ShowCaret PROTO :HWND
ShowCursor PROTO :XWORD
ShowOwnedPopups PROTO :HWND, :XWORD
ShowScrollBar PROTO :HWND, :XWORD, :XWORD
ShowWindow PROTO :HWND, :XWORD
ShowWindowAsync PROTO :HWND, :XWORD
SubtractRect PROTO :XPTR, :XPTR, :XPTR
SwapMouseButton PROTO :XWORD
SwitchDesktop PROTO :HDESK
SwitchToThisWindow PROTO :HWND, :XWORD
SystemParametersInfoA PROTO :XWORD, :XWORD, :PVOID, :XWORD
SystemParametersInfoW PROTO :XWORD, :XWORD, :PVOID, :XWORD
TabbedTextOutA PROTO :HDC, :XWORD, :XWORD, :LPCTSTR, :XWORD, :XWORD, :XPTR, :XWORD
TabbedTextOutW PROTO :HDC, :XWORD, :XWORD, :LPCWSTR, :XWORD, :XWORD, :XPTR, :XWORD
TileChildWindows PROTO :HWND, :XWORD
TileWindows PROTO :HWND, :XWORD, :XPTR, :XWORD, :XPTR
ToAscii PROTO :XWORD, :XWORD, :XPTR, :LPWORD, :XWORD
ToAsciiEx PROTO :XWORD, :XWORD, :XPTR, :LPWORD, :XWORD, :HKL
ToUnicode PROTO :XWORD, :XWORD, :XPTR, :LPWSTR, :XWORD, :XWORD
TrackPopupMenu PROTO :HMENU, :XWORD, :XWORD, :XWORD, :XWORD, :HWND, :XPTR
TrackPopupMenuEx PROTO :HMENU, :XWORD, :XWORD, :XWORD, :HWND, :XPTR
TranslateAccelerator PROTO :HWND, :HACCEL, :XPTR
TranslateAcceleratorA PROTO :HWND, :HACCEL, :XPTR
TranslateAcceleratorW PROTO :HWND, :HACCEL, :XPTR
TranslateMDISysAccel PROTO :HWND, :XPTR
TranslateMessage PROTO :XPTR
UnhookWindowsHook PROTO :HHOOK
UnhookWindowsHookEx PROTO :HHOOK
UnionRect PROTO :XPTR, :XPTR, :XPTR
UnloadKeyboardLayout PROTO :HKL
UnlockWindowStation PROTO
UnpackDDElParam PROTO :XWORD, :LPARAM
UnregisterClassA PROTO :LPCTSTR, :HINSTANCE
UnregisterClassW PROTO :LPCWSTR, :HINSTANCE
UnregisterHotKey PROTO :HWND, :XWORD
UpdateWindow PROTO :HWND
ValidateRect PROTO :HWND, :XPTR
ValidateRgn PROTO :HWND, :HRGN
VkKeyScanA PROTO :XWORD
VkKeyScanExA PROTO :XWORD, :HKL
VkKeyScanExW PROTO :XWORD, :HKL
VkKeyScanW PROTO :XWORD
WaitForInputIdle PROTO :HANDLE, :XWORD
WaitMessage PROTO
WindowFromDC PROTO :HDC
WindowFromPoint PROTO :XWORD, :XWORD
WinHelpA PROTO :XPTR
WinHelpW PROTO :XPTR
keybd_event PROTO :XWORD, :XWORD, :XWORD, :ULONG_PTR
mouse_event PROTO :XWORD, :XWORD, :XWORD, :XWORD, :ULONG_PTR
wsprintfA PROTO DECL :VARARG
wsprintfW PROTO DECL :VARARG
wvsprintfA PROTO :LPTSTR, :LPCTSTR, :XPTR
wvsprintfW PROTO :LPWSTR, :LPCWSTR, :XPTR

IF (NTDDI_VERSION LE NTDDI_WIN98_ME)
    GetNextQueueWindow PROTO :HWND, :XWORD
    IsHungThread PROTO :XWORD
    ModifyAccess PROTO :XWORD, :XWORD, :XPTR
    RegisterNetworkCapabilities PROTO :XWORD, :XWORD
    SetDesktopBitmap PROTO :LPCSTR
    SetWindowFullScreenState PROTO
    UserSignalProc PROTO :XWORD, :XWORD, :XWORD, :HMODULE
    WNDPROC_CALLBACK PROTO :HWND, :XWORD, :WPARAM, :LPARAM, :XWORD
ENDIF
IF (NTDDI_VERSION NE NTDDI_WINNT4)
    UnhookWinEvent PROTO :HANDLE
    WINNLSEnableIME PROTO :HWND, :XWORD
ENDIF

IF (NTDDI_VERSION GE NTDDI_WIN98_ME)
    BlockInput PROTO :XWORD
    ChangeDisplaySettingsExA PROTO :LPCTSTR, :XPTR, :HWND, :XWORD, :LPVOID
    ChangeDisplaySettingsExW PROTO :LPCWSTR, :XPTR, :HWND, :XWORD, :LPVOID
    EndMenu PROTO
    EnumDisplayMonitors PROTO :HDC, :XPTR, :XPTR, :LPARAM
    EnumDisplaySettingsExA PROTO :LPCTSTR, :XWORD, :XPTR, :XWORD
    EnumDisplaySettingsExW PROTO :LPCTSTR, :XWORD, :XPTR, :XWORD
    FlashWindowEx PROTO :XPTR
    GetAncestor PROTO :HWND, :XWORD
    GetClipboardSequenceNumber PROTO
    GetComboBoxInfo PROTO :HWND, :XPTR
    GetCursorInfo PROTO :XPTR
    GetGUIThreadInfo PROTO :XWORD, :XPTR
    GetListBoxInfo PROTO :HWND
    GetMenuBarInfo PROTO :HWND, :XWORD, :XWORD, :XPTR
    GetMenuInfo PROTO :HMENU, :XPTR
    GetProcessDefaultLayout PROTO :XPTR
    GetScrollBarInfo PROTO :HWND, :XWORD, :XPTR
    GetTitleBarInfo PROTO :HWND, :XPTR
    GetWindowInfo PROTO :HWND, :XPTR
    GetWindowModuleFileName PROTO :HWND, :LPTSTR, :XWORD
    GetWindowModuleFileNameA PROTO :HWND, :LPTSTR, :XWORD
    GetWindowModuleFileNameW PROTO :HWND, :LPWSTR, :XWORD
    IMPGetIMEA PROTO :HWND, :XPTR
    IMPGetIMEW PROTO :HWND, :XPTR
    IMPQueryIMEA PROTO :XPTR
    IMPQueryIMEW PROTO :XPTR
    IMPSetIMEA PROTO :HWND, :XPTR
    IMPSetIMEW PROTO :HWND, :XPTR
    MsgWaitForMultipleObjectsEx PROTO :XWORD, :XPTR, :XWORD, :XWORD, :XWORD
    NotifyWinEvent PROTO :XWORD, :HWND, :XWORD, :XWORD
    RealChildWindowFromPoint PROTO :HWND, :XWORD, :XWORD
    SendIMEMessageExA PROTO :HWND, :LPARAM
    SendIMEMessageExW PROTO :HWND, :LPARAM
    SendInput PROTO :XWORD, :XPTR, :XWORD
    SetWinEventHook PROTO :XWORD, :XWORD, :HMODULE, :XPTR, :XWORD, :XWORD, :XWORD
    ToUnicodeEx PROTO :XWORD, :XWORD, :XPTR, :LPWSTR, :XWORD, :XWORD, :HKL
    TrackMouseEvent PROTO :XPTR

    IF (NTDDI_VERSION NE NTDDI_WINNT4)
        GetMonitorInfoA PROTO :HMONITOR, :XPTR
        GetMonitorInfoW PROTO :HMONITOR, :XPTR
        InSendMessageEx PROTO :LPVOID
        MonitorFromPoint PROTO :XWORD, :XWORD, :XWORD
        MonitorFromRect PROTO :XPTR, :XWORD
        MonitorFromWindow PROTO :HWND, :XWORD
        RegisterDeviceNotificationA PROTO :HANDLE, :LPVOID, :XWORD
        RegisterDeviceNotificationW PROTO :HANDLE, :LPVOID, :XWORD
        SetMenuInfo PROTO :HMENU, :XPTR
        SetProcessDefaultLayout PROTO :XWORD
        UnregisterDeviceNotification PROTO :HANDLE
        IFDEF APP_UNICODE
            GetMonitorInfo EQU <GetMonitorInfoW>
            RegisterDeviceNotification EQU <RegisterDeviceNotificationW>
        ELSE
            GetMonitorInfo EQU <GetMonitorInfoA>
            RegisterDeviceNotification EQU <RegisterDeviceNotificationA>
        ENDIF
    ENDIF

    IFDEF APP_UNICODE
        ChangeDisplaySettingsEx EQU <ChangeDisplaySettingsExW>
        EnumDisplaySettingsEx EQU <EnumDisplaySettingsExW>
        IMPGetIME EQU <IMPGetIMEW>
        IMPQueryIME EQU <IMPQueryIMEW>
        IMPSetIME EQU <IMPSetIMEW>
        SendIMEMessageEx EQU <SendIMEMessageExW>
    ELSE
        ChangeDisplaySettingsEx EQU <ChangeDisplaySettingsExA>
        EnumDisplaySettingsEx EQU <EnumDisplaySettingsExA>
        IMPGetIME EQU <IMPGetIMEA>
        IMPQueryIME EQU <IMPQueryIMEA>
        IMPSetIME EQU <IMPSetIMEA>
        SendIMEMessageEx EQU <SendIMEMessageExA>
    ENDIF
ENDIF

IF (NTDDI_VERSION GE NTDDI_WINNT4)
    ClientThreadSetup PROTO
    CreateDialogIndirectParamAorW PROTO :HINSTANCE, :XPTR, :HWND, :XPTR, :LPARAM, :XWORD
    DdeGetQualityOfService PROTO :HWND, :XWORD, :XPTR
    DeregisterShellHookWindow PROTO :HWND
    DrawMenuBarTemp PROTO :HWND, :HDC, :XPTR, :HMENU, :HFONT
    GetAppCompatFlags PROTO :HTASK
    GetProgmanWindow PROTO
    GetTaskmanWindow PROTO
    IsHungAppWindow PROTO :HWND
    LoadKeyboardLayoutEx PROTO :XWORD, :LPCWSTR, :XWORD
    LoadLocalFonts PROTO
    LoadRemoteFonts PROTO
    MBToWCSEx PROTO :XWORD, :LPSTR, :XWORD, :XPTR, :XWORD, :XWORD
    MB_GetString PROTO :XWORD
    MenuWindowProcA PROTO :HWND, :ULONG_PTR, :XWORD, :WPARAM, :LPARAM
    MenuWindowProcW PROTO :HWND, :ULONG_PTR, :XWORD, :WPARAM, :LPARAM
    PrivateExtractIconExA PROTO :LPCSTR, :XWORD, :XPTR, :XPTR, :XWORD
    PrivateExtractIconExW PROTO :LPWSTR, :XWORD, :XPTR, :XPTR, :XWORD
    PrivateExtractIconsA PROTO :LPCSTR, :XWORD, :XWORD, :XWORD, :XPTR, :XPTR, :XWORD, :XWORD
    PrivateExtractIconsW PROTO :LPWSTR, :XWORD, :XWORD, :XWORD, :XPTR, :XPTR, :XWORD, :XWORD
    QuerySendMessage PROTO :XPTR
    RegisterServicesProcess PROTO :XWORD
    RegisterShellHookWindow PROTO :HWND
    SetProgmanWindow PROTO :HWND
    SetShellWindowEx PROTO :HWND, :HWND
    SetSystemMenu PROTO :HWND, :HMENU
    SetTaskmanWindow PROTO :HWND
    SetWindowStationUser PROTO :XWORD, :XWORD, :XWORD, :XWORD
    ShowStartGlass PROTO :XWORD
    TranslateMessageEx PROTO :XPTR, :XWORD
    UserRealizePalette PROTO :HDC
    UserRegisterWowHandlers PROTO :PVOID, :PVOID
    IFDEF APP_UNICODE
        MenuWindowProc EQU <MenuWindowProcW>
        PrivateExtractIconEx EQU <PrivateExtractIconExW>
        PrivateExtractIcons EQU <PrivateExtractIconsW>
    ELSE
        MenuWindowProc EQU <MenuWindowProcA>
        PrivateExtractIconEx EQU <PrivateExtractIconExA>
        PrivateExtractIcons EQU <PrivateExtractIconsA>
    ENDIF
ENDIF

IF (NTDDI_VERSION GE NTDDI_WIN2K)
    CliImmSetHotKey PROTO :XWORD, :XWORD, :XWORD, :HKL
    CtxInitUser32 PROTO
    DeviceEventWorker PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    GetAppCompatFlags2 PROTO :HTASK
    GetLastInputInfo PROTO :XPTR
    GetMouseMovePointsEx PROTO :XWORD, :XPTR, :XPTR, :XWORD, :XWORD
    InitializeLpkHooks PROTO :XPTR
    LockSetForegroundWindow PROTO :XWORD
    LockWorkStation PROTO
    SetLayeredWindowAttributes PROTO :HWND, :XPTR, :XWORD, :XWORD
    UpdateLayeredWindow PROTO :HWND, :HDC, :XPTR, :XPTR, :HDC, :XPTR, :XPTR, :XPTR, :XWORD
    UserHandleGrantAccess PROTO :HANDLE, :HANDLE, :XWORD
    AllowSetForegroundWindow PROTO :XWORD
    AnimateWindow PROTO :HWND, :XWORD, :XWORD
ENDIF

IF (NTDDI_VERSION GE NTDDI_WINXP)
    AllowForegroundActivation PROTO
    BroadcastSystemMessageExA PROTO :XWORD, :LPDWORD, :XWORD, :WPARAM, :LPARAM, :XPTR
    BroadcastSystemMessageExW PROTO :XWORD, :LPDWORD, :XWORD, :WPARAM, :LPARAM, :XPTR
    BuildReasonArray PROTO :PVOID
    CreateSystemThreads PROTO :XWORD
    CsrBroadcastSystemMessageExW PROTO :XWORD, :LPDWORD, :XWORD, :WPARAM, :LPARAM
    DefRawInputProc PROTO :XPTR, :XWORD, :XWORD
    DestroyReasons PROTO :PVOID
    DisableProcessWindowsGhosting PROTO
    GetLayeredWindowAttributes PROTO :HWND, :XWORD, :XPTR, :XWORD
    GetRawInputBuffer PROTO :XPTR, :XPTR, :XWORD
    GetRawInputData PROTO :HANDLE, :XWORD, :LPVOID, :XPTR, :XWORD
    GetRawInputDeviceInfoA PROTO :HANDLE, :XWORD, :LPVOID, :XPTR
    GetRawInputDeviceInfoW PROTO :HANDLE, :XWORD, :LPVOID, :XPTR
    GetRawInputDeviceList PROTO :XPTR, :XPTR, :XWORD
    GetReasonTitleFromReasonCode PROTO :XWORD, :XWORD, :XWORD
    GetRegisteredRawInputDevices PROTO :XPTR, :XPTR, :XWORD
    GetWindowRgnBox PROTO :HWND, :XPTR
    IsGUIThread PROTO :XWORD
    IF (NTDDI_VERSION LE NTDDI_WINXPALL)
        IsProcess16Bit PROTO
        SetLogonNotifyWindow PROTO :HWND, :HWINSTA
    ENDIF
    IsServerSideWindow PROTO :HWND
    IsWinEventHookInstalled PROTO :XWORD
    IsWindowInDestroy PROTO :HWND
    MessageBoxTimeoutA PROTO :HWND, :LPCTSTR, :LPCTSTR, :XWORD, :XWORD, :XWORD
    MessageBoxTimeoutW PROTO :HWND, :LPCWSTR, :LPCWSTR, :XWORD, :XWORD, :XWORD
    PrintWindow PROTO :HWND, :HDC, :XWORD
    RecordShutdownReason PROTO :XWORD
    RegisterMessagePumpHook PROTO :XPTR
    RegisterRawInputDevices PROTO :XPTR, :XWORD, :XWORD
    RegisterUserApiHook PROTO :HINSTANCE, :XPTR
    UnregisterMessagePumpHook PROTO
    UnregisterUserApiHook PROTO
    IFDEF APP_UNICODE
        BroadcastSystemMessageEx EQU <BroadcastSystemMessageExW>
        GetRawInputDeviceInfo EQU <GetRawInputDeviceInfoW>
        MessageBoxTimeout EQU <MessageBoxTimeoutW>
    ELSE
        BroadcastSystemMessageEx EQU <BroadcastSystemMessageExA>
        GetRawInputDeviceInfo EQU <GetRawInputDeviceInfoA>
        MessageBoxTimeout EQU <MessageBoxTimeoutA>
    ENDIF
ENDIF

IF (NTDDI_VERSION GE NTDDI_WS03SP1)
    IsWow64Message PROTO
ENDIF

IF (NTDDI_VERSION GE NTDDI_VISTA)
    AddClipboardFormatListener PROTO :HWND
    CancelShutdown PROTO
    ChangeWindowMessageFilter PROTO :XWORD, :XWORD
    CreateDesktopExA PROTO :LPCTSTR, :LPCTSTR, :XPTR, :XWORD, :XWORD, :XPTR, :XWORD, :PVOID
    CreateDesktopExW PROTO :LPCWSTR, :LPCWSTR, :XPTR, :XWORD, :XWORD, :XPTR, :XWORD, :PVOID
    DisplayConfigGetDeviceInfo PROTO :XPTR
    DisplayConfigSetDeviceInfo PROTO :XPTR
    FrostCrashedWindow PROTO :HWND, :HWND
    GetIconInfoExA PROTO :HICON, :XPTR
    GetIconInfoExW PROTO :HICON, :XPTR
    GetPhysicalCursorPos PROTO :XPTR
    GetSendMessageReceiver PROTO :XWORD
    GetUpdatedClipboardFormats PROTO :XPTR, :XWORD, :XPTR
    GetWindowMinimizeRect PROTO :HWND, :XPTR
    GhostWindowFromHungWindow PROTO :HWND
    HungWindowFromGhostWindow PROTO :HWND
    IsProcessDPIAware PROTO
    IsSETEnabled PROTO
    IsThreadDesktopComposited PROTO
    IsWindowRedirectedForPrint PROTO :HWND
    LogicalToPhysicalPoint PROTO :HWND, :XPTR
    PhysicalToLogicalPoint PROTO :HWND, :XPTR
    RegisterPowerSettingNotification PROTO :HANDLE, :XPTR, :XWORD
    RemoveClipboardFormatListener PROTO :HWND
    SetPhysicalCursorPos PROTO :XWORD, :XWORD
    SetProcessDPIAware PROTO
    ShutdownBlockReasonCreate PROTO :HWND, :LPCWSTR
    ShutdownBlockReasonDestroy PROTO :HWND
    ShutdownBlockReasonQuery PROTO :HWND, :LPWSTR, :XWORD
    SoundSentry PROTO
    UnregisterPowerSettingNotification PROTO :HANDLE
    UpdateLayeredWindowIndirect PROTO :HWND, :XPTR
    UpdateWindowTransform PROTO :HWND, :XPTR, :XWORD
    IFDEF APP_UNICODE
        CreateDesktopEx EQU <CreateDesktopExW>
        GetIconInfoEx EQU <GetIconInfoExW>
    ELSE
        CreateDesktopEx EQU <CreateDesktopExA>
        GetIconInfoEx EQU <GetIconInfoExA>
    ENDIF
ENDIF

IF (NTDDI_VERSION GE NTDDI_WIN7)
    CalculatePopupWindowPosition PROTO :XPTR, :XPTR, :XWORD, :XPTR, :XPTR
    ChangeWindowMessageFilterEx PROTO :HWND, :XWORD, :XWORD, :XPTR
    CloseGestureInfoHandle PROTO :HANDLE
    CloseTouchInputHandle PROTO :HANDLE
    DwmGetDxSharedSurface PROTO :HWND, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR
    GetDisplayConfigBufferSizes PROTO :XWORD, :XPTR, :XPTR
    GetGestureConfig PROTO :HWND, :XWORD, :XWORD, :XPTR, :XPTR, :XWORD
    GetGestureExtraArgs PROTO :HANDLE, :XWORD, :XPTR
    GetGestureInfo PROTO :HANDLE, :XPTR
    GetTouchInputInfo PROTO :HANDLE, :XWORD, :XPTR, :XWORD
    GetWindowCompositionAttribute PROTO :HWND, :XPTR
    GetWindowDisplayAffinity PROTO :HWND, :XPTR
    IsTopLevelWindow PROTO :HWND
    IsTouchWindow PROTO :HWND, :XPTR
    QueryDisplayConfig PROTO :XWORD, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR
    RegisterTouchWindow PROTO :HWND, :XWORD
    SetDisplayConfig PROTO :XWORD, :XPTR, :XWORD, :XPTR, :XWORD
    SetGestureConfig PROTO :HWND, :XWORD, :XWORD, :XPTR, :XWORD
    SetWindowCompositionAttribute PROTO :HWND, :XPTR
    SetWindowDisplayAffinity PROTO :HWND, :XWORD
    UnregisterTouchWindow PROTO :HWND
ENDIF

IF (NTDDI_VERSION GE NTDDI_WIN8)
    CreateWindowInBand PROTO :XWORD, :LPCWSTR, :LPCWSTR, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :HWND, :HMENU, :HINSTANCE, :LPVOID, :XWORD
    EnableMouseInPointer PROTO :XWORD
    EvaluateProximityToPolygon PROTO :XWORD, :XPTR, :XPTR, :XPTR
    EvaluateProximityToRect PROTO :XPTR, :XPTR, :XPTR
    GetAutoRotationState PROTO :XPTR
    GetCIMSSM PROTO :XPTR
    GetCurrentInputMessageSource PROTO :XPTR
    GetDisplayAutoRotationPreferences PROTO :XPTR
    GetPointerCursorId PROTO :XWORD, :XWORD
    GetPointerDevice PROTO :HANDLE, :XPTR
    GetPointerDeviceCursors PROTO :HANDLE, :XPTR, :XPTR
    GetPointerDeviceProperties PROTO :HANDLE, :XPTR, :XPTR
    GetPointerDeviceRects PROTO :HANDLE, :XPTR, :XPTR
    GetPointerDevices PROTO :XPTR, :XPTR
    GetPointerFrameInfo PROTO :XWORD, :XPTR, :XPTR
    GetPointerFrameInfoHistory PROTO :XWORD, :XPTR, :XPTR, :XPTR
    GetPointerFramePenInfo PROTO :XWORD, :XPTR, :XPTR
    GetPointerFramePenInfoHistory PROTO :XWORD, :XPTR, :XPTR, :XPTR
    GetPointerFrameTouchInfo PROTO :XWORD, :XPTR, :XPTR
    GetPointerFrameTouchInfoHistory PROTO :XWORD, :XPTR, :XPTR, :XPTR
    GetPointerInfo PROTO :XWORD, :XPTR
    GetPointerInfoHistory PROTO :XWORD, :XPTR, :XPTR
    GetPointerPenInfo PROTO :XWORD, :XPTR
    GetPointerPenInfoHistory PROTO :XWORD, :XPTR, :XPTR
    GetPointerTouchInfo PROTO :XWORD, :XPTR
    GetPointerTouchInfoHistory PROTO :XWORD, :XPTR, :XPTR
    GetPointerType PROTO :XWORD, :XPTR
    GetRawPointerDeviceData PROTO :XWORD, :XWORD, :XWORD, :XPTR, :XPTR
    GetUnpredictedMessagePos PROTO
    GetWindowFeedbackSetting PROTO :HWND, :ENUM, :XWORD, :XPTR, :XPTR
    InitializeTouchInjection PROTO :XWORD, :XWORD
    InjectTouchInput PROTO :XWORD, :XPTR
    IsImmersiveProcess PROTO :HANDLE
    IsMouseInPointerEnabled PROTO
    PackTouchHitTestingProximityEvaluation PROTO :XPTR, :XPTR
    RegisterPointerDeviceNotifications PROTO :HWND, :XWORD
    RegisterPointerInputTarget PROTO :HWND, :ENUM
    RegisterSuspendResumeNotification PROTO :XPTR, :XWORD
    RegisterTouchHitTestingWindow PROTO :HWND, :XWORD
    SetCoalescableTimer PROTO :HWND, :XWORD, :XWORD, :XPTR, :XWORD
    SetDisplayAutoRotationPreferences PROTO :XPTR
    SetProcessRestrictionExemption PROTO :XWORD
    SetWindowFeedbackSetting PROTO :HWND, :ENUM, :XWORD, :XWORD, :XPTR
    ShowSystemCursor PROTO :XWORD
    SkipPointerFrameMessages PROTO :XWORD
    UnregisterPointerInputTarget PROTO :HWND, :ENUM
    UnregisterSuspendResumeNotification PROTO :HANDLE
ENDIF

IF (NTDDI_VERSION GE NTDDI_WIN81)
    PhysicalToLogicalPointForPerMonitorDPI PROTO :HWND, :XPTR
ENDIF

IFDEF APP_UNICODE
    IFNDEF LOGFONT
        LOGFONT EQU <LOGFONTW>
    ENDIF
    ICONINFOEX EQU <ICONINFOEXW>
    CBT_CREATEWND EQU <CBT_CREATEWNDW>
    WNDCLASSEX EQU <WNDCLASSEXW>
    WNDCLASS EQU <WNDCLASSW>
    CREATESTRUCT EQU <CREATESTRUCTW>
    MENUITEMINFO EQU <MENUITEMINFOW>
    MSGBOXPARAMS EQU <MSGBOXPARAMSW>
    MDICREATESTRUCT EQU <MDICREATESTRUCTW>
    MULTIKEYHELP EQU <MULTIKEYHELPW>
    HELPWININFO EQU <HELPWININFOW>
    NONCLIENTMETRICS EQU <NONCLIENTMETRICSW>
    ICONMETRICS EQU <ICONMETRICSW>
    SERIALKEYS EQU <SERIALKEYSW>
    HIGHCONTRAST EQU <HIGHCONTRASTW>
    SOUNDSENTRY EQU <SOUNDSENTRYW>
    MONITORINFOEX EQU <MONITORINFOEXW>
    AppendMenu EQU <AppendMenuW>
    CallWindowProc EQU <CallWindowProcW>
    ChangeDisplaySettings EQU <ChangeDisplaySettingsW>
    ChangeMenu EQU <ChangeMenuW>
    CharLower EQU <CharLowerW>
    CharNext EQU <CharNextW>
    CharPrev EQU <CharPrevW>
    CharToOem EQU <CharToOemW>
    CharToOemBuff EQU <CharToOemBuffW>
    CharUpper EQU <CharUpperW>
    CharUpperBuff EQU <CharUpperBuffW>
    CopyAcceleratorTable EQU <CopyAcceleratorTableW>
    CreateAcceleratorTable EQU <CreateAcceleratorTableW>
    CreateDesktop EQU <CreateDesktopW>
    CreateDialogIndirectParam EQU <CreateDialogIndirectParamW>
    CreateDialogParam EQU <CreateDialogParamW>
    CreateMDIWindow EQU <CreateMDIWindowW>
    CreateWindowEx EQU <CreateWindowExW>
    CreateWindowStation EQU <CreateWindowStationW>
    DdeCreateStringHandle EQU <DdeCreateStringHandleW>
    DdeInitialize EQU <DdeInitializeW>
    DdeQueryString EQU <DdeQueryStringW>
    DefDlgProc EQU <DefDlgProcW>
    DefFrameProc EQU <DefFrameProcW>
    DefMDIChildProc EQU <DefMDIChildProcW>
    DefWindowProc EQU <DefWindowProcW>
    DialogBoxIndirectParam EQU <DialogBoxIndirectParamW>
    DialogBoxParam EQU <DialogBoxParamW>
    DispatchMessage EQU <DispatchMessageW>
    DlgDirList EQU <DlgDirListW>
    DlgDirListComboBox EQU <DlgDirListComboBoxW>
    DlgDirSelectComboBoxEx EQU <DlgDirSelectComboBoxExW>
    DlgDirSelectEx EQU <DlgDirSelectExW>
    DrawCaptionTemp EQU <DrawCaptionTempW>
    DrawState EQU <DrawStateW>
    DrawText EQU <DrawTextW>
    DrawTextEx EQU <DrawTextExW>
    EnumDesktops EQU <EnumDesktopsW>
    EnumDisplayDevices EQU <EnumDisplayDevicesW>
    EnumDisplaySettings EQU <EnumDisplaySettingsW>
    EnumProps EQU <EnumPropsW>
    EnumPropsEx EQU <EnumPropsExW>
    EnumWindowStations EQU <EnumWindowStationsW>
    FindWindow EQU <FindWindowW>
    FindWindowEx EQU <FindWindowExW>
    GetClassInfo EQU <GetClassInfoW>
    GetClassInfoEx EQU <GetClassInfoExW>
    GetClassLong EQU <GetClassLongW>
    GetClassName EQU <GetClassNameW>
    GetClipboardFormatName EQU <GetClipboardFormatNameW>
    GetDlgItemText EQU <GetDlgItemTextW>
    GetKeyboardLayoutName EQU <GetKeyboardLayoutNameW>
    GetKeyNameText EQU <GetKeyNameTextW>
    GetMenuItemInfo EQU <GetMenuItemInfoW>
    GetMenuString EQU <GetMenuStringW>
    GetMessage EQU <GetMessageW>
    GetProp EQU <GetPropW>
    GetTabbedTextExtent EQU <GetTabbedTextExtentW>
    GetUserObjectInformation EQU <GetUserObjectInformationW>
    GetWindowLong EQU <GetWindowLongW>
    GetWindowText EQU <GetWindowTextW>
    GetWindowTextLength EQU <GetWindowTextLengthW>
    GrayString EQU <GrayStringW>
    InsertMenu EQU <InsertMenuW>
    InsertMenuItem EQU <InsertMenuItemW>
    IsCharAlpha EQU <IsCharAlphaW>
    IsCharAlphaNumeric EQU <IsCharAlphaNumericW>
    IsCharLower EQU <IsCharLowerW>
    IsCharUpper EQU <IsCharUpperW>
    LoadAccelerators EQU <LoadAcceleratorsW>
    LoadBitmap EQU <LoadBitmapW>
    LoadCursor EQU <LoadCursorW>
    LoadCursorFromFile EQU <LoadCursorFromFileW>
    LoadIcon EQU <LoadIconW>
    LoadImage EQU <LoadImageW>
    LoadKeyboardLayout EQU <LoadKeyboardLayoutW>
    LoadMenu EQU <LoadMenuW>
    LoadMenuIndirect EQU <LoadMenuIndirectW>
    LoadString EQU <LoadStringW>
    MapVirtualKey EQU <MapVirtualKeyW>
    MapVirtualKeyEx EQU <MapVirtualKeyExW>
    MessageBox EQU <MessageBoxW>
    MessageBoxEx EQU <MessageBoxExW>
    MessageBoxIndirect EQU <MessageBoxIndirectW>
    ModifyMenu EQU <ModifyMenuW>
    OemToChar EQU <OemToCharW>
    OemToCharBuff EQU <OemToCharBuffW>
    OpenDesktop EQU <OpenDesktopW>
    OpenWindowStation EQU <OpenWindowStationW>
    PeekMessage EQU <PeekMessageW>
    PostMessage EQU <PostMessageW>
    PostThreadMessage EQU <PostThreadMessageW>
    RegisterClass EQU <RegisterClassW>
    RegisterClassEx EQU <RegisterClassExW>
    RegisterClipboardFormat EQU <RegisterClipboardFormatW>
    RegisterWindowMessage EQU <RegisterWindowMessageW>
    RemoveProp EQU <RemovePropW>
    SendDlgItemMessage EQU <SendDlgItemMessageW>
    SendMessage EQU <SendMessageW>
    SendMessageCallback EQU <SendMessageCallbackW>
    SendMessageTimeout EQU <SendMessageTimeoutW>
    SendNotifyMessage EQU <SendNotifyMessageW>
    SetClassLong EQU <SetClassLongW>
    SetDlgItemText EQU <SetDlgItemTextW>
    SetMenuItemInfo EQU <SetMenuItemInfoW>
    SetProp EQU <SetPropW>
    SetUserObjectInformation EQU <SetUserObjectInformationW>
    SetWindowLong EQU <SetWindowLongW>
    SetWindowsHook EQU <SetWindowsHookW>
    SetWindowsHookEx EQU <SetWindowsHookExW>
    SetWindowText EQU <SetWindowTextW>
    SystemParametersInfo EQU <SystemParametersInfoW>
    TabbedTextOut EQU <TabbedTextOutW>
    UnregisterClass EQU <UnregisterClassW>
    VkKeyScan EQU <VkKeyScanW>
    VkKeyScanEx EQU <VkKeyScanExW>
    WinHelp EQU <WinHelpW>
    wsprintf EQU <wsprintfW>
    wvsprintf EQU <wvsprintfW>
ELSE
    IFNDEF LOGFONT
        LOGFONT EQU <LOGFONTA>
    ENDIF
    ICONINFOEX EQU <ICONINFOEXA>
    CBT_CREATEWND EQU <CBT_CREATEWNDA>
    WNDCLASSEX EQU <WNDCLASSEXA>
    WNDCLASS EQU <WNDCLASSA>
    CREATESTRUCT EQU <CREATESTRUCTA>
    MENUITEMINFO EQU <MENUITEMINFOA>
    MSGBOXPARAMS EQU <MSGBOXPARAMSA>
    MDICREATESTRUCT EQU <MDICREATESTRUCTA>
    MULTIKEYHELP EQU <MULTIKEYHELPA>
    HELPWININFO EQU <HELPWININFOA>
    NONCLIENTMETRICS EQU <NONCLIENTMETRICSA>
    ICONMETRICS EQU <ICONMETRICSA>
    SERIALKEYS EQU <SERIALKEYSA>
    HIGHCONTRAST EQU <HIGHCONTRASTA>
    SOUNDSENTRY EQU <SOUNDSENTRYA>
    MONITORINFOEX EQU <MONITORINFOEXA>
    AppendMenu EQU <AppendMenuA>
    CallWindowProc EQU <CallWindowProcA>
    ChangeDisplaySettings EQU <ChangeDisplaySettingsA>
    ChangeMenu EQU <ChangeMenuA>
    CharLower EQU <CharLowerA>
    CharNext EQU <CharNextA>
    CharNextEx EQU <CharNextExA>
    CharPrev EQU <CharPrevA>
    CharPrevEx EQU <CharPrevExA>
    CharToOem EQU <CharToOemA>
    CharToOemBuff EQU <CharToOemBuffA>
    CharUpper EQU <CharUpperA>
    CharUpperBuff EQU <CharUpperBuffA>
    CopyAcceleratorTable EQU <CopyAcceleratorTableA>
    CreateAcceleratorTable EQU <CreateAcceleratorTableA>
    CreateDesktop EQU <CreateDesktopA>
    CreateDialogIndirectParam EQU <CreateDialogIndirectParamA>
    CreateDialogParam EQU <CreateDialogParamA>
    CreateMDIWindow EQU <CreateMDIWindowA>
    CreateWindowEx EQU <CreateWindowExA>
    CreateWindowStation EQU <CreateWindowStationA>
    DdeCreateStringHandle EQU <DdeCreateStringHandleA>
    DdeInitialize EQU <DdeInitializeA>
    DdeQueryString EQU <DdeQueryStringA>
    DefDlgProc EQU <DefDlgProcA>
    DefFrameProc EQU <DefFrameProcA>
    DefMDIChildProc EQU <DefMDIChildProcA>
    DefWindowProc EQU <DefWindowProcA>
    DialogBoxIndirectParam EQU <DialogBoxIndirectParamA>
    DialogBoxParam EQU <DialogBoxParamA>
    DispatchMessage EQU <DispatchMessageA>
    DlgDirList EQU <DlgDirListA>
    DlgDirListComboBox EQU <DlgDirListComboBoxA>
    DlgDirSelectComboBoxEx EQU <DlgDirSelectComboBoxExA>
    DlgDirSelectEx EQU <DlgDirSelectExA>
    DrawCaptionTemp EQU <DrawCaptionTempA>
    DrawState EQU <DrawStateA>
    DrawText EQU <DrawTextA>
    DrawTextEx EQU <DrawTextExA>
    EnumDesktops EQU <EnumDesktopsA>
    EnumDisplayDevices EQU <EnumDisplayDevicesA>
    EnumDisplaySettings EQU <EnumDisplaySettingsA>
    EnumProps EQU <EnumPropsA>
    EnumPropsEx EQU <EnumPropsExA>
    EnumWindowStations EQU <EnumWindowStationsA>
    FindWindow EQU <FindWindowA>
    FindWindowEx EQU <FindWindowExA>
    GetClassInfo EQU <GetClassInfoA>
    GetClassInfoEx EQU <GetClassInfoExA>
    GetClassLong EQU <GetClassLongA>
    GetClassName EQU <GetClassNameA>
    GetClipboardFormatName EQU <GetClipboardFormatNameA>
    GetDlgItemText EQU <GetDlgItemTextA>
    GetKeyboardLayoutName EQU <GetKeyboardLayoutNameA>
    GetKeyNameText EQU <GetKeyNameTextA>
    GetMenuItemInfo EQU <GetMenuItemInfoA>
    GetMenuString EQU <GetMenuStringA>
    GetMessage EQU <GetMessageA>
    GetProp EQU <GetPropA>
    GetTabbedTextExtent EQU <GetTabbedTextExtentA>
    GetUserObjectInformation EQU <GetUserObjectInformationA>
    GetWindowLong EQU <GetWindowLongA>
    GetWindowText EQU <GetWindowTextA>
    GetWindowTextLength EQU <GetWindowTextLengthA>
    GrayString EQU <GrayStringA>
    InsertMenu EQU <InsertMenuA>
    InsertMenuItem EQU <InsertMenuItemA>
    IsCharAlpha EQU <IsCharAlphaA>
    IsCharAlphaNumeric EQU <IsCharAlphaNumericA>
    IsCharLower EQU <IsCharLowerA>
    IsCharUpper EQU <IsCharUpperA>
    LoadAccelerators EQU <LoadAcceleratorsA>
    LoadBitmap EQU <LoadBitmapA>
    LoadCursor EQU <LoadCursorA>
    LoadCursorFromFile EQU <LoadCursorFromFileA>
    LoadIcon EQU <LoadIconA>
    LoadImage EQU <LoadImageA>
    LoadKeyboardLayout EQU <LoadKeyboardLayoutA>
    LoadMenu EQU <LoadMenuA>
    LoadMenuIndirect EQU <LoadMenuIndirectA>
    LoadString EQU <LoadStringA>
    MapVirtualKey EQU <MapVirtualKeyA>
    MapVirtualKeyEx EQU <MapVirtualKeyExA>
    MessageBox EQU <MessageBoxA>
    MessageBoxEx EQU <MessageBoxExA>
    MessageBoxIndirect EQU <MessageBoxIndirectA>
    ModifyMenu EQU <ModifyMenuA>
    OemToChar EQU <OemToCharA>
    OemToCharBuff EQU <OemToCharBuffA>
    OpenDesktop EQU <OpenDesktopA>
    OpenWindowStation EQU <OpenWindowStationA>
    PeekMessage EQU <PeekMessageA>
    PostMessage EQU <PostMessageA>
    PostThreadMessage EQU <PostThreadMessageA>
    RegisterClass EQU <RegisterClassA>
    RegisterClassEx EQU <RegisterClassExA>
    RegisterClipboardFormat EQU <RegisterClipboardFormatA>
    RegisterWindowMessage EQU <RegisterWindowMessageA>
    RemoveProp EQU <RemovePropA>
    SendDlgItemMessage EQU <SendDlgItemMessageA>
    SendMessage EQU <SendMessageA>
    SendMessageCallback EQU <SendMessageCallbackA>
    SendMessageTimeout EQU <SendMessageTimeoutA>
    SendNotifyMessage EQU <SendNotifyMessageA>
    SetClassLong EQU <SetClassLongA>
    SetDlgItemText EQU <SetDlgItemTextA>
    SetMenuItemInfo EQU <SetMenuItemInfoA>
    SetProp EQU <SetPropA>
    SetUserObjectInformation EQU <SetUserObjectInformationA>
    SetWindowLong EQU <SetWindowLongA>
    SetWindowsHook EQU <SetWindowsHookA>
    SetWindowsHookEx EQU <SetWindowsHookExA>
    SetWindowText EQU <SetWindowTextA>
    SystemParametersInfo EQU <SystemParametersInfoA>
    TabbedTextOut EQU <TabbedTextOutA>
    UnregisterClass EQU <UnregisterClassA>
    VkKeyScan EQU <VkKeyScanA>
    VkKeyScanEx EQU <VkKeyScanExA>
    WinHelp EQU <WinHelpA>
    wsprintf EQU <wsprintfA>
    wvsprintf EQU <wvsprintfA>
ENDIF

PostAppMessage EQU <PostThreadMessage>
PostAppMessageA EQU <PostThreadMessageA>
PostAppMessageW EQU <PostThreadMessageW>
AnsiToOem EQU <CharToOemA>
OemToAnsi EQU <OemToCharA>
AnsiToOemBuff EQU <CharToOemBuffA>
OemToAnsiBuff EQU <OemToCharBuffA>
AnsiUpper EQU <CharUpperA>
AnsiUpperBuff EQU <CharUpperBuffA>
AnsiLower EQU <CharLowerA>
AnsiLowerBuff EQU <CharLowerBuffA>
AnsiNext EQU <CharNextA>
AnsiPrev EQU <CharPrevA>

IFDEF APP_WIN64
    GetClassLongPtrA PROTO :HWND, :XWORD
    GetClassLongPtrW PROTO :HWND, :XWORD
    GetWindowLongPtrA PROTO :HWND, :XWORD
    GetWindowLongPtrW PROTO :HWND, :XWORD
    SetClassLongPtrA PROTO :HWND, :XWORD, :LONG_PTR
    SetClassLongPtrW PROTO :HWND, :XWORD, :LONG_PTR
    SetWindowLongPtrA PROTO :HWND, :XWORD, :LONG_PTR
    SetWindowLongPtrW PROTO :HWND, :XWORD, :LONG_PTR
    IFDEF APP_UNICODE
        GetClassLongPtr EQU <GetClassLongPtrW>
        GetWindowLongPtr EQU <GetWindowLongPtrW>
        SetClassLongPtr EQU <SetClassLongPtrW>
        SetWindowLongPtr EQU <SetWindowLongPtrW>
    ELSE
        GetClassLongPtr EQU <GetClassLongPtrA>
        GetWindowLongPtr EQU <GetWindowLongPtrA>
        SetClassLongPtr EQU <SetClassLongPtrA>
        SetWindowLongPtr EQU <SetWindowLongPtrA>
    ENDIF
ELSE
    GetClassLongPtr EQU <GetClassLong>
    GetWindowLongPtr EQU <GetWindowLong>
    SetClassLongPtr EQU <SetClassLong>
    SetWindowLongPtr EQU <SetWindowLong>
    GetClassLongPtrA EQU <GetClassLongA>
    GetWindowLongPtrA EQU <GetWindowLongA>
    SetClassLongPtrA EQU <SetClassLongA>
    SetWindowLongPtrA EQU <SetWindowLongA>
ENDIF

;======================= Undocumented functions (unknown arguments) =======================;
;AlignRects PROTO
;CalcMenuBar PROTO
;CheckDBCSEnabledExt PROTO
;CheckDesktopByThreadId PROTO
;CheckProcessForClipboardAccess PROTO
;CheckProcessSession PROTO
;CheckWindowThreadDesktop PROTO
;ConsoleControl PROTO
;ControlMagnification PROTO
;CreateDCompositionHwndTarget PROTO
;CreateWindowInBandEx PROTO
;CreateWindowIndirect PROTO
;DeferWindowPosAndBand PROTO
;DestroyDCompositionHwndTarget PROTO
;DialogBoxIndirectParamAorW PROTO
;DisplayExitWindowsWarnings PROTO
;DoSoundConnect PROTO
;DoSoundDisconnect PROTO
;DwmGetDxRgn PROTO
;DwmGetRemoteSessionOcclusionEvent PROTO
;DwmGetRemoteSessionOcclusionState PROTO
;DwmHintDxUpdate PROTO
;DwmKernelShutdown PROTO
;DwmKernelStartup PROTO
;DwmLockScreenUpdates PROTO
;DwmStartRedirection PROTO
;DwmStopRedirection PROTO
;DwmValidateWindow PROTO
;EnableChildWindowDpiMessage PROTO
;EnableSessionForMMCSS PROTO
;EndDeferWindowPosEx PROTO
;EnterReaderModeHelper PROTO
;gapfnScSendMessage PROTO
;GetClipboardAccessToken PROTO
;GetCursorFrameInfo PROTO
;GetDesktopID PROTO
;GetDpiForMonitorInternal PROTO
;GetDpiMetrics PROTO
;GetInputLocaleInfo PROTO
;GetMagnificationDesktopColorEffect PROTO
;GetMagnificationDesktopMagnification PROTO
;GetMagnificationLensCtxInformation PROTO
;GetPointerFrameArrivalTimes PROTO
;GetProcessDpiAwarenessInternal PROTO
;GetProcessUIContextInformation PROTO
;GetTopLevelWindow PROTO
;GetWinStationInfo PROTO
;GetWindowBand PROTO
;GetWindowCompositionInfo PROTO
;GetWindowDPI PROTO
;GetWindowRgnEx PROTO
;gSharedInfo PROTO
;InitDManipHook PROTO
;InitializeInputDeviceInjection PROTO
;InitializePointerDeviceInjection PROTO
;InjectDeviceInput PROTO
;InjectKeyboardInput PROTO
;InjectMouseInput PROTO
;InjectPointerInput PROTO
;InternalGetWindowIcon PROTO
;IsChildWindowDpiMessageEnabled PROTO
;IsInDesktopWindowBand PROTO
;IsQueueAttached PROTO
;IsThreadMessageQueueAttached PROTO
;IsWindowArranged PROTO
;IsWindowBroadcastingDpiToChildren PROTO
;KillSystemTimer PROTO
;LogicalToPhysicalPointForPerMonitorDPI PROTO
;MBToWCSExt PROTO
;NotifyOverlayWindow PROTO
;OpenThreadDesktop PROTO
;PaintMenuBar PROTO
;PaintMonitor PROTO
;PrivateRegisterICSProc PROTO
;QueryBSDRWindow PROTO
;ReasonCodeNeedsBugID PROTO
;ReasonCodeNeedsComment PROTO
;RegisterBSDRWindow PROTO
;RegisterDManipHook PROTO
;RegisterErrorReportingDialog PROTO
;RegisterFrostWindow PROTO
;RegisterGhostWindow PROTO
;RegisterManipulationThread PROTO
;RegisterPointerInputTargetEx PROTO
;RegisterSessionPort PROTO
;ReleaseDwmHitTestWaiters PROTO
;RemoveInjectionDevice PROTO
;ResolveDesktopForWOW PROTO
;RIMAddInputObserver PROTO
;RIMAddInputObserver PROTO
;RIMAreSiblingDevices PROTO
;RIMDeviceIoControl PROTO
;RIMFreeInputBuffer PROTO
;RIMGetDevicePreparsedData PROTO
;RIMGetDevicePreparsedDataLockfree PROTO
;RIMGetDeviceProperties PROTO
;RIMGetPhysicalDeviceRect PROTO
;RIMObserveNextInput PROTO
;RIMOnPnpNotification PROTO
;RIMOnTimerNotification PROTO
;RIMReadInput PROTO
;RIMRegisterForInput PROTO
;RIMRemoveInputObserver PROTO
;RIMSetTestModeStatus PROTO
;RIMUnregisterForInput PROTO
;RIMUpdateInputObserverRegistration PROTO
;ScrollChildren PROTO
;SetConsoleReserveKeys PROTO
;SetCursorContents PROTO
;SetDeskWallpaper PROTO
;SetFeatureReportResponse PROTO
;SetImmersiveBackgroundWindow PROTO
;SetMagnificationDesktopColorEffect PROTO
;SetMagnificationDesktopMagnification PROTO
;SetMagnificationLensCtxInformation PROTO
;SetManipulationInputTarget PROTO
;SetMirrorRendering PROTO
;SetProcessDpiAwarenessInternal PROTO
;SetSystemTimer PROTO
;SetThreadInputBlocked PROTO
;SetWindowBand PROTO
;SetWindowCompositionTransition PROTO
;SetWindowRgnEx PROTO
;SignalRedirectionStartComplete PROTO
;SfmDxBindSwapChain PROTO
;SfmDxBindSwapChain PROTO
;SfmDxGetSwapChainStats PROTO
;SfmDxOpenSwapChain PROTO
;SfmDxQuerySwapChainBindingStatus PROTO
;SfmDxReleaseSwapChain PROTO
;SfmDxReportPendingBindingsToDwm PROTO
;SfmDxSetSwapChainBindingStatus PROTO
;SfmDxSetSwapChainStats PROTO
;SoftModalMessageBox PROTO
;SwitchDesktopWithFade PROTO
;UnregisterPointerInputTargetEx PROTO
;UnregisterSessionPort PROTO
;UpdateDefaultDesktopThumbnail PROTO
;UpdatePerUserSystemParameters PROTO
;UpdateWindowInputSinkHints PROTO
;User32InitializeImmEntryTable PROTO
;UserClientDllInitialize PROTO
;UserLpkPSMTextOut PROTO
;UserLpkTabbedTextOut PROTO
;VRipOutput PROTO
;VTagOutput PROTO
;WCSToMBEx PROTO
;WINNLSGetEnableStatus PROTO
;WINNLSGetIMEHotkey PROTO
;WaitForRedirectionStartComplete PROTO
;Win32PoolAllocationStats PROTO
;WindowFromPhysicalPoint PROTO
;_UserTestTokenForInteractive PROTO
;IF (NTDDI_VERSION LE NTDDI_WIN98_ME)
;    CalcChildScroll PROTO
;    ClientThreadConnect PROTO
;    InitSharedTable PROTO
;    InitTask PROTO
;    PlaySoundEvent PROTO
;    SysErrorBox PROTO
;    WinOldAppHackoMatic PROTO
;    YieldTask PROTO
;ENDIF

ENDIF ;USER32_INC
