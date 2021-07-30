; ====================================================;
;                                                     ;
;      hal.inc for EC v2 SolAsm classic projects      ;
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

;======================= Undocumented functions (unknown arguments) =======================;
;#if NTDDI_VERSION >= NTDDI_WIN8
;    import HalAcpiGetTableEx
;    import HalDmaAllocateCrashDumpRegistersEx
;    import HalDmaFreeCrashDumpRegistersEx
;    import HalRequestIpiSpecifyVector
;    import KdHvComPortInUse
;#endif
;#if NTDDI_VERSION == NTDDI_VISTA
;    import HalClearSoftwareInterrupt
;    import KeReleaseQueuedSpinLock
;#endif
;#if NTDDI_VERSION >= NTDDI_VISTA
;    import HalEnumerateEnvironmentVariablesEx
;    import HalGetEnvironmentVariableEx
;    import HalGetInterruptTargetInformation
;    import HalGetMessageRoutingInfo
;    import HalGetProcessorIdByNtNumber
;    import HalGetVectorInput
;    import HalInitializeOnResume
;    import HalInitializeOnResume
;    import HalIsHyperThreadingEnabled
;    import HalStartDynamicProcessor
;#endif
;#if NTDDI_VERSION != NTDDI_VISTA
;    import HalEnumerateProcessors
;    import HalSendNMI
;    import HalSendSoftwareInterrupt
;#endif
;#if NTDDI_VERSION >= NTDDI_WIN7
;    import HalGetMemoryCachingRequirements
;    import HalPerformEndOfInterrupt
;    import HalRequestClockInterrupt
;    import HalRequestDeferredRecoveryServiceInterrupt
;    import HalHandleMcheck
;#endif
;#if NTDDI_VERSION == NTDDI_WINXP
;    import HalHandleMcheck
;#endif
;import HalRequestSoftwareInterrupt

#endif ;HAL_INC
