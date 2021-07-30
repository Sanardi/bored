;===========================================================;
;                                                           ;
;      ntifs.h for Easy Code 2.0 GoAsm 32-bit drivers       ;
;                     (version 1.0.0)                       ;
;                                                           ;
;             Driver Development Kit (32-bit)               ;
;                                                           ;
;              Copyright © Ramon Sala - 2015                ;
;                                                           ;
;===========================================================;

#IFNDEF NTIFS_H
#Define NTIFS_H 1

NTIFS_INCLUDED                                              Equ         1

#Include ntddk.h
#Include excpt.h
#Include ntnls.h

#IFNDEF SID_IDENTIFIER_AUTHORITY
    SID_IDENTIFIER_AUTHORITY Struct
        Value                                               DB          6 Dup ?
    EndS
#ENDIF

#IFNDEF SID
    SID Struct
        Revision                                            DB
        SubAuthorityCount                                   DB
        IdentifierAuthority                                 SID_IDENTIFIER_AUTHORITY
        SubAuthority                                        DD      ANYSIZE_ARRAY Dup ?
    EndS
#ENDIF

SID_REVISION                                                Equ         (1)
SID_MAX_SUB_AUTHORITIES                                     Equ         (15)
SID_RECOMMENDED_SUB_AUTHORITIES                             Equ         (1)

;SID_NAME_USE Enumeration
SidTypeUser                                                 Equ         1
SidTypeGroup                                                Equ         2
SidTypeDomain                                               Equ         3
SidTypeAlias                                                Equ         4
SidTypeWellKnownGroup                                       Equ         5
SidTypeDeletedAccount                                       Equ         6
SidTypeInvalid                                              Equ         7
SidTypeUnknown                                              Equ         8
SidTypeComputer                                             Equ         9
SidTypeLabel                                                Equ         10

SID_AND_ATTRIBUTES Struct
    Sid                                                     SID
    Attributes                                              DD
EndS

SID_HASH_SIZE                                               Equ         32

SID_AND_ATTRIBUTES_HASH Struct
    SidCount                                                DD
    SidAttr                                                 DD
    Hash                                                    DD          SID_HASH_SIZE Dup ?
EndS

SECURITY_NULL_RID                                           Equ         (00000000H)
SECURITY_WORLD_RID                                          Equ         (00000000H)
SECURITY_LOCAL_RID                                          Equ         (00000000H)
SECURITY_LOCAL_LOGON_RID                                    Equ         (00000001H)

SECURITY_CREATOR_OWNER_RID                                  Equ         (00000000H)
SECURITY_CREATOR_GROUP_RID                                  Equ         (00000001H)

SECURITY_CREATOR_OWNER_SERVER_RID                           Equ         (00000002H)
SECURITY_CREATOR_GROUP_SERVER_RID                           Equ         (00000003H)

SECURITY_CREATOR_OWNER_RIGHTS_RID                           Equ         (00000004H)

SECURITY_DIALUP_RID                                         Equ         (00000001H)
SECURITY_NETWORK_RID                                        Equ         (00000002H)
SECURITY_BATCH_RID                                          Equ         (00000003H)
SECURITY_INTERACTIVE_RID                                    Equ         (00000004H)
SECURITY_LOGON_IDS_RID                                      Equ         (00000005H)
SECURITY_LOGON_IDS_RID_COUNT                                Equ         (03H)
SECURITY_SERVICE_RID                                        Equ         (00000006H)
SECURITY_ANONYMOUS_LOGON_RID                                Equ         (00000007H)
SECURITY_PROXY_RID                                          Equ         (00000008H)
SECURITY_ENTERPRISE_CONTROLLERS_RID                         Equ         (00000009H)
SECURITY_SERVER_LOGON_RID                                   Equ         SECURITY_ENTERPRISE_CONTROLLERS_RID
SECURITY_PRINCIPAL_SELF_RID                                 Equ         (0000000AH)
SECURITY_AUTHENTICATED_USER_RID                             Equ         (0000000BH)
SECURITY_RESTRICTED_CODE_RID                                Equ         (0000000CH)
SECURITY_TERMINAL_SERVER_RID                                Equ         (0000000DH)
SECURITY_REMOTE_LOGON_RID                                   Equ         (0000000EH)
SECURITY_THIS_ORGANIZATION_RID                              Equ         (0000000FH)
SECURITY_IUSER_RID                                          Equ         (00000011H)
SECURITY_LOCAL_SYSTEM_RID                                   Equ         (00000012H)
SECURITY_LOCAL_SERVICE_RID                                  Equ         (00000013H)
SECURITY_NETWORK_SERVICE_RID                                Equ         (00000014H)

SECURITY_NT_NON_UNIQUE                                      Equ         (00000015H)
SECURITY_NT_NON_UNIQUE_SUB_AUTH_COUNT                       Equ         (3H)

SECURITY_ENTERPRISE_READONLY_CONTROLLERS_RID                Equ         (00000016H)

SECURITY_BUILTIN_DOMAIN_RID                                 Equ         (00000020H)
SECURITY_WRITE_RESTRICTED_CODE_RID                          Equ         (00000021H)


SECURITY_PACKAGE_BASE_RID                                   Equ         (00000040H)
SECURITY_PACKAGE_RID_COUNT                                  Equ         (2H)
SECURITY_PACKAGE_NTLM_RID                                   Equ         (0000000AH)
SECURITY_PACKAGE_SCHANNEL_RID                               Equ         (0000000EH)
SECURITY_PACKAGE_DIGEST_RID                                 Equ         (00000015H)

SECURITY_CRED_TYPE_BASE_RID                                 Equ         (00000041H)
SECURITY_CRED_TYPE_RID_COUNT                                Equ         (2H)
SECURITY_CRED_TYPE_THIS_ORG_CERT_RID                        Equ         (00000001H)

SECURITY_MIN_BASE_RID                                       Equ         (00000050H)

SECURITY_SERVICE_ID_BASE_RID                                Equ         (00000050H)
SECURITY_SERVICE_ID_RID_COUNT                               Equ         (6H)

SECURITY_RESERVED_ID_BASE_RID                               Equ         (00000051H)

SECURITY_APPPOOL_ID_BASE_RID                                Equ         (00000052H)
SECURITY_APPPOOL_ID_RID_COUNT                               Equ         (6H)

SECURITY_VIRTUALSERVER_ID_BASE_RID                          Equ         (00000053H)
SECURITY_VIRTUALSERVER_ID_RID_COUNT                         Equ         (6H)

SECURITY_USERMODEDRIVERHOST_ID_BASE_RID                     Equ         (00000054H)
SECURITY_USERMODEDRIVERHOST_ID_RID_COUNT                    Equ         (6H)

SECURITY_CLOUD_INFRASTRUCTURE_SERVICES_ID_BASE_RID          Equ         (00000055H)
SECURITY_CLOUD_INFRASTRUCTURE_SERVICES_ID_RID_COUNT         Equ         (6H)

SECURITY_WMIHOST_ID_BASE_RID                                Equ         (00000056H)
SECURITY_WMIHOST_ID_RID_COUNT                               Equ         (6H)

SECURITY_TASK_ID_BASE_RID                                   Equ         (00000057H)

SECURITY_NFS_ID_BASE_RID                                    Equ         (00000058H)

SECURITY_COM_ID_BASE_RID                                    Equ         (00000059H)

SECURITY_VIRTUALACCOUNT_ID_RID_COUNT                        Equ         (6H)

SECURITY_MAX_BASE_RID                                       Equ         (0000006FH)
SECURITY_MAX_ALWAYS_FILTERED                                Equ         (000003E7H)
SECURITY_MIN_NEVER_FILTERED                                 Equ         (000003E8H)

SECURITY_OTHER_ORGANIZATION_RID                             Equ         (000003E8H)

SECURITY_WINDOWSMOBILE_ID_BASE_RID                          Equ         (00000070H)

DOMAIN_GROUP_RID_ENTERPRISE_READONLY_DOMAIN_CONTROLLERS     Equ         (000001F2H)

FOREST_USER_RID_MAX                                         Equ         (000001F3H)

DOMAIN_USER_RID_ADMIN                                       Equ         (000001F4H)
DOMAIN_USER_RID_GUEST                                       Equ         (000001F5H)
DOMAIN_USER_RID_KRBTGT                                      Equ         (000001F6H)

DOMAIN_USER_RID_MAX                                         Equ         (000003E7H)

DOMAIN_GROUP_RID_ADMINS                                     Equ         (00000200H)
DOMAIN_GROUP_RID_USERS                                      Equ         (00000201H)
DOMAIN_GROUP_RID_GUESTS                                     Equ         (00000202H)
DOMAIN_GROUP_RID_COMPUTERS                                  Equ         (00000203H)
DOMAIN_GROUP_RID_CONTROLLERS                                Equ         (00000204H)
DOMAIN_GROUP_RID_CERT_ADMINS                                Equ         (00000205H)
DOMAIN_GROUP_RID_SCHEMA_ADMINS                              Equ         (00000206H)
DOMAIN_GROUP_RID_ENTERPRISE_ADMINS                          Equ         (00000207H)
DOMAIN_GROUP_RID_POLICY_ADMINS                              Equ         (00000208H)
DOMAIN_GROUP_RID_READONLY_CONTROLLERS                       Equ         (00000209H)

DOMAIN_ALIAS_RID_ADMINS                                     Equ         (00000220H)
DOMAIN_ALIAS_RID_USERS                                      Equ         (00000221H)
DOMAIN_ALIAS_RID_GUESTS                                     Equ         (00000222H)
DOMAIN_ALIAS_RID_POWER_USERS                                Equ         (00000223H)

DOMAIN_ALIAS_RID_ACCOUNT_OPS                                Equ         (00000224H)
DOMAIN_ALIAS_RID_SYSTEM_OPS                                 Equ         (00000225H)
DOMAIN_ALIAS_RID_PRINT_OPS                                  Equ         (00000226H)
DOMAIN_ALIAS_RID_BACKUP_OPS                                 Equ         (00000227H)

DOMAIN_ALIAS_RID_REPLICATOR                                 Equ         (00000228H)
DOMAIN_ALIAS_RID_RAS_SERVERS                                Equ         (00000229H)
DOMAIN_ALIAS_RID_PREW2KCOMPACCESS                           Equ         (0000022AH)
DOMAIN_ALIAS_RID_REMOTE_DESKTOP_USERS                       Equ         (0000022BH)
DOMAIN_ALIAS_RID_NETWORK_CONFIGURATION_OPS                  Equ         (0000022CH)
DOMAIN_ALIAS_RID_INCOMING_FOREST_TRUST_BUILDERS             Equ         (0000022DH)

DOMAIN_ALIAS_RID_MONITORING_USERS                           Equ         (0000022EH)
DOMAIN_ALIAS_RID_LOGGING_USERS                              Equ         (0000022FH)
DOMAIN_ALIAS_RID_AUTHORIZATIONACCESS                        Equ         (00000230H)
DOMAIN_ALIAS_RID_TS_LICENSE_SERVERS                         Equ         (00000231H)
DOMAIN_ALIAS_RID_DCOM_USERS                                 Equ         (00000232H)
DOMAIN_ALIAS_RID_IUSERS                                     Equ         (00000238H)
DOMAIN_ALIAS_RID_CRYPTO_OPERATORS                           Equ         (00000239H)
DOMAIN_ALIAS_RID_CACHEABLE_PRINCIPALS_GROUP                 Equ         (0000023BH)
DOMAIN_ALIAS_RID_NON_CACHEABLE_PRINCIPALS_GROUP             Equ         (0000023CH)
DOMAIN_ALIAS_RID_EVENT_LOG_READERS_GROUP                    Equ         (0000023DH)
DOMAIN_ALIAS_RID_CERTSVC_DCOM_ACCESS_GROUP                  Equ         (0000023EH)


SECURITY_MANDATORY_UNTRUSTED_RID                            Equ         (00000000H)
SECURITY_MANDATORY_LOW_RID                                  Equ         (00001000H)
SECURITY_MANDATORY_MEDIUM_RID                               Equ         (00002000H)
SECURITY_MANDATORY_MEDIUM_PLUS_RID                          Equ         (SECURITY_MANDATORY_MEDIUM_RID + 0100H)
SECURITY_MANDATORY_HIGH_RID                                 Equ         (00003000H)
SECURITY_MANDATORY_SYSTEM_RID                               Equ         (00004000H)
SECURITY_MANDATORY_PROTECTED_PROCESS_RID                    Equ         (00005000H)

SECURITY_MANDATORY_MAXIMUM_USER_RID                         Equ         SECURITY_MANDATORY_SYSTEM_RID

ACE_HEADER Struct
    AceType                                                 DB
    AceFlags                                                DB
    AceSize                                                 DW
EndS

ACCESS_MIN_MS_ACE_TYPE                                      Equ         (00H)
ACCESS_ALLOWED_ACE_TYPE                                     Equ         (00H)
ACCESS_DENIED_ACE_TYPE                                      Equ         (01H)
SYSTEM_AUDIT_ACE_TYPE                                       Equ         (02H)
SYSTEM_ALARM_ACE_TYPE                                       Equ         (03H)
ACCESS_MAX_MS_V2_ACE_TYPE                                   Equ         (03H)

ACCESS_ALLOWED_COMPOUND_ACE_TYPE                            Equ         (04H)
ACCESS_MAX_MS_V3_ACE_TYPE                                   Equ         (04H)

ACCESS_MIN_MS_OBJECT_ACE_TYPE                               Equ         (05H)
ACCESS_ALLOWED_OBJECT_ACE_TYPE                              Equ         (05H)
ACCESS_DENIED_OBJECT_ACE_TYPE                               Equ         (06H)
SYSTEM_AUDIT_OBJECT_ACE_TYPE                                Equ         (07H)
SYSTEM_ALARM_OBJECT_ACE_TYPE                                Equ         (08H)
ACCESS_MAX_MS_OBJECT_ACE_TYPE                               Equ         (08H)

ACCESS_MAX_MS_V4_ACE_TYPE                                   Equ         (08H)
ACCESS_MAX_MS_ACE_TYPE                                      Equ         (08H)

ACCESS_ALLOWED_CALLBACK_ACE_TYPE                            Equ         (09H)
ACCESS_DENIED_CALLBACK_ACE_TYPE                             Equ         (0AH)
ACCESS_ALLOWED_CALLBACK_OBJECT_ACE_TYPE                     Equ         (0BH)
ACCESS_DENIED_CALLBACK_OBJECT_ACE_TYPE                      Equ         (0CH)
SYSTEM_AUDIT_CALLBACK_ACE_TYPE                              Equ         (0DH)
SYSTEM_ALARM_CALLBACK_ACE_TYPE                              Equ         (0EH)
SYSTEM_AUDIT_CALLBACK_OBJECT_ACE_TYPE                       Equ         (0FH)
SYSTEM_ALARM_CALLBACK_OBJECT_ACE_TYPE                       Equ         (10H)

SYSTEM_MANDATORY_LABEL_ACE_TYPE                             Equ         (11H)
ACCESS_MAX_MS_V5_ACE_TYPE                                   Equ         (11H)

OBJECT_INHERIT_ACE                                          Equ         (01H)
CONTAINER_INHERIT_ACE                                       Equ         (02H)
NO_PROPAGATE_INHERIT_ACE                                    Equ         (04H)
INHERIT_ONLY_ACE                                            Equ         (08H)
INHERITED_ACE                                               Equ         (10H)
VALID_INHERIT_FLAGS                                         Equ         (1FH)

SUCCESSFUL_ACCESS_ACE_FLAG                                  Equ         (40H)
FAILED_ACCESS_ACE_FLAG                                      Equ         (80H)

ACCESS_ALLOWED_ACE Struct
    Header                                                  ACE_HEADER
    Mask                                                    DD
    SidStart                                                DD
EndS

ACCESS_DENIED_ACE Struct
    Header                                                  ACE_HEADER
    Mask                                                    DD
    SidStart                                                DD
EndS

SYSTEM_AUDIT_ACE Struct
    Header                                                  ACE_HEADER
    Mask                                                    DD
    SidStart                                                DD
EndS

SYSTEM_ALARM_ACE Struct
    Header                                                  ACE_HEADER
    Mask                                                    DD
    SidStart                                                DD
EndS

SYSTEM_MANDATORY_LABEL_ACE Struct
    Header                                                  ACE_HEADER
    Mask                                                    DD
    SidStart                                                DD
EndS

SYSTEM_MANDATORY_LABEL_NO_WRITE_UP                          Equ         01H
SYSTEM_MANDATORY_LABEL_NO_READ_UP                           Equ         02H
SYSTEM_MANDATORY_LABEL_NO_EXECUTE_UP                        Equ         04H

SYSTEM_MANDATORY_LABEL_VALID_MASK                           Equ         (SYSTEM_MANDATORY_LABEL_NO_WRITE_UP | SYSTEM_MANDATORY_LABEL_NO_READ_UP | SYSTEM_MANDATORY_LABEL_NO_EXECUTE_UP)

SECURITY_DESCRIPTOR_MIN_LENGTH                              Equ         (SizeOf SECURITY_DESCRIPTOR)

SE_OWNER_DEFAULTED                                          Equ         (00001H)
SE_GROUP_DEFAULTED                                          Equ         (00002H)
SE_DACL_PRESENT                                             Equ         (00004H)
SE_DACL_DEFAULTED                                           Equ         (00008H)
SE_SACL_PRESENT                                             Equ         (00010H)
SE_SACL_DEFAULTED                                           Equ         (00020H)

SE_DACL_UNTRUSTED                                           Equ         (00040H)
SE_SERVER_SECURITY                                          Equ         (00080H)

SE_DACL_AUTO_INHERIT_REQ                                    Equ         (00100H)
SE_SACL_AUTO_INHERIT_REQ                                    Equ         (00200H)
SE_DACL_AUTO_INHERITED                                      Equ         (00400H)
SE_SACL_AUTO_INHERITED                                      Equ         (00800H)
SE_DACL_PROTECTED                                           Equ         (01000H)
SE_SACL_PROTECTED                                           Equ         (02000H)
SE_RM_CONTROL_VALID                                         Equ         (04000H)
SE_SELF_RELATIVE                                            Equ         (08000H)

SECURITY_DESCRIPTOR_RELATIVE Struct
    Revision                                                DB
    Sbz1                                                    DB
    Control                                                 SECURITY_DESCRIPTOR_CONTROL
    Owner                                                   DD
    Group                                                   DD
    Sacl                                                    DD
    Dacl                                                    DD
EndS

SECURITY_DESCRIPTOR Struct
    Revision                                                DB
    Sbz1                                                    DB
    Control                                                 SECURITY_DESCRIPTOR_CONTROL
   Owner                                                    DD
   Group                                                    DD
   Sacl                                                     DD
   Dacl                                                     DD
EndS

OBJECT_TYPE_LIST Struct
    Level                                                   DW
    Sbz                                                     DW
    ObjectType                                              DD
EndS

ACCESS_OBJECT_GUID                                          Equ         0
ACCESS_PROPERTY_SET_GUID                                    Equ         1
ACCESS_PROPERTY_GUID                                        Equ         2

ACCESS_MAX_LEVEL                                            Equ         4

;AUDIT_EVENT_TYPE Enumeration
AuditEventObjectAccess                                      Equ         0
AuditEventDirectoryServiceAccess                            Equ         1

AUDIT_ALLOW_NO_PRIVILEGE                                    Equ         01H

#Define                                                     ACCESS_DS_SOURCE_A "DS"
#Define                                                     ACCESS_DS_SOURCE_W L"DS"
#Define                                                     ACCESS_DS_OBJECT_TYPE_NAME_A "Directory Service Object"
#Define                                                     ACCESS_DS_OBJECT_TYPE_NAME_W L"Directory Service Object"

ACCESS_REASON_TYPE_MASK                                     Equ         0FFFF0000H
ACCESS_REASON_DATA_MASK                                     Equ         00000FFFFH

;ACCESS_REASON_TYPE Enumeration
AccessReasonNone                                            Equ         00000000H
AccessReasonAllowedAce                                      Equ         00010000H
AccessReasonDeniedAce                                       Equ         00020000H
AccessReasonAllowedParentAce                                Equ         00030000H
AccessReasonDeniedParentAce                                 Equ         00040000H
AccessReasonMissingPrivilege                                Equ         00100000H
AccessReasonFromPrivilege                                   Equ         00200000H
AccessReasonIntegrityLevel                                  Equ         00300000H
AccessReasonOwnership                                       Equ         00400000H
AccessReasonNullDacl                                        Equ         00500000H
AccessReasonEmptyDacl                                       Equ         00600000H
AccessReasonNoSD                                            Equ         00700000H
AccessReasonNoGrant                                         Equ         00800000H

ACCESS_REASONS Struct
        Data                                                DD          32 Dup ?
EndS

SE_SECURITY_DESCRIPTOR_FLAG_NO_OWNER_ACE                    Equ         00000001H
SE_SECURITY_DESCRIPTOR_FLAG_NO_LABEL_ACE                    Equ         00000002H
SE_SECURITY_DESCRIPTOR_VALID_FLAGS                          Equ         00000003H

SE_SECURITY_DESCRIPTOR Struct
    Size                                                    DD
    Flags                                                   DD
    SecurityDescriptor                                      DD
EndS

SE_ACCESS_REQUEST Struct
    Size                                                    DD
    SeSecurityDescriptor                                    DD
    DesiredAccess                                           DD
    PreviouslyGrantedAccess                                 DD
    PrincipalSelfSid                                        DD
    GenericMapping                                          DD
    ObjectTypeListCount                                     DD
    ObjectTypeList                                          DD
EndS

SE_ACCESS_REPLY Struct
    Size                                                    DD
    ResultListCount                                         DD
    GrantedAccess                                           DD
    AccessStatus                                            DD
    AccessReason                                            DD
    Privileges                                              DD
EndS

;SE_AUDIT_OPERATION Enumeration
AuditPrivilegeObject                                        Equ         0
AuditPrivilegeService                                       Equ         1
AuditAccessCheck                                            Equ         2
AuditOpenObject                                             Equ         3
AuditOpenObjectWithTransaction                              Equ         4
AuditCloseObject                                            Equ         5
AuditDeleteObject                                           Equ         6
AuditOpenObjectForDelete                                    Equ         7
AuditOpenObjectForDeleteWithTransaction                     Equ         8
AuditCloseNonObject                                         Equ         9
AuditOpenNonObject                                          Equ         10
AuditObjectReference                                        Equ         11
AuditHandleCreation                                         Equ         12

SE_AUDIT_INFO Struct
    Size                                                    DD
    AuditType                                               DD
    AuditOperation                                          DD
    AuditFlags                                              DD
    SubsystemName                                           UNICODE_STRING
    ObjectTypeName                                          UNICODE_STRING
    ObjectName                                              UNICODE_STRING
    HandleId                                                DD
    TransactionId                                           DD
    OperationId                                             DD
    ObjectCreation                                          DB
    GenerateOnClose                                         DB
EndS

TOKEN_ASSIGN_PRIMARY                                        Equ         (0001H)
TOKEN_DUPLICATE                                             Equ         (0002H)
TOKEN_IMPERSONATE                                           Equ         (0004H)
TOKEN_QUERY                                                 Equ         (0008H)
TOKEN_QUERY_SOURCE                                          Equ         (0010H)
TOKEN_ADJUST_PRIVILEGES                                     Equ         (0020H)
TOKEN_ADJUST_GROUPS                                         Equ         (0040H)
TOKEN_ADJUST_DEFAULT                                        Equ         (0080H)
TOKEN_ADJUST_SESSIONID                                      Equ         (0100H)

