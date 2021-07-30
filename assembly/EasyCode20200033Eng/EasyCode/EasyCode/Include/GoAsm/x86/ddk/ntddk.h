;===========================================================;
;                                                           ;
;      ntddk.h for Easy Code 2.0 GoAsm 32-bit drivers       ;
;                     (version 1.0.2)                       ;
;                                                           ;
;             Driver Development Kit (32-bit)               ;
;                                                           ;
;           Copyright © Ramon Sala - 2015-2017              ;
;                                                           ;
;===========================================================;

#IFNDEF NTDDK_H
#Define NTDDK_H 1

NTDDK_INCLUDED                                              Equ         1
DDK_DRIVER                                                  Equ         1

#Include macrodrv.h
#Include bugcodes.h
#Include ntiologc.h
#Include ntdef.h
#Include ntstatus.h

#IFNDEF NTDDK
    NO_INTERLOCKED_INTRINSICS                               Equ         1
#ENDIF

NTDDK                                                       Equ         1
STRSAFE_USE_SECURE_CRT                                      Equ         0

#IFNDEF WIN64
    KADDRESS_BASE                                           Equ         0
    UADDRESS_BASE                                           Equ         0
#ENDIF

#Define                                                     PsGetCurrentProcess IoGetCurrentProcess

PASSIVE_LEVEL                                               Equ         0
LOW_LEVEL                                                   Equ         0
APC_LEVEL                                                   Equ         1
DISPATCH_LEVEL                                              Equ         2
CMCI_LEVEL                                                  Equ         5

PROFILE_LEVEL                                               Equ         27
CLOCK1_LEVEL                                                Equ         28
CLOCK2_LEVEL                                                Equ         28
IPI_LEVEL                                                   Equ         29
POWER_LEVEL                                                 Equ         30
HIGH_LEVEL                                                  Equ         31

#Define                                                     CLOCK_LEVEL CLOCK2_LEVEL

LOW_PRIORITY                                                Equ         0
LOW_REALTIME_PRIORITY                                       Equ         16
HIGH_PRIORITY                                               Equ         31
MAXIMUM_PRIORITY                                            Equ         32

MAXIMUM_WAIT_OBJECTS                                        Equ         64

#Define                                                     MAXIMUM_SUSPEND_COUNT MAXCHAR

KSYSTEM_TIME Struct
    LowPart                                                 DD
    High1Time                                               DD
    High2Time                                               DD
EndS

LOCK_QUEUE_WAIT                                             Equ         1
LOCK_QUEUE_WAIT_BIT                                         Equ         0

LOCK_QUEUE_OWNER                                            Equ         2
LOCK_QUEUE_OWNER_BIT                                        Equ         1

;KSPIN_LOCK_QUEUE_NUMBER Enumeration
#IFDEF WIN64
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
#ELSE
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
#ENDIF

#IFNDEF CLFS_MAX_CONTAINER_INFO
    CLFS_MAX_CONTAINER_INFO                                 Equ         256
#ENDIF

KSPIN_LOCK_QUEUE Struct
    Next                                                    DD
    Lock                                                    DD
EndS

KLOCK_QUEUE_HANDLE Struct
    LockQueue                                               KSPIN_LOCK_QUEUE
    OldIrql                                                 DB
EndS

;KPROFILE_SOURCE Enumeration
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
    Low                                                     DQ
    High                                                    DQ
EndS

XSAVE_FORMAT Struct
    ControlWord                                             DW
    StatusWord                                              DW
    TagWord                                                 DB
    Reserved1                                               DB
    ErrorOpcode                                             DW
    ErrorOffset                                             DD
    ErrorSelector                                           DW
    Reserved2                                               DW
    DataOffset                                              DD
    DataSelector                                            DW
    Reserved3                                               DW
    MxCsr                                                   DD
    MxCsr_Mask                                              DD
    FloatRegisters                                          M128A       8 Dup ?
    #IFDEF WIN64
        XmmRegisters                                        M128A       16 Dup ?
        Reserved4                                           DB          96 Dup ?
    #ELSE
        XmmRegisters                                        M128A       8 Dup ?
        Reserved4                                           DB          192 Dup ?
        StackControl                                        DD          7 Dup ?
        Cr0NpxState                                         DD
    #ENDIF
EndS

XSAVE_AREA_HEADER Struct
    Mask                                                    DQ
    Reserved                                                DQ          7 Dup ?
EndS

XSAVE_AREA Struct
    LegacyState                                             XSAVE_FORMAT
    Header                                                  XSAVE_AREA_HEADER
EndS

XSTATE_CONTEXT Struct
    Mask                                                    DQ
    Length                                                  DD
    Reserved1                                               DD
    Area                                                    DD
    #IFDEF X86
        Reserved2                                           DD
    #ENDIF
    Buffer                                                  DD
    #IFDEF X86
        Reserved3                                           DD
    #ENDIF
EndS

XSAVE_ALIGN                                                 Equ         64
MINIMAL_XSTATE_AREA_LENGTH                                  Equ         SizeOf XSAVE_AREA

CONTEXT_CHUNK Struct
    Offset                                                  DD
    Length                                                  DD
EndS

CONTEXT_EX Struct
    All                                                     CONTEXT_CHUNK
    Legacy                                                  CONTEXT_CHUNK
    XState                                                  CONTEXT_CHUNK
EndS

MAXIMUM_SUPPORTED_EXTENSION                                 Equ         512

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
    GenericRead                                             DD
    GenericWrite                                            DD
    GenericExecute                                          DD
    GenericAll                                              DD
EndS

LUID_AND_ATTRIBUTES Struct
    Luid                                                    LUID
    Attributes                                              DD
EndS

ACL_REVISION                                                Equ         (2)
ACL_REVISION_DS                                             Equ         (4)

ACL_REVISION1                                               Equ         (1)
MIN_ACL_REVISION                                            Equ         ACL_REVISION2
ACL_REVISION2                                               Equ         (2)
ACL_REVISION3                                               Equ         (3)
ACL_REVISION4                                               Equ         (4)
MAX_ACL_REVISION                                            Equ         ACL_REVISION4

ACL Struct
    AclRevision                                             DB
    Sbz1                                                    DB
    AclSize                                                 DW
    AceCount                                                DW
    Sbz2                                                    DW
EndS

SECURITY_DESCRIPTOR_REVISION                                Equ         (1)
SECURITY_DESCRIPTOR_REVISION1                               Equ         (1)

SE_PRIVILEGE_ENABLED_BY_DEFAULT                             Equ         (00000001H)
SE_PRIVILEGE_ENABLED                                        Equ         (00000002H)
SE_PRIVILEGE_REMOVED                                        Equ         (00000004H)
SE_PRIVILEGE_USED_FOR_ACCESS                                Equ         (80000000H)

SE_PRIVILEGE_VALID_ATTRIBUTES                               Equ         (SE_PRIVILEGE_ENABLED_BY_DEFAULT | SE_PRIVILEGE_ENABLED | SE_PRIVILEGE_REMOVED | SE_PRIVILEGE_USED_FOR_ACCESS)

PRIVILEGE_SET_ALL_NECESSARY                                 Equ         (1)

PRIVILEGE_SET Struct
    PrivilegeCount                                          DD
    Control                                                 DD
    Privilege                                               LUID_AND_ATTRIBUTES ANYSIZE_ARRAY Dup ?
EndS

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
SecurityAnonymous                                           Equ         0
SecurityIdentification                                      Equ         1
SecurityImpersonation                                       Equ         2
SecurityDelegation                                          Equ         3

SECURITY_MAX_IMPERSONATION_LEVEL                            Equ         SecurityDelegation
SECURITY_MIN_IMPERSONATION_LEVEL                            Equ         SecurityAnonymous
DEFAULT_IMPERSONATION_LEVEL                                 Equ         SecurityImpersonation

SECURITY_DYNAMIC_TRACKING                                   Equ         TRUE
SECURITY_STATIC_TRACKING                                    Equ         FALSE

SECURITY_QUALITY_OF_SERVICE Struct
    Length                                                  DD
    ImpersonationLevel                                      DD
    ContextTrackingMode                                     DB
    EffectiveOnly                                           DB
EndS

SE_IMPERSONATION_STATE Struct
    Token                                                   DD
    CopyOnOpen                                              DB
    EffectiveOnly                                           DB
    Level                                                   DD
EndS

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

#Define                                                     UOW         GUID

SE_ADT_OBJECT_TYPE Struct
    ObjectType                                              GUID
    Flags                                                   DW
    SE_ADT_OBJECT_ONLY                                      Equ         01H
    Level                                                   DW
    AccessMask                                              DD
EndS

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

SE_ADT_PARAMETER_ARRAY Struct
    CategoryId                                              DD
    AuditId                                                 DD
    ParameterCount                                          DD
    Length                                                  DD
    FlatSubCategoryId                                       DW
    Type                                                    DW
    Flags                                                   DD
    Parameters                                              SE_ADT_PARAMETER_ARRAY_ENTRY SE_MAX_AUDIT_PARAMETERS Dup ?
EndS

SE_ADT_PARAMETERS_SELF_RELATIVE                             Equ         00000001H
SE_ADT_PARAMETERS_SEND_TO_LSA                               Equ         00000002H
SE_ADT_PARAMETER_EXTENSIBLE_AUDIT                           Equ         00000004H
SE_ADT_PARAMETER_GENERIC_AUDIT                              Equ         00000008H
SE_ADT_PARAMETER_WRITE_SYNCHRONOUS                          Equ         00000010H

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

FILE_ALL_ACCESS                                             Equ         (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 01FFH)

FILE_GENERIC_READ                                           Equ         (STANDARD_RIGHTS_READ | FILE_READ_DATA | FILE_READ_ATTRIBUTES | FILE_READ_EA | SYNCHRONIZE)

FILE_GENERIC_WRITE                                          Equ         (STANDARD_RIGHTS_WRITE | FILE_WRITE_DATA | FILE_WRITE_ATTRIBUTES | FILE_WRITE_EA | FILE_APPEND_DATA | SYNCHRONIZE)

FILE_GENERIC_EXECUTE                                        Equ         (STANDARD_RIGHTS_EXECUTE | FILE_READ_ATTRIBUTES | FILE_EXECUTE | SYNCHRONIZE)

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
    Status                                                  DD
    Information                                             DD
EndS

#IFDEF WIN64
    IO_STATUS_BLOCK32 Struct
        Status                                              DD
        Information                                         DD
    EndS
#ENDIF

PIO_APC_ROUTINE_DEFINED                                     Equ         1

;IO_SESSION_EVENT Enumeration
IoSessionEventIgnore                                        Equ         0
IoSessionEventCreated                                       Equ         1
IoSessionEventTerminated                                    Equ         2
IoSessionEventConnected                                     Equ         3
IoSessionEventDisconnected                                  Equ         4
IoSessionEventLogon                                         Equ         5
IoSessionEventLogoff                                        Equ         6
IoSessionEventMax                                           Equ         7

;IO_SESSION_STATE Enumeration
IoSessionStateCreated                                       Equ         1
IoSessionStateInitialized                                   Equ         2
IoSessionStateConnected                                     Equ         3
IoSessionStateDisconnected                                  Equ         4
IoSessionStateDisconnectedLoggedOn                          Equ         5
IoSessionStateLoggedOn                                      Equ         6
IoSessionStateLoggedOff                                     Equ         7
IoSessionStateTerminated                                    Equ         8
IoSessionStateMax                                           Equ         9

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
    SessionId                                               DD
    LocalSession                                            DB
EndS

;FILE_INFORMATION_CLASS Enumeration
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

FILE_BASIC_INFORMATION Struct
    CreationTime                                            LARGE_INTEGER
    LastAccessTime                                          LARGE_INTEGER
    LastWriteTime                                           LARGE_INTEGER
    ChangeTime                                              LARGE_INTEGER
    FileAttributes                                          DD
EndS

FILE_STANDARD_INFORMATION Struct
    AllocationSize                                          LARGE_INTEGER
    EndOfFile                                               LARGE_INTEGER
    NumberOfLinks                                           DD
    DeletePending                                           DB
    Directory                                               DB
EndS


FILE_POSITION_INFORMATION Struct
    CurrentByteOffset                                       LARGE_INTEGER
EndS


FILE_NETWORK_OPEN_INFORMATION Struct
    CreationTime                                            LARGE_INTEGER
    LastAccessTime                                          LARGE_INTEGER
    LastWriteTime                                           LARGE_INTEGER
    ChangeTime                                              LARGE_INTEGER
    AllocationSize                                          LARGE_INTEGER
    EndOfFile                                               LARGE_INTEGER
    FileAttributes                                          DD
EndS

FILE_FULL_EA_INFORMATION Struct
    NextEntryOffset                                         DD
    Flags                                                   DB
    EaNameLength                                            DB
    EaValueLength                                           DW
    EaName                                                  DB          1 Dup ?
EndS

FILE_SFIO_RESERVE_INFORMATION Struct
    RequestsPerPeriod                                       DD
    Period                                                  DD
    RetryFailures                                           DB
    Discardable                                             DB
    RequestSize                                             DD
    NumOutstandingRequests                                  DD
EndS

FILE_SFIO_VOLUME_INFORMATION Struct
    MaximumRequestsPerPeriod                                DD
    MinimumPeriod                                           DD
    MinimumTransferSize                                     DD
EndS

;IO_PRIORITY_HINT Enumeration
IoPriorityVeryLow                                           Equ         0
IoPriorityLow                                               Equ         1
IoPriorityNormal                                            Equ         2
IoPriorityHigh                                              Equ         3
IoPriorityCritical                                          Equ         4
MaxIoPriorityTypes                                          Equ         5

FILE_IO_PRIORITY_HINT_INFORMATION Struct
    PriorityHint                                            DD
EndS

FILE_SKIP_COMPLETION_PORT_ON_SUCCESS                        Equ         01H

FILE_SKIP_SET_EVENT_ON_HANDLE                               Equ         02H

FILE_SKIP_SET_USER_EVENT_ON_FAST_IO                         Equ         04H

FILE_IO_COMPLETION_NOTIFICATION_INFORMATION Struct
    Flags                                                   DD
EndS

FILE_PROCESS_IDS_USING_FILE_INFORMATION Struct
    NumberOfProcessIdsInList                                DD
    ProcessIdList                                           DD          1 Dup ?
EndS

FILE_IS_REMOTE_DEVICE_INFORMATION Struct
    IsRemote                                                DB
EndS

FILE_NUMA_NODE_INFORMATION Struct
    NodeNumber                                              DW
EndS

FILE_IOSTATUSBLOCK_RANGE_INFORMATION Struct
    IoStatusBlockRange                                      DD
    Length                                                  DD
EndS

;FS_INFORMATION_CLASS Enumeration
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

FILE_FS_DEVICE_INFORMATION Struct
    DeviceType                                              DD
    Characteristics                                         DD
EndS

;INTERFACE_TYPE Enumeration
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

;DMA_WIDTH Enumeration
Width8Bits                                                  Equ         0
Width16Bits                                                 Equ         1
Width32Bits                                                 Equ         2
MaximumDmaWidth                                             Equ         3

;DMA_SPEED Enumeration
Compatible                                                  Equ         0
TypeA                                                       Equ         1
TypeB                                                       Equ         2
TypeC                                                       Equ         3
TypeF                                                       Equ         4
MaximumDmaSpeed                                             Equ         5

IO_ERROR_LOG_PACKET Struct
    MajorFunctionCode                                       DB
    RetryCount                                              DB
    DumpDataSize                                            DW
    NumberOfStrings                                         DW
    StringOffset                                            DW
    EventCategory                                           DW
    ErrorCode                                               DD
    UniqueErrorValue                                        DD
    FinalStatus                                             DD
    SequenceNumber                                          DD
    IoControlCode                                           DD
    DeviceOffset                                            LARGE_INTEGER
    DumpData                                                DD          1 Dup ?
EndS

IO_ERROR_LOG_MESSAGE Struct
    Type                                                    DW
    Size                                                    DW
    DriverNameLength                                        DW
    TimeStamp                                               LARGE_INTEGER
    DriverNameOffset                                        DD
    EntryData                                               IO_ERROR_LOG_PACKET
EndS

ERROR_LOG_LIMIT_SIZE                                        Equ         (256-16)

IO_ERROR_LOG_MESSAGE_HEADER_LENGTH                          Equ         (SizeOf IO_ERROR_LOG_MESSAGE - SizeOf IO_ERROR_LOG_PACKET + (SizeOf DW * 40))

ERROR_LOG_MESSAGE_LIMIT_SIZE                                Equ         (ERROR_LOG_LIMIT_SIZE + IO_ERROR_LOG_MESSAGE_HEADER_LENGTH)

#IFDEF WIN64
    PORT_MAXIMUM_MESSAGE_LENGTH                             Equ         512
#ELSE
    PORT_MAXIMUM_MESSAGE_LENGTH                             Equ         256
#ENDIF

KEY_QUERY_VALUE                                             Equ         (0001H)
KEY_SET_VALUE                                               Equ         (0002H)
KEY_CREATE_SUB_KEY                                          Equ         (0004H)
KEY_ENUMERATE_SUB_KEYS                                      Equ         (0008H)
KEY_NOTIFY                                                  Equ         (0010H)
KEY_CREATE_LINK                                             Equ         (0020H)
KEY_WOW64_32KEY                                             Equ         (0200H)
KEY_WOW64_64KEY                                             Equ         (0100H)
KEY_WOW64_RES                                               Equ         (0300H)

KEY_READ                                                    Equ         ((STANDARD_RIGHTS_READ | KEY_QUERY_VALUE | KEY_ENUMERATE_SUB_KEYS | KEY_NOTIFY) & (~SYNCHRONIZE))

KEY_WRITE                                                   Equ         ((STANDARD_RIGHTS_WRITE | KEY_SET_VALUE | KEY_CREATE_SUB_KEY) & (~ SYNCHRONIZE))

KEY_EXECUTE                                                 Equ         ((KEY_READ) & (~SYNCHRONIZE))

KEY_ALL_ACCESS                                              Equ         ((STANDARD_RIGHTS_ALL | KEY_QUERY_VALUE | KEY_SET_VALUE | KEY_CREATE_SUB_KEY | KEY_ENUMERATE_SUB_KEYS | KEY_NOTIFY | KEY_CREATE_LINK) & (~SYNCHRONIZE))

REG_OPTION_RESERVED                                         Equ         (00000000H)

REG_OPTION_NON_VOLATILE                                     Equ         (00000000H)

REG_OPTION_VOLATILE                                         Equ         (00000001H)

REG_OPTION_CREATE_LINK                                      Equ         (00000002H)

REG_OPTION_BACKUP_RESTORE                                   Equ         (00000004H)

REG_OPTION_OPEN_LINK                                        Equ         (00000008H)

REG_LEGAL_OPTION                                            Equ         (REG_OPTION_RESERVED | REG_OPTION_NON_VOLATILE | REG_OPTION_VOLATILE | REG_OPTION_CREATE_LINK | REG_OPTION_BACKUP_RESTORE | REG_OPTION_OPEN_LINK)

REG_OPEN_LEGAL_OPTION                                       Equ         (REG_OPTION_RESERVED | REG_OPTION_BACKUP_RESTORE | REG_OPTION_OPEN_LINK)

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

REG_LEGAL_CHANGE_FILTER                                     Equ         (REG_NOTIFY_CHANGE_NAME | REG_NOTIFY_CHANGE_ATTRIBUTES | REG_NOTIFY_CHANGE_LAST_SET | REG_NOTIFY_CHANGE_SECURITY)

KEY_BASIC_INFORMATION Struct
    LastWriteTime                                           LARGE_INTEGER
    TitleIndex                                              DD
    NameLength                                              DD
    Name                                                    DW          1 Dup ?
EndS

KEY_NODE_INFORMATION Struct
    LastWriteTime                                           LARGE_INTEGER
    TitleIndex                                              DD
    ClassOffset                                             DD
    ClassLength                                             DD
    NameLength                                              DD
    Name                                                    DW          1 Dup ?
EndS

KEY_FULL_INFORMATION Struct
    LastWriteTime                                           LARGE_INTEGER
    TitleIndex                                              DD
    ClassOffset                                             DD
    ClassLength                                             DD
    SubKeys                                                 DD
    MaxNameLen                                              DD
    MaxClassLen                                             DD
    Values                                                  DD
    MaxValueNameLen                                         DD
    MaxValueDataLen                                         DD
    Class                                                   DW          1 Dup ?
EndS

;KEY_INFORMATION_CLASS Enumeration
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
    LastWriteTime                                           LARGE_INTEGER
EndS

KEY_WOW64_FLAGS_INFORMATION Struct
    UserFlags                                               DD
EndS

KEY_HANDLE_TAGS_INFORMATION Struct
    HandleTags                                              DD
EndS

KEY_CONTROL_FLAGS_INFORMATION Struct
    ControlFlags                                            DD
EndS

;KEY_SET_INFORMATION_CLASS Enumeration
KeyWriteTimeInformation                                     Equ         0
KeyWow64FlagsInformation                                    Equ         1
KeyControlFlagsInformation                                  Equ         2
KeySetVirtualizationInformation                             Equ         3
KeySetDebugInformation                                      Equ         4
KeySetHandleTagsInformation                                 Equ         5
MaxKeySetInfoClass                                          Equ         6

KEY_VALUE_BASIC_INFORMATION Struct
    TitleIndex                                              DD
    _Type                                                   DD
    NameLength                                              DD
    Name                                                    DW          1 Dup ?
EndS

KEY_VALUE_FULL_INFORMATION Struct
    TitleIndex                                              DD
    Type                                                    DD
    DataOffset                                              DD
    DataLength                                              DD
    NameLength                                              DD
    Name                                                    DW          1 Dup ?
EndS

KEY_VALUE_PARTIAL_INFORMATION Struct
    TitleIndex                                              DD
    Type                                                    DD
    DataLength                                              DD
    Data                                                    DB          1 Dup ?
EndS

KEY_VALUE_PARTIAL_INFORMATION_ALIGN64 Struct
    Type                                                    DD
    DataLength                                              DD
    Data                                                    DB          1 Dup ?
EndS

KEY_VALUE_ENTRY Struct
    ValueName                                               DD
    DataLength                                              DD
    DataOffset                                              DD
    Type                                                    DD
EndS

;KEY_VALUE_INFORMATION_CLASS Enumeration
KeyValueBasicInformation                                    Equ         0
KeyValueFullInformation                                     Equ         1
KeyValuePartialInformation                                  Equ         2
KeyValueFullInformationAlign64                              Equ         3
KeyValuePartialInformationAlign64                           Equ         4
MaxKeyValueInfoClass                                        Equ         5

#Define                                                     OBJ_NAME_PATH_SEPARATOR L"\"

OBJECT_TYPE_CREATE                                          Equ         (0001H)

OBJECT_TYPE_ALL_ACCESS                                      Equ         (STANDARD_RIGHTS_REQUIRED | 01H)

DIRECTORY_QUERY                                             Equ         (0001H)
DIRECTORY_TRAVERSE                                          Equ         (0002H)
DIRECTORY_CREATE_OBJECT                                     Equ         (0004H)
DIRECTORY_CREATE_SUBDIRECTORY                               Equ         (0008H)

DIRECTORY_ALL_ACCESS                                        Equ         (STANDARD_RIGHTS_REQUIRED | 0FH)

SYMBOLIC_LINK_QUERY                                         Equ         (0001H)

SYMBOLIC_LINK_ALL_ACCESS                                    Equ         (STANDARD_RIGHTS_REQUIRED | 01H)

#IFNDEF UNICODE_STRING
    UNICODE_STRING Struct
        Length                          DW
        MaximumLength                   DW
        Buffer                          DD
    EndS
#ENDIF

OBJECT_NAME_INFORMATION Struct
    Name                                                    UNICODE_STRING
EndS

DUPLICATE_CLOSE_SOURCE                                      Equ         00000001H
DUPLICATE_SAME_ACCESS                                       Equ         00000002H
DUPLICATE_SAME_ATTRIBUTES                                   Equ         00000004H

;SECTION_INHERIT Enumeration
ViewShare                                                   Equ         1
ViewUnmap                                                   Equ         2

SECTION_QUERY                                               Equ         0001H
SECTION_MAP_WRITE                                           Equ         0002H
SECTION_MAP_READ                                            Equ         0004H
SECTION_MAP_EXECUTE                                         Equ         0008H
SECTION_EXTEND_SIZE                                         Equ         0010H
SECTION_MAP_EXECUTE_EXPLICIT                                Equ         0020H

SECTION_ALL_ACCESS                                          Equ         (STANDARD_RIGHTS_REQUIRED | SECTION_QUERY | SECTION_MAP_WRITE | SECTION_MAP_READ | SECTION_MAP_EXECUTE | SECTION_EXTEND_SIZE)

SESSION_QUERY_ACCESS                                        Equ         0001H
SESSION_MODIFY_ACCESS                                       Equ         0002H

SESSION_ALL_ACCESS                                          Equ         (STANDARD_RIGHTS_REQUIRED | SESSION_QUERY_ACCESS | SESSION_MODIFY_ACCESS)

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

#IFDEF WIN64
    MAXIMUM_PROC_PER_GROUP                                  Equ         64
#ELSE
    MAXIMUM_PROC_PER_GROUP                                  Equ         32
#ENDIF

MAXIMUM_PROCESSORS                                          Equ         MAXIMUM_PROC_PER_GROUP

THREAD_TERMINATE                                            Equ         (0001H)
THREAD_SUSPEND_RESUME                                       Equ         (0002H)
THREAD_ALERT                                                Equ         (0004H)
THREAD_GET_CONTEXT                                          Equ         (0008H)
THREAD_SET_CONTEXT                                          Equ         (0010H)
THREAD_SET_INFORMATION                                      Equ         (0020H)
THREAD_SET_LIMITED_INFORMATION                              Equ         (0400H)
THREAD_QUERY_LIMITED_INFORMATION                            Equ         (0800H)

