; ======================================================;
;                                                       ;
;  advapi32.inc for Easy Code 2.0 64-bit Masm projects  ;
;                  (version 1.0.5)                      ;
;                                                       ;
;          Copyright © Ramon Sala - 2015-2019           ;
;                                                       ;
; ======================================================;

IFNDEF ADVAPI32_INC
ADVAPI32_INC     EQU     1

Include macros.inc

NO_INHERITANCE                                  EQU     000H
SUB_OBJECTS_ONLY_INHERIT                        EQU     001H
SUB_CONTAINERS_ONLY_INHERIT                     EQU     002H
SUB_CONTAINERS_AND_OBJECTS_INHERIT              EQU     003H
INHERIT_NO_PROPAGATE                            EQU     004H
INHERIT_ONLY                                    EQU     008H
INHERITED_ACCESS_ENTRY                          EQU     010H

INHERITED_PARENT                                EQU     010000000H
INHERITED_GRANDPARENT                           EQU     020000000H

ACCCTRL_DEFAULT_PROVIDERA                       EQU     <Windows NT Access Provider>
ACCCTRL_DEFAULT_PROVIDERW                       EQU     L("Windows NT Access Provider")

SERVICES_ACTIVE_DATABASEW                       EQU     L("ServicesActive")
SERVICES_FAILED_DATABASEW                       EQU     L("ServicesFailed")
SERVICES_ACTIVE_DATABASEA                       EQU     <ServicesActive>
SERVICES_FAILED_DATABASEA                       EQU     <ServicesFailed>

SC_GROUP_IDENTIFIERW                            EQU     L("+")
SC_GROUP_IDENTIFIERA                            EQU     <+>

SERVICE_NO_CHANGE                               EQU     0FFFFFFFFH

SERVICE_ACTIVE                                  EQU     00000001H
SERVICE_INACTIVE                                EQU     00000002H
SERVICE_STATE_ALL                               EQU     (SERVICE_ACTIVE OR SERVICE_INACTIVE)

SERVICE_CONTROL_STOP                            EQU     00000001H
SERVICE_CONTROL_PAUSE                           EQU     00000002H
SERVICE_CONTROL_CONTINUE                        EQU     00000003H
SERVICE_CONTROL_INTERROGATE                     EQU     00000004H
SERVICE_CONTROL_SHUTDOWN                        EQU     00000005H
SERVICE_CONTROL_PARAMCHANGE                     EQU     00000006H
SERVICE_CONTROL_NETBINDADD                      EQU     00000007H
SERVICE_CONTROL_NETBINDREMOVE                   EQU     00000008H
SERVICE_CONTROL_NETBINDENABLE                   EQU     00000009H
SERVICE_CONTROL_NETBINDDISABLE                  EQU     0000000AH
SERVICE_CONTROL_DEVICEEVENT                     EQU     0000000BH
SERVICE_CONTROL_HARDWAREPROFILECHANGE           EQU     0000000CH
SERVICE_CONTROL_POWEREVENT                      EQU     0000000DH

SERVICE_STOPPED                                 EQU     00000001H
SERVICE_START_PENDING                           EQU     00000002H
SERVICE_STOP_PENDING                            EQU     00000003H
SERVICE_RUNNING                                 EQU     00000004H
SERVICE_CONTINUE_PENDING                        EQU     00000005H
SERVICE_PAUSE_PENDING                           EQU     00000006H
SERVICE_PAUSED                                  EQU     00000007H

SERVICE_ACCEPT_STOP                             EQU     00000001H
SERVICE_ACCEPT_PAUSE_CONTINUE                   EQU     00000002H
SERVICE_ACCEPT_SHUTDOWN                         EQU     00000004H
SERVICE_ACCEPT_PARAMCHANGE                      EQU     00000008H
SERVICE_ACCEPT_NETBINDCHANGE                    EQU     00000010H
SERVICE_ACCEPT_HARDWAREPROFILECHANGE            EQU     00000020H
SERVICE_ACCEPT_POWEREVENT                       EQU     00000040H

IFNDEF STANDARD_RIGHTS_REQUIRED
    STANDARD_RIGHTS_REQUIRED                    EQU     0000F0000H
ENDIF

SC_MANAGER_CONNECT                              EQU     0001H
SC_MANAGER_CREATE_SERVICE                       EQU     0002H
SC_MANAGER_ENUMERATE_SERVICE                    EQU     0004H
SC_MANAGER_LOCK                                 EQU     0008H
SC_MANAGER_QUERY_LOCK_STATUS                    EQU     0010H
SC_MANAGER_MODIFY_BOOT_CONFIG                   EQU     0020H
SC_MANAGER_ALL_ACCESS                           EQU     (STANDARD_RIGHTS_REQUIRED OR SC_MANAGER_CONNECT OR SC_MANAGER_CREATE_SERVICE OR SC_MANAGER_ENUMERATE_SERVICE OR SC_MANAGER_LOCK OR SC_MANAGER_QUERY_LOCK_STATUS OR SC_MANAGER_MODIFY_BOOT_CONFIG)

SERVICE_QUERY_CONFIG                            EQU     0001H
SERVICE_CHANGE_CONFIG                           EQU     0002H
SERVICE_QUERY_STATUS                            EQU     0004H
SERVICE_ENUMERATE_DEPENDENTS                    EQU     0008H
SERVICE_START                                   EQU     0010H
SERVICE_STOP                                    EQU     0020H
SERVICE_PAUSE_CONTINUE                          EQU     0040H
SERVICE_INTERROGATE                             EQU     0080H
SERVICE_USER_DEFINED_CONTROL                    EQU     0100H
SERVICE_ALL_ACCESS                              EQU     (STANDARD_RIGHTS_REQUIRED OR SERVICE_QUERY_CONFIG OR SERVICE_CHANGE_CONFIG OR SERVICE_QUERY_STATUS OR SERVICE_ENUMERATE_DEPENDENTS OR SERVICE_START OR SERVICE_STOP OR SERVICE_PAUSE_CONTINUE OR SERVICE_INTERROGATE OR SERVICE_USER_DEFINED_CONTROL)

SERVICE_RUNS_IN_SYSTEM_PROCESS                  EQU     00000001H

SERVICE_CONFIG_DESCRIPTION                      EQU     1
SERVICE_CONFIG_FAILURE_ACTIONS                  EQU     2

SC_ACTION_NONE                                  EQU     0
SC_ACTION_RESTART                               EQU     1
SC_ACTION_REBOOT                                EQU     2
SC_ACTION_RUN_COMMAND                           EQU     3

SC_STATUS_PROCESS_INFO                          EQU     0
SC_ENUM_PROCESS_INFO                            EQU     0

TRUSTEE_ACCESS_ALLOWED                          EQU     000000001H
TRUSTEE_ACCESS_READ                             EQU     000000002H
TRUSTEE_ACCESS_WRITE                            EQU     000000004H
TRUSTEE_ACCESS_EXPLICIT                         EQU     000000001H
TRUSTEE_ACCESS_READ_WRITE                       EQU     (TRUSTEE_ACCESS_READ OR TRUSTEE_ACCESS_WRITE)
TRUSTEE_ACCESS_ALL                              EQU     0FFFFFFFFH

ACTRL_RESERVED                                  EQU     000000000H
ACTRL_PERM_1                                    EQU     000000001H
ACTRL_PERM_2                                    EQU     000000002H
ACTRL_PERM_3                                    EQU     000000004H
ACTRL_PERM_4                                    EQU     000000008H
ACTRL_PERM_5                                    EQU     000000010H
ACTRL_PERM_6                                    EQU     000000020H
ACTRL_PERM_7                                    EQU     000000040H
ACTRL_PERM_8                                    EQU     000000080H
ACTRL_PERM_9                                    EQU     000000100H
ACTRL_PERM_10                                   EQU     000000200H
ACTRL_PERM_11                                   EQU     000000400H
ACTRL_PERM_12                                   EQU     000000800H
ACTRL_PERM_13                                   EQU     000001000H
ACTRL_PERM_14                                   EQU     000002000H
ACTRL_PERM_15                                   EQU     000004000H
ACTRL_PERM_16                                   EQU     000008000H
ACTRL_PERM_17                                   EQU     000010000H
ACTRL_PERM_18                                   EQU     000020000H
ACTRL_PERM_19                                   EQU     000040000H
ACTRL_PERM_20                                   EQU     000080000H

ACTRL_ACCESS_ALLOWED                            EQU     000000001H
ACTRL_ACCESS_DENIED                             EQU     000000002H
ACTRL_AUDIT_SUCCESS                             EQU     000000004H
ACTRL_AUDIT_FAILURE                             EQU     000000008H

ACTRL_ACCESS_PROTECTED                          EQU     000000001H

ACTRL_SYSTEM_ACCESS                             EQU     004000000H
ACTRL_DELETE                                    EQU     008000000H
ACTRL_READ_CONTROL                              EQU     010000000H
ACTRL_CHANGE_ACCESS                             EQU     020000000H
ACTRL_CHANGE_OWNER                              EQU     040000000H
ACTRL_SYNCHRONIZE                               EQU     080000000H
ACTRL_STD_RIGHTS_ALL                            EQU     0F8000000H
ACTRL_STD_RIGHT_REQUIRED                        EQU     (ACTRL_STD_RIGHTS_ALL AND (NOT ACTRL_SYNCHRONIZE))

IFNDEF ACTRL_DS_OPEN
    ACTRL_DS_OPEN                               EQU     ACTRL_RESERVED
    ACTRL_DS_CREATE_CHILD                       EQU     ACTRL_PERM_1
    ACTRL_DS_DELETE_CHILD                       EQU     ACTRL_PERM_2
    ACTRL_DS_LIST                               EQU     ACTRL_PERM_3
    ACTRL_DS_SELF                               EQU     ACTRL_PERM_4
    ACTRL_DS_READ_PROP                          EQU     ACTRL_PERM_5
    ACTRL_DS_WRITE_PROP                         EQU     ACTRL_PERM_6
    ACTRL_DS_DELETE_TREE                        EQU     ACTRL_PERM_7
    ACTRL_DS_LIST_OBJECT                        EQU     ACTRL_PERM_8
    ACTRL_DS_CONTROL_ACCESS                     EQU     ACTRL_PERM_9
ENDIF

ACTRL_FILE_READ                                 EQU     ACTRL_PERM_1
ACTRL_FILE_WRITE                                EQU     ACTRL_PERM_2
ACTRL_FILE_APPEND                               EQU     ACTRL_PERM_3
ACTRL_FILE_READ_PROP                            EQU     ACTRL_PERM_4
ACTRL_FILE_WRITE_PROP                           EQU     ACTRL_PERM_5
ACTRL_FILE_EXECUTE                              EQU     ACTRL_PERM_6
ACTRL_FILE_READ_ATTRIB                          EQU     ACTRL_PERM_8
ACTRL_FILE_WRITE_ATTRIB                         EQU     ACTRL_PERM_9
ACTRL_FILE_CREATE_PIPE                          EQU     ACTRL_PERM_10
ACTRL_DIR_LIST                                  EQU     ACTRL_PERM_1
ACTRL_DIR_CREATE_OBJECT                         EQU     ACTRL_PERM_2
ACTRL_DIR_CREATE_CHILD                          EQU     ACTRL_PERM_3
ACTRL_DIR_DELETE_CHILD                          EQU     ACTRL_PERM_7
ACTRL_DIR_TRAVERSE                              EQU     ACTRL_PERM_6
ACTRL_KERNEL_TERMINATE                          EQU     ACTRL_PERM_1
ACTRL_KERNEL_THREAD                             EQU     ACTRL_PERM_2
ACTRL_KERNEL_VM                                 EQU     ACTRL_PERM_3
ACTRL_KERNEL_VM_READ                            EQU     ACTRL_PERM_4
ACTRL_KERNEL_VM_WRITE                           EQU     ACTRL_PERM_5
ACTRL_KERNEL_DUP_HANDLE                         EQU     ACTRL_PERM_6
ACTRL_KERNEL_PROCESS                            EQU     ACTRL_PERM_7
ACTRL_KERNEL_SET_INFO                           EQU     ACTRL_PERM_8
ACTRL_KERNEL_GET_INFO                           EQU     ACTRL_PERM_9
ACTRL_KERNEL_CONTROL                            EQU     ACTRL_PERM_10
ACTRL_KERNEL_ALERT                              EQU     ACTRL_PERM_11
ACTRL_KERNEL_GET_CONTEXT                        EQU     ACTRL_PERM_12
ACTRL_KERNEL_SET_CONTEXT                        EQU     ACTRL_PERM_13
ACTRL_KERNEL_TOKEN                              EQU     ACTRL_PERM_14
ACTRL_KERNEL_IMPERSONATE                        EQU     ACTRL_PERM_15
ACTRL_KERNEL_DIMPERSONATE                       EQU     ACTRL_PERM_16
ACTRL_PRINT_SADMIN                              EQU     ACTRL_PERM_1
ACTRL_PRINT_SLIST                               EQU     ACTRL_PERM_2
ACTRL_PRINT_PADMIN                              EQU     ACTRL_PERM_3
ACTRL_PRINT_PUSE                                EQU     ACTRL_PERM_4
ACTRL_PRINT_JADMIN                              EQU     ACTRL_PERM_5
ACTRL_SVC_GET_INFO                              EQU     ACTRL_PERM_1
ACTRL_SVC_SET_INFO                              EQU     ACTRL_PERM_2
ACTRL_SVC_STATUS                                EQU     ACTRL_PERM_3
ACTRL_SVC_LIST                                  EQU     ACTRL_PERM_4
ACTRL_SVC_START                                 EQU     ACTRL_PERM_5
ACTRL_SVC_STOP                                  EQU     ACTRL_PERM_6
ACTRL_SVC_PAUSE                                 EQU     ACTRL_PERM_7
ACTRL_SVC_INTERROGATE                           EQU     ACTRL_PERM_8
ACTRL_SVC_UCONTROL                              EQU     ACTRL_PERM_9
ACTRL_REG_QUERY                                 EQU     ACTRL_PERM_1
ACTRL_REG_SET                                   EQU     ACTRL_PERM_2
ACTRL_REG_CREATE_CHILD                          EQU     ACTRL_PERM_3
ACTRL_REG_LIST                                  EQU     ACTRL_PERM_4
ACTRL_REG_NOTIFY                                EQU     ACTRL_PERM_5
ACTRL_REG_LINK                                  EQU     ACTRL_PERM_6
ACTRL_WIN_CLIPBRD                               EQU     ACTRL_PERM_1
ACTRL_WIN_GLOBAL_ATOMS                          EQU     ACTRL_PERM_2
ACTRL_WIN_CREATE                                EQU     ACTRL_PERM_3
ACTRL_WIN_LIST_DESK                             EQU     ACTRL_PERM_4
ACTRL_WIN_LIST                                  EQU     ACTRL_PERM_5
ACTRL_WIN_READ_ATTRIBS                          EQU     ACTRL_PERM_6
ACTRL_WIN_WRITE_ATTRIBS                         EQU     ACTRL_PERM_7
ACTRL_WIN_SCREEN                                EQU     ACTRL_PERM_8
ACTRL_WIN_EXIT                                  EQU     ACTRL_PERM_9

ACTRL_ACCESS_NO_OPTIONS                         EQU     000000000H
ACTRL_ACCESS_SUPPORTS_OBJECT_ENTRIES            EQU     000000001H

TREE_SEC_INFO_SET                               EQU     000000001H
TREE_SEC_INFO_RESET                             EQU     000000002H
TREE_SEC_INFO_RESET_KEEP_EXPLICIT               EQU     000000003H

ProgressInvokeNever                             EQU     1
ProgressInvokeEveryObject                       EQU     2
ProgressInvokeOnError                           EQU     3
ProgressCancelOperation                         EQU     4
ProgressRetryOperation                          EQU     5
ProgressInvokePrePostError                      EQU     6

SE_UNKNOWN_OBJECT_TYPE                          EQU     0
SE_FILE_OBJECT                                  EQU     1
SE_SERVICE                                      EQU     2
SE_PRINTER                                      EQU     3
SE_REGISTRY_KEY                                 EQU     4
SE_LMSHARE                                      EQU     5
SE_KERNEL_OBJECT                                EQU     6
SE_WINDOW_OBJECT                                EQU     7
SE_DS_OBJECT                                    EQU     8
SE_DS_OBJECT_ALL                                EQU     9
SE_PROVIDER_DEFINED_OBJECT                      EQU     10
SE_WMIGUID_OBJECT                               EQU     11
SE_REGISTRY_WOW64_32KEY                         EQU     12

TRUSTEE_IS_UNKNOWN                              EQU     0
TRUSTEE_IS_USER                                 EQU     1
TRUSTEE_IS_GROUP                                EQU     2
TRUSTEE_IS_DOMAIN                               EQU     3
TRUSTEE_IS_ALIAS                                EQU     4
TRUSTEE_IS_WELL_KNOWN_GROUP                     EQU     5
TRUSTEE_IS_DELETED                              EQU     6
TRUSTEE_IS_INVALID                              EQU     7
TRUSTEE_IS_COMPUTER                             EQU     8

TRUSTEE_IS_SID                                  EQU     0
TRUSTEE_IS_NAME                                 EQU     1
TRUSTEE_BAD_FORM                                EQU     2
TRUSTEE_IS_OBJECTS_AND_SID                      EQU     3
TRUSTEE_IS_OBJECTS_AND_NAME                     EQU     4

NO_MULTIPLE_TRUSTEE                             EQU     0
TRUSTEE_IS_IMPERSONATE                          EQU     1

NOT_USED_ACCESS                                 EQU     0
GRANT_ACCESS                                    EQU     1
SET_ACCESS                                      EQU     2
DENY_ACCESS                                     EQU     3
REVOKE_ACCESS                                   EQU     4
SET_AUDIT_SUCCESS                               EQU     5
SET_AUDIT_FAILURE                               EQU     6

