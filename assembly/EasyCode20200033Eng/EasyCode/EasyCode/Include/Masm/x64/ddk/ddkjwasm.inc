;===================================================================;
;                                                                   ;
;    ddkjwasm.inc for Easy Code 2.0 JWasm 64-bit driver projects    ;
;                        (version 1.0.1)                            ;
;                                                                   ;
;                  Driver Development Kit (64-bit)                  ;
;                                                                   ;
;                Copyright © Ramon Sala - 2015-2020                 ;
;                                                                   ;
;===================================================================;

IFNDEF DDKJWASM_INC
DDKJWASM_INC    EQU 1

CTL_CODE MACRO DeviceType:=<0>, Function:=<0>, Method:=<0>, Access:=<0>
    EXITM %(((DeviceType) SHL 16) OR ((Access) SHL 14) OR ((Function) SHL 2) OR (Method))
ENDM

IFNDEF UNICODE_STRING_DEFINED
	UNICODE_STRING_DEFINED EQU 1
    UNICODE_STRING STRUCT
        _Length                                     DW      ?   ;Length
        MaximumLength                               DW      ?
                                                    DD      ?   ;For Align 8
        Buffer                                      DQ      ?
    UNICODE_STRING ENDS
    PUNICODE_STRING                                 TYPEDEF QWORD
ENDIF

DRIVER_EXTENSION STRUCT
    DriverObject                                PDRIVER_OBJECT  ?
    AddDevice                                   DD          ?
    Count                                       DD          ?
    ServiceKeyName                              UNICODE_STRING  <>
DRIVER_EXTENSION ENDS
PDRIVER_EXTENSION                               TYPEDEF QWORD

DRIVER_OBJECT STRUCT
    _Type                                       DW      ?   ;Type
    _Size                                       DW      ?   ;Size
                                                DD      ?   ;For Align 8
    DeviceObject                                PDEVICE_OBJECT  ?
    Flags                                       DD      ?
                                                DD      ?   ;For Align 8
    DriverStart                                 PVOID   ?
    DriverSize                                  DD      ?
                                                DD      ?   ;For Align 8
    DriverSection                               PVOID   ?
    DriverExtension                             PDRIVER_EXTENSION ?
    DriverName                                  UNICODE_STRING  <>
    HardwareDatabase                            PUNICODE_STRING ?
    FastIoDispatch                              PFAST_IO_DISPATCH ?
    DriverInit                                  DQ      ?
    DriverStartIo                               DQ      ?
    DriverUnload                                DQ      ?
    MajorFunction                               DQ      (IRP_MJ_MAXIMUM_FUNCTION + 1) Dup(?)
DRIVER_OBJECT ENDS

LIST_ENTRY STRUCT
    Flink                                       DQ      ?
    Blink                                       DQ      ?
LIST_ENTRY ENDS
    
IO_STATUS_BLOCK STRUCT
    UNION
       Status                                   NTSTATUS ?
       Pointer                                  PVOID   ?
    ENDS
    Information                                 ULONG_PTR ?
IO_STATUS_BLOCK ENDS
PIO_STATUS_BLOCK                                TYPEDEF QWORD

LARGE_INTEGER UNION
    STRUCT
        LowPart                                 DD      ?
        HighPart                                DD      ?
    ENDS
    QuadPart                                    DQ      ?
LARGE_INTEGER ENDS

KDEVICE_QUEUE_ENTRY STRUCT
    DeviceListEntry                             LIST_ENTRY  <>
    SortKey                                     DD      ?
    Inserted                                    BOOLEAN ?
KDEVICE_QUEUE_ENTRY ENDS

KAPC STRUCT
    _Type                                       DB      ?   ;Type
    SpareByte0                                  DB      ?
    _Size                                       DB      ?   ;Size
    SpareByte1                                  DB      ?
    SpareLong0                                  DD      ?
    Thread                                      DD      ?
    ApcListEntry                                LIST_ENTRY  <>
    KernelRoutine                               DD      ?
    RundownRoutine                              DD      ?
    NormalRoutine                               DD      ?
    NormalContext                               PVOID   ?
    SystemArgument1                             PVOID   ?
    SystemArgument2                             PVOID   ?
    ApcStateIndex                               DB      ?
    ApcMode                                     KPROCESSOR_MODE ?
    Inserted                                    BOOLEAN ?
