; ====================================================;
;                                                     ;
;     shlwapi.inc for EC v2 Fasm visual projects      ;
;                   (version 1.0.4)                   ;
;                                                     ;
;         Copyright © Ramon Sala - 2018-2020          ;
;                                                     ;
; ====================================================;

if ~defined SHLWAPI_INC
define SHLWAPI_INC 1

SFBS_FLAGS_ROUND_TO_NEAREST_DISPLAYED_DIGIT             equ     00001H
SFBS_FLAGS_TRUNCATE_UNDISPLAYED_DECIMAL_DIGITS          equ     00002H
STIF_DEFAULT                                            equ     000000000H
STIF_SUPPORT_HEX                                        equ     000000001H

SZ_CONTENTTYPE_HTMLA                                    equ     'text/html'
SZ_CONTENTTYPE_HTMLW                                    du      'text/html',0
SZ_CONTENTTYPE_CDFA                                     equ     'application/x-cdf'
SZ_CONTENTTYPE_CDFW                                     du      'application/x-cdf', 0

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
URL_ESCAPE_URI_COMPONENT                                equ     (URL_ESCAPE_ASCII_URI_COMPONENT or URL_ESCAPE_AS_UTF8)
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
SRRF_RT_DWORD                                           equ     (SRRF_RT_REG_BINARY or SRRF_RT_REG_DWORD)
SRRF_RT_QWORD                                           equ     (SRRF_RT_REG_BINARY or SRRF_RT_REG_QWORD)
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
SHREGSET_DEFAULT                                        equ     (SHREGSET_FORCE_HKCU or SHREGSET_HKLM)

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
SHGVSPB_FOLDER                                          equ     (SHGVSPB_PERUSER or SHGVSPB_PERFOLDER)
SHGVSPB_FOLDERNODEFAULTS                                equ     (SHGVSPB_PERUSER or SHGVSPB_PERFOLDER or SHGVSPB_NOAUTODEFAULTS)
SHGVSPB_USERDEFAULTS                                    equ     (SHGVSPB_PERUSER or SHGVSPB_ALLFOLDERS)
SHGVSPB_GLOBALDEFAULTS                                  equ     (SHGVSPB_ALLUSERS or SHGVSPB_ALLFOLDERS)

FDTF_SHORTTIME                                          equ     000000001H
FDTF_SHORTDATE                                          equ     000000002H
FDTF_DEFAULT                                            equ     (FDTF_SHORTDATE or FDTF_SHORTTIME)
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
SHACF_URLALL                                            equ     (SHACF_URLHISTORY or SHACF_URLMRU)
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
    cbSize      dd   ?
    pszProtocol xptr ?
    cchProtocol dd   ?
    pszSuffix   xptr ?
    cchSuffix   dd   ?
    nScheme     dd   ?
ends

struct PARSEDURLW
    cbSize      dd   ?
    pszProtocol xptr ?
    cchProtocol dd   ?
    pszSuffix   xptr ?
    cchSuffix   dd   ?
    nScheme     dd   ?
ends

struct QITAB
    piid     xptr ?
    dwOffset dd   ?
ends

if ~defined DLLVERSIONINFO_DEF
    DLLVERSIONINFO_DEF equ 1
    struct DLLVERSIONINFO
        cbSize         dd ?
        dwMajorVersion dd ?
        dwMinorVersion dd ?
        dwBuildNumber  dd ?
        dwPlatformID   dd ?
    ends
end if

struct DLLVERSIONINFO2
    info1      DLLVERSIONINFO
    dwFlags    dd ?
    ullVersion dq ?
ends