HKEY_CLASSES_ROOT                               EQU     80000000H
HKEY_CURRENT_USER                               EQU     80000001H
HKEY_LOCAL_MACHINE                              EQU     80000002H
HKEY_USERS                                      EQU     80000003H
HKEY_PERFORMANCE_DATA                           EQU     80000004H
HKEY_CURRENT_CONFIG                             EQU     80000005H
HKEY_DYN_DATA                                   EQU     80000006H

REG_OPTION_NON_VOLATILE                         EQU     00000000H
REG_OPTION_VOLATILE                             EQU     00000001H
REG_OPTION_CREATE_LINK                          EQU     00000002H
REG_OPTION_BACKUP_RESTORE                       EQU     00000004H
REG_OPTION_OPEN_LINK                            EQU     00000008H
REG_CREATED_NEW_KEY                             EQU     00000001H
REG_OPENED_EXISTING_KEY                         EQU     00000002H

REG_NONE                                        EQU     0
REG_SZ                                          EQU     1
REG_EXPAND_SZ                                   EQU     2
REG_BINARY                                      EQU     3
REG_DWORD                                       EQU     4
REG_DWORD_LITTLE_ENDIAN                         EQU     4
REG_DWORD_BIG_ENDIAN                            EQU     5
REG_LINK                                        EQU     6
REG_MULTI_SZ                                    EQU     7
REG_RESOURCE_LIST                               EQU     8
REG_FULL_RESOURCE_DESCRIPTOR                    EQU     9
REG_RESOURCE_REQUIREMENTS_LIST                  EQU     10
REG_QWORD                                       EQU     11
REG_QWORD_LITTLE_ENDIAN                         EQU     11
        
REG_NOTIFY_CHANGE_NAME                          EQU     00000001H
REG_NOTIFY_CHANGE_ATTRIBUTES                    EQU     00000002H
REG_NOTIFY_CHANGE_LAST_SET                      EQU     00000004H
REG_NOTIFY_CHANGE_SECURITY                      EQU     00000008H

REG_NOTIFY_THREAD_AGNOSTIC                      EQU     10000000H

;======================================== Structures ======================================;

SERVICE_DESCRIPTIONA STRUCT ALIGNMODE
    lpDescription  XPTR    ?
SERVICE_DESCRIPTIONA ENDS

SERVICE_DESCRIPTIONW STRUCT ALIGNMODE
    lpDescription  XPTR    ?
SERVICE_DESCRIPTIONW ENDS

SC_ACTION STRUCT ALIGNMODE
    _Type  DD  ?
    Delay  DD  ?
SC_ACTION ENDS

SERVICE_FAILURE_ACTIONSA STRUCT ALIGNMODE
    dwResetPeriod  DD   ?
    lpRebootMsg    XPTR ?
    lpCommand      XPTR ?
    cActions       DD   ?
    lpsaActions    XPTR ?
SERVICE_FAILURE_ACTIONSA ENDS

SERVICE_FAILURE_ACTIONSW STRUCT ALIGNMODE
    dwResetPeriod  DD   ?
    lpRebootMsg    XPTR ?
    lpCommand      XPTR ?
    cActions       DD   ?
    lpsaActions    XPTR ?
SERVICE_FAILURE_ACTIONSW ENDS

SERVICE_STATUS STRUCT ALIGNMODE
    dwServiceType             DD  ?
    dwCurrentState            DD  ?
    dwControlsAccepted        DD  ?
    dwWin32ExitCode           DD  ?
    dwServiceSpecificExitCode DD  ?
    dwCheckPoint              DD  ?
    dwWaitHint                DD  ?
SERVICE_STATUS ENDS

SERVICE_STATUS_PROCESS STRUCT ALIGNMODE
    dwServiceType             DD  ?
    dwCurrentState            DD  ?
    dwControlsAccepted        DD  ?
    dwWin32ExitCode           DD  ?
    dwServiceSpecificExitCode DD  ?
    dwCheckPoint              DD  ?
    dwWaitHint                DD  ?
    dwProcessId               DD  ?
    dwServiceFlags            DD  ?
SERVICE_STATUS_PROCESS ENDS

ENUM_SERVICE_STATUSA STRUCT ALIGNMODE
    lpServiceName  XPTR  ?
    lpDisplayName  XPTR  ?
    ServiceStatus  SERVICE_STATUS <>
ENUM_SERVICE_STATUSA ENDS

ENUM_SERVICE_STATUSW STRUCT ALIGNMODE
    lpServiceName  XPTR  ?
    lpDisplayName  XPTR  ?
    ServiceStatus  SERVICE_STATUS <>
ENUM_SERVICE_STATUSW ENDS

ENUM_SERVICE_STATUS_PROCESSA STRUCT ALIGNMODE
    lpServiceName        XPTR  ?
    lpDisplayName        XPTR  ?
    ServiceStatusProcess SERVICE_STATUS_PROCESS <>
ENUM_SERVICE_STATUS_PROCESSA ENDS

ENUM_SERVICE_STATUS_PROCESSW STRUCT ALIGNMODE
    lpServiceName        XPTR  ?
    lpDisplayName        XPTR  ?
    ServiceStatusProcess SERVICE_STATUS_PROCESS <>
ENUM_SERVICE_STATUS_PROCESSW ENDS

QUERY_SERVICE_LOCK_STATUSA STRUCT ALIGNMODE
    fIsLocked      DD   ?
    lpLockOwner    XPTR ?
    dwLockDuration DD   ?
QUERY_SERVICE_LOCK_STATUSA ENDS

QUERY_SERVICE_LOCK_STATUSW STRUCT ALIGNMODE
    fIsLocked      DD   ?
    lpLockOwner    XPTR ?
    dwLockDuration DD   ?
QUERY_SERVICE_LOCK_STATUSW ENDS

QUERY_SERVICE_CONFIGA STRUCT ALIGNMODE
    dwServiceType      DD   ?
    dwStartType        DD   ?
    dwErrorControl     DD   ?
    lpBinaryPathName   XPTR ?
    lpLoadOrderGroup   XPTR ?
    dwTagId            DD   ?
    lpDependencies     XPTR ?
    lpServiceStartName XPTR ?
    lpDisplayName      XPTR ?
QUERY_SERVICE_CONFIGA ENDS

QUERY_SERVICE_CONFIGW STRUCT ALIGNMODE
    dwServiceType      DD   ?
    dwStartType        DD   ?
    dwErrorControl     DD   ?
    lpBinaryPathName   XPTR ?
    lpLoadOrderGroup   XPTR ?
    dwTagId            DD   ?
    lpDependencies     XPTR ?
    lpServiceStartName XPTR ?
    lpDisplayName      XPTR ?
QUERY_SERVICE_CONFIGW ENDS

SERVICE_TABLE_ENTRYA STRUCT ALIGNMODE
    lpServiceName  XPTR ?
    lpServiceProc  XPTR ?
SERVICE_TABLE_ENTRYA ENDS

SERVICE_TABLE_ENTRYW STRUCT ALIGNMODE
    lpServiceName  XPTR ?
    lpServiceProc  XPTR ?
SERVICE_TABLE_ENTRYW ENDS

INHERITED_FROMA STRUCT ALIGNMODE
    GenerationGap   LONG   ?
    AncestorName    LPTSTR ?
INHERITED_FROMA ENDS

INHERITED_FROMW STRUCT ALIGNMODE
    GenerationGap   LONG   ?
    AncestorName    LPWSTR ?
INHERITED_FROMW ENDS

OBJECTS_AND_SID STRUCT ALIGNMODE
    ObjectsPresent          DD   ?
    ObjectTypeGuid          GUID <>
    InheritedObjectTypeGuid GUID <>
    pSid                    XPTR ?
OBJECTS_AND_SID ENDS

OBJECTS_AND_NAME_A STRUCT ALIGNMODE
    ObjectsPresent          DD     ?
    ObjectType              ENUM   ?
    ObjectTypeName          LPTSTR ?
    InheritedObjectTypeName LPTSTR ?
    ptstrName               LPTSTR ?
OBJECTS_AND_NAME_A ENDS

OBJECTS_AND_NAME_W STRUCT ALIGNMODE
    ObjectsPresent          DD     ?
    ObjectType              ENUM   ?
    ObjectTypeName          LPWSTR ?
    InheritedObjectTypeName LPWSTR ?
    ptstrName               LPWSTR ?
OBJECTS_AND_NAME_W ENDS

TRUSTEE_A STRUCT ALIGNMODE
    pMultipleTrustee         XPTR   ?
    MultipleTrusteeOperation ENUM   ?
    TrusteeForm              ENUM   ?
    TrusteeType              ENUM   ?
    ptstrName                LPTSTR ?
TRUSTEE_A ENDS

TRUSTEE_W STRUCT ALIGNMODE
    pMultipleTrustee         XPTR   ?
    MultipleTrusteeOperation ENUM   ?
    TrusteeForm              ENUM   ?
    TrusteeType              ENUM   ?
    ptstrName                LPWSTR ?
TRUSTEE_W ENDS

EXPLICIT_ACCESSA STRUCT ALIGNMODE
    grfAccessPermissions DD        ?
    grfAccessMode        ENUM      ?
    grfInheritance       DD        ?
    Trustee              TRUSTEE_A <>
EXPLICIT_ACCESSA ENDS
EXPLICIT_ACCESS_A EQU <EXPLICIT_ACCESSA>

EXPLICIT_ACCESSW STRUCT ALIGNMODE
    grfAccessPermissions DD        ?
    grfAccessMode        ENUM      ?
    grfInheritance       DD        ?
    Trustee              TRUSTEE_W <>
EXPLICIT_ACCESSW ENDS
EXPLICIT_ACCESS_W EQU <EXPLICIT_ACCESSW>

ACTRL_ACCESS_ENTRYA STRUCT ALIGNMODE
    Trustee            TRUSTEE_A <>
    fAccessFlags       ULONG     ?
    Access             DD        ?
    ProvSpecificAccess DD        ?
    Inheritance        DD        ?
    lpInheritProperty  LPCTSTR   ?
ACTRL_ACCESS_ENTRYA ENDS

ACTRL_ACCESS_ENTRYW STRUCT ALIGNMODE
    Trustee            TRUSTEE_W <>
    fAccessFlags       ULONG     ?
    Access             DD        ?
    ProvSpecificAccess DD        ?
    Inheritance        DD        ?
    lpInheritProperty  LPCWSTR   ?
ACTRL_ACCESS_ENTRYW ENDS

ACTRL_ACCESS_ENTRY_LISTA STRUCT ALIGNMODE
    cEntries    ULONG ?
    pAccessList XPTR  ?
ACTRL_ACCESS_ENTRY_LISTA ENDS

ACTRL_ACCESS_ENTRY_LISTW STRUCT ALIGNMODE
    cEntries    ULONG ?
    pAccessList XPTR  ?
ACTRL_ACCESS_ENTRY_LISTW ENDS

ACTRL_PROPERTY_ENTRYA STRUCT ALIGNMODE
    lpProperty       LPCTSTR ?
    pAccessEntryList XPTR    ?
    fListFlags       ULONG   ?
ACTRL_PROPERTY_ENTRYA ENDS

ACTRL_PROPERTY_ENTRYW STRUCT ALIGNMODE
    lpProperty       LPCWSTR ?
    pAccessEntryList XPTR    ?
    fListFlags       ULONG   ?
ACTRL_PROPERTY_ENTRYW ENDS

ACTRL_ALISTA STRUCT ALIGNMODE
    cEntries            DD   ?
    pPropertyAccessList XPTR ?
ACTRL_ALISTA ENDS

ACTRL_ALISTW STRUCT ALIGNMODE
    cEntries            DD   ?
    pPropertyAccessList XPTR ?
ACTRL_ALISTW ENDS

TRUSTEE_ACCESSA STRUCT ALIGNMODE
    lpProperty      LPTSTR ?
    Access          DD     ?
    fAccessFlags    ULONG  ?
    fReturnedAccess ULONG  ?
TRUSTEE_ACCESSA ENDS

TRUSTEE_ACCESSW STRUCT ALIGNMODE
    lpProperty      LPWSTR ?
    Access          DD     ?
    fAccessFlags    ULONG  ?
    fReturnedAccess ULONG  ?
TRUSTEE_ACCESSW ENDS

ACTRL_OVERLAPPED STRUCT ALIGNMODE
    UNION
        Provider    PVOID  ?
        Reserved1   ULONG  ?
    ENDS
    Reserved2   ULONG  ?
    hEvent      HANDLE ?
ACTRL_OVERLAPPED ENDS

ACTRL_ACCESS_INFOA STRUCT ALIGNMODE
    fAccessPermission      ULONG ?
    lpAccessPermissionName LPSTR ?
ACTRL_ACCESS_INFOA ENDS

ACTRL_ACCESS_INFOW STRUCT ALIGNMODE
    fAccessPermission      ULONG ?
    lpAccessPermissionName LPWSTR ?
ACTRL_ACCESS_INFOW ENDS

ACTRL_CONTROL_INFOA STRUCT ALIGNMODE
    lpControlId   LPSTR ?
    lpControlName LPSTR ?
ACTRL_CONTROL_INFOA ENDS

ACTRL_CONTROL_INFOW STRUCT ALIGNMODE
    lpControlId   LPWSTR ?
    lpControlName LPWSTR ?
ACTRL_CONTROL_INFOW ENDS

ACTRL_AUDITA STRUCT ALIGNMODE
    cEntries            ULONG ?
    pPropertyAccessList XPTR  ?
ACTRL_AUDITA ENDS

ACTRL_AUDITW STRUCT ALIGNMODE
    cEntries            ULONG ?
    pPropertyAccessList XPTR  ?
ACTRL_AUDITW ENDS

FN_OBJECT_MGR_FUNCTIONS STRUCT ALIGNMODE
    Placeholder DD  ?
FN_OBJECT_MGR_FUNCTIONS ENDS

;======================================== Functions =======================================;
AbortSystemShutdownA PROTO :LPTSTR
AbortSystemShutdownW PROTO :LPWSTR
AccessCheck PROTO :XPTR, :HANDLE, :XWORD, :XPTR, :XPTR, :LPDWORD, :LPDWORD, :LPBOOL
AccessCheckAndAuditAlarmA PROTO :LPCTSTR, :LPVOID, :LPTSTR, :LPTSTR, :XPTR, :XWORD, :XPTR, :XWORD, :LPDWORD, :LPBOOL, :LPBOOL
AccessCheckAndAuditAlarmW PROTO :LPCWSTR, :LPVOID, :LPWSTR, :LPWSTR, :XPTR, :XWORD, :XPTR, :XWORD, :LPDWORD, :LPBOOL, :LPBOOL
AddAccessAllowedAce PROTO :XPTR, :XWORD, :XWORD, :XPTR
AddAccessDeniedAce PROTO :XPTR, :XWORD, :XWORD, :XPTR
AddAce PROTO :XPTR, :XWORD, :XWORD, :LPVOID, :XWORD
AddAuditAccessAce PROTO :XPTR, :XWORD, :XWORD, :XPTR, :XWORD, :XWORD
AdjustTokenGroups PROTO :HANDLE, :XWORD, :XPTR, :XWORD, :XPTR, :XWORD
AdjustTokenPrivileges PROTO :HANDLE, :XWORD, :XPTR, :XWORD, :XPTR, :XWORD
AllocateAndInitializeSid PROTO :XPTR, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XPTR
AllocateLocallyUniqueId PROTO :XPTR
AreAllAccessesGranted PROTO :XWORD, :XWORD
AreAnyAccessesGranted PROTO :XWORD, :XWORD
BackupEventLogA PROTO :HANDLE, :LPCTSTR
BackupEventLogW PROTO :HANDLE, :LPCWSTR
ChangeServiceConfigA PROTO :HANDLE, :XWORD, :XWORD, :XWORD, :LPCTSTR, :LPDWORD, :LPCTSTR, :LPCTSTR, :LPCTSTR, :LPCTSTR
ChangeServiceConfigW PROTO :HANDLE, :XWORD, :XWORD, :XWORD, :LPCWSTR, :LPDWORD, :LPCWSTR, :LPCWSTR, :LPCWSTR, :LPCWSTR
ClearEventLogA PROTO :HANDLE, :LPCTSTR
ClearEventLogW PROTO :HANDLE, :LPCWSTR
CloseEventLog PROTO :HANDLE
CloseServiceHandle PROTO :HANDLE
ControlService PROTO :HANDLE, :XWORD, :XPTR
CopySid PROTO :XWORD, :XPTR, :XPTR
CreatePrivateObjectSecurity PROTO :XPTR, :XPTR, :XPTR, :XWORD, :HANDLE, :XPTR
CreateServiceA PROTO :HANDLE, :LPCTSTR, :LPCTSTR, :XWORD, :XWORD, :XWORD, :XWORD, :LPCTSTR, :LPCTSTR, :LPDWORD, :LPCTSTR, :LPCTSTR, :LPCTSTR
CreateServiceW PROTO :HANDLE, :LPCWSTR, :LPCWSTR, :XWORD, :XWORD, :XWORD, :XWORD, :LPCWSTR, :LPCWSTR, :LPDWORD, :LPCWSTR, :LPCWSTR, :LPCWSTR
IFNDEF CryptAcquireContextA
    CryptAcquireContextA PROTO :XPTR, :LPCTSTR, :LPCTSTR, :XWORD, :XWORD
ENDIF
IFNDEF CryptAcquireContextW
    CryptAcquireContextW PROTO :XPTR, :LPCWSTR, :LPCWSTR, :XWORD, :XWORD
ENDIF
IFNDEF CryptCreateHash
    CryptCreateHash PROTO :HANDLE, :XWORD, :HKEY, :XWORD, :XPTR
ENDIF
IFNDEF CryptDecrypt
    CryptDecrypt PROTO :HANDLE, :HANDLE, :XWORD, :XWORD, :XPTR, :XPTR
ENDIF
IFNDEF CryptDeriveKey
    CryptDeriveKey PROTO :HANDLE, :XWORD, :HANDLE, :XWORD, :XPTR
ENDIF
IFNDEF CryptDestroyHash
    CryptDestroyHash PROTO :HANDLE
ENDIF
IFNDEF CryptDestroyKey
    CryptDestroyKey PROTO :HANDLE
