;===================================================================;
;                                                                   ;
;    ntddk.inc for Easy Code 2.0 JWasm/Masm/PoAsm 64-bit drivers    ;
;                        (version 1.0.0)                            ;
;                                                                   ;
;                 Driver Development Kit (64-bit)                   ;
;                                                                   ;
;                  Copyright © Ramon Sala - 2015                    ;
;                                                                   ;
;===================================================================;

IFNDEF NTDDK_INC
NTDDK_INC	EQU 1

NTDDI_WIN95                                     EQU     003000000H
NTDDI_WIN98_ME                                  EQU     003001000H
NTDDI_WIN9XALL                                  EQU     00300FFFFH

NTDDI_WINNT4                                    EQU     004000000H
NTDDI_WINNT4ALL                                 EQU     00400FFFFH

NTDDI_WIN2K                                     EQU     005000000H
NTDDI_WIN2KSP1                                  EQU     005000100H
NTDDI_WIN2KSP2                                  EQU     005000200H
NTDDI_WIN2KSP3                                  EQU     005000300H
NTDDI_WIN2KSP4                                  EQU     005000400H
NTDDI_WIN2KALL                                  EQU     00500FFFFH

NTDDI_WINXP                                     EQU     005010000H
NTDDI_WINXPSP1                                  EQU     005010100H
NTDDI_WINXPSP2                                  EQU     005010200H
NTDDI_WINXPSP3                                  EQU     005010300H
NTDDI_WINXPSP4                                  EQU     005010400H
NTDDI_WINXPALL                                  EQU     00501FFFFH

NTDDI_WS03                                      EQU     005020000H
NTDDI_WS03SP1                                   EQU     005020100H
NTDDI_WS03SP2                                   EQU     005020200H
NTDDI_WS03SP3                                   EQU     005020300H
NTDDI_WS03SP4                                   EQU     005020400H
NTDDI_WS03ALL                                   EQU     00502FFFFH

NTDDI_WIN6                                      EQU     006000000H
NTDDI_WIN6SP1                                   EQU     006000100H
NTDDI_WIN6SP2                                   EQU     006000200H
NTDDI_WIN6SP3                                   EQU     006000300H
NTDDI_WIN6SP4                                   EQU     006000400H
NTDDI_WIN6ALL                                   EQU     00600FFFFH

NTDDI_VISTA                                     EQU     NTDDI_WIN6
NTDDI_VISTASP1                                  EQU     NTDDI_WIN6SP1
NTDDI_VISTASP2                                  EQU     NTDDI_WIN6SP2
NTDDI_VISTASP3                                  EQU     NTDDI_WIN6SP3
NTDDI_VISTASP4                                  EQU     NTDDI_WIN6SP4
NTDDI_VISTALL                                   EQU     NTDDI_WIN6ALL

NTDDI_LONGHORN                                  EQU     NTDDI_VISTA

NTDDI_WS08                                      EQU     NTDDI_WIN6SP1
NTDDI_WS08SP2                                   EQU     NTDDI_WIN6SP2
NTDDI_WS08SP3                                   EQU     NTDDI_WIN6SP3
NTDDI_WS08SP4                                   EQU     NTDDI_WIN6SP4

NTDDI_WIN7                                      EQU     006010000H
NTDDI_WIN7SP1                                   EQU     006010100H
NTDDI_WIN7ALL                                   EQU     00601FFFFH

NTDDI_WIN8                                      EQU     006020000H
NTDDI_WIN81                                     EQU     006030000H
NTDDI_WIN8ALL                                   EQU     00603FFFFH

NTDDI_WIN10                                     EQU     010000000H

IFNDEF NTDDI_VERSION
    IFDEF APP_WIN64
        NTDDI_VERSION                           EQU     NTDDI_WINXP
    ELSE
        NTDDI_VERSION                           EQU     NTDDI_WIN95
    ENDIF
ENDIF

