; ====================================================;
;                                                     ;
;    shell32.inc for EC v2 SolAsm visual projects     ;
;                   (version 1.0.4)                   ;
;                                                     ;
;         Copyright © Ramon Sala - 2018-2020          ;
;                                                     ;
; ====================================================;

#ifndef SHELL32_INC
SHELL32_INC equ 1

ABM_NEW                                         equ     000000000H
ABM_REMOVE                                      equ     000000001H
ABM_QUERYPOS                                    equ     000000002H
ABM_SETPOS                                      equ     000000003H
ABM_GETSTATE                                    equ     000000004H
ABM_GETTASKBARPOS                               equ     000000005H
ABM_ACTIVATE                                    equ     000000006H
ABM_GETAUTOHIDEBAR                              equ     000000007H
ABM_SETAUTOHIDEBAR                              equ     000000008H
ABM_WINDOWPOSCHANGED                            equ     000000009H
ABM_SETSTATE                                    equ     00000000AH
ABM_GETAUTOHIDEBAREX                            equ     00000000BH
ABM_SETAUTOHIDEBAREX                            equ     00000000CH

ABN_STATECHANGE                                 equ     00000000H
ABN_POSCHANGED                                  equ     00000001H
ABN_FULLSCREENAPP                               equ     00000002H
ABN_WINDOWARRANGE                               equ     00000003H

ABS_AUTOHIDE                                    equ     00000001H
ABS_ALWAYSONTOP                                 equ     00000002H

ABE_LEFT                                        equ     0
ABE_TOP                                         equ     1
ABE_RIGHT                                       equ     2
ABE_BOTTOM                                      equ     3

FO_MOVE                                         equ     00001H
FO_COPY                                         equ     00002H
FO_DELETE                                       equ     00003H
FO_RENAME                                       equ     00004H

FOF_MULTIDESTFILES                              equ     00001H
FOF_CONFIRMMOUSE                                equ     00002H
FOF_SILENT                                      equ     00004H
FOF_RENAMEONCOLLISION                           equ     00008H
FOF_NOCONFIRMATION                              equ     00010H
FOF_WANTMAPPINGHANDLE                           equ     00020H

FOF_ALLOWUNDO                                   equ     00040H
FOF_FILESONLY                                   equ     00080H
FOF_SIMPLEPROGRESS                              equ     00100H
FOF_NOCONFIRMMKDIR                              equ     00200H
FOF_NOERRORUI                                   equ     00400H
FOF_NOCOPYSECURITYATTRIBS                       equ     00800H
FOF_NORECURSION                                 equ     01000H
FOF_NO_CONNECTED_ELEMENTS                       equ     02000H
FOF_WANTNUKEWARNING                             equ     04000H
FOF_NORECURSEREPARSE                            equ     08000H
FOF_NO_UI                                       equ     <FOF_SILENT or FOF_NOCONFIRMATION or FOF_NOERRORUI or FOF_NOCONFIRMMKDIR>

PO_DELETE                                       equ     00013H
PO_RENAME                                       equ     00014H
PO_PORTCHANGE                                   equ     00020H
PO_REN_PORT                                     equ     00034H

define FILEOP_FLAGS                             dw
define PRINTEROP_FLAGS                          dw

SE_ERR_FNF                                      equ     2
SE_ERR_PNF                                      equ     3
SE_ERR_ACCESSDENIED                             equ     5
SE_ERR_OOM                                      equ     8
SE_ERR_SHARE                                    equ     26
SE_ERR_ASSOCINCOMPLETE                          equ     27
SE_ERR_DDETIMEOUT                               equ     28
SE_ERR_DDEFAIL                                  equ     29
SE_ERR_DDEBUSY                                  equ     30
SE_ERR_NOASSOC                                  equ     31
SE_ERR_DLLNOTFOUND                              equ     32

SEE_MASK_DEFAULT                                equ     000000000H
SEE_MASK_CLASSNAME                              equ     000000001H
SEE_MASK_CLASSKEY                               equ     000000003H
SEE_MASK_IDLIST                                 equ     000000004H
SEE_MASK_INVOKEIDLIST                           equ     00000000CH
SEE_MASK_ICON                                   equ     000000010H
SEE_MASK_HOTKEY                                 equ     000000020H
SEE_MASK_NOCLOSEPROCESS                         equ     000000040H
SEE_MASK_CONNECTNETDRV                          equ     000000080H
SEE_MASK_NOASYNC                                equ     000000100H
SEE_MASK_FLAG_DDEWAIT                           equ     SEE_MASK_NOASYNC
SEE_MASK_DOENVSUBST                             equ     000000200H
SEE_MASK_FLAG_NO_UI                             equ     000000400H
SEE_MASK_UNICODE                                equ     000004000H
SEE_MASK_NO_CONSOLE                             equ     000008000H
SEE_MASK_ASYNCOK                                equ     000100000H
SEE_MASK_HMONITOR                               equ     000200000H
SEE_MASK_NOZONECHECKS                           equ     000800000H
SEE_MASK_NOQUERYCLASSSTORE                      equ     001000000H
SEE_MASK_WAITFORINPUTIDLE                       equ     002000000H
SEE_MASK_FLAG_LOG_USAGE                         equ     004000000H
SEE_MASK_FLAG_HINST_IS_SITE                     equ     008000000H

ASSOCCLASS_SHELL_KEY                            equ     0
ASSOCCLASS_PROGID_KEY                           equ     01H
ASSOCCLASS_PROGID_STR                           equ     02H
ASSOCCLASS_CLSID_KEY                            equ     03H
ASSOCCLASS_CLSID_STR                            equ     04H
ASSOCCLASS_APP_KEY                              equ     05H
ASSOCCLASS_APP_STR                              equ     06H
ASSOCCLASS_SYSTEM_STR                           equ     07H
ASSOCCLASS_FOLDER                               equ     08H
ASSOCCLASS_STAR                                 equ     09H
ASSOCCLASS_FIXED_PROGID_STR                     equ     0AH
ASSOCCLASS_PROTOCOL_STR                         equ     0BH

SHERB_NOCONFIRMATION                            equ     000000001H
SHERB_NOPROGRESSUI                              equ     000000002H
SHERB_NOSOUND                                   equ     000000004H

QUNS_NOT_PRESENT                                equ     1
QUNS_BUSY                                       equ     2
QUNS_RUNNING_D3D_FULL_SCREEN                    equ     3
QUNS_PRESENTATION_MODE                          equ     4
QUNS_ACCEPTS_NOTIFICATIONS                      equ     5
QUNS_QUIET_TIME                                 equ     6
QUNS_APP                                        equ     7

NIM_ADD                                         equ     000000000H
NIM_MODIFY                                      equ     000000001H
NIM_DELETE                                      equ     000000002H
NIM_SETFOCUS                                    equ     000000003h
NIM_SETVERSION                                  equ     000000004H

NIN_SELECT                                      equ     (WM_USER+0)
NINF_KEY                                        equ     01H
NIN_KEYSELECT                                   equ     <NIN_SELECT or NINF_KEY>
NIN_BALLOONSHOW                                 equ     (WM_USER+2)
NIN_BALLOONHIDE                                 equ     (WM_USER+3)
NIN_BALLOONTIMEOUT                              equ     (WM_USER+4)
NIN_BALLOONUSERCLICK                            equ     (WM_USER+5)
NIN_POPUPOPEN                                   equ     (WM_USER+6)
NIN_POPUPCLOSE                                  equ     (WM_USER+7)

NOTIFYICON_VERSION                              equ     3
NOTIFYICON_VERSION_4                            equ     4

NIF_MESSAGE                                     equ     000000001H
NIF_ICON                                        equ     000000002H
NIF_TIP                                         equ     000000004H
NIF_STATE                                       equ     000000008H
NIF_INFO                                        equ     000000010H
NIF_GUID                                        equ     000000020H
NIF_REALTIME                                    equ     000000040H
NIF_SHOWTIP                                     equ     000000080H

NIS_HIDDEN                                      equ     000000001H
NIS_SHAREDICON                                  equ     000000002H

NIIF_NONE                                       equ     000000000H
NIIF_INFO                                       equ     000000001H
NIIF_WARNING                                    equ     000000002H
NIIF_ERROR                                      equ     000000003H
NIIF_USER                                       equ     000000004H
NIIF_ICON_MASK                                  equ     00000000FH
NIIF_NOSOUND                                    equ     000000010H
NIIF_LARGE_ICON                                 equ     000000020H
NIIF_RESPECT_QUIET_TIME                         equ     000000080H

SHARD_PIDL                                      equ     000000001H
SHARD_PATHA                                     equ     000000002H
SHARD_PATHW                                     equ     000000003H
#ifdef APP_UNICODE
    SHARD_PATH                                  equ     SHARD_PATHW
#else
    SHARD_PATH                                  equ     SHARD_PATHA
#endif

SHDID_ROOT_REGITEM                              equ     1
SHDID_FS_FILE                                   equ     2
SHDID_FS_DIRECTORY                              equ     3
SHDID_FS_OTHER                                  equ     4
SHDID_COMPUTER_DRIVE35                          equ     5
SHDID_COMPUTER_DRIVE525                         equ     6
SHDID_COMPUTER_REMOVABLE                        equ     7
SHDID_COMPUTER_FIXED                            equ     8
SHDID_COMPUTER_NETDRIVE                         equ     9
SHDID_COMPUTER_CDROM                            equ     10
SHDID_COMPUTER_RAMDISK                          equ     11
SHDID_COMPUTER_OTHER                            equ     12
SHDID_NET_DOMAIN                                equ     13
SHDID_NET_SERVER                                equ     14
SHDID_NET_SHARE                                 equ     15
SHDID_NET_RESTOFNET                             equ     16
SHDID_NET_OTHER                                 equ     17
SHDID_COMPUTER_IMAGING                          equ     18
SHDID_COMPUTER_AUDIO                            equ     19
SHDID_COMPUTER_SHAREDDOCS                       equ     20
SHDID_MOBILE_DEVICE                             equ     21

SHGDFIL_FINDDATA                                equ     1
SHGDFIL_NETRESOURCE                             equ     2
SHGDFIL_DESCRIPTIONID                           equ     3

SHGFI_ICON                                      equ     0000000100H
SHGFI_DISPLAYNAME                               equ     0000000200H
SHGFI_TYPENAME                                  equ     0000000400H
SHGFI_ATTRIBUTES                                equ     0000000800H
SHGFI_ICONLOCATION                              equ     0000001000H
SHGFI_EXETYPE                                   equ     0000002000H
SHGFI_SYSICONINDEX                              equ     0000004000H
SHGFI_LINKOVERLAY                               equ     0000008000H
SHGFI_SELECTED                                  equ     0000010000H
SHGFI_ATTR_SPECIFIED                            equ     0000020000H
SHGFI_LARGEICON                                 equ     0000000000H
SHGFI_SMALLICON                                 equ     0000000001H
SHGFI_OPENICON                                  equ     0000000002H
SHGFI_SHELLICONSIZE                             equ     0000000004H
SHGFI_PIDL                                      equ     0000000008H
SHGFI_USEFILEATTRIBUTES                         equ     0000000010H
SHGFI_ADDOVERLAYS                               equ     0000000020H
SHGFI_OVERLAYINDEX                              equ     0000000040H

SHGSI_ICONLOCATION                              equ     0
SHGSI_ICON                                      equ     SHGFI_ICON
SHGSI_SYSICONINDEX                              equ     SHGFI_SYSICONINDEX
SHGSI_LINKOVERLAY                               equ     SHGFI_LINKOVERLAY
SHGSI_SELECTED                                  equ     SHGFI_SELECTED
SHGSI_LARGEICON                                 equ     SHGFI_LARGEICON
SHGSI_SMALLICON                                 equ     SHGFI_SMALLICON
SHGSI_SHELLICONSIZE                             equ     SHGFI_SHELLICONSIZE

