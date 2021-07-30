; ====================================================;
;                                                     ;
;     advapi32.inc for EC v2 Fasm visual projects     ;
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

STANDARD_RIGHTS_REQUIRED                        equ         000F0000H

STANDARD_RIGHTS_READ                            equ         READ_CONTROL
STANDARD_RIGHTS_WRITE                           equ         READ_CONTROL
STANDARD_RIGHTS_EXECUTE                         equ         READ_CONTROL

STANDARD_RIGHTS_ALL                             equ         (001F0000H)

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
    ServiceStatus  SERVICE_STATUS
ends

struct ENUM_SERVICE_STATUSW
    lpServiceName  xptr  ?
    lpDisplayName  xptr  ?
    ServiceStatus  SERVICE_STATUS
ends

struct ENUM_SERVICE_STATUS_PROCESSA
    lpServiceName        xptr  ?
    lpDisplayName        xptr  ?
    ServiceStatusProcess SERVICE_STATUS_PROCESS
ends

struct ENUM_SERVICE_STATUS_PROCESSW
    lpServiceName        xptr  ?
    lpDisplayName        xptr  ?
    ServiceStatusProcess SERVICE_STATUS_PROCESS
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
    ObjectTypeGuid          GUID
    InheritedObjectTypeGuid GUID
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
    Trustee              TRUSTEE_A
ends

struct EXPLICIT_ACCESS_W
    grfAccessPermissions dd        ?
    grfAccessMode        xptr      ?
    grfInheritance       dd        ?
    Trustee              TRUSTEE_W
ends

struct EXPLICIT_ACCESSA
    grfAccessPermissions dd        ?
    grfAccessMode        xptr      ?
    grfInheritance       dd        ?
    Trustee              TRUSTEE_A
ends

struct EXPLICIT_ACCESSW
    grfAccessPermissions dd        ?
    grfAccessMode        xptr      ?
    grfInheritance       dd        ?
    Trustee              TRUSTEE_W
ends

struct ACTRL_ACCESS_ENTRYA
    Trustee            TRUSTEE_A
    fAccessFlags       dd        ?
    Access             dd        ?
    ProvSpecificAccess dd        ?
    Inheritance        dd        ?
    lpInheritProperty  xptr      ?
ends

struct ACTRL_ACCESS_ENTRYW
    Trustee            TRUSTEE_W
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