ENDIF
IFNDEF CryptEncrypt
    CryptEncrypt PROTO :HANDLE, :HANDLE, :XWORD, :XWORD, :XPTR, :XPTR, :XWORD
ENDIF
CryptExportKey PROTO :HANDLE, :HANDLE, :XWORD, :XWORD, :XPTR, :XWORD
CryptGenKey PROTO :HANDLE, :XWORD, :XWORD, :XPTR
CryptGenRandom PROTO :HANDLE, :XWORD, :XPTR
CryptGetHashParam PROTO :HANDLE, :XWORD, :XPTR, :XPTR, :XWORD
CryptGetKeyParam PROTO :HANDLE, :XWORD, :XPTR, :XPTR, :XWORD
CryptGetProvParam PROTO :HANDLE, :XWORD, :XPTR, :XPTR, :XWORD
CryptGetUserKey PROTO :HANDLE, :XWORD, :XPTR
IFNDEF CryptHashData
    CryptHashData PROTO :HANDLE, :XPTR, :XWORD, :XWORD
ENDIF
CryptHashSessionKey PROTO :HANDLE, :HANDLE, :XWORD
CryptImportKey PROTO :HANDLE, :XPTR, :XWORD, :XWORD, :XWORD, :XPTR
IFNDEF CryptReleaseContext
    CryptReleaseContext PROTO :HANDLE, :XWORD
ENDIF
CryptSetHashParam PROTO :HANDLE, :XWORD, :XPTR, :XWORD
CryptSetKeyParam PROTO :HANDLE, :XWORD, :XPTR, :XWORD
CryptSetProviderA PROTO :LPCTSTR, :XWORD
CryptSetProviderExA PROTO :LPCTSTR, :XWORD, :XPTR, :XWORD
CryptSetProviderExW PROTO :LPCWSTR, :XWORD, :XPTR, :XWORD
CryptSetProviderW PROTO :LPCWSTR, :XWORD
CryptSetProvParam PROTO :HANDLE, :XWORD, :XPTR, :XWORD
CryptSignHashA PROTO :HANDLE, :XWORD, :LPCTSTR, :XWORD, :XPTR, :XWORD
CryptSignHashW PROTO :HANDLE, :XWORD, :LPCWSTR, :XWORD, :XPTR, :XWORD
CryptVerifySignatureA PROTO :HANDLE, :XPTR, :XWORD, :HANDLE, :LPCTSTR, :XWORD
CryptVerifySignatureW PROTO :HANDLE, :XPTR, :XWORD, :HANDLE, :LPCWSTR, :XWORD
DeleteAce PROTO :XPTR, :XWORD
DeleteService PROTO :HANDLE
DeregisterEventSource PROTO :HANDLE
DestroyPrivateObjectSecurity PROTO :XPTR
DuplicateToken PROTO :HANDLE, :ENUM, :XPTR
EnumDependentServicesA PROTO :HANDLE, :XWORD, :XPTR, :XWORD, :LPDWORD, :LPDWORD
EnumDependentServicesW PROTO :HANDLE, :XWORD, :XPTR, :XWORD, :LPDWORD, :LPDWORD
EnumServicesStatusA PROTO :HANDLE, :XWORD, :XWORD, :XPTR, :XWORD, :LPDWORD, :LPDWORD, :LPDWORD
EnumServicesStatusW PROTO :HANDLE, :XWORD, :XWORD, :XPTR, :XWORD, :LPDWORD, :LPDWORD, :LPDWORD
EqualPrefixSid PROTO :XPTR, :XPTR
EqualSid PROTO :XPTR, :XPTR
FindFirstFreeAce PROTO :XPTR, :LPVOID
FreeSid PROTO :XPTR
GetAce PROTO :XPTR, :XWORD, :LPVOID
GetAclInformation PROTO :XPTR, :LPVOID, :XWORD, :ENUM
GetFileSecurityA PROTO :LPCTSTR, :XWORD, :XPTR, :XWORD, :LPDWORD
GetFileSecurityW PROTO :LPCWSTR, :XWORD, :XPTR, :XWORD, :LPDWORD
GetKernelObjectSecurity PROTO :HANDLE, :XWORD, :XPTR, :XWORD, :LPDWORD
GetLengthSid PROTO :XPTR
GetNumberOfEventLogRecords PROTO :HANDLE, :XPTR
GetOldestEventLogRecord PROTO :HANDLE, :XPTR
GetPrivateObjectSecurity PROTO :XPTR, :XWORD, :XPTR, :XWORD, :XPTR
GetSecurityDescriptorControl PROTO :XPTR, :XPTR, :LPDWORD
GetSecurityDescriptorDacl PROTO :XPTR, :LPBOOL, :XPTR, :LPBOOL
GetSecurityDescriptorGroup PROTO :XPTR, :XPTR, :LPBOOL
GetSecurityDescriptorLength PROTO :XPTR
GetSecurityDescriptorOwner PROTO :XPTR, :XPTR, :LPBOOL
GetSecurityDescriptorSacl PROTO :XPTR, :LPBOOL, :XPTR, :LPBOOL
GetServiceDisplayNameA PROTO :HANDLE, :LPCTSTR, :LPTSTR, :LPDWORD
GetServiceDisplayNameW PROTO :HANDLE, :LPCWSTR, :LPWSTR, :LPDWORD
GetServiceKeyNameA PROTO :HANDLE, :LPCTSTR, :LPTSTR, :LPDWORD
GetServiceKeyNameW PROTO :HANDLE, :LPCWSTR, :LPWSTR, :LPDWORD
GetSidIdentifierAuthority PROTO :XPTR
GetSidLengthRequired PROTO :XWORD
GetSidSubAuthority PROTO :XPTR, :XWORD
GetSidSubAuthorityCount PROTO :XPTR
GetTokenInformation PROTO :HANDLE, :ENUM, :LPVOID, :XWORD, :XPTR
GetUserNameA PROTO :LPTSTR, :LPDWORD
GetUserNameW PROTO :LPWSTR, :LPDWORD
ImpersonateLoggedOnUser PROTO :HANDLE
ImpersonateNamedPipeClient PROTO :HANDLE
ImpersonateSelf PROTO :XWORD
InitializeAcl PROTO :XPTR, :XWORD, :XWORD
InitializeSecurityDescriptor PROTO :XPTR, :XWORD
InitializeSid PROTO :XPTR, :XPTR, :XWORD
InitiateSystemShutdownA PROTO :LPTSTR, :LPTSTR, :XWORD, :XWORD, :XWORD
InitiateSystemShutdownW PROTO :LPWSTR, :LPWSTR, :XWORD, :XWORD, :XWORD
IsTextUnicode PROTO :XPTR, :XWORD, :XPTR
IsValidAcl PROTO :XPTR
IsValidSecurityDescriptor PROTO :XPTR
IsValidSid PROTO :XPTR
LockServiceDatabase PROTO :HANDLE
LogonUserA PROTO :LPTSTR, :LPTSTR, :LPTSTR, :XWORD, :XWORD, :XPTR
LogonUserW PROTO :LPWSTR, :LPWSTR, :LPWSTR, :XWORD, :XWORD, :XPTR
LookupAccountNameA PROTO :LPCTSTR, :LPCTSTR, :XPTR, :LPDWORD, :LPTSTR, :LPDWORD, :XPTR
LookupAccountNameW PROTO :LPCWSTR, :LPCWSTR, :XPTR, :LPDWORD, :LPWSTR, :LPDWORD, :XPTR
LookupAccountSidA PROTO :LPCTSTR, :XPTR, :LPTSTR, :LPDWORD, :LPTSTR, :LPDWORD, :XPTR
LookupAccountSidW PROTO :LPCWSTR, :XPTR, :LPWSTR, :LPDWORD, :LPWSTR, :LPDWORD, :XPTR
LookupPrivilegeDisplayNameA PROTO :LPCTSTR, :LPCTSTR, :LPTSTR, :LPDWORD, :LPDWORD
LookupPrivilegeDisplayNameW PROTO :LPCWSTR, :LPCWSTR, :LPWSTR, :LPDWORD, :LPDWORD
LookupPrivilegeNameA PROTO :LPCTSTR, :XPTR, :LPTSTR, :LPDWORD
LookupPrivilegeNameW PROTO :LPCWSTR, :XPTR, :LPWSTR, :LPDWORD
LookupPrivilegeValueA PROTO :LPCTSTR, :LPCTSTR, :XPTR
LookupPrivilegeValueW PROTO :LPCWSTR, :LPCWSTR, :XPTR
MakeAbsoluteSD PROTO :XPTR, :XPTR, :LPDWORD, :XPTR, :LPDWORD, :XPTR, :LPDWORD, :XPTR, :LPDWORD, :XPTR, :LPDWORD
MakeSelfRelativeSD PROTO :XPTR, :XPTR, :LPDWORD
MapGenericMask PROTO :XPTR, :XPTR
NotifyBootConfigStatus PROTO :XWORD
NotifyChangeEventLog PROTO :HANDLE, :HANDLE
ObjectCloseAuditAlarmA PROTO :LPCTSTR, :LPVOID, :XWORD
ObjectCloseAuditAlarmW PROTO :LPCWSTR, :LPVOID, :XWORD
ObjectOpenAuditAlarmA PROTO :LPCTSTR, :LPVOID, :LPTSTR, :LPTSTR, :XPTR, :HANDLE, :XWORD, :XWORD, :XPTR, :XWORD, :XWORD, :LPBOOL
ObjectOpenAuditAlarmW PROTO :LPCWSTR, :LPVOID, :LPWSTR, :LPWSTR, :XPTR, :HANDLE, :XWORD, :XWORD, :XPTR, :XWORD, :XWORD, :LPBOOL
ObjectPrivilegeAuditAlarmA PROTO :LPCTSTR, :LPVOID, :HANDLE, :XWORD, :XPTR, :XWORD
ObjectPrivilegeAuditAlarmW PROTO :LPCWSTR, :LPVOID, :HANDLE, :XWORD, :XPTR, :XWORD
OpenBackupEventLogA PROTO :LPCTSTR, :LPCTSTR
OpenBackupEventLogW PROTO :LPCWSTR, :LPCWSTR
OpenEventLogA PROTO :LPCTSTR, :LPCTSTR
OpenEventLogW PROTO :LPCWSTR, :LPCWSTR
OpenSCManagerA PROTO :LPCTSTR, :LPCTSTR, :XWORD
OpenSCManagerW PROTO :LPCWSTR, :LPCWSTR, :XWORD
OpenServiceA PROTO :HANDLE, :LPCTSTR, :XWORD
OpenServiceW PROTO :HANDLE, :LPCWSTR, :XWORD
PrivilegeCheck PROTO
PrivilegedServiceAuditAlarmA PROTO :LPCTSTR, :LPCTSTR, :HANDLE, :XPTR, :XWORD
PrivilegedServiceAuditAlarmW PROTO :LPCWSTR, :LPCWSTR, :HANDLE, :XPTR, :XWORD
QueryServiceConfigA PROTO :HANDLE, :XPTR, :XWORD, :LPDWORD
QueryServiceConfigW PROTO :HANDLE, :XPTR, :XWORD, :LPDWORD
QueryServiceLockStatusA PROTO :HANDLE, :XPTR, :XWORD, :LPDWORD
QueryServiceLockStatusW PROTO :HANDLE, :XPTR, :XWORD, :LPDWORD
QueryServiceObjectSecurity PROTO :HANDLE, :XWORD, :XPTR, :XWORD, :LPDWORD
QueryServiceStatus PROTO :HANDLE, :XPTR
ReadEventLogA PROTO :HANDLE, :XWORD, :XWORD, :LPVOID, :XWORD, :XPTR, :XWORD
ReadEventLogW PROTO :HANDLE, :XWORD, :XWORD, :LPVOID, :XWORD, :XPTR, :XWORD
RegConnectRegistryA PROTO :LPCTSTR, :HKEY, :XPTR
RegConnectRegistryW PROTO :LPCWSTR, :HKEY, :XPTR
RegCloseKey PROTO :HKEY
RegCreateKeyA PROTO :HKEY, :LPCTSTR, :XPTR
RegCreateKeyExA PROTO :HKEY, :LPCTSTR, :XWORD, :LPTSTR, :XWORD, :XWORD, :XPTR, :XPTR, :LPDWORD
RegCreateKeyExW PROTO :HKEY, :LPCWSTR, :XWORD, :LPTSTR, :XWORD, :XWORD, :XPTR, :XPTR, :LPDWORD
RegCreateKeyW PROTO :HKEY, :LPCWSTR, :XPTR
RegDeleteKeyA PROTO :HKEY, :LPCTSTR
RegDeleteKeyW PROTO :HKEY, :LPCWSTR
RegDeleteValueA PROTO :HKEY, :LPCTSTR
RegDeleteValueW PROTO :HKEY, :LPCWSTR
RegEnumKeyA PROTO :HKEY, :XWORD, :LPTSTR, :XWORD
RegEnumKeyExA PROTO :HKEY, :XWORD, :LPTSTR, :LPDWORD, :LPDWORD, :LPTSTR, :LPDWORD, :XPTR
RegEnumKeyExW PROTO :HKEY, :XWORD, :LPWSTR, :LPDWORD, :LPDWORD, :LPWSTR, :LPDWORD, :XPTR
RegEnumKeyW PROTO :HKEY, :XWORD, :LPWSTR, :XWORD
RegEnumValueA PROTO :HKEY, :XWORD, :LPTSTR, :LPDWORD, :LPDWORD, :LPDWORD, :LPBYTE, :LPDWORD
RegEnumValueW PROTO :HKEY, :XWORD, :LPWSTR, :LPDWORD, :LPDWORD, :LPDWORD, :LPWORD, :LPDWORD
RegFlushKey PROTO :HKEY
RegGetKeySecurity PROTO :HKEY, :XWORD, :XPTR, :LPDWORD
RegLoadKeyA PROTO :HKEY, :LPCTSTR, :LPCTSTR
RegLoadKeyW PROTO :HKEY, :LPCWSTR, :LPCWSTR
RegNotifyChangeKeyValue PROTO :HKEY, :XWORD, :XWORD, :HANDLE, :XWORD
RegOpenKeyA PROTO :HKEY, :LPCTSTR, :XPTR
RegOpenKeyExA PROTO :HKEY, :LPCTSTR, :XWORD, :XWORD, :XPTR
RegOpenKeyExW PROTO :HKEY, :LPCWSTR, :XWORD, :XWORD, :XPTR
RegOpenKeyW PROTO :HKEY, :LPCWSTR, :XPTR
RegQueryInfoKeyA PROTO :HKEY, :LPTSTR, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD, :XPTR
RegQueryInfoKeyW PROTO :HKEY, :LPWSTR, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD, :LPDWORD, :XPTR
RegQueryMultipleValuesA PROTO :HKEY, :XPTR, :XWORD, :LPTSTR, :LPDWORD
RegQueryMultipleValuesW PROTO :HKEY, :XPTR, :XWORD, :LPWSTR, :LPDWORD
RegQueryValueA PROTO :HKEY, :LPCTSTR, :LPTSTR, :XPTR
RegQueryValueExA PROTO :HKEY, :LPCTSTR, :LPDWORD, :LPDWORD, :LPBYTE, :LPDWORD
RegQueryValueExW PROTO :HKEY, :LPCWSTR, :LPDWORD, :LPDWORD, :LPWORD, :LPDWORD
RegQueryValueW PROTO :HKEY, :LPCWSTR, :LPWSTR, :XPTR
RegReplaceKeyA PROTO :HKEY, :LPCTSTR, :LPCTSTR, :LPCTSTR
RegReplaceKeyW PROTO :HKEY, :LPCWSTR, :LPCWSTR, :LPCWSTR
RegRestoreKeyA PROTO :HKEY, :LPCTSTR, :XWORD
RegRestoreKeyW PROTO :HKEY, :LPCWSTR, :XWORD
RegSaveKeyA PROTO :HKEY, :LPCTSTR, :XPTR
RegSaveKeyW PROTO :HKEY, :LPCWSTR, :XPTR
RegSetKeySecurity PROTO :HKEY, :XWORD, :XPTR
RegSetValueA PROTO :HKEY, :LPCTSTR, :XWORD, :LPCTSTR, :XWORD
RegSetValueExA PROTO :HKEY, :LPCTSTR, :XWORD, :XWORD, :XPTR, :XWORD
RegSetValueExW PROTO :HKEY, :LPCWSTR, :XWORD, :XWORD, :XPTR, :XWORD
RegSetValueW PROTO :HKEY, :LPCWSTR, :XWORD, :LPCWSTR, :XWORD
RegUnLoadKeyA PROTO :HKEY, :LPCTSTR
RegUnLoadKeyW PROTO :HKEY, :LPCWSTR
RegisterEventSourceA PROTO :LPCTSTR, :LPCTSTR
RegisterEventSourceW PROTO :LPCWSTR, :LPCWSTR
RegisterServiceCtrlHandlerA PROTO :LPCTSTR, :XPTR
RegisterServiceCtrlHandlerW PROTO :LPCWSTR, :XPTR
ReportEventA PROTO :HANDLE, :XWORD, :XWORD, :XWORD, :XPTR, :XWORD, :XWORD, :LPCTSTR, :LPVOID
ReportEventW PROTO :HANDLE, :XWORD, :XWORD, :XWORD, :XPTR, :XWORD, :XWORD, :LPCWSTR, :LPVOID
RevertToSelf PROTO
SetAclInformation PROTO :XPTR, :LPVOID, :XWORD, :ENUM
SetFileSecurityA PROTO :LPCTSTR, :XWORD, :XPTR
SetFileSecurityW PROTO :LPCWSTR, :XWORD, :XPTR
SetKernelObjectSecurity PROTO :HANDLE, :XWORD, :XPTR
SetPrivateObjectSecurity PROTO :XWORD, :XPTR, :XPTR, :XPTR, :HANDLE
SetSecurityDescriptorDacl PROTO :XPTR, :XWORD, :XPTR, :XWORD
SetSecurityDescriptorGroup PROTO :XPTR, :XPTR, :XWORD
SetSecurityDescriptorOwner PROTO :XPTR, :XPTR, :XWORD
SetSecurityDescriptorSacl PROTO :XPTR, :XWORD, :XPTR, :XWORD
SetServiceBits PROTO :HANDLE, :XWORD, :XWORD, :XWORD
SetServiceObjectSecurity PROTO :HANDLE, :XWORD, :XPTR
SetServiceStatus PROTO  :HANDLE, :XPTR
SetThreadToken PROTO :XPTR, :HANDLE
SetTokenInformation PROTO :HANDLE, :ENUM, :LPVOID, :XWORD
StartServiceA PROTO :HANDLE, :XWORD, :LPCTSTR
StartServiceCtrlDispatcherA PROTO :XPTR
StartServiceCtrlDispatcherW PROTO :XPTR
StartServiceW PROTO :HANDLE, :XWORD, :LPCWSTR
UnlockServiceDatabase PROTO :XWORD

