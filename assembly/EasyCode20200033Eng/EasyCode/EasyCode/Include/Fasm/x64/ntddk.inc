;=============================================================;
;                                                             ;
;       ntddk.inc for Easy Code 2.0 Fasm 64-bit drivers       ;
;                      (version 1.0.7)                        ;
;                                                             ;
;              Driver Development Kit (64-bit)                ;
;                                                             ;
;            Copyright © Ramon Sala - 2015-2020               ;
;                                                             ;
;=============================================================;

if ~defined NTDDK_INC
define NTDDK_INC 1

if ~defined TYPEDEF
    macro TYPEDEF type, base {
        restruc type
        purge type

        struc type [v] \{ \common . base v \}
        macro type [v] \{ \common base v \}

        virtual at 0
            local label, sizeof
            label type ?
            sizeof = $ - label
            sizeof.#type = sizeof
            SIZEOF.#type = sizeof
            SizeOf.#type = sizeof
        end virtual
    }
end if

macro extrn def
{
    define state 0
    match ename =as name:size, def
    \{
        if used name
            extrn ename as name:size
        end if
        define state 1
    \}
    match =0 ename =as name, state def
    \{
        if used name
            extrn ename as name
        end if
        define state 1
    \}
    match =0 name:size, state def
    \{
        if used name
            extrn name:size
        end if
        define state 1
    \}
    match =0, state
    \{
    if used def
        extrn def
    end if
    \}
}

macro CTL_CODE Name,DeviceType,Function,Method,Access {
    Name=(((DeviceType) shl 16) or ((Access) shl 14) or ((Function) shl 2) or (Method))
}

TYPEDEF                                         xptr,   dq

NTDDI_WIN95                                     equ     003000000H
NTDDI_WIN98_ME                                  equ     003001000H
NTDDI_WIN9XALL                                  equ     00300FFFFH

NTDDI_WINNT4                                    equ     004000000H
NTDDI_WINNT4ALL                                 equ     00400FFFFH

NTDDI_WIN2K                                     equ     005000000H
NTDDI_WIN2KSP1                                  equ     005000100H
NTDDI_WIN2KSP2                                  equ     005000200H
NTDDI_WIN2KSP3                                  equ     005000300H
NTDDI_WIN2KSP4                                  equ     005000400H
NTDDI_WIN2KALL                                  equ     00500FFFFH

NTDDI_WINXP                                     equ     005010000H
NTDDI_WINXPSP1                                  equ     005010100H
NTDDI_WINXPSP2                                  equ     005010200H
NTDDI_WINXPSP3                                  equ     005010300H
NTDDI_WINXPSP4                                  equ     005010400H
NTDDI_WINXPALL                                  equ     00501FFFFH

NTDDI_WS03                                      equ     005020000H
NTDDI_WS03SP1                                   equ     005020100H
NTDDI_WS03SP2                                   equ     005020200H
NTDDI_WS03SP3                                   equ     005020300H
NTDDI_WS03SP4                                   equ     005020400H
NTDDI_WS03ALL                                   equ     00502FFFFH

NTDDI_WIN6                                      equ     006000000H
NTDDI_WIN6SP1                                   equ     006000100H
NTDDI_WIN6SP2                                   equ     006000200H
NTDDI_WIN6SP3                                   equ     006000300H
NTDDI_WIN6SP4                                   equ     006000400H
NTDDI_WIN6ALL                                   equ     00600FFFFH

NTDDI_VISTA                                     equ     NTDDI_WIN6
NTDDI_VISTASP1                                  equ     NTDDI_WIN6SP1
NTDDI_VISTASP2                                  equ     NTDDI_WIN6SP2
NTDDI_VISTASP3                                  equ     NTDDI_WIN6SP3
NTDDI_VISTASP4                                  equ     NTDDI_WIN6SP4
NTDDI_VISTALL                                   equ     NTDDI_WIN6ALL

NTDDI_LONGHORN                                  equ     NTDDI_VISTA