SIID_DOCNOASSOC                                 equ     0
SIID_DOCASSOC                                   equ     1
SIID_APPLICATION                                equ     2
SIID_FOLDER                                     equ     3
SIID_FOLDEROPEN                                 equ     4
SIID_DRIVE525                                   equ     5
SIID_DRIVE35                                    equ     6
SIID_DRIVEREMOVE                                equ     7
SIID_DRIVEFIXED                                 equ     8
SIID_DRIVENET                                   equ     9
SIID_DRIVENETDISABLED                           equ     10
SIID_DRIVECD                                    equ     11
SIID_DRIVERAM                                   equ     12
SIID_WORLD                                      equ     13
SIID_SERVER                                     equ     15
SIID_PRINTER                                    equ     16
SIID_MYNETWORK                                  equ     17
SIID_FIND                                       equ     22
SIID_HELP                                       equ     23
SIID_SHARE                                      equ     28
SIID_LINK                                       equ     29
SIID_SLOWFILE                                   equ     30
SIID_RECYCLER                                   equ     31
SIID_RECYCLERFULL                               equ     32
SIID_MEDIACDAUDIO                               equ     40
SIID_LOCK                                       equ     47
SIID_AUTOLIST                                   equ     49
SIID_PRINTERNET                                 equ     50
SIID_SERVERSHARE                                equ     51
SIID_PRINTERFAX                                 equ     52
SIID_PRINTERFAXNET                              equ     53
SIID_PRINTERFILE                                equ     54
SIID_STACK                                      equ     55
SIID_MEDIASVCD                                  equ     56
SIID_STUFFEDFOLDER                              equ     57
SIID_DRIVEUNKNOWN                               equ     58
SIID_DRIVEDVD                                   equ     59
SIID_MEDIADVD                                   equ     60
SIID_MEDIADVDRAM                                equ     61
SIID_MEDIADVDRW                                 equ     62
SIID_MEDIADVDR                                  equ     63
SIID_MEDIADVDROM                                equ     64
SIID_MEDIACDAUDIOPLUS                           equ     65
SIID_MEDIACDRW                                  equ     66
SIID_MEDIACDR                                   equ     67
SIID_MEDIACDBURN                                equ     68
SIID_MEDIABLANKCD                               equ     69
SIID_MEDIACDROM                                 equ     70
SIID_AUDIOFILES                                 equ     71
SIID_IMAGEFILES                                 equ     72
SIID_VIDEOFILES                                 equ     73
SIID_MIXEDFILES                                 equ     74
SIID_FOLDERBACK                                 equ     75
SIID_FOLDERFRONT                                equ     76
SIID_SHIELD                                     equ     77
SIID_WARNING                                    equ     78
SIID_INFO                                       equ     79
SIID_ERROR                                      equ     80
SIID_KEY                                        equ     81
SIID_SOFTWARE                                   equ     82
SIID_RENAME                                     equ     83
SIID_DELETE                                     equ     84
SIID_MEDIAAUDIODVD                              equ     85
SIID_MEDIAMOVIEDVD                              equ     86
SIID_MEDIAENHANCEDCD                            equ     87
SIID_MEDIAENHANCEDDVD                           equ     88
SIID_MEDIAHDDVD                                 equ     89
SIID_MEDIABLURAY                                equ     90
SIID_MEDIAVCD                                   equ     91
SIID_MEDIADVDPLUSR                              equ     92
SIID_MEDIADVDPLUSRW                             equ     93
SIID_DESKTOPPC                                  equ     94
SIID_MOBILEPC                                   equ     95
SIID_USERS                                      equ     96
SIID_MEDIASMARTMEDIA                            equ     97
SIID_MEDIACOMPACTFLASH                          equ     98
SIID_DEVICECELLPHONE                            equ     99
SIID_DEVICECAMERA                               equ     100
SIID_DEVICEVIDEOCAMERA                          equ     101
SIID_DEVICEAUDIOPLAYER                          equ     102
SIID_NETWORKCONNECT                             equ     103
SIID_INTERNET                                   equ     104
SIID_ZIPFILE                                    equ     105
SIID_SETTINGS                                   equ     106
SIID_DRIVEHDDVD                                 equ     132
SIID_DRIVEBD                                    equ     133
SIID_MEDIAHDDVDROM                              equ     134
SIID_MEDIAHDDVDR                                equ     135
SIID_MEDIAHDDVDRAM                              equ     136
SIID_MEDIABDROM                                 equ     137
SIID_MEDIABDR                                   equ     138
SIID_MEDIABDRE                                  equ     139
SIID_CLUSTEREDDRIVE                             equ     140
SIID_MAX_ICONS                                  equ     175

SIID_INVALID                                    equ     (-1)

SHGNLI_PIDL                                     equ     0000000001H
SHGNLI_PREFIXNAME                               equ     0000000002H
SHGNLI_NOUNIQUE                                 equ     0000000004H
SHGNLI_NOLNK                                    equ     0000000008H
SHGNLI_NOLOCNAME                                equ     0000000010H
SHGNLI_USEURLEXT                                equ     0000000020H

PRINTACTION_OPEN                                equ     0
PRINTACTION_PROPERTIES                          equ     1
PRINTACTION_NETINSTALL                          equ     2
PRINTACTION_NETINSTALLLINK                      equ     3
PRINTACTION_TESTPAGE                            equ     4
PRINTACTION_OPENNETPRN                          equ     5
PRINTACTION_DOCUMENTDEFAULTS                    equ     6
PRINTACTION_SERVERPROPERTIES                    equ     7

OFFLINE_STATUS_LOCAL                            equ     00001H
OFFLINE_STATUS_REMOTE                           equ     00002H
OFFLINE_STATUS_INCOMPLETE                       equ     00004H

SHIL_LARGE                                      equ     0
SHIL_SMALL                                      equ     1
SHIL_EXTRALARGE                                 equ     2
SHIL_SYSSMALL                                   equ     3
#if NTDDI_VERSION >= NTDDI_VISTA
    SHIL_JUMBO                                  equ     4
    SHIL_LAST                                   equ     SHIL_JUMBO
#else
    SHIL_LAST                                   equ     SHIL_SYSSMALL
#endif

NCM_SETALLOWTYPE                                equ     (WM_USER+2)
NCM_GETALLOWTYPE                                equ     (WM_USER+3)
NCM_DISPLAYERRORTIP                             equ     (WM_USER+4)

SCNRT_ENABLE                                    equ     0
SCNRT_DISABLE                                   equ     1

GPFIDL_DEFAULT                                  equ     00000H
GPFIDL_ALTNAME                                  equ     00001H
GPFIDL_UNCPRINTER                               equ     00002H

SIGDN_NORMALDISPLAY                             equ     00000000H
SIGDN_PARENTRELATIVEPARSING                     equ     80018001H
SIGDN_DESKTOPABSOLUTEPARSING                    equ     80028000H
SIGDN_PARENTRELATIVEEDITING                     equ     80031001H
SIGDN_DESKTOPABSOLUTEEDITING                    equ     8004c000H
SIGDN_FILESYSPATH                               equ     80058000H
SIGDN_URL                                       equ     80068000H
SIGDN_PARENTRELATIVEFORADDRESSBAR               equ     8007C001H
SIGDN_PARENTRELATIVE                            equ     80080001H
SIGDN_PARENTRELATIVEFORUI                       equ     80094001H

GPS_DEFAULT                                     equ     0H
GPS_HANDLERPROPERTIESONLY                       equ     01H
GPS_READWRITE                                   equ     02H
GPS_TEMPORARY                                   equ     04H
GPS_FASTPROPERTIESONLY                          equ     08H
GPS_OPENSLOWITEM                                equ     010H
GPS_DELAYCREATION                               equ     020H
GPS_BESTEFFORT                                  equ     040H
GPS_NO_OPLOCK                                   equ     080H
GPS_PREFERQUERYPROPERTIES                       equ     0100H
GPS_MASK_VALID                                  equ     01FFH
GPS_EXTRINSICPROPERTIES                         equ     00000200H
GPS_EXTRINSICPROPERTIESONLY                     equ     00000400H

DOGIF_DEFAULT                                   equ     0000H
DOGIF_TRAVERSE_LINK                             equ     0001H
DOGIF_NO_HDROP                                  equ     0002H
DOGIF_NO_URL                                    equ     0004H
DOGIF_ONLY_IF_ONE                               equ     0008H

KF_FLAG_SIMPLE_IDLIST                           equ     00000100H
KF_FLAG_NOT_PARENT_RELATIVE                     equ     00000200H
KF_FLAG_DEFAULT_PATH                            equ     00000400H
KF_FLAG_INIT                                    equ     00000800H
KF_FLAG_NO_ALIAS                                equ     00001000H
KF_FLAG_DONT_UNEXPAND                           equ     00002000H
KF_FLAG_DONT_VERIFY                             equ     00004000H
KF_FLAG_CREATE                                  equ     00008000H
KF_FLAG_NO_APPCONTAINER_REDIRECTION             equ     00010000H
KF_FLAG_ALIAS_ONLY                              equ     80000000H

LMD_DEFAULT                                     equ     00000000H
LMD_ALLOWUNINDEXABLENETWORKLOCATIONS            equ     00000001H

;======================================== Functions =======================================;
#if COFF_FORMAT == 1
    from_lib shell32.lib
#else
    from_dll shell32.dll
#endif

