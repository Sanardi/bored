; =====================================================;
;                                                      ;
;  shlwapi.inc for Easy Code 2.0 64-bit Masm projects  ;
;                  (version 1.0.1)                     ;
;                                                      ;
;          Copyright © Ramon Sala - 2017-2018          ;
;                                                      ;
; =====================================================;

IFNDEF SHLWAPI_INC
SHLWAPI_INC     EQU     1

SFBS_FLAGS_ROUND_TO_NEAREST_DISPLAYED_DIGIT             EQU     00001H
SFBS_FLAGS_TRUNCATE_UNDISPLAYED_DECIMAL_DIGITS          EQU     00002H
STIF_DEFAULT                                            EQU     000000000H
STIF_SUPPORT_HEX                                        EQU     000000001H

SZ_CONTENTTYPE_HTMLA                                    EQU     A("text/html")
SZ_CONTENTTYPE_HTMLW                                    EQU     L("text/html")
SZ_CONTENTTYPE_CDFA                                     EQU     A("application/x-cdf")
SZ_CONTENTTYPE_CDFW                                     EQU     L("application/x-cdf")

GCT_INVALID                                             EQU     00000H
GCT_LFNCHAR                                             EQU     00001H
GCT_SHORTCHAR                                           EQU     00002H
GCT_WILD                                                EQU     00004H
GCT_SEPARATOR                                           EQU     00008H

PMSF_NORMAL                                             EQU     000000000H
PMSF_MULTIPLE                                           EQU     000000001H
PMSF_DONT_STRIP_SPACES                                  EQU     000010000H

URL_SCHEME_INVALID                                      EQU     (-1)
URL_SCHEME_UNKNOWN                                      EQU     0
URL_SCHEME_FTP                                          EQU     01H
URL_SCHEME_HTTP                                         EQU     02H
URL_SCHEME_GOPHER                                       EQU     03H
URL_SCHEME_MAILTO                                       EQU     04H
URL_SCHEME_NEWS                                         EQU     05H
URL_SCHEME_NNTP                                         EQU     06H
URL_SCHEME_TELNET                                       EQU     07H
URL_SCHEME_WAIS                                         EQU     08H
URL_SCHEME_FILE                                         EQU     09H
URL_SCHEME_MK                                           EQU     0AH
URL_SCHEME_HTTPS                                        EQU     0BH
URL_SCHEME_SHELL                                        EQU     0CH
URL_SCHEME_SNEWS                                        EQU     0DH
URL_SCHEME_LOCAL                                        EQU     0EH
URL_SCHEME_JAVASCRIPT                                   EQU     0FH
URL_SCHEME_VBSCRIPT                                     EQU     010H
URL_SCHEME_ABOUT                                        EQU     011H
URL_SCHEME_RES                                          EQU     012H
URL_SCHEME_MSSHELLROOTED                                EQU     013H
URL_SCHEME_MSSHELLIDLIST                                EQU     014H
URL_SCHEME_MSHELP                                       EQU     015H
URL_SCHEME_MSSHELLDEVICE                                EQU     016H
URL_SCHEME_WILDCARD                                     EQU     017H
URL_SCHEME_SEARCH_MS                                    EQU     018H
URL_SCHEME_SEARCH                                       EQU     019H
URL_SCHEME_KNOWNFOLDER                                  EQU     01AH
URL_SCHEME_MAXVALUE                                     EQU     01BH

URL_PART_NONE                                           EQU     00H
URL_PART_SCHEME                                         EQU     01H
URL_PART_HOSTNAME                                       EQU     02H
URL_PART_USERNAME                                       EQU     03H
URL_PART_PASSWORD                                       EQU     04H
URL_PART_PORT                                           EQU     05H
URL_PART_QUERY                                          EQU     06H

URLIS_URL                                               EQU     00H
URLIS_OPAQUE                                            EQU     01H
URLIS_NOHISTORY                                         EQU     02H
URLIS_FILEURL                                           EQU     03H
URLIS_APPLIABLE                                         EQU     04H
URLIS_DIRECTORY                                         EQU     05H
URLIS_HASQUERY                                          EQU     06H

URL_UNESCAPE                                            EQU     010000000H
URL_ESCAPE_UNSAFE                                       EQU     020000000H
URL_PLUGGABLE_PROTOCOL                                  EQU     040000000H
URL_WININET_COMPATIBILITY                               EQU     080000000H
URL_DONT_ESCAPE_EXTRA_INFO                              EQU     002000000H
URL_DONT_UNESCAPE_EXTRA_INFO                            EQU     URL_DONT_ESCAPE_EXTRA_INFO
URL_BROWSER_MODE                                        EQU     URL_DONT_ESCAPE_EXTRA_INFO
URL_ESCAPE_SPACES_ONLY                                  EQU     004000000H
URL_DONT_SIMPLIFY                                       EQU     008000000H
URL_NO_META                                             EQU     URL_DONT_SIMPLIFY
URL_UNESCAPE_INPLACE                                    EQU     000100000H
URL_CONVERT_IF_DOSPATH                                  EQU     000200000H
URL_UNESCAPE_HIGH_ANSI_ONLY                             EQU     000400000H
URL_INTERNAL_PATH                                       EQU     000800000H
URL_FILE_USE_PATHURL                                    EQU     000010000H
URL_DONT_UNESCAPE                                       EQU     000020000H
URL_ESCAPE_AS_UTF8                                      EQU     000040000H
URL_UNESCAPE_AS_UTF8                                    EQU     URL_ESCAPE_AS_UTF8
URL_ESCAPE_ASCII_URI_COMPONENT                          EQU     000080000H
URL_ESCAPE_URI_COMPONENT                                EQU     (URL_ESCAPE_ASCII_URI_COMPONENT OR URL_ESCAPE_AS_UTF8)
URL_UNESCAPE_URI_COMPONENT                              EQU     URL_UNESCAPE_AS_UTF8
URL_ESCAPE_PERCENT                                      EQU     000001000H
URL_ESCAPE_SEGMENT_ONLY                                 EQU     000002000H
URL_PARTFLAG_KEEPSCHEME                                 EQU     000000001H
URL_APPLY_DEFAULT                                       EQU     000000001H
URL_APPLY_GUESSSCHEME                                   EQU     000000002H
URL_APPLY_GUESSFILE                                     EQU     000000004H
URL_APPLY_FORCEAPPLY                                    EQU     000000008H

SRRF_RT_REG_NONE                                        EQU     000000001H
SRRF_RT_REG_SZ                                          EQU     000000002H
SRRF_RT_REG_EXPAND_SZ                                   EQU     000000004H
SRRF_RT_REG_BINARY                                      EQU     000000008H
SRRF_RT_REG_DWORD                                       EQU     000000010H
SRRF_RT_REG_MULTI_SZ                                    EQU     000000020H
SRRF_RT_REG_QWORD                                       EQU     000000040H
SRRF_RT_DWORD                                           EQU     (SRRF_RT_REG_BINARY OR SRRF_RT_REG_DWORD)
SRRF_RT_QWORD                                           EQU     (SRRF_RT_REG_BINARY OR SRRF_RT_REG_QWORD)
SRRF_RT_ANY                                             EQU     00000ffffH
SRRF_RM_ANY                                             EQU     000000000H
SRRF_RM_NORMAL                                          EQU     000010000H
SRRF_RM_SAFE                                            EQU     000020000H
SRRF_RM_SAFENETWORK                                     EQU     000040000H
SRRF_NOEXPAND                                           EQU     010000000H
SRRF_ZEROONFAILURE                                      EQU     020000000H
SRRF_NOVIRT                                             EQU     040000000H

SHREGDEL_DEFAULT                                        EQU     000000000H
SHREGDEL_HKCU                                           EQU     000000001H
SHREGDEL_HKLM                                           EQU     000000010H
SHREGDEL_BOTH                                           EQU     000000011H

SHREGENUM_DEFAULT                                       EQU     000000000H
SHREGENUM_HKCU                                          EQU     000000001H
SHREGENUM_HKLM                                          EQU     000000010H
SHREGENUM_BOTH                                          EQU     000000011H

SHREGSET_HKCU                                           EQU     000000001H
SHREGSET_FORCE_HKCU                                     EQU     000000002H
SHREGSET_HKLM                                           EQU     000000004H
SHREGSET_FORCE_HKLM                                     EQU     000000008H
SHREGSET_DEFAULT                                        EQU     (SHREGSET_FORCE_HKCU OR SHREGSET_HKLM)