WIN32_IE_IE20                                   EQU     00200H
WIN32_IE_IE30                                   EQU     00300H
WIN32_IE_IE40                                   EQU     00400H
WIN32_IE_IE50                                   EQU     00500H
WIN32_IE_IE55                                   EQU     00550H
WIN32_IE_IE60                                   EQU     00600H
WIN32_IE_IE60SP1                                EQU     00601H
WIN32_IE_IE60SP2                                EQU     00603H
WIN32_IE_IE70                                   EQU     00700H
WIN32_IE_IE80                                   EQU     00800H
WIN32_IE_IE90                                   EQU     00900H
WIN32_IE_ALL                                    EQU     0FFFFH

WIN32_IE_IE200                                  EQU     0200H
WIN32_IE_IE300                                  EQU     0300H
WIN32_IE_IE302                                  EQU     0302H
WIN32_IE_IE400                                  EQU     0400H
WIN32_IE_IE401                                  EQU     0401H
WIN32_IE_IE500                                  EQU     0500H
WIN32_IE_IE501                                  EQU     0501H
WIN32_IE_IE550                                  EQU     0550H
WIN32_IE_IE600                                  EQU     0600H
WIN32_IE_IE601                                  EQU     0601H
WIN32_IE_IE603                                  EQU     0603H
WIN32_IE_IE700                                  EQU     0700H
WIN32_IE_IE800                                  EQU     0800H
WIN32_IE_IE900                                  EQU     0900H

WIN32_WINNT_NT4                                 EQU     0400H
WIN32_WINNT_WIN2K                               EQU     0500H
WIN32_WINNT_WINXP                               EQU     0501H
WIN32_WINNT_WS03                                EQU     0502H
WIN32_WINNT_WIN6                                EQU     0600H
WIN32_WINNT_VISTA                               EQU     0600H
WIN32_WINNT_WS08                                EQU     0600H
WIN32_WINNT_LONGHORN                            EQU     0600H
WIN32_WINNT_WIN7                                EQU     0601H
WIN32_WINNT_WIN8                                EQU     0602H
WIN32_WINNT_WIN81                               EQU     0603H
WIN32_WINNT_WIN10                               EQU     0604H   ;?

OSVERSION_MASK                                  EQU     0FFFF0000H
SPVERSION_MASK                                  EQU     00000FF00H
SUBVERSION_MASK                                 EQU     0000000FFH

MAX_PATH                                        EQU     260

ANYSIZE_ARRAY                                   EQU     1

IFDEF APP_UNICODE
    BCHAR                                       TYPEDEF WORD
    SCHAR                                       TYPEDEF WORD
    TCHAR                                       TYPEDEF WORD
ELSE
    BCHAR                                       TYPEDEF BYTE
    SCHAR                                       TYPEDEF BYTE
    TCHAR                                       TYPEDEF BYTE
ENDIF

ACCESS_MASK                                     TYPEDEF DWORD
ATOM                                            TYPEDEF WORD
BOOL                                            TYPEDEF DWORD
BOOLEAN                                         TYPEDEF BYTE
CALID                                           TYPEDEF DWORD
CALTYPE                                         TYPEDEF DWORD
CHAR                                            TYPEDEF BYTE
COLORREF                                        TYPEDEF DWORD
DATE                                            TYPEDEF QWORD
DOUBLE                                          TYPEDEF QWORD
DWORD32                                         TYPEDEF DWORD
DWORD64                                         TYPEDEF QWORD
DWORDLONG                                       TYPEDEF QWORD
FILEOP_FLAGS                                    TYPEDEF WORD
FLOAT                                           TYPEDEF DWORD
HFILE                                           TYPEDEF DWORD
INT16                                           TYPEDEF WORD
INT32                                           TYPEDEF DWORD
INT64                                           TYPEDEF QWORD
LANGID                                          TYPEDEF WORD
LCID                                            TYPEDEF DWORD
LCTYPE                                          TYPEDEF DWORD
LGRPID                                          TYPEDEF DWORD
LONG                                            TYPEDEF DWORD
LONG32                                          TYPEDEF DWORD
LONG64                                          TYPEDEF QWORD
LONGLONG                                        TYPEDEF QWORD
MCIDEVICEID                                     TYPEDEF DWORD
SCODE                                           TYPEDEF DWORD
UBYTE                                           TYPEDEF BYTE
UCHAR                                           TYPEDEF BYTE
UINT                                            TYPEDEF DWORD
UINT8                                           TYPEDEF BYTE
UINT16                                          TYPEDEF WORD
UINT32                                          TYPEDEF DWORD
UINT64                                          TYPEDEF QWORD
ULONG                                           TYPEDEF DWORD
ULONG32                                         TYPEDEF DWORD
ULONG64                                         TYPEDEF QWORD
ULONGLONG                                       TYPEDEF QWORD
USHORT                                          TYPEDEF WORD
USN                                             TYPEDEF QWORD
WCHAR                                           TYPEDEF WORD
VARIANT_BOOL                                    TYPEDEF WORD
VARTYPE                                         TYPEDEF WORD

