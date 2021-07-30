; =====================================================;
;                                                      ;
;  shell32.inc for Easy Code 2.0 64-bit Masm projects  ;
;                  (version 1.0.7)                     ;
;                                                      ;
;          Copyright © Ramon Sala - 2015-2020          ;
;                                                      ;
; =====================================================;

IFNDEF SHELL32_INC
SHELL32_INC EQU     1

ABM_NEW                                         EQU     000000000H
ABM_REMOVE                                      EQU     000000001H
ABM_QUERYPOS                                    EQU     000000002H
ABM_SETPOS                                      EQU     000000003H
ABM_GETSTATE                                    EQU     000000004H
ABM_GETTASKBARPOS                               EQU     000000005H
ABM_ACTIVATE                                    EQU     000000006H
ABM_GETAUTOHIDEBAR                              EQU     000000007H
ABM_SETAUTOHIDEBAR                              EQU     000000008H
ABM_WINDOWPOSCHANGED                            EQU     000000009H
ABM_SETSTATE                                    EQU     00000000AH
ABM_GETAUTOHIDEBAREX                            EQU     00000000BH
ABM_SETAUTOHIDEBAREX                            EQU     00000000CH

ABN_STATECHANGE                                 EQU     00000000H
ABN_POSCHANGED                                  EQU     00000001H
ABN_FULLSCREENAPP                               EQU     00000002H
ABN_WINDOWARRANGE                               EQU     00000003H

ABS_AUTOHIDE                                    EQU     00000001H
ABS_ALWAYSONTOP                                 EQU     00000002H

ABE_LEFT                                        EQU     0
ABE_TOP                                         EQU     1
ABE_RIGHT                                       EQU     2
ABE_BOTTOM                                      EQU     3

FO_MOVE                                         EQU     00001H
FO_COPY                                         EQU     00002H
FO_DELETE                                       EQU     00003H
FO_RENAME                                       EQU     00004H

FOF_MULTIDESTFILES                              EQU     00001H
FOF_CONFIRMMOUSE                                EQU     00002H
FOF_SILENT                                      EQU     00004H
FOF_RENAMEONCOLLISION                           EQU     00008H
FOF_NOCONFIRMATION                              EQU     00010H
FOF_WANTMAPPINGHANDLE                           EQU     00020H

FOF_ALLOWUNDO                                   EQU     00040H
FOF_FILESONLY                                   EQU     00080H
FOF_SIMPLEPROGRESS                              EQU     00100H
FOF_NOCONFIRMMKDIR                              EQU     00200H
FOF_NOERRORUI                                   EQU     00400H
FOF_NOCOPYSECURITYATTRIBS                       EQU     00800H
FOF_NORECURSION                                 EQU     01000H
FOF_NO_CONNECTED_ELEMENTS                       EQU     02000H
FOF_WANTNUKEWARNING                             EQU     04000H
FOF_NORECURSEREPARSE                            EQU     08000H
FOF_NO_UI                                       EQU     (FOF_SILENT OR FOF_NOCONFIRMATION OR FOF_NOERRORUI OR FOF_NOCONFIRMMKDIR)

PO_DELETE                                       EQU     00013H
PO_RENAME                                       EQU     00014H
PO_PORTCHANGE                                   EQU     00020H
PO_REN_PORT                                     EQU     00034H

FILEOP_FLAGS                                    TYPEDEF WORD
PRINTEROP_FLAGS                                 TYPEDEF WORD

SE_ERR_FNF                                      EQU     2
SE_ERR_PNF                                      EQU     3
SE_ERR_ACCESSDENIED                             EQU     5
SE_ERR_OOM                                      EQU     8
SE_ERR_SHARE                                    EQU     26
SE_ERR_ASSOCINCOMPLETE                          EQU     27
SE_ERR_DDETIMEOUT                               EQU     28
SE_ERR_DDEFAIL                                  EQU     29
SE_ERR_DDEBUSY                                  EQU     30
SE_ERR_NOASSOC                                  EQU     31
SE_ERR_DLLNOTFOUND                              EQU     32

SEE_MASK_DEFAULT                                EQU     000000000H
SEE_MASK_CLASSNAME                              EQU     000000001H
SEE_MASK_CLASSKEY                               EQU     000000003H
SEE_MASK_IDLIST                                 EQU     000000004H
SEE_MASK_INVOKEIDLIST                           EQU     00000000CH
SEE_MASK_ICON                                   EQU     000000010H
SEE_MASK_HOTKEY                                 EQU     000000020H
SEE_MASK_NOCLOSEPROCESS                         EQU     000000040H
SEE_MASK_CONNECTNETDRV                          EQU     000000080H
SEE_MASK_NOASYNC                                EQU     000000100H
SEE_MASK_FLAG_DDEWAIT                           EQU     SEE_MASK_NOASYNC
SEE_MASK_DOENVSUBST                             EQU     000000200H
SEE_MASK_FLAG_NO_UI                             EQU     000000400H
SEE_MASK_UNICODE                                EQU     000004000H
SEE_MASK_NO_CONSOLE                             EQU     000008000H
SEE_MASK_ASYNCOK                                EQU     000100000H
SEE_MASK_HMONITOR                               EQU     000200000H
SEE_MASK_NOZONECHECKS                           EQU     000800000H
SEE_MASK_NOQUERYCLASSSTORE                      EQU     001000000H
SEE_MASK_WAITFORINPUTIDLE                       EQU     002000000H
SEE_MASK_FLAG_LOG_USAGE                         EQU     004000000H
SEE_MASK_FLAG_HINST_IS_SITE                     EQU     008000000H

ASSOCCLASS_SHELL_KEY                            EQU     0
ASSOCCLASS_PROGID_KEY                           EQU     01H
ASSOCCLASS_PROGID_STR                           EQU     02H
ASSOCCLASS_CLSID_KEY                            EQU     03H
ASSOCCLASS_CLSID_STR                            EQU     04H
ASSOCCLASS_APP_KEY                              EQU     05H
ASSOCCLASS_APP_STR                              EQU     06H
ASSOCCLASS_SYSTEM_STR                           EQU     07H
ASSOCCLASS_FOLDER                               EQU     08H
ASSOCCLASS_STAR                                 EQU     09H
ASSOCCLASS_FIXED_PROGID_STR                     EQU     0AH
ASSOCCLASS_PROTOCOL_STR                         EQU     0BH

SHERB_NOCONFIRMATION                            EQU     000000001H
SHERB_NOPROGRESSUI                              EQU     000000002H
SHERB_NOSOUND                                   EQU     000000004H

QUNS_NOT_PRESENT                                EQU     1
QUNS_BUSY                                       EQU     2
QUNS_RUNNING_D3D_FULL_SCREEN                    EQU     3
QUNS_PRESENTATION_MODE                          EQU     4
QUNS_ACCEPTS_NOTIFICATIONS                      EQU     5
QUNS_QUIET_TIME                                 EQU     6
QUNS_APP                                        EQU     7

NIM_ADD                                         EQU     000000000H
NIM_MODIFY                                      EQU     000000001H
NIM_DELETE                                      EQU     000000002H
NIM_SETFOCUS                                    EQU     000000003h
NIM_SETVERSION                                  EQU     000000004H

NIN_SELECT                                      EQU     (WM_USER + 0)
NINF_KEY                                        EQU     01H
NIN_KEYSELECT                                   EQU     (NIN_SELECT OR NINF_KEY)
NIN_BALLOONSHOW                                 EQU     (WM_USER + 2)
NIN_BALLOONHIDE                                 EQU     (WM_USER + 3)
NIN_BALLOONTIMEOUT                              EQU     (WM_USER + 4)
NIN_BALLOONUSERCLICK                            EQU     (WM_USER + 5)
NIN_POPUPOPEN                                   EQU     (WM_USER + 6)
NIN_POPUPCLOSE                                  EQU     (WM_USER + 7)

NOTIFYICON_VERSION                              EQU     3
NOTIFYICON_VERSION_4                            EQU     4

NIF_MESSAGE                                     EQU     000000001H
NIF_ICON                                        EQU     000000002H
NIF_TIP                                         EQU     000000004H
NIF_STATE                                       EQU     000000008H
NIF_INFO                                        EQU     000000010H
NIF_GUID                                        EQU     000000020H
NIF_REALTIME                                    EQU     000000040H
NIF_SHOWTIP                                     EQU     000000080H

NIS_HIDDEN                                      EQU     000000001H
NIS_SHAREDICON                                  EQU     000000002H

NIIF_NONE                                       EQU     000000000H
NIIF_INFO                                       EQU     000000001H
NIIF_WARNING                                    EQU     000000002H
NIIF_ERROR                                      EQU     000000003H
NIIF_USER                                       EQU     000000004H
NIIF_ICON_MASK                                  EQU     00000000FH
NIIF_NOSOUND                                    EQU     000000010H
NIIF_LARGE_ICON                                 EQU     000000020H
NIIF_RESPECT_QUIET_TIME                         EQU     000000080H

SHARD_PIDL                                      EQU     000000001H
SHARD_PATHA                                     EQU     000000002H
SHARD_PATHW                                     EQU     000000003H
IFDEF APP_UNICODE
    SHARD_PATH                                  EQU     SHARD_PATHW
ELSE
    SHARD_PATH                                  EQU     SHARD_PATHA
ENDIF

SHDID_ROOT_REGITEM                              EQU     1
SHDID_FS_FILE                                   EQU     2
SHDID_FS_DIRECTORY                              EQU     3
SHDID_FS_OTHER                                  EQU     4
SHDID_COMPUTER_DRIVE35                          EQU     5
SHDID_COMPUTER_DRIVE525                         EQU     6
SHDID_COMPUTER_REMOVABLE                        EQU     7
SHDID_COMPUTER_FIXED                            EQU     8
SHDID_COMPUTER_NETDRIVE                         EQU     9
SHDID_COMPUTER_CDROM                            EQU     10
SHDID_COMPUTER_RAMDISK                          EQU     11
SHDID_COMPUTER_OTHER                            EQU     12
SHDID_NET_DOMAIN                                EQU     13
SHDID_NET_SERVER                                EQU     14
SHDID_NET_SHARE                                 EQU     15
SHDID_NET_RESTOFNET                             EQU     16
SHDID_NET_OTHER                                 EQU     17
SHDID_COMPUTER_IMAGING                          EQU     18
SHDID_COMPUTER_AUDIO                            EQU     19
SHDID_COMPUTER_SHAREDDOCS                       EQU     20
SHDID_MOBILE_DEVICE                             EQU     21

SHGDFIL_FINDDATA                                EQU     1
SHGDFIL_NETRESOURCE                             EQU     2
SHGDFIL_DESCRIPTIONID                           EQU     3