;======================================== Functions =======================================;
if defined APP_WIN64
    extrn '__imp_AssocCreate' as AssocCreate:qword
    extrn '__imp_AssocGetPerceivedType' as AssocGetPerceivedType:qword
    extrn '__imp_AssocIsDangerous' as AssocIsDangerous:qword
    extrn '__imp_AssocQueryKeyA' as AssocQueryKeyA:qword
    extrn '__imp_AssocQueryKeyW' as AssocQueryKeyW:qword
    extrn '__imp_AssocQueryStringA' as AssocQueryStringA:qword
    extrn '__imp_AssocQueryStringW' as AssocQueryStringW:qword
    extrn '__imp_AssocQueryStringByKeyA' as AssocQueryStringByKeyA:qword
    extrn '__imp_AssocQueryStringByKeyW' as AssocQueryStringByKeyW:qword
    extrn '__imp_ChrCmpIA' as ChrCmpIA:qword
    extrn '__imp_ChrCmpIW' as ChrCmpIW:qword
    extrn '__imp_ColorAdjustLuma' as ColorAdjustLuma:qword
    extrn '__imp_ColorHLSToRGB' as ColorHLSToRGB:qword
    extrn '__imp_ColorRGBToHLS' as ColorRGBToHLS:qword
    extrn '__imp_ConnectToConnectionPoint' as ConnectToConnectionPoint:qword
    extrn '__imp_DelayLoadFailureHook' as DelayLoadFailureHook:qword
    extrn '__imp_DllInstall' as DllInstall:qword
    extrn '__imp_GetAcceptLanguagesA' as GetAcceptLanguagesA:qword
    extrn '__imp_GetAcceptLanguagesW' as GetAcceptLanguagesW:qword
    extrn '__imp_GetMenuPosFromID' as GetMenuPosFromID:qword
    extrn '__imp_HashData' as HashData:qword
    extrn '__imp_IStream_Copy' as IStream_Copy:qword
    extrn '__imp_IStream_Read' as IStream_Read:qword
    extrn '__imp_IStream_ReadPidl' as IStream_ReadPidl:qword
    extrn '__imp_IStream_ReadStr' as IStream_ReadStr:qword
    extrn '__imp_IStream_Reset' as IStream_Reset:qword
    extrn '__imp_IStream_Size' as IStream_Size:qword
    extrn '__imp_IStream_Write' as IStream_Write:qword
    extrn '__imp_IStream_WritePidl' as IStream_WritePidl:qword
    extrn '__imp_IStream_WriteStr' as IStream_WriteStr:qword
    extrn '__imp_IUnknown_AtomicRelease' as IUnknown_AtomicRelease:qword
    extrn '__imp_IUnknown_GetSite' as IUnknown_GetSite:qword
    extrn '__imp_IUnknown_GetWindow' as IUnknown_GetWindow:qword
    extrn '__imp_IUnknown_QueryService' as IUnknown_QueryService:qword
    extrn '__imp_IUnknown_Set' as IUnknown_Set:qword
    extrn '__imp_IUnknown_SetSite' as IUnknown_SetSite:qword
    extrn '__imp_IntlStrEqWorkerA' as IntlStrEqWorkerA:qword
    extrn '__imp_IntlStrEqWorkerW' as IntlStrEqWorkerW:qword
    extrn '__imp_IsCharSpaceA' as IsCharSpaceA:qword
    extrn '__imp_IsCharSpaceW' as IsCharSpaceW:qword
    extrn '__imp_IsInternetESCEnabled' as IsInternetESCEnabled:qword
    extrn '__imp_IsOS' as IsOS:qword
    extrn '__imp_MLLoadLibraryA' as MLLoadLibraryA:qword
    extrn '__imp_MLLoadLibraryW' as MLLoadLibraryW:qword
    extrn '__imp_ParseURLA' as ParseURLA:qword
    extrn '__imp_ParseURLW' as ParseURLW:qword
    extrn '__imp_PathAddBackslashA' as PathAddBackslashA:qword
    extrn '__imp_PathAddBackslashW' as PathAddBackslashW:qword
    extrn '__imp_PathAddExtensionA' as PathAddExtensionA:qword
    extrn '__imp_PathAddExtensionW' as PathAddExtensionW:qword
    extrn '__imp_PathAppendA' as PathAppendA:qword
    extrn '__imp_PathAppendW' as PathAppendW:qword
    extrn '__imp_PathBuildRootA' as PathBuildRootA:qword
    extrn '__imp_PathBuildRootW' as PathBuildRootW:qword
    extrn '__imp_PathCanonicalizeA' as PathCanonicalizeA:qword
    extrn '__imp_PathCanonicalizeW' as PathCanonicalizeW:qword
    extrn '__imp_PathCombineA' as PathCombineA:qword
    extrn '__imp_PathCombineW' as PathCombineW:qword
    extrn '__imp_PathCommonPrefixA' as PathCommonPrefixA:qword
    extrn '__imp_PathCommonPrefixW' as PathCommonPrefixW:qword
    extrn '__imp_PathCompactPathA' as PathCompactPathA:qword
    extrn '__imp_PathCompactPathExA' as PathCompactPathExA:qword
    extrn '__imp_PathCompactPathExW' as PathCompactPathExW:qword
    extrn '__imp_PathCompactPathW' as PathCompactPathW:qword
    extrn '__imp_PathCreateFromUrlA' as PathCreateFromUrlA:qword
    extrn '__imp_PathCreateFromUrlAlloc' as PathCreateFromUrlAlloc:qword
    extrn '__imp_PathCreateFromUrlW' as PathCreateFromUrlW:qword
    extrn '__imp_PathFileExistsA' as PathFileExistsA:qword
    extrn '__imp_PathFileExistsW' as PathFileExistsW:qword
    extrn '__imp_PathFindExtensionA' as PathFindExtensionA:qword
    extrn '__imp_PathFindExtensionW' as PathFindExtensionW:qword
    extrn '__imp_PathFindFileNameA' as PathFindFileNameA:qword
    extrn '__imp_PathFindFileNameW' as PathFindFileNameW:qword
    extrn '__imp_PathFindNextComponentA' as PathFindNextComponentA:qword
    extrn '__imp_PathFindNextComponentW' as PathFindNextComponentW:qword
    extrn '__imp_PathFindOnPathA' as PathFindOnPathA:qword
    extrn '__imp_PathFindOnPathW' as PathFindOnPathW:qword
    extrn '__imp_PathFindSuffixArrayA' as PathFindSuffixArrayA:qword
    extrn '__imp_PathFindSuffixArrayW' as PathFindSuffixArrayW:qword
    extrn '__imp_PathGetArgsA' as PathGetArgsA:qword
    extrn '__imp_PathGetArgsW' as PathGetArgsW:qword
    extrn '__imp_PathGetCharTypeA' as PathGetCharTypeA:qword
    extrn '__imp_PathGetCharTypeW' as PathGetCharTypeW:qword
    extrn '__imp_PathGetDriveNumberA' as PathGetDriveNumberA:qword
    extrn '__imp_PathGetDriveNumberW' as PathGetDriveNumberW:qword
    extrn '__imp_PathIsContentTypeA' as PathIsContentTypeA:qword
    extrn '__imp_PathIsContentTypeW' as PathIsContentTypeW:qword
    extrn '__imp_PathIsDirectoryA' as PathIsDirectoryA:qword
    extrn '__imp_PathIsDirectoryEmptyA' as PathIsDirectoryEmptyA:qword
    extrn '__imp_PathIsDirectoryEmptyW' as PathIsDirectoryEmptyW:qword
    extrn '__imp_PathIsDirectoryW' as PathIsDirectoryW:qword
    extrn '__imp_PathIsFileSpecA' as PathIsFileSpecA:qword
    extrn '__imp_PathIsFileSpecW' as PathIsFileSpecW:qword
    extrn '__imp_PathIsLFNFileSpecA' as PathIsLFNFileSpecA:qword
    extrn '__imp_PathIsLFNFileSpecW' as PathIsLFNFileSpecW:qword
    extrn '__imp_PathIsNetworkPathA' as PathIsNetworkPathA:qword
    extrn '__imp_PathIsNetworkPathW' as PathIsNetworkPathW:qword
    extrn '__imp_PathIsPrefixA' as PathIsPrefixA:qword
    extrn '__imp_PathIsPrefixW' as PathIsPrefixW:qword
    extrn '__imp_PathIsRelativeA' as PathIsRelativeA:qword
    extrn '__imp_PathIsRelativeW' as PathIsRelativeW:qword
    extrn '__imp_PathIsRootA' as PathIsRootA:qword
    extrn '__imp_PathIsRootW' as PathIsRootW:qword
    extrn '__imp_PathIsSameRootA' as PathIsSameRootA:qword
    extrn '__imp_PathIsSameRootW' as PathIsSameRootW:qword
    extrn '__imp_PathIsSystemFolderA' as PathIsSystemFolderA:qword
    extrn '__imp_PathIsSystemFolderW' as PathIsSystemFolderW:qword
    extrn '__imp_PathIsUNCA' as PathIsUNCA:qword
    extrn '__imp_PathIsUNCServerA' as PathIsUNCServerA:qword
    extrn '__imp_PathIsUNCServerShareA' as PathIsUNCServerShareA:qword
    extrn '__imp_PathIsUNCServerShareW' as PathIsUNCServerShareW:qword
    extrn '__imp_PathIsUNCServerW' as PathIsUNCServerW:qword
    extrn '__imp_PathIsUNCW' as PathIsUNCW:qword
    extrn '__imp_PathIsURLA' as PathIsURLA:qword
    extrn '__imp_PathIsURLW' as PathIsURLW:qword
    extrn '__imp_PathMakePrettyA' as PathMakePrettyA:qword
    extrn '__imp_PathMakePrettyW' as PathMakePrettyW:qword
    extrn '__imp_PathMakeSystemFolderA' as PathMakeSystemFolderA:qword
    extrn '__imp_PathMakeSystemFolderW' as PathMakeSystemFolderW:qword
    extrn '__imp_PathMatchSpecA' as PathMatchSpecA:qword
    extrn '__imp_PathMatchSpecExA' as PathMatchSpecExA:qword
    extrn '__imp_PathMatchSpecExW' as PathMatchSpecExW:qword
    extrn '__imp_PathMatchSpecW' as PathMatchSpecW:qword
    extrn '__imp_PathParseIconLocationA' as PathParseIconLocationA:qword
    extrn '__imp_PathParseIconLocationW' as PathParseIconLocationW:qword
    extrn '__imp_PathQuoteSpacesA' as PathQuoteSpacesA:qword
    extrn '__imp_PathQuoteSpacesW' as PathQuoteSpacesW:qword
    extrn '__imp_PathRelativePathToA' as PathRelativePathToA:qword
    extrn '__imp_PathRelativePathToW' as PathRelativePathToW:qword
    extrn '__imp_PathRemoveArgsA' as PathRemoveArgsA:qword
    extrn '__imp_PathRemoveArgsW' as PathRemoveArgsW:qword
    extrn '__imp_PathRemoveBackslashA' as PathRemoveBackslashA:qword
    extrn '__imp_PathRemoveBackslashW' as PathRemoveBackslashW:qword
    extrn '__imp_PathRemoveBlanksA' as PathRemoveBlanksA:qword
    extrn '__imp_PathRemoveBlanksW' as PathRemoveBlanksW:qword
    extrn '__imp_PathRemoveExtensionA' as PathRemoveExtensionA:qword
    extrn '__imp_PathRemoveExtensionW' as PathRemoveExtensionW:qword
    extrn '__imp_PathRemoveFileSpecA' as PathRemoveFileSpecA:qword
    extrn '__imp_PathRemoveFileSpecW' as PathRemoveFileSpecW:qword
    extrn '__imp_PathRenameExtensionA' as PathRenameExtensionA:qword
    extrn '__imp_PathRenameExtensionW' as PathRenameExtensionW:qword
    extrn '__imp_PathSearchAndQualifyA' as PathSearchAndQualifyA:qword
    extrn '__imp_PathSearchAndQualifyW' as PathSearchAndQualifyW:qword
    extrn '__imp_PathSetDlgItemPathA' as PathSetDlgItemPathA:qword
    extrn '__imp_PathSetDlgItemPathW' as PathSetDlgItemPathW:qword
    extrn '__imp_PathSkipRootA' as PathSkipRootA:qword
    extrn '__imp_PathSkipRootW' as PathSkipRootW:qword
    extrn '__imp_PathStripPathA' as PathStripPathA:qword
    extrn '__imp_PathStripPathW' as PathStripPathW:qword
    extrn '__imp_PathStripToRootA' as PathStripToRootA:qword
    extrn '__imp_PathStripToRootW' as PathStripToRootW:qword
    extrn '__imp_PathUnExpandEnvStringsA' as PathUnExpandEnvStringsA:qword
    extrn '__imp_PathUnExpandEnvStringsW' as PathUnExpandEnvStringsW:qword
    extrn '__imp_PathUndecorateA' as PathUndecorateA:qword
    extrn '__imp_PathUndecorateW' as PathUndecorateW:qword
    extrn '__imp_PathUnmakeSystemFolderA' as PathUnmakeSystemFolderA:qword
    extrn '__imp_PathUnmakeSystemFolderW' as PathUnmakeSystemFolderW:qword
    extrn '__imp_PathUnquoteSpacesA' as PathUnquoteSpacesA:qword
    extrn '__imp_PathUnquoteSpacesW' as PathUnquoteSpacesW:qword
    extrn '__imp_QISearch' as QISearch:qword ;Not present in MASM32 shlwapi.ib
    extrn '__imp_SHAllocShared' as SHAllocShared:qword
    extrn '__imp_SHAnsiToAnsi' as SHAnsiToAnsi:qword
    extrn '__imp_SHAnsiToUnicode' as SHAnsiToUnicode:qword
    extrn '__imp_SHAutoComplete' as SHAutoComplete:qword
    extrn '__imp_SHCopyKeyA' as SHCopyKeyA:qword
    extrn '__imp_SHCopyKeyW' as SHCopyKeyW:qword
    extrn '__imp_SHCreateMemStream' as SHCreateMemStream:qword
    extrn '__imp_SHCreateShellPalette' as SHCreateShellPalette:qword
    extrn '__imp_SHCreateStreamOnFileA' as SHCreateStreamOnFileA:qword
    extrn '__imp_SHCreateStreamOnFileEx' as SHCreateStreamOnFileEx:qword
    extrn '__imp_SHCreateStreamOnFileW' as SHCreateStreamOnFileW:qword
    extrn '__imp_SHCreateThread' as SHCreateThread:qword
    extrn '__imp_SHCreateThreadRef' as SHCreateThreadRef:qword
    extrn '__imp_SHCreateThreadWithHandle' as SHCreateThreadWithHandle:qword
    extrn '__imp_SHDeleteEmptyKeyA' as SHDeleteEmptyKeyA:qword
    extrn '__imp_SHDeleteEmptyKeyW' as SHDeleteEmptyKeyW:qword
    extrn '__imp_SHDeleteKeyA' as SHDeleteKeyA:qword
    extrn '__imp_SHDeleteKeyW' as SHDeleteKeyW:qword
    extrn '__imp_SHDeleteValueA' as SHDeleteValueA:qword
    extrn '__imp_SHDeleteValueW' as SHDeleteValueW:qword
    extrn '__imp_SHEnumKeyExA' as SHEnumKeyExA:qword
    extrn '__imp_SHEnumKeyExW' as SHEnumKeyExW:qword
    extrn '__imp_SHEnumValueA' as SHEnumValueA:qword
    extrn '__imp_SHEnumValueW' as SHEnumValueW:qword
    extrn '__imp_SHFormatDateTimeA' as SHFormatDateTimeA:qword
    extrn '__imp_SHFormatDateTimeW' as SHFormatDateTimeW:qword
    extrn '__imp_SHFreeShared' as SHFreeShared:qword
    extrn '__imp_SHGetInverseCMAP' as SHGetInverseCMAP:qword
    extrn '__imp_SHGetThreadRef' as SHGetThreadRef:qword
    extrn '__imp_SHGetValueA' as SHGetValueA:qword
    extrn '__imp_SHGetValueW' as SHGetValueW:qword
    extrn '__imp_SHGetViewStatePropertyBag' as SHGetViewStatePropertyBag:qword
    extrn '__imp_SHIsChildOrSelf' as SHIsChildOrSelf:qword
    extrn '__imp_SHIsLowMemoryMachine' as SHIsLowMemoryMachine:qword
    extrn '__imp_SHLoadIndirectString' as SHLoadIndirectString:qword
    extrn '__imp_SHLockShared' as SHLockShared:qword
    extrn '__imp_SHMessageBoxCheckA' as SHMessageBoxCheckA:qword
    extrn '__imp_SHMessageBoxCheckW' as SHMessageBoxCheckW:qword
    extrn '__imp_SHOpenRegStream2A' as SHOpenRegStream2A:qword
    extrn '__imp_SHOpenRegStream2W' as SHOpenRegStream2W:qword
    extrn '__imp_SHOpenRegStreamA' as SHOpenRegStreamA:qword
    extrn '__imp_SHOpenRegStreamW' as SHOpenRegStreamW:qword
    extrn '__imp_SHQueryInfoKeyA' as SHQueryInfoKeyA:qword
    extrn '__imp_SHQueryInfoKeyW' as SHQueryInfoKeyW:qword
    extrn '__imp_SHQueryValueExA' as SHQueryValueExA:qword
    extrn '__imp_SHQueryValueExW' as SHQueryValueExW:qword
    extrn '__imp_SHRegCloseUSKey' as SHRegCloseUSKey:qword
    extrn '__imp_SHRegCreateUSKeyA' as SHRegCreateUSKeyA:qword
    extrn '__imp_SHRegCreateUSKeyW' as SHRegCreateUSKeyW:qword
    extrn '__imp_SHRegDeleteEmptyUSKeyA' as SHRegDeleteEmptyUSKeyA:qword
    extrn '__imp_SHRegDeleteEmptyUSKeyW' as SHRegDeleteEmptyUSKeyW:qword
    extrn '__imp_SHRegDeleteUSValueA' as SHRegDeleteUSValueA:qword
    extrn '__imp_SHRegDeleteUSValueW' as SHRegDeleteUSValueW:qword
    extrn '__imp_SHRegDuplicateHKey' as SHRegDuplicateHKey:qword
    extrn '__imp_SHRegEnumUSKeyA' as SHRegEnumUSKeyA:qword
    extrn '__imp_SHRegEnumUSKeyW' as SHRegEnumUSKeyW:qword
    extrn '__imp_SHRegEnumUSValueA' as SHRegEnumUSValueA:qword
    extrn '__imp_SHRegEnumUSValueW' as SHRegEnumUSValueW:qword
    extrn '__imp_SHRegGetBoolUSValueA' as SHRegGetBoolUSValueA:qword
    extrn '__imp_SHRegGetBoolUSValueW' as SHRegGetBoolUSValueW:qword
    extrn '__imp_SHRegGetIntW' as SHRegGetIntW:qword
    extrn '__imp_SHRegGetPathA' as SHRegGetPathA:qword
    extrn '__imp_SHRegGetPathW' as SHRegGetPathW:qword
    extrn '__imp_SHRegGetUSValueA' as SHRegGetUSValueA:qword
    extrn '__imp_SHRegGetUSValueW' as SHRegGetUSValueW:qword
    extrn '__imp_SHRegGetValueA' as SHRegGetValueA:qword
    extrn '__imp_SHRegGetValueW' as SHRegGetValueW:qword
    extrn '__imp_SHRegOpenUSKeyA' as SHRegOpenUSKeyA:qword
    extrn '__imp_SHRegOpenUSKeyW' as SHRegOpenUSKeyW:qword
    extrn '__imp_SHRegQueryInfoUSKeyA' as SHRegQueryInfoUSKeyA:qword
    extrn '__imp_SHRegQueryInfoUSKeyW' as SHRegQueryInfoUSKeyW:qword
    extrn '__imp_SHRegQueryUSValueA' as SHRegQueryUSValueA:qword
    extrn '__imp_SHRegQueryUSValueW' as SHRegQueryUSValueW:qword
    extrn '__imp_SHRegSetPathA' as SHRegSetPathA:qword
    extrn '__imp_SHRegSetPathW' as SHRegSetPathW:qword
    extrn '__imp_SHRegSetUSValueA' as SHRegSetUSValueA:qword
    extrn '__imp_SHRegSetUSValueW' as SHRegSetUSValueW:qword
    extrn '__imp_SHRegWriteUSValueA' as SHRegWriteUSValueA:qword
    extrn '__imp_SHRegWriteUSValueW' as SHRegWriteUSValueW:qword
    extrn '__imp_SHRegisterValidateTemplate' as SHRegisterValidateTemplate:qword
    extrn '__imp_SHReleaseThreadRef' as SHReleaseThreadRef:qword
    extrn '__imp_SHRunIndirectRegClientCommand' as SHRunIndirectRegClientCommand:qword
    extrn '__imp_SHSendMessageBroadcastA' as SHSendMessageBroadcastA:qword
    extrn '__imp_SHSendMessageBroadcastW' as SHSendMessageBroadcastW:qword
    extrn '__imp_SHSetThreadRef' as SHSetThreadRef:qword
    extrn '__imp_SHSetValueA' as SHSetValueA:qword
    extrn '__imp_SHSetValueW' as SHSetValueW:qword
    extrn '__imp_SHSkipJunction' as SHSkipJunction:qword
    extrn '__imp_SHStrDupA' as SHStrDupA:qword
    extrn '__imp_SHStrDupW' as SHStrDupW:qword
    extrn '__imp_SHStripMneumonicA' as SHStripMneumonicA:qword
    extrn '__imp_SHStripMneumonicW' as SHStripMneumonicW:qword
    extrn '__imp_SHUnicodeToAnsi' as SHUnicodeToAnsi:qword
    extrn '__imp_SHUnicodeToUnicode' as SHUnicodeToUnicode:qword
    extrn '__imp_SHUnlockShared' as SHUnlockShared:qword
    extrn '__imp_StrCSpnA' as StrCSpnA:qword
    extrn '__imp_StrCSpnIA' as StrCSpnIA:qword
    extrn '__imp_StrCSpnIW' as StrCSpnIW:qword
    extrn '__imp_StrCSpnW' as StrCSpnW:qword
    extrn '__imp_StrCatBuffA' as StrCatBuffA:qword
    extrn '__imp_StrCatBuffW' as StrCatBuffW:qword
    extrn '__imp_StrCatChainW' as StrCatChainW:qword
    extrn '__imp_StrChrA' as StrChrA:qword
    extrn '__imp_StrChrIA' as StrChrIA:qword
    extrn '__imp_StrChrIW' as StrChrIW:qword
    extrn '__imp_StrChrNIW' as StrChrNIW:qword
    extrn '__imp_StrChrNW' as StrChrNW:qword
    extrn '__imp_StrChrW' as StrChrW:qword
    extrn '__imp_StrCmpCA' as StrCmpCA:qword
    extrn '__imp_StrCmpCW' as StrCmpCW:qword
    extrn '__imp_StrCmpICA' as StrCmpICA:qword
    extrn '__imp_StrCmpICW' as StrCmpICW:qword
    extrn '__imp_StrCmpIW' as StrCmpIW:qword
    extrn '__imp_StrCmpLogicalW' as StrCmpLogicalW:qword
    extrn '__imp_StrCmpNA' as StrCmpNA:qword
    extrn '__imp_StrCmpNCA' as StrCmpNCA:qword
    extrn '__imp_StrCmpNCW' as StrCmpNCW:qword
    extrn '__imp_StrCmpNIA' as StrCmpNIA:qword
    extrn '__imp_StrCmpNICA' as StrCmpNICA:qword
    extrn '__imp_StrCmpNICW' as StrCmpNICW:qword
    extrn '__imp_StrCmpNIW' as StrCmpNIW:qword
    extrn '__imp_StrCmpNW' as StrCmpNW:qword
    extrn '__imp_StrCmpW' as StrCmpW:qword
    extrn '__imp_StrCpyNW' as StrCpyNW:qword
    extrn '__imp_StrCpyW' as StrCpyW:qword
    extrn '__imp_StrDupA' as StrDupA:qword
    extrn '__imp_StrDupW' as StrDupW:qword
    extrn '__imp_StrFormatByteSize64A' as StrFormatByteSize64A:qword
    extrn '__imp_StrFormatByteSizeEx' as StrFormatByteSizeEx:qword
    extrn '__imp_StrFormatByteSizeW' as StrFormatByteSizeW:qword
    extrn '__imp_StrFormatKBSizeA' as StrFormatKBSizeA:qword
    extrn '__imp_StrFormatKBSizeW' as StrFormatKBSizeW:qword
    extrn '__imp_StrFromTimeIntervalA' as StrFromTimeIntervalA:qword
    extrn '__imp_StrFromTimeIntervalW' as StrFromTimeIntervalW:qword
    extrn '__imp_StrIsIntlEqualA' as StrIsIntlEqualA:qword
    extrn '__imp_StrIsIntlEqualW' as StrIsIntlEqualW:qword
    extrn '__imp_StrNCatA' as StrNCatA:qword
    extrn '__imp_StrNCatW' as StrNCatW:qword
    extrn '__imp_StrPBrkA' as StrPBrkA:qword
    extrn '__imp_StrPBrkW' as StrPBrkW:qword
    extrn '__imp_StrRChrA' as StrRChrA:qword
    extrn '__imp_StrRChrIA' as StrRChrIA:qword
    extrn '__imp_StrRChrIW' as StrRChrIW:qword
    extrn '__imp_StrRChrW' as StrRChrW:qword
    extrn '__imp_StrRStrIA' as StrRStrIA:qword
    extrn '__imp_StrRStrIW' as StrRStrIW:qword
    extrn '__imp_StrRetToBSTR' as StrRetToBSTR:qword
    extrn '__imp_StrRetToBufA' as StrRetToBufA:qword
    extrn '__imp_StrRetToBufW' as StrRetToBufW:qword
    extrn '__imp_StrRetToStrA' as StrRetToStrA:qword
    extrn '__imp_StrRetToStrW' as StrRetToStrW:qword
    extrn '__imp_StrSpnA' as StrSpnA:qword
    extrn '__imp_StrSpnW' as StrSpnW:qword
    extrn '__imp_StrStrA' as StrStrA:qword
    extrn '__imp_StrStrIA' as StrStrIA:qword
    extrn '__imp_StrStrIW' as StrStrIW:qword
    extrn '__imp_StrStrNIW' as StrStrNIW:qword
    extrn '__imp_StrStrNW' as StrStrNW:qword
    extrn '__imp_StrStrW' as StrStrW:qword
    extrn '__imp_StrToInt64ExA' as StrToInt64ExA:qword
    extrn '__imp_StrToInt64ExW' as StrToInt64ExW:qword
    extrn '__imp_StrToIntA' as StrToIntA:qword
    extrn '__imp_StrToIntExA' as StrToIntExA:qword
    extrn '__imp_StrToIntExW' as StrToIntExW:qword
    extrn '__imp_StrToIntW' as StrToIntW:qword
    extrn '__imp_StrTrimA' as StrTrimA:qword
    extrn '__imp_StrTrimW' as StrTrimW:qword
    extrn '__imp_UrlApplySchemeA' as UrlApplySchemeA:qword
    extrn '__imp_UrlApplySchemeW' as UrlApplySchemeW:qword
    extrn '__imp_UrlCanonicalizeA' as UrlCanonicalizeA:qword
    extrn '__imp_UrlCanonicalizeW' as UrlCanonicalizeW:qword
    extrn '__imp_UrlCombineA' as UrlCombineA:qword
    extrn '__imp_UrlCombineW' as UrlCombineW:qword
    extrn '__imp_UrlCompareA' as UrlCompareA:qword
    extrn '__imp_UrlCompareW' as UrlCompareW:qword
    extrn '__imp_UrlCreateFromPathA' as UrlCreateFromPathA:qword
    extrn '__imp_UrlCreateFromPathW' as UrlCreateFromPathW:qword
    extrn '__imp_UrlEscapeA' as UrlEscapeA:qword
    extrn '__imp_UrlEscapeW' as UrlEscapeW:qword
    extrn '__imp_UrlFixupW' as UrlFixupW:qword
    extrn '__imp_UrlGetLocationA' as UrlGetLocationA:qword
    extrn '__imp_UrlGetLocationW' as UrlGetLocationW:qword
    extrn '__imp_UrlGetPartA' as UrlGetPartA:qword
    extrn '__imp_UrlGetPartW' as UrlGetPartW:qword
    extrn '__imp_UrlHashA' as UrlHashA:qword
    extrn '__imp_UrlHashW' as UrlHashW:qword
    extrn '__imp_UrlIsA' as UrlIsA:qword
    extrn '__imp_UrlIsNoHistoryA' as UrlIsNoHistoryA:qword
    extrn '__imp_UrlIsNoHistoryW' as UrlIsNoHistoryW:qword
    extrn '__imp_UrlIsOpaqueA' as UrlIsOpaqueA:qword
    extrn '__imp_UrlIsOpaqueW' as UrlIsOpaqueW:qword
    extrn '__imp_UrlIsW' as UrlIsW:qword
    extrn '__imp_UrlUnescapeA' as UrlUnescapeA:qword
    extrn '__imp_UrlUnescapeW' as UrlUnescapeW:qword
    extrn '__imp_WhichPlatform' as WhichPlatform:qword
    extrn '__imp_wnsprintfA' as wnsprintfA:qword
    extrn '__imp_wvnsprintfW' as wvnsprintfW:qword

    if (NTDDI_VERSION >= NTDDI_WIN2K)
        if (NTDDI_VERSION <= NTDDI_WIN7)
            if (NTDDI_VERSION < NTDDI_WIN7)
                extrn '__imp_DllGetClassObject' as DllGetClassObject:qword
            end if
            extrn '__imp_MLFreeLibrary' as MLFreeLibrary:qword
            extrn '__imp_SHDeleteOrphanKeyA' as SHDeleteOrphanKeyA:qword
            extrn '__imp_SHDeleteOrphanKeyW' as SHDeleteOrphanKeyW:qword
            api SHDeleteOrphanKey
        end if
    end if

    if (NTDDI_VERSION >= NTDDI_WINXP)
        extrn '__imp_GUIDFromStringA' as GUIDFromStringA:qword
        extrn '__imp_GUIDFromStringW' as GUIDFromStringW:qword
        api GUIDFromString
    end if

    if (NTDDI_VERSION >= NTDDI_WIN8)
        extrn '__imp_IUnknown_Exec' as IUnknown_Exec:qword
        extrn '__imp_IUnknown_QueryStatus' as IUnknown_QueryStatus:qword
        extrn '__imp_PathFileExistsAndAttributesA' as PathFileExistsAndAttributesA:qword
        extrn '__imp_PathFileExistsAndAttributesW' as PathFileExistsAndAttributesW:qword
        extrn '__imp_SHRegGetBoolValueFromHKCUHKLM' as SHRegGetBoolValueFromHKCUHKLM:qword
        extrn '__imp_SHRegGetValueFromHKCUHKLM' as SHRegGetValueFromHKCUHKLM:qword
        extrn '__imp_SHUnicodeToAnsiCP' as SHUnicodeToAnsiCP:qword
        api PathFileExistsAndAttributes
    end if

    if (NTDDI_VERSION >= NTDDI_WIN10)
        extrn '__imp_SHCreateWorkerWindowA' as SHCreateWorkerWindowA:qword
        extrn '__imp_SHCreateWorkerWindowW' as SHCreateWorkerWindowW:qword
        extrn '__imp_SHPinDllOfCLSID' as SHPinDllOfCLSID:qword
        api SHCreateWorkerWindow
    end if

    if defined APP_UNICODE
        SZ_CONTENTTYPE_HTML equ SZ_CONTENTTYPE_HTMLW
        SZ_CONTENTTYPE_CDF  equ SZ_CONTENTTYPE_CDFW
        PARSEDURL fix PARSEDURLW
	else
        SZ_CONTENTTYPE_HTML equ SZ_CONTENTTYPE_HTMLA
        SZ_CONTENTTYPE_CDF  equ SZ_CONTENTTYPE_CDFA
        PARSEDURL fix PARSEDURLA
    end if

    api AssocQueryKey,\
        AssocQueryString,\
        AssocQueryStringByKey,\
        ChrCmpI,\
        GetAcceptLanguages,\
        IntlStrEqWorker,\
        IsCharSpace,\
        MLLoadLibrary,\
        ParseURL,\
        PathAddBackslash,\
        PathAddExtension,\
        PathAppend,\
        PathBuildRoot,\
        PathCanonicalize,\
        PathCombine,\
        PathCommonPrefix,\
        PathCompactPath,\
        PathCompactPathEx,\
        PathCreateFromUrl,\
        PathFileExists,\
        PathFindExtension,\
        PathFindFileName,\
        PathFindNextComponent,\
        PathFindOnPath,\
        PathFindSuffixArray,\
        PathGetArgs,\
        PathGetCharType,\
        PathGetDriveNumber,\
        PathIsContentType,\
        PathIsDirectory,\
        PathIsDirectoryEmpty,\
        PathIsFileSpec,\
        PathIsLFNFileSpec,\
        PathIsNetworkPath,\
        PathIsPrefix,\
        PathIsRelative,\
        PathIsRoot,\
        PathIsSameRoot,\
        PathIsSystemFolder,\
        PathIsUNC,\
        PathIsUNCServerShare,\
        PathIsUNCServer,\
        PathIsURL,\
        PathMakePretty,\
        PathMakeSystemFolder,\
        PathMatchSpec,\
        PathMatchSpecEx,\
        PathParseIconLocation,\
        PathQuoteSpaces,\
        PathRelativePathTo,\
        PathRemoveArgs,\
        PathRemoveBackslash,\
        PathRemoveBlanks,\
        PathRemoveExtension,\
        PathRemoveFileSpec,\
        PathRenameExtension,\
        PathSearchAndQualify,\
        PathSetDlgItemPath,\
        PathSkipRoot,\
        PathStripPath,\
        PathStripToRoot,\
        PathUnExpandEnvStrings,\
        PathUndecorate,\
        PathUnmakeSystemFolder,\
        PathUnquoteSpaces,\
        SHCopyKey,\
        SHCreateStreamOnFile,\
        SHDeleteEmptyKey,\
        SHDeleteKey,\
        SHDeleteValue,\
        SHEnumKeyEx,\
        SHEnumValue,\
        SHFormatDateTime,\
        SHGetValue,\
        SHMessageBoxCheck,\
        SHOpenRegStream2,\
        SHOpenRegStream,\
        SHQueryInfoKey,\
        SHQueryValueEx,\
        SHRegCreateUSKey,\
        SHRegDeleteEmptyUSKey,\
        SHRegDeleteUSValue,\
        SHRegEnumUSKey,\
        SHRegEnumUSValue,\
        SHRegGetBoolUSValue,\
        SHRegGetPath,\
        SHRegGetUSValue,\
        SHRegGetValue,\
        SHRegOpenUSKey,\
        SHRegQueryInfoUSKey,\
        SHRegQueryUSValue,\
        SHRegSetPath,\
        SHRegSetUSValue,\
        SHRegWriteUSValue,\
        SHSendMessageBroadcast,\
        SHSetValue,\
        SHStrDup,\
        SHStripMneumonic,\
        StrCSpn,\
        StrCSpnI,\
        StrCatBuff,\
        StrCatChain,\
        StrCat,\
        StrChr,\
        StrChrI,\
        StrCmpC,\
        StrCmpIC,\
        StrCmpNC,\
        StrCmpNI,\
        StrCmpNIC,\
        StrCmpN,\
        StrDup,\
        StrFormatKBSize,\
        StrFromTimeInterval,\
        StrIsIntlEqual,\
        StrNCat,\
        StrPBrk,\
        StrRChrI,\
        StrRChr,\
        StrRStrI,\
        StrRetToBuf,\
        StrRetToStr,\
        StrSpn,\
        StrStr,\
        StrStrI,\
        StrToInt64Ex,\
        StrToIntEx,\
        StrToInt,\
        StrTrim,\
        UrlApplyScheme,\
        UrlCanonicalize,\
        UrlCombine,\
        UrlCompare,\
        UrlCreateFromPath,\
        UrlEscape,\
        UrlGetLocation,\
        UrlGetPart,\
        UrlHash,\
        UrlIsNoHistory,\
        UrlIsOpaque,\
        UrlIs,\
        UrlUnescape,\
        wnsprintf,\
        wvnsprintf
