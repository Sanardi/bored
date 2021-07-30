; ====================================================;
;                                                     ;
;    shlwapi.inc for EC v2 SolAsm visual projects     ;
;                   (version 1.0.3)                   ;
;                                                     ;
;         Copyright © Ramon Sala - 2019-2020          ;
;                                                     ;
; ====================================================;

#ifndef SHLWAPI_INC
SHLWAPI_INC equ 1

SFBS_FLAGS_ROUND_TO_NEAREST_DISPLAYED_DIGIT             equ     00001H
SFBS_FLAGS_TRUNCATE_UNDISPLAYED_DECIMAL_DIGITS          equ     00002H
STIF_DEFAULT                                            equ     000000000H
STIF_SUPPORT_HEX                                        equ     000000001H

SZ_CONTENTTYPE_HTMLA                                    db      'text/html',0
SZ_CONTENTTYPE_HTMLW                                    du      "text/html",0
SZ_CONTENTTYPE_CDFA                                     db      'application/x-cdf',0
SZ_CONTENTTYPE_CDFW                                     du      "application/x-cdf", 0

GCT_INVALID                                             equ     00000H
GCT_LFNCHAR                                             equ     00001H
GCT_SHORTCHAR                                           equ     00002H
GCT_WILD                                                equ     00004H
GCT_SEPARATOR                                           equ     00008H

PMSF_NORMAL                                             equ     000000000H
PMSF_MULTIPLE                                           equ     000000001H
PMSF_DONT_STRIP_SPACES                                  equ     000010000H

URL_SCHEME_INVALID                                      equ     (-1)
URL_SCHEME_UNKNOWN                                      equ     0
URL_SCHEME_FTP                                          equ     01H
URL_SCHEME_HTTP                                         equ     02H
URL_SCHEME_GOPHER                                       equ     03H
URL_SCHEME_MAILTO                                       equ     04H
URL_SCHEME_NEWS                                         equ     05H
URL_SCHEME_NNTP                                         equ     06H
URL_SCHEME_TELNET                                       equ     07H
URL_SCHEME_WAIS                                         equ     08H
URL_SCHEME_FILE                                         equ     09H
URL_SCHEME_MK                                           equ     0AH
URL_SCHEME_HTTPS                                        equ     0BH
URL_SCHEME_SHELL                                        equ     0CH
URL_SCHEME_SNEWS                                        equ     0DH
URL_SCHEME_LOCAL                                        equ     0EH
URL_SCHEME_JAVASCRIPT                                   equ     0FH
URL_SCHEME_VBSCRIPT                                     equ     010H
URL_SCHEME_ABOUT                                        equ     011H
URL_SCHEME_RES                                          equ     012H
URL_SCHEME_MSSHELLROOTED                                equ     013H
URL_SCHEME_MSSHELLIDLIST                                equ     014H
URL_SCHEME_MSHELP                                       equ     015H
URL_SCHEME_MSSHELLDEVICE                                equ     016H
URL_SCHEME_WILDCARD                                     equ     017H
URL_SCHEME_SEARCH_MS                                    equ     018H
URL_SCHEME_SEARCH                                       equ     019H
URL_SCHEME_KNOWNFOLDER                                  equ     01AH
URL_SCHEME_MAXVALUE                                     equ     01BH

URL_PART_NONE                                           equ     00H
URL_PART_SCHEME                                         equ     01H
URL_PART_HOSTNAME                                       equ     02H
URL_PART_USERNAME                                       equ     03H
URL_PART_PASSWORD                                       equ     04H
URL_PART_PORT                                           equ     05H
URL_PART_QUERY                                          equ     06H

URLIS_URL                                               equ     00H
URLIS_OPAQUE                                            equ     01H
URLIS_NOHISTORY                                         equ     02H
URLIS_FILEURL                                           equ     03H
URLIS_APPLIABLE                                         equ     04H
URLIS_DIRECTORY                                         equ     05H
URLIS_HASQUERY                                          equ     06H

URL_UNESCAPE                                            equ     010000000H
URL_ESCAPE_UNSAFE                                       equ     020000000H
URL_PLUGGABLE_PROTOCOL                                  equ     040000000H
URL_WININET_COMPATIBILITY                               equ     080000000H
URL_DONT_ESCAPE_EXTRA_INFO                              equ     002000000H
URL_DONT_UNESCAPE_EXTRA_INFO                            equ     URL_DONT_ESCAPE_EXTRA_INFO
URL_BROWSER_MODE                                        equ     URL_DONT_ESCAPE_EXTRA_INFO
URL_ESCAPE_SPACES_ONLY                                  equ     004000000H
URL_DONT_SIMPLIFY                                       equ     008000000H
URL_NO_META                                             equ     URL_DONT_SIMPLIFY
URL_UNESCAPE_INPLACE                                    equ     000100000H
URL_CONVERT_IF_DOSPATH                                  equ     000200000H
URL_UNESCAPE_HIGH_ANSI_ONLY                             equ     000400000H
URL_INTERNAL_PATH                                       equ     000800000H
URL_FILE_USE_PATHURL                                    equ     000010000H
URL_DONT_UNESCAPE                                       equ     000020000H
URL_ESCAPE_AS_UTF8                                      equ     000040000H
URL_UNESCAPE_AS_UTF8                                    equ     URL_ESCAPE_AS_UTF8
URL_ESCAPE_ASCII_URI_COMPONENT                          equ     000080000H
URL_ESCAPE_URI_COMPONENT                                equ     <URL_ESCAPE_ASCII_URI_COMPONENT or URL_ESCAPE_AS_UTF8>
URL_UNESCAPE_URI_COMPONENT                              equ     URL_UNESCAPE_AS_UTF8
URL_ESCAPE_PERCENT                                      equ     000001000H
URL_ESCAPE_SEGMENT_ONLY                                 equ     000002000H
URL_PARTFLAG_KEEPSCHEME                                 equ     000000001H
URL_APPLY_DEFAULT                                       equ     000000001H
URL_APPLY_GUESSSCHEME                                   equ     000000002H
URL_APPLY_GUESSFILE                                     equ     000000004H
URL_APPLY_FORCEAPPLY                                    equ     000000008H

SRRF_RT_REG_NONE                                        equ     000000001H
SRRF_RT_REG_SZ                                          equ     000000002H
SRRF_RT_REG_EXPAND_SZ                                   equ     000000004H
SRRF_RT_REG_BINARY                                      equ     000000008H
SRRF_RT_REG_DWORD                                       equ     000000010H
SRRF_RT_REG_MULTI_SZ                                    equ     000000020H
SRRF_RT_REG_QWORD                                       equ     000000040H
SRRF_RT_DWORD                                           equ     <SRRF_RT_REG_BINARY or SRRF_RT_REG_DWORD>
SRRF_RT_QWORD                                           equ     <SRRF_RT_REG_BINARY or SRRF_RT_REG_QWORD>
SRRF_RT_ANY                                             equ     00000ffffH
SRRF_RM_ANY                                             equ     000000000H
SRRF_RM_NORMAL                                          equ     000010000H
SRRF_RM_SAFE                                            equ     000020000H
SRRF_RM_SAFENETWORK                                     equ     000040000H
SRRF_NOEXPAND                                           equ     010000000H
SRRF_ZEROONFAILURE                                      equ     020000000H
SRRF_NOVIRT                                             equ     040000000H

SHREGDEL_DEFAULT                                        equ     000000000H
SHREGDEL_HKCU                                           equ     000000001H
SHREGDEL_HKLM                                           equ     000000010H
SHREGDEL_BOTH                                           equ     000000011H

SHREGENUM_DEFAULT                                       equ     000000000H
SHREGENUM_HKCU                                          equ     000000001H
SHREGENUM_HKLM                                          equ     000000010H
SHREGENUM_BOTH                                          equ     000000011H

SHREGSET_HKCU                                           equ     000000001H
SHREGSET_FORCE_HKCU                                     equ     000000002H
SHREGSET_HKLM                                           equ     000000004H
SHREGSET_FORCE_HKLM                                     equ     000000008H
SHREGSET_DEFAULT                                        equ     <SHREGSET_FORCE_HKCU or SHREGSET_HKLM>

ASSOCF_NONE                                             equ     000000000H
ASSOCF_INIT_NOREMAPCLSID                                equ     000000001H
ASSOCF_INIT_BYEXENAME                                   equ     000000002H
ASSOCF_OPEN_BYEXENAME                                   equ     000000002H
ASSOCF_INIT_DEFAULTTOSTAR                               equ     000000004H
ASSOCF_INIT_DEFAULTTOFOLDER                             equ     000000008H
ASSOCF_NOUSERSETTINGS                                   equ     000000010H
ASSOCF_NOTRUNCATE                                       equ     000000020H
ASSOCF_VERIFY                                           equ     000000040H
ASSOCF_REMAPRUNDLL                                      equ     000000080H
ASSOCF_NOFIXUPS                                         equ     000000100H
ASSOCF_IGNOREBASECLASS                                  equ     000000200H
ASSOCF_INIT_IGNOREUNKNOWN                               equ     000000400H
ASSOCF_INIT_FIXED_PROGID                                equ     000000800H
ASSOCF_IS_PROTOCOL                                      equ     000001000H
ASSOCF_INIT_FOR_FILE                                    equ     000002000H