SHGFI_ICON                                      EQU     0000000100H
SHGFI_DISPLAYNAME                               EQU     0000000200H
SHGFI_TYPENAME                                  EQU     0000000400H
SHGFI_ATTRIBUTES                                EQU     0000000800H
SHGFI_ICONLOCATION                              EQU     0000001000H
SHGFI_EXETYPE                                   EQU     0000002000H
SHGFI_SYSICONINDEX                              EQU     0000004000H
SHGFI_LINKOVERLAY                               EQU     0000008000H
SHGFI_SELECTED                                  EQU     0000010000H
SHGFI_ATTR_SPECIFIED                            EQU     0000020000H
SHGFI_LARGEICON                                 EQU     0000000000H
SHGFI_SMALLICON                                 EQU     0000000001H
SHGFI_OPENICON                                  EQU     0000000002H
SHGFI_SHELLICONSIZE                             EQU     0000000004H
SHGFI_PIDL                                      EQU     0000000008H
SHGFI_USEFILEATTRIBUTES                         EQU     0000000010H
SHGFI_ADDOVERLAYS                               EQU     0000000020H
SHGFI_OVERLAYINDEX                              EQU     0000000040H

SHGSI_ICONLOCATION                              EQU     0
SHGSI_ICON                                      EQU     SHGFI_ICON
SHGSI_SYSICONINDEX                              EQU     SHGFI_SYSICONINDEX
SHGSI_LINKOVERLAY                               EQU     SHGFI_LINKOVERLAY
SHGSI_SELECTED                                  EQU     SHGFI_SELECTED
SHGSI_LARGEICON                                 EQU     SHGFI_LARGEICON
SHGSI_SMALLICON                                 EQU     SHGFI_SMALLICON
SHGSI_SHELLICONSIZE                             EQU     SHGFI_SHELLICONSIZE

SIID_DOCNOASSOC                                 EQU     0
SIID_DOCASSOC                                   EQU     1
SIID_APPLICATION                                EQU     2
SIID_FOLDER                                     EQU     3
SIID_FOLDEROPEN                                 EQU     4
SIID_DRIVE525                                   EQU     5
SIID_DRIVE35                                    EQU     6
SIID_DRIVEREMOVE                                EQU     7
SIID_DRIVEFIXED                                 EQU     8
SIID_DRIVENET                                   EQU     9
SIID_DRIVENETDISABLED                           EQU     10
SIID_DRIVECD                                    EQU     11
SIID_DRIVERAM                                   EQU     12
SIID_WORLD                                      EQU     13
SIID_SERVER                                     EQU     15
SIID_PRINTER                                    EQU     16
SIID_MYNETWORK                                  EQU     17
SIID_FIND                                       EQU     22
SIID_HELP                                       EQU     23
SIID_SHARE                                      EQU     28
SIID_LINK                                       EQU     29
SIID_SLOWFILE                                   EQU     30
SIID_RECYCLER                                   EQU     31
SIID_RECYCLERFULL                               EQU     32
SIID_MEDIACDAUDIO                               EQU     40
SIID_LOCK                                       EQU     47
SIID_AUTOLIST                                   EQU     49
SIID_PRINTERNET                                 EQU     50
SIID_SERVERSHARE                                EQU     51
SIID_PRINTERFAX                                 EQU     52
SIID_PRINTERFAXNET                              EQU     53
SIID_PRINTERFILE                                EQU     54
SIID_STACK                                      EQU     55
SIID_MEDIASVCD                                  EQU     56
SIID_STUFFEDFOLDER                              EQU     57
SIID_DRIVEUNKNOWN                               EQU     58
SIID_DRIVEDVD                                   EQU     59
SIID_MEDIADVD                                   EQU     60
SIID_MEDIADVDRAM                                EQU     61
SIID_MEDIADVDRW                                 EQU     62
SIID_MEDIADVDR                                  EQU     63
SIID_MEDIADVDROM                                EQU     64
SIID_MEDIACDAUDIOPLUS                           EQU     65
SIID_MEDIACDRW                                  EQU     66
SIID_MEDIACDR                                   EQU     67
SIID_MEDIACDBURN                                EQU     68
SIID_MEDIABLANKCD                               EQU     69
SIID_MEDIACDROM                                 EQU     70
SIID_AUDIOFILES                                 EQU     71
SIID_IMAGEFILES                                 EQU     72
SIID_VIDEOFILES                                 EQU     73
SIID_MIXEDFILES                                 EQU     74
SIID_FOLDERBACK                                 EQU     75
SIID_FOLDERFRONT                                EQU     76
SIID_SHIELD                                     EQU     77
SIID_WARNING                                    EQU     78
SIID_INFO                                       EQU     79
SIID_ERROR                                      EQU     80
SIID_KEY                                        EQU     81
SIID_SOFTWARE                                   EQU     82
SIID_RENAME                                     EQU     83
SIID_DELETE                                     EQU     84
SIID_MEDIAAUDIODVD                              EQU     85
SIID_MEDIAMOVIEDVD                              EQU     86
SIID_MEDIAENHANCEDCD                            EQU     87
SIID_MEDIAENHANCEDDVD                           EQU     88
SIID_MEDIAHDDVD                                 EQU     89
SIID_MEDIABLURAY                                EQU     90
SIID_MEDIAVCD                                   EQU     91
SIID_MEDIADVDPLUSR                              EQU     92
SIID_MEDIADVDPLUSRW                             EQU     93
SIID_DESKTOPPC                                  EQU     94
SIID_MOBILEPC                                   EQU     95
SIID_USERS                                      EQU     96
SIID_MEDIASMARTMEDIA                            EQU     97
SIID_MEDIACOMPACTFLASH                          EQU     98
SIID_DEVICECELLPHONE                            EQU     99
SIID_DEVICECAMERA                               EQU     100
SIID_DEVICEVIDEOCAMERA                          EQU     101
SIID_DEVICEAUDIOPLAYER                          EQU     102
SIID_NETWORKCONNECT                             EQU     103
SIID_INTERNET                                   EQU     104
SIID_ZIPFILE                                    EQU     105
SIID_SETTINGS                                   EQU     106
SIID_DRIVEHDDVD                                 EQU     132
SIID_DRIVEBD                                    EQU     133
SIID_MEDIAHDDVDROM                              EQU     134
SIID_MEDIAHDDVDR                                EQU     135
SIID_MEDIAHDDVDRAM                              EQU     136
SIID_MEDIABDROM                                 EQU     137
SIID_MEDIABDR                                   EQU     138
SIID_MEDIABDRE                                  EQU     139
SIID_CLUSTEREDDRIVE                             EQU     140
SIID_MAX_ICONS                                  EQU     175

SIID_INVALID                                    EQU     (-1)

SHGNLI_PIDL                                     EQU     0000000001H
SHGNLI_PREFIXNAME                               EQU     0000000002H
SHGNLI_NOUNIQUE                                 EQU     0000000004H
SHGNLI_NOLNK                                    EQU     0000000008H
SHGNLI_NOLOCNAME                                EQU     0000000010H
SHGNLI_USEURLEXT                                EQU     0000000020H

PRINTACTION_OPEN                                EQU     0
PRINTACTION_PROPERTIES                          EQU     1
PRINTACTION_NETINSTALL                          EQU     2
PRINTACTION_NETINSTALLLINK                      EQU     3
PRINTACTION_TESTPAGE                            EQU     4
PRINTACTION_OPENNETPRN                          EQU     5
PRINTACTION_DOCUMENTDEFAULTS                    EQU     6
PRINTACTION_SERVERPROPERTIES                    EQU     7

OFFLINE_STATUS_LOCAL                            EQU     00001H
OFFLINE_STATUS_REMOTE                           EQU     00002H
OFFLINE_STATUS_INCOMPLETE                       EQU     00004H

SHIL_LARGE                                      EQU     0
SHIL_SMALL                                      EQU     1
SHIL_EXTRALARGE                                 EQU     2
SHIL_SYSSMALL                                   EQU     3
IF (NTDDI_VERSION GE NTDDI_VISTA)
    SHIL_JUMBO                                  EQU     4
    SHIL_LAST                                   EQU     SHIL_JUMBO
ELSE
    SHIL_LAST                                   EQU     SHIL_SYSSMALL
ENDIF

WC_NETADDRESS                                   EQU     L("msctls_netaddress")

NCM_SETALLOWTYPE                                EQU     (WM_USER + 2)
NCM_GETALLOWTYPE                                EQU     (WM_USER + 3)
NCM_DISPLAYERRORTIP                             EQU     (WM_USER + 4)

SCNRT_ENABLE                                    EQU     0
SCNRT_DISABLE                                   EQU     1

GPFIDL_DEFAULT                                  EQU     00000H
GPFIDL_ALTNAME                                  EQU     00001H
GPFIDL_UNCPRINTER                               EQU     00002H

SIGDN_NORMALDISPLAY                             EQU     00000000H
SIGDN_PARENTRELATIVEPARSING                     EQU     80018001H
SIGDN_DESKTOPABSOLUTEPARSING                    EQU     80028000H
SIGDN_PARENTRELATIVEEDITING                     EQU     80031001H
SIGDN_DESKTOPABSOLUTEEDITING                    EQU     8004c000H
SIGDN_FILESYSPATH                               EQU     80058000H
SIGDN_URL                                       EQU     80068000H
SIGDN_PARENTRELATIVEFORADDRESSBAR               EQU     8007C001H
SIGDN_PARENTRELATIVE                            EQU     80080001H
SIGDN_PARENTRELATIVEFORUI                       EQU     80094001H

GPS_DEFAULT                                     EQU     0H
GPS_HANDLERPROPERTIESONLY                       EQU     01H
GPS_READWRITE                                   EQU     02H
GPS_TEMPORARY                                   EQU     04H
GPS_FASTPROPERTIESONLY                          EQU     08H
GPS_OPENSLOWITEM                                EQU     010H
GPS_DELAYCREATION                               EQU     020H
GPS_BESTEFFORT                                  EQU     040H
GPS_NO_OPLOCK                                   EQU     080H
GPS_PREFERQUERYPROPERTIES                       EQU     0100H
GPS_MASK_VALID                                  EQU     01FFH
GPS_EXTRINSICPROPERTIES                         EQU     00000200H
GPS_EXTRINSICPROPERTIESONLY                     EQU     00000400H

DOGIF_DEFAULT                                   EQU     0000H
DOGIF_TRAVERSE_LINK                             EQU     0001H
DOGIF_NO_HDROP                                  EQU     0002H
DOGIF_NO_URL                                    EQU     0004H
DOGIF_ONLY_IF_ONE                               EQU     0008H

