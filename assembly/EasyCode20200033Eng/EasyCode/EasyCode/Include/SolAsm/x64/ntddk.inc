;=========================================================;
;                                                         ;
;    ntddk.inc for Easy Code 2.0 SolAsm 64-bit drivers    ;
;                     (version 1.0.0)                     ;
;                                                         ;
;              Copyright © Ramon Sala - 2018              ;
;                                                         ;
;=========================================================;

#ifndef NTDDK_INC
NTDDK_INC   equ 1

section "code"  class_code
section "data"  class_data
section "idata" class_imports
section "reloc" class_relocs
section "edata" class_exports
section "bss"   class_bss
section "rsrc"  class_rsrc

macro CTL_CODE
    marg Name,DeviceType,Function,Method,Access
    Name equ <(&DeviceType shl 16) or (&Access shl 14) or (&Function shl 2) or (&Method)>
endm

include ntstatus.inc

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

#ifndef NTDDI_VERSION
    #ifdef APP_WIN64
        NTDDI_VERSION                           equ     NTDDI_WINXP
    #else
        NTDDI_VERSION                           equ     NTDDI_WIN95
    #endif
#endif

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

#ifndef MAX_PATH_DEF
    MAX_PATH_DEF equ 1
    MAX_PATH                                    equ     260
#endif

#ifndef ANYSIZE_ARRAY_DEF
    ANYSIZE_ARRAY_DEF equ 1
    ANYSIZE_ARRAY                               equ     1
#endif

#ifdef APP_UNICODE
    define BCHAR                                dw
    define SCHAR                                dw
    define TCHAR                                dw
#else
    define BCHAR                                db
    define SCHAR                                db
    define TCHAR                                db
#endif

#ifndef NULL
    NULL                                        equ     0
    FALSE                                       equ     0
    TRUE                                        equ     1
#endif

#ifndef FILE_SHARE_READ
    FILE_SHARE_READ                             equ     1H
    FILE_SHARE_WRITE                            equ     2H
#endif

#ifndef FILE_ATTRIBUTE_READONLY
    FILE_ATTRIBUTE_READONLY                     equ     1H
    FILE_ATTRIBUTE_HIDDEN                       equ     2H
    FILE_ATTRIBUTE_SYSTEM                       equ     4H
    FILE_ATTRIBUTE_DIRECTORY                    equ     10H
    FILE_ATTRIBUTE_ARCHIVE                      equ     20H
    FILE_ATTRIBUTE_NORMAL                       equ     80H
    FILE_ATTRIBUTE_TEMPORARY                    equ     100H
    FILE_ATTRIBUTE_COMPRESSED                   equ     800H
#endif

#ifndef FILE_DEVICE_BEEP
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
#endif

#ifndef FILE_SYNCHRONOUS_IO_ALERT
    FILE_SYNCHRONOUS_IO_ALERT                   equ     00000010H
    FILE_SYNCHRONOUS_IO_NONALERT                equ     00000020H
    FILE_OVERWRITE_IF                           equ     5  
#endif

#ifndef DELETE
    DELETE                                      equ     00010000H
    READ_CONTROL                                equ     00020000H
    WRITE_DAC                                   equ     00040000H
    WRITE_OWNER                                 equ     00080000H
    SYNCHRONIZE                                 equ     00100000H
#endif

#ifndef STANDARD_RIGHTS_REQUIRED
    STANDARD_RIGHTS_REQUIRED                    equ     000F0000H
    STANDARD_RIGHTS_READ                        equ     READ_CONTROL
    STANDARD_RIGHTS_WRITE                       equ     READ_CONTROL
    STANDARD_RIGHTS_EXECUTE                     equ     READ_CONTROL
    STANDARD_RIGHTS_ALL                         equ     001F0000H
#endif

#ifndef FILE_READ_DATA
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

    FILE_ALL_ACCESS                             equ     <STANDARD_RIGHTS_REQUIRED or SYNCHRONIZE or 1FFH>
#endif

#ifndef FILE_ATTRIBUTE_READONLY
    FILE_ATTRIBUTE_READONLY                     equ     1H
    FILE_ATTRIBUTE_HIDDEN                       equ     2H
    FILE_ATTRIBUTE_SYSTEM                       equ     4H
    FILE_ATTRIBUTE_DIRECTORY                    equ     10H
    FILE_ATTRIBUTE_ARCHIVE                      equ     20H
    FILE_ATTRIBUTE_NORMAL                       equ     80H
    FILE_ATTRIBUTE_TEMPORARY                    equ     100H
    FILE_ATTRIBUTE_COMPRESSED                   equ     800H
#endif

#ifndef GENERIC_READ
    GENERIC_READ                                equ     080000000H
    GENERIC_WRITE                               equ     040000000H
    GENERIC_EXECUTE                             equ     020000000H
    GENERIC_ALL                                 equ     010000000H
#endif

OPEN_EXISTING                                   equ     3H
INVALID_HANDLE_VALUE                            equ     (-1)

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

;======================================== Structures ======================================;
#ifndef GUID_DEF
    GUID_DEF equ 1
    struc GUID
        Data1                                   dd ?
        Data2                                   dw ?
        Data3                                   dw ?
        Data4                                   rb 8
    ends
#endif

#ifndef UNICODE_STRING_DEF
    UNICODE_STRING_DEF equ 1
    struc UNICODE_STRING
        _Length                                 dw ?   ;Length
        MaximumLength                           dw ?
                                                dd ?   ;For Align 8
        Buffer                                  dq ?
    ends
