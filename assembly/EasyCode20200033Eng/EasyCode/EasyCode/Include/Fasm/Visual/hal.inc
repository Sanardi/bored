; ====================================================;
;                                                     ;
;       hal.inc for EC v2 Fasm visual projects        ;
;                   (version 1.0.0)                   ;
;                                                     ;
;            Copyright © Ramon Sala - 2018            ;
;                                                     ;
; ====================================================;

if ~defined HAL_INC
define HAL_INC 1

if defined APP_WIN64
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_ExAcquireFastMutex' as ExAcquireFastMutex:qword
        extrn '__imp_ExReleaseFastMutex' as ExReleaseFastMutex:qword
        extrn '__imp_ExTryToAcquireFastMutex' as ExTryToAcquireFastMutex:qword
    end if
    extrn '__imp_HalAcquireDisplayOwnership' as HalAcquireDisplayOwnership:qword
    extrn '__imp_HalAdjustResourceList' as HalAdjustResourceList:qword
    extrn '__imp_HalAllocateAdapterChannel' as HalAllocateAdapterChannel:qword
    extrn '__imp_HalAllocateCommonBuffer' as HalAllocateCommonBuffer:qword
    extrn '__imp_HalAllocateCrashDumpRegisters' as HalAllocateCrashDumpRegisters:qword
    if (NTDDI_VERSION >= NTDDI_WIN7)
         extrn '__imp_HalAllocateHardwareCounters' as HalAllocateHardwareCounters:qword
    end if
    extrn '__imp_HalAllProcessorsStarted' as HalAllProcessorsStarted:qword
    extrn '__imp_HalAssignSlotResources' as HalAssignSlotResources:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp_HalBeginSystemInterrupt' as HalBeginSystemInterrupt:qword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
         extrn '__imp_HalBugCheckSystem' as HalBugCheckSystem:qword
    end if
    extrn '__imp_HalCalibratePerformanceCounter' as HalCalibratePerformanceCounter:qword
    if (NTDDI_VERSION = NTDDI_WINXP)
         extrn '__imp_HalCallBios' as HalCallBios:qword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
         extrn '__imp_HalConvertDeviceIdtToIrql' as HalDisableSystemInterrupt:qword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_HalDisableInterrupt' as HalDisableInterrupt:qword
    end if
    if (NTDDI_VERSION = NTDDI_WINXP)
         extrn '__imp_HalDisableSystemInterrupt' as HalDisableSystemInterrupt:qword
    end if
    extrn '__imp_HalDisplayString' as HalDisplayString:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
         extrn '__imp_HalEnableInterrupt' as HalEnableInterrupt:qword
    end if
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp_HalEnableSystemInterrupt' as HalEnableSystemInterrupt:qword
        extrn '__imp_HalEndSystemInterrupt' as HalEndSystemInterrupt:qword
    end if
    extrn '__imp_HalFlushCommonBuffer' as HalFlushCommonBuffer:qword
    extrn '__imp_HalFreeCommonBuffer' as HalFreeCommonBuffer:qword
    if (NTDDI_VERSION = NTDDI_WIN7)
         extrn '__imp_HalFreeHardwareCounters' as HalFreeHardwareCounters:qword
    end if
    extrn '__imp_HalGetAdapter' as HalGetAdapter:qword
    extrn '__imp_HalGetBusData' as HalGetBusData:qword
    extrn '__imp_HalGetBusDataByOffset' as HalGetBusDataByOffset:qword
    extrn '__imp_HalGetEnvironmentVariable' as HalGetEnvironmentVariable:qword
    extrn '__imp_HalGetInterruptVector' as HalGetInterruptVector:qword
    extrn '__imp_HalHandleNMI' as HalHandleNMI:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
         extrn '__imp_HalInitializeBios' as HalInitializeBios:qword
    end if
    extrn '__imp_HalInitializeProcessor' as HalInitializeProcessor:qword
    extrn '__imp_HalInitSystem' as HalInitSystem:qword
    extrn '__imp_HalMakeBeep' as HalMakeBeep:qword
    if (NTDDI_VERSION = NTDDI_WIN7)
         extrn '__imp_HalMcUpdateReadPCIConfig' as HalMcUpdateReadPCIConfig:qword
    end if
    extrn '__imp_HalProcessorIdle' as HalProcessorIdle:qword
    extrn '__imp_HalQueryDisplayParameters' as HalQueryDisplayParameters:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
         extrn '__imp_HalQueryEnvironmentVariableInfoEx' as HalQueryEnvironmentVariableInfoEx:qword
         extrn '__imp_HalQueryMaximumProcessorCount' as HalQueryMaximumProcessorCount:qword
    end if
    extrn '__imp_HalQueryRealTimeClock' as HalQueryRealTimeClock:qword
    extrn '__imp_HalReadDmaCounter' as HalReadDmaCounter:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
         extrn '__imp_HalRegisterDynamicProcessor' as HalRegisterDynamicProcessor:qword
    end if
    extrn '__imp_HalReportResourceUsage' as HalReportResourceUsage:qword
    extrn '__imp_HalRequestIpi' as HalRequestIpi:qword
    extrn '__imp_HalReturnToFirmware' as HalReturnToFirmware:qword
    extrn '__imp_HalSetBusData' as HalSetBusData:qword
    extrn '__imp_HalSetBusDataByOffset' as HalSetBusDataByOffset:qword
    extrn '__imp_HalSetDisplayParameters' as HalSetDisplayParameters:qword
    extrn '__imp_HalSetEnvironmentVariable' as HalSetEnvironmentVariable:qword
    extrn '__imp_HalSetProfileInterval' as HalSetProfileInterval:qword
    extrn '__imp_HalSetRealTimeClock' as HalSetRealTimeClock:qword
    if (NTDDI_VERSION <= NTDDI_WIN8)
        extrn '__imp_HalSetTimeIncrement' as HalSetTimeIncrement:qword
    end if
    extrn '__imp_HalStartNextProcessor' as HalStartNextProcessor:qword
    extrn '__imp_HalStartProfileInterrupt' as HalStartProfileInterrupt:qword
    extrn '__imp_HalStopProfileInterrupt' as HalStopProfileInterrupt:qword
    extrn '__imp_HalSystemVectorDispatchEntry' as HalSystemVectorDispatchEntry:qword
    extrn '__imp_HalTranslateBusAddress' as HalTranslateBusAddress:qword
    if (NTDDI_VERSION <= NTDDI_VISTA)
         extrn '__imp_IoAssignDriveLetters' as IoAssignDriveLetters:qword
    end if
    extrn '__imp_IoFlushAdapterBuffers' as IoFlushAdapterBuffers:qword
    extrn '__imp_IoFreeAdapterChannel' as IoFreeAdapterChannel:qword
    extrn '__imp_IoFreeMapRegisters' as IoFreeMapRegisters:qword
    extrn '__imp_IoMapTransfer' as IoMapTransfer:qword
    extrn '__imp_IoReadPartitionTable' as IoReadPartitionTable:qword
    extrn '__imp_IoSetPartitionInformation' as IoSetPartitionInformation:qword
    extrn '__imp_IoWritePartitionTable' as IoWritePartitionTable:qword
    extrn '__imp_KdComPortInUse' as KdComPortInUse:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp_KeAcquireSpinLock' as KeAcquireSpinLock:qword
    end if
    extrn '__imp_KeFlushWriteBuffer' as KeFlushWriteBuffer:qword
    extrn '__imp_KeGetCurrentIrql' as KeGetCurrentIrql:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
         extrn '__imp_KeLowerIrql' as KeLowerIrql:qword
         extrn '__imp_KeRaiseIrql' as KeRaiseIrql:qword
         extrn '__imp_KeRaiseIrqlToDpcLevel' as KeRaiseIrqlToDpcLevel:qword
         extrn '__imp_KeRaiseIrqlToSynchLevel' as KeRaiseIrqlToSynchLevel:qword
        extrn '__imp_KeReleaseInStackQueuedSpinLock' as KeReleaseInStackQueuedSpinLock:qword
         extrn '__imp_KeReleaseSpinLock' as KeReleaseSpinLock:qword
    end if
    extrn '__imp_KeQueryPerformanceCounter' as KeQueryPerformanceCounter:qword
    extrn '__imp_KeStallExecutionProcessor' as KeStallExecutionProcessor:qword
    if (NTDDI_VERSION = NTDDI_VISTA)
         extrn '__imp_READ_PORT_BUFFER_UCHAR' as READ_PORT_BUFFER_UCHAR:qword
         extrn '__imp_READ_PORT_BUFFER_ULONG' as READ_PORT_BUFFER_ULONG:qword
         extrn '__imp_READ_PORT_BUFFER_USHORT' as READ_PORT_BUFFER_USHORT:qword
         extrn '__imp_READ_PORT_UCHAR' as READ_PORT_UCHAR:qword
         extrn '__imp_READ_PORT_ULONG' as READ_PORT_ULONG:qword
         extrn '__imp_READ_PORT_USHORT' as READ_PORT_USHORT:qword
         extrn '__imp_WRITE_PORT_BUFFER_UCHAR' as WRITE_PORT_BUFFER_UCHAR:qword
         extrn '__imp_WRITE_PORT_BUFFER_ULONG' as WRITE_PORT_BUFFER_ULONG:qword
         extrn '__imp_WRITE_PORT_BUFFER_USHORT' as WRITE_PORT_BUFFER_USHORT:qword
         extrn '__imp_WRITE_PORT_UCHAR' as WRITE_PORT_UCHAR:qword
         extrn '__imp_WRITE_PORT_ULONG' as WRITE_PORT_ULONG:qword
         extrn '__imp_WRITE_PORT_USHORT' as WRITE_PORT_USHORT:qword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
         extrn '__imp_x86BiosAllocateBuffer' as x86BiosAllocateBuffer:qword
         extrn '__imp_x86BiosCall' as x86BiosCall:qword
    end if
    if (NTDDI_VERSION = NTDDI_WINXP)
         extrn '__imp_x86BiosExecuteInterrupt' as x86BiosExecuteInterrupt:qword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
         extrn '__imp_x86BiosFreeBuffer' as x86BiosFreeBuffer:qword
         extrn '__imp_x86BiosReadMemory' as x86BiosReadMemory:qword
         extrn '__imp_x86BiosWriteMemory' as x86BiosWriteMemory:qword
    end if
    if (NTDDI_VERSION = NTDDI_WINXP)
         extrn '__imp_x86BiosInitializeBiosEx' as x86BiosInitializeBiosEx:qword
         extrn '__imp_x86BiosTranslateAddress' as x86BiosTranslateAddress:qword
    end if
