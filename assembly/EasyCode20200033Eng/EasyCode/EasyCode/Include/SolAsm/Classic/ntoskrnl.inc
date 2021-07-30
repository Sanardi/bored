; ========================================================;
;                                                         ;
;     ntoskrnl.inc for EC v2 SolAsm classic projects      ;
;                     (version 1.0.2)                     ;
;                                                         ;
;           Copyright © Ramon Sala - 2018-2019            ;
;                                                         ;
; ========================================================;

#ifndef NTOSKRNL_INC
NTOSKRNL_INC     equ     1

#ifndef xword_def
    xword_def equ 1
    #ifdef APP_WIN64
        define xword dq
    #else
        define xword dd
    #endif
#endif

#ifndef ANYSIZE_ARRAY
    ANYSIZE_ARRAY                               equ     1
#endif

FSRTL_FAT_LEGAL                                 equ     01H
FSRTL_HPFS_LEGAL                                equ     02H
FSRTL_NTFS_LEGAL                                equ     04H
FSRTL_WILD_CHARACTER                            equ     08H
FSRTL_OLE_LEGAL                                 equ     10H
FSRTL_NTFS_STREAM_LEGAL                         equ     <FSRTL_NTFS_LEGAL or FSRTL_OLE_LEGAL>

FSRTL_VOLUME_DISMOUNT                           equ     1
FSRTL_VOLUME_DISMOUNT_FAILED                    equ     2
FSRTL_VOLUME_LOCK                               equ     3
FSRTL_VOLUME_LOCK_FAILED                        equ     4
FSRTL_VOLUME_UNLOCK                             equ     5
FSRTL_VOLUME_MOUNT                              equ     6
FSRTL_VOLUME_NEEDS_CHKDSK                       equ     7
FSRTL_VOLUME_WORM_NEAR_FULL                     equ     8
FSRTL_VOLUME_WEARING_OUT                        equ     9
FSRTL_VOLUME_FORCED_CLOSED                      equ     10
FSRTL_VOLUME_INFO_MAKE_COMPAT                   equ     11
FSRTL_VOLUME_PREPARING_EJECT                    equ     12
FSRTL_VOLUME_CHANGE_SIZE                        equ     13
FSRTL_VOLUME_BACKGROUND_FORMAT                  equ     14

FSRTL_ECP_LOOKASIDE_FLAG_NONPAGED_POOL          equ     00000002H

FSRTL_UNC_PROVIDER_FLAGS_MAILSLOTS_SUPPORTED    equ     00000001H
FSRTL_UNC_PROVIDER_FLAGS_CSC_ENABLED            equ     00000002H
FSRTL_UNC_PROVIDER_FLAGS_DOMAIN_SVC_AWARE       equ     00000004H

FSRTL_ALLOCATE_ECPLIST_FLAG_CHARGE_QUOTA        equ     00000001H

FSRTL_ALLOCATE_ECP_FLAG_CHARGE_QUOTA            equ     00000001H
FSRTL_ALLOCATE_ECP_FLAG_NONPAGED_POOL           equ     00000002H

FSRTL_VIRTDISK_FULLY_ALLOCATED                  equ     00000001H
FSRTL_VIRTDISK_NO_DRIVE_LETTER                  equ     00000002H

IO_FORCE_ACCESS_CHECK                           equ     0001H
IO_NO_PARAMETER_CHECKING                        equ     0100H

IO_REPARSE                                      equ     0
IO_REMOUNT                                      equ     1

;SYSDBG_COMMAND enumeration
SysDbgQueryModuleInformation                    equ     0
SysDbgQueryTraceInformation                     equ     1
SysDbgSetTracepoint                             equ     2
SysDbgSetSpecialCall                            equ     3
SysDbgClearSpecialCalls                         equ     4
SysDbgQuerySpecialCalls                         equ     5
SysDbgBreakPoint                                equ     6
SysDbgQueryVersion                              equ     7
SysDbgReadVirtual                               equ     8
SysDbgWriteVirtual                              equ     9
SysDbgReadPhysical                              equ     10
SysDbgWritePhysical                             equ     11
SysDbgReadControlSpace                          equ     12
SysDbgWriteControlSpace                         equ     13
SysDbgReadIoSpace                               equ     14
SysDbgWriteIoSpace                              equ     15
SysDbgReadMsr                                   equ     16
SysDbgWriteMsr                                  equ     17
SysDbgReadBusData                               equ     18
SysDbgWriteBusData                              equ     19
SysDbgCheckLowMemory                            equ     20
SysDbgEnableKernelDebugger                      equ     21
SysDbgDisableKernelDebugger                     equ     22
SysDbgGetAutoKdEnable                           equ     23
SysDbgSetAutoKdEnable                           equ     24
SysDbgGetPrintBufferSize                        equ     25
SysDbgSetPrintBufferSize                        equ     26
SysDbgGetKdUmExceptionEnable                    equ     27
SysDbgSetKdUmExceptionEnable                    equ     28
SysDbgGetTriageDump                             equ     29
SysDbgGetKdBlockEnable                          equ     30
SysDbgSetKdBlockEnable                          equ     31
SysDbgRegisterForUmBreakInfo                    equ     32
SysDbgGetUmBreakPid                             equ     33
SysDbgClearUmBreakPid                           equ     34
SysDbgGetUmAttachPid                            equ     35
SysDbgClearUmAttachPid                          equ     36

;PSPROCESSPRIORITYMOD Enumeration
PsProcessPriorityForeground                     equ     0
PsProcessPriorityBackground                     equ     1
PsProcessPrioritySpinning                       equ     2

;JOBOBJECTINFOCLASS Enumeration
JobObjectBasicAccountingInformation             equ     1
JobObjectBasicLimitInformation                  equ     2
JobObjectBasicProcessIdList                     equ     3
JobObjectBasicUIRestrictions                    equ     4
JobObjectSecurityLimitInformation               equ     5
JobObjectEndOfJobTimeInformation                equ     6
JobObjectAssociateCompletionPortInformation     equ     7
JobObjectBasicAndIoAccountingInformation        equ     8
JobObjectExtendedLimitInformation               equ     9
JobObjectJobSetInformation                      equ     10
MaxJobObjectInfoClass                           equ     11

;WAIT_TYPE Enumeration
WaitAll                                         equ     0
WaitAny                                         equ     1

;======================================== Structures ======================================;
#ifndef GUID_DEF
    GUID_DEF equ 1
    struc GUID
        Data1   dd  ?
        Data2   dw  ?
        Data3   dw  ?
        Data4   rb  8
    ends
#endif

#ifndef DUMMYSTRUCTNAME_DEF
    DUMMYSTRUCTNAME_DEF equ 1
    struc DUMMYSTRUCTNAME
        LowPart                                     dd      ?
        HighPart                                    dd      ?
    ends

    struc u
        LowPart                                     dd      ?
        HighPart                                    dd      ?
    ends
#endif

#ifndef LARGE_INTEGER_DEF
    LARGE_INTEGER_DEF equ 1
    struct LARGE_INTEGER
        union
            DUMMYSTRUCTNAME ?
            u               ?
            QuadPart dq     ?
        endu
    ends
#endif

#ifndef ULARGE_INTEGER_DEF
    ULARGE_INTEGER_DEF equ 1
    struct ULARGE_INTEGER
        union
            DUMMYSTRUCTNAME ?
            u               ?
            QuadPart dq     ?
        endu
    ends
#endif

#ifndef LUID_DEF
    LUID_DEF equ 1
    struc LUID
        LowPart     dd  ?
        HighPart    dd  ?
    ends
#endif

#ifndef STRING_DEF
    STRING_DEF equ 1
    struc STRING
        _Length         dw    ?
        MaximumLength   dw    ?
        Buffer          xword ?
    ends
    define ANSI_STRING STRING
    define OEM_STRING STRING
#endif

#ifndef UNICODE_STRING_DEF
    UNICODE_STRING_DEF equ 1
    struc UNICODE_STRING
        _Length         dw    ?
        MaximumLength   dw    ?
        Buffer          xword ?
    ends
#endif

#ifndef LIST_ENTRY_DEF
    LIST_ENTRY_DEF equ 1
    struc LIST_ENTRY
        Flink   xword ?
        Blink   xword ?
    ends
#endif

#ifndef OWNER_ENTRY_DEF
    OWNER_ENTRY_DEF equ 1
    struc OWNER_ENTRY
        OwnerThread     dd ?
        union
            OwnerCount  dd ?
            TableSize   dd ?
        endu
    ends
#endif

#ifndef ALPC_MESSAGE_ATTRIBUTES_DEF
    ALPC_MESSAGE_ATTRIBUTES_DEF equ 1
    struc ALPC_MESSAGE_ATTRIBUTES
        AllocatedAttributes dd ?
        ValidAttributes     dd ?
    ends
#endif

#ifndef SYSTEM_PERFORMANCE_INFORMATION_DEF
    SYSTEM_PERFORMANCE_INFORMATION_DEF equ 1
    struc SYSTEM_PERFORMANCE_INFORMATION
        IdleProcessTime             LARGE_INTEGER ?
        IoReadTransferCount         LARGE_INTEGER ?
        IoWriteTransferCount        LARGE_INTEGER ?
        IoOtherTransferCount        LARGE_INTEGER ?
        IoReadOperationCount        dd   ?
        IoWriteOperationCount       dd   ?
        IoOtherOperationCount       dd   ?
        AvailablePages              dd   ?
        CommittedPages              dd   ?
        CommitLimit                 dd   ?
        PeakCommitment              dd   ?
        PageFaultCount              dd   ?
        CopyOnWriteCount            dd   ?
        TransitionCount             dd   ?
        CacheTransitionCount        dd   ?
        DemandZeroCount             dd   ?
        PageReadCount               dd   ?
        PageReadIoCount             dd   ?
        CacheReadCount              dd   ?
        CacheIoCount                dd   ?
        DirtyPagesWriteCount        dd   ?
        DirtyWriteIoCount           dd   ?
        MappedPagesWriteCount       dd   ?
        MappedWriteIoCount          dd   ?
        PagedPoolPages              dd   ?
        NonPagedPoolPages           dd   ?
        PagedPoolAllocs             dd   ?
        PagedPoolFrees              dd   ?
        NonPagedPoolAllocs          dd   ?
        NonPagedPoolFrees           dd   ?
        FreeSystemPtes              dd   ?
        ResidentSystemCodePage      dd   ?
        TotalSystemDriverPages      dd   ?
        TotalSystemCodePages        dd   ?
        NonPagedPoolLookasideHits   dd   ?
        PagedPoolLookasideHits      dd   ?
        Spare3Count                 dd   ?
        ResidentSystemCachePage     dd   ?
        ResidentPagedPoolPage       dd   ?
        ResidentSystemDriverPage    dd   ?
        CcFastReadNoWait            dd   ?
        CcFastReadWait              dd   ?
        CcFastReadResourceMiss      dd   ?
        CcFastReadNotPossible       dd   ?
        CcFastMdlReadNoWait         dd   ?
        CcFastMdlReadWait           dd   ?
        CcFastMdlReadResourceMiss   dd   ?
        CcFastMdlReadNotPossible    dd   ?
        CcMapDataNoWait             dd   ?
        CcMapDataWait               dd   ?
        CcMapDataNoWaitMiss         dd   ?
        CcMapDataWaitMiss           dd   ?
        CcPinMappedDataCount        dd   ?
        CcPinReadNoWait             dd   ?
        CcPinReadWait               dd   ?
        CcPinReadNoWaitMiss         dd   ?
        CcPinReadWaitMiss           dd   ?
        CcCopyReadNoWait            dd   ?
        CcCopyReadWait              dd   ?
        CcCopyReadNoWaitMiss        dd   ?
        CcCopyReadWaitMiss          dd   ?
        CcMdlReadNoWait             dd   ?
        CcMdlReadWait               dd   ?
        CcMdlReadNoWaitMiss         dd   ?
        CcMdlReadWaitMiss           dd   ?
        CcReadAheadIos              dd   ?
        CcLazyWriteIos              dd   ?
        CcLazyWritePages            dd   ?
        CcDataFlushes               dd   ?
        CcDataPages                 dd   ?
        ContextSwitches             dd   ?
        FirstLevelTbFills           dd   ?
        SecondLevelTbFills          dd   ?
        SystemCalls                 dd   ?
        #if NTDDI_VERSION >= NTDDI_WIN8
            CcTotalDirtyPages       dq   ?
            CcDirtyPageThreshold    dq   ?
            ResidentAvailablePages  dq   ?
        #endif
    ends
#endif

struc ERESOURCE
    SystemResourcesList      LIST_ENTRY  ?
    OwnerTable               xword       ?
    ActiveCount              dw          ?
    Flag                     dw          ?
    SharedWaiters            xword       ?
    ExclusiveWaiters         xword       ?
    OwnerEntry               OWNER_ENTRY ?
    ActiveEntries            dd          ?
    ContentionCount          dd          ?
    NumberOfSharedWaiters    dd          ?
    NumberOfExclusiveWaiters dd          ?
    union
        Address              xword       ?
        CreatorBackTraceIndex dd         ?
    endu
    SpinLock                 dd          ?
ends

struc FSRTL_MUP_PROVIDER_INFO_LEVEL_1
    ProviderId  dd ?
ends

struc FSRTL_MUP_PROVIDER_INFO_LEVEL_2
  ProviderId    dd ?
  ProviderName  UNICODE_STRING ?
ends

#ifndef IO_DISCONNECT_INTERRUPT_PARAMETERS_DEF
    IO_DISCONNECT_INTERRUPT_PARAMETERS_DEF equ 1
    struc IO_DISCONNECT_INTERRUPT_PARAMETERS
        Version                   dd    ?
        union
            Generic               xword ?
            InterruptObject       xword ?
            InterruptMessageTable xword ?
        endu
    ends
#endif

#ifndef LOADER_PARTITION_INFORMATION_EX_DEF
    LOADER_PARTITION_INFORMATION_EX_DEF equ 1
    struc LOADER_PARTITION_INFORMATION_EX
        PartitionStyle  dd   ?
        PartitionNumber dd   ?
        union
            Signature   dd   ?
            DeviceId    GUID ?
        endu
    ends
#endif

struc BOOTDISK_INFORMATION_LITE
    NumberEntries  dd ?
    Entries        LOADER_PARTITION_INFORMATION_EX ?
ends

#ifndef PROCESSOR_NUMBER_DEF
    PROCESSOR_NUMBER_DEF equ 1
    struc PROCESSOR_NUMBER
        _Group     dw ?
        Number     db ?
        Reserved   db ?
    ends
#endif

#ifndef SECTION_OBJECT_POINTERS_DEF
    SECTION_OBJECT_POINTERS_DEF equ 1
    struc SECTION_OBJECT_POINTERS
        DataSectionObject  xword ?
        SharedCacheMap     xword ?
        ImageSectionObject xword ?
    ends
#endif

#ifndef OB_CALLBACK_REGISTRATION_DEF
    OB_CALLBACK_REGISTRATION_DEF equ 1
    struc OB_CALLBACK_REGISTRATION
        Version                     dw    ?
        OperationRegistrationCount  dw    ?
        Altitude                    UNICODE_STRING ?
        RegistrationContext         xword ?
        OperationRegistration       xword ?
    ends
#endif

#ifndef OB_OPERATION_REGISTRATION_DEF
    OB_OPERATION_REGISTRATION_DEF equ 1
    struc OB_OPERATION_REGISTRATION
        ObjectType     xword ?
        Operations     xword ?
        PreOperation   xword ?
        PostOperation  xword ?
    ends
#endif

struc PO_FX_COMPONENT
    Id                         GUID  ?
    IdleStateCount             dd    ?
    DeepestWakeableIdleState   dd    ?
    IdleStates                 xword ?
ends

struc PO_FX_COMPONENT_IDLE_STATE
    TransitionLatency    xword ?
    ResidencyRequirement xword ?
    NominalPower         xword ?
ends

