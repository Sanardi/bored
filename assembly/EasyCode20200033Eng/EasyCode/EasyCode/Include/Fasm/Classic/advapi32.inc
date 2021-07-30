; ====================================================;
;                                                     ;
;    advapi32.inc for EC v2 Fasm classic projects     ;
;                   (version 1.0.2)                   ;
;                                                     ;
;         Copyright © Ramon Sala - 2018-2020          ;
;                                                     ;
; ====================================================;

if ~defined ADVAPI32_INC
define ADVAPI32_INC 1

NO_INHERITANCE                                  equ     000H
SUB_OBJECTS_ONLY_INHERIT                        equ     001H
SUB_CONTAINERS_ONLY_INHERIT                     equ     002H
SUB_CONTAINERS_AND_OBJECTS_INHERIT              equ     003H
INHERIT_NO_PROPAGATE                            equ     004H
INHERIT_ONLY                                    equ     008H
INHERITED_ACCESS_ENTRY                          equ     010H

INHERITED_PARENT                                equ     010000000H
INHERITED_GRANDPARENT                           equ     020000000H

ACCCTRL_DEFAULT_PROVIDERA                       equ     'Windows NT Access Provider'
ACCCTRL_DEFAULT_PROVIDERW                       du      'Windows NT Access Provider'

SERVICES_ACTIVE_DATABASEW                       du      'ServicesActive'
SERVICES_FAILED_DATABASEW                       du      'ServicesFailed'
SERVICES_ACTIVE_DATABASEA                       equ     'ServicesActive'
SERVICES_FAILED_DATABASEA                       equ     'ServicesFailed'

SC_GROUP_IDENTIFIERW                            du      '+'
SC_GROUP_IDENTIFIERA                            equ     '+'

SERVICE_NO_CHANGE                               equ     0FFFFFFFFH

SERVICE_ACTIVE                                  equ     00000001H
SERVICE_INACTIVE                                equ     00000002H
SERVICE_STATE_ALL                               equ     (SERVICE_ACTIVE or SERVICE_INACTIVE)

SERVICE_CONTROL_STOP                            equ     00000001H
SERVICE_CONTROL_PAUSE                           equ     00000002H
SERVICE_CONTROL_CONTINUE                        equ     00000003H
SERVICE_CONTROL_INTERROGATE                     equ     00000004H
SERVICE_CONTROL_SHUTDOWN                        equ     00000005H
SERVICE_CONTROL_PARAMCHANGE                     equ     00000006H
SERVICE_CONTROL_NETBINDADD                      equ     00000007H
SERVICE_CONTROL_NETBINDREMOVE                   equ     00000008H
SERVICE_CONTROL_NETBINDENABLE                   equ     00000009H
SERVICE_CONTROL_NETBINDDISABLE                  equ     0000000AH
SERVICE_CONTROL_DEVICEEVENT                     equ     0000000BH
SERVICE_CONTROL_HARDWAREPROFILECHANGE           equ     0000000CH
SERVICE_CONTROL_POWEREVENT                      equ     0000000DH

SERVICE_STOPPED                                 equ     00000001H
SERVICE_START_PENDING                           equ     00000002H
SERVICE_STOP_PENDING                            equ     00000003H
SERVICE_RUNNING                                 equ     00000004H
SERVICE_CONTINUE_PENDING                        equ     00000005H
SERVICE_PAUSE_PENDING                           equ     00000006H
SERVICE_PAUSED                                  equ     00000007H

SERVICE_ACCEPT_STOP                             equ     00000001H
SERVICE_ACCEPT_PAUSE_CONTINUE                   equ     00000002H
SERVICE_ACCEPT_SHUTDOWN                         equ     00000004H
SERVICE_ACCEPT_PARAMCHANGE                      equ     00000008H
SERVICE_ACCEPT_NETBINDCHANGE                    equ     00000010H
SERVICE_ACCEPT_HARDWAREPROFILECHANGE            equ     00000020H
SERVICE_ACCEPT_POWEREVENT                       equ     00000040H

if ~defined DELETE
    DELETE                                      equ     00010000H
    READ_CONTROL                                equ     00020000H
    WRITE_DAC                                   equ     00040000H
    WRITE_OWNER                                 equ     00080000H
    SYNCHRONIZE                                 equ     00100000H
end if

STANDARD_RIGHTS_REQUIRED                        equ     000F0000H

STANDARD_RIGHTS_READ                            equ     READ_CONTROL
STANDARD_RIGHTS_WRITE                           equ     READ_CONTROL
STANDARD_RIGHTS_EXECUTE                         equ     READ_CONTROL

STANDARD_RIGHTS_ALL                             equ     (001F0000H)

SC_MANAGER_CONNECT                              equ     0001H
SC_MANAGER_CREATE_SERVICE                       equ     0002H
SC_MANAGER_ENUMERATE_SERVICE                    equ     0004H
SC_MANAGER_LOCK                                 equ     0008H
SC_MANAGER_QUERY_LOCK_STATUS                    equ     0010H
SC_MANAGER_MODIFY_BOOT_CONFIG                   equ     0020H
SC_MANAGER_ALL_ACCESS                           equ     (STANDARD_RIGHTS_REQUIRED or SC_MANAGER_CONNECT or SC_MANAGER_CREATE_SERVICE or SC_MANAGER_ENUMERATE_SERVICE or SC_MANAGER_LOCK or SC_MANAGER_QUERY_LOCK_STATUS or SC_MANAGER_MODIFY_BOOT_CONFIG)

SERVICE_QUERY_CONFIG                            equ     0001H
SERVICE_CHANGE_CONFIG                           equ     0002H
SERVICE_QUERY_STATUS                            equ     0004H
SERVICE_ENUMERATE_DEPENDENTS                    equ     0008H
SERVICE_START                                   equ     0010H
SERVICE_STOP                                    equ     0020H
SERVICE_PAUSE_CONTINUE                          equ     0040H
SERVICE_INTERROGATE                             equ     0080H
SERVICE_USER_DEFINED_CONTROL                    equ     0100H
SERVICE_ALL_ACCESS                              equ     (STANDARD_RIGHTS_REQUIRED or SERVICE_QUERY_CONFIG or SERVICE_CHANGE_CONFIG or SERVICE_QUERY_STATUS or SERVICE_ENUMERATE_DEPENDENTS or SERVICE_START or SERVICE_STOP or SERVICE_PAUSE_CONTINUE or SERVICE_INTERROGATE or SERVICE_USER_DEFINED_CONTROL)

SERVICE_RUNS_IN_SYSTEM_PROCESS                  equ     00000001H

SERVICE_CONFIG_DESCRIPTION                      equ     1
SERVICE_CONFIG_FAILURE_ACTIONS                  equ     2

SERVICE_KERNEL_DRIVER                           equ         00000001H
SERVICE_FILE_SYSTEM_DRIVER                      equ         00000002H
SERVICE_ADAPTER                                 equ         00000004H
SERVICE_RECOGNIZER_DRIVER                       equ         00000008H

SERVICE_DRIVER                                  equ     (SERVICE_KERNEL_DRIVER or SERVICE_FILE_SYSTEM_DRIVER or SERVICE_RECOGNIZER_DRIVER)

SERVICE_WIN32_OWN_PROCESS                       equ     00000010H
SERVICE_WIN32_SHARE_PROCESS                     equ     00000020H
SERVICE_WIN32                                   equ     (SERVICE_WIN32_OWN_PROCESS or SERVICE_WIN32_SHARE_PROCESS)

SERVICE_INTERACTIVE_PROCESS                     equ     00000100H

SERVICE_TYPE_ALL                                equ     (SERVICE_WIN32 or SERVICE_ADAPTER or SERVICE_DRIVER or SERVICE_INTERACTIVE_PROCESS)

SERVICE_BOOT_START                              equ     00000000H
SERVICE_SYSTEM_START                            equ     00000001H
SERVICE_AUTO_START                              equ     00000002H
SERVICE_DEMAND_START                            equ     00000003H
SERVICE_DISABLED                                equ     00000004H

