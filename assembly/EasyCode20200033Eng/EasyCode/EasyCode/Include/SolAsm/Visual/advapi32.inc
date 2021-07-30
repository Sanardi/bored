; ====================================================;
;                                                     ;
;    advapi32.inc for EC v2 SolAsm visual projects    ;
;                   (version 1.0.3)                   ;
;                                                     ;
;         Copyright © Ramon Sala - 2018-2019          ;
;                                                     ;
; ====================================================;

#ifndef ADVAPI32_INC
ADVAPI32_INC equ 1

NO_INHERITANCE                                  equ     000H
SUB_OBJECTS_ONLY_INHERIT                        equ     001H
SUB_CONTAINERS_ONLY_INHERIT                     equ     002H
SUB_CONTAINERS_AND_OBJECTS_INHERIT              equ     003H
INHERIT_NO_PROPAGATE                            equ     004H
INHERIT_ONLY                                    equ     008H
INHERITED_ACCESS_ENTRY                          equ     010H

INHERITED_PARENT                                equ     010000000H
INHERITED_GRANDPARENT                           equ     020000000H

;ACCCTRL_DEFAULT_PROVIDERA                       db      'Windows NT Access Provider',0
;ACCCTRL_DEFAULT_PROVIDERW                       du      'Windows NT Access Provider',0

;SERVICES_ACTIVE_DATABASEW                       du      'ServicesActive',0
;SERVICES_FAILED_DATABASEW                       du      'ServicesFailed',0
;SERVICES_ACTIVE_DATABASEA                       db      'ServicesActive',0
;SERVICES_FAILED_DATABASEA                       db      'ServicesFailed',0

;SC_GROUP_IDENTIFIERW                            du      '+',0
;SC_GROUP_IDENTIFIERA                            db      '+',0

SERVICE_NO_CHANGE                               equ     0FFFFFFFFH

SERVICE_ACTIVE                                  equ     00000001H
SERVICE_INACTIVE                                equ     00000002H
SERVICE_STATE_ALL                               equ     <SERVICE_ACTIVE or SERVICE_INACTIVE>

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

#ifndef STANDARD_RIGHTS_REQUIRED
    STANDARD_RIGHTS_REQUIRED                    equ     0000F0000H
#endif

SC_MANAGER_CONNECT                              equ     0001H
SC_MANAGER_CREATE_SERVICE                       equ     0002H
SC_MANAGER_ENUMERATE_SERVICE                    equ     0004H
SC_MANAGER_LOCK                                 equ     0008H
SC_MANAGER_QUERY_LOCK_STATUS                    equ     0010H
SC_MANAGER_MODIFY_BOOT_CONFIG                   equ     0020H
SC_MANAGER_ALL_ACCESS                           equ     <STANDARD_RIGHTS_REQUIRED OR SC_MANAGER_CONNECT or SC_MANAGER_CREATE_SERVICE or SC_MANAGER_ENUMERATE_SERVICE or SC_MANAGER_LOCK or SC_MANAGER_QUERY_LOCK_STATUS or SC_MANAGER_MODIFY_BOOT_CONFIG>

SERVICE_QUERY_CONFIG                            equ     0001H
SERVICE_CHANGE_CONFIG                           equ     0002H
SERVICE_QUERY_STATUS                            equ     0004H
SERVICE_ENUMERATE_DEPENDENTS                    equ     0008H
SERVICE_START                                   equ     0010H
SERVICE_STOP                                    equ     0020H
SERVICE_PAUSE_CONTINUE                          equ     0040H
SERVICE_INTERROGATE                             equ     0080H
SERVICE_USER_DEFINED_CONTROL                    equ     0100H
SERVICE_ALL_ACCESS                              equ     <STANDARD_RIGHTS_REQUIRED or SERVICE_QUERY_CONFIG or SERVICE_CHANGE_CONFIG or SERVICE_QUERY_STATUS or SERVICE_ENUMERATE_DEPENDENTS or SERVICE_START or SERVICE_STOP or SERVICE_PAUSE_CONTINUE or SERVICE_INTERROGATE or SERVICE_USER_DEFINED_CONTROL>

SERVICE_RUNS_IN_SYSTEM_PROCESS                  equ     00000001H

SERVICE_CONFIG_DESCRIPTION                      equ     1
SERVICE_CONFIG_FAILURE_ACTIONS                  equ     2

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
TRUSTEE_ACCESS_READ_WRITE                       equ     <TRUSTEE_ACCESS_READ or TRUSTEE_ACCESS_WRITE>
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
ACTRL_STD_RIGHT_REQUIRED                        equ     <ACTRL_STD_RIGHTS_ALL and (not ACTRL_SYNCHRONIZE)>

#ifndef ACTRL_DS_OPEN
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
#endif

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

REG_OPTION_RESERVED                             equ     00000000H
REG_LEGAL_OPTION                                equ     <REG_OPTION_RESERVED or REG_OPTION_NON_VOLATILE or REG_OPTION_VOLATILE or REG_OPTION_CREATE_LINK or REG_OPTION_BACKUP_RESTORE or REG_OPTION_OPEN_LINK>
REG_LEGAL_CHANGE_FILTER                         equ     <REG_NOTIFY_CHANGE_NAME or REG_NOTIFY_CHANGE_ATTRIBUTES or REG_NOTIFY_CHANGE_LAST_SET or REG_NOTIFY_CHANGE_SECURITY>

REG_STANDARD_FORMAT                             equ     1
REG_LATEST_FORMAT                               equ     2
REG_NO_COMPRESSION                              equ     4

REG_WHOLE_HIVE_VOLATILE                         equ     00000001H
REG_REFRESH_HIVE                                equ     00000002H
REG_NO_LAZY_FLUSH                               equ     00000004H
REG_FORCE_RESTORE                               equ     00000008H
REG_APP_HIVE                                    equ     00000010H
REG_PROCESS_PRIVATE                             equ     00000020H
REG_START_JOURNAL                               equ     00000040H
REG_HIVE_EXACT_FILE_GROWTH                      equ     00000080H
REG_HIVE_NO_RM                                  equ     00000100H
REG_HIVE_SINGLE_LOG                             equ     00000200H
REG_BOOT_HIVE                                   equ     00000400H
REG_LOAD_HIVE_OPEN_HANDLE                       equ     00000800H
REG_FLUSH_HIVE_FILE_GROWTH                      equ     00001000H

REG_FORCE_UNLOAD                                equ     1

;======================================== Functions =======================================;
#if COFF_FORMAT == 1
    from_lib advapi32.lib
#else
    from_dll advapi32.dll
#endif

