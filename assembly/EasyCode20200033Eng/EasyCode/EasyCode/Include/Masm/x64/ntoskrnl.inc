; ======================================================;
;                                                       ;
;  ntoskrnl.inc for Easy Code 2.0 64-bit Masm projects  ;
;                  (version 1.0.5)                      ;
;                                                       ;
;          Copyright © Ramon Sala - 2015-2020           ;
;                                                       ;
; ======================================================;

IFNDEF NTOSKRNL_INC
NTOSKRNL_INC     EQU     1

IFDEF APP_WIN64
    IFNDEF ALIGNMODE
        IFDEF POASM_COMPILER
            ALIGNMODE                           TEXTEQU <>
        ELSE
            ALIGNMODE                           TEXTEQU <16>
        ENDIF
    ENDIF
    IFNDEF XPTR
        XPTR                                    TYPEDEF QWORD
        XWORD                                   TYPEDEF QWORD
        ENUM                                    TYPEDEF QWORD
    ENDIF
ELSE
    IFNDEF ALIGNMODE
        ALIGNMODE                               TEXTEQU <4>
    ENDIF
    IFNDEF XPTR
        XPTR                                    TYPEDEF DWORD
        XWORD                                   TYPEDEF DWORD
        ENUM                                    TYPEDEF DWORD
    ENDIF
ENDIF

IFNDEF ANYSIZE_ARRAY
    ANYSIZE_ARRAY                               EQU     1
ENDIF

Include macros.inc

FSRTL_FAT_LEGAL                                 EQU     01H
FSRTL_HPFS_LEGAL                                EQU     02H
FSRTL_NTFS_LEGAL                                EQU     04H
FSRTL_WILD_CHARACTER                            EQU     08H
FSRTL_OLE_LEGAL                                 EQU     10H
FSRTL_NTFS_STREAM_LEGAL                         EQU     (FSRTL_NTFS_LEGAL OR FSRTL_OLE_LEGAL)

FSRTL_VOLUME_DISMOUNT                           EQU     1
FSRTL_VOLUME_DISMOUNT_FAILED                    EQU     2
FSRTL_VOLUME_LOCK                               EQU     3
FSRTL_VOLUME_LOCK_FAILED                        EQU     4
FSRTL_VOLUME_UNLOCK                             EQU     5
FSRTL_VOLUME_MOUNT                              EQU     6
FSRTL_VOLUME_NEEDS_CHKDSK                       EQU     7
FSRTL_VOLUME_WORM_NEAR_FULL                     EQU     8
FSRTL_VOLUME_WEARING_OUT                        EQU     9
FSRTL_VOLUME_FORCED_CLOSED                      EQU     10
FSRTL_VOLUME_INFO_MAKE_COMPAT                   EQU     11
FSRTL_VOLUME_PREPARING_EJECT                    EQU     12
FSRTL_VOLUME_CHANGE_SIZE                        EQU     13
FSRTL_VOLUME_BACKGROUND_FORMAT                  EQU     14

FSRTL_ECP_LOOKASIDE_FLAG_NONPAGED_POOL          EQU     00000002H

FSRTL_UNC_PROVIDER_FLAGS_MAILSLOTS_SUPPORTED    EQU     00000001H
FSRTL_UNC_PROVIDER_FLAGS_CSC_ENABLED            EQU     00000002H
FSRTL_UNC_PROVIDER_FLAGS_DOMAIN_SVC_AWARE       EQU     00000004H

FSRTL_ALLOCATE_ECPLIST_FLAG_CHARGE_QUOTA        EQU     00000001H

FSRTL_ALLOCATE_ECP_FLAG_CHARGE_QUOTA            EQU     00000001H
FSRTL_ALLOCATE_ECP_FLAG_NONPAGED_POOL           EQU     00000002H

FSRTL_ECP_LOOKASIDE_FLAG_NONPAGED_POOL          EQU     00000002H

FSRTL_VIRTDISK_FULLY_ALLOCATED                  EQU     00000001H
FSRTL_VIRTDISK_NO_DRIVE_LETTER                  EQU     00000002H

IO_FORCE_ACCESS_CHECK                           Equ     0001H
IO_NO_PARAMETER_CHECKING                        Equ     0100H

IO_REPARSE                                      Equ     0
IO_REMOUNT                                      Equ     1

;SYSDBG_COMMAND enumeration
SysDbgQueryModuleInformation                    EQU     0
SysDbgQueryTraceInformation                     EQU     1
SysDbgSetTracepoint                             EQU     2
SysDbgSetSpecialCall                            EQU     3
SysDbgClearSpecialCalls                         EQU     4
SysDbgQuerySpecialCalls                         EQU     5
SysDbgBreakPoint                                EQU     6
SysDbgQueryVersion                              EQU     7
SysDbgReadVirtual                               EQU     8
SysDbgWriteVirtual                              EQU     9
SysDbgReadPhysical                              EQU     10
SysDbgWritePhysical                             EQU     11
SysDbgReadControlSpace                          EQU     12
SysDbgWriteControlSpace                         EQU     13
SysDbgReadIoSpace                               EQU     14
SysDbgWriteIoSpace                              EQU     15
SysDbgReadMsr                                   EQU     16
SysDbgWriteMsr                                  EQU     17
SysDbgReadBusData                               EQU     18
SysDbgWriteBusData                              EQU     19
SysDbgCheckLowMemory                            EQU     20
SysDbgEnableKernelDebugger                      EQU     21
SysDbgDisableKernelDebugger                     EQU     22
SysDbgGetAutoKdEnable                           EQU     23
SysDbgSetAutoKdEnable                           EQU     24
SysDbgGetPrintBufferSize                        EQU     25
SysDbgSetPrintBufferSize                        EQU     26
SysDbgGetKdUmExceptionEnable                    EQU     27
SysDbgSetKdUmExceptionEnable                    EQU     28
SysDbgGetTriageDump                             EQU     29
SysDbgGetKdBlockEnable                          EQU     30
SysDbgSetKdBlockEnable                          EQU     31
SysDbgRegisterForUmBreakInfo                    EQU     32
SysDbgGetUmBreakPid                             EQU     33
SysDbgClearUmBreakPid                           EQU     34
SysDbgGetUmAttachPid                            EQU     35
SysDbgClearUmAttachPid                          EQU     36

;PSPROCESSPRIORITYMOD Enumeration
PsProcessPriorityForeground                     EQU     0
PsProcessPriorityBackground                     EQU     1
PsProcessPrioritySpinning                       EQU     2

;JOBOBJECTINFOCLASS Enumeration
JobObjectBasicAccountingInformation             EQU     1
JobObjectBasicLimitInformation                  EQU     2
JobObjectBasicProcessIdList                     EQU     3
JobObjectBasicUIRestrictions                    EQU     4
JobObjectSecurityLimitInformation               EQU     5
JobObjectEndOfJobTimeInformation                EQU     6
JobObjectAssociateCompletionPortInformation     EQU     7
JobObjectBasicAndIoAccountingInformation        EQU     8
JobObjectExtendedLimitInformation               EQU     9
JobObjectJobSetInformation                      EQU     10
MaxJobObjectInfoClass                           EQU     11

;WAIT_TYPE Enumeration
WaitAll                                         EQU     0
WaitAny                                         EQU     1


;======================================== Structures ======================================;
IFNDEF GUID
    GUID STRUCT ALIGNMODE
        Data1   DD  ?
        Data2   DW  ?
        Data3   DW  ?
        Data4   DB  8 DUP(?)
    GUID ENDS
ENDIF

IFNDEF LARGE_INTEGER
    LARGE_INTEGER UNION ALIGNMODE
        STRUCT
            LowPart  DD ?
            HighPart DD ?
        ENDS
        QuadPart     DQ ?
    LARGE_INTEGER ENDS
ENDIF

IFNDEF ULARGE_INTEGER
    ULARGE_INTEGER STRUCT ALIGNMODE
        STRUCT
            LowPart  DD ?
            HighPart DD ?
        ENDS
        QuadPart     DQ ?
    ULARGE_INTEGER ENDS
ENDIF

IFNDEF LUID
    LUID STRUCT ALIGNMODE
        LowPart     DD  ?
        HighPart    DD  ?
    LUID ENDS
ENDIF

IFNDEF STRING_DEFINED
	STRING_DEFINED EQU 1
    STRING STRUCT ALIGNMODE
        _Length         DW   ?
        MaximumLength   DW   ?
        Buffer          XPTR ?
    STRING ENDS
    ANSI_STRING                             TYPEDEF STRING
    OEM_STRING                              TYPEDEF STRING
    PSTRING                                 TYPEDEF XPTR
    POEM_STRING                             TYPEDEF PSTRING
ENDIF


IFNDEF UNICODE_STRING_DEFINED
	UNICODE_STRING_DEFINED EQU 1
    UNICODE_STRING STRUCT ALIGNMODE
        _Length         DW   ?
        MaximumLength   DW   ?
        Buffer          XPTR ?
    UNICODE_STRING      ENDS
    PUNICODE_STRING                         TYPEDEF XPTR
ENDIF

IFNDEF LIST_ENTRY
    LIST_ENTRY STRUCT ALIGNMODE
        Flink   XPTR ?
        Blink   XPTR ?
    LIST_ENTRY ENDS
ENDIF

IFNDEF OWNER_ENTRY
    OWNER_ENTRY STRUCT ALIGNMODE
        OwnerThread     ULONG ?
        UNION
            OwnerCount  LONG  ?
            TableSize   ULONG ?
        ENDS
    OWNER_ENTRY ENDS
ENDIF

IFNDEF ALPC_MESSAGE_ATTRIBUTES
    ALPC_MESSAGE_ATTRIBUTES STRUCT ALIGNMODE
        AllocatedAttributes ULONG  ?
        ValidAttributes     ULONG  ?
    ALPC_MESSAGE_ATTRIBUTES EndS
ENDIF

IFNDEF SYSTEM_PERFORMANCE_INFORMATION
    SYSTEM_PERFORMANCE_INFORMATION STRUCT ALIGNMODE
        IdleProcessTime             LARGE_INTEGER <>
        IoReadTransferCount         LARGE_INTEGER <>
        IoWriteTransferCount        LARGE_INTEGER <>
        IoOtherTransferCount        LARGE_INTEGER <>
        IoReadOperationCount        ULONG   ?
        IoWriteOperationCount       ULONG   ?
        IoOtherOperationCount       ULONG   ?
        AvailablePages              ULONG   ?
        CommittedPages              ULONG   ?
        CommitLimit                 ULONG   ?
        PeakCommitment              ULONG   ?
        PageFaultCount              ULONG   ?
        CopyOnWriteCount            ULONG   ?
        TransitionCount             ULONG   ?
        CacheTransitionCount        ULONG   ?
        DemandZeroCount             ULONG   ?
        PageReadCount               ULONG   ?
        PageReadIoCount             ULONG   ?
        CacheReadCount              ULONG   ?
        CacheIoCount                ULONG   ?
        DirtyPagesWriteCount        ULONG   ?
        DirtyWriteIoCount           ULONG   ?
        MappedPagesWriteCount       ULONG   ?
        MappedWriteIoCount          ULONG   ?
        PagedPoolPages              ULONG   ?
        NonPagedPoolPages           ULONG   ?
        PagedPoolAllocs             ULONG   ?
        PagedPoolFrees              ULONG   ?
        NonPagedPoolAllocs          ULONG   ?
        NonPagedPoolFrees           ULONG   ?
        FreeSystemPtes              ULONG   ?
        ResidentSystemCodePage      ULONG   ?
        TotalSystemDriverPages      ULONG   ?
        TotalSystemCodePages        ULONG   ?
        NonPagedPoolLookasideHits   ULONG   ?
        PagedPoolLookasideHits      ULONG   ?
        Spare3Count                 ULONG   ?
        ResidentSystemCachePage     ULONG   ?
        ResidentPagedPoolPage       ULONG   ?
        ResidentSystemDriverPage    ULONG   ?
        CcFastReadNoWait            ULONG   ?
        CcFastReadWait              ULONG   ?
        CcFastReadResourceMiss      ULONG   ?
        CcFastReadNotPossible       ULONG   ?
        CcFastMdlReadNoWait         ULONG   ?
        CcFastMdlReadWait           ULONG   ?
        CcFastMdlReadResourceMiss   ULONG   ?
        CcFastMdlReadNotPossible    ULONG   ?
        CcMapDataNoWait             ULONG   ?
        CcMapDataWait               ULONG   ?
        CcMapDataNoWaitMiss         ULONG   ?
        CcMapDataWaitMiss           ULONG   ?
        CcPinMappedDataCount        ULONG   ?
        CcPinReadNoWait             ULONG   ?
        CcPinReadWait               ULONG   ?
        CcPinReadNoWaitMiss         ULONG   ?
        CcPinReadWaitMiss           ULONG   ?
        CcCopyReadNoWait            ULONG   ?
        CcCopyReadWait              ULONG   ?
        CcCopyReadNoWaitMiss        ULONG   ?
        CcCopyReadWaitMiss          ULONG   ?
        CcMdlReadNoWait             ULONG   ?
        CcMdlReadWait               ULONG   ?
        CcMdlReadNoWaitMiss         ULONG   ?
        CcMdlReadWaitMiss           ULONG   ?
        CcReadAheadIos              ULONG   ?
        CcLazyWriteIos              ULONG   ?
        CcLazyWritePages            ULONG   ?
        CcDataFlushes               ULONG   ?
        CcDataPages                 ULONG   ?
        ContextSwitches             ULONG   ?
        FirstLevelTbFills           ULONG   ?
        SecondLevelTbFills          ULONG   ?
        SystemCalls                 ULONG   ?
        IF (NTDDI_VERSION GE NTDDI_WIN8)
            CcTotalDirtyPages       UINT64  ?
            CcDirtyPageThreshold    UINT64  ?
            ResidentAvailablePages  INT64   ?
        ENDIF
    SYSTEM_PERFORMANCE_INFORMATION ENDS
ENDIF

ERESOURCE STRUCT ALIGNMODE
    SystemResourcesList LIST_ENTRY  <>
    OwnerTable          XPTR        ?
    ActiveCount         WORD        ?
    Flag                WORD        ?
    SharedWaiters       XPTR        ?
    ExclusiveWaiters    XPTR        ?
    OwnerEntry          OWNER_ENTRY <>
    ActiveEntries       ULONG       ?
    ContentionCount     ULONG       ?
    NumberOfSharedWaiters    ULONG  ?
    NumberOfExclusiveWaiters ULONG  ?
    UNION
          Address            PVOID   ?
          CreatorBackTraceIndex ULONG ?
    ENDS
    SpinLock            ULONG        ?
ERESOURCE ENDS

FSRTL_MUP_PROVIDER_INFO_LEVEL_1 STRUCT ALIGNMODE
    ProviderId  ULONG32 ?
FSRTL_MUP_PROVIDER_INFO_LEVEL_1 ENDS

FSRTL_MUP_PROVIDER_INFO_LEVEL_2 STRUCT ALIGNMODE
  ProviderId    ULONG32 ?
  ProviderName  UNICODE_STRING <>
FSRTL_MUP_PROVIDER_INFO_LEVEL_2 ENDS

IFNDEF IO_DISCONNECT_INTERRUPT_PARAMETERS
    IO_DISCONNECT_INTERRUPT_PARAMETERS STRUCT ALIGNMODE
        Version                     ULONG   ?
        UNION ConnectionContext
            Generic                 PVOID   ?
            InterruptObject         XPTR    ?
            InterruptMessageTable   XPTR    ?
        ENDS
    IO_DISCONNECT_INTERRUPT_PARAMETERS ENDS
ENDIF

IFNDEF LOADER_PARTITION_INFORMATION_EX
    LOADER_PARTITION_INFORMATION_EX STRUCT ALIGNMODE
        PartitionStyle     ULONG   ?
        PartitionNumber    ULONG   ?
        UNION
            Signature      ULONG   ?
            DeviceId       GUID    <>
        EndS
    LOADER_PARTITION_INFORMATION_EX ENDS
ENDIF

BOOTDISK_INFORMATION_LITE STRUCT ALIGNMODE
    NumberEntries  ULONG   ?
    Entries        LOADER_PARTITION_INFORMATION_EX <>
BOOTDISK_INFORMATION_LITE ENDS

IFNDEF PROCESSOR_NUMBER
    PROCESSOR_NUMBER STRUCT ALIGNMODE
        _Group     DW  ?
        Number     DB  ?
        Reserved   DB  ?
    PROCESSOR_NUMBER ENDS
ENDIF

IFNDEF SECTION_OBJECT_POINTERS
    SECTION_OBJECT_POINTERS STRUCT ALIGNMODE
        DataSectionObject  PVOID ?
        SharedCacheMap     PVOID ?
        ImageSectionObject PVOID ?
    SECTION_OBJECT_POINTERS ENDS
ENDIF

IFNDEF OB_CALLBACK_REGISTRATION
    OB_CALLBACK_REGISTRATION STRUCT ALIGNMODE
        Version                     DW    ?
        OperationRegistrationCount  DW    ?
        Altitude                    UNICODE_STRING <>
        RegistrationContext         PVOID ?
        OperationRegistration       XPTR  ?
    OB_CALLBACK_REGISTRATION ENDS
ENDIF

IFNDEF OB_OPERATION_REGISTRATION
    OB_OPERATION_REGISTRATION STRUCT ALIGNMODE
        ObjectType     XPTR    ?
        Operations     XWORD   ?
        PreOperation   XPTR    ?
        PostOperation  XPTR    ?
    OB_OPERATION_REGISTRATION ENDS
ENDIF

PO_FX_COMPONENT STRUCT ALIGNMODE
    Id                         GUID  <>
    IdleStateCount             ULONG ?
    DeepestWakeableIdleState   ULONG ?
    IdleStates                 XPTR  ?
PO_FX_COMPONENT ENDS

PO_FX_COMPONENT_IDLE_STATE STRUCT ALIGNMODE
    TransitionLatency    XWORD   ?
    ResidencyRequirement XWORD   ?
    NominalPower         XWORD   ?
PO_FX_COMPONENT_IDLE_STATE ENDS

PO_FX_DEVICE STRUCT ALIGNMODE
    Version                            ULONG   ?
    ComponentCount                     ULONG   ?
    ComponentActiveConditionCallback   XPTR    ?
    ComponentIdleConditionCallback     XPTR    ?
    ComponentIdleStateCallback         XPTR    ?
    DevicePowerRequiredCallback        XPTR    ?
    DevicePowerNotRequiredCallback     XPTR    ?
    PowerControlCallback               XPTR    ?
    DeviceContext                      PVOID   ?
    Components                         PO_FX_COMPONENT ANYSIZE_ARRAY DUP(<>)
PO_FX_DEVICE ENDS