ASSOCSTR_COMMAND                                        equ     1
ASSOCSTR_EXECUTABLE                                     equ     02H
ASSOCSTR_FRIENDLYDOCNAME                                equ     03H
ASSOCSTR_FRIENDLYAPPNAME                                equ     04H
ASSOCSTR_NOOPEN                                         equ     05H
ASSOCSTR_SHELLNEWVALUE                                  equ     06H
ASSOCSTR_DDECOMMAND                                     equ     07H
ASSOCSTR_DDEIFEXEC                                      equ     08H
ASSOCSTR_DDEAPPLICATION                                 equ     09H
ASSOCSTR_DDETOPIC                                       equ     0AH
ASSOCSTR_INFOTIP                                        equ     0BH
ASSOCSTR_QUICKTIP                                       equ     0CH
ASSOCSTR_TILEINFO                                       equ     0DH
ASSOCSTR_CONTENTTYPE                                    equ     0EH
ASSOCSTR_DEFAULTICON                                    equ     0FH
ASSOCSTR_SHELLEXTENSION                                 equ     010H
ASSOCSTR_DROPTARGET                                     equ     011H
ASSOCSTR_DELEGATEEXECUTE                                equ     012H
ASSOCSTR_SUPPORTED_URI_PROTOCOLS                        equ     013H
ASSOCSTR_PROGID                                         equ     014H
ASSOCSTR_APPID                                          equ     015H
ASSOCSTR_APPPUBLISHER                                   equ     016H
ASSOCSTR_APPICONREFERENCE                               equ     017H
ASSOCSTR_MAX                                            equ     018H

ASSOCKEY_SHELLEXECCLASS                                 equ     01H
ASSOCKEY_APP                                            equ     02H
ASSOCKEY_CLASS                                          equ     03H
ASSOCKEY_BASECLASS                                      equ     04H
ASSOCKEY_MAX                                            equ     05H

ASSOCDATA_MSIDESCRIPTOR                                 equ     01H
ASSOCDATA_NOACTIVATEHANDLER                             equ     02H
ASSOCDATA_QUERYCLASSSTORE                               equ     03H
ASSOCDATA_HASPERUSERASSOC                               equ     04H
ASSOCDATA_EDITFLAGS                                     equ     05H
ASSOCDATA_VALUE                                         equ     06H
ASSOCDATA_MAX                                           equ     07H

ASSOCENUM_NONE                                          equ     00H

FTA_None                                                equ     000000000H
FTA_Exclude                                             equ     000000001H
FTA_Show                                                equ     000000002H
FTA_HasExtension                                        equ     000000004H
FTA_NoEdit                                              equ     000000008H
FTA_NoRemove                                            equ     000000010H
FTA_NoNewVerb                                           equ     000000020H
FTA_NoEditVerb                                          equ     000000040H
FTA_NoRemoveVerb                                        equ     000000080H
FTA_NoEditDesc                                          equ     000000100H
FTA_NoEditIcon                                          equ     000000200H
FTA_NoEditDflt                                          equ     000000400H
FTA_NoEditVerbCmd                                       equ     000000800H
FTA_NoEditVerbExe                                       equ     000001000H
FTA_NoDDE                                               equ     000002000H
FTA_NoEditMIME                                          equ     000008000H
FTA_OpenIsSafe                                          equ     000010000H
FTA_AlwaysUnsafe                                        equ     000020000H
FTA_NoRecentDocs                                        equ     000100000H
FTA_SafeForElevation                                    equ     000200000H
FTA_AlwaysUseDirectInvoke                               equ     000400000H

SPMODE_SHELL                                            equ     000000001H
SPMODE_DEBUGOUT                                         equ     000000002H
SPMODE_TEST                                             equ     000000004H
SPMODE_BROWSER                                          equ     000000008H
SPMODE_FLUSH                                            equ     000000010H
SPMODE_EVENT                                            equ     000000020H
SPMODE_MSVM                                             equ     000000040H
SPMODE_FORMATTEXT                                       equ     000000080H
SPMODE_PROFILE                                          equ     000000100H
SPMODE_DEBUGBREAK                                       equ     000000200H
SPMODE_MSGTRACE                                         equ     000000400H
SPMODE_PERFTAGS                                         equ     000000800H
SPMODE_MEMWATCH                                         equ     000001000H
SPMODE_DBMON                                            equ     000002000H
SPMODE_MULTISTOP                                        equ     000004000H
SPMODE_EVENTTRACE                                       equ     000008000H

SHGVSPB_PERUSER                                         equ     000000001H
SHGVSPB_ALLUSERS                                        equ     000000002H
SHGVSPB_PERFOLDER                                       equ     000000004H
SHGVSPB_ALLFOLDERS                                      equ     000000008H
SHGVSPB_INHERIT                                         equ     000000010H
SHGVSPB_ROAM                                            equ     000000020H
SHGVSPB_NOAUTODEFAULTS                                  equ     080000000H
SHGVSPB_FOLDER                                          equ     <SHGVSPB_PERUSER or SHGVSPB_PERFOLDER>
SHGVSPB_FOLDERNODEFAULTS                                equ     <SHGVSPB_PERUSER or SHGVSPB_PERFOLDER or SHGVSPB_NOAUTODEFAULTS>
SHGVSPB_USERDEFAULTS                                    equ     <SHGVSPB_PERUSER or SHGVSPB_ALLFOLDERS>
SHGVSPB_GLOBALDEFAULTS                                  equ     <SHGVSPB_ALLUSERS or SHGVSPB_ALLFOLDERS>

FDTF_SHORTTIME                                          equ     000000001H
FDTF_SHORTDATE                                          equ     000000002H
FDTF_DEFAULT                                            equ     <FDTF_SHORTDATE or FDTF_SHORTTIME>
FDTF_LONGDATE                                           equ     000000004H
FDTF_LONGTIME                                           equ     000000008H
FDTF_RELATIVE                                           equ     000000010H
FDTF_LTRDATE                                            equ     000000100H
FDTF_RTLDATE                                            equ     000000200H
FDTF_NOAUTOREADINGORDER                                 equ     000000400H

OS_WINDOWS                                              equ     0
OS_NT                                                   equ     1
OS_WIN95ORGREATER                                       equ     2
OS_NT4ORGREATER                                         equ     3
OS_WIN98ORGREATER                                       equ     5
OS_WIN98_GOLD                                           equ     6
OS_WIN2000ORGREATER                                     equ     7
OS_WIN2000PRO                                           equ     8
OS_WIN2000SERVER                                        equ     9
OS_WIN2000ADVSERVER                                     equ     10
OS_WIN2000DATACENTER                                    equ     11
OS_WIN2000TERMINAL                                      equ     12
OS_EMBEDDED                                             equ     13
OS_TERMINALCLIENT                                       equ     14
OS_TERMINALREMOTEADMIN                                  equ     15
OS_WIN95_GOLD                                           equ     16
OS_MEORGREATER                                          equ     17
OS_XPORGREATER                                          equ     18
OS_HOME                                                 equ     19
OS_PROFESSIONAL                                         equ     20
OS_DATACENTER                                           equ     21
OS_ADVSERVER                                            equ     22
OS_SERVER                                               equ     23
OS_TERMINALSERVER                                       equ     24
OS_PERSONALTERMINALSERVER                               equ     25
OS_FASTUSERSWITCHING                                    equ     26
OS_WELCOMELOGONUI                                       equ     27
OS_DOMAINMEMBER                                         equ     28
OS_ANYSERVER                                            equ     29
OS_WOW6432                                              equ     30
OS_WEBSERVER                                            equ     31
OS_SMALLBUSINESSSERVER                                  equ     32
OS_TABLETPC                                             equ     33
OS_SERVERADMINUI                                        equ     34
OS_MEDIACENTER                                          equ     35
OS_APPLIANCE                                            equ     36

GLOBALCOUNTER_SEARCHMANAGER                             equ     00H
GLOBALCOUNTER_SEARCHOPTIONS                             equ     01H
GLOBALCOUNTER_FOLDERSETTINGSCHANGE                      equ     02H
GLOBALCOUNTER_RATINGS                                   equ     03H
GLOBALCOUNTER_APPROVEDSITES                             equ     04H
GLOBALCOUNTER_RESTRICTIONS                              equ     05H
GLOBALCOUNTER_SHELLSETTINGSCHANGED                      equ     06H
GLOBALCOUNTER_SYSTEMPIDLCHANGE                          equ     07H
GLOBALCOUNTER_OVERLAYMANAGER                            equ     08H
GLOBALCOUNTER_QUERYASSOCIATIONS                         equ     09H
GLOBALCOUNTER_IESESSIONS                                equ     0AH
GLOBALCOUNTER_IEONLY_SESSIONS                           equ     0BH
GLOBALCOUNTER_APPLICATION_DESTINATIONS                  equ     0CH
__UNUSED_RECYCLE_WAS_GLOBALCOUNTER_CSCSYNCINPROGRESS    equ     0DH
GLOBALCOUNTER_BITBUCKETNUMDELETERS                      equ     0EH
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_SHARES                  equ     0FH
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_A                 equ     010H
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_B                 equ     011H
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_C                 equ     012H
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_D                 equ     013H
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_E                 equ     014H
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_F                 equ     015H
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_G                 equ     016H
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_H                 equ     017H
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_I                 equ     018H
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_J                 equ     019H
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_K                 equ     01AH
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_L                 equ     01BH
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_M                 equ     01CH
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_N                 equ     01DH
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_O                 equ     01EH
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_P                 equ     01FH
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_Q                 equ     020H
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_R                 equ     021H
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_S                 equ     022H
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_T                 equ     023H
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_U                 equ     024H
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_V                 equ     025H
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_W                 equ     026H
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_X                 equ     027H
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_Y                 equ     028H
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_Z                 equ     029H
__UNUSED_RECYCLE_WAS_GLOBALCOUNTER_RECYCLEDIRTYCOUNT_SERVERDRIVE equ 02AH
__UNUSED_RECYCLE_WAS_GLOBALCOUNTER_RECYCLEGLOBALDIRTYCOUNT equ  02BH
GLOBALCOUNTER_RECYCLEBINENUM                            equ     02CH
GLOBALCOUNTER_RECYCLEBINCORRUPTED                       equ     02DH
GLOBALCOUNTER_RATINGS_STATECOUNTER                      equ     02EH
GLOBALCOUNTER_PRIVATE_PROFILE_CACHE                     equ     02FH
GLOBALCOUNTER_INTERNETTOOLBAR_LAYOUT                    equ     030H
GLOBALCOUNTER_FOLDERDEFINITION_CACHE                    equ     031H
GLOBALCOUNTER_COMMONPLACES_LIST_CACHE                   equ     032H
GLOBALCOUNTER_PRIVATE_PROFILE_CACHE_MACHINEWIDE         equ     033H
GLOBALCOUNTER_ASSOCCHANGED                              equ     034H
GLOBALCOUNTER_APP_ITEMS_STATE_STORE_CACHE               equ     035H
GLOBALCOUNTER_SETTINGSYNC_ENABLED                       equ     036H
GLOBALCOUNTER_APPSFOLDER_FILETYPEASSOCIATION_COUNTER    equ     037H
GLOBALCOUNTER_USERINFOCHANGED                           equ     038H
GLOBALCOUNTER_SYNC_ENGINE_INFORMATION_CACHE_MACHINEWIDE equ     039H
GLOBALCOUNTER_MAXIMUMVALUE                              equ     03AH