IF (NTDDI_VERSION GE NTDDI_WIN98_ME)
    BuildExplicitAccessWithNameA PROTO :XPTR, :LPTSTR, :XWORD, :XWORD, :XWORD
    BuildExplicitAccessWithNameW PROTO :XPTR, :LPWSTR, :XWORD, :XWORD, :XWORD
    BuildSecurityDescriptorA PROTO :XPTR, :XPTR, :XWORD, :XPTR, :XWORD, :XPTR, :XPTR, :PULONG, :XPTR
    BuildSecurityDescriptorW PROTO :XPTR, :XPTR, :XWORD, :XPTR, :XWORD, :XPTR, :XPTR, :PULONG, :XPTR
    BuildTrusteeWithNameA PROTO :XPTR, :LPTSTR
    BuildTrusteeWithNameW PROTO :XPTR, :LPWSTR
    BuildTrusteeWithSidA PROTO :XPTR, :XPTR
    BuildTrusteeWithSidW PROTO :XPTR, :XPTR
    ConvertAccessToSecurityDescriptorA PROTO :XPTR, :XPTR, :LPCSTR, :LPCSTR, :XPTR
    ConvertAccessToSecurityDescriptorW PROTO :XPTR, :XPTR, :LPWSTR, :LPWSTR, :XPTR
    ConvertSecurityDescriptorToAccessA PROTO :HANDLE, :XWORD, :XPTR, :XPTR, :XPTR, :LPSTR, :LPSTR
    ConvertSecurityDescriptorToAccessW PROTO :HANDLE, :XWORD, :XPTR, :XPTR, :XPTR, :LPWSTR, :LPWSTR
    ConvertSecurityDescriptorToAccessNamedA PROTO :XPTR, :XWORD, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR
    ConvertSecurityDescriptorToAccessNamedW PROTO :XPTR, :XWORD, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR
    CryptContextAddRef PROTO :HANDLE, :XWORD, :XWORD
    CryptDuplicateHash PROTO :HANDLE, :XPTR, :XWORD, :XPTR
    CryptDuplicateKey PROTO :HANDLE, :XPTR, :XWORD, :XPTR
    CryptEnumProvidersA PROTO :XWORD, :XPTR, :XWORD, :XPTR, :LPTSTR, :XPTR
    CryptEnumProviderTypesA PROTO :XWORD, :XPTR, :XWORD, :XPTR, :LPTSTR, :XPTR
    CryptEnumProviderTypesW PROTO :XWORD, :XPTR, :XWORD, :XPTR, :LPWSTR, :XPTR
    CryptEnumProvidersW PROTO :XWORD, :XPTR, :XWORD, :XPTR, :LPWSTR, :XPTR
    CryptGetDefaultProviderA PROTO :XWORD, :XPTR, :XWORD, :LPTSTR, :XPTR
    CryptGetDefaultProviderW PROTO :XWORD, :XPTR, :XWORD, :LPWSTR, :XPTR
    DuplicateTokenEx PROTO :HANDLE, :XWORD, :XPTR, :ENUM, :ENUM, :XPTR
    GetAccessPermissionsForObjectA PROTO :LPCSTR, :ENUM, :LPCSTR, :LPCSTR, :PULONG, :XPTR, :PULONG, :XPTR, :PULONG
    GetAccessPermissionsForObjectW PROTO :LPWSTR, :ENUM, :LPWSTR, :LPWSTR, :PULONG, :XPTR, :PULONG, :XPTR, :PULONG
    GetAuditedPermissionsFromAclA PROTO :XPTR, :XPTR, :XPTR, :XPTR
    GetAuditedPermissionsFromAclW PROTO :XPTR, :XPTR, :XPTR, :XPTR
    GetCurrentHwProfileA PROTO :XPTR
    GetCurrentHwProfileW PROTO :XPTR
    GetEffectiveRightsFromAclA PROTO :XPTR, :XPTR, :XPTR
    GetEffectiveRightsFromAclW PROTO :XPTR, :XPTR, :XPTR
    GetExplicitEntriesFromAclA PROTO :XPTR, :XPTR, :XPTR
    GetExplicitEntriesFromAclW PROTO :XPTR, :XPTR, :XPTR
    GetMultipleTrusteeA PROTO :XWORD
    GetMultipleTrusteeOperationA PROTO :XWORD
    GetMultipleTrusteeOperationW PROTO :XWORD
    GetMultipleTrusteeW PROTO :XWORD
    GetNamedSecurityInfoA PROTO :LPTSTR, :ENUM, :XWORD, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR
    GetNamedSecurityInfoExA PROTO :LPCTSTR, :ENUM, :XWORD, :LPCTSTR, :LPCTSTR, :XPTR, :XPTR, :LPTSTR, :LPTSTR
    GetNamedSecurityInfoExW PROTO :LPCWSTR, :ENUM, :XWORD, :LPCWSTR, :LPCWSTR, :XPTR, :XPTR, :LPWSTR, :LPWSTR
    GetNamedSecurityInfoW PROTO :LPWSTR, :ENUM, :XWORD, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR
    GetOverlappedAccessResults PROTO :XWORD, :XWORD, :XWORD, :XWORD
    GetSecurityInfo PROTO :HANDLE, :ENUM, :XWORD, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR
    GetSecurityInfoExA PROTO :HANDLE, :ENUM, :XWORD, :LPCSTR, :LPCSTR, :XPTR
    GetSecurityInfoExW PROTO :HANDLE, :ENUM, :XWORD, :LPWSTR, :LPCWSTR, :XPTR
    GetTrusteeNameA PROTO :XPTR
    GetTrusteeNameW PROTO :XPTR
    GetTrusteeTypeA PROTO :XPTR
    GetTrusteeTypeW PROTO :XPTR
    LookupSecurityDescriptorPartsA PROTO :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR
    LookupSecurityDescriptorPartsW PROTO :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR
    ObjectDeleteAuditAlarmA PROTO :LPCTSTR, :LPVOID, :XWORD
    ObjectDeleteAuditAlarmW PROTO :LPCWSTR, :LPVOID, :XWORD
    SetEntriesInAccessListA PROTO :XWORD, :XPTR, :XWORD, :LPCSTR, :XPTR, :XPTR
    SetEntriesInAccessListW PROTO :XWORD, :XPTR, :XWORD, :LPWSTR, :XPTR, :XPTR
    SetEntriesInAclA PROTO :XWORD, :XPTR, :XPTR, :XPTR
    SetEntriesInAclW PROTO :XWORD, :XPTR, :XPTR, :XPTR
    SetEntriesInAuditListA PROTO :XWORD, :XPTR, :XWORD, :LPCSTR, :XPTR, :XPTR
    SetEntriesInAuditListW PROTO :XWORD, :XPTR, :XWORD, :LPWSTR, :XPTR, :XPTR
    SetNamedSecurityInfoA PROTO :LPTSTR, :ENUM, :XWORD, :XPTR, :XPTR, :XPTR, :XPTR
    SetNamedSecurityInfoExA PROTO :LPTSTR, :ENUM, :XWORD, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR
    SetNamedSecurityInfoExW PROTO :LPWSTR, :ENUM, :XWORD, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR
    SetNamedSecurityInfoW PROTO :LPWSTR, :ENUM, :XWORD, :XPTR, :XPTR, :XPTR, :XPTR
    SetSecurityInfo PROTO :HANDLE, :ENUM, :XWORD, :XPTR, :XPTR, :XPTR, :XPTR
    SetSecurityInfoExA PROTO :HANDLE, :ENUM, :XWORD, :LPCSTR, :XPTR, :XPTR, :LPSTR, :LPSTR, :XPTR
    SetSecurityInfoExW PROTO :HANDLE, :ENUM, :XWORD, :LPWSTR, :XPTR, :XPTR, :LPWSTR, :LPWSTR, :XPTR
    TrusteeAccessToObjectA PROTO :LPCTSTR, :ENUM, :LPCTSTR, :XPTR, :XWORD, :XPTR
    TrusteeAccessToObjectW PROTO :LPCWSTR, :ENUM, :LPCWSTR, :XPTR, :XWORD, :XPTR
    IFDEF APP_UNICODE
        BuildExplicitAccessWithName EQU <BuildExplicitAccessWithNameW>
        BuildSecurityDescriptor EQU <BuildSecurityDescriptorW>
        BuildTrusteeWithName EQU <BuildTrusteeWithNameW>
        BuildTrusteeWithSid EQU <BuildTrusteeWithSidW>
        ConvertAccessToSecurityDescriptor EQU <ConvertAccessToSecurityDescriptorW>
        ConvertSecurityDescriptorToAccess EQU <ConvertSecurityDescriptorToAccessW>
        ConvertSecurityDescriptorToAccessNamed EQU <ConvertSecurityDescriptorToAccessNamedW>
        CryptEnumProviders EQU <CryptEnumProvidersW>
        CryptEnumProviderTypes EQU <CryptEnumProviderTypesW>
        CryptGetDefaultProvider EQU <CryptGetDefaultProviderW>
        GetAccessPermissionsForObject EQU <GetAccessPermissionsForObjectW>
        GetAuditedPermissionsFromAcl EQU <GetAuditedPermissionsFromAclW>
        GetCurrentHwProfile EQU <GetCurrentHwProfileW>
        GetEffectiveRightsFromAcl EQU <GetEffectiveRightsFromAclW>
        GetExplicitEntriesFromAcl EQU <GetExplicitEntriesFromAclW>
        GetMultipleTrustee EQU <GetMultipleTrusteeW>
        GetMultipleTrusteeOperation EQU <GetMultipleTrusteeOperationW>
        GetNamedSecurityInfo EQU <GetNamedSecurityInfoW>
        GetNamedSecurityInfoEx EQU <GetNamedSecurityInfoExW>
        GetSecurityInfoEx EQU <GetSecurityInfoExW>
        GetTrusteeName EQU <GetTrusteeNameW>
        GetTrusteeType EQU <GetTrusteeTypeW>
        LookupSecurityDescriptorParts EQU <LookupSecurityDescriptorPartsW>
        ObjectDeleteAuditAlarm EQU <ObjectDeleteAuditAlarmW>
        SetEntriesInAccessList EQU <SetEntriesInAccessListW>
        SetEntriesInAcl EQU <SetEntriesInAclW>
        SetEntriesInAuditList EQU <SetEntriesInAuditListW>
        SetNamedSecurityInfo EQU <SetNamedSecurityInfoW>
        SetNamedSecurityInfoEx EQU <SetNamedSecurityInfoExW>
        SetSecurityInfoEx EQU <SetSecurityInfoExW>
        TrusteeAccessToObject EQU <TrusteeAccessToObjectW>
    ELSE
        BuildExplicitAccessWithName EQU <BuildExplicitAccessWithNameA>
        BuildSecurityDescriptor EQU <BuildSecurityDescriptorA>
        BuildTrusteeWithName EQU <BuildTrusteeWithNameA>
        BuildTrusteeWithSid EQU <BuildTrusteeWithSidA>
        ConvertAccessToSecurityDescriptor EQU <ConvertAccessToSecurityDescriptorA>
        ConvertSecurityDescriptorToAccess EQU <ConvertSecurityDescriptorToAccessA>
        ConvertSecurityDescriptorToAccessNamed EQU <ConvertSecurityDescriptorToAccessNamedA>
        CryptEnumProviders EQU <CryptEnumProvidersA>
        CryptEnumProviderTypes EQU <CryptEnumProviderTypesA>
        CryptGetDefaultProvider EQU <CryptGetDefaultProviderA>
        GetAccessPermissionsForObject EQU <GetAccessPermissionsForObjectA>
        GetAuditedPermissionsFromAcl EQU <GetAuditedPermissionsFromAclA>
        GetCurrentHwProfile EQU <GetCurrentHwProfileA>
        GetEffectiveRightsFromAcl EQU <GetEffectiveRightsFromAclA>
        GetExplicitEntriesFromAcl EQU <GetExplicitEntriesFromAclA>
        GetMultipleTrustee EQU <GetMultipleTrusteeA>
        GetMultipleTrusteeOperation EQU <GetMultipleTrusteeOperationA>
        GetNamedSecurityInfo EQU <GetNamedSecurityInfoA>
        GetNamedSecurityInfoEx EQU <GetNamedSecurityInfoExA>
        GetSecurityInfoEx EQU <GetSecurityInfoExA>
        GetTrusteeName EQU <GetTrusteeNameA>
        GetTrusteeType EQU <GetTrusteeTypeA>
        LookupSecurityDescriptorParts EQU <LookupSecurityDescriptorPartsA>
        ObjectDeleteAuditAlarm EQU <ObjectDeleteAuditAlarmA>
        SetEntriesInAccessList EQU <SetEntriesInAccessListA>
        SetEntriesInAcl EQU <SetEntriesInAclA>
        SetEntriesInAuditList EQU <SetEntriesInAuditListA>
        SetNamedSecurityInfo EQU <SetNamedSecurityInfoA>
        SetNamedSecurityInfoEx EQU <SetNamedSecurityInfoExA>
        SetSecurityInfoEx EQU <SetSecurityInfoExA>
        TrusteeAccessToObject EQU <TrusteeAccessToObjectA>
    ENDIF
ENDIF