CLIENT_ID Struct
    UniqueProcess                                           DD
    UniqueThread                                            DD
EndS

#Define                                                     NtCurrentProcess (-1)
#Define                                                     ZwCurrentProcess NtCurrentProcess
#Define                                                     NtCurrentThread (-2)
#Define                                                     ZwCurrentThread NtCurrentThread

DEFINE_GUID     (GUID_MAX_POWER_SAVINGS,                                                 0A1841308H, 03541H, 04FABH, 0BCH, 081H, 0F7H, 015H, 056H, 0F2H, 00BH, 04AH)
DEFINE_GUID     (GUID_MIN_POWER_SAVINGS,                                                 08C5E7FDAH, 0E8BFH, 04A96H, 09AH, 085H, 0A6H, 0E2H, 03AH, 08CH, 063H, 05CH)

DEFINE_GUID     (GUID_TYPICAL_POWER_SAVINGS,                                             0381B4222H, 0F694H, 041F0H, 096H, 085H, 0FFH, 05BH, 0B2H, 060H, 0DFH, 02EH)
DEFINE_GUID     (NO_SUBGROUP_GUID,                                                       0FEA3413EH, 07E05H, 04911H, 09AH, 071H, 070H, 003H, 031H, 0F1H, 0C2H, 094H)
DEFINE_GUID     (ALL_POWERSCHEMES_GUID,                                                  068A1E95EH, 013EAH, 041E1H, 080H, 011H, 00CH, 049H, 06CH, 0A4H, 090H, 0B0H)
DEFINE_GUID     (GUID_POWERSCHEME_PERSONALITY,                                           0245D8541H, 03943H, 04422H, 0B0H, 025H, 013H, 0A7H, 084H, 0F6H, 079H, 0B7H)
DEFINE_GUID     (GUID_ACTIVE_POWERSCHEME,                                                031F9F286H, 05084H, 042FEH, 0B7H, 020H, 02BH, 002H, 064H, 099H, 037H, 063H)
DEFINE_GUID     (GUID_VIDEO_SUBGROUP,                                                    07516B95FH, 0F776H, 04464H, 08CH, 053H, 006H, 016H, 07FH, 040H, 0CCH, 099H)
DEFINE_GUID     (GUID_VIDEO_POWERDOWN_TIMEOUT,                                           03C0BC021H, 0C8A8H, 04E07H, 0A9H, 073H, 06BH, 014H, 0CBH, 0CBH, 02BH, 07EH)
DEFINE_GUID     (GUID_VIDEO_ANNOYANCE_TIMEOUT,                                           082DBCF2DH, 0CD67H, 040C5H, 0BFH, 0DCH, 09FH, 01AH, 05CH, 0CDH, 046H, 063H)
DEFINE_GUID     (GUID_VIDEO_ADAPTIVE_PERCENT_INCREASE,                                   0EED904DFH, 0B142H, 04183H, 0B1H, 00BH, 05AH, 011H, 097H, 0A3H, 078H, 064H)
DEFINE_GUID     (GUID_VIDEO_DIM_TIMEOUT,                                                 017AAA29BH, 08B43H, 04B94H, 0AAH, 0FEH, 035H, 0F6H, 04DH, 0AAH, 0F1H, 0EEH)
DEFINE_GUID     (GUID_VIDEO_ADAPTIVE_POWERDOWN,                                          090959D22H, 0D6A1H, 049B9H, 0AFH, 093H, 0BCH, 0E8H, 085H, 0ADH, 033H, 05BH)
DEFINE_GUID     (GUID_MONITOR_POWER_ON,                                                  002731015H, 04510H, 04526H, 099H, 0E6H, 0E5H, 0A1H, 07EH, 0BDH, 01AH, 0EAH)
DEFINE_GUID     (GUID_DEVICE_POWER_POLICY_VIDEO_BRIGHTNESS,                              0ADED5E82H, 0B909H, 04619H, 099H, 049H, 0F5H, 0D7H, 01DH, 0ACH, 00BH, 0CBH)
DEFINE_GUID     (GUID_DEVICE_POWER_POLICY_VIDEO_DIM_BRIGHTNESS,                          0F1FBFDE2H, 0A960H, 04165H, 09FH, 088H, 050H, 066H, 079H, 011H, 0CEH, 096H)
DEFINE_GUID     (GUID_VIDEO_CURRENT_MONITOR_BRIGHTNESS,                                  08FFEE2C6H, 02D01H, 046BEH, 0ADH, 0B9H, 039H, 08AH, 0DDH, 0C5H, 0B4H, 0FFH)
DEFINE_GUID     (GUID_VIDEO_ADAPTIVE_DISPLAY_BRIGHTNESS,                                 0FBD9AA66H, 09553H, 04097H, 0BAH, 044H, 0EDH, 06EH, 09DH, 065H, 0EAH, 0B8H)
DEFINE_GUID     (GUID_SESSION_DISPLAY_STATE,                                             073A5E93AH, 05BB1H, 04F93H, 089H, 05BH, 0DBH, 0D0H, 0DAH, 085H, 059H, 067H)
DEFINE_GUID     (GUID_CONSOLE_DISPLAY_STATE,                                             06FE69556H, 0704AH, 047A0H, 08FH, 024H, 0C2H, 08DH, 093H, 06FH, 0DAH, 047H)
DEFINE_GUID     (GUID_ALLOW_DISPLAY_REQUIRED,                                            0A9CEB8DAH, 0CD46H, 044FBH, 0A9H, 08BH, 002H, 0AFH, 069H, 0DEH, 046H, 023H)
DEFINE_GUID     (GUID_DISK_SUBGROUP,                                                     00012EE47H, 09041H, 04B5DH, 09BH, 077H, 053H, 05FH, 0BAH, 08BH, 014H, 042H)
DEFINE_GUID     (GUID_DISK_POWERDOWN_TIMEOUT,                                            06738E2C4H, 0E8A5H, 04A42H, 0B1H, 06AH, 0E0H, 040H, 0E7H, 069H, 075H, 06EH)
DEFINE_GUID     (GUID_DISK_BURST_IGNORE_THRESHOLD,                                       080E3C60EH, 0BB94H, 04AD8H, 0BBH, 0E0H, 00DH, 031H, 095H, 0EFH, 0C6H, 063H)
DEFINE_GUID     (GUID_DISK_ADAPTIVE_POWERDOWN,                                           0396A32E1H, 0499AH, 040B2H, 091H, 024H, 0A9H, 06AH, 0FEH, 070H, 076H, 067H)
DEFINE_GUID     (GUID_SLEEP_SUBGROUP,                                                    0238C9FA8H, 00AADH, 041EDH, 083H, 0F4H, 097H, 0BEH, 024H, 02CH, 08FH, 020H)
DEFINE_GUID     (GUID_SLEEP_IDLE_THRESHOLD,                                              081CD32E0H, 07833H, 044F3H, 087H, 037H, 070H, 081H, 0F3H, 08DH, 01FH, 070H)
DEFINE_GUID     (GUID_STANDBY_TIMEOUT,                                                   029F6C1DBH, 086DAH, 048C5H, 09FH, 0DBH, 0F2H, 0B6H, 07BH, 01FH, 044H, 0DAH)
DEFINE_GUID     (GUID_UNATTEND_SLEEP_TIMEOUT,                                            07BC4A2F9H, 0D8FCH, 04469H, 0B0H, 07BH, 033H, 0EBH, 078H, 05AH, 0ACH, 0A0H)
DEFINE_GUID     (GUID_HIBERNATE_TIMEOUT,                                                 09D7815A6H, 07EE4H, 0497EH, 088H, 088H, 051H, 05AH, 005H, 0F0H, 023H, 064H)
DEFINE_GUID     (GUID_HIBERNATE_FASTS4_POLICY,                                           094AC6D29H, 073CEH, 041A6H, 080H, 09FH, 063H, 063H, 0BAH, 021H, 0B4H, 07EH)
DEFINE_GUID     (GUID_CRITICAL_POWER_TRANSITION,                                         0B7A27025H, 0E569H, 046c2H, 0A5H, 004H, 02BH, 096H, 0CAH, 0D2H, 025H, 0A1H)
DEFINE_GUID     (GUID_SYSTEM_AWAYMODE,                                                   098A7F580H, 001F7H, 048AAH, 09CH, 00FH, 044H, 035H, 02CH, 029H, 0E5H, 0C0H)
DEFINE_GUID     (GUID_ALLOW_AWAYMODE,                                                    025DFA149H, 05DD1H, 04736H, 0B5H, 0ABH, 0E8H, 0A3H, 07BH, 05BH, 081H, 087H)
DEFINE_GUID     (GUID_ALLOW_STANDBY_STATES,                                              0ABFC2519H, 03608H, 04C2AH, 094H, 0EAH, 017H, 01BH, 00EH, 0D5H, 046H, 0ABH)
DEFINE_GUID     (GUID_ALLOW_RTC_WAKE,                                                    0BD3B718AH, 00680H, 04D9DH, 08AH, 0B2H, 0E1H, 0D2H, 0B4H, 0ACH, 080H, 06DH)
DEFINE_GUID     (GUID_ALLOW_SYSTEM_REQUIRED,                                             0A4B195F5H, 08225H, 047D8H, 080H, 012H, 09DH, 041H, 036H, 097H, 086H, 0E2H)
DEFINE_GUID     (GUID_SYSTEM_BUTTON_SUBGROUP,                                            04F971E89H, 0EEBDH, 04455H, 0A8H, 0DEH, 09EH, 059H, 004H, 00EH, 073H, 047H)
DEFINE_GUID     (GUID_POWERBUTTON_ACTION,                                                07648EFA3H, 0DD9CH, 04E3EH, 0B5H, 066H, 050H, 0F9H, 029H, 038H, 062H, 080H)
DEFINE_GUID     (GUID_POWERBUTTON_ACTION_FLAGS,                                          0857E7FACH, 0034BH, 04704H, 0ABH, 0B1H, 0BCH, 0A5H, 04AH, 0A3H, 014H, 078H)
DEFINE_GUID     (GUID_SLEEPBUTTON_ACTION,                                                096996BC0H, 0AD50H, 047ECH, 092H, 03BH, 06FH, 041H, 087H, 04DH, 0D9H, 0EBH)
DEFINE_GUID     (GUID_SLEEPBUTTON_ACTION_FLAGS,                                          02A160AB1H, 0B69DH, 04743H, 0B7H, 018H, 0BFH, 014H, 041H, 0D5H, 0E4H, 093H)
DEFINE_GUID     (GUID_USERINTERFACEBUTTON_ACTION,                                        0A7066653H, 08D6CH, 040A8H, 091H, 00EH, 0A1H, 0F5H, 04BH, 084H, 0C7H, 0E5H)
DEFINE_GUID     (GUID_LIDCLOSE_ACTION,                                                   05CA83367H, 06E45H, 0459FH, 0A2H, 07BH, 047H, 06BH, 01DH, 001H, 0C9H, 036H)
DEFINE_GUID     (GUID_LIDCLOSE_ACTION_FLAGS,                                             097E969ACH, 00D6CH, 04D08H, 092H, 07CH, 0D7H, 0BDH, 07AH, 0D7H, 085H, 07BH)
DEFINE_GUID     (GUID_LIDOPEN_POWERSTATE,                                                099FF10E7H, 023B1H, 04C07H, 0A9H, 0D1H, 05CH, 032H, 006H, 0D7H, 041H, 0B4H)
DEFINE_GUID     (GUID_BATTERY_SUBGROUP,                                                  0E73A048DH, 0BF27H, 04F12H, 097H, 031H, 08BH, 020H, 076H, 0E8H, 089H, 01FH)
DEFINE_GUID     (GUID_BATTERY_DISCHARGE_ACTION_0,                                        0637EA02FH, 0BBCBH, 04015H, 08EH, 02CH, 0A1H, 0C7H, 0B9H, 0C0H, 0B5H, 046H)
DEFINE_GUID     (GUID_BATTERY_DISCHARGE_LEVEL_0,                                         09A66D8D7H, 04FF7H, 04EF9H, 0B5H, 0A2H, 05AH, 032H, 06CH, 0A2H, 0A4H, 069H)
DEFINE_GUID     (GUID_BATTERY_DISCHARGE_FLAGS_0,                                         05DBB7C9FH, 038E9H, 040D2H, 097H, 049H, 04FH, 08AH, 00EH, 09FH, 064H, 00FH)

DEFINE_GUID     (GUID_BATTERY_DISCHARGE_ACTION_1,                                        0D8742DCBH, 03E6AH, 04B3CH, 0B3H, 0FEH, 037H, 046H, 023H, 0CDH, 0CFH, 006H)
DEFINE_GUID     (GUID_BATTERY_DISCHARGE_LEVEL_1,                                         08183BA9AH, 0E910H, 048DAH, 087H, 069H, 014H, 0AEH, 06DH, 0C1H, 017H, 00AH)
DEFINE_GUID     (GUID_BATTERY_DISCHARGE_FLAGS_1,                                         0BCDED951H, 0187BH, 04D05H, 0BCH, 0CCH, 0F7H, 0E5H, 019H, 060H, 0C2H, 058H)

DEFINE_GUID     (GUID_BATTERY_DISCHARGE_ACTION_2,                                        0421CBA38H, 01A8EH, 04881H, 0ACH, 089H, 0E3H, 03AH, 08BH, 004H, 0ECH, 0E4H)
DEFINE_GUID     (GUID_BATTERY_DISCHARGE_LEVEL_2,                                         007A07CA2H, 0ADAFH, 040D7H, 0B0H, 077H, 053H, 03AH, 0ADH, 0EDH, 01BH, 0FAH)
DEFINE_GUID     (GUID_BATTERY_DISCHARGE_FLAGS_2,                                         07FD2F0C4H, 0FEB7H, 04DA3H, 081H, 017H, 0E3H, 0FBH, 0EDH, 0C4H, 065H, 082H)

DEFINE_GUID     (GUID_BATTERY_DISCHARGE_ACTION_3,                                        080472613H, 09780H, 0455EH, 0B3H, 008H, 072H, 0D3H, 000H, 03CH, 0F2H, 0F8H)
DEFINE_GUID     (GUID_BATTERY_DISCHARGE_LEVEL_3,                                         058AFD5A6H, 0C2DDH, 047D2H, 09FH, 0BFH, 0EFH, 070H, 0CCH, 05CH, 059H, 065H)
DEFINE_GUID     (GUID_BATTERY_DISCHARGE_FLAGS_3,                                         073613CCFH, 0DBFAH, 04279H, 083H, 056H, 049H, 035H, 0f6H, 0bfH, 062H, 0f3H)

DEFINE_GUID     (GUID_PROCESSOR_SETTINGS_SUBGROUP,                                       054533251H, 082BEH, 04824H, 096H, 0C1H, 047H, 0B6H, 00BH, 074H, 00DH, 000H)
DEFINE_GUID     (GUID_PROCESSOR_THROTTLE_POLICY,                                         057027304H, 04AF6H, 04104H, 092H, 060H, 0E3H, 0D9H, 052H, 048H, 0FCH, 036H)

PERFSTATE_POLICY_CHANGE_IDEAL                               Equ         0
PERFSTATE_POLICY_CHANGE_SINGLE                              Equ         1
PERFSTATE_POLICY_CHANGE_ROCKET                              Equ         2
PERFSTATE_POLICY_CHANGE_MAX                                 Equ         PERFSTATE_POLICY_CHANGE_ROCKET

DEFINE_GUID     (GUID_PROCESSOR_THROTTLE_MAXIMUM,                                        0BC5038F7H, 023E0H, 04960H, 096H, 0DAH, 033H, 0ABH, 0AFH, 059H, 035H, 0ECH)
DEFINE_GUID     (GUID_PROCESSOR_THROTTLE_MINIMUM,                                        0893DEE8EH, 02BEFH, 041E0H, 089H, 0C6H, 0B5H, 05DH, 009H, 029H, 096H, 04CH)
DEFINE_GUID     (GUID_PROCESSOR_ALLOW_THROTTLING,                                        03B04D4FDH, 01CC7H, 04F23H, 0ABH, 01CH, 0D1H, 033H, 078H, 019H, 0C4H, 0BBH)
DEFINE_GUID     (GUID_PROCESSOR_IDLESTATE_POLICY,                                        068F262A7H, 0F621H, 04069H, 0B9H, 0A5H, 048H, 074H, 016H, 09BH, 0E2H, 03CH)
DEFINE_GUID     (GUID_PROCESSOR_PERFSTATE_POLICY,                                        0BBDC3814H, 018E9H, 04463H, 08AH, 055H, 0D1H, 097H, 032H, 07CH, 045H, 0C0H)
DEFINE_GUID     (GUID_PROCESSOR_PERF_INCREASE_THRESHOLD,                                 006CADF0EH, 064EDH, 0448AH, 089H, 027H, 0CEH, 07BH, 0F9H, 00EH, 0B3H, 05DH)
DEFINE_GUID     (GUID_PROCESSOR_PERF_DECREASE_THRESHOLD,                                 012A0AB44H, 0FE28H, 04FA9H, 0B3H, 0BDH, 04BH, 064H, 0F4H, 049H, 060H, 0A6H)
DEFINE_GUID     (GUID_PROCESSOR_PERF_INCREASE_POLICY,                                    0465E1F50H, 0B610H, 0473AH, 0ABH, 058H, 000H, 0D1H, 007H, 07DH, 0C4H, 018H)
DEFINE_GUID     (GUID_PROCESSOR_PERF_DECREASE_POLICY,                                    040FBEFC7H, 02E9DH, 04D25H, 0A1H, 085H, 00CH, 0FDH, 085H, 074H, 0BAH, 0C6H)
DEFINE_GUID     (GUID_PROCESSOR_PERF_INCREASE_TIME,                                      0984CF492H, 03BEDH, 04488H, 0A8H, 0F9H, 042H, 086H, 0C9H, 07BH, 0F5H, 0AAH)
DEFINE_GUID     (GUID_PROCESSOR_PERF_DECREASE_TIME,                                      0D8EDEB9BH, 095CFH, 04F95H, 0A7H, 03CH, 0B0H, 061H, 097H, 036H, 093H, 0C8H)
DEFINE_GUID     (GUID_PROCESSOR_PERF_TIME_CHECK,                                         04D2B0152H, 07D5CH, 0498BH, 088H, 0E2H, 034H, 034H, 053H, 092H, 0A2H, 0C5H)
DEFINE_GUID     (GUID_PROCESSOR_PERF_BOOST_POLICY,                                       045BCC044H, 0D885H, 043E2H, 086H, 005H, 0EEH, 00EH, 0C6H, 0E9H, 06BH, 059H)

PROCESSOR_PERF_BOOST_POLICY_DISABLED                        Equ         0
PROCESSOR_PERF_BOOST_POLICY_MAX                             Equ         100

DEFINE_GUID     (GUID_PROCESSOR_IDLE_ALLOW_SCALING,                                      06C2993B0H, 08F48H, 0481FH, 0BCH, 0C6H, 000H, 0DDH, 027H, 042H, 0AAH, 006H)
DEFINE_GUID     (GUID_PROCESSOR_IDLE_DISABLE,                                            05D76A2CAH, 0E8C0H, 0402FH, 0A1H, 033H, 021H, 058H, 049H, 02DH, 058H, 0ADH)
DEFINE_GUID     (GUID_PROCESSOR_IDLE_TIME_CHECK,                                         0C4581C31H, 089ABH, 04597H, 08EH, 02BH, 09CH, 09CH, 0ABH, 044H, 00EH, 06BH)
DEFINE_GUID     (GUID_PROCESSOR_IDLE_DEMOTE_THRESHOLD,                                   04B92D758H, 05A24H, 04851H, 0A4H, 070H, 081H, 05DH, 078H, 0AEH, 0E1H, 019H)
DEFINE_GUID     (GUID_PROCESSOR_IDLE_PROMOTE_THRESHOLD,                                  07B224883H, 0b3CCH, 04D79H, 081H, 09FH, 083H, 074H, 015H, 02CH, 0BEH, 07CH)
DEFINE_GUID     (GUID_PROCESSOR_CORE_PARKING_INCREASE_THRESHOLD,                         0DF142941H, 020F3H, 04EDfH, 09AH, 04AH, 09CH, 083H, 0D3H, 0D7H, 017H, 0D1H)
DEFINE_GUID     (GUID_PROCESSOR_CORE_PARKING_DECREASE_THRESHOLD,                         068DD2F27H, 0A4CEH, 04E11H, 084H, 087H, 037H, 094H, 0E4H, 013H, 05DH, 0FAH)
DEFINE_GUID     (GUID_PROCESSOR_CORE_PARKING_INCREASE_POLICY,                            0C7BE0679H, 02817H, 04D69H, 09DH, 002H, 051H, 09AH, 053H, 07EH, 0D0H, 0C6H)

CORE_PARKING_POLICY_CHANGE_IDEAL                            Equ         0
CORE_PARKING_POLICY_CHANGE_SINGLE                           Equ         1
CORE_PARKING_POLICY_CHANGE_ROCKET                           Equ         2
CORE_PARKING_POLICY_CHANGE_MAX                              Equ         CORE_PARKING_POLICY_CHANGE_ROCKET

DEFINE_GUID     (GUID_PROCESSOR_CORE_PARKING_DECREASE_POLICY,                            071021B41H, 0C749H, 04D21H, 0BEH, 074H, 0A0H, 00FH, 033H, 05DH, 058H, 02BH)
DEFINE_GUID     (GUID_PROCESSOR_CORE_PARKING_MAX_CORES,                                  0EA062031H, 00E34H, 04FF1H, 09BH, 06DH, 0EBH, 010H, 059H, 033H, 040H, 028H)
DEFINE_GUID     (GUID_PROCESSOR_CORE_PARKING_MIN_CORES,                                  00CC5B647H, 0C1DFH, 04637H, 089H, 01AH, 0DEH, 0C3H, 05CH, 031H, 085H, 083H)
DEFINE_GUID     (GUID_PROCESSOR_CORE_PARKING_INCREASE_TIME,                              02DDD5A84H, 05A71H, 0437EH, 091H, 02AH, 0DBH, 00BH, 08CH, 078H, 087H, 032H)
DEFINE_GUID     (GUID_PROCESSOR_CORE_PARKING_DECREASE_TIME,                              0DFD10D17H, 0D5EBH, 045DDH, 087H, 07AH, 09AH, 034H, 0DDH, 0D1H, 05CH, 082H)
DEFINE_GUID     (GUID_PROCESSOR_CORE_PARKING_AFFINITY_HISTORY_DECREASE_FACTOR,           08F7B45E3H, 0C393H, 0480AH, 087H, 08CH, 0F6H, 07AH, 0C3H, 0D0H, 070H, 082H)
DEFINE_GUID     (GUID_PROCESSOR_CORE_PARKING_AFFINITY_HISTORY_THRESHOLD,                 05B33697BH, 0E89DH, 04D38H, 0AAH, 046H, 09EH, 07DH, 0FBH, 07CH, 0D2H, 0F9H)
DEFINE_GUID     (GUID_PROCESSOR_CORE_PARKING_AFFINITY_WEIGHTING,                         0E70867F1H, 0FA2FH, 04F4EH, 0AEH, 0A1H, 04DH, 08AH, 00BH, 0A2H, 03BH, 020H)
DEFINE_GUID     (GUID_PROCESSOR_CORE_PARKING_OVER_UTILIZATION_HISTORY_DECREASE_FACTOR,   01299023CH, 0BC28H, 04F0AH, 081H, 0ECH, 0D3H, 029H, 05AH, 08DH, 081H, 05DH)
DEFINE_GUID     (GUID_PROCESSOR_CORE_PARKING_OVER_UTILIZATION_HISTORY_THRESHOLD,         09AC18E92H, 0AA3CH, 04E27H, 0B3H, 007H, 001H, 0AEH, 037H, 030H, 071H, 029H)
DEFINE_GUID     (GUID_PROCESSOR_CORE_PARKING_OVER_UTILIZATION_WEIGHTING,                 08809C2D8H, 0B155H, 042D4H, 0BCH, 0DAH, 00DH, 034H, 056H, 051H, 0B1H, 0DBH)
DEFINE_GUID     (GUID_PROCESSOR_CORE_PARKING_OVER_UTILIZATION_THRESHOLD,                 0943C8CB6H, 06F93H, 04227H, 0ADH, 087H, 0E9H, 0A3H, 0FEH, 0ECH, 008H, 0D1H)
DEFINE_GUID     (GUID_PROCESSOR_PARKING_CORE_OVERRIDE,                                   0A55612AAH, 0F624H, 042C6H, 0A4H, 043H, 073H, 097H, 0D0H, 064H, 0C0H, 04FH)
DEFINE_GUID     (GUID_PROCESSOR_PARKING_PERF_STATE,                                      0447235C7H, 06A8DH, 04CC0H, 08EH, 024H, 09EH, 0AFH, 070H, 0B9H, 06EH, 02BH)
DEFINE_GUID     (GUID_PROCESSOR_PERF_HISTORY,                                            07D24BAA7H, 00B84H, 0480FH, 084H, 00CH, 01BH, 007H, 043H, 0C0H, 00FH, 05FH)
DEFINE_GUID     (GUID_SYSTEM_COOLING_POLICY,                                             094D3A615H, 0A899H, 04AC5H, 0AEH, 02BH, 0E4H, 0D8H, 0F6H, 034H, 036H, 07FH)
DEFINE_GUID     (GUID_LOCK_CONSOLE_ON_WAKE,                                              00E796BDBH, 0100DH, 047D6H, 0A2H, 0D5H, 0F7H, 0D2H, 0DAH, 0A5H, 01FH, 051H)
DEFINE_GUID     (GUID_DEVICE_IDLE_POLICY,                                                04FAAB71AH, 092E5H, 04726H, 0B5H, 031H, 022H, 045H, 059H, 067H, 02DH, 019H)