PLATFORM_UNKNOWN                                        equ     0
PLATFORM_IE3                                            equ     1
PLATFORM_BROWSERONLY                                    equ     1
PLATFORM_INTEGRATED                                     equ     2

ILMM_IE4                                                equ     0

SHACF_DEFAULT                                           equ     000000000H
SHACF_FILESYSTEM                                        equ     000000001H
SHACF_URLALL                                            equ     <SHACF_URLHISTORY or SHACF_URLMRU>
SHACF_URLHISTORY                                        equ     000000002H
SHACF_URLMRU                                            equ     000000004H
SHACF_USETAB                                            equ     000000008H
SHACF_FILESYS_ONLY                                      equ     000000010H
SHACF_FILESYS_DIRS                                      equ     000000020H
SHACF_VIRTUAL_NAMESPACE                                 equ     000000040H
SHACF_AUTOSUGGEST_FORCE_ON                              equ     010000000H
SHACF_AUTOSUGGEST_FORCE_OFF                             equ     020000000H
SHACF_AUTOAPPEND_FORCE_ON                               equ     040000000H
SHACF_AUTOAPPEND_FORCE_OFF                              equ     080000000H

CTF_INSIST                                              equ     000000001H
CTF_THREAD_REF                                          equ     000000002H
CTF_PROCESS_REF                                         equ     000000004H
CTF_COINIT_STA                                          equ     000000008H
CTF_COINIT                                              equ     000000008H
CTF_FREELIBANDEXIT                                      equ     000000010H
CTF_REF_COUNTED                                         equ     000000020H
CTF_WAIT_ALLOWCOM                                       equ     000000040H
CTF_UNUSED                                              equ     000000080H
CTF_INHERITWOW64                                        equ     000000100H
CTF_WAIT_NO_REENTRANCY                                  equ     000000200H
CTF_KEYBOARD_LOCALE                                     equ     000000400H
CTF_OLEINITIALIZE                                       equ     000000800H
CTF_COINIT_MTA                                          equ     000001000H
CTF_NOADDREFLIB                                         equ     000002000H

DLLVER_PLATFORM_WINDOWS                                 equ     000000001H
DLLVER_PLATFORM_NT                                      equ     000000002H

DLLVER_MAJOR_MASK                                       equ     0FFFF000000000000H
DLLVER_MINOR_MASK                                       equ     00000FFFF00000000H
DLLVER_BUILD_MASK                                       equ     000000000FFFF0000H
DLLVER_QFE_MASK                                         equ     0000000000000FFFFH

;======================================== Structures ======================================;
struct PARSEDURLA
    cbSize      dd    ?
    pszProtocol xword ?
    cchProtocol dd    ?
    pszSuffix   xword ?
    cchSuffix   dd    ?
    nScheme     dd    ?
ends

struct PARSEDURLW
    cbSize      dd    ?
    pszProtocol xword ?
    cchProtocol dd    ?
    pszSuffix   xword ?
    cchSuffix   dd    ?
    nScheme     dd    ?
ends

struct QITAB
    piid     xword ?
    dwOffset dd    ?
ends

struct DLLVERSIONINFO2
    info1      DLLVERSIONINFO ?
    dwFlags    dd ?
    ullVersion dq ?
ends

;======================================== Functions =======================================;
#if COFF_FORMAT == 1
    from_lib shlwapi.lib
#else
    from_dll shlwapi.dll
#endif