ASSOCF_NONE                                             EQU     000000000H
ASSOCF_INIT_NOREMAPCLSID                                EQU     000000001H
ASSOCF_INIT_BYEXENAME                                   EQU     000000002H
ASSOCF_OPEN_BYEXENAME                                   EQU     000000002H
ASSOCF_INIT_DEFAULTTOSTAR                               EQU     000000004H
ASSOCF_INIT_DEFAULTTOFOLDER                             EQU     000000008H
ASSOCF_NOUSERSETTINGS                                   EQU     000000010H
ASSOCF_NOTRUNCATE                                       EQU     000000020H
ASSOCF_VERIFY                                           EQU     000000040H
ASSOCF_REMAPRUNDLL                                      EQU     000000080H
ASSOCF_NOFIXUPS                                         EQU     000000100H
ASSOCF_IGNOREBASECLASS                                  EQU     000000200H
ASSOCF_INIT_IGNOREUNKNOWN                               EQU     000000400H
ASSOCF_INIT_FIXED_PROGID                                EQU     000000800H
ASSOCF_IS_PROTOCOL                                      EQU     000001000H
ASSOCF_INIT_FOR_FILE                                    EQU     000002000H

ASSOCSTR_COMMAND                                        EQU     1
ASSOCSTR_EXECUTABLE                                     EQU     02H
ASSOCSTR_FRIENDLYDOCNAME                                EQU     03H
ASSOCSTR_FRIENDLYAPPNAME                                EQU     04H
ASSOCSTR_NOOPEN                                         EQU     05H
ASSOCSTR_SHELLNEWVALUE                                  EQU     06H
ASSOCSTR_DDECOMMAND                                     EQU     07H
ASSOCSTR_DDEIFEXEC                                      EQU     08H
ASSOCSTR_DDEAPPLICATION                                 EQU     09H
ASSOCSTR_DDETOPIC                                       EQU     0AH
ASSOCSTR_INFOTIP                                        EQU     0BH
ASSOCSTR_QUICKTIP                                       EQU     0CH
ASSOCSTR_TILEINFO                                       EQU     0DH
ASSOCSTR_CONTENTTYPE                                    EQU     0EH
ASSOCSTR_DEFAULTICON                                    EQU     0FH
ASSOCSTR_SHELLEXTENSION                                 EQU     010H
ASSOCSTR_DROPTARGET                                     EQU     011H
ASSOCSTR_DELEGATEEXECUTE                                EQU     012H
ASSOCSTR_SUPPORTED_URI_PROTOCOLS                        EQU     013H
ASSOCSTR_PROGID                                         EQU     014H
ASSOCSTR_APPID                                          EQU     015H
ASSOCSTR_APPPUBLISHER                                   EQU     016H
ASSOCSTR_APPICONREFERENCE                               EQU     017H
ASSOCSTR_MAX                                            EQU     018H

ASSOCKEY_SHELLEXECCLASS                                 EQU     01H
ASSOCKEY_APP                                            EQU     02H
ASSOCKEY_CLASS                                          EQU     03H
ASSOCKEY_BASECLASS                                      EQU     04H
ASSOCKEY_MAX                                            EQU     05H

ASSOCDATA_MSIDESCRIPTOR                                 EQU     01H
ASSOCDATA_NOACTIVATEHANDLER                             EQU     02H
ASSOCDATA_QUERYCLASSSTORE                               EQU     03H
ASSOCDATA_HASPERUSERASSOC                               EQU     04H
ASSOCDATA_EDITFLAGS                                     EQU     05H
ASSOCDATA_VALUE                                         EQU     06H
ASSOCDATA_MAX                                           EQU     07H

ASSOCENUM_NONE                                          EQU     00H

FTA_None                                                EQU     000000000H
FTA_Exclude                                             EQU     000000001H
FTA_Show                                                EQU     000000002H
FTA_HasExtension                                        EQU     000000004H
FTA_NoEdit                                              EQU     000000008H
FTA_NoRemove                                            EQU     000000010H
FTA_NoNewVerb                                           EQU     000000020H
FTA_NoEditVerb                                          EQU     000000040H
FTA_NoRemoveVerb                                        EQU     000000080H
FTA_NoEditDesc                                          EQU     000000100H
FTA_NoEditIcon                                          EQU     000000200H
FTA_NoEditDflt                                          EQU     000000400H
FTA_NoEditVerbCmd                                       EQU     000000800H
FTA_NoEditVerbExe                                       EQU     000001000H
FTA_NoDDE                                               EQU     000002000H
FTA_NoEditMIME                                          EQU     000008000H
FTA_OpenIsSafe                                          EQU     000010000H
FTA_AlwaysUnsafe                                        EQU     000020000H
FTA_NoRecentDocs                                        EQU     000100000H
FTA_SafeForElevation                                    EQU     000200000H
FTA_AlwaysUseDirectInvoke                               EQU     000400000H

SPMODE_SHELL                                            EQU     000000001H
SPMODE_DEBUGOUT                                         EQU     000000002H
SPMODE_TEST                                             EQU     000000004H
SPMODE_BROWSER                                          EQU     000000008H
SPMODE_FLUSH                                            EQU     000000010H
SPMODE_EVENT                                            EQU     000000020H
SPMODE_MSVM                                             EQU     000000040H
SPMODE_FORMATTEXT                                       EQU     000000080H
SPMODE_PROFILE                                          EQU     000000100H
SPMODE_DEBUGBREAK                                       EQU     000000200H
SPMODE_MSGTRACE                                         EQU     000000400H
SPMODE_PERFTAGS                                         EQU     000000800H
SPMODE_MEMWATCH                                         EQU     000001000H
SPMODE_DBMON                                            EQU     000002000H
SPMODE_MULTISTOP                                        EQU     000004000H
SPMODE_EVENTTRACE                                       EQU     000008000H

SHGVSPB_PERUSER                                         EQU     000000001H
SHGVSPB_ALLUSERS                                        EQU     000000002H
SHGVSPB_PERFOLDER                                       EQU     000000004H
SHGVSPB_ALLFOLDERS                                      EQU     000000008H
SHGVSPB_INHERIT                                         EQU     000000010H
SHGVSPB_ROAM                                            EQU     000000020H
SHGVSPB_NOAUTODEFAULTS                                  EQU     080000000H
SHGVSPB_FOLDER                                          EQU     (SHGVSPB_PERUSER OR SHGVSPB_PERFOLDER)
SHGVSPB_FOLDERNODEFAULTS                                EQU     (SHGVSPB_PERUSER OR SHGVSPB_PERFOLDER OR SHGVSPB_NOAUTODEFAULTS)
SHGVSPB_USERDEFAULTS                                    EQU     (SHGVSPB_PERUSER OR SHGVSPB_ALLFOLDERS)
SHGVSPB_GLOBALDEFAULTS                                  EQU     (SHGVSPB_ALLUSERS OR SHGVSPB_ALLFOLDERS)

FDTF_SHORTTIME                                          EQU     000000001H
FDTF_SHORTDATE                                          EQU     000000002H
FDTF_DEFAULT                                            EQU     (FDTF_SHORTDATE OR FDTF_SHORTTIME)
FDTF_LONGDATE                                           EQU     000000004H
FDTF_LONGTIME                                           EQU     000000008H
FDTF_RELATIVE                                           EQU     000000010H
FDTF_LTRDATE                                            EQU     000000100H
FDTF_RTLDATE                                            EQU     000000200H
FDTF_NOAUTOREADINGORDER                                 EQU     000000400H

OS_WINDOWS                                              EQU     0
OS_NT                                                   EQU     1
OS_WIN95ORGREATER                                       EQU     2
OS_NT4ORGREATER                                         EQU     3
OS_WIN98ORGREATER                                       EQU     5
OS_WIN98_GOLD                                           EQU     6
OS_WIN2000ORGREATER                                     EQU     7
OS_WIN2000PRO                                           EQU     8
OS_WIN2000SERVER                                        EQU     9
OS_WIN2000ADVSERVER                                     EQU     10
OS_WIN2000DATACENTER                                    EQU     11
OS_WIN2000TERMINAL                                      EQU     12
OS_EMBEDDED                                             EQU     13
OS_TERMINALCLIENT                                       EQU     14
OS_TERMINALREMOTEADMIN                                  EQU     15
OS_WIN95_GOLD                                           EQU     16
OS_MEORGREATER                                          EQU     17
OS_XPORGREATER                                          EQU     18
OS_HOME                                                 EQU     19
OS_PROFESSIONAL                                         EQU     20
OS_DATACENTER                                           EQU     21
OS_ADVSERVER                                            EQU     22
OS_SERVER                                               EQU     23
OS_TERMINALSERVER                                       EQU     24
OS_PERSONALTERMINALSERVER                               EQU     25
OS_FASTUSERSWITCHING                                    EQU     26
OS_WELCOMELOGONUI                                       EQU     27
OS_DOMAINMEMBER                                         EQU     28
OS_ANYSERVER                                            EQU     29
OS_WOW6432                                              EQU     30
OS_WEBSERVER                                            EQU     31
OS_SMALLBUSINESSSERVER                                  EQU     32
OS_TABLETPC                                             EQU     33
OS_SERVERADMINUI                                        EQU     34
OS_MEDIACENTER                                          EQU     35
OS_APPLIANCE                                            EQU     36