#ifdef APP_WIN64
    import AbortSystemShutdownA
    import AbortSystemShutdownW
    import AccessCheck
    import AccessCheckAndAuditAlarmA
    import AccessCheckAndAuditAlarmW
    import AddAccessAllowedAce
    import AddAccessDeniedAce
    import AddAce
    import AddAuditAccessAce
    import AdjustTokenGroups
    import AdjustTokenPrivileges
    import AllocateAndInitializeSid
    import AllocateLocallyUniqueId
    import AreAllAccessesGranted
    import AreAnyAccessesGranted
    import BackupEventLogA
    import BackupEventLogW
    import ChangeServiceConfigA
    import ChangeServiceConfigW
    import ClearEventLogA
    import ClearEventLogW
    import CloseEventLog
    import CloseServiceHandle
    import ControlService
    import CopySid
    import CreatePrivateObjectSecurity
    import CreateServiceA
    import CreateServiceW
    import CryptAcquireContextA
    import CryptAcquireContextW
    import CryptCreateHash
    import CryptDecrypt
    import CryptDeriveKey
    import CryptDestroyHash
    import CryptDestroyKey
    import CryptEncrypt
    import CryptExportKey
    import CryptGenKey
    import CryptGenRandom
    import CryptGetHashParam
    import CryptGetKeyParam
    import CryptGetProvParam
    import CryptGetUserKey
    import CryptHashData
    import CryptHashSessionKey
    import CryptImportKey
    import CryptReleaseContext
    import CryptSetHashParam
    import CryptSetKeyParam
    import CryptSetProviderA
    import CryptSetProviderExA
    import CryptSetProviderExW
    import CryptSetProviderW
    import CryptSetProvParam
    import CryptSignHashA
    import CryptSignHashW
    import CryptVerifySignatureA
    import CryptVerifySignatureW
    import DeleteAce
    import DeleteService
    import DeregisterEventSource
    import DestroyPrivateObjectSecurity
    import DuplicateToken
    import EnumDependentServicesA
    import EnumDependentServicesW
    import EnumServicesStatusA
    import EnumServicesStatusW
    import EqualPrefixSid
    import EqualSid
    import FindFirstFreeAce
    import FreeSid
    import GetAce
    import GetAclInformation
    import GetFileSecurityA
    import GetFileSecurityW
    import GetKernelObjectSecurity
    import GetLengthSid
    import GetNumberOfEventLogRecords
    import GetOldestEventLogRecord
    import GetPrivateObjectSecurity
    import GetSecurityDescriptorControl
    import GetSecurityDescriptorDacl
    import GetSecurityDescriptorGroup
    import GetSecurityDescriptorLength
    import GetSecurityDescriptorOwner
    import GetSecurityDescriptorSacl
    import GetServiceDisplayNameA
    import GetServiceDisplayNameW
    import GetServiceKeyNameA
    import GetServiceKeyNameW
    import GetSidIdentifierAuthority
    import GetSidLengthRequired
    import GetSidSubAuthority
    import GetSidSubAuthorityCount
    import GetTokenInformation
    import GetUserNameA
    import GetUserNameW
    import ImpersonateLoggedOnUser
    import ImpersonateNamedPipeClient
    import ImpersonateSelf
    import InitializeAcl
    import InitializeSecurityDescriptor
    import InitializeSid
    import InitiateSystemShutdownA
    import InitiateSystemShutdownW
    import IsTextUnicode
    import IsValidAcl
    import IsValidSecurityDescriptor
    import IsValidSid
    import LockServiceDatabase
    import LogonUserA
    import LogonUserW
    import LookupAccountNameA
    import LookupAccountNameW
    import LookupAccountSidA
    import LookupAccountSidW
    import LookupPrivilegeDisplayNameA
    import LookupPrivilegeDisplayNameW
    import LookupPrivilegeNameA
    import LookupPrivilegeNameW
    import LookupPrivilegeValueA
    import LookupPrivilegeValueW
    import MakeAbsoluteSD
    import MakeSelfRelativeSD
    import MapGenericMask
    import NotifyBootConfigStatus
    import NotifyChangeEventLog
    import ObjectCloseAuditAlarmA
    import ObjectCloseAuditAlarmW
    import ObjectOpenAuditAlarmA
    import ObjectOpenAuditAlarmW
    import ObjectPrivilegeAuditAlarmA
    import ObjectPrivilegeAuditAlarmW
    import OpenBackupEventLogA
    import OpenBackupEventLogW
    import OpenEventLogA
    import OpenEventLogW
    import OpenSCManagerA
    import OpenSCManagerW
    import OpenServiceA
    import OpenServiceW
    import PrivilegeCheck
    import PrivilegedServiceAuditAlarmA
    import PrivilegedServiceAuditAlarmW
    import QueryServiceConfigA
    import QueryServiceConfigW
    import QueryServiceLockStatusA
    import QueryServiceLockStatusW
    import QueryServiceObjectSecurity
    import QueryServiceStatus
    import ReadEventLogA
    import ReadEventLogW
    import RegConnectRegistryA
    import RegConnectRegistryW
    import RegCloseKey
    import RegCreateKeyA
    import RegCreateKeyExA
    import RegCreateKeyExW
    import RegCreateKeyW
    import RegDeleteKeyA
    import RegDeleteKeyW
    import RegDeleteValueA
    import RegDeleteValueW
    import RegEnumKeyA
    import RegEnumKeyExA
    import RegEnumKeyExW
    import RegEnumKeyW
    import RegEnumValueA
    import RegEnumValueW
    import RegFlushKey
    import RegGetKeySecurity
    import RegLoadKeyA
    import RegLoadKeyW
    import RegNotifyChangeKeyValue
    import RegOpenKeyA
    import RegOpenKeyExA
    import RegOpenKeyExW
    import RegOpenKeyW
    import RegQueryInfoKeyA
    import RegQueryInfoKeyW
    import RegQueryMultipleValuesA
    import RegQueryMultipleValuesW
    import RegQueryValueA
    import RegQueryValueExA
    import RegQueryValueExW
    import RegQueryValueW
    import RegReplaceKeyA
    import RegReplaceKeyW
    import RegRestoreKeyA
    import RegRestoreKeyW
    import RegSaveKeyA
    import RegSaveKeyW
    import RegSetKeySecurity
    import RegSetValueA
    import RegSetValueExA
    import RegSetValueExW
    import RegSetValueW
    import RegUnLoadKeyA
    import RegUnLoadKeyW
    import RegisterEventSourceA
    import RegisterEventSourceW
    import RegisterServiceCtrlHandlerA
    import RegisterServiceCtrlHandlerW
    import ReportEventA
    import ReportEventW
    import RevertToSelf
    import SetAclInformation
    import SetFileSecurityA
    import SetFileSecurityW
    import SetKernelObjectSecurity
    import SetPrivateObjectSecurity
    import SetSecurityDescriptorDacl
    import SetSecurityDescriptorGroup
    import SetSecurityDescriptorOwner
    import SetSecurityDescriptorSacl
    import SetServiceBits
    import SetServiceObjectSecurity
    import SetServiceStatus
    import SetThreadToken
    import SetTokenInformation
    import StartServiceA
    import StartServiceCtrlDispatcherA
    import StartServiceCtrlDispatcherW
    import StartServiceW
    import UnlockServiceDatabase

    #if NTDDI_VERSION >= NTDDI_WIN98_ME
        import BuildExplicitAccessWithNameA
        import BuildExplicitAccessWithNameW
        import BuildSecurityDescriptorA
        import BuildSecurityDescriptorW
        import BuildTrusteeWithNameA
        import BuildTrusteeWithNameW
        import BuildTrusteeWithSidA
        import BuildTrusteeWithSidW
        import ConvertAccessToSecurityDescriptorA
        import ConvertAccessToSecurityDescriptorW
        import ConvertSecurityDescriptorToAccessA
        import ConvertSecurityDescriptorToAccessW
        import ConvertSecurityDescriptorToAccessNamedA
        import ConvertSecurityDescriptorToAccessNamedW
        import CryptContextAddRef
        import CryptDuplicateHash
        import CryptDuplicateKey
        import CryptEnumProvidersA
        import CryptEnumProviderTypesA
        import CryptEnumProviderTypesW
        import CryptEnumProvidersW
        import CryptGetDefaultProviderA
        import CryptGetDefaultProviderW
        import DuplicateTokenEx
        import GetAccessPermissionsForObjectA
        import GetAccessPermissionsForObjectW
        import GetAuditedPermissionsFromAclA
        import GetAuditedPermissionsFromAclW
        import GetCurrentHwProfileA
        import GetCurrentHwProfileW
        import GetEffectiveRightsFromAclA
        import GetEffectiveRightsFromAclW
        import GetExplicitEntriesFromAclA
        import GetExplicitEntriesFromAclW
        import GetMultipleTrusteeA
        import GetMultipleTrusteeOperationA
        import GetMultipleTrusteeOperationW
        import GetMultipleTrusteeW
        import GetNamedSecurityInfoA
        import GetNamedSecurityInfoExA
        import GetNamedSecurityInfoExW
        import GetNamedSecurityInfoW
        import GetOverlappedAccessResults
        import GetSecurityInfo
        import GetSecurityInfoExA
        import GetSecurityInfoExW
        import GetTrusteeNameA
        import GetTrusteeNameW
        import GetTrusteeTypeA
        import GetTrusteeTypeW
        import LookupSecurityDescriptorPartsA
        import LookupSecurityDescriptorPartsW
        import ObjectDeleteAuditAlarmA
        import ObjectDeleteAuditAlarmW
        import SetEntriesInAccessListA
        import SetEntriesInAccessListW
        import SetEntriesInAclA
        import SetEntriesInAclW
        import SetEntriesInAuditListA
        import SetEntriesInAuditListW
        import SetNamedSecurityInfoA
        import SetNamedSecurityInfoExA
        import SetNamedSecurityInfoExW
        import SetNamedSecurityInfoW
        import SetSecurityInfo
        import SetSecurityInfoExA
        import SetSecurityInfoExW
        import TrusteeAccessToObjectA
        import TrusteeAccessToObjectW
        #ifdef APP_UNICODE
            define BuildExplicitAccessWithName BuildExplicitAccessWithNameW
            define BuildSecurityDescriptor BuildSecurityDescriptorW
            define BuildTrusteeWithName BuildTrusteeWithNameW
            define BuildTrusteeWithSid BuildTrusteeWithSidW
            define ConvertAccessToSecurityDescriptor ConvertAccessToSecurityDescriptorW
            define ConvertSecurityDescriptorToAccess ConvertSecurityDescriptorToAccessW
            define ConvertSecurityDescriptorToAccessNamed ConvertSecurityDescriptorToAccessNamedW
            define CryptEnumProviders CryptEnumProvidersW
            define CryptEnumProviderTypes CryptEnumProviderTypesW
            define CryptGetDefaultProvider CryptGetDefaultProviderW
            define GetAccessPermissionsForObject GetAccessPermissionsForObjectW
            define GetAuditedPermissionsFromAcl GetAuditedPermissionsFromAclW
            define GetCurrentHwProfile GetCurrentHwProfileW
            define GetEffectiveRightsFromAcl GetEffectiveRightsFromAclW
            define GetExplicitEntriesFromAcl GetExplicitEntriesFromAclW
            define GetMultipleTrustee GetMultipleTrusteeW
            define GetMultipleTrusteeOperation GetMultipleTrusteeOperationW
            define GetNamedSecurityInfo GetNamedSecurityInfoW
            define GetNamedSecurityInfoEx GetNamedSecurityInfoExW
            define GetSecurityInfoEx GetSecurityInfoExW
            define GetTrusteeName GetTrusteeNameW
            define GetTrusteeType GetTrusteeTypeW
            define LookupSecurityDescriptorParts LookupSecurityDescriptorPartsW
            define ObjectDeleteAuditAlarm ObjectDeleteAuditAlarmW
            define SetEntriesInAccessList SetEntriesInAccessListW
            define SetEntriesInAcl SetEntriesInAclW
            define SetEntriesInAuditList SetEntriesInAuditListW
            define SetNamedSecurityInfo SetNamedSecurityInfoW
            define SetNamedSecurityInfoEx SetNamedSecurityInfoExW
            define SetSecurityInfoEx SetSecurityInfoExW
            define TrusteeAccessToObject TrusteeAccessToObjectW
        #else
            define BuildExplicitAccessWithName BuildExplicitAccessWithNameA
            define BuildSecurityDescriptor BuildSecurityDescriptorA
            define BuildTrusteeWithName BuildTrusteeWithNameA
            define BuildTrusteeWithSid BuildTrusteeWithSidA
            define ConvertAccessToSecurityDescriptor ConvertAccessToSecurityDescriptorA
            define ConvertSecurityDescriptorToAccess ConvertSecurityDescriptorToAccessA
            define ConvertSecurityDescriptorToAccessNamed ConvertSecurityDescriptorToAccessNamedA
            define CryptEnumProviders CryptEnumProvidersA
            define CryptEnumProviderTypes CryptEnumProviderTypesA
            define CryptGetDefaultProvider CryptGetDefaultProviderA
            define GetAccessPermissionsForObject GetAccessPermissionsForObjectA
            define GetAuditedPermissionsFromAcl GetAuditedPermissionsFromAclA
            define GetCurrentHwProfile GetCurrentHwProfileA
            define GetEffectiveRightsFromAcl GetEffectiveRightsFromAclA
            define GetExplicitEntriesFromAcl GetExplicitEntriesFromAclA
            define GetMultipleTrustee GetMultipleTrusteeA
            define GetMultipleTrusteeOperation GetMultipleTrusteeOperationA
            define GetNamedSecurityInfo GetNamedSecurityInfoA
            define GetNamedSecurityInfoEx GetNamedSecurityInfoExA
            define GetSecurityInfoEx GetSecurityInfoExA
            define GetTrusteeName GetTrusteeNameA
            define GetTrusteeType GetTrusteeTypeA
            define LookupSecurityDescriptorParts LookupSecurityDescriptorPartsA
            define ObjectDeleteAuditAlarm ObjectDeleteAuditAlarmA
            define SetEntriesInAccessList SetEntriesInAccessListA
            define SetEntriesInAcl SetEntriesInAclA
            define SetEntriesInAuditList SetEntriesInAuditListA
            define SetNamedSecurityInfo SetNamedSecurityInfoA
            define SetNamedSecurityInfoEx SetNamedSecurityInfoExA
            define SetSecurityInfoEx SetSecurityInfoExA
            define TrusteeAccessToObject TrusteeAccessToObjectA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WINNT4
        import CreateProcessAsUserA
        import CreateProcessAsUserW
        import ElfBackupEventLogFileA
        import ElfBackupEventLogFileW
        import ElfChangeNotify
        import ElfClearEventLogFileA
        import ElfClearEventLogFileW
        import ElfCloseEventLog
        import ElfDeregisterEventSource
        import ElfNumberOfRecords
        import ElfOldestRecord
        import ElfOpenBackupEventLogA
        import ElfOpenBackupEventLogW
        import ElfOpenEventLogA
        import ElfOpenEventLogW
        import ElfReadEventLogA
        import ElfReadEventLogW
        import ElfRegisterEventSourceA
        import ElfRegisterEventSourceW
        import ElfReportEventA
        import ElfReportEventW
        import EnumServiceGroupW
        import EnumServicesStatusExA
        import EnumServicesStatusExW
        import IsTokenUntrusted
        import LsaAddAccountRights
        import LsaAddPrivilegesToAccount
        import LsaClearAuditLog
        import LsaClose
        import LsaCreateAccount
        import LsaCreateSecret
        import LsaCreateTrustedDomain
        import LsaDelete
        import LsaDeleteTrustedDomain
        import LsaEnumerateAccountRights
        import LsaEnumerateAccounts
        import LsaEnumerateAccountsWithUserRight
        import LsaEnumeratePrivileges
        import LsaEnumeratePrivilegesOfAccount
        import LsaEnumerateTrustedDomains
        import LsaFreeMemory
        import LsaGetQuotasForAccount
        import LsaGetRemoteUserName
        import LsaGetSystemAccessAccount
        import LsaGetUserName
        import LsaLookupNames
        import LsaLookupPrivilegeDisplayName
        import LsaLookupPrivilegeName
        import LsaLookupPrivilegeValue
        import LsaLookupSids
        import LsaNtStatusToWinError
        import LsaOpenAccount
        import LsaOpenPolicy
        import LsaOpenSecret
        import LsaOpenTrustedDomain
        import LsaOpenTrustedDomainByName
        import LsaQueryInformationPolicy
        import LsaQuerySecret
        import LsaQuerySecurityObject
        import LsaQueryTrustedDomainInfo
        import LsaRemoveAccountRights
        import LsaRemovePrivilegesFromAccount
        import LsaRetrievePrivateData
        import LsaSetInformationPolicy
        import LsaSetInformationTrustedDomain
        import LsaSetQuotasForAccount
        import LsaSetSecret
        import LsaSetSecurityObject
        import LsaSetSystemAccessAccount
        import LsaSetTrustedDomainInformation
        import LsaStorePrivateData
        import OpenProcessToken
        import OpenThreadToken
        #ifdef APP_UNICODE
            define CreateProcessAsUser CreateProcessAsUserW
            define ElfBackupEventLogFile ElfBackupEventLogFileW
            define ElfClearEventLogFile ElfClearEventLogFileW
            define ElfOpenBackupEventLog ElfOpenBackupEventLogW
            define ElfOpenEventLog ElfOpenEventLogW
            define ElfReadEventLog ElfReadEventLogW
            define ElfRegisterEventSource ElfRegisterEventSourceW
            define ElfReportEvent ElfReportEventW
            define EnumServicesStatusEx EnumServicesStatusExW
        #else
            define CreateProcessAsUser CreateProcessAsUserA
            define ElfBackupEventLogFile ElfBackupEventLogFileA
            define ElfClearEventLogFile ElfClearEventLogFileA
            define ElfOpenBackupEventLog ElfOpenBackupEventLogA
            define ElfOpenEventLog ElfOpenEventLogA
            define ElfReadEventLog ElfReadEventLogA
            define ElfRegisterEventSource ElfRegisterEventSourceA
            define ElfReportEvent ElfReportEventA
            define EnumServicesStatusEx EnumServicesStatusExA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WIN2K
        import AccessCheckByType
        import AccessCheckByTypeAndAuditAlarmA
        import AccessCheckByTypeAndAuditAlarmW
        import AccessCheckByTypeResultList
        import AccessCheckByTypeResultListAndAuditAlarmA
        import AccessCheckByTypeResultListAndAuditAlarmW
        import AccessCheckByTypeResultListAndAuditAlarmByHandleA
        import AccessCheckByTypeResultListAndAuditAlarmByHandleW
        import AddAccessAllowedAceEx
        import AddAccessAllowedObjectAce
        import AddAccessDeniedAceEx
        import AddAccessDeniedObjectAce
        import AddAuditAccessAceEx
        import AddAuditAccessObjectAce
        import AddUsersToEncryptedFile
        import BuildTrusteeWithObjectsAndNameA
        import BuildTrusteeWithObjectsAndNameW
        import BuildTrusteeWithObjectsAndSidA
        import BuildTrusteeWithObjectsAndSidW
        import CheckTokenMembership
        import CloseEncryptedFileRaw
        import CloseTrace
        import CommandLineFromMsiDescriptor
        import ControlTraceA
        import ControlTraceW
        import ConvertSDToStringSDRootDomainA
        import ConvertSDToStringSDRootDomainW
        import ConvertSecurityDescriptorToStringSecurityDescriptorA
        import ConvertSecurityDescriptorToStringSecurityDescriptorW
        import ConvertSidToStringSidA
        import ConvertSidToStringSidW
        import ConvertStringSDToSDRootDomainA
        import ConvertStringSDToSDRootDomainW
        import ConvertStringSecurityDescriptorToSecurityDescriptorA
        import ConvertStringSecurityDescriptorToSecurityDescriptorW
        import ConvertStringSidToSidA
        import ConvertStringSidToSidW
        import ConvertToAutoInheritPrivateObjectSecurity
        import CreatePrivateObjectSecurityEx
        import CreateProcessWithLogonW
        import CreateRestrictedToken
        import CreateTraceInstanceId
        import CreateWellKnownSid
        import EnableTrace
        import EncryptFileA
        import EncryptFileW
        import EncryptionDisable
        import EqualDomainSid
        import FileEncryptionStatusA
        import FileEncryptionStatusW
        import FreeEncryptionCertificateHashList
        import GetEventLogInformation
        import GetLocalManagedApplications
        import GetManagedApplications
        import ImpersonateAnonymousToken
        import InitiateSystemShutdownExA
        import InitiateSystemShutdownExW
        import InstallApplication
        import IsTokenRestricted
        import LsaCreateTrustedDomainEx
        import LsaEnumerateTrustedDomainsEx
        import LsaOpenPolicySce
        import LsaQueryDomainInformationPolicy
        import LsaQueryInfoTrustedDomain
        import LsaQueryTrustedDomainInfoByName
        import LsaSetDomainInformationPolicy
        import LsaSetTrustedDomainInfoByName
        import MakeAbsoluteSD2
        import OpenEncryptedFileRawA
        import OpenEncryptedFileRawW
        import OpenTraceA
        import OpenTraceW
        import QueryAllTracesA
        import QueryAllTracesW
        import QueryRecoveryAgentsOnEncryptedFile
        import QueryServiceConfig2A
        import QueryServiceConfig2W
        import QueryServiceStatusEx
        import QueryUsersOnEncryptedFile
        import ReadEncryptedFileRaw
        import RegDisablePredefinedCache
        import RegOpenCurrentUser
        import RegOpenUserClassesRoot
        import RegOverridePredefKey
        import RegisterServiceCtrlHandlerExA
        import RegisterServiceCtrlHandlerExW
        import RegisterTraceGuidsA
        import RegisterTraceGuidsW
        import RemoveUsersFromEncryptedFile
        import RemoveTraceCallback
        import SetPrivateObjectSecurityEx
        import SetSecurityDescriptorControl
        import SetSecurityDescriptorRMControl
        import SetTraceCallback
        import SetUserFileEncryptionKey
        import StartTraceA
        import StartTraceW
        import TraceEvent
        import TraceEventInstance
        import UninstallApplication
        import UnregisterTraceGuids
        import WmiCloseBlock
        import WmiEnumerateGuids
        import WmiDevInstToInstanceNameA
        import WmiDevInstToInstanceNameW
        import WmiExecuteMethodA
        import WmiExecuteMethodW
        import WmiFileHandleToInstanceNameA
        import WmiFileHandleToInstanceNameW
        import WmiFreeBuffer
        import WmiMofEnumerateResourcesA
        import WmiMofEnumerateResourcesW
        import WmiNotificationRegistrationA
        import WmiNotificationRegistrationW
        import WmiOpenBlock
        import WmiQueryAllDataA
        import WmiQueryAllDataW
        import WmiQueryGuidInformation
        import WmiQuerySingleInstanceA
        import WmiQuerySingleInstanceW
        import WmiSetSingleInstanceA
        import WmiSetSingleInstanceW
        import WmiSetSingleItemA
        import WmiSetSingleItemW
        import WriteEncryptedFileRaw
        #ifdef APP_UNICODE
            define AccessCheckByTypeAndAuditAlarm AccessCheckByTypeAndAuditAlarmW
            define AccessCheckByTypeResultListAndAuditAlarm AccessCheckByTypeResultListAndAuditAlarmW
            define AccessCheckByTypeResultListAndAuditAlarmByHandle AccessCheckByTypeResultListAndAuditAlarmByHandleW
            define BuildTrusteeWithObjectsAndName BuildTrusteeWithObjectsAndNameW
            define BuildTrusteeWithObjectsAndSid BuildTrusteeWithObjectsAndSidW
            define ControlTrace ControlTraceW
            define ConvertSDToStringSDRootDomain ConvertSDToStringSDRootDomainW
            define ConvertSecurityDescriptorToStringSecurityDescriptor ConvertSecurityDescriptorToStringSecurityDescriptorW
            define ConvertSidToStringSid ConvertSidToStringSidW
            define ConvertStringSDToSDRootDomain ConvertStringSDToSDRootDomainW
            define ConvertStringSecurityDescriptorToSecurityDescriptor ConvertStringSecurityDescriptorToSecurityDescriptorW
            define ConvertStringSidToSid ConvertStringSidToSidW
            define EncryptFile EncryptFileW
            define FileEncryptionStatus FileEncryptionStatusW
            define InitiateSystemShutdownEx InitiateSystemShutdownExW
            define OpenEncryptedFileRaw OpenEncryptedFileRawW
            define OpenTrace OpenTraceW
            define QueryAllTraces QueryAllTracesW
            define QueryServiceConfig2 QueryServiceConfig2W
            define RegisterServiceCtrlHandlerEx RegisterServiceCtrlHandlerExW
            define RegisterTraceGuids RegisterTraceGuidsW
            define StartTrace StartTraceW
            define WmiDevInstToInstanceName WmiDevInstToInstanceNameW
            define WmiExecuteMethod WmiExecuteMethodW
            define WmiFileHandleToInstanceName WmiFileHandleToInstanceNameW
            define WmiMofEnumerateResources WmiMofEnumerateResourcesW
            define WmiNotificationRegistration WmiNotificationRegistrationW
            define WmiQueryAllData WmiQueryAllDataW
            define WmiQuerySingleInstance WmiQuerySingleInstanceW
            define WmiSetSingleInstance WmiSetSingleInstanceW
            define WmiSetSingleItem WmiSetSingleItemW
        #else
            define AccessCheckByTypeAndAuditAlarm AccessCheckByTypeAndAuditAlarmA
            define AccessCheckByTypeResultListAndAuditAlarm AccessCheckByTypeResultListAndAuditAlarmA
            define AccessCheckByTypeResultListAndAuditAlarmByHandle AccessCheckByTypeResultListAndAuditAlarmByHandleA
            define BuildTrusteeWithObjectsAndName BuildTrusteeWithObjectsAndNameA
            define BuildTrusteeWithObjectsAndSid BuildTrusteeWithObjectsAndSidA
            define ControlTrace ControlTraceA
            define ConvertSDToStringSDRootDomain ConvertSDToStringSDRootDomainA
            define ConvertSecurityDescriptorToStringSecurityDescriptor ConvertSecurityDescriptorToStringSecurityDescriptorA
            define ConvertSidToStringSid ConvertSidToStringSidA
            define ConvertStringSDToSDRootDomain ConvertStringSDToSDRootDomainA
            define ConvertStringSecurityDescriptorToSecurityDescriptor ConvertStringSecurityDescriptorToSecurityDescriptorA
            define ConvertStringSidToSid ConvertStringSidToSidA
            define EncryptFile EncryptFileA
            define FileEncryptionStatus FileEncryptionStatusA
            define InitiateSystemShutdownEx InitiateSystemShutdownExA
            define OpenEncryptedFileRaw OpenEncryptedFileRawA
            define OpenTrace OpenTraceA
            define QueryAllTraces QueryAllTracesA
            define QueryServiceConfig2 QueryServiceConfig2A
            define RegisterServiceCtrlHandlerEx RegisterServiceCtrlHandlerExA
            define RegisterTraceGuids RegisterTraceGuidsA
            define StartTrace StartTraceA
            define WmiDevInstToInstanceName WmiDevInstToInstanceNameA
            define WmiExecuteMethod WmiExecuteMethodA
            define WmiFileHandleToInstanceName WmiFileHandleToInstanceNameA
            define WmiMofEnumerateResources WmiMofEnumerateResourcesA
            define WmiNotificationRegistration WmiNotificationRegistrationA
            define WmiQueryAllData WmiQueryAllDataA
            define WmiQuerySingleInstance WmiQuerySingleInstanceA
            define WmiSetSingleInstance WmiSetSingleInstanceA
            define WmiSetSingleItem WmiSetSingleItemA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WINXP
        import A_SHAFinal
        import A_SHAInit
        import A_SHAUpdate
        import ChangeServiceConfig2A
        import ChangeServiceConfig2W
        import ConvertStringSDToSDDomainA
        import ConvertStringSDToSDDomainW
        import CreatePrivateObjectSecurityWithMultipleInheritance
        import CredDeleteA
        import CredDeleteW
        import CredEnumerateA
        import CredEnumerateW
        import CredFree
        import CredGetSessionTypes
        import CredGetTargetInfoA
        import CredGetTargetInfoW
        import CredIsMarshaledCredentialA
        import CredIsMarshaledCredentialW
        import CredMarshalCredentialA
        import CredMarshalCredentialW
        import CredReadA
        import CredReadW
        import CredReadDomainCredentialsA
        import CredReadDomainCredentialsW
        import CredRenameA
        import CredRenameW
        import CredUnmarshalCredentialA
        import CredUnmarshalCredentialW
        import CredWriteA
        import CredWriteW
        import CredWriteDomainCredentialsA
        import CredWriteDomainCredentialsW
        import DecryptFileA
        import DecryptFileW
        import DuplicateEncryptionInfoFile
        import EnumerateTraceGuids
        import FlushTraceA
        import FlushTraceW
        import FreeInheritedFromArray
        import GetInheritanceSourceA
        import GetInheritanceSourceW
        import GetLocalManagedApplicationData
        import GetManagedApplicationCategories
        import GetSecurityDescriptorRMControl
        import GetTraceEnableFlags
        import GetTraceEnableLevel
        import GetTraceLoggerHandle
        import GetTrusteeFormA
        import GetTrusteeFormW
        import GetWindowsAccountDomainSid
        import IsWellKnownSid
        import LogonUserExA
        import LogonUserExExW
        import LogonUserExW
        import LsaLookupNames2
        import LsaQueryForestTrustInformation
        import LsaSetForestTrustInformation
        import MSChapSrvChangePassword
        import MSChapSrvChangePassword2
        import ProcessTrace
        import QueryTraceA
        import QueryTraceW
        import RegDisablePredefinedCacheEx
        import RegSaveKeyExA
        import RegSaveKeyExW
        import SaferCloseLevel
        import SaferComputeTokenFromLevel
        import SaferCreateLevel
        import SaferGetLevelInformation
        import SaferGetPolicyInformation
        import SaferIdentifyLevel
        import SaferRecordEventLogEntry
        import SaferSetLevelInformation
        import SaferSetPolicyInformation
        import SaferiIsExecutableFileType
        import SaferiSearchMatchingHashRules
        import SetEncryptedFileMetadata
        import StopTraceA
        import StopTraceW
        import TraceMessage
        import TraceMessageVa
        import TreeResetNamedSecurityInfoA
        import TreeResetNamedSecurityInfoW
        import UpdateTraceA
        import UpdateTraceW
        import WmiQueryAllDataMultipleA
        import WmiQueryAllDataMultipleW
        import WmiQuerySingleInstanceMultipleA
        import WmiQuerySingleInstanceMultipleW
        import WmiReceiveNotificationsA
        import WmiReceiveNotificationsW
        #ifdef APP_UNICODE
            define ChangeServiceConfig2 ChangeServiceConfig2W
            define ConvertStringSDToSDDomain ConvertStringSDToSDDomainW
            define CredDelete CredDeleteW
            define CredEnumerate CredEnumerateW
            define CredGetTargetInfo CredGetTargetInfoW
            define CredIsMarshaledCredential CredIsMarshaledCredentialW
            define CredMarshalCredential CredMarshalCredentialW
            define CredRead CredReadW
            define CredReadDomainCredentials CredReadDomainCredentialsW
            define CredRename CredRenameW
            define CredUnmarshalCredential CredUnmarshalCredentialW
            define CredWrite CredWriteW
            define CredWriteDomainCredentials CredWriteDomainCredentialsW
            define DecryptFile DecryptFileW
            define FlushTrace FlushTraceW
            define GetInheritanceSource GetInheritanceSourceW
            define GetTrusteeForm GetTrusteeFormW
            define LogonUserEx LogonUserExW
            define QueryTrace QueryTraceW
            define RegSaveKeyEx RegSaveKeyExW
            define StopTrace StopTraceW
            define TreeResetNamedSecurityInfo TreeResetNamedSecurityInfoW
            define UpdateTrace UpdateTraceW
            define WmiQueryAllDataMultiple WmiQueryAllDataMultipleW
            define WmiQuerySingleInstanceMultiple WmiQuerySingleInstanceMultipleW
            define WmiReceiveNotifications WmiReceiveNotificationsW
        #else
            define ChangeServiceConfig2 ChangeServiceConfig2A
            define ConvertStringSDToSDDomain ConvertStringSDToSDDomainA
            define CredDelete CredDeleteA
            define CredEnumerate CredEnumerateA
            define CredGetTargetInfo CredGetTargetInfoA
            define CredIsMarshaledCredential CredIsMarshaledCredentialA
            define CredMarshalCredential CredMarshalCredentialA
            define CredRead CredReadA
            define CredReadDomainCredentials CredReadDomainCredentialsA
            define CredRename CredRenameA
            define CredUnmarshalCredential CredUnmarshalCredentialA
            define CredWrite CredWriteA
            define CredWriteDomainCredentials CredWriteDomainCredentialsA
            define DecryptFile DecryptFileA
            define FlushTrace FlushTraceA
            define GetInheritanceSource GetInheritanceSourceA
            define GetTrusteeForm GetTrusteeFormA
            define LogonUserEx LogonUserExA
            define QueryTrace QueryTraceA
            define RegSaveKeyEx RegSaveKeyExA
            define StopTrace StopTraceA
            define TreeResetNamedSecurityInfo TreeResetNamedSecurityInfoA
            define UpdateTrace UpdateTraceA
            define WmiQueryAllDataMultiple WmiQueryAllDataMultipleA
            define WmiQuerySingleInstanceMultiple WmiQuerySingleInstanceMultipleA
            define WmiReceiveNotifications WmiReceiveNotificationsA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WS03
        import CreateProcessWithTokenW
    #endif

    #if NTDDI_VERSION >= NTDDI_VISTA
        import AddMandatoryAce
        import AuditComputeEffectivePolicyBySid
        import AuditComputeEffectivePolicyByToken
        import AuditEnumerateCategories
        import AuditEnumeratePerUserPolicy
        import AuditEnumerateSubCategories
        import AuditFree
        import AuditLookupCategoryGuidFromCategoryId
        import AuditLookupCategoryIdFromCategoryGuid
        import AuditLookupCategoryNameA
        import AuditLookupCategoryNameW
        import AuditLookupSubCategoryNameA
        import AuditLookupSubCategoryNameW
        import AuditQueryPerUserPolicy
        import AuditQuerySecurity
        import AuditQuerySystemPolicy
        import AuditSetPerUserPolicy
        import AuditSetSecurity
        import AuditSetSystemPolicy
        import CloseThreadWaitChainSession
        import ControlServiceExA
        import ControlServiceExW
        import CredFindBestCredentialA
        import CredFindBestCredentialW
        import CredIsProtectedA
        import CredIsProtectedW
        import CredProtectA
        import CredProtectW
        import CredUnprotectA
        import CredUnprotectW
        import EnumerateTraceGuidsEx
        import EventAccessControl
        import EventAccessQuery
        import EventAccessRemove
        import EventActivityIdControl
        import EventEnabled
        import EventProviderEnabled
        import EventRegister
        import EventUnregister
        import EventWrite
        import EventWriteString
        import EventWriteTransfer
        import FlushEfsCache
        import FreeEncryptedFileMetadata
        import GetEncryptedFileMetadata
        import GetThreadWaitChain
        import I_QueryTagInformation
        import InitiateShutdownA
        import InitiateShutdownW
        import LsaManageSidNameMapping
        import NotifyServiceStatusChangeA
        import NotifyServiceStatusChangeW
        import OpenThreadWaitChainSession
        import PerfCreateInstance
        import PerfDecrementULongCounterValue
        import PerfDecrementULongLongCounterValue
        import PerfDeleteInstance
        import PerfIncrementULongCounterValue
        import PerfIncrementULongLongCounterValue
        import PerfQueryInstance
        import PerfSetCounterRefValue
        import PerfSetCounterSetInfo
        import PerfSetULongCounterValue
        import PerfSetULongLongCounterValue
        import PerfStartProvider
        import PerfStartProviderEx
        import PerfStopProvider
        import QuerySecurityAccessMask
        import RegConnectRegistryExA
        import RegConnectRegistryExW
        import RegCopyTreeA
        import RegCopyTreeW
        import RegCreateKeyTransactedA
        import RegCreateKeyTransactedW
        import RegDeleteKeyExA
        import RegDeleteKeyExW
        import RegDeleteKeyTransactedA
        import RegDeleteKeyTransactedW
        import RegDeleteKeyValueA
        import RegDeleteKeyValueW
        import RegDeleteTreeA
        import RegDeleteTreeW
        import RegDisableReflectionKey
        import RegEnableReflectionKey
        import RegGetValueA
        import RegGetValueW
        import RegLoadAppKeyA
        import RegLoadAppKeyW
        import RegLoadMUIStringA
        import RegLoadMUIStringW
        import RegOpenKeyTransactedA
        import RegOpenKeyTransactedW
        import RegQueryReflectionKey
        import RegSetKeyValueA
        import RegSetKeyValueW
        import RegisterWaitChainCOMCallback
        import SetSecurityAccessMask
        import SetUserFileEncryptionKeyEx
        import TreeSetNamedSecurityInfoA
        import TreeSetNamedSecurityInfoW
        #ifdef APP_UNICODE
            define AuditLookupCategoryName AuditLookupCategoryNameW
            define AuditLookupSubCategoryName AuditLookupSubCategoryNameW
            define ControlServiceEx ControlServiceExW
            define CredFindBestCredential CredFindBestCredentialW
            define CredIsProtected CredIsProtectedW
            define CredProtect CredProtectW
            define CredUnprotect CredUnprotectW
            define InitiateShutdown InitiateShutdownW
            define NotifyServiceStatusChange NotifyServiceStatusChangeW
            define RegConnectRegistryEx RegConnectRegistryExW
            define RegCopyTree RegCopyTreeW
            define RegCreateKeyTransacted RegCreateKeyTransactedW
            define RegDeleteKeyEx RegDeleteKeyExW
            define RegDeleteKeyTransacted RegDeleteKeyTransactedW
            define RegDeleteKeyValue RegDeleteKeyValueW
            define RegDeleteTree RegDeleteTreeW
            define RegGetValue RegGetValueW
            define RegLoadAppKey RegLoadAppKeyW
            define RegLoadMUIString RegLoadMUIStringW
            define RegOpenKeyTransacted RegOpenKeyTransactedW
            define RegSetKeyValue RegSetKeyValueW
            define TreeSetNamedSecurityInfo TreeSetNamedSecurityInfoW
        #else
            define AuditLookupCategoryName AuditLookupCategoryNameA
            define AuditLookupSubCategoryName AuditLookupSubCategoryNameA
            define ControlServiceEx ControlServiceExA
            define CredFindBestCredential CredFindBestCredentialA
            define CredIsProtected CredIsProtectedA
            define CredProtect CredProtectA
            define CredUnprotect CredUnprotectW
            define InitiateShutdown InitiateShutdownA
            define NotifyServiceStatusChange NotifyServiceStatusChangeA
            define RegConnectRegistryEx RegConnectRegistryExA
            define RegCopyTree RegCopyTreeA
            define RegCreateKeyTransacted RegCreateKeyTransactedA
            define RegDeleteKeyEx RegDeleteKeyExA
            define RegDeleteKeyTransacted RegDeleteKeyTransactedA
            define RegDeleteKeyValue RegDeleteKeyValueA
            define RegDeleteTree RegDeleteTreeA
            define RegGetValue RegGetValueA
            define RegLoadAppKey RegLoadAppKeyA
            define RegLoadMUIString RegLoadMUIStringA
            define RegOpenKeyTransacted RegOpenKeyTransactedA
            define RegSetKeyValue RegSetKeyValueA
            define TreeSetNamedSecurityInfo TreeSetNamedSecurityInfoA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WIN7
        import AddConditionalAce
        import AuditQueryGlobalSaclA
        import AuditQueryGlobalSaclW
        import AuditSetGlobalSaclA
        import AuditSetGlobalSaclW
        import CredReadByTokenHandle
        import EnableTraceEx
        import EnableTraceEx2
        import EventWriteEx
        import TraceSetInformation
        #ifdef APP_UNICODE
            define AuditQueryGlobalSacl AuditQueryGlobalSaclW
            define AuditSetGlobalSacl AuditSetGlobalSaclW
        #else
            define AuditQueryGlobalSacl AuditQueryGlobalSaclA
            define AuditSetGlobalSacl AuditSetGlobalSaclA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WIN8
        import BaseRegCloseKey
        import BaseRegCreateKey
        import BaseRegDeleteKeyEx
        import BaseRegDeleteValue
        import BaseRegFlushKey
        import BaseRegGetVersion
        import BaseRegLoadKey
        import BaseRegOpenKey
        import BaseRegRestoreKey
        import BaseRegSaveKeyEx
        import BaseRegSetKeySecurity
        import BaseRegSetValue
        import BaseRegUnLoadKey
        import EnumDynamicTimeZoneInformation
        import EventSetInformation
        import GetDynamicTimeZoneInformationEffectiveYears
        import LsaGetAppliedCAPIDs
        import LsaLookupSids2
        import LsaQueryCAPs
        import LsaSetCAPs
        import OperationEnd
        import OperationStart
        import QueryServiceDynamicInformation
        import TraceQueryInformation
    #endif