POWER_DEVICE_IDLE_POLICY_PERFORMANCE                        Equ         0
POWER_DEVICE_IDLE_POLICY_CONSERVATIVE                       Equ         1

DEFINE_GUID     (GUID_ACDC_POWER_SOURCE,                                                 05D3E9A59H, 0E9D5H, 04B00H, 0A6H, 0BDH, 0FFH, 034H, 0FFH, 051H, 065H, 048H)
DEFINE_GUID     (GUID_LIDSWITCH_STATE_CHANGE,                                            0BA3E0F4DH, 0B817H, 04094H, 0A2H, 0D1H, 0D5H, 063H, 079H, 0E6H, 0A0H, 0F3H)
DEFINE_GUID     (GUID_BATTERY_PERCENTAGE_REMAINING,                                      0A7AD8041H, 0B45AH, 04CAEH, 087H, 0A3H, 0EEH, 0CBH, 0B4H, 068H, 0A9H, 0E1H)
DEFINE_GUID     (GUID_IDLE_BACKGROUND_TASK,                                              0515C31D8H, 0F734H, 0163DH, 0A0H, 0FDH, 011H, 0A0H, 08CH, 091H, 0E8H, 0F1H)
DEFINE_GUID     (GUID_BACKGROUND_TASK_NOTIFICATION,                                      0CF23F240H, 02A54H, 048D8H, 0B1H, 014H, 0DEH, 015H, 018H, 0FFH, 005H, 02EH)
DEFINE_GUID     (GUID_APPLAUNCH_BUTTON,                                                  01A689231H, 07399H, 04E9AH, 08FH, 099H, 0B7H, 01FH, 099H, 09DH, 0B3H, 0FAH)
DEFINE_GUID     (GUID_PCIEXPRESS_SETTINGS_SUBGROUP,                                      0501A4D13H, 042AFH, 04429H, 09FH, 0D1H, 0A8H, 021H, 08CH, 026H, 08EH, 020H)
DEFINE_GUID     (GUID_PCIEXPRESS_ASPM_POLICY,                                            0EE12F906H, 0D277H, 0404BH, 0B6H, 0DAH, 0E5H, 0FAH, 01AH, 057H, 06DH, 0F5H)
DEFINE_GUID     (GUID_ENABLE_SWITCH_FORCED_SHUTDOWN,                                     0833A6B62H, 0DFA4H, 046D1H, 082H, 0F8H, 0E0H, 09EH, 034H, 0D0H, 029H, 0D6H)

;SYSTEM_POWER_STATE Enumeration
PowerSystemUnspecified                                      Equ         0
PowerSystemWorking                                          Equ         1
PowerSystemSleeping1                                        Equ         2
PowerSystemSleeping2                                        Equ         3
PowerSystemSleeping3                                        Equ         4
PowerSystemHibernate                                        Equ         5
PowerSystemShutdown                                         Equ         6
PowerSystemMaximum                                          Equ         7

POWER_SYSTEM_MAXIMUM                                        Equ         7

;POWER_ACTION Enumeration
PowerActionNone                                             Equ         0
PowerActionReserved                                         Equ         1
PowerActionSleep                                            Equ         2
PowerActionHibernate                                        Equ         3
PowerActionShutdown                                         Equ         4
PowerActionShutdownReset                                    Equ         5
PowerActionShutdownOff                                      Equ         6
PowerActionWarmEject                                        Equ         7

;DEVICE_POWER_STATE Enumeration
PowerDeviceUnspecified                                      Equ         0
PowerDeviceD0                                               Equ         1
PowerDeviceD1                                               Equ         2
PowerDeviceD2                                               Equ         3
PowerDeviceD3                                               Equ         4
PowerDeviceMaximum                                          Equ         5

;MONITOR_DISPLAY_STATE Enumeration
PowerMonitorOff                                             Equ         0
PowerMonitorOn                                              Equ         1
PowerMonitorDim                                             Equ         2

POWER_STATE Union
    SystemState                                             DD
    DeviceState                                             DD
EndUnion

;POWER_STATE_TYPE Enumeration
SystemPowerState                                            Equ         0
DevicePowerState                                            Equ         1

IOCTL_QUERY_DEVICE_POWER_STATE                              Equ         CTL_CODE(FILE_DEVICE_BATTERY, 00H, METHOD_BUFFERED, FILE_READ_ACCESS)

IOCTL_SET_DEVICE_WAKE                                       Equ         CTL_CODE(FILE_DEVICE_BATTERY, 01H, METHOD_BUFFERED, FILE_WRITE_ACCESS)

IOCTL_CANCEL_DEVICE_WAKE                                    Equ         CTL_CODE(FILE_DEVICE_BATTERY, 02H, METHOD_BUFFERED, FILE_WRITE_ACCESS)

ES_SYSTEM_REQUIRED                                          Equ         (000000001H)
ES_DISPLAY_REQUIRED                                         Equ         (000000002H)
ES_USER_PRESENT                                             Equ         (000000004H)
ES_AWAYMODE_REQUIRED                                        Equ         (000000040H)
ES_CONTINUOUS                                               Equ         (080000000H)

;LATENCY_TIME Enumeration
LT_DONT_CARE                                                Equ         0
LT_LOWEST_LATENCY                                           Equ         1

DIAGNOSTIC_REASON_VERSION                                   Equ         0

DIAGNOSTIC_REASON_SIMPLE_STRING                             Equ         000000001H
DIAGNOSTIC_REASON_DETAILED_STRING                           Equ         000000002H
DIAGNOSTIC_REASON_NOT_SPECIFIED                             Equ         080000000H
DIAGNOSTIC_REASON_INVALID_FLAGS                             Equ         (~080000003H)

POWER_REQUEST_CONTEXT_VERSION                               Equ         0

POWER_REQUEST_CONTEXT_SIMPLE_STRING                         Equ         000000001H
POWER_REQUEST_CONTEXT_DETAILED_STRING                       Equ         000000002H

;POWER_REQUEST_TYPE Enumeration
PowerRequestDisplayRequired                                 Equ         0
PowerRequestSystemRequired                                  Equ         1
PowerRequestAwayModeRequired                                Equ         2

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
    PD_Size                                                 DD
    PD_MostRecentPowerState                                 DD
    PD_Capabilities                                         DD
    PD_D1Latency                                            DD
    PD_D2Latency                                            DD
    PD_D3Latency                                            DD
    PD_PowerStateMapping                                    DD          POWER_SYSTEM_MAXIMUM Dup ?
    PD_DeepestSystemWake                                    DD
EndS

;POWER_INFORMATION_LEVEL Enumeration
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
PoAc                                                        Equ         0
PoDc                                                        Equ         1
PoHot                                                       Equ         2
PoConditionMaximum                                          Equ         3

SET_POWER_SETTING_VALUE Struct
    Version                                                 DD
    Guid                                                    GUID
    PowerCondition                                          DD
    DataLength                                              DD
    Data                                                    DB          ANYSIZE_ARRAY Dup ?
EndS

POWER_SETTING_VALUE_VERSION                                 Equ         (01H)

NOTIFY_USER_POWER_SETTING Struct
    Guid                                                    GUID
EndS

APPLICATIONLAUNCH_SETTING_VALUE Struct
    ActivationTime                                          LARGE_INTEGER
    Flags                                                   DD
    ButtonInstanceID                                        DD
EndS

;POWER_PLATFORM_ROLE Enumeration
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
    Granularity                                             DD
    Capacity                                                DD
EndS

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

SERVICE_DRIVER                                              Equ         (SERVICE_KERNEL_DRIVER | SERVICE_FILE_SYSTEM_DRIVER | SERVICE_RECOGNIZER_DRIVER)

SERVICE_WIN32_OWN_PROCESS                                   Equ         00000010H
SERVICE_WIN32_SHARE_PROCESS                                 Equ         00000020H
SERVICE_WIN32                                               Equ         (SERVICE_WIN32_OWN_PROCESS | SERVICE_WIN32_SHARE_PROCESS)

SERVICE_INTERACTIVE_PROCESS                                 Equ         00000100H

SERVICE_TYPE_ALL                                            Equ         (SERVICE_WIN32 | SERVICE_ADAPTER | SERVICE_DRIVER | SERVICE_INTERACTIVE_PROCESS)

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
DriverType                                                  Equ         SERVICE_KERNEL_DRIVER
FileSystemType                                              Equ         SERVICE_FILE_SYSTEM_DRIVER
Win32ServiceOwnProcess                                      Equ         SERVICE_WIN32_OWN_PROCESS
Win32ServiceShareProcess                                    Equ         SERVICE_WIN32_SHARE_PROCESS
AdapterType                                                 Equ         SERVICE_ADAPTER
RecognizerType                                              Equ         SERVICE_RECOGNIZER_DRIVER

;SERVICE_LOAD_TYPE Enumeration
BootLoad                                                    Equ         SERVICE_BOOT_START,
SystemLoad                                                  Equ         SERVICE_SYSTEM_START
AutoLoad                                                    Equ         SERVICE_AUTO_START
DemandLoad                                                  Equ         SERVICE_DEMAND_START
DisableLoad                                                 Equ         SERVICE_DISABLED

;SERVICE_ERROR_TYPE Enumeration
IgnoreError                                                 Equ         SERVICE_ERROR_IGNORE
NormalError                                                 Equ         SERVICE_ERROR_NORMAL
SevereError                                                 Equ         SERVICE_ERROR_SEVERE
CriticalError                                               Equ         SERVICE_ERROR_CRITICAL

CM_SERVICE_NETWORK_BOOT_LOAD                                Equ         00000001H
CM_SERVICE_VIRTUAL_DISK_BOOT_LOAD                           Equ         00000002H
CM_SERVICE_USB_DISK_BOOT_LOAD                               Equ         00000004H

CM_SERVICE_VALID_PROMOTION_MASK                             Equ         (CM_SERVICE_NETWORK_BOOT_LOAD | CM_SERVICE_VIRTUAL_DISK_BOOT_LOAD | CM_SERVICE_USB_DISK_BOOT_LOAD)

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
    Type                                                    DB
    ShareDisposition                                        DB
    Flags                                                   DW
    u Union
        Generic Struct
            Start                                           PHYSICAL_ADDRESS
            Length                                          DD
        EndS
        Port Struct
            Start                                           PHYSICAL_ADDRESS
            Length                                          DD
        EndS
        Interrupt Struct
            Level                                           DW
            Group                                           DW
            Vector                                          DD
            Affinity                                        DD
        EndS
        MessageInterrupt Struct
            DUMMYUNIONNAME Union
               Raw Struct
                   Group                                    DW
                   MessageCount                             DW
                   Vector                                   DD
                   Affinity                                 DD
               EndS
               Translated Struct
                   Level                                    DW
                   Group                                    DW
                   Vector                                   DD
                   Affinity                                 DD
               EndS
            EndUnion
        EndS
        Memory Struct
            Start                                           PHYSICAL_ADDRESS
            Length                                          DD
        EndS
        Dma Struct
            Channel                                         DD
            Port                                            DD
            Reserved1                                       DD
        EndS
        DevicePrivate Struct
            Data                                            DD          3 Dup ?
        EndS
        BusNumber Struct
            Start                                           DD
            Length                                          DD
            Reserved                                        DD
        EndS
        DeviceSpecificData Struct
            DataSize                                        DD
            Reserved1                                       DD
            Reserved2                                       DD
        EndS
        Memory40 Struct
            Start                                           PHYSICAL_ADDRESS
            Length40                                        DD
        EndS
        Memory48 Struct
            Start                                           PHYSICAL_ADDRESS
            Length48                                        DD
        EndS
        Memory64 Struct
            Start                                           PHYSICAL_ADDRESS
            Length64                                        DD
        EndS
    EndUnion
EndS

CM_PARTIAL_RESOURCE_LIST Struct
    Version                                                 DW
    Revision                                                DW
    Count                                                   DD
    PartialDescriptors                                      CM_PARTIAL_RESOURCE_DESCRIPTOR  1 Dup ?
EndS

CM_FULL_RESOURCE_DESCRIPTOR Struct
    InterfaceType                                           DD
    BusNumber                                               DD
    PartialResourceList                                     CM_PARTIAL_RESOURCE_LIST
EndS

CM_RESOURCE_LIST Struct
    Count                                                   DD
    List                                                    CM_FULL_RESOURCE_DESCRIPTOR 1 Dup ?
EndS

CM_ROM_BLOCK Struct
    Address                                                 DD
    Size                                                    DD
EndS

CM_INT13_DRIVE_PARAMETER Struct
    DriveSelect                                             DW
    MaxCylinders                                            DD
    SectorsPerTrack                                         DW
    MaxHeads                                                DW
    NumberDrives                                            DW
EndS

CM_MCA_POS_DATA Struct
    AdapterId                                               DW
    PosData1                                                DB
    PosData2                                                DB
    PosData3                                                DB
    PosData4                                                DB
EndS

CM_EISA_SLOT_INFORMATION Struct
    ReturnCode                                              DB
    ReturnFlags                                             DB
    MajorRevision                                           DB
    MinorRevision                                           DB
    Checksum                                                DW
    NumberFunctions                                         DB
    FunctionInformation                                     DB
    CompressedId                                            DD
EndS

CM_PNP_BIOS_DEVICE_NODE Struct
    Size                                                    DW
    Node                                                    DB
    ProductId                                               DD
    DeviceType                                              DB          3 Dup ?
    DeviceAttributes                                        DW
EndS

CM_PNP_BIOS_INSTALLATION_CHECK Struct
    Signature                                               DB          4 Dup ?
    Revision                                                DB
    Length                                                  DB
    ControlField                                            DW
    Checksum                                                DB
    EventFlagAddress                                        DD
    RealModeEntryOffset                                     DW
    RealModeEntrySegment                                    DW
    ProtectedModeEntryOffset                                DW
    ProtectedModeCodeBaseAddress                            DD
    OemDeviceId                                             DD
    RealModeDataBaseAddress                                 DW
    ProtectedModeDataBaseAddress                            DD
EndS

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
    Version                                                 DW
    Revision                                                DW
    HostIdentifier                                          DB
EndS

CM_VIDEO_DEVICE_DATA Struct
    Version                                                 DW
    Revision                                                DW
    VideoClock                                              DD
EndS

CM_SONIC_DEVICE_DATA Struct
    Version                                                 DW
    Revision                                                DW
    DataConfigurationRegister                               DW
    EthernetAddress                                         DB          8 Dup ?
EndS

CM_SERIAL_DEVICE_DATA Struct
    Version                                                 DW
    Revision                                                DW
    BaudClock                                               DD
EndS

CM_MONITOR_DEVICE_DATA Struct
    Version                                                 DW
    Revision                                                DW
    HorizontalScreenSize                                    DW
    VerticalScreenSize                                      DW
    HorizontalResolution                                    DW
    VerticalResolution                                      DW
    HorizontalDisplayTimeLow                                DW
    HorizontalDisplayTime                                   DW
    HorizontalDisplayTimeHigh                               DW
    HorizontalBackPorchLow                                  DW
    HorizontalBackPorch                                     DW
    HorizontalBackPorchHigh                                 DW
    HorizontalFrontPorchLow                                 DW
    HorizontalFrontPorch                                    DW
    HorizontalFrontPorchHigh                                DW
    HorizontalSyncLow                                       DW
    HorizontalSync                                          DW
    HorizontalSyncHigh                                      DW
    VerticalBackPorchLow                                    DW
    VerticalBackPorch                                       DW
    VerticalBackPorchHigh                                   DW
    VerticalFrontPorchLow                                   DW
    VerticalFrontPorch                                      DW
    VerticalFrontPorchHigh                                  DW
    VerticalSyncLow                                         DW
    VerticalSync                                            DW
    VerticalSyncHigh                                        DW
EndS

CM_FLOPPY_DEVICE_DATA Struct
    Version                                                 DW
    Revision                                                DW
    Size                                                    DB          8 Dup ?
    MaxDensity                                              DD
    MountDensity                                            DD
    StepRateHeadUnloadTime                                  DB
    HeadLoadTime                                            DB
    MotorOffTime                                            DB
    SectorLengthCode                                        DB
    SectorPerTrack                                          DB
    ReadWriteGapLength                                      DB
    DataTransferLength                                      DB
    FormatGapLength                                         DB
    FormatFillCharacter                                     DB
    HeadSettleTime                                          DB
    MotorSettleTime                                         DB
    MaximumTrackValue                                       DB
    DataTransferRate                                        DB
EndS

CM_KEYBOARD_DEVICE_DATA Struct
    Version                                                 DW
    Revision                                                DW
    Type                                                    DB
    Subtype                                                 DB
    KeyboardFlags                                           DW
EndS

CM_DISK_GEOMETRY_DEVICE_DATA Struct
    BytesPerSector                                          DD
    NumberOfCylinders                                       DD
    SectorsPerTrack                                         DD
    NumberOfHeads                                           DD
EndS

IO_RESOURCE_PREFERRED                                       Equ         001H
IO_RESOURCE_DEFAULT                                         Equ         002H
IO_RESOURCE_ALTERNATIVE                                     Equ         008H

;IRQ_DEVICE_POLICY Enumeration
IrqPolicyMachineDefault                                     Equ         0
IrqPolicyAllCloseProcessors                                 Equ         1
IrqPolicyOneCloseProcessor                                  Equ         2
IrqPolicyAllProcessorsInMachine                             Equ         3
IrqPolicyAllProcessorsInGroup                               Equ         3
IrqPolicySpecifiedProcessors                                Equ         4
IrqPolicySpreadMessagesAcrossAllProcessors                  Equ         5

;IRQ_PRIORITY Enumeration
IrqPriorityUndefined                                        Equ         0
IrqPriorityLow                                              Equ         1
IrqPriorityNormal                                           Equ         2
IrqPriorityHigh                                             Equ         3

;IRQ_GROUP_POLICY Enumeration
GroupAffinityAllGroupZero                                   Equ         0
GroupAffinityDontCare                                       Equ         1

IO_RESOURCE_DESCRIPTOR Struct
    Option                                                  DB
    Type                                                    DB
    ShareDisposition                                        DB
    Spare1                                                  DB
    Flags                                                   DW
    Spare2                                                  DW
    u Union
        Port Struct
            Length                                          DD
            Alignment                                       DD
            MinimumAddress                                  PHYSICAL_ADDRESS
            MaximumAddress                                  PHYSICAL_ADDRESS
        EndS
        Memory Struct
            Length                                          DD
            Alignment                                       DD
            MinimumAddress                                  PHYSICAL_ADDRESS
            MaximumAddress                                  PHYSICAL_ADDRESS
        EndS
        Interrupt Struct
            MinimumVector                                   DD
            MaximumVector                                   DD
            AffinityPolicy                                  DW
            Group                                           DW
            PriorityPolicy                                  DD
            TargetedProcessors                              DD
        EndS
        Dma Struct
            MinimumChannel                                  DD
            MaximumChannel                                  DD
        EndS
        Generic Struct
            Length                                          DD
            Alignment                                       DD
            MinimumAddress                                  PHYSICAL_ADDRESS
            MaximumAddress                                  PHYSICAL_ADDRESS
        EndS
        DevicePrivate Struct
            Data                                            DD          3 Dup ?
        EndS
        BusNumber Struct
            Length                                          DD
            MinBusNumber                                    DD
            MaxBusNumber                                    DD
            Reserved                                        DD
        EndS
        ConfigData Struct
            Priority                                        DD
            Reserved1                                       DD
            Reserved2                                       DD
        EndS
        Memory40 Struct
            Length40                                        DD
            Alignment40                                     DD
            MinimumAddress                                  PHYSICAL_ADDRESS
            MaximumAddress                                  PHYSICAL_ADDRESS
        EndS
        Memory48 Struct
            Length48                                        DD
            Alignment48                                     DD
            MinimumAddress                                  PHYSICAL_ADDRESS
            MaximumAddress                                  PHYSICAL_ADDRESS
        EndS
        Memory64 Struct
            Length64                                        DD
            Alignment64                                     DD
            MinimumAddress                                  PHYSICAL_ADDRESS
            MaximumAddress                                  PHYSICAL_ADDRESS
        EndS
    EndUnion
EndS

IO_RESOURCE_LIST Struct
    Version                                                 DW
    Revision                                                DW
    Count                                                   DD
    Descriptors                                             IO_RESOURCE_DESCRIPTOR 1 Dup ?
EndS

IO_RESOURCE_REQUIREMENTS_LIST Struct
    ListSize                                                DD
    InterfaceType                                           DD
    BusNumber                                               DD
    SlotNumber                                              DD
    Reserved                                                DD          3 Dup ?
    AlternativeLists                                        DD
    List                                                    IO_RESOURCE_LIST 1 Dup ?
EndS

#IFDEF WIN64
    SLIST_ENTRY Struct
        Next                                                DD
    EndS

    SLIST_ENTRY32 Struct
        Next                                                DD
    EndS
#ELSE
    #Define                                                 SLIST_ENTRY SINGLE_LIST_ENTRY
    #Define                                                 SLIST_ENTRY32 SLIST_ENTRY
#ENDIF

SLIST_HEADER Struct
    Alignment                                               DQ
    DUMMYSTRUCTNAME Struct
        Next                                                SLIST_ENTRY
        Depth                                               DW
        Sequence                                            DW
    EndS
EndS
#Define                                                     SLIST_HEADER32 SLIST_HEADER

RTL_QUERY_REGISTRY_TABLE Struct
    QueryRoutine                                            DD
    Flags                                                   DD
    Name                                                    DD
    EntryContext                                            DD
    DefaultType                                             DD
    DefaultData                                             DD
    DefaultLength                                           DD
EndS

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
    Year                                                    DW
    Month                                                   DW
    Day                                                     DW
    Hour                                                    DW
    Minute                                                  DW
    Second                                                  DW
    Milliseconds                                            DW
    Weekday                                                 DW
EndS

SHORT_LEAST_SIGNIFICANT_BIT                                 Equ         0
SHORT_MOST_SIGNIFICANT_BIT                                  Equ         1

LONG_LEAST_SIGNIFICANT_BIT                                  Equ         0
LONG_3RD_MOST_SIGNIFICANT_BIT                               Equ         1
LONG_2ND_MOST_SIGNIFICANT_BIT                               Equ         2
LONG_MOST_SIGNIFICANT_BIT                                   Equ         3

RTL_BITMAP Struct
    SizeOfBitMap                                            DD
    Buffer                                                  DD
EndS

RTL_BITMAP_RUN Struct
    StartingIndex                                           DD
    NumberOfBits                                            DD
EndS

TRANSACTIONMANAGER_QUERY_INFORMATION                        Equ         (0001H)
TRANSACTIONMANAGER_SET_INFORMATION                          Equ         (0002H)
TRANSACTIONMANAGER_RECOVER                                  Equ         (0004H)
TRANSACTIONMANAGER_RENAME                                   Equ         (0008H)
TRANSACTIONMANAGER_CREATE_RM                                Equ         (0010H)

TRANSACTIONMANAGER_GENERIC_READ                             Equ         (STANDARD_RIGHTS_READ | TRANSACTIONMANAGER_QUERY_INFORMATION)
TRANSACTIONMANAGER_GENERIC_WRITE                            Equ         (STANDARD_RIGHTS_WRITE | TRANSACTIONMANAGER_SET_INFORMATION | TRANSACTIONMANAGER_RECOVER | TRANSACTIONMANAGER_RENAME | TRANSACTIONMANAGER_CREATE_RM)
TRANSACTIONMANAGER_GENERIC_EXECUTE                          Equ         (STANDARD_RIGHTS_EXECUTE)
TRANSACTIONMANAGER_ALL_ACCESS                               Equ         (STANDARD_RIGHTS_REQUIRED | TRANSACTIONMANAGER_GENERIC_READ | TRANSACTIONMANAGER_GENERIC_WRITE | TRANSACTIONMANAGER_GENERIC_EXECUTE | TRANSACTIONMANAGER_BIND_TRANSACTION)

TRANSACTION_QUERY_INFORMATION                               Equ         (0001H)
TRANSACTION_SET_INFORMATION                                 Equ         (0002H)
TRANSACTION_ENLIST                                          Equ         (0004H)
TRANSACTION_COMMIT                                          Equ         (0008H)
TRANSACTION_ROLLBACK                                        Equ         (0010H)
TRANSACTION_PROPAGATE                                       Equ         (0020H)
TRANSACTION_RIGHT_RESERVED1                                 Equ         (0040H)

TRANSACTION_GENERIC_READ                                    Equ         (STANDARD_RIGHTS_READ | TRANSACTION_QUERY_INFORMATION | SYNCHRONIZE)
TRANSACTION_GENERIC_WRITE                                   Equ         (STANDARD_RIGHTS_WRITE | TRANSACTION_SET_INFORMATION | TRANSACTION_COMMIT | TRANSACTION_ENLIST | TRANSACTION_ROLLBACK | TRANSACTION_PROPAGATE | SYNCHRONIZE)
TRANSACTION_GENERIC_EXECUTE                                 Equ         (STANDARD_RIGHTS_EXECUTE | TRANSACTION_COMMIT | TRANSACTION_ROLLBACK | SYNCHRONIZE)
TRANSACTION_ALL_ACCESS                                      Equ         (STANDARD_RIGHTS_REQUIRED | TRANSACTION_GENERIC_READ | TRANSACTION_GENERIC_WRITE | TRANSACTION_GENERIC_EXECUTE)
TRANSACTION_RESOURCE_MANAGER_RIGHTS                         Equ         (TRANSACTION_GENERIC_READ | STANDARD_RIGHTS_WRITE | TRANSACTION_SET_INFORMATION | TRANSACTION_ENLIST | TRANSACTION_ROLLBACK | TRANSACTION_PROPAGATE | SYNCHRONIZE)