TOKEN_ALL_ACCESS_P                                          Equ         (STANDARD_RIGHTS_REQUIRED | TOKEN_ASSIGN_PRIMARY | TOKEN_DUPLICATE | TOKEN_IMPERSONATE | TOKEN_QUERY | TOKEN_QUERY_SOURCE | TOKEN_ADJUST_PRIVILEGES | TOKEN_ADJUST_GROUPS | TOKEN_ADJUST_DEFAULT)
TOKEN_ALL_ACCESS                                            Equ         (TOKEN_ALL_ACCESS_P | TOKEN_ADJUST_SESSIONID)
TOKEN_READ                                                  Equ         (STANDARD_RIGHTS_READ | TOKEN_QUERY)
TOKEN_WRITE                                                 Equ         (STANDARD_RIGHTS_WRITE | TOKEN_ADJUST_PRIVILEGES | TOKEN_ADJUST_GROUPS | TOKEN_ADJUST_DEFAULT)
TOKEN_EXECUTE                                               Equ         (STANDARD_RIGHTS_EXECUTE)

;TOKEN_TYPE Enumeration
TokenPrimary                                                Equ         1
TokenImpersonation                                          Equ         2

;TOKEN_ELEVATION_TYPE Enumeration
TokenElevationTypeDefault                                   Equ         1
TokenElevationTypeFull                                      Equ         2
TokenElevationTypeLimited                                   Equ         3

;TOKEN_INFORMATION_CLASS Enumeration
TokenUser                                                   Equ         1
TokenGroups                                                 Equ         2
TokenPrivileges                                             Equ         3
TokenOwner                                                  Equ         4
TokenPrimaryGroup                                           Equ         5
TokenDefaultDacl                                            Equ         6
TokenSource                                                 Equ         7
TokenType                                                   Equ         8
TokenImpersonationLevel                                     Equ         9
TokenStatistics                                             Equ         10
TokenRestrictedSids                                         Equ         11
TokenSessionId                                              Equ         12
TokenGroupsAndPrivileges                                    Equ         13
TokenSessionReference                                       Equ         14
TokenSandBoxInert                                           Equ         15
TokenAuditPolicy                                            Equ         16
TokenOrigin                                                 Equ         17
TokenElevationType                                          Equ         18
TokenLinkedToken                                            Equ         19
TokenElevation                                              Equ         20
TokenHasRestrictions                                        Equ         21
TokenAccessInformation                                      Equ         22
TokenVirtualizationAllowed                                  Equ         23
TokenVirtualizationEnabled                                  Equ         24
TokenIntegrityLevel                                         Equ         25
TokenUIAccess                                               Equ         26
TokenMandatoryPolicy                                        Equ         27
TokenLogonSid                                               Equ         28
MaxTokenInfoClass                                           Equ         29

TOKEN_USER Struct
    User                                                    SID_AND_ATTRIBUTES
EndS

TOKEN_GROUPS Struct
    GroupCount                                              DD
    Groups                                                  SID_AND_ATTRIBUTES  ANYSIZE_ARRAY Dup ?
EndS

TOKEN_PRIVILEGES Struct
    PrivilegeCount                                          DD
    Privileges                                              LUID_AND_ATTRIBUTES ANYSIZE_ARRAY Dup ?
EndS

TOKEN_OWNER Struct
    Owner                                                   DD
EndS

TOKEN_PRIMARY_GROUP Struct
    PrimaryGroup                                            DD
EndS

TOKEN_DEFAULT_DACL Struct
    DefaultDacl                                             DD
EndS

TOKEN_GROUPS_AND_PRIVILEGES Struct
    SidCount                                                DD
    SidLength                                               DD
    Sids                                                    DD
    RestrictedSidCount                                      DD
    RestrictedSidLength                                     DD
    RestrictedSids                                          DD
    PrivilegeCount                                          DD
    PrivilegeLength                                         DD
    Privileges                                              DD
    AuthenticationId                                        LUID
EndS

TOKEN_LINKED_TOKEN Struct
    LinkedToken                                             DD
EndS

TOKEN_ELEVATION Struct
    TokenIsElevated                                         DD
EndS

TOKEN_MANDATORY_LABEL Struct
    Label                                                   SID_AND_ATTRIBUTES
EndS

TOKEN_MANDATORY_POLICY_OFF                                  Equ         00H
TOKEN_MANDATORY_POLICY_NO_WRITE_UP                          Equ         01H
TOKEN_MANDATORY_POLICY_NEW_PROCESS_MIN                      Equ         02H

TOKEN_MANDATORY_POLICY_VALID_MASK                           Equ         (TOKEN_MANDATORY_POLICY_NO_WRITE_UP | TOKEN_MANDATORY_POLICY_NEW_PROCESS_MIN)

TOKEN_MANDATORY_POLICY Struct
    Policy                                                  DD
EndS

TOKEN_ACCESS_INFORMATION Struct
    SidHash                                                 DD
    RestrictedSidHash                                       DD
    Privileges                                              DD
    AuthenticationId                                        LUID
    TokenType                                               DD
    ImpersonationLevel                                      DD
    MandatoryPolicy                                         TOKEN_MANDATORY_POLICY
    Flags                                                   DD
EndS

POLICY_AUDIT_SUBCATEGORY_COUNT                              Equ         (53)

TOKEN_AUDIT_POLICY Struct
    PerUserPolicy                                           DB          (((POLICY_AUDIT_SUBCATEGORY_COUNT) >> 1) + 1) Dup ?
EndS

TOKEN_SOURCE_LENGTH                                         Equ         8

TOKEN_SOURCE Struct
    SourceName                                              DB          TOKEN_SOURCE_LENGTH Dup ?
    SourceIdentifier                                        LUID
EndS

TOKEN_STATISTICS Struct
    TokenId                                                 LUID
    AuthenticationId                                        LUID
    ExpirationTime                                          LARGE_INTEGER
    TokenType                                               DD
    ImpersonationLevel                                      DD
    DynamicCharged                                          DD
    DynamicAvailable                                        DD
    GroupCount                                              DD
    PrivilegeCount                                          DD
    ModifiedId                                              LUID
EndS

TOKEN_CONTROL Struct
    TokenId                                                 LUID
    AuthenticationId                                        LUID
    ModifiedId                                              LUID
    _TokenSource                                            TOKEN_SOURCE    ;TokenSource
EndS

TOKEN_ORIGIN Struct
    OriginatingLogonSession                                 LUID
EndS

;MANDATORY_LEVEL Enumeration
MandatoryLevelUntrusted                                     Equ         0
MandatoryLevelLow                                           Equ         1
MandatoryLevelMedium                                        Equ         2
MandatoryLevelHigh                                          Equ         3
MandatoryLevelSystem                                        Equ         4
MandatoryLevelSecureProcess                                 Equ         5
MandatoryLevelCount                                         Equ         6

RTL_HEAP_PARAMETERS Struct
    Length                                                  DD
    SegmentReserve                                          DD
    SegmentCommit                                           DD
    DeCommitFreeBlockThreshold                              DD
    DeCommitTotalFreeThreshold                              DD
    MaximumAllocationSize                                   DD
    VirtualMemoryThreshold                                  DD
    InitialCommit                                           DD
    InitialReserve                                          DD
    CommitRoutine                                           DD
    Reserved                                                DD          2 Dup ?
EndS

HEAP_NO_SERIALIZE                                           Equ         00000001H
HEAP_GROWABLE                                               Equ         00000002H
HEAP_GENERATE_EXCEPTIONS                                    Equ         00000004H
HEAP_ZERO_MEMORY                                            Equ         00000008H
HEAP_REALLOC_IN_PLACE_ONLY                                  Equ         00000010H
HEAP_TAIL_CHECKING_ENABLED                                  Equ         00000020H
HEAP_FREE_CHECKING_ENABLED                                  Equ         00000040H
HEAP_DISABLE_COALESCE_ON_FREE                               Equ         00000080H

HEAP_CREATE_ALIGN_16                                        Equ         00010000H
HEAP_CREATE_ENABLE_TRACING                                  Equ         00020000H
HEAP_CREATE_ENABLE_EXECUTE                                  Equ         00040000H

HEAP_SETTABLE_USER_VALUE                                    Equ         00000100H
HEAP_SETTABLE_USER_FLAG1                                    Equ         00000200H
HEAP_SETTABLE_USER_FLAG2                                    Equ         00000400H
HEAP_SETTABLE_USER_FLAG3                                    Equ         00000800H
HEAP_SETTABLE_USER_FLAGS                                    Equ         00000E00H

HEAP_CLASS_0                                                Equ         00000000H
HEAP_CLASS_1                                                Equ         00001000H
HEAP_CLASS_2                                                Equ         00002000H
HEAP_CLASS_3                                                Equ         00003000H
HEAP_CLASS_4                                                Equ         00004000H
HEAP_CLASS_5                                                Equ         00005000H
HEAP_CLASS_6                                                Equ         00006000H
HEAP_CLASS_7                                                Equ         00007000H
HEAP_CLASS_8                                                Equ         00008000H
HEAP_CLASS_MASK                                             Equ         0000F000H

HEAP_MAXIMUM_TAG                                            Equ         0FFFH
HEAP_GLOBAL_TAG                                             Equ         0800H
HEAP_PSEUDO_TAG_FLAG                                        Equ         8000H
HEAP_TAG_SHIFT                                              Equ         18
HEAP_TAG_MASK                                               Equ         (HEAP_MAXIMUM_TAG << HEAP_TAG_SHIFT)

GENERATE_NAME_CONTEXT Struct
    Checksum                                                DW
    ChecksumInserted                                        DB
    NameLength                                              DB
    NameBuffer                                              DW          8 Dup ?
    ExtensionLength                                         DD
    ExtensionBuffer                                         DW          4 Dup ?
    LastIndexValue                                          DD
EndS

PREFIX_TABLE_ENTRY Struct
    NodeTypeCode                                            DW
    NameLength                                              DW
    NextPrefixTree                                          DD
    Links                                                   RTL_SPLAY_LINKS
    Prefix                                                  DD
EndS

PREFIX_TABLE Struct
    NodeTypeCode                                            DW
    NameLength                                              DW
    NextPrefixTree                                          DD
EndS

UNICODE_PREFIX_TABLE_ENTRY Struct
    NodeTypeCode                                            DW
    NameLength                                              DW
    NextPrefixTree                                          DD
    CaseMatch                                               DD
    Links                                                   RTL_SPLAY_LINKS
    Prefix                                                  DD
EndS

UNICODE_PREFIX_TABLE Struct
    NodeTypeCode                                            DW
    NameLength                                              DW
    NextPrefixTree                                          DD
    LastNextEntry                                           DD
EndS

COMPRESSION_FORMAT_NONE                                     Equ         (0000H)
COMPRESSION_FORMAT_DEFAULT                                  Equ         (0001H)
COMPRESSION_FORMAT_LZNT1                                    Equ         (0002H)

COMPRESSION_ENGINE_STANDARD                                 Equ         (0000H)
COMPRESSION_ENGINE_MAXIMUM                                  Equ         (0100H)
COMPRESSION_ENGINE_HIBER                                    Equ         (0200H)

COMPRESSED_DATA_INFO Struct
    CompressionFormatAndEngine                              DW
    CompressionUnitShift                                    DB
    ChunkShift                                              DB
    ClusterShift                                            DB
    Reserved                                                DB
    NumberOfChunks                                          DW
    CompressedChunkSizes                                    DD          ANYSIZE_ARRAY Dup ?
EndS

FILE_DEVICE_BEEP                                            Equ         00000001H
FILE_DEVICE_CD_ROM                                          Equ         00000002H
FILE_DEVICE_CD_ROM_FILE_SYSTEM                              Equ         00000003H
FILE_DEVICE_CONTROLLER                                      Equ         00000004H
FILE_DEVICE_DATALINK                                        Equ         00000005H
FILE_DEVICE_DFS                                             Equ         00000006H
FILE_DEVICE_DISK                                            Equ         00000007H
FILE_DEVICE_DISK_FILE_SYSTEM                                Equ         00000008H
FILE_DEVICE_FILE_SYSTEM                                     Equ         00000009H
FILE_DEVICE_INPORT_PORT                                     Equ         0000000AH
FILE_DEVICE_KEYBOARD                                        Equ         0000000BH
FILE_DEVICE_MAILSLOT                                        Equ         0000000CH
FILE_DEVICE_MIDI_IN                                         Equ         0000000DH
FILE_DEVICE_MIDI_OUT                                        Equ         0000000EH
FILE_DEVICE_MOUSE                                           Equ         0000000FH
FILE_DEVICE_MULTI_UNC_PROVIDER                              Equ         00000010H
FILE_DEVICE_NAMED_PIPE                                      Equ         00000011H
FILE_DEVICE_NETWORK                                         Equ         00000012H
FILE_DEVICE_NETWORK_BROWSER                                 Equ         00000013H
FILE_DEVICE_NETWORK_FILE_SYSTEM                             Equ         00000014H
FILE_DEVICE_NULL                                            Equ         00000015H
FILE_DEVICE_PARALLEL_PORT                                   Equ         00000016H
FILE_DEVICE_PHYSICAL_NETCARD                                Equ         00000017H
FILE_DEVICE_PRINTER                                         Equ         00000018H
FILE_DEVICE_SCANNER                                         Equ         00000019H
FILE_DEVICE_SERIAL_MOUSE_PORT                               Equ         0000001AH
FILE_DEVICE_SERIAL_PORT                                     Equ         0000001BH
FILE_DEVICE_SCREEN                                          Equ         0000001CH
FILE_DEVICE_SOUND                                           Equ         0000001DH
FILE_DEVICE_STREAMS                                         Equ         0000001EH
FILE_DEVICE_TAPE                                            Equ         0000001FH
FILE_DEVICE_TAPE_FILE_SYSTEM                                Equ         00000020H
FILE_DEVICE_TRANSPORT                                       Equ         00000021H
FILE_DEVICE_UNKNOWN                                         Equ         00000022H
FILE_DEVICE_VIDEO                                           Equ         00000023H
FILE_DEVICE_VIRTUAL_DISK                                    Equ         00000024H
FILE_DEVICE_WAVE_IN                                         Equ         00000025H
FILE_DEVICE_WAVE_OUT                                        Equ         00000026H
FILE_DEVICE_8042_PORT                                       Equ         00000027H
FILE_DEVICE_NETWORK_REDIRECTOR                              Equ         00000028H
FILE_DEVICE_BATTERY                                         Equ         00000029H
FILE_DEVICE_BUS_EXTENDER                                    Equ         0000002AH
FILE_DEVICE_MODEM                                           Equ         0000002BH
FILE_DEVICE_VDM                                             Equ         0000002CH
FILE_DEVICE_MASS_STORAGE                                    Equ         0000002DH
FILE_DEVICE_SMB                                             Equ         0000002EH
FILE_DEVICE_KS                                              Equ         0000002FH
FILE_DEVICE_CHANGER                                         Equ         00000030H
FILE_DEVICE_SMARTCARD                                       Equ         00000031H
FILE_DEVICE_ACPI                                            Equ         00000032H
FILE_DEVICE_DVD                                             Equ         00000033H
FILE_DEVICE_FULLSCREEN_VIDEO                                Equ         00000034H
FILE_DEVICE_DFS_FILE_SYSTEM                                 Equ         00000035H
FILE_DEVICE_DFS_VOLUME                                      Equ         00000036H
FILE_DEVICE_SERENUM                                         Equ         00000037H
FILE_DEVICE_TERMSRV                                         Equ         00000038H
FILE_DEVICE_KSEC                                            Equ         00000039H
FILE_DEVICE_FIPS                                            Equ         0000003AH
FILE_DEVICE_INFINIBAND                                      Equ         0000003BH
FILE_DEVICE_VMBUS                                           Equ         0000003EH
FILE_DEVICE_CRYPT_PROVIDER                                  Equ         0000003FH
FILE_DEVICE_WPD                                             Equ         00000040H
FILE_DEVICE_BLUETOOTH                                       Equ         00000041H
FILE_DEVICE_MT_COMPOSITE                                    Equ         00000042H
FILE_DEVICE_MT_TRANSPORT                                    Equ         00000043H
FILE_DEVICE_BIOMETRIC                                       Equ         00000044H
FILE_DEVICE_PMI                                             Equ         00000045H

#IFNDEF MACRODRV_H
    #Include macrodrv.h
#ENDIF

METHOD_BUFFERED                                             Equ         0
METHOD_IN_DIRECT                                            Equ         1
METHOD_OUT_DIRECT                                           Equ         2
METHOD_NEITHER                                              Equ         3

METHOD_DIRECT_TO_HARDWARE                                   Equ         METHOD_IN_DIRECT
METHOD_DIRECT_FROM_HARDWARE                                 Equ         METHOD_OUT_DIRECT

FILE_ANY_ACCESS                                             Equ         0
FILE_SPECIAL_ACCESS                                         Equ         (FILE_ANY_ACCESS)
FILE_READ_ACCESS                                            Equ         (0001H)
FILE_WRITE_ACCESS                                           Equ         (0002H)

;SECURITY_LOGON_TYPE Enumeration
UndefinedLogonType                                          Equ         0
Interactive                                                 Equ         2
Network                                                     Equ         3
Batch                                                       Equ         4
Service                                                     Equ         5
Proxy                                                       Equ         6
Unlock                                                      Equ         7
NetworkCleartext                                            Equ         8
NewCredentials                                              Equ         9
RemoteInteractive                                           Equ         10
CachedInteractive                                           Equ         11
CachedRemoteInteractive                                     Equ         12
CachedUnlock                                                Equ         13

;SE_ADT_PARAMETER_TYPE Enumeration
SeAdtParmTypeNone                                           Equ         0
SeAdtParmTypeString                                         Equ         1
SeAdtParmTypeFileSpec                                       Equ         2
SeAdtParmTypeUlong                                          Equ         3
SeAdtParmTypeSid                                            Equ         4
SeAdtParmTypeLogonId                                        Equ         5
SeAdtParmTypeNoLogonId                                      Equ         6
SeAdtParmTypeAccessMask                                     Equ         7
SeAdtParmTypePrivs                                          Equ         8
SeAdtParmTypeObjectTypes                                    Equ         9
SeAdtParmTypeHexUlong                                       Equ         10
SeAdtParmTypePtr                                            Equ         11
SeAdtParmTypeTime                                           Equ         12
SeAdtParmTypeGuid                                           Equ         13
SeAdtParmTypeLuid                                           Equ         14
SeAdtParmTypeHexInt64                                       Equ         15
SeAdtParmTypeStringList                                     Equ         16
SeAdtParmTypeSidList                                        Equ         17
SeAdtParmTypeDuration                                       Equ         18
SeAdtParmTypeUserAccountControl                             Equ         19
SeAdtParmTypeNoUac                                          Equ         20
SeAdtParmTypeMessage                                        Equ         21
SeAdtParmTypeDateTime                                       Equ         22
SeAdtParmTypeSockAddr                                       Equ         23
SeAdtParmTypeSD                                             Equ         24
SeAdtParmTypeLogonHours                                     Equ         25
SeAdtParmTypeLogonIdNoSid                                   Equ         26
SeAdtParmTypeUlongNoConv                                    Equ         27
SeAdtParmTypeSockAddrNoPort                                 Equ         28
SeAdtParmTypeAccessReason                                   Equ         29

#IFNDEF GUID
    #Define                                 GUID_DEFINED 1
    GUID Struct
        Data1                               DD
        Data2                               DW
        Data3                               DW
        Data4                               DB          8 Dup ?
    EndS
    #Define                                 CLSID GUID
    #Define                                 IID   GUID
    #Define                                 FMTID GUID
#ENDIF

SE_ADT_PARAMETER_ARRAY_ENTRY Struct
    Type                                                    DD
    Length                                                  DD
    Data                                                    DD          2 Dup ?
    Address                                                 DD
EndS

SE_ADT_ACCESS_REASON Struct
    AccessMask                                              DD
    AccessReasons                                           DD          32 Dup ?
    ObjectTypeIndex                                         DD
    AccessGranted                                           DD
    SecurityDescriptor                                      DD
EndS

SE_MAX_AUDIT_PARAMETERS                                     Equ         32
SE_MAX_GENERIC_AUDIT_PARAMETERS                             Equ         28

SE_ADT_PARAMETERS_SELF_RELATIVE                             Equ         00000001H
SE_ADT_PARAMETERS_SEND_TO_LSA                               Equ         00000002H
SE_ADT_PARAMETER_EXTENSIBLE_AUDIT                           Equ         00000004H
SE_ADT_PARAMETER_GENERIC_AUDIT                              Equ         00000008H
SE_ADT_PARAMETER_WRITE_SYNCHRONOUS                          Equ         00000010H

#Define                                                     MSV1_0_PACKAGE_NAME "MICROSOFT_AUTHENTICATION_PACKAGE_V1_0"
#Define                                                     MSV1_0_PACKAGE_NAMEW L"MICROSOFT_AUTHENTICATION_PACKAGE_V1_0"
#Define                                                     MSV1_0_PACKAGE_NAMEW_LENGTH (SizeOf MSV1_0_PACKAGE_NAMEW - SizeOf Word)

#Define                                                     MSV1_0_SUBAUTHENTICATION_KEY "SYSTEM\CurrentControlSet\Control\Lsa\\MSV1_0"

;MSV1_0_LOGON_SUBMIT_TYPE Enumeration
MsV1_0InteractiveLogon                                      Equ         2
MsV1_0Lm20Logon                                             Equ         3
MsV1_0NetworkLogon                                          Equ         4
MsV1_0SubAuthLogon                                          Equ         5
MsV1_0WorkstationUnlockLogon                                Equ         7
MsV1_0S4ULogon                                              Equ         12
MsV1_0VirtualLogon                                          Equ         82

;MSV1_0_PROFILE_BUFFER_TYPE Enumeration
MsV1_0InteractiveProfile                                    Equ         2
MsV1_0Lm20LogonProfile                                      Equ         3
MsV1_0SmartCardProfile                                      Equ         4

MSV1_0_INTERACTIVE_LOGON Struct
    MessageType                                             DD
    LogonDomainName                                         UNICODE_STRING
    UserName                                                UNICODE_STRING
    Password                                                UNICODE_STRING
EndS

MSV1_0_INTERACTIVE_PROFILE Struct
    MessageType                                             DD
    LogonCount                                              DW
    BadPasswordCount                                        DW
    LogonTime                                               LARGE_INTEGER
    LogoffTime                                              LARGE_INTEGER
    KickOffTime                                             LARGE_INTEGER
    PasswordLastSet                                         LARGE_INTEGER
    PasswordCanChange                                       LARGE_INTEGER
    PasswordMustChange                                      LARGE_INTEGER
    LogonScript                                             UNICODE_STRING
    HomeDirectory                                           UNICODE_STRING
    FullName                                                UNICODE_STRING
    ProfilePath                                             UNICODE_STRING
    HomeDirectoryDrive                                      UNICODE_STRING
    LogonServer                                             UNICODE_STRING
    UserFlags                                               DD
EndS

MSV1_0_CHALLENGE_LENGTH                                     Equ         8
MSV1_0_USER_SESSION_KEY_LENGTH                              Equ         16
MSV1_0_LANMAN_SESSION_KEY_LENGTH                            Equ         8