NTDDI_WS08                                      equ     NTDDI_WIN6SP1
NTDDI_WS08SP2                                   equ     NTDDI_WIN6SP2
NTDDI_WS08SP3                                   equ     NTDDI_WIN6SP3
NTDDI_WS08SP4                                   equ     NTDDI_WIN6SP4

NTDDI_WIN7                                      equ     006010000H
NTDDI_WIN7SP1                                   equ     006010100H
NTDDI_WIN7ALL                                   equ     00601FFFFH

NTDDI_WIN8                                      equ     006020000H
NTDDI_WIN81                                     equ     006030000H
NTDDI_WIN8ALL                                   equ     00603FFFFH

NTDDI_WIN10                                     equ     010000000H

WIN32_IE_IE20                                   equ     00200H
WIN32_IE_IE30                                   equ     00300H
WIN32_IE_IE40                                   equ     00400H
WIN32_IE_IE50                                   equ     00500H
WIN32_IE_IE55                                   equ     00550H
WIN32_IE_IE60                                   equ     00600H
WIN32_IE_IE60SP1                                equ     00601H
WIN32_IE_IE60SP2                                equ     00603H
WIN32_IE_IE70                                   equ     00700H
WIN32_IE_IE80                                   equ     00800H
WIN32_IE_IE90                                   equ     00900H
WIN32_IE_ALL                                    equ     0FFFFH

WIN32_IE_IE200                                  equ     0200H
WIN32_IE_IE300                                  equ     0300H
WIN32_IE_IE302                                  equ     0302H
WIN32_IE_IE400                                  equ     0400H
WIN32_IE_IE401                                  equ     0401H
WIN32_IE_IE500                                  equ     0500H
WIN32_IE_IE501                                  equ     0501H
WIN32_IE_IE550                                  equ     0550H
WIN32_IE_IE600                                  equ     0600H
WIN32_IE_IE601                                  equ     0601H
WIN32_IE_IE603                                  equ     0603H
WIN32_IE_IE700                                  equ     0700H
WIN32_IE_IE800                                  equ     0800H
WIN32_IE_IE900                                  equ     0900H

WIN32_WINNT_NT4                                 equ     0400H
WIN32_WINNT_WIN2K                               equ     0500H
WIN32_WINNT_WINXP                               equ     0501H
WIN32_WINNT_WS03                                equ     0502H
WIN32_WINNT_WIN6                                equ     0600H
WIN32_WINNT_VISTA                               equ     0600H
WIN32_WINNT_WS08                                equ     0600H
WIN32_WINNT_LONGHORN                            equ     0600H
WIN32_WINNT_WIN7                                equ     0601H
WIN32_WINNT_WIN8                                equ     0602H
WIN32_WINNT_WIN81                               equ     0603H
WIN32_WINNT_WIN10                               equ     0604H   ;?

OSVERSION_MASK                                  equ     0FFFF0000H
SPVERSION_MASK                                  equ     00000FF00H
SUBVERSION_MASK                                 equ     0000000FFH

MAX_PATH                                        equ     260

ANYSIZE_ARRAY                                   equ     1

TYPEDEF                                         BCHAR, dw
TYPEDEF                                         SCHAR, dw
TYPEDEF                                         TCHAR, dw

if ~defined FILE_SHARE_READ
    FILE_SHARE_READ                             equ     1H
    FILE_SHARE_WRITE                            equ     2H
end if

if ~defined FILE_ATTRIBUTE_READONLY
    FILE_ATTRIBUTE_READONLY                     equ     1H
    FILE_ATTRIBUTE_HIDDEN                       equ     2H
    FILE_ATTRIBUTE_SYSTEM                       equ     4H
    FILE_ATTRIBUTE_DIRECTORY                    equ     10H
    FILE_ATTRIBUTE_ARCHIVE                      equ     20H
    FILE_ATTRIBUTE_NORMAL                       equ     80H
    FILE_ATTRIBUTE_TEMPORARY                    equ     100H
    FILE_ATTRIBUTE_COMPRESSED                   equ     800H