#ifdef APP_WIN64
    import AssocCreate
    import AssocGetPerceivedType
    import AssocIsDangerous
    import AssocQueryKeyA
    import AssocQueryKeyW
    import AssocQueryStringA
    import AssocQueryStringW
    import AssocQueryStringByKeyA
    import AssocQueryStringByKeyW
    import ChrCmpIA
    import ChrCmpIW
    import ColorAdjustLuma
    import ColorHLSToRGB
    import ColorRGBToHLS
    import ConnectToConnectionPoint
    import DelayLoadFailureHook
    import DllGetClassObject
    import DllInstall
    import GetAcceptLanguagesA
    import GetAcceptLanguagesW
    import GetMenuPosFromID
    import GUIDFromStringA
    import GUIDFromStringW
    import HashData
    import IStream_Copy
    import IUnknown_Exec
    import IUnknown_QueryStatus
    import IStream_Read
    import IStream_ReadPidl
    import IStream_ReadStr
    import IStream_Reset
    import IStream_Size
    import IStream_Write
    import IStream_WritePidl
    import IStream_WriteStr
    import IUnknown_AtomicRelease
    import IUnknown_GetSite
    import IUnknown_GetWindow
    import IUnknown_QueryService
    import IUnknown_Set
    import IUnknown_SetSite
    import IntlStrEqWorkerA
    import IntlStrEqWorkerW
    import IsCharSpaceA
    import IsCharSpaceW
    import IsInternetESCEnabled
    import IsOS
    import MLFreeLibrary
    import MLLoadLibraryA
    import MLLoadLibraryW
    import ParseURLA
    import ParseURLW
    import PathAddBackslashA
    import PathAddBackslashW
    import PathAddExtensionA
    import PathAddExtensionW
    import PathAppendA
    import PathAppendW
    import PathBuildRootA
    import PathBuildRootW
    import PathCanonicalizeA
    import PathCanonicalizeW
    import PathCombineA
    import PathCombineW
    import PathCommonPrefixA
    import PathCommonPrefixW
    import PathCompactPathA
    import PathCompactPathExA
    import PathCompactPathExW
    import PathCompactPathW
    import PathCreateFromUrlA
    import PathCreateFromUrlAlloc
    import PathCreateFromUrlW
    import PathFileExistsA
    import PathFileExistsAndAttributesA
    import PathFileExistsAndAttributesW
    import PathFileExistsW
    import PathFindExtensionA
    import PathFindExtensionW
    import PathFindFileNameA
    import PathFindFileNameW
    import PathFindNextComponentA
    import PathFindNextComponentW
    import PathFindOnPathA
    import PathFindOnPathW
    import PathFindSuffixArrayA
    import PathFindSuffixArrayW
    import PathGetArgsA
    import PathGetArgsW
    import PathGetCharTypeA
    import PathGetCharTypeW
    import PathGetDriveNumberA
    import PathGetDriveNumberW
    import PathIsContentTypeA
    import PathIsContentTypeW
    import PathIsDirectoryA
    import PathIsDirectoryEmptyA
    import PathIsDirectoryEmptyW
    import PathIsDirectoryW
    import PathIsFileSpecA
    import PathIsFileSpecW
    import PathIsLFNFileSpecA
    import PathIsLFNFileSpecW
    import PathIsNetworkPathA
    import PathIsNetworkPathW
    import PathIsPrefixA
    import PathIsPrefixW
    import PathIsRelativeA
    import PathIsRelativeW
    import PathIsRootA
    import PathIsRootW
    import PathIsSameRootA
    import PathIsSameRootW
    import PathIsSystemFolderA
    import PathIsSystemFolderW
    import PathIsUNCA
    import PathIsUNCServerA
    import PathIsUNCServerShareA
    import PathIsUNCServerShareW
    import PathIsUNCServerW
    import PathIsUNCW
    import PathIsURLA
    import PathIsURLW
    import PathMakePrettyA
    import PathMakePrettyW
    import PathMakeSystemFolderA
    import PathMakeSystemFolderW
    import PathMatchSpecA
    import PathMatchSpecExA
    import PathMatchSpecExW
    import PathMatchSpecW
    import PathParseIconLocationA
    import PathParseIconLocationW
    import PathQuoteSpacesA
    import PathQuoteSpacesW
    import PathRelativePathToA
    import PathRelativePathToW
    import PathRemoveArgsA
    import PathRemoveArgsW
    import PathRemoveBackslashA
    import PathRemoveBackslashW
    import PathRemoveBlanksA
    import PathRemoveBlanksW
    import PathRemoveExtensionA
    import PathRemoveExtensionW
    import PathRemoveFileSpecA
    import PathRemoveFileSpecW
    import PathRenameExtensionA
    import PathRenameExtensionW
    import PathSearchAndQualifyA
    import PathSearchAndQualifyW
    import PathSetDlgItemPathA
    import PathSetDlgItemPathW
    import PathSkipRootA
    import PathSkipRootW
    import PathStripPathA
    import PathStripPathW
    import PathStripToRootA
    import PathStripToRootW
    import PathUnExpandEnvStringsA
    import PathUnExpandEnvStringsW
    import PathUndecorateA
    import PathUndecorateW
    import PathUnmakeSystemFolderA
    import PathUnmakeSystemFolderW
    import PathUnquoteSpacesA
    import PathUnquoteSpacesW
    import QISearch
    import SHAllocShared
    import SHAnsiToAnsi
    import SHAnsiToUnicode
    import SHAutoComplete
    import SHCopyKeyA
    import SHCopyKeyW
    import SHCreateMemStream
    import SHCreateShellPalette
    import SHCreateStreamOnFileA
    import SHCreateStreamOnFileEx
    import SHCreateStreamOnFileW
    import SHCreateThread
    import SHCreateThreadRef
    import SHCreateThreadWithHandle
    import SHCreateWorkerWindowA
    import SHCreateWorkerWindowW
    import SHDeleteEmptyKeyA
    import SHDeleteEmptyKeyW
    import SHDeleteKeyA
    import SHDeleteKeyW
    import SHDeleteOrphanKeyA
    import SHDeleteOrphanKeyW
    import SHDeleteValueA
    import SHDeleteValueW
    import SHEnumKeyExA
    import SHEnumKeyExW
    import SHEnumValueA
    import SHEnumValueW
    import SHFormatDateTimeA
    import SHFormatDateTimeW
    import SHFreeShared
    import SHGetInverseCMAP
    import SHGetThreadRef
    import SHGetValueA
    import SHGetValueW
    import SHGetViewStatePropertyBag
    import SHIsChildOrSelf
    import SHIsLowMemoryMachine
    import SHLoadIndirectString
    import SHLockShared
    import SHMessageBoxCheckA
    import SHMessageBoxCheckW
    import SHOpenRegStream2A
    import SHOpenRegStream2W
    import SHOpenRegStreamA
    import SHOpenRegStreamW
    import SHPinDllOfCLSID
    import SHQueryInfoKeyA
    import SHQueryInfoKeyW
    import SHQueryValueExA
    import SHQueryValueExW
    import SHRegCloseUSKey
    import SHRegCreateUSKeyA
    import SHRegCreateUSKeyW
    import SHRegDeleteEmptyUSKeyA
    import SHRegDeleteEmptyUSKeyW
    import SHRegDeleteUSValueA
    import SHRegDeleteUSValueW
    import SHRegDuplicateHKey
    import SHRegEnumUSKeyA
    import SHRegEnumUSKeyW
    import SHRegEnumUSValueA
    import SHRegEnumUSValueW
    import SHRegGetBoolUSValueA
    import SHRegGetBoolUSValueW
    import SHRegGetBoolValueFromHKCUHKLM
    import SHRegGetIntW
    import SHRegGetPathA
    import SHRegGetPathW
    import SHRegGetUSValueA
    import SHRegGetUSValueW
    import SHRegGetValueA
    import SHRegGetValueFromHKCUHKLM
    import SHRegGetValueW
    import SHRegOpenUSKeyA
    import SHRegOpenUSKeyW
    import SHRegQueryInfoUSKeyA
    import SHRegQueryInfoUSKeyW
    import SHRegQueryUSValueA
    import SHRegQueryUSValueW
    import SHRegSetPathA
    import SHRegSetPathW
    import SHRegSetUSValueA
    import SHRegSetUSValueW
    import SHRegWriteUSValueA
    import SHRegWriteUSValueW
    import SHRegisterValidateTemplate
    import SHReleaseThreadRef
    import SHRunIndirectRegClientCommand
    import SHSendMessageBroadcastA
    import SHSendMessageBroadcastW
    import SHSetThreadRef
    import SHSetValueA
    import SHSetValueW
    import SHSkipJunction
    import SHStrDupA
    import SHStrDupW
    import SHStripMneumonicA
    import SHStripMneumonicW
    import SHUnicodeToAnsi
    import SHUnicodeToAnsiCP
    import SHUnicodeToUnicode
    import SHUnlockShared
    import StrCSpnA
    import StrCSpnIA
    import StrCSpnIW
    import StrCSpnW
    import StrCatBuffA
    import StrCatBuffW
    import StrCatChainW
    import StrChrA
    import StrChrIA
    import StrChrIW
    import StrChrNIW
    import StrChrNW
    import StrChrW
    import StrCmpCA
    import StrCmpCW
    import StrCmpICA
    import StrCmpICW
    import StrCmpIW
    import StrCmpLogicalW
    import StrCmpNA
    import StrCmpNCA
    import StrCmpNCW
    import StrCmpNIA
    import StrCmpNICA
    import StrCmpNICW
    import StrCmpNIW
    import StrCmpNW
    import StrCmpW
    import StrCpyNW
    import StrCpyW
    import StrDupA
    import StrDupW
    import StrFormatByteSize64A
    import StrFormatByteSizeA
    import StrFormatByteSizeEx
    import StrFormatByteSizeW
    import StrFormatKBSizeA
    import StrFormatKBSizeW
    import StrFromTimeIntervalA
    import StrFromTimeIntervalW
    import StrIsIntlEqualA
    import StrIsIntlEqualW
    import StrNCatA
    import StrNCatW
    import StrPBrkA
    import StrPBrkW
    import StrRChrA
    import StrRChrIA
    import StrRChrIW
    import StrRChrW
    import StrRStrIA
    import StrRStrIW
    import StrRetToBSTR
    import StrRetToBufA
    import StrRetToBufW
    import StrRetToStrA
    import StrRetToStrW
    import StrSpnA
    import StrSpnW
    import StrStrA
    import StrStrIA
    import StrStrIW
    import StrStrNIW
    import StrStrNW
    import StrStrW
    import StrToInt64ExA
    import StrToInt64ExW
    import StrToIntA
    import StrToIntExA
    import StrToIntExW
    import StrToIntW
    import StrTrimA
    import StrTrimW
    import UrlApplySchemeA
    import UrlApplySchemeW
    import UrlCanonicalizeA
    import UrlCanonicalizeW
    import UrlCombineA
    import UrlCombineW
    import UrlCompareA
    import UrlCompareW
    import UrlCreateFromPathA
    import UrlCreateFromPathW
    import UrlEscapeA
    import UrlEscapeW
    import UrlFixupW
    import UrlGetLocationA
    import UrlGetLocationW
    import UrlGetPartA
    import UrlGetPartW
    import UrlHashA
    import UrlHashW
    import UrlIsA
    import UrlIsNoHistoryA
    import UrlIsNoHistoryW
    import UrlIsOpaqueA
    import UrlIsOpaqueW
    import UrlIsW
    import UrlUnescapeA
    import UrlUnescapeW
    import WhichPlatform
    import wnsprintfA
    import wnsprintfW
    import wvnsprintfA
    import wvnsprintfW