#else
    extern AbortSystemShutdownA alias _AbortSystemShutdownA@4
    extern AbortSystemShutdownW alias _AbortSystemShutdownW@4
    extern AccessCheck alias _AccessCheck@32
    extern AccessCheckAndAuditAlarmA alias _AccessCheckAndAuditAlarmA@44
    extern AccessCheckAndAuditAlarmW alias _AccessCheckAndAuditAlarmW@44
    extern AddAccessAllowedAce alias _AddAccessAllowedAce@16
    extern AddAccessDeniedAce alias _AddAccessDeniedAce@16
    extern AddAce alias _AddAce@20
    extern AddAuditAccessAce alias _AddAuditAccessAce@24
    extern AdjustTokenGroups alias _AdjustTokenGroups@24
    extern AdjustTokenPrivileges alias _AdjustTokenPrivileges@24
    extern AllocateAndInitializeSid alias _AllocateAndInitializeSid@44
    extern AllocateLocallyUniqueId alias _AllocateLocallyUniqueId@4
    extern AreAllAccessesGranted alias _AreAllAccessesGranted@8
    extern AreAnyAccessesGranted alias _AreAnyAccessesGranted@8
    extern BackupEventLogA alias _BackupEventLogA@8
    extern BackupEventLogW alias _BackupEventLogW@8
    extern ChangeServiceConfigA alias _ChangeServiceConfigA@44
    extern ChangeServiceConfigW alias _ChangeServiceConfigW@44
    extern ClearEventLogA alias _ClearEventLogA@8
    extern ClearEventLogW alias _ClearEventLogW@8
    extern CloseEventLog alias _CloseEventLog@4
    extern CloseServiceHandle alias _CloseServiceHandle@4
    extern ControlService alias _ControlService@12
    extern CopySid alias _CopySid@12
    extern CreatePrivateObjectSecurity alias _CreatePrivateObjectSecurity@24
    extern CreateServiceA alias _CreateServiceA@52
    extern CreateServiceW alias _CreateServiceW@52
    extern CryptAcquireContextA alias _CryptAcquireContextA@20
    extern CryptAcquireContextW alias _CryptAcquireContextW@20
    extern CryptCreateHash alias _CryptCreateHash@20
    extern CryptDecrypt alias _CryptDecrypt@24
    extern CryptDeriveKey alias _CryptDeriveKey@20
    extern CryptDestroyHash alias _CryptDestroyHash@4
    extern CryptDestroyKey alias _CryptDestroyKey@4
    extern CryptEncrypt alias _CryptEncrypt@28
    extern CryptExportKey alias _CryptExportKey@24
    extern CryptGenKey alias _CryptGenKey@16
    extern CryptGenRandom alias _CryptGenRandom@12
    extern CryptGetHashParam alias _CryptGetHashParam@20
    extern CryptGetKeyParam alias _CryptGetKeyParam@20
    extern CryptGetProvParam alias _CryptGetProvParam@20
    extern CryptGetUserKey alias _CryptGetUserKey@12
    extern CryptHashData alias _CryptHashData@16
    extern CryptHashSessionKey alias _CryptHashSessionKey@12
    extern CryptImportKey alias _CryptImportKey@24
    extern CryptReleaseContext alias _CryptReleaseContext@8
    extern CryptSetHashParam alias _CryptSetHashParam@16
    extern CryptSetKeyParam alias _CryptSetKeyParam@16
    extern CryptSetProviderA alias _CryptSetProviderA@8
    extern CryptSetProviderExA alias _CryptSetProviderExA@16
    extern CryptSetProviderExW alias _CryptSetProviderExW@16
    extern CryptSetProviderW alias _CryptSetProviderW@8
    extern CryptSetProvParam alias _CryptSetProvParam@16
    extern CryptSignHashA alias _CryptSignHashA@24
    extern CryptSignHashW alias _CryptSignHashW@24
    extern CryptVerifySignatureA alias _CryptVerifySignatureA@24
    extern CryptVerifySignatureW alias _CryptVerifySignatureW@24
    extern DeleteAce alias _DeleteAce@8
    extern DeleteService alias _DeleteService@4
    extern DeregisterEventSource alias _DeregisterEventSource@4
    extern DestroyPrivateObjectSecurity alias _DestroyPrivateObjectSecurity@4
    extern DuplicateToken alias _DuplicateToken@12
    extern EnumDependentServicesA alias _EnumDependentServicesA@24
    extern EnumDependentServicesW alias _EnumDependentServicesW@24
    extern EnumServicesStatusA alias _EnumServicesStatusA@32
    extern EnumServicesStatusW alias _EnumServicesStatusW@32
    extern EqualPrefixSid alias _EqualPrefixSid@8
    extern EqualSid alias _EqualSid@8
    extern FindFirstFreeAce alias _FindFirstFreeAce@8
    extern FreeSid alias _FreeSid@4
    extern GetAce alias _GetAce@12
    extern GetAclInformation alias _GetAclInformation@16
    extern GetFileSecurityA alias _GetFileSecurityA@20
    extern GetFileSecurityW alias _GetFileSecurityW@20
    extern GetKernelObjectSecurity alias _GetKernelObjectSecurity@20
    extern GetLengthSid alias _GetLengthSid@4
    extern GetNumberOfEventLogRecords alias _GetNumberOfEventLogRecords@8
    extern GetOldestEventLogRecord alias _GetOldestEventLogRecord@8
    extern GetPrivateObjectSecurity alias _GetPrivateObjectSecurity@20
    extern GetSecurityDescriptorControl alias _GetSecurityDescriptorControl@12
    extern GetSecurityDescriptorDacl alias _GetSecurityDescriptorDacl@16
    extern GetSecurityDescriptorGroup alias _GetSecurityDescriptorGroup@12
    extern GetSecurityDescriptorLength alias _GetSecurityDescriptorLength@4
    extern GetSecurityDescriptorOwner alias _GetSecurityDescriptorOwner@12
    extern GetSecurityDescriptorSacl alias _GetSecurityDescriptorSacl@16
    extern GetServiceDisplayNameA alias _GetServiceDisplayNameA@16
    extern GetServiceDisplayNameW alias _GetServiceDisplayNameW@16
    extern GetServiceKeyNameA alias _GetServiceKeyNameA@16
    extern GetServiceKeyNameW alias _GetServiceKeyNameW@16
    extern GetSidIdentifierAuthority alias _GetSidIdentifierAuthority@4
    extern GetSidLengthRequired alias _GetSidLengthRequired@4
    extern GetSidSubAuthority alias _GetSidSubAuthority@8
    extern GetSidSubAuthorityCount alias _GetSidSubAuthorityCount@4
    extern GetTokenInformation alias _GetTokenInformation@20
    extern GetUserNameA alias _GetUserNameA@8
    extern GetUserNameW alias _GetUserNameW@8
    extern ImpersonateLoggedOnUser alias _ImpersonateLoggedOnUser@4
    extern ImpersonateNamedPipeClient alias _ImpersonateNamedPipeClient@4
    extern ImpersonateSelf alias _ImpersonateSelf@4
    extern InitializeAcl alias _InitializeAcl@12
    extern InitializeSecurityDescriptor alias _InitializeSecurityDescriptor@8
    extern InitializeSid alias _InitializeSid@12
    extern InitiateSystemShutdownA alias _InitiateSystemShutdownA@20
    extern InitiateSystemShutdownW alias _InitiateSystemShutdownW@20
    extern IsTextUnicode alias _IsTextUnicode@12
    extern IsValidAcl alias _IsValidAcl@4
    extern IsValidSecurityDescriptor alias _IsValidSecurityDescriptor@4
    extern IsValidSid alias _IsValidSid@4
    extern LockServiceDatabase alias _LockServiceDatabase@4
    extern LogonUserA alias _LogonUserA@24
    extern LogonUserW alias _LogonUserW@24
    extern LookupAccountNameA alias _LookupAccountNameA@28
    extern LookupAccountNameW alias _LookupAccountNameW@28
    extern LookupAccountSidA alias _LookupAccountSidA@28
    extern LookupAccountSidW alias _LookupAccountSidW@28
    extern LookupPrivilegeDisplayNameA alias _LookupPrivilegeDisplayNameA@20
    extern LookupPrivilegeDisplayNameW alias _LookupPrivilegeDisplayNameW@20
    extern LookupPrivilegeNameA alias _LookupPrivilegeNameA@16
    extern LookupPrivilegeNameW alias _LookupPrivilegeNameW@16
    extern LookupPrivilegeValueA alias _LookupPrivilegeValueA@12
    extern LookupPrivilegeValueW alias _LookupPrivilegeValueW@12
    extern MakeAbsoluteSD alias _MakeAbsoluteSD@44
    extern MakeSelfRelativeSD alias _MakeSelfRelativeSD@12
    extern MapGenericMask alias _MapGenericMask@8
    extern NotifyBootConfigStatus alias _NotifyBootConfigStatus@4
    extern NotifyChangeEventLog alias _NotifyChangeEventLog@8
    extern ObjectCloseAuditAlarmA alias _ObjectCloseAuditAlarmA@12
    extern ObjectCloseAuditAlarmW alias _ObjectCloseAuditAlarmW@12
    extern ObjectOpenAuditAlarmA alias _ObjectOpenAuditAlarmA@48
    extern ObjectOpenAuditAlarmW alias _ObjectOpenAuditAlarmW@48
    extern ObjectPrivilegeAuditAlarmA alias _ObjectPrivilegeAuditAlarmA@24
    extern ObjectPrivilegeAuditAlarmW alias _ObjectPrivilegeAuditAlarmW@24
    extern OpenBackupEventLogA alias _OpenBackupEventLogA@8
    extern OpenBackupEventLogW alias _OpenBackupEventLogW@8
    extern OpenEventLogA alias _OpenEventLogA@8
    extern OpenEventLogW alias _OpenEventLogW@8
    extern OpenSCManagerA alias _OpenSCManagerA@12
    extern OpenSCManagerW alias _OpenSCManagerW@12
    extern OpenServiceA alias _OpenServiceA@12
    extern OpenServiceW alias _OpenServiceW@12
    extern PrivilegeCheck alias _PrivilegeCheck@12
    extern PrivilegedServiceAuditAlarmA alias _PrivilegedServiceAuditAlarmA@20
    extern PrivilegedServiceAuditAlarmW alias _PrivilegedServiceAuditAlarmW@20
    extern QueryServiceConfigA alias _QueryServiceConfigA@16
    extern QueryServiceConfigW alias _QueryServiceConfigW@16
    extern QueryServiceLockStatusA alias _QueryServiceLockStatusA@16
    extern QueryServiceLockStatusW alias _QueryServiceLockStatusW@16
    extern QueryServiceObjectSecurity alias _QueryServiceObjectSecurity@20
    extern QueryServiceStatus alias _QueryServiceStatus@8
    extern ReadEventLogA alias _ReadEventLogA@28
    extern ReadEventLogW alias _ReadEventLogW@28
    extern RegConnectRegistryA alias _RegConnectRegistryA@12
    extern RegConnectRegistryW alias _RegConnectRegistryW@12
    extern RegCloseKey alias _RegCloseKey@4
    extern RegCreateKeyA alias _RegCreateKeyA@12
    extern RegCreateKeyExA alias _RegCreateKeyExA@36
    extern RegCreateKeyExW alias _RegCreateKeyExW@36
    extern RegCreateKeyW alias _RegCreateKeyW@12
    extern RegDeleteKeyA alias _RegDeleteKeyA@8
    extern RegDeleteKeyW alias _RegDeleteKeyW@8
    extern RegDeleteValueA alias _RegDeleteValueA@8
    extern RegDeleteValueW alias _RegDeleteValueW@8
    extern RegEnumKeyA alias _RegEnumKeyA@16
    extern RegEnumKeyExA alias _RegEnumKeyExA@32
    extern RegEnumKeyExW alias _RegEnumKeyExW@32
    extern RegEnumKeyW alias _RegEnumKeyW@16
    extern RegEnumValueA alias _RegEnumValueA@32
    extern RegEnumValueW alias _RegEnumValueW@32
    extern RegFlushKey alias _RegFlushKey@4
    extern RegGetKeySecurity alias _RegGetKeySecurity@16
    extern RegLoadKeyA alias _RegLoadKeyA@12
    extern RegLoadKeyW alias _RegLoadKeyW@12
    extern RegNotifyChangeKeyValue alias _RegNotifyChangeKeyValue@20
    extern RegOpenKeyA alias _RegOpenKeyA@12
    extern RegOpenKeyExA alias _RegOpenKeyExA@20
    extern RegOpenKeyExW alias _RegOpenKeyExW@20
    extern RegOpenKeyW alias _RegOpenKeyW@12
    extern RegQueryInfoKeyA alias _RegQueryInfoKeyA@48
    extern RegQueryInfoKeyW alias _RegQueryInfoKeyW@48
    extern RegQueryMultipleValuesA alias _RegQueryMultipleValuesA@20
    extern RegQueryMultipleValuesW alias _RegQueryMultipleValuesW@20
    extern RegQueryValueA alias _RegQueryValueA@16
    extern RegQueryValueExA alias _RegQueryValueExA@24
    extern RegQueryValueExW alias _RegQueryValueExW@24
    extern RegQueryValueW alias _RegQueryValueW@16
    extern RegReplaceKeyA alias _RegReplaceKeyA@16
    extern RegReplaceKeyW alias _RegReplaceKeyW@16
    extern RegRestoreKeyA alias _RegRestoreKeyA@12
    extern RegRestoreKeyW alias _RegRestoreKeyW@12
    extern RegSaveKeyA alias _RegSaveKeyA@12
    extern RegSaveKeyW alias _RegSaveKeyW@12
    extern RegSetKeySecurity alias _RegSetKeySecurity@12
    extern RegSetValueA alias _RegSetValueA@20
    extern RegSetValueExA alias _RegSetValueExA@24
    extern RegSetValueExW alias _RegSetValueExW@24
    extern RegSetValueW alias _RegSetValueW@20
    extern RegUnLoadKeyA alias _RegUnLoadKeyA@8
    extern RegUnLoadKeyW alias _RegUnLoadKeyW@8
    extern RegisterEventSourceA alias _RegisterEventSourceA@8
    extern RegisterEventSourceW alias _RegisterEventSourceW@8
    extern RegisterServiceCtrlHandlerA alias _RegisterServiceCtrlHandlerA@8
    extern RegisterServiceCtrlHandlerW alias _RegisterServiceCtrlHandlerW@8
    extern ReportEventA alias _ReportEventA@36
    extern ReportEventW alias _ReportEventW@36
    extern RevertToSelf alias _RevertToSelf@0
    extern SetAclInformation alias _SetAclInformation@16
    extern SetFileSecurityA alias _SetFileSecurityA@12
    extern SetFileSecurityW alias _SetFileSecurityW@12
    extern SetKernelObjectSecurity alias _SetKernelObjectSecurity@12
    extern SetPrivateObjectSecurity alias _SetPrivateObjectSecurity@20
    extern SetSecurityDescriptorDacl alias _SetSecurityDescriptorDacl@16
    extern SetSecurityDescriptorGroup alias _SetSecurityDescriptorGroup@12
    extern SetSecurityDescriptorOwner alias _SetSecurityDescriptorOwner@12
    extern SetSecurityDescriptorSacl alias _SetSecurityDescriptorSacl@16
    extern SetServiceBits alias _SetServiceBits@16
    extern SetServiceObjectSecurity alias _SetServiceObjectSecurity@12
    extern SetServiceStatus alias _SetServiceStatus@8
    extern SetThreadToken alias _SetThreadToken@8
    extern SetTokenInformation alias _SetTokenInformation@16
    extern StartServiceA alias _StartServiceA@12
    extern StartServiceCtrlDispatcherA alias _StartServiceCtrlDispatcherA@4
    extern StartServiceCtrlDispatcherW alias _StartServiceCtrlDispatcherW@4
    extern StartServiceW alias _StartServiceW@12
    extern UnlockServiceDatabase alias _UnlockServiceDatabase@4

    #if NTDDI_VERSION >= NTDDI_WIN98_ME
        extern BuildExplicitAccessWithNameA alias _BuildExplicitAccessWithNameA@20
        extern BuildExplicitAccessWithNameW alias _BuildExplicitAccessWithNameW@20
        extern BuildSecurityDescriptorA alias _BuildSecurityDescriptorA@36
        extern BuildSecurityDescriptorW alias _BuildSecurityDescriptorW@36
        extern BuildTrusteeWithNameA alias _BuildTrusteeWithNameA@8
        extern BuildTrusteeWithNameW alias _BuildTrusteeWithNameW@8
        extern BuildTrusteeWithSidA alias _BuildTrusteeWithSidA@8
        extern BuildTrusteeWithSidW alias _BuildTrusteeWithSidW@8
        extern ConvertAccessToSecurityDescriptorA alias _ConvertAccessToSecurityDescriptorA@20
        extern ConvertAccessToSecurityDescriptorW alias _ConvertAccessToSecurityDescriptorW@20
        extern ConvertSecurityDescriptorToAccessA alias _ConvertSecurityDescriptorToAccessA@28
        extern ConvertSecurityDescriptorToAccessW alias _ConvertSecurityDescriptorToAccessW@28
        extern ConvertSecurityDescriptorToAccessNamedA alias _ConvertSecurityDescriptorToAccessNamedA@28
        extern ConvertSecurityDescriptorToAccessNamedW alias _ConvertSecurityDescriptorToAccessNamedW@28
        extern CryptContextAddRef alias _CryptContextAddRef@12
        extern CryptDuplicateHash alias _CryptDuplicateHash@16
        extern CryptDuplicateKey alias _CryptDuplicateKey@16
        extern CryptEnumProvidersA alias _CryptEnumProvidersA@24
        extern CryptEnumProviderTypesA alias _CryptEnumProviderTypesA@24
        extern CryptEnumProviderTypesW alias _CryptEnumProviderTypesW@24
        extern CryptEnumProvidersW alias _CryptEnumProvidersW@24
        extern CryptGetDefaultProviderA alias _CryptGetDefaultProviderA@20
        extern CryptGetDefaultProviderW alias _CryptGetDefaultProviderW@20
        extern DuplicateTokenEx alias _DuplicateTokenEx@24
        extern GetAccessPermissionsForObjectA alias _GetAccessPermissionsForObjectA@36
        extern GetAccessPermissionsForObjectW alias _GetAccessPermissionsForObjectW@36
        extern GetAuditedPermissionsFromAclA alias _GetAuditedPermissionsFromAclA@16
        extern GetAuditedPermissionsFromAclW alias _GetAuditedPermissionsFromAclW@16
        extern GetCurrentHwProfileA alias _GetCurrentHwProfileA@4
        extern GetCurrentHwProfileW alias _GetCurrentHwProfileW@4
        extern GetEffectiveRightsFromAclA alias _GetEffectiveRightsFromAclA@12
        extern GetEffectiveRightsFromAclW alias _GetEffectiveRightsFromAclW@12
        extern GetExplicitEntriesFromAclA alias _GetExplicitEntriesFromAclA@12
        extern GetExplicitEntriesFromAclW alias _GetExplicitEntriesFromAclW@12
        extern GetMultipleTrusteeA alias _GetMultipleTrusteeA@4
        extern GetMultipleTrusteeOperationA alias _GetMultipleTrusteeOperationA@4
        extern GetMultipleTrusteeOperationW alias _GetMultipleTrusteeOperationW@4
        extern GetMultipleTrusteeW alias _GetMultipleTrusteeW@4
        extern GetNamedSecurityInfoA alias _GetNamedSecurityInfoA@32
        extern GetNamedSecurityInfoExA alias _GetNamedSecurityInfoExA@36
        extern GetNamedSecurityInfoExW alias _GetNamedSecurityInfoExW@36
        extern GetNamedSecurityInfoW alias _GetNamedSecurityInfoW@32
        extern GetOverlappedAccessResults alias _GetOverlappedAccessResults@16
        extern GetSecurityInfo alias _GetSecurityInfo@32
        extern GetSecurityInfoExA alias _GetSecurityInfoExA@24
        extern GetSecurityInfoExW alias _GetSecurityInfoExW@24
        extern GetTrusteeNameA alias _GetTrusteeNameA@4
        extern GetTrusteeNameW alias _GetTrusteeNameW@4
        extern GetTrusteeTypeA alias _GetTrusteeTypeA@4
        extern GetTrusteeTypeW alias _GetTrusteeTypeW@4
        extern LookupSecurityDescriptorPartsA alias _LookupSecurityDescriptorPartsA@28
        extern LookupSecurityDescriptorPartsW alias _LookupSecurityDescriptorPartsW@28
        extern ObjectDeleteAuditAlarmA alias _ObjectDeleteAuditAlarmA@12
        extern ObjectDeleteAuditAlarmW alias _ObjectDeleteAuditAlarmW@12
        extern SetEntriesInAccessListA alias _SetEntriesInAccessListA@24
        extern SetEntriesInAccessListW alias _SetEntriesInAccessListW@24
        extern SetEntriesInAclA alias _SetEntriesInAclA@16
        extern SetEntriesInAclW alias _SetEntriesInAclW@16
        extern SetEntriesInAuditListA alias _SetEntriesInAuditListA@24
        extern SetEntriesInAuditListW alias _SetEntriesInAuditListW@24
        extern SetNamedSecurityInfoA alias _SetNamedSecurityInfoA@28
        extern SetNamedSecurityInfoExA alias _SetNamedSecurityInfoExA@36
        extern SetNamedSecurityInfoExW alias _SetNamedSecurityInfoExW@36
        extern SetNamedSecurityInfoW alias _SetNamedSecurityInfoW@28
        extern SetSecurityInfo alias _SetSecurityInfo@28
        extern SetSecurityInfoExA alias _SetSecurityInfoExA@36
        extern SetSecurityInfoExW alias _SetSecurityInfoExW@36
        extern TrusteeAccessToObjectA alias _TrusteeAccessToObjectA@24
        extern TrusteeAccessToObjectW alias _TrusteeAccessToObjectW@24
        #ifdef APP_UNICODE
            define BuildExplicitAccessWithName BuildExplicitAccessWithNameW
            define BuildSecurityDescriptor BuildSecurityDescriptorW
            define BuildTrusteeWithName BuildTrusteeWithNameW
            define BuildTrusteeWithSid BuildTrusteeWithSidW
            define ConvertAccessToSecurityDescriptor ConvertAccessToSecurityDescriptorW
            define ConvertSecurityDescriptorToAccess ConvertSecurityDescriptorToAccessW
            define ConvertSecurityDescriptorToAccessNamed ConvertSecurityDescriptorToAccessNamedW
            define CryptEnumProviders CryptEnumProvidersW
            define CryptEnumProviderTypes CryptEnumProviderTypesW
            define CryptGetDefaultProvider CryptGetDefaultProviderW
            define GetAccessPermissionsForObject GetAccessPermissionsForObjectW
            define GetAuditedPermissionsFromAcl GetAuditedPermissionsFromAclW
            define GetCurrentHwProfile GetCurrentHwProfileW
            define GetEffectiveRightsFromAcl GetEffectiveRightsFromAclW
            define GetExplicitEntriesFromAcl GetExplicitEntriesFromAclW
            define GetMultipleTrustee GetMultipleTrusteeW
            define GetMultipleTrusteeOperation GetMultipleTrusteeOperationW
            define GetNamedSecurityInfo GetNamedSecurityInfoW
            define GetNamedSecurityInfoEx GetNamedSecurityInfoExW
            define GetSecurityInfoEx GetSecurityInfoExW
            define GetTrusteeName GetTrusteeNameW
            define GetTrusteeType GetTrusteeTypeW
            define LookupSecurityDescriptorParts LookupSecurityDescriptorPartsW
            define ObjectDeleteAuditAlarm ObjectDeleteAuditAlarmW
            define SetEntriesInAccessList SetEntriesInAccessListW
            define SetEntriesInAcl SetEntriesInAclW
            define SetEntriesInAuditList SetEntriesInAuditListW
            define SetNamedSecurityInfo SetNamedSecurityInfoW
            define SetNamedSecurityInfoEx SetNamedSecurityInfoExW
            define SetSecurityInfoEx SetSecurityInfoExW
            define TrusteeAccessToObject TrusteeAccessToObjectW
        #else
            define BuildExplicitAccessWithName BuildExplicitAccessWithNameA
            define BuildSecurityDescriptor BuildSecurityDescriptorA
            define BuildTrusteeWithName BuildTrusteeWithNameA
            define BuildTrusteeWithSid BuildTrusteeWithSidA
            define ConvertAccessToSecurityDescriptor ConvertAccessToSecurityDescriptorA
            define ConvertSecurityDescriptorToAccess ConvertSecurityDescriptorToAccessA
            define ConvertSecurityDescriptorToAccessNamed ConvertSecurityDescriptorToAccessNamedA
            define CryptEnumProviders CryptEnumProvidersA
            define CryptEnumProviderTypes CryptEnumProviderTypesA
            define CryptGetDefaultProvider CryptGetDefaultProviderA
            define GetAccessPermissionsForObject GetAccessPermissionsForObjectA
            define GetAuditedPermissionsFromAcl GetAuditedPermissionsFromAclA
            define GetCurrentHwProfile GetCurrentHwProfileA
            define GetEffectiveRightsFromAcl GetEffectiveRightsFromAclA
            define GetExplicitEntriesFromAcl GetExplicitEntriesFromAclA
            define GetMultipleTrustee GetMultipleTrusteeA
            define GetMultipleTrusteeOperation GetMultipleTrusteeOperationA
            define GetNamedSecurityInfo GetNamedSecurityInfoA
            define GetNamedSecurityInfoEx GetNamedSecurityInfoExA
            define GetSecurityInfoEx GetSecurityInfoExA
            define GetTrusteeName GetTrusteeNameA
            define GetTrusteeType GetTrusteeTypeA
            define LookupSecurityDescriptorParts LookupSecurityDescriptorPartsA
            define ObjectDeleteAuditAlarm ObjectDeleteAuditAlarmA
            define SetEntriesInAccessList SetEntriesInAccessListA
            define SetEntriesInAcl SetEntriesInAclA
            define SetEntriesInAuditList SetEntriesInAuditListA
            define SetNamedSecurityInfo SetNamedSecurityInfoA
            define SetNamedSecurityInfoEx SetNamedSecurityInfoExA
            define SetSecurityInfoEx SetSecurityInfoExA
            define TrusteeAccessToObject TrusteeAccessToObjectA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WINNT4
        extern CreateProcessAsUserA alias _CreateProcessAsUserA@44
        extern CreateProcessAsUserW alias _CreateProcessAsUserW@44
        extern ElfBackupEventLogFileA alias _ElfBackupEventLogFileA@8
        extern ElfBackupEventLogFileW alias _ElfBackupEventLogFileW@8
        extern ElfChangeNotify alias _ElfChangeNotify@8
        extern ElfClearEventLogFileA alias _ElfClearEventLogFileA@8
        extern ElfClearEventLogFileW alias _ElfClearEventLogFileW@8
        extern ElfCloseEventLog alias _ElfCloseEventLog@4
        extern ElfDeregisterEventSource alias _ElfDeregisterEventSource@4
        extern ElfNumberOfRecords alias _ElfNumberOfRecords@8
        extern ElfOldestRecord alias _ElfOldestRecord@8
        extern ElfOpenBackupEventLogA alias _ElfOpenBackupEventLogA@12
        extern ElfOpenBackupEventLogW alias _ElfOpenBackupEventLogW@12
        extern ElfOpenEventLogA alias _ElfOpenEventLogA@12
        extern ElfOpenEventLogW alias _ElfOpenEventLogW@12
        extern ElfReadEventLogA alias _ElfReadEventLogA@28
        extern ElfReadEventLogW alias _ElfReadEventLogW@28
        extern ElfRegisterEventSourceA alias _ElfRegisterEventSourceA@12
        extern ElfRegisterEventSourceW alias _ElfRegisterEventSourceW@12
        extern ElfReportEventA alias _ElfReportEventA@48
        extern ElfReportEventW alias _ElfReportEventW@48
        extern EnumServiceGroupW alias _EnumServiceGroupW@36
        extern EnumServicesStatusExA alias _EnumServicesStatusExA@40
        extern EnumServicesStatusExW alias _EnumServicesStatusExW@40
        extern IsTokenUntrusted alias _IsTokenUntrusted@4
        extern LsaAddAccountRights alias _LsaAddAccountRights@16
        extern LsaAddPrivilegesToAccount alias _LsaAddPrivilegesToAccount@8
        extern LsaClearAuditLog alias _LsaClearAuditLog@4
        extern LsaClose alias _LsaClose@4
        extern LsaCreateAccount alias _LsaCreateAccount@16
        extern LsaCreateSecret alias _LsaCreateSecret@16
        extern LsaCreateTrustedDomain alias _LsaCreateTrustedDomain@16
        extern LsaDelete alias _LsaDelete@4
        extern LsaDeleteTrustedDomain alias _LsaDeleteTrustedDomain@8
        extern LsaEnumerateAccountRights alias _LsaEnumerateAccountRights@16
        extern LsaEnumerateAccounts alias _LsaEnumerateAccounts@20
        extern LsaEnumerateAccountsWithUserRight alias _LsaEnumerateAccountsWithUserRight@16
        extern LsaEnumeratePrivileges alias _LsaEnumeratePrivileges@20
        extern LsaEnumeratePrivilegesOfAccount alias _LsaEnumeratePrivilegesOfAccount@8
        extern LsaEnumerateTrustedDomains alias _LsaEnumerateTrustedDomains@20
        extern LsaFreeMemory alias _LsaFreeMemory@4
        extern LsaGetQuotasForAccount alias _LsaGetQuotasForAccount@8
        extern LsaGetRemoteUserName alias _LsaGetRemoteUserName@12
        extern LsaGetSystemAccessAccount alias _LsaGetSystemAccessAccount@8
        extern LsaGetUserName alias _LsaGetUserName@8
        extern LsaLookupNames alias _LsaLookupNames@20
        extern LsaLookupPrivilegeDisplayName alias _LsaLookupPrivilegeDisplayName@16
        extern LsaLookupPrivilegeName alias _LsaLookupPrivilegeName@12
        extern LsaLookupPrivilegeValue alias _LsaLookupPrivilegeValue@12
        extern LsaLookupSids alias _LsaLookupSids@20
        extern LsaNtStatusToWinError alias _LsaNtStatusToWinError@4
        extern LsaOpenAccount alias _LsaOpenAccount@16
        extern LsaOpenPolicy alias _LsaOpenPolicy@16
        extern LsaOpenSecret alias _LsaOpenSecret@16
        extern LsaOpenTrustedDomain alias _LsaOpenTrustedDomain@16
        extern LsaOpenTrustedDomainByName alias _LsaOpenTrustedDomainByName@16
        extern LsaQueryInformationPolicy alias _LsaQueryInformationPolicy@12
        extern LsaQuerySecret alias _LsaQuerySecret@20
        extern LsaQuerySecurityObject alias _LsaQuerySecurityObject@12
        extern LsaQueryTrustedDomainInfo alias _LsaQueryTrustedDomainInfo@16
        extern LsaRemoveAccountRights alias _LsaRemoveAccountRights@20
        extern LsaRemovePrivilegesFromAccount alias _LsaRemovePrivilegesFromAccount@12
        extern LsaRetrievePrivateData alias _LsaRetrievePrivateData@12
        extern LsaSetInformationPolicy alias _LsaSetInformationPolicy@12
        extern LsaSetInformationTrustedDomain alias _LsaSetInformationTrustedDomain@12
        extern LsaSetQuotasForAccount alias _LsaSetQuotasForAccount@8
        extern LsaSetSecret alias _LsaSetSecret@12
        extern LsaSetSecurityObject alias _LsaSetSecurityObject@12
        extern LsaSetSystemAccessAccount alias _LsaSetSystemAccessAccount@8
        extern LsaSetTrustedDomainInformation alias _LsaSetTrustedDomainInformation@16
        extern LsaStorePrivateData alias _LsaStorePrivateData@12
        extern OpenProcessToken alias _OpenProcessToken@12
        extern OpenThreadToken alias _OpenThreadToken@16
        #ifdef APP_UNICODE
            define CreateProcessAsUser CreateProcessAsUserW
            define ElfBackupEventLogFile ElfBackupEventLogFileW
            define ElfClearEventLogFile ElfClearEventLogFileW
            define ElfOpenBackupEventLog ElfOpenBackupEventLogW
            define ElfOpenEventLog ElfOpenEventLogW
            define ElfReadEventLog ElfReadEventLogW
            define ElfRegisterEventSource ElfRegisterEventSourceW
            define ElfReportEvent ElfReportEventW
            define EnumServicesStatusEx EnumServicesStatusExW
        #else
            define CreateProcessAsUser CreateProcessAsUserA
            define ElfBackupEventLogFile ElfBackupEventLogFileA
            define ElfClearEventLogFile ElfClearEventLogFileA
            define ElfOpenBackupEventLog ElfOpenBackupEventLogA
            define ElfOpenEventLog ElfOpenEventLogA
            define ElfReadEventLog ElfReadEventLogA
            define ElfRegisterEventSource ElfRegisterEventSourceA
            define ElfReportEvent ElfReportEventA
            define EnumServicesStatusEx EnumServicesStatusExA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WIN2K
        extern AccessCheckByType alias _AccessCheckByType@44
        extern AccessCheckByTypeAndAuditAlarmA alias _AccessCheckByTypeAndAuditAlarmA@64
        extern AccessCheckByTypeAndAuditAlarmW alias _AccessCheckByTypeAndAuditAlarmW@64
        extern AccessCheckByTypeResultList alias _AccessCheckByTypeResultList@44
        extern AccessCheckByTypeResultListAndAuditAlarmA alias _AccessCheckByTypeResultListAndAuditAlarmA@64
        extern AccessCheckByTypeResultListAndAuditAlarmW alias _AccessCheckByTypeResultListAndAuditAlarmW@64
        extern AccessCheckByTypeResultListAndAuditAlarmByHandleA alias _AccessCheckByTypeResultListAndAuditAlarmByHandleA@68
        extern AccessCheckByTypeResultListAndAuditAlarmByHandleW alias _AccessCheckByTypeResultListAndAuditAlarmByHandleW@68
        extern AddAccessAllowedAceEx alias _AddAccessAllowedAceEx@20
        extern AddAccessAllowedObjectAce alias _AddAccessAllowedObjectAce@28
        extern AddAccessDeniedAceEx alias _AddAccessDeniedAceEx@20
        extern AddAccessDeniedObjectAce alias _AddAccessDeniedObjectAce@28
        extern AddAuditAccessAceEx alias _AddAuditAccessAceEx@28
        extern AddAuditAccessObjectAce alias _AddAuditAccessObjectAce@36
        extern AddUsersToEncryptedFile alias _AddUsersToEncryptedFile@8
        extern BuildTrusteeWithObjectsAndNameA alias _BuildTrusteeWithObjectsAndNameA@24
        extern BuildTrusteeWithObjectsAndNameW alias _BuildTrusteeWithObjectsAndNameW@24
        extern BuildTrusteeWithObjectsAndSidA alias _BuildTrusteeWithObjectsAndSidA@20
        extern BuildTrusteeWithObjectsAndSidW alias _BuildTrusteeWithObjectsAndSidW@20
        extern CheckTokenMembership alias _CheckTokenMembership@12
        extern CloseEncryptedFileRaw alias _CloseEncryptedFileRaw@4
        extern CloseTrace alias _CloseTrace@4
        extern CommandLineFromMsiDescriptor alias _CommandLineFromMsiDescriptor@12
        extern ControlTraceA alias _ControlTraceA@12
        extern ControlTraceW alias _ControlTraceW@12
        extern ConvertSDToStringSDRootDomainA alias _ConvertSDToStringSDRootDomainA@24
        extern ConvertSDToStringSDRootDomainW alias _ConvertSDToStringSDRootDomainW@24
        extern ConvertSecurityDescriptorToStringSecurityDescriptorA alias _ConvertSecurityDescriptorToStringSecurityDescriptorA@12
        extern ConvertSecurityDescriptorToStringSecurityDescriptorW alias _ConvertSecurityDescriptorToStringSecurityDescriptorW@12
        extern ConvertSidToStringSidA alias _ConvertSidToStringSidA@8
        extern ConvertSidToStringSidW alias _ConvertSidToStringSidW@8
        extern ConvertStringSDToSDRootDomainA alias _ConvertStringSDToSDRootDomainA@20
        extern ConvertStringSDToSDRootDomainW alias _ConvertStringSDToSDRootDomainW@20
        extern ConvertStringSecurityDescriptorToSecurityDescriptorA alias _ConvertStringSecurityDescriptorToSecurityDescriptorA@16
        extern ConvertStringSecurityDescriptorToSecurityDescriptorW alias _ConvertStringSecurityDescriptorToSecurityDescriptorW@16
        extern ConvertStringSidToSidA alias _ConvertStringSidToSidA@8
        extern ConvertStringSidToSidW alias _ConvertStringSidToSidW@8
        extern ConvertToAutoInheritPrivateObjectSecurity alias _ConvertToAutoInheritPrivateObjectSecurity@24
        extern CreatePrivateObjectSecurityEx alias _CreatePrivateObjectSecurityEx@32
        extern CreateProcessWithLogonW alias _CreateProcessWithLogonW@44
        extern CreateRestrictedToken alias _CreateRestrictedToken@36
        extern CreateTraceInstanceId alias _CreateTraceInstanceId@8
        extern CreateWellKnownSid alias _CreateWellKnownSid@16
        extern EnableTrace alias _EnableTrace@20
        extern EncryptFileA alias _EncryptFileA@4
        extern EncryptFileW alias _EncryptFileW@4
        extern EncryptionDisable alias _EncryptionDisable@8
        extern EqualDomainSid alias _EqualDomainSid@12
        extern FileEncryptionStatusA alias _FileEncryptionStatusA@8
        extern FileEncryptionStatusW alias _FileEncryptionStatusW@8
        extern FreeEncryptionCertificateHashList alias _FreeEncryptionCertificateHashList@4
        extern GetEventLogInformation alias _GetEventLogInformation@20
        extern GetLocalManagedApplications alias _GetLocalManagedApplications@12
        extern GetManagedApplications alias _GetManagedApplications@20
        extern ImpersonateAnonymousToken alias _ImpersonateAnonymousToken@4
        extern InitiateSystemShutdownExA alias _InitiateSystemShutdownExA@24
        extern InitiateSystemShutdownExW alias _InitiateSystemShutdownExW@24
        extern InstallApplication alias _InstallApplication@4
        extern IsTokenRestricted alias _IsTokenRestricted@4
        extern LsaCreateTrustedDomainEx alias _LsaCreateTrustedDomainEx@12
        extern LsaEnumerateTrustedDomainsEx alias _LsaEnumerateTrustedDomainsEx@20
        extern LsaOpenPolicySce alias _LsaOpenPolicySce@16
        extern LsaQueryDomainInformationPolicy alias _LsaQueryDomainInformationPolicy@12
        extern LsaQueryInfoTrustedDomain alias _LsaQueryInfoTrustedDomain@12
        extern LsaQueryTrustedDomainInfoByName alias _LsaQueryTrustedDomainInfoByName@16
        extern LsaSetDomainInformationPolicy alias _LsaSetDomainInformationPolicy@12
        extern LsaSetTrustedDomainInfoByName alias _LsaSetTrustedDomainInfoByName@16
        extern MakeAbsoluteSD2 alias _MakeAbsoluteSD2@8
        extern OpenEncryptedFileRawA alias _OpenEncryptedFileRawA@12
        extern OpenEncryptedFileRawW alias _OpenEncryptedFileRawW@12
        extern OpenTraceA alias _OpenTraceA@4
        extern OpenTraceW alias _OpenTraceW@4
        extern QueryAllTracesA alias _QueryAllTracesA@12
        extern QueryAllTracesW alias _QueryAllTracesW@12
        extern QueryRecoveryAgentsOnEncryptedFile alias _QueryRecoveryAgentsOnEncryptedFile@8
        extern QueryServiceConfig2A alias _QueryServiceConfig2A@20
        extern QueryServiceConfig2W alias _QueryServiceConfig2W@20
        extern QueryServiceStatusEx alias _QueryServiceStatusEx@20
        extern QueryUsersOnEncryptedFile alias _QueryUsersOnEncryptedFile@8
        extern ReadEncryptedFileRaw alias _ReadEncryptedFileRaw@12
        extern RegDisablePredefinedCache alias _RegDisablePredefinedCache@0
        extern RegOpenCurrentUser alias _RegOpenCurrentUser@8
        extern RegOpenUserClassesRoot alias _RegOpenUserClassesRoot@16
        extern RegOverridePredefKey alias _RegOverridePredefKey@8
        extern RegisterServiceCtrlHandlerExA alias _RegisterServiceCtrlHandlerExA@12
        extern RegisterServiceCtrlHandlerExW alias _RegisterServiceCtrlHandlerExW@12
        extern RegisterTraceGuidsA alias _RegisterTraceGuidsA@32
        extern RegisterTraceGuidsW alias _RegisterTraceGuidsW@32
        extern RemoveUsersFromEncryptedFile alias _RemoveUsersFromEncryptedFile@8
        extern RemoveTraceCallback alias _RemoveTraceCallback@4
        extern SetPrivateObjectSecurityEx alias _SetPrivateObjectSecurityEx@24
        extern SetSecurityDescriptorControl alias _SetSecurityDescriptorControl@12
        extern SetSecurityDescriptorRMControl alias _SetSecurityDescriptorRMControl@8
        extern SetTraceCallback alias _SetTraceCallback@8
        extern SetUserFileEncryptionKey alias _SetUserFileEncryptionKey@4
        extern StartTraceA alias _StartTraceA@12
        extern StartTraceW alias _StartTraceW@12
        extern TraceEvent alias _TraceEvent@8
        extern TraceEventInstance alias _TraceEventInstance@16
        extern UninstallApplication alias _UninstallApplication@8
        extern UnregisterTraceGuids alias _UnregisterTraceGuids@4
        extern WmiCloseBlock alias _WmiCloseBlock@4
        extern WmiEnumerateGuids alias _WmiEnumerateGuids@8
        extern WmiDevInstToInstanceNameA alias _WmiDevInstToInstanceNameA@16
        extern WmiDevInstToInstanceNameW alias _WmiDevInstToInstanceNameW@16
        extern WmiExecuteMethodA alias _WmiExecuteMethodA@28
        extern WmiExecuteMethodW alias _WmiExecuteMethodW@28
        extern WmiFileHandleToInstanceNameA alias _WmiFileHandleToInstanceNameA@16
        extern WmiFileHandleToInstanceNameW alias _WmiFileHandleToInstanceNameW@16
        extern WmiFreeBuffer alias _WmiFreeBuffer@4
        extern WmiMofEnumerateResourcesA alias _WmiMofEnumerateResourcesA@12
        extern WmiMofEnumerateResourcesW alias _WmiMofEnumerateResourcesW@12
        extern WmiNotificationRegistrationA alias _WmiNotificationRegistrationA@20
        extern WmiNotificationRegistrationW alias _WmiNotificationRegistrationW@20
        extern WmiOpenBlock alias _WmiOpenBlock@12
        extern WmiQueryAllDataA alias _WmiQueryAllDataA@12
        extern WmiQueryAllDataW alias _WmiQueryAllDataW@12
        extern WmiQueryGuidInformation alias _WmiQueryGuidInformation@8
        extern WmiQuerySingleInstanceA alias _WmiQuerySingleInstanceA@16
        extern WmiQuerySingleInstanceW alias _WmiQuerySingleInstanceW@16
        extern WmiSetSingleInstanceA alias _WmiSetSingleInstanceA@20
        extern WmiSetSingleInstanceW alias _WmiSetSingleInstanceW@20
        extern WmiSetSingleItemA alias _WmiSetSingleItemA@24
        extern WmiSetSingleItemW alias _WmiSetSingleItemW@24
        extern WriteEncryptedFileRaw alias _WriteEncryptedFileRaw@12
        #ifdef APP_UNICODE
            define AccessCheckByTypeAndAuditAlarm AccessCheckByTypeAndAuditAlarmW
            define AccessCheckByTypeResultListAndAuditAlarm AccessCheckByTypeResultListAndAuditAlarmW
            define AccessCheckByTypeResultListAndAuditAlarmByHandle AccessCheckByTypeResultListAndAuditAlarmByHandleW
            define BuildTrusteeWithObjectsAndName BuildTrusteeWithObjectsAndNameW
            define BuildTrusteeWithObjectsAndSid BuildTrusteeWithObjectsAndSidW
            define ControlTrace ControlTraceW
            define ConvertSDToStringSDRootDomain ConvertSDToStringSDRootDomainW
            define ConvertSecurityDescriptorToStringSecurityDescriptor ConvertSecurityDescriptorToStringSecurityDescriptorW
            define ConvertSidToStringSid ConvertSidToStringSidW
            define ConvertStringSDToSDRootDomain ConvertStringSDToSDRootDomainW
            define ConvertStringSecurityDescriptorToSecurityDescriptor ConvertStringSecurityDescriptorToSecurityDescriptorW
            define ConvertStringSidToSid ConvertStringSidToSidW
            define EncryptFile EncryptFileW
            define FileEncryptionStatus FileEncryptionStatusW
            define InitiateSystemShutdownEx InitiateSystemShutdownExW
            define OpenEncryptedFileRaw OpenEncryptedFileRawW
            define OpenTrace OpenTraceW
            define QueryAllTraces QueryAllTracesW
            define QueryServiceConfig2 QueryServiceConfig2W
            define RegisterServiceCtrlHandlerEx RegisterServiceCtrlHandlerExW
            define RegisterTraceGuids RegisterTraceGuidsW
            define StartTrace StartTraceW
            define WmiDevInstToInstanceName WmiDevInstToInstanceNameW
            define WmiExecuteMethod WmiExecuteMethodW
            define WmiFileHandleToInstanceName WmiFileHandleToInstanceNameW
            define WmiMofEnumerateResources WmiMofEnumerateResourcesW
            define WmiNotificationRegistration WmiNotificationRegistrationW
            define WmiQueryAllData WmiQueryAllDataW
            define WmiQuerySingleInstance WmiQuerySingleInstanceW
            define WmiSetSingleInstance WmiSetSingleInstanceW
            define WmiSetSingleItem WmiSetSingleItemW
        #else
            define AccessCheckByTypeAndAuditAlarm AccessCheckByTypeAndAuditAlarmA
            define AccessCheckByTypeResultListAndAuditAlarm AccessCheckByTypeResultListAndAuditAlarmA
            define AccessCheckByTypeResultListAndAuditAlarmByHandle AccessCheckByTypeResultListAndAuditAlarmByHandleA
            define BuildTrusteeWithObjectsAndName BuildTrusteeWithObjectsAndNameA
            define BuildTrusteeWithObjectsAndSid BuildTrusteeWithObjectsAndSidA
            define ControlTrace ControlTraceA
            define ConvertSDToStringSDRootDomain ConvertSDToStringSDRootDomainA
            define ConvertSecurityDescriptorToStringSecurityDescriptor ConvertSecurityDescriptorToStringSecurityDescriptorA
            define ConvertSidToStringSid ConvertSidToStringSidA
            define ConvertStringSDToSDRootDomain ConvertStringSDToSDRootDomainA
            define ConvertStringSecurityDescriptorToSecurityDescriptor ConvertStringSecurityDescriptorToSecurityDescriptorA
            define ConvertStringSidToSid ConvertStringSidToSidA
            define EncryptFile EncryptFileA
            define FileEncryptionStatus FileEncryptionStatusA
            define InitiateSystemShutdownEx InitiateSystemShutdownExA
            define OpenEncryptedFileRaw OpenEncryptedFileRawA
            define OpenTrace OpenTraceA
            define QueryAllTraces QueryAllTracesA
            define QueryServiceConfig2 QueryServiceConfig2A
            define RegisterServiceCtrlHandlerEx RegisterServiceCtrlHandlerExA
            define RegisterTraceGuids RegisterTraceGuidsA
            define StartTrace StartTraceA
            define WmiDevInstToInstanceName WmiDevInstToInstanceNameA
            define WmiExecuteMethod WmiExecuteMethodA
            define WmiFileHandleToInstanceName WmiFileHandleToInstanceNameA
            define WmiMofEnumerateResources WmiMofEnumerateResourcesA
            define WmiNotificationRegistration WmiNotificationRegistrationA
            define WmiQueryAllData WmiQueryAllDataA
            define WmiQuerySingleInstance WmiQuerySingleInstanceA
            define WmiSetSingleInstance WmiSetSingleInstanceA
            define WmiSetSingleItem WmiSetSingleItemA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WINXP
        extern A_SHAFinal alias _A_SHAFinal@8
        extern A_SHAInit alias _A_SHAInit@4
        extern A_SHAUpdate alias _A_SHAUpdate@12
        extern ChangeServiceConfig2A alias _ChangeServiceConfig2A@12
        extern ChangeServiceConfig2W alias _ChangeServiceConfig2W@12
        extern ConvertStringSDToSDDomainA alias _ConvertStringSDToSDDomainA@24
        extern ConvertStringSDToSDDomainW alias _ConvertStringSDToSDDomainW@24
        extern CreatePrivateObjectSecurityWithMultipleInheritance alias _CreatePrivateObjectSecurityWithMultipleInheritance@36
        extern CredDeleteA alias _CredDeleteA@12
        extern CredDeleteW alias _CredDeleteW@12
        extern CredEnumerateA alias _CredEnumerateA@16
        extern CredEnumerateW alias _CredEnumerateW@16
        extern CredFree alias _CredFree@4
        extern CredGetSessionTypes alias _CredGetSessionTypes@8
        extern CredGetTargetInfoA alias _CredGetTargetInfoA@12
        extern CredGetTargetInfoW alias _CredGetTargetInfoW@12
        extern CredIsMarshaledCredentialA alias _CredIsMarshaledCredentialA@4
        extern CredIsMarshaledCredentialW alias _CredIsMarshaledCredentialW@4
        extern CredMarshalCredentialA alias _CredMarshalCredentialA@12
        extern CredMarshalCredentialW alias _CredMarshalCredentialW@12
        extern CredReadA alias _CredReadA@16
        extern CredReadW alias _CredReadW@16
        extern CredReadDomainCredentialsA alias _CredReadDomainCredentialsA@16
        extern CredReadDomainCredentialsW alias _CredReadDomainCredentialsW@16
        extern CredRenameA alias _CredRenameA@16
        extern CredRenameW alias _CredRenameW@16
        extern CredUnmarshalCredentialA alias _CredUnmarshalCredentialA@12
        extern CredUnmarshalCredentialW alias _CredUnmarshalCredentialW@12
        extern CredWriteA alias _CredWriteA@8
        extern CredWriteW alias _CredWriteW@8
        extern CredWriteDomainCredentialsA alias _CredWriteDomainCredentialsA@12
        extern CredWriteDomainCredentialsW alias _CredWriteDomainCredentialsW@12
        extern DecryptFileA alias _DecryptFileA@8
        extern DecryptFileW alias _DecryptFileW@8
        extern DuplicateEncryptionInfoFile alias _DuplicateEncryptionInfoFile@20
        extern EnumerateTraceGuids alias _EnumerateTraceGuids@12
        extern FlushTraceA alias _FlushTraceA@12
        extern FlushTraceW alias _FlushTraceW@12
        extern FreeInheritedFromArray alias _FreeInheritedFromArray@12
        extern GetInheritanceSourceA alias _GetInheritanceSourceA@40
        extern GetInheritanceSourceW alias _GetInheritanceSourceW@40
        extern GetLocalManagedApplicationData alias _GetLocalManagedApplicationData@12
        extern GetManagedApplicationCategories alias _GetManagedApplicationCategories@8
        extern GetSecurityDescriptorRMControl alias _GetSecurityDescriptorRMControl@8
        extern GetTraceEnableFlags alias _GetTraceEnableFlags@4
        extern GetTraceEnableLevel alias _GetTraceEnableLevel@4
        extern GetTraceLoggerHandle alias _GetTraceLoggerHandle@4
        extern GetTrusteeFormA alias _GetTrusteeFormA@4
        extern GetTrusteeFormW alias _GetTrusteeFormW@4
        extern GetWindowsAccountDomainSid alias _GetWindowsAccountDomainSid@12
        extern IsWellKnownSid alias _IsWellKnownSid@8
        extern LogonUserExA alias _LogonUserExA@40
        extern LogonUserExExW alias _LogonUserExExW@44
        extern LogonUserExW alias _LogonUserExW@40
        extern LsaLookupNames2 alias _LsaLookupNames2@24
        extern LsaQueryForestTrustInformation alias _LsaQueryForestTrustInformation@12
        extern LsaSetForestTrustInformation alias _LsaSetForestTrustInformation@20
        extern MSChapSrvChangePassword alias _MSChapSrvChangePassword@28
        extern MSChapSrvChangePassword2 alias _MSChapSrvChangePassword2@28
        extern ProcessTrace alias _ProcessTrace@16
        extern QueryTraceA alias _QueryTraceA@12
        extern QueryTraceW alias _QueryTraceW@12
        extern RegDisablePredefinedCacheEx alias _RegDisablePredefinedCacheEx@0
        extern RegSaveKeyExA alias _RegSaveKeyExA@16
        extern RegSaveKeyExW alias _RegSaveKeyExW@16
        extern SaferCloseLevel alias _SaferCloseLevel@4
        extern SaferComputeTokenFromLevel alias _SaferComputeTokenFromLevel@20
        extern SaferCreateLevel alias _SaferCreateLevel@16
        extern SaferGetLevelInformation alias _SaferGetLevelInformation@20
        extern SaferGetPolicyInformation alias _SaferGetPolicyInformation@24
        extern SaferIdentifyLevel alias _SaferIdentifyLevel@16
        extern SaferRecordEventLogEntry alias _SaferRecordEventLogEntry@12
        extern SaferSetLevelInformation alias _SaferSetLevelInformation@16
        extern SaferSetPolicyInformation alias _SaferSetPolicyInformation@20
        extern SaferiIsExecutableFileType alias _SaferiIsExecutableFileType@8
        extern SaferiSearchMatchingHashRules alias _SaferiSearchMatchingHashRules@24
        extern SetEncryptedFileMetadata alias _SetEncryptedFileMetadata@24
        extern StopTraceA alias _StopTraceA@12
        extern StopTraceW alias _StopTraceW@12
        extern TraceMessage alias _TraceMessage@16
        extern TraceMessageVa alias _TraceMessageVa@20
        extern TreeResetNamedSecurityInfoA alias _TreeResetNamedSecurityInfoA@44
        extern TreeResetNamedSecurityInfoW alias _TreeResetNamedSecurityInfoW@44
        extern UpdateTraceA alias _UpdateTraceA@12
        extern UpdateTraceW alias _UpdateTraceW@12
        extern WmiQueryAllDataMultipleA alias _WmiQueryAllDataMultipleA@16
        extern WmiQueryAllDataMultipleW alias _WmiQueryAllDataMultipleW@16
        extern WmiQuerySingleInstanceMultipleA alias _WmiQuerySingleInstanceMultipleA@20
        extern WmiQuerySingleInstanceMultipleW alias _WmiQuerySingleInstanceMultipleW@20
        extern WmiReceiveNotificationsA alias _WmiReceiveNotificationsA@16
        extern WmiReceiveNotificationsW alias _WmiReceiveNotificationsW@16
        #ifdef APP_UNICODE
            define ChangeServiceConfig2 ChangeServiceConfig2W
            define ConvertStringSDToSDDomain ConvertStringSDToSDDomainW
            define CredDelete CredDeleteW
            define CredEnumerate CredEnumerateW
            define CredGetTargetInfo CredGetTargetInfoW
            define CredIsMarshaledCredential CredIsMarshaledCredentialW
            define CredMarshalCredential CredMarshalCredentialW
            define CredReadDomainCredentials CredReadDomainCredentialsW
            define CredUnmarshalCredential CredUnmarshalCredentialW
            define CredWrite CredWriteW
            define CredWriteDomainCredentials CredWriteDomainCredentialsW
            define DecryptFile DecryptFileW
            define FlushTrace FlushTraceW
            define GetInheritanceSource GetInheritanceSourceW
            define GetTrusteeForm GetTrusteeFormW
            define LogonUserEx LogonUserExW
            define QueryTrace QueryTraceW
            define RegSaveKeyEx RegSaveKeyExW
            define StopTrace StopTraceW
            define TreeResetNamedSecurityInfo TreeResetNamedSecurityInfoW
            define UpdateTrace UpdateTraceW
            define WmiQueryAllDataMultiple WmiQueryAllDataMultipleW
            define WmiQuerySingleInstanceMultiple WmiQuerySingleInstanceMultipleW
            define WmiReceiveNotifications WmiReceiveNotificationsW
        #else
            define ChangeServiceConfig2 ChangeServiceConfig2A
            define ConvertStringSDToSDDomain ConvertStringSDToSDDomainA
            define CredDelete CredDeleteA
            define CredEnumerate CredEnumerateA
            define CredGetTargetInfo CredGetTargetInfoA
            define CredIsMarshaledCredential CredIsMarshaledCredentialA
            define CredMarshalCredential CredMarshalCredentialA
            define CredReadDomainCredentials CredReadDomainCredentialsA
            define CredUnmarshalCredential CredUnmarshalCredentialA
            define CredWrite CredWriteA
            define CredWriteDomainCredentials CredWriteDomainCredentialsA
            define DecryptFile DecryptFileA
            define FlushTrace FlushTraceA
            define GetInheritanceSource GetInheritanceSourceA
            define GetTrusteeForm GetTrusteeFormA
            define LogonUserEx LogonUserExA
            define QueryTrace QueryTraceA
            define RegSaveKeyEx RegSaveKeyExA
            define StopTrace StopTraceA
            define TreeResetNamedSecurityInfo TreeResetNamedSecurityInfoA
            define UpdateTrace UpdateTraceA
            define WmiQueryAllDataMultiple WmiQueryAllDataMultipleA
            define WmiQuerySingleInstanceMultiple WmiQuerySingleInstanceMultipleA
            define WmiReceiveNotifications WmiReceiveNotificationsA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WS03
        extern CreateProcessWithTokenW alias _CreateProcessWithTokenW@36
    #endif

    #if NTDDI_VERSION >= NTDDI_VISTA
        extern AddMandatoryAce alias _AddMandatoryAce@36
        extern AuditComputeEffectivePolicyBySid alias _AuditComputeEffectivePolicyBySid@16
        extern AuditComputeEffectivePolicyByToken alias _AuditComputeEffectivePolicyByToken@16
        extern AuditEnumerateCategories alias _AuditEnumerateCategories@8
        extern AuditEnumeratePerUserPolicy alias _AuditEnumeratePerUserPolicy@4
        extern AuditEnumerateSubCategories alias _AuditEnumerateSubCategories@16
        extern AuditFree alias _AuditFree@4
        extern AuditLookupCategoryGuidFromCategoryId alias _AuditLookupCategoryGuidFromCategoryId@8
        extern AuditLookupCategoryIdFromCategoryGuid alias _AuditLookupCategoryIdFromCategoryGuid@8
        extern AuditLookupCategoryNameA alias _AuditLookupCategoryNameA@8
        extern AuditLookupCategoryNameW alias _AuditLookupCategoryNameW@8
        extern AuditLookupSubCategoryNameA alias _AuditLookupSubCategoryNameA@8
        extern AuditLookupSubCategoryNameW alias _AuditLookupSubCategoryNameW@8
        extern AuditQueryPerUserPolicy alias _AuditQueryPerUserPolicy@16
        extern AuditQuerySecurity alias _AuditQuerySecurity@8
        extern AuditQuerySystemPolicy alias _AuditQuerySystemPolicy@12
        extern AuditSetPerUserPolicy alias _AuditSetPerUserPolicy@12
        extern AuditSetSecurity alias _AuditSetSecurity@8
        extern AuditSetSystemPolicy alias _AuditSetSystemPolicy@8
        extern CloseThreadWaitChainSession alias _CloseThreadWaitChainSession@4
        extern ControlServiceExA alias _ControlServiceExA@16
        extern ControlServiceExW alias _ControlServiceExW@16
        extern CredFindBestCredentialA alias _CredFindBestCredentialA@16
        extern CredFindBestCredentialW alias _CredFindBestCredentialW@16
        extern CredIsProtectedA alias _CredIsProtectedA@8
        extern CredIsProtectedW alias _CredIsProtectedW@8
        extern CredProtectA alias _CredProtectA@24
        extern CredProtectW alias _CredProtectW@24
        extern CredUnprotectA alias _CredUnprotectA@20
        extern CredUnprotectW alias _CredUnprotectW@20
        extern EnumerateTraceGuidsEx alias _EnumerateTraceGuidsEx@24
        extern EventAccessControl alias _EventAccessControl@20
        extern EventAccessQuery alias _EventAccessQuery@12
        extern EventAccessRemove alias _EventAccessRemove@4
        extern EventActivityIdControl alias _EventActivityIdControl@8
        extern EventEnabled alias _EventEnabled@8
        extern EventProviderEnabled alias _EventProviderEnabled@12
        extern EventRegister alias _EventRegister@16
        extern EventUnregister alias _EventUnregister@4
        extern EventWrite alias _EventWrite@16
        extern EventWriteString alias _EventWriteString@16
        extern EventWriteTransfer alias _EventWriteTransfer@24
        extern FlushEfsCache alias _FlushEfsCache@4
        extern FreeEncryptedFileMetadata alias _FreeEncryptedFileMetadata@4
        extern GetEncryptedFileMetadata alias _GetEncryptedFileMetadata@12
        extern GetThreadWaitChain alias _GetThreadWaitChain@28
        extern I_QueryTagInformation alias _I_QueryTagInformation@12
        extern InitiateShutdownA alias _InitiateShutdownA@20
        extern InitiateShutdownW alias _InitiateShutdownW@20
        extern LsaManageSidNameMapping alias _LsaManageSidNameMapping@12
        extern NotifyServiceStatusChangeA alias _NotifyServiceStatusChangeA@12
        extern NotifyServiceStatusChangeW alias _NotifyServiceStatusChangeW@12
        extern OpenThreadWaitChainSession alias _OpenThreadWaitChainSession@8
        extern PerfCreateInstance alias _PerfCreateInstance@16
        extern PerfDecrementULongCounterValue alias _PerfDecrementULongCounterValue@16
        extern PerfDecrementULongLongCounterValue alias _PerfDecrementULongLongCounterValue@16
        extern PerfDeleteInstance alias _PerfDeleteInstance@8
        extern PerfIncrementULongCounterValue alias _PerfIncrementULongCounterValue@16
        extern PerfIncrementULongLongCounterValue alias _PerfIncrementULongLongCounterValue@16
        extern PerfQueryInstance alias _PerfQueryInstance@16
        extern PerfSetCounterRefValue alias _PerfSetCounterRefValue@16
        extern PerfSetCounterSetInfo alias _PerfSetCounterSetInfo@12
        extern PerfSetULongCounterValue alias _PerfSetULongCounterValue@16
        extern PerfSetULongLongCounterValue alias _PerfSetULongLongCounterValue@16
        extern PerfStartProvider alias _PerfStartProvider@12
        extern PerfStartProviderEx alias _PerfStartProviderEx@12
        extern PerfStopProvider alias _PerfStopProvider@4
        extern QuerySecurityAccessMask alias _QuerySecurityAccessMask@8
        extern RegConnectRegistryExA alias _RegConnectRegistryExA@20
        extern RegConnectRegistryExW alias _RegConnectRegistryExW@20
        extern RegCopyTreeA alias _RegCopyTreeA@12
        extern RegCopyTreeW alias _RegCopyTreeW@12
        extern RegCreateKeyTransactedA alias _RegCreateKeyTransactedA@44
        extern RegCreateKeyTransactedW alias _RegCreateKeyTransactedW@44
        extern RegDeleteKeyExA alias _RegDeleteKeyExA@16
        extern RegDeleteKeyExW alias _RegDeleteKeyExW@16
        extern RegDeleteKeyTransactedA alias _RegDeleteKeyTransactedA@24
        extern RegDeleteKeyTransactedW alias _RegDeleteKeyTransactedW@24
        extern RegDeleteKeyValueA alias _RegDeleteKeyValueA@12
        extern RegDeleteKeyValueW alias _RegDeleteKeyValueW@12
        extern RegDeleteTreeA alias _RegDeleteTreeA@8
        extern RegDeleteTreeW alias _RegDeleteTreeW@8
        extern RegDisableReflectionKey alias _RegDisableReflectionKey@4
        extern RegEnableReflectionKey alias _RegEnableReflectionKey@4
        extern RegGetValueA alias _RegGetValueA@28
        extern RegGetValueW alias _RegGetValueW@28
        extern RegLoadAppKeyA alias _RegLoadAppKeyA@20
        extern RegLoadAppKeyW alias _RegLoadAppKeyW@20
        extern RegLoadMUIStringA alias _RegLoadMUIStringA@28
        extern RegLoadMUIStringW alias _RegLoadMUIStringW@28
        extern RegOpenKeyTransactedA alias _RegOpenKeyTransactedA@28
        extern RegOpenKeyTransactedW alias _RegOpenKeyTransactedW@28
        extern RegQueryReflectionKey alias _RegQueryReflectionKey@8
        extern RegSetKeyValueA alias _RegSetKeyValueA@24
        extern RegSetKeyValueW alias _RegSetKeyValueW@24
        extern RegisterWaitChainCOMCallback alias _RegisterWaitChainCOMCallback@8
        extern SetSecurityAccessMask alias _SetSecurityAccessMask@8
        extern SetUserFileEncryptionKeyEx alias _SetUserFileEncryptionKeyEx@16
        extern TreeSetNamedSecurityInfoA alias _TreeSetNamedSecurityInfoA@44
        extern TreeSetNamedSecurityInfoW alias _TreeSetNamedSecurityInfoW@44
        #ifdef APP_UNICODE
            define AuditLookupCategoryName AuditLookupCategoryNameW
            define AuditLookupSubCategoryName AuditLookupSubCategoryNameW
            define ControlServiceEx ControlServiceExW
            define CredFindBestCredential CredFindBestCredentialW
            define CredIsProtected CredIsProtectedW
            define CredProtect CredProtectW
            define CredUnprotect CredUnprotectW
            define InitiateShutdown InitiateShutdownW
            define NotifyServiceStatusChange NotifyServiceStatusChangeW
            define RegConnectRegistryEx RegConnectRegistryExW
            define RegCopyTree RegCopyTreeW
            define RegCreateKeyTransacted RegCreateKeyTransactedW
            define RegDeleteKeyEx RegDeleteKeyExW
            define RegDeleteKeyTransacted RegDeleteKeyTransactedW
            define RegDeleteKeyValue RegDeleteKeyValueW
            define RegDeleteTree RegDeleteTreeW
            define RegGetValue RegGetValueW
            define RegLoadAppKey RegLoadAppKeyW
            define RegLoadMUIString RegLoadMUIStringW
            define RegOpenKeyTransacted RegOpenKeyTransactedW
            define RegSetKeyValue RegSetKeyValueW
            define TreeSetNamedSecurityInfo TreeSetNamedSecurityInfoW
        #else
            define AuditLookupCategoryName AuditLookupCategoryNameA
            define AuditLookupSubCategoryName AuditLookupSubCategoryNameA
            define ControlServiceEx ControlServiceExA
            define CredFindBestCredential CredFindBestCredentialA
            define CredIsProtected CredIsProtectedA
            define CredProtect CredProtectA
            define CredUnprotect CredUnprotectW
            define InitiateShutdown InitiateShutdownA
            define NotifyServiceStatusChange NotifyServiceStatusChangeA
            define RegConnectRegistryEx RegConnectRegistryExA
            define RegCopyTree RegCopyTreeA
            define RegCreateKeyTransacted RegCreateKeyTransactedA
            define RegDeleteKeyEx RegDeleteKeyExA
            define RegDeleteKeyTransacted RegDeleteKeyTransactedA
            define RegDeleteKeyValue RegDeleteKeyValueA
            define RegDeleteTree RegDeleteTreeA
            define RegGetValue RegGetValueA
            define RegLoadAppKey RegLoadAppKeyA
            define RegLoadMUIString RegLoadMUIStringA
            define RegOpenKeyTransacted RegOpenKeyTransactedA
            define RegSetKeyValue RegSetKeyValueA
            define TreeSetNamedSecurityInfo TreeSetNamedSecurityInfoA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WIN7
        extern AddConditionalAce alias _AddConditionalAce@32
        extern AuditQueryGlobalSaclA alias _AuditQueryGlobalSaclA@8
        extern AuditQueryGlobalSaclW alias _AuditQueryGlobalSaclW@8
        extern AuditSetGlobalSaclA alias _AuditSetGlobalSaclA@8
        extern AuditSetGlobalSaclW alias _AuditSetGlobalSaclW@8
        extern CredReadByTokenHandle alias _CredReadByTokenHandle@4
        extern EnableTraceEx alias _EnableTraceEx@36
        extern EnableTraceEx2 alias _EnableTraceEx2@32
        extern EventWriteEx alias _EventWriteEx@32
        extern TraceSetInformation alias _TraceSetInformation@16
        #ifdef APP_UNICODE
            define AuditQueryGlobalSacl AuditQueryGlobalSaclW
            define AuditSetGlobalSacl AuditSetGlobalSaclW
        #else
            define AuditQueryGlobalSacl AuditQueryGlobalSaclA
            define AuditSetGlobalSacl AuditSetGlobalSaclA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WIN8
        extern BaseRegCloseKey alias _BaseRegCloseKey@4
        extern BaseRegCreateKey alias _BaseRegCreateKey@32
        extern BaseRegDeleteKeyEx alias _BaseRegDeleteKeyEx@16
        extern BaseRegDeleteValue alias _BaseRegDeleteValue@8
        extern BaseRegFlushKey alias _BaseRegFlushKey@4
        extern BaseRegGetVersion alias _BaseRegGetVersion@8
        extern BaseRegLoadKey alias _BaseRegLoadKey@12
        extern BaseRegOpenKey alias _BaseRegOpenKey@20
        extern BaseRegRestoreKey alias _BaseRegRestoreKey@12
        extern BaseRegSaveKeyEx alias _BaseRegSaveKeyEx@16
        extern BaseRegSetKeySecurity alias _BaseRegSetKeySecurity@12
        extern BaseRegSetValue alias _BaseRegSetValue@20
        extern BaseRegUnLoadKey alias _BaseRegUnLoadKey@8
        extern EnumDynamicTimeZoneInformation alias _EnumDynamicTimeZoneInformation@8
        extern EventSetInformation alias _EventSetInformation@16
        extern GetDynamicTimeZoneInformationEffectiveYears alias _GetDynamicTimeZoneInformationEffectiveYears@12
        extern LsaGetAppliedCAPIDs alias _LsaGetAppliedCAPIDs@12
        extern LsaLookupSids2 alias _LsaLookupSids2@24
        extern LsaQueryCAPs alias _LsaQueryCAPs@16
        extern LsaSetCAPs alias _LsaSetCAPs@12
        extern OperationEnd alias _OperationEnd@4
        extern OperationStart alias _OperationStart@4
        extern QueryServiceDynamicInformation alias _QueryServiceDynamicInformation@12
        extern TraceQueryInformation alias _TraceQueryInformation@20
    #endif