SERVICE_ERROR_IGNORE                            equ     00000000H
SERVICE_ERROR_NORMAL                            equ     00000001H
SERVICE_ERROR_SEVERE                            equ     00000002H
SERVICE_ERROR_CRITICAL                          equ     00000003H

SC_ACTION_NONE                                  equ     0
SC_ACTION_RESTART                               equ     1
SC_ACTION_REBOOT                                equ     2
SC_ACTION_RUN_COMMAND                           equ     3

SC_STATUS_PROCESS_INFO                          equ     0
SC_ENUM_PROCESS_INFO                            equ     0

TRUSTEE_ACCESS_ALLOWED                          equ     000000001H
TRUSTEE_ACCESS_READ                             equ     000000002H
TRUSTEE_ACCESS_WRITE                            equ     000000004H
TRUSTEE_ACCESS_EXPLICIT                         equ     000000001H
TRUSTEE_ACCESS_READ_WRITE                       equ     (TRUSTEE_ACCESS_READ or TRUSTEE_ACCESS_WRITE)
TRUSTEE_ACCESS_ALL                              equ     0FFFFFFFFH

ACTRL_RESERVED                                  equ     000000000H
ACTRL_PERM_1                                    equ     000000001H
ACTRL_PERM_2                                    equ     000000002H
ACTRL_PERM_3                                    equ     000000004H
ACTRL_PERM_4                                    equ     000000008H
ACTRL_PERM_5                                    equ     000000010H
ACTRL_PERM_6                                    equ     000000020H
ACTRL_PERM_7                                    equ     000000040H
ACTRL_PERM_8                                    equ     000000080H
ACTRL_PERM_9                                    equ     000000100H
ACTRL_PERM_10                                   equ     000000200H
ACTRL_PERM_11                                   equ     000000400H
ACTRL_PERM_12                                   equ     000000800H
ACTRL_PERM_13                                   equ     000001000H
ACTRL_PERM_14                                   equ     000002000H
ACTRL_PERM_15                                   equ     000004000H
ACTRL_PERM_16                                   equ     000008000H
ACTRL_PERM_17                                   equ     000010000H
ACTRL_PERM_18                                   equ     000020000H
ACTRL_PERM_19                                   equ     000040000H
ACTRL_PERM_20                                   equ     000080000H

ACTRL_ACCESS_ALLOWED                            equ     000000001H
ACTRL_ACCESS_DENIED                             equ     000000002H
ACTRL_AUDIT_SUCCESS                             equ     000000004H
ACTRL_AUDIT_FAILURE                             equ     000000008H

ACTRL_ACCESS_PROTECTED                          equ     000000001H

ACTRL_SYSTEM_ACCESS                             equ     004000000H
ACTRL_DELETE                                    equ     008000000H
ACTRL_READ_CONTROL                              equ     010000000H
ACTRL_CHANGE_ACCESS                             equ     020000000H
ACTRL_CHANGE_OWNER                              equ     040000000H
ACTRL_SYNCHRONIZE                               equ     080000000H
ACTRL_STD_RIGHTS_ALL                            equ     0F8000000H
ACTRL_STD_RIGHT_REQUIRED                        equ     (ACTRL_STD_RIGHTS_ALL and (not ACTRL_SYNCHRONIZE))

if ~defined ACTRL_DS_OPEN
    ACTRL_DS_OPEN                               equ     ACTRL_RESERVED
    ACTRL_DS_CREATE_CHILD                       equ     ACTRL_PERM_1
    ACTRL_DS_DELETE_CHILD                       equ     ACTRL_PERM_2
    ACTRL_DS_LIST                               equ     ACTRL_PERM_3
    ACTRL_DS_SELF                               equ     ACTRL_PERM_4
    ACTRL_DS_READ_PROP                          equ     ACTRL_PERM_5
    ACTRL_DS_WRITE_PROP                         equ     ACTRL_PERM_6
    ACTRL_DS_DELETE_TREE                        equ     ACTRL_PERM_7
    ACTRL_DS_LIST_OBJECT                        equ     ACTRL_PERM_8
    ACTRL_DS_CONTROL_ACCESS                     equ     ACTRL_PERM_9
end if

ACTRL_FILE_READ                                 equ     ACTRL_PERM_1
ACTRL_FILE_WRITE                                equ     ACTRL_PERM_2
ACTRL_FILE_APPEND                               equ     ACTRL_PERM_3
ACTRL_FILE_READ_PROP                            equ     ACTRL_PERM_4
ACTRL_FILE_WRITE_PROP                           equ     ACTRL_PERM_5
ACTRL_FILE_EXECUTE                              equ     ACTRL_PERM_6
ACTRL_FILE_READ_ATTRIB                          equ     ACTRL_PERM_8
ACTRL_FILE_WRITE_ATTRIB                         equ     ACTRL_PERM_9
ACTRL_FILE_CREATE_PIPE                          equ     ACTRL_PERM_10
ACTRL_DIR_LIST                                  equ     ACTRL_PERM_1
ACTRL_DIR_CREATE_OBJECT                         equ     ACTRL_PERM_2
ACTRL_DIR_CREATE_CHILD                          equ     ACTRL_PERM_3
ACTRL_DIR_DELETE_CHILD                          equ     ACTRL_PERM_7
ACTRL_DIR_TRAVERSE                              equ     ACTRL_PERM_6
ACTRL_KERNEL_TERMINATE                          equ     ACTRL_PERM_1
ACTRL_KERNEL_THREAD                             equ     ACTRL_PERM_2
ACTRL_KERNEL_VM                                 equ     ACTRL_PERM_3
ACTRL_KERNEL_VM_READ                            equ     ACTRL_PERM_4
ACTRL_KERNEL_VM_WRITE                           equ     ACTRL_PERM_5
ACTRL_KERNEL_DUP_HANDLE                         equ     ACTRL_PERM_6
ACTRL_KERNEL_PROCESS                            equ     ACTRL_PERM_7
ACTRL_KERNEL_SET_INFO                           equ     ACTRL_PERM_8
ACTRL_KERNEL_GET_INFO                           equ     ACTRL_PERM_9
ACTRL_KERNEL_CONTROL                            equ     ACTRL_PERM_10
ACTRL_KERNEL_ALERT                              equ     ACTRL_PERM_11
ACTRL_KERNEL_GET_CONTEXT                        equ     ACTRL_PERM_12
ACTRL_KERNEL_SET_CONTEXT                        equ     ACTRL_PERM_13
ACTRL_KERNEL_TOKEN                              equ     ACTRL_PERM_14
ACTRL_KERNEL_IMPERSONATE                        equ     ACTRL_PERM_15
ACTRL_KERNEL_DIMPERSONATE                       equ     ACTRL_PERM_16
ACTRL_PRINT_SADMIN                              equ     ACTRL_PERM_1
ACTRL_PRINT_SLIST                               equ     ACTRL_PERM_2
ACTRL_PRINT_PADMIN                              equ     ACTRL_PERM_3
ACTRL_PRINT_PUSE                                equ     ACTRL_PERM_4
ACTRL_PRINT_JADMIN                              equ     ACTRL_PERM_5
ACTRL_SVC_GET_INFO                              equ     ACTRL_PERM_1
ACTRL_SVC_SET_INFO                              equ     ACTRL_PERM_2
ACTRL_SVC_STATUS                                equ     ACTRL_PERM_3
ACTRL_SVC_LIST                                  equ     ACTRL_PERM_4
ACTRL_SVC_START                                 equ     ACTRL_PERM_5
ACTRL_SVC_STOP                                  equ     ACTRL_PERM_6
ACTRL_SVC_PAUSE                                 equ     ACTRL_PERM_7
ACTRL_SVC_INTERROGATE                           equ     ACTRL_PERM_8
ACTRL_SVC_UCONTROL                              equ     ACTRL_PERM_9
ACTRL_REG_QUERY                                 equ     ACTRL_PERM_1
ACTRL_REG_SET                                   equ     ACTRL_PERM_2
ACTRL_REG_CREATE_CHILD                          equ     ACTRL_PERM_3
ACTRL_REG_LIST                                  equ     ACTRL_PERM_4
ACTRL_REG_NOTIFY                                equ     ACTRL_PERM_5
ACTRL_REG_LINK                                  equ     ACTRL_PERM_6
ACTRL_WIN_CLIPBRD                               equ     ACTRL_PERM_1
ACTRL_WIN_GLOBAL_ATOMS                          equ     ACTRL_PERM_2
ACTRL_WIN_CREATE                                equ     ACTRL_PERM_3
ACTRL_WIN_LIST_DESK                             equ     ACTRL_PERM_4
ACTRL_WIN_LIST                                  equ     ACTRL_PERM_5
ACTRL_WIN_READ_ATTRIBS                          equ     ACTRL_PERM_6
ACTRL_WIN_WRITE_ATTRIBS                         equ     ACTRL_PERM_7
ACTRL_WIN_SCREEN                                equ     ACTRL_PERM_8
ACTRL_WIN_EXIT                                  equ     ACTRL_PERM_9