DWORD_PTR                                       TYPEDEF QWORD
HACCEL                                          TYPEDEF QWORD
HANDLE                                          TYPEDEF QWORD
HGLRC                                           TYPEDEF QWORD
HTASK                                           TYPEDEF QWORD
HWINEVENTHOOK                                   TYPEDEF QWORD
INT_PTR                                         TYPEDEF QWORD
LONG_PTR                                        TYPEDEF QWORD
LPARAM                                          TYPEDEF QWORD
LPBOOL                                          TYPEDEF QWORD
LPBYTE                                          TYPEDEF QWORD
LPCOLORREF                                      TYPEDEF QWORD
LPCSTR                                          TYPEDEF QWORD
LPCTSTR                                         TYPEDEF QWORD
LPCVOID                                         TYPEDEF QWORD
LPCWSTR                                         TYPEDEF QWORD
LPDWORD                                         TYPEDEF QWORD
LPHANDLE                                        TYPEDEF QWORD
LPLONG                                          TYPEDEF QWORD
LPSTR                                           TYPEDEF QWORD
LPTSTR                                          TYPEDEF QWORD
LPVOID                                          TYPEDEF QWORD
LPWORD                                          TYPEDEF QWORD
LPWSTR                                          TYPEDEF QWORD
LRESULT                                         TYPEDEF QWORD
PBOOLEAN                                        TYPEDEF QWORD
PDWORD32                                        TYPEDEF QWORD
PHALF_PTR                                       TYPEDEF QWORD
PINT16                                          TYPEDEF QWORD
PINT32                                          TYPEDEF QWORD
PINT64                                          TYPEDEF QWORD
PINT8                                           TYPEDEF QWORD
PINT_PTR                                        TYPEDEF QWORD
PLONG_PTR                                       TYPEDEF QWORD
PUINT32                                         TYPEDEF QWORD
PUINT64                                         TYPEDEF QWORD
PUINT_PTR                                       TYPEDEF QWORD
PULONG                                          TYPEDEF QWORD
PULONGLONG                                      TYPEDEF QWORD
PSCODE                                          TYPEDEF QWORD
PLONG32                                         TYPEDEF QWORD
PULONG32                                        TYPEDEF QWORD
PVOID                                           TYPEDEF QWORD
PWSTR                                           TYPEDEF QWORD
SOCKET                                          TYPEDEF QWORD
UINT_PTR                                        TYPEDEF QWORD
ULONG_PTR                                       TYPEDEF QWORD
WNDPROC                                         TYPEDEF QWORD