KF_FLAG_SIMPLE_IDLIST                           EQU     00000100H
KF_FLAG_NOT_PARENT_RELATIVE                     EQU     00000200H
KF_FLAG_DEFAULT_PATH                            EQU     00000400H
KF_FLAG_INIT                                    EQU     00000800H
KF_FLAG_NO_ALIAS                                EQU     00001000H
KF_FLAG_DONT_UNEXPAND                           EQU     00002000H
KF_FLAG_DONT_VERIFY                             EQU     00004000H
KF_FLAG_CREATE                                  EQU     00008000H
KF_FLAG_NO_APPCONTAINER_REDIRECTION             EQU     00010000H
KF_FLAG_ALIAS_ONLY                              EQU     80000000H

LMD_DEFAULT                                     EQU     00000000H
LMD_ALLOWUNINDEXABLENETWORKLOCATIONS            EQU     00000001H


;======================================== Structures ======================================;
DRAGINFOA STRUCT ALIGNMODE
    uSize       DD  ?
    pt          POINT <>
    fNC         DD  ?
    lpFileList  XPTR ?
    grfKeyState DD  ?
DRAGINFOA ENDS

DRAGINFOW STRUCT ALIGNMODE
    uSize       DD  ?
    pt          POINT <>
    fNC         DD  ?
    lpFileList  XPTR ?
    grfKeyState DD  ?
DRAGINFOW ENDS

APPBARDATA STRUCT ALIGNMODE
    cbSize           DD    ?
    hWnd             HWND  ?
    uCallbackMessage DD    ?
    uEdge            DD    ?
    rc               RECT <> 
    lParam           LPARAM ?
APPBARDATA ENDS

SHFILEOPSTRUCTA STRUCT ALIGNMODE
    hwnd                   HWND ?
    wFunc                  DD   ?
    pFrom                  XPTR ?
    pTo                    XPTR ?
    fFlags                 FILEOP_FLAGS ?
    fAnyOperationsAborted  DD   ?
    hNameMappings          XPTR ?
    lpszProgressTitle      XPTR ?
SHFILEOPSTRUCTA ENDS

SHFILEOPSTRUCTW STRUCT ALIGNMODE
    hwnd                   HWND ?
    wFunc                  DD   ?
    pFrom                  XPTR ?
    pTo                    XPTR ?
    fFlags                 FILEOP_FLAGS ?
    fAnyOperationsAborted  DD   ?
    hNameMappings          XPTR ?
    lpszProgressTitle      XPTR ?
SHFILEOPSTRUCTW ENDS

SHNAMEMAPPINGA STRUCT ALIGNMODE
    pszOldPath XPTR ?
    pszNewPath XPTR ?
    cchOldPath DD   ?
    cchNewPath DD   ?
SHNAMEMAPPINGA ENDS

SHNAMEMAPPINGW STRUCT ALIGNMODE
    pszOldPath XPTR ?
    pszNewPath XPTR ?
    cchOldPath DD   ?
    cchNewPath DD   ?
SHNAMEMAPPINGW ENDS

SHELLEXECUTEINFOA STRUCT ALIGNMODE
    cbSize         DD   ?
    fMask          DD   ?
    hwnd           HWND ?
    lpVerb         XPTR ?
    lpFile         XPTR ?
    lpParameters   XPTR ?
    lpDirectory    XPTR ?
    nShow          DD   ?
    hInstApp       HINSTANCE ?
    lpIDList       XPTR ?
    lpClass        XPTR ?
    hkeyClass      HKEY ?
    dwHotKey       DD   ?
    UNION u
        hIcon      HANDLE ?
        hMonitor   HANDLE ?
    ENDS
    hProcess       HANDLE ?
SHELLEXECUTEINFOA ENDS

SHELLEXECUTEINFOW STRUCT ALIGNMODE
    cbSize         DD   ?
    fMask          DD   ?
    hwnd           HWND ?
    lpVerb         XPTR ?
    lpFile         XPTR ?
    lpParameters   XPTR ?
    lpDirectory    XPTR ?
    nShow          DD   ?
    hInstApp       HINSTANCE ?
    lpIDList       XPTR ?
    lpClass        XPTR ?
    hkeyClass      HKEY ?
    dwHotKey       DD   ?
    UNION u
        hIcon      HANDLE ?
        hMonitor   HANDLE ?
    ENDS
    hProcess       HANDLE ?
SHELLEXECUTEINFOW ENDS

SHCREATEPROCESSINFOW STRUCT ALIGNMODE
    cbSize               DD      ?
    fMask                ULONG   ?
    hwnd                 HWND    ?
    pszFile              LPCWSTR ?
    pszParameters        LPCWSTR ?
    pszCurrentDirectory  LPCWSTR ?
    hUserToken           HANDLE  ?
    lpProcessAttributes  XPTR    ?
    lpThreadAttributes   XPTR    ?
    bInheritHandles      BOOL    ?
    dwCreationFlags      DD      ?
    lpStartupInfo        XPTR    ?
    lpProcessInformation XPTR    ?
SHCREATEPROCESSINFOW ENDS

ASSOCIATIONELEMENT STRUCT ALIGNMODE
    ac         DD   ?
    hkClass    HKEY ?
    pszClass   XPTR ?
ASSOCIATIONELEMENT ENDS

SHQUERYRBINFO STRUCT ALIGNMODE
    cbSize      DD    ?
    i64Size     DQ    ?
    i64NumItems DQ    ?
SHQUERYRBINFO ENDS

NOTIFYICONDATAA STRUCT ALIGNMODE
    cbSize              DD   ?
    hWnd                HWND ?
    uID                 DD   ?
    uFlags              DD   ?
    uCallbackMessage    DD   ?
    hIcon               HICON ?
    IF (NTDDI_VERSION LT  NTDDI_WIN2K)
        szTip           CHAR 64 DUP(?)
    ENDIF
    IF (NTDDI_VERSION GE NTDDI_WIN2K)
        szTip           CHAR 128 DUP(?)
        dwState         DD   ?
        dwStateMask     DD   ?
        szInfo          CHAR 256 DUP(?)
        UNION u
            uTimeout    DD   ?
            uVersion    DD   ?
        ENDS
        szInfoTitle     CHAR 64 DUP(?)
        dwInfoFlags     DD   ?
    ENDIF 
    IF (NTDDI_VERSION GE NTDDI_WINXP)
        guidItem        GUID <> 
    ENDIF
    IF (NTDDI_VERSION GE NTDDI_VISTA)
        hBalloonIcon    HICON ?
    ENDIF
NOTIFYICONDATAA ENDS

NOTIFYICONDATAW STRUCT ALIGNMODE
    cbSize              DD   ?
    hWnd                HWND ?
    uID                 DD   ?
    uFlags              DD   ?
    uCallbackMessage    DD   ?
    hIcon               HICON ?
    IF (NTDDI_VERSION LT  NTDDI_WIN2K)
        szTip           WCHAR 64 DUP(?)
    ENDIF
    IF (NTDDI_VERSION GE NTDDI_WIN2K)
        szTip           WCHAR 128 DUP(?)
        dwState         DD   ?
        dwStateMask     DD   ?
        szInfo          WCHAR 256 DUP(?)
        UNION u
            uTimeout    DD   ?
            uVersion    DD   ?
        ENDS
        szInfoTitle     WCHAR 64 DUP(?)
        dwInfoFlags     DD   ?
    ENDIF 
    IF (NTDDI_VERSION GE NTDDI_WINXP)
        guidItem        GUID <> 
    ENDIF
    IF (NTDDI_VERSION GE NTDDI_VISTA)
        hBalloonIcon    HICON ?
    ENDIF
NOTIFYICONDATAW ENDS

NOTIFYICONIDENTIFIER STRUCT ALIGNMODE
    cbSize     DD   ?
    hWnd       HWND ?
    uID        DD   ?
    guidItem   GUID <> 
NOTIFYICONIDENTIFIER ENDS

SHFILEINFOA STRUCT ALIGNMODE
    hIcon           HICON ?
    iIcon           DD  ?
    dwAttributes    DD  ?
    szDisplayName   CHAR MAX_PATH DUP(?)
    szTypeName      CHAR 80 DUP(?)
SHFILEINFOA ENDS

SHFILEINFOW STRUCT ALIGNMODE
    hIcon           HICON ?
    iIcon           DD  ?
    dwAttributes    DD  ?
    szDisplayName   WCHAR MAX_PATH DUP(?)
    szTypeName      WCHAR 80 DUP(?)
SHFILEINFOW ENDS

SHSTOCKICONINFO STRUCT ALIGNMODE
    cbSize         DD  ?
    hIcon          HICON ?
    iSysImageIndex DD  ?
    iIcon          DD  ?
    szPath         WCHAR MAX_PATH DUP(?)
SHSTOCKICONINFO ENDS

OPEN_PRINTER_PROPS_INFOA STRUCT ALIGNMODE
    dwSize       DD   ?
    pszSheetName XPTR ?
    uSheetIndex  DD   ?
    dwFlags      DD   ?
    bModal       BOOL ?
OPEN_PRINTER_PROPS_INFOA ENDS

OPEN_PRINTER_PROPS_INFOW STRUCT ALIGNMODE
    dwSize       DD   ?
    pszSheetName XPTR ?
    uSheetIndex  DD   ?
    dwFlags      DD   ?
    bModal       BOOL ?
OPEN_PRINTER_PROPS_INFOW ENDS

NC_ADDRESS STRUCT ALIGNMODE
    pAddrInfo      XPTR ?
    PortNumber     WORD ?
    PrefixLength   DB   ?
NC_ADDRESS ENDS

IFNDEF DLLVERSIONINFO
    DLLVERSIONINFO STRUCT ALIGNMODE
        cbSize          DD  ?
        dwMajorVersion  DD  ?
        dwMinorVersion  DD  ?
        dwBuildNumber   DD  ?
        dwPlatformID    DD  ?
    DLLVERSIONINFO ENDS
ENDIF

RUNASNEWUSERPARAM STRUCT ALIGNMODE
    eventName WCHAR 56 DUP(?)
    execFile  WCHAR MAX_PATH DUP(?)
    arguments WCHAR MAX_PATH DUP(?)
    padding   WCHAR 1536 DUP(?)
    directory WCHAR (MAX_PATH - 4) DUP(?)
RUNASNEWUSERPARAM ENDS


;======================================== Functions =======================================;
CheckEscapesW PROTO :LPWSTR, :XWORD
CommandLineToArgvW PROTO :LPCWSTR, :XWORD
Control_RunDLLA PROTO :HWND, :HINSTANCE, :LPCSTR, :XWORD
Control_RunDLLW PROTO :HWND, :HINSTANCE, :LPCSTR, :XWORD
IFNDEF DllGetClassObject
    DllGetClassObject PROTO :XPTR, :XPTR, :XPTR