#else
    extern AssocCreate alias _AssocCreate@24
    extern AssocGetPerceivedType alias _AssocGetPerceivedType@16
    extern AssocIsDangerous alias _AssocIsDangerous@4
    extern AssocQueryKeyA alias _AssocQueryKeyA@20
    extern AssocQueryKeyW alias _AssocQueryKeyW@20
    extern AssocQueryStringA alias _AssocQueryStringA@24
    extern AssocQueryStringW alias _AssocQueryStringW@24
    extern AssocQueryStringByKeyA alias _AssocQueryStringByKeyA@24
    extern AssocQueryStringByKeyW alias _AssocQueryStringByKeyW@24
    extern ChrCmpIA alias _ChrCmpIA@8
    extern ChrCmpIW alias _ChrCmpIW@8
    extern ColorAdjustLuma alias _ColorAdjustLuma@12
    extern ColorHLSToRGB alias _ColorHLSToRGB@12
    extern ColorRGBToHLS alias _ColorRGBToHLS@16
    ;extern ConnectToConnectionPoint alias _ConnectToConnectionPoint@24
    ;extern DelayLoadFailureHook alias _DelayLoadFailureHook@8
    extern DllInstall alias _DllInstall@8
    extern GetAcceptLanguagesA alias _GetAcceptLanguagesA@8
    extern GetAcceptLanguagesW alias _GetAcceptLanguagesW@8
    extern GetMenuPosFromID alias _GetMenuPosFromID@8
    extern HashData alias _HashData@16
    extern IStream_Copy alias _IStream_Copy@12
    extern IStream_Read alias _IStream_Read@12
    extern IStream_ReadPidl alias _IStream_ReadPidl@8
    extern IStream_ReadStr alias _IStream_ReadStr@8
    extern IStream_Reset alias _IStream_Reset@4
    extern IStream_Size alias _IStream_Size@8
    extern IStream_Write alias _IStream_Write@12
    extern IStream_WritePidl alias _IStream_WritePidl@8
    extern IStream_WriteStr alias _IStream_WriteStr@8
    extern IUnknown_AtomicRelease alias _IUnknown_AtomicRelease@4
    extern IUnknown_GetSite alias _IUnknown_GetSite@12
    extern IUnknown_GetWindow alias _IUnknown_GetWindow@8
    extern IUnknown_QueryService alias _IUnknown_QueryService@16
    extern IUnknown_Set alias _IUnknown_Set@8
    extern IUnknown_SetSite alias _IUnknown_SetSite@8
    extern IntlStrEqWorkerA alias _IntlStrEqWorkerA@16
    extern IntlStrEqWorkerW alias _IntlStrEqWorkerW@16
    extern IsCharSpaceA alias _IsCharSpaceA@4
    extern IsCharSpaceW alias _IsCharSpaceW@4
    extern IsInternetESCEnabled alias _IsInternetESCEnabled@0
    extern IsOS alias _IsOS@4
    extern MLLoadLibraryA alias _MLLoadLibraryA@12
    extern MLLoadLibraryW alias _MLLoadLibraryW@12
    extern ParseURLA alias _ParseURLA@8
    extern ParseURLW alias _ParseURLW@8
    extern PathAddBackslashA alias _PathAddBackslashA@4
    extern PathAddBackslashW alias _PathAddBackslashW@4
    extern PathAddExtensionA alias _PathAddExtensionA@8
    extern PathAddExtensionW alias _PathAddExtensionW@8
    extern PathAppendA alias _PathAppendA@8
    extern PathAppendW alias _PathAppendW@8
    extern PathBuildRootA alias _PathBuildRootA@8
    extern PathBuildRootW alias _PathBuildRootW@8
    extern PathCanonicalizeA alias _PathCanonicalizeA@8
    extern PathCanonicalizeW alias _PathCanonicalizeW@8
    extern PathCombineA alias _PathCombineA@12
    extern PathCombineW alias _PathCombineW@12
    extern PathCommonPrefixA alias _PathCommonPrefixA@12
    extern PathCommonPrefixW alias _PathCommonPrefixW@12
    extern PathCompactPathA alias _PathCompactPathA@12
    extern PathCompactPathExA alias _PathCompactPathExA@16
    extern PathCompactPathExW alias _PathCompactPathExW@16
    extern PathCompactPathW alias _PathCompactPathW@12
    extern PathCreateFromUrlA alias _PathCreateFromUrlA@16
    extern PathCreateFromUrlAlloc alias _PathCreateFromUrlAlloc@12
    extern PathCreateFromUrlW alias _PathCreateFromUrlW@16
    extern PathFileExistsA alias _PathFileExistsA@4
    extern PathFileExistsW alias _PathFileExistsW@4
    extern PathFindExtensionA alias _PathFindExtensionA@4
    extern PathFindExtensionW alias _PathFindExtensionW@4
    extern PathFindFileNameA alias _PathFindFileNameA@4
    extern PathFindFileNameW alias _PathFindFileNameW@4
    extern PathFindNextComponentA alias _PathFindNextComponentA@4
    extern PathFindNextComponentW alias _PathFindNextComponentW@4
    extern PathFindOnPathA alias _PathFindOnPathA@8
    extern PathFindOnPathW alias _PathFindOnPathW@8
    extern PathFindSuffixArrayA alias _PathFindSuffixArrayA@12
    extern PathFindSuffixArrayW alias _PathFindSuffixArrayW@12
    extern PathGetArgsA alias _PathGetArgsA@4
    extern PathGetArgsW alias _PathGetArgsW@4
    extern PathGetCharTypeA alias _PathGetCharTypeA@4
    extern PathGetCharTypeW alias _PathGetCharTypeW@4
    extern PathGetDriveNumberA alias _PathGetDriveNumberA@4
    extern PathGetDriveNumberW alias _PathGetDriveNumberW@4
    extern PathIsContentTypeA alias _PathIsContentTypeA@8
    extern PathIsContentTypeW alias _PathIsContentTypeW@8
    extern PathIsDirectoryA alias _PathIsDirectoryA@4
    extern PathIsDirectoryEmptyA alias _PathIsDirectoryEmptyA@4
    extern PathIsDirectoryEmptyW alias _PathIsDirectoryEmptyW@4
    extern PathIsDirectoryW alias _PathIsDirectoryW@4
    extern PathIsFileSpecA alias _PathIsFileSpecA@4
    extern PathIsFileSpecW alias _PathIsFileSpecW@4
    extern PathIsLFNFileSpecA alias _PathIsLFNFileSpecA@4
    extern PathIsLFNFileSpecW alias _PathIsLFNFileSpecW@4
    extern PathIsNetworkPathA alias _PathIsNetworkPathA@4
    extern PathIsNetworkPathW alias _PathIsNetworkPathW@4
    extern PathIsPrefixA alias _PathIsPrefixA@8
    extern PathIsPrefixW alias _PathIsPrefixW@8
    extern PathIsRelativeA alias _PathIsRelativeA@4
    extern PathIsRelativeW alias _PathIsRelativeW@4
    extern PathIsRootA alias _PathIsRootA@4
    extern PathIsRootW alias _PathIsRootW@4
    extern PathIsSameRootA alias _PathIsSameRootA@8
    extern PathIsSameRootW alias _PathIsSameRootW@8
    extern PathIsSystemFolderA alias _PathIsSystemFolderA@8
    extern PathIsSystemFolderW alias _PathIsSystemFolderW@8
    extern PathIsUNCA alias _PathIsUNCA@4
    extern PathIsUNCServerA alias _PathIsUNCServerA@4
    extern PathIsUNCServerShareA alias _PathIsUNCServerShareA@4
    extern PathIsUNCServerShareW alias _PathIsUNCServerShareW@4
    extern PathIsUNCServerW alias _PathIsUNCServerW@4
    extern PathIsUNCW alias _PathIsUNCW@4
    extern PathIsURLA alias _PathIsURLA@4
    extern PathIsURLW alias _PathIsURLW@4
    extern PathMakePrettyA alias _PathMakePrettyA@4
    extern PathMakePrettyW alias _PathMakePrettyW@4
    extern PathMakeSystemFolderA alias _PathMakeSystemFolderA@4
    extern PathMakeSystemFolderW alias _PathMakeSystemFolderW@4
    extern PathMatchSpecA alias _PathMatchSpecA@8
    extern PathMatchSpecExA alias _PathMatchSpecExA@12
    extern PathMatchSpecExW alias _PathMatchSpecExW@12
    extern PathMatchSpecW alias _PathMatchSpecW@8
    extern PathParseIconLocationA alias _PathParseIconLocationA@4
    extern PathParseIconLocationW alias _PathParseIconLocationW@4
    extern PathQuoteSpacesA alias _PathQuoteSpacesA@4
    extern PathQuoteSpacesW alias _PathQuoteSpacesW@4
    extern PathRelativePathToA alias _PathRelativePathToA@20
    extern PathRelativePathToW alias _PathRelativePathToW@20
    extern PathRemoveArgsA alias _PathRemoveArgsA@4
    extern PathRemoveArgsW alias _PathRemoveArgsW@4
    extern PathRemoveBackslashA alias _PathRemoveBackslashA@4
    extern PathRemoveBackslashW alias _PathRemoveBackslashW@4
    extern PathRemoveBlanksA alias _PathRemoveBlanksA@4
    extern PathRemoveBlanksW alias _PathRemoveBlanksW@4
    extern PathRemoveExtensionA alias _PathRemoveExtensionA@4
    extern PathRemoveExtensionW alias _PathRemoveExtensionW@4
    extern PathRemoveFileSpecA alias _PathRemoveFileSpecA@4
    extern PathRemoveFileSpecW alias _PathRemoveFileSpecW@4
    extern PathRenameExtensionA alias _PathRenameExtensionA@8
    extern PathRenameExtensionW alias _PathRenameExtensionW@8
    extern PathSearchAndQualifyA alias _PathSearchAndQualifyA@12
    extern PathSearchAndQualifyW alias _PathSearchAndQualifyW@12
    extern PathSetDlgItemPathA alias _PathSetDlgItemPathA@12
    extern PathSetDlgItemPathW alias _PathSetDlgItemPathW@12
    extern PathSkipRootA alias _PathSkipRootA@4
    extern PathSkipRootW alias _PathSkipRootW@4
    extern PathStripPathA alias _PathStripPathA@4
    extern PathStripPathW alias _PathStripPathW@4
    extern PathStripToRootA alias _PathStripToRootA@4
    extern PathStripToRootW alias _PathStripToRootW@4
    extern PathUnExpandEnvStringsA alias _PathUnExpandEnvStringsA@12
    extern PathUnExpandEnvStringsW alias _PathUnExpandEnvStringsW@12
    extern PathUndecorateA alias _PathUndecorateA@4
    extern PathUndecorateW alias _PathUndecorateW@4
    extern PathUnmakeSystemFolderA alias _PathUnmakeSystemFolderA@4
    extern PathUnmakeSystemFolderW alias _PathUnmakeSystemFolderW@4
    extern PathUnquoteSpacesA alias _PathUnquoteSpacesA@4
    extern PathUnquoteSpacesW alias _PathUnquoteSpacesW@4
    extern QISearch alias _QISearch@16
    extern SHAllocShared alias _SHAllocShared@12
    extern SHAnsiToAnsi alias _SHAnsiToAnsi@12
    extern SHAnsiToUnicode alias _SHAnsiToUnicode@12
    extern SHAutoComplete alias _SHAutoComplete@8
    extern SHCopyKeyA alias _SHCopyKeyA@16
    extern SHCopyKeyW alias _SHCopyKeyW@16
    extern SHCreateMemStream alias _SHCreateMemStream@8
    extern SHCreateShellPalette alias _SHCreateShellPalette@4
    extern SHCreateStreamOnFileA alias _SHCreateStreamOnFileA@12
    extern SHCreateStreamOnFileEx alias _SHCreateStreamOnFileEx@24
    extern SHCreateStreamOnFileW alias _SHCreateStreamOnFileW@12
    extern SHCreateThread alias _SHCreateThread@16
    extern SHCreateThreadRef alias _SHCreateThreadRef@8
    extern SHCreateThreadWithHandle alias _SHCreateThreadWithHandle@20
    extern SHDeleteEmptyKeyA alias _SHDeleteEmptyKeyA@8
    extern SHDeleteEmptyKeyW alias _SHDeleteEmptyKeyW@8
    extern SHDeleteKeyA alias _SHDeleteKeyA@8
    extern SHDeleteKeyW alias _SHDeleteKeyW@8
    extern SHDeleteValueA alias _SHDeleteValueA@12
    extern SHDeleteValueW alias _SHDeleteValueW@12
    extern SHEnumKeyExA alias _SHEnumKeyExA@16
    extern SHEnumKeyExW alias _SHEnumKeyExW@16
    extern SHEnumValueA alias _SHEnumValueA@28
    extern SHEnumValueW alias _SHEnumValueW@28
    extern SHFormatDateTimeA alias _SHFormatDateTimeA@12
    extern SHFormatDateTimeW alias _SHFormatDateTimeW@12
    extern SHFreeShared alias _SHFreeShared@8
    extern SHGetInverseCMAP alias _SHGetInverseCMAP@8
    extern SHGetThreadRef alias _SHGetThreadRef@4
    extern SHGetValueA alias _SHGetValueA@24
    extern SHGetValueW alias _SHGetValueW@24
    extern SHGetViewStatePropertyBag alias _SHGetViewStatePropertyBag@20
    extern SHIsChildOrSelf alias _SHIsChildOrSelf@8
    extern SHIsLowMemoryMachine alias _SHIsLowMemoryMachine@4
    extern SHLoadIndirectString alias _SHLoadIndirectString@16
    extern SHLockShared alias _SHLockShared@8
    extern SHMessageBoxCheckA alias _SHMessageBoxCheckA@24
    extern SHMessageBoxCheckW alias _SHMessageBoxCheckW@24
    extern SHOpenRegStream2A alias _SHOpenRegStream2A@16
    extern SHOpenRegStream2W alias _SHOpenRegStream2W@16
    extern SHOpenRegStreamA alias _SHOpenRegStreamA@16
    extern SHOpenRegStreamW alias _SHOpenRegStreamW@16
    extern SHQueryInfoKeyA alias _SHQueryInfoKeyA@20
    extern SHQueryInfoKeyW alias _SHQueryInfoKeyW@20
    extern SHQueryValueExA alias _SHQueryValueExA@24
    extern SHQueryValueExW alias _SHQueryValueExW@24
    extern SHRegCloseUSKey alias _SHRegCloseUSKey@4
    extern SHRegCreateUSKeyA alias _SHRegCreateUSKeyA@20
    extern SHRegCreateUSKeyW alias _SHRegCreateUSKeyW@20
    extern SHRegDeleteEmptyUSKeyA alias _SHRegDeleteEmptyUSKeyA@12
    extern SHRegDeleteEmptyUSKeyW alias _SHRegDeleteEmptyUSKeyW@12
    extern SHRegDeleteUSValueA alias _SHRegDeleteUSValueA@12
    extern SHRegDeleteUSValueW alias _SHRegDeleteUSValueW@12
    extern SHRegDuplicateHKey alias _SHRegDuplicateHKey@4
    extern SHRegEnumUSKeyA alias _SHRegEnumUSKeyA@20
    extern SHRegEnumUSKeyW alias _SHRegEnumUSKeyW@20
    extern SHRegEnumUSValueA alias _SHRegEnumUSValueA@32
    extern SHRegEnumUSValueW alias _SHRegEnumUSValueW@32
    extern SHRegGetBoolUSValueA alias _SHRegGetBoolUSValueA@16
    extern SHRegGetBoolUSValueW alias _SHRegGetBoolUSValueW@16
    extern SHRegGetIntW alias _SHRegGetIntW@12
    extern SHRegGetPathA alias _SHRegGetPathA@20
    extern SHRegGetPathW alias _SHRegGetPathW@20
    extern SHRegGetUSValueA alias _SHRegGetUSValueA@32
    extern SHRegGetUSValueW alias _SHRegGetUSValueW@32
    extern SHRegGetValueA alias _SHRegGetValueA@28
    extern SHRegGetValueW alias _SHRegGetValueW@28
    extern SHRegOpenUSKeyA alias _SHRegOpenUSKeyA@20
    extern SHRegOpenUSKeyW alias _SHRegOpenUSKeyW@20
    extern SHRegQueryInfoUSKeyA alias _SHRegQueryInfoUSKeyA@24
    extern SHRegQueryInfoUSKeyW alias _SHRegQueryInfoUSKeyW@24
    extern SHRegQueryUSValueA alias _SHRegQueryUSValueA@32
    extern SHRegQueryUSValueW alias _SHRegQueryUSValueW@32
    extern SHRegSetPathA alias _SHRegSetPathA@20
    extern SHRegSetPathW alias _SHRegSetPathW@20
    extern SHRegSetUSValueA alias _SHRegSetUSValueA@24
    extern SHRegSetUSValueW alias _SHRegSetUSValueW@24
    extern SHRegWriteUSValueA alias _SHRegWriteUSValueA@24
    extern SHRegWriteUSValueW alias _SHRegWriteUSValueW@24
    extern SHRegisterValidateTemplate alias _SHRegisterValidateTemplate@8
    extern SHReleaseThreadRef alias _SHReleaseThreadRef@0
    extern SHRunIndirectRegClientCommand alias _SHRunIndirectRegClientCommand@8
    extern SHSendMessageBroadcastA alias _SHSendMessageBroadcastA@12
    extern SHSendMessageBroadcastW alias _SHSendMessageBroadcastW@12
    extern SHSetThreadRef alias _SHSetThreadRef@4
    extern SHSetValueA alias _SHSetValueA@24
    extern SHSetValueW alias _SHSetValueW@24
    extern SHSkipJunction alias _SHSkipJunction@8
    extern SHStrDupA alias _SHStrDupA@8
    extern SHStrDupW alias _SHStrDupW@8
    extern SHStripMneumonicA alias _SHStripMneumonicA@4
    extern SHStripMneumonicW alias _SHStripMneumonicW@4
    extern SHUnicodeToAnsi alias _SHUnicodeToAnsi@12
    extern SHUnicodeToUnicode alias _SHUnicodeToUnicode@12
    extern SHUnlockShared alias _SHUnlockShared@4
    extern StrCSpnA alias _StrCSpnA@8
    extern StrCSpnIA alias _StrCSpnIA@8
    extern StrCSpnIW alias _StrCSpnIW@8
    extern StrCSpnW alias _StrCSpnW@8
    extern StrCatBuffA alias _StrCatBuffA@12
    extern StrCatBuffW alias _StrCatBuffW@12
    extern StrCatChainW alias _StrCatChainW@16
    extern StrChrA alias _StrChrA@8
    extern StrChrIA alias _StrChrIA@8
    extern StrChrIW alias _StrChrIW@8
    extern StrChrNIW alias _StrChrNIW@12
    extern StrChrNW alias _StrChrNW@12
    extern StrChrW alias _StrChrW@8
    extern StrCmpCA alias _StrCmpCA@8
    extern StrCmpCW alias _StrCmpCW@8
    extern StrCmpICA alias _StrCmpICA@8
    extern StrCmpICW alias _StrCmpICW@8
    extern StrCmpIW alias _StrCmpIW@8
    extern StrCmpLogicalW alias _StrCmpLogicalW@8
    extern StrCmpNA alias _StrCmpNA@12
    extern StrCmpNCA alias _StrCmpNCA@12
    extern StrCmpNCW alias _StrCmpNCW@12
    extern StrCmpNIA alias _StrCmpNIA@12
    extern StrCmpNICA alias _StrCmpNICA@12
    extern StrCmpNICW alias _StrCmpNICW@12
    extern StrCmpNIW alias _StrCmpNIW@12
    extern StrCmpNW alias _StrCmpNW@12
    extern StrCmpW alias _StrCmpW@8
    extern StrCpyNW alias _StrCpyNW@12
    extern StrCpyW alias _StrCpyW@8
    extern StrDupA alias _StrDupA@4
    extern StrDupW alias _StrDupW@4
    extern StrFormatByteSizeA alias _StrFormatByteSizeW@16
    extern StrFormatByteSize64A alias _StrFormatByteSize64A@16
    extern StrFormatByteSizeEx alias _StrFormatByteSizeEx@16
    extern StrFormatByteSizeW alias _StrFormatByteSizeW@16
    extern StrFormatKBSizeA alias _StrFormatKBSizeA@16
    extern StrFormatKBSizeW alias _StrFormatKBSizeW@16
    extern StrFromTimeIntervalA alias _StrFromTimeIntervalA@16
    extern StrFromTimeIntervalW alias _StrFromTimeIntervalW@16
    extern StrIsIntlEqualA alias _StrIsIntlEqualA@16
    extern StrIsIntlEqualW alias _StrIsIntlEqualW@16
    extern StrNCatA alias _StrNCatA@12
    extern StrNCatW alias _StrNCatW@12
    extern StrPBrkA alias _StrPBrkA@8
    extern StrPBrkW alias _StrPBrkW@8
    extern StrRChrA alias _StrRChrA@12
    extern StrRChrIA alias _StrRChrIA@12
    extern StrRChrIW alias _StrRChrIW@12
    extern StrRChrW alias _StrRChrW@12
    extern StrRStrIA alias _StrRStrIA@12
    extern StrRStrIW alias _StrRStrIW@12
    extern StrRetToBSTR alias _StrRetToBSTR@12
    extern StrRetToBufA alias _StrRetToBufA@16
    extern StrRetToBufW alias _StrRetToBufW@16
    extern StrRetToStrA alias _StrRetToStrA@12
    extern StrRetToStrW alias _StrRetToStrW@12
    extern StrSpnA alias _StrSpnA@8
    extern StrSpnW alias _StrSpnW@8
    extern StrStrA alias _StrStrA@8
    extern StrStrIA alias _StrStrIA@8
    extern StrStrIW alias _StrStrIW@8
    extern StrStrNIW alias _StrStrNIW@12
    extern StrStrNW alias _StrStrNW@12
    extern StrStrW alias _StrStrW@8
    extern StrToInt64ExA alias _StrToInt64ExA@12
    extern StrToInt64ExW alias _StrToInt64ExW@12
    extern StrToIntA alias _StrToIntA@4
    extern StrToIntExA alias _StrToIntExA@12
    extern StrToIntExW alias _StrToIntExW@12
    extern StrToIntW alias _StrToIntW@4
    extern StrTrimA alias _StrTrimA@8
    extern StrTrimW alias _StrTrimW@8
    extern UrlApplySchemeA alias _UrlApplySchemeA@16
    extern UrlApplySchemeW alias _UrlApplySchemeW@16
    extern UrlCanonicalizeA alias _UrlCanonicalizeA@16
    extern UrlCanonicalizeW alias _UrlCanonicalizeW@16
    extern UrlCombineA alias _UrlCombineA@20
    extern UrlCombineW alias _UrlCombineW@20
    extern UrlCompareA alias _UrlCompareA@12
    extern UrlCompareW alias _UrlCompareW@12
    extern UrlCreateFromPathA alias _UrlCreateFromPathA@16
    extern UrlCreateFromPathW alias _UrlCreateFromPathW@16
    extern UrlEscapeA alias _UrlEscapeA@16
    extern UrlEscapeW alias _UrlEscapeW@16
    extern UrlFixupW alias _UrlFixupW@12
    extern UrlGetLocationA alias _UrlGetLocationA@4
    extern UrlGetLocationW alias _UrlGetLocationW@4
    extern UrlGetPartA alias _UrlGetPartA@20
    extern UrlGetPartW alias _UrlGetPartW@20
    extern UrlHashA alias _UrlHashA@12
    extern UrlHashW alias _UrlHashW@12
    extern UrlIsA alias _UrlIsA@8
    extern UrlIsNoHistoryA alias _UrlIsNoHistoryA@4
    extern UrlIsNoHistoryW alias _UrlIsNoHistoryW@4
    extern UrlIsOpaqueA alias _UrlIsOpaqueA@4
    extern UrlIsOpaqueW alias _UrlIsOpaqueW@4
    extern UrlIsW alias _UrlIsW@8
    extern UrlUnescapeA alias _UrlUnescapeA@16
    extern UrlUnescapeW alias _UrlUnescapeW@16
    extern WhichPlatform alias _WhichPlatform@0
    extern wvnsprintfA alias _wvnsprintfA@16
    extern wvnsprintfW alias _wvnsprintfW@16

    #if NTDDI_VERSION >= NTDDI_WIN2K
        #if NTDDI_VERSION <= NTDDI_WIN7
            extern DllGetClassObject alias _DllGetClassObject@12
           extern MLFreeLibrary alias _MLFreeLibrary@4
            extern SHDeleteOrphanKeyA alias _SHDeleteOrphanKeyA@8
            extern SHDeleteOrphanKeyW alias _SHDeleteOrphanKeyW@8
            api SHDeleteOrphanKey
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WINXP
        extern GUIDFromStringA alias _GUIDFromStringA@8
        extern GUIDFromStringW alias _GUIDFromStringW@8
        api GUIDFromString
    #endif

    #if NTDDI_VERSION >= NTDDI_WIN8
        extern IUnknown_Exec alias _IUnknown_Exec@24
        extern IUnknown_QueryStatus alias _IUnknown_QueryStatus@20
        extern PathFileExistsAndAttributesA alias _PathFileExistsAndAttributesA@8
        extern PathFileExistsAndAttributesW alias _PathFileExistsAndAttributesW@8
        extern SHRegGetBoolValueFromHKCUHKLM alias _SHRegGetBoolValueFromHKCUHKLM@12
        extern SHRegGetValueFromHKCUHKLM alias _SHRegGetValueFromHKCUHKLM@24
        extern SHUnicodeToAnsiCP alias _SHUnicodeToAnsiCP@16
        api PathFileExistsAndAttributes
    #endif

    #if NTDDI_VERSION >= NTDDI_WIN10
        extern SHCreateWorkerWindowA alias _SHCreateWorkerWindowA@24
        extern SHCreateWorkerWindowW alias _SHCreateWorkerWindowW@24
        extern SHPinDllOfCLSID alias _SHPinDllOfCLSID@4
        api SHCreateWorkerWindow
    #endif