end if

if ~defined FILE_DEVICE_BEEP
    FILE_DEVICE_BEEP                            equ     00000001H
    FILE_DEVICE_CD_ROM                          equ     00000002H
    FILE_DEVICE_CD_ROM_FILE_SYSTEM              equ     00000003H
    FILE_DEVICE_CONTROLLER                      equ     00000004H
    FILE_DEVICE_DATALINK                        equ     00000005H
    FILE_DEVICE_DFS                             equ     00000006H
    FILE_DEVICE_DISK                            equ     00000007H
    FILE_DEVICE_DISK_FILE_SYSTEM                equ     00000008H
    FILE_DEVICE_FILE_SYSTEM                     equ     00000009H
    FILE_DEVICE_INPORT_PORT                     equ     0000000AH
    FILE_DEVICE_KEYBOARD                        equ     0000000BH
    FILE_DEVICE_MAILSLOT                        equ     0000000CH
    FILE_DEVICE_MIDI_IN                         equ     0000000DH
    FILE_DEVICE_MIDI_OUT                        equ     0000000EH
    FILE_DEVICE_MOUSE                           equ     0000000FH
    FILE_DEVICE_MULTI_UNC_PROVIDER              equ     00000010H
    FILE_DEVICE_NAMED_PIPE                      equ     00000011H
    FILE_DEVICE_NETWORK                         equ     00000012H
    FILE_DEVICE_NETWORK_BROWSER                 equ     00000013H
    FILE_DEVICE_NETWORK_FILE_SYSTEM             equ     00000014H
    FILE_DEVICE_NULL                            equ     00000015H
    FILE_DEVICE_PARALLEL_PORT                   equ     00000016H
    FILE_DEVICE_PHYSICAL_NETCARD                equ     00000017H
    FILE_DEVICE_PRINTER                         equ     00000018H
    FILE_DEVICE_SCANNER                         equ     00000019H
    FILE_DEVICE_SERIAL_MOUSE_PORT               equ     0000001AH
    FILE_DEVICE_SERIAL_PORT                     equ     0000001BH
    FILE_DEVICE_SCREEN                          equ     0000001CH
    FILE_DEVICE_SOUND                           equ     0000001DH
    FILE_DEVICE_STREAMS                         equ     0000001EH
    FILE_DEVICE_TAPE                            equ     0000001FH
    FILE_DEVICE_TAPE_FILE_SYSTEM                equ     00000020H
    FILE_DEVICE_TRANSPORT                       equ     00000021H
    FILE_DEVICE_UNKNOWN                         equ     00000022H
    FILE_DEVICE_VIDEO                           equ     00000023H
    FILE_DEVICE_VIRTUAL_DISK                    equ     00000024H
    FILE_DEVICE_WAVE_IN                         equ     00000025H
    FILE_DEVICE_WAVE_OUT                        equ     00000026H
    FILE_DEVICE_8042_PORT                       equ     00000027H
    FILE_DEVICE_NETWORK_REDIRECTOR              equ     00000028H
    FILE_DEVICE_BATTERY                         equ     00000029H
    FILE_DEVICE_BUS_EXTENDER                    equ     0000002AH
    FILE_DEVICE_MODEM                           equ     0000002BH
    FILE_DEVICE_VDM                             equ     0000002CH
    FILE_DEVICE_MASS_STORAGE                    equ     0000002DH
    FILE_DEVICE_SMB                             equ     0000002EH
    FILE_DEVICE_KS                              equ     0000002FH
    FILE_DEVICE_CHANGER                         equ     00000030H
    FILE_DEVICE_SMARTCARD                       equ     00000031H
    FILE_DEVICE_ACPI                            equ     00000032H
    FILE_DEVICE_DVD                             equ     00000033H
    FILE_DEVICE_FULLSCREEN_VIDEO                equ     00000034H
    FILE_DEVICE_DFS_FILE_SYSTEM                 equ     00000035H
    FILE_DEVICE_DFS_VOLUME                      equ     00000036H
    FILE_DEVICE_SERENUM                         equ     00000037H
    FILE_DEVICE_TERMSRV                         equ     00000038H
    FILE_DEVICE_KSEC                            equ     00000039H
    FILE_DEVICE_FIPS                            equ     0000003AH
    FILE_DEVICE_INFINIBAND                      equ     0000003BH
    FILE_DEVICE_VMBUS                           equ     0000003EH
    FILE_DEVICE_CRYPT_PROVIDER                  equ     0000003FH
    FILE_DEVICE_WPD                             equ     00000040H
    FILE_DEVICE_BLUETOOTH                       equ     00000041H
    FILE_DEVICE_MT_COMPOSITE                    equ     00000042H
    FILE_DEVICE_MT_TRANSPORT                    equ     00000043H
    FILE_DEVICE_BIOMETRIC                       equ     00000044H
    FILE_DEVICE_PMI                             equ     00000045H
    FILE_DEVICE_SECURE_OPEN                     equ     00000100H