#endif

#ifdef APP_UNICODE
    define ACCCTRL_DEFAULT_PROVIDER ACCCTRL_DEFAULT_PROVIDERW
    define SERVICES_ACTIVE_DATABASE SERVICES_ACTIVE_DATABASEW
    define SERVICES_FAILED_DATABASE SERVICES_FAILED_DATABASEW
    define SC_GROUP_IDENTIFIER SC_GROUP_IDENTIFIERW
    define AbortSystemShutdown AbortSystemShutdownW
    define AccessCheckAndAuditAlarm AccessCheckAndAuditAlarmW
    define BackupEventLog BackupEventLogW
    define ChangeServiceConfig ChangeServiceConfigW
    define ClearEventLog ClearEventLogW
    define CreateService CreateServiceW
    define CryptAcquireContext CryptAcquireContextW
    define CryptSetProvider CryptSetProviderW
    define CryptSetProviderEx CryptSetProviderExW
    define CryptSignHash CryptSignHashW
    define CryptVerifySignature CryptVerifySignatureW
    define EnumDependentServices EnumDependentServicesW
    define EnumServicesStatus EnumServicesStatusW
    define GetFileSecurity GetFileSecurityW
    define GetServiceDisplayName GetServiceDisplayNameW
    define GetServiceKeyName GetServiceKeyNameW
    define GetUserName GetUserNameW
    define InitiateSystemShutdown InitiateSystemShutdownW
    define LogonUser LogonUserW
    define LookupAccountName LookupAccountNameW
    define LookupAccountSid LookupAccountSidW
    define LookupPrivilegeDisplayName LookupPrivilegeDisplayNameW
    define LookupPrivilegeName LookupPrivilegeNameW
    define LookupPrivilegeValue LookupPrivilegeValueW
    define ObjectCloseAuditAlarm ObjectCloseAuditAlarmW
    define ObjectOpenAuditAlarm ObjectOpenAuditAlarmW
    define ObjectPrivilegeAuditAlarm ObjectPrivilegeAuditAlarmW
    define OpenBackupEventLog OpenBackupEventLogW
    define OpenEventLog OpenEventLogW
    define OpenSCManager OpenSCManagerA
    define OpenService OpenServiceA
    define PrivilegedServiceAuditAlarm PrivilegedServiceAuditAlarmW
    define QueryServiceConfig QueryServiceConfigW
    define QueryServiceLockStatus QueryServiceLockStatusW
    define ReadEventLog ReadEventLogW
    define RegConnectRegistry RegConnectRegistryW
    define RegCreateKey RegCreateKeyW
    define RegCreateKeyEx RegCreateKeyExW
    define RegDeleteKey RegDeleteKeyW
    define RegDeleteValue RegDeleteValueW
    define RegEnumKey RegEnumKeyW
    define RegEnumKeyEx RegEnumKeyExW
    define RegEnumValue RegEnumValueW
    define RegLoadKey RegLoadKeyW
    define RegOpenKey RegOpenKeyW
    define RegOpenKeyEx RegOpenKeyExW
    define RegQueryInfoKey RegQueryInfoKeyW
    define RegQueryMultipleValues RegQueryMultipleValuesW
    define RegQueryValue RegQueryValueW
    define RegQueryValueEx RegQueryValueExW
    define RegReplaceKey RegReplaceKeyW
    define RegRestoreKey RegRestoreKeyW
    define RegSaveKey RegSaveKeyW
    define RegSetValue RegSetValueW
    define RegSetValueEx RegSetValueExW
    define RegUnLoadKey RegUnLoadKeyW
    define RegisterEventSource RegisterEventSourceW
    define RegisterServiceCtrlHandler RegisterServiceCtrlHandlerW
    define ReportEvent ReportEventW
    define SetFileSecurity SetFileSecurityW
    define StartService StartServiceW
    define StartServiceCtrlDispatcher StartServiceCtrlDispatcherW