RESOURCEMANAGER_QUERY_INFORMATION                           Equ         (0001H)
RESOURCEMANAGER_SET_INFORMATION                             Equ         (0002H)
RESOURCEMANAGER_RECOVER                                     Equ         (0004H)
RESOURCEMANAGER_ENLIST                                      Equ         (0008H)
RESOURCEMANAGER_GET_NOTIFICATION                            Equ         (0010H)
RESOURCEMANAGER_REGISTER_PROTOCOL                           Equ         (0020H)
RESOURCEMANAGER_COMPLETE_PROPAGATION                        Equ         (0040H)

RESOURCEMANAGER_GENERIC_READ                                Equ         (STANDARD_RIGHTS_READ | RESOURCEMANAGER_QUERY_INFORMATION | SYNCHRONIZE)
RESOURCEMANAGER_GENERIC_WRITE                               Equ         (STANDARD_RIGHTS_WRITE | RESOURCEMANAGER_SET_INFORMATION | RESOURCEMANAGER_RECOVER | RESOURCEMANAGER_ENLIST | RESOURCEMANAGER_GET_NOTIFICATION | RESOURCEMANAGER_REGISTER_PROTOCOL | RESOURCEMANAGER_COMPLETE_PROPAGATION | SYNCHRONIZE)
RESOURCEMANAGER_GENERIC_EXECUTE                             Equ         (STANDARD_RIGHTS_EXECUTE | RESOURCEMANAGER_RECOVER | RESOURCEMANAGER_ENLIST | RESOURCEMANAGER_GET_NOTIFICATION | RESOURCEMANAGER_COMPLETE_PROPAGATION | SYNCHRONIZE)
RESOURCEMANAGER_ALL_ACCESS                                  Equ         (STANDARD_RIGHTS_REQUIRED | RESOURCEMANAGER_GENERIC_READ | RESOURCEMANAGER_GENERIC_WRITE | RESOURCEMANAGER_GENERIC_EXECUTE)

ENLISTMENT_QUERY_INFORMATION                                Equ         (0001H)
ENLISTMENT_SET_INFORMATION                                  Equ         (0002H)
ENLISTMENT_RECOVER                                          Equ         (0004H)
ENLISTMENT_SUBORDINATE_RIGHTS                               Equ         (0008H)
ENLISTMENT_SUPERIOR_RIGHTS                                  Equ         (0010H)

ENLISTMENT_GENERIC_READ                                     Equ         (STANDARD_RIGHTS_READ | ENLISTMENT_QUERY_INFORMATION)
ENLISTMENT_GENERIC_WRITE                                    Equ         (STANDARD_RIGHTS_WRITE | ENLISTMENT_SET_INFORMATION | ENLISTMENT_RECOVER | ENLISTMENT_SUBORDINATE_RIGHTS | ENLISTMENT_SUPERIOR_RIGHTS)
ENLISTMENT_GENERIC_EXECUTE                                  Equ         (STANDARD_RIGHTS_EXECUTE | ENLISTMENT_RECOVER | ENLISTMENT_SUBORDINATE_RIGHTS | ENLISTMENT_SUPERIOR_RIGHTS)
ENLISTMENT_ALL_ACCESS                                       Equ         (STANDARD_RIGHTS_REQUIRED | ENLISTMENT_GENERIC_READ | ENLISTMENT_GENERIC_WRITE | ENLISTMENT_GENERIC_EXECUTE)

;TRANSACTION_OUTCOME Enumeration
TransactionOutcomeUndetermined                              Equ         1
TransactionOutcomeCommitted                                 Equ         2
TransactionOutcomeAborted                                   Equ         3

;TRANSACTION_STATE Enumeration
TransactionStateNormal                                      Equ         1
TransactionStateIndoubt                                     Equ         2
TransactionStateCommittedNotify                             Equ         3

TRANSACTION_BASIC_INFORMATION Struct
    TransactionId                                           GUID
    State                                                   DD
    Outcome                                                 DD
EndS

TRANSACTIONMANAGER_BASIC_INFORMATION Struct
    TmIdentity                                              GUID
    VirtualClock                                            LARGE_INTEGER
EndS

TRANSACTIONMANAGER_LOG_INFORMATION Struct
    LogIdentity                                             GUID
EndS

TRANSACTIONMANAGER_RECOVERY_INFORMATION Struct
    LastRecoveredLsn                                        DQ
EndS

TRANSACTION_PROPERTIES_INFORMATION Struct
    IsolationLevel                                          DD
    IsolationFlags                                          DD
    Timeout                                                 LARGE_INTEGER
    Outcome                                                 DD
    DescriptionLength                                       DD
    Description                                             DW          1 Dup ?
EndS

TRANSACTION_BIND_INFORMATION Struct
    TmHandle                                                DD
EndS

TRANSACTION_ENLISTMENT_PAIR Struct
    EnlistmentId                                            GUID
    ResourceManagerId                                       GUID
EndS

TRANSACTION_ENLISTMENTS_INFORMATION Struct
    NumberOfEnlistments                                     DD
    EnlistmentPair                                          TRANSACTION_ENLISTMENT_PAIR 1 Dup ?
EndS

TRANSACTION_SUPERIOR_ENLISTMENT_INFORMATION Struct
    SuperiorEnlistmentPair                                  TRANSACTION_ENLISTMENT_PAIR
EndS

RESOURCEMANAGER_BASIC_INFORMATION Struct
    ResourceManagerId                                       GUID
    DescriptionLength                                       DD
    Description                                             DW          1 Dup ?
EndS

RESOURCEMANAGER_COMPLETION_INFORMATION Struct
    IoCompletionPortHandle                                  DD
    CompletionKey                                           DD
EndS

;TRANSACTION_INFORMATION_CLASS Enumeration
TransactionBasicInformation                                 Equ         0
TransactionPropertiesInformation                            Equ         1
TransactionEnlistmentInformation                            Equ         2
TransactionSuperiorEnlistmentInformation                    Equ         3

;TRANSACTIONMANAGER_INFORMATION_CLASS Enumeration
TransactionManagerBasicInformation                          Equ         0
TransactionManagerLogInformation                            Equ         1
TransactionManagerLogPathInformation                        Equ         2
TransactionManagerRecoveryInformation                       Equ         4

;RESOURCEMANAGER_INFORMATION_CLASS Enumeration
ResourceManagerBasicInformation                             Equ         0
ResourceManagerCompletionInformation                        Equ         1

ENLISTMENT_BASIC_INFORMATION Struct
    EnlistmentId                                            GUID
    TransactionId                                           GUID
    ResourceManagerId                                       GUID
EndS

ENLISTMENT_CRM_INFORMATION Struct
    CrmTransactionManagerId                                 GUID
    CrmResourceManagerId                                    GUID
    CrmEnlistmentId                                         GUID
EndS

;ENLISTMENT_INFORMATION_CLASS Enumeration
EnlistmentBasicInformation                                  Equ         0
EnlistmentRecoveryInformation                               Equ         1
EnlistmentCrmInformation                                    Equ         2

TRANSACTION_LIST_ENTRY Struct
    Uow                                                     UOW
EndS

TRANSACTION_LIST_INFORMATION Struct
    NumberOfTransactions                                    DD
    TransactionInformation                                  TRANSACTION_LIST_ENTRY  1 Dup ?
EndS

;KTMOBJECT_TYPE Enumeration
KTMOBJECT_TRANSACTION                                       Equ         0
KTMOBJECT_TRANSACTION_MANAGER                               Equ         1
KTMOBJECT_RESOURCE_MANAGER                                  Equ         2
KTMOBJECT_ENLISTMENT                                        Equ         3
KTMOBJECT_INVALID                                           Equ         4

KTMOBJECT_CURSOR Struct
    LastQuery                                               GUID
    ObjectIdCount                                           DD
    ObjectIds                                               GUID        1 Dup ?
EndS

KAPC Struct
    Type                                                    DB
    SpareByte0                                              DB
    Size                                                    DB
    SpareByte1                                              DB
    SpareLong0                                              DD
    Thread                                                  DD
    ApcListEntry                                            LIST_ENTRY
    KernelRoutine                                           DD
    RundownRoutine                                          DD
    NormalRoutine                                           DD
    NormalContext                                           DD
    SystemArgument1                                         DD
    SystemArgument2                                         DD
    ApcStateIndex                                           DB
    ApcMode                                                 DB
    Inserted                                                DB
EndS

;KDPC_IMPORTANCE Enumeration
LowImportance                                               Equ         0
MediumImportance                                            Equ         1
HighImportance                                              Equ         2
MediumHighImportance                                        Equ         3

DPC_NORMAL                                                  Equ         0
DPC_THREADED                                                Equ         1

KDPC Struct
    Type                                                    DB
    Importance                                              DB
    Number                                                  DW
    DpcListEntry                                            LIST_ENTRY
    DeferredRoutine                                         DD
    DeferredContext                                         DD
    SystemArgument1                                         DD
    SystemArgument2                                         DD
    DpcData                                                 DD
EndS

KIPI_COUNTS Struct
    Freeze                                                  DD
    Packet                                                  DD
    DPC                                                     DD
    APC                                                     DD
    FlushSingleTb                                           DD
    FlushMultipleTb                                         DD
    FlushEntireTb                                           DD
    GenericCall                                             DD
    ChangeColor                                             DD
    SweepDcache                                             DD
    SweepIcache                                             DD
    SweepIcacheRange                                        DD
    FlushIoBuffers                                          DD
    GratuitousDPC                                           DD
EndS

MDL Struct
    Next                                                    DD
    Size                                                    DW
    MdlFlags                                                DW
    Process                                                 DD
    MappedSystemVa                                          DD
    StartVa                                                 DD
    ByteCount                                               DD
    ByteOffset                                              DD
EndS

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

MDL_MAPPING_FLAGS                                           Equ         (MDL_MAPPED_TO_SYSTEM_VA | MDL_PAGES_LOCKED | MDL_SOURCE_IS_NONPAGED_POOL | MDL_PARTIAL_HAS_BEEN_MAPPED | MDL_PARENT_MAPPED_SYSTEM_VA | MDL_SYSTEM_VA | MDL_IO_SPACE)

TIMER_EXPIRED_INDEX_BITS                                    Equ         6
TIMER_PROCESSOR_INDEX_BITS                                  Equ         5

;LOCK_OPERATION Enumeration
IoReadAccess                                                Equ         0
IoWriteAccess                                               Equ         1
IoModifyAccess                                              Equ         2

FLUSH_MULTIPLE_MAXIMUM                                      Equ         32

KFLOATING_SAVE Struct
    ControlWord                                             DD
    StatusWord                                              DD
    ErrorOffset                                             DD
    ErrorSelector                                           DD
    DataOffset                                              DD
    DataSelector                                            DD
    Cr0NpxState                                             DD
    Spare1                                                  DD
EndS

;INTEL_CACHE_TYPE Enumeration
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
EFLAG_SELECT                                                Equ         (EFLAG_SIGN | EFLAG_ZERO)

PAGE_SHIFT                                                  Equ         12

MAXIMUM_VECTOR                                              Equ         256

EVENT_QUERY_STATE                                           Equ         0001H
EVENT_MODIFY_STATE                                          Equ         0002H
EVENT_ALL_ACCESS                                            Equ         (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 03H) 

SEMAPHORE_QUERY_STATE                                       Equ         0001H
SEMAPHORE_MODIFY_STATE                                      Equ         0002H
SEMAPHORE_ALL_ACCESS                                        Equ         (STANDARD_RIGHTS_REQUIRED | SYNCHRONIZE | 03H)

;LOGICAL_PROCESSOR_RELATIONSHIP Enumeration
RelationProcessorCore                                       Equ         0
RelationNumaNode                                            Equ         1
RelationCache                                               Equ         2
RelationProcessorPackage                                    Equ         3
RelationGroup                                               Equ         4
RelationAll                                                 Equ         0FFFFH

LTP_PC_SMT                                                  Equ         01H

;PROCESSOR_CACHE_TYPE Enumeration
CacheUnified                                                Equ         0
CacheInstruction                                            Equ         1
CacheData                                                   Equ         2
CacheTrace                                                  Equ         3

CACHE_FULLY_ASSOCIATIVE                                     Equ         0FFH

CACHE_DESCRIPTOR Struct
    Level                                                   DB
    Associativity                                           DB
    LineSize                                                DW
    Size                                                    DD
    Type                                                    DD
EndS

SYSTEM_LOGICAL_PROCESSOR_INFORMATION Struct
    ProcessorMask                                           DD
    Relationship                                            DD
    DUMMYUNIONNAME Union
        ProcessorCore Struct
            Flags                                           DB
        EndS
        NumaNode Struct
            NodeNumber                                      DD
        EndS
        Cache                                               CACHE_DESCRIPTOR
        Reserved                                            DQ          2 Dup ?
    EndUnion
EndS

PROCESSOR_RELATIONSHIP Struct
    Flags                                                   DB
    Reserved                                                DB          21 Dup ?
    GroupCount                                              DW
    GroupMask                                               GROUP_AFFINITY ANYSIZE_ARRAY Dup ?
EndS

NUMA_NODE_RELATIONSHIP Struct
    NodeNumber                                              DD
    Reserved                                                DB          20 Dup ?
    GroupMask                                               GROUP_AFFINITY
EndS

CACHE_RELATIONSHIP Struct
    Level                                                   DB
    Associativity                                           DB
    LineSize                                                DW
    CacheSize                                               DD
    Type                                                    DD
    Reserved                                                DB          20 Dup ? 
    GroupMask                                               GROUP_AFFINITY
EndS

PROCESSOR_GROUP_INFO Struct
    MaximumProcessorCount                                   DB
    ActiveProcessorCount                                    DB
    Reserved                                                DB          38 Dup ?
    ActiveProcessorMask                                     DD
EndS

GROUP_RELATIONSHIP Struct
    MaximumGroupCount                                       DW
    ActiveGroupCount                                        DW
    Reserved                                                DB          20 Dup ?
    GroupInfo                                               PROCESSOR_GROUP_INFO ANYSIZE_ARRAY Dup ?
EndS

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
StandardDesign                                              Equ         0
NEC98x86                                                    Equ         1
EndAlternatives                                             Equ         2

PROCESSOR_FEATURE_MAX                                       Equ         64

EXCEPTION_NONCONTINUABLE                                    Equ         01H

#IFNDEF EXCEPTION_MAXIMUM_PARAMETERS
    EXCEPTION_MAXIMUM_PARAMETERS                            Equ         15
#ENDIF

SIZE_OF_80387_REGISTERS                                     Equ         80

FLOATING_SAVE_AREA Struct
    ControlWord                                             DD
    StatusWord                                              DD
    TagWord                                                 DD
    ErrorOffset                                             DD
    ErrorSelector                                           DD
    DataOffset                                              DD
    DataSelector                                            DD
    RegisterArea                                            DB          SIZE_OF_80387_REGISTERS Dup ?
    Cr0NpxState                                             DD
EndS

CONTEXT Struct
    ContextFlags                                            DD
    _Dr0                                                    DD
    _Dr1                                                    DD
    _Dr2                                                    DD
    _Dr3                                                    DD
    _Dr6                                                    DD
    _Dr7                                                    DD
    FloatSave                                               FLOATING_SAVE_AREA
    SegGs                                                   DD
    SegFs                                                   DD
    SegEs                                                   DD
    SegDs                                                   DD
    _Edi                                                    DD
    _Esi                                                    DD
    _Ebx                                                    DD
    _Edx                                                    DD
    _Ecx                                                    DD
    _Eax                                                    DD
    _Ebp                                                    DD
    _Eip                                                    DD
    SegCs                                                   DD
    EFlags                                                  DD
    _Esp                                                    DD
    SegSs                                                   DD
    ExtendedRegisters                                       DB          MAXIMUM_SUPPORTED_EXTENSION Dup ?
Ends

EXCEPTION_RECORD Struct
    ExceptionCode                                           DD
    ExceptionFlags                                          DD
    ExceptionRecord                                         DD
    ExceptionAddress                                        DD
    NumberParameters                                        DD
    ExceptionInformation                                    DD          EXCEPTION_MAXIMUM_PARAMETERS Dup ?
EndS

EXCEPTION_RECORD32 Struct
    ExceptionCode                                           DD
    ExceptionFlags                                          DD
    ExceptionRecord                                         DD
    ExceptionAddress                                        DD
    NumberParameters                                        DD
    ExceptionInformation                                    DD          EXCEPTION_MAXIMUM_PARAMETERS Dup ?
EndS

EXCEPTION_RECORD64 Struct
    ExceptionCode                                           DD
    ExceptionFlags                                          DD
    ExceptionRecord                                         DQ
    ExceptionAddress                                        DQ
    NumberParameters                                        DD
    __unusedAlignment                                       DD
    ExceptionInformation                                    DQ          EXCEPTION_MAXIMUM_PARAMETERS Dup ?
EndS

EXCEPTION_POINTERS Struct
    ExceptionRecord                                         DD
    ContextRecord                                           DD
EndS

THREAD_WAIT_OBJECTS                                         Equ         3

;KINTERRUPT_MODE Enumeration
LevelSensitive                                              Equ         0
Latched                                                     Equ         1

;KINTERRUPT_POLARITY Enumeration
InterruptPolarityUnknown                                    Equ         0
InterruptActiveHigh                                         Equ         1
InterruptActiveLow                                          Equ         2

;KWAIT_REASON Enumeration
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
    WaitListEntry                                           LIST_ENTRY
    Thread                                                  DD
    Object                                                  DD
    NextWaitBlock                                           DD
    WaitKey                                                 DW
    WaitType                                                DB
    BlockState                                              DB
    #IFDEF WIN64
        SpareLong                                           DD
    #ENDIF
EndS

KDEVICE_QUEUE_ENTRY Struct
    DeviceListEntry                                         LIST_ENTRY
    SortKey                                                 DD
    Inserted                                                DB
EndS

;KBUGCHECK_CALLBACK_REASON Enumeration
KbCallbackInvalid                                           Equ         0
KbCallbackReserved1                                         Equ         1
KbCallbackSecondaryDumpData                                 Equ         2
KbCallbackDumpIo                                            Equ         3
KbCallbackAddPages                                          Equ         4

KBUGCHECK_SECONDARY_DUMP_DATA Struct
    InBuffer                                                DD
    InBufferLength                                          DD
    MaximumAllowed                                          DD
    Guid                                                    GUID
    OutBuffer                                               DD
    OutBufferLength                                         DD
EndS

KB_ADD_PAGES_FLAG_VIRTUAL_ADDRESS                           Equ         00000001H
KB_ADD_PAGES_FLAG_PHYSICAL_ADDRESS                          Equ         00000002H
KB_ADD_PAGES_FLAG_ADDITIONAL_RANGES_EXIST                   Equ         80000000H

KBUGCHECK_ADD_PAGES Struct
    Context                                                 DD
    Flags                                                   DD
    BugCheckCode                                            DD
    Address                                                 DD
    Count                                                   DD
EndS

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
MmFrameBufferCached                                         Equ         2

;MEMORY_CACHING_TYPE Enumeration
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
KeProcessorAddStartNotify                                   Equ         0
KeProcessorAddCompleteNotify                                Equ         1
KeProcessorAddFailureNotify                                 Equ         2

KE_PROCESSOR_CHANGE_NOTIFY_CONTEXT Struct
    State                                                   DD
    NtNumber                                                DD
    Status                                                  DD
EndS

INVALID_PROCESSOR_INDEX                                     Equ         0FFFFFFFFH

;POOL_TYPE Enumeration
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
    byType                                                  DB
    Absolute                                                DB
    cbSize                                                  DB
    Inserted                                                DB
    SignalState                                             DD
    WaitListHead                                            LIST_ENTRY
EndS

KDEVICE_QUEUE Struct
    fwType                                                  DW
    cbSize                                                  DW
    DeviceListHead                                          LIST_ENTRY
    ksLock                                                  DD
    Busy                                                    DB
                                                            DB          3   Dup ?
EndS

KEVENT Struct
    Header                                                  DISPATCHER_HEADER
EndS

FAST_MUTEX Struct
    FM_LOCK_BIT                                             Equ         01H
    FM_LOCK_BIT_V                                           Equ         00H
    FM_LOCK_WAITER_WOKEN                                    Equ         02H
    FM_LOCK_WAITER_INC                                      Equ         04H
    Count                                                   DD
    Owner                                                   DD
    Contention                                              DD
    Event                                                   KEVENT
    OldIrql                                                 DD
EndS

EX_LOOKASIDE_LIST_EX_FLAGS_RAISE_ON_FAIL                    Equ         00000001H
EX_LOOKASIDE_LIST_EX_FLAGS_FAIL_NO_RAISE                    Equ         00000002H

EX_MAXIMUM_LOOKASIDE_DEPTH_BASE                             Equ         256
EX_MAXIMUM_LOOKASIDE_DEPTH_LIMIT                            Equ         1024

;WORK_QUEUE_TYPE Enumeration
CriticalWorkQueue                                           Equ         0
DelayedWorkQueue                                            Equ         1
HyperCriticalWorkQueue                                      Equ         2
MaximumWorkQueue                                            Equ         3

ResourceNeverExclusive                                      Equ         10H
ResourceReleaseByOtherThread                                Equ         20H
ResourceOwnedExclusive                                      Equ         80H

RESOURCE_HASH_TABLE_SIZE                                    Equ         64

RESOURCE_HASH_ENTRY Struct
    ListEntry                                               LIST_ENTRY
    Address                                                 DD
    ContentionCount                                         DD
    Number                                                  DD
EndS

RESOURCE_PERFORMANCE_DATA Struct
    ActiveResourceCount                                     DD
    TotalResourceCount                                      DD
    ExclusiveAcquire                                        DD
    SharedFirstLevel                                        DD
    SharedSecondLevel                                       DD
    StarveFirstLevel                                        DD
    StarveSecondLevel                                       DD
    WaitForExclusive                                        DD
    OwnerTableExpands                                       DD
    MaximumTableExpand                                      DD
    HashTable                                               LIST_ENTRY  RESOURCE_HASH_TABLE_SIZE Dup ?
EndS

EX_RUNDOWN_REF Struct
    EX_RUNDOWN_ACTIVE                                       Equ         01H
    EX_RUNDOWN_COUNT_SHIFT                                  Equ         01H
    EX_RUNDOWN_COUNT_INC                                    Equ         (1 << EX_RUNDOWN_COUNT_SHIFT)
    Union
        Count                                               DD
        Ptr                                                 DD
    EndUnion
EndS

;REG_NOTIFY_CLASS Enumeration
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
    Object                                                  DD
    CallContext                                             DD
    ObjectContext                                           DD
    Reserved                                                DD
EndS

REG_SET_VALUE_KEY_INFORMATION Struct
    Object                                                  DD
    ValueName                                               DD
    TitleIndex                                              DD
    Type                                                    DD
    Data                                                    DD
    DataSize                                                DD
    CallContext                                             DD
    ObjectContext                                           DD
    Reserved                                                DD
EndS

REG_DELETE_VALUE_KEY_INFORMATION Struct
    Object                                                  DD
    ValueName                                               DD
    CallContext                                             DD
    ObjectContext                                           DD
    Reserved                                                DD
EndS

REG_SET_INFORMATION_KEY_INFORMATION Struct
    Object                                                  DD
    KeySetInformationClass                                  DD
    KeySetInformation                                       DD
    KeySetInformationLength                                 DD
    CallContext                                             DD
    ObjectContext                                           DD
    Reserved                                                DD
EndS

REG_ENUMERATE_KEY_INFORMATION Struct
    Object                                                  DD
    Index                                                   DD
    KeyInformationClass                                     DD
    KeyInformation                                          DD
    Length                                                  DD
    ResultLength                                            DD
    CallContext                                             DD
    ObjectContext                                           DD
    Reserved                                                DD
EndS

REG_ENUMERATE_VALUE_KEY_INFORMATION Struct
    Object                                                  DD
    Index                                                   DD
    KeyValueInformationClass                                DD
    KeyValueInformation                                     DD
    Length                                                  DD
    ResultLength                                            DD
    CallContext                                             DD
    ObjectContext                                           DD
    Reserved                                                DD
EndS

REG_QUERY_KEY_INFORMATION Struct
    Object                                                  DD
    KeyInformationClass                                     DD
    KeyInformation                                          DD
    Length                                                  DD
    ResultLength                                            DD
    CallContext                                             DD
    ObjectContext                                           DD
    Reserved                                                DD
EndS

REG_QUERY_VALUE_KEY_INFORMATION Struct
    Object                                                  DD
    ValueName                                               DD
    KeyValueInformationClass                                DD
    KeyValueInformation                                     DD
    Length                                                  DD
    ResultLength                                            DD
    CallContext                                             DD
    ObjectContext                                           DD
    Reserved                                                DD
EndS

REG_QUERY_MULTIPLE_VALUE_KEY_INFORMATION Struct
    Object                                                  DD
    ValueEntries                                            DD
    EntryCount                                              DD
    ValueBuffer                                             DD
    BufferLength                                            DD
    RequiredBufferLength                                    DD
    CallContext                                             DD
    ObjectContext                                           DD
    Reserved                                                DD
EndS

REG_RENAME_KEY_INFORMATION Struct
    Object                                                  DD
    NewName                                                 DD
    CallContext                                             DD
    ObjectContext                                           DD
    Reserved                                                DD
EndS

REG_KEY_HANDLE_CLOSE_INFORMATION Struct
    Object                                                  DD
    CallContext                                             DD
    ObjectContext                                           DD
    Reserved                                                DD
