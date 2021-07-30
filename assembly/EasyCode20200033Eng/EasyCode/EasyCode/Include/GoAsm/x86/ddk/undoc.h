;===========================================================;
;                                                           ;
;      undoc.h for Easy Code 2.0 GoAsm 32-bit drivers       ;
;                     (version 1.0.0)                       ;
;                                                           ;
;             Driver Development Kit (32-bit)               ;
;                                                           ;
;              Copyright © Ramon Sala - 2015                ;
;                                                           ;
;===========================================================;

#IFNDEF UNDOC_H
#Define UNDOC_H 1

SystemBasicInformation                              Equ         0
SystemProcessorInformation                          Equ         1
SystemPerformanceInformation                        Equ         2
SystemTimeOfDayInformation                          Equ         3
SystemProcessInformation                            Equ         5
SystemCallCounts                                    Equ         6
SystemConfigurationInformation                      Equ         7
SystemProcessorTimes                                Equ         8
SystemGlobalFlag                                    Equ         9
SystemModuleInformation                             Equ         11
SystemLockInformation                               Equ         12
SystemHandleInformation                             Equ         16
SystemObjectInformation                             Equ         17
SystemPagefileInformation                           Equ         18
SystemInstructionEmulationCounts                    Equ         19
SystemCacheInformation                              Equ         21
SystemPoolTagInformation                            Equ         22
SystemProcessorStatistics                           Equ         23
SystemDpcInformation                                Equ         24
SystemLoadImage                                     Equ         26
SystemUnloadImage                                   Equ         27
SystemTimeAdjustment                                Equ         28
SystemCrashDumpInformation                          Equ         32
SystemExceptionInformation                          Equ         33
SystemCrashDumpStateInformation                     Equ         34
SystemKernelDebuggerInformation                     Equ         35
SystemContextSwitchInformation                      Equ         36
SystemRegistryQuotaInformation                      Equ         37
SystemLoadAndCallImage                              Equ         38
SystemPrioritySeparation                            Equ         39
SystemTimeZoneInformation                           Equ         44
SystemLookasideInformation                          Equ         45
SystemSetTimeSlipEvent                              Equ         46
SystemCreateSession                                 Equ         47
SystemDeleteSession                                 Equ         48
SystemRangeStartInformation                         Equ         50
SystemVerifierInformation                           Equ         51
SystemAddVerifier                                   Equ         52
SystemSessionProcessesInformation                   Equ         53

SYSTEM_BASIC_INFORMATION Struct
    Unknown                                         DD
    MaximumIncrement                                DD
    PhysicalPageSize                                DD
    NumberOfPhysicalPages                           DD
    LowestPhysicalPage                              DD
    HighestPhysicalPage                             DD
    AllocationGranularity                           DD
    LowestUserAddress                               DD
    HighestUserAddress                              DD
    ActiveProcessors                                DD
    NumberProcessors                                DD
EndS

SYSTEM_PROCESSOR_INFORMATION Struct
    ProcessorArchitecture                           DW
    ProcessorLevel                                  DW
    ProcessorRevision                               DW
    Unknown                                         DW
    FeatureBits                                     DD
EndS