ENDIF
DllGetVersion PROTO :XPTR
DoEnvironmentSubstA PROTO :LPTSTR, :XWORD
DoEnvironmentSubstW PROTO :LPWSTR, :XWORD
DragAcceptFiles PROTO :HWND, :XWORD
DragFinish PROTO :HDROP
DragQueryFileAorW PROTO :HDROP, :XWORD, :LPWSTR, :XWORD, :XWORD, :XWORD
DragQueryFileW PROTO :HDROP, :XWORD, :LPWSTR, :XWORD
DragQueryPoint PROTO:HDROP, :XPTR
DriveType PROTO :XWORD
DuplicateIcon PROTO :HINSTANCE, :HICON
ExtractAssociatedIconA PROTO :HINSTANCE, :LPTSTR, :LPWORD
ExtractAssociatedIconExA PROTO :HINSTANCE, :LPTSTR, :LPWORD, :LPWORD
ExtractAssociatedIconExW PROTO :HINSTANCE, :LPTSTR, :LPWORD, :LPWORD
ExtractAssociatedIconW PROTO :HINSTANCE, :LPWSTR, :LPWORD
ExtractIconA PROTO :HINSTANCE, :LPCTSTR, :XWORD
ExtractIconW PROTO :HINSTANCE, :LPCWSTR, :XWORD
FindExecutableA PROTO :LPCTSTR, :LPCTSTR, :LPTSTR
FindExecutableW PROTO :LPCWSTR, :LPCWSTR, :LPWSTR
FreeIconList PROTO :XWORD
InternalExtractIconListA PROTO :HANDLE, :LPTSTR, :XPTR
InternalExtractIconListW PROTO :HANDLE, :LPWSTR, :XPTR
RealShellExecuteA PROTO :LPCTSTR, :LPCTSTR, :LPCTSTR, :LPCTSTR, :LPCTSTR, :LPCTSTR, :LPCTSTR, :LPCTSTR, :LPCTSTR, :LPCTSTR
RealShellExecuteExA PROTO :LPCTSTR, :LPCTSTR, :LPCTSTR, :LPCTSTR, :LPCTSTR, :LPCTSTR, :LPCTSTR, :LPCTSTR, :LPCTSTR, :LPCTSTR, :LPCTSTR
RealShellExecuteExW PROTO :LPCWSTR, :LPCWSTR, :LPCWSTR, :LPCWSTR, :LPCWSTR, :LPCWSTR, :LPCWSTR, :LPCWSTR, :LPCWSTR, :LPCWSTR, :LPCWSTR
RealShellExecuteW PROTO :LPCWSTR, :LPCWSTR, :LPCWSTR, :LPCWSTR, :LPCWSTR, :LPCWSTR, :LPCWSTR, :LPCWSTR, :LPCWSTR, :LPCWSTR
RegenerateUserEnvironment PROTO :LPVOID, :XWORD
SHAddToRecentDocs PROTO :XWORD, :LPCVOID
SHAppBarMessage PROTO :XWORD, :XPTR
SHChangeNotify PROTO :XWORD, :XWORD, :LPCVOID, :LPCVOID
SheGetDirA PROTO :LPTSTR, :LPTSTR
SheGetDirW PROTO :LPWSTR, :LPWSTR
ShellAboutA PROTO :HWND, :LPCTSTR, :LPCTSTR, :HICON
ShellAboutW PROTO :HWND, :LPCWSTR, :LPCWSTR, :HICON
ShellExecuteA PROTO :HWND, :LPCTSTR, :LPCTSTR, :LPCTSTR, :LPCTSTR, :XWORD
ShellExecuteW PROTO :HWND, :LPCTSTR, :LPCWSTR, :LPCWSTR, :LPCWSTR, :XWORD
SheSetCurDrive PROTO :LPCTSTR
SHFormatDrive PROTO :HWND, :XWORD, :XWORD, :XWORD
SHFreeNameMappings PROTO :HANDLE
SHGetDesktopFolder PROTO :XPTR
SHGetInstanceExplorer PROTO :XPTR
SHGetMalloc PROTO :XPTR
SHGetSpecialFolderLocation PROTO:HWND, :XWORD, :XPTR
SHLoadInProc PROTO :XPTR

IF (NTDDI_VERSION GT NTDDI_WIN95)
    DragQueryFileA PROTO :HDROP, :XWORD, :LPTSTR, :XWORD
    DragQueryFileW PROTO :HDROP, :XWORD, :LPWSTR, :XWORD
    ExtractIconExA PROTO :LPCTSTR, :XWORD, :HICON, :HICON, :XWORD
    ExtractIconExW PROTO :LPCWSTR, :XWORD, :HICON, :HICON, :XWORD
    OpenAs_RunDLLA PROTO :LPSTR
    OpenAs_RunDLLW PROTO :LPWSTR
    SHBrowseForFolderA PROTO :XPTR
    SHBrowseForFolderW PROTO :XPTR
    Shell_NotifyIconA PROTO :XWORD, :XPTR
    Shell_NotifyIconW PROTO :XWORD, :XPTR
    ShellExecuteExA PROTO :XPTR
    ShellExecuteExW PROTO :XPTR
    SHFileOperationA PROTO :XPTR
    SHFileOperationW PROTO :XPTR
    SHGetDataFromIDListA PROTO :XPTR, :XPTR, :XWORD, :LPVOID, :XWORD
    SHGetDataFromIDListW PROTO :XPTR, :XPTR, :XWORD, :LPVOID, :XWORD
    SHGetFileInfoA PROTO :LPCTSTR, :XWORD, :XPTR, :XWORD, :XWORD
    SHGetFileInfoW PROTO :LPCWSTR, :XWORD, :XPTR, :XWORD, :XWORD
    SHGetPathFromIDListA PROTO :XPTR, :LPTSTR
    SHGetPathFromIDListW PROTO :XPTR, :LPTSTR
    SHHelpShortcuts_RunDLLA PROTO :HWND, :HINSTANCE, :LPCSTR, :XWORD
    SHHelpShortcuts_RunDLLW PROTO :HWND, :HINSTANCE, :LPWSTR, :XWORD

    IFDEF APP_UNICODE
        DragQueryFile EQU <DragQueryFileW>
        ExtractIconEx EQU <ExtractIconExW>
        OpenAs_RunDLL EQU <OpenAs_RunDLLW>
        SHBrowseForFolder EQU <SHBrowseForFolderW>
        ShellExecuteEx EQU <ShellExecuteExW>
        SHGetDataFromIDList EQU <SHGetDataFromIDListW>
        Shell_NotifyIcon EQU <Shell_NotifyIconW>
        SHFileOperation EQU <SHFileOperationW>
        SHGetFileInfo EQU <SHGetFileInfoW>
        SHGetPathFromIDList EQU <SHGetPathFromIDListW>
        SHHelpShortcuts_RunDLL EQU <SHHelpShortcuts_RunDLLW>
    ELSE
        DragQueryFile EQU <DragQueryFileA>
        ExtractIconEx EQU <ExtractIconExA>
        OpenAs_RunDLL EQU <OpenAs_RunDLLA>
        SHBrowseForFolder EQU <SHBrowseForFolderA>
        ShellExecuteEx EQU <ShellExecuteExA>
        SHGetDataFromIDList EQU <SHGetDataFromIDListA>
        Shell_NotifyIcon EQU <Shell_NotifyIconA>
        SHFileOperation EQU <SHFileOperationA>
        SHGetFileInfo EQU <SHGetFileInfoA>
        SHGetPathFromIDList EQU <SHGetPathFromIDListA>
        SHHelpShortcuts_RunDLL EQU <SHHelpShortcuts_RunDLLA>
    ENDIF
ELSE
    DragQueryFile PROTO :HDROP, :XWORD, :LPTSTR, :XWORD
    DragQueryFileA PROTO :HDROP, :XWORD, :LPTSTR, :XWORD
    ExtractIconEx PROTO :LPCTSTR, :XWORD, :HICON, :HICON, :XWORD
    ExtractIconExA PROTO :LPCTSTR, :XWORD, :HICON, :HICON, :XWORD
    OpenAs_RunDLL PROTO :LPSTR
    OpenAs_RunDLLA PROTO :LPSTR
    SHBrowseForFolder PROTO :XPTR
    SHBrowseForFolderA PROTO :XPTR
    Shell_NotifyIcon PROTO :XWORD, :XPTR
    Shell_NotifyIconA PROTO :XWORD, :XPTR
    ShellExecuteEx PROTO :XPTR
    ShellExecuteExA PROTO :XPTR
    SHFileOperation PROTO :XPTR
    SHFileOperationA PROTO :XPTR
    SHGetDataFromIDList PROTO :XPTR, :XPTR, :XWORD, :LPVOID, :XWORD
    SHGetDataFromIDListA PROTO :XPTR, :XPTR, :XWORD, :LPVOID, :XWORD
    SHGetFileInfo PROTO :LPCTSTR, :XWORD, :XPTR, :XWORD, :XWORD
    SHGetFileInfoA PROTO :LPCTSTR, :XWORD, :XPTR, :XWORD, :XWORD
    SHGetPathFromIDList PROTO :XPTR, :LPTSTR
    SHGetPathFromIDListA PROTO :XPTR, :LPTSTR
    SHHelpShortcuts_RunDLL PROTO :HWND, :HINSTANCE, :LPCSTR, :XWORD
ENDIF


IF (NTDDI_VERSION GE NTDDI_WIN98_ME)
    IF (NTDDI_VERSION LE NTDDI_WINXP)
        FindExeDlgProc PROTO :XWORD, :XWORD, :XWORD, :XWORD
    ENDIF
    IF (NTDDI_VERSION NE NTDDI_WINNT4)
        IFNDEF DllCanUnloadNow
            DllCanUnloadNow PROTO
        ENDIF
        SHEmptyRecycleBinA PROTO :HWND, :LPCTSTR, :XWORD
        SHEmptyRecycleBinW PROTO :HWND, :LPCWSTR, :XWORD
        SHGetSettings PROTO :XPTR, :XWORD
        SHGetSpecialFolderPathA PROTO :HWND, :LPTSTR, :XWORD, :XWORD
        SHGetSpecialFolderPathW PROTO :HWND, :LPWSTR, :XWORD, :XWORD
        SHInvokePrinterCommandA PROTO :HWND, :XWORD,:LPCTSTR,:LPCTSTR, :XWORD
        SHInvokePrinterCommandW PROTO :HWND, :XWORD,:LPCWSTR,:LPCWSTR, :XWORD
        SHQueryRecycleBinA PROTO :LPCTSTR, :XPTR
        SHQueryRecycleBinW PROTO :LPCWSTR, :XPTR

        IFDEF APP_UNICODE
            SHEmptyRecycleBin EQU <SHEmptyRecycleBinW>
            SHGetSpecialFolderPath EQU <SHGetSpecialFolderPathW>
            SHInvokePrinterCommand EQU <SHInvokePrinterCommandW>
            SHQueryRecycleBin EQU <SHQueryRecycleBinW>
        ELSE
            SHEmptyRecycleBin EQU <SHEmptyRecycleBinA>
            SHGetSpecialFolderPath EQU <SHGetSpecialFolderPathA>
            SHInvokePrinterCommand EQU <SHInvokePrinterCommandA>
            SHQueryRecycleBin EQU <SHQueryRecycleBinA>
        ENDIF
    ENDIF
    ShellHookProc PROTO :XWORD, :XWORD, :XWORD
    SHGetDiskFreeSpaceA PROTO :LPCTSTR, :XPTR, :XPTR, :XPTR
    IFNDEF APP_UNICODE
        SHGetDiskFreeSpace EQU <SHGetDiskFreeSpaceA>
    ENDIF
    SHUpdateRecycleBinIcon PROTO