HBITMAP                                         TYPEDEF HANDLE
HBRUSH                                          TYPEDEF HANDLE
HCOLORSPACE                                     TYPEDEF HANDLE
HCONV                                           TYPEDEF HANDLE
HCONVLIST                                       TYPEDEF HANDLE
HCURSOR                                         TYPEDEF HANDLE
HDC                                             TYPEDEF HANDLE
HDDEDATA                                        TYPEDEF HANDLE
HDESK                                           TYPEDEF HANDLE
HDROP                                           TYPEDEF HANDLE
HDWP                                            TYPEDEF HANDLE
HENHMETAFILE                                    TYPEDEF HANDLE
HFONT                                           TYPEDEF HANDLE
HGDIOBJ                                         TYPEDEF HANDLE
HGLOBAL                                         TYPEDEF HANDLE
HHOOK                                           TYPEDEF HANDLE
HICON                                           TYPEDEF HANDLE
HINSTANCE                                       TYPEDEF HANDLE
HKEY                                            TYPEDEF HANDLE
HKL                                             TYPEDEF HANDLE
HLOCAL                                          TYPEDEF HANDLE
HMENU                                           TYPEDEF HANDLE
HMETAFILE                                       TYPEDEF HANDLE
HMODULE                                         TYPEDEF HINSTANCE
HMONITOR                                        TYPEDEF HANDLE
HPALETTE                                        TYPEDEF HANDLE
HPEN                                            TYPEDEF HANDLE
HRESULT                                         TYPEDEF LONG
HRGN                                            TYPEDEF HANDLE
HRSRC                                           TYPEDEF HANDLE
HSZ                                             TYPEDEF HANDLE
HWINSTA                                         TYPEDEF HANDLE
HWND                                            TYPEDEF HANDLE
SIZE_T                                          TYPEDEF ULONG_PTR
size_t                                          TYPEDEF SIZE_T
WPARAM                                          TYPEDEF UINT_PTR

NULL                                            EQU     0
FALSE                                           EQU     0
TRUE                                            EQU     1

KPROCESSOR_MODE                                 TYPEDEF BYTE

KIRQL                                           TYPEDEF BYTE
PKIRQL                                          TYPEDEF QWORD

IFNDEF KSPIN_LOCK
    KSPIN_LOCK                                  TYPEDEF DWORD
    PKSPIN_LOCK                                 TYPEDEF QWORD
ENDIF

IFNDEF NTSTATUS
    NTSTATUS                                    TYPEDEF DWORD
    PNTSTATUS                                   TYPEDEF QWORD
ENDIF

IFNDEF PCHAR
    PCHAR                                       TYPEDEF QWORD
ENDIF

IFNDEF FILE_SHARE_READ
    FILE_SHARE_READ                             EQU     1H
    FILE_SHARE_WRITE                            EQU     2H
ENDIF

IFNDEF FILE_ATTRIBUTE_READONLY
    FILE_ATTRIBUTE_READONLY                     EQU     1H
    FILE_ATTRIBUTE_HIDDEN                       EQU     2H
    FILE_ATTRIBUTE_SYSTEM                       EQU     4H
    FILE_ATTRIBUTE_DIRECTORY                    EQU     10H
    FILE_ATTRIBUTE_ARCHIVE                      EQU     20H
    FILE_ATTRIBUTE_NORMAL                       EQU     80H
    FILE_ATTRIBUTE_TEMPORARY                    EQU     100H
    FILE_ATTRIBUTE_COMPRESSED                   EQU     800H
ENDIF