GLOBALCOUNTER_SEARCHMANAGER                             EQU     00H
GLOBALCOUNTER_SEARCHOPTIONS                             EQU     01H
GLOBALCOUNTER_FOLDERSETTINGSCHANGE                      EQU     02H
GLOBALCOUNTER_RATINGS                                   EQU     03H
GLOBALCOUNTER_APPROVEDSITES                             EQU     04H
GLOBALCOUNTER_RESTRICTIONS                              EQU     05H
GLOBALCOUNTER_SHELLSETTINGSCHANGED                      EQU     06H
GLOBALCOUNTER_SYSTEMPIDLCHANGE                          EQU     07H
GLOBALCOUNTER_OVERLAYMANAGER                            EQU     08H
GLOBALCOUNTER_QUERYASSOCIATIONS                         EQU     09H
GLOBALCOUNTER_IESESSIONS                                EQU     0AH
GLOBALCOUNTER_IEONLY_SESSIONS                           EQU     0BH
GLOBALCOUNTER_APPLICATION_DESTINATIONS                  EQU     0CH
__UNUSED_RECYCLE_WAS_GLOBALCOUNTER_CSCSYNCINPROGRESS    EQU     0DH
GLOBALCOUNTER_BITBUCKETNUMDELETERS                      EQU     0EH
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_SHARES                  EQU     0FH
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_A                 EQU     010H
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_B                 EQU     011H
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_C                 EQU     012H
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_D                 EQU     013H
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_E                 EQU     014H
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_F                 EQU     015H
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_G                 EQU     016H
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_H                 EQU     017H
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_I                 EQU     018H
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_J                 EQU     019H
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_K                 EQU     01AH
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_L                 EQU     01BH
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_M                 EQU     01CH
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_N                 EQU     01DH
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_O                 EQU     01EH
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_P                 EQU     01FH
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_Q                 EQU     020H
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_R                 EQU     021H
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_S                 EQU     022H
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_T                 EQU     023H
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_U                 EQU     024H
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_V                 EQU     025H
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_W                 EQU     026H
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_X                 EQU     027H
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_Y                 EQU     028H
GLOBALCOUNTER_RECYCLEDIRTYCOUNT_DRIVE_Z                 EQU     029H
__UNUSED_RECYCLE_WAS_GLOBALCOUNTER_RECYCLEDIRTYCOUNT_SERVERDRIVE EQU 02AH
__UNUSED_RECYCLE_WAS_GLOBALCOUNTER_RECYCLEGLOBALDIRTYCOUNT EQU  02BH
GLOBALCOUNTER_RECYCLEBINENUM                            EQU     02CH
GLOBALCOUNTER_RECYCLEBINCORRUPTED                       EQU     02DH
GLOBALCOUNTER_RATINGS_STATECOUNTER                      EQU     02EH
GLOBALCOUNTER_PRIVATE_PROFILE_CACHE                     EQU     02FH
GLOBALCOUNTER_INTERNETTOOLBAR_LAYOUT                    EQU     030H
GLOBALCOUNTER_FOLDERDEFINITION_CACHE                    EQU     031H
GLOBALCOUNTER_COMMONPLACES_LIST_CACHE                   EQU     032H
GLOBALCOUNTER_PRIVATE_PROFILE_CACHE_MACHINEWIDE         EQU     033H
GLOBALCOUNTER_ASSOCCHANGED                              EQU     034H
GLOBALCOUNTER_APP_ITEMS_STATE_STORE_CACHE               EQU     035H
GLOBALCOUNTER_SETTINGSYNC_ENABLED                       EQU     036H
GLOBALCOUNTER_APPSFOLDER_FILETYPEASSOCIATION_COUNTER    EQU     037H
GLOBALCOUNTER_USERINFOCHANGED                           EQU     038H
GLOBALCOUNTER_SYNC_ENGINE_INFORMATION_CACHE_MACHINEWIDE EQU     039H
GLOBALCOUNTER_MAXIMUMVALUE                              EQU     03AH

PLATFORM_UNKNOWN                                        EQU     0
PLATFORM_IE3                                            EQU     1
PLATFORM_BROWSERONLY                                    EQU     1
PLATFORM_INTEGRATED                                     EQU     2

ILMM_IE4                                                EQU     0

SHACF_DEFAULT                                           EQU     000000000H
SHACF_FILESYSTEM                                        EQU     000000001H
SHACF_URLALL                                            EQU     (SHACF_URLHISTORY OR SHACF_URLMRU)
SHACF_URLHISTORY                                        EQU     000000002H
SHACF_URLMRU                                            EQU     000000004H
SHACF_USETAB                                            EQU     000000008H
SHACF_FILESYS_ONLY                                      EQU     000000010H
SHACF_FILESYS_DIRS                                      EQU     000000020H
SHACF_VIRTUAL_NAMESPACE                                 EQU     000000040H
SHACF_AUTOSUGGEST_FORCE_ON                              EQU     010000000H
SHACF_AUTOSUGGEST_FORCE_OFF                             EQU     020000000H
SHACF_AUTOAPPEND_FORCE_ON                               EQU     040000000H
SHACF_AUTOAPPEND_FORCE_OFF                              EQU     080000000H

CTF_INSIST                                              EQU     000000001H
CTF_THREAD_REF                                          EQU     000000002H
CTF_PROCESS_REF                                         EQU     000000004H
CTF_COINIT_STA                                          EQU     000000008H
CTF_COINIT                                              EQU     000000008H
CTF_FREELIBANDEXIT                                      EQU     000000010H
CTF_REF_COUNTED                                         EQU     000000020H
CTF_WAIT_ALLOWCOM                                       EQU     000000040H
CTF_UNUSED                                              EQU     000000080H
CTF_INHERITWOW64                                        EQU     000000100H
CTF_WAIT_NO_REENTRANCY                                  EQU     000000200H
CTF_KEYBOARD_LOCALE                                     EQU     000000400H
CTF_OLEINITIALIZE                                       EQU     000000800H
CTF_COINIT_MTA                                          EQU     000001000H
CTF_NOADDREFLIB                                         EQU     000002000H

DLLVER_PLATFORM_WINDOWS                                 EQU     000000001H
DLLVER_PLATFORM_NT                                      EQU     000000002H

DLLVER_MAJOR_MASK                                       EQU     0FFFF000000000000H
DLLVER_MINOR_MASK                                       EQU     00000FFFF00000000H
DLLVER_BUILD_MASK                                       EQU     000000000FFFF0000H
DLLVER_QFE_MASK                                         EQU     0000000000000FFFFH


;======================================== Structures ======================================;
PARSEDURLA STRUCT ALIGNMODE
    cbSize      DD   ?
    pszProtocol XPTR ?
    cchProtocol DD   ?
    pszSuffix   XPTR ?
    cchSuffix   DD   ?
    nScheme     DD   ?
PARSEDURLA ENDS

PARSEDURLW STRUCT ALIGNMODE
    cbSize      DD   ?
    pszProtocol XPTR ?
    cchProtocol DD   ?
    pszSuffix   XPTR ?
    cchSuffix   DD   ?
    nScheme     DD   ?
PARSEDURLW ENDS

QITAB STRUCT ALIGNMODE
    piid     XPTR ?
    dwOffset DD   ?
QITAB ENDS

IFNDEF DLLVERSIONINFO
    DLLVERSIONINFO STRUCT ALIGNMODE
        cbSize         DD ?
        dwMajorVersion DD ?
        dwMinorVersion DD ?
        dwBuildNumber  DD ?
        dwPlatformID   DD ?
    DLLVERSIONINFO ENDS
ENDIF

DLLVERSIONINFO2 STRUCT ALIGNMODE
    info1      DLLVERSIONINFO <>
    dwFlags    DD    ?
    ullVersion REAL8 ?
DLLVERSIONINFO2 ENDS