struc PO_FX_DEVICE
    Version                            dd    ?
    ComponentCount                     dd    ?
    ComponentActiveConditionCallback   xword ?
    ComponentIdleConditionCallback     xword ?
    ComponentIdleStateCallback         xword ?
    DevicePowerRequiredCallback        xword ?
    DevicePowerNotRequiredCallback     xword ?
    PowerControlCallback               xword ?
    DeviceContext                      xword ?
    Components                         rs    PO_FX_COMPONENT,ANYSIZE_ARRAY
ends

;======================================== Functions =======================================;
#if COFF_FORMAT == 1
    from_lib ntoskrnl.lib
#else
    from_dll ntoskrnl.exe
#endif

#if NTDDI_VERSION >= NTDDI_WINNT4
    #ifndef atoi
        import atoi
    #endif
    #ifndef atol
        import atol
    #endif
    import CcCanIWrite
    import CcCopyRead
    import CcCopyWrite
    import CcDeferWrite
    import CcFastCopyRead
    import CcFastCopyWrite
    import CcFastMdlReadWait
    #if NTDDI_VERSION < NTDDI_VISTA
        import CcFastReadWait
    #endif
    import CcFlushCache
    import CcGetDirtyPages
    import CcGetFileObjectFromBcb
    import CcGetFileObjectFromSectionPtrs
    import CcGetLsnForFileObject
    import CcInitializeCacheMap
    import CcIsThereDirtyData
    import CcMapData
    import CcMdlRead
    import CcMdlReadComplete
    import CcMdlWriteComplete
    import CcPinMappedData
    import CcPinRead
    import CcPrepareMdlWrite
    import CcPreparePinWrite
    import CcPurgeCacheSection
    import CcRepinBcb
    import CcScheduleReadAhead
    import CcSetAdditionalCacheAttributes
    import CcSetBcbOwnerPointer
    import CcSetDirtyPageThreshold
    import CcSetDirtyPinnedData
    import CcSetFileSizes
    import CcSetLogHandleForFile
    import CcSetReadAheadGranularity
    import CcUninitializeCacheMap
    import CcUnpinData
    import CcUnpinDataForThread
    import CcUnpinRepinnedBcb
    import CcZeroData
    import DbgBreakPoint
    import DbgBreakPointWithStatus
    import DbgLoadImageSymbols
    import DbgPrint
    import DbgPrompt
    import ExAcquireFastMutexUnsafe
    import ExAcquireResourceExclusiveLite
    import ExAcquireResourceSharedLite
    import ExAcquireSharedStarveExclusive
    import ExAcquireSharedWaitForExclusive
    import ExAllocatePool
    import ExAllocatePoolWithQuota
    import ExAllocatePoolWithQuotaTag
    import ExAllocatePoolWithTag
    import ExAllocatePoolWithTagPriority
    import ExConvertExclusiveToSharedLite
    import ExCreateCallback
    import ExDeleteNPagedLookasideList
    import ExDeletePagedLookasideList
    import ExDeleteResourceLite
    import ExDisableResourceBoostLite
    import ExEnumHandleTable
    import ExExtendZone
    import ExFreePool
    #if NTDDI_VERSION >= NTDDI_WIN2K
        #if NTDDI_VERSION < NTDDI_WIN8
            #ifndef APP_WIN64
                import KeQueryInterruptTime
            #endif
        #endif
    #endif
    #if NTDDI_VERSION < NTDDI_VISTA
        import KeConnectInterrupt
        import KeDisconnectInterrupt
    #else
        #if NTDDI_VERSION < NTDDI_WIN7
            #ifndef APP_WIN64
                import Exfi386InterlockedDecrementLong
                import Exfi386InterlockedExchangeUlong
                import Exfi386InterlockedIncrementLong
                import ExfInterlockedAddUlong
                #if NTDDI_VERSION >= NTDDI_WINXP
                    import ExfInterlockedCompareExchange64
                #endif
                import ExfInterlockedInsertHeadList
                import ExfInterlockedInsertTailList
                import ExfInterlockedPopEntryList
                import ExfInterlockedPushEntryList
                import ExfInterlockedRemoveHeadList
                import ExInterlockedAddLargeStatistic
                import ExInterlockedCompareExchange64
                import ExInterlockedFlushSList
                import ExInterlockedPopEntrySList
                import ExInterlockedPushEntrySList
                #if NTDDI_VERSION == NTDDI_VISTA
                    import ExiReleaseFastMutex
                    import ExiTryToAcquireFastMutex
                #endif
                import InterlockedCompareExchange
                import InterlockedDecrement
                import InterlockedExchange
                import InterlockedExchangeAdd
                import InterlockedIncrement
                import InterlockedPopEntrySList
                import InterlockedPushEntrySList
                import KefAcquireSpinLockAtDpcLevel
                import KefReleaseSpinLockFromDpcLevel
                import KeTerminateThread
                import KiAcquireSpinLock
                import Kii386SpinOnSpinLock
                import KiReleaseSpinLock
                import RtlUlongByteSwap
                import RtlUlonglongByteSwap
                import RtlUshortByteSwap
            #endif
            import IoPnPDeliverServicePowerNotification
        #else
            #if NTDDI_VERSION <= NTDDI_WIN7
                #ifndef APP_WIN64
                    import RtlConvertLongToLargeInteger
                    import RtlConvertUlongToLargeInteger
                    import RtlEnlargedIntegerMultiply
                    import RtlEnlargedUnsignedDivide
                    import RtlEnlargedUnsignedMultiply
                    import RtlExtendedIntegerMultiply
                    import RtlExtendedLargeIntegerDivide
                    import RtlExtendedMagicDivide
                    import RtlFillMemoryUlong
                    import RtlLargeIntegerArithmeticShift
                    import RtlLargeIntegerDivide
                    import RtlLargeIntegerNegate
                    import RtlLargeIntegerShiftLeft
                    import RtlLargeIntegerShiftRight
                    import RtlLargeIntegerSubtract
                #endif
            #else
                #if NTDDI_VERSION >= NTDDI_WIN7
                    #if NTDDI_VERSION < NTDDI_WIN8
                        #ifdef APP_WIN64
                            import IoSetOplockKeyContext
                        #else
                            import ExFreeToPagedLookasideList
                            import Exi386InterlockedDecrementLong
                            import Exi386InterlockedExchangeUlong
                            import Exi386InterlockedIncrementLong
                            import ExInterlockedDecrementLong
                            import ExInterlockedExchangeUlong
                            import ExInterlockedIncrementLong
                            import Ke386CallBios
                            import Ke386IoSetAccessProcess
                            import Ke386QueryIoAccessMap
                            import Ke386SetIoAccessMap
                            import KeGetPreviousMode
                            import KeI386AbiosCall
                            import KeI386AllocateGdtSelectors
                            import KeI386Call16BitFunction
                            import KeI386FlatToGdtSelector
                            import KeI386GetLid
                            import KeI386ReleaseGdtSelectors
                            import KeI386ReleaseLid
                            import KeI386SetGdtSelector
                            import KeProfileInterrupt
                            import KeQuerySystemTime
                            import KeQueryTickCount
                            import KiCoprocessorError
                            import KiDeliverApc
                            import KiIpiServiceRoutine
                            import READ_REGISTER_BUFFER_UCHAR
                            import READ_REGISTER_BUFFER_ULONG
                            import READ_REGISTER_BUFFER_USHORT
                            import READ_REGISTER_UCHAR
                            import READ_REGISTER_ULONG
                            import READ_REGISTER_USHORT
                        #endif
                    #endif
                #endif
            #endif
        #endif
    #endif
    import ExGetExclusiveWaiterCount
    import ExGetPreviousMode
    import ExGetSharedWaiterCount
    import ExInitializeNPagedLookasideList
    import ExInitializePagedLookasideList
    import ExInitializeResourceLite
    import ExInitializeZone
    import ExInterlockedAddLargeInteger
    import ExInterlockedAddUlong
    import ExInterlockedExtendZone
    import ExInterlockedInsertHeadList
    import ExInterlockedInsertTailList
    import ExInterlockedPopEntryList
    import ExInterlockedPushEntryList
    import ExInterlockedRemoveHeadList
    import ExIsProcessorFeaturePresent
    import ExIsResourceAcquiredExclusiveLite
    import ExIsResourceAcquiredSharedLite
    import ExLocalTimeToSystemTime
    import ExNotifyCallback
    import ExQueryPoolBlockSize
    import ExQueueWorkItem
    import ExRaiseAccessViolation
    import ExRaiseDatatypeMisalignment
    import ExRaiseException
    import ExRaiseHardError
    import ExRaiseStatus
    import ExRegisterCallback
    import ExReinitializeResourceLite
    import ExReleaseFastMutexUnsafe
    import ExReleaseResourceForThreadLite
    import ExReleaseResourceLite
    import ExSetResourceOwnerPointer
    import ExSystemExceptionFilter
    import ExSystemTimeToLocalTime
    import ExUnregisterCallback
    import FsRtlAddLargeMcbEntry
    import FsRtlAddMcbEntry
    import FsRtlAddToTunnelCache
    import FsRtlAllocatePool
    import FsRtlAllocatePoolWithQuota
    import FsRtlAllocatePoolWithQuotaTag
    import FsRtlAllocatePoolWithTag
    import FsRtlAllocateResource
    import FsRtlAreNamesEqual
    import FsRtlBalanceReads
    import FsRtlCheckLockForReadAccess
    import FsRtlCheckLockForWriteAccess
    import FsRtlCheckOplock
    import FsRtlCopyRead
    import FsRtlCopyWrite
    import FsRtlCurrentBatchOplock
    import FsRtlDeleteKeyFromTunnelCache
    import FsRtlDeleteTunnelCache
    import FsRtlDeregisterUncProvider
    import FsRtlDissectDbcs
    import FsRtlDissectName
    import FsRtlDoesDbcsContainWildCards
    import FsRtlDoesNameContainWildCards
    import FsRtlFastCheckLockForRead
    import FsRtlFastCheckLockForWrite
    import FsRtlFastUnlockAll
    import FsRtlFastUnlockAllByKey
    import FsRtlFastUnlockSingle
    import FsRtlFindInTunnelCache
    import FsRtlGetFileSize
    import FsRtlGetNextFileLock
    import FsRtlGetNextLargeMcbEntry
    import FsRtlGetNextMcbEntry
    import FsRtlInitializeFileLock
    import FsRtlInitializeLargeMcb
    import FsRtlInitializeMcb
    import FsRtlInitializeOplock
    import FsRtlInitializeTunnelCache
    import FsRtlIsDbcsInExpression
    import FsRtlIsFatDbcsLegal
    import FsRtlIsHpfsDbcsLegal
    import FsRtlIsNameInExpression
    import FsRtlIsNtstatusExpected
    import FsRtlIsTotalDeviceFailure
    import FsRtlLookupLargeMcbEntry
    import FsRtlLookupLastLargeMcbEntry
    import FsRtlLookupLastMcbEntry
    import FsRtlLookupMcbEntry
    import FsRtlMdlRead
    import FsRtlMdlReadComplete
    import FsRtlMdlReadCompleteDev
    import FsRtlMdlReadDev
    import FsRtlMdlWriteComplete
    import FsRtlMdlWriteCompleteDev
    import FsRtlNormalizeNtstatus
    import FsRtlNotifyChangeDirectory
    import FsRtlNotifyCleanup
    import FsRtlNotifyFullChangeDirectory
    import FsRtlNotifyFullReportChange
    import FsRtlNotifyInitializeSync
    import FsRtlNotifyReportChange
    import FsRtlNotifyUninitializeSync
    import FsRtlNumberOfRunsInLargeMcb
    import FsRtlNumberOfRunsInMcb
    import FsRtlOplockFsctrl
    import FsRtlOplockIsFastIoPossible
    import FsRtlPostPagingFileStackOverflow
    import FsRtlPostStackOverflow
    import FsRtlPrepareMdlWrite
    import FsRtlPrepareMdlWriteDev
    import FsRtlPrivateLock
    import FsRtlProcessFileLock
    import FsRtlRegisterUncProvider
    import FsRtlRemoveLargeMcbEntry
    import FsRtlRemoveMcbEntry
    import FsRtlSplitLargeMcb
    import FsRtlSyncVolumes
    import FsRtlTruncateLargeMcb
    import FsRtlTruncateMcb
    import FsRtlUninitializeFileLock
    import FsRtlUninitializeLargeMcb
    import FsRtlUninitializeMcb
    import FsRtlUninitializeOplock
    import IoAcquireVpbSpinLock
    import IoAllocateAdapterChannel
    import IoAllocateController
    import IoAllocateErrorLogEntry
    import IoAllocateIrp
    import IoAllocateMdl
    import IoAssignResources
    import IoAttachDevice
    import IoAttachDeviceByPointer
    import IoAttachDeviceToDeviceStack
    import IoBuildAsynchronousFsdRequest
    import IoBuildDeviceIoControlRequest
    import IoBuildPartialMdl
    import IoBuildSynchronousFsdRequest
    import IoCallDriver
    import IoCancelIrp
    import IoCheckDesiredAccess
    import IoCheckEaBufferValidity
    import IoCheckFunctionAccess
    import IoCheckShareAccess
    import IoCompleteRequest
    import IoConnectInterrupt
    import IoCreateController
    import IoCreateDevice
    import IoCreateFile
    import IoCreateNotificationEvent
    import IoCreateStreamFileObject
    import IoCreateSymbolicLink
    import IoCreateSynchronizationEvent
    import IoCreateUnprotectedSymbolicLink
    import IoDeleteController
    import IoDeleteDevice
    import IoDeleteSymbolicLink
    import IoDetachDevice
    import IoDisconnectInterrupt
    import IoEnqueueIrp
    import IoFastQueryNetworkAttributes
    import IofCallDriver
    import IofCompleteRequest
    import IoFreeController
    import IoFreeIrp
    import IoFreeMdl
    import IoGetAttachedDevice
    import IoGetBaseFileSystemDeviceObject
    import IoGetConfigurationInformation
    import IoGetCurrentProcess
    import IoGetDeviceObjectPointer
    import IoGetDeviceToVerify
    import IoGetFileObjectGenericMapping
    import IoGetInitialStack
    import IoGetRelatedDeviceObject
    import IoGetRequestorProcess
    import IoGetStackLimits
    import IoGetTopLevelIrp
    import IoInitializeIrp
    import IoInitializeTimer
    import IoIsOperationSynchronous
    import IoIsSystemThread
    import IoMakeAssociatedIrp
    import IoPageRead
    import IoQueryDeviceDescription
    import IoQueryFileInformation
    import IoQueryVolumeInformation
    import IoQueueThreadIrp
    import IoRaiseHardError
    import IoRaiseInformationalHardError
    import IoRegisterDriverReinitialization
    import IoRegisterFileSystem
    import IoRegisterFsRegistrationChange
    import IoRegisterShutdownNotification
    import IoReleaseCancelSpinLock
    import IoReleaseVpbSpinLock
    import IoRemoveShareAccess
    import IoReportHalResourceUsage
    import IoReportResourceUsage
    import IoSetDeviceToVerify
    import IoSetHardErrorOrVerifyDevice
    import IoSetInformation
    import IoSetShareAccess
    import IoSetThreadHardErrorMode
    import IoSetTopLevelIrp
    import IoStartNextPacket
    import IoStartNextPacketByKey
    import IoStartPacket
    import IoStartTimer
    import IoStopTimer
    import IoSynchronousPageWrite
    import IoThreadToProcess
    import IoUnregisterFileSystem
    import IoUnregisterFsRegistrationChange
    import IoUnregisterShutdownNotification
    import IoUpdateShareAccess
    import IoVerifyVolume
    import IoWriteErrorLogEntry
    import isdigit
    import islower
    import isprint
    import isspace
    import isupper
    import isxdigit
    import KdPollBreakIn
    import KeAcquireSpinLockAtDpcLevel
    import KeAddSystemServiceTable
    import KeAttachProcess
    import KeBugCheck
    import KeBugCheckEx
    import KeCancelTimer
    import KeClearEvent
    import KeDelayExecutionThread
    import KeDeregisterBugCheckCallback
    import KeDetachProcess
    import KeEnterCriticalRegion
    import KeEnterKernelDebugger
    import KeFindConfigurationEntry
    import KeFindConfigurationNextEntry
    import KeFlushEntireTb
    import KeGetCurrentThread
    import KeInitializeApc
    import KeInitializeDeviceQueue
    import KeInitializeDpc
    import KeInitializeEvent
    import KeInitializeInterrupt
    import KeInitializeMutant
    import KeInitializeMutex
    import KeInitializeQueue
    import KeInitializeSemaphore
    import KeInitializeSpinLock
    import KeInitializeTimer
    import KeInitializeTimerEx
    import KeInsertByKeyDeviceQueue
    import KeInsertDeviceQueue
    import KeInsertHeadQueue
    import KeInsertQueue
    import KeInsertQueueApc
    import KeInsertQueueDpc
    import KeIsExecutingDpc
    import KeLeaveCriticalRegion
    import KeProfileInterruptWithSource
    import KePulseEvent
    import KeQueryTimeIncrement
    import KeRaiseUserException
    import KeReadStateEvent
    import KeReadStateMutant
    import KeReadStateMutex
    import KeReadStateQueue
    import KeReadStateSemaphore
    import KeReadStateTimer
    import KeRegisterBugCheckCallback
    import KeReleaseMutant
    import KeReleaseMutex
    import KeReleaseSemaphore
    import KeReleaseSpinLockFromDpcLevel
    import KeRemoveByKeyDeviceQueue
    import KeRemoveDeviceQueue
    import KeRemoveEntryDeviceQueue
    import KeRemoveQueue
    import KeRemoveQueueDpc
    import KeResetEvent
    import KeRestoreFloatingPointState
    import KeRundownQueue
    import KeSaveFloatingPointState
    import KeSetAffinityThread
    import KeSetBasePriorityThread
    import KeSetDmaIoCoherency
    import KeSetEvent
    import KeSetEventBoostPriority
    import KeSetIdealProcessorThread
    import KeSetImportanceDpc
    import KeSetKernelStackSwapEnable
    import KeSetPriorityThread
    import KeSetProfileIrql
    import KeSetTargetProcessorDpc
    import KeSetTimeIncrement
    import KeSetTimer
    import KeSetTimerEx
    import KeSynchronizeExecution
    import KeUpdateRunTime
    import KeUserModeCallback
    import KeWaitForMultipleObjects
    import KeWaitForMutexObject
    import KeWaitForSingleObject
    import LdrAccessResource
    import LdrEnumResources
    import LdrFindResource_U
    import LdrFindResourceDirectory_U
    import LpcRequestPort
    import LsaCallAuthenticationPackage
    import LsaDeregisterLogonProcess
    import LsaFreeReturnBuffer
    import LsaLogonUser
    import LsaLookupAuthenticationPackage
    import LsaRegisterLogonProcess
    import mbstowcs
    import mbtowc
    import memchr
    import memcpy
    import memmove
    import memset
    import MmAdjustWorkingSetSize
    import MmAllocateContiguousMemory
    import MmAllocateNonCachedMemory
    import MmBuildMdlForNonPagedPool
    import MmCanFileBeTruncated
    import MmCreateMdl
    import MmCreateSection
    import MmDisableModifiedWriteOfSection
    import MmFlushImageSection
    import MmForceSectionClosed
    import MmFreeContiguousMemory
    import MmFreeNonCachedMemory
    import MmGetPhysicalAddress
    import MmGrowKernelStack
    import MmIsAddressValid
    import MmIsNonPagedSystemAddressValid
    import MmIsRecursiveIoFault
    import MmIsThisAnNtAsSystem
    import MmLockPagableDataSection
    import MmLockPagableImageSection
    import MmLockPagableSectionByHandle
    import MmMapIoSpace
    import MmMapLockedPages
    import MmMapLockedPagesSpecifyCache
    import MmMapMemoryDumpMdl
    import MmMapVideoDisplay
    import MmMapViewInSystemSpace
    import MmMapViewOfSection
    import MmPageEntireDriver
    import MmProbeAndLockPages
    import MmQuerySystemSize
    import MmResetDriverPaging
    import MmSecureVirtualMemory
    import MmSetAddressRangeModified
    import MmSetBankedSection
    import MmSizeOfMdl
    import MmUnlockPagableImageSection
    import MmUnlockPages
    import MmUnmapIoSpace
    import MmUnmapLockedPages
    import MmUnmapVideoDisplay
    import MmUnmapViewInSystemSpace
    import MmUnmapViewOfSection
    import MmUnsecureVirtualMemory
    import NlsOemLeadByteInfo
    import NtAddAtom
    import NtAdjustPrivilegesToken
    import NtAllocateLocallyUniqueId
    import NtAllocateUuids
    import NtAllocateVirtualMemory
    import NtClose
    import NtConnectPort
    import NtCreateEvent
    import NtCreateFile
    import NtCreateSection
    import NtDeleteAtom
    import NtDeleteFile
    import NtDeviceIoControlFile
    import NtDuplicateObject
    import NtDuplicateToken
    import NtFindAtom
    import NtFreeVirtualMemory
    import NtFsControlFile
    import NtLockFile
    import NtMapViewOfSection
    import NtNotifyChangeDirectoryFile
    import NtOpenFile
    import NtOpenProcess
    import NtOpenProcessToken
    import NtQueryDirectoryFile
    import NtQueryEaFile
    import NtQueryInformationAtom
    import NtQueryInformationFile
    import NtQueryInformationProcess
    import NtQueryInformationToken
    import NtQuerySecurityObject
    import NtQueryVolumeInformationFile
    import NtReadFile
    import NtRequestPort
    import NtRequestWaitReplyPort
    import NtSetEvent
    import NtSetInformationFile
    import NtSetInformationProcess
    import NtSetInformationThread
    import NtSetQuotaInformationFile
    import NtSetSecurityObject
    import NtUnlockFile
    import NtVdmControl
    import NtWaitForSingleObject
    import NtWriteFile
    import ObAssignSecurity
    import ObCheckCreateObjectAccess
    import ObCheckObjectAccess
    import ObCreateObject
    import ObDereferenceObject
    import ObfDereferenceObject
    import ObFindHandleForObject
    import ObfReferenceObject
    import ObGetObjectSecurity
    import ObInsertObject
    import ObMakeTemporaryObject
    import ObOpenObjectByName
    import ObOpenObjectByPointer
    import ObQueryNameString
    import ObQueryObjectAuditingByHandle
    import ObReferenceObjectByHandle
    import ObReferenceObjectByName
    import ObReferenceObjectByPointer
    import ObReleaseObjectSecurity
    import ObSetSecurityDescriptorInfo
    import PfxFindPrefix
    import PfxInitialize
    import PfxInsertPrefix
    import PfxRemovePrefix
    import ProbeForWrite
    import PsAssignImpersonationToken
    import PsChargePoolQuota
    import PsCreateSystemThread
    import PsEstablishWin32Callouts
    import PsGetCurrentProcessId
    import PsGetCurrentThreadId
    import PsGetProcessExitTime
    import PsGetVersion
    import PsImpersonateClient
    import PsIsThreadTerminating
    import PsLookupProcessByProcessId
    import PsLookupProcessThreadByCid
    import PsLookupThreadByThreadId
    import PsProcessType
    import PsReferenceImpersonationToken
    import PsReferencePrimaryToken
    import PsReturnPoolQuota
    import PsRevertToSelf
    import PsSetCreateProcessNotifyRoutine
    import PsSetCreateThreadNotifyRoutine
    import PsSetLegoNotifyRoutine
    import PsSetProcessPriorityByClass
    import PsTerminateSystemThread
    import PsThreadType
    import qsort
    import rand
    import RtlAbsoluteToSelfRelativeSD
    import RtlAddAccessAllowedAce
    import RtlAddAce
    import RtlAddAtomToAtomTable
    import RtlAllocateHeap
    import RtlAnsiCharToUnicodeChar
    import RtlAnsiStringToUnicodeSize
    import RtlAnsiStringToUnicodeString
    import RtlAppendAsciizToString
    import RtlAppendStringToString
    import RtlAppendUnicodeStringToString
    import RtlAppendUnicodeToString
    import RtlAreAllAccessesGranted
    import RtlAreAnyAccessesGranted
    import RtlAreBitsClear
    import RtlAreBitsSet
    import RtlAssert
    import RtlCaptureStackBackTrace
    import RtlCharToInteger
    import RtlCheckRegistryKey
    import RtlClearAllBits
    import RtlClearBits
    import RtlCompareMemory
    import RtlCompareMemoryUlong
    import RtlCompareString
    import RtlCompareUnicodeString
    import RtlCompressBuffer
    import RtlCompressChunks
    import RtlConvertSidToUnicodeString
    import RtlCopyLuid
    import RtlCopyMemory
    import RtlCopySid
    import RtlCopyString
    import RtlCopyUnicodeString
    import RtlCreateAcl
    import RtlCreateAtomTable
    import RtlCreateHeap
    import RtlCreateRegistryKey
    import RtlCreateSecurityDescriptor
    import RtlCreateUnicodeString
    import RtlCustomCPToUnicodeN
    import RtlDecompressBuffer
    import RtlDecompressChunks
    import RtlDecompressFragment
    import RtlDelete
    import RtlDeleteAtomFromAtomTable
    import RtlDeleteElementGenericTable
    import RtlDeleteNoSplay
    import RtlDeleteRegistryValue
    import RtlDescribeChunk
    import RtlDestroyAtomTable
    import RtlDestroyHeap
    import RtlDowncaseUnicodeString
    import RtlEmptyAtomTable
    import RtlEnumerateGenericTable
    import RtlEnumerateGenericTableWithoutSplaying
    import RtlEqualLuid
    import RtlEqualSid
    import RtlEqualString
    import RtlEqualUnicodeString
    import RtlFillMemory
    import RtlFindClearBits
    import RtlFindClearBitsAndSet
    import RtlFindFirstRunClear
    import RtlFindLongestRunClear
    import RtlFindMessage
    import RtlFindSetBits
    import RtlFindSetBitsAndClear
    import RtlFindUnicodePrefix
    import RtlFormatCurrentUserKeyPath
    import RtlFreeAnsiString
    import RtlFreeHeap
    import RtlFreeOemString
    import RtlFreeUnicodeString
    import RtlGenerate8dot3Name
    import RtlGetCallersAddress
    import RtlGetCompressionWorkSpaceSize
    import RtlGetDaclSecurityDescriptor
    import RtlGetDefaultCodePage
    import RtlGetElementGenericTable
    import RtlGetGroupSecurityDescriptor
    import RtlGetOwnerSecurityDescriptor
    import RtlImageNtHeader
    import RtlInitAnsiString
    import RtlInitCodePageTable
    import RtlInitializeBitMap
    import RtlInitializeGenericTable
    import RtlInitializeSid
    import RtlInitializeUnicodePrefix
    import RtlInitString
    import RtlInitUnicodeString
    import RtlInsertElementGenericTable
    import RtlInsertUnicodePrefix
    import RtlIntegerToChar
    import RtlIntegerToUnicodeString
    import RtlIsNameLegalDOS8Dot3
    import RtlLengthRequiredSid
    import RtlLengthSecurityDescriptor
    import RtlLengthSid
    import RtlLookupAtomInAtomTable
    import RtlLookupElementGenericTable
    import RtlMapGenericMask
    import RtlMoveMemory
    import RtlMultiByteToUnicodeN
    import RtlMultiByteToUnicodeSize
    import RtlNextUnicodePrefix
    import RtlNtStatusToDosError
    import RtlNtStatusToDosErrorNoTeb
    import RtlNumberGenericTableElements
    import RtlNumberOfClearBits
    import RtlNumberOfSetBits
    import RtlOemStringToCountedUnicodeString
    import RtlOemStringToUnicodeSize
    import RtlOemStringToUnicodeString
    import RtlOemToUnicodeN
    import RtlPinAtomInAtomTable
    import RtlPrefixString
    import RtlPrefixUnicodeString
    import RtlQueryAtomInAtomTable
    import RtlQueryRegistryValues
    import RtlQueryTimeZoneInformation
    import RtlRaiseException
    import RtlRandom
    import RtlRemoveUnicodePrefix
    import RtlReserveChunk
    import RtlSecondsSince1970ToTime
    import RtlSecondsSince1980ToTime
    import RtlSetAllBits
    import RtlSetBits
    import RtlSetDaclSecurityDescriptor
    import RtlSetGroupSecurityDescriptor
    import RtlSetOwnerSecurityDescriptor
    import RtlSetSaclSecurityDescriptor
    import RtlSetTimeZoneInformation
    import RtlSplay
    import RtlSubAuthorityCountSid
    import RtlSubAuthoritySid
    import RtlTimeFieldsToTime
    import RtlTimeToSecondsSince1970
    import RtlTimeToSecondsSince1980
    import RtlTimeToTimeFields
    import RtlUnicodeStringToAnsiSize
    import RtlUnicodeStringToAnsiString
    import RtlUnicodeStringToCountedOemString
    import RtlUnicodeStringToInteger
    import RtlUnicodeStringToOemSize
    import RtlUnicodeStringToOemString
    import RtlUnicodeToCustomCPN
    import RtlUnicodeToMultiByteN
    import RtlUnicodeToMultiByteSize
    import RtlUnicodeToOemN
    import RtlUnwind
    import RtlUnwindEx
    import RtlUpcaseUnicodeChar
    import RtlUpcaseUnicodeString
    import RtlUpcaseUnicodeStringToAnsiString
    import RtlUpcaseUnicodeStringToCountedOemString
    import RtlUpcaseUnicodeStringToOemString
    import RtlUpcaseUnicodeToCustomCPN
    import RtlUpcaseUnicodeToMultiByteN
    import RtlUpcaseUnicodeToOemN
    import RtlUpperChar
    import RtlUpperString
    import RtlValidSecurityDescriptor
    import RtlValidSid
    import RtlWriteRegistryValue
    import RtlxAnsiStringToUnicodeSize
    import RtlxOemStringToUnicodeSize
    import RtlxUnicodeStringToAnsiSize
    import RtlxUnicodeStringToOemSize
    import RtlZeroHeap
    import RtlZeroMemory
    import SeAccessCheck
    import SeAppendPrivileges
    import SeAssignSecurity
    import SeAuditingFileEvents
    import SeAuditingFileOrGlobalEvents
    import SeCaptureSecurityDescriptor
    import SeCaptureSubjectContext
    import SeCloseObjectAuditAlarm
    import SeCreateAccessState
    import SeCreateClientSecurity
    import SeDeassignSecurity
    import SeDeleteAccessState
    import SeDeleteObjectAuditAlarm
    import SeFreePrivileges
    import SeImpersonateClient
    import SeLockSubjectContext
    import SeMarkLogonSessionForTerminationNotification
    import SeOpenObjectAuditAlarm
    import SeOpenObjectForDeleteAuditAlarm
    import SePrivilegeCheck
    import SePrivilegeObjectAuditAlarm
    import SeQueryAuthenticationIdToken
    import SeQuerySecurityDescriptorInfo
    import SeRegisterLogonSessionTerminatedRoutine
    import SeReleaseSecurityDescriptor
    import SeReleaseSubjectContext
    import SeSetAccessStateGenericMapping
    import SeSetSecurityDescriptorInfo
    import SeSinglePrivilegeCheck
    import SeTokenImpersonationLevel
    import SeTokenType
    import SeUnlockSubjectContext
    import SeUnregisterLogonSessionTerminatedRoutine
    import SeValidSecurityDescriptor
    import tolower
    import toupper
    import towlower
    import towupper
    import vsprintf
    import wcscat
    import wcschr
    import wcscmp
    import wcscpy
    import wcscspn
    import wcslen
    import wcsncat
    import wcsncmp
    import wcsncpy
    import wcsrchr
    import wcsspn
    import wcsstr
    import wcstombs
    import wctomb
    import ZwAccessCheckAndAuditAlarm
    import ZwAlertThread
    import ZwAllocateVirtualMemory
    import ZwClearEvent
    import ZwClose
    import ZwCloseObjectAuditAlarm
    import ZwConnectPort
    import ZwCreateDirectoryObject
    import ZwCreateEvent
    import ZwCreateFile
    import ZwCreateKey
    import ZwCreateSection
    import ZwCreateSymbolicLinkObject
    import ZwDeleteFile
    import ZwDeleteKey
    import ZwDeleteValueKey
    import ZwDeviceIoControlFile
    import ZwDisplayString
    import ZwDuplicateObject
    import ZwDuplicateToken
    import ZwEnumerateKey
    import ZwEnumerateValueKey
    import ZwFlushInstructionCache
    import ZwFlushKey
    import ZwFreeVirtualMemory
    import ZwFsControlFile
    import ZwLoadDriver
    import ZwLoadKey
    import ZwMakeTemporaryObject
    import ZwMapViewOfSection
    import ZwNotifyChangeKey
    import ZwOpenDirectoryObject
    import ZwOpenEvent
    import ZwOpenFile
    import ZwOpenKey
    import ZwOpenProcess
    import ZwOpenProcessToken
    import ZwOpenSection
    import ZwOpenSymbolicLinkObject
    import ZwOpenThread
    import ZwOpenThreadToken
    import ZwPulseEvent
    import ZwQueryDefaultLocale
    import ZwQueryDirectoryFile
    import ZwQueryInformationFile
    import ZwQueryInformationProcess
    import ZwQueryInformationToken
    import ZwQueryKey
    import ZwQueryObject
    import ZwQuerySection
    import ZwQuerySecurityObject
    import ZwQuerySymbolicLinkObject
    import ZwQuerySystemInformation
    import ZwQueryValueKey
    import ZwQueryVolumeInformationFile
    import ZwReadFile
    import ZwReplaceKey
    import ZwRequestWaitReplyPort
    import ZwResetEvent
    import ZwSaveKey
    import ZwSetDefaultLocale
    import ZwSetEvent
    import ZwSetInformationFile
    import ZwSetInformationObject
    import ZwSetInformationProcess
    import ZwSetInformationThread
    import ZwSetSystemInformation
    import ZwSetSystemTime
    import ZwSetValueKey
    import ZwTerminateProcess
    import ZwUnloadDriver
    import ZwUnloadKey
    import ZwUnmapViewOfSection
    import ZwWaitForMultipleObjects
    import ZwWaitForSingleObject
    import ZwWriteFile
    import ZwYieldExecution
    #ifndef __C_specific_handler
        import __C_specific_handler
    #endif
    #ifndef __chkstk
        import __chkstk
    #endif
    import _itoa
    import _purecall
    import _snprintf
    import _stricmp
    import _strlwr
    import _strnicmp
    import _strnset
    import _strrev
    import _strset
    import _strupr
    import _vsnprintf
    import _wcsicmp
    import _wcslwr
    import _wcsnicmp
    import _wcsnset
    import _wcsrev
    import _wcsupr

    #if NTDDI_VERSION >= NTDDI_WIN2K
        import CcGetFlushedValidData
        import CcRemapBcb
        import CcWaitForCurrentLazyWriterActivity
        import ExFreePoolWithTag
        import ExSetTimerResolution
        import ExUuidCreate
        import FsRtlAllocateFileLock
        import FsRtlCreateSectionForDataScan
        import FsRtlFreeFileLock
        import FsRtlInsertPerFileObjectContext
        import FsRtlInsertPerStreamContext
        import FsRtlIsPagingFile
        import FsRtlLookupLastLargeMcbEntryAndIndex
        import FsRtlLookupPerFileObjectContext
        import FsRtlLookupPerStreamContextInternal
        import FsRtlNotifyFilterChangeDirectory
        import FsRtlNotifyFilterReportChange
        import FsRtlNotifyVolumeEvent
        import FsRtlRegisterFileSystemFilterCallbacks
        import FsRtlReleaseFile
        import FsRtlRemovePerFileObjectContext
        import FsRtlRemovePerStreamContext
        import FsRtlResetBaseMcb
        import FsRtlResetLargeMcb
        import FsRtlTeardownPerStreamContexts
        import InbvAcquireDisplayOwnership
        import InbvCheckDisplayOwnership
        import InbvDisplayString
        import InbvEnableBootDriver
        import InbvEnableDisplayString
        import InbvInstallDisplayStringFilter
        import InbvIsBootDriverInstalled
        import InbvNotifyDisplayOwnershipLost
        import InbvResetDisplay
        import InbvSetScrollRegion
        import InbvSetTextColor
        import InbvSolidColorFill
        import IoAcquireCancelSpinLock
        import IoAcquireRemoveLockEx
        import IoAllocateDriverObjectExtension
        import IoAllocateWorkItem
        import IoAttachDeviceToDeviceStackSafe
        import IoCancelFileOpen
        import IoCheckQuerySetFileInformation
        import IoCheckQuerySetVolumeInformation
        import IoCheckQuotaBufferValidity
        import IoCreateDriver
        import IoCreateFileSpecifyDeviceObjectHint
        import IoCreateStreamFileObjectLite
        import IoDeleteDriver
        import IoEnumerateDeviceObjectList
        import IoEnumerateRegisteredFiltersList
        import IoFreeWorkItem
        import IoGetAttachedDeviceReference
        import IoGetBootDiskInformation
        import IoGetDeviceAttachmentBaseRef
        import IoGetDeviceInterfaceAlias
        import IoGetDeviceInterfaces
        import IoGetDeviceProperty
        import IoGetDiskDeviceObject
        import IoGetDmaAdapter
        import IoGetDriverObjectExtension
        import IoGetLowerDeviceObject
        import IoGetRequestorProcessId
        import IoGetRequestorSessionId
        import IoInitializeRemoveLockEx
        import IoInvalidateDeviceRelations
        import IoInvalidateDeviceState
        import IoIsFileOriginRemote
        import IoIsValidNameGraftingBuffer
        import IoIsWdmVersionAvailable
        import IoOpenDeviceInterfaceRegistryKey
        import IoOpenDeviceRegistryKey
        import IoQueueWorkItem
        import IoRegisterBootDriverReinitialization
        import IoRegisterDeviceInterface
        import IoRegisterLastChanceShutdownNotification
        import IoRegisterPlugPlayNotification
        import IoReleaseRemoveLockAndWaitEx
        import IoReleaseRemoveLockEx
        import IoReportDetectedDevice
        import IoReportResourceForDetection
        import IoReportTargetDeviceChange
        import IoReportTargetDeviceChangeAsynchronous
        import IoRequestDeviceEject
        import IoReuseIrp
        import IoSetDeviceInterfaceState
        import IoSetFileOrigin
        import IoSetIoCompletion
        import IoSynchronousInvalidateDeviceRelations
        import IoUnregisterPlugPlayNotification
        import IoVolumeDeviceToDosName
        import IoWMIAllocateInstanceIds
        import IoWMIRegistrationControl
        import IoWMISuggestInstanceName
        import IoWMIWriteEvent
        import KdDisableDebugger
        import KdEnableDebugger
        import KeQueryActiveProcessors
        import KeQueryPriorityThread
        import KeSaveStateForHibernate
        import KeSetSystemAffinityThread
        import KeStackAttachProcess
        import KeUnstackDetachProcess
        import LpcRequestWaitReplyPort
        import MmAddPhysicalMemory
        import MmAddVerifierThunks
        import MmAllocateContiguousMemorySpecifyCache
        import MmAllocateMappingAddress
        import MmAllocatePagesForMdl
        import MmCommitSessionMappedView
        import MmFreeContiguousMemorySpecifyCache
        import MmFreeMappingAddress
        import MmFreePagesFromMdl
        import MmGetPhysicalMemoryRanges
        import MmGetSystemRoutineAddress
        import MmGetVirtualForPhysical
        import MmIsDriverVerifying
        import MmIsVerifierEnabled
        import MmMapLockedPagesWithReservedMapping
        import MmMapUserAddressesToPage
        import MmMapViewInSessionSpace
        import MmProbeAndLockProcessPages
        import MmProbeAndLockSelectedPages
        import MmRemovePhysicalMemory
        import MmTrimAllSystemPagableMemory
        import MmUnmapReservedMapping
        import MmUnmapViewInSessionSpace
        import NtQueryQuotaInformationFile
        import NtQuerySystemInformation
        import NtSetEaFile
        import NtSetVolumeInformationFile
        import ObCreateObjectType
        #if NTDDI_VERSION == NTDDI_WINXP
            import WmiTraceFastEvent
        #else
            import ObDeleteCapturedInsertInfo
        #endif
        import PoCallDriver
        import PoCancelDeviceNotify
        import PoRegisterDeviceForIdleDetection
        import PoRegisterDeviceNotify
        import PoRegisterSystemState
        import PoRequestPowerIrp
        import PoSetHiberRange
        import PoSetPowerState
        import PoSetSystemState
        import PoShutdownBugCheck
        import PoStartNextPowerIrp
        import PoUnregisterSystemState
        import ProbeForRead
        import PsDisableImpersonation
        import PsGetProcessId
        import PsGetProcessImageFileName
        import PsRestoreImpersonation
        import PsSetLoadImageNotifyRoutine
        import RtlAddAccessAllowedAceEx
        import RtlAddRange
        import RtlCaptureContext
        import RtlCopyRangeList
        import RtlDeleteAce
        import RtlDeleteOwnersRanges
        import RtlDeleteRange
        import RtlFindClearRuns
        import RtlFindLastBackwardRunClear
        import RtlFindLeastSignificantBit
        import RtlFindMostSignificantBit
        import RtlFindNextForwardRunClear
        import RtlFindRange
        import RtlFreeRangeList
        import RtlGetAce
        import RtlGetFirstRange
        import RtlGetNextRange
        import RtlGetNtGlobalFlags
        import RtlGetSaclSecurityDescriptor
        import RtlGUIDFromString
        import RtlImageDirectoryEntryToData
        import RtlInitializeRangeList
        import RtlInsertElementGenericTableFull
        import RtlInvertRangeList
        import RtlIsGenericTableEmpty
        import RtlIsRangeAvailable
        import RtlIsValidOemCharacter
        import RtlLargeIntegerAdd
        import RtlLookupElementGenericTableFull
        import RtlMergeRangeLists
        import RtlPrefetchMemoryNonTemporal
        import RtlRealPredecessor
        import RtlRealSuccessor
        import RtlSelfRelativeToAbsoluteSD
        import RtlSelfRelativeToAbsoluteSD2
        import RtlSizeHeap
        import RtlStringFromGUID
        import RtlSubtreePredecessor
        import RtlSubtreeSuccessor
        import RtlTraceDatabaseAdd
        import RtlTraceDatabaseCreate
        import RtlTraceDatabaseDestroy
        import RtlTraceDatabaseEnumerate
        import RtlTraceDatabaseFind
        import RtlTraceDatabaseLock
        import RtlTraceDatabaseUnlock
        import RtlTraceDatabaseValidate
        import RtlValidRelativeSecurityDescriptor
        import RtlVolumeDeviceToDosName
        import RtlWalkFrameChain
        import SeAssignSecurityEx
        import SeAuditHardLinkCreation
        import SeAuditingHardLinkEvents
        import SeCreateClientSecurityFromSubjectContext
        import SeImpersonateClientEx
        import SeQueryInformationToken
        import SeQuerySessionIdToken
        import SeSetSecurityDescriptorInfoEx
        import SeTokenIsAdmin
        import SeTokenIsRestricted
        import VerSetConditionMask
        import ZwAdjustPrivilegesToken
        import ZwCancelIoFile
        import ZwCancelTimer
        import ZwCreateTimer
        import ZwFlushVirtualMemory
        import ZwInitiatePowerAction
        import ZwOpenTimer
        import ZwPowerInformation
        import ZwQueryDefaultUILanguage
        import ZwQueryDirectoryObject
        import ZwQueryEaFile
        import ZwQueryInstallUILanguage
        import ZwRestoreKey
        import ZwSetDefaultUILanguage
        import ZwSetEaFile
        import ZwSetSecurityObject
        import ZwSetTimer
        import ZwSetVolumeInformationFile
        import _itow
    #endif

    #if NTDDI_VERSION >= NTDDI_WINXP
        #if NTDDI_VERSION <= NTDDI_VISTA
            #ifdef APP_WIN64
                import _alldiv
                import _alldvrm
                import _allmul
                import _allrem
                import _allshl
                import _allshr
                import _aulldiv
                import _aulldvrm
                import _aullrem
                import _aullshr
                import _except_handler2
                import _except_handler3
                import _global_unwind2
                import _local_unwind2
            #endif
            import IoAssignDriveLetters
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WINXP
        import CcMdlWriteAbort
        import CmRegisterCallback
        import CmUnRegisterCallback
        import DbgPrintEx
        import DbgPrintReturnControlC
        import DbgQueryDebugFilterState
        import DbgSetDebugFilterState
        import ExAcquireRundownProtection
        import ExAcquireRundownProtectionEx
        import ExAllocateFromPagedLookasideList
        import ExfAcquirePushLockExclusive
        import ExfAcquirePushLockShared
        import ExfReleasePushLock
        import ExGetCurrentProcessorCounts
        import ExGetCurrentProcessorCpuUsage
        import ExInitializeRundownProtection
        import ExReInitializeRundownProtection
        import ExReleaseRundownProtection
        import ExReleaseRundownProtectionEx
        import ExRundownCompleted
        import ExVerifySuite
        import ExWaitForRundownProtectionRelease
        import FsRtlAcquireFileExclusive
        import FsRtlIncrementCcFastReadNotPossible
        import FsRtlIncrementCcFastReadNoWait
        import FsRtlIncrementCcFastReadResourceMiss
        import FsRtlIncrementCcFastReadWait
        import HalExamineMBR
        import HeadlessDispatch
        import InitializeSListHead
        import IoCreateDisk
        import IoCreateStreamFileObjectEx
        import IoCsqInitialize
        import IoCsqInsertIrp
        import IoCsqRemoveIrp
        import IoCsqRemoveNextIrp
        import IoForwardAndCatchIrp
        import IoForwardIrpSynchronously
        import IoFreeErrorLogEntry
        import IoQueryFileDosDeviceName
        import IoReadDiskSignature
        import IoReadPartitionTable
        import IoReadPartitionTableEx
        import IoSetCompletionRoutineEx
        import IoSetPartitionInformation
        import IoSetPartitionInformationEx
        import IoSetStartIoAttributes
        import IoSetSystemPartition
        import IoValidateDeviceIoControlAccess
        import IoVerifyPartitionTable
        import IoWMIDeviceObjectToInstanceName
        import IoWMIExecuteMethod
        import IoWMIHandleToInstanceName
        import IoWMIOpenBlock
        import IoWMIQueryAllData
        import IoWMIQueryAllDataMultiple
        import IoWMIQuerySingleInstance
        import IoWMIQuerySingleInstanceMultiple
        import IoWMISetNotificationCallback
        import IoWMISetSingleInstance
        import IoWMISetSingleItem
        import IoWritePartitionTable
        import IoWritePartitionTableEx
        import KdPowerTransition
        import KeAcquireInStackQueuedSpinLockAtDpcLevel
        import KeAcquireInterruptSpinLock
        import KeAreApcsDisabled
        import KeCapturePersistentThreadState
        import KeDeregisterBugCheckReasonCallback
        import KeFlushQueuedDpcs
        import KeGetRecommendedSharedDataAlignment
        import KeIsAttachedProcess
        import KeQueryRuntimeThread
        import KeRegisterBugCheckReasonCallback
        import KeReleaseInterruptSpinLock
        import KeRemoveByKeyDeviceQueueIfBusy
        import KeRemoveSystemServiceTable
        import KeRestoreExtendedProcessorState
        import KeRevertToUserAffinityThreadEx
        import MmAdvanceMdl
        import MmMarkPhysicalMemoryAsBad
        import MmMarkPhysicalMemoryAsGood
        import MmPrefetchPages
        import MmProtectMdlSystemAddress
        import NtMakePermanentObject
        import NtOpenProcessTokenEx
        import NtOpenThread
        import NtOpenThreadToken
        import NtOpenThreadTokenEx
        import NtQueryInformationThread
        import NtShutdownSystem
        import NtTraceEvent
        import ObCloseHandle
        import ObIsDosDeviceLocallyMapped
        import ObLogSecurityDescriptor
        import ObReferenceSecurityDescriptor
        import ObSetHandleAttributes
        import ObSetSecurityObjectByPointer
        import PoRequestShutdownEvent
        import PsChargeProcessNonPagedPoolQuota
        import PsChargeProcessPagedPoolQuota
        import PsChargeProcessPoolQuota
        #if NTDDI_VERSION < NTDDI_VISTA
            import PsCreateSystemProcess
        #endif
        import PsDereferenceImpersonationToken
        import PsDereferencePrimaryToken
        import PsGetContextThread
        import PsGetCurrentProcess
        import PsGetCurrentProcessSessionId
        import PsGetCurrentThread
        import PsGetCurrentThreadPreviousMode
        import PsGetCurrentThreadStackBase
        import PsGetCurrentThreadStackLimit
        import PsGetJobLock
        import PsGetJobSessionId
        import PsGetJobUIRestrictionsClass
        import PsGetProcessCreateTimeQuadPart
        import PsGetProcessDebugPort
        import PsGetProcessExitProcessCalled
        import PsGetProcessExitStatus
        import PsGetProcessInheritedFromUniqueProcessId
        import PsGetProcessJob
        import PsGetProcessPeb
        import PsGetProcessPriorityClass
        import PsGetProcessSectionBaseAddress
        import PsGetProcessSecurityPort
        import PsGetProcessSessionId
        import PsGetProcessWin32Process
        import PsGetProcessWin32WindowStation
        import PsGetThreadFreezeCount
        import PsGetThreadHardErrorsAreDisabled
        import PsGetThreadId
        import PsGetThreadProcess
        import PsGetThreadProcessId
        import PsGetThreadSessionId
        import PsGetThreadTeb
        import PsGetThreadWin32Thread
        import PsIsProcessBeingDebugged
        import PsIsSystemThread
        import PsIsThreadImpersonating
        import PsRemoveCreateThreadNotifyRoutine
        import PsRemoveLoadImageNotifyRoutine
        import PsReturnProcessNonPagedPoolQuota
        import PsReturnProcessPagedPoolQuota
        import PsRevertThreadToSelf
        import PsSetContextThread
        #if NTDDI_VERSION == NTDDI_WINXP
            import WmiFlushTrace
            import WmiQueryTrace
            import WmiStartTrace
            import WmiStopTrace
            import WmiUpdateTrace
        #else
            #if NTDDI_VERSION < NTDDI_WIN8
                import PsSetJobUIRestrictionsClass
            #endif
        #endif
        import PsSetProcessPriorityClass
        import PsSetProcessSecurityPort
        import PsSetProcessWin32Process
        import PsSetProcessWindowStation
        import PsSetThreadHardErrorsAreDisabled
        import PsSetThreadWin32Thread
        import RtlClearBit
        import RtlCreateSystemVolumeInformationFolder
        import RtlDeleteElementGenericTableAvl
        import RtlEnumerateGenericTableAvl
        import RtlEnumerateGenericTableLikeADirectory
        import RtlEnumerateGenericTableWithoutSplayingAvl
        import RtlGetElementGenericTableAvl
        import RtlGetSetBootStatusData
        import RtlGetVersion
        import RtlHashUnicodeString
        import RtlInitializeGenericTableAvl
        import RtlInsertElementGenericTableAvl
        import RtlInsertElementGenericTableFullAvl
        import RtlInt64ToUnicodeString
        import RtlIntegerToUnicode
        import RtlIpv4AddressToStringA
        import RtlIpv4AddressToStringExA
        import RtlIpv4AddressToStringExW
        import RtlIpv4AddressToStringW
        import RtlIpv4StringToAddressA
        import RtlIpv4StringToAddressExA
        import RtlIpv4StringToAddressExW
        import RtlIpv4StringToAddressW
        import RtlIpv6AddressToStringA
        import RtlIpv6AddressToStringExA
        import RtlIpv6AddressToStringExW
        import RtlIpv6AddressToStringW
        import RtlIpv6StringToAddressA
        import RtlIpv6StringToAddressExA
        import RtlIpv6StringToAddressExW
        import RtlIpv6StringToAddressW
        import RtlIsGenericTableEmptyAvl
        import RtlLockBootStatusData
        import RtlLookupElementGenericTableAvl
        import RtlLookupElementGenericTableFullAvl
        import RtlMapSecurityErrorToNtStatus
        import RtlNumberGenericTableElementsAvl
        import RtlRandomEx
        import RtlSetBit
        import RtlTestBit
        import RtlTimeToElapsedTimeFields
        import RtlVerifyVersionInfo
        import SeAuditingHardLinkEventsWithContext
        import SeReportSecurityEvent
        import SeTokenIsWriteRestricted
        import SeTokenObjectType
        import vDbgPrintEx
        import vDbgPrintExWithPrefix
        import VfIsVerificationEnabled
        import WmiGetClock
        import WmiQueryTraceInformation
        import WmiTraceMessage
        import WmiTraceMessageVa
        import WRITE_REGISTER_BUFFER_UCHAR
        import WRITE_REGISTER_BUFFER_ULONG
        import WRITE_REGISTER_BUFFER_USHORT
        import WRITE_REGISTER_UCHAR
        import WRITE_REGISTER_ULONG
        import WRITE_REGISTER_USHORT
        import XIPDispatch
        import ZwAddBootEntry
        import ZwAssignProcessToJobObject
        import ZwCreateJobObject
        import ZwDeleteBootEntry
        import ZwEnumerateBootEntries
        import ZwIsProcessInJob
        import ZwOpenJobObject
        import ZwOpenProcessTokenEx
        import ZwOpenThreadTokenEx
        import ZwQueryBootEntryOrder
        import ZwQueryBootOptions
        import ZwQueryFullAttributesFile
        import ZwQueryInformationJobObject
        import ZwQueryInformationThread
        import ZwSaveKeyEx
        import ZwSetBootEntryOrder
        import ZwSetBootOptions
        import ZwSetInformationJobObject
        import ZwTerminateJobObject
        import ZwTranslateFilePath
        import _vsnwprintf

        #ifdef APP_UNICODE
            define RtlIpv4AddressToString RtlIpv4AddressToStringW
            define RtlIpv4AddressToStringEx RtlIpv4AddressToStringExW
            define RtlIpv4StringToAddress RtlIpv4StringToAddressW
            define RtlIpv4StringToAddressEx RtlIpv4StringToAddressExW
            define RtlIpv6AddressToString RtlIpv6AddressToStringW
            define RtlIpv6AddressToStringEx RtlIpv6AddressToStringExW
            define RtlIpv6StringToAddress RtlIpv6StringToAddressW
            define RtlIpv6StringToAddressEx RtlIpv6StringToAddressExW
        #else
            define RtlIpv4AddressToString RtlIpv4AddressToStringA
            define RtlIpv4AddressToStringEx RtlIpv4AddressToStringExA
            define RtlIpv4StringToAddress RtlIpv4StringToAddressA
            define RtlIpv4StringToAddressEx RtlIpv4StringToAddressExA
            define RtlIpv6AddressToString RtlIpv6AddressToStringA
            define RtlIpv6AddressToStringEx RtlIpv6AddressToStringExA
            define RtlIpv6StringToAddress RtlIpv6StringToAddressA
            define RtlIpv6StringToAddressEx RtlIpv6StringToAddressExA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_VISTA
        import AlpcGetHeaderSize
        import AlpcGetMessageAttribute
        import AlpcInitializeMessageAttribute
        import bsearch
        import CcGetFileObjectFromSectionPtrsRef
        import CcIsThereDirtyDataEx
        import CcSetFileSizesEx
        import CcSetParallelFlushFile
        import CmCallbackGetKeyObjectID
        import CmGetBoundTransaction
        import CmGetCallbackVersion
        import CmRegisterCallbackEx
        import CmSetCallbackObjectContext
        import DbgCommandString
        import DbgSetDebugPrintCallback
        import EmClientQueryRuleState
        import EtwActivityIdControl
        import EtwEventEnabled
        import EtwProviderEnabled
        import EtwRegister
        import EtwUnregister
        import EtwWrite
        import EtwWriteString
        import EtwWriteTransfer
        import ExAcquireSpinLockExclusive
        import ExAcquireSpinLockExclusiveAtDpcLevel
        import ExAcquireSpinLockShared
        import ExAcquireSpinLockSharedAtDpcLevel
        import ExAllocateCacheAwarePushLock
        import ExAllocateCacheAwareRundownProtection
        import ExDeleteLookasideListEx
        import ExEnterCriticalRegionAndAcquireFastMutexUnsafe
        import ExEnterCriticalRegionAndAcquireResourceExclusive
        import ExEnterCriticalRegionAndAcquireResourceShared
        import ExEnterCriticalRegionAndAcquireSharedWaitForExclusive
        import ExFlushLookasideListEx
        import ExFreeCacheAwarePushLock
        import ExfReleasePushLockExclusive
        import ExfReleasePushLockShared
        import ExfTryToWakePushLock
        import ExfUnblockPushLock
        import ExInitializeLookasideListEx
        import ExInitializePushLock
        import ExInitializeRundownProtectionCacheAware
        import ExReInitializeRundownProtectionCacheAware
        import ExReleaseCacheAwarePushLockExclusive
        import ExReleaseFastMutexUnsafeAndLeaveCriticalRegion
        import ExReleaseResourceAndLeaveCriticalRegion
        import ExReleaseRundownProtectionCacheAware
        import ExReleaseRundownProtectionCacheAwareEx
        import ExReleaseSpinLockExclusive
        import ExReleaseSpinLockExclusiveFromDpcLevel
        import ExReleaseSpinLockShared
        import ExReleaseSpinLockSharedFromDpcLevel
        import ExRundownCompletedCacheAware
        import ExSetLicenseTamperState
        import ExTryConvertSharedSpinLockExclusive
        import FirstEntrySList
        import FsRtlAcknowledgeEcp
        import FsRtlAddBaseMcbEntry
        import FsRtlAddBaseMcbEntryEx
        import FsRtlAllocateExtraCreateParameter
        import FsRtlAllocateExtraCreateParameterFromLookasideList
        import FsRtlAllocateExtraCreateParameterList
        import FsRtlAreVolumeStartupApplicationsComplete
        import FsRtlCancellableWaitForMultipleObjects
        import FsRtlCancellableWaitForSingleObject
        import FsRtlChangeBackingFileObject
        import FsRtlCheckOplockEx
        import FsRtlCurrentOplock
        import FsRtlDeleteExtraCreateParameterLookasideList
        import FsRtlFindExtraCreateParameter
        import FsRtlFreeExtraCreateParameter
        import FsRtlFreeExtraCreateParameterList
        import FsRtlGetEcpListFromIrp
        import FsRtlGetNextBaseMcbEntry
        import FsRtlGetNextExtraCreateParameter
        import FsRtlIncrementCcFastMdlReadWait
        import FsRtlInitExtraCreateParameterLookasideList
        import FsRtlInitializeExtraCreateParameter
        import FsRtlInitializeExtraCreateParameterList
        import FsRtlInsertExtraCreateParameter
        import FsRtlInsertPerFileContext
        import FsRtlIsEcpAcknowledged
        import FsRtlIsEcpFromUserMode
        import FsRtlLogCcFlushError
        import FsRtlLookupBaseMcbEntry
        import FsRtlLookupLastBaseMcbEntryAndIndex
        import FsRtlLookupPerFileContext
        import FsRtlMupGetProviderIdFromName
        import FsRtlMupGetProviderInfoFromFileObject
        import FsRtlNotifyCleanupAll
        import FsRtlNotifyVolumeEventEx
        import FsRtlOplockBreakToNone
        import FsRtlPrepareToReuseEcp
        import FsRtlRegisterUncProviderEx
        import FsRtlRemoveBaseMcbEntry
        import FsRtlRemoveDotsFromPath
        import FsRtlRemoveExtraCreateParameter
        import FsRtlRemovePerFileContext
        import FsRtlSetEcpListIntoIrp
        import FsRtlSplitBaseMcb
        import FsRtlTeardownPerFileContexts
        import FsRtlTruncateBaseMcb
        import FsRtlUninitializeBaseMcb
        import FsRtlValidateReparsePointBuffer
        import InterlockedPushListSList
        import IoAllocateMiniCompletionPacket
        import IoAllocateSfioStreamIdentifier
        import IoCheckShareAccessEx
        import IoClearIrpExtraCreateParameter
        import IoConnectInterruptEx
        import IoCreateFileEx
        import IoCsqInitializeEx
        import IoCsqInsertIrpEx
        import IoDisconnectInterruptEx
        import IoFreeSfioStreamIdentifier
        import IoGetBootDiskInformationLite
        import IoGetDevicePropertyData
        import IoGetIoPriorityHint
        import IoGetIrpExtraCreateParameter
        import IoGetPagingIoPriority
        import IoGetSfioStreamIdentifier
        import IoGetTransactionParameterBlock
        import IoInitializeWorkItem
        import IoIsFileObjectIgnoringSharing
        import IoQueueWorkItemEx
        import IoReplacePartitionUnit
        import IoSetDevicePropertyData
        import IoSetIoPriorityHint
        import IoSetIrpExtraCreateParameter
        import IoSetShareAccessEx
        import IoSizeofWorkItem
        import IoTranslateBusAddress
        import IoUninitializeWorkItem
        import IoWithinStackLimits
        import KdRefreshDebuggerNotPresent
        import KdSystemDebugControl
        import KeAcquireGuardedMutex
        import KeAcquireGuardedMutexUnsafe
        import KeAcquireInStackQueuedSpinLockForDpc
        import KeAcquireSpinLockForDpc
        import KeAlertThread
        import KeAreAllApcsDisabled
        import KeDeregisterNmiCallback
        import KeDeregisterProcessorChangeCallback
        import KeEnterGuardedRegion
        import KeExpandKernelStackAndCallout
        import KeExpandKernelStackAndCalloutEx
        import KeFindFirstSetLeftAffinityEx
        import KeGenericCallDpc
        import KeInitializeCrashDumpHeader
        import KeInitializeGuardedMutex
        import KeInitializeThreadedDpc
        import KeInvalidateAllCaches
        import KeInvalidateRangeAllCaches
        import KeIpiGenericCall
        import KeIsWaitListEmpty
        import KeLeaveGuardedRegion
        import KeQueryActiveProcessorCount
        import KeQueryDpcWatchdogInformation
        import KeQueryMaximumProcessorCount
        import KeRegisterNmiCallback
        import KeRegisterProcessorChangeCallback
        import KeReleaseGuardedMutex
        import KeReleaseGuardedMutexUnsafe
        import KeReleaseInStackQueuedSpinLockForDpc
        import KeReleaseInStackQueuedSpinLockFromDpcLevel
        import KeReleaseSpinLockForDpc
        import KeRemoveQueueEx
        import KeRevertToUserGroupAffinityThread
        import KeSetSystemAffinityThreadEx
        import KeTestAlertThread
        import KeTestSpinLock
        import KeTryToAcquireGuardedMutex
        import KeTryToAcquireSpinLockAtDpcLevel
        import KiCheckForKernelApcDelivery
        import LpcRequestWaitReplyPortEx
        import MmAllocateContiguousMemorySpecifyCacheNode
        import MmAllocatePagesForMdlEx
        import MmCopyVirtualMemory
        import MmCreateMirror
        import MmDoesFileHaveUserWritableReferences
        import MmIsDriverVerifyingByAddress
        import MmIsIoSpaceActive
        import MmRotatePhysicalView
        import NtCommitComplete
        import NtCommitEnlistment
        import NtCommitTransaction
        import NtCreateEnlistment
        import NtCreateResourceManager
        import NtCreateTransaction
        import NtEnumerateTransactionObject
        import NtFreezeTransactions
        import NtGetNotificationResourceManager
        import NtOpenEnlistment
        import NtOpenResourceManager
        import NtOpenTransaction
        import NtPrepareComplete
        import NtPrepareEnlistment
        import NtPrePrepareEnlistment
        import NtQueryInformationEnlistment
        import NtQueryInformationResourceManager
        import NtQueryInformationTransaction
        import NtQueryInformationTransactionManager
        import NtRollbackEnlistment
        import NtRollbackTransaction
        import NtSetInformationEnlistment
        import NtSetInformationResourceManager
        import NtSetInformationTransaction
        import NtThawTransactions
        import NtTraceControl
        import ObDereferenceObjectDeferDelete
        import ObDereferenceSecurityDescriptor
        import ObGetFilterVersion
        import ObIsKernelHandle
        import ObRegisterCallbacks
        import ObUnRegisterCallbacks
        import PoGetSystemWake
        import PoRegisterPowerSettingCallback
        import PoSetDeviceBusyEx
        import PoSetSystemWake
        import PoUnregisterPowerSettingCallback
        import PsAcquireProcessExitSynchronization
        import PsGetCurrentProcessWin32Process
        import PsGetCurrentThreadProcess
        import PsGetCurrentThreadProcessId
        import PsGetCurrentThreadTeb
        import PsGetCurrentThreadWin32Thread
        import PsIsCurrentThreadPrefetching
        import PsIsSystemProcess
        import PsReferenceProcessFilePointer
        import PsResumeProcess
        import PsSetCreateProcessNotifyRoutineEx
        import PsSetCurrentThreadPrefetching
        import PsSuspendProcess
        import PsWrapApcWow64Thread
        import RtlCmDecodeMemIoResource
        import RtlCmEncodeMemIoResource
        import RtlCompareAltitudes
        import RtlComputeCrc32
        import RtlCopyLuidAndAttributesArray
        import RtlCopySidAndAttributesArray
        import RtlDuplicateUnicodeString
        import RtlFormatMessage
        import RtlGetThreadLangIdByIndex
        import RtlInitAnsiStringEx
        import RtlInitUnicodeStringEx
        import RtlIoDecodeMemIoResource
        import RtlIoEncodeMemIoResource
        import RtlIsNormalizedString
        import RtlIsNtDdiVersionAvailable
        import RtlIsServicePackVersionInstalled
        import RtlLocalTimeToSystemTime
        import RtlLookupFirstMatchingElementGenericTableAvl
        import RtlNumberOfSetBitsUlongPtr
        import RtlQueryElevationFlags
        import RtlRunOnceBeginInitialize
        import RtlRunOnceComplete
        import RtlRunOnceExecuteOnce
        import RtlRunOnceInitialize
        import RtlSystemTimeToLocalTime
        import RtlUnlockBootStatusData
        import RtlValidateUnicodeString
        import SeAuditHardLinkCreationWithTransaction
        import SeAuditTransactionStateChange
        import SeCaptureSubjectContextEx
        import SeComputeAutoInheritByObjectType
        import SeCreateAccessStateEx
        import SeDeleteObjectAuditAlarmWithTransaction
        import SeExamineSacl
        import SeFilterToken
        import SeLocateProcessImageName
        import SeOpenObjectForDeleteAuditAlarmWithTransaction
        import SeReportSecurityEventWithSubCategory
        import SeSetAuditParameter
        import TmCommitComplete
        import TmCommitEnlistment
        import TmCommitTransaction
        import TmCreateEnlistment
        import TmDereferenceEnlistmentKey
        import TmEnableCallbacks
        import TmGetTransactionId
        import TmIsTransactionActive
        import TmPrepareComplete
        import TmPrepareEnlistment
        import TmPrePrepareComplete
        import TmPrePrepareEnlistment
        import TmReadOnlyEnlistment
        import TmRecoverEnlistment
        import TmRecoverResourceManager
        import TmRecoverTransactionManager
        import TmReferenceEnlistmentKey
        import TmRequestOutcomeEnlistment
        import TmRollbackComplete
        import TmRollbackEnlistment
        import TmRollbackTransaction
        import WheaAddErrorSource
        import ZwAddDriverEntry
        import ZwAllocateLocallyUniqueId
        import ZwAlpcAcceptConnectPort
        import ZwAlpcCancelMessage
        import ZwAlpcConnectPort
        import ZwAlpcCreatePort
        import ZwAlpcCreatePortSection
        import ZwAlpcCreateResourceReserve
        import ZwAlpcCreateSectionView
        import ZwAlpcCreateSecurityContext
        import ZwAlpcDeletePortSection
        import ZwAlpcDeleteResourceReserve
        import ZwAlpcDeleteSectionView
        import ZwAlpcDeleteSecurityContext
        import ZwAlpcDisconnectPort
        import ZwAlpcQueryInformation
        import ZwAlpcSendWaitReceivePort
        import ZwAlpcSetInformation
        import ZwCommitEnlistment
        import ZwCommitTransaction
        import ZwCreateEnlistment
        import ZwCreateIoCompletion
        import ZwCreateKeyTransacted
        import ZwCreateResourceManager
        import ZwCreateTransaction
        import ZwCreateTransactionManager
        import ZwEnumerateDriverEntries
        import ZwEnumerateTransactionObject
        import ZwFlushBuffersFile
        import ZwGetNotificationResourceManager
        import ZwImpersonateAnonymousToken
        import ZwLoadKeyEx
        import ZwLockProductActivationKeys
        import ZwModifyBootEntry
        import ZwModifyDriverEntry
        import ZwOpenEnlistment
        import ZwOpenKeyTransacted
        import ZwOpenResourceManager
        import ZwOpenTransaction
        import ZwOpenTransactionManager
        import ZwPrepareComplete
        import ZwPrepareEnlistment
        import ZwPrePrepareEnlistment
        import ZwQueryDriverEntryOrder
        import ZwQueryInformationEnlistment
        import ZwQueryInformationResourceManager
        import ZwQueryInformationTransaction
        import ZwQueryInformationTransactionManager
        import ZwQueryVirtualMemory
        import ZwRecoverEnlistment
        import ZwRecoverResourceManager
        import ZwRecoverTransactionManager
        import ZwRemoveIoCompletion
        import ZwRemoveIoCompletionEx
        import ZwRequestPort
        import ZwRollbackEnlistment
        import ZwRollbackTransaction
        import ZwSecureConnectPort
        import ZwSetDriverEntryOrder
        import ZwSetInformationEnlistment
        import ZwSetInformationTransaction
        import ZwUnloadKeyEx
        import _strtoui64
        import _swprintf
        import _vswprintf
    #endif

    #if NTDDI_VERSION >= NTDDI_WIN7
        import CcCoherencyFlushAndPurgeCache
        import CcCopyWriteWontFlush
        import EtwWriteEx
        import ExAcquireFastMutex
        import ExpInterlockedFlushSList
        import ExpInterlockedPopEntrySList
        import ExpInterlockedPushEntrySList
        import ExQueryDepthSList
        import ExReleaseFastMutex
        import ExSetResourceOwnerPointerEx
        import ExTryToAcquireFastMutex
        import FsRtlCurrentOplockH
        import FsRtlAreThereCurrentOrInProgressFileLocks
        import FsRtlGetVirtualDiskNestingLevel
        import FsRtlOplockBreakH
        import FsRtlOplockBreakToNoneEx
        import FsRtlOplockFsctrlEx
        import FsRtlOplockIsSharedRequest
        import FsRtlOplockKeysEqual
        import FsRtlQueryMaximumVirtualDiskNestingLevel
        import IoGetAffinityInterrupt
        import IoGetContainerInformation
        import IoGetDeviceNumaNode
        import IoGetOplockKeyContext
        import IoIs32bitProcess
        import IoRegisterContainerNotification
        import IoRegisterFsRegistrationChangeMountAware
        import IoReplaceFileObjectName
        import IoReportRootDevice
        import IoSetFileObjectIgnoreSharing
        import IoUnregisterContainerNotification
        import IoUnregisterPlugPlayNotificationEx
        import IoUnregisterPriorityCallback
        import IoWMIDeviceObjectToProviderId
        #ifdef APP_WIN64
            import KeAcquireInStackQueuedSpinLock
            import KeAcquireInStackQueuedSpinLockRaiseToSynch
            import KeAcquireQueuedSpinLock
            import KeAcquireQueuedSpinLockRaiseToSynch
            import KeAcquireSpinLockRaiseToDpc
            import KeAcquireSpinLockRaiseToSynch
            import KeGetCurrentIrql
            import KeLowerIrql
            import KeQueryPrcbAddress
            import KeRaiseIrqlToDpcLevel
            import KeReleaseInStackQueuedSpinLock
            import KeReleaseQueuedSpinLock
            import KeReleaseSpinLock
            import KeTryToAcquireQueuedSpinLock
            import KeTryToAcquireQueuedSpinLockRaiseToSynch
            import longjmp
            import memcmp
            import PsGetProcessWow64Process
            import RtlLookupFunctionEntry
            import RtlPcToFileHeader
            import RtlRestoreContext
            import RtlVirtualUnwind
            import _setjmp
            import _setjmpex
        #endif
        import KeAndAffinityEx
        import KeComplementAffinityEx
        import KeGetCurrentNodeNumber
        import KeGetCurrentProcessorNumberEx
        import KeGetProcessorIndexFromNumber
        import KeGetProcessorNumberFromIndex
        import KeInitializeEnumerationContext
        import KeInterlockedSetProcessorAffinityEx
        import KeIsEmptyAffinityEx
        import KeIsEqualAffinityEx
        import KeIsSubsetAffinityEx
        import KeQueryActiveGroupCount
        import KeQueryActiveProcessorCountEx
        import KeQueryGroupAffinity
        import KeQueryHardwareCounterConfiguration
        import KeQueryHighestNodeNumber
        import KeQueryLogicalProcessorRelationship
        import KeQueryMaximumGroupCount
        import KeQueryMaximumProcessorCountEx
        import KeQueryNodeActiveAffinity
        import KeQueryNodeMaximumProcessorCount
        import KeQueryUnbiasedInterruptTime
        import KeSaveExtendedProcessorState
        import KeSetCoalescableTimer
        import KeSetHardwareCounterConfiguration
        import KeSetSystemGroupAffinityThread
        import KeSetTargetProcessorDpcEx
        import memcpy_s
        import memmove_s
        import NtCreateTransactionManager
        import NtOpenTransactionManager
        import NtPrePrepareComplete
        import NtPropagationComplete
        import NtPropagationFailed
        import NtQuerySecurityAttributesToken
        import NtQuerySystemInformationEx
        import NtReadOnlyEnlistment
        import NtRecoverEnlistment
        import NtRecoverResourceManager
        import NtRecoverTransactionManager
        import NtRollbackComplete
        import NtSetInformationToken
        import ObDereferenceObjectDeferDeleteWithTag
        import ObfReferenceObjectWithTag
        import ObOpenObjectByPointerWithTag
        import ObQueryNameInfo
        import ObReferenceObjectByHandleWithTag
        import ObReferenceObjectByPointerWithTag
        import PcwAddInstance
        import PcwCloseInstance
        import PcwCreateInstance
        import PcwRegister
        import PcwUnregister
        import PoClearPowerRequest
        import PoCreatePowerRequest
        import PoDeletePowerRequest
        import PoEndDeviceBusy
        import PoQueryWatchdogTime
        import PoSetPowerRequest
        import PoStartDeviceBusy
        import RtlDowncaseUnicodeChar
        import RtlCompareUnicodeStrings
        import RtlEthernetAddressToStringA
        import RtlEthernetAddressToStringW
        import RtlEthernetStringToAddressA
        import RtlEthernetStringToAddressW
        import RtlGetEnabledExtendedFeatures
        import RtlGetNextEntryHashTable
        import RtlInitEnumerationHashTable
        import RtlInitWeakEnumerationHashTable
        import RtlInsertEntryHashTable
        import RtlLookupEntryHashTable
        import RtlUnicodeToUTF8N
        import RtlUTF8ToUnicodeN
        import SeAccessCheckEx
        import SeAuditingAnyFileEventsWithContext
        import SeAuditingFileEventsWithContext
        import vsprintf_s
        import vswprintf_s
        import wcscat_s
        import wcscpy_s
        import wcsncat_s
        import wcsncpy_s
        import wcsnlen
        import wcstoul
        import ZwCommitComplete
        import ZwLockFile
        import ZwOpenKeyEx
        import ZwOpenKeyTransactedEx
        import ZwOpenSession
        import ZwPrePrepareComplete
        import ZwPropagationComplete
        import ZwPropagationFailed
        import ZwQueryQuotaInformationFile
        import ZwQuerySecurityAttributesToken
        import ZwReadOnlyEnlistment
        import ZwRenameKey
        import ZwRollbackComplete
        import ZwSetInformationResourceManager
        import ZwSetInformationToken
        import ZwSetQuotaInformationFile
        import ZwSetTimerEx
        import ZwTraceEvent
        import ZwUnlockFile
        import _i64toa_s
        import _i64tow_s
        import _itoa_s
        import _itow_s
        import _ltoa_s
        import _ltow_s
        import _makepath_s
        import _snprintf_s
        import _splitpath_s
        import _strnset_s
        import _strset_s
        import _ui64toa_s
        import _ui64tow_s
        import _ultoa_s
        import _ultow_s
        import _vsnprintf_s
        import _vsnwprintf_s
        import _wcsnset_s
        import _wcsset_s
        import _wmakepath_s
        import _wsplitpath_s
        import _wtoi
        import _wtol

        #ifdef APP_UNICODE
            define RtlEthernetAddressToString RtlEthernetAddressToStringW
            define RtlEthernetStringToAddress RtlEthernetStringToAddressW
        #else
            define RtlEthernetAddressToString RtlEthernetAddressToStringA
            define RtlEthernetStringToAddress RtlEthernetStringToAddressA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WIN8
        import bsearch_s
        import CcCopyReadEx
        import CcCopyWriteEx
        import CcIsThereDirtyLoggedPages
        import CcScheduleReadAheadEx
        import CcSetAdditionalCacheAttributesEx
        import CcSetLoggedDataThreshold
        import CcSetLogHandleForFileEx
        import CcSetReadAheadGranularityEx
        import CcUnmapFileOffsetFromSystemCache
        import CmCallbackGetKeyObjectIDEx
        import CmCallbackReleaseKeyObjectIDEx
        import ExBlockPushLock
        import ExGetFirmwareEnvironmentVariable
        import ExQueryTimerResolution
        import ExSetFirmwareEnvironmentVariable
        import ExTimedWaitForUnblockPushLock
        import ExWaitForUnblockPushLock
        import FsRtlAreThereWaitingFileLocks
        import FsRtlCheckLockForOplockRequest
        import FsRtlGetSectorSizeInformation
        import FsRtlGetSupportedFeatures
        import FsRtlIssueDeviceIoControl
        import FsRtlIsSystemPagingFile
        import FsRtlMdlReadEx
        import FsRtlPrepareMdlWriteEx
        import FsRtlQueryCachedVdl
        import IoClearActivityIdThread
        import IoCreateStreamFileObjectEx2
        import IoCreateSystemThread
        import IoDecrementKeepAliveCount
        import IoGetActivityIdIrp
        import IoGetActivityIdThread
        import IoGetDeviceInterfacePropertyData
        import IoGetInitiatorProcess
        import IoGetOplockKeyContextEx
        import IoIncrementKeepAliveCount
        import IoIsInitiator32bitProcess
        import IoIsValidIrpStatus
        import IoPropagateActivityIdToThread
        import IoRegisterBootDriverCallback
        import IoReportInterruptActive
        import IoReportInterruptInactive
        import IoSetActivityIdIrp
        import IoSetActivityIdThread
        import IoSetDeviceInterfacePropertyData
        import IoSetMasterIrpStatus
        import IoTransferActivityId
        import IoTryQueueWorkItem
        import IoUnregisterBootDriverCallback
        import IoVolumeDeviceToGuid
        import KdLogDbgPrint
        import KeQueryInterruptTimePrecise
        import KeQuerySystemTimePrecise
        import KeQueryTotalCycleTimeThread
        import MmAllocateContiguousNodeMemory
        import MmAllocateMdlForIoSpace
        import MmAllocateNodePagesForMdlEx
        import MmGetMaximumFileSectionSize
        import MmIsDriverSuspectForVerifier
        import ObDuplicateObject
        import ObReferenceObjectSafe
        import ObWaitForSingleObject
        import PoFxActivateComponent
        import PoFxCompleteDevicePowerNotRequired
        import PoFxCompleteIdleCondition
        import PoFxCompleteIdleState
        import PoFxIdleComponent
        import PoFxNotifySurprisePowerOn
        import PoFxPowerControl
        import PoFxRegisterDevice
        import PoFxReportDevicePoweredOn
        import PoFxSetComponentLatency
        import PoFxSetComponentResidency
        import PoFxSetComponentWake
        import PoFxSetDeviceIdleTimeout
        import PoFxStartDevicePowerManagement
        import PoFxUnregisterDevice
        import PsCreateSystemThreadEx
        import PsGetThreadExitStatus
        import PsIsDiskCountersEnabled
        import PsQueryTotalCycleTimeProcess
        import PsUpdateDiskCounters
        import RtlCheckPortableOperatingSystem
        import RtlCreateUserThread
        import RtlCultureNameToLCID
        import RtlDecompressBufferEx
        import RtlDeleteElementGenericTableAvlEx
        import RtlOpenCurrentUser
        import RtlQueryInformationAcl
        import RtlRbInsertNodeEx
        import RtlRbRemoveNode
        import RtlSetControlSecurityDescriptor
        import TmInitializeTransactionManager
        import TmRenameTransactionManager
        import TmSinglePhaseReject
        import WheaRegisterInUsePageOfflineNotification
        import WheaUnregisterInUsePageOfflineNotification
        import ZwFlushBuffersFileEx
        import ZwQuerySystemEnvironmentValueEx
        import ZwSetInformationKey
        import ZwSetSystemEnvironmentValueEx
        import ZwUnlockVirtualMemory
    #endif