;======================================== Functions =======================================;
IF (NTDDI_VERSION GE NTDDI_WINNT4)
    IFNDEF atoi
        atoi PROTO :LPSTR
    ENDIF
    IFNDEF atol
        atol PROTO :LPSTR
    ENDIF
    CcCanIWrite PROTO :XWORD, :XWORD, :XWORD, :XWORD
    CcCopyRead PROTO :XPTR, :XPTR, :XWORD, :XWORD, :XPTR, :XPTR
    CcCopyWrite PROTO :XPTR, :XPTR, :XWORD, :XWORD, :XPTR
    CcDeferWrite PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    CcFastCopyRead PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    CcFastCopyWrite PROTO :XWORD, :XWORD, :XWORD, :XWORD
    CcFastMdlReadWait PROTO
    IF (NTDDI_VERSION LT NTDDI_VISTA)
        CcFastReadWait PROTO
    ENDIF
    CcFlushCache PROTO :XPTR, :XPTR, :XWORD, :XPTR
    CcGetDirtyPages PROTO :XPTR, :XPTR, :XPTR, :XPTR
    CcGetFileObjectFromBcb PROTO :XPTR
    CcGetFileObjectFromSectionPtrs PROTO :XPTR
    CcGetLsnForFileObject PROTO :XPTR, :XPTR
    CcInitializeCacheMap PROTO :XPTR, :XPTR, :XWORD, :XPTR, :XPTR
    CcIsThereDirtyData PROTO :XPTR
    CcMapData PROTO :XPTR, :XPTR, :XWORD, :XWORD, :XPTR, :XPTR
    CcMdlRead PROTO :XPTR, :XPTR, :XWORD, :XPTR, :XPTR
    CcMdlReadComplete PROTO :XPTR, :XPTR
    CcMdlWriteComplete PROTO :XPTR, :XPTR, :XPTR
    CcPinMappedData PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    CcPinRead PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    CcPrepareMdlWrite PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    CcPreparePinWrite PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    CcPurgeCacheSection PROTO :XWORD, :XWORD, :XWORD, :XWORD
    CcRepinBcb PROTO :XWORD
    CcScheduleReadAhead PROTO :XWORD, :XWORD, :XWORD
    CcSetAdditionalCacheAttributes PROTO :XWORD, :XWORD, :XWORD
    CcSetBcbOwnerPointer PROTO :XWORD, :XWORD
    CcSetDirtyPageThreshold PROTO :XWORD, :XWORD
    CcSetDirtyPinnedData PROTO :XWORD, :XWORD
    CcSetFileSizes PROTO :XWORD, :XWORD
    CcSetLogHandleForFile PROTO :XWORD, :XWORD, :XWORD
    CcSetReadAheadGranularity PROTO :XWORD, :XWORD
    CcUninitializeCacheMap PROTO :XPTR, :XPTR, :XPTR
    CcUnpinData PROTO :XWORD
    CcUnpinDataForThread PROTO :XWORD, :XWORD
    CcUnpinRepinnedBcb PROTO :XWORD, :XWORD, :XWORD
    CcZeroData PROTO :XWORD, :XWORD, :XWORD, :XWORD
    DbgBreakPoint PROTO
    DbgBreakPointWithStatus PROTO :XWORD
    DbgLoadImageSymbols PROTO :XWORD, :XWORD, :XWORD
    DbgPrint PROTO :XPTR, :VARARG
    DbgPrompt PROTO :XWORD, :XWORD, :XWORD
    ExAcquireFastMutexUnsafe PROTO :XPTR
    ExAcquireResourceExclusiveLite PROTO :XWORD, :XWORD
    ExAcquireResourceSharedLite PROTO :XWORD, :XWORD
    ExAcquireSharedStarveExclusive PROTO :XWORD, :XWORD
    ExAcquireSharedWaitForExclusive PROTO :XWORD, :XWORD
    ExAllocatePool PROTO :XWORD, :XWORD
    ExAllocatePoolWithQuota PROTO :XWORD, :XWORD
    ExAllocatePoolWithQuotaTag PROTO :XWORD, :XWORD, :XWORD
    ExAllocatePoolWithTag PROTO :XWORD, :XWORD, :XWORD
    ExAllocatePoolWithTagPriority PROTO :XWORD, :XWORD, :XWORD, :XWORD
    ExConvertExclusiveToSharedLite PROTO :XWORD
    ExCreateCallback PROTO :XWORD, :XWORD, :XWORD, :XWORD
    ExDeleteNPagedLookasideList PROTO :XWORD
    ExDeletePagedLookasideList PROTO :XWORD
    ExDeleteResourceLite PROTO :XWORD
    ExDisableResourceBoostLite PROTO :XWORD
    ExEnumHandleTable PROTO :XWORD, :XWORD, :XWORD, :XWORD
    ExExtendZone PROTO :XWORD, :XWORD, :XWORD
    ExFreePool PROTO :XWORD
    IF (NTDDI_VERSION LT NTDDI_WIN2K AND NTDDI_VERSION LT NTDDI_WIN8)
        IFNDEF APP_WIN64
            KeQueryInterruptTime PROTO
        ENDIF
    ENDIF
    IF (NTDDI_VERSION LT NTDDI_VISTA)
        KeConnectInterrupt PROTO :XWORD
        KeDisconnectInterrupt PROTO :XWORD
    ELSEIF (NTDDI_VERSION LT NTDDI_WIN7)
        IFNDEF APP_WIN64
            Exfi386InterlockedDecrementLong PROTO :XPTR
            Exfi386InterlockedExchangeUlong PROTO :XPTR, :XWORD
            Exfi386InterlockedIncrementLong PROTO :XPTR
            ExfInterlockedAddUlong PROTO :XWORD, :XWORD, :XWORD
            IF (NTDDI_VERSION GE NTDDI_WINXP)
                ExfInterlockedCompareExchange64 PROTO :XWORD, :XWORD, :XWORD
            ENDIF
            ExfInterlockedInsertHeadList PROTO :XWORD, :XWORD, :XWORD
            ExfInterlockedInsertTailList PROTO :XWORD, :XWORD, :XWORD
            ExfInterlockedPopEntryList PROTO :XWORD, :XWORD
            ExfInterlockedPushEntryList PROTO :XWORD, :XWORD
            ExfInterlockedRemoveHeadList PROTO :XWORD, :XWORD
            ExInterlockedAddLargeStatistic PROTO :XWORD, :XWORD
            ExInterlockedCompareExchange64 PROTO :XWORD, :XWORD, :XWORD
            ExInterlockedFlushSList PROTO :XWORD
            ExInterlockedPopEntrySList PROTO :XWORD, :XWORD
            ExInterlockedPushEntrySList PROTO :XWORD, :XWORD, :XWORD
            IF (NTDDI_VERSION EQ NTDDI_VISTA)
                ExiReleaseFastMutex PROTO :XPTR
                ExiTryToAcquireFastMutex PROTO :XPTR
            ENDIF
            InterlockedCompareExchange PROTO :XWORD, :XWORD, :XWORD
            InterlockedDecrement PROTO :XPTR
            InterlockedExchange PROTO :XPTR, :XWORD
            InterlockedExchangeAdd PROTO :XPTR, :XWORD
            InterlockedIncrement PROTO :XPTR
            InterlockedPopEntrySList PROTO :XPTR
            InterlockedPushEntrySList PROTO :XPTR, :XPTR
            KefAcquireSpinLockAtDpcLevel PROTO :XPTR
            KefReleaseSpinLockFromDpcLevel PROTO :XPTR
            KeTerminateThread PROTO :XWORD
            KiAcquireSpinLock PROTO :XPTR
            Kii386SpinOnSpinLock PROTO :XPTR, :XWORD
            KiReleaseSpinLock PROTO :XPTR
            RtlUlongByteSwap PROTO :XWORD
            RtlUlonglongByteSwap PROTO :XWORD, :XWORD
            RtlUshortByteSwap PROTO :XWORD
        ENDIF
        IoPnPDeliverServicePowerNotification PROTO :XWORD, :XWORD, :XWORD, :XWORD
    ELSEIF (NTDDI_VERSION LE NTDDI_WIN7)
        IFNDEF APP_WIN64
            RtlConvertLongToLargeInteger PROTO :XWORD
            RtlConvertUlongToLargeInteger PROTO :XWORD
            RtlEnlargedIntegerMultiply PROTO :XWORD, :XWORD
            RtlEnlargedUnsignedDivide PROTO :XWORD, :XWORD, :XWORD, :XWORD
            RtlEnlargedUnsignedMultiply PROTO :XWORD, :XWORD
            RtlExtendedIntegerMultiply PROTO :XWORD, :XWORD, :XWORD
            RtlExtendedLargeIntegerDivide PROTO :XWORD, :XWORD, :XWORD, :XWORD
            RtlExtendedMagicDivide PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
            RtlFillMemoryUlong PROTO :XWORD, :XWORD, :XWORD
            RtlLargeIntegerArithmeticShift PROTO :XWORD, :XWORD, :XWORD
            RtlLargeIntegerDivide PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
            RtlLargeIntegerNegate PROTO :XWORD, :XWORD
            RtlLargeIntegerShiftLeft PROTO :XWORD, :XWORD, :XWORD
            RtlLargeIntegerShiftRight PROTO :XWORD, :XWORD, :XWORD
            RtlLargeIntegerSubtract PROTO :XWORD, :XWORD, :XWORD, :XWORD
        ENDIF
    ELSEIF (NTDDI_VERSION GE NTDDI_WIN7 AND NTDDI_VERSION LT NTDDI_WIN8)
        IFDEF APP_WIN64
            IoSetOplockKeyContext PROTO :XWORD, :XWORD, :XWORD
        ELSE
            ExFreeToPagedLookasideList PROTO :XWORD, :XWORD
            Exi386InterlockedDecrementLong PROTO :XWORD
            Exi386InterlockedExchangeUlong PROTO :XWORD, :XWORD
            Exi386InterlockedIncrementLong PROTO :XWORD
            ExInterlockedDecrementLong PROTO :XWORD, :XWORD
            ExInterlockedExchangeUlong PROTO :XWORD, :XWORD, :XWORD
            ExInterlockedIncrementLong PROTO :XWORD, :XWORD
            Ke386CallBios PROTO :XWORD, :XWORD
            Ke386IoSetAccessProcess PROTO :XWORD, :XWORD
            Ke386QueryIoAccessMap PROTO :XWORD, :XWORD
            Ke386SetIoAccessMap PROTO :XWORD, :XWORD
            KeGetPreviousMode PROTO
            KeI386AbiosCall PROTO :XWORD, :XWORD, :XWORD, :XWORD
            KeI386AllocateGdtSelectors PROTO :XWORD, :XWORD
            KeI386Call16BitFunction PROTO :XWORD
            KeI386FlatToGdtSelector PROTO :XWORD, :XWORD, :XWORD
            KeI386GetLid PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
            KeI386ReleaseGdtSelectors PROTO :XWORD, :XWORD
            KeI386ReleaseLid PROTO :XWORD, :XWORD
            KeI386SetGdtSelector PROTO :XWORD, :XWORD
            KeProfileInterrupt PROTO :XWORD
            KeQuerySystemTime PROTO :XWORD
            KeQueryTickCount PROTO :XWORD
            KiCoprocessorError PROTO
            KiDeliverApc PROTO :XWORD, :XWORD, :XWORD
            KiIpiServiceRoutine PROTO :XWORD, :XWORD
            READ_REGISTER_BUFFER_UCHAR PROTO :XPTR, :XPTR, :XWORD
            READ_REGISTER_BUFFER_ULONG PROTO :XPTR, :XPTR, :XWORD
            READ_REGISTER_BUFFER_USHORT PROTO :XPTR, :XPTR, :XWORD
            READ_REGISTER_UCHAR PROTO :XPTR
            READ_REGISTER_ULONG PROTO :XPTR
            READ_REGISTER_USHORT PROTO :XPTR
        ENDIF
    ELSEIF (NTDDI_VERSION GE NTDDI_WIN7)
        IFNDEF APP_WIN64
            KeInitializeSpinLock PROTO :XWORD
        ENDIF
    ENDIF
    ExGetExclusiveWaiterCount PROTO :XWORD
    ExGetPreviousMode PROTO
    ExGetSharedWaiterCount PROTO :XWORD
    ExInitializeNPagedLookasideList PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    ExInitializePagedLookasideList PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    ExInitializeResourceLite PROTO :XWORD
    ExInitializeZone PROTO :XWORD, :XWORD, :XWORD, :XWORD
    ExInterlockedAddLargeInteger PROTO :XWORD, :XWORD, :XWORD, :XWORD
    ExInterlockedAddUlong PROTO :XWORD, :XWORD, :XWORD
    ExInterlockedExtendZone PROTO :XWORD, :XWORD, :XWORD, :XWORD
    ExInterlockedInsertHeadList PROTO :XWORD, :XWORD, :XWORD
    ExInterlockedInsertTailList PROTO :XWORD, :XWORD, :XWORD
    ExInterlockedPopEntryList PROTO :XWORD, :XWORD
    ExInterlockedPushEntryList PROTO :XWORD, :XWORD, :XWORD
    ExInterlockedRemoveHeadList PROTO :XWORD, :XWORD
    ExIsProcessorFeaturePresent PROTO :XWORD
    ExIsResourceAcquiredExclusiveLite PROTO :XWORD
    ExIsResourceAcquiredSharedLite PROTO :XWORD
    ExLocalTimeToSystemTime PROTO :XWORD, :XWORD
    ExNotifyCallback PROTO :XWORD, :XWORD, :XWORD
    ExQueryPoolBlockSize PROTO :XWORD, :XWORD
    ExQueueWorkItem PROTO :XWORD, :XWORD
    ExRaiseAccessViolation PROTO
    ExRaiseDatatypeMisalignment PROTO
    ExRaiseException PROTO :XWORD
    ExRaiseHardError PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    ExRaiseStatus PROTO :XWORD
    ExRegisterCallback PROTO :XWORD, :XWORD, :XWORD
    ExReinitializeResourceLite PROTO :XWORD
    ExReleaseFastMutexUnsafe PROTO :XPTR
    ExReleaseResourceForThreadLite PROTO :XWORD, :XWORD
    ExReleaseResourceLite PROTO :XPTR
    ExSetResourceOwnerPointer PROTO :XWORD, :XWORD
    ExSystemExceptionFilter PROTO
    ExSystemTimeToLocalTime PROTO :XWORD, :XWORD
    ExUnregisterCallback PROTO :XWORD
    FsRtlAddLargeMcbEntry PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    FsRtlAddMcbEntry PROTO :XWORD, :XWORD, :XWORD, :XWORD
    FsRtlAddToTunnelCache PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    FsRtlAllocatePool PROTO :XWORD, :XWORD
    FsRtlAllocatePoolWithQuota PROTO :XWORD, :XWORD
    FsRtlAllocatePoolWithQuotaTag PROTO :XWORD, :XWORD, :XWORD
    FsRtlAllocatePoolWithTag PROTO :XWORD, :XWORD, :XWORD
    FsRtlAllocateResource PROTO
    FsRtlAreNamesEqual PROTO :XWORD, :XWORD, :XWORD, :XWORD
    FsRtlBalanceReads PROTO :XPTR
    FsRtlCheckLockForReadAccess PROTO :XWORD, :XWORD
    FsRtlCheckLockForWriteAccess PROTO :XWORD, :XWORD
    FsRtlCheckOplock PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    FsRtlCopyRead PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    FsRtlCopyWrite PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    FsRtlCurrentBatchOplock PROTO :XWORD
    FsRtlDeleteKeyFromTunnelCache PROTO :XWORD, :XWORD, :XWORD
    FsRtlDeleteTunnelCache PROTO :XWORD
    FsRtlDeregisterUncProvider PROTO :XWORD
    FsRtlDissectDbcs PROTO :XWORD, :XWORD, :XWORD, :XWORD
    FsRtlDissectName PROTO :XWORD, :XWORD, :XWORD, :XWORD
    FsRtlDoesDbcsContainWildCards PROTO :XWORD
    FsRtlDoesNameContainWildCards PROTO :XWORD
    FsRtlFastCheckLockForRead PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    FsRtlFastCheckLockForWrite PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    FsRtlFastUnlockAll PROTO :XWORD, :XWORD, :XWORD, :XWORD
    FsRtlFastUnlockAllByKey PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    FsRtlFastUnlockSingle PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    FsRtlFindInTunnelCache PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    FsRtlGetFileSize PROTO :XWORD, :XWORD
    FsRtlGetNextFileLock PROTO :XWORD, :XWORD
    FsRtlGetNextLargeMcbEntry PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    FsRtlGetNextMcbEntry PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    FsRtlInitializeFileLock PROTO :XWORD, :XWORD, :XWORD
    FsRtlInitializeLargeMcb PROTO :XWORD, :XWORD
    FsRtlInitializeMcb PROTO :XWORD, :XWORD
    FsRtlInitializeOplock PROTO :XWORD
    FsRtlInitializeTunnelCache PROTO :XWORD
    FsRtlIsDbcsInExpression PROTO :XWORD, :XWORD
    FsRtlIsFatDbcsLegal PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    FsRtlIsHpfsDbcsLegal PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    FsRtlIsNameInExpression PROTO :XWORD, :XWORD, :XWORD, :XWORD
    FsRtlIsNtstatusExpected PROTO :XWORD
    FsRtlIsTotalDeviceFailure PROTO :XWORD
    FsRtlLookupLargeMcbEntry PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    FsRtlLookupLastLargeMcbEntry PROTO :XWORD, :XWORD, :XWORD
    FsRtlLookupLastMcbEntry PROTO :XWORD, :XWORD, :XWORD
    FsRtlLookupMcbEntry PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    FsRtlMdlRead PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    FsRtlMdlReadComplete PROTO :XWORD, :XWORD
    FsRtlMdlReadCompleteDev PROTO :XWORD, :XWORD, :XWORD
    FsRtlMdlReadDev PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    FsRtlMdlWriteComplete PROTO :XWORD, :XWORD, :XWORD
    FsRtlMdlWriteCompleteDev PROTO :XWORD, :XWORD, :XWORD, :XWORD
    FsRtlNormalizeNtstatus PROTO :XWORD, :XWORD
    FsRtlNotifyChangeDirectory PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    FsRtlNotifyCleanup PROTO :XWORD, :XWORD, :XWORD
    FsRtlNotifyFullChangeDirectory PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    FsRtlNotifyFullReportChange PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    FsRtlNotifyInitializeSync PROTO :XWORD
    FsRtlNotifyReportChange PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    FsRtlNotifyUninitializeSync PROTO :XWORD
    FsRtlNumberOfRunsInLargeMcb PROTO :XWORD
    FsRtlNumberOfRunsInMcb PROTO :XWORD
    FsRtlOplockFsctrl PROTO :XWORD, :XWORD, :XWORD
    FsRtlOplockIsFastIoPossible PROTO :XWORD
    FsRtlPostPagingFileStackOverflow PROTO :XWORD, :XWORD, :XWORD
    FsRtlPostStackOverflow PROTO :XWORD, :XWORD, :XWORD
    FsRtlPrepareMdlWrite PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    FsRtlPrepareMdlWriteDev PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    FsRtlPrivateLock PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    FsRtlProcessFileLock PROTO :XWORD, :XWORD, :XWORD
    FsRtlRegisterUncProvider PROTO :XWORD, :XWORD, :XWORD
    FsRtlRemoveLargeMcbEntry PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    FsRtlRemoveMcbEntry PROTO :XWORD, :XWORD, :XWORD
    FsRtlSplitLargeMcb PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    FsRtlSyncVolumes PROTO :XWORD, :XWORD, :XWORD
    FsRtlTruncateLargeMcb PROTO :XWORD, :XWORD, :XWORD
    FsRtlTruncateMcb PROTO :XWORD, :XWORD
    FsRtlUninitializeFileLock PROTO :XWORD
    FsRtlUninitializeLargeMcb PROTO :XWORD
    FsRtlUninitializeMcb PROTO :XWORD
    FsRtlUninitializeOplock PROTO :XWORD
    IoAcquireVpbSpinLock PROTO :XWORD
    IoAllocateAdapterChannel PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    IoAllocateController PROTO :XWORD, :XWORD, :XWORD, :XWORD
    IoAllocateErrorLogEntry PROTO :XWORD, :XWORD
    IoAllocateIrp PROTO :XWORD, :XWORD
    IoAllocateMdl PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    IoAssignResources PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    IoAttachDevice PROTO :XWORD, :XWORD, :XWORD
    IoAttachDeviceByPointer PROTO :XWORD, :XWORD
    IoAttachDeviceToDeviceStack PROTO :XWORD, :XWORD
    IoBuildAsynchronousFsdRequest PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    IoBuildDeviceIoControlRequest PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    IoBuildPartialMdl PROTO :XWORD, :XWORD, :XWORD, :XWORD
    IoBuildSynchronousFsdRequest PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    IoCallDriver PROTO :XWORD, :XWORD
    IoCancelIrp PROTO :XWORD
    IoCheckDesiredAccess PROTO :XWORD, :XWORD
    IoCheckEaBufferValidity PROTO :XWORD, :XWORD, :XWORD
    IoCheckFunctionAccess PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    IoCheckShareAccess PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    IoCompleteRequest PROTO :XPTR, :XWORD
    IoConnectInterrupt PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    IoCreateController PROTO :XWORD
    IoCreateDevice PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    IoCreateFile PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    IoCreateNotificationEvent PROTO :XWORD, :XWORD
    IoCreateStreamFileObject PROTO :XWORD, :XWORD
    IoCreateSymbolicLink PROTO :XWORD, :XWORD
    IoCreateSynchronizationEvent PROTO :XWORD, :XWORD
    IoCreateUnprotectedSymbolicLink PROTO :XWORD, :XWORD
    IoDeleteController PROTO :XWORD
    IoDeleteDevice PROTO :XWORD
    IoDeleteSymbolicLink PROTO :XWORD
    IoDetachDevice PROTO :XWORD
    IoDisconnectInterrupt PROTO :XWORD
    IoEnqueueIrp PROTO :XWORD
    IoFastQueryNetworkAttributes PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    IofCallDriver PROTO :XPTR, :XPTR
    IofCompleteRequest PROTO :XPTR, :XWORD
    IoFreeController PROTO :XWORD
    IoFreeIrp PROTO :XWORD
    IoFreeMdl PROTO :XWORD
    IoGetAttachedDevice PROTO :XWORD
    IoGetBaseFileSystemDeviceObject PROTO :XWORD
    IoGetConfigurationInformation PROTO
    IoGetCurrentProcess PROTO
    IoGetDeviceObjectPointer PROTO :XWORD, :XWORD, :XWORD, :XWORD
    IoGetDeviceToVerify PROTO :XWORD
    IoGetFileObjectGenericMapping PROTO
    IoGetInitialStack PROTO
    IoGetRelatedDeviceObject PROTO :XWORD
    IoGetRequestorProcess PROTO :XWORD
    IoGetStackLimits PROTO :XWORD, :XWORD
    IoGetTopLevelIrp PROTO
    IoInitializeIrp PROTO :XWORD, :XWORD, :XWORD
    IoInitializeTimer PROTO :XWORD, :XWORD, :XWORD
    IoIsOperationSynchronous PROTO :XWORD
    IoIsSystemThread PROTO :XWORD
    IoMakeAssociatedIrp PROTO :XWORD, :XWORD
    IoPageRead PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    IoQueryDeviceDescription PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    IoQueryFileInformation PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    IoQueryVolumeInformation PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    IoQueueThreadIrp PROTO :XWORD
    IoRaiseHardError PROTO :XWORD, :XWORD, :XWORD
    IoRaiseInformationalHardError PROTO :XWORD, :XWORD, :XWORD
    IoRegisterDriverReinitialization PROTO :XWORD, :XWORD, :XWORD
    IoRegisterFileSystem PROTO :XWORD
    IoRegisterFsRegistrationChange PROTO :XWORD, :XWORD
    IoRegisterShutdownNotification PROTO :XWORD
    IoReleaseCancelSpinLock PROTO :XWORD
    IoReleaseVpbSpinLock PROTO :XWORD
    IoRemoveShareAccess PROTO :XWORD, :XWORD
    IoReportHalResourceUsage PROTO :XWORD, :XWORD, :XWORD, :XWORD
    IoReportResourceUsage PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    IoSetDeviceToVerify PROTO :XWORD, :XWORD
    IoSetHardErrorOrVerifyDevice PROTO :XWORD, :XWORD
    IoSetInformation PROTO :XWORD, :XWORD, :XWORD, :XWORD
    IoSetShareAccess PROTO :XWORD, :XWORD, :XWORD, :XWORD
    IoSetThreadHardErrorMode PROTO :XWORD
    IoSetTopLevelIrp PROTO :XWORD
    IoStartNextPacket PROTO :XWORD, :XWORD
    IoStartNextPacketByKey PROTO :XWORD, :XWORD, :XWORD
    IoStartPacket PROTO :XWORD, :XWORD, :XWORD, :XWORD
    IoStartTimer PROTO :XWORD
    IoStopTimer PROTO :XWORD
    IoSynchronousPageWrite PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    IoThreadToProcess PROTO :XWORD
    IoUnregisterFileSystem PROTO :XPTR
    IoUnregisterFsRegistrationChange PROTO :XWORD, :XWORD
    IoUnregisterShutdownNotification PROTO :XWORD
    IoUpdateShareAccess PROTO :XWORD, :XWORD
    IoVerifyVolume PROTO :XWORD, :XWORD
    IoWriteErrorLogEntry PROTO :XWORD
    isdigit PROTO :XWORD
    islower PROTO :XWORD
    isprint PROTO :XWORD
    isspace PROTO :XWORD
    isupper PROTO :XWORD
    isxdigit PROTO :XWORD
    KdPollBreakIn PROTO
    KeAcquireSpinLockAtDpcLevel PROTO :XWORD
    KeAddSystemServiceTable PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    KeAttachProcess PROTO :XWORD
    KeBugCheck PROTO :XWORD
    KeBugCheckEx PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    KeCancelTimer PROTO :XWORD
    KeClearEvent PROTO :XWORD
    KeDelayExecutionThread PROTO :XWORD, :XWORD, :XWORD
    KeDeregisterBugCheckCallback PROTO :XWORD
    KeDetachProcess PROTO
    KeEnterCriticalRegion PROTO
    KeEnterKernelDebugger PROTO
    KeFindConfigurationEntry PROTO :XWORD, :XWORD, :XWORD, :XWORD
    KeFindConfigurationNextEntry PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    KeFlushEntireTb PROTO :XWORD, :XWORD
    KeGetCurrentThread PROTO
    KeInitializeApc PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    KeInitializeDeviceQueue PROTO :XWORD
    KeInitializeDpc PROTO :XWORD, :XWORD, :XWORD
    KeInitializeEvent PROTO :XWORD, :XWORD, :XWORD
    KeInitializeInterrupt PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    KeInitializeMutant PROTO :XWORD, :XWORD
    KeInitializeMutex PROTO :XWORD, :XWORD
    KeInitializeQueue PROTO :XWORD, :XWORD
    KeInitializeSemaphore PROTO :XWORD, :XWORD, :XWORD
    KeInitializeTimer PROTO :XWORD
    KeInitializeTimerEx PROTO :XWORD, :XWORD
    KeInsertByKeyDeviceQueue PROTO :XWORD, :XWORD, :XWORD
    KeInsertDeviceQueue PROTO :XWORD, :XWORD
    KeInsertHeadQueue PROTO :XWORD, :XWORD
    KeInsertQueue PROTO :XWORD, :XWORD
    KeInsertQueueApc PROTO :XWORD, :XWORD, :XWORD, :XWORD
    KeInsertQueueDpc PROTO :XWORD, :XWORD, :XWORD
    KeIsExecutingDpc PROTO
    KeLeaveCriticalRegion PROTO
    KeProfileInterruptWithSource PROTO :XWORD, :XWORD
    KePulseEvent PROTO :XWORD, :XWORD, :XWORD
    KeQueryTimeIncrement PROTO
    KeRaiseUserException PROTO :XWORD
    KeReadStateEvent PROTO :XWORD
    KeReadStateMutant PROTO :XWORD
    KeReadStateMutex PROTO :XWORD
    KeReadStateQueue PROTO :XWORD
    KeReadStateSemaphore PROTO :XWORD
    KeReadStateTimer PROTO :XWORD
    KeRegisterBugCheckCallback PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    KeReleaseMutant PROTO :XWORD, :XWORD, :XWORD, :XWORD
    KeReleaseMutex PROTO :XWORD, :XWORD
    KeReleaseSemaphore PROTO :XWORD, :XWORD, :XWORD, :XWORD
    KeReleaseSpinLockFromDpcLevel PROTO :XPTR
    KeRemoveByKeyDeviceQueue PROTO :XWORD, :XWORD
    KeRemoveDeviceQueue PROTO :XWORD
    KeRemoveEntryDeviceQueue PROTO :XWORD, :XWORD
    KeRemoveQueue PROTO :XWORD, :XWORD, :XWORD
    KeRemoveQueueDpc PROTO :XWORD
    KeResetEvent PROTO :XWORD
    KeRestoreFloatingPointState PROTO :XWORD
    KeRundownQueue PROTO :XWORD
    KeSaveFloatingPointState PROTO :XWORD
    KeSetAffinityThread PROTO :XWORD, :XWORD
    KeSetBasePriorityThread PROTO :XWORD, :XWORD
    KeSetDmaIoCoherency PROTO :XWORD
    KeSetEvent PROTO :XWORD, :XWORD, :XWORD
    KeSetEventBoostPriority PROTO :XWORD, :XWORD
    KeSetIdealProcessorThread PROTO :XWORD, :XWORD
    KeSetImportanceDpc PROTO :XWORD, :XWORD
    KeSetKernelStackSwapEnable PROTO :XWORD
    KeSetPriorityThread PROTO :XWORD, :XWORD
    KeSetProfileIrql PROTO :XWORD
    KeSetTargetProcessorDpc PROTO :XWORD, :XWORD
    KeSetTimeIncrement PROTO :XWORD, :XWORD
    KeSetTimer PROTO :XWORD, :XWORD, :XWORD, :XWORD
    KeSetTimerEx PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    KeSynchronizeExecution PROTO :XWORD, :XWORD, :XWORD
    KeUpdateRunTime PROTO :XWORD
    KeUserModeCallback PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    KeWaitForMultipleObjects PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    KeWaitForMutexObject PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    KeWaitForSingleObject PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    LdrAccessResource PROTO :XWORD, :XWORD, :XWORD, :XWORD
    LdrEnumResources PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    LdrFindResource_U PROTO :XWORD, :XWORD, :XWORD, :XWORD
    LdrFindResourceDirectory_U PROTO :XWORD, :XWORD, :XWORD, :XWORD
    LpcRequestPort PROTO :XWORD, :XWORD
    LsaCallAuthenticationPackage PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    LsaDeregisterLogonProcess PROTO :XWORD
    LsaFreeReturnBuffer PROTO :XWORD
    LsaLogonUser PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    LsaLookupAuthenticationPackage PROTO :XWORD, :XWORD, :XWORD
    LsaRegisterLogonProcess PROTO :XWORD, :XWORD, :XWORD
    mbstowcs PROTO :XPTR, :XPTR, :SIZE_T
    mbtowc PROTO :XPTR, :XPTR, :SIZE_T
    memchr PROTO :XPTR, :XWORD, :SIZE_T
    memcpy PROTO :XPTR, :XPTR, :SIZE_T
    IFNDEF memmove
        memmove PROTO :XPTR, :XPTR, :SIZE_T
    ENDIF
    IFNDEF memset
        memset PROTO :XPTR, :XWORD, :SIZE_T
    ENDIF
    MmAdjustWorkingSetSize PROTO :XWORD, :XWORD, :XWORD, :XWORD
    MmAllocateContiguousMemory PROTO :XWORD, :XWORD, :XWORD
    MmAllocateNonCachedMemory PROTO :XWORD
    MmBuildMdlForNonPagedPool PROTO :XWORD
    MmCanFileBeTruncated PROTO :XWORD, :XWORD
    MmCreateMdl PROTO :XWORD, :XWORD, :XWORD
    MmCreateSection PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    MmDisableModifiedWriteOfSection PROTO :XWORD
    MmFlushImageSection PROTO :XWORD, :XWORD
    MmForceSectionClosed PROTO :XWORD, :XWORD
    MmFreeContiguousMemory PROTO :XWORD
    MmFreeNonCachedMemory PROTO :XWORD, :XWORD
    MmGetPhysicalAddress PROTO :XWORD
    MmGrowKernelStack PROTO :XWORD
    MmIsAddressValid PROTO :XWORD
    MmIsNonPagedSystemAddressValid PROTO :PVOID
    MmIsRecursiveIoFault PROTO
    MmIsThisAnNtAsSystem PROTO
    MmLockPagableDataSection PROTO :XWORD
    MmLockPagableImageSection PROTO :XWORD
    MmLockPagableSectionByHandle PROTO :XWORD
    MmMapIoSpace PROTO :XWORD, :XWORD, :XWORD, :XWORD
    MmMapLockedPages PROTO :XWORD, :XWORD
    MmMapLockedPagesSpecifyCache PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    MmMapMemoryDumpMdl PROTO :XWORD
    MmMapVideoDisplay PROTO :XWORD, :XWORD, :XWORD, :XWORD
    MmMapViewInSystemSpace PROTO :XWORD, :XWORD, :XWORD
    MmMapViewOfSection PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    MmPageEntireDriver PROTO :XWORD
    MmProbeAndLockPages PROTO :XWORD, :XWORD, :XWORD
    MmQuerySystemSize PROTO
    MmResetDriverPaging PROTO :XWORD
    MmSecureVirtualMemory PROTO :XWORD, :XWORD, :XWORD
    MmSetAddressRangeModified PROTO :XWORD, :XWORD
    MmSetBankedSection PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    MmSizeOfMdl PROTO :XWORD, :XWORD
    MmUnlockPagableImageSection PROTO :XWORD
    MmUnlockPages PROTO :XWORD
    MmUnmapIoSpace PROTO :XWORD, :XWORD
    MmUnmapLockedPages PROTO :XWORD, :XWORD
    MmUnmapVideoDisplay PROTO :XWORD, :XWORD
    MmUnmapViewInSystemSpace PROTO :XWORD
    MmUnmapViewOfSection PROTO :XWORD, :XWORD
    MmUnsecureVirtualMemory PROTO :XWORD
    NlsOemLeadByteInfo PROTO :XPTR
    NtAddAtom PROTO :XWORD, :XWORD, :XWORD
    NtAdjustPrivilegesToken PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    NtAllocateLocallyUniqueId PROTO :XWORD
    NtAllocateUuids PROTO :XWORD, :XWORD, :XWORD, :XWORD
    NtAllocateVirtualMemory PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    NtClose PROTO :XWORD
    NtConnectPort PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    NtCreateEvent PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    NtCreateFile PROTO :XPTR, :XWORD, :XPTR, :XPTR, :XPTR, :XWORD, :XWORD, :XWORD, :XWORD, :XPTR, :XWORD
    NtCreateSection PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    NtDeleteAtom PROTO :XWORD
    NtDeleteFile PROTO :XWORD
    NtDeviceIoControlFile PROTO :HANDLE, :HANDLE, :XPTR, :XPTR, :XPTR, :XWORD, :XPTR, :XWORD, :XPTR, :XWORD
    NtDuplicateObject PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    NtDuplicateToken PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    NtFindAtom PROTO :XWORD, :XWORD, :XWORD
    NtFreeVirtualMemory PROTO :XWORD, :XWORD, :XWORD, :XWORD
    NtFsControlFile PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    NtLockFile PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    NtMapViewOfSection PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    NtNotifyChangeDirectoryFile PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    NtOpenFile PROTO :XPTR, :XWORD, :XPTR, :XPTR, :XWORD, :XWORD
    NtOpenProcess PROTO :XWORD, :XWORD, :XWORD, :XWORD
    NtOpenProcessToken PROTO :XWORD, :XWORD, :XWORD
    NtQueryDirectoryFile PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    NtQueryEaFile PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    NtQueryInformationAtom PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    NtQueryInformationFile PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    NtQueryInformationProcess PROTO :HANDLE, :XWORD, :XPTR, :XWORD, :XPTR
    NtQueryInformationToken PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    NtQuerySecurityObject PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    NtQueryVolumeInformationFile PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    NtReadFile PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    NtRequestPort PROTO :XWORD, :XWORD
    NtRequestWaitReplyPort PROTO :XWORD, :XWORD, :XWORD
    NtSetEvent PROTO :XWORD, :XWORD
    NtSetInformationFile PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    NtSetInformationProcess PROTO :XWORD, :XWORD, :XWORD, :XWORD
    NtSetInformationThread PROTO :XWORD, :XWORD, :XWORD, :XWORD
    NtSetQuotaInformationFile PROTO :XWORD, :XWORD, :XWORD, :XWORD
    NtSetSecurityObject PROTO :XWORD, :XWORD, :XWORD
    NtUnlockFile PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    NtVdmControl PROTO :XWORD, :XWORD
    NtWaitForSingleObject PROTO :HANDLE, :XWORD, :XPTR
    NtWriteFile PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    ObAssignSecurity PROTO :XWORD, :XWORD, :XWORD, :XWORD
    ObCheckCreateObjectAccess PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    ObCheckObjectAccess PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    ObCreateObject PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    ObDereferenceObject PROTO :XWORD
    ObfDereferenceObject PROTO :PVOID
    ObFindHandleForObject PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    ObfReferenceObject PROTO :PVOID
    ObGetObjectSecurity PROTO :XWORD, :XWORD, :XWORD
    ObInsertObject PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    ObMakeTemporaryObject PROTO :XWORD
    ObOpenObjectByName PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    ObOpenObjectByPointer PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    ObQueryNameString PROTO :XWORD, :XWORD, :XWORD, :XWORD
    ObQueryObjectAuditingByHandle PROTO :XWORD, :XWORD
    ObReferenceObjectByHandle PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    ObReferenceObjectByName PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    ObReferenceObjectByPointer PROTO :XWORD, :XWORD, :XWORD, :XWORD
    ObReleaseObjectSecurity PROTO :XWORD, :XWORD
    ObSetSecurityDescriptorInfo PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    PfxFindPrefix PROTO :XWORD, :XWORD
    PfxInitialize PROTO :XWORD
    PfxInsertPrefix PROTO :XWORD, :XWORD, :XWORD
    PfxRemovePrefix PROTO :XWORD, :XWORD
    ProbeForWrite PROTO :XWORD, :XWORD, :XWORD
    PsAssignImpersonationToken PROTO :XWORD, :XWORD
    PsChargePoolQuota PROTO :XWORD, :XWORD, :XWORD
    PsCreateSystemThread PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    PsEstablishWin32Callouts PROTO :XWORD
    PsGetCurrentProcessId PROTO
    PsGetCurrentThreadId PROTO
    PsGetProcessExitTime PROTO
    PsGetVersion PROTO :XWORD, :XWORD, :XWORD, :XWORD
    PsImpersonateClient PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    PsIsThreadTerminating PROTO :XWORD
    PsLookupProcessByProcessId PROTO :XWORD, :XWORD
    PsLookupProcessThreadByCid PROTO :XWORD, :XWORD, :XWORD
    PsLookupThreadByThreadId PROTO :XWORD, :XWORD
    PsProcessType PROTO :HANDLE, :XWORD, :XPTR, :XWORD, :PVOID, :XPTR
    PsReferenceImpersonationToken PROTO :XWORD, :XWORD, :XWORD, :XWORD
    PsReferencePrimaryToken PROTO :XWORD
    PsReturnPoolQuota PROTO :XWORD, :XWORD, :XWORD
    PsRevertToSelf PROTO
    PsSetCreateProcessNotifyRoutine PROTO :XWORD, :XWORD
    PsSetCreateThreadNotifyRoutine PROTO :XWORD
    PsSetLegoNotifyRoutine PROTO :XWORD
    PsSetProcessPriorityByClass PROTO :XWORD, :XWORD
    PsTerminateSystemThread PROTO :XWORD
    PsThreadType PROTO :HANDLE
    qsort PROTO :PVOID, :SIZE_T, :SIZE_T, :XPTR
    rand PROTO
    RtlAbsoluteToSelfRelativeSD PROTO :XWORD, :XWORD, :XWORD
    RtlAddAccessAllowedAce PROTO :XWORD, :XWORD, :XWORD, :XWORD
    RtlAddAce PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    RtlAddAtomToAtomTable PROTO :XWORD, :XWORD, :XWORD
    RtlAllocateHeap PROTO :XWORD, :XWORD, :XWORD
    RtlAnsiCharToUnicodeChar PROTO :XWORD
    RtlAnsiStringToUnicodeSize PROTO :XWORD
    RtlAnsiStringToUnicodeString PROTO :XPTR, :XPTR, :XWORD
    RtlAppendAsciizToString PROTO :XWORD, :XWORD
    RtlAppendStringToString PROTO :XWORD, :XWORD
    RtlAppendUnicodeStringToString PROTO :XWORD, :XWORD
    RtlAppendUnicodeToString PROTO :XWORD, :XWORD
    RtlAreAllAccessesGranted PROTO :XWORD, :XWORD
    RtlAreAnyAccessesGranted PROTO :XWORD, :XWORD
    RtlAreBitsClear PROTO :XWORD, :XWORD, :XWORD
    RtlAreBitsSet PROTO :XWORD, :XWORD, :XWORD
    RtlAssert PROTO :XWORD, :XWORD, :XWORD, :XWORD
    RtlCaptureStackBackTrace PROTO :XWORD, :XWORD, :PVOID, :PULONG
    RtlCharToInteger PROTO :XPTR, :XWORD, :XPTR
    RtlCheckRegistryKey PROTO :XWORD, :XWORD
    RtlClearAllBits PROTO :XWORD
    RtlClearBits PROTO :XWORD, :XWORD, :XWORD
    RtlCompareMemory PROTO :XPTR, :XPTR, :XWORD
    RtlCompareMemoryUlong PROTO :XWORD, :XWORD, :XWORD
    RtlCompareString PROTO :XWORD, :XWORD, :XWORD
    RtlCompareUnicodeString PROTO :XWORD, :XWORD, :XWORD
    RtlCompressBuffer PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    RtlCompressChunks PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    RtlConvertSidToUnicodeString PROTO :XPTR, :XPTR, :XWORD
    RtlCopyLuid PROTO :XWORD, :XWORD
    RtlCopyMemory PROTO :XPTR, :XPTR, :XWORD
    RtlCopySid PROTO :XWORD, :XWORD, :XWORD
    RtlCopyString PROTO :XWORD, :XWORD
    RtlCopyUnicodeString PROTO :XWORD, :XWORD
    RtlCreateAcl PROTO :XWORD, :XWORD, :XWORD
    RtlCreateAtomTable PROTO :XWORD, :XWORD
    RtlCreateHeap PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    RtlCreateRegistryKey PROTO :XWORD, :XWORD
    RtlCreateSecurityDescriptor PROTO :XWORD, :XWORD
    RtlCreateUnicodeString PROTO :XWORD, :XWORD
    RtlCustomCPToUnicodeN PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    RtlDecompressBuffer PROTO :XWORD, :XPTR, :XWORD, :XPTR, :XWORD, :XPTR
    RtlDecompressChunks PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    RtlDecompressFragment PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    RtlDelete PROTO :XWORD
    RtlDeleteAtomFromAtomTable PROTO :XWORD, :XWORD
    RtlDeleteElementGenericTable PROTO :XWORD, :XWORD
    RtlDeleteNoSplay PROTO :XWORD, :XWORD
    RtlDeleteRegistryValue PROTO :XWORD, :XWORD, :XWORD
    RtlDescribeChunk PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    RtlDestroyAtomTable PROTO :XWORD
    RtlDestroyHeap PROTO :XWORD
    RtlDowncaseUnicodeString PROTO :XWORD, :XWORD, :XWORD
    RtlEmptyAtomTable PROTO :XWORD, :XWORD
    RtlEnumerateGenericTable PROTO :XWORD, :XWORD
    RtlEnumerateGenericTableWithoutSplaying PROTO :XWORD, :XWORD
    RtlEqualLuid PROTO :XWORD, :XWORD
    RtlEqualSid PROTO :XWORD, :XWORD
    RtlEqualString PROTO :XWORD, :XWORD, :XWORD
    RtlEqualUnicodeString PROTO :XWORD, :XWORD, :XWORD
    RtlFillMemory PROTO :XWORD, :XWORD, :XWORD
    RtlFindClearBits PROTO :XWORD, :XWORD, :XWORD
    RtlFindClearBitsAndSet PROTO :XWORD, :XWORD, :XWORD
    RtlFindFirstRunClear PROTO :XWORD, :XWORD
    RtlFindLongestRunClear PROTO :XWORD, :XWORD
    RtlFindMessage PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    RtlFindSetBits PROTO :XWORD, :XWORD, :XWORD
    RtlFindSetBitsAndClear PROTO :XWORD, :XWORD, :XWORD
    RtlFindUnicodePrefix PROTO :XWORD, :XWORD, :XWORD
    RtlFormatCurrentUserKeyPath PROTO :XWORD
    RtlFreeAnsiString PROTO :XPTR
    RtlFreeHeap PROTO :XWORD, :XWORD, :XWORD
    RtlFreeOemString PROTO :XPTR
    RtlFreeUnicodeString PROTO :XPTR
    RtlGenerate8dot3Name PROTO :XWORD, :XWORD, :XWORD, :XWORD
    RtlGetCallersAddress PROTO :XWORD, :XWORD
    RtlGetCompressionWorkSpaceSize PROTO :XWORD, :XWORD, :XWORD
    RtlGetDaclSecurityDescriptor PROTO :XWORD, :XWORD, :XWORD, :XWORD
    RtlGetDefaultCodePage PROTO :XWORD, :XWORD
    RtlGetElementGenericTable PROTO :XWORD, :XWORD
    RtlGetGroupSecurityDescriptor PROTO :XWORD, :XWORD, :XWORD
    RtlGetOwnerSecurityDescriptor PROTO :XWORD, :XWORD, :XWORD
    RtlImageNtHeader PROTO :XWORD
    RtlInitAnsiString PROTO :XPTR, :XPTR
    RtlInitCodePageTable PROTO :XWORD, :XWORD
    RtlInitializeBitMap PROTO :XWORD, :XWORD, :XWORD
    RtlInitializeGenericTable PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    RtlInitializeSid PROTO :XWORD, :XWORD, :XWORD
    RtlInitializeUnicodePrefix PROTO :XWORD
    RtlInitString PROTO :XPTR, :XPTR
    RtlInitUnicodeString PROTO :XPTR, :XPTR
    RtlInsertElementGenericTable PROTO :XWORD, :XWORD, :XWORD, :XWORD
    RtlInsertUnicodePrefix PROTO :XWORD, :XWORD, :XWORD
    RtlIntegerToChar PROTO :XWORD, :XWORD, :XWORD, :XWORD
    RtlIntegerToUnicodeString PROTO :XWORD, :XWORD, :XWORD
    RtlIsNameLegalDOS8Dot3 PROTO :XPTR, :XPTR, :XPTR
    RtlLengthRequiredSid PROTO :XWORD
    RtlLengthSecurityDescriptor PROTO :XWORD
    RtlLengthSid PROTO :XWORD
    RtlLookupAtomInAtomTable PROTO :XWORD, :XWORD, :XWORD
    RtlLookupElementGenericTable PROTO :XWORD, :XWORD
    RtlMapGenericMask PROTO :XWORD, :XWORD
    RtlMoveMemory PROTO :XWORD, :XWORD, :XWORD
    RtlMultiByteToUnicodeN PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    RtlMultiByteToUnicodeSize PROTO :XWORD, :XWORD, :XWORD
    RtlNextUnicodePrefix PROTO :XWORD, :XWORD
    RtlNtStatusToDosError PROTO :XWORD
    RtlNtStatusToDosErrorNoTeb PROTO :XWORD
    RtlNumberGenericTableElements PROTO :XWORD
    RtlNumberOfClearBits PROTO :XWORD
    RtlNumberOfSetBits PROTO :XWORD
    RtlOemStringToCountedUnicodeString PROTO :XWORD, :XWORD, :XWORD
    RtlOemStringToUnicodeSize PROTO :XWORD
    RtlOemStringToUnicodeString PROTO :XWORD, :XWORD, :XWORD
    RtlOemToUnicodeN PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    RtlPinAtomInAtomTable PROTO :XWORD, :XWORD
    RtlPrefixString PROTO :XWORD, :XWORD, :XWORD
    RtlPrefixUnicodeString PROTO :XWORD, :XWORD, :XWORD
    RtlQueryAtomInAtomTable PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    RtlQueryRegistryValues PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    RtlQueryTimeZoneInformation PROTO :XWORD
    RtlRaiseException PROTO :XWORD
    RtlRandom PROTO :XWORD
    RtlRemoveUnicodePrefix PROTO :XWORD, :XWORD
    RtlReserveChunk PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    RtlSecondsSince1970ToTime PROTO :XWORD, :XWORD
    RtlSecondsSince1980ToTime PROTO :XWORD, :XWORD
    RtlSetAllBits PROTO :XWORD
    RtlSetBits PROTO :XWORD, :XWORD, :XWORD
    RtlSetDaclSecurityDescriptor PROTO :XWORD, :XWORD, :XWORD, :XWORD
    RtlSetGroupSecurityDescriptor PROTO :XWORD, :XWORD, :XWORD
    RtlSetOwnerSecurityDescriptor PROTO :XWORD, :XWORD, :XWORD
    RtlSetSaclSecurityDescriptor PROTO :XWORD, :XWORD, :XWORD, :XWORD
    RtlSetTimeZoneInformation PROTO :XWORD
    RtlSplay PROTO :XWORD
    RtlSubAuthorityCountSid PROTO :XWORD
    RtlSubAuthoritySid PROTO :XWORD, :XWORD
    RtlTimeFieldsToTime PROTO :XWORD, :XWORD
    RtlTimeToSecondsSince1970 PROTO :XPTR, :XPTR
    RtlTimeToSecondsSince1980 PROTO :XWORD, :XWORD
    RtlTimeToTimeFields PROTO :XWORD, :XWORD
    RtlUnicodeStringToAnsiSize PROTO :XWORD
    RtlUnicodeStringToAnsiString PROTO :XPTR, :XPTR, :XWORD
    RtlUnicodeStringToCountedOemString PROTO :XWORD, :XWORD, :XWORD
    RtlUnicodeStringToInteger PROTO :XWORD, :XWORD, :XWORD
    RtlUnicodeStringToOemSize PROTO :XWORD
    RtlUnicodeStringToOemString PROTO :XPTR, :XPTR, :XWORD
    RtlUnicodeToCustomCPN PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    RtlUnicodeToMultiByteN PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    RtlUnicodeToMultiByteSize PROTO :XPTR, :XPTR, :XWORD
    RtlUnicodeToOemN PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    RtlUnwind PROTO :XWORD, :XWORD, :XWORD, :XWORD
    RtlUnwindEx PROTO :PVOID, :PVOID, :XPTR, :PVOID, :XPTR, :XPTR
    RtlUpcaseUnicodeChar PROTO :XWORD
    RtlUpcaseUnicodeString PROTO :XWORD, :XWORD, :XWORD
    RtlUpcaseUnicodeStringToAnsiString PROTO :XWORD, :XWORD, :XWORD
    RtlUpcaseUnicodeStringToCountedOemString PROTO :XWORD, :XWORD, :XWORD
    RtlUpcaseUnicodeStringToOemString PROTO :XWORD, :XWORD, :XWORD
    RtlUpcaseUnicodeToCustomCPN PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    RtlUpcaseUnicodeToMultiByteN PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    RtlUpcaseUnicodeToOemN PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    RtlUpperChar PROTO :XWORD
    RtlUpperString PROTO :XWORD, :XWORD
    RtlValidSecurityDescriptor PROTO :XWORD
    RtlValidSid PROTO :XWORD
    RtlWriteRegistryValue PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    RtlxAnsiStringToUnicodeSize PROTO :XWORD
    RtlxOemStringToUnicodeSize PROTO :XWORD
    RtlxUnicodeStringToAnsiSize PROTO :XWORD
    RtlxUnicodeStringToOemSize PROTO :XWORD
    RtlZeroHeap PROTO :XWORD, :XWORD
    RtlZeroMemory PROTO :XWORD, :XWORD
    SeAccessCheck PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    SeAppendPrivileges PROTO :XWORD, :XWORD
    SeAssignSecurity PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    SeAuditingFileEvents PROTO :XWORD, :XWORD
    SeAuditingFileOrGlobalEvents PROTO :XWORD, :XWORD, :XWORD
    SeCaptureSecurityDescriptor PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    SeCaptureSubjectContext PROTO :XWORD
    SeCloseObjectAuditAlarm PROTO :XWORD, :XWORD, :XWORD
    SeCreateAccessState PROTO :XWORD, :XWORD, :XWORD, :XWORD
    SeCreateClientSecurity PROTO :XWORD, :XWORD, :XWORD, :XWORD
    SeDeassignSecurity PROTO :XWORD
    SeDeleteAccessState PROTO :XWORD
    SeDeleteObjectAuditAlarm PROTO :XWORD, :XWORD
    SeFreePrivileges PROTO :XWORD
    SeImpersonateClient PROTO :XWORD, :XWORD
    SeLockSubjectContext PROTO :XWORD
    SeMarkLogonSessionForTerminationNotification PROTO :XWORD
    SeOpenObjectAuditAlarm PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    SeOpenObjectForDeleteAuditAlarm PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    SePrivilegeCheck PROTO :XWORD, :XWORD, :XWORD
    SePrivilegeObjectAuditAlarm PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    SeQueryAuthenticationIdToken PROTO :XWORD, :XWORD
    SeQuerySecurityDescriptorInfo PROTO :XWORD, :XWORD, :XWORD, :XWORD
    SeRegisterLogonSessionTerminatedRoutine PROTO :XWORD
    SeReleaseSecurityDescriptor PROTO :XWORD, :XWORD, :XWORD
    SeReleaseSubjectContext PROTO :XWORD
    SeSetAccessStateGenericMapping PROTO :XWORD, :XWORD
    SeSetSecurityDescriptorInfo PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
    SeSinglePrivilegeCheck PROTO :XWORD, :XWORD, :XWORD
    SeTokenImpersonationLevel PROTO :XWORD
    SeTokenType PROTO :XWORD
    SeUnlockSubjectContext PROTO :XWORD
    SeUnregisterLogonSessionTerminatedRoutine PROTO :XWORD
    SeValidSecurityDescriptor PROTO :XWORD, :XWORD
    tolower PROTO :XWORD
    toupper PROTO :XWORD
    towlower PROTO :XWORD
    towupper PROTO :XWORD
    vsprintf PROTO :XPTR, :XPTR, :VARARG
    wcscat PROTO :XPTR, :XPTR
    wcschr PROTO :XPTR, :XWORD
    wcscmp PROTO :XPTR, :XPTR
    wcscpy PROTO :XPTR, :XPTR
    wcscspn PROTO :XPTR, :XPTR
    wcslen PROTO :XPTR
    wcsncat PROTO :XPTR, :XPTR, :SIZE_T
    wcsncmp PROTO :XPTR, :XPTR, :SIZE_T
    wcsncpy PROTO :XPTR, :XPTR, :SIZE_T
    wcsrchr PROTO :XPTR, :SIZE_T
    wcsspn PROTO :XPTR, :XPTR
    wcsstr PROTO :XPTR, :XPTR
    wcstombs PROTO :XPTR, :XPTR, :SIZE_T
    wctomb PROTO :XPTR, :XWORD
    ZwAccessCheckAndAuditAlarm PROTO :XPTR, :PVOID, :XPTR, :XPTR, :XPTR, :XWORD, :XPTR, :XWORD, :XPTR, :XPTR, :XPTR
    ZwAlertThread PROTO :HANDLE
    ZwAllocateVirtualMemory PROTO :HANDLE, :PVOID, :XPTR, :XPTR, :XWORD, :XWORD
    ZwClearEvent PROTO :HANDLE
    ZwClose PROTO :HANDLE
    ZwCloseObjectAuditAlarm PROTO :XPTR, :PVOID, :XWORD
    ZwConnectPort PROTO :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR
    ZwCreateDirectoryObject PROTO :XPTR, :XWORD, :XPTR
    ZwCreateEvent PROTO :XPTR, :XWORD, :XPTR, :XWORD, :XWORD
    ZwCreateFile PROTO :XPTR, :XWORD, :XPTR, :XPTR, :XPTR, :XWORD, :XWORD, :XWORD, :XWORD, :PVOID, :XWORD
    ZwCreateKey PROTO :XPTR, :XWORD, :XPTR, :XWORD, :XPTR, :XWORD, :XPTR
    ZwCreateSection PROTO :XPTR, :XWORD, :XPTR, :XPTR, :XWORD, :XWORD, :HANDLE
    ZwCreateSymbolicLinkObject PROTO :XPTR, :XWORD, :XPTR, :XPTR
    ZwDeleteFile PROTO :XPTR
    ZwDeleteKey PROTO :HANDLE
    ZwDeleteValueKey PROTO :HANDLE, :XPTR
    ZwDeviceIoControlFile PROTO :HANDLE, :HANDLE, :XPTR, :PVOID, :XPTR, :XWORD, :PVOID, :XWORD, :PVOID, :XWORD
    ZwDisplayString PROTO :XPTR
    ZwDuplicateObject PROTO :HANDLE, :HANDLE, :HANDLE, :HANDLE, :XWORD, :XWORD, :XWORD
    ZwDuplicateToken PROTO :HANDLE, :XWORD, :XPTR, :XWORD, :XWORD, :XPTR
    ZwEnumerateKey PROTO :HANDLE, :XWORD, :XWORD, :PVOID, :XWORD, :XPTR
    ZwEnumerateValueKey PROTO :HANDLE, :XWORD, :XWORD, :PVOID, :XWORD, :XPTR
    ZwFlushInstructionCache PROTO :HANDLE, :PVOID, :SIZE_T
    ZwFlushKey PROTO :HANDLE
    ZwFreeVirtualMemory PROTO :HANDLE, :PVOID, :XPTR, :XWORD
    ZwFsControlFile PROTO :HANDLE, :HANDLE, :XPTR, :PVOID, :XPTR, :XWORD, :PVOID, :XWORD, :PVOID, :XWORD
    ZwLoadDriver PROTO :XPTR
    ZwLoadKey PROTO :XPTR, :XPTR
    ZwMakeTemporaryObject PROTO :HANDLE
    ZwMapViewOfSection PROTO :HANDLE, :HANDLE, :PVOID, :XPTR, :SIZE_T, :XPTR, :XPTR, :XWORD, :XWORD, :XWORD
    ZwNotifyChangeKey PROTO :HANDLE, :HANDLE, :XPTR, :PVOID, :XPTR, :XWORD, :XWORD, :PVOID, :XWORD, :XWORD
    ZwOpenDirectoryObject PROTO :XPTR, :XWORD, :XPTR
    ZwOpenEvent PROTO :XPTR, :XWORD, :XPTR
    ZwOpenFile PROTO :XPTR, :XWORD, :XPTR, :XPTR, :XWORD, :XWORD
    ZwOpenKey PROTO :XPTR, :XWORD, :XPTR
    ZwOpenProcess PROTO :XPTR, :XWORD, :XPTR, :XPTR
    ZwOpenProcessToken PROTO :HANDLE, :XWORD, :XPTR
    ZwOpenSection PROTO :XPTR, :XWORD, :XPTR
    ZwOpenSymbolicLinkObject PROTO :XPTR, :XWORD, :XPTR
    ZwOpenThread PROTO :XPTR, :XWORD, :XPTR, :XPTR
    ZwOpenThreadToken PROTO :HANDLE, :XWORD, :XWORD, :XPTR
    ZwPulseEvent PROTO :HANDLE, :XPTR
    ZwQueryDefaultLocale PROTO :XWORD, :XPTR
    ZwQueryDirectoryFile PROTO :HANDLE, :HANDLE, :XPTR, :PVOID, :XPTR, :PVOID, :XWORD, :XWORD, :XWORD, :XPTR, :XWORD
    ZwQueryInformationFile PROTO :HANDLE, :XPTR, :PVOID, :XWORD, :XWORD
    ZwQueryInformationProcess PROTO :HANDLE, :XWORD, :PVOID, :XWORD, :XPTR
    ZwQueryInformationToken PROTO :HANDLE, :XWORD, :PVOID, :XWORD, :XPTR
    ZwQueryKey PROTO :HANDLE, :XWORD, :PVOID, :XWORD, :XPTR
    ZwQueryObject PROTO :HANDLE, :XWORD, :PVOID, :XWORD, :XPTR
    ZwQuerySection PROTO :HANDLE, :XWORD, :PVOID, :SIZE_T, :XPTR
    ZwQuerySecurityObject PROTO :HANDLE, :XWORD, :XPTR, :XWORD, :XPTR
    ZwQuerySymbolicLinkObject PROTO :HANDLE, :XPTR, :XPTR
    ZwQuerySystemInformation PROTO :XWORD, :PVOID, :XWORD, :XPTR
    ZwQueryValueKey PROTO :HANDLE, :XPTR, :XWORD, :PVOID, :XWORD, :XPTR
    ZwQueryVolumeInformationFile PROTO :HANDLE, :XPTR, :PVOID, :XWORD, :XWORD
    ZwReadFile PROTO :HANDLE, :HANDLE, :XPTR, :PVOID, :XPTR, :PVOID, :XWORD, :XPTR, :XPTR
    ZwReplaceKey PROTO :XPTR, :HANDLE, :XPTR
    ZwRequestWaitReplyPort PROTO :HANDLE, :XPTR, :XPTR
    ZwResetEvent PROTO :HANDLE, :XPTR
    ZwSaveKey PROTO :HANDLE, :HANDLE
    ZwSetDefaultLocale PROTO :XWORD, :XWORD
    ZwSetEvent PROTO :HANDLE, :XPTR
    ZwSetInformationFile PROTO :HANDLE, :XPTR, :PVOID, :XWORD, :XWORD
    ZwSetInformationObject PROTO :HANDLE, :XWORD, :PVOID, :XWORD
    ZwSetInformationProcess PROTO :HANDLE, :XWORD, :PVOID, :XWORD
    ZwSetInformationThread PROTO :HANDLE, :XWORD, :PVOID, :XWORD
    ZwSetSystemInformation PROTO :XWORD, :PVOID, :XWORD
    ZwSetSystemTime PROTO :XPTR, :XPTR
    ZwSetValueKey PROTO :HANDLE, :XPTR, :XWORD, :XWORD, :PVOID, :XWORD
    ZwTerminateProcess PROTO :HANDLE, :XWORD
    ZwUnloadDriver PROTO :XPTR
    ZwUnloadKey PROTO :XPTR
    ZwUnmapViewOfSection PROTO :HANDLE, :PVOID
    ZwWaitForMultipleObjects PROTO :XWORD, :HANDLE, :XWORD, :XWORD, :XPTR
    ZwWaitForSingleObject PROTO :HANDLE, :XWORD, :XPTR
    ZwWriteFile PROTO :HANDLE, :HANDLE, :XPTR, :PVOID, :XPTR, :PVOID, :XWORD, :XPTR, :XPTR
    ZwYieldExecution PROTO
    IFNDEF __C_specific_handler
        __C_specific_handler PROTO :XPTR, :XWORD, :XPTR, :XPTR 
    ENDIF
    IFNDEF __chkstk
        __chkstk PROTO
    ENDIF
    _itoa PROTO :XWORD, :XPTR, :XWORD
    _purecall PROTO
    _snprintf PROTO :XPTR, :SIZE_T, :XPTR, :VARARG
    _stricmp PROTO :XPTR, :XPTR
    _strlwr PROTO :XPTR
    _strnicmp PROTO :XPTR, :XPTR, :SIZE_T
    _strnset PROTO :XPTR, :XWORD, :SIZE_T
    _strrev PROTO :XPTR
    _strset PROTO :XPTR, :XWORD
    _strupr PROTO :XPTR
    _vsnprintf PROTO :XPTR, :SIZE_T, :XPTR, :VARARG
    _wcsicmp PROTO :XPTR, :XPTR
    _wcslwr PROTO :XPTR
    _wcsnicmp PROTO :XPTR, :XPTR, :SIZE_T
    _wcsnset PROTO :XPTR, :XWORD, :SIZE_T
    _wcsrev PROTO :XPTR
    _wcsupr PROTO :XPTR

    IF (NTDDI_VERSION GE NTDDI_WIN2K)
        CcGetFlushedValidData PROTO :XPTR, :XWORD
        CcRemapBcb PROTO :XWORD
        CcWaitForCurrentLazyWriterActivity PROTO
        ExFreePoolWithTag PROTO :XWORD, :XWORD
        ExSetTimerResolution PROTO :XWORD, :XWORD
        ExUuidCreate PROTO :XWORD
        FsRtlAllocateFileLock PROTO :XWORD, :XWORD
        FsRtlCreateSectionForDataScan PROTO :XPTR, :PVOID, :XPTR, :XPTR, :XWORD, :XPTR, :XPTR, :XWORD, :XWORD, :XWORD
        FsRtlFreeFileLock PROTO :XPTR
        FsRtlInsertPerFileObjectContext PROTO :XWORD, :XWORD
        FsRtlInsertPerStreamContext PROTO :XWORD, :XWORD
        FsRtlIsPagingFile PROTO :XWORD
        FsRtlLookupLastLargeMcbEntryAndIndex PROTO :XWORD, :XWORD, :XWORD, :XWORD
        FsRtlLookupPerFileObjectContext PROTO :XWORD, :XWORD, :XWORD
        FsRtlLookupPerStreamContextInternal PROTO :XWORD, :XWORD, :XWORD
        FsRtlNotifyFilterChangeDirectory PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        FsRtlNotifyFilterReportChange PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        FsRtlNotifyVolumeEvent PROTO :XWORD, :XWORD
        FsRtlRegisterFileSystemFilterCallbacks PROTO :XWORD, :XWORD
        FsRtlReleaseFile PROTO :XWORD
        FsRtlRemovePerFileObjectContext PROTO :XWORD, :XWORD, :XWORD
        FsRtlRemovePerStreamContext PROTO :XWORD, :XWORD, :XWORD
        FsRtlResetBaseMcb PROTO :XPTR
        FsRtlResetLargeMcb PROTO :XWORD, :XWORD
        FsRtlTeardownPerStreamContexts PROTO :XWORD
        InbvAcquireDisplayOwnership PROTO
        InbvCheckDisplayOwnership PROTO
        InbvDisplayString PROTO :XWORD
        InbvEnableBootDriver PROTO :XWORD
        InbvEnableDisplayString PROTO :XWORD
        InbvInstallDisplayStringFilter PROTO :XWORD
        InbvIsBootDriverInstalled PROTO
        InbvNotifyDisplayOwnershipLost PROTO :XWORD
        InbvResetDisplay PROTO
        InbvSetScrollRegion PROTO :XWORD, :XWORD, :XWORD, :XWORD
        InbvSetTextColor PROTO :XWORD
        InbvSolidColorFill PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        IoAcquireCancelSpinLock PROTO :XWORD
        IoAcquireRemoveLockEx PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        IoAllocateDriverObjectExtension PROTO :XWORD, :XWORD, :XWORD, :XWORD
        IoAllocateWorkItem PROTO :XWORD
        IoAttachDeviceToDeviceStackSafe PROTO :XWORD, :XWORD, :XWORD
        IoCancelFileOpen PROTO :XWORD, :XWORD
        IoCheckQuerySetFileInformation PROTO :XWORD, :XWORD, :XWORD
        IoCheckQuerySetVolumeInformation PROTO :XWORD, :XWORD, :XWORD
        IoCheckQuotaBufferValidity PROTO :XWORD, :XWORD, :XWORD
        IoCreateDriver PROTO :XWORD, :XWORD
        IoCreateFileSpecifyDeviceObjectHint PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        IoCreateStreamFileObjectLite PROTO :XWORD, :XWORD
        IoDeleteDriver PROTO :XWORD
        IoEnumerateDeviceObjectList PROTO :XWORD, :XWORD, :XWORD, :XWORD
        IoEnumerateRegisteredFiltersList PROTO :XPTR, :XWORD, :XPTR
        IoFreeWorkItem PROTO :XWORD
        IoGetAttachedDeviceReference PROTO :XWORD
        IoGetBootDiskInformation PROTO :XWORD, :XWORD
        IoGetDeviceAttachmentBaseRef PROTO :XWORD
        IoGetDeviceInterfaceAlias PROTO :XWORD, :XWORD, :XWORD
        IoGetDeviceInterfaces PROTO :XWORD, :XWORD, :XWORD, :XWORD
        IoGetDeviceProperty PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        IoGetDiskDeviceObject PROTO :XWORD, :XWORD
        IoGetDmaAdapter PROTO :XWORD, :XWORD, :XWORD
        IoGetDriverObjectExtension PROTO :XWORD, :XWORD
        IoGetLowerDeviceObject PROTO :XWORD
        IoGetRequestorProcessId PROTO :XWORD
        IoGetRequestorSessionId PROTO :XWORD, :XWORD
        IoInitializeRemoveLockEx PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        IoInvalidateDeviceRelations PROTO :XWORD, :XWORD
        IoInvalidateDeviceState PROTO :XWORD
        IoIsFileOriginRemote PROTO :XWORD
        IoIsValidNameGraftingBuffer PROTO :XWORD, :XWORD
        IoIsWdmVersionAvailable PROTO :XWORD, :XWORD
        IoOpenDeviceInterfaceRegistryKey PROTO :XWORD, :XWORD, :XWORD
        IoOpenDeviceRegistryKey PROTO :XWORD, :XWORD, :XWORD, :XWORD
        IoQueueWorkItem PROTO :XWORD, :XWORD, :XWORD, :XWORD
        IoRegisterBootDriverReinitialization PROTO :XWORD, :XWORD, :XWORD
        IoRegisterDeviceInterface PROTO :XWORD, :XWORD, :XWORD, :XWORD
        IoRegisterLastChanceShutdownNotification PROTO :XWORD
        IoRegisterPlugPlayNotification PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        IoReleaseRemoveLockAndWaitEx PROTO :XWORD, :XWORD, :XWORD
        IoReleaseRemoveLockEx PROTO :XWORD, :XWORD, :XWORD
        IoReportDetectedDevice PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        IoReportResourceForDetection PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        IoReportTargetDeviceChange PROTO :XWORD, :XWORD
        IoReportTargetDeviceChangeAsynchronous PROTO :XWORD, :XWORD, :XWORD, :XWORD
        IoRequestDeviceEject PROTO :XWORD
        IoReuseIrp PROTO :XWORD, :XWORD
        IoSetDeviceInterfaceState PROTO :XWORD, :XWORD
        IoSetFileOrigin PROTO :XWORD, :XWORD
        IoSetIoCompletion PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        IoSynchronousInvalidateDeviceRelations PROTO :XWORD, :XWORD
        IoUnregisterPlugPlayNotification PROTO :PVOID
        IoVolumeDeviceToDosName PROTO :XWORD, :XWORD
        IoWMIAllocateInstanceIds PROTO :XWORD, :XWORD, :XWORD
        IoWMIRegistrationControl PROTO :XWORD, :XWORD
        IoWMISuggestInstanceName PROTO :XWORD, :XWORD, :XWORD, :XWORD
        IoWMIWriteEvent PROTO :XWORD
        KdDisableDebugger PROTO
        KdEnableDebugger PROTO
        KeQueryActiveProcessors PROTO
        KeQueryPriorityThread PROTO :XWORD
        KeSaveStateForHibernate PROTO :XWORD
        KeSetSystemAffinityThread PROTO :XWORD
        KeStackAttachProcess PROTO :XWORD, :XWORD
        KeUnstackDetachProcess PROTO :XWORD
        LpcRequestWaitReplyPort PROTO :XWORD, :XWORD, :XWORD
        MmAddPhysicalMemory PROTO :XWORD, :XWORD
        MmAddVerifierThunks PROTO :XWORD, :XWORD
        MmAllocateContiguousMemorySpecifyCache PROTO :SIZE_T, :XWORD, :XWORD, :XWORD, :XWORD
        MmAllocateMappingAddress PROTO :XWORD, :XWORD
        MmAllocatePagesForMdl PROTO :XWORD, :XWORD, :XWORD, :SIZE_T
        MmCommitSessionMappedView PROTO :XWORD, :XWORD
        MmFreeContiguousMemorySpecifyCache PROTO :XWORD, :XWORD, :XWORD
        MmFreeMappingAddress PROTO :XWORD, :XWORD
        MmFreePagesFromMdl PROTO :XWORD
        MmGetPhysicalMemoryRanges PROTO
        MmGetSystemRoutineAddress PROTO :XWORD
        MmGetVirtualForPhysical PROTO :XWORD, :XWORD
        MmIsDriverVerifying PROTO :XWORD
        MmIsVerifierEnabled PROTO :XWORD
        MmMapLockedPagesWithReservedMapping PROTO :XWORD, :XWORD, :XWORD, :XWORD
        MmMapUserAddressesToPage PROTO :XWORD, :XWORD, :XWORD
        MmMapViewInSessionSpace PROTO :XWORD, :XWORD, :XWORD
        MmProbeAndLockProcessPages PROTO :XWORD, :XWORD, :XWORD, :XWORD
        MmProbeAndLockSelectedPages PROTO :XWORD, :XWORD, :XWORD, :XWORD
        MmRemovePhysicalMemory PROTO :XWORD, :XWORD
        MmTrimAllSystemPagableMemory PROTO :XWORD
        MmUnmapReservedMapping PROTO :XWORD, :XWORD, :XWORD
        MmUnmapViewInSessionSpace PROTO :XWORD
        NtQueryQuotaInformationFile PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        NtQuerySystemInformation PROTO :XWORD, :XPTR, :XWORD, :XPTR
        NtSetEaFile PROTO :XWORD, :XWORD, :XWORD, :XWORD
        NtSetVolumeInformationFile PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        ObCreateObjectType PROTO :XWORD, :XWORD, :XWORD, :XWORD
        IF (NTDDI_VERSION EQ NTDDI_WINXP)
            WmiTraceFastEvent PROTO :XPTR
        ELSE
            ObDeleteCapturedInsertInfo PROTO :PVOID
        ENDIF
        PoCallDriver PROTO :XWORD, :XWORD
        PoCancelDeviceNotify PROTO :XWORD
        PoRegisterDeviceForIdleDetection PROTO :XWORD, :XWORD, :XWORD, :XWORD
        PoRegisterDeviceNotify PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        PoRegisterSystemState PROTO :XWORD, :XWORD
        PoRequestPowerIrp PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        PoSetHiberRange PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        PoSetPowerState PROTO :XWORD, :XWORD, :XWORD
        PoSetSystemState PROTO :XWORD
        PoShutdownBugCheck PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        PoStartNextPowerIrp PROTO :XWORD
        PoUnregisterSystemState PROTO :XWORD
        ProbeForRead PROTO :XWORD, :XWORD, :XWORD
        PsDisableImpersonation PROTO :XWORD, :XWORD
        PsGetProcessId PROTO :XWORD
        PsGetProcessImageFileName PROTO :XWORD
        PsRestoreImpersonation PROTO :XWORD, :XWORD
        PsSetLoadImageNotifyRoutine PROTO :XWORD
        RtlAddAccessAllowedAceEx PROTO :XPTR, :XWORD, :XWORD, :XWORD, :XPTR
        RtlAddRange PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        RtlCaptureContext PROTO :XPTR
        RtlCopyRangeList PROTO :XWORD, :XWORD
        RtlDeleteAce PROTO :XWORD, :XWORD
        RtlDeleteOwnersRanges PROTO :XWORD, :XWORD
        RtlDeleteRange PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        RtlFindClearRuns PROTO :XWORD, :XWORD, :XWORD, :XWORD
        RtlFindLastBackwardRunClear PROTO :XWORD, :XWORD, :XWORD
        RtlFindLeastSignificantBit PROTO :XWORD, :XWORD
        RtlFindMostSignificantBit PROTO :XWORD, :XWORD
        RtlFindNextForwardRunClear PROTO :XWORD, :XWORD, :XWORD
        RtlFindRange PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        RtlFreeRangeList PROTO :XWORD
        RtlGetAce PROTO :XWORD, :XWORD, :XWORD
        RtlGetFirstRange PROTO :XWORD, :XWORD, :XWORD
        RtlGetNextRange PROTO :XWORD, :XWORD, :XWORD
        RtlGetNtGlobalFlags PROTO
        RtlGetSaclSecurityDescriptor PROTO :XWORD, :XWORD, :XWORD, :XWORD
        RtlGUIDFromString PROTO :XWORD, :XWORD
        RtlImageDirectoryEntryToData PROTO :XWORD, :XWORD, :XWORD, :XWORD
        RtlInitializeRangeList PROTO :XWORD
        RtlInsertElementGenericTableFull PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        RtlInvertRangeList PROTO :XWORD, :XWORD
        RtlIsGenericTableEmpty PROTO :XWORD
        RtlIsRangeAvailable PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        RtlIsValidOemCharacter PROTO :XWORD
        RtlLargeIntegerAdd PROTO :XWORD, :XWORD, :XWORD, :XWORD
        RtlLookupElementGenericTableFull PROTO :XWORD, :XWORD, :XWORD, :XWORD
        RtlMergeRangeLists PROTO :XWORD, :XWORD, :XWORD, :XWORD
        RtlPrefetchMemoryNonTemporal PROTO :PVOID, :SIZE_T
        RtlRealPredecessor PROTO :XWORD
        RtlRealSuccessor PROTO :XWORD
        RtlSelfRelativeToAbsoluteSD PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        RtlSelfRelativeToAbsoluteSD2 PROTO :XWORD, :XWORD
        RtlSizeHeap PROTO :XWORD, :XWORD, :XWORD
        RtlStringFromGUID PROTO :XWORD, :XWORD
        RtlSubtreePredecessor PROTO :XWORD
        RtlSubtreeSuccessor PROTO :XWORD
        RtlTraceDatabaseAdd PROTO :XWORD, :XWORD, :XWORD, :XWORD
        RtlTraceDatabaseCreate PROTO :XWORD, :SIZE_T, :XWORD, :XWORD, :XPTR
        RtlTraceDatabaseDestroy PROTO :XWORD
        RtlTraceDatabaseEnumerate PROTO :XWORD, :XWORD, :XWORD
        RtlTraceDatabaseFind PROTO :XWORD, :XWORD, :XWORD, :XWORD
        RtlTraceDatabaseLock PROTO :XWORD
        RtlTraceDatabaseUnlock PROTO :XWORD
        RtlTraceDatabaseValidate PROTO :XWORD
        RtlValidRelativeSecurityDescriptor PROTO :XWORD, :XWORD, :XWORD
        RtlVolumeDeviceToDosName PROTO :XWORD, :XWORD
        RtlWalkFrameChain PROTO :XWORD, :XWORD, :XWORD
        SeAssignSecurityEx PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        SeAuditHardLinkCreation PROTO :XWORD, :XWORD, :XWORD
        SeAuditingHardLinkEvents PROTO :XWORD, :XWORD
        SeCreateClientSecurityFromSubjectContext PROTO :XWORD, :XWORD, :XWORD, :XWORD
        SeImpersonateClientEx PROTO :XWORD, :XWORD
        SeQueryInformationToken PROTO :XWORD, :XWORD, :XWORD
        SeQuerySessionIdToken PROTO :XWORD, :XWORD
        SeSetSecurityDescriptorInfoEx PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        SeTokenIsAdmin PROTO :XWORD
        SeTokenIsRestricted PROTO :XWORD
        VerSetConditionMask PROTO :XWORD, :XWORD, :XWORD
        ZwAdjustPrivilegesToken PROTO :HANDLE, :XWORD, :XPTR, :XWORD, :XPTR, :XPTR
        ZwCancelIoFile PROTO :HANDLE, :XPTR
        ZwCancelTimer PROTO :HANDLE, :XPTR
        ZwCreateTimer PROTO :XPTR, :XWORD, :XPTR, :XWORD
        ZwFlushVirtualMemory PROTO :HANDLE, :PVOID, :XPTR, :XPTR
        ZwInitiatePowerAction PROTO :XWORD, :XWORD, :XWORD, :XWORD
        ZwOpenTimer PROTO :XPTR, :XWORD, :XPTR
        ZwPowerInformation PROTO :XWORD, :PVOID, :XWORD, :PVOID, :XWORD
        ZwQueryDefaultUILanguage PROTO :XPTR
        ZwQueryDirectoryObject PROTO :HANDLE, :PVOID, :XWORD, :XWORD, :XWORD, :XPTR, :XPTR
        ZwQueryEaFile PROTO :HANDLE, :XPTR, :PVOID, :XWORD, :XWORD, :PVOID, :XWORD, :XPTR, :XWORD
        ZwQueryInstallUILanguage PROTO :XPTR
        ZwRestoreKey PROTO :HANDLE, :HANDLE, :XWORD
        ZwSetDefaultUILanguage PROTO :XWORD
        ZwSetEaFile PROTO :HANDLE, :XPTR, :PVOID, :XWORD
        ZwSetSecurityObject PROTO :HANDLE, :XWORD, :XPTR
        ZwSetTimer PROTO :HANDLE, :XPTR, :XPTR, :PVOID, :XWORD, :XWORD, :XPTR
        ZwSetVolumeInformationFile PROTO :HANDLE, :XPTR, :PVOID, :XWORD, :XWORD
        _itow PROTO :XWORD, :XPTR, :XWORD
    ENDIF

    IF (NTDDI_VERSION EQ NTDDI_WINXP OR NTDDI_VERSION EQ NTDDI_VISTA)
        IFDEF APP_WIN64
            _alldiv PROTO :LONGLONG, :LONGLONG
            _alldvrm PROTO
            _allmul PROTO :LONGLONG, :LONGLONG
            _allrem PROTO :LONGLONG, :LONGLONG
            _allshl PROTO :LONGLONG, :XWORD
            _allshr PROTO :LONGLONG, :XWORD
            _aulldiv PROTO :LONGLONG, :LONGLONG
            _aulldvrm PROTO :LONGLONG, :LONGLONG
            _aullrem PROTO :LONGLONG, :LONGLONG
            _aullshr PROTO :LONGLONG, :XWORD
            _except_handler2 PROTO :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR
            _except_handler3 PROTO :XPTR, :XPTR, :XPTR, :XPTR
            _global_unwind2 PROTO :XPTR
            _local_unwind2 PROTO :XPTR, :XWORD
        ENDIF
        IoAssignDriveLetters PROTO :XPTR, :XPTR, :XPTR, :XPTR
    ENDIF

    IF (NTDDI_VERSION GE NTDDI_WINXP)
        CcMdlWriteAbort PROTO :XPTR, :XPTR
        CmRegisterCallback PROTO :XWORD, :XWORD, :XWORD
        CmUnRegisterCallback PROTO :XWORD, :XWORD
        DbgPrintEx PROTO :XWORD, :XWORD, :XPTR, :VARARG
        DbgPrintReturnControlC PROTO :XPTR, :VARARG
        DbgQueryDebugFilterState PROTO :XWORD, :XWORD
        DbgSetDebugFilterState PROTO :XWORD, :XWORD, :XWORD
        ExAcquireRundownProtection PROTO :XPTR
        ExAcquireRundownProtectionEx PROTO :XPTR, :XWORD
        ExAllocateFromPagedLookasideList PROTO :XWORD
        ExfAcquirePushLockExclusive PROTO :XPTR
        ExfAcquirePushLockShared PROTO :XPTR
        ExfReleasePushLock PROTO :XPTR
        ExGetCurrentProcessorCounts PROTO :XWORD, :XWORD, :XWORD
        ExGetCurrentProcessorCpuUsage PROTO :XWORD
        ExInitializeRundownProtection PROTO :XPTR
        ExReInitializeRundownProtection PROTO :XPTR
        ExReleaseRundownProtection PROTO :XPTR
        ExReleaseRundownProtectionEx PROTO :XPTR, :XWORD
        ExRundownCompleted PROTO :XPTR
        ExVerifySuite PROTO :XWORD
        ExWaitForRundownProtectionRelease PROTO :XPTR
        FsRtlAcquireFileExclusive PROTO :XPTR
        FsRtlIncrementCcFastReadNotPossible PROTO
        FsRtlIncrementCcFastReadNoWait PROTO
        FsRtlIncrementCcFastReadResourceMiss PROTO
        FsRtlIncrementCcFastReadWait PROTO
        HalExamineMBR PROTO :XPTR, :XWORD, :XWORD, :PVOID
        HeadlessDispatch PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        InitializeSListHead PROTO :XPTR
        IoCreateDisk PROTO :XWORD, :XWORD
        IoCreateStreamFileObjectEx PROTO :XWORD, :XWORD, :XWORD
        IoCsqInitialize PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        IoCsqInsertIrp PROTO :XWORD, :XWORD, :XWORD
        IoCsqRemoveIrp PROTO :XWORD, :XWORD
        IoCsqRemoveNextIrp PROTO :XWORD, :XWORD
        IoForwardAndCatchIrp PROTO :XWORD, :XWORD
        IoForwardIrpSynchronously PROTO :XWORD, :XWORD
        IoFreeErrorLogEntry PROTO :XWORD
        IoQueryFileDosDeviceName PROTO :XWORD, :XWORD
        IoReadDiskSignature PROTO :XWORD, :XWORD, :XWORD
        IoReadPartitionTable PROTO :XPTR, :XWORD, :XWORD, :XPTR
        IoReadPartitionTableEx PROTO :XWORD, :XWORD
        IoSetCompletionRoutineEx PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        IoSetPartitionInformation PROTO :XPTR, :XWORD, :XWORD, :XWORD
        IoSetPartitionInformationEx PROTO :XPTR, :XWORD, :XPTR
        IoSetStartIoAttributes PROTO :XWORD, :XWORD, :XWORD
        IoSetSystemPartition PROTO :XWORD
        IoValidateDeviceIoControlAccess PROTO :XWORD, :XWORD
        IoVerifyPartitionTable PROTO :XWORD, :XWORD
        IoWMIDeviceObjectToInstanceName PROTO :XWORD, :XWORD, :XWORD
        IoWMIExecuteMethod PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        IoWMIHandleToInstanceName PROTO :XWORD, :XWORD, :XWORD
        IoWMIOpenBlock PROTO :XWORD, :XWORD, :XWORD
        IoWMIQueryAllData PROTO :XWORD, :XWORD, :XWORD
        IoWMIQueryAllDataMultiple PROTO :XWORD, :XWORD, :XWORD, :XWORD
        IoWMIQuerySingleInstance PROTO :XWORD, :XWORD, :XWORD, :XWORD
        IoWMIQuerySingleInstanceMultiple PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        IoWMISetNotificationCallback PROTO :XWORD, :XWORD, :XWORD
        IoWMISetSingleInstance PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        IoWMISetSingleItem PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        IoWritePartitionTable PROTO :XPTR, :XWORD, :XWORD, :XWORD, :XPTR
        IoWritePartitionTableEx PROTO :XPTR, :XPTR
        KdPowerTransition PROTO :XWORD
        KeAcquireInStackQueuedSpinLockAtDpcLevel PROTO :XPTR, :XPTR
        KeAcquireInterruptSpinLock PROTO :XWORD
        KeAreApcsDisabled PROTO
        KeCapturePersistentThreadState PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        KeDeregisterBugCheckReasonCallback PROTO :XWORD
        KeFlushQueuedDpcs PROTO
        KeGetRecommendedSharedDataAlignment PROTO
        KeIsAttachedProcess PROTO
        KeQueryRuntimeThread PROTO :XWORD, :XWORD
        KeRegisterBugCheckReasonCallback PROTO :XWORD, :XWORD, :XWORD, :XWORD
        KeReleaseInterruptSpinLock PROTO :XWORD, :XWORD
        KeRemoveByKeyDeviceQueueIfBusy PROTO :XWORD, :XWORD
        KeRemoveSystemServiceTable PROTO :XWORD
        KeRestoreExtendedProcessorState PROTO :XPTR
        KeRevertToUserAffinityThreadEx PROTO :XWORD
        MmAdvanceMdl PROTO :XWORD, :XWORD
        MmMarkPhysicalMemoryAsBad PROTO :XWORD, :XWORD
        MmMarkPhysicalMemoryAsGood PROTO :XWORD, :XWORD
        MmPrefetchPages PROTO :XWORD, :XWORD
        MmProtectMdlSystemAddress PROTO :XWORD, :XWORD
        NtMakePermanentObject PROTO :XWORD
        NtOpenProcessTokenEx PROTO :XWORD, :XWORD, :XWORD, :XWORD
        NtOpenThread PROTO :XWORD, :XWORD, :XWORD, :XWORD
        NtOpenThreadToken PROTO :XWORD, :XWORD, :XWORD, :XWORD
        NtOpenThreadTokenEx PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        NtQueryInformationThread PROTO :HANDLE, :XWORD, :XPTR, :XWORD, :XPTR
        NtShutdownSystem PROTO :XWORD
        NtTraceEvent PROTO :XWORD, :XWORD, :XWORD, :XWORD
        ObCloseHandle PROTO :XWORD, :XWORD
        ObIsDosDeviceLocallyMapped PROTO :XWORD, :XPTR
        ObLogSecurityDescriptor PROTO :XWORD, :XWORD, :XWORD
        ObReferenceSecurityDescriptor PROTO :XWORD, :XWORD
        ObSetHandleAttributes PROTO :XWORD, :XWORD, :XWORD
        ObSetSecurityObjectByPointer PROTO :XWORD, :XWORD, :XWORD
        PoRequestShutdownEvent PROTO :XWORD
        PsChargeProcessNonPagedPoolQuota PROTO :XWORD, :XWORD
        PsChargeProcessPagedPoolQuota PROTO :XWORD, :XWORD
        PsChargeProcessPoolQuota PROTO :XWORD, :XWORD, :XWORD
        IF (NTDDI_VERSION LT NTDDI_VISTA)
            PsCreateSystemProcess PROTO :XWORD, :XWORD, :XWORD
        ENDIF
        PsDereferenceImpersonationToken PROTO :XWORD
        PsDereferencePrimaryToken PROTO :XWORD
        PsGetContextThread PROTO :XWORD, :XWORD, :XWORD
        PsGetCurrentProcess PROTO
        PsGetCurrentProcessSessionId PROTO
        PsGetCurrentThread PROTO
        PsGetCurrentThreadPreviousMode PROTO
        PsGetCurrentThreadStackBase PROTO
        PsGetCurrentThreadStackLimit PROTO
        PsGetJobLock PROTO :XWORD
        PsGetJobSessionId PROTO :XWORD
        PsGetJobUIRestrictionsClass PROTO :XWORD
        PsGetProcessCreateTimeQuadPart PROTO :XWORD
        PsGetProcessDebugPort PROTO :XWORD
        PsGetProcessExitProcessCalled PROTO :XWORD
        PsGetProcessExitStatus PROTO :XWORD
        PsGetProcessInheritedFromUniqueProcessId PROTO :XWORD
        PsGetProcessJob PROTO :XWORD
        PsGetProcessPeb PROTO :XWORD
        PsGetProcessPriorityClass PROTO :XWORD
        PsGetProcessSectionBaseAddress PROTO :XWORD
        PsGetProcessSecurityPort PROTO :XWORD
        PsGetProcessSessionId PROTO :XWORD
        PsGetProcessWin32Process PROTO :XWORD
        PsGetProcessWin32WindowStation PROTO :XWORD
        PsGetThreadFreezeCount PROTO :XWORD
        PsGetThreadHardErrorsAreDisabled PROTO :XWORD
        PsGetThreadId PROTO :XWORD
        PsGetThreadProcess PROTO :XWORD
        PsGetThreadProcessId PROTO :XWORD
        PsGetThreadSessionId PROTO :XWORD
        PsGetThreadTeb PROTO :XWORD
        PsGetThreadWin32Thread PROTO :XWORD
        PsIsProcessBeingDebugged PROTO :XWORD
        PsIsSystemThread PROTO :XWORD
        PsIsThreadImpersonating PROTO :XWORD
        PsRemoveCreateThreadNotifyRoutine PROTO :XWORD
        PsRemoveLoadImageNotifyRoutine PROTO :XWORD
        PsReturnProcessNonPagedPoolQuota PROTO :XWORD, :XWORD
        PsReturnProcessPagedPoolQuota PROTO :XWORD, :XWORD
        PsRevertThreadToSelf PROTO :XWORD
        PsSetContextThread PROTO :XWORD, :XWORD, :XWORD
        IF (NTDDI_VERSION EQ NTDDI_WINXP)
            WmiFlushTrace PROTO :XPTR
            WmiQueryTrace PROTO :XPTR
            WmiStartTrace PROTO :XPTR
            WmiStopTrace PROTO :XPTR
            WmiUpdateTrace PROTO :XPTR
        ELSEIF (NTDDI_VERSION LT NTDDI_WIN8)
            PsSetJobUIRestrictionsClass PROTO :XWORD, :XWORD
        ENDIF
        PsSetProcessPriorityClass PROTO :XWORD, :XWORD
        PsSetProcessSecurityPort PROTO :XWORD, :XWORD
        PsSetProcessWin32Process PROTO :XWORD, :XWORD, :XWORD
        PsSetProcessWindowStation PROTO :XWORD, :XWORD
        PsSetThreadHardErrorsAreDisabled PROTO :XWORD, :XWORD
        PsSetThreadWin32Thread PROTO :XWORD, :XWORD, :XWORD
        RtlClearBit PROTO :XWORD, :XWORD
        RtlCreateSystemVolumeInformationFolder PROTO :XWORD
        RtlDeleteElementGenericTableAvl PROTO :XWORD, :XWORD
        RtlEnumerateGenericTableAvl PROTO :XWORD, :XWORD
        RtlEnumerateGenericTableLikeADirectory PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        RtlEnumerateGenericTableWithoutSplayingAvl PROTO :XWORD, :XWORD
        RtlGetElementGenericTableAvl PROTO :XWORD, :XWORD
        RtlGetSetBootStatusData PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        RtlGetVersion PROTO :XWORD
        RtlHashUnicodeString PROTO :XWORD, :XWORD, :XWORD, :XWORD
        RtlInitializeGenericTableAvl PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        RtlInsertElementGenericTableAvl PROTO :XWORD, :XWORD, :XWORD, :XWORD
        RtlInsertElementGenericTableFullAvl PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        RtlInt64ToUnicodeString PROTO :XWORD, :XWORD, :XWORD, :XWORD
        RtlIntegerToUnicode PROTO :XWORD, :XWORD, :XWORD, :XWORD
        RtlIpv4AddressToStringA PROTO :XWORD, :XWORD
        RtlIpv4AddressToStringExA PROTO :XWORD, :XWORD, :XWORD, :XWORD
        RtlIpv4AddressToStringExW PROTO :XWORD, :XWORD, :XWORD, :XWORD
        RtlIpv4AddressToStringW PROTO :XWORD, :XWORD
        RtlIpv4StringToAddressA PROTO :XWORD, :XWORD, :XWORD, :XWORD
        RtlIpv4StringToAddressExA PROTO :XWORD, :XWORD, :XWORD, :XWORD
        RtlIpv4StringToAddressExW PROTO :XWORD, :XWORD, :XWORD, :XWORD
        RtlIpv4StringToAddressW PROTO :XWORD, :XWORD, :XWORD, :XWORD
        RtlIpv6AddressToStringA PROTO :XWORD, :XWORD
        RtlIpv6AddressToStringExA PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        RtlIpv6AddressToStringExW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        RtlIpv6AddressToStringW PROTO :XWORD, :XWORD
        RtlIpv6StringToAddressA PROTO :XWORD, :XWORD, :XWORD
        RtlIpv6StringToAddressExA PROTO :XWORD, :XWORD, :XWORD, :XWORD
        RtlIpv6StringToAddressExW PROTO :XWORD, :XWORD, :XWORD, :XWORD
        RtlIpv6StringToAddressW PROTO :XWORD, :XWORD, :XWORD
        RtlIsGenericTableEmptyAvl PROTO :XWORD
        RtlLockBootStatusData PROTO :XWORD
        RtlLookupElementGenericTableAvl PROTO :XWORD, :XWORD
        RtlLookupElementGenericTableFullAvl PROTO :XWORD, :XWORD, :XWORD, :XWORD
        RtlMapSecurityErrorToNtStatus PROTO :XWORD
        RtlNumberGenericTableElementsAvl PROTO :XWORD
        RtlRandomEx PROTO :XWORD
        RtlSetBit PROTO :XWORD, :XWORD
        RtlTestBit PROTO :XWORD, :XWORD
        RtlTimeToElapsedTimeFields PROTO :XWORD, :XWORD
        RtlVerifyVersionInfo PROTO :XWORD, :XWORD, :XWORD, :XWORD
        SeAuditingHardLinkEventsWithContext PROTO :XWORD, :XWORD, :XWORD
        SeReportSecurityEvent PROTO :XWORD, :XPTR, :XPTR, :XPTR
        SeTokenIsWriteRestricted PROTO :XWORD
        SeTokenObjectType PROTO :HANDLE, :XWORD, :XPTR, :XWORD, :PVOID, :XPTR
        vDbgPrintEx PROTO :XWORD, :XWORD, :XPTR, :VARARG
        vDbgPrintExWithPrefix PROTO :XPTR, :XWORD, :XWORD, :XPTR, :VARARG
        VfIsVerificationEnabled PROTO :XWORD, :PVOID
        WmiGetClock PROTO :XWORD, :XPTR
        WmiQueryTraceInformation PROTO :XWORD, :PVOID, :XWORD, :XPTR, :PVOID
        WmiTraceMessage PROTO :XWORD, :XWORD, :XPTR, :XWORD
        WmiTraceMessageVa PROTO :XWORD, :XWORD, :XPTR, :XWORD, :XWORD, :VARARG
        WRITE_REGISTER_BUFFER_UCHAR PROTO :XPTR, :XPTR, :XWORD
        WRITE_REGISTER_BUFFER_ULONG PROTO :XPTR, :XPTR, :XWORD
        WRITE_REGISTER_BUFFER_USHORT PROTO :XPTR, :XPTR, :XWORD
        WRITE_REGISTER_UCHAR PROTO :XPTR, :XWORD
        WRITE_REGISTER_ULONG PROTO :XPTR, :XWORD
        WRITE_REGISTER_USHORT PROTO :XPTR, :XWORD
        XIPDispatch PROTO :XWORD, :XPTR, :XWORD
        ZwAddBootEntry PROTO :XPTR, :XPTR
        ZwAssignProcessToJobObject PROTO :HANDLE, :HANDLE
        ZwCreateJobObject PROTO :XPTR, :XWORD, :XPTR
        ZwDeleteBootEntry PROTO :XPTR, :XPTR
        ZwEnumerateBootEntries PROTO :PVOID, :XPTR
        ZwIsProcessInJob PROTO :HANDLE, :HANDLE
        ZwOpenJobObject PROTO :XPTR, :XWORD, :XPTR
        ZwOpenProcessTokenEx PROTO :HANDLE, :XWORD, :XWORD, :XPTR
        ZwOpenThreadTokenEx PROTO :HANDLE, :XWORD, :XWORD, :XWORD, :XPTR
        ZwQueryBootEntryOrder PROTO :XPTR, :XPTR
        ZwQueryBootOptions PROTO :XPTR, :XPTR
        ZwQueryFullAttributesFile PROTO :XWORD, :XWORD
        ZwQueryInformationJobObject PROTO :HANDLE, :XWORD, :PVOID, :XWORD, :XPTR
        ZwQueryInformationThread PROTO :HANDLE, :XWORD, :PVOID, :XWORD, :XPTR
        ZwSaveKeyEx PROTO :HANDLE, :HANDLE, :XWORD
        ZwSetBootEntryOrder PROTO :XPTR, :XWORD
        ZwSetBootOptions PROTO :XPTR, :XWORD
        ZwSetInformationJobObject PROTO :HANDLE, :XWORD, :PVOID, :XWORD
        ZwTerminateJobObject PROTO :HANDLE, :XWORD
        ZwTranslateFilePath PROTO :XPTR, :XWORD, :XPTR, :XPTR
        _vsnwprintf PROTO :XPTR, :SIZE_T, :XPTR, :VARARG

        IFDEF APP_UNICODE
            RtlIpv4AddressToString EQU <RtlIpv4AddressToStringW>
            RtlIpv4AddressToStringEx EQU <RtlIpv4AddressToStringExW>
            RtlIpv4StringToAddress EQU <RtlIpv4StringToAddressW>
            RtlIpv4StringToAddressEx EQU <RtlIpv4StringToAddressExW>
            RtlIpv6AddressToString EQU <RtlIpv6AddressToStringW>
            RtlIpv6AddressToStringEx EQU <RtlIpv6AddressToStringExW>
            RtlIpv6StringToAddress EQU <RtlIpv6StringToAddressW>
            RtlIpv6StringToAddressEx EQU <RtlIpv6StringToAddressExW>
        ELSE
            RtlIpv4AddressToString EQU <RtlIpv4AddressToStringA>
            RtlIpv4AddressToStringEx EQU <RtlIpv4AddressToStringExA>
            RtlIpv4StringToAddress EQU <RtlIpv4StringToAddressA>
            RtlIpv4StringToAddressEx EQU <RtlIpv4StringToAddressExA>
            RtlIpv6AddressToString EQU <RtlIpv6AddressToStringA>
            RtlIpv6AddressToStringEx EQU <RtlIpv6AddressToStringExA>
            RtlIpv6StringToAddress EQU <RtlIpv6StringToAddressA>
            RtlIpv6StringToAddressEx EQU <RtlIpv6StringToAddressExA>
        ENDIF
    ENDIF

    IF (NTDDI_VERSION GE NTDDI_VISTA)
        AlpcGetHeaderSize PROTO :XWORD
        AlpcGetMessageAttribute PROTO :XPTR, :XWORD
        AlpcInitializeMessageAttribute PROTO :XWORD, :XPTR, :XWORD, :XPTR
        bsearch PROTO :XPTR, :XPTR, :XPTR, :XPTR, :XPTR
        CcGetFileObjectFromSectionPtrsRef PROTO :XPTR
        CcIsThereDirtyDataEx PROTO :XPTR, :XPTR
        CcSetFileSizesEx PROTO :XPTR, :XPTR
        CcSetParallelFlushFile PROTO :XPTR, :XWORD
        CmCallbackGetKeyObjectID PROTO :XPTR, :PVOID, :XPTR, :XPTR
        CmGetBoundTransaction PROTO :XPTR, :PVOID
        CmGetCallbackVersion PROTO :XPTR, :XPTR
        CmRegisterCallbackEx PROTO :XPTR, :XPTR, :PVOID, :PVOID, :XPTR, :PVOID
        CmSetCallbackObjectContext PROTO :PVOID, :XPTR, :PVOID, :PVOID
        DbgCommandString PROTO :XPTR, :XPTR
        DbgSetDebugPrintCallback PROTO :XPTR, :XWORD
        EmClientQueryRuleState PROTO :XPTR, :XPTR
        EtwActivityIdControl PROTO :XWORD, :XPTR
        EtwEventEnabled PROTO :XPTR, :XPTR
        EtwProviderEnabled PROTO :XPTR, :XWORD, :XWORD
        EtwRegister PROTO :XPTR, :XPTR, :PVOID, :XPTR
        EtwUnregister PROTO :XPTR
        EtwWrite PROTO :XPTR, :XPTR, :XPTR, :XWORD, :XPTR
        EtwWriteString PROTO :XPTR, :XWORD, :XWORD, :XPTR, :LPCWSTR
        EtwWriteTransfer PROTO :XPTR, :XPTR, :XPTR, :XPTR, :XWORD, :XPTR
        ExAcquireSpinLockExclusive PROTO :XPTR
        ExAcquireSpinLockExclusiveAtDpcLevel PROTO :XPTR
        ExAcquireSpinLockShared PROTO :XPTR
        ExAcquireSpinLockSharedAtDpcLevel PROTO :XPTR
        ExAllocateCacheAwarePushLock PROTO
        ExAllocateCacheAwareRundownProtection PROTO :XWORD, :XWORD
        ExDeleteLookasideListEx PROTO :XPTR
        ExEnterCriticalRegionAndAcquireFastMutexUnsafe PROTO :XPTR
        ExEnterCriticalRegionAndAcquireResourceExclusive PROTO :XPTR
        ExEnterCriticalRegionAndAcquireResourceShared PROTO :XPTR
        ExEnterCriticalRegionAndAcquireSharedWaitForExclusive PROTO :XPTR
        ExFlushLookasideListEx PROTO :XPTR
        ExFreeCacheAwarePushLock PROTO :XPTR
        ExfReleasePushLockExclusive PROTO :XPTR
        ExfReleasePushLockShared PROTO :XPTR
        ExfTryToWakePushLock PROTO :XPTR
        ExfUnblockPushLock PROTO :XPTR, :PVOID
        ExInitializeLookasideListEx PROTO :XPTR, :XPTR, :XPTR, :XWORD, :XWORD, :XPTR, :XWORD, :XWORD
        ExInitializePushLock PROTO :XPTR
        ExInitializeRundownProtectionCacheAware PROTO :XPTR, :XWORD, :XWORD
        ExReInitializeRundownProtectionCacheAware PROTO :XPTR
        ExReleaseCacheAwarePushLockExclusive PROTO :XPTR
        ExReleaseFastMutexUnsafeAndLeaveCriticalRegion PROTO :XPTR
        ExReleaseResourceAndLeaveCriticalRegion PROTO :XPTR
        ExReleaseRundownProtectionCacheAware PROTO :XPTR
        ExReleaseRundownProtectionCacheAwareEx PROTO :XPTR, :XWORD
        ExReleaseSpinLockExclusive PROTO :XPTR, :XWORD
        ExReleaseSpinLockExclusiveFromDpcLevel PROTO :XPTR
        ExReleaseSpinLockShared PROTO :XPTR, :XWORD
        ExReleaseSpinLockSharedFromDpcLevel PROTO :XPTR
        ExRundownCompletedCacheAware PROTO :XPTR
        ExSetLicenseTamperState PROTO :XWORD
        ExTryConvertSharedSpinLockExclusive PROTO :XPTR
        FirstEntrySList PROTO :XPTR
        FsRtlAcknowledgeEcp PROTO :PVOID
        FsRtlAddBaseMcbEntry PROTO :XPTR, :XWORD, :XWORD, :XWORD
        FsRtlAddBaseMcbEntryEx PROTO :XPTR, :XWORD, :XWORD, :XWORD
        FsRtlAllocateExtraCreateParameter PROTO :XPTR, :XWORD, :XWORD, :XPTR, :XWORD, :PVOID
        FsRtlAllocateExtraCreateParameterFromLookasideList PROTO :XPTR, :XWORD, :XWORD, :XPTR, :PVOID, :PVOID
        FsRtlAllocateExtraCreateParameterList PROTO :XWORD, :XPTR
        FsRtlAreVolumeStartupApplicationsComplete PROTO
        FsRtlCancellableWaitForMultipleObjects PROTO :XWORD, :PVOID, :XWORD, :XPTR, :XPTR, :XPTR
        FsRtlCancellableWaitForSingleObject PROTO :PVOID, :XPTR, :XPTR
        FsRtlChangeBackingFileObject PROTO :XPTR, :XPTR, :XWORD, :XWORD
        FsRtlCheckOplockEx PROTO :XPTR, :XPTR, :XWORD, :PVOID, :XPTR, :XPTR
        FsRtlCurrentOplock PROTO :XPTR
        FsRtlDeleteExtraCreateParameterLookasideList PROTO :PVOID, :XWORD
        FsRtlFindExtraCreateParameter PROTO :XPTR, :XPTR, :PVOID, :XPTR
        FsRtlFreeExtraCreateParameter PROTO :PVOID
        FsRtlFreeExtraCreateParameterList PROTO :XPTR
        FsRtlGetEcpListFromIrp PROTO :XPTR, :XPTR
        FsRtlGetNextBaseMcbEntry PROTO :XPTR, :XWORD, :XPTR, :XPTR, :XPTR
        FsRtlGetNextExtraCreateParameter PROTO :XPTR, :PVOID, :XPTR, :PVOID, :XWORD
        FsRtlIncrementCcFastMdlReadWait PROTO
        FsRtlInitExtraCreateParameterLookasideList PROTO :PVOID, :XWORD, :XWORD, :XWORD
        FsRtlInitializeExtraCreateParameter PROTO :XPTR, :XWORD, :XPTR, :XWORD, :XPTR, :PVOID
        FsRtlInitializeExtraCreateParameterList PROTO :XPTR
        FsRtlInsertExtraCreateParameter PROTO :XPTR, :PVOID
        FsRtlInsertPerFileContext PROTO :PVOID, :XPTR
        FsRtlIsEcpAcknowledged PROTO :PVOID
        FsRtlIsEcpFromUserMode PROTO :PVOID
        FsRtlLogCcFlushError PROTO :XPTR, :XPTR, :XPTR, :XWORD, :XWORD
        FsRtlLookupBaseMcbEntry PROTO :XPTR, :XWORD, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR
        FsRtlLookupLastBaseMcbEntryAndIndex PROTO :XPTR, :XPTR, :XPTR, :XPTR
        FsRtlLookupPerFileContext PROTO :PVOID, :PVOID, :PVOID
        FsRtlMupGetProviderIdFromName PROTO :XPTR, :XPTR
        FsRtlMupGetProviderInfoFromFileObject PROTO :XPTR, :XWORD, :PVOID, :XPTR
        FsRtlNotifyCleanupAll PROTO :XPTR, :XPTR
        FsRtlNotifyVolumeEventEx PROTO :XPTR, :XWORD, :XPTR
        FsRtlOplockBreakToNone PROTO :XPTR, :XPTR, :XWORD, :PVOID, :XPTR, :XPTR
        FsRtlPrepareToReuseEcp PROTO :PVOID
        FsRtlRegisterUncProviderEx PROTO :XPTR, :XPTR, :XPTR, :XWORD
        FsRtlRemoveBaseMcbEntry PROTO :XPTR, :XWORD, :XWORD
        FsRtlRemoveDotsFromPath PROTO :LPWSTR, :XWORD, :XPTR
        FsRtlRemoveExtraCreateParameter PROTO :XPTR, :XPTR, :PVOID, :XWORD
        FsRtlRemovePerFileContext PROTO :PVOID, :PVOID, :PVOID
        FsRtlSetEcpListIntoIrp PROTO :XPTR, :XPTR
        FsRtlSplitBaseMcb PROTO :XPTR, :XWORD, :XWORD
        FsRtlTeardownPerFileContexts PROTO :PVOID
        FsRtlTruncateBaseMcb PROTO :XPTR, :XWORD
        FsRtlUninitializeBaseMcb PROTO :XPTR
        FsRtlValidateReparsePointBuffer PROTO :XPTR, :XWORD
        InterlockedPushListSList PROTO :XPTR, :XPTR, :XPTR, :XWORD
        IoAllocateMiniCompletionPacket PROTO
        IoAllocateSfioStreamIdentifier PROTO :XPTR, :XWORD, :PVOID, :PVOID
        IoCheckShareAccessEx PROTO :XWORD, :XWORD, :XPTR, :XPTR, :XWORD, :XPTR
        IoClearIrpExtraCreateParameter PROTO :XPTR
        IoConnectInterruptEx PROTO :XPTR
        IoCreateFileEx PROTO :XPTR, :XWORD, :XPTR, :XPTR, :XPTR, :XWORD, :XWORD, :XWORD, :XWORD, :PVOID, :XWORD, :XWORD, :PVOID, :XWORD, :XPTR
        IoCsqInitializeEx PROTO :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR
        IoCsqInsertIrpEx PROTO :XPTR, :XPTR, :XPTR, :PVOID
        IoDisconnectInterruptEx PROTO :XPTR
        IoFreeSfioStreamIdentifier PROTO :XPTR, :PVOID
        IoGetBootDiskInformationLite PROTO :XPTR
        IoGetDevicePropertyData PROTO :XPTR, :XPTR, :XPTR, :XWORD, :XWORD, :PVOID, :XPTR, :XPTR
        IoGetIoPriorityHint PROTO :XPTR
        IoGetIrpExtraCreateParameter PROTO :XPTR, :XPTR
        IoGetPagingIoPriority PROTO :XPTR
        IoGetSfioStreamIdentifier PROTO :XPTR, :XPTR
        IoGetTransactionParameterBlock PROTO :XPTR
        IoInitializeWorkItem PROTO :XPTR, :XPTR
        IoIsFileObjectIgnoringSharing PROTO :XPTR
        IoQueueWorkItemEx PROTO :XPTR, :XPTR, :XWORD, :PVOID
        IoReplacePartitionUnit PROTO :XPTR, :XPTR, :XWORD
        IoSetDevicePropertyData PROTO :XPTR, :XPTR, :XWORD, :XWORD, :XWORD, :XWORD, :PVOID
        IoSetIoPriorityHint PROTO :XPTR, :XWORD
        IoSetIrpExtraCreateParameter PROTO :XPTR, :XPTR
        IoSetShareAccessEx PROTO :XWORD, :XWORD, :XPTR, :XPTR, :XPTR
        IoSizeofWorkItem PROTO
        IoTranslateBusAddress PROTO :XWORD, :XWORD, :XPTR, :XPTR, :XPTR
        IoUninitializeWorkItem PROTO :XPTR
        IoWithinStackLimits PROTO :XPTR, :SIZE_T
        KdRefreshDebuggerNotPresent PROTO
        KdSystemDebugControl PROTO :XWORD, :PVOID, :XWORD, :PVOID, :XWORD, :XPTR, :XWORD
        KeAcquireGuardedMutex PROTO :XPTR
        KeAcquireGuardedMutexUnsafe PROTO :XPTR
        KeAcquireInStackQueuedSpinLockForDpc PROTO :XPTR, :XPTR
        KeAcquireSpinLockForDpc PROTO :XPTR
        KeAlertThread PROTO :XPTR, :XWORD
        KeAreAllApcsDisabled PROTO
        KeDeregisterNmiCallback PROTO :PVOID
        KeDeregisterProcessorChangeCallback PROTO :PVOID
        KeEnterGuardedRegion PROTO
        KeExpandKernelStackAndCallout PROTO :XPTR, :PVOID, :SIZE_T
        KeExpandKernelStackAndCalloutEx PROTO :XPTR, :PVOID, :SIZE_T, :XWORD, :PVOID
        KeFindFirstSetLeftAffinityEx PROTO :XPTR
        KeGenericCallDpc PROTO :XPTR, :PVOID
        KeInitializeCrashDumpHeader PROTO :XWORD, :XWORD, :PVOID, :XWORD, :XPTR
        KeInitializeGuardedMutex PROTO :XPTR
        KeInitializeThreadedDpc PROTO :XPTR, :XPTR, :PVOID
        KeInvalidateAllCaches PROTO
        KeInvalidateRangeAllCaches PROTO :PVOID
        KeIpiGenericCall PROTO :XPTR, :XWORD
        KeIsWaitListEmpty PROTO :PVOID
        KeLeaveGuardedRegion PROTO
        KeQueryActiveProcessorCount PROTO :XPTR
        KeQueryDpcWatchdogInformation PROTO :XPTR
        KeQueryMaximumProcessorCount PROTO
        KeRegisterNmiCallback PROTO :XPTR, :PVOID
        KeRegisterProcessorChangeCallback PROTO :XPTR, :PVOID, :XWORD
        KeReleaseGuardedMutex PROTO :XPTR
        KeReleaseGuardedMutexUnsafe PROTO :XPTR
        KeReleaseInStackQueuedSpinLockForDpc PROTO :HANDLE
        KeReleaseInStackQueuedSpinLockFromDpcLevel PROTO :HANDLE
        KeReleaseSpinLockForDpc PROTO :XPTR, :XWORD
        KeRemoveQueueEx PROTO :XPTR, :XWORD, :XPTR
        KeRevertToUserGroupAffinityThread PROTO :XPTR
        KeSetSystemAffinityThreadEx PROTO :XWORD
        KeTestAlertThread PROTO :XWORD
        KeTestSpinLock PROTO :XPTR
        KeTryToAcquireGuardedMutex PROTO :XPTR
        KeTryToAcquireSpinLockAtDpcLevel PROTO :XWORD
        KiCheckForKernelApcDelivery PROTO
        LpcRequestWaitReplyPortEx PROTO :PVOID, :XPTR, :XPTR
        MmAllocateContiguousMemorySpecifyCacheNode PROTO :SIZE_T, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        MmAllocatePagesForMdlEx PROTO :XWORD, :XWORD, :XWORD, :SIZE_T, :XWORD, :XWORD
        MmCopyVirtualMemory PROTO :XPTR, :PVOID, :XPTR, :PVOID, :SIZE_T, :XWORD, :XPTR
        MmCreateMirror PROTO
        MmDoesFileHaveUserWritableReferences PROTO :XPTR
        MmIsDriverVerifyingByAddress PROTO :PVOID
        MmIsIoSpaceActive PROTO :XWORD, :SIZE_T
        MmRotatePhysicalView PROTO :PVOID, :XPTR, :XPTR, :XWORD, :XPTR, :PVOID
        NtCommitComplete PROTO :HANDLE, :XPTR
        NtCommitEnlistment PROTO :HANDLE, :XPTR
        NtCommitTransaction PROTO :HANDLE, :XWORD
        NtCreateEnlistment PROTO :XPTR, :XWORD, :HANDLE, :HANDLE, :XPTR, :XWORD, :XWORD, :PVOID
        NtCreateResourceManager PROTO :XPTR, :XWORD, :HANDLE, :XPTR, :XPTR, :XWORD, :XPTR
        NtCreateTransaction PROTO :XPTR, :XWORD, :XPTR, :XPTR, :HANDLE, :XWORD, :XWORD, :XWORD, :XPTR, :XPTR
        NtEnumerateTransactionObject PROTO :HANDLE, :XWORD, :XPTR, :XWORD, :XPTR
        NtFreezeTransactions PROTO :XPTR, :XPTR
        NtGetNotificationResourceManager PROTO :HANDLE, :XPTR, :XWORD, :XPTR, :XPTR, :XWORD, :XWORD
        NtOpenEnlistment PROTO :XPTR, :XWORD, :HANDLE, :XPTR, :XPTR
        NtOpenResourceManager PROTO :XPTR, :XWORD, :HANDLE, :XPTR, :XPTR
        NtOpenTransaction PROTO :XPTR, :XWORD, :XPTR, :XPTR, :HANDLE
        NtPrepareComplete PROTO :HANDLE, :XPTR
        NtPrepareEnlistment PROTO :HANDLE, :XPTR
        NtPrePrepareEnlistment PROTO :HANDLE, :XPTR
        NtQueryInformationEnlistment PROTO :HANDLE, :XWORD, :PVOID, :XWORD, :XPTR
        NtQueryInformationResourceManager PROTO :HANDLE, :XWORD, :PVOID, :XWORD, :XPTR
        NtQueryInformationTransaction PROTO :HANDLE, :XWORD, :PVOID, :XWORD, :XPTR
        NtQueryInformationTransactionManager PROTO
        NtRollbackEnlistment PROTO :HANDLE, :XPTR
        NtRollbackTransaction PROTO :HANDLE, :XWORD
        NtSetInformationEnlistment PROTO :HANDLE, :XWORD, :PVOID, :XWORD
        NtSetInformationResourceManager PROTO :HANDLE, :XWORD
        NtSetInformationTransaction PROTO :HANDLE, :XWORD, :PVOID, :XWORD
        NtThawTransactions PROTO
        NtTraceControl PROTO :XWORD, :PVOID, :XWORD, :PVOID, :XWORD, :XPTR
        ObDereferenceObjectDeferDelete PROTO :PVOID
        ObDereferenceSecurityDescriptor PROTO :XWORD, :XWORD
        ObGetFilterVersion PROTO
        ObIsKernelHandle PROTO :HANDLE
        ObRegisterCallbacks PROTO :XPTR, :PVOID
        ObUnRegisterCallbacks PROTO :PVOID
        PoGetSystemWake PROTO :XPTR
        PoRegisterPowerSettingCallback PROTO :XPTR, :XPTR, :XPTR, :PVOID, :PVOID
        PoSetDeviceBusyEx PROTO :XPTR
        PoSetSystemWake PROTO :XPTR
        PoUnregisterPowerSettingCallback PROTO :PVOID
        PsAcquireProcessExitSynchronization PROTO :XWORD
        PsGetCurrentProcessWin32Process PROTO
        PsGetCurrentThreadProcess PROTO
        PsGetCurrentThreadProcessId PROTO
        PsGetCurrentThreadTeb PROTO
        PsGetCurrentThreadWin32Thread PROTO
        PsIsCurrentThreadPrefetching PROTO
        PsIsSystemProcess PROTO :XWORD
        PsReferenceProcessFilePointer PROTO :XWORD, :XPTR
        PsResumeProcess PROTO :XWORD
        PsSetCreateProcessNotifyRoutineEx PROTO :XPTR, :XWORD
        PsSetCurrentThreadPrefetching PROTO :XWORD
        PsSuspendProcess PROTO :XWORD
        PsWrapApcWow64Thread PROTO :PVOID, :PVOID
        RtlCmDecodeMemIoResource PROTO :XPTR, :XPTR
        RtlCmEncodeMemIoResource PROTO :XPTR, :XWORD, :XWORD, :XWORD
        RtlCompareAltitudes PROTO :XPTR, :XPTR
        RtlComputeCrc32 PROTO :XWORD, :XPTR, :XWORD
        RtlCopyLuidAndAttributesArray PROTO :XWORD, :XPTR, :XPTR
        RtlCopySidAndAttributesArray PROTO :XWORD, :XPTR, :XWORD, :XPTR, :PVOID, :PVOID, :XPTR
        RtlDuplicateUnicodeString PROTO :XWORD, :XPTR, :XPTR
        RtlFormatMessage PROTO :LPWSTR, :XWORD, :XWORD, :XWORD, :XWORD, :XPTR, :LPWSTR, :XWORD, :XPTR, :XWORD
        RtlGetThreadLangIdByIndex PROTO
        RtlInitAnsiStringEx PROTO :XPTR, :XPTR
        RtlInitUnicodeStringEx PROTO :XPTR, :XPTR
        RtlIoDecodeMemIoResource PROTO :XPTR, :XPTR, :XPTR, :XPTR
        RtlIoEncodeMemIoResource PROTO :XPTR, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        RtlIsNormalizedString PROTO :XWORD, :LPCWSTR, :XWORD, :XPTR
        RtlIsNtDdiVersionAvailable PROTO :XWORD
        RtlIsServicePackVersionInstalled PROTO :XWORD
        RtlLocalTimeToSystemTime PROTO :XPTR, :XPTR
        RtlLookupFirstMatchingElementGenericTableAvl PROTO :XPTR, :PVOID, :PVOID
        RtlNumberOfSetBitsUlongPtr PROTO :XPTR
        RtlQueryElevationFlags PROTO :XPTR
        RtlRunOnceBeginInitialize PROTO :XPTR, :XWORD, :XPTR
        RtlRunOnceComplete PROTO :XPTR, :XWORD, :PVOID
        RtlRunOnceExecuteOnce PROTO :XPTR, :XPTR, :PVOID, :PVOID
        RtlRunOnceInitialize PROTO :XPTR
        RtlSystemTimeToLocalTime PROTO :XPTR, :XPTR
        RtlUnlockBootStatusData PROTO :XWORD
        RtlValidateUnicodeString PROTO :XWORD, :XPTR
        SeAuditHardLinkCreationWithTransaction PROTO :XPTR, :XPTR, :XWORD, :XPTR
        SeAuditTransactionStateChange PROTO :XPTR, :XPTR, :XWORD
        SeCaptureSubjectContextEx PROTO :XWORD, :XWORD, :XPTR
        SeComputeAutoInheritByObjectType PROTO :XPTR, :XPTR, :XPTR
        SeCreateAccessStateEx PROTO :XWORD, :XWORD, :XPTR, :XPTR, :XWORD, :XPTR
        SeDeleteObjectAuditAlarmWithTransaction PROTO :PVOID, :HANDLE, :XPTR
        SeExamineSacl PROTO :XPTR, :XPTR, :XWORD, :XWORD, :XPTR, :XPTR
        SeFilterToken PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        SeLocateProcessImageName PROTO :XWORD, :XPTR
        SeOpenObjectForDeleteAuditAlarmWithTransaction PROTO :XPTR, :PVOID, :XPTR, :XPTR, :XPTR, :XWORD, :XWORD, :XWORD, :XPTR, :XPTR
        SeReportSecurityEventWithSubCategory PROTO :XWORD, :XPTR, :XPTR, :XPTR, :XWORD
        SeSetAuditParameter PROTO :XPTR, :XWORD, :XWORD, :XPTR
        TmCommitComplete PROTO :XPTR, :XPTR
        TmCommitEnlistment PROTO :XPTR, :XPTR
        TmCommitTransaction PROTO :XPTR, :XWORD
        TmCreateEnlistment PROTO :XPTR, :XWORD, :XWORD, :XPTR, :XPTR, :XPTR, :XWORD, :XWORD, :PVOID
        TmDereferenceEnlistmentKey PROTO :XPTR, :XPTR
        TmEnableCallbacks PROTO :XPTR, :XPTR, :PVOID
        TmGetTransactionId PROTO :XPTR, :XPTR
        TmIsTransactionActive PROTO :XPTR
        TmPrepareComplete PROTO :XPTR, :XPTR
        TmPrepareEnlistment PROTO :XPTR, :XPTR
        TmPrePrepareComplete PROTO :XPTR, :XPTR
        TmPrePrepareEnlistment PROTO :XPTR, :XPTR
        TmReadOnlyEnlistment PROTO :XPTR, :XPTR
        TmRecoverEnlistment PROTO :XPTR, :PVOID
        TmRecoverResourceManager PROTO :XPTR
        TmRecoverTransactionManager PROTO :XPTR, :XPTR
        TmReferenceEnlistmentKey PROTO :XPTR, :PVOID
        TmRequestOutcomeEnlistment PROTO :XPTR, :XPTR
        TmRollbackComplete PROTO :XPTR, :XPTR
        TmRollbackEnlistment PROTO :XPTR, :XPTR
        TmRollbackTransaction PROTO :XPTR, :XWORD
        WheaAddErrorSource PROTO :XPTR, :XPTR
        ZwAddDriverEntry PROTO :XPTR, :XPTR
        ZwAllocateLocallyUniqueId PROTO :XPTR
        ZwAlpcAcceptConnectPort PROTO :XPTR, :HANDLE, :XWORD, :XPTR, :XPTR, :PVOID, :XPTR, :XPTR, :XWORD
        ZwAlpcCancelMessage PROTO :HANDLE, :XWORD, :XPTR
        ZwAlpcConnectPort PROTO :XPTR, :XPTR, :XPTR, :XPTR, :XWORD, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR
        ZwAlpcCreatePort PROTO :XPTR, :XPTR, :XPTR
        ZwAlpcCreatePortSection PROTO :HANDLE, :XWORD, :HANDLE, :SIZE_T, :XPTR, :XPTR
        ZwAlpcCreateResourceReserve PROTO :HANDLE, :XWORD, :SIZE_T, :XPTR
        ZwAlpcCreateSectionView PROTO :HANDLE, :XWORD, :XPTR
        ZwAlpcCreateSecurityContext PROTO :HANDLE, :XWORD, :XPTR
        ZwAlpcDeletePortSection PROTO :HANDLE, :XWORD, :XPTR
        ZwAlpcDeleteResourceReserve PROTO :HANDLE, :XWORD, :XWORD
        ZwAlpcDeleteSectionView PROTO :HANDLE, :XWORD, :PVOID
        ZwAlpcDeleteSecurityContext PROTO :HANDLE, :XWORD, :XWORD
        ZwAlpcDisconnectPort PROTO :HANDLE, :XWORD
        ZwAlpcQueryInformation PROTO :HANDLE, :XWORD, :PVOID, :XWORD, :XPTR
        ZwAlpcSendWaitReceivePort PROTO :HANDLE, :XWORD, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR
        ZwAlpcSetInformation PROTO :HANDLE, :XWORD, :PVOID, :XWORD
        ZwCommitEnlistment PROTO :HANDLE, :XPTR
        ZwCommitTransaction PROTO :HANDLE, :XWORD
        ZwCreateEnlistment PROTO :XPTR, :XWORD, :HANDLE, :HANDLE, :XPTR, :XWORD, :XWORD, :PVOID
        ZwCreateIoCompletion PROTO :XPTR, :XWORD, :XPTR, :XWORD
        ZwCreateKeyTransacted PROTO :XPTR, :XWORD, :XPTR, :XWORD, :XPTR, :XWORD, :HANDLE, :XPTR
        ZwCreateResourceManager PROTO :XPTR, :XWORD, :HANDLE, :XPTR, :XPTR, :XWORD, :XPTR
        ZwCreateTransaction PROTO :XPTR, :XWORD, :XPTR, :XPTR, :HANDLE, :XWORD, :XWORD, :XWORD, :XPTR, :XPTR
        ZwCreateTransactionManager PROTO :XPTR, :XWORD, :XPTR, :XPTR, :XWORD, :XWORD
        ZwEnumerateDriverEntries PROTO :PVOID, :XPTR
        ZwEnumerateTransactionObject PROTO :HANDLE, :XWORD, :XPTR, :XWORD, :XPTR
        ZwFlushBuffersFile PROTO :HANDLE, :XPTR
        ZwGetNotificationResourceManager PROTO :HANDLE, :XPTR, :XWORD, :XPTR, :XPTR, :XWORD, :XPTR
        ZwImpersonateAnonymousToken PROTO :HANDLE
        ZwLoadKeyEx PROTO :XPTR, :XPTR, :XWORD, :HANDLE
        ZwLockProductActivationKeys PROTO :XWORD, :XWORD
        ZwModifyBootEntry PROTO :XPTR
        ZwModifyDriverEntry PROTO :XPTR
        ZwOpenEnlistment PROTO :XPTR, :XWORD, :HANDLE, :XPTR, :XPTR
        ZwOpenKeyTransacted PROTO :XPTR, :XWORD, :XPTR, :HANDLE
        ZwOpenResourceManager PROTO :XPTR, :XWORD, :HANDLE, :XPTR, :XPTR
        ZwOpenTransaction PROTO :XPTR, :XWORD, :XPTR, :XPTR, :HANDLE
        ZwOpenTransactionManager PROTO :XPTR, :XWORD, :XPTR, :XPTR, :XPTR, :XWORD
        ZwPrepareComplete PROTO :HANDLE, :XPTR
        ZwPrepareEnlistment PROTO :HANDLE, :XPTR
        ZwPrePrepareEnlistment PROTO :HANDLE, :XPTR
        ZwQueryDriverEntryOrder PROTO :XPTR, :XPTR
        ZwQueryInformationEnlistment PROTO :HANDLE, :XWORD, :PVOID, :XWORD, :XPTR
        ZwQueryInformationResourceManager PROTO :HANDLE, :XWORD, :PVOID, :XWORD, :XPTR
        ZwQueryInformationTransaction PROTO :HANDLE, :XWORD, :PVOID, :XWORD, :XPTR
        ZwQueryInformationTransactionManager PROTO :HANDLE, :XWORD, :PVOID, :XWORD, :XPTR
        ZwQueryVirtualMemory PROTO :HANDLE, :PVOID, :XWORD, :PVOID, :SIZE_T, :XPTR
        ZwRecoverEnlistment PROTO :HANDLE, :PVOID
        ZwRecoverResourceManager PROTO :HANDLE
        ZwRecoverTransactionManager PROTO :HANDLE
        ZwRemoveIoCompletion PROTO :HANDLE, :PVOID, :PVOID, :XPTR, :XPTR
        ZwRemoveIoCompletionEx PROTO :HANDLE, :XPTR, :XWORD, :XPTR, :XPTR, :XWORD
        ZwRequestPort PROTO :HANDLE, :XPTR
        ZwRollbackEnlistment PROTO :HANDLE, :XPTR
        ZwRollbackTransaction PROTO :HANDLE, :XWORD
        ZwSecureConnectPort PROTO :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR, :PVOID, :XPTR
        ZwSetDriverEntryOrder PROTO :XPTR, :XWORD
        ZwSetInformationEnlistment PROTO :HANDLE, :XWORD, :PVOID, :XWORD
        ZwSetInformationTransaction PROTO :HANDLE, :XWORD, :PVOID, :XWORD
        ZwUnloadKeyEx PROTO :XPTR, :HANDLE
        _strtoui64 PROTO :XPTR, :XPTR, :XWORD
        _swprintf PROTO :XPTR, :SIZE_T, :XPTR, :VARARG
        _vswprintf PROTO :XPTR, :SIZE_T, :XPTR, :VARARG
    ENDIF

    IF (NTDDI_VERSION GE NTDDI_WIN7)
        CcCoherencyFlushAndPurgeCache PROTO :XPTR, :XPTR, :XWORD, :XPTR, :XWORD
        CcCopyWriteWontFlush PROTO :XPTR, :XPTR, :XWORD
        EtwWriteEx PROTO :XPTR, :XPTR, :XWORD, :XWORD, :XPTR, :XPTR, :XWORD, :XPTR
        ExAcquireFastMutex PROTO :XPTR
        ExpInterlockedFlushSList PROTO :XPTR
        ExpInterlockedPopEntrySList PROTO :XPTR
        ExpInterlockedPushEntrySList PROTO :XPTR, :XPTR
        ExQueryDepthSList PROTO :XPTR
        ExReleaseFastMutex PROTO :XPTR
        ExSetResourceOwnerPointerEx PROTO :XPTR, :PVOID, :XWORD
        ExTryToAcquireFastMutex PROTO :XPTR
        FsRtlCurrentOplockH PROTO :XPTR
        FsRtlAreThereCurrentOrInProgressFileLocks PROTO :XPTR
        FsRtlGetVirtualDiskNestingLevel PROTO :XPTR, :XPTR, :XPTR
        FsRtlOplockBreakH PROTO :XPTR, :XPTR, :XWORD, :PVOID, :XPTR, :XPTR
        FsRtlOplockBreakToNoneEx PROTO :XPTR, :XPTR, :XWORD, :PVOID, :XPTR, :XPTR
        FsRtlOplockFsctrlEx PROTO :XPTR, :XPTR, :XWORD, :XWORD
        FsRtlOplockIsSharedRequest PROTO :XPTR
        FsRtlOplockKeysEqual PROTO :XPTR, :XPTR
        FsRtlQueryMaximumVirtualDiskNestingLevel PROTO
        IoGetAffinityInterrupt PROTO :XPTR, :XPTR
        IoGetContainerInformation PROTO :XWORD, :PVOID, :PVOID, :XWORD
        IoGetDeviceNumaNode PROTO :XPTR, :XPTR
        IoGetOplockKeyContext PROTO :XPTR
        IoIs32bitProcess PROTO :XPTR
        IoRegisterContainerNotification PROTO :XWORD, :XPTR, :PVOID, :XWORD, :PVOID
        IoRegisterFsRegistrationChangeMountAware PROTO :XPTR, :XPTR, :XWORD
        IoReplaceFileObjectName PROTO :XPTR, :LPWSTR, :XWORD
        IoReportRootDevice PROTO :XPTR
        IoSetFileObjectIgnoreSharing PROTO :XPTR
        IoUnregisterContainerNotification PROTO :PVOID
        IoUnregisterPlugPlayNotificationEx PROTO :PVOID
        IoUnregisterPriorityCallback PROTO :XPTR
        IoWMIDeviceObjectToProviderId PROTO :XPTR
        IFDEF APP_WIN64
            KeAcquireInStackQueuedSpinLock PROTO :XPTR, :XPTR
            KeAcquireInStackQueuedSpinLockRaiseToSynch PROTO :XPTR, :XPTR
            KeAcquireQueuedSpinLock PROTO :XPTR, :XPTR
            KeAcquireQueuedSpinLockRaiseToSynch PROTO :XWORD
            KeAcquireSpinLockRaiseToDpc PROTO :XPTR
            KeAcquireSpinLockRaiseToSynch PROTO :XPTR
            KeGetCurrentIrql PROTO
            KeLowerIrql PROTO :XWORD
            KeQueryPrcbAddress PROTO :XWORD
            KeRaiseIrqlToDpcLevel PROTO
            KeReleaseInStackQueuedSpinLock PROTO :HANDLE
            KeReleaseQueuedSpinLock PROTO :HANDLE, :XPTR
            KeReleaseSpinLock PROTO :XPTR, :XWORD
            KeTryToAcquireQueuedSpinLock PROTO :XWORD, :XPTR
            KeTryToAcquireQueuedSpinLockRaiseToSynch PROTO :XWORD, :XPTR
            longjmp PROTO :XPTR, :XWORD
            memcmp PROTO :XPTR, :XPTR, :SIZE_T
            PsGetProcessWow64Process PROTO :XWORD
            RtlLookupFunctionEntry PROTO :XWORD, :XPTR, :XPTR
            RtlPcToFileHeader PROTO :PVOID, :PVOID
            RtlRestoreContext PROTO :XPTR, :XPTR
            RtlVirtualUnwind PROTO :XWORD, :XPTR, :XPTR, :XPTR, :XPTR, :XWORD, :XPTR, :XPTR
            _setjmp PROTO :XPTR
            _setjmpex PROTO :XPTR
        ENDIF
        KeAndAffinityEx PROTO :XPTR, :XPTR, :XPTR
        KeComplementAffinityEx PROTO :XPTR, :XPTR
        KeGetCurrentNodeNumber PROTO
        KeGetCurrentProcessorNumberEx PROTO :XPTR
        KeGetProcessorIndexFromNumber PROTO :XPTR
        KeGetProcessorNumberFromIndex PROTO :XWORD, :XPTR
        KeInitializeEnumerationContext PROTO
        KeInterlockedSetProcessorAffinityEx PROTO :XPTR, :XWORD
        KeIsEmptyAffinityEx PROTO :XPTR
        KeIsEqualAffinityEx PROTO :XPTR, :XPTR
        KeIsSubsetAffinityEx PROTO :XPTR, :XPTR
        KeQueryActiveGroupCount PROTO
        KeQueryActiveProcessorCountEx PROTO :XWORD
        KeQueryGroupAffinity PROTO :XWORD
        KeQueryHardwareCounterConfiguration PROTO :XPTR, :XWORD, :XPTR
        KeQueryHighestNodeNumber PROTO
        KeQueryLogicalProcessorRelationship PROTO :XPTR, :XWORD, :XPTR, :XPTR
        KeQueryMaximumGroupCount PROTO
        KeQueryMaximumProcessorCountEx PROTO :XWORD
        KeQueryNodeActiveAffinity PROTO :XWORD, :XPTR, :XPTR
        KeQueryNodeMaximumProcessorCount PROTO :XWORD
        KeQueryUnbiasedInterruptTime PROTO
        KeSaveExtendedProcessorState PROTO :XWORD, :XPTR
        KeSetCoalescableTimer PROTO :XPTR, :XWORD, :XWORD, :XWORD, :XPTR
        KeSetHardwareCounterConfiguration PROTO :XPTR, :XWORD
        KeSetSystemGroupAffinityThread PROTO :XPTR, :XPTR
        KeSetTargetProcessorDpcEx PROTO :XPTR, :XPTR
        memcpy_s PROTO :XPTR, :SIZE_T, :XPTR, :SIZE_T
        memmove_s PROTO :XPTR, :SIZE_T, :XPTR, :SIZE_T
        NtCreateTransactionManager PROTO :XPTR, :XWORD, :XPTR, :XPTR, :XWORD, :XWORD
        NtOpenTransactionManager PROTO :XPTR, :XWORD, :XPTR, :XPTR, :XPTR, :XWORD
        NtPrePrepareComplete PROTO :HANDLE, :XPTR
        NtPropagationComplete PROTO :HANDLE, :XWORD, :XWORD, :PVOID
        NtPropagationFailed PROTO :HANDLE, :XWORD, :XWORD
        NtQuerySecurityAttributesToken PROTO :HANDLE, :XPTR, :XWORD, :PVOID, :XWORD, :XPTR
        NtQuerySystemInformationEx PROTO :XWORD, :XPTR, :XWORD, :PVOID, :XWORD, :XPTR
        NtReadOnlyEnlistment PROTO :HANDLE, :XPTR
        NtRecoverEnlistment PROTO :HANDLE, :PVOID
        NtRecoverResourceManager PROTO :HANDLE
        NtRecoverTransactionManager PROTO :HANDLE
        NtRollbackComplete PROTO :HANDLE, :XPTR
        NtSetInformationToken PROTO :HANDLE, :XWORD, :PVOID, :XWORD
        ObDereferenceObjectDeferDeleteWithTag PROTO :PVOID, :XWORD
        ObfReferenceObjectWithTag PROTO :PVOID, :XWORD
        ObOpenObjectByPointerWithTag PROTO :PVOID, :XWORD, :XPTR, :XWORD, :XPTR, :XWORD, :XWORD, :XPTR
        ObQueryNameInfo PROTO :XPTR
        ObReferenceObjectByHandleWithTag PROTO :HANDLE, :XWORD, :XPTR, :XWORD, :XWORD, :PVOID, :XPTR
        ObReferenceObjectByPointerWithTag PROTO :PVOID, :XWORD, :XPTR, :XWORD, :XWORD
        PcwAddInstance PROTO :XPTR, :XPTR, :XWORD, :XWORD, :XPTR
        PcwCloseInstance PROTO :XPTR
        PcwCreateInstance PROTO :XPTR, :XPTR, :XPTR, :XWORD, :XPTR
        PcwRegister PROTO :XPTR, :XPTR
        PcwUnregister PROTO :XPTR
        PoClearPowerRequest PROTO :PVOID, :XWORD
        PoCreatePowerRequest PROTO :PVOID, :XPTR, :XPTR
        PoDeletePowerRequest PROTO :PVOID
        PoEndDeviceBusy PROTO :XWORD
        PoQueryWatchdogTime PROTO :XPTR, :XPTR
        PoSetPowerRequest PROTO :PVOID, :XWORD
        PoStartDeviceBusy PROTO :XPTR
        RtlDowncaseUnicodeChar PROTO :XWORD
        RtlCompareUnicodeStrings PROTO:XPTR, :XPTR, :XWORD
        RtlEthernetAddressToStringA PROTO :XPTR, :XPTR
        RtlEthernetAddressToStringW PROTO :XPTR, :XPTR
        RtlEthernetStringToAddressA PROTO :XPTR, :XPTR, :XPTR
        RtlEthernetStringToAddressW PROTO :XPTR, :XPTR, :XPTR
        RtlGetEnabledExtendedFeatures PROTO :XWORD
        RtlGetNextEntryHashTable PROTO :XPTR, :XPTR
        RtlInitEnumerationHashTable PROTO :XPTR, :XPTR
        RtlInitWeakEnumerationHashTable PROTO :XPTR, :XPTR
        RtlInsertEntryHashTable PROTO :XPTR, :XPTR, :XWORD, :XPTR
        RtlLookupEntryHashTable PROTO :XPTR, :XPTR, :XPTR
        RtlUnicodeToUTF8N PROTO :XPTR, :XWORD, :XPTR, :LPCWSTR, :XWORD
        RtlUTF8ToUnicodeN PROTO :LPWSTR, :XWORD, :XPTR, :XPTR, :XWORD
        SeAccessCheckEx PROTO :XPTR, :XWORD, :XWORD
        SeAuditingAnyFileEventsWithContext PROTO:XPTR, :XPTR, :XPTR
        SeAuditingFileEventsWithContext PROTO :XWORD, :XWORD, :XWORD
        vsprintf_s PROTO :XPTR, :SIZE_T, :XPTR, :VARARG
        vswprintf_s PROTO :XPTR, :SIZE_T, :XPTR, :VARARG
        wcscat_s PROTO :XPTR, :SIZE_T, :XPTR
        wcscpy_s PROTO :XPTR, :SIZE_T, :XPTR
        wcsncat_s PROTO :XPTR, :SIZE_T, :XPTR, :SIZE_T
        wcsncpy_s PROTO :XPTR, :SIZE_T, :XPTR, :SIZE_T
        wcsnlen PROTO :XPTR, :SIZE_T
        wcstoul PROTO :XPTR, :XPTR, :XWORD
        ZwCommitComplete PROTO :HANDLE, :XPTR
        ZwLockFile PROTO :HANDLE, :HANDLE, :XPTR, :PVOID, :XPTR, :XPTR, :XPTR, :XWORD, :XWORD, :XWORD
        ZwOpenKeyEx PROTO :XPTR, :XWORD, :XPTR, :XWORD
        ZwOpenKeyTransactedEx PROTO :XPTR, :XWORD, :XPTR, :XWORD, :HANDLE
        ZwOpenSession PROTO :XPTR, :XWORD, :XPTR
        ZwPrePrepareComplete PROTO :HANDLE, :XPTR
        ZwPropagationComplete PROTO :HANDLE, :XWORD, :XWORD, :PVOID
        ZwPropagationFailed PROTO :HANDLE, :XWORD, :XWORD
        ZwQueryQuotaInformationFile PROTO :HANDLE, :XPTR, :PVOID, :XWORD, :XWORD, :PVOID, :XWORD, :XPTR, :XWORD
        ZwQuerySecurityAttributesToken PROTO :HANDLE, :XPTR, :XWORD, :PVOID, :XWORD, :XPTR
        ZwReadOnlyEnlistment PROTO :HANDLE, :XPTR
        ZwRenameKey PROTO :HANDLE, :XPTR
        ZwRollbackComplete PROTO :HANDLE, :XPTR
        ZwSetInformationResourceManager PROTO :HANDLE, :XWORD, :PVOID, :XWORD
        ZwSetInformationToken PROTO :HANDLE, :XWORD, :PVOID, :XWORD
        ZwSetQuotaInformationFile PROTO :HANDLE, :XWORD, :PVOID, :XWORD
        ZwSetTimerEx PROTO :HANDLE, :XWORD, :PVOID, :XWORD
        ZwTraceEvent PROTO :HANDLE, :XWORD, :XWORD, :PVOID
        ZwUnlockFile PROTO :HANDLE, :XPTR, :XPTR, :XPTR, :XWORD
        _i64toa_s PROTO :INT64, :XPTR, :SIZE_T, :XWORD
        _i64tow_s PROTO :INT64, :XPTR, :SIZE_T, :XWORD
        _itoa_s PROTO :XWORD, :XPTR, :SIZE_T, :XWORD
        _itow_s PROTO :XWORD, :XPTR, :SIZE_T, :XWORD
        _ltoa_s PROTO :XWORD, :XPTR, :SIZE_T, :XWORD
        _ltow_s PROTO :XWORD, :XPTR, :SIZE_T, :XWORD
        _makepath_s PROTO :XPTR, :SIZE_T, :XPTR, :XPTR, :XPTR, :XPTR
        _snprintf_s PROTO :XPTR, :SIZE_T, :SIZE_T, :XPTR, :VARARG
        _splitpath_s PROTO :XPTR, :XPTR, :SIZE_T, :XPTR, :SIZE_T, :XPTR, :SIZE_T, :XPTR, :SIZE_T
        _strnset_s PROTO :XPTR, :SIZE_T, :XWORD, :SIZE_T
        _strset_s PROTO :XPTR, :SIZE_T, :XWORD
        _ui64toa_s PROTO :INT64, :XPTR, :SIZE_T, :XWORD
        _ui64tow_s PROTO :INT64, :XPTR, :SIZE_T, :XWORD
        _ultoa_s PROTO :XWORD, :XPTR, :SIZE_T, :XWORD
        _ultow_s PROTO :XWORD, :XPTR, :SIZE_T, :XWORD
        _vsnprintf_s PROTO :XPTR, :SIZE_T, :SIZE_T, :XPTR, :VARARG
        _vsnwprintf_s PROTO :XPTR, :SIZE_T, :SIZE_T, :XPTR, :VARARG
        _wcsnset_s PROTO :XPTR, :SIZE_T, :XWORD, :SIZE_T
        _wcsset_s PROTO :XPTR, :SIZE_T, :XWORD
        _wmakepath_s PROTO :XPTR, :SIZE_T, :XPTR, :XPTR, :XPTR, :XPTR
        _wsplitpath_s PROTO :XPTR, :XPTR, :SIZE_T, :XPTR, :SIZE_T, :XPTR, :SIZE_T, :XPTR, :SIZE_T
        _wtoi PROTO :XPTR
        _wtol PROTO :XPTR

        IFDEF APP_UNICODE
            RtlEthernetAddressToString EQU <RtlEthernetAddressToStringW>
            RtlEthernetStringToAddress EQU <RtlEthernetStringToAddressW>
        ELSE
            RtlEthernetAddressToString EQU <RtlEthernetAddressToStringA>
            RtlEthernetStringToAddress EQU <RtlEthernetStringToAddressA>
        ENDIF
    ENDIF

    IF (NTDDI_VERSION GE NTDDI_WIN8)
        bsearch_s PROTO :XPTR, :XPTR, :XPTR, :XPTR, :XPTR
        CcCopyReadEx PROTO :XPTR, :XPTR, :XWORD, :XWORD, :XPTR, :XPTR, :XWORD
        CcCopyWriteEx PROTO :XPTR, :XPTR, :XWORD, :XWORD, :XPTR, :XWORD
        CcIsThereDirtyLoggedPages PROTO :XPTR, :XPTR
        CcScheduleReadAheadEx PROTO :XPTR, :XPTR, :XWORD, :XWORD
        CcSetAdditionalCacheAttributesEx PROTO :XPTR, :XWORD
        CcSetLoggedDataThreshold PROTO :XPTR, :XWORD
        CcSetLogHandleForFileEx PROTO :XPTR, :XPTR, :XPTR, :XPTR
        CcSetReadAheadGranularityEx PROTO :XPTR, :XWORD, :XWORD
        CcUnmapFileOffsetFromSystemCache PROTO :XPTR, :XPTR, :XWORD, :XWORD
        CmCallbackGetKeyObjectIDEx PROTO :XPTR, :PVOID, :XPTR, :XPTR, :XWORD
        CmCallbackReleaseKeyObjectIDEx PROTO :XPTR
        ExBlockPushLock PROTO :XPTR, :PVOID
        ExGetFirmwareEnvironmentVariable PROTO :XPTR, :XPTR, :XPTR, :XPTR, :XPTR
        ExQueryTimerResolution PROTO :XPTR, :XPTR, :XPTR
        ExSetFirmwareEnvironmentVariable PROTO :XPTR, :XPTR, :PVOID, :XWORD, :XWORD
        ExTimedWaitForUnblockPushLock PROTO :XPTR, :PVOID, :XPTR
        ExWaitForUnblockPushLock PROTO :XPTR, :PVOID
        FsRtlAreThereWaitingFileLocks PROTO :XPTR
        FsRtlCheckLockForOplockRequest PROTO :XPTR, :XPTR
        FsRtlGetSectorSizeInformation PROTO :XPTR, :XPTR
        FsRtlGetSupportedFeatures PROTO :XPTR, :XPTR
        FsRtlIssueDeviceIoControl PROTO :XPTR, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XPTR
        FsRtlIsSystemPagingFile PROTO :XPTR
        FsRtlMdlReadEx PROTO :XPTR, :XPTR, :XWORD, :XWORD, :XPTR, :XPTR
        FsRtlPrepareMdlWriteEx PROTO :XPTR, :XPTR, :XWORD, :XWORD, :XPTR, :XPTR
        FsRtlQueryCachedVdl PROTO :XPTR, :XPTR
        IoClearActivityIdThread PROTO :XPTR
        IoCreateStreamFileObjectEx2 PROTO :XPTR, :XPTR, :XPTR, :XPTR, :XPTR
        IoCreateSystemThread PROTO :PVOID, :XPTR, :XWORD
        IoDecrementKeepAliveCount PROTO :HANDLE, :XWORD
        IoGetActivityIdIrp PROTO :XPTR, :XPTR
        IoGetActivityIdThread PROTO
        IoGetDeviceInterfacePropertyData PROTO :XPTR, :XPTR, :XPTR, :XWORD, :XWORD, :PVOID, :XPTR, :XPTR
        IoGetInitiatorProcess PROTO :XPTR
        IoGetOplockKeyContextEx PROTO :XPTR
        IoIncrementKeepAliveCount PROTO :XPTR, :XWORD
        IoIsInitiator32bitProcess PROTO :XPTR
        IoIsValidIrpStatus PROTO :XWORD
        IoPropagateActivityIdToThread PROTO :XPTR, :XPTR, :XPTR
        IoRegisterBootDriverCallback PROTO :XPTR, :PVOID
        IoReportInterruptActive PROTO :XPTR
        IoReportInterruptInactive PROTO :XPTR
        IoSetActivityIdIrp PROTO :XPTR, :XPTR
        IoSetActivityIdThread PROTO :XPTR
        IoSetDeviceInterfacePropertyData PROTO :XPTR, :XPTR, :XWORD, :XWORD, :XWORD, :XWORD, :PVOID
        IoSetMasterIrpStatus PROTO :XPTR, :XWORD
        IoTransferActivityId PROTO :XPTR, :XPTR
        IoTryQueueWorkItem PROTO :XPTR, :XPTR, :XWORD, :PVOID
        IoUnregisterBootDriverCallback PROTO :PVOID
        IoVolumeDeviceToGuid PROTO :PVOID, :XPTR
        KdLogDbgPrint PROTO :XPTR
        KeQueryInterruptTimePrecise PROTO :XPTR
        KeQuerySystemTimePrecise PROTO :XPTR
        KeQueryTotalCycleTimeThread PROTO :XPTR, :XPTR
        MmAllocateContiguousNodeMemory PROTO :SIZE_T, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        MmAllocateMdlForIoSpace PROTO :XPTR, :XWORD, :XPTR
        MmAllocateNodePagesForMdlEx PROTO :XWORD, :XWORD, :XWORD, :SIZE_T, :XWORD, :XWORD, :XWORD
        MmGetMaximumFileSectionSize PROTO
        MmIsDriverSuspectForVerifier PROTO :XPTR
        ObDuplicateObject PROTO :XWORD, :HANDLE, :XWORD, :XPTR, :XWORD, :XWORD, :XWORD, :XWORD
        ObReferenceObjectSafe PROTO :PVOID
        ObWaitForSingleObject PROTO :HANDLE, :XWORD, :XPTR
        PoFxActivateComponent PROTO :HANDLE, :XWORD, :XWORD
        PoFxCompleteDevicePowerNotRequired PROTO :HANDLE
        PoFxCompleteIdleCondition PROTO :HANDLE, :XWORD
        PoFxCompleteIdleState PROTO :HANDLE, :XWORD
        PoFxIdleComponent PROTO :HANDLE, :XWORD, :XWORD
        PoFxNotifySurprisePowerOn PROTO :XPTR
        PoFxPowerControl PROTO :HANDLE, :XPTR, :PVOID, :SIZE_T, :PVOID, :SIZE_T, :XPTR
        PoFxRegisterDevice PROTO :XPTR, :XPTR, :XPTR
        PoFxReportDevicePoweredOn PROTO :HANDLE
        PoFxSetComponentLatency PROTO :HANDLE, :XWORD, :XWORD
        PoFxSetComponentResidency PROTO :HANDLE, :XWORD, :XWORD
        PoFxSetComponentWake PROTO :HANDLE, :XWORD, :XWORD
        PoFxSetDeviceIdleTimeout PROTO :HANDLE, :XWORD
        PoFxStartDevicePowerManagement PROTO :HANDLE
        PoFxUnregisterDevice PROTO :HANDLE
        PsCreateSystemThreadEx PROTO :XPTR, :XWORD, :XWORD, :XWORD, :XPTR, :PVOID, :PVOID, :XWORD, :XWORD, :XWORD
        PsGetThreadExitStatus PROTO :XWORD
        PsIsDiskCountersEnabled PROTO
        PsQueryTotalCycleTimeProcess PROTO :XPTR, :XPTR
        PsUpdateDiskCounters PROTO :XPTR, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
        RtlCheckPortableOperatingSystem PROTO
        RtlCreateUserThread PROTO :HANDLE, :XPTR, :XWORD, :XWORD, :XPTR, :XPTR, :PVOID, :PVOID, :XPTR, :XPTR
        RtlCultureNameToLCID PROTO :XPTR, :XPTR
        RtlDecompressBufferEx PROTO :XWORD, :XPTR, :XWORD, :XPTR, :XWORD, :XPTR, :PVOID
        RtlDeleteElementGenericTableAvlEx PROTO :XPTR, :PVOID
        RtlOpenCurrentUser PROTO :XWORD, :XPTR
        RtlQueryInformationAcl PROTO :XPTR, :PVOID, :XWORD, :XWORD
        RtlRbInsertNodeEx PROTO :XPTR, :XPTR, :XWORD, :XPTR
        RtlRbRemoveNode PROTO :XPTR, :XPTR
        RtlSetControlSecurityDescriptor PROTO :XPTR, :XWORD, :XWORD
        TmInitializeTransactionManager PROTO :XPTR, :XPTR, :XPTR, :XWORD
        TmRenameTransactionManager PROTO :XPTR, :XPTR
        TmSinglePhaseReject PROTO :XPTR, :XPTR
        WheaRegisterInUsePageOfflineNotification PROTO :XPTR, :PVOID
        WheaUnregisterInUsePageOfflineNotification PROTO :XPTR
        ZwFlushBuffersFileEx PROTO :HANDLE, :XWORD, :XPTR
        ZwQuerySystemEnvironmentValueEx PROTO :XPTR, :XPTR, :PVOID, :XPTR, :XPTR
        ZwSetInformationKey PROTO :HANDLE, :XWORD, :PVOID, :XWORD
        ZwSetSystemEnvironmentValueEx PROTO :XPTR, :XPTR, :PVOID, :XWORD, :XWORD
        ZwUnlockVirtualMemory PROTO :HANDLE, :PVOID, :XPTR, :XWORD
    ENDIF