;======================================== Functions =======================================;
AssocCreate PROTO :XWORD, :XWORD, :XWORD
AssocGetPerceivedType PROTO :XWORD, :XWORD, :XWORD, :XWORD
AssocIsDangerous PROTO :XWORD
AssocQueryKeyA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
AssocQueryKeyW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
AssocQueryStringA PROTO :XWORD, :XWORD, :XPTR, :XPTR, :XPTR, :XWORD
AssocQueryStringW PROTO :XWORD, :XWORD, :XPTR, :XPTR, :XPTR, :XWORD
AssocQueryStringByKeyA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
AssocQueryStringByKeyW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
ChrCmpIA PROTO :XWORD, :XWORD
ChrCmpIW PROTO :XWORD, :XWORD
ColorAdjustLuma PROTO :XWORD, :XWORD, :XWORD
ColorHLSToRGB PROTO :XWORD, :XWORD, :XWORD
ColorRGBToHLS PROTO :XWORD, :XWORD, :XWORD, :XWORD
ConnectToConnectionPoint PROTO :XPTR, :XWORD, :XWORD, :XPTR, :XPTR, :XPTR
DelayLoadFailureHook PROTO :XPTR, :XPTR
DllGetVersion PROTO :XPTR
GetAcceptLanguagesA PROTO :XWORD, :XWORD
GetAcceptLanguagesW PROTO :XWORD, :XWORD
GetMenuPosFromID PROTO :XWORD, :XWORD
HashData PROTO :XWORD, :XWORD, :XWORD, :XWORD
IStream_Copy PROTO :XPTR, :XPTR, :XWORD
IStream_Read PROTO :XPTR, :XPTR, :XWORD
IStream_ReadPidl PROTO :XPTR, :XPTR
IStream_ReadStr PROTO :XPTR, :XPTR
IStream_Reset PROTO :XPTR
IStream_Size PROTO :XPTR, :XPTR
IStream_Write PROTO :XPTR, :XPTR, :XWORD
IStream_WritePidl PROTO :XPTR, :XWORD
IStream_WriteStr PROTO :XPTR, :XPTR
IUnknown_AtomicRelease PROTO :XPTR
IUnknown_GetSite PROTO :XPTR, :XWORD, :XPTR
IUnknown_GetWindow PROTO :XPTR, :XPTR
IUnknown_QueryService PROTO :XPTR, :XWORD, :XWORD, :XPTR
IUnknown_Set PROTO :XPTR, :XPTR
IUnknown_SetSite PROTO :XPTR, :XPTR
IntlStrEqWorkerA PROTO :XWORD, :XWORD, :XWORD, :XWORD
IntlStrEqWorkerW PROTO :XWORD, :XWORD, :XWORD, :XWORD
IsCharSpaceA PROTO :XWORD
IsCharSpaceW PROTO :XWORD
IsInternetESCEnabled PROTO
IsOS PROTO :XWORD
MLLoadLibraryA PROTO :XPTR, :XWORD, :XWORD
MLLoadLibraryW PROTO :XPTR, :XWORD, :XWORD
ParseURLA PROTO :XPTR, :XPTR
ParseURLW PROTO :XPTR, :XPTR
PathAddBackslashA PROTO :XPTR
PathAddBackslashW PROTO :XPTR
PathAddExtensionA PROTO :XPTR, :XPTR
PathAddExtensionW PROTO :XPTR, :XPTR
PathAppendA PROTO :XPTR, :XPTR
PathAppendW PROTO :XPTR, :XPTR
PathBuildRootA PROTO :XPTR, :XPTR
PathBuildRootW PROTO :XPTR, :XWORD
PathCanonicalizeA PROTO :XPTR, :XPTR
PathCanonicalizeW PROTO :XPTR, :XPTR
PathCombineA PROTO :XPTR, :XPTR, :XPTR
PathCombineW PROTO :XPTR, :XPTR, :XPTR
PathCommonPrefixA PROTO :XPTR, :XPTR, :XPTR
PathCommonPrefixW PROTO :XPTR, :XPTR, :XPTR
PathCompactPathA PROTO :XWORD, :XPTR, :XWORD
PathCompactPathExA PROTO :XPTR, :XPTR, :XWORD, :XWORD
PathCompactPathExW PROTO :XPTR, :XPTR, :XWORD, :XWORD
PathCompactPathW PROTO :XWORD, :XPTR, :XPTR
PathCreateFromUrlA PROTO :XPTR, :XPTR, :XWORD, :XWORD
PathCreateFromUrlAlloc PROTO :XPTR, :XPTR, :XWORD
PathCreateFromUrlW PROTO :XPTR, :XPTR, :XWORD, :XWORD
PathFileExistsA PROTO :XPTR
PathFileExistsW PROTO :XPTR
PathFindExtensionA PROTO :XPTR
PathFindExtensionW PROTO :XPTR
PathFindFileNameA PROTO :XPTR
PathFindFileNameW PROTO :XPTR
PathFindNextComponentA PROTO :XPTR
PathFindNextComponentW PROTO :XPTR
PathFindOnPathA PROTO :XPTR, :XPTR
PathFindOnPathW PROTO :XPTR, :XPTR
PathFindSuffixArrayA PROTO :XPTR, :XPTR, :XWORD
PathFindSuffixArrayW PROTO :XPTR, :XPTR, :XWORD
PathGetArgsA PROTO :XPTR
PathGetArgsW PROTO :XPTR
PathGetCharTypeA PROTO :XWORD
PathGetCharTypeW PROTO :XWORD
PathGetDriveNumberA PROTO :XPTR
PathGetDriveNumberW PROTO :XPTR
PathIsContentTypeA PROTO :XPTR, :XPTR
PathIsContentTypeW PROTO :XPTR, :XPTR
PathIsDirectoryA PROTO :XPTR
PathIsDirectoryEmptyA PROTO :XPTR
PathIsDirectoryEmptyW PROTO :XPTR
PathIsDirectoryW PROTO :XPTR
PathIsFileSpecA PROTO :XPTR
PathIsFileSpecW PROTO :XPTR
PathIsLFNFileSpecA PROTO :XPTR
PathIsLFNFileSpecW PROTO :XPTR
PathIsNetworkPathA PROTO :XPTR
PathIsNetworkPathW PROTO :XPTR
PathIsPrefixA PROTO :XPTR, :XPTR
PathIsPrefixW PROTO :XPTR, :XPTR
PathIsRelativeA PROTO :XPTR
PathIsRelativeW PROTO :XPTR
PathIsRootA PROTO :XPTR
PathIsRootW PROTO :XPTR
PathIsSameRootA PROTO :XPTR, :XPTR
PathIsSameRootW PROTO :XPTR, :XPTR
PathIsSystemFolderA PROTO :XPTR, :XPTR
PathIsSystemFolderW PROTO :XPTR, :XPTR
PathIsUNCA PROTO :XWORD
PathIsUNCServerA PROTO :XWORD
PathIsUNCServerShareA PROTO :XWORD
PathIsUNCServerShareW PROTO :XWORD
PathIsUNCServerW PROTO :XWORD
PathIsUNCW PROTO :XWORD
PathIsURLA PROTO :XPTR
PathIsURLW PROTO :XPTR
PathMakePrettyA PROTO :XWORD
PathMakePrettyW PROTO :XWORD
PathMakeSystemFolderA PROTO :XWORD
PathMakeSystemFolderW PROTO :XWORD
PathMatchSpecA PROTO :XWORD, :XWORD
PathMatchSpecExA PROTO :XPTR, :XPTR, :XWORD
PathMatchSpecExW PROTO :XPTR, :XPTR, :XWORD
PathMatchSpecW PROTO :XWORD, :XWORD
PathParseIconLocationA PROTO :XWORD
PathParseIconLocationW PROTO :XWORD
PathQuoteSpacesA PROTO :XWORD
PathQuoteSpacesW PROTO :XWORD
PathRelativePathToA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
PathRelativePathToW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
PathRemoveArgsA PROTO :XWORD
PathRemoveArgsW PROTO :XWORD
PathRemoveBackslashA PROTO :XWORD
PathRemoveBackslashW PROTO :XWORD
PathRemoveBlanksA PROTO :XWORD
PathRemoveBlanksW PROTO :XWORD
PathRemoveExtensionA PROTO :XWORD
PathRemoveExtensionW PROTO :XWORD
PathRemoveFileSpecA PROTO :XWORD
PathRemoveFileSpecW PROTO :XWORD
PathRenameExtensionA PROTO :XWORD, :XWORD
PathRenameExtensionW PROTO :XWORD, :XWORD
PathSearchAndQualifyA PROTO :XWORD, :XWORD, :XWORD
PathSearchAndQualifyW PROTO :XWORD, :XWORD, :XWORD
PathSetDlgItemPathA PROTO :XWORD, :XWORD, :XWORD
PathSetDlgItemPathW PROTO :XWORD, :XWORD, :XWORD
PathSkipRootA PROTO :XWORD
PathSkipRootW PROTO :XWORD
PathStripPathA PROTO :XWORD
PathStripPathW PROTO :XWORD
PathStripToRootA PROTO :XWORD
PathStripToRootW PROTO :XWORD
PathUnExpandEnvStringsA PROTO :XWORD, :XWORD, :XWORD
PathUnExpandEnvStringsW PROTO :XWORD, :XWORD, :XWORD
PathUndecorateA PROTO :XWORD
PathUndecorateW PROTO :XWORD
PathUnmakeSystemFolderA PROTO :XWORD
PathUnmakeSystemFolderW PROTO :XWORD
PathUnquoteSpacesA PROTO :XWORD
PathUnquoteSpacesW PROTO :XWORD
QISearch PROTO :XPTR, :XPTR, :XPTR, :XPTR
SHAllocShared PROTO :XWORD, :XWORD, :XWORD
SHAnsiToAnsi PROTO :XPTR, :XPTR, :XWORD
SHAnsiToUnicode PROTO :XPTR, :XPTR, :XWORD
SHAutoComplete PROTO :XWORD, :XWORD
SHCopyKeyA PROTO :XWORD, :XWORD, :XWORD, :XWORD
SHCopyKeyW PROTO :XWORD, :XWORD, :XWORD, :XWORD
SHCreateMemStream PROTO :XPTR, :XWORD
SHCreateShellPalette PROTO :XWORD
SHCreateStreamOnFileA PROTO :XWORD, :XWORD, :XWORD
SHCreateStreamOnFileEx PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
SHCreateStreamOnFileW PROTO :XWORD, :XWORD, :XWORD
SHCreateThread PROTO :XWORD, :XWORD, :XWORD, :XWORD
SHCreateThreadRef PROTO :XWORD, :XWORD
SHCreateThreadWithHandle PROTO :XPTR, :XPTR, :XWORD, :XPTR, :XWORD
SHDeleteEmptyKeyA PROTO :XWORD, :XWORD
SHDeleteEmptyKeyW PROTO :XWORD, :XWORD
SHDeleteKeyA PROTO :XWORD, :XWORD
SHDeleteKeyW PROTO :XWORD, :XWORD
SHDeleteValueA PROTO :XWORD, :XWORD, :XWORD
SHDeleteValueW PROTO :XWORD, :XWORD, :XWORD
SHEnumKeyExA PROTO :XWORD, :XWORD, :XWORD, :XWORD
SHEnumKeyExW PROTO :XWORD, :XWORD, :XWORD, :XWORD
SHEnumValueA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
SHEnumValueW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
SHFormatDateTimeA PROTO :XWORD, :XPTR, :XWORD
SHFormatDateTimeW PROTO :XWORD, :XPTR, :XWORD
SHFreeShared PROTO :XWORD, :XWORD
SHGetInverseCMAP PROTO :XWORD, :XWORD
SHGetThreadRef PROTO :XWORD
SHGetValueA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
SHGetValueW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
SHGetViewStatePropertyBag PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
SHIsChildOrSelf PROTO :XWORD, :XWORD
SHIsLowMemoryMachine PROTO :XWORD
SHLoadIndirectString PROTO :XWORD, :XWORD, :XWORD, :XWORD
SHLockShared PROTO :XWORD, :XWORD
SHMessageBoxCheckA PROTO :XWORD, :XPTR, :XPTR, :XWORD, :XWORD, :XPTR
SHMessageBoxCheckW PROTO :XWORD, :XPTR, :XPTR, :XWORD, :XWORD, :XPTR
SHOpenRegStream2A PROTO :XWORD, :XWORD, :XWORD, :XWORD
SHOpenRegStream2W PROTO :XWORD, :XWORD, :XWORD, :XWORD
SHOpenRegStreamA PROTO :XWORD, :XWORD, :XWORD, :XWORD
SHOpenRegStreamW PROTO :XWORD, :XWORD, :XWORD, :XWORD
SHQueryInfoKeyA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
SHQueryInfoKeyW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
SHQueryValueExA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
SHQueryValueExW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
SHRegCloseUSKey PROTO :XWORD
SHRegCreateUSKeyA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
SHRegCreateUSKeyW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
SHRegDeleteEmptyUSKeyA PROTO :XWORD, :XWORD, :XWORD
SHRegDeleteEmptyUSKeyW PROTO :XWORD, :XWORD, :XWORD
SHRegDeleteUSValueA PROTO :XWORD, :XWORD, :XWORD
SHRegDeleteUSValueW PROTO :XWORD, :XWORD, :XWORD
SHRegDuplicateHKey PROTO :XWORD
SHRegEnumUSKeyA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
SHRegEnumUSKeyW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
SHRegEnumUSValueA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
SHRegEnumUSValueW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
SHRegGetBoolUSValueA PROTO :XWORD, :XWORD, :XWORD, :XWORD
SHRegGetBoolUSValueW PROTO :XWORD, :XWORD, :XWORD, :XWORD
SHRegGetIntW PROTO :XWORD, :XPTR, :XWORD
SHRegGetPathA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
SHRegGetPathW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
SHRegGetUSValueA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
SHRegGetUSValueW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
SHRegGetValueA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
SHRegGetValueW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
SHRegOpenUSKeyA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
SHRegOpenUSKeyW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
SHRegQueryInfoUSKeyA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
SHRegQueryInfoUSKeyW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
SHRegQueryUSValueA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
SHRegQueryUSValueW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
SHRegSetPathA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
SHRegSetPathW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
SHRegSetUSValueA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
SHRegSetUSValueW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
SHRegWriteUSValueA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
SHRegWriteUSValueW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
SHRegisterValidateTemplate PROTO :XWORD, :XWORD
SHReleaseThreadRef PROTO
SHRunIndirectRegClientCommand PROTO :XWORD, :XPTR
SHSendMessageBroadcastA PROTO :XWORD, :WPARAM, :LPARAM
SHSendMessageBroadcastW PROTO :XWORD, :WPARAM, :LPARAM
SHSetThreadRef PROTO :XWORD
SHSetValueA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
SHSetValueW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
SHSkipJunction PROTO :XWORD, :XWORD
SHStrDupA PROTO :XWORD, :XWORD
SHStrDupW PROTO :XWORD, :XWORD
SHStripMneumonicA PROTO :XPTR
SHStripMneumonicW PROTO :XPTR
SHUnicodeToAnsi PROTO :XPTR, :XPTR, :XWORD
SHUnicodeToUnicode PROTO :XPTR, :XPTR, :XWORD
SHUnlockShared PROTO :XWORD
IFNDEF ShellMessageBoxA
    ShellMessageBoxA PROTO :XWORD, :XWORD, :XPTR, :XPTR, :XWORD, :XPTR