SYSTEM_PERFORMANCE_INFORMATION Struct
    IdleTime                                        LARGE_INTEGER
    ReadTransferCount                               LARGE_INTEGER
    WriteTransferCount                              LARGE_INTEGER
    OtherTransferCount                              LARGE_INTEGER
    ReadOperationCount                              DD
    WriteOperationCount                             DD
    OtherOperationCount                             DD
    AvailablePages                                  DD
    TotalCommittedPages                             DD
    TotalCommitLimit                                DD
    PeakCommitment                                  DD
    PageFaults                                      DD
    WriteCopyFaults                                 DD
    TransitionFaults                                DD
    Reserved1                                       DD
    DemandZeroFaults                                DD
    PagesRead                                       DD
    PageReadIos                                     DD
    Reserved2                                       DD          2 Dup ?
    PagefilePagesWritten                            DD
    PagefilePageWriteIos                            DD
    MappedFilePagesWritten                          DD
    MappedFilePageWriteIos                          DD
    PagedPoolUsage                                  DD
    NonPagedPoolUsage                               DD
    PagedPoolAllocs                                 DD
    PagedPoolFrees                                  DD
    NonPagedPoolAllocs                              DD
    NonPagedPoolFrees                               DD
    TotalFreeSystemPtes                             DD
    SystemCodePage                                  DD
    TotalSystemDriverPages                          DD
    TotalSystemCodePages                            DD
    SmallNonPagedLookasideListAllocateHits          DD
    SmallPagedLookasideListAllocateHits             DD
    Reserved3                                       DD
    MmSystemCachePage                               DD
    PagedPoolPage                                   DD
    SystemDriverPage                                DD
    FastReadNoWait                                  DD
    FastReadWait                                    DD
    FastReadResourceMiss                            DD
    FastReadNotPossible                             DD
    FastMdlReadNoWait                               DD
    FastMdlReadWait                                 DD
    FastMdlReadResourceMiss                         DD
    FastMdlReadNotPossible                          DD
    MapDataNoWait                                   DD
    MapDataWait                                     DD
    MapDataNoWaitMiss                               DD
    MapDataWaitMiss                                 DD
    PinMappedDataCount                              DD
    PinReadNoWait                                   DD
    PinReadWait                                     DD
    PinReadNoWaitMiss                               DD
    PinReadWaitMiss                                 DD
    CopyReadNoWait                                  DD
    CopyReadWait                                    DD
    CopyReadNoWaitMiss                              DD
    CopyReadWaitMiss                                DD
    MdlReadNoWait                                   DD
    MdlReadWait                                     DD
    MdlReadNoWaitMiss                               DD
    MdlReadWaitMiss                                 DD
    ReadAheadIos                                    DD
    LazyWriteIos                                    DD
    LazyWritePages                                  DD
    DataFlushes                                     DD
    DataPages                                       DD
    ContextSwitches                                 DD
    FirstLevelTbFills                               DD
    SecondLevelTbFills                              DD
    SystemCalls                                     DD
EndS

SYSTEM_TIME_OF_DAY_INFORMATION Struct
    BootTime                                        LARGE_INTEGER
    CurrentTime                                     LARGE_INTEGER
    TimeZoneBias                                    LARGE_INTEGER
    CurrentTimeZoneId                               DD
EndS

;THREAD_STATE Enumeration
StateInitialized                                    Equ     0
StateReady                                          Equ     1
StateRunning                                        Equ     2
StateStandby                                        Equ     3
StateTerminated                                     Equ     4
StateWait                                           Equ     5
StateTransition                                     Equ     6
StateUnknown                                        Equ     7

SYSTEM_THREADS Struct
    KernelTime                                      LARGE_INTEGER
    UserTime                                        LARGE_INTEGER
    CreateTime                                      LARGE_INTEGER
    WaitTime                                        DD
    StartAddress                                    DD
    ClientId                                        CLIENT_ID
    Priority                                        DD
    BasePriority                                    DD
    ContextSwitchCount                              DD
    State                                           DD
    WaitReason                                      DD
EndS

SYSTEM_PROCESSES Struct
    NextEntryDelta                                  DD
    ThreadCount                                     DD
    Reserved1                                       DD          6 Dup ?
    CreateTime                                      LARGE_INTEGER
    UserTime                                        LARGE_INTEGER
    KernelTime                                      LARGE_INTEGER
    ProcessName                                     UNICODE_STRING
    BasePriority                                    DD
    ProcessId                                       DD
    InheritedFromProcessId                          DD
    HandleCount                                     DD
    Reserved2                                       DD          2 Dup ?
    PrivatePageCount                                DD
    VmCounters                                      VM_COUNTERS
    IoCounters                                      IO_COUNTERS
    Threads                                         SYSTEM_THREADS 1 Dup ?
EndS

SYSTEM_CALLS_INFORMATION Struct
    Size                                            DD
    NumberOfDescriptorTables                        DD
    NumberOfRoutinesInTable                         DD          1 Dup ?
EndS

SYSTEM_CONFIGURATION_INFORMATION Struct
    DiskCount                                       DD
    FloppyCount                                     DD
    CdRomCount                                      DD
    TapeCount                                       DD
    SerialCount                                     DD
    ParallelCount                                   DD
EndS

SYSTEM_PROCESSOR_TIMES Struct
    IdleTime                                        LARGE_INTEGER
    KernelTime                                      LARGE_INTEGER
    UserTime                                        LARGE_INTEGER
    DpcTime                                         LARGE_INTEGER
    InterruptTime                                   LARGE_INTEGER
    InterruptCount                                  DD