IF (NTDDI_VERSION GE NTDDI_WINNT4)
    CreateProcessAsUserA PROTO :HANDLE, :LPCTSTR, :LPTSTR, :XPTR, :XPTR, :XWORD, :XWORD, :LPVOID, :LPCTSTR, :XPTR, :XPTR
    CreateProcessAsUserW PROTO :HANDLE, :LPCTSTR, :LPTSTR, :XPTR, :XPTR, :XWORD, :XWORD, :LPVOID, :LPCTSTR, :XPTR, :XPTR
    ElfBackupEventLogFileA PROTO :HANDLE, :XPTR
    ElfBackupEventLogFileW PROTO :HANDLE, :XPTR
    ElfChangeNotify PROTO :HANDLE, :HANDLE
    ElfClearEventLogFileA PROTO :HANDLE, :XPTR
    ElfClearEventLogFileW PROTO :HANDLE, :XPTR
    ElfCloseEventLog PROTO :HANDLE
    ElfDeregisterEventSource PROTO :HANDLE
    ElfNumberOfRecords PROTO :HANDLE, :XPTR
    ElfOldestRecord PROTO :HANDLE, :XPTR
    ElfOpenBackupEventLogA PROTO :XPTR, :XPTR, :XPTR
    ElfOpenBackupEventLogW PROTO :XPTR, :XPTR, :XPTR
    ElfOpenEventLogA PROTO :XPTR, :XPTR, :XPTR
    ElfOpenEventLogW PROTO :XPTR, :XPTR, :XPTR
    ElfReadEventLogA PROTO :HANDLE, :XWORD, :XWORD, :PVOID, :XWORD, :PULONG, :PULONG
    ElfReadEventLogW PROTO :HANDLE, :XWORD, :XWORD, :PVOID, :XWORD, :PULONG, :PULONG
    ElfRegisterEventSourceA PROTO :XPTR, :XPTR, :XPTR
    ElfRegisterEventSourceW PROTO :XPTR, :XPTR, :XPTR
    ElfReportEventA PROTO :HANDLE, :XWORD, :XWORD, :XWORD, :XPTR, :XWORD, :XWORD, :XPTR, :PVOID, :XWORD, :PULONG, :PULONG
    ElfReportEventW PROTO :HANDLE, :XWORD, :XWORD, :XWORD, :XPTR, :XWORD, :XWORD, :XPTR, :PVOID, :XWORD, :PULONG, :PULONG
    EnumServiceGroupW PROTO :HANDLE, :XWORD, :XWORD, :XPTR, :XWORD, :LPDWORD, :LPDWORD, :LPDWORD, :LPCWSTR
    EnumServicesStatusExA PROTO :HANDLE, :ENUM, :XWORD, :XWORD, :XPTR, :XWORD, :LPDWORD, :LPDWORD, :LPDWORD, :LPCTSTR
    EnumServicesStatusExW PROTO :HANDLE, :ENUM, :XWORD, :XWORD, :XPTR, :XWORD, :LPDWORD, :LPDWORD, :LPDWORD, :LPCWSTR
    IsTokenUntrusted PROTO :HANDLE
    LsaAddAccountRights PROTO :HANDLE, :XPTR, :XPTR, :XWORD
    LsaAddPrivilegesToAccount PROTO :HANDLE, :XPTR
    LsaClearAuditLog PROTO :HANDLE
    LsaClose PROTO :HANDLE
    LsaCreateAccount PROTO :HANDLE, :XPTR, :XWORD, :XPTR
    LsaCreateSecret PROTO :HANDLE, :XPTR, :XWORD, :XPTR
    LsaCreateTrustedDomain PROTO :HANDLE, :XPTR, :XWORD, :XPTR
    LsaDelete PROTO :HANDLE
    LsaDeleteTrustedDomain PROTO :HANDLE, :XPTR
    LsaEnumerateAccountRights PROTO :HANDLE, :XPTR, :XPTR, :PULONG
    LsaEnumerateAccounts PROTO :HANDLE, :XPTR, :XPTR, :XWORD, :XPTR
    LsaEnumerateAccountsWithUserRight PROTO :HANDLE, :XPTR, :PVOID, :PULONG
    LsaEnumeratePrivileges PROTO :HANDLE, :XPTR, :PVOID, :XWORD, :PULONG
    LsaEnumeratePrivilegesOfAccount PROTO :HANDLE, :XPTR
    LsaEnumerateTrustedDomains PROTO :HANDLE, :XPTR, :PVOID, :XWORD, :PULONG
    LsaFreeMemory PROTO :PVOID
    LsaGetQuotasForAccount PROTO :HANDLE, :XPTR
    LsaGetRemoteUserName PROTO :XPTR, :XPTR, :XPTR
    LsaGetSystemAccessAccount PROTO :HANDLE, :PULONG
    LsaGetUserName PROTO :XPTR, :XPTR
    LsaLookupNames PROTO :HANDLE, :XWORD, :XPTR, :XPTR, :XPTR
    LsaLookupPrivilegeDisplayName PROTO :HANDLE, :XPTR, :XPTR, :XPTR
    LsaLookupPrivilegeName PROTO :HANDLE, :XPTR, :XPTR
    LsaLookupPrivilegeValue PROTO :HANDLE, :XPTR, :XPTR
    LsaLookupSids PROTO :HANDLE, :XWORD, :XPTR, :XPTR, :XPTR
    LsaNtStatusToWinError PROTO :XWORD
    LsaOpenAccount PROTO :HANDLE, :XPTR, :XWORD, :XPTR
    LsaOpenPolicy PROTO :XPTR, :XPTR, :XWORD, :XPTR
    LsaOpenSecret PROTO :HANDLE, :XPTR, :XWORD, :XPTR
    LsaOpenTrustedDomain PROTO :HANDLE, :XPTR, :XWORD, :XPTR
    LsaOpenTrustedDomainByName PROTO :HANDLE, :XPTR, :XWORD, :XPTR
    LsaQueryInformationPolicy PROTO :HANDLE, :ENUM, :PVOID
    LsaQuerySecret PROTO :HANDLE, :XPTR, :XPTR, :XPTR, :XPTR
    LsaQuerySecurityObject PROTO :HANDLE, :XWORD, :XPTR
    LsaQueryTrustedDomainInfo PROTO :HANDLE, :XPTR, :ENUM, :PVOID
    LsaRemoveAccountRights PROTO :HANDLE, :XPTR, :XWORD, :XPTR, :XWORD
    LsaRemovePrivilegesFromAccount PROTO :HANDLE, :XWORD, :XPTR
    LsaRetrievePrivateData PROTO :HANDLE, :XPTR, :XPTR
    LsaSetInformationPolicy PROTO :HANDLE, :XWORD, :PVOID
    LsaSetInformationTrustedDomain PROTO :HANDLE, :XWORD, :PVOID
    LsaSetQuotasForAccount PROTO :HANDLE, :XPTR
    LsaSetSecret PROTO :HANDLE, :XPTR, :XPTR
    LsaSetSecurityObject PROTO :HANDLE, :XWORD, :XPTR
    LsaSetSystemAccessAccount PROTO :HANDLE, :XWORD
    LsaSetTrustedDomainInformation PROTO :HANDLE, :XPTR, :ENUM, :PVOID
    LsaStorePrivateData PROTO :HANDLE, :XPTR, :XPTR
    OpenProcessToken PROTO :HANDLE, :XWORD, :XPTR
    OpenThreadToken PROTO :HANDLE, :XWORD, :XWORD, :XPTR
    IFDEF APP_UNICODE
        CreateProcessAsUser EQU <CreateProcessAsUserW>
        ElfBackupEventLogFile EQU <ElfBackupEventLogFileW>
        ElfClearEventLogFile EQU <ElfClearEventLogFileW>
        ElfOpenBackupEventLog EQU <ElfOpenBackupEventLogW>
        ElfOpenEventLog EQU <ElfOpenEventLogW>
        ElfReadEventLog EQU <ElfReadEventLogW>
        ElfRegisterEventSource EQU <ElfRegisterEventSourceW>
        ElfReportEvent EQU <ElfReportEventW>
        EnumServicesStatusEx EQU <EnumServicesStatusExW>
    ELSE
        CreateProcessAsUser EQU <CreateProcessAsUserA>
        ElfBackupEventLogFile EQU <ElfBackupEventLogFileA>
        ElfClearEventLogFile EQU <ElfClearEventLogFileA>
        ElfOpenBackupEventLog EQU <ElfOpenBackupEventLogA>
        ElfOpenEventLog EQU <ElfOpenEventLogA>
        ElfReadEventLog EQU <ElfReadEventLogA>
        ElfRegisterEventSource EQU <ElfRegisterEventSourceA>
        ElfReportEvent EQU <ElfReportEventA>
        EnumServicesStatusEx EQU <EnumServicesStatusExA>
    ENDIF
ENDIF

IF (NTDDI_VERSION GE NTDDI_WIN2K)
    AccessCheckByType PROTO :XPTR, :XPTR, :HANDLE, :XWORD, :XPTR, :XWORD, :XPTR, :XPTR, :LPDWORD, :LPDWORD, :LPBOOL
    AccessCheckByTypeAndAuditAlarmA PROTO :LPCTSTR, :LPVOID, :LPCTSTR, :LPCTSTR, :XPTR, :XPTR, :XWORD, :XWORD, :XWORD, :XPTR, :XWORD, :XPTR, :XWORD, :LPDWORD, :LPBOOL, :LPBOOL
    AccessCheckByTypeAndAuditAlarmW PROTO :LPCWSTR, :LPVOID, :LPCWSTR, :LPCWSTR, :XPTR, :XPTR, :XWORD, :XWORD, :XWORD, :XPTR, :XWORD, :XPTR, :XWORD, :LPDWORD, :LPBOOL, :LPBOOL
    AccessCheckByTypeResultList PROTO :XPTR, :XPTR, :HANDLE, :XWORD, :XPTR, :XWORD, :XPTR, :XPTR, :LPDWORD, :LPDWORD, :LPDWORD
    AccessCheckByTypeResultListAndAuditAlarmA PROTO :LPCTSTR, :LPVOID, :LPCTSTR, :LPCTSTR, :XPTR, :XPTR, :XWORD, :XWORD, :XWORD, :XPTR, :XWORD, :XPTR, :XWORD, :LPDWORD, :LPDWORD, :LPBOOL
    AccessCheckByTypeResultListAndAuditAlarmW PROTO :LPCWSTR, :LPVOID, :LPCWSTR, :LPCWSTR, :XPTR, :XPTR, :XWORD, :XWORD, :XWORD, :XPTR, :XWORD, :XPTR, :XWORD, :LPDWORD, :LPDWORD, :LPBOOL
    AccessCheckByTypeResultListAndAuditAlarmByHandleA PROTO :LPCTSTR, :LPVOID, :HANDLE, :LPCTSTR, :LPCTSTR, :XPTR, :XPTR, :XWORD, :XWORD, :XWORD, :XPTR, :XWORD, :XPTR, :XWORD, :LPDWORD, :LPDWORD, :LPBOOL
    AccessCheckByTypeResultListAndAuditAlarmByHandleW PROTO :LPCWSTR, :LPVOID, :HANDLE, :LPCWSTR, :LPCWSTR, :XPTR, :XPTR, :XWORD, :XWORD, :XWORD, :XPTR, :XWORD, :XPTR, :XWORD, :LPDWORD, :LPDWORD, :LPBOOL
    AddAccessAllowedAceEx PROTO :XPTR, :XWORD, :XWORD, :XWORD, :XPTR
    AddAccessAllowedObjectAce PROTO :XPTR, :XWORD, :XWORD, :XWORD, :XPTR, :XPTR, :XPTR
    AddAccessDeniedAceEx PROTO :XPTR, :XWORD, :XWORD, :XWORD, :XPTR
    AddAccessDeniedObjectAce PROTO :XPTR, :XWORD, :XWORD, :XWORD, :XPTR, :XPTR, :XPTR
    AddAuditAccessAceEx PROTO :XPTR, :XWORD, :XWORD, :XWORD, :XPTR, :XWORD, :XWORD
    AddAuditAccessObjectAce PROTO :XPTR, :XWORD, :XWORD, :XWORD, :XPTR, :XPTR, :XPTR, :XWORD, :XWORD
    AddUsersToEncryptedFile PROTO :LPCWSTR, :XPTR
    BuildTrusteeWithObjectsAndNameA PROTO :XPTR, :XPTR, :XWORD, :LPSTR, :LPSTR, :LPSTR
    BuildTrusteeWithObjectsAndNameW PROTO :XPTR, :XPTR, :XWORD, :LPWSTR, :LPWSTR, :LPWSTR
    BuildTrusteeWithObjectsAndSidA PROTO :XPTR, :XPTR, :XPTR, :XPTR, :XPTR
    BuildTrusteeWithObjectsAndSidW PROTO :XPTR, :XPTR, :XPTR, :XPTR, :XPTR
    CheckTokenMembership PROTO :HANDLE, :XPTR, :XPTR
    CloseEncryptedFileRaw PROTO :PVOID
    CloseTrace PROTO :HANDLE
    CommandLineFromMsiDescriptor PROTO :XPTR, :XPTR, :XPTR
    ControlTraceA PROTO :HANDLE, :XPTR, :XWORD
    ControlTraceW PROTO :HANDLE, :XPTR, :XWORD
    ConvertSDToStringSDRootDomainA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    ConvertSDToStringSDRootDomainW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    ConvertSecurityDescriptorToStringSecurityDescriptorA PROTO :XPTR, :XWORD, :XWORD
    ConvertSecurityDescriptorToStringSecurityDescriptorW PROTO :XPTR, :XWORD, :XWORD
    ConvertSidToStringSidA PROTO :XPTR, :LPTSTR
    ConvertSidToStringSidW PROTO :XPTR, :LPWSTR
    ConvertStringSDToSDRootDomainA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    ConvertStringSDToSDRootDomainW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    ConvertStringSecurityDescriptorToSecurityDescriptorA PROTO :LPCTSTR, :XWORD, :XPTR, :PULONG
    ConvertStringSecurityDescriptorToSecurityDescriptorW PROTO :LPCWSTR, :XWORD, :XPTR, :PULONG
    ConvertStringSidToSidA PROTO :LPCTSTR, :XPTR
    ConvertStringSidToSidW PROTO :LPCWSTR, :XPTR
    ConvertToAutoInheritPrivateObjectSecurity PROTO :XPTR, :XPTR, :XPTR, :XPTR, :XWORD, :XPTR
    CreatePrivateObjectSecurityEx PROTO :XPTR, :XPTR, :XPTR, :XPTR, :XWORD, :XWORD, :HANDLE, :XPTR
    CreateProcessWithLogonW PROTO :LPCWSTR, :LPCWSTR, :LPCWSTR, :XWORD, :LPCWSTR, :LPWSTR, :XWORD, :LPVOID, :LPCWSTR, :XPTR, :XPTR
    CreateRestrictedToken PROTO :HANDLE, :XWORD, :XWORD, :XPTR, :XWORD, :XPTR, :XWORD, :XPTR, :XPTR
    CreateTraceInstanceId PROTO :HANDLE, :XPTR
    CreateWellKnownSid PROTO :ENUM, :XPTR, :XPTR, :XWORD
    EnableTrace PROTO :XWORD, :XWORD, :XWORD, :XPTR, :HANDLE
    EncryptFileA PROTO :LPCTSTR
    EncryptFileW PROTO :LPCWSTR
    EncryptionDisable PROTO :LPCWSTR, :XWORD
    EqualDomainSid PROTO :XPTR, :XPTR, :XPTR
    FileEncryptionStatusA PROTO :LPCTSTR, :LPDWORD
    FileEncryptionStatusW PROTO :LPCWSTR, :LPDWORD
    FreeEncryptionCertificateHashList PROTO :XPTR
    GetEventLogInformation PROTO :HANDLE, :XWORD, :LPVOID, :XWORD, :LPDWORD
    GetLocalManagedApplications PROTO :XWORD, :LPDWORD, :XPTR
    GetManagedApplications PROTO :XPTR, :XWORD, :XWORD, :LPDWORD, :XPTR
    ImpersonateAnonymousToken PROTO :HANDLE
    InitiateSystemShutdownExA PROTO :LPTSTR, :LPTSTR, :XWORD, :XWORD, :XWORD, :XWORD
    InitiateSystemShutdownExW PROTO :LPWSTR, :LPWSTR, :XWORD, :XWORD, :XWORD, :XWORD
    InstallApplication PROTO :XPTR
    IsTokenRestricted PROTO :HANDLE
    LsaCreateTrustedDomainEx PROTO :HANDLE, :XPTR, :XPTR
    LsaEnumerateTrustedDomainsEx PROTO :HANDLE, :XPTR, :PVOID, :XWORD, :PULONG
    LsaOpenPolicySce PROTO :XPTR, :XPTR, :XWORD, :XPTR
    LsaQueryDomainInformationPolicy PROTO :HANDLE, :ENUM, :PVOID
    LsaQueryInfoTrustedDomain PROTO :XWORD, :XWORD, :XWORD
    LsaQueryTrustedDomainInfoByName PROTO :HANDLE, :XPTR, :XWORD, :PVOID
    LsaSetDomainInformationPolicy PROTO :HANDLE, :ENUM, :PVOID
    LsaSetTrustedDomainInfoByName PROTO :HANDLE, :XPTR, :XWORD, :PVOID
    MakeAbsoluteSD2 PROTO :XPTR, :LPDWORD
    OpenEncryptedFileRawA PROTO :LPCTSTR, :XWORD, :PVOID
    OpenEncryptedFileRawW PROTO :LPCWSTR, :XWORD, :PVOID
    OpenTraceA PROTO :XPTR
    OpenTraceW PROTO :XPTR
    QueryAllTracesA PROTO :XPTR, :XWORD, :PULONG
    QueryAllTracesW PROTO :XPTR, :XWORD, :PULONG
    QueryRecoveryAgentsOnEncryptedFile PROTO :LPCWSTR, :XPTR
    QueryServiceConfig2A PROTO :HANDLE, :XWORD, :LPBYTE, :XWORD, :LPDWORD
    QueryServiceConfig2W PROTO :HANDLE, :XWORD, :LPBYTE, :XWORD, :LPDWORD
    QueryServiceStatusEx PROTO :HANDLE, :XWORD, :LPBYTE, :XWORD, :LPDWORD
    QueryUsersOnEncryptedFile PROTO :LPCWSTR, :XPTR
    ReadEncryptedFileRaw PROTO :XPTR, :PVOID, :PVOID
    RegDisablePredefinedCache PROTO
    RegOpenCurrentUser PROTO :XWORD, :XPTR
    RegOpenUserClassesRoot PROTO :HANDLE, :XWORD, :XWORD, :XPTR
    RegOverridePredefKey PROTO :HKEY, :HKEY
    RegisterServiceCtrlHandlerExA PROTO :LPCTSTR, :XPTR, :LPVOID
    RegisterServiceCtrlHandlerExW PROTO :LPCWSTR, :XPTR, :LPVOID
    RegisterTraceGuidsA PROTO :XPTR, :PVOID, :XPTR, :XWORD, :XPTR, :LPCTSTR, :LPCTSTR, :XPTR
    RegisterTraceGuidsW PROTO :XPTR, :PVOID, :XPTR, :XWORD, :XPTR, :LPCWSTR, :LPCWSTR, :XPTR
    RemoveUsersFromEncryptedFile PROTO :LPCWSTR, :XPTR
    RemoveTraceCallback PROTO :XPTR
    SetPrivateObjectSecurityEx PROTO :XWORD, :XPTR, :XPTR, :XWORD, :XPTR, :HANDLE
    SetSecurityDescriptorControl PROTO :XPTR, :XWORD, :XWORD
    SetSecurityDescriptorRMControl PROTO :XPTR, :XPTR
    SetTraceCallback PROTO :XPTR, :XPTR
    SetUserFileEncryptionKey PROTO :XPTR
    StartTraceA PROTO :XPTR, :LPCTSTR, :XPTR
    StartTraceW PROTO :XPTR, :LPCWSTR, :XPTR
    TraceEvent PROTO :HANDLE, :XPTR
    TraceEventInstance PROTO :HANDLE, :XPTR, :XPTR, :XPTR
    UninstallApplication PROTO :XPTR, :XWORD
    UnregisterTraceGuids PROTO :HANDLE
    WmiCloseBlock PROTO :XWORD
    WmiEnumerateGuids PROTO :XWORD, :XWORD
    WmiDevInstToInstanceNameA PROTO :XWORD, :XWORD, :XWORD, :XWORD
    WmiDevInstToInstanceNameW PROTO :XWORD, :XWORD, :XWORD, :XWORD
    WmiExecuteMethodA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    WmiExecuteMethodW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    WmiFileHandleToInstanceNameA PROTO :XWORD, :XWORD, :XWORD, :XWORD
    WmiFileHandleToInstanceNameW PROTO :XWORD, :XWORD, :XWORD, :XWORD
    WmiFreeBuffer PROTO :XWORD
    WmiMofEnumerateResourcesA PROTO :XWORD, :XWORD, :XWORD
    WmiMofEnumerateResourcesW PROTO :XWORD, :XWORD, :XWORD
    WmiNotificationRegistrationA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    WmiNotificationRegistrationW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    WmiOpenBlock PROTO :XWORD, :XWORD, :XWORD
    WmiQueryAllDataA PROTO :XWORD, :XWORD, :XWORD
    WmiQueryAllDataW PROTO :XWORD, :XWORD, :XWORD
    WmiQueryGuidInformation PROTO :XWORD, :XWORD
    WmiQuerySingleInstanceA PROTO :XWORD, :XWORD, :XWORD, :XWORD
    WmiQuerySingleInstanceW PROTO :XWORD, :XWORD, :XWORD, :XWORD
    WmiSetSingleInstanceA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    WmiSetSingleInstanceW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    WmiSetSingleItemA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    WmiSetSingleItemW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    WriteEncryptedFileRaw PROTO :XPTR, :PVOID, :PVOID
    IFDEF APP_UNICODE
        AccessCheckByTypeAndAuditAlarm EQU <AccessCheckByTypeAndAuditAlarmW>
        AccessCheckByTypeResultListAndAuditAlarm EQU <AccessCheckByTypeResultListAndAuditAlarmW>
        AccessCheckByTypeResultListAndAuditAlarmByHandle EQU <AccessCheckByTypeResultListAndAuditAlarmByHandleW>
        BuildTrusteeWithObjectsAndName EQU <BuildTrusteeWithObjectsAndNameW>
        BuildTrusteeWithObjectsAndSid EQU <BuildTrusteeWithObjectsAndSidW>
        ControlTrace EQU <ControlTraceW>
        ConvertSDToStringSDRootDomain EQU <ConvertSDToStringSDRootDomainW>
        ConvertSecurityDescriptorToStringSecurityDescriptor EQU <ConvertSecurityDescriptorToStringSecurityDescriptorW>
        ConvertSidToStringSid EQU <ConvertSidToStringSidW>
        ConvertStringSDToSDRootDomain EQU <ConvertStringSDToSDRootDomainW>
        ConvertStringSecurityDescriptorToSecurityDescriptor EQU <ConvertStringSecurityDescriptorToSecurityDescriptorW>
        ConvertStringSidToSid EQU <ConvertStringSidToSidW>
        EncryptFile EQU <EncryptFileW>
        FileEncryptionStatus EQU <FileEncryptionStatusW>
        InitiateSystemShutdownEx EQU <InitiateSystemShutdownExW>
        OpenEncryptedFileRaw EQU <OpenEncryptedFileRawW>
        OpenTrace EQU <OpenTraceW>
        QueryAllTraces EQU <QueryAllTracesW>
        QueryServiceConfig2 EQU <QueryServiceConfig2W>
        RegisterServiceCtrlHandlerEx EQU <RegisterServiceCtrlHandlerExW>
        RegisterTraceGuids EQU <RegisterTraceGuidsW>
        StartTrace EQU <StartTraceW>
        WmiDevInstToInstanceName EQU <WmiDevInstToInstanceNameW>
        WmiExecuteMethod EQU <WmiExecuteMethodW>
        WmiFileHandleToInstanceName EQU <WmiFileHandleToInstanceNameW>
        WmiMofEnumerateResources EQU <WmiMofEnumerateResourcesW>
        WmiNotificationRegistration EQU <WmiNotificationRegistrationW>
        WmiQueryAllData EQU <WmiQueryAllDataW>
        WmiQuerySingleInstance EQU <WmiQuerySingleInstanceW>
        WmiSetSingleInstance EQU <WmiSetSingleInstanceW>
        WmiSetSingleItem EQU <WmiSetSingleItemW>
    ELSE
        AccessCheckByTypeAndAuditAlarm EQU <AccessCheckByTypeAndAuditAlarmA>
        AccessCheckByTypeResultListAndAuditAlarm EQU <AccessCheckByTypeResultListAndAuditAlarmA>
        AccessCheckByTypeResultListAndAuditAlarmByHandle EQU <AccessCheckByTypeResultListAndAuditAlarmByHandleA>
        BuildTrusteeWithObjectsAndName EQU <BuildTrusteeWithObjectsAndNameA>
        BuildTrusteeWithObjectsAndSid EQU <BuildTrusteeWithObjectsAndSidA>
        ControlTrace EQU <ControlTraceA>
        ConvertSDToStringSDRootDomain EQU <ConvertSDToStringSDRootDomainA>
        ConvertSecurityDescriptorToStringSecurityDescriptor EQU <ConvertSecurityDescriptorToStringSecurityDescriptorA>
        ConvertSidToStringSid EQU <ConvertSidToStringSidA>
        ConvertStringSDToSDRootDomain EQU <ConvertStringSDToSDRootDomainA>
        ConvertStringSecurityDescriptorToSecurityDescriptor EQU <ConvertStringSecurityDescriptorToSecurityDescriptorA>
        ConvertStringSidToSid EQU <ConvertStringSidToSidA>
        EncryptFile EQU <EncryptFileA>
        FileEncryptionStatus EQU <FileEncryptionStatusA>
        InitiateSystemShutdownEx EQU <InitiateSystemShutdownExA>
        OpenEncryptedFileRaw EQU <OpenEncryptedFileRawA>
        OpenTrace EQU <OpenTraceA>
        QueryAllTraces EQU <QueryAllTracesA>
        QueryServiceConfig2 EQU <QueryServiceConfig2A>
        RegisterServiceCtrlHandlerEx EQU <RegisterServiceCtrlHandlerExA>
        RegisterTraceGuids EQU <RegisterTraceGuidsA>
        StartTrace EQU <StartTraceA>
        WmiDevInstToInstanceName EQU <WmiDevInstToInstanceNameA>
        WmiExecuteMethod EQU <WmiExecuteMethodA>
        WmiFileHandleToInstanceName EQU <WmiFileHandleToInstanceNameA>
        WmiMofEnumerateResources EQU <WmiMofEnumerateResourcesA>
        WmiNotificationRegistration EQU <WmiNotificationRegistrationA>
        WmiQueryAllData EQU <WmiQueryAllDataA>
        WmiQuerySingleInstance EQU <WmiQuerySingleInstanceA>
        WmiSetSingleInstance EQU <WmiSetSingleInstanceA>
        WmiSetSingleItem EQU <WmiSetSingleItemA>
    ENDIF