ENDIF
IFNDEF ShellMessageBoxW
    ShellMessageBoxW PROTO :XWORD, :XWORD, :XPTR, :XPTR, :XWORD, :XPTR
ENDIF
StrCSpnA PROTO :XPTR, :XPTR
StrCSpnIA PROTO :XWORD, :XWORD
StrCSpnIW PROTO :XWORD, :XWORD
StrCSpnW PROTO :XPTR, :XPTR
StrCatBuffA PROTO :XWORD, :XWORD, :XWORD
StrCatBuffW PROTO :XWORD, :XWORD, :XWORD
StrCatChainW PROTO :XPTR, :XWORD, :XWORD, :XPTR
StrChrA PROTO :XWORD, :XWORD
StrChrIA PROTO :XWORD, :XWORD
StrChrIW PROTO :XWORD, :XWORD
StrChrNIW PROTO :XPTR, :XWORD, :XWORD
StrChrNW PROTO :XPTR, :XWORD, :XWORD
StrChrW PROTO :XWORD, :XWORD
StrCmpCA PROTO :XWORD, :XWORD
StrCmpCW PROTO :XWORD, :XWORD
StrCmpICA PROTO :XWORD, :XWORD
StrCmpICW PROTO :XWORD, :XWORD
StrCmpIW PROTO :XPTR, :XPTR
StrCmpLogicalW PROTO :XPTR, :XPTR
StrCmpNA PROTO :XWORD, :XWORD, :XWORD
StrCmpNCA PROTO :XPTR, :XPTR, :XWORD
StrCmpNCW PROTO :XPTR, :XPTR, :XWORD
StrCmpNIA PROTO :XWORD, :XWORD, :XWORD
StrCmpNICA PROTO :XPTR, :XPTR, :XWORD
StrCmpNICW PROTO :XPTR, :XPTR, :XWORD
StrCmpNIW PROTO :XWORD, :XWORD, :XWORD
StrCmpNW PROTO :XWORD, :XWORD, :XWORD
StrCmpW PROTO :XPTR, :XPTR
StrCpyNW PROTO :XPTR, :XPTR, :XWORD
StrCpyW PROTO :XPTR, :XPTR
StrDupA PROTO :XWORD
StrDupW PROTO :XWORD
StrFormatByteSize64A PROTO :XWORD, :XPTR, :XWORD
StrFormatByteSizeEx PROTO :XWORD, :XWORD, :XPTR, :XWORD
StrFormatByteSizeW PROTO :XWORD, :XWORD, :XWORD
StrFormatKBSizeA PROTO :XWORD, :XWORD, :XWORD, :XWORD
StrFormatKBSizeW PROTO :XWORD, :XWORD, :XWORD, :XWORD
StrFromTimeIntervalA PROTO :XWORD, :XWORD, :XWORD, :XWORD
StrFromTimeIntervalW PROTO :XWORD, :XWORD, :XWORD, :XWORD
StrIsIntlEqualA PROTO :XWORD, :XWORD, :XWORD, :XWORD
StrIsIntlEqualW PROTO :XWORD, :XWORD, :XWORD, :XWORD
StrNCatA PROTO :XWORD, :XWORD, :XWORD
StrNCatW PROTO :XWORD, :XWORD, :XWORD
StrPBrkA PROTO :XWORD, :XWORD
StrPBrkW PROTO :XWORD, :XWORD
StrRChrA PROTO :XWORD, :XWORD, :XWORD
StrRChrIA PROTO :XWORD, :XWORD, :XWORD
StrRChrIW PROTO :XWORD, :XWORD, :XWORD
StrRChrW PROTO :XWORD, :XWORD, :XWORD
StrRStrIA PROTO :XWORD, :XWORD, :XWORD
StrRStrIW PROTO :XWORD, :XWORD, :XWORD
StrRetToBSTR PROTO :XWORD, :XWORD, :XWORD
StrRetToBufA PROTO :XWORD, :XWORD, :XWORD, :XWORD
StrRetToBufW PROTO :XWORD, :XWORD, :XWORD, :XWORD
StrRetToStrA PROTO :XWORD, :XWORD, :XWORD
StrRetToStrW PROTO :XWORD, :XWORD, :XWORD
StrSpnA PROTO :XWORD, :XWORD
StrSpnW PROTO :XWORD, :XWORD
StrStrA PROTO :XWORD, :XWORD
StrStrIA PROTO :XWORD, :XWORD
StrStrIW PROTO :XWORD, :XWORD
StrStrNIW PROTO :XPTR, :XPTR, :XWORD
StrStrNW PROTO :XPTR, :XPTR, :XWORD
StrStrW PROTO :XWORD, :XWORD
StrToInt64ExA PROTO :XWORD, :XWORD, :XWORD
StrToInt64ExW PROTO :XWORD, :XWORD, :XWORD
StrToIntA PROTO :XWORD
StrToIntExA PROTO :XWORD, :XWORD, :XWORD
StrToIntExW PROTO :XWORD, :XWORD, :XWORD
StrToIntW PROTO :XWORD
StrTrimA PROTO :XWORD, :XWORD
StrTrimW PROTO :XWORD, :XWORD
UrlApplySchemeA PROTO :XWORD, :XWORD, :XWORD, :XWORD
UrlApplySchemeW PROTO :XWORD, :XWORD, :XWORD, :XWORD
UrlCanonicalizeA PROTO :XWORD, :XWORD, :XWORD, :XWORD
UrlCanonicalizeW PROTO :XWORD, :XWORD, :XWORD, :XWORD
UrlCombineA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
UrlCombineW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
UrlCompareA PROTO :XWORD, :XWORD, :XWORD
UrlCompareW PROTO :XWORD, :XWORD, :XWORD
UrlCreateFromPathA PROTO :XWORD, :XWORD, :XWORD, :XWORD
UrlCreateFromPathW PROTO :XWORD, :XWORD, :XWORD, :XWORD
UrlEscapeA PROTO :XWORD, :XWORD, :XWORD, :XWORD
UrlEscapeW PROTO :XWORD, :XWORD, :XWORD, :XWORD
UrlFixupW PROTO :XPTR, :XPTR, :XWORD
UrlGetLocationA PROTO :XWORD
UrlGetLocationW PROTO :XWORD
UrlGetPartA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
UrlGetPartW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
UrlHashA PROTO :XWORD, :XWORD, :XWORD
UrlHashW PROTO :XWORD, :XWORD, :XWORD
UrlIsA PROTO :XWORD, :XWORD
UrlIsNoHistoryA PROTO :XWORD
UrlIsNoHistoryW PROTO :XWORD
UrlIsOpaqueA PROTO :XWORD
UrlIsOpaqueW PROTO :XWORD
UrlIsW PROTO :XWORD, :XWORD
UrlUnescapeA PROTO :XWORD, :XWORD, :XWORD, :XWORD
UrlUnescapeW PROTO :XWORD, :XWORD, :XWORD, :XWORD
WhichPlatform PROTO
wnsprintfA PROTO :VARARG
wnsprintfW PROTO :VARARG
wvnsprintfA PROTO :XPTR, :XWORD, :XPTR, :XPTR
wvnsprintfW PROTO :XPTR, :XWORD, :XPTR, :XPTR