end if

if ~defined FILE_SYNCHRONOUS_IO_ALERT
    FILE_SYNCHRONOUS_IO_ALERT                   equ     00000010H
    FILE_SYNCHRONOUS_IO_NONALERT                equ     00000020H
    FILE_OVERWRITE_IF                           equ     5  
end if

if ~defined DELETE
    DELETE                                      equ     00010000H
    READ_CONTROL                                equ     00020000H
    WRITE_DAC                                   equ     00040000H
    WRITE_OWNER                                 equ     00080000H
    SYNCHRONIZE                                 equ     00100000H
end if

if ~defined STANDARD_RIGHTS_REQUIRED
    STANDARD_RIGHTS_REQUIRED                    equ     000F0000H
    STANDARD_RIGHTS_READ                        equ     READ_CONTROL
    STANDARD_RIGHTS_WRITE                       equ     READ_CONTROL
    STANDARD_RIGHTS_EXECUTE                     equ     READ_CONTROL
    STANDARD_RIGHTS_ALL                         equ     001F0000H
end if

if ~defined FILE_READ_DATA
    FILE_READ_DATA                              equ     1H
    FILE_LIST_DIRECTORY                         equ     1H
    FILE_WRITE_DATA                             equ     2H
    FILE_ADD_FILE                               equ     2H

    FILE_APPEND_DATA                            equ     4H
    FILE_ADD_SUBDIRECTORY                       equ     4H
    FILE_CREATE_PIPE_INSTANCE                   equ     4H
    FILE_READ_EA                                equ     8H
    FILE_READ_PROPERTIES                        equ     FILE_READ_EA
    FILE_WRITE_EA                               equ     10H
    FILE_WRITE_PROPERTIES                       equ     FILE_WRITE_EA
    FILE_EXECUTE                                equ     20H
    FILE_TRAVERSE                               equ     20H
    FILE_DELETE_CHILD                           equ     40H
    FILE_READ_ATTRIBUTES                        equ     80H
    FILE_WRITE_ATTRIBUTES                       equ     100H

    FILE_ALL_ACCESS                             equ     (STANDARD_RIGHTS_REQUIRED or SYNCHRONIZE or 1FFH)
    FILE_SHARE_READ                             equ     1H
    FILE_SHARE_WRITE                            equ     2H
end if

if ~defined FILE_ATTRIBUTE_READONLY
    FILE_ATTRIBUTE_READONLY                     equ     1H
    FILE_ATTRIBUTE_HIDDEN                       equ     2H
    FILE_ATTRIBUTE_SYSTEM                       equ     4H
    FILE_ATTRIBUTE_DIRECTORY                    equ     10H
    FILE_ATTRIBUTE_ARCHIVE                      equ     20H
    FILE_ATTRIBUTE_NORMAL                       equ     80H
    FILE_ATTRIBUTE_TEMPORARY                    equ     100H
    FILE_ATTRIBUTE_COMPRESSED                   equ     800H
end if