else
    extrn '__imp__AssocCreate@24' as AssocCreate:dword
    extrn '__imp__AssocGetPerceivedType@16' as AssocGetPerceivedType:dword
    extrn '__imp__AssocIsDangerous@4' as AssocIsDangerous:dword
    extrn '__imp__AssocQueryKeyA@20' as AssocQueryKeyA:dword
    extrn '__imp__AssocQueryKeyW@20' as AssocQueryKeyW:dword
    extrn '__imp__AssocQueryStringA@24' as AssocQueryStringA:dword
    extrn '__imp__AssocQueryStringW@24' as AssocQueryStringW:dword
    extrn '__imp__AssocQueryStringByKeyA@24' as AssocQueryStringByKeyA:dword
    extrn '__imp__AssocQueryStringByKeyW@24' as AssocQueryStringByKeyW:dword
    extrn '__imp__ChrCmpIA@8' as ChrCmpIA:dword
    extrn '__imp__ChrCmpIW@8' as ChrCmpIW:dword
    extrn '__imp__ColorAdjustLuma@12' as ColorAdjustLuma:dword
    extrn '__imp__ColorHLSToRGB@12' as ColorHLSToRGB:dword
    extrn '__imp__ColorRGBToHLS@16' as ColorRGBToHLS:dword
    ;extrn '__imp__ConnectToConnectionPoint@24' as ConnectToConnectionPoint:dword ;Not present in MASM32 shlwapi.ib
    ;extrn '__imp__DelayLoadFailureHook@8' as DelayLoadFailureHook:dword ;Not present in MASM32 shlwapi.lib
    extrn '__imp__DllInstall@8' as DllInstall:dword
    extrn '__imp__GetAcceptLanguagesA@8' as GetAcceptLanguagesA:dword
    extrn '__imp__GetAcceptLanguagesW@8' as GetAcceptLanguagesW:dword
    extrn '__imp__GetMenuPosFromID@8' as GetMenuPosFromID:dword
    extrn '__imp__HashData@16' as HashData:dword
