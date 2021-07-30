;===================================================================;
;                                                                   ;
;     ddkmasm.inc for Easy Code 2.0 Masm 32-bit driver projects     ;
;                        (version 1.0.0)                            ;
;                                                                   ;
;                 Driver Development Kit (32-bit)                   ;
;                                                                   ;
;                  Copyright © Ramon Sala - 2015                    ;
;                                                                   ;
;===================================================================;

IFNDEF DDKMASM_INC
DDKMASM_INC Equ 1

KSYSTEM_TIME Struct
    LowPart                                                 DD          ?
    High1Time                                               DD          ?
    High2Time                                               DD          ?
KSYSTEM_TIME EndS
PKSYSTEM_TIME                                               TypeDef     DWord

KPRIORITY                                                   TypeDef     DWord

IFNDEF KSPIN_LOCK
    KSPIN_LOCK                                              TypeDef     DWord
ENDIF
PKSPIN_LOCK                                                 TypeDef     DWord

KPROCESSOR_MODE                                             TypeDef     Byte

LOCK_QUEUE_WAIT                                             Equ         1
LOCK_QUEUE_WAIT_BIT                                         Equ         0

LOCK_QUEUE_OWNER                                            Equ         2
LOCK_QUEUE_OWNER_BIT                                        Equ         1

;KSPIN_LOCK_QUEUE_NUMBER Enumeration
IFDEF APP_WIN64
    KSPIN_LOCK_QUEUE_NUMBER                                 TypeDef     QWord
    LockQueueUnusedSpare0                                   Equ         0
    LockQueueExpansionLock                                  Equ         1
    LockQueueUnusedSpare2                                   Equ         2
    LockQueueSystemSpaceLock                                Equ         3
    LockQueueVacbLock                                       Equ         4
    LockQueueMasterLock                                     Equ         5
    LockQueueNonPagedPoolLock                               Equ         6
    LockQueueIoCancelLock                                   Equ         7
    LockQueueWorkQueueLock                                  Equ         8
    LockQueueIoVpbLock                                      Equ         9
    LockQueueIoDatabaseLock                                 Equ         10
    LockQueueIoCompletionLock                               Equ         11
    LockQueueNtfsStructLock                                 Equ         12
    LockQueueAfdWorkQueueLock                               Equ         13
    LockQueueBcbLock                                        Equ         14
    LockQueueMmNonPagedPoolLock                             Equ         15
    LockQueueUnusedSpare16                                  Equ         16
    LockQueueMaximumLock                                    Equ         (LockQueueUnusedSpare16 + 1)
ELSE
    KSPIN_LOCK_QUEUE_NUMBER                                 TypeDef     DWord
    LockQueueUnusedSpare0                                   Equ         0
    LockQueueExpansionLock                                  Equ         1
    LockQueueUnusedSpare2                                   Equ         2
    LockQueueSystemSpaceLock                                Equ         3
    LockQueueVacbLock                                       Equ         4
    LockQueueMasterLock                                     Equ         5
    LockQueueNonPagedPoolLock                               Equ         6
    LockQueueIoCancelLock                                   Equ         7
    LockQueueWorkQueueLock                                  Equ         8
    LockQueueIoVpbLock                                      Equ         9
    LockQueueIoDatabaseLock                                 Equ         10
    LockQueueIoCompletionLock                               Equ         11
    LockQueueNtfsStructLock                                 Equ         12
    LockQueueAfdWorkQueueLock                               Equ         13
    LockQueueBcbLock                                        Equ         14
    LockQueueMmNonPagedPoolLock                             Equ         15
    LockQueueUnusedSpare16                                  Equ         16
    LockQueueMaximumLock                                    Equ         (LockQueueUnusedSpare16 + 1)
ENDIF

IFNDEF CLFS_MAX_CONTAINER_INFO
    CLFS_MAX_CONTAINER_INFO                                 Equ         256
ENDIF

PKSPIN_LOCK_QUEUE                                           TypeDef     DWord
KSPIN_LOCK_QUEUE Struct
    Next                                                    PKSPIN_LOCK_QUEUE   ?
    _Lock                                                   PKSPIN_LOCK ?   ;Lock
KSPIN_LOCK_QUEUE EndS

KLOCK_QUEUE_HANDLE Struct
    LockQueue                                               KSPIN_LOCK_QUEUE    <>
    OldIrql                                                 KIRQL       ?
KLOCK_QUEUE_HANDLE EndS
PKLOCK_QUEUE_HANDLE                                         TypeDef     DWord

PKINTERRUPT_ROUTINE                                         TypeDef     DWord

;KPROFILE_SOURCE Enumeration
KPROFILE_SOURCE                                             TypeDef     DWord
ProfileTime                                                 Equ         1
ProfileAlignmentFixup                                       Equ         2
ProfileTotalIssues                                          Equ         3
ProfilePipelineDry                                          Equ         4
ProfileLoadInstructions                                     Equ         5
ProfilePipelineFrozen                                       Equ         6
ProfileBranchInstructions                                   Equ         7
ProfileTotalNonissues                                       Equ         8
ProfileDcacheMisses                                         Equ         9
ProfileIcacheMisses                                         Equ         10
ProfileCacheMisses                                          Equ         11
ProfileBranchMispredictions                                 Equ         12
ProfileStoreInstructions                                    Equ         13
ProfileFpInstructions                                       Equ         14
ProfileIntegerInstructions                                  Equ         15
Profile2Issue                                               Equ         16
Profile3Issue                                               Equ         17
Profile4Issue                                               Equ         18
ProfileSpecialInstructions                                  Equ         19
ProfileTotalCycles                                          Equ         20
ProfileIcacheIssues                                         Equ         21
ProfileDcacheAccesses                                       Equ         22
ProfileMemoryBarrierCycles                                  Equ         23
ProfileLoadLinkedIssues                                     Equ         24
ProfileMaximum                                              Equ         25


M128A Struct
    _Low                                                    DQ          ?   ;Low
    _High                                                   DQ          ?   ;High
M128A EndS
PM128A                                                      TypeDef     DWord

XSAVE_FORMAT Struct
    ControlWord                                             DW          ?
    StatusWord                                              DW          ?
    TagWord                                                 DB          ?
    Reserved1                                               DB          ?
    ErrorOpcode                                             DW          ?
    ErrorOffset                                             DD          ?
    ErrorSelector                                           DW          ?
    Reserved2                                               DW          ?
    DataOffset                                              DD          ?
    DataSelector                                            DW          ?
    Reserved3                                               DW          ?
    MxCsr                                                   DD          ?
    MxCsr_Mask                                              DD          ?
    FloatRegisters                                          M128A       8 Dup(<>)
    IFDEF APP_WIN64
        XmmRegisters                                        M128A       16 Dup(<>)
        Reserved4                                           DB          96 Dup(?)
    ELSE
        XmmRegisters                                        M128A       8 Dup(<>)
        Reserved4                                           DB          192 Dup(?)
        StackControl                                        DD          7 Dup(?)
        Cr0NpxState                                         DD          ?
    ENDIF
XSAVE_FORMAT EndS
PXSAVE_FORMAT                                               TypeDef     DWord

XSAVE_AREA_HEADER Struct
    _Mask                                                   DQ          ?   ;Mask
    Reserved                                                DQ          7 Dup(?)
XSAVE_AREA_HEADER EndS
PXSAVE_AREA_HEADER                                          TypeDef     DWord

XSAVE_AREA Struct
    LegacyState                                             XSAVE_FORMAT    <>
    Header                                                  XSAVE_AREA_HEADER   <>
XSAVE_AREA EndS
PXSAVE_AREA                                                 TypeDef     DWord

XSTATE_CONTEXT Struct
    _Mask                                                   DQ          ?   ;Mask
    _Length                                                 DD          ?   ;Length
    Reserved1                                               DD          ?
    Area                                                    PXSAVE_AREA ?
    IFDEF APP_WIN32
        Reserved2                                           DD          ?
    ENDIF
    Buffer                                                  PVOID       ?
    IFDEF APP_WIN32
        Reserved3                                           DD          ?
    ENDIF
XSTATE_CONTEXT EndS
PXSTATE_CONTEXT                                             TypeDef     DWord

XSAVE_ALIGN                                                 Equ         64
MINIMAL_XSTATE_AREA_LENGTH                                  Equ         SizeOf XSAVE_AREA

CONTEXT_CHUNK Struct
    _Offset                                                 DD          ?   ;Offset
    _Length                                                 DD          ?   ;Length
CONTEXT_CHUNK EndS
PCONTEXT_CHUNK                                              TypeDef     DWord

CONTEXT_EX Struct
    All                                                     CONTEXT_CHUNK   <>
    Legacy                                                  CONTEXT_CHUNK   <>
    XState                                                  CONTEXT_CHUNK   <>
CONTEXT_EX EndS
PCONTEXT_EX                                                 TypeDef     DWord

MAXIMUM_SUPPORTED_EXTENSION                                 Equ         512

PACCESS_TOKEN                                               TypeDef     DWord

PSECURITY_DESCRIPTOR                                        TypeDef     DWord

PSID                                                        TypeDef     DWord

ACCESS_MASK                                                 TypeDef     DWord
PACCESS_MASK                                                TypeDef     DWord

DELETE                                                      Equ         (00010000H)
READ_CONTROL                                                Equ         (00020000H)
WRITE_DAC                                                   Equ         (00040000H)
WRITE_OWNER                                                 Equ         (00080000H)
SYNCHRONIZE                                                 Equ         (00100000H)

STANDARD_RIGHTS_REQUIRED                                    Equ         (000F0000H)

STANDARD_RIGHTS_READ                                        Equ         (READ_CONTROL)
STANDARD_RIGHTS_WRITE                                       Equ         (READ_CONTROL)
STANDARD_RIGHTS_EXECUTE                                     Equ         (READ_CONTROL)

STANDARD_RIGHTS_ALL                                         Equ         (001F0000H)

SPECIFIC_RIGHTS_ALL                                         Equ         (0000FFFFH)

ACCESS_SYSTEM_SECURITY                                      Equ         (01000000H)

MAXIMUM_ALLOWED                                             Equ         (02000000H)

GENERIC_READ                                                Equ         (80000000H)
GENERIC_WRITE                                               Equ         (40000000H)
GENERIC_EXECUTE                                             Equ         (20000000H)
GENERIC_ALL                                                 Equ         (10000000H)

GENERIC_MAPPING Struct
    GenericRead                                             ACCESS_MASK ?
    GenericWrite                                            ACCESS_MASK ?
    GenericExecute                                          ACCESS_MASK ?
    GenericAll                                              ACCESS_MASK ?
GENERIC_MAPPING EndS
PGENERIC_MAPPING                                            TypeDef     DWord

LUID_AND_ATTRIBUTES Struct
    Luid                                                    LUID        <>
    Attributes                                              DD          ?
LUID_AND_ATTRIBUTES EndS
PLUID_AND_ATTRIBUTES                                        TypeDef     DWord

ACL_REVISION                                                Equ         (2)
ACL_REVISION_DS                                             Equ         (4)

ACL_REVISION1                                               Equ         (1)
MIN_ACL_REVISION                                            Equ         ACL_REVISION2
ACL_REVISION2                                               Equ         (2)
ACL_REVISION3                                               Equ         (3)
ACL_REVISION4                                               Equ         (4)
MAX_ACL_REVISION                                            Equ         ACL_REVISION4

IFNDEF ACL
    ACL Struct
        AclRevision                                         DB          ?
        Sbz1                                                DB          ?
        AclSize                                             DW          ?
        AceCount                                            DW          ?
        Sbz2                                                DW          ?
    ACL EndS
    PACL                                                    TypeDef     DWord
ENDIF

SECURITY_DESCRIPTOR_REVISION                                Equ         (1)
SECURITY_DESCRIPTOR_REVISION1                               Equ         (1)

SE_PRIVILEGE_ENABLED_BY_DEFAULT                             Equ         (00000001H)
SE_PRIVILEGE_ENABLED                                        Equ         (00000002H)
SE_PRIVILEGE_REMOVED                                        Equ         (00000004H)
SE_PRIVILEGE_USED_FOR_ACCESS                                Equ         (80000000H)

SE_PRIVILEGE_VALID_ATTRIBUTES                               Equ         (SE_PRIVILEGE_ENABLED_BY_DEFAULT Or SE_PRIVILEGE_ENABLED Or SE_PRIVILEGE_REMOVED Or SE_PRIVILEGE_USED_FOR_ACCESS)

PRIVILEGE_SET_ALL_NECESSARY                                 Equ         (1)

PRIVILEGE_SET Struct
    PrivilegeCount                                          DD          ?
    Control                                                 DD          ?
    Privilege                                               LUID_AND_ATTRIBUTES ANYSIZE_ARRAY Dup(<>)
PRIVILEGE_SET EndS
PPRIVILEGE_SET                                              TypeDef     DWord

SE_MIN_WELL_KNOWN_PRIVILEGE                                 Equ         (2)
SE_CREATE_TOKEN_PRIVILEGE                                   Equ         (2)
SE_ASSIGNPRIMARYTOKEN_PRIVILEGE                             Equ         (3)
SE_LOCK_MEMORY_PRIVILEGE                                    Equ         (4)
SE_INCREASE_QUOTA_PRIVILEGE                                 Equ         (5)

SE_MACHINE_ACCOUNT_PRIVILEGE                                Equ         (6)
SE_TCB_PRIVILEGE                                            Equ         (7)
SE_SECURITY_PRIVILEGE                                       Equ         (8)
SE_TAKE_OWNERSHIP_PRIVILEGE                                 Equ         (9)
SE_LOAD_DRIVER_PRIVILEGE                                    Equ         (10)
SE_SYSTEM_PROFILE_PRIVILEGE                                 Equ         (11)
SE_SYSTEMTIME_PRIVILEGE                                     Equ         (12)
SE_PROF_SINGLE_PROCESS_PRIVILEGE                            Equ         (13)
SE_INC_BASE_PRIORITY_PRIVILEGE                              Equ         (14)
SE_CREATE_PAGEFILE_PRIVILEGE                                Equ         (15)
SE_CREATE_PERMANENT_PRIVILEGE                               Equ         (16)
SE_BACKUP_PRIVILEGE                                         Equ         (17)
SE_RESTORE_PRIVILEGE                                        Equ         (18)
SE_SHUTDOWN_PRIVILEGE                                       Equ         (19)
SE_DEBUG_PRIVILEGE                                          Equ         (20)
SE_AUDIT_PRIVILEGE                                          Equ         (21)
SE_SYSTEM_ENVIRONMENT_PRIVILEGE                             Equ         (22)
SE_CHANGE_NOTIFY_PRIVILEGE                                  Equ         (23)
SE_REMOTE_SHUTDOWN_PRIVILEGE                                Equ         (24)
SE_UNDOCK_PRIVILEGE                                         Equ         (25)
SE_SYNC_AGENT_PRIVILEGE                                     Equ         (26)
SE_ENABLE_DELEGATION_PRIVILEGE                              Equ         (27)
SE_MANAGE_VOLUME_PRIVILEGE                                  Equ         (28)
SE_IMPERSONATE_PRIVILEGE                                    Equ         (29)
SE_CREATE_GLOBAL_PRIVILEGE                                  Equ         (30)
SE_TRUSTED_CREDMAN_ACCESS_PRIVILEGE                         Equ         (31)
SE_RELABEL_PRIVILEGE                                        Equ         (32)
SE_INC_WORKING_SET_PRIVILEGE                                Equ         (33)
SE_TIME_ZONE_PRIVILEGE                                      Equ         (34)
SE_CREATE_SYMBOLIC_LINK_PRIVILEGE                           Equ         (35)
SE_MAX_WELL_KNOWN_PRIVILEGE                                 Equ         (SE_CREATE_SYMBOLIC_LINK_PRIVILEGE)

;SECURITY_IMPERSONATION_LEVEL Enumeration
SECURITY_IMPERSONATION_LEVEL                                TypeDef     DWord
SecurityAnonymous                                           Equ         0
SecurityIdentification                                      Equ         1
SecurityImpersonation                                       Equ         2
SecurityDelegation                                          Equ         3
PSECURITY_IMPERSONATION_LEVEL                               TypeDef     DWord

SECURITY_MAX_IMPERSONATION_LEVEL                            Equ         SecurityDelegation
SECURITY_MIN_IMPERSONATION_LEVEL                            Equ         SecurityAnonymous
DEFAULT_IMPERSONATION_LEVEL                                 Equ         SecurityImpersonation

SECURITY_DYNAMIC_TRACKING                                   Equ         TRUE
SECURITY_STATIC_TRACKING                                    Equ         FALSE

SECURITY_CONTEXT_TRACKING_MODE                              TypeDef     BOOLEAN
PSECURITY_CONTEXT_TRACKING_MODE                             TypeDef     DWord

SECURITY_QUALITY_OF_SERVICE Struct
    _Length                                                 DD          ?   ;Length
    ImpersonationLevel                                      SECURITY_IMPERSONATION_LEVEL    ?
    ContextTrackingMode                                     SECURITY_CONTEXT_TRACKING_MODE  ?
    EffectiveOnly                                           BOOLEAN     ?
SECURITY_QUALITY_OF_SERVICE EndS
PSECURITY_QUALITY_OF_SERVICE                                TypeDef     DWord

SE_IMPERSONATION_STATE Struct
    Token                                                   PACCESS_TOKEN   ?
    CopyOnOpen                                              BOOLEAN     ?
    EffectiveOnly                                           BOOLEAN     ?
    Level                                                   SECURITY_IMPERSONATION_LEVEL    ?
SE_IMPERSONATION_STATE EndS
PSE_IMPERSONATION_STATE                                     TypeDef     DWord

SECURITY_INFORMATION                                        TypeDef     DWord
PSECURITY_INFORMATION                                       TypeDef     DWord

OWNER_SECURITY_INFORMATION                                  Equ         (00000001H)
GROUP_SECURITY_INFORMATION                                  Equ         (00000002H)
DACL_SECURITY_INFORMATION                                   Equ         (00000004H)
SACL_SECURITY_INFORMATION                                   Equ         (00000008H)
LABEL_SECURITY_INFORMATION                                  Equ         (00000010H)

PROTECTED_DACL_SECURITY_INFORMATION                         Equ         (80000000H)
PROTECTED_SACL_SECURITY_INFORMATION                         Equ         (40000000H)
UNPROTECTED_DACL_SECURITY_INFORMATION                       Equ         (20000000H)
UNPROTECTED_SACL_SECURITY_INFORMATION                       Equ         (10000000H)

;SE_ADT_PARAMETER_TYPE Enumeration
SE_ADT_PARAMETER_TYPE                                       TypeDef     DWord
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
PSE_ADT_PARAMETER_TYPE                                      TypeDef     DWord

IFNDEF GUID_DEFINED
    Include guiddef.inc
ENDIF

UOW                                                         TypeDef     GUID
PUOW                                                        TypeDef     DWord
PGUID                                                       TypeDef     DWord
LPCGUID                                                     TypeDef     DWord

SE_ADT_OBJECT_TYPE Struct
    ObjectType                                              GUID        <>
    Flags                                                   DW          ?
    Level                                                   DW          ?
    AccessMask                                              ACCESS_MASK ?
SE_ADT_OBJECT_TYPE EndS
SE_ADT_OBJECT_ONLY                                          Equ         01H
PSE_ADT_OBJECT_TYPE                                         TypeDef     DWord

SE_ADT_PARAMETER_ARRAY_ENTRY Struct
    _Type                                                   SE_ADT_PARAMETER_TYPE   ?   ;Type
    _Length                                                 DD          ?   ;Length
    Data                                                    DD          2 Dup(?)
    Address                                                 PVOID       ?
SE_ADT_PARAMETER_ARRAY_ENTRY EndS
PSE_ADT_PARAMETER_ARRAY_ENTRY                               TypeDef     DWord

SE_ADT_ACCESS_REASON Struct
    AccessMask                                              ACCESS_MASK ?
    AccessReasons                                           DD          32 Dup(?)
    ObjectTypeIndex                                         DD          ?
    AccessGranted                                           DD          ?
    SecurityDescriptor                                      PSECURITY_DESCRIPTOR    ?
SE_ADT_ACCESS_REASON EndS
PSE_ADT_ACCESS_REASON                                       TypeDef     DWord

SE_MAX_AUDIT_PARAMETERS                                     Equ         32
SE_MAX_GENERIC_AUDIT_PARAMETERS                             Equ         28

SE_ADT_PARAMETER_ARRAY Struct
    CategoryId                                              DD          ?
    AuditId                                                 DD          ?
    ParameterCount                                          DD          ?
    _Length                                                 DD          ?   ;Length
    FlatSubCategoryId                                       DW          ?
    _Type                                                   DW          ?   ;Type
    Flags                                                   DD          ?
    Parameters                                              SE_ADT_PARAMETER_ARRAY_ENTRY SE_MAX_AUDIT_PARAMETERS Dup(<>)
SE_ADT_PARAMETER_ARRAY EndS
PSE_ADT_PARAMETER_ARRAY                                     TypeDef     DWord

SE_ADT_PARAMETERS_SELF_RELATIVE                             Equ         00000001H
SE_ADT_PARAMETERS_SEND_TO_LSA                               Equ         00000002H
SE_ADT_PARAMETER_EXTENSIBLE_AUDIT                           Equ         00000004H
SE_ADT_PARAMETER_GENERIC_AUDIT                              Equ         00000008H
SE_ADT_PARAMETER_WRITE_SYNCHRONOUS                          Equ         00000010H

DEVICE_TYPE                                                 TypeDef     DWord

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

FILE_READ_DATA                                              Equ         (0001H)
FILE_LIST_DIRECTORY                                         Equ         (0001H)

FILE_WRITE_DATA                                             Equ         (0002H)
FILE_ADD_FILE                                               Equ         (0002H)

FILE_APPEND_DATA                                            Equ         (0004H)
FILE_ADD_SUBDIRECTORY                                       Equ         (0004H)
FILE_CREATE_PIPE_INSTANCE                                   Equ         (0004H)

FILE_READ_EA                                                Equ         (0008H)

FILE_WRITE_EA                                               Equ         (0010H)

FILE_EXECUTE                                                Equ         (0020H)
FILE_TRAVERSE                                               Equ         (0020H)

FILE_DELETE_CHILD                                           Equ         (0040H)

FILE_READ_ATTRIBUTES                                        Equ         (0080H)

FILE_WRITE_ATTRIBUTES                                       Equ         (0100H)

FILE_ALL_ACCESS                                             Equ         (STANDARD_RIGHTS_REQUIRED Or SYNCHRONIZE Or 01FFH)

FILE_GENERIC_READ                                           Equ         (STANDARD_RIGHTS_READ Or FILE_READ_DATA Or FILE_READ_ATTRIBUTES Or FILE_READ_EA Or SYNCHRONIZE)

FILE_GENERIC_WRITE                                          Equ         (STANDARD_RIGHTS_WRITE Or FILE_WRITE_DATA Or FILE_WRITE_ATTRIBUTES Or FILE_WRITE_EA Or FILE_APPEND_DATA Or SYNCHRONIZE)

FILE_GENERIC_EXECUTE                                        Equ         (STANDARD_RIGHTS_EXECUTE Or FILE_READ_ATTRIBUTES Or FILE_EXECUTE Or SYNCHRONIZE)

FILE_SHARE_READ                                             Equ         00000001H
FILE_SHARE_WRITE                                            Equ         00000002H
FILE_SHARE_DELETE                                           Equ         00000004H
FILE_SHARE_VALID_FLAGS                                      Equ         00000007H

FILE_ATTRIBUTE_READONLY                                     Equ         00000001H
FILE_ATTRIBUTE_HIDDEN                                       Equ         00000002H
FILE_ATTRIBUTE_SYSTEM                                       Equ         00000004H

FILE_ATTRIBUTE_DIRECTORY                                    Equ         00000010H
FILE_ATTRIBUTE_ARCHIVE                                      Equ         00000020H
FILE_ATTRIBUTE_DEVICE                                       Equ         00000040H
FILE_ATTRIBUTE_NORMAL                                       Equ         00000080H

FILE_ATTRIBUTE_TEMPORARY                                    Equ         00000100H
FILE_ATTRIBUTE_SPARSE_FILE                                  Equ         00000200H
FILE_ATTRIBUTE_REPARSE_POINT                                Equ         00000400H
FILE_ATTRIBUTE_COMPRESSED                                   Equ         00000800H

FILE_ATTRIBUTE_OFFLINE                                      Equ         00001000H
FILE_ATTRIBUTE_NOT_CONTENT_INDEXED                          Equ         00002000H
FILE_ATTRIBUTE_ENCRYPTED                                    Equ         00004000H

FILE_ATTRIBUTE_VIRTUAL                                      Equ         00010000H

FILE_ATTRIBUTE_VALID_FLAGS                                  Equ         00007FB7H
FILE_ATTRIBUTE_VALID_SET_FLAGS                              Equ         000031A7H

FILE_SUPERSEDE                                              Equ         00000000H
FILE_OPEN                                                   Equ         00000001H
FILE_CREATE                                                 Equ         00000002H
FILE_OPEN_IF                                                Equ         00000003H
FILE_OVERWRITE                                              Equ         00000004H
FILE_OVERWRITE_IF                                           Equ         00000005H
FILE_MAXIMUM_DISPOSITION                                    Equ         00000005H

FILE_DIRECTORY_FILE                                         Equ         00000001H
FILE_WRITE_THROUGH                                          Equ         00000002H
FILE_SEQUENTIAL_ONLY                                        Equ         00000004H
FILE_NO_INTERMEDIATE_BUFFERING                              Equ         00000008H

FILE_SYNCHRONOUS_IO_ALERT                                   Equ         00000010H
FILE_SYNCHRONOUS_IO_NONALERT                                Equ         00000020H
FILE_NON_DIRECTORY_FILE                                     Equ         00000040H
FILE_CREATE_TREE_CONNECTION                                 Equ         00000080H

FILE_COMPLETE_IF_OPLOCKED                                   Equ         00000100H
FILE_NO_EA_KNOWLEDGE                                        Equ         00000200H
FILE_OPEN_REMOTE_INSTANCE                                   Equ         00000400H
FILE_RANDOM_ACCESS                                          Equ         00000800H

FILE_DELETE_ON_CLOSE                                        Equ         00001000H
FILE_OPEN_BY_FILE_ID                                        Equ         00002000H
FILE_OPEN_FOR_BACKUP_INTENT                                 Equ         00004000H
FILE_NO_COMPRESSION                                         Equ         00008000H

FILE_OPEN_REQUIRING_OPLOCK                                  Equ         00010000H
FILE_DISALLOW_EXCLUSIVE                                     Equ         00020000H

FILE_RESERVE_OPFILTER                                       Equ         00100000H
FILE_OPEN_REPARSE_POINT                                     Equ         00200000H
FILE_OPEN_NO_RECALL                                         Equ         00400000H
FILE_OPEN_FOR_FREE_SPACE_QUERY                              Equ         00800000H

FILE_VALID_OPTION_FLAGS                                     Equ         00FFFFFFH
FILE_VALID_PIPE_OPTION_FLAGS                                Equ         00000032H
FILE_VALID_MAILSLOT_OPTION_FLAGS                            Equ         00000032H
FILE_VALID_SET_FLAGS                                        Equ         00000036H

FILE_SUPERSEDED                                             Equ         00000000H
FILE_OPENED                                                 Equ         00000001H
FILE_CREATED                                                Equ         00000002H
FILE_OVERWRITTEN                                            Equ         00000003H
FILE_EXISTS                                                 Equ         00000004H
FILE_DOES_NOT_EXIST                                         Equ         00000005H

FILE_WRITE_TO_END_OF_FILE                                   Equ         0FFFFFFFFH
FILE_USE_FILE_POINTER_POSITION                              Equ         0FFFFFFFEH

FILE_BYTE_ALIGNMENT                                         Equ         00000000H
FILE_WORD_ALIGNMENT                                         Equ         00000001H
FILE_LONG_ALIGNMENT                                         Equ         00000003H
FILE_QUAD_ALIGNMENT                                         Equ         00000007H
FILE_OCTA_ALIGNMENT                                         Equ         0000000FH
FILE_32_BYTE_ALIGNMENT                                      Equ         0000001FH
FILE_64_BYTE_ALIGNMENT                                      Equ         0000003FH
FILE_128_BYTE_ALIGNMENT                                     Equ         0000007FH
FILE_256_BYTE_ALIGNMENT                                     Equ         000000FFH
FILE_512_BYTE_ALIGNMENT                                     Equ         000001FFH

MAXIMUM_FILENAME_LENGTH                                     Equ         256

FILE_REMOVABLE_MEDIA                                        Equ         00000001H
FILE_READ_ONLY_DEVICE                                       Equ         00000002H
FILE_FLOPPY_DISKETTE                                        Equ         00000004H
FILE_WRITE_ONCE_MEDIA                                       Equ         00000008H
FILE_REMOTE_DEVICE                                          Equ         00000010H
FILE_DEVICE_IS_MOUNTED                                      Equ         00000020H
FILE_VIRTUAL_VOLUME                                         Equ         00000040H
FILE_AUTOGENERATED_DEVICE_NAME                              Equ         00000080H
FILE_DEVICE_SECURE_OPEN                                     Equ         00000100H
FILE_CHARACTERISTIC_PNP_DEVICE                              Equ         00000800H
FILE_CHARACTERISTIC_TS_DEVICE                               Equ         00001000H
FILE_CHARACTERISTIC_WEBDAV_DEVICE                           Equ         00002000H

IO_STATUS_BLOCK Struct
    Union
       Status                                               NTSTATUS    ?
       Pointer                                              DD          ?
    EndS
    Information                                             DD          ?
IO_STATUS_BLOCK EndS
PIO_STATUS_BLOCK                                            TypeDef     DWord

IFDEF APP_WIN64
    IO_STATUS_BLOCK32 Struct
        Status                                              NTSTATUS    ?
        Information                                         DD          ?
    IO_STATUS_BLOCK32 EndS
    PIO_STATUS_BLOCK32                                      TypeDef     DWord
ENDIF

PIO_APC_ROUTINE_DEFINED                                     Equ         1

;IO_SESSION_EVENT Enumeration
IO_SESSION_EVENT                                            TypeDef     DWord
IoSessionEventIgnore                                        Equ         0
IoSessionEventCreated                                       Equ         1
IoSessionEventTerminated                                    Equ         2
IoSessionEventConnected                                     Equ         3
IoSessionEventDisconnected                                  Equ         4
IoSessionEventLogon                                         Equ         5
IoSessionEventLogoff                                        Equ         6
IoSessionEventMax                                           Equ         7
PIO_SESSION_EVENT                                           TypeDef     DWord

;IO_SESSION_STATE Enumeration
IO_SESSION_STATE                                            TypeDef     DWord
IoSessionStateCreated                                       Equ         1
IoSessionStateInitialized                                   Equ         2
IoSessionStateConnected                                     Equ         3
IoSessionStateDisconnected                                  Equ         4
IoSessionStateDisconnectedLoggedOn                          Equ         5
IoSessionStateLoggedOn                                      Equ         6
IoSessionStateLoggedOff                                     Equ         7
IoSessionStateTerminated                                    Equ         8
IoSessionStateMax                                           Equ         9
PIO_SESSION_STATE                                           TypeDef     DWord

IO_SESSION_STATE_ALL_EVENTS                                 Equ         0FFFFFFFFH
IO_SESSION_STATE_CREATION_EVENT                             Equ         000000001H
IO_SESSION_STATE_TERMINATION_EVENT                          Equ         000000002H
IO_SESSION_STATE_CONNECT_EVENT                              Equ         000000004H
IO_SESSION_STATE_DISCONNECT_EVENT                           Equ         000000008H
IO_SESSION_STATE_LOGON_EVENT                                Equ         000000010H
IO_SESSION_STATE_LOGOFF_EVENT                               Equ         000000020H

IO_SESSION_STATE_VALID_EVENT_MASK                           Equ         00000003FH

IO_SESSION_MAX_PAYLOAD_SIZE                                 Equ         256

IO_SESSION_CONNECT_INFO Struct
    SessionId                                               DD          ?
    LocalSession                                            BOOLEAN     ?
IO_SESSION_CONNECT_INFO EndS
PIO_SESSION_CONNECT_INFO                                    TypeDef     DWord

;FILE_INFORMATION_CLASS Enumeration
FILE_INFORMATION_CLASS                                      TypeDef     DWord
FileDirectoryInformation                                    Equ         1
FileFullDirectoryInformation                                Equ         2
FileBothDirectoryInformation                                Equ         3
FileBasicInformation                                        Equ         4
FileStandardInformation                                     Equ         5
FileInternalInformation                                     Equ         6
FileEaInformation                                           Equ         7
FileAccessInformation                                       Equ         8
FileNameInformation                                         Equ         9
FileRenameInformation                                       Equ         10
FileLinkInformation                                         Equ         11
FileNamesInformation                                        Equ         12
FileDispositionInformation                                  Equ         13
FilePositionInformation                                     Equ         14
FileFullEaInformation                                       Equ         15
FileModeInformation                                         Equ         16
FileAlignmentInformation                                    Equ         17
FileAllInformation                                          Equ         18
FileAllocationInformation                                   Equ         19
FileEndOfFileInformation                                    Equ         20
FileAlternateNameInformation                                Equ         21
FileStreamInformation                                       Equ         22
FilePipeInformation                                         Equ         23
FilePipeLocalInformation                                    Equ         24
FilePipeRemoteInformation                                   Equ         25
FileMailslotQueryInformation                                Equ         26
FileMailslotSetInformation                                  Equ         27
FileCompressionInformation                                  Equ         28
FileObjectIdInformation                                     Equ         29
FileCompletionInformation                                   Equ         30
FileMoveClusterInformation                                  Equ         31
FileQuotaInformation                                        Equ         32
FileReparsePointInformation                                 Equ         33
FileNetworkOpenInformation                                  Equ         34
FileAttributeTagInformation                                 Equ         35
FileTrackingInformation                                     Equ         36
FileIdBothDirectoryInformation                              Equ         37
FileIdFullDirectoryInformation                              Equ         38
FileValidDataLengthInformation                              Equ         39
FileShortNameInformation                                    Equ         40
FileIoCompletionNotificationInformation                     Equ         41
FileIoStatusBlockRangeInformation                           Equ         42
FileIoPriorityHintInformation                               Equ         43
FileSfioReserveInformation                                  Equ         44
FileSfioVolumeInformation                                   Equ         45
FileHardLinkInformation                                     Equ         46
FileProcessIdsUsingFileInformation                          Equ         47
FileNormalizedNameInformation                               Equ         48
FileNetworkPhysicalNameInformation                          Equ         49
FileIdGlobalTxDirectoryInformation                          Equ         50
FileIsRemoteDeviceInformation                               Equ         51
FileAttributeCacheInformation                               Equ         52
FileNumaNodeInformation                                     Equ         53
FileStandardLinkInformation                                 Equ         54
FileRemoteProtocolInformation                               Equ         55
FileMaximumInformation                                      Equ         56
PFILE_INFORMATION_CLASS                                     TypeDef     DWord

FILE_BASIC_INFORMATION Struct
    CreationTime                                            LARGE_INTEGER   <>
    LastAccessTime                                          LARGE_INTEGER   <>
    LastWriteTime                                           LARGE_INTEGER   <>
    ChangeTime                                              LARGE_INTEGER   <>
    FileAttributes                                          DD          ?
FILE_BASIC_INFORMATION EndS
PFILE_BASIC_INFORMATION                                     TypeDef     DWord

FILE_STANDARD_INFORMATION Struct
    AllocationSize                                          LARGE_INTEGER   <>
    EndOfFile                                               LARGE_INTEGER   <>
    NumberOfLinks                                           DD          ?
    DeletePending                                           BOOLEAN     ?
    Directory                                               BOOLEAN     ?
FILE_STANDARD_INFORMATION EndS
PFILE_STANDARD_INFORMATION                                  TypeDef     DWord


FILE_POSITION_INFORMATION Struct
    CurrentByteOffset                                       LARGE_INTEGER   <>
FILE_POSITION_INFORMATION EndS
PFILE_POSITION_INFORMATION                                  TypeDef     DWord


FILE_NETWORK_OPEN_INFORMATION Struct
    CreationTime                                            LARGE_INTEGER   <>
    LastAccessTime                                          LARGE_INTEGER   <>
    LastWriteTime                                           LARGE_INTEGER   <>
    ChangeTime                                              LARGE_INTEGER   <>
    AllocationSize                                          LARGE_INTEGER   <>
    EndOfFile                                               LARGE_INTEGER   <>
    FileAttributes                                          DD          ?
FILE_NETWORK_OPEN_INFORMATION EndS
PFILE_NETWORK_OPEN_INFORMATION                              TypeDef     DWord

FILE_FULL_EA_INFORMATION Struct
    NextEntryOffset                                         DD          ?
    Flags                                                   DB          ?
    EaNameLength                                            DB          ?
    EaValueLength                                           DW          ?
    EaName                                                  DB          1 Dup(?)
FILE_FULL_EA_INFORMATION EndS
PFILE_FULL_EA_INFORMATION                                   TypeDef     DWord

FILE_SFIO_RESERVE_INFORMATION Struct
    RequestsPerPeriod                                       DD          ?
    Period                                                  DD          ?
    RetryFailures                                           BOOLEAN     ?
    Discardable                                             BOOLEAN     ?
    RequestSize                                             DD          ?
    NumOutstandingRequests                                  DD          ?
FILE_SFIO_RESERVE_INFORMATION EndS
PFILE_SFIO_RESERVE_INFORMATION                              TypeDef     DWord

FILE_SFIO_VOLUME_INFORMATION Struct
    MaximumRequestsPerPeriod                                DD          ?
    MinimumPeriod                                           DD          ?
    MinimumTransferSize                                     DD          ?
FILE_SFIO_VOLUME_INFORMATION EndS
PFILE_SFIO_VOLUME_INFORMATION                               TypeDef     DWord

;IO_PRIORITY_HINT Enumeration
IO_PRIORITY_HINT                                            TypeDef     DWord
IoPriorityVeryLow                                           Equ         0
IoPriorityLow                                               Equ         1
IoPriorityNormal                                            Equ         2
IoPriorityHigh                                              Equ         3
IoPriorityCritical                                          Equ         4
MaxIoPriorityTypes                                          Equ         5

FILE_IO_PRIORITY_HINT_INFORMATION Struct
    PriorityHint                                            IO_PRIORITY_HINT    ?
FILE_IO_PRIORITY_HINT_INFORMATION EndS
PFILE_IO_PRIORITY_HINT_INFORMATION                          TypeDef     DWord

FILE_SKIP_COMPLETION_PORT_ON_SUCCESS                        Equ         01H

FILE_SKIP_SET_EVENT_ON_HANDLE                               Equ         02H

FILE_SKIP_SET_USER_EVENT_ON_FAST_IO                         Equ         04H

FILE_IO_COMPLETION_NOTIFICATION_INFORMATION Struct
    Flags                                                   DD          ?
FILE_IO_COMPLETION_NOTIFICATION_INFORMATION EndS
PFILE_IO_COMPLETION_NOTIFICATION_INFORMATION                TypeDef     DWord

FILE_PROCESS_IDS_USING_FILE_INFORMATION Struct
    NumberOfProcessIdsInList                                DD          ?
    ProcessIdList                                           DD          1 Dup(?)
FILE_PROCESS_IDS_USING_FILE_INFORMATION EndS
PFILE_PROCESS_IDS_USING_FILE_INFORMATION                    TypeDef     DWord

FILE_IS_REMOTE_DEVICE_INFORMATION Struct
    IsRemote                                                BOOLEAN     ?
FILE_IS_REMOTE_DEVICE_INFORMATION EndS
PFILE_IS_REMOTE_DEVICE_INFORMATION                          TypeDef     DWord

FILE_NUMA_NODE_INFORMATION Struct
    NodeNumber                                              DW          ?
FILE_NUMA_NODE_INFORMATION EndS
PFILE_NUMA_NODE_INFORMATION                                 TypeDef     DWord

FILE_IOSTATUSBLOCK_RANGE_INFORMATION Struct
    IoStatusBlockRange                                      DD          ?
    _Length                                                 DD          ?   ;Length
FILE_IOSTATUSBLOCK_RANGE_INFORMATION EndS
PFILE_IOSTATUSBLOCK_RANGE_INFORMATION                       TypeDef     DWord

;FS_INFORMATION_CLASS Enumeration
FS_INFORMATION_CLASS                                        TypeDef     DWord
FileFsVolumeInformation                                     Equ         1
FileFsLabelInformation                                      Equ         2
FileFsSizeInformation                                       Equ         3
FileFsDeviceInformation                                     Equ         4
FileFsAttributeInformation                                  Equ         5
FileFsControlInformation                                    Equ         6
FileFsFullSizeInformation                                   Equ         7
FileFsObjectIdInformation                                   Equ         8
FileFsDriverPathInformation                                 Equ         9
FileFsVolumeFlagsInformation                                Equ         10
FileFsMaximumInformation                                    Equ         11
PFS_INFORMATION_CLASS                                       TypeDef     DWord

FILE_FS_DEVICE_INFORMATION Struct
    DeviceType                                              DEVICE_TYPE ?
    Characteristics                                         DD          ?
FILE_FS_DEVICE_INFORMATION EndS
PFILE_FS_DEVICE_INFORMATION                                 TypeDef     DWord

;INTERFACE_TYPE Enumeration
INTERFACE_TYPE                                              TypeDef     DWord
InterfaceTypeUndefined                                      Equ         1
Internal                                                    Equ         2
Isa                                                         Equ         3
Eisa                                                        Equ         4
MicroChannel                                                Equ         5
TurboChannel                                                Equ         6
PCIBus                                                      Equ         7
VMEBus                                                      Equ         8
NuBus                                                       Equ         9
PCMCIABus                                                   Equ         10
CBus                                                        Equ         11
MPIBus                                                      Equ         12
MPSABus                                                     Equ         13
ProcessorInternal                                           Equ         14
InternalPowerBus                                            Equ         15
PNPISABus                                                   Equ         16
PNPBus                                                      Equ         17
Vmcs                                                        Equ         18
MaximumInterfaceType                                        Equ         19
PINTERFACE_TYPE                                             TypeDef     DWord

;DMA_WIDTH Enumeration
DMA_WIDTH                                                   TypeDef     DWord
Width8Bits                                                  Equ         0
Width16Bits                                                 Equ         1
Width32Bits                                                 Equ         2
MaximumDmaWidth                                             Equ         3
PDMA_WIDTH                                                  TypeDef     DWord

;DMA_SPEED Enumeration
DMA_SPEED                                                   TypeDef     DWord
Compatible                                                  Equ         0
TypeA                                                       Equ         1
TypeB                                                       Equ         2
TypeC                                                       Equ         3
TypeF                                                       Equ         4
MaximumDmaSpeed                                             Equ         5
PDMA_SPEED                                                  TypeDef     DWord

IO_ERROR_LOG_PACKET Struct
    MajorFunctionCode                                       DB          ?
    RetryCount                                              DB          ?
    DumpDataSize                                            DW          ?
    NumberOfStrings                                         DW          ?
    StringOffset                                            DW          ?
    EventCategory                                           DW          ?
    ErrorCode                                               NTSTATUS    ?
    UniqueErrorValue                                        DD          ?
    FinalStatus                                             NTSTATUS    ?
    SequenceNumber                                          DD          ?
    IoControlCode                                           DD          ?
    DeviceOffset                                            LARGE_INTEGER   <>
    DumpData                                                DD          1 Dup(?)
IO_ERROR_LOG_PACKET EndS
PIO_ERROR_LOG_PACKET                                        TypeDef     DWord

IO_ERROR_LOG_MESSAGE Struct
    _Type                                                   DW          ?   ;Type
    _Size                                                   DW          ?   ;Size
    DriverNameLength                                        DW          ?
    TimeStamp                                               LARGE_INTEGER   <>
    DriverNameOffset                                        DD          ?
    EntryData                                               IO_ERROR_LOG_PACKET <>
IO_ERROR_LOG_MESSAGE EndS
PIO_ERROR_LOG_MESSAGE                                       TypeDef     DWord

ERROR_LOG_LIMIT_SIZE                                        Equ         (256-16)

IO_ERROR_LOG_MESSAGE_HEADER_LENGTH                          Equ         (SizeOf IO_ERROR_LOG_MESSAGE - SizeOf IO_ERROR_LOG_PACKET + (SizeOf WCHAR * 40))

ERROR_LOG_MESSAGE_LIMIT_SIZE                                Equ         (ERROR_LOG_LIMIT_SIZE + IO_ERROR_LOG_MESSAGE_HEADER_LENGTH)

IFDEF APP_WIN64
    PORT_MAXIMUM_MESSAGE_LENGTH                             Equ         512
ELSE
    PORT_MAXIMUM_MESSAGE_LENGTH                             Equ         256
ENDIF

KEY_QUERY_VALUE                                             Equ         (0001H)
KEY_SET_VALUE                                               Equ         (0002H)
KEY_CREATE_SUB_KEY                                          Equ         (0004H)
KEY_ENUMERATE_SUB_KEYS                                      Equ         (0008H)
KEY_NOTIFY                                                  Equ         (0010H)
KEY_CREATE_LINK                                             Equ         (0020H)
KEY_WOW64_32KEY                                             Equ         (0200H)
KEY_WOW64_64KEY                                             Equ         (0100H)
KEY_WOW64_RES                                               Equ         (0300H)

KEY_READ                                                    Equ         ((STANDARD_RIGHTS_READ Or KEY_QUERY_VALUE Or KEY_ENUMERATE_SUB_KEYS Or KEY_NOTIFY) And (Not SYNCHRONIZE))

KEY_WRITE                                                   Equ         ((STANDARD_RIGHTS_WRITE Or KEY_SET_VALUE Or KEY_CREATE_SUB_KEY) And (Not SYNCHRONIZE))

KEY_EXECUTE                                                 Equ         ((KEY_READ) And (Not SYNCHRONIZE))

KEY_ALL_ACCESS                                              Equ         ((STANDARD_RIGHTS_ALL Or KEY_QUERY_VALUE Or KEY_SET_VALUE Or KEY_CREATE_SUB_KEY Or KEY_ENUMERATE_SUB_KEYS Or KEY_NOTIFY Or KEY_CREATE_LINK) And (Not SYNCHRONIZE))

REG_OPTION_RESERVED                                         Equ         (00000000H)

REG_OPTION_NON_VOLATILE                                     Equ         (00000000H)

REG_OPTION_VOLATILE                                         Equ         (00000001H)

REG_OPTION_CREATE_LINK                                      Equ         (00000002H)

REG_OPTION_BACKUP_RESTORE                                   Equ         (00000004H)

REG_OPTION_OPEN_LINK                                        Equ         (00000008H)

REG_LEGAL_OPTION                                            Equ         (REG_OPTION_RESERVED Or REG_OPTION_NON_VOLATILE Or REG_OPTION_VOLATILE Or REG_OPTION_CREATE_LINK Or REG_OPTION_BACKUP_RESTORE Or REG_OPTION_OPEN_LINK)

REG_OPEN_LEGAL_OPTION                                       Equ         (REG_OPTION_RESERVED Or REG_OPTION_BACKUP_RESTORE Or REG_OPTION_OPEN_LINK)

REG_CREATED_NEW_KEY                                         Equ         (00000001H)
REG_OPENED_EXISTING_KEY                                     Equ         (00000002H)

REG_STANDARD_FORMAT                                         Equ         1
REG_LATEST_FORMAT                                           Equ         2
REG_NO_COMPRESSION                                          Equ         4

REG_WHOLE_HIVE_VOLATILE                                     Equ         (00000001H)
REG_REFRESH_HIVE                                            Equ         (00000002H)
REG_NO_LAZY_FLUSH                                           Equ         (00000004H)
REG_FORCE_RESTORE                                           Equ         (00000008H)
REG_APP_HIVE                                                Equ         (00000010H)
REG_PROCESS_PRIVATE                                         Equ         (00000020H)
REG_START_JOURNAL                                           Equ         (00000040H)
REG_HIVE_EXACT_FILE_GROWTH                                  Equ         (00000080H)
REG_HIVE_NO_RM                                              Equ         (00000100H)
REG_HIVE_SINGLE_LOG                                         Equ         (00000200H)
REG_BOOT_HIVE                                               Equ         (00000400H)

REG_FORCE_UNLOAD                                            Equ         1

REG_NOTIFY_CHANGE_NAME                                      Equ         (00000001H)
REG_NOTIFY_CHANGE_ATTRIBUTES                                Equ         (00000002H)
REG_NOTIFY_CHANGE_LAST_SET                                  Equ         (00000004H)
REG_NOTIFY_CHANGE_SECURITY                                  Equ         (00000008H)

REG_LEGAL_CHANGE_FILTER                                     Equ         (REG_NOTIFY_CHANGE_NAME Or REG_NOTIFY_CHANGE_ATTRIBUTES Or REG_NOTIFY_CHANGE_LAST_SET Or REG_NOTIFY_CHANGE_SECURITY)

KEY_BASIC_INFORMATION Struct
    LastWriteTime                                           LARGE_INTEGER   <>
    TitleIndex                                              DD          ?
    NameLength                                              DD          ?
    _Name                                                   DW          1 Dup(?)
KEY_BASIC_INFORMATION EndS
PKEY_BASIC_INFORMATION                                      TypeDef     DWord

KEY_NODE_INFORMATION Struct
    LastWriteTime                                           LARGE_INTEGER   <>
    TitleIndex                                              DD          ?
    ClassOffset                                             DD          ?
    ClassLength                                             DD          ?
    NameLength                                              DD          ?
    _Name                                                   DW          1 Dup(?)
KEY_NODE_INFORMATION EndS
PKEY_NODE_INFORMATION                                       TypeDef     DWord

KEY_FULL_INFORMATION Struct
    LastWriteTime                                           LARGE_INTEGER   <>
    TitleIndex                                              DD          ?
    ClassOffset                                             DD          ?
    ClassLength                                             DD          ?
    SubKeys                                                 DD          ?
    MaxNameLen                                              DD          ?
    MaxClassLen                                             DD          ?
    Values                                                  DD          ?
    MaxValueNameLen                                         DD          ?
    MaxValueDataLen                                         DD          ?
    Class                                                   DW          1 Dup(?)
KEY_FULL_INFORMATION EndS
PKEY_FULL_INFORMATION                                       TypeDef     DWord

;KEY_INFORMATION_CLASS Enumeration
KEY_INFORMATION_CLASS                                       TypeDef     DWord
KeyBasicInformation                                         Equ         0
KeyNodeInformation                                          Equ         1
KeyFullInformation                                          Equ         2
KeyNameInformation                                          Equ         3
KeyCachedInformation                                        Equ         4
KeyFlagsInformation                                         Equ         5
KeyVirtualizationInformation                                Equ         6
KeyHandleTagsInformation                                    Equ         7
MaxKeyInfoClass                                             Equ         8

KEY_WRITE_TIME_INFORMATION Struct
    LastWriteTime                                           LARGE_INTEGER   <>
KEY_WRITE_TIME_INFORMATION EndS
PKEY_WRITE_TIME_INFORMATION                                 TypeDef     DWord

KEY_WOW64_FLAGS_INFORMATION Struct
    UserFlags                                               DD          ?
KEY_WOW64_FLAGS_INFORMATION EndS
PKEY_WOW64_FLAGS_INFORMATION                                TypeDef     DWord

KEY_HANDLE_TAGS_INFORMATION Struct
    HandleTags                                              DD          ?
KEY_HANDLE_TAGS_INFORMATION EndS
PKEY_HANDLE_TAGS_INFORMATION                                TypeDef     DWord

KEY_CONTROL_FLAGS_INFORMATION Struct
    ControlFlags                                            DD          ?
KEY_CONTROL_FLAGS_INFORMATION EndS
PKEY_CONTROL_FLAGS_INFORMATION                              TypeDef     DWord

;KEY_SET_INFORMATION_CLASS Enumeration
KEY_SET_INFORMATION_CLASS                                   TypeDef     DWord
KeyWriteTimeInformation                                     Equ         0
KeyWow64FlagsInformation                                    Equ         1
KeyControlFlagsInformation                                  Equ         2
KeySetVirtualizationInformation                             Equ         3
KeySetDebugInformation                                      Equ         4
KeySetHandleTagsInformation                                 Equ         5
MaxKeySetInfoClass                                          Equ         6

KEY_VALUE_BASIC_INFORMATION Struct
    TitleIndex                                              DD          ?
    _Type                                                   DD          ?
    NameLength                                              DD          ?
    _Name                                                   DW          1 Dup(?)
KEY_VALUE_BASIC_INFORMATION EndS
PKEY_VALUE_BASIC_INFORMATION                                TypeDef     DWord

KEY_VALUE_FULL_INFORMATION Struct
    TitleIndex                                              DD          ?
    _Type                                                   DD          ?   ;Type
    DataOffset                                              DD          ?
    DataLength                                              DD          ?
    NameLength                                              DD          ?
    _Name                                                   DW          1 Dup(?)
KEY_VALUE_FULL_INFORMATION EndS
PKEY_VALUE_FULL_INFORMATION                                 TypeDef     DWord

KEY_VALUE_PARTIAL_INFORMATION Struct
    TitleIndex                                              DD          ?
    _Type                                                   DD          ?   ;Type
    DataLength                                              DD          ?
    Data                                                    DB          1 Dup(?)
KEY_VALUE_PARTIAL_INFORMATION EndS
PKEY_VALUE_PARTIAL_INFORMATION                              TypeDef     DWord

KEY_VALUE_PARTIAL_INFORMATION_ALIGN64 Struct
    _Type                                                   DD          ?   ;Type
    DataLength                                              DD          ?
    Data                                                    DB          1 Dup(?)
KEY_VALUE_PARTIAL_INFORMATION_ALIGN64 EndS
PKEY_VALUE_PARTIAL_INFORMATION_ALIGN64                      TypeDef     DWord

KEY_VALUE_ENTRY Struct
    ValueName                                               PUNICODE_STRING ?
    DataLength                                              DD          ?
    DataOffset                                              DD          ?
    _Type                                                   DD          ?   ;Type
KEY_VALUE_ENTRY EndS
PKEY_VALUE_ENTRY                                            TypeDef     DWord

;KEY_VALUE_INFORMATION_CLASS Enumeration
KEY_VALUE_INFORMATION_CLASS                                 TypeDef     DWord
KeyValueBasicInformation                                    Equ         0
KeyValueFullInformation                                     Equ         1
KeyValuePartialInformation                                  Equ         2
KeyValueFullInformationAlign64                              Equ         3
KeyValuePartialInformationAlign64                           Equ         4
MaxKeyValueInfoClass                                        Equ         5

OBJ_NAME_PATH_SEPARATOR                                     Equ         L("\")

OBJECT_TYPE_CREATE                                          Equ         (0001H)

OBJECT_TYPE_ALL_ACCESS                                      Equ         (STANDARD_RIGHTS_REQUIRED Or 01H)

DIRECTORY_QUERY                                             Equ         (0001H)
DIRECTORY_TRAVERSE                                          Equ         (0002H)
DIRECTORY_CREATE_OBJECT                                     Equ         (0004H)
DIRECTORY_CREATE_SUBDIRECTORY                               Equ         (0008H)

DIRECTORY_ALL_ACCESS                                        Equ         (STANDARD_RIGHTS_REQUIRED Or 0FH)

SYMBOLIC_LINK_QUERY                                         Equ         (0001H)

SYMBOLIC_LINK_ALL_ACCESS                                    Equ         (STANDARD_RIGHTS_REQUIRED Or 01H)

OBJECT_NAME_INFORMATION Struct
    _Name                                                   UNICODE_STRING  <>
OBJECT_NAME_INFORMATION EndS
POBJECT_NAME_INFORMATION                                    TypeDef     DWord

DUPLICATE_CLOSE_SOURCE                                      Equ         00000001H
DUPLICATE_SAME_ACCESS                                       Equ         00000002H
DUPLICATE_SAME_ATTRIBUTES                                   Equ         00000004H

;SECTION_INHERIT Enumeration
SECTION_INHERIT                                             TypeDef     DWord
ViewShare                                                   Equ         1
ViewUnmap                                                   Equ         2

SECTION_QUERY                                               Equ         0001H
SECTION_MAP_WRITE                                           Equ         0002H
SECTION_MAP_READ                                            Equ         0004H
SECTION_MAP_EXECUTE                                         Equ         0008H
SECTION_EXTEND_SIZE                                         Equ         0010H
SECTION_MAP_EXECUTE_EXPLICIT                                Equ         0020H

SECTION_ALL_ACCESS                                          Equ         (STANDARD_RIGHTS_REQUIRED Or SECTION_QUERY Or SECTION_MAP_WRITE Or SECTION_MAP_READ Or SECTION_MAP_EXECUTE Or SECTION_EXTEND_SIZE)

SESSION_QUERY_ACCESS                                        Equ         0001H
SESSION_MODIFY_ACCESS                                       Equ         0002H

SESSION_ALL_ACCESS                                          Equ         (STANDARD_RIGHTS_REQUIRED Or SESSION_QUERY_ACCESS Or SESSION_MODIFY_ACCESS)

SEGMENT_ALL_ACCESS                                          Equ         SECTION_ALL_ACCESS

PAGE_NOACCESS                                               Equ         01H
PAGE_READONLY                                               Equ         02H
PAGE_READWRITE                                              Equ         04H
PAGE_WRITECOPY                                              Equ         08H
PAGE_EXECUTE                                                Equ         10H
PAGE_EXECUTE_READ                                           Equ         20H
PAGE_EXECUTE_READWRITE                                      Equ         40H
PAGE_EXECUTE_WRITECOPY                                      Equ         80H
PAGE_GUARD                                                  Equ         100H
PAGE_NOCACHE                                                Equ         200H
PAGE_WRITECOMBINE                                           Equ         400H

MEM_COMMIT                                                  Equ         1000H
MEM_RESERVE                                                 Equ         2000H
MEM_DECOMMIT                                                Equ         4000H
MEM_RELEASE                                                 Equ         8000H
MEM_FREE                                                    Equ         10000H
MEM_PRIVATE                                                 Equ         20000H
MEM_MAPPED                                                  Equ         40000H
MEM_RESET                                                   Equ         80000H
MEM_TOP_DOWN                                                Equ         100000H
MEM_LARGE_PAGES                                             Equ         20000000H
MEM_4MB_PAGES                                               Equ         80000000H
SEC_RESERVE                                                 Equ         4000000H
SEC_COMMIT                                                  Equ         8000000H
SEC_LARGE_PAGES                                             Equ         80000000H
PROCESS_DUP_HANDLE                                          Equ         (0040H)

;IF (NTDDI_VERSION >= NTDDI_VISTA)
;   PROCESS_ALL_ACCESS                                      Equ         (STANDARD_RIGHTS_REQUIRED Or SYNCHRONIZE Or 0FFFFH)
;ELSE
    PROCESS_ALL_ACCESS                                      Equ         (STANDARD_RIGHTS_REQUIRED Or SYNCHRONIZE Or 0FFFH)
;ENDIF

IFDEF APP_WIN64
    MAXIMUM_PROC_PER_GROUP                                  Equ         64
ELSE
    MAXIMUM_PROC_PER_GROUP                                  Equ         32
ENDIF

MAXIMUM_PROCESSORS                                          Equ         MAXIMUM_PROC_PER_GROUP

THREAD_TERMINATE                                            Equ         (0001H)
THREAD_SUSPEND_RESUME                                       Equ         (0002H)
THREAD_ALERT                                                Equ         (0004H)
THREAD_GET_CONTEXT                                          Equ         (0008H)
THREAD_SET_CONTEXT                                          Equ         (0010H)
THREAD_SET_INFORMATION                                      Equ         (0020H)
THREAD_SET_LIMITED_INFORMATION                              Equ         (0400H)
THREAD_QUERY_LIMITED_INFORMATION                            Equ         (0800H)
;IF (NTDDI_VERSION >= NTDDI_VISTA)
;   THREAD_ALL_ACCESS                                       Equ         (STANDARD_RIGHTS_REQUIRED Or SYNCHRONIZE Or 0FFFFH)
;ELSE
    THREAD_ALL_ACCESS                                       Equ         (STANDARD_RIGHTS_REQUIRED Or SYNCHRONIZE Or 03FFH)
;ENDIF

CLIENT_ID Struct
    UniqueProcess                                           HANDLE      ?
    UniqueThread                                            HANDLE      ?
CLIENT_ID EndS
PCLIENT_ID                                                  TypeDef     DWord

NtCurrentProcess                                            Equ         (-1)
ZwCurrentProcess                                            Equ         <NtCurrentProcess>
NtCurrentThread                                             Equ         (-2)
ZwCurrentThread                                             Equ         <NtCurrentThread>

IFNDEF GUID_MAX_POWER_SAVINGS
	DEFINE_GUID     GUID_MAX_POWER_SAVINGS,                                                 0A1841308H, 03541H, 04FABH, 0BCH, 081H, 0F7H, 015H, 056H, 0F2H, 00BH, 04AH
	DEFINE_GUID     GUID_MIN_POWER_SAVINGS,                                                 08C5E7FDAH, 0E8BFH, 04A96H, 09AH, 085H, 0A6H, 0E2H, 03AH, 08CH, 063H, 05CH

	DEFINE_GUID     GUID_TYPICAL_POWER_SAVINGS,                                             0381B4222H, 0F694H, 041F0H, 096H, 085H, 0FFH, 05BH, 0B2H, 060H, 0DFH, 02EH
	DEFINE_GUID     NO_SUBGROUP_GUID,                                                       0FEA3413EH, 07E05H, 04911H, 09AH, 071H, 070H, 003H, 031H, 0F1H, 0C2H, 094H
	DEFINE_GUID     ALL_POWERSCHEMES_GUID,                                                  068A1E95EH, 013EAH, 041E1H, 080H, 011H, 00CH, 049H, 06CH, 0A4H, 090H, 0B0H
	DEFINE_GUID     GUID_POWERSCHEME_PERSONALITY,                                           0245D8541H, 03943H, 04422H, 0B0H, 025H, 013H, 0A7H, 084H, 0F6H, 079H, 0B7H
	DEFINE_GUID     GUID_ACTIVE_POWERSCHEME,                                                031F9F286H, 05084H, 042FEH, 0B7H, 020H, 02BH, 002H, 064H, 099H, 037H, 063H
	DEFINE_GUID     GUID_VIDEO_SUBGROUP,                                                    07516B95FH, 0F776H, 04464H, 08CH, 053H, 006H, 016H, 07FH, 040H, 0CCH, 099H
	DEFINE_GUID     GUID_VIDEO_POWERDOWN_TIMEOUT,                                           03C0BC021H, 0C8A8H, 04E07H, 0A9H, 073H, 06BH, 014H, 0CBH, 0CBH, 02BH, 07EH
	DEFINE_GUID     GUID_VIDEO_ANNOYANCE_TIMEOUT,                                           082DBCF2DH, 0CD67H, 040C5H, 0BFH, 0DCH, 09FH, 01AH, 05CH, 0CDH, 046H, 063H
	DEFINE_GUID     GUID_VIDEO_ADAPTIVE_PERCENT_INCREASE,                                   0EED904DFH, 0B142H, 04183H, 0B1H, 00BH, 05AH, 011H, 097H, 0A3H, 078H, 064H
	DEFINE_GUID     GUID_VIDEO_DIM_TIMEOUT,                                                 017AAA29BH, 08B43H, 04B94H, 0AAH, 0FEH, 035H, 0F6H, 04DH, 0AAH, 0F1H, 0EEH
	DEFINE_GUID     GUID_VIDEO_ADAPTIVE_POWERDOWN,                                          090959D22H, 0D6A1H, 049B9H, 0AFH, 093H, 0BCH, 0E8H, 085H, 0ADH, 033H, 05BH
	DEFINE_GUID     GUID_MONITOR_POWER_ON,                                                  002731015H, 04510H, 04526H, 099H, 0E6H, 0E5H, 0A1H, 07EH, 0BDH, 01AH, 0EAH
	DEFINE_GUID     GUID_DEVICE_POWER_POLICY_VIDEO_BRIGHTNESS,                              0ADED5E82H, 0B909H, 04619H, 099H, 049H, 0F5H, 0D7H, 01DH, 0ACH, 00BH, 0CBH
	DEFINE_GUID     GUID_DEVICE_POWER_POLICY_VIDEO_DIM_BRIGHTNESS,                          0F1FBFDE2H, 0A960H, 04165H, 09FH, 088H, 050H, 066H, 079H, 011H, 0CEH, 096H
	DEFINE_GUID     GUID_VIDEO_CURRENT_MONITOR_BRIGHTNESS,                                  08FFEE2C6H, 02D01H, 046BEH, 0ADH, 0B9H, 039H, 08AH, 0DDH, 0C5H, 0B4H, 0FFH
	DEFINE_GUID     GUID_VIDEO_ADAPTIVE_DISPLAY_BRIGHTNESS,                                 0FBD9AA66H, 09553H, 04097H, 0BAH, 044H, 0EDH, 06EH, 09DH, 065H, 0EAH, 0B8H
	DEFINE_GUID     GUID_SESSION_DISPLAY_STATE,                                             073A5E93AH, 05BB1H, 04F93H, 089H, 05BH, 0DBH, 0D0H, 0DAH, 085H, 059H, 067H
	DEFINE_GUID     GUID_CONSOLE_DISPLAY_STATE,                                             06FE69556H, 0704AH, 047A0H, 08FH, 024H, 0C2H, 08DH, 093H, 06FH, 0DAH, 047H
	DEFINE_GUID     GUID_ALLOW_DISPLAY_REQUIRED,                                            0A9CEB8DAH, 0CD46H, 044FBH, 0A9H, 08BH, 002H, 0AFH, 069H, 0DEH, 046H, 023H
	DEFINE_GUID     GUID_DISK_SUBGROUP,                                                     00012EE47H, 09041H, 04B5DH, 09BH, 077H, 053H, 05FH, 0BAH, 08BH, 014H, 042H
	DEFINE_GUID     GUID_DISK_POWERDOWN_TIMEOUT,                                            06738E2C4H, 0E8A5H, 04A42H, 0B1H, 06AH, 0E0H, 040H, 0E7H, 069H, 075H, 06EH
	DEFINE_GUID     GUID_DISK_BURST_IGNORE_THRESHOLD,                                       080E3C60EH, 0BB94H, 04AD8H, 0BBH, 0E0H, 00DH, 031H, 095H, 0EFH, 0C6H, 063H
	DEFINE_GUID     GUID_DISK_ADAPTIVE_POWERDOWN,                                           0396A32E1H, 0499AH, 040B2H, 091H, 024H, 0A9H, 06AH, 0FEH, 070H, 076H, 067H
	DEFINE_GUID     GUID_SLEEP_SUBGROUP,                                                    0238C9FA8H, 00AADH, 041EDH, 083H, 0F4H, 097H, 0BEH, 024H, 02CH, 08FH, 020H
	DEFINE_GUID     GUID_SLEEP_IDLE_THRESHOLD,                                              081CD32E0H, 07833H, 044F3H, 087H, 037H, 070H, 081H, 0F3H, 08DH, 01FH, 070H
	DEFINE_GUID     GUID_STANDBY_TIMEOUT,                                                   029F6C1DBH, 086DAH, 048C5H, 09FH, 0DBH, 0F2H, 0B6H, 07BH, 01FH, 044H, 0DAH
	DEFINE_GUID     GUID_UNATTEND_SLEEP_TIMEOUT,                                            07BC4A2F9H, 0D8FCH, 04469H, 0B0H, 07BH, 033H, 0EBH, 078H, 05AH, 0ACH, 0A0H
	DEFINE_GUID     GUID_HIBERNATE_TIMEOUT,                                                 09D7815A6H, 07EE4H, 0497EH, 088H, 088H, 051H, 05AH, 005H, 0F0H, 023H, 064H
	DEFINE_GUID     GUID_HIBERNATE_FASTS4_POLICY,                                           094AC6D29H, 073CEH, 041A6H, 080H, 09FH, 063H, 063H, 0BAH, 021H, 0B4H, 07EH
	DEFINE_GUID     GUID_CRITICAL_POWER_TRANSITION,                                         0B7A27025H, 0E569H, 046c2H, 0A5H, 004H, 02BH, 096H, 0CAH, 0D2H, 025H, 0A1H
	DEFINE_GUID     GUID_SYSTEM_AWAYMODE,                                                   098A7F580H, 001F7H, 048AAH, 09CH, 00FH, 044H, 035H, 02CH, 029H, 0E5H, 0C0H
	DEFINE_GUID     GUID_ALLOW_AWAYMODE,                                                    025DFA149H, 05DD1H, 04736H, 0B5H, 0ABH, 0E8H, 0A3H, 07BH, 05BH, 081H, 087H
	DEFINE_GUID     GUID_ALLOW_STANDBY_STATES,                                              0ABFC2519H, 03608H, 04C2AH, 094H, 0EAH, 017H, 01BH, 00EH, 0D5H, 046H, 0ABH
	DEFINE_GUID     GUID_ALLOW_RTC_WAKE,                                                    0BD3B718AH, 00680H, 04D9DH, 08AH, 0B2H, 0E1H, 0D2H, 0B4H, 0ACH, 080H, 06DH
	DEFINE_GUID     GUID_ALLOW_SYSTEM_REQUIRED,                                             0A4B195F5H, 08225H, 047D8H, 080H, 012H, 09DH, 041H, 036H, 097H, 086H, 0E2H
	DEFINE_GUID     GUID_SYSTEM_BUTTON_SUBGROUP,                                            04F971E89H, 0EEBDH, 04455H, 0A8H, 0DEH, 09EH, 059H, 004H, 00EH, 073H, 047H
	DEFINE_GUID     GUID_POWERBUTTON_ACTION,                                                07648EFA3H, 0DD9CH, 04E3EH, 0B5H, 066H, 050H, 0F9H, 029H, 038H, 062H, 080H
	DEFINE_GUID     GUID_POWERBUTTON_ACTION_FLAGS,                                          0857E7FACH, 0034BH, 04704H, 0ABH, 0B1H, 0BCH, 0A5H, 04AH, 0A3H, 014H, 078H
	DEFINE_GUID     GUID_SLEEPBUTTON_ACTION,                                                096996BC0H, 0AD50H, 047ECH, 092H, 03BH, 06FH, 041H, 087H, 04DH, 0D9H, 0EBH
	DEFINE_GUID     GUID_SLEEPBUTTON_ACTION_FLAGS,                                          02A160AB1H, 0B69DH, 04743H, 0B7H, 018H, 0BFH, 014H, 041H, 0D5H, 0E4H, 093H
	DEFINE_GUID     GUID_USERINTERFACEBUTTON_ACTION,                                        0A7066653H, 08D6CH, 040A8H, 091H, 00EH, 0A1H, 0F5H, 04BH, 084H, 0C7H, 0E5H
	DEFINE_GUID     GUID_LIDCLOSE_ACTION,                                                   05CA83367H, 06E45H, 0459FH, 0A2H, 07BH, 047H, 06BH, 01DH, 001H, 0C9H, 036H
	DEFINE_GUID     GUID_LIDCLOSE_ACTION_FLAGS,                                             097E969ACH, 00D6CH, 04D08H, 092H, 07CH, 0D7H, 0BDH, 07AH, 0D7H, 085H, 07BH
	DEFINE_GUID     GUID_LIDOPEN_POWERSTATE,                                                099FF10E7H, 023B1H, 04C07H, 0A9H, 0D1H, 05CH, 032H, 006H, 0D7H, 041H, 0B4H
	DEFINE_GUID     GUID_BATTERY_SUBGROUP,                                                  0E73A048DH, 0BF27H, 04F12H, 097H, 031H, 08BH, 020H, 076H, 0E8H, 089H, 01FH
	DEFINE_GUID     GUID_BATTERY_DISCHARGE_ACTION_0,                                        0637EA02FH, 0BBCBH, 04015H, 08EH, 02CH, 0A1H, 0C7H, 0B9H, 0C0H, 0B5H, 046H
	DEFINE_GUID     GUID_BATTERY_DISCHARGE_LEVEL_0,                                         09A66D8D7H, 04FF7H, 04EF9H, 0B5H, 0A2H, 05AH, 032H, 06CH, 0A2H, 0A4H, 069H
	DEFINE_GUID     GUID_BATTERY_DISCHARGE_FLAGS_0,                                         05DBB7C9FH, 038E9H, 040D2H, 097H, 049H, 04FH, 08AH, 00EH, 09FH, 064H, 00FH

	DEFINE_GUID     GUID_BATTERY_DISCHARGE_ACTION_1,                                        0D8742DCBH, 03E6AH, 04B3CH, 0B3H, 0FEH, 037H, 046H, 023H, 0CDH, 0CFH, 006H
	DEFINE_GUID     GUID_BATTERY_DISCHARGE_LEVEL_1,                                         08183BA9AH, 0E910H, 048DAH, 087H, 069H, 014H, 0AEH, 06DH, 0C1H, 017H, 00AH
	DEFINE_GUID     GUID_BATTERY_DISCHARGE_FLAGS_1,                                         0BCDED951H, 0187BH, 04D05H, 0BCH, 0CCH, 0F7H, 0E5H, 019H, 060H, 0C2H, 058H

	DEFINE_GUID     GUID_BATTERY_DISCHARGE_ACTION_2,                                        0421CBA38H, 01A8EH, 04881H, 0ACH, 089H, 0E3H, 03AH, 08BH, 004H, 0ECH, 0E4H
	DEFINE_GUID     GUID_BATTERY_DISCHARGE_LEVEL_2,                                         007A07CA2H, 0ADAFH, 040D7H, 0B0H, 077H, 053H, 03AH, 0ADH, 0EDH, 01BH, 0FAH
	DEFINE_GUID     GUID_BATTERY_DISCHARGE_FLAGS_2,                                         07FD2F0C4H, 0FEB7H, 04DA3H, 081H, 017H, 0E3H, 0FBH, 0EDH, 0C4H, 065H, 082H

	DEFINE_GUID     GUID_BATTERY_DISCHARGE_ACTION_3,                                        080472613H, 09780H, 0455EH, 0B3H, 008H, 072H, 0D3H, 000H, 03CH, 0F2H, 0F8H
	DEFINE_GUID     GUID_BATTERY_DISCHARGE_LEVEL_3,                                         058AFD5A6H, 0C2DDH, 047D2H, 09FH, 0BFH, 0EFH, 070H, 0CCH, 05CH, 059H, 065H
	DEFINE_GUID     GUID_BATTERY_DISCHARGE_FLAGS_3,                                         073613CCFH, 0DBFAH, 04279H, 083H, 056H, 049H, 035H, 0f6H, 0bfH, 062H, 0f3H

	DEFINE_GUID     GUID_PROCESSOR_SETTINGS_SUBGROUP,                                       054533251H, 082BEH, 04824H, 096H, 0C1H, 047H, 0B6H, 00BH, 074H, 00DH, 000H
	DEFINE_GUID     GUID_PROCESSOR_THROTTLE_POLICY,                                         057027304H, 04AF6H, 04104H, 092H, 060H, 0E3H, 0D9H, 052H, 048H, 0FCH, 036H

	PERFSTATE_POLICY_CHANGE_IDEAL                               Equ         0
	PERFSTATE_POLICY_CHANGE_SINGLE                              Equ         1
	PERFSTATE_POLICY_CHANGE_ROCKET                              Equ         2
	PERFSTATE_POLICY_CHANGE_MAX                                 Equ         PERFSTATE_POLICY_CHANGE_ROCKET
ENDIF

IFNDEF GUID_PROCESSOR_THROTTLE_MAXIMUM
	DEFINE_GUID     GUID_PROCESSOR_THROTTLE_MAXIMUM,                                        0BC5038F7H, 023E0H, 04960H, 096H, 0DAH, 033H, 0ABH, 0AFH, 059H, 035H, 0ECH
	DEFINE_GUID     GUID_PROCESSOR_THROTTLE_MINIMUM,                                        0893DEE8EH, 02BEFH, 041E0H, 089H, 0C6H, 0B5H, 05DH, 009H, 029H, 096H, 04CH
	DEFINE_GUID     GUID_PROCESSOR_ALLOW_THROTTLING,                                        03B04D4FDH, 01CC7H, 04F23H, 0ABH, 01CH, 0D1H, 033H, 078H, 019H, 0C4H, 0BBH
	DEFINE_GUID     GUID_PROCESSOR_IDLESTATE_POLICY,                                        068F262A7H, 0F621H, 04069H, 0B9H, 0A5H, 048H, 074H, 016H, 09BH, 0E2H, 03CH
	DEFINE_GUID     GUID_PROCESSOR_PERFSTATE_POLICY,                                        0BBDC3814H, 018E9H, 04463H, 08AH, 055H, 0D1H, 097H, 032H, 07CH, 045H, 0C0H
	DEFINE_GUID     GUID_PROCESSOR_PERF_INCREASE_THRESHOLD,                                 006CADF0EH, 064EDH, 0448AH, 089H, 027H, 0CEH, 07BH, 0F9H, 00EH, 0B3H, 05DH
	DEFINE_GUID     GUID_PROCESSOR_PERF_DECREASE_THRESHOLD,                                 012A0AB44H, 0FE28H, 04FA9H, 0B3H, 0BDH, 04BH, 064H, 0F4H, 049H, 060H, 0A6H
	DEFINE_GUID     GUID_PROCESSOR_PERF_INCREASE_POLICY,                                    0465E1F50H, 0B610H, 0473AH, 0ABH, 058H, 000H, 0D1H, 007H, 07DH, 0C4H, 018H
	DEFINE_GUID     GUID_PROCESSOR_PERF_DECREASE_POLICY,                                    040FBEFC7H, 02E9DH, 04D25H, 0A1H, 085H, 00CH, 0FDH, 085H, 074H, 0BAH, 0C6H
	DEFINE_GUID     GUID_PROCESSOR_PERF_INCREASE_TIME,                                      0984CF492H, 03BEDH, 04488H, 0A8H, 0F9H, 042H, 086H, 0C9H, 07BH, 0F5H, 0AAH
	DEFINE_GUID     GUID_PROCESSOR_PERF_DECREASE_TIME,                                      0D8EDEB9BH, 095CFH, 04F95H, 0A7H, 03CH, 0B0H, 061H, 097H, 036H, 093H, 0C8H
	DEFINE_GUID     GUID_PROCESSOR_PERF_TIME_CHECK,                                         04D2B0152H, 07D5CH, 0498BH, 088H, 0E2H, 034H, 034H, 053H, 092H, 0A2H, 0C5H
	DEFINE_GUID     GUID_PROCESSOR_PERF_BOOST_POLICY,                                       045BCC044H, 0D885H, 043E2H, 086H, 005H, 0EEH, 00EH, 0C6H, 0E9H, 06BH, 059H

	PROCESSOR_PERF_BOOST_POLICY_DISABLED                        Equ         0
	PROCESSOR_PERF_BOOST_POLICY_MAX                             Equ         100
ENDIF

IFNDEF GUID_PROCESSOR_IDLE_ALLOW_SCALING
	DEFINE_GUID     GUID_PROCESSOR_IDLE_ALLOW_SCALING,                                      06C2993B0H, 08F48H, 0481FH, 0BCH, 0C6H, 000H, 0DDH, 027H, 042H, 0AAH, 006H
	DEFINE_GUID     GUID_PROCESSOR_IDLE_DISABLE,                                            05D76A2CAH, 0E8C0H, 0402FH, 0A1H, 033H, 021H, 058H, 049H, 02DH, 058H, 0ADH
	DEFINE_GUID     GUID_PROCESSOR_IDLE_TIME_CHECK,                                         0C4581C31H, 089ABH, 04597H, 08EH, 02BH, 09CH, 09CH, 0ABH, 044H, 00EH, 06BH
	DEFINE_GUID     GUID_PROCESSOR_IDLE_DEMOTE_THRESHOLD,                                   04B92D758H, 05A24H, 04851H, 0A4H, 070H, 081H, 05DH, 078H, 0AEH, 0E1H, 019H
	DEFINE_GUID     GUID_PROCESSOR_IDLE_PROMOTE_THRESHOLD,                                  07B224883H, 0b3CCH, 04D79H, 081H, 09FH, 083H, 074H, 015H, 02CH, 0BEH, 07CH
	DEFINE_GUID     GUID_PROCESSOR_CORE_PARKING_INCREASE_THRESHOLD,                         0DF142941H, 020F3H, 04EDfH, 09AH, 04AH, 09CH, 083H, 0D3H, 0D7H, 017H, 0D1H
	DEFINE_GUID     GUID_PROCESSOR_CORE_PARKING_DECREASE_THRESHOLD,                         068DD2F27H, 0A4CEH, 04E11H, 084H, 087H, 037H, 094H, 0E4H, 013H, 05DH, 0FAH
	DEFINE_GUID     GUID_PROCESSOR_CORE_PARKING_INCREASE_POLICY,                            0C7BE0679H, 02817H, 04D69H, 09DH, 002H, 051H, 09AH, 053H, 07EH, 0D0H, 0C6H

	CORE_PARKING_POLICY_CHANGE_IDEAL                            Equ         0
	CORE_PARKING_POLICY_CHANGE_SINGLE                           Equ         1
	CORE_PARKING_POLICY_CHANGE_ROCKET                           Equ         2
	CORE_PARKING_POLICY_CHANGE_MAX                              Equ         CORE_PARKING_POLICY_CHANGE_ROCKET
ENDIF

IFNDEF GUID_PROCESSOR_CORE_PARKING_DECREASE_POLICY
	DEFINE_GUID     GUID_PROCESSOR_CORE_PARKING_DECREASE_POLICY,                            071021B41H, 0C749H, 04D21H, 0BEH, 074H, 0A0H, 00FH, 033H, 05DH, 058H, 02BH
	DEFINE_GUID     GUID_PROCESSOR_CORE_PARKING_MAX_CORES,                                  0EA062031H, 00E34H, 04FF1H, 09BH, 06DH, 0EBH, 010H, 059H, 033H, 040H, 028H
	DEFINE_GUID     GUID_PROCESSOR_CORE_PARKING_MIN_CORES,                                  00CC5B647H, 0C1DFH, 04637H, 089H, 01AH, 0DEH, 0C3H, 05CH, 031H, 085H, 083H
	DEFINE_GUID     GUID_PROCESSOR_CORE_PARKING_INCREASE_TIME,                              02DDD5A84H, 05A71H, 0437EH, 091H, 02AH, 0DBH, 00BH, 08CH, 078H, 087H, 032H
	DEFINE_GUID     GUID_PROCESSOR_CORE_PARKING_DECREASE_TIME,                              0DFD10D17H, 0D5EBH, 045DDH, 087H, 07AH, 09AH, 034H, 0DDH, 0D1H, 05CH, 082H
	DEFINE_GUID     GUID_PROCESSOR_CORE_PARKING_AFFINITY_HISTORY_DECREASE_FACTOR,           08F7B45E3H, 0C393H, 0480AH, 087H, 08CH, 0F6H, 07AH, 0C3H, 0D0H, 070H, 082H
	DEFINE_GUID     GUID_PROCESSOR_CORE_PARKING_AFFINITY_HISTORY_THRESHOLD,                 05B33697BH, 0E89DH, 04D38H, 0AAH, 046H, 09EH, 07DH, 0FBH, 07CH, 0D2H, 0F9H
	DEFINE_GUID     GUID_PROCESSOR_CORE_PARKING_AFFINITY_WEIGHTING,                         0E70867F1H, 0FA2FH, 04F4EH, 0AEH, 0A1H, 04DH, 08AH, 00BH, 0A2H, 03BH, 020H
	DEFINE_GUID     GUID_PROCESSOR_CORE_PARKING_OVER_UTILIZATION_HISTORY_DECREASE_FACTOR,   01299023CH, 0BC28H, 04F0AH, 081H, 0ECH, 0D3H, 029H, 05AH, 08DH, 081H, 05DH
	DEFINE_GUID     GUID_PROCESSOR_CORE_PARKING_OVER_UTILIZATION_HISTORY_THRESHOLD,         09AC18E92H, 0AA3CH, 04E27H, 0B3H, 007H, 001H, 0AEH, 037H, 030H, 071H, 029H
	DEFINE_GUID     GUID_PROCESSOR_CORE_PARKING_OVER_UTILIZATION_WEIGHTING,                 08809C2D8H, 0B155H, 042D4H, 0BCH, 0DAH, 00DH, 034H, 056H, 051H, 0B1H, 0DBH
	DEFINE_GUID     GUID_PROCESSOR_CORE_PARKING_OVER_UTILIZATION_THRESHOLD,                 0943C8CB6H, 06F93H, 04227H, 0ADH, 087H, 0E9H, 0A3H, 0FEH, 0ECH, 008H, 0D1H
	DEFINE_GUID     GUID_PROCESSOR_PARKING_CORE_OVERRIDE,                                   0A55612AAH, 0F624H, 042C6H, 0A4H, 043H, 073H, 097H, 0D0H, 064H, 0C0H, 04FH
	DEFINE_GUID     GUID_PROCESSOR_PARKING_PERF_STATE,                                      0447235C7H, 06A8DH, 04CC0H, 08EH, 024H, 09EH, 0AFH, 070H, 0B9H, 06EH, 02BH
	DEFINE_GUID     GUID_PROCESSOR_PERF_HISTORY,                                            07D24BAA7H, 00B84H, 0480FH, 084H, 00CH, 01BH, 007H, 043H, 0C0H, 00FH, 05FH
	DEFINE_GUID     GUID_SYSTEM_COOLING_POLICY,                                             094D3A615H, 0A899H, 04AC5H, 0AEH, 02BH, 0E4H, 0D8H, 0F6H, 034H, 036H, 07FH
	DEFINE_GUID     GUID_LOCK_CONSOLE_ON_WAKE,                                              00E796BDBH, 0100DH, 047D6H, 0A2H, 0D5H, 0F7H, 0D2H, 0DAH, 0A5H, 01FH, 051H
	DEFINE_GUID     GUID_DEVICE_IDLE_POLICY,                                                04FAAB71AH, 092E5H, 04726H, 0B5H, 031H, 022H, 045H, 059H, 067H, 02DH, 019H

	POWER_DEVICE_IDLE_POLICY_PERFORMANCE                        Equ         0
	POWER_DEVICE_IDLE_POLICY_CONSERVATIVE                       Equ         1
ENDIF

IFNDEF GUID_ACDC_POWER_SOURCE
	DEFINE_GUID     GUID_ACDC_POWER_SOURCE,                                                 05D3E9A59H, 0E9D5H, 04B00H, 0A6H, 0BDH, 0FFH, 034H, 0FFH, 051H, 065H, 048H
	DEFINE_GUID     GUID_LIDSWITCH_STATE_CHANGE,                                            0BA3E0F4DH, 0B817H, 04094H, 0A2H, 0D1H, 0D5H, 063H, 079H, 0E6H, 0A0H, 0F3H
	DEFINE_GUID     GUID_BATTERY_PERCENTAGE_REMAINING,                                      0A7AD8041H, 0B45AH, 04CAEH, 087H, 0A3H, 0EEH, 0CBH, 0B4H, 068H, 0A9H, 0E1H
	DEFINE_GUID     GUID_IDLE_BACKGROUND_TASK,                                              0515C31D8H, 0F734H, 0163DH, 0A0H, 0FDH, 011H, 0A0H, 08CH, 091H, 0E8H, 0F1H
	DEFINE_GUID     GUID_BACKGROUND_TASK_NOTIFICATION,                                      0CF23F240H, 02A54H, 048D8H, 0B1H, 014H, 0DEH, 015H, 018H, 0FFH, 005H, 02EH
	DEFINE_GUID     GUID_APPLAUNCH_BUTTON,                                                  01A689231H, 07399H, 04E9AH, 08FH, 099H, 0B7H, 01FH, 099H, 09DH, 0B3H, 0FAH
	DEFINE_GUID     GUID_PCIEXPRESS_SETTINGS_SUBGROUP,                                      0501A4D13H, 042AFH, 04429H, 09FH, 0D1H, 0A8H, 021H, 08CH, 026H, 08EH, 020H
	DEFINE_GUID     GUID_PCIEXPRESS_ASPM_POLICY,                                            0EE12F906H, 0D277H, 0404BH, 0B6H, 0DAH, 0E5H, 0FAH, 01AH, 057H, 06DH, 0F5H
	DEFINE_GUID     GUID_ENABLE_SWITCH_FORCED_SHUTDOWN,                                     0833A6B62H, 0DFA4H, 046D1H, 082H, 0F8H, 0E0H, 09EH, 034H, 0D0H, 029H, 0D6H
ENDIF

;SYSTEM_POWER_STATE Enumeration
SYSTEM_POWER_STATE                                          TypeDef     DWord
PowerSystemUnspecified                                      Equ         0
PowerSystemWorking                                          Equ         1
PowerSystemSleeping1                                        Equ         2
PowerSystemSleeping2                                        Equ         3
PowerSystemSleeping3                                        Equ         4
PowerSystemHibernate                                        Equ         5
PowerSystemShutdown                                         Equ         6
PowerSystemMaximum                                          Equ         7
PSYSTEM_POWER_STATE                                         TypeDef     DWord

POWER_SYSTEM_MAXIMUM                                        Equ         7

;POWER_ACTION Enumeration
POWER_ACTION                                                TypeDef     DWord
PowerActionNone                                             Equ         0
PowerActionReserved                                         Equ         1
PowerActionSleep                                            Equ         2
PowerActionHibernate                                        Equ         3
PowerActionShutdown                                         Equ         4
PowerActionShutdownReset                                    Equ         5
PowerActionShutdownOff                                      Equ         6
PowerActionWarmEject                                        Equ         7
PPOWER_ACTION                                               TypeDef     DWord

;DEVICE_POWER_STATE Enumeration
DEVICE_POWER_STATE                                          TypeDef     DWord
PowerDeviceUnspecified                                      Equ         0
PowerDeviceD0                                               Equ         1
PowerDeviceD1                                               Equ         2
PowerDeviceD2                                               Equ         3
PowerDeviceD3                                               Equ         4
PowerDeviceMaximum                                          Equ         5
PDEVICE_POWER_STATE                                         TypeDef     DWord

;MONITOR_DISPLAY_STATE Enumeration
MONITOR_DISPLAY_STATE                                       TypeDef     DWord
PowerMonitorOff                                             Equ         0
PowerMonitorOn                                              Equ         1
PowerMonitorDim                                             Equ         2
PMONITOR_DISPLAY_STATE                                      TypeDef     DWord

POWER_STATE Union
    SystemState                                             SYSTEM_POWER_STATE  ?
    DeviceState                                             DEVICE_POWER_STATE  ?
POWER_STATE EndS
PPOWER_STATE                                                TypeDef     DWord

;POWER_STATE_TYPE Enumeration
POWER_STATE_TYPE                                            TypeDef     DWord
SystemPowerState                                            Equ         0
DevicePowerState                                            Equ         1
PPOWER_STATE_TYPE                                           TypeDef     DWord

IOCTL_QUERY_DEVICE_POWER_STATE                              Equ         CTL_CODE(FILE_DEVICE_BATTERY, 00H, METHOD_BUFFERED, FILE_READ_ACCESS)

IOCTL_SET_DEVICE_WAKE                                       Equ         CTL_CODE(FILE_DEVICE_BATTERY, 01H, METHOD_BUFFERED, FILE_WRITE_ACCESS)

IOCTL_CANCEL_DEVICE_WAKE                                    Equ         CTL_CODE(FILE_DEVICE_BATTERY, 02H, METHOD_BUFFERED, FILE_WRITE_ACCESS)

ES_SYSTEM_REQUIRED                                          Equ         (000000001H)
ES_DISPLAY_REQUIRED                                         Equ         (000000002H)
ES_USER_PRESENT                                             Equ         (000000004H)
ES_AWAYMODE_REQUIRED                                        Equ         (000000040H)
ES_CONTINUOUS                                               Equ         (080000000H)

EXECUTION_STATE                                             TypeDef     DWord
PEXECUTION_STATE                                            TypeDef     DWord

;LATENCY_TIME Enumeration
LATENCY_TIME                                                TypeDef     DWord
LT_DONT_CARE                                                Equ         0
LT_LOWEST_LATENCY                                           Equ         1

DIAGNOSTIC_REASON_VERSION                                   Equ         0

DIAGNOSTIC_REASON_SIMPLE_STRING                             Equ         000000001H
DIAGNOSTIC_REASON_DETAILED_STRING                           Equ         000000002H
DIAGNOSTIC_REASON_NOT_SPECIFIED                             Equ         080000000H
DIAGNOSTIC_REASON_INVALID_FLAGS                             Equ         (Not 080000003H)

POWER_REQUEST_CONTEXT_VERSION                               Equ         0

POWER_REQUEST_CONTEXT_SIMPLE_STRING                         Equ         000000001H
POWER_REQUEST_CONTEXT_DETAILED_STRING                       Equ         000000002H

;POWER_REQUEST_TYPE Enumeration
POWER_REQUEST_TYPE                                          TypeDef     DWord
PowerRequestDisplayRequired                                 Equ         0
PowerRequestSystemRequired                                  Equ         1
PowerRequestAwayModeRequired                                Equ         2
PPOWER_REQUEST_TYPE                                         TypeDef     DWord

PowerRequestMaximum                                         Equ         3

PDCAP_D0_SUPPORTED                                          Equ         000000001H
PDCAP_D1_SUPPORTED                                          Equ         000000002H
PDCAP_D2_SUPPORTED                                          Equ         000000004H
PDCAP_D3_SUPPORTED                                          Equ         000000008H
PDCAP_WAKE_FROM_D0_SUPPORTED                                Equ         000000010H
PDCAP_WAKE_FROM_D1_SUPPORTED                                Equ         000000020H
PDCAP_WAKE_FROM_D2_SUPPORTED                                Equ         000000040H
PDCAP_WAKE_FROM_D3_SUPPORTED                                Equ         000000080H
PDCAP_WARM_EJECT_SUPPORTED                                  Equ         000000100H

CM_POWER_DATA Struct
    PD_Size                                                 DD          ?
    PD_MostRecentPowerState                                 DEVICE_POWER_STATE  ?
    PD_Capabilities                                         DD          ?
    PD_D1Latency                                            DD          ?
    PD_D2Latency                                            DD          ?
    PD_D3Latency                                            DD          ?
    PD_PowerStateMapping                                    DEVICE_POWER_STATE  POWER_SYSTEM_MAXIMUM Dup(?)
    PD_DeepestSystemWake                                    SYSTEM_POWER_STATE  ?
CM_POWER_DATA EndS
PCM_POWER_DATA                                              TypeDef     DWord

;POWER_INFORMATION_LEVEL Enumeration
POWER_INFORMATION_LEVEL                                     TypeDef     DWord
SystemPowerPolicyAc                                         Equ         0
SystemPowerPolicyDc                                         Equ         1
VerifySystemPolicyAc                                        Equ         2
VerifySystemPolicyDc                                        Equ         
SystemPowerCapabilities                                     Equ         4
SystemBatteryState                                          Equ         5
SystemPowerStateHandler                                     Equ         6
ProcessorStateHandler                                       Equ         7
SystemPowerPolicyCurrent                                    Equ         8
AdministratorPowerPolicy                                    Equ         9
SystemReserveHiberFile                                      Equ         10
ProcessorInformation                                        Equ         11
SystemPowerInformation                                      Equ         12
ProcessorStateHandler2                                      Equ         13
LastWakeTime                                                Equ         14
LastSleepTime                                               Equ         15
SystemExecutionState                                        Equ         16
SystemPowerStateNotifyHandler                               Equ         17
ProcessorPowerPolicyAc                                      Equ         18
ProcessorPowerPolicyDc                                      Equ         19
VerifyProcessorPowerPolicyAc                                Equ         20
VerifyProcessorPowerPolicyDc                                Equ         21
ProcessorPowerPolicyCurrent                                 Equ         22
SystemPowerStateLogging                                     Equ         23
SystemPowerLoggingEntry                                     Equ         24
SetPowerSettingValue                                        Equ         25
NotifyUserPowerSetting                                      Equ         26
PowerInformationLevelUnused0                                Equ         27
PowerInformationLevelUnused1                                Equ         28
SystemVideoState                                            Equ         29
TraceApplicationPowerMessage                                Equ         30
TraceApplicationPowerMessageEnd                             Equ         31
ProcessorPerfStates                                         Equ         32
ProcessorIdleStates                                         Equ         33
ProcessorCap                                                Equ         34
SystemWakeSource                                            Equ         35
SystemHiberFileInformation                                  Equ         36
TraceServicePowerMessage                                    Equ         37
ProcessorLoad                                               Equ         38
PowerShutdownNotification                                   Equ         39
MonitorCapabilities                                         Equ         40
SessionPowerInit                                            Equ         41
SessionDisplayState                                         Equ         42
PowerRequestCreate                                          Equ         43
PowerRequestAction                                          Equ         44
GetPowerRequestList                                         Equ         45
ProcessorInformationEx                                      Equ         46
NotifyUserModeLegacyPowerEvent                              Equ         47
GroupPark                                                   Equ         48
ProcessorIdleDomains                                        Equ         49
WakeTimerList                                               Equ         50
SystemHiberFileSize                                         Equ         51
PowerInformationLevelMaximum                                Equ         52

;SYSTEM_POWER_CONDITION Enumeration
SYSTEM_POWER_CONDITION                                      TypeDef     DWord
PoAc                                                        Equ         0
PoDc                                                        Equ         1
PoHot                                                       Equ         2
PoConditionMaximum                                          Equ         3

SET_POWER_SETTING_VALUE Struct
    Version                                                 DD          ?
    Guid                                                    GUID        <>
    PowerCondition                                          SYSTEM_POWER_CONDITION  ?
    DataLength                                              DD          ?
    Data                                                    DB          ANYSIZE_ARRAY Dup(?)
SET_POWER_SETTING_VALUE EndS
PSET_POWER_SETTING_VALUE                                    TypeDef     DWord

POWER_SETTING_VALUE_VERSION                                 Equ         (01H)

NOTIFY_USER_POWER_SETTING Struct
    Guid                                                    GUID        <>
NOTIFY_USER_POWER_SETTING EndS
PNOTIFY_USER_POWER_SETTING                                  TypeDef     DWord

APPLICATIONLAUNCH_SETTING_VALUE Struct
    ActivationTime                                          LARGE_INTEGER   <>
    Flags                                                   DD          ?
    ButtonInstanceID                                        DD          ?
APPLICATIONLAUNCH_SETTING_VALUE EndS
PAPPLICATIONLAUNCH_SETTING_VALUE                            TypeDef     DWord

;POWER_PLATFORM_ROLE Enumeration
POWER_PLATFORM_ROLE                                         TypeDef     DWord
PlatformRoleUnspecified                                     Equ         0
PlatformRoleDesktop                                         Equ         1
PlatformRoleMobile                                          Equ         2
PlatformRoleWorkstation                                     Equ         3
PlatformRoleEnterpriseServer                                Equ         4
PlatformRoleSOHOServer                                      Equ         5
PlatformRoleAppliancePC                                     Equ         6
PlatformRolePerformanceServer                               Equ         7
PlatformRoleMaximum                                         Equ         8

BATTERY_REPORTING_SCALE Struct
    Granularity                                             DD          ?
    Capacity                                                DD          ?
BATTERY_REPORTING_SCALE EndS
PBATTERY_REPORTING_SCALE                                    TypeDef     DWord

REG_NONE                                                    Equ         (0)
REG_SZ                                                      Equ         (1)
REG_EXPAND_SZ                                               Equ         (2)

REG_BINARY                                                  Equ         (3)
REG_DWORD                                                   Equ         (4)
REG_DWORD_LITTLE_ENDIAN                                     Equ         (4)
REG_DWORD_BIG_ENDIAN                                        Equ         (5)
REG_LINK                                                    Equ         (6)
REG_MULTI_SZ                                                Equ         (7)
REG_RESOURCE_LIST                                           Equ         (8)
REG_FULL_RESOURCE_DESCRIPTOR                                Equ         (9)
REG_RESOURCE_REQUIREMENTS_LIST                              Equ         (10)
REG_QWORD                                                   Equ         (11)    ;64-bit integer
REG_QWORD_LITTLE_ENDIAN                                     Equ         (11)    ;64-bit integer

SERVICE_KERNEL_DRIVER                                       Equ         00000001H
SERVICE_FILE_SYSTEM_DRIVER                                  Equ         00000002H
SERVICE_ADAPTER                                             Equ         00000004H
SERVICE_RECOGNIZER_DRIVER                                   Equ         00000008H

SERVICE_DRIVER                                              Equ         (SERVICE_KERNEL_DRIVER Or SERVICE_FILE_SYSTEM_DRIVER Or SERVICE_RECOGNIZER_DRIVER)

SERVICE_WIN32_OWN_PROCESS                                   Equ         00000010H
SERVICE_WIN32_SHARE_PROCESS                                 Equ         00000020H
SERVICE_WIN32                                               Equ         (SERVICE_WIN32_OWN_PROCESS Or SERVICE_WIN32_SHARE_PROCESS)

SERVICE_INTERACTIVE_PROCESS                                 Equ         00000100H

SERVICE_TYPE_ALL                                            Equ         (SERVICE_WIN32 Or SERVICE_ADAPTER Or SERVICE_DRIVER Or SERVICE_INTERACTIVE_PROCESS)

SERVICE_BOOT_START                                          Equ         00000000H
SERVICE_SYSTEM_START                                        Equ         00000001H
SERVICE_AUTO_START                                          Equ         00000002H
SERVICE_DEMAND_START                                        Equ         00000003H
SERVICE_DISABLED                                            Equ         00000004H

SERVICE_ERROR_IGNORE                                        Equ         00000000H
SERVICE_ERROR_NORMAL                                        Equ         00000001H
SERVICE_ERROR_SEVERE                                        Equ         00000002H
SERVICE_ERROR_CRITICAL                                      Equ         00000003H

;SERVICE_NODE_TYPE Enumeration
SERVICE_NODE_TYPE                                           TypeDef     DWord
DriverType                                                  Equ         SERVICE_KERNEL_DRIVER
FileSystemType                                              Equ         SERVICE_FILE_SYSTEM_DRIVER
Win32ServiceOwnProcess                                      Equ         SERVICE_WIN32_OWN_PROCESS
Win32ServiceShareProcess                                    Equ         SERVICE_WIN32_SHARE_PROCESS
AdapterType                                                 Equ         SERVICE_ADAPTER
RecognizerType                                              Equ         SERVICE_RECOGNIZER_DRIVER

;SERVICE_LOAD_TYPE Enumeration
SERVICE_LOAD_TYPE                                           TypeDef     DWord
BootLoad                                                    Equ         SERVICE_BOOT_START,
SystemLoad                                                  Equ         SERVICE_SYSTEM_START
AutoLoad                                                    Equ         SERVICE_AUTO_START
DemandLoad                                                  Equ         SERVICE_DEMAND_START
DisableLoad                                                 Equ         SERVICE_DISABLED

;SERVICE_ERROR_TYPE Enumeration
SERVICE_ERROR_TYPE                                          TypeDef     DWord
IgnoreError                                                 Equ         SERVICE_ERROR_IGNORE
NormalError                                                 Equ         SERVICE_ERROR_NORMAL
SevereError                                                 Equ         SERVICE_ERROR_SEVERE
CriticalError                                               Equ         SERVICE_ERROR_CRITICAL

CM_SERVICE_NETWORK_BOOT_LOAD                                Equ         00000001H
CM_SERVICE_VIRTUAL_DISK_BOOT_LOAD                           Equ         00000002H
CM_SERVICE_USB_DISK_BOOT_LOAD                               Equ         00000004H

CM_SERVICE_VALID_PROMOTION_MASK                             Equ         (CM_SERVICE_NETWORK_BOOT_LOAD Or CM_SERVICE_VIRTUAL_DISK_BOOT_LOAD Or CM_SERVICE_USB_DISK_BOOT_LOAD)

CM_RESOURCE_TYPE                                            TypeDef     DWord

CmResourceTypeNull                                          Equ         0
CmResourceTypePort                                          Equ         1
CmResourceTypeInterrupt                                     Equ         2
CmResourceTypeMemory                                        Equ         3
CmResourceTypeDma                                           Equ         4
CmResourceTypeDeviceSpecific                                Equ         5
CmResourceTypeBusNumber                                     Equ         6
CmResourceTypeMemoryLarge                                   Equ         7
CmResourceTypeNonArbitrated                                 Equ         128
CmResourceTypeConfigData                                    Equ         128
CmResourceTypeDevicePrivate                                 Equ         129
CmResourceTypePcCardConfig                                  Equ         130
CmResourceTypeMfCardConfig                                  Equ         131

;CM_SHARE_DISPOSITION Enumeration
CM_SHARE_DISPOSITION                                        TypeDef     DWord
CmResourceShareUndetermined                                 Equ         0
CmResourceShareDeviceExclusive                              Equ         1
CmResourceShareDriverExclusive                              Equ         2
CmResourceShareShared                                       Equ         3

CM_RESOURCE_INTERRUPT_LEVEL_SENSITIVE                       Equ         0
CM_RESOURCE_INTERRUPT_LATCHED                               Equ         1
CM_RESOURCE_INTERRUPT_MESSAGE                               Equ         2
CM_RESOURCE_INTERRUPT_POLICY_INCLUDED                       Equ         4

CM_RESOURCE_INTERRUPT_LEVEL_LATCHED_BITS                    Equ         00001H

CM_RESOURCE_INTERRUPT_MESSAGE_TOKEN                         Equ         (-2)

CM_RESOURCE_MEMORY_READ_WRITE                               Equ         00000H
CM_RESOURCE_MEMORY_READ_ONLY                                Equ         00001H
CM_RESOURCE_MEMORY_WRITE_ONLY                               Equ         00002H
CM_RESOURCE_MEMORY_WRITEABILITY_MASK                        Equ         00003H
CM_RESOURCE_MEMORY_PREFETCHABLE                             Equ         00004H

CM_RESOURCE_MEMORY_COMBINEDWRITE                            Equ         00008H
CM_RESOURCE_MEMORY_24                                       Equ         00010H
CM_RESOURCE_MEMORY_CACHEABLE                                Equ         00020H
CM_RESOURCE_MEMORY_WINDOW_DECODE                            Equ         00040H
CM_RESOURCE_MEMORY_BAR                                      Equ         00080H

CM_RESOURCE_MEMORY_COMPAT_FOR_INACCESSIBLE_RANGE            Equ         00100H

CM_RESOURCE_MEMORY_LARGE                                    Equ         00E00H
CM_RESOURCE_MEMORY_LARGE_40                                 Equ         00200H
CM_RESOURCE_MEMORY_LARGE_48                                 Equ         00400H
CM_RESOURCE_MEMORY_LARGE_64                                 Equ         00800H

CM_RESOURCE_MEMORY_LARGE_40_MAXLEN                          Equ         0000000FFFFFFFF00H
CM_RESOURCE_MEMORY_LARGE_48_MAXLEN                          Equ         00000FFFFFFFF0000H
CM_RESOURCE_MEMORY_LARGE_64_MAXLEN                          Equ         0FFFFFFFF00000000H

CM_RESOURCE_PORT_MEMORY                                     Equ         00000H
CM_RESOURCE_PORT_IO                                         Equ         00001H
CM_RESOURCE_PORT_10_BIT_DECODE                              Equ         00004H
CM_RESOURCE_PORT_12_BIT_DECODE                              Equ         00008H
CM_RESOURCE_PORT_16_BIT_DECODE                              Equ         00010H
CM_RESOURCE_PORT_POSITIVE_DECODE                            Equ         00020H
CM_RESOURCE_PORT_PASSIVE_DECODE                             Equ         00040H
CM_RESOURCE_PORT_WINDOW_DECODE                              Equ         00080H
CM_RESOURCE_PORT_BAR                                        Equ         00100H

CM_RESOURCE_DMA_8                                           Equ         00000H
CM_RESOURCE_DMA_16                                          Equ         00001H
CM_RESOURCE_DMA_32                                          Equ         00002H
CM_RESOURCE_DMA_8_AND_16                                    Equ         00004H
CM_RESOURCE_DMA_BUS_MASTER                                  Equ         00008H
CM_RESOURCE_DMA_TYPE_A                                      Equ         00010H
CM_RESOURCE_DMA_TYPE_B                                      Equ         00020H
CM_RESOURCE_DMA_TYPE_F                                      Equ         00040H

CM_PARTIAL_RESOURCE_DESCRIPTOR Struct
    _Type                                                   DB          ?   ;Type
    ShareDisposition                                        DB          ?
    Flags                                                   DW          ?
    Union u
        Struct Generic
            _Start                                          PHYSICAL_ADDRESS    <>  ;Start
            _Length                                         DD          ?   ;Length
        EndS
        Struct Port
            _Start                                          PHYSICAL_ADDRESS    <>  ;Start
            _Length                                         DD          ?   ;Length
        EndS
        Struct Interrupt
            Level                                           DW          ?
            _Group                                          DW          ?   ;Group
            Vector                                          DD          ?
            Affinity                                        KAFFINITY   ?
        EndS
        Struct MessageInterrupt
            Union DUMMYUNIONNAME
               Struct Raw
                   _Group                                   DW          ?   ;Group
                   MessageCount                             DW          ?
                   Vector                                   DD          ?
                   Affinity                                 KAFFINITY   ?
               EndS
               Struct Translated
                   Level                                    DW          ?
                   _Group                                   DW          ?   ;Group
                   Vector                                   DD          ?
                   Affinity                                 KAFFINITY   ?
               EndS
            EndS
        EndS
        Struct Memory
            _Start                                          PHYSICAL_ADDRESS    <>  ;Start
            _Length                                         DD          ?   ;Length
        EndS
        Struct Dma
            Channel                                         DD          ?
            Port                                            DD          ?
            Reserved1                                       DD          ?
        EndS
        Struct DevicePrivate
            Data                                            DD          3 Dup(?)
        EndS
        Struct BusNumber
            _Start                                          DD          ?   ;Start
            _Length                                         DD          ?   ;Length
            Reserved                                        DD          ?
        EndS
        Struct DeviceSpecificData
            DataSize                                        DD          ?
            Reserved1                                       DD          ?
            Reserved2                                       DD          ?
        EndS
        Struct Memory40
            _Start                                          PHYSICAL_ADDRESS    <>  ;Start
            Length40                                        DD          ?
        EndS
        Struct Memory48
            _Start                                          PHYSICAL_ADDRESS    <>  ;Start
            Length48                                        DD          ?
        EndS
        Struct Memory64
            _Start                                          PHYSICAL_ADDRESS    <>  ;Start
            Length64                                        DD          ?
        EndS
    EndS
CM_PARTIAL_RESOURCE_DESCRIPTOR EndS
PCM_PARTIAL_RESOURCE_DESCRIPTOR                             TypeDef     DWord

CM_PARTIAL_RESOURCE_LIST Struct
    Version                                                 DW          ?
    Revision                                                DW          ?
    Count                                                   DD          ?
    PartialDescriptors                                      CM_PARTIAL_RESOURCE_DESCRIPTOR  1 Dup(<>)
CM_PARTIAL_RESOURCE_LIST EndS
PCM_PARTIAL_RESOURCE_LIST                                   TypeDef     DWord

CM_FULL_RESOURCE_DESCRIPTOR Struct
    InterfaceType                                           INTERFACE_TYPE  ?
    BusNumber                                               DD          ?
    PartialResourceList                                     CM_PARTIAL_RESOURCE_LIST    <>
CM_FULL_RESOURCE_DESCRIPTOR EndS
PCM_FULL_RESOURCE_DESCRIPTOR                                TypeDef     DWord

CM_RESOURCE_LIST Struct
    Count                                                   DD          ?
    List                                                    CM_FULL_RESOURCE_DESCRIPTOR 1 Dup(<>)
CM_RESOURCE_LIST EndS
PCM_RESOURCE_LIST                                           TypeDef     DWord

CM_ROM_BLOCK Struct
    Address                                                 DD          ?
    _Size                                                   DD          ?   ;Size
CM_ROM_BLOCK EndS
PCM_ROM_BLOCK                                               TypeDef     DWord

CM_INT13_DRIVE_PARAMETER Struct
    DriveSelect                                             DW          ?
    MaxCylinders                                            DD          ?
    SectorsPerTrack                                         DW          ?
    MaxHeads                                                DW          ?
    NumberDrives                                            DW          ?
CM_INT13_DRIVE_PARAMETER EndS
PCM_INT13_DRIVE_PARAMETER                                   TypeDef     DWord

CM_MCA_POS_DATA Struct
    AdapterId                                               DW          ?
    PosData1                                                DB          ?
    PosData2                                                DB          ?
    PosData3                                                DB          ?
    PosData4                                                DB          ?
CM_MCA_POS_DATA EndS
PCM_MCA_POS_DATA                                            TypeDef     DWord

CM_EISA_SLOT_INFORMATION Struct
    ReturnCode                                              DB          ?
    ReturnFlags                                             DB          ?
    MajorRevision                                           DB          ?
    MinorRevision                                           DB          ?
    Checksum                                                DW          ?
    NumberFunctions                                         DB          ?
    FunctionInformation                                     DB          ?
    CompressedId                                            DD          ?
CM_EISA_SLOT_INFORMATION EndS
PCM_EISA_SLOT_INFORMATION                                   TypeDef     DWord

CM_PNP_BIOS_DEVICE_NODE Struct
    _Size                                                   DW          ?   ;Size
    Node                                                    DB          ?
    ProductId                                               DD          ?
    DeviceType                                              DB          3 Dup(?)
    DeviceAttributes                                        DW          ?
CM_PNP_BIOS_DEVICE_NODE EndS
PCM_PNP_BIOS_DEVICE_NODE                                    TypeDef     DWord

CM_PNP_BIOS_INSTALLATION_CHECK Struct
    Signature                                               DB          4 Dup(?)
    Revision                                                DB          ?
    _Length                                                 DB          ?   ;Length
    ControlField                                            DW          ?
    Checksum                                                DB          ?
    EventFlagAddress                                        DD          ?
    RealModeEntryOffset                                     DW          ?
    RealModeEntrySegment                                    DW          ?
    ProtectedModeEntryOffset                                DW          ?
    ProtectedModeCodeBaseAddress                            DD          ?
    OemDeviceId                                             DD          ?
    RealModeDataBaseAddress                                 DW          ?
    ProtectedModeDataBaseAddress                            DD          ?
CM_PNP_BIOS_INSTALLATION_CHECK EndS
PCM_PNP_BIOS_INSTALLATION_CHECK                             TypeDef     DWord

EISA_FUNCTION_ENABLED                                       Equ         080H
EISA_FREE_FORM_DATA                                         Equ         040H
EISA_HAS_PORT_INIT_ENTRY                                    Equ         020H
EISA_HAS_PORT_RANGE                                         Equ         010H
EISA_HAS_DMA_ENTRY                                          Equ         008H
EISA_HAS_IRQ_ENTRY                                          Equ         004H
EISA_HAS_MEMORY_ENTRY                                       Equ         002H
EISA_HAS_TYPE_ENTRY                                         Equ         001H
EISA_HAS_INFORMATION                                        Equ         (EISA_HAS_PORT_RANGE + EISA_HAS_DMA_ENTRY + EISA_HAS_IRQ_ENTRY + EISA_HAS_MEMORY_ENTRY + EISA_HAS_TYPE_ENTRY)

EISA_MORE_ENTRIES                                           Equ         080H
EISA_SYSTEM_MEMORY                                          Equ         000H
EISA_MEMORY_TYPE_RAM                                        Equ         001H

EISA_INVALID_SLOT                                           Equ         080H
EISA_INVALID_FUNCTION                                       Equ         081H
EISA_INVALID_CONFIGURATION                                  Equ         082H
EISA_EMPTY_SLOT                                             Equ         083H
EISA_INVALID_BIOS_CALL                                      Equ         086H

CM_SCSI_DEVICE_DATA Struct
    Version                                                 DW          ?
    Revision                                                DW          ?
    HostIdentifier                                          DB          ?
CM_SCSI_DEVICE_DATA EndS
PCM_SCSI_DEVICE_DATA                                        TypeDef     DWord

CM_VIDEO_DEVICE_DATA Struct
    Version                                                 DW          ?
    Revision                                                DW          ?
    VideoClock                                              DD          ?
CM_VIDEO_DEVICE_DATA EndS
PCM_VIDEO_DEVICE_DATA                                       TypeDef     DWord

CM_SONIC_DEVICE_DATA Struct
    Version                                                 DW          ?
    Revision                                                DW          ?
    DataConfigurationRegister                               DW          ?
    EthernetAddress                                         DB          8 Dup(?)
CM_SONIC_DEVICE_DATA EndS
PCM_SONIC_DEVICE_DATA                                       TypeDef     DWord

CM_SERIAL_DEVICE_DATA Struct
    Version                                                 DW          ?
    Revision                                                DW          ?
    BaudClock                                               DD          ?
CM_SERIAL_DEVICE_DATA EndS
PCM_SERIAL_DEVICE_DATA                                      TypeDef     DWord

CM_MONITOR_DEVICE_DATA Struct
    Version                                                 DW          ?
    Revision                                                DW          ?
    HorizontalScreenSize                                    DW          ?
    VerticalScreenSize                                      DW          ?
    HorizontalResolution                                    DW          ?
    VerticalResolution                                      DW          ?
    HorizontalDisplayTimeLow                                DW          ?
    HorizontalDisplayTime                                   DW          ?
    HorizontalDisplayTimeHigh                               DW          ?
    HorizontalBackPorchLow                                  DW          ?
    HorizontalBackPorch                                     DW          ?
    HorizontalBackPorchHigh                                 DW          ?
    HorizontalFrontPorchLow                                 DW          ?
    HorizontalFrontPorch                                    DW          ?
    HorizontalFrontPorchHigh                                DW          ?
    HorizontalSyncLow                                       DW          ?
    HorizontalSync                                          DW          ?
    HorizontalSyncHigh                                      DW          ?
    VerticalBackPorchLow                                    DW          ?
    VerticalBackPorch                                       DW          ?
    VerticalBackPorchHigh                                   DW          ?
    VerticalFrontPorchLow                                   DW          ?
    VerticalFrontPorch                                      DW          ?
    VerticalFrontPorchHigh                                  DW          ?
    VerticalSyncLow                                         DW          ?
    VerticalSync                                            DW          ?
    VerticalSyncHigh                                        DW          ?
CM_MONITOR_DEVICE_DATA EndS
PCM_MONITOR_DEVICE_DATA                                     TypeDef     DWord

CM_FLOPPY_DEVICE_DATA Struct
    Version                                                 DW          ?
    Revision                                                DW          ?
    _Size                                                   DB          8 Dup(?)    ;Size
    MaxDensity                                              DD          ?
    MountDensity                                            DD          ?
    StepRateHeadUnloadTime                                  DB          ?
    HeadLoadTime                                            DB          ?
    MotorOffTime                                            DB          ?
    SectorLengthCode                                        DB          ?
    SectorPerTrack                                          DB          ?
    ReadWriteGapLength                                      DB          ?
    DataTransferLength                                      DB          ?
    FormatGapLength                                         DB          ?
    FormatFillCharacter                                     DB          ?
    HeadSettleTime                                          DB          ?
    MotorSettleTime                                         DB          ?
    MaximumTrackValue                                       DB          ?
    DataTransferRate                                        DB          ?
CM_FLOPPY_DEVICE_DATA EndS
PCM_FLOPPY_DEVICE_DATA                                      TypeDef     DWord

CM_KEYBOARD_DEVICE_DATA Struct
    Version                                                 DW          ?
    Revision                                                DW          ?
    _Type                                                   DB          ?   ;Type
    Subtype                                                 DB          ?
    KeyboardFlags                                           DW          ?
CM_KEYBOARD_DEVICE_DATA EndS
PCM_KEYBOARD_DEVICE_DATA                                    TypeDef     DWord

CM_DISK_GEOMETRY_DEVICE_DATA Struct
    BytesPerSector                                          DD          ?
    NumberOfCylinders                                       DD          ?
    SectorsPerTrack                                         DD          ?
    NumberOfHeads                                           DD          ?
CM_DISK_GEOMETRY_DEVICE_DATA EndS
PCM_DISK_GEOMETRY_DEVICE_DATA                               TypeDef     DWord

IO_RESOURCE_PREFERRED                                       Equ         001H
IO_RESOURCE_DEFAULT                                         Equ         002H
IO_RESOURCE_ALTERNATIVE                                     Equ         008H

;IRQ_DEVICE_POLICY Enumeration
IRQ_DEVICE_POLICY                                           TypeDef     Word
IrqPolicyMachineDefault                                     Equ         0
IrqPolicyAllCloseProcessors                                 Equ         1
IrqPolicyOneCloseProcessor                                  Equ         2
IrqPolicyAllProcessorsInMachine                             Equ         3
IrqPolicyAllProcessorsInGroup                               Equ         3
IrqPolicySpecifiedProcessors                                Equ         4
IrqPolicySpreadMessagesAcrossAllProcessors                  Equ         5
PIRQ_DEVICE_POLICY                                          TypeDef     DWord

;IRQ_PRIORITY Enumeration
IRQ_PRIORITY                                                TypeDef     DWord
IrqPriorityUndefined                                        Equ         0
IrqPriorityLow                                              Equ         1
IrqPriorityNormal                                           Equ         2
IrqPriorityHigh                                             Equ         3
PIRQ_PRIORITY                                               TypeDef     DWord

;IRQ_GROUP_POLICY Enumeration
IRQ_GROUP_POLICY                                            TypeDef     DWord
GroupAffinityAllGroupZero                                   Equ         0
GroupAffinityDontCare                                       Equ         1
PIRQ_GROUP_POLICY                                           TypeDef     DWord

IO_RESOURCE_DESCRIPTOR Struct
    _Option                                                 DB          ?   ;Option
    _Type                                                   DB          ?   ;Type
    ShareDisposition                                        DB          ?
    Spare1                                                  DB          ?
    Flags                                                   DW          ?
    Spare2                                                  DW          ?
    Union u
        Struct Port
            _Length                                         DD          ?   ;Length
            Alignment                                       DD          ?
            MinimumAddress                                  PHYSICAL_ADDRESS    <>
            MaximumAddress                                  PHYSICAL_ADDRESS    <>
        EndS
        Struct Memory
            _Length                                         DD          ?   ;Length
            Alignment                                       DD          ?
            MinimumAddress                                  PHYSICAL_ADDRESS    <>
            MaximumAddress                                  PHYSICAL_ADDRESS    <>
        EndS
        Struct Interrupt
            MinimumVector                                   DD          ?
            MaximumVector                                   DD          ?
            AffinityPolicy                                  IRQ_DEVICE_POLICY   ?
            _Group                                          DW          ?   ;Group
            PriorityPolicy                                  IRQ_PRIORITY    ?
            TargetedProcessors                              KAFFINITY   ?
        EndS
        Struct Dma
            MinimumChannel                                  DD          ?
            MaximumChannel                                  DD          ?
        EndS
        Struct Generic
            _Length                                         DD          ?   ;Length
            Alignment                                       DD          ?
            MinimumAddress                                  PHYSICAL_ADDRESS    <>
            MaximumAddress                                  PHYSICAL_ADDRESS    <>
        EndS
        Struct DevicePrivate
            Data                                            DD          3 Dup(?)
        EndS
        Struct BusNumber
            _Length                                         DD          ?   ;Length
            MinBusNumber                                    DD          ?
            MaxBusNumber                                    DD          ?
            Reserved                                        DD          ?
        EndS
        Struct ConfigData
            Priority                                        DD          ?
            Reserved1                                       DD          ?
            Reserved2                                       DD          ?
        EndS
        Struct Memory40
            Length40                                        DD          ?
            Alignment40                                     DD          ?
            MinimumAddress                                  PHYSICAL_ADDRESS    <>
            MaximumAddress                                  PHYSICAL_ADDRESS    <>
        EndS
        Struct Memory48
            Length48                                        DD          ?
            Alignment48                                     DD          ?
            MinimumAddress                                  PHYSICAL_ADDRESS    <>
            MaximumAddress                                  PHYSICAL_ADDRESS    <>
        EndS
        Struct Memory64
            Length64                                        DD          ?
            Alignment64                                     DD          ?
            MinimumAddress                                  PHYSICAL_ADDRESS    <>
            MaximumAddress                                  PHYSICAL_ADDRESS    <>
        EndS
    EndS
IO_RESOURCE_DESCRIPTOR EndS
PIO_RESOURCE_DESCRIPTOR                                     TypeDef     DWord

IO_RESOURCE_LIST Struct
    Version                                                 DW          ?
    Revision                                                DW          ?
    Count                                                   DD          ?
    Descriptors                                             IO_RESOURCE_DESCRIPTOR  1 Dup(<>)
IO_RESOURCE_LIST EndS
PIO_RESOURCE_LIST                                           TypeDef     DWord

IO_RESOURCE_REQUIREMENTS_LIST Struct
    ListSize                                                DD          ?
    InterfaceType                                           INTERFACE_TYPE ?
    BusNumber                                               DD          ?
    SlotNumber                                              DD          ?
    Reserved                                                DD          3 Dup(?)
    AlternativeLists                                        DD          ?
    List                                                    IO_RESOURCE_LIST    1 Dup(<>)
IO_RESOURCE_REQUIREMENTS_LIST EndS
PIO_RESOURCE_REQUIREMENTS_LIST                              TypeDef     DWord

IFDEF APP_WIN64
    PSLIST_ENTRY                                            TypeDef     DWord
    SLIST_ENTRY Struct
        Next                                                PSLIST_ENTRY    ?
    SLIST_ENTRY EndS

    SLIST_ENTRY32 Struct
        Next                                                DD          ?
    SLIST_ENTRY32 EndS
    PSLIST_ENTRY32                                          TypeDef     DWord
ELSE
    SLIST_ENTRY                                             Equ         <SINGLE_LIST_ENTRY>
    SLIST_ENTRY32                                           Equ         <SLIST_ENTRY>
    PSLIST_ENTRY                                            TypeDef     DWord
    PSLIST_ENTRY32                                          TypeDef     DWord
    PSINGLE_LIST_ENTRY                                      TypeDef     DWord
ENDIF

SLIST_HEADER Struct
    Alignment                                               DQ          ?
    Struct DUMMYSTRUCTNAME
        Next                                                SLIST_ENTRY <>
        Depth                                               DW          ?
        Sequence                                            DW          ?
    EndS
SLIST_HEADER EndS
PSLIST_HEADER                                               TypeDef     DWord
SLIST_HEADER32                                              TypeDef     SLIST_HEADER
PSLIST_HEADER32                                             TypeDef     DWord

RTL_QUERY_REGISTRY_TABLE Struct
    QueryRoutine                                            DD          ?
    Flags                                                   DD          ?
    _Name                                                   DD          ?
    EntryContext                                            PVOID       ?
    DefaultType                                             DD          ?
    DefaultData                                             PVOID       ?
    DefaultLength                                           DD          ?
RTL_QUERY_REGISTRY_TABLE EndS
PRTL_QUERY_REGISTRY_TABLE                                   TypeDef     DWord

RTL_QUERY_REGISTRY_SUBKEY                                   Equ         000000001H
RTL_QUERY_REGISTRY_TOPKEY                                   Equ         000000002H
RTL_QUERY_REGISTRY_REQUIRED                                 Equ         000000004H
RTL_QUERY_REGISTRY_NOVALUE                                  Equ         000000008H
RTL_QUERY_REGISTRY_NOEXPAND                                 Equ         000000010H
RTL_QUERY_REGISTRY_DIRECT                                   Equ         000000020H
RTL_QUERY_REGISTRY_DELETE                                   Equ         000000040H
RTL_QUERY_REGISTRY_NOSTRING                                 Equ         000000080H

RTL_REGISTRY_ABSOLUTE                                       Equ         0
RTL_REGISTRY_SERVICES                                       Equ         1
RTL_REGISTRY_CONTROL                                        Equ         2
RTL_REGISTRY_WINDOWS_NT                                     Equ         3
RTL_REGISTRY_DEVICEMAP                                      Equ         4
RTL_REGISTRY_USER                                           Equ         5
RTL_REGISTRY_MAXIMUM                                        Equ         6
RTL_REGISTRY_HANDLE                                         Equ         040000000H
RTL_REGISTRY_OPTIONAL                                       Equ         080000000H

DBG_STATUS_CONTROL_C                                        Equ         1
DBG_STATUS_SYSRQ                                            Equ         2
DBG_STATUS_BUGCHECK_FIRST                                   Equ         3
DBG_STATUS_BUGCHECK_SECOND                                  Equ         4
DBG_STATUS_FATAL                                            Equ         5
DBG_STATUS_DEBUG_CONTROL                                    Equ         6
DBG_STATUS_WORKER                                           Equ         7

TIME_FIELDS Struct
    Year                                                    CSHORT      ?
    Month                                                   CSHORT      ?
    Day                                                     CSHORT      ?
    Hour                                                    CSHORT      ?
    Minute                                                  CSHORT      ?
    Second                                                  CSHORT      ?
    Milliseconds                                            CSHORT      ?
    Weekday                                                 CSHORT      ?
TIME_FIELDS EndS
PTIME_FIELDS                                                TypeDef     DWord

SHORT_LEAST_SIGNIFICANT_BIT                                 Equ         0
SHORT_MOST_SIGNIFICANT_BIT                                  Equ         1

LONG_LEAST_SIGNIFICANT_BIT                                  Equ         0
LONG_3RD_MOST_SIGNIFICANT_BIT                               Equ         1
LONG_2ND_MOST_SIGNIFICANT_BIT                               Equ         2
LONG_MOST_SIGNIFICANT_BIT                                   Equ         3

RTL_BITMAP Struct
    SizeOfBitMap                                            DD          ?
    Buffer                                                  DD          ?
RTL_BITMAP EndS
PRTL_BITMAP                                                 TypeDef     DWord

RTL_BITMAP_RUN Struct
    StartingIndex                                           DD          ?
    NumberOfBits                                            DD          ?
RTL_BITMAP_RUN EndS
PRTL_BITMAP_RUN                                             TypeDef     DWord

TRANSACTIONMANAGER_QUERY_INFORMATION                        Equ         (0001H)
TRANSACTIONMANAGER_SET_INFORMATION                          Equ         (0002H)
TRANSACTIONMANAGER_RECOVER                                  Equ         (0004H)
TRANSACTIONMANAGER_RENAME                                   Equ         (0008H)
TRANSACTIONMANAGER_CREATE_RM                                Equ         (0010H)

TRANSACTIONMANAGER_GENERIC_READ                             Equ         (STANDARD_RIGHTS_READ Or TRANSACTIONMANAGER_QUERY_INFORMATION)
TRANSACTIONMANAGER_GENERIC_WRITE                            Equ         (STANDARD_RIGHTS_WRITE Or TRANSACTIONMANAGER_SET_INFORMATION Or TRANSACTIONMANAGER_RECOVER Or TRANSACTIONMANAGER_RENAME Or TRANSACTIONMANAGER_CREATE_RM)
TRANSACTIONMANAGER_GENERIC_EXECUTE                          Equ         (STANDARD_RIGHTS_EXECUTE)
TRANSACTIONMANAGER_ALL_ACCESS                               Equ         (STANDARD_RIGHTS_REQUIRED Or TRANSACTIONMANAGER_GENERIC_READ Or TRANSACTIONMANAGER_GENERIC_WRITE Or TRANSACTIONMANAGER_GENERIC_EXECUTE Or TRANSACTIONMANAGER_BIND_TRANSACTION)

TRANSACTION_QUERY_INFORMATION                               Equ         (0001H)
TRANSACTION_SET_INFORMATION                                 Equ         (0002H)
TRANSACTION_ENLIST                                          Equ         (0004H)
TRANSACTION_COMMIT                                          Equ         (0008H)
TRANSACTION_ROLLBACK                                        Equ         (0010H)
TRANSACTION_PROPAGATE                                       Equ         (0020H)
TRANSACTION_RIGHT_RESERVED1                                 Equ         (0040H)

TRANSACTION_GENERIC_READ                                    Equ         (STANDARD_RIGHTS_READ Or TRANSACTION_QUERY_INFORMATION Or SYNCHRONIZE)
TRANSACTION_GENERIC_WRITE                                   Equ         (STANDARD_RIGHTS_WRITE Or TRANSACTION_SET_INFORMATION Or TRANSACTION_COMMIT Or TRANSACTION_ENLIST Or TRANSACTION_ROLLBACK Or TRANSACTION_PROPAGATE Or SYNCHRONIZE)
TRANSACTION_GENERIC_EXECUTE                                 Equ         (STANDARD_RIGHTS_EXECUTE Or TRANSACTION_COMMIT Or TRANSACTION_ROLLBACK Or SYNCHRONIZE)
TRANSACTION_ALL_ACCESS                                      Equ         (STANDARD_RIGHTS_REQUIRED Or TRANSACTION_GENERIC_READ Or TRANSACTION_GENERIC_WRITE Or TRANSACTION_GENERIC_EXECUTE)
TRANSACTION_RESOURCE_MANAGER_RIGHTS                         Equ         (TRANSACTION_GENERIC_READ Or STANDARD_RIGHTS_WRITE Or TRANSACTION_SET_INFORMATION Or TRANSACTION_ENLIST Or TRANSACTION_ROLLBACK Or TRANSACTION_PROPAGATE Or SYNCHRONIZE)

RESOURCEMANAGER_QUERY_INFORMATION                           Equ         (0001H)
RESOURCEMANAGER_SET_INFORMATION                             Equ         (0002H)
RESOURCEMANAGER_RECOVER                                     Equ         (0004H)
RESOURCEMANAGER_ENLIST                                      Equ         (0008H)
RESOURCEMANAGER_GET_NOTIFICATION                            Equ         (0010H)
RESOURCEMANAGER_REGISTER_PROTOCOL                           Equ         (0020H)
RESOURCEMANAGER_COMPLETE_PROPAGATION                        Equ         (0040H)

RESOURCEMANAGER_GENERIC_READ                                Equ         (STANDARD_RIGHTS_READ Or RESOURCEMANAGER_QUERY_INFORMATION Or SYNCHRONIZE)
RESOURCEMANAGER_GENERIC_WRITE                               Equ         (STANDARD_RIGHTS_WRITE Or RESOURCEMANAGER_SET_INFORMATION Or RESOURCEMANAGER_RECOVER Or RESOURCEMANAGER_ENLIST Or RESOURCEMANAGER_GET_NOTIFICATION Or RESOURCEMANAGER_REGISTER_PROTOCOL Or RESOURCEMANAGER_COMPLETE_PROPAGATION Or SYNCHRONIZE)
RESOURCEMANAGER_GENERIC_EXECUTE                             Equ         (STANDARD_RIGHTS_EXECUTE Or RESOURCEMANAGER_RECOVER Or RESOURCEMANAGER_ENLIST Or RESOURCEMANAGER_GET_NOTIFICATION Or RESOURCEMANAGER_COMPLETE_PROPAGATION Or SYNCHRONIZE)
RESOURCEMANAGER_ALL_ACCESS                                  Equ         (STANDARD_RIGHTS_REQUIRED Or RESOURCEMANAGER_GENERIC_READ Or RESOURCEMANAGER_GENERIC_WRITE Or RESOURCEMANAGER_GENERIC_EXECUTE)

ENLISTMENT_QUERY_INFORMATION                                Equ         (0001H)
ENLISTMENT_SET_INFORMATION                                  Equ         (0002H)
ENLISTMENT_RECOVER                                          Equ         (0004H)
ENLISTMENT_SUBORDINATE_RIGHTS                               Equ         (0008H)
ENLISTMENT_SUPERIOR_RIGHTS                                  Equ         (0010H)

ENLISTMENT_GENERIC_READ                                     Equ         (STANDARD_RIGHTS_READ Or ENLISTMENT_QUERY_INFORMATION)
ENLISTMENT_GENERIC_WRITE                                    Equ         (STANDARD_RIGHTS_WRITE Or ENLISTMENT_SET_INFORMATION Or ENLISTMENT_RECOVER Or ENLISTMENT_SUBORDINATE_RIGHTS Or ENLISTMENT_SUPERIOR_RIGHTS)
ENLISTMENT_GENERIC_EXECUTE                                  Equ         (STANDARD_RIGHTS_EXECUTE Or ENLISTMENT_RECOVER Or ENLISTMENT_SUBORDINATE_RIGHTS Or ENLISTMENT_SUPERIOR_RIGHTS)
ENLISTMENT_ALL_ACCESS                                       Equ         (STANDARD_RIGHTS_REQUIRED Or ENLISTMENT_GENERIC_READ Or ENLISTMENT_GENERIC_WRITE Or ENLISTMENT_GENERIC_EXECUTE)

;TRANSACTION_OUTCOME Enumeration
TRANSACTION_OUTCOME                                         TypeDef     DWord
TransactionOutcomeUndetermined                              Equ         1
TransactionOutcomeCommitted                                 Equ         2
TransactionOutcomeAborted                                   Equ         3

;TRANSACTION_STATE Enumeration
TRANSACTION_STATE                                           TypeDef     DWord
TransactionStateNormal                                      Equ         1
TransactionStateIndoubt                                     Equ         2
TransactionStateCommittedNotify                             Equ         3

TRANSACTION_BASIC_INFORMATION Struct
    TransactionId                                           GUID        <>
    State                                                   DD          ?
    Outcome                                                 DD          ?
TRANSACTION_BASIC_INFORMATION EndS
PTRANSACTION_BASIC_INFORMATION                              TypeDef     DWord

TRANSACTIONMANAGER_BASIC_INFORMATION Struct
    TmIdentity                                              GUID        <>
    VirtualClock                                            LARGE_INTEGER   <>
TRANSACTIONMANAGER_BASIC_INFORMATION EndS
PTRANSACTIONMANAGER_BASIC_INFORMATION                       TypeDef     DWord

TRANSACTIONMANAGER_LOG_INFORMATION Struct
    LogIdentity                                             GUID        <>
TRANSACTIONMANAGER_LOG_INFORMATION EndS
PTRANSACTIONMANAGER_LOG_INFORMATION                         TypeDef     DWord

TRANSACTIONMANAGER_RECOVERY_INFORMATION Struct
    LastRecoveredLsn                                        DQ          ?
TRANSACTIONMANAGER_RECOVERY_INFORMATION EndS
PTRANSACTIONMANAGER_RECOVERY_INFORMATION                    TypeDef     DWord

TRANSACTION_PROPERTIES_INFORMATION Struct
    IsolationLevel                                          DD          ?
    IsolationFlags                                          DD          ?
    Timeout                                                 LARGE_INTEGER   <>
    Outcome                                                 DD          ?
    DescriptionLength                                       DD          ?
    Description                                             DW          1 Dup(?)
TRANSACTION_PROPERTIES_INFORMATION EndS
PTRANSACTION_PROPERTIES_INFORMATION                         TypeDef     DWord

TRANSACTION_BIND_INFORMATION Struct
    TmHandle                                                HANDLE      ?
TRANSACTION_BIND_INFORMATION EndS
PTRANSACTION_BIND_INFORMATION                               TypeDef     DWord

TRANSACTION_ENLISTMENT_PAIR Struct
    EnlistmentId                                            GUID        <>
    ResourceManagerId                                       GUID        <>
TRANSACTION_ENLISTMENT_PAIR EndS
PTRANSACTION_ENLISTMENT_PAIR                                TypeDef     DWord

TRANSACTION_ENLISTMENTS_INFORMATION Struct
    NumberOfEnlistments                                     DD          ?
    EnlistmentPair                                          TRANSACTION_ENLISTMENT_PAIR 1 Dup(<>)
TRANSACTION_ENLISTMENTS_INFORMATION EndS
PTRANSACTION_ENLISTMENTS_INFORMATION                        TypeDef     DWord

TRANSACTION_SUPERIOR_ENLISTMENT_INFORMATION Struct
    SuperiorEnlistmentPair                                  TRANSACTION_ENLISTMENT_PAIR <>
TRANSACTION_SUPERIOR_ENLISTMENT_INFORMATION EndS
PTRANSACTION_SUPERIOR_ENLISTMENT_INFORMATION                TypeDef     DWord

RESOURCEMANAGER_BASIC_INFORMATION Struct
    ResourceManagerId                                       GUID        <>
    DescriptionLength                                       DD          ?
    Description                                             DW          1 Dup(?)
RESOURCEMANAGER_BASIC_INFORMATION EndS
PRESOURCEMANAGER_BASIC_INFORMATION                          TypeDef     DWord

RESOURCEMANAGER_COMPLETION_INFORMATION Struct
    IoCompletionPortHandle                                  HANDLE      ?
    CompletionKey                                           DD          ?
RESOURCEMANAGER_COMPLETION_INFORMATION EndS
PRESOURCEMANAGER_COMPLETION_INFORMATION                     TypeDef     DWord

;TRANSACTION_INFORMATION_CLASS Enumeration
TRANSACTION_INFORMATION_CLASS                               TypeDef     DWord
TransactionBasicInformation                                 Equ         0
TransactionPropertiesInformation                            Equ         1
TransactionEnlistmentInformation                            Equ         2
TransactionSuperiorEnlistmentInformation                    Equ         3

;TRANSACTIONMANAGER_INFORMATION_CLASS Enumeration
TRANSACTIONMANAGER_INFORMATION_CLASS                        TypeDef     DWord
TransactionManagerBasicInformation                          Equ         0
TransactionManagerLogInformation                            Equ         1
TransactionManagerLogPathInformation                        Equ         2
TransactionManagerRecoveryInformation                       Equ         4

;RESOURCEMANAGER_INFORMATION_CLASS Enumeration
RESOURCEMANAGER_INFORMATION_CLASS                           TypeDef     DWord
ResourceManagerBasicInformation                             Equ         0
ResourceManagerCompletionInformation                        Equ         1

ENLISTMENT_BASIC_INFORMATION Struct
    EnlistmentId                                            GUID        <>
    TransactionId                                           GUID        <>
    ResourceManagerId                                       GUID        <>
ENLISTMENT_BASIC_INFORMATION EndS
PENLISTMENT_BASIC_INFORMATION                               TypeDef     DWord

ENLISTMENT_CRM_INFORMATION Struct
    CrmTransactionManagerId                                 GUID        <>
    CrmResourceManagerId                                    GUID        <>
    CrmEnlistmentId                                         GUID        <>
ENLISTMENT_CRM_INFORMATION EndS
PENLISTMENT_CRM_INFORMATION                                 TypeDef     DWord

;ENLISTMENT_INFORMATION_CLASS Enumeration
ENLISTMENT_INFORMATION_CLASS                                TypeDef     DWord
EnlistmentBasicInformation                                  Equ         0
EnlistmentRecoveryInformation                               Equ         1
EnlistmentCrmInformation                                    Equ         2

TRANSACTION_LIST_ENTRY Struct
    Uow                                                     UOW         <>
TRANSACTION_LIST_ENTRY EndS
PTRANSACTION_LIST_ENTRY                                     TypeDef     DWord

TRANSACTION_LIST_INFORMATION Struct
    NumberOfTransactions                                    DD          ?
    TransactionInformation                                  TRANSACTION_LIST_ENTRY  1 Dup(<>)
TRANSACTION_LIST_INFORMATION EndS
PTRANSACTION_LIST_INFORMATION                               TypeDef     DWord

;KTMOBJECT_TYPE Enumeration
KTMOBJECT_TYPE                                              TypeDef     DWord
KTMOBJECT_TRANSACTION                                       Equ         0
KTMOBJECT_TRANSACTION_MANAGER                               Equ         1
KTMOBJECT_RESOURCE_MANAGER                                  Equ         2
KTMOBJECT_ENLISTMENT                                        Equ         3
KTMOBJECT_INVALID                                           Equ         4
PKTMOBJECT_TYPE                                             TypeDef     DWord

KTMOBJECT_CURSOR Struct
    LastQuery                                               GUID        <>
    ObjectIdCount                                           DD          ?
    ObjectIds                                               GUID        1 Dup(<>)
KTMOBJECT_CURSOR EndS
PKTMOBJECT_CURSOR                                           TypeDef     DWord

KAPC Struct
    _Type                                                   DB          ?   ;Type
    SpareByte0                                              DB          ?
    _Size                                                   DB          ?   ;Size
    SpareByte1                                              DB          ?
    SpareLong0                                              DD          ?
    Thread                                                  DD          ?
    ApcListEntry                                            LIST_ENTRY  <>
    KernelRoutine                                           DD          ?
    RundownRoutine                                          DD          ?
    NormalRoutine                                           DD          ?
    NormalContext                                           PVOID       ?
    SystemArgument1                                         PVOID       ?
    SystemArgument2                                         PVOID       ?
    ApcStateIndex                                           DB          ?
    ApcMode                                                 KPROCESSOR_MODE ?
    Inserted                                                BOOLEAN     ?
                                                            DB          ? ; padding
KAPC EndS
PKAPC                                                       TypeDef     DWord

;KDPC_IMPORTANCE Enumeration
KDPC_IMPORTANCE                                             TypeDef     DWord
LowImportance                                               Equ         0
MediumImportance                                            Equ         1
HighImportance                                              Equ         2
MediumHighImportance                                        Equ         3

DPC_NORMAL                                                  Equ         0
DPC_THREADED                                                Equ         1

KDPC Struct
    _Type                                                   DB          ?   ;Type
    Importance                                              DB          ?
    Number                                                  DW          ?
    DpcListEntry                                            LIST_ENTRY  <>
    DeferredRoutine                                         DD          ?
    DeferredContext                                         PVOID       ?
    SystemArgument1                                         PVOID       ?
    SystemArgument2                                         PVOID       ?
    DpcData                                                 PVOID       ?
KDPC EndS
PKDPC                                                       TypeDef     DWord

PKIPI_CONTEXT                                               TypeDef     DWord

KIPI_COUNTS Struct
    Freeze                                                  DD          ?
    Packet                                                  DD          ?
    DPC                                                     DD          ?
    APC                                                     DD          ?
    FlushSingleTb                                           DD          ?
    FlushMultipleTb                                         DD          ?
    FlushEntireTb                                           DD          ?
    GenericCall                                             DD          ?
    ChangeColor                                             DD          ?
    SweepDcache                                             DD          ?
    SweepIcache                                             DD          ?
    SweepIcacheRange                                        DD          ?
    FlushIoBuffers                                          DD          ?
    GratuitousDPC                                           DD          ?
KIPI_COUNTS EndS
PKIPI_COUNTS                                                TypeDef     DWord

MDL Struct
    Next                                                    DD          ?
    _Size                                                   DW          ?   ;Size
    MdlFlags                                                DW          ?
    Process                                                 DD          ?
    MappedSystemVa                                          PVOID       ?
    StartVa                                                 PVOID       ?
    ByteCount                                               DD          ?
    ByteOffset                                              DD          ?
MDL EndS
PMDL                                                        TypeDef     DWord

MDL_MAPPED_TO_SYSTEM_VA                                     Equ         0001H
MDL_PAGES_LOCKED                                            Equ         0002H
MDL_SOURCE_IS_NONPAGED_POOL                                 Equ         0004H
MDL_ALLOCATED_FIXED_SIZE                                    Equ         0008H
MDL_PARTIAL                                                 Equ         0010H
MDL_PARTIAL_HAS_BEEN_MAPPED                                 Equ         0020H
MDL_IO_PAGE_READ                                            Equ         0040H
MDL_WRITE_OPERATION                                         Equ         0080H
MDL_PARENT_MAPPED_SYSTEM_VA                                 Equ         0100H
MDL_FREE_EXTRA_PTES                                         Equ         0200H
MDL_DESCRIBES_AWE                                           Equ         0400H
MDL_IO_SPACE                                                Equ         0800H
MDL_NETWORK_HEADER                                          Equ         1000H
MDL_MAPPING_CAN_FAIL                                        Equ         2000H
MDL_ALLOCATED_MUST_SUCCEED                                  Equ         4000H
MDL_INTERNAL                                                Equ         8000H

MDL_MAPPING_FLAGS                                           Equ         (MDL_MAPPED_TO_SYSTEM_VA Or MDL_PAGES_LOCKED Or MDL_SOURCE_IS_NONPAGED_POOL Or MDL_PARTIAL_HAS_BEEN_MAPPED Or MDL_PARENT_MAPPED_SYSTEM_VA Or MDL_SYSTEM_VA Or MDL_IO_SPACE)

TIMER_EXPIRED_INDEX_BITS                                    Equ         6
TIMER_PROCESSOR_INDEX_BITS                                  Equ         5

;LOCK_OPERATION Enumeration
LOCK_OPERATION                                              TypeDef     DWord
IoReadAccess                                                Equ         0
IoWriteAccess                                               Equ         1
IoModifyAccess                                              Equ         2

PFN_COUNT                                                   TypeDef     DWord

SPFN_NUMBER                                                 TypeDef     DWord
PFN_NUMBER                                                  TypeDef     DWord
PSPFN_NUMBER                                                TypeDef     DWord
PPFN_NUMBER                                                 TypeDef     DWord

FLUSH_MULTIPLE_MAXIMUM                                      Equ         32

KFLOATING_SAVE Struct
    ControlWord                                             DD          ?
    StatusWord                                              DD          ?
    ErrorOffset                                             DD          ?
    ErrorSelector                                           DD          ?
    DataOffset                                              DD          ?
    DataSelector                                            DD          ?
    Cr0NpxState                                             DD          ?
    Spare1                                                  DD          ?
KFLOATING_SAVE EndS
PKFLOATING_SAVE                                             TypeDef     DWord

;INTEL_CACHE_TYPE Enumeration
INTEL_CACHE_TYPE                                            TypeDef     DWord
IntelCacheNull                                              Equ         0
IntelCacheData                                              Equ         1
IntelCacheInstruction                                       Equ         2
IntelCacheUnified                                           Equ         3
IntelCacheRam                                               Equ         4
IntelCacheTrace                                             Equ         5

PAGE_SIZE                                                   Equ         1000H

PAGE_SHIFT                                                  Equ         12

KIP0PCRADDRESS                                              Equ         0FFDFF000H

KI_USER_SHARED_DATA                                         Equ         0FFDF0000H

EFLAG_SIGN                                                  Equ         8000H
EFLAG_ZERO                                                  Equ         4000H
EFLAG_SELECT                                                Equ         (EFLAG_SIGN Or EFLAG_ZERO)

PAGE_SIZE                                                   Equ         1000H

PAGE_SHIFT                                                  Equ         12

MAXIMUM_VECTOR                                              Equ         256

EVENT_QUERY_STATE                                           Equ         0001H
EVENT_MODIFY_STATE                                          Equ         0002H
EVENT_ALL_ACCESS                                            Equ         (STANDARD_RIGHTS_REQUIRED Or SYNCHRONIZE Or 03H) 

SEMAPHORE_QUERY_STATE                                       Equ         0001H
SEMAPHORE_MODIFY_STATE                                      Equ         0002H
SEMAPHORE_ALL_ACCESS                                        Equ         (STANDARD_RIGHTS_REQUIRED Or SYNCHRONIZE Or 03H)

;LOGICAL_PROCESSOR_RELATIONSHIP Enumeration
LOGICAL_PROCESSOR_RELATIONSHIP                              TypeDef     DWord
RelationProcessorCore                                       Equ         0
RelationNumaNode                                            Equ         1
RelationCache                                               Equ         2
RelationProcessorPackage                                    Equ         3
RelationGroup                                               Equ         4
RelationAll                                                 Equ         0FFFFH

LTP_PC_SMT                                                  Equ         01H

;PROCESSOR_CACHE_TYPE Enumeration
PROCESSOR_CACHE_TYPE                                        TypeDef     DWord
CacheUnified                                                Equ         0
CacheInstruction                                            Equ         1
CacheData                                                   Equ         2
CacheTrace                                                  Equ         3

CACHE_FULLY_ASSOCIATIVE                                     Equ         0FFH

CACHE_DESCRIPTOR Struct
    Level                                                   DB          ?
    Associativity                                           DB          ?
    LineSize                                                DW          ?
    _Size                                                   DD          ?   ;Size
    _Type                                                   PROCESSOR_CACHE_TYPE ?  ;Type
CACHE_DESCRIPTOR EndS
PCACHE_DESCRIPTOR                                           TypeDef     DWord

SYSTEM_LOGICAL_PROCESSOR_INFORMATION Struct
    ProcessorMask                                           DD          ?
    Relationship                                            LOGICAL_PROCESSOR_RELATIONSHIP ?
    Union DUMMYUNIONNAME
        Struct ProcessorCore
            Flags                                           DB          ?
        EndS
        Struct NumaNode
            NodeNumber                                      DD          ?
        EndS
        Cache                                               CACHE_DESCRIPTOR    <>
        Reserved                                            DQ          2 Dup(?)
    EndS
SYSTEM_LOGICAL_PROCESSOR_INFORMATION EndS
PSYSTEM_LOGICAL_PROCESSOR_INFORMATION                       TypeDef     DWord

PROCESSOR_RELATIONSHIP Struct
    Flags                                                   DB          ?
    Reserved                                                DB          21 Dup(?)
    GroupCount                                              DW          ?
    GroupMask                                               GROUP_AFFINITY  ANYSIZE_ARRAY Dup(<>)
PROCESSOR_RELATIONSHIP EndS
PPROCESSOR_RELATIONSHIP                                     TypeDef     DWord

NUMA_NODE_RELATIONSHIP Struct
    NodeNumber                                              DD          ?
    Reserved                                                DB          20 Dup(?)
    GroupMask                                               GROUP_AFFINITY  <>
NUMA_NODE_RELATIONSHIP EndS
PNUMA_NODE_RELATIONSHIP                                     TypeDef     DWord

CACHE_RELATIONSHIP Struct
    Level                                                   DB          ?
    Associativity                                           DB          ?
    LineSize                                                DW          ?
    CacheSize                                               DD          ?
    _Type                                                   PROCESSOR_CACHE_TYPE ?   ;Type
    Reserved                                                DB          20 Dup (?)
    GroupMask                                               GROUP_AFFINITY  <>
CACHE_RELATIONSHIP EndS
PCACHE_RELATIONSHIP                                         TypeDef     DWord

PROCESSOR_GROUP_INFO Struct
    MaximumProcessorCount                                   DB          ?
    ActiveProcessorCount                                    DB          ?
    Reserved                                                DB          38 Dup(?)
    ActiveProcessorMask                                     KAFFINITY   ?
PROCESSOR_GROUP_INFO EndS
PPROCESSOR_GROUP_INFO                                       TypeDef     DWord

GROUP_RELATIONSHIP Struct
    MaximumGroupCount                                       DW          ?
    ActiveGroupCount                                        DW          ?
    Reserved                                                DB          20 Dup(?)
    GroupInfo                                               PROCESSOR_GROUP_INFO    ANYSIZE_ARRAY Dup(<>)
GROUP_RELATIONSHIP EndS
PGROUP_RELATIONSHIP                                         TypeDef     DWord

PF_FLOATING_POINT_PRECISION_ERRATA                          Equ         0
PF_FLOATING_POINT_EMULATED                                  Equ         1
PF_COMPARE_EXCHANGE_DOUBLE                                  Equ         2
PF_MMX_INSTRUCTIONS_AVAILABLE                               Equ         3
PF_PPC_MOVEMEM_64BIT_OK                                     Equ         4
PF_ALPHA_BYTE_INSTRUCTIONS                                  Equ         5
PF_XMMI_INSTRUCTIONS_AVAILABLE                              Equ         6
PF_3DNOW_INSTRUCTIONS_AVAILABLE                             Equ         7
PF_RDTSC_INSTRUCTION_AVAILABLE                              Equ         8
PF_PAE_ENABLED                                              Equ         9
PF_XMMI64_INSTRUCTIONS_AVAILABLE                            Equ         10
PF_SSE_DAZ_MODE_AVAILABLE                                   Equ         11
PF_NX_ENABLED                                               Equ         12
PF_SSE3_INSTRUCTIONS_AVAILABLE                              Equ         13
PF_COMPARE_EXCHANGE128                                      Equ         14
PF_COMPARE64_EXCHANGE128                                    Equ         15
PF_CHANNELS_ENABLED                                         Equ         16
PF_XSAVE_ENABLED                                            Equ         17

;ALTERNATIVE_ARCHITECTURE_TYPE Enumeration
ALTERNATIVE_ARCHITECTURE_TYPE                               TypeDef     DWord
StandardDesign                                              Equ         0
NEC98x86                                                    Equ         1
EndAlternatives                                             Equ         2

PROCESSOR_FEATURE_MAX                                       Equ         64

EXCEPTION_NONCONTINUABLE                                    Equ         01H

IFNDEF EXCEPTION_MAXIMUM_PARAMETERS
    EXCEPTION_MAXIMUM_PARAMETERS                            Equ         15
ENDIF

SIZE_OF_80387_REGISTERS                                     Equ         80

FLOATING_SAVE_AREA Struct
    ControlWord                                             DD          ?
    StatusWord                                              DD          ?
    TagWord                                                 DD          ?
    ErrorOffset                                             DD          ?
    ErrorSelector                                           DD          ?
    DataOffset                                              DD          ?
    DataSelector                                            DD          ?
    RegisterArea                                            DB          SIZE_OF_80387_REGISTERS Dup(?)
    Cr0NpxState                                             DD          ?
FLOATING_SAVE_AREA EndS
PFLOATING_SAVE_AREA                                         TypeDef     DWord

CONTEXT Struct
    ContextFlags                                            DD          ?
    _Dr0                                                    DD          ?
    _Dr1                                                    DD          ?
    _Dr2                                                    DD          ?
    _Dr3                                                    DD          ?
    _Dr6                                                    DD          ?
    _Dr7                                                    DD          ?
    FloatSave                                               FLOATING_SAVE_AREA  <>
    SegGs                                                   DD          ?
    SegFs                                                   DD          ?
    SegEs                                                   DD          ?
    SegDs                                                   DD          ?
    _Edi                                                    DD          ?
    _Esi                                                    DD          ?
    _Ebx                                                    DD          ?
    _Edx                                                    DD          ?
    _Ecx                                                    DD          ?
    _Eax                                                    DD          ?
    _Ebp                                                    DD          ?
    _Eip                                                    DD          ?
    SegCs                                                   DD          ?
    EFlags                                                  DD          ?
    _Esp                                                    DD          ?
    SegSs                                                   DD          ?
    ExtendedRegisters                                       DB          MAXIMUM_SUPPORTED_EXTENSION Dup(?)
CONTEXT Ends
PCONTEXT                                                    TypeDef     DWord

EXCEPTION_RECORD Struct
    ExceptionCode                                           NTSTATUS    ?
    ExceptionFlags                                          DD          ?
    ExceptionRecord                                         DD          ?
    ExceptionAddress                                        PVOID       ?
    NumberParameters                                        DD          ?
    ExceptionInformation                                    DD          EXCEPTION_MAXIMUM_PARAMETERS Dup(?)
EXCEPTION_RECORD EndS
PEXCEPTION_RECORD                                           TypeDef     DWord

EXCEPTION_RECORD32 Struct
    ExceptionCode                                           NTSTATUS    ?
    ExceptionFlags                                          DD          ?
    ExceptionRecord                                         DD          ?
    ExceptionAddress                                        DD          ?
    NumberParameters                                        DD          ?
    ExceptionInformation                                    DD          EXCEPTION_MAXIMUM_PARAMETERS Dup(?)
EXCEPTION_RECORD32 EndS
PEXCEPTION_RECORD32                                         TypeDef     DWord

EXCEPTION_RECORD64 Struct
    ExceptionCode                                           NTSTATUS    ?
    ExceptionFlags                                          DD          ?
    ExceptionRecord                                         DQ          ?
    ExceptionAddress                                        DQ          ?
    NumberParameters                                        DD          ?
    __unusedAlignment                                       DD          ?
    ExceptionInformation                                    DQ          EXCEPTION_MAXIMUM_PARAMETERS Dup(?)
EXCEPTION_RECORD64 EndS
PEXCEPTION_RECORD64                                         TypeDef     DWord

EXCEPTION_POINTERS Struct
    ExceptionRecord                                         PEXCEPTION_RECORD   ?
    ContextRecord                                           PCONTEXT    ?
EXCEPTION_POINTERS EndS
PEXCEPTION_POINTERS                                         TypeDef     DWord

THREAD_WAIT_OBJECTS                                         Equ         3

;KINTERRUPT_MODE Enumeration
KINTERRUPT_MODE                                             TypeDef     DWord
LevelSensitive                                              Equ         0
Latched                                                     Equ         1

;KINTERRUPT_POLARITY Enumeration
KINTERRUPT_POLARITY                                         TypeDef     DWord
InterruptPolarityUnknown                                    Equ         0
InterruptActiveHigh                                         Equ         1
InterruptActiveLow                                          Equ         2
PKINTERRUPT_POLARITY                                        TypeDef     DWord

;KWAIT_REASON Enumeration
KWAIT_REASON                                                TypeDef     DWord
Executive                                                   Equ         0
FreePage                                                    Equ         1
PageIn                                                      Equ         2
PoolAllocation                                              Equ         3
DelayExecution                                              Equ         4
Suspended                                                   Equ         5
UserRequest                                                 Equ         6
WrExecutive                                                 Equ         7
WrFreePage                                                  Equ         8
WrPageIn                                                    Equ         9
WrPoolAllocation                                            Equ         10
WrDelayExecution                                            Equ         11
WrSuspended                                                 Equ         12
WrUserRequest                                               Equ         13
WrEventPair                                                 Equ         14
WrQueue                                                     Equ         15
WrLpcReceive                                                Equ         16
WrLpcReply                                                  Equ         17
WrVirtualMemory                                             Equ         18
WrPageOut                                                   Equ         19
WrRendezvous                                                Equ         20
WrKeyedEvent                                                Equ         21
WrTerminated                                                Equ         22
WrProcessInSwap                                             Equ         23
WrCpuRateControl                                            Equ         24
WrCalloutStack                                              Equ         25
WrKernel                                                    Equ         26
WrResource                                                  Equ         27
WrPushLock                                                  Equ         28
WrMutex                                                     Equ         29
WrQuantumEnd                                                Equ         30
WrDispatchInt                                               Equ         31
WrPreempted                                                 Equ         32
WrYieldExecution                                            Equ         33
WrFastMutex                                                 Equ         34
WrGuardedMutex                                              Equ         35
WrRundown                                                   Equ         36
MaximumWaitReason                                           Equ         37

KWAIT_BLOCK Struct
    WaitListEntry                                           LIST_ENTRY  <>
    Thread                                                  DD          ?
    Object                                                  PVOID       ?
    NextWaitBlock                                           DD          ?
    WaitKey                                                 DW          ?
    WaitType                                                DB          ?
    BlockState                                              DB          ?
    IFDEF APP_WIN64
        SpareLong                                           DD          ?
    ENDIF
KWAIT_BLOCK EndS
PKWAIT_BLOCK                                                TypeDef     DWord

KDEVICE_QUEUE_ENTRY Struct
    DeviceListEntry                                         LIST_ENTRY  <>
    SortKey                                                 DD          ?
    Inserted                                                BOOLEAN     ?
                                                            DB          3 Dup (?) ; padding
KDEVICE_QUEUE_ENTRY EndS
PKDEVICE_QUEUE_ENTRY                                        TypeDef     DWord

;KBUGCHECK_CALLBACK_REASON Enumeration
KBUGCHECK_CALLBACK_REASON                                   TypeDef     DWord
KbCallbackInvalid                                           Equ         0
KbCallbackReserved1                                         Equ         1
KbCallbackSecondaryDumpData                                 Equ         2
KbCallbackDumpIo                                            Equ         3
KbCallbackAddPages                                          Equ         4

KBUGCHECK_SECONDARY_DUMP_DATA Struct
    InBuffer                                                PVOID       ?
    InBufferLength                                          DD          ?
    MaximumAllowed                                          DD          ?
    Guid                                                    GUID        <>
    OutBuffer                                               PVOID       ?
    OutBufferLength                                         DD          ?
KBUGCHECK_SECONDARY_DUMP_DATA EndS
PKBUGCHECK_SECONDARY_DUMP_DATA                              TypeDef     DWord

KB_ADD_PAGES_FLAG_VIRTUAL_ADDRESS                           Equ         00000001H
KB_ADD_PAGES_FLAG_PHYSICAL_ADDRESS                          Equ         00000002H
KB_ADD_PAGES_FLAG_ADDITIONAL_RANGES_EXIST                   Equ         80000000H

KBUGCHECK_ADD_PAGES Struct
    Context                                                 PVOID       ?
    Flags                                                   DD          ?
    BugCheckCode                                            DD          ?
    Address                                                 DD          ?
    Count                                                   DD          ?
KBUGCHECK_ADD_PAGES EndS
PKBUGCHECK_ADD_PAGES                                        TypeDef     DWord

EXCEPTION_DIVIDED_BY_ZERO                                   Equ         0
EXCEPTION_DEBUG                                             Equ         1
EXCEPTION_NMI                                               Equ         2
EXCEPTION_INT3                                              Equ         3
EXCEPTION_BOUND_CHECK                                       Equ         5
EXCEPTION_INVALID_OPCODE                                    Equ         6
EXCEPTION_NPX_NOT_AVAILABLE                                 Equ         7
EXCEPTION_DOUBLE_FAULT                                      Equ         8
EXCEPTION_NPX_OVERRUN                                       Equ         9
EXCEPTION_INVALID_TSS                                       Equ         0AH
EXCEPTION_SEGMENT_NOT_PRESENT                               Equ         0BH
EXCEPTION_STACK_FAULT                                       Equ         0CH
EXCEPTION_GP_FAULT                                          Equ         0DH
EXCEPTION_RESERVED_TRAP                                     Equ         0FH
EXCEPTION_NPX_ERROR                                         Equ         010H
EXCEPTION_ALIGNMENT_CHECK                                   Equ         011H

;MEMORY_CACHING_TYPE_ORIG Enumeration
MEMORY_CACHING_TYPE_ORIG                                    TypeDef     DWord
MmFrameBufferCached                                         Equ         2

;MEMORY_CACHING_TYPE Enumeration
MEMORY_CACHING_TYPE                                         TypeDef     DWord
MmNonCached                                                 Equ         FALSE
MmCached                                                    Equ         TRUE
MmWriteCombined                                             Equ         MmFrameBufferCached
MmHardwareCoherentCached                                    Equ         3
MmNonCachedUnordered                                        Equ         4
MmUSWCCached                                                Equ         5
MmMaximumCacheType                                          Equ         6

GM_LOCK_BIT                                                 Equ         01H
GM_LOCK_BIT_V                                               Equ         00H
GM_LOCK_WAITER_WOKEN                                        Equ         02H
GM_LOCK_WAITER_INC                                          Equ         04H

;KE_PROCESSOR_CHANGE_NOTIFY_STATE Enumeration
KE_PROCESSOR_CHANGE_NOTIFY_STATE                            TypeDef     DWord
KeProcessorAddStartNotify                                   Equ         0
KeProcessorAddCompleteNotify                                Equ         1
KeProcessorAddFailureNotify                                 Equ         2

KE_PROCESSOR_CHANGE_NOTIFY_CONTEXT Struct
    State                                                   KE_PROCESSOR_CHANGE_NOTIFY_STATE ?
    NtNumber                                                DD          ?
    Status                                                  NTSTATUS    ?
KE_PROCESSOR_CHANGE_NOTIFY_CONTEXT EndS

INVALID_PROCESSOR_INDEX                                     Equ         0FFFFFFFFH

;POOL_TYPE Enumeration
POOL_TYPE                                                   TypeDef     DWord
NonPagedPool                                                Equ         0
PagedPool                                                   Equ         1
NonPagedPoolMustSucceed                                     Equ         2
DontUseThisType                                             Equ         3
NonPagedPoolCacheAligned                                    Equ         4
PagedPoolCacheAligned                                       Equ         5
NonPagedPoolCacheAlignedMustS                               Equ         6
MaxPoolType                                                 Equ         7
NonPagedPoolSession                                         Equ         32
PagedPoolSession                                            Equ         NonPagedPoolSession + 1
NonPagedPoolMustSucceedSession                              Equ         PagedPoolSession + 1
DontUseThisTypeSession                                      Equ         NonPagedPoolMustSucceedSession + 1
NonPagedPoolCacheAlignedSession                             Equ         DontUseThisTypeSession + 1
PagedPoolCacheAlignedSession                                Equ         NonPagedPoolCacheAlignedSession + 1
NonPagedPoolCacheAlignedMustSSession                        Equ         PagedPoolCacheAlignedSession + 1

POOL_COLD_ALLOCATION                                        Equ         256

POOL_QUOTA_FAIL_INSTEAD_OF_RAISE                            Equ         8
POOL_RAISE_IF_ALLOCATION_FAILURE                            Equ         16

;EX_POOL_PRIORITY Enumeration
EX_POOL_PRIORITY                                            TypeDef     DWord
LowPoolPriority                                             Equ         0
LowPoolPrioritySpecialPoolOverrun                           Equ         8
LowPoolPrioritySpecialPoolUnderrun                          Equ         9
NormalPoolPriority                                          Equ         16
NormalPoolPrioritySpecialPoolOverrun                        Equ         24
NormalPoolPrioritySpecialPoolUnderrun                       Equ         25
HighPoolPriority                                            Equ         32
HighPoolPrioritySpecialPoolOverrun                          Equ         40
HighPoolPrioritySpecialPoolUnderrun                         Equ         41

DISPATCHER_HEADER Struct
    byType                                                  DB          ?
    Absolute                                                DB          ?
    cbSize                                                  DB          ?
    Inserted                                                DB          ?
    SignalState                                             DD          ?
    WaitListHead                                            LIST_ENTRY  <>
DISPATCHER_HEADER EndS

KDEVICE_QUEUE Struct
    fwType                                                  DW          ?
    cbSize                                                  DW          ?
    DeviceListHead                                          LIST_ENTRY  <>
    ksLock                                                  KSPIN_LOCK  ?
    Busy                                                    BOOLEAN     ?
                                                            DB          3   Dup(?)
KDEVICE_QUEUE EndS
PKDEVICE_QUEUE                                              TypeDef     DWord

KEVENT Struct
    Header                                                  DISPATCHER_HEADER   <>
KEVENT EndS
PKEVENT                                                     TypeDef     DWord

FAST_MUTEX Struct
    Count                                                   DD          ?
    Owner                                                   DD          ?   ;PKTHREAD
    Contention                                              DD          ?
    Event                                                   KEVENT      <>
    OldIrql                                                 DD          ?
FAST_MUTEX EndS
FM_LOCK_BIT                                                 Equ         01H
FM_LOCK_BIT_V                                               Equ         00H
FM_LOCK_WAITER_WOKEN                                        Equ         02H
FM_LOCK_WAITER_INC                                          Equ         04H
PFAST_MUTEX                                                 TypeDef     DWord

EX_LOOKASIDE_LIST_EX_FLAGS_RAISE_ON_FAIL                    Equ         00000001H
EX_LOOKASIDE_LIST_EX_FLAGS_FAIL_NO_RAISE                    Equ         00000002H

EX_MAXIMUM_LOOKASIDE_DEPTH_BASE                             Equ         256
EX_MAXIMUM_LOOKASIDE_DEPTH_LIMIT                            Equ         1024

;WORK_QUEUE_TYPE Enumeration
WORK_QUEUE_TYPE                                             TypeDef     DWord
CriticalWorkQueue                                           Equ         0
DelayedWorkQueue                                            Equ         1
HyperCriticalWorkQueue                                      Equ         2
MaximumWorkQueue                                            Equ         3

ERESOURCE_THREAD                                            TypeDef     DWord

ResourceNeverExclusive                                      Equ         10H
ResourceReleaseByOtherThread                                Equ         20H
ResourceOwnedExclusive                                      Equ         80H

RESOURCE_HASH_TABLE_SIZE                                    Equ         64

RESOURCE_HASH_ENTRY Struct
    ListEntry                                               LIST_ENTRY  <>
    Address                                                 PVOID       ?
    ContentionCount                                         DD          ?
    Number                                                  DD          ?
RESOURCE_HASH_ENTRY EndS
PRESOURCE_HASH_ENTRY                                        TypeDef     DWord

RESOURCE_PERFORMANCE_DATA Struct
    ActiveResourceCount                                     DD          ?
    TotalResourceCount                                      DD          ?
    ExclusiveAcquire                                        DD          ?
    SharedFirstLevel                                        DD          ?
    SharedSecondLevel                                       DD          ?
    StarveFirstLevel                                        DD          ?
    StarveSecondLevel                                       DD          ?
    WaitForExclusive                                        DD          ?
    OwnerTableExpands                                       DD          ?
    MaximumTableExpand                                      DD          ?
    HashTable                                               LIST_ENTRY  RESOURCE_HASH_TABLE_SIZE Dup(<>)
RESOURCE_PERFORMANCE_DATA EndS
PRESOURCE_PERFORMANCE_DATA                                  TypeDef     DWord

EX_RUNDOWN_REF Struct
    Union
        Count                                               DD          ?
        _Ptr                                                PVOID       ?   ;Ptr
    EndS
EX_RUNDOWN_REF EndS
EX_RUNDOWN_ACTIVE                                           Equ         01H
EX_RUNDOWN_COUNT_SHIFT                                      Equ         01H
EX_RUNDOWN_COUNT_INC                                        Equ         (1 Shl EX_RUNDOWN_COUNT_SHIFT)
PEX_RUNDOWN_REF                                             TypeDef     DWord

;REG_NOTIFY_CLASS Enumeration
REG_NOTIFY_CLASS                                            TypeDef     DWord
RegNtDeleteKey                                              Equ         0
RegNtPreDeleteKey                                           Equ         RegNtDeleteKey
RegNtSetValueKey                                            Equ         1
RegNtPreSetValueKey                                         Equ         RegNtSetValueKey
RegNtDeleteValueKey                                         Equ         2
RegNtPreDeleteValueKey                                      Equ         RegNtDeleteValueKey
RegNtSetInformationKey                                      Equ         3
RegNtPreSetInformationKey                                   Equ         RegNtSetInformationKey
RegNtRenameKey                                              Equ         4
RegNtPreRenameKey                                           Equ         RegNtRenameKey
RegNtEnumerateKey                                           Equ         5
RegNtPreEnumerateKey                                        Equ         RegNtEnumerateKey
RegNtEnumerateValueKey                                      Equ         6
RegNtPreEnumerateValueKey                                   Equ         RegNtEnumerateValueKey
RegNtQueryKey                                               Equ         7
RegNtPreQueryKey                                            Equ         RegNtQueryKey
RegNtQueryValueKey                                          Equ         8
RegNtPreQueryValueKey                                       Equ         RegNtQueryValueKey
RegNtQueryMultipleValueKey                                  Equ         9
RegNtPreQueryMultipleValueKey                               Equ         RegNtQueryMultipleValueKey
RegNtPreCreateKey                                           Equ         10
RegNtPostCreateKey                                          Equ         11
RegNtPreOpenKey                                             Equ         12
RegNtPostOpenKey                                            Equ         13
RegNtKeyHandleClose                                         Equ         14
RegNtPreKeyHandleClose                                      Equ         RegNtKeyHandleClose
RegNtPostDeleteKey                                          Equ         15
RegNtPostSetValueKey                                        Equ         16
RegNtPostDeleteValueKey                                     Equ         17
RegNtPostSetInformationKey                                  Equ         18
RegNtPostRenameKey                                          Equ         19
RegNtPostEnumerateKey                                       Equ         20
RegNtPostEnumerateValueKey                                  Equ         21
RegNtPostQueryKey                                           Equ         22
RegNtPostQueryValueKey                                      Equ         23
RegNtPostQueryMultipleValueKey                              Equ         24
RegNtPostKeyHandleClose                                     Equ         25
RegNtPreCreateKeyEx                                         Equ         26
RegNtPostCreateKeyEx                                        Equ         27
RegNtPreOpenKeyEx                                           Equ         28
RegNtPostOpenKeyEx                                          Equ         29
RegNtPreFlushKey                                            Equ         30
RegNtPostFlushKey                                           Equ         31
RegNtPreLoadKey                                             Equ         32
RegNtPostLoadKey                                            Equ         33
RegNtPreUnLoadKey                                           Equ         34
RegNtPostUnLoadKey                                          Equ         35
RegNtPreQueryKeySecurity                                    Equ         36
RegNtPostQueryKeySecurity                                   Equ         37
RegNtPreSetKeySecurity                                      Equ         38
RegNtPostSetKeySecurity                                     Equ         38
RegNtCallbackObjectContextCleanup                           Equ         40
RegNtPreRestoreKey                                          Equ         41
RegNtPostRestoreKey                                         Equ         42
RegNtPreSaveKey                                             Equ         43
RegNtPostSaveKey                                            Equ         44
RegNtPreReplaceKey                                          Equ         45
RegNtPostReplaceKey                                         Equ         46
MaxRegNtNotifyClass                                         Equ         47

REG_DELETE_KEY_INFORMATION Struct
    Object                                                  PVOID       ?
    CallContext                                             PVOID       ?
    ObjectContext                                           PVOID       ?
    Reserved                                                PVOID       ?
REG_DELETE_KEY_INFORMATION EndS
PREG_DELETE_KEY_INFORMATION                                 TypeDef     DWord

REG_SET_VALUE_KEY_INFORMATION Struct
    Object                                                  PVOID       ?
    ValueName                                               PUNICODE_STRING ?
    TitleIndex                                              DD          ?
    _Type                                                   DD          ?   ;Type
    Data                                                    PVOID       ?
    DataSize                                                DD          ?
    CallContext                                             PVOID       ?
    ObjectContext                                           PVOID       ?
    Reserved                                                PVOID       ?
REG_SET_VALUE_KEY_INFORMATION EndS
PREG_SET_VALUE_KEY_INFORMATION                              TypeDef     DWord

REG_DELETE_VALUE_KEY_INFORMATION Struct
    Object                                                  PVOID       ?
    ValueName                                               PUNICODE_STRING ?
    CallContext                                             PVOID       ?
    ObjectContext                                           PVOID       ?
    Reserved                                                PVOID       ?
REG_DELETE_VALUE_KEY_INFORMATION EndS
PREG_DELETE_VALUE_KEY_INFORMATION                           TypeDef     DWord

REG_SET_INFORMATION_KEY_INFORMATION Struct
    Object                                                  PVOID       ?
    KeySetInformationClass                                  KEY_SET_INFORMATION_CLASS   ?
    KeySetInformation                                       PVOID       ?
    KeySetInformationLength                                 DD          ?
    CallContext                                             PVOID       ?
    ObjectContext                                           PVOID       ?
    Reserved                                                PVOID       ?
REG_SET_INFORMATION_KEY_INFORMATION EndS
PREG_SET_INFORMATION_KEY_INFORMATION                        TypeDef     DWord

REG_ENUMERATE_KEY_INFORMATION Struct
    Object                                                  PVOID       ?
    Index                                                   DD          ?
    KeyInformationClass                                     KEY_INFORMATION_CLASS   ?
    KeyInformation                                          PVOID       ?
    _Length                                                 DD          ?   ;Length
    ResultLength                                            DD          ?
    CallContext                                             PVOID       ?
    ObjectContext                                           PVOID       ?
    Reserved                                                PVOID       ?
REG_ENUMERATE_KEY_INFORMATION EndS
PREG_ENUMERATE_KEY_INFORMATION                              TypeDef     DWord

REG_ENUMERATE_VALUE_KEY_INFORMATION Struct
    Object                                                  PVOID       ?
    Index                                                   DD          ?
    KeyValueInformationClass                                KEY_VALUE_INFORMATION_CLASS ?
    KeyValueInformation                                     PVOID       ?
    _Length                                                 DD          ?   ;Length
    ResultLength                                            DD          ?
    CallContext                                             PVOID       ?
    ObjectContext                                           PVOID       ?
    Reserved                                                PVOID       ?
REG_ENUMERATE_VALUE_KEY_INFORMATION EndS
PREG_ENUMERATE_VALUE_KEY_INFORMATION                        TypeDef     DWord

REG_QUERY_KEY_INFORMATION Struct
    Object                                                  PVOID       ?
    KeyInformationClass                                     KEY_INFORMATION_CLASS   ?
    KeyInformation                                          PVOID       ?
    _Length                                                 DD          ?   ;Length
    ResultLength                                            DD          ?
    CallContext                                             PVOID       ?
    ObjectContext                                           PVOID       ?
    Reserved                                                PVOID       ?
REG_QUERY_KEY_INFORMATION EndS
PREG_QUERY_KEY_INFORMATION                                  TypeDef     DWord

REG_QUERY_VALUE_KEY_INFORMATION Struct
    Object                                                  PVOID       ?
    ValueName                                               PUNICODE_STRING ?
    KeyValueInformationClass                                KEY_VALUE_INFORMATION_CLASS ?
    KeyValueInformation                                     PVOID       ?
    _Length                                                 DD          ?   ;Length
    ResultLength                                            DD          ?
    CallContext                                             PVOID       ?
    ObjectContext                                           PVOID       ?
    Reserved                                                PVOID       ?
REG_QUERY_VALUE_KEY_INFORMATION EndS
PREG_QUERY_VALUE_KEY_INFORMATION                            TypeDef     DWord

REG_QUERY_MULTIPLE_VALUE_KEY_INFORMATION Struct
    Object                                                  PVOID       ?
    ValueEntries                                            PKEY_VALUE_ENTRY    ?
    EntryCount                                              DD          ?
    ValueBuffer                                             PVOID       ?
    BufferLength                                            DD          ?
    RequiredBufferLength                                    DD          ?
    CallContext                                             PVOID       ?
    ObjectContext                                           PVOID       ?
    Reserved                                                PVOID       ?
REG_QUERY_MULTIPLE_VALUE_KEY_INFORMATION EndS
PREG_QUERY_MULTIPLE_VALUE_KEY_INFORMATION                   TypeDef     DWord

REG_RENAME_KEY_INFORMATION Struct
    Object                                                  PVOID       ?
    NewName                                                 PUNICODE_STRING ?
    CallContext                                             PVOID       ?
    ObjectContext                                           PVOID       ?
    Reserved                                                PVOID       ?
REG_RENAME_KEY_INFORMATION EndS
PREG_RENAME_KEY_INFORMATION                                 TypeDef     DWord

REG_KEY_HANDLE_CLOSE_INFORMATION Struct
    Object                                                  PVOID       ?
    CallContext                                             PVOID       ?
    ObjectContext                                           PVOID       ?
    Reserved                                                PVOID       ?
REG_KEY_HANDLE_CLOSE_INFORMATION EndS
PREG_KEY_HANDLE_CLOSE_INFORMATION                           TypeDef     DWord

REG_CREATE_KEY_INFORMATION Struct
    CompleteName                                            PUNICODE_STRING ?
    RootObject                                              PVOID       ?
    ObjectType                                              PVOID       ?
    CreateOptions                                           DD          ?
    Class                                                   PUNICODE_STRING ?
    SecurityDescriptor                                      PVOID       ?
    SecurityQualityOfService                                PVOID       ?
    DesiredAccess                                           ACCESS_MASK ?
    GrantedAccess                                           ACCESS_MASK ?
    Disposition                                             DD          ?
    ResultObject                                            PVOID       ?
    CallContext                                             PVOID       ?
    RootObjectContext                                       PVOID       ?
    Transaction                                             PVOID       ?
    Reserved                                                PVOID       ?
REG_CREATE_KEY_INFORMATION EndS
PREG_CREATE_KEY_INFORMATION                                 TypeDef     DWord
PREG_OPEN_KEY_INFORMATION                                   TypeDef     DWord

REG_CREATE_KEY_INFORMATION_V1 Struct
    CompleteName                                            PUNICODE_STRING ?
    RootObject                                              PVOID       ?
    ObjectType                                              PVOID       ?
    Options                                                 DD          ?
    Class                                                   PUNICODE_STRING ?
    SecurityDescriptor                                      PVOID       ?
    SecurityQualityOfService                                PVOID       ?
    DesiredAccess                                           ACCESS_MASK ?
    GrantedAccess                                           ACCESS_MASK ?
    Disposition                                             DD          ?
    ResultObject                                            PVOID       ?
    CallContext                                             PVOID       ?
    RootObjectContext                                       PVOID       ?
    Transaction                                             PVOID       ?
    Version                                                 DD          ?
    RemainingName                                           PUNICODE_STRING ?
    Wow64Flags                                              DD          ?
    Attributes                                              DD          ?
    CheckAccessMode                                         KPROCESSOR_MODE ?
REG_CREATE_KEY_INFORMATION_V1 EndS
PREG_CREATE_KEY_INFORMATION_V1                              TypeDef     DWord

REG_POST_OPERATION_INFORMATION Struct
    Object                                                  PVOID       ?
    Status                                                  NTSTATUS    ?
    PreInformation                                          PVOID       ?
    ReturnStatus                                            NTSTATUS    ?
    CallContext                                             PVOID       ?
    ObjectContext                                           PVOID       ?
    Reserved                                                PVOID       ?
REG_POST_OPERATION_INFORMATION EndS
PREG_POST_OPERATION_INFORMATION                             TypeDef     DWord

REG_PRE_CREATE_KEY_INFORMATION Struct
    CompleteName                                            PUNICODE_STRING ?
REG_PRE_CREATE_KEY_INFORMATION EndS
PREG_PRE_CREATE_KEY_INFORMATION                             TypeDef     DWord

REG_POST_CREATE_KEY_INFORMATION Struct
    CompleteName                                            PUNICODE_STRING ?
    Object                                                  PVOID       ?
    Status                                                  NTSTATUS    ?
REG_POST_CREATE_KEY_INFORMATION EndS
PREG_POST_CREATE_KEY_INFORMATION                            TypeDef     DWord

REG_LOAD_KEY_INFORMATION Struct
    Object                                                  PVOID       ?
    KeyName                                                 PUNICODE_STRING ?
    SourceFile                                              PUNICODE_STRING ?
    Flags                                                   DD          ?
    TrustClassObject                                        PVOID       ?
    UserEvent                                               PVOID       ?
    DesiredAccess                                           ACCESS_MASK ?
    RootHandle                                              DD          ?
    CallContext                                             PVOID       ?
    ObjectContext                                           PVOID       ?
    Reserved                                                PVOID       ?
REG_LOAD_KEY_INFORMATION EndS
PREG_LOAD_KEY_INFORMATION                                   TypeDef     DWord

REG_UNLOAD_KEY_INFORMATION Struct
    Object                                                  PVOID       ?
    UserEvent                                               PVOID       ?
    CallContext                                             PVOID       ?
    ObjectContext                                           PVOID       ?
    Reserved                                                PVOID       ?
REG_UNLOAD_KEY_INFORMATION EndS
PREG_UNLOAD_KEY_INFORMATION                                 TypeDef     DWord

REG_CALLBACK_CONTEXT_CLEANUP_INFORMATION Struct
    Object                                                  PVOID       ?
    ObjectContext                                           PVOID       ?
    Reserved                                                PVOID       ?
REG_CALLBACK_CONTEXT_CLEANUP_INFORMATION EndS
PREG_CALLBACK_CONTEXT_CLEANUP_INFORMATION                   TypeDef     DWord

REG_QUERY_KEY_SECURITY_INFORMATION Struct
    Object                                                  PVOID       ?
    SecurityInformation                                     PSECURITY_INFORMATION   ?
    SecurityDescriptor                                      PSECURITY_DESCRIPTOR    ?
    _Length                                                 DD          ?   ;Length
    CallContext                                             PVOID       ?
    ObjectContext                                           PVOID       ?
    Reserved                                                PVOID       ?
REG_QUERY_KEY_SECURITY_INFORMATION EndS
PREG_QUERY_KEY_SECURITY_INFORMATION                         TypeDef     DWord

REG_SET_KEY_SECURITY_INFORMATION Struct
    Object                                                  PVOID       ?
    SecurityInformation                                     PSECURITY_INFORMATION   ?
    SecurityDescriptor                                      PSECURITY_DESCRIPTOR    ?
    CallContext                                             PVOID       ?
    ObjectContext                                           PVOID       ?
    Reserved                                                PVOID       ?
REG_SET_KEY_SECURITY_INFORMATION EndS
PREG_SET_KEY_SECURITY_INFORMATION                           TypeDef     DWord

REG_RESTORE_KEY_INFORMATION Struct
    Object                                                  PVOID       ?
    FileHandle                                              HANDLE      ?
    Flags                                                   DD          ?
    CallContext                                             PVOID       ?
    ObjectContext                                           PVOID       ?
    Reserved                                                PVOID       ?
REG_RESTORE_KEY_INFORMATION EndS
PREG_RESTORE_KEY_INFORMATION                                TypeDef     DWord

REG_SAVE_KEY_INFORMATION Struct
    Object                                                  PVOID       ?
    FileHandle                                              HANDLE      ?
    Format                                                  DD          ?
    CallContext                                             PVOID       ?
    ObjectContext                                           PVOID       ?
    Reserved                                                PVOID       ?
REG_SAVE_KEY_INFORMATION EndS
PREG_SAVE_KEY_INFORMATION                                   TypeDef     DWord

REG_REPLACE_KEY_INFORMATION Struct
    Object                                                  PVOID       ?
    OldFileName                                             PUNICODE_STRING ?
    NewFileName                                             PUNICODE_STRING ?
    CallContext                                             PVOID       ?
    ObjectContext                                           PVOID       ?
    Reserved                                                PVOID       ?
REG_REPLACE_KEY_INFORMATION EndS
PREG_REPLACE_KEY_INFORMATION                                TypeDef     DWord

EVENT_INCREMENT                                             Equ         1

IO_NO_INCREMENT                                             Equ         0
IO_CD_ROM_INCREMENT                                         Equ         1
IO_DISK_INCREMENT                                           Equ         1
IO_KEYBOARD_INCREMENT                                       Equ         6
IO_MAILSLOT_INCREMENT                                       Equ         2
IO_MOUSE_INCREMENT                                          Equ         6
IO_NAMED_PIPE_INCREMENT                                     Equ         2
IO_NETWORK_INCREMENT                                        Equ         2
IO_PARALLEL_INCREMENT                                       Equ         1
IO_SERIAL_INCREMENT                                         Equ         2
IO_SOUND_INCREMENT                                          Equ         8
IO_VIDEO_INCREMENT                                          Equ         1

SEMAPHORE_INCREMENT                                         Equ         1

MM_MAXIMUM_DISK_IO_SIZE                                     Equ         (10000H)

;MM_SYSTEMSIZE Enumeration
MM_SYSTEMSIZE                                               TypeDef     DWord
MmSmallSystem                                               Equ         0
MmMediumSystem                                              Equ         1
MmLargeSystem                                               Equ         2

;MM_PAGE_PRIORITY Enumeration
MM_PAGE_PRIORITY                                            TypeDef     DWord
LowPagePriority                                             Equ         0
NormalPagePriority                                          Equ         16
HighPagePriority                                            Equ         32

MM_DONT_ZERO_ALLOCATION                                     Equ         00000001H
MM_ALLOCATE_FROM_LOCAL_NODE_ONLY                            Equ         00000002H
MM_ALLOCATE_FULLY_REQUIRED                                  Equ         00000004H
MM_ALLOCATE_NO_WAIT                                         Equ         00000008H
MM_ALLOCATE_PREFER_CONTIGUOUS                               Equ         00000010H
MM_ALLOCATE_REQUIRE_CONTIGUOUS_CHUNKS                       Equ         00000020H

NODE_REQUIREMENT                                            TypeDef     DWord

MM_ANY_NODE_OK                                              Equ         80000000H

;SECURITY_OPERATION_CODE Enumeration
SECURITY_OPERATION_CODE                                     TypeDef     DWord
SetSecurityDescriptor                                       Equ         0
QuerySecurityDescriptor                                     Equ         1
DeleteSecurityDescriptor                                    Equ         2
AssignSecurityDescriptor                                    Equ         3
PSECURITY_OPERATION_CODE                                    TypeDef     DWord

SECURITY_SUBJECT_CONTEXT Struct
    ClientToken                                             PACCESS_TOKEN   ?
    ImpersonationLevel                                      SECURITY_IMPERSONATION_LEVEL    ?
    PrimaryToken                                            PACCESS_TOKEN   ?
    ProcessAuditId                                          PVOID       ?
SECURITY_SUBJECT_CONTEXT EndS
PSECURITY_SUBJECT_CONTEXT                                   TypeDef     DWord

INITIAL_PRIVILEGE_COUNT                                     Equ         3

INITIAL_PRIVILEGE_SET Struct
    PrivilegeCount                                          DD          ?
    Control                                                 DD          ?
    Privilege                                               LUID_AND_ATTRIBUTES INITIAL_PRIVILEGE_COUNT Dup(<>)
INITIAL_PRIVILEGE_SET EndS
PINITIAL_PRIVILEGE_SET                                      TypeDef     DWord

ACCESS_STATE Struct
   OperationID                                              LUID        <>
   SecurityEvaluated                                        BOOLEAN     ?
   GenerateAudit                                            BOOLEAN     ?
   GenerateOnClose                                          BOOLEAN     ?
   PrivilegesAllocated                                      BOOLEAN     ?
   Flags                                                    DD          ?
   RemainingDesiredAccess                                   ACCESS_MASK ?
   PreviouslyGrantedAccess                                  ACCESS_MASK ?
   OriginalDesiredAccess                                    ACCESS_MASK ?
   SubjectSecurityContext                                   SECURITY_SUBJECT_CONTEXT    <>
   SecurityDescriptor                                       PSECURITY_DESCRIPTOR    ?
   AuxData                                                  PVOID       ?
   Union Privileges
      InitialPrivilegeSet                                   INITIAL_PRIVILEGE_SET   <>
      PrivilegeSet                                          PRIVILEGE_SET   <>
   EndS
   AuditPrivileges                                          BOOLEAN     ?
   ObjectName                                               UNICODE_STRING  <>
   ObjectTypeName                                           UNICODE_STRING  <>
ACCESS_STATE EndS
PACCESS_STATE                                               TypeDef     DWord

IO_TYPE_ADAPTER                                             Equ         00000001H
IO_TYPE_CONTROLLER                                          Equ         00000002H
IO_TYPE_DEVICE                                              Equ         00000003H
IO_TYPE_DRIVER                                              Equ         00000004H
IO_TYPE_FILE                                                Equ         00000005H
IO_TYPE_IRP                                                 Equ         00000006H
IO_TYPE_MASTER_ADAPTER                                      Equ         00000007H
IO_TYPE_OPEN_PACKET                                         Equ         00000008H
IO_TYPE_TIMER                                               Equ         00000009H
IO_TYPE_VPB                                                 Equ         0000000AH
IO_TYPE_ERROR_LOG                                           Equ         0000000BH
IO_TYPE_ERROR_MESSAGE                                       Equ         0000000CH
IO_TYPE_DEVICE_OBJECT_EXTENSION                             Equ         0000000DH

IRP_MJ_CREATE                                               Equ         00H
IRP_MJ_CREATE_NAMED_PIPE                                    Equ         01H
IRP_MJ_CLOSE                                                Equ         02H
IRP_MJ_READ                                                 Equ         03H
IRP_MJ_WRITE                                                Equ         04H
IRP_MJ_QUERY_INFORMATION                                    Equ         05H
IRP_MJ_SET_INFORMATION                                      Equ         06H
IRP_MJ_QUERY_EA                                             Equ         07H
IRP_MJ_SET_EA                                               Equ         08H
IRP_MJ_FLUSH_BUFFERS                                        Equ         09H
IRP_MJ_QUERY_VOLUME_INFORMATION                             Equ         0AH
IRP_MJ_SET_VOLUME_INFORMATION                               Equ         0BH
IRP_MJ_DIRECTORY_CONTROL                                    Equ         0CH
IRP_MJ_FILE_SYSTEM_CONTROL                                  Equ         0DH
IRP_MJ_DEVICE_CONTROL                                       Equ         0EH
IRP_MJ_INTERNAL_DEVICE_CONTROL                              Equ         0FH
IRP_MJ_SHUTDOWN                                             Equ         10H
IRP_MJ_LOCK_CONTROL                                         Equ         11H
IRP_MJ_CLEANUP                                              Equ         12H
IRP_MJ_CREATE_MAILSLOT                                      Equ         13H
IRP_MJ_QUERY_SECURITY                                       Equ         14H
IRP_MJ_SET_SECURITY                                         Equ         15H
IRP_MJ_POWER                                                Equ         16H
IRP_MJ_SYSTEM_CONTROL                                       Equ         17H
IRP_MJ_DEVICE_CHANGE                                        Equ         18H
IRP_MJ_QUERY_QUOTA                                          Equ         19H
IRP_MJ_SET_QUOTA                                            Equ         1AH
IRP_MJ_PNP                                                  Equ         1BH
IRP_MJ_PNP_POWER                                            Equ         IRP_MJ_PNP
IRP_MJ_MAXIMUM_FUNCTION                                     Equ         1BH

IRP_MJ_SCSI                                                 Equ         IRP_MJ_INTERNAL_DEVICE_CONTROL

IRP_MN_SCSI_CLASS                                           Equ         01H

IRP_MN_START_DEVICE                                         Equ         00H
IRP_MN_QUERY_REMOVE_DEVICE                                  Equ         01H
IRP_MN_REMOVE_DEVICE                                        Equ         02H
IRP_MN_CANCEL_REMOVE_DEVICE                                 Equ         03H
IRP_MN_STOP_DEVICE                                          Equ         04H
IRP_MN_QUERY_STOP_DEVICE                                    Equ         05H
IRP_MN_CANCEL_STOP_DEVICE                                   Equ         06H

IRP_MN_QUERY_DEVICE_RELATIONS                               Equ         07H
IRP_MN_QUERY_INTERFACE                                      Equ         08H
IRP_MN_QUERY_CAPABILITIES                                   Equ         09H
IRP_MN_QUERY_RESOURCES                                      Equ         0AH
IRP_MN_QUERY_RESOURCE_REQUIREMENTS                          Equ         0BH
IRP_MN_QUERY_DEVICE_TEXT                                    Equ         0CH
IRP_MN_FILTER_RESOURCE_REQUIREMENTS                         Equ         0DH

IRP_MN_READ_CONFIG                                          Equ         0FH
IRP_MN_WRITE_CONFIG                                         Equ         10H
IRP_MN_EJECT                                                Equ         11H
IRP_MN_SET_LOCK                                             Equ         12H
IRP_MN_QUERY_ID                                             Equ         13H
IRP_MN_QUERY_PNP_DEVICE_STATE                               Equ         14H
IRP_MN_QUERY_BUS_INFORMATION                                Equ         15H
IRP_MN_DEVICE_USAGE_NOTIFICATION                            Equ         16H
IRP_MN_SURPRISE_REMOVAL                                     Equ         17H
IRP_MN_DEVICE_ENUMERATED                                    Equ         19H

IRP_MN_WAIT_WAKE                                            Equ         00H
IRP_MN_POWER_SEQUENCE                                       Equ         01H
IRP_MN_SET_POWER                                            Equ         02H
IRP_MN_QUERY_POWER                                          Equ         03H

IRP_MN_QUERY_ALL_DATA                                       Equ         00H
IRP_MN_QUERY_SINGLE_INSTANCE                                Equ         01H
IRP_MN_CHANGE_SINGLE_INSTANCE                               Equ         02H
IRP_MN_CHANGE_SINGLE_ITEM                                   Equ         03H
IRP_MN_ENABLE_EVENTS                                        Equ         04H
IRP_MN_DISABLE_EVENTS                                       Equ         05H
IRP_MN_ENABLE_COLLECTION                                    Equ         06H
IRP_MN_DISABLE_COLLECTION                                   Equ         07H
IRP_MN_REGINFO                                              Equ         08H
IRP_MN_EXECUTE_METHOD                                       Equ         09H
IRP_MN_REGINFO_EX                                           Equ         0BH

IO_FORCE_ACCESS_CHECK                                       Equ         0001H
IO_NO_PARAMETER_CHECKING                                    Equ         0100H

IO_REPARSE                                                  Equ         0H
IO_REMOUNT                                                  Equ         1H

;CREATE_FILE_TYPE Enumeration
CREATE_FILE_TYPE                                            TypeDef     DWord
CreateFileTypeNone                                          Equ         0
CreateFileTypeNamedPipe                                     Equ         1
CreateFileTypeMailslot                                      Equ         2

FAST_IO_DISPATCH Struct
    SizeOfFastIoDispatch                                    DD          ?
    FastIoCheckIfPossible                                   DD          ?
    FastIoRead                                              DD          ?
    FastIoWrite                                             DD          ?
    FastIoQueryBasicInfo                                    DD          ?
    FastIoQueryStandardInfo                                 DD          ?
    FastIoLock                                              DD          ?
    FastIoUnlockSingle                                      DD          ?
    FastIoUnlockAll                                         DD          ?
    FastIoUnlockAllByKey                                    DD          ?
    FastIoDeviceControl                                     DD          ?
    AcquireFileForNtCreateSection                           DD          ?
    ReleaseFileForNtCreateSection                           DD          ?
    FastIoDetachDevice                                      DD          ?
    FastIoQueryNetworkOpenInfo                              DD          ?
    AcquireForModWrite                                      DD          ?
    MdlRead                                                 DD          ?
    MdlReadComplete                                         DD          ?
    PrepareMdlWrite                                         DD          ?
    MdlWriteComplete                                        DD          ?
    FastIoReadCompressed                                    DD          ?
    FastIoWriteCompressed                                   DD          ?
    MdlReadCompleteCompressed                               DD          ?
    MdlWriteCompleteCompressed                              DD          ?
    FastIoQueryOpen                                         DD          ?
    ReleaseForModWrite                                      DD          ?
    AcquireForCcFlush                                       DD          ?
    ReleaseForCcFlush                                       DD          ?
FAST_IO_DISPATCH EndS
PFAST_IO_DISPATCH                                           TypeDef     DWord

;IO_ALLOCATION_ACTION enumeration
KeepObject                                                  Equ         1
DeallocateObject                                            Equ         2
DeallocateObjectKeepRegisters                               Equ         3

IO_SECURITY_CONTEXT Struct
    SecurityQos                                             PSECURITY_QUALITY_OF_SERVICE    ?
    AccessState                                             PACCESS_STATE   ?
    DesiredAccess                                           ACCESS_MASK ?
    FullCreateOptions                                       DD          ?
IO_SECURITY_CONTEXT EndS
PIO_SECURITY_CONTEXT                                        TypeDef     DWord

VPB_MOUNTED                                                 Equ         00000001H
VPB_LOCKED                                                  Equ         00000002H
VPB_PERSISTENT                                              Equ         00000004H
VPB_REMOVE_PENDING                                          Equ         00000008H
VPB_RAW_MOUNT                                               Equ         00000010H
VPB_DIRECT_WRITES_ALLOWED                                   Equ         00000020H

MAXIMUM_VOLUME_LABEL_LENGTH                                 Equ         (32 * SizeOf Word) ; 32 characters

PDEVICE_OBJECT                                              TypeDef     DWord
PDRIVER_OBJECT                                              TypeDef     DWord
PDRIVER_EXTENSION                                           TypeDef     DWord

DEVOBJ_EXTENSION Struct
    _Type                                                   DW          ?   ;Type
    _Size                                                   DW          ?   ;Size
    DeviceObject                                            PDEVICE_OBJECT  ?
DEVOBJ_EXTENSION EndS
PDEVOBJ_EXTENSION                                           TypeDef     DWord

VPB Struct
    _Type                                                   DW          ?   ;Type
    _Size                                                   DW          ?   ;Size
    Flags                                                   DW          ?
    VolumeLabelLength                                       DW          ?
    DeviceObject                                            PDEVICE_OBJECT  ?
    RealDevice                                              PDEVICE_OBJECT  ?
    SerialNumber                                            DD          ?
    ReferenceCount                                          DD          ?
    VolumeLabel                                             DW          (MAXIMUM_VOLUME_LABEL_LENGTH / SizeOf Word) Dup(?)
VPB EndS
PVPB                                                        TypeDef     DWord

WAIT_CONTEXT_BLOCK Struct
    WaitQueueEntry                                          KDEVICE_QUEUE_ENTRY <>
    DeviceRoutine                                           DD          ?
    DeviceContext                                           PVOID       ?
    NumberOfMapRegisters                                    DD          ?
    DeviceObject                                            PVOID       ?
    CurrentIrp                                              PVOID       ?
    BufferChainingDpc                                       PKDPC       ?
WAIT_CONTEXT_BLOCK EndS
PWAIT_CONTEXT_BLOCK                                         TypeDef     DWord

DEVICE_OBJECT Struct
    _Type                                                   DW          ?   ;Type
    _Size                                                   DW          ?   ;Size
    ReferenceCount                                          DD          ?
    DriverObject                                            PDRIVER_OBJECT  ?
    NextDevice                                              PDEVICE_OBJECT  ?
    AttachedDevice                                          PDEVICE_OBJECT  ?
    CurrentIrp                                              DD          ?   ;PIRP
    Timer                                                   DD          ?   ;PIO_TIMER
    Flags                                                   DD          ?
    Characteristics                                         DD          ?
    Vpb                                                     PVPB        ?
    DeviceExtension                                         PVOID       ?
    DeviceType                                              DEVICE_TYPE ?
    StackSize                                               DB          ?
    Union Queue
        ListEntry                                           LIST_ENTRY  <>
        Wcb                                                 WAIT_CONTEXT_BLOCK  <>
    EndS
    AlignmentRequirement                                    DD          ?
    DeviceQueue                                             KDEVICE_QUEUE   <>
    Dpc                                                     KDPC        <>
    ActiveThreadCount                                       DD          ?
    SecurityDescriptor                                      PSECURITY_DESCRIPTOR    ?
    DeviceLock                                              KEVENT      <>
    SectorSize                                              DW          ?
    Spare1                                                  DW          ?
    DeviceObjectExtension                                   PDEVOBJ_EXTENSION   ?
    Reserved                                                PVOID       ?
DEVICE_OBJECT EndS

DRIVER_OBJECT Struct
    _Type                                                   DW          ?   ;Type
    _Size                                                   DW          ?   ;Size
    DeviceObject                                            PDEVICE_OBJECT  ?
    Flags                                                   DD          ?
    DriverStart                                             PVOID       ?
    DriverSize                                              DD          ?
    DriverSection                                           PVOID       ?
    DriverExtension                                         PDRIVER_EXTENSION   ?
    DriverName                                              UNICODE_STRING  <>
    HardwareDatabase                                        PUNICODE_STRING ?
    FastIoDispatch                                          PFAST_IO_DISPATCH   ?
    DriverInit                                              DD          ?
    DriverStartIo                                           DD          ?
    DriverUnload                                            DD          ?
    MajorFunction                                           DD          (IRP_MJ_MAXIMUM_FUNCTION + 1) Dup(?)
DRIVER_OBJECT EndS

DRIVER_EXTENSION Struct
    DriverObject                                            PDRIVER_OBJECT  ?
    AddDevice                                               DD          ?
    Count                                                   DD          ?
    ServiceKeyName                                          UNICODE_STRING  <>
DRIVER_EXTENSION EndS

DO_VERIFY_VOLUME                                            Equ         00000002H
DO_BUFFERED_IO                                              Equ         00000004H
DO_EXCLUSIVE                                                Equ         00000008H
DO_DIRECT_IO                                                Equ         00000010H
DO_MAP_IO_BUFFER                                            Equ         00000020H
DO_DEVICE_INITIALIZING                                      Equ         00000080H
DO_SHUTDOWN_REGISTERED                                      Equ         00000800H
DO_BUS_ENUMERATED_DEVICE                                    Equ         00001000H
DO_POWER_PAGABLE                                            Equ         00002000H
DO_POWER_INRUSH                                             Equ         00004000H

DRVO_UNLOAD_INVOKED                                         Equ         00000001H
DRVO_LEGACY_DRIVER                                          Equ         00000002H
DRVO_BUILTIN_DRIVER                                         Equ         00000004H

SECTION_OBJECT_POINTERS Struct
    DataSectionObject                                       PVOID       ?
    SharedCacheMap                                          PVOID       ?
    ImageSectionObject                                      PVOID       ?
SECTION_OBJECT_POINTERS EndS
PSECTION_OBJECT_POINTERS                                    TypeDef     DWord

IO_COMPLETION_CONTEXT Struct
    Port                                                    PVOID       ?
    Key                                                     PVOID       ?
IO_COMPLETION_CONTEXT EndS
PIO_COMPLETION_CONTEXT                                      TypeDef     DWord

FO_FILE_OPEN                                                Equ         00000001H
FO_SYNCHRONOUS_IO                                           Equ         00000002H
FO_ALERTABLE_IO                                             Equ         00000004H
FO_NO_INTERMEDIATE_BUFFERING                                Equ         00000008H
FO_WRITE_THROUGH                                            Equ         00000010H
FO_SEQUENTIAL_ONLY                                          Equ         00000020H
FO_CACHE_SUPPORTED                                          Equ         00000040H
FO_NAMED_PIPE                                               Equ         00000080H
FO_STREAM_FILE                                              Equ         00000100H
FO_MAILSLOT                                                 Equ         00000200H
FO_GENERATE_AUDIT_ON_CLOSE                                  Equ         00000400H
FO_QUEUE_IRP_TO_THREAD                                      Equ         FO_GENERATE_AUDIT_ON_CLOSE
FO_DIRECT_DEVICE_OPEN                                       Equ         00000800H
FO_FILE_MODIFIED                                            Equ         00001000H
FO_FILE_SIZE_CHANGED                                        Equ         00002000H
FO_CLEANUP_COMPLETE                                         Equ         00004000H
FO_TEMPORARY_FILE                                           Equ         00008000H
FO_DELETE_ON_CLOSE                                          Equ         00010000H
FO_OPENED_CASE_SENSITIVE                                    Equ         00020000H
FO_HANDLE_CREATED                                           Equ         00040000H
FO_FILE_FAST_IO_READ                                        Equ         00080000H
FO_RANDOM_ACCESS                                            Equ         00100000H
FO_FILE_OPEN_CANCELLED                                      Equ         00200000H
FO_VOLUME_OPEN                                              Equ         00400000H
FO_REMOTE_ORIGIN                                            Equ         01000000H
FO_DISALLOW_EXCLUSIVE                                       Equ         02000000H
FO_SKIP_COMPLETION_PORT                                     Equ         FO_DISALLOW_EXCLUSIVE
FO_SKIP_SET_EVENT                                           Equ         04000000H
FO_SKIP_SET_FAST_IO                                         Equ         08000000H

FO_FLAGS_VALID_ONLY_DURING_CREATE                           Equ         FO_DISALLOW_EXCLUSIVE

FILE_OBJECT Struct
    _Type                                                   DW          ?   ;Type
    _Size                                                   DW          ?   ;Size
    DeviceObject                                            PDEVICE_OBJECT  ?
    Vpb                                                     PVPB        ?
    FsContext                                               PVOID       ?
    FsContext2                                              PVOID       ?
    SectionObjectPointer                                    PSECTION_OBJECT_POINTERS    ?
    PrivateCacheMap                                         PVOID       ?
    FinalStatus                                             NTSTATUS    ?
    RelatedFileObject                                       DD          ?
    LockOperation                                           BOOLEAN     ?
    DeletePending                                           BOOLEAN     ?
    ReadAccess                                              BOOLEAN     ?
    WriteAccess                                             BOOLEAN     ?
    DeleteAccess                                            BOOLEAN     ?
    SharedRead                                              BOOLEAN     ?
    SharedWrite                                             BOOLEAN     ?
    SharedDelete                                            BOOLEAN     ?
    Flags                                                   DD          ?
    FileName                                                UNICODE_STRING  <>
    CurrentByteOffset                                       LARGE_INTEGER   <>
    Waiters                                                 DD          ?
    Busy                                                    DD          ?
    LastLock                                                PVOID       ?
    _Lock                                                   KEVENT      <>  ;Lock
    Event                                                   KEVENT      <>
    CompletionContext                                       PIO_COMPLETION_CONTEXT  ?
    IrpListLock                                             KSPIN_LOCK  ?
    IrpList                                                 LIST_ENTRY  <>
    FileObjectExtension                                     PVOID       ?
FILE_OBJECT EndS
PFILE_OBJECT                                                TypeDef     DWord

IRP_NOCACHE                                                 Equ         00000001H
IRP_PAGING_IO                                               Equ         00000002H
IRP_MOUNT_COMPLETION                                        Equ         00000002H
IRP_SYNCHRONOUS_API                                         Equ         00000004H
IRP_ASSOCIATED_IRP                                          Equ         00000008H
IRP_BUFFERED_IO                                             Equ         00000010H
IRP_DEALLOCATE_BUFFER                                       Equ         00000020H
IRP_INPUT_OPERATION                                         Equ         00000040H
IRP_SYNCHRONOUS_PAGING_IO                                   Equ         00000040H
IRP_CREATE_OPERATION                                        Equ         00000080H
IRP_READ_OPERATION                                          Equ         00000100H
IRP_WRITE_OPERATION                                         Equ         00000200H
IRP_CLOSE_OPERATION                                         Equ         00000400H
IRP_DEFER_IO_COMPLETION                                     Equ         00000800H
IRP_OB_QUERY_NAME                                           Equ         00001000H
IRP_HOLD_DEVICE_QUEUE                                       Equ         00002000H

IRP_QUOTA_CHARGED                                           Equ         01H
IRP_ALLOCATED_MUST_SUCCEED                                  Equ         02H
IRP_ALLOCATED_FIXED_SIZE                                    Equ         04H
IRP_LOOKASIDE_ALLOCATION                                    Equ         08H

_IRP Struct
    _Type                                                   DW          ?   ;Type
    _Size                                                   DW          ?   ;Size
    MdlAddress                                              PVOID       ?
    Flags                                                   DD          ?
    Union AssociatedIrp
        MasterIrp                                           PVOID       ?
        IrpCount                                            DD          ?
        SystemBuffer                                        PVOID       ?
    EndS
    ThreadListEntry                                         LIST_ENTRY  <>
    IoStatus                                                IO_STATUS_BLOCK <>
    RequestorMode                                           KPROCESSOR_MODE ?
    PendingReturned                                         BOOLEAN     ?
    StackCount                                              DB          ?
    CurrentLocation                                         DB          ?
    Cancel                                                  BOOLEAN     ?
    CancelIrql                                              KIRQL       ?
    ApcEnvironment                                          DB          ?
    AllocationFlags                                         DB          ?
    UserIosb                                                PIO_STATUS_BLOCK    ?
    UserEvent                                               PKEVENT     ?
    Union Overlay
        Struct AsynchronousParameters
            UserApcRoutine                                  PVOID       ?
            UserApcContext                                  PVOID       ?
        EndS
        AllocationSize                                      LARGE_INTEGER   <>
    EndS
    CancelRoutine                                           PVOID       ?
    UserBuffer                                              PVOID       ?
    Union Tail
        Struct Overlay
            Union
                DeviceQueueEntry                            KDEVICE_QUEUE_ENTRY <>
                Struct
                    DriverContext                           PVOID       4 Dup(?)
                EndS
            EndS
            Thread                                          PVOID       ?
            AuxiliaryBuffer                                 PCHAR       ?
            Struct
                ListEntry                                   LIST_ENTRY  <>
                Union
                    CurrentStackLocation                    PVOID       ?
                    PacketType                              DD          ?
                EndS
            EndS
            OriginalFileObject                              PFILE_OBJECT    ?
        EndS
        Apc                                                 KAPC        <>
        CompletionKey                                       PVOID       ?
    EndS
_IRP EndS
PIRP                                                        TypeDef     DWord

SL_PENDING_RETURNED                                         Equ         01H
SL_ERROR_RETURNED                                           Equ         02H
SL_INVOKE_ON_CANCEL                                         Equ         20H
SL_INVOKE_ON_SUCCESS                                        Equ         40H
SL_INVOKE_ON_ERROR                                          Equ         80H

SL_FORCE_ACCESS_CHECK                                       Equ         01H
SL_OPEN_PAGING_FILE                                         Equ         02H
SL_OPEN_TARGET_DIRECTORY                                    Equ         04H
SL_STOP_ON_SYMLINK                                          Equ         08H

SL_CASE_SENSITIVE                                           Equ         80H

SL_KEY_SPECIFIED                                            Equ         01H
SL_OVERRIDE_VERIFY_VOLUME                                   Equ         02H
SL_WRITE_THROUGH                                            Equ         04H
SL_FT_SEQUENTIAL_WRITE                                      Equ         08H
SL_FORCE_DIRECT_WRITE                                       Equ         10H
SL_REALTIME_STREAM                                          Equ         20H

SL_READ_ACCESS_GRANTED                                      Equ         01H
SL_WRITE_ACCESS_GRANTED                                     Equ         04H

SL_FAIL_IMMEDIATELY                                         Equ         01H
SL_EXCLUSIVE_LOCK                                           Equ         02H

SL_RESTART_SCAN                                             Equ         01H
SL_RETURN_SINGLE_ENTRY                                      Equ         02H
SL_INDEX_SPECIFIED                                          Equ         04H

SL_WATCH_TREE                                               Equ         01H

SL_ALLOW_RAW_MOUNT                                          Equ         01H

;DEVICE_RELATION_TYPE enumeration
BusRelations                                                Equ         0
EjectionRelations                                           Equ         1
PowerRelations                                              Equ         2
RemovalRelations                                            Equ         3
TargetDeviceRelation                                        Equ         4
SingleBusRelations                                          Equ         5
TransportRelations                                          Equ         6

DEVICE_RELATIONS  Struct
    Count                                                   DD          ?
    Objects                                                 PDEVICE_OBJECT  1 Dup(?)
DEVICE_RELATIONS EndS
PDEVICE_RELATIONS                                           TypeDef     DWord

;DEVICE_USAGE_NOTIFICATION_TYPE Enumeration
DEVICE_USAGE_NOTIFICATION_TYPE                              TypeDef     DWord
DeviceUsageTypeUndefined                                    Equ         0
DeviceUsageTypePaging                                       Equ         1
DeviceUsageTypeHibernation                                  Equ         2
DeviceUsageTypeDumpFile                                     Equ         3

INTERFACE Struct
    _Size                                                   DW          ?   ;Size
    Version                                                 DW          ?
    Context                                                 PVOID       ?
    InterfaceReference                                      DD          ?   ;PINTERFACE_REFERENCE
    InterfaceDereference                                    DD          ?   ;PINTERFACE_DEREFERENCE
INTERFACE EndS
PINTERFACE                                                  TypeDef     DWord

POWER_SEQUENCE Struct
    SequenceD1                                              DD          ?
    SequenceD2                                              DD          ?
    SequenceD3                                              DD          ?
POWER_SEQUENCE EndS
PPOWER_SEQUENCE                                             TypeDef     DWord

;BUS_QUERY_ID_TYPE Enumeration
BUS_QUERY_ID_TYPE                                           TypeDef     DWord
BusQueryDeviceID                                            Equ         0
BusQueryHardwareIDs                                         Equ         1
BusQueryCompatibleIDs                                       Equ         2
BusQueryInstanceID                                          Equ         3
BusQueryDeviceSerialNumber                                  Equ         4
BusQueryContainerID                                         Equ         5
PBUS_QUERY_ID_TYPE                                          TypeDef     DWord

PNP_DEVICE_STATE                                            TypeDef     DWord
PPNP_DEVICE_STATE                                           TypeDef     DWord

PNP_DEVICE_DISABLED                                         Equ         00000001H
PNP_DEVICE_DONT_DISPLAY_IN_UI                               Equ         00000002H
PNP_DEVICE_FAILED                                           Equ         00000004H
PNP_DEVICE_REMOVED                                          Equ         00000008H
PNP_DEVICE_RESOURCE_REQUIREMENTS_CHANGED                    Equ         00000010H
PNP_DEVICE_NOT_DISABLEABLE                                  Equ         00000020H

;DEVICE_TEXT_TYPE Enumeration
DEVICE_TEXT_TYPE                                            TypeDef     DWord
DeviceTextDescription                                       Equ         0
DeviceTextLocationInformation                               Equ         1
PDEVICE_TEXT_TYPE                                           TypeDef     DWord

IO_STACK_LOCATION Struct
    MajorFunction                                           DB          ?
    MinorFunction                                           DB          ?
    Flags                                                   DB          ?
    Control                                                 DB          ?
    Union Parameters
        Struct Create
            SecurityContext                                 PVOID       ?
            Options                                         DD          ?
            FileAttributes                                  DW          ?
            ShareAccess                                     DW          ?
            EaLength                                        DD          ?
        EndS
        Struct Read
            dwLength                                        DD          ?
            Key                                             DD          ?
            ByteOffset                                      LARGE_INTEGER   <>
        EndS
        Struct Write
            dwLength                                        DD          ?
            Key                                             DD          ?
            ByteOffset                                      LARGE_INTEGER   <>
        EndS
        Struct DeviceIoControl
            OutputBufferLength                              DD          ?
            InputBufferLength                               DD          ?
            IoControlCode                                   DD          ?
            Type3InputBuffer                                PVOID       ?
        EndS
        Struct SetLock
            bLock                                           BOOLEAN     ?
                                                            DB          3 Dup(?)
        EndS
        Struct Others
            Argument1                                       PVOID       ?
            Argument2                                       PVOID       ?
            Argument3                                       PVOID       ?
            Argument4                                       PVOID       ?
        EndS
    EndS
    DeviceObject                                            PDEVICE_OBJECT  ?
    FileObject                                              PFILE_OBJECT    ?
    CompletionRoutine                                       PVOID       ?
    Context                                                 PVOID       ?
IO_STACK_LOCATION EndS
PIO_STACK_LOCATION                                          TypeDef     DWord

SHARE_ACCESS Struct
    OpenCount                                               DD          ?
    Readers                                                 DD          ?
    Writers                                                 DD          ?
    Deleters                                                DD          ?
    SharedRead                                              DD          ?
    SharedWrite                                             DD          ?
    SharedDelete                                            DD          ?
SHARE_ACCESS EndS
PSHARE_ACCESS                                               TypeDef     DWord

;IO_PAGING_PRIORITY Enumeration
IO_PAGING_PRIORITY                                          TypeDef     DWord
IoPagingPriorityInvalid                                     Equ         0
IoPagingPriorityNormal                                      Equ         1
IoPagingPriorityHigh                                        Equ         2
IoPagingPriorityReserved1                                   Equ         3
IoPagingPriorityReserved2                                   Equ         4

BOOTDISK_INFORMATION Struct
    BootPartitionOffset                                     DQ          ?
    SystemPartitionOffset                                   DQ          ?
    BootDeviceSignature                                     DD          ?
    SystemDeviceSignature                                   DD          ?
BOOTDISK_INFORMATION EndS
PBOOTDISK_INFORMATION                                       TypeDef     DWord

BOOTDISK_INFORMATION_EX Struct
    BootPartitionOffset                                     DQ          ?
    SystemPartitionOffset                                   DQ          ?
    BootDeviceSignature                                     DD          ?
    SystemDeviceSignature                                   DD          ?
    BootDeviceGuid                                          GUID        <>
    SystemDeviceGuid                                        GUID        <>
    BootDeviceIsGpt                                         BOOLEAN     ?
    SystemDeviceIsGpt                                       BOOLEAN     ?
BOOTDISK_INFORMATION_EX EndS
PBOOTDISK_INFORMATION_EX                                    TypeDef     DWord

LOADER_PARTITION_INFORMATION_EX Struct
    PartitionStyle                                          DD          ?
    PartitionNumber                                         DD          ?
    Union
        Signature                                           DD          ?
        DeviceId                                            GUID        <>
    EndS
    Flags                                                   DD          ?
LOADER_PARTITION_INFORMATION_EX EndS
PLOADER_PARTITION_INFORMATION_EX                            TypeDef     DWord

IO_INTERRUPT_MESSAGE_INFO_ENTRY Struct
    MessageAddress                                          PHYSICAL_ADDRESS    <>
    TargetProcessorSet                                      KAFFINITY   ?
    InterruptObject                                         DD          ?   ;PKINTERRUPT
    MessageData                                             DD          ?
    Vector                                                  DD          ?
    Irql                                                    KIRQL       ?
    Mode                                                    KINTERRUPT_MODE ?
    Polarity                                                KINTERRUPT_POLARITY ?
IO_INTERRUPT_MESSAGE_INFO_ENTRY EndS
PIO_INTERRUPT_MESSAGE_INFO_ENTRY                            TypeDef     DWord

IO_INTERRUPT_MESSAGE_INFO Struct
    UnifiedIrql                                             KIRQL       ?
    MessageCount                                            DD          ?
    MessageInfo                                             IO_INTERRUPT_MESSAGE_INFO_ENTRY 1 Dup(<>)
IO_INTERRUPT_MESSAGE_INFO EndS
PIO_INTERRUPT_MESSAGE_INFO                                  TypeDef     DWord

IO_CONNECT_INTERRUPT_FULLY_SPECIFIED_PARAMETERS Struct
    PhysicalDeviceObject                                    PDEVICE_OBJECT  ?
    InterruptObject                                         DD          ?   ;PKINTERRUPT
    ServiceRoutine                                          DD          ?   ;PKSERVICE_ROUTINE
    ServiceContext                                          PVOID       ?
    SpinLock                                                PKSPIN_LOCK ?
    SynchronizeIrql                                         KIRQL       ?
    FloatingSave                                            BOOLEAN     ?
    ShareVector                                             BOOLEAN     ?
    Vector                                                  DD          ?
    Irql                                                    KIRQL       ?
    InterruptMode                                           KINTERRUPT_MODE ?
    ProcessorEnableMask                                     KAFFINITY   ?
    _Group                                                  DW          ?   ;Group
IO_CONNECT_INTERRUPT_FULLY_SPECIFIED_PARAMETERS EndS
PIO_CONNECT_INTERRUPT_FULLY_SPECIFIED_PARAMETERS            TypeDef     DWord

IO_CONNECT_INTERRUPT_LINE_BASED_PARAMETERS Struct
    PhysicalDeviceObject                                    PDEVICE_OBJECT  ?
    InterruptObject                                         DD          ?   ;PKINTERRUPT
    ServiceRoutine                                          DD          ?   ;PKSERVICE_ROUTINE
    ServiceContext                                          PVOID       ?
    SpinLock                                                PKSPIN_LOCK ?
    SynchronizeIrql                                         KIRQL       ?
    FloatingSave                                            BOOLEAN     ?
IO_CONNECT_INTERRUPT_LINE_BASED_PARAMETERS EndS
PIO_CONNECT_INTERRUPT_LINE_BASED_PARAMETERS                 TypeDef     DWord

IO_CONNECT_INTERRUPT_MESSAGE_BASED_PARAMETERS Struct
    PhysicalDeviceObject                                    PDEVICE_OBJECT  ?
    Union ConnectionContext
        Generic                                             PVOID       ?
        InterruptMessageTable                               PIO_INTERRUPT_MESSAGE_INFO  ?
        InterruptObject                                     DD          ?   ;PKINTERRUPT
    EndS
    MessageServiceRoutine                                   DD          ?   ;PKMESSAGE_SERVICE_ROUTINE
    ServiceContext                                          PVOID       ?
    SpinLock                                                PKSPIN_LOCK ?
    SynchronizeIrql                                         KIRQL       ?
    FloatingSave                                            BOOLEAN     ?
    FallBackServiceRoutine                                  DD          ?   ;PKSERVICE_ROUTINE
IO_CONNECT_INTERRUPT_MESSAGE_BASED_PARAMETERS EndS
PIO_CONNECT_INTERRUPT_MESSAGE_BASED_PARAMETERS              TypeDef     DWord

CONNECT_FULLY_SPECIFIED                                     Equ         01H
CONNECT_LINE_BASED                                          Equ         02H
CONNECT_MESSAGE_BASED                                       Equ         03H
CONNECT_FULLY_SPECIFIED_GROUP                               Equ         04H
CONNECT_CURRENT_VERSION                                     Equ         04H

IO_CONNECT_INTERRUPT_PARAMETERS Struct
    Version                                                 DD          ?
    Union
        FullySpecified                                      IO_CONNECT_INTERRUPT_FULLY_SPECIFIED_PARAMETERS <>
        LineBased                                           IO_CONNECT_INTERRUPT_LINE_BASED_PARAMETERS  <>
        MessageBased                                        IO_CONNECT_INTERRUPT_MESSAGE_BASED_PARAMETERS   <>
    EndS
IO_CONNECT_INTERRUPT_PARAMETERS EndS
PIO_CONNECT_INTERRUPT_PARAMETERS                            TypeDef     DWord

WDM_MAJORVERSION                                            Equ         06H
WDM_MINORVERSION                                            Equ         00H

IO_DISCONNECT_INTERRUPT_PARAMETERS Struct
    Version                                                 DD          ?
    Union ConnectionContext
        Generic                                             PVOID       ?
        InterruptObject                                     DD          ?   ;PKINTERRUPT
        InterruptMessageTable                               PIO_INTERRUPT_MESSAGE_INFO  ?
    EndS
IO_DISCONNECT_INTERRUPT_PARAMETERS EndS
PIO_DISCONNECT_INTERRUPT_PARAMETERS                         TypeDef     DWord

IO_REMOVE_LOCK_COMMON_BLOCK Struct
    Removed                                                 BOOLEAN     ?
    Reserved                                                BOOLEAN     3 Dup(?)
    IoCount                                                 DD          ?
    RemoveEvent                                             KEVENT      <>
IO_REMOVE_LOCK_COMMON_BLOCK EndS
PIO_REMOVE_LOCK_COMMON_BLOCK                                TypeDef     DWord

IO_REMOVE_LOCK_DBG_BLOCK Struct
    Signature                                               DD          ?
    HighWatermark                                           DD          ?
    MaxLockedTicks                                          DQ          ?
    AllocateTag                                             DD          ?
    LockList                                                LIST_ENTRY  <>
    Spin                                                    KSPIN_LOCK  ?
    LowMemoryCount                                          DD          ?
    Reserved1                                               DD          4 Dup(?)
    Reserved2                                               PVOID       ?
    Blocks                                                  DD          ?   ;PIO_REMOVE_LOCK_TRACKING_BLOCK
IO_REMOVE_LOCK_DBG_BLOCK EndS

WMIREG_ACTION_REGISTER                                      Equ         1
WMIREG_ACTION_DEREGISTER                                    Equ         2
WMIREG_ACTION_REREGISTER                                    Equ         3
WMIREG_ACTION_UPDATE_GUIDS                                  Equ         4
WMIREG_ACTION_BLOCK_IRPS                                    Equ         5

WMIREGISTER                                                 Equ         0
WMIUPDATE                                                   Equ         1

PIO_CSQ                                                     TypeDef     DWord

IO_TYPE_CSQ_IRP_CONTEXT                                     Equ         1
IO_TYPE_CSQ                                                 Equ         2
IO_TYPE_CSQ_EX                                              Equ         3

IO_CSQ_IRP_CONTEXT Struct
    _Type                                                   DD          ?   ;Type
    _Irp                                                    DD          ?   ;Irp - PIRP
    Csq                                                     PIO_CSQ     ?
IO_CSQ_IRP_CONTEXT EndS
PIO_CSQ_IRP_CONTEXT                                         TypeDef     DWord

IO_CSQ Struct
    _Type                                                   DD          ?   ;Type
    CsqInsertIrp                                            DD          ?   ;PIO_CSQ_INSERT_IRP
    CsqRemoveIrp                                            DD          ?   ;PIO_CSQ_REMOVE_IRP
    CsqPeekNextIrp                                          DD          ?   ;PIO_CSQ_PEEK_NEXT_IRP
    CsqAcquireLock                                          DD          ?   ;PIO_CSQ_ACQUIRE_LOCK
    CsqReleaseLock                                          DD          ?   ;PIO_CSQ_RELEASE_LOCK
    CsqCompleteCanceledIrp                                  DD          ?   ;PIO_CSQ_COMPLETE_CANCELED_IRP
    ReservePointer                                          PVOID       ?
IO_CSQ EndS
PIO_CSQ                                                     TypeDef     DWord

;IO_ACCESS_TYPE Enumeration
IO_ACCESS_TYPE                                              TypeDef     DWord
ReadAccess                                                  Equ         0
WriteAccess                                                 Equ         1
ModifyAccess                                                Equ         2

;IO_ACCESS_MODE Enumeration
IO_ACCESS_MODE                                              TypeDef     DWord
SequentialAccess                                            Equ         0
RandomAccess                                                Equ         1

;IO_CONTAINER_NOTIFICATION_CLASS Enumeration
IO_CONTAINER_NOTIFICATION_CLASS                             TypeDef     DWord
IoSessionStateNotification                                  Equ         0
IoMaxContainerNotificationClass                             Equ         1

IO_SESSION_STATE_NOTIFICATION Struct
    _Size                                                   DD          ?   ;Size
    Flags                                                   DD          ?
    IoObject                                                PVOID       ?
    EventMask                                               DD          ?
    Context                                                 PVOID       ?
IO_SESSION_STATE_NOTIFICATION EndS
PIO_SESSION_STATE_NOTIFICATION                              TypeDef     DWord

;IO_CONTAINER_INFORMATION_CLASS Enumeration
IO_CONTAINER_INFORMATION_CLASS                              TypeDef     DWord
IoSessionStateInformation                                   Equ         0
IoMaxContainerInformationClass                              Equ         1

IO_SESSION_STATE_INFORMATION Struct
    SessionId                                               DD          ?
    SessionState                                            IO_SESSION_STATE    ?
    LocalSession                                            BOOLEAN     ?
IO_SESSION_STATE_INFORMATION EndS
PIO_SESSION_STATE_INFORMATION                               TypeDef     DWord

ETW_TRACE_SESSION_SETTINGS Struct
    Version                                                 DD          ?
    BufferSize                                              DD          ?
    MinimumBuffers                                          DD          ?
    MaximumBuffers                                          DD          ?
    LoggerMode                                              DD          ?
    FlushTimer                                              DD          ?
    FlushThreshold                                          DD          ?
    ClockType                                               DD          ?
ETW_TRACE_SESSION_SETTINGS EndS
PETW_TRACE_SESSION_SETTINGS                                 TypeDef     DWord

;TRACE_INFORMATION_CLASS Enumeration
TRACE_INFORMATION_CLASS                                     TypeDef     DWord
TraceIdClass                                                Equ         0
TraceHandleClass                                            Equ         1
TraceEnableFlagsClass                                       Equ         2
TraceEnableLevelClass                                       Equ         3
GlobalLoggerHandleClass                                     Equ         4
EventLoggerHandleClass                                      Equ         5
AllLoggerHandlesClass                                       Equ         6
TraceHandleByNameClass                                      Equ         7
LoggerEventsLostClass                                       Equ         8
TraceSessionSettingsClass                                   Equ         9
LoggerEventsLoggedClass                                     Equ         10
MaxTraceInformationClass                                    Equ         11

;DEVICE_INSTALL_STATE Enumeration
DEVICE_INSTALL_STATE                                        TypeDef     DWord
InstallStateInstalled                                       Equ         0
InstallStateNeedsReinstall                                  Equ         1
InstallStateFailedInstall                                   Equ         2
InstallStateFinishInstall                                   Equ         3
PDEVICE_INSTALL_STATE                                       TypeDef     DWord

PNP_BUS_INFORMATION Struct
    BusTypeGuid                                             GUID        <>
    LegacyBusType                                           INTERFACE_TYPE  ?
    BusNumber                                               DD          ?
PNP_BUS_INFORMATION EndS
PPNP_BUS_INFORMATION                                        TypeDef     DWord

LEGACY_BUS_INFORMATION Struct
    BusTypeGuid                                             GUID        <>
    LegacyBusType                                           INTERFACE_TYPE  ?
    BusNumber                                               DD          ?
LEGACY_BUS_INFORMATION EndS
PLEGACY_BUS_INFORMATION                                     TypeDef     DWord

;DEVICE_REMOVAL_POLICY Enumeration
DEVICE_REMOVAL_POLICY                                       TypeDef     DWord
RemovalPolicyExpectNoRemoval                                Equ         1
RemovalPolicyExpectOrderlyRemoval                           Equ         2
RemovalPolicyExpectSurpriseRemoval                          Equ         3
PDEVICE_REMOVAL_POLICY                                      TypeDef     DWord

BUS_INTERFACE_STANDARD Struct
    _Size                                                   DW          ?   ;Size
    Version                                                 DW          ?
    Context                                                 PVOID       ?
    InterfaceReference                                      DD          ?   ;PINTERFACE_REFERENCE
    InterfaceDereference                                    DD          ?   ;PINTERFACE_DEREFERENCE
    TranslateBusAddress                                     DD          ?   ;PTRANSLATE_BUS_ADDRESS
    GetDmaAdapter                                           DD          ?   ;PGET_DMA_ADAPTER
    SetBusData                                              DD          ?   ;PGET_SET_DEVICE_DATA
    GetBusData                                              DD          ?   ;PGET_SET_DEVICE_DATA
BUS_INTERFACE_STANDARD EndS
PBUS_INTERFACE_STANDARD                                     TypeDef     DWord

ACPI_INTERFACE_STANDARD Struct
    _Size                                                   DW          ?   ;Size
    Version                                                 DW          ?
    Context                                                 PVOID       ?
    InterfaceReference                                      DD          ?   ;PINTERFACE_REFERENCE
    InterfaceDereference                                    DD          ?   ;PINTERFACE_DEREFERENCE
    GpeConnectVector                                        DD          ?   ;PGPE_CONNECT_VECTOR
    GpeDisconnectVector                                     DD          ?   ;PGPE_DISCONNECT_VECTOR
    GpeEnableEvent                                          DD          ?   ;PGPE_ENABLE_EVENT
    GpeDisableEvent                                         DD          ?   ;PGPE_DISABLE_EVENT
    GpeClearStatus                                          DD          ?   ;PGPE_CLEAR_STATUS
    RegisterForDeviceNotifications                          DD          ?   ;PREGISTER_FOR_DEVICE_NOTIFICATIONS
    UnregisterForDeviceNotifications                        DD          ?   ;PUNREGISTER_FOR_DEVICE_NOTIFICATIONS
ACPI_INTERFACE_STANDARD EndS
PACPI_INTERFACE_STANDARD                                    TypeDef     DWord

ACPI_INTERFACE_STANDARD2 Struct
    _Size                                                   DW          ?   ;Size
    Version                                                 DW          ?
    Context                                                 PVOID       ?
    InterfaceReference                                      DD          ?   ;PINTERFACE_REFERENCE
    InterfaceDereference                                    DD          ?   ;PINTERFACE_DEREFERENCE
    GpeConnectVector                                        DD          ?   ;PGPE_CONNECT_VECTOR2
    GpeDisconnectVector                                     DD          ?   ;PGPE_DISCONNECT_VECTOR2
    GpeEnableEvent                                          DD          ?   ;PGPE_ENABLE_EVENT2
    GpeDisableEvent                                         DD          ?   ;PGPE_DISABLE_EVENT2
    GpeClearStatus                                          DD          ?   ;PGPE_CLEAR_STATUS2
    RegisterForDeviceNotifications                          DD          ?   ;PREGISTER_FOR_DEVICE_NOTIFICATIONS2
    UnregisterForDeviceNotifications                        DD          ?   ;PUNREGISTER_FOR_DEVICE_NOTIFICATIONS2
ACPI_INTERFACE_STANDARD2 EndS
PACPI_INTERFACE_STANDARD2                                   TypeDef     DWord

PLUGPLAY_REGKEY_DEVICE                                      Equ         1
PLUGPLAY_REGKEY_DRIVER                                      Equ         2
PLUGPLAY_REGKEY_CURRENT_HWPROFILE                           Equ         4

;IO_NOTIFICATION_EVENT_CATEGORY Enumeration
IO_NOTIFICATION_EVENT_CATEGORY                              TypeDef     DWord
EventCategoryReserved                                       Equ         0
EventCategoryHardwareProfileChange                          Equ         1
EventCategoryDeviceInterfaceChange                          Equ         2
EventCategoryTargetDeviceChange                             Equ         3

PNPNOTIFY_DEVICE_INTERFACE_INCLUDE_EXISTING_INTERFACES      Equ         00000001H

PLUGPLAY_NOTIFICATION_HEADER Struct
    Version                                                 DW          ?
    _Size                                                   DW          ?   ;Size
    Event                                                   GUID        <>
PLUGPLAY_NOTIFICATION_HEADER EndS
PPLUGPLAY_NOTIFICATION_HEADER                               TypeDef     DWord

HWPROFILE_CHANGE_NOTIFICATION Struct
    Version                                                 DW          ?
    _Size                                                   DW          ?   ;Size
    Event                                                   GUID        <>
HWPROFILE_CHANGE_NOTIFICATION EndS
PHWPROFILE_CHANGE_NOTIFICATION                              TypeDef     DWord

DEVICE_INTERFACE_CHANGE_NOTIFICATION Struct
    Version                                                 DW          ?
    _Size                                                   DW          ?   ;Size
    Event                                                   GUID        <>
    InterfaceClassGuid                                      GUID        <>
    SymbolicLinkName                                        PUNICODE_STRING ?
DEVICE_INTERFACE_CHANGE_NOTIFICATION EndS
PDEVICE_INTERFACE_CHANGE_NOTIFICATION                       TypeDef     DWord

TARGET_DEVICE_REMOVAL_NOTIFICATION Struct
    Version                                                 DW          ?
    _Size                                                   DW          ?   ;Size
    Event                                                   GUID        <>
    FileObject                                              PFILE_OBJECT    ?
TARGET_DEVICE_REMOVAL_NOTIFICATION EndS
PTARGET_DEVICE_REMOVAL_NOTIFICATION                         TypeDef     DWord

TARGET_DEVICE_CUSTOM_NOTIFICATION Struct
    Version                                                 DW          ?
    _Size                                                   DW          ?   ;Size
    Event                                                   GUID        <>
    FileObject                                              PFILE_OBJECT    ?
    NameBufferOffset                                        DD          ?
    CustomDataBuffer                                        DB          1 Dup(?)
TARGET_DEVICE_CUSTOM_NOTIFICATION EndS
PTARGET_DEVICE_CUSTOM_NOTIFICATION                          TypeDef     DWord

PNP_REPLACE_PROCESSOR_LIST Struct
    Affinity                                                PKAFFINITY  ?
    GroupCount                                              DD          ?
    AllocatedCount                                          DD          ?
    Count                                                   DD          ?
    ApicIds                                                 DD          ANYSIZE_ARRAY Dup(?)
PNP_REPLACE_PROCESSOR_LIST EndS
PPNP_REPLACE_PROCESSOR_LIST                                 TypeDef     DWord

PNP_REPLACE_PROCESSOR_LIST_V1 Struct
    AffinityMask                                            KAFFINITY   ?
    AllocatedCount                                          DD          ?
    Count                                                   DD          ?
    ApicIds                                                 DD          ANYSIZE_ARRAY Dup(?)
PNP_REPLACE_PROCESSOR_LIST_V1 EndS
PPNP_REPLACE_PROCESSOR_LIST_V1                              TypeDef     DWord

PNP_REPLACE_PARAMETERS_VERSION                              Equ         2

PNP_REPLACE_PARAMETERS Struct
    _Size                                                   DD          ?   ;Size
    Version                                                 DD          ?
    Target                                                  DQ          ?
    Spare                                                   DQ          ?
    TargetProcessors                                        PPNP_REPLACE_PROCESSOR_LIST ?
    SpareProcessors                                         PPNP_REPLACE_PROCESSOR_LIST ?
    TargetMemory                                            DD          ?
    SpareMemory                                             DD          ?
    MapMemory                                               DD          ? ;PREPLACE_MAP_MEMORY
PNP_REPLACE_PARAMETERS EndS
PPNP_REPLACE_PARAMETERS                                     TypeDef     DWord

PNP_REPLACE_DRIVER_INTERFACE_VERSION                        Equ         1

PNP_REPLACE_MEMORY_SUPPORTED                                Equ         0001H
PNP_REPLACE_PROCESSOR_SUPPORTED                             Equ         0002H
PNP_REPLACE_HARDWARE_MEMORY_MIRRORING                       Equ         0004H
PNP_REPLACE_HARDWARE_PAGE_COPY                              Equ         0008H
PNP_REPLACE_HARDWARE_QUIESCE                                Equ         0010H

PNP_REPLACE_DRIVER_INTERFACE Struct
    _Size                                                   DD          ?   ;Size
    Version                                                 DD          ?
    Flags                                                   DD          ?
    Unload                                                  DD          ? ;PREPLACE_UNLOAD
    BeginReplace                                            DD          ? ;PREPLACE_BEGIN
    EndReplace                                              DD          ? ;PREPLACE_END
    MirrorPhysicalMemory                                    DD          ? ;PREPLACE_MIRROR_PHYSICAL_MEMORY
    SetProcessorId                                          DD          ? ;PREPLACE_SET_PROCESSOR_ID
    Swap                                                    DD          ? ;PREPLACE_SWAP
    InitiateHardwareMirror                                  DD          ? ;PREPLACE_INITIATE_HARDWARE_MIRROR
    MirrorPlatformMemory                                    DD          ? ;PREPLACE_MIRROR_PLATFORM_MEMORY
    GetMemoryDestination                                    DD          ? ;PREPLACE_GET_MEMORY_DESTINATION
    EnableDisableHardwareQuiesce                            DD          ? ;PREPLACE_ENABLE_DISABLE_HARDWARE_QUIESCE
PNP_REPLACE_DRIVER_INTERFACE EndS
PPNP_REPLACE_DRIVER_INTERFACE                               TypeDef     DWord

DEVICE_DESCRIPTION Struct
    Version                                                 DD          ?
    Master                                                  BOOLEAN     ?
    ScatterGather                                           BOOLEAN     ?
    DemandMode                                              BOOLEAN     ?
    AutoInitialize                                          BOOLEAN     ?
    Dma32BitAddresses                                       BOOLEAN     ?
    IgnoreCount                                             BOOLEAN     ?
    Reserved1                                               BOOLEAN     ?
    Dma64BitAddresses                                       BOOLEAN     ?
    BusNumber                                               DD          ?
    DmaChannel                                              DD          ?
    InterfaceType                                           INTERFACE_TYPE  ?
    DmaWidth                                                DMA_WIDTH   ?
    DmaSpeed                                                DMA_SPEED   ?
    MaximumLength                                           DD          ?
    DmaPort                                                 DD          ?
DEVICE_DESCRIPTION EndS
PDEVICE_DESCRIPTION                                         TypeDef     DWord

DEVICE_DESCRIPTION_VERSION                                  Equ         0
DEVICE_DESCRIPTION_VERSION1                                 Equ         1
DEVICE_DESCRIPTION_VERSION2                                 Equ         2

PDMA_OPERATIONS                                             TypeDef     DWord

DMA_ADAPTER Struct
    Version                                                 DW          ?
    _Size                                                   DW          ?   ;Size
    DmaOperations                                           PDMA_OPERATIONS ?
DMA_ADAPTER EndS
PDMA_ADAPTER                                                TypeDef     DWord

DMA_OPERATIONS Struct
    _Size                                                   DD          ?   ;Size
    PutDmaAdapter                                           DD          ? ;PPUT_DMA_ADAPTER
    AllocateCommonBuffer                                    DD          ? ;PALLOCATE_COMMON_BUFFER
    FreeCommonBuffer                                        DD          ? ;PFREE_COMMON_BUFFER
    AllocateAdapterChannel                                  DD          ? ;PALLOCATE_ADAPTER_CHANNEL
    FlushAdapterBuffers                                     DD          ? ;PFLUSH_ADAPTER_BUFFERS
    FreeAdapterChannel                                      DD          ? ;PFREE_ADAPTER_CHANNEL
    FreeMapRegisters                                        DD          ? ;PFREE_MAP_REGISTERS
    MapTransfer                                             DD          ? ;PMAP_TRANSFER
    GetDmaAlignment                                         DD          ? ;PGET_DMA_ALIGNMENT
    ReadDmaCounter                                          DD          ? ;PREAD_DMA_COUNTER
    GetScatterGatherList                                    DD          ? ;PGET_SCATTER_GATHER_LIST
    PutScatterGatherList                                    DD          ? ;PPUT_SCATTER_GATHER_LIST
    CalculateScatterGatherList                              DD          ? ;PCALCULATE_SCATTER_GATHER_LIST_SIZE
    BuildScatterGatherList                                  DD          ? ;PBUILD_SCATTER_GATHER_LIST
    BuildMdlFromScatterGatherList                           DD          ? ;PBUILD_MDL_FROM_SCATTER_GATHER_LIST
DMA_OPERATIONS EndS

PO_CB_SYSTEM_POWER_POLICY                                   Equ         0
PO_CB_AC_STATUS                                             Equ         1
PO_CB_BUTTON_COLLISION                                      Equ         2
PO_CB_SYSTEM_STATE_LOCK                                     Equ         3
PO_CB_LID_SWITCH_STATE                                      Equ         4
PO_CB_PROCESSOR_POWER_POLICY                                Equ         5

OBJECT_HANDLE_INFORMATION Struct
    HandleAttributes                                        DD          ?
    GrantedAccess                                           ACCESS_MASK ?
OBJECT_HANDLE_INFORMATION EndS
POBJECT_HANDLE_INFORMATION                                  TypeDef     DWord

OB_FLT_REGISTRATION_VERSION_0100                            Equ         0100H

OB_FLT_REGISTRATION_VERSION                                 Equ         OB_FLT_REGISTRATION_VERSION_0100

OB_OPERATION                                                TypeDef     DWord

OB_OPERATION_HANDLE_CREATE                                  Equ         00000001H
OB_OPERATION_HANDLE_DUPLICATE                               Equ         00000002H

OB_PRE_CREATE_HANDLE_INFORMATION Struct
    DesiredAccess                                           ACCESS_MASK ?
    OriginalDesiredAccess                                   ACCESS_MASK ?
OB_PRE_CREATE_HANDLE_INFORMATION EndS
POB_PRE_CREATE_HANDLE_INFORMATION                           TypeDef     DWord

OB_PRE_DUPLICATE_HANDLE_INFORMATION Struct
    DesiredAccess                                           ACCESS_MASK ?
    OriginalDesiredAccess                                   ACCESS_MASK ?
    SourceProcess                                           PVOID       ?
    TargetProcess                                           PVOID       ?
OB_PRE_DUPLICATE_HANDLE_INFORMATION EndS
POB_PRE_DUPLICATE_HANDLE_INFORMATION                        TypeDef     DWord

OB_PRE_OPERATION_PARAMETERS Union
    CreateHandleInformation                                 OB_PRE_CREATE_HANDLE_INFORMATION    <>
    DuplicateHandleInformation                              OB_PRE_DUPLICATE_HANDLE_INFORMATION <>
OB_PRE_OPERATION_PARAMETERS EndS
POB_PRE_OPERATION_PARAMETERS                                TypeDef     DWord

OB_POST_CREATE_HANDLE_INFORMATION Struct
    GrantedAccess                                           ACCESS_MASK ?
OB_POST_CREATE_HANDLE_INFORMATION EndS
POB_POST_CREATE_HANDLE_INFORMATION                          TypeDef     DWord

OB_POST_DUPLICATE_HANDLE_INFORMATION Struct
    GrantedAccess                                           ACCESS_MASK ?
OB_POST_DUPLICATE_HANDLE_INFORMATION EndS
POB_POST_DUPLICATE_HANDLE_INFORMATION                       TypeDef     DWord

OB_POST_OPERATION_PARAMETERS Union
    CreateHandleInformation                                 OB_POST_CREATE_HANDLE_INFORMATION   <>
    DuplicateHandleInformation                              OB_POST_DUPLICATE_HANDLE_INFORMATION    <>
OB_POST_OPERATION_PARAMETERS EndS
POB_POST_OPERATION_PARAMETERS                               TypeDef     DWord

;OB_PREOP_CALLBACK_STATUS Enumeration
OB_PREOP_CALLBACK_STATUS                                    TypeDef     DWord
OB_PREOP_SUCCESS                                            Equ         0
POB_PREOP_CALLBACK_STATUS                                   TypeDef     DWord

OB_OPERATION_REGISTRATION Struct
    ObjectType                                              DD          ? ;POBJECT_TYPE
    Operations                                              OB_OPERATION    ?
    PreOperation                                            DD          ? ;POB_PRE_OPERATION_CALLBACK
    PostOperation                                           DD          ? ;POB_POST_OPERATION_CALLBACK
OB_OPERATION_REGISTRATION EndS
POB_OPERATION_REGISTRATION                                  TypeDef     DWord

OB_CALLBACK_REGISTRATION Struct
    Version                                                 DW          ?
    OperationRegistrationCount                              DW          ?
    Altitude                                                UNICODE_STRING  <>
    RegistrationContext                                     PVOID       ?
    OperationRegistration                                   POB_OPERATION_REGISTRATION  ?
OB_CALLBACK_REGISTRATION EndS
POB_CALLBACK_REGISTRATION                                   TypeDef     DWord

PCI_TYPE0_ADDRESSES                                         Equ         6
PCI_TYPE1_ADDRESSES                                         Equ         2
PCI_TYPE2_ADDRESSES                                         Equ         5

PCI_EXTENDED_CONFIG_LENGTH                                  Equ         1000H

PCI_MAX_DEVICES                                             Equ         32
PCI_MAX_FUNCTION                                            Equ         8
PCI_MAX_BRIDGE_NUMBER                                       Equ         0FFH

PCI_INVALID_VENDORID                                        Equ         0FFFFH

PCI_MULTIFUNCTION                                           Equ         80H
PCI_DEVICE_TYPE                                             Equ         00H
PCI_BRIDGE_TYPE                                             Equ         01H
PCI_CARDBUS_BRIDGE_TYPE                                     Equ         02H

PCI_ENABLE_IO_SPACE                                         Equ         0001H
PCI_ENABLE_MEMORY_SPACE                                     Equ         0002H
PCI_ENABLE_BUS_MASTER                                       Equ         0004H
PCI_ENABLE_SPECIAL_CYCLES                                   Equ         0008H
PCI_ENABLE_WRITE_AND_INVALIDATE                             Equ         0010H
PCI_ENABLE_VGA_COMPATIBLE_PALETTE                           Equ         0020H
PCI_ENABLE_PARITY                                           Equ         0040H
PCI_ENABLE_WAIT_CYCLE                                       Equ         0080H
PCI_ENABLE_SERR                                             Equ         0100H
PCI_ENABLE_FAST_BACK_TO_BACK                                Equ         0200H
PCI_DISABLE_LEVEL_INTERRUPT                                 Equ         0400H

PCI_STATUS_INTERRUPT_PENDING                                Equ         0008H
PCI_STATUS_CAPABILITIES_LIST                                Equ         0010H
PCI_STATUS_66MHZ_CAPABLE                                    Equ         0020H
PCI_STATUS_UDF_SUPPORTED                                    Equ         0040H
PCI_STATUS_FAST_BACK_TO_BACK                                Equ         0080H
PCI_STATUS_DATA_PARITY_DETECTED                             Equ         0100H
PCI_STATUS_DEVSEL                                           Equ         0600H
PCI_STATUS_SIGNALED_TARGET_ABORT                            Equ         0800H
PCI_STATUS_RECEIVED_TARGET_ABORT                            Equ         1000H
PCI_STATUS_RECEIVED_MASTER_ABORT                            Equ         2000H
PCI_STATUS_SIGNALED_SYSTEM_ERROR                            Equ         4000H
PCI_STATUS_DETECTED_PARITY_ERROR                            Equ         8000H

PCI_WHICHSPACE_CONFIG                                       Equ         0H
PCI_WHICHSPACE_ROM                                          Equ         52696350H

PCI_CAPABILITY_ID_POWER_MANAGEMENT                          Equ         01H
PCI_CAPABILITY_ID_AGP                                       Equ         02H
PCI_CAPABILITY_ID_VPD                                       Equ         03H
PCI_CAPABILITY_ID_SLOT_ID                                   Equ         04H
PCI_CAPABILITY_ID_MSI                                       Equ         05H
PCI_CAPABILITY_ID_CPCI_HOTSWAP                              Equ         06H
PCI_CAPABILITY_ID_PCIX                                      Equ         07H
PCI_CAPABILITY_ID_HYPERTRANSPORT                            Equ         08H
PCI_CAPABILITY_ID_VENDOR_SPECIFIC                           Equ         09H
PCI_CAPABILITY_ID_DEBUG_PORT                                Equ         0AH
PCI_CAPABILITY_ID_CPCI_RES_CTRL                             Equ         0BH
PCI_CAPABILITY_ID_SHPC                                      Equ         0CH
PCI_CAPABILITY_ID_P2P_SSID                                  Equ         0DH
PCI_CAPABILITY_ID_AGP_TARGET                                Equ         0EH
PCI_CAPABILITY_ID_SECURE                                    Equ         0FH
PCI_CAPABILITY_ID_PCI_EXPRESS                               Equ         10H
PCI_CAPABILITY_ID_MSIX                                      Equ         11H

PCI_CAPABILITIES_HEADER Struct
    CapabilityID                                            DB          ?
    Next                                                    DB          ?
PCI_CAPABILITIES_HEADER EndS
PPCI_CAPABILITIES_HEADER                                    TypeDef     DWord

PCI_EXPRESS_ADVANCED_ERROR_REPORTING_CAP_ID                 Equ         0001H
PCI_EXPRESS_VIRTUAL_CHANNEL_CAP_ID                          Equ         0002H
PCI_EXPRESS_DEVICE_SERIAL_NUMBER_CAP_ID                     Equ         0003H
PCI_EXPRESS_POWER_BUDGETING_CAP_ID                          Equ         0004H
PCI_EXPRESS_RC_LINK_DECLARATION_CAP_ID                      Equ         0005H
PCI_EXPRESS_RC_INTERNAL_LINK_CONTROL_CAP_ID                 Equ         0006H
PCI_EXPRESS_RC_EVENT_COLLECTOR_ENDPOINT_ASSOCIATION_CAP_ID  Equ         0007H
PCI_EXPRESS_MFVC_CAP_ID                                     Equ         0008H
PCI_EXPRESS_VC_AND_MFVC_CAP_ID                              Equ         0009H
PCI_EXPRESS_RCRB_HEADER_CAP_ID                              Equ         000AH
PCI_EXPRESS_SINGLE_ROOT_IO_VIRTUALIZATION_CAP_ID            Equ         0010H

ROOT_CMD_ENABLE_CORRECTABLE_ERROR_REPORTING                 Equ         00000001H
ROOT_CMD_ENABLE_NONFATAL_ERROR_REPORTING                    Equ         00000002H
ROOT_CMD_ENABLE_FATAL_ERROR_REPORTING                       Equ         00000004H

ROOT_CMD_ERROR_REPORTING_ENABLE_MASK                        Equ         (ROOT_CMD_ENABLE_FATAL_ERROR_REPORTING Or ROOT_CMD_ENABLE_NONFATAL_ERROR_REPORTING Or ROOT_CMD_ENABLE_CORRECTABLE_ERROR_REPORTING)

PCI_CLASS_PRE_20                                            Equ         00H
PCI_CLASS_MASS_STORAGE_CTLR                                 Equ         01H
PCI_CLASS_NETWORK_CTLR                                      Equ         02H
PCI_CLASS_DISPLAY_CTLR                                      Equ         03H
PCI_CLASS_MULTIMEDIA_DEV                                    Equ         04H
PCI_CLASS_MEMORY_CTLR                                       Equ         05H
PCI_CLASS_BRIDGE_DEV                                        Equ         06H
PCI_CLASS_SIMPLE_COMMS_CTLR                                 Equ         07H
PCI_CLASS_BASE_SYSTEM_DEV                                   Equ         08H
PCI_CLASS_INPUT_DEV                                         Equ         09H
PCI_CLASS_DOCKING_STATION                                   Equ         0AH
PCI_CLASS_PROCESSOR                                         Equ         0BH
PCI_CLASS_SERIAL_BUS_CTLR                                   Equ         0CH
PCI_CLASS_WIRELESS_CTLR                                     Equ         0DH
PCI_CLASS_INTELLIGENT_IO_CTLR                               Equ         0EH
PCI_CLASS_SATELLITE_COMMS_CTLR                              Equ         0FH
PCI_CLASS_ENCRYPTION_DECRYPTION                             Equ         10H
PCI_CLASS_DATA_ACQ_SIGNAL_PROC                              Equ         11H

PCI_CLASS_NOT_DEFINED                                       Equ         0FFH

PCI_SUBCLASS_PRE_20_NON_VGA                                 Equ         00H
PCI_SUBCLASS_PRE_20_VGA                                     Equ         01H

PCI_SUBCLASS_MSC_SCSI_BUS_CTLR                              Equ         00H
PCI_SUBCLASS_MSC_IDE_CTLR                                   Equ         01H
PCI_SUBCLASS_MSC_FLOPPY_CTLR                                Equ         02H
PCI_SUBCLASS_MSC_IPI_CTLR                                   Equ         03H
PCI_SUBCLASS_MSC_RAID_CTLR                                  Equ         04H
PCI_SUBCLASS_MSC_OTHER                                      Equ         80H

PCI_SUBCLASS_NET_ETHERNET_CTLR                              Equ         00H
PCI_SUBCLASS_NET_TOKEN_RING_CTLR                            Equ         01H
PCI_SUBCLASS_NET_FDDI_CTLR                                  Equ         02H
PCI_SUBCLASS_NET_ATM_CTLR                                   Equ         03H
PCI_SUBCLASS_NET_ISDN_CTLR                                  Equ         04H
PCI_SUBCLASS_NET_OTHER                                      Equ         80H

PCI_SUBCLASS_VID_VGA_CTLR                                   Equ         00H
PCI_SUBCLASS_VID_XGA_CTLR                                   Equ         01H
PCI_SUBLCASS_VID_3D_CTLR                                    Equ         02H
PCI_SUBCLASS_VID_OTHER                                      Equ         80H

PCI_SUBCLASS_MM_VIDEO_DEV                                   Equ         00H
PCI_SUBCLASS_MM_AUDIO_DEV                                   Equ         01H
PCI_SUBCLASS_MM_TELEPHONY_DEV                               Equ         02H
PCI_SUBCLASS_MM_OTHER                                       Equ         80H

PCI_SUBCLASS_MEM_RAM                                        Equ         00H
PCI_SUBCLASS_MEM_FLASH                                      Equ         01H
PCI_SUBCLASS_MEM_OTHER                                      Equ         80H

PCI_SUBCLASS_BR_HOST                                        Equ         00H
PCI_SUBCLASS_BR_ISA                                         Equ         01H
PCI_SUBCLASS_BR_EISA                                        Equ         02H
PCI_SUBCLASS_BR_MCA                                         Equ         03H
PCI_SUBCLASS_BR_PCI_TO_PCI                                  Equ         04H
PCI_SUBCLASS_BR_PCMCIA                                      Equ         05H
PCI_SUBCLASS_BR_NUBUS                                       Equ         06H
PCI_SUBCLASS_BR_CARDBUS                                     Equ         07H
PCI_SUBCLASS_BR_RACEWAY                                     Equ         08H
PCI_SUBCLASS_BR_OTHER                                       Equ         80H

PCI_SUBCLASS_COM_SERIAL                                     Equ         00H
PCI_SUBCLASS_COM_PARALLEL                                   Equ         01H
PCI_SUBCLASS_COM_MULTIPORT                                  Equ         02H
PCI_SUBCLASS_COM_MODEM                                      Equ         03H
PCI_SUBCLASS_COM_OTHER                                      Equ         80H

PCI_SUBCLASS_SYS_INTERRUPT_CTLR                             Equ         00H
PCI_SUBCLASS_SYS_DMA_CTLR                                   Equ         01H
PCI_SUBCLASS_SYS_SYSTEM_TIMER                               Equ         02H
PCI_SUBCLASS_SYS_REAL_TIME_CLOCK                            Equ         03H
PCI_SUBCLASS_SYS_GEN_HOTPLUG_CTLR                           Equ         04H
PCI_SUBCLASS_SYS_SDIO_CTRL                                  Equ         05H
PCI_SUBCLASS_SYS_OTHER                                      Equ         80H

PCI_SUBCLASS_INP_KEYBOARD                                   Equ         00H
PCI_SUBCLASS_INP_DIGITIZER                                  Equ         01H
PCI_SUBCLASS_INP_MOUSE                                      Equ         02H
PCI_SUBCLASS_INP_SCANNER                                    Equ         03H
PCI_SUBCLASS_INP_GAMEPORT                                   Equ         04H
PCI_SUBCLASS_INP_OTHER                                      Equ         80H

PCI_SUBCLASS_DOC_GENERIC                                    Equ         00H
PCI_SUBCLASS_DOC_OTHER                                      Equ         80H

PCI_SUBCLASS_PROC_386                                       Equ         00H
PCI_SUBCLASS_PROC_486                                       Equ         01H
PCI_SUBCLASS_PROC_PENTIUM                                   Equ         02H
PCI_SUBCLASS_PROC_ALPHA                                     Equ         10H
PCI_SUBCLASS_PROC_POWERPC                                   Equ         20H
PCI_SUBCLASS_PROC_COPROCESSOR                               Equ         40H

PCI_SUBCLASS_SB_IEEE1394                                    Equ         00H
PCI_SUBCLASS_SB_ACCESS                                      Equ         01H
PCI_SUBCLASS_SB_SSA                                         Equ         02H
PCI_SUBCLASS_SB_USB                                         Equ         03H
PCI_SUBCLASS_SB_FIBRE_CHANNEL                               Equ         04H
PCI_SUBCLASS_SB_SMBUS                                       Equ         05H

PCI_SUBCLASS_WIRELESS_IRDA                                  Equ         00H
PCI_SUBCLASS_WIRELESS_CON_IR                                Equ         01H
PCI_SUBCLASS_WIRELESS_RF                                    Equ         10H
PCI_SUBCLASS_WIRELESS_OTHER                                 Equ         80H

PCI_SUBCLASS_INTIO_I2O                                      Equ         00H

PCI_SUBCLASS_SAT_TV                                         Equ         01H
PCI_SUBCLASS_SAT_AUDIO                                      Equ         02H
PCI_SUBCLASS_SAT_VOICE                                      Equ         03H
PCI_SUBCLASS_SAT_DATA                                       Equ         04H

PCI_SUBCLASS_CRYPTO_NET_COMP                                Equ         00H
PCI_SUBCLASS_CRYPTO_ENTERTAINMENT                           Equ         10H
PCI_SUBCLASS_CRYPTO_OTHER                                   Equ         80H

PCI_SUBCLASS_DASP_DPIO                                      Equ         00H
PCI_SUBCLASS_DASP_OTHER                                     Equ         80H

PCI_ADDRESS_IO_SPACE                                        Equ         00000001H
PCI_ADDRESS_MEMORY_TYPE_MASK                                Equ         00000006H
PCI_ADDRESS_MEMORY_PREFETCHABLE                             Equ         00000008H

PCI_ADDRESS_IO_ADDRESS_MASK                                 Equ         0FFFFFFFCH
PCI_ADDRESS_MEMORY_ADDRESS_MASK                             Equ         0FFFFFFF0H
PCI_ADDRESS_ROM_ADDRESS_MASK                                Equ         0FFFFF800H

PCI_TYPE_32BIT                                              Equ         0
PCI_TYPE_20BIT                                              Equ         2
PCI_TYPE_64BIT                                              Equ         4

PCI_ROMADDRESS_ENABLED                                      Equ         00000001H

PCI_DEVICE_PRESENT_INTERFACE_VERSION                        Equ         1

PCI_USE_SUBSYSTEM_IDS                                       Equ         00000001H
PCI_USE_REVISION                                            Equ         00000002H
PCI_USE_VENDEV_IDS                                          Equ         00000004H
PCI_USE_CLASS_SUBCLASS                                      Equ         00000008H
PCI_USE_PROGIF                                              Equ         00000010H
PCI_USE_LOCAL_BUS                                           Equ         00000020H
PCI_USE_LOCAL_DEVICE                                        Equ         00000040H

PCI_DEVICE_PRESENCE_PARAMETERS Struct
    _Size                                                   DD          ?
    Flags                                                   DD          ?
    VendorID                                                DW          ?
    DeviceID                                                DW          ?
    RevisionID                                              DB          ?
    SubVendorID                                             DW          ?
    SubSystemID                                             DW          ?
    BaseClass                                               DB          ?
    SubClass                                                DB          ?
    ProgIf                                                  DB          ?
PCI_DEVICE_PRESENCE_PARAMETERS EndS
PPCI_DEVICE_PRESENCE_PARAMETERS                             TypeDef     DWord

PCI_DEVICE_PRESENT_INTERFACE Struct
    _Size                                                   DW          ?   ;Size
    Version                                                 DW          ?
    Context                                                 PVOID       ?
    InterfaceReference                                      DD          ?   ;PINTERFACE_REFERENCE
    InterfaceDereference                                    DD          ?   ;PINTERFACE_DEREFERENCE
    IsDevicePresent                                         DD          ?
    IsDevicePresentEx                                       DD          ?
PCI_DEVICE_PRESENT_INTERFACE EndS
PPCI_DEVICE_PRESENT_INTERFACE                               TypeDef     DWord

PCI_EXPRESS_LINK_QUIESCENT_INTERFACE_VERSION                Equ         1

PCI_EXPRESS_LINK_QUIESCENT_INTERFACE Struct
    _Size                                                   DW          ?   ;Size
    Version                                                 DW          ?
    Context                                                 PVOID       ?
    InterfaceReference                                      DD          ?   ;PINTERFACE_REFERENCE
    InterfaceDereference                                    DD          ?   ;PINTERFACE_DEREFERENCE
    PciExpressEnterLinkQuiescentMode                        DD          ?
    PciExpressExitLinkQuiescentMode                         DD          ?
PCI_EXPRESS_LINK_QUIESCENT_INTERFACE EndS
PPCI_EXPRESS_LINK_QUIESCENT_INTERFACE                       TypeDef     DWord

PCI_EXPRESS_ROOT_PORT_INTERFACE_VERSION                     Equ         1

PCI_EXPRESS_ROOT_PORT_INTERFACE Struct
    _Size                                                   DW          ?   ;Size
    Version                                                 DW          ?
    Context                                                 PVOID       ?
    InterfaceReference                                      DD          ?   ;PINTERFACE_REFERENCE
    InterfaceDereference                                    DD          ?   ;PINTERFACE_DEREFERENCE
    ReadConfigSpace                                         DD          ?
    WriteConfigSpace                                        DD          ?
PCI_EXPRESS_ROOT_PORT_INTERFACE EndS
PPCI_EXPRESS_ROOT_PORT_INTERFACE                            TypeDef     DWord

PCI_MSIX_TABLE_CONFIG_INTERFACE_VERSION                     Equ         1

PCI_MSIX_TABLE_CONFIG_INTERFACE Struct
    _Size                                                   DW          ?   ;Size
    Version                                                 DW          ?
    Context                                                 PVOID       ?
    InterfaceReference                                      DD          ?   ;PINTERFACE_REFERENCE
    InterfaceDereference                                    DD          ?   ;PINTERFACE_DEREFERENCE
    SetTableEntry                                           DD          ?
    MaskTableEntry                                          DD          ?
    UnmaskTableEntry                                        DD          ?
    GetTableEntry                                           DD          ?
    GetTableSize                                            DD          ?
PCI_MSIX_TABLE_CONFIG_INTERFACE EndS
PPCI_MSIX_TABLE_CONFIG_INTERFACE                            TypeDef     DWord

;EM_RULE_STATE  Enumeration
EM_RULE_STATE                                               TypeDef     DWord
STATE_FALSE                                                 Equ         0
STATE_UNKNOWN                                               Equ         1
STATE_TRUE                                                  Equ         2
PEM_RULE_STATE                                              TypeDef     DWord

EM_ENTRY_DATA Struct
    Data                                                    PVOID       ?
    DataLength                                              DD          ?
EM_ENTRY_DATA EndS
PEM_ENTRY_DATA                                              TypeDef     DWord

EM_ENTRY_REGISTRATION Struct
    EntryGuid                                               LPCGUID     ?
    LazyEntryCallback                                       DD          ?
    LazyCallbackContext                                     PVOID       ?
EM_ENTRY_REGISTRATION EndS
PEM_ENTRY_REGISTRATION                                      TypeDef     DWord

EM_CALLBACK_REGISTRATION Struct
    CallbackGuid                                            LPCGUID     ?
    CallbackFunction                                        DD          ?
    Context                                                 PVOID       ?
EM_CALLBACK_REGISTRATION EndS
PEM_CALLBACK_REGISTRATION                                   TypeDef     DWord

EM_CLIENT_NOTIFICATION_REGISTRATION Struct
    RuleId                                                  LPCGUID     ?
    RuleNotifyCallback                                      DD          ?
    Context                                                 PVOID       ?
EM_CLIENT_NOTIFICATION_REGISTRATION EndS
PEM_CLIENT_NOTIFICATION_REGISTRATION                        TypeDef     DWord

FILE_ATTRIBUTE_DEDICATED                                    Equ         FILE_ATTRIBUTE_TEMPORARY

EA_CONTAINER_NAME                                           Equ         A("ContainerName")
EA_CONTAINER_SIZE                                           Equ         A("ContainerSize")

CLFS_BASELOG_EXTENSION                                      Equ         L(".blf")

CLFS_FLAG_NO_FLAGS                                          Equ         00000000H
CLFS_FLAG_FORCE_APPEND                                      Equ         00000001H
CLFS_FLAG_FORCE_FLUSH                                       Equ         00000002H
CLFS_FLAG_USE_RESERVATION                                   Equ         00000004H
CLFS_FLAG_REENTRANT_FILE_SYSTEM                             Equ         00000008H
CLFS_FLAG_NON_REENTRANT_FILTER                              Equ         00000010H
CLFS_FLAG_REENTRANT_FILTER                                  Equ         00000020H
CLFS_FLAG_IGNORE_SHARE_ACCESS                               Equ         00000040H
CLFS_FLAG_READ_IN_PROGRESS                                  Equ         00000080H
CLFS_FLAG_MINIFILTER_LEVEL                                  Equ         00000100H
CLFS_FLAG_HIDDEN_SYSTEM_LOG                                 Equ         00000200H

CLFS_FLAG_FILTER_INTERMEDIATE_LEVEL                         Equ         CLFS_FLAG_NON_REENTRANT_FILTER

CLFS_FLAG_FILTER_TOP_LEVEL                                  Equ         CLFS_FLAG_REENTRANT_FILTER

CLFS_CONTAINER_ID                                           TypeDef     DWord
PCLFS_CONTAINER_ID                                          TypeDef     DWord

;CLS_CONTEXT_MODE Enumeration
CLS_CONTEXT_MODE                                            TypeDef     DWord
ClsContextNone                                              Equ         00H
ClsContextUndoNext                                          Equ         01H
ClsContextPrevious                                          Equ         02H
ClsContextForward                                           Equ         03H
PCLS_CONTEXT_MODE                                           TypeDef     DWord

;CLFS_CONTEXT_MODE Enumeration
CLFS_CONTEXT_MODE                                           TypeDef     DWord
ClfsContextNone                                             Equ         00H
ClfsContextUndoNext                                         Equ         01H
ClfsContextPrevious                                         Equ         02H
ClfsContextForward                                          Equ         03H
PCLFS_CONTEXT_MODE                                          TypeDef     DWord

CLFS_NODE_ID Struct
    cType                                                   DD          ?
    cbNode                                                  DD          ?
CLFS_NODE_ID EndS
PCLFS_NODE_ID                                               TypeDef     DWord

CLS_WRITE_ENTRY Struct
    Buffer                                                  PVOID       ?
    ByteLength                                              DD          ?
CLS_WRITE_ENTRY EndS
PCLS_WRITE_ENTRY                                            TypeDef     DWord

CLFS_WRITE_ENTRY                                            TypeDef     CLS_WRITE_ENTRY
PCLFS_WRITE_ENTRY                                           TypeDef     DWord

CLFS_LOG_ID                                                 TypeDef     GUID

IFNDEF CLS_LSN
    CLS_LSN Struct
        _Internal                                           DQ          ? ;Internal
    CLS_LSN EndS
    CLFS_LSN                                                TypeDef     CLS_LSN
    PCLS_LSN                                                TypeDef     DWord
    PCLFS_LSN                                               TypeDef     DWord
ENDIF

CLS_INFORMATION Struct
    TotalAvailable                                          DQ          ?
    CurrentAvailable                                        DQ          ?
    TotalReservation                                        DQ          ?
    BaseFileSize                                            DQ          ?
    ContainerSize                                           DQ          ?
    TotalContainers                                         DD          ?
    FreeContainers                                          DD          ?
    TotalClients                                            DD          ?
    Attributes                                              DD          ?
    FlushThreshold                                          DD          ?
    SectorSize                                              DD          ?
    MinArchiveTailLsn                                       CLS_LSN     <>
    BaseLsn                                                 CLS_LSN     <>
    LastFlushedLsn                                          CLS_LSN     <>
    LastLsn                                                 CLS_LSN     <>
    RestartLsn                                              CLS_LSN     <>
    Identity                                                GUID        <>
CLS_INFORMATION EndS
PCLS_INFORMATION                                            TypeDef     DWord

CLFS_INFORMATION                                            TypeDef     CLS_INFORMATION
PCLFS_INFORMATION                                           TypeDef     DWord

CLS_CLIENT_INFORMATION Struct
    ClfsInfo                                                CLS_INFORMATION <>
    ClientAttributes                                        DD          ?
    ClientUndoCommitment                                    DQ          ?
    ClientArchiveTailLsn                                    CLS_LSN     <>
    ClientBaseLsn                                           CLS_LSN     <>
    ClientLastLsn                                           CLS_LSN     <>
    ClientRestartLsn                                        CLS_LSN     <>
CLS_CLIENT_INFORMATION EndS
PCLS_CLIENT_INFORMATION                                     TypeDef     DWord

CLFS_CLIENT_INFORMATION                                     TypeDef     CLS_CLIENT_INFORMATION
PCLFS_CLIENT_INFORMATION                                    TypeDef     DWord

CLFS_LOG_NAME_INFORMATION Struct
    NameLengthInBytes                                       DW          ?
    _Name                                                   DW          1 Dup(?)
CLFS_LOG_NAME_INFORMATION EndS
PCLFS_LOG_NAME_INFORMATION                                  TypeDef     DWord

CLFS_STREAM_ID_INFORMATION Struct
    StreamIdentifier                                        DB          ?
CLFS_STREAM_ID_INFORMATION EndS
PCLFS_STREAM_ID_INFORMATION                                 TypeDef     DWord

CLFS_PHYSICAL_LSN_INFORMATION Struct
    StreamIdentifier                                        DB          ?
    VirtualLsn                                              CLFS_LSN    <>
    PhysicalLsn                                             CLFS_LSN    <>
CLFS_PHYSICAL_LSN_INFORMATION EndS
PCLFS_PHYSICAL_LSN_INFORMATION                              TypeDef     DWord

CLS_CONTAINER_STATE                                         TypeDef     DWord
PCLS_CONTAINER_STATE                                        TypeDef     DWord
CLFS_CONTAINER_STATE                                        TypeDef     CLS_CONTAINER_STATE
PCLFS_CONTAINER_STATE                                       TypeDef     DWord

CLS_CONTAINER_INFORMATION Struct
    FileAttributes                                          DD          ?
    CreationTime                                            DQ          ?
    LastAccessTime                                          DQ          ?
    LastWriteTime                                           DQ          ?
    ContainerSize                                           DQ          ?
    FileNameActualLength                                    DD          ?
    FileNameLength                                          DD          ?
    FileName                                                DW          CLFS_MAX_CONTAINER_INFO Dup(?)
    State                                                   CLFS_CONTAINER_STATE ?
    PhysicalContainerId                                     CLFS_CONTAINER_ID   ?
    LogicalContainerId                                      CLFS_CONTAINER_ID   ?
CLS_CONTAINER_INFORMATION EndS
PCLS_CONTAINER_INFORMATION                                  TypeDef     DWord

CLFS_CONTAINER_INFORMATION                                  TypeDef     CLS_CONTAINER_INFORMATION
PCLFS_CONTAINER_INFORMATION                                 TypeDef     DWord

;CLS_IOSTATS_CLASS Enumeration
CLS_IOSTATS_CLASS                                           TypeDef     DWord
ClsIoStatsDefault                                           Equ         00000H
ClsIoStatsMax                                               Equ         0FFFFH
PCLS_IOSTATS_CLASS                                          TypeDef     DWord

;CLFS_IOSTATS_CLASS Enumeration
CLFS_IOSTATS_CLASS                                          TypeDef     DWord
ClfsIoStatsDefault                                          Equ         00000H
ClfsIoStatsMax                                              Equ         0FFFFH
PCLFS_IOSTATS_CLASS                                         TypeDef     DWord

CLS_IO_STATISTICS_HEADER Struct
    ubMajorVersion                                          DB          ?
    ubMinorVersion                                          DB          ?
    eStatsClass                                             CLFS_IOSTATS_CLASS  ?
    cbLength                                                DW          ?
    coffData                                                DD          ?
CLS_IO_STATISTICS_HEADER EndS
PCLS_IO_STATISTICS_HEADER                                   TypeDef     DWord

CLFS_IO_STATISTICS_HEADER                                   TypeDef     CLS_IO_STATISTICS_HEADER
PCLFS_IO_STATISTICS_HEADER                                  TypeDef     DWord

CLS_IO_STATISTICS Struct
    hdrIoStats                                              CLS_IO_STATISTICS_HEADER    <>
    cFlush                                                  DQ          ?
    cbFlush                                                 DQ          ?
    cMetaFlush                                              DQ          ?
    cbMetaFlush                                             DQ          ?
CLS_IO_STATISTICS EndS
PCLS_IO_STATISTICS                                          TypeDef     DWord

CLFS_IO_STATISTICS                                          TypeDef     CLS_IO_STATISTICS
PCLFS_IO_STATISTICS                                         TypeDef     DWord

CLFS_SCAN_INIT                                              Equ         01H
CLFS_SCAN_FORWARD                                           Equ         02H
CLFS_SCAN_BACKWARD                                          Equ         04H
CLFS_SCAN_CLOSE                                             Equ         08H
CLFS_SCAN_INITIALIZED                                       Equ         10H
CLFS_SCAN_BUFFERED                                          Equ         20H

CLFS_SCAN_MODE                                              TypeDef     Byte
PCLFS_SCAN_MODE                                             TypeDef     DWord

LOG_FILE_OBJECT                                             TypeDef     FILE_OBJECT
PLOG_FILE_OBJECT                                            TypeDef     DWord

CLS_SCAN_CONTEXT Struct
    cidNode                                                 CLFS_NODE_ID    <>
    plfoLog                                                 PLOG_FILE_OBJECT    ?
    cIndex                                                  DD          ?
    cContainers                                             DD          ?
    cContainersReturned                                     DD          ?
    eScanMode                                               CLFS_SCAN_MODE  ?
    pinfoContainer                                          PCLS_CONTAINER_INFORMATION  ?
CLS_SCAN_CONTEXT EndS
PCLS_SCAN_CONTEXT                                           TypeDef     DWord

CLFS_SCAN_CONTEXT                                           TypeDef     CLS_SCAN_CONTEXT
PCLFS_SCAN_CONTEXT                                          TypeDef     DWord

CLS_ARCHIVE_DESCRIPTOR Struct
    coffLow                                                 DQ          ?
    coffHigh                                                DQ          ?
    infoContainer                                           CLS_CONTAINER_INFORMATION   <>
CLS_ARCHIVE_DESCRIPTOR EndS
PCLS_ARCHIVE_DESCRIPTOR                                     TypeDef     DWord

CLFS_ARCHIVE_DESCRIPTOR                                     TypeDef     CLS_ARCHIVE_DESCRIPTOR
PCLFS_ARCHIVE_DESCRIPTOR                                    TypeDef     DWord

;CLFS_LOG_ARCHIVE_MODE Enumeration
CLFS_LOG_ARCHIVE_MODE                                       TypeDef     DWord
ClfsLogArchiveEnabled                                       Equ         01H
ClfsLogArchiveDisabled                                      Equ         02H
PCLFS_LOG_ARCHIVE_MODE                                      TypeDef     DWord

;CLFS_MGMT_POLICY_TYPE Enumeration
CLFS_MGMT_POLICY_TYPE                                       TypeDef     DWord
ClfsMgmtPolicyMaximumSize                                   Equ         00H
ClfsMgmtPolicyMinimumSize                                   Equ         01H
ClfsMgmtPolicyNewContainerSize                              Equ         02H
ClfsMgmtPolicyGrowthRate                                    Equ         03H
ClfsMgmtPolicyLogTail                                       Equ         04H
ClfsMgmtPolicyAutoShrink                                    Equ         05H
ClfsMgmtPolicyAutoGrow                                      Equ         06H
ClfsMgmtPolicyNewContainerPrefix                            Equ         07H
ClfsMgmtPolicyNewContainerSuffix                            Equ         08H
ClfsMgmtPolicyNewContainerExtension                         Equ         09H
ClfsMgmtPolicyInvalid                                       Equ         0AH
PCLFS_MGMT_POLICY_TYPE                                      TypeDef     DWord

CLFS_MGMT_POLICY_VERSION                                    Equ         (01H)

LOG_POLICY_OVERWRITE                                        Equ         (01H)
LOG_POLICY_PERSIST                                          Equ         (02H)

CLFS_MGMT_POLICY Struct
    Version                                                 DD          ?
    LengthInBytes                                           DD          ?
    PolicyFlags                                             DD          ?
    PolicyType                                              CLFS_MGMT_POLICY_TYPE   ?
    Union PolicyParameters
        Struct MaximumSize
            Containers                                      DD          ?
        EndS
        Struct MinimumSize
            Containers                                      DD          ?
        EndS
        Struct NewContainerSize
            SizeInBytes                                     DD          ?
        EndS
        Struct GrowthRate
            AbsoluteGrowthInContainers                      DD          ?
            RelativeGrowthPercentage                        DD          ?
        EndS
        Struct LogTail
            MinimumAvailablePercentage                      DD          ?
            MinimumAvailableContainers                      DD          ?
        EndS
        Struct AutoShrink
            Percentage                                      DD          ?
        EndS
        Struct AutoGrow
            Enabled                                         DD          ?
        EndS
        Struct NewContainerPrefix
            PrefixLengthInBytes                             DW          ?
            PrefixString                                    DW          1 Dup(?)
        EndS
        Struct NewContainerSuffix
            NextContainerSuffix                             DQ          ?
        EndS
        Struct NewContainerExtension
            ExtensionLengthInBytes                          DW          ?
            ExtensionString                                 DW          1 Dup(?)
        EndS
    EndS
CLFS_MGMT_POLICY EndS
PCLFS_MGMT_POLICY                                           TypeDef     DWord

;CLFS_MGMT_NOTIFICATION_TYPE Enumeration
CLFS_MGMT_NOTIFICATION_TYPE                                 TypeDef     DWord
ClfsMgmtAdvanceTailNotification                             Equ         0
ClfsMgmtLogFullHandlerNotification                          Equ         1
ClfsMgmtLogUnpinnedNotification                             Equ         2
ClfsMgmtLogWriteNotification                                Equ         3
PCLFS_MGMT_NOTIFICATION_TYPE                                TypeDef     DWord

CLFS_MGMT_NOTIFICATION Struct
    Notification                                            CLFS_MGMT_NOTIFICATION_TYPE ?
    Lsn                                                     CLFS_LSN    <>
    LogIsPinned                                             DW          ?
CLFS_MGMT_NOTIFICATION EndS
PCLFS_MGMT_NOTIFICATION                                     TypeDef     DWord

CLFS_MGMT_CLIENT_REGISTRATION_VERSION                       Equ         (01H)

CLFS_MGMT_CLIENT_REGISTRATION Struct
    Version                                                 DD          ?
    AdvanceTailCallback                                     DD          ? ;PCLFS_CLIENT_ADVANCE_TAIL_CALLBACK
    AdvanceTailCallbackData                                 PVOID       ?
    LogGrowthCompleteCallback                               DD          ? ;PCLFS_CLIENT_LFF_HANDLER_COMPLETE_CALLBACK
    LogGrowthCompleteCallbackData                           PVOID       ?
    LogUnpinnedCallback                                     DD          ? ;PCLFS_CLIENT_LOG_UNPINNED_CALLBACK
    LogUnpinnedCallbackData                                 PVOID       ?
CLFS_MGMT_CLIENT_REGISTRATION EndS
PCLFS_MGMT_CLIENT_REGISTRATION                              TypeDef     DWord

CLFS_MGMT_CLIENT                                            TypeDef     DWord
PCLFS_MGMT_CLIENT                                           TypeDef     DWord

PCW_VERSION_1                                               Equ         0100H
PCW_CURRENT_VERSION                                         Equ         PCW_VERSION_1

PCW_COUNTER_DESCRIPTOR Struct
    Id                                                      DW          ?
    StructIndex                                             DW          ?
    _Offset                                                 DW          ?   ;Offset
    _Size                                                   DW          ?   ;Size
PCW_COUNTER_DESCRIPTOR EndS
PPCW_COUNTER_DESCRIPTOR                                     TypeDef     DWord

PCW_DATA Struct
    Data                                                    PVOID       ?
    _Size                                                   DD          ?   ;Size
PCW_DATA EndS
PPCW_DATA                                                   TypeDef     DWord

PCW_COUNTER_INFORMATION Struct
    CounterMask                                             DQ          ?
    InstanceMask                                            PUNICODE_STRING    ?
PCW_COUNTER_INFORMATION EndS
PPCW_COUNTER_INFORMATION                                    TypeDef     DWord

PCW_MASK_INFORMATION Struct
    CounterMask                                             DQ          ?
    InstanceMask                                            PUNICODE_STRING    ?
    InstanceId                                              DD          ?
    CollectMultiple                                         BOOLEAN     ?
    Buffer                                                  DD          ? ;PPCW_BUFFER
    CancelEvent                                             PKEVENT     ?
PCW_MASK_INFORMATION EndS
PPCW_MASK_INFORMATION                                       TypeDef     DWord

PCW_CALLBACK_INFORMATION Union
    AddCounter                                              PCW_COUNTER_INFORMATION <>
    RemoveCounter                                           PCW_COUNTER_INFORMATION <>
    EnumerateInstances                                      PCW_MASK_INFORMATION    <>
    CollectData                                             PCW_MASK_INFORMATION    <>
PCW_CALLBACK_INFORMATION EndS
PPCW_CALLBACK_INFORMATION                                   TypeDef     DWord

;PCW_CALLBACK_TYPE Enumeration
PCW_CALLBACK_TYPE                                           TypeDef     DWord
PcwCallbackAddCounter                                       Equ         0
PcwCallbackRemoveCounter                                    Equ         1
PcwCallbackEnumerateInstances                               Equ         2
PcwCallbackCollectData                                      Equ         3
PPCW_CALLBACK_TYPE                                          TypeDef     DWord

PCW_REGISTRATION_INFORMATION Struct
    Version                                                 DD          ?
    _Name                                                   PUNICODE_STRING    ?
    CounterCount                                            DD          ?
    Counters                                                PPCW_COUNTER_DESCRIPTOR ?
    Callback                                                DD          ? ;PPCW_CALLBACK
    CallbackContext                                         PVOID       ?
PCW_REGISTRATION_INFORMATION EndS
PPCW_REGISTRATION_INFORMATION                               TypeDef     DWord

PsGetCurrentProcess                                         Equ         IoGetCurrentProcess

KERNEL_STACK_SIZE                                           Equ         12288

KERNEL_LARGE_STACK_SIZE                                     Equ         61440

KERNEL_LARGE_STACK_COMMIT                                   Equ         12288

PF_TEMPORAL_LEVEL_1                                         Equ         1
PF_NON_TEMPORAL_LEVEL_ALL                                   Equ         1

PLABEL_DESCRIPTOR Struct
   EntryPoint                                               DQ          ?
   GlobalPointer                                            DQ          ?
PLABEL_DESCRIPTOR EndS
PPLABEL_DESCRIPTOR                                          TypeDef     DWord

;WELL_KNOWN_SID_TYPE Enumeration
WELL_KNOWN_SID_TYPE                                         TypeDef     DWord
WinNullSid                                                  Equ         0
WinWorldSid                                                 Equ         1
WinLocalSid                                                 Equ         2
WinCreatorOwnerSid                                          Equ         3
WinCreatorGroupSid                                          Equ         4
WinCreatorOwnerServerSid                                    Equ         5
WinCreatorGroupServerSid                                    Equ         6
WinNtAuthoritySid                                           Equ         7
WinDialupSid                                                Equ         8
WinNetworkSid                                               Equ         9
WinBatchSid                                                 Equ         10
WinInteractiveSid                                           Equ         11
WinServiceSid                                               Equ         12
WinAnonymousSid                                             Equ         13
WinProxySid                                                 Equ         14
WinEnterpriseControllersSid                                 Equ         15
WinSelfSid                                                  Equ         16
WinAuthenticatedUserSid                                     Equ         17
WinRestrictedCodeSid                                        Equ         18
WinTerminalServerSid                                        Equ         19
WinRemoteLogonIdSid                                         Equ         20
WinLogonIdsSid                                              Equ         21
WinLocalSystemSid                                           Equ         22
WinLocalServiceSid                                          Equ         23
WinNetworkServiceSid                                        Equ         24
WinBuiltinDomainSid                                         Equ         25
WinBuiltinAdministratorsSid                                 Equ         26
WinBuiltinUsersSid                                          Equ         27
WinBuiltinGuestsSid                                         Equ         28
WinBuiltinPowerUsersSid                                     Equ         29
WinBuiltinAccountOperatorsSid                               Equ         30
WinBuiltinSystemOperatorsSid                                Equ         31
WinBuiltinPrintOperatorsSid                                 Equ         32
WinBuiltinBackupOperatorsSid                                Equ         33
WinBuiltinReplicatorSid                                     Equ         34
WinBuiltinPreWindows2000CompatibleAccessSid                 Equ         35
WinBuiltinRemoteDesktopUsersSid                             Equ         36
WinBuiltinNetworkConfigurationOperatorsSid                  Equ         37
WinAccountAdministratorSid                                  Equ         38
WinAccountGuestSid                                          Equ         39
WinAccountKrbtgtSid                                         Equ         40
WinAccountDomainAdminsSid                                   Equ         41
WinAccountDomainUsersSid                                    Equ         42
WinAccountDomainGuestsSid                                   Equ         43
WinAccountComputersSid                                      Equ         44
WinAccountControllersSid                                    Equ         45
WinAccountCertAdminsSid                                     Equ         46
WinAccountSchemaAdminsSid                                   Equ         47
WinAccountEnterpriseAdminsSid                               Equ         48
WinAccountPolicyAdminsSid                                   Equ         49
WinAccountRasAndIasServersSid                               Equ         50
WinNTLMAuthenticationSid                                    Equ         51
WinDigestAuthenticationSid                                  Equ         52
WinSChannelAuthenticationSid                                Equ         53
WinThisOrganizationSid                                      Equ         54
WinOtherOrganizationSid                                     Equ         55
WinBuiltinIncomingForestTrustBuildersSid                    Equ         56
WinBuiltinPerfMonitoringUsersSid                            Equ         57
WinBuiltinPerfLoggingUsersSid                               Equ         58
WinBuiltinAuthorizationAccessSid                            Equ         59
WinBuiltinTerminalServerLicenseServersSid                   Equ         60
WinBuiltinDCOMUsersSid                                      Equ         61
WinBuiltinIUsersSid                                         Equ         62
WinIUserSid                                                 Equ         63
WinBuiltinCryptoOperatorsSid                                Equ         64
WinUntrustedLabelSid                                        Equ         65
WinLowLabelSid                                              Equ         66
WinMediumLabelSid                                           Equ         67
WinHighLabelSid                                             Equ         68
WinSystemLabelSid                                           Equ         69
WinWriteRestrictedCodeSid                                   Equ         70
WinCreatorOwnerRightsSid                                    Equ         71
WinCacheablePrincipalsGroupSid                              Equ         72
WinNonCacheablePrincipalsGroupSid                           Equ         73
WinEnterpriseReadonlyControllersSid                         Equ         74
WinAccountReadonlyControllersSid                            Equ         75
WinBuiltinEventLogReadersGroup                              Equ         76
WinNewEnterpriseReadonlyControllersSid                      Equ         77
WinBuiltinCertSvcDComAccessGroup                            Equ         78
WinMediumPlusLabelSid                                       Equ         79
WinLocalLogonSid                                            Equ         80
WinConsoleLogonSid                                          Equ         81
WinThisOrganizationCertificateSid                           Equ         82

SE_UNSOLICITED_INPUT_PRIVILEGE                              Equ         (6)

SE_MAX_AUDIT_PARAMETERS                                     Equ         32
SE_MAX_GENERIC_AUDIT_PARAMETERS                             Equ         28

SE_ADT_PARAMETERS_SELF_RELATIVE                             Equ         000000001H
SE_ADT_PARAMETERS_SEND_TO_LSA                               Equ         000000002H
SE_ADT_PARAMETER_EXTENSIBLE_AUDIT                           Equ         000000004H
SE_ADT_PARAMETER_GENERIC_AUDIT                              Equ         000000008H
SE_ADT_PARAMETER_WRITE_SYNCHRONOUS                          Equ         000000010H

RTL_RUN_ONCE_INIT                                           Equ         {0}

RTL_RUN_ONCE_CHECK_ONLY                                     Equ         000000001UH
RTL_RUN_ONCE_ASYNC                                          Equ         000000002UH
RTL_RUN_ONCE_INIT_FAILED                                    Equ         000000004UH

RTL_RUN_ONCE_CTX_RESERVED_BITS                              Equ         2

RTL_RUN_ONCE Union
    _Ptr                                                    DD          ?   ;Ptr
RTL_RUN_ONCE EndS
PRTL_RUN_ONCE                                               TypeDef     DWord

;TABLE_SEARCH_RESULT Enumeration
TABLE_SEARCH_RESULT                                         TypeDef     DWord
TableEmptyTree                                              Equ         0
TableFoundNode                                              Equ         1
TableInsertAsLeft                                           Equ         2
TableInsertAsRight                                          Equ         3

;RTL_GENERIC_COMPARE_RESULTS Enumeration
RTL_GENERIC_COMPARE_RESULTS                                 TypeDef     DWord
GenericLessThan                                             Equ         0
GenericGreaterThan                                          Equ         1
GenericEqual                                                Equ         2

RTL_BALANCED_LINKS Struct
    Parent                                                  DD          ?
    LeftChild                                               DD          ?
    RightChild                                              DD          ?
    Balance                                                 DB          ?
    Reserved                                                DB          3 Dup(?)
RTL_BALANCED_LINKS EndS
PRTL_BALANCED_LINKS                                         TypeDef     DWord

RTL_AVL_TABLE Struct
    BalancedRoot                                            RTL_BALANCED_LINKS  <>
    OrderedPointer                                          PVOID       ?
    WhichOrderedElement                                     DD          ?
    NumberGenericTableElements                              DD          ?
    DepthOfTree                                             DD          ?
    RestartKey                                              PRTL_BALANCED_LINKS ?
    DeleteCount                                             DD          ?
    CompareRoutine                                          DD          ? ;PRTL_AVL_COMPARE_ROUTINE
    AllocateRoutine                                         DD          ? ;PRTL_AVL_ALLOCATE_ROUTINE
    FreeRoutine                                             DD          ? ;PRTL_AVL_FREE_ROUTINE
    TableContext                                            PVOID       ?
RTL_AVL_TABLE EndS
PRTL_AVL_TABLE                                              TypeDef     DWord

RTL_SPLAY_LINKS Struct
    Parent                                                  DD          ?
    LeftChild                                               DD          ?
    RightChild                                              DD          ?
RTL_SPLAY_LINKS EndS
PRTL_SPLAY_LINKS                                            TypeDef     DWord

RTL_GENERIC_TABLE Struct
    TableRoot                                               PRTL_SPLAY_LINKS    ?
    InsertOrderList                                         LIST_ENTRY  <>
    OrderedPointer                                          PLIST_ENTRY ?
    WhichOrderedElement                                     DD          ?
    NumberGenericTableElements                              DD          ?
    CompareRoutine                                          DD          ? ;PRTL_GENERIC_COMPARE_ROUTINE
    AllocateRoutine                                         DD          ? ;PRTL_GENERIC_ALLOCATE_ROUTINE
    FreeRoutine                                             DD          ? ;PRTL_GENERIC_FREE_ROUTINE
    TableContext                                            PVOID       ?
RTL_GENERIC_TABLE EndS
PRTL_GENERIC_TABLE                                          TypeDef     DWord

RTL_HASH_ALLOCATED_HEADER                                   Equ         000000001H

RTL_HASH_RESERVED_SIGNATURE                                 Equ         0


RTL_DYNAMIC_HASH_TABLE_ENTRY Struct
    Linkage                                                 LIST_ENTRY  <>
    Signature                                               DD          ?
RTL_DYNAMIC_HASH_TABLE_ENTRY EndS
PRTL_DYNAMIC_HASH_TABLE_ENTRY                               TypeDef     DWord

RTL_DYNAMIC_HASH_TABLE_CONTEXT Struct
    ChainHead                                               PLIST_ENTRY ?
    PrevLinkage                                             PLIST_ENTRY ?
    Signature                                               DD          ?
RTL_DYNAMIC_HASH_TABLE_CONTEXT EndS
PRTL_DYNAMIC_HASH_TABLE_CONTEXT                             TypeDef     DWord

RTL_DYNAMIC_HASH_TABLE_ENUMERATOR Struct
    HashEntry                                               RTL_DYNAMIC_HASH_TABLE_ENTRY    <>
    ChainHead                                               PLIST_ENTRY ?
    BucketIndex                                             DD          ?
RTL_DYNAMIC_HASH_TABLE_ENUMERATOR EndS
PRTL_DYNAMIC_HASH_TABLE_ENUMERATOR                          TypeDef     DWord

RTL_DYNAMIC_HASH_TABLE Struct
    Flags                                                   DD          ?
    Shift                                                   DD          ?
    TableSize                                               DD          ?
    Pivot                                                   DD          ?
    DivisorMask                                             DD          ?
    NumEntries                                              DD          ?
    NonEmptyBuckets                                         DD          ?
    NumEnumerators                                          DD          ?
    Directory                                               PVOID       ?
RTL_DYNAMIC_HASH_TABLE EndS
PRTL_DYNAMIC_HASH_TABLE                                     TypeDef     DWord

RTL_STACK_WALKING_MODE_FRAMES_TO_SKIP_SHIFT                 Equ         8

OSVERSIONINFOA Struct
    dwOSVersionInfoSize                                     DD          ?
    dwMajorVersion                                          DD          ?
    dwMinorVersion                                          DD          ?
    dwBuildNumber                                           DD          ?
    dwPlatformId                                            DD          ?
    szCSDVersion                                            DB          128 Dup(?)
OSVERSIONINFOA EndS
POSVERSIONINFOA                                             TypeDef     DWord

OSVERSIONINFOW Struct
    dwOSVersionInfoSize                                     DD          ?
    dwMajorVersion                                          DD          ?
    dwMinorVersion                                          DD          ?
    dwBuildNumber                                           DD          ?
    dwPlatformId                                            DD          ?
    szCSDVersion                                            DW          128 Dup(?)
OSVERSIONINFOW EndS
POSVERSIONINFOW                                             TypeDef     DWord

IFDEF APP_UNICODE
    OSVERSIONINFO                                           Equ         <OSVERSIONINFOW>
ELSE
    OSVERSIONINFO                                           Equ         <OSVERSIONINFOA>
ENDIF

OSVERSIONINFOEXA Struct
    dwOSVersionInfoSize                                     DD          ?
    dwMajorVersion                                          DD          ?
    dwMinorVersion                                          DD          ?
    dwBuildNumber                                           DD          ?
    dwPlatformId                                            DD          ?
    szCSDVersion                                            DB          128 Dup(?)
    wServicePackMajor                                       DW          ?
    wServicePackMinor                                       DW          ?
    wSuiteMask                                              DW          ?
    wProductType                                            DB          ?
    wReserved                                               DB          ?
OSVERSIONINFOEXA EndS
POSVERSIONINFOEXA                                           TypeDef     DWord

OSVERSIONINFOEXW Struct
    dwOSVersionInfoSize                                     DD          ?
    dwMajorVersion                                          DD          ?
    dwMinorVersion                                          DD          ?
    dwBuildNumber                                           DD          ?
    dwPlatformId                                            DD          ?
    szCSDVersion                                            DW          128 Dup(?)
    wServicePackMajor                                       DW          ?
    wServicePackMinor                                       DW          ?
    wSuiteMask                                              DW          ?
    wProductType                                            DB          ?
    wReserved                                               DB          ?
OSVERSIONINFOEXW EndS
POSVERSIONINFOEXW                                           TypeDef     DWord

IFDEF APP_UNICODE
    OSVERSIONINFOEX                                         Equ         <OSVERSIONINFOEXW>
ELSE
    OSVERSIONINFOEX                                         Equ         <OSVERSIONINFOEXA>
ENDIF

VER_EQUAL                                                   Equ         1
VER_GREATER                                                 Equ         2
VER_GREATER_EQUAL                                           Equ         3
VER_LESS                                                    Equ         4
VER_LESS_EQUAL                                              Equ         5
VER_AND                                                     Equ         6
VER_OR                                                      Equ         7

VER_CONDITION_MASK                                          Equ         7
VER_NUM_BITS_PER_CONDITION_MASK                             Equ         3

VER_MINORVERSION                                            Equ         00000001H
VER_MAJORVERSION                                            Equ         00000002H
VER_BUILDNUMBER                                             Equ         00000004H
VER_PLATFORMID                                              Equ         00000008H
VER_SERVICEPACKMINOR                                        Equ         00000010H
VER_SERVICEPACKMAJOR                                        Equ         00000020H
VER_SUITENAME                                               Equ         00000040H
VER_PRODUCT_TYPE                                            Equ         00000080H

VER_NT_WORKSTATION                                          Equ         00000001H
VER_NT_DOMAIN_CONTROLLER                                    Equ         00000002H
VER_NT_SERVER                                               Equ         00000003H

VER_PLATFORM_WIN32s                                         Equ         0
VER_PLATFORM_WIN32_WINDOWS                                  Equ         1
VER_PLATFORM_WIN32_NT                                       Equ         2

FILE_CHARACTERISTICS_EXPECT_ORDERLY_REMOVAL                 Equ         00000200H
FILE_CHARACTERISTICS_EXPECT_SURPRISE_REMOVAL                Equ         00000300H
FILE_CHARACTERISTICS_REMOVAL_POLICY_MASK                    Equ         00000300H

FILE_CHARACTERISTICS_EXPECT_ORDERLY_REMOVAL_EX              Equ         00004000H
FILE_CHARACTERISTICS_EXPECT_SURPRISE_REMOVAL_EX             Equ         00008000H
FILE_CHARACTERISTICS_REMOVAL_POLICY_MASK_EX                 Equ         (FILE_CHARACTERISTICS_EXPECT_ORDERLY_REMOVAL_EX Or FILE_CHARACTERISTICS_EXPECT_SURPRISE_REMOVAL_EX)

FILE_CHARACTERISTICS_EXPECT_ORDERLY_REMOVAL_DEPRECATED      Equ         00000200H
FILE_CHARACTERISTICS_EXPECT_SURPRISE_REMOVAL_DEPRECATED     Equ         00000300H
FILE_CHARACTERISTICS_REMOVAL_POLICY_MASK_DEPRECATED         Equ         00000300H

FILE_CHARACTERISTICS_PROPAGATED                             Equ         (FILE_REMOVABLE_MEDIA Or FILE_READ_ONLY_DEVICE Or FILE_FLOPPY_DISKETTE Or FILE_WRITE_ONCE_MEDIA Or FILE_DEVICE_SECURE_OPEN)

FILE_ALIGNMENT_INFORMATION Struct
    AlignmentRequirement                                    DD          ?
FILE_ALIGNMENT_INFORMATION EndS
PFILE_ALIGNMENT_INFORMATION                                 TypeDef     DWord

FILE_NAME_INFORMATION Struct
    FileNameLength                                          DD          ?
    FileName                                                DW          1 Dup(?)
FILE_NAME_INFORMATION EndS
PFILE_NAME_INFORMATION                                      TypeDef     DWord

FILE_ATTRIBUTE_TAG_INFORMATION Struct
    FileAttributes                                          DD          ?
    ReparseTag                                              DD          ?
FILE_ATTRIBUTE_TAG_INFORMATION EndS
PFILE_ATTRIBUTE_TAG_INFORMATION                             TypeDef     DWord

FILE_DISPOSITION_INFORMATION Struct
    DeleteFile                                              BOOLEAN     ?
FILE_DISPOSITION_INFORMATION EndS
PFILE_DISPOSITION_INFORMATION                               TypeDef     DWord

FILE_END_OF_FILE_INFORMATION Struct
    EndOfFile                                               LARGE_INTEGER   <>
FILE_END_OF_FILE_INFORMATION EndS
PFILE_END_OF_FILE_INFORMATION                               TypeDef     DWord

FILE_VALID_DATA_LENGTH_INFORMATION Struct
    ValidDataLength                                         LARGE_INTEGER   <>
FILE_VALID_DATA_LENGTH_INFORMATION EndS
PFILE_VALID_DATA_LENGTH_INFORMATION                         TypeDef     DWord

FILE_FS_LABEL_INFORMATION Struct
    VolumeLabelLength                                       DD          ?
    VolumeLabel                                             DW          1 Dup (?)
FILE_FS_LABEL_INFORMATION EndS
PFILE_FS_LABEL_INFORMATION                                  TypeDef     DWord

FILE_FS_VOLUME_INFORMATION Struct
    VolumeCreationTime                                      LARGE_INTEGER   <>
    VolumeSerialNumber                                      DD          ?
    VolumeLabelLength                                       DD          ?
    SupportsObjects                                         BOOLEAN     ?
    VolumeLabel                                             DW          1 Dup(?)
FILE_FS_VOLUME_INFORMATION EndS
PFILE_FS_VOLUME_INFORMATION                                 TypeDef     DWord

FILE_FS_SIZE_INFORMATION Struct
    TotalAllocationUnits                                    LARGE_INTEGER   <>
    AvailableAllocationUnits                                LARGE_INTEGER   <>
    SectorsPerAllocationUnit                                DD          ?
    BytesPerSector                                          DD          ?
FILE_FS_SIZE_INFORMATION EndS
PFILE_FS_SIZE_INFORMATION                                   TypeDef     DWord

FILE_FS_FULL_SIZE_INFORMATION Struct
    TotalAllocationUnits                                    LARGE_INTEGER   <>
    CallerAvailableAllocationUnits                          LARGE_INTEGER   <>
    ActualAvailableAllocationUnits                          LARGE_INTEGER   <>
    SectorsPerAllocationUnit                                DD          ?
    BytesPerSector                                          DD          ?
FILE_FS_FULL_SIZE_INFORMATION EndS
PFILE_FS_FULL_SIZE_INFORMATION                              TypeDef     DWord

FILE_FS_OBJECTID_INFORMATION Struct
    ObjectId                                                DB          16 Dup(?)
    ExtendedInfo                                            DB          48 Dup(?)
FILE_FS_OBJECTID_INFORMATION EndS
PFILE_FS_OBJECTID_INFORMATION                               TypeDef     DWord

FILE_SEGMENT_ELEMENT Union
    Buffer                                                  DQ          ?
    Alignment                                               DQ          ?
FILE_SEGMENT_ELEMENT EndS
PFILE_SEGMENT_ELEMENT                                       TypeDef     DWord

IOCTL_AVIO_ALLOCATE_STREAM                                  Equ         CTL_CODE(FILE_DEVICE_AVIO, 1, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
IOCTL_AVIO_FREE_STREAM                                      Equ         CTL_CODE(FILE_DEVICE_AVIO, 2, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
IOCTL_AVIO_MODIFY_STREAM                                    Equ         CTL_CODE(FILE_DEVICE_AVIO, 3, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)

;BUS_DATA_TYPE Enumeration
BUS_DATA_TYPE                                               TypeDef     DWord
ConfigurationSpaceUndefined                                 Equ         (-1)
Cmos                                                        Equ         0
EisaConfiguration                                           Equ         1
Pos                                                         Equ         2
CbusConfiguration                                           Equ         3
PCIConfiguration                                            Equ         4
VMEConfiguration                                            Equ         5
NuBusConfiguration                                          Equ         6
PCMCIAConfiguration                                         Equ         7
MPIConfiguration                                            Equ         8
MPSAConfiguration                                           Equ         9
PNPISAConfiguration                                         Equ         10
SgiInternalConfiguration                                    Equ         11
MaximumBusDataType                                          Equ         12

KEY_NAME_INFORMATION Struct
    NameLength                                              DD          ?
    _Name                                                   DW          1 Dup(?)
KEY_NAME_INFORMATION EndS
PKEY_NAME_INFORMATION                                       TypeDef     DWord

KEY_CACHED_INFORMATION Struct
    LastWriteTime                                           LARGE_INTEGER   <>
    TitleIndex                                              DD          ?
    SubKeys                                                 DD          ?
    MaxNameLen                                              DD          ?
    Values                                                  DD          ?
    MaxValueNameLen                                         DD          ?
    MaxValueDataLen                                         DD          ?
    NameLength                                              DD          ?
KEY_CACHED_INFORMATION EndS
PKEY_CACHED_INFORMATION                                     TypeDef     DWord

KEY_VIRTUALIZATION_INFORMATION Struct
    VirtualizationCandidate                                 DD          ?
    VirtualizationEnabled                                   DD          ?
    VirtualTarget                                           DD          ?
    VirtualStore                                            DD          ?
    VirtualSource                                           DD          ?
    Reserved                                                DD          ?
KEY_VIRTUALIZATION_INFORMATION EndS
PKEY_VIRTUALIZATION_INFORMATION                             TypeDef     DWord

NT_TIB Struct
    ExceptionList                                           PVOID       ?
    StackBase                                               PVOID       ?
    StackLimit                                              PVOID       ?
    SubSystemTib                                            PVOID       ?
    Union
        FiberData                                           PVOID       ?
        Version                                             DD          ?
    EndS
    ArbitraryUserPointer                                    PVOID       ?
    Self                                                    PVOID       ?
NT_TIB EndS
PNT_TIB                                                     TypeDef     DWord

NT_TIB32 Struct
    ExceptionList                                           DD          ?
    StackBase                                               DD          ?
    StackLimit                                              DD          ?
    SubSystemTib                                            DD          ?
    Union
        FiberData                                           DD          ?
        Version                                             DD          ?
    EndS
    ArbitraryUserPointer                                    DD          ?
    Self                                                    DD          ?
NT_TIB32 EndS
PNT_TIB32                                                   TypeDef     DWord

NT_TIB64 Struct
    ExceptionList                                           DQ          ?
    StackBase                                               DQ          ?
    StackLimit                                              DQ          ?
    SubSystemTib                                            DQ          ?
    Union
        FiberData                                           DQ          ?
        Version                                             DD          ?
    EndS
    ArbitraryUserPointer                                    DQ          ?
    Self                                                    DQ          ?
NT_TIB64 EndS
PNT_TIB64                                                   TypeDef     DWord

;PROCESSINFOCLASS Enumeration
PROCESSINFOCLASS                                            TypeDef     DWord
ProcessBasicInformation                                     Equ         0
ProcessQuotaLimits                                          Equ         1
ProcessIoCounters                                           Equ         2
ProcessVmCounters                                           Equ         3
ProcessTimes                                                Equ         4
ProcessBasePriority                                         Equ         5
ProcessRaisePriority                                        Equ         6
ProcessDebugPort                                            Equ         7
ProcessExceptionPort                                        Equ         8
ProcessAccessToken                                          Equ         9
ProcessLdtInformation                                       Equ         10
ProcessLdtSize                                              Equ         11
ProcessDefaultHardErrorMode                                 Equ         12
ProcessIoPortHandlers                                       Equ         13
ProcessPooledUsageAndLimits                                 Equ         14
ProcessWorkingSetWatch                                      Equ         15
ProcessUserModeIOPL                                         Equ         16
ProcessEnableAlignmentFaultFixup                            Equ         17
ProcessPriorityClass                                        Equ         18
ProcessWx86Information                                      Equ         19
ProcessHandleCount                                          Equ         20
ProcessAffinityMask                                         Equ         21
ProcessPriorityBoost                                        Equ         22
ProcessDeviceMap                                            Equ         23
ProcessSessionInformation                                   Equ         24
ProcessForegroundInformation                                Equ         25
ProcessWow64Information                                     Equ         26
ProcessImageFileName                                        Equ         27
ProcessLUIDDeviceMapsEnabled                                Equ         28
ProcessBreakOnTermination                                   Equ         29
ProcessDebugObjectHandle                                    Equ         30
ProcessDebugFlags                                           Equ         31
ProcessHandleTracing                                        Equ         32
ProcessIoPriority                                           Equ         33
ProcessExecuteFlags                                         Equ         34
ProcessTlsInformation                                       Equ         35
ProcessCookie                                               Equ         36
ProcessImageInformation                                     Equ         37
ProcessCycleTime                                            Equ         38
ProcessPagePriority                                         Equ         39
ProcessInstrumentationCallback                              Equ         40
ProcessThreadStackAllocation                                Equ         41
ProcessWorkingSetWatchEx                                    Equ         42
ProcessImageFileNameWin32                                   Equ         43
ProcessImageFileMapping                                     Equ         44
ProcessAffinityUpdateMode                                   Equ         45
ProcessMemoryAllocationMode                                 Equ         46
ProcessGroupInformation                                     Equ         47
ProcessTokenVirtualizationEnabled                           Equ         48
ProcessConsoleHostProcess                                   Equ         49
ProcessWindowInformation                                    Equ         50
MaxProcessInfoClass                                         Equ         51

;THREADINFOCLASS Enumeration
THREADINFOCLASS                                             TypeDef     DWord
ThreadBasicInformation                                      Equ         0
ThreadTimes                                                 Equ         1
ThreadPriority                                              Equ         2
ThreadBasePriority                                          Equ         3
ThreadAffinityMask                                          Equ         4
ThreadImpersonationToken                                    Equ         5
ThreadDescriptorTableEntry                                  Equ         6
ThreadEnableAlignmentFaultFixup                             Equ         7
ThreadEventPair_Reusable                                    Equ         8
ThreadQuerySetWin32StartAddress                             Equ         9
ThreadZeroTlsCell                                           Equ         10
ThreadPerformanceCount                                      Equ         11
ThreadAmILastThread                                         Equ         12
ThreadIdealProcessor                                        Equ         13
ThreadPriorityBoost                                         Equ         14
ThreadSetTlsArrayAddress                                    Equ         15
ThreadIsIoPending                                           Equ         16
ThreadHideFromDebugger                                      Equ         17
ThreadBreakOnTermination                                    Equ         18
ThreadSwitchLegacyState                                     Equ         19
ThreadIsTerminated                                          Equ         20
ThreadLastSystemCall                                        Equ         21
ThreadIoPriority                                            Equ         22
ThreadCycleTime                                             Equ         23
ThreadPagePriority                                          Equ         24
ThreadActualBasePriority                                    Equ         25
ThreadTebInformation                                        Equ         26
ThreadCSwitchMon                                            Equ         27
ThreadCSwitchPmu                                            Equ         28
ThreadWow64Context                                          Equ         29
ThreadGroupInformation                                      Equ         30
ThreadUmsInformation                                        Equ         31
ThreadCounterProfiling                                      Equ         32
ThreadIdealProcessorEx                                      Equ         33
MaxThreadInfoClass                                          Equ         34

THREAD_CSWITCH_PMU_DISABLE                                  Equ         FALSE
THREAD_CSWITCH_PMU_ENABLE                                   Equ         TRUE

PAGE_PRIORITY_INFORMATION Struct
    PagePriority                                            DD          ?
PAGE_PRIORITY_INFORMATION EndS
PPAGE_PRIORITY_INFORMATION                                  TypeDef     DWord

PROCESS_WS_WATCH_INFORMATION Struct
    FaultingPc                                              PVOID       ?
    FaultingVa                                              PVOID       ?
PROCESS_WS_WATCH_INFORMATION EndS
PPROCESS_WS_WATCH_INFORMATION                               TypeDef     DWord

PROCESS_BASIC_INFORMATION Struct
    ExitStatus                                              NTSTATUS    ?
    PebBaseAddress                                          DD          ?
    AffinityMask                                            DD          ?
    BasePriority                                            DD          ?
    UniqueProcessId                                         DD          ?
    InheritedFromUniqueProcessId                            DD          ?
PROCESS_BASIC_INFORMATION EndS
PPROCESS_BASIC_INFORMATION                                  TypeDef     DWord

PROCESS_DEVICEMAP_INFORMATION Struct
    Union DUMMYUNIONNAME
        Struct Set
            DirectoryHandle                                 DD          ?
        EndS
        Struct Query
            DriveMap                                        DD          ?
            DriveType                                       DB          32 Dup(?)
        EndS
    EndS
PROCESS_DEVICEMAP_INFORMATION EndS
PPROCESS_DEVICEMAP_INFORMATION                              TypeDef     DWord

PROCESS_DEVICEMAP_INFORMATION_EX Struct
    Union DUMMYUNIONNAME
        Struct Set
            DirectoryHandle                                 DD          ?
        EndS
        Struct Query
            DriveMap                                        DD          ?
            DriveType                                       DB          32 Dup(?)
        EndS
    EndS
    Flags                                                   DD          ?
PROCESS_DEVICEMAP_INFORMATION_EX EndS
PPROCESS_DEVICEMAP_INFORMATION_EX                           TypeDef     DWord

PROCESS_LUID_DOSDEVICES_ONLY                                Equ         00000001H

PROCESS_SESSION_INFORMATION Struct
    SessionId                                               DD          ?
PROCESS_SESSION_INFORMATION EndS
PPROCESS_SESSION_INFORMATION                                TypeDef     DWord

PROCESS_HANDLE_TRACING_ENABLE Struct
    Flags                                                   DD          ?
PROCESS_HANDLE_TRACING_ENABLE EndS
PPROCESS_HANDLE_TRACING_ENABLE                              TypeDef     DWord

PROCESS_HANDLE_TRACING_ENABLE_EX Struct
    Flags                                                   DD          ?
    TotalSlots                                              DD          ?
PROCESS_HANDLE_TRACING_ENABLE_EX EndS
PPROCESS_HANDLE_TRACING_ENABLE_EX                           TypeDef     DWord

PROCESS_HANDLE_TRACING_MAX_STACKS                           Equ         16

PROCESS_HANDLE_TRACING_ENTRY Struct
    Handle                                                  DD          ?
    ClientId                                                CLIENT_ID   <>
    _Type                                                   DD          ?   ;Type
    Stacks                                                  PVOID       PROCESS_HANDLE_TRACING_MAX_STACKS Dup(?)
PROCESS_HANDLE_TRACING_ENTRY EndS
PPROCESS_HANDLE_TRACING_ENTRY                               TypeDef     DWord

PROCESS_HANDLE_TRACING_QUERY Struct
    Handle                                                  DD          ?
    TotalTraces                                             DD          ?
    HandleTrace                                             PROCESS_HANDLE_TRACING_ENTRY    1 Dup(<>)
PROCESS_HANDLE_TRACING_QUERY EndS
PPROCESS_HANDLE_TRACING_QUERY                               TypeDef     DWord

QUOTA_LIMITS Struct
    PagedPoolLimit                                          SIZE_T      ?
    NonPagedPoolLimit                                       SIZE_T      ?
    MinimumWorkingSetSize                                   SIZE_T      ?
    MaximumWorkingSetSize                                   SIZE_T      ?
    PagefileLimit                                           SIZE_T      ?
    TimeLimit                                               LARGE_INTEGER   <>
QUOTA_LIMITS EndS
PQUOTA_LIMITS                                               TypeDef     DWord

QUOTA_LIMITS_HARDWS_MIN_ENABLE                              Equ         00000001H
QUOTA_LIMITS_HARDWS_MIN_DISABLE                             Equ         00000002H
QUOTA_LIMITS_HARDWS_MAX_ENABLE                              Equ         00000004H
QUOTA_LIMITS_HARDWS_MAX_DISABLE                             Equ         00000008H
QUOTA_LIMITS_USE_DEFAULT_LIMITS                             Equ         00000010H

IO_COUNTERS Struct
    ReadOperationCount                                      DQ          ?
    WriteOperationCount                                     DQ          ?
    OtherOperationCount                                     DQ          ?
    ReadTransferCount                                       DQ          ?
    WriteTransferCount                                      DQ          ?
    OtherTransferCount                                      DQ          ?
IO_COUNTERS EndS
PIO_COUNTERS                                                TypeDef     DWord

VM_COUNTERS Struct
    PeakVirtualSize                                         SIZE_T      ?
    VirtualSize                                             SIZE_T      ?
    PageFaultCount                                          DD          ?
    PeakWorkingSetSize                                      SIZE_T      ?
    WorkingSetSize                                          SIZE_T      ?
    QuotaPeakPagedPoolUsage                                 SIZE_T      ?
    QuotaPagedPoolUsage                                     SIZE_T      ?
    QuotaPeakNonPagedPoolUsage                              SIZE_T      ?
    QuotaNonPagedPoolUsage                                  SIZE_T      ?
    PagefileUsage                                           SIZE_T      ?
    PeakPagefileUsage                                       SIZE_T      ?
VM_COUNTERS EndS
PVM_COUNTERS                                                TypeDef     DWord

VM_COUNTERS_EX Struct
    PeakVirtualSize                                         SIZE_T      ?
    VirtualSize                                             SIZE_T      ?
    PageFaultCount                                          DD          ?
    PeakWorkingSetSize                                      SIZE_T      ?
    WorkingSetSize                                          SIZE_T      ?
    QuotaPeakPagedPoolUsage                                 SIZE_T      ?
    QuotaPagedPoolUsage                                     SIZE_T      ?
    QuotaPeakNonPagedPoolUsage                              SIZE_T      ?
    QuotaNonPagedPoolUsage                                  SIZE_T      ?
    PagefileUsage                                           SIZE_T      ?
    PeakPagefileUsage                                       SIZE_T      ?
    PrivateUsage                                            SIZE_T      ?
VM_COUNTERS_EX EndS
PVM_COUNTERS_EX                                             TypeDef     DWord

MAX_HW_COUNTERS                                             Equ         16
THREAD_PROFILING_FLAG_DISPATCH                              Equ         00000001H

;HARDWARE_COUNTER_TYPE Enumeration
HARDWARE_COUNTER_TYPE                                       TypeDef     DWord
PMCCounter                                                  Equ         0
MaxHardwareCounterType                                      Equ         1

HARDWARE_COUNTER Struct
    _Type                                                   DD          ?   ;Type
    Reserved                                                DD          ?
    Index                                                   DQ          ?
HARDWARE_COUNTER EndS
PHARDWARE_COUNTER                                           TypeDef     DWord

POOLED_USAGE_AND_LIMITS Struct
    PeakPagedPoolUsage                                      SIZE_T      ?
    PagedPoolUsage                                          SIZE_T      ?
    PagedPoolLimit                                          SIZE_T      ?
    PeakNonPagedPoolUsage                                   SIZE_T      ?
    NonPagedPoolUsage                                       SIZE_T      ?
    NonPagedPoolLimit                                       SIZE_T      ?
    PeakPagefileUsage                                       SIZE_T      ?
    PagefileUsage                                           SIZE_T      ?
    PagefileLimit                                           SIZE_T      ?
POOLED_USAGE_AND_LIMITS EndS
PPOOLED_USAGE_AND_LIMITS                                    TypeDef     DWord

PROCESS_ACCESS_TOKEN Struct
    Token                                                   HANDLE      ?
    Thread                                                  HANDLE      ?
PROCESS_ACCESS_TOKEN EndS
PPROCESS_ACCESS_TOKEN                                       TypeDef     DWord

PROCESS_EXCEPTION_PORT_ALL_STATE_BITS                       Equ         00000003H
PROCESS_EXCEPTION_PORT_ALL_STATE_FLAGS                      Equ         ((1 Shl PROCESS_EXCEPTION_PORT_ALL_STATE_BITS) - 1)

PROCESS_EXCEPTION_PORT Struct
    ExceptionPortHandle                                     HANDLE      ?
    StateFlags                                              DD          ?
PROCESS_EXCEPTION_PORT EndS
PPROCESS_EXCEPTION_PORT                                     TypeDef     DWord

KERNEL_USER_TIMES Struct
    CreateTime                                              LARGE_INTEGER   <>
    ExitTime                                                LARGE_INTEGER   <>
    KernelTime                                              LARGE_INTEGER   <>
    UserTime                                                LARGE_INTEGER   <>
KERNEL_USER_TIMES EndS
PKERNEL_USER_TIMES                                          TypeDef     DWord

PCR_MINOR_VERSION                                           Equ         1
PCR_MAJOR_VERSION                                           Equ         1

KPCR Struct
    Union
        NtTib                                               NT_TIB      <>
        Struct
            Used_ExceptionList                              DD          ?
            Used_StackBase                                  PVOID       ?
            Spare2                                          PVOID       ?
            TssCopy                                         PVOID       ?
            ContextSwitches                                 DD          ?
            SetMemberCopy                                   KAFFINITY   ?
            Used_Self                                       PVOID       ?
        EndS
    EndS
    SelfPcr                                                 DD          ?
    Prcb                                                    DD          ?
    Irql                                                    KIRQL       ?
    IRR                                                     DD          ?
    IrrActive                                               DD          ?
    IDR                                                     DD          ?
    KdVersionBlock                                          PVOID       ?
    IDT                                                     DD          ?
    GDT                                                     DD          ?
    TSS                                                     DD          ?
    MajorVersion                                            DW          ?
    MinorVersion                                            DW          ?
    SetMember                                               KAFFINITY   ?
    StallScaleFactor                                        DD          ?
    SpareUnused                                             DB          ?
    Number                                                  DB          ?
    Spare0                                                  DB          ?
    SecondLevelCacheAssociativity                           DB          ?
    VdmAlert                                                DD          ?
    KernelReserved                                          DD          14 Dup(?)
    SecondLevelCacheSize                                    DD          ?
    HalReserved                                             DD          16 Dup(?)
KPCR Ends
PKPCR                                                       TypeDef     DWord

PDI_SHIFT_X86                                               Equ         22
PDI_SHIFT_X86PAE                                            Equ         21

GUARD_PAGE_SIZE                                             Equ         (PAGE_SIZE * 1)

PTI_SHIFT                                                   Equ         12

MM_HIGHEST_USER_ADDRESS                                     Equ         <MmHighestUserAddress>
MM_SYSTEM_RANGE_START                                       Equ         <MmSystemRangeStart>

MM_KSEG0_BASE                                               Equ         MM_SYSTEM_RANGE_START
MM_SYSTEM_SPACE_END                                         Equ         0FFFFFFFFH

MM_LOWEST_USER_ADDRESS                                      Equ         010000H

;INTERLOCKED_RESULT Enumration
INTERLOCKED_RESULT                                          TypeDef     DWord
ResultNegative                                              Equ         RESULT_NEGATIVE
ResultZero                                                  Equ         RESULT_ZERO
ResultPositive                                              Equ         RESULT_POSITIVE

;SYSTEM_FIRMWARE_TABLE_ACTION Enumeration
SYSTEM_FIRMWARE_TABLE_ACTION                                TypeDef     DWord
SystemFirmwareTable_Enumerate                               Equ         0
SystemFirmwareTable_Get                                     Equ         1

SYSTEM_FIRMWARE_TABLE_INFORMATION Struct
    ProviderSignature                                       DD          ?
    Action                                                  DD          ?
    TableID                                                 DD          ?
    TableBufferLength                                       DD          ?
    TableBuffer                                             DB          ANYSIZE_ARRAY Dup(?)
SYSTEM_FIRMWARE_TABLE_INFORMATION EndS
PSYSTEM_FIRMWARE_TABLE_INFORMATION                          TypeDef     DWord

;TIMER_SET_INFORMATION_CLASS Enumeration
TIMER_SET_INFORMATION_CLASS                                 TypeDef     DWord
TimerSetCoalescableTimer                                    Equ         0
MaxTimerInfoClass                                           Equ         1

DRIVER_VERIFIER_SPECIAL_POOLING                             Equ         0001H
DRIVER_VERIFIER_FORCE_IRQL_CHECKING                         Equ         0002H
DRIVER_VERIFIER_INJECT_ALLOCATION_FAILURES                  Equ         0004H
DRIVER_VERIFIER_TRACK_POOL_ALLOCATIONS                      Equ         0008H
DRIVER_VERIFIER_IO_CHECKING                                 Equ         0010H

XSTATE_LEGACY_FLOATING_POINT                                Equ         0
XSTATE_LEGACY_SSE                                           Equ         1
XSTATE_GSSE                                                 Equ         2

MAXIMUM_XSTATE_FEATURES                                     Equ         64

MAX_WOW64_SHARED_ENTRIES                                    Equ         16

NX_SUPPORT_POLICY_ALWAYSOFF                                 Equ         0
NX_SUPPORT_POLICY_ALWAYSON                                  Equ         1
NX_SUPPORT_POLICY_OPTIN                                     Equ         2
NX_SUPPORT_POLICY_OPTOUT                                    Equ         3

SHARED_GLOBAL_FLAGS_ERROR_PORT_V                            Equ         0H
SHARED_GLOBAL_FLAGS_ERROR_PORT                              Equ         (1 Shl SHARED_GLOBAL_FLAGS_ERROR_PORT_V)

SHARED_GLOBAL_FLAGS_ELEVATION_ENABLED_V                     Equ         1H
SHARED_GLOBAL_FLAGS_ELEVATION_ENABLED                       Equ         (1 Shl SHARED_GLOBAL_FLAGS_ELEVATION_ENABLED_V)

SHARED_GLOBAL_FLAGS_VIRT_ENABLED_V                          Equ         2H
SHARED_GLOBAL_FLAGS_VIRT_ENABLED                            Equ         (1 Shl SHARED_GLOBAL_FLAGS_VIRT_ENABLED_V)

SHARED_GLOBAL_FLAGS_INSTALLER_DETECT_ENABLED_V              Equ         3H
SHARED_GLOBAL_FLAGS_INSTALLER_DETECT_ENABLED                Equ         (1 Shl SHARED_GLOBAL_FLAGS_INSTALLER_DETECT_ENABLED_V)

SHARED_GLOBAL_FLAGS_SPARE_V                                 Equ         4H
SHARED_GLOBAL_FLAGS_SPARE                                   Equ         (1 Shl SHARED_GLOBAL_FLAGS_SPARE_V)

SHARED_GLOBAL_FLAGS_DYNAMIC_PROC_ENABLED_V                  Equ         5H
SHARED_GLOBAL_FLAGS_DYNAMIC_PROC_ENABLED                    Equ         (1 Shl SHARED_GLOBAL_FLAGS_DYNAMIC_PROC_ENABLED_V)

SHARED_GLOBAL_FLAGS_SEH_VALIDATION_ENABLED_V                Equ         6H
SHARED_GLOBAL_FLAGS_SEH_VALIDATION_ENABLED                  Equ         (1 Shl SHARED_GLOBAL_FLAGS_SEH_VALIDATION_ENABLED_V)

CmResourceTypeMaximum                                       Equ         8

CM_PCCARD_DEVICE_DATA Struct
    Flags                                                   DB          ?
    ErrorCode                                               DB          ?
    Reserved                                                DW          ?
    BusData                                                 DD          ?
    DeviceId                                                DD          ?
    LegacyBaseAddress                                       DD          ?
    IRQMap                                                  DB          16 Dup(?)
CM_PCCARD_DEVICE_DATA EndS
PCM_PCCARD_DEVICE_DATA                                      TypeDef     DWord

PCCARD_MAP_ERROR                                            Equ         01H
PCCARD_DEVICE_PCI                                           Equ         10H

PCCARD_SCAN_DISABLED                                        Equ         01H
PCCARD_MAP_ZERO                                             Equ         02H
PCCARD_NO_TIMER                                             Equ         03H
PCCARD_NO_PIC                                               Equ         04H
PCCARD_NO_LEGACY_BASE                                       Equ         05H
PCCARD_DUP_LEGACY_BASE                                      Equ         06H
PCCARD_NO_CONTROLLERS                                       Equ         07H

;CONFIGURATION_TYPE Enumeration
CONFIGURATION_TYPE                                          TypeDef     DWord
ArcSystem                                                   Equ         0
CentralProcessor                                            Equ         1
FloatingPointProcessor                                      Equ         2
PrimaryIcache                                               Equ         3
PrimaryDcache                                               Equ         4
SecondaryIcache                                             Equ         5
SecondaryDcache                                             Equ         6
SecondaryCache                                              Equ         7
EisaAdapter                                                 Equ         8
TcAdapter                                                   Equ         9
ScsiAdapter                                                 Equ         10
DtiAdapter                                                  Equ         11
MultiFunctionAdapter                                        Equ         12
DiskController                                              Equ         13
TapeController                                              Equ         14
CdromController                                             Equ         15
WormController                                              Equ         16
SerialController                                            Equ         17
NetworkController                                           Equ         18
DisplayController                                           Equ         19
ParallelController                                          Equ         20
PointerController                                           Equ         21
KeyboardController                                          Equ         22
AudioController                                             Equ         23
OtherController                                             Equ         24
DiskPeripheral                                              Equ         25
FloppyDiskPeripheral                                        Equ         26
TapePeripheral                                              Equ         27
ModemPeripheral                                             Equ         28
MonitorPeripheral                                           Equ         29
PrinterPeripheral                                           Equ         30
PointerPeripheral                                           Equ         31
KeyboardPeripheral                                          Equ         32
TerminalPeripheral                                          Equ         33
OtherPeripheral                                             Equ         34
LinePeripheral                                              Equ         35
NetworkPeripheral                                           Equ         36
SystemMemory                                                Equ         37
DockingInformation                                          Equ         38
RealModeIrqRoutingTable                                     Equ         39
RealModePCIEnumeration                                      Equ         40
MaximumType                                                 Equ         41

SINGLE_GROUP_LEGACY_API                                     Equ         1

PROTECTED_POOL                                              Equ         80000000H

ZONE_SEGMENT_HEADER Struct
    SegmentList                                             SINGLE_LIST_ENTRY   <>
    Reserved                                                PVOID       ?
ZONE_SEGMENT_HEADER EndS
PZONE_SEGMENT_HEADER                                        TypeDef     DWord

ZONE_HEADER Struct
    FreeList                                                SINGLE_LIST_ENTRY   <>
    SegmentList                                             SINGLE_LIST_ENTRY   <>
    BlockSize                                               DD          ?
    TotalSegmentSize                                        DD          ?
ZONE_HEADER EndS
PZONE_HEADER                                                TypeDef     DWord

ExInitializeResource                                        Equ         <ExInitializeResourceLite>
ExAcquireResourceShared                                     Equ         <ExAcquireResourceSharedLite>
ExAcquireResourceExclusive                                  Equ         <ExAcquireResourceExclusiveLite>
ExReleaseResourceForThread                                  Equ         <ExReleaseResourceForThreadLite>
ExConvertExclusiveToShared                                  Equ         <ExConvertExclusiveToSharedLite>
ExDeleteResource                                            Equ         <ExDeleteResourceLite>
ExIsResourceAcquiredExclusive                               Equ         <ExIsResourceAcquiredExclusiveLite>
ExIsResourceAcquiredShared                                  Equ         <ExIsResourceAcquiredSharedLite>
ExIsResourceAcquired                                        Equ         <ExIsResourceAcquiredSharedLite>

UUID                                                        TypeDef     GUID

EVENT_INCREMENT                                             Equ         1

IO_NO_INCREMENT                                             Equ         0

IO_CD_ROM_INCREMENT                                         Equ         1

IO_DISK_INCREMENT                                           Equ         1

IO_KEYBOARD_INCREMENT                                       Equ         6

IO_MAILSLOT_INCREMENT                                       Equ         2

IO_MOUSE_INCREMENT                                          Equ         6

IO_NAMED_PIPE_INCREMENT                                     Equ         2

IO_NETWORK_INCREMENT                                        Equ         2

IO_PARALLEL_INCREMENT                                       Equ         1

IO_SERIAL_INCREMENT                                         Equ         2

IO_SOUND_INCREMENT                                          Equ         8

IO_VIDEO_INCREMENT                                          Equ         1

SEMAPHORE_INCREMENT                                         Equ         1

PHYSICAL_MEMORY_RANGE Struct
    BaseAddress                                             PHYSICAL_ADDRESS    <>
    NumberOfBytes                                           LARGE_INTEGER   <>
PHYSICAL_MEMORY_RANGE EndS
PPHYSICAL_MEMORY_RANGE                                      TypeDef     DWord

;MM_ROTATE_DIRECTION Enumeration
MM_ROTATE_DIRECTION                                         TypeDef     DWord
MmToFrameBuffer                                             Equ         0
MmToFrameBufferNoCopy                                       Equ         1
MmToRegularMemory                                           Equ         2
MmToRegularMemoryNoCopy                                     Equ         3
MmMaximumRotateDirection                                    Equ         4

IMAGE_ADDRESSING_MODE_32BIT                                 Equ         3

IRP_MN_QUERY_DIRECTORY                                      Equ         01H
IRP_MN_NOTIFY_CHANGE_DIRECTORY                              Equ         02H

IRP_MN_USER_FS_REQUEST                                      Equ         00H
IRP_MN_MOUNT_VOLUME                                         Equ         01H
IRP_MN_VERIFY_VOLUME                                        Equ         02H
IRP_MN_LOAD_FILE_SYSTEM                                     Equ         03H
IRP_MN_TRACK_LINK                                           Equ         04H
IRP_MN_KERNEL_CALL                                          Equ         04H

IRP_MN_LOCK                                                 Equ         01H
IRP_MN_UNLOCK_SINGLE                                        Equ         02H
IRP_MN_UNLOCK_ALL                                           Equ         03H
IRP_MN_UNLOCK_ALL_BY_KEY                                    Equ         04H

IRP_MN_FLUSH_AND_PURGE                                      Equ         01H

IRP_MN_NORMAL                                               Equ         00H
IRP_MN_DPC                                                  Equ         01H
IRP_MN_MDL                                                  Equ         02H
IRP_MN_COMPLETE                                             Equ         04H
IRP_MN_COMPRESSED                                           Equ         08H

IRP_MN_MDL_DPC                                              Equ         (IRP_MN_MDL Or IRP_MN_DPC)
IRP_MN_COMPLETE_MDL                                         Equ         (IRP_MN_COMPLETE Or IRP_MN_MDL)
IRP_MN_COMPLETE_MDL_DPC                                     Equ         (IRP_MN_COMPLETE_MDL Or IRP_MN_DPC)

IRP_MN_QUERY_LEGACY_BUS_INFORMATION                         Equ         18H

IO_CHECK_CREATE_PARAMETERS                                  Equ         0200H
IO_ATTACH_DEVICE                                            Equ         0400H

IO_IGNORE_SHARE_ACCESS_CHECK                                Equ         0800H

;IO_QUERY_DEVICE_DATA_FORMAT Enumeration
IO_QUERY_DEVICE_DATA_FORMAT                                 TypeDef     DWord
IoQueryDeviceIdentifier                                     Equ         0
IoQueryDeviceConfigurationData                              Equ         1
IoQueryDeviceComponentInformation                           Equ         2
IoQueryDeviceMaxData                                        Equ         3

CONTROLLER_OBJECT Struct
    _Type                                                   CSHORT      ?   ;Type
    _Size                                                   CSHORT      ?   ;Size
    ControllerExtension                                     PVOID       ?
    DeviceWaitQueue                                         KDEVICE_QUEUE   <>
    Spare1                                                  DD          ?
    Spare2                                                  LARGE_INTEGER   <>
CONTROLLER_OBJECT EndS
PCONTROLLER_OBJECT                                          TypeDef     DWord

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
DRVO_REINIT_REGISTERED                                      Equ         00000008H
DRVO_INITIALIZED                                            Equ         00000010H
DRVO_BOOTREINIT_REGISTERED                                  Equ         00000020H
DRVO_LEGACY_RESOURCES                                       Equ         00000040H

CONFIGURATION_INFORMATION Struct
    DiskCount                                               DD          ?
    FloppyCount                                             DD          ?
    CdRomCount                                              DD          ?
    TapeCount                                               DD          ?
    ScsiPortCount                                           DD          ?
    SerialCount                                             DD          ?
    ParallelCount                                           DD          ?
    AtDiskPrimaryAddressClaimed                             BOOLEAN     ?
    AtDiskSecondaryAddressClaimed                           BOOLEAN     ?
    Version                                                 DD          ?
    MediumChangerCount                                      DD          ?
CONFIGURATION_INFORMATION EndS
PCONFIGURATION_INFORMATION                                  TypeDef     DWord

DISK_SIGNATURE Struct
    PartitionStyle                                          DD          ?
    Union
        Struct Mbr
            Signature                                       DD          ?
            CheckSum                                        DD          ?
        EndS

        Struct Gpt
            DiskId                                          GUID        <>
        EndS
    EndS
DISK_SIGNATURE EndS
PDISK_SIGNATURE                                             TypeDef     DWord

TXN_PARAMETER_BLOCK Struct
    _Length                                                 DW          ?   ;Length
    TxFsContext                                             DW          ?
    TransactionObject                                       PVOID       ?
TXN_PARAMETER_BLOCK EndS
PTXN_PARAMETER_BLOCK                                        TypeDef     DWord

TXF_MINIVERSION_DEFAULT_VIEW                                Equ         (0FFFEH)

IO_DRIVER_CREATE_CONTEXT Struct
    _Size                                                   CSHORT      ?   ;Size
    ExtraCreateParameter                                    DD          ?
    DeviceObjectHint                                        PVOID       ?
    TxnParameters                                           PTXN_PARAMETER_BLOCK    ?
IO_DRIVER_CREATE_CONTEXT EndS
PIO_DRIVER_CREATE_CONTEXT                                   TypeDef     DWord

AGP_TARGET_BUS_INTERFACE_STANDARD Struct
    _Size                                                   DW          ?   ;Size
    Version                                                 DW          ?
    Context                                                 PVOID       ?
    InterfaceReference                                      DD          ?
    InterfaceDereference                                    DD          ?
    SetBusData                                              DD          ?
    GetBusData                                              DD          ?
    CapabilityID                                            DB          ?
AGP_TARGET_BUS_INTERFACE_STANDARD EndS
PAGP_TARGET_BUS_INTERFACE_STANDARD                          TypeDef     DWord

PNP_LOCATION_INTERFACE Struct
    _Size                                                   DW          ?   ;Size
    Version                                                 DW          ?
    Context                                                 PVOID       ?
    InterfaceReference                                      DD          ?
    InterfaceDereference                                    DD          ?
    GetLocationString                                       DD          ?
PNP_LOCATION_INTERFACE EndS
PPNP_LOCATION_INTERFACE                                     TypeDef     DWord

;ARBITER_ACTION Enumeration
ARBITER_ACTION                                              TypeDef     DWord
ArbiterActionTestAllocation                                 Equ         0
ArbiterActionRetestAllocation                               Equ         1
ArbiterActionCommitAllocation                               Equ         2
ArbiterActionRollbackAllocation                             Equ         3
ArbiterActionQueryAllocatedResources                        Equ         4
ArbiterActionWriteReservedResources                         Equ         5
ArbiterActionQueryConflict                                  Equ         6
ArbiterActionQueryArbitrate                                 Equ         7
ArbiterActionAddReserved                                    Equ         8
ArbiterActionBootAllocation                                 Equ         9

ARBITER_CONFLICT_INFO Struct
    OwningObject                                            PDEVICE_OBJECT  ?
    _Start                                                  DQ          ?   ;Start
    _End                                                    DQ          ?   ;End
ARBITER_CONFLICT_INFO EndS
PARBITER_CONFLICT_INFO                                      TypeDef     DWord

ARBITER_TEST_ALLOCATION_PARAMETERS Struct
    ArbitrationList                                         PLIST_ENTRY ?
    AllocateFromCount                                       DD          ?
    AllocateFrom                                            PCM_PARTIAL_RESOURCE_DESCRIPTOR ?
ARBITER_TEST_ALLOCATION_PARAMETERS EndS
PARBITER_TEST_ALLOCATION_PARAMETERS                         TypeDef     DWord

ARBITER_RETEST_ALLOCATION_PARAMETERS Struct
    ArbitrationList                                         PLIST_ENTRY ?
    AllocateFromCount                                       DD          ?
    AllocateFrom                                            PCM_PARTIAL_RESOURCE_DESCRIPTOR ?
ARBITER_RETEST_ALLOCATION_PARAMETERS EndS
PARBITER_RETEST_ALLOCATION_PARAMETERS                       TypeDef     DWord

ARBITER_BOOT_ALLOCATION_PARAMETERS Struct
    ArbitrationList                                         PLIST_ENTRY ?
ARBITER_BOOT_ALLOCATION_PARAMETERS EndS
PARBITER_BOOT_ALLOCATION_PARAMETERS                         TypeDef     DWord

ARBITER_QUERY_ALLOCATED_RESOURCES_PARAMETERS Struct
    AllocatedResources                                      PCM_PARTIAL_RESOURCE_LIST   ?
ARBITER_QUERY_ALLOCATED_RESOURCES_PARAMETERS EndS
PARBITER_QUERY_ALLOCATED_RESOURCES_PARAMETERS               TypeDef     DWord

ARBITER_QUERY_CONFLICT_PARAMETERS Struct
    PhysicalDeviceObject                                    PDEVICE_OBJECT ?
    ConflictingResource                                     PIO_RESOURCE_DESCRIPTOR ?
    ConflictCount                                           DD          ?
    Conflicts                                               PARBITER_CONFLICT_INFO ?
ARBITER_QUERY_CONFLICT_PARAMETERS EndS
PARBITER_QUERY_CONFLICT_PARAMETERS                          TypeDef     DWord

ARBITER_QUERY_ARBITRATE_PARAMETERS Struct
    ArbitrationList                                         PLIST_ENTRY ?
ARBITER_QUERY_ARBITRATE_PARAMETERS EndS
PARBITER_QUERY_ARBITRATE_PARAMETERS                         TypeDef     DWord

ARBITER_ADD_RESERVED_PARAMETERS Struct
    ReserveDevice                                           PDEVICE_OBJECT  ?
ARBITER_ADD_RESERVED_PARAMETERS EndS
PARBITER_ADD_RESERVED_PARAMETERS                            TypeDef     DWord


ARBITER_PARAMETERS Struct
    Union Parameters
        TestAllocation                                      ARBITER_TEST_ALLOCATION_PARAMETERS  <>
        RetestAllocation                                    ARBITER_RETEST_ALLOCATION_PARAMETERS    <>
        BootAllocation                                      ARBITER_BOOT_ALLOCATION_PARAMETERS  <>
        QueryAllocatedResources                             ARBITER_QUERY_ALLOCATED_RESOURCES_PARAMETERS    <>
        QueryConflict                                       ARBITER_QUERY_CONFLICT_PARAMETERS   <>
        QueryArbitrate                                      ARBITER_QUERY_ARBITRATE_PARAMETERS  <>
        AddReserved                                         ARBITER_ADD_RESERVED_PARAMETERS <>
    EndS
ARBITER_PARAMETERS EndS
PARBITER_PARAMETERS                                         TypeDef     DWord

;ARBITER_REQUEST_SOURCE Enumeration
ARBITER_REQUEST_SOURCE                                      TypeDef     DWord
ArbiterRequestUndefined                                     Equ         (-1)
ArbiterRequestLegacyReported                                Equ         0
ArbiterRequestHalReported                                   Equ         1
ArbiterRequestLegacyAssigned                                Equ         2
ArbiterRequestPnpDetected                                   Equ         3
ArbiterRequestPnpEnumerated                                 Equ         4

;ARBITER_RESULT Enumeration
ARBITER_RESULT                                              TypeDef     DWord
ArbiterResultUndefined                                      Equ         (-1)
ArbiterResultSuccess                                        Equ         0
ArbiterResultExternalConflict                               Equ         1
ArbiterResultNullRequest                                    Equ         2

ARBITER_FLAG_BOOT_CONFIG                                    Equ         00000001H

ARBITER_LIST_ENTRY Struct
    ListEntry                                               LIST_ENTRY  <>
    AlternativeCount                                        DD          ?
    Alternatives                                            PIO_RESOURCE_DESCRIPTOR ?
    PhysicalDeviceObject                                    PDEVICE_OBJECT  ?
    RequestSource                                           ARBITER_REQUEST_SOURCE  ?
    Flags                                                   DD          ?
    WorkSpace                                               DD          ?
    InterfaceType                                           INTERFACE_TYPE  ?
    SlotNumber                                              DD          ?
    BusNumber                                               DD          ?
    Assignment                                              PCM_PARTIAL_RESOURCE_DESCRIPTOR ?
    SelectedAlternative                                     PIO_RESOURCE_DESCRIPTOR ?
    Result                                                  ARBITER_RESULT  ?
ARBITER_LIST_ENTRY EndS
PARBITER_LIST_ENTRY                                         TypeDef     DWord

ARBITER_PARTIAL                                             Equ         00000001H

ARBITER_INTERFACE Struct
    _Size                                                   DW          ?   ;Size
    Version                                                 DW          ?
    Context                                                 PVOID       ?
    InterfaceReference                                      DD          ?   ;PINTERFACE_REFERENCE
    InterfaceDereference                                    DD          ?   ;PINTERFACE_DEREFERENCE
    ArbiterHandler                                          DD          ?   ;PARBITER_HANDLER
    Flags                                                   DD          ?
ARBITER_INTERFACE EndS
PARBITER_INTERFACE                                          TypeDef     DWord

;RESOURCE_TRANSLATION_DIRECTION Enumeration
RESOURCE_TRANSLATION_DIRECTION                              TypeDef     DWord
TranslateChildToParent                                      Equ         0
TranslateParentToChild                                      Equ         1

TRANSLATOR_INTERFACE Struct
    _Size                                                   DW          ?   ;Size
    Version                                                 DW          ?
    Context                                                 PVOID       ?
    InterfaceReference                                      DD          ?   ;PINTERFACE_REFERENCE
    InterfaceDereference                                    DD          ?   ;PINTERFACE_DEREFERENCE
    TranslateResources                                      DD          ?   ;PTRANSLATE_RESOURCE_HANDLER
    TranslateResourceRequirements                           DD          ?   ;PTRANSLATE_RESOURCE_REQUIREMENTS_HANDLER
TRANSLATOR_INTERFACE EndS
PTRANSLATOR_INTERFACE                                       TypeDef     DWord

;HAL_QUERY_INFORMATION_CLASS Enumeration
HAL_QUERY_INFORMATION_CLASS                                 TypeDef     DWord
HalInstalledBusInformation                                  Equ         0
HalProfileSourceInformation                                 Equ         1
HalInformationClassUnused1                                  Equ         2
HalPowerInformation                                         Equ         3
HalProcessorSpeedInformation                                Equ         4
HalCallbackInformation                                      Equ         5
HalMapRegisterInformation                                   Equ         6
HalMcaLogInformation                                        Equ         7
HalFrameBufferCachingInformation                            Equ         8
HalDisplayBiosInformation                                   Equ         9
HalProcessorFeatureInformation                              Equ         10
HalNumaTopologyInterface                                    Equ         11
HalErrorInformation                                         Equ         12
HalCmcLogInformation                                        Equ         13
HalCpeLogInformation                                        Equ         14
HalQueryMcaInterface                                        Equ         15
HalQueryAMLIIllegalIOPortAddresses                          Equ         16
HalQueryMaxHotPlugMemoryAddress                             Equ         17
HalPartitionIpiInterface                                    Equ         18
HalPlatformInformation                                      Equ         19
HalQueryProfileSourceList                                   Equ         20
HalInitLogInformation                                       Equ         21
HalFrequencyInformation                                     Equ         22
HalProcessorBrandString                                     Equ         23
HalHypervisorInformation                                    Equ         24
HalPlatformTimerInformation                                 Equ         25
HalAcpiAuditInformation                                     Equ         26
PHAL_QUERY_INFORMATION_CLASS                                TypeDef     DWord

;HAL_SET_INFORMATION_CLASS Enumeration
HAL_SET_INFORMATION_CLASS                                   TypeDef     DWord
HalProfileSourceInterval                                    Equ         0
HalProfileSourceInterruptHandler                            Equ         1
HalMcaRegisterDriver                                        Equ         2
HalKernelErrorHandler                                       Equ         3
HalCmcRegisterDriver                                        Equ         4
HalCpeRegisterDriver                                        Equ         5
HalMcaLog                                                   Equ         6
HalCmcLog                                                   Equ         7
HalCpeLog                                                   Equ         8
HalGenerateCmcInterrupt                                     Equ         9
HalProfileSourceTimerHandler                                Equ         10
HalEnlightenment                                            Equ         11
HalProfileDpgoSourceInterruptHandler                        Equ         12
PHAL_SET_INFORMATION_CLASS                                  TypeDef     DWord

PM_DISPATCH_TABLE Struct
    Signature                                               DD          ?
    Version                                                 DD          ?
    Function                                                PVOID       1 Dup(?)
PM_DISPATCH_TABLE EndS
PPM_DISPATCH_TABLE                                          TypeDef     DWord

DEBUG_DEVICE_ADDRESS Struct
    _Type                                                   DB          ?   ;Type
    Valid                                                   BOOLEAN     ?
    Reserved                                                DB          2 Dup(?)
    TranslatedAddress                                       DD          ?
    _Length                                                 DD          ?   ;Length
DEBUG_DEVICE_ADDRESS EndS
PDEBUG_DEVICE_ADDRESS                                       TypeDef     DWord

DEBUG_MEMORY_REQUIREMENTS Struct
    _Start                                                  PHYSICAL_ADDRESS    <>  ;Start
    MaxEnd                                                  PHYSICAL_ADDRESS    <>
    VirtualAddress                                          PVOID       ?
    _Length                                                 DD          ?   ;Length
    Cached                                                  BOOLEAN     ?
    Aligned                                                 BOOLEAN     ?
DEBUG_MEMORY_REQUIREMENTS EndS
PDEBUG_MEMORY_REQUIREMENTS                                  TypeDef     DWord

DEBUG_DEVICE_DESCRIPTOR Struct
    Bus                                                     DD          ?
    _Segment                                                DW          ?   ;Segment
    Slot                                                    DD          ?
    VendorID                                                DW          ?
    DeviceID                                                DW          ?
    BaseClass                                               DB          ?
    SubClass                                                DB          ?
    ProgIf                                                  DB          ?
    Initialized                                             BOOLEAN     ?
    Configured                                              BOOLEAN     ?
    BaseAddress                                             DEBUG_DEVICE_ADDRESS    6 Dup(<>)
    Memory                                                  DEBUG_MEMORY_REQUIREMENTS   <>
DEBUG_DEVICE_DESCRIPTOR EndS
PDEBUG_DEVICE_DESCRIPTOR                                    TypeDef     DWord

HAL_BUS_INFORMATION Struct
    BusType                                                 INTERFACE_TYPE  ?
    ConfigurationType                                       BUS_DATA_TYPE   ?
    BusNumber                                               DD          ?
    Reserved                                                DD          ?
HAL_BUS_INFORMATION EndS
PHAL_BUS_INFORMATION                                        TypeDef     DWord

HAL_PROFILE_SOURCE_INFORMATION Struct
    Source                                                  KPROFILE_SOURCE ?
    Supported                                               BOOLEAN     ?
    Interval                                                DD          ?
HAL_PROFILE_SOURCE_INFORMATION EndS
PHAL_PROFILE_SOURCE_INFORMATION                             TypeDef     DWord

HAL_PROFILE_SOURCE_INFORMATION_EX Struct
    Source                                                  KPROFILE_SOURCE ?
    Supported                                               BOOLEAN     ?
    Interval                                                DD          ?
    DefInterval                                             DD          ?
    MaxInterval                                             DD          ?
    MinInterval                                             DD          ?
HAL_PROFILE_SOURCE_INFORMATION_EX EndS
PHAL_PROFILE_SOURCE_INFORMATION_EX                          TypeDef     DWord

HAL_PROFILE_SOURCE_INTERVAL Struct
    Source                                                  KPROFILE_SOURCE ?
    Interval                                                DD          ?
HAL_PROFILE_SOURCE_INTERVAL EndS
PHAL_PROFILE_SOURCE_INTERVAL                                TypeDef     DWord

HAL_PROFILE_SOURCE_LIST Struct
    Source                                                  KPROFILE_SOURCE ?
    Description                                             DD          ?
HAL_PROFILE_SOURCE_LIST EndS
PHAL_PROFILE_SOURCE_LIST                                    TypeDef     DWord

;HAL_DISPLAY_BIOS_INFORMATION Enumeration
HAL_DISPLAY_BIOS_INFORMATION                                TypeDef     DWord
HalDisplayInt10Bios                                         Equ         0
HalDisplayEmulatedBios                                      Equ         1
HalDisplayNoBios                                            Equ         2
PHAL_DISPLAY_BIOS_INFORMATION                               TypeDef     DWord

HAL_POWER_INFORMATION Struct
    TBD                                                     DD          ?
HAL_POWER_INFORMATION EndS
PHAL_POWER_INFORMATION                                      TypeDef     DWord

HAL_PROCESSOR_SPEED_INFORMATION Struct
    ProcessorSpeed                                          DD          ?
HAL_PROCESSOR_SPEED_INFORMATION EndS
PHAL_PROCESSOR_SPEED_INFORMATION                            TypeDef     DWord

HAL_CALLBACKS Struct
    SetSystemInformation                                    DD          ?   ;PCALLBACK_OBJECT
    BusCheck                                                DD          ?   ;PCALLBACK_OBJECT
HAL_CALLBACKS EndS
PHAL_CALLBACKS                                              TypeDef     DWord

HAL_PROCESSOR_FEATURE Struct
    UsableFeatureBits                                       DD          ?
HAL_PROCESSOR_FEATURE EndS

HAL_AMLI_BAD_IO_ADDRESS_LIST Struct
    BadAddrBegin                                            DD          ?
    BadAddrSize                                             DD          ?
    OSVersionTrigger                                        DD          ?
    IOHandler                                               DD          ?   ;PHALIOREADWRITEHANDLER
HAL_AMLI_BAD_IO_ADDRESS_LIST EndS
PHAL_AMLI_BAD_IO_ADDRESS_LIST                               TypeDef     DWord

HAL_MCA_INTERFACE Struct
    _Lock                                                   DD          ?   ;Lock - PHALMCAINTERFACELOCK
    Unlock                                                  DD          ?   ;PHALMCAINTERFACEUNLOCK
    ReadRegister                                            DD          ?   ;PHALMCAINTERFACEREADREGISTER
HAL_MCA_INTERFACE EndS

;HAL_APIC_DESTINATION_MODE Enumeration
HAL_APIC_DESTINATION_MODE                                   TypeDef     DWord
ApicDestinationModePhysical                                 Equ         1
ApicDestinationModeLogicalFlat                              Equ         2
ApicDestinationModeLogicalClustered                         Equ         3
ApicDestinationModeUnknown                                  Equ         4
PHAL_APIC_DESTINATION_MODE                                  TypeDef     DWord

MCA_DRIVER_INFO Struct
    ExceptionCallback                                       DD          ?   ;PDRIVER_MCA_EXCEPTION_CALLBACK
    DpcCallback                                             DD          ?   ;PKDEFERRED_ROUTINE
    DeviceContext                                           PVOID       ?
MCA_DRIVER_INFO EndS
PMCA_DRIVER_INFO                                            TypeDef     DWord

HAL_ERROR_INFO Struct
    Version                                                 DD          ?
    InitMaxSize                                             DD          ?
    McaMaxSize                                              DD          ?
    McaPreviousEventsCount                                  DD          ?
    McaCorrectedEventsCount                                 DD          ?
    McaKernelDeliveryFails                                  DD          ?
    McaDriverDpcQueueFails                                  DD          ?
    McaReserved                                             DD          ?
    CmcMaxSize                                              DD          ?
    CmcPollingInterval                                      DD          ?
    CmcInterruptsCount                                      DD          ?
    CmcKernelDeliveryFails                                  DD          ?
    CmcDriverDpcQueueFails                                  DD          ?
    CmcGetStateFails                                        DD          ?
    CmcClearStateFails                                      DD          ?
    CmcReserved                                             DD          ?
    CmcLogId                                                DQ          ?
    CpeMaxSize                                              DD          ?
    CpePollingInterval                                      DD          ?
    CpeInterruptsCount                                      DD          ?
    CpeKernelDeliveryFails                                  DD          ?
    CpeDriverDpcQueueFails                                  DD          ?
    CpeGetStateFails                                        DD          ?
    CpeClearStateFails                                      DD          ?
    CpeInterruptSources                                     DD          ?
    CpeLogId                                                DQ          ?
    KernelReserved                                          DQ          4 Dup(?)
HAL_ERROR_INFO EndS
PHAL_ERROR_INFO                                             TypeDef     DWord

HAL_MCE_INTERRUPTS_BASED                                    Equ         (-1)
HAL_MCE_DISABLED                                            Equ         (0)

HAL_CMC_INTERRUPTS_BASED                                    Equ         HAL_MCE_INTERRUPTS_BASED
HAL_CMC_DISABLED                                            Equ         HAL_MCE_DISABLED

HAL_CPE_INTERRUPTS_BASED                                    Equ         HAL_MCE_INTERRUPTS_BASED
HAL_CPE_DISABLED                                            Equ         HAL_MCE_DISABLED

HAL_MCA_INTERRUPTS_BASED                                    Equ         HAL_MCE_INTERRUPTS_BASED
HAL_MCA_DISABLED                                            Equ         HAL_MCE_DISABLED

CMC_DRIVER_INFO Struct
    ExceptionCallback                                       DD          ?   ;PDRIVER_CMC_EXCEPTION_CALLBACK
    DpcCallback                                             DD          ?   ;PKDEFERRED_ROUTINE
    DeviceContext                                           PVOID       ?
CMC_DRIVER_INFO EndS
PCMC_DRIVER_INFO                                            TypeDef     DWord

CPE_DRIVER_INFO Struct
    ExceptionCallback                                       DD          ?   ;PDRIVER_CPE_EXCEPTION_CALLBACK
    DpcCallback                                             DD          ?   ;PKDEFERRED_ROUTINE
    DeviceContext                                           PVOID       ?
CPE_DRIVER_INFO EndS
PCPE_DRIVER_INFO                                            TypeDef     DWord

HAL_PLATFORM_INFORMATION Struct
    PlatformFlags                                           ULONG       ?
HAL_PLATFORM_INFORMATION EndS
PHAL_PLATFORM_INFORMATION                                   TypeDef     DWord

HAL_PLATFORM_DISABLE_WRITE_COMBINING                        Equ         01H
HAL_PLATFORM_DISABLE_PTCG                                   Equ         04H
HAL_PLATFORM_DISABLE_UC_MAIN_MEMORY                         Equ         08H
HAL_PLATFORM_ENABLE_WRITE_COMBINING_MMIO                    Equ         10H
HAL_PLATFORM_ACPI_TABLES_CACHED                             Equ         20H

;PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR_TYPE Enumeration
PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR_TYPE                   TypeDef     DWord
ResourceTypeSingle                                          Equ         0
ResourceTypeRange                                           Equ         1
ResourceTypeExtendedCounterConfiguration                    Equ         2
ResourceTypeOverflow                                        Equ         3
ResourceTypeMax                                             Equ         4

PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR Struct
    _Type                                                   PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR_TYPE   ?   ;Type
    Flags                                                   DD          ?
    Union u
        CounterIndex                                        DD          ?
        ExtendedRegisterAddress                             DD          ?
        Struct Range
            Begin                                           DD          ?
            _End                                            DD          ?   ;End
        EndS
    EndS
PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR EndS
PPHYSICAL_COUNTER_RESOURCE_DESCRIPTOR                       TypeDef     DWord

PHYSICAL_COUNTER_RESOURCE_LIST Struct
    Count                                                   ULONG       ?
    Descriptors                                             PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR    ANYSIZE_ARRAY Dup(<>)
PHYSICAL_COUNTER_RESOURCE_LIST EndS
PPHYSICAL_COUNTER_RESOURCE_LIST                             TypeDef     DWord

;EXTENDED_AGP_REGISTER Enumeration
EXTENDED_AGP_REGISTER                                       TypeDef     DWord
IsochStatus                                                 Equ         0
AgpControl                                                  Equ         1
ApertureSize                                                Equ         2
AperturePageSize                                            Equ         3
GartLow                                                     Equ         4
GartHigh                                                    Equ         5
IsochCommand                                                Equ         6
PEXTENDED_AGP_REGISTER                                      TypeDef     DWord

PCI_AGP_RATE_1X                                             Equ         01H
PCI_AGP_RATE_2X                                             Equ         02H
PCI_AGP_RATE_4X                                             Equ         04H

PCIX_MODE_CONVENTIONAL_PCI                                  Equ         00H
PCIX_MODE1_66MHZ                                            Equ         01H
PCIX_MODE1_100MHZ                                           Equ         02H
PCIX_MODE1_133MHZ                                           Equ         03H
PCIX_MODE2_266_66MHZ                                        Equ         09H
PCIX_MODE2_266_100MHZ                                       Equ         0AH
PCIX_MODE2_266_133MHZ                                       Equ         0BH
PCIX_MODE2_533_66MHZ                                        Equ         0DH
PCIX_MODE2_533_100MHZ                                       Equ         0EH
PCIX_MODE2_533_133MHZ                                       Equ         0FH

PCIX_VERSION_MODE1_ONLY                                     Equ         00H
PCIX_VERSION_MODE2_ECC                                      Equ         01H
PCIX_VERSION_DUAL_MODE_ECC                                  Equ         02H

PCI_SUBSYSTEM_IDS_CAPABILITY Struct
    Header                                                  PCI_CAPABILITIES_HEADER <>
    Reserved                                                DW          ?
    SubVendorID                                             DW          ?
    SubSystemID                                             DW          ?
PCI_SUBSYSTEM_IDS_CAPABILITY EndS
PPCI_SUBSYSTEM_IDS_CAPABILITY                               TypeDef     DWord

OSC_FIRMWARE_FAILURE                                        Equ         02H
OSC_UNRECOGNIZED_UUID                                       Equ         04H
OSC_UNRECOGNIZED_REVISION                                   Equ         08H
OSC_CAPABILITIES_MASKED                                     Equ         10H

PCI_ROOT_BUS_OSC_METHOD_CAPABILITY_REVISION                 Equ         01H

;PCI_HARDWARE_INTERFACE Enumeration
PCI_HARDWARE_INTERFACE                                      TypeDef     DWord
PciConventional                                             Equ         1
PciXMode1                                                   Equ         2
PciXMode2                                                   Equ         3
PciExpress                                                  Equ         4
PPCI_HARDWARE_INTERFACE                                     TypeDef     DWord

;PCI_BUS_WIDTH Enumeration
PCI_BUS_WIDTH                                               TypeDef     DWord
BusWidth32Bits                                              Equ         0
BusWidth64Bits                                              Equ         1

PCI_EXPRESS_AER_DEVICE_CONTROL_MASK                         Equ         07H

PCI_EXPRESS_AER_DEVICE_STATUS_MASK                          Equ         0FH

;PCI_EXPRESS_MRL_STATE Enumeration
PCI_EXPRESS_MRL_STATE                                       TypeDef     DWord
MRLClosed                                                   Equ         0
MRLOpen                                                     Equ         1

;PCI_EXPRESS_CARD_PRESENCE Enumeration
PCI_EXPRESS_CARD_PRESENCE                                   TypeDef     DWord
SlotEmpty                                                   Equ         0
CardPresent                                                 Equ         1

;PCI_EXPRESS_INDICATOR_STATE Enumeration
PCI_EXPRESS_INDICATOR_STATE                                 TypeDef     DWord
IndicatorOn                                                 Equ         1
IndicatorBlink                                              Equ         2
IndicatorOff                                                Equ         2

;PCI_EXPRESS_POWER_STATE Enumeration
PCI_EXPRESS_POWER_STATE                                     TypeDef     DWord
PowerOn                                                     Equ         0
PowerOff                                                    Equ         1

;PCI_EXPRESS_ASPM_SUPPORT Enumeration
PCI_EXPRESS_ASPM_SUPPORT                                    TypeDef     DWord
L0sEntrySupport                                             Equ         1
L0sAndL1EntrySupport                                        Equ         3

;PCI_EXPRESS_ASPM_CONTROL Enumeration
PCI_EXPRESS_ASPM_CONTROL                                    TypeDef     DWord
L0sAndL1EntryDisabled                                       Equ         0
L0sEntryEnabled                                             Equ         1
L1EntryEnabled                                              Equ         2
L0sAndL1EntryEnabled                                        Equ         3

;PCI_EXPRESS_L0s_EXIT_LATENCY Enumeration
PCI_EXPRESS_L0s_EXIT_LATENCY                                TypeDef     DWord
L0s_Below64ns                                               Equ         0
L0s_64ns_128ns                                              Equ         1
L0s_128ns_256ns                                             Equ         2
L0s_256ns_512ns                                             Equ         3
L0s_512ns_1us                                               Equ         4
L0s_1us_2us                                                 Equ         5
L0s_2us_4us                                                 Equ         6
L0s_Above4us                                                Equ         7

;PCI_EXPRESS_L1_EXIT_LATENCY Enumeration
PCI_EXPRESS_L1_EXIT_LATENCY                                 TypeDef     DWord
L1_Below1us                                                 Equ         0
L1_1us_2us                                                  Equ         1
L1_2us_4us                                                  Equ         2
L1_4us_8us                                                  Equ         3
L1_8us_16us                                                 Equ         4
L1_16us_32us                                                Equ         5
L1_32us_64us                                                Equ         6
L1_Above64us                                                Equ         7

;PCI_EXPRESS_DEVICE_TYPE Enumeration
PCI_EXPRESS_DEVICE_TYPE                                     TypeDef     DWord
PciExpressEndpoint                                          Equ         0
PciExpressLegacyEndpoint                                    Equ         1
PciExpressRootPort                                          Equ         4
PciExpressUpstreamSwitchPort                                Equ         5
PciExpressDownstreamSwitchPort                              Equ         6
PciExpressToPciXBridge                                      Equ         7
PciXToExpressBridge                                         Equ         8
PciExpressRootComplexIntegratedEndpoint                     Equ         9
PciExpressRootComplexEventCollector                         Equ         10

;PCI_EXPRESS_MAX_PAYLOAD_SIZE Enumeration
PCI_EXPRESS_MAX_PAYLOAD_SIZE                                TypeDef     DWord
MaxPayload128Bytes                                          Equ         0
MaxPayload256Bytes                                          Equ         1
MaxPayload512Bytes                                          Equ         2
MaxPayload1024Bytes                                         Equ         3
MaxPayload2048Bytes                                         Equ         4
MaxPayload4096Bytes                                         Equ         5

PCI_DATA_TAG                                                Equ         A(" ICP")
PCI_DATA_VERSION                                            Equ         1

PCI_BUS_INTERFACE_STANDARD Struct
    _Size                                                   DW          ?   ;Size
    Version                                                 DW          ?
    Context                                                 PVOID       ?
    InterfaceReference                                      DD          ?   ;PINTERFACE_REFERENCE
    InterfaceDereference                                    DD          ?   ;PINTERFACE_DEREFERENCE
    ReadConfig                                              DD          ?   ;PCI_READ_WRITE_CONFIG
    WriteConfig                                             DD          ?   ;PCI_READ_WRITE_CONFIG
    PinToLine                                               DD          ?   ;PCI_PIN_TO_LINE
    LineToPin                                               DD          ?   ;PCI_LINE_TO_PIN
    RootBusCapability                                       DD          ?   ;PCI_ROOT_BUS_CAPABILITY
    ExpressWakeControl                                      DD          ?   ;PCI_EXPRESS_WAKE_CONTROL
PCI_BUS_INTERFACE_STANDARD EndS
PPCI_BUS_INTERFACE_STANDARD                                 TypeDef     DWord

PCI_BUS_INTERFACE_STANDARD_VERSION                          Equ         1

;WHEA_ERROR_SOURCE_TYPE Enumeration
WHEA_ERROR_SOURCE_TYPE                                      TypeDef     DWord
WheaErrSrcTypeMCE                                           Equ         00H
WheaErrSrcTypeCMC                                           Equ         01H
WheaErrSrcTypeCPE                                           Equ         02H
WheaErrSrcTypeNMI                                           Equ         03H
WheaErrSrcTypePCIe                                          Equ         04H
WheaErrSrcTypeGeneric                                       Equ         05H
WheaErrSrcTypeINIT                                          Equ         06H
WheaErrSrcTypeBOOT                                          Equ         07H
WheaErrSrcTypeSCIGeneric                                    Equ         08H
WheaErrSrcTypeIPFMCA                                        Equ         09H
WheaErrSrcTypeIPFCMC                                        Equ         0AH
WheaErrSrcTypeIPFCPE                                        Equ         0BH
WheaErrSrcTypeMax                                           Equ         0CH
PWHEA_ERROR_SOURCE_TYPE                                     TypeDef     DWord

;WHEA_ERROR_SOURCE_STATE Enumeration
WHEA_ERROR_SOURCE_STATE                                     TypeDef     DWord
WheaErrSrcStateStopped                                      Equ         01H
WheaErrSrcStateStarted                                      Equ         02H
PWHEA_ERROR_SOURCE_STATE                                    TypeDef     DWord

WHEA_ERROR_SOURCE_DESCRIPTOR_VERSION_10                     Equ         10

WHEA_MAX_MC_BANKS                                           Equ         32

WHEA_ERROR_SOURCE_FLAG_FIRMWAREFIRST                        Equ         00000001H
WHEA_ERROR_SOURCE_FLAG_GLOBAL                               Equ         00000002H
WHEA_ERROR_SOURCE_FLAG_PREALLOCATE_PER_PROCESSOR            Equ         00000004H
WHEA_ERROR_SOURCE_FLAG_DEFAULTSOURCE                        Equ         80000000H

WHEA_ERROR_SOURCE_DESCRIPTOR_TYPE_XPFMCE                    Equ         0
WHEA_ERROR_SOURCE_DESCRIPTOR_TYPE_XPFCMC                    Equ         1
WHEA_ERROR_SOURCE_DESCRIPTOR_TYPE_XPFNMI                    Equ         2
WHEA_ERROR_SOURCE_DESCRIPTOR_TYPE_IPFMCA                    Equ         3
WHEA_ERROR_SOURCE_DESCRIPTOR_TYPE_IPFCMC                    Equ         4
WHEA_ERROR_SOURCE_DESCRIPTOR_TYPE_IPFCPE                    Equ         5
WHEA_ERROR_SOURCE_DESCRIPTOR_TYPE_AERROOTPORT               Equ         6
WHEA_ERROR_SOURCE_DESCRIPTOR_TYPE_AERENDPOINT               Equ         7
WHEA_ERROR_SOURCE_DESCRIPTOR_TYPE_AERBRIDGE                 Equ         8
WHEA_ERROR_SOURCE_DESCRIPTOR_TYPE_GENERIC                   Equ         9

WHEA_XPF_MC_BANK_STATUSFORMAT_IA32MCA                       Equ         0
WHEA_XPF_MC_BANK_STATUSFORMAT_Intel64MCA                    Equ         1
WHEA_XPF_MC_BANK_STATUSFORMAT_AMD64MCA                      Equ         2

WHEA_NOTIFICATION_TYPE_POLLED                               Equ         0
WHEA_NOTIFICATION_TYPE_EXTERNALINTERRUPT                    Equ         1
WHEA_NOTIFICATION_TYPE_LOCALINTERRUPT                       Equ         2
WHEA_NOTIFICATION_TYPE_SCI                                  Equ         3
WHEA_NOTIFICATION_TYPE_NMI                                  Equ         4

WHEA_XPF_NMI_DESCRIPTOR Struct
    _Type                                                   DW          ?   ;Type
    Enabled                                                 BOOLEAN     ?
WHEA_XPF_NMI_DESCRIPTOR EndS
PWHEA_XPF_NMI_DESCRIPTOR                                    TypeDef     DWord

WHEA_IPF_MCA_DESCRIPTOR Struct
    _Type                                                   DW          ?   ;Type
    Enabled                                                 DB          ?
    Reserved                                                DB          ?
WHEA_IPF_MCA_DESCRIPTOR EndS
PWHEA_IPF_MCA_DESCRIPTOR                                    TypeDef     DWord

WHEA_IPF_CMC_DESCRIPTOR Struct
    _Type                                                   DW          ?   ;Type
    Enabled                                                 DB          ?
    Reserved                                                DB          ?
WHEA_IPF_CMC_DESCRIPTOR EndS
PWHEA_IPF_CMC_DESCRIPTOR                                    TypeDef     DWord

WHEA_IPF_CPE_DESCRIPTOR Struct
    _Type                                                   DW          ?   ;Type
    Enabled                                                 DB          ?
    Reserved                                                DB          ?
WHEA_IPF_CPE_DESCRIPTOR EndS
PWHEA_IPF_CPE_DESCRIPTOR                                    TypeDef     DWord

WHEA_REVISION Union
    Struct DUMMYSTRUCTNAME
        MinorRevision                                       DB          ?
        MajorRevision                                       DB          ?
    EndS
    AsUSHORT                                                DW          ?
WHEA_REVISION EndS
PWHEA_REVISION                                              TypeDef     DWord

;WHEA_ERROR_SEVERITY Enumeration
WHEA_ERROR_SEVERITY                                         TypeDef     DWord
WheaErrSevRecoverable                                       Equ         0
WheaErrSevFatal                                             Equ         1
WheaErrSevCorrected                                         Equ         2
WheaErrSevInformational                                     Equ         3
PWHEA_ERROR_SEVERITY                                        TypeDef     DWord

ERRTYP_INTERNAL                                             Equ         01H
ERRTYP_BUS                                                  Equ         10H
ERRTYP_MEM                                                  Equ         04H
ERRTYP_TLB                                                  Equ         05H
ERRTYP_CACHE                                                Equ         06H
ERRTYP_FUNCTION                                             Equ         07H
ERRTYP_SELFTEST                                             Equ         08H
ERRTYP_FLOW                                                 Equ         09H
ERRTYP_MAP                                                  Equ         11H
ERRTYP_IMPROPER                                             Equ         12H
ERRTYP_UNIMPL                                               Equ         13H
ERRTYP_LOSSOFLOCKSTEP                                       Equ         14H
ERRTYP_RESPONSE                                             Equ         15H
ERRTYP_PARITY                                               Equ         16H
ERRTYP_PROTOCOL                                             Equ         17H
ERRTYP_PATHERROR                                            Equ         18H
ERRTYP_TIMEOUT                                              Equ         19H
ERRTYP_POISONED                                             Equ         1AH

WHEA_ERROR_RECORD_VALID_PLATFORMID                          Equ         00000001H
WHEA_ERROR_RECORD_VALID_TIMESTAMP                           Equ         00000002H
WHEA_ERROR_RECORD_VALID_PARTITIONID                         Equ         00000004H

WHEA_ERROR_RECORD_FLAGS_RECOVERED                           Equ         00000001H
WHEA_ERROR_RECORD_FLAGS_PREVIOUSERROR                       Equ         00000002H
WHEA_ERROR_RECORD_FLAGS_SIMULATED                           Equ         00000004H

WHEA_ERROR_RECORD_SIGNATURE                                 Equ         A("REPC")
WHEA_ERROR_RECORD_REVISION                                  Equ         0210H
WHEA_ERROR_RECORD_SIGNATURE_END                             Equ         0FFFFFFFFH

WHEA_SECTION_DESCRIPTOR_FLAGS_PRIMARY                       Equ         00000001H
WHEA_SECTION_DESCRIPTOR_FLAGS_CONTAINMENTWRN                Equ         00000002H
WHEA_SECTION_DESCRIPTOR_FLAGS_RESET                         Equ         00000004H
WHEA_SECTION_DESCRIPTOR_FLAGS_THRESHOLDEXCEEDED             Equ         00000008H
WHEA_SECTION_DESCRIPTOR_FLAGS_RESOURCENA                    Equ         00000010H
WHEA_SECTION_DESCRIPTOR_FLAGS_LATENTERROR                   Equ         00000020H

WHEA_ERROR_RECORD_SECTION_DESCRIPTOR_REVISION               Equ         0201H

GENPROC_PROCTYPE_XPF                                        Equ         0
GENPROC_PROCTYPE_IPF                                        Equ         1

GENPROC_PROCISA_X86                                         Equ         0
GENPROC_PROCISA_IPF                                         Equ         1
GENPROC_PROCISA_X64                                         Equ         2

GENPROC_PROCERRTYPE_UNKNOWN                                 Equ         0
GENPROC_PROCERRTYPE_CACHE                                   Equ         1
GENPROC_PROCERRTYPE_TLB                                     Equ         2
GENPROC_PROCERRTYPE_BUS                                     Equ         4
GENPROC_PROCERRTYPE_MAE                                     Equ         8

GENPROC_OP_GENERIC                                          Equ         0
GENPROC_OP_DATAREAD                                         Equ         1
GENPROC_OP_DATAWRITE                                        Equ         2
GENPROC_OP_INSTRUCTIONEXE                                   Equ         3

GENPROC_FLAGS_RESTARTABLE                                   Equ         01H
GENPROC_FLAGS_PRECISEIP                                     Equ         02H
GENPROC_FLAGS_OVERFLOW                                      Equ         04H
GENPROC_FLAGS_CORRECTED                                     Equ         08H

XPF_CACHE_CHECK_TRANSACTIONTYPE_INSTRUCTION                 Equ         0
XPF_CACHE_CHECK_TRANSACTIONTYPE_DATAACCESS                  Equ         1
XPF_CACHE_CHECK_TRANSACTIONTYPE_GENERIC                     Equ         2

XPF_CACHE_CHECK_OPERATION_GENERIC                           Equ         0
XPF_CACHE_CHECK_OPERATION_GENREAD                           Equ         1
XPF_CACHE_CHECK_OPERATION_GENWRITE                          Equ         2
XPF_CACHE_CHECK_OPERATION_DATAREAD                          Equ         3
XPF_CACHE_CHECK_OPERATION_DATAWRITE                         Equ         4
XPF_CACHE_CHECK_OPERATION_INSTRUCTIONFETCH                  Equ         5
XPF_CACHE_CHECK_OPERATION_PREFETCH                          Equ         6
XPF_CACHE_CHECK_OPERATION_EVICTION                          Equ         7
XPF_CACHE_CHECK_OPERATION_SNOOP                             Equ         8

XPF_TLB_CHECK_TRANSACTIONTYPE_INSTRUCTION                   Equ         0
XPF_TLB_CHECK_TRANSACTIONTYPE_DATAACCESS                    Equ         1
XPF_TLB_CHECK_TRANSACTIONTYPE_GENERIC                       Equ         2

XPF_TLB_CHECK_OPERATION_GENERIC                             Equ         0
XPF_TLB_CHECK_OPERATION_GENREAD                             Equ         1
XPF_TLB_CHECK_OPERATION_GENWRITE                            Equ         2
XPF_TLB_CHECK_OPERATION_DATAREAD                            Equ         3
XPF_TLB_CHECK_OPERATION_DATAWRITE                           Equ         4
XPF_TLB_CHECK_OPERATION_INSTRUCTIONFETCH                    Equ         5
XPF_TLB_CHECK_OPERATION_PREFETCH                            Equ         6

XPF_BUS_CHECK_TRANSACTIONTYPE_INSTRUCTION                   Equ         0
XPF_BUS_CHECK_TRANSACTIONTYPE_DATAACCESS                    Equ         1
XPF_BUS_CHECK_TRANSACTIONTYPE_GENERIC                       Equ         2

XPF_BUS_CHECK_OPERATION_GENERIC                             Equ         0
XPF_BUS_CHECK_OPERATION_GENREAD                             Equ         1
XPF_BUS_CHECK_OPERATION_GENWRITE                            Equ         2
XPF_BUS_CHECK_OPERATION_DATAREAD                            Equ         3
XPF_BUS_CHECK_OPERATION_DATAWRITE                           Equ         4
XPF_BUS_CHECK_OPERATION_INSTRUCTIONFETCH                    Equ         5
XPF_BUS_CHECK_OPERATION_PREFETCH                            Equ         6

XPF_BUS_CHECK_PARTICIPATION_PROCORIGINATED                  Equ         0
XPF_BUS_CHECK_PARTICIPATION_PROCRESPONDED                   Equ         1
XPF_BUS_CHECK_PARTICIPATION_PROCOBSERVED                    Equ         2
XPF_BUS_CHECK_PARTICIPATION_GENERIC                         Equ         3

XPF_BUS_CHECK_ADDRESS_MEMORY                                Equ         0
XPF_BUS_CHECK_ADDRESS_RESERVED                              Equ         1
XPF_BUS_CHECK_ADDRESS_IO                                    Equ         2
XPF_BUS_CHECK_ADDRESS_OTHER                                 Equ         3

XPF_MS_CHECK_ERRORTYPE_NOERROR                              Equ         0
XPF_MS_CHECK_ERRORTYPE_UNCLASSIFIED                         Equ         1
XPF_MS_CHECK_ERRORTYPE_MCROMPARITY                          Equ         2
XPF_MS_CHECK_ERRORTYPE_EXTERNAL                             Equ         3
XPF_MS_CHECK_ERRORTYPE_FRC                                  Equ         4
XPF_MS_CHECK_ERRORTYPE_INTERNALUNCLASSIFIED                 Equ         5

WHEA_X86_REGISTER_STATE Struct
    _Eax                                                    DD          ?
    _Ebx                                                    DD          ?
    _Ecx                                                    DD          ?
    _Edx                                                    DD          ?
    _Esi                                                    DD          ?
    _Edi                                                    DD          ?
    _Ebp                                                    DD          ?
    _Esp                                                    DD          ?
    _Cs                                                     DW          ?
    _Ds                                                     DW          ?
    _Ss                                                     DW          ?
    _Es                                                     DW          ?
    _Fs                                                     DW          ?
    _Gs                                                     DW          ?
    Eflags                                                  DD          ?
    Eip                                                     DD          ?
    _Cr0                                                    DD          ?
    Cr1                                                     DD          ?
    _Cr2                                                    DD          ?
    _Cr3                                                    DD          ?
    _Cr4                                                    DD          ?
    Gdtr                                                    DQ          ?
    Idtr                                                    DQ          ?
    Ldtr                                                    DW          ?
    Tr                                                      DW          ?
WHEA_X86_REGISTER_STATE EndS
PWHEA_X86_REGISTER_STATE                                    TypeDef     DWord

WHEA128A Struct
    _Low                                                    DQ          ?   ;Low
    _High                                                   DQ          ?   ;High
WHEA128A EndS
PWHEA128A                                                   TypeDef     DWord

WHEA_X64_REGISTER_STATE Struct
    Rax                                                     DQ          ?
    Rbx                                                     DQ          ?
    Rcx                                                     DQ          ?
    Rdx                                                     DQ          ?
    Rsi                                                     DQ          ?
    Rdi                                                     DQ          ?
    Rbp                                                     DQ          ?
    Rsp                                                     DQ          ?
    R8                                                      DQ          ?
    R9                                                      DQ          ?
    R10                                                     DQ          ?
    R11                                                     DQ          ?
    R12                                                     DQ          ?
    R13                                                     DQ          ?
    R14                                                     DQ          ?
    R15                                                     DQ          ?
    _Cs                                                     DW          ?
    _Ds                                                     DW          ?
    _Ss                                                     DW          ?
    _Es                                                     DW          ?
    _Fs                                                     DW          ?
    _Gs                                                     DW          ?
    Reserved                                                DD          ?
    Rflags                                                  DQ          ?
    Eip                                                     DQ          ?
    _Cr0                                                    DQ          ?
    Cr1                                                     DQ          ?
    _Cr2                                                    DQ          ?
    _Cr3                                                    DQ          ?
    _Cr4                                                    DQ          ?
    Cr8                                                     DQ          ?
    Gdtr                                                    WHEA128A    <>
    Idtr                                                    WHEA128A    <>
    Ldtr                                                    DW          ?
    Tr                                                      DW          ?
WHEA_X64_REGISTER_STATE EndS
PWHEA_X64_REGISTER_STATE                                    TypeDef     DWord

XPF_CONTEXT_INFO_UNCLASSIFIEDDATA                           Equ         0
XPF_CONTEXT_INFO_MSRREGISTERS                               Equ         1
XPF_CONTEXT_INFO_32BITCONTEXT                               Equ         2
XPF_CONTEXT_INFO_64BITCONTEXT                               Equ         3
XPF_CONTEXT_INFO_FXSAVE                                     Equ         4
XPF_CONTEXT_INFO_32BITDEBUGREGS                             Equ         5
XPF_CONTEXT_INFO_64BITDEBUGREGS                             Equ         6
XPF_CONTEXT_INFO_MMREGISTERS                                Equ         7

WHEA_XPF_CONTEXT_INFO Struct
    RegisterContextType                                     DW          ?
    RegisterDataSize                                        DW          ?
    MSRAddress                                              DD          ?
    MmRegisterAddress                                       DQ          ?
WHEA_XPF_CONTEXT_INFO EndS
PWHEA_XPF_CONTEXT_INFO                                      TypeDef     DWord

WHEA_MEMERRTYPE_UNKNOWN                                     Equ         00H
WHEA_MEMERRTYPE_NOERROR                                     Equ         01H
WHEA_MEMERRTYPE_SINGLEBITECC                                Equ         02H
WHEA_MEMERRTYPE_MULTIBITECC                                 Equ         03H
WHEA_MEMERRTYPE_SINGLESYMCHIPKILL                           Equ         04H
WHEA_MEMERRTYPE_MULTISYMCHIPKILL                            Equ         05H
WHEA_MEMERRTYPE_MASTERABORT                                 Equ         06H
WHEA_MEMERRTYPE_TARGETABORT                                 Equ         07H
WHEA_MEMERRTYPE_PARITYERROR                                 Equ         08H
WHEA_MEMERRTYPE_WATCHDOGTIMEOUT                             Equ         09H
WHEA_MEMERRTYPE_INVALIDADDRESS                              Equ         0AH
WHEA_MEMERRTYPE_MIRRORBROKEN                                Equ         0BH
WHEA_MEMERRTYPE_MEMORYSPARING                               Equ         0CH

WHEA_PCIEXPRESS_VERSION Union
    Struct DUMMYSTRUCTNAME
        MinorVersion                                        DB          ?
        MajorVersion                                        DB          ?
        Reserved                                            DW          ?
    EndS
    AsULONG                                                 DD          ?
WHEA_PCIEXPRESS_VERSION EndS
PWHEA_PCIEXPRESS_VERSION                                    TypeDef     DWord

WHEA_PCIEXPRESS_COMMAND_STATUS Union
    Struct DUMMYSTRUCTNAME
        Command                                             DW          ?
        Status                                              DW          ?
    EndS
    AsULONG                                                 DD          ?
WHEA_PCIEXPRESS_COMMAND_STATUS EndS
PWHEA_PCIEXPRESS_COMMAND_STATUS                             TypeDef     DWord

WHEA_PCIEXPRESS_BRIDGE_CONTROL_STATUS Union
    Struct DUMMYSTRUCTNAME
        BridgeSecondaryStatus                               DW          ?
        BridgeControl                                       DW          ?
    EndS
    AsULONG                                                 DD          ?
WHEA_PCIEXPRESS_BRIDGE_CONTROL_STATUS EndS
PWHEA_PCIEXPRESS_BRIDGE_CONTROL_STATUS                      TypeDef     DWord

;WHEA_PCIEXPRESS_DEVICE_TYPE Enumeration
WHEA_PCIEXPRESS_DEVICE_TYPE                                 TypeDef     DWord
WheaPciExpressEndpoint                                      Equ         0
WheaPciExpressLegacyEndpoint                                Equ         1
WheaPciExpressRootPort                                      Equ         4
WheaPciExpressUpstreamSwitchPort                            Equ         5
WheaPciExpressDownstreamSwitchPort                          Equ         6
WheaPciExpressToPciXBridge                                  Equ         7
WheaPciXToExpressBridge                                     Equ         8
WheaPciExpressRootComplexIntegratedEndpoint                 Equ         9
WheaPciExpressRootComplexEventCollector                     Equ         10

PCIXBUS_ERRTYPE_UNKNOWN                                     Equ         0000H
PCIXBUS_ERRTYPE_DATAPARITY                                  Equ         0001H
PCIXBUS_ERRTYPE_SYSTEM                                      Equ         0002H
PCIXBUS_ERRTYPE_MASTERABORT                                 Equ         0003H
PCIXBUS_ERRTYPE_BUSTIMEOUT                                  Equ         0004H
PCIXBUS_ERRTYPE_MASTERDATAPARITY                            Equ         0005H
PCIXBUS_ERRTYPE_ADDRESSPARITY                               Equ         0006H
PCIXBUS_ERRTYPE_COMMANDPARITY                               Equ         0007H

WHEA_PCIXBUS_ID Union
    Struct DUMMYSTRUCTNAME
        BusNumber                                           DW          ?
        BusSegment                                          DW          ?
    EndS
    AsUSHORT                                                DW          ?
WHEA_PCIXBUS_ID EndS
PWHEA_PCIXBUS_ID                                            TypeDef     DWord

WHEA_PCIXDEVICE_REGISTER_PAIR Struct
    Register                                                DQ          ?
    Data                                                    DQ          ?
WHEA_PCIXDEVICE_REGISTER_PAIR EndS
PWHEA_PCIXDEVICE_REGISTER_PAIR                              TypeDef     DWord

WHEA_FIRMWARE_RECORD_TYPE_IPFSAL                            Equ         0

WHEA_FIRMWARE_ERROR_RECORD_REFERENCE Struct
    _Type                                                   DB          ?
    Reserved                                                DB          7 Dup(?)
    FirmwareRecordId                                        DQ          ?
WHEA_FIRMWARE_ERROR_RECORD_REFERENCE EndS
PWHEA_FIRMWARE_ERROR_RECORD_REFERENCE                       TypeDef     DWord

WHEA_FIRMWARE_RECORD                                        TypeDef     WHEA_FIRMWARE_ERROR_RECORD_REFERENCE
PWHEA_FIRMWARE_RECORD                                       TypeDef     DWord

;WHEA_CPU_VENDOR Enumeration
WHEA_CPU_VENDOR                                             TypeDef     DWord
WheaCpuVendorOther                                          Equ         0
WheaCpuVendorIntel                                          Equ         1
WheaCpuVendorAmd                                            Equ         2
PWHEA_CPU_VENDOR                                            TypeDef     DWord

WHEA_XPF_MCA_EXTREG_MAX_COUNT                               Equ         24
WHEA_XPF_MCA_SECTION_VERSION                                Equ         1

DEFINE_GUID     CMC_NOTIFY_TYPE_GUID,                       02DCE8BB1H, 0BDD7H, 0450EH, 0B9H, 0ADH, 09CH, 0F4H, 0EBH, 0D4H, 0F8H, 090H
DEFINE_GUID     CPE_NOTIFY_TYPE_GUID,                       04E292F96H, 0D843H, 04A55H, 0A8H, 0C2H, 0D4H, 081H, 0F2H, 07EH, 0BEH, 0EEH
DEFINE_GUID     MCE_NOTIFY_TYPE_GUID,                       0E8F56FFEH, 0919CH, 04CC5H, 0BAH, 088H, 065H, 0ABH, 0E1H, 049H, 013H, 0BBH
DEFINE_GUID     PCIe_NOTIFY_TYPE_GUID,                      0CF93C01FH, 01A16H, 04DFCH, 0B8H, 0BCH, 09CH, 04DH, 0AFH, 067H, 0C1H, 004H
DEFINE_GUID     INIT_NOTIFY_TYPE_GUID,                      0CC5263E8H, 09308H, 0454AH, 089H, 0D0H, 034H, 00BH, 0D3H, 09BH, 0C9H, 08EH
DEFINE_GUID     NMI_NOTIFY_TYPE_GUID,                       05BAD89FFH, 0B7E6H, 042C9H, 081H, 04AH, 0CFH, 024H, 085H, 0D6H, 0E9H, 08AH
DEFINE_GUID     BOOT_NOTIFY_TYPE_GUID,                      03D61A466H, 0AB40H, 0409AH, 0A6H, 098H, 0F3H, 062H, 0D4H, 064H, 0B3H, 08FH
DEFINE_GUID     PROCESSOR_GENERIC_ERROR_SECTION_GUID,       09876CCADH, 047B4H, 04BDBH, 0B6H, 05EH, 016H, 0F1H, 093H, 0C4H, 0F3H, 0DBH
DEFINE_GUID     XPF_PROCESSOR_ERROR_SECTION_GUID,           0DC3EA0B0H, 0A144H, 04797H, 0B9H, 05BH, 053H, 0FAH, 024H, 02BH, 06EH, 01DH
DEFINE_GUID     IPF_PROCESSOR_ERROR_SECTION_GUID,           0E429FAF1H, 03CB7H, 011D4H, 0BCH, 0A7H, 000H, 080H, 0C7H, 03CH, 088H, 081H
DEFINE_GUID     MEMORY_ERROR_SECTION_GUID,                  0A5BC1114H, 06F64H, 04EDEH, 0B8H, 063H, 03EH, 083H, 0EDH, 07CH, 083H, 0B1H
DEFINE_GUID     PCIEXPRESS_ERROR_SECTION_GUID,              0D995E954H, 0BBC1H, 0430FH, 0ADH, 091H, 0B4H, 04DH, 0CBH, 03CH, 06FH, 035H
DEFINE_GUID     PCIXBUS_ERROR_SECTION_GUID,                 0C5753963H, 03B84H, 04095H, 0BFH, 078H, 0EDH, 0DAH, 0D3H, 0F9H, 0C9H, 0DDH
DEFINE_GUID     PCIXDEVICE_ERROR_SECTION_GUID,              0EB5E4685H, 0CA66H, 04769H, 0B6H, 0A2H, 026H, 006H, 08BH, 000H, 013H, 026H
DEFINE_GUID     FIRMWARE_ERROR_RECORD_REFERENCE_GUID,       081212A96H, 009EDH, 04996H, 094H, 071H, 08DH, 072H, 09CH, 08EH, 069H, 0EDH

DEFINE_GUID     WHEA_CACHECHECK_GUID,                       0A55701F5H, 0E3EFH, 043DEH, 0ACH, 072H, 024H, 09BH, 057H, 03FH, 0ADH, 02CH
DEFINE_GUID     WHEA_TLBCHECK_GUID,                         0FC06B535H, 05E1FH, 04562H, 09FH, 025H, 00AH, 03BH, 09AH, 0DBH, 063H, 0C3H
DEFINE_GUID     WHEA_BUSCHECK_GUID,                         01CF3F8B3H, 0C5B1H, 049A2H, 0AAH, 059H, 05EH, 0EFH, 092H, 0FFH, 0A6H, 03CH
DEFINE_GUID     WHEA_MSCHECK_GUID,                          048AB7F57H, 0DC34H, 04F6CH, 0A7H, 0D3H, 0B0H, 0B5H, 0B0H, 0A7H, 043H, 014H

DEFINE_GUID     WHEA_RECORD_CREATOR_GUID,                   0CF07C4BDH, 0B789H, 04E18H, 0B3H, 0C4H, 01FH, 073H, 02CH, 0B5H, 071H, 031H

DEFINE_GUID     GENERIC_NOTIFY_TYPE_GUID,                   03E62A467H, 0AB40H, 0409AH, 0A6H, 098H, 0F3H, 062H, 0D4H, 064H, 0B3H, 08FH

DEFINE_GUID     IPF_SAL_RECORD_SECTION_GUID,                06F3380D1H, 06EB0H, 0497FH, 0A5H, 078H, 04DH, 04CH, 065H, 0A7H, 016H, 017H
DEFINE_GUID     XPF_MCA_SECTION_GUID,                       08A1E1D01H, 042F9H, 04557H, 09CH, 033H, 056H, 05EH, 05CH, 0C3H, 0F7H, 0E8H
DEFINE_GUID     NMI_SECTION_GUID,                           0E71254E7H, 0C1B9H, 04940H, 0ABH, 076H, 090H, 097H, 003H, 0A4H, 032H, 00FH
DEFINE_GUID     GENERIC_SECTION_GUID,                       0E71254E8H, 0C1B9H, 04940H, 0ABH, 076H, 090H, 097H, 003H, 0A4H, 032H, 00FH
DEFINE_GUID     WHEA_ERROR_PACKET_SECTION_GUID,             0E71254E9H, 0C1B9H, 04940H, 0ABH, 076H, 090H, 097H, 003H, 0A4H, 032H, 00FH

;WHEA_ERROR_TYPE Enumeration
WHEA_ERROR_TYPE                                             TypeDef     DWord
WheaErrTypeProcessor                                        Equ         0
WheaErrTypeMemory                                           Equ         1
WheaErrTypePCIExpress                                       Equ         2
WheaErrTypeNMI                                              Equ         3
WheaErrTypePCIXBus                                          Equ         4
WheaErrTypePCIXDevice                                       Equ         5
WheaErrTypeGeneric                                          Equ         6
PWHEA_ERROR_TYPE                                            TypeDef     DWord

;WHEA_ERROR_PACKET_DATA_FORMAT Enumeration
WHEA_ERROR_PACKET_DATA_FORMAT                               TypeDef     DWord
WheaDataFormatIPFSalRecord                                  Equ         0
WheaDataFormatXPFMCA                                        Equ         1
WheaDataFormatMemory                                        Equ         2
WheaDataFormatPCIExpress                                    Equ         3
WheaDataFormatNMIPort                                       Equ         4
WheaDataFormatPCIXBus                                       Equ         5
WheaDataFormatPCIXDevice                                    Equ         6
WheaDataFormatGeneric                                       Equ         7
WheaDataFormatMax                                           Equ         8
PWHEA_ERROR_PACKET_DATA_FORMAT                              TypeDef     DWord

;WHEA_RAW_DATA_FORMAT Enumeration
WHEA_RAW_DATA_FORMAT                                        TypeDef     DWord
WheaRawDataFormatIPFSalRecord                               Equ         00H
WheaRawDataFormatIA32MCA                                    Equ         01H
WheaRawDataFormatIntel64MCA                                 Equ         02H
WheaRawDataFormatAMD64MCA                                   Equ         03H
WheaRawDataFormatMemory                                     Equ         04H
WheaRawDataFormatPCIExpress                                 Equ         05H
WheaRawDataFormatNMIPort                                    Equ         06H
WheaRawDataFormatPCIXBus                                    Equ         07H
WheaRawDataFormatPCIXDevice                                 Equ         08H
WheaRawDataFormatGeneric                                    Equ         09H
WheaRawDataFormatMax                                        Equ         0AH
PWHEA_RAW_DATA_FORMAT                                       TypeDef     DWord

WHEA_ERROR_PACKET_V1_SIGNATURE                              Equ         A("tPrE")
WHEA_ERROR_PACKET_V1_VERSION                                Equ         2

WHEA_ERROR_PACKET_V2_SIGNATURE                              Equ         A("AEHW")
WHEA_ERROR_PACKET_V2_VERSION                                Equ         3

WHEA_GENERIC_ERROR_DATA_ENTRY Struct
    SectionType                                             GUID        <>
    ErrorSeverity                                           WHEA_ERROR_SEVERITY ?
    Revision                                                WHEA_REVISION   <>
    ValidBits                                               DB          ?
    Flags                                                   DB          ?
    ErrorDataLength                                         DD          ?
    FRUId                                                   GUID        <>
    FRUText                                                 DB          20 Dup(?)
    Data                                                    DB          1 Dup(?)
WHEA_GENERIC_ERROR_DATA_ENTRY EndS
PWHEA_GENERIC_ERROR_DATA_ENTRY                              TypeDef     DWord

INJECT_ERRTYPE_PROCESSOR_CORRECTABLE                        Equ         00000001H
INJECT_ERRTYPE_PROCESSOR_UNCORRECTABLENONFATAL              Equ         00000002H
INJECT_ERRTYPE_PROCESSOR_UNCORRECTABLEFATAL                 Equ         00000004H
INJECT_ERRTYPE_MEMORY_CORRECTABLE                           Equ         00000008H
INJECT_ERRTYPE_MEMORY_UNCORRECTABLENONFATAL                 Equ         00000010H
INJECT_ERRTYPE_MEMORY_UNCORRECTABLEFATAL                    Equ         00000020H
INJECT_ERRTYPE_PCIEXPRESS_CORRECTABLE                       Equ         00000040H
INJECT_ERRTYPE_PCIEXPRESS_UNCORRECTABLENONFATAL             Equ         00000080H
INJECT_ERRTYPE_PCIEXPRESS_UNCORRECTABLEFATAL                Equ         00000100H
INJECT_ERRTYPE_PLATFORM_CORRECTABLE                         Equ         00000200H
INJECT_ERRTYPE_PLATFORM_UNCORRECTABLENONFATAL               Equ         00000400H
INJECT_ERRTYPE_PLATFORM_UNCORRECTABLEFATAL                  Equ         00000800H

WHEA_PSHED_PLUGIN_CALLBACKS Struct
    GetAllErrorSources                                      DD          ?   ;PSHED_PI_GET_ALL_ERROR_SOURCES
    Reserved                                                PVOID       ?
    GetErrorSourceInfo                                      DD          ?   ;PSHED_PI_GET_ERROR_SOURCE_INFO
    SetErrorSourceInfo                                      DD          ?   ;PSHED_PI_SET_ERROR_SOURCE_INFO
    EnableErrorSource                                       DD          ?   ;PSHED_PI_ENABLE_ERROR_SOURCE
    DisableErrorSource                                      DD          ?   ;PSHED_PI_DISABLE_ERROR_SOURCE
    WriteErrorRecord                                        DD          ?   ;PSHED_PI_WRITE_ERROR_RECORD
    ReadErrorRecord                                         DD          ?   ;PSHED_PI_READ_ERROR_RECORD
    ClearErrorRecord                                        DD          ?   ;PSHED_PI_CLEAR_ERROR_RECORD
    RetrieveErrorInfo                                       DD          ?   ;PSHED_PI_RETRIEVE_ERROR_INFO
    FinalizeErrorRecord                                     DD          ?   ;PSHED_PI_FINALIZE_ERROR_RECORD
    ClearErrorStatus                                        DD          ?   ;PSHED_PI_CLEAR_ERROR_STATUS
    AttemptRecovery                                         DD          ?   ;PSHED_PI_ATTEMPT_ERROR_RECOVERY
    GetInjectionCapabilities                                DD          ?   ;PSHED_PI_GET_INJECTION_CAPABILITIES
    InjectError                                             DD          ?   ;PSHED_PI_INJECT_ERROR
WHEA_PSHED_PLUGIN_CALLBACKS EndS
PWHEA_PSHED_PLUGIN_CALLBACKS                                TypeDef     DWord

WHEA_PSHED_PLUGIN_REGISTRATION_PACKET Struct
    _Length                                                 DD          ?   ;Length
    Version                                                 DD          ?
    Context                                                 PVOID       ?
    FunctionalAreaMask                                      DD          ?
    Reserved                                                DD          ?
    Callbacks                                               WHEA_PSHED_PLUGIN_CALLBACKS <>
WHEA_PSHED_PLUGIN_REGISTRATION_PACKET EndS
PWHEA_PSHED_PLUGIN_REGISTRATION_PACKET                      TypeDef     DWord

WHEA_PLUGIN_REGISTRATION_PACKET_VERSION                     Equ         00010000H

PshedFADiscovery                                            Equ         00000001H
PshedFAErrorSourceControl                                   Equ         00000002H
PshedFAErrorRecordPersistence                               Equ         00000004H
PshedFAErrorInfoRetrieval                                   Equ         00000008H
PshedFAErrorRecovery                                        Equ         00000010H
PshedFAErrorInjection                                       Equ         00000020H

WHEA_WRITE_FLAG_DUMMY                                       Equ         00000001H

ENDIF ;DDKMASM_INC