MSV1_0_CLEARTEXT_PASSWORD_ALLOWED                           Equ         002H
MSV1_0_UPDATE_LOGON_STATISTICS                              Equ         004H
MSV1_0_RETURN_USER_PARAMETERS                               Equ         008H
MSV1_0_DONT_TRY_GUEST_ACCOUNT                               Equ         010H
MSV1_0_ALLOW_SERVER_TRUST_ACCOUNT                           Equ         020H
MSV1_0_RETURN_PASSWORD_EXPIRY                               Equ         040H
MSV1_0_USE_CLIENT_CHALLENGE                                 Equ         080H
SV1_0_TRY_GUEST_ACCOUNT_ONLY                                Equ         0100H
MSV1_0_RETURN_PROFILE_PATH                                  Equ         0200H
MSV1_0_TRY_SPECIFIED_DOMAIN_ONLY                            Equ         0400H
MSV1_0_ALLOW_WORKSTATION_TRUST_ACCOUNT                      Equ         0800H
MSV1_0_DISABLE_PERSONAL_FALLBACK                            Equ         00001000H
MSV1_0_ALLOW_FORCE_GUEST                                    Equ         00002000H
MSV1_0_CLEARTEXT_PASSWORD_SUPPLIED                          Equ         00004000H
MSV1_0_USE_DOMAIN_FOR_ROUTING_ONLY                          Equ         00008000H
MSV1_0_SUBAUTHENTICATION_DLL_EX                             Equ         00100000H
MSV1_0_ALLOW_MSVCHAPV2                                      Equ         00010000H

MSV1_0_S4U2SELF                                             Equ         00020000H
MSV1_0_CHECK_LOGONHOURS_FOR_S4U                             Equ         00040000H

MSV1_0_SUBAUTHENTICATION_DLL                                Equ         FF000000H
MSV1_0_SUBAUTHENTICATION_DLL_SHIFT                          Equ         24
MSV1_0_MNS_LOGON                                            Equ         01000000H

MSV1_0_SUBAUTHENTICATION_DLL_RAS                            Equ         2
MSV1_0_SUBAUTHENTICATION_DLL_IIS                            Equ         132

MSV1_0_LM20_LOGON Struct
    MessageType                                             DD
    LogonDomainName                                         UNICODE_STRING
    UserName                                                UNICODE_STRING
    Workstation                                             UNICODE_STRING
    ChallengeToClient                                       DB          MSV1_0_CHALLENGE_LENGTH Dup ?
    CaseSensitiveChallengeResponse                          STRING
    CaseInsensitiveChallengeResponse                        STRING
    ParameterControl                                        DD
EndS

MSV1_0_SUBAUTH_LOGON Struct
    MessageType                                             DD
    LogonDomainName                                         UNICODE_STRING
    UserName                                                UNICODE_STRING
    Workstation                                             UNICODE_STRING
    ChallengeToClient                                       DB          MSV1_0_CHALLENGE_LENGTH Dup ?
    AuthenticationInfo1                                     STRING
    AuthenticationInfo2                                     STRING
    ParameterControl                                        DD
    SubAuthPackageId                                        DD
EndS

MSV1_0_S4U_LOGON_FLAG_CHECK_LOGONHOURS                      Equ         02H

MSV1_0_S4U_LOGON Struct
    MessageType                                             DD
    Flags                                                   DD
    UserPrincipalName                                       UNICODE_STRING
    DomainName                                              UNICODE_STRING
EndS

LOGON_GUEST                                                 Equ         01H
LOGON_NOENCRYPTION                                          Equ         02H
LOGON_CACHED_ACCOUNT                                        Equ         04H
LOGON_USED_LM_PASSWORD                                      Equ         08H
LOGON_EXTRA_SIDS                                            Equ         20H
LOGON_SUBAUTH_SESSION_KEY                                   Equ         40H
LOGON_SERVER_TRUST_ACCOUNT                                  Equ         80H
LOGON_NTLMV2_ENABLED                                        Equ         100H
LOGON_RESOURCE_GROUPS                                       Equ         200H
LOGON_PROFILE_PATH_RETURNED                                 Equ         400H
LOGON_NT_V2                                                 Equ         800H
LOGON_LM_V2                                                 Equ         1000H
LOGON_NTLM_V2                                               Equ         2000H

LOGON_OPTIMIZED                                             Equ         4000H
LOGON_WINLOGON                                              Equ         8000H
LOGON_PKINIT                                                Equ         10000H
LOGON_NO_OPTIMIZED                                          Equ         20000H

MSV1_0_SUBAUTHENTICATION_FLAGS                              Equ         0FF000000H

LOGON_GRACE_LOGON                                           Equ         01000000H

MSV1_0_LM20_LOGON_PROFILE Struct
    MessageType                                             DD
    KickOffTime                                             LARGE_INTEGER
    LogoffTime                                              LARGE_INTEGER
    UserFlags                                               DD
    UserSessionKey                                          DB          MSV1_0_USER_SESSION_KEY_LENGTH Dup ?
    LogonDomainName                                         UNICODE_STRING
    LanmanSessionKey                                        DB          MSV1_0_LANMAN_SESSION_KEY_LENGTH Dup ?
    LogonServer                                             UNICODE_STRING
    UserParameters                                          UNICODE_STRING
EndS

MSV1_0_OWF_PASSWORD_LENGTH                                  Equ         16
MSV1_0_CRED_LM_PRESENT                                      Equ         01H
MSV1_0_CRED_NT_PRESENT                                      Equ         02H
MSV1_0_CRED_VERSION                                         Equ         0

MSV1_0_SUPPLEMENTAL_CREDENTIAL Struct
    Version                                                 DD
    Flags                                                   DD
    LmPassword                                              DB          MSV1_0_OWF_PASSWORD_LENGTH Dup ?
    NtPassword                                              DB          MSV1_0_OWF_PASSWORD_LENGTH Dup ?
EndS

MSV1_0_NTLM3_RESPONSE_LENGTH                                Equ         16
MSV1_0_NTLM3_OWF_LENGTH                                     Equ         16

MSV1_0_MAX_NTLM3_LIFE                                       Equ         129600
MSV1_0_MAX_AVL_SIZE                                         Equ         64000

MSV1_0_AV_FLAG_FORCE_GUEST                                  Equ         00000001H
MSV1_0_AV_FLAG_MIC_HANDSHAKE_MESSAGES                       Equ         00000002H

MSV1_0_NTLM3_RESPONSE Struct
    Response                                                DB          MSV1_0_NTLM3_RESPONSE_LENGTH Dup ?
    RespType                                                DB
    HiRespType                                              DB
    Flags                                                   DW
    MsgWord                                                 DD
    TimeStamp                                               DQ
    ChallengeFromClient                                     DB          MSV1_0_CHALLENGE_LENGTH Dup ?
    AvPairsOff                                              DD
    Buffer                                                  DB          1 Dup ?
EndS

MSV1_0_NTLM3_INPUT_LENGTH                                   Equ         ((SizeOf MSV1_0_NTLM3_RESPONSE) - MSV1_0_NTLM3_RESPONSE_LENGTH)

;MSV1_0_AVID Enumeration
MsvAvEOL                                                    Equ         0
MsvAvNbComputerName                                         Equ         1
MsvAvNbDomainName                                           Equ         2
MsvAvDnsComputerName                                        Equ         3
MsvAvDnsDomainName                                          Equ         4
MsvAvDnsTreeName                                            Equ         5
MsvAvFlags                                                  Equ         6
MsvAvTimestamp                                              Equ         7
MsvAvRestrictions                                           Equ         8
MsvAvTargetName                                             Equ         9
MsvAvChannelBindings                                        Equ         10

MSV1_0_AV_PAIR Struct
    AvId                                                    DW
    AvLen                                                   DW
EndS

;MSV1_0_PROTOCOL_MESSAGE_TYPE Enumeration
MsV1_0Lm20ChallengeRequest                                  Equ         0
MsV1_0Lm20GetChallengeResponse                              Equ         1
MsV1_0EnumerateUsers                                        Equ         2
MsV1_0GetUserInfo                                           Equ         3
MsV1_0ReLogonUsers                                          Equ         4
MsV1_0ChangePassword                                        Equ         5
MsV1_0ChangeCachedPassword                                  Equ         6
MsV1_0GenericPassthrough                                    Equ         7
MsV1_0CacheLogon                                            Equ         8
MsV1_0SubAuth                                               Equ         9
MsV1_0DeriveCredential                                      Equ         10
MsV1_0CacheLookup                                           Equ         11
MsV1_0SetProcessOption                                      Equ         12
MsV1_0ConfigLocalAliases                                    Equ         13
MsV1_0ClearCachedCredentials                                Equ         14

MSV1_0_LM20_CHALLENGE_REQUEST Struct
    MessageType                                             DD
EndS

MSV1_0_LM20_CHALLENGE_RESPONSE Struct
    MessageType                                             DD
    ChallengeToClient                                       DB          MSV1_0_CHALLENGE_LENGTH Dup ?
EndS

USE_PRIMARY_PASSWORD                                        Equ         01H
RETURN_PRIMARY_USERNAME                                     Equ         02H
RETURN_PRIMARY_LOGON_DOMAINNAME                             Equ         04H
RETURN_NON_NT_USER_SESSION_KEY                              Equ         08H
GENERATE_CLIENT_CHALLENGE                                   Equ         10H
GCR_NTLM3_PARMS                                             Equ         20H
GCR_TARGET_INFO                                             Equ         40H
RETURN_RESERVED_PARAMETER                                   Equ         80H
GCR_ALLOW_NTLM                                              Equ         100H
GCR_USE_OEM_SET                                             Equ         200H
GCR_MACHINE_CREDENTIAL                                      Equ         400H
GCR_USE_OWF_PASSWORD                                        Equ         800H
GCR_ALLOW_LM                                                Equ         1000H
GCR_ALLOW_NO_TARGET                                         Equ         2000H

MSV1_0_GETCHALLENRESP_REQUEST_V1 Struct
    MessageType                                             DD
    ParameterControl                                        DD
    LogonId                                                 LUID
    Password                                                UNICODE_STRING
    ChallengeToClient                                       DB          MSV1_0_CHALLENGE_LENGTH Dup ?
EndS

MSV1_0_GETCHALLENRESP_REQUEST Struct
    MessageType                                             DD
    ParameterControl                                        DD
    LogonId                                                 LUID
    Password                                                UNICODE_STRING
    ChallengeToClient                                       DB          MSV1_0_CHALLENGE_LENGTH Dup ?
    UserName                                                UNICODE_STRING
    LogonDomainName                                         UNICODE_STRING
    ServerName                                              UNICODE_STRING
EndS

MSV1_0_GETCHALLENRESP_RESPONSE Struct
    MessageType                                             DD
    CaseSensitiveChallengeResponse                          STRING
    CaseInsensitiveChallengeResponse                        STRING
    UserName                                                UNICODE_STRING
    LogonDomainName                                         UNICODE_STRING
    UserSessionKey                                          DB          MSV1_0_USER_SESSION_KEY_LENGTH Dup ?
    LanmanSessionKey                                        DB          MSV1_0_LANMAN_SESSION_KEY_LENGTH Dup ?
EndS

MSV1_0_ENUMUSERS_REQUEST Struct
    MessageType                                             DD
EndS

MSV1_0_ENUMUSERS_RESPONSE Struct
    MessageType                                             DD
    NumberOfLoggedOnUsers                                   DD
    LogonIds                                                DD
    EnumHandles                                             DD
EndS

MSV1_0_GETUSERINFO_REQUEST Struct
    MessageType                                             DD
    LogonId                                                 LUID
EndS

MSV1_0_GETUSERINFO_RESPONSE Struct
    MessageType                                             DD
    UserSid                                                 DD
    UserName                                                UNICODE_STRING
    LogonDomainName                                         UNICODE_STRING
    LogonServer                                             UNICODE_STRING
    LogonType                                               DD
EndS

FILE_OPLOCK_BROKEN_TO_LEVEL_2                               Equ         00000007H
FILE_OPLOCK_BROKEN_TO_NONE                                  Equ         00000008H

FILE_OPBATCH_BREAK_UNDERWAY                                 Equ         00000009H

FILE_NOTIFY_CHANGE_FILE_NAME                                Equ         00000001H
FILE_NOTIFY_CHANGE_DIR_NAME                                 Equ         00000002H
FILE_NOTIFY_CHANGE_NAME                                     Equ         00000003H
FILE_NOTIFY_CHANGE_ATTRIBUTES                               Equ         00000004H
FILE_NOTIFY_CHANGE_SIZE                                     Equ         00000008H
FILE_NOTIFY_CHANGE_LAST_WRITE                               Equ         00000010H
FILE_NOTIFY_CHANGE_LAST_ACCESS                              Equ         00000020H
FILE_NOTIFY_CHANGE_CREATION                                 Equ         00000040H
FILE_NOTIFY_CHANGE_EA                                       Equ         00000080H
FILE_NOTIFY_CHANGE_SECURITY                                 Equ         00000100H
FILE_NOTIFY_CHANGE_STREAM_NAME                              Equ         00000200H
FILE_NOTIFY_CHANGE_STREAM_SIZE                              Equ         00000400H
FILE_NOTIFY_CHANGE_STREAM_WRITE                             Equ         00000800H
FILE_NOTIFY_VALID_MASK                                      Equ         00000FFFH

FILE_ACTION_ADDED                                           Equ         00000001H
FILE_ACTION_REMOVED                                         Equ         00000002H
FILE_ACTION_MODIFIED                                        Equ         00000003H
FILE_ACTION_RENAMED_OLD_NAME                                Equ         00000004H
FILE_ACTION_RENAMED_NEW_NAME                                Equ         00000005H
FILE_ACTION_ADDED_STREAM                                    Equ         00000006H
FILE_ACTION_REMOVED_STREAM                                  Equ         00000007H
FILE_ACTION_MODIFIED_STREAM                                 Equ         00000008H
FILE_ACTION_REMOVED_BY_DELETE                               Equ         00000009H
FILE_ACTION_ID_NOT_TUNNELLED                                Equ         0000000AH
FILE_ACTION_TUNNELLED_ID_COLLISION                          Equ         0000000BH

FILE_PIPE_BYTE_STREAM_TYPE                                  Equ         00000000H
FILE_PIPE_MESSAGE_TYPE                                      Equ         00000001H

FILE_PIPE_ACCEPT_REMOTE_CLIENTS                             Equ         00000000H
FILE_PIPE_REJECT_REMOTE_CLIENTS                             Equ         00000002H

FILE_PIPE_TYPE_VALID_MASK                                   Equ         00000003H

FILE_PIPE_QUEUE_OPERATION                                   Equ         00000000H
FILE_PIPE_COMPLETE_OPERATION                                Equ         00000001H

FILE_PIPE_BYTE_STREAM_MODE                                  Equ         00000000H
FILE_PIPE_MESSAGE_MODE                                      Equ         00000001H

FILE_PIPE_INBOUND                                           Equ         00000000H
FILE_PIPE_OUTBOUND                                          Equ         00000001H
FILE_PIPE_FULL_DUPLEX                                       Equ         00000002H

FILE_PIPE_DISCONNECTED_STATE                                Equ         00000001H
FILE_PIPE_LISTENING_STATE                                   Equ         00000002H
FILE_PIPE_CONNECTED_STATE                                   Equ         00000003H
FILE_PIPE_CLOSING_STATE                                     Equ         00000004H

FILE_PIPE_CLIENT_END                                        Equ         00000000H
FILE_PIPE_SERVER_END                                        Equ         00000001H

FILE_CASE_SENSITIVE_SEARCH                                  Equ         00000001H
FILE_CASE_PRESERVED_NAMES                                   Equ         00000002H
FILE_UNICODE_ON_DISK                                        Equ         00000004H
FILE_PERSISTENT_ACLS                                        Equ         00000008H
FILE_FILE_COMPRESSION                                       Equ         00000010H
FILE_VOLUME_QUOTAS                                          Equ         00000020H
FILE_SUPPORTS_SPARSE_FILES                                  Equ         00000040H
FILE_SUPPORTS_REPARSE_POINTS                                Equ         00000080H
FILE_SUPPORTS_REMOTE_STORAGE                                Equ         00000100H
FILE_VOLUME_IS_COMPRESSED                                   Equ         00008000H
FILE_SUPPORTS_OBJECT_IDS                                    Equ         00010000H
FILE_SUPPORTS_ENCRYPTION                                    Equ         00020000H
FILE_NAMED_STREAMS                                          Equ         00040000H
FILE_READ_ONLY_VOLUME                                       Equ         00080000H
FILE_SEQUENTIAL_WRITE_ONCE                                  Equ         00100000H
FILE_SUPPORTS_TRANSACTIONS                                  Equ         00200000H
FILE_SUPPORTS_HARD_LINKS                                    Equ         00400000H
FILE_SUPPORTS_EXTENDED_ATTRIBUTES                           Equ         00800000H
FILE_SUPPORTS_OPEN_BY_FILE_ID                               Equ         01000000H
FILE_SUPPORTS_USN_JOURNAL                                   Equ         02000000H

FILE_NEED_EA                                                Equ         00000080H

FILE_EA_TYPE_BINARY                                         Equ         0FFFEH
FILE_EA_TYPE_ASCII                                          Equ         0FFFDH
FILE_EA_TYPE_BITMAP                                         Equ         0FFFBH
FILE_EA_TYPE_METAFILE                                       Equ         0FFFAH
FILE_EA_TYPE_ICON                                           Equ         0FFF9H
FILE_EA_TYPE_EA                                             Equ         0FFEEH
FILE_EA_TYPE_MVMT                                           Equ         0FFDEH
FILE_EA_TYPE_MVST                                           Equ         0FFDEH
FILE_EA_TYPE_ASN1                                           Equ         0FFDDH
FILE_EA_TYPE_FAMILY_IDS                                     Equ         0FF01H

FILE_NOTIFY_INFORMATION Struct
    NextEntryOffset                                         DD
    Action                                                  DD
    FileNameLength                                          DD
    FileName                                                DW          1 Dup ?
EndS

FILE_DIRECTORY_INFORMATION Struct
    NextEntryOffset                                         DD
    FileIndex                                               DD
    CreationTime                                            LARGE_INTEGER
    LastAccessTime                                          LARGE_INTEGER
    LastWriteTime                                           LARGE_INTEGER
    ChangeTime                                              LARGE_INTEGER
    EndOfFile                                               LARGE_INTEGER
    AllocationSize                                          LARGE_INTEGER
    FileAttributes                                          DD
    FileNameLength                                          DD
    FileName                                                DW          1 Dup ?
EndS

FILE_FULL_DIR_INFORMATION Struct
    NextEntryOffset                                         DD
    FileIndex                                               DD
    CreationTime                                            LARGE_INTEGER
    LastAccessTime                                          LARGE_INTEGER
    LastWriteTime                                           LARGE_INTEGER
    ChangeTime                                              LARGE_INTEGER
    EndOfFile                                               LARGE_INTEGER
    AllocationSize                                          LARGE_INTEGER
    FileAttributes                                          DD
    FileNameLength                                          DD
    EaSize                                                  DD
    FileName                                                DW          1 Dup ?
Ends

FILE_ID_FULL_DIR_INFORMATION Struct
    NextEntryOffset                                         DD
    FileIndex                                               DD
    CreationTime                                            LARGE_INTEGER
    LastAccessTime                                          LARGE_INTEGER
    LastWriteTime                                           LARGE_INTEGER
    ChangeTime                                              LARGE_INTEGER
    EndOfFile                                               LARGE_INTEGER
    AllocationSize                                          LARGE_INTEGER
    FileAttributes                                          DD
    FileNameLength                                          DD
    EaSize                                                  DD
    FileId                                                  LARGE_INTEGER
    FileName                                                DW          1 Dup ?
EndS

FILE_BOTH_DIR_INFORMATION Struct
    NextEntryOffset                                         DD
    FileIndex                                               DD
    CreationTime                                            LARGE_INTEGER
    LastAccessTime                                          LARGE_INTEGER
    LastWriteTime                                           LARGE_INTEGER
    ChangeTime                                              LARGE_INTEGER
    EndOfFile                                               LARGE_INTEGER
    AllocationSize                                          LARGE_INTEGER
    FileAttributes                                          DD
    FileNameLength                                          DD
    EaSize                                                  DD
    ShortNameLength                                         DW
    ShortName                                               DW          12 Dup ?
    FileName                                                DW          1 Dup ?
EndS

FILE_ID_BOTH_DIR_INFORMATION Struct
    NextEntryOffset                                         DD
    FileIndex                                               DD
    CreationTime                                            LARGE_INTEGER
    LastAccessTime                                          LARGE_INTEGER
    LastWriteTime                                           LARGE_INTEGER
    ChangeTime                                              LARGE_INTEGER
    EndOfFile                                               LARGE_INTEGER
    AllocationSize                                          LARGE_INTEGER
    FileAttributes                                          DD
    FileNameLength                                          DD
    EaSize                                                  DD
    ShortNameLength                                         DW
    ShortName                                               DW          12 Dup ?
    FileId                                                  LARGE_INTEGER
    FileName                                                DW          1 Dup ?
EndS

FILE_NAMES_INFORMATION Struct
    NextEntryOffset                                         DD
    FileIndex                                               DD
    FileNameLength                                          DD
    FileName                                                DW          1 Dup ?
EndS

FILE_ID_GLOBAL_TX_DIR_INFORMATION Struct
    NextEntryOffset                                         DD
    FileIndex                                               DD
    CreationTime                                            LARGE_INTEGER
    LastAccessTime                                          LARGE_INTEGER
    LastWriteTime                                           LARGE_INTEGER
    ChangeTime                                              LARGE_INTEGER
    EndOfFile                                               LARGE_INTEGER
    AllocationSize                                          LARGE_INTEGER
    FileAttributes                                          DD
    FileNameLength                                          DD
    FileId                                                  LARGE_INTEGER
    LockingTransactionId                                    GUID
    TxInfoFlags                                             DD
    FileName                                                DW          1 Dup ?
EndS

FILE_ID_GLOBAL_TX_DIR_INFO_FLAG_WRITELOCKED                 Equ         00000001H
FILE_ID_GLOBAL_TX_DIR_INFO_FLAG_VISIBLE_TO_TX               Equ         00000002H
FILE_ID_GLOBAL_TX_DIR_INFO_FLAG_VISIBLE_OUTSIDE_TX          Equ         00000004H

FILE_OBJECTID_INFORMATION Struct
    FileReference                                           DQ
    ObjectId                                                DB          16 Dup ?
    DUMMYUNIONNAME Union
        DUMMYSTRUCTNAME Struct
            BirthVolumeId                                   DB          16 Dup ?
            BirthObjectId                                   DB          16 Dup ?
            DomainId                                        DB          16 Dup ?
        EndS
        ExtendedInfo                                        DB          48 Dup ?
    EndUnion
EndS

#Define                                                     ANSI_DOS_STAR "<"
#Define                                                     ANSI_DOS_QM   ">"
#Define                                                     ANSI_DOS_DOT  34

#Define                                                     DOS_STAR L"<"
#Define                                                     DOS_QM   L">"
#Define                                                     DOS_DOT  L'"'

FILE_INTERNAL_INFORMATION Struct
    IndexNumber                                             LARGE_INTEGER
EndS

FILE_EA_INFORMATION Struct
    EaSize                                                  DD
EndS

FILE_ACCESS_INFORMATION Struct
    AccessFlags                                             DD
EndS

FILE_MODE_INFORMATION Struct
    Mode                                                    DD
EndS

FILE_ALL_INFORMATION Struct
    BasicInformation                                        FILE_BASIC_INFORMATION
    StandardInformation                                     FILE_STANDARD_INFORMATION
    InternalInformation                                     FILE_INTERNAL_INFORMATION
    EaInformation                                           FILE_EA_INFORMATION
    AccessInformation                                       FILE_ACCESS_INFORMATION
    PositionInformation                                     FILE_POSITION_INFORMATION
    ModeInformation                                         FILE_MODE_INFORMATION
    AlignmentInformation                                    FILE_ALIGNMENT_INFORMATION
    NameInformation                                         FILE_NAME_INFORMATION
EndS

FILE_ALLOCATION_INFORMATION Struct
    AllocationSize                                          LARGE_INTEGER