;    extrn '__imp__IStream_Copy@12' as IStream_Copy:dword ;Not present in MASM32 shlwapi.lib
;    extrn '__imp__IStream_Read@12' as IStream_Read:dword ;Not present in MASM32 shlwapi.lib
;    extrn '__imp__IStream_ReadPidl@8' as IStream_ReadPidl:dword ;Not present in MASM32 shlwapi.lib
;    extrn '__imp__IStream_ReadStr@8' as IStream_ReadStr:dword ;Not present in MASM32 shlwapi.lib
;    extrn '__imp__IStream_Reset@4' as IStream_Reset:dword ;Not present in MASM32 shlwapi.lib
;    extrn '__imp__IStream_Size@8' as IStream_Size:dword ;Not present in MASM32 shlwapi.lib
;    extrn '__imp__IStream_Write@12' as IStream_Write:dword ;Not present in MASM32 shlwapi.lib
;    extrn '__imp__IStream_WritePidl@8' as IStream_WritePidl:dword ;Not present in MASM32 shlwapi.lib
;    extrn '__imp__IStream_WriteStr@8' as IStream_WriteStr:dword ;Not present in MASM32 shlwapi.lib
;    extrn '__imp__IUnknown_AtomicRelease@4' as IUnknown_AtomicRelease:dword ;Not present in MASM32 shlwapi.lib
;    extrn '__imp__IUnknown_GetSite@12' as IUnknown_GetSite:dword ;Not present in MASM32 shlwapi.lib
;    extrn '__imp__IUnknown_GetWindow@8' as IUnknown_GetWindow:dword ;Not present in MASM32 shlwapi.lib
;    extrn '__imp__IUnknown_QueryService@16' as IUnknown_QueryService:dword ;Not present in MASM32 shlwapi.lib
;    extrn '__imp__IUnknown_Set@8' as IUnknown_Set:dword ;Not present in MASM32 shlwapi.lib
;    extrn '__imp__IUnknown_SetSite@8' as IUnknown_SetSite:dword ;Not present in MASM32 shlwapi.lib
    extrn '__imp__IntlStrEqWorkerA@16' as IntlStrEqWorkerA:dword
    extrn '__imp__IntlStrEqWorkerW@16' as IntlStrEqWorkerW:dword
    extrn '__imp__IsCharSpaceA@4' as IsCharSpaceA:dword
    extrn '__imp__IsCharSpaceW@4' as IsCharSpaceW:dword