EndS

SYSTEM_GLOBAL_FLAG Struct
    GlobalFlag                                      DD
EndS

FLG_STOP_ON_EXCEPTION                               Equ     00000001H
FLG_SHOW_LDR_SNAPS                                  Equ     00000002H
FLG_DEBUG_INITIAL_COMMAND                           Equ     00000004H
FLG_STOP_ON_HUNG_GUI                                Equ     00000008H
FLG_HEAP_ENABLE_TAIL_CHECK                          Equ     00000010H
FLG_HEAP_ENABLE_FREE_CHECK                          Equ     00000020H
FLG_HEAP_VALIDATE_PARAMETERS                        Equ     00000040H
FLG_HEAP_VALIDATE_ALL                               Equ     00000080H
FLG_POOL_ENABLE_TAIL_CHECK                          Equ     00000100H
FLG_POOL_ENABLE_FREE_CHECK                          Equ     00000200H
FLG_POOL_ENABLE_TAGGING                             Equ     00000400H
FLG_HEAP_ENABLE_TAGGING                             Equ     00000800H
FLG_USER_STACK_TRACE_DB                             Equ     00001000H
FLG_KERNEL_STACK_TRACE_DB                           Equ     00002000H
FLG_MAINTAIN_OBJECT_TYPELIST                        Equ     00004000H
FLG_HEAP_ENABLE_TAG_BY_DLL                          Equ     00008000H
FLG_IGNORE_DEBUG_PRIV                               Equ     00010000H
FLG_ENABLE_CSRDEBUG                                 Equ     00020000H
FLG_ENABLE_KDEBUG_SYMBOL_LOAD                       Equ     00040000H
FLG_DISABLE_PAGE_KERNEL_STACKS                      Equ     00080000H
FLG_HEAP_ENABLE_CALL_TRACING                        Equ     00100000H
FLG_HEAP_DISABLE_COALESCING                         Equ     00200000H
FLG_ENABLE_CLOSE_EXCEPTIONS                         Equ     00400000H
FLG_ENABLE_EXCEPTION_LOGGING                        Equ     00800000H
FLG_ENABLE_DBGPRINT_BUFFERING                       Equ     08000000H

SYSTEM_MODULE_INFORMATION Struct
    Reserved                                        DD          2 Dup ?
    Base                                            DD
    Size                                            DD
    Flags                                           DD
    Index                                           DW
    Unknown                                         DW
    LoadCount                                       DW
    ModuleNameOffset                                DW
    ImageName                                       DB          256 Dup ?
EndS

SYSTEM_LOCK_INFORMATION Struct
    Address                                         DD
    Type                                            DW
    Reserved1                                       DW
    ExclusiveOwnerThreadId                          DD
    ActiveCount                                     DD
    ContentionCount                                 DD
    Reserved2                                       DD          2 Dup ?
    NumberOfSharedWaiters                           DD
    NumberOfExclusiveWaiters                        DD
EndS

HANDLE_FLAG_INHERIT                                 Equ         00000001H
HANDLE_FLAG_PROTECT_FROM_CLOSE                      Equ         00000002H

SYSTEM_HANDLE_INFORMATION Struct
    ProcessId                                       DD
    ObjectTypeNumber                                DB
    Flags                                           DB
    Handle                                          DB
    Object                                          DD
    GrantedAccess                                   DD
EndS

SYSTEM_OBJECT_TYPE_INFORMATION Struct
    NextEntryOffset                                 DD
    ObjectCount                                     DD
    HandleCount                                     DD
    TypeNumber                                      DD
    InvalidAttributes                               DD
    GenericMapping                                  GENERIC_MAPPING
    ValidAccessMask                                 DD
    PoolType                                        DD
    Unknown                                         DB
    Name                                            UNICODE_STRING
EndS

SYSTEM_OBJECT_INFORMATION Struct
    NextEntryOffset                                 DD
    Object                                          DD
    CreatorProcessId                                DD
    Unknown                                         DW
    Flags                                           DW
    PointerCount                                    DD
    HandleCount                                     DD
    PagedPoolUsage                                  DD
    NonPagedPoolUsage                               DD
    ExclusiveProcessId                              DD
    SecurityDescriptor                              DD
    Name                                            UNICODE_STRING
EndS