#endif

#if NTDDI_VERSION >= NTDDI_WIN81
    import ExAllocateTimer
    import ExCancelTimer
    import ExDeleteTimer
    import ExSetTimer
    import FsRtlUpperOplockFsctrl
    import IoQueryFullDriverPath
    import MmCopyMemory
    import MmMdlPagesAreZero
    import PoFxPowerOnCrashdumpDevice
    import PoFxRegisterCrashdumpDevice
    import SeAdjustAccessStateForTrustLabel
    import SeShouldCheckForAccessRightsFromParent
    import ZwAssociateWaitCompletionPacket
    import ZwCancelIoFileEx
    import ZwCreateWaitCompletionPacket
    import ZwLockVirtualMemory
    import ZwProtectVirtualMemory
    import ZwQuerySystemInformationEx
#endif

#if NTDDI_VERSION >= NTDDI_WIN10
    import _finite
    import _wcslwr_s
    import CcAsyncCopyRead
    import ExIsManufacturingModeEnabled
    import IoClearFsTrackOffsetState
    import IoGetSiloParameters
    import IoInitializeIrpEx
    import IoIrpHasFsTrackOffsetExtensionType
    import IoRequestDeviceRemovalForReset
    import IoSetFsTrackOffsetState
    import IoSetFsZeroingOffset
    import IoSetFsZeroingOffsetRequired
    import IoSizeOfIrpEx
    import IoVolumeDeviceNameToGuid
    import KeConvertAuxiliaryCounterToPerformanceCounter
    import KeConvertPerformanceCounterToAuxiliaryCounter
    import KeDeregisterBoundCallback
    import KeFlushIoBuffers
    import KeQueryAuxiliaryCounterFrequency
    import KeRegisterBoundCallback
    import KeShouldYieldProcessor
    import MmLoadSystemImage
    import MmMapIoSpaceEx
    import MmUnloadSystemImage
    import PoCreateThermalRequest
    import PoDeleteThermalRequest
    import PoFxIssueComponentPerfStateChange
    import PoFxIssueComponentPerfStateChangeMultiple
    import PoFxQueryCurrentComponentPerfState
    import PoFxRegisterComponentPerfStates
    import PoGetThermalRequestSupport
    import PoSetThermalActiveCooling
    import PoSetThermalPassiveCooling
    import PsAllocateMonitorContextServerSilo
    import PsAttachSiloToCurrentThread
    import PsDeleteMonitorContextServerSilo
    import PsDereferenceMonitorContextServerSilo
    import PsDetachSiloFromCurrentThread
    import PsEqualCurrentServerSilo
    import PsEqualCurrentSilo
    import PsGetCurrentServerSilo
    import PsGetCurrentServerSiloName
    import PsGetCurrentSilo
    import PsGetCurrentSiloObject
    import PsGetJobServerSilo
    import PsGetMonitorContextServerSilo
    import PsGetServerSiloServiceSessionId
    import PsGetSiloObjectFromJob
    import PsGetThreadCreateTime
    import PsGetThreadProperty
    import PsInsertSiloObjectFromJob
    import PsIsCurrentThreadInServerSilo
    import PsIsHostSilo
    import PsReferenceMonitorContextServerSilo
    import PsRegisterMonitorServerSilo
    import PsRegisterPicoProvider
    import PsRemoveSiloObjectFromJob
    import PsSetCreateThreadNotifyRoutineEx
    import PsSetMonitorContextServerSilo
    import PsStartMonitorServerSilo
    import PsUnregisterMonitorServerSilo
    import RtlAddAccessDeniedAceEx
    import RtlAddAccessDeniedObjectAce
    import RtlAddAuditAccessAceEx
    import RtlAddAuditAccessObjectAce
    import RtlDecompressBufferEx2
    import RtlDecompressFragmentEx
    import RtlEndStrongEnumerationHashTable
    import RtlFirstFreeAce
    import RtlGetControlSecurityDescriptor
    import RtlInitializeSidEx
    import RtlInitStringEx
    import RtlInitStrongEnumerationHashTable
    import RtlLargeIntegerToChar
    import RtlOsDeploymentState
    import RtlStronglyEnumerateEntryHashTable
    import RtlSuffixUnicodeString
    import RtlUnicodeStringToInt64
    import RtlValidAcl
    import SeAuditFipsCryptoSelftests
    import SeMarkLogonSessionForTerminationNotificationEx
    import SeQuerySessionIdTokenEx
    import SeRegisterLogonSessionTerminatedRoutineEx
    import SeUnregisterLogonSessionTerminatedRoutineEx
    import ZwAlpcOpenSenderThread
    import ZwAlpcQueryInformationMessage
    import ZwCompareTokens
    import ZwGetCachedSigningLevel
    import ZwGetNextProcess
    import ZwNotifyChangeDirectoryFile
    import ZwTraceControl
    import ZwUnloadKey2