ENDIF

IF (NTDDI_VERSION GE NTDDI_WINXP)
    A_SHAFinal PROTO :XPTR, :XPTR
    A_SHAInit PROTO :XPTR
    A_SHAUpdate PROTO :XPTR, :XPTR, :XWORD
    ChangeServiceConfig2A PROTO :HANDLE, :XWORD, :LPVOID
    ChangeServiceConfig2W PROTO :HANDLE, :XWORD, :LPVOID
    ConvertStringSDToSDDomainA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    ConvertStringSDToSDDomainW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    CreatePrivateObjectSecurityWithMultipleInheritance PROTO :XPTR, :XPTR, :XPTR, :XPTR, :XWORD, :XWORD, :XWORD, :HANDLE, :XPTR
    CredDeleteA PROTO :LPCTSTR, :XWORD, :XWORD
    CredDeleteW PROTO :LPCWSTR, :XWORD, :XWORD
    CredEnumerateA PROTO :LPCTSTR, :XWORD, :XPTR, :XPTR
    CredEnumerateW PROTO :LPCWSTR, :XWORD, :XPTR, :XPTR
    CredFree PROTO :XPTR
    CredGetSessionTypes PROTO :XWORD, :LPDWORD
    CredGetTargetInfoA PROTO :LPCTSTR, :XWORD, :XPTR
    CredGetTargetInfoW PROTO :LPCWSTR, :XWORD, :XPTR
    CredIsMarshaledCredentialA PROTO :LPCTSTR
    CredIsMarshaledCredentialW PROTO :LPCWSTR
    CredMarshalCredentialA PROTO :XWORD, :PVOID, :LPCTSTR
    CredMarshalCredentialW PROTO :XWORD, :PVOID, :LPCWSTR
    CredReadA PROTO :LPCTSTR, :XWORD, :XWORD, :XPTR
    CredReadW PROTO :LPCWSTR, :XWORD, :XWORD, :XPTR
    CredReadDomainCredentialsA PROTO :XPTR, :XWORD, :XPTR, :XPTR
    CredReadDomainCredentialsW PROTO :XPTR, :XWORD, :XPTR, :XPTR
    CredRenameA PROTO :LPCTSTR, :LPCTSTR, :XWORD, :XWORD
    CredRenameW PROTO :LPCWSTR, :LPCWSTR, :XWORD, :XWORD
    CredUnmarshalCredentialA PROTO :LPCTSTR, :XWORD, :PVOID
    CredUnmarshalCredentialW PROTO :LPCWSTR, :XWORD, :PVOID
    CredWriteA PROTO :XPTR, :XWORD
    CredWriteW PROTO :XPTR, :XWORD
    CredWriteDomainCredentialsA PROTO :XPTR, :XPTR, :XWORD
    CredWriteDomainCredentialsW PROTO :XPTR, :XPTR, :XWORD
    DecryptFileA PROTO :LPCTSTR, :XWORD
    DecryptFileW PROTO :LPCWSTR, :XWORD
    DuplicateEncryptionInfoFile PROTO :LPCTSTR, :LPCTSTR, :XWORD, :XWORD, :XPTR
    EnumerateTraceGuids PROTO :XPTR, :XWORD, :PULONG
    FlushTraceA PROTO :HANDLE, :LPCTSTR, :XPTR
    FlushTraceW PROTO :HANDLE, :LPCWSTR, :XPTR
    FreeInheritedFromArray PROTO :XPTR, :XWORD, :XPTR
    GetInheritanceSourceA PROTO :LPTSTR, :ENUM, :XWORD, :XWORD, :XPTR, :XWORD, :XPTR, :XPTR, :XPTR, :XPTR
    GetInheritanceSourceW PROTO :LPWSTR, :ENUM, :XWORD, :XWORD, :XPTR, :XWORD, :XPTR, :XPTR, :XPTR, :XPTR
    GetLocalManagedApplicationData PROTO :XPTR, :LPWSTR, :LPWSTR
    GetManagedApplicationCategories PROTO :XWORD, :XPTR
    GetSecurityDescriptorRMControl PROTO :XPTR, :XPTR
    GetTraceEnableFlags PROTO :HANDLE
    GetTraceEnableLevel PROTO :HANDLE
    GetTraceLoggerHandle PROTO :PVOID
    GetTrusteeFormA PROTO :XPTR
    GetTrusteeFormW PROTO :XPTR
    GetWindowsAccountDomainSid PROTO :XPTR, :XPTR, :XPTR
    IsWellKnownSid PROTO :XPTR, :ENUM
    LogonUserExA PROTO :LPTSTR, :LPTSTR, :LPTSTR, :XWORD, :XWORD, :XPTR, :XPTR, :PVOID, :LPDWORD, :XPTR
    LogonUserExExW PROTO :LPTSTR, :LPTSTR, :LPTSTR, :XWORD, :XWORD, :XPTR, :XPTR, :XPTR, :PVOID, :LPDWORD, :XPTR
    LogonUserExW PROTO :LPWSTR, :LPWSTR, :LPWSTR, :XWORD, :XWORD, :XPTR, :XPTR, :PVOID, :LPDWORD, :XPTR
    LsaLookupNames2 PROTO :HANDLE, :XWORD, :XWORD, :XPTR, :XPTR, :XPTR
    LsaQueryForestTrustInformation PROTO :HANDLE, :XPTR, :XPTR
    LsaSetForestTrustInformation PROTO :HANDLE, :XPTR, :XPTR, :XWORD, :XPTR
    MSChapSrvChangePassword PROTO :XPTR, :XPTR, :XWORD, :XPTR, :XPTR, :XPTR, :XPTR
    MSChapSrvChangePassword2 PROTO :XPTR, :XPTR, :XPTR, :XPTR, :XWORD, :XPTR, :XPTR
    ProcessTrace PROTO :XPTR, :XWORD, :XPTR, :XPTR
    QueryTraceA PROTO :HANDLE, :LPCTSTR, :XPTR
    QueryTraceW PROTO :HANDLE, :LPCWSTR, :XPTR
    RegDisablePredefinedCacheEx PROTO
    RegSaveKeyExA PROTO :HKEY, :LPCTSTR, :XPTR, :XWORD
    RegSaveKeyExW PROTO :HKEY, :LPCWSTR, :XPTR, :XWORD
    SaferCloseLevel PROTO :HANDLE
    SaferComputeTokenFromLevel PROTO :HANDLE, :HANDLE, :XPTR, :XWORD, :LPVOID
    SaferCreateLevel PROTO :XWORD, :XWORD, :XWORD, :XPTR
    SaferGetLevelInformation PROTO :HANDLE, :ENUM, :LPVOID, :XWORD, :LPDWORD
    SaferGetPolicyInformation PROTO :XWORD, :ENUM, :XWORD, :PVOID, :XPTR, :LPVOID
    SaferIdentifyLevel PROTO :XWORD, :XPTR, :XPTR, :LPVOID
    SaferRecordEventLogEntry PROTO :HANDLE, :LPCWSTR, :LPVOID
    SaferSetLevelInformation PROTO :HANDLE, :ENUM, :LPVOID, :XWORD
    SaferSetPolicyInformation PROTO :XWORD, :ENUM, :XWORD, :PVOID, :LPVOID
    SaferiIsExecutableFileType PROTO :LPCWSTR, :XWORD
    SaferiSearchMatchingHashRules PROTO :XWORD, :XPTR, :XWORD, :XWORD, :XPTR, :XPTR
    SetEncryptedFileMetadata PROTO :LPCWSTR, :XPTR, :XPTR, :XPTR, :XWORD, :XPTR
    StopTraceA PROTO :HANDLE, :LPCTSTR, :XPTR
    StopTraceW PROTO :HANDLE, :LPCWSTR, :XPTR
    TraceMessage PROTO :HANDLE, :XWORD, :XPTR, :XWORD
    TraceMessageVa PROTO :HANDLE, :XWORD, :XPTR, :XWORD, :XPTR
    TreeResetNamedSecurityInfoA PROTO :LPTSTR, :ENUM, :XWORD, :XPTR, :XPTR, :XPTR, :XPTR, :XWORD, :XPTR, :ENUM, :PVOID
    TreeResetNamedSecurityInfoW PROTO :LPWSTR, :ENUM, :XWORD, :XPTR, :XPTR, :XPTR, :XPTR, :XWORD, :XPTR, :ENUM, :PVOID
    UpdateTraceA PROTO :HANDLE, :LPCTSTR, :XPTR
    UpdateTraceW PROTO :HANDLE, :LPCWSTR, :XPTR
    WmiQueryAllDataMultipleA PROTO :XWORD, :XWORD, :XWORD, :XWORD
    WmiQueryAllDataMultipleW PROTO :XWORD, :XWORD, :XWORD, :XWORD
    WmiQuerySingleInstanceMultipleA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    WmiQuerySingleInstanceMultipleW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    WmiReceiveNotificationsA PROTO :XWORD, :XWORD, :XWORD, :XWORD
    WmiReceiveNotificationsW PROTO :XWORD, :XWORD, :XWORD, :XWORD
    IFDEF APP_UNICODE
        ChangeServiceConfig2 EQU <ChangeServiceConfig2W>
        ConvertStringSDToSDDomain EQU <ConvertStringSDToSDDomainW>
        CredDelete EQU <CredDeleteW>
        CredEnumerate EQU <CredEnumerateW>
        CredGetTargetInfo EQU <CredGetTargetInfoW>
        CredIsMarshaledCredential EQU <CredIsMarshaledCredentialW>
        CredMarshalCredential EQU <CredMarshalCredentialW>
        CredRead EQU <CredReadW>
        CredReadDomainCredentials EQU <CredReadDomainCredentialsW>
        CredRename EQU <CredRenameW>
        CredUnmarshalCredential EQU <CredUnmarshalCredentialW>
        CredWrite EQU <CredWriteW>
        CredWriteDomainCredentials EQU <CredWriteDomainCredentialsW>
        DecryptFile EQU <DecryptFileW>
        FlushTrace EQU <FlushTraceW>
        GetInheritanceSource EQU <GetInheritanceSourceW>
        GetTrusteeForm EQU <GetTrusteeFormW>
        LogonUserEx EQU <LogonUserExW>
        QueryTrace EQU <QueryTraceW>
        RegSaveKeyEx EQU <RegSaveKeyExW>
        StopTrace EQU <StopTraceW>
        TreeResetNamedSecurityInfo EQU <TreeResetNamedSecurityInfoW>
        UpdateTrace EQU <UpdateTraceW>
        WmiQueryAllDataMultiple EQU <WmiQueryAllDataMultipleW>
        WmiQuerySingleInstanceMultiple EQU <WmiQuerySingleInstanceMultipleW>
        WmiReceiveNotifications EQU <WmiReceiveNotificationsW>
    ELSE
        ChangeServiceConfig2 EQU <ChangeServiceConfig2A>
        ConvertStringSDToSDDomain EQU <ConvertStringSDToSDDomainA>
        CredDelete EQU <CredDeleteA>
        CredEnumerate EQU <CredEnumerateA>
        CredGetTargetInfo EQU <CredGetTargetInfoA>
        CredIsMarshaledCredential EQU <CredIsMarshaledCredentialA>
        CredMarshalCredential EQU <CredMarshalCredentialA>
        CredRead EQU <CredReadA>
        CredReadDomainCredentials EQU <CredReadDomainCredentialsA>
        CredRename EQU <CredRenameA>
        CredUnmarshalCredential EQU <CredUnmarshalCredentialA>
        CredWrite EQU <CredWriteA>
        CredWriteDomainCredentials EQU <CredWriteDomainCredentialsA>
        DecryptFile EQU <DecryptFileA>
        FlushTrace EQU <FlushTraceA>
        GetInheritanceSource EQU <GetInheritanceSourceA>
        GetTrusteeForm EQU <GetTrusteeFormA>
        LogonUserEx EQU <LogonUserExA>
        QueryTrace EQU <QueryTraceA>
        RegSaveKeyEx EQU <RegSaveKeyExA>
        StopTrace EQU <StopTraceA>
        TreeResetNamedSecurityInfo EQU <TreeResetNamedSecurityInfoA>
        UpdateTrace EQU <UpdateTraceA>
        WmiQueryAllDataMultiple EQU <WmiQueryAllDataMultipleA>
        WmiQuerySingleInstanceMultiple EQU <WmiQuerySingleInstanceMultipleA>
        WmiReceiveNotifications EQU <WmiReceiveNotificationsA>
    ENDIF
ENDIF

IF (NTDDI_VERSION GE NTDDI_WS03)
    CreateProcessWithTokenW PROTO :HANDLE, :XWORD, :LPCWSTR, :LPWSTR, :XWORD, :LPVOID, :LPCWSTR, :XPTR, :XPTR