EndS

REG_CREATE_KEY_INFORMATION Struct
    CompleteName                                            DD
    RootObject                                              DD
    ObjectType                                              DD
    CreateOptions                                           DD
    Class                                                   DD
    SecurityDescriptor                                      DD
    SecurityQualityOfService                                DD
    DesiredAccess                                           DD
    GrantedAccess                                           DD
    Disposition                                             DD
    ResultObject                                            DD
    CallContext                                             DD
    RootObjectContext                                       DD
    Transaction                                             DD
    Reserved                                                DD
EndS

REG_CREATE_KEY_INFORMATION_V1 Struct
    CompleteName                                            DD
    RootObject                                              DD
    ObjectType                                              DD
    Options                                                 DD
    Class                                                   DD
    SecurityDescriptor                                      DD
    SecurityQualityOfService                                DD
    DesiredAccess                                           DD
    GrantedAccess                                           DD
    Disposition                                             DD
    ResultObject                                            DD
    CallContext                                             DD
    RootObjectContext                                       DD
    Transaction                                             DD
    Version                                                 DD
    RemainingName                                           DD
    Wow64Flags                                              DD
    Attributes                                              DD
    CheckAccessMode                                         DB
EndS

REG_POST_OPERATION_INFORMATION Struct
    Object                                                  DD
    Status                                                  DD
    PreInformation                                          DD
    ReturnStatus                                            DD
    CallContext                                             DD
    ObjectContext                                           DD
    Reserved                                                DD
EndS

REG_PRE_CREATE_KEY_INFORMATION Struct
    CompleteName                                            DD
EndS

REG_POST_CREATE_KEY_INFORMATION Struct
    CompleteName                                            DD
    Object                                                  DD
    Status                                                  DD
EndS

REG_LOAD_KEY_INFORMATION Struct
    Object                                                  DD
    KeyName                                                 DD
    SourceFile                                              DD
    Flags                                                   DD
    TrustClassObject                                        DD
    UserEvent                                               DD
    DesiredAccess                                           DD
    RootHandle                                              DD
    CallContext                                             DD
    ObjectContext                                           DD
    Reserved                                                DD
EndS

REG_UNLOAD_KEY_INFORMATION Struct
    Object                                                  DD
    UserEvent                                               DD
    CallContext                                             DD
    ObjectContext                                           DD
    Reserved                                                DD
EndS

REG_CALLBACK_CONTEXT_CLEANUP_INFORMATION Struct
    Object                                                  DD
    ObjectContext                                           DD
    Reserved                                                DD
EndS

REG_QUERY_KEY_SECURITY_INFORMATION Struct
    Object                                                  DD
    SecurityInformation                                     DD
    SecurityDescriptor                                      DD
    Length                                                  DD
    CallContext                                             DD
    ObjectContext                                           DD
    Reserved                                                DD
EndS

REG_SET_KEY_SECURITY_INFORMATION Struct
    Object                                                  DD
    SecurityInformation                                     DD
    SecurityDescriptor                                      DD
    CallContext                                             DD
    ObjectContext                                           DD
    Reserved                                                DD
EndS

REG_RESTORE_KEY_INFORMATION Struct
    Object                                                  DD
    FileHandle                                              DD
    Flags                                                   DD
    CallContext                                             DD
    ObjectContext                                           DD
    Reserved                                                DD
EndS

REG_SAVE_KEY_INFORMATION Struct
    Object                                                  DD
    FileHandle                                              DD
    Format                                                  DD
    CallContext                                             DD
    ObjectContext                                           DD
    Reserved                                                DD
EndS

REG_REPLACE_KEY_INFORMATION Struct
    Object                                                  DD
    OldFileName                                             DD
    NewFileName                                             DD
    CallContext                                             DD
    ObjectContext                                           DD
    Reserved                                                DD
EndS

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
MmSmallSystem                                               Equ         0
MmMediumSystem                                              Equ         1
MmLargeSystem                                               Equ         2

;MM_PAGE_PRIORITY Enumeration
LowPagePriority                                             Equ         0
NormalPagePriority                                          Equ         16
HighPagePriority                                            Equ         32

MM_DONT_ZERO_ALLOCATION                                     Equ         00000001H
MM_ALLOCATE_FROM_LOCAL_NODE_ONLY                            Equ         00000002H
MM_ALLOCATE_FULLY_REQUIRED                                  Equ         00000004H
MM_ALLOCATE_NO_WAIT                                         Equ         00000008H
MM_ALLOCATE_PREFER_CONTIGUOUS                               Equ         00000010H
MM_ALLOCATE_REQUIRE_CONTIGUOUS_CHUNKS                       Equ         00000020H

MM_ANY_NODE_OK                                              Equ         80000000H

;SECURITY_OPERATION_CODE Enumeration
SetSecurityDescriptor                                       Equ         0
QuerySecurityDescriptor                                     Equ         1
DeleteSecurityDescriptor                                    Equ         2
AssignSecurityDescriptor                                    Equ         3

SECURITY_SUBJECT_CONTEXT Struct
    ClientToken                                             DD
    ImpersonationLevel                                      DD
    PrimaryToken                                            DD
    ProcessAuditId                                          DD
EndS

INITIAL_PRIVILEGE_COUNT                                     Equ         3

INITIAL_PRIVILEGE_SET Struct
    PrivilegeCount                                          DD
    Control                                                 DD
    Privilege                                               LUID_AND_ATTRIBUTES INITIAL_PRIVILEGE_COUNT Dup ?
EndS

ACCESS_STATE Struct
   OperationID                                              LUID
   SecurityEvaluated                                        DB
   GenerateAudit                                            DB
   GenerateOnClose                                          DB
   PrivilegesAllocated                                      DB
   Flags                                                    DD
   RemainingDesiredAccess                                   DD
   PreviouslyGrantedAccess                                  DD
   OriginalDesiredAccess                                    DD
   SubjectSecurityContext                                   SECURITY_SUBJECT_CONTEXT
   SecurityDescriptor                                       DD
   AuxData                                                  DD
   Privileges Union
      InitialPrivilegeSet                                   INITIAL_PRIVILEGE_SET
      PrivilegeSet                                          PRIVILEGE_SET
   EndUnion
   AuditPrivileges                                          DB
   ObjectName                                               UNICODE_STRING
   ObjectTypeName                                           UNICODE_STRING
EndS

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
CreateFileTypeNone                                          Equ         0
CreateFileTypeNamedPipe                                     Equ         1
CreateFileTypeMailslot                                      Equ         2

FAST_IO_DISPATCH Struct
    SizeOfFastIoDispatch                                    DD
    FastIoCheckIfPossible                                   DD
    FastIoRead                                              DD
    FastIoWrite                                             DD
    FastIoQueryBasicInfo                                    DD
    FastIoQueryStandardInfo                                 DD
    FastIoLock                                              DD
    FastIoUnlockSingle                                      DD
    FastIoUnlockAll                                         DD
    FastIoUnlockAllByKey                                    DD
    FastIoDeviceControl                                     DD
    AcquireFileForNtCreateSection                           DD
    ReleaseFileForNtCreateSection                           DD
    FastIoDetachDevice                                      DD
    FastIoQueryNetworkOpenInfo                              DD
    AcquireForModWrite                                      DD
    MdlRead                                                 DD
    MdlReadComplete                                         DD
    PrepareMdlWrite                                         DD
    MdlWriteComplete                                        DD
    FastIoReadCompressed                                    DD
    FastIoWriteCompressed                                   DD
    MdlReadCompleteCompressed                               DD
    MdlWriteCompleteCompressed                              DD
    FastIoQueryOpen                                         DD
    ReleaseForModWrite                                      DD
    AcquireForCcFlush                                       DD
    ReleaseForCcFlush                                       DD
EndS

;IO_ALLOCATION_ACTION enumeration
KeepObject                                                  Equ         1
DeallocateObject                                            Equ         2
DeallocateObjectKeepRegisters                               Equ         3

IO_SECURITY_CONTEXT Struct
    SecurityQos                                             DD
    AccessState                                             DD
    DesiredAccess                                           DD
    FullCreateOptions                                       DD
EndS

VPB_MOUNTED                                                 Equ         00000001H
VPB_LOCKED                                                  Equ         00000002H
VPB_PERSISTENT                                              Equ         00000004H
VPB_REMOVE_PENDING                                          Equ         00000008H
VPB_RAW_MOUNT                                               Equ         00000010H
VPB_DIRECT_WRITES_ALLOWED                                   Equ         00000020H

MAXIMUM_VOLUME_LABEL_LENGTH                                 Equ         (32 * SizeOf DW) ; 32 characters

DEVOBJ_EXTENSION Struct
    Type                                                    DW
    Size                                                    DW
    DeviceObject                                            DD
EndS

VPB Struct
    Type                                                    DW
    Size                                                    DW
    Flags                                                   DW
    VolumeLabelLength                                       DW
    DeviceObject                                            DD
    RealDevice                                              DD
    SerialNumber                                            DD
    ReferenceCount                                          DD
    VolumeLabel                                             DW          (MAXIMUM_VOLUME_LABEL_LENGTH / SizeOf DW) Dup ?
EndS

WAIT_CONTEXT_BLOCK Struct
    WaitQueueEntry                                          KDEVICE_QUEUE_ENTRY
    DeviceRoutine                                           DD
    DeviceContext                                           DD
    NumberOfMapRegisters                                    DD
    DeviceObject                                            DD
    CurrentIrp                                              DD
    BufferChainingDpc                                       DD
EndS

DEVICE_OBJECT Struct
    Type                                                    DW
    Size                                                    DW
    ReferenceCount                                          DD
    DriverObject                                            DD
    NextDevice                                              DD
    AttachedDevice                                          DD
    CurrentIrp                                              DD
    Timer                                                   DD
    Flags                                                   DD
    Characteristics                                         DD
    Vpb                                                     DD
    DeviceExtension                                         DD
    DeviceType                                              DD
    StackSize                                               DB
    Queue Union
        ListEntry                                           LIST_ENTRY
        Wcb                                                 WAIT_CONTEXT_BLOCK
    EndUnion
    AlignmentRequirement                                    DD
    DeviceQueue                                             KDEVICE_QUEUE
    Dpc                                                     KDPC
    ActiveThreadCount                                       DD
    SecurityDescriptor                                      DD
    DeviceLock                                              KEVENT
    SectorSize                                              DW
    Spare1                                                  DW
    DeviceObjectExtension                                   DD
    Reserved                                                DD
EndS

DRIVER_OBJECT Struct
    Type                                                    DW
    Size                                                    DW
    DeviceObject                                            DD
    Flags                                                   DD
    DriverStart                                             DD
    DriverSize                                              DD
    DriverSection                                           DD
    DriverExtension                                         DD
    DriverName                                              UNICODE_STRING
    HardwareDatabase                                        DD
    FastIoDispatch                                          DD
    DriverInit                                              DD
    DriverStartIo                                           DD
    DriverUnload                                            DD
    MajorFunction                                           DD          (IRP_MJ_MAXIMUM_FUNCTION + 1) Dup ?
EndS

DRIVER_EXTENSION Struct
    DriverObject                                            DD
    AddDevice                                               DD
    Count                                                   DD
    ServiceKeyName                                          UNICODE_STRING
EndS

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
    DataSectionObject                                       DD
    SharedCacheMap                                          DD
    ImageSectionObject                                      DD
EndS

IO_COMPLETION_CONTEXT Struct
    Port                                                    DD
    Key                                                     DD
EndS

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
    Type                                                    DW
    Size                                                    DW
    DeviceObject                                            DD
    Vpb                                                     DD
    FsContext                                               DD
    FsContext2                                              DD
    SectionObjectPointer                                    DD
    PrivateCacheMap                                         DD
    FinalStatus                                             DD
    RelatedFileObject                                       DD
    LockOperation                                           DB
    DeletePending                                           DB
    ReadAccess                                              DB
    WriteAccess                                             DB
    DeleteAccess                                            DB
    SharedRead                                              DB
    SharedWrite                                             DB
    SharedDelete                                            DB
    Flags                                                   DD
    FileName                                                UNICODE_STRING
    CurrentByteOffset                                       LARGE_INTEGER
    Waiters                                                 DD
    Busy                                                    DD
    LastLock                                                DD
    Lock                                                    KEVENT
    Event                                                   KEVENT
    CompletionContext                                       DD
    IrpListLock                                             DD
    IrpList                                                 LIST_ENTRY
    FileObjectExtension                                     DD
EndS

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
    Type                                                    DW
    Size                                                    DW
    MdlAddress                                              DD
    Flags                                                   DD
    AssociatedIrp Union
        MasterIrp                                           DD
        IrpCount                                            DD
        SystemBuffer                                        DD
    EndUnion
    ThreadListEntry                                         LIST_ENTRY
    IoStatus                                                IO_STATUS_BLOCK
    RequestorMode                                           DB
    PendingReturned                                         DB
    StackCount                                              DB
    CurrentLocation                                         DB
    Cancel                                                  DB
    CancelIrql                                              DB
    ApcEnvironment                                          DB
    AllocationFlags                                         DB
    UserIosb                                                DD
    UserEvent                                               DD
    Overlay Union
        AsynchronousParameters Struct
            UserApcRoutine                                  DD
            UserApcContext                                  DD
        EndS
        AllocationSize                                      LARGE_INTEGER
    EndUnion
    CancelRoutine                                           DD
    UserBuffer                                              DD
    Tail Union
        Overlay Struct
            Union
                DeviceQueueEntry                            KDEVICE_QUEUE_ENTRY
                Struct
                    DriverContext                           DD          4 Dup ?
                EndS
            EndUnion
            Thread                                          DD
            AuxiliaryBuffer                                 DD
            Struct
                ListEntry                                   LIST_ENTRY
                Union
                    CurrentStackLocation                    DD
                    PacketType                              DD
                EndUnion
            EndS
            OriginalFileObject                              DD
        EndS
        Apc                                                 KAPC
        CompletionKey                                       DD
    EndUnion
EndS

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
    Count                                                   DD
    Objects                                                 DD          1 Dup ?
EndS

;DEVICE_USAGE_NOTIFICATION_TYPE Enumeration
DeviceUsageTypeUndefined                                    Equ         0
DeviceUsageTypePaging                                       Equ         1
DeviceUsageTypeHibernation                                  Equ         2
DeviceUsageTypeDumpFile                                     Equ         3

INTERFACE Struct
    Size                                                    DW
    Version                                                 DW
    Context                                                 DD
    InterfaceReference                                      DD
    InterfaceDereference                                    DD
EndS

POWER_SEQUENCE Struct
    SequenceD1                                              DD
    SequenceD2                                              DD
    SequenceD3                                              DD
EndS

;BUS_QUERY_ID_TYPE Enumeration
BusQueryDeviceID                                            Equ         0
BusQueryHardwareIDs                                         Equ         1
BusQueryCompatibleIDs                                       Equ         2
BusQueryInstanceID                                          Equ         3
BusQueryDeviceSerialNumber                                  Equ         4
BusQueryContainerID                                         Equ         5

PNP_DEVICE_DISABLED                                         Equ         00000001H
PNP_DEVICE_DONT_DISPLAY_IN_UI                               Equ         00000002H
PNP_DEVICE_FAILED                                           Equ         00000004H
PNP_DEVICE_REMOVED                                          Equ         00000008H
PNP_DEVICE_RESOURCE_REQUIREMENTS_CHANGED                    Equ         00000010H
PNP_DEVICE_NOT_DISABLEABLE                                  Equ         00000020H

;DEVICE_TEXT_TYPE Enumeration
DeviceTextDescription                                       Equ         0
DeviceTextLocationInformation                               Equ         1

IO_STACK_LOCATION Struct
    MajorFunction                                           DB
    MinorFunction                                           DB
    Flags                                                   DB
    Control                                                 DB
    Parameters Union
        Create Struct
            SecurityContext                                 DD
            Options                                         DD
            FileAttributes                                  DW
            ShareAccess                                     DW
            EaLength                                        DD
        EndS
        Read Struct
            dwLength                                        DD
            Key                                             DD
            ByteOffset                                      LARGE_INTEGER
        EndS
        Write Struct
            dwLength                                        DD
            Key                                             DD
            ByteOffset                                      LARGE_INTEGER
        EndS
        DeviceIoControl Struct
            OutputBufferLength                              DD
            InputBufferLength                               DD
            IoControlCode                                   DD
            Type3InputBuffer                                DD
        EndS
        SetLock Struct
            bLock                                           DB
                                                            DB          3 Dup ?
        EndS
        Others Struct
            Argument1                                       DD
            Argument2                                       DD
            Argument3                                       DD
            Argument4                                       DD
        EndS
    EndUnion
    DeviceObject                                            DD
    FileObject                                              DD
    CompletionRoutine                                       DD
    Context                                                 DD
EndS

SHARE_ACCESS Struct
    OpenCount                                               DD
    Readers                                                 DD
    Writers                                                 DD
    Deleters                                                DD
    SharedRead                                              DD
    SharedWrite                                             DD
    SharedDelete                                            DD
EndS

;IO_PAGING_PRIORITY Enumeration
IoPagingPriorityInvalid                                     Equ         0
IoPagingPriorityNormal                                      Equ         1
IoPagingPriorityHigh                                        Equ         2
IoPagingPriorityReserved1                                   Equ         3
IoPagingPriorityReserved2                                   Equ         4

BOOTDISK_INFORMATION Struct
    BootPartitionOffset                                     DQ
    SystemPartitionOffset                                   DQ
    BootDeviceSignature                                     DD
    SystemDeviceSignature                                   DD
EndS

BOOTDISK_INFORMATION_EX Struct
    BootPartitionOffset                                     DQ
    SystemPartitionOffset                                   DQ
    BootDeviceSignature                                     DD
    SystemDeviceSignature                                   DD
    BootDeviceGuid                                          GUID
    SystemDeviceGuid                                        GUID
    BootDeviceIsGpt                                         DB
    SystemDeviceIsGpt                                       DB
EndS

LOADER_PARTITION_INFORMATION_EX Struct
    PartitionStyle                                          DD
    PartitionNumber                                         DD
    Union
        Signature                                           DD
        DeviceId                                            GUID
    EndUnion
    Flags                                                   DD
EndS

IO_INTERRUPT_MESSAGE_INFO_ENTRY Struct
    MessageAddress                                          PHYSICAL_ADDRESS
    TargetProcessorSet                                      DD
    InterruptObject                                         DD
    MessageData                                             DD
    Vector                                                  DD
    Irql                                                    DB
    Mode                                                    DD
    Polarity                                                DD
EndS

IO_INTERRUPT_MESSAGE_INFO Struct
    UnifiedIrql                                             DB
    MessageCount                                            DD
    MessageInfo                                             IO_INTERRUPT_MESSAGE_INFO_ENTRY 1 Dup ?
EndS

IO_CONNECT_INTERRUPT_FULLY_SPECIFIED_PARAMETERS Struct
    PhysicalDeviceObject                                    DD
    InterruptObject                                         DD
    ServiceRoutine                                          DD
    ServiceContext                                          DD
    SpinLock                                                DD
    SynchronizeIrql                                         DB
    FloatingSave                                            DB
    ShareVector                                             DB
    Vector                                                  DD
    Irql                                                    DB
    InterruptMode                                           DD
    ProcessorEnableMask                                     DD
    Group                                                   DW
EndS

IO_CONNECT_INTERRUPT_LINE_BASED_PARAMETERS Struct
    PhysicalDeviceObject                                    DD
    InterruptObject                                         DD
    ServiceRoutine                                          DD
    ServiceContext                                          DD
    SpinLock                                                DD
    SynchronizeIrql                                         DB
    FloatingSave                                            DB
EndS

IO_CONNECT_INTERRUPT_MESSAGE_BASED_PARAMETERS Struct
    PhysicalDeviceObject                                    DD
    ConnectionContext Union
        Generic                                             DD
        InterruptMessageTable                               DD
        InterruptObject                                     DD
    EndUnion
    MessageServiceRoutine                                   DD
    ServiceContext                                          DD
    SpinLock                                                DD
    SynchronizeIrql                                         DB
    FloatingSave                                            DB
    FallBackServiceRoutine                                  DD
EndS

CONNECT_FULLY_SPECIFIED                                     Equ         01H
CONNECT_LINE_BASED                                          Equ         02H
CONNECT_MESSAGE_BASED                                       Equ         03H
CONNECT_FULLY_SPECIFIED_GROUP                               Equ         04H
CONNECT_CURRENT_VERSION                                     Equ         04H

IO_CONNECT_INTERRUPT_PARAMETERS Struct
    Version                                                 DD
    Union
        FullySpecified                                      IO_CONNECT_INTERRUPT_FULLY_SPECIFIED_PARAMETERS
        LineBased                                           IO_CONNECT_INTERRUPT_LINE_BASED_PARAMETERS
        MessageBased                                        IO_CONNECT_INTERRUPT_MESSAGE_BASED_PARAMETERS
    EndUnion
EndS

WDM_MAJORVERSION                                            Equ         06H
WDM_MINORVERSION                                            Equ         00H

IO_DISCONNECT_INTERRUPT_PARAMETERS Struct
    Version                                                 DD
    ConnectionContext Union
        Generic                                             DD
        InterruptObject                                     DD
        InterruptMessageTable                               DD
    EndUnion
EndS

IO_REMOVE_LOCK_COMMON_BLOCK Struct
    Removed                                                 DB
    Reserved                                                DB          3 Dup ?
    IoCount                                                 DD
    RemoveEvent                                             KEVENT
EndS

IO_REMOVE_LOCK_DBG_BLOCK Struct
    Signature                                               DD
    HighWatermark                                           DD
    MaxLockedTicks                                          DQ
    AllocateTag                                             DD
    LockList                                                LIST_ENTRY
    Spin                                                    DD
    LowMemoryCount                                          DD
    Reserved1                                               DD          4 Dup ?
    Reserved2                                               DD
    Blocks                                                  DD
EndS

WMIREG_ACTION_REGISTER                                      Equ         1
WMIREG_ACTION_DEREGISTER                                    Equ         2
WMIREG_ACTION_REREGISTER                                    Equ         3
WMIREG_ACTION_UPDATE_GUIDS                                  Equ         4
WMIREG_ACTION_BLOCK_IRPS                                    Equ         5

WMIREGISTER                                                 Equ         0
WMIUPDATE                                                   Equ         1

IO_TYPE_CSQ_IRP_CONTEXT                                     Equ         1
IO_TYPE_CSQ                                                 Equ         2
IO_TYPE_CSQ_EX                                              Equ         3

IO_CSQ_IRP_CONTEXT Struct
    Type                                                    DD
    _Irp                                                    DD
    Csq                                                     DD
EndS

IO_CSQ Struct
    Type                                                    DD
    CsqInsertIrp                                            DD
    CsqRemoveIrp                                            DD
    CsqPeekNextIrp                                          DD
    CsqAcquireLock                                          DD
    CsqReleaseLock                                          DD
    CsqCompleteCanceledIrp                                  DD
    ReservePointer                                          DD
EndS

;IO_ACCESS_TYPE Enumeration
ReadAccess                                                  Equ         0
WriteAccess                                                 Equ         1
ModifyAccess                                                Equ         2

;IO_ACCESS_MODE Enumeration
SequentialAccess                                            Equ         0
RandomAccess                                                Equ         1

;IO_CONTAINER_NOTIFICATION_CLASS Enumeration
IoSessionStateNotification                                  Equ         0
IoMaxContainerNotificationClass                             Equ         1

IO_SESSION_STATE_NOTIFICATION Struct
    Size                                                    DD
    Flags                                                   DD
    IoObject                                                DD
    EventMask                                               DD
    Context                                                 DD
EndS

;IO_CONTAINER_INFORMATION_CLASS Enumeration
IoSessionStateInformation                                   Equ         0
IoMaxContainerInformationClass                              Equ         1

IO_SESSION_STATE_INFORMATION Struct
    SessionId                                               DD
    SessionState                                            DD
    LocalSession                                            DB
EndS

ETW_TRACE_SESSION_SETTINGS Struct
    Version                                                 DD
    BufferSize                                              DD
    MinimumBuffers                                          DD
    MaximumBuffers                                          DD
    LoggerMode                                              DD
    FlushTimer                                              DD
    FlushThreshold                                          DD
    ClockType                                               DD
EndS

;TRACE_INFORMATION_CLASS Enumeration
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
InstallStateInstalled                                       Equ         0
InstallStateNeedsReinstall                                  Equ         1
InstallStateFailedInstall                                   Equ         2
InstallStateFinishInstall                                   Equ         3

PNP_BUS_INFORMATION Struct
    BusTypeGuid                                             GUID
    LegacyBusType                                           DD
    BusNumber                                               DD
EndS

LEGACY_BUS_INFORMATION Struct
    BusTypeGuid                                             GUID
    LegacyBusType                                           DD
    BusNumber                                               DD
EndS

;DEVICE_REMOVAL_POLICY Enumeration
RemovalPolicyExpectNoRemoval                                Equ         1
RemovalPolicyExpectOrderlyRemoval                           Equ         2
RemovalPolicyExpectSurpriseRemoval                          Equ         3

BUS_INTERFACE_STANDARD Struct
    Size                                                    DW
    Version                                                 DW
    Context                                                 DD
    InterfaceReference                                      DD
    InterfaceDereference                                    DD
    TranslateBusAddress                                     DD
    GetDmaAdapter                                           DD
    SetBusData                                              DD
    GetBusData                                              DD
EndS

ACPI_INTERFACE_STANDARD Struct
    Size                                                    DW
    Version                                                 DW
    Context                                                 DD
    InterfaceReference                                      DD
    InterfaceDereference                                    DD
    GpeConnectVector                                        DD
    GpeDisconnectVector                                     DD
    GpeEnableEvent                                          DD
    GpeDisableEvent                                         DD
    GpeClearStatus                                          DD
    RegisterForDeviceNotifications                          DD
    UnregisterForDeviceNotifications                        DD