;    extrn '__imp__IsInternetESCEnabled@0' as IsInternetESCEnabled:dword ;Not present in MASM32 shlwapi.lib
;    extrn '__imp__IsOS@4' as IsOS:dword ;Not present in MASM32 shlwapi.lib
;    extrn '__imp__MLLoadLibraryA@12' as MLLoadLibraryA:dword ;Not present in MASM32 shlwapi.lib
;    extrn '__imp__MLLoadLibraryW@12' as MLLoadLibraryW:dword ;Not present in MASM32 shlwapi.lib
;    extrn '__imp__ParseURLA@8' as ParseURLA:dword ;Not present in MASM32 shlwapi.lib
;    extrn '__imp__ParseURLW@8' as ParseURLW:dword ;Not present in MASM32 shlwapi.lib
    extrn '__imp__PathAddBackslashA@4' as PathAddBackslashA:dword
    extrn '__imp__PathAddBackslashW@4' as PathAddBackslashW:dword
    extrn '__imp__PathAddExtensionA@8' as PathAddExtensionA:dword
    extrn '__imp__PathAddExtensionW@8' as PathAddExtensionW:dword
    extrn '__imp__PathAppendA@8' as PathAppendA:dword
    extrn '__imp__PathAppendW@8' as PathAppendW:dword
    extrn '__imp__PathBuildRootA@8' as PathBuildRootA:dword
    extrn '__imp__PathBuildRootW@8' as PathBuildRootW:dword
    extrn '__imp__PathCanonicalizeA@8' as PathCanonicalizeA:dword
    extrn '__imp__PathCanonicalizeW@8' as PathCanonicalizeW:dword
    extrn '__imp__PathCombineA@12' as PathCombineA:dword
    extrn '__imp__PathCombineW@12' as PathCombineW:dword
    extrn '__imp__PathCommonPrefixA@12' as PathCommonPrefixA:dword
    extrn '__imp__PathCommonPrefixW@12' as PathCommonPrefixW:dword
    extrn '__imp__PathCompactPathA@12' as PathCompactPathA:dword
    extrn '__imp__PathCompactPathExA@16' as PathCompactPathExA:dword
    extrn '__imp__PathCompactPathExW@16' as PathCompactPathExW:dword
    extrn '__imp__PathCompactPathW@12' as PathCompactPathW:dword
    extrn '__imp__PathCreateFromUrlA@16' as PathCreateFromUrlA:dword
;    extrn '__imp__PathCreateFromUrlAlloc@12' as PathCreateFromUrlAlloc:dword ;Not present in MASM32 shlwapi.lib
    extrn '__imp__PathCreateFromUrlW@16' as PathCreateFromUrlW:dword
    extrn '__imp__PathFileExistsA@4' as PathFileExistsA:dword
    extrn '__imp__PathFileExistsW@4' as PathFileExistsW:dword
    extrn '__imp__PathFindExtensionA@4' as PathFindExtensionA:dword
    extrn '__imp__PathFindExtensionW@4' as PathFindExtensionW:dword
    extrn '__imp__PathFindFileNameA@4' as PathFindFileNameA:dword
    extrn '__imp__PathFindFileNameW@4' as PathFindFileNameW:dword
    extrn '__imp__PathFindNextComponentA@4' as PathFindNextComponentA:dword
    extrn '__imp__PathFindNextComponentW@4' as PathFindNextComponentW:dword
    extrn '__imp__PathFindOnPathA@8' as PathFindOnPathA:dword
    extrn '__imp__PathFindOnPathW@8' as PathFindOnPathW:dword
    extrn '__imp__PathFindSuffixArrayA@12' as PathFindSuffixArrayA:dword
    extrn '__imp__PathFindSuffixArrayW@12' as PathFindSuffixArrayW:dword
    extrn '__imp__PathGetArgsA@4' as PathGetArgsA:dword
    extrn '__imp__PathGetArgsW@4' as PathGetArgsW:dword
    extrn '__imp__PathGetCharTypeA@4' as PathGetCharTypeA:dword
    extrn '__imp__PathGetCharTypeW@4' as PathGetCharTypeW:dword
    extrn '__imp__PathGetDriveNumberA@4' as PathGetDriveNumberA:dword
    extrn '__imp__PathGetDriveNumberW@4' as PathGetDriveNumberW:dword
    extrn '__imp__PathIsContentTypeA@8' as PathIsContentTypeA:dword
    extrn '__imp__PathIsContentTypeW@8' as PathIsContentTypeW:dword
    extrn '__imp__PathIsDirectoryA@4' as PathIsDirectoryA:dword
    extrn '__imp__PathIsDirectoryEmptyA@4' as PathIsDirectoryEmptyA:dword
    extrn '__imp__PathIsDirectoryEmptyW@4' as PathIsDirectoryEmptyW:dword
    extrn '__imp__PathIsDirectoryW@4' as PathIsDirectoryW:dword
    extrn '__imp__PathIsFileSpecA@4' as PathIsFileSpecA:dword
    extrn '__imp__PathIsFileSpecW@4' as PathIsFileSpecW:dword
    extrn '__imp__PathIsLFNFileSpecA@4' as PathIsLFNFileSpecA:dword
    extrn '__imp__PathIsLFNFileSpecW@4' as PathIsLFNFileSpecW:dword
    extrn '__imp__PathIsNetworkPathA@4' as PathIsNetworkPathA:dword
    extrn '__imp__PathIsNetworkPathW@4' as PathIsNetworkPathW:dword
    extrn '__imp__PathIsPrefixA@8' as PathIsPrefixA:dword
    extrn '__imp__PathIsPrefixW@8' as PathIsPrefixW:dword
    extrn '__imp__PathIsRelativeA@4' as PathIsRelativeA:dword
    extrn '__imp__PathIsRelativeW@4' as PathIsRelativeW:dword
    extrn '__imp__PathIsRootA@4' as PathIsRootA:dword
    extrn '__imp__PathIsRootW@4' as PathIsRootW:dword
    extrn '__imp__PathIsSameRootA@8' as PathIsSameRootA:dword
    extrn '__imp__PathIsSameRootW@8' as PathIsSameRootW:dword
    extrn '__imp__PathIsSystemFolderA@8' as PathIsSystemFolderA:dword
    extrn '__imp__PathIsSystemFolderW@8' as PathIsSystemFolderW:dword
    extrn '__imp__PathIsUNCA@4' as PathIsUNCA:dword
    extrn '__imp__PathIsUNCServerA@4' as PathIsUNCServerA:dword
    extrn '__imp__PathIsUNCServerShareA@4' as PathIsUNCServerShareA:dword
    extrn '__imp__PathIsUNCServerShareW@4' as PathIsUNCServerShareW:dword
    extrn '__imp__PathIsUNCServerW@4' as PathIsUNCServerW:dword
    extrn '__imp__PathIsUNCW@4' as PathIsUNCW:dword
    extrn '__imp__PathIsURLA@4' as PathIsURLA:dword
    extrn '__imp__PathIsURLW@4' as PathIsURLW:dword
    extrn '__imp__PathMakePrettyA@4' as PathMakePrettyA:dword
    extrn '__imp__PathMakePrettyW@4' as PathMakePrettyW:dword
    extrn '__imp__PathMakeSystemFolderA@4' as PathMakeSystemFolderA:dword
    extrn '__imp__PathMakeSystemFolderW@4' as PathMakeSystemFolderW:dword
    extrn '__imp__PathMatchSpecA@8' as PathMatchSpecA:dword
