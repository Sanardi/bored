; ====================================================;
;                                                     ;
;      hal.inc for EC v2 SolAsm visual projects       ;
;                   (version 1.0.0)                   ;
;                                                     ;
;            Copyright © Ramon Sala - 2018            ;
;                                                     ;
; ====================================================;

#ifndef HAL_INC
HAL_INC equ 1

#if COFF_FORMAT == 1
    from_lib hal.lib
#else
    from_dll hal.dll
#endif

#ifdef APP_WIN64
    #if NTDDI_VERSION >= NTDDI_VISTA
        import ExAcquireFastMutex
        import ExReleaseFastMutex
        import ExTryToAcquireFastMutex
    #endif
    import HalAcquireDisplayOwnership
    import HalAdjustResourceList
    import HalAllocateAdapterChannel
    import HalAllocateCommonBuffer
    import HalAllocateCrashDumpRegisters
    #if NTDDI_VERSION >= NTDDI_WIN7
        import HalAllocateHardwareCounters
    #endif
    import HalAllProcessorsStarted
    import HalAssignSlotResources
    #if NTDDI_VERSION == NTDDI_VISTA
        import HalBeginSystemInterrupt
    #endif
    #if NTDDI_VERSION >= NTDDI_VISTA
        import HalBugCheckSystem
    #endif
    import HalCalibratePerformanceCounter
    #if NTDDI_VERSION == NTDDI_WINXP
        import HalCallBios
    #endif
    #if NTDDI_VERSION >= NTDDI_VISTA
        import HalConvertDeviceIdtToIrql
    #endif
    #if NTDDI_VERSION >= NTDDI_VISTA
        import HalDisableInterrupt
    #endif
    #if NTDDI_VERSION == NTDDI_WINXP
        import HalDisableSystemInterrupt
    #endif
    import HalDisplayString
    #if NTDDI_VERSION >= NTDDI_VISTA
        import HalEnableInterrupt
    #endif
    #if NTDDI_VERSION == NTDDI_VISTA
        import HalEnableSystemInterrupt
        import HalEndSystemInterrupt
    #endif
    import HalFlushCommonBuffer
    import HalFreeCommonBuffer
    #if NTDDI_VERSION >= NTDDI_WIN7
        import HalFreeHardwareCounters
    #endif
    import HalGetAdapter
    import HalGetBusData
    import HalGetBusDataByOffset
    import HalGetEnvironmentVariable
    import HalGetInterruptVector
    import HalHandleNMI
    #if NTDDI_VERSION >= NTDDI_VISTA
        import HalInitializeBios
    #endif
    import HalInitializeProcessor
    import HalInitSystem
    import HalMakeBeep
    #if NTDDI_VERSION == NTDDI_WIN7
        import HalMcUpdateReadPCIConfig
    #endif
    import HalProcessorIdle
    import HalQueryDisplayParameters
    #if NTDDI_VERSION >= NTDDI_VISTA
        import HalQueryEnvironmentVariableInfoEx
        import HalQueryMaximumProcessorCount
    #endif
    import HalQueryRealTimeClock
    import HalReadDmaCounter
    #if NTDDI_VERSION >= NTDDI_VISTA
        import HalRegisterDynamicProcessor
    #endif
    import HalReportResourceUsage
    import HalRequestIpi
    import HalReturnToFirmware
    import HalSetBusData
    import HalSetBusDataByOffset
    import HalSetDisplayParameters
    import HalSetEnvironmentVariable
    import HalSetProfileInterval
    import HalSetRealTimeClock
    #if NTDDI_VERSION <= NTDDI_WIN8
        import HalSetTimeIncrement
    #endif
    import HalStartNextProcessor
    import HalStartProfileInterrupt
    import HalStopProfileInterrupt
    import HalSystemVectorDispatchEntry
    import HalTranslateBusAddress
    #if NTDDI_VERSION <= NTDDI_VISTA
        import IoAssignDriveLetters
    #endif
    import IoFlushAdapterBuffers
    import IoFreeAdapterChannel
    import IoFreeMapRegisters
    import IoMapTransfer
    import IoReadPartitionTable
    import IoSetPartitionInformation
    import IoWritePartitionTable
    import KdComPortInUse
    #if NTDDI_VERSION == NTDDI_VISTA
        import KeAcquireSpinLock
    #endif
    import KeFlushWriteBuffer
    import KeGetCurrentIrql
    #if NTDDI_VERSION == NTDDI_VISTA
        import KeLowerIrql
        import KeRaiseIrql
        import KeRaiseIrqlToDpcLevel
        import KeRaiseIrqlToSynchLevel
        import KeReleaseInStackQueuedSpinLock
        import KeReleaseSpinLock
    #endif
    import KeQueryPerformanceCounter
    import KeStallExecutionProcessor
    #if NTDDI_VERSION == NTDDI_VISTA
        import READ_PORT_BUFFER_UCHAR
        import READ_PORT_BUFFER_ULONG
        import READ_PORT_BUFFER_USHORT
        import READ_PORT_UCHAR
        import READ_PORT_ULONG
        import READ_PORT_USHORT
        import WRITE_PORT_BUFFER_UCHAR
        import WRITE_PORT_BUFFER_ULONG
        import WRITE_PORT_BUFFER_USHORT
        import WRITE_PORT_UCHAR
        import WRITE_PORT_ULONG
        import WRITE_PORT_USHORT
    #endif
    #if NTDDI_VERSION >= NTDDI_VISTA
        import x86BiosAllocateBuffer
        import x86BiosCall
    #endif
    #if NTDDI_VERSION == NTDDI_WINXP
        import x86BiosExecuteInterrupt
    #endif
    #if NTDDI_VERSION >= NTDDI_VISTA
        import x86BiosFreeBuffer
        import x86BiosReadMemory
        import x86BiosWriteMemory
    #endif
    #if NTDDI_VERSION == NTDDI_WINXP
        import x86BiosInitializeBiosEx
        import x86BiosTranslateAddress
    #endif