#endif

#ifdef APP_UNICODE
    define AssocQueryKey AssocQueryKeyW
    define AssocQueryString AssocQueryStringW
    define AssocQueryStringByKey AssocQueryStringByKeyW
    define ChrCmpI ChrCmpIW
    define GetAcceptLanguages GetAcceptLanguagesW
    define GUIDFromString GUIDFromStringW
    define IntlStrEqWorker IntlStrEqWorkerW
    define IsCharSpace IsCharSpaceW
    define MLLoadLibrary MLLoadLibraryW
    define ParseURL ParseURLW
    define PathAddBackslash PathAddBackslashW
    define PathAddExtension PathAddExtensionW
    define PathAppend PathAppendW
    define PathBuildRoot PathBuildRootW
    define PathCanonicalize PathCanonicalizeW
    define PathCombine PathCombineW
    define PathCommonPrefix PathCommonPrefixW
    define PathCompactPath PathCompactPathW
    define PathCompactPathEx PathCompactPathExW
    define PathCreateFromUrl PathCreateFromUrlW
    define PathFileExists PathFileExistsW
    define PathFileExistsAndAttributes PathFileExistsAndAttributesW
    define PathFindExtension PathFindExtensionW
    define PathFindFileName PathFindFileNameW
    define PathFindNextComponent PathFindNextComponentW
    define PathFindOnPath PathFindOnPathW
    define PathFindSuffixArray PathFindSuffixArrayW
    define PathGetArgs PathGetArgsW
    define PathGetCharType PathGetCharTypeW
    define PathGetDriveNumber PathGetDriveNumberW
    define PathIsContentType PathIsContentTypeW
    define PathIsDirectory PathIsDirectoryW
    define PathIsDirectoryEmpty PathIsDirectoryEmptyW
    define PathIsFileSpec PathIsFileSpecW
    define PathIsLFNFileSpec PathIsLFNFileSpecW
    define PathIsNetworkPath PathIsNetworkPathW
    define PathIsPrefix PathIsPrefixW
    define PathIsRelative PathIsRelativeW
    define PathIsRoot PathIsRootW
    define PathIsSameRoot PathIsSameRootW
    define PathIsSystemFolder PathIsSystemFolderW
    define PathIsUNC PathIsUNCW
    define PathIsUNCServerShare PathIsUNCServerShareW
    define PathIsUNCServer PathIsUNCServerW
    define PathIsURL PathIsURLW
    define PathMakePretty PathMakePrettyW
    define PathMakeSystemFolder PathMakeSystemFolderW
    define PathMatchSpec PathMatchSpecW
    define PathMatchSpecEx PathMatchSpecExW
    define PathParseIconLocation PathParseIconLocationW
    define PathQuoteSpaces PathQuoteSpacesW
    define PathRelativePathTo PathRelativePathToW
    define PathRemoveArgs PathRemoveArgsW
    define PathRemoveBackslash PathRemoveBackslashW
    define PathRemoveBlanks PathRemoveBlanksW
    define PathRemoveExtension PathRemoveExtensionW
    define PathRemoveFileSpec PathRemoveFileSpecW
    define PathRenameExtension PathRenameExtensionW
    define PathSearchAndQualify PathSearchAndQualifyW
    define PathSetDlgItemPath PathSetDlgItemPathW
    define PathSkipRoot PathSkipRootW
    define PathStripPath PathStripPathW
    define PathStripToRoot PathStripToRootW
    define PathUnExpandEnvStrings PathUnExpandEnvStringsW
    define PathUndecorate PathUndecorateW
    define PathUnmakeSystemFolder PathUnmakeSystemFolderW
    define PathUnquoteSpaces PathUnquoteSpacesW
    define SHCopyKey SHCopyKeyW
    define SHCreateStreamOnFile SHCreateStreamOnFileW
    define SHCreateWorkerWindow SHCreateWorkerWindowW
    define SHDeleteEmptyKey SHDeleteEmptyKeyW
    define SHDeleteKey SHDeleteKeyW
    define SHDeleteOrphanKey SHDeleteOrphanKeyW
    define SHDeleteValue SHDeleteValueW
    define SHEnumKeyEx SHEnumKeyExW
    define SHEnumValue SHEnumValueW
    define SHFormatDateTime SHFormatDateTimeW
    define SHGetValue SHGetValueW
    define SHMessageBoxCheck SHMessageBoxCheckW
    define SHOpenRegStream2 SHOpenRegStream2W
    define SHOpenRegStream SHOpenRegStreamW
    define SHQueryInfoKey SHQueryInfoKeyW
    define SHQueryValueEx SHQueryValueExW
    define SHRegCreateUSKey SHRegCreateUSKeyW
    define SHRegDeleteEmptyUSKey SHRegDeleteEmptyUSKeyW
    define SHRegDeleteUSValue SHRegDeleteUSValueW
    define SHRegEnumUSKey SHRegEnumUSKeyW
    define SHRegEnumUSValue SHRegEnumUSValueW
    define SHRegGetBoolUSValue SHRegGetBoolUSValueW
    define SHRegGetPath SHRegGetPathW
    define SHRegGetUSValue SHRegGetUSValueW
    define SHRegGetValue SHRegGetValueW
    define SHRegOpenUSKey SHRegOpenUSKeyW
    define SHRegQueryInfoUSKey SHRegQueryInfoUSKeyW
    define SHRegQueryUSValue SHRegQueryUSValueW
    define SHRegSetPath SHRegSetPathW
    define SHRegSetUSValue SHRegSetUSValueW
    define SHRegWriteUSValue SHRegWriteUSValueW
    define SHSendMessageBroadcast SHSendMessageBroadcastW
    define SHSetValue SHSetValueW
    define SHStrDup SHStrDupW
    define SHStripMneumonic SHStripMneumonicW
    define StrCSpn StrCSpnW
    define StrCSpnI StrCSpnIW
    define StrCatBuff StrCatBuffW
    define StrCat StrCatW
    define StrChr StrChrW
    define StrChrI StrChrIW
    define StrCmpC StrCmpCW
    define StrCmpIC StrCmpICW
    define StrCmpNC StrCmpNCW
    define StrCmpNI StrCmpNIW
    define StrCmpNIC StrCmpNICW
    define StrCmpN StrCmpNW
    define StrDup StrDupW
    define StrFormatByteSize StrFormatByteSizeW
    define StrFormatKBSize StrFormatKBSizeW
    define StrFromTimeInterval StrFromTimeIntervalW
    define StrIsIntlEqual StrIsIntlEqualW
    define StrNCat StrNCatW
    define StrPBrk StrPBrkW
    define StrRChrI StrRChrIW
    define StrRChr StrRChrW
    define StrRStrI StrRStrIW
    define StrRetToBuf StrRetToBufW
    define StrRetToStr StrRetToStrW
    define StrSpn StrSpnW
    define StrStr StrStrW
    define StrStrI StrStrIW
    define StrToInt64Ex StrToInt64ExW
    define StrToIntEx StrToIntExW
    define StrToInt StrToIntW
    define StrTrim StrTrimW
    define UrlApplyScheme UrlApplySchemeW
    define UrlCanonicalize UrlCanonicalizeW
    define UrlCombine UrlCombineW
    define UrlCompare UrlCompareW
    define UrlCreateFromPath UrlCreateFromPathW
    define UrlEscape UrlEscapeW
    define UrlGetLocation UrlGetLocationW
    define UrlGetPart UrlGetPartW
    define UrlHash UrlHashW
    define UrlIsNoHistory UrlIsNoHistoryW
    define UrlIsOpaque UrlIsOpaqueW
    define UrlIs UrlIsW
    define UrlUnescape UrlUnescapeW
    define wnsprintf wnsprintfW
    define wvnsprintf wvnsprintfW