ENDIF

IF (NTDDI_VERSION GE NTDDI_WIN81)
    ExAllocateTimer PROTO :XPTR, :XPTR, :XWORD
    ExCancelTimer PROTO :XPTR, :XPTR
    ExDeleteTimer PROTO :XPTR, :XWORD, :XWORD, :XPTR
    ExSetTimer PROTO :XPTR, :XWORD, :XWORD, :XPTR
    FsRtlUpperOplockFsctrl PROTO :XPTR, :XPTR, :XWORD, :XWORD, :XWORD
    IoQueryFullDriverPath PROTO :XPTR, :XPTR
    MmCopyMemory PROTO :PVOID, :XPTR, :SIZE_T, :XWORD, :XPTR
    MmMdlPagesAreZero PROTO :XPTR
    PoFxPowerOnCrashdumpDevice PROTO :XWORD, :PVOID
    PoFxRegisterCrashdumpDevice PROTO :XWORD
    SeAdjustAccessStateForTrustLabel PROTO :XPTR, :XPTR, :XPTR
    SeShouldCheckForAccessRightsFromParent PROTO :XPTR, :XPTR, :XPTR
    ZwAssociateWaitCompletionPacket PROTO :HANDLE, :HANDLE, :HANDLE, :PVOID, :PVOID, :XWORD, :ULONG_PTR, :XPTR
    ZwCancelIoFileEx PROTO :HANDLE, :XPTR, :XPTR
    ZwCreateWaitCompletionPacket PROTO :XPTR, :XWORD, :XPTR
    ZwLockVirtualMemory PROTO :HANDLE, :XPTR, :XPTR, :XWORD
    ZwProtectVirtualMemory PROTO :HANDLE, :XPTR, :XPTR, :XWORD, :XPTR
    ZwQuerySystemInformationEx PROTO :XWORD, :XPTR, :XWORD, :XPTR, :XWORD, :XPTR
