; ========================================================;
;                                                         ;
;      ntoskrnl.inc for EC v2 SolAsm visual projects      ;
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

#ifdef APP_WIN64
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
#else
    extern CcCanIWrite alias _CcCanIWrite@16
    extern CcCopyRead alias _CcCopyRead@24
    extern CcCopyWrite alias _CcCopyWrite@20
    extern CcDeferWrite alias _CcDeferWrite@24
    extern CcFastCopyRead alias _CcFastCopyRead@24
    extern CcFastCopyWrite alias _CcFastCopyWrite@16
    extern CcFastMdlReadWait alias _CcFastMdlReadWait@4
    extern CcFastReadNotPossible alias _CcFastReadNotPossible@4
    extern CcFastReadWait alias _CcFastReadWait@4
    extern CcFlushCache alias _CcFlushCache@16
    extern CcGetDirtyPages alias _CcGetDirtyPages@16
    extern CcGetFileObjectFromBcb alias _CcGetFileObjectFromBcb@4
    extern CcGetFileObjectFromSectionPtrs alias _CcGetFileObjectFromSectionPtrs@4
    extern CcGetFlushedValidData alias _CcGetFlushedValidData@8
    extern CcGetLsnForFileObject alias _CcGetLsnForFileObject@8
    extern CcInitializeCacheMap alias _CcInitializeCacheMap@20
    extern CcIsThereDirtyData alias _CcIsThereDirtyData@4
    extern CcMapData alias _CcMapData@24
    extern CcMdlRead alias _CcMdlRead@20
    extern CcMdlReadComplete alias _CcMdlReadComplete@8
    extern CcMdlWriteAbort alias _CcMdlWriteAbort@8
    extern CcMdlWriteComplete alias _CcMdlWriteComplete@12
    extern CcPinMappedData alias _CcPinMappedData@20
    extern CcPinRead alias _CcPinRead@24
    extern CcPrepareMdlWrite alias _CcPrepareMdlWrite@20
    extern CcPreparePinWrite alias _CcPreparePinWrite@28
    extern CcPurgeCacheSection alias _CcPurgeCacheSection@16
    extern CcRemapBcb alias _CcRemapBcb@4
    extern CcRepinBcb alias _CcRepinBcb@4
    extern CcScheduleReadAhead alias _CcScheduleReadAhead@12
    extern CcSetAdditionalCacheAttributes alias _CcSetAdditionalCacheAttributes@12
    extern CcSetBcbOwnerPointer alias _CcSetBcbOwnerPointer@8
    extern CcSetDirtyPageThreshold alias _CcSetDirtyPageThreshold@8
    extern CcSetDirtyPinnedData alias _CcSetDirtyPinnedData@8
    extern CcSetFileSizes alias _CcSetFileSizes@8
    extern CcSetLogHandleForFile alias _CcSetLogHandleForFile@12
    extern CcSetReadAheadGranularity alias _CcSetReadAheadGranularity@8
    extern CcUninitializeCacheMap alias _CcUninitializeCacheMap@12
    extern CcUnpinData alias _CcUnpinData@4
    extern CcUnpinDataForThread alias _CcUnpinDataForThread@8
    extern CcUnpinRepinnedBcb alias _CcUnpinRepinnedBcb@12
    extern CcWaitForCurrentLazyWriterActivity alias _CcWaitForCurrentLazyWriterActivity@0
    extern CcZeroData alias _CcZeroData@16
    extern CmRegisterCallback alias _CmRegisterCallback@12
    extern CmUnRegisterCallback alias _CmUnRegisterCallback@8
    extern DbgBreakPoint alias _DbgBreakPoint@0
    extern DbgBreakPointWithStatus alias _DbgBreakPointWithStatus@4
    extern DbgLoadImageSymbols alias _DbgLoadImageSymbols@12
    extern DbgPrint alias _DbgPrint@4
    extern DbgPrintEx alias _DbgPrintEx@4
    extern DbgPrintReturnControlC alias _DbgPrintReturnControlC@4
    extern DbgPrompt alias _DbgPrompt@12
    extern DbgQueryDebugFilterState alias _DbgQueryDebugFilterState@8
    extern DbgSetDebugFilterState alias _DbgSetDebugFilterState@12
    extern ExAcquireResourceExclusiveLite alias _ExAcquireResourceExclusiveLite@8
    extern ExAcquireResourceSharedLite alias _ExAcquireResourceSharedLite@8
    extern ExAcquireSharedStarveExclusive alias _ExAcquireSharedStarveExclusive@8
    extern ExAcquireSharedWaitForExclusive alias _ExAcquireSharedWaitForExclusive@8
    extern ExAllocateFromPagedLookasideList alias _ExAllocateFromPagedLookasideList@4
    extern ExAllocatePool alias _ExAllocatePool@8
    extern ExAllocatePoolWithQuota alias _ExAllocatePoolWithQuota@8
    extern ExAllocatePoolWithQuotaTag alias _ExAllocatePoolWithQuotaTag@12
    extern ExAllocatePoolWithTag alias _ExAllocatePoolWithTag@12
    extern ExAllocatePoolWithTagPriority alias _ExAllocatePoolWithTagPriority@16
    extern ExConvertExclusiveToSharedLite alias _ExConvertExclusiveToSharedLite@4
    extern ExCreateCallback alias _ExCreateCallback@16
    extern ExDeleteNPagedLookasideList alias _ExDeleteNPagedLookasideList@4
    extern ExDeletePagedLookasideList alias _ExDeletePagedLookasideList@4
    extern ExDeleteResourceLite alias _ExDeleteResourceLite@4
    extern ExDesktopObjectType alias _ExDesktopObjectType@4
    extern ExDisableResourceBoostLite alias _ExDisableResourceBoostLite@4
    extern ExEnumHandleTable alias _ExEnumHandleTable@16
    extern ExEventObjectType alias _ExEventObjectType@4
    extern ExExtendZone alias _ExExtendZone@12
    extern ExFreePool alias _ExFreePool@4
    extern ExFreePoolWithTag alias _ExFreePoolWithTag@8
    extern ExFreeToPagedLookasideList alias _ExFreeToPagedLookasideList@8
    extern ExGetCurrentProcessorCounts alias _ExGetCurrentProcessorCounts@12
    extern ExGetCurrentProcessorCpuUsage alias _ExGetCurrentProcessorCpuUsage@4
    extern ExGetExclusiveWaiterCount alias _ExGetExclusiveWaiterCount@4
    extern ExGetPreviousMode alias _ExGetPreviousMode@0
    extern ExGetSharedWaiterCount alias _ExGetSharedWaiterCount@4
    extern ExInitializeNPagedLookasideList alias _ExInitializeNPagedLookasideList@28
    extern ExInitializePagedLookasideList alias _ExInitializePagedLookasideList@28
    extern ExInitializeResourceLite alias _ExInitializeResourceLite@4
    extern ExInitializeZone alias _ExInitializeZone@16
    extern ExInterlockedAddLargeInteger alias _ExInterlockedAddLargeInteger@16
    extern ExInterlockedAddUlong alias _ExInterlockedAddUlong@12
    extern ExInterlockedDecrementLong alias _ExInterlockedDecrementLong@8
    extern ExInterlockedExchangeUlong alias _ExInterlockedExchangeUlong@12
    extern ExInterlockedExtendZone alias _ExInterlockedExtendZone@16
    extern ExInterlockedIncrementLong alias _ExInterlockedIncrementLong@8
    extern ExInterlockedInsertHeadList alias _ExInterlockedInsertHeadList@12
    extern ExInterlockedInsertTailList alias _ExInterlockedInsertTailList@12
    extern ExInterlockedPopEntryList alias _ExInterlockedPopEntryList@8
    extern ExInterlockedPushEntryList alias _ExInterlockedPushEntryList@12
    extern ExInterlockedRemoveHeadList alias _ExInterlockedRemoveHeadList@8
    extern ExIsProcessorFeaturePresent alias _ExIsProcessorFeaturePresent@4
    extern ExIsResourceAcquiredExclusiveLite alias _ExIsResourceAcquiredExclusiveLite@4
    extern ExIsResourceAcquiredSharedLite alias _ExIsResourceAcquiredSharedLite@4
    extern ExLocalTimeToSystemTime alias _ExLocalTimeToSystemTime@8
    extern ExNotifyCallback alias _ExNotifyCallback@12
    extern ExQueryPoolBlockSize alias _ExQueryPoolBlockSize@8
    extern ExQueueWorkItem alias _ExQueueWorkItem@8
    extern ExRaiseAccessViolation alias _ExRaiseAccessViolation@0
    extern ExRaiseDatatypeMisalignment alias _ExRaiseDatatypeMisalignment@0
    extern ExRaiseException alias _ExRaiseException@4
    extern ExRaiseHardError alias _ExRaiseHardError@24
    extern ExRaiseStatus alias _ExRaiseStatus@4
    extern ExRegisterCallback alias _ExRegisterCallback@12
    extern ExReinitializeResourceLite alias _ExReinitializeResourceLite@4
    extern ExReleaseResourceForThreadLite alias _ExReleaseResourceForThreadLite@8
    extern ExSemaphoreObjectType alias _ExSemaphoreObjectType@4
    extern ExSetResourceOwnerPointer alias _ExSetResourceOwnerPointer@8
    extern ExSetTimerResolution alias _ExSetTimerResolution@8
    extern ExSystemExceptionFilter alias _ExSystemExceptionFilter@0
    extern ExSystemTimeToLocalTime alias _ExSystemTimeToLocalTime@8
    extern ExUnregisterCallback alias _ExUnregisterCallback@4
    extern ExUuidCreate alias _ExUuidCreate@4
    extern ExVerifySuite alias _ExVerifySuite@4
    extern ExWindowStationObjectType alias _ExWindowStationObjectType@4
    extern Exi386InterlockedDecrementLong alias _Exi386InterlockedDecrementLong@4
    extern Exi386InterlockedExchangeUlong alias _Exi386InterlockedExchangeUlong@8
    extern Exi386InterlockedIncrementLong alias _Exi386InterlockedIncrementLong@4
    extern FsRtlAcquireFileExclusive alias _FsRtlAcquireFileExclusive@4
    extern FsRtlAddLargeMcbEntry alias _FsRtlAddLargeMcbEntry@28
    extern FsRtlAddMcbEntry alias _FsRtlAddMcbEntry@16
    extern FsRtlAddToTunnelCache alias _FsRtlAddToTunnelCache@32
    extern FsRtlAllocateFileLock alias _FsRtlAllocateFileLock@8
    extern FsRtlAllocatePool alias _FsRtlAllocatePool@8
    extern FsRtlAllocatePoolWithQuota alias _FsRtlAllocatePoolWithQuota@8
    extern FsRtlAllocatePoolWithQuotaTag alias _FsRtlAllocatePoolWithQuotaTag@12
    extern FsRtlAllocatePoolWithTag alias _FsRtlAllocatePoolWithTag@12
    extern FsRtlAllocateResource alias _FsRtlAllocateResource@0
    extern FsRtlAreNamesEqual alias _FsRtlAreNamesEqual@16
    extern FsRtlBalanceReads alias _FsRtlBalanceReads@4
    extern FsRtlCheckLockForReadAccess alias _FsRtlCheckLockForReadAccess@8
    extern FsRtlCheckLockForWriteAccess alias _FsRtlCheckLockForWriteAccess@8
    extern FsRtlCheckOplock alias _FsRtlCheckOplock@20
    extern FsRtlCopyRead alias _FsRtlCopyRead@32
    extern FsRtlCopyWrite alias _FsRtlCopyWrite@32
    extern FsRtlCurrentBatchOplock alias _FsRtlCurrentBatchOplock@4
    extern FsRtlDeleteKeyFromTunnelCache alias _FsRtlDeleteKeyFromTunnelCache@12
    extern FsRtlDeleteTunnelCache alias _FsRtlDeleteTunnelCache@4
    extern FsRtlDeregisterUncProvider alias _FsRtlDeregisterUncProvider@4
    extern FsRtlDissectDbcs alias _FsRtlDissectDbcs@16
    extern FsRtlDissectName alias _FsRtlDissectName@16
    extern FsRtlDoesDbcsContainWildCards alias _FsRtlDoesDbcsContainWildCards@4
    extern FsRtlDoesNameContainWildCards alias _FsRtlDoesNameContainWildCards@4
    extern FsRtlFastCheckLockForRead alias _FsRtlFastCheckLockForRead@24
    extern FsRtlFastCheckLockForWrite alias _FsRtlFastCheckLockForWrite@24
    extern FsRtlFastUnlockAll alias _FsRtlFastUnlockAll@16
    extern FsRtlFastUnlockAllByKey alias _FsRtlFastUnlockAllByKey@20
    extern FsRtlFastUnlockSingle alias _FsRtlFastUnlockSingle@32
    extern FsRtlFindInTunnelCache alias _FsRtlFindInTunnelCache@32
    extern FsRtlFreeFileLock alias _FsRtlFreeFileLock@4
    extern FsRtlGetFileSize alias _FsRtlGetFileSize@8
    extern FsRtlGetNextFileLock alias _FsRtlGetNextFileLock@8
    extern FsRtlGetNextLargeMcbEntry alias _FsRtlGetNextLargeMcbEntry@20
    extern FsRtlGetNextMcbEntry alias _FsRtlGetNextMcbEntry@20
    extern FsRtlIncrementCcFastReadNoWait alias _FsRtlIncrementCcFastReadNoWait@0
    extern FsRtlIncrementCcFastReadNotPossible alias _FsRtlIncrementCcFastReadNotPossible@0
    extern FsRtlIncrementCcFastReadResourceMiss alias _FsRtlIncrementCcFastReadResourceMiss@0
    extern FsRtlIncrementCcFastReadWait alias _FsRtlIncrementCcFastReadWait@0
    extern FsRtlInitializeFileLock alias _FsRtlInitializeFileLock@12
    extern FsRtlInitializeLargeMcb alias _FsRtlInitializeLargeMcb@8
    extern FsRtlInitializeMcb alias _FsRtlInitializeMcb@8
    extern FsRtlInitializeOplock alias _FsRtlInitializeOplock@4
    extern FsRtlInitializeTunnelCache alias _FsRtlInitializeTunnelCache@4
    extern FsRtlInsertPerFileObjectContext alias _FsRtlInsertPerFileObjectContext@8
    extern FsRtlInsertPerStreamContext alias _FsRtlInsertPerStreamContext@8
    extern FsRtlIsDbcsInExpression alias _FsRtlIsDbcsInExpression@8
    extern FsRtlIsFatDbcsLegal alias _FsRtlIsFatDbcsLegal@20
    extern FsRtlIsHpfsDbcsLegal alias _FsRtlIsHpfsDbcsLegal@20
    extern FsRtlIsNameInExpression alias _FsRtlIsNameInExpression@16
    extern FsRtlIsNtstatusExpected alias _FsRtlIsNtstatusExpected@4
    extern FsRtlIsPagingFile alias _FsRtlIsPagingFile@4
    extern FsRtlIsTotalDeviceFailure alias _FsRtlIsTotalDeviceFailure@4
    extern FsRtlLegalAnsiCharacterArray alias _FsRtlLegalAnsiCharacterArray@4
    extern FsRtlLookupLargeMcbEntry alias _FsRtlLookupLargeMcbEntry@32
    extern FsRtlLookupLastLargeMcbEntry alias _FsRtlLookupLastLargeMcbEntry@12
    extern FsRtlLookupLastLargeMcbEntryAndIndex alias _FsRtlLookupLastLargeMcbEntryAndIndex@16
    extern FsRtlLookupLastMcbEntry alias _FsRtlLookupLastMcbEntry@12
    extern FsRtlLookupMcbEntry alias _FsRtlLookupMcbEntry@20
    extern FsRtlLookupPerFileObjectContext alias _FsRtlLookupPerFileObjectContext@12
    extern FsRtlLookupPerStreamContextInternal alias _FsRtlLookupPerStreamContextInternal@12
    extern FsRtlMdlRead alias _FsRtlMdlRead@24
    extern FsRtlMdlReadComplete alias _FsRtlMdlReadComplete@8
    extern FsRtlMdlReadCompleteDev alias _FsRtlMdlReadCompleteDev@12
    extern FsRtlMdlReadDev alias _FsRtlMdlReadDev@28
    extern FsRtlMdlWriteComplete alias _FsRtlMdlWriteComplete@12
    extern FsRtlMdlWriteCompleteDev alias _FsRtlMdlWriteCompleteDev@16
    extern FsRtlNormalizeNtstatus alias _FsRtlNormalizeNtstatus@8
    extern FsRtlNotifyChangeDirectory alias _FsRtlNotifyChangeDirectory@28
    extern FsRtlNotifyCleanup alias _FsRtlNotifyCleanup@12
    extern FsRtlNotifyFilterChangeDirectory alias _FsRtlNotifyFilterChangeDirectory@44
    extern FsRtlNotifyFilterReportChange alias _FsRtlNotifyFilterReportChange@40
    extern FsRtlNotifyFullChangeDirectory alias _FsRtlNotifyFullChangeDirectory@40
    extern FsRtlNotifyFullReportChange alias _FsRtlNotifyFullReportChange@36
    extern FsRtlNotifyInitializeSync alias _FsRtlNotifyInitializeSync@4
    extern FsRtlNotifyReportChange alias _FsRtlNotifyReportChange@20
    extern FsRtlNotifyUninitializeSync alias _FsRtlNotifyUninitializeSync@4
    extern FsRtlNotifyVolumeEvent alias _FsRtlNotifyVolumeEvent@8
    extern FsRtlNumberOfRunsInLargeMcb alias _FsRtlNumberOfRunsInLargeMcb@4
    extern FsRtlNumberOfRunsInMcb alias _FsRtlNumberOfRunsInMcb@4
    extern FsRtlOplockFsctrl alias _FsRtlOplockFsctrl@12
    extern FsRtlOplockIsFastIoPossible alias _FsRtlOplockIsFastIoPossible@4
    extern FsRtlPostPagingFileStackOverflow alias _FsRtlPostPagingFileStackOverflow@12
    extern FsRtlPostStackOverflow alias _FsRtlPostStackOverflow@12
    extern FsRtlPrepareMdlWrite alias _FsRtlPrepareMdlWrite@24
    extern FsRtlPrepareMdlWriteDev alias _FsRtlPrepareMdlWriteDev@28
    extern FsRtlPrivateLock alias _FsRtlPrivateLock@48
    extern FsRtlProcessFileLock alias _FsRtlProcessFileLock@12
    extern FsRtlRegisterFileSystemFilterCallbacks alias _FsRtlRegisterFileSystemFilterCallbacks@8
    extern FsRtlRegisterUncProvider alias _FsRtlRegisterUncProvider@12
    extern FsRtlReleaseFile alias _FsRtlReleaseFile@4
    extern FsRtlRemoveLargeMcbEntry alias _FsRtlRemoveLargeMcbEntry@20
    extern FsRtlRemoveMcbEntry alias _FsRtlRemoveMcbEntry@12
    extern FsRtlRemovePerFileObjectContext alias _FsRtlRemovePerFileObjectContext@12
    extern FsRtlRemovePerStreamContext alias _FsRtlRemovePerStreamContext@12
    extern FsRtlResetLargeMcb alias _FsRtlResetLargeMcb@8
    extern FsRtlSplitLargeMcb alias _FsRtlSplitLargeMcb@20
    extern FsRtlSyncVolumes alias _FsRtlSyncVolumes@12
    extern FsRtlTeardownPerStreamContexts alias _FsRtlTeardownPerStreamContexts@4
    extern FsRtlTruncateLargeMcb alias _FsRtlTruncateLargeMcb@12
    extern FsRtlTruncateMcb alias _FsRtlTruncateMcb@8
    extern FsRtlUninitializeFileLock alias _FsRtlUninitializeFileLock@4
    extern FsRtlUninitializeLargeMcb alias _FsRtlUninitializeLargeMcb@4
    extern FsRtlUninitializeMcb alias _FsRtlUninitializeMcb@4
    extern FsRtlUninitializeOplock alias _FsRtlUninitializeOplock@4
    extern HalDispatchTable alias _HalDispatchTable@4
    extern HalPrivateDispatchTable alias _HalPrivateDispatchTable@4
    extern HeadlessDispatch alias _HeadlessDispatch@20
    extern InbvAcquireDisplayOwnership alias _InbvAcquireDisplayOwnership@0
    extern InbvCheckDisplayOwnership alias _InbvCheckDisplayOwnership@0
    extern InbvDisplayString alias _InbvDisplayString@4
    extern InbvEnableBootDriver alias _InbvEnableBootDriver@4
    extern InbvEnableDisplayString alias _InbvEnableDisplayString@4
    extern InbvInstallDisplayStringFilter alias _InbvInstallDisplayStringFilter@4
    extern InbvIsBootDriverInstalled alias _InbvIsBootDriverInstalled@0
    extern InbvNotifyDisplayOwnershipLost alias _InbvNotifyDisplayOwnershipLost@4
    extern InbvResetDisplay alias _InbvResetDisplay@0
    extern InbvSetScrollRegion alias _InbvSetScrollRegion@16
    extern InbvSetTextColor alias _InbvSetTextColor@4
    extern InbvSolidColorFill alias _InbvSolidColorFill@20
    extern InitSafeBootMode alias _InitSafeBootMode@4
    extern IoAcquireCancelSpinLock alias _IoAcquireCancelSpinLock@4
    extern IoAcquireRemoveLockEx alias _IoAcquireRemoveLockEx@20
    extern IoAcquireVpbSpinLock alias _IoAcquireVpbSpinLock@4
    extern IoAdapterObjectType alias _IoAdapterObjectType@4
    extern IoAllocateAdapterChannel alias _IoAllocateAdapterChannel@20
    extern IoAllocateController alias _IoAllocateController@16
    extern IoAllocateDriverObjectExtension alias _IoAllocateDriverObjectExtension@16
    extern IoAllocateErrorLogEntry alias _IoAllocateErrorLogEntry@8
    extern IoAllocateIrp alias _IoAllocateIrp@8
    extern IoAllocateMdl alias _IoAllocateMdl@20
    extern IoAllocateWorkItem alias _IoAllocateWorkItem@4
    extern IoAssignResources alias _IoAssignResources@24
    extern IoAttachDevice alias _IoAttachDevice@12
    extern IoAttachDeviceByPointer alias _IoAttachDeviceByPointer@8
    extern IoAttachDeviceToDeviceStack alias _IoAttachDeviceToDeviceStack@8
    extern IoAttachDeviceToDeviceStackSafe alias _IoAttachDeviceToDeviceStackSafe@12
    extern IoBuildAsynchronousFsdRequest alias _IoBuildAsynchronousFsdRequest@24
    extern IoBuildDeviceIoControlRequest alias _IoBuildDeviceIoControlRequest@36
    extern IoBuildPartialMdl alias _IoBuildPartialMdl@16
    extern IoBuildSynchronousFsdRequest alias _IoBuildSynchronousFsdRequest@28
    extern IoCallDriver alias _IoCallDriver@8
    extern IoCancelFileOpen alias _IoCancelFileOpen@8
    extern IoCancelIrp alias _IoCancelIrp@4
    extern IoCheckDesiredAccess alias _IoCheckDesiredAccess@8
    extern IoCheckEaBufferValidity alias _IoCheckEaBufferValidity@12
    extern IoCheckFunctionAccess alias _IoCheckFunctionAccess@24
    extern IoCheckQuerySetFileInformation alias _IoCheckQuerySetFileInformation@12
    extern IoCheckQuerySetVolumeInformation alias _IoCheckQuerySetVolumeInformation@12
    extern IoCheckQuotaBufferValidity alias _IoCheckQuotaBufferValidity@12
    extern IoCheckShareAccess alias _IoCheckShareAccess@20
    extern IoCompleteRequest alias _IoCompleteRequest@8
    extern IoConnectInterrupt alias _IoConnectInterrupt@44
    extern IoCreateController alias _IoCreateController@4
    extern IoCreateDevice alias _IoCreateDevice@28
    extern IoCreateDisk alias _IoCreateDisk@8
    extern IoCreateDriver alias _IoCreateDriver@8
    extern IoCreateFile alias _IoCreateFile@56
    extern IoCreateFileSpecifyDeviceObjectHint alias _IoCreateFileSpecifyDeviceObjectHint@60
    extern IoCreateNotificationEvent alias _IoCreateNotificationEvent@8
    extern IoCreateStreamFileObject alias _IoCreateStreamFileObject@8
    extern IoCreateStreamFileObjectEx alias _IoCreateStreamFileObjectEx@12
    extern IoCreateStreamFileObjectLite alias _IoCreateStreamFileObjectLite@8
    extern IoCreateSymbolicLink alias _IoCreateSymbolicLink@8
    extern IoCreateSynchronizationEvent alias _IoCreateSynchronizationEvent@8
    extern IoCreateUnprotectedSymbolicLink alias _IoCreateUnprotectedSymbolicLink@8
    extern IoCsqInitialize alias _IoCsqInitialize@28
    extern IoCsqInsertIrp alias _IoCsqInsertIrp@12
    extern IoCsqRemoveIrp alias _IoCsqRemoveIrp@8
    extern IoCsqRemoveNextIrp alias _IoCsqRemoveNextIrp@8
    extern IoDeleteController alias _IoDeleteController@4
    extern IoDeleteDevice alias _IoDeleteDevice@4
    extern IoDeleteDriver alias _IoDeleteDriver@4
    extern IoDeleteSymbolicLink alias _IoDeleteSymbolicLink@4
    extern IoDetachDevice alias _IoDetachDevice@4
    extern IoDeviceHandlerObjectSize alias _IoDeviceHandlerObjectSize@4
    extern IoDeviceHandlerObjectType alias _IoDeviceHandlerObjectType@4
    extern IoDeviceObjectType alias _IoDeviceObjectType@4
    extern IoDisconnectInterrupt alias _IoDisconnectInterrupt@4
    extern IoDriverObjectType alias _IoDriverObjectType@4
    extern IoEnqueueIrp alias _IoEnqueueIrp@4
    extern IoEnumerateDeviceObjectList alias _IoEnumerateDeviceObjectList@16
    extern IoFastQueryNetworkAttributes alias _IoFastQueryNetworkAttributes@20
    extern IoFileObjectType alias _IoFileObjectType@4
    extern IoForwardAndCatchIrp alias _IoForwardAndCatchIrp@8
    extern IoForwardIrpSynchronously alias _IoForwardIrpSynchronously@8
    extern IoFreeController alias _IoFreeController@4
    extern IoFreeErrorLogEntry alias _IoFreeErrorLogEntry@4
    extern IoFreeIrp alias _IoFreeIrp@4
    extern IoFreeMdl alias _IoFreeMdl@4
    extern IoFreeWorkItem alias _IoFreeWorkItem@4
    extern IoGetAttachedDevice alias _IoGetAttachedDevice@4
    extern IoGetAttachedDeviceReference alias _IoGetAttachedDeviceReference@4
    extern IoGetBaseFileSystemDeviceObject alias _IoGetBaseFileSystemDeviceObject@4
    extern IoGetBootDiskInformation alias _IoGetBootDiskInformation@8
    extern IoGetConfigurationInformation alias _IoGetConfigurationInformation@0
    extern IoGetCurrentProcess alias _IoGetCurrentProcess@0
    extern IoGetDeviceAttachmentBaseRef alias _IoGetDeviceAttachmentBaseRef@4
    extern IoGetDeviceInterfaceAlias alias _IoGetDeviceInterfaceAlias@12
    extern IoGetDeviceInterfaces alias _IoGetDeviceInterfaces@16
    extern IoGetDeviceObjectPointer alias _IoGetDeviceObjectPointer@16
    extern IoGetDeviceProperty alias _IoGetDeviceProperty@20
    extern IoGetDeviceToVerify alias _IoGetDeviceToVerify@4
    extern IoGetDiskDeviceObject alias _IoGetDiskDeviceObject@8
    extern IoGetDmaAdapter alias _IoGetDmaAdapter@12
    extern IoGetDriverObjectExtension alias _IoGetDriverObjectExtension@8
    extern IoGetFileObjectGenericMapping alias _IoGetFileObjectGenericMapping@0
    extern IoGetInitialStack alias _IoGetInitialStack@0
    extern IoGetLowerDeviceObject alias _IoGetLowerDeviceObject@4
    extern IoGetRelatedDeviceObject alias _IoGetRelatedDeviceObject@4
    extern IoGetRequestorProcess alias _IoGetRequestorProcess@4
    extern IoGetRequestorProcessId alias _IoGetRequestorProcessId@4
    extern IoGetRequestorSessionId alias _IoGetRequestorSessionId@8
    extern IoGetStackLimits alias _IoGetStackLimits@8
    extern IoGetTopLevelIrp alias _IoGetTopLevelIrp@0
    extern IoInitializeIrp alias _IoInitializeIrp@12
    extern IoInitializeRemoveLockEx alias _IoInitializeRemoveLockEx@20
    extern IoInitializeTimer alias _IoInitializeTimer@12
    extern IoInvalidateDeviceRelations alias _IoInvalidateDeviceRelations@8
    extern IoInvalidateDeviceState alias _IoInvalidateDeviceState@4
    extern IoIsFileOriginRemote alias _IoIsFileOriginRemote@4
    extern IoIsOperationSynchronous alias _IoIsOperationSynchronous@4
    extern IoIsSystemThread alias _IoIsSystemThread@4
    extern IoIsValidNameGraftingBuffer alias _IoIsValidNameGraftingBuffer@8
    extern IoIsWdmVersionAvailable alias _IoIsWdmVersionAvailable@8
    extern IoMakeAssociatedIrp alias _IoMakeAssociatedIrp@8
    extern IoOpenDeviceInterfaceRegistryKey alias _IoOpenDeviceInterfaceRegistryKey@12
    extern IoOpenDeviceRegistryKey alias _IoOpenDeviceRegistryKey@16
    extern IoPageRead alias _IoPageRead@20
    extern IoPnPDeliverServicePowerNotification alias _IoPnPDeliverServicePowerNotification@16
    extern IoQueryDeviceDescription alias _IoQueryDeviceDescription@32
    extern IoQueryFileDosDeviceName alias _IoQueryFileDosDeviceName@8
    extern IoQueryFileInformation alias _IoQueryFileInformation@20
    extern IoQueryVolumeInformation alias _IoQueryVolumeInformation@20
    extern IoQueueThreadIrp alias _IoQueueThreadIrp@4
    extern IoQueueWorkItem alias _IoQueueWorkItem@16
    extern IoRaiseHardError alias _IoRaiseHardError@12
    extern IoRaiseInformationalHardError alias _IoRaiseInformationalHardError@12
    extern IoReadDiskSignature alias _IoReadDiskSignature@12
    extern IoReadOperationCount alias _IoReadOperationCount@4
    extern IoReadPartitionTableEx alias _IoReadPartitionTableEx@8
    extern IoReadTransferCount alias _IoReadTransferCount@4
    extern IoRegisterBootDriverReinitialization alias _IoRegisterBootDriverReinitialization@12
    extern IoRegisterDeviceInterface alias _IoRegisterDeviceInterface@16
    extern IoRegisterDriverReinitialization alias _IoRegisterDriverReinitialization@12
    extern IoRegisterFileSystem alias _IoRegisterFileSystem@4
    extern IoRegisterFsRegistrationChange alias _IoRegisterFsRegistrationChange@8
    extern IoRegisterLastChanceShutdownNotification alias _IoRegisterLastChanceShutdownNotification@4
    extern IoRegisterPlugPlayNotification alias _IoRegisterPlugPlayNotification@28
    extern IoRegisterShutdownNotification alias _IoRegisterShutdownNotification@4
    extern IoReleaseCancelSpinLock alias _IoReleaseCancelSpinLock@4
    extern IoReleaseRemoveLockAndWaitEx alias _IoReleaseRemoveLockAndWaitEx@12
    extern IoReleaseRemoveLockEx alias _IoReleaseRemoveLockEx@12
    extern IoReleaseVpbSpinLock alias _IoReleaseVpbSpinLock@4
    extern IoRemoveShareAccess alias _IoRemoveShareAccess@8
    extern IoReportDetectedDevice alias _IoReportDetectedDevice@32
    extern IoReportHalResourceUsage alias _IoReportHalResourceUsage@16
    extern IoReportResourceForDetection alias _IoReportResourceForDetection@28
    extern IoReportResourceUsage alias _IoReportResourceUsage@36
    extern IoReportTargetDeviceChange alias _IoReportTargetDeviceChange@8
    extern IoReportTargetDeviceChangeAsynchronous alias _IoReportTargetDeviceChangeAsynchronous@16
    extern IoRequestDeviceEject alias _IoRequestDeviceEject@4
    extern IoReuseIrp alias _IoReuseIrp@8
    extern IoSetCompletionRoutineEx alias _IoSetCompletionRoutineEx@28
    extern IoSetDeviceInterfaceState alias _IoSetDeviceInterfaceState@8
    extern IoSetDeviceToVerify alias _IoSetDeviceToVerify@8
    extern IoSetFileOrigin alias _IoSetFileOrigin@8
    extern IoSetHardErrorOrVerifyDevice alias _IoSetHardErrorOrVerifyDevice@8
    extern IoSetInformation alias _IoSetInformation@16
    extern IoSetIoCompletion alias _IoSetIoCompletion@24
    extern IoSetPartitionInformationEx alias _IoSetPartitionInformationEx@12
    extern IoSetShareAccess alias _IoSetShareAccess@16
    extern IoSetStartIoAttributes alias _IoSetStartIoAttributes@12
    extern IoSetSystemPartition alias _IoSetSystemPartition@4
    extern IoSetThreadHardErrorMode alias _IoSetThreadHardErrorMode@4
    extern IoSetTopLevelIrp alias _IoSetTopLevelIrp@4
    extern IoStartNextPacket alias _IoStartNextPacket@8
    extern IoStartNextPacketByKey alias _IoStartNextPacketByKey@12
    extern IoStartPacket alias _IoStartPacket@16
    extern IoStartTimer alias _IoStartTimer@4
    extern IoStatisticsLock alias _IoStatisticsLock@4
    extern IoStopTimer alias _IoStopTimer@4
    extern IoSynchronousInvalidateDeviceRelations alias _IoSynchronousInvalidateDeviceRelations@8
    extern IoSynchronousPageWrite alias _IoSynchronousPageWrite@20
    extern IoThreadToProcess alias _IoThreadToProcess@4
    extern IoUnregisterFileSystem alias _IoUnregisterFileSystem@4
    extern IoUnregisterFsRegistrationChange alias _IoUnregisterFsRegistrationChange@8
    extern IoUnregisterPlugPlayNotification alias _IoUnregisterPlugPlayNotification@4
    extern IoUnregisterShutdownNotification alias _IoUnregisterShutdownNotification@4
    extern IoUpdateShareAccess alias _IoUpdateShareAccess@8
    extern IoValidateDeviceIoControlAccess alias _IoValidateDeviceIoControlAccess@8
    extern IoVerifyPartitionTable alias _IoVerifyPartitionTable@8
    extern IoVerifyVolume alias _IoVerifyVolume@8
    extern IoVolumeDeviceToDosName alias _IoVolumeDeviceToDosName@8
    extern IoWMIAllocateInstanceIds alias _IoWMIAllocateInstanceIds@12
    extern IoWMIDeviceObjectToInstanceName alias _IoWMIDeviceObjectToInstanceName@12
    extern IoWMIExecuteMethod alias _IoWMIExecuteMethod@24
    extern IoWMIHandleToInstanceName alias _IoWMIHandleToInstanceName@12
    extern IoWMIOpenBlock alias _IoWMIOpenBlock@12
    extern IoWMIQueryAllData alias _IoWMIQueryAllData@12
    extern IoWMIQueryAllDataMultiple alias _IoWMIQueryAllDataMultiple@16
    extern IoWMIQuerySingleInstance alias _IoWMIQuerySingleInstance@16
    extern IoWMIQuerySingleInstanceMultiple alias _IoWMIQuerySingleInstanceMultiple@20
    extern IoWMIRegistrationControl alias _IoWMIRegistrationControl@8
    extern IoWMISetNotificationCallback alias _IoWMISetNotificationCallback@12
    extern IoWMISetSingleInstance alias _IoWMISetSingleInstance@20
    extern IoWMISetSingleItem alias _IoWMISetSingleItem@24
    extern IoWMISuggestInstanceName alias _IoWMISuggestInstanceName@16
    extern IoWMIWriteEvent alias _IoWMIWriteEvent@4
    extern IoWriteErrorLogEntry alias _IoWriteErrorLogEntry@4
    extern IoWriteOperationCount alias _IoWriteOperationCount@4
    extern IoWritePartitionTableEx alias _IoWritePartitionTableEx@8
    extern IoWriteTransferCount alias _IoWriteTransferCount@4
    extern KdDebuggerEnabled alias _KdDebuggerEnabled@4
    extern KdDebuggerNotPresent alias _KdDebuggerNotPresent@4
    extern KdDisableDebugger alias _KdDisableDebugger@0
    extern KdEnableDebugger alias _KdEnableDebugger@0
    extern KdEnteredDebugger alias _KdEnteredDebugger@4
    extern KdPollBreakIn alias _KdPollBreakIn@0
    extern KdPowerTransition alias _KdPowerTransition@4
    extern Ke386CallBios alias _Ke386CallBios@8
    extern Ke386IoSetAccessProcess alias _Ke386IoSetAccessProcess@8
    extern Ke386QueryIoAccessMap alias _Ke386QueryIoAccessMap@8
    extern Ke386SetIoAccessMap alias _Ke386SetIoAccessMap@8
    extern KeAcquireInterruptSpinLock alias _KeAcquireInterruptSpinLock@4
    extern KeAcquireSpinLockAtDpcLevel alias _KeAcquireSpinLockAtDpcLevel@4
    extern KeAddSystemServiceTable alias _KeAddSystemServiceTable@20
    extern KeAreApcsDisabled alias _KeAreApcsDisabled@0
    extern KeAttachProcess alias _KeAttachProcess@4
    extern KeBugCheck alias _KeBugCheck@4
    extern KeBugCheckEx alias _KeBugCheckEx@20
    extern KeCancelTimer alias _KeCancelTimer@4
    extern KeCapturePersistentThreadState alias _KeCapturePersistentThreadState@32
    extern KeClearEvent alias _KeClearEvent@4
    extern KeConnectInterrupt alias _KeConnectInterrupt@4
    extern KeDcacheFlushCount alias _KeDcacheFlushCount@4
    extern KeDelayExecutionThread alias _KeDelayExecutionThread@12
    extern KeDeregisterBugCheckCallback alias _KeDeregisterBugCheckCallback@4
    extern KeDeregisterBugCheckReasonCallback alias _KeDeregisterBugCheckReasonCallback@4
    extern KeDetachProcess alias _KeDetachProcess@0
    extern KeDisconnectInterrupt alias _KeDisconnectInterrupt@4
    extern KeEnterCriticalRegion alias _KeEnterCriticalRegion@0
    extern KeEnterKernelDebugger alias _KeEnterKernelDebugger@0
    extern KeFindConfigurationEntry alias _KeFindConfigurationEntry@16
    extern KeFindConfigurationNextEntry alias _KeFindConfigurationNextEntry@20
    extern KeFlushEntireTb alias _KeFlushEntireTb@8
    extern KeFlushQueuedDpcs alias _KeFlushQueuedDpcs@0
    extern KeGetCurrentThread alias _KeGetCurrentThread@0
    extern KeGetPreviousMode alias _KeGetPreviousMode@0
    extern KeGetRecommendedSharedDataAlignment alias _KeGetRecommendedSharedDataAlignment@0
    extern KeI386AbiosCall alias _KeI386AbiosCall@16
    extern KeI386AllocateGdtSelectors alias _KeI386AllocateGdtSelectors@8
    extern KeI386Call16BitCStyleFunction alias _KeI386Call16BitCStyleFunction@16
    extern KeI386Call16BitFunction alias _KeI386Call16BitFunction@4
    extern KeI386FlatToGdtSelector alias _KeI386FlatToGdtSelector@12
    extern KeI386GetLid alias _KeI386GetLid@20
    extern KeI386MachineType alias _KeI386MachineType@4
    extern KeI386ReleaseGdtSelectors alias _KeI386ReleaseGdtSelectors@8
    extern KeI386ReleaseLid alias _KeI386ReleaseLid@8
    extern KeI386SetGdtSelector alias _KeI386SetGdtSelector@8
    extern KeIcacheFlushCount alias _KeIcacheFlushCount@4
    extern KeInitializeApc alias _KeInitializeApc@32
    extern KeInitializeDeviceQueue alias _KeInitializeDeviceQueue@4
    extern KeInitializeDpc alias _KeInitializeDpc@12
    extern KeInitializeEvent alias _KeInitializeEvent@12
    extern KeInitializeInterrupt alias _KeInitializeInterrupt@44
    extern KeInitializeMutant alias _KeInitializeMutant@8
    extern KeInitializeMutex alias _KeInitializeMutex@8
    extern KeInitializeQueue alias _KeInitializeQueue@8
    extern KeInitializeSemaphore alias _KeInitializeSemaphore@12
    extern KeInitializeSpinLock alias _KeInitializeSpinLock@4
    extern KeInitializeTimer alias _KeInitializeTimer@4
    extern KeInitializeTimerEx alias _KeInitializeTimerEx@8
    extern KeInsertByKeyDeviceQueue alias _KeInsertByKeyDeviceQueue@12
    extern KeInsertDeviceQueue alias _KeInsertDeviceQueue@8
    extern KeInsertHeadQueue alias _KeInsertHeadQueue@8
    extern KeInsertQueue alias _KeInsertQueue@8
    extern KeInsertQueueApc alias _KeInsertQueueApc@16
    extern KeInsertQueueDpc alias _KeInsertQueueDpc@12
    extern KeIsAttachedProcess alias _KeIsAttachedProcess@0
    extern KeIsExecutingDpc alias _KeIsExecutingDpc@0
    extern KeLeaveCriticalRegion alias _KeLeaveCriticalRegion@0
    extern KeLoaderBlock alias _KeLoaderBlock@4
    extern KeNumberProcessors alias _KeNumberProcessors@4
    extern KeProfileInterrupt alias _KeProfileInterrupt@4
    extern KeProfileInterruptWithSource alias _KeProfileInterruptWithSource@8
    extern KePulseEvent alias _KePulseEvent@12
    extern KeQueryActiveProcessors alias _KeQueryActiveProcessors@0
    extern KeQueryInterruptTime alias _KeQueryInterruptTime@0
    extern KeQueryPriorityThread alias _KeQueryPriorityThread@4
    extern KeQueryRuntimeThread alias _KeQueryRuntimeThread@8
    extern KeQuerySystemTime alias _KeQuerySystemTime@4
    extern KeQueryTickCount alias _KeQueryTickCount@4
    extern KeQueryTimeIncrement alias _KeQueryTimeIncrement@0
    extern KeRaiseUserException alias _KeRaiseUserException@4
    extern KeReadStateEvent alias _KeReadStateEvent@4
    extern KeReadStateMutant alias _KeReadStateMutant@4
    extern KeReadStateMutex alias _KeReadStateMutex@4
    extern KeReadStateQueue alias _KeReadStateQueue@4
    extern KeReadStateSemaphore alias _KeReadStateSemaphore@4
    extern KeReadStateTimer alias _KeReadStateTimer@4
    extern KeRegisterBugCheckCallback alias _KeRegisterBugCheckCallback@20
    extern KeRegisterBugCheckReasonCallback alias _KeRegisterBugCheckReasonCallback@16
    extern KeReleaseInterruptSpinLock alias _KeReleaseInterruptSpinLock@8
    extern KeReleaseMutant alias _KeReleaseMutant@16
    extern KeReleaseMutex alias _KeReleaseMutex@8
    extern KeReleaseSemaphore alias _KeReleaseSemaphore@16
    extern KeReleaseSpinLockFromDpcLevel alias _KeReleaseSpinLockFromDpcLevel@4
    extern KeRemoveByKeyDeviceQueue alias _KeRemoveByKeyDeviceQueue@8
    extern KeRemoveByKeyDeviceQueueIfBusy alias _KeRemoveByKeyDeviceQueueIfBusy@8
    extern KeRemoveDeviceQueue alias _KeRemoveDeviceQueue@4
    extern KeRemoveEntryDeviceQueue alias _KeRemoveEntryDeviceQueue@8
    extern KeRemoveQueue alias _KeRemoveQueue@12
    extern KeRemoveQueueDpc alias _KeRemoveQueueDpc@4
    extern KeRemoveSystemServiceTable alias _KeRemoveSystemServiceTable@4
    extern KeResetEvent alias _KeResetEvent@4
    extern KeRestoreFloatingPointState alias _KeRestoreFloatingPointState@4
    extern KeRevertToUserAffinityThread alias _KeRevertToUserAffinityThread@0
    extern KeRundownQueue alias _KeRundownQueue@4
    extern KeSaveFloatingPointState alias _KeSaveFloatingPointState@4
    extern KeSaveStateForHibernate alias _KeSaveStateForHibernate@4
    extern KeServiceDescriptorTable alias _KeServiceDescriptorTable@4
    extern KeSetAffinityThread alias _KeSetAffinityThread@8
    extern KeSetBasePriorityThread alias _KeSetBasePriorityThread@8
    extern KeSetDmaIoCoherency alias _KeSetDmaIoCoherency@4
    extern KeSetEvent alias _KeSetEvent@12
    extern KeSetEventBoostPriority alias _KeSetEventBoostPriority@8
    extern KeSetIdealProcessorThread alias _KeSetIdealProcessorThread@8
    extern KeSetImportanceDpc alias _KeSetImportanceDpc@8
    extern KeSetKernelStackSwapEnable alias _KeSetKernelStackSwapEnable@4
    extern KeSetPriorityThread alias _KeSetPriorityThread@8
    extern KeSetProfileIrql alias _KeSetProfileIrql@4
    extern KeSetSystemAffinityThread alias _KeSetSystemAffinityThread@4
    extern KeSetTargetProcessorDpc alias _KeSetTargetProcessorDpc@8
    extern KeSetTimeIncrement alias _KeSetTimeIncrement@8
    extern KeSetTimer alias _KeSetTimer@16
    extern KeSetTimerEx alias _KeSetTimerEx@20
    extern KeStackAttachProcess alias _KeStackAttachProcess@8
    extern KeSynchronizeExecution alias _KeSynchronizeExecution@12
    extern KeTerminateThread alias _KeTerminateThread@4
    extern KeTickCount alias _KeTickCount@4
    extern KeUnstackDetachProcess alias _KeUnstackDetachProcess@4
    extern KeUpdateRunTime alias _KeUpdateRunTime@4
    extern KeUpdateSystemTime alias _KeUpdateSystemTime@0
    extern KeUserModeCallback alias _KeUserModeCallback@20
    extern KeWaitForMultipleObjects alias _KeWaitForMultipleObjects@32
    extern KeWaitForMutexObject alias _KeWaitForMutexObject@20
    extern KeWaitForSingleObject alias _KeWaitForSingleObject@20
    extern KiBugCheckData alias _KiBugCheckData@4
    extern KiCoprocessorError alias _KiCoprocessorError@0
    extern KiDeliverApc alias _KiDeliverApc@12
    extern KiDispatchInterrupt alias _KiDispatchInterrupt@0
    extern KiEnableTimerWatchdog alias _KiEnableTimerWatchdog@4
    extern KiIpiServiceRoutine alias _KiIpiServiceRoutine@8
    extern KiUnexpectedInterrupt alias _KiUnexpectedInterrupt@4
    extern LdrAccessResource alias _LdrAccessResource@16
    extern LdrEnumResources alias _LdrEnumResources@20
    extern LdrFindResourceDirectory_U alias _LdrFindResourceDirectory_U@16
    extern LdrFindResource_U alias _LdrFindResource_U@16
    extern LpcPortObjectType alias _LpcPortObjectType@4
    extern LpcRequestPort alias _LpcRequestPort@8
    extern LpcRequestWaitReplyPort alias _LpcRequestWaitReplyPort@12
    extern LsaCallAuthenticationPackage alias _LsaCallAuthenticationPackage@28
    extern LsaDeregisterLogonProcess alias _LsaDeregisterLogonProcess@4
    extern LsaFreeReturnBuffer alias _LsaFreeReturnBuffer@4
    extern LsaLogonUser alias _LsaLogonUser@56
    extern LsaLookupAuthenticationPackage alias _LsaLookupAuthenticationPackage@12
    extern LsaRegisterLogonProcess alias _LsaRegisterLogonProcess@12
    extern Mm64BitPhysicalAddress alias _Mm64BitPhysicalAddress@4
    extern MmAddPhysicalMemory alias _MmAddPhysicalMemory@8
    extern MmAddVerifierThunks alias _MmAddVerifierThunks@8
    extern MmAdjustWorkingSetSize alias _MmAdjustWorkingSetSize@16
    extern MmAdvanceMdl alias _MmAdvanceMdl@8
    extern MmAllocateContiguousMemory alias _MmAllocateContiguousMemory@12
    extern MmAllocateContiguousMemorySpecifyCache alias _MmAllocateContiguousMemorySpecifyCache@32
    extern MmAllocateMappingAddress alias _MmAllocateMappingAddress@8
    extern MmAllocateNonCachedMemory alias _MmAllocateNonCachedMemory@4
    extern MmAllocatePagesForMdl alias _MmAllocatePagesForMdl@28
    extern MmBuildMdlForNonPagedPool alias _MmBuildMdlForNonPagedPool@4
    extern MmCanFileBeTruncated alias _MmCanFileBeTruncated@8
    extern MmCommitSessionMappedView alias _MmCommitSessionMappedView@8
    extern MmCreateMdl alias _MmCreateMdl@12
    extern MmCreateSection alias _MmCreateSection@32
    extern MmDisableModifiedWriteOfSection alias _MmDisableModifiedWriteOfSection@4
    extern MmFlushImageSection alias _MmFlushImageSection@8
    extern MmForceSectionClosed alias _MmForceSectionClosed@8
    extern MmFreeContiguousMemory alias _MmFreeContiguousMemory@4
    extern MmFreeContiguousMemorySpecifyCache alias _MmFreeContiguousMemorySpecifyCache@12
    extern MmFreeMappingAddress alias _MmFreeMappingAddress@8
    extern MmFreeNonCachedMemory alias _MmFreeNonCachedMemory@8
    extern MmFreePagesFromMdl alias _MmFreePagesFromMdl@4
    extern MmGetPhysicalAddress alias _MmGetPhysicalAddress@4
    extern MmGetPhysicalMemoryRanges alias _MmGetPhysicalMemoryRanges@0
    extern MmGetSystemRoutineAddress alias _MmGetSystemRoutineAddress@4
    extern MmGetVirtualForPhysical alias _MmGetVirtualForPhysical@8
    extern MmGrowKernelStack alias _MmGrowKernelStack@4
    extern MmHighestUserAddress alias _MmHighestUserAddress@4
    extern MmIsAddressValid alias _MmIsAddressValid@4
    extern MmIsDriverVerifying alias _MmIsDriverVerifying@4
    extern MmIsNonPagedSystemAddressValid alias _MmIsNonPagedSystemAddressValid@4
    extern MmIsRecursiveIoFault alias _MmIsRecursiveIoFault@0
    extern MmIsThisAnNtAsSystem alias _MmIsThisAnNtAsSystem@0
    extern MmIsVerifierEnabled alias _MmIsVerifierEnabled@4
    extern MmLockPagableDataSection alias _MmLockPagableDataSection@4
    extern MmLockPagableImageSection alias _MmLockPagableImageSection@4
    extern MmLockPagableSectionByHandle alias _MmLockPagableSectionByHandle@4
    extern MmMapIoSpace alias _MmMapIoSpace@16
    extern MmMapLockedPages alias _MmMapLockedPages@8
    extern MmMapLockedPagesSpecifyCache alias _MmMapLockedPagesSpecifyCache@24
    extern MmMapLockedPagesWithReservedMapping alias _MmMapLockedPagesWithReservedMapping@16
    extern MmMapMemoryDumpMdl alias _MmMapMemoryDumpMdl@4
    extern MmMapUserAddressesToPage alias _MmMapUserAddressesToPage@12
    extern MmMapVideoDisplay alias _MmMapVideoDisplay@16
    extern MmMapViewInSessionSpace alias _MmMapViewInSessionSpace@12
    extern MmMapViewInSystemSpace alias _MmMapViewInSystemSpace@12
    extern MmMapViewOfSection alias _MmMapViewOfSection@40
    extern MmMarkPhysicalMemoryAsBad alias _MmMarkPhysicalMemoryAsBad@8
    extern MmMarkPhysicalMemoryAsGood alias _MmMarkPhysicalMemoryAsGood@8
    extern MmPageEntireDriver alias _MmPageEntireDriver@4
    extern MmPrefetchPages alias _MmPrefetchPages@8
    extern MmProbeAndLockPages alias _MmProbeAndLockPages@12
    extern MmProbeAndLockProcessPages alias _MmProbeAndLockProcessPages@16
    extern MmProbeAndLockSelectedPages alias _MmProbeAndLockSelectedPages@16
    extern MmProtectMdlSystemAddress alias _MmProtectMdlSystemAddress@8
    extern MmQuerySystemSize alias _MmQuerySystemSize@0
    extern MmRemovePhysicalMemory alias _MmRemovePhysicalMemory@8
    extern MmResetDriverPaging alias _MmResetDriverPaging@4
    extern MmSectionObjectType alias _MmSectionObjectType@4
    extern MmSecureVirtualMemory alias _MmSecureVirtualMemory@12
    extern MmSetAddressRangeModified alias _MmSetAddressRangeModified@8
    extern MmSetBankedSection alias _MmSetBankedSection@24
    extern MmSizeOfMdl alias _MmSizeOfMdl@8
    extern MmSystemRangeStart alias _MmSystemRangeStart@4
    extern MmTrimAllSystemPagableMemory alias _MmTrimAllSystemPagableMemory@4
    extern MmUnlockPagableImageSection alias _MmUnlockPagableImageSection@4
    extern MmUnlockPages alias _MmUnlockPages@4
    extern MmUnmapIoSpace alias _MmUnmapIoSpace@8
    extern MmUnmapLockedPages alias _MmUnmapLockedPages@8
    extern MmUnmapReservedMapping alias _MmUnmapReservedMapping@12
    extern MmUnmapVideoDisplay alias _MmUnmapVideoDisplay@8
    extern MmUnmapViewInSessionSpace alias _MmUnmapViewInSessionSpace@4
    extern MmUnmapViewInSystemSpace alias _MmUnmapViewInSystemSpace@4
    extern MmUnmapViewOfSection alias _MmUnmapViewOfSection@8
    extern MmUnsecureVirtualMemory alias _MmUnsecureVirtualMemory@4
    extern MmUserProbeAddress alias _MmUserProbeAddress@4
    extern NlsAnsiCodePage alias _NlsAnsiCodePage@4
    extern NlsLeadByteInfo alias _NlsLeadByteInfo@4
    extern NlsMbCodePageTag alias _NlsMbCodePageTag@4
    extern NlsMbOemCodePageTag alias _NlsMbOemCodePageTag@4
    extern NlsOemCodePage alias _NlsOemCodePage@4
    extern NlsOemLeadByteInfo alias _NlsOemLeadByteInfo@4
    extern NtAddAtom alias _NtAddAtom@12
    extern NtAdjustPrivilegesToken alias _NtAdjustPrivilegesToken@24
    extern NtAllocateLocallyUniqueId alias _NtAllocateLocallyUniqueId@4
    extern NtAllocateUuids alias _NtAllocateUuids@16
    extern NtAllocateVirtualMemory alias _NtAllocateVirtualMemory@24
    extern NtBuildNumber alias _NtBuildNumber@4
    extern NtClose alias _NtClose@4
    extern NtConnectPort alias _NtConnectPort@32
    extern NtCreateEvent alias _NtCreateEvent@20
    extern NtCreateFile alias _NtCreateFile@44
    extern NtCreateSection alias _NtCreateSection@28
    extern NtDeleteAtom alias _NtDeleteAtom@4
    extern NtDeleteFile alias _NtDeleteFile@4
    extern NtDeviceIoControlFile alias _NtDeviceIoControlFile@40
    extern NtDuplicateObject alias _NtDuplicateObject@28
    extern NtDuplicateToken alias _NtDuplicateToken@24
    extern NtFindAtom alias _NtFindAtom@12
    extern NtFreeVirtualMemory alias _NtFreeVirtualMemory@16
    extern NtFsControlFile alias _NtFsControlFile@40
    extern NtGlobalFlag alias _NtGlobalFlag@4
    extern NtLockFile alias _NtLockFile@40
    extern NtMakePermanentObject alias _NtMakePermanentObject@4
    extern NtMapViewOfSection alias _NtMapViewOfSection@40
    extern NtNotifyChangeDirectoryFile alias _NtNotifyChangeDirectoryFile@36
    extern NtOpenFile alias _NtOpenFile@24
    extern NtOpenProcess alias _NtOpenProcess@16
    extern NtOpenProcessToken alias _NtOpenProcessToken@12
    extern NtOpenProcessTokenEx alias _NtOpenProcessTokenEx@16
    extern NtOpenThread alias _NtOpenThread@16
    extern NtOpenThreadToken alias _NtOpenThreadToken@16
    extern NtOpenThreadTokenEx alias _NtOpenThreadTokenEx@20
    extern NtQueryDirectoryFile alias _NtQueryDirectoryFile@44
    extern NtQueryEaFile alias _NtQueryEaFile@36
    extern NtQueryInformationAtom alias _NtQueryInformationAtom@20
    extern NtQueryInformationFile alias _NtQueryInformationFile@20
    extern NtQueryInformationProcess alias _NtQueryInformationProcess@20
    extern NtQueryInformationThread alias _NtQueryInformationThread@20
    extern NtQueryInformationToken alias _NtQueryInformationToken@20
    extern NtQueryQuotaInformationFile alias _NtQueryQuotaInformationFile@36
    extern NtQuerySecurityObject alias _NtQuerySecurityObject@20
    extern NtQuerySystemInformation alias _NtQuerySystemInformation@16
    extern NtQueryVolumeInformationFile alias _NtQueryVolumeInformationFile@20
    extern NtReadFile alias _NtReadFile@36
    extern NtRequestPort alias _NtRequestPort@8
    extern NtRequestWaitReplyPort alias _NtRequestWaitReplyPort@12
    extern NtSetEaFile alias _NtSetEaFile@16
    extern NtSetEvent alias _NtSetEvent@8
    extern NtSetInformationFile alias _NtSetInformationFile@20
    extern NtSetInformationProcess alias _NtSetInformationProcess@16
    extern NtSetInformationThread alias _NtSetInformationThread@16
    extern NtSetQuotaInformationFile alias _NtSetQuotaInformationFile@16
    extern NtSetSecurityObject alias _NtSetSecurityObject@12
    extern NtSetVolumeInformationFile alias _NtSetVolumeInformationFile@20
    extern NtShutdownSystem alias _NtShutdownSystem@4
    extern NtTraceEvent alias _NtTraceEvent@16
    extern NtUnlockFile alias _NtUnlockFile@20
    extern NtVdmControl alias _NtVdmControl@8
    extern NtWaitForSingleObject alias _NtWaitForSingleObject@12
    extern NtWriteFile alias _NtWriteFile@36
    extern ObAssignSecurity alias _ObAssignSecurity@16
    extern ObCheckCreateObjectAccess alias _ObCheckCreateObjectAccess@28
    extern ObCheckObjectAccess alias _ObCheckObjectAccess@20
    extern ObCloseHandle alias _ObCloseHandle@8
    extern ObCreateObject alias _ObCreateObject@36
    extern ObCreateObjectType alias _ObCreateObjectType@16
    extern ObDereferenceObject alias _ObDereferenceObject@4
    extern ObDereferenceSecurityDescriptor alias _ObDereferenceSecurityDescriptor@8
    extern ObFindHandleForObject alias _ObFindHandleForObject@20
    extern ObGetObjectSecurity alias _ObGetObjectSecurity@12
    extern ObInsertObject alias _ObInsertObject@24
    extern ObLogSecurityDescriptor alias _ObLogSecurityDescriptor@12
    extern ObMakeTemporaryObject alias _ObMakeTemporaryObject@4
    extern ObOpenObjectByName alias _ObOpenObjectByName@28
    extern ObOpenObjectByPointer alias _ObOpenObjectByPointer@28
    extern ObQueryNameString alias _ObQueryNameString@16
    extern ObQueryObjectAuditingByHandle alias _ObQueryObjectAuditingByHandle@8
    extern ObReferenceObjectByHandle alias _ObReferenceObjectByHandle@24
    extern ObReferenceObjectByName alias _ObReferenceObjectByName@32
    extern ObReferenceObjectByPointer alias _ObReferenceObjectByPointer@16
    extern ObReferenceSecurityDescriptor alias _ObReferenceSecurityDescriptor@8
    extern ObReleaseObjectSecurity alias _ObReleaseObjectSecurity@8
    extern ObSetHandleAttributes alias _ObSetHandleAttributes@12
    extern ObSetSecurityDescriptorInfo alias _ObSetSecurityDescriptorInfo@24
    extern ObSetSecurityObjectByPointer alias _ObSetSecurityObjectByPointer@12
    extern PfxFindPrefix alias _PfxFindPrefix@8
    extern PfxInitialize alias _PfxInitialize@4
    extern PfxInsertPrefix alias _PfxInsertPrefix@12
    extern PfxRemovePrefix alias _PfxRemovePrefix@8
    extern PoCallDriver alias _PoCallDriver@8
    extern PoCancelDeviceNotify alias _PoCancelDeviceNotify@4
    extern PoQueueShutdownWorkItem alias _PoQueueShutdownWorkItem@4
    extern PoRegisterDeviceForIdleDetection alias _PoRegisterDeviceForIdleDetection@16
    extern PoRegisterDeviceNotify alias _PoRegisterDeviceNotify@24
    extern PoRegisterSystemState alias _PoRegisterSystemState@8
    extern PoRequestPowerIrp alias _PoRequestPowerIrp@24
    extern PoRequestShutdownEvent alias _PoRequestShutdownEvent@4
    extern PoSetHiberRange alias _PoSetHiberRange@20
    extern PoSetPowerState alias _PoSetPowerState@12
    extern PoSetSystemState alias _PoSetSystemState@4
    extern PoShutdownBugCheck alias _PoShutdownBugCheck@24
    extern PoStartNextPowerIrp alias _PoStartNextPowerIrp@4
    extern PoUnregisterSystemState alias _PoUnregisterSystemState@4
    extern ProbeForRead alias _ProbeForRead@12
    extern ProbeForWrite alias _ProbeForWrite@12
    extern PsAssignImpersonationToken alias _PsAssignImpersonationToken@8
    extern PsChargePoolQuota alias _PsChargePoolQuota@12
    extern PsChargeProcessNonPagedPoolQuota alias _PsChargeProcessNonPagedPoolQuota@8
    extern PsChargeProcessPagedPoolQuota alias _PsChargeProcessPagedPoolQuota@8
    extern PsChargeProcessPoolQuota alias _PsChargeProcessPoolQuota@12
    extern PsCreateSystemProcess alias _PsCreateSystemProcess@12
    extern PsCreateSystemThread alias _PsCreateSystemThread@28
    extern PsDereferenceImpersonationToken alias _PsDereferenceImpersonationToken@4
    extern PsDereferencePrimaryToken alias _PsDereferencePrimaryToken@4
    extern PsDisableImpersonation alias _PsDisableImpersonation@8
    extern PsEstablishWin32Callouts alias _PsEstablishWin32Callouts@4
    extern PsGetContextThread alias _PsGetContextThread@12
    extern PsGetCurrentProcess alias _PsGetCurrentProcess@0
    extern PsGetCurrentProcessId alias _PsGetCurrentProcessId@0
    extern PsGetCurrentProcessSessionId alias _PsGetCurrentProcessSessionId@0
    extern PsGetCurrentThread alias _PsGetCurrentThread@0
    extern PsGetCurrentThreadId alias _PsGetCurrentThreadId@0
    extern PsGetCurrentThreadPreviousMode alias _PsGetCurrentThreadPreviousMode@0
    extern PsGetCurrentThreadStackBase alias _PsGetCurrentThreadStackBase@0
    extern PsGetCurrentThreadStackLimit alias _PsGetCurrentThreadStackLimit@0
    extern PsGetJobLock alias _PsGetJobLock@4
    extern PsGetJobSessionId alias _PsGetJobSessionId@4
    extern PsGetJobUIRestrictionsClass alias _PsGetJobUIRestrictionsClass@4
    extern PsGetProcessCreateTimeQuadPart alias _PsGetProcessCreateTimeQuadPart@4
    extern PsGetProcessDebugPort alias _PsGetProcessDebugPort@4
    extern PsGetProcessExitProcessCalled alias _PsGetProcessExitProcessCalled@4
    extern PsGetProcessExitStatus alias _PsGetProcessExitStatus@4
    extern PsGetProcessExitTime alias _PsGetProcessExitTime@0
    extern PsGetProcessId alias _PsGetProcessId@4
    extern PsGetProcessImageFileName alias _PsGetProcessImageFileName@4
    extern PsGetProcessInheritedFromUniqueProcessId alias _PsGetProcessInheritedFromUniqueProcessId@4
    extern PsGetProcessJob alias _PsGetProcessJob@4
    extern PsGetProcessPeb alias _PsGetProcessPeb@4
    extern PsGetProcessPriorityClass alias _PsGetProcessPriorityClass@4
    extern PsGetProcessSectionBaseAddress alias _PsGetProcessSectionBaseAddress@4
    extern PsGetProcessSecurityPort alias _PsGetProcessSecurityPort@4
    extern PsGetProcessSessionId alias _PsGetProcessSessionId@4
    extern PsGetProcessWin32Process alias _PsGetProcessWin32Process@4
    extern PsGetProcessWin32WindowStation alias _PsGetProcessWin32WindowStation@4
    extern PsGetThreadFreezeCount alias _PsGetThreadFreezeCount@4
    extern PsGetThreadHardErrorsAreDisabled alias _PsGetThreadHardErrorsAreDisabled@4
    extern PsGetThreadId alias _PsGetThreadId@4
    extern PsGetThreadProcess alias _PsGetThreadProcess@4
    extern PsGetThreadProcessId alias _PsGetThreadProcessId@4
    extern PsGetThreadSessionId alias _PsGetThreadSessionId@4
    extern PsGetThreadTeb alias _PsGetThreadTeb@4
    extern PsGetThreadWin32Thread alias _PsGetThreadWin32Thread@4
    extern PsGetVersion alias _PsGetVersion@16
    extern PsImpersonateClient alias _PsImpersonateClient@20
    extern PsInitialSystemProcess alias _PsInitialSystemProcess@4
    extern PsIsProcessBeingDebugged alias _PsIsProcessBeingDebugged@4
    extern PsIsSystemThread alias _PsIsSystemThread@4
    extern PsIsThreadImpersonating alias _PsIsThreadImpersonating@4
    extern PsIsThreadTerminating alias _PsIsThreadTerminating@4
    extern PsJobType alias _PsJobType@4
    extern PsLookupProcessByProcessId alias _PsLookupProcessByProcessId@8
    extern PsLookupProcessThreadByCid alias _PsLookupProcessThreadByCid@12
    extern PsLookupThreadByThreadId alias _PsLookupThreadByThreadId@8
    extern PsProcessType alias _PsProcessType@4
    extern PsReferenceImpersonationToken alias _PsReferenceImpersonationToken@16
    extern PsReferencePrimaryToken alias _PsReferencePrimaryToken@4
    extern PsRemoveCreateThreadNotifyRoutine alias _PsRemoveCreateThreadNotifyRoutine@4
    extern PsRemoveLoadImageNotifyRoutine alias _PsRemoveLoadImageNotifyRoutine@4
    extern PsRestoreImpersonation alias _PsRestoreImpersonation@8
    extern PsReturnPoolQuota alias _PsReturnPoolQuota@12
    extern PsReturnProcessNonPagedPoolQuota alias _PsReturnProcessNonPagedPoolQuota@8
    extern PsReturnProcessPagedPoolQuota alias _PsReturnProcessPagedPoolQuota@8
    extern PsRevertThreadToSelf alias _PsRevertThreadToSelf@4
    extern PsRevertToSelf alias _PsRevertToSelf@0
    extern PsSetContextThread alias _PsSetContextThread@12
    extern PsSetCreateProcessNotifyRoutine alias _PsSetCreateProcessNotifyRoutine@8
    extern PsSetCreateThreadNotifyRoutine alias _PsSetCreateThreadNotifyRoutine@4
    extern PsSetJobUIRestrictionsClass alias _PsSetJobUIRestrictionsClass@8
    extern PsSetLegoNotifyRoutine alias _PsSetLegoNotifyRoutine@4
    extern PsSetLoadImageNotifyRoutine alias _PsSetLoadImageNotifyRoutine@4
    extern PsSetProcessPriorityByClass alias _PsSetProcessPriorityByClass@8
    extern PsSetProcessPriorityClass alias _PsSetProcessPriorityClass@8
    extern PsSetProcessSecurityPort alias _PsSetProcessSecurityPort@8
    extern PsSetProcessWin32Process alias _PsSetProcessWin32Process@12
    extern PsSetProcessWindowStation alias _PsSetProcessWindowStation@8
    extern PsSetThreadHardErrorsAreDisabled alias _PsSetThreadHardErrorsAreDisabled@8
    extern PsSetThreadWin32Thread alias _PsSetThreadWin32Thread@12
    extern PsTerminateSystemThread alias _PsTerminateSystemThread@4
    extern PsThreadType alias _PsThreadType@4
    extern READ_REGISTER_BUFFER_UCHAR alias _READ_REGISTER_BUFFER_UCHAR@12
    extern READ_REGISTER_BUFFER_ULONG alias _READ_REGISTER_BUFFER_ULONG@12
    extern READ_REGISTER_BUFFER_USHORT alias _READ_REGISTER_BUFFER_USHORT@12
    extern READ_REGISTER_UCHAR alias _READ_REGISTER_UCHAR@4
    extern READ_REGISTER_ULONG alias _READ_REGISTER_ULONG@4
    extern READ_REGISTER_USHORT alias _READ_REGISTER_USHORT@4
    extern RtlAbsoluteToSelfRelativeSD alias _RtlAbsoluteToSelfRelativeSD@12
    extern RtlAddAccessAllowedAce alias _RtlAddAccessAllowedAce@16
    extern RtlAddAccessAllowedAceEx alias _RtlAddAccessAllowedAceEx@20
    extern RtlAddAce alias _RtlAddAce@20
    extern RtlAddAtomToAtomTable alias _RtlAddAtomToAtomTable@12
    extern RtlAddRange alias _RtlAddRange@36
    extern RtlAllocateHeap alias _RtlAllocateHeap@12
    extern RtlAnsiCharToUnicodeChar alias _RtlAnsiCharToUnicodeChar@4
    extern RtlAnsiStringToUnicodeSize alias _RtlAnsiStringToUnicodeSize@4
    extern RtlAnsiStringToUnicodeString alias _RtlAnsiStringToUnicodeString@12
    extern RtlAppendAsciizToString alias _RtlAppendAsciizToString@8
    extern RtlAppendStringToString alias _RtlAppendStringToString@8
    extern RtlAppendUnicodeStringToString alias _RtlAppendUnicodeStringToString@8
    extern RtlAppendUnicodeToString alias _RtlAppendUnicodeToString@8
    extern RtlAreAllAccessesGranted alias _RtlAreAllAccessesGranted@8
    extern RtlAreAnyAccessesGranted alias _RtlAreAnyAccessesGranted@8
    extern RtlAreBitsClear alias _RtlAreBitsClear@12
    extern RtlAreBitsSet alias _RtlAreBitsSet@12
    extern RtlAssert alias _RtlAssert@16
    extern RtlCaptureContext alias _RtlCaptureContext@4
    extern RtlCaptureStackBackTrace alias _RtlCaptureStackBackTrace@16
    extern RtlCharToInteger alias _RtlCharToInteger@12
    extern RtlCheckRegistryKey alias _RtlCheckRegistryKey@8
    extern RtlClearAllBits alias _RtlClearAllBits@4
    extern RtlClearBit alias _RtlClearBit@8
    extern RtlClearBits alias _RtlClearBits@12
    extern RtlCompareMemory alias _RtlCompareMemory@12
    extern RtlCompareMemoryUlong alias _RtlCompareMemoryUlong@12
    extern RtlCompareString alias _RtlCompareString@12
    extern RtlCompareUnicodeString alias _RtlCompareUnicodeString@12
    extern RtlCompressBuffer alias _RtlCompressBuffer@32
    extern RtlCompressChunks alias _RtlCompressChunks@28
    extern RtlConvertLongToLargeInteger alias _RtlConvertLongToLargeInteger@4
    extern RtlConvertSidToUnicodeString alias _RtlConvertSidToUnicodeString@12
    extern RtlConvertUlongToLargeInteger alias _RtlConvertUlongToLargeInteger@4
    extern RtlCopyLuid alias _RtlCopyLuid@8
    extern RtlCopyRangeList alias _RtlCopyRangeList@8
    extern RtlCopySid alias _RtlCopySid@12
    extern RtlCopyString alias _RtlCopyString@8
    extern RtlCopyUnicodeString alias _RtlCopyUnicodeString@8
    extern RtlCreateAcl alias _RtlCreateAcl@12
    extern RtlCreateAtomTable alias _RtlCreateAtomTable@8
    extern RtlCreateHeap alias _RtlCreateHeap@24
    extern RtlCreateRegistryKey alias _RtlCreateRegistryKey@8
    extern RtlCreateSecurityDescriptor alias _RtlCreateSecurityDescriptor@8
    extern RtlCreateSystemVolumeInformationFolder alias _RtlCreateSystemVolumeInformationFolder@4
    extern RtlCreateUnicodeString alias _RtlCreateUnicodeString@8
    extern RtlCustomCPToUnicodeN alias _RtlCustomCPToUnicodeN@24
    extern RtlDecompressBuffer alias _RtlDecompressBuffer@24
    extern RtlDecompressChunks alias _RtlDecompressChunks@28
    extern RtlDecompressFragment alias _RtlDecompressFragment@32
    extern RtlDelete alias _RtlDelete@4
    extern RtlDeleteAce alias _RtlDeleteAce@8
    extern RtlDeleteAtomFromAtomTable alias _RtlDeleteAtomFromAtomTable@8
    extern RtlDeleteElementGenericTable alias _RtlDeleteElementGenericTable@8
    extern RtlDeleteElementGenericTableAvl alias _RtlDeleteElementGenericTableAvl@8
    extern RtlDeleteNoSplay alias _RtlDeleteNoSplay@8
    extern RtlDeleteOwnersRanges alias _RtlDeleteOwnersRanges@8
    extern RtlDeleteRange alias _RtlDeleteRange@24
    extern RtlDeleteRegistryValue alias _RtlDeleteRegistryValue@12
    extern RtlDescribeChunk alias _RtlDescribeChunk@20
    extern RtlDestroyAtomTable alias _RtlDestroyAtomTable@4
    extern RtlDestroyHeap alias _RtlDestroyHeap@4
    extern RtlDowncaseUnicodeString alias _RtlDowncaseUnicodeString@12
    extern RtlEmptyAtomTable alias _RtlEmptyAtomTable@8
    extern RtlEnlargedIntegerMultiply alias _RtlEnlargedIntegerMultiply@8
    extern RtlEnlargedUnsignedDivide alias _RtlEnlargedUnsignedDivide@16
    extern RtlEnlargedUnsignedMultiply alias _RtlEnlargedUnsignedMultiply@8
    extern RtlEnumerateGenericTable alias _RtlEnumerateGenericTable@8
    extern RtlEnumerateGenericTableAvl alias _RtlEnumerateGenericTableAvl@8
    extern RtlEnumerateGenericTableLikeADirectory alias _RtlEnumerateGenericTableLikeADirectory@28
    extern RtlEnumerateGenericTableWithoutSplaying alias _RtlEnumerateGenericTableWithoutSplaying@8
    extern RtlEnumerateGenericTableWithoutSplayingAvl alias _RtlEnumerateGenericTableWithoutSplayingAvl@8
    extern RtlEqualLuid alias _RtlEqualLuid@8
    extern RtlEqualSid alias _RtlEqualSid@8
    extern RtlEqualString alias _RtlEqualString@12
    extern RtlEqualUnicodeString alias _RtlEqualUnicodeString@12
    extern RtlExtendedIntegerMultiply alias _RtlExtendedIntegerMultiply@12
    extern RtlExtendedLargeIntegerDivide alias _RtlExtendedLargeIntegerDivide@16
    extern RtlExtendedMagicDivide alias _RtlExtendedMagicDivide@20
    extern RtlFillMemory alias _RtlFillMemory@12
    extern RtlFillMemoryUlong alias _RtlFillMemoryUlong@12
    extern RtlFindClearBits alias _RtlFindClearBits@12
    extern RtlFindClearBitsAndSet alias _RtlFindClearBitsAndSet@12
    extern RtlFindClearRuns alias _RtlFindClearRuns@16
    extern RtlFindFirstRunClear alias _RtlFindFirstRunClear@8
    extern RtlFindLastBackwardRunClear alias _RtlFindLastBackwardRunClear@12
    extern RtlFindLeastSignificantBit alias _RtlFindLeastSignificantBit@8
    extern RtlFindLongestRunClear alias _RtlFindLongestRunClear@8
    extern RtlFindMessage alias _RtlFindMessage@20
    extern RtlFindMostSignificantBit alias _RtlFindMostSignificantBit@8
    extern RtlFindNextForwardRunClear alias _RtlFindNextForwardRunClear@12
    extern RtlFindRange alias _RtlFindRange@48
    extern RtlFindSetBits alias _RtlFindSetBits@12
    extern RtlFindSetBitsAndClear alias _RtlFindSetBitsAndClear@12
    extern RtlFindUnicodePrefix alias _RtlFindUnicodePrefix@12
    extern RtlFormatCurrentUserKeyPath alias _RtlFormatCurrentUserKeyPath@4
    extern RtlFreeAnsiString alias _RtlFreeAnsiString@4
    extern RtlFreeHeap alias _RtlFreeHeap@12
    extern RtlFreeOemString alias _RtlFreeOemString@4
    extern RtlFreeRangeList alias _RtlFreeRangeList@4
    extern RtlFreeUnicodeString alias _RtlFreeUnicodeString@4
    extern RtlGUIDFromString alias _RtlGUIDFromString@8
    extern RtlGenerate8dot3Name alias _RtlGenerate8dot3Name@16
    extern RtlGetAce alias _RtlGetAce@12
    extern RtlGetCallersAddress alias _RtlGetCallersAddress@8
    extern RtlGetCompressionWorkSpaceSize alias _RtlGetCompressionWorkSpaceSize@12
    extern RtlGetDaclSecurityDescriptor alias _RtlGetDaclSecurityDescriptor@16
    extern RtlGetDefaultCodePage alias _RtlGetDefaultCodePage@8
    extern RtlGetElementGenericTable alias _RtlGetElementGenericTable@8
    extern RtlGetElementGenericTableAvl alias _RtlGetElementGenericTableAvl@8
    extern RtlGetFirstRange alias _RtlGetFirstRange@12
    extern RtlGetGroupSecurityDescriptor alias _RtlGetGroupSecurityDescriptor@12
    extern RtlGetNextRange alias _RtlGetNextRange@12
    extern RtlGetNtGlobalFlags alias _RtlGetNtGlobalFlags@0
    extern RtlGetOwnerSecurityDescriptor alias _RtlGetOwnerSecurityDescriptor@12
    extern RtlGetSaclSecurityDescriptor alias _RtlGetSaclSecurityDescriptor@16
    extern RtlGetSetBootStatusData alias _RtlGetSetBootStatusData@24
    extern RtlGetVersion alias _RtlGetVersion@4
    extern RtlHashUnicodeString alias _RtlHashUnicodeString@16
    extern RtlImageDirectoryEntryToData alias _RtlImageDirectoryEntryToData@16
    extern RtlImageNtHeader alias _RtlImageNtHeader@4
    extern RtlInitAnsiString alias _RtlInitAnsiString@8
    extern RtlInitCodePageTable alias _RtlInitCodePageTable@8
    extern RtlInitString alias _RtlInitString@8
    extern RtlInitUnicodeString alias _RtlInitUnicodeString@8
    extern RtlInitializeBitMap alias _RtlInitializeBitMap@12
    extern RtlInitializeGenericTable alias _RtlInitializeGenericTable@20
    extern RtlInitializeGenericTableAvl alias _RtlInitializeGenericTableAvl@20
    extern RtlInitializeRangeList alias _RtlInitializeRangeList@4
    extern RtlInitializeSid alias _RtlInitializeSid@12
    extern RtlInitializeUnicodePrefix alias _RtlInitializeUnicodePrefix@4
    extern RtlInsertElementGenericTable alias _RtlInsertElementGenericTable@16
    extern RtlInsertElementGenericTableAvl alias _RtlInsertElementGenericTableAvl@16
    extern RtlInsertElementGenericTableFull alias _RtlInsertElementGenericTableFull@24
    extern RtlInsertElementGenericTableFullAvl alias _RtlInsertElementGenericTableFullAvl@24
    extern RtlInsertUnicodePrefix alias _RtlInsertUnicodePrefix@12
    extern RtlInt64ToUnicodeString alias _RtlInt64ToUnicodeString@16
    extern RtlIntegerToChar alias _RtlIntegerToChar@16
    extern RtlIntegerToUnicode alias _RtlIntegerToUnicode@16
    extern RtlIntegerToUnicodeString alias _RtlIntegerToUnicodeString@12
    extern RtlInvertRangeList alias _RtlInvertRangeList@8
    extern RtlIpv4AddressToStringA alias RtlIpv4AddressToStringA@8
    extern RtlIpv4AddressToStringW alias RtlIpv4AddressToStringW@8
    extern RtlIpv4AddressToStringExA alias RtlIpv4AddressToStringExA@16
    extern RtlIpv4AddressToStringExW alias RtlIpv4AddressToStringExA@16
    extern RtlIpv4StringToAddressA alias RtlIpv4StringToAddressA@16
    extern RtlIpv4StringToAddressW alias RtlIpv4StringToAddressA@16
    extern RtlIpv4StringToAddressExA alias RtlIpv4StringToAddressExA@16
    extern RtlIpv4StringToAddressExW alias RtlIpv4StringToAddressExA@16
    extern RtlIpv6AddressToStringA alias RtlIpv6AddressToStringA@8
    extern RtlIpv6AddressToStringW alias RtlIpv6AddressToStringW@8
    extern RtlIpv6AddressToStringExA alias RtlIpv6AddressToStringExA@20
    extern RtlIpv6AddressToStringExW alias RtlIpv6AddressToStringExW@20
    extern RtlIpv6StringToAddressA alias RtlIpv6StringToAddressA@12
    extern RtlIpv6StringToAddressW alias RtlIpv6StringToAddressW@12
    extern RtlIpv6StringToAddressExA alias RtlIpv6StringToAddressExA@16
    extern RtlIpv6StringToAddressExW alias RtlIpv6StringToAddressExW@16
    extern RtlIsGenericTableEmpty alias _RtlIsGenericTableEmpty@4
    extern RtlIsGenericTableEmptyAvl alias _RtlIsGenericTableEmptyAvl@4
    extern RtlIsNameLegalDOS8Dot3 alias _RtlIsNameLegalDOS8Dot3@12
    extern RtlIsRangeAvailable alias _RtlIsRangeAvailable@40
    extern RtlIsValidOemCharacter alias _RtlIsValidOemCharacter@4
    extern RtlLargeIntegerAdd alias _RtlLargeIntegerAdd@16
    extern RtlLargeIntegerArithmeticShift alias _RtlLargeIntegerArithmeticShift@12
    extern RtlLargeIntegerDivide alias _RtlLargeIntegerDivide@20
    extern RtlLargeIntegerNegate alias _RtlLargeIntegerNegate@8
    extern RtlLargeIntegerShiftLeft alias _RtlLargeIntegerShiftLeft@12
    extern RtlLargeIntegerShiftRight alias _RtlLargeIntegerShiftRight@12
    extern RtlLargeIntegerSubtract alias _RtlLargeIntegerSubtract@16
    extern RtlLengthRequiredSid alias _RtlLengthRequiredSid@4
    extern RtlLengthSecurityDescriptor alias _RtlLengthSecurityDescriptor@4
    extern RtlLengthSid alias _RtlLengthSid@4
    extern RtlLockBootStatusData alias _RtlLockBootStatusData@4
    extern RtlLookupAtomInAtomTable alias _RtlLookupAtomInAtomTable@12
    extern RtlLookupElementGenericTable alias _RtlLookupElementGenericTable@8
    extern RtlLookupElementGenericTableAvl alias _RtlLookupElementGenericTableAvl@8
    extern RtlLookupElementGenericTableFull alias _RtlLookupElementGenericTableFull@16
    extern RtlLookupElementGenericTableFullAvl alias _RtlLookupElementGenericTableFullAvl@16
    extern RtlMapGenericMask alias _RtlMapGenericMask@8
    extern RtlMapSecurityErrorToNtStatus alias _RtlMapSecurityErrorToNtStatus@4
    extern RtlMergeRangeLists alias _RtlMergeRangeLists@16
    extern RtlMoveMemory alias _RtlMoveMemory@12
    extern RtlMultiByteToUnicodeN alias _RtlMultiByteToUnicodeN@20
    extern RtlMultiByteToUnicodeSize alias _RtlMultiByteToUnicodeSize@12
    extern RtlNextUnicodePrefix alias _RtlNextUnicodePrefix@8
    extern RtlNtStatusToDosError alias _RtlNtStatusToDosError@4
    extern RtlNtStatusToDosErrorNoTeb alias _RtlNtStatusToDosErrorNoTeb@4
    extern RtlNumberGenericTableElements alias _RtlNumberGenericTableElements@4
    extern RtlNumberGenericTableElementsAvl alias _RtlNumberGenericTableElementsAvl@4
    extern RtlNumberOfClearBits alias _RtlNumberOfClearBits@4
    extern RtlNumberOfSetBits alias _RtlNumberOfSetBits@4
    extern RtlOemStringToCountedUnicodeString alias _RtlOemStringToCountedUnicodeString@12
    extern RtlOemStringToUnicodeSize alias _RtlOemStringToUnicodeSize@4
    extern RtlOemStringToUnicodeString alias _RtlOemStringToUnicodeString@12
    extern RtlOemToUnicodeN alias _RtlOemToUnicodeN@20
    extern RtlPinAtomInAtomTable alias _RtlPinAtomInAtomTable@8
    extern RtlPrefixString alias _RtlPrefixString@12
    extern RtlPrefixUnicodeString alias _RtlPrefixUnicodeString@12
    extern RtlQueryAtomInAtomTable alias _RtlQueryAtomInAtomTable@24
    extern RtlQueryRegistryValues alias _RtlQueryRegistryValues@20
    extern RtlQueryTimeZoneInformation alias _RtlQueryTimeZoneInformation@4
    extern RtlRaiseException alias _RtlRaiseException@4
    extern RtlRandom alias _RtlRandom@4
    extern RtlRandomEx alias _RtlRandomEx@4
    extern RtlRealPredecessor alias _RtlRealPredecessor@4
    extern RtlRealSuccessor alias _RtlRealSuccessor@4
    extern RtlRemoveUnicodePrefix alias _RtlRemoveUnicodePrefix@8
    extern RtlReserveChunk alias _RtlReserveChunk@20
    extern RtlSecondsSince1970ToTime alias _RtlSecondsSince1970ToTime@8
    extern RtlSecondsSince1980ToTime alias _RtlSecondsSince1980ToTime@8
    extern RtlSelfRelativeToAbsoluteSD2 alias _RtlSelfRelativeToAbsoluteSD2@8
    extern RtlSelfRelativeToAbsoluteSD alias _RtlSelfRelativeToAbsoluteSD@44
    extern RtlSetAllBits alias _RtlSetAllBits@4
    extern RtlSetBit alias _RtlSetBit@8
    extern RtlSetBits alias _RtlSetBits@12
    extern RtlSetDaclSecurityDescriptor alias _RtlSetDaclSecurityDescriptor@16
    extern RtlSetGroupSecurityDescriptor alias _RtlSetGroupSecurityDescriptor@12
    extern RtlSetOwnerSecurityDescriptor alias _RtlSetOwnerSecurityDescriptor@12
    extern RtlSetSaclSecurityDescriptor alias _RtlSetSaclSecurityDescriptor@16
    extern RtlSetTimeZoneInformation alias _RtlSetTimeZoneInformation@4
    extern RtlSizeHeap alias _RtlSizeHeap@12
    extern RtlSplay alias _RtlSplay@4
    extern RtlStringFromGUID alias _RtlStringFromGUID@8
    extern RtlSubAuthorityCountSid alias _RtlSubAuthorityCountSid@4
    extern RtlSubAuthoritySid alias _RtlSubAuthoritySid@8
    extern RtlSubtreePredecessor alias _RtlSubtreePredecessor@4
    extern RtlSubtreeSuccessor alias _RtlSubtreeSuccessor@4
    extern RtlTestBit alias _RtlTestBit@8
    extern RtlTimeFieldsToTime alias _RtlTimeFieldsToTime@8
    extern RtlTimeToElapsedTimeFields alias _RtlTimeToElapsedTimeFields@8
    extern RtlTimeToSecondsSince1970 alias _RtlTimeToSecondsSince1970@8
    extern RtlTimeToSecondsSince1980 alias _RtlTimeToSecondsSince1980@8
    extern RtlTimeToTimeFields alias _RtlTimeToTimeFields@8
    extern RtlTraceDatabaseAdd alias _RtlTraceDatabaseAdd@16
    extern RtlTraceDatabaseCreate alias _RtlTraceDatabaseCreate@20
    extern RtlTraceDatabaseDestroy alias _RtlTraceDatabaseDestroy@4
    extern RtlTraceDatabaseEnumerate alias _RtlTraceDatabaseEnumerate@12
    extern RtlTraceDatabaseFind alias _RtlTraceDatabaseFind@16
    extern RtlTraceDatabaseLock alias _RtlTraceDatabaseLock@4
    extern RtlTraceDatabaseUnlock alias _RtlTraceDatabaseUnlock@4
    extern RtlTraceDatabaseValidate alias _RtlTraceDatabaseValidate@4
    extern RtlUnicodeStringToAnsiSize alias _RtlUnicodeStringToAnsiSize@4
    extern RtlUnicodeStringToAnsiString alias _RtlUnicodeStringToAnsiString@12
    extern RtlUnicodeStringToCountedOemString alias _RtlUnicodeStringToCountedOemString@12
    extern RtlUnicodeStringToInteger alias _RtlUnicodeStringToInteger@12
    extern RtlUnicodeStringToOemSize alias _RtlUnicodeStringToOemSize@4
    extern RtlUnicodeStringToOemString alias _RtlUnicodeStringToOemString@12
    extern RtlUnicodeToCustomCPN alias _RtlUnicodeToCustomCPN@24
    extern RtlUnicodeToMultiByteN alias _RtlUnicodeToMultiByteN@20
    extern RtlUnicodeToMultiByteSize alias _RtlUnicodeToMultiByteSize@12
    extern RtlUnicodeToOemN alias _RtlUnicodeToOemN@20
    extern RtlUnlockBootStatusData alias _RtlUnlockBootStatusData@4
    extern RtlUnwind alias _RtlUnwind@16
    extern RtlUpcaseUnicodeChar alias _RtlUpcaseUnicodeChar@4
    extern RtlUpcaseUnicodeString alias _RtlUpcaseUnicodeString@12
    extern RtlUpcaseUnicodeStringToAnsiString alias _RtlUpcaseUnicodeStringToAnsiString@12
    extern RtlUpcaseUnicodeStringToCountedOemString alias _RtlUpcaseUnicodeStringToCountedOemString@12
    extern RtlUpcaseUnicodeStringToOemString alias _RtlUpcaseUnicodeStringToOemString@12
    extern RtlUpcaseUnicodeToCustomCPN alias _RtlUpcaseUnicodeToCustomCPN@24
    extern RtlUpcaseUnicodeToMultiByteN alias _RtlUpcaseUnicodeToMultiByteN@20
    extern RtlUpcaseUnicodeToOemN alias _RtlUpcaseUnicodeToOemN@20
    extern RtlUpperChar alias _RtlUpperChar@4
    extern RtlUpperString alias _RtlUpperString@8
    extern RtlValidRelativeSecurityDescriptor alias _RtlValidRelativeSecurityDescriptor@12
    extern RtlValidSecurityDescriptor alias _RtlValidSecurityDescriptor@4
    extern RtlValidSid alias _RtlValidSid@4
    extern RtlVerifyVersionInfo alias _RtlVerifyVersionInfo@16
    extern RtlVolumeDeviceToDosName alias _RtlVolumeDeviceToDosName@8
    extern RtlWalkFrameChain alias _RtlWalkFrameChain@12
    extern RtlWriteRegistryValue alias _RtlWriteRegistryValue@24
    extern RtlZeroHeap alias _RtlZeroHeap@8
    extern RtlZeroMemory alias _RtlZeroMemory@8
    extern RtlxAnsiStringToUnicodeSize alias _RtlxAnsiStringToUnicodeSize@4
    extern RtlxOemStringToUnicodeSize alias _RtlxOemStringToUnicodeSize@4
    extern RtlxUnicodeStringToAnsiSize alias _RtlxUnicodeStringToAnsiSize@4
    extern RtlxUnicodeStringToOemSize alias _RtlxUnicodeStringToOemSize@4
    extern SeAccessCheck alias _SeAccessCheck@40
    extern SeAppendPrivileges alias _SeAppendPrivileges@8
    extern SeAssignSecurity alias _SeAssignSecurity@28
    extern SeAssignSecurityEx alias _SeAssignSecurityEx@36
    extern SeAuditHardLinkCreation alias _SeAuditHardLinkCreation@12
    extern SeAuditingFileEvents alias _SeAuditingFileEvents@8
    extern SeAuditingFileEventsWithContext alias _SeAuditingFileEventsWithContext@12
    extern SeAuditingFileOrGlobalEvents alias _SeAuditingFileOrGlobalEvents@12
    extern SeAuditingHardLinkEvents alias _SeAuditingHardLinkEvents@8
    extern SeAuditingHardLinkEventsWithContext alias _SeAuditingHardLinkEventsWithContext@12
    extern SeCaptureSecurityDescriptor alias _SeCaptureSecurityDescriptor@20
    extern SeCaptureSubjectContext alias _SeCaptureSubjectContext@4
    extern SeCloseObjectAuditAlarm alias _SeCloseObjectAuditAlarm@12
    extern SeCreateAccessState alias _SeCreateAccessState@16
    extern SeCreateClientSecurity alias _SeCreateClientSecurity@16
    extern SeCreateClientSecurityFromSubjectContext alias _SeCreateClientSecurityFromSubjectContext@16
    extern SeDeassignSecurity alias _SeDeassignSecurity@4
    extern SeDeleteAccessState alias _SeDeleteAccessState@4
    extern SeDeleteObjectAuditAlarm alias _SeDeleteObjectAuditAlarm@8
    extern SeExports alias _SeExports@4
    extern SeFilterToken alias _SeFilterToken@24
    extern SeFreePrivileges alias _SeFreePrivileges@4
    extern SeImpersonateClient alias _SeImpersonateClient@8
    extern SeImpersonateClientEx alias _SeImpersonateClientEx@8
    extern SeLockSubjectContext alias _SeLockSubjectContext@4
    extern SeMarkLogonSessionForTerminationNotification alias _SeMarkLogonSessionForTerminationNotification@4
    extern SeOpenObjectAuditAlarm alias _SeOpenObjectAuditAlarm@36
    extern SeOpenObjectForDeleteAuditAlarm alias _SeOpenObjectForDeleteAuditAlarm@36
    extern SePrivilegeCheck alias _SePrivilegeCheck@12
    extern SePrivilegeObjectAuditAlarm alias _SePrivilegeObjectAuditAlarm@24
    extern SePublicDefaultDacl alias _SePublicDefaultDacl@4
    extern SeQueryAuthenticationIdToken alias _SeQueryAuthenticationIdToken@8
    extern SeQueryInformationToken alias _SeQueryInformationToken@12
    extern SeQuerySecurityDescriptorInfo alias _SeQuerySecurityDescriptorInfo@16
    extern SeQuerySessionIdToken alias _SeQuerySessionIdToken@8
    extern SeRegisterLogonSessionTerminatedRoutine alias _SeRegisterLogonSessionTerminatedRoutine@4
    extern SeReleaseSecurityDescriptor alias _SeReleaseSecurityDescriptor@12
    extern SeReleaseSubjectContext alias _SeReleaseSubjectContext@4
    extern SeSetAccessStateGenericMapping alias _SeSetAccessStateGenericMapping@8
    extern SeSetSecurityDescriptorInfo alias _SeSetSecurityDescriptorInfo@24
    extern SeSetSecurityDescriptorInfoEx alias _SeSetSecurityDescriptorInfoEx@28
    extern SeSinglePrivilegeCheck alias _SeSinglePrivilegeCheck@12
    extern SeSystemDefaultDacl alias _SeSystemDefaultDacl@4
    extern SeTokenImpersonationLevel alias _SeTokenImpersonationLevel@4
    extern SeTokenIsAdmin alias _SeTokenIsAdmin@4
    extern SeTokenIsRestricted alias _SeTokenIsRestricted@4
    extern SeTokenIsWriteRestricted alias _SeTokenIsWriteRestricted@4
    extern SeTokenObjectType alias _SeTokenObjectType@4
    extern SeTokenType alias _SeTokenType@4
    extern SeUnlockSubjectContext alias _SeUnlockSubjectContext@4
    extern SeUnregisterLogonSessionTerminatedRoutine alias _SeUnregisterLogonSessionTerminatedRoutine@4
    extern SeValidSecurityDescriptor alias _SeValidSecurityDescriptor@8
    extern VerSetConditionMask alias _VerSetConditionMask@16
    extern VfFailDeviceNode alias _VfFailDeviceNode@4
    extern VfFailDriver alias _VfFailDriver@4
    extern VfFailSystemBIOS alias _VfFailSystemBIOS@4
    extern VfIsVerificationEnabled alias _VfIsVerificationEnabled@8
    extern WRITE_REGISTER_BUFFER_UCHAR alias _WRITE_REGISTER_BUFFER_UCHAR@12
    extern WRITE_REGISTER_BUFFER_ULONG alias _WRITE_REGISTER_BUFFER_ULONG@12
    extern WRITE_REGISTER_BUFFER_USHORT alias _WRITE_REGISTER_BUFFER_USHORT@12
    extern WRITE_REGISTER_UCHAR alias _WRITE_REGISTER_UCHAR@8
    extern WRITE_REGISTER_ULONG alias _WRITE_REGISTER_ULONG@8
    extern WRITE_REGISTER_USHORT alias _WRITE_REGISTER_USHORT@8
    extern WmiFlushTrace alias _WmiFlushTrace@4
    extern WmiQueryTrace alias _WmiQueryTrace@4
    extern WmiQueryTraceInformation alias _WmiQueryTraceInformation@20
    extern WmiStartTrace alias _WmiStartTrace@4
    extern WmiStopTrace alias _WmiStopTrace@4
    extern WmiTraceMessage alias _WmiTraceMessage@4
    extern WmiTraceMessageVa alias _WmiTraceMessageVa@24
    extern WmiUpdateTrace alias _WmiUpdateTrace@4
    extern XIPDispatch alias _XIPDispatch@12
    extern ZwAccessCheckAndAuditAlarm alias _ZwAccessCheckAndAuditAlarm@44
    extern ZwAddBootEntry alias _ZwAddBootEntry@8
    extern ZwAdjustPrivilegesToken alias _ZwAdjustPrivilegesToken@24
    extern ZwAlertThread alias _ZwAlertThread@4
    extern ZwAllocateVirtualMemory alias _ZwAllocateVirtualMemory@24
    extern ZwAssignProcessToJobObject alias _ZwAssignProcessToJobObject@8
    extern ZwCancelIoFile alias _ZwCancelIoFile@8
    extern ZwCancelTimer alias _ZwCancelTimer@8
    extern ZwClearEvent alias _ZwClearEvent@4
    extern ZwClose alias _ZwClose@4
    extern ZwCloseObjectAuditAlarm alias _ZwCloseObjectAuditAlarm@12
    extern ZwConnectPort alias _ZwConnectPort@32
    extern ZwCreateDirectoryObject alias _ZwCreateDirectoryObject@12
    extern ZwCreateEvent alias _ZwCreateEvent@20
    extern ZwCreateFile alias _ZwCreateFile@44
    extern ZwCreateJobObject alias _ZwCreateJobObject@12
    extern ZwCreateKey alias _ZwCreateKey@28
    extern ZwCreateSection alias _ZwCreateSection@28
    extern ZwCreateSymbolicLinkObject alias _ZwCreateSymbolicLinkObject@16
    extern ZwCreateTimer alias _ZwCreateTimer@16
    extern ZwDeleteBootEntry alias _ZwDeleteBootEntry@4
    extern ZwDeleteFile alias _ZwDeleteFile@4
    extern ZwDeleteKey alias _ZwDeleteKey@4
    extern ZwDeleteValueKey alias _ZwDeleteValueKey@8
    extern ZwDeviceIoControlFile alias _ZwDeviceIoControlFile@40
    extern ZwDisplayString alias _ZwDisplayString@4
    extern ZwDuplicateObject alias _ZwDuplicateObject@28
    extern ZwDuplicateToken alias _ZwDuplicateToken@24
    extern ZwEnumerateBootEntries alias _ZwEnumerateBootEntries@8
    extern ZwEnumerateKey alias _ZwEnumerateKey@24
    extern ZwEnumerateValueKey alias _ZwEnumerateValueKey@24
    extern ZwFlushInstructionCache alias _ZwFlushInstructionCache@12
    extern ZwFlushKey alias _ZwFlushKey@4
    extern ZwFlushVirtualMemory alias _ZwFlushVirtualMemory@16
    extern ZwFreeVirtualMemory alias _ZwFreeVirtualMemory@16
    extern ZwFsControlFile alias _ZwFsControlFile@40
    extern ZwInitiatePowerAction alias _ZwInitiatePowerAction@16
    extern ZwIsProcessInJob alias _ZwIsProcessInJob@8
    extern ZwLoadDriver alias _ZwLoadDriver@4
    extern ZwLoadKey alias _ZwLoadKey@8
    extern ZwMakeTemporaryObject alias _ZwMakeTemporaryObject@4
    extern ZwMapViewOfSection alias _ZwMapViewOfSection@40
    extern ZwNotifyChangeKey alias _ZwNotifyChangeKey@40
    extern ZwOpenDirectoryObject alias _ZwOpenDirectoryObject@12
    extern ZwOpenEvent alias _ZwOpenEvent@12
    extern ZwOpenFile alias _ZwOpenFile@24
    extern ZwOpenJobObject alias _ZwOpenJobObject@12
    extern ZwOpenKey alias _ZwOpenKey@12
    extern ZwOpenProcess alias _ZwOpenProcess@16
    extern ZwOpenProcessToken alias _ZwOpenProcessToken@12
    extern ZwOpenProcessTokenEx alias _ZwOpenProcessTokenEx@16
    extern ZwOpenSection alias _ZwOpenSection@12
    extern ZwOpenSymbolicLinkObject alias _ZwOpenSymbolicLinkObject@12
    extern ZwOpenThread alias _ZwOpenThread@16
    extern ZwOpenThreadToken alias _ZwOpenThreadToken@16
    extern ZwOpenThreadTokenEx alias _ZwOpenThreadTokenEx@20
    extern ZwOpenTimer alias _ZwOpenTimer@12
    extern ZwPowerInformation alias _ZwPowerInformation@20
    extern ZwPulseEvent alias _ZwPulseEvent@8
    extern ZwQueryBootEntryOrder alias _ZwQueryBootEntryOrder@8
    extern ZwQueryBootOptions alias _ZwQueryBootOptions@8
    extern ZwQueryDefaultLocale alias _ZwQueryDefaultLocale@8
    extern ZwQueryDefaultUILanguage alias _ZwQueryDefaultUILanguage@4
    extern ZwQueryDirectoryFile alias _ZwQueryDirectoryFile@44
    extern ZwQueryDirectoryObject alias _ZwQueryDirectoryObject@28
    extern ZwQueryEaFile alias _ZwQueryEaFile@36
    extern ZwQueryFullAttributesFile alias _ZwQueryFullAttributesFile@8
    extern ZwQueryInformationFile alias _ZwQueryInformationFile@20
    extern ZwQueryInformationJobObject alias _ZwQueryInformationJobObject@20
    extern ZwQueryInformationProcess alias _ZwQueryInformationProcess@20
    extern ZwQueryInformationThread alias _ZwQueryInformationThread@20
    extern ZwQueryInformationToken alias _ZwQueryInformationToken@20
    extern ZwQueryInstallUILanguage alias _ZwQueryInstallUILanguage@4
    extern ZwQueryKey alias _ZwQueryKey@20
    extern ZwQueryObject alias _ZwQueryObject@20
    extern ZwQuerySection alias _ZwQuerySection@20
    extern ZwQuerySecurityObject alias _ZwQuerySecurityObject@20
    extern ZwQuerySymbolicLinkObject alias _ZwQuerySymbolicLinkObject@12
    extern ZwQuerySystemInformation alias _ZwQuerySystemInformation@16
    extern ZwQueryValueKey alias _ZwQueryValueKey@24
    extern ZwQueryVolumeInformationFile alias _ZwQueryVolumeInformationFile@20
    extern ZwReadFile alias _ZwReadFile@36
    extern ZwReplaceKey alias _ZwReplaceKey@12
    extern ZwRequestWaitReplyPort alias _ZwRequestWaitReplyPort@12
    extern ZwResetEvent alias _ZwResetEvent@8
    extern ZwRestoreKey alias _ZwRestoreKey@12
    extern ZwSaveKey alias _ZwSaveKey@8
    extern ZwSaveKeyEx alias _ZwSaveKeyEx@12
    extern ZwSetBootEntryOrder alias _ZwSetBootEntryOrder@8
    extern ZwSetBootOptions alias _ZwSetBootOptions@8
    extern ZwSetDefaultLocale alias _ZwSetDefaultLocale@8
    extern ZwSetDefaultUILanguage alias _ZwSetDefaultUILanguage@4
    extern ZwSetEaFile alias _ZwSetEaFile@16
    extern ZwSetEvent alias _ZwSetEvent@8
    extern ZwSetInformationFile alias _ZwSetInformationFile@20
    extern ZwSetInformationJobObject alias _ZwSetInformationJobObject@16
    extern ZwSetInformationObject alias _ZwSetInformationObject@16
    extern ZwSetInformationProcess alias _ZwSetInformationProcess@16
    extern ZwSetInformationThread alias _ZwSetInformationThread@16
    extern ZwSetSecurityObject alias _ZwSetSecurityObject@12
    extern ZwSetSystemInformation alias _ZwSetSystemInformation@12
    extern ZwSetSystemTime alias _ZwSetSystemTime@8
    extern ZwSetTimer alias _ZwSetTimer@28
    extern ZwSetValueKey alias _ZwSetValueKey@24
    extern ZwSetVolumeInformationFile alias _ZwSetVolumeInformationFile@20
    extern ZwTerminateJobObject alias _ZwTerminateJobObject@8
    extern ZwTerminateProcess alias _ZwTerminateProcess@8
    extern ZwTranslateFilePath alias _ZwTranslateFilePath@16
    extern ZwUnloadDriver alias _ZwUnloadDriver@4
    extern ZwUnloadKey alias _ZwUnloadKey@4
    extern ZwUnmapViewOfSection alias _ZwUnmapViewOfSection@8
    extern ZwWaitForMultipleObjects alias _ZwWaitForMultipleObjects@20
    extern ZwWaitForSingleObject alias _ZwWaitForSingleObject@12
    extern ZwWriteFile alias _ZwWriteFile@36
    extern ZwYieldExecution alias _ZwYieldExecution@0

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