#ifdef APP_WIN64
    import CheckEscapesW
    import CommandLineToArgvW
    import Control_RunDLLA
    import Control_RunDLLW
    #ifndef DllGetVersion
        import DllGetVersion
    #endif
    import DoEnvironmentSubstA
    import DoEnvironmentSubstW
    import DragAcceptFiles
    import DragFinish
    import DragQueryFileAorW
    import DragQueryPoint
    import DriveType
    import DuplicateIcon
    import ExtractAssociatedIconA
    import ExtractAssociatedIconExA
    import ExtractAssociatedIconExW
    import ExtractAssociatedIconW
    import ExtractIconA
    import ExtractIconW
    import FindExecutableA
    import FindExecutableW
    import FreeIconList
    import InternalExtractIconListA
    import InternalExtractIconListW
    import RealShellExecuteA
    import RealShellExecuteExA
    import RealShellExecuteExW
    import RealShellExecuteW
    import RegenerateUserEnvironment
    import SHAddToRecentDocs
    import SHAppBarMessage
    import SHChangeNotify
    import SheGetDirA
    import SheGetDirW
    import ShellAboutA
    import ShellAboutW
    import ShellExecuteA
    import ShellExecuteW
    import SheSetCurDrive
    import SHFormatDrive
    import SHFreeNameMappings
    import SHGetDesktopFolder
    import SHGetInstanceExplorer
    import SHGetMalloc
    import SHGetSpecialFolderLocation
    import SHLoadInProc

    #if NTDDI_VERSION > NTDDI_WIN95
        import DragQueryFileA
        import DragQueryFileW
        import ExtractIconExA
        import ExtractIconExW
        import OpenAs_RunDLLA
        import OpenAs_RunDLLW
        import SHBrowseForFolderA
        import SHBrowseForFolderW
        import Shell_NotifyIconA
        import Shell_NotifyIconW
        import ShellExecuteExA
        import ShellExecuteExW
        import SHFileOperationA
        import SHFileOperationW
        import SHGetDataFromIDListA
        import SHGetDataFromIDListW
        import SHGetFileInfoA
        import SHGetFileInfoW
        import SHGetPathFromIDListA
        import SHGetPathFromIDListW
        import SHHelpShortcuts_RunDLLA
        import SHHelpShortcuts_RunDLLW

        #ifdef APP_UNICODE
            define DragQueryFile DragQueryFileW
            define ExtractIconEx ExtractIconExW
            define OpenAs_RunDLL OpenAs_RunDLLW
            define SHBrowseForFolder SHBrowseForFolderW
            define Shell_NotifyIcon Shell_NotifyIconW
            define ShellAbout ShellAboutW
            define ShellExecuteEx ShellExecuteExW
            define SHFileOperation SHFileOperationW
            define SHGetDataFromIDList SHGetDataFromIDListW
            define SHGetFileInfo SHGetFileInfoW
            define SHGetPathFromIDList SHGetPathFromIDListW
            define SHHelpShortcuts_RunDLL SHHelpShortcuts_RunDLLW
        #else
            define DragQueryFile DragQueryFileA
            define ExtractIconEx ExtractIconExA
            define OpenAs_RunDLL OpenAs_RunDLLA
            define SHBrowseForFolder SHBrowseForFolderW
            define Shell_NotifyIcon Shell_NotifyIconA
            define ShellAbout ShellAboutA
            define ShellExecuteEx ShellExecuteExA
            define SHFileOperation SHFileOperationA
            define SHGetDataFromIDList SHGetDataFromIDListA
            define SHGetFileInfo SHGetFileInfoA
            define SHGetPathFromIDList SHGetPathFromIDListA
            define SHHelpShortcuts_RunDLL SHHelpShortcuts_RunDLLA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WIN98_ME
        #if NTDDI_VERSION <= NTDDI_WINXP
            import FindExeDlgProc
        #endif
        #if NTDDI_VERSION != NTDDI_WINNT4
            import DllCanUnloadNow
            import SHEmptyRecycleBinA
            import SHEmptyRecycleBinW
            import SHGetSettings
            import SHGetSpecialFolderPathA
            import SHGetSpecialFolderPathW
            import SHInvokePrinterCommandA
            import SHInvokePrinterCommandW
            import SHQueryRecycleBinA
            import SHQueryRecycleBinW

            #ifdef APP_UNICODE
                define SHEmptyRecycleBin SHEmptyRecycleBinW
                define SHGetSpecialFolderPath SHGetSpecialFolderPathW
                define SHInvokePrinterCommand SHInvokePrinterCommandW
                define SHQueryRecycleBin SHQueryRecycleBinW
            #else
                define SHEmptyRecycleBin SHEmptyRecycleBinA
                define SHGetSpecialFolderPath SHGetSpecialFolderPathA
                define SHInvokePrinterCommand SHInvokePrinterCommandA
                define SHQueryRecycleBin SHQueryRecycleBinA
            #endif
        #endif
        import ShellHookProc
        import SHGetDiskFreeSpaceA
        #ifndef APP_UNICODE
            define SHGetDiskFreeSpace SHGetDiskFreeSpaceA
        #endif
        import SHUpdateRecycleBinIcon
    #endif

    #if NTDDI_VERSION >= NTDDI_WINNT4
        import StrChrA
        import StrChrIA
        import StrChrIW
        import StrChrW
        import StrCmpNA
        import StrCmpNIA
        import StrCmpNIW
        import StrCmpNW
        import StrNCmpA
        import StrNCmpIA
        import StrNCmpIW
        import StrNCmpW
        import StrRChrA
        import StrRChrIA
        import StrRChrIW
        import StrRChrW
        import StrRStrA
        import StrRStrIA
        import StrRStrIW
        import StrRStrW
        import StrStrA
        import StrStrIA
        import StrStrIW
        import StrStrW
        import WOWShellExecute

        #ifdef APP_UNICODE
            define StrChr StrChrW
            define StrChrI StrChrIW
            define StrCmpN StrCmpNW
            define StrCmpNI StrCmpNIW
            define StrNCmp StrNCmpW
            define StrNCmpI StrNCmpIW
            define StrRChr StrRChrW
            define StrRChrI StrRChrIW
            define StrRStr StrRStrW
            define StrRStrI StrRStrIW
            define StrStr StrStrW
            define StrStrI StrStrIW
        #else
            define StrChr StrChrA
            define StrChrI StrChrIA
            define StrCmpN StrCmpNA
            define StrCmpNI StrCmpNIA
            define StrNCmp StrNCmpA
            define StrNCmpI StrNCmpIA
            define StrRChr StrRChrA
            define StrRChrI StrRChrIA
            define StrRStr StrRStrA
            define StrRStrI StrRStrIA
            define StrStr StrStrA
            define StrStrI StrStrIA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WIN2K
        #if NTDDI_VERSION <= NTDDI_WINXPSP2
            import CallCPLEntry16
            import SHMapIDListToImageListIndexAsync
        #endif
        #ifndef DllRegisterServer
            import DllRegisterServer
        #endif
        #ifndef DllUnregisterServer
            import DllUnregisterServer
        #endif
        import SHBindToParent
        import SHCreateDirectory
        import SHCreateDirectoryExA
        import SHCreateDirectoryExW
        import ShellExec_RunDLLA
        import ShellExec_RunDLLW
        import SHGetDiskFreeSpaceExA
        import SHGetDiskFreeSpaceExW
        import SHGetFolderLocation
        import SHGetFolderPathA
        import SHGetFolderPathW
        import SHGetNewLinkInfoA
        import SHGetNewLinkInfoW
        import SHPathPrepareForWriteA
        import SHPathPrepareForWriteW

        #ifdef APP_UNICODE
            define SHCreateDirectoryEx SHCreateDirectoryExW
            define ShellExec_RunDLL ShellExec_RunDLLW
            define SHGetDiskFreeSpaceEx SHGetDiskFreeSpaceExW
            define SHGetFolderPath SHGetFolderPathW
            define SHGetNewLinkInfo SHGetNewLinkInfoW
            define SHPathPrepareForWrite SHPathPrepareForWriteW
        #else
            define SHCreateDirectoryEx SHCreateDirectoryExA
            define ShellExec_RunDLL ShellExec_RunDLLA
            define SHGetDiskFreeSpaceEx SHGetDiskFreeSpaceExA
            define SHGetFolderPath SHGetFolderPathA
            define SHGetNewLinkInfo SHGetNewLinkInfoA
            define SHPathPrepareForWrite SHPathPrepareForWriteA
        #endif
    #else
        #if NTDDI_VERSION > NTDDI_WIN95
            import SHGetNewLinkInfo
        #endif
    #endif

    #if NTDDI_VERSION <= NTDDI_WINXP
        import ExtractIconResInfoA
        import ExtractIconResInfoW
        import ExtractVersionResource16W
        import ILCreateFromPathA
        import ILCreateFromPathW
        import SheFullPathA
        import SheFullPathW
        import SheGetCurDrive
        import SheGetDirExW
        import SheGetPathOffsetW
        import SheRemoveQuotesA
        import SheRemoveQuotesW
        import SheShortenPathA
        import SheShortenPathW
        #ifdef APP_UNICODE
            define ExtractIconResInfo ExtractIconResInfoW
            define ILCreateFromPath ILCreateFromPathW
            define SheFullPath SheFullPathW
            define SheRemoveQuotes SheRemoveQuotesW
            define SheShortenPath SheShortenPathW
        #else
            define ExtractIconResInfo ExtractIconResInfoA
            define ILCreateFromPath ILCreateFromPathA
            define SheFullPath SheFullPathA
            define SheRemoveQuotes SheRemoveQuotesA
            define SheShortenPath SheShortenPathA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WINXP
        import AppCompat_RunDLLW
        #if NTDDI_VERSION <= NTDDI_VISTA
            import CDefFolderMenu_Create
            import Control_FillCache_RunDLLA
            import Control_FillCache_RunDLLW
            import SHRunControlPanel
        #endif
        import CDefFolderMenu_Create2
        import Control_RunDLLAsUserW
        import DAD_AutoScroll
        import DAD_DragEnterEx
        import DAD_DragEnterEx2
        import DAD_DragLeave
        import DAD_DragMove
        import DAD_SetDragImage
        import DAD_ShowDragImage
        import GetFileNameFromBrowse
        import ILAppendID
        import ILClone
        import ILCloneFirst
        import ILCombine
        import ILFindChild
        import ILFindLastID
        import ILFree
        import ILGetNext
        import ILGetSize
        import ILIsEqual
        import ILIsParent
        #if NTDDI_VERSION == NTDDI_WINXP
            import ILLoadFromStream
            import PathProcessCommand
            import SHAllocShared
            import SHGetSetFolderCustomSettingsW
        #endif
        import ILLoadFromStreamEx
        import ILRemoveLastID
        import ILSaveToStream
        import IsLFNDrive
        import IsLFNDriveA
        import IsLFNDriveW
        import IsNetDrive
        import IsUserAnAdmin
        import OpenRegStream
        import Options_RunDLLA
        import Options_RunDLLW
        import PathCleanupSpec
        import PathGetShortPath
        import PathIsExe
        import PathIsSlowA
        import PathIsSlowW
        import PathMakeUniqueName
        import PathResolve
        import PathYetAnotherMakeUniqueName
        import PickIconDlg
        import PifMgr_CloseProperties
        import PifMgr_GetProperties
        import PifMgr_OpenProperties
        import PifMgr_SetProperties
        import ReadCabinetState
        import RealDriveType
        import RestartDialog
        import RestartDialogEx
        import SHAddFromPropSheetExtArray
        import SHAlloc
        import SHChangeNotification_Lock
        import SHChangeNotification_Unlock
        import SHChangeNotifyDeregister
        import SHChangeNotifyRegister
        import SHChangeNotifySuspendResume
        import SHCloneSpecialIDList
        import SHCLSIDFromString
        import SHCoCreateInstance
        import SHCreateFileExtractIconW
        import SHCreateProcessAsUserW
        import SHCreatePropSheetExtArray
        import SHCreateQueryCancelAutoPlayMoniker
        import SHCreateShellFolderView
        import SHCreateShellFolderViewEx
        import SHCreateShellItem
        import SHCreateStdEnumFmtEtc
        import SHDefExtractIconA
        import SHDefExtractIconW
        import SHDestroyPropSheetExtArray
        import SHDoDragDrop
        import SheChangeDirA
        import SheChangeDirExA
        import SheChangeDirExW
        import SheChangeDirW
        import Shell_GetCachedImageIndex
        import Shell_GetImageLists
        import Shell_MergeMenus
        import ShellMessageBoxA
        import ShellMessageBoxW
        import SHEnableServiceObject
        import SHEnumerateUnreadMailAccountsW
        import SHExtractIconsW
        import SHFind_InitMenuPopup
        import SHFindFiles
        #if NTDDI_VERSION <= NTDDI_WINXPSP2
            import SHFlushClipboard
            import SHFreeShared
            import SHGetShellStyleHInstance
            import SHLockShared
            import SHUnlockShared
        #endif
        import SHFlushSFCache
        import SHFree
        import SHGetAttributesFromDataObject
        import SHGetFolderPathAndSubDirA
        import SHGetFolderPathAndSubDirW
        import SHGetIconOverlayIndexA
        import SHGetIconOverlayIndexW
        import SHGetImageList
        import SHGetRealIDL
        import SHGetSetFolderCustomSettings
        import SHGetSetSettings
        import SHGetUnreadMailCountW
        import SHHandleUpdateImage
        import SHILCreateFromPath
        import SHIsFileAvailableOffline
        import SHLimitInputEdit
        import SHLoadNonloadedIconOverlayIdentifiers
        import SHMapPIDLToSystemImageListIndex
        import SHMultiFileProperties
        import SHObjectProperties
        import SHOpenFolderAndSelectItems
        import SHOpenPropSheetW
        import SHParseDisplayName
        import SHPropStgCreate
        import SHPropStgReadMultiple
        import SHPropStgWriteMultiple
        import SHReplaceFromPropSheetExtArray
        import SHRestricted
        import SHSetInstanceExplorer
        import SHSetLocalizedName
        import SHSetUnreadMailCountW
        import SHShellFolderView_Message
        import SHSimpleIDListFromPath
        import SHStartNetConnectionDialogW
        import SHTestTokenMembership
        import SHUpdateImageA
        import SHUpdateImageW
        import SHValidateUNC
        import SignalFileOpen
        import Win32DeleteFile
        import WriteCabinetState

        #ifdef APP_UNICODE
            #if NTDDI_VERSION <= NTDDI_VISTA
                define Control_FillCache_RunDLL Control_FillCache_RunDLLW
            #endif
            define Options_RunDLL Options_RunDLLW
            define PathIsSlow PathIsSlowW
            define SheChangeDir SheChangeDirW
            define SheChangeDirEx SheChangeDirExW
            define ShellMessageBox ShellMessageBoxW
            define SHGetFolderPathAndSubDir SHGetFolderPathAndSubDirW
            define SHGetIconOverlayIndex SHGetIconOverlayIndexW
            define SHUpdateImage SHUpdateImageW
        #else
            #if NTDDI_VERSION <= NTDDI_VISTA
                define Control_FillCache_RunDLL Control_FillCache_RunDLLA
            #endif
            define Options_RunDLL Options_RunDLLA
            define PathIsSlow PathIsSlowA
            define SheChangeDir SheChangeDirA
            define SheChangeDirEx SheChangeDirExA
            define ShellMessageBox ShellMessageBoxA
            define SHGetFolderPathAndSubDir SHGetFolderPathAndSubDirA
            define SHGetIconOverlayIndex SHGetIconOverlayIndexA
            define SHUpdateImage SHUpdateImageA
        #endif
        define SHGetUnreadMailCount SHGetUnreadMailCountW
    #endif

    #if NTDDI_VERSION >= NTDDI_VISTA
        import AssocCreateForClasses
        import AssocGetDetailsOfPropKey
        import CIDLData_CreateFromIDArray
        import InitNetworkAddressControl
        import SHAddDefaultPropertiesByExt
        import SHAssocEnumHandlers
        import SHBindToFolderIDListParent
        import SHBindToFolderIDListParentEx
        import SHBindToObject
        import SHChangeNotifyRegisterThread
        import SHCreateAssociationRegistration
        import SHCreateDataObject
        import SHCreateDefaultContextMenu
        import SHCreateDefaultExtractIcon
        import SHCreateDefaultPropertiesOp
        import SHCreateItemFromIDList
        import SHCreateItemFromParsingName
        import SHCreateItemFromRelativeName
        import SHCreateItemInKnownFolder
        import SHCreateItemWithParent
        import SHCreateShellItemArray
        import SHCreateShellItemArrayFromDataObject
        import SHCreateShellItemArrayFromIDLists
        import SHCreateShellItemArrayFromShellItem
        import Shell_GetCachedImageIndexA
        import Shell_GetCachedImageIndexW
        import SHEvaluateSystemCommandTemplate
        import SHGetDriveMedia
        import SHGetFolderPathEx
        import SHGetIDListFromObject
        import SHGetKnownFolderIDList
        import SHGetKnownFolderPath
        import SHGetLocalizedName
        import SHGetNameFromIDList
        import SHGetPathFromIDListEx
        import SHGetPropertyStoreFromIDList
        import SHGetPropertyStoreFromParsingName
        import SHGetStockIconInfo
        import SHGetTemporaryPropertyForItem
        import SHOpenWithDialog
        import SHQueryUserNotificationState
        import SHRemoveLocalizedName
        import SHSetDefaultProperties
        import SHSetFolderPathA
        import SHSetFolderPathW
        import SHSetKnownFolderPath
        import SHSetTemporaryPropertyForItem
        import WaitForExplorerRestartW

        #ifdef APP_UNICODE
            define Shell_GetCachedImageIndex Shell_GetCachedImageIndexW
            define SHSetFolderPath SHSetFolderPathW
        #else
            define Shell_GetCachedImageIndex Shell_GetCachedImageIndexA
            define SHSetFolderPath SHSetFolderPathA
        #endif
    #else
        import CheckEscapesA
    #endif

    #if NTDDI_VERSION >= NTDDI_WIN7
        import GetCurrentProcessExplicitAppUserModelID
        import RunAsNewUser_RunDLLW
        import SetCurrentProcessExplicitAppUserModelID
        import SHAssocEnumHandlersForProtocolByApplication
        import Shell_NotifyIconGetRect
        import SHGetItemFromDataObject
        import SHGetItemFromObject
        import SHGetKnownFolderItem
        import SHGetPropertyStoreForWindow
        import SHResolveLibrary
        import SHShowManageLibraryUI
        import StgMakeUniqueName
    #endif

    #if NTDDI_VERSION >= NTDDI_WIN8
        import DllGetActivationFactory
    #endif

    #if NTDDI_VERSION >= NTDDI_WIN10
        import IsProcessAnExplorer
    #endif

    #ifdef APP_UNICODE
        define Control_RunDLL Control_RunDLLW
        define DoEnvironmentSubst DoEnvironmentSubstW
        define ExtractAssociatedIconEx ExtractAssociatedIconExW
        define ExtractAssociatedIcon ExtractAssociatedIconW
        define ExtractIcon ExtractIconW
        define FindExecutable FindExecutableW
        define InternalExtractIconList InternalExtractIconListW
        define RealShellExecute RealShellExecuteW
        define RealShellExecuteEx RealShellExecuteExW
        define SheGetDir SheGetDirW
        define ShellExecute ShellExecuteW
    #else
        define Control_RunDLL Control_RunDLLA
        define DoEnvironmentSubst DoEnvironmentSubstA
        define ExtractAssociatedIconEx ExtractAssociatedIconExA
        define ExtractAssociatedIcon ExtractAssociatedIconA
        define ExtractIcon ExtractIconA
        define FindExecutable FindExecutableA
        define InternalExtractIconList InternalExtractIconListA
        define RealShellExecute RealShellExecuteA
        define RealShellExecuteEx RealShellExecuteExA
        define SheGetDir SheGetDirA
        define ShellExecute ShellExecuteA
    #endif