if defined APP_WIN64
    extrn '__imp_AbortSystemShutdownA' as AbortSystemShutdownA:qword
    extrn '__imp_AbortSystemShutdownW' as AbortSystemShutdownW:qword
    extrn '__imp_AccessCheck' as AccessCheck:qword
    extrn '__imp_AccessCheckAndAuditAlarmA' as AccessCheckAndAuditAlarmA:qword
    extrn '__imp_AccessCheckAndAuditAlarmW' as AccessCheckAndAuditAlarmW:qword
    extrn '__imp_AddAccessAllowedAce' as AddAccessAllowedAce:qword
    extrn '__imp_AddAccessDeniedAce' as AddAccessDeniedAce:qword
    extrn '__imp_AddAce' as AddAce:qword
    extrn '__imp_AddAuditAccessAce' as AddAuditAccessAce:qword
    extrn '__imp_AdjustTokenGroups' as AdjustTokenGroups:qword
    extrn '__imp_AdjustTokenPrivileges' as AdjustTokenPrivileges:qword
    extrn '__imp_AllocateAndInitializeSid' as AllocateAndInitializeSid:qword
    extrn '__imp_AllocateLocallyUniqueId' as AllocateLocallyUniqueId:qword
    extrn '__imp_AreAllAccessesGranted' as AreAllAccessesGranted:qword
    extrn '__imp_AreAnyAccessesGranted' as AreAnyAccessesGranted:qword
    extrn '__imp_BackupEventLogA' as BackupEventLogA:qword
    extrn '__imp_BackupEventLogW' as BackupEventLogW:qword
    extrn '__imp_ChangeServiceConfigA' as ChangeServiceConfigA:qword
    extrn '__imp_ChangeServiceConfigW' as ChangeServiceConfigW:qword
    extrn '__imp_ClearEventLogA' as ClearEventLogA:qword
    extrn '__imp_ClearEventLogW' as ClearEventLogW:qword
    extrn '__imp_CloseEventLog' as CloseEventLog:qword
    extrn '__imp_CloseServiceHandle' as CloseServiceHandle:qword
    extrn '__imp_ControlService' as ControlService:qword
    extrn '__imp_CopySid' as CopySid:qword
    extrn '__imp_CreatePrivateObjectSecurity' as CreatePrivateObjectSecurity:qword
    extrn '__imp_CreateServiceA' as CreateServiceA:qword
    extrn '__imp_CreateServiceW' as CreateServiceW:qword
    extrn '__imp_CryptAcquireContextA' as CryptAcquireContextA:qword
    extrn '__imp_CryptAcquireContextW' as CryptAcquireContextW:qword
    extrn '__imp_CryptCreateHash' as CryptCreateHash:qword
    extrn '__imp_CryptDecrypt' as CryptDecrypt:qword
    extrn '__imp_CryptDeriveKey' as CryptDeriveKey:qword
    extrn '__imp_CryptDestroyHash' as CryptDestroyHash:qword
    extrn '__imp_CryptDestroyKey' as CryptDestroyKey:qword
    extrn '__imp_CryptEncrypt' as CryptEncrypt:qword
    extrn '__imp_CryptExportKey' as CryptExportKey:qword
    extrn '__imp_CryptGenKey' as CryptGenKey:qword
    extrn '__imp_CryptGenRandom' as CryptGenRandom:qword
    extrn '__imp_CryptGetHashParam' as CryptGetHashParam:qword
    extrn '__imp_CryptGetKeyParam' as CryptGetKeyParam:qword
    extrn '__imp_CryptGetProvParam' as CryptGetProvParam:qword
    extrn '__imp_CryptGetUserKey' as CryptGetUserKey:qword
    extrn '__imp_CryptHashData' as CryptHashData:qword
    extrn '__imp_CryptHashSessionKey' as CryptHashSessionKey:qword
    extrn '__imp_CryptImportKey' as CryptImportKey:qword
    extrn '__imp_CryptReleaseContext' as CryptReleaseContext:qword
    extrn '__imp_CryptSetHashParam' as CryptSetHashParam:qword
    extrn '__imp_CryptSetKeyParam' as CryptSetKeyParam:qword
    extrn '__imp_CryptSetProviderA' as CryptSetProviderA:qword
    extrn '__imp_CryptSetProviderExA' as CryptSetProviderExA:qword
    extrn '__imp_CryptSetProviderExW' as CryptSetProviderExW:qword
    extrn '__imp_CryptSetProviderW' as CryptSetProviderW:qword
    extrn '__imp_CryptSetProvParam' as CryptSetProvParam:qword
    extrn '__imp_CryptSignHashA' as CryptSignHashA:qword
    extrn '__imp_CryptSignHashW' as CryptSignHashW:qword
    extrn '__imp_CryptVerifySignatureA' as CryptVerifySignatureA:qword
    extrn '__imp_CryptVerifySignatureW' as CryptVerifySignatureW:qword
    extrn '__imp_DeleteAce' as DeleteAce:qword
    extrn '__imp_DeleteService' as DeleteService:qword
    extrn '__imp_DeregisterEventSource' as DeregisterEventSource:qword
    extrn '__imp_DestroyPrivateObjectSecurity' as DestroyPrivateObjectSecurity:qword
    extrn '__imp_DuplicateToken' as DuplicateToken:qword
    extrn '__imp_EnumDependentServicesA' as EnumDependentServicesA:qword
    extrn '__imp_EnumDependentServicesW' as EnumDependentServicesW:qword
    extrn '__imp_EnumServicesStatusA' as EnumServicesStatusA:qword
    extrn '__imp_EnumServicesStatusW' as EnumServicesStatusW:qword
    extrn '__imp_EqualPrefixSid' as EqualPrefixSid:qword
    extrn '__imp_EqualSid' as EqualSid:qword
    extrn '__imp_FindFirstFreeAce' as FindFirstFreeAce:qword
    extrn '__imp_FreeSid' as FreeSid:qword
    extrn '__imp_GetAce' as GetAce:qword
    extrn '__imp_GetAclInformation' as GetAclInformation:qword
    extrn '__imp_GetFileSecurityA' as GetFileSecurityA:qword
    extrn '__imp_GetFileSecurityW' as GetFileSecurityW:qword
    extrn '__imp_GetKernelObjectSecurity' as GetKernelObjectSecurity:qword
    extrn '__imp_GetLengthSid' as GetLengthSid:qword
    extrn '__imp_GetNumberOfEventLogRecords' as GetNumberOfEventLogRecords:qword
    extrn '__imp_GetOldestEventLogRecord' as GetOldestEventLogRecord:qword
    extrn '__imp_GetPrivateObjectSecurity' as GetPrivateObjectSecurity:qword
    extrn '__imp_GetSecurityDescriptorControl' as GetSecurityDescriptorControl:qword
    extrn '__imp_GetSecurityDescriptorDacl' as GetSecurityDescriptorDacl:qword
    extrn '__imp_GetSecurityDescriptorGroup' as GetSecurityDescriptorGroup:qword
    extrn '__imp_GetSecurityDescriptorLength' as GetSecurityDescriptorLength:qword
    extrn '__imp_GetSecurityDescriptorOwner' as GetSecurityDescriptorOwner:qword
    extrn '__imp_GetSecurityDescriptorSacl' as GetSecurityDescriptorSacl:qword
    extrn '__imp_GetServiceDisplayNameA' as GetServiceDisplayNameA:qword
    extrn '__imp_GetServiceDisplayNameW' as GetServiceDisplayNameW:qword
    extrn '__imp_GetServiceKeyNameA' as GetServiceKeyNameA:qword
    extrn '__imp_GetServiceKeyNameW' as GetServiceKeyNameW:qword
    extrn '__imp_GetSidIdentifierAuthority' as GetSidIdentifierAuthority:qword
    extrn '__imp_GetSidLengthRequired' as GetSidLengthRequired:qword
    extrn '__imp_GetSidSubAuthority' as GetSidSubAuthority:qword
    extrn '__imp_GetSidSubAuthorityCount' as GetSidSubAuthorityCount:qword
    extrn '__imp_GetTokenInformation' as GetTokenInformation:qword
    extrn '__imp_GetUserNameA' as GetUserNameA:qword
    extrn '__imp_GetUserNameW' as GetUserNameW:qword
    extrn '__imp_ImpersonateLoggedOnUser' as ImpersonateLoggedOnUser:qword
    extrn '__imp_ImpersonateNamedPipeClient' as ImpersonateNamedPipeClient:qword
    extrn '__imp_ImpersonateSelf' as ImpersonateSelf:qword
    extrn '__imp_InitializeAcl' as InitializeAcl:qword
    extrn '__imp_InitializeSecurityDescriptor' as InitializeSecurityDescriptor:qword
    extrn '__imp_InitializeSid' as InitializeSid:qword
    extrn '__imp_InitiateSystemShutdownA' as InitiateSystemShutdownA:qword
    extrn '__imp_InitiateSystemShutdownW' as InitiateSystemShutdownW:qword
    extrn '__imp_IsTextUnicode' as IsTextUnicode:qword
    extrn '__imp_IsValidAcl' as IsValidAcl:qword
    extrn '__imp_IsValidSecurityDescriptor' as IsValidSecurityDescriptor:qword
    extrn '__imp_IsValidSid' as IsValidSid:qword
    extrn '__imp_LockServiceDatabase' as LockServiceDatabase:qword
    extrn '__imp_LogonUserA' as LogonUserA:qword
    extrn '__imp_LogonUserW' as LogonUserW:qword
    extrn '__imp_LookupAccountNameA' as LookupAccountNameA:qword
    extrn '__imp_LookupAccountNameW' as LookupAccountNameW:qword
    extrn '__imp_LookupAccountSidA' as LookupAccountSidA:qword
    extrn '__imp_LookupAccountSidW' as LookupAccountSidW:qword
    extrn '__imp_LookupPrivilegeDisplayNameA' as LookupPrivilegeDisplayNameA:qword
    extrn '__imp_LookupPrivilegeDisplayNameW' as LookupPrivilegeDisplayNameW:qword
    extrn '__imp_LookupPrivilegeNameA' as LookupPrivilegeNameA:qword
    extrn '__imp_LookupPrivilegeNameW' as LookupPrivilegeNameW:qword
    extrn '__imp_LookupPrivilegeValueA' as LookupPrivilegeValueA:qword
    extrn '__imp_LookupPrivilegeValueW' as LookupPrivilegeValueW:qword
    extrn '__imp_MakeAbsoluteSD' as MakeAbsoluteSD:qword
    extrn '__imp_MakeSelfRelativeSD' as MakeSelfRelativeSD:qword
    extrn '__imp_MapGenericMask' as MapGenericMask:qword
    extrn '__imp_NotifyBootConfigStatus' as NotifyBootConfigStatus:qword
    extrn '__imp_NotifyChangeEventLog' as NotifyChangeEventLog:qword
    extrn '__imp_ObjectCloseAuditAlarmA' as ObjectCloseAuditAlarmA:qword
    extrn '__imp_ObjectCloseAuditAlarmW' as ObjectCloseAuditAlarmW:qword
    extrn '__imp_ObjectOpenAuditAlarmA' as ObjectOpenAuditAlarmA:qword
    extrn '__imp_ObjectOpenAuditAlarmW' as ObjectOpenAuditAlarmW:qword
    extrn '__imp_ObjectPrivilegeAuditAlarmA' as ObjectPrivilegeAuditAlarmA:qword
    extrn '__imp_ObjectPrivilegeAuditAlarmW' as ObjectPrivilegeAuditAlarmW:qword
    extrn '__imp_OpenBackupEventLogA' as OpenBackupEventLogA:qword
    extrn '__imp_OpenBackupEventLogW' as OpenBackupEventLogW:qword
    extrn '__imp_OpenEventLogA' as OpenEventLogA:qword
    extrn '__imp_OpenEventLogW' as OpenEventLogW:qword
    extrn '__imp_OpenSCManagerA' as OpenSCManagerA:qword
    extrn '__imp_OpenSCManagerW' as OpenSCManagerW:qword
    extrn '__imp_OpenServiceA' as OpenServiceA:qword
    extrn '__imp_OpenServiceW' as OpenServiceW:qword
    extrn '__imp_PrivilegeCheck' as PrivilegeCheck:qword
    extrn '__imp_PrivilegedServiceAuditAlarmA' as PrivilegedServiceAuditAlarmA:qword
    extrn '__imp_PrivilegedServiceAuditAlarmW' as PrivilegedServiceAuditAlarmW:qword
    extrn '__imp_QueryServiceConfigA' as QueryServiceConfigA:qword
    extrn '__imp_QueryServiceConfigW' as QueryServiceConfigW:qword
    extrn '__imp_QueryServiceLockStatusA' as QueryServiceLockStatusA:qword
    extrn '__imp_QueryServiceLockStatusW' as QueryServiceLockStatusW:qword
    extrn '__imp_QueryServiceObjectSecurity' as QueryServiceObjectSecurity:qword
    extrn '__imp_QueryServiceStatus' as QueryServiceStatus:qword
    extrn '__imp_ReadEventLogA' as ReadEventLogA:qword
    extrn '__imp_ReadEventLogW' as ReadEventLogW:qword
    extrn '__imp_RegConnectRegistryA' as RegConnectRegistryA:qword
    extrn '__imp_RegConnectRegistryW' as RegConnectRegistryW:qword
    extrn '__imp_RegCloseKey' as RegCloseKey:qword
    extrn '__imp_RegCreateKeyA' as RegCreateKeyA:qword
    extrn '__imp_RegCreateKeyExA' as RegCreateKeyExA:qword
    extrn '__imp_RegCreateKeyExW' as RegCreateKeyExW:qword
    extrn '__imp_RegCreateKeyW' as RegCreateKeyW:qword
    extrn '__imp_RegDeleteKeyA' as RegDeleteKeyA:qword
    extrn '__imp_RegDeleteKeyW' as RegDeleteKeyW:qword
    extrn '__imp_RegDeleteValueA' as RegDeleteValueA:qword
    extrn '__imp_RegDeleteValueW' as RegDeleteValueW:qword
    extrn '__imp_RegEnumKeyA' as RegEnumKeyA:qword
    extrn '__imp_RegEnumKeyExA' as RegEnumKeyExA:qword
    extrn '__imp_RegEnumKeyExW' as RegEnumKeyExW:qword
    extrn '__imp_RegEnumKeyW' as RegEnumKeyW:qword
    extrn '__imp_RegEnumValueA' as RegEnumValueA:qword
    extrn '__imp_RegEnumValueW' as RegEnumValueW:qword
    extrn '__imp_RegFlushKey' as RegFlushKey:qword
    extrn '__imp_RegGetKeySecurity' as RegGetKeySecurity:qword
    extrn '__imp_RegLoadKeyA' as RegLoadKeyA:qword
    extrn '__imp_RegLoadKeyW' as RegLoadKeyW:qword
    extrn '__imp_RegNotifyChangeKeyValue' as RegNotifyChangeKeyValue:qword
    extrn '__imp_RegOpenKeyA' as RegOpenKeyA:qword
    extrn '__imp_RegOpenKeyExA' as RegOpenKeyExA:qword
    extrn '__imp_RegOpenKeyExW' as RegOpenKeyExW:qword
    extrn '__imp_RegOpenKeyW' as RegOpenKeyW:qword
    extrn '__imp_RegQueryInfoKeyA' as RegQueryInfoKeyA:qword
    extrn '__imp_RegQueryInfoKeyW' as RegQueryInfoKeyW:qword
    extrn '__imp_RegQueryMultipleValuesA' as RegQueryMultipleValuesA:qword
    extrn '__imp_RegQueryMultipleValuesW' as RegQueryMultipleValuesW:qword
    extrn '__imp_RegQueryValueA' as RegQueryValueA:qword
    extrn '__imp_RegQueryValueExA' as RegQueryValueExA:qword
    extrn '__imp_RegQueryValueExW' as RegQueryValueExW:qword
    extrn '__imp_RegQueryValueW' as RegQueryValueW:qword
    extrn '__imp_RegReplaceKeyA' as RegReplaceKeyA:qword
    extrn '__imp_RegReplaceKeyW' as RegReplaceKeyW:qword
    extrn '__imp_RegRestoreKeyA' as RegRestoreKeyA:qword
    extrn '__imp_RegRestoreKeyW' as RegRestoreKeyW:qword
    extrn '__imp_RegSaveKeyA' as RegSaveKeyA:qword
    extrn '__imp_RegSaveKeyW' as RegSaveKeyW:qword
    extrn '__imp_RegSetKeySecurity' as RegSetKeySecurity:qword
    extrn '__imp_RegSetValueA' as RegSetValueA:qword
    extrn '__imp_RegSetValueExA' as RegSetValueExA:qword
    extrn '__imp_RegSetValueExW' as RegSetValueExW:qword
    extrn '__imp_RegSetValueW' as RegSetValueW:qword
    extrn '__imp_RegUnLoadKeyA' as RegUnLoadKeyA:qword
    extrn '__imp_RegUnLoadKeyW' as RegUnLoadKeyW:qword
    extrn '__imp_RegisterEventSourceA' as RegisterEventSourceA:qword
    extrn '__imp_RegisterEventSourceW' as RegisterEventSourceW:qword
    extrn '__imp_RegisterServiceCtrlHandlerA' as RegisterServiceCtrlHandlerA:qword
    extrn '__imp_RegisterServiceCtrlHandlerW' as RegisterServiceCtrlHandlerW:qword
    extrn '__imp_ReportEventA' as ReportEventA:qword
    extrn '__imp_ReportEventW' as ReportEventW:qword
    extrn '__imp_RevertToSelf' as RevertToSelf:qword
    extrn '__imp_SetAclInformation' as SetAclInformation:qword
    extrn '__imp_SetFileSecurityA' as SetFileSecurityA:qword
    extrn '__imp_SetFileSecurityW' as SetFileSecurityW:qword
    extrn '__imp_SetKernelObjectSecurity' as SetKernelObjectSecurity:qword
    extrn '__imp_SetPrivateObjectSecurity' as SetPrivateObjectSecurity:qword
    extrn '__imp_SetSecurityDescriptorDacl' as SetSecurityDescriptorDacl:qword
    extrn '__imp_SetSecurityDescriptorGroup' as SetSecurityDescriptorGroup:qword
    extrn '__imp_SetSecurityDescriptorOwner' as SetSecurityDescriptorOwner:qword
    extrn '__imp_SetSecurityDescriptorSacl' as SetSecurityDescriptorSacl:qword
    extrn '__imp_SetServiceBits' as SetServiceBits:qword
    extrn '__imp_SetServiceObjectSecurity' as SetServiceObjectSecurity:qword
    extrn '__imp_SetServiceStatus' as SetServiceStatus:qword
    extrn '__imp_SetThreadToken' as SetThreadToken:qword
    extrn '__imp_SetTokenInformation' as SetTokenInformation:qword
    extrn '__imp_StartServiceA' as StartServiceA:qword
    extrn '__imp_StartServiceCtrlDispatcherA' as StartServiceCtrlDispatcherA:qword
    extrn '__imp_StartServiceCtrlDispatcherW' as StartServiceCtrlDispatcherW:qword
    extrn '__imp_StartServiceW' as StartServiceW:qword
    extrn '__imp_UnlockServiceDatabase' as UnlockServiceDatabase:qword

    if (NTDDI_VERSION >= NTDDI_WIN98_ME)
        extrn '__imp_BuildExplicitAccessWithNameA' as BuildExplicitAccessWithNameA:qword
        extrn '__imp_BuildExplicitAccessWithNameW' as BuildExplicitAccessWithNameW:qword
        extrn '__imp_BuildSecurityDescriptorA' as BuildSecurityDescriptorA:qword
        extrn '__imp_BuildSecurityDescriptorW' as BuildSecurityDescriptorW:qword
        extrn '__imp_BuildTrusteeWithNameA' as BuildTrusteeWithNameA:qword
        extrn '__imp_BuildTrusteeWithNameW' as BuildTrusteeWithNameW:qword
        extrn '__imp_BuildTrusteeWithSidA' as BuildTrusteeWithSidA:qword
        extrn '__imp_BuildTrusteeWithSidW' as BuildTrusteeWithSidW:qword
        extrn '__imp_ConvertAccessToSecurityDescriptorA' as ConvertAccessToSecurityDescriptorA:qword
        extrn '__imp_ConvertAccessToSecurityDescriptorW' as ConvertAccessToSecurityDescriptorW:qword
        extrn '__imp_ConvertSecurityDescriptorToAccessA' as ConvertSecurityDescriptorToAccessA:qword
        extrn '__imp_ConvertSecurityDescriptorToAccessW' as ConvertSecurityDescriptorToAccessW:qword
        extrn '__imp_ConvertSecurityDescriptorToAccessNamedA' as ConvertSecurityDescriptorToAccessNamedA:qword
        extrn '__imp_ConvertSecurityDescriptorToAccessNamedW' as ConvertSecurityDescriptorToAccessNamedW:qword
        extrn '__imp_CryptContextAddRef' as CryptContextAddRef:qword
        extrn '__imp_CryptDuplicateHash' as CryptDuplicateHash:qword
        extrn '__imp_CryptDuplicateKey' as CryptDuplicateKey:qword
        extrn '__imp_CryptEnumProvidersA' as CryptEnumProvidersA:qword
        extrn '__imp_CryptEnumProviderTypesA' as CryptEnumProviderTypesA:qword
        extrn '__imp_CryptEnumProviderTypesW' as CryptEnumProviderTypesW:qword
        extrn '__imp_CryptEnumProvidersW' as CryptEnumProvidersW:qword
        extrn '__imp_CryptGetDefaultProviderA' as CryptGetDefaultProviderA:qword
        extrn '__imp_CryptGetDefaultProviderW' as CryptGetDefaultProviderW:qword
        extrn '__imp_DuplicateTokenEx' as DuplicateTokenEx:qword
        extrn '__imp_GetAccessPermissionsForObjectA' as GetAccessPermissionsForObjectA:qword
        extrn '__imp_GetAccessPermissionsForObjectW' as GetAccessPermissionsForObjectW:qword
        extrn '__imp_GetAuditedPermissionsFromAclA' as GetAuditedPermissionsFromAclA:qword
        extrn '__imp_GetAuditedPermissionsFromAclW' as GetAuditedPermissionsFromAclW:qword
        extrn '__imp_GetCurrentHwProfileA' as GetCurrentHwProfileA:qword
        extrn '__imp_GetCurrentHwProfileW' as GetCurrentHwProfileW:qword
        extrn '__imp_GetEffectiveRightsFromAclA' as GetEffectiveRightsFromAclA:qword
        extrn '__imp_GetEffectiveRightsFromAclW' as GetEffectiveRightsFromAclW:qword
        extrn '__imp_GetExplicitEntriesFromAclA' as GetExplicitEntriesFromAclA:qword
        extrn '__imp_GetExplicitEntriesFromAclW' as GetExplicitEntriesFromAclW:qword
        extrn '__imp_GetMultipleTrusteeA' as GetMultipleTrusteeA:qword
        extrn '__imp_GetMultipleTrusteeOperationA' as GetMultipleTrusteeOperationA:qword
        extrn '__imp_GetMultipleTrusteeOperationW' as GetMultipleTrusteeOperationW:qword
        extrn '__imp_GetMultipleTrusteeW' as GetMultipleTrusteeW:qword
        extrn '__imp_GetNamedSecurityInfoA' as GetNamedSecurityInfoA:qword
        extrn '__imp_GetNamedSecurityInfoExA' as GetNamedSecurityInfoExA:qword
        extrn '__imp_GetNamedSecurityInfoExW' as GetNamedSecurityInfoExW:qword
        extrn '__imp_GetNamedSecurityInfoW' as GetNamedSecurityInfoW:qword
        extrn '__imp_GetOverlappedAccessResults' as GetOverlappedAccessResults:qword
        extrn '__imp_GetSecurityInfo' as GetSecurityInfo:qword
        extrn '__imp_GetSecurityInfoExA' as GetSecurityInfoExA:qword
        extrn '__imp_GetSecurityInfoExW' as GetSecurityInfoExW:qword
        extrn '__imp_GetTrusteeNameA' as GetTrusteeNameA:qword
        extrn '__imp_GetTrusteeNameW' as GetTrusteeNameW:qword
        extrn '__imp_GetTrusteeTypeA' as GetTrusteeTypeA:qword
        extrn '__imp_GetTrusteeTypeW' as GetTrusteeTypeW:qword
        extrn '__imp_LookupSecurityDescriptorPartsA' as LookupSecurityDescriptorPartsA:qword
        extrn '__imp_LookupSecurityDescriptorPartsW' as LookupSecurityDescriptorPartsW:qword
        extrn '__imp_ObjectDeleteAuditAlarmA' as ObjectDeleteAuditAlarmA:qword
        extrn '__imp_ObjectDeleteAuditAlarmW' as ObjectDeleteAuditAlarmW:qword
        extrn '__imp_SetEntriesInAccessListA' as SetEntriesInAccessListA:qword
        extrn '__imp_SetEntriesInAccessListW' as SetEntriesInAccessListW:qword
        extrn '__imp_SetEntriesInAclA' as SetEntriesInAclA:qword
        extrn '__imp_SetEntriesInAclW' as SetEntriesInAclW:qword
        extrn '__imp_SetEntriesInAuditListA' as SetEntriesInAuditListA:qword
        extrn '__imp_SetEntriesInAuditListW' as SetEntriesInAuditListW:qword
        extrn '__imp_SetNamedSecurityInfoA' as SetNamedSecurityInfoA:qword
        extrn '__imp_SetNamedSecurityInfoExA' as SetNamedSecurityInfoExA:qword
        extrn '__imp_SetNamedSecurityInfoExW' as SetNamedSecurityInfoExW:qword
        extrn '__imp_SetNamedSecurityInfoW' as SetNamedSecurityInfoW:qword
        extrn '__imp_SetSecurityInfo' as SetSecurityInfo:qword
        extrn '__imp_SetSecurityInfoExA' as SetSecurityInfoExA:qword
        extrn '__imp_SetSecurityInfoExW' as SetSecurityInfoExW:qword
        extrn '__imp_TrusteeAccessToObjectA' as TrusteeAccessToObjectA:qword
        extrn '__imp_TrusteeAccessToObjectW' as TrusteeAccessToObjectW:qword
        api BuildExplicitAccessWithName,\
            BuildSecurityDescriptor,\
            BuildTrusteeWithName,\
            BuildTrusteeWithSid,\
            ConvertAccessToSecurityDescriptor,\
            ConvertSecurityDescriptorToAccess,\
            ConvertSecurityDescriptorToAccessNamed,\
            CryptEnumProviders,\
            CryptEnumProviderTypes,\
            CryptGetDefaultProvider,\
            GetAccessPermissionsForObject,\
            GetAuditedPermissionsFromAcl,\
            GetCurrentHwProfile,\
            GetEffectiveRightsFromAcl,\
            GetExplicitEntriesFromAcl,\
            GetMultipleTrustee,\
            GetMultipleTrusteeOperation,\
            GetNamedSecurityInfo,\
            GetNamedSecurityInfoEx,\
            GetSecurityInfoEx,\
            GetTrusteeName,\
            GetTrusteeType,\
            LookupSecurityDescriptorParts,\
            ObjectDeleteAuditAlarm,\
            SetEntriesInAccessList,\
            SetEntriesInAcl,\
            SetEntriesInAuditList,\
            SetNamedSecurityInfo,\
            SetNamedSecurityInfoEx,\
            SetSecurityInfoEx,\
            TrusteeAccessToObject
    end if

    if (NTDDI_VERSION >= NTDDI_WINNT4)
        extrn '__imp_CreateProcessAsUserA' as CreateProcessAsUserA:qword
        extrn '__imp_CreateProcessAsUserW' as CreateProcessAsUserW:qword
        extrn '__imp_ElfBackupEventLogFileA' as ElfBackupEventLogFileA:qword
        extrn '__imp_ElfBackupEventLogFileW' as ElfBackupEventLogFileW:qword
        extrn '__imp_ElfChangeNotify' as ElfChangeNotify:qword
        extrn '__imp_ElfClearEventLogFileA' as ElfClearEventLogFileA:qword
        extrn '__imp_ElfClearEventLogFileW' as ElfClearEventLogFileW:qword
        extrn '__imp_ElfCloseEventLog' as ElfCloseEventLog:qword
        extrn '__imp_ElfDeregisterEventSource' as ElfDeregisterEventSource:qword
        extrn '__imp_ElfNumberOfRecords' as ElfNumberOfRecords:qword
        extrn '__imp_ElfOldestRecord' as ElfOldestRecord:qword
        extrn '__imp_ElfOpenBackupEventLogA' as ElfOpenBackupEventLogA:qword
        extrn '__imp_ElfOpenBackupEventLogW' as ElfOpenBackupEventLogW:qword
        extrn '__imp_ElfOpenEventLogA' as ElfOpenEventLogA:qword
        extrn '__imp_ElfOpenEventLogW' as ElfOpenEventLogW:qword
        extrn '__imp_ElfReadEventLogA' as ElfReadEventLogA:qword
        extrn '__imp_ElfReadEventLogW' as ElfReadEventLogW:qword
        extrn '__imp_ElfRegisterEventSourceA' as ElfRegisterEventSourceA:qword
        extrn '__imp_ElfRegisterEventSourceW' as ElfRegisterEventSourceW:qword
        extrn '__imp_ElfReportEventA' as ElfReportEventA:qword
        extrn '__imp_ElfReportEventW' as ElfReportEventW:qword
        extrn '__imp_EnumServiceGroupW' as EnumServiceGroupW:qword
        extrn '__imp_EnumServicesStatusExA' as EnumServicesStatusExA:qword
        extrn '__imp_EnumServicesStatusExW' as EnumServicesStatusExW:qword
        extrn '__imp_IsTokenUntrusted' as IsTokenUntrusted:qword
        extrn '__imp_LsaAddAccountRights' as LsaAddAccountRights:qword
        extrn '__imp_LsaAddPrivilegesToAccount' as LsaAddPrivilegesToAccount:qword
        extrn '__imp_LsaClearAuditLog' as LsaClearAuditLog:qword
        extrn '__imp_LsaClose' as LsaClose:qword
        extrn '__imp_LsaCreateAccount' as LsaCreateAccount:qword
        extrn '__imp_LsaCreateSecret' as LsaCreateSecret:qword
        extrn '__imp_LsaCreateTrustedDomain' as LsaCreateTrustedDomain:qword
        extrn '__imp_LsaDelete' as LsaDelete:qword
        extrn '__imp_LsaDeleteTrustedDomain' as LsaDeleteTrustedDomain:qword
        extrn '__imp_LsaEnumerateAccountRights' as LsaEnumerateAccountRights:qword
        extrn '__imp_LsaEnumerateAccounts' as LsaEnumerateAccounts:qword
        extrn '__imp_LsaEnumerateAccountsWithUserRight' as LsaEnumerateAccountsWithUserRight:qword
        extrn '__imp_LsaEnumeratePrivileges' as LsaEnumeratePrivileges:qword
        extrn '__imp_LsaEnumeratePrivilegesOfAccount' as LsaEnumeratePrivilegesOfAccount:qword
        extrn '__imp_LsaEnumerateTrustedDomains' as LsaEnumerateTrustedDomains:qword
        extrn '__imp_LsaFreeMemory' as LsaFreeMemory:qword
        extrn '__imp_LsaGetQuotasForAccount' as LsaGetQuotasForAccount:qword
        extrn '__imp_LsaGetRemoteUserName' as LsaGetRemoteUserName:qword
        extrn '__imp_LsaGetSystemAccessAccount' as LsaGetSystemAccessAccount:qword
        extrn '__imp_LsaGetUserName' as LsaGetUserName:qword
        extrn '__imp_LsaLookupNames' as LsaLookupNames:qword
        extrn '__imp_LsaLookupPrivilegeDisplayName' as LsaLookupPrivilegeDisplayName:qword
        extrn '__imp_LsaLookupPrivilegeName' as LsaLookupPrivilegeName:qword
        extrn '__imp_LsaLookupPrivilegeValue' as LsaLookupPrivilegeValue:qword
        extrn '__imp_LsaLookupSids' as LsaLookupSids:qword
        extrn '__imp_LsaNtStatusToWinError' as LsaNtStatusToWinError:qword
        extrn '__imp_LsaOpenAccount' as LsaOpenAccount:qword
        extrn '__imp_LsaOpenPolicy' as LsaOpenPolicy:qword
        extrn '__imp_LsaOpenSecret' as LsaOpenSecret:qword
        extrn '__imp_LsaOpenTrustedDomain' as LsaOpenTrustedDomain:qword
        extrn '__imp_LsaOpenTrustedDomainByName' as LsaOpenTrustedDomainByName:qword
        extrn '__imp_LsaQueryInformationPolicy' as LsaQueryInformationPolicy:qword
        extrn '__imp_LsaQuerySecret' as LsaQuerySecret:qword
        extrn '__imp_LsaQuerySecurityObject' as LsaQuerySecurityObject:qword
        extrn '__imp_LsaQueryTrustedDomainInfo' as LsaQueryTrustedDomainInfo:qword
        extrn '__imp_LsaRemoveAccountRights' as LsaRemoveAccountRights:qword
        extrn '__imp_LsaRemovePrivilegesFromAccount' as LsaRemovePrivilegesFromAccount:qword
        extrn '__imp_LsaRetrievePrivateData' as LsaRetrievePrivateData:qword
        extrn '__imp_LsaSetInformationPolicy' as LsaSetInformationPolicy:qword
        extrn '__imp_LsaSetInformationTrustedDomain' as LsaSetInformationTrustedDomain:qword
        extrn '__imp_LsaSetQuotasForAccount' as LsaSetQuotasForAccount:qword
        extrn '__imp_LsaSetSecret' as LsaSetSecret:qword
        extrn '__imp_LsaSetSecurityObject' as LsaSetSecurityObject:qword
        extrn '__imp_LsaSetSystemAccessAccount' as LsaSetSystemAccessAccount:qword
        extrn '__imp_LsaSetTrustedDomainInformation' as LsaSetTrustedDomainInformation:qword
        extrn '__imp_LsaStorePrivateData' as LsaStorePrivateData:qword
        extrn '__imp_OpenProcessToken' as OpenProcessToken:qword
        extrn '__imp_OpenThreadToken' as OpenThreadToken:qword
        api CreateProcessAsUser,\
            ElfBackupEventLogFile,\
            ElfClearEventLogFile,\
            ElfOpenBackupEventLog,\
            ElfOpenEventLog,\
            ElfReadEventLog,\
            ElfRegisterEventSource,\
            ElfReportEvent,\
            EnumServicesStatusEx
    end if

    if (NTDDI_VERSION >= NTDDI_WIN2K)
        extrn '__imp_AccessCheckByType' as AccessCheckByType:qword
        extrn '__imp_AccessCheckByTypeAndAuditAlarmA' as AccessCheckByTypeAndAuditAlarmA:qword
        extrn '__imp_AccessCheckByTypeAndAuditAlarmW' as AccessCheckByTypeAndAuditAlarmW:qword
        extrn '__imp_AccessCheckByTypeResultList' as AccessCheckByTypeResultList:qword
        extrn '__imp_AccessCheckByTypeResultListAndAuditAlarmA' as AccessCheckByTypeResultListAndAuditAlarmA:qword
        extrn '__imp_AccessCheckByTypeResultListAndAuditAlarmW' as AccessCheckByTypeResultListAndAuditAlarmW:qword
        extrn '__imp_AccessCheckByTypeResultListAndAuditAlarmByHandleA' as AccessCheckByTypeResultListAndAuditAlarmByHandleA:qword
        extrn '__imp_AccessCheckByTypeResultListAndAuditAlarmByHandleW' as AccessCheckByTypeResultListAndAuditAlarmByHandleW:qword
        extrn '__imp_AddAccessAllowedAceEx' as AddAccessAllowedAceEx:qword
        extrn '__imp_AddAccessAllowedObjectAce' as AddAccessAllowedObjectAce:qword
        extrn '__imp_AddAccessDeniedAceEx' as AddAccessDeniedAceEx:qword
        extrn '__imp_AddAccessDeniedObjectAce' as AddAccessDeniedObjectAce:qword
        extrn '__imp_AddAuditAccessAceEx' as AddAuditAccessAceEx:qword
        extrn '__imp_AddAuditAccessObjectAce' as AddAuditAccessObjectAce:qword
        extrn '__imp_AddUsersToEncryptedFile' as AddUsersToEncryptedFile:qword
        extrn '__imp_BuildTrusteeWithObjectsAndNameA' as BuildTrusteeWithObjectsAndNameA:qword
        extrn '__imp_BuildTrusteeWithObjectsAndNameW' as BuildTrusteeWithObjectsAndNameW:qword
        extrn '__imp_BuildTrusteeWithObjectsAndSidA' as BuildTrusteeWithObjectsAndSidA:qword
        extrn '__imp_BuildTrusteeWithObjectsAndSidW' as BuildTrusteeWithObjectsAndSidW:qword
        extrn '__imp_CheckTokenMembership' as CheckTokenMembership:qword
        extrn '__imp_CloseEncryptedFileRaw' as CloseEncryptedFileRaw:qword
        extrn '__imp_CloseTrace' as CloseTrace:qword
        extrn '__imp_CommandLineFromMsiDescriptor' as CommandLineFromMsiDescriptor:qword
        extrn '__imp_ControlTraceA' as ControlTraceA:qword
        extrn '__imp_ControlTraceW' as ControlTraceW:qword
        extrn '__imp_ConvertSDToStringSDRootDomainA' as ConvertSDToStringSDRootDomainA:qword
        extrn '__imp_ConvertSDToStringSDRootDomainW' as ConvertSDToStringSDRootDomainW:qword
        extrn '__imp_ConvertSecurityDescriptorToStringSecurityDescriptorA' as ConvertSecurityDescriptorToStringSecurityDescriptorA:qword
        extrn '__imp_ConvertSecurityDescriptorToStringSecurityDescriptorW' as ConvertSecurityDescriptorToStringSecurityDescriptorW:qword
        extrn '__imp_ConvertSidToStringSidA' as ConvertSidToStringSidA:qword
        extrn '__imp_ConvertSidToStringSidW' as ConvertSidToStringSidW:qword
        extrn '__imp_ConvertStringSDToSDRootDomainA' as ConvertStringSDToSDRootDomainA:qword
        extrn '__imp_ConvertStringSDToSDRootDomainW' as ConvertStringSDToSDRootDomainW:qword
        extrn '__imp_ConvertStringSecurityDescriptorToSecurityDescriptorA' as ConvertStringSecurityDescriptorToSecurityDescriptorA:qword
        extrn '__imp_ConvertStringSecurityDescriptorToSecurityDescriptorW' as ConvertStringSecurityDescriptorToSecurityDescriptorW:qword
        extrn '__imp_ConvertStringSidToSidA' as ConvertStringSidToSidA:qword
        extrn '__imp_ConvertStringSidToSidW' as ConvertStringSidToSidW:qword
        extrn '__imp_ConvertToAutoInheritPrivateObjectSecurity' as ConvertToAutoInheritPrivateObjectSecurity:qword
        extrn '__imp_CreatePrivateObjectSecurityEx' as CreatePrivateObjectSecurityEx:qword
        extrn '__imp_CreateProcessWithLogonW' as CreateProcessWithLogonW:qword
        extrn '__imp_CreateRestrictedToken' as CreateRestrictedToken:qword
        extrn '__imp_CreateTraceInstanceId' as CreateTraceInstanceId:qword
        extrn '__imp_CreateWellKnownSid' as CreateWellKnownSid:qword
        extrn '__imp_EnableTrace' as EnableTrace:qword
        extrn '__imp_EncryptFileA' as EncryptFileA:qword
        extrn '__imp_EncryptFileW' as EncryptFileW:qword
        extrn '__imp_EncryptionDisable' as EncryptionDisable:qword
        extrn '__imp_EqualDomainSid' as EqualDomainSid:qword
        extrn '__imp_FileEncryptionStatusA' as FileEncryptionStatusA:qword
        extrn '__imp_FileEncryptionStatusW' as FileEncryptionStatusW:qword
        extrn '__imp_FreeEncryptionCertificateHashList' as FreeEncryptionCertificateHashList:qword
        extrn '__imp_GetEventLogInformation' as GetEventLogInformation:qword
        extrn '__imp_GetLocalManagedApplications' as GetLocalManagedApplications:qword
        extrn '__imp_GetManagedApplications' as GetManagedApplications:qword
        extrn '__imp_ImpersonateAnonymousToken' as ImpersonateAnonymousToken:qword
        extrn '__imp_InitiateSystemShutdownExA' as InitiateSystemShutdownExA:qword
        extrn '__imp_InitiateSystemShutdownExW' as InitiateSystemShutdownExW:qword
        extrn '__imp_InstallApplication' as InstallApplication:qword
        extrn '__imp_IsTokenRestricted' as IsTokenRestricted:qword
        extrn '__imp_LsaCreateTrustedDomainEx' as LsaCreateTrustedDomainEx:qword
        extrn '__imp_LsaEnumerateTrustedDomainsEx' as LsaEnumerateTrustedDomainsEx:qword
        extrn '__imp_LsaOpenPolicySce' as LsaOpenPolicySce:qword
        extrn '__imp_LsaQueryDomainInformationPolicy' as LsaQueryDomainInformationPolicy:qword
        extrn '__imp_LsaQueryInfoTrustedDomain' as LsaQueryInfoTrustedDomain:qword
        extrn '__imp_LsaQueryTrustedDomainInfoByName' as LsaQueryTrustedDomainInfoByName:qword
        extrn '__imp_LsaSetDomainInformationPolicy' as LsaSetDomainInformationPolicy:qword
        extrn '__imp_LsaSetTrustedDomainInfoByName' as LsaSetTrustedDomainInfoByName:qword
        extrn '__imp_MakeAbsoluteSD2' as MakeAbsoluteSD2:qword
        extrn '__imp_OpenEncryptedFileRawA' as OpenEncryptedFileRawA:qword
        extrn '__imp_OpenEncryptedFileRawW' as OpenEncryptedFileRawW:qword
        extrn '__imp_OpenTraceA' as OpenTraceA:qword
        extrn '__imp_OpenTraceW' as OpenTraceW:qword
        extrn '__imp_QueryAllTracesA' as QueryAllTracesA:qword
        extrn '__imp_QueryAllTracesW' as QueryAllTracesW:qword
        extrn '__imp_QueryRecoveryAgentsOnEncryptedFile' as QueryRecoveryAgentsOnEncryptedFile:qword
        extrn '__imp_QueryServiceConfig2A' as QueryServiceConfig2A:qword
        extrn '__imp_QueryServiceConfig2W' as QueryServiceConfig2W:qword
        extrn '__imp_QueryServiceStatusEx' as QueryServiceStatusEx:qword
        extrn '__imp_QueryUsersOnEncryptedFile' as QueryUsersOnEncryptedFile:qword
        extrn '__imp_ReadEncryptedFileRaw' as ReadEncryptedFileRaw:qword
        extrn '__imp_RegDisablePredefinedCache' as RegDisablePredefinedCache:qword
        extrn '__imp_RegOpenCurrentUser' as RegOpenCurrentUser:qword
        extrn '__imp_RegOpenUserClassesRoot' as RegOpenUserClassesRoot:qword
        extrn '__imp_RegOverridePredefKey' as RegOverridePredefKey:qword
        extrn '__imp_RegisterServiceCtrlHandlerExA' as RegisterServiceCtrlHandlerExA:qword
        extrn '__imp_RegisterServiceCtrlHandlerExW' as RegisterServiceCtrlHandlerExW:qword
        extrn '__imp_RegisterTraceGuidsA' as RegisterTraceGuidsA:qword
        extrn '__imp_RegisterTraceGuidsW' as RegisterTraceGuidsW:qword
        extrn '__imp_RemoveUsersFromEncryptedFile' as RemoveUsersFromEncryptedFile:qword
        extrn '__imp_RemoveTraceCallback' as RemoveTraceCallback:qword
        extrn '__imp_SetPrivateObjectSecurityEx' as SetPrivateObjectSecurityEx:qword
        extrn '__imp_SetSecurityDescriptorControl' as SetSecurityDescriptorControl:qword
        extrn '__imp_SetSecurityDescriptorRMControl' as SetSecurityDescriptorRMControl:qword
        extrn '__imp_SetTraceCallback' as SetTraceCallback:qword
        extrn '__imp_SetUserFileEncryptionKey' as SetUserFileEncryptionKey:qword
        extrn '__imp_StartTraceA' as StartTraceA:qword
        extrn '__imp_StartTraceW' as StartTraceW:qword
        extrn '__imp_TraceEvent' as TraceEvent:qword
        extrn '__imp_TraceEventInstance' as TraceEventInstance:qword
        extrn '__imp_UninstallApplication' as UninstallApplication:qword
        extrn '__imp_UnregisterTraceGuids' as UnregisterTraceGuids:qword
        extrn '__imp_WmiCloseBlock' as WmiCloseBlock:qword
        extrn '__imp_WmiEnumerateGuids' as WmiEnumerateGuids:qword
        extrn '__imp_WmiDevInstToInstanceNameA' as WmiDevInstToInstanceNameA:qword
        extrn '__imp_WmiDevInstToInstanceNameW' as WmiDevInstToInstanceNameW:qword
        extrn '__imp_WmiExecuteMethodA' as WmiExecuteMethodA:qword
        extrn '__imp_WmiExecuteMethodW' as WmiExecuteMethodW:qword
        extrn '__imp_WmiFileHandleToInstanceNameA' as WmiFileHandleToInstanceNameA:qword
        extrn '__imp_WmiFileHandleToInstanceNameW' as WmiFileHandleToInstanceNameW:qword
        extrn '__imp_WmiFreeBuffer' as WmiFreeBuffer:qword
        extrn '__imp_WmiMofEnumerateResourcesA' as WmiMofEnumerateResourcesA:qword
        extrn '__imp_WmiMofEnumerateResourcesW' as WmiMofEnumerateResourcesW:qword
        extrn '__imp_WmiNotificationRegistrationA' as WmiNotificationRegistrationA:qword
        extrn '__imp_WmiNotificationRegistrationW' as WmiNotificationRegistrationW:qword
        extrn '__imp_WmiOpenBlock' as WmiOpenBlock:qword
        extrn '__imp_WmiQueryAllDataA' as WmiQueryAllDataA:qword
        extrn '__imp_WmiQueryAllDataW' as WmiQueryAllDataW:qword
        extrn '__imp_WmiQueryGuidInformation' as WmiQueryGuidInformation:qword
        extrn '__imp_WmiQuerySingleInstanceA' as WmiQuerySingleInstanceA:qword
        extrn '__imp_WmiQuerySingleInstanceW' as WmiQuerySingleInstanceW:qword
        extrn '__imp_WmiSetSingleInstanceA' as WmiSetSingleInstanceA:qword
        extrn '__imp_WmiSetSingleInstanceW' as WmiSetSingleInstanceW:qword
        extrn '__imp_WmiSetSingleItemA' as WmiSetSingleItemA:qword
        extrn '__imp_WmiSetSingleItemW' as WmiSetSingleItemW:qword
        extrn '__imp_WriteEncryptedFileRaw' as WriteEncryptedFileRaw:qword
        api AccessCheckByTypeAndAuditAlarm,\
            AccessCheckByTypeResultListAndAuditAlarm,\
            AccessCheckByTypeResultListAndAuditAlarmByHandle,\
            BuildTrusteeWithObjectsAndName,\
            BuildTrusteeWithObjectsAndSid,\
            ControlTrace,\
            ConvertSDToStringSDRootDomain,\
            ConvertSecurityDescriptorToStringSecurityDescriptor,\
            ConvertSidToStringSid,\
            ConvertStringSDToSDRootDomain,\
            ConvertStringSecurityDescriptorToSecurityDescriptor,\
            ConvertStringSidToSid,\
            EncryptFile,\
            FileEncryptionStatus,\
            InitiateSystemShutdownEx,\
            OpenEncryptedFileRaw,\
            OpenTrace,\
            QueryAllTraces,\
            QueryServiceConfig2,\
            RegisterServiceCtrlHandlerEx,\
            RegisterTraceGuids,\
            StartTrace,\
            WmiDevInstToInstanceName,\
            WmiExecuteMethod,\
            WmiFileHandleToInstanceName,\
            WmiMofEnumerateResources,\
            WmiNotificationRegistration,\
            WmiQueryAllData,\
            WmiQuerySingleInstance,\
            WmiSetSingleInstance,\
            WmiSetSingleItem
    end if

    if (NTDDI_VERSION >= NTDDI_WINXP)
        extrn '__imp_A_SHAFinal' as A_SHAFinal:qword
        extrn '__imp_A_SHAInit' as A_SHAInit:qword
        extrn '__imp_A_SHAUpdate' as A_SHAUpdate:qword
        extrn '__imp_ChangeServiceConfig2A' as ChangeServiceConfig2A:qword
        extrn '__imp_ChangeServiceConfig2W' as ChangeServiceConfig2W:qword
        extrn '__imp_ConvertStringSDToSDDomainA' as ConvertStringSDToSDDomainA:qword
        extrn '__imp_ConvertStringSDToSDDomainW' as ConvertStringSDToSDDomainW:qword
        extrn '__imp_CreatePrivateObjectSecurityWithMultipleInheritance' as CreatePrivateObjectSecurityWithMultipleInheritance:qword
        extrn '__imp_CredDeleteA' as CredDeleteA:qword
        extrn '__imp_CredDeleteW' as CredDeleteW:qword
        extrn '__imp_CredEnumerateA' as CredEnumerateA:qword
        extrn '__imp_CredEnumerateW' as CredEnumerateW:qword
        extrn '__imp_CredFree' as CredFree:qword
        extrn '__imp_CredGetSessionTypes' as CredGetSessionTypes:qword
        extrn '__imp_CredGetTargetInfoA' as CredGetTargetInfoA:qword
        extrn '__imp_CredGetTargetInfoW' as CredGetTargetInfoW:qword
        extrn '__imp_CredIsMarshaledCredentialA' as CredIsMarshaledCredentialA:qword
        extrn '__imp_CredIsMarshaledCredentialW' as CredIsMarshaledCredentialW:qword
        extrn '__imp_CredMarshalCredentialA' as CredMarshalCredentialA:qword
        extrn '__imp_CredMarshalCredentialW' as CredMarshalCredentialW:qword
        extrn '__imp_CredReadA' as CredReadA:qword
        extrn '__imp_CredReadW' as CredReadW:qword
        extrn '__imp_CredReadDomainCredentialsA' as CredReadDomainCredentialsA:qword
        extrn '__imp_CredReadDomainCredentialsW' as CredReadDomainCredentialsW:qword
        extrn '__imp_CredRenameA' as CredRenameA:qword
        extrn '__imp_CredRenameW' as CredRenameW:qword
        extrn '__imp_CredUnmarshalCredentialA' as CredUnmarshalCredentialA:qword
        extrn '__imp_CredUnmarshalCredentialW' as CredUnmarshalCredentialW:qword
        extrn '__imp_CredWriteA' as CredWriteA:qword
        extrn '__imp_CredWriteW' as CredWriteW:qword
        extrn '__imp_CredWriteDomainCredentialsA' as CredWriteDomainCredentialsA:qword
        extrn '__imp_CredWriteDomainCredentialsW' as CredWriteDomainCredentialsW:qword
        extrn '__imp_DecryptFileA' as DecryptFileA:qword
        extrn '__imp_DecryptFileW' as DecryptFileW:qword
        extrn '__imp_DuplicateEncryptionInfoFile' as DuplicateEncryptionInfoFile:qword
        extrn '__imp_EnumerateTraceGuids' as EnumerateTraceGuids:qword
        extrn '__imp_FlushTraceA' as FlushTraceA:qword
        extrn '__imp_FlushTraceW' as FlushTraceW:qword
        extrn '__imp_FreeInheritedFromArray' as FreeInheritedFromArray:qword
        extrn '__imp_GetInheritanceSourceA' as GetInheritanceSourceA:qword
        extrn '__imp_GetInheritanceSourceW' as GetInheritanceSourceW:qword
        extrn '__imp_GetLocalManagedApplicationData' as GetLocalManagedApplicationData:qword
        extrn '__imp_GetManagedApplicationCategories' as GetManagedApplicationCategories:qword
        extrn '__imp_GetSecurityDescriptorRMControl' as GetSecurityDescriptorRMControl:qword
        extrn '__imp_GetTraceEnableFlags' as GetTraceEnableFlags:qword
        extrn '__imp_GetTraceEnableLevel' as GetTraceEnableLevel:qword
        extrn '__imp_GetTraceLoggerHandle' as GetTraceLoggerHandle:qword
        extrn '__imp_GetTrusteeFormA' as GetTrusteeFormA:qword
        extrn '__imp_GetTrusteeFormW' as GetTrusteeFormW:qword
        extrn '__imp_GetWindowsAccountDomainSid' as GetWindowsAccountDomainSid:qword
        extrn '__imp_IsWellKnownSid' as IsWellKnownSid:qword
        extrn '__imp_LogonUserExA' as LogonUserExA:qword
        extrn '__imp_LogonUserExExW' as LogonUserExExW:qword
        extrn '__imp_LogonUserExW' as LogonUserExW:qword
        extrn '__imp_LsaLookupNames2' as LsaLookupNames2:qword
        extrn '__imp_LsaQueryForestTrustInformation' as LsaQueryForestTrustInformation:qword
        extrn '__imp_LsaSetForestTrustInformation' as LsaSetForestTrustInformation:qword
        extrn '__imp_MSChapSrvChangePassword' as MSChapSrvChangePassword:qword
        extrn '__imp_MSChapSrvChangePassword2' as MSChapSrvChangePassword2:qword
        extrn '__imp_ProcessTrace' as ProcessTrace:qword
        extrn '__imp_QueryTraceA' as QueryTraceA:qword
        extrn '__imp_QueryTraceW' as QueryTraceW:qword
        extrn '__imp_RegDisablePredefinedCacheEx' as RegDisablePredefinedCacheEx:qword
        extrn '__imp_RegSaveKeyExA' as RegSaveKeyExA:qword
        extrn '__imp_RegSaveKeyExW' as RegSaveKeyExW:qword
        extrn '__imp_SaferCloseLevel' as SaferCloseLevel:qword
        extrn '__imp_SaferComputeTokenFromLevel' as SaferComputeTokenFromLevel:qword
        extrn '__imp_SaferCreateLevel' as SaferCreateLevel:qword
        extrn '__imp_SaferGetLevelInformation' as SaferGetLevelInformation:qword
        extrn '__imp_SaferGetPolicyInformation' as SaferGetPolicyInformation:qword
        extrn '__imp_SaferIdentifyLevel' as SaferIdentifyLevel:qword
        extrn '__imp_SaferRecordEventLogEntry' as SaferRecordEventLogEntry:qword
        extrn '__imp_SaferSetLevelInformation' as SaferSetLevelInformation:qword
        extrn '__imp_SaferSetPolicyInformation' as SaferSetPolicyInformation:qword
        extrn '__imp_SaferiIsExecutableFileType' as SaferiIsExecutableFileType:qword
        extrn '__imp_SaferiSearchMatchingHashRules' as SaferiSearchMatchingHashRules:qword
        extrn '__imp_SetEncryptedFileMetadata' as SetEncryptedFileMetadata:qword
        extrn '__imp_StopTraceA' as StopTraceA:qword
        extrn '__imp_StopTraceW' as StopTraceW:qword
        extrn '__imp_TraceMessage' as TraceMessage:qword
        extrn '__imp_TraceMessageVa' as TraceMessageVa:qword
        extrn '__imp_TreeResetNamedSecurityInfoA' as TreeResetNamedSecurityInfoA:qword
        extrn '__imp_TreeResetNamedSecurityInfoW' as TreeResetNamedSecurityInfoW:qword
        extrn '__imp_UpdateTraceA' as UpdateTraceA:qword
        extrn '__imp_UpdateTraceW' as UpdateTraceW:qword
        extrn '__imp_WmiQueryAllDataMultipleA' as WmiQueryAllDataMultipleA:qword
        extrn '__imp_WmiQueryAllDataMultipleW' as WmiQueryAllDataMultipleW:qword
        extrn '__imp_WmiQuerySingleInstanceMultipleA' as WmiQuerySingleInstanceMultipleA:qword
        extrn '__imp_WmiQuerySingleInstanceMultipleW' as WmiQuerySingleInstanceMultipleW:qword
        extrn '__imp_WmiReceiveNotificationsA' as WmiReceiveNotificationsA:qword
        extrn '__imp_WmiReceiveNotificationsW' as WmiReceiveNotificationsW:qword
        api ChangeServiceConfig2,\
            ConvertStringSDToSDDomain,\
            CredDelete,\
            CredEnumerate,\
            CredGetTargetInfo,\
            CredIsMarshaledCredential,\
            CredMarshalCredential,\
            CredRead,\
            CredReadDomainCredentials,\
            CredRename,\
            CredUnmarshalCredential,\
            CredWrite,\
            CredWriteDomainCredentials,\
            DecryptFile,\
            FlushTrace,\
            GetInheritanceSource,\
            GetTrusteeForm,\
            LogonUserEx,\
            QueryTrace,\
            RegSaveKeyEx,\
            StopTrace,\
            TreeResetNamedSecurityInfo,\
            UpdateTrace,\
            WmiQueryAllDataMultiple,\
            WmiQuerySingleInstanceMultiple,\
            WmiReceiveNotifications
    end if

    if (NTDDI_VERSION >= NTDDI_WS03)
        extrn '__imp_CreateProcessWithTokenW' as CreateProcessWithTokenW:qword
    end if

    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_AddMandatoryAce' as AddMandatoryAce:qword
        extrn '__imp_AuditComputeEffectivePolicyBySid' as AuditComputeEffectivePolicyBySid:qword
        extrn '__imp_AuditComputeEffectivePolicyByToken' as AuditComputeEffectivePolicyByToken:qword
        extrn '__imp_AuditEnumerateCategories' as AuditEnumerateCategories:qword
        extrn '__imp_AuditEnumeratePerUserPolicy' as AuditEnumeratePerUserPolicy:qword
        extrn '__imp_AuditEnumerateSubCategories' as AuditEnumerateSubCategories:qword
        extrn '__imp_AuditFree' as AuditFree:qword
        extrn '__imp_AuditLookupCategoryGuidFromCategoryId' as AuditLookupCategoryGuidFromCategoryId:qword
        extrn '__imp_AuditLookupCategoryIdFromCategoryGuid' as AuditLookupCategoryIdFromCategoryGuid:qword
        extrn '__imp_AuditLookupCategoryNameA' as AuditLookupCategoryNameA:qword
        extrn '__imp_AuditLookupCategoryNameW' as AuditLookupCategoryNameW:qword
        extrn '__imp_AuditLookupSubCategoryNameA' as AuditLookupSubCategoryNameA:qword
        extrn '__imp_AuditLookupSubCategoryNameW' as AuditLookupSubCategoryNameW:qword
        extrn '__imp_AuditQueryPerUserPolicy' as AuditQueryPerUserPolicy:qword
        extrn '__imp_AuditQuerySecurity' as AuditQuerySecurity:qword
        extrn '__imp_AuditQuerySystemPolicy' as AuditQuerySystemPolicy:qword
        extrn '__imp_AuditSetPerUserPolicy' as AuditSetPerUserPolicy:qword
        extrn '__imp_AuditSetSecurity' as AuditSetSecurity:qword
        extrn '__imp_AuditSetSystemPolicy' as AuditSetSystemPolicy:qword
        extrn '__imp_CloseThreadWaitChainSession' as CloseThreadWaitChainSession:qword
        extrn '__imp_ControlServiceExA' as ControlServiceExA:qword
        extrn '__imp_ControlServiceExW' as ControlServiceExW:qword
        extrn '__imp_CredFindBestCredentialA' as CredFindBestCredentialA:qword
        extrn '__imp_CredFindBestCredentialW' as CredFindBestCredentialW:qword
        extrn '__imp_CredIsProtectedA' as CredIsProtectedA:qword
        extrn '__imp_CredIsProtectedW' as CredIsProtectedW:qword
        extrn '__imp_CredProtectA' as CredProtectA:qword
        extrn '__imp_CredProtectW' as CredProtectW:qword
        extrn '__imp_CredUnprotectA' as CredUnprotectA:qword
        extrn '__imp_CredUnprotectW' as CredUnprotectW:qword
        extrn '__imp_EnumerateTraceGuidsEx' as EnumerateTraceGuidsEx:qword
        extrn '__imp_EventAccessControl' as EventAccessControl:qword
        extrn '__imp_EventAccessQuery' as EventAccessQuery:qword
        extrn '__imp_EventAccessRemove' as EventAccessRemove:qword
        extrn '__imp_EventActivityIdControl' as EventActivityIdControl:qword
        extrn '__imp_EventEnabled' as EventEnabled:qword
        extrn '__imp_EventProviderEnabled' as EventProviderEnabled:qword
        extrn '__imp_EventRegister' as EventRegister:qword
        extrn '__imp_EventUnregister' as EventUnregister:qword
        extrn '__imp_EventWrite' as EventWrite:qword
        extrn '__imp_EventWriteString' as EventWriteString:qword
        extrn '__imp_EventWriteTransfer' as EventWriteTransfer:qword
        extrn '__imp_FlushEfsCache' as FlushEfsCache:qword
        extrn '__imp_FreeEncryptedFileMetadata' as FreeEncryptedFileMetadata:qword
        extrn '__imp_GetEncryptedFileMetadata' as GetEncryptedFileMetadata:qword
        extrn '__imp_GetThreadWaitChain' as GetThreadWaitChain:qword
        extrn '__imp_I_QueryTagInformation' as I_QueryTagInformation:qword
        extrn '__imp_InitiateShutdownA' as InitiateShutdownA:qword
        extrn '__imp_InitiateShutdownW' as InitiateShutdownW:qword
        extrn '__imp_LsaManageSidNameMapping' as LsaManageSidNameMapping:qword
        extrn '__imp_NotifyServiceStatusChangeA' as NotifyServiceStatusChangeA:qword
        extrn '__imp_NotifyServiceStatusChangeW' as NotifyServiceStatusChangeW:qword
        extrn '__imp_OpenThreadWaitChainSession' as OpenThreadWaitChainSession:qword
        extrn '__imp_PerfCreateInstance' as PerfCreateInstance:qword
        extrn '__imp_PerfDecrementULongCounterValue' as PerfDecrementULongCounterValue:qword
        extrn '__imp_PerfDecrementULongLongCounterValue' as PerfDecrementULongLongCounterValue:qword
        extrn '__imp_PerfDeleteInstance' as PerfDeleteInstance:qword
        extrn '__imp_PerfIncrementULongCounterValue' as PerfIncrementULongCounterValue:qword
        extrn '__imp_PerfIncrementULongLongCounterValue' as PerfIncrementULongLongCounterValue:qword
        extrn '__imp_PerfQueryInstance' as PerfQueryInstance:qword
        extrn '__imp_PerfSetCounterRefValue' as PerfSetCounterRefValue:qword
        extrn '__imp_PerfSetCounterSetInfo' as PerfSetCounterSetInfo:qword
        extrn '__imp_PerfSetULongCounterValue' as PerfSetULongCounterValue:qword
        extrn '__imp_PerfSetULongLongCounterValue' as PerfSetULongLongCounterValue:qword
        extrn '__imp_PerfStartProvider' as PerfStartProvider:qword
        extrn '__imp_PerfStartProviderEx' as PerfStartProviderEx:qword
        extrn '__imp_PerfStopProvider' as PerfStopProvider:qword
        extrn '__imp_QuerySecurityAccessMask' as QuerySecurityAccessMask:qword
        extrn '__imp_RegConnectRegistryExA' as RegConnectRegistryExA:qword
        extrn '__imp_RegConnectRegistryExW' as RegConnectRegistryExW:qword
        extrn '__imp_RegCopyTreeA' as RegCopyTreeA:qword
        extrn '__imp_RegCopyTreeW' as RegCopyTreeW:qword
        extrn '__imp_RegCreateKeyTransactedA' as RegCreateKeyTransactedA:qword
        extrn '__imp_RegCreateKeyTransactedW' as RegCreateKeyTransactedW:qword
        extrn '__imp_RegDeleteKeyExA' as RegDeleteKeyExA:qword
        extrn '__imp_RegDeleteKeyExW' as RegDeleteKeyExW:qword
        extrn '__imp_RegDeleteKeyTransactedA' as RegDeleteKeyTransactedA:qword
        extrn '__imp_RegDeleteKeyTransactedW' as RegDeleteKeyTransactedW:qword
        extrn '__imp_RegDeleteKeyValueA' as RegDeleteKeyValueA:qword
        extrn '__imp_RegDeleteKeyValueW' as RegDeleteKeyValueW:qword
        extrn '__imp_RegDeleteTreeA' as RegDeleteTreeA:qword
        extrn '__imp_RegDeleteTreeW' as RegDeleteTreeW:qword
        extrn '__imp_RegDisableReflectionKey' as RegDisableReflectionKey:qword
        extrn '__imp_RegEnableReflectionKey' as RegEnableReflectionKey:qword
        extrn '__imp_RegGetValueA' as RegGetValueA:qword
        extrn '__imp_RegGetValueW' as RegGetValueW:qword
        extrn '__imp_RegLoadAppKeyA' as RegLoadAppKeyA:qword
        extrn '__imp_RegLoadAppKeyW' as RegLoadAppKeyW:qword
        extrn '__imp_RegLoadMUIStringA' as RegLoadMUIStringA:qword
        extrn '__imp_RegLoadMUIStringW' as RegLoadMUIStringW:qword
        extrn '__imp_RegOpenKeyTransactedA' as RegOpenKeyTransactedA:qword
        extrn '__imp_RegOpenKeyTransactedW' as RegOpenKeyTransactedW:qword
        extrn '__imp_RegQueryReflectionKey' as RegQueryReflectionKey:qword
        extrn '__imp_RegSetKeyValueA' as RegSetKeyValueA:qword
        extrn '__imp_RegSetKeyValueW' as RegSetKeyValueW:qword
        extrn '__imp_RegisterWaitChainCOMCallback' as RegisterWaitChainCOMCallback:qword
        extrn '__imp_SetSecurityAccessMask' as SetSecurityAccessMask:qword
        extrn '__imp_SetUserFileEncryptionKeyEx' as SetUserFileEncryptionKeyEx:qword
        extrn '__imp_TreeSetNamedSecurityInfoA' as TreeSetNamedSecurityInfoA:qword
        extrn '__imp_TreeSetNamedSecurityInfoW' as TreeSetNamedSecurityInfoW:qword
        api AuditLookupCategoryName,\
            AuditLookupSubCategoryName,\
            ControlServiceEx,\
            CredFindBestCredential,\
            CredIsProtected,\
            CredProtect,\
            CredUnprotect,\
            InitiateShutdown,\
            NotifyServiceStatusChange,\
            RegConnectRegistryEx,\
            RegCopyTree,\
            RegCreateKeyTransacted,\
            RegDeleteKeyEx,\
            RegDeleteKeyTransacted,\
            RegDeleteKeyValue,\
            RegDeleteTree,\
            RegGetValue,\
            RegLoadAppKey,\
            RegLoadMUIString,\
            RegOpenKeyTransacted,\
            RegSetKeyValue,\
            TreeSetNamedSecurityInfo
    end if

    if (NTDDI_VERSION >= NTDDI_WIN7)
        extrn '__imp_AddConditionalAce' as AddConditionalAce:qword
        extrn '__imp_AuditQueryGlobalSaclA' as AuditQueryGlobalSaclA:qword
        extrn '__imp_AuditQueryGlobalSaclW' as AuditQueryGlobalSaclW:qword
        extrn '__imp_AuditSetGlobalSaclA' as AuditSetGlobalSaclA:qword
        extrn '__imp_AuditSetGlobalSaclW' as AuditSetGlobalSaclW:qword
        extrn '__imp_CredReadByTokenHandle' as CredReadByTokenHandle:qword
        extrn '__imp_EnableTraceEx' as EnableTraceEx:qword
        extrn '__imp_EnableTraceEx2' as EnableTraceEx2:qword
        extrn '__imp_EventWriteEx' as EventWriteEx:qword
        extrn '__imp_TraceSetInformation' as TraceSetInformation:qword
        api AuditQueryGlobalSacl,\
            AuditSetGlobalSacl
    end if

    if (NTDDI_VERSION >= NTDDI_WIN8)
        extrn '__imp_BaseRegCloseKey' as BaseRegCloseKey:qword
        extrn '__imp_BaseRegCreateKey' as BaseRegCreateKey:qword
        extrn '__imp_BaseRegDeleteKeyEx' as BaseRegDeleteKeyEx:qword
        extrn '__imp_BaseRegDeleteValue' as BaseRegDeleteValue:qword
        extrn '__imp_BaseRegFlushKey' as BaseRegFlushKey:qword
        extrn '__imp_BaseRegGetVersion' as BaseRegGetVersion:qword
        extrn '__imp_BaseRegLoadKey' as BaseRegLoadKey:qword
        extrn '__imp_BaseRegOpenKey' as BaseRegOpenKey:qword
        extrn '__imp_BaseRegRestoreKey' as BaseRegRestoreKey:qword
        extrn '__imp_BaseRegSaveKeyEx' as BaseRegSaveKeyEx:qword
        extrn '__imp_BaseRegSetKeySecurity' as BaseRegSetKeySecurity:qword
        extrn '__imp_BaseRegSetValue' as BaseRegSetValue:qword
        extrn '__imp_BaseRegUnLoadKey' as BaseRegUnLoadKey:qword
        extrn '__imp_EnumDynamicTimeZoneInformation' as EnumDynamicTimeZoneInformation:qword
        extrn '__imp_EventSetInformation' as EventSetInformation:qword
        extrn '__imp_GetDynamicTimeZoneInformationEffectiveYears' as GetDynamicTimeZoneInformationEffectiveYears:qword
        extrn '__imp_LsaGetAppliedCAPIDs' as LsaGetAppliedCAPIDs:qword
        extrn '__imp_LsaLookupSids2' as LsaLookupSids2:qword
        extrn '__imp_LsaQueryCAPs' as LsaQueryCAPs:qword
        extrn '__imp_LsaSetCAPs' as LsaSetCAPs:qword
        extrn '__imp_OperationEnd' as OperationEnd:qword
        extrn '__imp_OperationStart' as OperationStart:qword
        extrn '__imp_QueryServiceDynamicInformation' as QueryServiceDynamicInformation:qword
        extrn '__imp_TraceQueryInformation' as TraceQueryInformation:qword
    end if

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
        ACTRL_ACCESS_ENTRY,\
        ACTRL_PROPERTY_ENTRY,\
        ACTRL_ALIST,\
        TRUSTEE_ACCESS,\
        ACTRL_ACCESS_INFO,\
        ACTRL_CONTROL_INFO,\
        ACTRL_AUDIT,\
        AbortSystemShutdown,\
        AccessCheckAndAuditAlarm,\
        BackupEventLog,\
        ChangeServiceConfig,\
	    ClearEventLog,\
	    CreateService,\
	    CryptAcquireContext,\
	    CryptSetProvider,\
	    CryptSetProviderEx,\
	    CryptSignHash,\
	    CryptVerifySignature,\
	    EnumDependentServices,\
	    EnumServicesStatus,\
	    GetFileSecurity,\
	    GetServiceDisplayName,\
	    GetServiceKeyName,\
	    GetUserName,\
	    InitiateSystemShutdown,\
	    LogonUser,\
	    LookupAccountName,\
	    LookupAccountSid,\
	    LookupPrivilegeDisplayName,\
	    LookupPrivilegeName,\
	    LookupPrivilegeValue,\
	    ObjectCloseAuditAlarm,\
	    ObjectOpenAuditAlarm,\
	    ObjectPrivilegeAuditAlarm,\
	    OpenBackupEventLog,\
	    OpenEventLog,\
	    OpenSCManager,\
	    OpenService,\
	    PrivilegedServiceAuditAlarm,\
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
	    ReportEvent,\
	    SetFileSecurity,\
	    StartService,\
	    StartServiceCtrlDispatcher