SINGLE_HANDLE_ENTRY                                 Equ     040H
DEFAULT_SECURITY_QUOTA                              Equ     020H
PERMANENT                                           Equ     010H
EXCLUSIVE                                           Equ     008H
CREATOR_INFO                                        Equ     004H
KERNEL_MODE                                         Equ     002H

SYSTEM_PAGEFILE_INFORMATION Struct
    NextEntryOffset                                 DD
    CurrentSize                                     DD
    TotalUsed                                       DD
    PeakUsed                                        DD
    FileName                                        UNICODE_STRING
EndS

SYSTEM_INSTRUCTION_EMULATION_INFORMATION Struct
    SegmentNotPresent                               DD
    TwoByteOpcode                                   DD
    ESprefix                                        DD
    CSprefix                                        DD
    SSprefix                                        DD
    DSprefix                                        DD
    FSPrefix                                        DD
    GSprefix                                        DD
    OPER32prefix                                    DD
    ADDR32prefix                                    DD
    _INSB                                           DD  ;INSB
    _INSW                                           DD  ;INSW
    _OUTSB                                          DD  ;OUTSB
    _OUTSW                                          DD  ;OUTSW
    _PUSHFD                                         DD  ;PUSHFD
    _POPFD                                          DD  ;POPFD
    INTnn                                           DD
    _INTO                                           DD  ;INTO
    _IRETD                                          DD  ;IRETD
    INBimm                                          DD
    INWimm                                          DD
    OUTBimm                                         DD
    OUTWimm                                         DD
    INB                                             DD
    INW                                             DD
    OUTB                                            DD
    OUTW                                            DD
    LOCKprefix                                      DD
    REPNEprefix                                     DD
    REPprefix                                       DD
    _HLT                                            DD  ;HLT
    _CLI                                            DD  ;CLI
    _STI                                            DD  ;STI
    GenericInvalidOpcode                            DD
EndS

SYSTEM_CACHE_INFORMATION Struct
    SystemCacheWsSize                               DD
    SystemCacheWsPeakSize                           DD
    SystemCacheWsFaults                             DD
    SystemCacheWsMinimum                            DD
    SystemCacheWsMaximum                            DD
    TransitionSharedPages                           DD
    TransitionSharedPagesPeak                       DD
    Reserved                                        DD          2 Dup ?
EndS

SYSTEM_POOL_TAG_INFORMATION Struct
    Tag                                             DB          4 Dup ?
    PagedPoolAllocs                                 DD
    PagedPoolFrees                                  DD
    PagedPoolUsage                                  DD
    NonPagedPoolAllocs                              DD
    NonPagedPoolFrees                               DD
    NonPagedPoolUsage                               DD
EndS

SYSTEM_PROCESSOR_STATISTICS Struct
    ContextSwitches                                 DD
    DpcCount                                        DD
    DpcRequestRate                                  DD
    TimeIncrement                                   DD
    DpcBypassCount                                  DD
    ApcBypassCount                                  DD
EndS

SYSTEM_DPC_INFORMATION Struct
    Reserved                                        DD
    MaximumDpcQueueDepth                            DD
    MinimumDpcRate                                  DD
    AdjustDpcThreshold                              DD
    IdealDpcRate                                    DD
EndS

SYSTEM_LOAD_IMAGE Struct
    ModuleName                                      UNICODE_STRING
    ModuleBase                                      DD
    Unknown                                         DD
    EntryPoint                                      DD
    ExportDirectory                                 DD
EndS

SYSTEM_UNLOAD_IMAGE Struct
    ModuleBase                                      DD
EndS

SYSTEM_QUERY_TIME_ADJUSTMENT Struct
    TimeAdjustment                                  DD
    MaximumIncrement                                DD
    TimeSynchronization                             DB
EndS

SYSTEM_SET_TIME_ADJUSTMENT Struct
    TimeAdjustment                                  DD
    TimeSynchronization                             DB
EndS

SYSTEM_CRASH_DUMP_INFORMATION Struct
    CrashDumpSectionHandle                          DD
    Unknown                                         DD
EndS

SYSTEM_EXCEPTION_INFORMATION Struct
    AlignmentFixupCount                             DD
    ExceptionDispatchCount                          DD
    FloatingEmulationCount                          DD
    Reserved                                        DD
EndS

SYSTEM_CRASH_DUMP_STATE_INFORMATION Struct
    CrashDumpSectionExists                          DD
    Unknown                                         DD
