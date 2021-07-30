; ====================================================;
;                                                     ;
;   hal.inc for Easy Code 2.0 64-bit Masm projects    ;
;                  (version 1.0.3)                    ;
;                                                     ;
;         Copyright © Ramon Sala - 2015-2018          ;
;                                                     ;
; ====================================================;

IFNDEF HAL_INC
HAL_INC EQU 1

IF (NTDDI_VERSION GE NTDDI_VISTA)
    ExAcquireFastMutex PROTO :XPTR
    ExReleaseFastMutex PROTO :XPTR
    ExTryToAcquireFastMutex PROTO :XPTR
ENDIF
HalAcquireDisplayOwnership PROTO :XWORD
HalAdjustResourceList PROTO :XWORD
HalAllocateAdapterChannel PROTO :XWORD, :XWORD, :XWORD, :XWORD
HalAllocateCommonBuffer PROTO :XWORD, :XWORD, :XWORD, :XWORD
HalAllocateCrashDumpRegisters PROTO :XWORD, :XWORD
IF (NTDDI_VERSION GE NTDDI_WIN7)
    HalAllocateHardwareCounters PROTO :XPTR, :XWORD, :XPTR, :XPTR
ENDIF
HalAllProcessorsStarted PROTO
HalAssignSlotResources PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
IF (NTDDI_VERSION EQ NTDDI_VISTA)
    HalBeginSystemInterrupt PROTO :XWORD, :XWORD, :XWORD
ENDIF
IF (NTDDI_VERSION GE NTDDI_VISTA)
    HalBugCheckSystem PROTO :XPTR
ENDIF
HalCalibratePerformanceCounter PROTO :XWORD, :XWORD, :XWORD
IF (NTDDI_VERSION EQ NTDDI_WINXP)
    HalCallBios PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
ENDIF
IF (NTDDI_VERSION GE NTDDI_VISTA)
    HalConvertDeviceIdtToIrql PROTO :XWORD
ENDIF
IF (NTDDI_VERSION GE NTDDI_VISTA)
    HalDisableInterrupt PROTO :XWORD
ENDIF
IF (NTDDI_VERSION EQ NTDDI_WINXP)
    HalDisableSystemInterrupt PROTO :XWORD, :XWORD
ENDIF
HalDisplayString PROTO :XWORD
IF (NTDDI_VERSION GE NTDDI_VISTA)
    HalEnableInterrupt PROTO :XWORD
ENDIF
IF (NTDDI_VERSION EQ NTDDI_VISTA)
    HalEnableSystemInterrupt PROTO :XWORD, :XWORD, :XWORD
    HalEndSystemInterrupt PROTO :XWORD, :XWORD
ENDIF
HalFlushCommonBuffer PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
HalFreeCommonBuffer PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
IF (NTDDI_VERSION GE NTDDI_WIN7)
    HalFreeHardwareCounters PROTO :XWORD
ENDIF
HalGetAdapter PROTO :XWORD, :XWORD
HalGetBusData PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
HalGetBusDataByOffset PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
HalGetEnvironmentVariable PROTO :XWORD, :XWORD, :XWORD
HalGetInterruptVector PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
HalHandleNMI PROTO :XWORD
IF (NTDDI_VERSION GE NTDDI_VISTA)
    HalInitializeBios PROTO :XWORD, :XWORD
ENDIF
HalInitializeProcessor PROTO :XWORD, :XWORD
HalInitSystem PROTO :XWORD, :XWORD
HalMakeBeep PROTO :XWORD
IF (NTDDI_VERSION EQ NTDDI_WIN7)
    HalMcUpdateReadPCIConfig PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
ENDIF
HalProcessorIdle PROTO
HalQueryDisplayParameters PROTO :XWORD, :XWORD, :XWORD, :XWORD
IF (NTDDI_VERSION GE NTDDI_VISTA)
    HalQueryEnvironmentVariableInfoEx PROTO :XWORD, :XWORD, :XWORD, :XWORD
    HalQueryMaximumProcessorCount PROTO
ENDIF
HalQueryRealTimeClock PROTO :XWORD
HalReadDmaCounter PROTO :XWORD
IF (NTDDI_VERSION GE NTDDI_VISTA)
    HalRegisterDynamicProcessor PROTO
ENDIF
HalReportResourceUsage PROTO
HalRequestIpi PROTO :XWORD
HalReturnToFirmware PROTO :XWORD
HalSetBusData PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
HalSetBusDataByOffset PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
HalSetDisplayParameters PROTO :XWORD, :XWORD
HalSetEnvironmentVariable PROTO :XWORD, :XWORD
HalSetProfileInterval PROTO :XWORD
HalSetRealTimeClock PROTO :XWORD
IF (NTDDI_VERSION LE NTDDI_WIN8)
    HalSetTimeIncrement PROTO :XWORD
ENDIF
HalStartNextProcessor PROTO :XWORD, :XWORD
HalStartProfileInterrupt PROTO :XWORD
HalStopProfileInterrupt PROTO :XWORD
HalSystemVectorDispatchEntry PROTO :XWORD, :XWORD, :XWORD
HalTranslateBusAddress PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
IF (NTDDI_VERSION LE NTDDI_VISTA)
    IoAssignDriveLetters PROTO :XWORD, :XWORD, :XWORD, :XWORD
