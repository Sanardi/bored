; ====================================================;
;                                                     ;
;     shlwapi.inc for EC v2 Fasm classic projects     ;
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

if defined APP_UNICODE
	PARSEDURL fix PARSEDURLW
else
	PARSEDURL fix PARSEDURLA
end if

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
import shlwapi,\
AssocCreate,'AssocCreate',\
AssocGetPerceivedType,'AssocGetPerceivedType',\
AssocIsDangerous,'AssocIsDangerous',\
AssocQueryKeyA,'AssocQueryKeyA',\
AssocQueryKeyW,'AssocQueryKeyW',\
AssocQueryStringA,'AssocQueryStringA',\
AssocQueryStringW,'AssocQueryStringW',\
AssocQueryStringByKeyA,'AssocQueryStringByKeyA',\
AssocQueryStringByKeyW,'AssocQueryStringByKeyW',\
ChrCmpIA,'ChrCmpIA',\
ChrCmpIW,'ChrCmpIW',\
ColorAdjustLuma,'ColorAdjustLuma',\
ColorHLSToRGB,'ColorHLSToRGB',\
ColorRGBToHLS,'ColorRGBToHLS',\
ConnectToConnectionPoint,'ConnectToConnectionPoint',\
DelayLoadFailureHook,'DelayLoadFailureHook',\
DllGetClassObject,'DllGetClassObject',\
DllInstall,'DllInstall',\
GetAcceptLanguagesA,'GetAcceptLanguagesA',\
GetAcceptLanguagesW,'GetAcceptLanguagesW',\
GetMenuPosFromID,'GetMenuPosFromID',\
GUIDFromStringA,'GUIDFromStringA',\
GUIDFromStringW,'GUIDFromStringW',\
HashData,'HashData',\
IStream_Copy,'IStream_Copy',\
IUnknown_Exec,'IUnknown_Exec',\
IUnknown_QueryStatus,'IUnknown_QueryStatus',\
IStream_Read,'IStream_Read',\
IStream_ReadPidl,'IStream_ReadPidl',\
IStream_ReadStr,'IStream_ReadStr',\
IStream_Reset,'IStream_Reset',\
IStream_Size,'IStream_Size',\
IStream_Write,'IStream_Write',\
IStream_WritePidl,'IStream_WritePidl',\
IStream_WriteStr,'IStream_WriteStr',\
IUnknown_AtomicRelease,'IUnknown_AtomicRelease',\
IUnknown_GetSite,'IUnknown_GetSite',\
IUnknown_GetWindow,'IUnknown_GetWindow',\
IUnknown_QueryService,'IUnknown_QueryService',\
IUnknown_Set,'IUnknown_Set',\
IUnknown_SetSite,'IUnknown_SetSite',\
IntlStrEqWorkerA,'IntlStrEqWorkerA',\
IntlStrEqWorkerW,'IntlStrEqWorkerW',\
IsCharSpaceA,'IsCharSpaceA',\
IsCharSpaceW,'IsCharSpaceW',\
IsInternetESCEnabled,'IsInternetESCEnabled',\
IsOS,'IsOS',\
MLFreeLibrary,'MLFreeLibrary',\
MLLoadLibraryA,'MLLoadLibraryA',\
MLLoadLibraryW,'MLLoadLibraryW',\
ParseURLA,'ParseURLA',\
ParseURLW,'ParseURLW',\
PathAddBackslashA,'PathAddBackslashA',\
PathAddBackslashW,'PathAddBackslashW',\
PathAddExtensionA,'PathAddExtensionA',\
PathAddExtensionW,'PathAddExtensionW',\
PathAppendA,'PathAppendA',\
PathAppendW,'PathAppendW',\
PathBuildRootA,'PathBuildRootA',\
PathBuildRootW,'PathBuildRootW',\
PathCanonicalizeA,'PathCanonicalizeA',\
PathCanonicalizeW,'PathCanonicalizeW',\
PathCombineA,'PathCombineA',\
PathCombineW,'PathCombineW',\
PathCommonPrefixA,'PathCommonPrefixA',\
PathCommonPrefixW,'PathCommonPrefixW',\
PathCompactPathA,'PathCompactPathA',\
PathCompactPathExA,'PathCompactPathExA',\
PathCompactPathExW,'PathCompactPathExW',\
PathCompactPathW,'PathCompactPathW',\
PathCreateFromUrlA,'PathCreateFromUrlA',\
PathCreateFromUrlAlloc,'PathCreateFromUrlAlloc',\
PathCreateFromUrlW,'PathCreateFromUrlW',\
PathFileExistsA,'PathFileExistsA',\
PathFileExistsAndAttributesA,'PathFileExistsAndAttributesA',\
PathFileExistsAndAttributesW,'PathFileExistsAndAttributesW',\
PathFileExistsW,'PathFileExistsW',\
PathFindExtensionA,'PathFindExtensionA',\
PathFindExtensionW,'PathFindExtensionW',\
PathFindFileNameA,'PathFindFileNameA',\
PathFindFileNameW,'PathFindFileNameW',\
PathFindNextComponentA,'PathFindNextComponentA',\
PathFindNextComponentW,'PathFindNextComponentW',\
PathFindOnPathA,'PathFindOnPathA',\
PathFindOnPathW,'PathFindOnPathW',\
PathFindSuffixArrayA,'PathFindSuffixArrayA',\
PathFindSuffixArrayW,'PathFindSuffixArrayW',\
PathGetArgsA,'PathGetArgsA',\
PathGetArgsW,'PathGetArgsW',\
PathGetCharTypeA,'PathGetCharTypeA',\
PathGetCharTypeW,'PathGetCharTypeW',\
PathGetDriveNumberA,'PathGetDriveNumberA',\
PathGetDriveNumberW,'PathGetDriveNumberW',\
PathIsContentTypeA,'PathIsContentTypeA',\
PathIsContentTypeW,'PathIsContentTypeW',\
PathIsDirectoryA,'PathIsDirectoryA',\
PathIsDirectoryEmptyA,'PathIsDirectoryEmptyA',\
PathIsDirectoryEmptyW,'PathIsDirectoryEmptyW',\
PathIsDirectoryW,'PathIsDirectoryW',\
PathIsFileSpecA,'PathIsFileSpecA',\
PathIsFileSpecW,'PathIsFileSpecW',\
PathIsLFNFileSpecA,'PathIsLFNFileSpecA',\
PathIsLFNFileSpecW,'PathIsLFNFileSpecW',\
PathIsNetworkPathA,'PathIsNetworkPathA',\
PathIsNetworkPathW,'PathIsNetworkPathW',\
PathIsPrefixA,'PathIsPrefixA',\
PathIsPrefixW,'PathIsPrefixW',\
PathIsRelativeA,'PathIsRelativeA',\
PathIsRelativeW,'PathIsRelativeW',\
PathIsRootA,'PathIsRootA',\
PathIsRootW,'PathIsRootW',\
PathIsSameRootA,'PathIsSameRootA',\
PathIsSameRootW,'PathIsSameRootW',\
PathIsSystemFolderA,'PathIsSystemFolderA',\
PathIsSystemFolderW,'PathIsSystemFolderW',\
PathIsUNCA,'PathIsUNCA',\
PathIsUNCServerA,'PathIsUNCServerA',\
PathIsUNCServerShareA,'PathIsUNCServerShareA',\
PathIsUNCServerShareW,'PathIsUNCServerShareW',\
PathIsUNCServerW,'PathIsUNCServerW',\
PathIsUNCW,'PathIsUNCW',\
PathIsURLA,'PathIsURLA',\
PathIsURLW,'PathIsURLW',\
PathMakePrettyA,'PathMakePrettyA',\
PathMakePrettyW,'PathMakePrettyW',\
PathMakeSystemFolderA,'PathMakeSystemFolderA',\
PathMakeSystemFolderW,'PathMakeSystemFolderW',\
PathMatchSpecA,'PathMatchSpecA',\
PathMatchSpecExA,'PathMatchSpecExA',\
PathMatchSpecExW,'PathMatchSpecExW',\
PathMatchSpecW,'PathMatchSpecW',\
PathParseIconLocationA,'PathParseIconLocationA',\
PathParseIconLocationW,'PathParseIconLocationW',\
PathQuoteSpacesA,'PathQuoteSpacesA',\
PathQuoteSpacesW,'PathQuoteSpacesW',\
PathRelativePathToA,'PathRelativePathToA',\
PathRelativePathToW,'PathRelativePathToW',\
PathRemoveArgsA,'PathRemoveArgsA',\
PathRemoveArgsW,'PathRemoveArgsW',\
PathRemoveBackslashA,'PathRemoveBackslashA',\
PathRemoveBackslashW,'PathRemoveBackslashW',\
PathRemoveBlanksA,'PathRemoveBlanksA',\
PathRemoveBlanksW,'PathRemoveBlanksW',\
PathRemoveExtensionA,'PathRemoveExtensionA',\
PathRemoveExtensionW,'PathRemoveExtensionW',\
PathRemoveFileSpecA,'PathRemoveFileSpecA',\
PathRemoveFileSpecW,'PathRemoveFileSpecW',\
PathRenameExtensionA,'PathRenameExtensionA',\
PathRenameExtensionW,'PathRenameExtensionW',\
PathSearchAndQualifyA,'PathSearchAndQualifyA',\
PathSearchAndQualifyW,'PathSearchAndQualifyW',\
PathSetDlgItemPathA,'PathSetDlgItemPathA',\
PathSetDlgItemPathW,'PathSetDlgItemPathW',\
PathSkipRootA,'PathSkipRootA',\
PathSkipRootW,'PathSkipRootW',\
PathStripPathA,'PathStripPathA',\
PathStripPathW,'PathStripPathW',\
PathStripToRootA,'PathStripToRootA',\
PathStripToRootW,'PathStripToRootW',\
PathUnExpandEnvStringsA,'PathUnExpandEnvStringsA',\
PathUnExpandEnvStringsW,'PathUnExpandEnvStringsW',\
PathUndecorateA,'PathUndecorateA',\
PathUndecorateW,'PathUndecorateW',\
PathUnmakeSystemFolderA,'PathUnmakeSystemFolderA',\
PathUnmakeSystemFolderW,'PathUnmakeSystemFolderW',\
PathUnquoteSpacesA,'PathUnquoteSpacesA',\
PathUnquoteSpacesW,'PathUnquoteSpacesW',\
QISearch,'QISearch',\
SHAllocShared,'SHAllocShared',\
SHAnsiToAnsi,'SHAnsiToAnsi',\
SHAnsiToUnicode,'SHAnsiToUnicode',\
SHAutoComplete,'SHAutoComplete',\
SHCopyKeyA,'SHCopyKeyA',\
SHCopyKeyW,'SHCopyKeyW',\
SHCreateMemStream,'SHCreateMemStream',\
SHCreateShellPalette,'SHCreateShellPalette',\
SHCreateStreamOnFileA,'SHCreateStreamOnFileA',\
SHCreateStreamOnFileEx,'SHCreateStreamOnFileEx',\
SHCreateStreamOnFileW,'SHCreateStreamOnFileW',\
SHCreateThread,'SHCreateThread',\
SHCreateThreadRef,'SHCreateThreadRef',\
SHCreateThreadWithHandle,'SHCreateThreadWithHandle',\
SHCreateWorkerWindowA,'SHCreateWorkerWindowA',\
SHCreateWorkerWindowW,'SHCreateWorkerWindowW',\
SHDeleteEmptyKeyA,'SHDeleteEmptyKeyA',\
SHDeleteEmptyKeyW,'SHDeleteEmptyKeyW',\
SHDeleteKeyA,'SHDeleteKeyA',\
SHDeleteKeyW,'SHDeleteKeyW',\
SHDeleteOrphanKeyA,'SHDeleteOrphanKeyA',\
SHDeleteOrphanKeyW,'SHDeleteOrphanKeyW',\
SHDeleteValueA,'SHDeleteValueA',\
SHDeleteValueW,'SHDeleteValueW',\
SHEnumKeyExA,'SHEnumKeyExA',\
SHEnumKeyExW,'SHEnumKeyExW',\
SHEnumValueA,'SHEnumValueA',\
SHEnumValueW,'SHEnumValueW',\
SHFormatDateTimeA,'SHFormatDateTimeA',\
SHFormatDateTimeW,'SHFormatDateTimeW',\
SHFreeShared,'SHFreeShared',\
SHGetInverseCMAP,'SHGetInverseCMAP',\
SHGetThreadRef,'SHGetThreadRef',\
SHGetValueA,'SHGetValueA',\
SHGetValueW,'SHGetValueW',\
SHGetViewStatePropertyBag,'SHGetViewStatePropertyBag',\
SHIsChildOrSelf,'SHIsChildOrSelf',\
SHIsLowMemoryMachine,'SHIsLowMemoryMachine',\
SHLoadIndirectString,'SHLoadIndirectString',\
SHLockShared,'SHLockShared',\
SHMessageBoxCheckA,'SHMessageBoxCheckA',\
SHMessageBoxCheckW,'SHMessageBoxCheckW',\
SHOpenRegStream2A,'SHOpenRegStream2A',\
SHOpenRegStream2W,'SHOpenRegStream2W',\
SHOpenRegStreamA,'SHOpenRegStreamA',\
SHOpenRegStreamW,'SHOpenRegStreamW',\
SHPinDllOfCLSID,'SHPinDllOfCLSID',\
SHQueryInfoKeyA,'SHQueryInfoKeyA',\
SHQueryInfoKeyW,'SHQueryInfoKeyW',\
SHQueryValueExA,'SHQueryValueExA',\
SHQueryValueExW,'SHQueryValueExW',\
SHRegCloseUSKey,'SHRegCloseUSKey',\
SHRegCreateUSKeyA,'SHRegCreateUSKeyA',\
SHRegCreateUSKeyW,'SHRegCreateUSKeyW',\
SHRegDeleteEmptyUSKeyA,'SHRegDeleteEmptyUSKeyA',\
SHRegDeleteEmptyUSKeyW,'SHRegDeleteEmptyUSKeyW',\
SHRegDeleteUSValueA,'SHRegDeleteUSValueA',\
SHRegDeleteUSValueW,'SHRegDeleteUSValueW',\
SHRegDuplicateHKey,'SHRegDuplicateHKey',\
SHRegEnumUSKeyA,'SHRegEnumUSKeyA',\
SHRegEnumUSKeyW,'SHRegEnumUSKeyW',\
SHRegEnumUSValueA,'SHRegEnumUSValueA',\
SHRegEnumUSValueW,'SHRegEnumUSValueW',\
SHRegGetBoolUSValueA,'SHRegGetBoolUSValueA',\
SHRegGetBoolUSValueW,'SHRegGetBoolUSValueW',\
SHRegGetBoolValueFromHKCUHKLM,'SHRegGetBoolValueFromHKCUHKLM',\
SHRegGetIntW,'SHRegGetIntW',\
SHRegGetPathA,'SHRegGetPathA',\
SHRegGetPathW,'SHRegGetPathW',\
SHRegGetUSValueA,'SHRegGetUSValueA',\
SHRegGetUSValueW,'SHRegGetUSValueW',\
SHRegGetValueA,'SHRegGetValueA',\
SHRegGetValueFromHKCUHKLM,'SHRegGetValueFromHKCUHKLM',\
SHRegGetValueW,'SHRegGetValueW',\
SHRegOpenUSKeyA,'SHRegOpenUSKeyA',\
SHRegOpenUSKeyW,'SHRegOpenUSKeyW',\
SHRegQueryInfoUSKeyA,'SHRegQueryInfoUSKeyA',\
SHRegQueryInfoUSKeyW,'SHRegQueryInfoUSKeyW',\
SHRegQueryUSValueA,'SHRegQueryUSValueA',\
SHRegQueryUSValueW,'SHRegQueryUSValueW',\
SHRegSetPathA,'SHRegSetPathA',\
SHRegSetPathW,'SHRegSetPathW',\
SHRegSetUSValueA,'SHRegSetUSValueA',\
SHRegSetUSValueW,'SHRegSetUSValueW',\
SHRegWriteUSValueA,'SHRegWriteUSValueA',\
SHRegWriteUSValueW,'SHRegWriteUSValueW',\
SHRegisterValidateTemplate,'SHRegisterValidateTemplate',\
SHReleaseThreadRef,'SHReleaseThreadRef',\
SHRunIndirectRegClientCommand,'SHRunIndirectRegClientCommand',\
SHSendMessageBroadcastA,'SHSendMessageBroadcastA',\
SHSendMessageBroadcastW,'SHSendMessageBroadcastW',\
SHSetThreadRef,'SHSetThreadRef',\
SHSetValueA,'SHSetValueA',\
SHSetValueW,'SHSetValueW',\
SHSkipJunction,'SHSkipJunction',\
SHStrDupA,'SHStrDupA',\
SHStrDupW,'SHStrDupW',\
SHStripMneumonicA,'SHStripMneumonicA',\
SHStripMneumonicW,'SHStripMneumonicW',\
SHUnicodeToAnsi,'SHUnicodeToAnsi',\
SHUnicodeToAnsiCP,'SHUnicodeToAnsiCP',\
SHUnicodeToUnicode,'SHUnicodeToUnicode',\
SHUnlockShared,'SHUnlockShared',\
StrCSpnA,'StrCSpnA',\
StrCSpnIA,'StrCSpnIA',\
StrCSpnIW,'StrCSpnIW',\
StrCSpnW,'StrCSpnW',\
StrCatBuffA,'StrCatBuffA',\
StrCatBuffW,'StrCatBuffW',\
StrCatChainW,'StrCatChainW',\
StrChrA,'StrChrA',\
StrChrIA,'StrChrIA',\
StrChrIW,'StrChrIW',\
StrChrNIW,'StrChrNIW',\
StrChrNW,'StrChrNW',\
StrChrW,'StrChrW',\
StrCmpCA,'StrCmpCA',\
StrCmpCW,'StrCmpCW',\
StrCmpICA,'StrCmpICA',\
StrCmpICW,'StrCmpICW',\
StrCmpIW,'StrCmpIW',\
StrCmpLogicalW,'StrCmpLogicalW',\
StrCmpNA,'StrCmpNA',\
StrCmpNCA,'StrCmpNCA',\
StrCmpNCW,'StrCmpNCW',\
StrCmpNIA,'StrCmpNIA',\
StrCmpNICA,'StrCmpNICA',\
StrCmpNICW,'StrCmpNICW',\
StrCmpNIW,'StrCmpNIW',\
StrCmpNW,'StrCmpNW',\
StrCmpW,'StrCmpW',\
StrCpyNW,'StrCpyNW',\
StrCpyW,'StrCpyW',\
StrDupA,'StrDupA',\
StrDupW,'StrDupW',\
StrFormatByteSize64A,'StrFormatByteSize64A',\
StrFormatByteSizeA,'StrFormatByteSizeA',\
StrFormatByteSizeEx,'StrFormatByteSizeEx',\
StrFormatByteSizeW,'StrFormatByteSizeW',\
StrFormatKBSizeA,'StrFormatKBSizeA',\
StrFormatKBSizeW,'StrFormatKBSizeW',\
StrFromTimeIntervalA,'StrFromTimeIntervalA',\
StrFromTimeIntervalW,'StrFromTimeIntervalW',\
StrIsIntlEqualA,'StrIsIntlEqualA',\
StrIsIntlEqualW,'StrIsIntlEqualW',\
StrNCatA,'StrNCatA',\
StrNCatW,'StrNCatW',\
StrPBrkA,'StrPBrkA',\
StrPBrkW,'StrPBrkW',\
StrRChrA,'StrRChrA',\
StrRChrIA,'StrRChrIA',\
StrRChrIW,'StrRChrIW',\
StrRChrW,'StrRChrW',\
StrRStrIA,'StrRStrIA',\
StrRStrIW,'StrRStrIW',\
StrRetToBSTR,'StrRetToBSTR',\
StrRetToBufA,'StrRetToBufA',\
StrRetToBufW,'StrRetToBufW',\
StrRetToStrA,'StrRetToStrA',\
StrRetToStrW,'StrRetToStrW',\
StrSpnA,'StrSpnA',\
StrSpnW,'StrSpnW',\
StrStrA,'StrStrA',\
StrStrIA,'StrStrIA',\
StrStrIW,'StrStrIW',\
StrStrNIW,'StrStrNIW',\
StrStrNW,'StrStrNW',\
StrStrW,'StrStrW',\
StrToInt64ExA,'StrToInt64ExA',\
StrToInt64ExW,'StrToInt64ExW',\
StrToIntA,'StrToIntA',\
StrToIntExA,'StrToIntExA',\
StrToIntExW,'StrToIntExW',\
StrToIntW,'StrToIntW',\
StrTrimA,'StrTrimA',\
StrTrimW,'StrTrimW',\
UrlApplySchemeA,'UrlApplySchemeA',\
UrlApplySchemeW,'UrlApplySchemeW',\
UrlCanonicalizeA,'UrlCanonicalizeA',\
UrlCanonicalizeW,'UrlCanonicalizeW',\
UrlCombineA,'UrlCombineA',\
UrlCombineW,'UrlCombineW',\
UrlCompareA,'UrlCompareA',\
UrlCompareW,'UrlCompareW',\
UrlCreateFromPathA,'UrlCreateFromPathA',\
UrlCreateFromPathW,'UrlCreateFromPathW',\
UrlEscapeA,'UrlEscapeA',\
UrlEscapeW,'UrlEscapeW',\
UrlFixupW,'UrlFixupW',\
UrlGetLocationA,'UrlGetLocationA',\
UrlGetLocationW,'UrlGetLocationW',\
UrlGetPartA,'UrlGetPartA',\
UrlGetPartW,'UrlGetPartW',\
UrlHashA,'UrlHashA',\
UrlHashW,'UrlHashW',\
UrlIsA,'UrlIsA',\
UrlIsNoHistoryA,'UrlIsNoHistoryA',\
UrlIsNoHistoryW,'UrlIsNoHistoryW',\
UrlIsOpaqueA,'UrlIsOpaqueA',\
UrlIsOpaqueW,'UrlIsOpaqueW',\
UrlIsW,'UrlIsW',\
UrlUnescapeA,'UrlUnescapeA',\
UrlUnescapeW,'UrlUnescapeW',\
WhichPlatform,'WhichPlatform',\
wnsprintfA,'wnsprintfA',\
wnsprintfW,'wnsprintfW',\
wvnsprintfA,'wvnsprintfA',\
wvnsprintfW,'wvnsprintfW'