if ~defined GENERIC_READ
    GENERIC_READ                                equ     080000000H
    GENERIC_WRITE                               equ     040000000H
    GENERIC_EXECUTE                             equ     020000000H
    GENERIC_ALL                                 equ     010000000H
end if

OPEN_EXISTING                                   equ     3H
INVALID_HANDLE_VALUE                            equ     (-1)

STATUS_SUCCESS                                  equ     0
STATUS_DEVICE_CONFIGURATION_ERROR               equ     0C0000182H
STATUS_INVALID_DEVICE_REQUEST                   equ     0C0000010H
STATUS_NOT_IMPLEMENTED                          equ     0C0000002H
STATUS_INFO_LENGTH_MISMATCH                     equ     0C0000004H

OBJ_INHERIT                                     equ     00000002H
OBJ_PERMANENT                                   equ     00000010H
OBJ_EXCLUSIVE                                   equ     00000020H
OBJ_CASE_INSENSITIVE                            equ     00000040H
OBJ_OPENIF                                      equ     00000080H
OBJ_OPENLINK                                    equ     00000100H
OBJ_KERNEL_HANDLE                               equ     00000200H
OBJ_VALID_ATTRIBUTES                            equ     000003F2H

IRP_MJ_CREATE                                   equ     00H
IRP_MJ_CREATE_NAMED_PIPE                        equ     01H
IRP_MJ_CLOSE                                    equ     02H
IRP_MJ_READ                                     equ     03H
IRP_MJ_WRITE                                    equ     04H
IRP_MJ_QUERY_INFORMATION                        equ     05H
IRP_MJ_SET_INFORMATION                          equ     06H
IRP_MJ_QUERY_EA                                 equ     07H
IRP_MJ_SET_EA                                   equ     08H
IRP_MJ_FLUSH_BUFFERS                            equ     09H
IRP_MJ_QUERY_VOLUME_INFORMATION                 equ     0AH
IRP_MJ_SET_VOLUME_INFORMATION                   equ     0BH
IRP_MJ_DIRECTORY_CONTROL                        equ     0CH
IRP_MJ_FILE_SYSTEM_CONTROL                      equ     0DH
IRP_MJ_DEVICE_CONTROL                           equ     0EH
IRP_MJ_INTERNAL_DEVICE_CONTROL                  equ     0FH
IRP_MJ_SHUTDOWN                                 equ     10H
IRP_MJ_LOCK_CONTROL                             equ     11H
IRP_MJ_CLEANUP                                  equ     12H
IRP_MJ_CREATE_MAILSLOT                          equ     13H
IRP_MJ_QUERY_SECURITY                           equ     14H
IRP_MJ_SET_SECURITY                             equ     15H
IRP_MJ_POWER                                    equ     16H
IRP_MJ_SYSTEM_CONTROL                           equ     17H
IRP_MJ_DEVICE_CHANGE                            equ     18H
IRP_MJ_QUERY_QUOTA                              equ     19H
IRP_MJ_SET_QUOTA                                equ     1AH
IRP_MJ_PNP                                      equ     1BH
IRP_MJ_PNP_POWER                                equ     IRP_MJ_PNP
IRP_MJ_MAXIMUM_FUNCTION                         equ     1BH

IRP_MJ_SCSI                                     equ     IRP_MJ_INTERNAL_DEVICE_CONTROL

IO_NO_INCREMENT                                 equ     0
IO_CD_ROM_INCREMENT                             equ     1
IO_DISK_INCREMENT                               equ     1
IO_KEYBOARD_INCREMENT                           equ     6
IO_MAILSLOT_INCREMENT                           equ     2
IO_MOUSE_INCREMENT                              equ     6
IO_NAMED_PIPE_INCREMENT                         equ     2
IO_NETWORK_INCREMENT                            equ     2
IO_PARALLEL_INCREMENT                           equ     1
IO_SERIAL_INCREMENT                             equ     2
IO_SOUND_INCREMENT                              equ     8
IO_VIDEO_INCREMENT                              equ     1