ACTRL_ACCESS_NO_OPTIONS                         equ     000000000H
ACTRL_ACCESS_SUPPORTS_OBJECT_ENTRIES            equ     000000001H

TREE_SEC_INFO_SET                               equ     000000001H
TREE_SEC_INFO_RESET                             equ     000000002H
TREE_SEC_INFO_RESET_KEEP_EXPLICIT               equ     000000003H

ProgressInvokeNever                             equ     1
ProgressInvokeEveryObject                       equ     2
ProgressInvokeOnError                           equ     3
ProgressCancelOperation                         equ     4
ProgressRetryOperation                          equ     5
ProgressInvokePrePostError                      equ     6

SE_UNKNOWN_OBJECT_TYPE                          equ     0
SE_FILE_OBJECT                                  equ     1
SE_SERVICE                                      equ     2
SE_PRINTER                                      equ     3
SE_REGISTRY_KEY                                 equ     4
SE_LMSHARE                                      equ     5
SE_KERNEL_OBJECT                                equ     6
SE_WINDOW_OBJECT                                equ     7
SE_DS_OBJECT                                    equ     8
SE_DS_OBJECT_ALL                                equ     9
SE_PROVIDER_DEFINED_OBJECT                      equ     10
SE_WMIGUID_OBJECT                               equ     11
SE_REGISTRY_WOW64_32KEY                         equ     12

TRUSTEE_IS_UNKNOWN                              equ     0
TRUSTEE_IS_USER                                 equ     1
TRUSTEE_IS_GROUP                                equ     2
TRUSTEE_IS_DOMAIN                               equ     3
TRUSTEE_IS_ALIAS                                equ     4
TRUSTEE_IS_WELL_KNOWN_GROUP                     equ     5
TRUSTEE_IS_DELETED                              equ     6
TRUSTEE_IS_INVALID                              equ     7
TRUSTEE_IS_COMPUTER                             equ     8

TRUSTEE_IS_SID                                  equ     0
TRUSTEE_IS_NAME                                 equ     1
TRUSTEE_BAD_FORM                                equ     2
TRUSTEE_IS_OBJECTS_AND_SID                      equ     3
TRUSTEE_IS_OBJECTS_AND_NAME                     equ     4

NO_MULTIPLE_TRUSTEE                             equ     0
TRUSTEE_IS_IMPERSONATE                          equ     1

NOT_USED_ACCESS                                 equ     0
GRANT_ACCESS                                    equ     1
SET_ACCESS                                      equ     2
DENY_ACCESS                                     equ     3
REVOKE_ACCESS                                   equ     4
SET_AUDIT_SUCCESS                               equ     5
SET_AUDIT_FAILURE                               equ     6

HKEY_CLASSES_ROOT                               equ     80000000H
HKEY_CURRENT_USER                               equ     80000001H
HKEY_LOCAL_MACHINE                              equ     80000002H
HKEY_USERS                                      equ     80000003H
HKEY_PERFORMANCE_DATA                           equ     80000004H
HKEY_CURRENT_CONFIG                             equ     80000005H
HKEY_DYN_DATA                                   equ     80000006H

REG_OPTION_NON_VOLATILE                         equ     00000000H
REG_OPTION_VOLATILE                             equ     00000001H
REG_OPTION_CREATE_LINK                          equ     00000002H
REG_OPTION_BACKUP_RESTORE                       equ     00000004H
REG_OPTION_OPEN_LINK                            equ     00000008H
REG_CREATED_NEW_KEY                             equ     00000001H
REG_OPENED_EXISTING_KEY                         equ     00000002H

REG_NONE                                        equ     0
REG_SZ                                          equ     1
REG_EXPAND_SZ                                   equ     2
REG_BINARY                                      equ     3
REG_DWORD                                       equ     4
REG_DWORD_LITTLE_ENDIAN                         equ     4
REG_DWORD_BIG_ENDIAN                            equ     5
REG_LINK                                        equ     6
REG_MULTI_SZ                                    equ     7
REG_RESOURCE_LIST                               equ     8
REG_FULL_RESOURCE_DESCRIPTOR                    equ     9
REG_RESOURCE_REQUIREMENTS_LIST                  equ     10
REG_QWORD                                       equ     11
REG_QWORD_LITTLE_ENDIAN                         equ     11
        
REG_NOTIFY_CHANGE_NAME                          equ     00000001H
REG_NOTIFY_CHANGE_ATTRIBUTES                    equ     00000002H
REG_NOTIFY_CHANGE_LAST_SET                      equ     00000004H
REG_NOTIFY_CHANGE_SECURITY                      equ     00000008H

REG_NOTIFY_THREAD_AGNOSTIC                      equ     10000000H


;======================================== Structures ======================================;
struct SERVICE_DESCRIPTIONA
    lpDescription  xptr    ?
ends

struct SERVICE_DESCRIPTIONW
    lpDescription  xptr    ?
ends

struct SC_ACTION
    Type   dd  ?
    Delay  dd  ?
ends

struct SERVICE_FAILURE_ACTIONSA
    dwResetPeriod  dd   ?
    lpRebootMsg    xptr ?
    lpCommand      xptr ?
    cActions       dd   ?
    lpsaActions    xptr ?
ends

struct SERVICE_FAILURE_ACTIONSW
    dwResetPeriod  dd   ?
    lpRebootMsg    xptr ?
    lpCommand      xptr ?
    cActions       dd   ?
    lpsaActions    xptr ?
ends

struct SERVICE_STATUS
    dwServiceType             dd  ?
    dwCurrentState            dd  ?
    dwControlsAccepted        dd  ?
    dwWin32ExitCode           dd  ?
    dwServiceSpecificExitCode dd  ?
    dwCheckPoint              dd  ?
    dwWaitHint                dd  ?
ends

struct SERVICE_STATUS_PROCESS
    dwServiceType             dd  ?
    dwCurrentState            dd  ?
    dwControlsAccepted        dd  ?
    dwWin32ExitCode           dd  ?
    dwServiceSpecificExitCode dd  ?
    dwCheckPoint              dd  ?
    dwWaitHint                dd  ?
    dwProcessId               dd  ?
    dwServiceFlags            dd  ?
ends

struct ENUM_SERVICE_STATUSA
    lpServiceName  xptr  ?
    lpDisplayName  xptr  ?
    ServiceStatus  SERVICE_STATUS <>
ends

struct ENUM_SERVICE_STATUSW
    lpServiceName  xptr  ?
    lpDisplayName  xptr  ?
    ServiceStatus  SERVICE_STATUS <>
ends

struct ENUM_SERVICE_STATUS_PROCESSA
    lpServiceName        xptr  ?
    lpDisplayName        xptr  ?
    ServiceStatusProcess SERVICE_STATUS_PROCESS <>
ends

struct ENUM_SERVICE_STATUS_PROCESSW
    lpServiceName        xptr  ?
    lpDisplayName        xptr  ?
    ServiceStatusProcess SERVICE_STATUS_PROCESS <>