IF (NTDDI_VERSION GE NTDDI_WIN2K)
    IF (NTDDI_VERSION LE NTDDI_WIN7)
        IF (NTDDI_VERSION LT NTDDI_WIN7)
            DllGetClassObject PROTO :XPTR, :XPTR, :XPTR
        ENDIF
        SHDeleteOrphanKeyA PROTO :XWORD, :XPTR
        SHDeleteOrphanKeyW PROTO :XWORD, :XPTR
        MLFreeLibrary PROTO :XWORD
        IFDEF APP_UNICODE
            SHDeleteOrphanKey EQU <SHDeleteOrphanKeyW>
        ELSE
            SHDeleteOrphanKey EQU <SHDeleteOrphanKeyA>
        ENDIF
    ENDIF
ENDIF

IF (NTDDI_VERSION GE NTDDI_WINXP)
    GUIDFromStringA PROTO :XPTR, :XPTR
    GUIDFromStringW PROTO :XPTR, :XPTR
    IFDEF APP_UNICODE
        GUIDFromString EQU <GUIDFromStringW>
    ELSE
        GUIDFromString EQU <GUIDFromStringA>
    ENDIF
ENDIF

IF (NTDDI_VERSION GE NTDDI_WIN8)
    IUnknown_Exec PROTO :XPTR, :XPTR, :XWORD, :XWORD, :XPTR, :XPTR
    IUnknown_QueryStatus PROTO :XPTR, :XPTR, :XWORD, :XPTR, :XPTR
    PathFileExistsAndAttributesA PROTO :XPTR, :XWORD
    PathFileExistsAndAttributesW PROTO :XPTR, :XWORD
    SHRegGetBoolValueFromHKCUHKLM PROTO :XPTR, :XPTR, :XWORD
    SHRegGetValueFromHKCUHKLM PROTO :XPTR, :XPTR, :XWORD, :XWORD, :XPTR, :XWORD
    SHUnicodeToAnsiCP PROTO :XWORD, :XPTR, :XPTR, :XWORD
    IFDEF APP_UNICODE
        PathFileExistsAndAttributes EQU <PathFileExistsAndAttributesW>
    ELSE
        PathFileExistsAndAttributes EQU <PathFileExistsAndAttributesA>
    ENDIF
ENDIF

IF (NTDDI_VERSION GE NTDDI_WIN10)
    SHCreateWorkerWindowA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    SHCreateWorkerWindowW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    SHPinDllOfCLSID PROTO :XWORD
    IFDEF APP_UNICODE
        SHCreateWorkerWindow EQU <SHCreateWorkerWindowW>
    ELSE
        SHCreateWorkerWindow EQU <SHCreateWorkerWindowA>
    ENDIF
ENDIF

SHRegGetInt EQU <SHRegGetIntW>
StrCatChain EQU <StrCatChainW>
StrChrN EQU <StrChrNW>
StrChrNI EQU <StrChrNIW>
StrCmpI EQU <StrCmpIW>
StrCmpLogical EQU <StrCmpLogicalW>
StrCmp EQU <StrCmpW>
StrCpy EQU <StrCpyW>
StrCpyN EQU <StrCpyNW>
StrFormatByteSize EQU <StrFormatByteSizeW>
StrFormatByteSize64 EQU <StrFormatByteSize64A>
StrStrN EQU <StrStrNW>
StrStrNI EQU <StrStrNIW>
UrlFixup EQU <UrlFixupW>