else
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ExAcquireFastMutex@4' as ExAcquireFastMutex:dword
        extrn '__imp__ExReleaseFastMutex@4' as ExReleaseFastMutex:dword
        extrn '__imp__ExTryToAcquireFastMutex@4' as ExTryToAcquireFastMutex:dword
    end if
    extrn '__imp__HalAcquireDisplayOwnership@4' as HalAcquireDisplayOwnership:dword
    extrn '__imp__HalAdjustResourceList@4' as HalAdjustResourceList:dword
    extrn '__imp__HalAllocateAdapterChannel@16' as HalAllocateAdapterChannel:dword
    extrn '__imp__HalAllocateCommonBuffer@16' as HalAllocateCommonBuffer:dword
    extrn '__imp__HalAllocateCrashDumpRegisters@8' as HalAllocateCrashDumpRegisters:dword
    if (NTDDI_VERSION >= NTDDI_WIN7)
         extrn '__imp__HalAllocateHardwareCounters@16' as HalAllocateHardwareCounters:dword
    end if
    extrn '__imp__HalAllProcessorsStarted@0' as HalAllProcessorsStarted:dword
    extrn '__imp__HalAssignSlotResources@32' as HalAssignSlotResources:dword
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp__HalBeginSystemInterrupt@12' as HalBeginSystemInterrupt:dword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
         extrn '__imp__HalBugCheckSystem@4' as HalBugCheckSystem:dword
    end if
    extrn '__imp__HalCalibratePerformanceCounter@12' as HalCalibratePerformanceCounter:dword
    if (NTDDI_VERSION = NTDDI_WINXP)
         extrn '__imp__HalCallBios@32' as HalCallBios:dword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
         extrn '__imp__HalConvertDeviceIdtToIrql@4' as HalDisableSystemInterrupt:dword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__HalDisableInterrupt@4' as HalDisableInterrupt:dword
    end if
    if (NTDDI_VERSION = NTDDI_WINXP)
         extrn '__imp__HalDisableSystemInterrupt@8' as HalDisableSystemInterrupt:dword
    end if
    extrn '__imp__HalDisplayString@4' as HalDisplayString:dword
    if (NTDDI_VERSION >= NTDDI_VISTA)
         extrn '__imp__HalEnableInterrupt@4' as HalEnableInterrupt:dword
    end if
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp__HalEnableSystemInterrupt@12' as HalEnableSystemInterrupt:dword
        extrn '__imp__HalEndSystemInterrupt@8' as HalEndSystemInterrupt:dword
    end if
    extrn '__imp__HalFlushCommonBuffer@20' as HalFlushCommonBuffer:dword
    extrn '__imp__HalFreeCommonBuffer@24' as HalFreeCommonBuffer:dword
    if (NTDDI_VERSION = NTDDI_WIN7)
         extrn '__imp__HalFreeHardwareCounters@4' as HalFreeHardwareCounters:dword
    end if
    extrn '__imp__HalGetAdapter@8' as HalGetAdapter:dword
    extrn '__imp__HalGetBusData@20' as HalGetBusData:dword
    extrn '__imp__HalGetBusDataByOffset@24' as HalGetBusDataByOffset:dword
    extrn '__imp__HalGetEnvironmentVariable@12' as HalGetEnvironmentVariable:dword
    extrn '__imp__HalGetInterruptVector@24' as HalGetInterruptVector:dword
    extrn '__imp__HalHandleNMI@4' as HalHandleNMI:dword
    if (NTDDI_VERSION >= NTDDI_VISTA)
         extrn '__imp__HalInitializeBios@8' as HalInitializeBios:dword
    end if
    extrn '__imp__HalInitializeProcessor@8' as HalInitializeProcessor:dword
    extrn '__imp__HalInitSystem@8' as HalInitSystem:dword
    extrn '__imp__HalMakeBeep@4' as HalMakeBeep:dword
    if (NTDDI_VERSION = NTDDI_WIN7)
         extrn '__imp__HalMcUpdateReadPCIConfig@20' as HalMcUpdateReadPCIConfig:dword
    end if
    extrn '__imp__HalProcessorIdle@0' as HalProcessorIdle:dword
    extrn '__imp__HalQueryDisplayParameters@16' as HalQueryDisplayParameters:dword
    if (NTDDI_VERSION >= NTDDI_VISTA)
         extrn '__imp__HalQueryEnvironmentVariableInfoEx@16' as HalQueryEnvironmentVariableInfoEx:dword
         extrn '__imp__HalQueryMaximumProcessorCount@0' as HalQueryMaximumProcessorCount:dword
    end if
    extrn '__imp__HalQueryRealTimeClock@4' as HalQueryRealTimeClock:dword
    extrn '__imp__HalReadDmaCounter@4' as HalReadDmaCounter:dword
    if (NTDDI_VERSION >= NTDDI_VISTA)
         extrn '__imp__HalRegisterDynamicProcessor@0' as HalRegisterDynamicProcessor:dword
    end if
    extrn '__imp__HalReportResourceUsage@0' as HalReportResourceUsage:dword
    extrn '__imp__HalRequestIpi@4' as HalRequestIpi:dword
    extrn '__imp__HalReturnToFirmware@4' as HalReturnToFirmware:dword
    extrn '__imp__HalSetBusData@20' as HalSetBusData:dword
    extrn '__imp__HalSetBusDataByOffset@24' as HalSetBusDataByOffset:dword
    extrn '__imp__HalSetDisplayParameters@8' as HalSetDisplayParameters:dword
    extrn '__imp__HalSetEnvironmentVariable@8' as HalSetEnvironmentVariable:dword
    extrn '__imp__HalSetProfileInterval@4' as HalSetProfileInterval:dword
    extrn '__imp__HalSetRealTimeClock@4' as HalSetRealTimeClock:dword
    if (NTDDI_VERSION <= NTDDI_WIN8)
        extrn '__imp__HalSetTimeIncrement@4' as HalSetTimeIncrement:dword
    end if
    extrn '__imp__HalStartNextProcessor@8' as HalStartNextProcessor:dword
    extrn '__imp__HalStartProfileInterrupt@4' as HalStartProfileInterrupt:dword
    extrn '__imp__HalStopProfileInterrupt@4' as HalStopProfileInterrupt:dword
    ;extrn '__imp__HalSystemVectorDispatchEntry@12' as HalSystemVectorDispatchEntry:dword ;Not present in MASM32 hal.lib
    extrn '__imp__HalTranslateBusAddress@24' as HalTranslateBusAddress:dword
    ;if (NTDDI_VERSION <= NTDDI_VISTA)
    ;     extrn '__imp__IoAssignDriveLetters@16' as IoAssignDriveLetters:dword ;Not present in MASM32 hal.lib
    ;end if
    extrn '__imp__IoFlushAdapterBuffers@24' as IoFlushAdapterBuffers:dword
    extrn '__imp__IoFreeAdapterChannel@4' as IoFreeAdapterChannel:dword
    extrn '__imp__IoFreeMapRegisters@12' as IoFreeMapRegisters:dword
    extrn '__imp__IoMapTransfer@24' as IoMapTransfer:dword
    ;extrn '__imp__IoReadPartitionTable@16' as IoReadPartitionTable:dword ;Not present in MASM32 hal.lib
    ;extrn '__imp__IoSetPartitionInformation@16' as IoSetPartitionInformation:dword ;Not present in MASM32 hal.lib
    ;extrn '__imp__IoWritePartitionTable2@20' as IoWritePartitionTable:dword ;Not present in MASM32 hal.lib
    extrn '__imp__KdComPortInUse' as KdComPortInUse:dword
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp__KeAcquireSpinLock@8' as KeAcquireSpinLock:dword
    end if
    extrn '__imp__KeFlushWriteBuffer@0' as KeFlushWriteBuffer:dword
    extrn '__imp__KeGetCurrentIrql@0' as KeGetCurrentIrql:dword
    if (NTDDI_VERSION = NTDDI_VISTA)
        extrn '__imp__KeLowerIrql@4' as KeLowerIrql:dword
        extrn '__imp__KeRaiseIrql@8' as KeRaiseIrql:dword
         extrn '__imp__KeRaiseIrqlToDpcLevel@0' as KeRaiseIrqlToDpcLevel:dword
         extrn '__imp__KeRaiseIrqlToSynchLevel@0' as KeRaiseIrqlToSynchLevel:dword
        extrn '__imp__KeReleaseInStackQueuedSpinLock@4' as KeReleaseInStackQueuedSpinLock:dword
         extrn '__imp__KeReleaseSpinLock@8' as KeReleaseSpinLock:dword
    end if
    extrn '__imp__KeQueryPerformanceCounter@4' as KeQueryPerformanceCounter:dword
    extrn '__imp__KeStallExecutionProcessor@4' as KeStallExecutionProcessor:dword
    if (NTDDI_VERSION = NTDDI_VISTA)
         extrn '__imp__READ_PORT_BUFFER_UCHAR@12' as READ_PORT_BUFFER_UCHAR:dword
         extrn '__imp__READ_PORT_BUFFER_ULONG@12' as READ_PORT_BUFFER_ULONG:dword
         extrn '__imp__READ_PORT_BUFFER_USHORT@12' as READ_PORT_BUFFER_USHORT:dword
         extrn '__imp__READ_PORT_UCHAR@4' as READ_PORT_UCHAR:dword
         extrn '__imp__READ_PORT_ULONG@4' as READ_PORT_ULONG:dword
         extrn '__imp__READ_PORT_USHORT@4' as READ_PORT_USHORT:dword
         extrn '__imp__WRITE_PORT_BUFFER_UCHAR@12' as WRITE_PORT_BUFFER_UCHAR:dword
         extrn '__imp__WRITE_PORT_BUFFER_ULONG@12' as WRITE_PORT_BUFFER_ULONG:dword
         extrn '__imp__WRITE_PORT_BUFFER_USHORT@12' as WRITE_PORT_BUFFER_USHORT:dword
         extrn '__imp__WRITE_PORT_UCHAR@8' as WRITE_PORT_UCHAR:dword
         extrn '__imp__WRITE_PORT_ULONG@8' as WRITE_PORT_ULONG:dword
         extrn '__imp__WRITE_PORT_USHORT@8' as WRITE_PORT_USHORT:dword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
         extrn '__imp__x86BiosAllocateBuffer@12' as x86BiosAllocateBuffer:dword
         extrn '__imp__x86BiosCall@8' as x86BiosCall:dword
    end if
    if (NTDDI_VERSION = NTDDI_WINXP)
         extrn '__imp__x86BiosExecuteInterrupt@16' as x86BiosExecuteInterrupt:dword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
         extrn '__imp__x86BiosFreeBuffer@8' as x86BiosFreeBuffer:dword
         extrn '__imp__x86BiosReadMemory@16' as x86BiosReadMemory:dword
         extrn '__imp__x86BiosWriteMemory@16' as x86BiosWriteMemory:dword
    end if
    if (NTDDI_VERSION = NTDDI_WINXP)
         extrn '__imp__x86BiosInitializeBiosEx@20' as x86BiosInitializeBiosEx:dword
         extrn '__imp__x86BiosTranslateAddress@8' as x86BiosTranslateAddress:dword
    end if