ends

struct QUERY_SERVICE_LOCK_STATUSA
    fIsLocked      dd   ?
    lpLockOwner    xptr ?
    dwLockDuration dd   ?
ends

struct QUERY_SERVICE_LOCK_STATUSW
    fIsLocked      dd   ?
    lpLockOwner    xptr ?
    dwLockDuration dd   ?
ends

struct QUERY_SERVICE_CONFIGA
    dwServiceType      dd   ?
    dwStartType        dd   ?
    dwErrorControl     dd   ?
    lpBinaryPathName   xptr ?
    lpLoadOrderGroup   xptr ?
    dwTagId            dd   ?
    lpDependencies     xptr ?
    lpServiceStartName xptr ?
    lpDisplayName      xptr ?
ends

struct QUERY_SERVICE_CONFIGW
    dwServiceType      dd   ?
    dwStartType        dd   ?
    dwErrorControl     dd   ?
    lpBinaryPathName   xptr ?
    lpLoadOrderGroup   xptr ?
    dwTagId            dd   ?
    lpDependencies     xptr ?
    lpServiceStartName xptr ?
    lpDisplayName      xptr ?
ends

struct SERVICE_TABLE_ENTRYA
    lpServiceName  xptr ?
    lpServiceProc  xptr ?
ends

struct SERVICE_TABLE_ENTRYW
    lpServiceName  xptr ?
    lpServiceProc  xptr ?
ends

struct INHERITED_FROMA
    GenerationGap   dd   ?
    AncestorName    xptr ?
ends

struct INHERITED_FROMW
    GenerationGap   dd   ?
    AncestorName    xptr ?
ends

struct OBJECTS_AND_SID
    ObjectsPresent          dd   ?
    ObjectTypeGuid          GUID <>
    InheritedObjectTypeGuid GUID <>
    pSid                    xptr ?
ends

struct OBJECTS_AND_NAME_A
    ObjectsPresent          dd   ?
    ObjectType              xptr ?
    ObjectTypeName          xptr ?
    InheritedObjectTypeName xptr ?
    ptstrName               xptr ?
ends

struct OBJECTS_AND_NAME_W
    ObjectsPresent          dd   ?
    ObjectType              xptr ?
    ObjectTypeName          xptr ?
    InheritedObjectTypeName xptr ?
    ptstrName               xptr ?
ends

struct TRUSTEE_A
    pMultipleTrustee         xptr ?
    MultipleTrusteeOperation xptr ?
    TrusteeForm              xptr ?
    TrusteeType              xptr ?
    ptstrName                xptr ?
ends

struct TRUSTEE_W
    pMultipleTrustee         xptr ?
    MultipleTrusteeOperation xptr ?
    TrusteeForm              xptr ?
    TrusteeType              xptr ?
    ptstrName                xptr ?
ends

struct EXPLICIT_ACCESS_A
    grfAccessPermissions dd        ?
    grfAccessMode        xptr      ?
    grfInheritance       dd        ?
    Trustee              TRUSTEE_A <>
ends

struct EXPLICIT_ACCESS_W
    grfAccessPermissions dd        ?
    grfAccessMode        xptr      ?
    grfInheritance       dd        ?
    Trustee              TRUSTEE_W <>
ends

struct EXPLICIT_ACCESSA
    grfAccessPermissions dd        ?
    grfAccessMode        xptr      ?
    grfInheritance       dd        ?
    Trustee              TRUSTEE_A <>
ends

struct EXPLICIT_ACCESSW
    grfAccessPermissions dd        ?
    grfAccessMode        xptr      ?
    grfInheritance       dd        ?
    Trustee              TRUSTEE_W <>
ends

struct ACTRL_ACCESS_ENTRYA
    Trustee            TRUSTEE_A <>
    fAccessFlags       dd        ?
    Access             dd        ?
    ProvSpecificAccess dd        ?
    Inheritance        dd        ?
    lpInheritProperty  xptr      ?
ends

struct ACTRL_ACCESS_ENTRYW
    Trustee            TRUSTEE_W <>
    fAccessFlags       dd        ?
    Access             dd        ?
    ProvSpecificAccess dd        ?
    Inheritance        dd        ?
    lpInheritProperty  xptr      ?
ends

struct ACTRL_ACCESS_ENTRY_LISTA
    cEntries    dd    ?
    pAccessList xptr  ?
ends

struct ACTRL_ACCESS_ENTRY_LISTW
    cEntries    dd    ?
    pAccessList xptr  ?
ends

struct ACTRL_PROPERTY_ENTRYA
    lpProperty       xptr ?
    pAccessEntryList xptr ?
    fListFlags       dd   ?
ends

struct ACTRL_PROPERTY_ENTRYW
    lpProperty       xptr ?
    pAccessEntryList xptr ?
    fListFlags       dd   ?
ends

struct ACTRL_ALISTA
    cEntries            dd   ?
    pPropertyAccessList xptr ?
ends

struct ACTRL_ALISTW
    cEntries            dd   ?
    pPropertyAccessList xptr ?
ends

struct TRUSTEE_ACCESSA
    lpProperty      xptr ?
    Access          dd   ?
    fAccessFlags    dd   ?
    fReturnedAccess dd   ?
ends

struct TRUSTEE_ACCESSW
    lpProperty      xptr ?
    Access          dd   ?
    fAccessFlags    dd   ?
    fReturnedAccess dd   ?
ends

struct ACTRL_ACCESS_INFOA
    fAccessPermission      dd   ?
    lpAccessPermissionName xptr ?
ends

struct ACTRL_ACCESS_INFOW
    fAccessPermission      dd   ?
    lpAccessPermissionName xptr ?
ends

struct ACTRL_CONTROL_INFOA
    lpControlId   xptr ?
    lpControlName xptr ?
ends

struct ACTRL_CONTROL_INFOW
    lpControlId   xptr ?
    lpControlName xptr ?
ends

struct ACTRL_AUDITA
    cEntries            dd   ?
    pPropertyAccessList xptr ?
ends

struct ACTRL_AUDITW
    cEntries            dd   ?
    pPropertyAccessList xptr ?
ends

struct FN_OBJECT_MGR_FUNCTIONS
    Placeholder dd  ?
ends