#else
    extern HalAcquireDisplayOwnership alias _HalAcquireDisplayOwnership@4
    extern HalAdjustResourceList alias _HalAdjustResourceList@4
    extern HalAllProcessorsStarted alias _HalAllProcessorsStarted@0
    extern HalAllocateAdapterChannel alias _HalAllocateAdapterChannel@16
    extern HalAllocateCommonBuffer alias _HalAllocateCommonBuffer@16
    extern HalAllocateCrashDumpRegisters alias _HalAllocateCrashDumpRegisters@8
    extern HalAssignSlotResources alias _HalAssignSlotResources@32
    extern HalBeginSystemInterrupt alias _HalBeginSystemInterrupt@12
    extern HalCalibratePerformanceCounter alias _HalCalibratePerformanceCounter@12
    extern HalDisableSystemInterrupt alias _HalDisableSystemInterrupt@8
    extern HalDisplayString alias _HalDisplayString@4
    extern HalEnableSystemInterrupt alias _HalEnableSystemInterrupt@12
    extern HalEndSystemInterrupt alias _HalEndSystemInterrupt@8
    extern HalFlushCommonBuffer alias _HalFlushCommonBuffer@20
    extern HalFreeCommonBuffer alias _HalFreeCommonBuffer@24
    extern HalGetAdapter alias _HalGetAdapter@8
    extern HalGetBusData alias _HalGetBusData@20
    extern HalGetBusDataByOffset alias _HalGetBusDataByOffset@24
    extern HalGetEnvironmentVariable alias _HalGetEnvironmentVariable@12
    extern HalGetInterruptVector alias _HalGetInterruptVector@24
    extern HalHandleNMI alias _HalHandleNMI@4
    extern HalInitSystem alias _HalInitSystem@8
    extern HalInitializeProcessor alias _HalInitializeProcessor@8
    extern HalMakeBeep alias _HalMakeBeep@4
    extern HalProcessorIdle alias _HalProcessorIdle@0
    extern HalQueryDisplayParameters alias _HalQueryDisplayParameters@16
    extern HalQueryRealTimeClock alias _HalQueryRealTimeClock@4
    extern HalReadDmaCounter alias _HalReadDmaCounter@4
    extern HalReportResourceUsage alias _HalReportResourceUsage@0
    extern HalRequestIpi alias _HalRequestIpi@4
    extern HalReturnToFirmware alias _HalReturnToFirmware@4
    extern HalSetBusData alias _HalSetBusData@20
    extern HalSetBusDataByOffset alias _HalSetBusDataByOffset@24
    extern HalSetDisplayParameters alias _HalSetDisplayParameters@8
    extern HalSetEnvironmentVariable alias _HalSetEnvironmentVariable@8
    extern HalSetProfileInterval alias _HalSetProfileInterval@4
    extern HalSetRealTimeClock alias _HalSetRealTimeClock@4
    extern HalSetTimeIncrement alias _HalSetTimeIncrement@4
    extern HalStartNextProcessor alias _HalStartNextProcessor@8
    extern HalStartProfileInterrupt alias _HalStartProfileInterrupt@4
    extern HalStopProfileInterrupt alias _HalStopProfileInterrupt@4
    extern HalTranslateBusAddress alias _HalTranslateBusAddress@24
    extern IoFlushAdapterBuffers alias _IoFlushAdapterBuffers@24
    extern IoFreeAdapterChannel alias _IoFreeAdapterChannel@4
    extern IoFreeMapRegisters alias _IoFreeMapRegisters@12
    extern IoMapTransfer alias _IoMapTransfer@24
    extern KdComPortInUse alias _KdComPortInUse@4
    extern KeAcquireSpinLock alias _KeAcquireSpinLock@8
    extern KeFlushWriteBuffer alias _KeFlushWriteBuffer@0
    extern KeGetCurrentIrql alias _KeGetCurrentIrql@0
    extern KeLowerIrql alias _KeLowerIrql@4
    extern KeQueryPerformanceCounter alias _KeQueryPerformanceCounter@4
    extern KeRaiseIrql alias _KeRaiseIrql@8
    extern KeRaiseIrqlToDpcLevel alias _KeRaiseIrqlToDpcLevel@0
    extern KeRaiseIrqlToSynchLevel alias _KeRaiseIrqlToSynchLevel@0
    extern KeReleaseSpinLock alias _KeReleaseSpinLock@8
    extern KeStallExecutionProcessor alias _KeStallExecutionProcessor@4
    extern READ_PORT_BUFFER_UCHAR alias _READ_PORT_BUFFER_UCHAR@12
    extern READ_PORT_BUFFER_ULONG alias _READ_PORT_BUFFER_ULONG@12
    extern READ_PORT_BUFFER_USHORT alias _READ_PORT_BUFFER_USHORT@12
    extern READ_PORT_UCHAR alias _READ_PORT_UCHAR@4
    extern READ_PORT_ULONG alias _READ_PORT_ULONG@4
    extern READ_PORT_USHORT alias _READ_PORT_USHORT@4
    extern WRITE_PORT_BUFFER_UCHAR alias _WRITE_PORT_BUFFER_UCHAR@12
    extern WRITE_PORT_BUFFER_ULONG alias _WRITE_PORT_BUFFER_ULONG@12
    extern WRITE_PORT_BUFFER_USHORT alias _WRITE_PORT_BUFFER_USHORT@12
    extern WRITE_PORT_UCHAR alias _WRITE_PORT_UCHAR@8
    extern WRITE_PORT_ULONG alias _WRITE_PORT_ULONG@8
    extern WRITE_PORT_USHORT alias _WRITE_PORT_USHORT@8