ENDIF

IF (NTDDI_VERSION GE NTDDI_WINNT4)
    StrChrA PROTO :LPTSTR, :XWORD
    StrChrIA PROTO :LPTSTR, :XWORD
    StrChrIW PROTO :LPWSTR, :XWORD
    StrChrW PROTO :LPWSTR, :XWORD
    StrCmpNA PROTO :LPTSTR, :LPTSTR, :XWORD
    StrCmpNIA PROTO :LPTSTR, :LPTSTR, :XWORD
    StrCmpNIW PROTO :LPWSTR, :LPWSTR, :XWORD
    StrCmpNW PROTO :LPWSTR, :LPWSTR, :XWORD
    StrNCmpA PROTO :LPTSTR, :LPTSTR, :XWORD
    StrNCmpIA PROTO :LPTSTR, :LPTSTR, :XWORD
    StrNCmpIW PROTO :LPWSTR, :LPWSTR, :XWORD
    StrNCmpW PROTO :LPWSTR, :LPWSTR, :XWORD
    StrRChrA PROTO :LPTSTR, :LPTSTR, :XWORD
    StrRChrIA PROTO :LPTSTR, :LPTSTR, :XWORD
    StrRChrIW PROTO :LPWSTR, :LPWSTR, :XWORD
    StrRChrW PROTO :LPWSTR, :LPWSTR, :XWORD
    StrRStrA PROTO :LPTSTR, :LPTSTR, :LPTSTR
    StrRStrIA PROTO :LPTSTR, :LPTSTR, :LPTSTR
    StrRStrIW PROTO :LPWSTR, :LPWSTR, :LPWSTR
    StrRStrW PROTO :LPWSTR, :LPWSTR, :LPWSTR
    StrStrA PROTO :LPSTR, :LPTSTR
    StrStrIA PROTO :LPSTR, :LPTSTR
    StrStrIW PROTO :LPWSTR, :LPWSTR
    StrStrW PROTO :LPWSTR, :LPWSTR
    WOWShellExecute PROTO :HWND, :LPCTSTR, :LPCTSTR, :LPCTSTR, :LPCTSTR, :XWORD, :XPTR

    IFDEF APP_UNICODE
        StrChr EQU <StrChrW>
        StrChrI EQU <StrChrIW>
        StrCmpN EQU <StrCmpNW>
        StrCmpNI EQU <StrCmpNIW>
        StrNCmp EQU <StrNCmpW>
        StrNCmpI EQU <StrNCmpIW>
        StrRChr EQU <StrRChrW>
        StrRChrI EQU <StrRChrIW>
        StrRStr EQU <StrRStrW>
        StrRStrI EQU <StrRStrIW>
        StrStr EQU <StrStrW>
        StrStrI EQU <StrStrIW>
    ELSE
        StrChr EQU <StrChrA>
        StrChrI EQU <StrChrIA>
        StrCmpN EQU <StrCmpNA>
        StrCmpNI EQU <StrCmpNIA>
        StrNCmp EQU <StrNCmpA>
        StrNCmpI EQU <StrNCmpIA>
        StrRChr EQU <StrRChrA>
        StrRChrI EQU <StrRChrIA>
        StrRStr EQU <StrRStrA>
        StrRStrI EQU <StrRStrIA>
        StrStr EQU <StrStrA>
        StrStrI EQU <StrStrIA>
    ENDIF
ENDIF

IF (NTDDI_VERSION GE NTDDI_WIN2K)
    IF (NTDDI_VERSION LE NTDDI_WINXPSP2)
        CallCPLEntry16 PROTO :HINSTANCE, :XPTR, :HWND, :XWORD, :XWORD, :XWORD
        SHMapIDListToImageListIndexAsync PROTO :XPTR, :XPTR, :XWORD, :XWORD, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR
    ENDIF
    IFNDEF DllRegisterServer
        DllRegisterServer PROTO
    ENDIF
    IFNDEF DllUnregisterServer
        DllUnregisterServer PROTO
    ENDIF
    SHBindToParent PROTO :XPTR, :XWORD, :XPTR, :XPTR
    SHCreateDirectory PROTO :HWND, :LPWSTR
    SHCreateDirectoryExA PROTO :HWND, :LPCSTR, :XPTR
    SHCreateDirectoryExW PROTO :HWND, :LPWSTR, :XPTR
    ShellExec_RunDLLA PROTO :LPCSTR
    ShellExec_RunDLLW PROTO :LPWSTR
    SHGetDiskFreeSpaceExA PROTO :LPCTSTR, :XPTR, :XPTR, :XPTR
    SHGetDiskFreeSpaceExW PROTO :LPCWSTR, :XPTR, :XPTR, :XPTR
    SHGetFolderLocation PROTO :HWND, :XWORD, :HANDLE, :XWORD, :XPTR
    SHGetFolderPathA PROTO :HWND, :XWORD, :HANDLE, :XWORD, :LPTSTR
    SHGetFolderPathW PROTO :HWND, :XWORD, :HANDLE, :XWORD, :LPWSTR
    SHGetNewLinkInfoA PROTO :LPCTSTR, :LPCTSTR, :LPCTSTR, :XWORD, :XWORD
    SHGetNewLinkInfoW PROTO :LPCWSTR, :LPCWSTR, :LPCWSTR, :XWORD, :XWORD
    SHPathPrepareForWriteA PROTO :HWND, :XPTR, :LPCTSTR, :XWORD
    SHPathPrepareForWriteW PROTO :HWND, :XPTR, :LPCWSTR, :XWORD

    IFDEF APP_UNICODE
        ShellExec_RunDLL EQU <ShellExec_RunDLLW>
        SHGetNewLinkInfo EQU <SHGetNewLinkInfoW>
        SHCreateDirectoryEx EQU <SHCreateDirectoryExW>
        SHGetDiskFreeSpaceEx EQU <SHGetDiskFreeSpaceExW>
        SHGetFolderPath EQU <SHGetFolderPathW>
        SHPathPrepareForWrite EQU <SHPathPrepareForWriteW>
    ELSE
        ShellExec_RunDLL EQU <ShellExec_RunDLLA>
        SHGetNewLinkInfo EQU <SHGetNewLinkInfoA>
        SHCreateDirectoryEx EQU <SHCreateDirectoryExA>
        SHGetDiskFreeSpaceEx EQU <SHGetDiskFreeSpaceExA>
        SHGetFolderPath EQU <SHGetFolderPathA>
        SHPathPrepareForWrite EQU <SHPathPrepareForWriteA>
    ENDIF
ELSE
    IF (NTDDI_VERSION GT NTDDI_WIN95)
        SHGetNewLinkInfo PROTO :LPCTSTR, :LPCTSTR, :LPCTSTR, :XWORD, :XWORD
    ENDIF
ENDIF

IF (NTDDI_VERSION LE NTDDI_WINXP)
    ExtractIconResInfoA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    ExtractIconResInfoW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    ExtractVersionResource16W PROTO :XWORD, :XWORD
    ILCreateFromPathA PROTO :LPCTSTR
    ILCreateFromPathW PROTO :LPCWSTR
    SheFullPathA PROTO :XWORD, :XWORD, :XWORD
    SheFullPathW PROTO :XWORD, :XWORD, :XWORD
    SheGetCurDrive PROTO
    SheGetDirExW PROTO :LPWSTR, :LPWSTR, :LPWSTR
    SheGetPathOffsetW PROTO :XWORD
    SheRemoveQuotesA PROTO :XWORD
    SheRemoveQuotesW PROTO :XWORD
    SheShortenPathA PROTO :XWORD, :XWORD
    SheShortenPathW PROTO :XWORD, :XWORD
    IFDEF APP_UNICODE
        ExtractIconResInfo EQU <ExtractIconResInfoW>
        ILCreateFromPath EQU <ILCreateFromPathW>
        SheFullPath EQU <SheFullPathW>
        SheRemoveQuotes EQU <SheRemoveQuotesW>
        SheShortenPath EQU <SheShortenPathW>
    ELSE
        ExtractIconResInfo EQU <ExtractIconResInfoA>
        ILCreateFromPath EQU <ILCreateFromPathA>
        SheFullPath EQU <SheFullPathA>
        SheRemoveQuotes EQU <SheRemoveQuotesA>
        SheShortenPath EQU <SheShortenPathA>
    ENDIF
ENDIF