SEMAPHORE_INCREMENT                             equ     1

SystemProcessInformation                        equ     5
NonPagedPool                                    equ     0

METHOD_BUFFERED                                 equ     0
METHOD_IN_DIRECT                                equ     1
METHOD_OUT_DIRECT                               equ     2
METHOD_NEITHER                                  equ     3

FILE_ANY_ACCESS                                 equ     0
FILE_SPECIAL_ACCESS                             equ     FILE_ANY_ACCESS
FILE_READ_ACCESS                                equ     00001H
FILE_WRITE_ACCESS                               equ     00002H

struct GUID
    Data1                                       dd      ?
    Data2                                       dw      ?
    Data3                                       dw      ?
    Data4                                       db      8 dup(?)
ends

if ~defined UNICODE_STRING_DEFINED
    define UNICODE_STRING_DEFINED 1
    struct UNICODE_STRING
        Length                                      dw      ?
        MaximumLength                               dw      ?
                                                    dd      ?   ;For Align 8
        Buffer                                      dq      ?
    ends
end if

struct DRIVER_EXTENSION
    DriverObject                                dq      ?
    AddDevice                                   dd      ?
    Count                                       dd      ?
    ServiceKeyName                              UNICODE_STRING
ends

struct DRIVER_OBJECT
    Type                                        dw      ?
    Size                                        dw      ?
                                                dd      ?   ;For Align 8
    DeviceObject                                dq      ?
    Flags                                       dd      ?
                                                dd      ?   ;For Align 8
    DriverStart                                 dq      ?
    DriverSize                                  dd      ?
                                                dd      ?   ;For Align 8
    DriverSection                               dq      ?
    DriverExtension                             dq      ?
    DriverName                                  UNICODE_STRING
    HardwareDatabase                            dq      ?
    FastIoDispatch                              dq      ?
    DriverInit                                  dq      ?
    DriverStartIo                               dq      ?
    DriverUnload                                dq      ?
    MajorFunction                               dq      (IRP_MJ_MAXIMUM_FUNCTION + 1) Dup(?)
ends

struct LIST_ENTRY
    Flink                                       dq      ?
    Blink                                       dq      ?
ends

struct IO_STATUS_BLOCK
    union
       Status                                   dd      ?
                                                dd      ?   ;For Align 8
       Pointer                                  dq      ?
    ends
    Information                                 dq      ?
ends

if ~defined DUMMYSTRUCTNAME_DEF
    DUMMYSTRUCTNAME_DEF equ 1
    struct DUMMYSTRUCTNAME
        LowPart                                 dd      ?
        HighPart                                dd      ?
    ends
    struct u
        LowPart                                 dd      ?
        HighPart                                dd      ?
    ends
end if

if ~defined LARGE_INTEGER_DEF
    LARGE_INTEGER_DEF equ 1
    struct LARGE_INTEGER
        union
            LowPart  dd ?
            HighPart dd ?
            QuadPart dq ?
        ends                  
    ends
end if

if ~defined ULARGE_INTEGER_DEF
    ULARGE_INTEGER_DEF equ 1
    struct ULARGE_INTEGER
        union
            LowPart  dd ?
            HighPart dd ?
            QuadPart dq ?
        ends                  
    ends
end if

struct KDEVICE_QUEUE_ENTRY
    DeviceListEntry                             LIST_ENTRY
    SortKey                                     dd      ?
    Inserted                                    db      ?
ends

struct KAPC
    Type                                        db      ?
    SpareByte0                                  db      ?
    Size                                        db      ?
    SpareByte1                                  db      ?
    SpareLong0                                  dq      ?
    Thread                                      dq      ?
    ApcListEntry                                LIST_ENTRY
    KernelRoutine                               dq      ?
    RundownRoutine                              dq      ?
    NormalRoutine                               dq      ?
    NormalContext                               dq      ?
    SystemArgument1                             dq      ?
    SystemArgument2                             dq      ?
    ApcStateIndex                               db      ?
    ApcMode                                     db      ?
    Inserted                                    db      ?
