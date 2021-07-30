; =====================================================;
;                                                      ;
;      shlobj.inc for Easy Code 2.0 Masm projects      ;
;                  (version 1.0.0)                     ;
;                                                      ;
;             Copyright © Ramon Sala 2021              ;
;                                                      ;
; =====================================================;

IFNDEF SHLOBJ_INC
SHLOBJ_INC EQU     1

IFNDEF MAX_PATH
    MAX_PATH                                    EQU     260
ENDIF

IFNDEF MAX_COLUMN_NAME_LEN
    MAX_COLUMN_NAME_LEN                         EQU     80
ENDIF

IFNDEF MAX_COLUMN_DESC_LEN
    MAX_COLUMN_DESC_LEN                         EQU     128
ENDIF

IFNDEF OLE32_INC
    Include ole32.inc
ENDIF

IFNDEF COMCTL32_INC
    include comctl32.inc
ENDIF

IFNDEF SHLGUID_INC
    include shlguid.inc
ENDIF

IFNDEF WININET_INC
    include wininet.inc
ENDIF

ISHCUTCMDID_DOWNLOADICON                        EQU     0
ISHCUTCMDID_INTSHORTCUTCREATE                   EQU     1
ISHCUTCMDID_COMMITHISTORY                       EQU     2
ISHCUTCMDID_SETUSERAWURL                        EQU     3
CMDID_INTSHORTCUTCREATE                         EQU     ISHCUTCMDID_INTSHORTCUTCREATE

NUM_POINTS                                      EQU     3

PIFNAMESIZE                                     EQU     30
PIFSTARTLOCSIZE                                 EQU     63
PIFDEFPATHSIZE                                  EQU     64
PIFPARAMSSIZE                                   EQU     64
PIFSHPROGSIZE                                   EQU     64
PIFSHDATASIZE                                   EQU     64
PIFDEFFILESIZE                                  EQU     80
PIFMAXFILEPATH                                  EQU     260

FCS_READ                                        EQU     00000001H
FCS_FORCEWRITE                                  EQU     00000002H
FCS_WRITE                                       EQU     (FCS_READ OR FCS_FORCEWRITE)
FCS_FLAG_DRAGDROP                               EQU     2
FCSM_VIEWID                                     EQU     00000001H
FCSM_WEBVIEWTEMPLATE                            EQU     00000002H
FCSM_INFOTIP                                    EQU     00000004H
FCSM_CLSID                                      EQU     00000008H
FCSM_ICONFILE                                   EQU     00000010H
FCSM_LOGO                                       EQU     00000020H
FCSM_FLAGS                                      EQU     00000040H

OFASI_EDIT                                      EQU     0001H
OFASI_OPENDESKTOP                               EQU     0002H

SIOM_OVERLAYINDEX                               EQU     1
SIOM_ICONINDEX                                  EQU     2
SIOM_PRIORITY                                   EQU     3
SIOM_RESERVED_SHARED                            EQU     0
SIOM_RESERVED_LINK                              EQU     1
SIOM_RESERVED_SLOWFILE                          EQU     2

CMF_NORMAL                                      EQU     000000000H
CMF_DEFAULTONLY                                 EQU     000000001H
CMF_VERBSONLY                                   EQU     000000002H
CMF_EXPLORE                                     EQU     000000004H
CMF_NOVERBS                                     EQU     000000008H
CMF_CANRENAME                                   EQU     000000010H
CMF_NODEFAULT                                   EQU     000000020H
CMF_INCLUDESTATIC                               EQU     000000040H
CMF_ITEMMENU                                    EQU     000000080H
CMF_FINDHACK                                    EQU     000000080H
CMF_EXTENDEDVERBS                               EQU     000000100H
CMF_DISABLEDVERBS                               EQU     000000200H
CMF_RESERVED                                    EQU     0FFFF0000H
CMF_ASYNCVERBSTATE                              EQU     000000400H
CMF_OPTIMIZEFORINVOKE                           EQU     000000800H
CMF_SYNCCASCADEMENU                             EQU     000001000H
CMF_DONOTPICKDEFAULT                            EQU     000002000H
CMF_RESERVED                                    EQU     0FFFF0000H

GCS_VERBA                                       EQU     00000000H
GCS_HELPTEXTA                                   EQU     00000001H
GCS_VALIDATEA                                   EQU     00000002H
GCS_VERBW                                       EQU     00000004H
GCS_HELPTEXTW                                   EQU     00000005H
GCS_VALIDATEW                                   EQU     00000006H
GCS_UNICODE                                     EQU     00000004H

CMDSTR_NEWFOLDERA                               EQU     A("NewFolder")
CMDSTR_VIEWLISTA                                EQU     A("ViewList")
CMDSTR_VIEWDETAILSA                             EQU     A("ViewDetails")
CMDSTR_NEWFOLDERW                               EQU     L("NewFolder")
CMDSTR_VIEWLISTW                                EQU     L("ViewList")
CMDSTR_VIEWDETAILSW                             EQU     L("ViewDetails")

CMIC_MASK_HOTKEY                                EQU     SEE_MASK_HOTKEY
CMIC_MASK_ICON                                  EQU     SEE_MASK_ICON
CMIC_MASK_FLAG_NO_UI                            EQU     SEE_MASK_FLAG_NO_UI
CMIC_MASK_UNICODE                               EQU     SEE_MASK_UNICODE
CMIC_MASK_NO_CONSOLE                            EQU     SEE_MASK_NO_CONSOLE
IF NTDDI_VERSION LT NTDDI_VISTA
    CMIC_MASK_HASLINKNAME                       EQU     SEE_MASK_HASLINKNAME
    CMIC_MASK_HASTITLE                          EQU     SEE_MASK_HASTITLE
ENDIF
CMIC_MASK_FLAG_SEP_VDM                          EQU     SEE_MASK_FLAG_SEPVDM
CMIC_MASK_ASYNCOK                               EQU     SEE_MASK_ASYNCOK
CMIC_MASK_NOASYNC                               EQU     SEE_MASK_NOASYNC
CMIC_MASK_SHIFT_DOWN                            EQU     10000000H
CMIC_MASK_CONTROL_DOWN                          EQU     20000000H
CMIC_MASK_PTINVOKE                              EQU     20000000H

GIL_OPENICON                                    EQU     0001H
GIL_FORSHELL                                    EQU     0002H
GIL_ASYNC                                       EQU     0020H
GIL_DEFAULTICON                                 EQU     0040H
GIL_FORSHORTCUT                                 EQU     0080H
GIL_CHECKSHIELD                                 EQU     0200H

GIL_SIMULATEDOC                                 EQU     0001H
GIL_PERINSTANCE                                 EQU     0002H
GIL_PERCLASS                                    EQU     0004H
GIL_NOTFILENAME                                 EQU     0008H
GIL_DONTCACHE                                   EQU     0010H
GIL_SHIELD                                      EQU     0200H
GIL_FORCENOSHIELD                               EQU     0400H

ISIOI_ICONFILE                                  EQU     00000001H
ISIOI_ICONINDEX                                 EQU     00000002H

TOID_NULL                                       EQU     GUID_NULL
ITSAT_DEFAULT_LPARAM                            EQU     (-1)
ITSAT_DEFAULT_PRIORITY                          EQU     10000000H
ITSAT_MAX_PRIORITY                              EQU     7FFFFFFFH
ITSAT_MIN_PRIORITY                              EQU     00000000H
ITSSFLAG_COMPLETE_ON_DESTROY                    EQU     0000H
ITSSFLAG_KILL_ON_DESTROY                        EQU     0001H
ITSSFLAG_FLAGS_MASK                             EQU     0003H
ITSS_THREAD_DESTROY_DEFAULT_TIMEOUT             EQU     10000
ITSS_THREAD_TERMINATE_TIMEOUT                   EQU     INFINITE
ITSS_THREAD_TIMEOUT_NO_CHANGE                   EQU     (INFINITE - 1)

OI_ASYNC                                        EQU     0FFFFEEEEH

IDO_SHGIOI_SHARE                                EQU     00FFFFFFFH
IDO_SHGIOI_LINK                                 EQU     00FFFFFFEH
IDO_SHGIOI_SLOWFILE                             EQU     0FFFFFFFDH

NT_CONSOLE_PROPS_SIG                            EQU     0A0000002H
NT_FE_CONSOLE_PROPS_SIG                         EQU     0A0000004H

IFNDEF FO_MOVE
    FO_MOVE                                     EQU     0001H
    FO_COPY                                     EQU     0002H
    FO_DELETE                                   EQU     0003H
    FO_RENAME                                   EQU     0004H
    FOF_MULTIDESTFILES                          EQU     0001H
    FOF_CONFIRMMOUSE                            EQU     0002H
    FOF_SILENT                                  EQU     0004H
    FOF_RENAMEONCOLLISION                       EQU     0008H
    FOF_NOCONFIRMATION                          EQU     0010H
    FOF_WANTMAPPINGHANDLE                       EQU     0020H
    FOF_ALLOWUNDO                               EQU     0040H
    FOF_FILESONLY                               EQU     0080H
    FOF_SIMPLEPROGRESS                          EQU     0100H
    FOF_NOCONFIRMMKDIR                          EQU     0200H
    FOF_NOERRORUI                               EQU     0400H
    FOF_NOCOPYSECURITYATTRIBS                   EQU     0800H
    FOF_NORECURSION                             EQU     1000H
    FOF_NO_CONNECTED_ELEMENTS                   EQU     2000H
    FOF_WANTNUKEWARNING                         EQU     4000H
    PO_DELETE                                   EQU     0013H
    PO_RENAME                                   EQU     0014H
    PO_PORTCHANGE                               EQU     0020H
    PO_REN_PORT                                 EQU     0034H
ENDIF

FVSIF_RECT                                      EQU     00000001H
FVSIF_PINNED                                    EQU     00000002H
FVSIF_NEWFAILED                                 EQU     08000000H
FVSIF_NEWFILE                                   EQU     80000000H
FVSIF_CANVIEWIT                                 EQU     40000000H

FCIDM_SHVIEWFIRST                               EQU     00000H
FCIDM_SHVIEWLAST                                EQU     07FFFH
FCIDM_BROWSERFIRST                              EQU     0A000H
FCIDM_BROWSERLAST                               EQU     0BF00H
FCIDM_GLOBALFIRST                               EQU     08000H
FCIDM_GLOBALLAST                                EQU     09FFFH

FCIDM_MENU_FILE                                 EQU     (FCIDM_GLOBALFIRST + 0000H)
FCIDM_MENU_EDIT                                 EQU     (FCIDM_GLOBALFIRST + 0040H)
FCIDM_MENU_VIEW                                 EQU     (FCIDM_GLOBALFIRST + 0080H)
FCIDM_MENU_VIEW_SEP_OPTIONS                     EQU     (FCIDM_GLOBALFIRST + 0081H)
FCIDM_MENU_TOOLS                                EQU     (FCIDM_GLOBALFIRST + 00C0H)
FCIDM_MENU_TOOLS_SEP_GOTO                       EQU     (FCIDM_GLOBALFIRST + 00C1H)
FCIDM_MENU_HELP                                 EQU     (FCIDM_GLOBALFIRST + 0100H)
FCIDM_MENU_FIND                                 EQU     (FCIDM_GLOBALFIRST + 0140H)
FCIDM_MENU_EXPLORE                              EQU     (FCIDM_GLOBALFIRST + 0150H)
FCIDM_MENU_FAVORITES                            EQU     (FCIDM_GLOBALFIRST + 0170H)

FCIDM_TOOLBAR                                   EQU     (FCIDM_BROWSERFIRST + 0)
FCIDM_STATUS                                    EQU     (FCIDM_BROWSERFIRST + 1)

SBSP_DEFBROWSER                                 EQU     0000H
SBSP_SAMEBROWSER                                EQU     0001H
SBSP_NEWBROWSER                                 EQU     0002H
SBSP_DEFMODE                                    EQU     0000H
SBSP_OPENMODE                                   EQU     0010H
SBSP_EXPLOREMODE                                EQU     0020H
SBSP_HELPMODE                                   EQU     0040H
SBSP_NOTRANSFERHIST                             EQU     0080H
SBSP_ABSOLUTE                                   EQU     0000H
SBSP_RELATIVE                                   EQU     1000H
SBSP_PARENT                                     EQU     2000H
SBSP_NAVIGATEBACK                               EQU     4000H
SBSP_NAVIGATEFORWARD                            EQU     8000H
SBSP_ALLOW_AUTONAVIGATE                         EQU     10000H
SBSP_KEEPSAMETEMPLATE                           EQU     00020000H
SBSP_KEEPWORDWHEELTEXT                          EQU     00040000H
SBSP_ACTIVATE_NOFOCUS                           EQU     00080000H
SBSP_CREATENOHISTORY                            EQU     00100000H
SBSP_PLAYNOSOUND                                EQU     00200000H
SBSP_CALLERUNTRUSTED                            EQU     00800000H
SBSP_TRUSTFIRSTDOWNLOAD                         EQU     01000000H
SBSP_UNTRUSTEDFORDOWNLOAD                       EQU     02000000H
SBSP_NOAUTOSELECT                               EQU     04000000H
SBSP_WRITENOHISTORY                             EQU     08000000H
SBSP_TRUSTEDFORACTIVEX                          EQU     10000000H
SBSP_FEEDNAVIGATION                             EQU     20000000H
SBSP_REDIRECT                                   EQU     40000000H
SBSP_INITIATEDBYHLINKFRAME                      EQU     80000000H

FCW_STATUS                                      EQU     0001H
FCW_TOOLBAR                                     EQU     0002H
FCW_TREE                                        EQU     0003H
FCW_INTERNETBAR                                 EQU     0006H
FCW_PROGRESS                                    EQU     0008H

FCT_MERGE                                       EQU     0001H
FCT_CONFIGABLE                                  EQU     0002H
FCT_ADDTOEND                                    EQU     0004H

CDBOSC_SETFOCUS                                 EQU     00000000H
CDBOSC_KILLFOCUS                                EQU     00000001H
CDBOSC_SELCHANGE                                EQU     00000002H
CDBOSC_RENAME                                   EQU     00000003H

IDC_OFFLINE_HAND                                EQU     103
IDC_PANTOOL_HAND_OPEN                           EQU     104
IDC_PANTOOL_HAND_CLOSED                         EQU     105

CDB2N_CONTEXTMENU_DONE                          EQU     00000001H
CDB2N_CONTEXTMENU_START                         EQU     00000002H

CDB2GVF_SHOWALLFILES                            EQU     00000001H
CDB2GVF_ISFILESAVE                              EQU     00000002H
CDB2GVF_ALLOWPREVIEWPANE                        EQU     00000004H
CDB2GVF_NOSELECTVERB                            EQU     00000008H
CDB2GVF_NOINCLUDEITEM                           EQU     00000010H
CDB2GVF_ISFOLDERPICKER                          EQU     00000020H
CDB2GVF_ADDSHIELD                               EQU     00000040H