IF (NTDDI_VERSION GE NTDDI_WINXP)
    AppCompat_RunDLLW PROTO :HWND, :HINSTANCE, :LPWSTR, :XWORD
    IF (NTDDI_VERSION LE NTDDI_VISTA)
        CDefFolderMenu_Create PROTO :XPTR, :HWND, :XWORD, :XPTR, :XPTR, :XPTR, :XWORD, :HKEY, :XPTR
        Control_FillCache_RunDLLA PROTO :HWND, :HANDLE, :XWORD, :XWORD
        Control_FillCache_RunDLLW PROTO :HWND, :HANDLE, :XWORD, :XWORD
        SHRunControlPanel PROTO :LPCWSTR, :HWND
    ENDIF
    CDefFolderMenu_Create2 PROTO :XPTR, :HWND, :XWORD, :XPTR, :XPTR, :XPTR, :XWORD, :HKEY, :XPTR
    Control_RunDLLAsUserW PROTO :HWND, :HINSTANCE, :LPWSTR, :XWORD
    DAD_AutoScroll PROTO :HWND, :XPTR, :XPTR
    DAD_DragEnterEx PROTO :HWND, :XPTR
    DAD_DragEnterEx2 PROTO :HWND, :XPTR, :XPTR
    DAD_DragLeave PROTO
    DAD_DragMove PROTO :XPTR
    DAD_SetDragImage PROTO :HANDLE, :XPTR
    DAD_ShowDragImage PROTO :XWORD
    GetFileNameFromBrowse PROTO :HWND, :LPWSTR, :XWORD, :LPCWSTR, :LPCWSTR, :LPCWSTR, :LPCWSTR
    ILAppendID PROTO :XPTR, :XPTR, :XWORD
    ILClone PROTO :XPTR
    ILCloneFirst PROTO :XPTR
    ILCombine PROTO :XPTR, :XPTR
    ILFindChild PROTO :XPTR, :XPTR
    ILFindLastID PROTO :XPTR
    ILFree PROTO :XPTR
    ILGetNext PROTO :XPTR
    ILGetSize PROTO :XPTR
    ILIsEqual PROTO :XPTR, :XPTR
    ILIsParent PROTO :XPTR, :XPTR, :XWORD
    IF (NTDDI_VERSION EQ NTDDI_WINXP)
        ILLoadFromStream PROTO :XPTR, :XPTR
        PathProcessCommand PROTO :XPTR, :XPTR, :XWORD, :XWORD
        SHAllocShared PROTO :XPTR, :XWORD, :XWORD
        SHGetSetFolderCustomSettingsW PROTO :XWORD, :XWORD, :XWORD
    ENDIF
    ILLoadFromStreamEx PROTO :XPTR, :XPTR
    ILRemoveLastID PROTO :XPTR
    ILSaveToStream PROTO :XPTR, :XPTR
    IsLFNDrive PROTO :LPCSTR
    IsLFNDriveA PROTO :LPCSTR
    IsLFNDriveW PROTO :LPCWSTR
    IsNetDrive PROTO :XWORD
    IsUserAnAdmin PROTO
    OpenRegStream PROTO :HKEY, :LPCWSTR, :LPCWSTR, :XWORD
    Options_RunDLLA PROTO :HWND, :HINSTANCE, :LPCSTR, :XWORD
    Options_RunDLLW PROTO :HWND, :HINSTANCE, :LPCWSTR, :XWORD
    PathCleanupSpec PROTO :LPCWSTR, :LPWSTR
    PathGetShortPath PROTO :LPWSTR
    PathIsExe PROTO :LPCWSTR
    PathIsSlowA PROTO :LPCTSTR, :XWORD
    PathIsSlowW PROTO :LPCWSTR, :XWORD
    PathMakeUniqueName PROTO :LPWSTR, :XWORD, :LPCWSTR, :LPCWSTR, :LPCWSTR
    PathResolve PROTO :LPWSTR, :XPTR, :XWORD
    PathYetAnotherMakeUniqueName PROTO :LPWSTR, :LPCWSTR, :LPCWSTR, :LPCWSTR
    PickIconDlg PROTO :HWND, :LPWSTR, :XWORD, :XWORD
    PifMgr_CloseProperties PROTO :HANDLE, :XWORD
    PifMgr_GetProperties PROTO :HANDLE, :LPCSTR, :LPVOID, :XWORD, :XWORD
    PifMgr_OpenProperties PROTO :LPWSTR, :LPWSTR, :XWORD, :XWORD
    PifMgr_SetProperties PROTO :HANDLE, :LPCSTR, :LPVOID, :XPTR, :XWORD
    ReadCabinetState PROTO :XPTR, :XWORD
    RealDriveType PROTO :XWORD, :XWORD
    RestartDialog PROTO :HWND, :LPCWSTR, :XWORD
    RestartDialogEx PROTO :HWND, :LPCWSTR, :XWORD, :XWORD
    SHAddFromPropSheetExtArray PROTO :XPTR, :XPTR, :LPARAM
    SHAlloc PROTO :SIZE_T
    SHChangeNotification_Lock PROTO :HANDLE, :XWORD, :XPTR, :XWORD
    SHChangeNotification_Unlock PROTO :HANDLE
    SHChangeNotifyDeregister PROTO :XWORD
    SHChangeNotifyRegister PROTO :HWND, :XWORD, :XWORD, :XWORD, :XWORD
    SHChangeNotifySuspendResume PROTO :XWORD, :XPTR, :XWORD, :XWORD
    SHCloneSpecialIDList PROTO :HWND, :XWORD, :XWORD
    SHCLSIDFromString PROTO :LPCWSTR, :XPTR
    SHCoCreateInstance PROTO :LPCWSTR, :XPTR, :XPTR, :HANDLE, :LPVOID
    SHCreateFileExtractIconW PROTO :LPCTSTR, :XWORD, :HANDLE, :LPVOID
    SHCreateProcessAsUserW PROTO :XPTR
    SHCreatePropSheetExtArray PROTO :HKEY, :LPCWSTR, :XWORD
    SHCreateQueryCancelAutoPlayMoniker PROTO :XPTR
    SHCreateShellFolderView PROTO :XPTR, :XPTR
    SHCreateShellFolderViewEx PROTO :XPTR, :XPTR
    SHCreateShellItem PROTO :XPTR, :XPTR, :XPTR, :XPTR
    SHCreateStdEnumFmtEtc PROTO :XWORD, :XPTR, :XPTR
    SHDefExtractIconA PROTO :LPCTSTR, :XWORD, :XWORD, :HICON, :HICON, :XWORD
    SHDefExtractIconW PROTO :LPCWSTR, :XWORD, :XWORD, :HICON, :HICON, :XWORD
    SHDestroyPropSheetExtArray PROTO :HANDLE
    SHDoDragDrop PROTO :HWND, :XPTR, :XPTR, :XWORD, :XPTR
    SheChangeDirA PROTO :LPSTR
    SheChangeDirExA PROTO :LPSTR
    SheChangeDirExW PROTO :LPWSTR
    SheChangeDirW PROTO :LPWSTR
    Shell_GetImageLists PROTO :XPTR, :XPTR
    Shell_MergeMenus PROTO :HMENU, :HMENU, :XWORD, :XWORD, :XWORD, :XWORD
    IFNDEF ShellMessageBoxA
        ShellMessageBoxA PROTO :HINSTANCE, :HWND, :LPCTSTR, :LPCTSTR, :XWORD, :XPTR
    ENDIF
    IFNDEF ShellMessageBoxW
        ShellMessageBoxW PROTO :HINSTANCE, :HWND, :LPCWSTR, :LPCWSTR, :XWORD, :XPTR
    ENDIF
    SHEnableServiceObject PROTO :XWORD, :XWORD
    SHEnumerateUnreadMailAccountsW PROTO :HKEY, :XWORD, :LPWSTR, :XWORD
    SHExtractIconsW PROTO :LPCWSTR, :XWORD, :XWORD, :XWORD, :HICON, :XWORD, :XWORD, :XWORD
    SHFind_InitMenuPopup PROTO :HMENU, :HWND, :XWORD, :XWORD
    SHFindFiles PROTO :XWORD, :XWORD
    IF (NTDDI_VERSION LE NTDDI_WINXPSP2)
        SHFlushClipboard PROTO
        SHFreeShared PROTO :HANDLE, :XWORD
        SHGetShellStyleHInstance PROTO
        SHLockShared PROTO :HANDLE, :XWORD
        SHUnlockShared PROTO :XPTR
    ENDIF
    SHFlushSFCache PROTO
    SHFree PROTO :XPTR
    SHGetAttributesFromDataObject PROTO :XPTR, :XWORD, :XPTR, :XPTR
    SHGetFolderPathAndSubDirA PROTO :HWND, :XWORD, :HANDLE, :XWORD, :LPCTSTR, :LPTSTR
    SHGetFolderPathAndSubDirW PROTO :HWND, :XWORD, :HANDLE, :XWORD, :LPCWSTR, :LPWSTR
    SHGetIconOverlayIndexA PROTO :LPCTSTR, :XWORD
    SHGetIconOverlayIndexW PROTO :LPCWSTR, :XWORD
    SHGetImageList PROTO :XWORD, :XWORD, :LPVOID
    SHGetRealIDL PROTO :XPTR, :XWORD, :XPTR
    SHGetSetFolderCustomSettings PROTO :XPTR, :LPCTSTR, :XWORD
    SHGetSetSettings PROTO :XPTR, :XWORD, :XWORD
    SHGetUnreadMailCountW PROTO :HKEY, :LPCWSTR, :XWORD, :XPTR, :LPCWSTR, :XWORD
    SHHandleUpdateImage PROTO :XWORD
    SHILCreateFromPath PROTO :LPCWSTR, :XPTR, :XPTR
    SHIsFileAvailableOffline PROTO :LPCWSTR, :LPDWORD
    SHLimitInputEdit PROTO :HWND, :XPTR
    SHLoadNonloadedIconOverlayIdentifiers PROTO
    SHMapPIDLToSystemImageListIndex PROTO :XPTR, :XWORD, :XPTR
    SHMultiFileProperties PROTO :XPTR, :XWORD
    SHObjectProperties PROTO :HWND, :XWORD, :LPCWSTR, :LPCWSTR
    SHOpenFolderAndSelectItems PROTO :XPTR, :XWORD, :XPTR, :XWORD
    SHOpenPropSheetW PROTO :LPWSTR, :XPTR, :XWORD, :XPTR, :XPTR, :XPTR, :LPWSTR
    SHParseDisplayName PROTO :LPCWSTR, :XPTR, :XPTR, :XWORD, :XPTR
    SHPropStgCreate PROTO :XPTR, :HANDLE, :XPTR, :XWORD, :XWORD, :XWORD, :XPTR, :XPTR
    SHPropStgReadMultiple PROTO :XPTR, :XWORD, :XWORD, :XPTR, :XPTR
    SHPropStgWriteMultiple PROTO :XPTR, :XWORD, :XWORD, :XPTR, :XPTR, :XWORD
    SHReplaceFromPropSheetExtArray PROTO:XPTR, :XWORD, :XPTR, :LPARAM
    SHRestricted PROTO :XWORD
    SHSetInstanceExplorer PROTO :XPTR
    SHSetLocalizedName PROTO :LPCWSTR, :LPCWSTR, :XWORD
    SHSetUnreadMailCountW PROTO :LPWSTR, :XWORD, :LPWSTR
    SHShellFolderView_Message PROTO :HWND, :XWORD, :LPARAM
    SHSimpleIDListFromPath PROTO :LPCWSTR
    SHStartNetConnectionDialogW PROTO :HWND, :LPCWSTR, :XWORD
    SHTestTokenMembership PROTO :HANDLE, :XWORD
    SHUpdateImageA PROTO :LPCTSTR, :XWORD, :XWORD, :XWORD
    SHUpdateImageW PROTO :LPCWSTR, :XWORD, :XWORD, :XWORD
    SHValidateUNC PROTO :HWND, :LPWSTR, :XWORD
    SignalFileOpen PROTO :XWORD
    Win32DeleteFile PROTO :LPCWSTR
    WriteCabinetState PROTO :XPTR

    IFDEF APP_UNICODE
        IF (NTDDI_VERSION LE NTDDI_VISTA)
            Control_FillCache_RunDLL EQU <Control_FillCache_RunDLLW>
        ENDIF
        Options_RunDLL EQU <Options_RunDLLW>
        PathIsSlow EQU <PathIsSlowW>
        SheChangeDir EQU <SheChangeDirW>
        SheChangeDirEx Equ <SheChangeDirExW>
        IFNDEF ShellMessageBox
            ShellMessageBox Equ <ShellMessageBoxW>
        ENDIF
        SHGetFolderPathAndSubDir EQU <SHGetFolderPathAndSubDirW>
        SHGetIconOverlayIndex EQU <SHGetIconOverlayIndexW>
        SHUpdateImage EQU <SHUpdateImageW>
    ELSE
        IF (NTDDI_VERSION LE NTDDI_VISTA)
            Control_FillCache_RunDLL EQU <Control_FillCache_RunDLLA>
        ENDIF
        Options_RunDLL EQU <Options_RunDLLA>
        PathIsSlow EQU <PathIsSlowA>
        SheChangeDir EQU <SheChangeDirA>
        SheChangeDirEx Equ <SheChangeDirExA>
        IFNDEF ShellMessageBox
            ShellMessageBox Equ <ShellMessageBoxA>
        ENDIF
        SHGetFolderPathAndSubDir EQU <SHGetFolderPathAndSubDirA>
        SHGetIconOverlayIndex EQU <SHGetIconOverlayIndexA>
        SHUpdateImage EQU <SHUpdateImageA>
    ENDIF
    SHGetUnreadMailCount EQU <SHGetUnreadMailCountW>