#else
    define AssocQueryKey AssocQueryKeyA
    define AssocQueryString AssocQueryStringA
    define AssocQueryStringByKey AssocQueryStringByKeyA
    define ChrCmpI ChrCmpIA
    define GetAcceptLanguages GetAcceptLanguagesA
    define GUIDFromString GUIDFromStringA
    define IntlStrEqWorker IntlStrEqWorkerA
    define IsCharSpace IsCharSpaceA
    define MLLoadLibrary MLLoadLibraryA
    define ParseURL ParseURLA
    define PathAddBackslash PathAddBackslashA
    define PathAddExtension PathAddExtensionA
    define PathAppend PathAppendA
    define PathBuildRoot PathBuildRootA
    define PathCanonicalize PathCanonicalizeA
    define PathCombine PathCombineA
    define PathCommonPrefix PathCommonPrefixA
    define PathCompactPath PathCompactPathA
    define PathCompactPathEx PathCompactPathExA
    define PathCreateFromUrl PathCreateFromUrlA
    define PathFileExists PathFileExistsA
    define PathFileExistsAndAttributes PathFileExistsAndAttributesA
    define PathFindExtension PathFindExtensionA
    define PathFindFileName PathFindFileNameA
    define PathFindNextComponent PathFindNextComponentA
    define PathFindOnPath PathFindOnPathA
    define PathFindSuffixArray PathFindSuffixArrayA
    define PathGetArgs PathGetArgsA
    define PathGetCharType PathGetCharTypeA
    define PathGetDriveNumber PathGetDriveNumberA
    define PathIsContentType PathIsContentTypeA
    define PathIsDirectory PathIsDirectoryA
    define PathIsDirectoryEmpty PathIsDirectoryEmptyA
    define PathIsFileSpec PathIsFileSpecA
    define PathIsLFNFileSpec PathIsLFNFileSpecA
    define PathIsNetworkPath PathIsNetworkPathA
    define PathIsPrefix PathIsPrefixA
    define PathIsRelative PathIsRelativeA
    define PathIsRoot PathIsRootA
    define PathIsSameRoot PathIsSameRootA
    define PathIsSystemFolder PathIsSystemFolderA
    define PathIsUNC PathIsUNCA
    define PathIsUNCServerShare PathIsUNCServerShareA
    define PathIsUNCServer PathIsUNCServerA
    define PathIsURL PathIsURLA
    define PathMakePretty PathMakePrettyA
    define PathMakeSystemFolder PathMakeSystemFolderA
    define PathMatchSpec PathMatchSpecA
    define PathMatchSpecEx PathMatchSpecExA
    define PathParseIconLocation PathParseIconLocationA
    define PathQuoteSpaces PathQuoteSpacesA
    define PathRelativePathTo PathRelativePathToA
    define PathRemoveArgs PathRemoveArgsA
    define PathRemoveBackslash PathRemoveBackslashA
    define PathRemoveBlanks PathRemoveBlanksA
    define PathRemoveExtension PathRemoveExtensionA
    define PathRemoveFileSpec PathRemoveFileSpecA
    define PathRenameExtension PathRenameExtensionA
    define PathSearchAndQualify PathSearchAndQualifyA
    define PathSetDlgItemPath PathSetDlgItemPathA
    define PathSkipRoot PathSkipRootA
    define PathStripPath PathStripPathA
    define PathStripToRoot PathStripToRootA
    define PathUnExpandEnvStrings PathUnExpandEnvStringsA
    define PathUndecorate PathUndecorateA
    define PathUnmakeSystemFolder PathUnmakeSystemFolderA
    define PathUnquoteSpaces PathUnquoteSpacesA
    define SHCopyKey SHCopyKeyA
    define SHCreateStreamOnFile SHCreateStreamOnFileA
    define SHCreateWorkerWindow SHCreateWorkerWindowA
    define SHDeleteEmptyKey SHDeleteEmptyKeyA
    define SHDeleteKey SHDeleteKeyA
    define SHDeleteOrphanKey SHDeleteOrphanKeyA
    define SHDeleteValue SHDeleteValueA
    define SHEnumKeyEx SHEnumKeyExA
    define SHEnumValue SHEnumValueA
    define SHFormatDateTime SHFormatDateTimeA
    define SHGetValue SHGetValueA
    define SHMessageBoxCheck SHMessageBoxCheckA
    define SHOpenRegStream2 SHOpenRegStream2A
    define SHOpenRegStream SHOpenRegStreamA
    define SHQueryInfoKey SHQueryInfoKeyA
    define SHQueryValueEx SHQueryValueExA
    define SHRegCreateUSKey SHRegCreateUSKeyA
    define SHRegDeleteEmptyUSKey SHRegDeleteEmptyUSKeyA
    define SHRegDeleteUSValue SHRegDeleteUSValueA
    define SHRegEnumUSKey SHRegEnumUSKeyA
    define SHRegEnumUSValue SHRegEnumUSValueA
    define SHRegGetBoolUSValue SHRegGetBoolUSValueA
    define SHRegGetPath SHRegGetPathA
    define SHRegGetUSValue SHRegGetUSValueA
    define SHRegGetValue SHRegGetValueA
    define SHRegOpenUSKey SHRegOpenUSKeyA
    define SHRegQueryInfoUSKey SHRegQueryInfoUSKeyA
    define SHRegQueryUSValue SHRegQueryUSValueA
    define SHRegSetPath SHRegSetPathA
    define SHRegSetUSValue SHRegSetUSValueA
    define SHRegWriteUSValue SHRegWriteUSValueA
    define SHSendMessageBroadcast SHSendMessageBroadcastA
    define SHSetValue SHSetValueA
    define SHStrDup SHStrDupA
    define SHStripMneumonic SHStripMneumonicA
    define StrCSpn StrCSpnA
    define StrCSpnI StrCSpnIA
    define StrCatBuff StrCatBuffA
    define StrCat StrCatA
    define StrChr StrChrA
    define StrChrI StrChrIA
    define StrCmpC StrCmpCA
    define StrCmpIC StrCmpICA
    define StrCmpNC StrCmpNCA
    define StrCmpNI StrCmpNIA
    define StrCmpNIC StrCmpNICA
    define StrCmpN StrCmpNA
    define StrDup StrDupA
    define StrFormatByteSize StrFormatByteSizeA
    define StrFormatKBSize StrFormatKBSizeA
    define StrFromTimeInterval StrFromTimeIntervalA
    define StrIsIntlEqual StrIsIntlEqualA
    define StrNCat StrNCatA
    define StrPBrk StrPBrkA
    define StrRChrI StrRChrIA
    define StrRChr StrRChrA
    define StrRStrI StrRStrIA
    define StrRetToBuf StrRetToBufA
    define StrRetToStr StrRetToStrA
    define StrSpn StrSpnA
    define StrStr StrStrA
    define StrStrI StrStrIA
    define StrToInt64Ex StrToInt64ExA
    define StrToIntEx StrToIntExA
    define StrToInt StrToIntA
    define StrTrim StrTrimA
    define UrlApplyScheme UrlApplySchemeA
    define UrlCanonicalize UrlCanonicalizeA
    define UrlCombine UrlCombineA
    define UrlCompare UrlCompareA
    define UrlCreateFromPath UrlCreateFromPathA
    define UrlEscape UrlEscapeA
    define UrlGetLocation UrlGetLocationA
    define UrlGetPart UrlGetPartA
    define UrlHash UrlHashA
    define UrlIsNoHistory UrlIsNoHistoryA
    define UrlIsOpaque UrlIsOpaqueA
    define UrlIs UrlIsA
    define UrlUnescape UrlUnescapeA
    define wnsprintf wnsprintfA
    define wvnsprintf wvnsprintfA