ENDIF

IF (NTDDI_VERSION GE NTDDI_WIN10)
    _finite PROTO :QWORD
    _wcslwr_s PROTO :XPTR, :SIZE_T
    CcAsyncCopyRead PROTO :XPTR, :XPTR, XWORD, XWORD, :XPTR, :XPTR, :XPTR, :XPTR
    ExIsManufacturingModeEnabled PROTO
    IoClearFsTrackOffsetState PROTO :XPTR
    IoGetSiloParameters PROTO :XWORD
    IoInitializeIrpEx PROTO :XPTR, :XPTR, :XWORD, :XWORD
    IoIrpHasFsTrackOffsetExtensionType PROTO :XPTR
    IoRequestDeviceRemovalForReset PROTO :XPTR, :XWORD
    IoSetFsTrackOffsetState PROTO :XPTR, :XPTR, :LONGLONG
    IoSetFsZeroingOffset PROTO :XPTR, :XWORD
    IoSetFsZeroingOffsetRequired PROTO :XPTR
    IoSizeOfIrpEx PROTO :XPTR, :XWORD
    IoVolumeDeviceNameToGuid PROTO :XPTR, :XPTR
    KeConvertAuxiliaryCounterToPerformanceCounter PROTO :ULONG64, :XPTR, :XPTR
    KeConvertPerformanceCounterToAuxiliaryCounter PROTO :ULONG64, :XPTR, :XPTR
    KeDeregisterBoundCallback PROTO :PVOID
    KeFlushIoBuffers PROTO :XPTR, :XWORD, :XWORD
    KeQueryAuxiliaryCounterFrequency PROTO :XPTR
    KeRegisterBoundCallback PROTO :XPTR
    KeShouldYieldProcessor PROTO
    MmLoadSystemImage PROTO :XPTR, :XPTR, :XPTR, :XWORD, :PVOID, :PVOID
    MmMapIoSpaceEx PROTO :XWORD, :SIZE_T, :XWORD
    MmUnloadSystemImage PROTO :XPTR
    PoCreateThermalRequest PROTO :XPTR, :XPTR, :XPTR, :XPTR, :XWORD
    PoDeleteThermalRequest PROTO :PVOID
    PoFxIssueComponentPerfStateChange PROTO :XWORD, :XWORD, :XWORD, :XPTR, :PVOID
    PoFxIssueComponentPerfStateChangeMultiple PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XPTR, :PVOID
    PoFxQueryCurrentComponentPerfState PROTO :XWORD, :XWORD, :XWORD, :XWORD, :PULONGLONG
    PoFxRegisterComponentPerfStates PROTO :XWORD, :XWORD, :XWORD, :XPTR, :XPTR, :XPTR
    PoGetThermalRequestSupport PROTO :XPTR, :XWORD
    PoSetThermalActiveCooling PROTO :XPTR, :XWORD
    PoSetThermalPassiveCooling PROTO :XPTR, :XWORD
    PsAllocateMonitorContextServerSilo PROTO :XPTR, :SIZE_T, :PVOID
    PsAttachSiloToCurrentThread PROTO :XPTR
    PsDeleteMonitorContextServerSilo PROTO :XPTR
    PsDereferenceMonitorContextServerSilo PROTO :XPTR
    PsDetachSiloFromCurrentThread PROTO :XPTR
    PsEqualCurrentServerSilo PROTO :XPTR
    PsEqualCurrentSilo PROTO :XPTR
    PsGetCurrentServerSilo PROTO
    PsGetCurrentServerSiloName PROTO
    PsGetCurrentSilo PROTO
    PsGetCurrentSiloObject PROTO :ULONG_PTR, :PVOID
    PsGetJobServerSilo PROTO :XWORD, :XPTR
    PsGetMonitorContextServerSilo PROTO :XWORD, :XWORD, :PVOID
    PsGetServerSiloServiceSessionId PROTO :XWORD
    PsGetSiloObjectFromJob PROTO :HANDLE, :ULONG_PTR, :PVOID
    PsGetThreadCreateTime PROTO :XWORD
    PsGetThreadProperty PROTO :XWORD, :ULONG_PTR, :XWORD
    PsInsertSiloObjectFromJob PROTO :HANDLE, :ULONG_PTR, :PVOID
    PsIsCurrentThreadInServerSilo PROTO
    PsIsHostSilo PROTO :XWORD
    PsReferenceMonitorContextServerSilo PROTO
    PsRegisterMonitorServerSilo PROTO :XPTR, :XPTR, :XWORD, :XPTR
    PsRegisterPicoProvider PROTO :XPTR, :XPTR
    PsRemoveSiloObjectFromJob PROTO :HANDLE, :ULONG_PTR
    PsSetCreateThreadNotifyRoutineEx PROTO :XWORD, :PVOID
    PsSetMonitorContextServerSilo PROTO :XWORD, :XWORD, :XWORD, :PVOID, :PVOID
    PsStartMonitorServerSilo PROTO :XWORD
    PsUnregisterMonitorServerSilo PROTO :XWORD
    RtlAddAccessDeniedAceEx PROTO :XPTR, :XWORD, :XWORD, :XWORD, :XPTR
    RtlAddAccessDeniedObjectAce PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XPTR, :XPTR, :XWORD
    RtlAddAuditAccessAceEx PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XPTR, :XWORD, :XWORD
    RtlAddAuditAccessObjectAce PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XPTR, :XPTR, :XWORD, :XWORD, :XWORD
    RtlDecompressBufferEx2 PROTO :XWORD, :XPTR, :XWORD, :XPTR, :XWORD, :XWORD, :XPTR, :XPTR
    RtlDecompressFragmentEx PROTO :XWORD, :XPTR, :XWORD, :XPTR, :XWORD, :XWORD, :XWORD, :XPTR, :XPTR
    RtlEndStrongEnumerationHashTable PROTO :XPTR, :XPTR
    RtlFirstFreeAce PROTO :XWORD, :XPTR
    RtlGetControlSecurityDescriptor PROTO :XPTR, :XPTR, :XPTR
    RtlInitializeSidEx PROTO :XPTR, :XPTR, :XWORD
    RtlInitStringEx PROTO :XPTR, :XPTR
    RtlInitStrongEnumerationHashTable PROTO :XPTR, :XPTR
    RtlLargeIntegerToChar PROTO :XPTR, :XWORD, :XWORD, :XPTR
    RtlOsDeploymentState PROTO :XWORD
    RtlStronglyEnumerateEntryHashTable PROTO :XWORD, :XWORD
    RtlSuffixUnicodeString PROTO :XWORD, :XWORD, :XPTR
    RtlUnicodeStringToInt64 PROTO :XPTR, :XWORD, :XPTR, :XPTR
    RtlValidAcl PROTO :XPTR
    SeAuditFipsCryptoSelftests PROTO :XWORD, :XWORD
    SeMarkLogonSessionForTerminationNotificationEx PROTO :XWORD, :XPTR
    SeQuerySessionIdTokenEx PROTO :XWORD, :XPTR, :XPTR
    SeRegisterLogonSessionTerminatedRoutineEx PROTO :XPTR
    SeUnregisterLogonSessionTerminatedRoutineEx PROTO :XPTR
    ZwAlpcOpenSenderThread PROTO :XPTR, :XWORD, :XPTR, :XWORD, :XWORD, :XPTR
    ZwAlpcQueryInformationMessage PROTO :XWORD, :XPTR, :XWORD, :XPTR, :XWORD, :XPTR
    ZwCompareTokens PROTO :HANDLE, :HANDLE, :XPTR
    ZwGetCachedSigningLevel PROTO :HANDLE, :XPTR, :XWORD, :XPTR, :XPTR, :XPTR
    ZwGetNextProcess PROTO :HANDLE, :XWORD, :XWORD, :XWORD, :XPTR
    ZwNotifyChangeDirectoryFile PROTO :HANDLE, :HANDLE, :XPTR, :XPTR, :XPTR, :XPTR, :XWORD, :XWORD, :XWORD
    ZwTraceControl PROTO :XWORD, :XPTR, :XWORD, :XPTR, :XWORD, :XPTR
    ZwUnloadKey2 PROTO :XPTR, :XWORD