;    extrn '__imp__PathMatchSpecExA@12' as PathMatchSpecExA:dword ;Not present in MASM32 shlwapi.lib
;    extrn '__imp__PathMatchSpecExW@12' as PathMatchSpecExW:dword ;Not present in MASM32 shlwapi.lib
    extrn '__imp__PathMatchSpecW@8' as PathMatchSpecW:dword
    extrn '__imp__PathParseIconLocationA@4' as PathParseIconLocationA:dword
    extrn '__imp__PathParseIconLocationW@4' as PathParseIconLocationW:dword
    extrn '__imp__PathQuoteSpacesA@4' as PathQuoteSpacesA:dword
    extrn '__imp__PathQuoteSpacesW@4' as PathQuoteSpacesW:dword
    extrn '__imp__PathRelativePathToA@20' as PathRelativePathToA:dword
    extrn '__imp__PathRelativePathToW@20' as PathRelativePathToW:dword
    extrn '__imp__PathRemoveArgsA@4' as PathRemoveArgsA:dword
    extrn '__imp__PathRemoveArgsW@4' as PathRemoveArgsW:dword
    extrn '__imp__PathRemoveBackslashA@4' as PathRemoveBackslashA:dword
    extrn '__imp__PathRemoveBackslashW@4' as PathRemoveBackslashW:dword
    extrn '__imp__PathRemoveBlanksA@4' as PathRemoveBlanksA:dword
    extrn '__imp__PathRemoveBlanksW@4' as PathRemoveBlanksW:dword
    extrn '__imp__PathRemoveExtensionA@4' as PathRemoveExtensionA:dword
    extrn '__imp__PathRemoveExtensionW@4' as PathRemoveExtensionW:dword
    extrn '__imp__PathRemoveFileSpecA@4' as PathRemoveFileSpecA:dword
    extrn '__imp__PathRemoveFileSpecW@4' as PathRemoveFileSpecW:dword
    extrn '__imp__PathRenameExtensionA@8' as PathRenameExtensionA:dword
    extrn '__imp__PathRenameExtensionW@8' as PathRenameExtensionW:dword
    extrn '__imp__PathSearchAndQualifyA@12' as PathSearchAndQualifyA:dword
    extrn '__imp__PathSearchAndQualifyW@12' as PathSearchAndQualifyW:dword
    extrn '__imp__PathSetDlgItemPathA@12' as PathSetDlgItemPathA:dword
    extrn '__imp__PathSetDlgItemPathW@12' as PathSetDlgItemPathW:dword
    extrn '__imp__PathSkipRootA@4' as PathSkipRootA:dword
    extrn '__imp__PathSkipRootW@4' as PathSkipRootW:dword
    extrn '__imp__PathStripPathA@4' as PathStripPathA:dword
    extrn '__imp__PathStripPathW@4' as PathStripPathW:dword
    extrn '__imp__PathStripToRootA@4' as PathStripToRootA:dword
    extrn '__imp__PathStripToRootW@4' as PathStripToRootW:dword
    extrn '__imp__PathUnExpandEnvStringsA@12' as PathUnExpandEnvStringsA:dword
    extrn '__imp__PathUnExpandEnvStringsW@12' as PathUnExpandEnvStringsW:dword
    extrn '__imp__PathUndecorateA@4' as PathUndecorateA:dword
    extrn '__imp__PathUndecorateW@4' as PathUndecorateW:dword
    extrn '__imp__PathUnmakeSystemFolderA@4' as PathUnmakeSystemFolderA:dword
    extrn '__imp__PathUnmakeSystemFolderW@4' as PathUnmakeSystemFolderW:dword
    extrn '__imp__PathUnquoteSpacesA@4' as PathUnquoteSpacesA:dword
    extrn '__imp__PathUnquoteSpacesW@4' as PathUnquoteSpacesW:dword
;    extrn '__imp__QISearch@16' as QISearch:dword ;Not present in MASM32 shlwapi.ib
    extrn '__imp__SHAllocShared@12' as SHAllocShared:dword
;    extrn '__imp__SHAnsiToAnsi@12' as SHAnsiToAnsi:dword ;Not present in MASM32 shlwapi.ib
;    extrn '__imp__SHAnsiToUnicode@12' as SHAnsiToUnicode:dword ;Not present in MASM32 shlwapi.ib
    extrn '__imp__SHAutoComplete@8' as SHAutoComplete:dword
    extrn '__imp__SHCopyKeyA@16' as SHCopyKeyA:dword
    extrn '__imp__SHCopyKeyW@16' as SHCopyKeyW:dword
;    extrn '__imp__SHCreateMemStream@8' as SHCreateMemStream:dword ;Not present in MASM32 shlwapi.ib
    extrn '__imp__SHCreateShellPalette@4' as SHCreateShellPalette:dword
    extrn '__imp__SHCreateStreamOnFileA@12' as SHCreateStreamOnFileA:dword
    extrn '__imp__SHCreateStreamOnFileEx@24' as SHCreateStreamOnFileEx:dword
    extrn '__imp__SHCreateStreamOnFileW@12' as SHCreateStreamOnFileW:dword
    extrn '__imp__SHCreateThread@16' as SHCreateThread:dword
    extrn '__imp__SHCreateThreadRef@8' as SHCreateThreadRef:dword
;    extrn '__imp__SHCreateThreadWithHandle@20' as SHCreateThreadWithHandle:dword ;Not present in MASM32 shlwapi.ib
    extrn '__imp__SHDeleteEmptyKeyA@8' as SHDeleteEmptyKeyA:dword
    extrn '__imp__SHDeleteEmptyKeyW@8' as SHDeleteEmptyKeyW:dword
    extrn '__imp__SHDeleteKeyA@8' as SHDeleteKeyA:dword
    extrn '__imp__SHDeleteKeyW@8' as SHDeleteKeyW:dword
    extrn '__imp__SHDeleteValueA@12' as SHDeleteValueA:dword
    extrn '__imp__SHDeleteValueW@12' as SHDeleteValueW:dword
    extrn '__imp__SHEnumKeyExA@16' as SHEnumKeyExA:dword
    extrn '__imp__SHEnumKeyExW@16' as SHEnumKeyExW:dword
    extrn '__imp__SHEnumValueA@28' as SHEnumValueA:dword
    extrn '__imp__SHEnumValueW@28' as SHEnumValueW:dword
;    extrn '__imp__SHFormatDateTimeA@12' as SHFormatDateTimeA:dword ;Not present in MASM32 shlwapi.ib
;    extrn '__imp__SHFormatDateTimeW@12' as SHFormatDateTimeW:dword ;Not present in MASM32 shlwapi.ib
    extrn '__imp__SHFreeShared@8' as SHFreeShared:dword
    extrn '__imp__SHGetInverseCMAP@8' as SHGetInverseCMAP:dword
    extrn '__imp__SHGetThreadRef@4' as SHGetThreadRef:dword
    extrn '__imp__SHGetValueA@24' as SHGetValueA:dword
    extrn '__imp__SHGetValueW@24' as SHGetValueW:dword
    extrn '__imp__SHGetViewStatePropertyBag@20' as SHGetViewStatePropertyBag:dword
;    extrn '__imp__SHIsChildOrSelf@8' as SHIsChildOrSelf:dword ;Not present in MASM32 shlwapi.ib
    extrn '__imp__SHIsLowMemoryMachine@4' as SHIsLowMemoryMachine:dword
    extrn '__imp__SHLoadIndirectString@16' as SHLoadIndirectString:dword
    extrn '__imp__SHLockShared@8' as SHLockShared:dword
;    extrn '__imp__SHMessageBoxCheckA@24' as SHMessageBoxCheckA:dword ;Not present in MASM32 shlwapi.ib
;    extrn '__imp__SHMessageBoxCheckW@24' as SHMessageBoxCheckW:dword ;Not present in MASM32 shlwapi.ib
    extrn '__imp__SHOpenRegStream2A@16' as SHOpenRegStream2A:dword
    extrn '__imp__SHOpenRegStream2W@16' as SHOpenRegStream2W:dword
    extrn '__imp__SHOpenRegStreamA@16' as SHOpenRegStreamA:dword
    extrn '__imp__SHOpenRegStreamW@16' as SHOpenRegStreamW:dword
    extrn '__imp__SHQueryInfoKeyA@20' as SHQueryInfoKeyA:dword
    extrn '__imp__SHQueryInfoKeyW@20' as SHQueryInfoKeyW:dword
    extrn '__imp__SHQueryValueExA@24' as SHQueryValueExA:dword
    extrn '__imp__SHQueryValueExW@24' as SHQueryValueExW:dword
    extrn '__imp__SHRegCloseUSKey@4' as SHRegCloseUSKey:dword
    extrn '__imp__SHRegCreateUSKeyA@20' as SHRegCreateUSKeyA:dword
    extrn '__imp__SHRegCreateUSKeyW@20' as SHRegCreateUSKeyW:dword
    extrn '__imp__SHRegDeleteEmptyUSKeyA@12' as SHRegDeleteEmptyUSKeyA:dword
    extrn '__imp__SHRegDeleteEmptyUSKeyW@12' as SHRegDeleteEmptyUSKeyW:dword
    extrn '__imp__SHRegDeleteUSValueA@12' as SHRegDeleteUSValueA:dword
    extrn '__imp__SHRegDeleteUSValueW@12' as SHRegDeleteUSValueW:dword
    extrn '__imp__SHRegDuplicateHKey@4' as SHRegDuplicateHKey:dword
    extrn '__imp__SHRegEnumUSKeyA@20' as SHRegEnumUSKeyA:dword
    extrn '__imp__SHRegEnumUSKeyW@20' as SHRegEnumUSKeyW:dword
    extrn '__imp__SHRegEnumUSValueA@32' as SHRegEnumUSValueA:dword
    extrn '__imp__SHRegEnumUSValueW@32' as SHRegEnumUSValueW:dword
    extrn '__imp__SHRegGetBoolUSValueA@16' as SHRegGetBoolUSValueA:dword
    extrn '__imp__SHRegGetBoolUSValueW@16' as SHRegGetBoolUSValueW:dword