;======================================== Functions =======================================;
import advapi32,\
AbortSystemShutdownA,'AbortSystemShutdownA',\
AbortSystemShutdownW,'AbortSystemShutdownW',\
AccessCheck,'AccessCheck',\
AccessCheckAndAuditAlarmA,'AccessCheckAndAuditAlarmA',\
AccessCheckAndAuditAlarmW,'AccessCheckAndAuditAlarmW',\
AccessCheckByType,'AccessCheckByType',\
AccessCheckByTypeAndAuditAlarmA,'AccessCheckByTypeAndAuditAlarmA',\
AccessCheckByTypeAndAuditAlarmW,'AccessCheckByTypeAndAuditAlarmW',\
AccessCheckByTypeResultList,'AccessCheckByTypeResultList',\
AccessCheckByTypeResultListAndAuditAlarmA,'AccessCheckByTypeResultListAndAuditAlarmW',\
AccessCheckByTypeResultListAndAuditAlarmW,'AccessCheckByTypeResultListAndAuditAlarmW',\
AddAccessAllowedAce,'AddAccessAllowedAce',\
AddAccessAllowedAceEx,'AddAccessAllowedAceEx',\
AddAccessAllowedObjectAce,'AddAccessAllowedObjectAce',\
AddAccessDeniedAce,'AddAccessDeniedAce',\
AddAccessDeniedAceEx,'AddAccessDeniedAceEx',\
AddAccessDeniedObjectAce,'AddAccessDeniedObjectAce',\
AddAce,'AddAce',\
AddAuditAccessAce,'AddAuditAccessAce',\
AddAuditAccessAceEx,'AddAuditAccessAceEx',\
AddAuditAccessObjectAce,'AddAuditAccessObjectAce',\
AdjustTokenGroups,'AdjustTokenGroups',\
AdjustTokenPrivileges,'AdjustTokenPrivileges',\
AllocateAndInitializeSid,'AllocateAndInitializeSid',\
AllocateLocallyUniqueId,'AllocateLocallyUniqueId',\
AreAllAccessesGranted,'AreAllAccessesGranted',\
AreAnyAccessesGranted,'AreAnyAccessesGranted',\
BackupEventLogA,'BackupEventLogA',\
BackupEventLogW,'BackupEventLogW',\
BuildExplicitAccessWithNameA,'BuildExplicitAccessWithNameA',\
BuildExplicitAccessWithNameW,'BuildExplicitAccessWithNameW',\
BuildImpersonateExplicitAccessWithNameA,'BuildImpersonateExplicitAccessWithNameA',\
BuildImpersonateExplicitAccessWithNameW,'BuildImpersonateExplicitAccessWithNameW',\
BuildImpersonateTrusteeA,'BuildImpersonateTrusteeA',\
BuildImpersonateTrusteeW,'BuildImpersonateTrusteeW',\
BuildSecurityDescriptorA,'BuildSecurityDescriptorA',\
BuildSecurityDescriptorW,'BuildSecurityDescriptorW',\
BuildTrusteeWithNameA,'BuildTrusteeWithNameA',\
BuildTrusteeWithNameW,'BuildTrusteeWithNameW',\
BuildTrusteeWithSidA,'BuildTrusteeWithSidA',\
BuildTrusteeWithSidW,'BuildTrusteeWithSidW',\
CancelOverlappedAccess,'CancelOverlappedAccess',\
ChangeServiceConfig2A,'ChangeServiceConfig2A',\
ChangeServiceConfig2W,'ChangeServiceConfig2W',\
ChangeServiceConfigA,'ChangeServiceConfigA',\
ChangeServiceConfigW,'ChangeServiceConfigW',\
ClearEventLogA,'ClearEventLogA',\
ClearEventLogW,'ClearEventLogW',\
CloseEventLog,'CloseEventLog',\
CloseRaw,'CloseRaw',\
CloseServiceHandle,'CloseServiceHandle',\
ControlService,'ControlService',\
ConvertAccessToSecurityDescriptorA,'ConvertAccessToSecurityDescriptorA',\
ConvertAccessToSecurityDescriptorW,'ConvertAccessToSecurityDescriptorW',\
ConvertSecurityDescriptorToAccessA,'ConvertSecurityDescriptorToAccessA',\
ConvertSecurityDescriptorToAccessW,'ConvertSecurityDescriptorToAccessW',\
ConvertSecurityDescriptorToAccessNamedA,'ConvertSecurityDescriptorToAccessNamedA',\
ConvertSecurityDescriptorToAccessNamedW,'ConvertSecurityDescriptorToAccessNamedW',\
ConvertToAutoInheritPrivateObjectSecurity,'ConvertToAutoInheritPrivateObjectSecurity',\
CopySid,'CopySid',\
CreatePrivateObjectSecurity,'CreatePrivateObjectSecurity',\
CreatePrivateObjectSecurityEx,'CreatePrivateObjectSecurityEx',\
CreateProcessAsUserA,'CreateProcessAsUserA',\
CreateProcessAsUserW,'CreateProcessAsUserW',\
CreateRestrictedToken,'CreateRestrictedToken',\
CreateServiceA,'CreateServiceA',\
CreateServiceW,'CreateServiceW',\
CryptAcquireContextA,'CryptAcquireContextA',\
CryptAcquireContextW,'CryptAcquireContextW',\
CryptContextAddRef,'CryptContextAddRef',\
CryptCreateHash,'CryptCreateHash',\
CryptDecrypt,'CryptDecrypt',\
CryptDeriveKey,'CryptDeriveKey',\
CryptDestroyHash,'CryptDestroyHash',\
CryptDestroyKey,'CryptDestroyKey',\
CryptDuplicateHash,'CryptDuplicateHash',\
CryptDuplicateKey,'CryptDuplicateKey',\
CryptEncrypt,'CryptEncrypt',\
CryptEnumProviderTypesA,'CryptEnumProviderTypesA',\
CryptEnumProviderTypesW,'CryptEnumProviderTypesW',\
CryptEnumProvidersA,'CryptEnumProvidersA',\
CryptEnumProvidersW,'CryptEnumProvidersW',\
CryptExportKey,'CryptExportKey',\
CryptGenKey,'CryptGenKey',\
CryptGenRandom,'CryptGenRandom',\
CryptGetDefaultProviderA,'CryptGetDefaultProviderA',\
CryptGetDefaultProviderW,'CryptGetDefaultProviderW',\
CryptGetHashParam,'CryptGetHashParam',\
CryptGetKeyParam,'CryptGetKeyParam',\
CryptGetProvParam,'CryptGetProvParam',\
CryptGetUserKey,'CryptGetUserKey',\
CryptHashData,'CryptHashData',\
CryptHashSessionKey,'CryptHashSessionKey',\
CryptImportKey,'CryptImportKey',\
CryptReleaseContext,'CryptReleaseContext',\
CryptSetHashParam,'CryptSetHashParam',\
CryptSetKeyParam,'CryptSetKeyParam',\
CryptSetProvParam,'CryptSetProvParam',\
CryptSetProviderA,'CryptSetProviderA',\
CryptSetProviderW,'CryptSetProviderW',\
CryptSetProviderExA,'CryptSetProviderExA',\
CryptSetProviderExW,'CryptSetProviderExW',\
CryptSignHashA,'CryptSignHashA',\
CryptSignHashW,'CryptSignHashW',\
CryptVerifySignatureA,'CryptVerifySignatureA',\
CryptVerifySignatureW,'CryptVerifySignatureW',\
DecryptFileA,'DecryptFileA',\
DecryptFileW,'DecryptFileW',\
DeleteAce,'DeleteAce',\
DeleteService,'DeleteService',\
DeregisterEventSource,'DeregisterEventSource',\
DestroyPrivateObjectSecurity,'DestroyPrivateObjectSecurity',\
DuplicateToken,'DuplicateToken',\
DuplicateTokenEx,'DuplicateTokenEx',\
ElfBackupEventLogFileA,'ElfBackupEventLogFileA',\
ElfBackupEventLogFileW,'ElfBackupEventLogFileW',\
ElfChangeNotify,'ElfChangeNotify',\
ElfClearEventLogFileA,'ElfClearEventLogFileA',\
ElfClearEventLogFileW,'ElfClearEventLogFileW',\
ElfCloseEventLog,'ElfCloseEventLog',\
ElfDeregisterEventSource,'ElfDeregisterEventSource',\
ElfNumberOfRecords,'ElfNumberOfRecords',\
ElfOldestRecord,'ElfOldestRecord',\
ElfOpenBackupEventLogA,'ElfOpenBackupEventLogA',\
ElfOpenBackupEventLogW,'ElfOpenBackupEventLogW',\
ElfOpenEventLogA,'ElfOpenEventLogA',\
ElfOpenEventLogW,'ElfOpenEventLogW',\
ElfReadEventLogA,'ElfReadEventLogA',\
ElfReadEventLogW,'ElfReadEventLogW',\
ElfRegisterEventSourceA,'ElfRegisterEventSourceA',\
ElfRegisterEventSourceW,'ElfRegisterEventSourceW',\
ElfReportEventA,'ElfReportEventA',\
ElfReportEventW,'ElfReportEventW',\
EncryptFileA,'EncryptFileA',\
EncryptFileW,'EncryptFileW',\
EnumDependentServicesA,'EnumDependentServicesA',\
EnumDependentServicesW,'EnumDependentServicesW',\
EnumServicesStatusA,'EnumServicesStatusA',\
EnumServicesStatusW,'EnumServicesStatusW',\
EqualPrefixSid,'EqualPrefixSid',\
EqualSid,'EqualSid',\
FindFirstFreeAce,'FindFirstFreeAce',\
FreeSid,'FreeSid',\
GetAccessPermissionsForObjectA,'GetAccessPermissionsForObjectA',\
GetAccessPermissionsForObjectW,'GetAccessPermissionsForObjectW',\
GetAce,'GetAce',\
GetAclInformation,'GetAclInformation',\
GetAuditedPermissionsFromAclA,'GetAuditedPermissionsFromAclA',\
GetAuditedPermissionsFromAclW,'GetAuditedPermissionsFromAclW',\
GetCurrentHwProfileA,'GetCurrentHwProfileA',\
GetCurrentHwProfileW,'GetCurrentHwProfileW',\
GetEffectiveRightsFromAclA,'GetEffectiveRightsFromAclA',\
GetEffectiveRightsFromAclW,'GetEffectiveRightsFromAclW',\
GetExplicitEntriesFromAclA,'GetExplicitEntriesFromAclA',\
GetExplicitEntriesFromAclW,'GetExplicitEntriesFromAclW',\
GetFileSecurityA,'GetFileSecurityA',\
GetFileSecurityW,'GetFileSecurityW',\
GetKernelObjectSecurity,'GetKernelObjectSecurity',\
GetLengthSid,'GetLengthSid',\
GetMultipleTrusteeA,'GetMultipleTrusteeA',\
GetMultipleTrusteeW,'GetMultipleTrusteeW',\
GetMultipleTrusteeOperationA,'GetMultipleTrusteeOperationA',\
GetMultipleTrusteeOperationW,'GetMultipleTrusteeOperationW',\
GetNamedSecurityInfoA,'GetNamedSecurityInfoA',\
GetNamedSecurityInfoW,'GetNamedSecurityInfoW',\
GetNamedSecurityInfoExA,'GetNamedSecurityInfoExA',\
GetNamedSecurityInfoExW,'GetNamedSecurityInfoExW',\
GetNumberOfEventLogRecords,'GetNumberOfEventLogRecords',\
GetOldestEventLogRecord,'GetOldestEventLogRecord',\
GetOverlappedAccessResults,'GetOverlappedAccessResults',\
GetPrivateObjectSecurity,'GetPrivateObjectSecurity',\
GetSecurityDescriptorControl,'GetSecurityDescriptorControl',\
GetSecurityDescriptorDacl,'GetSecurityDescriptorDacl',\
GetSecurityDescriptorGroup,'GetSecurityDescriptorGroup',\
GetSecurityDescriptorLength,'GetSecurityDescriptorLength',\
GetSecurityDescriptorOwner,'GetSecurityDescriptorOwner',\
GetSecurityDescriptorSacl,'GetSecurityDescriptorSacl',\
GetSecurityInfo,'GetSecurityInfo',\
GetSecurityInfoExA,'GetSecurityInfoExW',\
GetSecurityInfoExW,'GetSecurityInfoExW',\
GetServiceDisplayNameA,'GetServiceDisplayNameA',\
GetServiceDisplayNameW,'GetServiceDisplayNameW',\
GetServiceKeyNameA,'GetServiceKeyNameA',\
GetServiceKeyNameW,'GetServiceKeyNameW',\
GetSidLengthRequiredA,'GetSidLengthRequiredA',\
GetSidLengthRequiredW,'GetSidLengthRequiredW',\
GetSidSubAuthority,'GetSidSubAuthority',\
GetSidSubAuthorityCount,'GetSidSubAuthorityCount',\
GetTokenInformation,'GetTokenInformation',\
GetTrusteeNameA,'GetTrusteeNameA',\
GetTrusteeNameW,'GetTrusteeNameW',\
GetTrusteeTypeA,'GetTrusteeTypeA',\
GetTrusteeTypeW,'GetTrusteeTypeW',\
GetUserNameA,'GetUserNameA',\
GetUserNameW,'GetUserNameW',\
I_ScSetServiceBitsA,'I_ScSetServiceBitsA',\
I_ScSetServiceBitsW,'I_ScSetServiceBitsW',\
ImpersonateLoggedOnUser,'ImpersonateLoggedOnUser',\
ImpersonateNamedPipeClient,'ImpersonateNamedPipeClient',\
ImpersonateSelf,'ImpersonateSelf',\
InitializeAcl,'InitializeAcl',\
InitializeSecurityDescriptor,'InitializeSecurityDescriptor',\
InitializeSid,'InitializeSid',\
InitiateSystemShutdownA,'InitiateSystemShutdownA',\
InitiateSystemShutdownW,'InitiateSystemShutdownW',\
IsTextUnicode,'IsTextUnicode',\
IsTokenRestricted,'IsTokenRestricted',\
IsValidAcl,'IsValidAcl',\
IsValidSecurityDescriptor,'IsValidSecurityDescriptor',\
IsValidSid,'IsValidSid',\
LockServiceDatabase,'LockServiceDatabase',\
LogonUserA,'LogonUserA',\
LogonUserW,'LogonUserW',\
LookupAccountNameA,'LookupAccountNameA',\
LookupAccountNameW,'LookupAccountNameW',\
LookupAccountSidA,'LookupAccountSidA',\
LookupAccountSidW,'LookupAccountSidW',\
LookupPrivilegeDisplayNameA,'LookupPrivilegeDisplayNameA',\
LookupPrivilegeDisplayNameW,'LookupPrivilegeDisplayNameW',\
LookupPrivilegeNameA,'LookupPrivilegeNameA',\
LookupPrivilegeNameW,'LookupPrivilegeNameW',\
LookupPrivilegeValueA,'LookupPrivilegeValueA',\
LookupPrivilegeValueW,'LookupPrivilegeValueW',\
LookupSecurityDescriptorPartsA,'LookupSecurityDescriptorPartsA',\
LookupSecurityDescriptorPartsW,'LookupSecurityDescriptorPartsW',\
LsaAddAccountRights,'LsaAddAccountRights',\
LsaAddPrivilegesToAccount,'LsaAddPrivilegesToAccount',\
LsaClearAuditLog,'LsaClearAuditLog',\
LsaClose,'LsaClose',\
LsaCreateAccount,'LsaCreateAccount',\
LsaCreateSecret,'LsaCreateSecret',\
LsaCreateTrustedDomain,'LsaCreateTrustedDomain',\
LsaCreateTrustedDomainEx,'LsaCreateTrustedDomainEx',\
LsaDelete,'LsaDelete',\
LsaDeleteTrustedDomain,'LsaDeleteTrustedDomain',\
LsaEnumerateAccountRights,'LsaEnumerateAccountRights',\
LsaEnumerateAccounts,'LsaEnumerateAccounts',\
LsaEnumerateAccountsWithUserRight,'LsaEnumerateAccountsWithUserRight',\
LsaEnumeratePrivileges,'LsaEnumeratePrivileges',\
LsaEnumeratePrivilegesOfAccount,'LsaEnumeratePrivilegesOfAccount',\
LsaEnumerateTrustedDomains,'LsaEnumerateTrustedDomains',\
LsaEnumerateTrustedDomainsEx,'LsaEnumerateTrustedDomainsEx',\
LsaFreeMemory,'LsaFreeMemory',\
LsaGetQuotasForAccount,'LsaGetQuotasForAccount',\
LsaGetSystemAccessAccount,'LsaGetSystemAccessAccount',\
LsaGetUserName,'LsaGetUserName',\
LsaICLookupNames,'LsaICLookupNames',\
LsaICLookupSids,'LsaICLookupSids',\
LsaIGetTrustedDomainAuthInfoBlobs,'LsaIGetTrustedDomainAuthInfoBlobs',\
LsaISetTrustedDomainAuthInfoBlobs,'LsaISetTrustedDomainAuthInfoBlobs',\
LsaLookupNames,'LsaLookupNames',\
LsaLookupPrivilegeDisplayName,'LsaLookupPrivilegeDisplayName',\
LsaLookupPrivilegeName,'LsaLookupPrivilegeName',\
LsaLookupPrivilegeValue,'LsaLookupPrivilegeValue',\
LsaLookupSids,'LsaLookupSids',\
LsaNtStatusToWinError,'LsaNtStatusToWinError',\
LsaOpenAccount,'LsaOpenAccount',\
LsaOpenPolicy,'LsaOpenPolicy',\
LsaOpenSecret,'LsaOpenSecret',\
LsaOpenTrustedDomain,'LsaOpenTrustedDomain',\
LsaQueryDomainInformationPolicy,'LsaQueryDomainInformationPolicy',\
LsaQueryInfoTrustedDomain,'LsaQueryInfoTrustedDomain',\
LsaQueryInformationPolicy,'LsaQueryInformationPolicy',\
LsaQueryLocalInformationPolicy,'LsaQueryLocalInformationPolicy',\
LsaQuerySecret,'LsaQuerySecret',\
LsaQuerySecurityObject,'LsaQuerySecurityObject',\
LsaQueryTrustedDomainInfo,'LsaQueryTrustedDomainInfo',\
LsaQueryTrustedDomainInfoByName,'LsaQueryTrustedDomainInfoByName',\
LsaRemoveAccountRights,'LsaRemoveAccountRights',\
LsaRemovePrivilegesFromAccount,'LsaRemovePrivilegesFromAccount',\
LsaRetrievePrivateData,'LsaRetrievePrivateData',\
LsaSetDomainInformationPolicy,'LsaSetDomainInformationPolicy',\
LsaSetInformationPolicy,'LsaSetInformationPolicy',\
LsaSetInformationTrustedDomain,'LsaSetInformationTrustedDomain',\
LsaSetLocalInformationPolicy,'LsaSetLocalInformationPolicy',\
LsaSetQuotasForAccount,'LsaSetQuotasForAccount',\
LsaSetSecret,'LsaSetSecret',\
LsaSetSecurityObject,'LsaSetSecurityObject',\
LsaSetSystemAccessAccount,'LsaSetSystemAccessAccount',\
LsaSetTrustedDomainInfoByName,'LsaSetTrustedDomainInfoByName',\
LsaSetTrustedDomainInformation,'LsaSetTrustedDomainInformation',\
LsaStorePrivateData,'LsaStorePrivateData',\
MakeAbsoluteSD,'MakeAbsoluteSD',\
MakeSelfRelativeSD,'MakeSelfRelativeSD',\
MapGenericMask,'MapGenericMask',\
NotifyBootConfigStatus,'NotifyBootConfigStatus',\
NotifyChangeEventLog,'NotifyChangeEventLog',\
ObjectCloseAuditAlarmA,'ObjectCloseAuditAlarmA',\
ObjectCloseAuditAlarmW,'ObjectCloseAuditAlarmW',\
ObjectDeleteAuditAlarmA,'ObjectDeleteAuditAlarmA',\
ObjectDeleteAuditAlarmW,'ObjectDeleteAuditAlarmW',\
ObjectOpenAuditAlarmA,'ObjectOpenAuditAlarmA',\
ObjectOpenAuditAlarmW,'ObjectOpenAuditAlarmW',\
ObjectPrivilegeAuditAlarmA,'ObjectPrivilegeAuditAlarmA',\
ObjectPrivilegeAuditAlarmW,'ObjectPrivilegeAuditAlarmW',\
OpenBackupEventLogA,'OpenBackupEventLogA',\
OpenBackupEventLogW,'OpenBackupEventLogW',\
OpenEventLogA,'OpenEventLogA',\
OpenEventLogW,'OpenEventLogW',\
OpenProcessToken,'OpenProcessToken',\
OpenRawA,'OpenRawA',\
OpenRawW,'OpenRawW',\
OpenSCManagerA,'OpenSCManagerA',\
OpenSCManagerW,'OpenSCManagerW',\
OpenServiceA,'OpenServiceA',\
OpenServiceW,'OpenServiceW',\
OpenThreadToken,'OpenThreadToken',\
PrivilegeCheck,'PrivilegeCheck',\
PrivilegedServiceAuditAlarmA,'PrivilegedServiceAuditAlarmA',\
PrivilegedServiceAuditAlarmW,'PrivilegedServiceAuditAlarmW',\
QueryRecoveryAgentsA,'QueryRecoveryAgentsA',\
QueryRecoveryAgentsW,'QueryRecoveryAgentsW',\
QueryServiceConfig2A,'QueryServiceConfig2A',\
QueryServiceConfig2W,'QueryServiceConfig2W',\
QueryServiceConfigA,'QueryServiceConfigA',\
QueryServiceConfigW,'QueryServiceConfigW',\
QueryServiceLockStatusA,'QueryServiceLockStatusA',\
QueryServiceLockStatusW,'QueryServiceLockStatusW',\
QueryServiceObjectSecurity,'QueryServiceObjectSecurity',\
QueryServiceStatus,'QueryServiceStatus',\
QueryWindows31FilesMigration,'QueryWindows31FilesMigration',\
ReadEventLogA,'ReadEventLogA',\
ReadEventLogW,'ReadEventLogW',\
ReadRaw,'ReadRaw',\
RegCloseKey,'RegCloseKey',\
RegConnectRegistryA,'RegConnectRegistryA',\
RegConnectRegistryW,'RegConnectRegistryW',\
RegCreateKeyA,'RegCreateKeyA',\
RegCreateKeyW,'RegCreateKeyW',\
RegCreateKeyExA,'RegCreateKeyExA',\
RegCreateKeyExW,'RegCreateKeyExW',\
RegDeleteKeyA,'RegDeleteKeyA',\
RegDeleteKeyW,'RegDeleteKeyW',\
RegDeleteValueA,'RegDeleteValueA',\
RegDeleteValueW,'RegDeleteValueW',\
RegEnumKeyA,'RegEnumKeyA',\
RegEnumKeyW,'RegEnumKeyW',\
RegEnumKeyExA,'RegEnumKeyExA',\
RegEnumKeyExW,'RegEnumKeyExW',\
RegEnumValueA,'RegEnumValueA',\
RegEnumValueW,'RegEnumValueW',\
RegFlushKey,'RegFlushKey',\
RegGetKeySecurity,'RegGetKeySecurity',\
RegLoadKeyA,'RegLoadKeyA',\
RegLoadKeyW,'RegLoadKeyW',\
RegNotifyChangeKeyValue,'RegNotifyChangeKeyValue',\
RegOpenKeyA,'RegOpenKeyA',\
RegOpenKeyW,'RegOpenKeyW',\
RegOpenKeyExA,'RegOpenKeyExA',\
RegOpenKeyExW,'RegOpenKeyExW',\
RegOverridePredefKey,'RegOverridePredefKey',\
RegQueryInfoKeyA,'RegQueryInfoKeyA',\
RegQueryInfoKeyW,'RegQueryInfoKeyW',\
RegQueryMultipleValuesA,'RegQueryMultipleValuesA',\
RegQueryMultipleValuesW,'RegQueryMultipleValuesW',\
RegQueryValueA,'RegQueryValueA',\
RegQueryValueW,'RegQueryValueW',\
RegQueryValueExA,'RegQueryValueExA',\
RegQueryValueExW,'RegQueryValueExW',\
RegReplaceKeyA,'RegReplaceKeyA',\
RegReplaceKeyW,'RegReplaceKeyW',\
RegRestoreKeyA,'RegRestoreKeyA',\
RegRestoreKeyW,'RegRestoreKeyW',\
RegSaveKeyA,'RegSaveKeyA',\
RegSaveKeyW,'RegSaveKeyW',\
RegSetKeySecurity,'RegSetKeySecurity',\
RegSetValueA,'RegSetValueA',\
RegSetValueW,'RegSetValueW',\
RegSetValueExA,'RegSetValueExA',\
RegSetValueExW,'RegSetValueExW',\
RegUnLoadKeyA,'RegUnLoadKeyA',\
RegUnLoadKeyW,'RegUnLoadKeyW',\
RegisterEventSourceA,'RegisterEventSourceA',\
RegisterEventSourceW,'RegisterEventSourceW',\
RegisterServiceCtrlHandlerA,'RegisterServiceCtrlHandlerA',\
RegisterServiceCtrlHandlerW,'RegisterServiceCtrlHandlerW',\
ReportEventA,'ReportEventA',\
ReportEventW,'ReportEventW',\
RevertToSelf,'RevertToSelf',\
SetAclInformation,'SetAclInformation',\
SetEntriesInAccessListA,'SetEntriesInAccessListA',\
SetEntriesInAccessListW,'SetEntriesInAccessListW',\
SetEntriesInAclA,'SetEntriesInAclA',\
SetEntriesInAclW,'SetEntriesInAclW',\
SetEntriesInAuditListA,'SetEntriesInAuditListA',\
SetEntriesInAuditListW,'SetEntriesInAuditListW',\
SetFileSecurityA,'SetFileSecurityA',\
SetFileSecurityW,'SetFileSecurityW',\
SetKernelObjectSecurity,'SetKernelObjectSecurity',\
SetNamedSecurityInfoA,'SetNamedSecurityInfoA',\
SetNamedSecurityInfoW,'SetNamedSecurityInfoW',\
SetNamedSecurityInfoExA,'SetNamedSecurityInfoExA',\
SetNamedSecurityInfoExW,'SetNamedSecurityInfoExW',\
SetPrivateObjectSecurity,'SetPrivateObjectSecurity',\
SetPrivateObjectSecurityEx,'SetPrivateObjectSecurityEx',\
SetSecurityDescriptorControl,'SetSecurityDescriptorControl',\
SetSecurityDescriptorDacl,'SetSecurityDescriptorDacl',\
SetSecurityDescriptorGroup,'SetSecurityDescriptorGroup',\
SetSecurityDescriptorOwner,'SetSecurityDescriptorOwner',\
SetSecurityDescriptorSacl,'SetSecurityDescriptorSacl',\
SetSecurityInfo,'SetSecurityInfo',\
SetSecurityInfoExA,'SetSecurityInfoExA',\
SetSecurityInfoExW,'SetSecurityInfoExW',\
SetServiceBits,'SetServiceBits',\
SetServiceObjectSecurity,'SetServiceObjectSecurity',\
SetServiceStatus,'SetServiceStatus',\
SetThreadToken,'SetThreadToken',\
SetTokenInformation,'SetTokenInformation',\
StartServiceA,'StartServiceA',\
StartServiceW,'StartServiceW',\
StartServiceCtrlDispatcherA,'StartServiceCtrlDispatcherA',\
StartServiceCtrlDispatcherW,'StartServiceCtrlDispatcherW',\
SynchronizeWindows31FilesAndWindowsNTRegistry,'SynchronizeWindows31FilesAndWindowsNTRegistry',\
TrusteeAccessToObjectA,'TrusteeAccessToObjectA',\
TrusteeAccessToObjectW,'TrusteeAccessToObjectW',\
UnlockServiceDatabase,'UnlockServiceDatabase',\
WriteRaw,'WriteRaw'