IFDEF APP_UNICODE
    SZ_CONTENTTYPE_HTML EQU <SZ_CONTENTTYPE_HTMLW>
    SZ_CONTENTTYPE_CDF  EQU <SZ_CONTENTTYPE_CDFW>
    PARSEDURL EQU <PARSEDURLW>

    AssocQueryKey EQU <AssocQueryKeyW>
    AssocQueryString EQU <AssocQueryStringW>
    AssocQueryStringByKey EQU <AssocQueryStringByKeyW>
    AssocQueryString EQU <AssocQueryStringW>
    ChrCmpI EQU <ChrCmpIW>
    GetAcceptLanguages EQU <GetAcceptLanguagesW>
    IntlStrEqWorker EQU <IntlStrEqWorkerW>
    IsCharSpace EQU <IsCharSpaceW>
    MLLoadLibrary EQU <MLLoadLibraryW>
    ParseURL EQU <ParseURLW>
    PathAddBackslash EQU <PathAddBackslashW>
    PathAddExtension EQU <PathAddExtensionW>
    PathAppend EQU <PathAppendW>
    PathBuildRoot EQU <PathBuildRootW>
    PathCanonicalize EQU <PathCanonicalizeW>
    PathCombine EQU <PathCombineW>
    PathCommonPrefix EQU <PathCommonPrefixW>
    PathCompactPath EQU <PathCompactPathW>
    PathCompactPathEx EQU <PathCompactPathExW>
    PathCreateFromUrl EQU <PathCreateFromUrlW>
    PathFileExists EQU <PathFileExistsW>
    PathFindExtension EQU <PathFindExtensionW>
    PathFindFileName EQU <PathFindFileNameW>
    PathFindNextComponent EQU <PathFindNextComponentW>
    PathFindOnPath EQU <PathFindOnPathW>
    PathFindSuffixArray EQU <PathFindSuffixArrayW>
    PathGetArgs EQU <PathGetArgsW>
    PathGetCharType EQU <PathGetCharTypeW>
    PathGetDriveNumber EQU <PathGetDriveNumberW>
    PathIsContentType EQU <PathIsContentTypeW>
    PathIsDirectory EQU <IsDirectoryW>
    PathIsDirectoryEmpty EQU <PathIsDirectoryEmptyW>
    PathIsDirectoryEmpty EQU <PathIsDirectoryEmptyW>
    PathIsFileSpec EQU <PathIsFileSpecW>
    PathIsLFNFileSpec EQU <PathIsLFNFileSpecW>
    PathIsNetworkPath EQU <PathIsNetworkPathW>
    PathIsPrefix EQU <PathIsPrefixW>
    PathIsRelative EQU <PathIsRelativeW>
    PathIsRoot EQU <PathIsRootW>
    PathIsSameRoot EQU <PathIsSameRootW>
    PathIsSystemFolder EQU <PathIsSystemFolderW>
    PathIsUNC EQU <PathIsUNCW>
    PathIsUNCServerShare EQU <PathIsUNCServerShareW>
    PathIsUNCServer EQU <PathIsUNCServerW>
    PathIsUNC EQU <PathIsUNCW>
    PathIsURL EQU <PathIsURLW>
    PathMakePretty EQU <PathMakePrettyW>
    PathMakePretty EQU <PathMakePrettyW>
    PathMakeSystemFolder EQU <PathMakeSystemFolderW>
    PathMatchSpec EQU <PathMatchSpecW>
    PathMatchSpecEx EQU <PathMatchSpecExW>
    PathParseIconLocation EQU <PathParseIconLocationW>
    PathQuoteSpaces EQU <PathQuoteSpacesW>
    PathRelativePathTo EQU <PathRelativePathToW>
    PathRemoveArgs EQU <PathRemoveArgsW>
    PathRemoveBackslash EQU <PathRemoveBackslashW>
    PathRemoveBlanks EQU <PathRemoveBlanksW>
    PathRemoveExtension EQU <PathRemoveExtensionW>
    PathRemoveFileSpec EQU <PathRemoveFileSpecW>
    PathRenameExtension EQU <PathRenameExtensionW>
    PathSearchAndQualify EQU <PathSearchAndQualifyW>
    PathSetDlgItemPath EQU <PathSetDlgItemPathW>
    PathSkipRoot EQU <PathSkipRootW>
    PathStripPath EQU <PathStripPathW>
    PathStripToRoot EQU <PathStripToRootW>
    PathUnExpandEnvStrings EQU <PathUnExpandEnvStringsW>
    PathUndecorate EQU <PathUndecorateW>
    PathUnmakeSystemFolder EQU <PathUnmakeSystemFolderW>
    PathUnquoteSpaces EQU <PathUnquoteSpacesW>
    SHCopyKey EQU <SHCopyKeyW>
    SHCreateStreamOnFile EQU <SHCreateStreamOnFileW>
    SHDeleteEmptyKey EQU <SHDeleteEmptyKeyW>
    SHDeleteKey EQU <SHDeleteKeyW>
    SHDeleteValue EQU <SHDeleteValueW>
    SHEnumKeyEx EQU <SHEnumKeyExW>
    SHEnumValue EQU <SHEnumValueW>
    SHFormatDateTime EQU <SHFormatDateTimeW>
    SHGetValue EQU <SHGetValueW>
    SHMessageBoxCheck EQU <SHMessageBoxCheckW>
    SHOpenRegStream2 EQU <SHOpenRegStream2W>
    SHOpenRegStream EQU <SHOpenRegStreamW>
    SHQueryInfoKey EQU <SHQueryInfoKeyW>
    SHQueryValueEx EQU <SHQueryValueExW>
    SHRegCreateUSKey EQU <SHRegCreateUSKeyW>
    SHRegDeleteEmptyUSKey EQU <SHRegDeleteEmptyUSKeyW>
    SHRegDeleteUSValue EQU <SHRegDeleteUSValueW>
    SHRegEnumUSKey EQU <SHRegEnumUSKeyW>
    SHRegEnumUSValue EQU <SHRegEnumUSValueW>
    SHRegGetBoolUSValue EQU <SHRegGetBoolUSValueW>
    SHRegGetPath EQU <SHRegGetPathW>
    SHRegGetUSValue EQU <SHRegGetUSValueW>
    SHRegGetValue EQU <SHRegGetValueW>
    SHRegOpenUSKey EQU <SHRegOpenUSKeyW>
    SHRegQueryInfoUSKey EQU <SHRegQueryInfoUSKeyW>
    SHRegQueryUSValue EQU <SHRegQueryUSValueW>
    SHRegSetPath EQU <SHRegSetPathW>
    SHRegSetUSValue EQU <SHRegSetUSValueW>
    SHRegWriteUSValue EQU <SHRegWriteUSValueW>
    SHSendMessageBroadcast EQU <SHSendMessageBroadcastW>
    SHSetValue EQU <SHSetValueW>
    SHStrDup EQU <SHStrDupW>
    SHStripMneumonic Equ <SHStripMneumonicW>
    IFNDEF ShellMessageBox
        ShellMessageBox Equ <ShellMessageBoxW>
    ENDIF
    StrCSpn EQU <StrCSpnW>
    StrCSpnI EQU <StrCSpnIW>
    StrCatBuff EQU <StrCatBuffW>
    StrCatChain EQU <StrCatChainW>
    StrCat EQU <StrCatW>
    StrChr EQU <StrChrW>
    StrChrI EQU <StrChrIW>
    StrCmpC EQU <StrCmpCW>
    StrCmpIC EQU <StrCmpICW>
    StrCmpNC EQU <StrCmpNCW>
    StrCmpNI EQU <StrCmpNIW>
    StrCmpNIC EQU <StrCmpNICW>
    StrCmpN EQU <StrCmpNW>
    StrDup EQU <StrDupW>
    StrFormatKBSize EQU <StrFormatKBSizeW>
    StrFromTimeInterval EQU <StrFromTimeIntervalW>
    StrIsIntlEqual EQU <StrIsIntlEqualW>
    StrNCat EQU <StrNCatW>
    StrPBrk EQU <StrPBrkW>
    StrRChrI EQU <StrRChrIW>
    StrRChr EQU <StrRChrW>
    StrRStrI EQU <StrRStrIW>
    StrRetToBuf EQU <StrRetToBufW>
    StrRetToStr EQU <StrRetToStrW>
    StrSpn EQU <StrSpnW>
    StrStr EQU <StrStrW>
    StrStrI EQU <StrStrIW>
    StrToInt64Ex EQU <StrToInt64ExW>
    StrToIntEx EQU <StrToIntExW>
    StrToInt EQU <StrToIntW>
    StrTrim EQU <StrTrimW>
    UrlApplyScheme EQU <UrlApplySchemeW>
    UrlCanonicalize EQU <UrlCanonicalizeW>
    UrlCombine EQU <UrlCombineW>
    UrlCompare EQU <UrlCompareW>
    UrlCreateFromPath EQU <UrlCreateFromPathW>
    UrlEscape EQU <UrlEscapeW>
    UrlGetLocation EQU <UrlGetLocationW>
    UrlGetPart EQU <UrlGetPartW>
    UrlHash EQU <UrlHashW>
    UrlIsNoHistory EQU <UrlIsNoHistoryW>
    UrlIsOpaque EQU <UrlIsOpaqueW>
    UrlIs EQU <UrlIsW>
    UrlUnescape EQU <UrlUnescapeW>
    wnsprintf EQU <wnsprintfW>
    wvnsprintf EQU <wvnsprintfW>