#else
    extern CheckEscapesW alias _CheckEscapesW@8
    extern CommandLineToArgvW alias _CommandLineToArgvW@8
    extern DoEnvironmentSubstA alias _DoEnvironmentSubstA@8
    extern DoEnvironmentSubstW alias _DoEnvironmentSubstW@8
    extern DragAcceptFiles alias _DragAcceptFiles@8
    extern DragFinish alias _DragFinish@4
    extern DragQueryFileAorW alias _DragQueryFileAorW@24
    extern DragQueryPoint alias _DragQueryPoint@8
    extern DriveType alias _DriveType@4
    extern DuplicateIcon alias _DuplicateIcon@8
    extern ExtractAssociatedIconA alias _ExtractAssociatedIconA@12
    extern ExtractAssociatedIconExA alias _ExtractAssociatedIconExA@16
    extern ExtractAssociatedIconExW alias _ExtractAssociatedIconExW@16
    extern ExtractAssociatedIconW alias _ExtractAssociatedIconW@12
    extern ExtractIconA alias _ExtractIconA@12
    extern ExtractIconW alias _ExtractIconW@12
    extern FindExecutableA alias _FindExecutableA@12
    extern FindExecutableW alias _FindExecutableW@12
    extern FreeIconList alias _FreeIconList@8
    extern InternalExtractIconListA alias _InternalExtractIconListA@12
    extern InternalExtractIconListW alias _InternalExtractIconListW@12
    extern RealShellExecuteA alias _RealShellExecuteA@40
    extern RealShellExecuteExA alias _RealShellExecuteExA@44
    extern RealShellExecuteExW alias _RealShellExecuteExW@44
    extern RealShellExecuteW alias _RealShellExecuteW@40
    extern RegenerateUserEnvironment alias _RegenerateUserEnvironment@8
    extern SHAddToRecentDocs alias _SHAddToRecentDocs@8
    extern SHAppBarMessage alias _SHAppBarMessage@8
    extern SHChangeNotify alias _SHChangeNotify@16
    extern ShellAboutA alias _ShellAboutA@16
    extern ShellAboutW alias _ShellAboutW@16
    extern ShellExecuteA alias _ShellExecuteA@24
    extern ShellExecuteW alias _ShellExecuteW@24
    extern SheSetCurDrive alias _SheSetCurDrive@4
    extern SHFormatDrive alias _SHFormatDrive@16
    extern SHFreeNameMappings alias _SHFreeNameMappings@4
    extern SHGetDesktopFolder alias _SHGetDesktopFolder@4
    extern SHGetInstanceExplorer alias _SHGetInstanceExplorer@4
    extern SHGetMalloc alias _SHGetMalloc@4
    extern SHGetSpecialFolderLocation alias _SHGetSpecialFolderLocation@12
    extern SHLoadInProc alias _SHLoadInProc@4

    #if NTDDI_VERSION > NTDDI_WIN95
        extern DragQueryFileA alias _DragQueryFileA@16
        extern DragQueryFileW alias _DragQueryFileW@16
        extern ExtractIconExA alias _ExtractIconExA@20
        extern ExtractIconExW alias _ExtractIconExW@20
        extern SHBrowseForFolderA alias _SHBrowseForFolderA@4
        extern SHBrowseForFolderW alias _SHBrowseForFolderW@4
        extern Shell_NotifyIconA alias _Shell_NotifyIconA@8
        extern Shell_NotifyIconW alias _Shell_NotifyIconW@8
        extern ShellExecuteExA alias _ShellExecuteExA@4
        extern ShellExecuteExW alias _ShellExecuteExW@4
        extern SHFileOperationA alias _SHFileOperationA@4
        extern SHFileOperationW alias _SHFileOperationW@4
        extern SHGetDataFromIDListA alias _SHGetDataFromIDListA@20
        extern SHGetDataFromIDListW alias _SHGetDataFromIDListW@20
        extern SHGetFileInfoA alias _SHGetFileInfoA@20
        extern SHGetFileInfoW alias _SHGetFileInfoW@20
        extern SHGetPathFromIDListA alias _SHGetPathFromIDListA@8
        extern SHGetPathFromIDListW alias _SHGetPathFromIDListW@8
        extern SHHelpShortcuts_RunDLLA alias _SHHelpShortcuts_RunDLLA@16
        extern SHHelpShortcuts_RunDLLW alias _SHHelpShortcuts_RunDLLW@16

        #ifdef APP_UNICODE
            define SHBrowseForFolder SHBrowseForFolderW
            define DragQueryFile DragQueryFileW
            define ExtractIconEx ExtractIconExW
            define Shell_NotifyIcon Shell_NotifyIconW
            define ShellExecuteEx ShellExecuteExW
            define SHFileOperation SHFileOperationW
            define SHGetDataFromIDList SHGetDataFromIDListW
            define SHGetFileInfo SHGetFileInfoW
            define SHGetPathFromIDList SHGetPathFromIDListW
            define SHHelpShortcuts_RunDLL SHHelpShortcuts_RunDLLW
        #else
            define SHBrowseForFolder SHBrowseForFolderA
            define DragQueryFile DragQueryFileA
            define ExtractIconEx ExtractIconExA
            define Shell_NotifyIcon Shell_NotifyIconA
            define ShellExecuteEx ShellExecuteExA
            define SHFileOperation SHFileOperationA
            define SHGetFileInfo SHGetFileInfoA
            define SHGetDataFromIDList SHGetDataFromIDListA
            define SHGetPathFromIDList SHGetPathFromIDListA
            define SHHelpShortcuts_RunDLL SHHelpShortcuts_RunDLLA
        #endif
    #endif


    #if NTDDI_VERSION >= NTDDI_WIN98_ME
        #if NTDDI_VERSION <= NTDDI_WINXP
            extern FindExeDlgProc alias _FindExeDlgProc@16
        #endif
        #if NTDDI_VERSION != NTDDI_WINNT4
            extern DllCanUnloadNow alias _DllCanUnloadNow@0
            extern SHEmptyRecycleBinA alias _SHEmptyRecycleBinA@12
            extern SHEmptyRecycleBinW alias _SHEmptyRecycleBinW@12
            extern SHGetSettings alias _SHGetSettings@8
            extern SHGetSpecialFolderPathA alias _SHGetSpecialFolderPathA@16
            extern SHGetSpecialFolderPathW alias _SHGetSpecialFolderPathW@16
            extern SHInvokePrinterCommandA alias _SHInvokePrinterCommandA@20
            extern SHInvokePrinterCommandW alias _SHInvokePrinterCommandW@20
            extern SHQueryRecycleBinA alias _SHQueryRecycleBinA@8
            extern SHQueryRecycleBinW alias _SHQueryRecycleBinW@8

            #ifdef APP_UNICODE
                define SHEmptyRecycleBin SHEmptyRecycleBinW
                define SHGetSpecialFolderPath SHGetSpecialFolderPathW
                define SHInvokePrinterCommand SHInvokePrinterCommandW
                define SHQueryRecycleBin SHQueryRecycleBinW
            #else
                define SHEmptyRecycleBin SHEmptyRecycleBinA
                define SHGetSpecialFolderPath SHGetSpecialFolderPathA
                define SHInvokePrinterCommand SHInvokePrinterCommandA
                define SHQueryRecycleBin SHQueryRecycleBinA
            #endif
        #endif
        extern ShellHookProc alias _ShellHookProc@12
        extern SHGetDiskFreeSpaceA alias _SHGetDiskFreeSpaceA@16
        #ifndef APP_UNICODE
            define SHGetDiskFreeSpace SHGetDiskFreeSpaceA
        #endif
        extern SHUpdateRecycleBinIcon alias _SHUpdateRecycleBinIcon@0
    #endif

    #if NTDDI_VERSION >= NTDDI_WINNT4
        extern StrChrA alias _StrChrA@8
        extern StrChrIA alias _StrChrIA@8
        extern StrChrIW alias _StrChrIW@8
        extern StrChrW alias _StrChrW@8
        extern StrCmpNA alias _StrCmpNA@12
        extern StrCmpNIA alias _StrCmpNIA@12
        extern StrCmpNIW alias _StrCmpNIW@12
        extern StrCmpNW alias _StrCmpNW@12
        extern StrNCmpA alias _StrNCmpA@12
        extern StrNCmpIA alias _StrNCmpIA@12
        extern StrNCmpIW alias _StrNCmpIW@12
        extern StrNCmpW alias _StrNCmpW@12
        extern StrRChrA alias _StrRChrA@12
        extern StrRChrIA alias _StrRChrIA@12
        extern StrRChrIW alias _StrRChrIW@12
        extern StrRChrW alias _StrRChrW@12
        extern StrRStrA alias _StrRStrA@12
        extern StrRStrIA alias _StrRStrIA@12
        extern StrRStrIW alias _StrRStrIW@12
        extern StrRStrW alias _StrRStrW@12
        extern StrStrA alias _StrStrA@8
        extern StrStrIA alias _StrStrIA@8
        extern StrStrIW alias _StrStrIW@8
        extern StrStrW alias _StrStrW@8
        extern WOWShellExecute alias _WOWShellExecute@28

        #ifdef APP_UNICODE
            define StrChr StrChrW
            define StrChrI StrChrIW
            define StrCmpN StrCmpNW
            define StrCmpNI StrCmpNIW
            define StrNCmp StrNCmpW
            define StrNCmpI StrNCmpIW
            define StrRChr StrRChrW
            define StrRChrI StrRChrIW
            define StrRStr StrRStrW
            define StrRStrI StrRStrIW
            define StrStr StrStrW
            define StrStrI StrStrIW
        #else
            define StrChr StrChrA
            define StrChrI StrChrIA
            define StrCmpN StrCmpNA
            define StrCmpNI StrCmpNIA
            define StrNCmp StrNCmpA
            define StrNCmpI StrNCmpIA
            define StrRChr StrRChrA
            define StrRChrI StrRChrIA
            define StrRStr StrRStrA
            define StrRStrI StrRStrIA
            define StrStr StrStrA
            define StrStrI StrStrIA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WIN2K
        #if NTDDI_VERSION <= NTDDI_WINXPSP2
            extern CallCPLEntry16 alias _CallCPLEntry16@24
            extern SHMapIDListToImageListIndexAsync alias _SHMapIDListToImageListIndexAsync@36
        #endif
        #ifndef DllRegisterServer
            extern DllRegisterServer alias _DllRegisterServer@0
        #endif
        #ifndef DllUnregisterServer
            extern DllUnregisterServer alias _DllUnregisterServer@0
        #endif
        extern SHBindToParent alias _SHBindToParent@16
        extern SHCreateDirectory alias _SHCreateDirectory@8
        extern SHCreateDirectoryExA alias _SHCreateDirectoryExA@12
        extern SHCreateDirectoryExW alias _SHCreateDirectoryExW@12
        extern ShellExec_RunDLLA alias _ShellExec_RunDLLA@4
        extern ShellExec_RunDLLW alias _ShellExec_RunDLLW@4
        extern SHGetDiskFreeSpaceExA alias _SHGetDiskFreeSpaceExA@16
        extern SHGetDiskFreeSpaceExW alias _SHGetDiskFreeSpaceExW@16
        extern SHGetFolderLocation alias _SHGetFolderLocation@20
        extern SHGetFolderPathA alias _SHGetFolderPathA@20
        extern SHGetFolderPathW alias _SHGetFolderPathW@20
        extern SHGetNewLinkInfoA alias _SHGetNewLinkInfoA@20
        extern SHGetNewLinkInfoW alias _SHGetNewLinkInfoW@20
        extern SHPathPrepareForWriteA alias _SHPathPrepareForWriteA@16
        extern SHPathPrepareForWriteW alias _SHPathPrepareForWriteW@16

        #ifdef APP_UNICODE
            define SHCreateDirectoryEx SHCreateDirectoryExW
            define ShellExec_RunDLL ShellExec_RunDLLW
            define SHGetDiskFreeSpaceEx SHGetDiskFreeSpaceExW
            define SHGetFolderPath SHGetFolderPathW
            define SHGetNewLinkInfo SHGetNewLinkInfoW
            define SHPathPrepareForWrite SHPathPrepareForWriteW
        #else
            define SHCreateDirectoryEx SHCreateDirectoryExA
            define ShellExec_RunDLL ShellExec_RunDLLA
            define SHGetDiskFreeSpaceEx SHGetDiskFreeSpaceExA
            define SHGetFolderPath SHGetFolderPathA
            define SHGetNewLinkInfo SHGetNewLinkInfoA
            define SHPathPrepareForWrite SHPathPrepareForWriteA
        #endif
    #else
        #if NTDDI_VERSION > NTDDI_WIN95
            extern HGetNewLinkInfo alias _SHGetNewLinkInfo@20
        #endif
    #endif

    #if NTDDI_VERSION <= NTDDI_WINXP
        extern ILCreateFromPathA alias _ILCreateFromPathA@4
        extern ILCreateFromPathW alias _ILCreateFromPathW@4
        #ifdef APP_UNICODE
            define ILCreateFromPath ILCreateFromPathW
        #else
            define ILCreateFromPath ILCreateFromPathA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WINXP
        extern AppCompat_RunDLLW alias _AppCompat_RunDLLW@16
        #if NTDDI_VERSION <= NTDDI_VISTA
            extern CDefFolderMenu_Create alias _CDefFolderMenu_Create@36
            extern Control_FillCache_RunDLLA alias _Control_FillCache_RunDLLA@16
            extern Control_FillCache_RunDLLW alias _Control_FillCache_RunDLLW@16
            extern SHRunControlPanel alias _SHRunControlPanel@8
        #endif
        extern CDefFolderMenu_Create2 alias _CDefFolderMenu_Create2@36
        extern Control_RunDLLAsUserW alias _Control_RunDLLAsUserW@16
        extern DAD_AutoScroll alias _DAD_AutoScroll@12
        extern DAD_DragEnterEx alias _DAD_DragEnterEx@8
        extern DAD_DragEnterEx2 alias _DAD_DragEnterEx2@12
        extern DAD_DragLeave alias _DAD_DragLeave@0
        extern DAD_DragMove alias _DAD_DragMove@4
        extern DAD_SetDragImage alias _DAD_SetDragImage@8
        extern DAD_ShowDragImage alias _DAD_ShowDragImage@4
        extern GetFileNameFromBrowse alias _GetFileNameFromBrowse@28
        extern ILAppendID alias _ILAppendID@12
        extern ILClone alias _ILClone@4
        extern ILCloneFirst alias _ILCloneFirst@4
        extern ILCombine alias _ILCombine@8
        extern ILFindChild alias _ILFindChild@8
        extern ILFindLastID alias _ILFindLastID@4
        extern ILFree alias _ILFree@4
        extern ILGetNext alias _ILGetNext@4
        extern ILGetSize alias _ILGetSize@4
        extern ILIsEqual alias _ILIsEqual@8
        extern ILIsParent alias _ILIsParent@12
        #if NTDDI_VERSION = NTDDI_WINXP
            extern ILLoadFromStream alias _ILLoadFromStream@8
            extern PathProcessCommand alias _PathProcessCommand@16
            extern SHAllocShared alias _SHAllocShared@12
            extern SHGetSetFolderCustomSettingsW alias _SHGetSetFolderCustomSettingsW@12
        #endif
        extern ILLoadFromStreamEx alias _ILLoadFromStreamEx@8
        extern ILRemoveLastID alias _ILRemoveLastID@4
        extern ILSaveToStream alias _ILSaveToStream@8
        extern IsLFNDrive alias _IsLFNDrive@4
        extern IsLFNDriveA alias _IsLFNDriveA@4
        extern IsLFNDriveW alias _IsLFNDriveW@4
        extern IsNetDrive alias _IsNetDrive@4
        extern IsUserAnAdmin alias _IsUserAnAdmin@0
        extern OpenRegStream alias _OpenRegStream@16
        extern Options_RunDLLA alias _Options_RunDLLA@16
        extern Options_RunDLLW alias _Options_RunDLLW@16
        extern PathCleanupSpec alias _PathCleanupSpec@8
        extern PathGetShortPath alias _PathGetShortPath@4
        extern PathIsExe alias _PathIsExe@4
        extern PathIsSlowA alias _PathIsSlowA@8
        extern PathIsSlowW alias _PathIsSlowW@8
        extern PathMakeUniqueName alias _PathMakeUniqueName@20
        extern PathResolve alias _PathResolve@12
        extern PathYetAnotherMakeUniqueName alias _PathYetAnotherMakeUniqueName@16
        extern PickIconDlg alias _PickIconDlg@16
        extern PifMgr_CloseProperties alias _PifMgr_CloseProperties@8
        extern PifMgr_GetProperties alias _PifMgr_GetProperties@20
        extern PifMgr_OpenProperties alias _PifMgr_OpenProperties@16
        extern PifMgr_SetProperties alias _PifMgr_SetProperties@20
        extern ReadCabinetState alias _ReadCabinetState@8
        extern RealDriveType alias _RealDriveType@8
        extern RestartDialog alias _RestartDialog@12
        extern RestartDialogEx alias _RestartDialogEx@16
        extern SHAddFromPropSheetExtArray alias _SHAddFromPropSheetExtArray@12
        extern SHAlloc alias _SHAlloc@4
        extern SHChangeNotification_Lock alias _SHChangeNotification_Lock@16
        extern SHChangeNotification_Unlock alias _SHChangeNotification_Unlock@4
        extern SHChangeNotifyDeregister alias _SHChangeNotifyDeregister@4
        extern SHChangeNotifyRegister alias _SHChangeNotifyRegister@20
        extern SHChangeNotifySuspendResume alias _SHChangeNotifySuspendResume@16
        extern SHCloneSpecialIDList alias _SHCloneSpecialIDList@12
        extern SHCLSIDFromString alias _SHCLSIDFromString@8
        extern SHCoCreateInstance alias _SHCoCreateInstance@20
        extern SHCreateFileExtractIconW alias _SHCreateFileExtractIconW@16
        extern SHCreateProcessAsUserW alias _SHCreateProcessAsUserW@4
        extern SHCreatePropSheetExtArray alias _SHCreatePropSheetExtArray@12
        extern SHCreateQueryCancelAutoPlayMoniker alias _SHCreateQueryCancelAutoPlayMoniker@4
        extern SHCreateShellFolderView alias _SHCreateShellFolderView@8
        extern SHCreateShellFolderViewEx alias _SHCreateShellFolderViewEx@8
        extern SHCreateShellItem alias _SHCreateShellItem@16
        extern SHCreateStdEnumFmtEtc alias _SHCreateStdEnumFmtEtc@12
        extern SHDefExtractIconA alias _SHDefExtractIconA@24
        extern SHDefExtractIconW alias _SHDefExtractIconW@24
        extern SHDestroyPropSheetExtArray alias _SHDestroyPropSheetExtArray@4
        extern SHDoDragDrop alias _SHDoDragDrop@20
        extern SheChangeDirA alias _SheChangeDirA@4
        extern SheChangeDirW alias _SheChangeDirW@4
        extern SheChangeDirExA alias _SheChangeDirExA@4
        extern SheChangeDirExW alias _SheChangeDirExW@4
        extern Shell_GetCachedImageIndex alias _Shell_GetCachedImageIndex@12
        extern Shell_GetImageLists alias _Shell_GetImageLists@8
        extern Shell_MergeMenus alias _Shell_MergeMenus@24
        extern ShellMessageBoxA alias _ShellMessageBoxA@20
        extern ShellMessageBoxW alias _ShellMessageBoxW@20
        extern SHEnableServiceObject alias _SHEnableServiceObject@8
        extern SHEnumerateUnreadMailAccountsW alias _SHEnumerateUnreadMailAccountsW@16
        extern SHExtractIconsW alias _SHExtractIconsW@32
        extern SHFind_InitMenuPopup alias _SHFind_InitMenuPopup@16
        extern SHFindFiles alias _SHFindFiles@8
        #if NTDDI_VERSION <= NTDDI_WINXPSP2
            extern SHFlushClipboard alias _SHFlushClipboard@0
            extern SHFreeShared alias _SHFreeShared@8
            extern SHGetShellStyleHInstance alias _SHGetShellStyleHInstance@0
            extern SHLockShared alias _SHLockShared@8
            extern SHUnlockShared alias _SHUnlockShared@4
        #endif
        extern SHFlushSFCache alias _SHFlushSFCache@0
        extern SHFree alias _SHFree@4
        extern SHGetAttributesFromDataObject alias _SHGetAttributesFromDataObject@16
        extern SHGetFolderPathAndSubDirA alias _SHGetFolderPathAndSubDirA@24
        extern SHGetFolderPathAndSubDirW alias _SHGetFolderPathAndSubDirW@24
        extern SHGetIconOverlayIndexA alias _SHGetIconOverlayIndexA@8
        extern SHGetIconOverlayIndexW alias _SHGetIconOverlayIndexW@8
        extern SHGetImageList alias _SHGetImageList@12
        extern SHGetRealIDL alias _SHGetRealIDL@12
        extern SHGetSetFolderCustomSettings alias _SHGetSetFolderCustomSettings@12
        extern SHGetSetSettings alias _SHGetSetSettings@12
        extern SHGetUnreadMailCountW alias _SHGetUnreadMailCountW@24
        extern SHHandleUpdateImage alias _SHHandleUpdateImage@4
        extern SHILCreateFromPath alias _SHILCreateFromPath@12
        extern SHIsFileAvailableOffline alias _SHIsFileAvailableOffline@8
        extern SHLimitInputEdit alias _SHLimitInputEdit@8
        extern SHLoadNonloadedIconOverlayIdentifiers alias _SHLoadNonloadedIconOverlayIdentifiers@0
        extern SHMapPIDLToSystemImageListIndex alias _SHMapPIDLToSystemImageListIndex@12
        extern SHMultiFileProperties alias _SHMultiFileProperties@8
        extern SHObjectProperties alias _SHObjectProperties@16
        extern SHOpenFolderAndSelectItems alias _SHOpenFolderAndSelectItems@16
        extern SHOpenPropSheetW alias _SHOpenPropSheetW@28
        extern SHParseDisplayName alias _SHParseDisplayName@20
        extern SHPropStgCreate alias _SHPropStgCreate@32
        extern SHPropStgReadMultiple alias _SHPropStgReadMultiple@20
        extern SHPropStgWriteMultiple alias _SHPropStgWriteMultiple@24
        extern SHReplaceFromPropSheetExtArray alias _SHReplaceFromPropSheetExtArray@16
        extern SHRestricted alias _SHRestricted@4
        extern SHSetInstanceExplorer alias _SHSetInstanceExplorer@4
        extern SHSetLocalizedName alias _SHSetLocalizedName@12
        extern SHSetUnreadMailCountW alias _SHSetUnreadMailCountW@12
        extern SHShellFolderView_Message alias _SHShellFolderView_Message@12
        extern SHSimpleIDListFromPath alias _SHSimpleIDListFromPath@4
        extern SHStartNetConnectionDialogW alias _SHStartNetConnectionDialogW@12
        extern SHTestTokenMembership alias _SHTestTokenMembership@8
        extern SHUpdateImageA alias _SHUpdateImageA@16
        extern SHUpdateImageW alias _SHUpdateImageW@16
        extern SHValidateUNC alias _SHValidateUNC@12
        extern SignalFileOpen alias _SignalFileOpen@4
        extern Win32DeleteFile alias _Win32DeleteFile@4
        extern WriteCabinetState alias _WriteCabinetState@4

        #ifdef APP_UNICODE
            #if NTDDI_VERSION <= NTDDI_VISTA
                define Control_FillCache_RunDLL Control_FillCache_RunDLLW
            #endif
            define Options_RunDLL Options_RunDLLW
            define PathIsSlow PathIsSlowW
            define SheChangeDir SheChangeDirW
            define SheChangeDirEx SheChangeDirExW
            define ShellMessageBox ShellMessageBoxW
            define SHGetFolderPathAndSubDir SHGetFolderPathAndSubDirW
            define SHGetIconOverlayIndex SHGetIconOverlayIndexW
            define SHUpdateImage SHUpdateImageW
        #else
            #if NTDDI_VERSION <= NTDDI_VISTA
                define Control_FillCache_RunDLL Control_FillCache_RunDLLA
            #endif
            define Options_RunDLL Options_RunDLLA
            define PathIsSlow PathIsSlowA
            define SheChangeDir SheChangeDirA
            define SheChangeDirEx SheChangeDirExA
            define ShellMessageBox ShellMessageBoxA
            define SHGetFolderPathAndSubDir SHGetFolderPathAndSubDirA
            define SHGetIconOverlayIndex SHGetIconOverlayIndexA
            define SHUpdateImage SHUpdateImageA
        #endif
        define SHGetUnreadMailCount SHGetUnreadMailCountW
    #endif

    #if NTDDI_VERSION >= NTDDI_VISTA
        extern AssocCreateForClasses alias _AssocCreateForClasses@12
        extern AssocGetDetailsOfPropKey alias _AssocGetDetailsOfPropKey@20
        extern CIDLData_CreateFromIDArray alias _CIDLData_CreateFromIDArray@16
        extern InitNetworkAddressControl alias _InitNetworkAddressControl@0
        extern SHAddDefaultPropertiesByExt alias _SHAddDefaultPropertiesByExt@8
        extern SHAssocEnumHandlers alias _SHAssocEnumHandlers@12
        extern SHBindToFolderIDListParent alias _SHBindToFolderIDListParent@20
        extern SHBindToFolderIDListParentEx alias _SHBindToFolderIDListParentEx@24
        extern SHBindToObject alias _SHBindToObject@20
        extern SHChangeNotifyRegisterThread alias _SHChangeNotifyRegisterThread@4
        extern SHCreateAssociationRegistration alias _SHCreateAssociationRegistration@8
        extern SHCreateDataObject alias _SHCreateDataObject@24
        extern SHCreateDefaultContextMenu alias _SHCreateDefaultContextMenu@12
        extern SHCreateDefaultExtractIcon alias _SHCreateDefaultExtractIcon@8
        extern SHCreateDefaultPropertiesOp alias _SHCreateDefaultPropertiesOp@8
        extern SHCreateItemFromIDList alias _SHCreateItemFromIDList@12
        extern SHCreateItemFromParsingName alias _SHCreateItemFromParsingName@16
        extern SHCreateItemFromRelativeName alias _SHCreateItemFromRelativeName@20
        extern SHCreateItemInKnownFolder alias _SHCreateItemInKnownFolder@20
        extern SHCreateItemWithParent alias _SHCreateItemWithParent@20
        extern SHCreateShellItemArray alias _SHCreateShellItemArray@20
        extern SHCreateShellItemArrayFromDataObject alias _SHCreateShellItemArrayFromDataObject@12
        extern SHCreateShellItemArrayFromIDLists alias _SHCreateShellItemArrayFromIDLists@12
        extern SHCreateShellItemArrayFromShellItem alias _SHCreateShellItemArrayFromShellItem@12
        extern Shell_GetCachedImageIndexA alias _Shell_GetCachedImageIndexA@12
        extern Shell_GetCachedImageIndexW alias _Shell_GetCachedImageIndexW@12
        extern SHEvaluateSystemCommandTemplate alias _SHEvaluateSystemCommandTemplate@16
        extern SHGetDriveMedia alias _SHGetDriveMedia@8
        extern SHGetFolderPathEx alias _SHGetFolderPathEx@20
        extern SHGetIDListFromObject alias _SHGetIDListFromObject@8
        extern SHGetKnownFolderIDList alias _SHGetKnownFolderIDList@16
        extern SHGetKnownFolderPath alias _SHGetKnownFolderPath@16
        extern SHGetLocalizedName alias _SHGetLocalizedName@16
        extern SHGetNameFromIDList alias _SHGetNameFromIDList@12
        extern SHGetPathFromIDListEx alias _SHGetPathFromIDListEx@16
        extern SHGetPropertyStoreFromIDList alias _SHGetPropertyStoreFromIDList@16
        extern SHGetPropertyStoreFromParsingName alias _SHGetPropertyStoreFromParsingName@20
        extern SHGetStockIconInfo alias _SHGetStockIconInfo@0
        extern SHGetTemporaryPropertyForItem alias _SHGetTemporaryPropertyForItem@0
        extern SHOpenWithDialog alias _SHOpenWithDialog@0
        extern SHQueryUserNotificationState alias _SHQueryUserNotificationState@0
        extern SHRemoveLocalizedName alias _SHRemoveLocalizedName@0
        extern SHSetDefaultProperties alias _SHSetDefaultProperties@0
        extern SHSetFolderPathA alias _SHSetFolderPathA@0
        extern SHSetFolderPathW alias _SHSetFolderPathW@0
        extern SHSetKnownFolderPath alias _SHSetKnownFolderPath@0
        extern SHSetTemporaryPropertyForItem alias _SHSetTemporaryPropertyForItem@0
        extern WaitForExplorerRestartW alias _WaitForExplorerRestartW@0

        #ifdef APP_UNICODE
            define Shell_GetCachedImageIndex Shell_GetCachedImageIndexW
            define SHSetFolderPath SHSetFolderPathW
        #else
            define Shell_GetCachedImageIndex Shell_GetCachedImageIndexA
            define SHSetFolderPath SHSetFolderPathA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WIN7
        extern GetCurrentProcessExplicitAppUserModelID alias _GetCurrentProcessExplicitAppUserModelID@4
        extern RunAsNewUser_RunDLLW alias _RunAsNewUser_RunDLLW@16
        extern SetCurrentProcessExplicitAppUserModelID alias _SetCurrentProcessExplicitAppUserModelID@4
        extern SHAssocEnumHandlersForProtocolByApplication alias _SHAssocEnumHandlersForProtocolByApplication@12
        extern Shell_NotifyIconGetRect alias _Shell_NotifyIconGetRect@8
        extern SHGetItemFromDataObject alias _SHGetItemFromDataObject@16
        extern SHGetItemFromObject alias _SHGetItemFromObject@12
        extern SHGetKnownFolderItem alias _SHGetKnownFolderItem@20
        extern SHGetPropertyStoreForWindow alias _SHGetPropertyStoreForWindow@12
        extern SHResolveLibrary alias _SHResolveLibrary@4
        extern SHShowManageLibraryUI alias _SHShowManageLibraryUI@20
        extern StgMakeUniqueName alias _StgMakeUniqueName@20
    #endif

    #if NTDDI_VERSION >= NTDDI_WIN8
        extern DllGetActivationFactory alias _DllGetActivationFactory@8
    #endif

    #if NTDDI_VERSION >= NTDDI_WIN10
        extern IsProcessAnExplorer alias _IsProcessAnExplorer@0
    #endif

    #ifdef APP_UNICODE
        define DoEnvironmentSubst DoEnvironmentSubstW
        define ExtractAssociatedIconEx ExtractAssociatedIconExW
        define ExtractAssociatedIcon ExtractAssociatedIconW
        define ExtractIcon ExtractIconW
        define FindExecutable FindExecutableW
        define InternalExtractIconList InternalExtractIconListW
        define RealShellExecute RealShellExecuteW
        define RealShellExecuteEx RealShellExecuteExW
        define ShellAbout ShellAboutW
        define ShellExecute ShellExecuteW
    #else
        define DoEnvironmentSubst DoEnvironmentSubstA
        define ExtractAssociatedIconEx ExtractAssociatedIconExA
        define ExtractAssociatedIcon ExtractAssociatedIconA
        define ExtractIcon ExtractIconA
        define FindExecutable FindExecutableA
        define InternalExtractIconList InternalExtractIconListA
        define RealShellExecute RealShellExecuteA
        define RealShellExecuteEx RealShellExecuteExA
        define ShellAbout ShellAboutA
        define ShellExecute ShellExecuteA
    #endif