;    extrn '__imp__SHRegGetIntW@12' as SHRegGetIntW:dword ;Not present in MASM32 shlwapi.ib
    extrn '__imp__SHRegGetPathA@20' as SHRegGetPathA:dword
    extrn '__imp__SHRegGetPathW@20' as SHRegGetPathW:dword
    extrn '__imp__SHRegGetUSValueA@32' as SHRegGetUSValueA:dword
    extrn '__imp__SHRegGetUSValueW@32' as SHRegGetUSValueW:dword
    extrn '__imp__SHRegGetValueA@28' as SHRegGetValueA:dword
    extrn '__imp__SHRegGetValueW@28' as SHRegGetValueW:dword
    extrn '__imp__SHRegOpenUSKeyA@20' as SHRegOpenUSKeyA:dword
    extrn '__imp__SHRegOpenUSKeyW@20' as SHRegOpenUSKeyW:dword
    extrn '__imp__SHRegQueryInfoUSKeyA@24' as SHRegQueryInfoUSKeyA:dword
    extrn '__imp__SHRegQueryInfoUSKeyW@24' as SHRegQueryInfoUSKeyW:dword
    extrn '__imp__SHRegQueryUSValueA@32' as SHRegQueryUSValueA:dword
    extrn '__imp__SHRegQueryUSValueW@32' as SHRegQueryUSValueW:dword
    extrn '__imp__SHRegSetPathA@20' as SHRegSetPathA:dword
    extrn '__imp__SHRegSetPathW@20' as SHRegSetPathW:dword
    extrn '__imp__SHRegSetUSValueA@24' as SHRegSetUSValueA:dword
    extrn '__imp__SHRegSetUSValueW@24' as SHRegSetUSValueW:dword
    extrn '__imp__SHRegWriteUSValueA@24' as SHRegWriteUSValueA:dword
    extrn '__imp__SHRegWriteUSValueW@24' as SHRegWriteUSValueW:dword
    extrn '__imp__SHRegisterValidateTemplate@8' as SHRegisterValidateTemplate:dword
    extrn '__imp__SHReleaseThreadRef@0' as SHReleaseThreadRef:dword
;    extrn '__imp__SHRunIndirectRegClientCommand@8' as SHRunIndirectRegClientCommand:dword ;Not present in MASM32 shlwapi.ib
;    extrn '__imp__SHSendMessageBroadcastA@12' as SHSendMessageBroadcastA:dword ;Not present in MASM32 shlwapi.ib
;    extrn '__imp__SHSendMessageBroadcastW@12' as SHSendMessageBroadcastW:dword ;Not present in MASM32 shlwapi.ib
    extrn '__imp__SHSetThreadRef@4' as SHSetThreadRef:dword
    extrn '__imp__SHSetValueA@24' as SHSetValueA:dword
    extrn '__imp__SHSetValueW@24' as SHSetValueW:dword
    extrn '__imp__SHSkipJunction@8' as SHSkipJunction:dword
    extrn '__imp__SHStrDupA@8' as SHStrDupA:dword
    extrn '__imp__SHStrDupW@8' as SHStrDupW:dword
;    extrn '__imp__SHStripMneumonicA@4' as SHStripMneumonicA:dword ;Not present in MASM32 shlwapi.ib
;    extrn '__imp__SHStripMneumonicW@4' as SHStripMneumonicW:dword ;Not present in MASM32 shlwapi.ib
;    extrn '__imp__SHUnicodeToAnsi@12' as SHUnicodeToAnsi:dword ;Not present in MASM32 shlwapi.ib
;    extrn '__imp__SHUnicodeToUnicode@12' as SHUnicodeToUnicode:dword ;Not present in MASM32 shlwapi.ib
    extrn '__imp__SHUnlockShared@4' as SHUnlockShared:dword
    extrn '__imp__StrCSpnA@8' as StrCSpnA:dword
    extrn '__imp__StrCSpnIA@8' as StrCSpnIA:dword
    extrn '__imp__StrCSpnIW@8' as StrCSpnIW:dword
    extrn '__imp__StrCSpnW@8' as StrCSpnW:dword
    extrn '__imp__StrCatBuffA@12' as StrCatBuffA:dword
    extrn '__imp__StrCatBuffW@12' as StrCatBuffW:dword
    extrn '__imp__StrCatChainW@16' as StrCatChainW:dword
    extrn '__imp__StrChrA@8' as StrChrA:dword
    extrn '__imp__StrChrIA@8' as StrChrIA:dword
    extrn '__imp__StrChrIW@8' as StrChrIW:dword
    extrn '__imp__StrChrNIW@12' as StrChrNIW:dword
    extrn '__imp__StrChrNW@12' as StrChrNW:dword
    extrn '__imp__StrChrW@8' as StrChrW:dword
    extrn '__imp__StrCmpCA@8' as StrCmpCA:dword
    extrn '__imp__StrCmpCW@8' as StrCmpCW:dword
    extrn '__imp__StrCmpICA@8' as StrCmpICA:dword
    extrn '__imp__StrCmpICW@8' as StrCmpICW:dword
    extrn '__imp__StrCmpIW@8' as StrCmpIW:dword
    extrn '__imp__StrCmpLogicalW@8' as StrCmpLogicalW:dword
    extrn '__imp__StrCmpNA@12' as StrCmpNA:dword
;    extrn '__imp__StrCmpNCA@12' as StrCmpNCA:dword ;Not present in MASM32 shlwapi.ib
;    extrn '__imp__StrCmpNCW@12' as StrCmpNCW:dword ;Not present in MASM32 shlwapi.ib
    extrn '__imp__StrCmpNIA@12' as StrCmpNIA:dword
;    extrn '__imp__StrCmpNICA@12' as StrCmpNICA:dword ;Not present in MASM32 shlwapi.ib
;    extrn '__imp__StrCmpNICW@12' as StrCmpNICW:dword ;Not present in MASM32 shlwapi.ib
    extrn '__imp__StrCmpNIW@12' as StrCmpNIW:dword
    extrn '__imp__StrCmpNW@12' as StrCmpNW:dword
    extrn '__imp__StrCmpW@8' as StrCmpW:dword
    extrn '__imp__StrCpyNW@12' as StrCpyNW:dword
    extrn '__imp__StrCpyW@8' as StrCpyW:dword
    extrn '__imp__StrDupA@4' as StrDupA:dword
    extrn '__imp__StrDupW@4' as StrDupW:dword
    extrn '__imp__StrFormatByteSize64A@16' as StrFormatByteSize64A:dword
;    extrn '__imp__StrFormatByteSizeEx@16' as StrFormatByteSizeEx:dword ;Not present in MASM32 shlwapi.ib
    extrn '__imp__StrFormatByteSizeW@16' as StrFormatByteSizeW:dword
    extrn '__imp__StrFormatKBSizeA@16' as StrFormatKBSizeA:dword
    extrn '__imp__StrFormatKBSizeW@16' as StrFormatKBSizeW:dword
    extrn '__imp__StrFromTimeIntervalA@16' as StrFromTimeIntervalA:dword
    extrn '__imp__StrFromTimeIntervalW@16' as StrFromTimeIntervalW:dword
    extrn '__imp__StrIsIntlEqualA@16' as StrIsIntlEqualA:dword
    extrn '__imp__StrIsIntlEqualW@16' as StrIsIntlEqualW:dword
    extrn '__imp__StrNCatA@12' as StrNCatA:dword
    extrn '__imp__StrNCatW@12' as StrNCatW:dword
    extrn '__imp__StrPBrkA@8' as StrPBrkA:dword
    extrn '__imp__StrPBrkW@8' as StrPBrkW:dword
    extrn '__imp__StrRChrA@12' as StrRChrA:dword
    extrn '__imp__StrRChrIA@12' as StrRChrIA:dword
    extrn '__imp__StrRChrIW@12' as StrRChrIW:dword
    extrn '__imp__StrRChrW@12' as StrRChrW:dword
    extrn '__imp__StrRStrIA@12' as StrRStrIA:dword
    extrn '__imp__StrRStrIW@12' as StrRStrIW:dword
    extrn '__imp__StrRetToBSTR@12' as StrRetToBSTR:dword
    extrn '__imp__StrRetToBufA@16' as StrRetToBufA:dword
    extrn '__imp__StrRetToBufW@16' as StrRetToBufW:dword
    extrn '__imp__StrRetToStrA@12' as StrRetToStrA:dword
    extrn '__imp__StrRetToStrW@12' as StrRetToStrW:dword
    extrn '__imp__StrSpnA@8' as StrSpnA:dword
    extrn '__imp__StrSpnW@8' as StrSpnW:dword
    extrn '__imp__StrStrA@8' as StrStrA:dword
    extrn '__imp__StrStrIA@8' as StrStrIA:dword
    extrn '__imp__StrStrIW@8' as StrStrIW:dword
    extrn '__imp__StrStrNIW@12' as StrStrNIW:dword
    extrn '__imp__StrStrNW@12' as StrStrNW:dword
    extrn '__imp__StrStrW@8' as StrStrW:dword
    extrn '__imp__StrToInt64ExA@12' as StrToInt64ExA:dword
    extrn '__imp__StrToInt64ExW@12' as StrToInt64ExW:dword
    extrn '__imp__StrToIntA@4' as StrToIntA:dword
    extrn '__imp__StrToIntExA@12' as StrToIntExA:dword
    extrn '__imp__StrToIntExW@12' as StrToIntExW:dword
    extrn '__imp__StrToIntW@4' as StrToIntW:dword
    extrn '__imp__StrTrimA@8' as StrTrimA:dword
    extrn '__imp__StrTrimW@8' as StrTrimW:dword
    extrn '__imp__UrlApplySchemeA@16' as UrlApplySchemeA:dword
    extrn '__imp__UrlApplySchemeW@16' as UrlApplySchemeW:dword
    extrn '__imp__UrlCanonicalizeA@16' as UrlCanonicalizeA:dword
    extrn '__imp__UrlCanonicalizeW@16' as UrlCanonicalizeW:dword
    extrn '__imp__UrlCombineA@20' as UrlCombineA:dword
    extrn '__imp__UrlCombineW@20' as UrlCombineW:dword
    extrn '__imp__UrlCompareA@12' as UrlCompareA:dword
    extrn '__imp__UrlCompareW@12' as UrlCompareW:dword
    extrn '__imp__UrlCreateFromPathA@16' as UrlCreateFromPathA:dword
    extrn '__imp__UrlCreateFromPathW@16' as UrlCreateFromPathW:dword
    extrn '__imp__UrlEscapeA@16' as UrlEscapeA:dword
    extrn '__imp__UrlEscapeW@16' as UrlEscapeW:dword