IFNDEF SVSI_NOSTATECHANGE
    SVSI_DESELECT                               EQU     00000000H
    SVSI_SELECT                                 EQU     00000001H
    SVSI_EDIT                                   EQU     00000003H
    SVSI_DESELECTOTHERS                         EQU     00000004H
    SVSI_ENSUREVISIBLE                          EQU     00000008H
    SVSI_FOCUSED                                EQU     00000010H
    SVSI_TRANSLATEPT                            EQU     00000020H
    SVSI_SELECTIONMARK                          EQU     00000040H
    SVSI_POSITIONITEM                           EQU     00000080H
    SVSI_CHECK                                  EQU     00000100H
    SVSI_NOSTATECHANGE                          EQU     80000000H
ENDIF

IFNDEF SVGIO_FLAG_VIEWORDER
    SVGIO_BACKGROUND                            EQU     0
    SVGIO_SELECTION                             EQU     01H
    SVGIO_ALLVIEW                               EQU     02H
    SVGIO_CHECKED                               EQU     03H
    SVGIO_TYPE_MASK                             EQU     0FH
    SVGIO_FLAG_VIEWORDER                        EQU     80000000H
ENDIF

SV2GV_CURRENTVIEW                               EQU     (-1)
SV2GV_DEFAULTVIEW                               EQU     (-2)

STRRET_WSTR                                     EQU     0000H
STRRET_OFFSET                                   EQU     0001H
STRRET_CSTR                                     EQU     0002H

IFNDEF REGSTR_PATH_EXPLORER
    REGSTR_PATH_EXPLORER                        EQU     TEXT("Software\Microsoft\Windows\CurrentVersion\Explorer")
ENDIF

REGSTR_PATH_SPECIAL_FOLDERS                     EQU     TEXT("\Shell Folders")

CSIDL_DESKTOP                                   EQU     00000H
CSIDL_INTERNET                                  EQU     00001H
CSIDL_PROGRAMS                                  EQU     00002H
CSIDL_CONTROLS                                  EQU     00003H
CSIDL_PRINTERS                                  EQU     00004H
CSIDL_PERSONAL                                  EQU     00005H
CSIDL_FAVORITES                                 EQU     00006H
CSIDL_STARTUP                                   EQU     00007H
CSIDL_RECENT                                    EQU     00008H
CSIDL_SENDTO                                    EQU     00009H
CSIDL_BITBUCKET                                 EQU     0000AH
CSIDL_STARTMENU                                 EQU     0000BH
CSIDL_MYDOCUMENTS                               EQU     CSIDL_PERSONAL
CSIDL_MYMUSIC                                   EQU     0000DH
CSIDL_MYVIDEO                                   EQU     0000EH
CSIDL_DESKTOPDIRECTORY                          EQU     00010H
CSIDL_DRIVES                                    EQU     00011H
CSIDL_NETWORK                                   EQU     00012H
CSIDL_NETHOOD                                   EQU     00013H
CSIDL_FONTS                                     EQU     00014H
CSIDL_TEMPLATES                                 EQU     00015H
CSIDL_COMMON_STARTMENU                          EQU     00016H
CSIDL_COMMON_PROGRAMS                           EQU     00017H
CSIDL_COMMON_STARTUP                            EQU     00018H
CSIDL_COMMON_DESKTOPDIRECTORY                   EQU     00019H
CSIDL_APPDATA                                   EQU     0001AH
CSIDL_PRINTHOOD                                 EQU     0001BH
CSIDL_LOCAL_APPDATA                             EQU     0001CH
CSIDL_ALTSTARTUP                                EQU     0001DH
CSIDL_COMMON_ALTSTARTUP                         EQU     0001EH
CSIDL_COMMON_FAVORITES                          EQU     0001FH
CSIDL_INTERNET_CACHE                            EQU     00020H
CSIDL_COOKIES                                   EQU     00021H
CSIDL_HISTORY                                   EQU     00022H
CSIDL_COMMON_APPDATA                            EQU     00023H
CSIDL_WINDOWS                                   EQU     00024H
CSIDL_SYSTEM                                    EQU     00025H
CSIDL_PROGRAM_FILES                             EQU     00026H
CSIDL_MYPICTURES                                EQU     00027H
CSIDL_PROFILE                                   EQU     00028H
CSIDL_SYSTEMX86                                 EQU     00029H
CSIDL_PROGRAM_FILESX86                          EQU     0002AH
CSIDL_PROGRAM_FILES_COMMON                      EQU     0002BH
CSIDL_PROGRAM_FILES_COMMONX86                   EQU     0002CH
CSIDL_COMMON_TEMPLATES                          EQU     0002DH
CSIDL_COMMON_DOCUMENTS                          EQU     0002EH
CSIDL_COMMON_ADMINTOOLS                         EQU     0002FH
CSIDL_ADMINTOOLS                                EQU     00030H
CSIDL_CONNECTIONS                               EQU     00031H
CSIDL_COMMON_MUSIC                              EQU     00035H
CSIDL_COMMON_PICTURES                           EQU     00036H
CSIDL_COMMON_VIDEO                              EQU     00037H
CSIDL_RESOURCES                                 EQU     00038H
CSIDL_RESOURCES_LOCALIZED                       EQU     00039H
CSIDL_COMMON_OEM_LINKS                          EQU     0003AH
CSIDL_CDBURN_AREA                               EQU     0003BH
CSIDL_COMPUTERSNEARME                           EQU     0003DH

CSIDL_FLAG_CREATE                               EQU     08000H
CSIDL_FLAG_DONT_VERIFY                          EQU     04000H
CSIDL_FLAG_NO_ALIAS                             EQU     01000H
CSIDL_FLAG_PER_USER_INIT                        EQU     00800H
CSIDL_FLAG_MASK                                 EQU     0FF00H

BIF_RETURNONLYFSDIRS                            EQU     00001H
BIF_DONTGOBELOWDOMAIN                           EQU     00002H
BIF_STATUSTEXT                                  EQU     00004H
BIF_RETURNFSANCESTORS                           EQU     00008H
BIF_EDITBOX                                     EQU     00010H
BIF_VALIDATE                                    EQU     00020H
BIF_NEWDIALOGSTYLE                              EQU     00040H
BIF_USENEWUI                                    EQU     (BIF_NEWDIALOGSTYLE OR BIF_EDITBOX)
BIF_BROWSEINCLUDEURLS                           EQU     00080H
BIF_BROWSEFORCOMPUTER                           EQU     01000H
BIF_BROWSEFORPRINTER                            EQU     02000H
BIF_BROWSEINCLUDEFILES                          EQU     04000H
BIF_SHAREABLE                                   EQU     08000H

BFFM_INITIALIZED                                EQU     1
BFFM_SELCHANGED                                 EQU     2
BFFM_VALIDATEFAILEDA                            EQU     3
BFFM_VALIDATEFAILEDW                            EQU     4
BFFM_IUNKNOWN                                   EQU     5

BFFM_SETSTATUSTEXTA                             EQU     (WM_USER + 100)
BFFM_ENABLEOK                                   EQU     (WM_USER + 101)
BFFM_SETSELECTIONA                              EQU     (WM_USER + 102)
BFFM_SETSELECTIONW                              EQU     (WM_USER + 103)
BFFM_SETSTATUSTEXTW                             EQU     (WM_USER + 104)
BFFM_SETOKTEXT                                  EQU     (WM_USER + 105)
BFFM_SETEXPANDED                                EQU     (WM_USER + 106)

GPFIDL_DEFAULT                                  EQU     0000H
GPFIDL_ALTNAME                                  EQU     0001H
GPFIDL_UNCPRINTER                               EQU     0002H

DROPEFFECT_COPY                                 EQU     01H
DROPEFFECT_MOVE                                 EQU     02H
DROPEFFECT_LINK                                 EQU     04H

IFNDEF SFGAO_STORAGECAPMASK
    SHCIDS_ALLFIELDS                            EQU     080000000H
    SHCIDS_CANONICALONLY                        EQU     010000000H
    SHCIDS_BITMASK                              EQU     0FFFF0000H
    SHCIDS_COLUMNMASK                           EQU     00000FFFFH
    SFGAO_CANCOPY                               EQU     DROPEFFECT_COPY
    SFGAO_CANMOVE                               EQU     DROPEFFECT_MOVE
    SFGAO_CANLINK                               EQU     DROPEFFECT_LINK
    SFGAO_STORAGE                               EQU     000000008H
    SFGAO_CANRENAME                             EQU     000000010H
    SFGAO_CANDELETE                             EQU     000000020H
    SFGAO_HASPROPSHEET                          EQU     000000040H
    SFGAO_DROPTARGET                            EQU     000000100H
    SFGAO_CAPABILITYMASK                        EQU     000000177H
    SFGAO_ENCRYPTED                             EQU     000002000H
    SFGAO_ISSLOW                                EQU     000004000H
    SFGAO_GHOSTED                               EQU     000008000H
    SFGAO_LINK                                  EQU     000010000H
    SFGAO_SHARE                                 EQU     000020000H
    SFGAO_READONLY                              EQU     000040000H
    SFGAO_HIDDEN                                EQU     000080000H
    SFGAO_DISPLAYATTRMASK                       EQU     0000FC000H
    SFGAO_FILESYSANCESTOR                       EQU     010000000H
    SFGAO_FOLDER                                EQU     020000000H
    SFGAO_FILESYSTEM                            EQU     040000000H
    SFGAO_HASSUBFOLDER                          EQU     080000000H
    SFGAO_CONTENTSMASK                          EQU     080000000H
    SFGAO_VALIDATE                              EQU     001000000H
    SFGAO_REMOVABLE                             EQU     002000000H
    SFGAO_COMPRESSED                            EQU     004000000H
    SFGAO_BROWSABLE                             EQU     008000000H
    SFGAO_NONENUMERATED                         EQU     000100000H
    SFGAO_NEWCONTENT                            EQU     000200000H
    SFGAO_CANMONIKER                            EQU     000400000H
    SFGAO_HASSTORAGE                            EQU     000400000H
    SFGAO_STREAM                                EQU     000400000H
    SFGAO_STORAGEANCESTOR                       EQU     000800000H
    SFGAO_STORAGECAPMASK                        EQU     070C50008H
    SFGAO_PKEYSFGAOMASK                         EQU     081044000H
ENDIF