#else
    define ACCCTRL_DEFAULT_PROVIDER ACCCTRL_DEFAULT_PROVIDERA
    define SERVICES_ACTIVE_DATABASE SERVICES_ACTIVE_DATABASEA
    define SERVICES_FAILED_DATABASE SERVICES_FAILED_DATABASEA
    define SC_GROUP_IDENTIFIER SC_GROUP_IDENTIFIERA
    define AbortSystemShutdown AbortSystemShutdownA
    define AccessCheckAndAuditAlarm AccessCheckAndAuditAlarmA
    define BackupEventLog BackupEventLogA
    define ChangeServiceConfig ChangeServiceConfigA
    define ClearEventLog ClearEventLogA
    define CreateService CreateServiceA
    define CryptAcquireContext CryptAcquireContextA
    define CryptSetProvider CryptSetProviderA
    define CryptSetProviderEx CryptSetProviderExA
    define CryptSignHash CryptSignHashA
    define CryptVerifySignature CryptVerifySignatureA
    define EnumDependentServices EnumDependentServicesA
    define EnumServicesStatus EnumServicesStatusA
    define GetFileSecurity GetFileSecurityA
    define GetServiceDisplayName GetServiceDisplayNameA
    define GetServiceKeyName GetServiceKeyNameA
    define GetUserName GetUserNameA
    define InitiateSystemShutdown InitiateSystemShutdownA
    define LogonUser LogonUserA
    define LookupAccountName LookupAccountNameA
    define LookupAccountSid LookupAccountSidA
    define LookupPrivilegeDisplayName LookupPrivilegeDisplayNameA
    define LookupPrivilegeName LookupPrivilegeNameA
    define LookupPrivilegeValue LookupPrivilegeValueA
    define ObjectCloseAuditAlarm ObjectCloseAuditAlarmA
    define ObjectOpenAuditAlarm ObjectOpenAuditAlarmA
    define ObjectPrivilegeAuditAlarm ObjectPrivilegeAuditAlarmA
    define OpenBackupEventLog OpenBackupEventLogA
    define OpenEventLog OpenEventLogA
    define OpenSCManager OpenSCManagerA
    define OpenService OpenServiceA
    define PrivilegedServiceAuditAlarm PrivilegedServiceAuditAlarmA
    define QueryServiceConfig QueryServiceConfigA
    define QueryServiceLockStatus QueryServiceLockStatusA
    define ReadEventLog ReadEventLogA
    define RegConnectRegistry RegConnectRegistryA
    define RegCreateKey RegCreateKeyA
    define RegCreateKeyEx RegCreateKeyExA
    define RegDeleteKey RegDeleteKeyA
    define RegDeleteValue RegDeleteValueA
    define RegEnumKey RegEnumKeyA
    define RegEnumKeyEx RegEnumKeyExA
    define RegEnumValue RegEnumValueA
    define RegLoadKey RegLoadKeyA
    define RegOpenKey RegOpenKeyA
    define RegOpenKeyEx RegOpenKeyExA
    define RegQueryInfoKey RegQueryInfoKeyA
    define RegQueryMultipleValues RegQueryMultipleValuesA
    define RegQueryValue RegQueryValueA
    define RegQueryValueEx RegQueryValueExA
    define RegReplaceKey RegReplaceKeyA
    define RegRestoreKey RegRestoreKeyA
    define RegSaveKey RegSaveKeyA
    define RegSetValue RegSetValueA
    define RegSetValueEx RegSetValueExA
    define RegUnLoadKey RegUnLoadKeyA
    define RegisterEventSource RegisterEventSourceA
    define RegisterServiceCtrlHandler RegisterServiceCtrlHandlerA
    define ReportEvent ReportEventA
    define SetFileSecurity SetFileSecurityA
    define StartService StartServiceA
    define StartServiceCtrlDispatcher StartServiceCtrlDispatcherA