end if

;======================= Undocumented functions (unknown arguments) =======================;
;if defined APP_WIN64
;    if (NTDDI_VERSION >= NTDDI_WIN8)
;        extrn '__imp_HalAcpiGetTableEx' as HalAcpiGetTableEx:qword
;        extrn '__imp_HalDmaAllocateCrashDumpRegistersEx' as HalDmaAllocateCrashDumpRegistersEx:qword
;        extrn '__imp_HalDmaFreeCrashDumpRegistersEx' as HalDmaFreeCrashDumpRegistersEx:qword
;        extrn '__imp_HalRequestIpiSpecifyVector' as HalRequestIpiSpecifyVector:qword
;        extrn '__imp_KdHvComPortInUse' as KdHvComPortInUse:qword
;    end if
;    if (NTDDI_VERSION = NTDDI_VISTA)
;        extrn '__imp_HalClearSoftwareInterrupt' as HalClearSoftwareInterrupt:qword
;        extrn '__imp_KeReleaseQueuedSpinLock' as KeReleaseQueuedSpinLock:qword
;    end if
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp_HalEnumerateEnvironmentVariablesEx' as HalEnumerateEnvironmentVariablesEx:qword
;        extrn '__imp_HalGetEnvironmentVariableEx' as HalGetEnvironmentVariableEx:qword
;        extrn '__imp_HalGetInterruptTargetInformation' as HalGetInterruptTargetInformation:qword
;        extrn '__imp_HalGetMessageRoutingInfo' as HalGetMessageRoutingInfo:qword
;        extrn '__imp_HalGetProcessorIdByNtNumber' as HalGetProcessorIdByNtNumber:qword
;        extrn '__imp_HalGetVectorInput' as HalGetVectorInput:qword
;        extrn '__imp_HalInitializeOnResume' as HalInitializeOnResume:qword
;        extrn '__imp_HalInitializeOnResume' as HalInitializeOnResume:qword
;        extrn '__imp_HalIsHyperThreadingEnabled' as HalIsHyperThreadingEnabled:qword
;        extrn '__imp_HalStartDynamicProcessor' as HalStartDynamicProcessor:qword
;    end if
;    if (NTDDI_VERSION <> NTDDI_VISTA)
;        extrn '__imp_HalEnumerateProcessors' as HalEnumerateProcessors:qword
;        extrn '__imp_HalSendNMI' as HalSendNMI:qword
;        extrn '__imp_HalSendSoftwareInterrupt' as HalSendSoftwareInterrupt:qword
;    end if
;    if (NTDDI_VERSION >= NTDDI_WIN7)
;        extrn '__imp_HalGetMemoryCachingRequirements' as HalGetMemoryCachingRequirements:qword
;        extrn '__imp_HalPerformEndOfInterrupt' as HalPerformEndOfInterrupt:qword
;        extrn '__imp_HalRequestClockInterrupt' as HalRequestClockInterrupt:qword
;        extrn '__imp_HalRequestDeferredRecoveryServiceInterrupt' as HalRequestDeferredRecoveryServiceInterrupt:qword
;        extrn '__imp_HalHandleMcheck' as HalHandleMcheck:qword
;    end if
;    if (NTDDI_VERSION = NTDDI_WINXP)
;        extrn '__imp_HalHandleMcheck' as HalHandleMcheck:qword
;    end if
;    extrn '__imp_HalRequestSoftwareInterrupt' as HalRequestSoftwareInterrupt:qword
;else
;    if (NTDDI_VERSION >= NTDDI_WIN8)
;        extrn '__imp__HalAcpiGetTableEx@??' as HalAcpiGetTableEx:dword
;        extrn '__imp__HalDmaAllocateCrashDumpRegistersEx@??' as HalDmaAllocateCrashDumpRegistersEx:dword
;        extrn '__imp__HalDmaFreeCrashDumpRegistersEx@??' as HalDmaFreeCrashDumpRegistersEx:dword
;        extrn '__imp__HalRequestIpiSpecifyVector@??' as HalRequestIpiSpecifyVector:dword
;        extrn '__imp__KdHvComPortInUse@??' as KdHvComPortInUse:dword
;    end if
;    if (NTDDI_VERSION = NTDDI_VISTA)
;        extrn '__imp__HalClearSoftwareInterrupt@??' as HalClearSoftwareInterrupt:dword
;        extrn '__imp__KeReleaseQueuedSpinLock@??' as KeReleaseQueuedSpinLock:dword
;    end if
;    if (NTDDI_VERSION >= NTDDI_VISTA)
;        extrn '__imp__HalEnumerateEnvironmentVariablesEx@??' as HalEnumerateEnvironmentVariablesEx:dword
;        extrn '__imp__HalGetEnvironmentVariableEx@??' as HalGetEnvironmentVariableEx:dword
;        extrn '__imp__HalGetInterruptTargetInformation@??' as HalGetInterruptTargetInformation:dword
;        extrn '__imp__HalGetMessageRoutingInfo@??' as HalGetMessageRoutingInfo:dword
;        extrn '__imp__HalGetProcessorIdByNtNumber@??' as HalGetProcessorIdByNtNumber:dword
;        extrn '__imp__HalGetVectorInput@??' as HalGetVectorInput:dword
;        extrn '__imp__HalInitializeOnResume@??' as HalInitializeOnResume:dword
;        extrn '__imp__HalInitializeOnResume@??' as HalInitializeOnResume:dword
;        extrn '__imp__HalIsHyperThreadingEnabled@??' as HalIsHyperThreadingEnabled:dword
;        extrn '__imp__HalStartDynamicProcessor@??' as HalStartDynamicProcessor:dword
;    end if
;    if (NTDDI_VERSION <> NTDDI_VISTA)
;        extrn '__imp__HalEnumerateProcessors@??' as HalEnumerateProcessors:dword
;        extrn '__imp__HalSendNMI@??' as HalSendNMI:dword
;        extrn '__imp__HalSendSoftwareInterrupt@??' as HalSendSoftwareInterrupt:dword
;    end if
;    if (NTDDI_VERSION >= NTDDI_WIN7)
;        extrn '__imp__HalGetMemoryCachingRequirements@??' as HalGetMemoryCachingRequirements:dword
;        extrn '__imp__HalPerformEndOfInterrupt@??' as HalPerformEndOfInterrupt:dword
;        extrn '__imp__HalRequestClockInterrupt@??' as HalRequestClockInterrupt:dword
;        extrn '__imp__HalRequestDeferredRecoveryServiceInterrupt@??' as HalRequestDeferredRecoveryServiceInterrupt:dword
;        extrn '__imp__HalHandleMcheck@??' as HalHandleMcheck:dword
;    end if
;    if (NTDDI_VERSION = NTDDI_WINXP)
;        extrn '__imp__HalHandleMcheck@??' as HalHandleMcheck:dword
;    end if
;    extrn '__imp__HalRequestSoftwareInterrupt@??' as HalRequestSoftwareInterrupt:dword
;end if

end if ;HAL_INC