IFNDEF FILE_DEVICE_BEEP
    FILE_DEVICE_BEEP                            EQU     00000001H
    FILE_DEVICE_CD_ROM                          EQU     00000002H
    FILE_DEVICE_CD_ROM_FILE_SYSTEM              EQU     00000003H
    FILE_DEVICE_CONTROLLER                      EQU     00000004H
    FILE_DEVICE_DATALINK                        EQU     00000005H
    FILE_DEVICE_DFS                             EQU     00000006H
    FILE_DEVICE_DISK                            EQU     00000007H
    FILE_DEVICE_DISK_FILE_SYSTEM                EQU     00000008H
    FILE_DEVICE_FILE_SYSTEM                     EQU     00000009H
    FILE_DEVICE_INPORT_PORT                     EQU     0000000AH
    FILE_DEVICE_KEYBOARD                        EQU     0000000BH
    FILE_DEVICE_MAILSLOT                        EQU     0000000CH
    FILE_DEVICE_MIDI_IN                         EQU     0000000DH
    FILE_DEVICE_MIDI_OUT                        EQU     0000000EH
    FILE_DEVICE_MOUSE                           EQU     0000000FH
    FILE_DEVICE_MULTI_UNC_PROVIDER              EQU     00000010H
    FILE_DEVICE_NAMED_PIPE                      EQU     00000011H
    FILE_DEVICE_NETWORK                         EQU     00000012H
    FILE_DEVICE_NETWORK_BROWSER                 EQU     00000013H
    FILE_DEVICE_NETWORK_FILE_SYSTEM             EQU     00000014H
    FILE_DEVICE_NULL                            EQU     00000015H
    FILE_DEVICE_PARALLEL_PORT                   EQU     00000016H
    FILE_DEVICE_PHYSICAL_NETCARD                EQU     00000017H
    FILE_DEVICE_PRINTER                         EQU     00000018H
    FILE_DEVICE_SCANNER                         EQU     00000019H
    FILE_DEVICE_SERIAL_MOUSE_PORT               EQU     0000001AH
    FILE_DEVICE_SERIAL_PORT                     EQU     0000001BH
    FILE_DEVICE_SCREEN                          EQU     0000001CH
    FILE_DEVICE_SOUND                           EQU     0000001DH
    FILE_DEVICE_STREAMS                         EQU     0000001EH
    FILE_DEVICE_TAPE                            EQU     0000001FH
    FILE_DEVICE_TAPE_FILE_SYSTEM                EQU     00000020H
    FILE_DEVICE_TRANSPORT                       EQU     00000021H
    FILE_DEVICE_UNKNOWN                         EQU     00000022H
    FILE_DEVICE_VIDEO                           EQU     00000023H
    FILE_DEVICE_VIRTUAL_DISK                    EQU     00000024H
    FILE_DEVICE_WAVE_IN                         EQU     00000025H
    FILE_DEVICE_WAVE_OUT                        EQU     00000026H
    FILE_DEVICE_8042_PORT                       EQU     00000027H
    FILE_DEVICE_NETWORK_REDIRECTOR              EQU     00000028H
    FILE_DEVICE_BATTERY                         EQU     00000029H
    FILE_DEVICE_BUS_EXTENDER                    EQU     0000002AH
    FILE_DEVICE_MODEM                           EQU     0000002BH
    FILE_DEVICE_VDM                             EQU     0000002CH
    FILE_DEVICE_MASS_STORAGE                    EQU     0000002DH
    FILE_DEVICE_SMB                             EQU     0000002EH
    FILE_DEVICE_KS                              EQU     0000002FH
    FILE_DEVICE_CHANGER                         EQU     00000030H
    FILE_DEVICE_SMARTCARD                       EQU     00000031H
    FILE_DEVICE_ACPI                            EQU     00000032H
    FILE_DEVICE_DVD                             EQU     00000033H
    FILE_DEVICE_FULLSCREEN_VIDEO                EQU     00000034H
    FILE_DEVICE_DFS_FILE_SYSTEM                 EQU     00000035H
    FILE_DEVICE_DFS_VOLUME                      EQU     00000036H
    FILE_DEVICE_SERENUM                         EQU     00000037H
    FILE_DEVICE_TERMSRV                         EQU     00000038H
    FILE_DEVICE_KSEC                            EQU     00000039H
    FILE_DEVICE_FIPS                            EQU     0000003AH
    FILE_DEVICE_INFINIBAND                      EQU     0000003BH
    FILE_DEVICE_VMBUS                           EQU     0000003EH
    FILE_DEVICE_CRYPT_PROVIDER                  EQU     0000003FH
    FILE_DEVICE_WPD                             EQU     00000040H
    FILE_DEVICE_BLUETOOTH                       EQU     00000041H
    FILE_DEVICE_MT_COMPOSITE                    EQU     00000042H
    FILE_DEVICE_MT_TRANSPORT                    EQU     00000043H
    FILE_DEVICE_BIOMETRIC                       EQU     00000044H
    FILE_DEVICE_PMI                             EQU     00000045H
    FILE_DEVICE_SECURE_OPEN                     EQU     00000100H
ENDIF

IFNDEF FILE_SYNCHRONOUS_IO_ALERT
    FILE_SYNCHRONOUS_IO_ALERT                   EQU     00000010H
    FILE_SYNCHRONOUS_IO_NONALERT                EQU     00000020H
    FILE_OVERWRITE_IF                           EQU     5  