;    extrn '__imp__UrlFixupW@12' as UrlFixupW:dword ;Not present in MASM32 shlwapi.ib
    extrn '__imp__UrlGetLocationA@4' as UrlGetLocationA:dword
    extrn '__imp__UrlGetLocationW@4' as UrlGetLocationW:dword
    extrn '__imp__UrlGetPartA@20' as UrlGetPartA:dword
    extrn '__imp__UrlGetPartW@20' as UrlGetPartW:dword
    extrn '__imp__UrlHashA@12' as UrlHashA:dword
    extrn '__imp__UrlHashW@12' as UrlHashW:dword
    extrn '__imp__UrlIsA@8' as UrlIsA:dword
    extrn '__imp__UrlIsNoHistoryA@4' as UrlIsNoHistoryA:dword
    extrn '__imp__UrlIsNoHistoryW@4' as UrlIsNoHistoryW:dword
    extrn '__imp__UrlIsOpaqueA@4' as UrlIsOpaqueA:dword
    extrn '__imp__UrlIsOpaqueW@4' as UrlIsOpaqueW:dword
    extrn '__imp__UrlIsW@8' as UrlIsW:dword
    extrn '__imp__UrlUnescapeA@16' as UrlUnescapeA:dword
    extrn '__imp__UrlUnescapeW@16' as UrlUnescapeW:dword
;    extrn '__imp__WhichPlatform@0' as WhichPlatform:dword ;Not present in MASM32 shlwapi.ib
    extrn '__imp__wvnsprintfA@16' as wvnsprintfA:dword
    extrn '__imp__wvnsprintfW@16' as wvnsprintfW:dword

    if (NTDDI_VERSION >= NTDDI_WIN2K)
        if (NTDDI_VERSION <= NTDDI_WIN7)
;            extrn '__imp__DllGetClassObject@12' as DllGetClassObject:dword ;Not present in MASM32 shlwapi.lib
;           extrn '__imp__MLFreeLibrary@4' as MLFreeLibrary:dword ;Not present in MASM32 shlwapi.lib
            extrn '__imp__SHDeleteOrphanKeyA@8' as SHDeleteOrphanKeyA:dword
            extrn '__imp__SHDeleteOrphanKeyW@8' as SHDeleteOrphanKeyW:dword
            api SHDeleteOrphanKey
        end if
    end if

    if (NTDDI_VERSION >= NTDDI_WINXP)
        extrn '__imp__GUIDFromStringA@8' as GUIDFromStringA:dword
        extrn '__imp__GUIDFromStringW@8' as GUIDFromStringW:dword
        api GUIDFromString
    end if

    if (NTDDI_VERSION >= NTDDI_WIN8)
        extrn '__imp__IUnknown_Exec@24' as IUnknown_Exec:dword
        extrn '__imp__IUnknown_QueryStatus@20' as IUnknown_QueryStatus:dword
        extrn '__imp__PathFileExistsAndAttributesA@8' as PathFileExistsAndAttributesA:dword
        extrn '__imp__PathFileExistsAndAttributesW@8' as PathFileExistsAndAttributesW:dword
        extrn '__imp__SHRegGetBoolValueFromHKCUHKLM@12' as SHRegGetBoolValueFromHKCUHKLM:dword
        extrn '__imp__SHRegGetValueFromHKCUHKLM@24' as SHRegGetValueFromHKCUHKLM:dword
        extrn '__imp__SHUnicodeToAnsiCP@16' as SHUnicodeToAnsiCP:dword
        api PathFileExistsAndAttributes
    end if

    if (NTDDI_VERSION >= NTDDI_WIN10)
        extrn '__imp__SHCreateWorkerWindowA@24' as SHCreateWorkerWindowA:dword
        extrn '__imp__SHCreateWorkerWindowW@24' as SHCreateWorkerWindowW:dword
        extrn '__imp__SHPinDllOfCLSID@4' as SHPinDllOfCLSID:dword
        api SHCreateWorkerWindow
    end if

    if defined APP_UNICODE
        SZ_CONTENTTYPE_HTML equ SZ_CONTENTTYPE_HTMLW
        SZ_CONTENTTYPE_CDF  equ SZ_CONTENTTYPE_CDFW
        PARSEDURL fix PARSEDURLW
	else
        SZ_CONTENTTYPE_HTML equ SZ_CONTENTTYPE_HTMLA
        SZ_CONTENTTYPE_CDF  equ SZ_CONTENTTYPE_CDFA
        PARSEDURL fix PARSEDURLA
    end if

    api AssocQueryKey,\
        AssocQueryString,\
        AssocQueryStringByKey,\
        AssocQueryString,\
        ChrCmpI,\
        GetAcceptLanguages,\
        IntlStrEqWorker,\
        IsCharSpace,\
        PathAddBackslash,\
        PathAddExtension,\
        PathAppend,\
        PathBuildRoot,\
        PathCanonicalize,\
        PathCombine,\
        PathCommonPrefix,\
        PathCompactPath,\
        PathCompactPathEx,\
        PathCreateFromUrl,\
        PathFileExists,\
        PathFindExtension,\
        PathFindFileName,\
        PathFindNextComponent,\
        PathFindOnPath,\
        PathFindSuffixArray,\
        PathGetArgs,\
        PathGetCharType,\
        PathGetDriveNumber,\
        PathIsContentType,\
        PathIsDirectory,\
        PathIsDirectoryEmpty,\
        PathIsDirectoryEmpty,\
        PathIsFileSpec,\
        PathIsLFNFileSpec,\
        PathIsNetworkPath,\
        PathIsPrefix,\
        PathIsRelative,\
        PathIsRoot,\
        PathIsSameRoot,\
        PathIsSystemFolder,\
        PathIsUNC,\
        PathIsUNCServerShare,\
        PathIsUNCServer,\
        PathIsUNC,\
        PathIsURL,\
        PathMakePretty,\
        PathMakePretty,\
        PathMakeSystemFolder,\
        PathMatchSpec,\
        PathParseIconLocation,\
        PathQuoteSpaces,\
        PathRelativePathTo,\
        PathRemoveArgs,\
        PathRemoveBackslash,\
        PathRemoveBlanks,\
        PathRemoveExtension,\
        PathRemoveFileSpec,\
        PathRenameExtension,\
        PathSearchAndQualify,\
        PathSetDlgItemPath,\
        PathSkipRoot,\
        PathStripPath,\
        PathStripToRoot,\
        PathUnExpandEnvStrings,\
        PathUndecorate,\
        PathUnmakeSystemFolder,\
        PathUnquoteSpaces,\
        SHCopyKey,\
        SHCreateStreamOnFile,\
        SHDeleteEmptyKey,\
        SHDeleteKey,\
        SHDeleteValue,\
        SHEnumKeyEx,\
        SHEnumValue,\
        SHGetValue,\
        SHOpenRegStream2,\
        SHOpenRegStream,\
        SHQueryInfoKey,\
        SHQueryValueEx,\
        SHRegCreateUSKey,\
        SHRegDeleteEmptyUSKey,\
        SHRegDeleteUSValue,\
        SHRegEnumUSKey,\
        SHRegEnumUSValue,\
        SHRegGetBoolUSValue,\
        SHRegGetPath,\
        SHRegGetUSValue,\
        SHRegGetValue,\
        SHRegOpenUSKey,\
        SHRegQueryInfoUSKey,\
        SHRegQueryUSValue,\
        SHRegSetPath,\
        SHRegSetUSValue,\
        SHRegWriteUSValue,\
        SHSetValue,\
        SHStrDup,\
        StrCSpn,\
        StrCSpnI,\
        StrCatBuff,\
        StrCatChain,\
        StrCat,\
        StrChr,\
        StrChrI,\
        StrCmpC,\
        StrCmpIC,\
        StrCmpNI,\
        StrCmpN,\
        StrDup,\
        StrFormatKBSize,\
        StrFromTimeInterval,\
        StrIsIntlEqual,\
        StrNCat,\
        StrPBrk,\
        StrRChrI,\
        StrRChr,\
        StrRStrI,\
        StrRetToBuf,\
        StrRetToStr,\
        StrSpn,\
        StrStr,\
        StrStrI,\
        StrToInt64Ex,\
        StrToIntEx,\
        StrToInt,\
        StrTrim,\
        UrlApplyScheme,\
        UrlCanonicalize,\
        UrlCombine,\
        UrlCompare,\
        UrlCreateFromPath,\
        UrlEscape,\
        UrlGetLocation,\
        UrlGetPart,\
        UrlHash,\
        UrlIsNoHistory,\
        UrlIsOpaque,\
        UrlIs,\
        UrlUnescape,\
        wvnsprintf
end if

StrCatChain equ StrCatChainW
StrChrN equ StrChrNW
StrChrNI equ StrChrNIW
StrCmpI equ StrCmpIW
StrCmpLogical equ StrCmpLogicalW
StrCmp equ StrCmpW
StrCpy equ StrCpyW
StrCpyN equ StrCpyNW
StrFormatByteSize equ StrFormatByteSizeW
StrFormatByteSize64 equ StrFormatByteSize64A
StrStrN equ StrStrNW
StrStrNI equ StrStrNIW
if defined APP_WIN64
    SHRegGetInt equ SHRegGetIntW
    UrlFixup equ UrlFixupW
end if


;======================= Undocumented functions (unknown arguments) =======================;
;extrn '__imp__SHPropertyBag_ReadStrAlloc' as SHPropertyBag_ReadStrAlloc:qword
;extrn '__imp__SHPropertyBag_WriteBSTR' as SHPropertyBag_WriteBSTR:qword

;if defined APP_WIN64
    ;extrn '__imp__wnsprintfW' as wnsprintfW:qword ;VARARG
    ;extrn '__imp__wvnsprintfA' as wvnsprintfA:qword ;VARARG
;else
    ;extrn '__imp__wnsprintfA@??' as wnsprintfA:dword ;VARARG
    ;extrn '__imp__wnsprintfW@??' as wnsprintfW:dword ;VARARG
;end if

end if ;SHLWAPI_INC