#endif

;======================= Undocumented functions (unknown arguments) =======================;
;#ifdef APP_WIN64
;    #if NTDDI_VERSION >= NTDDI_WIN8
;        import HalAcpiGetTableEx
;        import HalDmaAllocateCrashDumpRegistersEx
;        import HalDmaFreeCrashDumpRegistersEx
;        import HalRequestIpiSpecifyVector
;        import KdHvComPortInUse
;    #endif
;    #if NTDDI_VERSION == NTDDI_VISTA
;        import HalClearSoftwareInterrupt
;        import KeReleaseQueuedSpinLock
;    #endif
;    #if NTDDI_VERSION >= NTDDI_VISTA
;        import HalEnumerateEnvironmentVariablesEx
;        import HalGetEnvironmentVariableEx
;        import HalGetInterruptTargetInformation
;        import HalGetMessageRoutingInfo
;        import HalGetProcessorIdByNtNumber
;        import HalGetVectorInput
;        import HalInitializeOnResume
;        import HalInitializeOnResume
;        import HalIsHyperThreadingEnabled
;        import HalStartDynamicProcessor
;    #endif
;    #if NTDDI_VERSION != NTDDI_VISTA
;        import HalEnumerateProcessors
;        import HalSendNMI
;        import HalSendSoftwareInterrupt
;    #endif
;    #if NTDDI_VERSION >= NTDDI_WIN7
;        import HalGetMemoryCachingRequirements
;        import HalPerformEndOfInterrupt
;        import HalRequestClockInterrupt
;        import HalRequestDeferredRecoveryServiceInterrupt
;        import HalHandleMcheck
;    #endif
;    #if NTDDI_VERSION == NTDDI_WINXP
;        import HalHandleMcheck
;    #endif
;    import HalRequestSoftwareInterrupt
;#else
;    #if NTDDI_VERSION >= NTDDI_WIN8
;        extern HalAcpiGetTableEx alias _HalAcpiGetTableEx@??
;        extern HalDmaAllocateCrashDumpRegistersEx alias _HalDmaAllocateCrashDumpRegistersEx@??
;        extern HalDmaFreeCrashDumpRegistersEx alias _HalDmaFreeCrashDumpRegistersEx@??
;        extern HalRequestIpiSpecifyVector alias _HalRequestIpiSpecifyVector@??
;        extern KdHvComPortInUse alias _KdHvComPortInUse@??
;    #endif
;    #if NTDDI_VERSION == NTDDI_VISTA
;        extern HalClearSoftwareInterrupt alias _HalClearSoftwareInterrupt@??
;        extern KeReleaseQueuedSpinLock alias _KeReleaseQueuedSpinLock@??
;    #endif
;    #if NTDDI_VERSION >= NTDDI_VISTA
;        extern HalEnumerateEnvironmentVariablesEx alias _HalEnumerateEnvironmentVariablesEx@??
;        extern HalGetEnvironmentVariableEx alias _HalGetEnvironmentVariableEx@??
;        extern HalGetInterruptTargetInformation alias _HalGetInterruptTargetInformation@??
;        extern HalGetMessageRoutingInfo alias _HalGetMessageRoutingInfo@??
;        extern HalGetProcessorIdByNtNumber alias _HalGetProcessorIdByNtNumber@??
;        extern HalGetVectorInput alias _HalGetVectorInput@??
;        extern HalInitializeOnResume alias _HalInitializeOnResume@??
;        extern HalInitializeOnResume alias _HalInitializeOnResume@??
;        extern HalIsHyperThreadingEnabled alias _HalIsHyperThreadingEnabled@??
;        extern HalStartDynamicProcessor alias _HalStartDynamicProcessor@??
;    #endif
;    #if NTDDI_VERSION != NTDDI_VISTA
;        extern HalEnumerateProcessors alias _HalEnumerateProcessors@??
;        extern HalSendNMI alias _HalSendNMI@??
;        extern HalSendSoftwareInterrupt alias _HalSendSoftwareInterrupt@??
;    #endif
;    #if NTDDI_VERSION >= NTDDI_WIN7
;        extern HalGetMemoryCachingRequirements alias _HalGetMemoryCachingRequirements@??
;        extern HalPerformEndOfInterrupt alias _HalPerformEndOfInterrupt@??
;        extern HalRequestClockInterrupt alias _HalRequestClockInterrupt@??
;        extern HalRequestDeferredRecoveryServiceInterrupt alias _HalRequestDeferredRecoveryServiceInterrupt@??
;        extern HalHandleMcheck alias _HalHandleMcheck@??
;    #endif
;    #if NTDDI_VERSION == NTDDI_WINXP
;        extern HalHandleMcheck alias _HalHandleMcheck@??
;    #endif
;    extern HalRequestSoftwareInterrupt alias _HalRequestSoftwareInterrupt@??
;#endif

#endif ;HAL_INC