api ACCCTRL_DEFAULT_PROVIDER,\
    SERVICES_ACTIVE_DATABASE,\
    SERVICES_FAILED_DATABASE,\
    SC_GROUP_IDENTIFIER,\
    SERVICE_DESCRIPTION,\
    SERVICE_FAILURE_ACTIONS,\
    QUERY_SERVICE_LOCK_STATUS,\
    QUERY_SERVICE_CONFIG,\
    SERVICE_TABLE_ENTRY,\
    ENUM_SERVICE_STATUS,\
    ENUM_SERVICE_STATUS_PROCESS,\
    INHERITED_FROM,\
    OBJECTS_AND_NAME,\
    TRUSTEE,\
    EXPLICIT_ACCESS,\
    ACTRL_ACCESS_ENTRY,\
    ACTRL_ACCESS_ENTRY_LIST,\
    ACTRL_PROPERTY_ENTRY,\
    ACTRL_ALIST,\
    TRUSTEE_ACCESS,\
    ACTRL_ACCESS_INFO,\
    ACTRL_CONTROL_INFO,\
    ACTRL_AUDIT,\
    AbortSystemShutdown,\
    AccessCheckByTypeAndAuditAlarm,\
    AccessCheckAndAuditAlarm,\
    AccessCheckByTypeResultListAndAuditAlarm,\
    BackupEventLog,\
    BuildExplicitAccessWithName,\
    BuildImpersonateExplicitAccessWithName,\
    BuildImpersonateTrustee,\
    BuildSecurityDescriptor,\
    BuildTrusteeWithName,\
    BuildTrusteeWithSid,\
    ChangeServiceConfig2,\
    ChangeServiceConfig,\
    ClearEventLog,\
    ConvertAccessToSecurityDescriptor,\
    ConvertSecurityDescriptorToAccess,\
    ConvertSecurityDescriptorToAccessNamed,\
    CreateProcessAsUser,\
    CreateService,\
    CryptAcquireContext,\
    CryptEnumProviderTypes,\
    CryptEnumProviders,\
    CryptGetDefaultProvider,\
    CryptSetProvider,\
    CryptSetProviderEx,\
    CryptSignHash,\
    CryptVerifySignature,\
    DecryptFile,\
    ElfBackupEventLogFile,\
    ElfClearEventLogFile,\
    ElfOpenBackupEventLog,\
    ElfOpenEventLog,\
    ElfReadEventLog,\
    ElfRegisterEventSource,\
    ElfReportEvent,\
    EncryptFile,\
    EnumDependentServices,\
    EnumServicesStatus,\
    GetAccessPermissionsForObject,\
    GetAuditedPermissionsFromAcl,\
    GetCurrentHwProfile,\
    GetEffectiveRightsFromAcl,\
    GetExplicitEntriesFromAcl,\
    GetFileSecurity,\
    GetMultipleTrustee,\
    GetMultipleTrusteeOperation,\
    GetNamedSecurityInfo,\
    GetNamedSecurityInfoEx,\
    GetSecurityInfoEx,\
    GetServiceDisplayName,\
    GetServiceKeyName,\
    GetSidLengthRequired,\
    GetTrusteeName,\
    GetTrusteeType,\
    GetUserName,\
    I_ScSetServiceBits,\
    InitiateSystemShutdown,\
    LogonUser,\
    LookupAccountName,\
    LookupAccountSid,\
    LookupPrivilegeDisplayName,\
    LookupPrivilegeName,\
    LookupPrivilegeValue,\
    LookupSecurityDescriptorParts,\
    ObjectCloseAuditAlarm,\
    ObjectDeleteAuditAlarm,\
    ObjectOpenAuditAlarm,\
    ObjectPrivilegeAuditAlarm,\
    OpenBackupEventLog,\
    OpenEventLog,\
    OpenRaw,\
    OpenSCManager,\
    OpenService,\
    PrivilegedServiceAuditAlarm,\
    QueryRecoveryAgents,\
    QueryServiceConfig2,\
    QueryServiceConfig,\
    QueryServiceLockStatus,\
    ReadEventLog,\
    RegConnectRegistry,\
    RegCreateKey,\
    RegCreateKeyEx,\
    RegDeleteKey,\
    RegDeleteValue,\
    RegEnumKey,\
    RegEnumKeyEx,\
    RegEnumValue,\
    RegLoadKey,\
    RegOpenKey,\
    RegOpenKeyEx,\
    RegQueryInfoKey,\
    RegQueryMultipleValues,\
    RegQueryValue,\
    RegQueryValueEx,\
    RegReplaceKey,\
    RegRestoreKey,\
    RegSaveKey,\
    RegSetValue,\
    RegSetValueEx,\
    RegUnLoadKey,\
    RegisterEventSource,\
    RegisterServiceCtrlHandler,\
    ReportEventW,\
    SetEntriesInAccessList,\
    SetEntriesInAcl,\
    SetEntriesInAuditList,\
    SetFileSecurity,\
    SetNamedSecurityInfo,\
    SetNamedSecurityInfoEx,\
    SetSecurityInfoEx,\
    StartService,\
    StartServiceCtrlDispatcher,\
    TrusteeAccessToObject

end if ;ADVAPI32_INC