EndS

FILE_COMPRESSION_INFORMATION Struct
    CompressedFileSize                                      LARGE_INTEGER
    CompressionFormat                                       DW
    CompressionUnitShift                                    DB
    ChunkShift                                              DB
    ClusterShift                                            DB
    Reserved                                                DB          3 Dup ?
EndS

FILE_LINK_INFORMATION Struct
    ReplaceIfExists                                         DB
    RootDirectory                                           DD
    FileNameLength                                          DD
    FileName                                                DW          1 Dup ?
EndS

FILE_MOVE_CLUSTER_INFORMATION Struct
    ClusterCount                                            DD
    RootDirectory                                           DD
    FileNameLength                                          DD
    FileName                                                DW          1 Dup ?
EndS

FILE_RENAME_INFORMATION Struct
    ReplaceIfExists                                         DB
    RootDirectory                                           DD
    FileNameLength                                          DD
    FileName                                                DW          1 Dup ?
EndS

FILE_STREAM_INFORMATION Struct
    NextEntryOffset                                         DD
    StreamNameLength                                        DD
    StreamSize                                              LARGE_INTEGER
    StreamAllocationSize                                    LARGE_INTEGER
    StreamName                                              DW          1 Dup ?
EndS

FILE_TRACKING_INFORMATION Struct
    DestinationFile                                         DD
    ObjectInformationLength                                 DD
    ObjectInformation                                       DB          1 Dup ?
EndS

FILE_COMPLETION_INFORMATION Struct
    Port                                                    DD
    Key                                                     DD
EndS

FILE_PIPE_INFORMATION Struct
    ReadMode                                                DD
    CompletionMode                                          DD
EndS

FILE_PIPE_LOCAL_INFORMATION Struct
    NamedPipeType                                           DD
    NamedPipeConfiguration                                  DD
    MaximumInstances                                        DD
    CurrentInstances                                        DD
    InboundQuota                                            DD
    ReadDataAvailable                                       DD
    OutboundQuota                                           DD
    WriteQuotaAvailable                                     DD
    NamedPipeState                                          DD
    NamedPipeEnd                                            DD
EndS

FILE_PIPE_REMOTE_INFORMATION Struct
    CollectDataTime                                         LARGE_INTEGER
    MaximumCollectionCount                                  DD
EndS

FILE_MAILSLOT_QUERY_INFORMATION Struct
    MaximumMessageSize                                      DD
    MailslotQuota                                           DD
    NextMessageSize                                         DD
    MessagesAvailable                                       DD
    ReadTimeout                                             LARGE_INTEGER
EndS

FILE_MAILSLOT_SET_INFORMATION Struct
    ReadTimeout                                             DD
EndS

FILE_REPARSE_POINT_INFORMATION Struct
    FileReference                                           DQ
    Tag                                                     DD
EndS

FILE_LINK_ENTRY_INFORMATION Struct
    NextEntryOffset                                         DD
    ParentFileId                                            DQ
    FileNameLength                                          DD
    FileName                                                DW          1 Dup ?
EndS

FILE_LINKS_INFORMATION Struct
    BytesNeeded                                             DD
    EntriesReturned                                         DD
    Entry                                                   FILE_LINK_ENTRY_INFORMATION
EndS

FILE_NETWORK_PHYSICAL_NAME_INFORMATION Struct
    FileNameLength                                          DD
    FileName                                                DW          1 Dup ?
EndS

FILE_STANDARD_LINK_INFORMATION Struct
    NumberOfAccessibleLinks                                 DD
    TotalNumberOfLinks                                      DD
    DeletePending                                           DB
    Directory                                               DB
EndS

FILE_GET_EA_INFORMATION Struct
    NextEntryOffset                                         DD
    EaNameLength                                            DB
    EaName                                                  DB          1 Dup ?
EndS

REMOTE_PROTOCOL_FLAG_LOOPBACK                               Equ         00000001H
REMOTE_PROTOCOL_FLAG_OFFLINE                                Equ         00000002H

FILE_REMOTE_PROTOCOL_INFORMATION Struct
    StructureVersion                                        DW
    StructureSize                                           DW
    Protocol                                                DD
    ProtocolMajorVersion                                    DW
    ProtocolMinorVersion                                    DW
    ProtocolRevision                                        DW
    Reserved                                                DW
    Flags                                                   DD
    GenericReserved Struct
        Reserved                                            DD          8 Dup ?
    EndS
    ProtocolSpecificReserved Struct
        Reserved                                            DD          16 Dup ?
    EndS
EndS

FILE_GET_QUOTA_INFORMATION Struct
    NextEntryOffset                                         DD
    SidLength                                               DD
    Sid                                                     SID
EndS

FILE_QUOTA_INFORMATION Struct
    NextEntryOffset                                         DD
    SidLength                                               DD
    ChangeTime                                              LARGE_INTEGER
    QuotaUsed                                               LARGE_INTEGER
    QuotaThreshold                                          LARGE_INTEGER
    QuotaLimit                                              LARGE_INTEGER
    Sid                                                     SID
EndS

FILE_FS_ATTRIBUTE_INFORMATION Struct
    FileSystemAttributes                                    DD
    MaximumComponentNameLength                              DD
    FileSystemNameLength                                    DD
    FileSystemName                                          DW          1 Dup ?
EndS

FILE_FS_DRIVER_PATH_INFORMATION Struct
    DriverInPath                                            DB
    DriverNameLength                                        DD
    DriverName                                              DW          1 Dup ?
EndS

FILE_FS_VOLUME_FLAGS_INFORMATION Struct
    Flags                                                   DD
EndS

FILE_VC_QUOTA_NONE                                          Equ         00000000H
FILE_VC_QUOTA_TRACK                                         Equ         00000001H
FILE_VC_QUOTA_ENFORCE                                       Equ         00000002H
FILE_VC_QUOTA_MASK                                          Equ         00000003H

FILE_VC_CONTENT_INDEX_DISABLED                              Equ         00000008H

FILE_VC_LOG_QUOTA_THRESHOLD                                 Equ         00000010H
FILE_VC_LOG_QUOTA_LIMIT                                     Equ         00000020H
FILE_VC_LOG_VOLUME_THRESHOLD                                Equ         00000040H
FILE_VC_LOG_VOLUME_LIMIT                                    Equ         00000080H

FILE_VC_QUOTAS_INCOMPLETE                                   Equ         00000100H
FILE_VC_QUOTAS_REBUILDING                                   Equ         00000200H

FILE_VC_VALID_MASK                                          Equ         000003FFH

FILE_FS_CONTROL_INFORMATION Struct
    FreeSpaceStartFiltering                                 LARGE_INTEGER
    FreeSpaceThreshold                                      LARGE_INTEGER
    FreeSpaceStopFiltering                                  LARGE_INTEGER
    DefaultQuotaThreshold                                   LARGE_INTEGER
    DefaultQuotaLimit                                       LARGE_INTEGER
    FileSystemControlFlags                                  DD
EndS