ENDIF

IF (NTDDI_VERSION GE NTDDI_VISTA)
    AddMandatoryAce PROTO :XPTR, :XWORD, :XWORD, :XWORD, :XPTR, :XPTR, :XPTR, :XWORD, :XWORD
    AuditComputeEffectivePolicyBySid PROTO :XPTR, :XPTR, :XWORD, :XPTR
    AuditComputeEffectivePolicyByToken PROTO :HANDLE, :XPTR, :XWORD, :XPTR
    AuditEnumerateCategories PROTO :XPTR, :XPTR
    AuditEnumeratePerUserPolicy PROTO :XPTR
    AuditEnumerateSubCategories PROTO :XPTR, :XWORD, :XPTR, :XPTR
    AuditFree PROTO :PVOID
    AuditLookupCategoryGuidFromCategoryId PROTO :ENUM, :XPTR
    AuditLookupCategoryIdFromCategoryGuid PROTO :XPTR, :XPTR
    AuditLookupCategoryNameA PROTO :XPTR, :XPTR
    AuditLookupCategoryNameW PROTO :XPTR, :XPTR
    AuditLookupSubCategoryNameA PROTO :XPTR, :XPTR
    AuditLookupSubCategoryNameW PROTO :XPTR, :XPTR
    AuditQueryPerUserPolicy PROTO :XPTR, :XPTR, :XWORD, :XPTR
    AuditQuerySecurity PROTO :XWORD, :XPTR
    AuditQuerySystemPolicy PROTO :XPTR, :XWORD, :XPTR
    AuditSetPerUserPolicy PROTO :XPTR, :XPTR, :XWORD
    AuditSetSecurity PROTO :XWORD, :XPTR
    AuditSetSystemPolicy PROTO :XPTR, :XWORD
    CloseThreadWaitChainSession PROTO :HANDLE
    ControlServiceExA PROTO :HANDLE, :XWORD, :XWORD, :PVOID
    ControlServiceExW PROTO :HANDLE, :XWORD, :XWORD, :PVOID
    CredFindBestCredentialA PROTO :LPCTSTR, :XWORD, :XWORD, :XPTR
    CredFindBestCredentialW PROTO :LPCWSTR, :XWORD, :XWORD, :XPTR
    CredIsProtectedA PROTO :LPTSTR, :XPTR
    CredIsProtectedW PROTO :LPTSTR, :XPTR
    CredProtectA PROTO :XWORD, :LPTSTR, :XWORD, :LPTSTR, :XPTR, :XPTR
    CredProtectW PROTO :XWORD, :LPWSTR, :XWORD, :LPWSTR, :XPTR, :XPTR
    CredUnprotectA PROTO :XWORD, :LPTSTR, :XWORD, :LPTSTR, :XWORD
    CredUnprotectW PROTO :XWORD, :LPWSTR, :XWORD, :LPWSTR, :XWORD
    EnumerateTraceGuidsEx PROTO :ENUM, :PVOID, :XWORD, :PVOID, :XWORD, :PULONG
    EventAccessControl PROTO :XPTR, :XWORD, :XPTR, :XWORD, :XWORD
    EventAccessQuery PROTO :XPTR, :XPTR, :XPTR
    EventAccessRemove PROTO :XPTR
    EventActivityIdControl PROTO :XWORD, :XPTR
    EventEnabled PROTO :HANDLE, :XPTR
    EventProviderEnabled PROTO :HANDLE, :XWORD, :XWORD
    EventRegister PROTO :XPTR, :XPTR, :PVOID, :XPTR
    EventUnregister PROTO :HANDLE
    EventWrite PROTO :HANDLE, :XPTR, :XWORD, :XPTR
    EventWriteString PROTO :HANDLE, :XWORD, :XWORD, :XPTR
    EventWriteTransfer PROTO :HANDLE, :XPTR, :XPTR, :XPTR, :XWORD, :XPTR
    FlushEfsCache PROTO :PVOID
    FreeEncryptedFileMetadata PROTO :XPTR
    GetEncryptedFileMetadata PROTO :LPCWSTR, :XPTR, :XPTR
    GetThreadWaitChain PROTO :HANDLE, :XWORD, :XWORD, :XWORD, :LPDWORD, :XPTR, :LPBOOL
    I_QueryTagInformation PROTO :PVOID, :XWORD, :XPTR
    InitiateShutdownA PROTO :LPTSTR, :LPTSTR, :XWORD, :XWORD, :XWORD
    InitiateShutdownW PROTO :LPWSTR, :LPWSTR, :XWORD, :XWORD, :XWORD
    LsaManageSidNameMapping PROTO :XWORD, :XPTR, :XPTR
    NotifyServiceStatusChangeA PROTO :HANDLE, :XWORD, :XPTR
    NotifyServiceStatusChangeW PROTO :HANDLE, :XWORD, :XPTR
    OpenThreadWaitChainSession PROTO :XWORD, :XPTR
    PerfCreateInstance PROTO :HANDLE, :XPTR, :LPCWSTR, :XWORD
    PerfDecrementULongCounterValue PROTO :HANDLE, :XPTR, :XWORD, :XWORD
    PerfDecrementULongLongCounterValue PROTO :HANDLE, :XPTR, :XWORD, :XWORD
    PerfDeleteInstance PROTO :HANDLE, :XPTR
    PerfIncrementULongCounterValue PROTO :HANDLE, :XPTR, :XWORD, :XWORD
    PerfIncrementULongLongCounterValue PROTO :HANDLE, :XPTR, :XWORD, :XWORD
    PerfQueryInstance PROTO :HANDLE, :XPTR, :LPCWSTR, :XWORD
    PerfSetCounterRefValue PROTO :HANDLE, :XPTR, :XWORD, :PVOID
    PerfSetCounterSetInfo PROTO :HANDLE, :XPTR, :XWORD
    PerfSetULongCounterValue PROTO :HANDLE, :XPTR, :XWORD, :XWORD
    PerfSetULongLongCounterValue PROTO :HANDLE, :XPTR, :XWORD, :XWORD
    PerfStartProvider PROTO :HANDLE, :XPTR, :XPTR
    PerfStartProviderEx PROTO :XPTR, :XPTR, :XPTR
    PerfStopProvider PROTO :HANDLE
    QuerySecurityAccessMask PROTO :XWORD, :LPDWORD
    RegConnectRegistryExA PROTO :LPCSTR, :HKEY, :XWORD, :XWORD, :XPTR
    RegConnectRegistryExW PROTO :LPWSTR, :HKEY, :XWORD, :XWORD, :XPTR
    RegCopyTreeA PROTO :HKEY, :LPCTSTR, :HKEY
    RegCopyTreeW PROTO :HKEY, :LPCWSTR, :HKEY
    RegCreateKeyTransactedA PROTO :HKEY, :LPCTSTR, :XWORD, :LPTSTR, :XWORD, :XWORD, :XPTR, :XPTR, :LPDWORD, :HANDLE, :PVOID
    RegCreateKeyTransactedW PROTO :HKEY, :LPCWSTR, :XWORD, :LPTSTR, :XWORD, :XWORD, :XPTR, :XPTR, :LPDWORD, :HANDLE, :PVOID
    RegDeleteKeyExA PROTO :HKEY, :LPCTSTR, :XWORD, :XWORD
    RegDeleteKeyExW PROTO :HKEY, :LPCWSTR, :XWORD, :XWORD
    RegDeleteKeyTransactedA PROTO :HKEY, :LPCTSTR, :XWORD, :XWORD, :HANDLE, :PVOID
    RegDeleteKeyTransactedW PROTO :HKEY, :LPCWSTR, :XWORD, :XWORD, :HANDLE, :PVOID
    RegDeleteKeyValueA PROTO :HKEY, :LPCTSTR, :LPCTSTR
    RegDeleteKeyValueW PROTO :HKEY, :LPCWSTR, :LPCWSTR
    RegDeleteTreeA PROTO :HKEY, :LPCTSTR
    RegDeleteTreeW PROTO :HKEY, :LPCWSTR
    RegDisableReflectionKey PROTO :HKEY
    RegEnableReflectionKey PROTO :HKEY
    RegGetValueA PROTO :HKEY, :LPCTSTR, :LPCTSTR, :XWORD, :LPDWORD, :PVOID, :LPDWORD
    RegGetValueW PROTO :HKEY, :LPCWSTR, :LPCWSTR, :XWORD, :LPDWORD, :PVOID, :LPDWORD
    RegLoadAppKeyA PROTO :LPCTSTR, :XPTR, :XWORD, :XWORD, :XWORD
    RegLoadAppKeyW PROTO :LPCWSTR, :XPTR, :XWORD, :XWORD, :XWORD
    RegLoadMUIStringA PROTO :HKEY, :LPCTSTR, :LPTSTR, :XWORD, :LPDWORD, :XWORD, :LPCTSTR
    RegLoadMUIStringW PROTO :HKEY, :LPCWSTR, :LPWSTR, :XWORD, :LPDWORD, :XWORD, :LPCWSTR
    RegOpenKeyTransactedA PROTO :HKEY, :LPCTSTR, :XWORD, :XWORD, :XPTR, :HANDLE, :PVOID
    RegOpenKeyTransactedW PROTO :HKEY, :LPCWSTR, :XWORD, :XWORD, :XPTR, :HANDLE, :PVOID
    RegQueryReflectionKey PROTO :HKEY, :LPBOOL
    RegSetKeyValueA PROTO :HKEY, :LPCTSTR, :LPCTSTR, :XWORD, :LPCVOID, :XWORD
    RegSetKeyValueW PROTO :HKEY, :LPCWSTR, :LPCWSTR, :XWORD, :LPCVOID, :XWORD
    RegisterWaitChainCOMCallback PROTO :XPTR, :XPTR
    SetSecurityAccessMask PROTO :XWORD, :LPDWORD
    SetUserFileEncryptionKeyEx PROTO :XPTR, :XWORD, :XWORD, :LPVOID
    TreeSetNamedSecurityInfoA PROTO :LPTSTR, :ENUM, :XWORD, :XPTR, :XPTR, :XPTR, :XPTR, :XWORD, :XPTR, :ENUM, :PVOID
    TreeSetNamedSecurityInfoW PROTO :LPWSTR, :ENUM, :XWORD, :XPTR, :XPTR, :XPTR, :XPTR, :XWORD, :XPTR, :ENUM, :PVOID
    IFDEF APP_UNICODE
        AuditLookupCategoryName EQU <AuditLookupCategoryNameW>
        AuditLookupSubCategoryName EQU <AuditLookupSubCategoryNameW>
        ControlServiceEx EQU <ControlServiceExW>
        CredFindBestCredential EQU <CredFindBestCredentialW>
        CredIsProtected EQU <CredIsProtectedW>
        CredProtect EQU <CredProtectW>
        CredUnprotect EQU <CredUnprotectW>
        InitiateShutdown EQU <InitiateShutdownW>
        NotifyServiceStatusChange EQU <NotifyServiceStatusChangeW>
        RegConnectRegistryEx EQU <RegConnectRegistryExW>
        RegCopyTree EQU <RegCopyTreeW>
        RegCreateKeyTransacted EQU <RegCreateKeyTransactedW>
        RegDeleteKeyEx EQU <RegDeleteKeyExW>
        RegDeleteKeyTransacted EQU <RegDeleteKeyTransactedW>
        RegDeleteKeyValue EQU <RegDeleteKeyValueW>
        RegDeleteTree EQU <RegDeleteTreeW>
        RegGetValue EQU <RegGetValueW>
        RegLoadAppKey EQU <RegLoadAppKeyW>
        RegLoadMUIString EQU <RegLoadMUIStringW>
        RegOpenKeyTransacted EQU <RegOpenKeyTransactedW>
        RegSetKeyValue EQU <RegSetKeyValueW>
        TreeSetNamedSecurityInfo EQU <TreeSetNamedSecurityInfoW>
    ELSE
        AuditLookupCategoryName EQU <AuditLookupCategoryNameA>
        AuditLookupSubCategoryName EQU <AuditLookupSubCategoryNameA>
        ControlServiceEx EQU <ControlServiceExA>
        CredFindBestCredential EQU <CredFindBestCredentialA>
        CredIsProtected EQU <CredIsProtectedA>
        CredProtect EQU <CredProtectA>
        CredUnprotect EQU <CredUnprotectW>
        InitiateShutdown EQU <InitiateShutdownA>
        NotifyServiceStatusChange EQU <NotifyServiceStatusChangeA>
        RegConnectRegistryEx EQU <RegConnectRegistryExA>
        RegCopyTree EQU <RegCopyTreeA>
        RegCreateKeyTransacted EQU <RegCreateKeyTransactedA>
        RegDeleteKeyEx EQU <RegDeleteKeyExA>
        RegDeleteKeyTransacted EQU <RegDeleteKeyTransactedA>
        RegDeleteKeyValue EQU <RegDeleteKeyValueA>
        RegDeleteTree EQU <RegDeleteTreeA>
        RegGetValue EQU <RegGetValueA>
        RegLoadAppKey EQU <RegLoadAppKeyA>
        RegLoadMUIString EQU <RegLoadMUIStringA>
        RegOpenKeyTransacted EQU <RegOpenKeyTransactedA>
        RegSetKeyValue EQU <RegSetKeyValueA>
        TreeSetNamedSecurityInfo EQU <TreeSetNamedSecurityInfoA>
    ENDIF
ENDIF

IF (NTDDI_VERSION GE NTDDI_WIN7)
    AddConditionalAce PROTO :XPTR, :XWORD, :XWORD, :XWORD, :XWORD, :XPTR, :XPTR, :XPTR
    AuditQueryGlobalSaclA PROTO :XPTR, :XPTR
    AuditQueryGlobalSaclW PROTO :XPTR, :XPTR
    AuditSetGlobalSaclA PROTO :XPTR, :XPTR
    AuditSetGlobalSaclW PROTO :XPTR, :XPTR
    CredReadByTokenHandle PROTO :XPTR
    EnableTraceEx PROTO :XPTR, :XPTR, :HANDLE, :XPTR, :XPTR, :XWORD, :XWORD, :XWORD, :XPTR
    EnableTraceEx2 PROTO :HANDLE, :XPTR, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XPTR
    EventWriteEx PROTO :HANDLE, :XPTR, :XWORD, :XWORD, :XPTR, :XPTR, :XWORD, :XPTR
    TraceSetInformation PROTO :HANDLE, :ENUM, :PVOID, :XWORD
    IFDEF APP_UNICODE
        AuditQueryGlobalSacl EQU <AuditQueryGlobalSaclW>
        AuditSetGlobalSacl EQU <AuditSetGlobalSaclW>
    ELSE
        AuditQueryGlobalSacl EQU <AuditQueryGlobalSaclA>
        AuditSetGlobalSacl EQU <AuditSetGlobalSaclA>
    ENDIF
ENDIF

IF (NTDDI_VERSION GE NTDDI_WIN8)
    BaseRegCloseKey PROTO :HKEY
    BaseRegCreateKey PROTO :HKEY, :XPTR, :XPTR, :XWORD, :XWORD, :XPTR, :XPTR, :LPDWORD
    BaseRegDeleteKeyEx PROTO :HKEY, :XPTR, :XWORD, :XWORD
    BaseRegDeleteValue PROTO :HKEY, :XPTR
    BaseRegFlushKey PROTO :HKEY
    BaseRegGetVersion PROTO :HKEY, :LPDWORD
    BaseRegLoadKey PROTO :HKEY, :XPTR, :XPTR
    BaseRegOpenKey PROTO :HKEY, :XPTR, :XWORD, :XWORD, :XPTR
    BaseRegRestoreKey PROTO :HKEY, :XPTR, :XWORD
    BaseRegSaveKeyEx PROTO :HKEY, :XPTR, :XPTR, :XWORD
    BaseRegSetKeySecurity PROTO :HKEY, :XWORD, :XPTR
    BaseRegSetValue PROTO :HKEY, :XPTR, :XWORD, :LPBYTE, :XWORD
    BaseRegUnLoadKey PROTO :HKEY, :XPTR
    EnumDynamicTimeZoneInformation PROTO :XWORD, :XPTR
    EventSetInformation PROTO :HANDLE, :ENUM, :PVOID, :XWORD
    GetDynamicTimeZoneInformationEffectiveYears PROTO :XPTR, :LPDWORD, :LPDWORD
    LsaGetAppliedCAPIDs PROTO :XPTR, :XPTR, :XPTR
    LsaLookupSids2 PROTO :HANDLE, :XWORD, :XWORD, :XPTR, :XPTR, :XPTR
    LsaQueryCAPs PROTO :XPTR, :XWORD, :XPTR, :PULONG
    LsaSetCAPs PROTO :XPTR, :XWORD, :XWORD
    OperationEnd PROTO :XPTR
    OperationStart PROTO :XPTR
    QueryServiceDynamicInformation PROTO :HANDLE, :XWORD, :PVOID
    TraceQueryInformation PROTO :HANDLE, :ENUM, :PVOID, :XWORD, :PULONG
ENDIF