#endif

struc DRIVER_EXTENSION
    DriverObject                                dq ?
    AddDevice                                   dd ?
    Count                                       dd ?
    ServiceKeyName                              UNICODE_STRING ?
ends

struc DRIVER_OBJECT
    _Type                                       dw ?   ;Type
    _Size                                       dw ?   ;Size
                                                dd ?   ;For Align 8
    DeviceObject                                dq ?
    Flags                                       dd ?
                                                dd ?   ;For Align 8
    DriverStart                                 dq ?
    DriverSize                                  dd ?
                                                dd ?   ;For Align 8
    DriverSection                               dq ?
    DriverExtension                             dq ?
    DriverName                                  UNICODE_STRING ?
    HardwareDatabase                            dq ?
    FastIoDispatch                              dq ?
    DriverInit                                  dq ?
    DriverStartIo                               dq ?
    DriverUnload                                dq ?
    MajorFunction                               rq <IRP_MJ_MAXIMUM_FUNCTION+1>
ends

#ifndef LIST_ENTRY_DEF
    LIST_ENTRY_DEF equ 1
    struc LIST_ENTRY
        Flink   dq ?
        Blink   dq ?
    ends
#endif
    
struc IO_STATUS_BLOCK
    union
       Status                                   dd ?
                                                dd ?   ;For Align 8
       Pointer                                  dq ?
    endu
    Information                                 dq ?
ends

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

struc KDEVICE_QUEUE_ENTRY
    DeviceListEntry                             LIST_ENTRY ?
    SortKey                                     dd      ?
    Inserted                                    db      ?
ends

struc KAPC
    _Type                                       db      ?   ;Type
    SpareByte0                                  db      ?
    _Size                                       db      ?   ;Size
    SpareByte1                                  db      ?
    SpareLong0                                  dq      ?
    Thread                                      dq      ?
    ApcListEntry                                LIST_ENTRY ?
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

struc OVERLAY
    union
        DeviceQueueEntry                        KDEVICE_QUEUE_ENTRY ?
        DriverContext                           rq      4
    endu
    Thread                                      dq      ?
    AuxiliaryBuffer                             dq      ?
    ListEntry                                   LIST_ENTRY ?
    union
        CurrentStackLocation                    dq      ?
        PacketType                              dd      ?
    endu
    OriginalFileObject                          dq      ?
ends

struc ASYNCHRONOUSPARAMETERS
    UserApcRoutine                              dq      ?
    UserApcContext                              dq      ?
ends

struc _IRP
    _Type                                       dw      ?   ;Type
    _Size                                       dw      ?   ;Size
                                                dd      ?   ;For Align 8
    MdlAddress                                  dq      ?
    Flags                                       dd      ?
                                                dd      ?   ;For Align 8
    union
        AssociatedIrp.MasterIrp                 dq      ?
        AssociatedIrp.IrpCount                  dd      ?
        AssociatedIrp.SystemBuffer              dq      ?
    endu
    ThreadListEntry                             LIST_ENTRY ?
    IoStatus                                    IO_STATUS_BLOCK ?
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
        AsynchronousParameters                  ASYNCHRONOUSPARAMETERS ?
        AllocationSize                          LARGE_INTEGER ?
    endu
    CancelRoutine                               dq      ?
    UserBuffer                                  dq      ?
    union
        Overlay                                 OVERLAY ?
        Apc                                     KAPC    ?
        CompletionKey                           dq      ?
    endu
ends

struc CREATE
    SecurityContext                             dq      ?
    Options                                     dd      ?
    FileAttributes                              dw      ?
    ShareAccess                                 dw      ?
    EaLength                                    dd      ?
ends
struc READ
    dwLength                                    dd      ?
    Key                                         dd      ?
    ByteOffset                                  LARGE_INTEGER ?
ends
struc WRITE
    dwLength                                    dd      ?
    Key                                         dd      ?
    ByteOffset                                  LARGE_INTEGER ?
ends
struc DEVICEIOCONTROL
    OutputBufferLength                          dq      ?
    InputBufferLength                           dq      ?
    IoControlCode                               dd      ?
    Type3InputBuffer                            dq      ?
ends
struc SETLOCK
    bLock                                       db      ?
                                                rb      3
ends
struc OTHERS
    Argument1                                   dq      ?
    Argument2                                   dq      ?
    Argument3                                   dq      ?
    Argument4                                   dq      ?
ends

struc IO_STACK_LOCATION
    MajorFunction                               db      ?
    MinorFunction                               db      ?
    Flags                                       db      ?
    Control                                     db      ?
                                                dd      ?   ;For Align 8
    union
        Create                                  CREATE  ?
        Read                                    READ    ?
        Write                                   WRITE   ?
        DeviceIoControl                         DEVICEIOCONTROL ?
        SetLock                                 SETLOCK ?
        Others                                  OTHERS  ?
    endu
    DeviceObject                                dq      ?
    FileObject                                  dq      ?
    CompletionRoutine                           dq      ?
    Context                                     dq      ?
ends

struc OBJECT_ATTRIBUTES
    _Length                                     dd      ?   ;Length
                                                dd      ?   ;For Align 8
    RootDirectory                               dq      ?
    ObjectName                                  dq      ?
    Attributes                                  dd      ?
                                                dd      ?   ;For Align 8
    SecurityDescriptor                          dq      ?
    SecurityQualityOfService                    dq      ?
ends

#endif ;NTDDK_INC