#endif

;======================= Undocumented functions (unknown arguments) =======================;
;import AddUsersToEncryptedFileEx
;import CancelOverlappedAccess
;import CheckAppInitBlockedServiceIdentity
;import CheckForHiberboot
;import CloseCodeAuthzLevel
;import ComputeAccessTokenFromCodeAuthzLevel
;import ConvertSDToStringSDDomainW
;import CreateCodeAuthzLevel
;import CredBackupCredentials
;import CredEncryptAndMarshalBinaryBlob
;import CredpConvertCredential
;import CredpConvertOneCredentialSize
;import CredpConvertTargetInfo
;import CredpDecodeCredential
;import CredpEncodeCredential
;import CredpEncodeSecret
;import CredProfileLoaded
;import CredProfileLoadedEx
;import CredProfileUnloaded
;import CredRestoreCredentials
;import ElfFlushEventLog
;import ElfReportEventAndSourceW
;import EncryptedFileKeyInfo
;import EtwLogSysConfigExtension
;import EventWriteEndScenario
;import EventWriteStartScenario
;import FreeEncryptedFileKeyInfo
;import GetInformationCodeAuthzLevelW
;import GetInformationCodeAuthzPolicyW
;import GetStringConditionFromBinary
;import I_ScGetCurrentGroupStateW
;import I_ScIsSecurityProcess
;import I_ScPnPGetServiceName
;import I_ScQueryServiceConfig
;import I_ScRegisterPreshutdownRestart
;import I_ScSendPnPMessage
;import I_ScSendTSMessage
;import I_ScSetServiceBitsA
;import I_ScSetServiceBitsW
;import I_ScValidatePnPService
;import IdentifyCodeAuthzLevelW
;import IsTokenUntrusted
;import IsValidRelativeSecurityDescriptor
;import LsaICLookupNames
;import LsaICLookupNamesWithCreds
;import LsaICLookupSids
;import LsaICLookupSidsWithCreds
;import MD4Final
;import MD4Init
;import MD4Update
;import MD5Final
;import MD5Init
;import MD5Update
;import MIDL_user_free_Ext
;import PerfAddCounters
;import PerfCloseQueryHandle
;import PerfDeleteCounters
;import PerfEnumerateCounterSet
;import PerfEnumerateCounterSetInstances
;import PerfOpenQueryHandle
;import PerfQueryCounterData
;import PerfQueryCounterInfo
;import PerfQueryCounterSetRegistrationInfo
;import PerfRegCloseKey
;import PerfRegEnumKey
;import PerfRegEnumValue
;import PerfRegQueryInfoKey
;import PerfRegQueryValue
;import PerfRegSetValue
;import ProcessIdleTasks
;import ProcessIdleTasksW
;import PsmActivateApplication
;import PsmAdjustActivationToken
;import PsmQueryBackgroundActivationType
;import PsmRegisterApplicationProcess
;import RegisterIdleTask
;import RegRemapPreDefKey
;import RegRenameKey
;import RemoteRegEnumKeyWrapper
;import RemoteRegEnumValueWrapper
;import RemoteRegQueryInfoKeyWrapper
;import RemoteRegQueryValueWrapper
;import SafeBaseRegGetKeySecurity
;import SaferiChangeRegistryScope
;import SaferiCompareTokenLevels
;import SaferiIsDllAllowed
;import SaferiPopulateDefaultsInRegistry
;import SaferiRecordEventLogEntry
;import SaferiReplaceProcessThreadTokens
;import SetInformationCodeAuthzLevelW
;import SetInformationCodeAuthzPolicyW
;import SystemFunction001
;import SystemFunction002
;import SystemFunction003
;import SystemFunction004
;import SystemFunction005
;import SystemFunction006
;import SystemFunction007
;import SystemFunction008
;import SystemFunction009
;import SystemFunction010
;import SystemFunction011
;import SystemFunction012
;import SystemFunction013
;import SystemFunction014
;import SystemFunction015
;import SystemFunction016
;import SystemFunction017
;import SystemFunction018
;import SystemFunction019
;import SystemFunction020
;import SystemFunction021
;import SystemFunction022
;import SystemFunction023
;import SystemFunction024
;import SystemFunction025
;import SystemFunction026
;import SystemFunction027
;import SystemFunction028
;import SystemFunction029
;import SystemFunction030
;import SystemFunction031
;import SystemFunction032
;import SystemFunction033
;import SystemFunction034
;import SystemFunction035
;import SystemFunction036
;import SystemFunction040
;import SystemFunction041
;import UnregisterIdleTask
;import UsePinForEncryptedFilesA
;import UsePinForEncryptedFilesW
;import WaitServiceState
;import WdmWmiServiceMain
;import WmiCloseTraceWithCursor
;import WmiConvertTimestamp
;import WmiGetFirstTraceOffset
;import WmiGetNextEvent
;import WmiGetTraceHeader
;import WmiOpenTraceWithCursor
;import WmiParseTraceEvent
;import Wow64Win32ApiEntry

;#ifdef APP_UNICODE
;    define I_ScSetServiceBits I_ScSetServiceBitsW
;    define SetInformationCodeAuthzLevel SetInformationCodeAuthzLevelW
;    define UsePinForEncryptedFiles UsePinForEncryptedFilesW
;#else
;    define I_ScSetServiceBits I_ScSetServiceBitsA
;    define SetInformationCodeAuthzLevel SetInformationCodeAuthzLevelA
;    define UsePinForEncryptedFiles UsePinForEncryptedFilesA
;#endif

#endif ;ADVAPI32_INC