else
    extrn '__imp__AbortSystemShutdownA@4' as AbortSystemShutdownA:dword
    extrn '__imp__AbortSystemShutdownW@4' as AbortSystemShutdownW:dword
    extrn '__imp__AccessCheck@32' as AccessCheck:dword
    extrn '__imp__AccessCheckAndAuditAlarmA@44' as AccessCheckAndAuditAlarmA:dword
    extrn '__imp__AccessCheckAndAuditAlarmW@44' as AccessCheckAndAuditAlarmW:dword
    extrn '__imp__AddAccessAllowedAce@16' as AddAccessAllowedAce:dword
    extrn '__imp__AddAccessDeniedAce@16' as AddAccessDeniedAce:dword
    extrn '__imp__AddAce@20' as AddAce:dword
    extrn '__imp__AddAuditAccessAce@24' as AddAuditAccessAce:dword
    extrn '__imp__AdjustTokenGroups@24' as AdjustTokenGroups:dword
    extrn '__imp__AdjustTokenPrivileges@24' as AdjustTokenPrivileges:dword
    extrn '__imp__AllocateAndInitializeSid@44' as AllocateAndInitializeSid:dword
    extrn '__imp__AllocateLocallyUniqueId@4' as AllocateLocallyUniqueId:dword
    extrn '__imp__AreAllAccessesGranted@8' as AreAllAccessesGranted:dword
    extrn '__imp__AreAnyAccessesGranted@8' as AreAnyAccessesGranted:dword
    extrn '__imp__BackupEventLogA@8' as BackupEventLogA:dword
    extrn '__imp__BackupEventLogW@8' as BackupEventLogW:dword
    extrn '__imp__ChangeServiceConfigA@44' as ChangeServiceConfigA:dword
    extrn '__imp__ChangeServiceConfigW@44' as ChangeServiceConfigW:dword
    extrn '__imp__ClearEventLogA@8' as ClearEventLogA:dword
    extrn '__imp__ClearEventLogW@8' as ClearEventLogW:dword
    extrn '__imp__CloseEventLog@4' as CloseEventLog:dword
    extrn '__imp__CloseServiceHandle@4' as CloseServiceHandle:dword
    extrn '__imp__ControlService@12' as ControlService:dword
    extrn '__imp__CopySid@12' as CopySid:dword
    extrn '__imp__CreatePrivateObjectSecurity@24' as CreatePrivateObjectSecurity:dword
    extrn '__imp__CreateServiceA@52' as CreateServiceA:dword
    extrn '__imp__CreateServiceW@52' as CreateServiceW:dword
    extrn '__imp__CryptAcquireContextA@20' as CryptAcquireContextA:dword
    extrn '__imp__CryptAcquireContextW@20' as CryptAcquireContextW:dword
    extrn '__imp__CryptCreateHash@20' as CryptCreateHash:dword
    extrn '__imp__CryptDecrypt@24' as CryptDecrypt:dword
    extrn '__imp__CryptDeriveKey@20' as CryptDeriveKey:dword
    extrn '__imp__CryptDestroyHash@4' as CryptDestroyHash:dword
    extrn '__imp__CryptDestroyKey@4' as CryptDestroyKey:dword
    extrn '__imp__CryptEncrypt@28' as CryptEncrypt:dword
    extrn '__imp__CryptExportKey@24' as CryptExportKey:dword
    extrn '__imp__CryptGenKey@16' as CryptGenKey:dword
    extrn '__imp__CryptGenRandom@12' as CryptGenRandom:dword
    extrn '__imp__CryptGetHashParam@20' as CryptGetHashParam:dword
    extrn '__imp__CryptGetKeyParam@20' as CryptGetKeyParam:dword
    extrn '__imp__CryptGetProvParam@20' as CryptGetProvParam:dword
    extrn '__imp__CryptGetUserKey@12' as CryptGetUserKey:dword
    extrn '__imp__CryptHashData@16' as CryptHashData:dword
    extrn '__imp__CryptHashSessionKey@12' as CryptHashSessionKey:dword
    extrn '__imp__CryptImportKey@24' as CryptImportKey:dword
    extrn '__imp__CryptReleaseContext@8' as CryptReleaseContext:dword
    extrn '__imp__CryptSetHashParam@16' as CryptSetHashParam:dword
    extrn '__imp__CryptSetKeyParam@16' as CryptSetKeyParam:dword
    extrn '__imp__CryptSetProviderA@8' as CryptSetProviderA:dword
    extrn '__imp__CryptSetProviderExA@16' as CryptSetProviderExA:dword
    extrn '__imp__CryptSetProviderExW@16' as CryptSetProviderExW:dword
    extrn '__imp__CryptSetProviderW@8' as CryptSetProviderW:dword
    extrn '__imp__CryptSetProvParam@16' as CryptSetProvParam:dword
    extrn '__imp__CryptSignHashA@24' as CryptSignHashA:dword
    extrn '__imp__CryptSignHashW@24' as CryptSignHashW:dword
    extrn '__imp__CryptVerifySignatureA@24' as CryptVerifySignatureA:dword
    extrn '__imp__CryptVerifySignatureW@24' as CryptVerifySignatureW:dword
    extrn '__imp__DeleteAce@8' as DeleteAce:dword
    extrn '__imp__DeleteService@4' as DeleteService:dword
    extrn '__imp__DeregisterEventSource@4' as DeregisterEventSource:dword
    extrn '__imp__DestroyPrivateObjectSecurity@4' as DestroyPrivateObjectSecurity:dword
    extrn '__imp__DuplicateToken@12' as DuplicateToken:dword
    extrn '__imp__EnumDependentServicesA@24' as EnumDependentServicesA:dword
    extrn '__imp__EnumDependentServicesW@24' as EnumDependentServicesW:dword
    extrn '__imp__EnumServicesStatusA@32' as EnumServicesStatusA:dword
    extrn '__imp__EnumServicesStatusW@32' as EnumServicesStatusW:dword
    extrn '__imp__EqualPrefixSid@8' as EqualPrefixSid:dword
    extrn '__imp__EqualSid@8' as EqualSid:dword
    extrn '__imp__FindFirstFreeAce@8' as FindFirstFreeAce:dword
    extrn '__imp__FreeSid@4' as FreeSid:dword
    extrn '__imp__GetAce@12' as GetAce:dword
    extrn '__imp__GetAclInformation@16' as GetAclInformation:dword
    extrn '__imp__GetFileSecurityA@20' as GetFileSecurityA:dword
    extrn '__imp__GetFileSecurityW@20' as GetFileSecurityW:dword
    extrn '__imp__GetKernelObjectSecurity@20' as GetKernelObjectSecurity:dword
    extrn '__imp__GetLengthSid@4' as GetLengthSid:dword
    extrn '__imp__GetNumberOfEventLogRecords@8' as GetNumberOfEventLogRecords:dword
    extrn '__imp__GetOldestEventLogRecord@8' as GetOldestEventLogRecord:dword
    extrn '__imp__GetPrivateObjectSecurity@20' as GetPrivateObjectSecurity:dword
    extrn '__imp__GetSecurityDescriptorControl@12' as GetSecurityDescriptorControl:dword
    extrn '__imp__GetSecurityDescriptorDacl@16' as GetSecurityDescriptorDacl:dword
    extrn '__imp__GetSecurityDescriptorGroup@12' as GetSecurityDescriptorGroup:dword
    extrn '__imp__GetSecurityDescriptorLength@4' as GetSecurityDescriptorLength:dword
    extrn '__imp__GetSecurityDescriptorOwner@12' as GetSecurityDescriptorOwner:dword
    extrn '__imp__GetSecurityDescriptorSacl@16' as GetSecurityDescriptorSacl:dword
    extrn '__imp__GetServiceDisplayNameA@16' as GetServiceDisplayNameA:dword
    extrn '__imp__GetServiceDisplayNameW@16' as GetServiceDisplayNameW:dword
    extrn '__imp__GetServiceKeyNameA@16' as GetServiceKeyNameA:dword
    extrn '__imp__GetServiceKeyNameW@16' as GetServiceKeyNameW:dword
    extrn '__imp__GetSidIdentifierAuthority@4' as GetSidIdentifierAuthority:dword
    extrn '__imp__GetSidLengthRequired@4' as GetSidLengthRequired:dword
    extrn '__imp__GetSidSubAuthority@8' as GetSidSubAuthority:dword
    extrn '__imp__GetSidSubAuthorityCount@4' as GetSidSubAuthorityCount:dword
    extrn '__imp__GetTokenInformation@20' as GetTokenInformation:dword
    extrn '__imp__GetUserNameA@8' as GetUserNameA:dword
    extrn '__imp__GetUserNameW@8' as GetUserNameW:dword
    extrn '__imp__ImpersonateLoggedOnUser@4' as ImpersonateLoggedOnUser:dword
    extrn '__imp__ImpersonateNamedPipeClient@4' as ImpersonateNamedPipeClient:dword
    extrn '__imp__ImpersonateSelf@4' as ImpersonateSelf:dword
    extrn '__imp__InitializeAcl@12' as InitializeAcl:dword
    extrn '__imp__InitializeSecurityDescriptor@8' as InitializeSecurityDescriptor:dword
    extrn '__imp__InitializeSid@12' as InitializeSid:dword
    extrn '__imp__InitiateSystemShutdownA@20' as InitiateSystemShutdownA:dword
    extrn '__imp__InitiateSystemShutdownW@20' as InitiateSystemShutdownW:dword
    extrn '__imp__IsTextUnicode@12' as IsTextUnicode:dword
    extrn '__imp__IsValidAcl@4' as IsValidAcl:dword
    extrn '__imp__IsValidSecurityDescriptor@4' as IsValidSecurityDescriptor:dword
    extrn '__imp__IsValidSid@4' as IsValidSid:dword
    extrn '__imp__LockServiceDatabase@4' as LockServiceDatabase:dword
    extrn '__imp__LogonUserA@24' as LogonUserA:dword
    extrn '__imp__LogonUserW@24' as LogonUserW:dword
    extrn '__imp__LookupAccountNameA@28' as LookupAccountNameA:dword
    extrn '__imp__LookupAccountNameW@28' as LookupAccountNameW:dword
    extrn '__imp__LookupAccountSidA@28' as LookupAccountSidA:dword
    extrn '__imp__LookupAccountSidW@28' as LookupAccountSidW:dword
    extrn '__imp__LookupPrivilegeDisplayNameA@20' as LookupPrivilegeDisplayNameA:dword
    extrn '__imp__LookupPrivilegeDisplayNameW@20' as LookupPrivilegeDisplayNameW:dword
    extrn '__imp__LookupPrivilegeNameA@16' as LookupPrivilegeNameA:dword
    extrn '__imp__LookupPrivilegeNameW@16' as LookupPrivilegeNameW:dword
    extrn '__imp__LookupPrivilegeValueA@12' as LookupPrivilegeValueA:dword
    extrn '__imp__LookupPrivilegeValueW@12' as LookupPrivilegeValueW:dword
    extrn '__imp__MakeAbsoluteSD@44' as MakeAbsoluteSD:dword
    extrn '__imp__MakeSelfRelativeSD@12' as MakeSelfRelativeSD:dword
    extrn '__imp__MapGenericMask@8' as MapGenericMask:dword
    extrn '__imp__NotifyBootConfigStatus@4' as NotifyBootConfigStatus:dword
    extrn '__imp__NotifyChangeEventLog@8' as NotifyChangeEventLog:dword
    extrn '__imp__ObjectCloseAuditAlarmA@12' as ObjectCloseAuditAlarmA:dword
    extrn '__imp__ObjectCloseAuditAlarmW@12' as ObjectCloseAuditAlarmW:dword
    extrn '__imp__ObjectOpenAuditAlarmA@48' as ObjectOpenAuditAlarmA:dword
    extrn '__imp__ObjectOpenAuditAlarmW@48' as ObjectOpenAuditAlarmW:dword
    extrn '__imp__ObjectPrivilegeAuditAlarmA@24' as ObjectPrivilegeAuditAlarmA:dword
    extrn '__imp__ObjectPrivilegeAuditAlarmW@24' as ObjectPrivilegeAuditAlarmW:dword
    extrn '__imp__OpenBackupEventLogA@8' as OpenBackupEventLogA:dword
    extrn '__imp__OpenBackupEventLogW@8' as OpenBackupEventLogW:dword
    extrn '__imp__OpenEventLogA@8' as OpenEventLogA:dword
    extrn '__imp__OpenEventLogW@8' as OpenEventLogW:dword
    extrn '__imp__OpenSCManagerA@12' as OpenSCManagerA:dword
    extrn '__imp__OpenSCManagerW@12' as OpenSCManagerW:dword
    extrn '__imp__OpenServiceA@12' as OpenServiceA:dword
    extrn '__imp__OpenServiceW@12' as OpenServiceW:dword
    extrn '__imp__PrivilegeCheck@12' as PrivilegeCheck:dword
    extrn '__imp__PrivilegedServiceAuditAlarmA@20' as PrivilegedServiceAuditAlarmA:dword
    extrn '__imp__PrivilegedServiceAuditAlarmW@20' as PrivilegedServiceAuditAlarmW:dword
    extrn '__imp__QueryServiceConfigA@16' as QueryServiceConfigA:dword
    extrn '__imp__QueryServiceConfigW@16' as QueryServiceConfigW:dword
    extrn '__imp__QueryServiceLockStatusA@16' as QueryServiceLockStatusA:dword
    extrn '__imp__QueryServiceLockStatusW@16' as QueryServiceLockStatusW:dword
    extrn '__imp__QueryServiceObjectSecurity@20' as QueryServiceObjectSecurity:dword
    extrn '__imp__QueryServiceStatus@8' as QueryServiceStatus:dword
    extrn '__imp__ReadEventLogA@28' as ReadEventLogA:dword
    extrn '__imp__ReadEventLogW@28' as ReadEventLogW:dword
    extrn '__imp__RegConnectRegistryA@12' as RegConnectRegistryA:dword
    extrn '__imp__RegConnectRegistryW@12' as RegConnectRegistryW:dword
    extrn '__imp__RegCloseKey@4' as RegCloseKey:dword
    extrn '__imp__RegCreateKeyA@12' as RegCreateKeyA:dword
    extrn '__imp__RegCreateKeyExA@36' as RegCreateKeyExA:dword
    extrn '__imp__RegCreateKeyExW@36' as RegCreateKeyExW:dword
    extrn '__imp__RegCreateKeyW@12' as RegCreateKeyW:dword
    extrn '__imp__RegDeleteKeyA@8' as RegDeleteKeyA:dword
    extrn '__imp__RegDeleteKeyW@8' as RegDeleteKeyW:dword
    extrn '__imp__RegDeleteValueA@8' as RegDeleteValueA:dword
    extrn '__imp__RegDeleteValueW@8' as RegDeleteValueW:dword
    extrn '__imp__RegEnumKeyA@16' as RegEnumKeyA:dword
    extrn '__imp__RegEnumKeyExA@32' as RegEnumKeyExA:dword
    extrn '__imp__RegEnumKeyExW@32' as RegEnumKeyExW:dword
    extrn '__imp__RegEnumKeyW@16' as RegEnumKeyW:dword
    extrn '__imp__RegEnumValueA@32' as RegEnumValueA:dword
    extrn '__imp__RegEnumValueW@32' as RegEnumValueW:dword
    extrn '__imp__RegFlushKey@4' as RegFlushKey:dword
    extrn '__imp__RegGetKeySecurity@16' as RegGetKeySecurity:dword
    extrn '__imp__RegLoadKeyA@12' as RegLoadKeyA:dword
    extrn '__imp__RegLoadKeyW@12' as RegLoadKeyW:dword
    extrn '__imp__RegNotifyChangeKeyValue@20' as RegNotifyChangeKeyValue:dword
    extrn '__imp__RegOpenKeyA@12' as RegOpenKeyA:dword
    extrn '__imp__RegOpenKeyExA@20' as RegOpenKeyExA:dword
    extrn '__imp__RegOpenKeyExW@20' as RegOpenKeyExW:dword
    extrn '__imp__RegOpenKeyW@12' as RegOpenKeyW:dword
    extrn '__imp__RegQueryInfoKeyA@48' as RegQueryInfoKeyA:dword
    extrn '__imp__RegQueryInfoKeyW@48' as RegQueryInfoKeyW:dword
    extrn '__imp__RegQueryMultipleValuesA@20' as RegQueryMultipleValuesA:dword
    extrn '__imp__RegQueryMultipleValuesW@20' as RegQueryMultipleValuesW:dword
    extrn '__imp__RegQueryValueA@16' as RegQueryValueA:dword
    extrn '__imp__RegQueryValueExA@24' as RegQueryValueExA:dword
    extrn '__imp__RegQueryValueExW@24' as RegQueryValueExW:dword
    extrn '__imp__RegQueryValueW@16' as RegQueryValueW:dword
    extrn '__imp__RegReplaceKeyA@16' as RegReplaceKeyA:dword
    extrn '__imp__RegReplaceKeyW@16' as RegReplaceKeyW:dword
    extrn '__imp__RegRestoreKeyA@12' as RegRestoreKeyA:dword
    extrn '__imp__RegRestoreKeyW@12' as RegRestoreKeyW:dword
    extrn '__imp__RegSaveKeyA@12' as RegSaveKeyA:dword
    extrn '__imp__RegSaveKeyW@12' as RegSaveKeyW:dword
    extrn '__imp__RegSetKeySecurity@12' as RegSetKeySecurity:dword
    extrn '__imp__RegSetValueA@20' as RegSetValueA:dword
    extrn '__imp__RegSetValueExA@24' as RegSetValueExA:dword
    extrn '__imp__RegSetValueExW@24' as RegSetValueExW:dword
    extrn '__imp__RegSetValueW@20' as RegSetValueW:dword
    extrn '__imp__RegUnLoadKeyA@8' as RegUnLoadKeyA:dword
    extrn '__imp__RegUnLoadKeyW@8' as RegUnLoadKeyW:dword
    extrn '__imp__RegisterEventSourceA@8' as RegisterEventSourceA:dword
    extrn '__imp__RegisterEventSourceW@8' as RegisterEventSourceW:dword
    extrn '__imp__RegisterServiceCtrlHandlerA@8' as RegisterServiceCtrlHandlerA:dword
    extrn '__imp__RegisterServiceCtrlHandlerW@8' as RegisterServiceCtrlHandlerW:dword
    extrn '__imp__ReportEventA@36' as ReportEventA:dword
    extrn '__imp__ReportEventW@36' as ReportEventW:dword
    extrn '__imp__RevertToSelf@0' as RevertToSelf:dword
    extrn '__imp__SetAclInformation@16' as SetAclInformation:dword
    extrn '__imp__SetFileSecurityA@12' as SetFileSecurityA:dword
    extrn '__imp__SetFileSecurityW@12' as SetFileSecurityW:dword
    extrn '__imp__SetKernelObjectSecurity@12' as SetKernelObjectSecurity:dword
    extrn '__imp__SetPrivateObjectSecurity@20' as SetPrivateObjectSecurity:dword
    extrn '__imp__SetSecurityDescriptorDacl@16' as SetSecurityDescriptorDacl:dword
    extrn '__imp__SetSecurityDescriptorGroup@12' as SetSecurityDescriptorGroup:dword
    extrn '__imp__SetSecurityDescriptorOwner@12' as SetSecurityDescriptorOwner:dword
    extrn '__imp__SetSecurityDescriptorSacl@16' as SetSecurityDescriptorSacl:dword
    extrn '__imp__SetServiceBits@16' as SetServiceBits:dword
    extrn '__imp__SetServiceObjectSecurity@12' as SetServiceObjectSecurity:dword
    extrn '__imp__SetServiceStatus@8' as SetServiceStatus:dword
    extrn '__imp__SetThreadToken@8' as SetThreadToken:dword
    extrn '__imp__SetTokenInformation@16' as SetTokenInformation:dword
    extrn '__imp__StartServiceA@12' as StartServiceA:dword
    extrn '__imp__StartServiceCtrlDispatcherA@4' as StartServiceCtrlDispatcherA:dword
    extrn '__imp__StartServiceCtrlDispatcherW@4' as StartServiceCtrlDispatcherW:dword
    extrn '__imp__StartServiceW@12' as StartServiceW:dword
    extrn '__imp__UnlockServiceDatabase@4' as UnlockServiceDatabase:dword

    if (NTDDI_VERSION >= NTDDI_WIN98_ME)
        extrn '__imp__BuildExplicitAccessWithNameA@20' as BuildExplicitAccessWithNameA:dword
        extrn '__imp__BuildExplicitAccessWithNameW@20' as BuildExplicitAccessWithNameW:dword
        extrn '__imp__BuildSecurityDescriptorA@36' as BuildSecurityDescriptorA:dword
        extrn '__imp__BuildSecurityDescriptorW@36' as BuildSecurityDescriptorW:dword
        extrn '__imp__BuildTrusteeWithNameA@8' as BuildTrusteeWithNameA:dword
        extrn '__imp__BuildTrusteeWithNameW@8' as BuildTrusteeWithNameW:dword
        extrn '__imp__BuildTrusteeWithSidA@8' as BuildTrusteeWithSidA:dword
        extrn '__imp__BuildTrusteeWithSidW@8' as BuildTrusteeWithSidW:dword
        extrn '__imp__ConvertAccessToSecurityDescriptorA@20' as ConvertAccessToSecurityDescriptorA:dword
        extrn '__imp__ConvertAccessToSecurityDescriptorW@20' as ConvertAccessToSecurityDescriptorW:dword
        extrn '__imp__ConvertSecurityDescriptorToAccessA@28' as ConvertSecurityDescriptorToAccessA:dword
        extrn '__imp__ConvertSecurityDescriptorToAccessW@28' as ConvertSecurityDescriptorToAccessW:dword
        extrn '__imp__ConvertSecurityDescriptorToAccessNamedA@28' as ConvertSecurityDescriptorToAccessNamedA:dword
        extrn '__imp__ConvertSecurityDescriptorToAccessNamedW@28' as ConvertSecurityDescriptorToAccessNamedW:dword
        extrn '__imp__CryptContextAddRef@12' as CryptContextAddRef:dword
        extrn '__imp__CryptDuplicateHash@16' as CryptDuplicateHash:dword
        extrn '__imp__CryptDuplicateKey@16' as CryptDuplicateKey:dword
        extrn '__imp__CryptEnumProvidersA@24' as CryptEnumProvidersA:dword
        extrn '__imp__CryptEnumProviderTypesA@24' as CryptEnumProviderTypesA:dword
        extrn '__imp__CryptEnumProviderTypesW@24' as CryptEnumProviderTypesW:dword
        extrn '__imp__CryptEnumProvidersW@24' as CryptEnumProvidersW:dword
        extrn '__imp__CryptGetDefaultProviderA@20' as CryptGetDefaultProviderA:dword
        extrn '__imp__CryptGetDefaultProviderW@20' as CryptGetDefaultProviderW:dword
        extrn '__imp__DuplicateTokenEx@24' as DuplicateTokenEx:dword
        extrn '__imp__GetAccessPermissionsForObjectA@36' as GetAccessPermissionsForObjectA:dword
        extrn '__imp__GetAccessPermissionsForObjectW@36' as GetAccessPermissionsForObjectW:dword
        extrn '__imp__GetAuditedPermissionsFromAclA@16' as GetAuditedPermissionsFromAclA:dword
        extrn '__imp__GetAuditedPermissionsFromAclW@16' as GetAuditedPermissionsFromAclW:dword
        extrn '__imp__GetCurrentHwProfileA@4' as GetCurrentHwProfileA:dword
        extrn '__imp__GetCurrentHwProfileW@4' as GetCurrentHwProfileW:dword
        extrn '__imp__GetEffectiveRightsFromAclA@12' as GetEffectiveRightsFromAclA:dword
        extrn '__imp__GetEffectiveRightsFromAclW@12' as GetEffectiveRightsFromAclW:dword
        extrn '__imp__GetExplicitEntriesFromAclA@12' as GetExplicitEntriesFromAclA:dword
        extrn '__imp__GetExplicitEntriesFromAclW@12' as GetExplicitEntriesFromAclW:dword
        extrn '__imp__GetMultipleTrusteeA@4' as GetMultipleTrusteeA:dword
        extrn '__imp__GetMultipleTrusteeOperationA@4' as GetMultipleTrusteeOperationA:dword
        extrn '__imp__GetMultipleTrusteeOperationW@4' as GetMultipleTrusteeOperationW:dword
        extrn '__imp__GetMultipleTrusteeW@4' as GetMultipleTrusteeW:dword
        extrn '__imp__GetNamedSecurityInfoA@32' as GetNamedSecurityInfoA:dword
        extrn '__imp__GetNamedSecurityInfoExA@36' as GetNamedSecurityInfoExA:dword
        extrn '__imp__GetNamedSecurityInfoExW@36' as GetNamedSecurityInfoExW:dword
        extrn '__imp__GetNamedSecurityInfoW@32' as GetNamedSecurityInfoW:dword
        extrn '__imp__GetOverlappedAccessResults@16' as GetOverlappedAccessResults:dword
        extrn '__imp__GetSecurityInfo@32' as GetSecurityInfo:dword
        extrn '__imp__GetSecurityInfoExA@24' as GetSecurityInfoExA:dword
        extrn '__imp__GetSecurityInfoExW@24' as GetSecurityInfoExW:dword
        extrn '__imp__GetTrusteeNameA@4' as GetTrusteeNameA:dword
        extrn '__imp__GetTrusteeNameW@4' as GetTrusteeNameW:dword
        extrn '__imp__GetTrusteeTypeA@4' as GetTrusteeTypeA:dword
        extrn '__imp__GetTrusteeTypeW@4' as GetTrusteeTypeW:dword
        extrn '__imp__LookupSecurityDescriptorPartsA@28' as LookupSecurityDescriptorPartsA:dword
        extrn '__imp__LookupSecurityDescriptorPartsW@28' as LookupSecurityDescriptorPartsW:dword
        extrn '__imp__ObjectDeleteAuditAlarmA@12' as ObjectDeleteAuditAlarmA:dword
        extrn '__imp__ObjectDeleteAuditAlarmW@12' as ObjectDeleteAuditAlarmW:dword
        extrn '__imp__SetEntriesInAccessListA@24' as SetEntriesInAccessListA:dword
        extrn '__imp__SetEntriesInAccessListW@24' as SetEntriesInAccessListW:dword
        extrn '__imp__SetEntriesInAclA@16' as SetEntriesInAclA:dword
        extrn '__imp__SetEntriesInAclW@16' as SetEntriesInAclW:dword
        extrn '__imp__SetEntriesInAuditListA@24' as SetEntriesInAuditListA:dword
        extrn '__imp__SetEntriesInAuditListW@24' as SetEntriesInAuditListW:dword
        extrn '__imp__SetNamedSecurityInfoA@28' as SetNamedSecurityInfoA:dword
        extrn '__imp__SetNamedSecurityInfoExA@36' as SetNamedSecurityInfoExA:dword
        extrn '__imp__SetNamedSecurityInfoExW@36' as SetNamedSecurityInfoExW:dword
        extrn '__imp__SetNamedSecurityInfoW@28' as SetNamedSecurityInfoW:dword
        extrn '__imp__SetSecurityInfo@28' as SetSecurityInfo:dword
        extrn '__imp__SetSecurityInfoExA@36' as SetSecurityInfoExA:dword
        extrn '__imp__SetSecurityInfoExW@36' as SetSecurityInfoExW:dword
        extrn '__imp__TrusteeAccessToObjectA@24' as TrusteeAccessToObjectA:dword
        extrn '__imp__TrusteeAccessToObjectW@24' as TrusteeAccessToObjectW:dword
        api BuildExplicitAccessWithName,\
            BuildSecurityDescriptor,\
            BuildTrusteeWithName,\
            BuildTrusteeWithSid,\
            ConvertAccessToSecurityDescriptor,\
            ConvertSecurityDescriptorToAccess,\
            ConvertSecurityDescriptorToAccessNamed,\
            CryptEnumProviders,\
            CryptEnumProviderTypes,\
            CryptGetDefaultProvider,\
            GetAccessPermissionsForObject,\
            GetAuditedPermissionsFromAcl,\
            GetCurrentHwProfile,\
            GetEffectiveRightsFromAcl,\
            GetExplicitEntriesFromAcl,\
            GetMultipleTrustee,\
            GetMultipleTrusteeOperation,\
            GetNamedSecurityInfo,\
            GetNamedSecurityInfoEx,\
            GetSecurityInfoEx,\
            GetTrusteeName,\
            GetTrusteeType,\
            LookupSecurityDescriptorParts,\
            ObjectDeleteAuditAlarm,\
            SetEntriesInAccessList,\
            SetEntriesInAcl,\
            SetEntriesInAuditList,\
            SetNamedSecurityInfo,\
            SetNamedSecurityInfoEx,\
            SetSecurityInfoEx,\
            TrusteeAccessToObject
    end if

    if (NTDDI_VERSION >= NTDDI_WINNT4)
        extrn '__imp__CreateProcessAsUserA@44' as CreateProcessAsUserA:dword
        extrn '__imp__CreateProcessAsUserW@44' as CreateProcessAsUserW:dword
        extrn '__imp__ElfBackupEventLogFileA@8' as ElfBackupEventLogFileA:dword
        extrn '__imp__ElfBackupEventLogFileW@8' as ElfBackupEventLogFileW:dword
        extrn '__imp__ElfChangeNotify@8' as ElfChangeNotify:dword
        extrn '__imp__ElfClearEventLogFileA@8' as ElfClearEventLogFileA:dword
        extrn '__imp__ElfClearEventLogFileW@8' as ElfClearEventLogFileW:dword
        extrn '__imp__ElfCloseEventLog@4' as ElfCloseEventLog:dword
        extrn '__imp__ElfDeregisterEventSource@4' as ElfDeregisterEventSource:dword
        extrn '__imp__ElfNumberOfRecords@8' as ElfNumberOfRecords:dword
        extrn '__imp__ElfOldestRecord@8' as ElfOldestRecord:dword
        extrn '__imp__ElfOpenBackupEventLogA@12' as ElfOpenBackupEventLogA:dword
        extrn '__imp__ElfOpenBackupEventLogW@12' as ElfOpenBackupEventLogW:dword
        extrn '__imp__ElfOpenEventLogA@12' as ElfOpenEventLogA:dword
        extrn '__imp__ElfOpenEventLogW@12' as ElfOpenEventLogW:dword
        extrn '__imp__ElfReadEventLogA@28' as ElfReadEventLogA:dword
        extrn '__imp__ElfReadEventLogW@28' as ElfReadEventLogW:dword
        extrn '__imp__ElfRegisterEventSourceA@12' as ElfRegisterEventSourceA:dword
        extrn '__imp__ElfRegisterEventSourceW@12' as ElfRegisterEventSourceW:dword
        extrn '__imp__ElfReportEventA@48' as ElfReportEventA:dword
        extrn '__imp__ElfReportEventW@48' as ElfReportEventW:dword
        extrn '__imp__EnumServiceGroupW@36' as EnumServiceGroupW:dword
        extrn '__imp__EnumServicesStatusExA@40' as EnumServicesStatusExA:dword
        extrn '__imp__EnumServicesStatusExW@40' as EnumServicesStatusExW:dword
        extrn '__imp__IsTokenUntrusted@4' as IsTokenUntrusted:dword
        extrn '__imp__LsaAddAccountRights@16' as LsaAddAccountRights:dword
        extrn '__imp__LsaAddPrivilegesToAccount@8' as LsaAddPrivilegesToAccount:dword
        extrn '__imp__LsaClearAuditLog@4' as LsaClearAuditLog:dword
        extrn '__imp__LsaClose@4' as LsaClose:dword
        extrn '__imp__LsaCreateAccount@16' as LsaCreateAccount:dword
        extrn '__imp__LsaCreateSecret@16' as LsaCreateSecret:dword
        extrn '__imp__LsaCreateTrustedDomain@16' as LsaCreateTrustedDomain:dword
        extrn '__imp__LsaDelete@4' as LsaDelete:dword
        extrn '__imp__LsaDeleteTrustedDomain@8' as LsaDeleteTrustedDomain:dword
        extrn '__imp__LsaEnumerateAccountRights@16' as LsaEnumerateAccountRights:dword
        extrn '__imp__LsaEnumerateAccounts@20' as LsaEnumerateAccounts:dword
        extrn '__imp__LsaEnumerateAccountsWithUserRight@16' as LsaEnumerateAccountsWithUserRight:dword
        extrn '__imp__LsaEnumeratePrivileges@20' as LsaEnumeratePrivileges:dword
        extrn '__imp__LsaEnumeratePrivilegesOfAccount@8' as LsaEnumeratePrivilegesOfAccount:dword
        extrn '__imp__LsaEnumerateTrustedDomains@20' as LsaEnumerateTrustedDomains:dword
        extrn '__imp__LsaFreeMemory@4' as LsaFreeMemory:dword
        extrn '__imp__LsaGetQuotasForAccount@8' as LsaGetQuotasForAccount:dword
        extrn '__imp__LsaGetRemoteUserName@12' as LsaGetRemoteUserName:dword
        extrn '__imp__LsaGetSystemAccessAccount@8' as LsaGetSystemAccessAccount:dword
        extrn '__imp__LsaGetUserName@8' as LsaGetUserName:dword
        extrn '__imp__LsaLookupNames@20' as LsaLookupNames:dword
        extrn '__imp__LsaLookupPrivilegeDisplayName@16' as LsaLookupPrivilegeDisplayName:dword
        extrn '__imp__LsaLookupPrivilegeName@12' as LsaLookupPrivilegeName:dword
        extrn '__imp__LsaLookupPrivilegeValue@12' as LsaLookupPrivilegeValue:dword
        extrn '__imp__LsaLookupSids@20' as LsaLookupSids:dword
        extrn '__imp__LsaNtStatusToWinError@4' as LsaNtStatusToWinError:dword
        extrn '__imp__LsaOpenAccount@16' as LsaOpenAccount:dword
        extrn '__imp__LsaOpenPolicy@16' as LsaOpenPolicy:dword
        extrn '__imp__LsaOpenSecret@16' as LsaOpenSecret:dword
        extrn '__imp__LsaOpenTrustedDomain@16' as LsaOpenTrustedDomain:dword
        extrn '__imp__LsaOpenTrustedDomainByName@16' as LsaOpenTrustedDomainByName:dword
        extrn '__imp__LsaQueryInformationPolicy@12' as LsaQueryInformationPolicy:dword
        extrn '__imp__LsaQuerySecret@20' as LsaQuerySecret:dword
        extrn '__imp__LsaQuerySecurityObject@12' as LsaQuerySecurityObject:dword
        extrn '__imp__LsaQueryTrustedDomainInfo@16' as LsaQueryTrustedDomainInfo:dword
        extrn '__imp__LsaRemoveAccountRights@20' as LsaRemoveAccountRights:dword
        extrn '__imp__LsaRemovePrivilegesFromAccount@12' as LsaRemovePrivilegesFromAccount:dword
        extrn '__imp__LsaRetrievePrivateData@12' as LsaRetrievePrivateData:dword
        extrn '__imp__LsaSetInformationPolicy@12' as LsaSetInformationPolicy:dword
        extrn '__imp__LsaSetInformationTrustedDomain@12' as LsaSetInformationTrustedDomain:dword
        extrn '__imp__LsaSetQuotasForAccount@8' as LsaSetQuotasForAccount:dword
        extrn '__imp__LsaSetSecret@12' as LsaSetSecret:dword
        extrn '__imp__LsaSetSecurityObject@12' as LsaSetSecurityObject:dword
        extrn '__imp__LsaSetSystemAccessAccount@8' as LsaSetSystemAccessAccount:dword
        extrn '__imp__LsaSetTrustedDomainInformation@16' as LsaSetTrustedDomainInformation:dword
        extrn '__imp__LsaStorePrivateData@12' as LsaStorePrivateData:dword
        extrn '__imp__OpenProcessToken@12' as OpenProcessToken:dword
        extrn '__imp__OpenThreadToken@16' as OpenThreadToken:dword
        api CreateProcessAsUser,\
            ElfBackupEventLogFile,\
            ElfClearEventLogFile,\
            ElfOpenBackupEventLog,\
            ElfOpenEventLog,\
            ElfReadEventLog,\
            ElfRegisterEventSource,\
            ElfReportEvent,\
            EnumServicesStatusEx
    end if

    if (NTDDI_VERSION >= NTDDI_WIN2K)
        extrn '__imp__AccessCheckByType@44' as AccessCheckByType:dword
        extrn '__imp__AccessCheckByTypeAndAuditAlarmA@64' as AccessCheckByTypeAndAuditAlarmA:dword
        extrn '__imp__AccessCheckByTypeAndAuditAlarmW@64' as AccessCheckByTypeAndAuditAlarmW:dword
        extrn '__imp__AccessCheckByTypeResultList@44' as AccessCheckByTypeResultList:dword
        extrn '__imp__AccessCheckByTypeResultListAndAuditAlarmA@64' as AccessCheckByTypeResultListAndAuditAlarmA:dword
        extrn '__imp__AccessCheckByTypeResultListAndAuditAlarmW@64' as AccessCheckByTypeResultListAndAuditAlarmW:dword
        extrn '__imp__AccessCheckByTypeResultListAndAuditAlarmByHandleA@68' as AccessCheckByTypeResultListAndAuditAlarmByHandleA:dword
        extrn '__imp__AccessCheckByTypeResultListAndAuditAlarmByHandleW@68' as AccessCheckByTypeResultListAndAuditAlarmByHandleW:dword
        extrn '__imp__AddAccessAllowedAceEx@20' as AddAccessAllowedAceEx:dword
        extrn '__imp__AddAccessAllowedObjectAce@28' as AddAccessAllowedObjectAce:dword
        extrn '__imp__AddAccessDeniedAceEx@20' as AddAccessDeniedAceEx:dword
        extrn '__imp__AddAccessDeniedObjectAce@28' as AddAccessDeniedObjectAce:dword
        extrn '__imp__AddAuditAccessAceEx@28' as AddAuditAccessAceEx:dword
        extrn '__imp__AddAuditAccessObjectAce@36' as AddAuditAccessObjectAce:dword
        extrn '__imp__AddUsersToEncryptedFile@8' as AddUsersToEncryptedFile:dword
        extrn '__imp__BuildTrusteeWithObjectsAndNameA@24' as BuildTrusteeWithObjectsAndNameA:dword
        extrn '__imp__BuildTrusteeWithObjectsAndNameW@24' as BuildTrusteeWithObjectsAndNameW:dword
        extrn '__imp__BuildTrusteeWithObjectsAndSidA@20' as BuildTrusteeWithObjectsAndSidA:dword
        extrn '__imp__BuildTrusteeWithObjectsAndSidW@20' as BuildTrusteeWithObjectsAndSidW:dword
        extrn '__imp__CheckTokenMembership@12' as CheckTokenMembership:dword
        extrn '__imp__CloseEncryptedFileRaw@4' as CloseEncryptedFileRaw:dword
        extrn '__imp__CloseTrace@4' as CloseTrace:dword
        extrn '__imp__CommandLineFromMsiDescriptor@12' as CommandLineFromMsiDescriptor:dword
        extrn '__imp__ControlTraceA@12' as ControlTraceA:dword
        extrn '__imp__ControlTraceW@12' as ControlTraceW:dword
        extrn '__imp__ConvertSDToStringSDRootDomainA@24' as ConvertSDToStringSDRootDomainA:dword
        extrn '__imp__ConvertSDToStringSDRootDomainW@24' as ConvertSDToStringSDRootDomainW:dword
        extrn '__imp__ConvertSecurityDescriptorToStringSecurityDescriptorA@12' as ConvertSecurityDescriptorToStringSecurityDescriptorA:dword
        extrn '__imp__ConvertSecurityDescriptorToStringSecurityDescriptorW@12' as ConvertSecurityDescriptorToStringSecurityDescriptorW:dword
        extrn '__imp__ConvertSidToStringSidA@8' as ConvertSidToStringSidA:dword
        extrn '__imp__ConvertSidToStringSidW@8' as ConvertSidToStringSidW:dword
        extrn '__imp__ConvertStringSDToSDRootDomainA@20' as ConvertStringSDToSDRootDomainA:dword
        extrn '__imp__ConvertStringSDToSDRootDomainW@20' as ConvertStringSDToSDRootDomainW:dword
        extrn '__imp__ConvertStringSecurityDescriptorToSecurityDescriptorA@16' as ConvertStringSecurityDescriptorToSecurityDescriptorA:dword
        extrn '__imp__ConvertStringSecurityDescriptorToSecurityDescriptorW@16' as ConvertStringSecurityDescriptorToSecurityDescriptorW:dword
        extrn '__imp__ConvertStringSidToSidA@8' as ConvertStringSidToSidA:dword
        extrn '__imp__ConvertStringSidToSidW@8' as ConvertStringSidToSidW:dword
        extrn '__imp__ConvertToAutoInheritPrivateObjectSecurity@24' as ConvertToAutoInheritPrivateObjectSecurity:dword
        extrn '__imp__CreatePrivateObjectSecurityEx@32' as CreatePrivateObjectSecurityEx:dword
        extrn '__imp__CreateProcessWithLogonW@44' as CreateProcessWithLogonW:dword
        extrn '__imp__CreateRestrictedToken@36' as CreateRestrictedToken:dword
        extrn '__imp__CreateTraceInstanceId@8' as CreateTraceInstanceId:dword
        extrn '__imp__CreateWellKnownSid@16' as CreateWellKnownSid:dword
        extrn '__imp__EnableTrace@20' as EnableTrace:dword
        extrn '__imp__EncryptFileA@4' as EncryptFileA:dword
        extrn '__imp__EncryptFileW@4' as EncryptFileW:dword
        extrn '__imp__EncryptionDisable@8' as EncryptionDisable:dword
        extrn '__imp__EqualDomainSid@12' as EqualDomainSid:dword
        extrn '__imp__FileEncryptionStatusA@8' as FileEncryptionStatusA:dword
        extrn '__imp__FileEncryptionStatusW@8' as FileEncryptionStatusW:dword
        extrn '__imp__FreeEncryptionCertificateHashList@4' as FreeEncryptionCertificateHashList:dword
        extrn '__imp__GetEventLogInformation@20' as GetEventLogInformation:dword
        extrn '__imp__GetLocalManagedApplications@12' as GetLocalManagedApplications:dword
        extrn '__imp__GetManagedApplications@20' as GetManagedApplications:dword
        extrn '__imp__ImpersonateAnonymousToken@4' as ImpersonateAnonymousToken:dword
        extrn '__imp__InitiateSystemShutdownExA@24' as InitiateSystemShutdownExA:dword
        extrn '__imp__InitiateSystemShutdownExW@24' as InitiateSystemShutdownExW:dword
        extrn '__imp__InstallApplication@4' as InstallApplication:dword
        extrn '__imp__IsTokenRestricted@4' as IsTokenRestricted:dword
        extrn '__imp__LsaCreateTrustedDomainEx@12' as LsaCreateTrustedDomainEx:dword
        extrn '__imp__LsaEnumerateTrustedDomainsEx@20' as LsaEnumerateTrustedDomainsEx:dword
        extrn '__imp__LsaOpenPolicySce@16' as LsaOpenPolicySce:dword
        extrn '__imp__LsaQueryDomainInformationPolicy@12' as LsaQueryDomainInformationPolicy:dword
        extrn '__imp__LsaQueryInfoTrustedDomain@12' as LsaQueryInfoTrustedDomain:dword
        extrn '__imp__LsaQueryTrustedDomainInfoByName@16' as LsaQueryTrustedDomainInfoByName:dword
        extrn '__imp__LsaSetDomainInformationPolicy@12' as LsaSetDomainInformationPolicy:dword
        extrn '__imp__LsaSetTrustedDomainInfoByName@16' as LsaSetTrustedDomainInfoByName:dword
        extrn '__imp__MakeAbsoluteSD2@8' as MakeAbsoluteSD2:dword
        extrn '__imp__OpenEncryptedFileRawA@12' as OpenEncryptedFileRawA:dword
        extrn '__imp__OpenEncryptedFileRawW@12' as OpenEncryptedFileRawW:dword
        extrn '__imp__OpenTraceA@4' as OpenTraceA:dword
        extrn '__imp__OpenTraceW@4' as OpenTraceW:dword
        extrn '__imp__QueryAllTracesA@12' as QueryAllTracesA:dword
        extrn '__imp__QueryAllTracesW@12' as QueryAllTracesW:dword
        extrn '__imp__QueryRecoveryAgentsOnEncryptedFile@8' as QueryRecoveryAgentsOnEncryptedFile:dword
        extrn '__imp__QueryServiceConfig2A@20' as QueryServiceConfig2A:dword
        extrn '__imp__QueryServiceConfig2W@20' as QueryServiceConfig2W:dword
        extrn '__imp__QueryServiceStatusEx@20' as QueryServiceStatusEx:dword
        extrn '__imp__QueryUsersOnEncryptedFile@8' as QueryUsersOnEncryptedFile:dword
        extrn '__imp__ReadEncryptedFileRaw@12' as ReadEncryptedFileRaw:dword
        extrn '__imp__RegDisablePredefinedCache@0' as RegDisablePredefinedCache:dword
        extrn '__imp__RegOpenCurrentUser@8' as RegOpenCurrentUser:dword
        extrn '__imp__RegOpenUserClassesRoot@16' as RegOpenUserClassesRoot:dword
        extrn '__imp__RegOverridePredefKey@8' as RegOverridePredefKey:dword
        extrn '__imp__RegisterServiceCtrlHandlerExA@12' as RegisterServiceCtrlHandlerExA:dword
        extrn '__imp__RegisterServiceCtrlHandlerExW@12' as RegisterServiceCtrlHandlerExW:dword
        extrn '__imp__RegisterTraceGuidsA@32' as RegisterTraceGuidsA:dword
        extrn '__imp__RegisterTraceGuidsW@32' as RegisterTraceGuidsW:dword
        extrn '__imp__RemoveUsersFromEncryptedFile@8' as RemoveUsersFromEncryptedFile:dword
        extrn '__imp__RemoveTraceCallback@4' as RemoveTraceCallback:dword
        extrn '__imp__SetPrivateObjectSecurityEx@24' as SetPrivateObjectSecurityEx:dword
        extrn '__imp__SetSecurityDescriptorControl@12' as SetSecurityDescriptorControl:dword
        extrn '__imp__SetSecurityDescriptorRMControl@8' as SetSecurityDescriptorRMControl:dword
        extrn '__imp__SetTraceCallback@8' as SetTraceCallback:dword
        extrn '__imp__SetUserFileEncryptionKey@4' as SetUserFileEncryptionKey:dword
        extrn '__imp__StartTraceA@12' as StartTraceA:dword
        extrn '__imp__StartTraceW@12' as StartTraceW:dword
        extrn '__imp__TraceEvent@8' as TraceEvent:dword
        extrn '__imp__TraceEventInstance@16' as TraceEventInstance:dword
        extrn '__imp__UninstallApplication@8' as UninstallApplication:dword
        extrn '__imp__UnregisterTraceGuids@4' as UnregisterTraceGuids:dword
        extrn '__imp__WmiCloseBlock@4' as WmiCloseBlock:dword
        extrn '__imp__WmiEnumerateGuids@8' as WmiEnumerateGuids:dword
        extrn '__imp__WmiDevInstToInstanceNameA@16' as WmiDevInstToInstanceNameA:dword
        extrn '__imp__WmiDevInstToInstanceNameW@16' as WmiDevInstToInstanceNameW:dword
        extrn '__imp__WmiExecuteMethodA@28' as WmiExecuteMethodA:dword
        extrn '__imp__WmiExecuteMethodW@28' as WmiExecuteMethodW:dword
        extrn '__imp__WmiFileHandleToInstanceNameA@16' as WmiFileHandleToInstanceNameA:dword
        extrn '__imp__WmiFileHandleToInstanceNameW@16' as WmiFileHandleToInstanceNameW:dword
        extrn '__imp__WmiFreeBuffer@4' as WmiFreeBuffer:dword
        extrn '__imp__WmiMofEnumerateResourcesA@12' as WmiMofEnumerateResourcesA:dword
        extrn '__imp__WmiMofEnumerateResourcesW@12' as WmiMofEnumerateResourcesW:dword
        extrn '__imp__WmiNotificationRegistrationA@20' as WmiNotificationRegistrationA:dword
        extrn '__imp__WmiNotificationRegistrationW@20' as WmiNotificationRegistrationW:dword
        extrn '__imp__WmiOpenBlock@12' as WmiOpenBlock:dword
        extrn '__imp__WmiQueryAllDataA@12' as WmiQueryAllDataA:dword
        extrn '__imp__WmiQueryAllDataW@12' as WmiQueryAllDataW:dword
        extrn '__imp__WmiQueryGuidInformation@8' as WmiQueryGuidInformation:dword
        extrn '__imp__WmiQuerySingleInstanceA@16' as WmiQuerySingleInstanceA:dword
        extrn '__imp__WmiQuerySingleInstanceW@16' as WmiQuerySingleInstanceW:dword
        extrn '__imp__WmiSetSingleInstanceA@20' as WmiSetSingleInstanceA:dword
        extrn '__imp__WmiSetSingleInstanceW@20' as WmiSetSingleInstanceW:dword
        extrn '__imp__WmiSetSingleItemA@24' as WmiSetSingleItemA:dword
        extrn '__imp__WmiSetSingleItemW@24' as WmiSetSingleItemW:dword
        extrn '__imp__WriteEncryptedFileRaw@12' as WriteEncryptedFileRaw:dword
        api AccessCheckByTypeAndAuditAlarm,\
            AccessCheckByTypeResultListAndAuditAlarm,\
            AccessCheckByTypeResultListAndAuditAlarmByHandle,\
            BuildTrusteeWithObjectsAndName,\
            BuildTrusteeWithObjectsAndSid,\
            ControlTrace,\
            ConvertSDToStringSDRootDomain,\
            ConvertSecurityDescriptorToStringSecurityDescriptor,\
            ConvertSidToStringSid,\
            ConvertStringSDToSDRootDomain,\
            ConvertStringSecurityDescriptorToSecurityDescriptor,\
            ConvertStringSidToSid,\
            EncryptFile,\
            FileEncryptionStatus,\
            InitiateSystemShutdownEx,\
            OpenEncryptedFileRaw,\
            OpenTrace,\
            QueryAllTraces,\
            QueryServiceConfig2,\
            RegisterServiceCtrlHandlerEx,\
            RegisterTraceGuids,\
            StartTrace,\
            WmiDevInstToInstanceName,\
            WmiExecuteMethod,\
            WmiFileHandleToInstanceName,\
            WmiMofEnumerateResources,\
            WmiNotificationRegistration,\
            WmiQueryAllData,\
            WmiQuerySingleInstance,\
            WmiSetSingleInstance,\
            WmiSetSingleItem
    end if

    if (NTDDI_VERSION >= NTDDI_WINXP)
        extrn '__imp__A_SHAFinal@8' as A_SHAFinal:dword
        extrn '__imp__A_SHAInit@4' as A_SHAInit:dword
        extrn '__imp__A_SHAUpdate@12' as A_SHAUpdate:dword
        extrn '__imp__ChangeServiceConfig2A@12' as ChangeServiceConfig2A:dword
        extrn '__imp__ChangeServiceConfig2W@12' as ChangeServiceConfig2W:dword
        extrn '__imp__ConvertStringSDToSDDomainA@24' as ConvertStringSDToSDDomainA:dword
        extrn '__imp__ConvertStringSDToSDDomainW@24' as ConvertStringSDToSDDomainW:dword
        extrn '__imp__CreatePrivateObjectSecurityWithMultipleInheritance@36' as CreatePrivateObjectSecurityWithMultipleInheritance:dword
        extrn '__imp__CredDeleteA@12' as CredDeleteA:dword
        extrn '__imp__CredDeleteW@12' as CredDeleteW:dword
        extrn '__imp__CredEnumerateA@16' as CredEnumerateA:dword
        extrn '__imp__CredEnumerateW@16' as CredEnumerateW:dword
        extrn '__imp__CredFree@4' as CredFree:dword
        extrn '__imp__CredGetSessionTypes@8' as CredGetSessionTypes:dword
        extrn '__imp__CredGetTargetInfoA@12' as CredGetTargetInfoA:dword
        extrn '__imp__CredGetTargetInfoW@12' as CredGetTargetInfoW:dword
        extrn '__imp__CredIsMarshaledCredentialA@4' as CredIsMarshaledCredentialA:dword
        extrn '__imp__CredIsMarshaledCredentialW@4' as CredIsMarshaledCredentialW:dword
        extrn '__imp__CredMarshalCredentialA@12' as CredMarshalCredentialA:dword
        extrn '__imp__CredMarshalCredentialW@12' as CredMarshalCredentialW:dword
        extrn '__imp__CredReadA@16' as CredReadA:dword
        extrn '__imp__CredReadW@16' as CredReadW:dword
        extrn '__imp__CredReadDomainCredentialsA@16' as CredReadDomainCredentialsA:dword
        extrn '__imp__CredReadDomainCredentialsW@16' as CredReadDomainCredentialsW:dword
        extrn '__imp__CredRenameA@16' as CredRenameA:dword
        extrn '__imp__CredRenameW@16' as CredRenameW:dword
        extrn '__imp__CredUnmarshalCredentialA@12' as CredUnmarshalCredentialA:dword
        extrn '__imp__CredUnmarshalCredentialW@12' as CredUnmarshalCredentialW:dword
        extrn '__imp__CredWriteA@8' as CredWriteA:dword
        extrn '__imp__CredWriteW@8' as CredWriteW:dword
        extrn '__imp__CredWriteDomainCredentialsA@12' as CredWriteDomainCredentialsA:dword
        extrn '__imp__CredWriteDomainCredentialsW@12' as CredWriteDomainCredentialsW:dword
        extrn '__imp__DecryptFileA@8' as DecryptFileA:dword
        extrn '__imp__DecryptFileW@8' as DecryptFileW:dword
        extrn '__imp__DuplicateEncryptionInfoFile@20' as DuplicateEncryptionInfoFile:dword
        extrn '__imp__EnumerateTraceGuids@12' as EnumerateTraceGuids:dword
        extrn '__imp__FlushTraceA@12' as FlushTraceA:dword
        extrn '__imp__FlushTraceW@12' as FlushTraceW:dword
        extrn '__imp__FreeInheritedFromArray@12' as FreeInheritedFromArray:dword
        extrn '__imp__GetInheritanceSourceA@40' as GetInheritanceSourceA:dword
        extrn '__imp__GetInheritanceSourceW@40' as GetInheritanceSourceW:dword
        extrn '__imp__GetLocalManagedApplicationData@12' as GetLocalManagedApplicationData:dword
        extrn '__imp__GetManagedApplicationCategories@8' as GetManagedApplicationCategories:dword
        extrn '__imp__GetSecurityDescriptorRMControl@8' as GetSecurityDescriptorRMControl:dword
        extrn '__imp__GetTraceEnableFlags@4' as GetTraceEnableFlags:dword
        extrn '__imp__GetTraceEnableLevel@4' as GetTraceEnableLevel:dword
        extrn '__imp__GetTraceLoggerHandle@4' as GetTraceLoggerHandle:dword
        extrn '__imp__GetTrusteeFormA@4' as GetTrusteeFormA:dword
        extrn '__imp__GetTrusteeFormW@4' as GetTrusteeFormW:dword
        extrn '__imp__GetWindowsAccountDomainSid@12' as GetWindowsAccountDomainSid:dword
        extrn '__imp__IsWellKnownSid@8' as IsWellKnownSid:dword
        extrn '__imp__LogonUserExA@40' as LogonUserExA:dword
        extrn '__imp__LogonUserExExW@44' as LogonUserExExW:dword
        extrn '__imp__LogonUserExW@40' as LogonUserExW:dword
        extrn '__imp__LsaLookupNames2@24' as LsaLookupNames2:dword
        extrn '__imp__LsaQueryForestTrustInformation@12' as LsaQueryForestTrustInformation:dword
        extrn '__imp__LsaSetForestTrustInformation@20' as LsaSetForestTrustInformation:dword
        extrn '__imp__MSChapSrvChangePassword@28' as MSChapSrvChangePassword:dword
        extrn '__imp__MSChapSrvChangePassword2@28' as MSChapSrvChangePassword2:dword
        extrn '__imp__ProcessTrace@16' as ProcessTrace:dword
        extrn '__imp__QueryTraceA@12' as QueryTraceA:dword
        extrn '__imp__QueryTraceW@12' as QueryTraceW:dword
        extrn '__imp__RegDisablePredefinedCacheEx@0' as RegDisablePredefinedCacheEx:dword
        extrn '__imp__RegSaveKeyExA@16' as RegSaveKeyExA:dword
        extrn '__imp__RegSaveKeyExW@16' as RegSaveKeyExW:dword
        extrn '__imp__SaferCloseLevel@4' as SaferCloseLevel:dword
        extrn '__imp__SaferComputeTokenFromLevel@20' as SaferComputeTokenFromLevel:dword
        extrn '__imp__SaferCreateLevel@16' as SaferCreateLevel:dword
        extrn '__imp__SaferGetLevelInformation@20' as SaferGetLevelInformation:dword
        extrn '__imp__SaferGetPolicyInformation@24' as SaferGetPolicyInformation:dword
        extrn '__imp__SaferIdentifyLevel@16' as SaferIdentifyLevel:dword
        extrn '__imp__SaferRecordEventLogEntry@12' as SaferRecordEventLogEntry:dword
        extrn '__imp__SaferSetLevelInformation@16' as SaferSetLevelInformation:dword
        extrn '__imp__SaferSetPolicyInformation@20' as SaferSetPolicyInformation:dword
        extrn '__imp__SaferiIsExecutableFileType@8' as SaferiIsExecutableFileType:dword
        extrn '__imp__SaferiSearchMatchingHashRules@24' as SaferiSearchMatchingHashRules:dword
        extrn '__imp__SetEncryptedFileMetadata@24' as SetEncryptedFileMetadata:dword
        extrn '__imp__StopTraceA@12' as StopTraceA:dword
        extrn '__imp__StopTraceW@12' as StopTraceW:dword
        extrn '__imp__TraceMessage@16' as TraceMessage:dword
        extrn '__imp__TraceMessageVa@20' as TraceMessageVa:dword
        extrn '__imp__TreeResetNamedSecurityInfoA@44' as TreeResetNamedSecurityInfoA:dword
        extrn '__imp__TreeResetNamedSecurityInfoW@44' as TreeResetNamedSecurityInfoW:dword
        extrn '__imp__UpdateTraceA@12' as UpdateTraceA:dword
        extrn '__imp__UpdateTraceW@12' as UpdateTraceW:dword
        extrn '__imp__WmiQueryAllDataMultipleA@16' as WmiQueryAllDataMultipleA:dword
        extrn '__imp__WmiQueryAllDataMultipleW@16' as WmiQueryAllDataMultipleW:dword
        extrn '__imp__WmiQuerySingleInstanceMultipleA@20' as WmiQuerySingleInstanceMultipleA:dword
        extrn '__imp__WmiQuerySingleInstanceMultipleW@20' as WmiQuerySingleInstanceMultipleW:dword
        extrn '__imp__WmiReceiveNotificationsA@16' as WmiReceiveNotificationsA:dword
        extrn '__imp__WmiReceiveNotificationsW@16' as WmiReceiveNotificationsW:dword
        api ChangeServiceConfig2,\
            ConvertStringSDToSDDomain,\
            CredDelete,\
            CredEnumerate,\
            CredGetTargetInfo,\
            CredIsMarshaledCredential,\
            CredMarshalCredential,\
            CredReadDomainCredentials,\
            CredUnmarshalCredential,\
            CredWrite,\
            CredWriteDomainCredentials,\
            DecryptFile,\
            FlushTrace,\
            GetInheritanceSource,\
            GetTrusteeForm,\
            LogonUserEx,\
            QueryTrace,\
            RegSaveKeyEx,\
            StopTrace,\
            TreeResetNamedSecurityInfo,\
            UpdateTrace,\
            WmiQueryAllDataMultiple,\
            WmiQuerySingleInstanceMultiple,\
            WmiReceiveNotifications
    end if

    if (NTDDI_VERSION >= NTDDI_WS03)
        extrn '__imp__CreateProcessWithTokenW@36' as CreateProcessWithTokenW:dword
    end if

    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__AddMandatoryAce@36' as AddMandatoryAce:dword
        extrn '__imp__AuditComputeEffectivePolicyBySid@16' as AuditComputeEffectivePolicyBySid:dword
        extrn '__imp__AuditComputeEffectivePolicyByToken@16' as AuditComputeEffectivePolicyByToken:dword
        extrn '__imp__AuditEnumerateCategories@8' as AuditEnumerateCategories:dword
        extrn '__imp__AuditEnumeratePerUserPolicy@4' as AuditEnumeratePerUserPolicy:dword
        extrn '__imp__AuditEnumerateSubCategories@16' as AuditEnumerateSubCategories:dword
        extrn '__imp__AuditFree@4' as AuditFree:dword
        extrn '__imp__AuditLookupCategoryGuidFromCategoryId@8' as AuditLookupCategoryGuidFromCategoryId:dword
        extrn '__imp__AuditLookupCategoryIdFromCategoryGuid@8' as AuditLookupCategoryIdFromCategoryGuid:dword
        extrn '__imp__AuditLookupCategoryNameA@8' as AuditLookupCategoryNameA:dword
        extrn '__imp__AuditLookupCategoryNameW@8' as AuditLookupCategoryNameW:dword
        extrn '__imp__AuditLookupSubCategoryNameA@8' as AuditLookupSubCategoryNameA:dword
        extrn '__imp__AuditLookupSubCategoryNameW@8' as AuditLookupSubCategoryNameW:dword
        extrn '__imp__AuditQueryPerUserPolicy@16' as AuditQueryPerUserPolicy:dword
        extrn '__imp__AuditQuerySecurity@8' as AuditQuerySecurity:dword
        extrn '__imp__AuditQuerySystemPolicy@12' as AuditQuerySystemPolicy:dword
        extrn '__imp__AuditSetPerUserPolicy@12' as AuditSetPerUserPolicy:dword
        extrn '__imp__AuditSetSecurity@8' as AuditSetSecurity:dword
        extrn '__imp__AuditSetSystemPolicy@8' as AuditSetSystemPolicy:dword
        extrn '__imp__CloseThreadWaitChainSession@4' as CloseThreadWaitChainSession:dword
        extrn '__imp__ControlServiceExA@16' as ControlServiceExA:dword
        extrn '__imp__ControlServiceExW@16' as ControlServiceExW:dword
        extrn '__imp__CredFindBestCredentialA@16' as CredFindBestCredentialA:dword
        extrn '__imp__CredFindBestCredentialW@16' as CredFindBestCredentialW:dword
        extrn '__imp__CredIsProtectedA@8' as CredIsProtectedA:dword
        extrn '__imp__CredIsProtectedW@8' as CredIsProtectedW:dword
        extrn '__imp__CredProtectA@24' as CredProtectA:dword
        extrn '__imp__CredProtectW@24' as CredProtectW:dword
        extrn '__imp__CredUnprotectA@20' as CredUnprotectA:dword
        extrn '__imp__CredUnprotectW@20' as CredUnprotectW:dword
        extrn '__imp__EnumerateTraceGuidsEx@24' as EnumerateTraceGuidsEx:dword
        extrn '__imp__EventAccessControl@20' as EventAccessControl:dword
        extrn '__imp__EventAccessQuery@12' as EventAccessQuery:dword
        extrn '__imp__EventAccessRemove@4' as EventAccessRemove:dword
        extrn '__imp__EventActivityIdControl@8' as EventActivityIdControl:dword
        extrn '__imp__EventEnabled@8' as EventEnabled:dword
        extrn '__imp__EventProviderEnabled@12' as EventProviderEnabled:dword
        extrn '__imp__EventRegister@16' as EventRegister:dword
        extrn '__imp__EventUnregister@4' as EventUnregister:dword
        extrn '__imp__EventWrite@16' as EventWrite:dword
        extrn '__imp__EventWriteString@16' as EventWriteString:dword
        extrn '__imp__EventWriteTransfer@24' as EventWriteTransfer:dword
        extrn '__imp__FlushEfsCache@4' as FlushEfsCache:dword
        extrn '__imp__FreeEncryptedFileMetadata@4' as FreeEncryptedFileMetadata:dword
        extrn '__imp__GetEncryptedFileMetadata@12' as GetEncryptedFileMetadata:dword
        extrn '__imp__GetThreadWaitChain@28' as GetThreadWaitChain:dword
        extrn '__imp__I_QueryTagInformation@12' as I_QueryTagInformation:dword
        extrn '__imp__InitiateShutdownA@20' as InitiateShutdownA:dword
        extrn '__imp__InitiateShutdownW@20' as InitiateShutdownW:dword
        extrn '__imp__LsaManageSidNameMapping@12' as LsaManageSidNameMapping:dword
        extrn '__imp__NotifyServiceStatusChangeA@12' as NotifyServiceStatusChangeA:dword
        extrn '__imp__NotifyServiceStatusChangeW@12' as NotifyServiceStatusChangeW:dword
        extrn '__imp__OpenThreadWaitChainSession@8' as OpenThreadWaitChainSession:dword
        extrn '__imp__PerfCreateInstance@16' as PerfCreateInstance:dword
        extrn '__imp__PerfDecrementULongCounterValue@16' as PerfDecrementULongCounterValue:dword
        extrn '__imp__PerfDecrementULongLongCounterValue@16' as PerfDecrementULongLongCounterValue:dword
        extrn '__imp__PerfDeleteInstance@8' as PerfDeleteInstance:dword
        extrn '__imp__PerfIncrementULongCounterValue@16' as PerfIncrementULongCounterValue:dword
        extrn '__imp__PerfIncrementULongLongCounterValue@16' as PerfIncrementULongLongCounterValue:dword
        extrn '__imp__PerfQueryInstance@16' as PerfQueryInstance:dword
        extrn '__imp__PerfSetCounterRefValue@16' as PerfSetCounterRefValue:dword
        extrn '__imp__PerfSetCounterSetInfo@12' as PerfSetCounterSetInfo:dword
        extrn '__imp__PerfSetULongCounterValue@16' as PerfSetULongCounterValue:dword
        extrn '__imp__PerfSetULongLongCounterValue@16' as PerfSetULongLongCounterValue:dword
        extrn '__imp__PerfStartProvider@12' as PerfStartProvider:dword
        extrn '__imp__PerfStartProviderEx@12' as PerfStartProviderEx:dword
        extrn '__imp__PerfStopProvider@4' as PerfStopProvider:dword
        extrn '__imp__QuerySecurityAccessMask@8' as QuerySecurityAccessMask:dword
        extrn '__imp__RegConnectRegistryExA@20' as RegConnectRegistryExA:dword
        extrn '__imp__RegConnectRegistryExW@20' as RegConnectRegistryExW:dword
        extrn '__imp__RegCopyTreeA@12' as RegCopyTreeA:dword
        extrn '__imp__RegCopyTreeW@12' as RegCopyTreeW:dword
        extrn '__imp__RegCreateKeyTransactedA@44' as RegCreateKeyTransactedA:dword
        extrn '__imp__RegCreateKeyTransactedW@44' as RegCreateKeyTransactedW:dword
        extrn '__imp__RegDeleteKeyExA@16' as RegDeleteKeyExA:dword
        extrn '__imp__RegDeleteKeyExW@16' as RegDeleteKeyExW:dword
        extrn '__imp__RegDeleteKeyTransactedA@24' as RegDeleteKeyTransactedA:dword
        extrn '__imp__RegDeleteKeyTransactedW@24' as RegDeleteKeyTransactedW:dword
        extrn '__imp__RegDeleteKeyValueA@12' as RegDeleteKeyValueA:dword
        extrn '__imp__RegDeleteKeyValueW@12' as RegDeleteKeyValueW:dword
        extrn '__imp__RegDeleteTreeA@8' as RegDeleteTreeA:dword
        extrn '__imp__RegDeleteTreeW@8' as RegDeleteTreeW:dword
        extrn '__imp__RegDisableReflectionKey@4' as RegDisableReflectionKey:dword
        extrn '__imp__RegEnableReflectionKey@4' as RegEnableReflectionKey:dword
        extrn '__imp__RegGetValueA@28' as RegGetValueA:dword
        extrn '__imp__RegGetValueW@28' as RegGetValueW:dword
        extrn '__imp__RegLoadAppKeyA@20' as RegLoadAppKeyA:dword
        extrn '__imp__RegLoadAppKeyW@20' as RegLoadAppKeyW:dword
        extrn '__imp__RegLoadMUIStringA@28' as RegLoadMUIStringA:dword
        extrn '__imp__RegLoadMUIStringW@28' as RegLoadMUIStringW:dword
        extrn '__imp__RegOpenKeyTransactedA@28' as RegOpenKeyTransactedA:dword
        extrn '__imp__RegOpenKeyTransactedW@28' as RegOpenKeyTransactedW:dword
        extrn '__imp__RegQueryReflectionKey@8' as RegQueryReflectionKey:dword
        extrn '__imp__RegSetKeyValueA@24' as RegSetKeyValueA:dword
        extrn '__imp__RegSetKeyValueW@24' as RegSetKeyValueW:dword
        extrn '__imp__RegisterWaitChainCOMCallback@8' as RegisterWaitChainCOMCallback:dword
        extrn '__imp__SetSecurityAccessMask@8' as SetSecurityAccessMask:dword
        extrn '__imp__SetUserFileEncryptionKeyEx@16' as SetUserFileEncryptionKeyEx:dword
        extrn '__imp__TreeSetNamedSecurityInfoA@44' as TreeSetNamedSecurityInfoA:dword
        extrn '__imp__TreeSetNamedSecurityInfoW@44' as TreeSetNamedSecurityInfoW:dword
        api AuditLookupCategoryName,\
            AuditLookupSubCategoryName,\
            ControlServiceEx,\
            CredFindBestCredential,\
            CredIsProtected,\
            CredProtect,\
            CredUnprotect,\
            InitiateShutdown,\
            NotifyServiceStatusChange,\
            RegConnectRegistryEx,\
            RegCopyTree,\
            RegCreateKeyTransacted,\
            RegDeleteKeyEx,\
            RegDeleteKeyTransacted,\
            RegDeleteKeyValue,\
            RegDeleteTree,\
            RegGetValue,\
            RegLoadAppKey,\
            RegLoadMUIString,\
            RegOpenKeyTransacted,\
            RegSetKeyValue,\
            TreeSetNamedSecurityInfo
    end if

    if (NTDDI_VERSION >= NTDDI_WIN7)
        extrn '__imp__AddConditionalAce@32' as AddConditionalAce:dword
        extrn '__imp__AuditQueryGlobalSaclA@8' as AuditQueryGlobalSaclA:dword
        extrn '__imp__AuditQueryGlobalSaclW@8' as AuditQueryGlobalSaclW:dword
        extrn '__imp__AuditSetGlobalSaclA@8' as AuditSetGlobalSaclA:dword
        extrn '__imp__AuditSetGlobalSaclW@8' as AuditSetGlobalSaclW:dword
        extrn '__imp__CredReadByTokenHandle@4' as CredReadByTokenHandle:dword
        extrn '__imp__EnableTraceEx@36' as EnableTraceEx:dword
        extrn '__imp__EnableTraceEx2@32' as EnableTraceEx2:dword
        extrn '__imp__EventWriteEx@32' as EventWriteEx:dword
        extrn '__imp__TraceSetInformation@16' as TraceSetInformation:dword
        api AuditQueryGlobalSacl,\
            AuditSetGlobalSacl
    end if

    if (NTDDI_VERSION >= NTDDI_WIN8)
        extrn '__imp__BaseRegCloseKey@4' as BaseRegCloseKey:dword
        extrn '__imp__BaseRegCreateKey@32' as BaseRegCreateKey:dword
        extrn '__imp__BaseRegDeleteKeyEx@16' as BaseRegDeleteKeyEx:dword
        extrn '__imp__BaseRegDeleteValue@8' as BaseRegDeleteValue:dword
        extrn '__imp__BaseRegFlushKey@4' as BaseRegFlushKey:dword
        extrn '__imp__BaseRegGetVersion@8' as BaseRegGetVersion:dword
        extrn '__imp__BaseRegLoadKey@12' as BaseRegLoadKey:dword
        extrn '__imp__BaseRegOpenKey@20' as BaseRegOpenKey:dword
        extrn '__imp__BaseRegRestoreKey@12' as BaseRegRestoreKey:dword
        extrn '__imp__BaseRegSaveKeyEx@16' as BaseRegSaveKeyEx:dword
        extrn '__imp__BaseRegSetKeySecurity@12' as BaseRegSetKeySecurity:dword
        extrn '__imp__BaseRegSetValue@20' as BaseRegSetValue:dword
        extrn '__imp__BaseRegUnLoadKey@8' as BaseRegUnLoadKey:dword
        extrn '__imp__EnumDynamicTimeZoneInformation@8' as EnumDynamicTimeZoneInformation:dword
        extrn '__imp__EventSetInformation@16' as EventSetInformation:dword
        extrn '__imp__GetDynamicTimeZoneInformationEffectiveYears@12' as GetDynamicTimeZoneInformationEffectiveYears:dword
        extrn '__imp__LsaGetAppliedCAPIDs@12' as LsaGetAppliedCAPIDs:dword
        extrn '__imp__LsaLookupSids2@24' as LsaLookupSids2:dword
        extrn '__imp__LsaQueryCAPs@16' as LsaQueryCAPs:dword
        extrn '__imp__LsaSetCAPs@12' as LsaSetCAPs:dword
        extrn '__imp__OperationEnd@4' as OperationEnd:dword
        extrn '__imp__OperationStart@4' as OperationStart:dword
        extrn '__imp__QueryServiceDynamicInformation@12' as QueryServiceDynamicInformation:dword
        extrn '__imp__TraceQueryInformation@20' as TraceQueryInformation:dword
    end if

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
        AccessCheckAndAuditAlarm,\
        BackupEventLog,\
        ChangeServiceConfig,\
        ClearEventLog,\
        CreateService,\
        CryptAcquireContext,\
        CryptSetProvider,\
        CryptSetProviderEx,\
        CryptSignHash,\
        CryptVerifySignature,\
        EnumDependentServices,\
        EnumServicesStatus,\
        GetFileSecurity,\
        GetServiceDisplayName,\
        GetServiceKeyName,\
        GetUserName,\
        InitiateSystemShutdown,\
        LogonUser,\
        LookupAccountName,\
        LookupAccountSid,\
        LookupPrivilegeDisplayName,\
        LookupPrivilegeName,\
        LookupPrivilegeValue,\
        ObjectCloseAuditAlarm,\
        ObjectOpenAuditAlarm,\
        ObjectPrivilegeAuditAlarm,\
        OpenBackupEventLog,\
        OpenEventLog,\
        OpenSCManager,\
        OpenService,\
        PrivilegedServiceAuditAlarm,\
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
        ReportEvent,\
        SetFileSecurity,\
        StartService,\
        StartServiceCtrlDispatcher
