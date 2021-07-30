; ====================================================;
;                                                     ;
;     ntoskrnl.inc for EC v2 Fasm visual projects     ;
;                   (version 1.0.2)                   ;
;                                                     ;
;         Copyright © Ramon Sala - 2018-2020          ;
;                                                     ;
; ====================================================;

if  ~defined NTOSKRNL_INC
define NTOSKRNL_INC 1

FSRTL_FAT_LEGAL                                 equ     01H
FSRTL_HPFS_LEGAL                                equ     02H
FSRTL_NTFS_LEGAL                                equ     04H
FSRTL_WILD_CHARACTER                            equ     08H
FSRTL_OLE_LEGAL                                 equ     10H
FSRTL_NTFS_STREAM_LEGAL                         equ     (FSRTL_NTFS_LEGAL or FSRTL_OLE_LEGAL)

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

FSRTL_ECP_LOOKASIDE_FLAG_NONPAGED_POOL          equ     00000002H

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
struct OWNER_ENTRY_UNION
    OwnerCount                                  dd       ?
    TableSize                                   dd       ?
ends

struct OWNER_ENTRY
    OwnerThread                                 dd       ?
    union
                                                OWNER_ENTRY_UNION
    ends
ends

struct ALPC_MESSAGE_ATTRIBUTES
    AllocatedAttributes                         dd       ?
    ValidAttributes                             dd       ?
ends

struct LOADER_PARTITION_INFORMATION_EX
    PartitionStyle  dd ?
    PartitionNumber dd ?
    union
        Signature   dd ?
        DeviceId    GUID
    ends
    Flags           dd ?
ends

struct ERESOURCE_UNION
    Address               xptr ?
    CreatorBackTraceIndex dd   ?
ends

struct ERESOURCE
    SystemResourcesList LIST_ENTRY 
    OwnerTable          xptr        ?
    ActiveCount         dw          ?
    Flag                dw          ?
    SharedWaiters       xptr        ?
    ExclusiveWaiters    xptr        ?
    OwnerEntry          OWNER_ENTRY
    ActiveEntries       dd          ?
    ContentionCount     dd          ?
    NumberOfSharedWaiters    dd     ?
    NumberOfExclusiveWaiters dd     ?
    union
                    ERESOURCE_UNION
    ends
    SpinLock            dd          ?
ends

struct BOOTDISK_INFORMATION_LITE
    NumberEntries  dd   ?
    Entries        LOADER_PARTITION_INFORMATION_EX
ends

struct FSRTL_MUP_PROVIDER_INFO_LEVEL_1
    ProviderId  dd ?
ends

struct FSRTL_MUP_PROVIDER_INFO_LEVEL_2
  ProviderId    dd ?
  ProviderName  UNICODE_STRING
ends

struct PO_FX_COMPONENT
    Id                         GUID 
    IdleStateCount             dd ?
    DeepestWakeableIdleState   dd ?
    IdleStates                 xptr  ?
ends

struct PO_FX_COMPONENT_IDLE_STATE
    TransitionLatency    xptr  ?
    ResidencyRequirement xptr  ?
    NominalPower         xptr  ?
ends

struct PO_FX_DEVICE
    Version                            dd   ?
    ComponentCount                     dd   ?
    ComponentActiveConditionCallback   xptr ?
    ComponentIdleConditionCallback     xptr ?
    ComponentIdleStateCallback         xptr ?
    DevicePowerRequiredCallback        xptr ?
    DevicePowerNotRequiredCallback     xptr ?
    PowerControlCallback               xptr ?
    DeviceContext                      xptr ?
    Components                         PO_FX_COMPONENT ANYSIZE_ARRAY dup(?)
ends


;======================================== Functions ======================================;
if defined APP_WIN64
    if (NTDDI_VERSION >= NTDDI_WINNT4)
        if ~defined __imp_atoi
            extrn '__imp_atoi' as atoi:qword
        end if
        if ~defined __imp_atol
            extrn '__imp_atol' as atol:qword
        end if
        extrn '__imp_CcCanIWrite' as CcCanIWrite:qword
        extrn '__imp_CcCopyRead' as CcCopyRead:qword
        extrn '__imp_CcCopyWrite' as CcCopyWrite:qword
        extrn '__imp_CcDeferWrite' as CcDeferWrite:qword
        extrn '__imp_CcFastCopyRead' as CcFastCopyRead:qword
        extrn '__imp_CcFastCopyWrite' as CcFastCopyWrite:qword
        extrn '__imp_CcFastMdlReadWait' as CcFastMdlReadWait:qword
        if (NTDDI_VERSION < NTDDI_VISTA)
            extrn '__imp_CcFastReadWait' as CcFastReadWait:qword
        end if
        extrn '__imp_CcFlushCache' as CcFlushCache:qword
        extrn '__imp_CcGetDirtyPages' as CcGetDirtyPages:qword
        extrn '__imp_CcGetFileObjectFromBcb' as CcGetFileObjectFromBcb:qword
        extrn '__imp_CcGetFileObjectFromSectionPtrs' as CcGetFileObjectFromSectionPtrs:qword
        extrn '__imp_CcGetLsnForFileObject' as CcGetLsnForFileObject:qword
        extrn '__imp_CcInitializeCacheMap' as CcInitializeCacheMap:qword
        extrn '__imp_CcIsThereDirtyData' as CcIsThereDirtyData:qword
        extrn '__imp_CcMapData' as CcMapData:qword
        extrn '__imp_CcMdlRead' as CcMdlRead:qword
        extrn '__imp_CcMdlReadComplete' as CcMdlReadComplete:qword
        extrn '__imp_CcMdlWriteComplete' as CcMdlWriteComplete:qword
        extrn '__imp_CcPinMappedData' as CcPinMappedData:qword
        extrn '__imp_CcPinRead' as CcPinRead:qword
        extrn '__imp_CcPrepareMdlWrite' as CcPrepareMdlWrite:qword
        extrn '__imp_CcPreparePinWrite' as CcPreparePinWrite:qword
        extrn '__imp_CcPurgeCacheSection' as CcPurgeCacheSection:qword
        extrn '__imp_CcRepinBcb' as CcRepinBcb:qword
        extrn '__imp_CcScheduleReadAhead' as CcScheduleReadAhead:qword
        extrn '__imp_CcSetAdditionalCacheAttributes' as CcSetAdditionalCacheAttributes:qword
        extrn '__imp_CcSetBcbOwnerPointer' as CcSetBcbOwnerPointer:qword
        extrn '__imp_CcSetDirtyPageThreshold' as CcSetDirtyPageThreshold:qword
        extrn '__imp_CcSetDirtyPinnedData' as CcSetDirtyPinnedData:qword
        extrn '__imp_CcSetFileSizes' as CcSetFileSizes:qword
        extrn '__imp_CcSetLogHandleForFile' as CcSetLogHandleForFile:qword
        extrn '__imp_CcSetReadAheadGranularity' as CcSetReadAheadGranularity:qword
        extrn '__imp_CcUninitializeCacheMap' as CcUninitializeCacheMap:qword
        extrn '__imp_CcUnpinData' as CcUnpinData:qword
        extrn '__imp_CcUnpinDataForThread' as CcUnpinDataForThread:qword
        extrn '__imp_CcUnpinRepinnedBcb' as CcUnpinRepinnedBcb:qword
        extrn '__imp_CcZeroData' as CcZeroData:qword
        extrn '__imp_DbgBreakPoint' as DbgBreakPoint:qword
        extrn '__imp_DbgBreakPointWithStatus' as DbgBreakPointWithStatus:qword
        extrn '__imp_DbgLoadImageSymbols' as DbgLoadImageSymbols:qword
        extrn '__imp_DbgPrint' as DbgPrint:qword
        extrn '__imp_DbgPrompt' as DbgPrompt:qword
        extrn '__imp_ExAcquireFastMutexUnsafe' as ExAcquireFastMutexUnsafe:qword
        extrn '__imp_ExAcquireResourceExclusiveLite' as ExAcquireResourceExclusiveLite:qword
        extrn '__imp_ExAcquireResourceSharedLite' as ExAcquireResourceSharedLite:qword
        extrn '__imp_ExAcquireSharedStarveExclusive' as ExAcquireSharedStarveExclusive:qword
        extrn '__imp_ExAcquireSharedWaitForExclusive' as ExAcquireSharedWaitForExclusive:qword
        extrn '__imp_ExAllocatePool' as ExAllocatePool:qword
        extrn '__imp_ExAllocatePoolWithQuota' as ExAllocatePoolWithQuota:qword
        extrn '__imp_ExAllocatePoolWithQuotaTag' as ExAllocatePoolWithQuotaTag:qword
        extrn '__imp_ExAllocatePoolWithTag' as ExAllocatePoolWithTag:qword
        extrn '__imp_ExAllocatePoolWithTagPriority' as ExAllocatePoolWithTagPriority:qword
        extrn '__imp_ExConvertExclusiveToSharedLite' as ExConvertExclusiveToSharedLite:qword
        extrn '__imp_ExCreateCallback' as ExCreateCallback:qword
        extrn '__imp_ExDeleteNPagedLookasideList' as ExDeleteNPagedLookasideList:qword
        extrn '__imp_ExDeletePagedLookasideList' as ExDeletePagedLookasideList:qword
        extrn '__imp_ExDeleteResourceLite' as ExDeleteResourceLite:qword
        extrn '__imp_ExDisableResourceBoostLite' as ExDisableResourceBoostLite:qword
        extrn '__imp_ExEnumHandleTable' as ExEnumHandleTable:qword
        extrn '__imp_ExExtendZone' as ExExtendZone:qword
        extrn '__imp_ExFreePool' as ExFreePool:qword
        if (NTDDI_VERSION < NTDDI_WIN2K & NTDDI_VERSION < NTDDI_WIN8)
            if ~defined APP_WIN64
                extrn '__imp_KeQueryInterruptTime' as KeQueryInterruptTime:qword
            end if
        end if
        if (NTDDI_VERSION < NTDDI_VISTA)
            extrn '__imp_KeConnectInterrupt' as KeConnectInterrupt:qword
            extrn '__imp_KeDisconnectInterrupt' as KeDisconnectInterrupt:qword
        else if (NTDDI_VERSION < NTDDI_WIN7)
            extrn '__imp_IoPnPDeliverServicePowerNotification' as IoPnPDeliverServicePowerNotification:qword
            extrn '__imp_KeTerminateThread' as KeTerminateThread:qword
        else if (NTDDI_VERSION <= NTDDI_WIN7)
            if ~defined APP_WIN64
                extrn '__imp_RtlConvertLongToLargeInteger' as RtlConvertLongToLargeInteger:qword
                extrn '__imp_RtlConvertUlongToLargeInteger' as RtlConvertUlongToLargeInteger:qword
                extrn '__imp_RtlEnlargedIntegerMultiply' as RtlEnlargedIntegerMultiply:qword
                extrn '__imp_RtlEnlargedUnsignedDivide' as RtlEnlargedUnsignedDivide:qword
                extrn '__imp_RtlEnlargedUnsignedMultiply' as RtlEnlargedUnsignedMultiply:qword
                extrn '__imp_RtlExtendedIntegerMultiply' as RtlExtendedIntegerMultiply:qword
                extrn '__imp_RtlExtendedLargeIntegerDivide' as RtlExtendedLargeIntegerDivide:qword
                extrn '__imp_RtlExtendedMagicDivide' as RtlExtendedMagicDivide:qword
                extrn '__imp_RtlFillMemoryUlong' as RtlFillMemoryUlong:qword
                extrn '__imp_RtlLargeIntegerArithmeticShift' as RtlLargeIntegerArithmeticShift:qword
                extrn '__imp_RtlLargeIntegerDivide' as RtlLargeIntegerDivide:qword
                extrn '__imp_RtlLargeIntegerNegate' as RtlLargeIntegerNegate:qword
                extrn '__imp_RtlLargeIntegerShiftLeft' as RtlLargeIntegerShiftLeft:qword
                extrn '__imp_RtlLargeIntegerShiftRight' as RtlLargeIntegerShiftRight:qword
                extrn '__imp_RtlLargeIntegerSubtract' as RtlLargeIntegerSubtract:qword
            end if
        else if (NTDDI_VERSION >= NTDDI_WIN7 & NTDDI_VERSION < NTDDI_WIN8)
            if defined APP_WIN64
                extrn '__imp_IoSetOplockKeyContext' as IoSetOplockKeyContext:qword
            else
                extrn '__imp_ExFreeToPagedLookasideList' as ExFreeToPagedLookasideList:qword
                extrn '__imp_Exi386InterlockedDecrementLong' as Exi386InterlockedDecrementLong:qword
                extrn '__imp_Exi386InterlockedExchangeUlong' as Exi386InterlockedExchangeUlong:qword
                extrn '__imp_Exi386InterlockedIncrementLong' as Exi386InterlockedIncrementLong:qword
                extrn '__imp_ExInterlockedDecrementLong' as ExInterlockedDecrementLong:qword
                extrn '__imp_ExInterlockedExchangeUlong' as ExInterlockedExchangeUlong:qword
                extrn '__imp_ExInterlockedIncrementLong' as ExInterlockedIncrementLong:qword
                extrn '__imp_Ke386CallBios' as Ke386CallBios:qword
                extrn '__imp_Ke386IoSetAccessProcess' as Ke386IoSetAccessProcess:qword
                extrn '__imp_Ke386QueryIoAccessMap' as Ke386QueryIoAccessMap:qword
                extrn '__imp_Ke386SetIoAccessMap' as Ke386SetIoAccessMap:qword
                extrn '__imp_KeGetPreviousMode' as KeGetPreviousMode:qword
                extrn '__imp_KeI386AbiosCall' as KeI386AbiosCall:qword
                extrn '__imp_KeI386AllocateGdtSelectors' as KeI386AllocateGdtSelectors:qword
                extrn '__imp_KeI386Call16BitFunction' as KeI386Call16BitFunction:qword
                extrn '__imp_KeI386FlatToGdtSelector' as KeI386FlatToGdtSelector:qword
                extrn '__imp_KeI386GetLid' as KeI386GetLid:qword
                extrn '__imp_KeI386ReleaseGdtSelectors' as KeI386ReleaseGdtSelectors:qword
                extrn '__imp_KeI386ReleaseLid' as KeI386ReleaseLid:qword
                extrn '__imp_KeI386SetGdtSelector' as KeI386SetGdtSelector:qword
                extrn '__imp_KeProfileInterrupt' as KeProfileInterrupt:qword
                extrn '__imp_KeQuerySystemTime' as KeQuerySystemTime:qword
                extrn '__imp_KeQueryTickCount' as KeQueryTickCount:qword
                extrn '__imp_KiCoprocessorError' as KiCoprocessorError:qword
                extrn '__imp_KiDeliverApc' as KiDeliverApc:qword
                extrn '__imp_KiIpiServiceRoutine' as KiIpiServiceRoutine:qword
                extrn '__imp_READ_REGISTER_BUFFER_UCHAR' as READ_REGISTER_BUFFER_UCHAR:qword
                extrn '__imp_READ_REGISTER_BUFFER_ULONG' as READ_REGISTER_BUFFER_ULONG:qword
                extrn '__imp_READ_REGISTER_BUFFER_USHORT' as READ_REGISTER_BUFFER_USHORT:qword
                extrn '__imp_READ_REGISTER_UCHAR' as READ_REGISTER_UCHAR:qword
                extrn '__imp_READ_REGISTER_ULONG' as READ_REGISTER_ULONG:qword
                extrn '__imp_READ_REGISTER_USHORT' as READ_REGISTER_USHORT:qword
            end if
        else if (NTDDI_VERSION >= NTDDI_WIN7)
            if ~defined APP_WIN64
                extrn '__imp_KeInitializeSpinLock' as KeInitializeSpinLock:qword
            end if
        end if
        extrn '__imp_ExGetExclusiveWaiterCount' as ExGetExclusiveWaiterCount:qword
        extrn '__imp_ExGetPreviousMode' as ExGetPreviousMode:qword
        extrn '__imp_ExGetSharedWaiterCount' as ExGetSharedWaiterCount:qword
        extrn '__imp_ExInitializeNPagedLookasideList' as ExInitializeNPagedLookasideList:qword
        extrn '__imp_ExInitializePagedLookasideList' as ExInitializePagedLookasideList:qword
        extrn '__imp_ExInitializeResourceLite' as ExInitializeResourceLite:qword
        extrn '__imp_ExInitializeZone' as ExInitializeZone:qword
        extrn '__imp_ExInterlockedAddLargeInteger' as ExInterlockedAddLargeInteger:qword
        extrn '__imp_ExInterlockedAddUlong' as ExInterlockedAddUlong:qword
        extrn '__imp_ExInterlockedExtendZone' as ExInterlockedExtendZone:qword
        extrn '__imp_ExInterlockedInsertHeadList' as ExInterlockedInsertHeadList:qword
        extrn '__imp_ExInterlockedInsertTailList' as ExInterlockedInsertTailList:qword
        extrn '__imp_ExInterlockedPopEntryList' as ExInterlockedPopEntryList:qword
        extrn '__imp_ExInterlockedPushEntryList' as ExInterlockedPushEntryList:qword
        extrn '__imp_ExInterlockedRemoveHeadList' as ExInterlockedRemoveHeadList:qword
        extrn '__imp_ExIsProcessorFeaturePresent' as ExIsProcessorFeaturePresent:qword
        extrn '__imp_ExIsResourceAcquiredExclusiveLite' as ExIsResourceAcquiredExclusiveLite:qword
        extrn '__imp_ExIsResourceAcquiredSharedLite' as ExIsResourceAcquiredSharedLite:qword
        extrn '__imp_ExLocalTimeToSystemTime' as ExLocalTimeToSystemTime:qword
        extrn '__imp_ExNotifyCallback' as ExNotifyCallback:qword
        extrn '__imp_ExQueryPoolBlockSize' as ExQueryPoolBlockSize:qword
        extrn '__imp_ExQueueWorkItem' as ExQueueWorkItem:qword
        extrn '__imp_ExRaiseAccessViolation' as ExRaiseAccessViolation:qword
        extrn '__imp_ExRaiseDatatypeMisalignment' as ExRaiseDatatypeMisalignment:qword
        extrn '__imp_ExRaiseException' as ExRaiseException:qword
        extrn '__imp_ExRaiseHardError' as ExRaiseHardError:qword
        extrn '__imp_ExRaiseStatus' as ExRaiseStatus:qword
        extrn '__imp_ExRegisterCallback' as ExRegisterCallback:qword
        extrn '__imp_ExReinitializeResourceLite' as ExReinitializeResourceLite:qword
        extrn '__imp_ExReleaseFastMutexUnsafe' as ExReleaseFastMutexUnsafe:qword
        extrn '__imp_ExReleaseResourceForThreadLite' as ExReleaseResourceForThreadLite:qword
        extrn '__imp_ExReleaseResourceLite' as ExReleaseResourceLite:qword
        extrn '__imp_ExSetResourceOwnerPointer' as ExSetResourceOwnerPointer:qword
        extrn '__imp_ExSystemExceptionFilter' as ExSystemExceptionFilter:qword
        extrn '__imp_ExSystemTimeToLocalTime' as ExSystemTimeToLocalTime:qword
        extrn '__imp_ExUnregisterCallback' as ExUnregisterCallback:qword
        extrn '__imp_FsRtlAddLargeMcbEntry' as FsRtlAddLargeMcbEntry:qword
        extrn '__imp_FsRtlAddMcbEntry' as FsRtlAddMcbEntry:qword
        extrn '__imp_FsRtlAddToTunnelCache' as FsRtlAddToTunnelCache:qword
        extrn '__imp_FsRtlAllocatePool' as FsRtlAllocatePool:qword
        extrn '__imp_FsRtlAllocatePoolWithQuota' as FsRtlAllocatePoolWithQuota:qword
        extrn '__imp_FsRtlAllocatePoolWithQuotaTag' as FsRtlAllocatePoolWithQuotaTag:qword
        extrn '__imp_FsRtlAllocatePoolWithTag' as FsRtlAllocatePoolWithTag:qword
        extrn '__imp_FsRtlAllocateResource' as FsRtlAllocateResource:qword
        extrn '__imp_FsRtlAreNamesEqual' as FsRtlAreNamesEqual:qword
        extrn '__imp_FsRtlBalanceReads' as FsRtlBalanceReads:qword
        extrn '__imp_FsRtlCheckLockForReadAccess' as FsRtlCheckLockForReadAccess:qword
        extrn '__imp_FsRtlCheckLockForWriteAccess' as FsRtlCheckLockForWriteAccess:qword
        extrn '__imp_FsRtlCheckOplock' as FsRtlCheckOplock:qword
        extrn '__imp_FsRtlCopyRead' as FsRtlCopyRead:qword
        extrn '__imp_FsRtlCopyWrite' as FsRtlCopyWrite:qword
        extrn '__imp_FsRtlCurrentBatchOplock' as FsRtlCurrentBatchOplock:qword
        extrn '__imp_FsRtlDeleteKeyFromTunnelCache' as FsRtlDeleteKeyFromTunnelCache:qword
        extrn '__imp_FsRtlDeleteTunnelCache' as FsRtlDeleteTunnelCache:qword
        extrn '__imp_FsRtlDeregisterUncProvider' as FsRtlDeregisterUncProvider:qword
        extrn '__imp_FsRtlDissectDbcs' as FsRtlDissectDbcs:qword
        extrn '__imp_FsRtlDissectName' as FsRtlDissectName:qword
        extrn '__imp_FsRtlDoesDbcsContainWildCards' as FsRtlDoesDbcsContainWildCards:qword
        extrn '__imp_FsRtlDoesNameContainWildCards' as FsRtlDoesNameContainWildCards:qword
        extrn '__imp_FsRtlFastCheckLockForRead' as FsRtlFastCheckLockForRead:qword
        extrn '__imp_FsRtlFastCheckLockForWrite' as FsRtlFastCheckLockForWrite:qword
        extrn '__imp_FsRtlFastUnlockAll' as FsRtlFastUnlockAll:qword
        extrn '__imp_FsRtlFastUnlockAllByKey' as FsRtlFastUnlockAllByKey:qword
        extrn '__imp_FsRtlFastUnlockSingle' as FsRtlFastUnlockSingle:qword
        extrn '__imp_FsRtlFindInTunnelCache' as FsRtlFindInTunnelCache:qword
        extrn '__imp_FsRtlGetFileSize' as FsRtlGetFileSize:qword
        extrn '__imp_FsRtlGetNextFileLock' as FsRtlGetNextFileLock:qword
        extrn '__imp_FsRtlGetNextLargeMcbEntry' as FsRtlGetNextLargeMcbEntry:qword
        extrn '__imp_FsRtlGetNextMcbEntry' as FsRtlGetNextMcbEntry:qword
        extrn '__imp_FsRtlInitializeFileLock' as FsRtlInitializeFileLock:qword
        extrn '__imp_FsRtlInitializeLargeMcb' as FsRtlInitializeLargeMcb:qword
        extrn '__imp_FsRtlInitializeMcb' as FsRtlInitializeMcb:qword
        extrn '__imp_FsRtlInitializeOplock' as FsRtlInitializeOplock:qword
        extrn '__imp_FsRtlInitializeTunnelCache' as FsRtlInitializeTunnelCache:qword
        extrn '__imp_FsRtlIsDbcsInExpression' as FsRtlIsDbcsInExpression:qword
        extrn '__imp_FsRtlIsFatDbcsLegal' as FsRtlIsFatDbcsLegal:qword
        extrn '__imp_FsRtlIsHpfsDbcsLegal' as FsRtlIsHpfsDbcsLegal:qword
        extrn '__imp_FsRtlIsNameInExpression' as FsRtlIsNameInExpression:qword
        extrn '__imp_FsRtlIsNtstatusExpected' as FsRtlIsNtstatusExpected:qword
        extrn '__imp_FsRtlIsTotalDeviceFailure' as FsRtlIsTotalDeviceFailure:qword
        extrn '__imp_FsRtlLookupLargeMcbEntry' as FsRtlLookupLargeMcbEntry:qword
        extrn '__imp_FsRtlLookupLastLargeMcbEntry' as FsRtlLookupLastLargeMcbEntry:qword
        extrn '__imp_FsRtlLookupLastMcbEntry' as FsRtlLookupLastMcbEntry:qword
        extrn '__imp_FsRtlLookupMcbEntry' as FsRtlLookupMcbEntry:qword
        extrn '__imp_FsRtlMdlRead' as FsRtlMdlRead:qword
        extrn '__imp_FsRtlMdlReadComplete' as FsRtlMdlReadComplete:qword
        extrn '__imp_FsRtlMdlReadCompleteDev' as FsRtlMdlReadCompleteDev:qword
        extrn '__imp_FsRtlMdlReadDev' as FsRtlMdlReadDev:qword
        extrn '__imp_FsRtlMdlWriteComplete' as FsRtlMdlWriteComplete:qword
        extrn '__imp_FsRtlMdlWriteCompleteDev' as FsRtlMdlWriteCompleteDev:qword
        extrn '__imp_FsRtlNormalizeNtstatus' as FsRtlNormalizeNtstatus:qword
        extrn '__imp_FsRtlNotifyChangeDirectory' as FsRtlNotifyChangeDirectory:qword
        extrn '__imp_FsRtlNotifyCleanup' as FsRtlNotifyCleanup:qword
        extrn '__imp_FsRtlNotifyFullChangeDirectory' as FsRtlNotifyFullChangeDirectory:qword
        extrn '__imp_FsRtlNotifyFullReportChange' as FsRtlNotifyFullReportChange:qword
        extrn '__imp_FsRtlNotifyInitializeSync' as FsRtlNotifyInitializeSync:qword
        extrn '__imp_FsRtlNotifyReportChange' as FsRtlNotifyReportChange:qword
        extrn '__imp_FsRtlNotifyUninitializeSync' as FsRtlNotifyUninitializeSync:qword
        extrn '__imp_FsRtlNumberOfRunsInLargeMcb' as FsRtlNumberOfRunsInLargeMcb:qword
        extrn '__imp_FsRtlNumberOfRunsInMcb' as FsRtlNumberOfRunsInMcb:qword
        extrn '__imp_FsRtlOplockFsctrl' as FsRtlOplockFsctrl:qword
        extrn '__imp_FsRtlOplockIsFastIoPossible' as FsRtlOplockIsFastIoPossible:qword
        extrn '__imp_FsRtlPostPagingFileStackOverflow' as FsRtlPostPagingFileStackOverflow:qword
        extrn '__imp_FsRtlPostStackOverflow' as FsRtlPostStackOverflow:qword
        extrn '__imp_FsRtlPrepareMdlWrite' as FsRtlPrepareMdlWrite:qword
        extrn '__imp_FsRtlPrepareMdlWriteDev' as FsRtlPrepareMdlWriteDev:qword
        extrn '__imp_FsRtlPrivateLock' as FsRtlPrivateLock:qword
        extrn '__imp_FsRtlProcessFileLock' as FsRtlProcessFileLock:qword
        extrn '__imp_FsRtlRegisterUncProvider' as FsRtlRegisterUncProvider:qword
        extrn '__imp_FsRtlRemoveLargeMcbEntry' as FsRtlRemoveLargeMcbEntry:qword
        extrn '__imp_FsRtlRemoveMcbEntry' as FsRtlRemoveMcbEntry:qword
        extrn '__imp_FsRtlSplitLargeMcb' as FsRtlSplitLargeMcb:qword
        extrn '__imp_FsRtlSyncVolumes' as FsRtlSyncVolumes:qword
        extrn '__imp_FsRtlTruncateLargeMcb' as FsRtlTruncateLargeMcb:qword
        extrn '__imp_FsRtlTruncateMcb' as FsRtlTruncateMcb:qword
        extrn '__imp_FsRtlUninitializeFileLock' as FsRtlUninitializeFileLock:qword
        extrn '__imp_FsRtlUninitializeLargeMcb' as FsRtlUninitializeLargeMcb:qword
        extrn '__imp_FsRtlUninitializeMcb' as FsRtlUninitializeMcb:qword
        extrn '__imp_FsRtlUninitializeOplock' as FsRtlUninitializeOplock:qword
        extrn '__imp_IoAcquireVpbSpinLock' as IoAcquireVpbSpinLock:qword
        extrn '__imp_IoAllocateAdapterChannel' as IoAllocateAdapterChannel:qword
        extrn '__imp_IoAllocateController' as IoAllocateController:qword
        extrn '__imp_IoAllocateErrorLogEntry' as IoAllocateErrorLogEntry:qword
        extrn '__imp_IoAllocateIrp' as IoAllocateIrp:qword
        extrn '__imp_IoAllocateMdl' as IoAllocateMdl:qword
        extrn '__imp_IoAssignResources' as IoAssignResources:qword
        extrn '__imp_IoAttachDevice' as IoAttachDevice:qword
        extrn '__imp_IoAttachDeviceByPointer' as IoAttachDeviceByPointer:qword
        extrn '__imp_IoAttachDeviceToDeviceStack' as IoAttachDeviceToDeviceStack:qword
        extrn '__imp_IoBuildAsynchronousFsdRequest' as IoBuildAsynchronousFsdRequest:qword
        extrn '__imp_IoBuildDeviceIoControlRequest' as IoBuildDeviceIoControlRequest:qword
        extrn '__imp_IoBuildPartialMdl' as IoBuildPartialMdl:qword
        extrn '__imp_IoBuildSynchronousFsdRequest' as IoBuildSynchronousFsdRequest:qword
        extrn '__imp_IoCallDriver' as IoCallDriver:qword
        extrn '__imp_IoCancelIrp' as IoCancelIrp:qword
        extrn '__imp_IoCheckDesiredAccess' as IoCheckDesiredAccess:qword
        extrn '__imp_IoCheckEaBufferValidity' as IoCheckEaBufferValidity:qword
        extrn '__imp_IoCheckFunctionAccess' as IoCheckFunctionAccess:qword
        extrn '__imp_IoCheckShareAccess' as IoCheckShareAccess:qword
        extrn '__imp_IoCompleteRequest' as IoCompleteRequest:qword
        extrn '__imp_IoConnectInterrupt' as IoConnectInterrupt:qword
        extrn '__imp_IoCreateController' as IoCreateController:qword
        extrn '__imp_IoCreateDevice' as IoCreateDevice:qword
        extrn '__imp_IoCreateFile' as IoCreateFile:qword
        extrn '__imp_IoCreateNotificationEvent' as IoCreateNotificationEvent:qword
        extrn '__imp_IoCreateStreamFileObject' as IoCreateStreamFileObject:qword
        extrn '__imp_IoCreateSymbolicLink' as IoCreateSymbolicLink:qword
        extrn '__imp_IoCreateSynchronizationEvent' as IoCreateSynchronizationEvent:qword
        extrn '__imp_IoCreateUnprotectedSymbolicLink' as IoCreateUnprotectedSymbolicLink:qword
        extrn '__imp_IoDeleteController' as IoDeleteController:qword
        extrn '__imp_IoDeleteDevice' as IoDeleteDevice:qword
        extrn '__imp_IoDeleteSymbolicLink' as IoDeleteSymbolicLink:qword
        extrn '__imp_IoDetachDevice' as IoDetachDevice:qword
        extrn '__imp_IoDisconnectInterrupt' as IoDisconnectInterrupt:qword
        extrn '__imp_IoEnqueueIrp' as IoEnqueueIrp:qword
        extrn '__imp_IoFastQueryNetworkAttributes' as IoFastQueryNetworkAttributes:qword
        extrn '__imp_IofCallDriver' as IofCallDriver:qword
        extrn '__imp_IofCompleteRequest' as IofCompleteRequest:qword
        extrn '__imp_IoFreeController' as IoFreeController:qword
        extrn '__imp_IoFreeIrp' as IoFreeIrp:qword
        extrn '__imp_IoFreeMdl' as IoFreeMdl:qword
        extrn '__imp_IoGetAttachedDevice' as IoGetAttachedDevice:qword
        extrn '__imp_IoGetBaseFileSystemDeviceObject' as IoGetBaseFileSystemDeviceObject:qword
        extrn '__imp_IoGetConfigurationInformation' as IoGetConfigurationInformation:qword
        extrn '__imp_IoGetCurrentProcess' as IoGetCurrentProcess:qword
        extrn '__imp_IoGetDeviceObjectPointer' as IoGetDeviceObjectPointer:qword
        extrn '__imp_IoGetDeviceToVerify' as IoGetDeviceToVerify:qword
        extrn '__imp_IoGetFileObjectGenericMapping' as IoGetFileObjectGenericMapping:qword
        extrn '__imp_IoGetInitialStack' as IoGetInitialStack:qword
        extrn '__imp_IoGetRelatedDeviceObject' as IoGetRelatedDeviceObject:qword
        extrn '__imp_IoGetRequestorProcess' as IoGetRequestorProcess:qword
        extrn '__imp_IoGetStackLimits' as IoGetStackLimits:qword
        extrn '__imp_IoGetTopLevelIrp' as IoGetTopLevelIrp:qword
        extrn '__imp_IoInitializeIrp' as IoInitializeIrp:qword
        extrn '__imp_IoInitializeTimer' as IoInitializeTimer:qword
        extrn '__imp_IoIsOperationSynchronous' as IoIsOperationSynchronous:qword
        extrn '__imp_IoIsSystemThread' as IoIsSystemThread:qword
        extrn '__imp_IoMakeAssociatedIrp' as IoMakeAssociatedIrp:qword
        extrn '__imp_IoPageRead' as IoPageRead:qword
        extrn '__imp_IoQueryDeviceDescription' as IoQueryDeviceDescription:qword
        extrn '__imp_IoQueryFileInformation' as IoQueryFileInformation:qword
        extrn '__imp_IoQueryVolumeInformation' as IoQueryVolumeInformation:qword
        extrn '__imp_IoQueueThreadIrp' as IoQueueThreadIrp:qword
        extrn '__imp_IoRaiseHardError' as IoRaiseHardError:qword
        extrn '__imp_IoRaiseInformationalHardError' as IoRaiseInformationalHardError:qword
        extrn '__imp_IoRegisterDriverReinitialization' as IoRegisterDriverReinitialization:qword
        extrn '__imp_IoRegisterFileSystem' as IoRegisterFileSystem:qword
        extrn '__imp_IoRegisterFsRegistrationChange' as IoRegisterFsRegistrationChange:qword
        extrn '__imp_IoRegisterShutdownNotification' as IoRegisterShutdownNotification:qword
        extrn '__imp_IoReleaseCancelSpinLock' as IoReleaseCancelSpinLock:qword
        extrn '__imp_IoReleaseVpbSpinLock' as IoReleaseVpbSpinLock:qword
        extrn '__imp_IoRemoveShareAccess' as IoRemoveShareAccess:qword
        extrn '__imp_IoReportHalResourceUsage' as IoReportHalResourceUsage:qword
        extrn '__imp_IoReportResourceUsage' as IoReportResourceUsage:qword
        extrn '__imp_IoSetDeviceToVerify' as IoSetDeviceToVerify:qword
        extrn '__imp_IoSetHardErrorOrVerifyDevice' as IoSetHardErrorOrVerifyDevice:qword
        extrn '__imp_IoSetInformation' as IoSetInformation:qword
        extrn '__imp_IoSetShareAccess' as IoSetShareAccess:qword
        extrn '__imp_IoSetThreadHardErrorMode' as IoSetThreadHardErrorMode:qword
        extrn '__imp_IoSetTopLevelIrp' as IoSetTopLevelIrp:qword
        extrn '__imp_IoStartNextPacket' as IoStartNextPacket:qword
        extrn '__imp_IoStartNextPacketByKey' as IoStartNextPacketByKey:qword
        extrn '__imp_IoStartPacket' as IoStartPacket:qword
        extrn '__imp_IoStartTimer' as IoStartTimer:qword
        extrn '__imp_IoStopTimer' as IoStopTimer:qword
        extrn '__imp_IoSynchronousPageWrite' as IoSynchronousPageWrite:qword
        extrn '__imp_IoThreadToProcess' as IoThreadToProcess:qword
        extrn '__imp_IoUnregisterFileSystem' as IoUnregisterFileSystem:qword
        extrn '__imp_IoUnregisterFsRegistrationChange' as IoUnregisterFsRegistrationChange:qword
        extrn '__imp_IoUnregisterShutdownNotification' as IoUnregisterShutdownNotification:qword
        extrn '__imp_IoUpdateShareAccess' as IoUpdateShareAccess:qword
        extrn '__imp_IoVerifyVolume' as IoVerifyVolume:qword
        extrn '__imp_IoWriteErrorLogEntry' as IoWriteErrorLogEntry:qword
        if ~defined __imp_isdigit
            extrn '__imp_isdigit' as isdigit:qword
        end if
        if ~defined __imp_islower
            extrn '__imp_islower' as islower:qword
        end if
        if ~defined __imp_isprint
            extrn '__imp_isprint' as isprint:qword
        end if
        if ~defined __imp_isspace
            extrn '__imp_isspace' as isspace:qword
        end if
        if ~defined __imp_isupper
            extrn '__imp_isupper' as isupper:qword
        end if
        if ~defined __imp_isxdigit
            extrn '__imp_isxdigit' as isxdigit:qword
        end if
        extrn '__imp_KdPollBreakIn' as KdPollBreakIn:qword
        extrn '__imp_KeAcquireSpinLockAtDpcLevel' as KeAcquireSpinLockAtDpcLevel:qword
        extrn '__imp_KeAddSystemServiceTable' as KeAddSystemServiceTable:qword
        extrn '__imp_KeAttachProcess' as KeAttachProcess:qword
        extrn '__imp_KeBugCheck' as KeBugCheck:qword
        extrn '__imp_KeBugCheckEx' as KeBugCheckEx:qword
        extrn '__imp_KeCancelTimer' as KeCancelTimer:qword
        extrn '__imp_KeClearEvent' as KeClearEvent:qword
        extrn '__imp_KeDelayExecutionThread' as KeDelayExecutionThread:qword
        extrn '__imp_KeDeregisterBugCheckCallback' as KeDeregisterBugCheckCallback:qword
        extrn '__imp_KeDetachProcess' as KeDetachProcess:qword
        extrn '__imp_KeEnterCriticalRegion' as KeEnterCriticalRegion:qword
        extrn '__imp_KeEnterKernelDebugger' as KeEnterKernelDebugger:qword
        extrn '__imp_KeFindConfigurationEntry' as KeFindConfigurationEntry:qword
        extrn '__imp_KeFindConfigurationNextEntry' as KeFindConfigurationNextEntry:qword
        extrn '__imp_KeFlushEntireTb' as KeFlushEntireTb:qword
        extrn '__imp_KeGetCurrentThread' as KeGetCurrentThread:qword
        extrn '__imp_KeInitializeApc' as KeInitializeApc:qword
        extrn '__imp_KeInitializeDeviceQueue' as KeInitializeDeviceQueue:qword
        extrn '__imp_KeInitializeDpc' as KeInitializeDpc:qword
        extrn '__imp_KeInitializeEvent' as KeInitializeEvent:qword
        extrn '__imp_KeInitializeInterrupt' as KeInitializeInterrupt:qword
        extrn '__imp_KeInitializeMutant' as KeInitializeMutant:qword
        extrn '__imp_KeInitializeMutex' as KeInitializeMutex:qword
        extrn '__imp_KeInitializeQueue' as KeInitializeQueue:qword
        extrn '__imp_KeInitializeSemaphore' as KeInitializeSemaphore:qword
        extrn '__imp_KeInitializeTimer' as KeInitializeTimer:qword
        extrn '__imp_KeInitializeTimerEx' as KeInitializeTimerEx:qword
        extrn '__imp_KeInsertByKeyDeviceQueue' as KeInsertByKeyDeviceQueue:qword
        extrn '__imp_KeInsertDeviceQueue' as KeInsertDeviceQueue:qword
        extrn '__imp_KeInsertHeadQueue' as KeInsertHeadQueue:qword
        extrn '__imp_KeInsertQueue' as KeInsertQueue:qword
        extrn '__imp_KeInsertQueueApc' as KeInsertQueueApc:qword
        extrn '__imp_KeInsertQueueDpc' as KeInsertQueueDpc:qword
        extrn '__imp_KeIsExecutingDpc' as KeIsExecutingDpc:qword
        extrn '__imp_KeLeaveCriticalRegion' as KeLeaveCriticalRegion:qword
        extrn '__imp_KeProfileInterruptWithSource' as KeProfileInterruptWithSource:qword
        extrn '__imp_KePulseEvent' as KePulseEvent:qword
        extrn '__imp_KeQueryTimeIncrement' as KeQueryTimeIncrement:qword
        extrn '__imp_KeRaiseUserException' as KeRaiseUserException:qword
        extrn '__imp_KeReadStateEvent' as KeReadStateEvent:qword
        extrn '__imp_KeReadStateMutant' as KeReadStateMutant:qword
        extrn '__imp_KeReadStateMutex' as KeReadStateMutex:qword
        extrn '__imp_KeReadStateQueue' as KeReadStateQueue:qword
        extrn '__imp_KeReadStateSemaphore' as KeReadStateSemaphore:qword
        extrn '__imp_KeReadStateTimer' as KeReadStateTimer:qword
        extrn '__imp_KeRegisterBugCheckCallback' as KeRegisterBugCheckCallback:qword
        extrn '__imp_KeReleaseMutant' as KeReleaseMutant:qword
        extrn '__imp_KeReleaseMutex' as KeReleaseMutex:qword
        extrn '__imp_KeReleaseSemaphore' as KeReleaseSemaphore:qword
        extrn '__imp_KeReleaseSpinLockFromDpcLevel' as KeReleaseSpinLockFromDpcLevel:qword
        extrn '__imp_KeRemoveByKeyDeviceQueue' as KeRemoveByKeyDeviceQueue:qword
        extrn '__imp_KeRemoveDeviceQueue' as KeRemoveDeviceQueue:qword
        extrn '__imp_KeRemoveEntryDeviceQueue' as KeRemoveEntryDeviceQueue:qword
        extrn '__imp_KeRemoveQueue' as KeRemoveQueue:qword
        extrn '__imp_KeRemoveQueueDpc' as KeRemoveQueueDpc:qword
        extrn '__imp_KeResetEvent' as KeResetEvent:qword
        extrn '__imp_KeRestoreFloatingPointState' as KeRestoreFloatingPointState:qword
        extrn '__imp_KeRundownQueue' as KeRundownQueue:qword
        extrn '__imp_KeSaveFloatingPointState' as KeSaveFloatingPointState:qword
        extrn '__imp_KeSetAffinityThread' as KeSetAffinityThread:qword
        extrn '__imp_KeSetBasePriorityThread' as KeSetBasePriorityThread:qword
        extrn '__imp_KeSetDmaIoCoherency' as KeSetDmaIoCoherency:qword
        extrn '__imp_KeSetEvent' as KeSetEvent:qword
        extrn '__imp_KeSetEventBoostPriority' as KeSetEventBoostPriority:qword
        extrn '__imp_KeSetIdealProcessorThread' as KeSetIdealProcessorThread:qword
        extrn '__imp_KeSetImportanceDpc' as KeSetImportanceDpc:qword
        extrn '__imp_KeSetKernelStackSwapEnable' as KeSetKernelStackSwapEnable:qword
        extrn '__imp_KeSetPriorityThread' as KeSetPriorityThread:qword
        extrn '__imp_KeSetProfileIrql' as KeSetProfileIrql:qword
        extrn '__imp_KeSetTargetProcessorDpc' as KeSetTargetProcessorDpc:qword
        extrn '__imp_KeSetTimeIncrement' as KeSetTimeIncrement:qword
        extrn '__imp_KeSetTimer' as KeSetTimer:qword
        extrn '__imp_KeSetTimerEx' as KeSetTimerEx:qword
        extrn '__imp_KeSynchronizeExecution' as KeSynchronizeExecution:qword
        extrn '__imp_KeUpdateRunTime' as KeUpdateRunTime:qword
        extrn '__imp_KeUserModeCallback' as KeUserModeCallback:qword
        extrn '__imp_KeWaitForMultipleObjects' as KeWaitForMultipleObjects:qword
        extrn '__imp_KeWaitForMutexObject' as KeWaitForMutexObject:qword
        extrn '__imp_KeWaitForSingleObject' as KeWaitForSingleObject:qword
        extrn '__imp_LdrAccessResource' as LdrAccessResource:qword
        extrn '__imp_LdrEnumResources' as LdrEnumResources:qword
        extrn '__imp_LdrFindResource_U' as LdrFindResource_U:qword
        extrn '__imp_LdrFindResourceDirectory_U' as LdrFindResourceDirectory_U:qword
        extrn '__imp_LpcRequestPort' as LpcRequestPort:qword
        extrn '__imp_LsaCallAuthenticationPackage' as LsaCallAuthenticationPackage:qword
        extrn '__imp_LsaDeregisterLogonProcess' as LsaDeregisterLogonProcess:qword
        extrn '__imp_LsaFreeReturnBuffer' as LsaFreeReturnBuffer:qword
        extrn '__imp_LsaLogonUser' as LsaLogonUser:qword
        extrn '__imp_LsaLookupAuthenticationPackage' as LsaLookupAuthenticationPackage:qword
        extrn '__imp_LsaRegisterLogonProcess' as LsaRegisterLogonProcess:qword
        if ~defined __imp_mbstowcs
            extrn '__imp_mbstowcs' as mbstowcs:qword
        end if
        if ~defined __imp_mbtowc
            extrn '__imp_mbtowc' as mbtowc:qword
        end if
        if ~defined __imp_memchr
            extrn '__imp_memchr' as memchr:qword
        end if
        if ~defined __imp_memcpy
            extrn '__imp_memcpy' as memcpy:qword
        end if
        if ~defined __imp_memmove
            extrn '__imp_memmove' as memmove:qword
        end if
        if ~defined __imp_memset
            extrn '__imp_memset' as memset:qword
        end if
        extrn '__imp_MmAdjustWorkingSetSize' as MmAdjustWorkingSetSize:qword
        extrn '__imp_MmAllocateContiguousMemory' as MmAllocateContiguousMemory:qword
        extrn '__imp_MmAllocateNonCachedMemory' as MmAllocateNonCachedMemory:qword
        extrn '__imp_MmBuildMdlForNonPagedPool' as MmBuildMdlForNonPagedPool:qword
        extrn '__imp_MmCanFileBeTruncated' as MmCanFileBeTruncated:qword
        extrn '__imp_MmCreateMdl' as MmCreateMdl:qword
        extrn '__imp_MmCreateSection' as MmCreateSection:qword
        extrn '__imp_MmDisableModifiedWriteOfSection' as MmDisableModifiedWriteOfSection:qword
        extrn '__imp_MmFlushImageSection' as MmFlushImageSection:qword
        extrn '__imp_MmForceSectionClosed' as MmForceSectionClosed:qword
        extrn '__imp_MmFreeContiguousMemory' as MmFreeContiguousMemory:qword
        extrn '__imp_MmFreeNonCachedMemory' as MmFreeNonCachedMemory:qword
        extrn '__imp_MmGetPhysicalAddress' as MmGetPhysicalAddress:qword
        extrn '__imp_MmGrowKernelStack' as MmGrowKernelStack:qword
        extrn '__imp_MmIsAddressValid' as MmIsAddressValid:qword
        extrn '__imp_MmIsNonPagedSystemAddressValid' as MmIsNonPagedSystemAddressValid:qword
        extrn '__imp_MmIsRecursiveIoFault' as MmIsRecursiveIoFault:qword
        extrn '__imp_MmIsThisAnNtAsSystem' as MmIsThisAnNtAsSystem:qword
        extrn '__imp_MmLockPagableDataSection' as MmLockPagableDataSection:qword
        extrn '__imp_MmLockPagableImageSection' as MmLockPagableImageSection:qword
        extrn '__imp_MmLockPagableSectionByHandle' as MmLockPagableSectionByHandle:qword
        extrn '__imp_MmMapIoSpace' as MmMapIoSpace:qword
        extrn '__imp_MmMapLockedPages' as MmMapLockedPages:qword
        extrn '__imp_MmMapLockedPagesSpecifyCache' as MmMapLockedPagesSpecifyCache:qword
        extrn '__imp_MmMapMemoryDumpMdl' as MmMapMemoryDumpMdl:qword
        extrn '__imp_MmMapVideoDisplay' as MmMapVideoDisplay:qword
        extrn '__imp_MmMapViewInSystemSpace' as MmMapViewInSystemSpace:qword
        extrn '__imp_MmMapViewOfSection' as MmMapViewOfSection:qword
        extrn '__imp_MmPageEntireDriver' as MmPageEntireDriver:qword
        extrn '__imp_MmProbeAndLockPages' as MmProbeAndLockPages:qword
        extrn '__imp_MmQuerySystemSize' as MmQuerySystemSize:qword
        extrn '__imp_MmResetDriverPaging' as MmResetDriverPaging:qword
        extrn '__imp_MmSecureVirtualMemory' as MmSecureVirtualMemory:qword
        extrn '__imp_MmSetAddressRangeModified' as MmSetAddressRangeModified:qword
        extrn '__imp_MmSetBankedSection' as MmSetBankedSection:qword
        extrn '__imp_MmSizeOfMdl' as MmSizeOfMdl:qword
        extrn '__imp_MmUnlockPagableImageSection' as MmUnlockPagableImageSection:qword
        extrn '__imp_MmUnlockPages' as MmUnlockPages:qword
        extrn '__imp_MmUnmapIoSpace' as MmUnmapIoSpace:qword
        extrn '__imp_MmUnmapLockedPages' as MmUnmapLockedPages:qword
        extrn '__imp_MmUnmapVideoDisplay' as MmUnmapVideoDisplay:qword
        extrn '__imp_MmUnmapViewInSystemSpace' as MmUnmapViewInSystemSpace:qword
        extrn '__imp_MmUnmapViewOfSection' as MmUnmapViewOfSection:qword
        extrn '__imp_MmUnsecureVirtualMemory' as MmUnsecureVirtualMemory:qword
        extrn '__imp_NlsOemLeadByteInfo' as NlsOemLeadByteInfo:qword
        extrn '__imp_NtAddAtom' as NtAddAtom:qword
        extrn '__imp_NtAdjustPrivilegesToken' as NtAdjustPrivilegesToken:qword
        extrn '__imp_NtAllocateLocallyUniqueId' as NtAllocateLocallyUniqueId:qword
        extrn '__imp_NtAllocateUuids' as NtAllocateUuids:qword
        extrn '__imp_NtAllocateVirtualMemory' as NtAllocateVirtualMemory:qword
        extrn '__imp_NtClose' as NtClose:qword
        extrn '__imp_NtConnectPort' as NtConnectPort:qword
        extrn '__imp_NtCreateEvent' as NtCreateEvent:qword
        extrn '__imp_NtCreateFile' as NtCreateFile:qword
        extrn '__imp_NtCreateSection' as NtCreateSection:qword
        extrn '__imp_NtDeleteAtom' as NtDeleteAtom:qword
        extrn '__imp_NtDeleteFile' as NtDeleteFile:qword
        extrn '__imp_NtDeviceIoControlFile' as NtDeviceIoControlFile:qword
        extrn '__imp_NtDuplicateObject' as NtDuplicateObject:qword
        extrn '__imp_NtDuplicateToken' as NtDuplicateToken:qword
        extrn '__imp_NtFindAtom' as NtFindAtom:qword
        extrn '__imp_NtFreeVirtualMemory' as NtFreeVirtualMemory:qword
        extrn '__imp_NtFsControlFile' as NtFsControlFile:qword
        extrn '__imp_NtLockFile' as NtLockFile:qword
        extrn '__imp_NtMapViewOfSection' as NtMapViewOfSection:qword
        extrn '__imp_NtNotifyChangeDirectoryFile' as NtNotifyChangeDirectoryFile:qword
        extrn '__imp_NtOpenFile' as NtOpenFile:qword
        extrn '__imp_NtOpenProcess' as NtOpenProcess:qword
        extrn '__imp_NtOpenProcessToken' as NtOpenProcessToken:qword
        extrn '__imp_NtQueryDirectoryFile' as NtQueryDirectoryFile:qword
        extrn '__imp_NtQueryEaFile' as NtQueryEaFile:qword
        extrn '__imp_NtQueryInformationAtom' as NtQueryInformationAtom:qword
        extrn '__imp_NtQueryInformationFile' as NtQueryInformationFile:qword
        extrn '__imp_NtQueryInformationProcess' as NtQueryInformationProcess:qword
        extrn '__imp_NtQueryInformationToken' as NtQueryInformationToken:qword
        extrn '__imp_NtQuerySecurityObject' as NtQuerySecurityObject:qword
        extrn '__imp_NtQueryVolumeInformationFile' as NtQueryVolumeInformationFile:qword
        extrn '__imp_NtReadFile' as NtReadFile:qword
        extrn '__imp_NtRequestPort' as NtRequestPort:qword
        extrn '__imp_NtRequestWaitReplyPort' as NtRequestWaitReplyPort:qword
        extrn '__imp_NtSetEvent' as NtSetEvent:qword
        extrn '__imp_NtSetInformationFile' as NtSetInformationFile:qword
        extrn '__imp_NtSetInformationProcess' as NtSetInformationProcess:qword
        extrn '__imp_NtSetInformationThread' as NtSetInformationThread:qword
        extrn '__imp_NtSetQuotaInformationFile' as NtSetQuotaInformationFile:qword
        extrn '__imp_NtSetSecurityObject' as NtSetSecurityObject:qword
        extrn '__imp_NtUnlockFile' as NtUnlockFile:qword
        extrn '__imp_NtVdmControl' as NtVdmControl:qword
        extrn '__imp_NtWaitForSingleObject' as NtWaitForSingleObject:qword
        extrn '__imp_NtWriteFile' as NtWriteFile:qword
        extrn '__imp_ObAssignSecurity' as ObAssignSecurity:qword
        extrn '__imp_ObCheckCreateObjectAccess' as ObCheckCreateObjectAccess:qword
        extrn '__imp_ObCheckObjectAccess' as ObCheckObjectAccess:qword
        extrn '__imp_ObCreateObject' as ObCreateObject:qword
        extrn '__imp_ObDereferenceObject' as ObDereferenceObject:qword
        extrn '__imp_ObfDereferenceObject' as ObfDereferenceObject:qword
        extrn '__imp_ObFindHandleForObject' as ObFindHandleForObject:qword
        extrn '__imp_ObfReferenceObject' as ObfReferenceObject:qword
        extrn '__imp_ObGetObjectSecurity' as ObGetObjectSecurity:qword
        extrn '__imp_ObInsertObject' as ObInsertObject:qword
        extrn '__imp_ObMakeTemporaryObject' as ObMakeTemporaryObject:qword
        extrn '__imp_ObOpenObjectByName' as ObOpenObjectByName:qword
        extrn '__imp_ObOpenObjectByPointer' as ObOpenObjectByPointer:qword
        extrn '__imp_ObQueryNameString' as ObQueryNameString:qword
        extrn '__imp_ObQueryObjectAuditingByHandle' as ObQueryObjectAuditingByHandle:qword
        extrn '__imp_ObReferenceObjectByHandle' as ObReferenceObjectByHandle:qword
        extrn '__imp_ObReferenceObjectByName' as ObReferenceObjectByName:qword
        extrn '__imp_ObReferenceObjectByPointer' as ObReferenceObjectByPointer:qword
        extrn '__imp_ObReleaseObjectSecurity' as ObReleaseObjectSecurity:qword
        extrn '__imp_ObSetSecurityDescriptorInfo' as ObSetSecurityDescriptorInfo:qword
        extrn '__imp_PfxFindPrefix' as PfxFindPrefix:qword
        extrn '__imp_PfxInitialize' as PfxInitialize:qword
        extrn '__imp_PfxInsertPrefix' as PfxInsertPrefix:qword
        extrn '__imp_PfxRemovePrefix' as PfxRemovePrefix:qword
        extrn '__imp_ProbeForWrite' as ProbeForWrite:qword
        extrn '__imp_PsAssignImpersonationToken' as PsAssignImpersonationToken:qword
        extrn '__imp_PsChargePoolQuota' as PsChargePoolQuota:qword
        extrn '__imp_PsCreateSystemThread' as PsCreateSystemThread:qword
        extrn '__imp_PsEstablishWin32Callouts' as PsEstablishWin32Callouts:qword
        extrn '__imp_PsGetCurrentProcessId' as PsGetCurrentProcessId:qword
        extrn '__imp_PsGetCurrentThreadId' as PsGetCurrentThreadId:qword
        extrn '__imp_PsGetProcessExitTime' as PsGetProcessExitTime:qword
        extrn '__imp_PsGetVersion' as PsGetVersion:qword
        extrn '__imp_PsImpersonateClient' as PsImpersonateClient:qword
        extrn '__imp_PsIsThreadTerminating' as PsIsThreadTerminating:qword
        extrn '__imp_PsLookupProcessByProcessId' as PsLookupProcessByProcessId:qword
        extrn '__imp_PsLookupProcessThreadByCid' as PsLookupProcessThreadByCid:qword
        extrn '__imp_PsLookupThreadByThreadId' as PsLookupThreadByThreadId:qword
        extrn '__imp_PsProcessType' as PsProcessType:qword
        extrn '__imp_PsReferenceImpersonationToken' as PsReferenceImpersonationToken:qword
        extrn '__imp_PsReferencePrimaryToken' as PsReferencePrimaryToken:qword
        extrn '__imp_PsReturnPoolQuota' as PsReturnPoolQuota:qword
        extrn '__imp_PsRevertToSelf' as PsRevertToSelf:qword
        extrn '__imp_PsSetCreateProcessNotifyRoutine' as PsSetCreateProcessNotifyRoutine:qword
        extrn '__imp_PsSetCreateThreadNotifyRoutine' as PsSetCreateThreadNotifyRoutine:qword
        extrn '__imp_PsSetLegoNotifyRoutine' as PsSetLegoNotifyRoutine:qword
        extrn '__imp_PsSetProcessPriorityByClass' as PsSetProcessPriorityByClass:qword
        extrn '__imp_PsTerminateSystemThread' as PsTerminateSystemThread:qword
        extrn '__imp_PsThreadType' as PsThreadType:qword
        if ~defined __imp_qsort
            extrn '__imp_qsort' as qsort:qword
        end if
        if ~defined __imp_rand
            extrn '__imp_rand' as rand:qword
        end if
        extrn '__imp_RtlAbsoluteToSelfRelativeSD' as RtlAbsoluteToSelfRelativeSD:qword
        extrn '__imp_RtlAddAccessAllowedAce' as RtlAddAccessAllowedAce:qword
        extrn '__imp_RtlAddAce' as RtlAddAce:qword
        extrn '__imp_RtlAddAtomToAtomTable' as RtlAddAtomToAtomTable:qword
        extrn '__imp_RtlAllocateHeap' as RtlAllocateHeap:qword
        extrn '__imp_RtlAnsiCharToUnicodeChar' as RtlAnsiCharToUnicodeChar:qword
        extrn '__imp_RtlAnsiStringToUnicodeSize' as RtlAnsiStringToUnicodeSize:qword
        extrn '__imp_RtlAnsiStringToUnicodeString' as RtlAnsiStringToUnicodeString:qword
        extrn '__imp_RtlAppendAsciizToString' as RtlAppendAsciizToString:qword
        extrn '__imp_RtlAppendStringToString' as RtlAppendStringToString:qword
        extrn '__imp_RtlAppendUnicodeStringToString' as RtlAppendUnicodeStringToString:qword
        extrn '__imp_RtlAppendUnicodeToString' as RtlAppendUnicodeToString:qword
        extrn '__imp_RtlAreAllAccessesGranted' as RtlAreAllAccessesGranted:qword
        extrn '__imp_RtlAreAnyAccessesGranted' as RtlAreAnyAccessesGranted:qword
        extrn '__imp_RtlAreBitsClear' as RtlAreBitsClear:qword
        extrn '__imp_RtlAreBitsSet' as RtlAreBitsSet:qword
        extrn '__imp_RtlAssert' as RtlAssert:qword
        extrn '__imp_RtlCaptureStackBackTrace' as RtlCaptureStackBackTrace:qword
        extrn '__imp_RtlCharToInteger' as RtlCharToInteger:qword
        extrn '__imp_RtlCheckRegistryKey' as RtlCheckRegistryKey:qword
        extrn '__imp_RtlClearAllBits' as RtlClearAllBits:qword
        extrn '__imp_RtlClearBits' as RtlClearBits:qword
        extrn '__imp_RtlCompareMemory' as RtlCompareMemory:qword
        extrn '__imp_RtlCompareMemoryUlong' as RtlCompareMemoryUlong:qword
        extrn '__imp_RtlCompareString' as RtlCompareString:qword
        extrn '__imp_RtlCompareUnicodeString' as RtlCompareUnicodeString:qword
        extrn '__imp_RtlCompressBuffer' as RtlCompressBuffer:qword
        extrn '__imp_RtlCompressChunks' as RtlCompressChunks:qword
        extrn '__imp_RtlConvertSidToUnicodeString' as RtlConvertSidToUnicodeString:qword
        extrn '__imp_RtlCopyLuid' as RtlCopyLuid:qword
        extrn '__imp_RtlCopyMemory' as RtlCopyMemory:qword
        extrn '__imp_RtlCopySid' as RtlCopySid:qword
        extrn '__imp_RtlCopyString' as RtlCopyString:qword
        extrn '__imp_RtlCopyUnicodeString' as RtlCopyUnicodeString:qword
        extrn '__imp_RtlCreateAcl' as RtlCreateAcl:qword
        extrn '__imp_RtlCreateAtomTable' as RtlCreateAtomTable:qword
        extrn '__imp_RtlCreateHeap' as RtlCreateHeap:qword
        extrn '__imp_RtlCreateRegistryKey' as RtlCreateRegistryKey:qword
        extrn '__imp_RtlCreateSecurityDescriptor' as RtlCreateSecurityDescriptor:qword
        extrn '__imp_RtlCreateUnicodeString' as RtlCreateUnicodeString:qword
        extrn '__imp_RtlCustomCPToUnicodeN' as RtlCustomCPToUnicodeN:qword
        extrn '__imp_RtlDecompressBuffer' as RtlDecompressBuffer:qword
        extrn '__imp_RtlDecompressChunks' as RtlDecompressChunks:qword
        extrn '__imp_RtlDecompressFragment' as RtlDecompressFragment:qword
        extrn '__imp_RtlDelete' as RtlDelete:qword
        extrn '__imp_RtlDeleteAtomFromAtomTable' as RtlDeleteAtomFromAtomTable:qword
        extrn '__imp_RtlDeleteElementGenericTable' as RtlDeleteElementGenericTable:qword
        extrn '__imp_RtlDeleteNoSplay' as RtlDeleteNoSplay:qword
        extrn '__imp_RtlDeleteRegistryValue' as RtlDeleteRegistryValue:qword
        extrn '__imp_RtlDescribeChunk' as RtlDescribeChunk:qword
        extrn '__imp_RtlDestroyAtomTable' as RtlDestroyAtomTable:qword
        extrn '__imp_RtlDestroyHeap' as RtlDestroyHeap:qword
        extrn '__imp_RtlDowncaseUnicodeString' as RtlDowncaseUnicodeString:qword
        extrn '__imp_RtlEmptyAtomTable' as RtlEmptyAtomTable:qword
        extrn '__imp_RtlEnumerateGenericTable' as RtlEnumerateGenericTable:qword
        extrn '__imp_RtlEnumerateGenericTableWithoutSplaying' as RtlEnumerateGenericTableWithoutSplaying:qword
        extrn '__imp_RtlEqualLuid' as RtlEqualLuid:qword
        extrn '__imp_RtlEqualSid' as RtlEqualSid:qword
        extrn '__imp_RtlEqualString' as RtlEqualString:qword
        extrn '__imp_RtlEqualUnicodeString' as RtlEqualUnicodeString:qword
        extrn '__imp_RtlFindClearBits' as RtlFindClearBits:qword
        extrn '__imp_RtlFindClearBitsAndSet' as RtlFindClearBitsAndSet:qword
        extrn '__imp_RtlFindFirstRunClear' as RtlFindFirstRunClear:qword
        extrn '__imp_RtlFindLongestRunClear' as RtlFindLongestRunClear:qword
        extrn '__imp_RtlFindMessage' as RtlFindMessage:qword
        extrn '__imp_RtlFindSetBits' as RtlFindSetBits:qword
        extrn '__imp_RtlFindSetBitsAndClear' as RtlFindSetBitsAndClear:qword
        extrn '__imp_RtlFindUnicodePrefix' as RtlFindUnicodePrefix:qword
        extrn '__imp_RtlFormatCurrentUserKeyPath' as RtlFormatCurrentUserKeyPath:qword
        extrn '__imp_RtlFreeAnsiString' as RtlFreeAnsiString:qword
        extrn '__imp_RtlFreeHeap' as RtlFreeHeap:qword
        extrn '__imp_RtlFreeOemString' as RtlFreeOemString:qword
        extrn '__imp_RtlFreeUnicodeString' as RtlFreeUnicodeString:qword
        extrn '__imp_RtlGenerate8dot3Name' as RtlGenerate8dot3Name:qword
        extrn '__imp_RtlGetCallersAddress' as RtlGetCallersAddress:qword
        extrn '__imp_RtlGetCompressionWorkSpaceSize' as RtlGetCompressionWorkSpaceSize:qword
        extrn '__imp_RtlGetDaclSecurityDescriptor' as RtlGetDaclSecurityDescriptor:qword
        extrn '__imp_RtlGetDefaultCodePage' as RtlGetDefaultCodePage:qword
        extrn '__imp_RtlGetElementGenericTable' as RtlGetElementGenericTable:qword
        extrn '__imp_RtlGetGroupSecurityDescriptor' as RtlGetGroupSecurityDescriptor:qword
        extrn '__imp_RtlGetOwnerSecurityDescriptor' as RtlGetOwnerSecurityDescriptor:qword
        extrn '__imp_RtlImageNtHeader' as RtlImageNtHeader:qword
        extrn '__imp_RtlInitAnsiString' as RtlInitAnsiString:qword
        extrn '__imp_RtlInitCodePageTable' as RtlInitCodePageTable:qword
        extrn '__imp_RtlInitializeBitMap' as RtlInitializeBitMap:qword
        extrn '__imp_RtlInitializeGenericTable' as RtlInitializeGenericTable:qword
        extrn '__imp_RtlInitializeSid' as RtlInitializeSid:qword
        extrn '__imp_RtlInitializeUnicodePrefix' as RtlInitializeUnicodePrefix:qword
        extrn '__imp_RtlInitString' as RtlInitString:qword
        extrn '__imp_RtlInitUnicodeString' as RtlInitUnicodeString:qword
        extrn '__imp_RtlInsertElementGenericTable' as RtlInsertElementGenericTable:qword
        extrn '__imp_RtlInsertUnicodePrefix' as RtlInsertUnicodePrefix:qword
        extrn '__imp_RtlIntegerToChar' as RtlIntegerToChar:qword
        extrn '__imp_RtlIntegerToUnicodeString' as RtlIntegerToUnicodeString:qword
        extrn '__imp_RtlIsNameLegalDOS8Dot3' as RtlIsNameLegalDOS8Dot3:qword
        extrn '__imp_RtlLengthRequiredSid' as RtlLengthRequiredSid:qword
        extrn '__imp_RtlLengthSecurityDescriptor' as RtlLengthSecurityDescriptor:qword
        extrn '__imp_RtlLengthSid' as RtlLengthSid:qword
        extrn '__imp_RtlLookupAtomInAtomTable' as RtlLookupAtomInAtomTable:qword
        extrn '__imp_RtlLookupElementGenericTable' as RtlLookupElementGenericTable:qword
        extrn '__imp_RtlMapGenericMask' as RtlMapGenericMask:qword
        extrn '__imp_RtlMultiByteToUnicodeN' as RtlMultiByteToUnicodeN:qword
        extrn '__imp_RtlMultiByteToUnicodeSize' as RtlMultiByteToUnicodeSize:qword
        extrn '__imp_RtlNextUnicodePrefix' as RtlNextUnicodePrefix:qword
        extrn '__imp_RtlNtStatusToDosError' as RtlNtStatusToDosError:qword
        extrn '__imp_RtlNtStatusToDosErrorNoTeb' as RtlNtStatusToDosErrorNoTeb:qword
        extrn '__imp_RtlNumberGenericTableElements' as RtlNumberGenericTableElements:qword
        extrn '__imp_RtlNumberOfClearBits' as RtlNumberOfClearBits:qword
        extrn '__imp_RtlNumberOfSetBits' as RtlNumberOfSetBits:qword
        extrn '__imp_RtlOemStringToCountedUnicodeString' as RtlOemStringToCountedUnicodeString:qword
        extrn '__imp_RtlOemStringToUnicodeSize' as RtlOemStringToUnicodeSize:qword
        extrn '__imp_RtlOemStringToUnicodeString' as RtlOemStringToUnicodeString:qword
        extrn '__imp_RtlOemToUnicodeN' as RtlOemToUnicodeN:qword
        extrn '__imp_RtlPinAtomInAtomTable' as RtlPinAtomInAtomTable:qword
        extrn '__imp_RtlPrefixString' as RtlPrefixString:qword
        extrn '__imp_RtlPrefixUnicodeString' as RtlPrefixUnicodeString:qword
        extrn '__imp_RtlQueryAtomInAtomTable' as RtlQueryAtomInAtomTable:qword
        extrn '__imp_RtlQueryRegistryValues' as RtlQueryRegistryValues:qword
        extrn '__imp_RtlQueryTimeZoneInformation' as RtlQueryTimeZoneInformation:qword
        extrn '__imp_RtlRaiseException' as RtlRaiseException:qword
        extrn '__imp_RtlRandom' as RtlRandom:qword
        extrn '__imp_RtlRemoveUnicodePrefix' as RtlRemoveUnicodePrefix:qword
        extrn '__imp_RtlReserveChunk' as RtlReserveChunk:qword
        extrn '__imp_RtlSecondsSince1970ToTime' as RtlSecondsSince1970ToTime:qword
        extrn '__imp_RtlSecondsSince1980ToTime' as RtlSecondsSince1980ToTime:qword
        extrn '__imp_RtlSetAllBits' as RtlSetAllBits:qword
        extrn '__imp_RtlSetBits' as RtlSetBits:qword
        extrn '__imp_RtlSetDaclSecurityDescriptor' as RtlSetDaclSecurityDescriptor:qword
        extrn '__imp_RtlSetGroupSecurityDescriptor' as RtlSetGroupSecurityDescriptor:qword
        extrn '__imp_RtlSetOwnerSecurityDescriptor' as RtlSetOwnerSecurityDescriptor:qword
        extrn '__imp_RtlSetSaclSecurityDescriptor' as RtlSetSaclSecurityDescriptor:qword
        extrn '__imp_RtlSetTimeZoneInformation' as RtlSetTimeZoneInformation:qword
        extrn '__imp_RtlSplay' as RtlSplay:qword
        extrn '__imp_RtlSubAuthorityCountSid' as RtlSubAuthorityCountSid:qword
        extrn '__imp_RtlSubAuthoritySid' as RtlSubAuthoritySid:qword
        extrn '__imp_RtlTimeFieldsToTime' as RtlTimeFieldsToTime:qword
        extrn '__imp_RtlTimeToSecondsSince1970' as RtlTimeToSecondsSince1970:qword
        extrn '__imp_RtlTimeToSecondsSince1980' as RtlTimeToSecondsSince1980:qword
        extrn '__imp_RtlTimeToTimeFields' as RtlTimeToTimeFields:qword
        extrn '__imp_RtlUnicodeStringToAnsiSize' as RtlUnicodeStringToAnsiSize:qword
        extrn '__imp_RtlUnicodeStringToAnsiString' as RtlUnicodeStringToAnsiString:qword
        extrn '__imp_RtlUnicodeStringToCountedOemString' as RtlUnicodeStringToCountedOemString:qword
        extrn '__imp_RtlUnicodeStringToInteger' as RtlUnicodeStringToInteger:qword
        extrn '__imp_RtlUnicodeStringToOemSize' as RtlUnicodeStringToOemSize:qword
        extrn '__imp_RtlUnicodeStringToOemString' as RtlUnicodeStringToOemString:qword
        extrn '__imp_RtlUnicodeToCustomCPN' as RtlUnicodeToCustomCPN:qword
        extrn '__imp_RtlUnicodeToMultiByteN' as RtlUnicodeToMultiByteN:qword
        extrn '__imp_RtlUnicodeToMultiByteSize' as RtlUnicodeToMultiByteSize:qword
        extrn '__imp_RtlUnicodeToOemN' as RtlUnicodeToOemN:qword
        extrn '__imp_RtlUnwindEx' as RtlUnwindEx:qword
        extrn '__imp_RtlUpcaseUnicodeChar' as RtlUpcaseUnicodeChar:qword
        extrn '__imp_RtlUpcaseUnicodeString' as RtlUpcaseUnicodeString:qword
        extrn '__imp_RtlUpcaseUnicodeStringToAnsiString' as RtlUpcaseUnicodeStringToAnsiString:qword
        extrn '__imp_RtlUpcaseUnicodeStringToCountedOemString' as RtlUpcaseUnicodeStringToCountedOemString:qword
        extrn '__imp_RtlUpcaseUnicodeStringToOemString' as RtlUpcaseUnicodeStringToOemString:qword
        extrn '__imp_RtlUpcaseUnicodeToCustomCPN' as RtlUpcaseUnicodeToCustomCPN:qword
        extrn '__imp_RtlUpcaseUnicodeToMultiByteN' as RtlUpcaseUnicodeToMultiByteN:qword
        extrn '__imp_RtlUpcaseUnicodeToOemN' as RtlUpcaseUnicodeToOemN:qword
        extrn '__imp_RtlUpperChar' as RtlUpperChar:qword
        extrn '__imp_RtlUpperString' as RtlUpperString:qword
        extrn '__imp_RtlValidSecurityDescriptor' as RtlValidSecurityDescriptor:qword
        extrn '__imp_RtlValidSid' as RtlValidSid:qword
        extrn '__imp_RtlWriteRegistryValue' as RtlWriteRegistryValue:qword
        extrn '__imp_RtlxAnsiStringToUnicodeSize' as RtlxAnsiStringToUnicodeSize:qword
        extrn '__imp_RtlxOemStringToUnicodeSize' as RtlxOemStringToUnicodeSize:qword
        extrn '__imp_RtlxUnicodeStringToAnsiSize' as RtlxUnicodeStringToAnsiSize:qword
        extrn '__imp_RtlxUnicodeStringToOemSize' as RtlxUnicodeStringToOemSize:qword
        extrn '__imp_RtlZeroHeap' as RtlZeroHeap:qword
        extrn '__imp_SeAccessCheck' as SeAccessCheck:qword
        extrn '__imp_SeAppendPrivileges' as SeAppendPrivileges:qword
        extrn '__imp_SeAssignSecurity' as SeAssignSecurity:qword
        extrn '__imp_SeAuditingFileEvents' as SeAuditingFileEvents:qword
        extrn '__imp_SeAuditingFileOrGlobalEvents' as SeAuditingFileOrGlobalEvents:qword
        extrn '__imp_SeCaptureSecurityDescriptor' as SeCaptureSecurityDescriptor:qword
        extrn '__imp_SeCaptureSubjectContext' as SeCaptureSubjectContext:qword
        extrn '__imp_SeCloseObjectAuditAlarm' as SeCloseObjectAuditAlarm:qword
        extrn '__imp_SeCreateAccessState' as SeCreateAccessState:qword
        extrn '__imp_SeCreateClientSecurity' as SeCreateClientSecurity:qword
        extrn '__imp_SeDeassignSecurity' as SeDeassignSecurity:qword
        extrn '__imp_SeDeleteAccessState' as SeDeleteAccessState:qword
        extrn '__imp_SeDeleteObjectAuditAlarm' as SeDeleteObjectAuditAlarm:qword
        extrn '__imp_SeFreePrivileges' as SeFreePrivileges:qword
        extrn '__imp_SeImpersonateClient' as SeImpersonateClient:qword
        extrn '__imp_SeLockSubjectContext' as SeLockSubjectContext:qword
        extrn '__imp_SeMarkLogonSessionForTerminationNotification' as SeMarkLogonSessionForTerminationNotification:qword
        extrn '__imp_SeOpenObjectAuditAlarm' as SeOpenObjectAuditAlarm:qword
        extrn '__imp_SeOpenObjectForDeleteAuditAlarm' as SeOpenObjectForDeleteAuditAlarm:qword
        extrn '__imp_SePrivilegeCheck' as SePrivilegeCheck:qword
        extrn '__imp_SePrivilegeObjectAuditAlarm' as SePrivilegeObjectAuditAlarm:qword
        extrn '__imp_SeQueryAuthenticationIdToken' as SeQueryAuthenticationIdToken:qword
        extrn '__imp_SeQuerySecurityDescriptorInfo' as SeQuerySecurityDescriptorInfo:qword
        extrn '__imp_SeRegisterLogonSessionTerminatedRoutine' as SeRegisterLogonSessionTerminatedRoutine:qword
        extrn '__imp_SeReleaseSecurityDescriptor' as SeReleaseSecurityDescriptor:qword
        extrn '__imp_SeReleaseSubjectContext' as SeReleaseSubjectContext:qword
        extrn '__imp_SeSetAccessStateGenericMapping' as SeSetAccessStateGenericMapping:qword
        extrn '__imp_SeSetSecurityDescriptorInfo' as SeSetSecurityDescriptorInfo:qword
        extrn '__imp_SeSinglePrivilegeCheck' as SeSinglePrivilegeCheck:qword
        extrn '__imp_SeTokenImpersonationLevel' as SeTokenImpersonationLevel:qword
        extrn '__imp_SeTokenType' as SeTokenType:qword
        extrn '__imp_SeUnlockSubjectContext' as SeUnlockSubjectContext:qword
        extrn '__imp_SeUnregisterLogonSessionTerminatedRoutine' as SeUnregisterLogonSessionTerminatedRoutine:qword
        extrn '__imp_SeValidSecurityDescriptor' as SeValidSecurityDescriptor:qword
        if ~defined __imp_tolower
            extrn '__imp_tolower' as tolower:qword
        end if
        if ~defined __imp_toupper
            extrn '__imp_toupper' as toupper:qword
        end if
        if ~defined __imp_towlower
            extrn '__imp_towlower' as towlower:qword
        end if
        if ~defined __imp_towupper
            extrn '__imp_towupper' as towupper:qword
        end if
        if ~defined __imp_vsprintf
            extrn '__imp_vsprintf' as vsprintf:qword
        end if
        if ~defined __imp_wcscat
            extrn '__imp_wcscat' as wcscat:qword
            extrn '__imp_wcschr' as wcschr:qword
            extrn '__imp_wcscmp' as wcscmp:qword
            extrn '__imp_wcscpy' as wcscpy:qword
            extrn '__imp_wcscspn' as wcscspn:qword
            extrn '__imp_wcslen' as wcslen:qword
            extrn '__imp_wcsncat' as wcsncat:qword
            extrn '__imp_wcsncmp' as wcsncmp:qword
            extrn '__imp_wcsncpy' as wcsncpy:qword
            extrn '__imp_wcsrchr' as wcsrchr:qword
            extrn '__imp_wcsspn' as wcsspn:qword
            extrn '__imp_wcsstr' as wcsstr:qword
            extrn '__imp_wcstombs' as wcstombs:qword
            extrn '__imp_wctomb' as wctomb:qword
        end if
        extrn '__imp_ZwAccessCheckAndAuditAlarm' as ZwAccessCheckAndAuditAlarm:qword
        extrn '__imp_ZwAlertThread' as ZwAlertThread:qword
        extrn '__imp_ZwAllocateVirtualMemory' as ZwAllocateVirtualMemory:qword
        extrn '__imp_ZwClearEvent' as ZwClearEvent:qword
        extrn '__imp_ZwClose' as ZwClose:qword
        extrn '__imp_ZwCloseObjectAuditAlarm' as ZwCloseObjectAuditAlarm:qword
        extrn '__imp_ZwConnectPort' as ZwConnectPort:qword
        extrn '__imp_ZwCreateDirectoryObject' as ZwCreateDirectoryObject:qword
        extrn '__imp_ZwCreateEvent' as ZwCreateEvent:qword
        extrn '__imp_ZwCreateFile' as ZwCreateFile:qword
        extrn '__imp_ZwCreateKey' as ZwCreateKey:qword
        extrn '__imp_ZwCreateSection' as ZwCreateSection:qword
        extrn '__imp_ZwCreateSymbolicLinkObject' as ZwCreateSymbolicLinkObject:qword
        extrn '__imp_ZwDeleteFile' as ZwDeleteFile:qword
        extrn '__imp_ZwDeleteKey' as ZwDeleteKey:qword
        extrn '__imp_ZwDeleteValueKey' as ZwDeleteValueKey:qword
        extrn '__imp_ZwDeviceIoControlFile' as ZwDeviceIoControlFile:qword
        extrn '__imp_ZwDisplayString' as ZwDisplayString:qword
        extrn '__imp_ZwDuplicateObject' as ZwDuplicateObject:qword
        extrn '__imp_ZwDuplicateToken' as ZwDuplicateToken:qword
        extrn '__imp_ZwEnumerateKey' as ZwEnumerateKey:qword
        extrn '__imp_ZwEnumerateValueKey' as ZwEnumerateValueKey:qword
        extrn '__imp_ZwFlushInstructionCache' as ZwFlushInstructionCache:qword
        extrn '__imp_ZwFlushKey' as ZwFlushKey:qword
        extrn '__imp_ZwFreeVirtualMemory' as ZwFreeVirtualMemory:qword
        extrn '__imp_ZwFsControlFile' as ZwFsControlFile:qword
        extrn '__imp_ZwLoadDriver' as ZwLoadDriver:qword
        extrn '__imp_ZwLoadKey' as ZwLoadKey:qword
        extrn '__imp_ZwMakeTemporaryObject' as ZwMakeTemporaryObject:qword
        extrn '__imp_ZwMapViewOfSection' as ZwMapViewOfSection:qword
        extrn '__imp_ZwNotifyChangeKey' as ZwNotifyChangeKey:qword
        extrn '__imp_ZwOpenDirectoryObject' as ZwOpenDirectoryObject:qword
        extrn '__imp_ZwOpenEvent' as ZwOpenEvent:qword
        extrn '__imp_ZwOpenFile' as ZwOpenFile:qword
        extrn '__imp_ZwOpenKey' as ZwOpenKey:qword
        extrn '__imp_ZwOpenProcess' as ZwOpenProcess:qword
        extrn '__imp_ZwOpenProcessToken' as ZwOpenProcessToken:qword
        extrn '__imp_ZwOpenSection' as ZwOpenSection:qword
        extrn '__imp_ZwOpenSymbolicLinkObject' as ZwOpenSymbolicLinkObject:qword
        extrn '__imp_ZwOpenThread' as ZwOpenThread:qword
        extrn '__imp_ZwOpenThreadToken' as ZwOpenThreadToken:qword
        extrn '__imp_ZwPulseEvent' as ZwPulseEvent:qword
        extrn '__imp_ZwQueryDefaultLocale' as ZwQueryDefaultLocale:qword
        extrn '__imp_ZwQueryDirectoryFile' as ZwQueryDirectoryFile:qword
        extrn '__imp_ZwQueryInformationFile' as ZwQueryInformationFile:qword
        extrn '__imp_ZwQueryInformationProcess' as ZwQueryInformationProcess:qword
        extrn '__imp_ZwQueryInformationToken' as ZwQueryInformationToken:qword
        extrn '__imp_ZwQueryKey' as ZwQueryKey:qword
        extrn '__imp_ZwQueryObject' as ZwQueryObject:qword
        extrn '__imp_ZwQuerySection' as ZwQuerySection:qword
        extrn '__imp_ZwQuerySecurityObject' as ZwQuerySecurityObject:qword
        extrn '__imp_ZwQuerySymbolicLinkObject' as ZwQuerySymbolicLinkObject:qword
        extrn '__imp_ZwQuerySystemInformation' as ZwQuerySystemInformation:qword
        extrn '__imp_ZwQueryValueKey' as ZwQueryValueKey:qword
        extrn '__imp_ZwQueryVolumeInformationFile' as ZwQueryVolumeInformationFile:qword
        extrn '__imp_ZwReadFile' as ZwReadFile:qword
        extrn '__imp_ZwReplaceKey' as ZwReplaceKey:qword
        extrn '__imp_ZwRequestWaitReplyPort' as ZwRequestWaitReplyPort:qword
        extrn '__imp_ZwResetEvent' as ZwResetEvent:qword
        extrn '__imp_ZwSaveKey' as ZwSaveKey:qword
        extrn '__imp_ZwSetDefaultLocale' as ZwSetDefaultLocale:qword
        extrn '__imp_ZwSetEvent' as ZwSetEvent:qword
        extrn '__imp_ZwSetInformationFile' as ZwSetInformationFile:qword
        extrn '__imp_ZwSetInformationObject' as ZwSetInformationObject:qword
        extrn '__imp_ZwSetInformationProcess' as ZwSetInformationProcess:qword
        extrn '__imp_ZwSetInformationThread' as ZwSetInformationThread:qword
        extrn '__imp_ZwSetSystemInformation' as ZwSetSystemInformation:qword
        extrn '__imp_ZwSetSystemTime' as ZwSetSystemTime:qword
        extrn '__imp_ZwSetValueKey' as ZwSetValueKey:qword
        extrn '__imp_ZwTerminateProcess' as ZwTerminateProcess:qword
        extrn '__imp_ZwUnloadDriver' as ZwUnloadDriver:qword
        extrn '__imp_ZwUnloadKey' as ZwUnloadKey:qword
        extrn '__imp_ZwUnmapViewOfSection' as ZwUnmapViewOfSection:qword
        extrn '__imp_ZwWaitForMultipleObjects' as ZwWaitForMultipleObjects:qword
        extrn '__imp_ZwWaitForSingleObject' as ZwWaitForSingleObject:qword
        extrn '__imp_ZwWriteFile' as ZwWriteFile:qword
        extrn '__imp_ZwYieldExecution' as ZwYieldExecution:qword
        if ~defined __imp__itoa
            extrn '__imp__itoa' as _itoa:qword
        end if
        if ~defined __imp__purecall
            extrn '__imp__purecall' as _purecall:qword
        end if
        if ~defined __imp__snprintf
            extrn '__imp__snprintf' as _snprintf:qword
        end if
        if ~defined __imp__stricmp
            extrn '__imp__stricmp' as _stricmp:qword
        end if
        if ~defined __imp__strlwr
            extrn '__imp__strlwr' as _strlwr:qword
        end if
        if ~defined __imp__strnicmp
            extrn '__imp__strnicmp' as _strnicmp:qword
        end if
        if ~defined __imp__strnset
            extrn '__imp__strnset' as _strnset:qword
        end if
        if ~defined __imp__strrev
            extrn '__imp__strrev' as _strrev:qword
        end if
        if ~defined __imp__strset
            extrn '__imp__strset' as _strset:qword
        end if
        if ~defined __imp__strupr
            extrn '__imp__strupr' as _strupr:qword
        end if
        if ~defined __imp__vsnprintf
            extrn '__imp__vsnprintf' as _vsnprintf:qword
        end if
        if ~defined __imp__wcsicmp
            extrn '__imp__wcsicmp' as _wcsicmp:qword
        end if
        if ~defined __imp__wcslwr
            extrn '__imp__wcslwr' as _wcslwr:qword
        end if
        if ~defined __imp__wcsnicmp
            extrn '__imp__wcsnicmp' as _wcsnicmp:qword
        end if
        if ~defined __imp__wcsnset
            extrn '__imp__wcsnset' as _wcsnset:qword
        end if
        if ~defined __imp__wcsrev
            extrn '__imp__wcsrev' as _wcsrev:qword
        end if
        if ~defined __imp__wcsupr
            extrn '__imp__wcsupr' as _wcsupr:qword
        end if

        if (NTDDI_VERSION >= NTDDI_WIN2K)
            extrn '__imp_CcGetFlushedValidData' as CcGetFlushedValidData:qword
            extrn '__imp_CcRemapBcb' as CcRemapBcb:qword
            extrn '__imp_CcWaitForCurrentLazyWriterActivity' as CcWaitForCurrentLazyWriterActivity:qword
            extrn '__imp_ExFreePoolWithTag' as ExFreePoolWithTag:qword
            extrn '__imp_ExSetTimerResolution' as ExSetTimerResolution:qword
            extrn '__imp_ExUuidCreate' as ExUuidCreate:qword
            extrn '__imp_FsRtlAllocateFileLock' as FsRtlAllocateFileLock:qword
            extrn '__imp_FsRtlCreateSectionForDataScan' as FsRtlCreateSectionForDataScan:qword
            extrn '__imp_FsRtlFreeFileLock' as FsRtlFreeFileLock:qword
            extrn '__imp_FsRtlInsertPerFileObjectContext' as FsRtlInsertPerFileObjectContext:qword
            extrn '__imp_FsRtlInsertPerStreamContext' as FsRtlInsertPerStreamContext:qword
            extrn '__imp_FsRtlIsPagingFile' as FsRtlIsPagingFile:qword
            extrn '__imp_FsRtlLookupLastLargeMcbEntryAndIndex' as FsRtlLookupLastLargeMcbEntryAndIndex:qword
            extrn '__imp_FsRtlLookupPerFileObjectContext' as FsRtlLookupPerFileObjectContext:qword
            extrn '__imp_FsRtlLookupPerStreamContextInternal' as FsRtlLookupPerStreamContextInternal:qword
            extrn '__imp_FsRtlNotifyFilterChangeDirectory' as FsRtlNotifyFilterChangeDirectory:qword
            extrn '__imp_FsRtlNotifyFilterReportChange' as FsRtlNotifyFilterReportChange:qword
            extrn '__imp_FsRtlNotifyVolumeEvent' as FsRtlNotifyVolumeEvent:qword
            extrn '__imp_FsRtlRegisterFileSystemFilterCallbacks' as FsRtlRegisterFileSystemFilterCallbacks:qword
            extrn '__imp_FsRtlReleaseFile' as FsRtlReleaseFile:qword
            extrn '__imp_FsRtlRemovePerFileObjectContext' as FsRtlRemovePerFileObjectContext:qword
            extrn '__imp_FsRtlRemovePerStreamContext' as FsRtlRemovePerStreamContext:qword
            extrn '__imp_FsRtlResetBaseMcb' as FsRtlResetBaseMcb:qword
            extrn '__imp_FsRtlResetLargeMcb' as FsRtlResetLargeMcb:qword
            extrn '__imp_FsRtlTeardownPerStreamContexts' as FsRtlTeardownPerStreamContexts:qword
            extrn '__imp_InbvAcquireDisplayOwnership' as InbvAcquireDisplayOwnership:qword
            extrn '__imp_InbvCheckDisplayOwnership' as InbvCheckDisplayOwnership:qword
            extrn '__imp_InbvDisplayString' as InbvDisplayString:qword
            extrn '__imp_InbvEnableBootDriver' as InbvEnableBootDriver:qword
            extrn '__imp_InbvEnableDisplayString' as InbvEnableDisplayString:qword
            extrn '__imp_InbvInstallDisplayStringFilter' as InbvInstallDisplayStringFilter:qword
            extrn '__imp_InbvIsBootDriverInstalled' as InbvIsBootDriverInstalled:qword
            extrn '__imp_InbvNotifyDisplayOwnershipLost' as InbvNotifyDisplayOwnershipLost:qword
            extrn '__imp_InbvResetDisplay' as InbvResetDisplay:qword
            extrn '__imp_InbvSetScrollRegion' as InbvSetScrollRegion:qword
            extrn '__imp_InbvSetTextColor' as InbvSetTextColor:qword
            extrn '__imp_InbvSolidColorFill' as InbvSolidColorFill:qword
            extrn '__imp_IoAcquireCancelSpinLock' as IoAcquireCancelSpinLock:qword
            extrn '__imp_IoAcquireRemoveLockEx' as IoAcquireRemoveLockEx:qword
            extrn '__imp_IoAllocateDriverObjectExtension' as IoAllocateDriverObjectExtension:qword
            extrn '__imp_IoAllocateWorkItem' as IoAllocateWorkItem:qword
            extrn '__imp_IoAttachDeviceToDeviceStackSafe' as IoAttachDeviceToDeviceStackSafe:qword
            extrn '__imp_IoCancelFileOpen' as IoCancelFileOpen:qword
            extrn '__imp_IoCheckQuerySetFileInformation' as IoCheckQuerySetFileInformation:qword
            extrn '__imp_IoCheckQuerySetVolumeInformation' as IoCheckQuerySetVolumeInformation:qword
            extrn '__imp_IoCheckQuotaBufferValidity' as IoCheckQuotaBufferValidity:qword
            extrn '__imp_IoCreateDriver' as IoCreateDriver:qword
            extrn '__imp_IoCreateFileSpecifyDeviceObjectHint' as IoCreateFileSpecifyDeviceObjectHint:qword
            extrn '__imp_IoCreateStreamFileObjectLite' as IoCreateStreamFileObjectLite:qword
            extrn '__imp_IoDeleteDriver' as IoDeleteDriver:qword
            extrn '__imp_IoEnumerateDeviceObjectList' as IoEnumerateDeviceObjectList:qword
            extrn '__imp_IoEnumerateRegisteredFiltersList' as IoEnumerateRegisteredFiltersList:qword
            extrn '__imp_IoFreeWorkItem' as IoFreeWorkItem:qword
            extrn '__imp_IoGetAttachedDeviceReference' as IoGetAttachedDeviceReference:qword
            extrn '__imp_IoGetBootDiskInformation' as IoGetBootDiskInformation:qword
            extrn '__imp_IoGetDeviceAttachmentBaseRef' as IoGetDeviceAttachmentBaseRef:qword
            extrn '__imp_IoGetDeviceInterfaceAlias' as IoGetDeviceInterfaceAlias:qword
            extrn '__imp_IoGetDeviceInterfaces' as IoGetDeviceInterfaces:qword
            extrn '__imp_IoGetDeviceProperty' as IoGetDeviceProperty:qword
            extrn '__imp_IoGetDiskDeviceObject' as IoGetDiskDeviceObject:qword
            extrn '__imp_IoGetDmaAdapter' as IoGetDmaAdapter:qword
            extrn '__imp_IoGetDriverObjectExtension' as IoGetDriverObjectExtension:qword
            extrn '__imp_IoGetLowerDeviceObject' as IoGetLowerDeviceObject:qword
            extrn '__imp_IoGetRequestorProcessId' as IoGetRequestorProcessId:qword
            extrn '__imp_IoGetRequestorSessionId' as IoGetRequestorSessionId:qword
            extrn '__imp_IoInitializeRemoveLockEx' as IoInitializeRemoveLockEx:qword
            extrn '__imp_IoInvalidateDeviceRelations' as IoInvalidateDeviceRelations:qword
            extrn '__imp_IoInvalidateDeviceState' as IoInvalidateDeviceState:qword
            extrn '__imp_IoIsFileOriginRemote' as IoIsFileOriginRemote:qword
            extrn '__imp_IoIsValidNameGraftingBuffer' as IoIsValidNameGraftingBuffer:qword
            extrn '__imp_IoIsWdmVersionAvailable' as IoIsWdmVersionAvailable:qword
            extrn '__imp_IoOpenDeviceInterfaceRegistryKey' as IoOpenDeviceInterfaceRegistryKey:qword
            extrn '__imp_IoOpenDeviceRegistryKey' as IoOpenDeviceRegistryKey:qword
            extrn '__imp_IoQueueWorkItem' as IoQueueWorkItem:qword
            extrn '__imp_IoRegisterBootDriverReinitialization' as IoRegisterBootDriverReinitialization:qword
            extrn '__imp_IoRegisterDeviceInterface' as IoRegisterDeviceInterface:qword
            extrn '__imp_IoRegisterLastChanceShutdownNotification' as IoRegisterLastChanceShutdownNotification:qword
            extrn '__imp_IoRegisterPlugPlayNotification' as IoRegisterPlugPlayNotification:qword
            extrn '__imp_IoReleaseRemoveLockAndWaitEx' as IoReleaseRemoveLockAndWaitEx:qword
            extrn '__imp_IoReleaseRemoveLockEx' as IoReleaseRemoveLockEx:qword
            extrn '__imp_IoReportDetectedDevice' as IoReportDetectedDevice:qword
            extrn '__imp_IoReportResourceForDetection' as IoReportResourceForDetection:qword
            extrn '__imp_IoReportTargetDeviceChange' as IoReportTargetDeviceChange:qword
            extrn '__imp_IoReportTargetDeviceChangeAsynchronous' as IoReportTargetDeviceChangeAsynchronous:qword
            extrn '__imp_IoRequestDeviceEject' as IoRequestDeviceEject:qword
            extrn '__imp_IoReuseIrp' as IoReuseIrp:qword
            extrn '__imp_IoSetDeviceInterfaceState' as IoSetDeviceInterfaceState:qword
            extrn '__imp_IoSetFileOrigin' as IoSetFileOrigin:qword
            extrn '__imp_IoSetIoCompletion' as IoSetIoCompletion:qword
            extrn '__imp_IoSynchronousInvalidateDeviceRelations' as IoSynchronousInvalidateDeviceRelations:qword
            extrn '__imp_IoUnregisterPlugPlayNotification' as IoUnregisterPlugPlayNotification:qword
            extrn '__imp_IoVolumeDeviceToDosName' as IoVolumeDeviceToDosName:qword
            extrn '__imp_IoWMIAllocateInstanceIds' as IoWMIAllocateInstanceIds:qword
            extrn '__imp_IoWMIRegistrationControl' as IoWMIRegistrationControl:qword
            extrn '__imp_IoWMISuggestInstanceName' as IoWMISuggestInstanceName:qword
            extrn '__imp_IoWMIWriteEvent' as IoWMIWriteEvent:qword
            extrn '__imp_KdDisableDebugger' as KdDisableDebugger:qword
            extrn '__imp_KdEnableDebugger' as KdEnableDebugger:qword
            extrn '__imp_KeQueryActiveProcessors' as KeQueryActiveProcessors:qword
            extrn '__imp_KeQueryPriorityThread' as KeQueryPriorityThread:qword
            extrn '__imp_KeSaveStateForHibernate' as KeSaveStateForHibernate:qword
            extrn '__imp_KeSetSystemAffinityThread' as KeSetSystemAffinityThread:qword
            extrn '__imp_KeStackAttachProcess' as KeStackAttachProcess:qword
            extrn '__imp_KeUnstackDetachProcess' as KeUnstackDetachProcess:qword
            extrn '__imp_LpcRequestWaitReplyPort' as LpcRequestWaitReplyPort:qword
            extrn '__imp_MmAddPhysicalMemory' as MmAddPhysicalMemory:qword
            extrn '__imp_MmAddVerifierThunks' as MmAddVerifierThunks:qword
            extrn '__imp_MmAllocateContiguousMemorySpecifyCache' as MmAllocateContiguousMemorySpecifyCache:qword
            extrn '__imp_MmAllocateMappingAddress' as MmAllocateMappingAddress:qword
            extrn '__imp_MmAllocatePagesForMdl' as MmAllocatePagesForMdl:qword
            extrn '__imp_MmCommitSessionMappedView' as MmCommitSessionMappedView:qword
            extrn '__imp_MmFreeContiguousMemorySpecifyCache' as MmFreeContiguousMemorySpecifyCache:qword
            extrn '__imp_MmFreeMappingAddress' as MmFreeMappingAddress:qword
            extrn '__imp_MmFreePagesFromMdl' as MmFreePagesFromMdl:qword
            extrn '__imp_MmGetPhysicalMemoryRanges' as MmGetPhysicalMemoryRanges:qword
            extrn '__imp_MmGetSystemRoutineAddress' as MmGetSystemRoutineAddress:qword
            extrn '__imp_MmGetVirtualForPhysical' as MmGetVirtualForPhysical:qword
            extrn '__imp_MmIsDriverVerifying' as MmIsDriverVerifying:qword
            extrn '__imp_MmIsVerifierEnabled' as MmIsVerifierEnabled:qword
            extrn '__imp_MmMapLockedPagesWithReservedMapping' as MmMapLockedPagesWithReservedMapping:qword
            extrn '__imp_MmMapUserAddressesToPage' as MmMapUserAddressesToPage:qword
            extrn '__imp_MmMapViewInSessionSpace' as MmMapViewInSessionSpace:qword
            extrn '__imp_MmProbeAndLockProcessPages' as MmProbeAndLockProcessPages:qword
            extrn '__imp_MmProbeAndLockSelectedPages' as MmProbeAndLockSelectedPages:qword
            extrn '__imp_MmRemovePhysicalMemory' as MmRemovePhysicalMemory:qword
            extrn '__imp_MmTrimAllSystemPagableMemory' as MmTrimAllSystemPagableMemory:qword
            extrn '__imp_MmUnmapReservedMapping' as MmUnmapReservedMapping:qword
            extrn '__imp_MmUnmapViewInSessionSpace' as MmUnmapViewInSessionSpace:qword
            extrn '__imp_NtQueryQuotaInformationFile' as NtQueryQuotaInformationFile:qword
            extrn '__imp_NtQuerySystemInformation' as NtQuerySystemInformation:qword
            extrn '__imp_NtSetEaFile' as NtSetEaFile:qword
            extrn '__imp_NtSetVolumeInformationFile' as NtSetVolumeInformationFile:qword
            extrn '__imp_ObCreateObjectType' as ObCreateObjectType:qword
            if (NTDDI_VERSION = NTDDI_WINXP)
                extrn '__imp_WmiTraceFastEvent' as WmiTraceFastEvent:qword
            else
                extrn '__imp_ObDeleteCapturedInsertInfo' as ObDeleteCapturedInsertInfo:qword
            end if
            extrn '__imp_PoCallDriver' as PoCallDriver:qword
            extrn '__imp_PoCancelDeviceNotify' as PoCancelDeviceNotify:qword
            extrn '__imp_PoRegisterDeviceForIdleDetection' as PoRegisterDeviceForIdleDetection:qword
            extrn '__imp_PoRegisterDeviceNotify' as PoRegisterDeviceNotify:qword
            extrn '__imp_PoRegisterSystemState' as PoRegisterSystemState:qword
            extrn '__imp_PoRequestPowerIrp' as PoRequestPowerIrp:qword
            extrn '__imp_PoSetHiberRange' as PoSetHiberRange:qword
            extrn '__imp_PoSetPowerState' as PoSetPowerState:qword
            extrn '__imp_PoSetSystemState' as PoSetSystemState:qword
            extrn '__imp_PoShutdownBugCheck' as PoShutdownBugCheck:qword
            extrn '__imp_PoStartNextPowerIrp' as PoStartNextPowerIrp:qword
            extrn '__imp_PoUnregisterSystemState' as PoUnregisterSystemState:qword
            extrn '__imp_ProbeForRead' as ProbeForRead:qword
            extrn '__imp_PsDisableImpersonation' as PsDisableImpersonation:qword
            extrn '__imp_PsGetProcessId' as PsGetProcessId:qword
            extrn '__imp_PsGetProcessImageFileName' as PsGetProcessImageFileName:qword
            extrn '__imp_PsRestoreImpersonation' as PsRestoreImpersonation:qword
            extrn '__imp_PsSetLoadImageNotifyRoutine' as PsSetLoadImageNotifyRoutine:qword
            extrn '__imp_RtlAddAccessAllowedAceEx' as RtlAddAccessAllowedAceEx:qword
            extrn '__imp_RtlAddRange' as RtlAddRange:qword
            extrn '__imp_RtlCaptureContext' as RtlCaptureContext:qword
            extrn '__imp_RtlCopyRangeList' as RtlCopyRangeList:qword
            extrn '__imp_RtlDeleteAce' as RtlDeleteAce:qword
            extrn '__imp_RtlDeleteOwnersRanges' as RtlDeleteOwnersRanges:qword
            extrn '__imp_RtlDeleteRange' as RtlDeleteRange:qword
            extrn '__imp_RtlFindClearRuns' as RtlFindClearRuns:qword
            extrn '__imp_RtlFindLastBackwardRunClear' as RtlFindLastBackwardRunClear:qword
            extrn '__imp_RtlFindLeastSignificantBit' as RtlFindLeastSignificantBit:qword
            extrn '__imp_RtlFindMostSignificantBit' as RtlFindMostSignificantBit:qword
            extrn '__imp_RtlFindNextForwardRunClear' as RtlFindNextForwardRunClear:qword
            extrn '__imp_RtlFindRange' as RtlFindRange:qword
            extrn '__imp_RtlFreeRangeList' as RtlFreeRangeList:qword
            extrn '__imp_RtlGetAce' as RtlGetAce:qword
            extrn '__imp_RtlGetFirstRange' as RtlGetFirstRange:qword
            extrn '__imp_RtlGetNextRange' as RtlGetNextRange:qword
            extrn '__imp_RtlGetNtGlobalFlags' as RtlGetNtGlobalFlags:qword
            extrn '__imp_RtlGetSaclSecurityDescriptor' as RtlGetSaclSecurityDescriptor:qword
            extrn '__imp_RtlGUIDFromString' as RtlGUIDFromString:qword
            extrn '__imp_RtlImageDirectoryEntryToData' as RtlImageDirectoryEntryToData:qword
            extrn '__imp_RtlInitializeRangeList' as RtlInitializeRangeList:qword
            extrn '__imp_RtlInsertElementGenericTableFull' as RtlInsertElementGenericTableFull:qword
            extrn '__imp_RtlInvertRangeList' as RtlInvertRangeList:qword
            extrn '__imp_RtlIsGenericTableEmpty' as RtlIsGenericTableEmpty:qword
            extrn '__imp_RtlIsRangeAvailable' as RtlIsRangeAvailable:qword
            extrn '__imp_RtlIsValidOemCharacter' as RtlIsValidOemCharacter:qword
            extrn '__imp_RtlLargeIntegerAdd' as RtlLargeIntegerAdd:qword
            extrn '__imp_RtlLookupElementGenericTableFull' as RtlLookupElementGenericTableFull:qword
            extrn '__imp_RtlMergeRangeLists' as RtlMergeRangeLists:qword
            extrn '__imp_RtlPrefetchMemoryNonTemporal' as RtlPrefetchMemoryNonTemporal:qword
            extrn '__imp_RtlRealPredecessor' as RtlRealPredecessor:qword
            extrn '__imp_RtlRealSuccessor' as RtlRealSuccessor:qword
            extrn '__imp_RtlSelfRelativeToAbsoluteSD' as RtlSelfRelativeToAbsoluteSD:qword
            extrn '__imp_RtlSelfRelativeToAbsoluteSD2' as RtlSelfRelativeToAbsoluteSD2:qword
            extrn '__imp_RtlSizeHeap' as RtlSizeHeap:qword
            extrn '__imp_RtlStringFromGUID' as RtlStringFromGUID:qword
            extrn '__imp_RtlSubtreePredecessor' as RtlSubtreePredecessor:qword
            extrn '__imp_RtlSubtreeSuccessor' as RtlSubtreeSuccessor:qword
            extrn '__imp_RtlTraceDatabaseAdd' as RtlTraceDatabaseAdd:qword
            extrn '__imp_RtlTraceDatabaseCreate' as RtlTraceDatabaseCreate:qword
            extrn '__imp_RtlTraceDatabaseDestroy' as RtlTraceDatabaseDestroy:qword
            extrn '__imp_RtlTraceDatabaseEnumerate' as RtlTraceDatabaseEnumerate:qword
            extrn '__imp_RtlTraceDatabaseFind' as RtlTraceDatabaseFind:qword
            extrn '__imp_RtlTraceDatabaseLock' as RtlTraceDatabaseLock:qword
            extrn '__imp_RtlTraceDatabaseUnlock' as RtlTraceDatabaseUnlock:qword
            extrn '__imp_RtlTraceDatabaseValidate' as RtlTraceDatabaseValidate:qword
            extrn '__imp_RtlValidRelativeSecurityDescriptor' as RtlValidRelativeSecurityDescriptor:qword
            extrn '__imp_RtlVolumeDeviceToDosName' as RtlVolumeDeviceToDosName:qword
            extrn '__imp_RtlWalkFrameChain' as RtlWalkFrameChain:qword
            extrn '__imp_SeAssignSecurityEx' as SeAssignSecurityEx:qword
            extrn '__imp_SeAuditHardLinkCreation' as SeAuditHardLinkCreation:qword
            extrn '__imp_SeAuditingHardLinkEvents' as SeAuditingHardLinkEvents:qword
            extrn '__imp_SeCreateClientSecurityFromSubjectContext' as SeCreateClientSecurityFromSubjectContext:qword
            extrn '__imp_SeImpersonateClientEx' as SeImpersonateClientEx:qword
            extrn '__imp_SeQueryInformationToken' as SeQueryInformationToken:qword
            extrn '__imp_SeQuerySessionIdToken' as SeQuerySessionIdToken:qword
            extrn '__imp_SeSetSecurityDescriptorInfoEx' as SeSetSecurityDescriptorInfoEx:qword
            extrn '__imp_SeTokenIsAdmin' as SeTokenIsAdmin:qword
            extrn '__imp_SeTokenIsRestricted' as SeTokenIsRestricted:qword
            extrn '__imp_VerSetConditionMask' as VerSetConditionMask:qword
            extrn '__imp_ZwAdjustPrivilegesToken' as ZwAdjustPrivilegesToken:qword
            extrn '__imp_ZwCancelIoFile' as ZwCancelIoFile:qword
            extrn '__imp_ZwCancelTimer' as ZwCancelTimer:qword
            extrn '__imp_ZwCreateTimer' as ZwCreateTimer:qword
            extrn '__imp_ZwFlushVirtualMemory' as ZwFlushVirtualMemory:qword
            extrn '__imp_ZwInitiatePowerAction' as ZwInitiatePowerAction:qword
            extrn '__imp_ZwOpenTimer' as ZwOpenTimer:qword
            extrn '__imp_ZwPowerInformation' as ZwPowerInformation:qword
            extrn '__imp_ZwQueryDefaultUILanguage' as ZwQueryDefaultUILanguage:qword
            extrn '__imp_ZwQueryDirectoryObject' as ZwQueryDirectoryObject:qword
            extrn '__imp_ZwQueryEaFile' as ZwQueryEaFile:qword
            extrn '__imp_ZwQueryInstallUILanguage' as ZwQueryInstallUILanguage:qword
            extrn '__imp_ZwRestoreKey' as ZwRestoreKey:qword
            extrn '__imp_ZwSetDefaultUILanguage' as ZwSetDefaultUILanguage:qword
            extrn '__imp_ZwSetEaFile' as ZwSetEaFile:qword
            extrn '__imp_ZwSetSecurityObject' as ZwSetSecurityObject:qword
            extrn '__imp_ZwSetTimer' as ZwSetTimer:qword
            extrn '__imp_ZwSetVolumeInformationFile' as ZwSetVolumeInformationFile:qword
            extrn '__imp__itow' as _itow:qword
        end if

        if (NTDDI_VERSION = NTDDI_WINXP | NTDDI_VERSION = NTDDI_VISTA)
            extrn '__imp__alldiv' as _alldiv:qword
            extrn '__imp__alldvrm' as _alldvrm:qword
            extrn '__imp__allmul' as _allmul:qword
            extrn '__imp__allrem' as _allrem:qword
            extrn '__imp__allshl' as _allshl:qword
            extrn '__imp__allshr' as _allshr:qword
            extrn '__imp__aulldiv' as _aulldiv:qword
            extrn '__imp__aulldvrm' as _aulldvrm:qword
            extrn '__imp__aullrem' as _aullrem:qword
            extrn '__imp__aullshr' as _aullshr:qword
            extrn '__imp__except_handler2' as _except_handler2:qword
            extrn '__imp__except_handler3' as _except_handler3:qword
            extrn '__imp__global_unwind2' as _global_unwind2:qword
            extrn '__imp__local_unwind2' as _local_unwind2:qword
            extrn '__imp_IoAssignDriveLetters' as IoAssignDriveLetters:qword
        end if

        if (NTDDI_VERSION >= NTDDI_WINXP)
            extrn '__imp_CcMdlWriteAbort' as CcMdlWriteAbort:qword
            extrn '__imp_CmRegisterCallback' as CmRegisterCallback:qword
            extrn '__imp_CmUnRegisterCallback' as CmUnRegisterCallback:qword
            extrn '__imp_DbgPrintEx' as DbgPrintEx:qword
            extrn '__imp_DbgPrintReturnControlC' as DbgPrintReturnControlC:qword
            extrn '__imp_DbgQueryDebugFilterState' as DbgQueryDebugFilterState:qword
            extrn '__imp_DbgSetDebugFilterState' as DbgSetDebugFilterState:qword
            extrn '__imp_ExAcquireRundownProtection' as ExAcquireRundownProtection:qword
            extrn '__imp_ExAcquireRundownProtectionEx' as ExAcquireRundownProtectionEx:qword
            extrn '__imp_ExAllocateFromPagedLookasideList' as ExAllocateFromPagedLookasideList:qword
            extrn '__imp_ExfAcquirePushLockExclusive' as ExfAcquirePushLockExclusive:qword
            extrn '__imp_ExfAcquirePushLockShared' as ExfAcquirePushLockShared:qword
            extrn '__imp_ExfReleasePushLock' as ExfReleasePushLock:qword
            extrn '__imp_ExGetCurrentProcessorCounts' as ExGetCurrentProcessorCounts:qword
            extrn '__imp_ExGetCurrentProcessorCpuUsage' as ExGetCurrentProcessorCpuUsage:qword
            extrn '__imp_ExInitializeRundownProtection' as ExInitializeRundownProtection:qword
            extrn '__imp_ExReInitializeRundownProtection' as ExReInitializeRundownProtection:qword
            extrn '__imp_ExReleaseRundownProtection' as ExReleaseRundownProtection:qword
            extrn '__imp_ExReleaseRundownProtectionEx' as ExReleaseRundownProtectionEx:qword
            extrn '__imp_ExRundownCompleted' as ExRundownCompleted:qword
            extrn '__imp_ExVerifySuite' as ExVerifySuite:qword
            extrn '__imp_ExWaitForRundownProtectionRelease' as ExWaitForRundownProtectionRelease:qword
            extrn '__imp_FsRtlAcquireFileExclusive' as FsRtlAcquireFileExclusive:qword
            extrn '__imp_FsRtlIncrementCcFastReadNotPossible' as FsRtlIncrementCcFastReadNotPossible:qword
            extrn '__imp_FsRtlIncrementCcFastReadNoWait' as FsRtlIncrementCcFastReadNoWait:qword
            extrn '__imp_FsRtlIncrementCcFastReadResourceMiss' as FsRtlIncrementCcFastReadResourceMiss:qword
            extrn '__imp_FsRtlIncrementCcFastReadWait' as FsRtlIncrementCcFastReadWait:qword
            extrn '__imp_HalExamineMBR' as HalExamineMBR:qword
            extrn '__imp_HeadlessDispatch' as HeadlessDispatch:qword
            extrn '__imp_InitializeSListHead' as InitializeSListHead:qword
            extrn '__imp_IoCreateDisk' as IoCreateDisk:qword
            extrn '__imp_IoCreateStreamFileObjectEx' as IoCreateStreamFileObjectEx:qword
            extrn '__imp_IoCsqInitialize' as IoCsqInitialize:qword
            extrn '__imp_IoCsqInsertIrp' as IoCsqInsertIrp:qword
            extrn '__imp_IoCsqRemoveIrp' as IoCsqRemoveIrp:qword
            extrn '__imp_IoCsqRemoveNextIrp' as IoCsqRemoveNextIrp:qword
            extrn '__imp_IoForwardAndCatchIrp' as IoForwardAndCatchIrp:qword
            extrn '__imp_IoForwardIrpSynchronously' as IoForwardIrpSynchronously:qword
            extrn '__imp_IoFreeErrorLogEntry' as IoFreeErrorLogEntry:qword
            extrn '__imp_IoQueryFileDosDeviceName' as IoQueryFileDosDeviceName:qword
            extrn '__imp_IoReadDiskSignature' as IoReadDiskSignature:qword
            extrn '__imp_IoReadPartitionTable' as IoReadPartitionTable:qword
            extrn '__imp_IoReadPartitionTableEx' as IoReadPartitionTableEx:qword
            extrn '__imp_IoSetCompletionRoutineEx' as IoSetCompletionRoutineEx:qword
            extrn '__imp_IoSetPartitionInformation' as IoSetPartitionInformation:qword
            extrn '__imp_IoSetPartitionInformationEx' as IoSetPartitionInformationEx:qword
            extrn '__imp_IoSetStartIoAttributes' as IoSetStartIoAttributes:qword
            extrn '__imp_IoSetSystemPartition' as IoSetSystemPartition:qword
            extrn '__imp_IoValidateDeviceIoControlAccess' as IoValidateDeviceIoControlAccess:qword
            extrn '__imp_IoVerifyPartitionTable' as IoVerifyPartitionTable:qword
            extrn '__imp_IoWMIDeviceObjectToInstanceName' as IoWMIDeviceObjectToInstanceName:qword
            extrn '__imp_IoWMIExecuteMethod' as IoWMIExecuteMethod:qword
            extrn '__imp_IoWMIHandleToInstanceName' as IoWMIHandleToInstanceName:qword
            extrn '__imp_IoWMIOpenBlock' as IoWMIOpenBlock:qword
            extrn '__imp_IoWMIQueryAllData' as IoWMIQueryAllData:qword
            extrn '__imp_IoWMIQueryAllDataMultiple' as IoWMIQueryAllDataMultiple:qword
            extrn '__imp_IoWMIQuerySingleInstance' as IoWMIQuerySingleInstance:qword
            extrn '__imp_IoWMIQuerySingleInstanceMultiple' as IoWMIQuerySingleInstanceMultiple:qword
            extrn '__imp_IoWMISetNotificationCallback' as IoWMISetNotificationCallback:qword
            extrn '__imp_IoWMISetSingleInstance' as IoWMISetSingleInstance:qword
            extrn '__imp_IoWMISetSingleItem' as IoWMISetSingleItem:qword
            extrn '__imp_IoWritePartitionTable' as IoWritePartitionTable:qword
            extrn '__imp_IoWritePartitionTableEx' as IoWritePartitionTableEx:qword
            extrn '__imp_KdPowerTransition' as KdPowerTransition:qword
            extrn '__imp_KeAcquireInStackQueuedSpinLockAtDpcLevel' as KeAcquireInStackQueuedSpinLockAtDpcLevel:qword
            extrn '__imp_KeAcquireInterruptSpinLock' as KeAcquireInterruptSpinLock:qword
            extrn '__imp_KeAreApcsDisabled' as KeAreApcsDisabled:qword
            extrn '__imp_KeCapturePersistentThreadState' as KeCapturePersistentThreadState:qword
            extrn '__imp_KeDeregisterBugCheckReasonCallback' as KeDeregisterBugCheckReasonCallback:qword
            extrn '__imp_KeFlushQueuedDpcs' as KeFlushQueuedDpcs:qword
            extrn '__imp_KeGetRecommendedSharedDataAlignment' as KeGetRecommendedSharedDataAlignment:qword
            extrn '__imp_KeIsAttachedProcess' as KeIsAttachedProcess:qword
            extrn '__imp_KeQueryRuntimeThread' as KeQueryRuntimeThread:qword
            extrn '__imp_KeRegisterBugCheckReasonCallback' as KeRegisterBugCheckReasonCallback:qword
            extrn '__imp_KeReleaseInterruptSpinLock' as KeReleaseInterruptSpinLock:qword
            extrn '__imp_KeRemoveByKeyDeviceQueueIfBusy' as KeRemoveByKeyDeviceQueueIfBusy:qword
            extrn '__imp_KeRemoveSystemServiceTable' as KeRemoveSystemServiceTable:qword
            extrn '__imp_KeRestoreExtendedProcessorState' as KeRestoreExtendedProcessorState:qword
            extrn '__imp_KeRevertToUserAffinityThreadEx' as KeRevertToUserAffinityThreadEx:qword
            extrn '__imp_MmAdvanceMdl' as MmAdvanceMdl:qword
            extrn '__imp_MmMarkPhysicalMemoryAsBad' as MmMarkPhysicalMemoryAsBad:qword
            extrn '__imp_MmMarkPhysicalMemoryAsGood' as MmMarkPhysicalMemoryAsGood:qword
            extrn '__imp_MmPrefetchPages' as MmPrefetchPages:qword
            extrn '__imp_MmProtectMdlSystemAddress' as MmProtectMdlSystemAddress:qword
            extrn '__imp_NtMakePermanentObject' as NtMakePermanentObject:qword
            extrn '__imp_NtOpenProcessTokenEx' as NtOpenProcessTokenEx:qword
            extrn '__imp_NtOpenThread' as NtOpenThread:qword
            extrn '__imp_NtOpenThreadToken' as NtOpenThreadToken:qword
            extrn '__imp_NtOpenThreadTokenEx' as NtOpenThreadTokenEx:qword
            extrn '__imp_NtQueryInformationThread' as NtQueryInformationThread:qword
            extrn '__imp_NtShutdownSystem' as NtShutdownSystem:qword
            extrn '__imp_NtTraceEvent' as NtTraceEvent:qword
            extrn '__imp_ObCloseHandle' as ObCloseHandle:qword
            extrn '__imp_ObIsDosDeviceLocallyMapped' as ObIsDosDeviceLocallyMapped:qword
            extrn '__imp_ObLogSecurityDescriptor' as ObLogSecurityDescriptor:qword
            extrn '__imp_ObReferenceSecurityDescriptor' as ObReferenceSecurityDescriptor:qword
            extrn '__imp_ObSetHandleAttributes' as ObSetHandleAttributes:qword
            extrn '__imp_ObSetSecurityObjectByPointer' as ObSetSecurityObjectByPointer:qword
            extrn '__imp_PoRequestShutdownEvent' as PoRequestShutdownEvent:qword
            extrn '__imp_PsChargeProcessNonPagedPoolQuota' as PsChargeProcessNonPagedPoolQuota:qword
            extrn '__imp_PsChargeProcessPagedPoolQuota' as PsChargeProcessPagedPoolQuota:qword
            extrn '__imp_PsChargeProcessPoolQuota' as PsChargeProcessPoolQuota:qword
            if (NTDDI_VERSION < NTDDI_VISTA)
                extrn '__imp_PsCreateSystemProcess' as PsCreateSystemProcess:qword
            end if
            extrn '__imp_PsDereferenceImpersonationToken' as PsDereferenceImpersonationToken:qword
            extrn '__imp_PsDereferencePrimaryToken' as PsDereferencePrimaryToken:qword
            extrn '__imp_PsGetContextThread' as PsGetContextThread:qword
            extrn '__imp_PsGetCurrentProcess' as PsGetCurrentProcess:qword
            extrn '__imp_PsGetCurrentProcessSessionId' as PsGetCurrentProcessSessionId:qword
            extrn '__imp_PsGetCurrentThread' as PsGetCurrentThread:qword
            extrn '__imp_PsGetCurrentThreadPreviousMode' as PsGetCurrentThreadPreviousMode:qword
            extrn '__imp_PsGetCurrentThreadStackBase' as PsGetCurrentThreadStackBase:qword
            extrn '__imp_PsGetCurrentThreadStackLimit' as PsGetCurrentThreadStackLimit:qword
            extrn '__imp_PsGetJobLock' as PsGetJobLock:qword
            extrn '__imp_PsGetJobSessionId' as PsGetJobSessionId:qword
            extrn '__imp_PsGetJobUIRestrictionsClass' as PsGetJobUIRestrictionsClass:qword
            extrn '__imp_PsGetProcessCreateTimeQuadPart' as PsGetProcessCreateTimeQuadPart:qword
            extrn '__imp_PsGetProcessDebugPort' as PsGetProcessDebugPort:qword
            extrn '__imp_PsGetProcessExitProcessCalled' as PsGetProcessExitProcessCalled:qword
            extrn '__imp_PsGetProcessExitStatus' as PsGetProcessExitStatus:qword
            extrn '__imp_PsGetProcessInheritedFromUniqueProcessId' as PsGetProcessInheritedFromUniqueProcessId:qword
            extrn '__imp_PsGetProcessJob' as PsGetProcessJob:qword
            extrn '__imp_PsGetProcessPeb' as PsGetProcessPeb:qword
            extrn '__imp_PsGetProcessPriorityClass' as PsGetProcessPriorityClass:qword
            extrn '__imp_PsGetProcessSectionBaseAddress' as PsGetProcessSectionBaseAddress:qword
            extrn '__imp_PsGetProcessSecurityPort' as PsGetProcessSecurityPort:qword
            extrn '__imp_PsGetProcessSessionId' as PsGetProcessSessionId:qword
            extrn '__imp_PsGetProcessWin32Process' as PsGetProcessWin32Process:qword
            extrn '__imp_PsGetProcessWin32WindowStation' as PsGetProcessWin32WindowStation:qword
            extrn '__imp_PsGetThreadFreezeCount' as PsGetThreadFreezeCount:qword
            extrn '__imp_PsGetThreadHardErrorsAreDisabled' as PsGetThreadHardErrorsAreDisabled:qword
            extrn '__imp_PsGetThreadId' as PsGetThreadId:qword
            extrn '__imp_PsGetThreadProcess' as PsGetThreadProcess:qword
            extrn '__imp_PsGetThreadProcessId' as PsGetThreadProcessId:qword
            extrn '__imp_PsGetThreadSessionId' as PsGetThreadSessionId:qword
            extrn '__imp_PsGetThreadTeb' as PsGetThreadTeb:qword
            extrn '__imp_PsGetThreadWin32Thread' as PsGetThreadWin32Thread:qword
            extrn '__imp_PsIsProcessBeingDebugged' as PsIsProcessBeingDebugged:qword
            extrn '__imp_PsIsSystemThread' as PsIsSystemThread:qword
            extrn '__imp_PsIsThreadImpersonating' as PsIsThreadImpersonating:qword
            extrn '__imp_PsRemoveCreateThreadNotifyRoutine' as PsRemoveCreateThreadNotifyRoutine:qword
            extrn '__imp_PsRemoveLoadImageNotifyRoutine' as PsRemoveLoadImageNotifyRoutine:qword
            extrn '__imp_PsReturnProcessNonPagedPoolQuota' as PsReturnProcessNonPagedPoolQuota:qword
            extrn '__imp_PsReturnProcessPagedPoolQuota' as PsReturnProcessPagedPoolQuota:qword
            extrn '__imp_PsRevertThreadToSelf' as PsRevertThreadToSelf:qword
            extrn '__imp_PsSetContextThread' as PsSetContextThread:qword
            if (NTDDI_VERSION = NTDDI_WINXP)
                extrn '__imp_WmiFlushTrace' as WmiFlushTrace:qword
                extrn '__imp_WmiQueryTrace' as WmiQueryTrace:qword
                extrn '__imp_WmiStartTrace' as WmiStartTrace:qword
                extrn '__imp_WmiStopTrace' as WmiStopTrace:qword
                extrn '__imp_WmiUpdateTrace' as WmiUpdateTrace:qword
            else if (NTDDI_VERSION < NTDDI_WIN8)
                extrn '__imp_PsSetJobUIRestrictionsClass' as PsSetJobUIRestrictionsClass:qword
            end if
            extrn '__imp_PsSetProcessPriorityClass' as PsSetProcessPriorityClass:qword
            extrn '__imp_PsSetProcessSecurityPort' as PsSetProcessSecurityPort:qword
            extrn '__imp_PsSetProcessWin32Process' as PsSetProcessWin32Process:qword
            extrn '__imp_PsSetProcessWindowStation' as PsSetProcessWindowStation:qword
            extrn '__imp_PsSetThreadHardErrorsAreDisabled' as PsSetThreadHardErrorsAreDisabled:qword
            extrn '__imp_PsSetThreadWin32Thread' as PsSetThreadWin32Thread:qword
            extrn '__imp_RtlClearBit' as RtlClearBit:qword
            extrn '__imp_RtlCreateSystemVolumeInformationFolder' as RtlCreateSystemVolumeInformationFolder:qword
            extrn '__imp_RtlDeleteElementGenericTableAvl' as RtlDeleteElementGenericTableAvl:qword
            extrn '__imp_RtlEnumerateGenericTableAvl' as RtlEnumerateGenericTableAvl:qword
            extrn '__imp_RtlEnumerateGenericTableLikeADirectory' as RtlEnumerateGenericTableLikeADirectory:qword
            extrn '__imp_RtlEnumerateGenericTableWithoutSplayingAvl' as RtlEnumerateGenericTableWithoutSplayingAvl:qword
            extrn '__imp_RtlGetElementGenericTableAvl' as RtlGetElementGenericTableAvl:qword
            extrn '__imp_RtlGetSetBootStatusData' as RtlGetSetBootStatusData:qword
            extrn '__imp_RtlGetVersion' as RtlGetVersion:qword
            extrn '__imp_RtlHashUnicodeString' as RtlHashUnicodeString:qword
            extrn '__imp_RtlInitializeGenericTableAvl' as RtlInitializeGenericTableAvl:qword
            extrn '__imp_RtlInsertElementGenericTableAvl' as RtlInsertElementGenericTableAvl:qword
            extrn '__imp_RtlInsertElementGenericTableFullAvl' as RtlInsertElementGenericTableFullAvl:qword
            extrn '__imp_RtlInt64ToUnicodeString' as RtlInt64ToUnicodeString:qword
            extrn '__imp_RtlIntegerToUnicode' as RtlIntegerToUnicode:qword
            extrn '__imp_RtlIpv4AddressToStringA' as RtlIpv4AddressToStringA:qword
            extrn '__imp_RtlIpv4AddressToStringExA' as RtlIpv4AddressToStringExA:qword
            extrn '__imp_RtlIpv4AddressToStringExW' as RtlIpv4AddressToStringExW:qword
            extrn '__imp_RtlIpv4AddressToStringW' as RtlIpv4AddressToStringW:qword
            extrn '__imp_RtlIpv4StringToAddressA' as RtlIpv4StringToAddressA:qword
            extrn '__imp_RtlIpv4StringToAddressExA' as RtlIpv4StringToAddressExA:qword
            extrn '__imp_RtlIpv4StringToAddressExW' as RtlIpv4StringToAddressExW:qword
            extrn '__imp_RtlIpv4StringToAddressW' as RtlIpv4StringToAddressW:qword
            extrn '__imp_RtlIpv6AddressToStringA' as RtlIpv6AddressToStringA:qword
            extrn '__imp_RtlIpv6AddressToStringExA' as RtlIpv6AddressToStringExA:qword
            extrn '__imp_RtlIpv6AddressToStringExW' as RtlIpv6AddressToStringExW:qword
            extrn '__imp_RtlIpv6AddressToStringW' as RtlIpv6AddressToStringW:qword
            extrn '__imp_RtlIpv6StringToAddressA' as RtlIpv6StringToAddressA:qword
            extrn '__imp_RtlIpv6StringToAddressExA' as RtlIpv6StringToAddressExA:qword
            extrn '__imp_RtlIpv6StringToAddressExW' as RtlIpv6StringToAddressExW:qword
            extrn '__imp_RtlIpv6StringToAddressW' as RtlIpv6StringToAddressW:qword
            extrn '__imp_RtlIsGenericTableEmptyAvl' as RtlIsGenericTableEmptyAvl:qword
            extrn '__imp_RtlLockBootStatusData' as RtlLockBootStatusData:qword
            extrn '__imp_RtlLookupElementGenericTableAvl' as RtlLookupElementGenericTableAvl:qword
            extrn '__imp_RtlLookupElementGenericTableFullAvl' as RtlLookupElementGenericTableFullAvl:qword
            extrn '__imp_RtlMapSecurityErrorToNtStatus' as RtlMapSecurityErrorToNtStatus:qword
            extrn '__imp_RtlNumberGenericTableElementsAvl' as RtlNumberGenericTableElementsAvl:qword
            extrn '__imp_RtlRandomEx' as RtlRandomEx:qword
            extrn '__imp_RtlSetBit' as RtlSetBit:qword
            extrn '__imp_RtlTestBit' as RtlTestBit:qword
            extrn '__imp_RtlTimeToElapsedTimeFields' as RtlTimeToElapsedTimeFields:qword
            extrn '__imp_RtlVerifyVersionInfo' as RtlVerifyVersionInfo:qword
            extrn '__imp_SeAuditingHardLinkEventsWithContext' as SeAuditingHardLinkEventsWithContext:qword
            extrn '__imp_SeReportSecurityEvent' as SeAuditingHardLinkEventsWithContext:qword
            extrn '__imp_SeTokenIsWriteRestricted' as SeTokenIsWriteRestricted:qword
            extrn '__imp_SeTokenObjectType' as SeTokenObjectType:qword
            extrn '__imp_vDbgPrintEx' as vDbgPrintEx:qword
            extrn '__imp_vDbgPrintExWithPrefix' as vDbgPrintExWithPrefix:qword
            extrn '__imp_VfIsVerificationEnabled' as VfIsVerificationEnabled:qword
            extrn '__imp_WmiGetClock' as WmiGetClock:qword
            extrn '__imp_WmiQueryTraceInformation' as WmiQueryTraceInformation:qword
            extrn '__imp_WmiTraceMessage' as WmiTraceMessage:qword
            extrn '__imp_WmiTraceMessageVa' as WmiTraceMessageVa:qword
            extrn '__imp_WRITE_REGISTER_BUFFER_UCHAR' as WRITE_REGISTER_BUFFER_UCHAR:qword
            extrn '__imp_WRITE_REGISTER_BUFFER_ULONG' as WRITE_REGISTER_BUFFER_ULONG:qword
            extrn '__imp_WRITE_REGISTER_BUFFER_USHORT' as WRITE_REGISTER_BUFFER_USHORT:qword
            extrn '__imp_WRITE_REGISTER_UCHAR' as WRITE_REGISTER_UCHAR:qword
            extrn '__imp_WRITE_REGISTER_ULONG' as WRITE_REGISTER_ULONG:qword
            extrn '__imp_WRITE_REGISTER_USHORT' as WRITE_REGISTER_USHORT:qword
            extrn '__imp_XIPDispatch' as XIPDispatch:qword
            extrn '__imp_ZwAddBootEntry' as ZwAddBootEntry:qword
            extrn '__imp_ZwAssignProcessToJobObject' as ZwAssignProcessToJobObject:qword
            extrn '__imp_ZwCreateJobObject' as ZwCreateJobObject:qword
            extrn '__imp_ZwDeleteBootEntry' as ZwDeleteBootEntry:qword
            extrn '__imp_ZwEnumerateBootEntries' as ZwEnumerateBootEntries:qword
            extrn '__imp_ZwIsProcessInJob' as ZwIsProcessInJob:qword
            extrn '__imp_ZwOpenJobObject' as ZwOpenJobObject:qword
            extrn '__imp_ZwOpenProcessTokenEx' as ZwOpenProcessTokenEx:qword
            extrn '__imp_ZwOpenThreadTokenEx' as ZwOpenThreadTokenEx:qword
            extrn '__imp_ZwQueryBootEntryOrder' as ZwQueryBootEntryOrder:qword
            extrn '__imp_ZwQueryBootOptions' as ZwQueryBootOptions:qword
            extrn '__imp_ZwQueryFullAttributesFile' as ZwQueryFullAttributesFile:qword
            extrn '__imp_ZwQueryInformationJobObject' as ZwQueryInformationJobObject:qword
            extrn '__imp_ZwQueryInformationThread' as ZwQueryInformationThread:qword
            extrn '__imp_ZwSaveKeyEx' as ZwSaveKeyEx:qword
            extrn '__imp_ZwSetBootEntryOrder' as ZwSetBootEntryOrder:qword
            extrn '__imp_ZwSetBootOptions' as ZwSetBootOptions:qword
            extrn '__imp_ZwSetInformationJobObject' as ZwSetInformationJobObject:qword
            extrn '__imp_ZwTerminateJobObject' as ZwTerminateJobObject:qword
            extrn '__imp_ZwTranslateFilePath' as ZwTranslateFilePath:qword
            extrn '__imp__vsnwprintf' as _vsnwprintf:qword

            api RtlIpv4AddressToString,\
                RtlIpv4AddressToStringEx,\
                RtlIpv4StringToAddress,\
                RtlIpv4StringToAddressEx,\
                RtlIpv6AddressToString,\
                RtlIpv6AddressToStringEx,\
                RtlIpv6StringToAddress,\
                RtlIpv6StringToAddressEx
        end if

        if (NTDDI_VERSION >= NTDDI_VISTA)
            extrn '__imp_AlpcGetHeaderSize' as AlpcGetHeaderSize:qword
            extrn '__imp_AlpcGetMessageAttribute' as AlpcGetMessageAttribute:qword
            extrn '__imp_AlpcInitializeMessageAttribute' as AlpcInitializeMessageAttribute:qword
            extrn '__imp_bsearch' as bsearch:qword
            extrn '__imp_CcGetFileObjectFromSectionPtrsRef' as CcGetFileObjectFromSectionPtrsRef:qword
            extrn '__imp_CcIsThereDirtyDataEx' as CcIsThereDirtyDataEx:qword
            extrn '__imp_CcSetFileSizesEx' as CcSetFileSizesEx:qword
            extrn '__imp_CcSetParallelFlushFile' as CcSetParallelFlushFile:qword
            extrn '__imp_CmCallbackGetKeyObjectID' as CmCallbackGetKeyObjectID:qword
            extrn '__imp_CmGetBoundTransaction' as CmGetBoundTransaction:qword
            extrn '__imp_CmGetCallbackVersion' as CmGetCallbackVersion:qword
            extrn '__imp_CmRegisterCallbackEx' as CmRegisterCallbackEx:qword
            extrn '__imp_CmSetCallbackObjectContext' as CmSetCallbackObjectContext:qword
            extrn '__imp_DbgCommandString' as DbgCommandString:qword
            extrn '__imp_DbgSetDebugPrintCallback' as DbgSetDebugPrintCallback:qword
            extrn '__imp_EmClientQueryRuleState' as EmClientQueryRuleState:qword
            extrn '__imp_EtwActivityIdControl' as EtwActivityIdControl:qword
            extrn '__imp_EtwEventEnabled' as EtwEventEnabled:qword
            extrn '__imp_EtwProviderEnabled' as EtwProviderEnabled:qword
            extrn '__imp_EtwRegister' as EtwRegister:qword
            extrn '__imp_EtwUnregister' as EtwUnregister:qword
            extrn '__imp_EtwWrite' as EtwWrite:qword
            extrn '__imp_EtwWriteString' as EtwWriteString:qword
            extrn '__imp_EtwWriteTransfer' as EtwWriteTransfer:qword
            extrn '__imp_ExAcquireSpinLockExclusive' as ExAcquireSpinLockExclusive:qword
            extrn '__imp_ExAcquireSpinLockExclusiveAtDpcLevel' as ExAcquireSpinLockExclusiveAtDpcLevel:qword
            extrn '__imp_ExAcquireSpinLockShared' as ExAcquireSpinLockShared:qword
            extrn '__imp_ExAcquireSpinLockSharedAtDpcLevel' as ExAcquireSpinLockSharedAtDpcLevel:qword
            extrn '__imp_ExAllocateCacheAwarePushLock' as ExAllocateCacheAwarePushLock:qword
            extrn '__imp_ExAllocateCacheAwareRundownProtection' as ExAllocateCacheAwareRundownProtection:qword
            extrn '__imp_ExDeleteLookasideListEx' as ExDeleteLookasideListEx:qword
            extrn '__imp_ExEnterCriticalRegionAndAcquireFastMutexUnsafe' as ExEnterCriticalRegionAndAcquireFastMutexUnsafe:qword
            extrn '__imp_ExEnterCriticalRegionAndAcquireResourceExclusive' as ExEnterCriticalRegionAndAcquireResourceExclusive:qword
            extrn '__imp_ExEnterCriticalRegionAndAcquireResourceShared' as ExEnterCriticalRegionAndAcquireResourceShared:qword
            extrn '__imp_ExEnterCriticalRegionAndAcquireSharedWaitForExclusive' as ExEnterCriticalRegionAndAcquireSharedWaitForExclusive:qword
            extrn '__imp_ExFlushLookasideListEx' as ExFlushLookasideListEx:qword
            extrn '__imp_ExFreeCacheAwarePushLock' as ExFreeCacheAwarePushLock:qword
            extrn '__imp_ExfReleasePushLockExclusive' as ExfReleasePushLockExclusive:qword
            extrn '__imp_ExfReleasePushLockShared' as ExfReleasePushLockShared:qword
            extrn '__imp_ExfTryToWakePushLock' as ExfTryToWakePushLock:qword
            extrn '__imp_ExfUnblockPushLock' as ExfUnblockPushLock:qword
            extrn '__imp_ExInitializeLookasideListEx' as ExInitializeLookasideListEx:qword
            extrn '__imp_ExInitializePushLock' as ExInitializePushLock:qword
            extrn '__imp_ExInitializeRundownProtectionCacheAware' as ExInitializeRundownProtectionCacheAware:qword
            extrn '__imp_ExReInitializeRundownProtectionCacheAware' as ExReInitializeRundownProtectionCacheAware:qword
            extrn '__imp_ExReleaseCacheAwarePushLockExclusive' as ExReleaseCacheAwarePushLockExclusive:qword
            extrn '__imp_ExReleaseFastMutexUnsafeAndLeaveCriticalRegion' as ExReleaseFastMutexUnsafeAndLeaveCriticalRegion:qword
            extrn '__imp_ExReleaseResourceAndLeaveCriticalRegion' as ExReleaseResourceAndLeaveCriticalRegion:qword
            extrn '__imp_ExReleaseRundownProtectionCacheAware' as ExReleaseRundownProtectionCacheAware:qword
            extrn '__imp_ExReleaseRundownProtectionCacheAwareEx' as ExReleaseRundownProtectionCacheAwareEx:qword
            extrn '__imp_ExReleaseSpinLockExclusive' as ExReleaseSpinLockExclusive:qword
            extrn '__imp_ExReleaseSpinLockExclusiveFromDpcLevel' as ExReleaseSpinLockExclusiveFromDpcLevel:qword
            extrn '__imp_ExReleaseSpinLockShared' as ExReleaseSpinLockShared:qword
            extrn '__imp_ExReleaseSpinLockSharedFromDpcLevel' as ExReleaseSpinLockSharedFromDpcLevel:qword
            extrn '__imp_ExRundownCompletedCacheAware' as ExRundownCompletedCacheAware:qword
            extrn '__imp_ExSetLicenseTamperState' as ExSetLicenseTamperState:qword
            extrn '__imp_ExTryConvertSharedSpinLockExclusive' as ExTryConvertSharedSpinLockExclusive:qword
            extrn '__imp_FirstEntrySList' as FirstEntrySList:qword
            extrn '__imp_FsRtlAcknowledgeEcp' as FsRtlAcknowledgeEcp:qword
            extrn '__imp_FsRtlAddBaseMcbEntry' as FsRtlAddBaseMcbEntry:qword
            extrn '__imp_FsRtlAddBaseMcbEntryEx' as FsRtlAddBaseMcbEntryEx:qword
            extrn '__imp_FsRtlAllocateExtraCreateParameter' as FsRtlAllocateExtraCreateParameter:qword
            extrn '__imp_FsRtlAllocateExtraCreateParameterFromLookasideList' as FsRtlAllocateExtraCreateParameterFromLookasideList:qword
            extrn '__imp_FsRtlAllocateExtraCreateParameterList' as FsRtlAllocateExtraCreateParameterList:qword
            extrn '__imp_FsRtlAreVolumeStartupApplicationsComplete' as FsRtlAreVolumeStartupApplicationsComplete:qword
            extrn '__imp_FsRtlCancellableWaitForMultipleObjects' as FsRtlCancellableWaitForMultipleObjects:qword
            extrn '__imp_FsRtlCancellableWaitForSingleObject' as FsRtlCancellableWaitForSingleObject:qword
            extrn '__imp_FsRtlChangeBackingFileObject' as FsRtlChangeBackingFileObject:qword
            extrn '__imp_FsRtlCheckOplockEx' as FsRtlCheckOplockEx:qword
            extrn '__imp_FsRtlCurrentOplock' as FsRtlCurrentOplock:qword
            extrn '__imp_FsRtlDeleteExtraCreateParameterLookasideList' as FsRtlDeleteExtraCreateParameterLookasideList:qword
            extrn '__imp_FsRtlFindExtraCreateParameter' as FsRtlFindExtraCreateParameter:qword
            extrn '__imp_FsRtlFreeExtraCreateParameter' as FsRtlFreeExtraCreateParameter:qword
            extrn '__imp_FsRtlFreeExtraCreateParameterList' as FsRtlFreeExtraCreateParameterList:qword
            extrn '__imp_FsRtlGetEcpListFromIrp' as FsRtlGetEcpListFromIrp:qword
            extrn '__imp_FsRtlGetNextBaseMcbEntry' as FsRtlGetNextBaseMcbEntry:qword
            extrn '__imp_FsRtlGetNextExtraCreateParameter' as FsRtlGetNextExtraCreateParameter:qword
            extrn '__imp_FsRtlIncrementCcFastMdlReadWait' as FsRtlIncrementCcFastMdlReadWait:qword
            extrn '__imp_FsRtlInitExtraCreateParameterLookasideList' as FsRtlInitExtraCreateParameterLookasideList:qword
            extrn '__imp_FsRtlInitializeExtraCreateParameter' as FsRtlInitializeExtraCreateParameter:qword
            extrn '__imp_FsRtlInitializeExtraCreateParameterList' as FsRtlInitializeExtraCreateParameterList:qword
            extrn '__imp_FsRtlInsertExtraCreateParameter' as FsRtlInsertExtraCreateParameter:qword
            extrn '__imp_FsRtlInsertPerFileContext' as FsRtlInsertPerFileContext:qword
            extrn '__imp_FsRtlIsEcpAcknowledged' as FsRtlIsEcpAcknowledged:qword
            extrn '__imp_FsRtlIsEcpFromUserMode' as FsRtlIsEcpFromUserMode:qword
            extrn '__imp_FsRtlLogCcFlushError' as FsRtlLogCcFlushError:qword
            extrn '__imp_FsRtlLookupBaseMcbEntry' as FsRtlLookupBaseMcbEntry:qword
            extrn '__imp_FsRtlLookupLastBaseMcbEntryAndIndex' as FsRtlLookupLastBaseMcbEntryAndIndex:qword
            extrn '__imp_FsRtlLookupPerFileContext' as FsRtlLookupPerFileContext:qword
            extrn '__imp_FsRtlMupGetProviderIdFromName' as FsRtlMupGetProviderIdFromName:qword
            extrn '__imp_FsRtlMupGetProviderInfoFromFileObject' as FsRtlMupGetProviderInfoFromFileObject:qword
            extrn '__imp_FsRtlNotifyCleanupAll' as FsRtlNotifyCleanupAll:qword
            extrn '__imp_FsRtlNotifyVolumeEventEx' as FsRtlNotifyVolumeEventEx:qword
            extrn '__imp_FsRtlOplockBreakToNone' as FsRtlOplockBreakToNone:qword
            extrn '__imp_FsRtlPrepareToReuseEcp' as FsRtlPrepareToReuseEcp:qword
            extrn '__imp_FsRtlRegisterUncProviderEx' as FsRtlRegisterUncProviderEx:qword
            extrn '__imp_FsRtlRemoveBaseMcbEntry' as FsRtlRemoveBaseMcbEntry:qword
            extrn '__imp_FsRtlRemoveDotsFromPath' as FsRtlRemoveDotsFromPath:qword
            extrn '__imp_FsRtlRemoveExtraCreateParameter' as FsRtlRemoveExtraCreateParameter:qword
            extrn '__imp_FsRtlRemovePerFileContext' as FsRtlRemovePerFileContext:qword
            extrn '__imp_FsRtlSetEcpListIntoIrp' as FsRtlSetEcpListIntoIrp:qword
            extrn '__imp_FsRtlSplitBaseMcb' as FsRtlSplitBaseMcb:qword
            extrn '__imp_FsRtlTeardownPerFileContexts' as FsRtlTeardownPerFileContexts:qword
            extrn '__imp_FsRtlTruncateBaseMcb' as FsRtlTruncateBaseMcb:qword
            extrn '__imp_FsRtlUninitializeBaseMcb' as FsRtlUninitializeBaseMcb:qword
            extrn '__imp_FsRtlValidateReparsePointBuffer' as FsRtlValidateReparsePointBuffer:qword
            extrn '__imp_InterlockedPushListSList' as InterlockedPushListSList:qword
            extrn '__imp_IoAllocateMiniCompletionPacket' as IoAllocateMiniCompletionPacket:qword
            extrn '__imp_IoAllocateSfioStreamIdentifier' as IoAllocateSfioStreamIdentifier:qword
            extrn '__imp_IoCheckShareAccessEx' as IoCheckShareAccessEx:qword
            extrn '__imp_IoClearIrpExtraCreateParameter' as IoClearIrpExtraCreateParameter:qword
            extrn '__imp_IoConnectInterruptEx' as IoConnectInterruptEx:qword
            extrn '__imp_IoCreateFileEx' as IoCreateFileEx:qword
            extrn '__imp_IoCsqInitializeEx' as IoCsqInitializeEx:qword
            extrn '__imp_IoCsqInsertIrpEx' as IoCsqInsertIrpEx:qword
            extrn '__imp_IoDisconnectInterruptEx' as IoDisconnectInterruptEx:qword
            extrn '__imp_IoFreeSfioStreamIdentifier' as IoFreeSfioStreamIdentifier:qword
            extrn '__imp_IoGetBootDiskInformationLite' as IoGetBootDiskInformationLite:qword
            extrn '__imp_IoGetDevicePropertyData' as IoGetDevicePropertyData:qword
            extrn '__imp_IoGetIoPriorityHint' as IoGetIoPriorityHint:qword
            extrn '__imp_IoGetIrpExtraCreateParameter' as IoGetIrpExtraCreateParameter:qword
            extrn '__imp_IoGetPagingIoPriority' as IoGetPagingIoPriority:qword
            extrn '__imp_IoGetSfioStreamIdentifier' as IoGetSfioStreamIdentifier:qword
            extrn '__imp_IoGetTransactionParameterBlock' as IoGetTransactionParameterBlock:qword
            extrn '__imp_IoInitializeWorkItem' as IoInitializeWorkItem:qword
            extrn '__imp_IoIsFileObjectIgnoringSharing' as IoIsFileObjectIgnoringSharing:qword
            extrn '__imp_IoQueueWorkItemEx' as IoQueueWorkItemEx:qword
            extrn '__imp_IoReplacePartitionUnit' as IoReplacePartitionUnit:qword
            extrn '__imp_IoSetDevicePropertyData' as IoSetDevicePropertyData:qword
            extrn '__imp_IoSetIoPriorityHint' as IoSetIoPriorityHint:qword
            extrn '__imp_IoSetIrpExtraCreateParameter' as IoSetIrpExtraCreateParameter:qword
            extrn '__imp_IoSetShareAccessEx' as IoSetShareAccessEx:qword
            extrn '__imp_IoSizeofWorkItem' as IoSizeofWorkItem:qword
            extrn '__imp_IoTranslateBusAddress' as IoTranslateBusAddress:qword
            extrn '__imp_IoUninitializeWorkItem' as IoUninitializeWorkItem:qword
            extrn '__imp_IoWithinStackLimits' as IoWithinStackLimits:qword
            extrn '__imp_KdRefreshDebuggerNotPresent' as KdRefreshDebuggerNotPresent:qword
            extrn '__imp_KdSystemDebugControl' as KdSystemDebugControl:qword
            extrn '__imp_KeAcquireGuardedMutex' as KeAcquireGuardedMutex:qword
            extrn '__imp_KeAcquireGuardedMutexUnsafe' as KeAcquireGuardedMutexUnsafe:qword
            extrn '__imp_KeAcquireInStackQueuedSpinLockForDpc' as KeAcquireInStackQueuedSpinLockForDpc:qword
            extrn '__imp_KeAcquireSpinLockForDpc' as KeAcquireSpinLockForDpc:qword
            extrn '__imp_KeAlertThread' as KeAlertThread:qword
            extrn '__imp_KeAreAllApcsDisabled' as KeAreAllApcsDisabled:qword
            extrn '__imp_KeDeregisterNmiCallback' as KeDeregisterNmiCallback:qword
            extrn '__imp_KeDeregisterProcessorChangeCallback' as KeDeregisterProcessorChangeCallback:qword
            extrn '__imp_KeEnterGuardedRegion' as KeEnterGuardedRegion:qword
            extrn '__imp_KeExpandKernelStackAndCallout' as KeExpandKernelStackAndCallout:qword
            extrn '__imp_KeExpandKernelStackAndCalloutEx' as KeExpandKernelStackAndCalloutEx:qword
            extrn '__imp_KeFindFirstSetLeftAffinityEx' as KeFindFirstSetLeftAffinityEx:qword
            extrn '__imp_KeGenericCallDpc' as KeGenericCallDpc:qword
            extrn '__imp_KeInitializeCrashDumpHeader' as KeInitializeCrashDumpHeader:qword
            extrn '__imp_KeInitializeGuardedMutex' as KeInitializeGuardedMutex:qword
            extrn '__imp_KeInitializeThreadedDpc' as KeInitializeThreadedDpc:qword
            extrn '__imp_KeInvalidateAllCaches' as KeInvalidateAllCaches:qword
            extrn '__imp_KeInvalidateRangeAllCaches' as KeInvalidateRangeAllCaches:qword
            extrn '__imp_KeIpiGenericCall' as KeIpiGenericCall:qword
            extrn '__imp_KeIsWaitListEmpty' as KeIsWaitListEmpty:qword
            extrn '__imp_KeLeaveGuardedRegion' as KeLeaveGuardedRegion:qword
            extrn '__imp_KeQueryActiveProcessorCount' as KeQueryActiveProcessorCount:qword
            extrn '__imp_KeQueryDpcWatchdogInformation' as KeQueryDpcWatchdogInformation:qword
            extrn '__imp_KeQueryMaximumProcessorCount' as KeQueryMaximumProcessorCount:qword
            extrn '__imp_KeRegisterNmiCallback' as KeRegisterNmiCallback:qword
            extrn '__imp_KeRegisterProcessorChangeCallback' as KeRegisterProcessorChangeCallback:qword
            extrn '__imp_KeReleaseGuardedMutex' as KeReleaseGuardedMutex:qword
            extrn '__imp_KeReleaseGuardedMutexUnsafe' as KeReleaseGuardedMutexUnsafe:qword
            extrn '__imp_KeReleaseInStackQueuedSpinLockForDpc' as KeReleaseInStackQueuedSpinLockForDpc:qword
            extrn '__imp_KeReleaseInStackQueuedSpinLockFromDpcLevel' as KeReleaseInStackQueuedSpinLockFromDpcLevel:qword
            extrn '__imp_KeReleaseSpinLockForDpc' as KeReleaseSpinLockForDpc:qword
            extrn '__imp_KeRemoveQueueEx' as KeRemoveQueueEx:qword
            extrn '__imp_KeRevertToUserGroupAffinityThread' as KeRevertToUserGroupAffinityThread:qword
            extrn '__imp_KeSetSystemAffinityThreadEx' as KeSetSystemAffinityThreadEx:qword
            extrn '__imp_KeTestAlertThread' as KeTestAlertThread:qword
            extrn '__imp_KeTestSpinLock' as KeTestSpinLock:qword
            extrn '__imp_KeTryToAcquireGuardedMutex' as KeTryToAcquireGuardedMutex:qword
            extrn '__imp_KeTryToAcquireSpinLockAtDpcLevel' as KeTryToAcquireSpinLockAtDpcLevel:qword
            extrn '__imp_KiCheckForKernelApcDelivery' as KiCheckForKernelApcDelivery:qword
            extrn '__imp_LpcRequestWaitReplyPortEx' as LpcRequestWaitReplyPortEx:qword
            extrn '__imp_MmAllocateContiguousMemorySpecifyCacheNode' as MmAllocateContiguousMemorySpecifyCacheNode:qword
            extrn '__imp_MmAllocatePagesForMdlEx' as MmAllocatePagesForMdlEx:qword
            extrn '__imp_MmCopyVirtualMemory' as MmCopyVirtualMemory:qword
            extrn '__imp_MmCreateMirror' as MmCreateMirror:qword
            extrn '__imp_MmDoesFileHaveUserWritableReferences' as MmDoesFileHaveUserWritableReferences:qword
            extrn '__imp_MmIsDriverVerifyingByAddress' as MmIsDriverVerifyingByAddress:qword
            extrn '__imp_MmIsIoSpaceActive' as MmIsIoSpaceActive:qword
            extrn '__imp_MmRotatePhysicalView' as MmRotatePhysicalView:qword
            extrn '__imp_NtCommitComplete' as NtCommitComplete:qword
            extrn '__imp_NtCommitEnlistment' as NtCommitEnlistment:qword
            extrn '__imp_NtCommitTransaction' as NtCommitTransaction:qword
            extrn '__imp_NtCreateEnlistment' as NtCreateEnlistment:qword
            extrn '__imp_NtCreateResourceManager' as NtCreateResourceManager:qword
            extrn '__imp_NtCreateTransaction' as NtCreateTransaction:qword
            extrn '__imp_NtEnumerateTransactionObject' as NtEnumerateTransactionObject:qword
            extrn '__imp_NtFreezeTransactions' as NtFreezeTransactions:qword
            extrn '__imp_NtGetNotificationResourceManager' as NtGetNotificationResourceManager:qword
            extrn '__imp_NtOpenEnlistment' as NtOpenEnlistment:qword
            extrn '__imp_NtOpenResourceManager' as NtOpenResourceManager:qword
            extrn '__imp_NtOpenTransaction' as NtOpenTransaction:qword
            extrn '__imp_NtPrepareComplete' as NtPrepareComplete:qword
            extrn '__imp_NtPrepareEnlistment' as NtPrepareEnlistment:qword
            extrn '__imp_NtPrePrepareEnlistment' as NtPrePrepareEnlistment:qword
            extrn '__imp_NtQueryInformationEnlistment' as NtQueryInformationEnlistment:qword
            extrn '__imp_NtQueryInformationResourceManager' as NtQueryInformationResourceManager:qword
            extrn '__imp_NtQueryInformationTransaction' as NtQueryInformationTransaction:qword
            extrn '__imp_NtQueryInformationTransactionManager' as NtQueryInformationTransactionManager:qword
            extrn '__imp_NtRollbackEnlistment' as NtRollbackEnlistment:qword
            extrn '__imp_NtRollbackTransaction' as NtRollbackTransaction:qword
            extrn '__imp_NtSetInformationEnlistment' as NtSetInformationEnlistment:qword
            extrn '__imp_NtSetInformationResourceManager' as NtSetInformationResourceManager:qword
            extrn '__imp_NtSetInformationTransaction' as NtSetInformationTransaction:qword
            extrn '__imp_NtThawTransactions' as NtThawTransactions:qword
            extrn '__imp_NtTraceControl' as NtTraceControl:qword
            extrn '__imp_ObDereferenceObjectDeferDelete' as ObDereferenceObjectDeferDelete:qword
            extrn '__imp_ObDereferenceSecurityDescriptor' as ObDereferenceSecurityDescriptor:qword
            extrn '__imp_ObGetFilterVersion' as ObGetFilterVersion:qword
            extrn '__imp_ObIsKernelHandle' as ObIsKernelHandle:qword
            extrn '__imp_ObRegisterCallbacks' as ObRegisterCallbacks:qword
            extrn '__imp_ObUnRegisterCallbacks' as ObUnRegisterCallbacks:qword
            extrn '__imp_PoGetSystemWake' as PoGetSystemWake:qword
            extrn '__imp_PoRegisterPowerSettingCallback' as PoRegisterPowerSettingCallback:qword
            extrn '__imp_PoSetDeviceBusyEx' as PoSetDeviceBusyEx:qword
            extrn '__imp_PoSetSystemWake' as PoSetSystemWake:qword
            extrn '__imp_PoUnregisterPowerSettingCallback' as PoUnregisterPowerSettingCallback:qword
            extrn '__imp_PsAcquireProcessExitSynchronization' as PsAcquireProcessExitSynchronization:qword
            extrn '__imp_PsGetCurrentProcessWin32Process' as PsGetCurrentProcessWin32Process:qword
            extrn '__imp_PsGetCurrentThreadProcess' as PsGetCurrentThreadProcess:qword
            extrn '__imp_PsGetCurrentThreadProcessId' as PsGetCurrentThreadProcessId:qword
            extrn '__imp_PsGetCurrentThreadTeb' as PsGetCurrentThreadTeb:qword
            extrn '__imp_PsGetCurrentThreadWin32Thread' as PsGetCurrentThreadWin32Thread:qword
            extrn '__imp_PsIsCurrentThreadPrefetching' as PsIsCurrentThreadPrefetching:qword
            extrn '__imp_PsIsSystemProcess' as PsIsSystemProcess:qword
            extrn '__imp_PsReferenceProcessFilePointer' as PsReferenceProcessFilePointer:qword
            extrn '__imp_PsResumeProcess' as PsResumeProcess:qword
            extrn '__imp_PsSetCreateProcessNotifyRoutineEx' as PsSetCreateProcessNotifyRoutineEx:qword
            extrn '__imp_PsSetCurrentThreadPrefetching' as PsSetCurrentThreadPrefetching:qword
            extrn '__imp_PsSuspendProcess' as PsSuspendProcess:qword
            extrn '__imp_PsWrapApcWow64Thread' as PsWrapApcWow64Thread:qword
            extrn '__imp_RtlCmDecodeMemIoResource' as RtlCmDecodeMemIoResource:qword
            extrn '__imp_RtlCmEncodeMemIoResource' as RtlCmEncodeMemIoResource:qword
            extrn '__imp_RtlCompareAltitudes' as RtlCompareAltitudes:qword
            extrn '__imp_RtlComputeCrc32' as RtlComputeCrc32:qword
            extrn '__imp_RtlCopyLuidAndAttributesArray' as RtlCopyLuidAndAttributesArray:qword
            extrn '__imp_RtlCopySidAndAttributesArray' as RtlCopySidAndAttributesArray:qword
            extrn '__imp_RtlDuplicateUnicodeString' as RtlDuplicateUnicodeString:qword
            extrn '__imp_RtlFormatMessage' as RtlFormatMessage:qword
            extrn '__imp_RtlGetThreadLangIdByIndex' as RtlGetThreadLangIdByIndex:qword
            extrn '__imp_RtlInitAnsiStringEx' as RtlInitAnsiStringEx:qword
            extrn '__imp_RtlInitUnicodeStringEx' as RtlInitUnicodeStringEx:qword
            extrn '__imp_RtlIoDecodeMemIoResource' as RtlIoDecodeMemIoResource:qword
            extrn '__imp_RtlIoEncodeMemIoResource' as RtlIoEncodeMemIoResource:qword
            extrn '__imp_RtlIsNormalizedString' as RtlIsNormalizedString:qword
            extrn '__imp_RtlIsNtDdiVersionAvailable' as RtlIsNtDdiVersionAvailable:qword
            extrn '__imp_RtlIsServicePackVersionInstalled' as RtlIsServicePackVersionInstalled:qword
            extrn '__imp_RtlLocalTimeToSystemTime' as RtlLocalTimeToSystemTime:qword
            extrn '__imp_RtlLookupFirstMatchingElementGenericTableAvl' as RtlLookupFirstMatchingElementGenericTableAvl:qword
            extrn '__imp_RtlNumberOfSetBitsUlongPtr' as RtlNumberOfSetBitsUlongPtr:qword
            extrn '__imp_RtlQueryElevationFlags' as RtlQueryElevationFlags:qword
            extrn '__imp_RtlRunOnceBeginInitialize' as RtlRunOnceBeginInitialize:qword
            extrn '__imp_RtlRunOnceComplete' as RtlRunOnceComplete:qword
            extrn '__imp_RtlRunOnceExecuteOnce' as RtlRunOnceExecuteOnce:qword
            extrn '__imp_RtlRunOnceInitialize' as RtlRunOnceInitialize:qword
            extrn '__imp_RtlSystemTimeToLocalTime' as RtlSystemTimeToLocalTime:qword
            extrn '__imp_RtlUnlockBootStatusData' as RtlUnlockBootStatusData:qword
            extrn '__imp_RtlValidateUnicodeString' as RtlValidateUnicodeString:qword
            extrn '__imp_SeAuditHardLinkCreationWithTransaction' as SeAuditHardLinkCreationWithTransaction:qword
            extrn '__imp_SeAuditTransactionStateChange' as SeAuditTransactionStateChange:qword
            extrn '__imp_SeCaptureSubjectContextEx' as SeCaptureSubjectContextEx:qword
            extrn '__imp_SeComputeAutoInheritByObjectType' as SeComputeAutoInheritByObjectType:qword
            extrn '__imp_SeCreateAccessStateEx' as SeCreateAccessStateEx:qword
            extrn '__imp_SeDeleteObjectAuditAlarmWithTransaction' as SeDeleteObjectAuditAlarmWithTransaction:qword
            extrn '__imp_SeExamineSacl' as SeExamineSacl:qword
            extrn '__imp_SeFilterToken' as SeFilterToken:qword
            extrn '__imp_SeLocateProcessImageName' as SeLocateProcessImageName:qword
            extrn '__imp_SeOpenObjectForDeleteAuditAlarmWithTransaction' as SeOpenObjectForDeleteAuditAlarmWithTransaction:qword
            extrn '__imp_SeReportSecurityEventWithSubCategory' as SeReportSecurityEventWithSubCategory:qword
            extrn '__imp_SeSetAuditParameter' as SeSetAuditParameter:qword
            extrn '__imp_TmCommitComplete' as TmCommitComplete:qword
            extrn '__imp_TmCommitEnlistment' as TmCommitEnlistment:qword
            extrn '__imp_TmCommitTransaction' as TmCommitTransaction:qword
            extrn '__imp_TmCreateEnlistment' as TmCreateEnlistment:qword
            extrn '__imp_TmDereferenceEnlistmentKey' as TmDereferenceEnlistmentKey:qword
            extrn '__imp_TmEnableCallbacks' as TmEnableCallbacks:qword
            extrn '__imp_TmGetTransactionId' as TmGetTransactionId:qword
            extrn '__imp_TmIsTransactionActive' as TmIsTransactionActive:qword
            extrn '__imp_TmPrepareComplete' as TmPrepareComplete:qword
            extrn '__imp_TmPrepareEnlistment' as TmPrepareEnlistment:qword
            extrn '__imp_TmPrePrepareComplete' as TmPrePrepareComplete:qword
            extrn '__imp_TmPrePrepareEnlistment' as TmPrePrepareEnlistment:qword
            extrn '__imp_TmReadOnlyEnlistment' as TmReadOnlyEnlistment:qword
            extrn '__imp_TmRecoverEnlistment' as TmRecoverEnlistment:qword
            extrn '__imp_TmRecoverResourceManager' as TmRecoverResourceManager:qword
            extrn '__imp_TmRecoverTransactionManager' as TmRecoverTransactionManager:qword
            extrn '__imp_TmReferenceEnlistmentKey' as TmReferenceEnlistmentKey:qword
            extrn '__imp_TmRequestOutcomeEnlistment' as TmRequestOutcomeEnlistment:qword
            extrn '__imp_TmRollbackComplete' as TmRollbackComplete:qword
            extrn '__imp_TmRollbackEnlistment' as TmRollbackEnlistment:qword
            extrn '__imp_TmRollbackTransaction' as TmRollbackTransaction:qword
            extrn '__imp_WheaAddErrorSource' as WheaAddErrorSource:qword
            extrn '__imp_ZwAddDriverEntry' as ZwAddDriverEntry:qword
            extrn '__imp_ZwAllocateLocallyUniqueId' as ZwAllocateLocallyUniqueId:qword
            extrn '__imp_ZwAlpcAcceptConnectPort' as ZwAlpcAcceptConnectPort:qword
            extrn '__imp_ZwAlpcCancelMessage' as ZwAlpcCancelMessage:qword
            extrn '__imp_ZwAlpcConnectPort' as ZwAlpcConnectPort:qword
            extrn '__imp_ZwAlpcCreatePort' as ZwAlpcCreatePort:qword
            extrn '__imp_ZwAlpcCreatePortSection' as ZwAlpcCreatePortSection:qword
            extrn '__imp_ZwAlpcCreateResourceReserve' as ZwAlpcCreateResourceReserve:qword
            extrn '__imp_ZwAlpcCreateSectionView' as ZwAlpcCreateSectionView:qword
            extrn '__imp_ZwAlpcCreateSecurityContext' as ZwAlpcCreateSecurityContext:qword
            extrn '__imp_ZwAlpcDeletePortSection' as ZwAlpcDeletePortSection:qword
            extrn '__imp_ZwAlpcDeleteResourceReserve' as ZwAlpcDeleteResourceReserve:qword
            extrn '__imp_ZwAlpcDeleteSectionView' as ZwAlpcDeleteSectionView:qword
            extrn '__imp_ZwAlpcDeleteSecurityContext' as ZwAlpcDeleteSecurityContext:qword
            extrn '__imp_ZwAlpcDisconnectPort' as ZwAlpcDisconnectPort:qword
            extrn '__imp_ZwAlpcQueryInformation' as ZwAlpcQueryInformation:qword
            extrn '__imp_ZwAlpcSendWaitReceivePort' as ZwAlpcSendWaitReceivePort:qword
            extrn '__imp_ZwAlpcSetInformation' as ZwAlpcSetInformation:qword
            extrn '__imp_ZwCommitEnlistment' as ZwCommitEnlistment:qword
            extrn '__imp_ZwCommitTransaction' as ZwCommitTransaction:qword
            extrn '__imp_ZwCreateEnlistment' as ZwCreateEnlistment:qword
            extrn '__imp_ZwCreateIoCompletion' as ZwCreateIoCompletion:qword
            extrn '__imp_ZwCreateKeyTransacted' as ZwCreateKeyTransacted:qword
            extrn '__imp_ZwCreateResourceManager' as ZwCreateResourceManager:qword
            extrn '__imp_ZwCreateTransaction' as ZwCreateTransaction:qword
            extrn '__imp_ZwCreateTransactionManager' as ZwCreateTransactionManager:qword
            extrn '__imp_ZwEnumerateDriverEntries' as ZwEnumerateDriverEntries:qword
            extrn '__imp_ZwEnumerateTransactionObject' as ZwEnumerateTransactionObject:qword
            extrn '__imp_ZwFlushBuffersFile' as ZwFlushBuffersFile:qword
            extrn '__imp_ZwGetNotificationResourceManager' as ZwGetNotificationResourceManager:qword
            extrn '__imp_ZwImpersonateAnonymousToken' as ZwImpersonateAnonymousToken:qword
            extrn '__imp_ZwLoadKeyEx' as ZwLoadKeyEx:qword
            extrn '__imp_ZwLockProductActivationKeys' as ZwLockProductActivationKeys:qword
            extrn '__imp_ZwModifyBootEntry' as ZwModifyBootEntry:qword
            extrn '__imp_ZwModifyDriverEntry' as ZwModifyDriverEntry:qword
            extrn '__imp_ZwOpenEnlistment' as ZwOpenEnlistment:qword
            extrn '__imp_ZwOpenKeyTransacted' as ZwOpenKeyTransacted:qword
            extrn '__imp_ZwOpenResourceManager' as ZwOpenResourceManager:qword
            extrn '__imp_ZwOpenTransaction' as ZwOpenTransaction:qword
            extrn '__imp_ZwOpenTransactionManager' as ZwOpenTransactionManager:qword
            extrn '__imp_ZwPrepareComplete' as ZwPrepareComplete:qword
            extrn '__imp_ZwPrepareEnlistment' as ZwPrepareEnlistment:qword
            extrn '__imp_ZwPrePrepareEnlistment' as ZwPrePrepareEnlistment:qword
            extrn '__imp_ZwQueryDriverEntryOrder' as ZwQueryDriverEntryOrder:qword
            extrn '__imp_ZwQueryInformationEnlistment' as ZwQueryInformationEnlistment:qword
            extrn '__imp_ZwQueryInformationResourceManager' as ZwQueryInformationResourceManager:qword
            extrn '__imp_ZwQueryInformationTransaction' as ZwQueryInformationTransaction:qword
            extrn '__imp_ZwQueryInformationTransactionManager' as ZwQueryInformationTransactionManager:qword
            extrn '__imp_ZwQueryVirtualMemory' as ZwQueryVirtualMemory:qword
            extrn '__imp_ZwRecoverEnlistment' as ZwRecoverEnlistment:qword
            extrn '__imp_ZwRecoverResourceManager' as ZwRecoverResourceManager:qword
            extrn '__imp_ZwRecoverTransactionManager' as ZwRecoverTransactionManager:qword
            extrn '__imp_ZwRemoveIoCompletion' as ZwRemoveIoCompletion:qword
            extrn '__imp_ZwRemoveIoCompletionEx' as ZwRemoveIoCompletionEx:qword
            extrn '__imp_ZwRequestPort' as ZwRequestPort:qword
            extrn '__imp_ZwRollbackEnlistment' as ZwRollbackEnlistment:qword
            extrn '__imp_ZwRollbackTransaction' as ZwRollbackTransaction:qword
            extrn '__imp_ZwSecureConnectPort' as ZwSecureConnectPort:qword
            extrn '__imp_ZwSetDriverEntryOrder' as ZwSetDriverEntryOrder:qword
            extrn '__imp_ZwSetInformationEnlistment' as ZwSetInformationEnlistment:qword
            extrn '__imp_ZwSetInformationTransaction' as ZwSetInformationTransaction:qword
            extrn '__imp_ZwUnloadKeyEx' as ZwUnloadKeyEx:qword
            extrn '__imp__strtoui64' as _strtoui64:qword
            extrn '__imp__swprintf' as _swprintf:qword
            extrn '__imp__vswprintf' as _vswprintf:qword
        end if

        if (NTDDI_VERSION >= NTDDI_WIN7)
            extrn '__imp_CcCoherencyFlushAndPurgeCache' as CcCoherencyFlushAndPurgeCache:qword
            extrn '__imp_CcCopyWriteWontFlush' as CcCopyWriteWontFlush:qword
            extrn '__imp_EtwWriteEx' as EtwWriteEx:qword
            extrn '__imp_ExAcquireFastMutex' as ExAcquireFastMutex:qword
            extrn '__imp_ExpInterlockedFlushSList' as ExpInterlockedFlushSList:qword
            extrn '__imp_ExpInterlockedPopEntrySList' as ExpInterlockedPopEntrySList:qword
            extrn '__imp_ExpInterlockedPushEntrySList' as ExpInterlockedPushEntrySList:qword
            extrn '__imp_ExQueryDepthSList' as ExQueryDepthSList:qword
            extrn '__imp_ExReleaseFastMutex' as ExReleaseFastMutex:qword
            extrn '__imp_ExSetResourceOwnerPointerEx' as ExSetResourceOwnerPointerEx:qword
            extrn '__imp_ExTryToAcquireFastMutex' as ExTryToAcquireFastMutex:qword
            extrn '__imp_FsRtlCurrentOplockH' as FsRtlCurrentOplockH:qword
            extrn '__imp_FsRtlAreThereCurrentOrInProgressFileLocks' as FsRtlAreThereCurrentOrInProgressFileLocks:qword
            extrn '__imp_FsRtlGetVirtualDiskNestingLevel' as FsRtlGetVirtualDiskNestingLevel:qword
            extrn '__imp_FsRtlOplockBreakH' as FsRtlOplockBreakH:qword
            extrn '__imp_FsRtlOplockBreakToNoneEx' as FsRtlOplockBreakToNoneEx:qword
            extrn '__imp_FsRtlOplockFsctrlEx' as FsRtlOplockFsctrlEx:qword
            extrn '__imp_FsRtlOplockIsSharedRequest' as FsRtlOplockIsSharedRequest:qword
            extrn '__imp_FsRtlOplockKeysEqual' as FsRtlOplockKeysEqual:qword
            extrn '__imp_FsRtlQueryMaximumVirtualDiskNestingLevel' as FsRtlQueryMaximumVirtualDiskNestingLevel:qword
            extrn '__imp_IoGetAffinityInterrupt' as IoGetAffinityInterrupt:qword
            extrn '__imp_IoGetContainerInformation' as IoGetContainerInformation:qword
            extrn '__imp_IoGetDeviceNumaNode' as IoGetDeviceNumaNode:qword
            extrn '__imp_IoGetOplockKeyContext' as IoGetOplockKeyContext:qword
            extrn '__imp_IoIs32bitProcess' as IoIs32bitProcess:qword
            extrn '__imp_IoRegisterContainerNotification' as IoRegisterContainerNotification:qword
            extrn '__imp_IoRegisterFsRegistrationChangeMountAware' as IoRegisterFsRegistrationChangeMountAware:qword
            extrn '__imp_IoReplaceFileObjectName' as IoReplaceFileObjectName:qword
            extrn '__imp_IoReportRootDevice' as IoReportRootDevice:qword
            extrn '__imp_IoSetFileObjectIgnoreSharing' as IoSetFileObjectIgnoreSharing:qword
            extrn '__imp_IoUnregisterContainerNotification' as IoUnregisterContainerNotification:qword
            extrn '__imp_IoUnregisterPlugPlayNotificationEx' as IoUnregisterPlugPlayNotificationEx:qword
            extrn '__imp_IoUnregisterPriorityCallback' as IoUnregisterPriorityCallback:qword
            extrn '__imp_IoWMIDeviceObjectToProviderId' as IoWMIDeviceObjectToProviderId:qword
            if defined APP_WIN64
                extrn '__imp_KeAcquireInStackQueuedSpinLock' as KeAcquireInStackQueuedSpinLock:qword
                extrn '__imp_KeAcquireInStackQueuedSpinLockRaiseToSynch' as KeAcquireInStackQueuedSpinLockRaiseToSynch:qword
                extrn '__imp_KeAcquireQueuedSpinLock' as KeAcquireQueuedSpinLock:qword
                extrn '__imp_KeAcquireQueuedSpinLockRaiseToSynch' as KeAcquireQueuedSpinLockRaiseToSynch:qword
                extrn '__imp_KeAcquireSpinLockRaiseToDpc' as KeAcquireSpinLockRaiseToDpc:qword
                extrn '__imp_KeAcquireSpinLockRaiseToSynch' as KeAcquireSpinLockRaiseToSynch:qword
                extrn '__imp_KeGetCurrentIrql' as KeGetCurrentIrql:qword
                extrn '__imp_KeLowerIrql' as KeLowerIrql:qword
                extrn '__imp_KeQueryPrcbAddress' as KeQueryPrcbAddress:qword
                extrn '__imp_KeRaiseIrqlToDpcLevel' as KeRaiseIrqlToDpcLevel:qword
                extrn '__imp_KeReleaseInStackQueuedSpinLock' as KeReleaseInStackQueuedSpinLock:qword
                extrn '__imp_KeReleaseQueuedSpinLock' as KeReleaseQueuedSpinLock:qword
                extrn '__imp_KeReleaseSpinLock' as KeReleaseSpinLock:qword
                extrn '__imp_KeTryToAcquireQueuedSpinLock' as KeTryToAcquireQueuedSpinLock:qword
                extrn '__imp_KeTryToAcquireQueuedSpinLockRaiseToSynch' as KeTryToAcquireQueuedSpinLockRaiseToSynch:qword
                extrn '__imp_longjmp' as longjmp:qword
                extrn '__imp_memcmp' as memcmp:qword
                extrn '__imp_PsGetProcessWow64Process' as PsGetProcessWow64Process:qword
                extrn '__imp_RtlLookupFunctionEntry' as RtlLookupFunctionEntry:qword
                extrn '__imp_RtlPcToFileHeader' as RtlPcToFileHeader:qword
                extrn '__imp_RtlRestoreContext' as RtlRestoreContext:qword
                extrn '__imp_RtlVirtualUnwind' as RtlVirtualUnwind:qword
                extrn '__imp__setjmp' as _setjmp:qword
                extrn '__imp__setjmpex' as _setjmpex:qword
            end if
            extrn '__imp_KeAndAffinityEx' as KeAndAffinityEx:qword
            extrn '__imp_KeComplementAffinityEx' as KeComplementAffinityEx:qword
            extrn '__imp_KeGetCurrentNodeNumber' as KeGetCurrentNodeNumber:qword
            extrn '__imp_KeGetCurrentProcessorNumberEx' as KeGetCurrentProcessorNumberEx:qword
            extrn '__imp_KeGetProcessorIndexFromNumber' as KeGetProcessorIndexFromNumber:qword
            extrn '__imp_KeGetProcessorNumberFromIndex' as KeGetProcessorNumberFromIndex:qword
            extrn '__imp_KeInitializeEnumerationContext' as KeInitializeEnumerationContext:qword
            extrn '__imp_KeInterlockedSetProcessorAffinityEx' as KeInterlockedSetProcessorAffinityEx:qword
            extrn '__imp_KeIsEmptyAffinityEx' as KeIsEmptyAffinityEx:qword
            extrn '__imp_KeIsEqualAffinityEx' as KeIsEqualAffinityEx:qword
            extrn '__imp_KeIsSubsetAffinityEx' as KeIsSubsetAffinityEx:qword
            extrn '__imp_KeQueryActiveGroupCount' as KeQueryActiveGroupCount:qword
            extrn '__imp_KeQueryActiveProcessorCountEx' as KeQueryActiveProcessorCountEx:qword
            extrn '__imp_KeQueryGroupAffinity' as KeQueryGroupAffinity:qword
            extrn '__imp_KeQueryHardwareCounterConfiguration' as KeQueryHardwareCounterConfiguration:qword
            extrn '__imp_KeQueryHighestNodeNumber' as KeQueryHighestNodeNumber:qword
            extrn '__imp_KeQueryLogicalProcessorRelationship' as KeQueryLogicalProcessorRelationship:qword
            extrn '__imp_KeQueryMaximumGroupCount' as KeQueryMaximumGroupCount:qword
            extrn '__imp_KeQueryMaximumProcessorCountEx' as KeQueryMaximumProcessorCountEx:qword
            extrn '__imp_KeQueryNodeActiveAffinity' as KeQueryNodeActiveAffinity:qword
            extrn '__imp_KeQueryNodeMaximumProcessorCount' as KeQueryNodeMaximumProcessorCount:qword
            extrn '__imp_KeQueryUnbiasedInterruptTime' as KeQueryUnbiasedInterruptTime:qword
            extrn '__imp_KeSaveExtendedProcessorState' as KeSaveExtendedProcessorState:qword
            extrn '__imp_KeSetCoalescableTimer' as KeSetCoalescableTimer:qword
            extrn '__imp_KeSetHardwareCounterConfiguration' as KeSetHardwareCounterConfiguration:qword
            extrn '__imp_KeSetSystemGroupAffinityThread' as KeSetSystemGroupAffinityThread:qword
            extrn '__imp_KeSetTargetProcessorDpcEx' as KeSetTargetProcessorDpcEx:qword
            extrn '__imp_memcpy_s' as memcpy_s:qword
            extrn '__imp_memmove_s' as memmove_s:qword
            extrn '__imp_NtCreateTransactionManager' as NtCreateTransactionManager:qword
            extrn '__imp_NtOpenTransactionManager' as NtOpenTransactionManager:qword
            extrn '__imp_NtPrePrepareComplete' as NtPrePrepareComplete:qword
            extrn '__imp_NtPropagationComplete' as NtPropagationComplete:qword
            extrn '__imp_NtPropagationFailed' as NtPropagationFailed:qword
            extrn '__imp_NtQuerySecurityAttributesToken' as NtQuerySecurityAttributesToken:qword
            extrn '__imp_NtQuerySystemInformationEx' as NtQuerySystemInformationEx:qword
            extrn '__imp_NtReadOnlyEnlistment' as NtReadOnlyEnlistment:qword
            extrn '__imp_NtRecoverEnlistment' as NtRecoverEnlistment:qword
            extrn '__imp_NtRecoverResourceManager' as NtRecoverResourceManager:qword
            extrn '__imp_NtRecoverTransactionManager' as NtRecoverTransactionManager:qword
            extrn '__imp_NtRollbackComplete' as NtRollbackComplete:qword
            extrn '__imp_NtSetInformationToken' as NtSetInformationToken:qword
            extrn '__imp_ObDereferenceObjectDeferDeleteWithTag' as ObDereferenceObjectDeferDeleteWithTag:qword
            extrn '__imp_ObfReferenceObjectWithTag' as ObfReferenceObjectWithTag:qword
            extrn '__imp_ObOpenObjectByPointerWithTag' as ObOpenObjectByPointerWithTag:qword
            extrn '__imp_ObQueryNameInfo' as ObQueryNameInfo:qword
            extrn '__imp_ObReferenceObjectByHandleWithTag' as ObReferenceObjectByHandleWithTag:qword
            extrn '__imp_ObReferenceObjectByPointerWithTag' as ObReferenceObjectByPointerWithTag:qword
            extrn '__imp_PcwAddInstance' as PcwAddInstance:qword
            extrn '__imp_PcwCloseInstance' as PcwCloseInstance:qword
            extrn '__imp_PcwCreateInstance' as PcwCreateInstance:qword
            extrn '__imp_PcwRegister' as PcwRegister:qword
            extrn '__imp_PcwUnregister' as PcwUnregister:qword
            extrn '__imp_PoClearPowerRequest' as PoClearPowerRequest:qword
            extrn '__imp_PoCreatePowerRequest' as PoCreatePowerRequest:qword
            extrn '__imp_PoDeletePowerRequest' as PoDeletePowerRequest:qword
            extrn '__imp_PoEndDeviceBusy' as PoEndDeviceBusy:qword
            extrn '__imp_PoQueryWatchdogTime' as PoQueryWatchdogTime:qword
            extrn '__imp_PoSetPowerRequest' as PoSetPowerRequest:qword
            extrn '__imp_PoStartDeviceBusy' as PoStartDeviceBusy:qword
            extrn '__imp_RtlDowncaseUnicodeChar' as RtlDowncaseUnicodeChar:qword
            extrn '__imp_RtlCompareUnicodeStrings' as RtlCompareUnicodeStrings:qword
            extrn '__imp_RtlEthernetAddressToStringA' as RtlEthernetAddressToStringA:qword
            extrn '__imp_RtlEthernetAddressToStringW' as RtlEthernetAddressToStringW:qword
            extrn '__imp_RtlEthernetStringToAddressA' as RtlEthernetStringToAddressA:qword
            extrn '__imp_RtlEthernetStringToAddressW' as RtlEthernetStringToAddressW:qword
            extrn '__imp_RtlGetEnabledExtendedFeatures' as RtlGetEnabledExtendedFeatures:qword
            extrn '__imp_RtlGetNextEntryHashTable' as RtlGetNextEntryHashTable:qword
            extrn '__imp_RtlInitEnumerationHashTable' as RtlInitEnumerationHashTable:qword
            extrn '__imp_RtlInitWeakEnumerationHashTable' as RtlInitWeakEnumerationHashTable:qword
            extrn '__imp_RtlInsertEntryHashTable' as RtlInsertEntryHashTable:qword
            extrn '__imp_RtlLookupEntryHashTable' as RtlLookupEntryHashTable:qword
            extrn '__imp_RtlUnicodeToUTF8N' as RtlUnicodeToUTF8N:qword
            extrn '__imp_RtlUTF8ToUnicodeN' as RtlUTF8ToUnicodeN:qword
            extrn '__imp_SeAccessCheckEx' as SeAccessCheckEx:qword
            extrn '__imp_SeAuditingAnyFileEventsWithContext' as SeAuditingAnyFileEventsWithContext:qword
            extrn '__imp_SeAuditingFileEventsWithContext' as SeAuditingFileEventsWithContext:qword
            extrn '__imp_vsprintf_s' as vsprintf_s:qword
            extrn '__imp_vswprintf_s' as vswprintf_s:qword
            extrn '__imp_wcscat_s' as wcscat_s:qword
            extrn '__imp_wcscpy_s' as wcscpy_s:qword
            extrn '__imp_wcsncat_s' as wcsncat_s:qword
            extrn '__imp_wcsncpy_s' as wcsncpy_s:qword
            extrn '__imp_wcsnlen' as wcsnlen:qword
            extrn '__imp_wcstoul' as wcstoul:qword
            extrn '__imp_ZwCommitComplete' as ZwCommitComplete:qword
            extrn '__imp_ZwLockFile' as ZwLockFile:qword
            extrn '__imp_ZwOpenKeyEx' as ZwOpenKeyEx:qword
            extrn '__imp_ZwOpenKeyTransactedEx' as ZwOpenKeyTransactedEx:qword
            extrn '__imp_ZwOpenSession' as ZwOpenSession:qword
            extrn '__imp_ZwPrePrepareComplete' as ZwPrePrepareComplete:qword
            extrn '__imp_ZwPropagationComplete' as ZwPropagationComplete:qword
            extrn '__imp_ZwPropagationFailed' as ZwPropagationFailed:qword
            extrn '__imp_ZwQueryQuotaInformationFile' as ZwQueryQuotaInformationFile:qword
            extrn '__imp_ZwQuerySecurityAttributesToken' as ZwQuerySecurityAttributesToken:qword
            extrn '__imp_ZwReadOnlyEnlistment' as ZwReadOnlyEnlistment:qword
            extrn '__imp_ZwRenameKey' as ZwRenameKey:qword
            extrn '__imp_ZwRollbackComplete' as ZwRollbackComplete:qword
            extrn '__imp_ZwSetInformationResourceManager' as ZwSetInformationResourceManager:qword
            extrn '__imp_ZwSetInformationToken' as ZwSetInformationToken:qword
            extrn '__imp_ZwSetQuotaInformationFile' as ZwSetQuotaInformationFile:qword
            extrn '__imp_ZwSetTimerEx' as ZwSetTimerEx:qword
            extrn '__imp_ZwTraceEvent' as ZwTraceEvent:qword
            extrn '__imp_ZwUnlockFile' as ZwUnlockFile:qword
            extrn '__imp__i64toa_s' as _i64toa_s:qword
            extrn '__imp__i64tow_s' as _i64tow_s:qword
            extrn '__imp__itoa_s' as _itoa_s:qword
            extrn '__imp__itow_s' as _itow_s:qword
            extrn '__imp__ltoa_s' as _ltoa_s:qword
            extrn '__imp__ltow_s' as _ltow_s:qword
            extrn '__imp__makepath_s' as _makepath_s:qword
            extrn '__imp__snprintf_s' as _snprintf_s:qword
            extrn '__imp__splitpath_s' as _splitpath_s:qword
            extrn '__imp__strnset_s' as _strnset_s:qword
            extrn '__imp__strset_s' as _strset_s:qword
            extrn '__imp__ui64toa_s' as _ui64toa_s:qword
            extrn '__imp__ui64tow_s' as _ui64tow_s:qword
            extrn '__imp__ultoa_s' as _ultoa_s:qword
            extrn '__imp__ultow_s' as _ultow_s:qword
            extrn '__imp__vsnprintf_s' as _vsnprintf_s:qword
            extrn '__imp__vsnwprintf_s' as _vsnwprintf_s:qword
            extrn '__imp__wcsnset_s' as _wcsnset_s:qword
            extrn '__imp__wcsset_s' as _wcsset_s:qword
            extrn '__imp__wmakepath_s' as _wmakepath_s:qword
            extrn '__imp__wsplitpath_s' as _wsplitpath_s:qword
            extrn '__imp__wtoi' as _wtoi:qword
            extrn '__imp__wtol' as _wtol:qword

            api RtlEthernetAddressToString,\
                RtlEthernetStringToAddress
        end if

        if (NTDDI_VERSION >= NTDDI_WIN8)
            extrn '__imp_bsearch_s' as bsearch_s:qword
            extrn '__imp_CcCopyReadEx' as CcCopyReadEx:qword
            extrn '__imp_CcCopyWriteEx' as CcCopyWriteEx:qword
            extrn '__imp_CcIsThereDirtyLoggedPages' as CcIsThereDirtyLoggedPages:qword
            extrn '__imp_CcScheduleReadAheadEx' as CcScheduleReadAheadEx:qword
            extrn '__imp_CcSetAdditionalCacheAttributesEx' as CcSetAdditionalCacheAttributesEx:qword
            extrn '__imp_CcSetLoggedDataThreshold' as CcSetLoggedDataThreshold:qword
            extrn '__imp_CcSetLogHandleForFileEx' as CcSetLogHandleForFileEx:qword
            extrn '__imp_CcSetReadAheadGranularityEx' as CcSetReadAheadGranularityEx:qword
            extrn '__imp_CcUnmapFileOffsetFromSystemCache' as CcUnmapFileOffsetFromSystemCache:qword
            extrn '__imp_CmCallbackGetKeyObjectIDEx' as CmCallbackGetKeyObjectIDEx:qword
            extrn '__imp_CmCallbackReleaseKeyObjectIDEx' as CmCallbackReleaseKeyObjectIDEx:qword
            extrn '__imp_ExBlockPushLock' as ExBlockPushLock:qword
            extrn '__imp_ExGetFirmwareEnvironmentVariable' as ExGetFirmwareEnvironmentVariable:qword
            extrn '__imp_ExQueryTimerResolution' as ExQueryTimerResolution:qword
            extrn '__imp_ExSetFirmwareEnvironmentVariable' as ExSetFirmwareEnvironmentVariable:qword
            extrn '__imp_ExTimedWaitForUnblockPushLock' as ExTimedWaitForUnblockPushLock:qword
            extrn '__imp_ExWaitForUnblockPushLock' as ExWaitForUnblockPushLock:qword
            extrn '__imp_FsRtlAreThereWaitingFileLocks' as FsRtlAreThereWaitingFileLocks:qword
            extrn '__imp_FsRtlCheckLockForOplockRequest' as FsRtlCheckLockForOplockRequest:qword
            extrn '__imp_FsRtlGetSectorSizeInformation' as FsRtlGetSectorSizeInformation:qword
            extrn '__imp_FsRtlGetSupportedFeatures' as FsRtlGetSupportedFeatures:qword
            extrn '__imp_FsRtlIssueDeviceIoControl' as FsRtlIssueDeviceIoControl:qword
            extrn '__imp_FsRtlIsSystemPagingFile' as FsRtlIsSystemPagingFile:qword
            extrn '__imp_FsRtlMdlReadEx' as FsRtlMdlReadEx:qword
            extrn '__imp_FsRtlPrepareMdlWriteEx' as FsRtlPrepareMdlWriteEx:qword
            extrn '__imp_FsRtlQueryCachedVdl' as FsRtlQueryCachedVdl:qword
            extrn '__imp_IoClearActivityIdThread' as IoClearActivityIdThread:qword
            extrn '__imp_IoCreateStreamFileObjectEx2' as IoCreateStreamFileObjectEx2:qword
            extrn '__imp_IoCreateSystemThread' as IoCreateSystemThread:qword
            extrn '__imp_IoDecrementKeepAliveCount' as IoDecrementKeepAliveCount:qword
            extrn '__imp_IoGetActivityIdIrp' as IoGetActivityIdIrp:qword
            extrn '__imp_IoGetActivityIdThread' as IoGetActivityIdThread:qword
            extrn '__imp_IoGetDeviceInterfacePropertyData' as IoGetDeviceInterfacePropertyData:qword
            extrn '__imp_IoGetInitiatorProcess' as IoGetInitiatorProcess:qword
            extrn '__imp_IoGetOplockKeyContextEx' as IoGetOplockKeyContextEx:qword
            extrn '__imp_IoIncrementKeepAliveCount' as IoIncrementKeepAliveCount:qword
            extrn '__imp_IoIsInitiator32bitProcess' as IoIsInitiator32bitProcess:qword
            extrn '__imp_IoIsValidIrpStatus' as IoIsValidIrpStatus:qword
            extrn '__imp_IoPropagateActivityIdToThread' as IoPropagateActivityIdToThread:qword
            extrn '__imp_IoRegisterBootDriverCallback' as IoRegisterBootDriverCallback:qword
            extrn '__imp_IoReportInterruptActive' as IoReportInterruptActive:qword
            extrn '__imp_IoReportInterruptInactive' as IoReportInterruptInactive:qword
            extrn '__imp_IoSetActivityIdIrp' as IoSetActivityIdIrp:qword
            extrn '__imp_IoSetActivityIdThread' as IoSetActivityIdThread:qword
            extrn '__imp_IoSetDeviceInterfacePropertyData' as IoSetDeviceInterfacePropertyData:qword
            extrn '__imp_IoSetMasterIrpStatus' as IoSetMasterIrpStatus:qword
            extrn '__imp_IoTransferActivityId' as IoTransferActivityId:qword
            extrn '__imp_IoTryQueueWorkItem' as IoTryQueueWorkItem:qword
            extrn '__imp_IoUnregisterBootDriverCallback' as IoUnregisterBootDriverCallback:qword
            extrn '__imp_IoVolumeDeviceToGuid' as IoVolumeDeviceToGuid:qword
            extrn '__imp_KdLogDbgPrint' as KdLogDbgPrint:qword
            extrn '__imp_KeQueryInterruptTimePrecise' as KeQueryInterruptTimePrecise:qword
            extrn '__imp_KeQuerySystemTimePrecise' as KeQuerySystemTimePrecise:qword
            extrn '__imp_KeQueryTotalCycleTimeThread' as KeQueryTotalCycleTimeThread:qword
            extrn '__imp_MmAllocateContiguousNodeMemory' as MmAllocateContiguousNodeMemory:qword
            extrn '__imp_MmAllocateMdlForIoSpace' as MmAllocateMdlForIoSpace:qword
            extrn '__imp_MmAllocateNodePagesForMdlEx' as MmAllocateNodePagesForMdlEx:qword
            extrn '__imp_MmGetMaximumFileSectionSize' as MmGetMaximumFileSectionSize:qword
            extrn '__imp_MmIsDriverSuspectForVerifier' as MmIsDriverSuspectForVerifier:qword
            extrn '__imp_ObDuplicateObject' as ObDuplicateObject:qword
            extrn '__imp_ObReferenceObjectSafe' as ObReferenceObjectSafe:qword
            extrn '__imp_ObWaitForSingleObject' as ObWaitForSingleObject:qword
            extrn '__imp_PoFxActivateComponent' as PoFxActivateComponent:qword
            extrn '__imp_PoFxCompleteDevicePowerNotRequired' as PoFxCompleteDevicePowerNotRequired:qword
            extrn '__imp_PoFxCompleteIdleCondition' as PoFxCompleteIdleCondition:qword
            extrn '__imp_PoFxCompleteIdleState' as PoFxCompleteIdleState:qword
            extrn '__imp_PoFxIdleComponent' as PoFxIdleComponent:qword
            extrn '__imp_PoFxNotifySurprisePowerOn' as PoFxNotifySurprisePowerOn:qword
            extrn '__imp_PoFxPowerControl' as PoFxPowerControl:qword
            extrn '__imp_PoFxRegisterDevice' as PoFxRegisterDevice:qword
            extrn '__imp_PoFxReportDevicePoweredOn' as PoFxReportDevicePoweredOn:qword
            extrn '__imp_PoFxSetComponentLatency' as PoFxSetComponentLatency:qword
            extrn '__imp_PoFxSetComponentResidency' as PoFxSetComponentResidency:qword
            extrn '__imp_PoFxSetComponentWake' as PoFxSetComponentWake:qword
            extrn '__imp_PoFxSetDeviceIdleTimeout' as PoFxSetDeviceIdleTimeout:qword
            extrn '__imp_PoFxStartDevicePowerManagement' as PoFxStartDevicePowerManagement:qword
            extrn '__imp_PoFxUnregisterDevice' as PoFxUnregisterDevice:qword
            extrn '__imp_PsCreateSystemThreadEx' as PsCreateSystemThreadEx:qword
            extrn '__imp_PsGetThreadExitStatus' as PsGetThreadExitStatus:qword
            extrn '__imp_PsIsDiskCountersEnabled' as PsIsDiskCountersEnabled:qword
            extrn '__imp_PsQueryTotalCycleTimeProcess' as PsQueryTotalCycleTimeProcess:qword
            extrn '__imp_PsUpdateDiskCounters' as PsUpdateDiskCounters:qword
            extrn '__imp_RtlCheckPortableOperatingSystem' as RtlCheckPortableOperatingSystem:qword
            extrn '__imp_RtlCreateUserThread' as RtlCreateUserThread:qword
            extrn '__imp_RtlCultureNameToLCID' as RtlCultureNameToLCID:qword
            extrn '__imp_RtlDecompressBufferEx' as RtlDecompressBufferEx:qword
            extrn '__imp_RtlDeleteElementGenericTableAvlEx' as RtlDeleteElementGenericTableAvlEx:qword
            extrn '__imp_RtlOpenCurrentUser' as RtlOpenCurrentUser:qword
            extrn '__imp_RtlQueryInformationAcl' as RtlQueryInformationAcl:qword
            extrn '__imp_RtlRbInsertNodeEx' as RtlRbInsertNodeEx:qword
            extrn '__imp_RtlRbRemoveNode' as RtlRbRemoveNode:qword
            extrn '__imp_RtlSetControlSecurityDescriptor' as RtlSetControlSecurityDescriptor:qword
            extrn '__imp_TmInitializeTransactionManager' as TmInitializeTransactionManager:qword
            extrn '__imp_TmRenameTransactionManager' as TmRenameTransactionManager:qword
            extrn '__imp_TmSinglePhaseReject' as TmSinglePhaseReject:qword
            extrn '__imp_WheaRegisterInUsePageOfflineNotification' as WheaRegisterInUsePageOfflineNotification:qword
            extrn '__imp_WheaUnregisterInUsePageOfflineNotification' as WheaUnregisterInUsePageOfflineNotification:qword
            extrn '__imp_ZwFlushBuffersFileEx' as ZwFlushBuffersFileEx:qword
            extrn '__imp_ZwQuerySystemEnvironmentValueEx' as ZwQuerySystemEnvironmentValueEx:qword
            extrn '__imp_ZwSetInformationKey' as ZwSetInformationKey:qword
            extrn '__imp_ZwSetSystemEnvironmentValueEx' as ZwSetSystemEnvironmentValueEx:qword
            extrn '__imp_ZwUnlockVirtualMemory' as ZwUnlockVirtualMemory:qword
        end if

        if (NTDDI_VERSION >= NTDDI_WIN81)
            extrn '__imp_ExAllocateTimer' as ExAllocateTimer:qword
            extrn '__imp_ExCancelTimer' as ExCancelTimer:qword
            extrn '__imp_ExDeleteTimer' as ExDeleteTimer:qword
            extrn '__imp_ExSetTimer' as ExSetTimer:qword
            extrn '__imp_FsRtlUpperOplockFsctrl' as FsRtlUpperOplockFsctrl:qword
            extrn '__imp_IoQueryFullDriverPath' as IoQueryFullDriverPath:qword
            extrn '__imp_MmCopyMemory' as MmCopyMemory:qword
            extrn '__imp_MmMdlPagesAreZero' as MmMdlPagesAreZero:qword
            extrn '__imp_PoFxPowerOnCrashdumpDevice' as PoFxPowerOnCrashdumpDevice:qword
            extrn '__imp_PoFxRegisterCrashdumpDevice' as PoFxRegisterCrashdumpDevice:qword
            extrn '__imp_SeAdjustAccessStateForTrustLabel' as SeAdjustAccessStateForTrustLabel:qword
            extrn '__imp_SeShouldCheckForAccessRightsFromParent' as SeShouldCheckForAccessRightsFromParent:qword
            extrn '__imp_ZwAssociateWaitCompletionPacket' as ZwAssociateWaitCompletionPacket:qword
            extrn '__imp_ZwCancelIoFileEx' as ZwCancelIoFileEx:qword
            extrn '__imp_ZwCreateWaitCompletionPacket' as ZwCreateWaitCompletionPacket:qword
            extrn '__imp_ZwLockVirtualMemory' as ZwLockVirtualMemory:qword
            extrn '__imp_ZwQuerySystemInformationEx' as ZwQuerySystemInformationEx:qword
        end if

        if (NTDDI_VERSION >= NTDDI_WIN10)
            extrn '__imp__finite' as _finite:qword
            extrn '__imp__wcslwr_s' as _wcslwr_s:qword
            extrn '__imp_CcAsyncCopyRead' as CcAsyncCopyRead:qword
            extrn '__imp_ExIsManufacturingModeEnabled' as ExIsManufacturingModeEnabled:qword
            extrn '__imp_IoClearFsTrackOffsetState' as IoClearFsTrackOffsetState:qword
            extrn '__imp_IoGetSiloParameters' as IoGetSiloParameters:qword
            extrn '__imp_IoInitializeIrpEx' as IoInitializeIrpEx:qword
            extrn '__imp_IoIrpHasFsTrackOffsetExtensionType' as IoIrpHasFsTrackOffsetExtensionType:qword
            extrn '__imp_IoRequestDeviceRemovalForReset' as IoRequestDeviceRemovalForReset:qword
            extrn '__imp_IoSetFsTrackOffsetState' as IoSetFsTrackOffsetState:qword
            extrn '__imp_IoSetFsZeroingOffset' as IoSetFsZeroingOffset:qword
            extrn '__imp_IoSetFsZeroingOffsetRequired' as IoSetFsZeroingOffsetRequired:qword
            extrn '__imp_IoSizeOfIrpEx' as IoSizeOfIrpEx:qword
            extrn '__imp_IoVolumeDeviceNameToGuid' as IoVolumeDeviceNameToGuid:qword
            extrn '__imp_KeConvertAuxiliaryCounterToPerformanceCounter' as KeConvertAuxiliaryCounterToPerformanceCounter:qword
            extrn '__imp_KeConvertPerformanceCounterToAuxiliaryCounter' as KeConvertPerformanceCounterToAuxiliaryCounter:qword
            extrn '__imp_KeDeregisterBoundCallback' as KeDeregisterBoundCallback:qword
            extrn '__imp_KeFlushIoBuffers' as KeFlushIoBuffers:qword
            extrn '__imp_KeQueryAuxiliaryCounterFrequency' as KeQueryAuxiliaryCounterFrequency:qword
            extrn '__imp_KeRegisterBoundCallback' as KeRegisterBoundCallback:qword
            extrn '__imp_KeShouldYieldProcessor' as KeShouldYieldProcessor:qword
            extrn '__imp_MmLoadSystemImage' as MmLoadSystemImage:qword
            extrn '__imp_MmMapIoSpaceEx' as MmMapIoSpaceEx:qword
            extrn '__imp_MmUnloadSystemImage' as MmUnloadSystemImage:qword
            extrn '__imp_PoCreateThermalRequest' as PoCreateThermalRequest:qword
            extrn '__imp_PoDeleteThermalRequest' as PoDeleteThermalRequest:qword
            extrn '__imp_PoFxIssueComponentPerfStateChange' as PoFxIssueComponentPerfStateChange:qword
            extrn '__imp_PoFxIssueComponentPerfStateChangeMultiple' as PoFxIssueComponentPerfStateChangeMultiple:qword
            extrn '__imp_PoFxQueryCurrentComponentPerfState' as PoFxQueryCurrentComponentPerfState:qword
            extrn '__imp_PoFxRegisterComponentPerfStates' as PoFxRegisterComponentPerfStates:qword
            extrn '__imp_PoGetThermalRequestSupport' as PoGetThermalRequestSupport:qword
            extrn '__imp_PoSetThermalActiveCooling' as PoSetThermalActiveCooling:qword
            extrn '__imp_PoSetThermalPassiveCooling' as PoSetThermalPassiveCooling:qword
            extrn '__imp_PsAllocateMonitorContextServerSilo' as PsAllocateMonitorContextServerSilo:qword
            extrn '__imp_PsAttachSiloToCurrentThread' as PsAttachSiloToCurrentThread:qword
            extrn '__imp_PsDeleteMonitorContextServerSilo' as PsDeleteMonitorContextServerSilo:qword
            extrn '__imp_PsDereferenceMonitorContextServerSilo' as PsDereferenceMonitorContextServerSilo:qword
            extrn '__imp_PsDetachSiloFromCurrentThread' as PsDetachSiloFromCurrentThread:qword
            extrn '__imp_PsDeleteMonitorContextServerSilo' as PsDeleteMonitorContextServerSilo:qword
            extrn '__imp_PsDereferenceMonitorContextServerSilo' as PsDereferenceMonitorContextServerSilo:qword
            extrn '__imp_PsDetachSiloFromCurrentThread' as PsDetachSiloFromCurrentThread:qword
            extrn '__imp_PsEqualCurrentServerSilo' as PsEqualCurrentServerSilo:qword
            extrn '__imp_PsEqualCurrentSilo' as PsEqualCurrentSilo:qword
            extrn '__imp_PsGetCurrentServerSilo' as PsGetCurrentServerSilo:qword
            extrn '__imp_PsGetCurrentServerSiloName' as PsGetCurrentServerSiloName:qword
            extrn '__imp_PsGetCurrentSilo' as PsGetCurrentSilo:qword
            extrn '__imp_PsGetCurrentSiloObject' as PsGetCurrentSiloObject:qword
            extrn '__imp_PsGetJobServerSilo' as PsGetJobServerSilo:qword
            extrn '__imp_PsGetMonitorContextServerSilo' as PsGetMonitorContextServerSilo:qword
            extrn '__imp_PsGetServerSiloServiceSessionId' as PsGetServerSiloServiceSessionId:qword
            extrn '__imp_PsGetSiloObjectFromJob' as PsGetSiloObjectFromJob:qword
            extrn '__imp_PsGetThreadCreateTime' as PsGetThreadCreateTime:qword
            extrn '__imp_PsGetThreadProperty' as PsGetThreadProperty:qword
            extrn '__imp_PsInsertSiloObjectFromJob' as PsInsertSiloObjectFromJob:qword
            extrn '__imp_PsIsCurrentThreadInServerSilo' as PsIsCurrentThreadInServerSilo:qword
            extrn '__imp_PsIsHostSilo' as PsIsHostSilo:qword
            extrn '__imp_PsReferenceMonitorContextServerSilo' as PsReferenceMonitorContextServerSilo:qword
            extrn '__imp_PsRegisterMonitorServerSilo' as PsRegisterMonitorServerSilo:qword
            extrn '__imp_PsRegisterPicoProvider' as PsRegisterPicoProvider:qword
            extrn '__imp_PsRemoveSiloObjectFromJob' as PsRemoveSiloObjectFromJob:qword
            extrn '__imp_PsSetCreateThreadNotifyRoutineEx' as PsSetCreateThreadNotifyRoutineEx:qword
            extrn '__imp_PsSetMonitorContextServerSilo' as PsSetMonitorContextServerSilo:qword
            extrn '__imp_PsStartMonitorServerSilo' as PsStartMonitorServerSilo:qword
            extrn '__imp_PsUnregisterMonitorServerSilo' as PsUnregisterMonitorServerSilo:qword
            extrn '__imp_RtlAddAccessDeniedAceEx' as RtlAddAccessDeniedAceEx:qword
            extrn '__imp_RtlAddAccessDeniedObjectAce' as RtlAddAccessDeniedObjectAce:qword
            extrn '__imp_RtlAddAuditAccessAceEx' as RtlAddAuditAccessAceEx:qword
            extrn '__imp_RtlAddAuditAccessObjectAce' as RtlAddAuditAccessObjectAce:qword
            extrn '__imp_RtlDecompressBufferEx2' as RtlDecompressBufferEx2:qword
            extrn '__imp_RtlDecompressFragmentEx' as RtlDecompressFragmentEx:qword
            extrn '__imp_RtlEndStrongEnumerationHashTable' as RtlEndStrongEnumerationHashTable:qword
            extrn '__imp_RtlFirstFreeAce' as RtlFirstFreeAce:qword
            extrn '__imp_RtlGetControlSecurityDescriptor' as RtlGetControlSecurityDescriptor:qword
            extrn '__imp_RtlInitializeSidEx' as RtlInitializeSidEx:qword
            extrn '__imp_RtlInitStringEx' as RtlInitStringEx:qword
            extrn '__imp_RtlInitStrongEnumerationHashTable' as RtlInitStrongEnumerationHashTable:qword
            extrn '__imp_RtlLargeIntegerToChar' as RtlLargeIntegerToChar:qword
            extrn '__imp_RtlOsDeploymentState' as RtlOsDeploymentState:qword
            extrn '__imp_RtlStronglyEnumerateEntryHashTable' as RtlStronglyEnumerateEntryHashTable:qword
            extrn '__imp_RtlSuffixUnicodeString' as RtlSuffixUnicodeString:qword
            extrn '__imp_RtlUnicodeStringToInt64' as RtlUnicodeStringToInt64:qword
            extrn '__imp_RtlValidAcl' as RtlValidAcl:qword
            extrn '__imp_SeAuditFipsCryptoSelftests' as SeAuditFipsCryptoSelftests:qword
            extrn '__imp_SeMarkLogonSessionForTerminationNotificationEx' as SeMarkLogonSessionForTerminationNotificationEx:qword
            extrn '__imp_SeQuerySessionIdTokenEx' as SeQuerySessionIdTokenEx:qword
            extrn '__imp_SeRegisterLogonSessionTerminatedRoutineEx' as SeRegisterLogonSessionTerminatedRoutineEx:qword
            extrn '__imp_SeUnregisterLogonSessionTerminatedRoutineEx' as SeUnregisterLogonSessionTerminatedRoutineEx:qword
            extrn '__imp_ZwAlpcOpenSenderThread' as ZwAlpcOpenSenderThread:qword
            extrn '__imp_ZwAlpcQueryInformationMessage' as ZwAlpcQueryInformationMessage:qword
            extrn '__imp_ZwCompareTokens' as ZwCompareTokens:qword
            extrn '__imp_ZwGetCachedSigningLevel' as ZwGetCachedSigningLevel:qword
            extrn '__imp_ZwGetNextProcess' as ZwGetNextProcess:qword
            extrn '__imp_ZwNotifyChangeDirectoryFile' as ZwNotifyChangeDirectoryFile:qword
            extrn '__imp_ZwTraceControl' as ZwTraceControl:qword
            extrn '__imp_ZwUnloadKey2' as ZwUnloadKey2:qword
        end if
    end if
else
    if (NTDDI_VERSION >= NTDDI_WINNT4)
        if ~defined __imp__atoi
            extrn '__imp__atoi@4' as atoi:dword
        end if
        if ~defined __imp__atol
            extrn '__imp__atol@4' as atol:dword
        end if
        extrn '__imp__CcCanIWrite@16' as CcCanIWrite:dword
        extrn '__imp__CcCopyRead@24' as CcCopyRead:dword
        extrn '__imp__CcCopyWrite@20' as CcCopyWrite:dword
        extrn '__imp__CcDeferWrite@24' as CcDeferWrite:dword
        extrn '__imp__CcFastCopyRead@24' as CcFastCopyRead:dword
        extrn '__imp__CcFastCopyWrite@16' as CcFastCopyWrite:dword
        extrn '__imp__CcFastMdlReadWait@0' as CcFastMdlReadWait:dword
        if (NTDDI_VERSION < NTDDI_VISTA)
            extrn '__imp__CcFastReadWait@0' as CcFastReadWait:dword
        end if
        extrn '__imp__CcFlushCache@16' as CcFlushCache:dword
        extrn '__imp__CcGetDirtyPages@16' as CcGetDirtyPages:dword
        extrn '__imp__CcGetFileObjectFromBcb@4' as CcGetFileObjectFromBcb:dword
        extrn '__imp__CcGetFileObjectFromSectionPtrs@4' as CcGetFileObjectFromSectionPtrs:dword
        extrn '__imp__CcGetLsnForFileObject@8' as CcGetLsnForFileObject:dword
        extrn '__imp__CcInitializeCacheMap@20' as CcInitializeCacheMap:dword
        extrn '__imp__CcIsThereDirtyData@4' as CcIsThereDirtyData:dword
        extrn '__imp__CcMapData@24' as CcMapData:dword
        extrn '__imp__CcMdlRead@20' as CcMdlRead:dword
        extrn '__imp__CcMdlReadComplete@8' as CcMdlReadComplete:dword
        extrn '__imp__CcMdlWriteComplete@12' as CcMdlWriteComplete:dword
        extrn '__imp__CcPinMappedData@20' as CcPinMappedData:dword
        extrn '__imp__CcPinRead@24' as CcPinRead:dword
        extrn '__imp__CcPrepareMdlWrite@20' as CcPrepareMdlWrite:dword
        extrn '__imp__CcPreparePinWrite@28' as CcPreparePinWrite:dword
        extrn '__imp__CcPurgeCacheSection@16' as CcPurgeCacheSection:dword
        extrn '__imp__CcRepinBcb@4' as CcRepinBcb:dword
        extrn '__imp__CcScheduleReadAhead@12' as CcScheduleReadAhead:dword
        extrn '__imp__CcSetAdditionalCacheAttributes@12' as CcSetAdditionalCacheAttributes:dword
        extrn '__imp__CcSetBcbOwnerPointer@8' as CcSetBcbOwnerPointer:dword
        extrn '__imp__CcSetDirtyPageThreshold@8' as CcSetDirtyPageThreshold:dword
        extrn '__imp__CcSetDirtyPinnedData@8' as CcSetDirtyPinnedData:dword
        extrn '__imp__CcSetFileSizes@8' as CcSetFileSizes:dword
        extrn '__imp__CcSetLogHandleForFile@12' as CcSetLogHandleForFile:dword
        extrn '__imp__CcSetReadAheadGranularity@8' as CcSetReadAheadGranularity:dword
        extrn '__imp__CcUninitializeCacheMap@12' as CcUninitializeCacheMap:dword
        extrn '__imp__CcUnpinData@4' as CcUnpinData:dword
        extrn '__imp__CcUnpinDataForThread@8' as CcUnpinDataForThread:dword
        extrn '__imp__CcUnpinRepinnedBcb@12' as CcUnpinRepinnedBcb:dword
        extrn '__imp__CcZeroData@16' as CcZeroData:dword
        extrn '__imp__DbgBreakPoint@0' as DbgBreakPoint:dword
        extrn '__imp__DbgBreakPointWithStatus@4' as DbgBreakPointWithStatus:dword
        extrn '__imp__DbgLoadImageSymbols@12' as DbgLoadImageSymbols:dword
        extrn '__imp__DbgPrint@8' as DbgPrint:dword
        extrn '__imp__DbgPrompt@12' as DbgPrompt:dword
        extrn '__imp__ExAcquireFastMutexUnsafe@4' as ExAcquireFastMutexUnsafe:dword
        extrn '__imp__ExAcquireResourceExclusiveLite@8' as ExAcquireResourceExclusiveLite:dword
        extrn '__imp__ExAcquireResourceSharedLite@8' as ExAcquireResourceSharedLite:dword
        extrn '__imp__ExAcquireSharedStarveExclusive@8' as ExAcquireSharedStarveExclusive:dword
        extrn '__imp__ExAcquireSharedWaitForExclusive@8' as ExAcquireSharedWaitForExclusive:dword
        extrn '__imp__ExAllocatePool@8' as ExAllocatePool:dword
        extrn '__imp__ExAllocatePoolWithQuota@8' as ExAllocatePoolWithQuota:dword
        extrn '__imp__ExAllocatePoolWithQuotaTag@12' as ExAllocatePoolWithQuotaTag:dword
        extrn '__imp__ExAllocatePoolWithTag@12' as ExAllocatePoolWithTag:dword
        extrn '__imp__ExAllocatePoolWithTagPriority@16' as ExAllocatePoolWithTagPriority:dword
        extrn '__imp__ExConvertExclusiveToSharedLite@4' as ExConvertExclusiveToSharedLite:dword
        extrn '__imp__ExCreateCallback@16' as ExCreateCallback:dword
        extrn '__imp__ExDeleteNPagedLookasideList@4' as ExDeleteNPagedLookasideList:dword
        extrn '__imp__ExDeletePagedLookasideList@4' as ExDeletePagedLookasideList:dword
        extrn '__imp__ExDeleteResourceLite@4' as ExDeleteResourceLite:dword
        extrn '__imp__ExDisableResourceBoostLite@4' as ExDisableResourceBoostLite:dword
        extrn '__imp__ExEnumHandleTable@16' as ExEnumHandleTable:dword
        extrn '__imp__ExExtendZone@12' as ExExtendZone:dword
        extrn '__imp__ExFreePool@4' as ExFreePool:dword
        if (NTDDI_VERSION < NTDDI_WIN2K & NTDDI_VERSION < NTDDI_WIN8)
            extrn '__imp__KeQueryInterruptTime@0' as KeQueryInterruptTime:dword
        end if
        if (NTDDI_VERSION < NTDDI_VISTA)
            extrn '__imp__KeConnectInterrupt@4' as KeConnectInterrupt:dword
            extrn '__imp__KeDisconnectInterrupt@4' as KeDisconnectInterrupt:dword
        else if (NTDDI_VERSION < NTDDI_WIN7)
            extrn '__imp__Exfi386InterlockedDecrementLong@4' as Exfi386InterlockedDecrementLong:dword
            extrn '__imp__Exfi386InterlockedExchangeUlong@8' as Exfi386InterlockedExchangeUlong:dword
            extrn '__imp__Exfi386InterlockedIncrementLong@4' as Exfi386InterlockedIncrementLong:dword
            extrn '__imp__ExfInterlockedAddUlong@12' as ExfInterlockedAddUlong:dword
            if (NTDDI_VERSION >= NTDDI_WINXP)
                extrn '__imp__ExfInterlockedCompareExchange64@12' as ExfInterlockedCompareExchange64:dword
            end if
            extrn '__imp__ExfInterlockedInsertHeadList@12' as ExfInterlockedInsertHeadList:dword
            extrn '__imp__ExfInterlockedInsertTailList@12' as ExfInterlockedInsertTailList:dword
            extrn '__imp__ExfInterlockedPopEntryList@8' as ExfInterlockedPopEntryList:dword
            extrn '__imp__ExfInterlockedPushEntryList@8' as ExfInterlockedPushEntryList:dword
            extrn '__imp__ExfInterlockedRemoveHeadList@8' as ExfInterlockedRemoveHeadList:dword
            extrn '__imp__ExInterlockedAddLargeStatistic@8' as ExInterlockedAddLargeStatistic:dword
            extrn '__imp__ExInterlockedCompareExchange64@12' as ExInterlockedCompareExchange64:dword
            extrn '__imp__ExInterlockedFlushSList@4' as ExInterlockedFlushSList:dword
            extrn '__imp__ExInterlockedPopEntrySList@8' as ExInterlockedPopEntrySList:dword
            extrn '__imp__ExInterlockedPushEntrySList@12' as ExInterlockedPushEntrySList:dword
            if (NTDDI_VERSION = NTDDI_VISTA)
                extrn '__imp__ExiReleaseFastMutex@4' as ExiReleaseFastMutex:dword
                extrn '__imp__ExiTryToAcquireFastMutex@4' as ExiTryToAcquireFastMutex:dword
            end if
            extrn '__imp__InterlockedCompareExchange@12' as InterlockedCompareExchange:dword
            extrn '__imp__InterlockedDecrement@4' as InterlockedDecrement:dword
            extrn '__imp__InterlockedExchange@8' as InterlockedExchange:dword
            extrn '__imp__InterlockedExchangeAdd@8' as InterlockedExchangeAdd:dword
            extrn '__imp__InterlockedIncrement@4' as InterlockedIncrement:dword
            extrn '__imp__InterlockedPopEntrySList@4' as InterlockedPopEntrySList:dword
            extrn '__imp__InterlockedPushEntrySList@8' as InterlockedPushEntrySList:dword
            extrn '__imp__IoPnPDeliverServicePowerNotification@16' as IoPnPDeliverServicePowerNotification:dword
            extrn '__imp__KefAcquireSpinLockAtDpcLevel@4' as KefAcquireSpinLockAtDpcLevel:dword
            extrn '__imp__KefReleaseSpinLockFromDpcLevel@4' as KefReleaseSpinLockFromDpcLevel:dword
            extrn '__imp__KeTerminateThread@4' as KeTerminateThread:dword
            extrn '__imp__KiAcquireSpinLock@4' as KiAcquireSpinLock:dword
            extrn '__imp__Kii386SpinOnSpinLock@8' as Kii386SpinOnSpinLock:dword
            extrn '__imp__KiReleaseSpinLock@4' as KiReleaseSpinLock:dword
            extrn '__imp__RtlUlongByteSwap@4' as RtlUlongByteSwap:dword
            extrn '__imp__RtlUlonglongByteSwap@8' as RtlUlonglongByteSwap:dword
            extrn '__imp__RtlUshortByteSwap@4' as RtlUshortByteSwap:dword
        else if (NTDDI_VERSION <= NTDDI_WIN7)
            extrn '__imp__RtlConvertLongToLargeInteger@4' as RtlConvertLongToLargeInteger:dword
            extrn '__imp__RtlConvertUlongToLargeInteger@4' as RtlConvertUlongToLargeInteger:dword
            extrn '__imp__RtlEnlargedIntegerMultiply@8' as RtlEnlargedIntegerMultiply:dword
            extrn '__imp__RtlEnlargedUnsignedDivide@16' as RtlEnlargedUnsignedDivide:dword
            extrn '__imp__RtlEnlargedUnsignedMultiply@8' as RtlEnlargedUnsignedMultiply:dword
            extrn '__imp__RtlExtendedIntegerMultiply@12' as RtlExtendedIntegerMultiply:dword
            extrn '__imp__RtlExtendedLargeIntegerDivide@16' as RtlExtendedLargeIntegerDivide:dword
            extrn '__imp__RtlExtendedMagicDivide@20' as RtlExtendedMagicDivide:dword
            extrn '__imp__RtlFillMemoryUlong@12' as RtlFillMemoryUlong:dword
            extrn '__imp__RtlLargeIntegerArithmeticShift@12' as RtlLargeIntegerArithmeticShift:dword
            extrn '__imp__RtlLargeIntegerDivide@20' as RtlLargeIntegerDivide:dword
            extrn '__imp__RtlLargeIntegerNegate@8' as RtlLargeIntegerNegate:dword
            extrn '__imp__RtlLargeIntegerShiftLeft@12' as RtlLargeIntegerShiftLeft:dword
            extrn '__imp__RtlLargeIntegerShiftRight@12' as RtlLargeIntegerShiftRight:dword
            extrn '__imp__RtlLargeIntegerSubtract@16' as RtlLargeIntegerSubtract:dword
        else if (NTDDI_VERSION >= NTDDI_WIN7 & NTDDI_VERSION < NTDDI_WIN8)
            extrn '__imp__ExFreeToPagedLookasideList@8' as ExFreeToPagedLookasideList:dword
            extrn '__imp__Exi386InterlockedDecrementLong@4' as Exi386InterlockedDecrementLong:dword
            extrn '__imp__Exi386InterlockedExchangeUlong@8' as Exi386InterlockedExchangeUlong:dword
            extrn '__imp__Exi386InterlockedIncrementLong@4' as Exi386InterlockedIncrementLong:dword
            extrn '__imp__ExInterlockedDecrementLong@8' as ExInterlockedDecrementLong:dword
            extrn '__imp__ExInterlockedExchangeUlong@12' as ExInterlockedExchangeUlong:dword
            extrn '__imp__ExInterlockedIncrementLong@8' as ExInterlockedIncrementLong:dword
            extrn '__imp__Ke386CallBios@8' as Ke386CallBios:dword
            extrn '__imp__Ke386IoSetAccessProcess@8' as Ke386IoSetAccessProcess:dword
            extrn '__imp__Ke386QueryIoAccessMap@8' as Ke386QueryIoAccessMap:dword
            extrn '__imp__Ke386SetIoAccessMap@8' as Ke386SetIoAccessMap:dword
            extrn '__imp__KeGetPreviousMode@0' as KeGetPreviousMode:dword
            extrn '__imp__KeI386AbiosCall@16' as KeI386AbiosCall:dword
            extrn '__imp__KeI386AllocateGdtSelectors@8' as KeI386AllocateGdtSelectors:dword
            extrn '__imp__KeI386Call16BitFunction@4' as KeI386Call16BitFunction:dword
            extrn '__imp__KeI386FlatToGdtSelector@12' as KeI386FlatToGdtSelector:dword
            extrn '__imp__KeI386GetLid@20' as KeI386GetLid:dword
            extrn '__imp__KeI386ReleaseGdtSelectors@8' as KeI386ReleaseGdtSelectors:dword
            extrn '__imp__KeI386ReleaseLid@8' as KeI386ReleaseLid:dword
            extrn '__imp__KeI386SetGdtSelector@8' as KeI386SetGdtSelector:dword
            extrn '__imp__KeProfileInterrupt@4' as KeProfileInterrupt:dword
            extrn '__imp__KeQuerySystemTime@4' as KeQuerySystemTime:dword
            extrn '__imp__KeQueryTickCount@4' as KeQueryTickCount:dword
            extrn '__imp__KiCoprocessorError@0' as KiCoprocessorError:dword
            extrn '__imp__KiDeliverApc@12' as KiDeliverApc:dword
            extrn '__imp__KiIpiServiceRoutine@8' as KiIpiServiceRoutine:dword
            extrn '__imp__READ_REGISTER_BUFFER_UCHAR@12' as READ_REGISTER_BUFFER_UCHAR:dword
            extrn '__imp__READ_REGISTER_BUFFER_ULONG@12' as READ_REGISTER_BUFFER_ULONG:dword
            extrn '__imp__READ_REGISTER_BUFFER_USHORT@12' as READ_REGISTER_BUFFER_USHORT:dword
            extrn '__imp__READ_REGISTER_UCHAR@4' as READ_REGISTER_UCHAR:dword
            extrn '__imp__READ_REGISTER_ULONG@4' as READ_REGISTER_ULONG:dword
            extrn '__imp__READ_REGISTER_USHORT@4' as READ_REGISTER_USHORT:dword
        else if (NTDDI_VERSION >= NTDDI_WIN7)
            extrn '__imp__KeInitializeSpinLock@4' as KeInitializeSpinLock:dword
        end if
        extrn '__imp__ExGetExclusiveWaiterCount@4' as ExGetExclusiveWaiterCount:dword
        extrn '__imp__ExGetPreviousMode@0' as ExGetPreviousMode:dword
        extrn '__imp__ExGetSharedWaiterCount@4' as ExGetSharedWaiterCount:dword
        extrn '__imp__ExInitializeNPagedLookasideList@28' as ExInitializeNPagedLookasideList:dword
        extrn '__imp__ExInitializePagedLookasideList@28' as ExInitializePagedLookasideList:dword
        extrn '__imp__ExInitializeResourceLite@4' as ExInitializeResourceLite:dword
        extrn '__imp__ExInitializeZone@16' as ExInitializeZone:dword
        extrn '__imp__ExInterlockedAddLargeInteger@16' as ExInterlockedAddLargeInteger:dword
        extrn '__imp__ExInterlockedAddUlong@12' as ExInterlockedAddUlong:dword
        extrn '__imp__ExInterlockedExtendZone@16' as ExInterlockedExtendZone:dword
        extrn '__imp__ExInterlockedInsertHeadList@12' as ExInterlockedInsertHeadList:dword
        extrn '__imp__ExInterlockedInsertTailList@12' as ExInterlockedInsertTailList:dword
        extrn '__imp__ExInterlockedPopEntryList@8' as ExInterlockedPopEntryList:dword
        extrn '__imp__ExInterlockedPushEntryList@12' as ExInterlockedPushEntryList:dword
        extrn '__imp__ExInterlockedRemoveHeadList@8' as ExInterlockedRemoveHeadList:dword
        extrn '__imp__ExIsProcessorFeaturePresent@4' as ExIsProcessorFeaturePresent:dword
        extrn '__imp__ExIsResourceAcquiredExclusiveLite@4' as ExIsResourceAcquiredExclusiveLite:dword
        extrn '__imp__ExIsResourceAcquiredSharedLite@4' as ExIsResourceAcquiredSharedLite:dword
        extrn '__imp__ExLocalTimeToSystemTime@8' as ExLocalTimeToSystemTime:dword
        extrn '__imp__ExNotifyCallback@12' as ExNotifyCallback:dword
        extrn '__imp__ExQueryPoolBlockSize@8' as ExQueryPoolBlockSize:dword
        extrn '__imp__ExQueueWorkItem@8' as ExQueueWorkItem:dword
        extrn '__imp__ExRaiseAccessViolation@0' as ExRaiseAccessViolation:dword
        extrn '__imp__ExRaiseDatatypeMisalignment@0' as ExRaiseDatatypeMisalignment:dword
        extrn '__imp__ExRaiseException@4' as ExRaiseException:dword
        extrn '__imp__ExRaiseHardError@24' as ExRaiseHardError:dword
        extrn '__imp__ExRaiseStatus@4' as ExRaiseStatus:dword
        extrn '__imp__ExRegisterCallback@12' as ExRegisterCallback:dword
        extrn '__imp__ExReinitializeResourceLite@4' as ExReinitializeResourceLite:dword
        extrn '__imp__ExReleaseFastMutexUnsafe@4' as ExReleaseFastMutexUnsafe:dword
        extrn '__imp__ExReleaseResourceForThreadLite@8' as ExReleaseResourceForThreadLite:dword
        extrn '__imp__ExReleaseResourceLite@4' as ExReleaseResourceLite:dword
        extrn '__imp__ExSetResourceOwnerPointer@8' as ExSetResourceOwnerPointer:dword
        extrn '__imp__ExSystemExceptionFilter@0' as ExSystemExceptionFilter:dword
        extrn '__imp__ExSystemTimeToLocalTime@8' as ExSystemTimeToLocalTime:dword
        extrn '__imp__ExUnregisterCallback@4' as ExUnregisterCallback:dword
        extrn '__imp__FsRtlAddLargeMcbEntry@28' as FsRtlAddLargeMcbEntry:dword
        extrn '__imp__FsRtlAddMcbEntry@16' as FsRtlAddMcbEntry:dword
        extrn '__imp__FsRtlAddToTunnelCache@32' as FsRtlAddToTunnelCache:dword
        extrn '__imp__FsRtlAllocatePool@8' as FsRtlAllocatePool:dword
        extrn '__imp__FsRtlAllocatePoolWithQuota@8' as FsRtlAllocatePoolWithQuota:dword
        extrn '__imp__FsRtlAllocatePoolWithQuotaTag@12' as FsRtlAllocatePoolWithQuotaTag:dword
        extrn '__imp__FsRtlAllocatePoolWithTag@12' as FsRtlAllocatePoolWithTag:dword
        extrn '__imp__FsRtlAllocateResource@0' as FsRtlAllocateResource:dword
        extrn '__imp__FsRtlAreNamesEqual@16' as FsRtlAreNamesEqual:dword
        extrn '__imp__FsRtlBalanceReads@4' as FsRtlBalanceReads:dword
        extrn '__imp__FsRtlCheckLockForReadAccess@8' as FsRtlCheckLockForReadAccess:dword
        extrn '__imp__FsRtlCheckLockForWriteAccess@8' as FsRtlCheckLockForWriteAccess:dword
        extrn '__imp__FsRtlCheckOplock@20' as FsRtlCheckOplock:dword
        extrn '__imp__FsRtlCopyRead@32' as FsRtlCopyRead:dword
        extrn '__imp__FsRtlCopyWrite@32' as FsRtlCopyWrite:dword
        extrn '__imp__FsRtlCurrentBatchOplock@4' as FsRtlCurrentBatchOplock:dword
        extrn '__imp__FsRtlDeleteKeyFromTunnelCache@12' as FsRtlDeleteKeyFromTunnelCache:dword
        extrn '__imp__FsRtlDeleteTunnelCache@4' as FsRtlDeleteTunnelCache:dword
        extrn '__imp__FsRtlDeregisterUncProvider@4' as FsRtlDeregisterUncProvider:dword
        extrn '__imp__FsRtlDissectDbcs@16' as FsRtlDissectDbcs:dword
        extrn '__imp__FsRtlDissectName@16' as FsRtlDissectName:dword
        extrn '__imp__FsRtlDoesDbcsContainWildCards@4' as FsRtlDoesDbcsContainWildCards:dword
        extrn '__imp__FsRtlDoesNameContainWildCards@4' as FsRtlDoesNameContainWildCards:dword
        extrn '__imp__FsRtlFastCheckLockForRead@24' as FsRtlFastCheckLockForRead:dword
        extrn '__imp__FsRtlFastCheckLockForWrite@24' as FsRtlFastCheckLockForWrite:dword
        extrn '__imp__FsRtlFastUnlockAll@16' as FsRtlFastUnlockAll:dword
        extrn '__imp__FsRtlFastUnlockAllByKey@20' as FsRtlFastUnlockAllByKey:dword
        extrn '__imp__FsRtlFastUnlockSingle@32' as FsRtlFastUnlockSingle:dword
        extrn '__imp__FsRtlFindInTunnelCache@32' as FsRtlFindInTunnelCache:dword
        extrn '__imp__FsRtlGetFileSize@8' as FsRtlGetFileSize:dword
        extrn '__imp__FsRtlGetNextFileLock@8' as FsRtlGetNextFileLock:dword
        extrn '__imp__FsRtlGetNextLargeMcbEntry@20' as FsRtlGetNextLargeMcbEntry:dword
        extrn '__imp__FsRtlGetNextMcbEntry@20' as FsRtlGetNextMcbEntry:dword
        extrn '__imp__FsRtlInitializeFileLock@12' as FsRtlInitializeFileLock:dword
        extrn '__imp__FsRtlInitializeLargeMcb@8' as FsRtlInitializeLargeMcb:dword
        extrn '__imp__FsRtlInitializeMcb@8' as FsRtlInitializeMcb:dword
        extrn '__imp__FsRtlInitializeOplock@4' as FsRtlInitializeOplock:dword
        extrn '__imp__FsRtlInitializeTunnelCache@4' as FsRtlInitializeTunnelCache:dword
        extrn '__imp__FsRtlIsDbcsInExpression@8' as FsRtlIsDbcsInExpression:dword
        extrn '__imp__FsRtlIsFatDbcsLegal@20' as FsRtlIsFatDbcsLegal:dword
        extrn '__imp__FsRtlIsHpfsDbcsLegal@20' as FsRtlIsHpfsDbcsLegal:dword
        extrn '__imp__FsRtlIsNameInExpression@16' as FsRtlIsNameInExpression:dword
        extrn '__imp__FsRtlIsNtstatusExpected@4' as FsRtlIsNtstatusExpected:dword
        extrn '__imp__FsRtlIsTotalDeviceFailure@4' as FsRtlIsTotalDeviceFailure:dword
        extrn '__imp__FsRtlLookupLargeMcbEntry@32' as FsRtlLookupLargeMcbEntry:dword
        extrn '__imp__FsRtlLookupLastLargeMcbEntry@12' as FsRtlLookupLastLargeMcbEntry:dword
        extrn '__imp__FsRtlLookupLastMcbEntry@12' as FsRtlLookupLastMcbEntry:dword
        extrn '__imp__FsRtlLookupMcbEntry@20' as FsRtlLookupMcbEntry:dword
        extrn '__imp__FsRtlMdlRead@24' as FsRtlMdlRead:dword
        extrn '__imp__FsRtlMdlReadComplete@8' as FsRtlMdlReadComplete:dword
        extrn '__imp__FsRtlMdlReadCompleteDev@12' as FsRtlMdlReadCompleteDev:dword
        extrn '__imp__FsRtlMdlReadDev@28' as FsRtlMdlReadDev:dword
        extrn '__imp__FsRtlMdlWriteComplete@12' as FsRtlMdlWriteComplete:dword
        extrn '__imp__FsRtlMdlWriteCompleteDev@16' as FsRtlMdlWriteCompleteDev:dword
        extrn '__imp__FsRtlNormalizeNtstatus@8' as FsRtlNormalizeNtstatus:dword
        extrn '__imp__FsRtlNotifyChangeDirectory@28' as FsRtlNotifyChangeDirectory:dword
        extrn '__imp__FsRtlNotifyCleanup@12' as FsRtlNotifyCleanup:dword
        extrn '__imp__FsRtlNotifyFullChangeDirectory@40' as FsRtlNotifyFullChangeDirectory:dword
        extrn '__imp__FsRtlNotifyFullReportChange@36' as FsRtlNotifyFullReportChange:dword
        extrn '__imp__FsRtlNotifyInitializeSync@4' as FsRtlNotifyInitializeSync:dword
        extrn '__imp__FsRtlNotifyReportChange@20' as FsRtlNotifyReportChange:dword
        extrn '__imp__FsRtlNotifyUninitializeSync@4' as FsRtlNotifyUninitializeSync:dword
        extrn '__imp__FsRtlNumberOfRunsInLargeMcb@4' as FsRtlNumberOfRunsInLargeMcb:dword
        extrn '__imp__FsRtlNumberOfRunsInMcb@4' as FsRtlNumberOfRunsInMcb:dword
        extrn '__imp__FsRtlOplockFsctrl@12' as FsRtlOplockFsctrl:dword
        extrn '__imp__FsRtlOplockIsFastIoPossible@4' as FsRtlOplockIsFastIoPossible:dword
        extrn '__imp__FsRtlPostPagingFileStackOverflow@12' as FsRtlPostPagingFileStackOverflow:dword
        extrn '__imp__FsRtlPostStackOverflow@12' as FsRtlPostStackOverflow:dword
        extrn '__imp__FsRtlPrepareMdlWrite@24' as FsRtlPrepareMdlWrite:dword
        extrn '__imp__FsRtlPrepareMdlWriteDev@28' as FsRtlPrepareMdlWriteDev:dword
        extrn '__imp__FsRtlPrivateLock@48' as FsRtlPrivateLock:dword
        extrn '__imp__FsRtlProcessFileLock@12' as FsRtlProcessFileLock:dword
        extrn '__imp__FsRtlRegisterUncProvider@12' as FsRtlRegisterUncProvider:dword
        extrn '__imp__FsRtlRemoveLargeMcbEntry@20' as FsRtlRemoveLargeMcbEntry:dword
        extrn '__imp__FsRtlRemoveMcbEntry@12' as FsRtlRemoveMcbEntry:dword
        extrn '__imp__FsRtlSplitLargeMcb@20' as FsRtlSplitLargeMcb:dword
        extrn '__imp__FsRtlSyncVolumes@12' as FsRtlSyncVolumes:dword
        extrn '__imp__FsRtlTruncateLargeMcb@12' as FsRtlTruncateLargeMcb:dword
        extrn '__imp__FsRtlTruncateMcb@8' as FsRtlTruncateMcb:dword
        extrn '__imp__FsRtlUninitializeFileLock@4' as FsRtlUninitializeFileLock:dword
        extrn '__imp__FsRtlUninitializeLargeMcb@4' as FsRtlUninitializeLargeMcb:dword
        extrn '__imp__FsRtlUninitializeMcb@4' as FsRtlUninitializeMcb:dword
        extrn '__imp__FsRtlUninitializeOplock@4' as FsRtlUninitializeOplock:dword
        extrn '__imp__IoAcquireVpbSpinLock@4' as IoAcquireVpbSpinLock:dword
        extrn '__imp__IoAllocateAdapterChannel@20' as IoAllocateAdapterChannel:dword
        extrn '__imp__IoAllocateController@16' as IoAllocateController:dword
        extrn '__imp__IoAllocateErrorLogEntry@8' as IoAllocateErrorLogEntry:dword
        extrn '__imp__IoAllocateIrp@8' as IoAllocateIrp:dword
        extrn '__imp__IoAllocateMdl@20' as IoAllocateMdl:dword
        extrn '__imp__IoAssignResources@24' as IoAssignResources:dword
        extrn '__imp__IoAttachDevice@12' as IoAttachDevice:dword
        extrn '__imp__IoAttachDeviceByPointer@8' as IoAttachDeviceByPointer:dword
        extrn '__imp__IoAttachDeviceToDeviceStack@8' as IoAttachDeviceToDeviceStack:dword
        extrn '__imp__IoBuildAsynchronousFsdRequest@24' as IoBuildAsynchronousFsdRequest:dword
        extrn '__imp__IoBuildDeviceIoControlRequest@36' as IoBuildDeviceIoControlRequest:dword
        extrn '__imp__IoBuildPartialMdl@16' as IoBuildPartialMdl:dword
        extrn '__imp__IoBuildSynchronousFsdRequest@28' as IoBuildSynchronousFsdRequest:dword
        extrn '__imp__IoCallDriver@8' as IoCallDriver:dword
        extrn '__imp__IoCancelIrp@4' as IoCancelIrp:dword
        extrn '__imp__IoCheckDesiredAccess@8' as IoCheckDesiredAccess:dword
        extrn '__imp__IoCheckEaBufferValidity@12' as IoCheckEaBufferValidity:dword
        extrn '__imp__IoCheckFunctionAccess@24' as IoCheckFunctionAccess:dword
        extrn '__imp__IoCheckShareAccess@20' as IoCheckShareAccess:dword
        extrn '__imp__IoCompleteRequest@8' as IoCompleteRequest:dword
        extrn '__imp__IoConnectInterrupt@44' as IoConnectInterrupt:dword
        extrn '__imp__IoCreateController@4' as IoCreateController:dword
        extrn '__imp__IoCreateDevice@28' as IoCreateDevice:dword
        extrn '__imp__IoCreateFile@56' as IoCreateFile:dword
        extrn '__imp__IoCreateNotificationEvent@8' as IoCreateNotificationEvent:dword
        extrn '__imp__IoCreateStreamFileObject@8' as IoCreateStreamFileObject:dword
        extrn '__imp__IoCreateSymbolicLink@8' as IoCreateSymbolicLink:dword
        extrn '__imp__IoCreateSynchronizationEvent@8' as IoCreateSynchronizationEvent:dword
        extrn '__imp__IoCreateUnprotectedSymbolicLink@8' as IoCreateUnprotectedSymbolicLink:dword
        extrn '__imp__IoDeleteController@4' as IoDeleteController:dword
        extrn '__imp__IoDeleteDevice@4' as IoDeleteDevice:dword
        extrn '__imp__IoDeleteSymbolicLink@4' as IoDeleteSymbolicLink:dword
        extrn '__imp__IoDetachDevice@4' as IoDetachDevice:dword
        extrn '__imp__IoDisconnectInterrupt@4' as IoDisconnectInterrupt:dword
        extrn '__imp__IoEnqueueIrp@4' as IoEnqueueIrp:dword
        extrn '__imp__IoFastQueryNetworkAttributes@20' as IoFastQueryNetworkAttributes:dword
        extrn '__imp__IofCallDriver@8' as IofCallDriver:dword
        extrn '__imp__IofCompleteRequest@8' as IofCompleteRequest:dword
        extrn '__imp__IoFreeController@4' as IoFreeController:dword
        extrn '__imp__IoFreeIrp@4' as IoFreeIrp:dword
        extrn '__imp__IoFreeMdl@4' as IoFreeMdl:dword
        extrn '__imp__IoGetAttachedDevice@4' as IoGetAttachedDevice:dword
        extrn '__imp__IoGetBaseFileSystemDeviceObject@4' as IoGetBaseFileSystemDeviceObject:dword
        extrn '__imp__IoGetConfigurationInformation@0' as IoGetConfigurationInformation:dword
        extrn '__imp__IoGetCurrentProcess@0' as IoGetCurrentProcess:dword
        extrn '__imp__IoGetDeviceObjectPointer@16' as IoGetDeviceObjectPointer:dword
        extrn '__imp__IoGetDeviceToVerify@4' as IoGetDeviceToVerify:dword
        extrn '__imp__IoGetFileObjectGenericMapping@0' as IoGetFileObjectGenericMapping:dword
        extrn '__imp__IoGetInitialStack@0' as IoGetInitialStack:dword
        extrn '__imp__IoGetRelatedDeviceObject@4' as IoGetRelatedDeviceObject:dword
        extrn '__imp__IoGetRequestorProcess@4' as IoGetRequestorProcess:dword
        extrn '__imp__IoGetStackLimits@8' as IoGetStackLimits:dword
        extrn '__imp__IoGetTopLevelIrp@0' as IoGetTopLevelIrp:dword
        extrn '__imp__IoInitializeIrp@12' as IoInitializeIrp:dword
        extrn '__imp__IoInitializeTimer@12' as IoInitializeTimer:dword
        extrn '__imp__IoIsOperationSynchronous@4' as IoIsOperationSynchronous:dword
        extrn '__imp__IoIsSystemThread@4' as IoIsSystemThread:dword
        extrn '__imp__IoMakeAssociatedIrp@8' as IoMakeAssociatedIrp:dword
        extrn '__imp__IoPageRead@20' as IoPageRead:dword
        extrn '__imp__IoQueryDeviceDescription@32' as IoQueryDeviceDescription:dword
        extrn '__imp__IoQueryFileInformation@20' as IoQueryFileInformation:dword
        extrn '__imp__IoQueryVolumeInformation@20' as IoQueryVolumeInformation:dword
        extrn '__imp__IoQueueThreadIrp@4' as IoQueueThreadIrp:dword
        extrn '__imp__IoRaiseHardError@12' as IoRaiseHardError:dword
        extrn '__imp__IoRaiseInformationalHardError@12' as IoRaiseInformationalHardError:dword
        extrn '__imp__IoRegisterDriverReinitialization@12' as IoRegisterDriverReinitialization:dword
        extrn '__imp__IoRegisterFileSystem@4' as IoRegisterFileSystem:dword
        extrn '__imp__IoRegisterFsRegistrationChange@8' as IoRegisterFsRegistrationChange:dword
        extrn '__imp__IoRegisterShutdownNotification@4' as IoRegisterShutdownNotification:dword
        extrn '__imp__IoReleaseCancelSpinLock@4' as IoReleaseCancelSpinLock:dword
        extrn '__imp__IoReleaseVpbSpinLock@4' as IoReleaseVpbSpinLock:dword
        extrn '__imp__IoRemoveShareAccess@8' as IoRemoveShareAccess:dword
        extrn '__imp__IoReportHalResourceUsage@16' as IoReportHalResourceUsage:dword
        extrn '__imp__IoReportResourceUsage@36' as IoReportResourceUsage:dword
        extrn '__imp__IoSetDeviceToVerify@8' as IoSetDeviceToVerify:dword
        extrn '__imp__IoSetHardErrorOrVerifyDevice@8' as IoSetHardErrorOrVerifyDevice:dword
        extrn '__imp__IoSetInformation@16' as IoSetInformation:dword
        extrn '__imp__IoSetShareAccess@16' as IoSetShareAccess:dword
        extrn '__imp__IoSetThreadHardErrorMode@4' as IoSetThreadHardErrorMode:dword
        extrn '__imp__IoSetTopLevelIrp@4' as IoSetTopLevelIrp:dword
        extrn '__imp__IoStartNextPacket@8' as IoStartNextPacket:dword
        extrn '__imp__IoStartNextPacketByKey@12' as IoStartNextPacketByKey:dword
        extrn '__imp__IoStartPacket@16' as IoStartPacket:dword
        extrn '__imp__IoStartTimer@4' as IoStartTimer:dword
        extrn '__imp__IoStopTimer@4' as IoStopTimer:dword
        extrn '__imp__IoSynchronousPageWrite@20' as IoSynchronousPageWrite:dword
        extrn '__imp__IoThreadToProcess@4' as IoThreadToProcess:dword
        extrn '__imp__IoUnregisterFileSystem@4' as IoUnregisterFileSystem:dword
        extrn '__imp__IoUnregisterFsRegistrationChange@8' as IoUnregisterFsRegistrationChange:dword
        extrn '__imp__IoUnregisterShutdownNotification@4' as IoUnregisterShutdownNotification:dword
        extrn '__imp__IoUpdateShareAccess@8' as IoUpdateShareAccess:dword
        extrn '__imp__IoVerifyVolume@8' as IoVerifyVolume:dword
        extrn '__imp__IoWriteErrorLogEntry@4' as IoWriteErrorLogEntry:dword
        if ~defined __imp__isdigit
            extrn '__imp__isdigit@4' as isdigit:dword
        end if
        if ~defined __imp__islower
            extrn '__imp__islower@4' as islower:dword
        end if
        if ~defined __imp__isprint
            extrn '__imp__isprint@4' as isprint:dword
        end if
        if ~defined __imp__isspace
            extrn '__imp__isspace@4' as isspace:dword
        end if
        if ~defined __imp__isupper
            extrn '__imp__isupper@4' as isupper:dword
        end if
        if ~defined __imp__isxdigit
            extrn '__imp__isxdigit@4' as isxdigit:dword
        end if
        extrn '__imp__KdPollBreakIn@0' as KdPollBreakIn:dword
        extrn '__imp__KeAcquireSpinLockAtDpcLevel@4' as KeAcquireSpinLockAtDpcLevel:dword
        extrn '__imp__KeAddSystemServiceTable@20' as KeAddSystemServiceTable:dword
        extrn '__imp__KeAttachProcess@4' as KeAttachProcess:dword
        extrn '__imp__KeBugCheck@4' as KeBugCheck:dword
        extrn '__imp__KeBugCheckEx@20' as KeBugCheckEx:dword
        extrn '__imp__KeCancelTimer@4' as KeCancelTimer:dword
        extrn '__imp__KeClearEvent@4' as KeClearEvent:dword
        extrn '__imp__KeDelayExecutionThread@12' as KeDelayExecutionThread:dword
        extrn '__imp__KeDeregisterBugCheckCallback@4' as KeDeregisterBugCheckCallback:dword
        extrn '__imp__KeDetachProcess@0' as KeDetachProcess:dword
        extrn '__imp__KeEnterCriticalRegion@0' as KeEnterCriticalRegion:dword
        extrn '__imp__KeEnterKernelDebugger@0' as KeEnterKernelDebugger:dword
        extrn '__imp__KeFindConfigurationEntry@16' as KeFindConfigurationEntry:dword
        extrn '__imp__KeFindConfigurationNextEntry@20' as KeFindConfigurationNextEntry:dword
        extrn '__imp__KeFlushEntireTb@8' as KeFlushEntireTb:dword
        extrn '__imp__KeGetCurrentThread@0' as KeGetCurrentThread:dword
        extrn '__imp__KeInitializeApc@32' as KeInitializeApc:dword
        extrn '__imp__KeInitializeDeviceQueue@4' as KeInitializeDeviceQueue:dword
        extrn '__imp__KeInitializeDpc@12' as KeInitializeDpc:dword
        extrn '__imp__KeInitializeEvent@12' as KeInitializeEvent:dword
        extrn '__imp__KeInitializeInterrupt@44' as KeInitializeInterrupt:dword
        extrn '__imp__KeInitializeMutant@8' as KeInitializeMutant:dword
        extrn '__imp__KeInitializeMutex@8' as KeInitializeMutex:dword
        extrn '__imp__KeInitializeQueue@8' as KeInitializeQueue:dword
        extrn '__imp__KeInitializeSemaphore@12' as KeInitializeSemaphore:dword
        extrn '__imp__KeInitializeTimer@4' as KeInitializeTimer:dword
        extrn '__imp__KeInitializeTimerEx@8' as KeInitializeTimerEx:dword
        extrn '__imp__KeInsertByKeyDeviceQueue@12' as KeInsertByKeyDeviceQueue:dword
        extrn '__imp__KeInsertDeviceQueue@8' as KeInsertDeviceQueue:dword
        extrn '__imp__KeInsertHeadQueue@8' as KeInsertHeadQueue:dword
        extrn '__imp__KeInsertQueue@8' as KeInsertQueue:dword
        extrn '__imp__KeInsertQueueApc@16' as KeInsertQueueApc:dword
        extrn '__imp__KeInsertQueueDpc@12' as KeInsertQueueDpc:dword
        extrn '__imp__KeIsExecutingDpc@0' as KeIsExecutingDpc:dword
        extrn '__imp__KeLeaveCriticalRegion@0' as KeLeaveCriticalRegion:dword
        extrn '__imp__KeProfileInterruptWithSource@8' as KeProfileInterruptWithSource:dword
        extrn '__imp__KePulseEvent@12' as KePulseEvent:dword
        extrn '__imp__KeQueryTimeIncrement@0' as KeQueryTimeIncrement:dword
        extrn '__imp__KeRaiseUserException@4' as KeRaiseUserException:dword
        extrn '__imp__KeReadStateEvent@4' as KeReadStateEvent:dword
        extrn '__imp__KeReadStateMutant@4' as KeReadStateMutant:dword
        extrn '__imp__KeReadStateMutex@4' as KeReadStateMutex:dword
        extrn '__imp__KeReadStateQueue@4' as KeReadStateQueue:dword
        extrn '__imp__KeReadStateSemaphore@4' as KeReadStateSemaphore:dword
        extrn '__imp__KeReadStateTimer@4' as KeReadStateTimer:dword
        extrn '__imp__KeRegisterBugCheckCallback@20' as KeRegisterBugCheckCallback:dword
        extrn '__imp__KeReleaseMutant@16' as KeReleaseMutant:dword
        extrn '__imp__KeReleaseMutex@8' as KeReleaseMutex:dword
        extrn '__imp__KeReleaseSemaphore@16' as KeReleaseSemaphore:dword
        extrn '__imp__KeReleaseSpinLockFromDpcLevel@4' as KeReleaseSpinLockFromDpcLevel:dword
        extrn '__imp__KeRemoveByKeyDeviceQueue@8' as KeRemoveByKeyDeviceQueue:dword
        extrn '__imp__KeRemoveDeviceQueue@4' as KeRemoveDeviceQueue:dword
        extrn '__imp__KeRemoveEntryDeviceQueue@8' as KeRemoveEntryDeviceQueue:dword
        extrn '__imp__KeRemoveQueue@12' as KeRemoveQueue:dword
        extrn '__imp__KeRemoveQueueDpc@4' as KeRemoveQueueDpc:dword
        extrn '__imp__KeResetEvent@4' as KeResetEvent:dword
        extrn '__imp__KeRestoreFloatingPointState@4' as KeRestoreFloatingPointState:dword
        extrn '__imp__KeRundownQueue@4' as KeRundownQueue:dword
        extrn '__imp__KeSaveFloatingPointState@4' as KeSaveFloatingPointState:dword
        extrn '__imp__KeSetAffinityThread@8' as KeSetAffinityThread:dword
        extrn '__imp__KeSetBasePriorityThread@8' as KeSetBasePriorityThread:dword
        extrn '__imp__KeSetDmaIoCoherency@4' as KeSetDmaIoCoherency:dword
        extrn '__imp__KeSetEvent@12' as KeSetEvent:dword
        extrn '__imp__KeSetEventBoostPriority@8' as KeSetEventBoostPriority:dword
        extrn '__imp__KeSetIdealProcessorThread@8' as KeSetIdealProcessorThread:dword
        extrn '__imp__KeSetImportanceDpc@8' as KeSetImportanceDpc:dword
        extrn '__imp__KeSetKernelStackSwapEnable@4' as KeSetKernelStackSwapEnable:dword
        extrn '__imp__KeSetPriorityThread@8' as KeSetPriorityThread:dword
        extrn '__imp__KeSetProfileIrql@4' as KeSetProfileIrql:dword
        extrn '__imp__KeSetTargetProcessorDpc@8' as KeSetTargetProcessorDpc:dword
        extrn '__imp__KeSetTimeIncrement@8' as KeSetTimeIncrement:dword
        extrn '__imp__KeSetTimer@16' as KeSetTimer:dword
        extrn '__imp__KeSetTimerEx@20' as KeSetTimerEx:dword
        extrn '__imp__KeSynchronizeExecution@12' as KeSynchronizeExecution:dword
        extrn '__imp__KeUpdateRunTime@4' as KeUpdateRunTime:dword
        extrn '__imp__KeUserModeCallback@20' as KeUserModeCallback:dword
        extrn '__imp__KeWaitForMultipleObjects@32' as KeWaitForMultipleObjects:dword
        extrn '__imp__KeWaitForMutexObject@20' as KeWaitForMutexObject:dword
        extrn '__imp__KeWaitForSingleObject@20' as KeWaitForSingleObject:dword
        extrn '__imp__LdrAccessResource@16' as LdrAccessResource:dword
        extrn '__imp__LdrEnumResources@20' as LdrEnumResources:dword
        extrn '__imp__LdrFindResource_U@16' as LdrFindResource_U:dword
        extrn '__imp__LdrFindResourceDirectory_U@16' as LdrFindResourceDirectory_U:dword
        extrn '__imp__LpcRequestPort@8' as LpcRequestPort:dword
        extrn '__imp__LsaCallAuthenticationPackage@28' as LsaCallAuthenticationPackage:dword
        extrn '__imp__LsaDeregisterLogonProcess@4' as LsaDeregisterLogonProcess:dword
        extrn '__imp__LsaFreeReturnBuffer@4' as LsaFreeReturnBuffer:dword
        extrn '__imp__LsaLogonUser@56' as LsaLogonUser:dword
        extrn '__imp__LsaLookupAuthenticationPackage@12' as LsaLookupAuthenticationPackage:dword
        extrn '__imp__LsaRegisterLogonProcess@12' as LsaRegisterLogonProcess:dword
        if ~defined __imp__mbstowcs
            extrn '__imp__mbstowcs@12' as mbstowcs:dword
        end if
        if ~defined __imp__mbtowc
            extrn '__imp__mbtowc@12' as mbtowc:dword
        end if
        if ~defined __imp__memchr
            extrn '__imp__memchr@12' as memchr:dword
        end if
        if ~defined __imp__memcpy
            extrn '__imp__memcpy@12' as memcpy:dword
        end if
        if ~defined __imp__memmove
            extrn '__imp__memmove@12' as memmove:dword
        end if
        if ~defined __imp__memset
            extrn '__imp__memset@12' as memset:dword
        end if
        extrn '__imp__MmAdjustWorkingSetSize@16' as MmAdjustWorkingSetSize:dword
        extrn '__imp__MmAllocateContiguousMemory@12' as MmAllocateContiguousMemory:dword
        extrn '__imp__MmAllocateNonCachedMemory@4' as MmAllocateNonCachedMemory:dword
        extrn '__imp__MmBuildMdlForNonPagedPool@4' as MmBuildMdlForNonPagedPool:dword
        extrn '__imp__MmCanFileBeTruncated@8' as MmCanFileBeTruncated:dword
        extrn '__imp__MmCreateMdl@12' as MmCreateMdl:dword
        extrn '__imp__MmCreateSection@32' as MmCreateSection:dword
        extrn '__imp__MmDisableModifiedWriteOfSection@4' as MmDisableModifiedWriteOfSection:dword
        extrn '__imp__MmFlushImageSection@8' as MmFlushImageSection:dword
        extrn '__imp__MmForceSectionClosed@8' as MmForceSectionClosed:dword
        extrn '__imp__MmFreeContiguousMemory@4' as MmFreeContiguousMemory:dword
        extrn '__imp__MmFreeNonCachedMemory@8' as MmFreeNonCachedMemory:dword
        extrn '__imp__MmGetPhysicalAddress@4' as MmGetPhysicalAddress:dword
        extrn '__imp__MmGrowKernelStack@4' as MmGrowKernelStack:dword
        extrn '__imp__MmIsAddressValid@4' as MmIsAddressValid:dword
        extrn '__imp__MmIsNonPagedSystemAddressValid@4' as MmIsNonPagedSystemAddressValid:dword
        extrn '__imp__MmIsRecursiveIoFault@0' as MmIsRecursiveIoFault:dword
        extrn '__imp__MmIsThisAnNtAsSystem@0' as MmIsThisAnNtAsSystem:dword
        extrn '__imp__MmLockPagableDataSection@4' as MmLockPagableDataSection:dword
        extrn '__imp__MmLockPagableImageSection@4' as MmLockPagableImageSection:dword
        extrn '__imp__MmLockPagableSectionByHandle@4' as MmLockPagableSectionByHandle:dword
        extrn '__imp__MmMapIoSpace@16' as MmMapIoSpace:dword
        extrn '__imp__MmMapLockedPages@8' as MmMapLockedPages:dword
        extrn '__imp__MmMapLockedPagesSpecifyCache@24' as MmMapLockedPagesSpecifyCache:dword
        extrn '__imp__MmMapMemoryDumpMdl@4' as MmMapMemoryDumpMdl:dword
        extrn '__imp__MmMapVideoDisplay@16' as MmMapVideoDisplay:dword
        extrn '__imp__MmMapViewInSystemSpace@12' as MmMapViewInSystemSpace:dword
        extrn '__imp__MmMapViewOfSection@40' as MmMapViewOfSection:dword
        extrn '__imp__MmPageEntireDriver@4' as MmPageEntireDriver:dword
        extrn '__imp__MmProbeAndLockPages@12' as MmProbeAndLockPages:dword
        extrn '__imp__MmQuerySystemSize@0' as MmQuerySystemSize:dword
        extrn '__imp__MmResetDriverPaging@4' as MmResetDriverPaging:dword
        extrn '__imp__MmSecureVirtualMemory@12' as MmSecureVirtualMemory:dword
        extrn '__imp__MmSetAddressRangeModified@8' as MmSetAddressRangeModified:dword
        extrn '__imp__MmSetBankedSection@24' as MmSetBankedSection:dword
        extrn '__imp__MmSizeOfMdl@8' as MmSizeOfMdl:dword
        extrn '__imp__MmUnlockPagableImageSection@4' as MmUnlockPagableImageSection:dword
        extrn '__imp__MmUnlockPages@4' as MmUnlockPages:dword
        extrn '__imp__MmUnmapIoSpace@8' as MmUnmapIoSpace:dword
        extrn '__imp__MmUnmapLockedPages@8' as MmUnmapLockedPages:dword
        extrn '__imp__MmUnmapVideoDisplay@8' as MmUnmapVideoDisplay:dword
        extrn '__imp__MmUnmapViewInSystemSpace@4' as MmUnmapViewInSystemSpace:dword
        extrn '__imp__MmUnmapViewOfSection@8' as MmUnmapViewOfSection:dword
        extrn '__imp__MmUnsecureVirtualMemory@4' as MmUnsecureVirtualMemory:dword
        extrn '__imp__NlsOemLeadByteInfo@4' as NlsOemLeadByteInfo:dword
        extrn '__imp__NtAddAtom@12' as NtAddAtom:dword
        extrn '__imp__NtAdjustPrivilegesToken@24' as NtAdjustPrivilegesToken:dword
        extrn '__imp__NtAllocateLocallyUniqueId@4' as NtAllocateLocallyUniqueId:dword
        extrn '__imp__NtAllocateUuids@16' as NtAllocateUuids:dword
        extrn '__imp__NtAllocateVirtualMemory@24' as NtAllocateVirtualMemory:dword
        extrn '__imp__NtClose@4' as NtClose:dword
        extrn '__imp__NtConnectPort@32' as NtConnectPort:dword
        extrn '__imp__NtCreateEvent@20' as NtCreateEvent:dword
        extrn '__imp__NtCreateFile@44' as NtCreateFile:dword
        extrn '__imp__NtCreateSection@28' as NtCreateSection:dword
        extrn '__imp__NtDeleteAtom@4' as NtDeleteAtom:dword
        extrn '__imp__NtDeleteFile@4' as NtDeleteFile:dword
        extrn '__imp__NtDeviceIoControlFile@40' as NtDeviceIoControlFile:dword
        extrn '__imp__NtDuplicateObject@28' as NtDuplicateObject:dword
        extrn '__imp__NtDuplicateToken@24' as NtDuplicateToken:dword
        extrn '__imp__NtFindAtom@12' as NtFindAtom:dword
        extrn '__imp__NtFreeVirtualMemory@16' as NtFreeVirtualMemory:dword
        extrn '__imp__NtFsControlFile@40' as NtFsControlFile:dword
        extrn '__imp__NtLockFile@40' as NtLockFile:dword
        extrn '__imp__NtMapViewOfSection@40' as NtMapViewOfSection:dword
        extrn '__imp__NtNotifyChangeDirectoryFile@36' as NtNotifyChangeDirectoryFile:dword
        extrn '__imp__NtOpenFile@24' as NtOpenFile:dword
        extrn '__imp__NtOpenProcess@16' as NtOpenProcess:dword
        extrn '__imp__NtOpenProcessToken@12' as NtOpenProcessToken:dword
        extrn '__imp__NtQueryDirectoryFile@44' as NtQueryDirectoryFile:dword
        extrn '__imp__NtQueryEaFile@36' as NtQueryEaFile:dword
        extrn '__imp__NtQueryInformationAtom@20' as NtQueryInformationAtom:dword
        extrn '__imp__NtQueryInformationFile@20' as NtQueryInformationFile:dword
        extrn '__imp__NtQueryInformationProcess@20' as NtQueryInformationProcess:dword
        extrn '__imp__NtQueryInformationToken@20' as NtQueryInformationToken:dword
        extrn '__imp__NtQuerySecurityObject@20' as NtQuerySecurityObject:dword
        extrn '__imp__NtQueryVolumeInformationFile@20' as NtQueryVolumeInformationFile:dword
        extrn '__imp__NtReadFile@36' as NtReadFile:dword
        extrn '__imp__NtRequestPort@8' as NtRequestPort:dword
        extrn '__imp__NtRequestWaitReplyPort@12' as NtRequestWaitReplyPort:dword
        extrn '__imp__NtSetEvent@8' as NtSetEvent:dword
        extrn '__imp__NtSetInformationFile@20' as NtSetInformationFile:dword
        extrn '__imp__NtSetInformationProcess@16' as NtSetInformationProcess:dword
        extrn '__imp__NtSetInformationThread@16' as NtSetInformationThread:dword
        extrn '__imp__NtSetQuotaInformationFile@16' as NtSetQuotaInformationFile:dword
        extrn '__imp__NtSetSecurityObject@12' as NtSetSecurityObject:dword
        extrn '__imp__NtUnlockFile@20' as NtUnlockFile:dword
        extrn '__imp__NtVdmControl@8' as NtVdmControl:dword
        extrn '__imp__NtWaitForSingleObject@12' as NtWaitForSingleObject:dword
        extrn '__imp__NtWriteFile@36' as NtWriteFile:dword
        extrn '__imp__ObAssignSecurity@16' as ObAssignSecurity:dword
        extrn '__imp__ObCheckCreateObjectAccess@28' as ObCheckCreateObjectAccess:dword
        extrn '__imp__ObCheckObjectAccess@20' as ObCheckObjectAccess:dword
        extrn '__imp__ObCreateObject@36' as ObCreateObject:dword
        extrn '__imp__ObDereferenceObject@4' as ObDereferenceObject:dword
        extrn '__imp__ObfDereferenceObject@4' as ObfDereferenceObject:dword
        extrn '__imp__ObFindHandleForObject@20' as ObFindHandleForObject:dword
        extrn '__imp__ObfReferenceObject@4' as ObfReferenceObject:dword
        extrn '__imp__ObGetObjectSecurity@12' as ObGetObjectSecurity:dword
        extrn '__imp__ObInsertObject@24' as ObInsertObject:dword
        extrn '__imp__ObMakeTemporaryObject@4' as ObMakeTemporaryObject:dword
        extrn '__imp__ObOpenObjectByName@28' as ObOpenObjectByName:dword
        extrn '__imp__ObOpenObjectByPointer@28' as ObOpenObjectByPointer:dword
        extrn '__imp__ObQueryNameString@16' as ObQueryNameString:dword
        extrn '__imp__ObQueryObjectAuditingByHandle@8' as ObQueryObjectAuditingByHandle:dword
        extrn '__imp__ObReferenceObjectByHandle@24' as ObReferenceObjectByHandle:dword
        extrn '__imp__ObReferenceObjectByName@32' as ObReferenceObjectByName:dword
        extrn '__imp__ObReferenceObjectByPointer@16' as ObReferenceObjectByPointer:dword
        extrn '__imp__ObReleaseObjectSecurity@8' as ObReleaseObjectSecurity:dword
        extrn '__imp__ObSetSecurityDescriptorInfo@24' as ObSetSecurityDescriptorInfo:dword
        extrn '__imp__PfxFindPrefix@8' as PfxFindPrefix:dword
        extrn '__imp__PfxInitialize@4' as PfxInitialize:dword
        extrn '__imp__PfxInsertPrefix@12' as PfxInsertPrefix:dword
        extrn '__imp__PfxRemovePrefix@8' as PfxRemovePrefix:dword
        extrn '__imp__ProbeForWrite@12' as ProbeForWrite:dword
        extrn '__imp__PsAssignImpersonationToken@8' as PsAssignImpersonationToken:dword
        extrn '__imp__PsChargePoolQuota@12' as PsChargePoolQuota:dword
        extrn '__imp__PsCreateSystemThread@28' as PsCreateSystemThread:dword
        extrn '__imp__PsEstablishWin32Callouts@4' as PsEstablishWin32Callouts:dword
        extrn '__imp__PsGetCurrentProcessId@0' as PsGetCurrentProcessId:dword
        extrn '__imp__PsGetCurrentThreadId@0' as PsGetCurrentThreadId:dword
        extrn '__imp__PsGetProcessExitTime@0' as PsGetProcessExitTime:dword
        extrn '__imp__PsGetVersion@16' as PsGetVersion:dword
        extrn '__imp__PsImpersonateClient@20' as PsImpersonateClient:dword
        extrn '__imp__PsIsThreadTerminating@4' as PsIsThreadTerminating:dword
        extrn '__imp__PsLookupProcessByProcessId@8' as PsLookupProcessByProcessId:dword
        extrn '__imp__PsLookupProcessThreadByCid@12' as PsLookupProcessThreadByCid:dword
        extrn '__imp__PsLookupThreadByThreadId@8' as PsLookupThreadByThreadId:dword
        extrn '__imp__PsProcessType@24' as PsProcessType:dword
        extrn '__imp__PsReferenceImpersonationToken@16' as PsReferenceImpersonationToken:dword
        extrn '__imp__PsReferencePrimaryToken@4' as PsReferencePrimaryToken:dword
        extrn '__imp__PsReturnPoolQuota@12' as PsReturnPoolQuota:dword
        extrn '__imp__PsRevertToSelf@0' as PsRevertToSelf:dword
        extrn '__imp__PsSetCreateProcessNotifyRoutine@8' as PsSetCreateProcessNotifyRoutine:dword
        extrn '__imp__PsSetCreateThreadNotifyRoutine@4' as PsSetCreateThreadNotifyRoutine:dword
        extrn '__imp__PsSetLegoNotifyRoutine@4' as PsSetLegoNotifyRoutine:dword
        extrn '__imp__PsSetProcessPriorityByClass@8' as PsSetProcessPriorityByClass:dword
        extrn '__imp__PsTerminateSystemThread@4' as PsTerminateSystemThread:dword
        extrn '__imp__PsThreadType@4' as PsThreadType:dword
        if ~defined __imp__qsort
            extrn '__imp__qsort@16' as qsort:dword
        end if
        if ~defined __imp__rand
            extrn '__imp__rand@0' as rand:dword
        end if
        extrn '__imp__RtlAbsoluteToSelfRelativeSD@12' as RtlAbsoluteToSelfRelativeSD:dword
        extrn '__imp__RtlAddAccessAllowedAce@16' as RtlAddAccessAllowedAce:dword
        extrn '__imp__RtlAddAce@20' as RtlAddAce:dword
        extrn '__imp__RtlAddAtomToAtomTable@12' as RtlAddAtomToAtomTable:dword
        extrn '__imp__RtlAllocateHeap@12' as RtlAllocateHeap:dword
        extrn '__imp__RtlAnsiCharToUnicodeChar@4' as RtlAnsiCharToUnicodeChar:dword
        extrn '__imp__RtlAnsiStringToUnicodeSize@4' as RtlAnsiStringToUnicodeSize:dword
        extrn '__imp__RtlAnsiStringToUnicodeString@12' as RtlAnsiStringToUnicodeString:dword
        extrn '__imp__RtlAppendAsciizToString@8' as RtlAppendAsciizToString:dword
        extrn '__imp__RtlAppendStringToString@8' as RtlAppendStringToString:dword
        extrn '__imp__RtlAppendUnicodeStringToString@8' as RtlAppendUnicodeStringToString:dword
        extrn '__imp__RtlAppendUnicodeToString@8' as RtlAppendUnicodeToString:dword
        extrn '__imp__RtlAreAllAccessesGranted@8' as RtlAreAllAccessesGranted:dword
        extrn '__imp__RtlAreAnyAccessesGranted@8' as RtlAreAnyAccessesGranted:dword
        extrn '__imp__RtlAreBitsClear@12' as RtlAreBitsClear:dword
        extrn '__imp__RtlAreBitsSet@12' as RtlAreBitsSet:dword
        extrn '__imp__RtlAssert@16' as RtlAssert:dword
        extrn '__imp__RtlCaptureStackBackTrace@16' as RtlCaptureStackBackTrace:dword
        extrn '__imp__RtlCharToInteger@12' as RtlCharToInteger:dword
        extrn '__imp__RtlCheckRegistryKey@8' as RtlCheckRegistryKey:dword
        extrn '__imp__RtlClearAllBits@4' as RtlClearAllBits:dword
        extrn '__imp__RtlClearBits@12' as RtlClearBits:dword
        extrn '__imp__RtlCompareMemory@12' as RtlCompareMemory:dword
        extrn '__imp__RtlCompareMemoryUlong@12' as RtlCompareMemoryUlong:dword
        extrn '__imp__RtlCompareString@12' as RtlCompareString:dword
        extrn '__imp__RtlCompareUnicodeString@12' as RtlCompareUnicodeString:dword
        extrn '__imp__RtlCompressBuffer@32' as RtlCompressBuffer:dword
        extrn '__imp__RtlCompressChunks@28' as RtlCompressChunks:dword
        extrn '__imp__RtlConvertSidToUnicodeString@12' as RtlConvertSidToUnicodeString:dword
        extrn '__imp__RtlCopyLuid@8' as RtlCopyLuid:dword
        extrn '__imp__RtlCopyMemory@12' as RtlCopyMemory:dword
        extrn '__imp__RtlCopySid@12' as RtlCopySid:dword
        extrn '__imp__RtlCopyString@8' as RtlCopyString:dword
        extrn '__imp__RtlCopyUnicodeString@8' as RtlCopyUnicodeString:dword
        extrn '__imp__RtlCreateAcl@12' as RtlCreateAcl:dword
        extrn '__imp__RtlCreateAtomTable@8' as RtlCreateAtomTable:dword
        extrn '__imp__RtlCreateHeap@24' as RtlCreateHeap:dword
        extrn '__imp__RtlCreateRegistryKey@8' as RtlCreateRegistryKey:dword
        extrn '__imp__RtlCreateSecurityDescriptor@8' as RtlCreateSecurityDescriptor:dword
        extrn '__imp__RtlCreateUnicodeString@8' as RtlCreateUnicodeString:dword
        extrn '__imp__RtlCustomCPToUnicodeN@24' as RtlCustomCPToUnicodeN:dword
        extrn '__imp__RtlDecompressBuffer@24' as RtlDecompressBuffer:dword
        extrn '__imp__RtlDecompressChunks@28' as RtlDecompressChunks:dword
        extrn '__imp__RtlDecompressFragment@32' as RtlDecompressFragment:dword
        extrn '__imp__RtlDelete@4' as RtlDelete:dword
        extrn '__imp__RtlDeleteAtomFromAtomTable@8' as RtlDeleteAtomFromAtomTable:dword
        extrn '__imp__RtlDeleteElementGenericTable@8' as RtlDeleteElementGenericTable:dword
        extrn '__imp__RtlDeleteNoSplay@8' as RtlDeleteNoSplay:dword
        extrn '__imp__RtlDeleteRegistryValue@12' as RtlDeleteRegistryValue:dword
        extrn '__imp__RtlDescribeChunk@20' as RtlDescribeChunk:dword
        extrn '__imp__RtlDestroyAtomTable@4' as RtlDestroyAtomTable:dword
        extrn '__imp__RtlDestroyHeap@4' as RtlDestroyHeap:dword
        extrn '__imp__RtlDowncaseUnicodeString@12' as RtlDowncaseUnicodeString:dword
        extrn '__imp__RtlEmptyAtomTable@8' as RtlEmptyAtomTable:dword
        extrn '__imp__RtlEnumerateGenericTable@8' as RtlEnumerateGenericTable:dword
        extrn '__imp__RtlEnumerateGenericTableWithoutSplaying@8' as RtlEnumerateGenericTableWithoutSplaying:dword
        extrn '__imp__RtlEqualLuid@8' as RtlEqualLuid:dword
        extrn '__imp__RtlEqualSid@8' as RtlEqualSid:dword
        extrn '__imp__RtlEqualString@12' as RtlEqualString:dword
        extrn '__imp__RtlEqualUnicodeString@12' as RtlEqualUnicodeString:dword
        extrn '__imp__RtlFindClearBits@12' as RtlFindClearBits:dword
        extrn '__imp__RtlFindClearBitsAndSet@12' as RtlFindClearBitsAndSet:dword
        extrn '__imp__RtlFindFirstRunClear@8' as RtlFindFirstRunClear:dword
        extrn '__imp__RtlFindLongestRunClear@8' as RtlFindLongestRunClear:dword
        extrn '__imp__RtlFindMessage@20' as RtlFindMessage:dword
        extrn '__imp__RtlFindSetBits@12' as RtlFindSetBits:dword
        extrn '__imp__RtlFindSetBitsAndClear@12' as RtlFindSetBitsAndClear:dword
        extrn '__imp__RtlFindUnicodePrefix@12' as RtlFindUnicodePrefix:dword
        extrn '__imp__RtlFormatCurrentUserKeyPath@4' as RtlFormatCurrentUserKeyPath:dword
        extrn '__imp__RtlFreeAnsiString@4' as RtlFreeAnsiString:dword
        extrn '__imp__RtlFreeHeap@12' as RtlFreeHeap:dword
        extrn '__imp__RtlFreeOemString@4' as RtlFreeOemString:dword
        extrn '__imp__RtlFreeUnicodeString@4' as RtlFreeUnicodeString:dword
        extrn '__imp__RtlGenerate8dot3Name@16' as RtlGenerate8dot3Name:dword
        extrn '__imp__RtlGetCallersAddress@8' as RtlGetCallersAddress:dword
        extrn '__imp__RtlGetCompressionWorkSpaceSize@12' as RtlGetCompressionWorkSpaceSize:dword
        extrn '__imp__RtlGetDaclSecurityDescriptor@16' as RtlGetDaclSecurityDescriptor:dword
        extrn '__imp__RtlGetDefaultCodePage@8' as RtlGetDefaultCodePage:dword
        extrn '__imp__RtlGetElementGenericTable@8' as RtlGetElementGenericTable:dword
        extrn '__imp__RtlGetGroupSecurityDescriptor@12' as RtlGetGroupSecurityDescriptor:dword
        extrn '__imp__RtlGetOwnerSecurityDescriptor@12' as RtlGetOwnerSecurityDescriptor:dword
        extrn '__imp__RtlImageNtHeader@4' as RtlImageNtHeader:dword
        extrn '__imp__RtlInitAnsiString@8' as RtlInitAnsiString:dword
        extrn '__imp__RtlInitCodePageTable@8' as RtlInitCodePageTable:dword
        extrn '__imp__RtlInitializeBitMap@12' as RtlInitializeBitMap:dword
        extrn '__imp__RtlInitializeGenericTable@20' as RtlInitializeGenericTable:dword
        extrn '__imp__RtlInitializeSid@12' as RtlInitializeSid:dword
        extrn '__imp__RtlInitializeUnicodePrefix@4' as RtlInitializeUnicodePrefix:dword
        extrn '__imp__RtlInitString@8' as RtlInitString:dword
        extrn '__imp__RtlInitUnicodeString@8' as RtlInitUnicodeString:dword
        extrn '__imp__RtlInsertElementGenericTable@16' as RtlInsertElementGenericTable:dword
        extrn '__imp__RtlInsertUnicodePrefix@12' as RtlInsertUnicodePrefix:dword
        extrn '__imp__RtlIntegerToChar@16' as RtlIntegerToChar:dword
        extrn '__imp__RtlIntegerToUnicodeString@12' as RtlIntegerToUnicodeString:dword
        extrn '__imp__RtlIsNameLegalDOS8Dot3@12' as RtlIsNameLegalDOS8Dot3:dword
        extrn '__imp__RtlLengthRequiredSid@4' as RtlLengthRequiredSid:dword
        extrn '__imp__RtlLengthSecurityDescriptor@4' as RtlLengthSecurityDescriptor:dword
        extrn '__imp__RtlLengthSid@4' as RtlLengthSid:dword
        extrn '__imp__RtlLookupAtomInAtomTable@12' as RtlLookupAtomInAtomTable:dword
        extrn '__imp__RtlLookupElementGenericTable@8' as RtlLookupElementGenericTable:dword
        extrn '__imp__RtlMapGenericMask@8' as RtlMapGenericMask:dword
        extrn '__imp__RtlMultiByteToUnicodeN@20' as RtlMultiByteToUnicodeN:dword
        extrn '__imp__RtlMultiByteToUnicodeSize@12' as RtlMultiByteToUnicodeSize:dword
        extrn '__imp__RtlNextUnicodePrefix@8' as RtlNextUnicodePrefix:dword
        extrn '__imp__RtlNtStatusToDosError@4' as RtlNtStatusToDosError:dword
        extrn '__imp__RtlNtStatusToDosErrorNoTeb@4' as RtlNtStatusToDosErrorNoTeb:dword
        extrn '__imp__RtlNumberGenericTableElements@4' as RtlNumberGenericTableElements:dword
        extrn '__imp__RtlNumberOfClearBits@4' as RtlNumberOfClearBits:dword
        extrn '__imp__RtlNumberOfSetBits@4' as RtlNumberOfSetBits:dword
        extrn '__imp__RtlOemStringToCountedUnicodeString@12' as RtlOemStringToCountedUnicodeString:dword
        extrn '__imp__RtlOemStringToUnicodeSize@4' as RtlOemStringToUnicodeSize:dword
        extrn '__imp__RtlOemStringToUnicodeString@12' as RtlOemStringToUnicodeString:dword
        extrn '__imp__RtlOemToUnicodeN@20' as RtlOemToUnicodeN:dword
        extrn '__imp__RtlPinAtomInAtomTable@8' as RtlPinAtomInAtomTable:dword
        extrn '__imp__RtlPrefixString@12' as RtlPrefixString:dword
        extrn '__imp__RtlPrefixUnicodeString@12' as RtlPrefixUnicodeString:dword
        extrn '__imp__RtlQueryAtomInAtomTable@24' as RtlQueryAtomInAtomTable:dword
        extrn '__imp__RtlQueryRegistryValues@20' as RtlQueryRegistryValues:dword
        extrn '__imp__RtlQueryTimeZoneInformation@4' as RtlQueryTimeZoneInformation:dword
        extrn '__imp__RtlRaiseException@4' as RtlRaiseException:dword
        extrn '__imp__RtlRandom@4' as RtlRandom:dword
        extrn '__imp__RtlRemoveUnicodePrefix@8' as RtlRemoveUnicodePrefix:dword
        extrn '__imp__RtlReserveChunk@20' as RtlReserveChunk:dword
        extrn '__imp__RtlSecondsSince1970ToTime@8' as RtlSecondsSince1970ToTime:dword
        extrn '__imp__RtlSecondsSince1980ToTime@8' as RtlSecondsSince1980ToTime:dword
        extrn '__imp__RtlSetAllBits@4' as RtlSetAllBits:dword
        extrn '__imp__RtlSetBits@12' as RtlSetBits:dword
        extrn '__imp__RtlSetDaclSecurityDescriptor@16' as RtlSetDaclSecurityDescriptor:dword
        extrn '__imp__RtlSetGroupSecurityDescriptor@12' as RtlSetGroupSecurityDescriptor:dword
        extrn '__imp__RtlSetOwnerSecurityDescriptor@12' as RtlSetOwnerSecurityDescriptor:dword
        extrn '__imp__RtlSetSaclSecurityDescriptor@16' as RtlSetSaclSecurityDescriptor:dword
        extrn '__imp__RtlSetTimeZoneInformation@4' as RtlSetTimeZoneInformation:dword
        extrn '__imp__RtlSplay@4' as RtlSplay:dword
        extrn '__imp__RtlSubAuthorityCountSid@4' as RtlSubAuthorityCountSid:dword
        extrn '__imp__RtlSubAuthoritySid@8' as RtlSubAuthoritySid:dword
        extrn '__imp__RtlTimeFieldsToTime@8' as RtlTimeFieldsToTime:dword
        extrn '__imp__RtlTimeToSecondsSince1970@8' as RtlTimeToSecondsSince1970:dword
        extrn '__imp__RtlTimeToSecondsSince1980@8' as RtlTimeToSecondsSince1980:dword
        extrn '__imp__RtlTimeToTimeFields@8' as RtlTimeToTimeFields:dword
        extrn '__imp__RtlUnicodeStringToAnsiSize@4' as RtlUnicodeStringToAnsiSize:dword
        extrn '__imp__RtlUnicodeStringToAnsiString@12' as RtlUnicodeStringToAnsiString:dword
        extrn '__imp__RtlUnicodeStringToCountedOemString@12' as RtlUnicodeStringToCountedOemString:dword
        extrn '__imp__RtlUnicodeStringToInteger@12' as RtlUnicodeStringToInteger:dword
        extrn '__imp__RtlUnicodeStringToOemSize@4' as RtlUnicodeStringToOemSize:dword
        extrn '__imp__RtlUnicodeStringToOemString@12' as RtlUnicodeStringToOemString:dword
        extrn '__imp__RtlUnicodeToCustomCPN@24' as RtlUnicodeToCustomCPN:dword
        extrn '__imp__RtlUnicodeToMultiByteN@20' as RtlUnicodeToMultiByteN:dword
        extrn '__imp__RtlUnicodeToMultiByteSize@12' as RtlUnicodeToMultiByteSize:dword
        extrn '__imp__RtlUnicodeToOemN@20' as RtlUnicodeToOemN:dword
        extrn '__imp__RtlUnwindEx@24' as RtlUnwindEx:dword
        extrn '__imp__RtlUpcaseUnicodeChar@4' as RtlUpcaseUnicodeChar:dword
        extrn '__imp__RtlUpcaseUnicodeString@12' as RtlUpcaseUnicodeString:dword
        extrn '__imp__RtlUpcaseUnicodeStringToAnsiString@12' as RtlUpcaseUnicodeStringToAnsiString:dword
        extrn '__imp__RtlUpcaseUnicodeStringToCountedOemString@12' as RtlUpcaseUnicodeStringToCountedOemString:dword
        extrn '__imp__RtlUpcaseUnicodeStringToOemString@12' as RtlUpcaseUnicodeStringToOemString:dword
        extrn '__imp__RtlUpcaseUnicodeToCustomCPN@24' as RtlUpcaseUnicodeToCustomCPN:dword
        extrn '__imp__RtlUpcaseUnicodeToMultiByteN@20' as RtlUpcaseUnicodeToMultiByteN:dword
        extrn '__imp__RtlUpcaseUnicodeToOemN@20' as RtlUpcaseUnicodeToOemN:dword
        extrn '__imp__RtlUpperChar@4' as RtlUpperChar:dword
        extrn '__imp__RtlUpperString@8' as RtlUpperString:dword
        extrn '__imp__RtlValidSecurityDescriptor@4' as RtlValidSecurityDescriptor:dword
        extrn '__imp__RtlValidSid@4' as RtlValidSid:dword
        extrn '__imp__RtlWriteRegistryValue@24' as RtlWriteRegistryValue:dword
        extrn '__imp__RtlxAnsiStringToUnicodeSize@4' as RtlxAnsiStringToUnicodeSize:dword
        extrn '__imp__RtlxOemStringToUnicodeSize@4' as RtlxOemStringToUnicodeSize:dword
        extrn '__imp__RtlxUnicodeStringToAnsiSize@4' as RtlxUnicodeStringToAnsiSize:dword
        extrn '__imp__RtlxUnicodeStringToOemSize@4' as RtlxUnicodeStringToOemSize:dword
        extrn '__imp__RtlZeroHeap@8' as RtlZeroHeap:dword
        extrn '__imp__SeAccessCheck@40' as SeAccessCheck:dword
        extrn '__imp__SeAppendPrivileges@8' as SeAppendPrivileges:dword
        extrn '__imp__SeAssignSecurity@28' as SeAssignSecurity:dword
        extrn '__imp__SeAuditingFileEvents@8' as SeAuditingFileEvents:dword
        extrn '__imp__SeAuditingFileOrGlobalEvents@12' as SeAuditingFileOrGlobalEvents:dword
        extrn '__imp__SeCaptureSecurityDescriptor@20' as SeCaptureSecurityDescriptor:dword
        extrn '__imp__SeCaptureSubjectContext@4' as SeCaptureSubjectContext:dword
        extrn '__imp__SeCloseObjectAuditAlarm@12' as SeCloseObjectAuditAlarm:dword
        extrn '__imp__SeCreateAccessState@16' as SeCreateAccessState:dword
        extrn '__imp__SeCreateClientSecurity@16' as SeCreateClientSecurity:dword
        extrn '__imp__SeDeassignSecurity@4' as SeDeassignSecurity:dword
        extrn '__imp__SeDeleteAccessState@4' as SeDeleteAccessState:dword
        extrn '__imp__SeDeleteObjectAuditAlarm@8' as SeDeleteObjectAuditAlarm:dword
        extrn '__imp__SeFreePrivileges@4' as SeFreePrivileges:dword
        extrn '__imp__SeImpersonateClient@8' as SeImpersonateClient:dword
        extrn '__imp__SeLockSubjectContext@4' as SeLockSubjectContext:dword
        extrn '__imp__SeMarkLogonSessionForTerminationNotification@4' as SeMarkLogonSessionForTerminationNotification:dword
        extrn '__imp__SeOpenObjectAuditAlarm@36' as SeOpenObjectAuditAlarm:dword
        extrn '__imp__SeOpenObjectForDeleteAuditAlarm@36' as SeOpenObjectForDeleteAuditAlarm:dword
        extrn '__imp__SePrivilegeCheck@12' as SePrivilegeCheck:dword
        extrn '__imp__SePrivilegeObjectAuditAlarm@24' as SePrivilegeObjectAuditAlarm:dword
        extrn '__imp__SeQueryAuthenticationIdToken@8' as SeQueryAuthenticationIdToken:dword
        extrn '__imp__SeQuerySecurityDescriptorInfo@16' as SeQuerySecurityDescriptorInfo:dword
        extrn '__imp__SeRegisterLogonSessionTerminatedRoutine@4' as SeRegisterLogonSessionTerminatedRoutine:dword
        extrn '__imp__SeReleaseSecurityDescriptor@12' as SeReleaseSecurityDescriptor:dword
        extrn '__imp__SeReleaseSubjectContext@4' as SeReleaseSubjectContext:dword
        extrn '__imp__SeSetAccessStateGenericMapping@8' as SeSetAccessStateGenericMapping:dword
        extrn '__imp__SeSetSecurityDescriptorInfo@24' as SeSetSecurityDescriptorInfo:dword
        extrn '__imp__SeSinglePrivilegeCheck@12' as SeSinglePrivilegeCheck:dword
        extrn '__imp__SeTokenImpersonationLevel@4' as SeTokenImpersonationLevel:dword
        extrn '__imp__SeTokenType@4' as SeTokenType:dword
        extrn '__imp__SeUnlockSubjectContext@4' as SeUnlockSubjectContext:dword
        extrn '__imp__SeUnregisterLogonSessionTerminatedRoutine@4' as SeUnregisterLogonSessionTerminatedRoutine:dword
        extrn '__imp__SeValidSecurityDescriptor@8' as SeValidSecurityDescriptor:dword
        if ~defined __imp__tolower
            extrn '__imp__tolower@4' as tolower:dword
        end if
        if ~defined __imp__toupper
            extrn '__imp__toupper@4' as toupper:dword
        end if
        if ~defined __imp__towlower
            extrn '__imp__towlower@4' as towlower:dword
        end if
        if ~defined __imp__towupper
            extrn '__imp__towupper@4' as towupper:dword
        end if
        if ~defined __imp__vsprintf
            extrn '__imp__vsprintf@12' as vsprintf:dword
        end if
        if ~defined __imp__wcscat
            extrn '__imp__wcscat@8' as wcscat:dword
            extrn '__imp__wcschr@8' as wcschr:dword
            extrn '__imp__wcscmp@8' as wcscmp:dword
            extrn '__imp__wcscpy@8' as wcscpy:dword
            extrn '__imp__wcscspn@8' as wcscspn:dword
            extrn '__imp__wcslen@4' as wcslen:dword
            extrn '__imp__wcsncat@12' as wcsncat:dword
            extrn '__imp__wcsncmp@12' as wcsncmp:dword
            extrn '__imp__wcsncpy@12' as wcsncpy:dword
            extrn '__imp__wcsrchr@8' as wcsrchr:dword
            extrn '__imp__wcsspn@8' as wcsspn:dword
            extrn '__imp__wcsstr@8' as wcsstr:dword
            extrn '__imp__wcstombs@12' as wcstombs:dword
            extrn '__imp__wctomb@8' as wctomb:dword
        end if
        extrn '__imp__ZwAccessCheckAndAuditAlarm@44' as ZwAccessCheckAndAuditAlarm:dword
        extrn '__imp__ZwAlertThread@4' as ZwAlertThread:dword
        extrn '__imp__ZwAllocateVirtualMemory@24' as ZwAllocateVirtualMemory:dword
        extrn '__imp__ZwClearEvent@4' as ZwClearEvent:dword
        extrn '__imp__ZwClose@4' as ZwClose:dword
        extrn '__imp__ZwCloseObjectAuditAlarm@12' as ZwCloseObjectAuditAlarm:dword
        extrn '__imp__ZwConnectPort@32' as ZwConnectPort:dword
        extrn '__imp__ZwCreateDirectoryObject@12' as ZwCreateDirectoryObject:dword
        extrn '__imp__ZwCreateEvent@20' as ZwCreateEvent:dword
        extrn '__imp__ZwCreateFile@44' as ZwCreateFile:dword
        extrn '__imp__ZwCreateKey@28' as ZwCreateKey:dword
        extrn '__imp__ZwCreateSection@28' as ZwCreateSection:dword
        extrn '__imp__ZwCreateSymbolicLinkObject@16' as ZwCreateSymbolicLinkObject:dword
        extrn '__imp__ZwDeleteFile@4' as ZwDeleteFile:dword
        extrn '__imp__ZwDeleteKey@4' as ZwDeleteKey:dword
        extrn '__imp__ZwDeleteValueKey@8' as ZwDeleteValueKey:dword
        extrn '__imp__ZwDeviceIoControlFile@40' as ZwDeviceIoControlFile:dword
        extrn '__imp__ZwDisplayString@4' as ZwDisplayString:dword
        extrn '__imp__ZwDuplicateObject@28' as ZwDuplicateObject:dword
        extrn '__imp__ZwDuplicateToken@24' as ZwDuplicateToken:dword
        extrn '__imp__ZwEnumerateKey@24' as ZwEnumerateKey:dword
        extrn '__imp__ZwEnumerateValueKey@24' as ZwEnumerateValueKey:dword
        extrn '__imp__ZwFlushInstructionCache@12' as ZwFlushInstructionCache:dword
        extrn '__imp__ZwFlushKey@4' as ZwFlushKey:dword
        extrn '__imp__ZwFreeVirtualMemory@16' as ZwFreeVirtualMemory:dword
        extrn '__imp__ZwFsControlFile@40' as ZwFsControlFile:dword
        extrn '__imp__ZwLoadDriver@4' as ZwLoadDriver:dword
        extrn '__imp__ZwLoadKey@8' as ZwLoadKey:dword
        extrn '__imp__ZwMakeTemporaryObject@4' as ZwMakeTemporaryObject:dword
        extrn '__imp__ZwMapViewOfSection@40' as ZwMapViewOfSection:dword
        extrn '__imp__ZwNotifyChangeKey@40' as ZwNotifyChangeKey:dword
        extrn '__imp__ZwOpenDirectoryObject@12' as ZwOpenDirectoryObject:dword
        extrn '__imp__ZwOpenEvent@12' as ZwOpenEvent:dword
        extrn '__imp__ZwOpenFile@24' as ZwOpenFile:dword
        extrn '__imp__ZwOpenKey@12' as ZwOpenKey:dword
        extrn '__imp__ZwOpenProcess@16' as ZwOpenProcess:dword
        extrn '__imp__ZwOpenProcessToken@12' as ZwOpenProcessToken:dword
        extrn '__imp__ZwOpenSection@12' as ZwOpenSection:dword
        extrn '__imp__ZwOpenSymbolicLinkObject@12' as ZwOpenSymbolicLinkObject:dword
        extrn '__imp__ZwOpenThread@16' as ZwOpenThread:dword
        extrn '__imp__ZwOpenThreadToken@16' as ZwOpenThreadToken:dword
        extrn '__imp__ZwPulseEvent@8' as ZwPulseEvent:dword
        extrn '__imp__ZwQueryDefaultLocale@8' as ZwQueryDefaultLocale:dword
        extrn '__imp__ZwQueryDirectoryFile@44' as ZwQueryDirectoryFile:dword
        extrn '__imp__ZwQueryInformationFile@20' as ZwQueryInformationFile:dword
        extrn '__imp__ZwQueryInformationProcess@20' as ZwQueryInformationProcess:dword
        extrn '__imp__ZwQueryInformationToken@20' as ZwQueryInformationToken:dword
        extrn '__imp__ZwQueryKey@20' as ZwQueryKey:dword
        extrn '__imp__ZwQueryObject@20' as ZwQueryObject:dword
        extrn '__imp__ZwQuerySection@20' as ZwQuerySection:dword
        extrn '__imp__ZwQuerySecurityObject@20' as ZwQuerySecurityObject:dword
        extrn '__imp__ZwQuerySymbolicLinkObject@12' as ZwQuerySymbolicLinkObject:dword
        extrn '__imp__ZwQuerySystemInformation@16' as ZwQuerySystemInformation:dword
        extrn '__imp__ZwQueryValueKey@24' as ZwQueryValueKey:dword
        extrn '__imp__ZwQueryVolumeInformationFile@20' as ZwQueryVolumeInformationFile:dword
        extrn '__imp__ZwReadFile@36' as ZwReadFile:dword
        extrn '__imp__ZwReplaceKey@12' as ZwReplaceKey:dword
        extrn '__imp__ZwRequestWaitReplyPort@12' as ZwRequestWaitReplyPort:dword
        extrn '__imp__ZwResetEvent@8' as ZwResetEvent:dword
        extrn '__imp__ZwSaveKey@8' as ZwSaveKey:dword
        extrn '__imp__ZwSetDefaultLocale@8' as ZwSetDefaultLocale:dword
        extrn '__imp__ZwSetEvent@8' as ZwSetEvent:dword
        extrn '__imp__ZwSetInformationFile@20' as ZwSetInformationFile:dword
        extrn '__imp__ZwSetInformationObject@16' as ZwSetInformationObject:dword
        extrn '__imp__ZwSetInformationProcess@16' as ZwSetInformationProcess:dword
        extrn '__imp__ZwSetInformationThread@16' as ZwSetInformationThread:dword
        extrn '__imp__ZwSetSystemInformation@12' as ZwSetSystemInformation:dword
        extrn '__imp__ZwSetSystemTime@8' as ZwSetSystemTime:dword
        extrn '__imp__ZwSetValueKey@24' as ZwSetValueKey:dword
        extrn '__imp__ZwTerminateProcess@8' as ZwTerminateProcess:dword
        extrn '__imp__ZwUnloadDriver@4' as ZwUnloadDriver:dword
        extrn '__imp__ZwUnloadKey@4' as ZwUnloadKey:dword
        extrn '__imp__ZwUnmapViewOfSection@8' as ZwUnmapViewOfSection:dword
        extrn '__imp__ZwWaitForMultipleObjects@20' as ZwWaitForMultipleObjects:dword
        extrn '__imp__ZwWaitForSingleObject@12' as ZwWaitForSingleObject:dword
        extrn '__imp__ZwWriteFile@36' as ZwWriteFile:dword
        extrn '__imp__ZwYieldExecution@0' as ZwYieldExecution:dword
        extrn '__imp___itoa@12' as _itoa:dword
        extrn '__imp___purecall@0' as _purecall:dword
        extrn '__imp___snprintf@16' as _snprintf:dword
        extrn '__imp___stricmp@8' as _stricmp:dword
        extrn '__imp___strlwr@4' as _strlwr:dword
        extrn '__imp___strnicmp@12' as _strnicmp:dword
        extrn '__imp___strnset@12' as _strnset:dword
        extrn '__imp___strrev@4' as _strrev:dword
        extrn '__imp___strset@8' as _strset:dword
        extrn '__imp___strupr@4' as _strupr:dword
        extrn '__imp___vsnprintf@16' as _vsnprintf:dword
        extrn '__imp___wcsicmp@8' as _wcsicmp:dword
        extrn '__imp___wcslwr@4' as _wcslwr:dword
        extrn '__imp___wcsnicmp@12' as _wcsnicmp:dword
        extrn '__imp___wcsnset@12' as _wcsnset:dword
        extrn '__imp___wcsrev@4' as _wcsrev:dword
        extrn '__imp___wcsupr@4' as _wcsupr:dword

        if (NTDDI_VERSION >= NTDDI_WIN2K)
            extrn '__imp__CcGetFlushedValidData@8' as CcGetFlushedValidData:dword
            extrn '__imp__CcRemapBcb@4' as CcRemapBcb:dword
            extrn '__imp__CcWaitForCurrentLazyWriterActivity@0' as CcWaitForCurrentLazyWriterActivity:dword
            extrn '__imp__ExFreePoolWithTag@8' as ExFreePoolWithTag:dword
            extrn '__imp__ExSetTimerResolution@8' as ExSetTimerResolution:dword
            extrn '__imp__ExUuidCreate@4' as ExUuidCreate:dword
            extrn '__imp__FsRtlAllocateFileLock@8' as FsRtlAllocateFileLock:dword
            extrn '__imp__FsRtlCreateSectionForDataScan@40' as FsRtlCreateSectionForDataScan:dword
            extrn '__imp__FsRtlFreeFileLock@4' as FsRtlFreeFileLock:dword
            extrn '__imp__FsRtlInsertPerFileObjectContext@8' as FsRtlInsertPerFileObjectContext:dword
            extrn '__imp__FsRtlInsertPerStreamContext@8' as FsRtlInsertPerStreamContext:dword
            extrn '__imp__FsRtlIsPagingFile@4' as FsRtlIsPagingFile:dword
            extrn '__imp__FsRtlLookupLastLargeMcbEntryAndIndex@16' as FsRtlLookupLastLargeMcbEntryAndIndex:dword
            extrn '__imp__FsRtlLookupPerFileObjectContext@12' as FsRtlLookupPerFileObjectContext:dword
            extrn '__imp__FsRtlLookupPerStreamContextInternal@12' as FsRtlLookupPerStreamContextInternal:dword
            extrn '__imp__FsRtlNotifyFilterChangeDirectory@44' as FsRtlNotifyFilterChangeDirectory:dword
            extrn '__imp__FsRtlNotifyFilterReportChange@40' as FsRtlNotifyFilterReportChange:dword
            extrn '__imp__FsRtlNotifyVolumeEvent@8' as FsRtlNotifyVolumeEvent:dword
            extrn '__imp__FsRtlRegisterFileSystemFilterCallbacks@8' as FsRtlRegisterFileSystemFilterCallbacks:dword
            extrn '__imp__FsRtlReleaseFile@4' as FsRtlReleaseFile:dword
            extrn '__imp__FsRtlRemovePerFileObjectContext@12' as FsRtlRemovePerFileObjectContext:dword
            extrn '__imp__FsRtlRemovePerStreamContext@12' as FsRtlRemovePerStreamContext:dword
            extrn '__imp__FsRtlResetBaseMcb@4' as FsRtlResetBaseMcb:dword
            extrn '__imp__FsRtlResetLargeMcb@8' as FsRtlResetLargeMcb:dword
            extrn '__imp__FsRtlTeardownPerStreamContexts@4' as FsRtlTeardownPerStreamContexts:dword
            extrn '__imp__InbvAcquireDisplayOwnership@0' as InbvAcquireDisplayOwnership:dword
            extrn '__imp__InbvCheckDisplayOwnership@0' as InbvCheckDisplayOwnership:dword
            extrn '__imp__InbvDisplayString@4' as InbvDisplayString:dword
            extrn '__imp__InbvEnableBootDriver@4' as InbvEnableBootDriver:dword
            extrn '__imp__InbvEnableDisplayString@4' as InbvEnableDisplayString:dword
            extrn '__imp__InbvInstallDisplayStringFilter@4' as InbvInstallDisplayStringFilter:dword
            extrn '__imp__InbvIsBootDriverInstalled@0' as InbvIsBootDriverInstalled:dword
            extrn '__imp__InbvNotifyDisplayOwnershipLost@4' as InbvNotifyDisplayOwnershipLost:dword
            extrn '__imp__InbvResetDisplay@0' as InbvResetDisplay:dword
            extrn '__imp__InbvSetScrollRegion@16' as InbvSetScrollRegion:dword
            extrn '__imp__InbvSetTextColor@4' as InbvSetTextColor:dword
            extrn '__imp__InbvSolidColorFill@20' as InbvSolidColorFill:dword
            extrn '__imp__IoAcquireCancelSpinLock@4' as IoAcquireCancelSpinLock:dword
            extrn '__imp__IoAcquireRemoveLockEx@20' as IoAcquireRemoveLockEx:dword
            extrn '__imp__IoAllocateDriverObjectExtension@16' as IoAllocateDriverObjectExtension:dword
            extrn '__imp__IoAllocateWorkItem@4' as IoAllocateWorkItem:dword
            extrn '__imp__IoAttachDeviceToDeviceStackSafe@12' as IoAttachDeviceToDeviceStackSafe:dword
            extrn '__imp__IoCancelFileOpen@8' as IoCancelFileOpen:dword
            extrn '__imp__IoCheckQuerySetFileInformation@12' as IoCheckQuerySetFileInformation:dword
            extrn '__imp__IoCheckQuerySetVolumeInformation@12' as IoCheckQuerySetVolumeInformation:dword
            extrn '__imp__IoCheckQuotaBufferValidity@12' as IoCheckQuotaBufferValidity:dword
            extrn '__imp__IoCreateDriver@8' as IoCreateDriver:dword
            extrn '__imp__IoCreateFileSpecifyDeviceObjectHint@60' as IoCreateFileSpecifyDeviceObjectHint:dword
            extrn '__imp__IoCreateStreamFileObjectLite@8' as IoCreateStreamFileObjectLite:dword
            extrn '__imp__IoDeleteDriver@4' as IoDeleteDriver:dword
            extrn '__imp__IoEnumerateDeviceObjectList@16' as IoEnumerateDeviceObjectList:dword
            extrn '__imp__IoEnumerateRegisteredFiltersList@12' as IoEnumerateRegisteredFiltersList:dword
            extrn '__imp__IoFreeWorkItem@4' as IoFreeWorkItem:dword
            extrn '__imp__IoGetAttachedDeviceReference@4' as IoGetAttachedDeviceReference:dword
            extrn '__imp__IoGetBootDiskInformation@8' as IoGetBootDiskInformation:dword
            extrn '__imp__IoGetDeviceAttachmentBaseRef@4' as IoGetDeviceAttachmentBaseRef:dword
            extrn '__imp__IoGetDeviceInterfaceAlias@12' as IoGetDeviceInterfaceAlias:dword
            extrn '__imp__IoGetDeviceInterfaces@16' as IoGetDeviceInterfaces:dword
            extrn '__imp__IoGetDeviceProperty@20' as IoGetDeviceProperty:dword
            extrn '__imp__IoGetDiskDeviceObject@8' as IoGetDiskDeviceObject:dword
            extrn '__imp__IoGetDmaAdapter@12' as IoGetDmaAdapter:dword
            extrn '__imp__IoGetDriverObjectExtension@8' as IoGetDriverObjectExtension:dword
            extrn '__imp__IoGetLowerDeviceObject@4' as IoGetLowerDeviceObject:dword
            extrn '__imp__IoGetRequestorProcessId@4' as IoGetRequestorProcessId:dword
            extrn '__imp__IoGetRequestorSessionId@8' as IoGetRequestorSessionId:dword
            extrn '__imp__IoInitializeRemoveLockEx@20' as IoInitializeRemoveLockEx:dword
            extrn '__imp__IoInvalidateDeviceRelations@8' as IoInvalidateDeviceRelations:dword
            extrn '__imp__IoInvalidateDeviceState@4' as IoInvalidateDeviceState:dword
            extrn '__imp__IoIsFileOriginRemote@4' as IoIsFileOriginRemote:dword
            extrn '__imp__IoIsValidNameGraftingBuffer@8' as IoIsValidNameGraftingBuffer:dword
            extrn '__imp__IoIsWdmVersionAvailable@8' as IoIsWdmVersionAvailable:dword
            extrn '__imp__IoOpenDeviceInterfaceRegistryKey@12' as IoOpenDeviceInterfaceRegistryKey:dword
            extrn '__imp__IoOpenDeviceRegistryKey@16' as IoOpenDeviceRegistryKey:dword
            extrn '__imp__IoQueueWorkItem@16' as IoQueueWorkItem:dword
            extrn '__imp__IoRegisterBootDriverReinitialization@12' as IoRegisterBootDriverReinitialization:dword
            extrn '__imp__IoRegisterDeviceInterface@16' as IoRegisterDeviceInterface:dword
            extrn '__imp__IoRegisterLastChanceShutdownNotification@4' as IoRegisterLastChanceShutdownNotification:dword
            extrn '__imp__IoRegisterPlugPlayNotification@28' as IoRegisterPlugPlayNotification:dword
            extrn '__imp__IoReleaseRemoveLockAndWaitEx@12' as IoReleaseRemoveLockAndWaitEx:dword
            extrn '__imp__IoReleaseRemoveLockEx@12' as IoReleaseRemoveLockEx:dword
            extrn '__imp__IoReportDetectedDevice@32' as IoReportDetectedDevice:dword
            extrn '__imp__IoReportResourceForDetection@28' as IoReportResourceForDetection:dword
            extrn '__imp__IoReportTargetDeviceChange@8' as IoReportTargetDeviceChange:dword
            extrn '__imp__IoReportTargetDeviceChangeAsynchronous@16' as IoReportTargetDeviceChangeAsynchronous:dword
            extrn '__imp__IoRequestDeviceEject@4' as IoRequestDeviceEject:dword
            extrn '__imp__IoReuseIrp@8' as IoReuseIrp:dword
            extrn '__imp__IoSetDeviceInterfaceState@8' as IoSetDeviceInterfaceState:dword
            extrn '__imp__IoSetFileOrigin@8' as IoSetFileOrigin:dword
            extrn '__imp__IoSetIoCompletion@24' as IoSetIoCompletion:dword
            extrn '__imp__IoSynchronousInvalidateDeviceRelations@8' as IoSynchronousInvalidateDeviceRelations:dword
            extrn '__imp__IoUnregisterPlugPlayNotification@4' as IoUnregisterPlugPlayNotification:dword
            extrn '__imp__IoVolumeDeviceToDosName@8' as IoVolumeDeviceToDosName:dword
            extrn '__imp__IoWMIAllocateInstanceIds@12' as IoWMIAllocateInstanceIds:dword
            extrn '__imp__IoWMIRegistrationControl@8' as IoWMIRegistrationControl:dword
            extrn '__imp__IoWMISuggestInstanceName@16' as IoWMISuggestInstanceName:dword
            extrn '__imp__IoWMIWriteEvent@4' as IoWMIWriteEvent:dword
            extrn '__imp__KdDisableDebugger@0' as KdDisableDebugger:dword
            extrn '__imp__KdEnableDebugger@0' as KdEnableDebugger:dword
            extrn '__imp__KeQueryActiveProcessors@0' as KeQueryActiveProcessors:dword
            extrn '__imp__KeQueryPriorityThread@4' as KeQueryPriorityThread:dword
            extrn '__imp__KeSaveStateForHibernate@4' as KeSaveStateForHibernate:dword
            extrn '__imp__KeSetSystemAffinityThread@4' as KeSetSystemAffinityThread:dword
            extrn '__imp__KeStackAttachProcess@8' as KeStackAttachProcess:dword
            extrn '__imp__KeUnstackDetachProcess@4' as KeUnstackDetachProcess:dword
            extrn '__imp__LpcRequestWaitReplyPort@12' as LpcRequestWaitReplyPort:dword
            extrn '__imp__MmAddPhysicalMemory@8' as MmAddPhysicalMemory:dword
            extrn '__imp__MmAddVerifierThunks@8' as MmAddVerifierThunks:dword
            extrn '__imp__MmAllocateContiguousMemorySpecifyCache@20' as MmAllocateContiguousMemorySpecifyCache:dword
            extrn '__imp__MmAllocateMappingAddress@8' as MmAllocateMappingAddress:dword
            extrn '__imp__MmAllocatePagesForMdl@16' as MmAllocatePagesForMdl:dword
            extrn '__imp__MmCommitSessionMappedView@8' as MmCommitSessionMappedView:dword
            extrn '__imp__MmFreeContiguousMemorySpecifyCache@12' as MmFreeContiguousMemorySpecifyCache:dword
            extrn '__imp__MmFreeMappingAddress@8' as MmFreeMappingAddress:dword
            extrn '__imp__MmFreePagesFromMdl@4' as MmFreePagesFromMdl:dword
            extrn '__imp__MmGetPhysicalMemoryRanges@0' as MmGetPhysicalMemoryRanges:dword
            extrn '__imp__MmGetSystemRoutineAddress@4' as MmGetSystemRoutineAddress:dword
            extrn '__imp__MmGetVirtualForPhysical@8' as MmGetVirtualForPhysical:dword
            extrn '__imp__MmIsDriverVerifying@4' as MmIsDriverVerifying:dword
            extrn '__imp__MmIsVerifierEnabled@4' as MmIsVerifierEnabled:dword
            extrn '__imp__MmMapLockedPagesWithReservedMapping@16' as MmMapLockedPagesWithReservedMapping:dword
            extrn '__imp__MmMapUserAddressesToPage@12' as MmMapUserAddressesToPage:dword
            extrn '__imp__MmMapViewInSessionSpace@12' as MmMapViewInSessionSpace:dword
            extrn '__imp__MmProbeAndLockProcessPages@16' as MmProbeAndLockProcessPages:dword
            extrn '__imp__MmProbeAndLockSelectedPages@16' as MmProbeAndLockSelectedPages:dword
            extrn '__imp__MmRemovePhysicalMemory@8' as MmRemovePhysicalMemory:dword
            extrn '__imp__MmTrimAllSystemPagableMemory@4' as MmTrimAllSystemPagableMemory:dword
            extrn '__imp__MmUnmapReservedMapping@12' as MmUnmapReservedMapping:dword
            extrn '__imp__MmUnmapViewInSessionSpace@4' as MmUnmapViewInSessionSpace:dword
            extrn '__imp__NtQueryQuotaInformationFile@36' as NtQueryQuotaInformationFile:dword
            extrn '__imp__NtQuerySystemInformation@16' as NtQuerySystemInformation:dword
            extrn '__imp__NtSetEaFile@16' as NtSetEaFile:dword
            extrn '__imp__NtSetVolumeInformationFile@20' as NtSetVolumeInformationFile:dword
            extrn '__imp__ObCreateObjectType@16' as ObCreateObjectType:dword
            if (NTDDI_VERSION = NTDDI_WINXP)
                extrn '__imp__WmiTraceFastEvent@4' as WmiTraceFastEvent:dword
            else
                extrn '__imp__ObDeleteCapturedInsertInfo@4' as ObDeleteCapturedInsertInfo:dword
            end if
            extrn '__imp__PoCallDriver@8' as PoCallDriver:dword
            extrn '__imp__PoCancelDeviceNotify@4' as PoCancelDeviceNotify:dword
            extrn '__imp__PoRegisterDeviceForIdleDetection@16' as PoRegisterDeviceForIdleDetection:dword
            extrn '__imp__PoRegisterDeviceNotify@24' as PoRegisterDeviceNotify:dword
            extrn '__imp__PoRegisterSystemState@8' as PoRegisterSystemState:dword
            extrn '__imp__PoRequestPowerIrp@24' as PoRequestPowerIrp:dword
            extrn '__imp__PoSetHiberRange@20' as PoSetHiberRange:dword
            extrn '__imp__PoSetPowerState@12' as PoSetPowerState:dword
            extrn '__imp__PoSetSystemState@4' as PoSetSystemState:dword
            extrn '__imp__PoShutdownBugCheck@24' as PoShutdownBugCheck:dword
            extrn '__imp__PoStartNextPowerIrp@4' as PoStartNextPowerIrp:dword
            extrn '__imp__PoUnregisterSystemState@4' as PoUnregisterSystemState:dword
            extrn '__imp__ProbeForRead@12' as ProbeForRead:dword
            extrn '__imp__PsDisableImpersonation@8' as PsDisableImpersonation:dword
            extrn '__imp__PsGetProcessId@4' as PsGetProcessId:dword
            extrn '__imp__PsGetProcessImageFileName@4' as PsGetProcessImageFileName:dword
            extrn '__imp__PsRestoreImpersonation@8' as PsRestoreImpersonation:dword
            extrn '__imp__PsSetLoadImageNotifyRoutine@4' as PsSetLoadImageNotifyRoutine:dword
            extrn '__imp__RtlAddAccessAllowedAceEx@20' as RtlAddAccessAllowedAceEx:dword
            extrn '__imp__RtlAddRange@36' as RtlAddRange:dword
            extrn '__imp__RtlCaptureContext@4' as RtlCaptureContext:dword
            extrn '__imp__RtlCopyRangeList@8' as RtlCopyRangeList:dword
            extrn '__imp__RtlDeleteAce@8' as RtlDeleteAce:dword
            extrn '__imp__RtlDeleteOwnersRanges@8' as RtlDeleteOwnersRanges:dword
            extrn '__imp__RtlDeleteRange@24' as RtlDeleteRange:dword
            extrn '__imp__RtlFindClearRuns@16' as RtlFindClearRuns:dword
            extrn '__imp__RtlFindLastBackwardRunClear@12' as RtlFindLastBackwardRunClear:dword
            extrn '__imp__RtlFindLeastSignificantBit@8' as RtlFindLeastSignificantBit:dword
            extrn '__imp__RtlFindMostSignificantBit@8' as RtlFindMostSignificantBit:dword
            extrn '__imp__RtlFindNextForwardRunClear@12' as RtlFindNextForwardRunClear:dword
            extrn '__imp__RtlFindRange@48' as RtlFindRange:dword
            extrn '__imp__RtlFreeRangeList@4' as RtlFreeRangeList:dword
            extrn '__imp__RtlGetAce@12' as RtlGetAce:dword
            extrn '__imp__RtlGetFirstRange@12' as RtlGetFirstRange:dword
            extrn '__imp__RtlGetNextRange@12' as RtlGetNextRange:dword
            extrn '__imp__RtlGetNtGlobalFlags@0' as RtlGetNtGlobalFlags:dword
            extrn '__imp__RtlGetSaclSecurityDescriptor@16' as RtlGetSaclSecurityDescriptor:dword
            extrn '__imp__RtlGUIDFromString@8' as RtlGUIDFromString:dword
            extrn '__imp__RtlImageDirectoryEntryToData@16' as RtlImageDirectoryEntryToData:dword
            extrn '__imp__RtlInitializeRangeList@4' as RtlInitializeRangeList:dword
            extrn '__imp__RtlInsertElementGenericTableFull@24' as RtlInsertElementGenericTableFull:dword
            extrn '__imp__RtlInvertRangeList@8' as RtlInvertRangeList:dword
            extrn '__imp__RtlIsGenericTableEmpty@4' as RtlIsGenericTableEmpty:dword
            extrn '__imp__RtlIsRangeAvailable@40' as RtlIsRangeAvailable:dword
            extrn '__imp__RtlIsValidOemCharacter@4' as RtlIsValidOemCharacter:dword
            extrn '__imp__RtlLargeIntegerAdd@16' as RtlLargeIntegerAdd:dword
            extrn '__imp__RtlLookupElementGenericTableFull@16' as RtlLookupElementGenericTableFull:dword
            extrn '__imp__RtlMergeRangeLists@16' as RtlMergeRangeLists:dword
            extrn '__imp__RtlPrefetchMemoryNonTemporal@8' as RtlPrefetchMemoryNonTemporal:dword
            extrn '__imp__RtlRealPredecessor@4' as RtlRealPredecessor:dword
            extrn '__imp__RtlRealSuccessor@4' as RtlRealSuccessor:dword
            extrn '__imp__RtlSelfRelativeToAbsoluteSD@44' as RtlSelfRelativeToAbsoluteSD:dword
            extrn '__imp__RtlSelfRelativeToAbsoluteSD2@8' as RtlSelfRelativeToAbsoluteSD2:dword
            extrn '__imp__RtlSizeHeap@12' as RtlSizeHeap:dword
            extrn '__imp__RtlStringFromGUID@8' as RtlStringFromGUID:dword
            extrn '__imp__RtlSubtreePredecessor@4' as RtlSubtreePredecessor:dword
            extrn '__imp__RtlSubtreeSuccessor@4' as RtlSubtreeSuccessor:dword
            extrn '__imp__RtlTraceDatabaseAdd@16' as RtlTraceDatabaseAdd:dword
            extrn '__imp__RtlTraceDatabaseCreate@20' as RtlTraceDatabaseCreate:dword
            extrn '__imp__RtlTraceDatabaseDestroy@4' as RtlTraceDatabaseDestroy:dword
            extrn '__imp__RtlTraceDatabaseEnumerate@12' as RtlTraceDatabaseEnumerate:dword
            extrn '__imp__RtlTraceDatabaseFind@16' as RtlTraceDatabaseFind:dword
            extrn '__imp__RtlTraceDatabaseLock@4' as RtlTraceDatabaseLock:dword
            extrn '__imp__RtlTraceDatabaseUnlock@4' as RtlTraceDatabaseUnlock:dword
            extrn '__imp__RtlTraceDatabaseValidate@4' as RtlTraceDatabaseValidate:dword
            extrn '__imp__RtlValidRelativeSecurityDescriptor@12' as RtlValidRelativeSecurityDescriptor:dword
            extrn '__imp__RtlVolumeDeviceToDosName@8' as RtlVolumeDeviceToDosName:dword
            extrn '__imp__RtlWalkFrameChain@12' as RtlWalkFrameChain:dword
            extrn '__imp__SeAssignSecurityEx@36' as SeAssignSecurityEx:dword
            extrn '__imp__SeAuditHardLinkCreation@12' as SeAuditHardLinkCreation:dword
            extrn '__imp__SeAuditingHardLinkEvents@8' as SeAuditingHardLinkEvents:dword
            extrn '__imp__SeCreateClientSecurityFromSubjectContext@16' as SeCreateClientSecurityFromSubjectContext:dword
            extrn '__imp__SeImpersonateClientEx@8' as SeImpersonateClientEx:dword
            extrn '__imp__SeQueryInformationToken@12' as SeQueryInformationToken:dword
            extrn '__imp__SeQuerySessionIdToken@8' as SeQuerySessionIdToken:dword
            extrn '__imp__SeSetSecurityDescriptorInfoEx@28' as SeSetSecurityDescriptorInfoEx:dword
            extrn '__imp__SeTokenIsAdmin@4' as SeTokenIsAdmin:dword
            extrn '__imp__SeTokenIsRestricted@4' as SeTokenIsRestricted:dword
            extrn '__imp__VerSetConditionMask@12' as VerSetConditionMask:dword
            extrn '__imp__ZwAdjustPrivilegesToken@24' as ZwAdjustPrivilegesToken:dword
            extrn '__imp__ZwCancelIoFile@8' as ZwCancelIoFile:dword
            extrn '__imp__ZwCancelTimer@8' as ZwCancelTimer:dword
            extrn '__imp__ZwCreateTimer@16' as ZwCreateTimer:dword
            extrn '__imp__ZwFlushVirtualMemory@16' as ZwFlushVirtualMemory:dword
            extrn '__imp__ZwInitiatePowerAction@16' as ZwInitiatePowerAction:dword
            extrn '__imp__ZwOpenTimer@12' as ZwOpenTimer:dword
            extrn '__imp__ZwPowerInformation@20' as ZwPowerInformation:dword
            extrn '__imp__ZwQueryDefaultUILanguage@4' as ZwQueryDefaultUILanguage:dword
            extrn '__imp__ZwQueryDirectoryObject@28' as ZwQueryDirectoryObject:dword
            extrn '__imp__ZwQueryEaFile@36' as ZwQueryEaFile:dword
            extrn '__imp__ZwQueryInstallUILanguage@4' as ZwQueryInstallUILanguage:dword
            extrn '__imp__ZwRestoreKey@12' as ZwRestoreKey:dword
            extrn '__imp__ZwSetDefaultUILanguage@4' as ZwSetDefaultUILanguage:dword
            extrn '__imp__ZwSetEaFile@16' as ZwSetEaFile:dword
            extrn '__imp__ZwSetSecurityObject@12' as ZwSetSecurityObject:dword
            extrn '__imp__ZwSetTimer@28' as ZwSetTimer:dword
            extrn '__imp__ZwSetVolumeInformationFile@20' as ZwSetVolumeInformationFile:dword
            extrn '__imp___itow@12' as _itow:dword
        end if

        if (NTDDI_VERSION = NTDDI_WINXP | NTDDI_VERSION = NTDDI_VISTA)
            extrn '__imp__IoAssignDriveLetters@16' as IoAssignDriveLetters:dword
        end if

        if (NTDDI_VERSION >= NTDDI_WINXP)
            extrn '__imp__CcMdlWriteAbort@8' as CcMdlWriteAbort:dword
            extrn '__imp__CmRegisterCallback@12' as CmRegisterCallback:dword
            extrn '__imp__CmUnRegisterCallback@8' as CmUnRegisterCallback:dword
            extrn '__imp__DbgPrintEx@16' as DbgPrintEx:dword
            extrn '__imp__DbgPrintReturnControlC@8' as DbgPrintReturnControlC:dword
            extrn '__imp__DbgQueryDebugFilterState@8' as DbgQueryDebugFilterState:dword
            extrn '__imp__DbgSetDebugFilterState@12' as DbgSetDebugFilterState:dword
            extrn '__imp__ExAcquireRundownProtection@4' as ExAcquireRundownProtection:dword
            extrn '__imp__ExAcquireRundownProtectionEx@8' as ExAcquireRundownProtectionEx:dword
            extrn '__imp__ExAllocateFromPagedLookasideList@4' as ExAllocateFromPagedLookasideList:dword
            extrn '__imp__ExfAcquirePushLockExclusive@4' as ExfAcquirePushLockExclusive:dword
            extrn '__imp__ExfAcquirePushLockShared@4' as ExfAcquirePushLockShared:dword
            extrn '__imp__ExfReleasePushLock@4' as ExfReleasePushLock:dword
            extrn '__imp__ExGetCurrentProcessorCounts@12' as ExGetCurrentProcessorCounts:dword
            extrn '__imp__ExGetCurrentProcessorCpuUsage@4' as ExGetCurrentProcessorCpuUsage:dword
            extrn '__imp__ExInitializeRundownProtection@4' as ExInitializeRundownProtection:dword
            extrn '__imp__ExReInitializeRundownProtection@4' as ExReInitializeRundownProtection:dword
            extrn '__imp__ExReleaseRundownProtection@4' as ExReleaseRundownProtection:dword
            extrn '__imp__ExReleaseRundownProtectionEx@8' as ExReleaseRundownProtectionEx:dword
            extrn '__imp__ExRundownCompleted@4' as ExRundownCompleted:dword
            extrn '__imp__ExVerifySuite@4' as ExVerifySuite:dword
            extrn '__imp__ExWaitForRundownProtectionRelease@4' as ExWaitForRundownProtectionRelease:dword
            extrn '__imp__FsRtlAcquireFileExclusive@4' as FsRtlAcquireFileExclusive:dword
            extrn '__imp__FsRtlIncrementCcFastReadNotPossible@0' as FsRtlIncrementCcFastReadNotPossible:dword
            extrn '__imp__FsRtlIncrementCcFastReadNoWait@0' as FsRtlIncrementCcFastReadNoWait:dword
            extrn '__imp__FsRtlIncrementCcFastReadResourceMiss@0' as FsRtlIncrementCcFastReadResourceMiss:dword
            extrn '__imp__FsRtlIncrementCcFastReadWait@0' as FsRtlIncrementCcFastReadWait:dword
            extrn '__imp__HalExamineMBR@16' as HalExamineMBR:dword
            extrn '__imp__HeadlessDispatch@20' as HeadlessDispatch:dword
            extrn '__imp__InitializeSListHead@4' as InitializeSListHead:dword
            extrn '__imp__IoCreateDisk@8' as IoCreateDisk:dword
            extrn '__imp__IoCreateStreamFileObjectEx@12' as IoCreateStreamFileObjectEx:dword
            extrn '__imp__IoCsqInitialize@28' as IoCsqInitialize:dword
            extrn '__imp__IoCsqInsertIrp@12' as IoCsqInsertIrp:dword
            extrn '__imp__IoCsqRemoveIrp@8' as IoCsqRemoveIrp:dword
            extrn '__imp__IoCsqRemoveNextIrp@8' as IoCsqRemoveNextIrp:dword
            extrn '__imp__IoForwardAndCatchIrp@8' as IoForwardAndCatchIrp:dword
            extrn '__imp__IoForwardIrpSynchronously@8' as IoForwardIrpSynchronously:dword
            extrn '__imp__IoFreeErrorLogEntry@4' as IoFreeErrorLogEntry:dword
            extrn '__imp__IoQueryFileDosDeviceName@8' as IoQueryFileDosDeviceName:dword
            extrn '__imp__IoReadDiskSignature@12' as IoReadDiskSignature:dword
            extrn '__imp__IoReadPartitionTable@16' as IoReadPartitionTable:dword
            extrn '__imp__IoReadPartitionTableEx@8' as IoReadPartitionTableEx:dword
            extrn '__imp__IoSetCompletionRoutineEx@28' as IoSetCompletionRoutineEx:dword
            extrn '__imp__IoSetPartitionInformation@16' as IoSetPartitionInformation:dword
            extrn '__imp__IoSetPartitionInformationEx@12' as IoSetPartitionInformationEx:dword
            extrn '__imp__IoSetStartIoAttributes@12' as IoSetStartIoAttributes:dword
            extrn '__imp__IoSetSystemPartition@4' as IoSetSystemPartition:dword
            extrn '__imp__IoValidateDeviceIoControlAccess@8' as IoValidateDeviceIoControlAccess:dword
            extrn '__imp__IoVerifyPartitionTable@8' as IoVerifyPartitionTable:dword
            extrn '__imp__IoWMIDeviceObjectToInstanceName@12' as IoWMIDeviceObjectToInstanceName:dword
            extrn '__imp__IoWMIExecuteMethod@24' as IoWMIExecuteMethod:dword
            extrn '__imp__IoWMIHandleToInstanceName@12' as IoWMIHandleToInstanceName:dword
            extrn '__imp__IoWMIOpenBlock@12' as IoWMIOpenBlock:dword
            extrn '__imp__IoWMIQueryAllData@12' as IoWMIQueryAllData:dword
            extrn '__imp__IoWMIQueryAllDataMultiple@16' as IoWMIQueryAllDataMultiple:dword
            extrn '__imp__IoWMIQuerySingleInstance@16' as IoWMIQuerySingleInstance:dword
            extrn '__imp__IoWMIQuerySingleInstanceMultiple@20' as IoWMIQuerySingleInstanceMultiple:dword
            extrn '__imp__IoWMISetNotificationCallback@12' as IoWMISetNotificationCallback:dword
            extrn '__imp__IoWMISetSingleInstance@20' as IoWMISetSingleInstance:dword
            extrn '__imp__IoWMISetSingleItem@24' as IoWMISetSingleItem:dword
            extrn '__imp__IoWritePartitionTable@20' as IoWritePartitionTable:dword
            extrn '__imp__IoWritePartitionTableEx@8' as IoWritePartitionTableEx:dword
            extrn '__imp__KdPowerTransition@4' as KdPowerTransition:dword
            extrn '__imp__KeAcquireInStackQueuedSpinLockAtDpcLevel@8' as KeAcquireInStackQueuedSpinLockAtDpcLevel:dword
            extrn '__imp__KeAcquireInterruptSpinLock@4' as KeAcquireInterruptSpinLock:dword
            extrn '__imp__KeAreApcsDisabled@0' as KeAreApcsDisabled:dword
            extrn '__imp__KeCapturePersistentThreadState@32' as KeCapturePersistentThreadState:dword
            extrn '__imp__KeDeregisterBugCheckReasonCallback@4' as KeDeregisterBugCheckReasonCallback:dword
            extrn '__imp__KeFlushQueuedDpcs@0' as KeFlushQueuedDpcs:dword
            extrn '__imp__KeGetRecommendedSharedDataAlignment@0' as KeGetRecommendedSharedDataAlignment:dword
            extrn '__imp__KeIsAttachedProcess@0' as KeIsAttachedProcess:dword
            extrn '__imp__KeQueryRuntimeThread@8' as KeQueryRuntimeThread:dword
            extrn '__imp__KeRegisterBugCheckReasonCallback@16' as KeRegisterBugCheckReasonCallback:dword
            extrn '__imp__KeReleaseInterruptSpinLock@8' as KeReleaseInterruptSpinLock:dword
            extrn '__imp__KeRemoveByKeyDeviceQueueIfBusy@8' as KeRemoveByKeyDeviceQueueIfBusy:dword
            extrn '__imp__KeRemoveSystemServiceTable@4' as KeRemoveSystemServiceTable:dword
            extrn '__imp__KeRestoreExtendedProcessorState@4' as KeRestoreExtendedProcessorState:dword
            extrn '__imp__KeRevertToUserAffinityThreadEx@4' as KeRevertToUserAffinityThreadEx:dword
            extrn '__imp__MmAdvanceMdl@8' as MmAdvanceMdl:dword
            extrn '__imp__MmMarkPhysicalMemoryAsBad@8' as MmMarkPhysicalMemoryAsBad:dword
            extrn '__imp__MmMarkPhysicalMemoryAsGood@8' as MmMarkPhysicalMemoryAsGood:dword
            extrn '__imp__MmPrefetchPages@8' as MmPrefetchPages:dword
            extrn '__imp__MmProtectMdlSystemAddress@8' as MmProtectMdlSystemAddress:dword
            extrn '__imp__NtMakePermanentObject@4' as NtMakePermanentObject:dword
            extrn '__imp__NtOpenProcessTokenEx@16' as NtOpenProcessTokenEx:dword
            extrn '__imp__NtOpenThread@16' as NtOpenThread:dword
            extrn '__imp__NtOpenThreadToken@16' as NtOpenThreadToken:dword
            extrn '__imp__NtOpenThreadTokenEx@20' as NtOpenThreadTokenEx:dword
            extrn '__imp__NtQueryInformationThread@20' as NtQueryInformationThread:dword
            extrn '__imp__NtShutdownSystem@4' as NtShutdownSystem:dword
            extrn '__imp__NtTraceEvent@16' as NtTraceEvent:dword
            extrn '__imp__ObCloseHandle@8' as ObCloseHandle:dword
            extrn '__imp__ObIsDosDeviceLocallyMapped@8' as ObIsDosDeviceLocallyMapped:dword
            extrn '__imp__ObLogSecurityDescriptor@12' as ObLogSecurityDescriptor:dword
            extrn '__imp__ObReferenceSecurityDescriptor@8' as ObReferenceSecurityDescriptor:dword
            extrn '__imp__ObSetHandleAttributes@12' as ObSetHandleAttributes:dword
            extrn '__imp__ObSetSecurityObjectByPointer@12' as ObSetSecurityObjectByPointer:dword
            extrn '__imp__PoRequestShutdownEvent@4' as PoRequestShutdownEvent:dword
            extrn '__imp__PsChargeProcessNonPagedPoolQuota@8' as PsChargeProcessNonPagedPoolQuota:dword
            extrn '__imp__PsChargeProcessPagedPoolQuota@8' as PsChargeProcessPagedPoolQuota:dword
            extrn '__imp__PsChargeProcessPoolQuota@12' as PsChargeProcessPoolQuota:dword
            if (NTDDI_VERSION < NTDDI_VISTA)
                extrn '__imp__PsCreateSystemProcess@12' as PsCreateSystemProcess:dword
            end if
            extrn '__imp__PsDereferenceImpersonationToken@4' as PsDereferenceImpersonationToken:dword
            extrn '__imp__PsDereferencePrimaryToken@4' as PsDereferencePrimaryToken:dword
            extrn '__imp__PsGetContextThread@12' as PsGetContextThread:dword
            extrn '__imp__PsGetCurrentProcess@0' as PsGetCurrentProcess:dword
            extrn '__imp__PsGetCurrentProcessSessionId@0' as PsGetCurrentProcessSessionId:dword
            extrn '__imp__PsGetCurrentThread@0' as PsGetCurrentThread:dword
            extrn '__imp__PsGetCurrentThreadPreviousMode@0' as PsGetCurrentThreadPreviousMode:dword
            extrn '__imp__PsGetCurrentThreadStackBase@0' as PsGetCurrentThreadStackBase:dword
            extrn '__imp__PsGetCurrentThreadStackLimit@0' as PsGetCurrentThreadStackLimit:dword
            extrn '__imp__PsGetJobLock@4' as PsGetJobLock:dword
            extrn '__imp__PsGetJobSessionId@4' as PsGetJobSessionId:dword
            extrn '__imp__PsGetJobUIRestrictionsClass@4' as PsGetJobUIRestrictionsClass:dword
            extrn '__imp__PsGetProcessCreateTimeQuadPart@4' as PsGetProcessCreateTimeQuadPart:dword
            extrn '__imp__PsGetProcessDebugPort@4' as PsGetProcessDebugPort:dword
            extrn '__imp__PsGetProcessExitProcessCalled@4' as PsGetProcessExitProcessCalled:dword
            extrn '__imp__PsGetProcessExitStatus@4' as PsGetProcessExitStatus:dword
            extrn '__imp__PsGetProcessInheritedFromUniqueProcessId@4' as PsGetProcessInheritedFromUniqueProcessId:dword
            extrn '__imp__PsGetProcessJob@4' as PsGetProcessJob:dword
            extrn '__imp__PsGetProcessPeb@4' as PsGetProcessPeb:dword
            extrn '__imp__PsGetProcessPriorityClass@4' as PsGetProcessPriorityClass:dword
            extrn '__imp__PsGetProcessSectionBaseAddress@4' as PsGetProcessSectionBaseAddress:dword
            extrn '__imp__PsGetProcessSecurityPort@4' as PsGetProcessSecurityPort:dword
            extrn '__imp__PsGetProcessSessionId@4' as PsGetProcessSessionId:dword
            extrn '__imp__PsGetProcessWin32Process@4' as PsGetProcessWin32Process:dword
            extrn '__imp__PsGetProcessWin32WindowStation@4' as PsGetProcessWin32WindowStation:dword
            extrn '__imp__PsGetThreadFreezeCount@4' as PsGetThreadFreezeCount:dword
            extrn '__imp__PsGetThreadHardErrorsAreDisabled@4' as PsGetThreadHardErrorsAreDisabled:dword
            extrn '__imp__PsGetThreadId@4' as PsGetThreadId:dword
            extrn '__imp__PsGetThreadProcess@4' as PsGetThreadProcess:dword
            extrn '__imp__PsGetThreadProcessId@4' as PsGetThreadProcessId:dword
            extrn '__imp__PsGetThreadSessionId@4' as PsGetThreadSessionId:dword
            extrn '__imp__PsGetThreadTeb@4' as PsGetThreadTeb:dword
            extrn '__imp__PsGetThreadWin32Thread@4' as PsGetThreadWin32Thread:dword
            extrn '__imp__PsIsProcessBeingDebugged@4' as PsIsProcessBeingDebugged:dword
            extrn '__imp__PsIsSystemThread@4' as PsIsSystemThread:dword
            extrn '__imp__PsIsThreadImpersonating@4' as PsIsThreadImpersonating:dword
            extrn '__imp__PsRemoveCreateThreadNotifyRoutine@4' as PsRemoveCreateThreadNotifyRoutine:dword
            extrn '__imp__PsRemoveLoadImageNotifyRoutine@4' as PsRemoveLoadImageNotifyRoutine:dword
            extrn '__imp__PsReturnProcessNonPagedPoolQuota@8' as PsReturnProcessNonPagedPoolQuota:dword
            extrn '__imp__PsReturnProcessPagedPoolQuota@8' as PsReturnProcessPagedPoolQuota:dword
            extrn '__imp__PsRevertThreadToSelf@4' as PsRevertThreadToSelf:dword
            extrn '__imp__PsSetContextThread@12' as PsSetContextThread:dword
            if (NTDDI_VERSION = NTDDI_WINXP)
                extrn '__imp__WmiFlushTrace@4' as WmiFlushTrace:dword
                extrn '__imp__WmiQueryTrace@4' as WmiQueryTrace:dword
                extrn '__imp__WmiStartTrace@4' as WmiStartTrace:dword
                extrn '__imp__WmiStopTrace@4' as WmiStopTrace:dword
                extrn '__imp__WmiUpdateTrace@4' as WmiUpdateTrace:dword
            else if (NTDDI_VERSION < NTDDI_WIN8)
                extrn '__imp__PsSetJobUIRestrictionsClass@8' as PsSetJobUIRestrictionsClass:dword
            end if
            extrn '__imp__PsSetProcessPriorityClass@8' as PsSetProcessPriorityClass:dword
            extrn '__imp__PsSetProcessSecurityPort@8' as PsSetProcessSecurityPort:dword
            extrn '__imp__PsSetProcessWin32Process@12' as PsSetProcessWin32Process:dword
            extrn '__imp__PsSetProcessWindowStation@8' as PsSetProcessWindowStation:dword
            extrn '__imp__PsSetThreadHardErrorsAreDisabled@8' as PsSetThreadHardErrorsAreDisabled:dword
            extrn '__imp__PsSetThreadWin32Thread@12' as PsSetThreadWin32Thread:dword
            extrn '__imp__RtlClearBit@8' as RtlClearBit:dword
            extrn '__imp__RtlCreateSystemVolumeInformationFolder@4' as RtlCreateSystemVolumeInformationFolder:dword
            extrn '__imp__RtlDeleteElementGenericTableAvl@8' as RtlDeleteElementGenericTableAvl:dword
            extrn '__imp__RtlEnumerateGenericTableAvl@8' as RtlEnumerateGenericTableAvl:dword
            extrn '__imp__RtlEnumerateGenericTableLikeADirectory@28' as RtlEnumerateGenericTableLikeADirectory:dword
            extrn '__imp__RtlEnumerateGenericTableWithoutSplayingAvl@8' as RtlEnumerateGenericTableWithoutSplayingAvl:dword
            extrn '__imp__RtlGetElementGenericTableAvl@8' as RtlGetElementGenericTableAvl:dword
            extrn '__imp__RtlGetSetBootStatusData@24' as RtlGetSetBootStatusData:dword
            extrn '__imp__RtlGetVersion@4' as RtlGetVersion:dword
            extrn '__imp__RtlHashUnicodeString@16' as RtlHashUnicodeString:dword
            extrn '__imp__RtlInitializeGenericTableAvl@20' as RtlInitializeGenericTableAvl:dword
            extrn '__imp__RtlInsertElementGenericTableAvl@16' as RtlInsertElementGenericTableAvl:dword
            extrn '__imp__RtlInsertElementGenericTableFullAvl@24' as RtlInsertElementGenericTableFullAvl:dword
            extrn '__imp__RtlInt64ToUnicodeString@16' as RtlInt64ToUnicodeString:dword
            extrn '__imp__RtlIntegerToUnicode@16' as RtlIntegerToUnicode:dword
            extrn '__imp__RtlIpv4AddressToStringA@8' as RtlIpv4AddressToStringA:dword
            extrn '__imp__RtlIpv4AddressToStringExA@16' as RtlIpv4AddressToStringExA:dword
            extrn '__imp__RtlIpv4AddressToStringExW@16' as RtlIpv4AddressToStringExW:dword
            extrn '__imp__RtlIpv4AddressToStringW@8' as RtlIpv4AddressToStringW:dword
            extrn '__imp__RtlIpv4StringToAddressA@16' as RtlIpv4StringToAddressA:dword
            extrn '__imp__RtlIpv4StringToAddressExA@16' as RtlIpv4StringToAddressExA:dword
            extrn '__imp__RtlIpv4StringToAddressExW@16' as RtlIpv4StringToAddressExW:dword
            extrn '__imp__RtlIpv4StringToAddressW@16' as RtlIpv4StringToAddressW:dword
            extrn '__imp__RtlIpv6AddressToStringA@8' as RtlIpv6AddressToStringA:dword
            extrn '__imp__RtlIpv6AddressToStringExA@20' as RtlIpv6AddressToStringExA:dword
            extrn '__imp__RtlIpv6AddressToStringExW@20' as RtlIpv6AddressToStringExW:dword
            extrn '__imp__RtlIpv6AddressToStringW@8' as RtlIpv6AddressToStringW:dword
            extrn '__imp__RtlIpv6StringToAddressA@12' as RtlIpv6StringToAddressA:dword
            extrn '__imp__RtlIpv6StringToAddressExA@16' as RtlIpv6StringToAddressExA:dword
            extrn '__imp__RtlIpv6StringToAddressExW@16' as RtlIpv6StringToAddressExW:dword
            extrn '__imp__RtlIpv6StringToAddressW@12' as RtlIpv6StringToAddressW:dword
            extrn '__imp__RtlIsGenericTableEmptyAvl@4' as RtlIsGenericTableEmptyAvl:dword
            extrn '__imp__RtlLockBootStatusData@4' as RtlLockBootStatusData:dword
            extrn '__imp__RtlLookupElementGenericTableAvl@8' as RtlLookupElementGenericTableAvl:dword
            extrn '__imp__RtlLookupElementGenericTableFullAvl@16' as RtlLookupElementGenericTableFullAvl:dword
            extrn '__imp__RtlMapSecurityErrorToNtStatus@4' as RtlMapSecurityErrorToNtStatus:dword
            extrn '__imp__RtlNumberGenericTableElementsAvl@4' as RtlNumberGenericTableElementsAvl:dword
            extrn '__imp__RtlRandomEx@4' as RtlRandomEx:dword
            extrn '__imp__RtlSetBit@8' as RtlSetBit:dword
            extrn '__imp__RtlTestBit@8' as RtlTestBit:dword
            extrn '__imp__RtlTimeToElapsedTimeFields@8' as RtlTimeToElapsedTimeFields:dword
            extrn '__imp__RtlVerifyVersionInfo@16' as RtlVerifyVersionInfo:dword
            extrn '__imp__SeAuditingHardLinkEventsWithContext@12' as SeAuditingHardLinkEventsWithContext:dword
            extrn '__imp__SeReportSecurityEvent@16' as SeAuditingHardLinkEventsWithContext:dword
            extrn '__imp__SeTokenIsWriteRestricted@4' as SeTokenIsWriteRestricted:dword
            extrn '__imp__SeTokenObjectType@24' as SeTokenObjectType:dword
            extrn '__imp__vDbgPrintEx@16' as vDbgPrintEx:dword
            extrn '__imp__vDbgPrintExWithPrefix@20' as vDbgPrintExWithPrefix:dword
            extrn '__imp__VfIsVerificationEnabled@8' as VfIsVerificationEnabled:dword
            extrn '__imp__WmiGetClock@8' as WmiGetClock:dword
            extrn '__imp__WmiQueryTraceInformation@20' as WmiQueryTraceInformation:dword
            extrn '__imp__WmiTraceMessage@16' as WmiTraceMessage:dword
            extrn '__imp__WmiTraceMessageVa@24' as WmiTraceMessageVa:dword
            extrn '__imp__WRITE_REGISTER_BUFFER_UCHAR@12' as WRITE_REGISTER_BUFFER_UCHAR:dword
            extrn '__imp__WRITE_REGISTER_BUFFER_ULONG@12' as WRITE_REGISTER_BUFFER_ULONG:dword
            extrn '__imp__WRITE_REGISTER_BUFFER_USHORT@12' as WRITE_REGISTER_BUFFER_USHORT:dword
            extrn '__imp__WRITE_REGISTER_UCHAR@8' as WRITE_REGISTER_UCHAR:dword
            extrn '__imp__WRITE_REGISTER_ULONG@8' as WRITE_REGISTER_ULONG:dword
            extrn '__imp__WRITE_REGISTER_USHORT@8' as WRITE_REGISTER_USHORT:dword
            extrn '__imp__XIPDispatch@12' as XIPDispatch:dword
            extrn '__imp__ZwAddBootEntry@8' as ZwAddBootEntry:dword
            extrn '__imp__ZwAssignProcessToJobObject@8' as ZwAssignProcessToJobObject:dword
            extrn '__imp__ZwCreateJobObject@12' as ZwCreateJobObject:dword
            extrn '__imp__ZwDeleteBootEntry@8' as ZwDeleteBootEntry:dword
            extrn '__imp__ZwEnumerateBootEntries@8' as ZwEnumerateBootEntries:dword
            extrn '__imp__ZwIsProcessInJob@8' as ZwIsProcessInJob:dword
            extrn '__imp__ZwOpenJobObject@12' as ZwOpenJobObject:dword
            extrn '__imp__ZwOpenProcessTokenEx@16' as ZwOpenProcessTokenEx:dword
            extrn '__imp__ZwOpenThreadTokenEx@20' as ZwOpenThreadTokenEx:dword
            extrn '__imp__ZwQueryBootEntryOrder@8' as ZwQueryBootEntryOrder:dword
            extrn '__imp__ZwQueryBootOptions@8' as ZwQueryBootOptions:dword
            extrn '__imp__ZwQueryFullAttributesFile@8' as ZwQueryFullAttributesFile:dword
            extrn '__imp__ZwQueryInformationJobObject@20' as ZwQueryInformationJobObject:dword
            extrn '__imp__ZwQueryInformationThread@20' as ZwQueryInformationThread:dword
            extrn '__imp__ZwSaveKeyEx@12' as ZwSaveKeyEx:dword
            extrn '__imp__ZwSetBootEntryOrder@8' as ZwSetBootEntryOrder:dword
            extrn '__imp__ZwSetBootOptions@8' as ZwSetBootOptions:dword
            extrn '__imp__ZwSetInformationJobObject@16' as ZwSetInformationJobObject:dword
            extrn '__imp__ZwTerminateJobObject@8' as ZwTerminateJobObject:dword
            extrn '__imp__ZwTranslateFilePath@16' as ZwTranslateFilePath:dword
            extrn '__imp___vsnwprintf@16' as _vsnwprintf:dword

            api RtlIpv4AddressToString,\
                RtlIpv4AddressToStringEx,\
                RtlIpv4StringToAddress,\
                RtlIpv4StringToAddressEx,\
                RtlIpv6AddressToString,\
                RtlIpv6AddressToStringEx,\
                RtlIpv6StringToAddress,\
                RtlIpv6StringToAddressEx
        end if

        if (NTDDI_VERSION >= NTDDI_VISTA)
            extrn '__imp__AlpcGetHeaderSize@4' as AlpcGetHeaderSize:dword
            extrn '__imp__AlpcGetMessageAttribute@8' as AlpcGetMessageAttribute:dword
            extrn '__imp__AlpcInitializeMessageAttribute@16' as AlpcInitializeMessageAttribute:dword
            extrn '__imp__bsearch@20' as bsearch:dword
            extrn '__imp__CcGetFileObjectFromSectionPtrsRef@4' as CcGetFileObjectFromSectionPtrsRef:dword
            extrn '__imp__CcIsThereDirtyDataEx@8' as CcIsThereDirtyDataEx:dword
            extrn '__imp__CcSetFileSizesEx@8' as CcSetFileSizesEx:dword
            extrn '__imp__CcSetParallelFlushFile@8' as CcSetParallelFlushFile:dword
            extrn '__imp__CmCallbackGetKeyObjectID@16' as CmCallbackGetKeyObjectID:dword
            extrn '__imp__CmGetBoundTransaction@8' as CmGetBoundTransaction:dword
            extrn '__imp__CmGetCallbackVersion@8' as CmGetCallbackVersion:dword
            extrn '__imp__CmRegisterCallbackEx@24' as CmRegisterCallbackEx:dword
            extrn '__imp__CmSetCallbackObjectContext@16' as CmSetCallbackObjectContext:dword
            extrn '__imp__DbgCommandString@8' as DbgCommandString:dword
            extrn '__imp__DbgSetDebugPrintCallback@4' as DbgSetDebugPrintCallback:dword
            extrn '__imp__EmClientQueryRuleState@8' as EmClientQueryRuleState:dword
            extrn '__imp__EtwActivityIdControl@8' as EtwActivityIdControl:dword
            extrn '__imp__EtwEventEnabled@8' as EtwEventEnabled:dword
            extrn '__imp__EtwProviderEnabled@12' as EtwProviderEnabled:dword
            extrn '__imp__EtwRegister@16' as EtwRegister:dword
            extrn '__imp__EtwUnregister@4' as EtwUnregister:dword
            extrn '__imp__EtwWrite@20' as EtwWrite:dword
            extrn '__imp__EtwWriteString@20' as EtwWriteString:dword
            extrn '__imp__EtwWriteTransfer@24' as EtwWriteTransfer:dword
            extrn '__imp__ExAcquireSpinLockExclusive@4' as ExAcquireSpinLockExclusive:dword
            extrn '__imp__ExAcquireSpinLockExclusiveAtDpcLevel@4' as ExAcquireSpinLockExclusiveAtDpcLevel:dword
            extrn '__imp__ExAcquireSpinLockShared@4' as ExAcquireSpinLockShared:dword
            extrn '__imp__ExAcquireSpinLockSharedAtDpcLevel@4' as ExAcquireSpinLockSharedAtDpcLevel:dword
            extrn '__imp__ExAllocateCacheAwarePushLock@0' as ExAllocateCacheAwarePushLock:dword
            extrn '__imp__ExAllocateCacheAwareRundownProtection@8' as ExAllocateCacheAwareRundownProtection:dword
            extrn '__imp__ExDeleteLookasideListEx@4' as ExDeleteLookasideListEx:dword
            extrn '__imp__ExEnterCriticalRegionAndAcquireFastMutexUnsafe@4' as ExEnterCriticalRegionAndAcquireFastMutexUnsafe:dword
            extrn '__imp__ExEnterCriticalRegionAndAcquireResourceExclusive@4' as ExEnterCriticalRegionAndAcquireResourceExclusive:dword
            extrn '__imp__ExEnterCriticalRegionAndAcquireResourceShared@4' as ExEnterCriticalRegionAndAcquireResourceShared:dword
            extrn '__imp__ExEnterCriticalRegionAndAcquireSharedWaitForExclusive@4' as ExEnterCriticalRegionAndAcquireSharedWaitForExclusive:dword
            extrn '__imp__ExFlushLookasideListEx@4' as ExFlushLookasideListEx:dword
            extrn '__imp__ExFreeCacheAwarePushLock@4' as ExFreeCacheAwarePushLock:dword
            extrn '__imp__ExfReleasePushLockExclusive@4' as ExfReleasePushLockExclusive:dword
            extrn '__imp__ExfReleasePushLockShared@4' as ExfReleasePushLockShared:dword
            extrn '__imp__ExfTryToWakePushLock@4' as ExfTryToWakePushLock:dword
            extrn '__imp__ExfUnblockPushLock@8' as ExfUnblockPushLock:dword
            extrn '__imp__ExInitializeLookasideListEx@32' as ExInitializeLookasideListEx:dword
            extrn '__imp__ExInitializePushLock@4' as ExInitializePushLock:dword
            extrn '__imp__ExInitializeRundownProtectionCacheAware@12' as ExInitializeRundownProtectionCacheAware:dword
            extrn '__imp__ExReInitializeRundownProtectionCacheAware@4' as ExReInitializeRundownProtectionCacheAware:dword
            extrn '__imp__ExReleaseCacheAwarePushLockExclusive@4' as ExReleaseCacheAwarePushLockExclusive:dword
            extrn '__imp__ExReleaseFastMutexUnsafeAndLeaveCriticalRegion@4' as ExReleaseFastMutexUnsafeAndLeaveCriticalRegion:dword
            extrn '__imp__ExReleaseResourceAndLeaveCriticalRegion@4' as ExReleaseResourceAndLeaveCriticalRegion:dword
            extrn '__imp__ExReleaseRundownProtectionCacheAware@4' as ExReleaseRundownProtectionCacheAware:dword
            extrn '__imp__ExReleaseRundownProtectionCacheAwareEx@8' as ExReleaseRundownProtectionCacheAwareEx:dword
            extrn '__imp__ExReleaseSpinLockExclusive@8' as ExReleaseSpinLockExclusive:dword
            extrn '__imp__ExReleaseSpinLockExclusiveFromDpcLevel@4' as ExReleaseSpinLockExclusiveFromDpcLevel:dword
            extrn '__imp__ExReleaseSpinLockShared@8' as ExReleaseSpinLockShared:dword
            extrn '__imp__ExReleaseSpinLockSharedFromDpcLevel@4' as ExReleaseSpinLockSharedFromDpcLevel:dword
            extrn '__imp__ExRundownCompletedCacheAware@4' as ExRundownCompletedCacheAware:dword
            extrn '__imp__ExSetLicenseTamperState@4' as ExSetLicenseTamperState:dword
            extrn '__imp__ExTryConvertSharedSpinLockExclusive@4' as ExTryConvertSharedSpinLockExclusive:dword
            extrn '__imp__FirstEntrySList@4' as FirstEntrySList:dword
            extrn '__imp__FsRtlAcknowledgeEcp@4' as FsRtlAcknowledgeEcp:dword
            extrn '__imp__FsRtlAddBaseMcbEntry@16' as FsRtlAddBaseMcbEntry:dword
            extrn '__imp__FsRtlAddBaseMcbEntryEx@16' as FsRtlAddBaseMcbEntryEx:dword
            extrn '__imp__FsRtlAllocateExtraCreateParameter@24' as FsRtlAllocateExtraCreateParameter:dword
            extrn '__imp__FsRtlAllocateExtraCreateParameterFromLookasideList@24' as FsRtlAllocateExtraCreateParameterFromLookasideList:dword
            extrn '__imp__FsRtlAllocateExtraCreateParameterList@8' as FsRtlAllocateExtraCreateParameterList:dword
            extrn '__imp__FsRtlAreVolumeStartupApplicationsComplete@0' as FsRtlAreVolumeStartupApplicationsComplete:dword
            extrn '__imp__FsRtlCancellableWaitForMultipleObjects@24' as FsRtlCancellableWaitForMultipleObjects:dword
            extrn '__imp__FsRtlCancellableWaitForSingleObject@12' as FsRtlCancellableWaitForSingleObject:dword
            extrn '__imp__FsRtlChangeBackingFileObject@16' as FsRtlChangeBackingFileObject:dword
            extrn '__imp__FsRtlCheckOplockEx@24' as FsRtlCheckOplockEx:dword
            extrn '__imp__FsRtlCurrentOplock@4' as FsRtlCurrentOplock:dword
            extrn '__imp__FsRtlDeleteExtraCreateParameterLookasideList@8' as FsRtlDeleteExtraCreateParameterLookasideList:dword
            extrn '__imp__FsRtlFindExtraCreateParameter@16' as FsRtlFindExtraCreateParameter:dword
            extrn '__imp__FsRtlFreeExtraCreateParameter@4' as FsRtlFreeExtraCreateParameter:dword
            extrn '__imp__FsRtlFreeExtraCreateParameterList@4' as FsRtlFreeExtraCreateParameterList:dword
            extrn '__imp__FsRtlGetEcpListFromIrp@8' as FsRtlGetEcpListFromIrp:dword
            extrn '__imp__FsRtlGetNextBaseMcbEntry@20' as FsRtlGetNextBaseMcbEntry:dword
            extrn '__imp__FsRtlGetNextExtraCreateParameter@20' as FsRtlGetNextExtraCreateParameter:dword
            extrn '__imp__FsRtlIncrementCcFastMdlReadWait@0' as FsRtlIncrementCcFastMdlReadWait:dword
            extrn '__imp__FsRtlInitExtraCreateParameterLookasideList@16' as FsRtlInitExtraCreateParameterLookasideList:dword
            extrn '__imp__FsRtlInitializeExtraCreateParameter@24' as FsRtlInitializeExtraCreateParameter:dword
            extrn '__imp__FsRtlInitializeExtraCreateParameterList@4' as FsRtlInitializeExtraCreateParameterList:dword
            extrn '__imp__FsRtlInsertExtraCreateParameter@8' as FsRtlInsertExtraCreateParameter:dword
            extrn '__imp__FsRtlInsertPerFileContext@8' as FsRtlInsertPerFileContext:dword
            extrn '__imp__FsRtlIsEcpAcknowledged@4' as FsRtlIsEcpAcknowledged:dword
            extrn '__imp__FsRtlIsEcpFromUserMode@4' as FsRtlIsEcpFromUserMode:dword
            extrn '__imp__FsRtlLogCcFlushError@20' as FsRtlLogCcFlushError:dword
            extrn '__imp__FsRtlLookupBaseMcbEntry@28' as FsRtlLookupBaseMcbEntry:dword
            extrn '__imp__FsRtlLookupLastBaseMcbEntryAndIndex@16' as FsRtlLookupLastBaseMcbEntryAndIndex:dword
            extrn '__imp__FsRtlLookupPerFileContext@12' as FsRtlLookupPerFileContext:dword
            extrn '__imp__FsRtlMupGetProviderIdFromName@8' as FsRtlMupGetProviderIdFromName:dword
            extrn '__imp__FsRtlMupGetProviderInfoFromFileObject@16' as FsRtlMupGetProviderInfoFromFileObject:dword
            extrn '__imp__FsRtlNotifyCleanupAll@8' as FsRtlNotifyCleanupAll:dword
            extrn '__imp__FsRtlNotifyVolumeEventEx@12' as FsRtlNotifyVolumeEventEx:dword
            extrn '__imp__FsRtlOplockBreakToNone@24' as FsRtlOplockBreakToNone:dword
            extrn '__imp__FsRtlPrepareToReuseEcp@4' as FsRtlPrepareToReuseEcp:dword
            extrn '__imp__FsRtlRegisterUncProviderEx@16' as FsRtlRegisterUncProviderEx:dword
            extrn '__imp__FsRtlRemoveBaseMcbEntry@12' as FsRtlRemoveBaseMcbEntry:dword
            extrn '__imp__FsRtlRemoveDotsFromPath@12' as FsRtlRemoveDotsFromPath:dword
            extrn '__imp__FsRtlRemoveExtraCreateParameter@16' as FsRtlRemoveExtraCreateParameter:dword
            extrn '__imp__FsRtlRemovePerFileContext@12' as FsRtlRemovePerFileContext:dword
            extrn '__imp__FsRtlSetEcpListIntoIrp@8' as FsRtlSetEcpListIntoIrp:dword
            extrn '__imp__FsRtlSplitBaseMcb@12' as FsRtlSplitBaseMcb:dword
            extrn '__imp__FsRtlTeardownPerFileContexts@4' as FsRtlTeardownPerFileContexts:dword
            extrn '__imp__FsRtlTruncateBaseMcb@8' as FsRtlTruncateBaseMcb:dword
            extrn '__imp__FsRtlUninitializeBaseMcb@4' as FsRtlUninitializeBaseMcb:dword
            extrn '__imp__FsRtlValidateReparsePointBuffer@8' as FsRtlValidateReparsePointBuffer:dword
            extrn '__imp__InterlockedPushListSList@16' as InterlockedPushListSList:dword
            extrn '__imp__IoAllocateMiniCompletionPacket@0' as IoAllocateMiniCompletionPacket:dword
            extrn '__imp__IoAllocateSfioStreamIdentifier@16' as IoAllocateSfioStreamIdentifier:dword
            extrn '__imp__IoCheckShareAccessEx@24' as IoCheckShareAccessEx:dword
            extrn '__imp__IoClearIrpExtraCreateParameter@4' as IoClearIrpExtraCreateParameter:dword
            extrn '__imp__IoConnectInterruptEx@4' as IoConnectInterruptEx:dword
            extrn '__imp__IoCreateFileEx@60' as IoCreateFileEx:dword
            extrn '__imp__IoCsqInitializeEx@28' as IoCsqInitializeEx:dword
            extrn '__imp__IoCsqInsertIrpEx@16' as IoCsqInsertIrpEx:dword
            extrn '__imp__IoDisconnectInterruptEx@4' as IoDisconnectInterruptEx:dword
            extrn '__imp__IoFreeSfioStreamIdentifier@8' as IoFreeSfioStreamIdentifier:dword
            extrn '__imp__IoGetBootDiskInformationLite@4' as IoGetBootDiskInformationLite:dword
            extrn '__imp__IoGetDevicePropertyData@32' as IoGetDevicePropertyData:dword
            extrn '__imp__IoGetIoPriorityHint@4' as IoGetIoPriorityHint:dword
            extrn '__imp__IoGetIrpExtraCreateParameter@8' as IoGetIrpExtraCreateParameter:dword
            extrn '__imp__IoGetPagingIoPriority@4' as IoGetPagingIoPriority:dword
            extrn '__imp__IoGetSfioStreamIdentifier@8' as IoGetSfioStreamIdentifier:dword
            extrn '__imp__IoGetTransactionParameterBlock@4' as IoGetTransactionParameterBlock:dword
            extrn '__imp__IoInitializeWorkItem@8' as IoInitializeWorkItem:dword
            extrn '__imp__IoIsFileObjectIgnoringSharing@4' as IoIsFileObjectIgnoringSharing:dword
            extrn '__imp__IoQueueWorkItemEx@16' as IoQueueWorkItemEx:dword
            extrn '__imp__IoReplacePartitionUnit@12' as IoReplacePartitionUnit:dword
            extrn '__imp__IoSetDevicePropertyData@28' as IoSetDevicePropertyData:dword
            extrn '__imp__IoSetIoPriorityHint@8' as IoSetIoPriorityHint:dword
            extrn '__imp__IoSetIrpExtraCreateParameter@8' as IoSetIrpExtraCreateParameter:dword
            extrn '__imp__IoSetShareAccessEx@20' as IoSetShareAccessEx:dword
            extrn '__imp__IoSizeofWorkItem@0' as IoSizeofWorkItem:dword
            extrn '__imp__IoTranslateBusAddress@20' as IoTranslateBusAddress:dword
            extrn '__imp__IoUninitializeWorkItem@4' as IoUninitializeWorkItem:dword
            extrn '__imp__IoWithinStackLimits@8' as IoWithinStackLimits:dword
            extrn '__imp__KdRefreshDebuggerNotPresent@0' as KdRefreshDebuggerNotPresent:dword
            extrn '__imp__KdSystemDebugControl@28' as KdSystemDebugControl:dword
            extrn '__imp__KeAcquireGuardedMutex@4' as KeAcquireGuardedMutex:dword
            extrn '__imp__KeAcquireGuardedMutexUnsafe@4' as KeAcquireGuardedMutexUnsafe:dword
            extrn '__imp__KeAcquireInStackQueuedSpinLockForDpc@8' as KeAcquireInStackQueuedSpinLockForDpc:dword
            extrn '__imp__KeAcquireSpinLockForDpc@4' as KeAcquireSpinLockForDpc:dword
            extrn '__imp__KeAlertThread@8' as KeAlertThread:dword
            extrn '__imp__KeAreAllApcsDisabled@0' as KeAreAllApcsDisabled:dword
            extrn '__imp__KeDeregisterNmiCallback@4' as KeDeregisterNmiCallback:dword
            extrn '__imp__KeDeregisterProcessorChangeCallback@4' as KeDeregisterProcessorChangeCallback:dword
            extrn '__imp__KeEnterGuardedRegion@0' as KeEnterGuardedRegion:dword
            extrn '__imp__KeExpandKernelStackAndCallout@12' as KeExpandKernelStackAndCallout:dword
            extrn '__imp__KeExpandKernelStackAndCalloutEx@20' as KeExpandKernelStackAndCalloutEx:dword
            extrn '__imp__KeFindFirstSetLeftAffinityEx@4' as KeFindFirstSetLeftAffinityEx:dword
            extrn '__imp__KeGenericCallDpc@8' as KeGenericCallDpc:dword
            extrn '__imp__KeInitializeCrashDumpHeader@20' as KeInitializeCrashDumpHeader:dword
            extrn '__imp__KeInitializeGuardedMutex@4' as KeInitializeGuardedMutex:dword
            extrn '__imp__KeInitializeThreadedDpc@12' as KeInitializeThreadedDpc:dword
            extrn '__imp__KeInvalidateAllCaches@0' as KeInvalidateAllCaches:dword
            extrn '__imp__KeInvalidateRangeAllCaches@4' as KeInvalidateRangeAllCaches:dword
            extrn '__imp__KeIpiGenericCall@8' as KeIpiGenericCall:dword
            extrn '__imp__KeIsWaitListEmpty@4' as KeIsWaitListEmpty:dword
            extrn '__imp__KeLeaveGuardedRegion@0' as KeLeaveGuardedRegion:dword
            extrn '__imp__KeQueryActiveProcessorCount@4' as KeQueryActiveProcessorCount:dword
            extrn '__imp__KeQueryDpcWatchdogInformation@4' as KeQueryDpcWatchdogInformation:dword
            extrn '__imp__KeQueryMaximumProcessorCount@0' as KeQueryMaximumProcessorCount:dword
            extrn '__imp__KeRegisterNmiCallback@8' as KeRegisterNmiCallback:dword
            extrn '__imp__KeRegisterProcessorChangeCallback@12' as KeRegisterProcessorChangeCallback:dword
            extrn '__imp__KeReleaseGuardedMutex@4' as KeReleaseGuardedMutex:dword
            extrn '__imp__KeReleaseGuardedMutexUnsafe@4' as KeReleaseGuardedMutexUnsafe:dword
            extrn '__imp__KeReleaseInStackQueuedSpinLockForDpc@4' as KeReleaseInStackQueuedSpinLockForDpc:dword
            extrn '__imp__KeReleaseInStackQueuedSpinLockFromDpcLevel@4' as KeReleaseInStackQueuedSpinLockFromDpcLevel:dword
            extrn '__imp__KeReleaseSpinLockForDpc@8' as KeReleaseSpinLockForDpc:dword
            extrn '__imp__KeRemoveQueueEx@12' as KeRemoveQueueEx:dword
            extrn '__imp__KeRevertToUserGroupAffinityThread@4' as KeRevertToUserGroupAffinityThread:dword
            extrn '__imp__KeSetSystemAffinityThreadEx@4' as KeSetSystemAffinityThreadEx:dword
            extrn '__imp__KeTestAlertThread@4' as KeTestAlertThread:dword
            extrn '__imp__KeTestSpinLock@4' as KeTestSpinLock:dword
            extrn '__imp__KeTryToAcquireGuardedMutex@4' as KeTryToAcquireGuardedMutex:dword
            extrn '__imp__KeTryToAcquireSpinLockAtDpcLevel@4' as KeTryToAcquireSpinLockAtDpcLevel:dword
            extrn '__imp__KiCheckForKernelApcDelivery@0' as KiCheckForKernelApcDelivery:dword
            extrn '__imp__LpcRequestWaitReplyPortEx@12' as LpcRequestWaitReplyPortEx:dword
            extrn '__imp__MmAllocateContiguousMemorySpecifyCacheNode@24' as MmAllocateContiguousMemorySpecifyCacheNode:dword
            extrn '__imp__MmAllocatePagesForMdlEx@24' as MmAllocatePagesForMdlEx:dword
            extrn '__imp__MmCopyVirtualMemory@28' as MmCopyVirtualMemory:dword
            extrn '__imp__MmCreateMirror@0' as MmCreateMirror:dword
            extrn '__imp__MmDoesFileHaveUserWritableReferences@4' as MmDoesFileHaveUserWritableReferences:dword
            extrn '__imp__MmIsDriverVerifyingByAddress@4' as MmIsDriverVerifyingByAddress:dword
            extrn '__imp__MmIsIoSpaceActive@8' as MmIsIoSpaceActive:dword
            extrn '__imp__MmRotatePhysicalView@24' as MmRotatePhysicalView:dword
            extrn '__imp__NtCommitComplete@8' as NtCommitComplete:dword
            extrn '__imp__NtCommitEnlistment@8' as NtCommitEnlistment:dword
            extrn '__imp__NtCommitTransaction@8' as NtCommitTransaction:dword
            extrn '__imp__NtCreateEnlistment@32' as NtCreateEnlistment:dword
            extrn '__imp__NtCreateResourceManager@20' as NtCreateResourceManager:dword
            extrn '__imp__NtCreateTransaction@40' as NtCreateTransaction:dword
            extrn '__imp__NtEnumerateTransactionObject@20' as NtEnumerateTransactionObject:dword
            extrn '__imp__NtFreezeTransactions@8' as NtFreezeTransactions:dword
            extrn '__imp__NtGetNotificationResourceManager@28' as NtGetNotificationResourceManager:dword
            extrn '__imp__NtOpenEnlistment@20' as NtOpenEnlistment:dword
            extrn '__imp__NtOpenResourceManager@20' as NtOpenResourceManager:dword
            extrn '__imp__NtOpenTransaction@20' as NtOpenTransaction:dword
            extrn '__imp__NtPrepareComplete@8' as NtPrepareComplete:dword
            extrn '__imp__NtPrepareEnlistment@8' as NtPrepareEnlistment:dword
            extrn '__imp__NtPrePrepareEnlistment@8' as NtPrePrepareEnlistment:dword
            extrn '__imp__NtQueryInformationEnlistment@20' as NtQueryInformationEnlistment:dword
            extrn '__imp__NtQueryInformationResourceManager@20' as NtQueryInformationResourceManager:dword
            extrn '__imp__NtQueryInformationTransaction@20' as NtQueryInformationTransaction:dword
            extrn '__imp__NtQueryInformationTransactionManager@0' as NtQueryInformationTransactionManager:dword
            extrn '__imp__NtRollbackEnlistment@8' as NtRollbackEnlistment:dword
            extrn '__imp__NtRollbackTransaction@8' as NtRollbackTransaction:dword
            extrn '__imp__NtSetInformationEnlistment@16' as NtSetInformationEnlistment:dword
            extrn '__imp__NtSetInformationResourceManager@8' as NtSetInformationResourceManager:dword
            extrn '__imp__NtSetInformationTransaction@16' as NtSetInformationTransaction:dword
            extrn '__imp__NtThawTransactions@0' as NtThawTransactions:dword
            extrn '__imp__NtTraceControl@24' as NtTraceControl:dword
            extrn '__imp__ObDereferenceObjectDeferDelete@4' as ObDereferenceObjectDeferDelete:dword
            extrn '__imp__ObDereferenceSecurityDescriptor@8' as ObDereferenceSecurityDescriptor:dword
            extrn '__imp__ObGetFilterVersion@0' as ObGetFilterVersion:dword
            extrn '__imp__ObIsKernelHandle@4' as ObIsKernelHandle:dword
            extrn '__imp__ObRegisterCallbacks@8' as ObRegisterCallbacks:dword
            extrn '__imp__ObUnRegisterCallbacks@4' as ObUnRegisterCallbacks:dword
            extrn '__imp__PoGetSystemWake@4' as PoGetSystemWake:dword
            extrn '__imp__PoRegisterPowerSettingCallback@20' as PoRegisterPowerSettingCallback:dword
            extrn '__imp__PoSetDeviceBusyEx@4' as PoSetDeviceBusyEx:dword
            extrn '__imp__PoSetSystemWake@4' as PoSetSystemWake:dword
            extrn '__imp__PoUnregisterPowerSettingCallback@4' as PoUnregisterPowerSettingCallback:dword
            extrn '__imp__PsAcquireProcessExitSynchronization@4' as PsAcquireProcessExitSynchronization:dword
            extrn '__imp__PsGetCurrentProcessWin32Process@0' as PsGetCurrentProcessWin32Process:dword
            extrn '__imp__PsGetCurrentThreadProcess@0' as PsGetCurrentThreadProcess:dword
            extrn '__imp__PsGetCurrentThreadProcessId@0' as PsGetCurrentThreadProcessId:dword
            extrn '__imp__PsGetCurrentThreadTeb@0' as PsGetCurrentThreadTeb:dword
            extrn '__imp__PsGetCurrentThreadWin32Thread@0' as PsGetCurrentThreadWin32Thread:dword
            extrn '__imp__PsIsCurrentThreadPrefetching@0' as PsIsCurrentThreadPrefetching:dword
            extrn '__imp__PsIsSystemProcess@4' as PsIsSystemProcess:dword
            extrn '__imp__PsReferenceProcessFilePointer@8' as PsReferenceProcessFilePointer:dword
            extrn '__imp__PsResumeProcess@4' as PsResumeProcess:dword
            extrn '__imp__PsSetCreateProcessNotifyRoutineEx@8' as PsSetCreateProcessNotifyRoutineEx:dword
            extrn '__imp__PsSetCurrentThreadPrefetching@4' as PsSetCurrentThreadPrefetching:dword
            extrn '__imp__PsSuspendProcess@4' as PsSuspendProcess:dword
            extrn '__imp__PsWrapApcWow64Thread@8' as PsWrapApcWow64Thread:dword
            extrn '__imp__RtlCmDecodeMemIoResource@8' as RtlCmDecodeMemIoResource:dword
            extrn '__imp__RtlCmEncodeMemIoResource@16' as RtlCmEncodeMemIoResource:dword
            extrn '__imp__RtlCompareAltitudes@8' as RtlCompareAltitudes:dword
            extrn '__imp__RtlComputeCrc32@12' as RtlComputeCrc32:dword
            extrn '__imp__RtlCopyLuidAndAttributesArray@12' as RtlCopyLuidAndAttributesArray:dword
            extrn '__imp__RtlCopySidAndAttributesArray@28' as RtlCopySidAndAttributesArray:dword
            extrn '__imp__RtlDuplicateUnicodeString@12' as RtlDuplicateUnicodeString:dword
            extrn '__imp__RtlFormatMessage@40' as RtlFormatMessage:dword
            extrn '__imp__RtlGetThreadLangIdByIndex@0' as RtlGetThreadLangIdByIndex:dword
            extrn '__imp__RtlInitAnsiStringEx@8' as RtlInitAnsiStringEx:dword
            extrn '__imp__RtlInitUnicodeStringEx@8' as RtlInitUnicodeStringEx:dword
            extrn '__imp__RtlIoDecodeMemIoResource@16' as RtlIoDecodeMemIoResource:dword
            extrn '__imp__RtlIoEncodeMemIoResource@24' as RtlIoEncodeMemIoResource:dword
            extrn '__imp__RtlIsNormalizedString@16' as RtlIsNormalizedString:dword
            extrn '__imp__RtlIsNtDdiVersionAvailable@4' as RtlIsNtDdiVersionAvailable:dword
            extrn '__imp__RtlIsServicePackVersionInstalled@4' as RtlIsServicePackVersionInstalled:dword
            extrn '__imp__RtlLocalTimeToSystemTime@8' as RtlLocalTimeToSystemTime:dword
            extrn '__imp__RtlLookupFirstMatchingElementGenericTableAvl@12' as RtlLookupFirstMatchingElementGenericTableAvl:dword
            extrn '__imp__RtlNumberOfSetBitsUlongPtr@4' as RtlNumberOfSetBitsUlongPtr:dword
            extrn '__imp__RtlQueryElevationFlags@4' as RtlQueryElevationFlags:dword
            extrn '__imp__RtlRunOnceBeginInitialize@12' as RtlRunOnceBeginInitialize:dword
            extrn '__imp__RtlRunOnceComplete@12' as RtlRunOnceComplete:dword
            extrn '__imp__RtlRunOnceExecuteOnce@16' as RtlRunOnceExecuteOnce:dword
            extrn '__imp__RtlRunOnceInitialize@4' as RtlRunOnceInitialize:dword
            extrn '__imp__RtlSystemTimeToLocalTime@8' as RtlSystemTimeToLocalTime:dword
            extrn '__imp__RtlUnlockBootStatusData@4' as RtlUnlockBootStatusData:dword
            extrn '__imp__RtlValidateUnicodeString@8' as RtlValidateUnicodeString:dword
            extrn '__imp__SeAuditHardLinkCreationWithTransaction@16' as SeAuditHardLinkCreationWithTransaction:dword
            extrn '__imp__SeAuditTransactionStateChange@12' as SeAuditTransactionStateChange:dword
            extrn '__imp__SeCaptureSubjectContextEx@12' as SeCaptureSubjectContextEx:dword
            extrn '__imp__SeComputeAutoInheritByObjectType@12' as SeComputeAutoInheritByObjectType:dword
            extrn '__imp__SeCreateAccessStateEx@24' as SeCreateAccessStateEx:dword
            extrn '__imp__SeDeleteObjectAuditAlarmWithTransaction@12' as SeDeleteObjectAuditAlarmWithTransaction:dword
            extrn '__imp__SeExamineSacl@24' as SeExamineSacl:dword
            extrn '__imp__SeFilterToken@24' as SeFilterToken:dword
            extrn '__imp__SeLocateProcessImageName@8' as SeLocateProcessImageName:dword
            extrn '__imp__SeOpenObjectForDeleteAuditAlarmWithTransaction@40' as SeOpenObjectForDeleteAuditAlarmWithTransaction:dword
            extrn '__imp__SeReportSecurityEventWithSubCategory@20' as SeReportSecurityEventWithSubCategory:dword
            extrn '__imp__SeSetAuditParameter@16' as SeSetAuditParameter:dword
            extrn '__imp__TmCommitComplete@8' as TmCommitComplete:dword
            extrn '__imp__TmCommitEnlistment@8' as TmCommitEnlistment:dword
            extrn '__imp__TmCommitTransaction@8' as TmCommitTransaction:dword
            extrn '__imp__TmCreateEnlistment@36' as TmCreateEnlistment:dword
            extrn '__imp__TmDereferenceEnlistmentKey@8' as TmDereferenceEnlistmentKey:dword
            extrn '__imp__TmEnableCallbacks@12' as TmEnableCallbacks:dword
            extrn '__imp__TmGetTransactionId@8' as TmGetTransactionId:dword
            extrn '__imp__TmIsTransactionActive@4' as TmIsTransactionActive:dword
            extrn '__imp__TmPrepareComplete@8' as TmPrepareComplete:dword
            extrn '__imp__TmPrepareEnlistment@8' as TmPrepareEnlistment:dword
            extrn '__imp__TmPrePrepareComplete@8' as TmPrePrepareComplete:dword
            extrn '__imp__TmPrePrepareEnlistment@8' as TmPrePrepareEnlistment:dword
            extrn '__imp__TmReadOnlyEnlistment@8' as TmReadOnlyEnlistment:dword
            extrn '__imp__TmRecoverEnlistment@8' as TmRecoverEnlistment:dword
            extrn '__imp__TmRecoverResourceManager@4' as TmRecoverResourceManager:dword
            extrn '__imp__TmRecoverTransactionManager@8' as TmRecoverTransactionManager:dword
            extrn '__imp__TmReferenceEnlistmentKey@8' as TmReferenceEnlistmentKey:dword
            extrn '__imp__TmRequestOutcomeEnlistment@8' as TmRequestOutcomeEnlistment:dword
            extrn '__imp__TmRollbackComplete@8' as TmRollbackComplete:dword
            extrn '__imp__TmRollbackEnlistment@8' as TmRollbackEnlistment:dword
            extrn '__imp__TmRollbackTransaction@8' as TmRollbackTransaction:dword
            extrn '__imp__WheaAddErrorSource@8' as WheaAddErrorSource:dword
            extrn '__imp__ZwAddDriverEntry@8' as ZwAddDriverEntry:dword
            extrn '__imp__ZwAllocateLocallyUniqueId@4' as ZwAllocateLocallyUniqueId:dword
            extrn '__imp__ZwAlpcAcceptConnectPort@36' as ZwAlpcAcceptConnectPort:dword
            extrn '__imp__ZwAlpcCancelMessage@12' as ZwAlpcCancelMessage:dword
            extrn '__imp__ZwAlpcConnectPort@44' as ZwAlpcConnectPort:dword
            extrn '__imp__ZwAlpcCreatePort@12' as ZwAlpcCreatePort:dword
            extrn '__imp__ZwAlpcCreatePortSection@24' as ZwAlpcCreatePortSection:dword
            extrn '__imp__ZwAlpcCreateResourceReserve@16' as ZwAlpcCreateResourceReserve:dword
            extrn '__imp__ZwAlpcCreateSectionView@12' as ZwAlpcCreateSectionView:dword
            extrn '__imp__ZwAlpcCreateSecurityContext@12' as ZwAlpcCreateSecurityContext:dword
            extrn '__imp__ZwAlpcDeletePortSection@12' as ZwAlpcDeletePortSection:dword
            extrn '__imp__ZwAlpcDeleteResourceReserve@12' as ZwAlpcDeleteResourceReserve:dword
            extrn '__imp__ZwAlpcDeleteSectionView@12' as ZwAlpcDeleteSectionView:dword
            extrn '__imp__ZwAlpcDeleteSecurityContext@12' as ZwAlpcDeleteSecurityContext:dword
            extrn '__imp__ZwAlpcDisconnectPort@8' as ZwAlpcDisconnectPort:dword
            extrn '__imp__ZwAlpcQueryInformation@20' as ZwAlpcQueryInformation:dword
            extrn '__imp__ZwAlpcSendWaitReceivePort@32' as ZwAlpcSendWaitReceivePort:dword
            extrn '__imp__ZwAlpcSetInformation@16' as ZwAlpcSetInformation:dword
            extrn '__imp__ZwCommitEnlistment@8' as ZwCommitEnlistment:dword
            extrn '__imp__ZwCommitTransaction@8' as ZwCommitTransaction:dword
            extrn '__imp__ZwCreateEnlistment@32' as ZwCreateEnlistment:dword
            extrn '__imp__ZwCreateIoCompletion@16' as ZwCreateIoCompletion:dword
            extrn '__imp__ZwCreateKeyTransacted@32' as ZwCreateKeyTransacted:dword
            extrn '__imp__ZwCreateResourceManager@28' as ZwCreateResourceManager:dword
            extrn '__imp__ZwCreateTransaction@40' as ZwCreateTransaction:dword
            extrn '__imp__ZwCreateTransactionManager@24' as ZwCreateTransactionManager:dword
            extrn '__imp__ZwEnumerateDriverEntries@8' as ZwEnumerateDriverEntries:dword
            extrn '__imp__ZwEnumerateTransactionObject@20' as ZwEnumerateTransactionObject:dword
            extrn '__imp__ZwFlushBuffersFile@8' as ZwFlushBuffersFile:dword
            extrn '__imp__ZwGetNotificationResourceManager@28' as ZwGetNotificationResourceManager:dword
            extrn '__imp__ZwImpersonateAnonymousToken@4' as ZwImpersonateAnonymousToken:dword
            extrn '__imp__ZwLoadKeyEx@16' as ZwLoadKeyEx:dword
            extrn '__imp__ZwLockProductActivationKeys@8' as ZwLockProductActivationKeys:dword
            extrn '__imp__ZwModifyBootEntry@4' as ZwModifyBootEntry:dword
            extrn '__imp__ZwModifyDriverEntry@4' as ZwModifyDriverEntry:dword
            extrn '__imp__ZwOpenEnlistment@20' as ZwOpenEnlistment:dword
            extrn '__imp__ZwOpenKeyTransacted@16' as ZwOpenKeyTransacted:dword
            extrn '__imp__ZwOpenResourceManager@20' as ZwOpenResourceManager:dword
            extrn '__imp__ZwOpenTransaction@20' as ZwOpenTransaction:dword
            extrn '__imp__ZwOpenTransactionManager@24' as ZwOpenTransactionManager:dword
            extrn '__imp__ZwPrepareComplete@8' as ZwPrepareComplete:dword
            extrn '__imp__ZwPrepareEnlistment@8' as ZwPrepareEnlistment:dword
            extrn '__imp__ZwPrePrepareEnlistment@8' as ZwPrePrepareEnlistment:dword
            extrn '__imp__ZwQueryDriverEntryOrder@8' as ZwQueryDriverEntryOrder:dword
            extrn '__imp__ZwQueryInformationEnlistment@20' as ZwQueryInformationEnlistment:dword
            extrn '__imp__ZwQueryInformationResourceManager@20' as ZwQueryInformationResourceManager:dword
            extrn '__imp__ZwQueryInformationTransaction@20' as ZwQueryInformationTransaction:dword
            extrn '__imp__ZwQueryInformationTransactionManager@20' as ZwQueryInformationTransactionManager:dword
            extrn '__imp__ZwQueryVirtualMemory@24' as ZwQueryVirtualMemory:dword
            extrn '__imp__ZwRecoverEnlistment@8' as ZwRecoverEnlistment:dword
            extrn '__imp__ZwRecoverResourceManager@4' as ZwRecoverResourceManager:dword
            extrn '__imp__ZwRecoverTransactionManager@4' as ZwRecoverTransactionManager:dword
            extrn '__imp__ZwRemoveIoCompletion@20' as ZwRemoveIoCompletion:dword
            extrn '__imp__ZwRemoveIoCompletionEx@24' as ZwRemoveIoCompletionEx:dword
            extrn '__imp__ZwRequestPort@8' as ZwRequestPort:dword
            extrn '__imp__ZwRollbackEnlistment@8' as ZwRollbackEnlistment:dword
            extrn '__imp__ZwRollbackTransaction@8' as ZwRollbackTransaction:dword
            extrn '__imp__ZwSecureConnectPort@36' as ZwSecureConnectPort:dword
            extrn '__imp__ZwSetDriverEntryOrder@8' as ZwSetDriverEntryOrder:dword
            extrn '__imp__ZwSetInformationEnlistment@16' as ZwSetInformationEnlistment:dword
            extrn '__imp__ZwSetInformationTransaction@16' as ZwSetInformationTransaction:dword
            extrn '__imp__ZwUnloadKeyEx@8' as ZwUnloadKeyEx:dword
            extrn '__imp___strtoui64@12' as _strtoui64:dword
            extrn '__imp___swprintf@16' as _swprintf:dword
            extrn '__imp___vswprintf@16' as _vswprintf:dword
        end if

        if (NTDDI_VERSION >= NTDDI_WIN7)
            extrn '__imp__CcCoherencyFlushAndPurgeCache@20' as CcCoherencyFlushAndPurgeCache:dword
            extrn '__imp__CcCopyWriteWontFlush@12' as CcCopyWriteWontFlush:dword
            extrn '__imp__EtwWriteEx@32' as EtwWriteEx:dword
            extrn '__imp__ExAcquireFastMutex@4' as ExAcquireFastMutex:dword
            extrn '__imp__ExpInterlockedFlushSList@4' as ExpInterlockedFlushSList:dword
            extrn '__imp__ExpInterlockedPopEntrySList@4' as ExpInterlockedPopEntrySList:dword
            extrn '__imp__ExpInterlockedPushEntrySList@8' as ExpInterlockedPushEntrySList:dword
            extrn '__imp__ExQueryDepthSList@4' as ExQueryDepthSList:dword
            extrn '__imp__ExReleaseFastMutex@4' as ExReleaseFastMutex:dword
            extrn '__imp__ExSetResourceOwnerPointerEx@12' as ExSetResourceOwnerPointerEx:dword
            extrn '__imp__ExTryToAcquireFastMutex@4' as ExTryToAcquireFastMutex:dword
            extrn '__imp__FsRtlCurrentOplockH@4' as FsRtlCurrentOplockH:dword
            extrn '__imp__FsRtlAreThereCurrentOrInProgressFileLocks@4' as FsRtlAreThereCurrentOrInProgressFileLocks:dword
            extrn '__imp__FsRtlGetVirtualDiskNestingLevel@12' as FsRtlGetVirtualDiskNestingLevel:dword
            extrn '__imp__FsRtlOplockBreakH@24' as FsRtlOplockBreakH:dword
            extrn '__imp__FsRtlOplockBreakToNoneEx@24' as FsRtlOplockBreakToNoneEx:dword
            extrn '__imp__FsRtlOplockFsctrlEx@16' as FsRtlOplockFsctrlEx:dword
            extrn '__imp__FsRtlOplockIsSharedRequest@4' as FsRtlOplockIsSharedRequest:dword
            extrn '__imp__FsRtlOplockKeysEqual@8' as FsRtlOplockKeysEqual:dword
            extrn '__imp__FsRtlQueryMaximumVirtualDiskNestingLevel@0' as FsRtlQueryMaximumVirtualDiskNestingLevel:dword
            extrn '__imp__IoGetAffinityInterrupt@8' as IoGetAffinityInterrupt:dword
            extrn '__imp__IoGetContainerInformation@16' as IoGetContainerInformation:dword
            extrn '__imp__IoGetDeviceNumaNode@8' as IoGetDeviceNumaNode:dword
            extrn '__imp__IoGetOplockKeyContext@4' as IoGetOplockKeyContext:dword
            extrn '__imp__IoIs32bitProcess@4' as IoIs32bitProcess:dword
            extrn '__imp__IoRegisterContainerNotification@20' as IoRegisterContainerNotification:dword
            extrn '__imp__IoRegisterFsRegistrationChangeMountAware@12' as IoRegisterFsRegistrationChangeMountAware:dword
            extrn '__imp__IoReplaceFileObjectName@12' as IoReplaceFileObjectName:dword
            extrn '__imp__IoReportRootDevice@4' as IoReportRootDevice:dword
            extrn '__imp__IoSetFileObjectIgnoreSharing@4' as IoSetFileObjectIgnoreSharing:dword
            extrn '__imp__IoUnregisterContainerNotification@4' as IoUnregisterContainerNotification:dword
            extrn '__imp__IoUnregisterPlugPlayNotificationEx@4' as IoUnregisterPlugPlayNotificationEx:dword
            extrn '__imp__IoUnregisterPriorityCallback@4' as IoUnregisterPriorityCallback:dword
            extrn '__imp__IoWMIDeviceObjectToProviderId@4' as IoWMIDeviceObjectToProviderId:dword
            extrn '__imp__KeAndAffinityEx@12' as KeAndAffinityEx:dword
            extrn '__imp__KeComplementAffinityEx@8' as KeComplementAffinityEx:dword
            extrn '__imp__KeGetCurrentNodeNumber@0' as KeGetCurrentNodeNumber:dword
            extrn '__imp__KeGetCurrentProcessorNumberEx@4' as KeGetCurrentProcessorNumberEx:dword
            extrn '__imp__KeGetProcessorIndexFromNumber@4' as KeGetProcessorIndexFromNumber:dword
            extrn '__imp__KeGetProcessorNumberFromIndex@8' as KeGetProcessorNumberFromIndex:dword
            extrn '__imp__KeInitializeEnumerationContext@0' as KeInitializeEnumerationContext:dword
            extrn '__imp__KeInterlockedSetProcessorAffinityEx@8' as KeInterlockedSetProcessorAffinityEx:dword
            extrn '__imp__KeIsEmptyAffinityEx@4' as KeIsEmptyAffinityEx:dword
            extrn '__imp__KeIsEqualAffinityEx@8' as KeIsEqualAffinityEx:dword
            extrn '__imp__KeIsSubsetAffinityEx@8' as KeIsSubsetAffinityEx:dword
            extrn '__imp__KeQueryActiveGroupCount@0' as KeQueryActiveGroupCount:dword
            extrn '__imp__KeQueryActiveProcessorCountEx@4' as KeQueryActiveProcessorCountEx:dword
            extrn '__imp__KeQueryGroupAffinity@4' as KeQueryGroupAffinity:dword
            extrn '__imp__KeQueryHardwareCounterConfiguration@12' as KeQueryHardwareCounterConfiguration:dword
            extrn '__imp__KeQueryHighestNodeNumber@0' as KeQueryHighestNodeNumber:dword
            extrn '__imp__KeQueryLogicalProcessorRelationship@16' as KeQueryLogicalProcessorRelationship:dword
            extrn '__imp__KeQueryMaximumGroupCount@0' as KeQueryMaximumGroupCount:dword
            extrn '__imp__KeQueryMaximumProcessorCountEx@4' as KeQueryMaximumProcessorCountEx:dword
            extrn '__imp__KeQueryNodeActiveAffinity@12' as KeQueryNodeActiveAffinity:dword
            extrn '__imp__KeQueryNodeMaximumProcessorCount@4' as KeQueryNodeMaximumProcessorCount:dword
            extrn '__imp__KeQueryUnbiasedInterruptTime@0' as KeQueryUnbiasedInterruptTime:dword
            extrn '__imp__KeSaveExtendedProcessorState@8' as KeSaveExtendedProcessorState:dword
            extrn '__imp__KeSetCoalescableTimer@20' as KeSetCoalescableTimer:dword
            extrn '__imp__KeSetHardwareCounterConfiguration@8' as KeSetHardwareCounterConfiguration:dword
            extrn '__imp__KeSetSystemGroupAffinityThread@8' as KeSetSystemGroupAffinityThread:dword
            extrn '__imp__KeSetTargetProcessorDpcEx@8' as KeSetTargetProcessorDpcEx:dword
            extrn '__imp__memcpy_s@16' as memcpy_s:dword
            extrn '__imp__memmove_s@16' as memmove_s:dword
            extrn '__imp__NtCreateTransactionManager@24' as NtCreateTransactionManager:dword
            extrn '__imp__NtOpenTransactionManager@24' as NtOpenTransactionManager:dword
            extrn '__imp__NtPrePrepareComplete@8' as NtPrePrepareComplete:dword
            extrn '__imp__NtPropagationComplete@16' as NtPropagationComplete:dword
            extrn '__imp__NtPropagationFailed@12' as NtPropagationFailed:dword
            extrn '__imp__NtQuerySecurityAttributesToken@24' as NtQuerySecurityAttributesToken:dword
            extrn '__imp__NtQuerySystemInformationEx@24' as NtQuerySystemInformationEx:dword
            extrn '__imp__NtReadOnlyEnlistment@8' as NtReadOnlyEnlistment:dword
            extrn '__imp__NtRecoverEnlistment@8' as NtRecoverEnlistment:dword
            extrn '__imp__NtRecoverResourceManager@4' as NtRecoverResourceManager:dword
            extrn '__imp__NtRecoverTransactionManager@4' as NtRecoverTransactionManager:dword
            extrn '__imp__NtRollbackComplete@8' as NtRollbackComplete:dword
            extrn '__imp__NtSetInformationToken@16' as NtSetInformationToken:dword
            extrn '__imp__ObDereferenceObjectDeferDeleteWithTag@8' as ObDereferenceObjectDeferDeleteWithTag:dword
            extrn '__imp__ObfReferenceObjectWithTag@8' as ObfReferenceObjectWithTag:dword
            extrn '__imp__ObOpenObjectByPointerWithTag@32' as ObOpenObjectByPointerWithTag:dword
            extrn '__imp__ObQueryNameInfo@4' as ObQueryNameInfo:dword
            extrn '__imp__ObReferenceObjectByHandleWithTag@28' as ObReferenceObjectByHandleWithTag:dword
            extrn '__imp__ObReferenceObjectByPointerWithTag@20' as ObReferenceObjectByPointerWithTag:dword
            extrn '__imp__PcwAddInstance@20' as PcwAddInstance:dword
            extrn '__imp__PcwCloseInstance@4' as PcwCloseInstance:dword
            extrn '__imp__PcwCreateInstance@20' as PcwCreateInstance:dword
            extrn '__imp__PcwRegister@8' as PcwRegister:dword
            extrn '__imp__PcwUnregister@4' as PcwUnregister:dword
            extrn '__imp__PoClearPowerRequest@8' as PoClearPowerRequest:dword
            extrn '__imp__PoCreatePowerRequest@12' as PoCreatePowerRequest:dword
            extrn '__imp__PoDeletePowerRequest@4' as PoDeletePowerRequest:dword
            extrn '__imp__PoEndDeviceBusy@4' as PoEndDeviceBusy:dword
            extrn '__imp__PoQueryWatchdogTime@8' as PoQueryWatchdogTime:dword
            extrn '__imp__PoSetPowerRequest@8' as PoSetPowerRequest:dword
            extrn '__imp__PoStartDeviceBusy@4' as PoStartDeviceBusy:dword
            extrn '__imp__RtlDowncaseUnicodeChar@4' as RtlDowncaseUnicodeChar:dword
            extrn '__imp__RtlCompareUnicodeStrings@12' as RtlCompareUnicodeStrings:dword
            extrn '__imp__RtlEthernetAddressToStringA@8' as RtlEthernetAddressToStringA:dword
            extrn '__imp__RtlEthernetAddressToStringW@8' as RtlEthernetAddressToStringW:dword
            extrn '__imp__RtlEthernetStringToAddressA@12' as RtlEthernetStringToAddressA:dword
            extrn '__imp__RtlEthernetStringToAddressW@12' as RtlEthernetStringToAddressW:dword
            extrn '__imp__RtlGetEnabledExtendedFeatures@4' as RtlGetEnabledExtendedFeatures:dword
            extrn '__imp__RtlGetNextEntryHashTable@8' as RtlGetNextEntryHashTable:dword
            extrn '__imp__RtlInitEnumerationHashTable@8' as RtlInitEnumerationHashTable:dword
            extrn '__imp__RtlInitWeakEnumerationHashTable@8' as RtlInitWeakEnumerationHashTable:dword
            extrn '__imp__RtlInsertEntryHashTable@16' as RtlInsertEntryHashTable:dword
            extrn '__imp__RtlLookupEntryHashTable@12' as RtlLookupEntryHashTable:dword
            extrn '__imp__RtlUnicodeToUTF8N@20' as RtlUnicodeToUTF8N:dword
            extrn '__imp__RtlUTF8ToUnicodeN@20' as RtlUTF8ToUnicodeN:dword
            extrn '__imp__SeAccessCheckEx@12' as SeAccessCheckEx:dword
            extrn '__imp__SeAuditingAnyFileEventsWithContext@12' as SeAuditingAnyFileEventsWithContext:dword
            extrn '__imp__SeAuditingFileEventsWithContext@12' as SeAuditingFileEventsWithContext:dword
            extrn '__imp__vsprintf_s@16' as vsprintf_s:dword
            extrn '__imp__vswprintf_s@16' as vswprintf_s:dword
            extrn '__imp__wcscat_s@12' as wcscat_s:dword
            extrn '__imp__wcscpy_s@12' as wcscpy_s:dword
            extrn '__imp__wcsncat_s@16' as wcsncat_s:dword
            extrn '__imp__wcsncpy_s@16' as wcsncpy_s:dword
            extrn '__imp__wcsnlen@8' as wcsnlen:dword
            extrn '__imp__wcstoul@12' as wcstoul:dword
            extrn '__imp__ZwCommitComplete@8' as ZwCommitComplete:dword
            extrn '__imp__ZwLockFile@40' as ZwLockFile:dword
            extrn '__imp__ZwOpenKeyEx@16' as ZwOpenKeyEx:dword
            extrn '__imp__ZwOpenKeyTransactedEx@20' as ZwOpenKeyTransactedEx:dword
            extrn '__imp__ZwOpenSession@12' as ZwOpenSession:dword
            extrn '__imp__ZwPrePrepareComplete@8' as ZwPrePrepareComplete:dword
            extrn '__imp__ZwPropagationComplete@16' as ZwPropagationComplete:dword
            extrn '__imp__ZwPropagationFailed@12' as ZwPropagationFailed:dword
            extrn '__imp__ZwQueryQuotaInformationFile@36' as ZwQueryQuotaInformationFile:dword
            extrn '__imp__ZwQuerySecurityAttributesToken@24' as ZwQuerySecurityAttributesToken:dword
            extrn '__imp__ZwReadOnlyEnlistment@8' as ZwReadOnlyEnlistment:dword
            extrn '__imp__ZwRenameKey@8' as ZwRenameKey:dword
            extrn '__imp__ZwRollbackComplete@8' as ZwRollbackComplete:dword
            extrn '__imp__ZwSetInformationResourceManager@16' as ZwSetInformationResourceManager:dword
            extrn '__imp__ZwSetInformationToken@16' as ZwSetInformationToken:dword
            extrn '__imp__ZwSetQuotaInformationFile@16' as ZwSetQuotaInformationFile:dword
            extrn '__imp__ZwSetTimerEx@16' as ZwSetTimerEx:dword
            extrn '__imp__ZwTraceEvent@16' as ZwTraceEvent:dword
            extrn '__imp__ZwUnlockFile@20' as ZwUnlockFile:dword
            extrn '__imp___i64toa_s@16' as _i64toa_s:dword
            extrn '__imp___i64tow_s@16' as _i64tow_s:dword
            extrn '__imp___itoa_s@16' as _itoa_s:dword
            extrn '__imp___itow_s@16' as _itow_s:dword
            extrn '__imp___ltoa_s@16' as _ltoa_s:dword
            extrn '__imp___ltow_s@16' as _ltow_s:dword
            extrn '__imp___makepath_s@24' as _makepath_s:dword
            extrn '__imp___snprintf_s@20' as _snprintf_s:dword
            extrn '__imp___splitpath_s@36' as _splitpath_s:dword
            extrn '__imp___strnset_s@16' as _strnset_s:dword
            extrn '__imp___strset_s@12' as _strset_s:dword
            extrn '__imp___ui64toa_s@16' as _ui64toa_s:dword
            extrn '__imp___ui64tow_s@16' as _ui64tow_s:dword
            extrn '__imp___ultoa_s@16' as _ultoa_s:dword
            extrn '__imp___ultow_s@16' as _ultow_s:dword
            extrn '__imp___vsnprintf_s@20' as _vsnprintf_s:dword
            extrn '__imp___vsnwprintf_s@20' as _vsnwprintf_s:dword
            extrn '__imp___wcsnset_s@16' as _wcsnset_s:dword
            extrn '__imp___wcsset_s@12' as _wcsset_s:dword
            extrn '__imp___wmakepath_s@24' as _wmakepath_s:dword
            extrn '__imp___wsplitpath_s@36' as _wsplitpath_s:dword
            extrn '__imp___wtoi@4' as _wtoi:dword
            extrn '__imp___wtol@4' as _wtol:dword

            api RtlEthernetAddressToString,\
                RtlEthernetStringToAddress
        end if

        if (NTDDI_VERSION >= NTDDI_WIN8)
            extrn '__imp__bsearch_s@20' as bsearch_s:dword
            extrn '__imp__CcCopyReadEx@28' as CcCopyReadEx:dword
            extrn '__imp__CcCopyWriteEx@24' as CcCopyWriteEx:dword
            extrn '__imp__CcIsThereDirtyLoggedPages@8' as CcIsThereDirtyLoggedPages:dword
            extrn '__imp__CcScheduleReadAheadEx@16' as CcScheduleReadAheadEx:dword
            extrn '__imp__CcSetAdditionalCacheAttributesEx@8' as CcSetAdditionalCacheAttributesEx:dword
            extrn '__imp__CcSetLoggedDataThreshold@8' as CcSetLoggedDataThreshold:dword
            extrn '__imp__CcSetLogHandleForFileEx@16' as CcSetLogHandleForFileEx:dword
            extrn '__imp__CcSetReadAheadGranularityEx@12' as CcSetReadAheadGranularityEx:dword
            extrn '__imp__CcUnmapFileOffsetFromSystemCache@16' as CcUnmapFileOffsetFromSystemCache:dword
            extrn '__imp__CmCallbackGetKeyObjectIDEx@20' as CmCallbackGetKeyObjectIDEx:dword
            extrn '__imp__CmCallbackReleaseKeyObjectIDEx@4' as CmCallbackReleaseKeyObjectIDEx:dword
            extrn '__imp__ExBlockPushLock@8' as ExBlockPushLock:dword
            extrn '__imp__ExGetFirmwareEnvironmentVariable@20' as ExGetFirmwareEnvironmentVariable:dword
            extrn '__imp__ExQueryTimerResolution@12' as ExQueryTimerResolution:dword
            extrn '__imp__ExSetFirmwareEnvironmentVariable@20' as ExSetFirmwareEnvironmentVariable:dword
            extrn '__imp__ExTimedWaitForUnblockPushLock@12' as ExTimedWaitForUnblockPushLock:dword
            extrn '__imp__ExWaitForUnblockPushLock@8' as ExWaitForUnblockPushLock:dword
            extrn '__imp__FsRtlAreThereWaitingFileLocks@4' as FsRtlAreThereWaitingFileLocks:dword
            extrn '__imp__FsRtlCheckLockForOplockRequest@8' as FsRtlCheckLockForOplockRequest:dword
            extrn '__imp__FsRtlGetSectorSizeInformation@8' as FsRtlGetSectorSizeInformation:dword
            extrn '__imp__FsRtlGetSupportedFeatures@8' as FsRtlGetSupportedFeatures:dword
            extrn '__imp__FsRtlIssueDeviceIoControl@32' as FsRtlIssueDeviceIoControl:dword
            extrn '__imp__FsRtlIsSystemPagingFile@4' as FsRtlIsSystemPagingFile:dword
            extrn '__imp__FsRtlMdlReadEx@24' as FsRtlMdlReadEx:dword
            extrn '__imp__FsRtlPrepareMdlWriteEx@24' as FsRtlPrepareMdlWriteEx:dword
            extrn '__imp__FsRtlQueryCachedVdl@8' as FsRtlQueryCachedVdl:dword
            extrn '__imp__IoClearActivityIdThread@4' as IoClearActivityIdThread:dword
            extrn '__imp__IoCreateStreamFileObjectEx2@20' as IoCreateStreamFileObjectEx2:dword
            extrn '__imp__IoCreateSystemThread@12' as IoCreateSystemThread:dword
            extrn '__imp__IoDecrementKeepAliveCount@8' as IoDecrementKeepAliveCount:dword
            extrn '__imp__IoGetActivityIdIrp@8' as IoGetActivityIdIrp:dword
            extrn '__imp__IoGetActivityIdThread@0' as IoGetActivityIdThread:dword
            extrn '__imp__IoGetDeviceInterfacePropertyData@32' as IoGetDeviceInterfacePropertyData:dword
            extrn '__imp__IoGetInitiatorProcess@4' as IoGetInitiatorProcess:dword
            extrn '__imp__IoGetOplockKeyContextEx@4' as IoGetOplockKeyContextEx:dword
            extrn '__imp__IoIncrementKeepAliveCount@8' as IoIncrementKeepAliveCount:dword
            extrn '__imp__IoIsInitiator32bitProcess@4' as IoIsInitiator32bitProcess:dword
            extrn '__imp__IoIsValidIrpStatus@4' as IoIsValidIrpStatus:dword
            extrn '__imp__IoPropagateActivityIdToThread@12' as IoPropagateActivityIdToThread:dword
            extrn '__imp__IoRegisterBootDriverCallback@8' as IoRegisterBootDriverCallback:dword
            extrn '__imp__IoReportInterruptActive@4' as IoReportInterruptActive:dword
            extrn '__imp__IoReportInterruptInactive@4' as IoReportInterruptInactive:dword
            extrn '__imp__IoSetActivityIdIrp@8' as IoSetActivityIdIrp:dword
            extrn '__imp__IoSetActivityIdThread@4' as IoSetActivityIdThread:dword
            extrn '__imp__IoSetDeviceInterfacePropertyData@28' as IoSetDeviceInterfacePropertyData:dword
            extrn '__imp__IoSetMasterIrpStatus@8' as IoSetMasterIrpStatus:dword
            extrn '__imp__IoTransferActivityId@8' as IoTransferActivityId:dword
            extrn '__imp__IoTryQueueWorkItem@16' as IoTryQueueWorkItem:dword
            extrn '__imp__IoUnregisterBootDriverCallback@4' as IoUnregisterBootDriverCallback:dword
            extrn '__imp__IoVolumeDeviceToGuid@8' as IoVolumeDeviceToGuid:dword
            extrn '__imp__KdLogDbgPrint@4' as KdLogDbgPrint:dword
            extrn '__imp__KeQueryInterruptTimePrecise@4' as KeQueryInterruptTimePrecise:dword
            extrn '__imp__KeQuerySystemTimePrecise@4' as KeQuerySystemTimePrecise:dword
            extrn '__imp__KeQueryTotalCycleTimeThread@8' as KeQueryTotalCycleTimeThread:dword
            extrn '__imp__MmAllocateContiguousNodeMemory@24' as MmAllocateContiguousNodeMemory:dword
            extrn '__imp__MmAllocateMdlForIoSpace@12' as MmAllocateMdlForIoSpace:dword
            extrn '__imp__MmAllocateNodePagesForMdlEx@28' as MmAllocateNodePagesForMdlEx:dword
            extrn '__imp__MmGetMaximumFileSectionSize@0' as MmGetMaximumFileSectionSize:dword
            extrn '__imp__MmIsDriverSuspectForVerifier@4' as MmIsDriverSuspectForVerifier:dword
            extrn '__imp__ObDuplicateObject@32' as ObDuplicateObject:dword
            extrn '__imp__ObReferenceObjectSafe@4' as ObReferenceObjectSafe:dword
            extrn '__imp__ObWaitForSingleObject@12' as ObWaitForSingleObject:dword
            extrn '__imp__PoFxActivateComponent@12' as PoFxActivateComponent:dword
            extrn '__imp__PoFxCompleteDevicePowerNotRequired@4' as PoFxCompleteDevicePowerNotRequired:dword
            extrn '__imp__PoFxCompleteIdleCondition@8' as PoFxCompleteIdleCondition:dword
            extrn '__imp__PoFxCompleteIdleState@8' as PoFxCompleteIdleState:dword
            extrn '__imp__PoFxIdleComponent@12' as PoFxIdleComponent:dword
            extrn '__imp__PoFxNotifySurprisePowerOn@4' as PoFxNotifySurprisePowerOn:dword
            extrn '__imp__PoFxPowerControl@28' as PoFxPowerControl:dword
            extrn '__imp__PoFxRegisterDevice@12' as PoFxRegisterDevice:dword
            extrn '__imp__PoFxReportDevicePoweredOn@4' as PoFxReportDevicePoweredOn:dword
            extrn '__imp__PoFxSetComponentLatency@12' as PoFxSetComponentLatency:dword
            extrn '__imp__PoFxSetComponentResidency@12' as PoFxSetComponentResidency:dword
            extrn '__imp__PoFxSetComponentWake@12' as PoFxSetComponentWake:dword
            extrn '__imp__PoFxSetDeviceIdleTimeout@8' as PoFxSetDeviceIdleTimeout:dword
            extrn '__imp__PoFxStartDevicePowerManagement@4' as PoFxStartDevicePowerManagement:dword
            extrn '__imp__PoFxUnregisterDevice@4' as PoFxUnregisterDevice:dword
            extrn '__imp__PsCreateSystemThreadEx@40' as PsCreateSystemThreadEx:dword
            extrn '__imp__PsGetThreadExitStatus@4' as PsGetThreadExitStatus:dword
            extrn '__imp__PsIsDiskCountersEnabled@0' as PsIsDiskCountersEnabled:dword
            extrn '__imp__PsQueryTotalCycleTimeProcess@8' as PsQueryTotalCycleTimeProcess:dword
            extrn '__imp__PsUpdateDiskCounters@24' as PsUpdateDiskCounters:dword
            extrn '__imp__RtlCheckPortableOperatingSystem@0' as RtlCheckPortableOperatingSystem:dword
            extrn '__imp__RtlCreateUserThread@40' as RtlCreateUserThread:dword
            extrn '__imp__RtlCultureNameToLCID@8' as RtlCultureNameToLCID:dword
            extrn '__imp__RtlDecompressBufferEx@28' as RtlDecompressBufferEx:dword
            extrn '__imp__RtlDeleteElementGenericTableAvlEx@8' as RtlDeleteElementGenericTableAvlEx:dword
            extrn '__imp__RtlOpenCurrentUser@8' as RtlOpenCurrentUser:dword
            extrn '__imp__RtlQueryInformationAcl@16' as RtlQueryInformationAcl:dword
            extrn '__imp__RtlRbInsertNodeEx@16' as RtlRbInsertNodeEx:dword
            extrn '__imp__RtlRbRemoveNode@8' as RtlRbRemoveNode:dword
            extrn '__imp__RtlSetControlSecurityDescriptor@12' as RtlSetControlSecurityDescriptor:dword
            extrn '__imp__TmInitializeTransactionManager@16' as TmInitializeTransactionManager:dword
            extrn '__imp__TmRenameTransactionManager@8' as TmRenameTransactionManager:dword
            extrn '__imp__TmSinglePhaseReject@8' as TmSinglePhaseReject:dword
            extrn '__imp__WheaRegisterInUsePageOfflineNotification@8' as WheaRegisterInUsePageOfflineNotification:dword
            extrn '__imp__WheaUnregisterInUsePageOfflineNotification@4' as WheaUnregisterInUsePageOfflineNotification:dword
            extrn '__imp__ZwFlushBuffersFileEx@12' as ZwFlushBuffersFileEx:dword
            extrn '__imp__ZwQuerySystemEnvironmentValueEx@20' as ZwQuerySystemEnvironmentValueEx:dword
            extrn '__imp__ZwSetInformationKey@16' as ZwSetInformationKey:dword
            extrn '__imp__ZwSetSystemEnvironmentValueEx@20' as ZwSetSystemEnvironmentValueEx:dword
            extrn '__imp__ZwUnlockVirtualMemory@16' as ZwUnlockVirtualMemory:dword
        end if

        if (NTDDI_VERSION >= NTDDI_WIN81)
            extrn '__imp__ExAllocateTimer@12' as ExAllocateTimer:dword
            extrn '__imp__ExCancelTimer@8' as ExCancelTimer:dword
            extrn '__imp__ExDeleteTimer@16' as ExDeleteTimer:dword
            extrn '__imp__ExSetTimer@16' as ExSetTimer:dword
            extrn '__imp__FsRtlUpperOplockFsctrl@20' as FsRtlUpperOplockFsctrl:dword
            extrn '__imp__IoQueryFullDriverPath@8' as IoQueryFullDriverPath:dword
            extrn '__imp__MmCopyMemory@20' as MmCopyMemory:dword
            extrn '__imp__MmMdlPagesAreZero@4' as MmMdlPagesAreZero:dword
            extrn '__imp__PoFxPowerOnCrashdumpDevice@8' as PoFxPowerOnCrashdumpDevice:dword
            extrn '__imp__PoFxRegisterCrashdumpDevice@4' as PoFxRegisterCrashdumpDevice:dword
            extrn '__imp__SeAdjustAccessStateForTrustLabel@12' as SeAdjustAccessStateForTrustLabel:dword
            extrn '__imp__SeShouldCheckForAccessRightsFromParent@12' as SeShouldCheckForAccessRightsFromParent:dword
            extrn '__imp__ZwAssociateWaitCompletionPacket@32' as ZwAssociateWaitCompletionPacket:dword
            extrn '__imp__ZwCancelIoFileEx@12' as ZwCancelIoFileEx:dword
            extrn '__imp__ZwCreateWaitCompletionPacket@12' as ZwCreateWaitCompletionPacket:dword
            extrn '__imp__ZwLockVirtualMemory@16' as ZwLockVirtualMemory:dword
            extrn '__imp__ZwQuerySystemInformationEx@24' as ZwQuerySystemInformationEx:dword
        end if

        if (NTDDI_VERSION >= NTDDI_WIN10)
            extrn '__imp___finite@4' as _finite:dword
            extrn '__imp___wcslwr_s@8' as _wcslwr_s:dword
            extrn '__imp__CcAsyncCopyRead@32' as CcAsyncCopyRead:dword
            extrn '__imp__ExIsManufacturingModeEnabled@0' as ExIsManufacturingModeEnabled:dword
            extrn '__imp__IoClearFsTrackOffsetState@4' as IoClearFsTrackOffsetState:dword
            extrn '__imp__IoGetSiloParameters@4' as IoGetSiloParameters:dword
            extrn '__imp__IoInitializeIrpEx@16' as IoInitializeIrpEx:dword
            extrn '__imp__IoIrpHasFsTrackOffsetExtensionType@4' as IoIrpHasFsTrackOffsetExtensionType:dword
            extrn '__imp__IoRequestDeviceRemovalForReset@8' as IoRequestDeviceRemovalForReset:dword
            extrn '__imp__IoSetFsTrackOffsetState@12' as IoSetFsTrackOffsetState:dword
            extrn '__imp__IoSetFsZeroingOffset@8' as IoSetFsZeroingOffset:dword
            extrn '__imp__IoSetFsZeroingOffsetRequired@4' as IoSetFsZeroingOffsetRequired:dword
            extrn '__imp__IoSizeOfIrpEx@8' as IoSizeOfIrpEx:dword
            extrn '__imp__IoVolumeDeviceNameToGuid@8' as IoVolumeDeviceNameToGuid:dword
            extrn '__imp__KeConvertAuxiliaryCounterToPerformanceCounter@12' as KeConvertAuxiliaryCounterToPerformanceCounter:dword
            extrn '__imp__KeConvertPerformanceCounterToAuxiliaryCounter@12' as KeConvertPerformanceCounterToAuxiliaryCounter:dword
            extrn '__imp__KeDeregisterBoundCallback@4' as KeDeregisterBoundCallback:dword
            extrn '__imp__KeFlushIoBuffers@12' as KeFlushIoBuffers:dword
            extrn '__imp__KeQueryAuxiliaryCounterFrequency@4' as KeQueryAuxiliaryCounterFrequency:dword
            extrn '__imp__KeRegisterBoundCallback@4' as KeRegisterBoundCallback:dword
            extrn '__imp__KeShouldYieldProcessor@0' as KeShouldYieldProcessor:dword
            extrn '__imp__MmLoadSystemImage@24' as MmLoadSystemImage:dword
            extrn '__imp__MmMapIoSpaceEx@12' as MmMapIoSpaceEx:dword
            extrn '__imp__MmUnloadSystemImage@4' as MmUnloadSystemImage:dword
            extrn '__imp__PoCreateThermalRequest@20' as PoCreateThermalRequest:dword
            extrn '__imp__PoDeleteThermalRequest@4' as PoDeleteThermalRequest:dword
            extrn '__imp__PoFxIssueComponentPerfStateChange@20' as PoFxIssueComponentPerfStateChange:dword
            extrn '__imp__PoFxIssueComponentPerfStateChangeMultiple@24' as PoFxIssueComponentPerfStateChangeMultiple:dword
            extrn '__imp__PoFxQueryCurrentComponentPerfState@20' as PoFxQueryCurrentComponentPerfState:dword
            extrn '__imp__PoFxRegisterComponentPerfStates@24' as PoFxRegisterComponentPerfStates:dword
            extrn '__imp__PoGetThermalRequestSupport@8' as PoGetThermalRequestSupport:dword
            extrn '__imp__PoSetThermalActiveCooling@8' as PoSetThermalActiveCooling:dword
            extrn '__imp__PoSetThermalPassiveCooling@8' as PoSetThermalPassiveCooling:dword
            extrn '__imp__PsAllocateMonitorContextServerSilo@12' as PsAllocateMonitorContextServerSilo:dword
            extrn '__imp__PsAttachSiloToCurrentThread@4' as PsAttachSiloToCurrentThread:dword
            extrn '__imp__PsDeleteMonitorContextServerSilo@4' as PsDeleteMonitorContextServerSilo:dword
            extrn '__imp__PsDereferenceMonitorContextServerSilo@4' as PsDereferenceMonitorContextServerSilo:dword
            extrn '__imp__PsDetachSiloFromCurrentThread@4' as PsDetachSiloFromCurrentThread:dword
            extrn '__imp__PsEqualCurrentServerSilo@4' as PsEqualCurrentServerSilo:dword
            extrn '__imp__PsEqualCurrentSilo@4' as PsEqualCurrentSilo:dword
            extrn '__imp__PsGetCurrentServerSilo@0' as PsGetCurrentServerSilo:dword
            extrn '__imp__PsGetCurrentServerSiloName@0' as PsGetCurrentServerSiloName:dword
            extrn '__imp__PsGetCurrentSilo@0' as PsGetCurrentSilo:dword
            extrn '__imp__PsGetCurrentSiloObject@8' as PsGetCurrentSiloObject:dword
            extrn '__imp__PsGetJobServerSilo@8' as PsGetJobServerSilo:dword
            extrn '__imp__PsGetMonitorContextServerSilo@12' as PsGetMonitorContextServerSilo:dword
            extrn '__imp__PsGetServerSiloServiceSessionId@4' as PsGetServerSiloServiceSessionId:dword
            extrn '__imp__PsGetSiloObjectFromJob@12' as PsGetSiloObjectFromJob:dword
            extrn '__imp__PsGetThreadCreateTime@4' as PsGetThreadCreateTime:dword
            extrn '__imp__PsGetThreadProperty@12' as PsGetThreadProperty:dword
            extrn '__imp__PsInsertSiloObjectFromJob@12' as PsInsertSiloObjectFromJob:dword
            extrn '__imp__PsIsCurrentThreadInServerSilo@0' as PsIsCurrentThreadInServerSilo:dword
            extrn '__imp__PsIsHostSilo@4' as PsIsHostSilo:dword
            extrn '__imp__PsReferenceMonitorContextServerSilo@0' as PsReferenceMonitorContextServerSilo:dword
            extrn '__imp__PsRegisterMonitorServerSilo@16' as PsRegisterMonitorServerSilo:dword
            extrn '__imp__PsRegisterPicoProvider@8' as PsRegisterPicoProvider:dword
            extrn '__imp__PsRemoveSiloObjectFromJob@8' as PsRemoveSiloObjectFromJob:dword
            extrn '__imp__PsSetCreateThreadNotifyRoutineEx@8' as PsSetCreateThreadNotifyRoutineEx:dword
            extrn '__imp__PsSetMonitorContextServerSilo@20' as PsSetMonitorContextServerSilo:dword
            extrn '__imp__PsStartMonitorServerSilo@4' as PsStartMonitorServerSilo:dword
            extrn '__imp__PsUnregisterMonitorServerSilo@4' as PsUnregisterMonitorServerSilo:dword
            extrn '__imp__RtlAddAccessDeniedAceEx@20' as RtlAddAccessDeniedAceEx:dword
            extrn '__imp__RtlAddAccessDeniedObjectAce@28' as RtlAddAccessDeniedObjectAce:dword
            extrn '__imp__RtlAddAuditAccessAceEx@28' as RtlAddAuditAccessAceEx:dword
            extrn '__imp__RtlAddAuditAccessObjectAce@36' as RtlAddAuditAccessObjectAce:dword
            extrn '__imp__RtlDecompressBufferEx2@32' as RtlDecompressBufferEx2:dword
            extrn '__imp__RtlDecompressFragmentEx@36' as RtlDecompressFragmentEx:dword
            extrn '__imp__RtlEndStrongEnumerationHashTable@8' as RtlEndStrongEnumerationHashTable:dword
            extrn '__imp__RtlFirstFreeAce@8' as RtlFirstFreeAce:dword
            extrn '__imp__RtlGetControlSecurityDescriptor@12' as RtlGetControlSecurityDescriptor:dword
            extrn '__imp__RtlInitializeSidEx@12' as RtlInitializeSidEx:dword
            extrn '__imp__RtlInitStringEx@8' as RtlInitStringEx:dword
            extrn '__imp__RtlInitStrongEnumerationHashTable@8' as RtlInitStrongEnumerationHashTable:dword
            extrn '__imp__RtlLargeIntegerToChar@16' as RtlLargeIntegerToChar:dword
            extrn '__imp__RtlOsDeploymentState@4' as RtlOsDeploymentState:dword
            extrn '__imp__RtlStronglyEnumerateEntryHashTable@8' as RtlStronglyEnumerateEntryHashTable:dword
            extrn '__imp__RtlSuffixUnicodeString@12' as RtlSuffixUnicodeString:dword
            extrn '__imp__RtlUnicodeStringToInt64@16' as RtlUnicodeStringToInt64:dword
            extrn '__imp__RtlValidAcl@4' as RtlValidAcl:dword
            extrn '__imp__SeAuditFipsCryptoSelftests@8' as SeAuditFipsCryptoSelftests:dword
            extrn '__imp__SeMarkLogonSessionForTerminationNotificationEx@8' as SeMarkLogonSessionForTerminationNotificationEx:dword
            extrn '__imp__SeQuerySessionIdTokenEx@12' as SeQuerySessionIdTokenEx:dword
            extrn '__imp__SeRegisterLogonSessionTerminatedRoutineEx@4' as SeRegisterLogonSessionTerminatedRoutineEx:dword
            extrn '__imp__SeUnregisterLogonSessionTerminatedRoutineEx@4' as SeUnregisterLogonSessionTerminatedRoutineEx:dword
            extrn '__imp__ZwAlpcOpenSenderThread@24' as ZwAlpcOpenSenderThread:dword
            extrn '__imp__ZwAlpcQueryInformationMessage@24' as ZwAlpcQueryInformationMessage:dword
            extrn '__imp__ZwCompareTokens@12' as ZwCompareTokens:dword
            extrn '__imp__ZwGetCachedSigningLevel@24' as ZwGetCachedSigningLevel:dword
            extrn '__imp__ZwGetNextProcess@20' as ZwGetNextProcess:dword
            extrn '__imp__ZwNotifyChangeDirectoryFile@36' as ZwNotifyChangeDirectoryFile:dword
            extrn '__imp__ZwTraceControl@24' as ZwTraceControl:dword
            extrn '__imp__ZwUnloadKey2@8' as ZwUnloadKey2:dword
        end if
    end if
end if

;======================= Undocumented functions (unknown arguments) =======================;
;if defined APP_WIN64
;    extrn '__imp_BgkDisplayCharacter' as BgkDisplayCharacter:qword
;    extrn '__imp_BgkGetConsoleState' as BgkGetConsoleState:qword
;    extrn '__imp_BgkGetCursorState' as BgkGetCursorState:qword
;    extrn '__imp_BgkSetCursor' as BgkSetCursor:qword
;    extrn '__imp_CcAddDirtyPagesToExternalCache' as CcAddDirtyPagesToExternalCache:qword
;    extrn '__imp_CcDeductDirtyPagesFromExternalCache' as CcDeductDirtyPagesFromExternalCache:qword
;    extrn '__imp_CcFlushCacheToLsn' as CcFlushCacheToLsn:qword
;    extrn '__imp_CcRegisterExternalCache' as CcRegisterExternalCache:qword
;    extrn '__imp_CcTestControl' as CcTestControl:qword
;    extrn '__imp_CcUnregisterExternalCache' as CcUnregisterExternalCache:qword
;    extrn '__imp_CcZeroDataOnDisk' as CcZeroDataOnDisk:qword
;    extrn '__imp_CmKeyObjectType' as CmKeyObjectType:qword
;    extrn '__imp_DbgkLkmdRegisterCallback' as DbgkLkmdRegisterCallback:qword
;    extrn '__imp_DbgkLkmdUnregisterCallback' as DbgkLkmdUnregisterCallback:qword
;    extrn '__imp_DbgkWerCaptureLiveKernelDump' as DbgkWerCaptureLiveKernelDump:qword
;    extrn '__imp_EmClientRuleDeregisterNotification' as EmClientRuleDeregisterNotification:qword
;    extrn '__imp_EmClientRuleEvaluate' as EmClientRuleEvaluate:qword
;    extrn '__imp_EmClientRuleRegisterNotification' as EmClientRuleRegisterNotification:qword
;    extrn '__imp_EmpProviderRegister' as EmpProviderRegister:qword
;    extrn '__imp_EmProviderDeregister' as EmProviderDeregister:qword
;    extrn '__imp_EmProviderDeregisterEntry' as EmProviderDeregisterEntry:qword
;    extrn '__imp_EmProviderRegister' as EmProviderRegister:qword
;    extrn '__imp_EmProviderRegisterEntry' as EmProviderRegisterEntry:qword
;    extrn '__imp_EtwEnableTrace' as EtwEnableTrace:qword
;    extrn '__imp_EtwRegisterClassicProvider' as EtwRegisterClassicProvider:qword
;    extrn '__imp_EtwSendTraceBuffer' as EtwSendTraceBuffer:qword
;    extrn '__imp_EtwSetInformation' as EtwSetInformation:qword
;    extrn '__imp_EtwWriteEndScenario' as EtwWriteEndScenario:qword
;    extrn '__imp_CcFastReadNotPossible' as CcFastReadNotPossible:qword
;    extrn '__imp_EtwWriteStartScenario' as EtwWriteStartScenario:qword
;    extrn '__imp_ExAcquireAutoExpandPushLockExclusive' as ExAcquireAutoExpandPushLockExclusive:qword
;    extrn '__imp_ExAcquireAutoExpandPushLockShared' as ExAcquireAutoExpandPushLockShared:qword
;    extrn '__imp_ExAcquireCacheAwarePushLockExclusive' as ExAcquireCacheAwarePushLockExclusive:qword
;    extrn '__imp_ExAcquireCacheAwarePushLockExclusiveEx' as ExAcquireCacheAwarePushLockExclusiveEx:qword
;    extrn '__imp_ExAcquireCacheAwarePushLockSharedEx' as ExAcquireCacheAwarePushLockSharedEx:qword
;    extrn '__imp_ExAcquirePushLockExclusiveEx' as ExAcquirePushLockExclusiveEx:qword
;    extrn '__imp_ExAcquirePushLockSharedEx' as ExAcquirePushLockSharedEx:qword
;    extrn '__imp_ExAcquireRundownProtectionCacheAware' as ExAcquireRundownProtectionCacheAware:qword
;    extrn '__imp_ExAcquireRundownProtectionCacheAwareEx' as ExAcquireRundownProtectionCacheAwareEx:qword
;    extrn '__imp_ExAllocateAutoExpandPushLock' as ExAllocateAutoExpandPushLock:qword
;    extrn '__imp_ExBlockOnAddressPushLock' as ExBlockOnAddressPushLock:qword
;    extrn '__imp_ExCleanupAutoExpandPushLock' as ExCleanupAutoExpandPushLock:qword
;    extrn '__imp_ExCleanupRundownProtectionCacheAware' as ExCleanupRundownProtectionCacheAware:qword
;    extrn '__imp_ExCompositionObjectType' as ExCompositionObjectType:qword
;    extrn '__imp_ExCompositionSurfaceObjectType' as ExCompositionSurfaceObjectType:qword
;    extrn '__imp_ExConvertPushLockExclusiveToShared' as ExConvertPushLockExclusiveToShared:qword
;    extrn '__imp_ExDesktopObjectType' as ExDesktopObjectType:qword
;    extrn '__imp_ExEnterPriorityRegionAndAcquireResourceExclusive' as ExEnterPriorityRegionAndAcquireResourceExclusive:qword
;    extrn '__imp_ExEnterPriorityRegionAndAcquireResourceShared' as ExEnterPriorityRegionAndAcquireResourceShared:qword
;    extrn '__imp_ExEventObjectType' as ExEventObjectType:qword
;    extrn '__imp_ExFetchLicenseData' as ExFetchLicenseData:qword
;    extrn '__imp_ExFreeAutoExpandPushLock' as ExFreeAutoExpandPushLock:qword
;    extrn '__imp_ExFreeCacheAwareRundownProtection' as ExFreeCacheAwareRundownProtection:qword
;    extrn '__imp_ExfTryAcquirePushLockShared' as ExfTryAcquirePushLockShared:qword
;    extrn '__imp_ExGetLicenseTamperState' as ExGetLicenseTamperState:qword
;    extrn '__imp_ExiAcquireFastMutex' as ExiAcquireFastMutex:qword
;    extrn '__imp_ExInitializeAutoExpandPushLock' as ExInitializeAutoExpandPushLock:qword
;    extrn '__imp_ExInitializeRundownProtectionCacheAwareEx' as ExInitializeRundownProtectionCacheAwareEx:qword
;    extrn '__imp_ExNotifyBootDeviceRemoval' as ExNotifyBootDeviceRemoval:qword
;    extrn '__imp_ExQueryAttributeInformation' as ExQueryAttributeInformation:qword
;    extrn '__imp_ExQueryFastCacheAppOrigin' as ExQueryFastCacheAppOrigin:qword
;    extrn '__imp_ExQueryFastCacheDevLicense' as ExQueryFastCacheDevLicense:qword
;    extrn '__imp_ExQueryWnfStateData' as ExQueryWnfStateData:qword
;    extrn '__imp_ExRawInputManagerObjectType' as ExRawInputManagerObjectType:qword
;    extrn '__imp_ExRealTimeIsUniversal' as ExRealTimeIsUniversal:qword
;    extrn '__imp_ExRegisterAttributeInformationCallback' as ExRegisterAttributeInformationCallback:qword
;    extrn '__imp_ExRegisterBootDevice' as ExRegisterBootDevice:qword
;    extrn '__imp_ExRegisterExtension' as ExRegisterExtension:qword
;    extrn '__imp_ExReleaseAutoExpandPushLockExclusive' as ExReleaseAutoExpandPushLockExclusive:qword
;    extrn '__imp_ExReleaseAutoExpandPushLockShared' as ExReleaseAutoExpandPushLockShared:qword
;    extrn '__imp_ExReleaseCacheAwarePushLockExclusiveEx' as ExReleaseCacheAwarePushLockExclusiveEx:qword
;    extrn '__imp_ExReleaseCacheAwarePushLockSharedEx' as ExReleaseCacheAwarePushLockSharedEx:qword
;    extrn '__imp_ExReleasePushLockEx' as ExReleasePushLockEx:qword
;    extrn '__imp_ExReleasePushLockExclusiveEx' as ExReleasePushLockExclusiveEx:qword
;    extrn '__imp_ExReleasePushLockSharedEx' as ExReleasePushLockSharedEx:qword
;    extrn '__imp_ExReleaseResourceAndLeavePriorityRegion' as ExReleaseResourceAndLeavePriorityRegion:qword
;    extrn '__imp_ExSemaphoreObjectType' as ExSemaphoreObjectType:qword
;    extrn '__imp_ExShareAddressSpaceWithDevice' as ExShareAddressSpaceWithDevice:qword
;    extrn '__imp_ExSizeOfAutoExpandPushLock' as ExSizeOfAutoExpandPushLock:qword
;    extrn '__imp_ExSizeOfRundownProtectionCacheAware' as ExSizeOfRundownProtectionCacheAware:qword
;    extrn '__imp_ExSubscribeWnfStateChange' as ExSubscribeWnfStateChange:qword
;    extrn '__imp_ExTimerObjectType' as ExTimerObjectType:qword
;    extrn '__imp_ExTryAcquireAutoExpandPushLockExclusive' as ExTryAcquireAutoExpandPushLockExclusive:qword
;    extrn '__imp_ExTryAcquireAutoExpandPushLockShared' as ExTryAcquireAutoExpandPushLockShared:qword
;    extrn '__imp_ExTryAcquireCacheAwarePushLockExclusiveEx' as ExTryAcquireCacheAwarePushLockExclusiveEx:qword
;    extrn '__imp_ExTryAcquireCacheAwarePushLockSharedEx' as ExTryAcquireCacheAwarePushLockSharedEx:qword
;    extrn '__imp_ExTryAcquirePushLockExclusiveEx' as ExTryAcquirePushLockExclusiveEx:qword
;    extrn '__imp_ExTryAcquirePushLockSharedEx' as ExTryAcquirePushLockSharedEx:qword
;    extrn '__imp_ExTryConvertPushLockSharedToExclusiveEx' as ExTryConvertPushLockSharedToExclusiveEx:qword
;    extrn '__imp_ExTryQueueWorkItem' as ExTryQueueWorkItem:qword
;    extrn '__imp_ExTryToAcquireResourceExclusiveLite' as ExTryToAcquireResourceExclusiveLite:qword
;    extrn '__imp_ExUnblockOnAddressPushLockEx' as ExUnblockOnAddressPushLockEx:qword
;    extrn '__imp_ExUnblockPushLockEx' as ExUnblockPushLockEx:qword
;    extrn '__imp_ExUnregisterAttributeInformationCallback' as ExUnregisterAttributeInformationCallback:qword
;    extrn '__imp_ExUnregisterExtension' as ExUnregisterExtension:qword
;    extrn '__imp_ExUnsubscribeWnfStateChange' as ExUnsubscribeWnfStateChange:qword
;    extrn '__imp_ExUpdateLicenseData' as ExUpdateLicenseData:qword
;    extrn '__imp_ExWaitForRundownProtectionReleaseCacheAware' as ExWaitForRundownProtectionReleaseCacheAware:qword
;    extrn '__imp_ExWindowStationObjectType' as ExWindowStationObjectType:qword
;    extrn '__imp_FsRtlAcquireEofLock' as FsRtlAcquireEofLock:qword
;    extrn '__imp_FsRtlAcquireHeaderMutex' as FsRtlAcquireHeaderMutex:qword
;    extrn '__imp_FsRtlCheckUpperOplock' as FsRtlCheckUpperOplock:qword
;    extrn '__imp_FsRtlDismountComplete' as FsRtlDismountComplete:qword
;    extrn '__imp_FsRtlGetFileNameInformation' as FsRtlGetFileNameInformation:qword
;    extrn '__imp_FsRtlGetIoAtEof' as FsRtlGetIoAtEof:qword
;    extrn '__imp_FsRtlHeatInit' as FsRtlHeatInit:qword
;    extrn '__imp_FsRtlHeatLogIo' as FsRtlHeatLogIo:qword
;    extrn '__imp_FsRtlHeatLogTierMove' as FsRtlHeatLogTierMove:qword
;    extrn '__imp_FsRtlHeatUninit' as FsRtlHeatUninit:qword
;    extrn '__imp_FsRtlInitializeBaseMcb' as FsRtlInitializeBaseMcb:qword
;    extrn '__imp_FsRtlInitializeBaseMcbEx' as FsRtlInitializeBaseMcbEx:qword
;    extrn '__imp_FsRtlInitializeEofLock' as FsRtlInitializeEofLock:qword
;    extrn '__imp_FsRtlInsertReservedPerFileContext' as FsRtlInsertReservedPerFileContext:qword
;    extrn '__imp_FsRtlInsertReservedPerStreamContext' as FsRtlInsertReservedPerStreamContext:qword
;    extrn '__imp_FsRtlIsMobileOS' as FsRtlIsMobileOS:qword
;    extrn '__imp_FsRtlKernelFsControlFile' as FsRtlKernelFsControlFile:qword
;    extrn '__imp_FsRtlLegalAnsiCharacterArray' as FsRtlLegalAnsiCharacterArray:qword
;    extrn '__imp_FsRtlLookupLastBaseMcbEntry' as FsRtlLookupLastBaseMcbEntry:qword
;    extrn '__imp_FsRtlLookupReservedPerFileContext' as FsRtlLookupReservedPerFileContext:qword
;    extrn '__imp_FsRtlLookupReservedPerStreamContext' as FsRtlLookupReservedPerStreamContext:qword
;    extrn '__imp_FsRtlNotifyFilterChangeDirectoryLite' as FsRtlNotifyFilterChangeDirectoryLite:qword
;    extrn '__imp_FsRtlNotifyFilterReportChangeLite' as FsRtlNotifyFilterReportChangeLite:qword
;    extrn '__imp_FsRtlNumberOfRunsInBaseMcb' as FsRtlNumberOfRunsInBaseMcb:qword
;    extrn '__imp_FsRtlQueryInformationFile' as FsRtlQueryInformationFile:qword
;    extrn '__imp_FsRtlQueryKernelEaFile' as FsRtlQueryKernelEaFile:qword
;    extrn '__imp_FsRtlRegisterFltMgrCalls' as FsRtlRegisterFltMgrCalls:qword
;    extrn '__imp_FsRtlRegisterMupCalls' as FsRtlRegisterMupCalls:qword
;    extrn '__imp_FsRtlRegisterUncProviderEx2' as FsRtlRegisterUncProviderEx2:qword
;    extrn '__imp_FsRtlReleaseEofLock' as FsRtlReleaseEofLock:qword
;    extrn '__imp_FsRtlReleaseFileNameInformation' as FsRtlReleaseFileNameInformation:qword
;    extrn '__imp_FsRtlReleaseHeaderMutex' as FsRtlReleaseHeaderMutex:qword
;    extrn '__imp_FsRtlRemoveReservedPerFileContext' as FsRtlRemoveReservedPerFileContext:qword
;    extrn '__imp_FsRtlRemoveReservedPerStreamContext' as FsRtlRemoveReservedPerStreamContext:qword
;    extrn '__imp_FsRtlSendModernAppTermination' as FsRtlSendModernAppTermination:qword
;    extrn '__imp_FsRtlSetDriverBacking' as FsRtlSetDriverBacking:qword
;    extrn '__imp_FsRtlSetKernelEaFile' as FsRtlSetKernelEaFile:qword
;    extrn '__imp_FsRtlTryToAcquireHeaderMutex' as FsRtlTryToAcquireHeaderMutex:qword
;    extrn '__imp_FsRtlUpdateDiskCounters' as FsRtlUpdateDiskCounters:qword
;    extrn '__imp_FsRtlValidateReparsePointBuffer' as FsRtlValidateReparsePointBuffer:qword
;    extrn '__imp_HalDispatchTable' as HalDispatchTable:qword
;    extrn '__imp_HalPrivateDispatchTable' as HalPrivateDispatchTable:qword
;    extrn '__imp_HvlGetLpIndexFromApicId' as HvlGetLpIndexFromApicId:qword
;    extrn '__imp_HviGetDebugDeviceOptions' as HviGetDebugDeviceOptions:qword
;    extrn '__imp_HviGetEnlightenmentInformation' as HviGetEnlightenmentInformation:qword
;    extrn '__imp_HviGetHardwareFeatures' as HviGetHardwareFeatures:qword
;    extrn '__imp_HviGetHypervisorFeatures' as HviGetHypervisorFeatures:qword
;    extrn '__imp_HviGetHypervisorInterface' as HviGetHypervisorInterface:qword
;    extrn '__imp_HviGetHypervisorVendorAndMaxFunction' as HviGetHypervisorVendorAndMaxFunction:qword
;    extrn '__imp_HviGetHypervisorVersion' as HviGetHypervisorVersion:qword
;    extrn '__imp_HviGetImplementationLimits' as HviGetImplementationLimits:qword
;    extrn '__imp_HviIsAnyHypervisorPresent' as HviIsAnyHypervisorPresent:qword
;    extrn '__imp_HviIsHypervisorMicrosoftCompatible' as HviIsHypervisorMicrosoftCompatible:qword
;    extrn '__imp_HviIsHypervisorVendorMicrosoft' as HviIsHypervisorVendorMicrosoft:qword
;    extrn '__imp_HviIsIommuInUse' as HviIsIommuInUse:qword
;    extrn '__imp_HvlPerformEndOfInterrupt' as HvlPerformEndOfInterrupt:qword
;    extrn '__imp_HvlQueryActiveHypervisorProcessorCount' as HvlQueryActiveHypervisorProcessorCount:qword
;    extrn '__imp_HvlQueryActiveProcessors' as HvlQueryActiveProcessors:qword
;    extrn '__imp_HvlQueryConnection' as HvlQueryConnection:qword
;    extrn '__imp_HvlQueryHypervisorProcessorNodeNumber' as HvlQueryHypervisorProcessorNodeNumber:qword
;    extrn '__imp_HvlQueryNumaDistance' as HvlQueryNumaDistance:qword
;    extrn '__imp_HvlQueryProcessorTopology' as HvlQueryProcessorTopology:qword
;    extrn '__imp_HvlQueryProcessorTopologyCount' as HvlQueryProcessorTopologyCount:qword
;    extrn '__imp_HvlQueryProcessorTopologyHighestId' as HvlQueryProcessorTopologyHighestId:qword
;    extrn '__imp_HvlReadPerformanceStateCounters' as HvlReadPerformanceStateCounters:qword
;    extrn '__imp_HvlRegisterInterruptCallback' as HvlRegisterInterruptCallback:qword
;    extrn '__imp_HvlRegisterWheaErrorNotification' as HvlRegisterWheaErrorNotification:qword
;    extrn '__imp_HvlUnregisterInterruptCallback' as HvlUnregisterInterruptCallback:qword
;    extrn '__imp_HvlUnregisterWheaErrorNotification' as HvlUnregisterWheaErrorNotification:qword
;    extrn '__imp_InbvNotifyDisplayOwnershipChange' as InbvNotifyDisplayOwnershipChange:qword
;    extrn '__imp_InbvSetVirtualFrameBuffer' as InbvSetVirtualFrameBuffer:qword
;    extrn '__imp_InitSafeBootMode' as InitSafeBootMode:qword
;    extrn '__imp_IoAdapterObjectType' as IoAdapterObjectType:qword
;    extrn '__imp_IoAdjustStackSizeForRedirection' as IoAdjustStackSizeForRedirection:qword
;    extrn '__imp_IoAllocateIrpEx' as IoAllocateIrpEx:qword
;    extrn '__imp_IoApplyPriorityInfoThread' as IoApplyPriorityInfoThread:qword
;    extrn '__imp_IoBoostThreadIo' as IoBoostThreadIo:qword
;    extrn '__imp_IoCallDriverStackSafe' as IoCallDriverStackSafe:qword
;    extrn '__imp_IoClearDependency' as IoClearDependency:qword
;    extrn '__imp_IoClearReservedDependency' as IoClearReservedDependency:qword
;    extrn '__imp_IoCompletionObjectType' as IoCompletionObjectType:qword
;    extrn '__imp_IoConvertFileHandleToKernelHandle' as IoConvertFileHandleToKernelHandle:qword
;    extrn '__imp_IoCopyDeviceObjectHint' as IoCopyDeviceObjectHint:qword
;    extrn '__imp_IoCreateArcName' as IoCreateArcName:qword
;    extrn '__imp_IoDeleteAllDependencyRelations' as IoDeleteAllDependencyRelations:qword
;    extrn '__imp_IoDeviceHandlerObjectSize' as IoDeviceHandlerObjectSize:qword
;    extrn '__imp_IoDeviceHandlerObjectType' as IoDeviceHandlerObjectType:qword
;    extrn '__imp_IoDeviceObjectType' as IoDeviceObjectType:qword
;    extrn '__imp_IoDriverObjectType' as IoDriverObjectType:qword
;    extrn '__imp_IoDuplicateDependency' as IoDuplicateDependency:qword
;    extrn '__imp_IoEnumerateRegisteredFiltersListEx' as IoEnumerateRegisteredFiltersListEx:qword
;    extrn '__imp_IoFileObjectType' as IoFileObjectType:qword
;    extrn '__imp_IoFreeMiniCompletionPacket' as IoFreeMiniCompletionPacket:qword
;    extrn '__imp_IoGetFsTrackOffsetState' as IoGetFsTrackOffsetState:qword
;    extrn '__imp_IoGetFsZeroingOffset' as IoGetFsZeroingOffset:qword
;    extrn '__imp_IoGetGenericIrpExtension' as IoGetGenericIrpExtension:qword
;    extrn '__imp_IoGetSymlinkSupportInformation' as IoGetSymlinkSupportInformation:qword
;    extrn '__imp_IoInitializeMiniCompletionPacket' as IoInitializeMiniCompletionPacket:qword
;    extrn '__imp_IoIsActivityTracingEnabled' as IoIsActivityTracingEnabled:qword
;    extrn '__imp_IoLoadCrashDumpDriver' as IoLoadCrashDumpDriver:qword
;    extrn '__imp_IoMakeAssociatedIrpEx' as IoMakeAssociatedIrpEx:qword
;    extrn '__imp_IoPropagateIrpExtension' as IoPropagateIrpExtension:qword
;    extrn '__imp_IoPropagateIrpExtensionEx' as IoPropagateIrpExtensionEx:qword
;    extrn '__imp_IoQueryInterface' as IoQueryInterface:qword
;    extrn '__imp_IoQueueWorkItemToNode' as IoQueueWorkItemToNode:qword
;    extrn '__imp_IoReadOperationCount' as IoReadOperationCount:qword
;    extrn '__imp_IoReadTransferCount' as IoReadTransferCount:qword
;    extrn '__imp_IoRegisterFsRegistrationChangeMountAwareEx' as IoRegisterFsRegistrationChangeMountAwareEx:qword
;    extrn '__imp_IoRegisterIoTracking' as IoRegisterIoTracking:qword
;    extrn '__imp_IoRegisterPriorityCallback' as IoRegisterPriorityCallback:qword
;    extrn '__imp_IoRequestDeviceEjectEx' as IoRequestDeviceEjectEx:qword
;    extrn '__imp_IoReserveDependency' as IoReserveDependency:qword
;    extrn '__imp_IoResolveDependency' as IoResolveDependency:qword
;    extrn '__imp_IoRetrievePriorityInfo' as IoRetrievePriorityInfo:qword
;    extrn '__imp_IoSetDependency' as IoSetDependency:qword
;    extrn '__imp_IoSetGenericIrpExtension' as IoSetGenericIrpExtension:qword
;    extrn '__imp_IoSetIoCompletionEx' as IoSetIoCompletionEx:qword
;    extrn '__imp_IoSetIoPriorityHintIntoFileObject' as IoSetIoPriorityHintIntoFileObject:qword
;    extrn '__imp_IoSetIoPriorityHintIntoThread' as IoSetIoPriorityHintIntoThread:qword
;    extrn '__imp_IoSizeofGenericIrpExtension' as IoSizeofGenericIrpExtension:qword
;    extrn '__imp_IoStatisticsLock' as IoStatisticsLock:qword
;    extrn '__imp_IoSynchronousCallDriver' as IoSynchronousCallDriver:qword
;    extrn '__imp_IoSteerInterrupt' as IoSteerInterrupt:qword
;    extrn '__imp_IoTestDependency' as IoTestDependency:qword
;    extrn '__imp_IoUnregisterIoTracking' as IoUnregisterIoTracking:qword
;    extrn '__imp_IoVolumeDeviceNameToGuidPath' as IoVolumeDeviceNameToGuidPath:qword
;    extrn '__imp_IoVolumeDeviceToGuidPath' as IoVolumeDeviceToGuidPath:qword
;    extrn '__imp_IoWriteOperationCount' as IoWriteOperationCount:qword
;    extrn '__imp_IoWriteTransferCount' as IoWriteTransferCount:qword
;    extrn '__imp_iswalnum' as iswalnum:qword
;    extrn '__imp_iswdigit' as iswdigit:qword
;    extrn '__imp_iswspace' as iswspace:qword
;    extrn '__imp_KdAcquireDebuggerLock' as KdAcquireDebuggerLock:qword
;    extrn '__imp_KdChangeOption' as KdChangeOption:qword
;    extrn '__imp_KdDebuggerEnabled' as KdDebuggerEnabled:qword
;    extrn '__imp_KdDebuggerNotPresent' as KdDebuggerNotPresent:qword
;    extrn '__imp_KdDeregisterPowerHandler' as KdDeregisterPowerHandler:qword
;    extrn '__imp_KdEnteredDebugger' as KdEnteredDebugger:qword
;    extrn '__imp_KdEventLoggingEnabled' as KdEventLoggingEnabled:qword
;    extrn '__imp_KdGetDebugDevice' as KdGetDebugDevice:qword
;    extrn '__imp_KdRegisterPowerHandler' as KdRegisterPowerHandler:qword
;    extrn '__imp_KdReleaseDebuggerLock' as KdReleaseDebuggerLock:qword
;    extrn '__imp_KdSetEventLoggingPresent' as KdSetEventLoggingPresent:qword
;    extrn '__imp_KeAddGroupAffinityEx' as KeAddGroupAffinityEx:qword
;    extrn '__imp_KeAddProcessorAffinityEx' as KeAddProcessorAffinityEx:qword
;    extrn '__imp_KeAddProcessorGroupAffinity' as KeAddProcessorGroupAffinity:qword
;    extrn '__imp_KeAllocateCalloutStack' as KeAllocateCalloutStack:qword
;    extrn '__imp_KeAllocateCalloutStackEx' as KeAllocateCalloutStackEx:qword
;    extrn '__imp_KeAndGroupAffinityEx' as KeAndGroupAffinityEx:qword
;    extrn '__imp_KeCancelTimer2' as KeCancelTimer2:qword
;    extrn '__imp_KeCheckProcessorAffinityEx' as KeCheckProcessorAffinityEx:qword
;    extrn '__imp_KeCheckProcessorGroupAffinity' as KeCheckProcessorGroupAffinity:qword
;    extrn '__imp_KeClockInterruptNotify' as KeClockInterruptNotify:qword
;    extrn '__imp_KeClockTimerPowerChange' as KeClockTimerPowerChange:qword
;    extrn '__imp_KeConnectInterruptForHal' as KeConnectInterruptForHal:qword
;    extrn '__imp_KeCopyAffinityEx' as KeCopyAffinityEx:qword
;    extrn '__imp_KeCountSetBitsAffinityEx' as KeCountSetBitsAffinityEx:qword
;    extrn '__imp_KeCountSetBitsGroupAffinity' as KeCountSetBitsGroupAffinity:qword
;    extrn '__imp_KeDcacheFlushCount' as KeDcacheFlushCount:qword
;    extrn '__imp_KeDispatchSecondaryInterrupt' as KeDispatchSecondaryInterrupt:qword
;    extrn '__imp_KeEnumerateNextProcessor' as KeEnumerateNextProcessor:qword
;    extrn '__imp_KeFindFirstSetLeftGroupAffinity' as KeFindFirstSetLeftGroupAffinity:qword
;    extrn '__imp_KeFindFirstSetRightAffinityEx' as KeFindFirstSetRightAffinityEx:qword
;    extrn '__imp_KeFindFirstSetRightGroupAffinity' as KeFindFirstSetRightGroupAffinity:qword
;    extrn '__imp_KeFirstGroupAffinityEx' as KeFirstGroupAffinityEx:qword
;    extrn '__imp_KeForceEnableNx' as KeForceEnableNx:qword
;    extrn '__imp_KeFreeCalloutStack' as KeFreeCalloutStack:qword
;    extrn '__imp_KeGetClockOwner' as KeGetClockOwner:qword
;    extrn '__imp_KeGetClockTimerResolution' as KeGetClockTimerResolution:qword
;    extrn '__imp_KeGetEffectiveIrql' as KeGetEffectiveIrql:qword
;    extrn '__imp_KeGetNextClockTickDuration' as KeGetNextClockTickDuration:qword
;    extrn '__imp_KeGetNextTimerExpirationDueTime' as KeGetNextTimerExpirationDueTime:qword
;    extrn '__imp_KeGetXSaveFeatureFlags' as KeGetXSaveFeatureFlags:qword
;    extrn '__imp_KeHwPolicyLocateResource' as KeHwPolicyLocateResource:qword
;    extrn '__imp_KeI386Call16BitCStyleFunction' as KeI386Call16BitCStyleFunction:qword
;    extrn '__imp_Kei386EoiHelper' as Kei386EoiHelper:qword
;    extrn '__imp_KeI386MachineType' as KeI386MachineType:qword
;    extrn '__imp_KeIcacheFlushCount' as KeIcacheFlushCount:qword
;    extrn '__imp_KeInitializeAffinityEx' as KeInitializeAffinityEx:qword
;    extrn '__imp_KeInitializeEnumerationContextFromGroup' as KeInitializeEnumerationContextFromGroup:qword
;    extrn '__imp_KeInitializeSecondaryInterruptServices' as KeInitializeSecondaryInterruptServices:qword
;    extrn '__imp_KeInitializeTimer2' as KeInitializeTimer2:qword
;    extrn '__imp_KeInterlockedClearProcessorAffinityEx' as KeInterlockedClearProcessorAffinityEx:qword
;    extrn '__imp_KeIsSingleGroupAffinityEx' as KeIsSingleGroupAffinityEx:qword
;    extrn '__imp_KeLastBranchMSR' as KeLastBranchMSR:qword
;    extrn '__imp_KeLoaderBlock' as KeLoaderBlock:qword :VARARG
;    extrn '__imp_KeLoadMTRR' as KeLoadMTRR:qword
;    extrn '__imp_KeNotifyProcessorFreezeSupported' as KeNotifyProcessorFreezeSupported:qword
;    extrn '__imp_KeNumberProcessors' as KeNumberProcessors:qword
;    extrn '__imp_KeOrAffinityEx' as KeOrAffinityEx:qword
;    extrn '__imp_KeProcessorGroupAffinity' as KeProcessorGroupAffinity:qword
;    extrn '__imp_KeQueryActiveProcessorAffinity' as KeQueryActiveProcessorAffinity:qword
;    extrn '__imp_KeQueryEffectivePriorityThread' as KeQueryEffectivePriorityThread:qword
;    extrn '__imp_KeQueryGroupAffinityEx' as KeQueryGroupAffinityEx:qword
;    extrn '__imp_KeQueryHeteroCpuPolicyThread' as KeQueryHeteroCpuPolicyThread:qword
;    extrn '__imp_KeQueryMultiThreadProcessorSet' as KeQueryMultiThreadProcessorSet:qword
;    extrn '__imp_KeRemoveGroupAffinityEx' as KeRemoveGroupAffinityEx:qword
;    extrn '__imp_KeRemoveProcessorAffinityEx' as KeRemoveProcessorAffinityEx:qword
;    extrn '__imp_KeRemoveProcessorGroupAffinity' as KeRemoveProcessorGroupAffinity:qword
;    extrn '__imp_KeRemoveQueueDpcEx' as KeRemoveQueueDpcEx:qword
;    extrn '__imp_KeReportCacheIncoherentDevice' as KeReportCacheIncoherentDevice:qword
;    extrn '__imp_KeRevertToUserAffinityThread' as KeRevertToUserAffinityThread:qword
;    extrn '__imp_KeServiceDescriptorTable' as KeServiceDescriptorTable:qword
;    extrn '__imp_KeSetActualBasePriorityThread' as KeSetActualBasePriorityThread:qword
;    extrn '__imp_KeSetHeteroCpuPolicyThread' as KeSetHeteroCpuPolicyThread:qword
;    extrn '__imp_KeSetSelectedCpuSetsThread' as KeSetSelectedCpuSetsThread:qword
;    extrn '__imp_KeSetTimer2' as KeSetTimer2:qword
;    extrn '__imp_KeSignalCallDpcDone' as KeSignalCallDpcDone:qword
;    extrn '__imp_KeSignalCallDpcSynchronize' as KeSignalCallDpcSynchronize:qword
;    extrn '__imp_KeStallWhileFrozen' as KeStallWhileFrozen:qword
;    extrn '__imp_KeStartDynamicProcessor' as KeStartDynamicProcessor:qword
;    extrn '__imp_KeSubtractAffinityEx' as KeSubtractAffinityEx:qword
;    extrn '__imp_KeSweepLocalCaches' as KeSweepLocalCaches:qword
;    extrn '__imp_KeSynchronizeTimeToQpc' as KeSynchronizeTimeToQpc:qword
;    extrn '__imp_KeSystemFullyCacheCoherent' as KeSystemFullyCacheCoherent:qword
;    extrn '__imp_KeTickCount' as KeTickCount:qword
;    extrn '__imp_KeUpdateSystemTime' as KeUpdateSystemTime:qword
;    extrn '__imp_KeUpdateTime' as KeUpdateTime:qword
;    extrn '__imp_KeUpdateThreadTag' as KeUpdateThreadTag:qword
;    extrn '__imp_KeUpdateTimeAssist' as KeUpdateTimeAssist:qword
;    extrn '__imp_KeWriteProtectPAT' as KeWriteProtectPAT:qword
;    extrn '__imp_KfRaiseIrql' as KfRaiseIrql:qword
;    extrn '__imp_KiBugCheckData' as KiBugCheckData:qword
;    extrn '__imp_KiCheckForSListAddress' as KiCheckForSListAddress:qword
;    extrn '__imp_KiCpuId' as KiCpuId:qword
;    extrn '__imp_KiDispatchInterrupt' as KiDispatchInterrupt:qword
;    extrn '__imp_KiEnableTimerWatchdog' as KiEnableTimerWatchdog:qword
;    extrn '__imp_KitLogFeatureUsage' as KitLogFeatureUsage:qword
;    extrn '__imp_KiUnexpectedInterrupt' as KiUnexpectedInterrupt:qword
;    extrn '__imp_KseQueryDeviceData' as KseQueryDeviceData:qword
;    extrn '__imp_KseQueryDeviceDataList' as KseQueryDeviceDataList:qword
;    extrn '__imp_KseQueryDeviceFlags' as KseQueryDeviceFlags:qword
;    extrn '__imp_KseRegisterShim' as KseRegisterShim:qword
;    extrn '__imp_KseRegisterShimEx' as KseRegisterShimEx:qword
;    extrn '__imp_KseSetDeviceFlags' as KseSetDeviceFlags:qword
;    extrn '__imp_KseUnregisterShim' as KseUnregisterShim:qword
;    extrn '__imp_LdrFindResourceEx_U' as LdrFindResourceEx_U:qword
;    extrn '__imp_LdrResFindResource' as LdrResFindResource:qword
;    extrn '__imp_LdrResFindResourceDirectory' as LdrResFindResourceDirectory:qword
;    extrn '__imp_LdrResSearchResource' as LdrResSearchResource:qword
;    extrn '__imp_LpcPortObjectType' as LpcPortObjectType:qword
;    extrn '__imp_LpcReplyWaitReplyPort' as LpcReplyWaitReplyPort:qword
;    extrn '__imp_LpcSendWaitReceivePort' as LpcSendWaitReceivePort:qword
;    extrn '__imp_Mm64BitPhysicalAddress' as Mm64BitPhysicalAddress:qword
;    extrn '__imp_MmAddVerifierSpecialThunks' as MmAddVerifierSpecialThunks:qword
;    extrn '__imp_MmAreMdlPagesCached' as MmAreMdlPagesCached:qword
;    extrn '__imp_MmBadPointer' as MmBadPointer:qword
;    extrn '__imp_MmChangeImageProtection' as MmChangeImageProtection:qword
;    extrn '__imp_MmGetCacheAttribute' as MmGetCacheAttribute:qword
;    extrn '__imp_MmHighestUserAddress' as MmHighestUserAddress:qword
;    extrn '__imp_MmMapViewInSessionSpaceEx' as MmMapViewInSessionSpaceEx:qword
;    extrn '__imp_MmMapViewInSystemSpaceEx' as MmMapViewInSystemSpaceEx:qword
;    extrn '__imp_MmMdlPageContentsState' as MmMdlPageContentsState:qword
;    extrn '__imp_MmPrefetchVirtualAddresses' as MmPrefetchVirtualAddresses:qword
;    extrn '__imp_MmSectionObjectType' as MmSectionObjectType:qword
;    extrn '__imp_MmSetUserExceptionCallout' as MmSetUserExceptionCallout:qword
;    extrn '__imp_MmSystemRangeStart' as MmSystemRangeStart:qword
;    extrn '__imp_MmUserProbeAddress' as MmUserProbeAddress:qword
;    extrn '__imp_NlsAnsiCodePage' as NlsAnsiCodePage:qword
;    extrn '__imp_NlsLeadByteInfo' as NlsLeadByteInfo:qword
;    extrn '__imp_NlsMbCodePageTag' as NlsMbCodePageTag:qword
;    extrn '__imp_NlsMbOemCodePageTag' as NlsMbOemCodePageTag:qword
;    extrn '__imp_NlsOemCodePage' as NlsOemCodePage:qword
;    extrn '__imp_NtBuildGUID' as NtBuildGUID:qword
;    extrn '__imp_NtBuildLab' as NtBuildLab:qword
;    extrn '__imp_NtBuildNumber' as NtBuildNumber:qword
;    extrn '__imp_NtGetEnvironmentVariableEx' as NtGetEnvironmentVariableEx:qword
;    extrn '__imp_NtGlobalFlag' as NtGlobalFlag:qword
;    extrn '__imp_NtQueryEnvironmentVariableInfoEx' as NtQueryEnvironmentVariableInfoEx:qword
;    extrn '__imp_NtSetCachedSigningLevel' as NtSetCachedSigningLevel:qword
;    extrn '__imp_NtSetInformationVirtualMemory' as NtSetInformationVirtualMemory:qword
;    extrn '__imp_ObfDereferenceObjectWithTag' as ObfDereferenceObjectWithTag:qword
;    extrn '__imp_ObGetObjectType' as ObGetObjectType:qword
;    extrn '__imp_ObOpenObjectByNameEx' as ObOpenObjectByNameEx:qword
;    extrn '__imp_ObReferenceObjectSafeWithTag' as ObReferenceObjectSafeWithTag:qword
;    extrn '__imp_ObWaitForMultipleObjects' as ObWaitForMultipleObjects:qword
;    extrn '__imp_PfFileInfoNotify' as PfFileInfoNotify:qword
;    extrn '__imp_PoAllProcessorsDeepIdle' as PoAllProcessorsDeepIdle:qword
;    extrn '__imp_PoCpuIdledSinceLastCallImprecise' as PoCpuIdledSinceLastCallImprecise:qword
;    extrn '__imp_PoDisableSleepStates' as PoDisableSleepStates:qword
;    extrn '__imp_PoFxProcessorNotification' as PoFxProcessorNotification:qword
;    extrn '__imp_PoEnergyEstimationEnabled' as PoEnergyEstimationEnabled:qword
;    extrn '__imp_PoFxEnableDStateReporting' as PoFxEnableDStateReporting:qword
;    extrn '__imp_PoFxRegisterCoreDevice' as PoFxRegisterCoreDevice:qword
;    extrn '__imp_PoFxRegisterPlugin' as PoFxRegisterPlugin:qword
;    extrn '__imp_PoFxRegisterPluginEx' as PoFxRegisterPluginEx:qword
;    extrn '__imp_PoFxRegisterPrimaryDevice' as PoFxRegisterPrimaryDevice:qword
;    extrn '__imp_PoGetProcessorIdleAccounting' as PoGetProcessorIdleAccounting:qword
;    extrn '__imp_POGOBuffer' as POGOBuffer:qword
;    extrn '__imp_PoInitiateProcessorWake' as PoInitiateProcessorWake:qword
;    extrn '__imp_PoLatencySensitivityHint' as PoLatencySensitivityHint:qword
;    extrn '__imp_PoNotifyDisableDynamicTick' as PoNotifyDisableDynamicTick:qword
;    extrn '__imp_PoNotifyMediaBuffering' as PoNotifyMediaBuffering:qword
;    extrn '__imp_PoNotifyVSyncChange' as PoNotifyVSyncChange:qword
;    extrn '__imp_PoQueueShutdownWorkItem' as PoQueueShutdownWorkItem:qword
;    extrn '__imp_PoReenableSleepStates' as PoReenableSleepStates:qword
;    extrn '__imp_PoRegisterCoalescingCallback' as PoRegisterCoalescingCallback:qword
;    extrn '__imp_PoSetFixedWakeSource' as PoSetFixedWakeSource:qword
;    extrn '__imp_PoSetUserPresent' as PoSetUserPresent:qword
;    extrn '__imp_PoSetSystemWakeDevice' as PoSetSystemWakeDevice:qword
;    extrn '__imp_PoUnregisterCoalescingCallback' as PoUnregisterCoalescingCallback:qword
;    extrn '__imp_PoUserShutdownCancelled' as PoUserShutdownCancelled:qword
;    extrn '__imp_PoUserShutdownInitiated' as PoUserShutdownInitiated:qword
;    extrn '__imp_PsChargeProcessCpuCycles' as PsChargeProcessCpuCycles:qword
;    extrn '__imp_PsChargeProcessWakeCounter' as PsChargeProcessWakeCounter:qword
;    extrn '__imp_PsDereferenceKernelStack' as PsDereferenceKernelStack:qword
;    extrn '__imp_PsEnterPriorityRegion' as PsEnterPriorityRegion:qword
;    extrn '__imp_PsGetCurrentProcessWow64Process' as PsGetCurrentProcessWow64Process:qword
;    extrn '__imp_PsGetCurrentThreadWin32ThreadAndEnterCriticalRegion' as PsGetCurrentThreadWin32ThreadAndEnterCriticalRegion:qword
;    extrn '__imp_PsGetEffectiveContainerId' as PsGetEffectiveContainerId:qword
;    extrn '__imp_PsGetJobProperty' as PsGetJobProperty:qword
;    extrn '__imp_PsGetProcessCommonJob' as PsGetProcessCommonJob:qword
;    extrn '__imp_PsGetProcessProtection' as PsGetProcessProtection:qword
;    extrn '__imp_PsGetProcessServerSilo' as PsGetProcessServerSilo:qword
;    extrn '__imp_PsGetProcessSessionIdEx' as PsGetProcessSessionIdEx:qword
;    extrn '__imp_PsGetProcessSignatureLevel' as PsGetProcessSignatureLevel:qword
;    extrn '__imp_PsGetSiloIdentifier' as PsGetSiloIdentifier:qword
;    extrn '__imp_PsInitialSystemProcess' as PsInitialSystemProcess:qword
;    extrn '__imp_PsIsProcessInAppSilo' as PsIsProcessInAppSilo:qword
;    extrn '__imp_PsIsProtectedProcess' as PsIsProtectedProcess:qword
;    extrn '__imp_PsIsProtectedProcessLight' as PsIsProtectedProcessLight:qword
;    extrn '__imp_PsJobType' as PsJobType:qword
;    extrn '__imp_PsLeavePriorityRegion' as PsLeavePriorityRegion:qword
;    extrn '__imp_psMUITest' as psMUITest:qword
;    extrn '__imp_PsLoadedModuleList' as PsLoadedModuleList:qword
;    extrn '__imp_PsLoadedModuleResource' as PsLoadedModuleResource:qword
;    extrn '__imp_PsUpdateComponentPower' as PsUpdateComponentPower:qword
;    extrn '__imp_PsQueryProcessAttributesByToken' as PsQueryProcessAttributesByToken:qword
;    extrn '__imp_PsQueryProcessExceptionFlags' as PsQueryProcessExceptionFlags:qword
;    extrn '__imp_PsReferenceKernelStack' as PsReferenceKernelStack:qword
;    extrn '__imp_PsReleaseProcessExitSynchronization' as PsReleaseProcessExitSynchronization:qword
;    extrn '__imp_PsReleaseProcessWakeCounter' as PsReleaseProcessWakeCounter:qword
;    extrn '__imp_PsSetCreateProcessNotifyRoutineEx2' as PsSetCreateProcessNotifyRoutineEx2:qword
;    extrn '__imp_PsSetJobProperty' as PsSetJobProperty:qword
;    extrn '__imp_PsSetThreadProperty' as PsSetThreadProperty:qword
;    extrn '__imp_PsUILanguageComitted' as PsUILanguageComitted:qword
;    extrn '__imp_RtlAddAccessAllowedObjectAce' as RtlAddAccessAllowedObjectAce:qword
;    extrn '__imp_RtlAddAtomToAtomTableEx' as RtlAddAtomToAtomTableEx:qword
;    extrn '__imp_RtlAddProcessTrustLabelAce' as RtlAddProcessTrustLabelAce:qword
;    extrn '__imp_RtlAddResourceAttributeAce' as RtlAddResourceAttributeAce:qword
;    extrn '__imp_RtlAreBitsClearEx' as RtlAreBitsClearEx:qword
;    extrn '__imp_RtlAreBitsSetEx' as RtlAreBitsSetEx:qword
;    extrn '__imp_RtlAvlInsertNodeEx' as RtlAvlInsertNodeEx:qword
;    extrn '__imp_RtlAvlRemoveNode' as RtlAvlRemoveNode:qword
;    extrn '__imp_RtlCapabilityCheck' as RtlCapabilityCheck:qword
;    extrn '__imp_RtlCheckTokenCapability' as RtlCheckTokenCapability:qword
;    extrn '__imp_RtlCheckTokenMembership' as RtlCheckTokenMembership:qword
;    extrn '__imp_RtlCheckTokenMembershipEx' as RtlCheckTokenMembershipEx:qword
;    extrn '__imp_RtlClearAllBitsEx' as RtlClearAllBitsEx:qword
;    extrn '__imp_RtlClearBitEx' as RtlClearBitEx:qword
;    extrn '__imp_RtlClearBitsEx' as RtlClearBitsEx:qword
;    extrn '__imp_RtlContractHashTable' as RtlContractHashTable:qword
;    extrn '__imp_RtlCopyBitMap' as RtlCopyBitMap:qword
;    extrn '__imp_RtlCopyMemoryNonTemporal' as RtlCopyMemoryNonTemporal:qword
;    extrn '__imp_RtlCrc32' as RtlCrc32:qword
;    extrn '__imp_RtlCrc64' as RtlCrc64:qword
;    extrn '__imp_RtlCreateAtomTableEx' as RtlCreateAtomTableEx:qword
;    extrn '__imp_RtlCreateHashTable' as RtlCreateHashTable:qword
;    extrn '__imp_RtlCreateHashTableEx' as RtlCreateHashTableEx:qword
;    extrn '__imp_RtlDeleteHashTable' as RtlDeleteHashTable:qword
;    extrn '__imp_RtlEndEnumerationHashTable' as RtlEndEnumerationHashTable:qword
;    extrn '__imp_RtlEndWeakEnumerationHashTable' as RtlEndWeakEnumerationHashTable:qword
;    extrn '__imp_RtlEnumerateEntryHashTable' as RtlEnumerateEntryHashTable:qword
;    extrn '__imp_RtlEqualWnfChangeStamps' as RtlEqualWnfChangeStamps:qword
;    extrn '__imp_RtlExpandHashTable' as RtlExpandHashTable:qword
;    extrn '__imp_RtlExtractBitMap' as RtlExtractBitMap:qword
;    extrn '__imp_RtlFindAceByType' as RtlFindAceByType:qword
;    extrn '__imp_RtlFindClearBitsAndSetEx' as RtlFindClearBitsAndSetEx:qword
;    extrn '__imp_RtlFindClearBitsEx' as RtlFindClearBitsEx:qword
;    extrn '__imp_RtlFindClosestEncodableLength' as RtlFindClosestEncodableLength:qword
;    extrn '__imp_RtlFindExportedRoutineByName' as RtlFindExportedRoutineByName:qword
;    extrn '__imp_RtlFindNextForwardRunClearEx' as RtlFindNextForwardRunClearEx:qword
;    extrn '__imp_RtlFindSetBitsAndClearEx' as RtlFindSetBitsAndClearEx:qword
;    extrn '__imp_RtlFindSetBitsEx' as RtlFindSetBitsEx:qword
;    extrn '__imp_RtlGenerateClass5Guid' as RtlGenerateClass5Guid:qword
;    extrn '__imp_RtlGetAppContainerNamedObjectPath' as RtlGetAppContainerNamedObjectPath:qword
;    extrn '__imp_RtlGetAppContainerParent' as RtlGetAppContainerParent:qword
;    extrn '__imp_RtlGetAppContainerSidType' as RtlGetAppContainerSidType:qword
;    extrn '__imp_RtlGetIntegerAtom' as RtlGetIntegerAtom:qword
;    extrn '__imp_RtlGetLastRange' as RtlGetLastRange:qword
;    extrn '__imp_RtlGetProductInfo' as RtlGetProductInfo:qword
;    extrn '__imp_RtlIdnToAscii' as RtlIdnToAscii:qword
;    extrn '__imp_RtlIdnToNameprepUnicode' as RtlIdnToNameprepUnicode:qword
;    extrn '__imp_RtlIdnToUnicode' as RtlIdnToUnicode:qword
;    extrn '__imp_RtlImageNtHeaderEx' as RtlImageNtHeaderEx:qword
;    extrn '__imp_RtlInitializeBitMapEx' as RtlInitializeBitMapEx:qword
;    extrn '__imp_RtlInterlockedClearBitRun' as RtlInterlockedClearBitRun:qword
;    extrn '__imp_RtlInterlockedSetBitRun' as RtlInterlockedSetBitRun:qword
;    extrn '__imp_RtlInterlockedSetClearRun' as RtlInterlockedSetClearRun:qword
;    extrn '__imp_RtlInvertRangeListEx' as RtlInvertRangeListEx:qword
;    extrn '__imp_RtlIsMultiSessionSku' as RtlIsMultiSessionSku:qword
;    extrn '__imp_RtlIsSandboxedToken' as RtlIsSandboxedToken:qword
;    extrn '__imp_RtlIsUntrustedObject' as RtlIsUntrustedObject:qword
;    extrn '__imp_RtlLCIDToCultureName' as RtlLCIDToCultureName:qword
;    extrn '__imp_RtlLoadString' as RtlLoadString:qword
;    extrn '__imp_RtlNormalizeString' as RtlNormalizeString:qword
;    extrn '__imp_RtlNumberOfClearBitsEx' as RtlNumberOfClearBitsEx:qword
;    extrn '__imp_RtlNumberOfClearBitsInRange' as RtlNumberOfClearBitsInRange:qword
;    extrn '__imp_RtlNumberOfSetBitsEx' as RtlNumberOfSetBitsEx:qword
;    extrn '__imp_RtlNumberOfSetBitsInRange' as RtlNumberOfSetBitsInRange:qword
;    extrn '__imp_RtlOwnerAcesPresent' as RtlOwnerAcesPresent:qword
;    extrn '__imp_RtlQueryDynamicTimeZoneInformation' as RtlQueryDynamicTimeZoneInformation:qword
;    extrn '__imp_RtlQueryModuleInformation' as RtlQueryModuleInformation:qword
;    extrn '__imp_RtlQueryPackageClaims' as RtlQueryPackageClaims:qword
;    extrn '__imp_RtlQueryPackageIdentity' as RtlQueryPackageIdentity:qword
;    extrn '__imp_RtlQueryRegistryValuesEx' as RtlQueryRegistryValuesEx:qword
;    extrn '__imp_RtlQueryValidationRunlevel' as RtlQueryValidationRunlevel:qword
;    extrn '__imp_RtlRbReplaceNode' as RtlRbReplaceNode:qword
;    extrn '__imp_RtlRemoveEntryHashTable' as RtlRemoveEntryHashTable:qword
;    extrn '__imp_RtlReplaceSidInSd' as RtlReplaceSidInSd:qword
;    extrn '__imp_RtlSetAllBitsEx' as RtlSetAllBitsEx:qword
;    extrn '__imp_RtlSetBitEx' as RtlSetBitEx:qword
;    extrn '__imp_RtlSetBitsEx' as RtlSetBitsEx:qword
;    extrn '__imp_RtlSetDynamicTimeZoneInformation' as RtlSetDynamicTimeZoneInformation:qword
;    extrn '__imp_RtlSetPortableOperatingSystem' as RtlSetPortableOperatingSystem:qword
;    extrn '__imp_RtlSidHashInitialize' as RtlSidHashInitialize:qword
;    extrn '__imp_RtlSidHashLookup' as RtlSidHashLookup:qword
;    extrn '__imp_RtlTestBitEx' as RtlTestBitEx:qword
;    extrn '__imp_RtlWeaklyEnumerateEntryHashTable' as RtlWeaklyEnumerateEntryHashTable:qword
;    extrn '__imp_SeAccessCheckFromState' as SeAccessCheckFromState:qword
;    extrn '__imp_SeAccessCheckFromStateEx' as SeAccessCheckFromStateEx:qword
;    extrn '__imp_SeAccessCheckWithHint' as SeAccessCheckWithHint:qword
;    extrn '__imp_SeAuditingAnyFileEventsWithContextEx' as SeAuditingAnyFileEventsWithContextEx:qword
;    extrn '__imp_SeAuditingFileEventsWithContextEx' as SeAuditingFileEventsWithContextEx:qword
;    extrn '__imp_SeAuditingWithTokenForSubcategory' as SeAuditingWithTokenForSubcategory:qword
;    extrn '__imp_SeCloseObjectAuditAlarmForNonObObject' as SeCloseObjectAuditAlarmForNonObObject:qword
;    extrn '__imp_SeCompareSigningLevels' as SeCompareSigningLevels:qword
;    extrn '__imp_SeCreateClientSecurityEx' as SeCreateClientSecurityEx:qword
;    extrn '__imp_SeCreateClientSecurityFromSubjectContextEx' as SeCreateClientSecurityFromSubjectContextEx:qword
;    extrn '__imp_SeExports' as SeExports:qword
;    extrn '__imp_SeGetCachedSigningLevel' as SeGetCachedSigningLevel:qword
;    extrn '__imp_SeGetLinkedToken' as SeGetLinkedToken:qword
;    extrn '__imp_SeGetLogonSessionToken' as SeGetLogonSessionToken:qword
;    extrn '__imp_SeIsParentOfChildAppContainer' as SeIsParentOfChildAppContainer:qword
;    extrn '__imp_SeOpenObjectAuditAlarmForNonObObject' as SeOpenObjectAuditAlarmForNonObObject:qword
;    extrn '__imp_SeOpenObjectAuditAlarmWithTransaction' as SeOpenObjectAuditAlarmWithTransaction:qword
;    extrn '__imp_SePublicDefaultDacl' as SePublicDefaultDacl:qword
;    extrn '__imp_SeQuerySecureBootPolicyValue' as SeQuerySecureBootPolicyValue:qword
;    extrn '__imp_SeQuerySecurityAttributesToken' as SeQuerySecurityAttributesToken:qword
;    extrn '__imp_SeRegisterImageVerificationCallback' as SeRegisterImageVerificationCallback:qword
;    extrn '__imp_SeSecurityAttributePresent' as SeSecurityAttributePresent:qword
;    extrn '__imp_SeSetAuthorizationCallbacks' as SeSetAuthorizationCallbacks:qword
;    extrn '__imp_SeSetSecurityAttributesToken' as SeSetSecurityAttributesToken:qword
;    extrn '__imp_SeSetSecurityAttributesTokenEx' as SeSetSecurityAttributesTokenEx:qword
;    extrn '__imp_SeSrpAccessCheck' as SeSrpAccessCheck:qword
;    extrn '__imp_SeSystemDefaultDacl' as SeSystemDefaultDacl:qword
;    extrn '__imp_SeSystemDefaultSd' as SeSystemDefaultSd:qword
;    extrn '__imp_SeTokenFromAccessInformation' as SeTokenFromAccessInformation:qword
;    extrn '__imp_SeUnregisterImageVerificationCallback' as SeUnregisterImageVerificationCallback:qword
;    extrn '__imp_SkAcquirePushLockExclusive' as SkAcquirePushLockExclusive:qword
;    extrn '__imp_SkAllocatePool' as SkAllocatePool:qword
;    extrn '__imp_SkFreePool' as SkFreePool:qword
;    extrn '__imp_SkInitializePushLock' as SkInitializePushLock:qword
;    extrn '__imp_SkIsSecureKernel' as SkIsSecureKernel:qword
;    extrn '__imp_SkQuerySecureKernelInformation' as SkQuerySecureKernelInformation:qword
;    extrn '__imp_SkReleasePushLockExclusive' as SkReleasePushLockExclusive:qword
;    extrn '__imp_sprintf' as sprintf:qword
;    extrn '__imp_sprintf_s' as sprintf_s:qword
;    extrn '__imp_sqrt' as sqrt:qword
;    extrn '__imp_sqrtf' as sqrtf:qword
;    extrn '__imp_srand' as srand:qword
;    extrn '__imp_sscanf_s' as sscanf_s:qword
;    extrn '__imp_strcat' as strcat:qword
;    extrn '__imp_strcat_s' as strcat_s:qword
;    extrn '__imp_strchr' as strchr:qword
;    extrn '__imp_strcmp' as strcmp:qword
;    extrn '__imp_strcpy' as strcpy:qword
;    extrn '__imp_strcpy_s' as strcpy_s:qword
;    extrn '__imp_strlen' as strlen:qword
;    extrn '__imp_strncat' as strncat:qword
;    extrn '__imp_strncat_s' as strncat_s:qword
;    extrn '__imp_strncmp' as strncmp:qword
;    extrn '__imp_strncpy' as strncpy:qword
;    extrn '__imp_strncpy_s' as strncpy_s:qword
;    extrn '__imp_strnlen' as strnlen:qword
;    extrn '__imp_strrchr' as strrchr:qword
;    extrn '__imp_strspn' as strspn:qword
;    extrn '__imp_strstr' as strstr:qword
;    extrn '__imp_strtok_s' as strtok_s:qword
;    extrn '__imp_swprintf' as swprintf:qword
;    extrn '__imp_swprintf_s' as swprintf_s:qword
;    extrn '__imp_swscanf_s' as swscanf_s:qword
;    extrn '__imp_TmCancelPropagationRequest' as TmCancelPropagationRequest:qword
;    extrn '__imp_TmCurrentTransaction' as TmCurrentTransaction:qword
;    extrn '__imp_TmEndPropagationRequest' as TmEndPropagationRequest:qword
;    extrn '__imp_TmEnlistmentObjectType' as TmEnlistmentObjectType:qword
;    extrn '__imp_TmFreezeTransactions' as TmFreezeTransactions:qword
;    extrn '__imp_TmInitializeResourceManager' as TmInitializeResourceManager:qword
;    extrn '__imp_TmInitializeTransaction' as TmInitializeTransaction:qword
;    extrn '__imp_TmInitSystem' as TmInitSystem:qword
;    extrn '__imp_TmInitSystemPhase2' as TmInitSystemPhase2:qword
;    extrn '__imp_TmIsKTMCommitCoordinator' as TmIsKTMCommitCoordinator:qword
;    extrn '__imp_TmpIsKTMCommitCoordinator' as TmpIsKTMCommitCoordinator:qword
;    extrn '__imp_TmPropagationComplete' as TmPropagationComplete:qword
;    extrn '__imp_TmPropagationFailed' as TmPropagationFailed:qword
;    extrn '__imp_TmResourceManagerObjectType' as TmResourceManagerObjectType:qword
;    extrn '__imp_TmSetCurrentTransaction' as TmSetCurrentTransaction:qword
;    extrn '__imp_TmThawTransactions' as TmThawTransactions:qword
;    extrn '__imp_TmTransactionManagerObjectType' as TmTransactionManagerObjectType:qword
;    extrn '__imp_TmTransactionObjectType' as TmTransactionObjectType:qword
;    extrn '__imp_VfCheckNxPagePriority' as VfCheckNxPagePriority:qword
;    extrn '__imp_VfCheckNxPageProtection' as VfCheckNxPageProtection:qword
;    extrn '__imp_VfCheckNxPoolType' as VfCheckNxPoolType:qword
;    extrn '__imp_VfFailDeviceNode' as VfFailDeviceNode:qword
;    extrn '__imp_VfFailDriver' as VfFailDriver:qword
;    extrn '__imp_VfFailSystemBIOS' as VfFailSystemBIOS:qword
;    extrn '__imp_VfInsertContext' as VfInsertContext:qword
;    extrn '__imp_VfQueryDeviceContext' as VfQueryDeviceContext:qword
;    extrn '__imp_VfQueryDispatchTable' as VfQueryDispatchTable:qword
;    extrn '__imp_VfQueryDriverContext' as VfQueryDriverContext:qword
;    extrn '__imp_VfQueryIrpContext' as VfQueryIrpContext:qword
;    extrn '__imp_VfQueryThreadContext' as VfQueryThreadContext:qword
;    extrn '__imp_VfRemoveContext' as VfRemoveContext:qword
;    extrn '__imp_VmAccessFault' as VmAccessFault:qword
;    extrn '__imp_VmCreateMemoryRange' as VmCreateMemoryRange:qword
;    extrn '__imp_VmDeleteMemoryRange' as VmDeleteMemoryRange:qword
;    extrn '__imp_VslExchangeEntropy' as VslExchangeEntropy:qword
;    extrn '__imp_VslRetrieveMailbox' as VslRetrieveMailbox:qword
;    extrn '__imp_WheaAttemptPhysicalPageOffline' as WheaAttemptPhysicalPageOffline:qword
;    extrn '__imp_WheaConfigureErrorSource' as WheaConfigureErrorSource:qword
;    extrn '__imp_WheaDeferredRecoveryService' as WheaDeferredRecoveryService:qword
;    extrn '__imp_WheaGetErrorSource' as WheaGetErrorSource:qword
;    extrn '__imp_WheaInitializeDeferredRecoveryObject' as WheaInitializeDeferredRecoveryObject:qword
;    extrn '__imp_WheaInitializeRecordHeader' as WheaInitializeRecordHeader:qword
;    extrn '__imp_WheaRegisterErrSrcInitializer' as WheaRegisterErrSrcInitializer:qword
;    extrn '__imp_WheaReportHwError' as WheaReportHwError:qword
;    extrn '__imp_WheaRequestDeferredRecovery' as WheaRequestDeferredRecovery:qword
;    extrn '__imp_ZwAlpcConnectPortEx' as ZwAlpcConnectPortEx:qword
;    extrn '__imp_ZwCreateWnfStateName' as ZwCreateWnfStateName:qword
;    extrn '__imp_ZwDeleteDriverEntry' as ZwDeleteDriverEntry:qword
;    extrn '__imp_ZwDeleteWnfStateData' as ZwDeleteWnfStateData:qword
;    extrn '__imp_ZwDeleteWnfStateName' as ZwDeleteWnfStateName:qword
;    extrn '__imp_ZwNotifyChangeSession' as ZwNotifyChangeSession:qword
;    extrn '__imp_ZwQueryLicenseValue' as ZwQueryLicenseValue:qword
;    extrn '__imp_ZwQueryWnfStateData' as ZwQueryWnfStateData:qword
;    extrn '__imp_ZwQueryWnfStateNameInformation' as ZwQueryWnfStateNameInformation:qword
;    extrn '__imp_ZwSetCachedSigningLevel' as ZwSetCachedSigningLevel:qword
;    extrn '__imp_ZwSetInformationVirtualMemory' as ZwSetInformationVirtualMemory:qword
;    extrn '__imp_ZwUpdateWnfStateData' as ZwUpdateWnfStateData:qword
;    extrn '__imp__abnormal_termination' as _abnormal_termination:qword
;    extrn '__imp__alloca_probe' as _alloca_probe:qword
;    extrn '__imp__alloca_probe_16' as _alloca_probe_16:qword
;    extrn '__imp__alloca_probe_8' as _alloca_probe_8:qword
;    extrn '__imp__CIcos' as _CIcos:qword
;    extrn '__imp__CIsin' as _CIsin:qword
;    extrn '__imp__CIsqrt' as _CIsqrt:qword
;    extrn '__imp__local_unwind' as local_unwind:qword
;    if ~defined __imp___misaligned_access
;        extrn '__imp___misaligned_access' as misaligned_access:qword
;    end if
;    extrn '__imp__snscanf_s' as _snscanf_s:qword
;    extrn '__imp__snwprintf' as _snwprintf:qword
;    extrn '__imp__snwprintf_s' as _snwprintf_s:qword
;    extrn '__imp__snwscanf_s' as _snwscanf_s:qword
;else
;    extrn '__imp__BgkDisplayCharacter@??' as BgkDisplayCharacter:dword
;    extrn '__imp__BgkGetConsoleState@??' as BgkGetConsoleState:dword
;    extrn '__imp__BgkGetCursorState@??' as BgkGetCursorState:dword
;    extrn '__imp__BgkSetCursor@??' as BgkSetCursor:dword
;    extrn '__imp__CcAddDirtyPagesToExternalCache@??' as CcAddDirtyPagesToExternalCache:dword
;    extrn '__imp__CcDeductDirtyPagesFromExternalCache@??' as CcDeductDirtyPagesFromExternalCache:dword
;    extrn '__imp__CcFlushCacheToLsn@??' as CcFlushCacheToLsn:dword
;    extrn '__imp__CcRegisterExternalCache@??' as CcRegisterExternalCache:dword
;    extrn '__imp__CcTestControl@??' as CcTestControl:dword
;    extrn '__imp__CcUnregisterExternalCache@??' as CcUnregisterExternalCache:dword
;    extrn '__imp__CcZeroDataOnDisk@??' as CcZeroDataOnDisk:dword
;    extrn '__imp__CmKeyObjectType@??' as CmKeyObjectType:dword
;    extrn '__imp__DbgkLkmdRegisterCallback@??' as DbgkLkmdRegisterCallback:dword
;    extrn '__imp__DbgkLkmdUnregisterCallback@??' as DbgkLkmdUnregisterCallback:dword
;    extrn '__imp__DbgkWerCaptureLiveKernelDump@??' as DbgkWerCaptureLiveKernelDump:dword
;    extrn '__imp__EmClientRuleDeregisterNotification@??' as EmClientRuleDeregisterNotification:dword
;    extrn '__imp__EmClientRuleEvaluate@??' as EmClientRuleEvaluate:dword
;    extrn '__imp__EmClientRuleRegisterNotification@??' as EmClientRuleRegisterNotification:dword
;    extrn '__imp__EmpProviderRegister@??' as EmpProviderRegister:dword
;    extrn '__imp__EmProviderDeregister@??' as EmProviderDeregister:dword
;    extrn '__imp__EmProviderDeregisterEntry@??' as EmProviderDeregisterEntry:dword
;    extrn '__imp__EmProviderRegister@??' as EmProviderRegister:dword
;    extrn '__imp__EmProviderRegisterEntry@??' as EmProviderRegisterEntry:dword
;    extrn '__imp__EtwEnableTrace@??' as EtwEnableTrace:dword
;    extrn '__imp__EtwRegisterClassicProvider@??' as EtwRegisterClassicProvider:dword
;    extrn '__imp__EtwSendTraceBuffer@??' as EtwSendTraceBuffer:dword
;    extrn '__imp__EtwSetInformation@??' as EtwSetInformation:dword
;    extrn '__imp__EtwWriteEndScenario@??' as EtwWriteEndScenario:dword
;    extrn '__imp__CcFastReadNotPossible@??' as CcFastReadNotPossible:dword
;    extrn '__imp__EtwWriteStartScenario@??' as EtwWriteStartScenario:dword
;    extrn '__imp__ExAcquireAutoExpandPushLockExclusive@??' as ExAcquireAutoExpandPushLockExclusive:dword
;    extrn '__imp__ExAcquireAutoExpandPushLockShared@??' as ExAcquireAutoExpandPushLockShared:dword
;    extrn '__imp__ExAcquireCacheAwarePushLockExclusive@??' as ExAcquireCacheAwarePushLockExclusive:dword
;    extrn '__imp__ExAcquireCacheAwarePushLockExclusiveEx@??' as ExAcquireCacheAwarePushLockExclusiveEx:dword
;    extrn '__imp__ExAcquireCacheAwarePushLockSharedEx@??' as ExAcquireCacheAwarePushLockSharedEx:dword
;    extrn '__imp__ExAcquirePushLockExclusiveEx@??' as ExAcquirePushLockExclusiveEx:dword
;    extrn '__imp__ExAcquirePushLockSharedEx@??' as ExAcquirePushLockSharedEx:dword
;    extrn '__imp__ExAcquireRundownProtectionCacheAware@??' as ExAcquireRundownProtectionCacheAware:dword
;    extrn '__imp__ExAcquireRundownProtectionCacheAwareEx@??' as ExAcquireRundownProtectionCacheAwareEx:dword
;    extrn '__imp__ExAllocateAutoExpandPushLock@??' as ExAllocateAutoExpandPushLock:dword
;    extrn '__imp__ExBlockOnAddressPushLock@??' as ExBlockOnAddressPushLock:dword
;    extrn '__imp__ExCleanupAutoExpandPushLock@??' as ExCleanupAutoExpandPushLock:dword
;    extrn '__imp__ExCleanupRundownProtectionCacheAware@??' as ExCleanupRundownProtectionCacheAware:dword
;    extrn '__imp__ExCompositionObjectType@??' as ExCompositionObjectType:dword
;    extrn '__imp__ExCompositionSurfaceObjectType@??' as ExCompositionSurfaceObjectType:dword
;    extrn '__imp__ExConvertPushLockExclusiveToShared@??' as ExConvertPushLockExclusiveToShared:dword
;    extrn '__imp__ExDesktopObjectType@??' as ExDesktopObjectType:dword
;    extrn '__imp__ExEnterPriorityRegionAndAcquireResourceExclusive@??' as ExEnterPriorityRegionAndAcquireResourceExclusive:dword
;    extrn '__imp__ExEnterPriorityRegionAndAcquireResourceShared@??' as ExEnterPriorityRegionAndAcquireResourceShared:dword
;    extrn '__imp__ExEventObjectType@??' as ExEventObjectType:dword
;    extrn '__imp__ExFetchLicenseData@??' as ExFetchLicenseData:dword
;    extrn '__imp__ExFreeAutoExpandPushLock@??' as ExFreeAutoExpandPushLock:dword
;    extrn '__imp__ExFreeCacheAwareRundownProtection@??' as ExFreeCacheAwareRundownProtection:dword
;    extrn '__imp__ExfTryAcquirePushLockShared@??' as ExfTryAcquirePushLockShared:dword
;    extrn '__imp__ExGetLicenseTamperState@??' as ExGetLicenseTamperState:dword
;    extrn '__imp__ExiAcquireFastMutex@??' as ExiAcquireFastMutex:dword
;    extrn '__imp__ExInitializeAutoExpandPushLock@??' as ExInitializeAutoExpandPushLock:dword
;    extrn '__imp__ExInitializeRundownProtectionCacheAwareEx@??' as ExInitializeRundownProtectionCacheAwareEx:dword
;    extrn '__imp__ExNotifyBootDeviceRemoval@??' as ExNotifyBootDeviceRemoval:dword
;    extrn '__imp__ExQueryAttributeInformation@??' as ExQueryAttributeInformation:dword
;    extrn '__imp__ExQueryFastCacheAppOrigin@??' as ExQueryFastCacheAppOrigin:dword
;    extrn '__imp__ExQueryFastCacheDevLicense@??' as ExQueryFastCacheDevLicense:dword
;    extrn '__imp__ExQueryWnfStateData@??' as ExQueryWnfStateData:dword
;    extrn '__imp__ExRawInputManagerObjectType@??' as ExRawInputManagerObjectType:dword
;    extrn '__imp__ExRealTimeIsUniversal@??' as ExRealTimeIsUniversal:dword
;    extrn '__imp__ExRegisterAttributeInformationCallback@??' as ExRegisterAttributeInformationCallback:dword
;    extrn '__imp__ExRegisterBootDevice@??' as ExRegisterBootDevice:dword
;    extrn '__imp__ExRegisterExtension@??' as ExRegisterExtension:dword
;    extrn '__imp__ExReleaseAutoExpandPushLockExclusive@??' as ExReleaseAutoExpandPushLockExclusive:dword
;    extrn '__imp__ExReleaseAutoExpandPushLockShared@??' as ExReleaseAutoExpandPushLockShared:dword
;    extrn '__imp__ExReleaseCacheAwarePushLockExclusiveEx@??' as ExReleaseCacheAwarePushLockExclusiveEx:dword
;    extrn '__imp__ExReleaseCacheAwarePushLockSharedEx@??' as ExReleaseCacheAwarePushLockSharedEx:dword
;    extrn '__imp__ExReleasePushLockEx@??' as ExReleasePushLockEx:dword
;    extrn '__imp__ExReleasePushLockExclusiveEx@??' as ExReleasePushLockExclusiveEx:dword
;    extrn '__imp__ExReleasePushLockSharedEx@??' as ExReleasePushLockSharedEx:dword
;    extrn '__imp__ExReleaseResourceAndLeavePriorityRegion@??' as ExReleaseResourceAndLeavePriorityRegion:dword
;    extrn '__imp__ExSemaphoreObjectType@??' as ExSemaphoreObjectType:dword
;    extrn '__imp__ExShareAddressSpaceWithDevice@??' as ExShareAddressSpaceWithDevice:dword
;    extrn '__imp__ExSizeOfAutoExpandPushLock@??' as ExSizeOfAutoExpandPushLock:dword
;    extrn '__imp__ExSizeOfRundownProtectionCacheAware@??' as ExSizeOfRundownProtectionCacheAware:dword
;    extrn '__imp__ExSubscribeWnfStateChange@??' as ExSubscribeWnfStateChange:dword
;    extrn '__imp__ExTimerObjectType@??' as ExTimerObjectType:dword
;    extrn '__imp__ExTryAcquireAutoExpandPushLockExclusive@??' as ExTryAcquireAutoExpandPushLockExclusive:dword
;    extrn '__imp__ExTryAcquireAutoExpandPushLockShared@??' as ExTryAcquireAutoExpandPushLockShared:dword
;    extrn '__imp__ExTryAcquireCacheAwarePushLockExclusiveEx@??' as ExTryAcquireCacheAwarePushLockExclusiveEx:dword
;    extrn '__imp__ExTryAcquireCacheAwarePushLockSharedEx@??' as ExTryAcquireCacheAwarePushLockSharedEx:dword
;    extrn '__imp__ExTryAcquirePushLockExclusiveEx@??' as ExTryAcquirePushLockExclusiveEx:dword
;    extrn '__imp__ExTryAcquirePushLockSharedEx@??' as ExTryAcquirePushLockSharedEx:dword
;    extrn '__imp__ExTryConvertPushLockSharedToExclusiveEx@??' as ExTryConvertPushLockSharedToExclusiveEx:dword
;    extrn '__imp__ExTryQueueWorkItem@??' as ExTryQueueWorkItem:dword
;    extrn '__imp__ExTryToAcquireResourceExclusiveLite@??' as ExTryToAcquireResourceExclusiveLite:dword
;    extrn '__imp__ExUnblockOnAddressPushLockEx@??' as ExUnblockOnAddressPushLockEx:dword
;    extrn '__imp__ExUnblockPushLockEx@??' as ExUnblockPushLockEx:dword
;    extrn '__imp__ExUnregisterAttributeInformationCallback@??' as ExUnregisterAttributeInformationCallback:dword
;    extrn '__imp__ExUnregisterExtension@??' as ExUnregisterExtension:dword
;    extrn '__imp__ExUnsubscribeWnfStateChange@??' as ExUnsubscribeWnfStateChange:dword
;    extrn '__imp__ExUpdateLicenseData@??' as ExUpdateLicenseData:dword
;    extrn '__imp__ExWaitForRundownProtectionReleaseCacheAware@??' as ExWaitForRundownProtectionReleaseCacheAware:dword
;    extrn '__imp__ExWindowStationObjectType@??' as ExWindowStationObjectType:dword
;    extrn '__imp__FsRtlAcquireEofLock@??' as FsRtlAcquireEofLock:dword
;    extrn '__imp__FsRtlAcquireHeaderMutex@??' as FsRtlAcquireHeaderMutex:dword
;    extrn '__imp__FsRtlCheckUpperOplock@??' as FsRtlCheckUpperOplock:dword
;    extrn '__imp__FsRtlDismountComplete@??' as FsRtlDismountComplete:dword
;    extrn '__imp__FsRtlGetFileNameInformation@??' as FsRtlGetFileNameInformation:dword
;    extrn '__imp__FsRtlGetIoAtEof@??' as FsRtlGetIoAtEof:dword
;    extrn '__imp__FsRtlHeatInit@??' as FsRtlHeatInit:dword
;    extrn '__imp__FsRtlHeatLogIo@??' as FsRtlHeatLogIo:dword
;    extrn '__imp__FsRtlHeatLogTierMove@??' as FsRtlHeatLogTierMove:dword
;    extrn '__imp__FsRtlHeatUninit@??' as FsRtlHeatUninit:dword
;    extrn '__imp__FsRtlInitializeBaseMcb@??' as FsRtlInitializeBaseMcb:dword
;    extrn '__imp__FsRtlInitializeBaseMcbEx@??' as FsRtlInitializeBaseMcbEx:dword
;    extrn '__imp__FsRtlInitializeEofLock@??' as FsRtlInitializeEofLock:dword
;    extrn '__imp__FsRtlInsertReservedPerFileContext@??' as FsRtlInsertReservedPerFileContext:dword
;    extrn '__imp__FsRtlInsertReservedPerStreamContext@??' as FsRtlInsertReservedPerStreamContext:dword
;    extrn '__imp__FsRtlIsMobileOS@??' as FsRtlIsMobileOS:dword
;    extrn '__imp__FsRtlKernelFsControlFile@??' as FsRtlKernelFsControlFile:dword
;    extrn '__imp__FsRtlLegalAnsiCharacterArray@??' as FsRtlLegalAnsiCharacterArray:dword
;    extrn '__imp__FsRtlLookupLastBaseMcbEntry@??' as FsRtlLookupLastBaseMcbEntry:dword
;    extrn '__imp__FsRtlLookupReservedPerFileContext@??' as FsRtlLookupReservedPerFileContext:dword
;    extrn '__imp__FsRtlLookupReservedPerStreamContext@??' as FsRtlLookupReservedPerStreamContext:dword
;    extrn '__imp__FsRtlNotifyFilterChangeDirectoryLite@??' as FsRtlNotifyFilterChangeDirectoryLite:dword
;    extrn '__imp__FsRtlNotifyFilterReportChangeLite@??' as FsRtlNotifyFilterReportChangeLite:dword
;    extrn '__imp__FsRtlNumberOfRunsInBaseMcb@??' as FsRtlNumberOfRunsInBaseMcb:dword
;    extrn '__imp__FsRtlQueryInformationFile@??' as FsRtlQueryInformationFile:dword
;    extrn '__imp__FsRtlQueryKernelEaFile@??' as FsRtlQueryKernelEaFile:dword
;    extrn '__imp__FsRtlRegisterFltMgrCalls@??' as FsRtlRegisterFltMgrCalls:dword
;    extrn '__imp__FsRtlRegisterMupCalls@??' as FsRtlRegisterMupCalls:dword
;    extrn '__imp__FsRtlRegisterUncProviderEx2@??' as FsRtlRegisterUncProviderEx2:dword
;    extrn '__imp__FsRtlReleaseEofLock@??' as FsRtlReleaseEofLock:dword
;    extrn '__imp__FsRtlReleaseFileNameInformation@??' as FsRtlReleaseFileNameInformation:dword
;    extrn '__imp__FsRtlReleaseHeaderMutex@??' as FsRtlReleaseHeaderMutex:dword
;    extrn '__imp__FsRtlRemoveReservedPerFileContext@??' as FsRtlRemoveReservedPerFileContext:dword
;    extrn '__imp__FsRtlRemoveReservedPerStreamContext@??' as FsRtlRemoveReservedPerStreamContext:dword
;    extrn '__imp__FsRtlSendModernAppTermination@??' as FsRtlSendModernAppTermination:dword
;    extrn '__imp__FsRtlSetDriverBacking@??' as FsRtlSetDriverBacking:dword
;    extrn '__imp__FsRtlSetKernelEaFile@??' as FsRtlSetKernelEaFile:dword
;    extrn '__imp__FsRtlTryToAcquireHeaderMutex@??' as FsRtlTryToAcquireHeaderMutex:dword
;    extrn '__imp__FsRtlUpdateDiskCounters@??' as FsRtlUpdateDiskCounters:dword
;    extrn '__imp__FsRtlValidateReparsePointBuffer@??' as FsRtlValidateReparsePointBuffer:dword
;    extrn '__imp__HalDispatchTable@??' as HalDispatchTable:dword
;    extrn '__imp__HalPrivateDispatchTable@??' as HalPrivateDispatchTable:dword
;    extrn '__imp__HvlGetLpIndexFromApicId@??' as HvlGetLpIndexFromApicId:dword
;    extrn '__imp__HviGetDebugDeviceOptions@??' as HviGetDebugDeviceOptions:dword
;    extrn '__imp__HviGetEnlightenmentInformation@??' as HviGetEnlightenmentInformation:dword
;    extrn '__imp__HviGetHardwareFeatures@??' as HviGetHardwareFeatures:dword
;    extrn '__imp__HviGetHypervisorFeatures@??' as HviGetHypervisorFeatures:dword
;    extrn '__imp__HviGetHypervisorInterface@??' as HviGetHypervisorInterface:dword
;    extrn '__imp__HviGetHypervisorVendorAndMaxFunction@??' as HviGetHypervisorVendorAndMaxFunction:dword
;    extrn '__imp__HviGetHypervisorVersion@??' as HviGetHypervisorVersion:dword
;    extrn '__imp__HviGetImplementationLimits@??' as HviGetImplementationLimits:dword
;    extrn '__imp__HviIsAnyHypervisorPresent@??' as HviIsAnyHypervisorPresent:dword
;    extrn '__imp__HviIsHypervisorMicrosoftCompatible@??' as HviIsHypervisorMicrosoftCompatible:dword
;    extrn '__imp__HviIsHypervisorVendorMicrosoft@??' as HviIsHypervisorVendorMicrosoft:dword
;    extrn '__imp__HviIsIommuInUse@??' as HviIsIommuInUse:dword
;    extrn '__imp__HvlPerformEndOfInterrupt@??' as HvlPerformEndOfInterrupt:dword
;    extrn '__imp__HvlQueryActiveHypervisorProcessorCount@??' as HvlQueryActiveHypervisorProcessorCount:dword
;    extrn '__imp__HvlQueryActiveProcessors@??' as HvlQueryActiveProcessors:dword
;    extrn '__imp__HvlQueryConnection@??' as HvlQueryConnection:dword
;    extrn '__imp__HvlQueryHypervisorProcessorNodeNumber@??' as HvlQueryHypervisorProcessorNodeNumber:dword
;    extrn '__imp__HvlQueryNumaDistance@??' as HvlQueryNumaDistance:dword
;    extrn '__imp__HvlQueryProcessorTopology@??' as HvlQueryProcessorTopology:dword
;    extrn '__imp__HvlQueryProcessorTopologyCount@??' as HvlQueryProcessorTopologyCount:dword
;    extrn '__imp__HvlQueryProcessorTopologyHighestId@??' as HvlQueryProcessorTopologyHighestId:dword
;    extrn '__imp__HvlReadPerformanceStateCounters@??' as HvlReadPerformanceStateCounters:dword
;    extrn '__imp__HvlRegisterInterruptCallback@??' as HvlRegisterInterruptCallback:dword
;    extrn '__imp__HvlRegisterWheaErrorNotification@??' as HvlRegisterWheaErrorNotification:dword
;    extrn '__imp__HvlUnregisterInterruptCallback@??' as HvlUnregisterInterruptCallback:dword
;    extrn '__imp__HvlUnregisterWheaErrorNotification@??' as HvlUnregisterWheaErrorNotification:dword
;    extrn '__imp__InbvNotifyDisplayOwnershipChange@??' as InbvNotifyDisplayOwnershipChange:dword
;    extrn '__imp__InbvSetVirtualFrameBuffer@??' as InbvSetVirtualFrameBuffer:dword
;    extrn '__imp__InitSafeBootMode@??' as InitSafeBootMode:dword
;    extrn '__imp__IoAdapterObjectType@??' as IoAdapterObjectType:dword
;    extrn '__imp__IoAdjustStackSizeForRedirection@??' as IoAdjustStackSizeForRedirection:dword
;    extrn '__imp__IoAllocateIrpEx@??' as IoAllocateIrpEx:dword
;    extrn '__imp__IoApplyPriorityInfoThread@??' as IoApplyPriorityInfoThread:dword
;    extrn '__imp__IoBoostThreadIo@??' as IoBoostThreadIo:dword
;    extrn '__imp__IoCallDriverStackSafe@??' as IoCallDriverStackSafe:dword
;    extrn '__imp__IoClearDependency@??' as IoClearDependency:dword
;    extrn '__imp__IoClearReservedDependency@??' as IoClearReservedDependency:dword
;    extrn '__imp__IoCompletionObjectType@??' as IoCompletionObjectType:dword
;    extrn '__imp__IoConvertFileHandleToKernelHandle@??' as IoConvertFileHandleToKernelHandle:dword
;    extrn '__imp__IoCopyDeviceObjectHint@??' as IoCopyDeviceObjectHint:dword
;    extrn '__imp__IoCreateArcName@??' as IoCreateArcName:dword
;    extrn '__imp__IoDeleteAllDependencyRelations@??' as IoDeleteAllDependencyRelations:dword
;    extrn '__imp__IoDeviceHandlerObjectSize@??' as IoDeviceHandlerObjectSize:dword
;    extrn '__imp__IoDeviceHandlerObjectType@??' as IoDeviceHandlerObjectType:dword
;    extrn '__imp__IoDeviceObjectType@??' as IoDeviceObjectType:dword
;    extrn '__imp__IoDriverObjectType@??' as IoDriverObjectType:dword
;    extrn '__imp__IoDuplicateDependency@??' as IoDuplicateDependency:dword
;    extrn '__imp__IoEnumerateRegisteredFiltersListEx@??' as IoEnumerateRegisteredFiltersListEx:dword
;    extrn '__imp__IoFileObjectType@??' as IoFileObjectType:dword
;    extrn '__imp__IoFreeMiniCompletionPacket@??' as IoFreeMiniCompletionPacket:dword
;    extrn '__imp__IoGetFsTrackOffsetState@??' as IoGetFsTrackOffsetState:dword
;    extrn '__imp__IoGetFsZeroingOffset@??' as IoGetFsZeroingOffset:dword
;    extrn '__imp__IoGetGenericIrpExtension@??' as IoGetGenericIrpExtension:dword
;    extrn '__imp__IoGetSymlinkSupportInformation@??' as IoGetSymlinkSupportInformation:dword
;    extrn '__imp__IoInitializeMiniCompletionPacket@??' as IoInitializeMiniCompletionPacket:dword
;    extrn '__imp__IoIsActivityTracingEnabled@??' as IoIsActivityTracingEnabled:dword
;    extrn '__imp__IoLoadCrashDumpDriver@??' as IoLoadCrashDumpDriver:dword
;    extrn '__imp__IoMakeAssociatedIrpEx@??' as IoMakeAssociatedIrpEx:dword
;    extrn '__imp__IoPropagateIrpExtension@??' as IoPropagateIrpExtension:dword
;    extrn '__imp__IoPropagateIrpExtensionEx@??' as IoPropagateIrpExtensionEx:dword
;    extrn '__imp__IoQueryInterface@??' as IoQueryInterface:dword
;    extrn '__imp__IoQueueWorkItemToNode@??' as IoQueueWorkItemToNode:dword
;    extrn '__imp__IoReadOperationCount@??' as IoReadOperationCount:dword
;    extrn '__imp__IoReadTransferCount@??' as IoReadTransferCount:dword
;    extrn '__imp__IoRegisterFsRegistrationChangeMountAwareEx@??' as IoRegisterFsRegistrationChangeMountAwareEx:dword
;    extrn '__imp__IoRegisterIoTracking@??' as IoRegisterIoTracking:dword
;    extrn '__imp__IoRegisterPriorityCallback@??' as IoRegisterPriorityCallback:dword
;    extrn '__imp__IoRequestDeviceEjectEx@??' as IoRequestDeviceEjectEx:dword
;    extrn '__imp__IoReserveDependency@??' as IoReserveDependency:dword
;    extrn '__imp__IoResolveDependency@??' as IoResolveDependency:dword
;    extrn '__imp__IoRetrievePriorityInfo@??' as IoRetrievePriorityInfo:dword
;    extrn '__imp__IoSetDependency@??' as IoSetDependency:dword
;    extrn '__imp__IoSetGenericIrpExtension@??' as IoSetGenericIrpExtension:dword
;    extrn '__imp__IoSetIoCompletionEx@??' as IoSetIoCompletionEx:dword
;    extrn '__imp__IoSetIoPriorityHintIntoFileObject@??' as IoSetIoPriorityHintIntoFileObject:dword
;    extrn '__imp__IoSetIoPriorityHintIntoThread@??' as IoSetIoPriorityHintIntoThread:dword
;    extrn '__imp__IoSizeofGenericIrpExtension@??' as IoSizeofGenericIrpExtension:dword
;    extrn '__imp__IoStatisticsLock@??' as IoStatisticsLock:dword
;    extrn '__imp__IoSynchronousCallDriver@??' as IoSynchronousCallDriver:dword
;    extrn '__imp__IoSteerInterrupt@??' as IoSteerInterrupt:dword
;    extrn '__imp__IoTestDependency@??' as IoTestDependency:dword
;    extrn '__imp__IoUnregisterIoTracking@??' as IoUnregisterIoTracking:dword
;    extrn '__imp__IoVolumeDeviceNameToGuidPath@??' as IoVolumeDeviceNameToGuidPath:dword
;    extrn '__imp__IoVolumeDeviceToGuidPath@??' as IoVolumeDeviceToGuidPath:dword
;    extrn '__imp__IoWriteOperationCount@??' as IoWriteOperationCount:dword
;    extrn '__imp__IoWriteTransferCount@??' as IoWriteTransferCount:dword
;    extrn '__imp__iswalnum@??' as iswalnum:dword
;    extrn '__imp__iswdigit@??' as iswdigit:dword
;    extrn '__imp__iswspace@??' as iswspace:dword
;    extrn '__imp__KdAcquireDebuggerLock@??' as KdAcquireDebuggerLock:dword
;    extrn '__imp__KdChangeOption@??' as KdChangeOption:dword
;    extrn '__imp__KdDebuggerEnabled@??' as KdDebuggerEnabled:dword
;    extrn '__imp__KdDebuggerNotPresent@??' as KdDebuggerNotPresent:dword
;    extrn '__imp__KdDeregisterPowerHandler@??' as KdDeregisterPowerHandler:dword
;    extrn '__imp__KdEnteredDebugger@??' as KdEnteredDebugger:dword
;    extrn '__imp__KdEventLoggingEnabled@??' as KdEventLoggingEnabled:dword
;    extrn '__imp__KdGetDebugDevice@??' as KdGetDebugDevice:dword
;    extrn '__imp__KdRegisterPowerHandler@??' as KdRegisterPowerHandler:dword
;    extrn '__imp__KdReleaseDebuggerLock@??' as KdReleaseDebuggerLock:dword
;    extrn '__imp__KdSetEventLoggingPresent@??' as KdSetEventLoggingPresent:dword
;    extrn '__imp__KeAddGroupAffinityEx@??' as KeAddGroupAffinityEx:dword
;    extrn '__imp__KeAddProcessorAffinityEx@??' as KeAddProcessorAffinityEx:dword
;    extrn '__imp__KeAddProcessorGroupAffinity@??' as KeAddProcessorGroupAffinity:dword
;    extrn '__imp__KeAllocateCalloutStack@??' as KeAllocateCalloutStack:dword
;    extrn '__imp__KeAllocateCalloutStackEx@??' as KeAllocateCalloutStackEx:dword
;    extrn '__imp__KeAndGroupAffinityEx@??' as KeAndGroupAffinityEx:dword
;    extrn '__imp__KeCancelTimer2@??' as KeCancelTimer2:dword
;    extrn '__imp__KeCheckProcessorAffinityEx@??' as KeCheckProcessorAffinityEx:dword
;    extrn '__imp__KeCheckProcessorGroupAffinity@??' as KeCheckProcessorGroupAffinity:dword
;    extrn '__imp__KeClockInterruptNotify@??' as KeClockInterruptNotify:dword
;    extrn '__imp__KeClockTimerPowerChange@??' as KeClockTimerPowerChange:dword
;    extrn '__imp__KeConnectInterruptForHal@??' as KeConnectInterruptForHal:dword
;    extrn '__imp__KeCopyAffinityEx@??' as KeCopyAffinityEx:dword
;    extrn '__imp__KeCountSetBitsAffinityEx@??' as KeCountSetBitsAffinityEx:dword
;    extrn '__imp__KeCountSetBitsGroupAffinity@??' as KeCountSetBitsGroupAffinity:dword
;    extrn '__imp__KeDcacheFlushCount@??' as KeDcacheFlushCount:dword
;    extrn '__imp__KeDispatchSecondaryInterrupt@??' as KeDispatchSecondaryInterrupt:dword
;    extrn '__imp__KeEnumerateNextProcessor@??' as KeEnumerateNextProcessor:dword
;    extrn '__imp__KeFindFirstSetLeftGroupAffinity@??' as KeFindFirstSetLeftGroupAffinity:dword
;    extrn '__imp__KeFindFirstSetRightAffinityEx@??' as KeFindFirstSetRightAffinityEx:dword
;    extrn '__imp__KeFindFirstSetRightGroupAffinity@??' as KeFindFirstSetRightGroupAffinity:dword
;    extrn '__imp__KeFirstGroupAffinityEx@??' as KeFirstGroupAffinityEx:dword
;    extrn '__imp__KeForceEnableNx@??' as KeForceEnableNx:dword
;    extrn '__imp__KeFreeCalloutStack@??' as KeFreeCalloutStack:dword
;    extrn '__imp__KeGetClockOwner@??' as KeGetClockOwner:dword
;    extrn '__imp__KeGetClockTimerResolution@??' as KeGetClockTimerResolution:dword
;    extrn '__imp__KeGetEffectiveIrql@??' as KeGetEffectiveIrql:dword
;    extrn '__imp__KeGetNextClockTickDuration@??' as KeGetNextClockTickDuration:dword
;    extrn '__imp__KeGetNextTimerExpirationDueTime@??' as KeGetNextTimerExpirationDueTime:dword
;    extrn '__imp__KeGetXSaveFeatureFlags@??' as KeGetXSaveFeatureFlags:dword
;    extrn '__imp__KeHwPolicyLocateResource@??' as KeHwPolicyLocateResource:dword
;    extrn '__imp__KeI386Call16BitCStyleFunction@??' as KeI386Call16BitCStyleFunction:dword
;    extrn '__imp__Kei386EoiHelper@??' as Kei386EoiHelper:dword
;    extrn '__imp__KeI386MachineType@??' as KeI386MachineType:dword
;    extrn '__imp__KeIcacheFlushCount@??' as KeIcacheFlushCount:dword
;    extrn '__imp__KeInitializeAffinityEx@??' as KeInitializeAffinityEx:dword
;    extrn '__imp__KeInitializeEnumerationContextFromGroup@??' as KeInitializeEnumerationContextFromGroup:dword
;    extrn '__imp__KeInitializeSecondaryInterruptServices@??' as KeInitializeSecondaryInterruptServices:dword
;    extrn '__imp__KeInitializeTimer2@??' as KeInitializeTimer2:dword
;    extrn '__imp__KeInterlockedClearProcessorAffinityEx@??' as KeInterlockedClearProcessorAffinityEx:dword
;    extrn '__imp__KeIsSingleGroupAffinityEx@??' as KeIsSingleGroupAffinityEx:dword
;    extrn '__imp__KeLastBranchMSR@??' as KeLastBranchMSR:dword
;    extrn '__imp__KeLoaderBlock@??' as KeLoaderBlock:dword :VARARG
;    extrn '__imp__KeLoadMTRR@??' as KeLoadMTRR:dword
;    extrn '__imp__KeNotifyProcessorFreezeSupported@??' as KeNotifyProcessorFreezeSupported:dword
;    extrn '__imp__KeNumberProcessors@??' as KeNumberProcessors:dword
;    extrn '__imp__KeOrAffinityEx@??' as KeOrAffinityEx:dword
;    extrn '__imp__KeProcessorGroupAffinity@??' as KeProcessorGroupAffinity:dword
;    extrn '__imp__KeQueryActiveProcessorAffinity@??' as KeQueryActiveProcessorAffinity:dword
;    extrn '__imp__KeQueryEffectivePriorityThread@??' as KeQueryEffectivePriorityThread:dword
;    extrn '__imp__KeQueryGroupAffinityEx@??' as KeQueryGroupAffinityEx:dword
;    extrn '__imp__KeQueryHeteroCpuPolicyThread@??' as KeQueryHeteroCpuPolicyThread:dword
;    extrn '__imp__KeQueryMultiThreadProcessorSet@??' as KeQueryMultiThreadProcessorSet:dword
;    extrn '__imp__KeRemoveGroupAffinityEx@??' as KeRemoveGroupAffinityEx:dword
;    extrn '__imp__KeRemoveProcessorAffinityEx@??' as KeRemoveProcessorAffinityEx:dword
;    extrn '__imp__KeRemoveProcessorGroupAffinity@??' as KeRemoveProcessorGroupAffinity:dword
;    extrn '__imp__KeRemoveQueueDpcEx@??' as KeRemoveQueueDpcEx:dword
;    extrn '__imp__KeReportCacheIncoherentDevice@??' as KeReportCacheIncoherentDevice:dword
;    extrn '__imp__KeRevertToUserAffinityThread@??' as KeRevertToUserAffinityThread:dword
;    extrn '__imp__KeServiceDescriptorTable@??' as KeServiceDescriptorTable:dword
;    extrn '__imp__KeSetActualBasePriorityThread@??' as KeSetActualBasePriorityThread:dword
;    extrn '__imp__KeSetHeteroCpuPolicyThread@??' as KeSetHeteroCpuPolicyThread:dword
;    extrn '__imp__KeSetSelectedCpuSetsThread@??' as KeSetSelectedCpuSetsThread:dword
;    extrn '__imp__KeSetTimer2@??' as KeSetTimer2:dword
;    extrn '__imp__KeSignalCallDpcDone@??' as KeSignalCallDpcDone:dword
;    extrn '__imp__KeSignalCallDpcSynchronize@??' as KeSignalCallDpcSynchronize:dword
;    extrn '__imp__KeStallWhileFrozen@??' as KeStallWhileFrozen:dword
;    extrn '__imp__KeStartDynamicProcessor@??' as KeStartDynamicProcessor:dword
;    extrn '__imp__KeSubtractAffinityEx@??' as KeSubtractAffinityEx:dword
;    extrn '__imp__KeSweepLocalCaches@??' as KeSweepLocalCaches:dword
;    extrn '__imp__KeSynchronizeTimeToQpc@??' as KeSynchronizeTimeToQpc:dword
;    extrn '__imp__KeSystemFullyCacheCoherent@??' as KeSystemFullyCacheCoherent:dword
;    extrn '__imp__KeTickCount@??' as KeTickCount:dword
;    extrn '__imp__KeUpdateSystemTime@??' as KeUpdateSystemTime:dword
;    extrn '__imp__KeUpdateTime@??' as KeUpdateTime:dword
;    extrn '__imp__KeUpdateThreadTag@??' as KeUpdateThreadTag:dword
;    extrn '__imp__KeUpdateTimeAssist@??' as KeUpdateTimeAssist:dword
;    extrn '__imp__KeWriteProtectPAT@??' as KeWriteProtectPAT:dword
;    extrn '__imp__KfRaiseIrql@??' as KfRaiseIrql:dword
;    extrn '__imp__KiBugCheckData@??' as KiBugCheckData:dword
;    extrn '__imp__KiCheckForSListAddress@??' as KiCheckForSListAddress:dword
;    extrn '__imp__KiCpuId@??' as KiCpuId:dword
;    extrn '__imp__KiDispatchInterrupt@??' as KiDispatchInterrupt:dword
;    extrn '__imp__KiEnableTimerWatchdog@??' as KiEnableTimerWatchdog:dword
;    extrn '__imp__KitLogFeatureUsage@??' as KitLogFeatureUsage:dword
;    extrn '__imp__KiUnexpectedInterrupt@??' as KiUnexpectedInterrupt:dword
;    extrn '__imp__KseQueryDeviceData@??' as KseQueryDeviceData:dword
;    extrn '__imp__KseQueryDeviceDataList@??' as KseQueryDeviceDataList:dword
;    extrn '__imp__KseQueryDeviceFlags@??' as KseQueryDeviceFlags:dword
;    extrn '__imp__KseRegisterShim@??' as KseRegisterShim:dword
;    extrn '__imp__KseRegisterShimEx@??' as KseRegisterShimEx:dword
;    extrn '__imp__KseSetDeviceFlags@??' as KseSetDeviceFlags:dword
;    extrn '__imp__KseUnregisterShim@??' as KseUnregisterShim:dword
;    extrn '__imp__LdrFindResourceEx_U@??' as LdrFindResourceEx_U:dword
;    extrn '__imp__LdrResFindResource@??' as LdrResFindResource:dword
;    extrn '__imp__LdrResFindResourceDirectory@??' as LdrResFindResourceDirectory:dword
;    extrn '__imp__LdrResSearchResource@??' as LdrResSearchResource:dword
;    extrn '__imp__LpcPortObjectType@??' as LpcPortObjectType:dword
;    extrn '__imp__LpcReplyWaitReplyPort@??' as LpcReplyWaitReplyPort:dword
;    extrn '__imp__LpcSendWaitReceivePort@??' as LpcSendWaitReceivePort:dword
;    extrn '__imp__Mm64BitPhysicalAddress@??' as Mm64BitPhysicalAddress:dword
;    extrn '__imp__MmAddVerifierSpecialThunks@??' as MmAddVerifierSpecialThunks:dword
;    extrn '__imp__MmAreMdlPagesCached@??' as MmAreMdlPagesCached:dword
;    extrn '__imp__MmBadPointer@??' as MmBadPointer:dword
;    extrn '__imp__MmChangeImageProtection@??' as MmChangeImageProtection:dword
;    extrn '__imp__MmGetCacheAttribute@??' as MmGetCacheAttribute:dword
;    extrn '__imp__MmHighestUserAddress@??' as MmHighestUserAddress:dword
;    extrn '__imp__MmMapViewInSessionSpaceEx@??' as MmMapViewInSessionSpaceEx:dword
;    extrn '__imp__MmMapViewInSystemSpaceEx@??' as MmMapViewInSystemSpaceEx:dword
;    extrn '__imp__MmMdlPageContentsState@??' as MmMdlPageContentsState:dword
;    extrn '__imp__MmPrefetchVirtualAddresses@??' as MmPrefetchVirtualAddresses:dword
;    extrn '__imp__MmSectionObjectType@??' as MmSectionObjectType:dword
;    extrn '__imp__MmSetUserExceptionCallout@??' as MmSetUserExceptionCallout:dword
;    extrn '__imp__MmSystemRangeStart@??' as MmSystemRangeStart:dword
;    extrn '__imp__MmUserProbeAddress@??' as MmUserProbeAddress:dword
;    extrn '__imp__NlsAnsiCodePage@??' as NlsAnsiCodePage:dword
;    extrn '__imp__NlsLeadByteInfo@??' as NlsLeadByteInfo:dword
;    extrn '__imp__NlsMbCodePageTag@??' as NlsMbCodePageTag:dword
;    extrn '__imp__NlsMbOemCodePageTag@??' as NlsMbOemCodePageTag:dword
;    extrn '__imp__NlsOemCodePage@??' as NlsOemCodePage:dword
;    extrn '__imp__NtBuildGUID@??' as NtBuildGUID:dword
;    extrn '__imp__NtBuildLab@??' as NtBuildLab:dword
;    extrn '__imp__NtBuildNumber@??' as NtBuildNumber:dword
;    extrn '__imp__NtGetEnvironmentVariableEx@??' as NtGetEnvironmentVariableEx:dword
;    extrn '__imp__NtGlobalFlag@??' as NtGlobalFlag:dword
;    extrn '__imp__NtQueryEnvironmentVariableInfoEx@??' as NtQueryEnvironmentVariableInfoEx:dword
;    extrn '__imp__NtSetCachedSigningLevel@??' as NtSetCachedSigningLevel:dword
;    extrn '__imp__NtSetInformationVirtualMemory@??' as NtSetInformationVirtualMemory:dword
;    extrn '__imp__ObfDereferenceObjectWithTag@??' as ObfDereferenceObjectWithTag:dword
;    extrn '__imp__ObGetObjectType@??' as ObGetObjectType:dword
;    extrn '__imp__ObOpenObjectByNameEx@??' as ObOpenObjectByNameEx:dword
;    extrn '__imp__ObReferenceObjectSafeWithTag@??' as ObReferenceObjectSafeWithTag:dword
;    extrn '__imp__ObWaitForMultipleObjects@??' as ObWaitForMultipleObjects:dword
;    extrn '__imp__PfFileInfoNotify@??' as PfFileInfoNotify:dword
;    extrn '__imp__PoAllProcessorsDeepIdle@??' as PoAllProcessorsDeepIdle:dword
;    extrn '__imp__PoCpuIdledSinceLastCallImprecise@??' as PoCpuIdledSinceLastCallImprecise:dword
;    extrn '__imp__PoDisableSleepStates@??' as PoDisableSleepStates:dword
;    extrn '__imp__PoFxProcessorNotification@??' as PoFxProcessorNotification:dword
;    extrn '__imp__PoEnergyEstimationEnabled@??' as PoEnergyEstimationEnabled:dword
;    extrn '__imp__PoFxEnableDStateReporting@??' as PoFxEnableDStateReporting:dword
;    extrn '__imp__PoFxRegisterCoreDevice@??' as PoFxRegisterCoreDevice:dword
;    extrn '__imp__PoFxRegisterPlugin@??' as PoFxRegisterPlugin:dword
;    extrn '__imp__PoFxRegisterPluginEx@??' as PoFxRegisterPluginEx:dword
;    extrn '__imp__PoFxRegisterPrimaryDevice@??' as PoFxRegisterPrimaryDevice:dword
;    extrn '__imp__PoGetProcessorIdleAccounting@??' as PoGetProcessorIdleAccounting:dword
;    extrn '__imp__POGOBuffer@??' as POGOBuffer:dword
;    extrn '__imp__PoInitiateProcessorWake@??' as PoInitiateProcessorWake:dword
;    extrn '__imp__PoLatencySensitivityHint@??' as PoLatencySensitivityHint:dword
;    extrn '__imp__PoNotifyDisableDynamicTick@??' as PoNotifyDisableDynamicTick:dword
;    extrn '__imp__PoNotifyMediaBuffering@??' as PoNotifyMediaBuffering:dword
;    extrn '__imp__PoNotifyVSyncChange@??' as PoNotifyVSyncChange:dword
;    extrn '__imp__PoQueueShutdownWorkItem@??' as PoQueueShutdownWorkItem:dword
;    extrn '__imp__PoReenableSleepStates@??' as PoReenableSleepStates:dword
;    extrn '__imp__PoRegisterCoalescingCallback@??' as PoRegisterCoalescingCallback:dword
;    extrn '__imp__PoSetFixedWakeSource@??' as PoSetFixedWakeSource:dword
;    extrn '__imp__PoSetUserPresent@??' as PoSetUserPresent:dword
;    extrn '__imp__PoSetSystemWakeDevice@??' as PoSetSystemWakeDevice:dword
;    extrn '__imp__PoUnregisterCoalescingCallback@??' as PoUnregisterCoalescingCallback:dword
;    extrn '__imp__PoUserShutdownCancelled@??' as PoUserShutdownCancelled:dword
;    extrn '__imp__PoUserShutdownInitiated@??' as PoUserShutdownInitiated:dword
;    extrn '__imp__PsChargeProcessCpuCycles@??' as PsChargeProcessCpuCycles:dword
;    extrn '__imp__PsChargeProcessWakeCounter@??' as PsChargeProcessWakeCounter:dword
;    extrn '__imp__PsDereferenceKernelStack@??' as PsDereferenceKernelStack:dword
;    extrn '__imp__PsEnterPriorityRegion@??' as PsEnterPriorityRegion:dword
;    extrn '__imp__PsGetCurrentProcessWow64Process@??' as PsGetCurrentProcessWow64Process:dword
;    extrn '__imp__PsGetCurrentThreadWin32ThreadAndEnterCriticalRegion@??' as PsGetCurrentThreadWin32ThreadAndEnterCriticalRegion:dword
;    extrn '__imp__PsGetEffectiveContainerId@??' as PsGetEffectiveContainerId:dword
;    extrn '__imp__PsGetJobProperty@??' as PsGetJobProperty:dword
;    extrn '__imp__PsGetProcessCommonJob@??' as PsGetProcessCommonJob:dword
;    extrn '__imp__PsGetProcessProtection@??' as PsGetProcessProtection:dword
;    extrn '__imp__PsGetProcessServerSilo@??' as PsGetProcessServerSilo:dword
;    extrn '__imp__PsGetProcessSessionIdEx@??' as PsGetProcessSessionIdEx:dword
;    extrn '__imp__PsGetProcessSignatureLevel@??' as PsGetProcessSignatureLevel:dword
;    extrn '__imp__PsGetSiloIdentifier@??' as PsGetSiloIdentifier:dword
;    extrn '__imp__PsInitialSystemProcess@??' as PsInitialSystemProcess:dword
;    extrn '__imp__PsIsProcessInAppSilo@??' as PsIsProcessInAppSilo:dword
;    extrn '__imp__PsIsProtectedProcess@??' as PsIsProtectedProcess:dword
;    extrn '__imp__PsIsProtectedProcessLight@??' as PsIsProtectedProcessLight:dword
;    extrn '__imp__PsJobType@??' as PsJobType:dword
;    extrn '__imp__PsLeavePriorityRegion@??' as PsLeavePriorityRegion:dword
;    extrn '__imp__psMUITest@??' as psMUITest:dword
;    extrn '__imp__PsLoadedModuleList@??' as PsLoadedModuleList:dword
;    extrn '__imp__PsLoadedModuleResource@??' as PsLoadedModuleResource:dword
;    extrn '__imp__PsUpdateComponentPower@??' as PsUpdateComponentPower:dword
;    extrn '__imp__PsQueryProcessAttributesByToken@??' as PsQueryProcessAttributesByToken:dword
;    extrn '__imp__PsQueryProcessExceptionFlags@??' as PsQueryProcessExceptionFlags:dword
;    extrn '__imp__PsReferenceKernelStack@??' as PsReferenceKernelStack:dword
;    extrn '__imp__PsReleaseProcessExitSynchronization@??' as PsReleaseProcessExitSynchronization:dword
;    extrn '__imp__PsReleaseProcessWakeCounter@??' as PsReleaseProcessWakeCounter:dword
;    extrn '__imp__PsSetCreateProcessNotifyRoutineEx2@??' as PsSetCreateProcessNotifyRoutineEx2:dword
;    extrn '__imp__PsSetJobProperty@??' as PsSetJobProperty:dword
;    extrn '__imp__PsSetThreadProperty@??' as PsSetThreadProperty:dword
;    extrn '__imp__PsUILanguageComitted@??' as PsUILanguageComitted:dword
;    extrn '__imp__RtlAddAccessAllowedObjectAce@??' as RtlAddAccessAllowedObjectAce:dword
;    extrn '__imp__RtlAddAtomToAtomTableEx@??' as RtlAddAtomToAtomTableEx:dword
;    extrn '__imp__RtlAddProcessTrustLabelAce@??' as RtlAddProcessTrustLabelAce:dword
;    extrn '__imp__RtlAddResourceAttributeAce@??' as RtlAddResourceAttributeAce:dword
;    extrn '__imp__RtlAreBitsClearEx@??' as RtlAreBitsClearEx:dword
;    extrn '__imp__RtlAreBitsSetEx@??' as RtlAreBitsSetEx:dword
;    extrn '__imp__RtlAvlInsertNodeEx@??' as RtlAvlInsertNodeEx:dword
;    extrn '__imp__RtlAvlRemoveNode@??' as RtlAvlRemoveNode:dword
;    extrn '__imp__RtlCapabilityCheck@??' as RtlCapabilityCheck:dword
;    extrn '__imp__RtlCheckTokenCapability@??' as RtlCheckTokenCapability:dword
;    extrn '__imp__RtlCheckTokenMembership@??' as RtlCheckTokenMembership:dword
;    extrn '__imp__RtlCheckTokenMembershipEx@??' as RtlCheckTokenMembershipEx:dword
;    extrn '__imp__RtlClearAllBitsEx@??' as RtlClearAllBitsEx:dword
;    extrn '__imp__RtlClearBitEx@??' as RtlClearBitEx:dword
;    extrn '__imp__RtlClearBitsEx@??' as RtlClearBitsEx:dword
;    extrn '__imp__RtlContractHashTable@??' as RtlContractHashTable:dword
;    extrn '__imp__RtlCopyBitMap@??' as RtlCopyBitMap:dword
;    extrn '__imp__RtlCopyMemoryNonTemporal@??' as RtlCopyMemoryNonTemporal:dword
;    extrn '__imp__RtlCrc32@??' as RtlCrc32:dword
;    extrn '__imp__RtlCrc64@??' as RtlCrc64:dword
;    extrn '__imp__RtlCreateAtomTableEx@??' as RtlCreateAtomTableEx:dword
;    extrn '__imp__RtlCreateHashTable@??' as RtlCreateHashTable:dword
;    extrn '__imp__RtlCreateHashTableEx@??' as RtlCreateHashTableEx:dword
;    extrn '__imp__RtlDeleteHashTable@??' as RtlDeleteHashTable:dword
;    extrn '__imp__RtlEndEnumerationHashTable@??' as RtlEndEnumerationHashTable:dword
;    extrn '__imp__RtlEndWeakEnumerationHashTable@??' as RtlEndWeakEnumerationHashTable:dword
;    extrn '__imp__RtlEnumerateEntryHashTable@??' as RtlEnumerateEntryHashTable:dword
;    extrn '__imp__RtlEqualWnfChangeStamps@??' as RtlEqualWnfChangeStamps:dword
;    extrn '__imp__RtlExpandHashTable@??' as RtlExpandHashTable:dword
;    extrn '__imp__RtlExtractBitMap@??' as RtlExtractBitMap:dword
;    extrn '__imp__RtlFindAceByType@??' as RtlFindAceByType:dword
;    extrn '__imp__RtlFindClearBitsAndSetEx@??' as RtlFindClearBitsAndSetEx:dword
;    extrn '__imp__RtlFindClearBitsEx@??' as RtlFindClearBitsEx:dword
;    extrn '__imp__RtlFindClosestEncodableLength@??' as RtlFindClosestEncodableLength:dword
;    extrn '__imp__RtlFindExportedRoutineByName@??' as RtlFindExportedRoutineByName:dword
;    extrn '__imp__RtlFindNextForwardRunClearEx@??' as RtlFindNextForwardRunClearEx:dword
;    extrn '__imp__RtlFindSetBitsAndClearEx@??' as RtlFindSetBitsAndClearEx:dword
;    extrn '__imp__RtlFindSetBitsEx@??' as RtlFindSetBitsEx:dword
;    extrn '__imp__RtlGenerateClass5Guid@??' as RtlGenerateClass5Guid:dword
;    extrn '__imp__RtlGetAppContainerNamedObjectPath@??' as RtlGetAppContainerNamedObjectPath:dword
;    extrn '__imp__RtlGetAppContainerParent@??' as RtlGetAppContainerParent:dword
;    extrn '__imp__RtlGetAppContainerSidType@??' as RtlGetAppContainerSidType:dword
;    extrn '__imp__RtlGetIntegerAtom@??' as RtlGetIntegerAtom:dword
;    extrn '__imp__RtlGetLastRange@??' as RtlGetLastRange:dword
;    extrn '__imp__RtlGetProductInfo@??' as RtlGetProductInfo:dword
;    extrn '__imp__RtlIdnToAscii@??' as RtlIdnToAscii:dword
;    extrn '__imp__RtlIdnToNameprepUnicode@??' as RtlIdnToNameprepUnicode:dword
;    extrn '__imp__RtlIdnToUnicode@??' as RtlIdnToUnicode:dword
;    extrn '__imp__RtlImageNtHeaderEx@??' as RtlImageNtHeaderEx:dword
;    extrn '__imp__RtlInitializeBitMapEx@??' as RtlInitializeBitMapEx:dword
;    extrn '__imp__RtlInterlockedClearBitRun@??' as RtlInterlockedClearBitRun:dword
;    extrn '__imp__RtlInterlockedSetBitRun@??' as RtlInterlockedSetBitRun:dword
;    extrn '__imp__RtlInterlockedSetClearRun@??' as RtlInterlockedSetClearRun:dword
;    extrn '__imp__RtlInvertRangeListEx@??' as RtlInvertRangeListEx:dword
;    extrn '__imp__RtlIsMultiSessionSku@??' as RtlIsMultiSessionSku:dword
;    extrn '__imp__RtlIsSandboxedToken@??' as RtlIsSandboxedToken:dword
;    extrn '__imp__RtlIsUntrustedObject@??' as RtlIsUntrustedObject:dword
;    extrn '__imp__RtlLCIDToCultureName@??' as RtlLCIDToCultureName:dword
;    extrn '__imp__RtlLoadString@??' as RtlLoadString:dword
;    extrn '__imp__RtlNormalizeString@??' as RtlNormalizeString:dword
;    extrn '__imp__RtlNumberOfClearBitsEx@??' as RtlNumberOfClearBitsEx:dword
;    extrn '__imp__RtlNumberOfClearBitsInRange@??' as RtlNumberOfClearBitsInRange:dword
;    extrn '__imp__RtlNumberOfSetBitsEx@??' as RtlNumberOfSetBitsEx:dword
;    extrn '__imp__RtlNumberOfSetBitsInRange@??' as RtlNumberOfSetBitsInRange:dword
;    extrn '__imp__RtlOwnerAcesPresent@??' as RtlOwnerAcesPresent:dword
;    extrn '__imp__RtlQueryDynamicTimeZoneInformation@??' as RtlQueryDynamicTimeZoneInformation:dword
;    extrn '__imp__RtlQueryModuleInformation@??' as RtlQueryModuleInformation:dword
;    extrn '__imp__RtlQueryPackageClaims@??' as RtlQueryPackageClaims:dword
;    extrn '__imp__RtlQueryPackageIdentity@??' as RtlQueryPackageIdentity:dword
;    extrn '__imp__RtlQueryRegistryValuesEx@??' as RtlQueryRegistryValuesEx:dword
;    extrn '__imp__RtlQueryValidationRunlevel@??' as RtlQueryValidationRunlevel:dword
;    extrn '__imp__RtlRbReplaceNode@??' as RtlRbReplaceNode:dword
;    extrn '__imp__RtlRemoveEntryHashTable@??' as RtlRemoveEntryHashTable:dword
;    extrn '__imp__RtlReplaceSidInSd@??' as RtlReplaceSidInSd:dword
;    extrn '__imp__RtlSetAllBitsEx@??' as RtlSetAllBitsEx:dword
;    extrn '__imp__RtlSetBitEx@??' as RtlSetBitEx:dword
;    extrn '__imp__RtlSetBitsEx@??' as RtlSetBitsEx:dword
;    extrn '__imp__RtlSetDynamicTimeZoneInformation@??' as RtlSetDynamicTimeZoneInformation:dword
;    extrn '__imp__RtlSetPortableOperatingSystem@??' as RtlSetPortableOperatingSystem:dword
;    extrn '__imp__RtlSidHashInitialize@??' as RtlSidHashInitialize:dword
;    extrn '__imp__RtlSidHashLookup@??' as RtlSidHashLookup:dword
;    extrn '__imp__RtlTestBitEx@??' as RtlTestBitEx:dword
;    extrn '__imp__RtlWeaklyEnumerateEntryHashTable@??' as RtlWeaklyEnumerateEntryHashTable:dword
;    extrn '__imp__SeAccessCheckFromState@??' as SeAccessCheckFromState:dword
;    extrn '__imp__SeAccessCheckFromStateEx@??' as SeAccessCheckFromStateEx:dword
;    extrn '__imp__SeAccessCheckWithHint@??' as SeAccessCheckWithHint:dword
;    extrn '__imp__SeAuditingAnyFileEventsWithContextEx@??' as SeAuditingAnyFileEventsWithContextEx:dword
;    extrn '__imp__SeAuditingFileEventsWithContextEx@??' as SeAuditingFileEventsWithContextEx:dword
;    extrn '__imp__SeAuditingWithTokenForSubcategory@??' as SeAuditingWithTokenForSubcategory:dword
;    extrn '__imp__SeCloseObjectAuditAlarmForNonObObject@??' as SeCloseObjectAuditAlarmForNonObObject:dword
;    extrn '__imp__SeCompareSigningLevels@??' as SeCompareSigningLevels:dword
;    extrn '__imp__SeCreateClientSecurityEx@??' as SeCreateClientSecurityEx:dword
;    extrn '__imp__SeCreateClientSecurityFromSubjectContextEx@??' as SeCreateClientSecurityFromSubjectContextEx:dword
;    extrn '__imp__SeExports@??' as SeExports:dword
;    extrn '__imp__SeGetCachedSigningLevel@??' as SeGetCachedSigningLevel:dword
;    extrn '__imp__SeGetLinkedToken@??' as SeGetLinkedToken:dword
;    extrn '__imp__SeGetLogonSessionToken@??' as SeGetLogonSessionToken:dword
;    extrn '__imp__SeIsParentOfChildAppContainer@??' as SeIsParentOfChildAppContainer:dword
;    extrn '__imp__SeOpenObjectAuditAlarmForNonObObject@??' as SeOpenObjectAuditAlarmForNonObObject:dword
;    extrn '__imp__SeOpenObjectAuditAlarmWithTransaction@??' as SeOpenObjectAuditAlarmWithTransaction:dword
;    extrn '__imp__SePublicDefaultDacl@??' as SePublicDefaultDacl:dword
;    extrn '__imp__SeQuerySecureBootPolicyValue@??' as SeQuerySecureBootPolicyValue:dword
;    extrn '__imp__SeQuerySecurityAttributesToken@??' as SeQuerySecurityAttributesToken:dword
;    extrn '__imp__SeRegisterImageVerificationCallback@??' as SeRegisterImageVerificationCallback:dword
;    extrn '__imp__SeSecurityAttributePresent@??' as SeSecurityAttributePresent:dword
;    extrn '__imp__SeSetAuthorizationCallbacks@??' as SeSetAuthorizationCallbacks:dword
;    extrn '__imp__SeSetSecurityAttributesToken@??' as SeSetSecurityAttributesToken:dword
;    extrn '__imp__SeSetSecurityAttributesTokenEx@??' as SeSetSecurityAttributesTokenEx:dword
;    extrn '__imp__SeSrpAccessCheck@??' as SeSrpAccessCheck:dword
;    extrn '__imp__SeSystemDefaultDacl@??' as SeSystemDefaultDacl:dword
;    extrn '__imp__SeSystemDefaultSd@??' as SeSystemDefaultSd:dword
;    extrn '__imp__SeTokenFromAccessInformation@??' as SeTokenFromAccessInformation:dword
;    extrn '__imp__SeUnregisterImageVerificationCallback@??' as SeUnregisterImageVerificationCallback:dword
;    extrn '__imp__SkAcquirePushLockExclusive@??' as SkAcquirePushLockExclusive:dword
;    extrn '__imp__SkAllocatePool@??' as SkAllocatePool:dword
;    extrn '__imp__SkFreePool@??' as SkFreePool:dword
;    extrn '__imp__SkInitializePushLock@??' as SkInitializePushLock:dword
;    extrn '__imp__SkIsSecureKernel@??' as SkIsSecureKernel:dword
;    extrn '__imp__SkQuerySecureKernelInformation@??' as SkQuerySecureKernelInformation:dword
;    extrn '__imp__SkReleasePushLockExclusive@??' as SkReleasePushLockExclusive:dword
;    extrn '__imp__sprintf@??' as sprintf:dword
;    extrn '__imp__sprintf_s@??' as sprintf_s:dword
;    extrn '__imp__sqrt@??' as sqrt:dword
;    extrn '__imp__sqrtf@??' as sqrtf:dword
;    extrn '__imp__srand@??' as srand:dword
;    extrn '__imp__sscanf_s@??' as sscanf_s:dword
;    extrn '__imp__strcat@??' as strcat:dword
;    extrn '__imp__strcat_s@??' as strcat_s:dword
;    extrn '__imp__strchr@??' as strchr:dword
;    extrn '__imp__strcmp@??' as strcmp:dword
;    extrn '__imp__strcpy@??' as strcpy:dword
;    extrn '__imp__strcpy_s@??' as strcpy_s:dword
;    extrn '__imp__strlen@??' as strlen:dword
;    extrn '__imp__strncat@??' as strncat:dword
;    extrn '__imp__strncat_s@??' as strncat_s:dword
;    extrn '__imp__strncmp@??' as strncmp:dword
;    extrn '__imp__strncpy@??' as strncpy:dword
;    extrn '__imp__strncpy_s@??' as strncpy_s:dword
;    extrn '__imp__strnlen@??' as strnlen:dword
;    extrn '__imp__strrchr@??' as strrchr:dword
;    extrn '__imp__strspn@??' as strspn:dword
;    extrn '__imp__strstr@??' as strstr:dword
;    extrn '__imp__strtok_s@??' as strtok_s:dword
;    extrn '__imp__swprintf@??' as swprintf:dword
;    extrn '__imp__swprintf_s@??' as swprintf_s:dword
;    extrn '__imp__swscanf_s@??' as swscanf_s:dword
;    extrn '__imp__TmCancelPropagationRequest@??' as TmCancelPropagationRequest:dword
;    extrn '__imp__TmCurrentTransaction@??' as TmCurrentTransaction:dword
;    extrn '__imp__TmEndPropagationRequest@??' as TmEndPropagationRequest:dword
;    extrn '__imp__TmEnlistmentObjectType@??' as TmEnlistmentObjectType:dword
;    extrn '__imp__TmFreezeTransactions@??' as TmFreezeTransactions:dword
;    extrn '__imp__TmInitializeResourceManager@??' as TmInitializeResourceManager:dword
;    extrn '__imp__TmInitializeTransaction@??' as TmInitializeTransaction:dword
;    extrn '__imp__TmInitSystem@??' as TmInitSystem:dword
;    extrn '__imp__TmInitSystemPhase2@??' as TmInitSystemPhase2:dword
;    extrn '__imp__TmIsKTMCommitCoordinator@??' as TmIsKTMCommitCoordinator:dword
;    extrn '__imp__TmpIsKTMCommitCoordinator@??' as TmpIsKTMCommitCoordinator:dword
;    extrn '__imp__TmPropagationComplete@??' as TmPropagationComplete:dword
;    extrn '__imp__TmPropagationFailed@??' as TmPropagationFailed:dword
;    extrn '__imp__TmResourceManagerObjectType@??' as TmResourceManagerObjectType:dword
;    extrn '__imp__TmSetCurrentTransaction@??' as TmSetCurrentTransaction:dword
;    extrn '__imp__TmThawTransactions@??' as TmThawTransactions:dword
;    extrn '__imp__TmTransactionManagerObjectType@??' as TmTransactionManagerObjectType:dword
;    extrn '__imp__TmTransactionObjectType@??' as TmTransactionObjectType:dword
;    extrn '__imp__VfCheckNxPagePriority@??' as VfCheckNxPagePriority:dword
;    extrn '__imp__VfCheckNxPageProtection@??' as VfCheckNxPageProtection:dword
;    extrn '__imp__VfCheckNxPoolType@??' as VfCheckNxPoolType:dword
;    extrn '__imp__VfFailDeviceNode@??' as VfFailDeviceNode:dword
;    extrn '__imp__VfFailDriver@??' as VfFailDriver:dword
;    extrn '__imp__VfFailSystemBIOS@??' as VfFailSystemBIOS:dword
;    extrn '__imp__VfInsertContext@??' as VfInsertContext:dword
;    extrn '__imp__VfQueryDeviceContext@??' as VfQueryDeviceContext:dword
;    extrn '__imp__VfQueryDispatchTable@??' as VfQueryDispatchTable:dword
;    extrn '__imp__VfQueryDriverContext@??' as VfQueryDriverContext:dword
;    extrn '__imp__VfQueryIrpContext@??' as VfQueryIrpContext:dword
;    extrn '__imp__VfQueryThreadContext@??' as VfQueryThreadContext:dword
;    extrn '__imp__VfRemoveContext@??' as VfRemoveContext:dword
;    extrn '__imp__VmAccessFault@??' as VmAccessFault:dword
;    extrn '__imp__VmCreateMemoryRange@??' as VmCreateMemoryRange:dword
;    extrn '__imp__VmDeleteMemoryRange@??' as VmDeleteMemoryRange:dword
;    extrn '__imp__VslExchangeEntropy@??' as VslExchangeEntropy:dword
;    extrn '__imp__VslRetrieveMailbox@??' as VslRetrieveMailbox:dword
;    extrn '__imp__WheaAttemptPhysicalPageOffline@??' as WheaAttemptPhysicalPageOffline:dword
;    extrn '__imp__WheaConfigureErrorSource@??' as WheaConfigureErrorSource:dword
;    extrn '__imp__WheaDeferredRecoveryService@??' as WheaDeferredRecoveryService:dword
;    extrn '__imp__WheaGetErrorSource@??' as WheaGetErrorSource:dword
;    extrn '__imp__WheaInitializeDeferredRecoveryObject@??' as WheaInitializeDeferredRecoveryObject:dword
;    extrn '__imp__WheaInitializeRecordHeader@??' as WheaInitializeRecordHeader:dword
;    extrn '__imp__WheaRegisterErrSrcInitializer@??' as WheaRegisterErrSrcInitializer:dword
;    extrn '__imp__WheaReportHwError@??' as WheaReportHwError:dword
;    extrn '__imp__WheaRequestDeferredRecovery@??' as WheaRequestDeferredRecovery:dword
;    extrn '__imp__ZwAlpcConnectPortEx@??' as ZwAlpcConnectPortEx:dword
;    extrn '__imp__ZwCreateWnfStateName@??' as ZwCreateWnfStateName:dword
;    extrn '__imp__ZwDeleteDriverEntry@??' as ZwDeleteDriverEntry:dword
;    extrn '__imp__ZwDeleteWnfStateData@??' as ZwDeleteWnfStateData:dword
;    extrn '__imp__ZwDeleteWnfStateName@??' as ZwDeleteWnfStateName:dword
;    extrn '__imp__ZwNotifyChangeSession@??' as ZwNotifyChangeSession:dword
;    extrn '__imp__ZwQueryLicenseValue@??' as ZwQueryLicenseValue:dword
;    extrn '__imp__ZwQueryWnfStateData@??' as ZwQueryWnfStateData:dword
;    extrn '__imp__ZwQueryWnfStateNameInformation@??' as ZwQueryWnfStateNameInformation:dword
;    extrn '__imp__ZwSetCachedSigningLevel@??' as ZwSetCachedSigningLevel:dword
;    extrn '__imp__ZwSetInformationVirtualMemory@??' as ZwSetInformationVirtualMemory:dword
;    extrn '__imp__ZwUpdateWnfStateData@??' as ZwUpdateWnfStateData:dword
;    extrn '__imp___abnormal_termination@??' as _abnormal_termination:dword
;    extrn '__imp___alloca_probe@??' as _alloca_probe:dword
;    extrn '__imp___alloca_probe_16@??' as _alloca_probe_16:dword
;    extrn '__imp___alloca_probe_8@??' as _alloca_probe_8:dword
;    extrn '__imp___CIcos@??' as _CIcos:dword
;    extrn '__imp___CIsin@??' as _CIsin:dword
;    extrn '__imp___CIsqrt@??' as _CIsqrt:dword
;    extrn '__imp___local_unwind@??' as local_unwind:dword
;    if ~defined __imp____misaligned_access
;        extrn '__imp____misaligned_access@??' as misaligned_access:dword
;    end if
;    extrn '__imp___snscanf_s@??' as _snscanf_s:dword
;    extrn '__imp___snwprintf@??' as _snwprintf:dword
;    extrn '__imp___snwprintf_s@??' as _snwprintf_s:dword
;    extrn '__imp___snwscanf_s@??' as _snwscanf_s:dword
;end if

end if ;NTOSKRNL_INC