#IFNDEF _FILESYSTEMFSCTL
    _FILESYSTEMFSCTL                                        Equ         1
    FSCTL_REQUEST_OPLOCK_LEVEL_1                            Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM,  0, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_REQUEST_OPLOCK_LEVEL_2                            Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM,  1, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_REQUEST_BATCH_OPLOCK                              Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM,  2, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_OPLOCK_BREAK_ACKNOWLEDGE                          Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM,  3, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_OPBATCH_ACK_CLOSE_PENDING                         Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM,  4, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_OPLOCK_BREAK_NOTIFY                               Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM,  5, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_LOCK_VOLUME                                       Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM,  6, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_UNLOCK_VOLUME                                     Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM,  7, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_DISMOUNT_VOLUME                                   Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM,  8, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_IS_VOLUME_MOUNTED                                 Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 10, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_IS_PATHNAME_VALID                                 Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 11, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_MARK_VOLUME_DIRTY                                 Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 12, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_QUERY_RETRIEVAL_POINTERS                          Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 14, METHOD_NEITHER, FILE_ANY_ACCESS)
    FSCTL_GET_COMPRESSION                                   Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 15, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_SET_COMPRESSION                                   Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 16, METHOD_BUFFERED, FILE_READ_DATA | FILE_WRITE_DATA)
    FSCTL_SET_BOOTLOADER_ACCESSED                           Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 19, METHOD_NEITHER, FILE_ANY_ACCESS)
    FSCTL_OPLOCK_BREAK_ACK_NO_2                             Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 20, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_INVALIDATE_VOLUMES                                Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 21, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_QUERY_FAT_BPB                                     Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 22, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_REQUEST_FILTER_OPLOCK                             Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 23, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_FILESYSTEM_GET_STATISTICS                         Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 24, METHOD_BUFFERED, FILE_ANY_ACCESS)

    FSCTL_GET_NTFS_VOLUME_DATA                              Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 25, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_GET_NTFS_FILE_RECORD                              Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 26, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_GET_VOLUME_BITMAP                                 Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 27, METHOD_NEITHER, FILE_ANY_ACCESS)
    FSCTL_GET_RETRIEVAL_POINTERS                            Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 28, METHOD_NEITHER, FILE_ANY_ACCESS)
    FSCTL_MOVE_FILE                                         Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 29, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
    FSCTL_IS_VOLUME_DIRTY                                   Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 30, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_ALLOW_EXTENDED_DASD_IO                            Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 32, METHOD_NEITHER,  FILE_ANY_ACCESS)

    FSCTL_FIND_FILES_BY_SID                                 Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 35, METHOD_NEITHER, FILE_ANY_ACCESS)
    FSCTL_SET_OBJECT_ID                                     Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 38, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
    FSCTL_GET_OBJECT_ID                                     Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 39, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_DELETE_OBJECT_ID                                  Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 40, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
    FSCTL_SET_REPARSE_POINT                                 Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 41, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
    FSCTL_GET_REPARSE_POINT                                 Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 42, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_DELETE_REPARSE_POINT                              Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 43, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
    FSCTL_ENUM_USN_DATA                                     Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 44, METHOD_NEITHER, FILE_ANY_ACCESS)
    FSCTL_SECURITY_ID_CHECK                                 Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 45, METHOD_NEITHER, FILE_READ_DATA)
    FSCTL_READ_USN_JOURNAL                                  Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 46, METHOD_NEITHER, FILE_ANY_ACCESS)
    FSCTL_SET_OBJECT_ID_EXTENDED                            Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 47, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
    FSCTL_CREATE_OR_GET_OBJECT_ID                           Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 48, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_SET_SPARSE                                        Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 49, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
    FSCTL_SET_ZERO_DATA                                     Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 50, METHOD_BUFFERED, FILE_WRITE_DATA)
    FSCTL_QUERY_ALLOCATED_RANGES                            Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 51, METHOD_NEITHER, FILE_READ_DATA)
    FSCTL_ENABLE_UPGRADE                                    Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 52, METHOD_BUFFERED, FILE_WRITE_DATA)
    FSCTL_SET_ENCRYPTION                                    Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 53, METHOD_NEITHER, FILE_ANY_ACCESS)
    FSCTL_ENCRYPTION_FSCTL_IO                               Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 54, METHOD_NEITHER, FILE_ANY_ACCESS)
    FSCTL_WRITE_RAW_ENCRYPTED                               Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 55, METHOD_NEITHER, FILE_SPECIAL_ACCESS)
    FSCTL_READ_RAW_ENCRYPTED                                Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 56, METHOD_NEITHER, FILE_SPECIAL_ACCESS)
    FSCTL_CREATE_USN_JOURNAL                                Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 57, METHOD_NEITHER, FILE_ANY_ACCESS)
    FSCTL_READ_FILE_USN_DATA                                Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 58, METHOD_NEITHER, FILE_ANY_ACCESS)
    FSCTL_WRITE_USN_CLOSE_RECORD                            Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 59, METHOD_NEITHER, FILE_ANY_ACCESS)
    FSCTL_EXTEND_VOLUME                                     Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 60, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_QUERY_USN_JOURNAL                                 Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 61, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_DELETE_USN_JOURNAL                                Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 62, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_MARK_HANDLE                                       Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 63, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_SIS_COPYFILE                                      Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 64, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_SIS_LINK_FILES                                    Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 65, METHOD_BUFFERED, FILE_READ_DATA | FILE_WRITE_DATA)
    FSCTL_RECALL_FILE                                       Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 69, METHOD_NEITHER, FILE_ANY_ACCESS)
    FSCTL_READ_FROM_PLEX                                    Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 71, METHOD_OUT_DIRECT, FILE_READ_DATA)
    FSCTL_FILE_PREFETCH                                     Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 72, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)

    FSCTL_MAKE_MEDIA_COMPATIBLE                             Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 76, METHOD_BUFFERED, FILE_WRITE_DATA)
    FSCTL_SET_DEFECT_MANAGEMENT                             Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 77, METHOD_BUFFERED, FILE_WRITE_DATA)
    FSCTL_QUERY_SPARING_INFO                                Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 78, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_QUERY_ON_DISK_VOLUME_INFO                         Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 79, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_SET_VOLUME_COMPRESSION_STATE                      Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 80, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
    FSCTL_TXFS_MODIFY_RM                                    Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 81, METHOD_BUFFERED, FILE_WRITE_DATA)
    FSCTL_TXFS_QUERY_RM_INFORMATION                         Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 82, METHOD_BUFFERED, FILE_READ_DATA)
    FSCTL_TXFS_ROLLFORWARD_REDO                             Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 84, METHOD_BUFFERED, FILE_WRITE_DATA)
    FSCTL_TXFS_ROLLFORWARD_UNDO                             Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 85, METHOD_BUFFERED, FILE_WRITE_DATA)
    FSCTL_TXFS_START_RM                                     Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 86, METHOD_BUFFERED, FILE_WRITE_DATA)
    FSCTL_TXFS_SHUTDOWN_RM                                  Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 87, METHOD_BUFFERED, FILE_WRITE_DATA)
    FSCTL_TXFS_READ_BACKUP_INFORMATION                      Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 88, METHOD_BUFFERED, FILE_READ_DATA)
    FSCTL_TXFS_WRITE_BACKUP_INFORMATION                     Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 89, METHOD_BUFFERED, FILE_WRITE_DATA)
    FSCTL_TXFS_CREATE_SECONDARY_RM                          Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 90, METHOD_BUFFERED, FILE_WRITE_DATA)
    FSCTL_TXFS_GET_METADATA_INFO                            Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 91, METHOD_BUFFERED, FILE_READ_DATA)
    FSCTL_TXFS_GET_TRANSACTED_VERSION                       Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 92, METHOD_BUFFERED, FILE_READ_DATA)
    FSCTL_TXFS_SAVEPOINT_INFORMATION                        Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 94, METHOD_BUFFERED, FILE_WRITE_DATA)
    FSCTL_TXFS_CREATE_MINIVERSION                           Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 95, METHOD_BUFFERED, FILE_WRITE_DATA)
    FSCTL_TXFS_TRANSACTION_ACTIVE                           Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 99, METHOD_BUFFERED, FILE_READ_DATA)
    FSCTL_SET_ZERO_ON_DEALLOCATION                          Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 101, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
    FSCTL_SET_REPAIR                                        Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 102, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_GET_REPAIR                                        Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 103, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_WAIT_FOR_REPAIR                                   Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 104, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_INITIATE_REPAIR                                   Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 106, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_CSC_INTERNAL                                      Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 107, METHOD_NEITHER, FILE_ANY_ACCESS)
    FSCTL_SHRINK_VOLUME                                     Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 108, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
    FSCTL_SET_SHORT_NAME_BEHAVIOR                           Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 109, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_DFSR_SET_GHOST_HANDLE_STATE                       Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 110, METHOD_BUFFERED, FILE_ANY_ACCESS)

    FSCTL_TXFS_LIST_TRANSACTION_LOCKED_FILES                Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 120, METHOD_BUFFERED, FILE_READ_DATA)
    FSCTL_TXFS_LIST_TRANSACTIONS                            Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 121, METHOD_BUFFERED, FILE_READ_DATA)
    FSCTL_QUERY_PAGEFILE_ENCRYPTION                         Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 122, METHOD_BUFFERED, FILE_ANY_ACCESS)

    FSCTL_RESET_VOLUME_ALLOCATION_HINTS                     Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 123, METHOD_BUFFERED, FILE_ANY_ACCESS)

    FSCTL_QUERY_DEPENDENT_VOLUME                            Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 124, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_SD_GLOBAL_CHANGE                                  Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 125, METHOD_BUFFERED, FILE_ANY_ACCESS)

    FSCTL_TXFS_READ_BACKUP_INFORMATION2                     Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 126, METHOD_BUFFERED, FILE_ANY_ACCESS)

    FSCTL_LOOKUP_STREAM_FROM_CLUSTER                        Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 127, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_TXFS_WRITE_BACKUP_INFORMATION2                    Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 128, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_FILE_TYPE_NOTIFICATION                            Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 129, METHOD_BUFFERED, FILE_ANY_ACCESS)

    FSCTL_GET_BOOT_AREA_INFO                                Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 140, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_GET_RETRIEVAL_POINTER_BASE                        Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 141, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_SET_PERSISTENT_VOLUME_STATE                       Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 142, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_QUERY_PERSISTENT_VOLUME_STATE                     Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 143, METHOD_BUFFERED, FILE_ANY_ACCESS)

    FSCTL_REQUEST_OPLOCK                                    Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 144, METHOD_BUFFERED, FILE_ANY_ACCESS)

    FSCTL_CSV_TUNNEL_REQUEST                                Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 145, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_IS_CSV_FILE                                       Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 146, METHOD_BUFFERED, FILE_ANY_ACCESS)

    FSCTL_QUERY_FILE_SYSTEM_RECOGNITION                     Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 147, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_CSV_GET_VOLUME_PATH_NAME                          Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 148, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_CSV_GET_VOLUME_NAME_FOR_VOLUME_MOUNT_POINT        Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 149, METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_CSV_GET_VOLUME_PATH_NAMES_FOR_VOLUME_NAME         Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 150,  METHOD_BUFFERED, FILE_ANY_ACCESS)
    FSCTL_IS_FILE_ON_CSV_VOLUME                             Equ         CTL_CODE(FILE_DEVICE_FILE_SYSTEM, 151,  METHOD_BUFFERED, FILE_ANY_ACCESS)

    FSCTL_MARK_AS_SYSTEM_HIVE                               Equ         FSCTL_SET_BOOTLOADER_ACCESSED

    CSV_NAMESPACE_INFO Struct
        Version                                             DD
        DeviceNumber                                        DD
        StartingOffset                                      LARGE_INTEGER
        SectorSize                                          DD
    EndS

    CSV_NAMESPACE_INFO_V1                                   Equ         (SizeOf CSV_NAMESPACE_INFO)
    CSV_INVALID_DEVICE_NUMBER                               Equ         0FFFFFFFFH

    PATHNAME_BUFFER Struct
        PathNameLength                                      DD
        Name                                                DW          1 Dup ?
    EndS

    FSCTL_QUERY_FAT_BPB_BUFFER Struct
        First0x24BytesOfBootSector                          DB          24H Dup ?
    EndS

    NTFS_VOLUME_DATA_BUFFER Struct
        VolumeSerialNumber                                  LARGE_INTEGER
        NumberSectors                                       LARGE_INTEGER
        TotalClusters                                       LARGE_INTEGER
        FreeClusters                                        LARGE_INTEGER
        TotalReserved                                       LARGE_INTEGER
        BytesPerSector                                      DD
        BytesPerCluster                                     DD
        BytesPerFileRecordSegment                           DD
        ClustersPerFileRecordSegment                        DD
        MftValidDataLength                                  LARGE_INTEGER
        MftStartLcn                                         LARGE_INTEGER
        Mft2StartLcn                                        LARGE_INTEGER
        MftZoneStart                                        LARGE_INTEGER
        MftZoneEnd                                          LARGE_INTEGER
    EndS

    NTFS_EXTENDED_VOLUME_DATA Struct
        ByteCount                                           DD
        MajorVersion                                        DW
        MinorVersion                                        DW
    EndS

    STARTING_LCN_INPUT_BUFFER Struct
        StartingLcn                                         LARGE_INTEGER
    EndS

    VOLUME_BITMAP_BUFFER Struct
        StartingLcn                                         LARGE_INTEGER
        BitmapSize                                          LARGE_INTEGER
        Buffer                                              DB          1 Dup ?
    EndS

    STARTING_VCN_INPUT_BUFFER Struct
        StartingVcn                                         LARGE_INTEGER
    EndS

    NTFS_FILE_RECORD_INPUT_BUFFER Struct
        FileReferenceNumber                                 LARGE_INTEGER
    EndS

    NTFS_FILE_RECORD_OUTPUT_BUFFER Struct
        FileReferenceNumber                                 LARGE_INTEGER
        FileRecordLength                                    DD
        FileRecordBuffer                                    DB          1 Dup ?
    EndS

    MOVE_FILE_DATA Struct
        FileHandle                                          DD
        StartingVcn                                         LARGE_INTEGER
        StartingLcn                                         LARGE_INTEGER
        ClusterCount                                        DD
    EndS

    MOVE_FILE_RECORD_DATA Struct
        FileHandle                                          DD
        SourceFileRecord                                    LARGE_INTEGER
        TargetFileRecord                                    LARGE_INTEGER
    EndS

    MOVE_FILE_DATA32 Struct
        FileHandle                                          DD
        StartingVcn                                         LARGE_INTEGER
        StartingLcn                                         LARGE_INTEGER
        ClusterCount                                        DD
    EndS

    FIND_BY_SID_DATA Struct
        Restart                                             DD
        Sid                                                 SID
    EndS

    FIND_BY_SID_OUTPUT Struct
        NextEntryOffset                                     DD
        FileIndex                                           DD
        FileNameLength                                      DD
        FileName                                            DW          1 Dup ?
    EndS

    MFT_ENUM_DATA Struct
        StartFileReferenceNumber                            DD
        LowUsn                                              DQ
        HighUsn                                             DQ
    EndS

    CREATE_USN_JOURNAL_DATA Struct
        MaximumSize                                         DQ
        AllocationDelta                                     DQ
    EndS

    READ_USN_JOURNAL_DATA Struct
        StartUsn                                            DQ
        ReasonMask                                          DD
        ReturnOnlyOnClose                                   DD
        Timeout                                             DQ
        BytesToWaitFor                                      DQ
        UsnJournalID                                        DQ
    EndS

    USN_RECORD Struct
        RecordLength                                        DD
        MajorVersion                                        DW
        MinorVersion                                        DW
        FileReferenceNumber                                 DQ
        ParentFileReferenceNumber                           DQ
        Usn                                                 DQ
        TimeStamp                                           LARGE_INTEGER
        Reason                                              DD
        SourceInfo                                          DD
        SecurityId                                          DD
        FileAttributes                                      DD
        FileNameLength                                      DW
        FileNameOffset                                      DW
        FileName                                            DW          1 Dup ?
    EndS

    USN_PAGE_SIZE                                           Equ         (1000H)

    USN_REASON_DATA_OVERWRITE                               Equ         (00000001H)
    USN_REASON_DATA_EXTEND                                  Equ         (00000002H)
    USN_REASON_DATA_TRUNCATION                              Equ         (00000004H)
    USN_REASON_NAMED_DATA_OVERWRITE                         Equ         (00000010H)
    USN_REASON_NAMED_DATA_EXTEND                            Equ         (00000020H)
    USN_REASON_NAMED_DATA_TRUNCATION                        Equ         (00000040H)
    USN_REASON_FILE_CREATE                                  Equ         (00000100H)
    USN_REASON_FILE_DELETE                                  Equ         (00000200H)
    USN_REASON_EA_CHANGE                                    Equ         (00000400H)
    USN_REASON_SECURITY_CHANGE                              Equ         (00000800H)
    USN_REASON_RENAME_OLD_NAME                              Equ         (00001000H)
    USN_REASON_RENAME_NEW_NAME                              Equ         (00002000H)
    USN_REASON_INDEXABLE_CHANGE                             Equ         (00004000H)
    USN_REASON_BASIC_INFO_CHANGE                            Equ         (00008000H)
    USN_REASON_HARD_LINK_CHANGE                             Equ         (00010000H)
    USN_REASON_COMPRESSION_CHANGE                           Equ         (00020000H)
    USN_REASON_ENCRYPTION_CHANGE                            Equ         (00040000H)
    USN_REASON_OBJECT_ID_CHANGE                             Equ         (00080000H)
    USN_REASON_REPARSE_POINT_CHANGE                         Equ         (00100000H)
    USN_REASON_STREAM_CHANGE                                Equ         (00200000H)
    USN_REASON_TRANSACTED_CHANGE                            Equ         (00400000H)
    USN_REASON_CLOSE                                        Equ         (80000000H)

    USN_JOURNAL_DATA Struct
        UsnJournalID                                        DQ
        FirstUsn                                            DQ
        NextUsn                                             DQ
        LowestValidUsn                                      DQ
        MaxUsn                                              DQ
        MaximumSize                                         DQ
        AllocationDelta                                     DQ
    EndS

    DELETE_USN_JOURNAL_DATA Struct
        UsnJournalID                                        DQ
        DeleteFlags                                         DD
    EndS

    USN_DELETE_FLAG_DELETE                                  Equ         (00000001H)
    USN_DELETE_FLAG_NOTIFY                                  Equ         (00000002H)

    USN_DELETE_VALID_FLAGS                                  Equ         (00000003H)

    MARK_HANDLE_INFO Struct
        UsnSourceInfo                                       DD
        VolumeHandle                                        DD
        HandleInfo                                          DD
    EndS

    MARK_HANDLE_INFO32 Struct
        UsnSourceInfo                                       DD
        VolumeHandle                                        DD
        HandleInfo                                          DD
    EndS

    USN_SOURCE_DATA_MANAGEMENT                              Equ         (00000001H)
    USN_SOURCE_AUXILIARY_DATA                               Equ         (00000002H)
    USN_SOURCE_REPLICATION_MANAGEMENT                       Equ         (00000004H)

    MARK_HANDLE_PROTECT_CLUSTERS                            Equ         (00000001H)
    MARK_HANDLE_TXF_SYSTEM_LOG                              Equ         (00000004H)
    MARK_HANDLE_NOT_TXF_SYSTEM_LOG                          Equ         (00000008H)

    MARK_HANDLE_REALTIME                                    Equ         (00000020H)
    MARK_HANDLE_NOT_REALTIME                                Equ         (00000040H)

    NO_8DOT3_NAME_PRESENT                                   Equ         (00000001H)
    REMOVED_8DOT3_NAME                                      Equ         (00000002H)

    PERSISTENT_VOLUME_STATE_SHORT_NAME_CREATION_DISABLED    Equ         (00000001H)

    BULK_SECURITY_TEST_DATA Struct
        DesiredAccess                                       DD
        SecurityIds                                         DD          1 Dup ?
    EndS

    VOLUME_IS_DIRTY                                         Equ         (00000001H)
    VOLUME_UPGRADE_SCHEDULED                                Equ         (00000002H)
    VOLUME_SESSION_OPEN                                     Equ         (00000004H)

    FILE_PREFETCH Struct
        Type                                                DD
        Count                                               DD
        _Prefetch                                           DQ          1 Dup ?    ;Prefetch
    EndS

    FILE_PREFETCH_EX Struct
        Type                                                DD
        Count                                               DD
        Context                                             DD
        _Prefetch                                           DQ          1 Dup ?    ;Prefetch
    EndS

    FILE_PREFETCH_TYPE_FOR_CREATE                           Equ         01H
    FILE_PREFETCH_TYPE_FOR_DIRENUM                          Equ         02H
    FILE_PREFETCH_TYPE_FOR_CREATE_EX                        Equ         03H
    FILE_PREFETCH_TYPE_FOR_DIRENUM_EX                       Equ         04H

    FILE_PREFETCH_TYPE_MAX                                  Equ         04H

    FILESYSTEM_STATISTICS Struct
        _FileSystemType                                     DW  ;FileSystemType
        Version                                             DW
        SizeOfCompleteStructure                             DD
        UserFileReads                                       DD
        UserFileReadBytes                                   DD
        UserDiskReads                                       DD
        UserFileWrites                                      DD
        UserFileWriteBytes                                  DD
        UserDiskWrites                                      DD
        MetaDataReads                                       DD
        MetaDataReadBytes                                   DD
        MetaDataDiskReads                                   DD
        MetaDataWrites                                      DD
        MetaDataWriteBytes                                  DD
        MetaDataDiskWrites                                  DD
    EndS

    FILESYSTEM_STATISTICS_TYPE_NTFS                         Equ         1
    FILESYSTEM_STATISTICS_TYPE_FAT                          Equ         2
    FILESYSTEM_STATISTICS_TYPE_EXFAT                        Equ         3

    FAT_STATISTICS Struct
        CreateHits                                          DD
        SuccessfulCreates                                   DD
        FailedCreates                                       DD
        NonCachedReads                                      DD
        NonCachedReadBytes                                  DD
        NonCachedWrites                                     DD
        NonCachedWriteBytes                                 DD
        NonCachedDiskReads                                  DD
        NonCachedDiskWrites                                 DD
    EndS

    EXFAT_STATISTICS Struct
        CreateHits                                          DD
        SuccessfulCreates                                   DD
        FailedCreates                                       DD
        NonCachedReads                                      DD
        NonCachedReadBytes                                  DD
        NonCachedWrites                                     DD
        NonCachedWriteBytes                                 DD
        NonCachedDiskReads                                  DD
        NonCachedDiskWrites                                 DD
    EndS

    NTFS_STATISTICS Struct
        LogFileFullExceptions                               DD
        OtherExceptions                                     DD
        MftReads                                            DD
        MftReadBytes                                        DD
        MftWrites                                           DD
        MftWriteBytes                                       DD
        MftWritesUserLevel Struct
            Write                                           DW
            Create                                          DW
            SetInfo                                         DW
            Flush                                           DW
        EndS
        MftWritesFlushForLogFileFull                        DW
        MftWritesLazyWriter                                 DW
        MftWritesUserRequest                                DW
        Mft2Writes                                          DD
        Mft2WriteBytes                                      DD
        Mft2WritesUserLevel Struct
            Write                                           DW
            Create                                          DW
            SetInfo                                         DW
            Flush                                           DW
        EndS
        Mft2WritesFlushForLogFileFull                       DW
        Mft2WritesLazyWriter                                DW
        Mft2WritesUserRequest                               DW
        RootIndexReads                                      DD
        RootIndexReadBytes                                  DD
        RootIndexWrites                                     DD
        RootIndexWriteBytes                                 DD
        BitmapReads                                         DD
        BitmapReadBytes                                     DD
        BitmapWrites                                        DD
        BitmapWriteBytes                                    DD
        BitmapWritesFlushForLogFileFull                     DW
        BitmapWritesLazyWriter                              DW
        BitmapWritesUserRequest                             DW
        BitmapWritesUserLevel Struct
            Write                                           DW
            Create                                          DW
            SetInfo                                         DW
        EndS
        MftBitmapReads                                      DD
        MftBitmapReadBytes                                  DD
        MftBitmapWrites                                     DD
        MftBitmapWriteBytes                                 DD
        MftBitmapWritesFlushForLogFileFull                  DW
        MftBitmapWritesLazyWriter                           DW
        MftBitmapWritesUserRequest                          DW
        MftBitmapWritesUserLevel Struct
            Write                                           DW
            Create                                          DW
            SetInfo                                         DW
            Flush                                           DW
        EndS
        UserIndexReads                                      DD
        UserIndexReadBytes                                  DD
        UserIndexWrites                                     DD
        UserIndexWriteBytes                                 DD
        LogFileReads                                        DD
        LogFileReadBytes                                    DD
        LogFileWrites                                       DD
        LogFileWriteBytes                                   DD
        Allocate Struct
            Calls                                           DD
            Clusters                                        DD
            Hints                                           DD
            RunsReturned                                    DD
            HintsHonored                                    DD
            HintsClusters                                   DD
            Cache                                           DD
            CacheClusters                                   DD
            CacheMiss                                       DD
            CacheMissClusters                               DD
        EndS
    EndS

    FILE_OBJECTID_BUFFER Struct
        ObjectId                                            DB          16 Dup ?
        DUMMYUNIONNAME Union
            DUMMYSTRUCTNAME Struct
                BirthVolumeId                               DB          16 Dup ?
                BirthObjectId                               DB          16 Dup ?
                DomainId                                    DB          16 Dup ?
            EndS
            ExtendedInfo                                    DB          48 Dup ?
        EndUnion
    EndS

    FILE_SET_SPARSE_BUFFER Struct
        SetSparse                                           DB
    EndS

    FILE_ZERO_DATA_INFORMATION Struct
        FileOffset                                          LARGE_INTEGER
        BeyondFinalZero                                     LARGE_INTEGER
    EndS

    FILE_ALLOCATED_RANGE_BUFFER Struct
        FileOffset                                          LARGE_INTEGER
        Length                                              LARGE_INTEGER
    EndS

    ENCRYPTION_BUFFER Struct
        EncryptionOperation                                 DD
        Private                                             DB          1 Dup ?
    EndS

    FILE_SET_ENCRYPTION                                     Equ         00000001H
    FILE_CLEAR_ENCRYPTION                                   Equ         00000002H
    STREAM_SET_ENCRYPTION                                   Equ         00000003H
    STREAM_CLEAR_ENCRYPTION                                 Equ         00000004H

    MAXIMUM_ENCRYPTION_VALUE                                Equ         00000004H

    DECRYPTION_STATUS_BUFFER Struct
        NoEncryptedStreams                                  DB
    EndS

    ENCRYPTION_FORMAT_DEFAULT                               Equ         (01H)

    COMPRESSION_FORMAT_SPARSE                               Equ         (4000H)

    REQUEST_RAW_ENCRYPTED_DATA Struct
        FileOffset                                          DQ
        Length                                              DD
    EndS

    ENCRYPTED_DATA_INFO Struct
        StartingFileOffset                                  DQ
        OutputBufferOffset                                  DD
        BytesWithinFileSize                                 DD
        BytesWithinValidDataLength                          DD
        CompressionFormat                                   DW
        DataUnitShift                                       DB
        ChunkShift                                          DB
        ClusterShift                                        DB
        EncryptionFormat                                    DB
        NumberOfDataBlocks                                  DW
        DataBlockSize                                       DD          ANYSIZE_ARRAY Dup ?
    EndS

    PLEX_READ_DATA_REQUEST Struct
        ByteOffset                                          LARGE_INTEGER
        ByteLength                                          DD
        PlexNumber                                          DD
    EndS

    SI_COPYFILE Struct
        SourceFileNameLength                                DD
        DestinationFileNameLength                           DD
        Flags                                               DD
        FileNameBuffer                                      DW          1 Dup ?
    EndS

    COPYFILE_SIS_LINK                                       Equ         0001H
    COPYFILE_SIS_REPLACE                                    Equ         0002H
    COPYFILE_SIS_FLAGS                                      Equ         0003H

    FILE_MAKE_COMPATIBLE_BUFFER Struct
        CloseDisc                                           DB
    EndS

    FILE_SET_DEFECT_MGMT_BUFFER Struct
        Disable                                             DB
    EndS

    FILE_QUERY_SPARING_BUFFER Struct
        SparingUnitBytes                                    DD
        SoftwareSparing                                     DB
        TotalSpareBlocks                                    DD
        FreeSpareBlocks                                     DD
    EndS

    FILE_QUERY_ON_DISK_VOL_INFO_BUFFER Struct
        DirectoryCount                                      LARGE_INTEGER
        FileCount                                           LARGE_INTEGER
        FsFormatMajVersion                                  DW
        FsFormatMinVersion                                  DW
        FsFormatName                                        DW          12 Dup ?
        FormatTime                                          LARGE_INTEGER
        LastUpdateTime                                      LARGE_INTEGER
        CopyrightInfo                                       DW          34 Dup ?
        AbstractInfo                                        DW          34 Dup ?
        FormattingImplementationInfo                        DW          34 Dup ?
        LastModifyingImplementationInfo                     DW          34 Dup ?
    EndS

    SET_REPAIR_ENABLED                                      Equ         (00000001H)
    SET_REPAIR_VOLUME_BITMAP_SCAN                           Equ         (00000002H)
    SET_REPAIR_DELETE_CROSSLINK                             Equ         (00000004H)
    SET_REPAIR_WARN_ABOUT_DATA_LOSS                         Equ         (00000008H)
    SET_REPAIR_DISABLED_AND_BUGCHECK_ON_CORRUPT             Equ         (00000010H)
    SET_REPAIR_VALID_MASK                                   Equ         (0000001FH)

    ;SHRINK_VOLUME_REQUEST_TYPES Enumeration
    ShrinkPrepare                                           Equ         1
    ShrinkCommit                                            Equ         2
    ShrinkAbort                                             Equ         3

    SHRINK_VOLUME_INFORMATION Struct
        ShrinkRequestType                                   DD
        Flags                                               DQ
        NewNumberOfSectors                                  DQ
    EndS

    TXFS_RM_FLAG_LOGGING_MODE                               Equ         00000001H
    TXFS_RM_FLAG_RENAME_RM                                  Equ         00000002H
    TXFS_RM_FLAG_LOG_CONTAINER_COUNT_MAX                    Equ         00000004H
    TXFS_RM_FLAG_LOG_CONTAINER_COUNT_MIN                    Equ         00000008H
    TXFS_RM_FLAG_LOG_GROWTH_INCREMENT_NUM_CONTAINERS        Equ         00000010H
    TXFS_RM_FLAG_LOG_GROWTH_INCREMENT_PERCENT               Equ         00000020H
    TXFS_RM_FLAG_LOG_AUTO_SHRINK_PERCENTAGE                 Equ         00000040H
    TXFS_RM_FLAG_LOG_NO_CONTAINER_COUNT_MAX                 Equ         00000080H
    TXFS_RM_FLAG_LOG_NO_CONTAINER_COUNT_MIN                 Equ         00000100H
    TXFS_RM_FLAG_GROW_LOG                                   Equ         00000400H
    TXFS_RM_FLAG_SHRINK_LOG                                 Equ         00000800H
    TXFS_RM_FLAG_ENFORCE_MINIMUM_SIZE                       Equ         00001000H
    TXFS_RM_FLAG_PRESERVE_CHANGES                           Equ         00002000H
    TXFS_RM_FLAG_RESET_RM_AT_NEXT_START                     Equ         00004000H
    TXFS_RM_FLAG_DO_NOT_RESET_RM_AT_NEXT_START              Equ         00008000H
    TXFS_RM_FLAG_PREFER_CONSISTENCY                         Equ         00010000H
    TXFS_RM_FLAG_PREFER_AVAILABILITY                        Equ         00020000H

    TXFS_LOGGING_MODE_SIMPLE                                Equ         (0001H)
    TXFS_LOGGING_MODE_FULL                                  Equ         (0002H)

    TXFS_TRANSACTION_STATE_NONE                             Equ         00H
    TXFS_TRANSACTION_STATE_ACTIVE                           Equ         01H
    TXFS_TRANSACTION_STATE_PREPARED                         Equ         02H
    TXFS_TRANSACTION_STATE_NOTACTIVE                        Equ         03H

    TXFS_MODIFY_RM Struct
        Flags                                               DD
        LogContainerCountMax                                DD
        LogContainerCountMin                                DD
        LogContainerCount                                   DD
        LogGrowthIncrement                                  DD
        LogAutoShrinkPercentage                             DD
        Reserved                                            DQ
        LoggingMode                                         DW
    EndS

    TXFS_RM_STATE_NOT_STARTED                               Equ         0
    TXFS_RM_STATE_STARTING                                  Equ         1
    TXFS_RM_STATE_ACTIVE                                    Equ         2
    TXFS_RM_STATE_SHUTTING_DOWN                             Equ         3

    TXFS_QUERY_RM_INFORMATION Struct
        BytesRequired                                       DD
        TailLsn                                             DQ
        CurrentLsn                                          DQ
        ArchiveTailLsn                                      DQ
        LogContainerSize                                    DQ
        HighestVirtualClock                                 LARGE_INTEGER
        LogContainerCount                                   DD
        LogContainerCountMax                                DD
        LogContainerCountMin                                DD
        LogGrowthIncrement                                  DD
        LogAutoShrinkPercentage                             DD
        Flags                                               DD
        LoggingMode                                         DW
        Reserved                                            DW
        RmState                                             DD
        LogCapacity                                         DQ
        LogFree                                             DQ
        TopsSize                                            DQ
        TopsUsed                                            DQ
        TransactionCount                                    DQ
        OnePCCount                                          DQ
        TwoPCCount                                          DQ
        NumberLogFileFull                                   DQ
        OldestTransactionAge                                DQ
        RMName                                              GUID
        TmLogPathOffset                                     DD
    EndS

    TXFS_ROLLFORWARD_REDO_FLAG_USE_LAST_REDO_LSN            Equ         01H
    TXFS_ROLLFORWARD_REDO_FLAG_USE_LAST_VIRTUAL_CLOCK       Equ         02H

    TXFS_ROLLFORWARD_REDO_VALID_FLAGS                       Equ         (TXFS_ROLLFORWARD_REDO_FLAG_USE_LAST_REDO_LSN | TXFS_ROLLFORWARD_REDO_FLAG_USE_LAST_VIRTUAL_CLOCK)

    TXFS_ROLLFORWARD_REDO_INFORMATION Struct
        LastVirtualClock                                    LARGE_INTEGER
        LastRedoLsn                                         DQ
        HighestRecoveryLsn                                  DQ
        Flags                                               DD
    EndS

    TXFS_START_RM_FLAG_LOG_CONTAINER_COUNT_MAX              Equ         00000001H
    TXFS_START_RM_FLAG_LOG_CONTAINER_COUNT_MIN              Equ         00000002H
    TXFS_START_RM_FLAG_LOG_CONTAINER_SIZE                   Equ         00000004H
    TXFS_START_RM_FLAG_LOG_GROWTH_INCREMENT_NUM_CONTAINERS  Equ         00000008H
    TXFS_START_RM_FLAG_LOG_GROWTH_INCREMENT_PERCENT         Equ         00000010H
    TXFS_START_RM_FLAG_LOG_AUTO_SHRINK_PERCENTAGE           Equ         00000020H
    TXFS_START_RM_FLAG_LOG_NO_CONTAINER_COUNT_MAX           Equ         00000040H
    TXFS_START_RM_FLAG_LOG_NO_CONTAINER_COUNT_MIN           Equ         00000080H

    TXFS_START_RM_FLAG_RECOVER_BEST_EFFORT                  Equ         00000200H
    TXFS_START_RM_FLAG_LOGGING_MODE                         Equ         00000400H
    TXFS_START_RM_FLAG_PRESERVE_CHANGES                     Equ         00000800H

    TXFS_START_RM_FLAG_PREFER_CONSISTENCY                   Equ         00001000H
    TXFS_START_RM_FLAG_PREFER_AVAILABILITY                  Equ         00002000H

    TXFS_START_RM_INFORMATION Struct
        Flags                                               DD
        LogContainerSize                                    DQ
        LogContainerCountMin                                DD
        LogContainerCountMax                                DD
        LogGrowthIncrement                                  DD
        LogAutoShrinkPercentage                             DD
        TmLogPathOffset                                     DD
        TmLogPathLength                                     DW
        LoggingMode                                         DW
        LogPathLength                                       DW
        Reserved                                            DW
        LogPath                                             DW          1 Dup ?
    EndS

    TXFS_GET_METADATA_INFO_OUT Struct
        TxfFileId Struct
            LowPart                                         DQ
            HighPart                                        DQ
        EndS
        LockingTransaction                                  GUID
        LastLsn                                             DQ
        TransactionState                                    DD
    EndS

    TXFS_LIST_TRANSACTION_LOCKED_FILES_ENTRY_FLAG_CREATED   Equ         00000001H
    TXFS_LIST_TRANSACTION_LOCKED_FILES_ENTRY_FLAG_DELETED   Equ         00000002H

    TXFS_LIST_TRANSACTION_LOCKED_FILES_ENTRY Struct
        Offset                                              DQ
        NameFlags                                           DD
        FileId                                              DQ
        Reserved1                                           DD
        Reserved2                                           DD
        Reserved3                                           DQ
        FileName                                            DW          1 Dup ?
    EndS

    TXFS_LIST_TRANSACTION_LOCKED_FILES Struct
        KtmTransaction                                      GUID
        NumberOfFiles                                       DQ
        BufferSizeRequired                                  DQ
        Offset                                              DQ
    EndS

    TXFS_LIST_TRANSACTIONS_ENTRY Struct
        TransactionId                                       GUID
        TransactionState                                    DD
        Reserved1                                           DD
        Reserved2                                           DD
        Reserved3                                           DQ
    EndS

    TXFS_LIST_TRANSACTIONS Struct
        NumberOfTransactions                                DQ
        BufferSizeRequired                                  DQ
    EndS

    TXFS_READ_BACKUP_INFORMATION_OUT Struct
        DUMMYUNIONNAME Union
            BufferLength                                    DD
            Buffer                                          DB          1 Dup ?
        EndUnion
    EndS

    TXFS_WRITE_BACKUP_INFORMATION Struct
        Buffer                                              DB          1 Dup ?
    EndS

    TXFS_TRANSACTED_VERSION_NONTRANSACTED                   Equ         0FFFFFFFEH
    TXFS_TRANSACTED_VERSION_UNCOMMITTED                     Equ         0FFFFFFFFH

    TXFS_GET_TRANSACTED_VERSION Struct
        ThisBaseVersion                                     DD
        LatestVersion                                       DD
        ThisMiniVersion                                     DW
        FirstMiniVersion                                    DW
        LatestMiniVersion                                   DW
    EndS

    TXFS_SAVEPOINT_SET                                      Equ         00000001H
    TXFS_SAVEPOINT_ROLLBACK                                 Equ         00000002H
    TXFS_SAVEPOINT_CLEAR                                    Equ         00000004H
    TXFS_SAVEPOINT_CLEAR_ALL                                Equ         00000010H

    TXFS_SAVEPOINT_INFORMATION Struct
        KtmTransaction                                      DD
        ActionCode                                          DD
        SavepointId                                         DD
    EndS

    TXFS_CREATE_MINIVERSION_INFO Struct
        StructureVersion                                    DW
        StructureLength                                     DW
        BaseVersion                                         DD
        MiniVersion                                         DW
    EndS

    TXFS_TRANSACTION_ACTIVE_INFO Struct
        TransactionsActiveAtSnapshot                        DB
    EndS

    RETRIEVAL_POINTER_BASE Struct
        FileAreaOffset                                      LARGE_INTEGER
    EndS

    FILE_FS_PERSISTENT_VOLUME_INFORMATION Struct
        VolumeFlags                                         DD
        FlagMask                                            DD
        Version                                             DD
        Reserved                                            DD
    EndS

    FILE_SYSTEM_RECOGNITION_INFORMATION Struct
        FileSystem                                          DB          9 Dup ?
    EndS

    OPLOCK_LEVEL_CACHE_READ                                 Equ         (00000001H)
    OPLOCK_LEVEL_CACHE_HANDLE                               Equ         (00000002H)
    OPLOCK_LEVEL_CACHE_WRITE                                Equ         (00000004H)

    REQUEST_OPLOCK_INPUT_FLAG_REQUEST                       Equ         (00000001H)
    REQUEST_OPLOCK_INPUT_FLAG_ACK                           Equ         (00000002H)
    REQUEST_OPLOCK_INPUT_FLAG_COMPLETE_ACK_ON_CLOSE         Equ         (00000004H)

    REQUEST_OPLOCK_CURRENT_VERSION                          Equ         1

    REQUEST_OPLOCK_INPUT_BUFFER Struct
        StructureVersion                                    DW
        StructureLength                                     DW
        RequestedOplockLevel                                DD
        Flags                                               DD
    EndS

    REQUEST_OPLOCK_OUTPUT_FLAG_ACK_REQUIRED                 Equ         (00000001H)
    REQUEST_OPLOCK_OUTPUT_FLAG_MODES_PROVIDED               Equ         (00000002H)

    REQUEST_OPLOCK_OUTPUT_BUFFER Struct
        StructureVersion                                    DW
        StructureLength                                     DW
        OriginalOplockLevel                                 DD
        NewOplockLevel                                      DD
        Flags                                               DD
        AccessMode                                          DD
        ShareMode                                           DW
    EndS

    SD_GLOBAL_CHANGE_TYPE_MACHINE_SID                       Equ         1

    SD_CHANGE_MACHINE_SID_INPUT Struct
        CurrentMachineSIDOffset                             DW
        CurrentMachineSIDLength                             DW
        NewMachineSIDOffset                                 DW
        NewMachineSIDLength                                 DW
    EndS

    SD_CHANGE_MACHINE_SID_OUTPUT Struct
        NumSDChangedSuccess                                 DQ
        NumSDChangedFail                                    DQ
        NumSDUnused                                         DQ
        NumSDTotal                                          DQ
        NumMftSDChangedSuccess                              DQ
        NumMftSDChangedFail                                 DQ
        NumMftSDTotal                                       DQ
    EndS

    SD_GLOBAL_CHANGE_INPUT Struct
        Flags                                               DD
        ChangeType                                          DD
        Union
            SdChange                                        SD_CHANGE_MACHINE_SID_INPUT
        EndUnion
    EndS

    SD_GLOBAL_CHANGE_OUTPUT Struct
        Flags                                               DD
        ChangeType                                          DD
        Union
            SdChange                                        SD_CHANGE_MACHINE_SID_OUTPUT
        EndUnion
    EndS

    ENCRYPTED_DATA_INFO_SPARSE_FILE                         Equ         1

    EXTENDED_ENCRYPTED_DATA_INFO Struct
        ExtendedCode                                        DD
        Length                                              DD
        Flags                                               DD
        Reserved                                            DD
    EndS

    LOOKUP_STREAM_FROM_CLUSTER_INPUT Struct
        Flags                                               DD
        NumberOfClusters                                    DD
        Cluster                                             LARGE_INTEGER   1 Dup ?
    EndS

    LOOKUP_STREAM_FROM_CLUSTER_OUTPUT Struct
        _Offset                                             DD  ;Offset
        NumberOfMatches                                     DD
        BufferSizeRequired                                  DD
    EndS

    LOOKUP_STREAM_FROM_CLUSTER_ENTRY_FLAG_PAGE_FILE         Equ         00000001H
    LOOKUP_STREAM_FROM_CLUSTER_ENTRY_FLAG_DENY_DEFRAG_SET   Equ         00000002H
    LOOKUP_STREAM_FROM_CLUSTER_ENTRY_FLAG_FS_SYSTEM_FILE    Equ         00000004H
    LOOKUP_STREAM_FROM_CLUSTER_ENTRY_FLAG_TXF_SYSTEM_FILE   Equ         00000008H

    LOOKUP_STREAM_FROM_CLUSTER_ENTRY_ATTRIBUTE_MASK         Equ         0FF000000H
    LOOKUP_STREAM_FROM_CLUSTER_ENTRY_ATTRIBUTE_DATA         Equ         001000000H
    LOOKUP_STREAM_FROM_CLUSTER_ENTRY_ATTRIBUTE_INDEX        Equ         002000000H
    LOOKUP_STREAM_FROM_CLUSTER_ENTRY_ATTRIBUTE_SYSTEM       Equ         003000000H

    LOOKUP_STREAM_FROM_CLUSTER_ENTRY Struct
        OffsetToNext                                        DD
        Flags                                               DD
        Reserved                                            LARGE_INTEGER
        Cluster                                             LARGE_INTEGER
        FileName                                            DW          1 Dup ?
    EndS

    FILE_TYPE_NOTIFICATION_INPUT Struct
        Flags                                               DD
        NumFileTypeIDs                                      DD
        FileTypeID                                          GUID        1 Dup ?
    EndS

    FILE_TYPE_NOTIFICATION_FLAG_USAGE_BEGIN                 Equ         00000001H
    FILE_TYPE_NOTIFICATION_FLAG_USAGE_END                   Equ         00000002H

    DEFINE_GUID     (ILE_TYPE_NOTIFICATION_GUID_PAGE_FILE,              00D0A64A1H, 038FCH, 4DB8H, 09FH, 0E7H, 03FH, 043H, 052H, 0CDH, 07CH, 05CH)
    DEFINE_GUID     (ILE_TYPE_NOTIFICATION_GUID_HIBERNATION_FILE,       0B7624D64H, 0B9A3H, 4CF8H, 080H, 011H, 05BH, 086H, 0C9H, 040H, 0E7H, 0B7H)
    DEFINE_GUID     (ILE_TYPE_NOTIFICATION_GUID_CRASHDUMP_FILE,         09D453EB7H, 0D2A6H, 4DBDH, 0A2H, 0E3H, 0FBH, 0D0H, 0EDH, 091H, 009H, 0A9H)