end if

;======================= Undocumented functions (unknown arguments) =======================;
;if defined APP_WIN64
;    extrn '__imp_AddUsersToEncryptedFileEx' as AddUsersToEncryptedFileEx:qword
;    extrn '__imp_CancelOverlappedAccess' as CancelOverlappedAccess:qword
;    extrn '__imp_CheckAppInitBlockedServiceIdentity' as CheckAppInitBlockedServiceIdentity:qword
;    extrn '__imp_CheckForHiberboot' as CheckForHiberboot:qword
;    extrn '__imp_CloseCodeAuthzLevel' as CloseCodeAuthzLevel:qword
;    extrn '__imp_ComputeAccessTokenFromCodeAuthzLevel' as ComputeAccessTokenFromCodeAuthzLevel:qword
;    extrn '__imp_ConvertSDToStringSDDomainW' as ConvertSDToStringSDDomainW:qword
;    extrn '__imp_CreateCodeAuthzLevel' as CreateCodeAuthzLevel:qword
;    extrn '__imp_CredBackupCredentials' as CredBackupCredentials:qword
;    extrn '__imp_CredEncryptAndMarshalBinaryBlob' as CredEncryptAndMarshalBinaryBlob:qword
;    extrn '__imp_CredpConvertCredential' as CredpConvertCredential:qword
;    extrn '__imp_CredpConvertOneCredentialSize' as CredpConvertOneCredentialSize:qword
;    extrn '__imp_CredpConvertTargetInfo' as CredpConvertTargetInfo:qword
;    extrn '__imp_CredpDecodeCredential' as CredpDecodeCredential:qword
;    extrn '__imp_CredpEncodeCredential' as CredpEncodeCredential:qword
;    extrn '__imp_CredpEncodeSecret' as CredpEncodeSecret:qword
;    extrn '__imp_CredProfileLoaded' as CredProfileLoaded:qword
;    extrn '__imp_CredProfileLoadedEx' as CredProfileLoadedEx:qword
;    extrn '__imp_CredProfileUnloaded' as CredProfileUnloaded:qword
;    extrn '__imp_CredRestoreCredentials' as CredRestoreCredentials:qword
;    extrn '__imp_ElfFlushEventLog' as ElfFlushEventLog:qword
;    extrn '__imp_ElfReportEventAndSourceW' as ElfReportEventAndSourceW:qword
;    extrn '__imp_EncryptedFileKeyInfo' as EncryptedFileKeyInfo:qword
;    extrn '__imp_EtwLogSysConfigExtension' as EtwLogSysConfigExtension:qword
;    extrn '__imp_EventWriteEndScenario' as EventWriteEndScenario:qword
;    extrn '__imp_EventWriteStartScenario' as EventWriteStartScenario:qword
;    extrn '__imp_FreeEncryptedFileKeyInfo' as FreeEncryptedFileKeyInfo:qword
;    extrn '__imp_GetInformationCodeAuthzLevelW' as GetInformationCodeAuthzLevelW:qword
;    extrn '__imp_GetInformationCodeAuthzPolicyW' as GetInformationCodeAuthzPolicyW:qword
;    extrn '__imp_GetStringConditionFromBinary' as GetStringConditionFromBinary:qword
;    extrn '__imp_I_ScGetCurrentGroupStateW' as I_ScGetCurrentGroupStateW:qword
;    extrn '__imp_I_ScIsSecurityProcess' as I_ScIsSecurityProcess:qword
;    extrn '__imp_I_ScPnPGetServiceName' as I_ScPnPGetServiceName:qword
;    extrn '__imp_I_ScQueryServiceConfig' as I_ScQueryServiceConfig:qword
;    extrn '__imp_I_ScRegisterPreshutdownRestart' as I_ScRegisterPreshutdownRestart:qword
;    extrn '__imp_I_ScSendPnPMessage' as I_ScSendPnPMessage:qword
;    extrn '__imp_I_ScSendTSMessage' as I_ScSendTSMessage:qword
;    extrn '__imp_I_ScSetServiceBitsA' as I_ScSetServiceBitsA:qword
;    extrn '__imp_I_ScSetServiceBitsW' as I_ScSetServiceBitsW:qword
;    extrn '__imp_I_ScValidatePnPService' as I_ScValidatePnPService:qword
;    extrn '__imp_IdentifyCodeAuthzLevelW' as IdentifyCodeAuthzLevelW:qword
;    extrn '__imp_IsTokenUntrusted' as IsTokenUntrusted:qword
;    extrn '__imp_IsValidRelativeSecurityDescriptor' as IsValidRelativeSecurityDescriptor:qword
;    extrn '__imp_LsaICLookupNames' as LsaICLookupNames:qword
;    extrn '__imp_LsaICLookupNamesWithCreds' as LsaICLookupNamesWithCreds:qword
;    extrn '__imp_LsaICLookupSids' as LsaICLookupSids:qword
;    extrn '__imp_LsaICLookupSidsWithCreds' as LsaICLookupSidsWithCreds:qword
;    extrn '__imp_MD4Final' as MD4Final:qword
;    extrn '__imp_MD4Init' as MD4Init:qword
;    extrn '__imp_MD4Update' as MD4Update:qword
;    extrn '__imp_MD5Final' as MD5Final:qword
;    extrn '__imp_MD5Init' as MD5Init:qword
;    extrn '__imp_MD5Update' as MD5Update:qword
;    extrn '__imp_MIDL_user_free_Ext' as MIDL_user_free_Ext:qword
;    extrn '__imp_PerfAddCounters' as PerfAddCounters:qword
;    extrn '__imp_PerfCloseQueryHandle' as PerfCloseQueryHandle:qword
;    extrn '__imp_PerfDeleteCounters' as PerfDeleteCounters:qword
;    extrn '__imp_PerfEnumerateCounterSet' as PerfEnumerateCounterSet:qword
;    extrn '__imp_PerfEnumerateCounterSetInstances' as PerfEnumerateCounterSetInstances:qword
;    extrn '__imp_PerfOpenQueryHandle' as PerfOpenQueryHandle:qword
;    extrn '__imp_PerfQueryCounterData' as PerfQueryCounterData:qword
;    extrn '__imp_PerfQueryCounterInfo' as PerfQueryCounterInfo:qword
;    extrn '__imp_PerfQueryCounterSetRegistrationInfo' as PerfQueryCounterSetRegistrationInfo:qword
;    extrn '__imp_PerfRegCloseKey' as PerfRegCloseKey:qword
;    extrn '__imp_PerfRegEnumKey' as PerfRegEnumKey:qword
;    extrn '__imp_PerfRegEnumValue' as PerfRegEnumValue:qword
;    extrn '__imp_PerfRegQueryInfoKey' as PerfRegQueryInfoKey:qword
;    extrn '__imp_PerfRegQueryValue' as PerfRegQueryValue:qword
;    extrn '__imp_PerfRegSetValue' as PerfRegSetValue:qword
;    extrn '__imp_ProcessIdleTasks' as ProcessIdleTasks:qword
;    extrn '__imp_ProcessIdleTasksW' as ProcessIdleTasksW:qword
;    extrn '__imp_PsmActivateApplication' as PsmActivateApplication:qword
;    extrn '__imp_PsmAdjustActivationToken' as PsmAdjustActivationToken:qword
;    extrn '__imp_PsmQueryBackgroundActivationType' as PsmQueryBackgroundActivationType:qword
;    extrn '__imp_PsmRegisterApplicationProcess' as PsmRegisterApplicationProcess:qword
;    extrn '__imp_RegisterIdleTask' as RegisterIdleTask:qword
;    extrn '__imp_RegRemapPreDefKey' as RegRemapPreDefKey:qword
;    extrn '__imp_RegRenameKey' as RegRenameKey:qword
;    extrn '__imp_RemoteRegEnumKeyWrapper' as RemoteRegEnumKeyWrapper:qword
;    extrn '__imp_RemoteRegEnumValueWrapper' as RemoteRegEnumValueWrapper:qword
;    extrn '__imp_RemoteRegQueryInfoKeyWrapper' as RemoteRegQueryInfoKeyWrapper:qword
;    extrn '__imp_RemoteRegQueryValueWrapper' as RemoteRegQueryValueWrapper:qword
;    extrn '__imp_SafeBaseRegGetKeySecurity' as SafeBaseRegGetKeySecurity:qword
;    extrn '__imp_SaferiChangeRegistryScope' as SaferiChangeRegistryScope:qword
;    extrn '__imp_SaferiCompareTokenLevels' as SaferiCompareTokenLevels:qword
;    extrn '__imp_SaferiIsDllAllowed' as SaferiIsDllAllowed:qword
;    extrn '__imp_SaferiPopulateDefaultsInRegistry' as SaferiPopulateDefaultsInRegistry:qword
;    extrn '__imp_SaferiRecordEventLogEntry' as SaferiRecordEventLogEntry:qword
;    extrn '__imp_SaferiReplaceProcessThreadTokens' as SaferiReplaceProcessThreadTokens:qword
;    extrn '__imp_SetInformationCodeAuthzLevelW' as SetInformationCodeAuthzLevelW:qword
;    extrn '__imp_SetInformationCodeAuthzPolicyW' as SetInformationCodeAuthzPolicyW:qword
;    extrn '__imp_SystemFunction001' as SystemFunction001:qword
;    extrn '__imp_SystemFunction002' as SystemFunction002:qword
;    extrn '__imp_SystemFunction003' as SystemFunction003:qword
;    extrn '__imp_SystemFunction004' as SystemFunction004:qword
;    extrn '__imp_SystemFunction005' as SystemFunction005:qword
;    extrn '__imp_SystemFunction006' as SystemFunction006:qword
;    extrn '__imp_SystemFunction007' as SystemFunction007:qword
;    extrn '__imp_SystemFunction008' as SystemFunction008:qword
;    extrn '__imp_SystemFunction009' as SystemFunction009:qword
;    extrn '__imp_SystemFunction010' as SystemFunction010:qword
;    extrn '__imp_SystemFunction011' as SystemFunction011:qword
;    extrn '__imp_SystemFunction012' as SystemFunction012:qword
;    extrn '__imp_SystemFunction013' as SystemFunction013:qword
;    extrn '__imp_SystemFunction014' as SystemFunction014:qword
;    extrn '__imp_SystemFunction015' as SystemFunction015:qword
;    extrn '__imp_SystemFunction016' as SystemFunction016:qword
;    extrn '__imp_SystemFunction017' as SystemFunction017:qword
;    extrn '__imp_SystemFunction018' as SystemFunction018:qword
;    extrn '__imp_SystemFunction019' as SystemFunction019:qword
;    extrn '__imp_SystemFunction020' as SystemFunction020:qword
;    extrn '__imp_SystemFunction021' as SystemFunction021:qword
;    extrn '__imp_SystemFunction022' as SystemFunction022:qword
;    extrn '__imp_SystemFunction023' as SystemFunction023:qword
;    extrn '__imp_SystemFunction024' as SystemFunction024:qword
;    extrn '__imp_SystemFunction025' as SystemFunction025:qword
;    extrn '__imp_SystemFunction026' as SystemFunction026:qword
;    extrn '__imp_SystemFunction027' as SystemFunction027:qword
;    extrn '__imp_SystemFunction028' as SystemFunction028:qword
;    extrn '__imp_SystemFunction029' as SystemFunction029:qword
;    extrn '__imp_SystemFunction030' as SystemFunction030:qword
;    extrn '__imp_SystemFunction031' as SystemFunction031:qword
;    extrn '__imp_SystemFunction032' as SystemFunction032:qword
;    extrn '__imp_SystemFunction033' as SystemFunction033:qword
;    extrn '__imp_SystemFunction034' as SystemFunction034:qword
;    extrn '__imp_SystemFunction035' as SystemFunction035:qword
;    extrn '__imp_SystemFunction036' as SystemFunction036:qword
;    extrn '__imp_SystemFunction040' as SystemFunction040:qword
;    extrn '__imp_SystemFunction041' as SystemFunction041:qword
;    extrn '__imp_UnregisterIdleTask' as UnregisterIdleTask:qword
;    extrn '__imp_UsePinForEncryptedFilesA' as UsePinForEncryptedFilesA:qword
;    extrn '__imp_UsePinForEncryptedFilesW' as UsePinForEncryptedFilesW:qword
;    extrn '__imp_WaitServiceState' as WaitServiceState:qword
;    extrn '__imp_WdmWmiServiceMain' as WdmWmiServiceMain:qword
;    extrn '__imp_WmiCloseTraceWithCursor' as WmiCloseTraceWithCursor:qword
;    extrn '__imp_WmiConvertTimestamp' as WmiConvertTimestamp:qword
;    extrn '__imp_WmiGetFirstTraceOffset' as WmiGetFirstTraceOffset:qword
;    extrn '__imp_WmiGetNextEvent' as WmiGetNextEvent:qword
;    extrn '__imp_WmiGetTraceHeader' as WmiGetTraceHeader:qword
;    extrn '__imp_WmiOpenTraceWithCursor' as WmiOpenTraceWithCursor:qword
;    extrn '__imp_WmiParseTraceEvent' as WmiParseTraceEvent:qword
;    extrn '__imp_Wow64Win32ApiEntry' as Wow64Win32ApiEntry:qword
;else
;    extrn '__imp__AddUsersToEncryptedFileEx@??' as AddUsersToEncryptedFileEx:dword
;    extrn '__imp__CancelOverlappedAccess@??' as CancelOverlappedAccess:dword
;    extrn '__imp__CheckAppInitBlockedServiceIdentity@??' as CheckAppInitBlockedServiceIdentity:dword
;    extrn '__imp__CheckForHiberboot@??' as CheckForHiberboot:dword
;    extrn '__imp__CloseCodeAuthzLevel@??' as CloseCodeAuthzLevel:dword
;    extrn '__imp__ComputeAccessTokenFromCodeAuthzLevel@??' as ComputeAccessTokenFromCodeAuthzLevel:dword
;    extrn '__imp__ConvertSDToStringSDDomainW@??' as ConvertSDToStringSDDomainW:dword
;    extrn '__imp__CreateCodeAuthzLevel@??' as CreateCodeAuthzLevel:dword
;    extrn '__imp__CredBackupCredentials@??' as CredBackupCredentials:dword
;    extrn '__imp__CredEncryptAndMarshalBinaryBlob@??' as CredEncryptAndMarshalBinaryBlob:dword
;    extrn '__imp__CredpConvertCredential@??' as CredpConvertCredential:dword
;    extrn '__imp__CredpConvertOneCredentialSize@??' as CredpConvertOneCredentialSize:dword
;    extrn '__imp__CredpConvertTargetInfo@??' as CredpConvertTargetInfo:dword
;    extrn '__imp__CredpDecodeCredential@??' as CredpDecodeCredential:dword
;    extrn '__imp__CredpEncodeCredential@??' as CredpEncodeCredential:dword
;    extrn '__imp__CredpEncodeSecret@??' as CredpEncodeSecret:dword
;    extrn '__imp__CredProfileLoaded@??' as CredProfileLoaded:dword
;    extrn '__imp__CredProfileLoadedEx@??' as CredProfileLoadedEx:dword
;    extrn '__imp__CredProfileUnloaded@??' as CredProfileUnloaded:dword
;    extrn '__imp__CredRestoreCredentials@??' as CredRestoreCredentials:dword
;    extrn '__imp__ElfFlushEventLog@??' as ElfFlushEventLog:dword
;    extrn '__imp__ElfReportEventAndSourceW@??' as ElfReportEventAndSourceW:dword
;    extrn '__imp__EncryptedFileKeyInfo@??' as EncryptedFileKeyInfo:dword
;    extrn '__imp__EtwLogSysConfigExtension@??' as EtwLogSysConfigExtension:dword
;    extrn '__imp__EventWriteEndScenario@??' as EventWriteEndScenario:dword
;    extrn '__imp__EventWriteStartScenario@??' as EventWriteStartScenario:dword
;    extrn '__imp__FreeEncryptedFileKeyInfo@??' as FreeEncryptedFileKeyInfo:dword
;    extrn '__imp__GetInformationCodeAuthzLevelW@??' as GetInformationCodeAuthzLevelW:dword
;    extrn '__imp__GetInformationCodeAuthzPolicyW@??' as GetInformationCodeAuthzPolicyW:dword
;    extrn '__imp__GetStringConditionFromBinary@??' as GetStringConditionFromBinary:dword
;    extrn '__imp__I_ScGetCurrentGroupStateW@??' as I_ScGetCurrentGroupStateW:dword
;    extrn '__imp__I_ScIsSecurityProcess@??' as I_ScIsSecurityProcess:dword
;    extrn '__imp__I_ScPnPGetServiceName@??' as I_ScPnPGetServiceName:dword
;    extrn '__imp__I_ScQueryServiceConfig@??' as I_ScQueryServiceConfig:dword
;    extrn '__imp__I_ScRegisterPreshutdownRestart@??' as I_ScRegisterPreshutdownRestart:dword
;    extrn '__imp__I_ScSendPnPMessage@??' as I_ScSendPnPMessage:dword
;    extrn '__imp__I_ScSendTSMessage@??' as I_ScSendTSMessage:dword
;    extrn '__imp__I_ScSetServiceBitsA@??' as I_ScSetServiceBitsA:dword
;    extrn '__imp__I_ScSetServiceBitsW@??' as I_ScSetServiceBitsW:dword
;    extrn '__imp__I_ScValidatePnPService@??' as I_ScValidatePnPService:dword
;    extrn '__imp__IdentifyCodeAuthzLevelW@??' as IdentifyCodeAuthzLevelW:dword
;    extrn '__imp__IsTokenUntrusted@??' as IsTokenUntrusted:dword
;    extrn '__imp__IsValidRelativeSecurityDescriptor@??' as IsValidRelativeSecurityDescriptor:dword
;    extrn '__imp__LsaICLookupNames@??' as LsaICLookupNames:dword
;    extrn '__imp__LsaICLookupNamesWithCreds@??' as LsaICLookupNamesWithCreds:dword
;    extrn '__imp__LsaICLookupSids@??' as LsaICLookupSids:dword
;    extrn '__imp__LsaICLookupSidsWithCreds@??' as LsaICLookupSidsWithCreds:dword
;    extrn '__imp__MD4Final@??' as MD4Final:dword
;    extrn '__imp__MD4Init@??' as MD4Init:dword
;    extrn '__imp__MD4Update@??' as MD4Update:dword
;    extrn '__imp__MD5Final@??' as MD5Final:dword
;    extrn '__imp__MD5Init@??' as MD5Init:dword
;    extrn '__imp__MD5Update@??' as MD5Update:dword
;    extrn '__imp__MIDL_user_free_Ext@??' as MIDL_user_free_Ext:dword
;    extrn '__imp__PerfAddCounters@??' as PerfAddCounters:dword
;    extrn '__imp__PerfCloseQueryHandle@??' as PerfCloseQueryHandle:dword
;    extrn '__imp__PerfDeleteCounters@??' as PerfDeleteCounters:dword
;    extrn '__imp__PerfEnumerateCounterSet@??' as PerfEnumerateCounterSet:dword
;    extrn '__imp__PerfEnumerateCounterSetInstances@??' as PerfEnumerateCounterSetInstances:dword
;    extrn '__imp__PerfOpenQueryHandle@??' as PerfOpenQueryHandle:dword
;    extrn '__imp__PerfQueryCounterData@??' as PerfQueryCounterData:dword
;    extrn '__imp__PerfQueryCounterInfo@??' as PerfQueryCounterInfo:dword
;    extrn '__imp__PerfQueryCounterSetRegistrationInfo@??' as PerfQueryCounterSetRegistrationInfo:dword
;    extrn '__imp__PerfRegCloseKey@??' as PerfRegCloseKey:dword
;    extrn '__imp__PerfRegEnumKey@??' as PerfRegEnumKey:dword
;    extrn '__imp__PerfRegEnumValue@??' as PerfRegEnumValue:dword
;    extrn '__imp__PerfRegQueryInfoKey@??' as PerfRegQueryInfoKey:dword
;    extrn '__imp__PerfRegQueryValue@??' as PerfRegQueryValue:dword
;    extrn '__imp__PerfRegSetValue@??' as PerfRegSetValue:dword
;    extrn '__imp__ProcessIdleTasks@??' as ProcessIdleTasks:dword
;    extrn '__imp__ProcessIdleTasksW@??' as ProcessIdleTasksW:dword
;    extrn '__imp__PsmActivateApplication@??' as PsmActivateApplication:dword
;    extrn '__imp__PsmAdjustActivationToken@??' as PsmAdjustActivationToken:dword
;    extrn '__imp__PsmQueryBackgroundActivationType@??' as PsmQueryBackgroundActivationType:dword
;    extrn '__imp__PsmRegisterApplicationProcess@??' as PsmRegisterApplicationProcess:dword
;    extrn '__imp__RegisterIdleTask@??' as RegisterIdleTask:dword
;    extrn '__imp__RegRemapPreDefKey@??' as RegRemapPreDefKey:dword
;    extrn '__imp__RegRenameKey@??' as RegRenameKey:dword
;    extrn '__imp__RemoteRegEnumKeyWrapper@??' as RemoteRegEnumKeyWrapper:dword
;    extrn '__imp__RemoteRegEnumValueWrapper@??' as RemoteRegEnumValueWrapper:dword
;    extrn '__imp__RemoteRegQueryInfoKeyWrapper@??' as RemoteRegQueryInfoKeyWrapper:dword
;    extrn '__imp__RemoteRegQueryValueWrapper@??' as RemoteRegQueryValueWrapper:dword
;    extrn '__imp__SafeBaseRegGetKeySecurity@??' as SafeBaseRegGetKeySecurity:dword
;    extrn '__imp__SaferiChangeRegistryScope@??' as SaferiChangeRegistryScope:dword
;    extrn '__imp__SaferiCompareTokenLevels@??' as SaferiCompareTokenLevels:dword
;    extrn '__imp__SaferiIsDllAllowed@??' as SaferiIsDllAllowed:dword
;    extrn '__imp__SaferiPopulateDefaultsInRegistry@??' as SaferiPopulateDefaultsInRegistry:dword
;    extrn '__imp__SaferiRecordEventLogEntry@??' as SaferiRecordEventLogEntry:dword
;    extrn '__imp__SaferiReplaceProcessThreadTokens@??' as SaferiReplaceProcessThreadTokens:dword
;    extrn '__imp__SetInformationCodeAuthzLevelW@??' as SetInformationCodeAuthzLevelW:dword
;    extrn '__imp__SetInformationCodeAuthzPolicyW@??' as SetInformationCodeAuthzPolicyW:dword
;    extrn '__imp__SystemFunction001@??' as SystemFunction001:dword
;    extrn '__imp__SystemFunction002@??' as SystemFunction002:dword
;    extrn '__imp__SystemFunction003@??' as SystemFunction003:dword
;    extrn '__imp__SystemFunction004@??' as SystemFunction004:dword
;    extrn '__imp__SystemFunction005@??' as SystemFunction005:dword
;    extrn '__imp__SystemFunction006@??' as SystemFunction006:dword
;    extrn '__imp__SystemFunction007@??' as SystemFunction007:dword
;    extrn '__imp__SystemFunction008@??' as SystemFunction008:dword
;    extrn '__imp__SystemFunction009@??' as SystemFunction009:dword
;    extrn '__imp__SystemFunction010@??' as SystemFunction010:dword
;    extrn '__imp__SystemFunction011@??' as SystemFunction011:dword
;    extrn '__imp__SystemFunction012@??' as SystemFunction012:dword
;    extrn '__imp__SystemFunction013@??' as SystemFunction013:dword
;    extrn '__imp__SystemFunction014@??' as SystemFunction014:dword
;    extrn '__imp__SystemFunction015@??' as SystemFunction015:dword
;    extrn '__imp__SystemFunction016@??' as SystemFunction016:dword
;    extrn '__imp__SystemFunction017@??' as SystemFunction017:dword
;    extrn '__imp__SystemFunction018@??' as SystemFunction018:dword
;    extrn '__imp__SystemFunction019@??' as SystemFunction019:dword
;    extrn '__imp__SystemFunction020@??' as SystemFunction020:dword
;    extrn '__imp__SystemFunction021@??' as SystemFunction021:dword
;    extrn '__imp__SystemFunction022@??' as SystemFunction022:dword
;    extrn '__imp__SystemFunction023@??' as SystemFunction023:dword
;    extrn '__imp__SystemFunction024@??' as SystemFunction024:dword
;    extrn '__imp__SystemFunction025@??' as SystemFunction025:dword
;    extrn '__imp__SystemFunction026@??' as SystemFunction026:dword
;    extrn '__imp__SystemFunction027@??' as SystemFunction027:dword
;    extrn '__imp__SystemFunction028@??' as SystemFunction028:dword
;    extrn '__imp__SystemFunction029@??' as SystemFunction029:dword
;    extrn '__imp__SystemFunction030@??' as SystemFunction030:dword
;    extrn '__imp__SystemFunction031@??' as SystemFunction031:dword
;    extrn '__imp__SystemFunction032@??' as SystemFunction032:dword
;    extrn '__imp__SystemFunction033@??' as SystemFunction033:dword
;    extrn '__imp__SystemFunction034@??' as SystemFunction034:dword
;    extrn '__imp__SystemFunction035@??' as SystemFunction035:dword
;    extrn '__imp__SystemFunction036@??' as SystemFunction036:dword
;    extrn '__imp__SystemFunction040@??' as SystemFunction040:dword
;    extrn '__imp__SystemFunction041@??' as SystemFunction041:dword
;    extrn '__imp__UnregisterIdleTask@??' as UnregisterIdleTask:dword
;    extrn '__imp__UsePinForEncryptedFilesA@??' as UsePinForEncryptedFilesA:dword
;    extrn '__imp__UsePinForEncryptedFilesW@??' as UsePinForEncryptedFilesW:dword
;    extrn '__imp__WaitServiceState@??' as WaitServiceState:dword
;    extrn '__imp__WdmWmiServiceMain@??' as WdmWmiServiceMain:dword
;    extrn '__imp__WmiCloseTraceWithCursor@??' as WmiCloseTraceWithCursor:dword
;    extrn '__imp__WmiConvertTimestamp@??' as WmiConvertTimestamp:dword
;    extrn '__imp__WmiGetFirstTraceOffset@??' as WmiGetFirstTraceOffset:dword
;    extrn '__imp__WmiGetNextEvent@??' as WmiGetNextEvent:dword
;    extrn '__imp__WmiGetTraceHeader@??' as WmiGetTraceHeader:dword
;    extrn '__imp__WmiOpenTraceWithCursor@??' as WmiOpenTraceWithCursor:dword
;    extrn '__imp__WmiParseTraceEvent@??' as WmiParseTraceEvent:dword
;    extrn '__imp__Wow64Win32ApiEntry@??' as Wow64Win32ApiEntry:dword
;end if

;api I_ScSetServiceBits,\
;    UsePinForEncryptedFiles

SetInformationCodeAuthzLevel equ SetInformationCodeAuthzLevelW

end if ; ADVAPI32_INC