ends

struct OVERLAY
    union
        DeviceQueueEntry                        KDEVICE_QUEUE_ENTRY
        DriverContext                           dq      4 Dup(?)
    ends
    Thread                                      dq      ?
    AuxiliaryBuffer                             dq      ?
    Overlay.ListEntry                           LIST_ENTRY
    union
        CurrentStackLocation                    dq      ?
        PacketType                              dd      ?
    ends
    OriginalFileObject                          dq      ?
ends

struct ASYNCHRONOUSPARAMETERS
    UserApcRoutine                              dq      ?
    UserApcContext                              dq      ?
ends

struct _IRP
    Type                                        dw      ?
    Size                                        dw      ?
                                                dd      ?   ;For Align 8
    MdlAddress                                  dq      ?
    Flags                                       dd      ?
                                                dd      ?   ;For Align 8
    union
        AssociatedIrp.MasterIrp                 dq      ?
        AssociatedIrp.IrpCount                  dd      ?
        AssociatedIrp.SystemBuffer              dq      ?
    ends
    ThreadListEntry                             LIST_ENTRY
    IoStatus                                    IO_STATUS_BLOCK
    RequestorMode                               db      ?
    PendingReturned                             db      ?
    StackCount                                  db      ?
    CurrentLocation                             db      ?
    Cancel                                      db      ?
    CancelIrql                                  db      ?
    ApcEnvironment                              db      ?
    AllocationFlags                             db      ?
    UserIosb                                    dq      ?
    UserEvent                                   dq      ?
    union
        Overlay.AsynchronousParameters          ASYNCHRONOUSPARAMETERS
        Overlay.AllocationSize                  LARGE_INTEGER
    ends
    CancelRoutine                               dq      ?
    UserBuffer                                  dq      ?
    union
        Tail.Overlay                            OVERLAY
        Tail.Apc                                KAPC
        Tail.CompletionKey                      dq      ?
    ends
ends

struct CREATE
    SecurityContext                             dq      ?
    Options                                     dd      ?
    FileAttributes                              dw      ?
    ShareAccess                                 dw      ?
    EaLength                                    dd      ?
ends
struct READ
    dwLength                                    dd      ?
    Key                                         dd      ?
    ByteOffset                                  LARGE_INTEGER
ends
struct WRITE
    dwLength                                    dd      ?
    Key                                         dd      ?
    ByteOffset                                  LARGE_INTEGER
ends
struct DEVICEIOCONTROL
    OutputBufferLength                          dq      ?
    InputBufferLength                           dq      ?
    IoControlCode                               dd      ?
    Type3InputBuffer                            dq      ?
ends
struct SETLOCK
    bLock                                       db      ?
                                                db      3 Dup(?)
ends
struct OTHERS
    Argument1                                   dq      ?
    Argument2                                   dq      ?
    Argument3                                   dq      ?
    Argument4                                   dq      ?
ends

struct IO_STACK_LOCATION
    MajorFunction                               db      ?
    MinorFunction                               db      ?
    Flags                                       db      ?
    Control                                     db      ?
                                                dd      ?   ;For Align 8
    union ;Parameters
        Parameters.Create                       CREATE 
        Parameters.Read                         READ        
        Parameters.Write                        WRITE
        Parameters.DeviceIoControl              DEVICEIOCONTROL
        Parameters.SetLock                      SETLOCK
        Parameters.Others                       OTHERS
    ends
    DeviceObject                                dq      ?
    FileObject                                  dq      ?
    CompletionRoutine                           dq      ?
    Context                                     dq      ?
ends

struct OBJECT_ATTRIBUTES
    Length                                      dd      ?
                                                dd      ?   ;For Align 8
    RootDirectory                               dq      ?
    ObjectName                                  dq      ?
    Attributes                                  dd      ?
                                                dd      ?   ;For Align 8
    SecurityDescriptor                          dq      ?
    SecurityQualityOfService                    dq      ?
ends

end if ;NTDDK_INC