ENDIF

IFNDEF DELETE
    DELETE                                      EQU     00010000H
    READ_CONTROL                                EQU     00020000H
    WRITE_DAC                                   EQU     00040000H
    WRITE_OWNER                                 EQU     00080000H
    SYNCHRONIZE                                 EQU     00100000H
ENDIF

IFNDEF STANDARD_RIGHTS_REQUIRED
    STANDARD_RIGHTS_REQUIRED                    EQU     000F0000H
    STANDARD_RIGHTS_READ                        EQU     READ_CONTROL
    STANDARD_RIGHTS_WRITE                       EQU     READ_CONTROL
    STANDARD_RIGHTS_EXECUTE                     EQU     READ_CONTROL
    STANDARD_RIGHTS_ALL                         EQU     001F0000H
ENDIF

IFNDEF FILE_READ_DATA
    FILE_READ_DATA                              EQU     1H
    FILE_LIST_DIRECTORY                         EQU     1H
    FILE_WRITE_DATA                             EQU     2H
    FILE_ADD_FILE                               EQU     2H

    FILE_APPEND_DATA                            EQU     4H
    FILE_ADD_SUBDIRECTORY                       EQU     4H
    FILE_CREATE_PIPE_INSTANCE                   EQU     4H
    FILE_READ_EA                                EQU     8H
    FILE_READ_PROPERTIES                        EQU     FILE_READ_EA
    FILE_WRITE_EA                               EQU     10H
    FILE_WRITE_PROPERTIES                       EQU     FILE_WRITE_EA
    FILE_EXECUTE                                EQU     20H
    FILE_TRAVERSE                               EQU     20H
    FILE_DELETE_CHILD                           EQU     40H
    FILE_READ_ATTRIBUTES                        EQU     80H
    FILE_WRITE_ATTRIBUTES                       EQU     100H

    FILE_ALL_ACCESS                             EQU     (STANDARD_RIGHTS_REQUIRED OR SYNCHRONIZE OR 1FFH)
    FILE_SHARE_READ                             EQU     1H
    FILE_SHARE_WRITE                            EQU     2H
ENDIF

IFNDEF FILE_ATTRIBUTE_READONLY
    FILE_ATTRIBUTE_READONLY                     EQU     1H
    FILE_ATTRIBUTE_HIDDEN                       EQU     2H
    FILE_ATTRIBUTE_SYSTEM                       EQU     4H
    FILE_ATTRIBUTE_DIRECTORY                    EQU     10H
    FILE_ATTRIBUTE_ARCHIVE                      EQU     20H
    FILE_ATTRIBUTE_NORMAL                       EQU     80H
    FILE_ATTRIBUTE_TEMPORARY                    EQU     100H
    FILE_ATTRIBUTE_COMPRESSED                   EQU     800H
ENDIF

IFNDEF GENERIC_READ
    GENERIC_READ                                EQU     080000000H
    GENERIC_WRITE                               EQU     040000000H
    GENERIC_EXECUTE                             EQU     020000000H
    GENERIC_ALL                                 EQU     010000000H
ENDIF

OPEN_EXISTING                                   EQU     3H
INVALID_HANDLE_VALUE                            EQU     (-1)

STATUS_SUCCESS                                  EQU     0
STATUS_DEVICE_CONFIGURATION_ERROR               EQU     0C0000182H
STATUS_INVALID_DEVICE_REQUEST                   EQU     0C0000010H
STATUS_NOT_IMPLEMENTED                          EQU     0C0000002H

OBJ_INHERIT                                     EQU     00000002H
OBJ_PERMANENT                                   EQU     00000010H
OBJ_EXCLUSIVE                                   EQU     00000020H
OBJ_CASE_INSENSITIVE                            EQU     00000040H
OBJ_OPENIF                                      EQU     00000080H
OBJ_OPENLINK                                    EQU     00000100H
OBJ_KERNEL_HANDLE                               EQU     00000200H
OBJ_VALID_ATTRIBUTES                            EQU     000003F2H