#endif

define StrCatChain StrCatChainW
define StrChrN StrChrNW
define StrChrNI StrChrNIW
define StrCmp StrCmpW
define StrCmpI StrCmpIW
define StrCmpLogical StrCmpLogicalW
define StrCpy StrCpyW
define StrCpyN StrCpyNW
define StrFormatByteSize64 StrFormatByteSize64A
define StrStrN StrStrNW
define StrStrNI StrStrNIW
#ifdef APP_WIN64
    define SHRegGetInt SHRegGetIntW
    define UrlFixup UrlFixupW
#endif

#ifdef APP_UNICODE
    SZ_CONTENTTYPE_HTML equ SZ_CONTENTTYPE_HTMLW
    SZ_CONTENTTYPE_CDF  equ SZ_CONTENTTYPE_CDFW
    define PARSEDURL PARSEDURLW
#else
    SZ_CONTENTTYPE_HTML equ SZ_CONTENTTYPE_HTMLA
    SZ_CONTENTTYPE_CDF  equ SZ_CONTENTTYPE_CDFA
    define PARSEDURL PARSEDURLA
#endif

;======================= Undocumented functions (unknown arguments) =======================;
;#ifdef APP_WIN64
    ;import SHPropertyBag_ReadStrAlloc
    ;import SHPropertyBag_WriteBSTR
;#else
    ;extern SHPropertyBag_ReadStrAlloc alias _SHPropertyBag_ReadStrAlloc@??
    ;extern SHPropertyBag_WriteBSTR alias _SHPropertyBag_WriteBSTR@??
;#endif

#endif ;SHLWAPI_INC