ELSE
    SZ_CONTENTTYPE_HTML EQU <SZ_CONTENTTYPE_HTMLA>
    SZ_CONTENTTYPE_CDF  EQU <SZ_CONTENTTYPE_CDFA>
    PARSEDURL EQU <PARSEDURLA>

    AssocQueryKey EQU <AssocQueryKeyA>
    AssocQueryString EQU <AssocQueryStringA>
    AssocQueryStringByKey EQU <AssocQueryStringByKeyA>
    AssocQueryString EQU <AssocQueryStringA>
    ChrCmpI EQU <ChrCmpIA>
    GetAcceptLanguages EQU <GetAcceptLanguagesA>
    IntlStrEqWorker EQU <IntlStrEqWorkerA>
    IsCharSpace EQU <IsCharSpaceA>
    MLLoadLibrary EQU <MLLoadLibraryA>
    ParseURL EQU <ParseURLA>
    PathAddBackslash EQU <PathAddBackslashA>
    PathAddExtension EQU <PathAddExtensionA>
    PathAppend EQU <PathAppendA>
    PathBuildRoot EQU <PathBuildRootA>
    PathCanonicalize EQU <PathCanonicalizeA>
    PathCombine EQU <PathCombineA>
    PathCommonPrefix EQU <PathCommonPrefixA>
    PathCompactPath EQU <PathCompactPathA>
    PathCompactPathEx EQU <PathCompactPathExA>
    PathCreateFromUrl EQU <PathCreateFromUrlA>
    PathFileExists EQU <PathFileExistsA>
    PathFindExtension EQU <PathFindExtensionA>
    PathFindFileName EQU <PathFindFileNameA>
    PathFindNextComponent EQU <PathFindNextComponentA>
    PathFindOnPath EQU <PathFindOnPathA>
    PathFindSuffixArray EQU <PathFindSuffixArrayA>
    PathGetArgs EQU <PathGetArgsA>
    PathGetCharType EQU <PathGetCharTypeA>
    PathGetDriveNumber EQU <PathGetDriveNumberA>
    PathIsContentType EQU <PathIsContentTypeA>
    PathIsDirectory EQU <IsDirectoryA>
    PathIsDirectoryEmpty EQU <PathIsDirectoryEmptyA>
    PathIsDirectoryEmpty EQU <PathIsDirectoryEmptyA>
    PathIsFileSpec EQU <PathIsFileSpecA>
    PathIsLFNFileSpec EQU <PathIsLFNFileSpecA>
    PathIsNetworkPath EQU <PathIsNetworkPathA>
    PathIsPrefix EQU <PathIsPrefixA>
    PathIsRelative EQU <PathIsRelativeA>
    PathIsRoot EQU <PathIsRootA>
    PathIsSameRoot EQU <PathIsSameRootA>
    PathIsSystemFolder EQU <PathIsSystemFolderA>
    PathIsUNC EQU <PathIsUNCA>
    PathIsUNCServerShare EQU <PathIsUNCServerShareA>
    PathIsUNCServer EQU <PathIsUNCServerA>
    PathIsUNC EQU <PathIsUNCA>
    PathIsURL EQU <PathIsURLA>
    PathMakePretty EQU <PathMakePrettyA>
    PathMakePretty EQU <PathMakePrettyA>
    PathMakeSystemFolder EQU <PathMakeSystemFolderA>
    PathMatchSpec EQU <PathMatchSpecA>
    PathMatchSpecEx EQU <PathMatchSpecExA>
    PathParseIconLocation EQU <PathParseIconLocationA>
    PathQuoteSpaces EQU <PathQuoteSpacesA>
    PathRelativePathTo EQU <PathRelativePathToA>
    PathRemoveArgs EQU <PathRemoveArgsA>
    PathRemoveBackslash EQU <PathRemoveBackslashA>
    PathRemoveBlanks EQU <PathRemoveBlanksA>
    PathRemoveExtension EQU <PathRemoveExtensionA>
    PathRemoveFileSpec EQU <PathRemoveFileSpecA>
    PathRenameExtension EQU <PathRenameExtensionA>
    PathSearchAndQualify EQU <PathSearchAndQualifyA>
    PathSetDlgItemPath EQU <PathSetDlgItemPathA>
    PathSkipRoot EQU <PathSkipRootA>
    PathStripPath EQU <PathStripPathA>
    PathStripToRoot EQU <PathStripToRootA>
    PathUnExpandEnvStrings EQU <PathUnExpandEnvStringsA>
    PathUndecorate EQU <PathUndecorateA>
    PathUnmakeSystemFolder EQU <PathUnmakeSystemFolderA>
    PathUnquoteSpaces EQU <PathUnquoteSpacesA>
    SHCopyKey EQU <SHCopyKeyA>
    SHCreateStreamOnFile EQU <SHCreateStreamOnFileA>
    SHDeleteEmptyKey EQU <SHDeleteEmptyKeyA>
    SHDeleteKey EQU <SHDeleteKeyA>
    SHDeleteValue EQU <SHDeleteValueA>
    SHEnumKeyEx EQU <SHEnumKeyExA>
    SHEnumValue EQU <SHEnumValueA>
    SHFormatDateTime EQU <SHFormatDateTimeA>
    SHGetValue EQU <SHGetValueA>
    SHMessageBoxCheck EQU <SHMessageBoxCheckA>
    SHOpenRegStream2 EQU <SHOpenRegStream2A>
    SHOpenRegStream EQU <SHOpenRegStreamA>
    SHQueryInfoKey EQU <SHQueryInfoKeyA>
    SHQueryValueEx EQU <SHQueryValueExA>
    SHRegCreateUSKey EQU <SHRegCreateUSKeyA>
    SHRegDeleteEmptyUSKey EQU <SHRegDeleteEmptyUSKeyA>
    SHRegDeleteUSValue EQU <SHRegDeleteUSValueA>
    SHRegEnumUSKey EQU <SHRegEnumUSKeyA>
    SHRegEnumUSValue EQU <SHRegEnumUSValueA>
    SHRegGetBoolUSValue EQU <SHRegGetBoolUSValueA>
    SHRegGetPath EQU <SHRegGetPathA>
    SHRegGetUSValue EQU <SHRegGetUSValueA>
    SHRegGetValue EQU <SHRegGetValueA>
    SHRegOpenUSKey EQU <SHRegOpenUSKeyA>
    SHRegQueryInfoUSKey EQU <SHRegQueryInfoUSKeyA>
    SHRegQueryUSValue EQU <SHRegQueryUSValueA>
    SHRegSetPath EQU <SHRegSetPathA>
    SHRegSetUSValue EQU <SHRegSetUSValueA>
    SHRegWriteUSValue EQU <SHRegWriteUSValueA>
    SHSendMessageBroadcast EQU <SHSendMessageBroadcastA>
    SHSetValue EQU <SHSetValueA>
    SHStrDup EQU <SHStrDupA>
    SHStripMneumonic EQU <SHStripMneumonicA>
    IFNDEF ShellMessageBox
        ShellMessageBox Equ <ShellMessageBoxA>
    ENDIF
    StrCSpn EQU <StrCSpnA>
    StrCSpnI EQU <StrCSpnIA>
    StrCatBuff EQU <StrCatBuffA>
    StrCatChain EQU <StrCatChainA>
    StrCat EQU <StrCatA>
    StrChr EQU <StrChrA>
    StrChrI EQU <StrChrIA>
    StrCmpC EQU <StrCmpCA>
    StrCmpIC EQU <StrCmpICA>
    StrCmpNC EQU <StrCmpNCA>
    StrCmpNI EQU <StrCmpNIA>
    StrCmpNIC EQU <StrCmpNICA>
    StrCmpN EQU <StrCmpNA>
    StrDup EQU <StrDupA>
    StrFormatKBSize EQU <StrFormatKBSizeA>
    StrFromTimeInterval EQU <StrFromTimeIntervalA>
    StrIsIntlEqual EQU <StrIsIntlEqualA>
    StrNCat EQU <StrNCatA>
    StrPBrk EQU <StrPBrkA>
    StrRChrI EQU <StrRChrIA>
    StrRChr EQU <StrRChrA>
    StrRStrI EQU <StrRStrIA>
    StrRetToBuf EQU <StrRetToBufA>
    StrRetToStr EQU <StrRetToStrA>
    StrSpn EQU <StrSpnA>
    StrStr EQU <StrStrA>
    StrStrI EQU <StrStrIA>
    StrToInt64Ex EQU <StrToInt64ExA>
    StrToIntEx EQU <StrToIntExA>
    StrToInt EQU <StrToIntA>
    StrTrim EQU <StrTrimA>
    UrlApplyScheme EQU <UrlApplySchemeA>
    UrlCanonicalize EQU <UrlCanonicalizeA>
    UrlCombine EQU <UrlCombineA>
    UrlCompare EQU <UrlCompareA>
    UrlCreateFromPath EQU <UrlCreateFromPathA>
    UrlEscape EQU <UrlEscapeA>
    UrlGetLocation EQU <UrlGetLocationA>
    UrlGetPart EQU <UrlGetPartA>
    UrlHash EQU <UrlHashA>
    UrlIsNoHistory EQU <UrlIsNoHistoryA>
    UrlIsOpaque EQU <UrlIsOpaqueA>
    UrlIs EQU <UrlIsA>
    UrlUnescape EQU <UrlUnescapeA>
    wnsprintf EQU <wnsprintfA>
    wvnsprintf EQU <wvnsprintfA>
ENDIF


;======================= Undocumented functions (unknown arguments) =======================;
;SHPropertyBag_ReadStrAlloc PROTO
;SHPropertyBag_WriteBSTR PROTO

ENDIF ;SHLWAPI_INC