#ENDIF

SYMLINK_FLAG_RELATIVE                                       Equ         1

REPARSE_DATA_BUFFER Struct
    ReparseTag                                              DD
    ReparseDataLength                                       DW
    Reserved                                                DW
    DUMMYUNIONNAME Union
        SymbolicLinkReparseBuffer Struct
            SubstituteNameOffset                            DW
            SubstituteNameLength                            DW
            PrintNameOffset                                 DW
            PrintNameLength                                 DW
            Flags                                           DD
            PathBuffer                                      DW          1 Dup ?
        EndS
        MountPointReparseBuffer Struct
            SubstituteNameOffset                            DW
            SubstituteNameLength                            DW
            PrintNameOffset                                 DW
            PrintNameLength                                 DW
            PathBuffer                                      DW          1 Dup ?
        EndS
        GenericReparseBuffer Struct
            DataBuffer                                      DB          1 Dup ?
        EndS
    EndUnion
EndS

REPARSE_GUID_DATA_BUFFER Struct
    ReparseTag                                              DD
    ReparseDataLength                                       DW
    Reserved                                                DW
    ReparseGuid                                             GUID
    GenericReparseBuffer Struct
        DataBuffer                                          DB          1 Dup ?
    EndS
EndS

MAXIMUM_REPARSE_DATA_BUFFER_SIZE                            Equ         (16 * 1024)

IO_REPARSE_TAG_RESERVED_ZERO                                Equ         (0)
IO_REPARSE_TAG_RESERVED_ONE                                 Equ         (1)

IO_REPARSE_TAG_RESERVED_RANGE                               Equ         IO_REPARSE_TAG_RESERVED_ONE

IO_REPARSE_TAG_MOUNT_POINT                                  Equ         (0A0000003H)
IO_REPARSE_TAG_HSM                                          Equ         (0C0000004H)
IO_REPARSE_TAG_DRIVE_EXTENDER                               Equ         (080000005H)
IO_REPARSE_TAG_HSM2                                         Equ         (080000006H)
IO_REPARSE_TAG_SIS                                          Equ         (080000007H)
IO_REPARSE_TAG_WIM                                          Equ         (080000008H)
IO_REPARSE_TAG_CSV                                          Equ         (080000009H)
IO_REPARSE_TAG_DFS                                          Equ         (08000000AH)
IO_REPARSE_TAG_FILTER_MANAGER                               Equ         (08000000BH)
IO_REPARSE_TAG_SYMLINK                                      Equ         (0A000000CH)
IO_REPARSE_TAG_IIS_CACHE                                    Equ         (0A0000010H)
IO_REPARSE_TAG_DFSR                                         Equ         (080000012H)

IO_REPARSE_TAG_IFSTEST_CONGRUENT                            Equ         (00000009H)
IO_REPARSE_TAG_MOONWALK_HSM                                 Equ         (0000000AH)
IO_REPARSE_TAG_TSINGHUA_UNIVERSITY_RESEARCH                 Equ         (0000000BH)
IO_REPARSE_TAG_ARKIVIO                                      Equ         (0000000CH)
IO_REPARSE_TAG_SOLUTIONSOFT                                 Equ         (2000000DH)
IO_REPARSE_TAG_COMMVAULT                                    Equ         (0000000EH)
IO_REPARSE_TAG_OVERTONE                                     Equ         (0000000FH)
IO_REPARSE_TAG_SYMANTEC_HSM2                                Equ         (00000010H)
IO_REPARSE_TAG_ENIGMA_HSM                                   Equ         (00000011H)
IO_REPARSE_TAG_SYMANTEC_HSM                                 Equ         (00000012H)
IO_REPARSE_TAG_INTERCOPE_HSM                                Equ         (00000013H)
IO_REPARSE_TAG_KOM_NETWORKS_HSM                             Equ         (00000014H)
IO_REPARSE_TAG_MEMORY_TECH_HSM                              Equ         (00000015H)
IO_REPARSE_TAG_BRIDGEHEAD_HSM                               Equ         (00000016H)
IO_REPARSE_TAG_OSR_SAMPLE                                   Equ         (20000017H)
IO_REPARSE_TAG_GLOBAL360_HSM                                Equ         (00000018H)
IO_REPARSE_TAG_ALTIRIS_HSM                                  Equ         (00000019H)
IO_REPARSE_TAG_HERMES_HSM                                   Equ         (0000001AH)
IO_REPARSE_TAG_POINTSOFT_HSM                                Equ         (0000001BH)
IO_REPARSE_TAG_GRAU_DATASTORAGE_HSM                         Equ         (0000001CH)
IO_REPARSE_TAG_COMMVAULT_HSM                                Equ         (0000001DH)
IO_REPARSE_TAG_DATASTOR_SIS                                 Equ         (0000001EH)
IO_REPARSE_TAG_EDSI_HSM                                     Equ         (0000001FH)
IO_REPARSE_TAG_HP_HSM                                       Equ         (00000020H)
IO_REPARSE_TAG_SER_HSM                                      Equ         (00000021H)
IO_REPARSE_TAG_DOUBLE_TAKE_HSM                              Equ         (00000022H)
IO_REPARSE_TAG_WISDATA_HSM                                  Equ         (00000023H)
IO_REPARSE_TAG_MIMOSA_HSM                                   Equ         (00000024H)
IO_REPARSE_TAG_HSAG_HSM                                     Equ         (00000025H)
IO_REPARSE_TAG_ADA_HSM                                      Equ         (00000026H)
IO_REPARSE_TAG_AUTN_HSM                                     Equ         (00000027H)
IO_REPARSE_TAG_NEXSAN_HSM                                   Equ         (00000028H)
IO_REPARSE_TAG_DOUBLE_TAKE_SIS                              Equ         (00000029H)
IO_REPARSE_TAG_SONY_HSM                                     Equ         (0000002AH)
IO_REPARSE_TAG_ELTAN_HSM                                    Equ         (0000002BH)
IO_REPARSE_TAG_UTIXO_HSM                                    Equ         (0000002CH)
IO_REPARSE_TAG_QUEST_HSM                                    Equ         (0000002DH)
IO_REPARSE_TAG_DATAGLOBAL_HSM                               Equ         (0000002EH)
IO_REPARSE_TAG_QI_TECH_HSM                                  Equ         (2000002FH)
IO_REPARSE_TAG_DATAFIRST_HSM                                Equ         (00000030H)
IO_REPARSE_TAG_C2CSYSTEMS_HSM                               Equ         (00000031H)

REPARSE_INDEX_KEY Struct
    FileReparseTag                                          DD
    FileId                                                  LARGE_INTEGER
EndS

FSCTL_LMR_GET_LINK_TRACKING_INFORMATION                     Equ         CTL_CODE(FILE_DEVICE_NETWORK_FILE_SYSTEM, 58, METHOD_BUFFERED, FILE_ANY_ACCESS)

FSCTL_LMR_SET_LINK_TRACKING_INFORMATION                     Equ         CTL_CODE(FILE_DEVICE_NETWORK_FILE_SYSTEM, 59, METHOD_BUFFERED, FILE_ANY_ACCESS)

IOCTL_LMR_ARE_FILE_OBJECTS_ON_SAME_SERVER                   Equ         CTL_CODE(FILE_DEVICE_NETWORK_FILE_SYSTEM, 60, METHOD_BUFFERED, FILE_ANY_ACCESS)

FSCTL_PIPE_ASSIGN_EVENT                                     Equ         CTL_CODE(FILE_DEVICE_NAMED_PIPE, 0, METHOD_BUFFERED, FILE_ANY_ACCESS)
FSCTL_PIPE_DISCONNECT                                       Equ         CTL_CODE(FILE_DEVICE_NAMED_PIPE, 1, METHOD_BUFFERED, FILE_ANY_ACCESS)
FSCTL_PIPE_LISTEN                                           Equ         CTL_CODE(FILE_DEVICE_NAMED_PIPE, 2, METHOD_BUFFERED, FILE_ANY_ACCESS)
FSCTL_PIPE_PEEK                                             Equ         CTL_CODE(FILE_DEVICE_NAMED_PIPE, 3, METHOD_BUFFERED, FILE_READ_DATA)
FSCTL_PIPE_QUERY_EVENT                                      Equ         CTL_CODE(FILE_DEVICE_NAMED_PIPE, 4, METHOD_BUFFERED, FILE_ANY_ACCESS)
FSCTL_PIPE_TRANSCEIVE                                       Equ         CTL_CODE(FILE_DEVICE_NAMED_PIPE, 5, METHOD_NEITHER,  FILE_READ_DATA | FILE_WRITE_DATA)
FSCTL_PIPE_WAIT                                             Equ         CTL_CODE(FILE_DEVICE_NAMED_PIPE, 6, METHOD_BUFFERED, FILE_ANY_ACCESS)
FSCTL_PIPE_IMPERSONATE                                      Equ         CTL_CODE(FILE_DEVICE_NAMED_PIPE, 7, METHOD_BUFFERED, FILE_ANY_ACCESS)
FSCTL_PIPE_SET_CLIENT_PROCESS                               Equ         CTL_CODE(FILE_DEVICE_NAMED_PIPE, 8, METHOD_BUFFERED, FILE_ANY_ACCESS)
FSCTL_PIPE_QUERY_CLIENT_PROCESS                             Equ         CTL_CODE(FILE_DEVICE_NAMED_PIPE, 9, METHOD_BUFFERED, FILE_ANY_ACCESS)
FSCTL_PIPE_GET_PIPE_ATTRIBUTE                               Equ         CTL_CODE(FILE_DEVICE_NAMED_PIPE, 10, METHOD_BUFFERED, FILE_ANY_ACCESS)
FSCTL_PIPE_SET_PIPE_ATTRIBUTE                               Equ         CTL_CODE(FILE_DEVICE_NAMED_PIPE, 11, METHOD_BUFFERED, FILE_ANY_ACCESS)
FSCTL_PIPE_GET_CONNECTION_ATTRIBUTE                         Equ         CTL_CODE(FILE_DEVICE_NAMED_PIPE, 12, METHOD_BUFFERED, FILE_ANY_ACCESS)
FSCTL_PIPE_SET_CONNECTION_ATTRIBUTE                         Equ         CTL_CODE(FILE_DEVICE_NAMED_PIPE, 13, METHOD_BUFFERED, FILE_ANY_ACCESS)
FSCTL_PIPE_GET_HANDLE_ATTRIBUTE                             Equ         CTL_CODE(FILE_DEVICE_NAMED_PIPE, 14, METHOD_BUFFERED, FILE_ANY_ACCESS)
FSCTL_PIPE_SET_HANDLE_ATTRIBUTE                             Equ         CTL_CODE(FILE_DEVICE_NAMED_PIPE, 15, METHOD_BUFFERED, FILE_ANY_ACCESS)
FSCTL_PIPE_FLUSH                                            Equ         CTL_CODE(FILE_DEVICE_NAMED_PIPE, 16, METHOD_BUFFERED, FILE_WRITE_DATA)

FSCTL_PIPE_INTERNAL_READ                                    Equ         CTL_CODE(FILE_DEVICE_NAMED_PIPE, 2045, METHOD_BUFFERED, FILE_READ_DATA)
FSCTL_PIPE_INTERNAL_WRITE                                   Equ         CTL_CODE(FILE_DEVICE_NAMED_PIPE, 2046, METHOD_BUFFERED, FILE_WRITE_DATA)
FSCTL_PIPE_INTERNAL_TRANSCEIVE                              Equ         CTL_CODE(FILE_DEVICE_NAMED_PIPE, 2047, METHOD_NEITHER, FILE_READ_DATA | FILE_WRITE_DATA)
FSCTL_PIPE_INTERNAL_READ_OVFLOW                             Equ         CTL_CODE(FILE_DEVICE_NAMED_PIPE, 2048, METHOD_BUFFERED, FILE_READ_DATA)

FILE_PIPE_READ_DATA                                         Equ         00000000H
FILE_PIPE_WRITE_SPACE                                       Equ         00000001H

FILE_PIPE_ASSIGN_EVENT_BUFFER Struct
    EventHandle                                             DD
    KeyValue                                                DD
EndS

FILE_PIPE_PEEK_BUFFER Struct
    NamedPipeState                                          DD
    ReadDataAvailable                                       DD
    NumberOfMessages                                        DD
    MessageLength                                           DD
    Data                                                    DB          1 Dup ?
EndS

FILE_PIPE_EVENT_BUFFER Struct
    NamedPipeState                                          DD
    EntryType                                               DD
    ByteCount                                               DD
    KeyValue                                                DD
    NumberRequests                                          DD
EndS

FILE_PIPE_WAIT_FOR_BUFFER Struct
    Timeout                                                 LARGE_INTEGER
    NameLength                                              DD
    TimeoutSpecified                                        DB
    Name                                                    DW          1 Dup ?
EndS

FILE_PIPE_COMPUTER_NAME_LENGTH                              Equ         15

FSCTL_MAILSLOT_PEEK                                         Equ         CTL_CODE(FILE_DEVICE_MAILSLOT, 0, METHOD_NEITHER, FILE_READ_DATA)

;LINK_TRACKING_INFORMATION_TYPE Enumeration
NtfsLinkTrackingInformation                                 Equ         0
DfsLinkTrackingInformation                                  Equ         1

LINK_TRACKING_INFORMATION Struct
    Type                                                    DD
    VolumeId                                                DB          16 Dup ?
EndS

REMOTE_LINK_TRACKING_INFORMATION Struct
    TargetFileObject                                        DD
    TargetLinkTrackingInformationLength                     DD
    TargetLinkTrackingInformationBuffer                     DB          1 Dup ?
EndS

#IFNDEF _VIRTUAL_STORAGE_TYPE_DEFINED
    _VIRTUAL_STORAGE_TYPE_DEFINED                           Equ         1
    VIRTUAL_STORAGE_TYPE Struct
        DeviceId                                            DD
        VendorId                                            GUID
    EndS
#ENDIF

STORAGE_QUERY_DEPENDENT_VOLUME_REQUEST Struct
    RequestLevel                                            DD
    RequestFlags                                            DD
EndS

QUERY_DEPENDENT_VOLUME_REQUEST_FLAG_HOST_VOLUMES            Equ         01H
QUERY_DEPENDENT_VOLUME_REQUEST_FLAG_GUEST_VOLUMES           Equ         02H

STORAGE_QUERY_DEPENDENT_VOLUME_LEV1_ENTRY Struct
    EntryLength                                             DD
    DependencyTypeFlags                                     DD
    ProviderSpecificFlags                                   DD
    VirtualStorageType                                      VIRTUAL_STORAGE_TYPE
EndS

STORAGE_QUERY_DEPENDENT_VOLUME_LEV2_ENTRY Struct
    EntryLength                                             DD
    DependencyTypeFlags                                     DD
    ProviderSpecificFlags                                   DD
    VirtualStorageType                                      VIRTUAL_STORAGE_TYPE
    AncestorLevel                                           DD
    HostVolumeNameOffset                                    DD
    HostVolumeNameSize                                      DD
    DependentVolumeNameOffset                               DD
    DependentVolumeNameSize                                 DD
    RelativePathOffset                                      DD
    RelativePathSize                                        DD
    DependentDeviceNameOffset                               DD
    DependentDeviceNameSize                                 DD
EndS

STORAGE_QUERY_DEPENDENT_VOLUME_RESPONSE Struct
    ResponseLevel                                           DD
    NumberEntries                                           DD
    Union
        Lev1Depends                                         STORAGE_QUERY_DEPENDENT_VOLUME_LEV1_ENTRY
        Lev2Depends                                         STORAGE_QUERY_DEPENDENT_VOLUME_LEV2_ENTRY
    EndUnion
EndS

;OBJECT_INFORMATION_CLASS Enumeration
ObjectBasicInformation                                      Equ         0
ObjectTypeInformation                                       Equ         2

PUBLIC_OBJECT_BASIC_INFORMATION Struct
    Attributes                                              DD
    GrantedAccess                                           DD
    HandleCount                                             DD
    PointerCount                                            DD
    Reserved                                                DD          10 Dup ?
EndS

SECURITY_CLIENT_CONTEXT Struct
    SecurityQos                                             SECURITY_QUALITY_OF_SERVICE
    ClientToken                                             DD
    DirectlyAccessClientToken                               DB
    DirectAccessEffectiveOnly                               DB
    ServerIsRemote                                          DB
    ClientTokenControl                                      TOKEN_CONTROL
EndS
    
EVENT_INCREMENT                                             Equ         1

IO_NO_INCREMENT                                             Equ         0

IO_CD_ROM_INCREMENT                                         Equ         1

IO_DISK_INCREMENT                                           Equ         1

IO_MAILSLOT_INCREMENT                                       Equ         2

IO_NAMED_PIPE_INCREMENT                                     Equ         2

IO_NETWORK_INCREMENT                                        Equ         2

SEMAPHORE_INCREMENT                                         Equ         1

SYSTEM_PAGE_PRIORITY_BITS                                   Equ         3
SYSTEM_PAGE_PRIORITY_LEVELS                                 Equ         (1 << SYSTEM_PAGE_PRIORITY_BITS)

KAPC_STATE Struct
    ApcListHead                                             LIST_ENTRY  2 Dup ?
    Process                                                 DD
    KernelApcInProgress                                     DB
    KernelApcPending                                        DB
    UserApcPending                                          DB
EndS

KQUEUE Struct
    Header                                                  DISPATCHER_HEADER
    EntryListHead                                           LIST_ENTRY
    CurrentCount                                            DD
    MaximumCount                                            DD
    ThreadListHead                                          LIST_ENTRY
EndS

TOKEN_HAS_TRAVERSE_PRIVILEGE                                Equ         0001H
TOKEN_HAS_BACKUP_PRIVILEGE                                  Equ         0002H
TOKEN_HAS_RESTORE_PRIVILEGE                                 Equ         0004H
TOKEN_WRITE_RESTRICTED                                      Equ         0008H
TOKEN_IS_RESTRICTED                                         Equ         0010H
TOKEN_SESSION_NOT_REFERENCED                                Equ         0020H
TOKEN_SANDBOX_INERT                                         Equ         0040H
TOKEN_HAS_IMPERSONATE_PRIVILEGE                             Equ         0080H
SE_BACKUP_PRIVILEGES_CHECKED                                Equ         0100H
TOKEN_VIRTUALIZE_ALLOWED                                    Equ         0200H
TOKEN_VIRTUALIZE_ENABLED                                    Equ         0400H
TOKEN_IS_FILTERED                                           Equ         0800H
TOKEN_UIACCESS                                              Equ         1000H
TOKEN_NOT_LOW                                               Equ         2000H