EndS

ACPI_INTERFACE_STANDARD2 Struct
    Size                                                    DW
    Version                                                 DW
    Context                                                 DD
    InterfaceReference                                      DD
    InterfaceDereference                                    DD
    GpeConnectVector                                        DD
    GpeDisconnectVector                                     DD
    GpeEnableEvent                                          DD
    GpeDisableEvent                                         DD
    GpeClearStatus                                          DD
    RegisterForDeviceNotifications                          DD
    UnregisterForDeviceNotifications                        DD
EndS

PLUGPLAY_REGKEY_DEVICE                                      Equ         1
PLUGPLAY_REGKEY_DRIVER                                      Equ         2
PLUGPLAY_REGKEY_CURRENT_HWPROFILE                           Equ         4

;IO_NOTIFICATION_EVENT_CATEGORY Enumeration
EventCategoryReserved                                       Equ         0
EventCategoryHardwareProfileChange                          Equ         1
EventCategoryDeviceInterfaceChange                          Equ         2
EventCategoryTargetDeviceChange                             Equ         3

PNPNOTIFY_DEVICE_INTERFACE_INCLUDE_EXISTING_INTERFACES      Equ         00000001H

PLUGPLAY_NOTIFICATION_HEADER Struct
    Version                                                 DW
    Size                                                    DW
    Event                                                   GUID
EndS

HWPROFILE_CHANGE_NOTIFICATION Struct
    Version                                                 DW
    Size                                                    DW
    Event                                                   GUID
EndS

DEVICE_INTERFACE_CHANGE_NOTIFICATION Struct
    Version                                                 DW
    Size                                                    DW
    Event                                                   GUID
    InterfaceClassGuid                                      GUID
    SymbolicLinkName                                        DD
EndS

TARGET_DEVICE_REMOVAL_NOTIFICATION Struct
    Version                                                 DW
    Size                                                    DW
    Event                                                   GUID
    FileObject                                              DD
EndS

TARGET_DEVICE_CUSTOM_NOTIFICATION Struct
    Version                                                 DW
    Size                                                    DW
    Event                                                   GUID
    FileObject                                              DD
    NameBufferOffset                                        DD
    CustomDataBuffer                                        DB          1 Dup ?
EndS

PNP_REPLACE_PROCESSOR_LIST Struct
    Affinity                                                DD
    GroupCount                                              DD
    AllocatedCount                                          DD
    Count                                                   DD
    ApicIds                                                 DD          ANYSIZE_ARRAY Dup ?
EndS

PNP_REPLACE_PROCESSOR_LIST_V1 Struct
    AffinityMask                                            DD
    AllocatedCount                                          DD
    Count                                                   DD
    ApicIds                                                 DD          ANYSIZE_ARRAY Dup ?
EndS

PNP_REPLACE_PARAMETERS_VERSION                              Equ         2

PNP_REPLACE_PARAMETERS Struct
    Size                                                    DD
    Version                                                 DD
    Target                                                  DQ
    Spare                                                   DQ
    TargetProcessors                                        DD
    SpareProcessors                                         DD
    TargetMemory                                            DD
    SpareMemory                                             DD
    MapMemory                                               DD
EndS

PNP_REPLACE_DRIVER_INTERFACE_VERSION                        Equ         1

PNP_REPLACE_MEMORY_SUPPORTED                                Equ         0001H
PNP_REPLACE_PROCESSOR_SUPPORTED                             Equ         0002H
PNP_REPLACE_HARDWARE_MEMORY_MIRRORING                       Equ         0004H
PNP_REPLACE_HARDWARE_PAGE_COPY                              Equ         0008H
PNP_REPLACE_HARDWARE_QUIESCE                                Equ         0010H

PNP_REPLACE_DRIVER_INTERFACE Struct
    Size                                                    DD
    Version                                                 DD
    Flags                                                   DD
    Unload                                                  DD
    BeginReplace                                            DD
    EndReplace                                              DD
    MirrorPhysicalMemory                                    DD
    SetProcessorId                                          DD
    Swap                                                    DD
    InitiateHardwareMirror                                  DD
    MirrorPlatformMemory                                    DD
    GetMemoryDestination                                    DD
    EnableDisableHardwareQuiesce                            DD
EndS

DEVICE_DESCRIPTION Struct
    Version                                                 DD
    Master                                                  DB
    ScatterGather                                           DB
    DemandMode                                              DB
    AutoInitialize                                          DB
    Dma32BitAddresses                                       DB
    IgnoreCount                                             DB
    Reserved1                                               DB
    Dma64BitAddresses                                       DB
    BusNumber                                               DD
    DmaChannel                                              DD
    InterfaceType                                           DD
    DmaWidth                                                DD
    DmaSpeed                                                DD
    MaximumLength                                           DD
    DmaPort                                                 DD
EndS

DEVICE_DESCRIPTION_VERSION                                  Equ         0
DEVICE_DESCRIPTION_VERSION1                                 Equ         1
DEVICE_DESCRIPTION_VERSION2                                 Equ         2

DMA_ADAPTER Struct
    Version                                                 DW
    Size                                                    DW
    DmaOperations                                           DD
EndS

DMA_OPERATIONS Struct
    Size                                                    DD
    PutDmaAdapter                                           DD
    AllocateCommonBuffer                                    DD
    FreeCommonBuffer                                        DD
    AllocateAdapterChannel                                  DD
    FlushAdapterBuffers                                     DD
    FreeAdapterChannel                                      DD
    FreeMapRegisters                                        DD
    MapTransfer                                             DD
    GetDmaAlignment                                         DD
    ReadDmaCounter                                          DD
    GetScatterGatherList                                    DD
    PutScatterGatherList                                    DD
    CalculateScatterGatherList                              DD
    BuildScatterGatherList                                  DD
    BuildMdlFromScatterGatherList                           DD
EndS

PO_CB_SYSTEM_POWER_POLICY                                   Equ         0
PO_CB_AC_STATUS                                             Equ         1
PO_CB_BUTTON_COLLISION                                      Equ         2
PO_CB_SYSTEM_STATE_LOCK                                     Equ         3
PO_CB_LID_SWITCH_STATE                                      Equ         4
PO_CB_PROCESSOR_POWER_POLICY                                Equ         5

OBJECT_HANDLE_INFORMATION Struct
    HandleAttributes                                        DD
    GrantedAccess                                           DD
EndS

OB_FLT_REGISTRATION_VERSION_0100                            Equ         0100H

OB_FLT_REGISTRATION_VERSION                                 Equ         OB_FLT_REGISTRATION_VERSION_0100

OB_OPERATION_HANDLE_CREATE                                  Equ         00000001H
OB_OPERATION_HANDLE_DUPLICATE                               Equ         00000002H

OB_PRE_CREATE_HANDLE_INFORMATION Struct
    DesiredAccess                                           DD
    OriginalDesiredAccess                                   DD
EndS

OB_PRE_DUPLICATE_HANDLE_INFORMATION Struct
    DesiredAccess                                           DD
    OriginalDesiredAccess                                   DD
    SourceProcess                                           DD
    TargetProcess                                           DD
EndS

OB_PRE_OPERATION_PARAMETERS Union
    CreateHandleInformation                                 OB_PRE_CREATE_HANDLE_INFORMATION
    DuplicateHandleInformation                              OB_PRE_DUPLICATE_HANDLE_INFORMATION
EndUnion

OB_POST_CREATE_HANDLE_INFORMATION Struct
    GrantedAccess                                           DD
EndS

OB_POST_DUPLICATE_HANDLE_INFORMATION Struct
    GrantedAccess                                           DD
EndS

OB_POST_OPERATION_PARAMETERS Union
    CreateHandleInformation                                 OB_POST_CREATE_HANDLE_INFORMATION
    DuplicateHandleInformation                              OB_POST_DUPLICATE_HANDLE_INFORMATION
EndUnion

;OB_PREOP_CALLBACK_STATUS Enumeration
OB_PREOP_SUCCESS                                            Equ         0

OB_OPERATION_REGISTRATION Struct
    ObjectType                                              DD
    Operations                                              DD
    PreOperation                                            DD
    PostOperation                                           DD
EndS

OB_CALLBACK_REGISTRATION Struct
    Version                                                 DW
    OperationRegistrationCount                              DW
    Altitude                                                UNICODE_STRING
    RegistrationContext                                     DD
    OperationRegistration                                   DD
EndS

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
    CapabilityID                                            DB
    Next                                                    DB
EndS

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

ROOT_CMD_ERROR_REPORTING_ENABLE_MASK                        Equ         (ROOT_CMD_ENABLE_FATAL_ERROR_REPORTING | ROOT_CMD_ENABLE_NONFATAL_ERROR_REPORTING | ROOT_CMD_ENABLE_CORRECTABLE_ERROR_REPORTING)

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
    _Size                                                   DD
    Flags                                                   DD
    VendorID                                                DW
    DeviceID                                                DW
    RevisionID                                              DB
    SubVendorID                                             DW
    SubSystemID                                             DW
    BaseClass                                               DB
    SubClass                                                DB
    ProgIf                                                  DB
EndS

PCI_DEVICE_PRESENT_INTERFACE Struct
    Size                                                    DW
    Version                                                 DW
    Context                                                 DD
    InterfaceReference                                      DD
    InterfaceDereference                                    DD
    IsDevicePresent                                         DD
    IsDevicePresentEx                                       DD
EndS

PCI_EXPRESS_LINK_QUIESCENT_INTERFACE_VERSION                Equ         1

PCI_EXPRESS_LINK_QUIESCENT_INTERFACE Struct
    Size                                                    DW
    Version                                                 DW
    Context                                                 DD
    InterfaceReference                                      DD
    InterfaceDereference                                    DD
    PciExpressEnterLinkQuiescentMode                        DD
    PciExpressExitLinkQuiescentMode                         DD
EndS

PCI_EXPRESS_ROOT_PORT_INTERFACE_VERSION                     Equ         1

PCI_EXPRESS_ROOT_PORT_INTERFACE Struct
    Size                                                    DW
    Version                                                 DW
    Context                                                 DD
    InterfaceReference                                      DD
    InterfaceDereference                                    DD
    ReadConfigSpace                                         DD
    WriteConfigSpace                                        DD
EndS

PCI_MSIX_TABLE_CONFIG_INTERFACE_VERSION                     Equ         1

PCI_MSIX_TABLE_CONFIG_INTERFACE Struct
    Size                                                    DW
    Version                                                 DW
    Context                                                 DD
    InterfaceReference                                      DD
    InterfaceDereference                                    DD
    SetTableEntry                                           DD
    MaskTableEntry                                          DD
    UnmaskTableEntry                                        DD
    GetTableEntry                                           DD
    GetTableSize                                            DD
EndS

;EM_RULE_STATE  Enumeration
STATE_FALSE                                                 Equ         0
STATE_UNKNOWN                                               Equ         1
STATE_TRUE                                                  Equ         2

EM_ENTRY_DATA Struct
    Data                                                    DD
    DataLength                                              DD
EndS

EM_ENTRY_REGISTRATION Struct
    EntryGuid                                               DD
    LazyEntryCallback                                       DD
    LazyCallbackContext                                     DD
EndS

EM_CALLBACK_REGISTRATION Struct
    CallbackGuid                                            DD
    CallbackFunction                                        DD
    Context                                                 DD
EndS

EM_CLIENT_NOTIFICATION_REGISTRATION Struct
    RuleId                                                  DD
    RuleNotifyCallback                                      DD
    Context                                                 DD
EndS

FILE_ATTRIBUTE_DEDICATED                                    Equ         FILE_ATTRIBUTE_TEMPORARY

#Define                                                     EA_CONTAINER_NAME "ContainerName"
#Define                                                     EA_CONTAINER_SIZE "ContainerSize"

#Define                                                     CLFS_BASELOG_EXTENSION ".blf"

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

;CLS_CONTEXT_MODE Enumeration
ClsContextNone                                              Equ         00H
ClsContextUndoNext                                          Equ         01H
ClsContextPrevious                                          Equ         02H
ClsContextForward                                           Equ         03H

;CLFS_CONTEXT_MODE Enumeration
ClfsContextNone                                             Equ         00H
ClfsContextUndoNext                                         Equ         01H
ClfsContextPrevious                                         Equ         02H
ClfsContextForward                                          Equ         03H

CLFS_NODE_ID Struct
    cType                                                   DD
    cbNode                                                  DD
EndS

CLS_WRITE_ENTRY Struct
    Buffer                                                  DD
    ByteLength                                              DD
EndS

#Define                                                     CLFS_LOG_ID GUID

#IFNDEF  CLS_LSN
    CLS_LSN Struct
        Internal                                            DQ
    EndS
    #Define                                                 CLFS_LSN CLS_LSN
#ENDIF

CLS_INFORMATION Struct
    TotalAvailable                                          DQ
    CurrentAvailable                                        DQ
    TotalReservation                                        DQ
    BaseFileSize                                            DQ
    ContainerSize                                           DQ
    TotalContainers                                         DD
    FreeContainers                                          DD
    TotalClients                                            DD
    Attributes                                              DD
    FlushThreshold                                          DD
    SectorSize                                              DD
    MinArchiveTailLsn                                       CLS_LSN
    BaseLsn                                                 CLS_LSN
    LastFlushedLsn                                          CLS_LSN
    LastLsn                                                 CLS_LSN
    RestartLsn                                              CLS_LSN
    Identity                                                GUID
EndS

#Define                                                     CLFS_INFORMATION CLS_INFORMATION

CLS_CLIENT_INFORMATION Struct
    ClfsInfo                                                CLS_INFORMATION
    ClientAttributes                                        DD
    ClientUndoCommitment                                    DQ
    ClientArchiveTailLsn                                    CLS_LSN
    ClientBaseLsn                                           CLS_LSN
    ClientLastLsn                                           CLS_LSN
    ClientRestartLsn                                        CLS_LSN
EndS

#Define                                                     CLFS_CLIENT_INFORMATION CLS_CLIENT_INFORMATION

CLFS_LOG_NAME_INFORMATION Struct
    NameLengthInBytes                                       DW
    Name                                                    DW          1 Dup ?
EndS

CLFS_STREAM_ID_INFORMATION Struct
    StreamIdentifier                                        DB
EndS

CLFS_PHYSICAL_LSN_INFORMATION Struct
    StreamIdentifier                                        DB
    VirtualLsn                                              CLFS_LSN
    PhysicalLsn                                             CLFS_LSN
EndS

#Define                                                     CLFS_CONTAINER_STATE CLS_CONTAINER_STATE

CLS_CONTAINER_INFORMATION Struct
    FileAttributes                                          DD
    CreationTime                                            DQ
    LastAccessTime                                          DQ
    LastWriteTime                                           DQ
    ContainerSize                                           DQ
    FileNameActualLength                                    DD
    FileNameLength                                          DD
    FileName                                                DW          CLFS_MAX_CONTAINER_INFO Dup ?
    State                                                   CLFS_CONTAINER_STATE
    PhysicalContainerId                                     CLFS_CONTAINER_ID
    LogicalContainerId                                      CLFS_CONTAINER_ID
EndS

#Define                                                     CLFS_CONTAINER_INFORMATION CLS_CONTAINER_INFORMATION

;CLS_IOSTATS_CLASS Enumeration
ClsIoStatsDefault                                           Equ         00000H
ClsIoStatsMax                                               Equ         0FFFFH

;CLFS_IOSTATS_CLASS Enumeration
ClfsIoStatsDefault                                          Equ         00000H
ClfsIoStatsMax                                              Equ         0FFFFH

CLS_IO_STATISTICS_HEADER Struct
    ubMajorVersion                                          DB
    ubMinorVersion                                          DB
    eStatsClass                                             DD
    cbLength                                                DW
    coffData                                                DD
EndS

#Define                                                     CLFS_IO_STATISTICS_HEADER CLS_IO_STATISTICS_HEADER

CLS_IO_STATISTICS Struct
    hdrIoStats                                              CLS_IO_STATISTICS_HEADER
    cFlush                                                  DQ
    cbFlush                                                 DQ
    cMetaFlush                                              DQ
    cbMetaFlush                                             DQ
EndS

#Define                                                     CLFS_IO_STATISTICS CLS_IO_STATISTICS

CLFS_SCAN_INIT                                              Equ         01H
CLFS_SCAN_FORWARD                                           Equ         02H
CLFS_SCAN_BACKWARD                                          Equ         04H
CLFS_SCAN_CLOSE                                             Equ         08H
CLFS_SCAN_INITIALIZED                                       Equ         10H
CLFS_SCAN_BUFFERED                                          Equ         20H

#Define                                                     LOG_FILE_OBJECT FILE_OBJECT

CLS_SCAN_CONTEXT Struct
    cidNode                                                 CLFS_NODE_ID
    plfoLog                                                 DD
    cIndex                                                  DD
    cContainers                                             DD
    cContainersReturned                                     DD
    eScanMode                                               DB
    pinfoContainer                                          DD
EndS

#Define                                                     CLFS_SCAN_CONTEXT CLS_SCAN_CONTEXT

CLS_ARCHIVE_DESCRIPTOR Struct
    coffLow                                                 DQ
    coffHigh                                                DQ
    infoContainer                                           CLS_CONTAINER_INFORMATION
EndS

#Define                                                     CLFS_ARCHIVE_DESCRIPTOR CLS_ARCHIVE_DESCRIPTOR

;CLFS_LOG_ARCHIVE_MODE Enumeration
ClfsLogArchiveEnabled                                       Equ         01H
ClfsLogArchiveDisabled                                      Equ         02H

;CLFS_MGMT_POLICY_TYPE Enumeration
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

CLFS_MGMT_POLICY_VERSION                                    Equ         (01H)

LOG_POLICY_OVERWRITE                                        Equ         (01H)
LOG_POLICY_PERSIST                                          Equ         (02H)

CLFS_MGMT_POLICY Struct
    Version                                                 DD
    LengthInBytes                                           DD
    PolicyFlags                                             DD
    PolicyType                                              CLFS_MGMT_POLICY_TYPE
    PolicyParameters Union
        MaximumSize Struct
            Containers                                      DD
        EndS
        MinimumSize Struct
            Containers                                      DD
        EndS
        NewContainerSize Struct
            SizeInBytes                                     DD
        EndS
        GrowthRate Struct
            AbsoluteGrowthInContainers                      DD
            RelativeGrowthPercentage                        DD
        EndS
        LogTail Struct
            MinimumAvailablePercentage                      DD
            MinimumAvailableContainers                      DD
        EndS
        AutoShrink Struct
            Percentage                                      DD
        EndS
        AutoGrow Struct
            Enabled                                         DD
        EndS
        NewContainerPrefix Struct
            PrefixLengthInBytes                             DW
            PrefixString                                    DW          1 Dup ?
        EndS
        NewContainerSuffix Struct
            NextContainerSuffix                             DQ
        EndS
        NewContainerExtension Struct
            ExtensionLengthInBytes                          DW
            ExtensionString                                 DW          1 Dup ?
        EndS
    EndUnion
EndS

;CLFS_MGMT_NOTIFICATION_TYPE Enumeration
ClfsMgmtAdvanceTailNotification                             Equ         0
ClfsMgmtLogFullHandlerNotification                          Equ         1
ClfsMgmtLogUnpinnedNotification                             Equ         2
ClfsMgmtLogWriteNotification                                Equ         3

CLFS_MGMT_NOTIFICATION Struct
    Notification                                            CLFS_MGMT_NOTIFICATION_TYPE
    Lsn                                                     CLFS_LSN
    LogIsPinned                                             DW
EndS

CLFS_MGMT_CLIENT_REGISTRATION_VERSION                       Equ         (01H)

CLFS_MGMT_CLIENT_REGISTRATION Struct
    Version                                                 DD
    AdvanceTailCallback                                     DD
    AdvanceTailCallbackData                                 DD
    LogGrowthCompleteCallback                               DD
    LogGrowthCompleteCallbackData                           DD
    LogUnpinnedCallback                                     DD
    LogUnpinnedCallbackData                                 DD
EndS

#Define                                                     PCW_VERSION_1 0100H
#Define                                                     PCW_CURRENT_VERSION PCW_VERSION_1

PCW_COUNTER_DESCRIPTOR Struct
    Id                                                      DW
    StructIndex                                             DW
    Offset                                                  DW
    Size                                                    DW
EndS

PCW_DATA Struct
    Data                                                    DD
    Size                                                    DD
EndS

PCW_COUNTER_INFORMATION Struct
    CounterMask                                             DQ
    InstanceMask                                            DD
EndS

PCW_MASK_INFORMATION Struct
    CounterMask                                             DQ
    InstanceMask                                            DD
    InstanceId                                              DD
    CollectMultiple                                         DB
    Buffer                                                  DD
    CancelEvent                                             DD
EndS

PCW_CALLBACK_INFORMATION Union
    AddCounter                                              PCW_COUNTER_INFORMATION
    RemoveCounter                                           PCW_COUNTER_INFORMATION
    EnumerateInstances                                      PCW_MASK_INFORMATION
    CollectData                                             PCW_MASK_INFORMATION
EndUnion

;PCW_CALLBACK_TYPE Enumeration
PcwCallbackAddCounter                                       Equ         0
PcwCallbackRemoveCounter                                    Equ         1
PcwCallbackEnumerateInstances                               Equ         2
PcwCallbackCollectData                                      Equ         3

PCW_REGISTRATION_INFORMATION Struct
    Version                                                 DD
    Name                                                    DD
    CounterCount                                            DD
    Counters                                                DD
    Callback                                                DD
    CallbackContext                                         DD
EndS

PsGetCurrentProcess                                         Equ         IoGetCurrentProcess

KERNEL_STACK_SIZE                                           Equ         12288

KERNEL_LARGE_STACK_SIZE                                     Equ         61440

KERNEL_LARGE_STACK_COMMIT                                   Equ         12288

PF_TEMPORAL_LEVEL_1                                         Equ         1
PF_NON_TEMPORAL_LEVEL_ALL                                   Equ         1

PLABEL_DESCRIPTOR Struct
   EntryPoint                                               DQ
   GlobalPointer                                            DQ
EndS

;WELL_KNOWN_SID_TYPE Enumeration
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
    Ptr                                                     DD
EndUnion

;TABLE_SEARCH_RESULT Enumeration
TableEmptyTree                                              Equ         0
TableFoundNode                                              Equ         1
TableInsertAsLeft                                           Equ         2
TableInsertAsRight                                          Equ         3

;RTL_GENERIC_COMPARE_RESULTS Enumeration
GenericLessThan                                             Equ         0
GenericGreaterThan                                          Equ         1
GenericEqual                                                Equ         2

RTL_BALANCED_LINKS Struct
    Parent                                                  DD
    LeftChild                                               DD
    RightChild                                              DD
    Balance                                                 DB
    Reserved                                                DB          3 Dup ?
EndS

RTL_AVL_TABLE Struct
    BalancedRoot                                            RTL_BALANCED_LINKS
    OrderedPointer                                          DD
    WhichOrderedElement                                     DD
    NumberGenericTableElements                              DD
    DepthOfTree                                             DD
    RestartKey                                              DD
    DeleteCount                                             DD
    CompareRoutine                                          DD
    AllocateRoutine                                         DD
    FreeRoutine                                             DD
    TableContext                                            DD
EndS

RTL_SPLAY_LINKS Struct
    Parent                                                  DD
    LeftChild                                               DD
    RightChild                                              DD
EndS

RTL_GENERIC_TABLE Struct
    TableRoot                                               DD
    InsertOrderList                                         LIST_ENTRY
    OrderedPointer                                          DD
    WhichOrderedElement                                     DD
    NumberGenericTableElements                              DD
    CompareRoutine                                          DD
    AllocateRoutine                                         DD
    FreeRoutine                                             DD
    TableContext                                            DD
EndS

RTL_HASH_ALLOCATED_HEADER                                   Equ         000000001H

RTL_HASH_RESERVED_SIGNATURE                                 Equ         0


RTL_DYNAMIC_HASH_TABLE_ENTRY Struct
    Linkage                                                 LIST_ENTRY
    Signature                                               DD
EndS

RTL_DYNAMIC_HASH_TABLE_CONTEXT Struct
    ChainHead                                               DD
    PrevLinkage                                             DD
    Signature                                               DD
EndS

RTL_DYNAMIC_HASH_TABLE_ENUMERATOR Struct
    HashEntry                                               RTL_DYNAMIC_HASH_TABLE_ENTRY
    ChainHead                                               DD
    BucketIndex                                             DD
EndS

RTL_DYNAMIC_HASH_TABLE Struct
    Flags                                                   DD
    Shift                                                   DD
    TableSize                                               DD
    Pivot                                                   DD
    DivisorMask                                             DD
    NumEntries                                              DD
    NonEmptyBuckets                                         DD
    NumEnumerators                                          DD
    Directory                                               DD
EndS

RTL_STACK_WALKING_MODE_FRAMES_TO_SKIP_SHIFT                 Equ         8

OSVERSIONINFOA Struct
    dwOSVersionInfoSize                                     DD
    dwMajorVersion                                          DD
    dwMinorVersion                                          DD
    dwBuildNumber                                           DD
    dwPlatformId                                            DD
    szCSDVersion                                            DB          128 Dup ?
EndS

OSVERSIONINFOW Struct
    dwOSVersionInfoSize                                     DD
    dwMajorVersion                                          DD
    dwMinorVersion                                          DD
    dwBuildNumber                                           DD
    dwPlatformId                                            DD
    szCSDVersion                                            DW          128 Dup ?
EndS

#IF STRINGS UNICODE
    #Define                                                 OSVERSIONINFO OSVERSIONINFOW