ENDIF
IoFlushAdapterBuffers PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
IoFreeAdapterChannel PROTO :XWORD
IoFreeMapRegisters PROTO :XWORD, :XWORD, :XWORD
IoMapTransfer PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
IoReadPartitionTable PROTO :XPTR, :XWORD, :XWORD, :XPTR
IoSetPartitionInformation PROTO :XPTR, :XWORD, :XWORD, :XWORD
IoWritePartitionTable PROTO :XPTR, :XWORD, :XWORD, :XWORD, :XPTR
KdComPortInUse PROTO :VARARG
IF (NTDDI_VERSION EQ NTDDI_VISTA)
    KeAcquireSpinLock PROTO :XWORD, :XWORD
ENDIF
KeFlushWriteBuffer PROTO
KeGetCurrentIrql PROTO
IF (NTDDI_VERSION EQ NTDDI_VISTA)
    KeLowerIrql PROTO :XWORD
    KeRaiseIrql PROTO :XWORD, :XWORD
    KeRaiseIrqlToDpcLevel PROTO
    KeRaiseIrqlToSynchLevel PROTO
    KeReleaseInStackQueuedSpinLock PROTO :XPTR
    KeReleaseSpinLock PROTO :XWORD, :XWORD
ENDIF
KeQueryPerformanceCounter PROTO :XPTR
KeStallExecutionProcessor PROTO :XWORD
IF (NTDDI_VERSION EQ NTDDI_VISTA)
    READ_PORT_BUFFER_UCHAR PROTO :XWORD, :XWORD, :XWORD
    READ_PORT_BUFFER_ULONG PROTO :XWORD, :XWORD, :XWORD
    READ_PORT_BUFFER_USHORT PROTO :XWORD, :XWORD, :XWORD
    READ_PORT_UCHAR PROTO :XWORD
    READ_PORT_ULONG PROTO :XWORD
    READ_PORT_USHORT PROTO :XWORD
    WRITE_PORT_BUFFER_UCHAR PROTO :XWORD, :XWORD, :XWORD
    WRITE_PORT_BUFFER_ULONG PROTO :XWORD, :XWORD, :XWORD
    WRITE_PORT_BUFFER_USHORT PROTO :XWORD, :XWORD, :XWORD
    WRITE_PORT_UCHAR PROTO :XWORD, :XWORD
    WRITE_PORT_ULONG PROTO :XWORD, :XWORD
    WRITE_PORT_USHORT PROTO :XWORD, :XWORD
ENDIF
IF (NTDDI_VERSION GE NTDDI_VISTA)
    x86BiosAllocateBuffer PROTO :XWORD, :XWORD, :XWORD
    x86BiosCall PROTO :XWORD, :XPTR
ENDIF
IF (NTDDI_VERSION EQ NTDDI_WINXP)
    x86BiosExecuteInterrupt PROTO :XWORD, :XPTR, :XPTR, :XPTR
ENDIF
IF (NTDDI_VERSION GE NTDDI_VISTA)
    x86BiosFreeBuffer PROTO :XWORD, :XWORD
    x86BiosReadMemory PROTO :XWORD, :XWORD, :XPTR, :XWORD
    x86BiosWriteMemory PROTO :XWORD, :XWORD, :XPTR, :XWORD
ENDIF
IF (NTDDI_VERSION EQ NTDDI_WINXP)
    x86BiosInitializeBiosEx PROTO :XPTR, :XPTR, :XPTR, :XPTR, :XWORD
    x86BiosTranslateAddress PROTO :XWORD, :XWORD
ENDIF

;======================= Undocumented functions (unknown arguments) =======================;
;IF (NTDDI_VERSION GE NTDDI_WIN8)
;    HalAcpiGetTableEx PROTO :VARARG
;    HalDmaAllocateCrashDumpRegistersEx PROTO :VARARG
;    HalDmaFreeCrashDumpRegistersEx PROTO :VARARG
;    HalRequestIpiSpecifyVector PROTO :VARARG
;    KdHvComPortInUse PROTO :VARARG
;ENDIF
;IF (NTDDI_VERSION EQ NTDDI_VISTA)
;    HalClearSoftwareInterrupt PROTO :VARARG
;    KeReleaseQueuedSpinLock PROTO :VARARG
;ENDIF
;IF (NTDDI_VERSION GE NTDDI_VISTA)
;    HalEnumerateEnvironmentVariablesEx PROTO :VARARG
;    HalGetEnvironmentVariableEx PROTO :VARARG
;    HalGetInterruptTargetInformation PROTO :VARARG
;    HalGetMessageRoutingInfo PROTO :VARARG
;    HalGetProcessorIdByNtNumber PROTO :VARARG
;    HalGetVectorInput PROTO :VARARG
;    HalInitializeOnResume PROTO :VARARG
;    HalInitializeOnResume PROTO :VARARG
;    HalIsHyperThreadingEnabled PROTO :VARARG
;    HalStartDynamicProcessor PROTO :VARARG
;ENDIF
;IF (NTDDI_VERSION NE NTDDI_VISTA)
;    HalEnumerateProcessors PROTO :VARARG
;    HalSendNMI PROTO :VARARG
;    HalSendSoftwareInterrupt PROTO :VARARG
;ENDIF
;IF (NTDDI_VERSION GE NTDDI_WIN7)
;    HalGetMemoryCachingRequirements PROTO :VARARG
;    HalPerformEndOfInterrupt PROTO :VARARG
;    HalRequestClockInterrupt PROTO :VARARG
;    HalRequestDeferredRecoveryServiceInterrupt PROTO :VARARG
;    HalHandleMcheck PROTO :VARARG
;ENDIF
;IF (NTDDI_VERSION EQ NTDDI_WINXP)
;    HalHandleMcheck PROTO :VARARG
;ENDIF
;HalRequestSoftwareInterrupt PROTO :VARARG

ENDIF ;HAL_INC