STR_BIND_FORCE_FOLDER_SHORTCUT_RESOLVE          EQU     L("Force Folder Shortcut Resolve")
STR_AVOID_DRIVE_RESTRICTION_POLICY              EQU     L("L"Avoid Drive Restriction Policy")
STR_AVOID_DRIVE_RESTRICTION_POLICY              EQU     L("Avoid Drive Restriction Policy")
STR_SKIP_BINDING_CLSID                          EQU     L("Skip Binding CLSID")
STR_PARSE_PREFER_FOLDER_BROWSING                EQU     L("Parse Prefer Folder Browsing")
STR_DONT_PARSE_RELATIVE                         EQU     L("Don't Parse Relative")
STR_PARSE_TRANSLATE_ALIASES                     EQU     L("Parse Translate Aliases")
STR_PARSE_SKIP_NET_CACHE                        EQU     L("Skip Net Resource Cache")
STR_PARSE_SHELL_PROTOCOL_TO_FILE_OBJECTS        EQU     L("Parse Shell Protocol To File Objects")
STR_TRACK_CLSID                                 EQU     L("Track the CLSID")
STR_INTERNAL_NAVIGATE                           EQU     L("Internal Navigation")
STR_PARSE_PROPERTYSTORE                         EQU     L("DelegateNamedProperties")
STR_NO_VALIDATE_FILENAME_CHARS                  EQU     L("NoValidateFilenameChars")
STR_BIND_DELEGATE_CREATE_OBJECT                 EQU     L("Delegate Object Creation")
STR_PARSE_ALLOW_INTERNET_SHELL_FOLDERS          EQU     L("Allow binding to Internet shell folder handlers and negate STR_PARSE_PREFER_WEB_BROWSING")
STR_PARSE_PREFER_WEB_BROWSING                   EQU     L("Do not bind to Internet shell folder handlers")
STR_PARSE_SHOW_NET_DIAGNOSTICS_UI               EQU     L("Show network diagnostics UI")
STR_PARSE_DONT_REQUIRE_VALIDATED_URLS           EQU     L("Do not require validated URLs")
STR_INTERNETFOLDER_PARSE_ONLY_URLMON_BINDABLE   EQU     L("Validate URL")

PANE_NONE                                       EQU     (-1)
PANE_ZONE                                       EQU     1
PANE_OFFLINE                                    EQU     2
PANE_PRINTER                                    EQU     3
PANE_SSL                                        EQU     4
PANE_NAVIGATION                                 EQU     5
PANE_PROGRESS                                   EQU     6
PANE_PRIVACY                                    EQU     7

IFNDEF STR_SKIP_BINDING_CLSID
    STR_SKIP_BINDING_CLSID                      EQU     L("Skip Binding CLSID")
ENDIF
STR_FILE_SYS_BIND_DATA                          EQU     L("File System Bind Data")

PROGDLG_NORMAL                                  EQU     000000000H
PROGDLG_MODAL                                   EQU     000000001H
PROGDLG_AUTOTIME                                EQU     000000002H
PROGDLG_NOTIME                                  EQU     000000004H
PROGDLG_NOMINIMIZE                              EQU     000000008H
PROGDLG_NOPROGRESSBAR                           EQU     000000010H
PROGDLG_MARQUEEPROGRESS                         EQU     000000020H
PROGDLG_NOCANCEL                                EQU     000000040H

PDTIMER_RESET                                   EQU     000000001H
PDTIMER_PAUSE                                   EQU     000000002H
PDTIMER_RESUME                                  EQU     000000003H

DWFRF_NORMAL                                    EQU     00000H
DWFRF_DELETECONFIGDATA                          EQU     00001H

DWFAF_HIDDEN                                    EQU     00001H
DWFAF_GROUP1                                    EQU     00002H
DWFAF_GROUP2                                    EQU     00004H
DWFAF_AUTOHIDE                                  EQU     00010H

DBIM_MINSIZE                                    EQU     00001H
DBIM_MAXSIZE                                    EQU     00002H
DBIM_INTEGRAL                                   EQU     00004H
DBIM_ACTUAL                                     EQU     00008H
DBIM_TITLE                                      EQU     00010H
DBIM_MODEFLAGS                                  EQU     00020H
DBIM_BKCOLOR                                    EQU     00040H

DBIMF_NORMAL                                    EQU     00000H
DBIMF_VARIABLEHEIGHT                            EQU     00008H
DBIMF_DEBOSSED                                  EQU     00020H
DBIMF_BKCOLOR                                   EQU     00040H

DBIF_VIEWMODE_NORMAL                            EQU     00000H
DBIF_VIEWMODE_VERTICAL                          EQU     00001H
DBIF_VIEWMODE_FLOATING                          EQU     00002H
DBIF_VIEWMODE_TRANSPARENT                       EQU     00004H

CFSTR_SHELLIDLIST                               EQU     TEXT("Shell IDList Array")
CFSTR_SHELLIDLISTOFFSET                         EQU     TEXT("Shell Object Offsets")
CFSTR_NETRESOURCES                              EQU     TEXT("Net Resource")
CFSTR_FILEDESCRIPTORA                           EQU     TEXT("FileGroupDescriptor")
CFSTR_FILEDESCRIPTORW                           EQU     TEXT("FileGroupDescriptorW")
CFSTR_FILECONTENTS                              EQU     TEXT("FileContents")
CFSTR_FILENAMEA                                 EQU     TEXT("FileName")
CFSTR_FILENAMEW                                 EQU     TEXT("FileNameW")
CFSTR_PRINTERGROUP                              EQU     TEXT("PrinterFriendlyName")
CFSTR_FILENAMEMAPA                              EQU     TEXT("FileNameMap")
CFSTR_FILENAMEMAPW                              EQU     TEXT("FileNameMapW")
CFSTR_SHELLURL                                  EQU     TEXT("UniformResourceLocator")
CFSTR_INETURLA                                  EQU     TEXT("UniformResourceLocator")
CFSTR_INETURLW                                  EQU     TEXT("UniformResourceLocatorW")
CFSTR_PREFERREDDROPEFFECT                       EQU     TEXT("Preferred DropEffect")
CFSTR_PERFORMEDDROPEFFECT                       EQU     TEXT("Performed DropEffect")
CFSTR_PASTESUCCEEDED                            EQU     TEXT("Paste Succeeded")
CFSTR_INDRAGLOOP                                EQU     TEXT("InShellDragLoop")
CFSTR_MOUNTEDVOLUME                             EQU     TEXT("MountedVolume")
CFSTR_PERSISTEDDATAOBJECT                       EQU     TEXT("PersistedDataObject")
CFSTR_TARGETCLSID                               EQU     TEXT("TargetCLSID")
CFSTR_LOGICALPERFORMEDDROPEFFECT                EQU     TEXT("Logical Performed DropEffect")
CFSTR_AUTOPLAY_SHELLIDLISTS                     EQU     TEXT("Autoplay Enumerated IDList Array")
CFSTR_UNTRUSTEDDRAGDROP                         EQU     TEXT("UntrustedDragDrop")
CFSTR_FILE_ATTRIBUTES_ARRAY                     EQU     TEXT("File Attributes Array")
CFSTR_INVOKECOMMAND_DROPPARAM                   EQU     TEXT("InvokeCommand DropParam")
CFSTR_SHELLDROPHANDLER                          EQU     TEXT("DropHandlerCLSID")
CFSTR_DROPDESCRIPTION                           EQU     TEXT("DropDescription")

DVASPECT_SHORTNAME                              EQU     2
DVASPECT_COPY                                   EQU     3
DVASPECT_LINK                                   EQU     4

SHCNE_RENAMEITEM                                EQU     000000001H
SHCNE_CREATE                                    EQU     000000002H
SHCNE_DELETE                                    EQU     000000004H
SHCNE_MKDIR                                     EQU     000000008H
SHCNE_RMDIR                                     EQU     000000010H
SHCNE_MEDIAINSERTED                             EQU     000000020H
SHCNE_MEDIAREMOVED                              EQU     000000040H
SHCNE_DRIVEREMOVED                              EQU     000000080H
SHCNE_DRIVEADD                                  EQU     000000100H
SHCNE_NETSHARE                                  EQU     000000200H
SHCNE_NETUNSHARE                                EQU     000000400H
SHCNE_ATTRIBUTES                                EQU     000000800H
SHCNE_UPDATEDIR                                 EQU     000001000H
SHCNE_UPDATEITEM                                EQU     000002000H
SHCNE_SERVERDISCONNECT                          EQU     000004000H
SHCNE_UPDATEIMAGE                               EQU     000008000H
SHCNE_DRIVEADDGUI                               EQU     000010000H
SHCNE_RENAMEFOLDER                              EQU     000020000H
SHCNE_FREESPACE                                 EQU     000040000H
SHCNE_EXTENDED_EVENT                            EQU     004000000H
SHCNE_ASSOCCHANGED                              EQU     008000000H
SHCNE_DISKEVENTS                                EQU     00002381FH
SHCNE_GLOBALEVENTS                              EQU     00C0581E0H
SHCNE_ALLEVENTS                                 EQU     07FFFFFFFH
SHCNE_INTERRUPT                                 EQU     080000000H

SHCNEE_ORDERCHANGED                             EQU     2
SHCNEE_MSI_CHANGE                               EQU     4
SHCNEE_MSI_UNINSTALL                            EQU     5

SHCNF_IDLIST                                    EQU     00000H
SHCNF_PATHA                                     EQU     00001H
SHCNF_PRINTERA                                  EQU     00002H
SHCNF_DWORD                                     EQU     00003H
SHCNF_PATHW                                     EQU     00005H
SHCNF_PRINTERW                                  EQU     00006H
SHCNF_TYPE                                      EQU     000FFH
SHCNF_FLUSH                                     EQU     01000H
SHCNF_FLUSHNOWAIT                               EQU     02000H

QITIPF_DEFAULT                                  EQU     000000000H
QITIPF_USENAME                                  EQU     000000001H
QITIPF_LINKNOTARGET                             EQU     000000002H
QITIPF_LINKUSETARGET                            EQU     000000004H
QITIPF_USESLOWTIP                               EQU     000000008H
QITIPF_SINGLELINE                               EQU     000000010H

QIF_CACHED                                      EQU     000000001H
QIF_DONTEXPANDFOLDER                            EQU     000000002H

SHARD_PIDL                                      EQU     000000001H
SHARD_PATHA                                     EQU     000000002H
SHARD_PATHW                                     EQU     000000003H

IFDEF APP_UNICODE
    CFSTR_FILEDESCRIPTOR EQU <CFSTR_FILEDESCRIPTORW>
    CFSTR_FILENAME EQU <CFSTR_FILENAMEW>
    CFSTR_FILENAMEMAP EQU <CFSTR_FILENAMEMAPW>
    CFSTR_INETURL EQU <CFSTR_INETURLW>
ELSE
    CFSTR_FILEDESCRIPTOR EQU <CFSTR_FILEDESCRIPTORA>
    CFSTR_FILENAME EQU <CFSTR_FILENAMEA>
    CFSTR_FILENAMEMAP EQU <CFSTR_FILENAMEMAPA>
    CFSTR_INETURL EQU <CFSTR_INETURLA>
ENDIF

SHGDFIL_FINDDATA                                EQU     1
SHGDFIL_NETRESOURCE                             EQU     2
SHGDFIL_DESCRIPTIONID                           EQU     3

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

PID_IS_URL                                      EQU     2
PID_IS_NAME                                     EQU     4
PID_IS_WORKINGDIR                               EQU     5
PID_IS_HOTKEY                                   EQU     6
PID_IS_SHOWCMD                                  EQU     7
PID_IS_ICONINDEX                                EQU     8
PID_IS_ICONFILE                                 EQU     9
PID_IS_WHATSNEW                                 EQU     10
PID_IS_AUTHOR                                   EQU     11
PID_IS_DESCRIPTION                              EQU     12
PID_IS_COMMENT                                  EQU     13

PID_INTSITE_WHATSNEW                            EQU     2
PID_INTSITE_AUTHOR                              EQU     3
PID_INTSITE_LASTVISIT                           EQU     4
PID_INTSITE_LASTMOD                             EQU     5
PID_INTSITE_VISITCOUNT                          EQU     6
PID_INTSITE_DESCRIPTION                         EQU     7
PID_INTSITE_COMMENT                             EQU     8
PID_INTSITE_FLAGS                               EQU     9
PID_INTSITE_CONTENTLEN                          EQU     10
PID_INTSITE_CONTENTCODE                         EQU     11
PID_INTSITE_RECURSE                             EQU     12
PID_INTSITE_WATCH                               EQU     13
PID_INTSITE_SUBSCRIPTION                        EQU     14
PID_INTSITE_URL                                 EQU     15
PID_INTSITE_TITLE                               EQU     16
PID_INTSITE_CODEPAGE                            EQU     18
PID_INTSITE_TRACKING                            EQU     19
PID_INTSITE_ICONINDEX                           EQU     20
PID_INTSITE_ICONFILE                            EQU     21

PIDISF_RECENTLYCHANGED                          EQU     000000001H
PIDISF_CACHEDSTICKY                             EQU     000000002H
PIDISF_CACHEIMAGES                              EQU     000000010H
PIDISF_FOLLOWALLLINKS                           EQU     000000020H

PIDISM_GLOBAL                                   EQU     0
PIDISM_WATCH                                    EQU     1
PIDISM_DONTWATCH                                EQU     2

SSF_SHOWALLOBJECTS                              EQU     000000001H
SSF_SHOWEXTENSIONS                              EQU     000000002H
SSF_SHOWCOMPCOLOR                               EQU     000000008H
SSF_SHOWSYSFILES                                EQU     000000020H
SSF_DOUBLECLICKINWEBVIEW                        EQU     000000080H
SSF_SHOWATTRIBCOL                               EQU     000000100H
SSF_DESKTOPHTML                                 EQU     000000200H
SSF_WIN95CLASSIC                                EQU     000000400H
SSF_DONTPRETTYPATH                              EQU     000000800H
SSF_SHOWINFOTIP                                 EQU     000002000H
SSF_MAPNETDRVBUTTON                             EQU     000001000H
SSF_NOCONFIRMRECYCLE                            EQU     000008000H
SSF_HIDEICONS                                   EQU     000004000H

SHPPFW_NONE                                     EQU     000000000H
SHPPFW_DEFAULT                                  EQU     SHPPFW_DIRCREATE
SHPPFW_DIRCREATE                                EQU     000000001H
SHPPFW_ASKDIRCREATE                             EQU     000000002H
SHPPFW_IGNOREFILENAME                           EQU     000000004H
SHPPFW_NOWRITECHECK                             EQU     000000008H
IF (NTDDI_VERSION GE NTDDI_WINXP)
    SHPPFW_MEDIACHECKONLY                       EQU     000000010H
ENDIF

KF_FLAG_CREATE                                  EQU     000008000H
KF_FLAG_DONT_VERIFY                             EQU     000004000H
KF_FLAG_DONT_UNEXPAND                           EQU     000002000H
KF_FLAG_NO_ALIAS                                EQU     000001000H
KF_FLAG_INIT                                    EQU     000000800H
KF_FLAG_DEFAULT_PATH                            EQU     000000400H
KF_FLAG_NOT_PARENT_RELATIVE                     EQU     000000200H
KF_FLAG_SIMPLE_IDLIST                           EQU     000000100H

SHIMSTCAPFLAG_LOCKABLE                          EQU     00001H
SHIMSTCAPFLAG_PURGEABLE                         EQU     00002H

VALIDATEUNC_CONNECT                             EQU     00001H
VALIDATEUNC_NOUI                                EQU     00002H
VALIDATEUNC_PRINT                               EQU     00004H
IF (NTDDI_VERSION GE NTDDI_VISTA)
    VALIDATEUNC_PERSIST                         EQU     00008H
    VALIDATEUNC_VALID                           EQU     0000FH

    DROPIMAGE_INVALID                           EQU     (-1)
    DROPIMAGE_NONE                              EQU     0
    DROPIMAGE_COPY                              EQU     DROPEFFECT_COPY
    DROPIMAGE_MOVE                              EQU     DROPEFFECT_MOVE
    DROPIMAGE_LINK                              EQU     DROPEFFECT_LINK
    DROPIMAGE_LABEL                             EQU     6
    DROPIMAGE_WARNING                           EQU     7
ELSE
    VALIDATEUNC_VALID                           EQU     00007H
ENDIF

CM_MASK_WIDTH                                   EQU     001H
CM_MASK_DEFAULTWIDTH                            EQU     002H
CM_MASK_IDEALWIDTH                              EQU     004H
CM_MASK_NAME                                    EQU     008H
CM_MASK_STATE                                   EQU     010H

CM_STATE_NONE                                   EQU     000H
CM_STATE_VISIBLE                                EQU     001H
CM_STATE_FIXEDWIDTH                             EQU     002H
CM_STATE_NOSORTBYFOLDERNESS                     EQU     004H
CM_STATE_ALWAYSVISIBLE                          EQU     008H

CM_ENUM_ALL                                     EQU     901H
CM_ENUM_VISIBLE                                 EQU     902H

CM_WIDTH_USEDEFAULT                             EQU     (-1)
CM_WIDTH_AUTOSIZE                               EQU     (-2)


CSIDL_FLAG_PFTI_TRACKTARGET                     EQU     CSIDL_FLAG_DONT_VERIFY

SLR_NO_UI                                       EQU     00001H
SLR_ANY_MATCH                                   EQU     00002H
SLR_UPDATE                                      EQU     00004H
SLR_NOUPDATE                                    EQU     00008H
SLR_NOSEARCH                                    EQU     00010H
SLR_NOTRACK                                     EQU     00020H
SLR_NOLINKINFO                                  EQU     00040H
SLR_INVOKE_MSI                                  EQU     00080H
SLR_NO_UI_WITH_MSG_PUMP                         EQU     00101H
SLR_OFFER_DELETE_WITHOUT_FILE                   EQU     00200H
SLR_KNOWNFOLDER                                 EQU     00400H
SLR_MACHINE_IN_LOCAL_TARGET                     EQU     00800H
SLR_UPDATE_MACHINE_AND_SID                      EQU     01000H

SLGP_SHORTPATH                                  EQU     00001H
SLGP_UNCPRIORITY                                EQU     00002H
SLGP_RAWPATH                                    EQU     00004H
SLGP_RELATIVEPRIORITY                           EQU     00008H

SLDF_HAS_ID_LIST                                EQU     00000001H
SLDF_HAS_LINK_INFO                              EQU     00000002H
SLDF_HAS_NAME                                   EQU     00000004H
SLDF_HAS_RELPATH                                EQU     00000008H
SLDF_HAS_WORKINGDIR                             EQU     00000010H
SLDF_HAS_ARGS                                   EQU     00000020H
SLDF_HAS_ICONLOCATION                           EQU     00000040H
SLDF_UNICODE                                    EQU     00000080H
SLDF_FORCE_NO_LINKINFO                          EQU     00000100H
SLDF_HAS_EXP_SZ                                 EQU     00000200H
SLDF_RUN_IN_SEPARATE                            EQU     00000400H
SLDF_HAS_LOGO3ID                                EQU     00000800H
SLDF_HAS_DARWINID                               EQU     00001000H
SLDF_RUNAS_USER                                 EQU     00002000H
SLDF_HAS_EXP_ICON_SZ                            EQU     00004000H
SLDF_NO_PIDL_ALIAS                              EQU     00008000H
SLDF_FORCE_UNCNAME                              EQU     00010000H
SLDF_RUN_WITH_SHIMLAYER                         EQU     00020000H
SLDF_FORCE_NO_LINKTRACK                         EQU     00040000H
SLDF_ENABLE_TARGET_METADATA                     EQU     00080000H
SLDF_DISABLE_KNOWNFOLDER_RELATIVE_TRACKING      EQU     00200000H
SLDF_VALID                                      EQU     003FF7FFH
SLDF_RESERVED                                   EQU     80000000H

EXP_DARWIN_ID_SIG                               EQU     0A0000006H
EXP_LOGO3_ID_SIG                                EQU     0A0000007H

EXP_SPECIAL_FOLDER_SIG                          EQU     0A0000005H

EXP_SZ_LINK_SIG                                 EQU     0A0000001H
EXP_SZ_ICON_SIG                                 EQU     0A0000007H

EXP_PROPERTYSTORAGE_SIG                         EQU     0A0000009H

IFNDEF FWF_CHECKSELECT
    FWF_AUTOARRANGE                             EQU     000001H
    FWF_ABBREVIATEDNAMES                        EQU     000002H
    FWF_SNAPTOGRID                              EQU     000004H
    FWF_OWNERDATA                               EQU     000008H
    FWF_BESTFITWINDOW                           EQU     000010H
    FWF_DESKTOP                                 EQU     000020H
    FWF_SINGLESEL                               EQU     000040H
    FWF_NOSUBFOLDERS                            EQU     000080H
    FWF_TRANSPARENT                             EQU     000100H
    FWF_NOCLIENTEDGE                            EQU     000200H
    FWF_NOSCROLL                                EQU     000400H
    FWF_ALIGNLEFT                               EQU     000800H
    FWF_NOICONS                                 EQU     001000H
    FWF_SHOWSELALWAYS                           EQU     002000H
    FWF_NOVISIBLE                               EQU     004000H
    FWF_SINGLECLICKACTIVATE                     EQU     008000H
    FWF_NOWEBVIEW                               EQU     010000H
    FWF_HIDEFILENAMES                           EQU     020000H
    FWF_CHECKSELECT                             EQU     040000H
ENDIF

IFNDEF FVM_LAST
    FVM_FIRST                                   EQU     1
    FVM_ICON                                    EQU     1
    FVM_SMALLICON                               EQU     2
    FVM_LIST                                    EQU     3
    FVM_DETAILS                                 EQU     4
    FVM_THUMBNAIL                               EQU     5
    FVM_TILE                                    EQU     6
    FVM_THUMBSTRIP                              EQU     7
    FVM_LAST                                    EQU     7
ENDIF

IFNDEF FLVM_LAST
    FLVM_UNSPECIFIED                            EQU     (-1)
    FLVM_FIRST                                  EQU     1
    FLVM_DETAILS                                EQU     1
    FLVM_TILES                                  EQU     2
    FLVM_ICONS                                  EQU     3
    FLVM_LIST                                   EQU     4
    FLVM_CONTENT                                EQU     5
    FLVM_LAST                                   EQU     5
ENDIF

SBSC_HIDE                                       EQU     0
SBSC_SHOW                                       EQU     1
SBSC_TOGGLE                                     EQU     2
SBSC_QUERY                                      EQU     3

SBO_DEFAULT                                     EQU     0
SBO_NOBROWSERPAGES                              EQU     1

IFNDEF SVUIA_INPLACEACTIVATE
    SVUIA_DEACTIVATE                            EQU     0
    SVUIA_ACTIVATE_NOFOCUS                      EQU     1
    SVUIA_ACTIVATE_FOCUS                        EQU     2
    SVUIA_INPLACEACTIVATE                       EQU     3
ENDIF

SV3CVW3_DEFAULT                                 EQU     0
SV3CVW3_NONINTERACTIVE                          EQU     01H
SV3CVW3_FORCEVIEWMODE                           EQU     02H
SV3CVW3_FORCEFOLDERFLAGS                        EQU     04H

VPWF_DEFAULT                                    EQU     0
VPWF_ALPHABLEND                                 EQU     1

VPCF_TEXT                                       EQU     1
VPCF_BACKGROUND                                 EQU     2
VPCF_SORTCOLUMN                                 EQU     3
VPCF_SUBTEXT                                    EQU     4
VPCF_TEXTBACKGROUND                             EQU     5

CDBOSC_SETFOCUS                                 EQU     00000000H
CDBOSC_KILLFOCUS                                EQU     00000001H
CDBOSC_SELCHANGE                                EQU     00000002H
CDBOSC_RENAME                                   EQU     00000003H
CDBOSC_STATECHANGE                              EQU     00000004H

SORT_DESCENDING                                 EQU     (-1)
SORT_ASCENDING                                  EQU     1

FVST_EMPTYTEXT                                  EQU     0

SHGFP_TYPE_CURRENT                              EQU     0
SHGFP_TYPE_DEFAULT                              EQU     1

IFNDEF SHGDN_FORPARSING
    SHGDN_NORMAL                                EQU     0000H
    SHGDN_INFOLDER                              EQU     0001H
    SHGDN_FOREDITING                            EQU     1000H
    SHGDN_FORADDRESSBAR                         EQU     4000H
    SHGDN_FORPARSING                            EQU     8000H
ENDIF

IFNDEF SHCONTF_STORAGE
    SHCONTF_FOLDERS                             EQU     0020H
    SHCONTF_NONFOLDERS                          EQU     0040H
    SHCONTF_INCLUDEHIDDEN                       EQU     0080H
    SHCONTF_INIT_ON_FIRST_NEXT                  EQU     0100H
    SHCONTF_NETPRINTERSRCH                      EQU     0200H
    SHCONTF_SHAREABLE                           EQU     0400H
    SHCONTF_STORAGE                             EQU     0800H
ENDIF

IFNDEF SHCOLSTATE_PREFER_VARCMP
    SHCOLSTATE_TYPE_STR                         EQU     00001H
    SHCOLSTATE_TYPE_INT                         EQU     00002H
    SHCOLSTATE_TYPE_DATE                        EQU     00003H
    SHCOLSTATE_TYPEMASK                         EQU     0000FH
    SHCOLSTATE_ONBYDEFAULT                      EQU     00010H
    SHCOLSTATE_SLOW                             EQU     00020H
    SHCOLSTATE_EXTENDED                         EQU     00040H
    SHCOLSTATE_SECONDARYUI                      EQU     00080H
    SHCOLSTATE_HIDDEN                           EQU     00100H
    SHCOLSTATE_PREFER_VARCMP                    EQU     00200H
ENDIF

ISFB_MASK_STATE                                 EQU     00000001H
ISFB_MASK_BKCOLOR                               EQU     00000002H
ISFB_MASK_VIEWMODE                              EQU     00000004H
ISFB_MASK_SHELLFOLDER                           EQU     00000008H
ISFB_MASK_IDLIST                                EQU     00000010H
ISFB_MASK_COLORS                                EQU     00000020H

ISFB_STATE_DEFAULT                              EQU     00000000H
ISFB_STATE_DEBOSSED                             EQU     00000001H
ISFB_STATE_ALLOWRENAME                          EQU     00000002H
ISFB_STATE_NOSHOWTEXT                           EQU     00000004H
ISFB_STATE_CHANNELBAR                           EQU     00000010H
ISFB_STATE_QLINKSMODE                           EQU     00000020H
ISFB_STATE_FULLOPEN                             EQU     00000040H
ISFB_STATE_NONAMESORT                           EQU     00000080H
ISFB_STATE_BTNMINSIZE                           EQU     00000100H

ISFBVIEWMODE_SMALLICONS                         EQU     0001H
ISFBVIEWMODE_LARGEICONS                         EQU     0002H
ISFBVIEWMODE_LOGOS                              EQU     0003H

ACLO_NONE                                       EQU     0
ACLO_CURRENTDIR                                 EQU     1
ACLO_MYCOMPUTER                                 EQU     2
ACLO_DESKTOP                                    EQU     4
ACLO_FAVORITES                                  EQU     8
ACLO_FILESYSONLY                                EQU     16
ACLO_FILESYSDIRS                                EQU     32
ACLO_VIRTUALNAMESPACE                           EQU     64


;======================================== Structures ======================================;
IFNDEF POINT
    POINT STRUCT ALIGNMODE
        x   DD  ?
        y   DD  ?
    POINT ENDS
ENDIF

IFNDEF GUID
    GUID STRUCT ALIGNMODE
        Data1   DD
        Data2   DW
        Data3   DW
        Data4   DB 8 DUP(?)
    GUID ENDS
ENDIF

IFNDEF SIZEL
    SIZEL STRUCT ALIGNMODE
        x   DD  ?
        y   DD  ?
    SIZEL ENDS
ENDIF

IFNDEF POINTL
    POINTL STRUCT ALIGNMODE
        x   DD  ?
        y   DD  ?
    POINTL ENDS
ENDIF

IFNDEF COORD
    COORD STRUCT ALIGNMODE
        X DW ?
        Y DW ?
    COORD ENDS
ENDIF

IFNDEF Unknown
    Unknown STRUCT ALIGNMODE
        QueryInterface          XPTR ?
        AddRef                  XPTR ?
        Release                 XPTR ?
    Unknown ENDS
ENDIF

IF (NTDDI_VERSION GE NTDDI_WIN7)
    STR_BIND_FOLDERS_READ_ONLY  EQU L("Folders As Read Only")
    STR_BIND_FOLDER_ENUM_MODE   EQU L("Folder Enum Mode")

    FEM_VIEWRESULT              EQU 0
    FEM_NAVIGATION              EQU 1

    IObjectWithFolderEnumMode STRUCT ALIGNMODE
        UNION
            STRUCT
                QueryInterface  XPTR ?
                AddRef          XPTR ?
                Release         XPTR ?
            ENDS
            IUnknown            Unknown <>
        ENDS
        SetMode                 XPTR ?
        GetMode                 XPTR ?
    IObjectWithFolderEnumMode ENDS

    STR_PARSE_WITH_EXPLICIT_PROGID              EQU L("ExplicitProgid")
    STR_PARSE_WITH_EXPLICIT_ASSOCAPP            EQU L("ExplicitAssociationApp")
    STR_PARSE_EXPLICIT_ASSOCIATION_SUCCESSFUL   EQU L("ExplicitAssociationSuccessful")
    STR_PARSE_AND_CREATE_ITEM                   EQU L("ParseAndCreateItem")

    IParseAndCreateItem STRUCT ALIGNMODE
        UNION
            STRUCT
                QueryInterface  XPTR ?
                AddRef          XPTR ?
                Release         XPTR ?
            ENDS
            IUnknown            Unknown <>
        ENDS
        SetItem                 XPTR ?
        GetItem                 XPTR ?
    IParseAndCreateItem ENDS
    
    STR_ITEM_CACHE_CONTEXT      EQU L("ItemCacheContext")
ENDIF

CM_COLUMNINFO Struct ALIGNMODE
    cbSize          DD ?
    dwMask          DD ?
    dwState         DD ?
    uWidth          DD ?
    uDefaultWidth   DD ?
    uIdealWidth     DD ?
    wszName         WCHAR 80 DUP(?)
CM_COLUMNINFO ENDS

ENUMSHELLIMAGESTOREDATA STRUCT ALIGNMODE
    szPath      DW MAX_PATH DUP(?)
    ftTimeStamp FILETIME <>
ENUMSHELLIMAGESTOREDATA ENDS

SHFOLDERCUSTOMSETTINGS STRUCT ALIGNMODE
    dwSize                      DD   ?
    dwMask                      DD   ?
    pvid                        XPTR ?
    pszWebViewTemplate          XPTR ?
    cchWebViewTemplate          DD   ?
    pszWebViewTemplateVersion   XPTR ?
    pszInfoTip                  XPTR ?
    cchInfoTip                  DD   ?
    pclsid                      XPTR ?
    dwFlags                     DD   ?
    pszIconFile                 XPTR ?
    cchIconFile                 DD   ?
    iIconIndex                  DD   ?
    pszLogo                     XPTR ?
    cchLogo                     DD   ?
SHFOLDERCUSTOMSETTINGS ENDS

SHITEMID STRUCT ALIGNMODE
    cb      DW ?
    abID    DB ?
SHITEMID ENDS

ITEMIDLIST STRUCT ALIGNMODE
    mkid SHITEMID <>
ITEMIDLIST ENDS

CMINVOKECOMMANDINFO STRUCT ALIGNMODE
    cbSize          DD     ?
    fMask           DD     ?
    hwnd            HANDLE ?
    lpVerb          XPTR   ?
    lpParameters    XPTR   ?
    lpDirectory     XPTR   ?
    nShow           DD     ?
    dwHotKey        DD     ?
    hIcon           HANDLE ?
CMINVOKECOMMANDINFO ENDS

CMINVOKECOMMANDINFOEX STRUCT ALIGNMODE
    cbSize          DD     ?
    fMask           DD     ?
    hwnd            HANDLE ?
    lpVerb          XPTR   ?
    lpParameters    XPTR   ?
    lpDirectory     XPTR   ?
    nShow           DD     ?
    dwHotKey        DD     ?
    hIcon           HANDLE ?
    lpTitle         XPTR   ?
    lpVerbW         XPTR   ?
    lpParametersW   XPTR   ?
    lpDirectoryW    XPTR   ?
    lpTitleW        XPTR   ?
    ptInvoke        POINT  <>
CMINVOKECOMMANDINFOEX ENDS

IContextMenu STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    QueryContextMenu        XPTR ?
    InvokeCommand           XPTR ?
    GetCommandString        XPTR ?
IContextMenu ENDS

IContextMenu2 STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    QueryContextMenu        XPTR ?
    InvokeCommand           XPTR ?
    GetCommandString        XPTR ?
    HandleMenuMsg           XPTR ?
IContextMenu2 ENDS

IContextMenu3 STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    QueryContextMenu        XPTR ?
    InvokeCommand           XPTR ?
    GetCommandString        XPTR ?
    HandleMenuMsg           XPTR ?
    HandleMenuMsg2          XPTR ?
IContextMenu3 ENDS

IShellExtInit STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    Initialize              XPTR ?
IShellExtInit ENDS

IShellPropSheetExt STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    AddPages                XPTR ?
    ReplacePage             XPTR ?
IShellPropSheetExt ENDS

IFNDEF IPersistFolder
    IPersistFolder STRUCT ALIGNMODE
        UNION
            STRUCT
                QueryInterface  XPTR ?
                AddRef          XPTR ?
                Release         XPTR ?
            ENDS
            IUnknown            Unknown <>
        ENDS
        GetClassID              XPTR ?
        Initialize              XPTR ?
    IPersistFolder ENDS
ENDIF

IFNDEF IPersistFolder2
    IPersistFolder2 STRUCT ALIGNMODE
        UNION
            STRUCT
                QueryInterface  XPTR ?
                AddRef          XPTR ?
                Release         XPTR ?
            ENDS
            IUnknown            Unknown <>
        ENDS
        GetClassID              XPTR ?
        Initialize              XPTR ?
        GetCurFolder            XPTR ?
    IPersistFolder2 ENDS
ENDIF

PERSIST_FOLDER_TARGET_INFO STRUCT ALIGNMODE
    pidlTargetFolder    XPTR ?
    szTargetParsingName DW   MAX_PATH DUP(?)
    szNetworkProvider   DW   MAX_PATH DUP(?)
    dwAttributes        DD   ?
    csidl               DD   ?
PERSIST_FOLDER_TARGET_INFO ENDS

IPersistFolder3 STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    GetClassID              XPTR ?
    Initialize              XPTR ?
    GetCurFolder            XPTR ?
    InitializeEx            XPTR ?
    GetFolderTargetInfo     XPTR ?
IPersistFolder3 ENDS

IPersistIDList STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    GetClassID              XPTR ?
    SetIDList               XPTR ?
    GetIDList               XPTR ?
IPersistIDList ENDS

IEnumIDList STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    Next                    XPTR ?
    Skip                    XPTR ?
    Reset                   XPTR ?
    Clone                   XPTR ?
IEnumIDList ENDS

IEnumFullIDList STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    Next                    XPTR ?
    Skip                    XPTR ?
    Reset                   XPTR ?
    Clone                   XPTR ?
IEnumFullIDList ENDS

IRemoteComputer STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    Initialize              XPTR ?
IRemoteComputer ENDS

ISearchFolderItemFactory STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface   XPTR ?
            AddRef           XPTR ?
            Release          XPTR ?
        ENDS
        IUnknown             Unknown <>
    ENDS
    SetDisplayName           XPTR ?
    SetFolderTypeID          XPTR ?
    SetFolderLogicalViewMode XPTR ?
    SetIconSize              XPTR ?
    SetVisibleColumns        XPTR ?
    SetSortColumns           XPTR ?
    SetGroupColumn           XPTR ?
    SetStacks                XPTR ?
    SetScope                 XPTR ?
    SetCondition             XPTR ?
    GetShellItem             XPTR ?
    GetIDList                XPTR ?
ISearchFolderItemFactory ENDS

IExtractIconA STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    GetIconLocation         XPTR ?
    Extract                 XPTR ?
IExtractIconA ENDS

IExtractIconW STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    GetIconLocation         XPTR ?
    Extract                 XPTR ?
IExtractIconW ENDS

IShellIcon STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    GetIconOf               XPTR ?
IShellIcon ENDS

IShellIconOverlayIdentifier STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    IsMemberOf              XPTR ?
    GetOverlayInfo          XPTR ?
    GetPriority             XPTR ?
IShellIconOverlayIdentifier ENDS

IShellIconOverlay STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    GetOverlayIndex         XPTR ?
    GetOverlayIconIndex     XPTR ?
IShellIconOverlay ENDS

IShellLinkA STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    GetPath                 XPTR ?
    GetIDList               XPTR ?
    SetIDList               XPTR ?
    GetDescription          XPTR ?
    SetDescription          XPTR ?
    GetWorkingDirectory     XPTR ?
    SetWorkingDirectory     XPTR ?
    GetArguments            XPTR ?
    SetArguments            XPTR ?
    GetHotkey               XPTR ?
    SetHotkey               XPTR ?
    GetShowCmd              XPTR ?
    SetShowCmd              XPTR ?
    GetIconLocation         XPTR ?
    SetIconLocation         XPTR ?
    SetRelativePath         XPTR ?
    Resolve                 XPTR ?
    SetPath                 XPTR ?
IShellLinkA ENDS

IShellLinkW STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    GetPath                 XPTR ?
    GetIDList               XPTR ?
    SetIDList               XPTR ?
    GetDescription          XPTR ?
    SetDescription          XPTR ?
    GetWorkingDirectory     XPTR ?
    SetWorkingDirectory     XPTR ?
    GetArguments            XPTR ?
    SetArguments            XPTR ?
    GetHotkey               XPTR ?
    SetHotkey               XPTR ?
    GetShowCmd              XPTR ?
    SetShowCmd              XPTR ?
    GetIconLocation         XPTR ?
    SetIconLocation         XPTR ?
    SetRelativePath         XPTR ?
    Resolve                 XPTR ?
    SetPath                 XPTR ?
IShellLinkW ENDS

DATABLOCK_HEADER STRUCT ALIGNMODE
    cbSize      DD ?
    dwSignature DD ?
DATABLOCK_HEADER ENDS

NT_CONSOLE_PROPS STRUCT ALIGNMODE
    dbh                     DATABLOCK_HEADER <>
    wFillAttribute          DW    ?
    wPopupFillAttribute     DW    ?
    dwScreenBufferSize      COORD <>
    dwWindowSize            COORD <>
    dwWindowOrigin          COORD <>
    nFont                   DD    ?
    nInputBufferSize        DD    ?
    dwFontSize              COORD <>
    uFontFamily             DD    ?
    uFontWeight             DD    ?
    FaceName                DW    LF_FACESIZE DUP(?)
    uCursorSize             DD    ?
    bFullScreen             DD    ?
    bQuickEdit              DD    ?
    bInsertMode             DD    ?
    bAutoPosition           DD    ?
    uHistoryBufferSize      DD    ?
    uNumberOfHistoryBuffers DD    ?
    bHistoryNoDup           DD    ?
    ColorTable              DD    16 DUP(?)
NT_CONSOLE_PROPS ENDS

NT_FE_CONSOLE_PROPS STRUCT ALIGNMODE
    dbh         DATABLOCK_HEADER <>
    uCodePage   DD ?
NT_FE_CONSOLE_PROPS ENDS

EXP_DARWIN_LINK STRUCT ALIGNMODE
    dbh         DATABLOCK_HEADER <>
    szDarwinID  DB MAX_PATH DUP(?)
    szwDarwinID DW MAX_PATH DUP(?)
EXP_DARWIN_LINK ENDS

EXP_SPECIAL_FOLDER STRUCT ALIGNMODE
    cbSize          DD ?
    dwSignature     DD ?
    idSpecialFolder DD ?
    cbOffset        DD ?
EXP_SPECIAL_FOLDER ENDS

EXP_SZ_LINK STRUCT ALIGNMODE
    cbSize      DD ?
    dwSignature DD ?
    szTarget    DB MAX_PATH DUP(?)
    swzTarget   DW MAX_PATH DUP(?)
EXP_SZ_LINK ENDS

EXP_PROPERTYSTORAGE STRUCT ALIGNMODE
    cbSize              DD ?
    dwSignature         DD ?
    abPropertyStorage   DB ?
EXP_PROPERTYSTORAGE ENDS

IShellLinkDataList STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    AddDataBlock            XPTR ?
    CopyDataBlock           XPTR ?
    RemoveDataBlock         XPTR ?
    GetFlags                XPTR ?
    SetFlags                XPTR ?
IShellLinkDataList ENDS

IResolveShellLink STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    ResolveShellLink        XPTR ?
IResolveShellLink ENDS

IShellExecuteHookA STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    Execute                 XPTR ?
IShellExecuteHookA ENDS

IShellExecuteHookW STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    Execute                 XPTR ?
IShellExecuteHookW ENDS

IURLSearchHook STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    Translate               XPTR ?
IURLSearchHook ENDS

ISearchContext STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    GetSearchUrl            XPTR ?
    GetSearchText           XPTR ?
    GetSearchStyle          XPTR ?
ISearchContext ENDS

IURLSearchHook2 STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    Translate                   XPTR ?
    TranslateWithSearchContext  XPTR ?
IURLSearchHook2 ENDS

INewShortcutHookA STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    SetReferent             XPTR ?
    GetReferent             XPTR ?
    SetFolder               XPTR ?
    GetFolder               XPTR ?
    GetName                 XPTR ?
    GetExtension            XPTR ?
INewShortcutHookA ENDS

INewShortcutHookW STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    SetReferent             XPTR ?
    GetReferent             XPTR ?
    SetFolder               XPTR ?
    GetFolder               XPTR ?
    GetName                 XPTR ?
    GetExtension            XPTR ?
INewShortcutHookW ENDS

ICopyHookA STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    CopyCallback            XPTR ?
ICopyHookA ENDS

ICopyHookW STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    CopyCallback            XPTR ?
ICopyHookW ENDS

IFileViewerSite STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    SetPinnedWindow         XPTR ?
    GetPinnedWindow         XPTR ?
IFileViewerSite ENDS

FVSHOWINFO STRUCT ALIGNMODE
    cbSize      DD     ?
    hwndOwner   HANDLE ?
    iShow       DD     ?
    dwFlags     DD     ?
    rect        RECT   <>
    punkRel     XPTR   ?
    strNewFile  DW     MAX_PATH Dup(?)
FVSHOWINFO ENDS

IFileViewerA STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    ShowInitialize          XPTR ?
    Show                    XPTR ?
    PrintTo                 XPTR ?
IFileViewerA ENDS

IFileViewerW STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    ShowInitialize          XPTR ?
    Show                    XPTR ?
    PrintTo                 XPTR ?
IFileViewerW ENDS

IFNDEF FOLDERSETTINGS
    FOLDERSETTINGS STRUCT ALIGNMODE
        ViewMode DD ?
        fFlags   DD ?
    FOLDERSETTINGS ENDS
ENDIF

IShellBrowser STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    GetWindow               XPTR ?
    ContextSensitiveHelp    XPTR ?
    InsertMenusSB           XPTR ?
    SetMenuSB               XPTR ?
    RemoveMenusSB           XPTR ?
    SetStatusTextSB         XPTR ?
    EnableModelessSB        XPTR ?
    TranslateAcceleratorSB  XPTR ?
    BrowseObject            XPTR ?
    GetViewStateStream      XPTR ?
    GetControlWindow        XPTR ?
    SendControlMsg          XPTR ?
    QueryActiveShellView    XPTR ?
    OnViewWindowActive      XPTR ?
    SetToolbarItems         XPTR ?
IShellBrowser ENDS

ICommDlgBrowser STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    OnDefaultCommand        XPTR ?
    OnStateChange           XPTR ?
    IncludeObject           XPTR ?
ICommDlgBrowser ENDS

ICommDlgBrowser2 STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    OnDefaultCommand        XPTR ?
    OnStateChange           XPTR ?
    IncludeObject           XPTR ?
    Notify                  XPTR ?
    GetDefaultMenuText      XPTR ?
    GetViewFlags            XPTR ?
ICommDlgBrowser2 ENDS

ICommDlgBrowser3 STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    OnDefaultCommand        XPTR ?
    OnStateChange           XPTR ?
    IncludeObject           XPTR ?
    Notify                  XPTR ?
    GetDefaultMenuText      XPTR ?
    GetViewFlags            XPTR ?
    OnColumnClicked         XPTR ?
    GetCurrentFilter        XPTR ?
    OnPreViewCreated        XPTR ?
ICommDlgBrowser3 ENDS

IFNDEF IShellView
    IShellView STRUCT ALIGNMODE
        UNION
            STRUCT
                QueryInterface  XPTR ?
                AddRef          XPTR ?
                Release         XPTR ?
            ENDS
            IUnknown            Unknown <>
        ENDS
        GetWindow               XPTR ?
        ContextSensitiveHelp    XPTR ?
        TranslateAccelerator    XPTR ?
        EnableModeless          XPTR ?
        UIActivate              XPTR ?
        Refresh                 XPTR ?
        CreateViewWindow        XPTR ?
        DestroyViewWindow       XPTR ?
        GetCurrentInfo          XPTR ?
        AddPropertySheetPages   XPTR ?
        SaveViewState           XPTR ?
        SelectItem              XPTR ?
        GetItemObject           XPTR ?
    IShellView ENDS
ENDIF

SV2CVW2_PARAMS STRUCT ALIGNMODE
    cbSize      DD     ?
    psvPrev     XPTR   ?
    pfs         XPTR   ?
    psbOwner    XPTR   ?
    prcView     XPTR   ?
    pvid        XPTR   ?
    hwndView    HANDLE ?
SV2CVW2_PARAMS ENDS

IShellView2 STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    GetWindow                   XPTR ?
    ContextSensitiveHelp        XPTR ?
    TranslateAccelerator        XPTR ?
    EnableModeless              XPTR ?
    UIActivate                  XPTR ?
    Refresh                     XPTR ?
    CreateViewWindow            XPTR ?
    DestroyViewWindow           XPTR ?
    GetCurrentInfo              XPTR ?
    AddPropertySheetPages       XPTR ?
    SaveViewState               XPTR ?
    SelectItem                  XPTR ?
    GetItemObject               XPTR ?
    GetView                     XPTR ?
    CreateViewWindow2           XPTR ?
    HandleRename                XPTR ?
    SelectAndPositionItem       XPTR ?
IShellView2 ENDS

IShellView3 STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    GetWindow               XPTR ?
    ContextSensitiveHelp    XPTR ?
    TranslateAccelerator    XPTR ?
    EnableModeless          XPTR ?
    UIActivate              XPTR ?
    Refresh                 XPTR ?
    CreateViewWindow        XPTR ?
    DestroyViewWindow       XPTR ?
    GetCurrentInfo          XPTR ?
    AddPropertySheetPages   XPTR ?
    SaveViewState           XPTR ?
    SelectItem              XPTR ?
    GetItemObject           XPTR ?
    GetView                 XPTR ?
    CreateViewWindow2       XPTR ?
    HandleRename            XPTR ?
    SelectAndPositionItem   XPTR ?
    CreateViewWindow3       XPTR ?
IShellView3 ENDS

IFolderView STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    GetCurrentViewMode      XPTR ?
    SetCurrentViewMode      XPTR ?
    GetFolder               XPTR ?
    Item                    XPTR ?
    ItemCount               XPTR ?
    Items                   XPTR ?
    GetSelectionMarkedItem  XPTR ?
    GetFocusedItem          XPTR ?
    GetItemPosition         XPTR ?
    GetSpacing              XPTR ?
    GetDefaultSpacing       XPTR ?
    GetAutoArrange          XPTR ?
    SelectItem              XPTR ?
    SelectAndPositionItems  XPTR ?
IFolderView ENDS

IFolderView2 STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface          XPTR ?
            AddRef                  XPTR ?
            Release                 XPTR ?
        ENDS
        IUnknown                    Unknown <>
    ENDS
    GetCurrentViewMode              XPTR ?
    SetCurrentViewMode              XPTR ?
    GetFolder                       XPTR ?
    Item                            XPTR ?
    ItemCount                       XPTR ?
    Items                           XPTR ?
    GetSelectionMarkedItem          XPTR ?
    GetFocusedItem                  XPTR ?
    GetItemPosition                 XPTR ?
    GetSpacing                      XPTR ?
    GetDefaultSpacing               XPTR ?
    GetAutoArrange                  XPTR ?
    SelectItem                      XPTR ?
    SelectAndPositionItems          XPTR ?
    SetGroupBy                      XPTR ?
    GetGroupBy                      XPTR ?
    SetViewProperty                 XPTR ?
    GetViewProperty                 XPTR ?
    SetTileViewProperties           XPTR ?
    SetExtendedTileViewProperties   XPTR ?
    SetText                         XPTR ?
    SetCurrentFolderFlags           XPTR ?
    GetCurrentFolderFlags           XPTR ?
    GetSortColumnCount              XPTR ?
    SetSortColumns                  XPTR ?
    GetSortColumns                  XPTR ?
    GetItem                         XPTR ?
    GetVisibleItem                  XPTR ?
    GetSelectedItem                 XPTR ?
    GetSelection                    XPTR ?
    GetSelectionState               XPTR ?
    InvokeVerbOnSelection           XPTR ?
    SetViewModeAndIconSize          XPTR ?
    GetViewModeAndIconSize          XPTR ?
    SetGroupSubsetCount             XPTR ?
    GetGroupSubsetCount             XPTR ?
    SetRedraw                       XPTR ?
    IsMoveInSameFolder              XPTR ?
    DoRename                        XPTR ?
IFolderView2 ENDS

IPreviewHandlerVisuals STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    SetBackgroundColor      XPTR ?
    SetFont                 XPTR ?
    SetTextColor            XPTR ?
IPreviewHandlerVisuals ENDS

IVisualProperties STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    SetWatermark            XPTR ?
    SetColor                XPTR ?
    GetColor                XPTR ?
    SetItemHeight           XPTR ?
    GetItemHeight           XPTR ?
    SetFont                 XPTR ?
    GetFont                 XPTR ?
    SetTheme                XPTR ?
IVisualProperties ENDS

IColumnManager STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    SetColumnInfo           XPTR ?
    GetColumnInfo           XPTR ?
    GetColumnCount          XPTR ?
    GetColumns              XPTR ?
    SetColumns              XPTR ?
IColumnManager ENDS

IFolderFilterSite STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    SetFilter               XPTR ?
IFolderFilterSite ENDS

IFolderFilter STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    ShouldShow                  XPTR ?
    GetEnumFlags                XPTR ?
IFolderFilter ENDS

IInputObjectSite STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    OnFocusChangeIS         XPTR ?
IInputObjectSite ENDS

IInputObject STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    UIActivateIO            XPTR ?
    HasFocusIO              XPTR ?
    TranslateAcceleratorIO  XPTR ?
IInputObject ENDS

IInputObject2 STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    UIActivateIO                XPTR ?
    HasFocusIO                  XPTR ?
    TranslateAcceleratorIO      XPTR ?
    TranslateAcceleratorGlobal  XPTR ?
IInputObject2 ENDS

IFolderViewSettings STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    GetColumnPropertyList   XPTR ?
    GetGroupByProperty      XPTR ?
    GetViewMode             XPTR ?
    GetIconSize             XPTR ?
    GetFolderFlags          XPTR ?
    GetSortColumns          XPTR ?
    GetGroupSubsetCount     XPTR ?
IFolderViewSettings ENDS

ISearchBoxInfo STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    GetCondition            XPTR ?
    GetText                 XPTR ?
ISearchBoxInfo ENDS

IFNDEF PROPERTYKEY
    PROPERTYKEY STRUCT ALIGNMODE
        fmtid   GUID <>
        pid     DD   ?
    PROPERTYKEY ENDS
ENDIF

SORTCOLUMN STRUCT ALIGNMODE
    propkey     PROPERTYKEY <>
    direction   DD ?
SORTCOLUMN ENDS

STRRET STRUCT ALIGNMODE
    uType       DD ?
    UNION
        pOleStr XPTR ?
        pStr    XPTR ?
        uOffset DD  ?
        cStr    DB MAX_PATH DUP(?)
    ENDS
STRRET ENDS

IFNDEF BROWSEINFO
    BROWSEINFOA STRUCT ALIGNMODE
        hwndOwner       HANDLE ?
        pidlRoot        XPTR   ?
        pszDisplayName  XPTR   ?
        lpszTitle       XPTR   ?
        ulFlags         DD     ?
        lpfn            XPTR   ?
        lParam          LPARAM ?
        iImage          DD     ?
    BROWSEINFOA ENDS

    BROWSEINFOW STRUCT ALIGNMODE
        hwndOwner       HANDLE ?
        pidlRoot        XPTR   ?
        pszDisplayName  XPTR   ?
        lpszTitle       XPTR   ?
        ulFlags         DD     ?
        lpfn            XPTR   ?
        lParam          LPARAM ?
        iImage          DD     ?
    BROWSEINFOW ENDS
ENDIF

IFNDEF IEnumIDList
    IEnumIDList STRUCT ALIGNMODE
        UNION
            STRUCT
                QueryInterface  XPTR ?
                AddRef          XPTR ?
                Release         XPTR ?
            ENDS
            IUnknown            Unknown <>
        ENDS
        Next                    XPTR ?
        Skip                    XPTR ?
        Reset                   XPTR ?
        Clone                   XPTR ?
    IEnumIDList ENDS
ENDIF

IFNDEF IShellFolder
    IShellFolder STRUCT ALIGNMODE
        UNION
            STRUCT
                QueryInterface  XPTR ?
                AddRef          XPTR ?
                Release         XPTR ?
            ENDS
            IUnknown            Unknown <>
        ENDS
        ParseDisplayName        XPTR ?
        EnumObjects             XPTR ?
        BindToObject            XPTR ?
        BindToStorage           XPTR ?
        CompareIDs              XPTR ?
        CreateViewObject        XPTR ?
        GetAttributesOf         XPTR ?
        GetUIObjectOf           XPTR ?
        GetDisplayNameOf        XPTR ?
        SetNameOf               XPTR ?
    IShellFolder ENDS
ENDIF

IFileSystemBindData STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    SetFindData             XPTR ?
    GetFindData             XPTR ?
IFileSystemBindData ENDS

SHELLDETAILS STRUCT ALIGNMODE
    fmt     DD     ?
    xcxChar DD     ?
    _str    STRRET <>
SHELLDETAILS ENDS

IShellDetails STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    GetDetailsOf            XPTR ?
    ColumnClick             XPTR ?
IShellDetails ENDS

IFNDEF EXTRASEARCH
    EXTRASEARCH STRUCT ALIGNMODE
        guidSearch      GUID <>
        wszFriendlyName DW 80 DUP(?)
        wszUrl          DW 2084 DUP(?)
    EXTRASEARCH ENDS
ENDIF

IFNDEF IEnumExtraSearch
    IEnumExtraSearch STRUCT ALIGNMODE
        UNION
            STRUCT
                QueryInterface  XPTR ?
                AddRef          XPTR ?
                Release         XPTR ?
            ENDS
            IUnknown            Unknown <>
        ENDS
        Next                    XPTR ?
        Skip                    XPTR ?
        Reset                   XPTR ?
        Clone                   XPTR ?
    IEnumExtraSearch ENDS
ENDIF

IFNDEF SHCOLUMNID
    SHCOLUMNID STRUCT ALIGNMODE
        fmtid   GUID <>
        pid     XPTR ?
    SHCOLUMNID ENDS
ENDIF

IEnumShellImageStore STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    Reset                   XPTR ?
    Next                    XPTR ?
    Skip                    XPTR ?
    Clone                   XPTR ?
IEnumShellImageStore ENDS

IShellImageStore STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    Open                    XPTR ?
    Create                  XPTR ?
    ReleaseLock             XPTR ?
    Close                   XPTR ?
    Commit                  XPTR ?
    IsLocked                XPTR ?
    GetMode                 XPTR ?
    GetCapabilities         XPTR ?
    AddEntry                XPTR ?
    GetEntry                XPTR ?
    DeleteEntry             XPTR ?
    IsEntryInStore          XPTR ?
    Enum                    XPTR ?
IShellImageStore ENDS

IThumbnailCapture STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    CaptureThumbnail        XPTR ?
IThumbnailCapture ENDS

IShellFolder2 STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    ParseDisplayName        XPTR ?
    EnumObjects             XPTR ?
    BindToObject            XPTR ?
    BindToStorage           XPTR ?
    CompareIDs              XPTR ?
    CreateViewObject        XPTR ?
    GetAttributesOf         XPTR ?
    GetUIObjectOf           XPTR ?
    GetDisplayNameOf        XPTR ?
    SetNameOf               XPTR ?
    GetDefaultSearchGUID    XPTR ?
    EnumSearches            XPTR ?
    GetDefaultColumn        XPTR ?
    GetDefaultColumnState   XPTR ?
    GetDetailsEx            XPTR ?
    GetDetailsOf            XPTR ?
    MapColumnToSCID         XPTR ?
IShellFolder2 ENDS

IFNDEF ITaskbarList
    ITaskbarList STRUCT ALIGNMODE
        UNION
            STRUCT
                QueryInterface  XPTR ?
                AddRef          XPTR ?
                Release         XPTR ?
            ENDS
            IUnknown            Unknown <>
        ENDS
        HrInit                  XPTR ?
        AddTab                  XPTR ?
        DeleteTab               XPTR ?
        ActivateTab             XPTR ?
        SetActiveAlt            XPTR ?
    ITaskbarList ENDS
ENDIF

IObjMgr STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    Append                  XPTR ?
    Remove                  XPTR ?
IObjMgr ENDS

ICurrentWorkingDirectory STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    GetDirectory            XPTR ?
    SetDirectory            XPTR ?
ICurrentWorkingDirectory ENDS

IACList STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    Expand                  XPTR ?
IACList ENDS

IACList2 STRUCT ALIGNMODE
    UNION
        struct
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    Expand                  XPTR ?
    SetOptions              XPTR ?
    GetOptions              XPTR ?
IACList2 ENDS

IProgressDialog STRUCT ALIGNMODE
    UNION
        struct
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    StartProgressDialog     XPTR ?
    StopProgressDialog      XPTR ?
    SetTitle                XPTR ?
    SetAnimation            XPTR ?
    HasUserCancelled        XPTR ?
    SetProgress             XPTR ?
    SetProgress64           XPTR ?
    SetLine                 XPTR ?
    SetCancelMsg            XPTR ?
    Timer                   XPTR ?
IProgressDialog ENDS

IDockingWindowSite STRUCT ALIGNMODE
    UNION
        struct
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    GetWindow               XPTR ?
    ContextSensitiveHelp    XPTR ?
    GetBorderDW             XPTR ?
    RequestBorderSpaceDW    XPTR ?
    SetBorderSpaceDW        XPTR ?
IDockingWindowSite ENDS

IDockingWindowFrame STRUCT ALIGNMODE
    UNION
        struct
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    GetWindow               XPTR ?
    ContextSensitiveHelp    XPTR ?
    AddToolbar              XPTR ?
    RemoveToolbar           XPTR ?
    FindToolbar             XPTR ?
IDockingWindowFrame ENDS

IDockingWindow STRUCT ALIGNMODE
    UNION
        struct
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    GetWindow               XPTR ?
    ContextSensitiveHelp    XPTR ?
    ShowDW                  XPTR ?
    CloseDW                 XPTR ?
    ResizeBorderDW          XPTR ?
IDockingWindow ENDS

DESKBANDINFO STRUCT ALIGNMODE
    dwMask      DD     ?
    ptMinSize   POINTL <>
    ptMaxSize   POINTL <>
    ptIntegral  POINTL <>
    ptActual    POINTL <>
    wszTitle    DW     256 DUP(?)
    dwModeFlags DD     ?
    crBkgnd     DD     ?
DESKBANDINFO ENDS

BANDINFOSFB STRUCT ALIGNMODE
    dwMask      DD   ?
    dwStateMask DD   ?
    dwState     DD   ?
    crBkgnd     DD   ?
    crBtnLt     DD   ?
    crBtnDk     DD   ?
    wViewMode   DW   ?
    wAlign      DW   ?
    psf         XPTR ?
    pidl        XPTR ?
BANDINFOSFB ENDS

IShellFolderBand STRUCT ALIGNMODE
    UNION
        struct
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    InitializeSFB           XPTR ?
    SetBandInfoSFB          XPTR ?
    GetBandInfoSFB          XPTR ?
IShellFolderBand ENDS

IDeskBarClient STRUCT ALIGNMODE
    UNION
        struct
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    GetWindow               XPTR ?
    ContextSensitiveHelp    XPTR ?
    SetDeskBarSite          XPTR ?
    SetModeDBC              XPTR ?
    UIActivateDBC           XPTR ?
    GetSize                 XPTR ?
IDeskBarClient ENDS

IDeskBand STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    GetWindow               XPTR ?
    ContextSensitiveHelp    XPTR ?
    ShowDW                  XPTR ?
    CloseDW                 XPTR ?
    ResizeBorderDW          XPTR ?
    GetBandInfo             XPTR ?
IDeskBand ENDS

IRunnableTask STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    Run                     XPTR ?
    Kill                    XPTR ?
    Suspend                 XPTR ?
    Resume                  XPTR ?
    IsRunning               XPTR ?
IRunnableTask ENDS

IExtractImage STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    GetLocation             XPTR ?
    Extract                 XPTR ?
IExtractImage ENDS

IExtractImage2 STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    GetLocation             XPTR ?
    Extract                 XPTR ?
    GetDateStamp            XPTR ?
IExtractImage2 ENDS

WALLPAPEROPT STRUCT ALIGNMODE
    dwSize  DD ?
    dwStyle DD ?
WALLPAPEROPT ENDS

COMPONENTSOPT STRUCT ALIGNMODE
    dwSize              DD ?
    fEnableComponents   DD ?
    fActiveDesktop      DD ?
COMPONENTSOPT ENDS

COMPPOS STRUCT ALIGNMODE
    dwSize                  DD ?
    iLeft                   DD ?
    iTop                    DD ?
    dwWidth                 DD ?
    dwHeight                DD ?
    izIndex                 DD ?
    fCanResize              DD ?
    fCanResizeX             DD ?
    fCanResizeY             DD ?
    iPreferredLeftPercent   DD ?
    iPreferredTopPercent    DD ?
COMPPOS ENDS

COMPSTATEINFO STRUCT ALIGNMODE
    dwSize      DD ?
    iLeft       DD ?
    iTop        DD ?
    dwWidth     DD ?
    dwHeight    DD ?
    dwItemState DD ?
COMPSTATEINFO ENDS

IE4COMPONENT STRUCT ALIGNMODE
    dwSize           DD ?
    dwID             DD ?
    iComponentType   DD ?
    fChecked         DD ?
    fDirty           DD ?
    fNoScroll        DD ?
    cpPos            COMPPOS <>
    wszFriendlyName  DW MAX_PATH DUP(?)
    wszSource        DW INTERNET_MAX_URL_LENGTH DUP(?)
    wszSubscribedURL DW INTERNET_MAX_URL_LENGTH DUP(?)
IE4COMPONENT ENDS

COMPONENT STRUCT ALIGNMODE
    dwSize              DD ?
    dwID                DD ?
    iComponentType      DD ?
    fChecked            DD ?
    fDirty              DD ?
    fNoScroll           DD ?
    cpPos               COMPPOS <>
    wszFriendlyName     DW MAX_PATH DUP(?)
    wszSource           DW INTERNET_MAX_URL_LENGTH DUP(?)
    wszSubscribedURL    DW INTERNET_MAX_URL_LENGTH DUP(?)
    dwCurItemState      DD ?
    csiOriginal         COMPSTATEINFO <>
    csiRestored         COMPSTATEINFO <>
COMPONENT ENDS

IActiveDesktop STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    ApplyChanges            XPTR ?
    GetWallpaper            XPTR ?
    SetWallpaper            XPTR ?
    GetWallpaperOptions     XPTR ?
    SetWallpaperOptions     XPTR ?
    GetPattern              XPTR ?
    SetPattern              XPTR ?
    GetDesktopItemOptions   XPTR ?
    SetDesktopItemOptions   XPTR ?
    AddDesktopItem          XPTR ?
    AddDesktopItemWithUI    XPTR ?
    ModifyDesktopItem       XPTR ?
    RemoveDesktopItem       XPTR ?
    GetDesktopItemCount     XPTR ?
    GetDesktopItem          XPTR ?
    GetDesktopItemByID      XPTR ?
    GenerateDesktopItemHtml XPTR ?
    AddUrl                  XPTR ?
    GetDesktopItemBySource  XPTR ?
IActiveDesktop ENDS

IActiveDesktopP STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    SetSafeMode             XPTR ?
    EnsureUpdateHTML        XPTR ?
    SetScheme               XPTR ?
    GetScheme               XPTR ?
IActiveDesktopP ENDS

IADesktopP2 STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface          XPTR ?
            AddRef                  XPTR ?
            Release                 XPTR ?
        ENDS
        IUnknown                    Unknown <>
    ENDS
    ReReadWallpaper                 XPTR ?
    GetADObjectFlags                XPTR ?
    UpdateAllDesktopSubscriptions   XPTR ?
    MakeDynamicChanges              XPTR ?
IADesktopP2 ENDS

IQueryCancelAutoPlay STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    AllowAutoPlay           XPTR ?
IQueryCancelAutoPlay ENDS

IDynamicHWHandler STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    GetDynamicInfo          XPTR ?
IDynamicHWHandler ENDS

IActionProgress STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    Begin                   XPTR ?
    UpdateProgress          XPTR ?
    UpdateText              XPTR ?
    QueryCancel             XPTR ?
    ResetCancel             XPTR ?
    _End                    XPTR ?
IActionProgress ENDS

SHCOLUMNINIT STRUCT ALIGNMODE
    dwFlags     DD ?
    dwReserved  DD ?
    wszFolder   DW MAX_PATH DUP(?)
SHCOLUMNINIT ENDS

SHCOLUMNINFO STRUCT ALIGNMODE
    scid            SHCOLUMNID <>
    vt              DD ?
    fmt             DD ?
    cChars          DD ?
    csFlags         DD ?
    wszTitle        DW MAX_COLUMN_NAME_LEN DUP(?)
    wszDescription  DW MAX_COLUMN_DESC_LEN DUP(?)
SHCOLUMNINFO ENDS

SHCOLUMNDATA STRUCT ALIGNMODE
    dwFlags             DD ?
    dwFileAttributes    DD ?
    dwReserved          DD ?
    pwszExt             XPTR ?
    wszFile             DW MAX_PATH DUP(?)
SHCOLUMNDATA ENDS

IColumnProvider STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    Initialize              XPTR ?
    GetColumnInfo           XPTR ?
    GetItemData             XPTR ?
IColumnProvider ENDS

SHDRAGIMAGE STRUCT ALIGNMODE
    sizeDragImage   SIZEL  <>
    ptOffset        POINT  <>
    hbmpDragImage   HANDLE ?
    crColorKey      DD     ?
SHDRAGIMAGE ENDS

IDropTargetHelper STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    DragEnter               XPTR ?
    DragLeave               XPTR ?
    DragOver                XPTR ?
    Drop                    XPTR ?
    Show                    XPTR ?
IDropTargetHelper ENDS

IDragSourceHelper STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    InitializeFromBitmap    XPTR ?
    InitializeFromWindow    XPTR ?
IDragSourceHelper ENDS

IDragSourceHelper2 STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    InitializeFromBitmap    XPTR ?
    InitializeFromWindow    XPTR ?
    SetFlags                XPTR ?
IDragSourceHelper2 ENDS

NRESARRAY STRUCT ALIGNMODE
    cItems  DD ?
    nr      NETRESOURCE <>
NRESARRAY ENDS

CIDA STRUCT ALIGNMODE
    cidl    DD ?
    aoffset DD ?
CIDA ENDS

FILEDESCRIPTORA STRUCT ALIGNMODE
    dwFlags             DD ?
    clsid               GUID <>
    sizel               SIZEL <>
    pointl              POINTL <>
    dwFileAttributes    DD ?
    ftCreationTime      FILETIME <>
    ftLastAccessTime    FILETIME <>
    ftLastWriteTime     FILETIME <>
    nFileSizeHigh       DD ?
    nFileSizeLow        DD ?
    cFileName           DB MAX_PATH DUP(?)
FILEDESCRIPTORA ENDS

FILEDESCRIPTORW STRUCT ALIGNMODE
    dwFlags             DD ?
    clsid               GUID <>
    sizel               SIZEL <>
    pointl              POINTL <>
    dwFileAttributes    DD ?
    ftCreationTime      FILETIME <>
    ftLastAccessTime    FILETIME <>
    ftLastWriteTime     FILETIME <>
    nFileSizeHigh       DD ?
    nFileSizeLow        DD ?
    cFileName           DW MAX_PATH DUP(?)
FILEDESCRIPTORW ENDS

FILEGROUPDESCRIPTORA STRUCT ALIGNMODE
    cItems  DD ?
    fgd     FILEDESCRIPTORA <>
FILEGROUPDESCRIPTORA ENDS

FILEGROUPDESCRIPTORW STRUCT ALIGNMODE
    cItems  DD ?
    fgd     FILEDESCRIPTORW <>
FILEGROUPDESCRIPTORW ENDS

DROPFILES STRUCT ALIGNMODE
    pFiles  DD ?
    pt      POINT <>
    fNC     DD ?
    fWide   DD ?
DROPFILES ENDS

IF (NTDDI_VERSION GE NTDDI_VISTA)
    FILE_ATTRIBUTES_ARRAY STRUCT ALIGNMODE
        cItems                  DD ?
        dwSumFileAttributes     DD ?
        dwProductFileAttributes DD ?
        rgdwFileAttributes      DD ?
    FILE_ATTRIBUTES_ARRAY ENDS

    DROPDESCRIPTION STRUCT ALIGNMODE
        type        DD ?
        szMessage   DW MAX_PATH DUP(?)
        szInsert    DW MAX_PATH DUP(?)
    DROPDESCRIPTION ENDS
ENDIF

OPENASINFO STRUCT ALIGNMODE
    pcszFile    XPTR ?
    pcszClass   XPTR ?
    oaifInFlags DD   ?
OPENASINFO ENDS

AUTO_SCROLL_DATA STRUCT ALIGNMODE
    iNextSample     DD ?
    dwLastScroll    DD ?
    bFull           DD ?
    pts             POINT NUM_POINTS DUP(<>)
    dwTimes         DD NUM_POINTS DUP(?)
AUTO_SCROLL_DATA ENDS

CABINETSTATE STRUCT ALIGNMODE
    cLength                     DW ?
    nVersion                    DW ?
    fFullPathTitle              DD ?
    fSaveLocalView              DD ?
    fNotShell                   DD ?
    fSimpleDefault              DD ?
    fDontShowDescBar            DD ?
    fNewWindowMode              DD ?
    fShowCompColor              DD ?
    fDontPrettyNames            DD ?
    fAdminsCreateCommonGroups   DD ?
    fUnusedFlags                DD ?
    fMenuEnumFilter             DD ?
CABINETSTATE ENDS

IShellChangeNotify STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    OnChange                XPTR ?
IShellChangeNotify ENDS

IQueryInfo STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    GetInfoTip XPTR ?
    GetInfoFlags XPTR ?
IQueryInfo ENDS

SHChangeUpdateImageIDList STRUCT ALIGNMODE
    cb          DW ?
    iIconIndex  DD ?
    iCurIndex   DD ?
    uFlags      DD ?
    dwProcessID DD ?
    szName      DW MAX_PATH DUP(?)
    cbZero      DW ?
SHChangeUpdateImageIDList ENDS

SHChangeProductKeyAsIDList STRUCT ALIGNMODE
    cb              DW ?
    wszProductKey   DW 39 DUP(?)
    cbZero          DW ?
SHChangeProductKeyAsIDList ENDS

SHDESCRIPTIONID STRUCT ALIGNMODE
    dwDescriptionId DD ?
    clsid           GUID <>
SHDESCRIPTIONID ENDS

IF (NTDDI_VERSION LT NTDDI_VISTA)
    IDefViewFrame STRUCT ALIGNMODE
        UNION
            STRUCT
                QueryInterface  XPTR ?
                AddRef          XPTR ?
                Release         XPTR ?
            ENDS
            IUnknown            Unknown <>
        ENDS
        GetWindowLV             XPTR ?
        ReleaseWindowLV         XPTR ?
        GetShellFolder          XPTR ?
    IDefViewFrame ENDS
ENDIF

IDocViewSite STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    OnSetTitle              XPTR ?
IDocViewSite ENDS

PROPPRG STRUCT ALIGNMODE
    flPrg           DW ?
    flPrgInit       DW ?
    achTitle        DB PIFNAMESIZE DUP(?)
    achCmdLine      DB (PIFSTARTLOCSIZE + PIFPARAMSSIZE + 1) DUP(?)
    achWorkDir      DB PIFDEFPATHSIZE DUP(?)
    wHotKey         DW ?
    achIconFile     DB PIFDEFFILESIZE DUP(?)
    wIconIndex      DW ?
    dwEnhModeFlags  DD ?
    dwRealModeFlags DD ?
    achOtherFile    DB PIFDEFFILESIZE DUP(?)
    achPIFFile      DB PIFMAXFILEPATH DUP(?)
PROPPRG ENDS

IInitializeObject STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    Initialize XPTR ?
IInitializeObject ENDS

IBanneredBar STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    SetIconSize             XPTR ?
    GetIconSize             XPTR ?
    SetBitmap               XPTR ?
    GetBitmap               XPTR ?
IBanneredBar ENDS

IShellFolderViewCB STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    MessageSFVCB            XPTR ?
IShellFolderViewCB ENDS

IProfferService STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    ProfferService          XPTR ?
    RevokeService           XPTR ?
IProfferService ENDS

IShellItem STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    BindToHandler           XPTR ?
    GetParent               XPTR ?
    GetDisplayName          XPTR ?
    GetAttributes           XPTR ?
    Compare                 XPTR ?
IShellItem ENDS

IShellItem2 STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface              XPTR ?
            AddRef                      XPTR ?
            Release                     XPTR ?
        ENDS
        IUnknown                        Unknown <>
    ENDS
    BindToHandler                       XPTR ?
    GetParent                           XPTR ?
    GetDisplayName                      XPTR ?
    GetAttributes                       XPTR ?
    Compare                             XPTR ?
    GetPropertyStore                    XPTR ?
    GetPropertyStoreWithCreateObject    XPTR ?
    GetPropertyStoreForKeys             XPTR ?
    GetPropertyDescriptionList          XPTR ?
    Update                              XPTR ?
    GetProperty                         XPTR ?
    GetCLSID                            XPTR ?
    GetFileTime                         XPTR ?
    GetInt32                            XPTR ?
    GetString                           XPTR ?
    GetUInt32                           XPTR ?
    GetUInt64                           XPTR ?
    GetBool                             XPTR ?
IShellItem2 ENDS

IShellItemImageFactory STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    GetImage                XPTR ?
IShellItemImageFactory ENDS

IUserAccountChangeCallback STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    OnPictureChange         XPTR ?
IUserAccountChangeCallback ENDS

IEnumShellItems STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    Next                    XPTR ?
    Skip                    XPTR ?
    Reset                   XPTR ?
    Clone                   XPTR ?
IEnumShellItems ENDS

ITransferAdviseSink STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    UpdateProgress          XPTR ?
    UpdateTransferState     XPTR ?
    ConfirmOverwrite        XPTR ?
    ConfirmEncryptionLoss   XPTR ?
    FileFailure             XPTR ?
    SubStreamFailure        XPTR ?
    PropertyFailure         XPTR ?
ITransferAdviseSink ENDS

ITransferSource STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    Advise                      XPTR ?
    Unadvise                    XPTR ?
    SetProperties               XPTR ?
    OpenItem                    XPTR ?
    MoveItem                    XPTR ?
    RecycleItem                 XPTR ?
    RemoveItem                  XPTR ?
    RenameItem                  XPTR ?
    LinkItem                    XPTR ?
    ApplyPropertiesToItem       XPTR ?
    GetDefaultDestinationName   XPTR ?
    EnterFolder                 XPTR ?
    LeaveFolder                 XPTR ?
ITransferSource ENDS

SHELL_ITEM_RESOURCE STRUCT ALIGNMODE
    guidType    GUID <>
    szName      WCHAR 260 DUP(?)
SHELL_ITEM_RESOURCE ENDS

IEnumResources STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    Next                    XPTR ?
    Skip                    XPTR ?
    Reset                   XPTR ?
    Clone                   XPTR ?
IEnumResources ENDS

IShellItemResources STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    GetAttributes           XPTR ?
    GetSize                 XPTR ?
    GetTimes                XPTR ?
    SetTimes                XPTR ?
    GetResourceDescription  XPTR ?
    EnumResources           XPTR ?
    SupportsResource        XPTR ?
    OpenResource            XPTR ?
    CreateResource          XPTR ?
    MarkForDelete           XPTR ?
IShellItemResources ENDS

IFNDEF OVERLAPPED
    OVERLAPPED STRUCT ALIGNMODE
        Internal        XPTR ?
        InternalHigh    XPTR ?
        UNION
            STRUCT
                        _Offset DD ?
                        OffsetHigh DD ?
            ENDS
            Pointer     XPTR ?
        ENDS
        hEvent          HANDLE ?
    OVERLAPPED ENDS
ENDIF

IStreamAsync STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    Read                    XPTR ?
    Write                   XPTR ?
    Seek                    XPTR ?
    SetSize                 XPTR ?
    CopyTo                  XPTR ?
    ommit                   XPTR ?
    Revert                  XPTR ?
    LockRegion              XPTR ?
    UnlockRegion            XPTR ?
    Stat                    XPTR ?
    Clone                   XPTR ?
    ReadAsync               XPTR ?
    WriteAsync              XPTR ?
    OverlappedResult        XPTR ?
    CancelIo                XPTR ?
IStreamAsync ENDS

IStreamUnbufferedInfo STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    GetSectorSize           XPTR ?
IStreamUnbufferedInfo ENDS

IFileOperationProgressSink STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    StartOperations         XPTR ?
    FinishOperations        XPTR ?
    PreRenameItem           XPTR ?
    PostRenameItem          XPTR ?
    PreMoveItem             XPTR ?
    PostMoveItem            XPTR ?
    PreCopyItem             XPTR ?
    PostCopyItem            XPTR ?
    PreDeleteItem           XPTR ?
    PostDeleteItem          XPTR ?
    PreNewItem              XPTR ?
    PostNewItem             XPTR ?
    UpdateProgress          XPTR ?
    ResetTimer              XPTR ?
    PauseTimer              XPTR ?
    ResumeTimer             XPTR ?
IFileOperationProgressSink ENDS

ITransferDestination STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    Advise                  XPTR ?
    Unadvise                XPTR ?
    CreateItem              XPTR ?
ITransferDestination ENDS

IShellItemArray STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    BindToHandler               XPTR ?
    GetPropertyStore            XPTR ?
    GetPropertyDescriptionList  XPTR ?
    GetAttributes               XPTR ?
    GetCount                    XPTR ?
    GetItemAt                   XPTR ?
    EnumItems                   XPTR ?
IShellItemArray ENDS

IInitializeWithItem STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    Initialize              XPTR ?
IInitializeWithItem ENDS

IObjectWithSelection STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    SetSelection            XPTR ?
    GetSelection            XPTR ?
IObjectWithSelection ENDS

IObjectWithBackReferences STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    RemoveBackReferences    XPTR ?
IObjectWithBackReferences ENDS

IPropertyUI STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    ParsePropertyName       XPTR ?
    GetCannonicalName       XPTR ?
    GetDisplayName          XPTR ?
    GetPropertyDescription  XPTR ?
    GetDefaultWidth         XPTR ?
    GetFlags                XPTR ?
    FormatForDisplay        XPTR ?
    GetHelpInfo             XPTR ?
IPropertyUI ENDS

ICategoryProvider STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    CanCategorizeOnSCID     XPTR ?
    GetDefaultCategory      XPTR ?
    GetCategoryForSCID      XPTR ?
    EnumCategories          XPTR ?
    GetCategoryName         XPTR ?
    CreateCategory          XPTR ?
ICategoryProvider ENDS

CATEGORY_INFO STRUCT ALIGNMODE
    cif     DD ?
    wszName WCHAR 260 DUP(?)
CATEGORY_INFO ENDS

ICategorizer STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    GetDescription          XPTR ?
    GetCategory             XPTR ?
    GetCategoryInfo         XPTR ?
    CompareCategory         XPTR ?
ICategorizer ENDS

QCMINFO_IDMAP_PLACEMENT STRUCT ALIGNMODE
    id      DD ?
    fFlags  DD ?
QCMINFO_IDMAP_PLACEMENT ENDS

QCMINFO_IDMAP STRUCT ALIGNMODE
    nMaxIds DD ?
    pIdList QCMINFO_IDMAP_PLACEMENT <>
QCMINFO_IDMAP ENDS

QCMINFO STRUCT ALIGNMODE
    hmenu       HANDLE ?
    indexMenu   DD     ?
    idCmdFirst  DD     ?
    idCmdLast   DD     ?
    pIdMap      XPTR   ?
QCMINFO ENDS

TBINFO STRUCT ALIGNMODE
    cbuttons    DD ?
    uFlags      DD ?
TBINFO ENDS

DETAILSINFO STRUCT ALIGNMODE
    pidl    XPTR ?
    fmt     DD ?
    cxChar  DD ?
    _str    STRRET <>
    iImage  DD ?
DETAILSINFO ENDS

SFVM_PROPPAGE_DATA STRUCT ALIGNMODE
    dwReserved  DD ?
    pfn         XPTR ?
    lParam      LPARAM ?
SFVM_PROPPAGE_DATA ENDS

SFVM_HELPTOPIC_DATA STRUCT ALIGNMODE
    wszHelpFile     DW MAX_PATH DUP(?)
    wszHelpTopic    DW MAX_PATH DUP(?)
SFVM_HELPTOPIC_DATA ENDS

ITEMSPACING STRUCT ALIGNMODE
    cxSmall DD ?
    cySmall DD ?
    cxLarge DD ?
    cyLarge DD ?
ITEMSPACING ENDS

IShellFolderView STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    Rearrange               XPTR ?
    GetArrangeParam         XPTR ?
    ArrangeGrid             XPTR ?
    AutoArrange             XPTR ?
    GetAutoArrange          XPTR ?
    AddObject               XPTR ?
    GetObject               XPTR ?
    RemoveObject            XPTR ?
    GetObjectCount          XPTR ?
    SetObjectCount          XPTR ?
    UpdateObject            XPTR ?
    RefreshObject           XPTR ?
    SetRedraw               XPTR ?
    GetSelectedCount        XPTR ?
    GetSelectedObjects      XPTR ?
    IsDropOnSource          XPTR ?
    GetDragPoint            XPTR ?
    GetDropPoint            XPTR ?
    MoveIcons               XPTR ?
    SetItemPos              XPTR ?
    IsBkDropTarget          XPTR ?
    SetClipboard            XPTR ?
    SetPoints               XPTR ?
    GetItemSpacing          XPTR ?
    SetCallback             XPTR ?
    Select                  XPTR ?
    QuerySupport            XPTR ?
    SetAutomationObject     XPTR ?
IShellFolderView ENDS

SFV_CREATE STRUCT ALIGNMODE
    cbSize      DD   ?
    pshf        XPTR ?
    psvOuter    XPTR ?
    psfvcb      XPTR ?
SFV_CREATE ENDS

DEFCONTEXTMENU STRUCT ALIGNMODE
    hwnd                HANDLE ?
    pcmcb               XPTR   ?
    pidlFolder          XPTR   ?
    psf                 XPTR   ?
    cidl                DD     ?
    apidl               XPTR   ?
    punkAssociationInfo XPTR   ?
    cKeys               DD     ?
    aKeys               XPTR   ?
DEFCONTEXTMENU ENDS

DFMICS STRUCT ALIGNMODE
    cbSize       DD ?
    fMask        DD ?
    lParam       LPARAM ?
    idCmdFirst   DD ?
    idDefMax     DD ?
    pici         XPTR ?
    IF (NTDDI_VERSION GE NTDDI_VISTA)
        punkSite XPTR ?
    ENDIF
DFMICS ENDS

CSFV STRUCT ALIGNMODE
    cbSize      DD ?
    pshf        XPTR ?
    psvOuter    XPTR ?
    pidl        XPTR ?
    lEvents     DD ?
    pfnCallback XPTR ?
    fvm         DD ?
CSFV ENDS

SFV_SETITEMPOS STRUCT ALIGNMODE
    pidl    XPTR ?
    pt      POINT <>
SFV_SETITEMPOS ENDS

SHELLSTATEA STRUCT ALIGNMODE
    fShowAllObjects         DD ?
    fShowExtensions         DD ?
    fNoConfirmRecycle       DD ?
    fShowSysFiles           DD ?
    fShowCompColor          DD ?
    fDoubleClickInWebView   DD ?
    fDesktopHTML            DD ?
    fWin95Classic           DD ?
    fDontPrettyPath         DD ?
    fShowAttribCol          DD ?
    fMapNetDrvBtn           DD ?
    fShowInfoTip            DD ?
    fHideIcons              DD ?
    fWebView                DD ?
    fFilter                 DD ?
    fShowSuperHidden        DD ?
    fNoNetCrawling          DD ?
    dwWin95Unused           DD ?
    uWin95Unused            DD ?
    lParamSort              DD ?
    iSortDirection          DD ?
    version                 DD ?
    uNotUsed                DD ? ;You can rename it and use it
    fSepProcess             DD ?
    fStartPanelOn           DD ?
    fShowStartPage          DD ?
    fAutoCheckSelect        DD ?
    fIconsOnly              DD ?
    fShowTypeOverlay        DD ?
    fSpareFlags             DD ?
SHELLSTATEA ENDS

SHELLSTATEW STRUCT ALIGNMODE
    fShowAllObjects         DD ?
    fShowExtensions         DD ?
    fNoConfirmRecycle       DD ?
    fShowSysFiles           DD ?
    fShowCompColor          DD ?
    fDoubleClickInWebView   DD ?
    fDesktopHTML            DD ?
    fWin95Classic           DD ?
    fDontPrettyPath         DD ?
    fShowAttribCol          DD ?
    fMapNetDrvBtn           DD ?
    fShowInfoTip            DD ?
    fHideIcons              DD ?
    fWebView                DD ?
    fFilter                 DD ?
    fShowSuperHidden        DD ?
    fNoNetCrawling          DD ?
    dwWin95Unused           DD ?
    uWin95Unused            DD ?
    lParamSort              DD ?
    iSortDirection          DD ?
    version                 DD ?
    uNotUsed                DD ? ;You can rename it and use it
    fSepProcess             DD ?
    fStartPanelOn           DD ?
    fShowStartPage          DD ?
    fAutoCheckSelect        DD ?
    fIconsOnly              DD ?
    fShowTypeOverlay        DD ?
    fSpareFlags             DD ?
SHELLSTATEW ENDS

SHELLFLAGSTATE STRUCT ALIGNMODE
    fShowAllObjects         DD ?
    fShowExtensions         DD ?
    fNoConfirmRecycle       DD ?
    fShowSysFiles           DD ?
    fShowCompColor          DD ?
    fDoubleClickInWebView   DD ?
    fDesktopHTML            DD ?
    fWin95Classic           DD ?
    fDontPrettyPath         DD ?
    fShowAttribCol          DD ?
    fMapNetDrvBtn           DD ?
    fShowInfoTip            DD ?
    fHideIcons              DD ?
    IF (NTDDI_VERSION GE NTDDI_VISTA)
        fAutoCheckSelect    DD ?
        fIconsOnly          DD ?
        fRestFlags          DD ?
    ELSE
        fRestFlags          DD ?
    ENDIF
SHELLFLAGSTATE ENDS

INamedPropertyBag STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface  XPTR ?
            AddRef          XPTR ?
            Release         XPTR ?
        ENDS
        IUnknown            Unknown <>
    ENDS
    ReadPropertyNPB         XPTR ?
    WritePropertyNPB        XPTR ?
    RemovePropertyNPB       XPTR ?
INamedPropertyBag ENDS

AASHELLMENUFILENAME STRUCT ALIGNMODE
    cbTotal     DW ?
    rgbReserved DB 12 DUP(?)
    szFileName  DW ?
AASHELLMENUFILENAME ENDS

AASHELLMENUITEM STRUCT ALIGNMODE
    lpReserved1 XPTR ?
    iReserved   DD ?
    uiReserved  DD ?
    lpName      XPTR ?
    psz         XPTR ?
AASHELLMENUITEM ENDS

IFDEF APP_UNICODE
    SHELLSTATE EQU <SHELLSTATEW>
    GCS_VERB EQU <GCS_VERBW>
    GCS_HELPTEXT EQU <GCS_HELPTEXTW>
    GCS_VALIDATE EQU <GCS_VALIDATEW>
    CMDSTR_NEWFOLDER EQU <CMDSTR_NEWFOLDERW>
    CMDSTR_VIEWLIST EQU <CMDSTR_VIEWLISTW>
    CMDSTR_VIEWDETAILS EQU <CMDSTR_VIEWDETAILSW>
    IExtractIcon EQU <IExtractIconW>
    SHGetIconOverlayIndex EQU <SHGetIconOverlayIndexW>
    IShellLink EQU <IShellLinkW>
    IShellExecuteHook EQU <IShellExecuteHookW>
    INewShortcutHook EQU <INewShortcutHookW>
    ICopyHook EQU <ICopyHookW>
    IFileViewer EQU <IFileViewerW>
    SHGetPathFromIDList EQU <SHGetPathFromIDListW>
    SHCreateDirectoryEx EQU <SHCreateDirectoryExW>
    SHGetSpecialFolderPath EQU <SHGetSpecialFolderPathW>
    SHGetFolderPath EQU <SHGetFolderPathW>
    BROWSEINFO EQU <BROWSEINFOW>
    SHBrowseForFolder EQU <SHBrowseForFolderW>
    BFFM_SETSTATUSTEXT EQU <BFFM_SETSTATUSTEXTW>
    BFFM_SETSELECTION EQU <BFFM_SETSELECTIONW>
    BFFM_VALIDATEFAILED EQU <BFFM_VALIDATEFAILEDW>
    FILEDESCRIPTOR EQU <FILEDESCRIPTORW>
    FILEGROUPDESCRIPTOR EQU <FILEGROUPDESCRIPTORW>
    SHCNF_PATH EQU <SHCNF_PATHW>
    SHCNF_PRINTER EQU <SHCNF_PRINTERW>
    SHARD_PATH EQU <SHARD_PATHW>
    SHUpdateImage EQU <SHUpdateImageW>
    SHGetDataFromIDList EQU <SHGetDataFromIDListW>
    SHPathPrepareForWrite EQU <SHPathPrepareForWriteW>
    SHGetFolderPathAndSubDir EQU <SHGetFolderPathAndSubDirW>
    SHSetFolderPath EQU <SHSetFolderPathW>
    SHCreateFileExtractIcon EQU <SHCreateFileExtractIconW>
ELSE
    SHELLSTATE EQU <SHELLSTATEA>
    GCS_VERB EQU <GCS_VERBA>
    GCS_HELPTEXT EQU <GCS_HELPTEXTA>
    GCS_VALIDATE EQU <GCS_VALIDATEA>
    CMDSTR_NEWFOLDER EQU <CMDSTR_NEWFOLDERA>
    CMDSTR_VIEWLIST EQU <CMDSTR_VIEWLISTA>
    CMDSTR_VIEWDETAILS EQU <CMDSTR_VIEWDETAILSA>
    IExtractIcon EQU <IExtractIconA>
    SHGetIconOverlayIndex EQU <SHGetIconOverlayIndexA>
    IShellLink EQU <IShellLinkA>
    IShellExecuteHook EQU <IShellExecuteHookA>
    INewShortcutHook EQU <INewShortcutHookA>
    ICopyHook EQU <ICopyHookA>
    IFileViewer EQU <IFileViewerA>
    SHGetPathFromIDList EQU <SHGetPathFromIDListA>
    SHCreateDirectoryEx EQU <SHCreateDirectoryExA>
    SHGetSpecialFolderPath EQU <SHGetSpecialFolderPathA>
    SHGetFolderPath EQU <SHGetFolderPathA>
    BROWSEINFO EQU <BROWSEINFOA>
    SHBrowseForFolder EQU <SHBrowseForFolderA>
    BFFM_SETSTATUSTEXT EQU <BFFM_SETSTATUSTEXTA>
    BFFM_SETSELECTION EQU <BFFM_SETSELECTIONA>
    BFFM_VALIDATEFAILED EQU <BFFM_VALIDATEFAILEDA>
    FILEDESCRIPTOR EQU <FILEDESCRIPTORA>
    FILEGROUPDESCRIPTOR EQU <FILEGROUPDESCRIPTORA>
    SHCNF_PATH EQU <SHCNF_PATHA>
    SHCNF_PRINTER EQU <SHCNF_PRINTERA>
    SHARD_PATH EQU <SHARD_PATHA>
    SHUpdateImage EQU <SHUpdateImageA>
    SHGetDataFromIDList EQU <SHGetDataFromIDListA>
    SHPathPrepareForWrite EQU <SHPathPrepareForWriteA>
    SHGetFolderPathAndSubDir EQU <SHGetFolderPathAndSubDirA>
    SHSetFolderPath EQU <SHSetFolderPathA>
    SHCreateFileExtractIcon EQU <SHCreateFileExtractIconA>
ENDIF

ENDIF ;SHLOBJ_INC