#ELSE
    #Define                                                 OSVERSIONINFO OSVERSIONINFOA
#ENDIF

OSVERSIONINFOEXA Struct
    dwOSVersionInfoSize                                     DD
    dwMajorVersion                                          DD
    dwMinorVersion                                          DD
    dwBuildNumber                                           DD
    dwPlatformId                                            DD
    szCSDVersion                                            DB          128 Dup ?
    wServicePackMajor                                       DW
    wServicePackMinor                                       DW
    wSuiteMask                                              DW
    wProductType                                            DB
    wReserved                                               DB
EndS

OSVERSIONINFOEXW Struct
    dwOSVersionInfoSize                                     DD
    dwMajorVersion                                          DD
    dwMinorVersion                                          DD
    dwBuildNumber                                           DD
    dwPlatformId                                            DD
    szCSDVersion                                            DW          128 Dup ?
    wServicePackMajor                                       DW
    wServicePackMinor                                       DW
    wSuiteMask                                              DW
    wProductType                                            DB
    wReserved                                               DB
EndS

#IF STRINGS UNICODE
    #Define                                                 OSVERSIONINFOEX OSVERSIONINFOEXW
#ELSE
    #Define                                                 OSVERSIONINFOEX OSVERSIONINFOEXA
#ENDIF

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
FILE_CHARACTERISTICS_REMOVAL_POLICY_MASK_EX                 Equ         (FILE_CHARACTERISTICS_EXPECT_ORDERLY_REMOVAL_EX | FILE_CHARACTERISTICS_EXPECT_SURPRISE_REMOVAL_EX)

FILE_CHARACTERISTICS_EXPECT_ORDERLY_REMOVAL_DEPRECATED      Equ         00000200H
FILE_CHARACTERISTICS_EXPECT_SURPRISE_REMOVAL_DEPRECATED     Equ         00000300H
FILE_CHARACTERISTICS_REMOVAL_POLICY_MASK_DEPRECATED         Equ         00000300H

FILE_CHARACTERISTICS_PROPAGATED                             Equ         (FILE_REMOVABLE_MEDIA | FILE_READ_ONLY_DEVICE | FILE_FLOPPY_DISKETTE | FILE_WRITE_ONCE_MEDIA | FILE_DEVICE_SECURE_OPEN)

FILE_ALIGNMENT_INFORMATION Struct
    AlignmentRequirement                                    DD
EndS

FILE_NAME_INFORMATION Struct
    FileNameLength                                          DD
    FileName                                                DW          1 Dup ?
EndS

FILE_ATTRIBUTE_TAG_INFORMATION Struct
    FileAttributes                                          DD
    ReparseTag                                              DD
EndS

FILE_DISPOSITION_INFORMATION Struct
    DeleteFile                                              DB
EndS

FILE_END_OF_FILE_INFORMATION Struct
    EndOfFile                                               LARGE_INTEGER
EndS

FILE_VALID_DATA_LENGTH_INFORMATION Struct
    ValidDataLength                                         LARGE_INTEGER
EndS

FILE_FS_LABEL_INFORMATION Struct
    VolumeLabelLength                                       DD
    VolumeLabel                                             DW          1 Dup ?
EndS

FILE_FS_VOLUME_INFORMATION Struct
    VolumeCreationTime                                      LARGE_INTEGER
    VolumeSerialNumber                                      DD
    VolumeLabelLength                                       DD
    SupportsObjects                                         DB
    VolumeLabel                                             DW          1 Dup ?
EndS

FILE_FS_SIZE_INFORMATION Struct
    TotalAllocationUnits                                    LARGE_INTEGER
    AvailableAllocationUnits                                LARGE_INTEGER
    SectorsPerAllocationUnit                                DD
    BytesPerSector                                          DD
EndS

FILE_FS_FULL_SIZE_INFORMATION Struct
    TotalAllocationUnits                                    LARGE_INTEGER
    CallerAvailableAllocationUnits                          LARGE_INTEGER
    ActualAvailableAllocationUnits                          LARGE_INTEGER
    SectorsPerAllocationUnit                                DD
    BytesPerSector                                          DD
EndS

FILE_FS_OBJECTID_INFORMATION Struct
    ObjectId                                                DB          16 Dup ?
    ExtendedInfo                                            DB          48 Dup ?
EndS

FILE_SEGMENT_ELEMENT Union
    Buffer                                                  DQ
    Alignment                                               DQ
EndUnion