EndS

SYSTEM_KERNEL_DEBUGGER_INFORMATION Struct
    DebuggerEnabled                                 DB
    DebuggerNotPresent                              DB
EndS

SYSTEM_CONTEXT_SWITCH_INFORMATION Struct
    ContextSwitches                                 DD
    ContextSwitchCounters                           DD          11 Dup ?
EndS

SYSTEM_REGISTRY_QUOTA_INFORMATION Struct
    RegistryQuota                                   DD
    RegistryQuotaInUse                              DD
    PagedPoolSize                                   DD
EndS

SYSTEM_LOAD_AND_CALL_IMAGE Struct
    ModuleName                                      UNICODE_STRING
EndS

SYSTEM_PRIORITY_SEPARATION Struct
    PrioritySeparation                              DD
EndS

SYSTEM_TIME_ZONE_INFORMATION Struct
    Bias                                            DD
    StandardName                                    DW          32 Dup ?
    StandardDate                                    SYSTEMTIME
    StandardBias                                    DD
    DaylightName                                    DW          32 Dup ?
    DaylightDate                                    SYSTEMTIME
    DaylightBias                                    DD
EndS

SYSTEM_LOOKASIDE_INFORMATION Struct
    Depth                                           DW
    MaximumDepth                                    DW
    TotalAllocates                                  DD
    AllocateMisses                                  DD
    TotalFrees                                      DD
    FreeMisses                                      DD
    Type                                            DD
    Tag                                             DD
    Size                                            DD
EndS

SYSTEM_SET_TIME_SLIP_EVENT Struct
    TimeSlipEvent                                   DD
EndS

SYSTEM_CREATE_SESSION Struct
    SessionId                                       DD
EndS

SYSTEM_DELETE_SESSION Struct
    SessionId                                       DD
EndS

SYSTEM_RANGE_START_INFORMATION Struct
    SystemRangeStart                                DD
EndS

SYSTEM_SESSION_PROCESSES_INFORMATION Struct
    SessionId                                       DD
    BufferSize                                      DD
    Buffer                                          DD
EndS

SYSTEM_POOL_BLOCK Struct
    Allocated                                       DB
    Unknown                                         DW
    Size                                            DD
    Tag                                             DB          4 Dup ?
EndS

SYSTEM_POOL_BLOCKS_INFORMATION Struct
    PoolSize                                        DD
    PoolBase                                        DD
    Unknown                                         DW
    NumberOfBlocks                                  DD
    PoolBlocks                                      SYSTEM_POOL_BLOCK 1 Dup ?
EndS

SYSTEM_MEMORY_USAGE Struct
    Name                                            DD
    Valid                                           DW
    Standby                                         DW
    Modified                                        DW
    PageTables                                      DW
EndS

SYSTEM_MEMORY_USAGE_INFORMATION Struct
    Reserved                                        DD
    EndOfData                                       DD
    MemoryUsage                                     SYSTEM_MEMORY_USAGE 1 Dup ?
EndS

;DEBUG_CONTROL_CODE Enumeration
DebugGetTraceInformation                            Equ         1
DebugSetInternalBreakpoint                          Equ         2
DebugSetSpecialCall                                 Equ         3
DebugClearSpecialCalls                              Equ         4
DebugQuerySpecialCalls                              Equ         5
DebugDbgBreakPoint                                  Equ         6

DBGKD_INTERNAL_BP_FLAG_COUNTONLY                    Equ         01H
DBGKD_INTERNAL_BP_FLAG_INVALID                      Equ         02H
DBGKD_INTERNAL_BP_FLAG_SUSPENDED                    Equ         04H
DBGKD_INTERNAL_BP_FLAG_DYING                        Equ         08H

DBGKD_GET_INTERNAL_BREAKPOINT Struct
    BreakpointAddress                               DD
    Flags                                           DD
    Calls                                           DD
    MaxCallsPerPeriod                               DD
    MinInstructions                                 DD
    MaxInstructions                                 DD
    TotalInstructions                               DD
EndS

DBGKD_SET_INTERNAL_BREAKPOINT Struct
    BreakpointAddress                               DD
    Flags                                           DD
EndS

DBGKD_QUERY_SPECIAL_CALLS Struct
    NumberOfSpecialCalls                            DD
EndS

#ENDIF ;UNDOC_H