;======================= Undocumented functions (unknown arguments) =======================;
#ifdef APP_WIN64
;    import BgkDisplayCharacter
;    import BgkGetConsoleState
;    import BgkGetCursorState
;    import BgkSetCursor
;    import CcAddDirtyPagesToExternalCache
;    import CcDeductDirtyPagesFromExternalCache
;    import CcFlushCacheToLsn
;    import CcRegisterExternalCache
;    import CcTestControl
;    import CcUnregisterExternalCache
;    import CcZeroDataOnDisk
;    import CmKeyObjectType
;    import DbgkLkmdRegisterCallback
;    import DbgkLkmdUnregisterCallback
;    import DbgkWerCaptureLiveKernelDump
;    import EmClientRuleDeregisterNotification
;    import EmClientRuleEvaluate
;    import EmClientRuleRegisterNotification
;    import EmpProviderRegister
;    import EmProviderDeregister
;    import EmProviderDeregisterEntry
;    import EmProviderRegister
;    import EmProviderRegisterEntry
;    import EtwEnableTrace
;    import EtwRegisterClassicProvider
;    import EtwSendTraceBuffer
;    import EtwSetInformation
;    import EtwWriteEndScenario
;    import CcFastReadNotPossible
;    import EtwWriteStartScenario
;    import ExAcquireAutoExpandPushLockExclusive
;    import ExAcquireAutoExpandPushLockShared
;    import ExAcquireCacheAwarePushLockExclusive
;    import ExAcquireCacheAwarePushLockExclusiveEx
;    import ExAcquireCacheAwarePushLockSharedEx
;    import ExAcquirePushLockExclusiveEx
;    import ExAcquirePushLockSharedEx
;    import ExAcquireRundownProtectionCacheAware
;    import ExAcquireRundownProtectionCacheAwareEx
;    import ExAllocateAutoExpandPushLock
;    import ExBlockOnAddressPushLock
;    import ExCleanupAutoExpandPushLock
;    import ExCleanupRundownProtectionCacheAware
;    import ExCompositionObjectType
;    import ExCompositionSurfaceObjectType
;    import ExConvertPushLockExclusiveToShared
;    import ExDesktopObjectType
;    import ExEnterPriorityRegionAndAcquireResourceExclusive
;    import ExEnterPriorityRegionAndAcquireResourceShared
;    import ExEventObjectType
;    import ExFetchLicenseData
;    import ExFreeAutoExpandPushLock
;    import ExFreeCacheAwareRundownProtection
;    import ExfTryAcquirePushLockShared
;    import ExGetLicenseTamperState
;    import ExiAcquireFastMutex
;    import ExInitializeAutoExpandPushLock
;    import ExInitializeRundownProtectionCacheAwareEx
;    import ExNotifyBootDeviceRemoval
;    import ExQueryAttributeInformation
;    import ExQueryFastCacheAppOrigin
;    import ExQueryFastCacheDevLicense
;    import ExQueryWnfStateData
;    import ExRawInputManagerObjectType
;    import ExRealTimeIsUniversal
;    import ExRegisterAttributeInformationCallback
;    import ExRegisterBootDevice
;    import ExRegisterExtension
;    import ExReleaseAutoExpandPushLockExclusive
;    import ExReleaseAutoExpandPushLockShared
;    import ExReleaseCacheAwarePushLockExclusiveEx
;    import ExReleaseCacheAwarePushLockSharedEx
;    import ExReleasePushLockEx
;    import ExReleasePushLockExclusiveEx
;    import ExReleasePushLockSharedEx
;    import ExReleaseResourceAndLeavePriorityRegion
;    import ExSemaphoreObjectType
;    import ExShareAddressSpaceWithDevice
;    import ExSizeOfAutoExpandPushLock
;    import ExSizeOfRundownProtectionCacheAware
;    import ExSubscribeWnfStateChange
;    import ExTimerObjectType
;    import ExTryAcquireAutoExpandPushLockExclusive
;    import ExTryAcquireAutoExpandPushLockShared
;    import ExTryAcquireCacheAwarePushLockExclusiveEx
;    import ExTryAcquireCacheAwarePushLockSharedEx
;    import ExTryAcquirePushLockExclusiveEx
;    import ExTryAcquirePushLockSharedEx
;    import ExTryConvertPushLockSharedToExclusiveEx
;    import ExTryQueueWorkItem
;    import ExTryToAcquireResourceExclusiveLite
;    import ExUnblockOnAddressPushLockEx
;    import ExUnblockPushLockEx
;    import ExUnregisterAttributeInformationCallback
;    import ExUnregisterExtension
;    import ExUnsubscribeWnfStateChange
;    import ExUpdateLicenseData
;    import ExWaitForRundownProtectionReleaseCacheAware
;    import ExWindowStationObjectType
;    import FsRtlAcquireEofLock
;    import FsRtlAcquireHeaderMutex
;    import FsRtlCheckUpperOplock
;    import FsRtlDismountComplete
;    import FsRtlGetFileNameInformation
;    import FsRtlGetIoAtEof
;    import FsRtlHeatInit
;    import FsRtlHeatLogIo
;    import FsRtlHeatLogTierMove
;    import FsRtlHeatUninit
;    import FsRtlInitializeBaseMcb
;    import FsRtlInitializeBaseMcbEx
;    import FsRtlInitializeEofLock
;    import FsRtlInsertReservedPerFileContext
;    import FsRtlInsertReservedPerStreamContext
;    import FsRtlIsMobileOS
;    import FsRtlKernelFsControlFile
;    import FsRtlLegalAnsiCharacterArray
;    import FsRtlLookupLastBaseMcbEntry
;    import FsRtlLookupReservedPerFileContext
;    import FsRtlLookupReservedPerStreamContext
;    import FsRtlNotifyFilterChangeDirectoryLite
;    import FsRtlNotifyFilterReportChangeLite
;    import FsRtlNumberOfRunsInBaseMcb
;    import FsRtlQueryInformationFile
;    import FsRtlQueryKernelEaFile
;    import FsRtlRegisterFltMgrCalls
;    import FsRtlRegisterMupCalls
;    import FsRtlRegisterUncProviderEx2
;    import FsRtlReleaseEofLock
;    import FsRtlReleaseFileNameInformation
;    import FsRtlReleaseHeaderMutex
;    import FsRtlRemoveReservedPerFileContext
;    import FsRtlRemoveReservedPerStreamContext
;    import FsRtlSendModernAppTermination
;    import FsRtlSetDriverBacking
;    import FsRtlSetKernelEaFile
;    import FsRtlTryToAcquireHeaderMutex
;    import FsRtlUpdateDiskCounters
;    import FsRtlValidateReparsePointBuffer
;    import HalDispatchTable
;    import HalPrivateDispatchTable
;    import HvlGetLpIndexFromApicId
;    import HviGetDebugDeviceOptions
;    import HviGetEnlightenmentInformation
;    import HviGetHardwareFeatures
;    import HviGetHypervisorFeatures
;    import HviGetHypervisorInterface
;    import HviGetHypervisorVendorAndMaxFunction
;    import HviGetHypervisorVersion
;    import HviGetImplementationLimits
;    import HviIsAnyHypervisorPresent
;    import HviIsHypervisorMicrosoftCompatible
;    import HviIsHypervisorVendorMicrosoft
;    import HviIsIommuInUse
;    import HvlPerformEndOfInterrupt
;    import HvlQueryActiveHypervisorProcessorCount
;    import HvlQueryActiveProcessors
;    import HvlQueryConnection
;    import HvlQueryHypervisorProcessorNodeNumber
;    import HvlQueryNumaDistance
;    import HvlQueryProcessorTopology
;    import HvlQueryProcessorTopologyCount
;    import HvlQueryProcessorTopologyHighestId
;    import HvlReadPerformanceStateCounters
;    import HvlRegisterInterruptCallback
;    import HvlRegisterWheaErrorNotification
;    import HvlUnregisterInterruptCallback
;    import HvlUnregisterWheaErrorNotification
;    import InbvNotifyDisplayOwnershipChange
;    import InbvSetVirtualFrameBuffer
;    import InitSafeBootMode
;    import IoAdapterObjectType
;    import IoAdjustStackSizeForRedirection
;    import IoAllocateIrpEx
;    import IoApplyPriorityInfoThread
;    import IoBoostThreadIo
;    import IoCallDriverStackSafe
;    import IoClearDependency
;    import IoClearReservedDependency
;    import IoCompletionObjectType
;    import IoConvertFileHandleToKernelHandle
;    import IoCopyDeviceObjectHint
;    import IoCreateArcName
;    import IoDeleteAllDependencyRelations
;    import IoDeviceHandlerObjectSize
;    import IoDeviceHandlerObjectType
;    import IoDeviceObjectType
;    import IoDriverObjectType
;    import IoDuplicateDependency
;    IoEnumerateRegisteredFiltersListEx
;    import IoFileObjectType
;    import IoFreeMiniCompletionPacket
;    import IoGetFsTrackOffsetState
;    import IoGetFsZeroingOffset
;    import IoGetGenericIrpExtension
;    import IoGetSymlinkSupportInformation
;    import IoInitializeMiniCompletionPacket
;    import IoIsActivityTracingEnabled
;    import IoLoadCrashDumpDriver
;    import IoMakeAssociatedIrpEx
;    import IoPropagateIrpExtension
;    import IoPropagateIrpExtensionEx
;    import IoQueryInterface
;    import IoQueueWorkItemToNode
;    import IoReadOperationCount
;    import IoReadTransferCount
;    import IoRegisterFsRegistrationChangeMountAwareEx
;    import IoRegisterIoTracking
;    import IoRegisterPriorityCallback
;    import IoRequestDeviceEjectEx
;    import IoReserveDependency
;    import IoResolveDependency
;    import IoRetrievePriorityInfo
;    import IoSetDependency
;    import IoSetGenericIrpExtension
;    import IoSetIoCompletionEx
;    import IoSetIoPriorityHintIntoFileObject
;    import IoSetIoPriorityHintIntoThread
;    import IoSizeofGenericIrpExtension
;    import IoStatisticsLock
;    import IoSynchronousCallDriver
;    import IoSteerInterrupt
;    import IoTestDependency
;    import IoUnregisterIoTracking
;    import IoVolumeDeviceNameToGuidPath
;    import IoVolumeDeviceToGuidPath
;    import IoWriteOperationCount
;    import IoWriteTransferCount
;    import iswalnum
;    import iswdigit
;    import iswspace
;    import KdAcquireDebuggerLock
;    import KdChangeOption
;    import KdDebuggerEnabled
;    import KdDebuggerNotPresent
;    import KdDeregisterPowerHandler
;    import KdEnteredDebugger
;    import KdEventLoggingEnabled
;    import KdGetDebugDevice
;    import KdRegisterPowerHandler
;    import KdReleaseDebuggerLock
;    import KdSetEventLoggingPresent
;    import KeAddGroupAffinityEx
;    import KeAddProcessorAffinityEx
;    import KeAddProcessorGroupAffinity
;    import KeAllocateCalloutStack
;    import KeAllocateCalloutStackEx
;    import KeAndGroupAffinityEx
;    import KeCancelTimer2
;    import KeCheckProcessorAffinityEx
;    import KeCheckProcessorGroupAffinity
;    import KeClockInterruptNotify
;    import KeClockTimerPowerChange
;    import KeConnectInterruptForHal
;    import KeCopyAffinityEx
;    import KeCountSetBitsAffinityEx
;    import KeCountSetBitsGroupAffinity
;    import KeDcacheFlushCount
;    import KeDispatchSecondaryInterrupt
;    import KeEnumerateNextProcessor
;    import KeFindFirstSetLeftGroupAffinity
;    import KeFindFirstSetRightAffinityEx
;    import KeFindFirstSetRightGroupAffinity
;    import KeFirstGroupAffinityEx
;    import KeForceEnableNx
;    import KeFreeCalloutStack
;    import KeGetClockOwner
;    import KeGetClockTimerResolution
;    import KeGetEffectiveIrql
;    import KeGetNextClockTickDuration
;    import KeGetNextTimerExpirationDueTime
;    import KeGetXSaveFeatureFlags
;    import KeHwPolicyLocateResource
;    import KeI386Call16BitCStyleFunction
;    import Kei386EoiHelper
;    import KeI386MachineType
;    import KeIcacheFlushCount
;    import KeInitializeAffinityEx
;    import KeInitializeEnumerationContextFromGroup
;    import KeInitializeSecondaryInterruptServices
;    import KeInitializeTimer2
;    import KeInterlockedClearProcessorAffinityEx
;    import KeIsSingleGroupAffinityEx
;    import KeLastBranchMSR
;    import KeLoaderBlock
;    import KeLoadMTRR
;    import KeNotifyProcessorFreezeSupported
;    import KeNumberProcessors
;    import KeOrAffinityEx
;    import KeProcessorGroupAffinity
;    import KeQueryActiveProcessorAffinity
;    import KeQueryEffectivePriorityThread
;    import KeQueryGroupAffinityEx
;    import KeQueryHeteroCpuPolicyThread
;    import KeQueryMultiThreadProcessorSet
;    import KeRemoveGroupAffinityEx
;    import KeRemoveProcessorAffinityEx
;    import KeRemoveProcessorGroupAffinity
;    import KeRemoveQueueDpcEx
;    import KeReportCacheIncoherentDevice
;    import KeRevertToUserAffinityThread
;    import KeServiceDescriptorTable
;    import KeSetActualBasePriorityThread
;    import KeSetHeteroCpuPolicyThread
;    import KeSetSelectedCpuSetsThread
;    import KeSetTimer2
;    import KeSignalCallDpcDone
;    import KeSignalCallDpcSynchronize
;    import KeStallWhileFrozen
;    import KeStartDynamicProcessor
;    import KeSubtractAffinityEx
;    import KeSweepLocalCaches
;    import KeSynchronizeTimeToQpc
;    import KeSystemFullyCacheCoherent
;    import KeTickCount
;    import KeUpdateSystemTime
;    import KeUpdateTime
;    import KeUpdateThreadTag
;    import KeUpdateTimeAssist
;    import KeWriteProtectPAT
;    import KfRaiseIrql
;    import KiBugCheckData
;    import KiCheckForSListAddress
;    import KiCpuId
;    import KiDispatchInterrupt
;    import KiEnableTimerWatchdog
;    import KitLogFeatureUsage
;    import KiUnexpectedInterrupt
;    import KseQueryDeviceData
;    import KseQueryDeviceDataList
;    import KseQueryDeviceFlags
;    import KseRegisterShim
;    import KseRegisterShimEx
;    import KseSetDeviceFlags
;    import KseUnregisterShim
;    import LdrFindResourceEx_U
;    import LdrResFindResource
;    import LdrResFindResourceDirectory
;    import LdrResSearchResource
;    import LpcPortObjectType
;    import LpcReplyWaitReplyPort
;    import LpcSendWaitReceivePort
;    import Mm64BitPhysicalAddress
;    import MmAddVerifierSpecialThunks
;    import MmAreMdlPagesCached
;    import MmBadPointer
;    import MmChangeImageProtection
;    import MmGetCacheAttribute
;    import MmHighestUserAddress
;    import MmMapViewInSessionSpaceEx
;    import MmMapViewInSystemSpaceEx
;    import MmMdlPageContentsState
;    import MmPrefetchVirtualAddresses
;    import MmSectionObjectType
;    import MmSetUserExceptionCallout
;    import MmSystemRangeStart
;    import MmUserProbeAddress
;    import NlsAnsiCodePage
;    import NlsLeadByteInfo
;    import NlsMbCodePageTag
;    import NlsMbOemCodePageTag
;    import NlsOemCodePage
;    import NtBuildGUID
;    import NtBuildLab
;    import NtBuildNumber
;    import NtGetEnvironmentVariableEx
;    import NtGlobalFlag
;    import NtQueryEnvironmentVariableInfoEx
;    import NtSetCachedSigningLevel
;    import NtSetInformationVirtualMemory
;    import ObfDereferenceObjectWithTag
;    import ObGetObjectType
;    import ObOpenObjectByNameEx
;    import ObReferenceObjectSafeWithTag
;    import ObWaitForMultipleObjects
;    import PfFileInfoNotify
;    import PoAllProcessorsDeepIdle
;    import PoCpuIdledSinceLastCallImprecise
;    import PoDisableSleepStates
;    import PoFxProcessorNotification
;    import PoEnergyEstimationEnabled
;    import PoFxEnableDStateReporting
;    import PoFxRegisterCoreDevice
;    import PoFxRegisterPlugin
;    import PoFxRegisterPluginEx
;    import PoFxRegisterPrimaryDevice
;    import PoGetProcessorIdleAccounting
;    import POGOBuffer
;    import PoInitiateProcessorWake
;    import PoLatencySensitivityHint
;    import PoNotifyDisableDynamicTick
;    import PoNotifyMediaBuffering
;    import PoNotifyVSyncChange
;    import PoQueueShutdownWorkItem
;    import PoReenableSleepStates
;    import PoRegisterCoalescingCallback
;    import PoSetFixedWakeSource
;    import PoSetUserPresent
;    import PoSetSystemWakeDevice
;    import PoUnregisterCoalescingCallback
;    import PoUserShutdownCancelled
;    import PoUserShutdownInitiated
;    import PsChargeProcessCpuCycles
;    import PsChargeProcessWakeCounter
;    import PsDereferenceKernelStack
;    import PsEnterPriorityRegion
;    import PsGetCurrentProcessWow64Process
;    import PsGetCurrentThreadWin32ThreadAndEnterCriticalRegion
;    import PsGetEffectiveContainerId
;    import PsGetJobProperty
;    import PsGetProcessCommonJob
;    import PsGetProcessProtection
;    import PsGetProcessServerSilo
;    import PsGetProcessSessionIdEx
;    import PsGetProcessSignatureLevel
;    import PsGetSiloIdentifier
;    import PsInitialSystemProcess
;    import PsIsProcessInAppSilo
;    import PsIsProtectedProcess
;    import PsIsProtectedProcessLight
;    import PsJobType
;    import PsLeavePriorityRegion
;    import psMUITest
;    import PsLoadedModuleList
;    import PsLoadedModuleResource
;    import PsUpdateComponentPower
;    import PsQueryProcessAttributesByToken
;    import PsQueryProcessExceptionFlags
;    import PsReferenceKernelStack
;    import PsReleaseProcessExitSynchronization
;    import PsReleaseProcessWakeCounter
;    import PsSetCreateProcessNotifyRoutineEx2
;    import PsSetJobProperty
;    import PsSetThreadProperty
;    import PsUILanguageComitted
;    import RtlAddAccessAllowedObjectAce
;    import RtlAddAtomToAtomTableEx
;    import RtlAddProcessTrustLabelAce
;    import RtlAddResourceAttributeAce
;    import RtlAreBitsClearEx
;    import RtlAreBitsSetEx
;    import RtlAvlInsertNodeEx
;    import RtlAvlRemoveNode
;    import RtlCapabilityCheck
;    import RtlCheckTokenCapability
;    import RtlCheckTokenMembership
;    import RtlCheckTokenMembershipEx
;    import RtlClearAllBitsEx
;    import RtlClearBitEx
;    import RtlClearBitsEx
;    import RtlContractHashTable
;    import RtlCopyBitMap
;    import RtlCopyMemoryNonTemporal
;    import RtlCrc32
;    import RtlCrc64
;    import RtlCreateAtomTableEx
;    import RtlCreateHashTable
;    import RtlCreateHashTableEx
;    import RtlDeleteHashTable
;    import RtlEndEnumerationHashTable
;    import RtlEndWeakEnumerationHashTable
;    import RtlEnumerateEntryHashTable
;    import RtlEqualWnfChangeStamps
;    import RtlExpandHashTable
;    import RtlExtractBitMap
;    import RtlFindAceByType
;    import RtlFindClearBitsAndSetEx
;    import RtlFindClearBitsEx
;    import RtlFindClosestEncodableLength
;    import RtlFindExportedRoutineByName
;    import RtlFindNextForwardRunClearEx
;    import RtlFindSetBitsAndClearEx
;    import RtlFindSetBitsEx
;    import RtlGenerateClass5Guid
;    import RtlGetAppContainerNamedObjectPath
;    import RtlGetAppContainerParent
;    import RtlGetAppContainerSidType
;    import RtlGetIntegerAtom
;    import RtlGetLastRange
;    import RtlGetProductInfo
;    import RtlIdnToAscii
;    import RtlIdnToNameprepUnicode
;    import RtlIdnToUnicode
;    import RtlImageNtHeaderEx
;    import RtlInitializeBitMapEx
;    import RtlInterlockedClearBitRun
;    import RtlInterlockedSetBitRun
;    import RtlInterlockedSetClearRun
;    import RtlInvertRangeListEx
;    import RtlIsMultiSessionSku
;    import RtlIsSandboxedToken
;    import RtlIsUntrustedObject
;    import RtlLCIDToCultureName
;    import RtlLoadString
;    import RtlNormalizeString
;    import RtlNumberOfClearBitsEx
;    import RtlNumberOfClearBitsInRange
;    import RtlNumberOfSetBitsEx
;    import RtlNumberOfSetBitsInRange
;    import RtlOwnerAcesPresent
;    import RtlQueryDynamicTimeZoneInformation
;    import RtlQueryModuleInformation
;    import RtlQueryPackageClaims
;    import RtlQueryPackageIdentity
;    import RtlQueryRegistryValuesEx
;    import RtlQueryValidationRunlevel
;    import RtlRbReplaceNode
;    import RtlRemoveEntryHashTable
;    import RtlReplaceSidInSd
;    import RtlSetAllBitsEx
;    import RtlSetBitEx
;    import RtlSetBitsEx
;    import RtlSetDynamicTimeZoneInformation
;    import RtlSetPortableOperatingSystem
;    import RtlSidHashInitialize
;    import RtlSidHashLookup
;    import RtlTestBitEx
;    import RtlWeaklyEnumerateEntryHashTable
;    import SeAccessCheckFromState
;    import SeAccessCheckFromStateEx
;    import SeAccessCheckWithHint
;    import SeAuditingAnyFileEventsWithContextEx
;    import SeAuditingFileEventsWithContextEx
;    import SeAuditingWithTokenForSubcategory
;    import SeCloseObjectAuditAlarmForNonObObject
;    import SeCompareSigningLevels
;    import SeCreateClientSecurityEx
;    import SeCreateClientSecurityFromSubjectContextEx
;    import SeExports
;    import SeGetCachedSigningLevel
;    import SeGetLinkedToken
;    import SeGetLogonSessionToken
;    import SeIsParentOfChildAppContainer
;    import SeOpenObjectAuditAlarmForNonObObject
;    import SeOpenObjectAuditAlarmWithTransaction
;    import SePublicDefaultDacl
;    import SeQuerySecureBootPolicyValue
;    import SeQuerySecurityAttributesToken
;    import SeRegisterImageVerificationCallback
;    import SeSecurityAttributePresent
;    import SeSetAuthorizationCallbacks
;    import SeSetSecurityAttributesToken
;    import SeSetSecurityAttributesTokenEx
;    import SeSrpAccessCheck
;    import SeSystemDefaultDacl
;    import SeSystemDefaultSd
;    import SeTokenFromAccessInformation
;    import SeUnregisterImageVerificationCallback
;    import SkAcquirePushLockExclusive
;    import SkAllocatePool
;    import SkFreePool
;    import SkInitializePushLock
;    import SkIsSecureKernel
;    import SkQuerySecureKernelInformation
;    import SkReleasePushLockExclusive
;    import sprintf
;    import sprintf_s
;    import sqrt
;    import sqrtf
;    import srand
;    import sscanf_s
;    import strcat
;    import strcat_s
;    import strchr
;    import strcmp
;    import strcpy
;    import strcpy_s
;    import strlen
;    import strncat
;    import strncat_s
;    import strncmp
;    import strncpy
;    import strncpy_s
;    import strnlen
;    import strrchr
;    import strspn
;    import strstr
;    import strtok_s
;    import swprintf
;    import swprintf_s
;    import swscanf_s
;    import TmCancelPropagationRequest
;    import TmCurrentTransaction
;    import TmEndPropagationRequest
;    import TmEnlistmentObjectType
;    import TmFreezeTransactions
;    import TmInitializeResourceManager
;    import TmInitializeTransaction
;    import TmInitSystem
;    import TmInitSystemPhase2
;    import TmIsKTMCommitCoordinator
;    import TmpIsKTMCommitCoordinator
;    import TmPropagationComplete
;    import TmPropagationFailed
;    import TmResourceManagerObjectType
;    import TmSetCurrentTransaction
;    import TmThawTransactions
;    import TmTransactionManagerObjectType
;    import TmTransactionObjectType
;    import VfCheckNxPagePriority
;    import VfCheckNxPageProtection
;    import VfCheckNxPoolType
;    import VfFailDeviceNode
;    import VfFailDriver
;    import VfFailSystemBIOS
;    import VfInsertContext
;    import VfQueryDeviceContext
;    import VfQueryDispatchTable
;    import VfQueryDriverContext
;    import VfQueryIrpContext
;    import VfQueryThreadContext
;    import VfRemoveContext
;    import VmAccessFault
;    import VmCreateMemoryRange
;    import VmDeleteMemoryRange
;    import VslExchangeEntropy
;    import VslRetrieveMailbox
;    import WheaAttemptPhysicalPageOffline
;    import WheaConfigureErrorSource
;    import WheaDeferredRecoveryService
;    import WheaGetErrorSource
;    import WheaInitializeDeferredRecoveryObject
;    import WheaInitializeRecordHeader
;    import WheaRegisterErrSrcInitializer
;    import WheaReportHwError
;    import WheaRequestDeferredRecovery
;    import ZwAlpcConnectPortEx
;    import ZwCreateWnfStateName
;    import ZwDeleteDriverEntry
;    import ZwDeleteWnfStateData
;    import ZwDeleteWnfStateName
;    import ZwNotifyChangeSession
;    import ZwQueryLicenseValue
;    import ZwQueryWnfStateData
;    import ZwQueryWnfStateNameInformation
;    import ZwSetCachedSigningLevel
;    import ZwSetInformationVirtualMemory
;    import ZwUpdateWnfStateData
;    import _abnormal_termination
;    import _alloca_probe
;    import _alloca_probe_16
;    import _alloca_probe_8
;    import _CIcos
;    import _CIsin
;    import _CIsqrt
;    import _local_unwind
;    #ifndef __misaligned_access
;        import __misaligned_access
;    #endif
;    import _snscanf_s
;    import _snwprintf
;    import _snwprintf_s
;    import _snwscanf_s
#else
;    extern alias _BgkDisplayCharacter@??
;    extern alias _BgkGetConsoleState@??
;    extern alias _BgkGetCursorState@??
;    extern alias _BgkSetCursor@??
;    extern alias _CcAddDirtyPagesToExternalCache@??
;    extern alias _CcDeductDirtyPagesFromExternalCache@??
;    extern alias _CcFlushCacheToLsn@??
;    extern alias _CcRegisterExternalCache@??
;    extern alias _CcTestControl@??
;    extern alias _CcUnregisterExternalCache@??
;    extern alias _CcZeroDataOnDisk@??
;    extern alias _CmKeyObjectType@??
;    extern alias _DbgkLkmdRegisterCallback@??
;    extern alias _DbgkLkmdUnregisterCallback@??
;    extern alias _DbgkWerCaptureLiveKernelDump@??
;    extern alias _EmClientRuleDeregisterNotification@??
;    extern alias _EmClientRuleEvaluate@??
;    extern alias _EmClientRuleRegisterNotification@??
;    extern alias _EmpProviderRegister@??
;    extern alias _EmProviderDeregister@??
;    extern alias _EmProviderDeregisterEntry@??
;    extern alias _EmProviderRegister@??
;    extern alias _EmProviderRegisterEntry@??
;    extern alias _EtwEnableTrace@??
;    extern alias _EtwRegisterClassicProvider@??
;    extern alias _EtwSendTraceBuffer@??
;    extern alias _EtwSetInformation@??
;    extern alias _EtwWriteEndScenario@??
;    extern alias _CcFastReadNotPossible@??
;    extern alias _EtwWriteStartScenario@??
;    extern alias _ExAcquireAutoExpandPushLockExclusive@??
;    extern alias _ExAcquireAutoExpandPushLockShared@??
;    extern alias _ExAcquireCacheAwarePushLockExclusive@??
;    extern alias _ExAcquireCacheAwarePushLockExclusiveEx@??
;    extern alias _ExAcquireCacheAwarePushLockSharedEx@??
;    extern alias _ExAcquirePushLockExclusiveEx@??
;    extern alias _ExAcquirePushLockSharedEx@??
;    extern alias _ExAcquireRundownProtectionCacheAware@??
;    extern alias _ExAcquireRundownProtectionCacheAwareEx@??
;    extern alias _ExAllocateAutoExpandPushLock@??
;    extern alias _ExBlockOnAddressPushLock@??
;    extern alias _ExCleanupAutoExpandPushLock@??
;    extern alias _ExCleanupRundownProtectionCacheAware@??
;    extern alias _ExCompositionObjectType@??
;    extern alias _ExCompositionSurfaceObjectType@??
;    extern alias _ExConvertPushLockExclusiveToShared@??
;    extern alias _ExDesktopObjectType@??
;    extern alias _ExEnterPriorityRegionAndAcquireResourceExclusive@??
;    extern alias _ExEnterPriorityRegionAndAcquireResourceShared@??
;    extern alias _ExEventObjectType@??
;    extern alias _ExFetchLicenseData@??
;    extern alias _ExFreeAutoExpandPushLock@??
;    extern alias _ExFreeCacheAwareRundownProtection@??
;    extern alias _ExfTryAcquirePushLockShared@??
;    extern alias _ExGetLicenseTamperState@??
;    extern alias _ExiAcquireFastMutex@??
;    extern alias _ExInitializeAutoExpandPushLock@??
;    extern alias _ExInitializeRundownProtectionCacheAwareEx@??
;    extern alias _ExNotifyBootDeviceRemoval@??
;    extern alias _ExQueryAttributeInformation@??
;    extern alias _ExQueryFastCacheAppOrigin@??
;    extern alias _ExQueryFastCacheDevLicense@??
;    extern alias _ExQueryWnfStateData@??
;    extern alias _ExRawInputManagerObjectType@??
;    extern alias _ExRealTimeIsUniversal@??
;    extern alias _ExRegisterAttributeInformationCallback@??
;    extern alias _ExRegisterBootDevice@??
;    extern alias _ExRegisterExtension@??
;    extern alias _ExReleaseAutoExpandPushLockExclusive@??
;    extern alias _ExReleaseAutoExpandPushLockShared@??
;    extern alias _ExReleaseCacheAwarePushLockExclusiveEx@??
;    extern alias _ExReleaseCacheAwarePushLockSharedEx@??
;    extern alias _ExReleasePushLockEx@??
;    extern alias _ExReleasePushLockExclusiveEx@??
;    extern alias _ExReleasePushLockSharedEx@??
;    extern alias _ExReleaseResourceAndLeavePriorityRegion@??
;    extern alias _ExSemaphoreObjectType@??
;    extern alias _ExShareAddressSpaceWithDevice@??
;    extern alias _ExSizeOfAutoExpandPushLock@??
;    extern alias _ExSizeOfRundownProtectionCacheAware@??
;    extern alias _ExSubscribeWnfStateChange@??
;    extern alias _ExTimerObjectType@??
;    extern alias _ExTryAcquireAutoExpandPushLockExclusive@??
;    extern alias _ExTryAcquireAutoExpandPushLockShared@??
;    extern alias _ExTryAcquireCacheAwarePushLockExclusiveEx@??
;    extern alias _ExTryAcquireCacheAwarePushLockSharedEx@??
;    extern alias _ExTryAcquirePushLockExclusiveEx@??
;    extern alias _ExTryAcquirePushLockSharedEx@??
;    extern alias _ExTryConvertPushLockSharedToExclusiveEx@??
;    extern alias _ExTryQueueWorkItem@??
;    extern alias _ExTryToAcquireResourceExclusiveLite@??
;    extern alias _ExUnblockOnAddressPushLockEx@??
;    extern alias _ExUnblockPushLockEx@??
;    extern alias _ExUnregisterAttributeInformationCallback@??
;    extern alias _ExUnregisterExtension@??
;    extern alias _ExUnsubscribeWnfStateChange@??
;    extern alias _ExUpdateLicenseData@??
;    extern alias _ExWaitForRundownProtectionReleaseCacheAware@??
;    extern alias _ExWindowStationObjectType@??
;    extern alias _FsRtlAcquireEofLock@??
;    extern alias _FsRtlAcquireHeaderMutex@??
;    extern alias _FsRtlCheckUpperOplock@??
;    extern alias _FsRtlDismountComplete@??
;    extern alias _FsRtlGetFileNameInformation@??
;    extern alias _FsRtlGetIoAtEof@??
;    extern alias _FsRtlHeatInit@??
;    extern alias _FsRtlHeatLogIo@??
;    extern alias _FsRtlHeatLogTierMove@??
;    extern alias _FsRtlHeatUninit@??
;    extern alias _FsRtlInitializeBaseMcb@??
;    extern alias _FsRtlInitializeBaseMcbEx@??
;    extern alias _FsRtlInitializeEofLock@??
;    extern alias _FsRtlInsertReservedPerFileContext@??
;    extern alias _FsRtlInsertReservedPerStreamContext@??
;    extern alias _FsRtlIsMobileOS@??
;    extern alias _FsRtlKernelFsControlFile@??
;    extern alias _FsRtlLegalAnsiCharacterArray@??
;    extern alias _FsRtlLookupLastBaseMcbEntry@??
;    extern alias _FsRtlLookupReservedPerFileContext@??
;    extern alias _FsRtlLookupReservedPerStreamContext@??
;    extern alias _FsRtlNotifyFilterChangeDirectoryLite@??
;    extern alias _FsRtlNotifyFilterReportChangeLite@??
;    extern alias _FsRtlNumberOfRunsInBaseMcb@??
;    extern alias _FsRtlQueryInformationFile@??
;    extern alias _FsRtlQueryKernelEaFile@??
;    extern alias _FsRtlRegisterFltMgrCalls@??
;    extern alias _FsRtlRegisterMupCalls@??
;    extern alias _FsRtlRegisterUncProviderEx2@??
;    extern alias _FsRtlReleaseEofLock@??
;    extern alias _FsRtlReleaseFileNameInformation@??
;    extern alias _FsRtlReleaseHeaderMutex@??
;    extern alias _FsRtlRemoveReservedPerFileContext@??
;    extern alias _FsRtlRemoveReservedPerStreamContext@??
;    extern alias _FsRtlSendModernAppTermination@??
;    extern alias _FsRtlSetDriverBacking@??
;    extern alias _FsRtlSetKernelEaFile@??
;    extern alias _FsRtlTryToAcquireHeaderMutex@??
;    extern alias _FsRtlUpdateDiskCounters@??
;    extern alias _FsRtlValidateReparsePointBuffer@??
;    extern alias _HalDispatchTable@??
;    extern alias _HalPrivateDispatchTable@??
;    extern alias _HvlGetLpIndexFromApicId@??
;    extern alias _HviGetDebugDeviceOptions@??
;    extern alias _HviGetEnlightenmentInformation@??
;    extern alias _HviGetHardwareFeatures@??
;    extern alias _HviGetHypervisorFeatures@??
;    extern alias _HviGetHypervisorInterface@??
;    extern alias _HviGetHypervisorVendorAndMaxFunction@??
;    extern alias _HviGetHypervisorVersion@??
;    extern alias _HviGetImplementationLimits@??
;    extern alias _HviIsAnyHypervisorPresent@??
;    extern alias _HviIsHypervisorMicrosoftCompatible@??
;    extern alias _HviIsHypervisorVendorMicrosoft@??
;    extern alias _HviIsIommuInUse@??
;    extern alias _HvlPerformEndOfInterrupt@??
;    extern alias _HvlQueryActiveHypervisorProcessorCount@??
;    extern alias _HvlQueryActiveProcessors@??
;    extern alias _HvlQueryConnection@??
;    extern alias _HvlQueryHypervisorProcessorNodeNumber@??
;    extern alias _HvlQueryNumaDistance@??
;    extern alias _HvlQueryProcessorTopology@??
;    extern alias _HvlQueryProcessorTopologyCount@??
;    extern alias _HvlQueryProcessorTopologyHighestId@??
;    extern alias _HvlReadPerformanceStateCounters@??
;    extern alias _HvlRegisterInterruptCallback@??
;    extern alias _HvlRegisterWheaErrorNotification@??
;    extern alias _HvlUnregisterInterruptCallback@??
;    extern alias _HvlUnregisterWheaErrorNotification@??
;    extern alias _InbvNotifyDisplayOwnershipChange@??
;    extern alias _InbvSetVirtualFrameBuffer@??
;    extern alias _InitSafeBootMode@??
;    extern alias _IoAdapterObjectType@??
;    extern alias _IoAdjustStackSizeForRedirection@??
;    extern alias _IoAllocateIrpEx@??
;    extern alias _IoApplyPriorityInfoThread@??
;    extern alias _IoBoostThreadIo@??
;    extern alias _IoCallDriverStackSafe@??
;    extern alias _IoClearDependency@??
;    extern alias _IoClearReservedDependency@??
;    extern alias _IoCompletionObjectType@??
;    extern alias _IoConvertFileHandleToKernelHandle@??
;    extern alias _IoCopyDeviceObjectHint@??
;    extern alias _IoCreateArcName@??
;    extern alias _IoDeleteAllDependencyRelations@??
;    extern alias _IoDeviceHandlerObjectSize@??
;    extern alias _IoDeviceHandlerObjectType@??
;    extern alias _IoDeviceObjectType@??
;    extern alias _IoDriverObjectType@??
;    extern alias _IoDuplicateDependency@??
;    extern alias _IoEnumerateRegisteredFiltersListEx@??
;    extern alias _IoFileObjectType@??
;    extern alias _IoFreeMiniCompletionPacket@??
;    extern alias _IoGetFsTrackOffsetState@??
;    extern alias _IoGetFsZeroingOffset@??
;    extern alias _IoGetGenericIrpExtension@??
;    extern alias _IoGetSymlinkSupportInformation@??
;    extern alias _IoInitializeMiniCompletionPacket@??
;    extern alias _IoIsActivityTracingEnabled@??
;    extern alias _IoLoadCrashDumpDriver@??
;    extern alias _IoMakeAssociatedIrpEx@??
;    extern alias _IoPropagateIrpExtension@??
;    extern alias _IoPropagateIrpExtensionEx@??
;    extern alias _IoQueryInterface@??
;    extern alias _IoQueueWorkItemToNode@??
;    extern alias _IoReadOperationCount@??
;    extern alias _IoReadTransferCount@??
;    extern alias _IoRegisterFsRegistrationChangeMountAwareEx@??
;    extern alias _IoRegisterIoTracking@??
;    extern alias _IoRegisterPriorityCallback@??
;    extern alias _IoRequestDeviceEjectEx@??
;    extern alias _IoReserveDependency@??
;    extern alias _IoResolveDependency@??
;    extern alias _IoRetrievePriorityInfo@??
;    extern alias _IoSetDependency@??
;    extern alias _IoSetGenericIrpExtension@??
;    extern alias _IoSetIoCompletionEx@??
;    extern alias _IoSetIoPriorityHintIntoFileObject@??
;    extern alias _IoSetIoPriorityHintIntoThread@??
;    extern alias _IoSizeofGenericIrpExtension@??
;    extern alias _IoStatisticsLock@??
;    extern alias _IoSynchronousCallDriver@??
;    extern alias _IoSteerInterrupt@??
;    extern alias _IoTestDependency@??
;    extern alias _IoUnregisterIoTracking@??
;    extern alias _IoVolumeDeviceNameToGuidPath@??
;    extern alias _IoVolumeDeviceToGuidPath@??
;    extern alias _IoWriteOperationCount@??
;    extern alias _IoWriteTransferCount@??
;    extern alias _iswalnum@??
;    extern alias _iswdigit@??
;    extern alias _iswspace@??
;    extern alias _KdAcquireDebuggerLock@??
;    extern alias _KdChangeOption@??
;    extern alias _KdDebuggerEnabled@??
;    extern alias _KdDebuggerNotPresent@??
;    extern alias _KdDeregisterPowerHandler@??
;    extern alias _KdEnteredDebugger@??
;    extern alias _KdEventLoggingEnabled@??
;    extern alias _KdGetDebugDevice@??
;    extern alias _KdRegisterPowerHandler@??
;    extern alias _KdReleaseDebuggerLock@??
;    extern alias _KdSetEventLoggingPresent@??
;    extern alias _KeAddGroupAffinityEx@??
;    extern alias _KeAddProcessorAffinityEx@??
;    extern alias _KeAddProcessorGroupAffinity@??
;    extern alias _KeAllocateCalloutStack@??
;    extern alias _KeAllocateCalloutStackEx@??
;    extern alias _KeAndGroupAffinityEx@??
;    extern alias _KeCancelTimer2@??
;    extern alias _KeCheckProcessorAffinityEx@??
;    extern alias _KeCheckProcessorGroupAffinity@??
;    extern alias _KeClockInterruptNotify@??
;    extern alias _KeClockTimerPowerChange@??
;    extern alias _KeConnectInterruptForHal@??
;    extern alias _KeCopyAffinityEx@??
;    extern alias _KeCountSetBitsAffinityEx@??
;    extern alias _KeCountSetBitsGroupAffinity@??
;    extern alias _KeDcacheFlushCount@??
;    extern alias _KeDispatchSecondaryInterrupt@??
;    extern alias _KeEnumerateNextProcessor@??
;    extern alias _KeFindFirstSetLeftGroupAffinity@??
;    extern alias _KeFindFirstSetRightAffinityEx@??
;    extern alias _KeFindFirstSetRightGroupAffinity@??
;    extern alias _KeFirstGroupAffinityEx@??
;    extern alias _KeForceEnableNx@??
;    extern alias _KeFreeCalloutStack@??
;    extern alias _KeGetClockOwner@??
;    extern alias _KeGetClockTimerResolution@??
;    extern alias _KeGetEffectiveIrql@??
;    extern alias _KeGetNextClockTickDuration@??
;    extern alias _KeGetNextTimerExpirationDueTime@??
;    extern alias _KeGetXSaveFeatureFlags@??
;    extern alias _KeHwPolicyLocateResource@??
;    extern alias _KeI386Call16BitCStyleFunction@??
;    extern alias _Kei386EoiHelper@??
;    extern alias _KeI386MachineType@??
;    extern alias _KeIcacheFlushCount@??
;    extern alias _KeInitializeAffinityEx@??
;    extern alias _KeInitializeEnumerationContextFromGroup@??
;    extern alias _KeInitializeSecondaryInterruptServices@??
;    extern alias _KeInitializeTimer2@??
;    extern alias _KeInterlockedClearProcessorAffinityEx@??
;    extern alias _KeIsSingleGroupAffinityEx@??
;    extern alias _KeLastBranchMSR@??
;    extern alias _KeLoaderBlock@??
;    extern alias _KeLoadMTRR@??
;    extern alias _KeNotifyProcessorFreezeSupported@??
;    extern alias _KeNumberProcessors@??
;    extern alias _KeOrAffinityEx@??
;    extern alias _KeProcessorGroupAffinity@??
;    extern alias _KeQueryActiveProcessorAffinity@??
;    extern alias _KeQueryEffectivePriorityThread@??
;    extern alias _KeQueryGroupAffinityEx@??
;    extern alias _KeQueryHeteroCpuPolicyThread@??
;    extern alias _KeQueryMultiThreadProcessorSet@??
;    extern alias _KeRemoveGroupAffinityEx@??
;    extern alias _KeRemoveProcessorAffinityEx@??
;    extern alias _KeRemoveProcessorGroupAffinity@??
;    extern alias _KeRemoveQueueDpcEx@??
;    extern alias _KeReportCacheIncoherentDevice@??
;    extern alias _KeRevertToUserAffinityThread@??
;    extern alias _KeServiceDescriptorTable@??
;    extern alias _KeSetActualBasePriorityThread@??
;    extern alias _KeSetHeteroCpuPolicyThread@??
;    extern alias _KeSetSelectedCpuSetsThread@??
;    extern alias _KeSetTimer2@??
;    extern alias _KeSignalCallDpcDone@??
;    extern alias _KeSignalCallDpcSynchronize@??
;    extern alias _KeStallWhileFrozen@??
;    extern alias _KeStartDynamicProcessor@??
;    extern alias _KeSubtractAffinityEx@??
;    extern alias _KeSweepLocalCaches@??
;    extern alias _KeSynchronizeTimeToQpc@??
;    extern alias _KeSystemFullyCacheCoherent@??
;    extern alias _KeTickCount@??
;    extern alias _KeUpdateSystemTime@??
;    extern alias _KeUpdateTime@??
;    extern alias _KeUpdateThreadTag@??
;    extern alias _KeUpdateTimeAssist@??
;    extern alias _KeWriteProtectPAT@??
;    extern alias _KfRaiseIrql@??
;    extern alias _KiBugCheckData@??
;    extern alias _KiCheckForSListAddress@??
;    extern alias _KiCpuId@??
;    extern alias _KiDispatchInterrupt@??
;    extern alias _KiEnableTimerWatchdog@??
;    extern alias _KitLogFeatureUsage@??
;    extern alias _KiUnexpectedInterrupt@??
;    extern alias _KseQueryDeviceData@??
;    extern alias _KseQueryDeviceDataList@??
;    extern alias _KseQueryDeviceFlags@??
;    extern alias _KseRegisterShim@??
;    extern alias _KseRegisterShimEx@??
;    extern alias _KseSetDeviceFlags@??
;    extern alias _KseUnregisterShim@??
;    extern alias _LdrFindResourceEx_U@??
;    extern alias _LdrResFindResource@??
;    extern alias _LdrResFindResourceDirectory@??
;    extern alias _LdrResSearchResource@??
;    extern alias _LpcPortObjectType@??
;    extern alias _LpcReplyWaitReplyPort@??
;    extern alias _LpcSendWaitReceivePort@??
;    extern alias _Mm64BitPhysicalAddress@??
;    extern alias _MmAddVerifierSpecialThunks@??
;    extern alias _MmAreMdlPagesCached@??
;    extern alias _MmBadPointer@??
;    extern alias _MmChangeImageProtection@??
;    extern alias _MmGetCacheAttribute@??
;    extern alias _MmHighestUserAddress@??
;    extern alias _MmMapViewInSessionSpaceEx@??
;    extern alias _MmMapViewInSystemSpaceEx@??
;    extern alias _MmMdlPageContentsState@??
;    extern alias _MmPrefetchVirtualAddresses@??
;    extern alias _MmSectionObjectType@??
;    extern alias _MmSetUserExceptionCallout@??
;    extern alias _MmSystemRangeStart@??
;    extern alias _MmUserProbeAddress@??
;    extern alias _NlsAnsiCodePage@??
;    extern alias _NlsLeadByteInfo@??
;    extern alias _NlsMbCodePageTag@??
;    extern alias _NlsMbOemCodePageTag@??
;    extern alias _NlsOemCodePage@??
;    extern alias _NtBuildGUID@??
;    extern alias _NtBuildLab@??
;    extern alias _NtBuildNumber@??
;    extern alias _NtGetEnvironmentVariableEx@??
;    extern alias _NtGlobalFlag@??
;    extern alias _NtQueryEnvironmentVariableInfoEx@??
;    extern alias _NtSetCachedSigningLevel@??
;    extern alias _NtSetInformationVirtualMemory@??
;    extern alias _ObfDereferenceObjectWithTag@??
;    extern alias _ObGetObjectType@??
;    extern alias _ObOpenObjectByNameEx@??
;    extern alias _ObReferenceObjectSafeWithTag@??
;    extern alias _ObWaitForMultipleObjects@??
;    extern alias _PfFileInfoNotify@??
;    extern alias _PoAllProcessorsDeepIdle@??
;    extern alias _PoCpuIdledSinceLastCallImprecise@??
;    extern alias _PoDisableSleepStates@??
;    extern alias _PoFxProcessorNotification@??
;    extern alias _PoEnergyEstimationEnabled@??
;    extern alias _PoFxEnableDStateReporting@??
;    extern alias _PoFxRegisterCoreDevice@??
;    extern alias _PoFxRegisterPlugin@??
;    extern alias _PoFxRegisterPluginEx@??
;    extern alias _PoFxRegisterPrimaryDevice@??
;    extern alias _PoGetProcessorIdleAccounting@??
;    extern alias _POGOBuffer@??
;    extern alias _PoInitiateProcessorWake@??
;    extern alias _PoLatencySensitivityHint@??
;    extern alias _PoNotifyDisableDynamicTick@??
;    extern alias _PoNotifyMediaBuffering@??
;    extern alias _PoNotifyVSyncChange@??
;    extern alias _PoQueueShutdownWorkItem@??
;    extern alias _PoReenableSleepStates@??
;    extern alias _PoRegisterCoalescingCallback@??
;    extern alias _PoSetFixedWakeSource@??
;    extern alias _PoSetUserPresent@??
;    extern alias _PoSetSystemWakeDevice@??
;    extern alias _PoUnregisterCoalescingCallback@??
;    extern alias _PoUserShutdownCancelled@??
;    extern alias _PoUserShutdownInitiated@??
;    extern alias _PsChargeProcessCpuCycles@??
;    extern alias _PsChargeProcessWakeCounter@??
;    extern alias _PsDereferenceKernelStack@??
;    extern alias _PsEnterPriorityRegion@??
;    extern alias _PsGetCurrentProcessWow64Process@??
;    extern alias _PsGetCurrentThreadWin32ThreadAndEnterCriticalRegion@??
;    extern alias _PsGetEffectiveContainerId@??
;    extern alias _PsGetJobProperty@??
;    extern alias _PsGetProcessCommonJob@??
;    extern alias _PsGetProcessProtection@??
;    extern alias _PsGetProcessServerSilo@??
;    extern alias _PsGetProcessSessionIdEx@??
;    extern alias _PsGetProcessSignatureLevel@??
;    extern alias _PsGetSiloIdentifier@??
;    extern alias _PsInitialSystemProcess@??
;    extern alias _PsIsProcessInAppSilo@??
;    extern alias _PsIsProtectedProcess@??
;    extern alias _PsIsProtectedProcessLight@??
;    extern alias _PsJobType@??
;    extern alias _PsLeavePriorityRegion@??
;    extern alias _psMUITest@??
;    extern alias _PsLoadedModuleList@??
;    extern alias _PsLoadedModuleResource@??
;    extern alias _PsUpdateComponentPower@??
;    extern alias _PsQueryProcessAttributesByToken@??
;    extern alias _PsQueryProcessExceptionFlags@??
;    extern alias _PsReferenceKernelStack@??
;    extern alias _PsReleaseProcessExitSynchronization@??
;    extern alias _PsReleaseProcessWakeCounter@??
;    extern alias _PsSetCreateProcessNotifyRoutineEx2@??
;    extern alias _PsSetJobProperty@??
;    extern alias _PsSetThreadProperty@??
;    extern alias _PsUILanguageComitted@??
;    extern alias _RtlAddAccessAllowedObjectAce@??
;    extern alias _RtlAddAtomToAtomTableEx@??
;    extern alias _RtlAddProcessTrustLabelAce@??
;    extern alias _RtlAddResourceAttributeAce@??
;    extern alias _RtlAreBitsClearEx@??
;    extern alias _RtlAreBitsSetEx@??
;    extern alias _RtlAvlInsertNodeEx@??
;    extern alias _RtlAvlRemoveNode@??
;    extern alias _RtlCapabilityCheck@??
;    extern alias _RtlCheckTokenCapability@??
;    extern alias _RtlCheckTokenMembership@??
;    extern alias _RtlCheckTokenMembershipEx@??
;    extern alias _RtlClearAllBitsEx@??
;    extern alias _RtlClearBitEx@??
;    extern alias _RtlClearBitsEx@??
;    extern alias _RtlContractHashTable@??
;    extern alias _RtlCopyBitMap@??
;    extern alias _RtlCopyMemoryNonTemporal@??
;    extern alias _RtlCrc32@??
;    extern alias _RtlCrc64@??
;    extern alias _RtlCreateAtomTableEx@??
;    extern alias _RtlCreateHashTable@??
;    extern alias _RtlCreateHashTableEx@??
;    extern alias _RtlDeleteHashTable@??
;    extern alias _RtlEndEnumerationHashTable@??
;    extern alias _RtlEndWeakEnumerationHashTable@??
;    extern alias _RtlEnumerateEntryHashTable@??
;    extern alias _RtlEqualWnfChangeStamps@??
;    extern alias _RtlExpandHashTable@??
;    extern alias _RtlExtractBitMap@??
;    extern alias _RtlFindAceByType@??
;    extern alias _RtlFindClearBitsAndSetEx@??
;    extern alias _RtlFindClearBitsEx@??
;    extern alias _RtlFindClosestEncodableLength@??
;    extern alias _RtlFindExportedRoutineByName@??
;    extern alias _RtlFindNextForwardRunClearEx@??
;    extern alias _RtlFindSetBitsAndClearEx@??
;    extern alias _RtlFindSetBitsEx@??
;    extern alias _RtlGenerateClass5Guid@??
;    extern alias _RtlGetAppContainerNamedObjectPath@??
;    extern alias _RtlGetAppContainerParent@??
;    extern alias _RtlGetAppContainerSidType@??
;    extern alias _RtlGetIntegerAtom@??
;    extern alias _RtlGetLastRange@??
;    extern alias _RtlGetProductInfo@??
;    extern alias _RtlIdnToAscii@??
;    extern alias _RtlIdnToNameprepUnicode@??
;    extern alias _RtlIdnToUnicode@??
;    extern alias _RtlImageNtHeaderEx@??
;    extern alias _RtlInitializeBitMapEx@??
;    extern alias _RtlInterlockedClearBitRun@??
;    extern alias _RtlInterlockedSetBitRun@??
;    extern alias _RtlInterlockedSetClearRun@??
;    extern alias _RtlInvertRangeListEx@??
;    extern alias _RtlIsMultiSessionSku@??
;    extern alias _RtlIsSandboxedToken@??
;    extern alias _RtlIsUntrustedObject@??
;    extern alias _RtlLCIDToCultureName@??
;    extern alias _RtlLoadString@??
;    extern alias _RtlNormalizeString@??
;    extern alias _RtlNumberOfClearBitsEx@??
;    extern alias _RtlNumberOfClearBitsInRange@??
;    extern alias _RtlNumberOfSetBitsEx@??
;    extern alias _RtlNumberOfSetBitsInRange@??
;    extern alias _RtlOwnerAcesPresent@??
;    extern alias _RtlQueryDynamicTimeZoneInformation@??
;    extern alias _RtlQueryModuleInformation@??
;    extern alias _RtlQueryPackageClaims@??
;    extern alias _RtlQueryPackageIdentity@??
;    extern alias _RtlQueryRegistryValuesEx@??
;    extern alias _RtlQueryValidationRunlevel@??
;    extern alias _RtlRbReplaceNode@??
;    extern alias _RtlRemoveEntryHashTable@??
;    extern alias _RtlReplaceSidInSd@??
;    extern alias _RtlSetAllBitsEx@??
;    extern alias _RtlSetBitEx@??
;    extern alias _RtlSetBitsEx@??
;    extern alias _RtlSetDynamicTimeZoneInformation@??
;    extern alias _RtlSetPortableOperatingSystem@??
;    extern alias _RtlSidHashInitialize@??
;    extern alias _RtlSidHashLookup@??
;    extern alias _RtlTestBitEx@??
;    extern alias _RtlWeaklyEnumerateEntryHashTable@??
;    extern alias _SeAccessCheckFromState@??
;    extern alias _SeAccessCheckFromStateEx@??
;    extern alias _SeAccessCheckWithHint@??
;    extern alias _SeAuditingAnyFileEventsWithContextEx@??
;    extern alias _SeAuditingFileEventsWithContextEx@??
;    extern alias _SeAuditingWithTokenForSubcategory@??
;    extern alias _SeCloseObjectAuditAlarmForNonObObject@??
;    extern alias _SeCompareSigningLevels@??
;    extern alias _SeCreateClientSecurityEx@??
;    extern alias _SeCreateClientSecurityFromSubjectContextEx@??
;    extern alias _SeExports@??
;    extern alias _SeGetCachedSigningLevel@??
;    extern alias _SeGetLinkedToken@??
;    extern alias _SeGetLogonSessionToken@??
;    extern alias _SeIsParentOfChildAppContainer@??
;    extern alias _SeOpenObjectAuditAlarmForNonObObject@??
;    extern alias _SeOpenObjectAuditAlarmWithTransaction@??
;    extern alias _SePublicDefaultDacl@??
;    extern alias _SeQuerySecureBootPolicyValue@??
;    extern alias _SeQuerySecurityAttributesToken@??
;    extern alias _SeRegisterImageVerificationCallback@??
;    extern alias _SeSecurityAttributePresent@??
;    extern alias _SeSetAuthorizationCallbacks@??
;    extern alias _SeSetSecurityAttributesToken@??
;    extern alias _SeSetSecurityAttributesTokenEx@??
;    extern alias _SeSrpAccessCheck@??
;    extern alias _SeSystemDefaultDacl@??
;    extern alias _SeSystemDefaultSd@??
;    extern alias _SeTokenFromAccessInformation@??
;    extern alias _SeUnregisterImageVerificationCallback@??
;    extern alias _SkAcquirePushLockExclusive@??
;    extern alias _SkAllocatePool@??
;    extern alias _SkFreePool@??
;    extern alias _SkInitializePushLock@??
;    extern alias _SkIsSecureKernel@??
;    extern alias _SkQuerySecureKernelInformation@??
;    extern alias _SkReleasePushLockExclusive@??
;    extern alias _sprintf@??
;    extern alias _sprintf_s@??
;    extern alias _sqrt@??
;    extern alias _sqrtf@??
;    extern alias _srand@??
;    extern alias _sscanf_s@??
;    extern alias _strcat@??
;    extern alias _strcat_s@??
;    extern alias _strchr@??
;    extern alias _strcmp@??
;    extern alias _strcpy@??
;    extern alias _strcpy_s@??
;    extern alias _strlen@??
;    extern alias _strncat@??
;    extern alias _strncat_s@??
;    extern alias _strncmp@??
;    extern alias _strncpy@??
;    extern alias _strncpy_s@??
;    extern alias _strnlen@??
;    extern alias _strrchr@??
;    extern alias _strspn@??
;    extern alias _strstr@??
;    extern alias _strtok_s@??
;    extern alias _swprintf@??
;    extern alias _swprintf_s@??
;    extern alias _swscanf_s@??
;    extern alias _TmCancelPropagationRequest@??
;    extern alias _TmCurrentTransaction@??
;    extern alias _TmEndPropagationRequest@??
;    extern alias _TmEnlistmentObjectType@??
;    extern alias _TmFreezeTransactions@??
;    extern alias _TmInitializeResourceManager@??
;    extern alias _TmInitializeTransaction@??
;    extern alias _TmInitSystem@??
;    extern alias _TmInitSystemPhase2@??
;    extern alias _TmIsKTMCommitCoordinator@??
;    extern alias _TmpIsKTMCommitCoordinator@??
;    extern alias _TmPropagationComplete@??
;    extern alias _TmPropagationFailed@??
;    extern alias _TmResourceManagerObjectType@??
;    extern alias _TmSetCurrentTransaction@??
;    extern alias _TmThawTransactions@??
;    extern alias _TmTransactionManagerObjectType@??
;    extern alias _TmTransactionObjectType@??
;    extern alias _VfCheckNxPagePriority@??
;    extern alias _VfCheckNxPageProtection@??
;    extern alias _VfCheckNxPoolType@??
;    extern alias _VfFailDeviceNode@??
;    extern alias _VfFailDriver@??
;    extern alias _VfFailSystemBIOS@??
;    extern alias _VfInsertContext@??
;    extern alias _VfQueryDeviceContext@??
;    extern alias _VfQueryDispatchTable@??
;    extern alias _VfQueryDriverContext@??
;    extern alias _VfQueryIrpContext@??
;    extern alias _VfQueryThreadContext@??
;    extern alias _VfRemoveContext@??
;    extern alias _VmAccessFault@??
;    extern alias _VmCreateMemoryRange@??
;    extern alias _VmDeleteMemoryRange@??
;    extern alias _VslExchangeEntropy@??
;    extern alias _VslRetrieveMailbox@??
;    extern alias _WheaAttemptPhysicalPageOffline@??
;    extern alias _WheaConfigureErrorSource@??
;    extern alias _WheaDeferredRecoveryService@??
;    extern alias _WheaGetErrorSource@??
;    extern alias _WheaInitializeDeferredRecoveryObject@??
;    extern alias _WheaInitializeRecordHeader@??
;    extern alias _WheaRegisterErrSrcInitializer@??
;    extern alias _WheaReportHwError@??
;    extern alias _WheaRequestDeferredRecovery@??
;    extern alias _ZwAlpcConnectPortEx@??
;    extern alias _ZwCreateWnfStateName@??
;    extern alias _ZwDeleteDriverEntry@??
;    extern alias _ZwDeleteWnfStateData@??
;    extern alias _ZwDeleteWnfStateName@??
;    extern alias _ZwNotifyChangeSession@??
;    extern alias _ZwQueryLicenseValue@??
;    extern alias _ZwQueryWnfStateData@??
;    extern alias _ZwQueryWnfStateNameInformation@??
;    extern alias _ZwSetCachedSigningLevel@??
;    extern alias _ZwSetInformationVirtualMemory@??
;    extern alias _ZwUpdateWnfStateData@??
;    extern alias __abnormal_termination@??
;    extern alias __alloca_probe@??
;    extern alias __alloca_probe_16@??
;    extern alias __alloca_probe_8@??
;    extern alias __CIcos@??
;    extern alias __CIsin@??
;    extern alias __CIsqrt@??
;    extern alias __local_unwind@??
;    #ifndef __misaligned_access@??
;        extern alias ___misaligned_access@??
;    #endif@??
;    extern alias __snscanf_s@??
;    extern alias __snwprintf@??
;    extern alias __snwprintf_s@??
;    extern alias __snwscanf_s@??
#endif

#endif ;NTOSKRNL_INC