ENDIF

;======================= Undocumented functions (unknown arguments) =======================;
;BgkDisplayCharacter PROTO
;BgkGetConsoleState PROTO
;BgkGetCursorState PROTO
;BgkSetCursor PROTO
;CcAddDirtyPagesToExternalCache PROTO
;CcDeductDirtyPagesFromExternalCache PROTO
;CcFlushCacheToLsn PROTO
;CcRegisterExternalCache PROTO
;CcTestControl PROTO
;CcUnregisterExternalCache PROTO
;CcZeroDataOnDisk PROTO
;CmKeyObjectType PROTO
;DbgkLkmdRegisterCallback PROTO
;DbgkLkmdUnregisterCallback PROTO
;DbgkWerCaptureLiveKernelDump PROTO
;EmClientRuleDeregisterNotification PROTO
;EmClientRuleEvaluate PROTO
;EmClientRuleRegisterNotification PROTO
;EmpProviderRegister PROTO
;EmProviderDeregister PROTO
;EmProviderDeregisterEntry PROTO
;EmProviderRegister PROTO
;EmProviderRegisterEntry PROTO
;EtwEnableTrace PROTO
;EtwRegisterClassicProvider PROTO
;EtwSendTraceBuffer PROTO
;EtwSetInformation PROTO
;EtwWriteEndScenario PROTO
;CcFastReadNotPossible PROTO
;EtwWriteStartScenario PROTO
;ExAcquireAutoExpandPushLockExclusive PROTO
;ExAcquireAutoExpandPushLockShared PROTO
;ExAcquireCacheAwarePushLockExclusive PROTO
;ExAcquireCacheAwarePushLockExclusiveEx PROTO
;ExAcquireCacheAwarePushLockSharedEx PROTO
;ExAcquirePushLockExclusiveEx PROTO
;ExAcquirePushLockSharedEx PROTO
;ExAcquireRundownProtectionCacheAware PROTO
;ExAcquireRundownProtectionCacheAwareEx PROTO
;ExAllocateAutoExpandPushLock PROTO
;ExBlockOnAddressPushLock PROTO
;ExCleanupAutoExpandPushLock PROTO
;ExCleanupRundownProtectionCacheAware PROTO
;ExCompositionObjectType PROTO
;ExCompositionSurfaceObjectType PROTO
;ExConvertPushLockExclusiveToShared PROTO
;ExDesktopObjectType PROTO
;ExEnterPriorityRegionAndAcquireResourceExclusive PROTO
;ExEnterPriorityRegionAndAcquireResourceShared PROTO
;ExEventObjectType PROTO
;ExFetchLicenseData PROTO
;ExFreeAutoExpandPushLock PROTO
;ExFreeCacheAwareRundownProtection PROTO
;ExfTryAcquirePushLockShared PROTO
;ExGetLicenseTamperState PROTO
;ExiAcquireFastMutex PROTO
;ExInitializeAutoExpandPushLock PROTO
;ExInitializeRundownProtectionCacheAwareEx PROTO
;ExNotifyBootDeviceRemoval PROTO
;ExQueryAttributeInformation PROTO
;ExQueryFastCacheAppOrigin PROTO
;ExQueryFastCacheDevLicense PROTO
;ExQueryWnfStateData PROTO
;ExRawInputManagerObjectType PROTO
;ExRealTimeIsUniversal PROTO
;ExRegisterAttributeInformationCallback PROTO
;ExRegisterBootDevice PROTO
;ExRegisterExtension PROTO
;ExReleaseAutoExpandPushLockExclusive PROTO
;ExReleaseAutoExpandPushLockShared PROTO
;ExReleaseCacheAwarePushLockExclusiveEx PROTO
;ExReleaseCacheAwarePushLockSharedEx PROTO
;ExReleasePushLockEx PROTO
;ExReleasePushLockExclusiveEx PROTO
;ExReleasePushLockSharedEx PROTO
;ExReleaseResourceAndLeavePriorityRegion PROTO
;ExSemaphoreObjectType PROTO
;ExShareAddressSpaceWithDevice PROTO
;ExSizeOfAutoExpandPushLock PROTO
;ExSizeOfRundownProtectionCacheAware PROTO
;ExSubscribeWnfStateChange PROTO
;ExTimerObjectType PROTO
;ExTryAcquireAutoExpandPushLockExclusive PROTO
;ExTryAcquireAutoExpandPushLockShared PROTO
;ExTryAcquireCacheAwarePushLockExclusiveEx PROTO
;ExTryAcquireCacheAwarePushLockSharedEx PROTO
;ExTryAcquirePushLockExclusiveEx PROTO
;ExTryAcquirePushLockSharedEx PROTO
;ExTryConvertPushLockSharedToExclusiveEx PROTO
;ExTryQueueWorkItem PROTO
;ExTryToAcquireResourceExclusiveLite PROTO
;ExUnblockOnAddressPushLockEx PROTO
;ExUnblockPushLockEx PROTO
;ExUnregisterAttributeInformationCallback PROTO
;ExUnregisterExtension PROTO
;ExUnsubscribeWnfStateChange PROTO
;ExUpdateLicenseData PROTO
;ExWaitForRundownProtectionReleaseCacheAware PROTO
;ExWindowStationObjectType PROTO
;FsRtlAcquireEofLock PROTO
;FsRtlAcquireHeaderMutex PROTO
;FsRtlCheckUpperOplock PROTO
;FsRtlDismountComplete PROTO
;FsRtlGetFileNameInformation PROTO
;FsRtlGetIoAtEof PROTO
;FsRtlHeatInit PROTO
;FsRtlHeatLogIo PROTO
;FsRtlHeatLogTierMove PROTO
;FsRtlHeatUninit PROTO
;FsRtlInitializeBaseMcb PROTO
;FsRtlInitializeBaseMcbEx PROTO
;FsRtlInitializeEofLock PROTO
;FsRtlInsertReservedPerFileContext PROTO
;FsRtlInsertReservedPerStreamContext PROTO
;FsRtlIsMobileOS PROTO
;FsRtlKernelFsControlFile PROTO
;FsRtlLegalAnsiCharacterArray PROTO
;FsRtlLookupLastBaseMcbEntry PROTO
;FsRtlLookupReservedPerFileContext PROTO
;FsRtlLookupReservedPerStreamContext PROTO
;FsRtlNotifyFilterChangeDirectoryLite PROTO
;FsRtlNotifyFilterReportChangeLite PROTO
;FsRtlNumberOfRunsInBaseMcb PROTO
;FsRtlQueryInformationFile PROTO
;FsRtlQueryKernelEaFile PROTO
;FsRtlRegisterFltMgrCalls PROTO
;FsRtlRegisterMupCalls PROTO
;FsRtlRegisterUncProviderEx2 PROTO
;FsRtlReleaseEofLock PROTO
;FsRtlReleaseFileNameInformation PROTO
;FsRtlReleaseHeaderMutex PROTO
;FsRtlRemoveReservedPerFileContext PROTO
;FsRtlRemoveReservedPerStreamContext PROTO
;FsRtlSendModernAppTermination PROTO
;FsRtlSetDriverBacking PROTO
;FsRtlSetKernelEaFile PROTO
;FsRtlTryToAcquireHeaderMutex PROTO
;FsRtlUpdateDiskCounters PROTO
;FsRtlValidateReparsePointBuffer PROTO
;HalDispatchTable PROTO
;HalPrivateDispatchTable PROTO
;HvlGetLpIndexFromApicId PROTO
;HviGetDebugDeviceOptions PROTO
;HviGetEnlightenmentInformation PROTO
;HviGetHardwareFeatures PROTO
;HviGetHypervisorFeatures PROTO
;HviGetHypervisorInterface PROTO
;HviGetHypervisorVendorAndMaxFunction PROTO
;HviGetHypervisorVersion PROTO
;HviGetImplementationLimits PROTO
;HviIsAnyHypervisorPresent PROTO
;HviIsHypervisorMicrosoftCompatible PROTO
;HviIsHypervisorVendorMicrosoft PROTO
;HviIsIommuInUse PROTO
;HvlPerformEndOfInterrupt PROTO
;HvlQueryActiveHypervisorProcessorCount PROTO
;HvlQueryActiveProcessors PROTO
;HvlQueryConnection PROTO
;HvlQueryHypervisorProcessorNodeNumber PROTO
;HvlQueryNumaDistance PROTO
;HvlQueryProcessorTopology PROTO
;HvlQueryProcessorTopologyCount PROTO
;HvlQueryProcessorTopologyHighestId PROTO
;HvlReadPerformanceStateCounters PROTO
;HvlRegisterInterruptCallback PROTO
;HvlRegisterWheaErrorNotification PROTO
;HvlUnregisterInterruptCallback PROTO
;HvlUnregisterWheaErrorNotification PROTO
;InbvNotifyDisplayOwnershipChange PROTO
;InbvSetVirtualFrameBuffer PROTO
;InitSafeBootMode PROTO
;IoAdapterObjectType PROTO
;IoAdjustStackSizeForRedirection PROTO
;IoAllocateIrpEx PROTO
;IoApplyPriorityInfoThread PROTO
;IoBoostThreadIo PROTO
;IoCallDriverStackSafe PROTO
;IoClearDependency PROTO
;IoClearReservedDependency PROTO
;IoCompletionObjectType PROTO
;IoConvertFileHandleToKernelHandle PROTO
;IoCopyDeviceObjectHint PROTO
;IoCreateArcName PROTO
;IoDeleteAllDependencyRelations PROTO
;IoDeviceHandlerObjectSize PROTO
;IoDeviceHandlerObjectType PROTO
;IoDeviceObjectType PROTO
;IoDriverObjectType PROTO
;IoDuplicateDependency PROTO
;IoEnumerateRegisteredFiltersListEx
;IoFileObjectType PROTO
;IoFreeMiniCompletionPacket PROTO
;IoGetFsTrackOffsetState PROTO
;IoGetFsZeroingOffset PROTO
;IoGetGenericIrpExtension PROTO
;IoGetSymlinkSupportInformation PROTO
;IoInitializeMiniCompletionPacket PROTO
;IoIsActivityTracingEnabled PROTO
;IoLoadCrashDumpDriver PROTO
;IoMakeAssociatedIrpEx PROTO
;IoPropagateIrpExtension PROTO
;IoPropagateIrpExtensionEx PROTO
;IoQueryInterface PROTO
;IoQueueWorkItemToNode PROTO
;IoReadOperationCount PROTO
;IoReadTransferCount PROTO
;IoRegisterFsRegistrationChangeMountAwareEx PROTO
;IoRegisterIoTracking PROTO
;IoRegisterPriorityCallback PROTO
;IoRequestDeviceEjectEx PROTO
;IoReserveDependency PROTO
;IoResolveDependency PROTO
;IoRetrievePriorityInfo PROTO
;IoSetDependency PROTO
;IoSetGenericIrpExtension PROTO
;IoSetIoCompletionEx PROTO
;IoSetIoPriorityHintIntoFileObject PROTO
;IoSetIoPriorityHintIntoThread PROTO
;IoSizeofGenericIrpExtension PROTO
;IoStatisticsLock PROTO
;IoSynchronousCallDriver PROTO
;IoSteerInterrupt PROTO
;IoTestDependency PROTO
;IoUnregisterIoTracking PROTO
;IoVolumeDeviceNameToGuidPath PROTO
;IoVolumeDeviceToGuidPath PROTO
;IoWriteOperationCount PROTO
;IoWriteTransferCount PROTO
;iswalnum PROTO
;iswdigit PROTO
;iswspace PROTO
;KdAcquireDebuggerLock PROTO
;KdChangeOption PROTO
;KdDebuggerEnabled PROTO
;KdDebuggerNotPresent PROTO
;KdDeregisterPowerHandler PROTO
;KdEnteredDebugger PROTO
;KdEventLoggingEnabled PROTO
;KdGetDebugDevice PROTO
;KdRegisterPowerHandler PROTO
;KdReleaseDebuggerLock PROTO
;KdSetEventLoggingPresent PROTO
;KeAddGroupAffinityEx PROTO
;KeAddProcessorAffinityEx PROTO
;KeAddProcessorGroupAffinity PROTO
;KeAllocateCalloutStack PROTO
;KeAllocateCalloutStackEx PROTO
;KeAndGroupAffinityEx PROTO
;KeCancelTimer2 PROTO
;KeCheckProcessorAffinityEx PROTO
;KeCheckProcessorGroupAffinity PROTO
;KeClockInterruptNotify PROTO
;KeClockTimerPowerChange PROTO
;KeConnectInterruptForHal PROTO
;KeCopyAffinityEx PROTO
;KeCountSetBitsAffinityEx PROTO
;KeCountSetBitsGroupAffinity PROTO
;KeDcacheFlushCount PROTO
;KeDispatchSecondaryInterrupt PROTO
;KeEnumerateNextProcessor PROTO
;KeFindFirstSetLeftGroupAffinity PROTO
;KeFindFirstSetRightAffinityEx PROTO
;KeFindFirstSetRightGroupAffinity PROTO
;KeFirstGroupAffinityEx PROTO
;KeForceEnableNx PROTO
;KeFreeCalloutStack PROTO
;KeGetClockOwner PROTO
;KeGetClockTimerResolution PROTO
;KeGetEffectiveIrql PROTO
;KeGetNextClockTickDuration PROTO
;KeGetNextTimerExpirationDueTime PROTO
;KeGetXSaveFeatureFlags PROTO
;KeHwPolicyLocateResource PROTO
;KeI386Call16BitCStyleFunction PROTO
;Kei386EoiHelper PROTO
;KeI386MachineType PROTO
;KeIcacheFlushCount PROTO
;KeInitializeAffinityEx PROTO
;KeInitializeEnumerationContextFromGroup PROTO
;KeInitializeSecondaryInterruptServices PROTO
;KeInitializeTimer2 PROTO
;KeInterlockedClearProcessorAffinityEx PROTO
;KeIsSingleGroupAffinityEx PROTO
;KeLastBranchMSR PROTO
;KeLoaderBlock PROTO :VARARG
;KeLoadMTRR PROTO
;KeNotifyProcessorFreezeSupported PROTO
;KeNumberProcessors PROTO
;KeOrAffinityEx PROTO
;KeProcessorGroupAffinity PROTO
;KeQueryActiveProcessorAffinity PROTO
;KeQueryEffectivePriorityThread PROTO
;KeQueryGroupAffinityEx PROTO
;KeQueryHeteroCpuPolicyThread PROTO
;KeQueryMultiThreadProcessorSet PROTO
;KeRemoveGroupAffinityEx PROTO
;KeRemoveProcessorAffinityEx PROTO
;KeRemoveProcessorGroupAffinity PROTO
;KeRemoveQueueDpcEx PROTO
;KeReportCacheIncoherentDevice PROTO
;KeRevertToUserAffinityThread PROTO
;KeServiceDescriptorTable PROTO
;KeSetActualBasePriorityThread PROTO
;KeSetHeteroCpuPolicyThread PROTO
;KeSetSelectedCpuSetsThread PROTO
;KeSetTimer2 PROTO
;KeSignalCallDpcDone PROTO
;KeSignalCallDpcSynchronize PROTO
;KeStallWhileFrozen PROTO
;KeStartDynamicProcessor PROTO
;KeSubtractAffinityEx PROTO
;KeSweepLocalCaches PROTO
;KeSynchronizeTimeToQpc PROTO
;KeSystemFullyCacheCoherent PROTO
;KeTickCount PROTO
;KeUpdateSystemTime PROTO
;KeUpdateTime PROTO
;KeUpdateThreadTag PROTO
;KeUpdateTimeAssist PROTO
;KeWriteProtectPAT PROTO
;KfRaiseIrql PROTO
;KiBugCheckData PROTO
;KiCheckForSListAddress PROTO
;KiCpuId PROTO
;KiDispatchInterrupt PROTO
;KiEnableTimerWatchdog PROTO
;KitLogFeatureUsage PROTO
;KiUnexpectedInterrupt PROTO
;KseQueryDeviceData PROTO
;KseQueryDeviceDataList PROTO
;KseQueryDeviceFlags PROTO
;KseRegisterShim PROTO
;KseRegisterShimEx PROTO
;KseSetDeviceFlags PROTO
;KseUnregisterShim PROTO
;LdrFindResourceEx_U PROTO
;LdrResFindResource PROTO
;LdrResFindResourceDirectory PROTO
;LdrResSearchResource PROTO
;LpcPortObjectType PROTO
;LpcReplyWaitReplyPort PROTO
;LpcSendWaitReceivePort PROTO
;Mm64BitPhysicalAddress PROTO
;MmAddVerifierSpecialThunks PROTO
;MmAreMdlPagesCached PROTO
;MmBadPointer PROTO
;MmChangeImageProtection PROTO
;MmGetCacheAttribute PROTO
;MmHighestUserAddress PROTO
;MmMapViewInSessionSpaceEx PROTO
;MmMapViewInSystemSpaceEx PROTO
;MmMdlPageContentsState PROTO
;MmPrefetchVirtualAddresses PROTO
;MmSectionObjectType PROTO
;MmSetUserExceptionCallout PROTO
;MmSystemRangeStart PROTO
;MmUserProbeAddress PROTO
;NlsAnsiCodePage PROTO
;NlsLeadByteInfo PROTO
;NlsMbCodePageTag PROTO
;NlsMbOemCodePageTag PROTO
;NlsOemCodePage PROTO
;NtBuildGUID PROTO
;NtBuildLab PROTO
;NtBuildNumber PROTO
;NtGetEnvironmentVariableEx PROTO
;NtGlobalFlag PROTO
;NtQueryEnvironmentVariableInfoEx PROTO
;NtSetCachedSigningLevel PROTO
;NtSetInformationVirtualMemory PROTO
;ObfDereferenceObjectWithTag PROTO
;ObGetObjectType PROTO
;ObOpenObjectByNameEx PROTO
;ObReferenceObjectSafeWithTag PROTO
;ObWaitForMultipleObjects PROTO
;PfFileInfoNotify PROTO
;PoAllProcessorsDeepIdle PROTO
;PoCpuIdledSinceLastCallImprecise PROTO
;PoDisableSleepStates PROTO
;PoFxProcessorNotification PROTO
;PoEnergyEstimationEnabled PROTO
;PoFxEnableDStateReporting PROTO
;PoFxRegisterCoreDevice PROTO
;PoFxRegisterPlugin PROTO
;PoFxRegisterPluginEx PROTO
;PoFxRegisterPrimaryDevice PROTO
;PoGetProcessorIdleAccounting PROTO
;POGOBuffer PROTO
;PoInitiateProcessorWake PROTO
;PoLatencySensitivityHint PROTO
;PoNotifyDisableDynamicTick PROTO
;PoNotifyMediaBuffering PROTO
;PoNotifyVSyncChange PROTO
;PoQueueShutdownWorkItem PROTO
;PoReenableSleepStates PROTO
;PoRegisterCoalescingCallback PROTO
;PoSetFixedWakeSource PROTO
;PoSetUserPresent PROTO
;PoSetSystemWakeDevice PROTO
;PoUnregisterCoalescingCallback PROTO
;PoUserShutdownCancelled PROTO
;PoUserShutdownInitiated PROTO
;PsChargeProcessCpuCycles PROTO
;PsChargeProcessWakeCounter PROTO
;PsDereferenceKernelStack PROTO
;PsEnterPriorityRegion PROTO
;PsGetCurrentProcessWow64Process PROTO
;PsGetCurrentThreadWin32ThreadAndEnterCriticalRegion PROTO
;PsGetEffectiveContainerId PROTO
;PsGetJobProperty PROTO
;PsGetProcessCommonJob PROTO
;PsGetProcessProtection PROTO
;PsGetProcessServerSilo PROTO
;PsGetProcessSessionIdEx PROTO
;PsGetProcessSignatureLevel PROTO
;PsGetSiloIdentifier PROTO
;PsInitialSystemProcess PROTO
;PsIsProcessInAppSilo PROTO
;PsIsProtectedProcess PROTO
;PsIsProtectedProcessLight PROTO
;PsJobType PROTO
;PsLeavePriorityRegion PROTO
;psMUITest PROTO
;PsLoadedModuleList PROTO
;PsLoadedModuleResource PROTO
;PsUpdateComponentPower PROTO
;PsQueryProcessAttributesByToken PROTO
;PsQueryProcessExceptionFlags PROTO
;PsReferenceKernelStack PROTO
;PsReleaseProcessExitSynchronization PROTO
;PsReleaseProcessWakeCounter PROTO
;PsSetCreateProcessNotifyRoutineEx2 PROTO
;PsSetJobProperty PROTO
;PsSetThreadProperty PROTO
;PsUILanguageComitted PROTO
;RtlAddAccessAllowedObjectAce PROTO
;RtlAddAtomToAtomTableEx PROTO
;RtlAddProcessTrustLabelAce PROTO
;RtlAddResourceAttributeAce PROTO
;RtlAreBitsClearEx PROTO
;RtlAreBitsSetEx PROTO
;RtlAvlInsertNodeEx PROTO
;RtlAvlRemoveNode PROTO
;RtlCapabilityCheck PROTO
;RtlCheckTokenCapability PROTO
;RtlCheckTokenMembership PROTO
;RtlCheckTokenMembershipEx PROTO
;RtlClearAllBitsEx PROTO
;RtlClearBitEx PROTO
;RtlClearBitsEx PROTO
;RtlContractHashTable PROTO
;RtlCopyBitMap PROTO
;RtlCopyMemoryNonTemporal PROTO
;RtlCrc32 PROTO
;RtlCrc64 PROTO
;RtlCreateAtomTableEx PROTO
;RtlCreateHashTable PROTO
;RtlCreateHashTableEx PROTO
;RtlDeleteHashTable PROTO
;RtlEndEnumerationHashTable PROTO
;RtlEndWeakEnumerationHashTable PROTO
;RtlEnumerateEntryHashTable PROTO
;RtlEqualWnfChangeStamps PROTO
;RtlExpandHashTable PROTO
;RtlExtractBitMap PROTO
;RtlFindAceByType PROTO
;RtlFindClearBitsAndSetEx PROTO
;RtlFindClearBitsEx PROTO
;RtlFindClosestEncodableLength PROTO
;RtlFindExportedRoutineByName PROTO
;RtlFindNextForwardRunClearEx PROTO
;RtlFindSetBitsAndClearEx PROTO
;RtlFindSetBitsEx PROTO
;RtlGenerateClass5Guid PROTO
;RtlGetAppContainerNamedObjectPath PROTO
;RtlGetAppContainerParent PROTO
;RtlGetAppContainerSidType PROTO
;RtlGetIntegerAtom PROTO
;RtlGetLastRange PROTO
;RtlGetProductInfo PROTO
;RtlIdnToAscii PROTO
;RtlIdnToNameprepUnicode PROTO
;RtlIdnToUnicode PROTO
;RtlImageNtHeaderEx PROTO
;RtlInitializeBitMapEx PROTO
;RtlInterlockedClearBitRun PROTO
;RtlInterlockedSetBitRun PROTO
;RtlInterlockedSetClearRun PROTO
;RtlInvertRangeListEx PROTO
;RtlIsMultiSessionSku PROTO
;RtlIsSandboxedToken PROTO
;RtlIsUntrustedObject PROTO
;RtlLCIDToCultureName PROTO
;RtlLoadString PROTO
;RtlNormalizeString PROTO
;RtlNumberOfClearBitsEx PROTO
;RtlNumberOfClearBitsInRange PROTO
;RtlNumberOfSetBitsEx PROTO
;RtlNumberOfSetBitsInRange PROTO
;RtlOwnerAcesPresent PROTO
;RtlQueryDynamicTimeZoneInformation PROTO
;RtlQueryModuleInformation PROTO
;RtlQueryPackageClaims PROTO
;RtlQueryPackageIdentity PROTO
;RtlQueryRegistryValuesEx PROTO
;RtlQueryValidationRunlevel PROTO
;RtlRbReplaceNode PROTO
;RtlRemoveEntryHashTable PROTO
;RtlReplaceSidInSd PROTO
;RtlSetAllBitsEx PROTO
;RtlSetBitEx PROTO
;RtlSetBitsEx PROTO
;RtlSetDynamicTimeZoneInformation PROTO
;RtlSetPortableOperatingSystem PROTO
;RtlSidHashInitialize PROTO
;RtlSidHashLookup PROTO
;RtlTestBitEx PROTO
;RtlWeaklyEnumerateEntryHashTable PROTO
;SeAccessCheckFromState PROTO
;SeAccessCheckFromStateEx PROTO
;SeAccessCheckWithHint PROTO
;SeAuditingAnyFileEventsWithContextEx PROTO
;SeAuditingFileEventsWithContextEx PROTO
;SeAuditingWithTokenForSubcategory PROTO
;SeCloseObjectAuditAlarmForNonObObject PROTO
;SeCompareSigningLevels PROTO
;SeCreateClientSecurityEx PROTO
;SeCreateClientSecurityFromSubjectContextEx PROTO
;SeExports PROTO
;SeGetCachedSigningLevel PROTO
;SeGetLinkedToken PROTO
;SeGetLogonSessionToken PROTO
;SeIsParentOfChildAppContainer PROTO
;SeOpenObjectAuditAlarmForNonObObject PROTO
;SeOpenObjectAuditAlarmWithTransaction PROTO
;SePublicDefaultDacl PROTO
;SeQuerySecureBootPolicyValue PROTO
;SeQuerySecurityAttributesToken PROTO
;SeRegisterImageVerificationCallback PROTO
;SeSecurityAttributePresent PROTO
;SeSetAuthorizationCallbacks PROTO
;SeSetSecurityAttributesToken PROTO
;SeSetSecurityAttributesTokenEx PROTO
;SeSrpAccessCheck PROTO
;SeSystemDefaultDacl PROTO
;SeSystemDefaultSd PROTO
;SeTokenFromAccessInformation PROTO
;SeUnregisterImageVerificationCallback PROTO
;SkAcquirePushLockExclusive PROTO
;SkAllocatePool PROTO
;SkFreePool PROTO
;SkInitializePushLock PROTO
;SkIsSecureKernel PROTO
;SkQuerySecureKernelInformation PROTO
;SkReleasePushLockExclusive PROTO
;sprintf PROTO
;sprintf_s PROTO
;sqrt PROTO
;sqrtf PROTO
;srand PROTO
;sscanf_s PROTO
;strcat PROTO
;strcat_s PROTO
;strchr PROTO
;strcmp PROTO
;strcpy PROTO
;strcpy_s PROTO
;strlen PROTO
;strncat PROTO
;strncat_s PROTO
;strncmp PROTO
;strncpy PROTO
;strncpy_s PROTO
;strnlen PROTO
;strrchr PROTO
;strspn PROTO
;strstr PROTO
;strtok_s PROTO
;swprintf PROTO
;swprintf_s PROTO
;swscanf_s PROTO
;TmCancelPropagationRequest PROTO
;TmCurrentTransaction PROTO
;TmEndPropagationRequest PROTO
;TmEnlistmentObjectType PROTO
;TmFreezeTransactions PROTO
;TmInitializeResourceManager PROTO
;TmInitializeTransaction PROTO
;TmInitSystem PROTO
;TmInitSystemPhase2 PROTO
;TmIsKTMCommitCoordinator PROTO
;TmpIsKTMCommitCoordinator PROTO
;TmPropagationComplete PROTO
;TmPropagationFailed PROTO
;TmResourceManagerObjectType PROTO
;TmSetCurrentTransaction PROTO
;TmThawTransactions PROTO
;TmTransactionManagerObjectType PROTO
;TmTransactionObjectType PROTO
;VfCheckNxPagePriority PROTO
;VfCheckNxPageProtection PROTO
;VfCheckNxPoolType PROTO
;VfFailDeviceNode PROTO
;VfFailDriver PROTO
;VfFailSystemBIOS PROTO
;VfInsertContext PROTO
;VfQueryDeviceContext PROTO
;VfQueryDispatchTable PROTO
;VfQueryDriverContext PROTO
;VfQueryIrpContext PROTO
;VfQueryThreadContext PROTO
;VfRemoveContext PROTO
;VmAccessFault PROTO
;VmCreateMemoryRange PROTO
;VmDeleteMemoryRange PROTO
;VslExchangeEntropy PROTO
;VslRetrieveMailbox PROTO
;WheaAttemptPhysicalPageOffline PROTO
;WheaConfigureErrorSource PROTO
;WheaDeferredRecoveryService PROTO
;WheaGetErrorSource PROTO
;WheaInitializeDeferredRecoveryObject PROTO
;WheaInitializeRecordHeader PROTO
;WheaRegisterErrSrcInitializer PROTO
;WheaReportHwError PROTO
;WheaRequestDeferredRecovery PROTO
;ZwAlpcConnectPortEx PROTO
;ZwCreateWnfStateName PROTO
;ZwDeleteDriverEntry PROTO
;ZwDeleteWnfStateData PROTO
;ZwDeleteWnfStateName PROTO
;ZwNotifyChangeSession PROTO
;ZwQueryLicenseValue PROTO
;ZwQueryWnfStateData PROTO
;ZwQueryWnfStateNameInformation PROTO
;ZwSetCachedSigningLevel PROTO
;ZwSetInformationVirtualMemory PROTO
;ZwUpdateWnfStateData PROTO
;_abnormal_termination PROTO
;_alloca_probe PROTO
;_alloca_probe_16 PROTO
;_alloca_probe_8 PROTO
;_CIcos PROTO
;_CIsin PROTO
;_CIsqrt PROTO
;_local_unwind PROTO
;IFNDEF __misaligned_access
;    __misaligned_access PROTO
;ENDIF
;_snscanf_s PROTO
;_snwprintf PROTO
;_snwprintf_s PROTO
;_snwscanf_s PROTO

ENDIF ;NTOSKRNL_INC