IFDEF APP_UNICODE
    ACCCTRL_DEFAULT_PROVIDER EQU <ACCCTRL_DEFAULT_PROVIDERW>
    SERVICES_ACTIVE_DATABASE EQU <SERVICES_ACTIVE_DATABASEW>
    SERVICES_FAILED_DATABASE EQU <SERVICES_FAILED_DATABASEW>
    SC_GROUP_IDENTIFIER EQU <SC_GROUP_IDENTIFIERW>
    SERVICE_DESCRIPTION EQU <SERVICE_DESCRIPTIONW>
    SERVICE_FAILURE_ACTIONS EQU <SERVICE_FAILURE_ACTIONSW>
    QUERY_SERVICE_LOCK_STATUS EQU <QUERY_SERVICE_LOCK_STATUSW>
    QUERY_SERVICE_CONFIG EQU <QUERY_SERVICE_CONFIGW>
    SERVICE_TABLE_ENTRY EQU <SERVICE_TABLE_ENTRYW>
    ENUM_SERVICE_STATUS EQU <ENUM_SERVICE_STATUSW>
    ENUM_SERVICE_STATUS_PROCESS EQU <ENUM_SERVICE_STATUS_PROCESSW>
    INHERITED_FROM EQU <INHERITED_FROMW>
    OBJECTS_AND_NAME EQU <OBJECTS_AND_NAME_W>
    TRUSTEE EQU <TRUSTEE_W>
    EXPLICIT_ACCESS EQU <EXPLICIT_ACCESSW>
    ACTRL_ACCESS_ENTRY EQU <ACTRL_ACCESS_ENTRYW>
    ACTRL_ACCESS_ENTRY_LIST EQU <ACTRL_ACCESS_ENTRY_LISTW>
    ACTRL_PROPERTY_ENTRY EQU <ACTRL_PROPERTY_ENTRYW>
    ACTRL_ALIST EQU <ACTRL_ALISTW>
    TRUSTEE_ACCESS EQU <TRUSTEE_ACCESSW>
    ACTRL_ACCESS_INFO EQU <ACTRL_ACCESS_INFOW>
    ACTRL_CONTROL_INFO EQU <ACTRL_CONTROL_INFOW>
    ACTRL_AUDIT EQU <ACTRL_AUDITW>
    AbortSystemShutdown EQU <AbortSystemShutdownW>
    AccessCheckAndAuditAlarm EQU <AccessCheckAndAuditAlarmW>
    BackupEventLog EQU <BackupEventLogW>
    ChangeServiceConfig EQU <ChangeServiceConfigW>
    ClearEventLog EQU <ClearEventLogW>
    CreateService EQU <CreateServiceW>
    IFNDEF CryptAcquireContext
        CryptAcquireContext EQU <CryptAcquireContextW>
    ENDIF
    CryptSetProvider EQU <CryptSetProviderW>
    CryptSetProviderEx EQU <CryptSetProviderExW>
    CryptSignHash EQU <CryptSignHashW>
    CryptVerifySignature EQU <CryptVerifySignatureW>
    EnumDependentServices EQU <EnumDependentServicesW>
    EnumServicesStatus EQU <EnumServicesStatusW>
    GetFileSecurity EQU <GetFileSecurityW>
    GetServiceDisplayName EQU <GetServiceDisplayNameW>
    GetServiceKeyName EQU <GetServiceKeyNameW>
    GetUserName EQU <GetUserNameW>
    InitiateSystemShutdown EQU <InitiateSystemShutdownW>
    LogonUser EQU <LogonUserW>
    LookupAccountName EQU <LookupAccountNameW>
    LookupAccountSid EQU <LookupAccountSidW>
    LookupPrivilegeDisplayName EQU <LookupPrivilegeDisplayNameW>
    LookupPrivilegeName EQU <LookupPrivilegeNameW>
    LookupPrivilegeValue EQU <LookupPrivilegeValueW>
    ObjectCloseAuditAlarm EQU <ObjectCloseAuditAlarmW>
    ObjectOpenAuditAlarm EQU <ObjectOpenAuditAlarmW>
    ObjectPrivilegeAuditAlarm EQU <ObjectPrivilegeAuditAlarmW>
    OpenBackupEventLog EQU <OpenBackupEventLogW>
    OpenEventLog EQU <OpenEventLogW>
    OpenSCManager EQU <OpenSCManagerA>
    OpenService EQU <OpenServiceA>
    PrivilegedServiceAuditAlarm EQU <PrivilegedServiceAuditAlarmW>
    QueryServiceConfig EQU <QueryServiceConfigW>
    QueryServiceLockStatus EQU <QueryServiceLockStatusW>
    ReadEventLog EQU <ReadEventLogW>
    RegConnectRegistry EQU <RegConnectRegistryW>
    RegCreateKey EQU <RegCreateKeyW>
    RegCreateKeyEx EQU <RegCreateKeyExW>
    RegDeleteKey EQU <RegDeleteKeyW>
    RegDeleteValue EQU <RegDeleteValueW>
    RegEnumKey EQU <RegEnumKeyW>
    RegEnumKeyEx EQU <RegEnumKeyExW>
    RegEnumValue EQU <RegEnumValueW>
    RegLoadKey EQU <RegLoadKeyW>
    RegOpenKey EQU <RegOpenKeyW>
    RegOpenKeyEx EQU <RegOpenKeyExW>
    RegQueryInfoKey EQU <RegQueryInfoKeyW>
    RegQueryMultipleValues EQU <RegQueryMultipleValuesW>
    RegQueryValue EQU <RegQueryValueW>
    RegQueryValueEx EQU <RegQueryValueExW>
    RegReplaceKey EQU <RegReplaceKeyW>
    RegRestoreKey EQU <RegRestoreKeyW>
    RegSaveKey EQU <RegSaveKeyW>
    RegSetValue EQU <RegSetValueW>
    RegSetValueEx EQU <RegSetValueExW>
    RegUnLoadKey EQU <RegUnLoadKeyW>
    RegisterEventSource EQU <RegisterEventSourceW>
    RegisterServiceCtrlHandler EQU <RegisterServiceCtrlHandlerW>
    ReportEvent EQU <ReportEventW>
    SetFileSecurity EQU <SetFileSecurityW>
    StartService EQU <StartServiceW>
    StartServiceCtrlDispatcher EQU <StartServiceCtrlDispatcherW>
ELSE
    ACCCTRL_DEFAULT_PROVIDER EQU <ACCCTRL_DEFAULT_PROVIDERA>
    SERVICES_ACTIVE_DATABASE EQU <SERVICES_ACTIVE_DATABASEA>
    SERVICES_FAILED_DATABASE EQU <SERVICES_FAILED_DATABASEA>
    SC_GROUP_IDENTIFIER EQU <SC_GROUP_IDENTIFIERA>
    SERVICE_DESCRIPTION EQU <SERVICE_DESCRIPTIONA>
    SERVICE_FAILURE_ACTIONS EQU <SERVICE_FAILURE_ACTIONSA>
    QUERY_SERVICE_LOCK_STATUS EQU <QUERY_SERVICE_LOCK_STATUSA>
    QUERY_SERVICE_CONFIG EQU <QUERY_SERVICE_CONFIGA>
    SERVICE_TABLE_ENTRY EQU <SERVICE_TABLE_ENTRYA>
    ENUM_SERVICE_STATUS EQU <ENUM_SERVICE_STATUSA>
    ENUM_SERVICE_STATUS_PROCESS EQU <ENUM_SERVICE_STATUS_PROCESSA>
    INHERITED_FROM EQU <INHERITED_FROMA>
    OBJECTS_AND_NAME EQU <OBJECTS_AND_NAME_A>
    TRUSTEE EQU <TRUSTEE_A>
    EXPLICIT_ACCESS EQU <EXPLICIT_ACCESSA>
    ACTRL_ACCESS_ENTRY EQU <ACTRL_ACCESS_ENTRYA>
    ACTRL_ACCESS_ENTRY_LIST EQU <ACTRL_ACCESS_ENTRY_LISTA>
    ACTRL_PROPERTY_ENTRY EQU <ACTRL_PROPERTY_ENTRYA>
    ACTRL_ALIST EQU <ACTRL_ALISTA>
    TRUSTEE_ACCESS EQU <TRUSTEE_ACCESSA>
    ACTRL_ACCESS_INFO EQU <ACTRL_ACCESS_INFOA>
    ACTRL_CONTROL_INFO EQU <ACTRL_CONTROL_INFOA>
    ACTRL_AUDIT EQU <ACTRL_AUDITA>
    AbortSystemShutdown EQU <AbortSystemShutdownA>
    AccessCheckAndAuditAlarm EQU <AccessCheckAndAuditAlarmA>
    BackupEventLog EQU <BackupEventLogA>
    ChangeServiceConfig EQU <ChangeServiceConfigA>
    ClearEventLog EQU <ClearEventLogA>
    CreateService EQU <CreateServiceA>
    IFNDEF CryptAcquireContext
        CryptAcquireContext EQU <CryptAcquireContextA>
    ENDIF
    CryptSetProvider EQU <CryptSetProviderA>
    CryptSetProviderEx EQU <CryptSetProviderExA>
    CryptSignHash EQU <CryptSignHashA>
    CryptVerifySignature EQU <CryptVerifySignatureA>
    EnumDependentServices EQU <EnumDependentServicesA>
    EnumServicesStatus EQU <EnumServicesStatusA>
    GetFileSecurity EQU <GetFileSecurityA>
    GetServiceDisplayName EQU <GetServiceDisplayNameA>
    GetServiceKeyName EQU <GetServiceKeyNameA>
    GetUserName EQU <GetUserNameA>
    InitiateSystemShutdown EQU <InitiateSystemShutdownA>
    LogonUser EQU <LogonUserA>
    LookupAccountName EQU <LookupAccountNameA>
    LookupAccountSid EQU <LookupAccountSidA>
    LookupPrivilegeDisplayName EQU <LookupPrivilegeDisplayNameA>
    LookupPrivilegeName EQU <LookupPrivilegeNameA>
    LookupPrivilegeValue EQU <LookupPrivilegeValueA>
    ObjectCloseAuditAlarm EQU <ObjectCloseAuditAlarmA>
    ObjectOpenAuditAlarm EQU <ObjectOpenAuditAlarmA>
    ObjectPrivilegeAuditAlarm EQU <ObjectPrivilegeAuditAlarmA>
    OpenBackupEventLog EQU <OpenBackupEventLogA>
    OpenEventLog EQU <OpenEventLogA>
    OpenSCManager EQU <OpenSCManagerA>
    OpenService EQU <OpenServiceA>
    PrivilegedServiceAuditAlarm EQU <PrivilegedServiceAuditAlarmA>
    QueryServiceConfig EQU <QueryServiceConfigA>
    QueryServiceLockStatus EQU <QueryServiceLockStatusA>
    ReadEventLog EQU <ReadEventLogA>
    RegConnectRegistry EQU <RegConnectRegistryA>
    RegCreateKey EQU <RegCreateKeyA>
    RegCreateKeyEx EQU <RegCreateKeyExA>
    RegDeleteKey EQU <RegDeleteKeyA>
    RegDeleteValue EQU <RegDeleteValueA>
    RegEnumKey EQU <RegEnumKeyA>
    RegEnumKeyEx EQU <RegEnumKeyExA>
    RegEnumValue EQU <RegEnumValueA>
    RegLoadKey EQU <RegLoadKeyA>
    RegOpenKey EQU <RegOpenKeyA>
    RegOpenKeyEx EQU <RegOpenKeyExA>
    RegQueryInfoKey EQU <RegQueryInfoKeyA>
    RegQueryMultipleValues EQU <RegQueryMultipleValuesA>
    RegQueryValue EQU <RegQueryValueA>
    RegQueryValueEx EQU <RegQueryValueExA>
    RegReplaceKey EQU <RegReplaceKeyA>
    RegRestoreKey EQU <RegRestoreKeyA>
    RegSaveKey EQU <RegSaveKeyA>
    RegSetValue EQU <RegSetValueA>
    RegSetValueEx EQU <RegSetValueExA>
    RegUnLoadKey EQU <RegUnLoadKeyA>
    RegisterEventSource EQU <RegisterEventSourceA>
    RegisterServiceCtrlHandler EQU <RegisterServiceCtrlHandlerA>
    ReportEvent EQU <ReportEventA>
    SetFileSecurity EQU <SetFileSecurityA>
    StartService EQU <StartServiceA>
    StartServiceCtrlDispatcher EQU <StartServiceCtrlDispatcherA>
ENDIF

;======================= Undocumented functions (unknown arguments) =======================;
;AddUsersToEncryptedFileEx PROTO
;CancelOverlappedAccess PROTO
;CheckAppInitBlockedServiceIdentity PROTO
;CheckForHiberboot PROTO
;CloseCodeAuthzLevel PROTO
;ComputeAccessTokenFromCodeAuthzLevel PROTO
;ConvertSDToStringSDDomainW PROTO
;CreateCodeAuthzLevel PROTO
;CredBackupCredentials PROTO
;CredEncryptAndMarshalBinaryBlob PROTO
;CredpConvertCredential PROTO
;CredpConvertOneCredentialSize PROTO
;CredpConvertTargetInfo PROTO
;CredpDecodeCredential PROTO
;CredpEncodeCredential PROTO
;CredpEncodeSecret PROTO
;CredProfileLoaded PROTO
;CredProfileLoadedEx PROTO
;CredProfileUnloaded PROTO
;CredRestoreCredentials PROTO
;ElfFlushEventLog PROTO
;ElfReportEventAndSourceW PROTO
;EncryptedFileKeyInfo PROTO
;EtwLogSysConfigExtension PROTO
;EventWriteEndScenario PROTO
;EventWriteStartScenario PROTO
;FreeEncryptedFileKeyInfo PROTO
;GetInformationCodeAuthzLevelW PROTO
;GetInformationCodeAuthzPolicyW PROTO
;GetStringConditionFromBinary PROTO
;I_ScGetCurrentGroupStateW PROTO
;I_ScIsSecurityProcess PROTO
;I_ScPnPGetServiceName PROTO
;I_ScQueryServiceConfig PROTO
;I_ScRegisterPreshutdownRestart PROTO
;I_ScSendPnPMessage PROTO
;I_ScSendTSMessage PROTO
;I_ScSetServiceBitsA PROTO
;I_ScSetServiceBitsW PROTO
;I_ScValidatePnPService PROTO
;IdentifyCodeAuthzLevelW PROTO
;IsTokenUntrusted PROTO
;IsValidRelativeSecurityDescriptor PROTO
;LsaICLookupNames PROTO
;LsaICLookupNamesWithCreds PROTO
;LsaICLookupSids PROTO
;LsaICLookupSidsWithCreds PROTO
;MD4Final PROTO
;MD4Init PROTO
;MD4Update PROTO
;MD5Final PROTO
;MD5Init PROTO
;MD5Update PROTO
;MIDL_user_free_Ext PROTO
;PerfAddCounters PROTO
;PerfCloseQueryHandle PROTO
;PerfDeleteCounters PROTO
;PerfEnumerateCounterSet PROTO
;PerfEnumerateCounterSetInstances PROTO
;PerfOpenQueryHandle PROTO
;PerfQueryCounterData PROTO
;PerfQueryCounterInfo PROTO
;PerfQueryCounterSetRegistrationInfo PROTO
;PerfRegCloseKey PROTO
;PerfRegEnumKey PROTO
;PerfRegEnumValue PROTO
;PerfRegQueryInfoKey PROTO
;PerfRegQueryValue PROTO
;PerfRegSetValue PROTO
;ProcessIdleTasks PROTO
;ProcessIdleTasksW PROTO
;PsmActivateApplication PROTO
;PsmAdjustActivationToken PROTO
;PsmQueryBackgroundActivationType PROTO
;PsmRegisterApplicationProcess PROTO
;RegisterIdleTask PROTO
;RegRemapPreDefKey PROTO
;RegRenameKey PROTO
;RemoteRegEnumKeyWrapper PROTO
;RemoteRegEnumValueWrapper PROTO
;RemoteRegQueryInfoKeyWrapper PROTO
;RemoteRegQueryValueWrapper PROTO
;SafeBaseRegGetKeySecurity PROTO
;SaferiChangeRegistryScope PROTO
;SaferiCompareTokenLevels PROTO
;SaferiIsDllAllowed PROTO
;SaferiPopulateDefaultsInRegistry PROTO
;SaferiRecordEventLogEntry PROTO
;SaferiReplaceProcessThreadTokens PROTO
;SetInformationCodeAuthzLevelW PROTO
;SetInformationCodeAuthzPolicyW PROTO
;SystemFunction001 PROTO
;SystemFunction002 PROTO
;SystemFunction003 PROTO
;SystemFunction004 PROTO
;SystemFunction005 PROTO
;SystemFunction006 PROTO
;SystemFunction007 PROTO
;SystemFunction008 PROTO
;SystemFunction009 PROTO
;SystemFunction010 PROTO
;SystemFunction011 PROTO
;SystemFunction012 PROTO
;SystemFunction013 PROTO
;SystemFunction014 PROTO
;SystemFunction015 PROTO
;SystemFunction016 PROTO
;SystemFunction017 PROTO
;SystemFunction018 PROTO
;SystemFunction019 PROTO
;SystemFunction020 PROTO
;SystemFunction021 PROTO
;SystemFunction022 PROTO
;SystemFunction023 PROTO
;SystemFunction024 PROTO
;SystemFunction025 PROTO
;SystemFunction026 PROTO
;SystemFunction027 PROTO
;SystemFunction028 PROTO
;SystemFunction029 PROTO
;SystemFunction030 PROTO
;SystemFunction031 PROTO
;SystemFunction032 PROTO
;SystemFunction033 PROTO
;SystemFunction034 PROTO
;SystemFunction035 PROTO
;SystemFunction036 PROTO
;SystemFunction040 PROTO
;SystemFunction041 PROTO
;UnregisterIdleTask PROTO
;UsePinForEncryptedFilesA PROTO
;UsePinForEncryptedFilesW PROTO
;WaitServiceState PROTO
;WdmWmiServiceMain PROTO
;WmiCloseTraceWithCursor PROTO
;WmiConvertTimestamp PROTO
;WmiGetFirstTraceOffset PROTO
;WmiGetNextEvent PROTO
;WmiGetTraceHeader PROTO
;WmiOpenTraceWithCursor PROTO
;WmiParseTraceEvent PROTO
;Wow64Win32ApiEntry PROTO

;IFDEF APP_UNICODE
;    I_ScSetServiceBits EQU <I_ScSetServiceBitsW>
;    SetInformationCodeAuthzLevel EQU <SetInformationCodeAuthzLevelW>
;    UsePinForEncryptedFiles EQU <UsePinForEncryptedFilesW>
;ELSE
;    I_ScSetServiceBits EQU <I_ScSetServiceBitsA>
;    SetInformationCodeAuthzLevel EQU <SetInformationCodeAuthzLevelA>
;    UsePinForEncryptedFiles EQU <UsePinForEncryptedFilesA>
;ENDIF

ENDIF ;ADVAPI32_INC