IRP_MJ_CREATE                                   EQU     00H
IRP_MJ_CREATE_NAMED_PIPE                        EQU     01H
IRP_MJ_CLOSE                                    EQU     02H
IRP_MJ_READ                                     EQU     03H
IRP_MJ_WRITE                                    EQU     04H
IRP_MJ_QUERY_INFORMATION                        EQU     05H
IRP_MJ_SET_INFORMATION                          EQU     06H
IRP_MJ_QUERY_EA                                 EQU     07H
IRP_MJ_SET_EA                                   EQU     08H
IRP_MJ_FLUSH_BUFFERS                            EQU     09H
IRP_MJ_QUERY_VOLUME_INFORMATION                 EQU     0AH
IRP_MJ_SET_VOLUME_INFORMATION                   EQU     0BH
IRP_MJ_DIRECTORY_CONTROL                        EQU     0CH
IRP_MJ_FILE_SYSTEM_CONTROL                      EQU     0DH
IRP_MJ_DEVICE_CONTROL                           EQU     0EH
IRP_MJ_INTERNAL_DEVICE_CONTROL                  EQU     0FH
IRP_MJ_SHUTDOWN                                 EQU     10H
IRP_MJ_LOCK_CONTROL                             EQU     11H
IRP_MJ_CLEANUP                                  EQU     12H
IRP_MJ_CREATE_MAILSLOT                          EQU     13H
IRP_MJ_QUERY_SECURITY                           EQU     14H
IRP_MJ_SET_SECURITY                             EQU     15H
IRP_MJ_POWER                                    EQU     16H
IRP_MJ_SYSTEM_CONTROL                           EQU     17H
IRP_MJ_DEVICE_CHANGE                            EQU     18H
IRP_MJ_QUERY_QUOTA                              EQU     19H
IRP_MJ_SET_QUOTA                                EQU     1AH
IRP_MJ_PNP                                      EQU     1BH
IRP_MJ_PNP_POWER                                EQU     IRP_MJ_PNP
IRP_MJ_MAXIMUM_FUNCTION                         EQU     1BH

IRP_MJ_SCSI                                     EQU     IRP_MJ_INTERNAL_DEVICE_CONTROL

IO_NO_INCREMENT                                 EQU     0
IO_CD_ROM_INCREMENT                             EQU     1
IO_DISK_INCREMENT                               EQU     1
IO_KEYBOARD_INCREMENT                           EQU     6
IO_MAILSLOT_INCREMENT                           EQU     2
IO_MOUSE_INCREMENT                              EQU     6
IO_NAMED_PIPE_INCREMENT                         EQU     2
IO_NETWORK_INCREMENT                            EQU     2
IO_PARALLEL_INCREMENT                           EQU     1
IO_SERIAL_INCREMENT                             EQU     2
IO_SOUND_INCREMENT                              EQU     8
IO_VIDEO_INCREMENT                              EQU     1

SEMAPHORE_INCREMENT                             EQU     1

SystemProcessInformation                        EQU     5
NonPagedPool                                    EQU     0

METHOD_BUFFERED                                 EQU     0
METHOD_IN_DIRECT                                EQU     1
METHOD_OUT_DIRECT                               EQU     2
METHOD_NEITHER                                  EQU     3

FILE_ANY_ACCESS                                 EQU     0
FILE_SPECIAL_ACCESS                             EQU     FILE_ANY_ACCESS
FILE_READ_ACCESS                                EQU     00001H
FILE_WRITE_ACCESS                               EQU     00002H

PDEVICE_OBJECT                                  TYPEDEF QWORD
PDRIVER_OBJECT                                  TYPEDEF QWORD
PFAST_IO_DISPATCH                               TYPEDEF QWORD
PKEVENT                                         TYPEDEF QWORD
PCHAR                                           TYPEDEF QWORD
PFILE_OBJECT                                    TYPEDEF QWORD

IFDEF JWASM_COMPILER
    Include ddkjwasm.inc
ELSEIFDEF POASM_COMPILER
    Include ddkpoasm.inc
ELSE
    Include ddkmasm.inc
ENDIF

ENDIF ;NTDDK_INC