SE_EXPORTS Struct
    SeCreateTokenPrivilege                                  LUID
    SeAssignPrimaryTokenPrivilege                           LUID
    SeLockMemoryPrivilege                                   LUID
    SeIncreaseQuotaPrivilege                                LUID
    SeUnsolicitedInputPrivilege                             LUID
    SeTcbPrivilege                                          LUID
    SeSecurityPrivilege                                     LUID
    SeTakeOwnershipPrivilege                                LUID
    SeLoadDriverPrivilege                                   LUID
    SeCreatePagefilePrivilege                               LUID
    SeIncreaseBasePriorityPrivilege                         LUID
    SeSystemProfilePrivilege                                LUID
    SeSystemtimePrivilege                                   LUID
    SeProfileSingleProcessPrivilege                         LUID
    SeCreatePermanentPrivilege                              LUID
    SeBackupPrivilege                                       LUID
    SeRestorePrivilege                                      LUID
    SeShutdownPrivilege                                     LUID
    SeDebugPrivilege                                        LUID
    SeAuditPrivilege                                        LUID
    SeSystemEnvironmentPrivilege                            LUID
    SeChangeNotifyPrivilege                                 LUID
    SeRemoteShutdownPrivilege                               LUID
    SeNullSid                                               DD
    SeWorldSid                                              DD
    SeLocalSid                                              DD
    SeCreatorOwnerSid                                       DD
    SeCreatorGroupSid                                       DD
    SeNtAuthoritySid                                        DD
    SeDialupSid                                             DD
    SeNetworkSid                                            DD
    SeBatchSid                                              DD
    SeInteractiveSid                                        DD
    SeLocalSystemSid                                        DD
    SeAliasAdminsSid                                        DD
    SeAliasUsersSid                                         DD
    SeAliasGuestsSid                                        DD
    SeAliasPowerUsersSid                                    DD
    SeAliasAccountOpsSid                                    DD
    SeAliasSystemOpsSid                                     DD
    SeAliasPrintOpsSid                                      DD
    SeAliasBackupOpsSid                                     DD
    SeAuthenticatedUsersSid                                 DD
    SeRestrictedSid                                         DD
    SeAnonymousLogonSid                                     DD
    SeUndockPrivilege                                       LUID
    SeSyncAgentPrivilege                                    LUID
    SeEnableDelegationPrivilege                             LUID
    SeLocalServiceSid                                       DD
    SeNetworkServiceSid                                     DD
    SeManageVolumePrivilege                                 LUID
    SeImpersonatePrivilege                                  LUID
    SeCreateGlobalPrivilege                                 LUID
    SeTrustedCredManAccessPrivilege                         LUID
    SeRelabelPrivilege                                      LUID
    SeIncreaseWorkingSetPrivilege                           LUID
    SeTimeZonePrivilege                                     LUID
    SeCreateSymbolicLinkPrivilege                           LUID
    SeIUserSid                                              DD
    SeUntrustedMandatorySid                                 DD
    SeLowMandatorySid                                       DD
    SeMediumMandatorySid                                    DD
    SeHighMandatorySid                                      DD
    SeSystemMandatorySid                                    DD
    SeOwnerRightsSid                                        DD
EndS

IO_OPEN_PAGING_FILE                                         Equ         0002H
IO_OPEN_TARGET_DIRECTORY                                    Equ         0004H

IO_STOP_ON_SYMLINK                                          Equ         0008H


IO_MM_PAGING_FILE                                           Equ         0010H

;FS_FILTER_SECTION_SYNC_TYPE Enumeration
SyncTypeOther                                               Equ         0
SyncTypeCreateSection                                       Equ         1

;FS_FILTER_STREAM_FO_NOTIFICATION_TYPE Enumeration
NotifyTypeCreate                                            Equ         0
NotifyTypeRetired                                           Equ         1

FS_FILTER_ACQUIRE_FOR_SECTION_SYNCHRONIZATION               Equ         (-1)
FS_FILTER_RELEASE_FOR_SECTION_SYNCHRONIZATION               Equ         (-2)
FS_FILTER_ACQUIRE_FOR_MOD_WRITE                             Equ         (-3)
FS_FILTER_RELEASE_FOR_MOD_WRITE                             Equ         (-4)
FS_FILTER_ACQUIRE_FOR_CC_FLUSH                              Equ         (-5)
FS_FILTER_RELEASE_FOR_CC_FLUSH                              Equ         (-6)

FS_FILTER_CALLBACKS Struct
    SizeOfFsFilterCallbacks                                 DD
    Reserved                                                DD
    PreAcquireForSectionSynchronization                     DD
    PostAcquireForSectionSynchronization                    DD
    PreReleaseForSectionSynchronization                     DD
    PostReleaseForSectionSynchronization                    DD
    PreAcquireForCcFlush                                    DD
    PostAcquireForCcFlush                                   DD
    PreReleaseForCcFlush                                    DD
    PostReleaseForCcFlush                                   DD
    PreAcquireForModifiedPageWriter                         DD
    PostAcquireForModifiedPageWriter                        DD
    PreReleaseForModifiedPageWriter                         DD
    PostReleaseForModifiedPageWriter                        DD
EndS

DO_VERIFY_VOLUME                                            Equ         00000002H
DO_BUFFERED_IO                                              Equ         00000004H
DO_EXCLUSIVE                                                Equ         00000008H
DO_DIRECT_IO                                                Equ         00000010H
DO_MAP_IO_BUFFER                                            Equ         00000020H
DO_DEVICE_HAS_NAME                                          Equ         00000040H
DO_DEVICE_INITIALIZING                                      Equ         00000080H
DO_SYSTEM_BOOT_PARTITION                                    Equ         00000100H
DO_LONG_TERM_REQUESTS                                       Equ         00000200H
DO_NEVER_LAST_DEVICE                                        Equ         00000400H
DO_SHUTDOWN_REGISTERED                                      Equ         00000800H
DO_BUS_ENUMERATED_DEVICE                                    Equ         00001000H
DO_POWER_PAGABLE                                            Equ         00002000H
DO_POWER_INRUSH                                             Equ         00004000H
DO_LOW_PRIORITY_FILESYSTEM                                  Equ         00010000H
DO_SUPPORTS_TRANSACTIONS                                    Equ         00040000H
DO_FORCE_NEITHER_IO                                         Equ         00080000H
DO_VOLUME_DEVICE_OBJECT                                     Equ         00100000H
DO_SYSTEM_SYSTEM_PARTITION                                  Equ         00200000H
DO_SYSTEM_CRITICAL_PARTITION                                Equ         00400000H
DO_DISALLOW_EXECUTE                                         Equ         00800000H

IO_FILE_OBJECT_NON_PAGED_POOL_CHARGE                        Equ         64
IO_FILE_OBJECT_PAGED_POOL_CHARGE                            Equ         1024

PO_CB_SYSTEM_POWER_POLICY                                   Equ         0
PO_CB_AC_STATUS                                             Equ         1
PO_CB_BUTTON_COLLISION                                      Equ         2
PO_CB_SYSTEM_STATE_LOCK                                     Equ         3
PO_CB_LID_SWITCH_STATE                                      Equ         4
PO_CB_PROCESSOR_POWER_POLICY                                Equ         5

;FAST_IO_POSSIBLE Enumeration
FastIoIsNotPossible                                         Equ         0
FastIoIsPossible                                            Equ         1
FastIoIsQuestionable                                        Equ         2

FSRTL_COMMON_FCB_HEADER Struct
    NodeTypeCode                                            DW
    NodeByteSize                                            DW
    Flags                                                   DB
    IsFastIoPossible                                        DB
    Flags2                                                  DB
    fbits                                                   DB  ;Members Reserved to Version are included here
    Resource                                                DD
    PagingIoResource                                        DD
    AllocationSize                                          LARGE_INTEGER
    FileSize                                                LARGE_INTEGER
    ValidDataLength                                         LARGE_INTEGER
EndS

#IFNDEF FAST_MUTEX
    FAST_MUTEX Struct
        FM_LOCK_BIT                                         Equ         01H
        FM_LOCK_BIT_V                                       Equ         00H
        FM_LOCK_WAITER_WOKEN                                Equ         02H
        FM_LOCK_WAITER_INC                                  Equ         04H
        Count                                               DD
        Owner                                               DD
        Contention                                          DD
        Event                                               KEVENT
        OldIrql                                             DD
    EndS
#ENDIF

FSRTL_ADVANCED_FCB_HEADER Struct
    DUMMYSTRUCTNAME                                         FSRTL_COMMON_FCB_HEADER
    FastMutex                                               DD
    FilterContexts                                          LIST_ENTRY
    PushLock                                                DD
    FileContextSupportPointer                               DD
EndS

FSRTL_FCB_HEADER_V0                                         Equ         (00H)
FSRTL_FCB_HEADER_V1                                         Equ         (01H)

FSRTL_FLAG_FILE_MODIFIED                                    Equ         (01H)
FSRTL_FLAG_FILE_LENGTH_CHANGED                              Equ         (02H)
FSRTL_FLAG_LIMIT_MODIFIED_PAGES                             Equ         (04H)
FSRTL_FLAG_ACQUIRE_MAIN_RSRC_EX                             Equ         (08H)
FSRTL_FLAG_ACQUIRE_MAIN_RSRC_SH                             Equ         (10H)
FSRTL_FLAG_USER_MAPPED_FILE                                 Equ         (20H)
FSRTL_FLAG_ADVANCED_HEADER                                  Equ         (40H)
FSRTL_FLAG_EOF_ADVANCE_ACTIVE                               Equ         (80H)

FSRTL_FLAG2_DO_MODIFIED_WRITE                               Equ         (01H)
FSRTL_FLAG2_SUPPORTS_FILTER_CONTEXTS                        Equ         (02H)
FSRTL_FLAG2_PURGE_WHEN_MAPPED                               Equ         (04H)
FSRTL_FLAG2_IS_PAGING_FILE                                  Equ         (08H)

FSRTL_FSP_TOP_LEVEL_IRP                                     Equ         (01H)
FSRTL_CACHE_TOP_LEVEL_IRP                                   Equ         (02H)
FSRTL_MOD_WRITE_TOP_LEVEL_IRP                               Equ         (03H)
FSRTL_FAST_IO_TOP_LEVEL_IRP                                 Equ         (04H)
FSRTL_NETWORK1_TOP_LEVEL_IRP                                Equ         (05H)
FSRTL_NETWORK2_TOP_LEVEL_IRP                                Equ         (06H)
FSRTL_MAX_TOP_LEVEL_IRP_FLAG                                Equ         (0FFFFH)

EOF_WAIT_BLOCK Struct
    EofWaitLinks                                            LIST_ENTRY
    Event                                                   KEVENT
EndS

FSRTL_AUXILIARY_BUFFER Struct
    Buffer                                                  DD
    Length                                                  DD
    Flags                                                   DD
    Mdl                                                     DD
EndS

FSRTL_AUXILIARY_FLAG_DEALLOCATE                             Equ         00000001H

FILE_LOCK_INFO Struct
    StartingByte                                            LARGE_INTEGER
    Length                                                  LARGE_INTEGER
    ExclusiveLock                                           DB
    Key                                                     DD
    FileObject                                              DD
    ProcessId                                               DD
    EndingByte                                              LARGE_INTEGER
EndS

FILE_LOCK Struct
    CompleteLockIrpRoutine                                  DD
    UnlockRoutine                                           DD
    FastIoIsQuestionable                                    DB
    SpareC                                                  DB          3 Dup ?
    LockInformation                                         DD
    LastReturnedLockInfo                                    FILE_LOCK_INFO
    LastReturnedLock                                        DD
    LockRequestsInProgress                                  DD
EndS

TUNNEL Struct
    Mutex                                                   FAST_MUTEX
    Cache                                                   DD
    TimerQueue                                              LIST_ENTRY
    NumEntries                                              DW
EndS

;FSRTL_COMPARISON_RESULT Enumeration
LessThan                                                    Equ         (-1)
EqualTo                                                     Equ         0
GreaterThan                                                 Equ         1

FSRTL_FAT_LEGAL                                             Equ         01H
FSRTL_HPFS_LEGAL                                            Equ         02H
FSRTL_NTFS_LEGAL                                            Equ         04H
FSRTL_WILD_CHARACTER                                        Equ         08H
FSRTL_OLE_LEGAL                                             Equ         10H
FSRTL_NTFS_STREAM_LEGAL                                     Equ         (FSRTL_NTFS_LEGAL | FSRTL_OLE_LEGAL)

FSRTL_VOLUME_DISMOUNT                                       Equ         1
FSRTL_VOLUME_DISMOUNT_FAILED                                Equ         2
FSRTL_VOLUME_LOCK                                           Equ         3
FSRTL_VOLUME_LOCK_FAILED                                    Equ         4
FSRTL_VOLUME_UNLOCK                                         Equ         5
FSRTL_VOLUME_MOUNT                                          Equ         6
FSRTL_VOLUME_NEEDS_CHKDSK                                   Equ         7
FSRTL_VOLUME_WORM_NEAR_FULL                                 Equ         8
FSRTL_VOLUME_WEARING_OUT                                    Equ         9
FSRTL_VOLUME_FORCED_CLOSED                                  Equ         10
FSRTL_VOLUME_INFO_MAKE_COMPAT                               Equ         11
FSRTL_VOLUME_PREPARING_EJECT                                Equ         12
FSRTL_VOLUME_CHANGE_SIZE                                    Equ         13
FSRTL_VOLUME_BACKGROUND_FORMAT                              Equ         14

FSRTL_UNC_PROVIDER_FLAGS_MAILSLOTS_SUPPORTED                Equ         00000001H
FSRTL_UNC_PROVIDER_FLAGS_CSC_ENABLED                        Equ         00000002H
FSRTL_UNC_PROVIDER_FLAGS_DOMAIN_SVC_AWARE                   Equ         00000004H

FSRTL_MUP_PROVIDER_INFO_LEVEL_1 Struct
    ProviderId                                              DD
EndS

FSRTL_MUP_PROVIDER_INFO_LEVEL_2 Struct
    ProviderId                                              DD
    ProviderName                                            UNICODE_STRING
EndS

FSRTL_PER_FILE_CONTEXT Struct
    Links                                                   LIST_ENTRY
    OwnerId                                                 DD
    InstanceId                                              DD
    FreeCallback                                            DD
EndS

FSRTL_PER_STREAM_CONTEXT Struct
    Links                                                   LIST_ENTRY
    OwnerId                                                 DD
    InstanceId                                              DD
    FreeCallback                                            DD
EndS

FSRTL_PER_FILEOBJECT_CONTEXT Struct
    Links                                                   LIST_ENTRY
    OwnerId                                                 DD
    InstanceId                                              DD
EndS

FSRTL_ALLOCATE_ECPLIST_FLAG_CHARGE_QUOTA                    Equ         00000001H

FSRTL_ALLOCATE_ECP_FLAG_CHARGE_QUOTA                        Equ         00000001H

FSRTL_ALLOCATE_ECP_FLAG_NONPAGED_POOL                       Equ         00000002H

;NETWORK_OPEN_LOCATION_QUALIFIER Enumeration
NetworkOpenLocationAny                                      Equ         0
NetworkOpenLocationRemote                                   Equ         1
NetworkOpenLocationLoopback                                 Equ         2

;NETWORK_OPEN_INTEGRITY_QUALIFIER Enumeration
NetworkOpenIntegrityAny                                     Equ         0
NetworkOpenIntegrityNone                                    Equ         1
NetworkOpenIntegritySigned                                  Equ         2
NetworkOpenIntegrityEncrypted                               Equ         3
NetworkOpenIntegrityMaximum                                 Equ         4

NETWORK_OPEN_ECP_IN_FLAG_DISABLE_HANDLE_COLLAPSING          Equ         01H
NETWORK_OPEN_ECP_IN_FLAG_DISABLE_HANDLE_DURABILITY          Equ         02H
NETWORK_OPEN_ECP_IN_FLAG_FORCE_BUFFERED_SYNCHRONOUS_IO_HACK Equ         80000000H

PREFETCH_OPEN_ECP_CONTEXT Struct
    Context                                                 DD
EndS

DEFINE_GUID     (GUID_ECP_PREFETCH_OPEN,                     0E1777B21H, 0847EH, 04837H, 0AAH, 045H, 064H, 016H, 01DH, 028H, 006H, 055H)

DEFINE_GUID     (GUID_ECP_NFS_OPEN,                          0F326D30CH, 0E5F8H, 04FE7H, 0ABH, 074H, 0F5H, 0A3H, 019H, 06DH, 092H, 0DBH)

NFS_OPEN_ECP_CONTEXT Struct
    ExportAlias                                             DD
    ClientSocketAddress                                     DD
EndS

DEFINE_GUID     (GUID_ECP_SRV_OPEN,                          0BEBFAEBCH, 0AABFH, 0489DH, 09DH, 02CH, 0E9H, 0E3H, 061H, 010H, 028H, 053H)

SRV_OPEN_ECP_CONTEXT Struct
    ShareName                                               DD
    SocketAddress                                           DD
    OplockBlockState                                        DB
    OplockAppState                                          DB
    OplockFinalState                                        DB
EndS

;FSRTL_CHANGE_BACKING_TYPE Enumeration
ChangeDataControlArea                                       Equ         0
ChangeImageControlArea                                      Equ         1
ChangeSharedCacheMap                                        Equ         2

FSRTL_CC_FLUSH_ERROR_FLAG_NO_HARD_ERROR                     Equ         01H
FSRTL_CC_FLUSH_ERROR_FLAG_NO_LOG_ENTRY                      Equ         02H

FSRTL_VIRTDISK_FULLY_ALLOCATED                              Equ         00000001H
FSRTL_VIRTDISK_NO_DRIVE_LETTER                              Equ         00000002H

VACB_MAPPING_GRANULARITY                                    Equ         (40000H)
VACB_OFFSET_SHIFT                                           Equ         (18)

PUBLIC_BCB Struct
    NodeTypeCode                                            DW
    NodeByteSize                                            DW
    MappedLength                                            DD
    MappedFileOffset                                        LARGE_INTEGER
EndS

CC_FILE_SIZES Struct
    AllocationSize                                          LARGE_INTEGER
    FileSize                                                LARGE_INTEGER
    ValidDataLength                                         LARGE_INTEGER
EndS

CACHE_MANAGER_CALLBACKS Struct
    AcquireForLazyWrite                                     DD
    ReleaseFromLazyWrite                                    DD
    AcquireForReadAhead                                     DD
    ReleaseFromReadAhead                                    DD
EndS

CACHE_UNINITIALIZE_EVENT Struct
    Next                                                    DD
    Event                                                   KEVENT
EndS

UNINITIALIZE_CACHE_MAPS                                     Equ         (01H)
DO_NOT_RETRY_PURGE                                          Equ         (02H)
DO_NOT_PURGE_DIRTY_PAGES                                    Equ         (04H)

CC_FLUSH_AND_PURGE_NO_PURGE                                 Equ         (01H)

PIN_WAIT                                                    Equ         (1)
PIN_EXCLUSIVE                                               Equ         (2)
PIN_NO_READ                                                 Equ         (4)
PIN_IF_BCB                                                  Equ         (8)
PIN_CALLER_TRACKS_DIRTY_DATA                                Equ         (32)

PIN_HIGH_PRIORITY                                           Equ         (64)

MAP_WAIT                                                    Equ         (1)
MAP_NO_READ                                                 Equ         (16)
MAP_HIGH_PRIORITY                                           Equ         (64)

#IFNDEF SecHandle
    SecHandle Struct
        dwLower                                             DD
        dwUpper                                             DD
    EndS
#ENDIF

SEC_DELETED_HANDLE                                          Equ         (-2)

#Define                                                     CredHandle  SecHandle
#Define                                                     CtxtHandle  SecHandle

#Define                                                     SECURITY_INTEGER LARGE_INTEGER
#Define                                                     TimeStamp LARGE_INTEGER
#Define                                                     SECURITY_STRING UNICODE_STRING

SECPKG_FLAG_INTEGRITY                                       Equ         00000001H
SECPKG_FLAG_PRIVACY                                         Equ         00000002H
SECPKG_FLAG_TOKEN_ONLY                                      Equ         00000004H
SECPKG_FLAG_DATAGRAM                                        Equ         00000008H
SECPKG_FLAG_CONNECTION                                      Equ         00000010H
SECPKG_FLAG_MULTI_REQUIRED                                  Equ         00000020H
SECPKG_FLAG_CLIENT_ONLY                                     Equ         00000040H
SECPKG_FLAG_EXTENDED_ERROR                                  Equ         00000080H
SECPKG_FLAG_IMPERSONATION                                   Equ         00000100H
SECPKG_FLAG_ACCEPT_WIN32_NAME                               Equ         00000200H
SECPKG_FLAG_STREAM                                          Equ         00000400H
SECPKG_FLAG_NEGOTIABLE                                      Equ         00000800H
SECPKG_FLAG_GSS_COMPATIBLE                                  Equ         00001000H
SECPKG_FLAG_LOGON                                           Equ         00002000H
SECPKG_FLAG_ASCII_BUFFERS                                   Equ         00004000H
SECPKG_FLAG_FRAGMENT                                        Equ         00008000H
SECPKG_FLAG_MUTUAL_AUTH                                     Equ         00010000H
SECPKG_FLAG_DELEGATION                                      Equ         00020000H
SECPKG_FLAG_READONLY_WITH_CHECKSUM                          Equ         00040000H
SECPKG_FLAG_RESTRICTED_TOKENS                               Equ         00080000H
SECPKG_FLAG_NEGO_EXTENDER                                   Equ         00100000H
SECPKG_FLAG_NEGOTIABLE2                                     Equ         00200000H

SECPKG_ID_NONE                                              Equ         0FFFFH

SECBUFFER_VERSION                                           Equ         0

SECBUFFER_EMPTY                                             Equ         0
SECBUFFER_DATA                                              Equ         1
SECBUFFER_TOKEN                                             Equ         2
SECBUFFER_PKG_PARAMS                                        Equ         3
SECBUFFER_MISSING                                           Equ         4
SECBUFFER_EXTRA                                             Equ         5
SECBUFFER_STREAM_TRAILER                                    Equ         6
SECBUFFER_STREAM_HEADER                                     Equ         7
SECBUFFER_NEGOTIATION_INFO                                  Equ         8
SECBUFFER_PADDING                                           Equ         9
SECBUFFER_STREAM                                            Equ         10
SECBUFFER_MECHLIST                                          Equ         11
SECBUFFER_MECHLIST_SIGNATURE                                Equ         12
SECBUFFER_TARGET                                            Equ         13
SECBUFFER_CHANNEL_BINDINGS                                  Equ         14
SECBUFFER_CHANGE_PASS_RESPONSE                              Equ         15
SECBUFFER_TARGET_HOST                                       Equ         16
SECBUFFER_ALERT                                             Equ         17

SECBUFFER_ATTRMASK                                          Equ         0F0000000H
SECBUFFER_READONLY                                          Equ         080000000H
SECBUFFER_READONLY_WITH_CHECKSUM                            Equ         010000000H
SECBUFFER_RESERVED                                          Equ         060000000H

SEC_NEGOTIATION_INFO Struct
    Size                                                    DD
    NameLength                                              DD
    Name                                                    DD
    Reserved                                                DD
EndS

SEC_CHANNEL_BINDINGS Struct
    dwInitiatorAddrType                                     DD
    cbInitiatorLength                                       DD
    dwInitiatorOffset                                       DD
    dwAcceptorAddrType                                      DD
    cbAcceptorLength                                        DD
    dwAcceptorOffset                                        DD
    cbApplicationDataLength                                 DD
    dwApplicationDataOffset                                 DD