if defined APP_UNICODE
    SZ_CONTENTTYPE_HTML equ SZ_CONTENTTYPE_HTMLW
    SZ_CONTENTTYPE_CDF  equ SZ_CONTENTTYPE_CDFW
    PARSEDURL fix PARSEDURLW
else
    SZ_CONTENTTYPE_HTML equ SZ_CONTENTTYPE_HTMLA
    SZ_CONTENTTYPE_CDF  equ SZ_CONTENTTYPE_CDFA
    PARSEDURL fix PARSEDURLA
end if

SHRegGetInt equ SHRegGetIntW
StrCatChain equ StrCatChainW
StrChrN equ StrChrNW
StrChrNI equ StrChrNIW
StrCmp equ StrCmpW
StrCmpI equ StrCmpIW
StrCmpLogical equ StrCmpLogicalW
StrCpy equ StrCpyW
StrCpyN equ StrCpyNW
StrFormatByteSize64 equ StrFormatByteSize64A
StrStrN equ StrStrNW
StrStrNI equ StrStrNIW
UrlFixup equ UrlFixupW

api AssocQueryKey,\
    AssocQueryString,\
    AssocQueryStringByKey,\
    ChrCmpI,\
    GetAcceptLanguages,\
    GUIDFromString,\
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
    PathFileExistsAndAttributes,\
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
    SHCreateWorkerWindow,\
    SHDeleteEmptyKey,\
    SHDeleteKey,\
    SHDeleteOrphanKey,\
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
    StrFormatByteSize,\
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

;======================= Undocumented functions (unknown arguments) =======================;
;SHPropertyBag_ReadStrAlloc,'SHPropertyBag_ReadStrAlloc',\
;SHPropertyBag_WriteBSTR,'SHPropertyBag_WriteBSTR',\

end if ;SHLWAPI_INC