ENDIF

IF (NTDDI_VERSION GE NTDDI_VISTA)
    AssocCreateForClasses PROTO :XPTR, :XWORD, :XWORD, :LPVOID
    AssocGetDetailsOfPropKey PROTO :XPTR, :XWORD, :XPTR, :XPTR, :XPTR
    CIDLData_CreateFromIDArray PROTO :XWORD, :XWORD, :XPTR, :XPTR
    InitNetworkAddressControl PROTO
    SHAddDefaultPropertiesByExt PROTO :LPCWSTR, :XPTR
    SHAssocEnumHandlers PROTO :LPCWSTR, :XWORD, :XPTR
    SHBindToFolderIDListParent PROTO :XPTR, :XWORD, :XWORD, :LPVOID, :XPTR
    SHBindToFolderIDListParentEx PROTO :XPTR, :XWORD, :XPTR, :XWORD, :LPVOID, :XPTR
    SHBindToObject PROTO :XPTR, :XWORD, :XPTR, :XWORD, :LPVOID
    SHChangeNotifyRegisterThread PROTO :XWORD
    SHCreateAssociationRegistration PROTO :XWORD, :LPVOID
    SHCreateDataObject PROTO :XPTR, :XWORD, :XPTR, :XPTR, :XWORD, :XPTR
    SHCreateDefaultContextMenu PROTO :XPTR, :XWORD, :XPTR
    SHCreateDefaultExtractIcon PROTO :XWORD, :XPTR
    SHCreateDefaultPropertiesOp PROTO :XPTR, :XPTR
    SHCreateItemFromIDList PROTO :XWORD, :XWORD, :XPTR
    SHCreateItemFromParsingName PROTO :LPCWSTR, :XPTR, :XWORD, :XPTR
    SHCreateItemFromRelativeName PROTO :XPTR, :LPCWSTR, :XPTR, :XWORD, :XPTR
    SHCreateItemInKnownFolder PROTO :XWORD, :XWORD, :LPCWSTR, :XWORD, :LPVOID
    SHCreateItemWithParent PROTO :XWORD, :XPTR, :XWORD, :XWORD, :XPTR
    SHCreateShellItemArray PROTO :XWORD, :XPTR, :XWORD, :XPTR, :XPTR
    SHCreateShellItemArrayFromDataObject PROTO :XPTR, :XWORD, :LPVOID
    SHCreateShellItemArrayFromIDLists PROTO :XWORD, :XPTR, :XPTR
    SHCreateShellItemArrayFromShellItem PROTO :XPTR, :XWORD, :XPTR
    Shell_GetCachedImageIndexA PROTO :LPCSTR, :XWORD, :XWORD
    Shell_GetCachedImageIndexW PROTO :LPCWSTR, :XWORD, :XWORD
    SHEvaluateSystemCommandTemplate PROTO :LPCWSTR, :LPWSTR, :LPWSTR, :LPWSTR
    SHGetDriveMedia PROTO :LPCWSTR, :XPTR
    SHGetFolderPathEx PROTO :XWORD, :XWORD, :XWORD, :LPCSTR, :XWORD
    SHGetIDListFromObject PROTO :XPTR, :XPTR
    SHGetKnownFolderIDList PROTO :XWORD, :XWORD, :HANDLE, :XPTR
    SHGetKnownFolderPath PROTO :XWORD, :XWORD, :HANDLE, :XPTR
    SHGetLocalizedName PROTO :LPCWSTR, :LPWSTR, :XWORD, :XPTR
    SHGetNameFromIDList PROTO :XWORD, :XWORD, :LPWSTR
    SHGetPathFromIDListEx PROTO :XWORD, :LPWSTR, :XWORD, :XWORD
    SHGetPropertyStoreFromIDList PROTO :XPTR, :XWORD, :XWORD, :LPVOID
    SHGetPropertyStoreFromParsingName PROTO :LPCWSTR, :XPTR, :XWORD, :XWORD, :LPVOID
    SHGetStockIconInfo PROTO
    SHGetTemporaryPropertyForItem PROTO
    SHOpenWithDialog PROTO
    SHQueryUserNotificationState PROTO
    SHRemoveLocalizedName PROTO
    SHSetDefaultProperties PROTO
    SHSetFolderPathA PROTO
    SHSetFolderPathW PROTO
    SHSetKnownFolderPath PROTO
    SHSetTemporaryPropertyForItem PROTO
    WaitForExplorerRestartW PROTO

    IFDEF APP_UNICODE
        Shell_GetCachedImageIndex EQU <Shell_GetCachedImageIndexW>
        SHSetFolderPath EQU <SHSetFolderPathW>
    ELSE
        Shell_GetCachedImageIndex EQU <Shell_GetCachedImageIndexA>
        SHSetFolderPath EQU <SHSetFolderPathA>
    ENDIF
ELSE
    CheckEscapesA PROTO :LPSTR, :XWORD
ENDIF

IF (NTDDI_VERSION GE NTDDI_WIN7)
    GetCurrentProcessExplicitAppUserModelID PROTO :LPWSTR
    RunAsNewUser_RunDLLW PROTO :HWND, :HINSTANCE, :LPCWSTR, :XWORD
    SetCurrentProcessExplicitAppUserModelID PROTO :LPCWSTR
    SHAssocEnumHandlersForProtocolByApplication PROTO :LPCWSTR, :XWORD, :LPVOID
    Shell_NotifyIconGetRect PROTO :XPTR, :XPTR
    SHGetItemFromDataObject PROTO :XPTR, :XWORD, :XWORD, :XPTR
    SHGetItemFromObject PROTO :XPTR, :XWORD, :LPVOID
    SHGetKnownFolderItem PROTO :XPTR, :XWORD, :HANDLE, :XWORD, :LPVOID
    SHGetPropertyStoreForWindow PROTO :HWND, :XWORD, :LPVOID
    SHResolveLibrary PROTO :XPTR
    SHShowManageLibraryUI PROTO :XPTR, :HWND, :LPCWSTR, :LPCWSTR, :XWORD
    StgMakeUniqueName PROTO :XPTR, :LPCWSTR, :XWORD, :XWORD, :LPVOID
ENDIF

IF (NTDDI_VERSION GE NTDDI_WIN8)
    DllGetActivationFactory PROTO :XWORD, :XPTR
ENDIF

IF (NTDDI_VERSION GE NTDDI_WIN10)
    IsProcessAnExplorer PROTO
ENDIF

IFDEF APP_UNICODE
    DRAGINFO EQU <DRAGINFOW>
    SHFILEOPSTRUCT EQU <SHFILEOPSTRUCTW>
    SHNAMEMAPPING EQU <SHNAMEMAPPINGW>
    SHELLEXECUTEINFO EQU <SHELLEXECUTEINFOW>
    NOTIFYICONDATA EQU <NOTIFYICONDATAW>
    SHFILEINFO EQU <SHFILEINFOW>
    OPEN_PRINTER_PROPS_INFO EQU <OPEN_PRINTER_PROPS_INFOW>
    Control_RunDLL EQU <Control_RunDLLW>
    DoEnvironmentSubst EQU <DoEnvironmentSubstW>
    ExtractAssociatedIconEx EQU <ExtractAssociatedIconExW>
    ExtractAssociatedIcon EQU <ExtractAssociatedIconW>
    ExtractIcon EQU <ExtractIconW>
    FindExecutable EQU <FindExecutableW>
    InternalExtractIconList EQU <InternalExtractIconListW>
    RealShellExecute EQU <RealShellExecuteW>
    RealShellExecuteEx EQU <RealShellExecuteExW>
    SheGetDir EQU <SheGetDirW>
    ShellAbout EQU <ShellAboutW>
    ShellExecute EQU <ShellExecuteW>
ELSE
    DRAGINFO EQU <DRAGINFOA>
    SHFILEOPSTRUCT EQU <SHFILEOPSTRUCTA>
    SHNAMEMAPPING EQU <SHNAMEMAPPINGA>
    SHELLEXECUTEINFO EQU <SHELLEXECUTEINFOA>
    NOTIFYICONDATA EQU <NOTIFYICONDATAA>
    SHFILEINFO EQU <SHFILEINFOA>
    OPEN_PRINTER_PROPS_INFO EQU <OPEN_PRINTER_PROPS_INFOA>
    Control_RunDLL EQU <Control_RunDLLA>
    DoEnvironmentSubst EQU <DoEnvironmentSubstA>
    ExtractAssociatedIconEx EQU <ExtractAssociatedIconExA>
    ExtractAssociatedIcon EQU <ExtractAssociatedIconA>
    ExtractIcon EQU <ExtractIconA>
    FindExecutable EQU <FindExecutableA>
    InternalExtractIconList EQU <InternalExtractIconListA>
    RealShellExecute EQU <RealShellExecuteA>
    RealShellExecuteEx EQU <RealShellExecuteExA>
    SheGetDir EQU <SheGetDirA>
    ShellAbout EQU <ShellAboutA>
    ShellExecute EQU <ShellExecuteA>