EndS

SECURITY_NATIVE_DREP                                        Equ         000000010H
SECURITY_NETWORK_DREP                                       Equ         000000000H

SECPKG_CRED_INBOUND                                         Equ         000000001H
SECPKG_CRED_OUTBOUND                                        Equ         000000002H
SECPKG_CRED_BOTH                                            Equ         000000003H
SECPKG_CRED_DEFAULT                                         Equ         000000004H
SECPKG_CRED_RESERVED                                        Equ         0F0000000H

SECPKG_CRED_AUTOLOGON_RESTRICTED                            Equ         00000010H
SECPKG_CRED_PROCESS_POLICY_ONLY                             Equ         00000020H

ISC_REQ_DELEGATE                                            Equ         00000001H
ISC_REQ_MUTUAL_AUTH                                         Equ         00000002H
ISC_REQ_REPLAY_DETECT                                       Equ         00000004H
ISC_REQ_SEQUENCE_DETECT                                     Equ         00000008H
ISC_REQ_CONFIDENTIALITY                                     Equ         00000010H
ISC_REQ_USE_SESSION_KEY                                     Equ         00000020H
ISC_REQ_PROMPT_FOR_CREDS                                    Equ         00000040H
ISC_REQ_USE_SUPPLIED_CREDS                                  Equ         00000080H
ISC_REQ_ALLOCATE_MEMORY                                     Equ         00000100H
ISC_REQ_USE_DCE_STYLE                                       Equ         00000200H
ISC_REQ_DATAGRAM                                            Equ         00000400H
ISC_REQ_CONNECTION                                          Equ         00000800H
ISC_REQ_CALL_LEVEL                                          Equ         00001000H
ISC_REQ_FRAGMENT_SUPPLIED                                   Equ         00002000H
ISC_REQ_EXTENDED_ERROR                                      Equ         00004000H
ISC_REQ_STREAM                                              Equ         00008000H
ISC_REQ_INTEGRITY                                           Equ         00010000H
ISC_REQ_IDENTIFY                                            Equ         00020000H
ISC_REQ_NULL_SESSION                                        Equ         00040000H
ISC_REQ_MANUAL_CRED_VALIDATION                              Equ         00080000H
ISC_REQ_RESERVED1                                           Equ         00100000H
ISC_REQ_FRAGMENT_TO_FIT                                     Equ         00200000H
ISC_REQ_FORWARD_CREDENTIALS                                 Equ         00400000H
ISC_REQ_NO_INTEGRITY                                        Equ         00800000H
ISC_REQ_USE_HTTP_STYLE                                      Equ         01000000H

ISC_RET_DELEGATE                                            Equ         00000001H
ISC_RET_MUTUAL_AUTH                                         Equ         00000002H
ISC_RET_REPLAY_DETECT                                       Equ         00000004H
ISC_RET_SEQUENCE_DETECT                                     Equ         00000008H
ISC_RET_CONFIDENTIALITY                                     Equ         00000010H
ISC_RET_USE_SESSION_KEY                                     Equ         00000020H
ISC_RET_USED_COLLECTED_CREDS                                Equ         00000040H
ISC_RET_USED_SUPPLIED_CREDS                                 Equ         00000080H
ISC_RET_ALLOCATED_MEMORY                                    Equ         00000100H
ISC_RET_USED_DCE_STYLE                                      Equ         00000200H
ISC_RET_DATAGRAM                                            Equ         00000400H
ISC_RET_CONNECTION                                          Equ         00000800H
ISC_RET_INTERMEDIATE_RETURN                                 Equ         00001000H
ISC_RET_CALL_LEVEL                                          Equ         00002000H
ISC_RET_EXTENDED_ERROR                                      Equ         00004000H
ISC_RET_STREAM                                              Equ         00008000H
ISC_RET_INTEGRITY                                           Equ         00010000H
ISC_RET_IDENTIFY                                            Equ         00020000H
ISC_RET_NULL_SESSION                                        Equ         00040000H
ISC_RET_MANUAL_CRED_VALIDATION                              Equ         00080000H
ISC_RET_RESERVED1                                           Equ         00100000H
ISC_RET_FRAGMENT_ONLY                                       Equ         00200000H
ISC_RET_FORWARD_CREDENTIALS                                 Equ         00400000H

ISC_RET_USED_HTTP_STYLE                                     Equ         01000000H
ISC_RET_NO_ADDITIONAL_TOKEN                                 Equ         02000000H
ISC_RET_REAUTHENTICATION                                    Equ         08000000H

ASC_REQ_DELEGATE                                            Equ         00000001H
ASC_REQ_MUTUAL_AUTH                                         Equ         00000002H
ASC_REQ_REPLAY_DETECT                                       Equ         00000004H
ASC_REQ_SEQUENCE_DETECT                                     Equ         00000008H
ASC_REQ_CONFIDENTIALITY                                     Equ         00000010H
ASC_REQ_USE_SESSION_KEY                                     Equ         00000020H
ASC_REQ_ALLOCATE_MEMORY                                     Equ         00000100H
ASC_REQ_USE_DCE_STYLE                                       Equ         00000200H
ASC_REQ_DATAGRAM                                            Equ         00000400H
ASC_REQ_CONNECTION                                          Equ         00000800H
ASC_REQ_CALL_LEVEL                                          Equ         00001000H
ASC_REQ_EXTENDED_ERROR                                      Equ         00008000H
ASC_REQ_STREAM                                              Equ         00010000H
ASC_REQ_INTEGRITY                                           Equ         00020000H
ASC_REQ_LICENSING                                           Equ         00040000H
ASC_REQ_IDENTIFY                                            Equ         00080000H
ASC_REQ_ALLOW_NULL_SESSION                                  Equ         00100000H
ASC_REQ_ALLOW_NON_USER_LOGONS                               Equ         00200000H
ASC_REQ_ALLOW_CONTEXT_REPLAY                                Equ         00400000H
ASC_REQ_FRAGMENT_TO_FIT                                     Equ         00800000H
ASC_REQ_FRAGMENT_SUPPLIED                                   Equ         00002000H
ASC_REQ_NO_TOKEN                                            Equ         01000000H
ASC_REQ_PROXY_BINDINGS                                      Equ         04000000H
ASC_REQ_ALLOW_MISSING_BINDINGS                              Equ         10000000H

ASC_RET_DELEGATE                                            Equ         00000001H
ASC_RET_MUTUAL_AUTH                                         Equ         00000002H
ASC_RET_REPLAY_DETECT                                       Equ         00000004H
ASC_RET_SEQUENCE_DETECT                                     Equ         00000008H
ASC_RET_CONFIDENTIALITY                                     Equ         00000010H
ASC_RET_USE_SESSION_KEY                                     Equ         00000020H
ASC_RET_ALLOCATED_MEMORY                                    Equ         00000100H
ASC_RET_USED_DCE_STYLE                                      Equ         00000200H
ASC_RET_DATAGRAM                                            Equ         00000400H
ASC_RET_CONNECTION                                          Equ         00000800H
ASC_RET_CALL_LEVEL                                          Equ         00002000H
ASC_RET_THIRD_LEG_FAILED                                    Equ         00004000H
ASC_RET_EXTENDED_ERROR                                      Equ         00008000H
ASC_RET_STREAM                                              Equ         00010000H
ASC_RET_INTEGRITY                                           Equ         00020000H
ASC_RET_LICENSING                                           Equ         00040000H
ASC_RET_IDENTIFY                                            Equ         00080000H
ASC_RET_NULL_SESSION                                        Equ         00100000H
ASC_RET_ALLOW_NON_USER_LOGONS                               Equ         00200000H
ASC_RET_ALLOW_CONTEXT_REPLAY                                Equ         00400000H
ASC_RET_FRAGMENT_ONLY                                       Equ         00800000H
ASC_RET_NO_TOKEN                                            Equ         01000000H
ASC_RET_NO_ADDITIONAL_TOKEN                                 Equ         02000000H
ASC_RET_NO_PROXY_BINDINGS                                   Equ         04000000H
ASC_RET_MISSING_BINDINGS                                    Equ         10000000H

SECPKG_CRED_ATTR_NAMES                                      Equ         1
SECPKG_CRED_ATTR_SSI_PROVIDER                               Equ         2

SECPKG_ATTR_SIZES                                           Equ         0
SECPKG_ATTR_NAMES                                           Equ         1
SECPKG_ATTR_LIFESPAN                                        Equ         2
SECPKG_ATTR_DCE_INFO                                        Equ         3
SECPKG_ATTR_STREAM_SIZES                                    Equ         4
SECPKG_ATTR_KEY_INFO                                        Equ         5
SECPKG_ATTR_AUTHORITY                                       Equ         6
SECPKG_ATTR_PROTO_INFO                                      Equ         7
SECPKG_ATTR_PASSWORD_EXPIRY                                 Equ         8
SECPKG_ATTR_SESSION_KEY                                     Equ         9
SECPKG_ATTR_PACKAGE_INFO                                    Equ         10
SECPKG_ATTR_USER_FLAGS                                      Equ         11
SECPKG_ATTR_NEGOTIATION_INFO                                Equ         12
SECPKG_ATTR_NATIVE_NAMES                                    Equ         13
SECPKG_ATTR_FLAGS                                           Equ         14
SECPKG_ATTR_USE_VALIDATED                                   Equ         15
SECPKG_ATTR_CREDENTIAL_NAME                                 Equ         16
SECPKG_ATTR_TARGET_INFORMATION                              Equ         17
SECPKG_ATTR_ACCESS_TOKEN                                    Equ         18
SECPKG_ATTR_TARGET                                          Equ         19
SECPKG_ATTR_AUTHENTICATION_ID                               Equ         20
SECPKG_ATTR_LOGOFF_TIME                                     Equ         21
SECPKG_ATTR_NEGO_KEYS                                       Equ         22
SECPKG_ATTR_PROMPTING_NEEDED                                Equ         24
SECPKG_ATTR_UNIQUE_BINDINGS                                 Equ         25
SECPKG_ATTR_ENDPOINT_BINDINGS                               Equ         26
SECPKG_ATTR_CLIENT_SPECIFIED_TARGET                         Equ         27

SECPKG_ATTR_LAST_CLIENT_TOKEN_STATUS                        Equ         30
SECPKG_ATTR_NEGO_PKG_INFO                                   Equ         31
SECPKG_ATTR_NEGO_STATUS                                     Equ         32
SECPKG_ATTR_CONTEXT_DELETED                                 Equ         33

SECPKG_ATTR_SUBJECT_SECURITY_ATTRIBUTES                     Equ         128

SecPkgContext_SubjectAttributes Struct
    AttributeInfo                                           DD
EndS

SECPKG_ATTR_NEGO_INFO_FLAG_NO_KERBEROS                      Equ         01H
SECPKG_ATTR_NEGO_INFO_FLAG_NO_NTLM                          Equ         02H

;SECPKG_CRED_CLASS Enumeration
SecPkgCredClass_None                                        Equ         0
SecPkgCredClass_Ephemeral                                   Equ         10
SecPkgCredClass_PersistedGeneric                            Equ         20
SecPkgCredClass_PersistedSpecific                           Equ         30
SecPkgCredClass_Explicit                                    Equ         40

SecPkgContext_CredInfo Struct
    CredClass                                               DD
    IsPromptingNeeded                                       DD
EndS

SecPkgContext_NegoPackageInfo Struct
    PackageMask                                             DD
EndS

SecPkgContext_NegoStatus Struct
    LastStatus                                              DD
EndS

SecPkgContext_Sizes Struct
    cbMaxToken                                              DD
    cbMaxSignature                                          DD
    cbBlockSize                                             DD
    cbSecurityTrailer                                       DD
EndS

SecPkgContext_StreamSizes Struct
    cbHeader                                                DD
    cbTrailer                                               DD
    cbMaximumMessage                                        DD
    cBuffers                                                DD
    cbBlockSize                                             DD
EndS

SecPkgContext_NamesW Struct
    sUserName                                               DD
EndS

SecPkgContext_Lifespan Struct
    tsStart                                                 TimeStamp
    tsExpiry                                                TimeStamp
EndS

SecPkgContext_DceInfo Struct
    AuthzSvc                                                DD
    pPac                                                    DD
EndS

SecPkgContext_KeyInfoW Struct
    sSignatureAlgorithmName                                 DD
    sEncryptAlgorithmName                                   DD
    KeySize                                                 DD
    SignatureAlgorithm                                      DD
    EncryptAlgorithm                                        DD
EndS

#Define                                                     SecPkgContext_KeyInfo SecPkgContext_KeyInfoW      

SecPkgContext_AuthorityW Struct
    sAuthorityName                                          DD
EndS

#Define                                                     SecPkgContext_Authority SecPkgContext_AuthorityW        

SecPkgContext_ProtoInfoW Struct
    sProtocolName                                           DD
    majorVersion                                            DD
    minorVersion                                            DD
EndS

#Define                                                     SecPkgContext_ProtoInfo SecPkgContext_ProtoInfoW      

SecPkgContext_PasswordExpiry Struct
    tsPasswordExpires                                       TimeStamp
EndS

SecPkgContext_LogoffTime Struct
    tsLogoffTime                                            TimeStamp
EndS

SecPkgContext_SessionKey Struct
    SessionKeyLength                                        DD
    SessionKey                                              DD
EndS

SecPkgContext_NegoKeys Struct
    KeyType                                                 DD
    KeyLength                                               DW
    KeyValue                                                DD
    VerifyKeyType                                           DD
    VerifyKeyLength                                         DW
    VerifyKeyValue                                          DD
EndS

SecPkgContext_PackageInfoW Struct
    PackageInfo                                             DD
EndS

SecPkgContext_UserFlags Struct
    UserFlags                                               DD
EndS

SecPkgContext_Flags Struct
    Flags                                                   DD
EndS

#Define                                                     SecPkgContext_PackageInfo SecPkgContext_PackageInfoW

SecPkgContext_NegotiationInfoW Struct
    PackageInfo                                             DD
    NegotiationState                                        DD
EndS

#Define                                                     SecPkgContext_NativeNames SecPkgContext_NativeNamesW          

SecPkgContext_CredentialNameW Struct
    CredentialType                                          DD
    sCredentialName                                         DD
EndS

#Define                                                     SecPkgContext_CredentialName SecPkgContext_CredentialNameW          

SECPKG_CONTEXT_EXPORT_RESET_NEW                             Equ         00000001H
SECPKG_CONTEXT_EXPORT_DELETE_OLD                            Equ         00000002H
SECPKG_CONTEXT_EXPORT_TO_KERNEL                             Equ         00000004H

SECURITY_SUPPORT_PROVIDER_INTERFACE_VERSION                 Equ         1   
SECURITY_SUPPORT_PROVIDER_INTERFACE_VERSION_2               Equ         2   
SECURITY_SUPPORT_PROVIDER_INTERFACE_VERSION_3               Equ         3   
SECURITY_SUPPORT_PROVIDER_INTERFACE_VERSION_4               Equ         4   

#IFNDEF _AUTH_IDENTITY_EX2_DEFINED
    _AUTH_IDENTITY_EX2_DEFINED                              Equ         1
    SEC_WINNT_AUTH_IDENTITY_VERSION_2                       Equ         0201H
    SEC_WINNT_AUTH_IDENTITY_EX2 Struct
        Version                                             DD
        cbHeaderLength                                      DW
        cbStructureLength                                   DD
        UserOffset                                          DD
        UserLength                                          DW
        DomainOffset                                        DD
        DomainLength                                        DW
        PackedCredentialsOffset                             DD
        PackedCredentialsLength                             DW
        Flags                                               DD
        PackageListOffset                                   DD
        PackageListLength                                   DW
    EndS
#ENDIF

#IFNDEF _AUTH_IDENTITY_DEFINED
    _AUTH_IDENTITY_DEFINED                                  Equ         1
    SEC_WINNT_AUTH_IDENTITY_ANSI                            Equ         01H
    SEC_WINNT_AUTH_IDENTITY_UNICODE                         Equ         02H
    SEC_WINNT_AUTH_IDENTITY_W Struct
        User                                                DD
        UserLength                                          DD
        Domain                                              DD
        DomainLength                                        DD
        Password                                            DD
        PasswordLength                                      DD
        Flags                                               DD
    EndS
    #Define                                                 SEC_WINNT_AUTH_IDENTITY  SEC_WINNT_AUTH_IDENTITY_W
    #Define                                                 _SEC_WINNT_AUTH_IDENTITY _SEC_WINNT_AUTH_IDENTITY_W
#ENDIF

#IFNDEF SEC_WINNT_AUTH_IDENTITY_VERSION
    SEC_WINNT_AUTH_IDENTITY_VERSION                         Equ         0200H
    SEC_WINNT_AUTH_IDENTITY_EXW Struct
        Version                                             DD
        Length                                              DD
        User                                                DD
        UserLength                                          DD
        Domain                                              DD
        DomainLength                                        DD
        Password                                            DD
        PasswordLength                                      DD
        Flags                                               DD
        PackageList                                         DD
        PackageListLength                                   DD
    EndS
    #Define                                                 SEC_WINNT_AUTH_IDENTITY_EX SEC_WINNT_AUTH_IDENTITY_EXW    
#ENDIF

SEC_WINNT_AUTH_IDENTITY_MARSHALLED                          Equ         04H
SEC_WINNT_AUTH_IDENTITY_ONLY                                Equ         08H

#IFNDEF SECURITY_USER_DATA_DEFINED
    SECURITY_USER_DATA_DEFINED                              Equ         1
    SECURITY_USER_DATA Struct
        UserName                                            SECURITY_STRING
        LogonDomainName                                     SECURITY_STRING
        LogonServer                                         SECURITY_STRING
        pSid                                                DD
    EndS
    UNDERSTANDS_LONG_NAMES                                  Equ         1
    NO_LONG_NAMES                                           Equ         2
#ENDIF

#Define                                                     DD_MUP_DEVICE_NAME L"\Device\Mup"

IOCTL_REDIR_QUERY_PATH                                      Equ         CTL_CODE(FILE_DEVICE_NETWORK_FILE_SYSTEM, 99, METHOD_NEITHER, FILE_ANY_ACCESS)

IOCTL_REDIR_QUERY_PATH_EX                                   Equ         CTL_CODE(FILE_DEVICE_NETWORK_FILE_SYSTEM, 100, METHOD_NEITHER, FILE_ANY_ACCESS)

QUERY_PATH_REQUEST Struct
    PathNameLength                                          DD
    SecurityContext                                         DD
    FilePathName                                            DW          1 Dup ?
EndS

QUERY_PATH_REQUEST_EX Struct
    pSecurityContext                                        DD
    EaLength                                                DD
    pEaBuffer                                               DD
    PathName                                                UNICODE_STRING
    DomainServiceName                                       UNICODE_STRING
    Reserved                                                DD          3 Dup ?
EndS

QUERY_PATH_RESPONSE Struct
    LengthAccepted                                          DD
EndS

WNNC_NET_MSNET                                              Equ         00010000H
WNNC_NET_SMB                                                Equ         00020000H
WNNC_NET_NETWARE                                            Equ         00030000H
WNNC_NET_VINES                                              Equ         00040000H
WNNC_NET_10NET                                              Equ         00050000H
WNNC_NET_LOCUS                                              Equ         00060000H
WNNC_NET_SUN_PC_NFS                                         Equ         00070000H
WNNC_NET_LANSTEP                                            Equ         00080000H
WNNC_NET_9TILES                                             Equ         00090000H
WNNC_NET_LANTASTIC                                          Equ         000A0000H
WNNC_NET_AS400                                              Equ         000B0000H
WNNC_NET_FTP_NFS                                            Equ         000C0000H
WNNC_NET_PATHWORKS                                          Equ         000D0000H
WNNC_NET_LIFENET                                            Equ         000E0000H
WNNC_NET_POWERLAN                                           Equ         000F0000H
WNNC_NET_BWNFS                                              Equ         00100000H
WNNC_NET_COGENT                                             Equ         00110000H
WNNC_NET_FARALLON                                           Equ         00120000H
WNNC_NET_APPLETALK                                          Equ         00130000H
WNNC_NET_INTERGRAPH                                         Equ         00140000H
WNNC_NET_SYMFONET                                           Equ         00150000H
WNNC_NET_CLEARCASE                                          Equ         00160000H
WNNC_NET_FRONTIER                                           Equ         00170000H
WNNC_NET_BMC                                                Equ         00180000H
WNNC_NET_DCE                                                Equ         00190000H
WNNC_NET_AVID                                               Equ         001A0000H
WNNC_NET_DOCUSPACE                                          Equ         001B0000H
WNNC_NET_MANGOSOFT                                          Equ         001C0000H
WNNC_NET_SERNET                                             Equ         001D0000H
WNNC_NET_RIVERFRONT1                                        Equ         001E0000H
WNNC_NET_RIVERFRONT2                                        Equ         001F0000H
WNNC_NET_DECORB                                             Equ         00200000H
WNNC_NET_PROTSTOR                                           Equ         00210000H
WNNC_NET_FJ_REDIR                                           Equ         00220000H
WNNC_NET_DISTINCT                                           Equ         00230000H
WNNC_NET_TWINS                                              Equ         00240000H
WNNC_NET_RDR2SAMPLE                                         Equ         00250000H
WNNC_NET_CSC                                                Equ         00260000H
WNNC_NET_3IN1                                               Equ         00270000H
WNNC_NET_EXTENDNET                                          Equ         00290000H
WNNC_NET_STAC                                               Equ         002A0000H
WNNC_NET_FOXBAT                                             Equ         002B0000H
WNNC_NET_YAHOO                                              Equ         002C0000H
WNNC_NET_EXIFS                                              Equ         002D0000H
WNNC_NET_DAV                                                Equ         002E0000H
WNNC_NET_KNOWARE                                            Equ         002F0000H
WNNC_NET_OBJECT_DIRE                                        Equ         00300000H
WNNC_NET_MASFAX                                             Equ         00310000H
WNNC_NET_HOB_NFS                                            Equ         00320000H
WNNC_NET_SHIVA                                              Equ         00330000H
WNNC_NET_IBMAL                                              Equ         00340000H
WNNC_NET_LOCK                                               Equ         00350000H
WNNC_NET_TERMSRV                                            Equ         00360000H
WNNC_NET_SRT                                                Equ         00370000H
WNNC_NET_QUINCY                                             Equ         00380000H
WNNC_NET_OPENAFS                                            Equ         00390000H
WNNC_NET_AVID1                                              Equ         003A0000H
WNNC_NET_DFS                                                Equ         003B0000H
WNNC_NET_KWNP                                               Equ         003C0000H
WNNC_NET_ZENWORKS                                           Equ         003D0000H
WNNC_NET_DRIVEONWEB                                         Equ         003E0000H
WNNC_NET_VMWARE                                             Equ         003F0000H
WNNC_NET_RSFX                                               Equ         00400000H
WNNC_NET_MFILES                                             Equ         00410000H
WNNC_NET_MS_NFS                                             Equ         00420000H
WNNC_NET_GOOGLE                                             Equ         00430000H

WNNC_CRED_MANAGER                                           Equ         0FFFF0000H

WNNC_NET_LANMAN                                             Equ         WNNC_NET_SMB

VOLSNAPCONTROLTYPE                                          Equ         00000053H
IOCTL_VOLSNAP_FLUSH_AND_HOLD_WRITES                         Equ         CTL_CODE(VOLSNAPCONTROLTYPE, 0, METHOD_BUFFERED, FILE_READ_ACCESS | FILE_WRITE_ACCESS)

#ENDIF ;NTIFS_H