KAPC ENDS
PKAPC                                           TYPEDEF QWORD

_IRP STRUCT
    _Type                                       DW      ?   ;Type
    _Size                                       DW      ?   ;Size
                                                DD      ?   ;For Align 8
    MdlAddress                                  PVOID   ?
    Flags                                       DD      ?
                                                DD      ?   ;For Align 8
    UNION AssociatedIrp
        MasterIrp                               PVOID   ?
        IrpCount                                DD      ?
        SystemBuffer                            PVOID   ?
    ENDS
    ThreadListEntry                             LIST_ENTRY  <>
    IoStatus                                    IO_STATUS_BLOCK <>
    RequestorMode                               KPROCESSOR_MODE ?
    PendingReturned                             BOOLEAN ?
    StackCount                                  DB      ?
    CurrentLocation                             DB      ?
    Cancel                                      BOOLEAN ?
    CancelIrql                                  KIRQL   ?
    ApcEnvironment                              DB      ?
    AllocationFlags                             DB      ?
    UserIosb                                    PIO_STATUS_BLOCK    ?
    UserEvent                                   PKEVENT ?
    UNION Overlay
        STRUCT AsynchronousParameters
            UserApcRoutine                      PVOID   ?
            UserApcContext                      PVOID   ?
        ENDS
        AllocationSize                          LARGE_INTEGER   <>
    ENDS
    CancelRoutine                               PVOID   ?
    UserBuffer                                  PVOID   ?
    UNION Tail
        STRUCT Overlay
            UNION
                DeviceQueueEntry                KDEVICE_QUEUE_ENTRY <>
                STRUCT
                    DriverContext               PVOID   4 Dup(?)
                ENDS
            ENDS
            Thread                              PVOID   ?
            AuxiliaryBuffer                     PCHAR   ?
            STRUCT
                ListEntry                       LIST_ENTRY  <>
                UNION
                    CurrentStackLocation        PVOID   ?
                    PacketType                  DD      ?
                ENDS
            ENDS
            OriginalFileObject                  PFILE_OBJECT ?
        ENDS
        Apc                                     KAPC    <>
        CompletionKey                           PVOID   ?
    ENDS
_IRP ENDS
PIRP                                            TYPEDEF QWORD

IO_STACK_LOCATION STRUCT
    MajorFunction                               DB      ?
    MinorFunction                               DB      ?
    Flags                                       DB      ?
    Control                                     DB      ?
                                                DD      ?   ;For Align 8
    UNION Parameters
        STRUCT Create
            SecurityContext                     PVOID   ?
            Options                             DD      ?
            FileAttributes                      DW      ?
            ShareAccess                         DW      ?
            EaLength                            DD      ?
        ENDS
        STRUCT Read
            dwLength                            DD      ?
            Key                                 DD      ?
            ByteOffset                          LARGE_INTEGER <>
        ENDS
        STRUCT Write
            dwLength                            DD      ?
            Key                                 DD      ?
            ByteOffset                          LARGE_INTEGER <>
        ENDS
        STRUCT DeviceIoControl
            OutputBufferLength                  DQ      ?
            InputBufferLength                   DQ      ?
            IoControlCode                       DD      ?
            Type3InputBuffer                    PVOID   ?
        ENDS
        STRUCT SetLock
            bLock                               BOOLEAN ?
                                                DB      3 Dup(?)
        ENDS
        STRUCT Others
            Argument1                           PVOID   ?
            Argument2                           PVOID   ?
            Argument3                           PVOID   ?
            Argument4                           PVOID   ?
        ENDS
    ENDS
    DeviceObject                                PDEVICE_OBJECT ?
    FileObject                                  PFILE_OBJECT ?
    CompletionRoutine                           PVOID   ?
    Context                                     PVOID   ?
IO_STACK_LOCATION ENDS
PIO_STACK_LOCATION                              TYPEDEF QWORD

OBJECT_ATTRIBUTES STRUCT
    _Length                                     DQ      ?   ;Length
    RootDirectory                               HANDLE  ?
    ObjectName                                  PUNICODE_STRING ?
    Attributes                                  DQ      ?
    SecurityDescriptor                          PVOID   ?
    SecurityQualityOfService                    PVOID   ?
OBJECT_ATTRIBUTES ENDS
POBJECT_ATTRIBUTES                              TYPEDEF QWORD

ENDIF ;DDKJWASM_INC