#endif

;======================= Undocumented functions (unknown arguments) =======================;
;#ifdef APP_WIN64
;    import Activate_RunDLL
;    import CreateStorageItemFromPath_FullTrustCaller
;    import CreateStorageItemFromPath_FullTrustCaller_ForPackage
;    import CreateStorageItemFromPath_PartialTrustCaller
;    import CreateStorageItemFromShellItem_FullTrustCaller
;    import CreateStorageItemFromShellItem_FullTrustCaller_ForPackage
;    import CreateStorageItemFromShellItem_FullTrustCaller_ForPackage_WithProcessHandle
;    import CreateStorageItemFromShellItem_FullTrustCaller_UseImplicitFlagsAndPackage
;    import CStorageItem_GetValidatedStorageItemObject
;    import GetSystemPersistedStorageItemList
;    import IsDesktopExplorerProcess
;    import LaunchMSHelp_RunDLLW
;    import PathCleanupSpecWorker
;    import PathIsExeWorker
;    import PathQualify
;    import PrepareDiscForBurnRunDllW
;    import PrintersGetCommand_RunDLLA
;    import PrintersGetCommand_RunDLLW
;    import SHELL32_AddToBackIconTable
;    import SHELL32_AddToFrontIconTable
;    import SHELL32_AreAllItemsAvailable
;    import SHELL32_BindToFilePlaceholderHandler
;    import SHELL32_CallFileCopyHooks
;    import SHELL32_CanDisplayWin8CopyDialog
;    import SHELL32_CCommonPlacesFolder_CreateInstance
;    import SHELL32_CDBurn_CloseSession
;    import SHELL32_CDBurn_DriveSupportedForDataBurn
;    import SHELL32_CDBurn_Erase
;    import SHELL32_CDBurn_GetCDInfo
;    import SHELL32_CDBurn_GetLiveFSDiscInfo
;    import SHELL32_CDBurn_GetStagingPathOrNormalPath
;    import SHELL32_CDBurn_GetTaskInfo
;    import SHELL32_CDBurn_IsBlankDisc
;    import SHELL32_CDBurn_IsBlankDisc2
;    import SHELL32_CDBurn_IsLiveFS
;    import SHELL32_CDBurn_OnDeviceChange
;    import SHELL32_CDBurn_OnEject
;    import SHELL32_CDBurn_OnMediaChange
;    import SHELL32_CDefFolderMenu_Create2
;    import SHELL32_CDefFolderMenu_Create2Ex
;    import SHELL32_CDefFolderMenu_MergeMenu
;    import SHELL32_CDrivesContextMenu_Create
;    import SHELL32_CDrivesDropTarget_Create
;    import SHELL32_CFillPropertiesTask_CreateInstance
;    import SHELL32_CFSDropTarget_CreateInstance
;    import SHELL32_CFSFolderCallback_Create
;    import SHELL32_CLibraryDropTarget_CreateInstance
;    import SHELL32_CLocationContextMenu_Create
;    import SHELL32_CloseAutoplayPrompt
;    import SHELL32_CMountPoint_DoAutorun
;    import SHELL32_CMountPoint_DoAutorunPrompt
;    import SHELL32_CMountPoint_IsAutoRunDriveAndEnabledByPolicy
;    import SHELL32_CMountPoint_ProcessAutoRunFile
;    import SHELL32_CMountPoint_WantAutorunUI
;    import SHELL32_CMountPoint_WantAutorunUIGetReady
;    import SHELL32_CommandLineFromMsiDescriptor
;    import SHELL32_CopyExtrinsicPropertyStore
;    import SHELL32_CopyFilePlaceholderToNewFile
;    import SHELL32_CopySecondaryTiles
;    import SHELL32_CPL_CategoryIdArrayFromVariant
;    import SHELL32_CPL_IsLegacyCanonicalNameListedUnderKey
;    import SHELL32_CPL_ModifyWowDisplayName
;    import SHELL32_Create_IEnumUICommand
;    import SHELL32_CreateAlternateStreamFileName
;    import SHELL32_CreateConfirmationInterrupt
;    import SHELL32_CreateConflictInterrupt
;    import SHELL32_CreateDefaultOperationDataProvider
;    import SHELL32_CreateExtrinsicPropertyStore
;    import SHELL32_CreateFileFolderContextMenu
;    import SHELL32_CreateLinkInfoW
;    import SHELL32_CreatePlaceholderFile
;    import SHELL32_CreateQosRecorder
;    import SHELL32_CreateSharePointView
;    import SHELL32_CRecentDocsContextMenu_CreateInstance
;    import SHELL32_CSyncRootManager_CreateInstance
;    import SHELL32_CTransferConfirmation_CreateInstance
;    import SHELL32_DestroyLinkInfo
;    import SHELL32_EncryptDirectory
;    import SHELL32_EncryptedFileKeyInfo
;    import SHELL32_EnumCommonTasks
;    import SHELL32_FilePlaceholder_BindToPrimaryStream
;    import SHELL32_FilePlaceholder_CreateInstance
;    import SHELL32_FreeEncryptedFileKeyInfo
;    import SHELL32_GenerateAppID
;    import SHELL32_GetAppIDRoot
;    import SHELL32_GetCommandProviderForFolderType
;    import SHELL32_GetDiskCleanupPath
;    import SHELL32_GetDPIAdjustedLogicalSize
;    import SHELL32_GetFileNameFromBrowse
;    import SHELL32_GetIconOverlayManager
;    import SHELL32_GetLinkInfoData
;    import SHELL32_GetPlaceholderStatesFromFileAttributesAndReparsePointTag
;    import SHELL32_GetRatingBucket
;    import SHELL32_GetSkyDriveNetworkStates
;    import SHELL32_GetSqmableFileName
;    import SHELL32_GetThumbnailAdornerFromFactory
;    import SHELL32_GetThumbnailAdornerFromFactory2
;    import SHELL32_HandleUnrecognizedFileSystem
;    import SHELL32_IconCache_AboutToExtractIcons
;    import SHELL32_IconCache_DoneExtractingIcons
;    import SHELL32_IconCache_ExpandEnvAndSearchPath
;    import SHELL32_IconCache_RememberRecentlyExtractedIconsW
;    import SHELL32_IconCacheCreate
;    import SHELL32_IconCacheDestroy
;    import SHELL32_IconCacheHandleAssociationChanged
;    import SHELL32_IconCacheRestore
;    import SHELL32_IconOverlayManagerInit
;    import SHELL32_IsGetKeyboardLayoutPresent
;    import SHELL32_IsSystemUpgradeInProgress
;    import SHELL32_IsValidLinkInfo
;    import SHELL32_LegacyEnumSpecialTasksByType
;    import SHELL32_LegacyEnumTasks
;    import SHELL32_LookupBackIconIndex
;    import SHELL32_LookupFrontIconIndex
;    import SHELL32_NormalizeRating
;    import SHELL32_NotifyLinkTrackingServiceOfMove
;    import SHELL32_PifMgr_CloseProperties
;    import SHELL32_PifMgr_GetProperties
;    import SHELL32_PifMgr_OpenProperties
;    import SHELL32_PifMgr_SetProperties
;    import SHELL32_Printers_CreateBindInfo
;    import SHELL32_Printjob_GetPidl
;    import SHELL32_PurgeSystemIcon
;    import SHELL32_RefreshOverlayImages
;    import SHELL32_ResolveLinkInfoW
;    import SHELL32_SendToMenu_InvokeTargetedCommand
;    import SHELL32_SendToMenu_VerifyTargetedCommand
;    import SHELL32_SetPlaceholderReparsePointAttribute
;    import SHELL32_SetPlaceholderReparsePointAttribute2
;    import SHELL32_SHAddSparseIcon
;    import SHELL32_SHCreateByValueOperationInterrupt
;    import SHELL32_SHCreateDefaultContextMenu
;    import SHELL32_SHCreateLocalServer
;    import SHELL32_SHCreateShellFolderView
;    import SHELL32_SHDuplicateEncryptionInfoFile
;    import SHELL32_SHEncryptFile
;    import SHELL32_SHFormatDriveAsync
;    import SHELL32_SHGetThreadUndoManager
;    import SHELL32_SHGetUserNameW
;    import SHELL32_SHIsVirtualDevice
;    import SHELL32_SHLaunchPropSheet
;    import SHELL32_SHLogILFromFSIL
;    import SHELL32_SHOpenWithDialog
;    import SHELL32_ShowHideIconOnlyOnDesktop
;    import SHELL32_SHUICommandFromGUID
;    import SHELL32_SimpleRatingToFilterCondition
;    import SHELL32_StampIconForElevation
;    import SHELL32_SuspendUndo
;    import SHELL32_TryVirtualDiscImageDriveEject
;    import SHELL32_UpdateFilePlaceholderStates
;    import SHELL32_VerifySaferTrust
;    import SHCoCreateInstanceWorker
;    import SHCreateCategoryEnum
;    import SHCreateDirectoryExWWorker
;    import SHCreateDrvExtIcon
;    import SHCreateLocalServerRunDll
;    import SheConvertPathW
;    import SHGetDesktopFolderWorker
;    import SHGetFileInfoWWorker
;    import SHGetFolderLocationWorker
;    import SHGetFolderPathAndSubDirWWorker
;    import SHGetFolderPathAWorker
;    import SHGetFolderPathWWorker
;    import SHGetInstanceExplorerWorker
;    import SHGetKnownFolderPathWorker
;    import SHSetKnownFolderPathWorker
;    import SHGetSpecialFolderPathAWorker
;    import SHGetSpecialFolderPathWWorker
;    import StrCpyNA
;    import StrCpyNW
;    import StrNCpyA
;    import StrNCpyW
;    import UsersLibrariesFolderUI_CreateInstance
;#else
;    extern Activate_RunDLL alias _Activate_RunDLL@??
;    extern CreateStorageItemFromPath_FullTrustCaller alias _CreateStorageItemFromPath_FullTrustCaller@??
;    extern CreateStorageItemFromPath_FullTrustCaller_ForPackage alias _CreateStorageItemFromPath_FullTrustCaller_ForPackage@??
;    extern CreateStorageItemFromPath_PartialTrustCaller alias _CreateStorageItemFromPath_PartialTrustCaller@??
;    extern CreateStorageItemFromShellItem_FullTrustCaller alias _CreateStorageItemFromShellItem_FullTrustCaller@??
;    extern CreateStorageItemFromShellItem_FullTrustCaller_ForPackage alias _CreateStorageItemFromShellItem_FullTrustCaller_ForPackage@??
;    extern CreateStorageItemFromShellItem_FullTrustCaller_ForPackage_WithProcessHandle alias _CreateStorageItemFromShellItem_FullTrustCaller_ForPackage_WithProcessHandle@??
;    extern CreateStorageItemFromShellItem_FullTrustCaller_UseImplicitFlagsAndPackage alias _CreateStorageItemFromShellItem_FullTrustCaller_UseImplicitFlagsAndPackage@??
;    extern CStorageItem_GetValidatedStorageItemObject alias _CStorageItem_GetValidatedStorageItemObject@??
;    extern GetSystemPersistedStorageItemList alias _GetSystemPersistedStorageItemList@??
;    extern IsDesktopExplorerProcess alias _IsDesktopExplorerProcess@??
;    extern LaunchMSHelp_RunDLLW alias _LaunchMSHelp_RunDLLW@??
;    extern PathCleanupSpecWorker alias _PathCleanupSpecWorker@??
;    extern PathIsExeWorker alias _PathIsExeWorker@??
;    extern PathQualify alias _PathQualify@??
;    extern PrepareDiscForBurnRunDllW alias _PrepareDiscForBurnRunDllW@??
;    extern PrintersGetCommand_RunDLLA alias _PrintersGetCommand_RunDLLA@??
;    extern PrintersGetCommand_RunDLLW alias _PrintersGetCommand_RunDLLW@??
;    extern SHELL32_AddToBackIconTable alias _SHELL32_AddToBackIconTable@??
;    extern SHELL32_AddToFrontIconTable alias _SHELL32_AddToFrontIconTable@??
;    extern SHELL32_AreAllItemsAvailable alias _SHELL32_AreAllItemsAvailable@??
;    extern SHELL32_BindToFilePlaceholderHandler alias _SHELL32_BindToFilePlaceholderHandler@??
;    extern SHELL32_CallFileCopyHooks alias _SHELL32_CallFileCopyHooks@??
;    extern SHELL32_CanDisplayWin8CopyDialog alias _SHELL32_CanDisplayWin8CopyDialog@??
;    extern SHELL32_CCommonPlacesFolder_CreateInstance alias _SHELL32_CCommonPlacesFolder_CreateInstance@??
;    extern SHELL32_CDBurn_CloseSession alias _SHELL32_CDBurn_CloseSession@??
;    extern SHELL32_CDBurn_DriveSupportedForDataBurn alias _SHELL32_CDBurn_DriveSupportedForDataBurn@??
;    extern SHELL32_CDBurn_Erase alias _SHELL32_CDBurn_Erase@??
;    extern SHELL32_CDBurn_GetCDInfo alias _SHELL32_CDBurn_GetCDInfo@??
;    extern SHELL32_CDBurn_GetLiveFSDiscInfo alias _SHELL32_CDBurn_GetLiveFSDiscInfo@??
;    extern SHELL32_CDBurn_GetStagingPathOrNormalPath alias _SHELL32_CDBurn_GetStagingPathOrNormalPath@??
;    extern SHELL32_CDBurn_GetTaskInfo alias _SHELL32_CDBurn_GetTaskInfo@??
;    extern SHELL32_CDBurn_IsBlankDisc alias _SHELL32_CDBurn_IsBlankDisc@??
;    extern SHELL32_CDBurn_IsBlankDisc2 alias _SHELL32_CDBurn_IsBlankDisc2@??
;    extern SHELL32_CDBurn_IsLiveFS alias _SHELL32_CDBurn_IsLiveFS@??
;    extern SHELL32_CDBurn_OnDeviceChange alias _SHELL32_CDBurn_OnDeviceChange@??
;    extern SHELL32_CDBurn_OnEject alias _SHELL32_CDBurn_OnEject@??
;    extern SHELL32_CDBurn_OnMediaChange alias _SHELL32_CDBurn_OnMediaChange@??
;    extern SHELL32_CDefFolderMenu_Create2 alias _SHELL32_CDefFolderMenu_Create2@??
;    extern SHELL32_CDefFolderMenu_Create2Ex alias _SHELL32_CDefFolderMenu_Create2Ex@??
;    extern SHELL32_CDefFolderMenu_MergeMenu alias _SHELL32_CDefFolderMenu_MergeMenu@??
;    extern SHELL32_CDrivesContextMenu_Create alias _SHELL32_CDrivesContextMenu_Create@??
;    extern SHELL32_CDrivesDropTarget_Create alias _SHELL32_CDrivesDropTarget_Create@??
;    extern SHELL32_CFillPropertiesTask_CreateInstance alias _SHELL32_CFillPropertiesTask_CreateInstance@??
;    extern SHELL32_CFSDropTarget_CreateInstance alias _SHELL32_CFSDropTarget_CreateInstance@??
;    extern SHELL32_CFSFolderCallback_Create alias _SHELL32_CFSFolderCallback_Create@??
;    extern SHELL32_CLibraryDropTarget_CreateInstance alias _SHELL32_CLibraryDropTarget_CreateInstance@??
;    extern SHELL32_CLocationContextMenu_Create alias _SHELL32_CLocationContextMenu_Create@??
;    extern SHELL32_CloseAutoplayPrompt alias _SHELL32_CloseAutoplayPrompt@??
;    extern SHELL32_CMountPoint_DoAutorun alias _SHELL32_CMountPoint_DoAutorun@??
;    extern SHELL32_CMountPoint_DoAutorunPrompt alias _SHELL32_CMountPoint_DoAutorunPrompt@??
;    extern SHELL32_CMountPoint_IsAutoRunDriveAndEnabledByPolicy alias _SHELL32_CMountPoint_IsAutoRunDriveAndEnabledByPolicy@??
;    extern SHELL32_CMountPoint_ProcessAutoRunFile alias _SHELL32_CMountPoint_ProcessAutoRunFile@??
;    extern SHELL32_CMountPoint_WantAutorunUI alias _SHELL32_CMountPoint_WantAutorunUI@??
;    extern SHELL32_CMountPoint_WantAutorunUIGetReady alias _SHELL32_CMountPoint_WantAutorunUIGetReady@??
;    extern SHELL32_CommandLineFromMsiDescriptor alias _SHELL32_CommandLineFromMsiDescriptor@??
;    extern SHELL32_CopyExtrinsicPropertyStore alias _SHELL32_CopyExtrinsicPropertyStore@??
;    extern SHELL32_CopyFilePlaceholderToNewFile alias _SHELL32_CopyFilePlaceholderToNewFile@??
;    extern SHELL32_CopySecondaryTiles alias _SHELL32_CopySecondaryTiles@??
;    extern SHELL32_CPL_CategoryIdArrayFromVariant alias _SHELL32_CPL_CategoryIdArrayFromVariant@??
;    extern SHELL32_CPL_IsLegacyCanonicalNameListedUnderKey alias _SHELL32_CPL_IsLegacyCanonicalNameListedUnderKey@??
;    extern SHELL32_CPL_ModifyWowDisplayName alias _SHELL32_CPL_ModifyWowDisplayName@??
;    extern SHELL32_Create_IEnumUICommand alias _SHELL32_Create_IEnumUICommand@??
;    extern SHELL32_CreateAlternateStreamFileName alias _SHELL32_CreateAlternateStreamFileName@??
;    extern SHELL32_CreateConfirmationInterrupt alias _SHELL32_CreateConfirmationInterrupt@??
;    extern SHELL32_CreateConflictInterrupt alias _SHELL32_CreateConflictInterrupt@??
;    extern SHELL32_CreateDefaultOperationDataProvider alias _SHELL32_CreateDefaultOperationDataProvider@??
;    extern SHELL32_CreateExtrinsicPropertyStore alias _SHELL32_CreateExtrinsicPropertyStore@??
;    extern SHELL32_CreateFileFolderContextMenu alias _SHELL32_CreateFileFolderContextMenu@??
;    extern SHELL32_CreateLinkInfoW alias _SHELL32_CreateLinkInfoW@??
;    extern SHELL32_CreatePlaceholderFile alias _SHELL32_CreatePlaceholderFile@??
;    extern SHELL32_CreateQosRecorder alias _SHELL32_CreateQosRecorder@??
;    extern SHELL32_CreateSharePointView alias _SHELL32_CreateSharePointView@??
;    extern SHELL32_CRecentDocsContextMenu_CreateInstance alias _SHELL32_CRecentDocsContextMenu_CreateInstance@??
;    extern SHELL32_CSyncRootManager_CreateInstance alias _SHELL32_CSyncRootManager_CreateInstance@??
;    extern SHELL32_CTransferConfirmation_CreateInstance alias _SHELL32_CTransferConfirmation_CreateInstance@??
;    extern SHELL32_DestroyLinkInfo alias _SHELL32_DestroyLinkInfo@??
;    extern SHELL32_EncryptDirectory alias _SHELL32_EncryptDirectory@??
;    extern SHELL32_EncryptedFileKeyInfo alias _SHELL32_EncryptedFileKeyInfo@??
;    extern SHELL32_EnumCommonTasks alias _SHELL32_EnumCommonTasks@??
;    extern SHELL32_FilePlaceholder_BindToPrimaryStream alias _SHELL32_FilePlaceholder_BindToPrimaryStream@??
;    extern SHELL32_FilePlaceholder_CreateInstance alias _SHELL32_FilePlaceholder_CreateInstance@??
;    extern SHELL32_FreeEncryptedFileKeyInfo alias _SHELL32_FreeEncryptedFileKeyInfo@??
;    extern SHELL32_GenerateAppID alias _SHELL32_GenerateAppID@??
;    extern SHELL32_GetAppIDRoot alias _SHELL32_GetAppIDRoot@??
;    extern SHELL32_GetCommandProviderForFolderType alias _SHELL32_GetCommandProviderForFolderType@??
;    extern SHELL32_GetDiskCleanupPath alias _SHELL32_GetDiskCleanupPath@??
;    extern SHELL32_GetDPIAdjustedLogicalSize alias _SHELL32_GetDPIAdjustedLogicalSize@??
;    extern SHELL32_GetFileNameFromBrowse alias _SHELL32_GetFileNameFromBrowse@??
;    extern SHELL32_GetIconOverlayManager alias _SHELL32_GetIconOverlayManager@??
;    extern SHELL32_GetLinkInfoData alias _SHELL32_GetLinkInfoData@??
;    extern SHELL32_GetPlaceholderStatesFromFileAttributesAndReparsePointTag alias _SHELL32_GetPlaceholderStatesFromFileAttributesAndReparsePointTag@??
;    extern SHELL32_GetRatingBucket alias _SHELL32_GetRatingBucket@??
;    extern SHELL32_GetSkyDriveNetworkStates alias _SHELL32_GetSkyDriveNetworkStates@??
;    extern SHELL32_GetSqmableFileName alias _SHELL32_GetSqmableFileName@??
;    extern SHELL32_GetThumbnailAdornerFromFactory alias _SHELL32_GetThumbnailAdornerFromFactory@??
;    extern SHELL32_GetThumbnailAdornerFromFactory2 alias _SHELL32_GetThumbnailAdornerFromFactory2@??
;    extern SHELL32_HandleUnrecognizedFileSystem alias _SHELL32_HandleUnrecognizedFileSystem@??
;    extern SHELL32_IconCache_AboutToExtractIcons alias _SHELL32_IconCache_AboutToExtractIcons@??
;    extern SHELL32_IconCache_DoneExtractingIcons alias _SHELL32_IconCache_DoneExtractingIcons@??
;    extern SHELL32_IconCache_ExpandEnvAndSearchPath alias _SHELL32_IconCache_ExpandEnvAndSearchPath@??
;    extern SHELL32_IconCache_RememberRecentlyExtractedIconsW alias _SHELL32_IconCache_RememberRecentlyExtractedIconsW@??
;    extern SHELL32_IconCacheCreate alias _SHELL32_IconCacheCreate@??
;    extern SHELL32_IconCacheDestroy alias _SHELL32_IconCacheDestroy@??
;    extern SHELL32_IconCacheHandleAssociationChanged alias _SHELL32_IconCacheHandleAssociationChanged@??
;    extern SHELL32_IconCacheRestore alias _SHELL32_IconCacheRestore@??
;    extern SHELL32_IconOverlayManagerInit alias _SHELL32_IconOverlayManagerInit@??
;    extern SHELL32_IsGetKeyboardLayoutPresent alias _SHELL32_IsGetKeyboardLayoutPresent@??
;    extern SHELL32_IsSystemUpgradeInProgress alias _SHELL32_IsSystemUpgradeInProgress@??
;    extern SHELL32_IsValidLinkInfo alias _SHELL32_IsValidLinkInfo@??
;    extern SHELL32_LegacyEnumSpecialTasksByType alias _SHELL32_LegacyEnumSpecialTasksByType@??
;    extern SHELL32_LegacyEnumTasks alias _SHELL32_LegacyEnumTasks@??
;    extern SHELL32_LookupBackIconIndex alias _SHELL32_LookupBackIconIndex@??
;    extern SHELL32_LookupFrontIconIndex alias _SHELL32_LookupFrontIconIndex@??
;    extern SHELL32_NormalizeRating alias _SHELL32_NormalizeRating@??
;    extern SHELL32_NotifyLinkTrackingServiceOfMove alias _SHELL32_NotifyLinkTrackingServiceOfMove@??
;    extern SHELL32_PifMgr_CloseProperties alias _SHELL32_PifMgr_CloseProperties@??
;    extern SHELL32_PifMgr_GetProperties alias _SHELL32_PifMgr_GetProperties@??
;    extern SHELL32_PifMgr_OpenProperties alias _SHELL32_PifMgr_OpenProperties@??
;    extern SHELL32_PifMgr_SetProperties alias _SHELL32_PifMgr_SetProperties@??
;    extern SHELL32_Printers_CreateBindInfo alias _SHELL32_Printers_CreateBindInfo@??
;    extern SHELL32_Printjob_GetPidl alias _SHELL32_Printjob_GetPidl@??
;    extern SHELL32_PurgeSystemIcon alias _SHELL32_PurgeSystemIcon@??
;    extern SHELL32_RefreshOverlayImages alias _SHELL32_RefreshOverlayImages@??
;    extern SHELL32_ResolveLinkInfoW alias _SHELL32_ResolveLinkInfoW@??
;    extern SHELL32_SendToMenu_InvokeTargetedCommand alias _SHELL32_SendToMenu_InvokeTargetedCommand@??
;    extern SHELL32_SendToMenu_VerifyTargetedCommand alias _SHELL32_SendToMenu_VerifyTargetedCommand@??
;    extern SHELL32_SetPlaceholderReparsePointAttribute alias _SHELL32_SetPlaceholderReparsePointAttribute@??
;    extern SHELL32_SetPlaceholderReparsePointAttribute2 alias _SHELL32_SetPlaceholderReparsePointAttribute2@??
;    extern SHELL32_SHAddSparseIcon alias _SHELL32_SHAddSparseIcon@??
;    extern SHELL32_SHCreateByValueOperationInterrupt alias _SHELL32_SHCreateByValueOperationInterrupt@??
;    extern SHELL32_SHCreateDefaultContextMenu alias _SHELL32_SHCreateDefaultContextMenu@??
;    extern SHELL32_SHCreateLocalServer alias _SHELL32_SHCreateLocalServer@??
;    extern SHELL32_SHCreateShellFolderView alias _SHELL32_SHCreateShellFolderView@??
;    extern SHELL32_SHDuplicateEncryptionInfoFile alias _SHELL32_SHDuplicateEncryptionInfoFile@??
;    extern SHELL32_SHEncryptFile alias _SHELL32_SHEncryptFile@??
;    extern SHELL32_SHFormatDriveAsync alias _SHELL32_SHFormatDriveAsync@??
;    extern SHELL32_SHGetThreadUndoManager alias _SHELL32_SHGetThreadUndoManager@??
;    extern SHELL32_SHGetUserNameW alias _SHELL32_SHGetUserNameW@??
;    extern SHELL32_SHIsVirtualDevice alias _SHELL32_SHIsVirtualDevice@??
;    extern SHELL32_SHLaunchPropSheet alias _SHELL32_SHLaunchPropSheet@??
;    extern SHELL32_SHLogILFromFSIL alias _SHELL32_SHLogILFromFSIL@??
;    extern SHELL32_SHOpenWithDialog alias _SHELL32_SHOpenWithDialog@??
;    extern SHELL32_ShowHideIconOnlyOnDesktop alias _SHELL32_ShowHideIconOnlyOnDesktop@??
;    extern SHELL32_SHUICommandFromGUID alias _SHELL32_SHUICommandFromGUID@??
;    extern SHELL32_SimpleRatingToFilterCondition alias _SHELL32_SimpleRatingToFilterCondition@??
;    extern SHELL32_StampIconForElevation alias _SHELL32_StampIconForElevation@??
;    extern SHELL32_SuspendUndo alias _SHELL32_SuspendUndo@??
;    extern SHELL32_TryVirtualDiscImageDriveEject alias _SHELL32_TryVirtualDiscImageDriveEject@??
;    extern SHELL32_UpdateFilePlaceholderStates alias _SHELL32_UpdateFilePlaceholderStates@??
;    extern SHELL32_VerifySaferTrust alias _SHELL32_VerifySaferTrust@??
;    extern SHCoCreateInstanceWorker alias _SHCoCreateInstanceWorker@??
;    extern SHCreateCategoryEnum alias _SHCreateCategoryEnum@??
;    extern SHCreateDirectoryExWWorker alias _SHCreateDirectoryExWWorker@??
;    extern SHCreateDrvExtIcon alias _SHCreateDrvExtIcon@??
;    extern SHCreateLocalServerRunDll alias _SHCreateLocalServerRunDll@??
;    extern SheConvertPathW alias _SheConvertPathW@??
;    extern SHGetDesktopFolderWorker alias _SHGetDesktopFolderWorker@??
;    extern SHGetFileInfoWWorker alias _SHGetFileInfoWWorker@??
;    extern SHGetFolderLocationWorker alias _SHGetFolderLocationWorker@??
;    extern SHGetFolderPathAndSubDirWWorker alias _SHGetFolderPathAndSubDirWWorker@??
;    extern SHGetFolderPathAWorker alias _SHGetFolderPathAWorker@??
;    extern SHGetFolderPathWWorker alias _SHGetFolderPathWWorker@??
;    extern SHGetInstanceExplorerWorker alias _SHGetInstanceExplorerWorker@??
;    extern SHGetKnownFolderPathWorker alias _SHGetKnownFolderPathWorker@??
;    extern SHSetKnownFolderPathWorker alias _SHSetKnownFolderPathWorker@??
;    extern SHGetSpecialFolderPathAWorker alias _SHGetSpecialFolderPathAWorker@??
;    extern SHGetSpecialFolderPathWWorker alias _SHGetSpecialFolderPathWWorker@??
;    extern StrCpyNA alias _StrCpyNA@??
;    extern StrCpyNW alias _StrCpyNW@??
;    extern StrNCpyA alias _StrNCpyA@??
;    extern StrNCpyW alias _StrNCpyW@??
;    extern UsersLibrariesFolderUI_CreateInstance alias _UsersLibrariesFolderUI_CreateInstance@??
;#endif

#endif ;SHELL32_INC
