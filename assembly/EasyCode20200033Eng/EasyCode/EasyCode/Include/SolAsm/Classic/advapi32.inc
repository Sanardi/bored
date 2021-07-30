; ====================================================;
;                                                     ;
;   advapi32.inc for EC v2 SolAsm classic projects    ;
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