IOCTL_AVIO_ALLOCATE_STREAM                                  Equ         CTL_CODE(FILE_DEVICE_AVIO, 1, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
IOCTL_AVIO_FREE_STREAM                                      Equ         CTL_CODE(FILE_DEVICE_AVIO, 2, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)
IOCTL_AVIO_MODIFY_STREAM                                    Equ         CTL_CODE(FILE_DEVICE_AVIO, 3, METHOD_BUFFERED, FILE_SPECIAL_ACCESS)

;BUS_DATA_TYPE Enumeration
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
    NameLength                                              DD
    Name                                                    DW          1 Dup ?
EndS

KEY_CACHED_INFORMATION Struct
    LastWriteTime                                           LARGE_INTEGER
    TitleIndex                                              DD
    SubKeys                                                 DD
    MaxNameLen                                              DD
    Values                                                  DD
    MaxValueNameLen                                         DD
    MaxValueDataLen                                         DD
    NameLength                                              DD
EndS

KEY_VIRTUALIZATION_INFORMATION Struct
    VirtualizationCandidate                                 DD
    VirtualizationEnabled                                   DD
    VirtualTarget                                           DD
    VirtualStore                                            DD
    VirtualSource                                           DD
    Reserved                                                DD
EndS

NT_TIB Struct
    ExceptionList                                           DD
    StackBase                                               DD
    StackLimit                                              DD
    SubSystemTib                                            DD
    Union
        FiberData                                           DD
        Version                                             DD
    EndUnion
    ArbitraryUserPointer                                    DD
    Self                                                    DD
EndS

NT_TIB32 Struct
    ExceptionList                                           DD
    StackBase                                               DD
    StackLimit                                              DD
    SubSystemTib                                            DD
    Union
        FiberData                                           DD
        Version                                             DD
    EndUnion
    ArbitraryUserPointer                                    DD
    Self                                                    DD
EndS

NT_TIB64 Struct
    ExceptionList                                           DQ
    StackBase                                               DQ
    StackLimit                                              DQ
    SubSystemTib                                            DQ
    Union
        FiberData                                           DQ
        Version                                             DD
    EndUnion
    ArbitraryUserPointer                                    DQ
    Self                                                    DQ
EndS

;PROCESSINFOCLASS Enumeration
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
    PagePriority                                            DD
EndS

PROCESS_WS_WATCH_INFORMATION Struct
    FaultingPc                                              DD
    FaultingVa                                              DD
EndS

PROCESS_BASIC_INFORMATION Struct
    ExitStatus                                              DD
    PebBaseAddress                                          DD
    AffinityMask                                            DD
    BasePriority                                            DD
    UniqueProcessId                                         DD
    InheritedFromUniqueProcessId                            DD
EndS

PROCESS_DEVICEMAP_INFORMATION Struct
    DUMMYUNIONNAME Union
        Set Struct
            DirectoryHandle                                 DD
        EndS
        Query Struct
            DriveMap                                        DD
            DriveType                                       DB          32 Dup ?
        EndS
    EndUnion
EndS

PROCESS_DEVICEMAP_INFORMATION_EX Struct
    DUMMYUNIONNAME Union
        Set Struct
            DirectoryHandle                                 DD
        EndS
        Query Struct
            DriveMap                                        DD
            DriveType                                       DB          32 Dup ?
        EndS
    EndUnion
    Flags                                                   DD
EndS

PROCESS_LUID_DOSDEVICES_ONLY                                Equ         00000001H

PROCESS_SESSION_INFORMATION Struct
    SessionId                                               DD
EndS

PROCESS_HANDLE_TRACING_ENABLE Struct
    Flags                                                   DD
EndS

PROCESS_HANDLE_TRACING_ENABLE_EX Struct
    Flags                                                   DD
    TotalSlots                                              DD
EndS

PROCESS_HANDLE_TRACING_MAX_STACKS                           Equ         16

PROCESS_HANDLE_TRACING_ENTRY Struct
    Handle                                                  DD
    ClientId                                                CLIENT_ID
    Type                                                    DD
    Stacks                                                  DD          PROCESS_HANDLE_TRACING_MAX_STACKS Dup ?
EndS

PROCESS_HANDLE_TRACING_QUERY Struct
    Handle                                                  DD
    TotalTraces                                             DD
    HandleTrace                                             PROCESS_HANDLE_TRACING_ENTRY    1 Dup ?
EndS

QUOTA_LIMITS Struct
    PagedPoolLimit                                          DD
    NonPagedPoolLimit                                       DD
    MinimumWorkingSetSize                                   DD
    MaximumWorkingSetSize                                   DD
    PagefileLimit                                           DD
    TimeLimit                                               LARGE_INTEGER
EndS

QUOTA_LIMITS_HARDWS_MIN_ENABLE                              Equ         00000001H
QUOTA_LIMITS_HARDWS_MIN_DISABLE                             Equ         00000002H
QUOTA_LIMITS_HARDWS_MAX_ENABLE                              Equ         00000004H
QUOTA_LIMITS_HARDWS_MAX_DISABLE                             Equ         00000008H
QUOTA_LIMITS_USE_DEFAULT_LIMITS                             Equ         00000010H

IO_COUNTERS Struct
    ReadOperationCount                                      DQ
    WriteOperationCount                                     DQ
    OtherOperationCount                                     DQ
    ReadTransferCount                                       DQ
    WriteTransferCount                                      DQ
    OtherTransferCount                                      DQ
EndS

VM_COUNTERS Struct
    PeakVirtualSize                                         DD
    VirtualSize                                             DD
    PageFaultCount                                          DD
    PeakWorkingSetSize                                      DD
    WorkingSetSize                                          DD
    QuotaPeakPagedPoolUsage                                 DD
    QuotaPagedPoolUsage                                     DD
    QuotaPeakNonPagedPoolUsage                              DD
    QuotaNonPagedPoolUsage                                  DD
    PagefileUsage                                           DD
    PeakPagefileUsage                                       DD
EndS

VM_COUNTERS_EX Struct
    PeakVirtualSize                                         DD
    VirtualSize                                             DD
    PageFaultCount                                          DD
    PeakWorkingSetSize                                      DD
    WorkingSetSize                                          DD
    QuotaPeakPagedPoolUsage                                 DD
    QuotaPagedPoolUsage                                     DD
    QuotaPeakNonPagedPoolUsage                              DD
    QuotaNonPagedPoolUsage                                  DD
    PagefileUsage                                           DD
    PeakPagefileUsage                                       DD
    PrivateUsage                                            DD
EndS

MAX_HW_COUNTERS                                             Equ         16
THREAD_PROFILING_FLAG_DISPATCH                              Equ         00000001H

;HARDWARE_COUNTER_TYPE Enumeration
PMCCounter                                                  Equ         0
MaxHardwareCounterType                                      Equ         1

HARDWARE_COUNTER Struct
    Type                                                    DD
    Reserved                                                DD
    Index                                                   DQ
EndS

POOLED_USAGE_AND_LIMITS Struct
    PeakPagedPoolUsage                                      DD
    PagedPoolUsage                                          DD
    PagedPoolLimit                                          DD
    PeakNonPagedPoolUsage                                   DD
    NonPagedPoolUsage                                       DD
    NonPagedPoolLimit                                       DD
    PeakPagefileUsage                                       DD
    PagefileUsage                                           DD
    PagefileLimit                                           DD
EndS

PROCESS_ACCESS_TOKEN Struct
    Token                                                   DD
    Thread                                                  DD
EndS

PROCESS_EXCEPTION_PORT_ALL_STATE_BITS                       Equ         00000003H
PROCESS_EXCEPTION_PORT_ALL_STATE_FLAGS                      Equ         ((1 << PROCESS_EXCEPTION_PORT_ALL_STATE_BITS) - 1)

PROCESS_EXCEPTION_PORT Struct
    ExceptionPortHandle                                     DD
    StateFlags                                              DD
EndS

KERNEL_USER_TIMES Struct
    CreateTime                                              LARGE_INTEGER
    ExitTime                                                LARGE_INTEGER
    KernelTime                                              LARGE_INTEGER
    UserTime                                                LARGE_INTEGER
EndS

PCR_MINOR_VERSION                                           Equ         1
PCR_MAJOR_VERSION                                           Equ         1

KPCR Struct
    Union
        NtTib                                               NT_TIB
        Struct
            Used_ExceptionList                              DD
            Used_StackBase                                  DD
            Spare2                                          DD
            TssCopy                                         DD
            ContextSwitches                                 DD
            SetMemberCopy                                   DD
            Used_Self                                       DD
        EndS
    EndUnion
    SelfPcr                                                 DD
    Prcb                                                    DD
    Irql                                                    DB
    IRR                                                     DD
    IrrActive                                               DD
    IDR                                                     DD
    KdVersionBlock                                          DD
    IDT                                                     DD
    GDT                                                     DD
    TSS                                                     DD
    MajorVersion                                            DW
    MinorVersion                                            DW
    SetMember                                               DD
    StallScaleFactor                                        DD
    SpareUnused                                             DB
    Number                                                  DB
    Spare0                                                  DB
    SecondLevelCacheAssociativity                           DB
    VdmAlert                                                DD
    KernelReserved                                          DD          14 Dup ?
    SecondLevelCacheSize                                    DD
    HalReserved                                             DD          16 Dup ?
Ends

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
ResultNegative                                              Equ         RESULT_NEGATIVE
ResultZero                                                  Equ         RESULT_ZERO
ResultPositive                                              Equ         RESULT_POSITIVE

;SYSTEM_FIRMWARE_TABLE_ACTION Enumeration
SystemFirmwareTable_Enumerate                               Equ         0
SystemFirmwareTable_Get                                     Equ         1

SYSTEM_FIRMWARE_TABLE_INFORMATION Struct
    ProviderSignature                                       DD
    Action                                                  DD
    TableID                                                 DD
    TableBufferLength                                       DD
    TableBuffer                                             DB          ANYSIZE_ARRAY Dup ?
EndS

;TIMER_SET_INFORMATION_CLASS Enumeration
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
SHARED_GLOBAL_FLAGS_ERROR_PORT                              Equ         (1 << SHARED_GLOBAL_FLAGS_ERROR_PORT_V)

SHARED_GLOBAL_FLAGS_ELEVATION_ENABLED_V                     Equ         1H
SHARED_GLOBAL_FLAGS_ELEVATION_ENABLED                       Equ         (1 << SHARED_GLOBAL_FLAGS_ELEVATION_ENABLED_V)

SHARED_GLOBAL_FLAGS_VIRT_ENABLED_V                          Equ         2H
SHARED_GLOBAL_FLAGS_VIRT_ENABLED                            Equ         (1 << SHARED_GLOBAL_FLAGS_VIRT_ENABLED_V)

SHARED_GLOBAL_FLAGS_INSTALLER_DETECT_ENABLED_V              Equ         3H
SHARED_GLOBAL_FLAGS_INSTALLER_DETECT_ENABLED                Equ         (1 << SHARED_GLOBAL_FLAGS_INSTALLER_DETECT_ENABLED_V)

SHARED_GLOBAL_FLAGS_SPARE_V                                 Equ         4H
SHARED_GLOBAL_FLAGS_SPARE                                   Equ         (1 << SHARED_GLOBAL_FLAGS_SPARE_V)

SHARED_GLOBAL_FLAGS_DYNAMIC_PROC_ENABLED_V                  Equ         5H
SHARED_GLOBAL_FLAGS_DYNAMIC_PROC_ENABLED                    Equ         (1 << SHARED_GLOBAL_FLAGS_DYNAMIC_PROC_ENABLED_V)

SHARED_GLOBAL_FLAGS_SEH_VALIDATION_ENABLED_V                Equ         6H
SHARED_GLOBAL_FLAGS_SEH_VALIDATION_ENABLED                  Equ         (1 << SHARED_GLOBAL_FLAGS_SEH_VALIDATION_ENABLED_V)

CmResourceTypeMaximum                                       Equ         8

CM_PCCARD_DEVICE_DATA Struct
    Flags                                                   DB
    ErrorCode                                               DB
    Reserved                                                DW
    BusData                                                 DD
    DeviceId                                                DD
    LegacyBaseAddress                                       DD
    IRQMap                                                  DB          16 Dup ?
EndS

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
    SegmentList                                             SINGLE_LIST_ENTRY
    Reserved                                                DD
EndS

ZONE_HEADER Struct
    FreeList                                                SINGLE_LIST_ENTRY
    SegmentList                                             SINGLE_LIST_ENTRY
    BlockSize                                               DD
    TotalSegmentSize                                        DD
EndS

#Define                                                     ExInitializeResource ExInitializeResourceLite
#Define                                                     ExAcquireResourceShared ExAcquireResourceSharedLite
#Define                                                     ExAcquireResourceExclusive ExAcquireResourceExclusiveLite
#Define                                                     ExReleaseResourceForThread ExReleaseResourceForThreadLite
#Define                                                     ExConvertExclusiveToShared ExConvertExclusiveToSharedLite
#Define                                                     ExDeleteResource ExDeleteResourceLite
#Define                                                     ExIsResourceAcquiredExclusive ExIsResourceAcquiredExclusiveLite
#Define                                                     ExIsResourceAcquiredShared ExIsResourceAcquiredSharedLite
#Define                                                     ExIsResourceAcquired ExIsResourceAcquiredSharedLite


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
    BaseAddress                                             PHYSICAL_ADDRESS
    NumberOfBytes                                           LARGE_INTEGER
EndS

;MM_ROTATE_DIRECTION Enumeration
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

IRP_MN_MDL_DPC                                              Equ         (IRP_MN_MDL | IRP_MN_DPC)
IRP_MN_COMPLETE_MDL                                         Equ         (IRP_MN_COMPLETE | IRP_MN_MDL)
IRP_MN_COMPLETE_MDL_DPC                                     Equ         (IRP_MN_COMPLETE_MDL | IRP_MN_DPC)

IRP_MN_QUERY_LEGACY_BUS_INFORMATION                         Equ         18H

IO_CHECK_CREATE_PARAMETERS                                  Equ         0200H
IO_ATTACH_DEVICE                                            Equ         0400H

IO_IGNORE_SHARE_ACCESS_CHECK                                Equ         0800H

;IO_QUERY_DEVICE_DATA_FORMAT Enumeration
IoQueryDeviceIdentifier                                     Equ         0
IoQueryDeviceConfigurationData                              Equ         1
IoQueryDeviceComponentInformation                           Equ         2
IoQueryDeviceMaxData                                        Equ         3

CONTROLLER_OBJECT Struct
    Type                                                    DW
    Size                                                    DW
    ControllerExtension                                     DD
    DeviceWaitQueue                                         KDEVICE_QUEUE
    Spare1                                                  DD
    Spare2                                                  LARGE_INTEGER
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
DRVO_REINIT_REGISTERED                                      Equ         00000008H
DRVO_INITIALIZED                                            Equ         00000010H
DRVO_BOOTREINIT_REGISTERED                                  Equ         00000020H
DRVO_LEGACY_RESOURCES                                       Equ         00000040H

CONFIGURATION_INFORMATION Struct
    DiskCount                                               DD
    FloppyCount                                             DD
    CdRomCount                                              DD
    TapeCount                                               DD
    ScsiPortCount                                           DD
    SerialCount                                             DD
    ParallelCount                                           DD
    AtDiskPrimaryAddressClaimed                             DB
    AtDiskSecondaryAddressClaimed                           DB
    Version                                                 DD
    MediumChangerCount                                      DD
EndS

DISK_SIGNATURE Struct
    PartitionStyle                                          DD
    Union
        Mbr Struct
            Signature                                       DD
            CheckSum                                        DD
        EndS

        Gpt Struct
            DiskId                                          GUID
        EndS
    EndUnion
EndS

TXN_PARAMETER_BLOCK Struct
    Length                                                  DW
    TxFsContext                                             DW
    TransactionObject                                       DD
EndS

TXF_MINIVERSION_DEFAULT_VIEW                                Equ         (0FFFEH)

IO_DRIVER_CREATE_CONTEXT Struct
    Size                                                    DW
    ExtraCreateParameter                                    DD
    DeviceObjectHint                                        DD
    TxnParameters                                           DD
EndS

AGP_TARGET_BUS_INTERFACE_STANDARD Struct
    Size                                                    DW
    Version                                                 DW
    Context                                                 DD
    InterfaceReference                                      DD
    InterfaceDereference                                    DD
    SetBusData                                              DD
    GetBusData                                              DD
    CapabilityID                                            DB
EndS

PNP_LOCATION_INTERFACE Struct
    Size                                                    DW
    Version                                                 DW
    Context                                                 DD
    InterfaceReference                                      DD
    InterfaceDereference                                    DD
    GetLocationString                                       DD
EndS

;ARBITER_ACTION Enumeration
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
    OwningObject                                            DD
    Start                                                   DQ
    End                                                     DQ
EndS

ARBITER_TEST_ALLOCATION_PARAMETERS Struct
    ArbitrationList                                         DD
    AllocateFromCount                                       DD
    AllocateFrom                                            DD
EndS

ARBITER_RETEST_ALLOCATION_PARAMETERS Struct
    ArbitrationList                                         DD
    AllocateFromCount                                       DD
    AllocateFrom                                            DD
EndS

ARBITER_BOOT_ALLOCATION_PARAMETERS Struct
    ArbitrationList                                         DD
EndS

ARBITER_QUERY_ALLOCATED_RESOURCES_PARAMETERS Struct
    AllocatedResources                                      DD
EndS

ARBITER_QUERY_CONFLICT_PARAMETERS Struct
    PhysicalDeviceObject                                    DD
    ConflictingResource                                     DD
    ConflictCount                                           DD
    Conflicts                                               DD
EndS

ARBITER_QUERY_ARBITRATE_PARAMETERS Struct
    ArbitrationList                                         DD
EndS

ARBITER_ADD_RESERVED_PARAMETERS Struct
    ReserveDevice                                           DD
EndS

ARBITER_PARAMETERS Struct
    Parameters Union
        TestAllocation                                      ARBITER_TEST_ALLOCATION_PARAMETERS
        RetestAllocation                                    ARBITER_RETEST_ALLOCATION_PARAMETERS
        BootAllocation                                      ARBITER_BOOT_ALLOCATION_PARAMETERS
        QueryAllocatedResources                             ARBITER_QUERY_ALLOCATED_RESOURCES_PARAMETERS
        QueryConflict                                       ARBITER_QUERY_CONFLICT_PARAMETERS
        QueryArbitrate                                      ARBITER_QUERY_ARBITRATE_PARAMETERS
        AddReserved                                         ARBITER_ADD_RESERVED_PARAMETERS
    EndUnion
EndS

;ARBITER_REQUEST_SOURCE Enumeration
ArbiterRequestUndefined                                     Equ         (-1)
ArbiterRequestLegacyReported                                Equ         0
ArbiterRequestHalReported                                   Equ         1
ArbiterRequestLegacyAssigned                                Equ         2
ArbiterRequestPnpDetected                                   Equ         3
ArbiterRequestPnpEnumerated                                 Equ         4

;ARBITER_RESULT Enumeration
ArbiterResultUndefined                                      Equ         (-1)
ArbiterResultSuccess                                        Equ         0
ArbiterResultExternalConflict                               Equ         1
ArbiterResultNullRequest                                    Equ         2

ARBITER_FLAG_BOOT_CONFIG                                    Equ         00000001H

ARBITER_LIST_ENTRY Struct
    ListEntry                                               LIST_ENTRY
    AlternativeCount                                        DD
    Alternatives                                            DD
    PhysicalDeviceObject                                    DD
    RequestSource                                           DD
    Flags                                                   DD
    WorkSpace                                               DD
    InterfaceType                                           DD
    SlotNumber                                              DD
    BusNumber                                               DD
    Assignment                                              DD
    SelectedAlternative                                     DD
    Result                                                  DD
EndS

ARBITER_PARTIAL                                             Equ         00000001H

ARBITER_INTERFACE Struct
    Size                                                    DW
    Version                                                 DW
    Context                                                 DD
    InterfaceReference                                      DD
    InterfaceDereference                                    DD
    ArbiterHandler                                          DD
    Flags                                                   DD
EndS

;RESOURCE_TRANSLATION_DIRECTION Enumeration
TranslateChildToParent                                      Equ         0
TranslateParentToChild                                      Equ         1

TRANSLATOR_INTERFACE Struct
    Size                                                    DW
    Version                                                 DW
    Context                                                 DD
    InterfaceReference                                      DD
    InterfaceDereference                                    DD
    TranslateResources                                      DD
    TranslateResourceRequirements                           DD
EndS

;HAL_QUERY_INFORMATION_CLASS Enumeration
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

;HAL_SET_INFORMATION_CLASS Enumeration
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

PM_DISPATCH_TABLE Struct
    Signature                                               DD
    Version                                                 DD
    Function                                                DD          1 Dup ?
EndS

DEBUG_DEVICE_ADDRESS Struct
    Type                                                    DB
    Valid                                                   DB
    Reserved                                                DB          2 Dup ?
    TranslatedAddress                                       DD
    Length                                                  DD
EndS

DEBUG_MEMORY_REQUIREMENTS Struct
    Start                                                   PHYSICAL_ADDRESS
    MaxEnd                                                  PHYSICAL_ADDRESS
    VirtualAddress                                          DD
    Length                                                  DD
    Cached                                                  DB
    Aligned                                                 DB
EndS

DEBUG_DEVICE_DESCRIPTOR Struct
    Bus                                                     DD
    Segment                                                 DW
    Slot                                                    DD
    VendorID                                                DW
    DeviceID                                                DW
    BaseClass                                               DB
    SubClass                                                DB
    ProgIf                                                  DB
    Initialized                                             DB
    Configured                                              DB
    BaseAddress                                             DEBUG_DEVICE_ADDRESS    6 Dup ?
    Memory                                                  DEBUG_MEMORY_REQUIREMENTS
EndS

HAL_BUS_INFORMATION Struct
    BusType                                                 DD
    ConfigurationType                                       DD
    BusNumber                                               DD
    Reserved                                                DD
EndS

HAL_PROFILE_SOURCE_INFORMATION Struct
    Source                                                  DD
    Supported                                               DB
    Interval                                                DD
EndS

HAL_PROFILE_SOURCE_INFORMATION_EX Struct
    Source                                                  DD
    Supported                                               DB
    Interval                                                DD
    DefInterval                                             DD
    MaxInterval                                             DD
    MinInterval                                             DD
EndS

HAL_PROFILE_SOURCE_INTERVAL Struct
    Source                                                  DD
    Interval                                                DD
EndS

HAL_PROFILE_SOURCE_LIST Struct
    Source                                                  DD
    Description                                             DD
EndS

;HAL_DISPLAY_BIOS_INFORMATION Enumeration
HalDisplayInt10Bios                                         Equ         0
HalDisplayEmulatedBios                                      Equ         1
HalDisplayNoBios                                            Equ         2

HAL_POWER_INFORMATION Struct
    TBD                                                     DD
EndS

HAL_PROCESSOR_SPEED_INFORMATION Struct
    ProcessorSpeed                                          DD
EndS

HAL_CALLBACKS Struct
    SetSystemInformation                                    DD
    BusCheck                                                DD
EndS

HAL_PROCESSOR_FEATURE Struct
    UsableFeatureBits                                       DD
EndS

HAL_AMLI_BAD_IO_ADDRESS_LIST Struct
    BadAddrBegin                                            DD
    BadAddrSize                                             DD
    OSVersionTrigger                                        DD
    IOHandler                                               DD
EndS

HAL_MCA_INTERFACE Struct
    Lock                                                    DD
    Unlock                                                  DD
    ReadRegister                                            DD
EndS

;HAL_APIC_DESTINATION_MODE Enumeration
ApicDestinationModePhysical                                 Equ         1
ApicDestinationModeLogicalFlat                              Equ         2
ApicDestinationModeLogicalClustered                         Equ         3
ApicDestinationModeUnknown                                  Equ         4

MCA_DRIVER_INFO Struct
    ExceptionCallback                                       DD
    DpcCallback                                             DD
    DeviceContext                                           DD
EndS

HAL_ERROR_INFO Struct
    Version                                                 DD
    InitMaxSize                                             DD
    McaMaxSize                                              DD
    McaPreviousEventsCount                                  DD
    McaCorrectedEventsCount                                 DD
    McaKernelDeliveryFails                                  DD
    McaDriverDpcQueueFails                                  DD
    McaReserved                                             DD
    CmcMaxSize                                              DD
    CmcPollingInterval                                      DD
    CmcInterruptsCount                                      DD
    CmcKernelDeliveryFails                                  DD
    CmcDriverDpcQueueFails                                  DD
    CmcGetStateFails                                        DD
    CmcClearStateFails                                      DD
    CmcReserved                                             DD
    CmcLogId                                                DQ
    CpeMaxSize                                              DD
    CpePollingInterval                                      DD
    CpeInterruptsCount                                      DD
    CpeKernelDeliveryFails                                  DD
    CpeDriverDpcQueueFails                                  DD
    CpeGetStateFails                                        DD
    CpeClearStateFails                                      DD
    CpeInterruptSources                                     DD
    CpeLogId                                                DQ
    KernelReserved                                          DQ          4 Dup ?
EndS

#Define                                                     HAL_MCE_INTERRUPTS_BASED (-1)
#Define                                                     HAL_MCE_DISABLED (0)

#Define                                                     HAL_CMC_INTERRUPTS_BASED HAL_MCE_INTERRUPTS_BASED
#Define                                                     HAL_CMC_DISABLED HAL_MCE_DISABLED

#Define                                                     HAL_CPE_INTERRUPTS_BASED HAL_MCE_INTERRUPTS_BASED
#Define                                                     HAL_CPE_DISABLED HAL_MCE_DISABLED

#Define                                                     HAL_MCA_INTERRUPTS_BASED HAL_MCE_INTERRUPTS_BASED
#Define                                                     HAL_MCA_DISABLED HAL_MCE_DISABLED

CMC_DRIVER_INFO Struct
    ExceptionCallback                                       DD
    DpcCallback                                             DD
    DeviceContext                                           DD
EndS

CPE_DRIVER_INFO Struct
    ExceptionCallback                                       DD
    DpcCallback                                             DD
    DeviceContext                                           DD
EndS

HAL_PLATFORM_INFORMATION Struct
    PlatformFlags                                           DD
EndS

HAL_PLATFORM_DISABLE_WRITE_COMBINING                        Equ         01H
HAL_PLATFORM_DISABLE_PTCG                                   Equ         04H
HAL_PLATFORM_DISABLE_UC_MAIN_MEMORY                         Equ         08H
HAL_PLATFORM_ENABLE_WRITE_COMBINING_MMIO                    Equ         10H
HAL_PLATFORM_ACPI_TABLES_CACHED                             Equ         20H

;PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR_TYPE Enumeration
ResourceTypeSingle                                          Equ         0
ResourceTypeRange                                           Equ         1
ResourceTypeExtendedCounterConfiguration                    Equ         2
ResourceTypeOverflow                                        Equ         3
ResourceTypeMax                                             Equ         4

PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR Struct
    Type                                                    DD
    Flags                                                   DD
    u Union
        CounterIndex                                        DD
        ExtendedRegisterAddress                             DD
        Range Struct
            Begin                                           DD
            End                                             DD
        EndS
    EndUnion
EndS

PHYSICAL_COUNTER_RESOURCE_LIST Struct
    Count                                                   DD
    Descriptors                                             PHYSICAL_COUNTER_RESOURCE_DESCRIPTOR ANYSIZE_ARRAY Dup ?
EndS

;EXTENDED_AGP_REGISTER Enumeration
IsochStatus                                                 Equ         0
AgpControl                                                  Equ         1
ApertureSize                                                Equ         2
AperturePageSize                                            Equ         3
GartLow                                                     Equ         4
GartHigh                                                    Equ         5
IsochCommand                                                Equ         6

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
    Header                                                  PCI_CAPABILITIES_HEADER
    Reserved                                                DW
    SubVendorID                                             DW
    SubSystemID                                             DW
EndS

OSC_FIRMWARE_FAILURE                                        Equ         02H
OSC_UNRECOGNIZED_UUID                                       Equ         04H
OSC_UNRECOGNIZED_REVISION                                   Equ         08H
OSC_CAPABILITIES_MASKED                                     Equ         10H

PCI_ROOT_BUS_OSC_METHOD_CAPABILITY_REVISION                 Equ         01H

;PCI_HARDWARE_INTERFACE Enumeration
PciConventional                                             Equ         1
PciXMode1                                                   Equ         2
PciXMode2                                                   Equ         3
PciExpress                                                  Equ         4

;PCI_BUS_WIDTH Enumeration
BusWidth32Bits                                              Equ         0
BusWidth64Bits                                              Equ         1

PCI_EXPRESS_AER_DEVICE_CONTROL_MASK                         Equ         07H

PCI_EXPRESS_AER_DEVICE_STATUS_MASK                          Equ         0FH

;PCI_EXPRESS_MRL_STATE Enumeration
MRLClosed                                                   Equ         0
MRLOpen                                                     Equ         1

;PCI_EXPRESS_CARD_PRESENCE Enumeration
SlotEmpty                                                   Equ         0
CardPresent                                                 Equ         1

;PCI_EXPRESS_INDICATOR_STATE Enumeration
IndicatorOn                                                 Equ         1
IndicatorBlink                                              Equ         2
IndicatorOff                                                Equ         2

;PCI_EXPRESS_POWER_STATE Enumeration
PowerOn                                                     Equ         0
PowerOff                                                    Equ         1

;PCI_EXPRESS_ASPM_SUPPORT Enumeration
L0sEntrySupport                                             Equ         1
L0sAndL1EntrySupport                                        Equ         3

;PCI_EXPRESS_ASPM_CONTROL Enumeration
L0sAndL1EntryDisabled                                       Equ         0
L0sEntryEnabled                                             Equ         1
L1EntryEnabled                                              Equ         2
L0sAndL1EntryEnabled                                        Equ         3

;PCI_EXPRESS_L0s_EXIT_LATENCY Enumeration
L0s_Below64ns                                               Equ         0
L0s_64ns_128ns                                              Equ         1
L0s_128ns_256ns                                             Equ         2
L0s_256ns_512ns                                             Equ         3
L0s_512ns_1us                                               Equ         4
L0s_1us_2us                                                 Equ         5
L0s_2us_4us                                                 Equ         6
L0s_Above4us                                                Equ         7

;PCI_EXPRESS_L1_EXIT_LATENCY Enumeration
L1_Below1us                                                 Equ         0
L1_1us_2us                                                  Equ         1
L1_2us_4us                                                  Equ         2
L1_4us_8us                                                  Equ         3
L1_8us_16us                                                 Equ         4
L1_16us_32us                                                Equ         5
L1_32us_64us                                                Equ         6
L1_Above64us                                                Equ         7

;PCI_EXPRESS_DEVICE_TYPE Enumeration
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
MaxPayload128Bytes                                          Equ         0
MaxPayload256Bytes                                          Equ         1
MaxPayload512Bytes                                          Equ         2
MaxPayload1024Bytes                                         Equ         3
MaxPayload2048Bytes                                         Equ         4
MaxPayload4096Bytes                                         Equ         5

#Define                                                     PCI_DATA_TAG " ICP"
#Define                                                     PCI_DATA_VERSION 1

PCI_BUS_INTERFACE_STANDARD Struct
    Size                                                    DW
    Version                                                 DW
    Context                                                 DD
    InterfaceReference                                      DD
    InterfaceDereference                                    DD
    ReadConfig                                              DD
    WriteConfig                                             DD
    PinToLine                                               DD
    LineToPin                                               DD
    RootBusCapability                                       DD
    ExpressWakeControl                                      DD
EndS

PCI_BUS_INTERFACE_STANDARD_VERSION                          Equ         1

;WHEA_ERROR_SOURCE_TYPE Enumeration
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

;WHEA_ERROR_SOURCE_STATE Enumeration
WheaErrSrcStateStopped                                      Equ         01H
WheaErrSrcStateStarted                                      Equ         02H

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
    Type                                                    DW
    Enabled                                                 DB
EndS

WHEA_IPF_MCA_DESCRIPTOR Struct
    Type                                                    DW
    Enabled                                                 DB
    Reserved                                                DB
EndS

WHEA_IPF_CMC_DESCRIPTOR Struct
    Type                                                    DW
    Enabled                                                 DB
    Reserved                                                DB
EndS

WHEA_IPF_CPE_DESCRIPTOR Struct
    Type                                                    DW
    Enabled                                                 DB
    Reserved                                                DB
EndS

WHEA_REVISION Union
    DUMMYSTRUCTNAME Struct
        MinorRevision                                       DB
        MajorRevision                                       DB
    EndS
    AsUSHORT                                                DW
EndUnion

;WHEA_ERROR_SEVERITY Enumeration
WheaErrSevRecoverable                                       Equ         0
WheaErrSevFatal                                             Equ         1
WheaErrSevCorrected                                         Equ         2
WheaErrSevInformational                                     Equ         3

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

#Define                                                     WHEA_ERROR_RECORD_SIGNATURE "REPC"
#Define                                                     WHEA_ERROR_RECORD_REVISION 0210H
#Define                                                     WHEA_ERROR_RECORD_SIGNATURE_END 0FFFFFFFFH

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
    _Eax                                                    DD
    _Ebx                                                    DD
    _Ecx                                                    DD
    _Edx                                                    DD
    _Esi                                                    DD
    _Edi                                                    DD
    _Ebp                                                    DD
    _Esp                                                    DD
    _Cs                                                     DW
    _Ds                                                     DW
    _Ss                                                     DW
    _Es                                                     DW
    _Fs                                                     DW
    _Gs                                                     DW
    Eflags                                                  DD
    Eip                                                     DD
    _Cr0                                                    DD
    Cr1                                                     DD
    _Cr2                                                    DD
    _Cr3                                                    DD
    _Cr4                                                    DD
    Gdtr                                                    DQ
    Idtr                                                    DQ
    Ldtr                                                    DW
    Tr                                                      DW
EndS

WHEA128A Struct
    Low                                                     DQ
    High                                                    DQ
EndS

WHEA_X64_REGISTER_STATE Struct
    Rax                                                     DQ
    Rbx                                                     DQ
    Rcx                                                     DQ
    Rdx                                                     DQ
    Rsi                                                     DQ
    Rdi                                                     DQ
    Rbp                                                     DQ
    Rsp                                                     DQ
    R8                                                      DQ
    R9                                                      DQ
    R10                                                     DQ
    R11                                                     DQ
    R12                                                     DQ
    R13                                                     DQ
    R14                                                     DQ
    R15                                                     DQ
    _Cs                                                     DW
    _Ds                                                     DW
    _Ss                                                     DW
    _Es                                                     DW
    _Fs                                                     DW
    _Gs                                                     DW
    Reserved                                                DD
    Rflags                                                  DQ
    Eip                                                     DQ
    _Cr0                                                    DQ
    Cr1                                                     DQ
    _Cr2                                                    DQ
    _Cr3                                                    DQ
    _Cr4                                                    DQ
    Cr8                                                     DQ
    Gdtr                                                    WHEA128A
    Idtr                                                    WHEA128A
    Ldtr                                                    DW
    Tr                                                      DW
EndS

XPF_CONTEXT_INFO_UNCLASSIFIEDDATA                           Equ         0
XPF_CONTEXT_INFO_MSRREGISTERS                               Equ         1
XPF_CONTEXT_INFO_32BITCONTEXT                               Equ         2
XPF_CONTEXT_INFO_64BITCONTEXT                               Equ         3
XPF_CONTEXT_INFO_FXSAVE                                     Equ         4
XPF_CONTEXT_INFO_32BITDEBUGREGS                             Equ         5
XPF_CONTEXT_INFO_64BITDEBUGREGS                             Equ         6
XPF_CONTEXT_INFO_MMREGISTERS                                Equ         7

WHEA_XPF_CONTEXT_INFO Struct
    RegisterContextType                                     DW
    RegisterDataSize                                        DW
    MSRAddress                                              DD
    MmRegisterAddress                                       DQ
EndS

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
    DUMMYSTRUCTNAME Struct
        MinorVersion                                        DB
        MajorVersion                                        DB
        Reserved                                            DW
    EndS
    AsULONG                                                 DD
EndUnion

WHEA_PCIEXPRESS_COMMAND_STATUS Union
    DUMMYSTRUCTNAME Struct
        Command                                             DW
        Status                                              DW
    EndS
    AsULONG                                                 DD
EndUnion

WHEA_PCIEXPRESS_BRIDGE_CONTROL_STATUS Union
    DUMMYSTRUCTNAME Struct
        BridgeSecondaryStatus                               DW
        BridgeControl                                       DW
    EndS
    AsULONG                                                 DD
EndUnion

;WHEA_PCIEXPRESS_DEVICE_TYPE Enumeration
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
    DUMMYSTRUCTNAME Struct
        BusNumber                                           DW
        BusSegment                                          DW
    EndS
    AsUSHORT                                                DW
EndUnion

WHEA_PCIXDEVICE_REGISTER_PAIR Struct
    Register                                                DQ
    Data                                                    DQ
EndS

WHEA_FIRMWARE_RECORD_TYPE_IPFSAL                            Equ         0

WHEA_FIRMWARE_ERROR_RECORD_REFERENCE Struct
    _Type                                                   DB
    Reserved                                                DB          7 Dup ?
    FirmwareRecordId                                        DQ
EndS

;WHEA_CPU_VENDOR Enumeration
WheaCpuVendorOther                                          Equ         0
WheaCpuVendorIntel                                          Equ         1
WheaCpuVendorAmd                                            Equ         2

WHEA_XPF_MCA_EXTREG_MAX_COUNT                               Equ         24
WHEA_XPF_MCA_SECTION_VERSION                                Equ         1

DEFINE_GUID     (CMC_NOTIFY_TYPE_GUID,                       02DCE8BB1H, 0BDD7H, 0450EH, 0B9H, 0ADH, 09CH, 0F4H, 0EBH, 0D4H, 0F8H, 090H)
DEFINE_GUID     (CPE_NOTIFY_TYPE_GUID,                       04E292F96H, 0D843H, 04A55H, 0A8H, 0C2H, 0D4H, 081H, 0F2H, 07EH, 0BEH, 0EEH)
DEFINE_GUID     (MCE_NOTIFY_TYPE_GUID,                       0E8F56FFEH, 0919CH, 04CC5H, 0BAH, 088H, 065H, 0ABH, 0E1H, 049H, 013H, 0BBH)
DEFINE_GUID     (PCIe_NOTIFY_TYPE_GUID,                      0CF93C01FH, 01A16H, 04DFCH, 0B8H, 0BCH, 09CH, 04DH, 0AFH, 067H, 0C1H, 004H)
DEFINE_GUID     (INIT_NOTIFY_TYPE_GUID,                      0CC5263E8H, 09308H, 0454AH, 089H, 0D0H, 034H, 00BH, 0D3H, 09BH, 0C9H, 08EH)
DEFINE_GUID     (NMI_NOTIFY_TYPE_GUID,                       05BAD89FFH, 0B7E6H, 042C9H, 081H, 04AH, 0CFH, 024H, 085H, 0D6H, 0E9H, 08AH)
DEFINE_GUID     (BOOT_NOTIFY_TYPE_GUID,                      03D61A466H, 0AB40H, 0409AH, 0A6H, 098H, 0F3H, 062H, 0D4H, 064H, 0B3H, 08FH)
DEFINE_GUID     (PROCESSOR_GENERIC_ERROR_SECTION_GUID,       09876CCADH, 047B4H, 04BDBH, 0B6H, 05EH, 016H, 0F1H, 093H, 0C4H, 0F3H, 0DBH)
DEFINE_GUID     (XPF_PROCESSOR_ERROR_SECTION_GUID,           0DC3EA0B0H, 0A144H, 04797H, 0B9H, 05BH, 053H, 0FAH, 024H, 02BH, 06EH, 01DH)
DEFINE_GUID     (IPF_PROCESSOR_ERROR_SECTION_GUID,           0E429FAF1H, 03CB7H, 011D4H, 0BCH, 0A7H, 000H, 080H, 0C7H, 03CH, 088H, 081H)
DEFINE_GUID     (MEMORY_ERROR_SECTION_GUID,                  0A5BC1114H, 06F64H, 04EDEH, 0B8H, 063H, 03EH, 083H, 0EDH, 07CH, 083H, 0B1H)
DEFINE_GUID     (PCIEXPRESS_ERROR_SECTION_GUID,              0D995E954H, 0BBC1H, 0430FH, 0ADH, 091H, 0B4H, 04DH, 0CBH, 03CH, 06FH, 035H)
DEFINE_GUID     (PCIXBUS_ERROR_SECTION_GUID,                 0C5753963H, 03B84H, 04095H, 0BFH, 078H, 0EDH, 0DAH, 0D3H, 0F9H, 0C9H, 0DDH)
DEFINE_GUID     (PCIXDEVICE_ERROR_SECTION_GUID,              0EB5E4685H, 0CA66H, 04769H, 0B6H, 0A2H, 026H, 006H, 08BH, 000H, 013H, 026H)
DEFINE_GUID     (FIRMWARE_ERROR_RECORD_REFERENCE_GUID,       081212A96H, 009EDH, 04996H, 094H, 071H, 08DH, 072H, 09CH, 08EH, 069H, 0EDH)

DEFINE_GUID     (WHEA_CACHECHECK_GUID,                       0A55701F5H, 0E3EFH, 043DEH, 0ACH, 072H, 024H, 09BH, 057H, 03FH, 0ADH, 02CH)
DEFINE_GUID     (WHEA_TLBCHECK_GUID,                         0FC06B535H, 05E1FH, 04562H, 09FH, 025H, 00AH, 03BH, 09AH, 0DBH, 063H, 0C3H)
DEFINE_GUID     (WHEA_BUSCHECK_GUID,                         01CF3F8B3H, 0C5B1H, 049A2H, 0AAH, 059H, 05EH, 0EFH, 092H, 0FFH, 0A6H, 03CH)
DEFINE_GUID     (WHEA_MSCHECK_GUID,                          048AB7F57H, 0DC34H, 04F6CH, 0A7H, 0D3H, 0B0H, 0B5H, 0B0H, 0A7H, 043H, 014H)

DEFINE_GUID     (WHEA_RECORD_CREATOR_GUID,                   0CF07C4BDH, 0B789H, 04E18H, 0B3H, 0C4H, 01FH, 073H, 02CH, 0B5H, 071H, 031H)

DEFINE_GUID     (GENERIC_NOTIFY_TYPE_GUID,                   03E62A467H, 0AB40H, 0409AH, 0A6H, 098H, 0F3H, 062H, 0D4H, 064H, 0B3H, 08FH)

DEFINE_GUID     (IPF_SAL_RECORD_SECTION_GUID,                06F3380D1H, 06EB0H, 0497FH, 0A5H, 078H, 04DH, 04CH, 065H, 0A7H, 016H, 017H)
DEFINE_GUID     (XPF_MCA_SECTION_GUID,                       08A1E1D01H, 042F9H, 04557H, 09CH, 033H, 056H, 05EH, 05CH, 0C3H, 0F7H, 0E8H)
DEFINE_GUID     (NMI_SECTION_GUID,                           0E71254E7H, 0C1B9H, 04940H, 0ABH, 076H, 090H, 097H, 003H, 0A4H, 032H, 00FH)
DEFINE_GUID     (GENERIC_SECTION_GUID,                       0E71254E8H, 0C1B9H, 04940H, 0ABH, 076H, 090H, 097H, 003H, 0A4H, 032H, 00FH)
DEFINE_GUID     (WHEA_ERROR_PACKET_SECTION_GUID,             0E71254E9H, 0C1B9H, 04940H, 0ABH, 076H, 090H, 097H, 003H, 0A4H, 032H, 00FH)

;WHEA_ERROR_TYPE Enumeration
WheaErrTypeProcessor                                        Equ         0
WheaErrTypeMemory                                           Equ         1
WheaErrTypePCIExpress                                       Equ         2
WheaErrTypeNMI                                              Equ         3
WheaErrTypePCIXBus                                          Equ         4
WheaErrTypePCIXDevice                                       Equ         5
WheaErrTypeGeneric                                          Equ         6

;WHEA_ERROR_PACKET_DATA_FORMAT Enumeration
WheaDataFormatIPFSalRecord                                  Equ         0
WheaDataFormatXPFMCA                                        Equ         1
WheaDataFormatMemory                                        Equ         2
WheaDataFormatPCIExpress                                    Equ         3
WheaDataFormatNMIPort                                       Equ         4
WheaDataFormatPCIXBus                                       Equ         5
WheaDataFormatPCIXDevice                                    Equ         6
WheaDataFormatGeneric                                       Equ         7
WheaDataFormatMax                                           Equ         8

;WHEA_RAW_DATA_FORMAT Enumeration
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

#Define                                                     WHEA_ERROR_PACKET_V1_SIGNATURE "tPrE"
#Define                                                     WHEA_ERROR_PACKET_V1_VERSION 2

#Define                                                     WHEA_ERROR_PACKET_V2_SIGNATURE "AEHW"
#Define                                                     WHEA_ERROR_PACKET_V2_VERSION 3

WHEA_GENERIC_ERROR_DATA_ENTRY Struct
    SectionType                                             GUID
    ErrorSeverity                                           DD
    Revision                                                WHEA_REVISION
    ValidBits                                               DB
    Flags                                                   DB
    ErrorDataLength                                         DD
    FRUId                                                   GUID
    FRUText                                                 DB          20 Dup ?
    Data                                                    DB          1 Dup ?
EndS

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
    GetAllErrorSources                                      DD
    Reserved                                                DD
    GetErrorSourceInfo                                      DD
    SetErrorSourceInfo                                      DD
    EnableErrorSource                                       DD
    DisableErrorSource                                      DD
    WriteErrorRecord                                        DD
    ReadErrorRecord                                         DD
    ClearErrorRecord                                        DD
    RetrieveErrorInfo                                       DD
    FinalizeErrorRecord                                     DD
    ClearErrorStatus                                        DD
    AttemptRecovery                                         DD
    GetInjectionCapabilities                                DD
    InjectError                                             DD
EndS

WHEA_PSHED_PLUGIN_REGISTRATION_PACKET Struct
    Length                                                  DD
    Version                                                 DD
    Context                                                 DD
    FunctionalAreaMask                                      DD
    Reserved                                                DD
    Callbacks                                               WHEA_PSHED_PLUGIN_CALLBACKS
EndS

WHEA_PLUGIN_REGISTRATION_PACKET_VERSION                     Equ         00010000H

PshedFADiscovery                                            Equ         00000001H
PshedFAErrorSourceControl                                   Equ         00000002H
PshedFAErrorRecordPersistence                               Equ         00000004H
PshedFAErrorInfoRetrieval                                   Equ         00000008H
PshedFAErrorRecovery                                        Equ         00000010H
PshedFAErrorInjection                                       Equ         00000020H

WHEA_WRITE_FLAG_DUMMY                                       Equ         00000001H

#Include undoc.h

#ENDIF ;NTDDK_H
