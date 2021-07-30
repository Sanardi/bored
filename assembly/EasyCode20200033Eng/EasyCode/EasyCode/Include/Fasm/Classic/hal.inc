; ====================================================;
;                                                     ;
;       hal.inc for EC v2 Fasm classic projects       ;
;                   (version 1.0.0)                   ;
;                                                     ;
;            Copyright © Ramon Sala - 2018            ;
;                                                     ;
; ====================================================;

if ~defined HAL_INC
define HAL_INC 1

import hal,\
    ExAcquireFastMutex,'ExAcquireFastMutex',\
    ExReleaseFastMutex,'ExReleaseFastMutex',\
    ExTryToAcquireFastMutex,'ExTryToAcquireFastMutex',\
    HalAcpiGetTableEx,'HalAcpiGetTableEx',\
    HalAcquireDisplayOwnership,'HalAcquireDisplayOwnership',\
    HalAdjustResourceList,'HalAdjustResourceList',\
    HalAllocateAdapterChannel,'HalAllocateAdapterChannel',\
    HalAllocateCommonBuffer,'HalAllocateCommonBuffer',\
    HalAllocateCrashDumpRegisters,'HalAllocateCrashDumpRegisters',\
    HalAllocateHardwareCounters,'HalAllocateHardwareCounters',\
    HalAllProcessorsStarted,'HalAllProcessorsStarted',\
    HalAssignSlotResources,'HalAssignSlotResources',\
    HalBeginSystemInterrupt,'HalBeginSystemInterrupt',\
    HalBugCheckSystem,'HalBugCheckSystem',\
    HalCalibratePerformanceCounter,'HalCalibratePerformanceCounter',\
    HalCallBios,'HalCallBios',\
    HalClearSoftwareInterrupt,'HalClearSoftwareInterrupt',\
    HalConvertDeviceIdtToIrql,'HalConvertDeviceIdtToIrql',\
    HalDisableSystemInterrupt,'HalDisableSystemInterrupt',\
    HalDisableInterrupt,'HalDisableInterrupt',\
    HalDisplayString,'HalDisplayString',\
    HalDmaAllocateCrashDumpRegistersEx,'HalDmaAllocateCrashDumpRegistersEx',\
    HalDmaFreeCrashDumpRegistersEx,'HalDmaFreeCrashDumpRegistersEx',\
    HalEnableInterrupt,'HalEnableInterrupt',\
    HalEnableSystemInterrupt,'HalEnableSystemInterrupt',\
    HalEndSystemInterrupt,'HalEndSystemInterrupt',\
    HalEnumerateEnvironmentVariablesEx,'HalEnumerateEnvironmentVariablesEx',\
    HalEnumerateProcessors,'HalEnumerateProcessors',\
    HalFlushCommonBuffer,'HalFlushCommonBuffer',\
    HalFreeCommonBuffer,'HalFreeCommonBuffer',\
    HalFreeHardwareCounters,'HalFreeHardwareCounters',\
    HalGetAdapter,'HalGetAdapter',\
    HalGetBusData,'HalGetBusData',\
    HalGetBusDataByOffset,'HalGetBusDataByOffset',\
    HalGetEnvironmentVariable,'HalGetEnvironmentVariable',\
    HalGetEnvironmentVariableEx,'HalGetEnvironmentVariableEx',\
    HalGetInterruptTargetInformation,'HalGetInterruptTargetInformation',\
    HalGetInterruptVector,'HalGetInterruptVector',\
    HalGetMemoryCachingRequirements,'HalGetMemoryCachingRequirements',\
    HalGetMessageRoutingInfo,'HalGetMessageRoutingInfo',\
    HalGetProcessorIdByNtNumber,'HalGetProcessorIdByNtNumber',\
    HalGetVectorInput,'HalGetVectorInput',\
    HalHandleMcheck,'HalHandleMcheck',\
    HalHandleNMI,'HalHandleNMI',\
    HalInitializeBios,'HalInitializeBios',\
    HalInitializeOnResume,'HalInitializeOnResume',\
    HalInitializeProcessor,'HalInitializeProcessor',\
    HalInitSystem,'HalInitSystem',\
    HalIsHyperThreadingEnabled,'HalIsHyperThreadingEnabled',\
    HalMakeBeep,'HalMakeBeep',\
    HalMcUpdateReadPCIConfig,'HalMcUpdateReadPCIConfig',\
    HalPerformEndOfInterrupt,'HalPerformEndOfInterrupt',\
    HalProcessorIdle,'HalProcessorIdle',\
    HalQueryDisplayParameters,'HalQueryDisplayParameters',\
    HalQueryEnvironmentVariableInfoEx,'HalQueryEnvironmentVariableInfoEx',\
    HalQueryMaximumProcessorCount,'HalQueryMaximumProcessorCount',\
    HalQueryRealTimeClock,'HalQueryRealTimeClock',\
    HalReadDmaCounter,'HalReadDmaCounter',\
    HalRegisterDynamicProcessor,'HalRegisterDynamicProcessor',\
    HalRegisterErrataCallbacks,'HalRegisterErrataCallbacks',\
    HalReportResourceUsage,'HalReportResourceUsage',\
    HalRequestClockInterrupt,'HalRequestClockInterrupt',\
    HalRequestDeferredRecoveryServiceInterrupt,'HalRequestDeferredRecoveryServiceInterrupt',\
    HalRequestIpi,'HalRequestIpi',\
    HalRequestIpiSpecifyVector,'HalRequestIpiSpecifyVector',\
    HalRequestSoftwareInterrupt,'HalRequestSoftwareInterrupt',\
    HalReturnToFirmware,'HalReturnToFirmware',\
    HalSendNMI,'HalSendNMI',\
    HalSendSoftwareInterrupt,'HalSendSoftwareInterrupt',\
    HalSetBusData,'HalSetBusData',\
    HalSetBusDataByOffset,'HalSetBusDataByOffset',\
    HalSetDisplayParameters,'HalSetDisplayParameters',\
    HalSetEnvironmentVariable,'HalSetEnvironmentVariable',\
    HalSetProfileInterval,'HalSetProfileInterval',\
    HalSetRealTimeClock,'HalSetRealTimeClock',\
    HalSetTimeIncrement,'HalSetTimeIncrement',\
    HalStartDynamicProcessor,'HalStartDynamicProcessor',\
    HalStartNextProcessor,'HalStartNextProcessor',\
    HalStartProfileInterrupt,'HalStartProfileInterrupt',\
    HalStopProfileInterrupt,'HalStopProfileInterrupt',\
    HalSystemVectorDispatchEntry,'HalSystemVectorDispatchEntry',\
    HalTranslateBusAddress,'HalTranslateBusAddress',\
    IoAssignDriveLetters,'IoAssignDriveLetters',\
    IoFlushAdapterBuffers,'IoFlushAdapterBuffers',\
    IoFreeAdapterChannel,'IoFreeAdapterChannel',\
    IoFreeMapRegisters,'IoFreeMapRegisters',\
    IoMapTransfer,'IoMapTransfer',\
    IoReadPartitionTable,'IoReadPartitionTable',\
    IoSetPartitionInformation,'IoSetPartitionInformation',\
    IoWritePartitionTable,'IoWritePartitionTable',\
    KdComPortInUse,'KdComPortInUse',\
    KdHvComPortInUse,'KdHvComPortInUse',\
    KeAcquireInStackQueuedSpinLock,'KeAcquireInStackQueuedSpinLock',\
    KeAcquireInStackQueuedSpinLockRaiseToSynch,'KeAcquireInStackQueuedSpinLockRaiseToSynch',\
    KeAcquireQueuedSpinLock,'KeAcquireQueuedSpinLock',\
    KeAcquireQueuedSpinLockRaiseToSynch,'KeAcquireQueuedSpinLockRaiseToSynch',\
    KeAcquireSpinLock,'KeAcquireSpinLock',\
    KeAcquireSpinLockRaiseToSynch,'KeAcquireSpinLockRaiseToSynch',\
    KeFlushWriteBuffer,'KeFlushWriteBuffer',\
    KeGetCurrentIrql,'KeGetCurrentIrql',\
    KeLowerIrql,'KeLowerIrql',\
    KeQueryPerformanceCounter,'KeQueryPerformanceCounter',\
    KeRaiseIrql,'KeRaiseIrql',\
    KeRaiseIrqlToDpcLevel,'KeRaiseIrqlToDpcLevel',\
    KeRaiseIrqlToSynchLevel,'KeRaiseIrqlToSynchLevel',\
    KeReleaseInStackQueuedSpinLock,'KeReleaseInStackQueuedSpinLock',\
    KeReleaseQueuedSpinLock,'KeReleaseQueuedSpinLock',\
    KeReleaseSpinLock,'KeReleaseSpinLock',\
    KeStallExecutionProcessor,'KeStallExecutionProcessor',\
    READ_PORT_BUFFER_UCHAR,'READ_PORT_BUFFER_UCHAR',\
    READ_PORT_BUFFER_ULONG,'READ_PORT_BUFFER_ULONG',\
    READ_PORT_BUFFER_USHORT,'READ_PORT_BUFFER_USHORT',\
    READ_PORT_UCHAR,'READ_PORT_UCHAR',\
    READ_PORT_ULONG,'READ_PORT_ULONG',\
    READ_PORT_USHORT,'READ_PORT_USHORT',\
    WRITE_PORT_BUFFER_UCHAR,'WRITE_PORT_BUFFER_UCHAR',\
    WRITE_PORT_BUFFER_ULONG,'WRITE_PORT_BUFFER_ULONG',\
    WRITE_PORT_BUFFER_USHORT,'WRITE_PORT_BUFFER_USHORT',\
    WRITE_PORT_UCHAR,'WRITE_PORT_UCHAR',\
    WRITE_PORT_ULONG,'WRITE_PORT_ULONG',\
    WRITE_PORT_USHORT,'WRITE_PORT_USHORT',\
    x86BiosAllocateBuffer,'x86BiosAllocateBuffer',\
    x86BiosCall,'x86BiosCall',\
    x86BiosExecuteInterrupt,'x86BiosExecuteInterrupt',\
    x86BiosFreeBuffer,'x86BiosFreeBuffer',\
    x86BiosInitializeBiosEx,'x86BiosInitializeBiosEx',\
    x86BiosReadMemory,'x86BiosReadMemory',\
    x86BiosTranslateAddress,'x86BiosTranslateAddress',\
    x86BiosWriteMemory,'x86BiosWriteMemory'

end if ;HAL_INC