ENDIF

;======================= Undocumented functions (unknown arguments) =======================;
;Activate_RunDLL PROTO
;CreateStorageItemFromPath_FullTrustCaller PROTO
;CreateStorageItemFromPath_FullTrustCaller_ForPackage PROTO
;CreateStorageItemFromPath_PartialTrustCaller PROTO
;CreateStorageItemFromShellItem_FullTrustCaller PROTO
;CreateStorageItemFromShellItem_FullTrustCaller_ForPackage PROTO
;CreateStorageItemFromShellItem_FullTrustCaller_ForPackage_WithProcessHandle PROTO
;CreateStorageItemFromShellItem_FullTrustCaller_UseImplicitFlagsAndPackage PROTO
;CStorageItem_GetValidatedStorageItemObject PROTO
;GetSystemPersistedStorageItemList PROTO
;IsDesktopExplorerProcess PROTO
;LaunchMSHelp_RunDLLW PROTO
;PathCleanupSpecWorker PROTO
;PathIsExeWorker PROTO
;PathQualify PROTO
;PrepareDiscForBurnRunDllW PROTO
;PrintersGetCommand_RunDLLA PROTO
;PrintersGetCommand_RunDLLW PROTO
;SHELL32_AddToBackIconTable PROTO
;SHELL32_AddToFrontIconTable PROTO
;SHELL32_AreAllItemsAvailable PROTO
;SHELL32_BindToFilePlaceholderHandler PROTO
;SHELL32_CallFileCopyHooks PROTO
;SHELL32_CanDisplayWin8CopyDialog PROTO
;SHELL32_CCommonPlacesFolder_CreateInstance PROTO
;SHELL32_CDBurn_CloseSession PROTO
;SHELL32_CDBurn_DriveSupportedForDataBurn PROTO
;SHELL32_CDBurn_Erase PROTO
;SHELL32_CDBurn_GetCDInfo PROTO
;SHELL32_CDBurn_GetLiveFSDiscInfo PROTO
;SHELL32_CDBurn_GetStagingPathOrNormalPath PROTO
;SHELL32_CDBurn_GetTaskInfo PROTO
;SHELL32_CDBurn_IsBlankDisc PROTO
;SHELL32_CDBurn_IsBlankDisc2 PROTO
;SHELL32_CDBurn_IsLiveFS PROTO
;SHELL32_CDBurn_OnDeviceChange PROTO
;SHELL32_CDBurn_OnEject PROTO
;SHELL32_CDBurn_OnMediaChange PROTO
;SHELL32_CDefFolderMenu_Create2 PROTO
;SHELL32_CDefFolderMenu_Create2Ex PROTO
;SHELL32_CDefFolderMenu_MergeMenu PROTO
;SHELL32_CDrivesContextMenu_Create PROTO
;SHELL32_CDrivesDropTarget_Create PROTO
;SHELL32_CFillPropertiesTask_CreateInstance PROTO
;SHELL32_CFSDropTarget_CreateInstance PROTO
;SHELL32_CFSFolderCallback_Create PROTO
;SHELL32_CLibraryDropTarget_CreateInstance PROTO
;SHELL32_CLocationContextMenu_Create PROTO
;SHELL32_CloseAutoplayPrompt PROTO
;SHELL32_CMountPoint_DoAutorun PROTO
;SHELL32_CMountPoint_DoAutorunPrompt PROTO
;SHELL32_CMountPoint_IsAutoRunDriveAndEnabledByPolicy PROTO
;SHELL32_CMountPoint_ProcessAutoRunFile PROTO
;SHELL32_CMountPoint_WantAutorunUI PROTO
;SHELL32_CMountPoint_WantAutorunUIGetReady PROTO
;SHELL32_CommandLineFromMsiDescriptor PROTO
;SHELL32_CopyExtrinsicPropertyStore PROTO
;SHELL32_CopyFilePlaceholderToNewFile PROTO
;SHELL32_CopySecondaryTiles PROTO
;SHELL32_CPL_CategoryIdArrayFromVariant PROTO
;SHELL32_CPL_IsLegacyCanonicalNameListedUnderKey PROTO
;SHELL32_CPL_ModifyWowDisplayName PROTO
;SHELL32_Create_IEnumUICommand PROTO
;SHELL32_CreateAlternateStreamFileName PROTO
;SHELL32_CreateConfirmationInterrupt PROTO
;SHELL32_CreateConflictInterrupt PROTO
;SHELL32_CreateDefaultOperationDataProvider PROTO
;SHELL32_CreateExtrinsicPropertyStore PROTO
;SHELL32_CreateFileFolderContextMenu PROTO
;SHELL32_CreateLinkInfoW PROTO
;SHELL32_CreatePlaceholderFile PROTO
;SHELL32_CreateQosRecorder PROTO
;SHELL32_CreateSharePointView PROTO
;SHELL32_CRecentDocsContextMenu_CreateInstance PROTO
;SHELL32_CSyncRootManager_CreateInstance PROTO
;SHELL32_CTransferConfirmation_CreateInstance PROTO
;SHELL32_DestroyLinkInfo PROTO
;SHELL32_EncryptDirectory PROTO
;SHELL32_EncryptedFileKeyInfo PROTO
;SHELL32_EnumCommonTasks PROTO
;SHELL32_FilePlaceholder_BindToPrimaryStream PROTO
;SHELL32_FilePlaceholder_CreateInstance PROTO
;SHELL32_FreeEncryptedFileKeyInfo PROTO
;SHELL32_GenerateAppID PROTO
;SHELL32_GetAppIDRoot PROTO
;SHELL32_GetCommandProviderForFolderType PROTO
;SHELL32_GetDiskCleanupPath PROTO
;SHELL32_GetDPIAdjustedLogicalSize PROTO
;SHELL32_GetFileNameFromBrowse PROTO
;SHELL32_GetIconOverlayManager PROTO
;SHELL32_GetLinkInfoData PROTO
;SHELL32_GetPlaceholderStatesFromFileAttributesAndReparsePointTag PROTO
;SHELL32_GetRatingBucket PROTO
;SHELL32_GetSkyDriveNetworkStates PROTO
;SHELL32_GetSqmableFileName PROTO
;SHELL32_GetThumbnailAdornerFromFactory PROTO
;SHELL32_GetThumbnailAdornerFromFactory2 PROTO
;SHELL32_HandleUnrecognizedFileSystem PROTO
;SHELL32_IconCache_AboutToExtractIcons PROTO
;SHELL32_IconCache_DoneExtractingIcons PROTO
;SHELL32_IconCache_ExpandEnvAndSearchPath PROTO
;SHELL32_IconCache_RememberRecentlyExtractedIconsW PROTO
;SHELL32_IconCacheCreate PROTO
;SHELL32_IconCacheDestroy PROTO
;SHELL32_IconCacheHandleAssociationChanged PROTO
;SHELL32_IconCacheRestore PROTO
;SHELL32_IconOverlayManagerInit PROTO
;SHELL32_IsGetKeyboardLayoutPresent PROTO
;SHELL32_IsSystemUpgradeInProgress PROTO
;SHELL32_IsValidLinkInfo PROTO
;SHELL32_LegacyEnumSpecialTasksByType PROTO
;SHELL32_LegacyEnumTasks PROTO
;SHELL32_LookupBackIconIndex PROTO
;SHELL32_LookupFrontIconIndex PROTO
;SHELL32_NormalizeRating PROTO
;SHELL32_NotifyLinkTrackingServiceOfMove PROTO
;SHELL32_PifMgr_CloseProperties PROTO
;SHELL32_PifMgr_GetProperties PROTO
;SHELL32_PifMgr_OpenProperties PROTO
;SHELL32_PifMgr_SetProperties PROTO
;SHELL32_Printers_CreateBindInfo PROTO
;SHELL32_Printjob_GetPidl PROTO
;SHELL32_PurgeSystemIcon PROTO
;SHELL32_RefreshOverlayImages PROTO
;SHELL32_ResolveLinkInfoW PROTO
;SHELL32_SendToMenu_InvokeTargetedCommand PROTO
;SHELL32_SendToMenu_VerifyTargetedCommand PROTO
;SHELL32_SetPlaceholderReparsePointAttribute PROTO
;SHELL32_SetPlaceholderReparsePointAttribute2 PROTO
;SHELL32_SHAddSparseIcon PROTO
;SHELL32_SHCreateByValueOperationInterrupt PROTO
;SHELL32_SHCreateDefaultContextMenu PROTO
;SHELL32_SHCreateLocalServer PROTO
;SHELL32_SHCreateShellFolderView PROTO
;SHELL32_SHDuplicateEncryptionInfoFile PROTO
;SHELL32_SHEncryptFile PROTO
;SHELL32_SHFormatDriveAsync PROTO
;SHELL32_SHGetThreadUndoManager PROTO
;SHELL32_SHGetUserNameW PROTO
;SHELL32_SHIsVirtualDevice PROTO
;SHELL32_SHLaunchPropSheet PROTO
;SHELL32_SHLogILFromFSIL PROTO
;SHELL32_SHOpenWithDialog PROTO
;SHELL32_ShowHideIconOnlyOnDesktop PROTO
;SHELL32_SHUICommandFromGUID PROTO
;SHELL32_SimpleRatingToFilterCondition PROTO
;SHELL32_StampIconForElevation PROTO
;SHELL32_SuspendUndo PROTO
;SHELL32_TryVirtualDiscImageDriveEject PROTO
;SHELL32_UpdateFilePlaceholderStates PROTO
;SHELL32_VerifySaferTrust PROTO
;SHCoCreateInstanceWorker PROTO
;SHCreateCategoryEnum PROTO
;SHCreateDirectoryExWWorker PROTO
;SHCreateDrvExtIcon PROTO
;SHCreateLocalServerRunDll PROTO
;SheConvertPathW PROTO
;SHGetDesktopFolderWorker PROTO
;SHGetFileInfoWWorker PROTO
;SHGetFolderLocationWorker PROTO
;SHGetFolderPathAndSubDirWWorker PROTO
;SHGetFolderPathAWorker PROTO
;SHGetFolderPathWWorker PROTO
;SHGetInstanceExplorerWorker PROTO
;SHGetKnownFolderPathWorker PROTO
;SHSetKnownFolderPathWorker PROTO
;SHGetSpecialFolderPathAWorker PROTO
;SHGetSpecialFolderPathWWorker PROTO
;StrCpyNA PROTO
;StrCpyNW PROTO
;StrNCpyA PROTO
;StrNCpyW PROTO
;UsersLibrariesFolderUI_CreateInstance PROTO

ENDIF ;SHELL32_INC