#endif

;======================= Undocumented functions (unknown arguments) =======================;
;import BgkDisplayCharacter
;import BgkGetConsoleState
;import BgkGetCursorState
;import BgkSetCursor
;import CcAddDirtyPagesToExternalCache
;import CcDeductDirtyPagesFromExternalCache
;import CcFlushCacheToLsn
;import CcRegisterExternalCache
;import CcTestControl
;import CcUnregisterExternalCache
;import CcZeroDataOnDisk
;import CmKeyObjectType
;import DbgkLkmdRegisterCallback
;import DbgkLkmdUnregisterCallback
;import DbgkWerCaptureLiveKernelDump
;import EmClientRuleDeregisterNotification
;import EmClientRuleEvaluate
;import EmClientRuleRegisterNotification
;import EmpProviderRegister
;import EmProviderDeregister
;import EmProviderDeregisterEntry
;import EmProviderRegister
;import EmProviderRegisterEntry
;import EtwEnableTrace
;import EtwRegisterClassicProvider
;import EtwSendTraceBuffer
;import EtwSetInformation
;import EtwWriteEndScenario
;import CcFastReadNotPossible
;import EtwWriteStartScenario
;import ExAcquireAutoExpandPushLockExclusive
;import ExAcquireAutoExpandPushLockShared
;import ExAcquireCacheAwarePushLockExclusive
;import ExAcquireCacheAwarePushLockExclusiveEx
;import ExAcquireCacheAwarePushLockSharedEx
;import ExAcquirePushLockExclusiveEx
;import ExAcquirePushLockSharedEx
;import ExAcquireRundownProtectionCacheAware
;import ExAcquireRundownProtectionCacheAwareEx
;import ExAllocateAutoExpandPushLock
;import ExBlockOnAddressPushLock
;import ExCleanupAutoExpandPushLock
;import ExCleanupRundownProtectionCacheAware
;import ExCompositionObjectType
;import ExCompositionSurfaceObjectType
;import ExConvertPushLockExclusiveToShared
;import ExDesktopObjectType
;import ExEnterPriorityRegionAndAcquireResourceExclusive
;import ExEnterPriorityRegionAndAcquireResourceShared
;import ExEventObjectType
;import ExFetchLicenseData
;import ExFreeAutoExpandPushLock
;import ExFreeCacheAwareRundownProtection
;import ExfTryAcquirePushLockShared
;import ExGetLicenseTamperState
;import ExiAcquireFastMutex
;import ExInitializeAutoExpandPushLock
;import ExInitializeRundownProtectionCacheAwareEx
;import ExNotifyBootDeviceRemoval
;import ExQueryAttributeInformation
;import ExQueryFastCacheAppOrigin
;import ExQueryFastCacheDevLicense
;import ExQueryWnfStateData
;import ExRawInputManagerObjectType
;import ExRealTimeIsUniversal
;import ExRegisterAttributeInformationCallback
;import ExRegisterBootDevice
;import ExRegisterExtension
;import ExReleaseAutoExpandPushLockExclusive
;import ExReleaseAutoExpandPushLockShared
;import ExReleaseCacheAwarePushLockExclusiveEx
;import ExReleaseCacheAwarePushLockSharedEx
;import ExReleasePushLockEx
;import ExReleasePushLockExclusiveEx
;import ExReleasePushLockSharedEx
;import ExReleaseResourceAndLeavePriorityRegion
;import ExSemaphoreObjectType
;import ExShareAddressSpaceWithDevice
;import ExSizeOfAutoExpandPushLock
;import ExSizeOfRundownProtectionCacheAware
;import ExSubscribeWnfStateChange
;import ExTimerObjectType
;import ExTryAcquireAutoExpandPushLockExclusive
;import ExTryAcquireAutoExpandPushLockShared
;import ExTryAcquireCacheAwarePushLockExclusiveEx
;import ExTryAcquireCacheAwarePushLockSharedEx
;import ExTryAcquirePushLockExclusiveEx
;import ExTryAcquirePushLockSharedEx
;import ExTryConvertPushLockSharedToExclusiveEx
;import ExTryQueueWorkItem
;import ExTryToAcquireResourceExclusiveLite
;import ExUnblockOnAddressPushLockEx
;import ExUnblockPushLockEx
;import ExUnregisterAttributeInformationCallback
;import ExUnregisterExtension
;import ExUnsubscribeWnfStateChange
;import ExUpdateLicenseData
;import ExWaitForRundownProtectionReleaseCacheAware
;import ExWindowStationObjectType
;import FsRtlAcquireEofLock
;import FsRtlAcquireHeaderMutex
;import FsRtlCheckUpperOplock
;import FsRtlDismountComplete
;import FsRtlGetFileNameInformation
;import FsRtlGetIoAtEof
;import FsRtlHeatInit
;import FsRtlHeatLogIo
;import FsRtlHeatLogTierMove
;import FsRtlHeatUninit
;import FsRtlInitializeBaseMcb
;import FsRtlInitializeBaseMcbEx
;import FsRtlInitializeEofLock
;import FsRtlInsertReservedPerFileContext
;import FsRtlInsertReservedPerStreamContext
;import FsRtlIsMobileOS
;import FsRtlKernelFsControlFile
;import FsRtlLegalAnsiCharacterArray
;import FsRtlLookupLastBaseMcbEntry
;import FsRtlLookupReservedPerFileContext
;import FsRtlLookupReservedPerStreamContext
;import FsRtlNotifyFilterChangeDirectoryLite
;import FsRtlNotifyFilterReportChangeLite
;import FsRtlNumberOfRunsInBaseMcb
;import FsRtlQueryInformationFile
;import FsRtlQueryKernelEaFile
;import FsRtlRegisterFltMgrCalls
;import FsRtlRegisterMupCalls
;import FsRtlRegisterUncProviderEx2
;import FsRtlReleaseEofLock
;import FsRtlReleaseFileNameInformation
;import FsRtlReleaseHeaderMutex
;import FsRtlRemoveReservedPerFileContext
;import FsRtlRemoveReservedPerStreamContext
;import FsRtlSendModernAppTermination
;import FsRtlSetDriverBacking
;import FsRtlSetKernelEaFile
;import FsRtlTryToAcquireHeaderMutex
;import FsRtlUpdateDiskCounters
;import FsRtlValidateReparsePointBuffer
;import HalDispatchTable
;import HalPrivateDispatchTable
;import HvlGetLpIndexFromApicId
;import HviGetDebugDeviceOptions
;import HviGetEnlightenmentInformation
;import HviGetHardwareFeatures
;import HviGetHypervisorFeatures
;import HviGetHypervisorInterface
;import HviGetHypervisorVendorAndMaxFunction
;import HviGetHypervisorVersion
;import HviGetImplementationLimits
;import HviIsAnyHypervisorPresent
;import HviIsHypervisorMicrosoftCompatible
;import HviIsHypervisorVendorMicrosoft
;import HviIsIommuInUse
;import HvlPerformEndOfInterrupt
;import HvlQueryActiveHypervisorProcessorCount
;import HvlQueryActiveProcessors
;import HvlQueryConnection
;import HvlQueryHypervisorProcessorNodeNumber
;import HvlQueryNumaDistance
;import HvlQueryProcessorTopology
;import HvlQueryProcessorTopologyCount
;import HvlQueryProcessorTopologyHighestId
;import HvlReadPerformanceStateCounters
;import HvlRegisterInterruptCallback
;import HvlRegisterWheaErrorNotification
;import HvlUnregisterInterruptCallback
;import HvlUnregisterWheaErrorNotification
;import InbvNotifyDisplayOwnershipChange
;import InbvSetVirtualFrameBuffer
;import InitSafeBootMode
;import IoAdapterObjectType
;import IoAdjustStackSizeForRedirection
;import IoAllocateIrpEx
;import IoApplyPriorityInfoThread
;import IoBoostThreadIo
;import IoCallDriverStackSafe
;import IoClearDependency
;import IoClearReservedDependency
;import IoCompletionObjectType
;import IoConvertFileHandleToKernelHandle
;import IoCopyDeviceObjectHint
;import IoCreateArcName
;import IoDeleteAllDependencyRelations
;import IoDeviceHandlerObjectSize
;import IoDeviceHandlerObjectType
;import IoDeviceObjectType
;import IoDriverObjectType
;import IoDuplicateDependency
;import IoEnumerateRegisteredFiltersListEx
;import IoFileObjectType
;import IoFreeMiniCompletionPacket
;import IoGetFsTrackOffsetState
;import IoGetFsZeroingOffset
;import IoGetGenericIrpExtension
;import IoGetSymlinkSupportInformation
;import IoInitializeMiniCompletionPacket
;import IoIsActivityTracingEnabled
;import IoLoadCrashDumpDriver
;import IoMakeAssociatedIrpEx
;import IoPropagateIrpExtension
;import IoPropagateIrpExtensionEx
;import IoQueryInterface
;import IoQueueWorkItemToNode
;import IoReadOperationCount
;import IoReadTransferCount
;import IoRegisterFsRegistrationChangeMountAwareEx
;import IoRegisterIoTracking
;import IoRegisterPriorityCallback
;import IoRequestDeviceEjectEx
;import IoReserveDependency
;import IoResolveDependency
;import IoRetrievePriorityInfo
;import IoSetDependency
;import IoSetGenericIrpExtension
;import IoSetIoCompletionEx
;import IoSetIoPriorityHintIntoFileObject
;import IoSetIoPriorityHintIntoThread
;import IoSizeofGenericIrpExtension
;import IoStatisticsLock
;import IoSynchronousCallDriver
;import IoSteerInterrupt
;import IoTestDependency
;import IoUnregisterIoTracking
;import IoVolumeDeviceNameToGuidPath
;import IoVolumeDeviceToGuidPath
;import IoWriteOperationCount
;import IoWriteTransferCount
;import iswalnum
;import iswdigit
;import iswspace
;import KdAcquireDebuggerLock
;import KdChangeOption
;import KdDebuggerEnabled
;import KdDebuggerNotPresent
;import KdDeregisterPowerHandler
;import KdEnteredDebugger
;import KdEventLoggingEnabled
;import KdGetDebugDevice
;import KdRegisterPowerHandler
;import KdReleaseDebuggerLock
;import KdSetEventLoggingPresent
;import KeAddGroupAffinityEx
;import KeAddProcessorAffinityEx
;import KeAddProcessorGroupAffinity
;import KeAllocateCalloutStack
;import KeAllocateCalloutStackEx
;import KeAndGroupAffinityEx
;import KeCancelTimer2
;import KeCheckProcessorAffinityEx
;import KeCheckProcessorGroupAffinity
;import KeClockInterruptNotify
;import KeClockTimerPowerChange
;import KeConnectInterruptForHal
;import KeCopyAffinityEx
;import KeCountSetBitsAffinityEx
;import KeCountSetBitsGroupAffinity
;import KeDcacheFlushCount
;import KeDispatchSecondaryInterrupt
;import KeEnumerateNextProcessor
;import KeFindFirstSetLeftGroupAffinity
;import KeFindFirstSetRightAffinityEx
;import KeFindFirstSetRightGroupAffinity
;import KeFirstGroupAffinityEx
;import KeForceEnableNx
;import KeFreeCalloutStack
;import KeGetClockOwner
;import KeGetClockTimerResolution
;import KeGetEffectiveIrql
;import KeGetNextClockTickDuration
;import KeGetNextTimerExpirationDueTime
;import KeGetXSaveFeatureFlags
;import KeHwPolicyLocateResource
;import KeI386Call16BitCStyleFunction
;import Kei386EoiHelper
;import KeI386MachineType
;import KeIcacheFlushCount
;import KeInitializeAffinityEx
;import KeInitializeEnumerationContextFromGroup
;import KeInitializeSecondaryInterruptServices
;import KeInitializeTimer2
;import KeInterlockedClearProcessorAffinityEx
;import KeIsSingleGroupAffinityEx
;import KeLastBranchMSR
;import KeLoaderBlock
;import KeLoadMTRR
;import KeNotifyProcessorFreezeSupported
;import KeNumberProcessors
;import KeOrAffinityEx
;import KeProcessorGroupAffinity
;import KeQueryActiveProcessorAffinity
;import KeQueryEffectivePriorityThread
;import KeQueryGroupAffinityEx
;import KeQueryHeteroCpuPolicyThread
;import KeQueryMultiThreadProcessorSet
;import KeRemoveGroupAffinityEx
;import KeRemoveProcessorAffinityEx
;import KeRemoveProcessorGroupAffinity
;import KeRemoveQueueDpcEx
;import KeReportCacheIncoherentDevice
;import KeRevertToUserAffinityThread
;import KeServiceDescriptorTable
;import KeSetActualBasePriorityThread
;import KeSetHeteroCpuPolicyThread
;import KeSetSelectedCpuSetsThread
;import KeSetTimer2
;import KeSignalCallDpcDone
;import KeSignalCallDpcSynchronize
;import KeStallWhileFrozen
;import KeStartDynamicProcessor
;import KeSubtractAffinityEx
;import KeSweepLocalCaches
;import KeSynchronizeTimeToQpc
;import KeSystemFullyCacheCoherent
;import KeTickCount
;import KeUpdateSystemTime
;import KeUpdateTime
;import KeUpdateThreadTag
;import KeUpdateTimeAssist
;import KeWriteProtectPAT
;import KfRaiseIrql
;import KiBugCheckData
;import KiCheckForSListAddress
;import KiCpuId
;import KiDispatchInterrupt
;import KiEnableTimerWatchdog
;import KitLogFeatureUsage
;import KiUnexpectedInterrupt
;import KseQueryDeviceData
;import KseQueryDeviceDataList
;import KseQueryDeviceFlags
;import KseRegisterShim
;import KseRegisterShimEx
;import KseSetDeviceFlags
;import KseUnregisterShim
;import LdrFindResourceEx_U
;import LdrResFindResource
;import LdrResFindResourceDirectory
;import LdrResSearchResource
;import LpcPortObjectType
;import LpcReplyWaitReplyPort
;import LpcSendWaitReceivePort
;import Mm64BitPhysicalAddress
;import MmAddVerifierSpecialThunks
;import MmAreMdlPagesCached
;import MmBadPointer
;import MmChangeImageProtection
;import MmGetCacheAttribute
;import MmHighestUserAddress
;import MmMapViewInSessionSpaceEx
;import MmMapViewInSystemSpaceEx
;import MmMdlPageContentsState
;import MmPrefetchVirtualAddresses
;import MmSectionObjectType
;import MmSetUserExceptionCallout
;import MmSystemRangeStart
;import MmUserProbeAddress
;import NlsAnsiCodePage
;import NlsLeadByteInfo
;import NlsMbCodePageTag
;import NlsMbOemCodePageTag
;import NlsOemCodePage
;import NtBuildGUID
;import NtBuildLab
;import NtBuildNumber
;import NtGetEnvironmentVariableEx
;import NtGlobalFlag
;import NtQueryEnvironmentVariableInfoEx
;import NtSetCachedSigningLevel
;import NtSetInformationVirtualMemory
;import ObfDereferenceObjectWithTag
;import ObGetObjectType
;import ObOpenObjectByNameEx
;import ObReferenceObjectSafeWithTag
;import ObWaitForMultipleObjects
;import PfFileInfoNotify
;import PoAllProcessorsDeepIdle
;import PoCpuIdledSinceLastCallImprecise
;import PoDisableSleepStates
;import PoFxProcessorNotification
;import PoEnergyEstimationEnabled
;import PoFxEnableDStateReporting
;import PoFxRegisterCoreDevice
;import PoFxRegisterPlugin
;import PoFxRegisterPluginEx
;import PoFxRegisterPrimaryDevice
;import PoGetProcessorIdleAccounting
;import POGOBuffer
;import PoInitiateProcessorWake
;import PoLatencySensitivityHint
;import PoNotifyDisableDynamicTick
;import PoNotifyMediaBuffering
;import PoNotifyVSyncChange
;import PoQueueShutdownWorkItem
;import PoReenableSleepStates
;import PoRegisterCoalescingCallback
;import PoSetFixedWakeSource
;import PoSetUserPresent
;import PoSetSystemWakeDevice
;import PoUnregisterCoalescingCallback
;import PoUserShutdownCancelled
;import PoUserShutdownInitiated
;import PsChargeProcessCpuCycles
;import PsChargeProcessWakeCounter
;import PsDereferenceKernelStack
;import PsEnterPriorityRegion
;import PsGetCurrentProcessWow64Process
;import PsGetCurrentThreadWin32ThreadAndEnterCriticalRegion
;import PsGetEffectiveContainerId
;import PsGetJobProperty
;import PsGetProcessCommonJob
;import PsGetProcessProtection
;import PsGetProcessServerSilo
;import PsGetProcessSessionIdEx
;import PsGetProcessSignatureLevel
;import PsGetSiloIdentifier
;import PsInitialSystemProcess
;import PsIsProcessInAppSilo
;import PsIsProtectedProcess
;import PsIsProtectedProcessLight
;import PsJobType
;import PsLeavePriorityRegion
;import psMUITest
;import PsLoadedModuleList
;import PsLoadedModuleResource
;import PsUpdateComponentPower
;import PsQueryProcessAttributesByToken
;import PsQueryProcessExceptionFlags
;import PsReferenceKernelStack
;import PsReleaseProcessExitSynchronization
;import PsReleaseProcessWakeCounter
;import PsSetCreateProcessNotifyRoutineEx2
;import PsSetJobProperty
;import PsSetThreadProperty
;import PsUILanguageComitted
;import RtlAddAccessAllowedObjectAce
;import RtlAddAtomToAtomTableEx
;import RtlAddProcessTrustLabelAce
;import RtlAddResourceAttributeAce
;import RtlAreBitsClearEx
;import RtlAreBitsSetEx
;import RtlAvlInsertNodeEx
;import RtlAvlRemoveNode
;import RtlCapabilityCheck
;import RtlCheckTokenCapability
;import RtlCheckTokenMembership
;import RtlCheckTokenMembershipEx
;import RtlClearAllBitsEx
;import RtlClearBitEx
;import RtlClearBitsEx
;import RtlContractHashTable
;import RtlCopyBitMap
;import RtlCopyMemoryNonTemporal
;import RtlCrc32
;import RtlCrc64
;import RtlCreateAtomTableEx
;import RtlCreateHashTable
;import RtlCreateHashTableEx
;import RtlDeleteHashTable
;import RtlEndEnumerationHashTable
;import RtlEndWeakEnumerationHashTable
;import RtlEnumerateEntryHashTable
;import RtlEqualWnfChangeStamps
;import RtlExpandHashTable
;import RtlExtractBitMap
;import RtlFindAceByType
;import RtlFindClearBitsAndSetEx
;import RtlFindClearBitsEx
;import RtlFindClosestEncodableLength
;import RtlFindExportedRoutineByName
;import RtlFindNextForwardRunClearEx
;import RtlFindSetBitsAndClearEx
;import RtlFindSetBitsEx
;import RtlGenerateClass5Guid
;import RtlGetAppContainerNamedObjectPath
;import RtlGetAppContainerParent
;import RtlGetAppContainerSidType
;import RtlGetIntegerAtom
;import RtlGetLastRange
;import RtlGetProductInfo
;import RtlIdnToAscii
;import RtlIdnToNameprepUnicode
;import RtlIdnToUnicode
;import RtlImageNtHeaderEx
;import RtlInitializeBitMapEx
;import RtlInterlockedClearBitRun
;import RtlInterlockedSetBitRun
;import RtlInterlockedSetClearRun
;import RtlInvertRangeListEx
;import RtlIsMultiSessionSku
;import RtlIsSandboxedToken
;import RtlIsUntrustedObject
;import RtlLCIDToCultureName
;import RtlLoadString
;import RtlNormalizeString
;import RtlNumberOfClearBitsEx
;import RtlNumberOfClearBitsInRange
;import RtlNumberOfSetBitsEx
;import RtlNumberOfSetBitsInRange
;import RtlOwnerAcesPresent
;import RtlQueryDynamicTimeZoneInformation
;import RtlQueryModuleInformation
;import RtlQueryPackageClaims
;import RtlQueryPackageIdentity
;import RtlQueryRegistryValuesEx
;import RtlQueryValidationRunlevel
;import RtlRbReplaceNode
;import RtlRemoveEntryHashTable
;import RtlReplaceSidInSd
;import RtlSetAllBitsEx
;import RtlSetBitEx
;import RtlSetBitsEx
;import RtlSetDynamicTimeZoneInformation
;import RtlSetPortableOperatingSystem
;import RtlSidHashInitialize
;import RtlSidHashLookup
;import RtlTestBitEx
;import RtlWeaklyEnumerateEntryHashTable
;import SeAccessCheckFromState
;import SeAccessCheckFromStateEx
;import SeAccessCheckWithHint
;import SeAuditingAnyFileEventsWithContextEx
;import SeAuditingFileEventsWithContextEx
;import SeAuditingWithTokenForSubcategory
;import SeCloseObjectAuditAlarmForNonObObject
;import SeCompareSigningLevels
;import SeCreateClientSecurityEx
;import SeCreateClientSecurityFromSubjectContextEx
;import SeExports
;import SeGetCachedSigningLevel
;import SeGetLinkedToken
;import SeGetLogonSessionToken
;import SeIsParentOfChildAppContainer
;import SeOpenObjectAuditAlarmForNonObObject
;import SeOpenObjectAuditAlarmWithTransaction
;import SePublicDefaultDacl
;import SeQuerySecureBootPolicyValue
;import SeQuerySecurityAttributesToken
;import SeRegisterImageVerificationCallback
;import SeSecurityAttributePresent
;import SeSetAuthorizationCallbacks
;import SeSetSecurityAttributesToken
;import SeSetSecurityAttributesTokenEx
;import SeSrpAccessCheck
;import SeSystemDefaultDacl
;import SeSystemDefaultSd
;import SeTokenFromAccessInformation
;import SeUnregisterImageVerificationCallback
;import SkAcquirePushLockExclusive
;import SkAllocatePool
;import SkFreePool
;import SkInitializePushLock
;import SkIsSecureKernel
;import SkQuerySecureKernelInformation
;import SkReleasePushLockExclusive
;import sprintf
;import sprintf_s
;import sqrt
;import sqrtf
;import srand
;import sscanf_s
;import strcat
;import strcat_s
;import strchr
;import strcmp
;import strcpy
;import strcpy_s
;import strlen
;import strncat
;import strncat_s
;import strncmp
;import strncpy
;import strncpy_s
;import strnlen
;import strrchr
;import strspn
;import strstr
;import strtok_s
;import swprintf
;import swprintf_s
;import swscanf_s
;import TmCancelPropagationRequest
;import TmCurrentTransaction
;import TmEndPropagationRequest
;import TmEnlistmentObjectType
;import TmFreezeTransactions
;import TmInitializeResourceManager
;import TmInitializeTransaction
;import TmInitSystem
;import TmInitSystemPhase2
;import TmIsKTMCommitCoordinator
;import TmpIsKTMCommitCoordinator
;import TmPropagationComplete
;import TmPropagationFailed
;import TmResourceManagerObjectType
;import TmSetCurrentTransaction
;import TmThawTransactions
;import TmTransactionManagerObjectType
;import TmTransactionObjectType
;import VfCheckNxPagePriority
;import VfCheckNxPageProtection
;import VfCheckNxPoolType
;import VfFailDeviceNode
;import VfFailDriver
;import VfFailSystemBIOS
;import VfInsertContext
;import VfQueryDeviceContext
;import VfQueryDispatchTable
;import VfQueryDriverContext
;import VfQueryIrpContext
;import VfQueryThreadContext
;import VfRemoveContext
;import VmAccessFault
;import VmCreateMemoryRange
;import VmDeleteMemoryRange
;import VslExchangeEntropy
;import VslRetrieveMailbox
;import WheaAttemptPhysicalPageOffline
;import WheaConfigureErrorSource
;import WheaDeferredRecoveryService
;import WheaGetErrorSource
;import WheaInitializeDeferredRecoveryObject
;import WheaInitializeRecordHeader
;import WheaRegisterErrSrcInitializer
;import WheaReportHwError
;import WheaRequestDeferredRecovery
;import ZwAlpcConnectPortEx
;import ZwCreateWnfStateName
;import ZwDeleteDriverEntry
;import ZwDeleteWnfStateData
;import ZwDeleteWnfStateName
;import ZwNotifyChangeSession
;import ZwQueryLicenseValue
;import ZwQueryWnfStateData
;import ZwQueryWnfStateNameInformation
;import ZwSetCachedSigningLevel
;import ZwSetInformationVirtualMemory
;import ZwUpdateWnfStateData
;import _abnormal_termination
;import _alloca_probe
;import _alloca_probe_16
;import _alloca_probe_8
;import _CIcos
;import _CIsin
;import _CIsqrt
;import _local_unwind
;#ifndef __misaligned_access
;    import __misaligned_access
;#endif
;import _snscanf_s
;import _snwprintf
;import _snwprintf_s
;import _snwscanf_s

#endif ;NTOSKRNL_INC
