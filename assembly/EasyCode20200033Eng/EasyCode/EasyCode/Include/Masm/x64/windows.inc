; =======================================================;
;                                                        ;
;   windows.inc for Easy Code 2.0 64-bit Masm projects   ;
;                    (version 1.0.11)                    ;
;                                                        ;
;         Copyright © Ramon Sala - 2015-2021             ;
;                                                        ;
; =======================================================;

IFNDEF WINDOWS_INC
WINDOWS_INC     EQU     1

IFDEF APP_WIN64
    IFNDEF ALIGNMODE
        IFDEF POASM_COMPILER
            ALIGNMODE                           TEXTEQU <>
        ELSE
            ALIGNMODE                           TEXTEQU <16>
        ENDIF
    ENDIF
    XPTR                                        TYPEDEF QWORD
    XWORD                                       TYPEDEF QWORD
    ENUM                                        TYPEDEF QWORD
ELSE
    IFNDEF ALIGNMODE
        ALIGNMODE                               TEXTEQU <4>
    ENDIF
    XPTR                                        TYPEDEF DWORD
    XWORD                                       TYPEDEF DWORD
    ENUM                                        TYPEDEF DWORD
ENDIF

Include macros.inc

;========================================= windef =========================================;
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
NTDDI_WINBLUE                                   EQU     NTDDI_WIN81
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

IFNDEF TYPES_INC
    Include types.inc
ENDIF

IFNDEF WM_USER
    WM_USER                                     EQU     400H
ENDIF

IFNDEF MAXLONG
    MAXLONG                                     EQU     07FFFFFFFH
ENDIF

IFNDEF MAX_PATH
    MAX_PATH                                    EQU     260
ENDIF

ANYSIZE_ARRAY                                   EQU     1

NULL                                            EQU     0
FALSE                                           EQU     0
TRUE                                            EQU     1

Normal                                          EQU     0000000H
ReadOnly                                        EQU     0000001H
Hidden                                          EQU     0000010H
System                                          EQU     0000100H
vLabel                                          EQU     0001000H
SubDir                                          EQU     0010000H
Archive                                         EQU     0100000H
Black                                           EQU     0000000H
Blue                                            EQU     0FF0000H
Green                                           EQU     000FF00H
Cyan                                            EQU     0FFFF00H
Red                                             EQU     00000FFH
Magenta                                         EQU     0FF00FFH
Yellow                                          EQU     000FFFFH
White                                           EQU     0FFFFFFH
Gray                                            EQU     0080808H

HFILE_ERROR                                     EQU     (-1)

DM_UPDATE                                       EQU     1
DM_COPY                                         EQU     2
DM_PROMPT                                       EQU     4
DM_MODIFY                                       EQU     8

DM_IN_BUFFER                                    EQU     DM_MODIFY
DM_IN_PROMPT                                    EQU     DM_PROMPT
DM_OUT_BUFFER                                   EQU     DM_COPY
DM_OUT_DEFAULT                                  EQU     DM_UPDATE

DC_FIELDS                                       EQU     1
DC_PAPERS                                       EQU     2
DC_PAPERSIZE                                    EQU     3
DC_MINEXTENT                                    EQU     4
DC_MAXEXTENT                                    EQU     5
DC_BINS                                         EQU     6
DC_DUPLEX                                       EQU     7
DC_SIZE                                         EQU     8
DC_EXTRA                                        EQU     9
DC_VERSION                                      EQU     10
DC_DRIVER                                       EQU     11
DC_BINNAMES                                     EQU     12
DC_ENUMRESOLUTIONS                              EQU     13
DC_FILEDEPENDENCIES                             EQU     14
DC_TRUETYPE                                     EQU     15
DC_PAPERNAMES                                   EQU     16
DC_ORIENTATION                                  EQU     17
DC_COPIES                                       EQU     18

;====================================== winerror ==========================================;
FACILITY_XPS                                    EQU     82
FACILITY_WINRM                                  EQU     51
FACILITY_WINDOWSUPDATE                          EQU     36
FACILITY_WINDOWS_DEFENDER                       EQU     80
FACILITY_WINDOWS_CE                             EQU     24
FACILITY_WINDOWS                                EQU     8
FACILITY_USERMODE_VOLMGR                        EQU     56
FACILITY_USERMODE_VIRTUALIZATION                EQU     55
FACILITY_USERMODE_VHD                           EQU     58
FACILITY_URT                                    EQU     19
FACILITY_UMI                                    EQU     22
FACILITY_UI                                     EQU     42
FACILITY_TPM_SOFTWARE                           EQU     41
FACILITY_TPM_SERVICES                           EQU     40
FACILITY_SXS                                    EQU     23
FACILITY_STORAGE                                EQU     3
FACILITY_STATE_MANAGEMENT                       EQU     34
FACILITY_SSPI                                   EQU     9
FACILITY_SCARD                                  EQU     16
FACILITY_SHELL                                  EQU     39
FACILITY_SETUPAPI                               EQU     15
FACILITY_SECURITY                               EQU     9
FACILITY_SDIAG                                  EQU     60
FACILITY_RPC                                    EQU     1
FACILITY_RAS                                    EQU     83
FACILITY_PLA                                    EQU     48
FACILITY_OPC                                    EQU     81
FACILITY_WIN32                                  EQU     7
FACILITY_CONTROL                                EQU     10
FACILITY_WEBSERVICES                            EQU     61
FACILITY_NULL                                   EQU     0
FACILITY_NDIS                                   EQU     52
FACILITY_METADIRECTORY                          EQU     35
FACILITY_MSMQ                                   EQU     14
FACILITY_MEDIASERVER                            EQU     13
FACILITY_MBN                                    EQU     84
FACILITY_INTERNET                               EQU     12
FACILITY_ITF                                    EQU     4
FACILITY_USERMODE_HYPERVISOR                    EQU     53
FACILITY_HTTP                                   EQU     25
FACILITY_GRAPHICS                               EQU     38
FACILITY_FWP                                    EQU     50
FACILITY_FVE                                    EQU     49
FACILITY_USERMODE_FILTER_MANAGER                EQU     31
FACILITY_DPLAY                                  EQU     21
FACILITY_DISPATCH                               EQU     2
FACILITY_DIRECTORYSERVICE                       EQU     37
FACILITY_CONFIGURATION                          EQU     33
FACILITY_COMPLUS                                EQU     17
FACILITY_USERMODE_COMMONLOG                     EQU     26
FACILITY_CMI                                    EQU     54
FACILITY_CERT                                   EQU     11
FACILITY_BCD                                    EQU     57
FACILITY_BACKGROUNDCOPY                         EQU     32
FACILITY_ACS                                    EQU     20
FACILITY_AAF                                    EQU     18
FACILITY_USB_ERROR_CODE                         EQU     010H
FACILITY_TERMINAL_SERVER                        EQU     0AH
FACILITY_SXS_ERROR_CODE                         EQU     015H
FACILITY_RPC_STUBS                              EQU     03H
FACILITY_RPC_RUNTIME                            EQU     02H
FACILITY_IO_ERROR_CODE                          EQU     04H
FACILITY_HID_ERROR_CODE                         EQU     011H
FACILITY_FIREWIRE_ERROR_CODE                    EQU     012H
FACILITY_DEBUGGER                               EQU     01H
FACILITY_CLUSTER_ERROR_CODE                     EQU     013H
FACILITY_ACPI_ERROR_CODE                        EQU     014H
ERROR_SUCCESS                                   EQU     0
NO_ERROR                                        EQU     0
SEC_E_OK                                        EQU     00000000H
STATUS_SUCCESS                                  EQU     00000000H
STATUS_SEVERITY_WARNING                         EQU     02H
STATUS_SEVERITY_SUCCESS                         EQU     00H
STATUS_SEVERITY_INFORMATIONAL                   EQU     01H
STATUS_SEVERITY_ERROR                           EQU     03H
STATUS_WAIT_1                                   EQU     000000001H
STATUS_WAIT_2                                   EQU     000000002H
STATUS_WAIT_3                                   EQU     000000003H
STATUS_WAIT_63                                  EQU     00000003FH
STATUS_ABANDONED                                EQU     000000080H
STATUS_ABANDONED_WAIT_63                        EQU     0000000BFH
STATUS_KERNEL_APC                               EQU     000000100H
STATUS_ALERTED                                  EQU     000000101H
STATUS_REPARSE                                  EQU     000000104H
STATUS_MORE_ENTRIES                             EQU     000000105H
STATUS_NOT_ALL_ASSIGNED                         EQU     000000106H
STATUS_SOME_NOT_MAPPED                          EQU     000000107H
STATUS_OPLOCK_BREAK_IN_PROGRESS                 EQU     000000108H
STATUS_VOLUME_MOUNTED                           EQU     000000109H
STATUS_RXACT_COMMITTED                          EQU     00000010AH
STATUS_NOTIFY_CLEANUP                           EQU     00000010BH
STATUS_NOTIFY_ENUM_DIR                          EQU     00000010CH
STATUS_NO_QUOTAS_FOR_ACCOUNT                    EQU     00000010DH
STATUS_PRIMARY_TRANSPORT_CONNECT_FAILED         EQU     00000010EH
STATUS_PAGE_FAULT_TRANSITION                    EQU     000000110H
STATUS_PAGE_FAULT_DEMAND_ZERO                   EQU     000000111H
STATUS_PAGE_FAULT_COPY_ON_WRITE                 EQU     000000112H
STATUS_PAGE_FAULT_GUARD_PAGE                    EQU     000000113H
STATUS_PAGE_FAULT_PAGING_FILE                   EQU     000000114H
STATUS_CACHE_PAGE_LOCKED                        EQU     000000115H
STATUS_CRASH_DUMP                               EQU     000000116H
STATUS_BUFFER_ALL_ZEROS                         EQU     000000117H
STATUS_REPARSE_OBJECT                           EQU     000000118H
STATUS_RESOURCE_REQUIREMENTS_CHANGED            EQU     000000119H
STATUS_TRANSLATION_COMPLETE                     EQU     000000120H
STATUS_DS_MEMBERSHIP_EVALUATED_LOCALLY          EQU     000000121H
STATUS_NOTHING_TO_TERMINATE                     EQU     000000122H
STATUS_PROCESS_NOT_IN_JOB                       EQU     000000123H
STATUS_PROCESS_IN_JOB                           EQU     000000124H
STATUS_VOLSNAP_HIBERNATE_READY                  EQU     000000125H
STATUS_FSFILTER_OP_COMPLETED_SUCCESSFULLY       EQU     000000126H
STATUS_OBJECT_NAME_EXISTS                       EQU     040000000H
STATUS_THREAD_WAS_SUSPENDED                     EQU     040000001H
STATUS_WORKING_SET_LIMIT_RANGE                  EQU     040000002H
STATUS_IMAGE_NOT_AT_BASE                        EQU     040000003H
STATUS_RXACT_STATE_CREATED                      EQU     040000004H
STATUS_LOCAL_USER_SESSION_KEY                   EQU     040000006H
STATUS_BAD_CURRENT_DIRECTORY                    EQU     040000007H
STATUS_SERIAL_MORE_WRITES                       EQU     040000008H
STATUS_REGISTRY_RECOVERED                       EQU     040000009H
STATUS_FT_READ_RECOVERY_FROM_BACKUP             EQU     04000000AH
STATUS_FT_WRITE_RECOVERY                        EQU     04000000BH
STATUS_SERIAL_COUNTER_TIMEOUT                   EQU     04000000CH
STATUS_NULL_LM_PASSWORD                         EQU     04000000DH
STATUS_IMAGE_MACHINE_TYPE_MISMATCH              EQU     04000000EH
STATUS_RECEIVE_PARTIAL                          EQU     04000000FH
STATUS_RECEIVE_EXPEDITED                        EQU     040000010H
STATUS_RECEIVE_PARTIAL_EXPEDITED                EQU     040000011H
STATUS_EVENT_DONE                               EQU     040000012H
STATUS_EVENT_PENDING                            EQU     040000013H
STATUS_CHECKING_FILE_SYSTEM                     EQU     040000014H
STATUS_FATAL_APP_EXIT                           EQU     040000015H
STATUS_PREDEFINED_HANDLE                        EQU     040000016H
STATUS_WAS_UNLOCKED                             EQU     040000017H
STATUS_SERVICE_NOTIFICATION                     EQU     040000018H
STATUS_WAS_LOCKED                               EQU     040000019H
STATUS_LOG_HARD_ERROR                           EQU     04000001AH
STATUS_ALREADY_WIN32                            EQU     04000001BH
STATUS_WX86_UNSIMULATE                          EQU     04000001CH
STATUS_WX86_CONTINUE                            EQU     04000001DH
STATUS_WX86_SINGLE_STEP                         EQU     04000001EH
STATUS_WX86_BREAKPOINT                          EQU     04000001FH
STATUS_WX86_EXCEPTION_CONTINUE                  EQU     040000020H
STATUS_WX86_EXCEPTION_LASTCHANCE                EQU     040000021H
STATUS_WX86_EXCEPTION_CHAIN                     EQU     040000022H
STATUS_IMAGE_MACHINE_TYPE_MISMATCH_EXE          EQU     040000023H
STATUS_NO_YIELD_PERFORMED                       EQU     040000024H
STATUS_TIMER_RESUME_IGNORED                     EQU     040000025H
STATUS_ARBITRATION_UNHANDLED                    EQU     040000026H
STATUS_CARDBUS_NOT_SUPPORTED                    EQU     040000027H
STATUS_WX86_CREATEWX86TIB                       EQU     040000028H
STATUS_MP_PROCESSOR_MISMATCH                    EQU     040000029H
STATUS_HIBERNATED                               EQU     04000002AH
STATUS_RESUME_HIBERNATION                       EQU     04000002BH
STATUS_FIRMWARE_UPDATED                         EQU     04000002CH
STATUS_DRIVERS_LEAKING_LOCKED_PAGES             EQU     04000002DH
DBG_REPLY_LATER                                 EQU     040010001H
DBG_UNABLE_TO_PROVIDE_HANDLE                    EQU     040010002H
DBG_PRINTEXCEPTION_C                            EQU     040010006H
DBG_RIPEXCEPTION                                EQU     040010007H
STATUS_BUFFER_OVERFLOW                          EQU     080000005H
STATUS_NO_MORE_FILES                            EQU     080000006H
STATUS_WAKE_SYSTEM_DEBUGGER                     EQU     080000007H
STATUS_HANDLES_CLOSED                           EQU     08000000AH
STATUS_NO_INHERITANCE                           EQU     08000000BH
STATUS_GUID_SUBSTITUTION_MADE                   EQU     08000000CH
STATUS_PARTIAL_COPY                             EQU     08000000DH
STATUS_DEVICE_PAPER_EMPTY                       EQU     08000000EH
STATUS_DEVICE_POWERED_OFF                       EQU     08000000FH
STATUS_DEVICE_OFF_LINE                          EQU     080000010H
STATUS_DEVICE_BUSY                              EQU     080000011H
STATUS_NO_MORE_EAS                              EQU     080000012H
STATUS_INVALID_EA_NAME                          EQU     080000013H
STATUS_EA_LIST_INCONSISTENT                     EQU     080000014H
STATUS_INVALID_EA_FLAG                          EQU     080000015H
STATUS_VERIFY_REQUIRED                          EQU     080000016H
STATUS_EXTRANEOUS_INFORMATION                   EQU     080000017H
STATUS_RXACT_COMMIT_NECESSARY                   EQU     080000018H
STATUS_NO_MORE_ENTRIES                          EQU     08000001AH
STATUS_FILEMARK_DETECTED                        EQU     08000001BH
STATUS_MEDIA_CHANGED                            EQU     08000001CH
STATUS_BUS_RESET                                EQU     08000001DH
STATUS_END_OF_MEDIA                             EQU     08000001EH
STATUS_BEGINNING_OF_MEDIA                       EQU     08000001FH
STATUS_MEDIA_CHECK                              EQU     080000020H
STATUS_SETMARK_DETECTED                         EQU     080000021H
STATUS_NO_DATA_DETECTED                         EQU     080000022H
STATUS_REDIRECTOR_HAS_OPEN_HANDLES              EQU     080000023H
STATUS_SERVER_HAS_OPEN_HANDLES                  EQU     080000024H
STATUS_ALREADY_DISCONNECTED                     EQU     080000025H
STATUS_LONGJUMP                                 EQU     080000026H
STATUS_CLEANER_CARTRIDGE_INSTALLED              EQU     080000027H
STATUS_PLUGPLAY_QUERY_VETOED                    EQU     080000028H
STATUS_UNWIND_CONSOLIDATE                       EQU     080000029H
STATUS_REGISTRY_HIVE_RECOVERED                  EQU     08000002AH
STATUS_DLL_MIGHT_BE_INSECURE                    EQU     08000002BH
STATUS_DLL_MIGHT_BE_INCOMPATIBLE                EQU     08000002CH
STATUS_CLUSTER_NODE_ALREADY_UP                  EQU     080130001H
STATUS_CLUSTER_NODE_ALREADY_DOWN                EQU     080130002H
STATUS_CLUSTER_NETWORK_ALREADY_ONLINE           EQU     080130003H
STATUS_CLUSTER_NETWORK_ALREADY_OFFLINE          EQU     080130004H
STATUS_CLUSTER_NODE_ALREADY_MEMBER              EQU     080130005H
STATUS_UNSUCCESSFUL                             EQU     0C0000001H
STATUS_NOT_IMPLEMENTED                          EQU     0C0000002H
STATUS_INVALID_INFO_CLASS                       EQU     0C0000003H
STATUS_INFO_LENGTH_MISMATCH                     EQU     0C0000004H
STATUS_PAGEFILE_QUOTA                           EQU     0C0000007H
STATUS_BAD_INITIAL_STACK                        EQU     0C0000009H
STATUS_BAD_INITIAL_PC                           EQU     0C000000AH
STATUS_INVALID_CID                              EQU     0C000000BH
STATUS_TIMER_NOT_CANCELED                       EQU     0C000000CH
STATUS_INVALID_PARAMETER                        EQU     0C000000DH
STATUS_NO_SUCH_DEVICE                           EQU     0C000000EH
STATUS_NO_SUCH_FILE                             EQU     0C000000FH
STATUS_INVALID_DEVICE_REQUEST                   EQU     0C0000010H
STATUS_END_OF_FILE                              EQU     0C0000011H
STATUS_WRONG_VOLUME                             EQU     0C0000012H
STATUS_NO_MEDIA_IN_DEVICE                       EQU     0C0000013H
STATUS_UNRECOGNIZED_MEDIA                       EQU     0C0000014H
STATUS_NONEXISTENT_SECTOR                       EQU     0C0000015H
STATUS_MORE_PROCESSING_REQUIRED                 EQU     0C0000016H
STATUS_CONFLICTING_ADDRESSES                    EQU     0C0000018H
STATUS_NOT_MAPPED_VIEW                          EQU     0C0000019H
STATUS_UNABLE_TO_FREE_VM                        EQU     0C000001AH
STATUS_UNABLE_TO_DELETE_SECTION                 EQU     0C000001BH
STATUS_INVALID_SYSTEM_SERVICE                   EQU     0C000001CH
STATUS_INVALID_LOCK_SEQUENCE                    EQU     0C000001EH
STATUS_INVALID_VIEW_SIZE                        EQU     0C000001FH
STATUS_INVALID_FILE_FOR_SECTION                 EQU     0C0000020H
STATUS_ALREADY_COMMITTED                        EQU     0C0000021H
STATUS_ACCESS_DENIED                            EQU     0C0000022H
STATUS_BUFFER_TOO_SMALL                         EQU     0C0000023H
STATUS_OBJECT_TYPE_MISMATCH                     EQU     0C0000024H
STATUS_UNWIND                                   EQU     0C0000027H
STATUS_BAD_STACK                                EQU     0C0000028H
STATUS_INVALID_UNWIND_TARGET                    EQU     0C0000029H
STATUS_NOT_LOCKED                               EQU     0C000002AH
STATUS_PARITY_ERROR                             EQU     0C000002BH
STATUS_UNABLE_TO_DECOMMIT_VM                    EQU     0C000002CH
STATUS_NOT_COMMITTED                            EQU     0C000002DH
STATUS_INVALID_PORT_ATTRIBUTES                  EQU     0C000002EH
STATUS_PORT_MESSAGE_TOO_LONG                    EQU     0C000002FH
STATUS_INVALID_PARAMETER_MIX                    EQU     0C0000030H
STATUS_INVALID_QUOTA_LOWER                      EQU     0C0000031H
STATUS_DISK_CORRUPT_ERROR                       EQU     0C0000032H
STATUS_OBJECT_NAME_INVALID                      EQU     0C0000033H
STATUS_OBJECT_NAME_NOT_FOUND                    EQU     0C0000034H
STATUS_OBJECT_NAME_COLLISION                    EQU     0C0000035H
STATUS_PORT_DISCONNECTED                        EQU     0C0000037H
STATUS_DEVICE_ALREADY_ATTACHED                  EQU     0C0000038H
STATUS_OBJECT_PATH_INVALID                      EQU     0C0000039H
STATUS_OBJECT_PATH_NOT_FOUND                    EQU     0C000003AH
STATUS_OBJECT_PATH_SYNTAX_BAD                   EQU     0C000003BH
STATUS_DATA_OVERRUN                             EQU     0C000003CH
STATUS_DATA_LATE_ERROR                          EQU     0C000003DH
STATUS_DATA_ERROR                               EQU     0C000003EH
STATUS_CRC_ERROR                                EQU     0C000003FH
STATUS_SECTION_TOO_BIG                          EQU     0C0000040H
STATUS_PORT_CONNECTION_REFUSED                  EQU     0C0000041H
STATUS_INVALID_PORT_HANDLE                      EQU     0C0000042H
STATUS_SHARING_VIOLATION                        EQU     0C0000043H
STATUS_QUOTA_EXCEEDED                           EQU     0C0000044H
STATUS_INVALID_PAGE_PROTECTION                  EQU     0C0000045H
STATUS_MUTANT_NOT_OWNED                         EQU     0C0000046H
STATUS_SEMAPHORE_LIMIT_EXCEEDED                 EQU     0C0000047H
STATUS_PORT_ALREADY_SET                         EQU     0C0000048H
STATUS_SECTION_NOT_IMAGE                        EQU     0C0000049H
STATUS_SUSPEND_COUNT_EXCEEDED                   EQU     0C000004AH
STATUS_THREAD_IS_TERMINATING                    EQU     0C000004BH
STATUS_BAD_WORKING_SET_LIMIT                    EQU     0C000004CH
STATUS_INCOMPATIBLE_FILE_MAP                    EQU     0C000004DH
STATUS_SECTION_PROTECTION                       EQU     0C000004EH
STATUS_EAS_NOT_SUPPORTED                        EQU     0C000004FH
STATUS_EA_TOO_LARGE                             EQU     0C0000050H
STATUS_NONEXISTENT_EA_ENTRY                     EQU     0C0000051H
STATUS_NO_EAS_ON_FILE                           EQU     0C0000052H
STATUS_EA_CORRUPT_ERROR                         EQU     0C0000053H
STATUS_FILE_LOCK_CONFLICT                       EQU     0C0000054H
STATUS_LOCK_NOT_GRANTED                         EQU     0C0000055H
STATUS_DELETE_PENDING                           EQU     0C0000056H
STATUS_CTL_FILE_NOT_SUPPORTED                   EQU     0C0000057H
STATUS_UNKNOWN_REVISION                         EQU     0C0000058H
STATUS_REVISION_MISMATCH                        EQU     0C0000059H
STATUS_INVALID_OWNER                            EQU     0C000005AH
STATUS_INVALID_PRIMARY_GROUP                    EQU     0C000005BH
STATUS_NO_IMPERSONATION_TOKEN                   EQU     0C000005CH
STATUS_CANT_DISABLE_MANDATORY                   EQU     0C000005DH
STATUS_NO_LOGON_SERVERS                         EQU     0C000005EH
STATUS_NO_SUCH_LOGON_SESSION                    EQU     0C000005FH
STATUS_NO_SUCH_PRIVILEGE                        EQU     0C0000060H
STATUS_PRIVILEGE_NOT_HELD                       EQU     0C0000061H
STATUS_INVALID_ACCOUNT_NAME                     EQU     0C0000062H
STATUS_USER_EXISTS                              EQU     0C0000063H
STATUS_NO_SUCH_USER                             EQU     0C0000064H
STATUS_GROUP_EXISTS                             EQU     0C0000065H
STATUS_NO_SUCH_GROUP                            EQU     0C0000066H
STATUS_MEMBER_IN_GROUP                          EQU     0C0000067H
STATUS_MEMBER_NOT_IN_GROUP                      EQU     0C0000068H
STATUS_LAST_ADMIN                               EQU     0C0000069H
STATUS_WRONG_PASSWORD                           EQU     0C000006AH
STATUS_ILL_FORMED_PASSWORD                      EQU     0C000006BH
STATUS_PASSWORD_RESTRICTION                     EQU     0C000006CH
STATUS_LOGON_FAILURE                            EQU     0C000006DH
STATUS_ACCOUNT_RESTRICTION                      EQU     0C000006EH
STATUS_INVALID_LOGON_HOURS                      EQU     0C000006FH
STATUS_INVALID_WORKSTATION                      EQU     0C0000070H
STATUS_PASSWORD_EXPIRED                         EQU     0C0000071H
STATUS_ACCOUNT_DISABLED                         EQU     0C0000072H
STATUS_NONE_MAPPED                              EQU     0C0000073H
STATUS_TOO_MANY_LUIDS_REQUESTED                 EQU     0C0000074H
STATUS_LUIDS_EXHAUSTED                          EQU     0C0000075H
STATUS_INVALID_SUB_AUTHORITY                    EQU     0C0000076H
STATUS_INVALID_ACL                              EQU     0C0000077H
STATUS_INVALID_SID                              EQU     0C0000078H
STATUS_INVALID_SECURITY_DESCR                   EQU     0C0000079H
STATUS_PROCEDURE_NOT_FOUND                      EQU     0C000007AH
STATUS_INVALID_IMAGE_FORMAT                     EQU     0C000007BH
STATUS_NO_TOKEN                                 EQU     0C000007CH
STATUS_BAD_INHERITANCE_ACL                      EQU     0C000007DH
STATUS_RANGE_NOT_LOCKED                         EQU     0C000007EH
STATUS_DISK_FULL                                EQU     0C000007FH
STATUS_SERVER_DISABLED                          EQU     0C0000080H
STATUS_SERVER_NOT_DISABLED                      EQU     0C0000081H
STATUS_TOO_MANY_GUIDS_REQUESTED                 EQU     0C0000082H
STATUS_GUIDS_EXHAUSTED                          EQU     0C0000083H
STATUS_INVALID_ID_AUTHORITY                     EQU     0C0000084H
STATUS_AGENTS_EXHAUSTED                         EQU     0C0000085H
STATUS_INVALID_VOLUME_LABEL                     EQU     0C0000086H
STATUS_SECTION_NOT_EXTENDED                     EQU     0C0000087H
STATUS_NOT_MAPPED_DATA                          EQU     0C0000088H
STATUS_RESOURCE_DATA_NOT_FOUND                  EQU     0C0000089H
STATUS_RESOURCE_TYPE_NOT_FOUND                  EQU     0C000008AH
STATUS_RESOURCE_NAME_NOT_FOUND                  EQU     0C000008BH
STATUS_TOO_MANY_PAGING_FILES                    EQU     0C0000097H
STATUS_FILE_INVALID                             EQU     0C0000098H
STATUS_ALLOTTED_SPACE_EXCEEDED                  EQU     0C0000099H
STATUS_INSUFFICIENT_RESOURCES                   EQU     0C000009AH
STATUS_DFS_EXIT_PATH_FOUND                      EQU     0C000009BH
STATUS_DEVICE_DATA_ERROR                        EQU     0C000009CH
STATUS_DEVICE_NOT_CONNECTED                     EQU     0C000009DH
STATUS_DEVICE_POWER_FAILURE                     EQU     0C000009EH
STATUS_FREE_VM_NOT_AT_BASE                      EQU     0C000009FH
STATUS_MEMORY_NOT_ALLOCATED                     EQU     0C00000A0H
STATUS_WORKING_SET_QUOTA                        EQU     0C00000A1H
STATUS_MEDIA_WRITE_PROTECTED                    EQU     0C00000A2H
STATUS_DEVICE_NOT_READY                         EQU     0C00000A3H
STATUS_INVALID_GROUP_ATTRIBUTES                 EQU     0C00000A4H
STATUS_BAD_IMPERSONATION_LEVEL                  EQU     0C00000A5H
STATUS_CANT_OPEN_ANONYMOUS                      EQU     0C00000A6H
STATUS_BAD_VALIDATION_CLASS                     EQU     0C00000A7H
STATUS_BAD_TOKEN_TYPE                           EQU     0C00000A8H
STATUS_BAD_MASTER_BOOT_RECORD                   EQU     0C00000A9H
STATUS_INSTRUCTION_MISALIGNMENT                 EQU     0C00000AAH
STATUS_INSTANCE_NOT_AVAILABLE                   EQU     0C00000ABH
STATUS_PIPE_NOT_AVAILABLE                       EQU     0C00000ACH
STATUS_INVALID_PIPE_STATE                       EQU     0C00000ADH
STATUS_PIPE_BUSY                                EQU     0C00000AEH
STATUS_ILLEGAL_FUNCTION                         EQU     0C00000AFH
STATUS_PIPE_DISCONNECTED                        EQU     0C00000B0H
STATUS_PIPE_CLOSING                             EQU     0C00000B1H
STATUS_PIPE_CONNECTED                           EQU     0C00000B2H
STATUS_PIPE_LISTENING                           EQU     0C00000B3H
STATUS_INVALID_READ_MODE                        EQU     0C00000B4H
STATUS_IO_TIMEOUT                               EQU     0C00000B5H
STATUS_FILE_FORCED_CLOSED                       EQU     0C00000B6H
STATUS_PROFILING_NOT_STARTED                    EQU     0C00000B7H
STATUS_PROFILING_NOT_STOPPED                    EQU     0C00000B8H
STATUS_COULD_NOT_INTERPRET                      EQU     0C00000B9H
STATUS_FILE_IS_A_DIRECTORY                      EQU     0C00000BAH
STATUS_NOT_SUPPORTED                            EQU     0C00000BBH
STATUS_REMOTE_NOT_LISTENING                     EQU     0C00000BCH
STATUS_DUPLICATE_NAME                           EQU     0C00000BDH
STATUS_BAD_NETWORK_PATH                         EQU     0C00000BEH
STATUS_NETWORK_BUSY                             EQU     0C00000BFH
STATUS_DEVICE_DOES_NOT_EXIST                    EQU     0C00000C0H
STATUS_TOO_MANY_COMMANDS                        EQU     0C00000C1H
STATUS_ADAPTER_HARDWARE_ERROR                   EQU     0C00000C2H
STATUS_INVALID_NETWORK_RESPONSE                 EQU     0C00000C3H
STATUS_UNEXPECTED_NETWORK_ERROR                 EQU     0C00000C4H
STATUS_BAD_REMOTE_ADAPTER                       EQU     0C00000C5H
STATUS_PRINT_QUEUE_FULL                         EQU     0C00000C6H
STATUS_NO_SPOOL_SPACE                           EQU     0C00000C7H
STATUS_PRINT_CANCELLED                          EQU     0C00000C8H
STATUS_NETWORK_NAME_DELETED                     EQU     0C00000C9H
STATUS_NETWORK_ACCESS_DENIED                    EQU     0C00000CAH
STATUS_BAD_DEVICE_TYPE                          EQU     0C00000CBH
STATUS_BAD_NETWORK_NAME                         EQU     0C00000CCH
STATUS_TOO_MANY_NAMES                           EQU     0C00000CDH
STATUS_TOO_MANY_SESSIONS                        EQU     0C00000CEH
STATUS_SHARING_PAUSED                           EQU     0C00000CFH
STATUS_REQUEST_NOT_ACCEPTED                     EQU     0C00000D0H
STATUS_REDIRECTOR_PAUSED                        EQU     0C00000D1H
STATUS_NET_WRITE_FAULT                          EQU     0C00000D2H
STATUS_PROFILING_AT_LIMIT                       EQU     0C00000D3H
STATUS_NOT_SAME_DEVICE                          EQU     0C00000D4H
STATUS_FILE_RENAMED                             EQU     0C00000D5H
STATUS_VIRTUAL_CIRCUIT_CLOSED                   EQU     0C00000D6H
STATUS_NO_SECURITY_ON_OBJECT                    EQU     0C00000D7H
STATUS_CANT_WAIT                                EQU     0C00000D8H
STATUS_PIPE_EMPTY                               EQU     0C00000D9H
STATUS_CANT_ACCESS_DOMAIN_INFO                  EQU     0C00000DAH
STATUS_CANT_TERMINATE_SELF                      EQU     0C00000DBH
STATUS_INVALID_SERVER_STATE                     EQU     0C00000DCH
STATUS_INVALID_DOMAIN_STATE                     EQU     0C00000DDH
STATUS_INVALID_DOMAIN_ROLE                      EQU     0C00000DEH
STATUS_NO_SUCH_DOMAIN                           EQU     0C00000DFH
STATUS_DOMAIN_EXISTS                            EQU     0C00000E0H
STATUS_DOMAIN_LIMIT_EXCEEDED                    EQU     0C00000E1H
STATUS_OPLOCK_NOT_GRANTED                       EQU     0C00000E2H
STATUS_INVALID_OPLOCK_PROTOCOL                  EQU     0C00000E3H
STATUS_INTERNAL_DB_CORRUPTION                   EQU     0C00000E4H
STATUS_INTERNAL_ERROR                           EQU     0C00000E5H
STATUS_GENERIC_NOT_MAPPED                       EQU     0C00000E6H
STATUS_BAD_DESCRIPTOR_FORMAT                    EQU     0C00000E7H
STATUS_INVALID_USER_BUFFER                      EQU     0C00000E8H
STATUS_UNEXPECTED_IO_ERROR                      EQU     0C00000E9H
STATUS_UNEXPECTED_MM_CREATE_ERR                 EQU     0C00000EAH
STATUS_UNEXPECTED_MM_MAP_ERROR                  EQU     0C00000EBH
STATUS_UNEXPECTED_MM_EXTEND_ERR                 EQU     0C00000ECH
STATUS_NOT_LOGON_PROCESS                        EQU     0C00000EDH
STATUS_LOGON_SESSION_EXISTS                     EQU     0C00000EEH
STATUS_INVALID_PARAMETER_1                      EQU     0C00000EFH
STATUS_INVALID_PARAMETER_2                      EQU     0C00000F0H
STATUS_INVALID_PARAMETER_3                      EQU     0C00000F1H
STATUS_INVALID_PARAMETER_4                      EQU     0C00000F2H
STATUS_INVALID_PARAMETER_5                      EQU     0C00000F3H
STATUS_INVALID_PARAMETER_6                      EQU     0C00000F4H
STATUS_INVALID_PARAMETER_7                      EQU     0C00000F5H
STATUS_INVALID_PARAMETER_8                      EQU     0C00000F6H
STATUS_INVALID_PARAMETER_9                      EQU     0C00000F7H
STATUS_INVALID_PARAMETER_10                     EQU     0C00000F8H
STATUS_INVALID_PARAMETER_11                     EQU     0C00000F9H
STATUS_INVALID_PARAMETER_12                     EQU     0C00000FAH
STATUS_REDIRECTOR_NOT_STARTED                   EQU     0C00000FBH
STATUS_REDIRECTOR_STARTED                       EQU     0C00000FCH
STATUS_NO_SUCH_PACKAGE                          EQU     0C00000FEH
STATUS_BAD_FUNCTION_TABLE                       EQU     0C00000FFH
STATUS_VARIABLE_NOT_FOUND                       EQU     0C0000100H
STATUS_DIRECTORY_NOT_EMPTY                      EQU     0C0000101H
STATUS_FILE_CORRUPT_ERROR                       EQU     0C0000102H
STATUS_NOT_A_DIRECTORY                          EQU     0C0000103H
STATUS_BAD_LOGON_SESSION_STATE                  EQU     0C0000104H
STATUS_LOGON_SESSION_COLLISION                  EQU     0C0000105H
STATUS_NAME_TOO_LONG                            EQU     0C0000106H
STATUS_FILES_OPEN                               EQU     0C0000107H
STATUS_CONNECTION_IN_USE                        EQU     0C0000108H
STATUS_MESSAGE_NOT_FOUND                        EQU     0C0000109H
STATUS_PROCESS_IS_TERMINATING                   EQU     0C000010AH
STATUS_INVALID_LOGON_TYPE                       EQU     0C000010BH
STATUS_NO_GUID_TRANSLATION                      EQU     0C000010CH
STATUS_CANNOT_IMPERSONATE                       EQU     0C000010DH
STATUS_IMAGE_ALREADY_LOADED                     EQU     0C000010EH
STATUS_ABIOS_NOT_PRESENT                        EQU     0C000010FH
STATUS_ABIOS_LID_NOT_EXIST                      EQU     0C0000110H
STATUS_ABIOS_LID_ALREADY_OWNED                  EQU     0C0000111H
STATUS_ABIOS_NOT_LID_OWNER                      EQU     0C0000112H
STATUS_ABIOS_INVALID_COMMAND                    EQU     0C0000113H
STATUS_ABIOS_INVALID_LID                        EQU     0C0000114H
STATUS_ABIOS_SELECTOR_NOT_AVAILABLE             EQU     0C0000115H
STATUS_ABIOS_INVALID_SELECTOR                   EQU     0C0000116H
STATUS_NO_LDT                                   EQU     0C0000117H
STATUS_INVALID_LDT_SIZE                         EQU     0C0000118H
STATUS_INVALID_LDT_OFFSET                       EQU     0C0000119H
STATUS_INVALID_LDT_DESCRIPTOR                   EQU     0C000011AH
STATUS_INVALID_IMAGE_NE_FORMAT                  EQU     0C000011BH
STATUS_RXACT_INVALID_STATE                      EQU     0C000011CH
STATUS_RXACT_COMMIT_FAILURE                     EQU     0C000011DH
STATUS_MAPPED_FILE_SIZE_ZERO                    EQU     0C000011EH
STATUS_TOO_MANY_OPENED_FILES                    EQU     0C000011FH
STATUS_CANCELLED                                EQU     0C0000120H
STATUS_CANNOT_DELETE                            EQU     0C0000121H
STATUS_INVALID_COMPUTER_NAME                    EQU     0C0000122H
STATUS_FILE_DELETED                             EQU     0C0000123H
STATUS_SPECIAL_ACCOUNT                          EQU     0C0000124H
STATUS_SPECIAL_GROUP                            EQU     0C0000125H
STATUS_SPECIAL_USER                             EQU     0C0000126H
STATUS_MEMBERS_PRIMARY_GROUP                    EQU     0C0000127H
STATUS_FILE_CLOSED                              EQU     0C0000128H
STATUS_TOO_MANY_THREADS                         EQU     0C0000129H
STATUS_THREAD_NOT_IN_PROCESS                    EQU     0C000012AH
STATUS_TOKEN_ALREADY_IN_USE                     EQU     0C000012BH
STATUS_PAGEFILE_QUOTA_EXCEEDED                  EQU     0C000012CH
STATUS_COMMITMENT_LIMIT                         EQU     0C000012DH
STATUS_INVALID_IMAGE_LE_FORMAT                  EQU     0C000012EH
STATUS_INVALID_IMAGE_NOT_MZ                     EQU     0C000012FH
STATUS_INVALID_IMAGE_PROTECT                    EQU     0C0000130H
STATUS_INVALID_IMAGE_WIN_16                     EQU     0C0000131H
STATUS_LOGON_SERVER_CONFLICT                    EQU     0C0000132H
STATUS_TIME_DIFFERENCE_AT_DC                    EQU     0C0000133H
STATUS_SYNCHRONIZATION_REQUIRED                 EQU     0C0000134H
STATUS_DLL_NOT_FOUND                            EQU     0C0000135H
STATUS_OPEN_FAILED                              EQU     0C0000136H
STATUS_IO_PRIVILEGE_FAILED                      EQU     0C0000137H
STATUS_ORDINAL_NOT_FOUND                        EQU     0C0000138H
STATUS_ENTRYPOINT_NOT_FOUND                     EQU     0C0000139H
STATUS_LOCAL_DISCONNECT                         EQU     0C000013BH
STATUS_REMOTE_DISCONNECT                        EQU     0C000013CH
STATUS_REMOTE_RESOURCES                         EQU     0C000013DH
STATUS_LINK_FAILED                              EQU     0C000013EH
STATUS_LINK_TIMEOUT                             EQU     0C000013FH
STATUS_INVALID_CONNECTION                       EQU     0C0000140H
STATUS_INVALID_ADDRESS                          EQU     0C0000141H
STATUS_DLL_INIT_FAILED                          EQU     0C0000142H
STATUS_MISSING_SYSTEMFILE                       EQU     0C0000143H
STATUS_UNHANDLED_EXCEPTION                      EQU     0C0000144H
STATUS_APP_INIT_FAILURE                         EQU     0C0000145H
STATUS_PAGEFILE_CREATE_FAILED                   EQU     0C0000146H
STATUS_NO_PAGEFILE                              EQU     0C0000147H
STATUS_INVALID_LEVEL                            EQU     0C0000148H
STATUS_WRONG_PASSWORD_CORE                      EQU     0C0000149H
STATUS_ILLEGAL_FLOAT_CONTEXT                    EQU     0C000014AH
STATUS_PIPE_BROKEN                              EQU     0C000014BH
STATUS_REGISTRY_CORRUPT                         EQU     0C000014CH
STATUS_REGISTRY_IO_FAILED                       EQU     0C000014DH
STATUS_NO_EVENT_PAIR                            EQU     0C000014EH
STATUS_UNRECOGNIZED_VOLUME                      EQU     0C000014FH
STATUS_SERIAL_NO_DEVICE_INITED                  EQU     0C0000150H
STATUS_NO_SUCH_ALIAS                            EQU     0C0000151H
STATUS_MEMBER_NOT_IN_ALIAS                      EQU     0C0000152H
STATUS_MEMBER_IN_ALIAS                          EQU     0C0000153H
STATUS_ALIAS_EXISTS                             EQU     0C0000154H
STATUS_LOGON_NOT_GRANTED                        EQU     0C0000155H
STATUS_TOO_MANY_SECRETS                         EQU     0C0000156H
STATUS_SECRET_TOO_LONG                          EQU     0C0000157H
STATUS_INTERNAL_DB_ERROR                        EQU     0C0000158H
STATUS_FULLSCREEN_MODE                          EQU     0C0000159H
STATUS_TOO_MANY_CONTEXT_IDS                     EQU     0C000015AH
STATUS_LOGON_TYPE_NOT_GRANTED                   EQU     0C000015BH
STATUS_NOT_REGISTRY_FILE                        EQU     0C000015CH
STATUS_NT_CROSS_ENCRYPTION_REQUIRED             EQU     0C000015DH
STATUS_DOMAIN_CTRLR_CONFIG_ERROR                EQU     0C000015EH
STATUS_FT_MISSING_MEMBER                        EQU     0C000015FH
STATUS_ILL_FORMED_SERVICE_ENTRY                 EQU     0C0000160H
STATUS_ILLEGAL_CHARACTER                        EQU     0C0000161H
STATUS_UNMAPPABLE_CHARACTER                     EQU     0C0000162H
STATUS_UNDEFINED_CHARACTER                      EQU     0C0000163H
STATUS_FLOPPY_VOLUME                            EQU     0C0000164H
STATUS_FLOPPY_ID_MARK_NOT_FOUND                 EQU     0C0000165H
STATUS_FLOPPY_WRONG_CYLINDER                    EQU     0C0000166H
STATUS_FLOPPY_UNKNOWN_ERROR                     EQU     0C0000167H
STATUS_FLOPPY_BAD_REGISTERS                     EQU     0C0000168H
STATUS_DISK_RECALIBRATE_FAILED                  EQU     0C0000169H
STATUS_DISK_OPERATION_FAILED                    EQU     0C000016AH
STATUS_DISK_RESET_FAILED                        EQU     0C000016BH
STATUS_SHARED_IRQ_BUSY                          EQU     0C000016CH
STATUS_FT_ORPHANING                             EQU     0C000016DH
STATUS_BIOS_FAILED_TO_CONNECT_INTERRUPT         EQU     0C000016EH
STATUS_PARTITION_FAILURE                        EQU     0C0000172H
STATUS_INVALID_BLOCK_LENGTH                     EQU     0C0000173H
STATUS_DEVICE_NOT_PARTITIONED                   EQU     0C0000174H
STATUS_UNABLE_TO_LOCK_MEDIA                     EQU     0C0000175H
STATUS_UNABLE_TO_UNLOAD_MEDIA                   EQU     0C0000176H
STATUS_EOM_OVERFLOW                             EQU     0C0000177H
STATUS_NO_MEDIA                                 EQU     0C0000178H
STATUS_NO_SUCH_MEMBER                           EQU     0C000017AH
STATUS_INVALID_MEMBER                           EQU     0C000017BH
STATUS_KEY_DELETED                              EQU     0C000017CH
STATUS_NO_LOG_SPACE                             EQU     0C000017DH
STATUS_TOO_MANY_SIDS                            EQU     0C000017EH
STATUS_LM_CROSS_ENCRYPTION_REQUIRED             EQU     0C000017FH
STATUS_KEY_HAS_CHILDREN                         EQU     0C0000180H
STATUS_CHILD_MUST_BE_VOLATILE                   EQU     0C0000181H
STATUS_DEVICE_CONFIGURATION_ERROR               EQU     0C0000182H
STATUS_DRIVER_INTERNAL_ERROR                    EQU     0C0000183H
STATUS_INVALID_DEVICE_STATE                     EQU     0C0000184H
STATUS_IO_DEVICE_ERROR                          EQU     0C0000185H
STATUS_DEVICE_PROTOCOL_ERROR                    EQU     0C0000186H
STATUS_BACKUP_CONTROLLER                        EQU     0C0000187H
STATUS_LOG_FILE_FULL                            EQU     0C0000188H
STATUS_TOO_LATE                                 EQU     0C0000189H
STATUS_NO_TRUST_LSA_SECRET                      EQU     0C000018AH
STATUS_NO_TRUST_SAM_ACCOUNT                     EQU     0C000018BH
STATUS_TRUSTED_DOMAIN_FAILURE                   EQU     0C000018CH
STATUS_TRUSTED_RELATIONSHIP_FAILURE             EQU     0C000018DH
STATUS_EVENTLOG_FILE_CORRUPT                    EQU     0C000018EH
STATUS_EVENTLOG_CANT_START                      EQU     0C000018FH
STATUS_TRUST_FAILURE                            EQU     0C0000190H
STATUS_MUTANT_LIMIT_EXCEEDED                    EQU     0C0000191H
STATUS_NETLOGON_NOT_STARTED                     EQU     0C0000192H
STATUS_ACCOUNT_EXPIRED                          EQU     0C0000193H
STATUS_POSSIBLE_DEADLOCK                        EQU     0C0000194H
STATUS_NETWORK_CREDENTIAL_CONFLICT              EQU     0C0000195H
STATUS_REMOTE_SESSION_LIMIT                     EQU     0C0000196H
STATUS_EVENTLOG_FILE_CHANGED                    EQU     0C0000197H
STATUS_NOLOGON_INTERDOMAIN_TRUST_ACCOUNT        EQU     0C0000198H
STATUS_NOLOGON_WORKSTATION_TRUST_ACCOUNT        EQU     0C0000199H
STATUS_NOLOGON_SERVER_TRUST_ACCOUNT             EQU     0C000019AH
STATUS_DOMAIN_TRUST_INCONSISTENT                EQU     0C000019BH
STATUS_FS_DRIVER_REQUIRED                       EQU     0C000019CH
STATUS_NO_USER_SESSION_KEY                      EQU     0C0000202H
STATUS_USER_SESSION_DELETED                     EQU     0C0000203H
STATUS_RESOURCE_LANG_NOT_FOUND                  EQU     0C0000204H
STATUS_INSUFF_SERVER_RESOURCES                  EQU     0C0000205H
STATUS_INVALID_BUFFER_SIZE                      EQU     0C0000206H
STATUS_INVALID_ADDRESS_COMPONENT                EQU     0C0000207H
STATUS_INVALID_ADDRESS_WILDCARD                 EQU     0C0000208H
STATUS_TOO_MANY_ADDRESSES                       EQU     0C0000209H
STATUS_ADDRESS_ALREADY_EXISTS                   EQU     0C000020AH
STATUS_ADDRESS_CLOSED                           EQU     0C000020BH
STATUS_CONNECTION_DISCONNECTED                  EQU     0C000020CH
STATUS_CONNECTION_RESET                         EQU     0C000020DH
STATUS_TOO_MANY_NODES                           EQU     0C000020EH
STATUS_TRANSACTION_ABORTED                      EQU     0C000020FH
STATUS_TRANSACTION_TIMED_OUT                    EQU     0C0000210H
STATUS_TRANSACTION_NO_RELEASE                   EQU     0C0000211H
STATUS_TRANSACTION_NO_MATCH                     EQU     0C0000212H
STATUS_TRANSACTION_RESPONDED                    EQU     0C0000213H
STATUS_TRANSACTION_INVALID_ID                   EQU     0C0000214H
STATUS_TRANSACTION_INVALID_TYPE                 EQU     0C0000215H
STATUS_NOT_SERVER_SESSION                       EQU     0C0000216H
STATUS_NOT_CLIENT_SESSION                       EQU     0C0000217H
STATUS_CANNOT_LOAD_REGISTRY_FILE                EQU     0C0000218H
STATUS_DEBUG_ATTACH_FAILED                      EQU     0C0000219H
STATUS_SYSTEM_PROCESS_TERMINATED                EQU     0C000021AH
STATUS_DATA_NOT_ACCEPTED                        EQU     0C000021BH
STATUS_NO_BROWSER_SERVERS_FOUND                 EQU     0C000021CH
STATUS_VDM_HARD_ERROR                           EQU     0C000021DH
STATUS_DRIVER_CANCEL_TIMEOUT                    EQU     0C000021EH
STATUS_REPLY_MESSAGE_MISMATCH                   EQU     0C000021FH
STATUS_MAPPED_ALIGNMENT                         EQU     0C0000220H
STATUS_IMAGE_CHECKSUM_MISMATCH                  EQU     0C0000221H
STATUS_LOST_WRITEBEHIND_DATA                    EQU     0C0000222H
STATUS_CLIENT_SERVER_PARAMETERS_INVALID         EQU     0C0000223H
STATUS_PASSWORD_MUST_CHANGE                     EQU     0C0000224H
STATUS_NOT_FOUND                                EQU     0C0000225H
STATUS_NOT_TINY_STREAM                          EQU     0C0000226H
STATUS_RECOVERY_FAILURE                         EQU     0C0000227H
STATUS_STACK_OVERFLOW_READ                      EQU     0C0000228H
STATUS_FAIL_CHECK                               EQU     0C0000229H
STATUS_DUPLICATE_OBJECTID                       EQU     0C000022AH
STATUS_OBJECTID_EXISTS                          EQU     0C000022BH
STATUS_CONVERT_TO_LARGE                         EQU     0C000022CH
STATUS_RETRY                                    EQU     0C000022DH
STATUS_FOUND_OUT_OF_SCOPE                       EQU     0C000022EH
STATUS_ALLOCATE_BUCKET                          EQU     0C000022FH
STATUS_PROPSET_NOT_FOUND                        EQU     0C0000230H
STATUS_MARSHALL_OVERFLOW                        EQU     0C0000231H
STATUS_INVALID_VARIANT                          EQU     0C0000232H
STATUS_DOMAIN_CONTROLLER_NOT_FOUND              EQU     0C0000233H
STATUS_ACCOUNT_LOCKED_OUT                       EQU     0C0000234H
STATUS_HANDLE_NOT_CLOSABLE                      EQU     0C0000235H
STATUS_CONNECTION_REFUSED                       EQU     0C0000236H
STATUS_GRACEFUL_DISCONNECT                      EQU     0C0000237H
STATUS_ADDRESS_ALREADY_ASSOCIATED               EQU     0C0000238H
STATUS_ADDRESS_NOT_ASSOCIATED                   EQU     0C0000239H
STATUS_CONNECTION_INVALID                       EQU     0C000023AH
STATUS_CONNECTION_ACTIVE                        EQU     0C000023BH
STATUS_NETWORK_UNREACHABLE                      EQU     0C000023CH
STATUS_HOST_UNREACHABLE                         EQU     0C000023DH
STATUS_PROTOCOL_UNREACHABLE                     EQU     0C000023EH
STATUS_PORT_UNREACHABLE                         EQU     0C000023FH
STATUS_REQUEST_ABORTED                          EQU     0C0000240H
STATUS_CONNECTION_ABORTED                       EQU     0C0000241H
STATUS_BAD_COMPRESSION_BUFFER                   EQU     0C0000242H
STATUS_USER_MAPPED_FILE                         EQU     0C0000243H
STATUS_AUDIT_FAILED                             EQU     0C0000244H
STATUS_TIMER_RESOLUTION_NOT_SET                 EQU     0C0000245H
STATUS_CONNECTION_COUNT_LIMIT                   EQU     0C0000246H
STATUS_LOGIN_TIME_RESTRICTION                   EQU     0C0000247H
STATUS_LOGIN_WKSTA_RESTRICTION                  EQU     0C0000248H
STATUS_IMAGE_MP_UP_MISMATCH                     EQU     0C0000249H
STATUS_INSUFFICIENT_LOGON_INFO                  EQU     0C0000250H
STATUS_BAD_DLL_ENTRYPOINT                       EQU     0C0000251H
STATUS_BAD_SERVICE_ENTRYPOINT                   EQU     0C0000252H
STATUS_LPC_REPLY_LOST                           EQU     0C0000253H
STATUS_IP_ADDRESS_CONFLICT1                     EQU     0C0000254H
STATUS_IP_ADDRESS_CONFLICT2                     EQU     0C0000255H
STATUS_REGISTRY_QUOTA_LIMIT                     EQU     0C0000256H
STATUS_PATH_NOT_COVERED                         EQU     0C0000257H
STATUS_NO_CALLBACK_ACTIVE                       EQU     0C0000258H
STATUS_LICENSE_QUOTA_EXCEEDED                   EQU     0C0000259H
STATUS_PWD_TOO_SHORT                            EQU     0C000025AH
STATUS_PWD_TOO_RECENT                           EQU     0C000025BH
STATUS_PWD_HISTORY_CONFLICT                     EQU     0C000025CH
STATUS_PLUGPLAY_NO_DEVICE                       EQU     0C000025EH
STATUS_UNSUPPORTED_COMPRESSION                  EQU     0C000025FH
STATUS_INVALID_HW_PROFILE                       EQU     0C0000260H
STATUS_INVALID_PLUGPLAY_DEVICE_PATH             EQU     0C0000261H
STATUS_DRIVER_ORDINAL_NOT_FOUND                 EQU     0C0000262H
STATUS_DRIVER_ENTRYPOINT_NOT_FOUND              EQU     0C0000263H
STATUS_RESOURCE_NOT_OWNED                       EQU     0C0000264H
STATUS_TOO_MANY_LINKS                           EQU     0C0000265H
STATUS_QUOTA_LIST_INCONSISTENT                  EQU     0C0000266H
STATUS_FILE_IS_OFFLINE                          EQU     0C0000267H
STATUS_EVALUATION_EXPIRATION                    EQU     0C0000268H
STATUS_ILLEGAL_DLL_RELOCATION                   EQU     0C0000269H
STATUS_LICENSE_VIOLATION                        EQU     0C000026AH
STATUS_DLL_INIT_FAILED_LOGOFF                   EQU     0C000026BH
STATUS_DRIVER_UNABLE_TO_LOAD                    EQU     0C000026CH
STATUS_DFS_UNAVAILABLE                          EQU     0C000026DH
STATUS_VOLUME_DISMOUNTED                        EQU     0C000026EH
STATUS_WX86_INTERNAL_ERROR                      EQU     0C000026FH
STATUS_WX86_FLOAT_STACK_CHECK                   EQU     0C0000270H
STATUS_VALIDATE_CONTINUE                        EQU     0C0000271H
STATUS_NO_MATCH                                 EQU     0C0000272H
STATUS_NO_MORE_MATCHES                          EQU     0C0000273H
STATUS_NOT_A_REPARSE_POINT                      EQU     0C0000275H
STATUS_IO_REPARSE_TAG_INVALID                   EQU     0C0000276H
STATUS_IO_REPARSE_TAG_MISMATCH                  EQU     0C0000277H
STATUS_IO_REPARSE_DATA_INVALID                  EQU     0C0000278H
STATUS_IO_REPARSE_TAG_NOT_HANDLED               EQU     0C0000279H
STATUS_REPARSE_POINT_NOT_RESOLVED               EQU     0C0000280H
STATUS_DIRECTORY_IS_A_REPARSE_POINT             EQU     0C0000281H
STATUS_RANGE_LIST_CONFLICT                      EQU     0C0000282H
STATUS_SOURCE_ELEMENT_EMPTY                     EQU     0C0000283H
STATUS_DESTINATION_ELEMENT_FULL                 EQU     0C0000284H
STATUS_ILLEGAL_ELEMENT_ADDRESS                  EQU     0C0000285H
STATUS_MAGAZINE_NOT_PRESENT                     EQU     0C0000286H
STATUS_REINITIALIZATION_NEEDED                  EQU     0C0000287H
STATUS_DEVICE_REQUIRES_CLEANING                 EQU     080000288H
STATUS_DEVICE_DOOR_OPEN                         EQU     080000289H
STATUS_ENCRYPTION_FAILED                        EQU     0C000028AH
STATUS_DECRYPTION_FAILED                        EQU     0C000028BH
STATUS_RANGE_NOT_FOUND                          EQU     0C000028CH
STATUS_NO_RECOVERY_POLICY                       EQU     0C000028DH
STATUS_NO_EFS                                   EQU     0C000028EH
STATUS_WRONG_EFS                                EQU     0C000028FH
STATUS_NO_USER_KEYS                             EQU     0C0000290H
STATUS_FILE_NOT_ENCRYPTED                       EQU     0C0000291H
STATUS_NOT_EXPORT_FORMAT                        EQU     0C0000292H
STATUS_FILE_ENCRYPTED                           EQU     0C0000293H
STATUS_WAKE_SYSTEM                              EQU     040000294H
STATUS_WMI_GUID_NOT_FOUND                       EQU     0C0000295H
STATUS_WMI_INSTANCE_NOT_FOUND                   EQU     0C0000296H
STATUS_WMI_ITEMID_NOT_FOUND                     EQU     0C0000297H
STATUS_WMI_TRY_AGAIN                            EQU     0C0000298H
STATUS_SHARED_POLICY                            EQU     0C0000299H
STATUS_POLICY_OBJECT_NOT_FOUND                  EQU     0C000029AH
STATUS_POLICY_ONLY_IN_DS                        EQU     0C000029BH
STATUS_VOLUME_NOT_UPGRADED                      EQU     0C000029CH
STATUS_REMOTE_STORAGE_NOT_ACTIVE                EQU     0C000029DH
STATUS_REMOTE_STORAGE_MEDIA_ERROR               EQU     0C000029EH
STATUS_NO_TRACKING_SERVICE                      EQU     0C000029FH
STATUS_SERVER_SID_MISMATCH                      EQU     0C00002A0H
STATUS_DS_NO_ATTRIBUTE_OR_VALUE                 EQU     0C00002A1H
STATUS_DS_INVALID_ATTRIBUTE_SYNTAX              EQU     0C00002A2H
STATUS_DS_ATTRIBUTE_TYPE_UNDEFINED              EQU     0C00002A3H
STATUS_DS_ATTRIBUTE_OR_VALUE_EXISTS             EQU     0C00002A4H
STATUS_DS_BUSY                                  EQU     0C00002A5H
STATUS_DS_UNAVAILABLE                           EQU     0C00002A6H
STATUS_DS_NO_RIDS_ALLOCATED                     EQU     0C00002A7H
STATUS_DS_NO_MORE_RIDS                          EQU     0C00002A8H
STATUS_DS_INCORRECT_ROLE_OWNER                  EQU     0C00002A9H
STATUS_DS_RIDMGR_INIT_ERROR                     EQU     0C00002AAH
STATUS_DS_OBJ_CLASS_VIOLATION                   EQU     0C00002ABH
STATUS_DS_CANT_ON_NON_LEAF                      EQU     0C00002ACH
STATUS_DS_CANT_ON_RDN                           EQU     0C00002ADH
STATUS_DS_CANT_MOD_OBJ_CLASS                    EQU     0C00002AEH
STATUS_DS_CROSS_DOM_MOVE_FAILED                 EQU     0C00002AFH
STATUS_DS_GC_NOT_AVAILABLE                      EQU     0C00002B0H
STATUS_DIRECTORY_SERVICE_REQUIRED               EQU     0C00002B1H
STATUS_REPARSE_ATTRIBUTE_CONFLICT               EQU     0C00002B2H
STATUS_CANT_ENABLE_DENY_ONLY                    EQU     0C00002B3H
STATUS_DEVICE_REMOVED                           EQU     0C00002B6H
STATUS_JOURNAL_DELETE_IN_PROGRESS               EQU     0C00002B7H
STATUS_JOURNAL_NOT_ACTIVE                       EQU     0C00002B8H
STATUS_NOINTERFACE                              EQU     0C00002B9H
STATUS_DS_ADMIN_LIMIT_EXCEEDED                  EQU     0C00002C1H
STATUS_DRIVER_FAILED_SLEEP                      EQU     0C00002C2H
STATUS_MUTUAL_AUTHENTICATION_FAILED             EQU     0C00002C3H
STATUS_CORRUPT_SYSTEM_FILE                      EQU     0C00002C4H
STATUS_DATATYPE_MISALIGNMENT_ERROR              EQU     0C00002C5H
STATUS_WMI_READ_ONLY                            EQU     0C00002C6H
STATUS_WMI_SET_FAILURE                          EQU     0C00002C7H
STATUS_COMMITMENT_MINIMUM                       EQU     0C00002C8H
STATUS_TRANSPORT_FULL                           EQU     0C00002CAH
STATUS_DS_SAM_INIT_FAILURE                      EQU     0C00002CBH
STATUS_ONLY_IF_CONNECTED                        EQU     0C00002CCH
STATUS_DS_SENSITIVE_GROUP_VIOLATION             EQU     0C00002CDH
STATUS_PNP_RESTART_ENUMERATION                  EQU     0C00002CEH
STATUS_JOURNAL_ENTRY_DELETED                    EQU     0C00002CFH
STATUS_DS_CANT_MOD_PRIMARYGROUPID               EQU     0C00002D0H
STATUS_SYSTEM_IMAGE_BAD_SIGNATURE               EQU     0C00002D1H
STATUS_PNP_REBOOT_REQUIRED                      EQU     0C00002D2H
STATUS_POWER_STATE_INVALID                      EQU     0C00002D3H
STATUS_DS_INVALID_GROUP_TYPE                    EQU     0C00002D4H
STATUS_DS_NO_NEST_GLOBALGROUP_IN_MIXEDDOMAIN    EQU     0C00002D5H
STATUS_DS_NO_NEST_LOCALGROUP_IN_MIXEDDOMAIN     EQU     0C00002D6H
STATUS_DS_GLOBAL_CANT_HAVE_LOCAL_MEMBER         EQU     0C00002D7H
STATUS_DS_GLOBAL_CANT_HAVE_UNIVERSAL_MEMBER     EQU     0C00002D8H
STATUS_DS_UNIVERSAL_CANT_HAVE_LOCAL_MEMBER      EQU     0C00002D9H
STATUS_DS_GLOBAL_CANT_HAVE_CROSSDOMAIN_MEMBER   EQU     0C00002DAH
STATUS_DS_LOCAL_CANT_HAVE_CROSSDOMAIN_LOCAL_MEMBER EQU  0C00002DBH
STATUS_DS_HAVE_PRIMARY_MEMBERS                  EQU     0C00002DCH
STATUS_WMI_NOT_SUPPORTED                        EQU     0C00002DDH
STATUS_INSUFFICIENT_POWER                       EQU     0C00002DEH
STATUS_SAM_NEED_BOOTKEY_PASSWORD                EQU     0C00002DFH
STATUS_SAM_NEED_BOOTKEY_FLOPPY                  EQU     0C00002E0H
STATUS_DS_CANT_START                            EQU     0C00002E1H
STATUS_DS_INIT_FAILURE                          EQU     0C00002E2H
STATUS_SAM_INIT_FAILURE                         EQU     0C00002E3H
STATUS_DS_GC_REQUIRED                           EQU     0C00002E4H
STATUS_DS_LOCAL_MEMBER_OF_LOCAL_ONLY            EQU     0C00002E5H
STATUS_DS_NO_FPO_IN_UNIVERSAL_GROUPS            EQU     0C00002E6H
STATUS_DS_MACHINE_ACCOUNT_QUOTA_EXCEEDED        EQU     0C00002E7H
STATUS_MULTIPLE_FAULT_VIOLATION                 EQU     0C00002E8H
STATUS_CURRENT_DOMAIN_NOT_ALLOWED               EQU     0C00002E9H
STATUS_CANNOT_MAKE                              EQU     0C00002EAH
STATUS_SYSTEM_SHUTDOWN                          EQU     0C00002EBH
STATUS_DS_INIT_FAILURE_CONSOLE                  EQU     0C00002ECH
STATUS_DS_SAM_INIT_FAILURE_CONSOLE              EQU     0C00002EDH
STATUS_UNFINISHED_CONTEXT_DELETED               EQU     0C00002EEH
STATUS_NO_TGT_REPLY                             EQU     0C00002EFH
STATUS_OBJECTID_NOT_FOUND                       EQU     0C00002F0H
STATUS_NO_IP_ADDRESSES                          EQU     0C00002F1H
STATUS_WRONG_CREDENTIAL_HANDLE                  EQU     0C00002F2H
STATUS_CRYPTO_SYSTEM_INVALID                    EQU     0C00002F3H
STATUS_MAX_REFERRALS_EXCEEDED                   EQU     0C00002F4H
STATUS_MUST_BE_KDC                              EQU     0C00002F5H
STATUS_STRONG_CRYPTO_NOT_SUPPORTED              EQU     0C00002F6H
STATUS_TOO_MANY_PRINCIPALS                      EQU     0C00002F7H
STATUS_NO_PA_DATA                               EQU     0C00002F8H
STATUS_PKINIT_NAME_MISMATCH                     EQU     0C00002F9H
STATUS_SMARTCARD_LOGON_REQUIRED                 EQU     0C00002FAH
STATUS_KDC_INVALID_REQUEST                      EQU     0C00002FBH
STATUS_KDC_UNABLE_TO_REFER                      EQU     0C00002FCH
STATUS_KDC_UNKNOWN_ETYPE                        EQU     0C00002FDH
STATUS_SHUTDOWN_IN_PROGRESS                     EQU     0C00002FEH
STATUS_SERVER_SHUTDOWN_IN_PROGRESS              EQU     0C00002FFH
STATUS_NOT_SUPPORTED_ON_SBS                     EQU     0C0000300H
STATUS_WMI_GUID_DISCONNECTED                    EQU     0C0000301H
STATUS_WMI_ALREADY_DISABLED                     EQU     0C0000302H
STATUS_WMI_ALREADY_ENABLED                      EQU     0C0000303H
STATUS_MFT_TOO_FRAGMENTED                       EQU     0C0000304H
STATUS_COPY_PROTECTION_FAILURE                  EQU     0C0000305H
STATUS_CSS_AUTHENTICATION_FAILURE               EQU     0C0000306H
STATUS_CSS_KEY_NOT_PRESENT                      EQU     0C0000307H
STATUS_CSS_KEY_NOT_ESTABLISHED                  EQU     0C0000308H
STATUS_CSS_SCRAMBLED_SECTOR                     EQU     0C0000309H
STATUS_CSS_REGION_MISMATCH                      EQU     0C000030AH
STATUS_CSS_RESETS_EXHAUSTED                     EQU     0C000030BH
STATUS_PKINIT_FAILURE                           EQU     0C0000320H
STATUS_SMARTCARD_SUBSYSTEM_FAILURE              EQU     0C0000321H
STATUS_NO_KERB_KEY                              EQU     0C0000322H
STATUS_HOST_DOWN                                EQU     0C0000350H
STATUS_UNSUPPORTED_PREAUTH                      EQU     0C0000351H
STATUS_EFS_ALG_BLOB_TOO_BIG                     EQU     0C0000352H
STATUS_PORT_NOT_SET                             EQU     0C0000353H
STATUS_DEBUGGER_INACTIVE                        EQU     0C0000354H
STATUS_DS_VERSION_CHECK_FAILURE                 EQU     0C0000355H
STATUS_AUDITING_DISABLED                        EQU     0C0000356H
STATUS_PRENT4_MACHINE_ACCOUNT                   EQU     0C0000357H
STATUS_DS_AG_CANT_HAVE_UNIVERSAL_MEMBER         EQU     0C0000358H
STATUS_INVALID_IMAGE_WIN_32                     EQU     0C0000359H
STATUS_INVALID_IMAGE_WIN_64                     EQU     0C000035AH
STATUS_BAD_BINDINGS                             EQU     0C000035BH
STATUS_NETWORK_SESSION_EXPIRED                  EQU     0C000035CH
STATUS_APPHELP_BLOCK                            EQU     0C000035DH
STATUS_ALL_SIDS_FILTERED                        EQU     0C000035EH
STATUS_NOT_SAFE_MODE_DRIVER                     EQU     0C000035FH
STATUS_ACCESS_DISABLED_BY_POLICY_DEFAULT        EQU     0C0000361H
STATUS_ACCESS_DISABLED_BY_POLICY_PATH           EQU     0C0000362H
STATUS_ACCESS_DISABLED_BY_POLICY_PUBLISHER      EQU     0C0000363H
STATUS_ACCESS_DISABLED_BY_POLICY_OTHER          EQU     0C0000364H
STATUS_FAILED_DRIVER_ENTRY                      EQU     0C0000365H
STATUS_DEVICE_ENUMERATION_ERROR                 EQU     0C0000366H
STATUS_WAIT_FOR_OPLOCK                          EQU     000000367H
STATUS_MOUNT_POINT_NOT_RESOLVED                 EQU     0C0000368H
STATUS_INVALID_DEVICE_OBJECT_PARAMETER          EQU     0C0000369H
STATUS_MCA_OCCURED                              EQU     0C000036AH
STATUS_DRIVER_BLOCKED_CRITICAL                  EQU     0C000036BH
STATUS_DRIVER_BLOCKED                           EQU     0C000036CH
STATUS_DRIVER_DATABASE_ERROR                    EQU     0C000036DH
STATUS_SYSTEM_HIVE_TOO_LARGE                    EQU     0C000036EH
STATUS_INVALID_IMPORT_OF_NON_DLL                EQU     0C000036FH
STATUS_DS_SHUTTING_DOWN                         EQU     040000370H
STATUS_SMARTCARD_WRONG_PIN                      EQU     0C0000380H
STATUS_SMARTCARD_CARD_BLOCKED                   EQU     0C0000381H
STATUS_SMARTCARD_CARD_NOT_AUTHENTICATED         EQU     0C0000382H
STATUS_SMARTCARD_NO_CARD                        EQU     0C0000383H
STATUS_SMARTCARD_NO_KEY_CONTAINER               EQU     0C0000384H
STATUS_SMARTCARD_NO_CERTIFICATE                 EQU     0C0000385H
STATUS_SMARTCARD_NO_KEYSET                      EQU     0C0000386H
STATUS_SMARTCARD_IO_ERROR                       EQU     0C0000387H
STATUS_DOWNGRADE_DETECTED                       EQU     0C0000388H
STATUS_SMARTCARD_CERT_REVOKED                   EQU     0C0000389H
STATUS_ISSUING_CA_UNTRUSTED                     EQU     0C000038AH
STATUS_REVOCATION_OFFLINE_C                     EQU     0C000038BH
STATUS_PKINIT_CLIENT_FAILURE                    EQU     0C000038CH
STATUS_SMARTCARD_CERT_EXPIRED                   EQU     0C000038DH
STATUS_DRIVER_FAILED_PRIOR_UNLOAD               EQU     0C000038EH
STATUS_SMARTCARD_SILENT_CONTEXT                 EQU     0C000038FH
STATUS_PER_USER_TRUST_QUOTA_EXCEEDED            EQU     0C0000401H
STATUS_ALL_USER_TRUST_QUOTA_EXCEEDED            EQU     0C0000402H
STATUS_USER_DELETE_TRUST_QUOTA_EXCEEDED         EQU     0C0000403H
STATUS_DS_NAME_NOT_UNIQUE                       EQU     0C0000404H
STATUS_DS_DUPLICATE_ID_FOUND                    EQU     0C0000405H
STATUS_DS_GROUP_CONVERSION_ERROR                EQU     0C0000406H
STATUS_VOLSNAP_PREPARE_HIBERNATE                EQU     0C0000407H
STATUS_USER2USER_REQUIRED                       EQU     0C0000408H
STATUS_STACK_BUFFER_OVERRUN                     EQU     0C0000409H
STATUS_NO_S4U_PROT_SUPPORT                      EQU     0C000040AH
STATUS_CROSSREALM_DELEGATION_FAILURE            EQU     0C000040BH
STATUS_REVOCATION_OFFLINE_KDC                   EQU     0C000040CH
STATUS_ISSUING_CA_UNTRUSTED_KDC                 EQU     0C000040DH
STATUS_KDC_CERT_EXPIRED                         EQU     0C000040EH
STATUS_KDC_CERT_REVOKED                         EQU     0C000040FH
STATUS_PARAMETER_QUOTA_EXCEEDED                 EQU     0C0000410H
STATUS_HIBERNATION_FAILURE                      EQU     0C0000411H
STATUS_DELAY_LOAD_FAILED                        EQU     0C0000412H
STATUS_AUTHENTICATION_FIREWALL_FAILED           EQU     0C0000413H
STATUS_VDM_DISALLOWED                           EQU     0C0000414H
STATUS_HUNG_DISPLAY_DRIVER_THREAD               EQU     0C0000415H
STATUS_WOW_ASSERTION                            EQU     0C0009898H
ERROR_INVALID_FUNCTION                          EQU     1
ERROR_FILE_NOT_FOUND                            EQU     2
ERROR_PATH_NOT_FOUND                            EQU     3
ERROR_TOO_MANY_OPEN_FILES                       EQU     4
ERROR_ACCESS_DENIED                             EQU     5
ERROR_INVALID_HANDLE                            EQU     6
ERROR_ARENA_TRASHED                             EQU     7
ERROR_NOT_ENOUGH_MEMORY                         EQU     8
ERROR_INVALID_BLOCK                             EQU     9
ERROR_BAD_ENVIRONMENT                           EQU     10
ERROR_BAD_FORMAT                                EQU     11
ERROR_INVALID_ACCESS                            EQU     12
ERROR_INVALID_DATA                              EQU     13
ERROR_OUTOFMEMORY                               EQU     14
ERROR_INVALID_DRIVE                             EQU     15
ERROR_CURRENT_DIRECTORY                         EQU     16
ERROR_NOT_SAME_DEVICE                           EQU     17
ERROR_NO_MORE_FILES                             EQU     18
ERROR_WRITE_PROTECT                             EQU     19
ERROR_BAD_UNIT                                  EQU     20
ERROR_NOT_READY                                 EQU     21
ERROR_BAD_COMMAND                               EQU     22
ERROR_CRC                                       EQU     23
ERROR_BAD_LENGTH                                EQU     24
ERROR_SEEK                                      EQU     25
ERROR_NOT_DOS_DISK                              EQU     26
ERROR_SECTOR_NOT_FOUND                          EQU     27
ERROR_OUT_OF_PAPER                              EQU     28
ERROR_WRITE_FAULT                               EQU     29
ERROR_READ_FAULT                                EQU     30
ERROR_GEN_FAILURE                               EQU     31
ERROR_SHARING_VIOLATION                         EQU     32
ERROR_LOCK_VIOLATION                            EQU     33
ERROR_WRONG_DISK                                EQU     34
ERROR_SHARING_BUFFER_EXCEEDED                   EQU     36
ERROR_HANDLE_EOF                                EQU     38
ERROR_HANDLE_DISK_FULL                          EQU     39
ERROR_NOT_SUPPORTED                             EQU     50
ERROR_REM_NOT_LIST                              EQU     51
ERROR_DUP_NAME                                  EQU     52
ERROR_BAD_NETPATH                               EQU     53
ERROR_NETWORK_BUSY                              EQU     54
ERROR_DEV_NOT_EXIST                             EQU     55
ERROR_TOO_MANY_CMDS                             EQU     56
ERROR_ADAP_HDW_ERR                              EQU     57
ERROR_BAD_NET_RESP                              EQU     58
ERROR_UNEXP_NET_ERR                             EQU     59
ERROR_BAD_REM_ADAP                              EQU     60
ERROR_PRINTQ_FULL                               EQU     61
ERROR_NO_SPOOL_SPACE                            EQU     62
ERROR_PRINT_CANCELLED                           EQU     63
ERROR_NETNAME_DELETED                           EQU     64
ERROR_NETWORK_ACCESS_DENIED                     EQU     65
ERROR_BAD_DEV_TYPE                              EQU     66
ERROR_BAD_NET_NAME                              EQU     67
ERROR_TOO_MANY_NAMES                            EQU     68
ERROR_TOO_MANY_SESS                             EQU     69
ERROR_SHARING_PAUSED                            EQU     70
ERROR_REQ_NOT_ACCEP                             EQU     71
ERROR_REDIR_PAUSED                              EQU     72
ERROR_FILE_EXISTS                               EQU     80
ERROR_CANNOT_MAKE                               EQU     82
ERROR_FAIL_I24                                  EQU     83
ERROR_OUT_OF_STRUCTURES                         EQU     84
ERROR_ALREADY_ASSIGNED                          EQU     85
ERROR_INVALID_PASSWORD                          EQU     86
ERROR_INVALID_PARAMETER                         EQU     87
ERROR_NET_WRITE_FAULT                           EQU     88
ERROR_NO_PROC_SLOTS                             EQU     89
ERROR_TOO_MANY_SEMAPHORES                       EQU     100
ERROR_EXCL_SEM_ALREADY_OWNED                    EQU     101
ERROR_SEM_IS_SET                                EQU     102
ERROR_TOO_MANY_SEM_REQUESTS                     EQU     103
ERROR_INVALID_AT_INTERRUPT_TIME                 EQU     104
ERROR_SEM_OWNER_DIED                            EQU     105
ERROR_SEM_USER_LIMIT                            EQU     106
ERROR_DISK_CHANGE                               EQU     107
ERROR_DRIVE_LOCKED                              EQU     108
ERROR_BROKEN_PIPE                               EQU     109
ERROR_OPEN_FAILED                               EQU     110
ERROR_BUFFER_OVERFLOW                           EQU     111
ERROR_DISK_FULL                                 EQU     112
ERROR_NO_MORE_SEARCH_HANDLES                    EQU     113
ERROR_INVALID_TARGET_HANDLE                     EQU     114
ERROR_INVALID_CATEGORY                          EQU     117
ERROR_INVALID_VERIFY_SWITCH                     EQU     118
ERROR_BAD_DRIVER_LEVEL                          EQU     119
ERROR_CALL_NOT_IMPLEMENTED                      EQU     120
ERROR_SEM_TIMEOUT                               EQU     121
ERROR_INSUFFICIENT_BUFFER                       EQU     122
ERROR_INVALID_NAME                              EQU     123
ERROR_INVALID_LEVEL                             EQU     124
ERROR_NO_VOLUME_LABEL                           EQU     125
ERROR_MOD_NOT_FOUND                             EQU     126
ERROR_PROC_NOT_FOUND                            EQU     127
ERROR_WAIT_NO_CHILDREN                          EQU     128
ERROR_CHILD_NOT_COMPLETE                        EQU     129
ERROR_DIRECT_ACCESS_HANDLE                      EQU     130
ERROR_NEGATIVE_SEEK                             EQU     131
ERROR_SEEK_ON_DEVICE                            EQU     132
ERROR_IS_JOIN_TARGET                            EQU     133
ERROR_IS_JOINED                                 EQU     134
ERROR_IS_SUBSTED                                EQU     135
ERROR_NOT_JOINED                                EQU     136
ERROR_NOT_SUBSTED                               EQU     137
ERROR_JOIN_TO_JOIN                              EQU     138
ERROR_SUBST_TO_SUBST                            EQU     139
ERROR_JOIN_TO_SUBST                             EQU     140
ERROR_SUBST_TO_JOIN                             EQU     141
ERROR_BUSY_DRIVE                                EQU     142
ERROR_SAME_DRIVE                                EQU     143
ERROR_DIR_NOT_ROOT                              EQU     144
ERROR_DIR_NOT_EMPTY                             EQU     145
ERROR_IS_SUBST_PATH                             EQU     146
ERROR_IS_JOIN_PATH                              EQU     147
ERROR_PATH_BUSY                                 EQU     148
ERROR_IS_SUBST_TARGET                           EQU     149
ERROR_SYSTEM_TRACE                              EQU     150
ERROR_INVALID_EVENT_COUNT                       EQU     151
ERROR_TOO_MANY_MUXWAITERS                       EQU     152
ERROR_INVALID_LIST_FORMAT                       EQU     153
ERROR_LABEL_TOO_LONG                            EQU     154
ERROR_TOO_MANY_TCBS                             EQU     155
ERROR_SIGNAL_REFUSED                            EQU     156
ERROR_DISCARDED                                 EQU     157
ERROR_NOT_LOCKED                                EQU     158
ERROR_BAD_THREADID_ADDR                         EQU     159
ERROR_BAD_ARGUMENTS                             EQU     160
ERROR_BAD_PATHNAME                              EQU     161
ERROR_SIGNAL_PENDING                            EQU     162
ERROR_MAX_THRDS_REACHED                         EQU     164
ERROR_LOCK_FAILED                               EQU     167
ERROR_BUSY                                      EQU     170
ERROR_CANCEL_VIOLATION                          EQU     173
ERROR_ATOMIC_LOCKS_NOT_SUPPORTED                EQU     174
ERROR_INVALID_SEGMENT_NUMBER                    EQU     180
ERROR_INVALID_ORDINAL                           EQU     182
ERROR_ALREADY_EXISTS                            EQU     183
ERROR_INVALID_FLAG_NUMBER                       EQU     186
ERROR_SEM_NOT_FOUND                             EQU     187
ERROR_INVALID_STARTING_CODESEG                  EQU     188
ERROR_INVALID_STACKSEG                          EQU     189
ERROR_INVALID_MODULETYPE                        EQU     190
ERROR_INVALID_EXE_SIGNATURE                     EQU     191
ERROR_EXE_MARKED_INVALID                        EQU     192
ERROR_BAD_EXE_FORMAT                            EQU     193
ERROR_ITERATED_DATA_EXCEEDS_64k                 EQU     194
ERROR_INVALID_MINALLOCSIZE                      EQU     195
ERROR_DYNLINK_FROM_INVALID_RING                 EQU     196
ERROR_IOPL_NOT_ENABLED                          EQU     197
ERROR_INVALID_SEGDPL                            EQU     198
ERROR_AUTODATASEG_EXCEEDS_64k                   EQU     199
ERROR_RING2SEG_MUST_BE_MOVABLE                  EQU     200
ERROR_RELOC_CHAIN_XEEDS_SEGLIM                  EQU     201
ERROR_INFLOOP_IN_RELOC_CHAIN                    EQU     202
ERROR_ENVVAR_NOT_FOUND                          EQU     203
ERROR_NO_SIGNAL_SENT                            EQU     205
ERROR_FILENAME_EXCED_RANGE                      EQU     206
ERROR_RING2_STACK_IN_USE                        EQU     207
ERROR_META_EXPANSION_TOO_LONG                   EQU     208
ERROR_INVALID_SIGNAL_NUMBER                     EQU     209
ERROR_THREAD_1_INACTIVE                         EQU     210
ERROR_LOCKED                                    EQU     212
ERROR_TOO_MANY_MODULES                          EQU     214
ERROR_NESTING_NOT_ALLOWED                       EQU     215
ERROR_EXE_MACHINE_TYPE_MISMATCH                 EQU     216
ERROR_EXE_CANNOT_MODIFY_SIGNED_BINARY           EQU     217
ERROR_EXE_CANNOT_MODIFY_STRONG_SIGNED_BINARY    EQU     218
ERROR_FILE_CHECKED_OUT                          EQU     220
ERROR_CHECKOUT_REQUIRED                         EQU     221
ERROR_BAD_FILE_TYPE                             EQU     222
ERROR_FILE_TOO_LARGE                            EQU     223
ERROR_FORMS_AUTH_REQUIRED                       EQU     224
ERROR_VIRUS_INFECTED                            EQU     225
ERROR_VIRUS_DELETED                             EQU     226
ERROR_PIPE_LOCAL                                EQU     229
ERROR_BAD_PIPE                                  EQU     230
ERROR_PIPE_BUSY                                 EQU     231
ERROR_NO_DATA                                   EQU     232
ERROR_PIPE_NOT_CONNECTED                        EQU     233
ERROR_MORE_DATA                                 EQU     234
ERROR_VC_DISCONNECTED                           EQU     240
ERROR_INVALID_EA_NAME                           EQU     254
ERROR_EA_LIST_INCONSISTENT                      EQU     255
WAIT_TIMEOUT                                    EQU     258
ERROR_NO_MORE_ITEMS                             EQU     259
ERROR_CANNOT_COPY                               EQU     266
ERROR_DIRECTORY                                 EQU     267
ERROR_EAS_DIDNT_FIT                             EQU     275
ERROR_EA_FILE_CORRUPT                           EQU     276
ERROR_EA_TABLE_FULL                             EQU     277
ERROR_INVALID_EA_HANDLE                         EQU     278
ERROR_EAS_NOT_SUPPORTED                         EQU     282
ERROR_NOT_OWNER                                 EQU     288
ERROR_TOO_MANY_POSTS                            EQU     298
ERROR_PARTIAL_COPY                              EQU     299
ERROR_OPLOCK_NOT_GRANTED                        EQU     300
ERROR_INVALID_OPLOCK_PROTOCOL                   EQU     301
ERROR_DISK_TOO_FRAGMENTED                       EQU     302
ERROR_DELETE_PENDING                            EQU     303
ERROR_INCOMPATIBLE_WITH_GLOBAL_SHORT_NAME_REGISTRY_SETTING EQU 304
ERROR_SHORT_NAMES_NOT_ENABLED_ON_VOLUME         EQU     305
ERROR_SECURITY_STREAM_IS_INCONSISTENT           EQU     306
ERROR_INVALID_LOCK_RANGE                        EQU     307
ERROR_IMAGE_SUBSYSTEM_NOT_PRESENT               EQU     308
ERROR_NOTIFICATION_GUID_ALREADY_DEFINED         EQU     309
ERROR_MR_MID_NOT_FOUND                          EQU     317
ERROR_SCOPE_NOT_FOUND                           EQU     318
ERROR_FAIL_NOACTION_REBOOT                      EQU     350
ERROR_FAIL_SHUTDOWN                             EQU     351
ERROR_FAIL_RESTART                              EQU     352
ERROR_MAX_SESSIONS_REACHED                      EQU     353
ERROR_THREAD_MODE_ALREADY_BACKGROUND            EQU     400
ERROR_THREAD_MODE_NOT_BACKGROUND                EQU     401
ERROR_PROCESS_MODE_ALREADY_BACKGROUND           EQU     402
ERROR_PROCESS_MODE_NOT_BACKGROUND               EQU     403
ERROR_INVALID_ADDRESS                           EQU     487
ERROR_USER_PROFILE_LOAD                         EQU     500
ERROR_ARITHMETIC_OVERFLOW                       EQU     534
ERROR_PIPE_CONNECTED                            EQU     535
ERROR_PIPE_LISTENING                            EQU     536
ERROR_VERIFIER_STOP                             EQU     537
ERROR_ABIOS_ERROR                               EQU     538
ERROR_WX86_WARNING                              EQU     539
ERROR_WX86_ERROR                                EQU     540
ERROR_TIMER_NOT_CANCELED                        EQU     541
ERROR_UNWIND                                    EQU     542
ERROR_BAD_STACK                                 EQU     543
ERROR_INVALID_UNWIND_TARGET                     EQU     544
ERROR_INVALID_PORT_ATTRIBUTES                   EQU     545
ERROR_PORT_MESSAGE_TOO_LONG                     EQU     546
ERROR_INVALID_QUOTA_LOWER                       EQU     547
ERROR_DEVICE_ALREADY_ATTACHED                   EQU     548
ERROR_INSTRUCTION_MISALIGNMENT                  EQU     549
ERROR_PROFILING_NOT_STARTED                     EQU     550
ERROR_PROFILING_NOT_STOPPED                     EQU     551
ERROR_COULD_NOT_INTERPRET                       EQU     552
ERROR_PROFILING_AT_LIMIT                        EQU     553
ERROR_CANT_WAIT                                 EQU     554
ERROR_CANT_TERMINATE_SELF                       EQU     555
ERROR_UNEXPECTED_MM_CREATE_ERR                  EQU     556
ERROR_UNEXPECTED_MM_MAP_ERROR                   EQU     557
ERROR_UNEXPECTED_MM_EXTEND_ERR                  EQU     558
ERROR_BAD_FUNCTION_TABLE                        EQU     559
ERROR_NO_GUID_TRANSLATION                       EQU     560
ERROR_INVALID_LDT_SIZE                          EQU     561
ERROR_INVALID_LDT_OFFSET                        EQU     563
ERROR_INVALID_LDT_DESCRIPTOR                    EQU     564
ERROR_TOO_MANY_THREADS                          EQU     565
ERROR_THREAD_NOT_IN_PROCESS                     EQU     566
ERROR_PAGEFILE_QUOTA_EXCEEDED                   EQU     567
ERROR_LOGON_SERVER_CONFLICT                     EQU     568
ERROR_SYNCHRONIZATION_REQUIRED                  EQU     569
ERROR_NET_OPEN_FAILED                           EQU     570
ERROR_IO_PRIVILEGE_FAILED                       EQU     571
ERROR_CONTROL_C_EXIT                            EQU     572
ERROR_MISSING_SYSTEMFILE                        EQU     573
ERROR_UNHANDLED_EXCEPTION                       EQU     574
ERROR_APP_INIT_FAILURE                          EQU     575
ERROR_PAGEFILE_CREATE_FAILED                    EQU     576
ERROR_INVALID_IMAGE_HASH                        EQU     577
ERROR_NO_PAGEFILE                               EQU     578
ERROR_ILLEGAL_FLOAT_CONTEXT                     EQU     579
ERROR_NO_EVENT_PAIR                             EQU     580
ERROR_DOMAIN_CTRLR_CONFIG_ERROR                 EQU     581
ERROR_ILLEGAL_CHARACTER                         EQU     582
ERROR_UNDEFINED_CHARACTER                       EQU     583
ERROR_FLOPPY_VOLUME                             EQU     584
ERROR_BIOS_FAILED_TO_CONNECT_INTERRUPT          EQU     585
ERROR_BACKUP_CONTROLLER                         EQU     586
ERROR_MUTANT_LIMIT_EXCEEDED                     EQU     587
ERROR_FS_DRIVER_REQUIRED                        EQU     588
ERROR_CANNOT_LOAD_REGISTRY_FILE                 EQU     589
ERROR_DEBUG_ATTACH_FAILED                       EQU     590
ERROR_SYSTEM_PROCESS_TERMINATED                 EQU     591
ERROR_DATA_NOT_ACCEPTED                         EQU     592
ERROR_VDM_HARD_ERROR                            EQU     593
ERROR_DRIVER_CANCEL_TIMEOUT                     EQU     594
ERROR_REPLY_MESSAGE_MISMATCH                    EQU     595
ERROR_LOST_WRITEBEHIND_DATA                     EQU     596
ERROR_CLIENT_SERVER_PARAMETERS_INVALID          EQU     597
ERROR_NOT_TINY_STREAM                           EQU     598
ERROR_STACK_OVERFLOW_READ                       EQU     599
ERROR_CONVERT_TO_LARGE                          EQU     600
ERROR_FOUND_OUT_OF_SCOPE                        EQU     601
ERROR_ALLOCATE_BUCKET                           EQU     602
ERROR_MARSHALL_OVERFLOW                         EQU     603
ERROR_INVALID_VARIANT                           EQU     604
ERROR_BAD_COMPRESSION_BUFFER                    EQU     605
ERROR_AUDIT_FAILED                              EQU     606
ERROR_TIMER_RESOLUTION_NOT_SET                  EQU     607
ERROR_INSUFFICIENT_LOGON_INFO                   EQU     608
ERROR_BAD_DLL_ENTRYPOINT                        EQU     609
ERROR_BAD_SERVICE_ENTRYPOINT                    EQU     610
ERROR_IP_ADDRESS_CONFLICT1                      EQU     611
ERROR_IP_ADDRESS_CONFLICT2                      EQU     612
ERROR_REGISTRY_QUOTA_LIMIT                      EQU     613
ERROR_NO_CALLBACK_ACTIVE                        EQU     614
ERROR_PWD_TOO_SHORT                             EQU     615
ERROR_PWD_TOO_RECENT                            EQU     616
ERROR_PWD_HISTORY_CONFLICT                      EQU     617
ERROR_UNSUPPORTED_COMPRESSION                   EQU     618
ERROR_INVALID_HW_PROFILE                        EQU     619
ERROR_INVALID_PLUGPLAY_DEVICE_PATH              EQU     620
ERROR_QUOTA_LIST_INCONSISTENT                   EQU     621
ERROR_EVALUATION_EXPIRATION                     EQU     622
ERROR_ILLEGAL_DLL_RELOCATION                    EQU     623
ERROR_DLL_INIT_FAILED_LOGOFF                    EQU     624
ERROR_VALIDATE_CONTINUE                         EQU     625
ERROR_NO_MORE_MATCHES                           EQU     626
ERROR_RANGE_LIST_CONFLICT                       EQU     627
ERROR_SERVER_SID_MISMATCH                       EQU     628
ERROR_CANT_ENABLE_DENY_ONLY                     EQU     629
ERROR_FLOAT_MULTIPLE_FAULTS                     EQU     630
ERROR_FLOAT_MULTIPLE_TRAPS                      EQU     631
ERROR_NOINTERFACE                               EQU     632
ERROR_DRIVER_FAILED_SLEEP                       EQU     633
ERROR_CORRUPT_SYSTEM_FILE                       EQU     634
ERROR_COMMITMENT_MINIMUM                        EQU     635
ERROR_PNP_RESTART_ENUMERATION                   EQU     636
ERROR_SYSTEM_IMAGE_BAD_SIGNATURE                EQU     637
ERROR_PNP_REBOOT_REQUIRED                       EQU     638
ERROR_INSUFFICIENT_POWER                        EQU     639
ERROR_MULTIPLE_FAULT_VIOLATION                  EQU     640
ERROR_SYSTEM_SHUTDOWN                           EQU     641
ERROR_PORT_NOT_SET                              EQU     642
ERROR_DS_VERSION_CHECK_FAILURE                  EQU     643
ERROR_RANGE_NOT_FOUND                           EQU     644
ERROR_NOT_SAFE_MODE_DRIVER                      EQU     646
ERROR_FAILED_DRIVER_ENTRY                       EQU     647
ERROR_DEVICE_ENUMERATION_ERROR                  EQU     648
ERROR_MOUNT_POINT_NOT_RESOLVED                  EQU     649
ERROR_INVALID_DEVICE_OBJECT_PARAMETER           EQU     650
ERROR_MCA_OCCURED                               EQU     651
ERROR_DRIVER_DATABASE_ERROR                     EQU     652
ERROR_SYSTEM_HIVE_TOO_LARGE                     EQU     653
ERROR_DRIVER_FAILED_PRIOR_UNLOAD                EQU     654
ERROR_VOLSNAP_PREPARE_HIBERNATE                 EQU     655
ERROR_HIBERNATION_FAILURE                       EQU     656
ERROR_FILE_SYSTEM_LIMITATION                    EQU     665
ERROR_ASSERTION_FAILURE                         EQU     668
ERROR_ACPI_ERROR                                EQU     669
ERROR_WOW_ASSERTION                             EQU     670
ERROR_PNP_BAD_MPS_TABLE                         EQU     671
ERROR_PNP_TRANSLATION_FAILED                    EQU     672
ERROR_PNP_IRQ_TRANSLATION_FAILED                EQU     673
ERROR_PNP_INVALID_ID                            EQU     674
ERROR_WAKE_SYSTEM_DEBUGGER                      EQU     675
ERROR_HANDLES_CLOSED                            EQU     676
ERROR_EXTRANEOUS_INFORMATION                    EQU     677
ERROR_RXACT_COMMIT_NECESSARY                    EQU     678
ERROR_MEDIA_CHECK                               EQU     679
ERROR_GUID_SUBSTITUTION_MADE                    EQU     680
ERROR_STOPPED_ON_SYMLINK                        EQU     681
ERROR_LONGJUMP                                  EQU     682
ERROR_PLUGPLAY_QUERY_VETOED                     EQU     683
ERROR_UNWIND_CONSOLIDATE                        EQU     684
ERROR_REGISTRY_HIVE_RECOVERED                   EQU     685
ERROR_DLL_MIGHT_BE_INSECURE                     EQU     686
ERROR_DLL_MIGHT_BE_INCOMPATIBLE                 EQU     687
ERROR_DBG_EXCEPTION_NOT_HANDLED                 EQU     688
ERROR_DBG_REPLY_LATER                           EQU     689
ERROR_DBG_UNABLE_TO_PROVIDE_HANDLE              EQU     690
ERROR_DBG_TERMINATE_THREAD                      EQU     691
ERROR_DBG_TERMINATE_PROCESS                     EQU     692
ERROR_DBG_CONTROL_C                             EQU     693
ERROR_DBG_PRINTEXCEPTION_C                      EQU     694
ERROR_DBG_RIPEXCEPTION                          EQU     695
ERROR_DBG_CONTROL_BREAK                         EQU     696
ERROR_DBG_COMMAND_EXCEPTION                     EQU     697
ERROR_OBJECT_NAME_EXISTS                        EQU     698
ERROR_THREAD_WAS_SUSPENDED                      EQU     699
ERROR_IMAGE_NOT_AT_BASE                         EQU     700
ERROR_RXACT_STATE_CREATED                       EQU     701
ERROR_SEGMENT_NOTIFICATION                      EQU     702
ERROR_BAD_CURRENT_DIRECTORY                     EQU     703
ERROR_FT_READ_RECOVERY_FROM_BACKUP              EQU     704
ERROR_FT_WRITE_RECOVERY                         EQU     705
ERROR_IMAGE_MACHINE_TYPE_MISMATCH               EQU     706
ERROR_RECEIVE_PARTIAL                           EQU     707
ERROR_RECEIVE_EXPEDITED                         EQU     708
ERROR_RECEIVE_PARTIAL_EXPEDITED                 EQU     709
ERROR_EVENT_DONE                                EQU     710
ERROR_EVENT_PENDING                             EQU     711
ERROR_CHECKING_FILE_SYSTEM                      EQU     712
ERROR_FATAL_APP_EXIT                            EQU     713
ERROR_PREDEFINED_HANDLE                         EQU     714
ERROR_WAS_UNLOCKED                              EQU     715
ERROR_SERVICE_NOTIFICATION                      EQU     716
ERROR_WAS_LOCKED                                EQU     717
ERROR_LOG_HARD_ERROR                            EQU     718
ERROR_ALREADY_WIN32                             EQU     719
ERROR_IMAGE_MACHINE_TYPE_MISMATCH_EXE           EQU     720
ERROR_NO_YIELD_PERFORMED                        EQU     721
ERROR_TIMER_RESUME_IGNORED                      EQU     722
ERROR_ARBITRATION_UNHANDLED                     EQU     723
ERROR_CARDBUS_NOT_SUPPORTED                     EQU     724
ERROR_MP_PROCESSOR_MISMATCH                     EQU     725
ERROR_HIBERNATED                                EQU     726
ERROR_RESUME_HIBERNATION                        EQU     727
ERROR_FIRMWARE_UPDATED                          EQU     728
ERROR_DRIVERS_LEAKING_LOCKED_PAGES              EQU     729
ERROR_WAKE_SYSTEM                               EQU     730
ERROR_WAIT_1                                    EQU     731
ERROR_WAIT_2                                    EQU     732
ERROR_WAIT_3                                    EQU     733
ERROR_WAIT_63                                   EQU     734
ERROR_ABANDONED_WAIT_0                          EQU     735
ERROR_ABANDONED_WAIT_63                         EQU     736
ERROR_USER_APC                                  EQU     737
ERROR_KERNEL_APC                                EQU     738
ERROR_ALERTED                                   EQU     739
ERROR_ELEVATION_REQUIRED                        EQU     740
ERROR_REPARSE                                   EQU     741
ERROR_OPLOCK_BREAK_IN_PROGRESS                  EQU     742
ERROR_VOLUME_MOUNTED                            EQU     743
ERROR_RXACT_COMMITTED                           EQU     744
ERROR_NOTIFY_CLEANUP                            EQU     745
ERROR_PRIMARY_TRANSPORT_CONNECT_FAILED          EQU     746
ERROR_PAGE_FAULT_TRANSITION                     EQU     747
ERROR_PAGE_FAULT_DEMAND_ZERO                    EQU     748
ERROR_PAGE_FAULT_COPY_ON_WRITE                  EQU     749
ERROR_PAGE_FAULT_GUARD_PAGE                     EQU     750
ERROR_PAGE_FAULT_PAGING_FILE                    EQU     751
ERROR_CACHE_PAGE_LOCKED                         EQU     752
ERROR_CRASH_DUMP                                EQU     753
ERROR_BUFFER_ALL_ZEROS                          EQU     754
ERROR_REPARSE_OBJECT                            EQU     755
ERROR_RESOURCE_REQUIREMENTS_CHANGED             EQU     756
ERROR_TRANSLATION_COMPLETE                      EQU     757
ERROR_NOTHING_TO_TERMINATE                      EQU     758
ERROR_PROCESS_NOT_IN_JOB                        EQU     759
ERROR_PROCESS_IN_JOB                            EQU     760
ERROR_VOLSNAP_HIBERNATE_READY                   EQU     761
ERROR_FSFILTER_OP_COMPLETED_SUCCESSFULLY        EQU     762
ERROR_INTERRUPT_VECTOR_ALREADY_CONNECTED        EQU     763
ERROR_INTERRUPT_STILL_CONNECTED                 EQU     764
ERROR_WAIT_FOR_OPLOCK                           EQU     765
ERROR_DBG_EXCEPTION_HANDLED                     EQU     766
ERROR_DBG_CONTINUE                              EQU     767
ERROR_CALLBACK_POP_STACK                        EQU     768
ERROR_COMPRESSION_DISABLED                      EQU     769
ERROR_CANTFETCHBACKWARDS                        EQU     770
ERROR_CANTSCROLLBACKWARDS                       EQU     771
ERROR_ROWSNOTRELEASED                           EQU     772
ERROR_BAD_ACCESSOR_FLAGS                        EQU     773
ERROR_ERRORS_ENCOUNTERED                        EQU     774
ERROR_NOT_CAPABLE                               EQU     775
ERROR_REQUEST_OUT_OF_SEQUENCE                   EQU     776
ERROR_VERSION_PARSE_ERROR                       EQU     777
ERROR_BADSTARTPOSITION                          EQU     778
ERROR_MEMORY_HARDWARE                           EQU     779
ERROR_DISK_REPAIR_DISABLED                      EQU     780
ERROR_INSUFFICIENT_RESOURCE_FOR_SPECIFIED_SHARED_SECTION_SIZE EQU 781
ERROR_SYSTEM_POWERSTATE_TRANSITION              EQU     782
ERROR_SYSTEM_POWERSTATE_COMPLEX_TRANSITION      EQU     783
ERROR_MCA_EXCEPTION                             EQU     784
ERROR_ACCESS_AUDIT_BY_POLICY                    EQU     785
ERROR_ACCESS_DISABLED_NO_SAFER_UI_BY_POLICY     EQU     786
ERROR_ABANDON_HIBERFILE                         EQU     787
ERROR_LOST_WRITEBEHIND_DATA_NETWORK_DISCONNECTED EQU 788
ERROR_LOST_WRITEBEHIND_DATA_NETWORK_SERVER_ERROR EQU 789
ERROR_LOST_WRITEBEHIND_DATA_LOCAL_DISK_ERROR    EQU     790
ERROR_BAD_MCFG_TABLE                            EQU     791
ERROR_OPLOCK_SWITCHED_TO_NEW_HANDLE             EQU     800
ERROR_CANNOT_GRANT_REQUESTED_OPLOCK             EQU     801
ERROR_CANNOT_BREAK_OPLOCK                       EQU     802
ERROR_OPLOCK_HANDLE_CLOSED                      EQU     803
ERROR_NO_ACE_CONDITION                          EQU     804
ERROR_INVALID_ACE_CONDITION                     EQU     805
ERROR_EA_ACCESS_DENIED                          EQU     994
ERROR_OPERATION_ABORTED                         EQU     995
ERROR_IO_INCOMPLETE                             EQU     996
ERROR_IO_PENDING                                EQU     997
ERROR_NOACCESS                                  EQU     998
ERROR_SWAPERROR                                 EQU     999
ERROR_STACK_OVERFLOW                            EQU     1001
ERROR_INVALID_MESSAGE                           EQU     1002
ERROR_CAN_NOT_COMPLETE                          EQU     1003
ERROR_INVALID_FLAGS                             EQU     1004
ERROR_UNRECOGNIZED_VOLUME                       EQU     1005
ERROR_FILE_INVALID                              EQU     1006
ERROR_FULLSCREEN_MODE                           EQU     1007
ERROR_NO_TOKEN                                  EQU     1008
ERROR_BADDB                                     EQU     1009
ERROR_BADKEY                                    EQU     1010
ERROR_CANTOPEN                                  EQU     1011
ERROR_CANTREAD                                  EQU     1012
ERROR_CANTWRITE                                 EQU     1013
ERROR_REGISTRY_RECOVERED                        EQU     1014
ERROR_REGISTRY_CORRUPT                          EQU     1015
ERROR_REGISTRY_IO_FAILED                        EQU     1016
ERROR_NOT_REGISTRY_FILE                         EQU     1017
ERROR_KEY_DELETED                               EQU     1018
ERROR_NO_LOG_SPACE                              EQU     1019
ERROR_KEY_HAS_CHILDREN                          EQU     1020
ERROR_CHILD_MUST_BE_VOLATILE                    EQU     1021
ERROR_NOTIFY_ENUM_DIR                           EQU     1022
ERROR_DEPENDENT_SERVICES_RUNNING                EQU     1051
ERROR_INVALID_SERVICE_CONTROL                   EQU     1052
ERROR_SERVICE_REQUEST_TIMEOUT                   EQU     1053
ERROR_SERVICE_NO_THREAD                         EQU     1054
ERROR_SERVICE_DATABASE_LOCKED                   EQU     1055
ERROR_SERVICE_ALREADY_RUNNING                   EQU     1056
ERROR_INVALID_SERVICE_ACCOUNT                   EQU     1057
ERROR_SERVICE_DISABLED                          EQU     1058
ERROR_CIRCULAR_DEPENDENCY                       EQU     1059
ERROR_SERVICE_DOES_NOT_EXIST                    EQU     1060
ERROR_SERVICE_CANNOT_ACCEPT_CTRL                EQU     1061
ERROR_SERVICE_NOT_ACTIVE                        EQU     1062
ERROR_FAILED_SERVICE_CONTROLLER_CONNECT         EQU     1063
ERROR_EXCEPTION_IN_SERVICE                      EQU     1064
ERROR_DATABASE_DOES_NOT_EXIST                   EQU     1065
ERROR_SERVICE_SPECIFIC_ERROR                    EQU     1066
ERROR_PROCESS_ABORTED                           EQU     1067
ERROR_SERVICE_DEPENDENCY_FAIL                   EQU     1068
ERROR_SERVICE_LOGON_FAILED                      EQU     1069
ERROR_SERVICE_START_HANG                        EQU     1070
ERROR_INVALID_SERVICE_LOCK                      EQU     1071
ERROR_SERVICE_MARKED_FOR_DELETE                 EQU     1072
ERROR_SERVICE_EXISTS                            EQU     1073
ERROR_ALREADY_RUNNING_LKG                       EQU     1074
ERROR_SERVICE_DEPENDENCY_DELETED                EQU     1075
ERROR_BOOT_ALREADY_ACCEPTED                     EQU     1076
ERROR_SERVICE_NEVER_STARTED                     EQU     1077
ERROR_DUPLICATE_SERVICE_NAME                    EQU     1078
ERROR_DIFFERENT_SERVICE_ACCOUNT                 EQU     1079
ERROR_CANNOT_DETECT_DRIVER_FAILURE              EQU     1080
ERROR_CANNOT_DETECT_PROCESS_ABORT               EQU     1081
ERROR_NO_RECOVERY_PROGRAM                       EQU     1082
ERROR_SERVICE_NOT_IN_EXE                        EQU     1083
ERROR_NOT_SAFEBOOT_SERVICE                      EQU     1084
ERROR_END_OF_MEDIA                              EQU     1100
ERROR_FILEMARK_DETECTED                         EQU     1101
ERROR_BEGINNING_OF_MEDIA                        EQU     1102
ERROR_SETMARK_DETECTED                          EQU     1103
ERROR_NO_DATA_DETECTED                          EQU     1104
ERROR_PARTITION_FAILURE                         EQU     1105
ERROR_INVALID_BLOCK_LENGTH                      EQU     1106
ERROR_DEVICE_NOT_PARTITIONED                    EQU     1107
ERROR_UNABLE_TO_LOCK_MEDIA                      EQU     1108
ERROR_UNABLE_TO_UNLOAD_MEDIA                    EQU     1109
ERROR_MEDIA_CHANGED                             EQU     1110
ERROR_BUS_RESET                                 EQU     1111
ERROR_NO_MEDIA_IN_DRIVE                         EQU     1112
ERROR_NO_UNICODE_TRANSLATION                    EQU     1113
ERROR_DLL_INIT_FAILED                           EQU     1114
ERROR_SHUTDOWN_IN_PROGRESS                      EQU     1115
ERROR_NO_SHUTDOWN_IN_PROGRESS                   EQU     1116
ERROR_IO_DEVICE                                 EQU     1117
ERROR_SERIAL_NO_DEVICE                          EQU     1118
ERROR_IRQ_BUSY                                  EQU     1119
ERROR_MORE_WRITES                               EQU     1120
ERROR_COUNTER_TIMEOUT                           EQU     1121
ERROR_FLOPPY_ID_MARK_NOT_FOUND                  EQU     1122
ERROR_FLOPPY_WRONG_CYLINDER                     EQU     1123
ERROR_FLOPPY_UNKNOWN_ERROR                      EQU     1124
ERROR_FLOPPY_BAD_REGISTERS                      EQU     1125
ERROR_DISK_RECALIBRATE_FAILED                   EQU     1126
ERROR_DISK_OPERATION_FAILED                     EQU     1127
ERROR_DISK_RESET_FAILED                         EQU     1128
ERROR_EOM_OVERFLOW                              EQU     1129
ERROR_NOT_ENOUGH_SERVER_MEMORY                  EQU     1130
ERROR_POSSIBLE_DEADLOCK                         EQU     1131
ERROR_MAPPED_ALIGNMENT                          EQU     1132
ERROR_SET_POWER_STATE_VETOED                    EQU     1140
ERROR_SET_POWER_STATE_FAILED                    EQU     1141
ERROR_TOO_MANY_LINKS                            EQU     1142
ERROR_OLD_WIN_VERSION                           EQU     1150
ERROR_APP_WRONG_OS                              EQU     1151
ERROR_SINGLE_INSTANCE_APP                       EQU     1152
ERROR_RMODE_APP                                 EQU     1153
ERROR_INVALID_DLL                               EQU     1154
ERROR_NO_ASSOCIATION                            EQU     1155
ERROR_DDE_FAIL                                  EQU     1156
ERROR_DLL_NOT_FOUND                             EQU     1157
ERROR_NO_MORE_USER_HANDLES                      EQU     1158
ERROR_MESSAGE_SYNC_ONLY                         EQU     1159
ERROR_SOURCE_ELEMENT_EMPTY                      EQU     1160
ERROR_DESTINATION_ELEMENT_FULL                  EQU     1161
ERROR_ILLEGAL_ELEMENT_ADDRESS                   EQU     1162
ERROR_MAGAZINE_NOT_PRESENT                      EQU     1163
ERROR_DEVICE_REINITIALIZATION_NEEDED            EQU     1164
ERROR_DEVICE_REQUIRES_CLEANING                  EQU     1165
ERROR_DEVICE_DOOR_OPEN                          EQU     1166
ERROR_DEVICE_NOT_CONNECTED                      EQU     1167
ERROR_NOT_FOUND                                 EQU     1168
ERROR_NO_MATCH                                  EQU     1169
ERROR_SET_NOT_FOUND                             EQU     1170
ERROR_POINT_NOT_FOUND                           EQU     1171
ERROR_NO_TRACKING_SERVICE                       EQU     1172
ERROR_NO_VOLUME_ID                              EQU     1173
ERROR_UNABLE_TO_REMOVE_REPLACED                 EQU     1175
ERROR_UNABLE_TO_MOVE_REPLACEMENT                EQU     1176
ERROR_UNABLE_TO_MOVE_REPLACEMENT_2              EQU     1177
ERROR_JOURNAL_DELETE_IN_PROGRESS                EQU     1178
ERROR_JOURNAL_NOT_ACTIVE                        EQU     1179
ERROR_POTENTIAL_FILE_FOUND                      EQU     1180
ERROR_JOURNAL_ENTRY_DELETED                     EQU     1181
ERROR_SHUTDOWN_IS_SCHEDULED                     EQU     1190
ERROR_SHUTDOWN_USERS_LOGGED_ON                  EQU     1191
ERROR_BAD_DEVICE                                EQU     1200
ERROR_CONNECTION_UNAVAIL                        EQU     1201
ERROR_DEVICE_ALREADY_REMEMBERED                 EQU     1202
ERROR_NO_NET_OR_BAD_PATH                        EQU     1203
ERROR_BAD_PROVIDER                              EQU     1204
ERROR_CANNOT_OPEN_PROFILE                       EQU     1205
ERROR_BAD_PROFILE                               EQU     1206
ERROR_NOT_CONTAINER                             EQU     1207
ERROR_EXTENDED_ERROR                            EQU     1208
ERROR_INVALID_GROUPNAME                         EQU     1209
ERROR_INVALID_COMPUTERNAME                      EQU     1210
ERROR_INVALID_EVENTNAME                         EQU     1211
ERROR_INVALID_DOMAINNAME                        EQU     1212
ERROR_INVALID_SERVICENAME                       EQU     1213
ERROR_INVALID_NETNAME                           EQU     1214
ERROR_INVALID_SHARENAME                         EQU     1215
ERROR_INVALID_PASSWORDNAME                      EQU     1216
ERROR_INVALID_MESSAGENAME                       EQU     1217
ERROR_INVALID_MESSAGEDEST                       EQU     1218
ERROR_SESSION_CREDENTIAL_CONFLICT               EQU     1219
ERROR_REMOTE_SESSION_LIMIT_EXCEEDED             EQU     1220
ERROR_DUP_DOMAINNAME                            EQU     1221
ERROR_NO_NETWORK                                EQU     1222
ERROR_CANCELLED                                 EQU     1223
ERROR_USER_MAPPED_FILE                          EQU     1224
ERROR_CONNECTION_REFUSED                        EQU     1225
ERROR_GRACEFUL_DISCONNECT                       EQU     1226
ERROR_ADDRESS_ALREADY_ASSOCIATED                EQU     1227
ERROR_ADDRESS_NOT_ASSOCIATED                    EQU     1228
ERROR_CONNECTION_INVALID                        EQU     1229
ERROR_CONNECTION_ACTIVE                         EQU     1230
ERROR_NETWORK_UNREACHABLE                       EQU     1231
ERROR_HOST_UNREACHABLE                          EQU     1232
ERROR_PROTOCOL_UNREACHABLE                      EQU     1233
ERROR_PORT_UNREACHABLE                          EQU     1234
ERROR_REQUEST_ABORTED                           EQU     1235
ERROR_CONNECTION_ABORTED                        EQU     1236
ERROR_RETRY                                     EQU     1237
ERROR_CONNECTION_COUNT_LIMIT                    EQU     1238
ERROR_LOGIN_TIME_RESTRICTION                    EQU     1239
ERROR_LOGIN_WKSTA_RESTRICTION                   EQU     1240
ERROR_INCORRECT_ADDRESS                         EQU     1241
ERROR_ALREADY_REGISTERED                        EQU     1242
ERROR_SERVICE_NOT_FOUND                         EQU     1243
ERROR_NOT_AUTHENTICATED                         EQU     1244
ERROR_NOT_LOGGED_ON                             EQU     1245
ERROR_CONTINUE                                  EQU     1246
ERROR_ALREADY_INITIALIZED                       EQU     1247
ERROR_NO_MORE_DEVICES                           EQU     1248
ERROR_NO_SUCH_SITE                              EQU     1249
ERROR_DOMAIN_CONTROLLER_EXISTS                  EQU     1250
ERROR_ONLY_IF_CONNECTED                         EQU     1251
ERROR_OVERRIDE_NOCHANGES                        EQU     1252
ERROR_BAD_USER_PROFILE                          EQU     1253
ERROR_NOT_SUPPORTED_ON_SBS                      EQU     1254
ERROR_SERVER_SHUTDOWN_IN_PROGRESS               EQU     1255
ERROR_HOST_DOWN                                 EQU     1256
ERROR_NON_ACCOUNT_SID                           EQU     1257
ERROR_NON_DOMAIN_SID                            EQU     1258
ERROR_APPHELP_BLOCK                             EQU     1259
ERROR_ACCESS_DISABLED_BY_POLICY                 EQU     1260
ERROR_REG_NAT_CONSUMPTION                       EQU     1261
ERROR_CSCSHARE_OFFLINE                          EQU     1262
ERROR_PKINIT_FAILURE                            EQU     1263
ERROR_SMARTCARD_SUBSYSTEM_FAILURE               EQU     1264
ERROR_DOWNGRADE_DETECTED                        EQU     1265
ERROR_MACHINE_LOCKED                            EQU     1271
ERROR_CALLBACK_SUPPLIED_INVALID_DATA            EQU     1273
ERROR_SYNC_FOREGROUND_REFRESH_REQUIRED          EQU     1274
ERROR_DRIVER_BLOCKED                            EQU     1275
ERROR_INVALID_IMPORT_OF_NON_DLL                 EQU     1276
ERROR_ACCESS_DISABLED_WEBBLADE                  EQU     1277
ERROR_ACCESS_DISABLED_WEBBLADE_TAMPER           EQU     1278
ERROR_RECOVERY_FAILURE                          EQU     1279
ERROR_ALREADY_FIBER                             EQU     1280
ERROR_ALREADY_THREAD                            EQU     1281
ERROR_STACK_BUFFER_OVERRUN                      EQU     1282
ERROR_PARAMETER_QUOTA_EXCEEDED                  EQU     1283
ERROR_DEBUGGER_INACTIVE                         EQU     1284
ERROR_DELAY_LOAD_FAILED                         EQU     1285
ERROR_VDM_DISALLOWED                            EQU     1286
ERROR_UNIDENTIFIED_ERROR                        EQU     1287
ERROR_INVALID_CRUNTIME_PARAMETER                EQU     1288
ERROR_BEYOND_VDL                                EQU     1289
ERROR_INCOMPATIBLE_SERVICE_SID_TYPE             EQU     1290
ERROR_DRIVER_PROCESS_TERMINATED                 EQU     1291
ERROR_IMPLEMENTATION_LIMIT                      EQU     1292
ERROR_PROCESS_IS_PROTECTED                      EQU     1293
ERROR_SERVICE_NOTIFY_CLIENT_LAGGING             EQU     1294
ERROR_DISK_QUOTA_EXCEEDED                       EQU     1295
ERROR_CONTENT_BLOCKED                           EQU     1296
ERROR_INCOMPATIBLE_SERVICE_PRIVILEGE            EQU     1297
ERROR_APP_HANG                                  EQU     1298
ERROR_INVALID_LABEL                             EQU     1299
ERROR_NOT_ALL_ASSIGNED                          EQU     1300
ERROR_SOME_NOT_MAPPED                           EQU     1301
ERROR_NO_QUOTAS_FOR_ACCOUNT                     EQU     1302
ERROR_LOCAL_USER_SESSION_KEY                    EQU     1303
ERROR_NULL_LM_PASSWORD                          EQU     1304
ERROR_UNKNOWN_REVISION                          EQU     1305
ERROR_REVISION_MISMATCH                         EQU     1306
ERROR_INVALID_OWNER                             EQU     1307
ERROR_INVALID_PRIMARY_GROUP                     EQU     1308
ERROR_NO_IMPERSONATION_TOKEN                    EQU     1309
ERROR_CANT_DISABLE_MANDATORY                    EQU     1310
ERROR_NO_LOGON_SERVERS                          EQU     1311
ERROR_NO_SUCH_LOGON_SESSION                     EQU     1312
ERROR_NO_SUCH_PRIVILEGE                         EQU     1313
ERROR_PRIVILEGE_NOT_HELD                        EQU     1314
ERROR_INVALID_ACCOUNT_NAME                      EQU     1315
ERROR_USER_EXISTS                               EQU     1316
ERROR_NO_SUCH_USER                              EQU     1317
ERROR_GROUP_EXISTS                              EQU     1318
ERROR_NO_SUCH_GROUP                             EQU     1319
ERROR_MEMBER_IN_GROUP                           EQU     1320
ERROR_MEMBER_NOT_IN_GROUP                       EQU     1321
ERROR_LAST_ADMIN                                EQU     1322
ERROR_WRONG_PASSWORD                            EQU     1323
ERROR_ILL_FORMED_PASSWORD                       EQU     1324
ERROR_PASSWORD_RESTRICTION                      EQU     1325
ERROR_LOGON_FAILURE                             EQU     1326
ERROR_ACCOUNT_RESTRICTION                       EQU     1327
ERROR_INVALID_LOGON_HOURS                       EQU     1328
ERROR_INVALID_WORKSTATION                       EQU     1329
ERROR_PASSWORD_EXPIRED                          EQU     1330
ERROR_ACCOUNT_DISABLED                          EQU     1331
ERROR_NONE_MAPPED                               EQU     1332
ERROR_TOO_MANY_LUIDS_REQUESTED                  EQU     1333
ERROR_LUIDS_EXHAUSTED                           EQU     1334
ERROR_INVALID_SUB_AUTHORITY                     EQU     1335
ERROR_INVALID_ACL                               EQU     1336
ERROR_INVALID_SID                               EQU     1337
ERROR_INVALID_SECURITY_DESCR                    EQU     1338
ERROR_BAD_INHERITANCE_ACL                       EQU     1340
ERROR_SERVER_DISABLED                           EQU     1341
ERROR_SERVER_NOT_DISABLED                       EQU     1342
ERROR_INVALID_ID_AUTHORITY                      EQU     1343
ERROR_ALLOTTED_SPACE_EXCEEDED                   EQU     1344
ERROR_INVALID_GROUP_ATTRIBUTES                  EQU     1345
ERROR_BAD_IMPERSONATION_LEVEL                   EQU     1346
ERROR_CANT_OPEN_ANONYMOUS                       EQU     1347
ERROR_BAD_VALIDATION_CLASS                      EQU     1348
ERROR_BAD_TOKEN_TYPE                            EQU     1349
ERROR_NO_SECURITY_ON_OBJECT                     EQU     1350
ERROR_CANT_ACCESS_DOMAIN_INFO                   EQU     1351
ERROR_INVALID_SERVER_STATE                      EQU     1352
ERROR_INVALID_DOMAIN_STATE                      EQU     1353
ERROR_INVALID_DOMAIN_ROLE                       EQU     1354
ERROR_NO_SUCH_DOMAIN                            EQU     1355
ERROR_DOMAIN_EXISTS                             EQU     1356
ERROR_DOMAIN_LIMIT_EXCEEDED                     EQU     1357
ERROR_INTERNAL_DB_CORRUPTION                    EQU     1358
ERROR_INTERNAL_ERROR                            EQU     1359
ERROR_GENERIC_NOT_MAPPED                        EQU     1360
ERROR_BAD_DESCRIPTOR_FORMAT                     EQU     1361
ERROR_NOT_LOGON_PROCESS                         EQU     1362
ERROR_LOGON_SESSION_EXISTS                      EQU     1363
ERROR_NO_SUCH_PACKAGE                           EQU     1364
ERROR_BAD_LOGON_SESSION_STATE                   EQU     1365
ERROR_LOGON_SESSION_COLLISION                   EQU     1366
ERROR_INVALID_LOGON_TYPE                        EQU     1367
ERROR_CANNOT_IMPERSONATE                        EQU     1368
ERROR_RXACT_INVALID_STATE                       EQU     1369
ERROR_RXACT_COMMIT_FAILURE                      EQU     1370
ERROR_SPECIAL_ACCOUNT                           EQU     1371
ERROR_SPECIAL_GROUP                             EQU     1372
ERROR_SPECIAL_USER                              EQU     1373
ERROR_MEMBERS_PRIMARY_GROUP                     EQU     1374
ERROR_TOKEN_ALREADY_IN_USE                      EQU     1375
ERROR_NO_SUCH_ALIAS                             EQU     1376
ERROR_MEMBER_NOT_IN_ALIAS                       EQU     1377
ERROR_MEMBER_IN_ALIAS                           EQU     1378
ERROR_ALIAS_EXISTS                              EQU     1379
ERROR_LOGON_NOT_GRANTED                         EQU     1380
ERROR_TOO_MANY_SECRETS                          EQU     1381
ERROR_SECRET_TOO_LONG                           EQU     1382
ERROR_INTERNAL_DB_ERROR                         EQU     1383
ERROR_TOO_MANY_CONTEXT_IDS                      EQU     1384
ERROR_LOGON_TYPE_NOT_GRANTED                    EQU     1385
ERROR_NT_CROSS_ENCRYPTION_REQUIRED              EQU     1386
ERROR_NO_SUCH_MEMBER                            EQU     1387
ERROR_INVALID_MEMBER                            EQU     1388
ERROR_TOO_MANY_SIDS                             EQU     1389
ERROR_LM_CROSS_ENCRYPTION_REQUIRED              EQU     1390
ERROR_NO_INHERITANCE                            EQU     1391
ERROR_FILE_CORRUPT                              EQU     1392
ERROR_DISK_CORRUPT                              EQU     1393
ERROR_NO_USER_SESSION_KEY                       EQU     1394
ERROR_LICENSE_QUOTA_EXCEEDED                    EQU     1395
ERROR_WRONG_TARGET_NAME                         EQU     1396
ERROR_MUTUAL_AUTH_FAILED                        EQU     1397
ERROR_TIME_SKEW                                 EQU     1398
ERROR_CURRENT_DOMAIN_NOT_ALLOWED                EQU     1399
ERROR_INVALID_WINDOW_HANDLE                     EQU     1400
ERROR_INVALID_MENU_HANDLE                       EQU     1401
ERROR_INVALID_CURSOR_HANDLE                     EQU     1402
ERROR_INVALID_ACCEL_HANDLE                      EQU     1403
ERROR_INVALID_HOOK_HANDLE                       EQU     1404
ERROR_INVALID_DWP_HANDLE                        EQU     1405
ERROR_TLW_WITH_WSCHILD                          EQU     1406
ERROR_CANNOT_FIND_WND_CLASS                     EQU     1407
ERROR_WINDOW_OF_OTHER_THREAD                    EQU     1408
ERROR_HOTKEY_ALREADY_REGISTERED                 EQU     1409
ERROR_CLASS_ALREADY_EXISTS                      EQU     1410
ERROR_CLASS_DOES_NOT_EXIST                      EQU     1411
ERROR_CLASS_HAS_WINDOWS                         EQU     1412
ERROR_INVALID_INDEX                             EQU     1413
ERROR_INVALID_ICON_HANDLE                       EQU     1414
ERROR_PRIVATE_DIALOG_INDEX                      EQU     1415
ERROR_LISTBOX_ID_NOT_FOUND                      EQU     1416
ERROR_NO_WILDCARD_CHARACTERS                    EQU     1417
ERROR_CLIPBOARD_NOT_OPEN                        EQU     1418
ERROR_HOTKEY_NOT_REGISTERED                     EQU     1419
ERROR_WINDOW_NOT_DIALOG                         EQU     1420
ERROR_CONTROL_ID_NOT_FOUND                      EQU     1421
ERROR_INVALID_COMBOBOX_MESSAGE                  EQU     1422
ERROR_WINDOW_NOT_COMBOBOX                       EQU     1423
ERROR_INVALID_EDIT_HEIGHT                       EQU     1424
ERROR_DC_NOT_FOUND                              EQU     1425
ERROR_INVALID_HOOK_FILTER                       EQU     1426
ERROR_INVALID_FILTER_PROC                       EQU     1427
ERROR_HOOK_NEEDS_HMOD                           EQU     1428
ERROR_GLOBAL_ONLY_HOOK                          EQU     1429
ERROR_JOURNAL_HOOK_SET                          EQU     1430
ERROR_HOOK_NOT_INSTALLED                        EQU     1431
ERROR_INVALID_LB_MESSAGE                        EQU     1432
ERROR_SETCOUNT_ON_BAD_LB                        EQU     1433
ERROR_LB_WITHOUT_TABSTOPS                       EQU     1434
ERROR_DESTROY_OBJECT_OF_OTHER_THREAD            EQU     1435
ERROR_CHILD_WINDOW_MENU                         EQU     1436
ERROR_NO_SYSTEM_MENU                            EQU     1437
ERROR_INVALID_MSGBOX_STYLE                      EQU     1438
ERROR_INVALID_SPI_VALUE                         EQU     1439
ERROR_SCREEN_ALREADY_LOCKED                     EQU     1440
ERROR_HWNDS_HAVE_DIFF_PARENT                    EQU     1441
ERROR_NOT_CHILD_WINDOW                          EQU     1442
ERROR_INVALID_GW_COMMAND                        EQU     1443
ERROR_INVALID_THREAD_ID                         EQU     1444
ERROR_NON_MDICHILD_WINDOW                       EQU     1445
ERROR_POPUP_ALREADY_ACTIVE                      EQU     1446
ERROR_NO_SCROLLBARS                             EQU     1447
ERROR_INVALID_SCROLLBAR_RANGE                   EQU     1448
ERROR_INVALID_SHOWWIN_COMMAND                   EQU     1449
ERROR_NO_SYSTEM_RESOURCES                       EQU     1450
ERROR_NONPAGED_SYSTEM_RESOURCES                 EQU     1451
ERROR_PAGED_SYSTEM_RESOURCES                    EQU     1452
ERROR_WORKING_SET_QUOTA                         EQU     1453
ERROR_PAGEFILE_QUOTA                            EQU     1454
ERROR_COMMITMENT_LIMIT                          EQU     1455
ERROR_MENU_ITEM_NOT_FOUND                       EQU     1456
ERROR_INVALID_KEYBOARD_HANDLE                   EQU     1457
ERROR_HOOK_TYPE_NOT_ALLOWED                     EQU     1458
ERROR_REQUIRES_INTERACTIVE_WINDOWSTATION        EQU     1459
ERROR_TIMEOUT                                   EQU     1460
ERROR_INVALID_MONITOR_HANDLE                    EQU     1461
ERROR_INCORRECT_SIZE                            EQU     1462
ERROR_SYMLINK_CLASS_DISABLED                    EQU     1463
ERROR_SYMLINK_NOT_SUPPORTED                     EQU     1464
ERROR_XML_PARSE_ERROR                           EQU     1465
ERROR_XMLDSIG_ERROR                             EQU     1466
ERROR_RESTART_APPLICATION                       EQU     1467
ERROR_WRONG_COMPARTMENT                         EQU     1468
ERROR_AUTHIP_FAILURE                            EQU     1469
ERROR_NO_NVRAM_RESOURCES                        EQU     1470
ERROR_EVENTLOG_FILE_CORRUPT                     EQU     1500
ERROR_EVENTLOG_CANT_START                       EQU     1501
ERROR_LOG_FILE_FULL                             EQU     1502
ERROR_EVENTLOG_FILE_CHANGED                     EQU     1503
ERROR_INVALID_TASK_NAME                         EQU     1550
ERROR_INVALID_TASK_INDEX                        EQU     1551
ERROR_THREAD_ALREADY_IN_TASK                    EQU     1552
ERROR_INSTALL_SERVICE_FAILURE                   EQU     1601
ERROR_INSTALL_USEREXIT                          EQU     1602
ERROR_INSTALL_FAILURE                           EQU     1603
ERROR_INSTALL_SUSPEND                           EQU     1604
ERROR_UNKNOWN_PRODUCT                           EQU     1605
ERROR_UNKNOWN_FEATURE                           EQU     1606
ERROR_UNKNOWN_COMPONENT                         EQU     1607
ERROR_UNKNOWN_PROPERTY                          EQU     1608
ERROR_INVALID_HANDLE_STATE                      EQU     1609
ERROR_BAD_CONFIGURATION                         EQU     1610
ERROR_INDEX_ABSENT                              EQU     1611
ERROR_INSTALL_SOURCE_ABSENT                     EQU     1612
ERROR_INSTALL_PACKAGE_VERSION                   EQU     1613
ERROR_PRODUCT_UNINSTALLED                       EQU     1614
ERROR_BAD_QUERY_SYNTAX                          EQU     1615
ERROR_INVALID_FIELD                             EQU     1616
ERROR_DEVICE_REMOVED                            EQU     1617
ERROR_INSTALL_ALREADY_RUNNING                   EQU     1618
ERROR_INSTALL_PACKAGE_OPEN_FAILED               EQU     1619
ERROR_INSTALL_PACKAGE_INVALID                   EQU     1620
ERROR_INSTALL_UI_FAILURE                        EQU     1621
ERROR_INSTALL_LOG_FAILURE                       EQU     1622
ERROR_INSTALL_LANGUAGE_UNSUPPORTED              EQU     1623
ERROR_INSTALL_TRANSFORM_FAILURE                 EQU     1624
ERROR_INSTALL_PACKAGE_REJECTED                  EQU     1625
ERROR_FUNCTION_NOT_CALLED                       EQU     1626
ERROR_FUNCTION_FAILED                           EQU     1627
ERROR_INVALID_TABLE                             EQU     1628
ERROR_DATATYPE_MISMATCH                         EQU     1629
ERROR_UNSUPPORTED_TYPE                          EQU     1630
ERROR_CREATE_FAILED                             EQU     1631
ERROR_INSTALL_TEMP_UNWRITABLE                   EQU     1632
ERROR_INSTALL_PLATFORM_UNSUPPORTED              EQU     1633
ERROR_INSTALL_NOTUSED                           EQU     1634
ERROR_PATCH_PACKAGE_OPEN_FAILED                 EQU     1635
ERROR_PATCH_PACKAGE_INVALID                     EQU     1636
ERROR_PATCH_PACKAGE_UNSUPPORTED                 EQU     1637
ERROR_PRODUCT_VERSION                           EQU     1638
ERROR_INVALID_COMMAND_LINE                      EQU     1639
ERROR_INSTALL_REMOTE_DISALLOWED                 EQU     1640
ERROR_SUCCESS_REBOOT_INITIATED                  EQU     1641
ERROR_PATCH_TARGET_NOT_FOUND                    EQU     1642
ERROR_PATCH_PACKAGE_REJECTED                    EQU     1643
ERROR_INSTALL_TRANSFORM_REJECTED                EQU     1644
ERROR_INSTALL_REMOTE_PROHIBITED                 EQU     1645
ERROR_PATCH_REMOVAL_UNSUPPORTED                 EQU     1646
ERROR_UNKNOWN_PATCH                             EQU     1647
ERROR_PATCH_NO_SEQUENCE                         EQU     1648
ERROR_PATCH_REMOVAL_DISALLOWED                  EQU     1649
ERROR_INVALID_PATCH_XML                         EQU     1650
ERROR_PATCH_MANAGED_ADVERTISED_PRODUCT          EQU     1651
ERROR_INSTALL_SERVICE_SAFEBOOT                  EQU     1652
ERROR_FAIL_FAST_EXCEPTION                       EQU     1653
RPC_S_INVALID_STRING_BINDING                    EQU     1700
RPC_S_WRONG_KIND_OF_BINDING                     EQU     1701
RPC_S_INVALID_BINDING                           EQU     1702
RPC_S_PROTSEQ_NOT_SUPPORTED                     EQU     1703
RPC_S_INVALID_RPC_PROTSEQ                       EQU     1704
RPC_S_INVALID_STRING_UUID                       EQU     1705
RPC_S_INVALID_ENDPOINT_FORMAT                   EQU     1706
RPC_S_INVALID_NET_ADDR                          EQU     1707
RPC_S_NO_ENDPOINT_FOUND                         EQU     1708
RPC_S_INVALID_TIMEOUT                           EQU     1709
RPC_S_OBJECT_NOT_FOUND                          EQU     1710
RPC_S_ALREADY_REGISTERED                        EQU     1711
RPC_S_TYPE_ALREADY_REGISTERED                   EQU     1712
RPC_S_ALREADY_LISTENING                         EQU     1713
RPC_S_NO_PROTSEQS_REGISTERED                    EQU     1714
RPC_S_NOT_LISTENING                             EQU     1715
RPC_S_UNKNOWN_MGR_TYPE                          EQU     1716
RPC_S_UNKNOWN_IF                                EQU     1717
RPC_S_NO_BINDINGS                               EQU     1718
RPC_S_NO_PROTSEQS                               EQU     1719
RPC_S_CANT_CREATE_ENDPOINT                      EQU     1720
RPC_S_OUT_OF_RESOURCES                          EQU     1721
RPC_S_SERVER_UNAVAILABLE                        EQU     1722
RPC_S_SERVER_TOO_BUSY                           EQU     1723
RPC_S_INVALID_NETWORK_OPTIONS                   EQU     1724
RPC_S_NO_CALL_ACTIVE                            EQU     1725
RPC_S_CALL_FAILED                               EQU     1726
RPC_S_CALL_FAILED_DNE                           EQU     1727
RPC_S_PROTOCOL_ERROR                            EQU     1728
RPC_S_PROXY_ACCESS_DENIED                       EQU     1729
RPC_S_UNSUPPORTED_TRANS_SYN                     EQU     1730
RPC_S_UNSUPPORTED_TYPE                          EQU     1732
RPC_S_INVALID_TAG                               EQU     1733
RPC_S_INVALID_BOUND                             EQU     1734
RPC_S_NO_ENTRY_NAME                             EQU     1735
RPC_S_INVALID_NAME_SYNTAX                       EQU     1736
RPC_S_UNSUPPORTED_NAME_SYNTAX                   EQU     1737
RPC_S_UUID_NO_ADDRESS                           EQU     1739
RPC_S_DUPLICATE_ENDPOINT                        EQU     1740
RPC_S_UNKNOWN_AUTHN_TYPE                        EQU     1741
RPC_S_MAX_CALLS_TOO_SMALL                       EQU     1742
RPC_S_STRING_TOO_LONG                           EQU     1743
RPC_S_PROTSEQ_NOT_FOUND                         EQU     1744
RPC_S_PROCNUM_OUT_OF_RANGE                      EQU     1745
RPC_S_BINDING_HAS_NO_AUTH                       EQU     1746
RPC_S_UNKNOWN_AUTHN_SERVICE                     EQU     1747
RPC_S_UNKNOWN_AUTHN_LEVEL                       EQU     1748
RPC_S_INVALID_AUTH_IDENTITY                     EQU     1749
RPC_S_UNKNOWN_AUTHZ_SERVICE                     EQU     1750
EPT_S_INVALID_ENTRY                             EQU     1751
EPT_S_CANT_PERFORM_OP                           EQU     1752
EPT_S_NOT_REGISTERED                            EQU     1753
RPC_S_NOTHING_TO_EXPORT                         EQU     1754
RPC_S_INCOMPLETE_NAME                           EQU     1755
RPC_S_INVALID_VERS_OPTION                       EQU     1756
RPC_S_NO_MORE_MEMBERS                           EQU     1757
RPC_S_NOT_ALL_OBJS_UNEXPORTED                   EQU     1758
RPC_S_INTERFACE_NOT_FOUND                       EQU     1759
RPC_S_ENTRY_ALREADY_EXISTS                      EQU     1760
RPC_S_ENTRY_NOT_FOUND                           EQU     1761
RPC_S_NAME_SERVICE_UNAVAILABLE                  EQU     1762
RPC_S_INVALID_NAF_ID                            EQU     1763
RPC_S_CANNOT_SUPPORT                            EQU     1764
RPC_S_NO_CONTEXT_AVAILABLE                      EQU     1765
RPC_S_INTERNAL_ERROR                            EQU     1766
RPC_S_ZERO_DIVIDE                               EQU     1767
RPC_S_ADDRESS_ERROR                             EQU     1768
RPC_S_FP_DIV_ZERO                               EQU     1769
RPC_S_FP_UNDERFLOW                              EQU     1770
RPC_S_FP_OVERFLOW                               EQU     1771
RPC_X_NO_MORE_ENTRIES                           EQU     1772
RPC_X_SS_CHAR_TRANS_OPEN_FAIL                   EQU     1773
RPC_X_SS_CHAR_TRANS_SHORT_FILE                  EQU     1774
RPC_X_SS_IN_NULL_CONTEXT                        EQU     1775
RPC_X_SS_CONTEXT_DAMAGED                        EQU     1777
RPC_X_SS_HANDLES_MISMATCH                       EQU     1778
RPC_X_SS_CANNOT_GET_CALL_HANDLE                 EQU     1779
RPC_X_NULL_REF_POINTER                          EQU     1780
RPC_X_ENUM_VALUE_OUT_OF_RANGE                   EQU     1781
RPC_X_BYTE_COUNT_TOO_SMALL                      EQU     1782
RPC_X_BAD_STUB_DATA                             EQU     1783
ERROR_INVALID_USER_BUFFER                       EQU     1784
ERROR_UNRECOGNIZED_MEDIA                        EQU     1785
ERROR_NO_TRUST_LSA_SECRET                       EQU     1786
ERROR_NO_TRUST_SAM_ACCOUNT                      EQU     1787
ERROR_TRUSTED_DOMAIN_FAILURE                    EQU     1788
ERROR_TRUSTED_RELATIONSHIP_FAILURE              EQU     1789
ERROR_TRUST_FAILURE                             EQU     1790
RPC_S_CALL_IN_PROGRESS                          EQU     1791
ERROR_NETLOGON_NOT_STARTED                      EQU     1792
ERROR_ACCOUNT_EXPIRED                           EQU     1793
ERROR_REDIRECTOR_HAS_OPEN_HANDLES               EQU     1794
ERROR_PRINTER_DRIVER_ALREADY_INSTALLED          EQU     1795
ERROR_UNKNOWN_PORT                              EQU     1796
ERROR_UNKNOWN_PRINTER_DRIVER                    EQU     1797
ERROR_UNKNOWN_PRINTPROCESSOR                    EQU     1798
ERROR_INVALID_SEPARATOR_FILE                    EQU     1799
ERROR_INVALID_PRIORITY                          EQU     1800
ERROR_INVALID_PRINTER_NAME                      EQU     1801
ERROR_PRINTER_ALREADY_EXISTS                    EQU     1802
ERROR_INVALID_PRINTER_COMMAND                   EQU     1803
ERROR_INVALID_DATATYPE                          EQU     1804
ERROR_INVALID_ENVIRONMENT                       EQU     1805
RPC_S_NO_MORE_BINDINGS                          EQU     1806
ERROR_NOLOGON_INTERDOMAIN_TRUST_ACCOUNT         EQU     1807
ERROR_NOLOGON_WORKSTATION_TRUST_ACCOUNT         EQU     1808
ERROR_NOLOGON_SERVER_TRUST_ACCOUNT              EQU     1809
ERROR_DOMAIN_TRUST_INCONSISTENT                 EQU     1810
ERROR_SERVER_HAS_OPEN_HANDLES                   EQU     1811
ERROR_RESOURCE_DATA_NOT_FOUND                   EQU     1812
ERROR_RESOURCE_TYPE_NOT_FOUND                   EQU     1813
ERROR_RESOURCE_NAME_NOT_FOUND                   EQU     1814
ERROR_RESOURCE_LANG_NOT_FOUND                   EQU     1815
ERROR_NOT_ENOUGH_QUOTA                          EQU     1816
RPC_S_NO_INTERFACES                             EQU     1817
RPC_S_CALL_CANCELLED                            EQU     1818
RPC_S_BINDING_INCOMPLETE                        EQU     1819
RPC_S_COMM_FAILURE                              EQU     1820
RPC_S_UNSUPPORTED_AUTHN_LEVEL                   EQU     1821
RPC_S_NO_PRINC_NAME                             EQU     1822
RPC_S_NOT_RPC_ERROR                             EQU     1823
RPC_S_UUID_LOCAL_ONLY                           EQU     1824
RPC_S_SEC_PKG_ERROR                             EQU     1825
RPC_S_NOT_CANCELLED                             EQU     1826
RPC_X_INVALID_ES_ACTION                         EQU     1827
RPC_X_WRONG_ES_VERSION                          EQU     1828
RPC_X_WRONG_STUB_VERSION                        EQU     1829
RPC_X_INVALID_PIPE_OBJECT                       EQU     1830
RPC_X_WRONG_PIPE_ORDER                          EQU     1831
RPC_X_WRONG_PIPE_VERSION                        EQU     1832
RPC_S_COOKIE_AUTH_FAILED                        EQU     1833
RPC_S_GROUP_MEMBER_NOT_FOUND                    EQU     1898
EPT_S_CANT_CREATE                               EQU     1899
RPC_S_INVALID_OBJECT                            EQU     1900
ERROR_INVALID_TIME                              EQU     1901
ERROR_INVALID_FORM_NAME                         EQU     1902
ERROR_INVALID_FORM_SIZE                         EQU     1903
ERROR_ALREADY_WAITING                           EQU     1904
ERROR_PRINTER_DELETED                           EQU     1905
ERROR_INVALID_PRINTER_STATE                     EQU     1906
ERROR_PASSWORD_MUST_CHANGE                      EQU     1907
ERROR_DOMAIN_CONTROLLER_NOT_FOUND               EQU     1908
ERROR_ACCOUNT_LOCKED_OUT                        EQU     1909
OR_INVALID_OXID                                 EQU     1910
OR_INVALID_OID                                  EQU     1911
OR_INVALID_SET                                  EQU     1912
RPC_S_SEND_INCOMPLETE                           EQU     1913
RPC_S_INVALID_ASYNC_HANDLE                      EQU     1914
RPC_S_INVALID_ASYNC_CALL                        EQU     1915
RPC_X_PIPE_CLOSED                               EQU     1916
RPC_X_PIPE_DISCIPLINE_ERROR                     EQU     1917
RPC_X_PIPE_EMPTY                                EQU     1918
ERROR_NO_SITENAME                               EQU     1919
ERROR_CANT_ACCESS_FILE                          EQU     1920
ERROR_CANT_RESOLVE_FILENAME                     EQU     1921
RPC_S_ENTRY_TYPE_MISMATCH                       EQU     1922
RPC_S_NOT_ALL_OBJS_EXPORTED                     EQU     1923
RPC_S_INTERFACE_NOT_EXPORTED                    EQU     1924
RPC_S_PROFILE_NOT_ADDED                         EQU     1925
RPC_S_PRF_ELT_NOT_ADDED                         EQU     1926
RPC_S_PRF_ELT_NOT_REMOVED                       EQU     1927
RPC_S_GRP_ELT_NOT_ADDED                         EQU     1928
RPC_S_GRP_ELT_NOT_REMOVED                       EQU     1929
ERROR_KM_DRIVER_BLOCKED                         EQU     1930
ERROR_CONTEXT_EXPIRED                           EQU     1931
ERROR_PER_USER_TRUST_QUOTA_EXCEEDED             EQU     1932
ERROR_ALL_USER_TRUST_QUOTA_EXCEEDED             EQU     1933
ERROR_USER_DELETE_TRUST_QUOTA_EXCEEDED          EQU     1934
ERROR_AUTHENTICATION_FIREWALL_FAILED            EQU     1935
ERROR_REMOTE_PRINT_CONNECTIONS_BLOCKED          EQU     1936
ERROR_NTLM_BLOCKED                              EQU     1937
ERROR_INVALID_PIXEL_FORMAT                      EQU     2000
ERROR_BAD_DRIVER                                EQU     2001
ERROR_INVALID_WINDOW_STYLE                      EQU     2002
ERROR_METAFILE_NOT_SUPPORTED                    EQU     2003
ERROR_TRANSFORM_NOT_SUPPORTED                   EQU     2004
ERROR_CLIPPING_NOT_SUPPORTED                    EQU     2005
ERROR_INVALID_CMM                               EQU     2010
ERROR_INVALID_PROFILE                           EQU     2011
ERROR_TAG_NOT_FOUND                             EQU     2012
ERROR_TAG_NOT_PRESENT                           EQU     2013
ERROR_DUPLICATE_TAG                             EQU     2014
ERROR_PROFILE_NOT_ASSOCIATED_WITH_DEVICE        EQU     2015
ERROR_PROFILE_NOT_FOUND                         EQU     2016
ERROR_INVALID_COLORSPACE                        EQU     2017
ERROR_ICM_NOT_ENABLED                           EQU     2018
ERROR_DELETING_ICM_XFORM                        EQU     2019
ERROR_INVALID_TRANSFORM                         EQU     2020
ERROR_COLORSPACE_MISMATCH                       EQU     2021
ERROR_INVALID_COLORINDEX                        EQU     2022
ERROR_PROFILE_DOES_NOT_MATCH_DEVICE             EQU     2023
ERROR_CONNECTED_OTHER_PASSWORD                  EQU     2108
ERROR_CONNECTED_OTHER_PASSWORD_DEFAULT          EQU     2109
ERROR_BAD_USERNAME                              EQU     2202
ERROR_NOT_CONNECTED                             EQU     2250
ERROR_OPEN_FILES                                EQU     2401
ERROR_ACTIVE_CONNECTIONS                        EQU     2402
ERROR_DEVICE_IN_USE                             EQU     2404
ERROR_UNKNOWN_PRINT_MONITOR                     EQU     3000
ERROR_PRINTER_DRIVER_IN_USE                     EQU     3001
ERROR_SPOOL_FILE_NOT_FOUND                      EQU     3002
ERROR_SPL_NO_STARTDOC                           EQU     3003
ERROR_SPL_NO_ADDJOB                             EQU     3004
ERROR_PRINT_PROCESSOR_ALREADY_INSTALLED         EQU     3005
ERROR_PRINT_MONITOR_ALREADY_INSTALLED           EQU     3006
ERROR_INVALID_PRINT_MONITOR                     EQU     3007
ERROR_PRINT_MONITOR_IN_USE                      EQU     3008
ERROR_PRINTER_HAS_JOBS_QUEUED                   EQU     3009
ERROR_SUCCESS_REBOOT_REQUIRED                   EQU     3010
ERROR_SUCCESS_RESTART_REQUIRED                  EQU     3011
ERROR_PRINTER_NOT_FOUND                         EQU     3012
ERROR_PRINTER_DRIVER_WARNED                     EQU     3013
ERROR_PRINTER_DRIVER_BLOCKED                    EQU     3014
ERROR_PRINTER_DRIVER_PACKAGE_IN_USE             EQU     3015
ERROR_CORE_DRIVER_PACKAGE_NOT_FOUND             EQU     3016
ERROR_FAIL_REBOOT_REQUIRED                      EQU     3017
ERROR_FAIL_REBOOT_INITIATED                     EQU     3018
ERROR_PRINTER_DRIVER_DOWNLOAD_NEEDED            EQU     3019
ERROR_PRINT_JOB_RESTART_REQUIRED                EQU     3020
ERROR_IO_REISSUE_AS_CACHED                      EQU     3950
ERROR_WINS_INTERNAL                             EQU     4000
ERROR_CAN_NOT_DEL_LOCAL_WINS                    EQU     4001
ERROR_STATIC_INIT                               EQU     4002
ERROR_INC_BACKUP                                EQU     4003
ERROR_FULL_BACKUP                               EQU     4004
ERROR_REC_NON_EXISTENT                          EQU     4005
ERROR_RPL_NOT_ALLOWED                           EQU     4006
PEERDIST_ERROR_CONTENTINFO_VERSION_UNSUPPORTED  EQU     4050
PEERDIST_ERROR_CANNOT_PARSE_CONTENTINFO         EQU     4051
PEERDIST_ERROR_MISSING_DATA                     EQU     4052
PEERDIST_ERROR_NO_MORE                          EQU     4053
PEERDIST_ERROR_NOT_INITIALIZED                  EQU     4054
PEERDIST_ERROR_ALREADY_INITIALIZED              EQU     4055
PEERDIST_ERROR_SHUTDOWN_IN_PROGRESS             EQU     4056
PEERDIST_ERROR_INVALIDATED                      EQU     4057
PEERDIST_ERROR_ALREADY_EXISTS                   EQU     4058
PEERDIST_ERROR_OPERATION_NOTFOUND               EQU     4059
PEERDIST_ERROR_ALREADY_COMPLETED                EQU     4060
PEERDIST_ERROR_OUT_OF_BOUNDS                    EQU     4061
PEERDIST_ERROR_VERSION_UNSUPPORTED              EQU     4062
PEERDIST_ERROR_INVALID_CONFIGURATION            EQU     4063
PEERDIST_ERROR_NOT_LICENSED                     EQU     4064
PEERDIST_ERROR_SERVICE_UNAVAILABLE              EQU     4065
ERROR_DHCP_ADDRESS_CONFLICT                     EQU     4100
ERROR_WMI_GUID_NOT_FOUND                        EQU     4200
ERROR_WMI_INSTANCE_NOT_FOUND                    EQU     4201
ERROR_WMI_ITEMID_NOT_FOUND                      EQU     4202
ERROR_WMI_TRY_AGAIN                             EQU     4203
ERROR_WMI_DP_NOT_FOUND                          EQU     4204
ERROR_WMI_UNRESOLVED_INSTANCE_REF               EQU     4205
ERROR_WMI_ALREADY_ENABLED                       EQU     4206
ERROR_WMI_GUID_DISCONNECTED                     EQU     4207
ERROR_WMI_SERVER_UNAVAILABLE                    EQU     4208
ERROR_WMI_DP_FAILED                             EQU     4209
ERROR_WMI_INVALID_MOF                           EQU     4210
ERROR_WMI_INVALID_REGINFO                       EQU     4211
ERROR_WMI_ALREADY_DISABLED                      EQU     4212
ERROR_WMI_READ_ONLY                             EQU     4213
ERROR_WMI_SET_FAILURE                           EQU     4214
ERROR_INVALID_MEDIA                             EQU     4300
ERROR_INVALID_LIBRARY                           EQU     4301
ERROR_INVALID_MEDIA_POOL                        EQU     4302
ERROR_DRIVE_MEDIA_MISMATCH                      EQU     4303
ERROR_MEDIA_OFFLINE                             EQU     4304
ERROR_LIBRARY_OFFLINE                           EQU     4305
ERROR_EMPTY                                     EQU     4306
ERROR_NOT_EMPTY                                 EQU     4307
ERROR_MEDIA_UNAVAILABLE                         EQU     4308
ERROR_RESOURCE_DISABLED                         EQU     4309
ERROR_INVALID_CLEANER                           EQU     4310
ERROR_UNABLE_TO_CLEAN                           EQU     4311
ERROR_OBJECT_NOT_FOUND                          EQU     4312
ERROR_DATABASE_FAILURE                          EQU     4313
ERROR_DATABASE_FULL                             EQU     4314
ERROR_MEDIA_INCOMPATIBLE                        EQU     4315
ERROR_RESOURCE_NOT_PRESENT                      EQU     4316
ERROR_INVALID_OPERATION                         EQU     4317
ERROR_MEDIA_NOT_AVAILABLE                       EQU     4318
ERROR_DEVICE_NOT_AVAILABLE                      EQU     4319
ERROR_REQUEST_REFUSED                           EQU     4320
ERROR_INVALID_DRIVE_OBJECT                      EQU     4321
ERROR_LIBRARY_FULL                              EQU     4322
ERROR_MEDIUM_NOT_ACCESSIBLE                     EQU     4323
ERROR_UNABLE_TO_LOAD_MEDIUM                     EQU     4324
ERROR_UNABLE_TO_INVENTORY_DRIVE                 EQU     4325
ERROR_UNABLE_TO_INVENTORY_SLOT                  EQU     4326
ERROR_UNABLE_TO_INVENTORY_TRANSPORT             EQU     4327
ERROR_TRANSPORT_FULL                            EQU     4328
ERROR_CONTROLLING_IEPORT                        EQU     4329
ERROR_UNABLE_TO_EJECT_MOUNTED_MEDIA             EQU     4330
ERROR_CLEANER_SLOT_SET                          EQU     4331
ERROR_CLEANER_SLOT_NOT_SET                      EQU     4332
ERROR_CLEANER_CARTRIDGE_SPENT                   EQU     4333
ERROR_UNEXPECTED_OMID                           EQU     4334
ERROR_CANT_DELETE_LAST_ITEM                     EQU     4335
ERROR_MESSAGE_EXCEEDS_MAX_SIZE                  EQU     4336
ERROR_VOLUME_CONTAINS_SYS_FILES                 EQU     4337
ERROR_INDIGENOUS_TYPE                           EQU     4338
ERROR_NO_SUPPORTING_DRIVES                      EQU     4339
ERROR_CLEANER_CARTRIDGE_INSTALLED               EQU     4340
ERROR_IEPORT_FULL                               EQU     4341
ERROR_FILE_OFFLINE                              EQU     4350
ERROR_REMOTE_STORAGE_NOT_ACTIVE                 EQU     4351
ERROR_REMOTE_STORAGE_MEDIA_ERROR                EQU     4352
ERROR_NOT_A_REPARSE_POINT                       EQU     4390
ERROR_REPARSE_ATTRIBUTE_CONFLICT                EQU     4391
ERROR_INVALID_REPARSE_DATA                      EQU     4392
ERROR_REPARSE_TAG_INVALID                       EQU     4393
ERROR_REPARSE_TAG_MISMATCH                      EQU     4394
ERROR_VOLUME_NOT_SIS_ENABLED                    EQU     4500
ERROR_DEPENDENT_RESOURCE_EXISTS                 EQU     5001
ERROR_DEPENDENCY_NOT_FOUND                      EQU     5002
ERROR_DEPENDENCY_ALREADY_EXISTS                 EQU     5003
ERROR_RESOURCE_NOT_ONLINE                       EQU     5004
ERROR_HOST_NODE_NOT_AVAILABLE                   EQU     5005
ERROR_RESOURCE_NOT_AVAILABLE                    EQU     5006
ERROR_RESOURCE_NOT_FOUND                        EQU     5007
ERROR_SHUTDOWN_CLUSTER                          EQU     5008
ERROR_CANT_EVICT_ACTIVE_NODE                    EQU     5009
ERROR_OBJECT_ALREADY_EXISTS                     EQU     5010
ERROR_OBJECT_IN_LIST                            EQU     5011
ERROR_GROUP_NOT_AVAILABLE                       EQU     5012
ERROR_GROUP_NOT_FOUND                           EQU     5013
ERROR_GROUP_NOT_ONLINE                          EQU     5014
ERROR_HOST_NODE_NOT_RESOURCE_OWNER              EQU     5015
ERROR_HOST_NODE_NOT_GROUP_OWNER                 EQU     5016
ERROR_RESMON_CREATE_FAILED                      EQU     5017
ERROR_RESMON_ONLINE_FAILED                      EQU     5018
ERROR_RESOURCE_ONLINE                           EQU     5019
ERROR_QUORUM_RESOURCE                           EQU     5020
ERROR_NOT_QUORUM_CAPABLE                        EQU     5021
ERROR_CLUSTER_SHUTTING_DOWN                     EQU     5022
ERROR_INVALID_STATE                             EQU     5023
ERROR_RESOURCE_PROPERTIES_STORED                EQU     5024
ERROR_NOT_QUORUM_CLASS                          EQU     5025
ERROR_CORE_RESOURCE                             EQU     5026
ERROR_QUORUM_RESOURCE_ONLINE_FAILED             EQU     5027
ERROR_QUORUMLOG_OPEN_FAILED                     EQU     5028
ERROR_CLUSTERLOG_CORRUPT                        EQU     5029
ERROR_CLUSTERLOG_RECORD_EXCEEDS_MAXSIZE         EQU     5030
ERROR_CLUSTERLOG_EXCEEDS_MAXSIZE                EQU     5031
ERROR_CLUSTERLOG_CHKPOINT_NOT_FOUND             EQU     5032
ERROR_CLUSTERLOG_NOT_ENOUGH_SPACE               EQU     5033
ERROR_QUORUM_OWNER_ALIVE                        EQU     5034
ERROR_NETWORK_NOT_AVAILABLE                     EQU     5035
ERROR_NODE_NOT_AVAILABLE                        EQU     5036
ERROR_ALL_NODES_NOT_AVAILABLE                   EQU     5037
ERROR_RESOURCE_FAILED                           EQU     5038
ERROR_CLUSTER_INVALID_NODE                      EQU     5039
ERROR_CLUSTER_NODE_EXISTS                       EQU     5040
ERROR_CLUSTER_JOIN_IN_PROGRESS                  EQU     5041
ERROR_CLUSTER_NODE_NOT_FOUND                    EQU     5042
ERROR_CLUSTER_LOCAL_NODE_NOT_FOUND              EQU     5043
ERROR_CLUSTER_NETWORK_EXISTS                    EQU     5044
ERROR_CLUSTER_NETWORK_NOT_FOUND                 EQU     5045
ERROR_CLUSTER_NETINTERFACE_EXISTS               EQU     5046
ERROR_CLUSTER_NETINTERFACE_NOT_FOUND            EQU     5047
ERROR_CLUSTER_INVALID_REQUEST                   EQU     5048
ERROR_CLUSTER_INVALID_NETWORK_PROVIDER          EQU     5049
ERROR_CLUSTER_NODE_DOWN                         EQU     5050
ERROR_CLUSTER_NODE_UNREACHABLE                  EQU     5051
ERROR_CLUSTER_NODE_NOT_MEMBER                   EQU     5052
ERROR_CLUSTER_JOIN_NOT_IN_PROGRESS              EQU     5053
ERROR_CLUSTER_INVALID_NETWORK                   EQU     5054
ERROR_CLUSTER_NODE_UP                           EQU     5056
ERROR_CLUSTER_IPADDR_IN_USE                     EQU     5057
ERROR_CLUSTER_NODE_NOT_PAUSED                   EQU     5058
ERROR_CLUSTER_NO_SECURITY_CONTEXT               EQU     5059
ERROR_CLUSTER_NETWORK_NOT_INTERNAL              EQU     5060
ERROR_CLUSTER_NODE_ALREADY_UP                   EQU     5061
ERROR_CLUSTER_NODE_ALREADY_DOWN                 EQU     5062
ERROR_CLUSTER_NETWORK_ALREADY_ONLINE            EQU     5063
ERROR_CLUSTER_NETWORK_ALREADY_OFFLINE           EQU     5064
ERROR_CLUSTER_NODE_ALREADY_MEMBER               EQU     5065
ERROR_CLUSTER_LAST_INTERNAL_NETWORK             EQU     5066
ERROR_CLUSTER_NETWORK_HAS_DEPENDENTS            EQU     5067
ERROR_INVALID_OPERATION_ON_QUORUM               EQU     5068
ERROR_DEPENDENCY_NOT_ALLOWED                    EQU     5069
ERROR_CLUSTER_NODE_PAUSED                       EQU     5070
ERROR_NODE_CANT_HOST_RESOURCE                   EQU     5071
ERROR_CLUSTER_NODE_NOT_READY                    EQU     5072
ERROR_CLUSTER_NODE_SHUTTING_DOWN                EQU     5073
ERROR_CLUSTER_JOIN_ABORTED                      EQU     5074
ERROR_CLUSTER_INCOMPATIBLE_VERSIONS             EQU     5075
ERROR_CLUSTER_MAXNUM_OF_RESOURCES_EXCEEDED      EQU     5076
ERROR_CLUSTER_SYSTEM_CONFIG_CHANGED             EQU     5077
ERROR_CLUSTER_RESOURCE_TYPE_NOT_FOUND           EQU     5078
ERROR_CLUSTER_RESTYPE_NOT_SUPPORTED             EQU     5079
ERROR_CLUSTER_RESNAME_NOT_FOUND                 EQU     5080
ERROR_CLUSTER_NO_RPC_PACKAGES_REGISTERED        EQU     5081
ERROR_CLUSTER_OWNER_NOT_IN_PREFLIST             EQU     5082
ERROR_CLUSTER_DATABASE_SEQMISMATCH              EQU     5083
ERROR_RESMON_INVALID_STATE                      EQU     5084
ERROR_CLUSTER_GUM_NOT_LOCKER                    EQU     5085
ERROR_QUORUM_DISK_NOT_FOUND                     EQU     5086
ERROR_DATABASE_BACKUP_CORRUPT                   EQU     5087
ERROR_CLUSTER_NODE_ALREADY_HAS_DFS_ROOT         EQU     5088
ERROR_RESOURCE_PROPERTY_UNCHANGEABLE            EQU     5089
ERROR_CLUSTER_MEMBERSHIP_INVALID_STATE          EQU     5890
ERROR_CLUSTER_QUORUMLOG_NOT_FOUND               EQU     5891
ERROR_CLUSTER_MEMBERSHIP_HALT                   EQU     5892
ERROR_CLUSTER_INSTANCE_ID_MISMATCH              EQU     5893
ERROR_CLUSTER_NETWORK_NOT_FOUND_FOR_IP          EQU     5894
ERROR_CLUSTER_PROPERTY_DATA_TYPE_MISMATCH       EQU     5895
ERROR_CLUSTER_EVICT_WITHOUT_CLEANUP             EQU     5896
ERROR_CLUSTER_PARAMETER_MISMATCH                EQU     5897
ERROR_NODE_CANNOT_BE_CLUSTERED                  EQU     5898
ERROR_CLUSTER_WRONG_OS_VERSION                  EQU     5899
ERROR_CLUSTER_CANT_CREATE_DUP_CLUSTER_NAME      EQU     5900
ERROR_CLUSCFG_ALREADY_COMMITTED                 EQU     5901
ERROR_CLUSCFG_ROLLBACK_FAILED                   EQU     5902
ERROR_CLUSCFG_SYSTEM_DISK_DRIVE_LETTER_CONFLICT EQU     5903
ERROR_CLUSTER_OLD_VERSION                       EQU     5904
ERROR_CLUSTER_MISMATCHED_COMPUTER_ACCT_NAME     EQU     5905
ERROR_CLUSTER_NO_NET_ADAPTERS                   EQU     5906
ERROR_CLUSTER_POISONED                          EQU     5907
ERROR_CLUSTER_GROUP_MOVING                      EQU     5908
ERROR_CLUSTER_RESOURCE_TYPE_BUSY                EQU     5909
ERROR_RESOURCE_CALL_TIMED_OUT                   EQU     5910
ERROR_INVALID_CLUSTER_IPV6_ADDRESS              EQU     5911
ERROR_CLUSTER_INTERNAL_INVALID_FUNCTION         EQU     5912
ERROR_CLUSTER_PARAMETER_OUT_OF_BOUNDS           EQU     5913
ERROR_CLUSTER_PARTIAL_SEND                      EQU     5914
ERROR_CLUSTER_REGISTRY_INVALID_FUNCTION         EQU     5915
ERROR_CLUSTER_INVALID_STRING_TERMINATION        EQU     5916
ERROR_CLUSTER_INVALID_STRING_FORMAT             EQU     5917
ERROR_CLUSTER_DATABASE_TRANSACTION_IN_PROGRESS  EQU     5918
ERROR_CLUSTER_DATABASE_TRANSACTION_NOT_IN_PROGRESS EQU  5919
ERROR_CLUSTER_NULL_DATA                         EQU     5920
ERROR_CLUSTER_PARTIAL_READ                      EQU     5921
ERROR_CLUSTER_PARTIAL_WRITE                     EQU     5922
ERROR_CLUSTER_CANT_DESERIALIZE_DATA             EQU     5923
ERROR_DEPENDENT_RESOURCE_PROPERTY_CONFLICT      EQU     5924
ERROR_CLUSTER_NO_QUORUM                         EQU     5925
ERROR_CLUSTER_INVALID_IPV6_NETWORK              EQU     5926
ERROR_CLUSTER_INVALID_IPV6_TUNNEL_NETWORK       EQU     5927
ERROR_QUORUM_NOT_ALLOWED_IN_THIS_GROUP          EQU     5928
ERROR_DEPENDENCY_TREE_TOO_COMPLEX               EQU     5929
ERROR_EXCEPTION_IN_RESOURCE_CALL                EQU     5930
ERROR_CLUSTER_RHS_FAILED_INITIALIZATION         EQU     5931
ERROR_CLUSTER_NOT_INSTALLED                     EQU     5932
ERROR_CLUSTER_RESOURCES_MUST_BE_ONLINE_ON_THE_SAME_NODE EQU 5933
ERROR_CLUSTER_MAX_NODES_IN_CLUSTER              EQU     5934
ERROR_CLUSTER_TOO_MANY_NODES                    EQU     5935
ERROR_CLUSTER_OBJECT_ALREADY_USED               EQU     5936
ERROR_NONCORE_GROUPS_FOUND                      EQU     5937
ERROR_FILE_SHARE_RESOURCE_CONFLICT              EQU     5938
ERROR_CLUSTER_EVICT_INVALID_REQUEST             EQU     5939
ERROR_CLUSTER_SINGLETON_RESOURCE                EQU     5940
ERROR_CLUSTER_GROUP_SINGLETON_RESOURCE          EQU     5941
ERROR_CLUSTER_RESOURCE_PROVIDER_FAILED          EQU     5942
ERROR_CLUSTER_RESOURCE_CONFIGURATION_ERROR      EQU     5943
ERROR_CLUSTER_GROUP_BUSY                        EQU     5944
ERROR_CLUSTER_NOT_SHARED_VOLUME                 EQU     5945
ERROR_CLUSTER_INVALID_SECURITY_DESCRIPTOR       EQU     5946
ERROR_CLUSTER_SHARED_VOLUMES_IN_USE             EQU     5947
ERROR_CLUSTER_USE_SHARED_VOLUMES_API            EQU     5948
ERROR_CLUSTER_BACKUP_IN_PROGRESS                EQU     5949
ERROR_NON_CSV_PATH                              EQU     5950
ERROR_CSV_VOLUME_NOT_LOCAL                      EQU     5951
ERROR_CLUSTER_WATCHDOG_TERMINATING              EQU     5952
ERROR_ENCRYPTION_FAILED                         EQU     6000
ERROR_DECRYPTION_FAILED                         EQU     6001
ERROR_FILE_ENCRYPTED                            EQU     6002
ERROR_NO_RECOVERY_POLICY                        EQU     6003
ERROR_NO_EFS                                    EQU     6004
ERROR_WRONG_EFS                                 EQU     6005
ERROR_NO_USER_KEYS                              EQU     6006
ERROR_FILE_NOT_ENCRYPTED                        EQU     6007
ERROR_NOT_EXPORT_FORMAT                         EQU     6008
ERROR_FILE_READ_ONLY                            EQU     6009
ERROR_DIR_EFS_DISALLOWED                        EQU     6010
ERROR_EFS_SERVER_NOT_TRUSTED                    EQU     6011
ERROR_BAD_RECOVERY_POLICY                       EQU     6012
ERROR_EFS_ALG_BLOB_TOO_BIG                      EQU     6013
ERROR_VOLUME_NOT_SUPPORT_EFS                    EQU     6014
ERROR_EFS_DISABLED                              EQU     6015
ERROR_EFS_VERSION_NOT_SUPPORT                   EQU     6016
ERROR_CS_ENCRYPTION_INVALID_SERVER_RESPONSE     EQU     6017
ERROR_CS_ENCRYPTION_UNSUPPORTED_SERVER          EQU     6018
ERROR_CS_ENCRYPTION_EXISTING_ENCRYPTED_FILE     EQU     6019
ERROR_CS_ENCRYPTION_NEW_ENCRYPTED_FILE          EQU     6020
ERROR_CS_ENCRYPTION_FILE_NOT_CSE                EQU     6021
ERROR_ENCRYPTION_POLICY_DENIES_OPERATION        EQU     6022
ERROR_NO_BROWSER_SERVERS_FOUND                  EQU     6118
SCHED_E_SERVICE_NOT_LOCALSYSTEM                 EQU     6200
ERROR_LOG_SECTOR_INVALID                        EQU     6600
ERROR_LOG_SECTOR_PARITY_INVALID                 EQU     6601
ERROR_LOG_SECTOR_REMAPPED                       EQU     6602
ERROR_LOG_BLOCK_INCOMPLETE                      EQU     6603
ERROR_LOG_INVALID_RANGE                         EQU     6604
ERROR_LOG_BLOCKS_EXHAUSTED                      EQU     6605
ERROR_LOG_READ_CONTEXT_INVALID                  EQU     6606
ERROR_LOG_RESTART_INVALID                       EQU     6607
ERROR_LOG_BLOCK_VERSION                         EQU     6608
ERROR_LOG_BLOCK_INVALID                         EQU     6609
ERROR_LOG_READ_MODE_INVALID                     EQU     6610
ERROR_LOG_NO_RESTART                            EQU     6611
ERROR_LOG_METADATA_CORRUPT                      EQU     6612
ERROR_LOG_METADATA_INVALID                      EQU     6613
ERROR_LOG_METADATA_INCONSISTENT                 EQU     6614
ERROR_LOG_RESERVATION_INVALID                   EQU     6615
ERROR_LOG_CANT_DELETE                           EQU     6616
ERROR_LOG_CONTAINER_LIMIT_EXCEEDED              EQU     6617
ERROR_LOG_START_OF_LOG                          EQU     6618
ERROR_LOG_POLICY_ALREADY_INSTALLED              EQU     6619
ERROR_LOG_POLICY_NOT_INSTALLED                  EQU     6620
ERROR_LOG_POLICY_INVALID                        EQU     6621
ERROR_LOG_POLICY_CONFLICT                       EQU     6622
ERROR_LOG_PINNED_ARCHIVE_TAIL                   EQU     6623
ERROR_LOG_RECORD_NONEXISTENT                    EQU     6624
ERROR_LOG_RECORDS_RESERVED_INVALID              EQU     6625
ERROR_LOG_SPACE_RESERVED_INVALID                EQU     6626
ERROR_LOG_TAIL_INVALID                          EQU     6627
ERROR_LOG_FULL                                  EQU     6628
ERROR_COULD_NOT_RESIZE_LOG                      EQU     6629
ERROR_LOG_MULTIPLEXED                           EQU     6630
ERROR_LOG_DEDICATED                             EQU     6631
ERROR_LOG_ARCHIVE_NOT_IN_PROGRESS               EQU     6632
ERROR_LOG_ARCHIVE_IN_PROGRESS                   EQU     6633
ERROR_LOG_EPHEMERAL                             EQU     6634
ERROR_LOG_NOT_ENOUGH_CONTAINERS                 EQU     6635
ERROR_LOG_CLIENT_ALREADY_REGISTERED             EQU     6636
ERROR_LOG_CLIENT_NOT_REGISTERED                 EQU     6637
ERROR_LOG_FULL_HANDLER_IN_PROGRESS              EQU     6638
ERROR_LOG_CONTAINER_READ_FAILED                 EQU     6639
ERROR_LOG_CONTAINER_WRITE_FAILED                EQU     6640
ERROR_LOG_CONTAINER_OPEN_FAILED                 EQU     6641
ERROR_LOG_CONTAINER_STATE_INVALID               EQU     6642
ERROR_LOG_STATE_INVALID                         EQU     6643
ERROR_LOG_PINNED                                EQU     6644
ERROR_LOG_METADATA_FLUSH_FAILED                 EQU     6645
ERROR_LOG_INCONSISTENT_SECURITY                 EQU     6646
ERROR_LOG_APPENDED_FLUSH_FAILED                 EQU     6647
ERROR_LOG_PINNED_RESERVATION                    EQU     6648
ERROR_INVALID_TRANSACTION                       EQU     6700
ERROR_TRANSACTION_NOT_ACTIVE                    EQU     6701
ERROR_TRANSACTION_REQUEST_NOT_VALID             EQU     6702
ERROR_TRANSACTION_NOT_REQUESTED                 EQU     6703
ERROR_TRANSACTION_ALREADY_ABORTED               EQU     6704
ERROR_TRANSACTION_ALREADY_COMMITTED             EQU     6705
ERROR_TM_INITIALIZATION_FAILED                  EQU     6706
ERROR_RESOURCEMANAGER_READ_ONLY                 EQU     6707
ERROR_TRANSACTION_NOT_JOINED                    EQU     6708
ERROR_TRANSACTION_SUPERIOR_EXISTS               EQU     6709
ERROR_CRM_PROTOCOL_ALREADY_EXISTS               EQU     6710
ERROR_TRANSACTION_PROPAGATION_FAILED            EQU     6711
ERROR_CRM_PROTOCOL_NOT_FOUND                    EQU     6712
ERROR_TRANSACTION_INVALID_MARSHALL_BUFFER       EQU     6713
ERROR_CURRENT_TRANSACTION_NOT_VALID             EQU     6714
ERROR_TRANSACTION_NOT_FOUND                     EQU     6715
ERROR_RESOURCEMANAGER_NOT_FOUND                 EQU     6716
ERROR_ENLISTMENT_NOT_FOUND                      EQU     6717
ERROR_TRANSACTIONMANAGER_NOT_FOUND              EQU     6718
ERROR_TRANSACTIONMANAGER_NOT_ONLINE             EQU     6719
ERROR_TRANSACTIONMANAGER_RECOVERY_NAME_COLLISION EQU    6720
ERROR_TRANSACTION_NOT_ROOT                      EQU     6721
ERROR_TRANSACTION_OBJECT_EXPIRED                EQU     6722
ERROR_TRANSACTION_RESPONSE_NOT_ENLISTED         EQU     6723
ERROR_TRANSACTION_RECORD_TOO_LONG               EQU     6724
ERROR_IMPLICIT_TRANSACTION_NOT_SUPPORTED        EQU     6725
ERROR_TRANSACTION_INTEGRITY_VIOLATED            EQU     6726
ERROR_TRANSACTIONMANAGER_IDENTITY_MISMATCH      EQU     6727
ERROR_RM_CANNOT_BE_FROZEN_FOR_SNAPSHOT          EQU     6728
ERROR_TRANSACTION_MUST_WRITETHROUGH             EQU     6729
ERROR_TRANSACTION_NO_SUPERIOR                   EQU     6730
ERROR_HEURISTIC_DAMAGE_POSSIBLE                 EQU     6731
ERROR_TRANSACTIONAL_CONFLICT                    EQU     6800
ERROR_RM_NOT_ACTIVE                             EQU     6801
ERROR_RM_METADATA_CORRUPT                       EQU     6802
ERROR_DIRECTORY_NOT_RM                          EQU     6803
ERROR_TRANSACTIONS_UNSUPPORTED_REMOTE           EQU     6805
ERROR_LOG_RESIZE_INVALID_SIZE                   EQU     6806
ERROR_OBJECT_NO_LONGER_EXISTS                   EQU     6807
ERROR_STREAM_MINIVERSION_NOT_FOUND              EQU     6808
ERROR_STREAM_MINIVERSION_NOT_VALID              EQU     6809
ERROR_MINIVERSION_INACCESSIBLE_FROM_SPECIFIED_TRANSACTION EQU 6810
ERROR_CANT_OPEN_MINIVERSION_WITH_MODIFY_INTENT  EQU     6811
ERROR_CANT_CREATE_MORE_STREAM_MINIVERSIONS      EQU     6812
ERROR_REMOTE_FILE_VERSION_MISMATCH              EQU     6814
ERROR_HANDLE_NO_LONGER_VALID                    EQU     6815
ERROR_NO_TXF_METADATA                           EQU     6816
ERROR_LOG_CORRUPTION_DETECTED                   EQU     6817
ERROR_CANT_RECOVER_WITH_HANDLE_OPEN             EQU     6818
ERROR_RM_DISCONNECTED                           EQU     6819
ERROR_ENLISTMENT_NOT_SUPERIOR                   EQU     6820
ERROR_RECOVERY_NOT_NEEDED                       EQU     6821
ERROR_RM_ALREADY_STARTED                        EQU     6822
ERROR_FILE_IDENTITY_NOT_PERSISTENT              EQU     6823
ERROR_CANT_BREAK_TRANSACTIONAL_DEPENDENCY       EQU     6824
ERROR_CANT_CROSS_RM_BOUNDARY                    EQU     6825
ERROR_TXF_DIR_NOT_EMPTY                         EQU     6826
ERROR_INDOUBT_TRANSACTIONS_EXIST                EQU     6827
ERROR_TM_VOLATILE                               EQU     6828
ERROR_ROLLBACK_TIMER_EXPIRED                    EQU     6829
ERROR_TXF_ATTRIBUTE_CORRUPT                     EQU     6830
ERROR_EFS_NOT_ALLOWED_IN_TRANSACTION            EQU     6831
ERROR_TRANSACTIONAL_OPEN_NOT_ALLOWED            EQU     6832
ERROR_LOG_GROWTH_FAILED                         EQU     6833
ERROR_TRANSACTED_MAPPING_UNSUPPORTED_REMOTE     EQU     6834
ERROR_TXF_METADATA_ALREADY_PRESENT              EQU     6835
ERROR_TRANSACTION_SCOPE_CALLBACKS_NOT_SET       EQU     6836
ERROR_TRANSACTION_REQUIRED_PROMOTION            EQU     6837
ERROR_CANNOT_EXECUTE_FILE_IN_TRANSACTION        EQU     6838
ERROR_TRANSACTIONS_NOT_FROZEN                   EQU     6839
ERROR_TRANSACTION_FREEZE_IN_PROGRESS            EQU     6840
ERROR_NOT_SNAPSHOT_VOLUME                       EQU     6841
ERROR_NO_SAVEPOINT_WITH_OPEN_FILES              EQU     6842
ERROR_DATA_LOST_REPAIR                          EQU     6843
ERROR_SPARSE_NOT_ALLOWED_IN_TRANSACTION         EQU     6844
ERROR_TM_IDENTITY_MISMATCH                      EQU     6845
ERROR_FLOATED_SECTION                           EQU     6846
ERROR_CANNOT_ACCEPT_TRANSACTED_WORK             EQU     6847
ERROR_CANNOT_ABORT_TRANSACTIONS                 EQU     6848
ERROR_BAD_CLUSTERS                              EQU     6849
ERROR_COMPRESSION_NOT_ALLOWED_IN_TRANSACTION    EQU     6850
ERROR_VOLUME_DIRTY                              EQU     6851
ERROR_NO_LINK_TRACKING_IN_TRANSACTION           EQU     6852
ERROR_OPERATION_NOT_SUPPORTED_IN_TRANSACTION    EQU     6853
ERROR_EXPIRED_HANDLE                            EQU     6854
ERROR_TRANSACTION_NOT_ENLISTED                  EQU     6855
ERROR_CTX_WINSTATION_NAME_INVALID               EQU     7001
ERROR_CTX_INVALID_PD                            EQU     7002
ERROR_CTX_PD_NOT_FOUND                          EQU     7003
ERROR_CTX_WD_NOT_FOUND                          EQU     7004
ERROR_CTX_CANNOT_MAKE_EVENTLOG_ENTRY            EQU     7005
ERROR_CTX_SERVICE_NAME_COLLISION                EQU     7006
ERROR_CTX_CLOSE_PENDING                         EQU     7007
ERROR_CTX_NO_OUTBUF                             EQU     7008
ERROR_CTX_MODEM_INF_NOT_FOUND                   EQU     7009
ERROR_CTX_INVALID_MODEMNAME                     EQU     7010
ERROR_CTX_MODEM_RESPONSE_ERROR                  EQU     7011
ERROR_CTX_MODEM_RESPONSE_TIMEOUT                EQU     7012
ERROR_CTX_MODEM_RESPONSE_NO_CARRIER             EQU     7013
ERROR_CTX_MODEM_RESPONSE_NO_DIALTONE            EQU     7014
ERROR_CTX_MODEM_RESPONSE_BUSY                   EQU     7015
ERROR_CTX_MODEM_RESPONSE_VOICE                  EQU     7016
ERROR_CTX_TD_ERROR                              EQU     7017
ERROR_CTX_WINSTATION_NOT_FOUND                  EQU     7022
ERROR_CTX_WINSTATION_ALREADY_EXISTS             EQU     7023
ERROR_CTX_WINSTATION_BUSY                       EQU     7024
ERROR_CTX_BAD_VIDEO_MODE                        EQU     7025
ERROR_CTX_GRAPHICS_INVALID                      EQU     7035
ERROR_CTX_LOGON_DISABLED                        EQU     7037
ERROR_CTX_NOT_CONSOLE                           EQU     7038
ERROR_CTX_CLIENT_QUERY_TIMEOUT                  EQU     7040
ERROR_CTX_CONSOLE_DISCONNECT                    EQU     7041
ERROR_CTX_CONSOLE_CONNECT                       EQU     7042
ERROR_CTX_SHADOW_DENIED                         EQU     7044
ERROR_CTX_WINSTATION_ACCESS_DENIED              EQU     7045
ERROR_CTX_INVALID_WD                            EQU     7049
ERROR_CTX_SHADOW_INVALID                        EQU     7050
ERROR_CTX_SHADOW_DISABLED                       EQU     7051
ERROR_CTX_CLIENT_LICENSE_IN_USE                 EQU     7052
ERROR_CTX_CLIENT_LICENSE_NOT_SET                EQU     7053
ERROR_CTX_LICENSE_NOT_AVAILABLE                 EQU     7054
ERROR_CTX_LICENSE_CLIENT_INVALID                EQU     7055
ERROR_CTX_LICENSE_EXPIRED                       EQU     7056
ERROR_CTX_SHADOW_NOT_RUNNING                    EQU     7057
ERROR_CTX_SHADOW_ENDED_BY_MODE_CHANGE           EQU     7058
ERROR_ACTIVATION_COUNT_EXCEEDED                 EQU     7059
ERROR_CTX_WINSTATIONS_DISABLED                  EQU     7060
ERROR_CTX_ENCRYPTION_LEVEL_REQUIRED             EQU     7061
ERROR_CTX_SESSION_IN_USE                        EQU     7062
ERROR_CTX_NO_FORCE_LOGOFF                       EQU     7063
ERROR_CTX_ACCOUNT_RESTRICTION                   EQU     7064
ERROR_RDP_PROTOCOL_ERROR                        EQU     7065
ERROR_CTX_CDM_CONNECT                           EQU     7066
ERROR_CTX_CDM_DISCONNECT                        EQU     7067
ERROR_CTX_SECURITY_LAYER_ERROR                  EQU     7068
ERROR_TS_INCOMPATIBLE_SESSIONS                  EQU     7069
ERROR_TS_VIDEO_SUBSYSTEM_ERROR                  EQU     7070
FRS_ERR_INVALID_API_SEQUENCE                    EQU     8001
FRS_ERR_STARTING_SERVICE                        EQU     8002
FRS_ERR_STOPPING_SERVICE                        EQU     8003
FRS_ERR_INTERNAL_API                            EQU     8004
FRS_ERR_INTERNAL                                EQU     8005
FRS_ERR_SERVICE_COMM                            EQU     8006
FRS_ERR_INSUFFICIENT_PRIV                       EQU     8007
FRS_ERR_AUTHENTICATION                          EQU     8008
FRS_ERR_PARENT_INSUFFICIENT_PRIV                EQU     8009
FRS_ERR_PARENT_AUTHENTICATION                   EQU     8010
FRS_ERR_CHILD_TO_PARENT_COMM                    EQU     8011
FRS_ERR_PARENT_TO_CHILD_COMM                    EQU     8012
FRS_ERR_SYSVOL_POPULATE                         EQU     8013
FRS_ERR_SYSVOL_POPULATE_TIMEOUT                 EQU     8014
FRS_ERR_SYSVOL_IS_BUSY                          EQU     8015
FRS_ERR_SYSVOL_DEMOTE                           EQU     8016
FRS_ERR_INVALID_SERVICE_PARAMETER               EQU     8017
DS_S_SUCCESS                                    EQU     NO_ERROR
ERROR_DS_NOT_INSTALLED                          EQU     8200
ERROR_DS_MEMBERSHIP_EVALUATED_LOCALLY           EQU     8201
ERROR_DS_NO_ATTRIBUTE_OR_VALUE                  EQU     8202
ERROR_DS_INVALID_ATTRIBUTE_SYNTAX               EQU     8203
ERROR_DS_ATTRIBUTE_TYPE_UNDEFINED               EQU     8204
ERROR_DS_ATTRIBUTE_OR_VALUE_EXISTS              EQU     8205
ERROR_DS_BUSY                                   EQU     8206
ERROR_DS_UNAVAILABLE                            EQU     8207
ERROR_DS_NO_RIDS_ALLOCATED                      EQU     8208
ERROR_DS_NO_MORE_RIDS                           EQU     8209
ERROR_DS_INCORRECT_ROLE_OWNER                   EQU     8210
ERROR_DS_RIDMGR_INIT_ERROR                      EQU     8211
ERROR_DS_OBJ_CLASS_VIOLATION                    EQU     8212
ERROR_DS_CANT_ON_NON_LEAF                       EQU     8213
ERROR_DS_CANT_ON_RDN                            EQU     8214
ERROR_DS_CANT_MOD_OBJ_CLASS                     EQU     8215
ERROR_DS_CROSS_DOM_MOVE_ERROR                   EQU     8216
ERROR_DS_GC_NOT_AVAILABLE                       EQU     8217
ERROR_SHARED_POLICY                             EQU     8218
ERROR_POLICY_OBJECT_NOT_FOUND                   EQU     8219
ERROR_POLICY_ONLY_IN_DS                         EQU     8220
ERROR_PROMOTION_ACTIVE                          EQU     8221
ERROR_NO_PROMOTION_ACTIVE                       EQU     8222
ERROR_DS_OPERATIONS_ERROR                       EQU     8224
ERROR_DS_PROTOCOL_ERROR                         EQU     8225
ERROR_DS_TIMELIMIT_EXCEEDED                     EQU     8226
ERROR_DS_SIZELIMIT_EXCEEDED                     EQU     8227
ERROR_DS_ADMIN_LIMIT_EXCEEDED                   EQU     8228
ERROR_DS_COMPARE_FALSE                          EQU     8229
ERROR_DS_COMPARE_TRUE                           EQU     8230
ERROR_DS_AUTH_METHOD_NOT_SUPPORTED              EQU     8231
ERROR_DS_STRONG_AUTH_REQUIRED                   EQU     8232
ERROR_DS_INAPPROPRIATE_AUTH                     EQU     8233
ERROR_DS_AUTH_UNKNOWN                           EQU     8234
ERROR_DS_REFERRAL                               EQU     8235
ERROR_DS_UNAVAILABLE_CRIT_EXTENSION             EQU     8236
ERROR_DS_CONFIDENTIALITY_REQUIRED               EQU     8237
ERROR_DS_INAPPROPRIATE_MATCHING                 EQU     8238
ERROR_DS_CONSTRAINT_VIOLATION                   EQU     8239
ERROR_DS_NO_SUCH_OBJECT                         EQU     8240
ERROR_DS_ALIAS_PROBLEM                          EQU     8241
ERROR_DS_INVALID_DN_SYNTAX                      EQU     8242
ERROR_DS_IS_LEAF                                EQU     8243
ERROR_DS_ALIAS_DEREF_PROBLEM                    EQU     8244
ERROR_DS_UNWILLING_TO_PERFORM                   EQU     8245
ERROR_DS_LOOP_DETECT                            EQU     8246
ERROR_DS_NAMING_VIOLATION                       EQU     8247
ERROR_DS_OBJECT_RESULTS_TOO_LARGE               EQU     8248
ERROR_DS_AFFECTS_MULTIPLE_DSAS                  EQU     8249
ERROR_DS_SERVER_DOWN                            EQU     8250
ERROR_DS_LOCAL_ERROR                            EQU     8251
ERROR_DS_ENCODING_ERROR                         EQU     8252
ERROR_DS_DECODING_ERROR                         EQU     8253
ERROR_DS_FILTER_UNKNOWN                         EQU     8254
ERROR_DS_PARAM_ERROR                            EQU     8255
ERROR_DS_NOT_SUPPORTED                          EQU     8256
ERROR_DS_NO_RESULTS_RETURNED                    EQU     8257
ERROR_DS_CONTROL_NOT_FOUND                      EQU     8258
ERROR_DS_CLIENT_LOOP                            EQU     8259
ERROR_DS_REFERRAL_LIMIT_EXCEEDED                EQU     8260
ERROR_DS_SORT_CONTROL_MISSING                   EQU     8261
ERROR_DS_OFFSET_RANGE_ERROR                     EQU     8262
ERROR_DS_ROOT_MUST_BE_NC                        EQU     8301
ERROR_DS_ADD_REPLICA_INHIBITED                  EQU     8302
ERROR_DS_ATT_NOT_DEF_IN_SCHEMA                  EQU     8303
ERROR_DS_MAX_OBJ_SIZE_EXCEEDED                  EQU     8304
ERROR_DS_OBJ_STRING_NAME_EXISTS                 EQU     8305
ERROR_DS_NO_RDN_DEFINED_IN_SCHEMA               EQU     8306
ERROR_DS_RDN_DOESNT_MATCH_SCHEMA                EQU     8307
ERROR_DS_NO_REQUESTED_ATTS_FOUND                EQU     8308
ERROR_DS_USER_BUFFER_TO_SMALL                   EQU     8309
ERROR_DS_ATT_IS_NOT_ON_OBJ                      EQU     8310
ERROR_DS_ILLEGAL_MOD_OPERATION                  EQU     8311
ERROR_DS_OBJ_TOO_LARGE                          EQU     8312
ERROR_DS_BAD_INSTANCE_TYPE                      EQU     8313
ERROR_DS_MASTERDSA_REQUIRED                     EQU     8314
ERROR_DS_OBJECT_CLASS_REQUIRED                  EQU     8315
ERROR_DS_MISSING_REQUIRED_ATT                   EQU     8316
ERROR_DS_ATT_NOT_DEF_FOR_CLASS                  EQU     8317
ERROR_DS_ATT_ALREADY_EXISTS                     EQU     8318
ERROR_DS_CANT_ADD_ATT_VALUES                    EQU     8320
ERROR_DS_SINGLE_VALUE_CONSTRAINT                EQU     8321
ERROR_DS_RANGE_CONSTRAINT                       EQU     8322
ERROR_DS_ATT_VAL_ALREADY_EXISTS                 EQU     8323
ERROR_DS_CANT_REM_MISSING_ATT                   EQU     8324
ERROR_DS_CANT_REM_MISSING_ATT_VAL               EQU     8325
ERROR_DS_ROOT_CANT_BE_SUBREF                    EQU     8326
ERROR_DS_NO_CHAINING                            EQU     8327
ERROR_DS_NO_CHAINED_EVAL                        EQU     8328
ERROR_DS_NO_PARENT_OBJECT                       EQU     8329
ERROR_DS_PARENT_IS_AN_ALIAS                     EQU     8330
ERROR_DS_CANT_MIX_MASTER_AND_REPS               EQU     8331
ERROR_DS_CHILDREN_EXIST                         EQU     8332
ERROR_DS_OBJ_NOT_FOUND                          EQU     8333
ERROR_DS_ALIASED_OBJ_MISSING                    EQU     8334
ERROR_DS_BAD_NAME_SYNTAX                        EQU     8335
ERROR_DS_ALIAS_POINTS_TO_ALIAS                  EQU     8336
ERROR_DS_CANT_DEREF_ALIAS                       EQU     8337
ERROR_DS_OUT_OF_SCOPE                           EQU     8338
ERROR_DS_OBJECT_BEING_REMOVED                   EQU     8339
ERROR_DS_CANT_DELETE_DSA_OBJ                    EQU     8340
ERROR_DS_GENERIC_ERROR                          EQU     8341
ERROR_DS_DSA_MUST_BE_INT_MASTER                 EQU     8342
ERROR_DS_CLASS_NOT_DSA                          EQU     8343
ERROR_DS_INSUFF_ACCESS_RIGHTS                   EQU     8344
ERROR_DS_ILLEGAL_SUPERIOR                       EQU     8345
ERROR_DS_ATTRIBUTE_OWNED_BY_SAM                 EQU     8346
ERROR_DS_NAME_TOO_MANY_PARTS                    EQU     8347
ERROR_DS_NAME_TOO_LONG                          EQU     8348
ERROR_DS_NAME_VALUE_TOO_LONG                    EQU     8349
ERROR_DS_NAME_UNPARSEABLE                       EQU     8350
ERROR_DS_NAME_TYPE_UNKNOWN                      EQU     8351
ERROR_DS_NOT_AN_OBJECT                          EQU     8352
ERROR_DS_SEC_DESC_TOO_SHORT                     EQU     8353
ERROR_DS_SEC_DESC_INVALID                       EQU     8354
ERROR_DS_NO_DELETED_NAME                        EQU     8355
ERROR_DS_SUBREF_MUST_HAVE_PARENT                EQU     8356
ERROR_DS_NCNAME_MUST_BE_NC                      EQU     8357
ERROR_DS_CANT_ADD_SYSTEM_ONLY                   EQU     8358
ERROR_DS_CLASS_MUST_BE_CONCRETE                 EQU     8359
ERROR_DS_INVALID_DMD                            EQU     8360
ERROR_DS_OBJ_GUID_EXISTS                        EQU     8361
ERROR_DS_NOT_ON_BACKLINK                        EQU     8362
ERROR_DS_NO_CROSSREF_FOR_NC                     EQU     8363
ERROR_DS_SHUTTING_DOWN                          EQU     8364
ERROR_DS_UNKNOWN_OPERATION                      EQU     8365
ERROR_DS_INVALID_ROLE_OWNER                     EQU     8366
ERROR_DS_COULDNT_CONTACT_FSMO                   EQU     8367
ERROR_DS_CROSS_NC_DN_RENAME                     EQU     8368
ERROR_DS_CANT_MOD_SYSTEM_ONLY                   EQU     8369
ERROR_DS_REPLICATOR_ONLY                        EQU     8370
ERROR_DS_OBJ_CLASS_NOT_DEFINED                  EQU     8371
ERROR_DS_OBJ_CLASS_NOT_SUBCLASS                 EQU     8372
ERROR_DS_NAME_REFERENCE_INVALID                 EQU     8373
ERROR_DS_CROSS_REF_EXISTS                       EQU     8374
ERROR_DS_CANT_DEL_MASTER_CROSSREF               EQU     8375
ERROR_DS_SUBTREE_NOTIFY_NOT_NC_HEAD             EQU     8376
ERROR_DS_NOTIFY_FILTER_TOO_COMPLEX              EQU     8377
ERROR_DS_DUP_RDN                                EQU     8378
ERROR_DS_DUP_OID                                EQU     8379
ERROR_DS_DUP_MAPI_ID                            EQU     8380
ERROR_DS_DUP_SCHEMA_ID_GUID                     EQU     8381
ERROR_DS_DUP_LDAP_DISPLAY_NAME                  EQU     8382
ERROR_DS_SEMANTIC_ATT_TEST                      EQU     8383
ERROR_DS_SYNTAX_MISMATCH                        EQU     8384
ERROR_DS_EXISTS_IN_MUST_HAVE                    EQU     8385
ERROR_DS_EXISTS_IN_MAY_HAVE                     EQU     8386
ERROR_DS_NONEXISTENT_MAY_HAVE                   EQU     8387
ERROR_DS_NONEXISTENT_MUST_HAVE                  EQU     8388
ERROR_DS_AUX_CLS_TEST_FAIL                      EQU     8389
ERROR_DS_NONEXISTENT_POSS_SUP                   EQU     8390
ERROR_DS_SUB_CLS_TEST_FAIL                      EQU     8391
ERROR_DS_BAD_RDN_ATT_ID_SYNTAX                  EQU     8392
ERROR_DS_EXISTS_IN_AUX_CLS                      EQU     8393
ERROR_DS_EXISTS_IN_SUB_CLS                      EQU     8394
ERROR_DS_EXISTS_IN_POSS_SUP                     EQU     8395
ERROR_DS_RECALCSCHEMA_FAILED                    EQU     8396
ERROR_DS_TREE_DELETE_NOT_FINISHED               EQU     8397
ERROR_DS_CANT_DELETE                            EQU     8398
ERROR_DS_ATT_SCHEMA_REQ_ID                      EQU     8399
ERROR_DS_BAD_ATT_SCHEMA_SYNTAX                  EQU     8400
ERROR_DS_CANT_CACHE_ATT                         EQU     8401
ERROR_DS_CANT_CACHE_CLASS                       EQU     8402
ERROR_DS_CANT_REMOVE_ATT_CACHE                  EQU     8403
ERROR_DS_CANT_REMOVE_CLASS_CACHE                EQU     8404
ERROR_DS_CANT_RETRIEVE_DN                       EQU     8405
ERROR_DS_MISSING_SUPREF                         EQU     8406
ERROR_DS_CANT_RETRIEVE_INSTANCE                 EQU     8407
ERROR_DS_CODE_INCONSISTENCY                     EQU     8408
ERROR_DS_DATABASE_ERROR                         EQU     8409
ERROR_DS_GOVERNSID_MISSING                      EQU     8410
ERROR_DS_MISSING_EXPECTED_ATT                   EQU     8411
ERROR_DS_NCNAME_MISSING_CR_REF                  EQU     8412
ERROR_DS_SECURITY_CHECKING_ERROR                EQU     8413
ERROR_DS_SCHEMA_NOT_LOADED                      EQU     8414
ERROR_DS_SCHEMA_ALLOC_FAILED                    EQU     8415
ERROR_DS_ATT_SCHEMA_REQ_SYNTAX                  EQU     8416
ERROR_DS_GCVERIFY_ERROR                         EQU     8417
ERROR_DS_DRA_SCHEMA_MISMATCH                    EQU     8418
ERROR_DS_CANT_FIND_DSA_OBJ                      EQU     8419
ERROR_DS_CANT_FIND_EXPECTED_NC                  EQU     8420
ERROR_DS_CANT_FIND_NC_IN_CACHE                  EQU     8421
ERROR_DS_CANT_RETRIEVE_CHILD                    EQU     8422
ERROR_DS_SECURITY_ILLEGAL_MODIFY                EQU     8423
ERROR_DS_CANT_REPLACE_HIDDEN_REC                EQU     8424
ERROR_DS_BAD_HIERARCHY_FILE                     EQU     8425
ERROR_DS_BUILD_HIERARCHY_TABLE_FAILED           EQU     8426
ERROR_DS_CONFIG_PARAM_MISSING                   EQU     8427
ERROR_DS_COUNTING_AB_INDICES_FAILED             EQU     8428
ERROR_DS_HIERARCHY_TABLE_MALLOC_FAILED          EQU     8429
ERROR_DS_INTERNAL_FAILURE                       EQU     8430
ERROR_DS_UNKNOWN_ERROR                          EQU     8431
ERROR_DS_ROOT_REQUIRES_CLASS_TOP                EQU     8432
ERROR_DS_REFUSING_FSMO_ROLES                    EQU     8433
ERROR_DS_MISSING_FSMO_SETTINGS                  EQU     8434
ERROR_DS_UNABLE_TO_SURRENDER_ROLES              EQU     8435
ERROR_DS_DRA_GENERIC                            EQU     8436
ERROR_DS_DRA_INVALID_PARAMETER                  EQU     8437
ERROR_DS_DRA_BUSY                               EQU     8438
ERROR_DS_DRA_BAD_DN                             EQU     8439
ERROR_DS_DRA_BAD_NC                             EQU     8440
ERROR_DS_DRA_DN_EXISTS                          EQU     8441
ERROR_DS_DRA_INTERNAL_ERROR                     EQU     8442
ERROR_DS_DRA_INCONSISTENT_DIT                   EQU     8443
ERROR_DS_DRA_CONNECTION_FAILED                  EQU     8444
ERROR_DS_DRA_BAD_INSTANCE_TYPE                  EQU     8445
ERROR_DS_DRA_OUT_OF_MEM                         EQU     8446
ERROR_DS_DRA_MAIL_PROBLEM                       EQU     8447
ERROR_DS_DRA_REF_ALREADY_EXISTS                 EQU     8448
ERROR_DS_DRA_REF_NOT_FOUND                      EQU     8449
ERROR_DS_DRA_OBJ_IS_REP_SOURCE                  EQU     8450
ERROR_DS_DRA_DB_ERROR                           EQU     8451
ERROR_DS_DRA_NO_REPLICA                         EQU     8452
ERROR_DS_DRA_ACCESS_DENIED                      EQU     8453
ERROR_DS_DRA_NOT_SUPPORTED                      EQU     8454
ERROR_DS_DRA_RPC_CANCELLED                      EQU     8455
ERROR_DS_DRA_SOURCE_DISABLED                    EQU     8456
ERROR_DS_DRA_SINK_DISABLED                      EQU     8457
ERROR_DS_DRA_NAME_COLLISION                     EQU     8458
ERROR_DS_DRA_SOURCE_REINSTALLED                 EQU     8459
ERROR_DS_DRA_MISSING_PARENT                     EQU     8460
ERROR_DS_DRA_PREEMPTED                          EQU     8461
ERROR_DS_DRA_ABANDON_SYNC                       EQU     8462
ERROR_DS_DRA_SHUTDOWN                           EQU     8463
ERROR_DS_DRA_INCOMPATIBLE_PARTIAL_SET           EQU     8464
ERROR_DS_DRA_SOURCE_IS_PARTIAL_REPLICA          EQU     8465
ERROR_DS_DRA_EXTN_CONNECTION_FAILED             EQU     8466
ERROR_DS_INSTALL_SCHEMA_MISMATCH                EQU     8467
ERROR_DS_DUP_LINK_ID                            EQU     8468
ERROR_DS_NAME_ERROR_RESOLVING                   EQU     8469
ERROR_DS_NAME_ERROR_NOT_FOUND                   EQU     8470
ERROR_DS_NAME_ERROR_NOT_UNIQUE                  EQU     8471
ERROR_DS_NAME_ERROR_NO_MAPPING                  EQU     8472
ERROR_DS_NAME_ERROR_DOMAIN_ONLY                 EQU     8473
ERROR_DS_NAME_ERROR_NO_SYNTACTICAL_MAPPING      EQU     8474
ERROR_DS_CONSTRUCTED_ATT_MOD                    EQU     8475
ERROR_DS_WRONG_OM_OBJ_CLASS                     EQU     8476
ERROR_DS_DRA_REPL_PENDING                       EQU     8477
ERROR_DS_DS_REQUIRED                            EQU     8478
ERROR_DS_INVALID_LDAP_DISPLAY_NAME              EQU     8479
ERROR_DS_NON_BASE_SEARCH                        EQU     8480
ERROR_DS_CANT_RETRIEVE_ATTS                     EQU     8481
ERROR_DS_BACKLINK_WITHOUT_LINK                  EQU     8482
ERROR_DS_EPOCH_MISMATCH                         EQU     8483
ERROR_DS_SRC_NAME_MISMATCH                      EQU     8484
ERROR_DS_SRC_AND_DST_NC_IDENTICAL               EQU     8485
ERROR_DS_DST_NC_MISMATCH                        EQU     8486
ERROR_DS_NOT_AUTHORITIVE_FOR_DST_NC             EQU     8487
ERROR_DS_SRC_GUID_MISMATCH                      EQU     8488
ERROR_DS_CANT_MOVE_DELETED_OBJECT               EQU     8489
ERROR_DS_PDC_OPERATION_IN_PROGRESS              EQU     8490
ERROR_DS_CROSS_DOMAIN_CLEANUP_REQD              EQU     8491
ERROR_DS_ILLEGAL_XDOM_MOVE_OPERATION            EQU     8492
ERROR_DS_CANT_WITH_ACCT_GROUP_MEMBERSHPS        EQU     8493
ERROR_DS_NC_MUST_HAVE_NC_PARENT                 EQU     8494
ERROR_DS_CR_IMPOSSIBLE_TO_VALIDATE              EQU     8495
ERROR_DS_DST_DOMAIN_NOT_NATIVE                  EQU     8496
ERROR_DS_MISSING_INFRASTRUCTURE_CONTAINER       EQU     8497
ERROR_DS_CANT_MOVE_ACCOUNT_GROUP                EQU     8498
ERROR_DS_CANT_MOVE_RESOURCE_GROUP               EQU     8499
ERROR_DS_INVALID_SEARCH_FLAG                    EQU     8500
ERROR_DS_NO_TREE_DELETE_ABOVE_NC                EQU     8501
ERROR_DS_COULDNT_LOCK_TREE_FOR_DELETE           EQU     8502
ERROR_DS_COULDNT_IDENTIFY_OBJECTS_FOR_TREE_DELETE EQU   8503
ERROR_DS_SAM_INIT_FAILURE                       EQU     8504
ERROR_DS_SENSITIVE_GROUP_VIOLATION              EQU     8505
ERROR_DS_CANT_MOD_PRIMARYGROUPID                EQU     8506
ERROR_DS_ILLEGAL_BASE_SCHEMA_MOD                EQU     8507
ERROR_DS_NONSAFE_SCHEMA_CHANGE                  EQU     8508
ERROR_DS_SCHEMA_UPDATE_DISALLOWED               EQU     8509
ERROR_DS_CANT_CREATE_UNDER_SCHEMA               EQU     8510
ERROR_DS_INSTALL_NO_SRC_SCH_VERSION             EQU     8511
ERROR_DS_INSTALL_NO_SCH_VERSION_IN_INIFILE      EQU     8512
ERROR_DS_INVALID_GROUP_TYPE                     EQU     8513
ERROR_DS_NO_NEST_GLOBALGROUP_IN_MIXEDDOMAIN     EQU     8514
ERROR_DS_NO_NEST_LOCALGROUP_IN_MIXEDDOMAIN      EQU     8515
ERROR_DS_GLOBAL_CANT_HAVE_LOCAL_MEMBER          EQU     8516
ERROR_DS_GLOBAL_CANT_HAVE_UNIVERSAL_MEMBER      EQU     8517
ERROR_DS_UNIVERSAL_CANT_HAVE_LOCAL_MEMBER       EQU     8518
ERROR_DS_GLOBAL_CANT_HAVE_CROSSDOMAIN_MEMBER    EQU     8519
ERROR_DS_LOCAL_CANT_HAVE_CROSSDOMAIN_LOCAL_MEMBER EQU   8520
ERROR_DS_HAVE_PRIMARY_MEMBERS                   EQU     8521
ERROR_DS_STRING_SD_CONVERSION_FAILED            EQU     8522
ERROR_DS_NAMING_MASTER_GC                       EQU     8523
ERROR_DS_DNS_LOOKUP_FAILURE                     EQU     8524
ERROR_DS_COULDNT_UPDATE_SPNS                    EQU     8525
ERROR_DS_CANT_RETRIEVE_SD                       EQU     8526
ERROR_DS_KEY_NOT_UNIQUE                         EQU     8527
ERROR_DS_WRONG_LINKED_ATT_SYNTAX                EQU     8528
ERROR_DS_SAM_NEED_BOOTKEY_PASSWORD              EQU     8529
ERROR_DS_SAM_NEED_BOOTKEY_FLOPPY                EQU     8530
ERROR_DS_CANT_START                             EQU     8531
ERROR_DS_INIT_FAILURE                           EQU     8532
ERROR_DS_NO_PKT_PRIVACY_ON_CONNECTION           EQU     8533
ERROR_DS_SOURCE_DOMAIN_IN_FOREST                EQU     8534
ERROR_DS_DESTINATION_DOMAIN_NOT_IN_FOREST       EQU     8535
ERROR_DS_DESTINATION_AUDITING_NOT_ENABLED       EQU     8536
ERROR_DS_CANT_FIND_DC_FOR_SRC_DOMAIN            EQU     8537
ERROR_DS_SRC_OBJ_NOT_GROUP_OR_USER              EQU     8538
ERROR_DS_SRC_SID_EXISTS_IN_FOREST               EQU     8539
ERROR_DS_SRC_AND_DST_OBJECT_CLASS_MISMATCH      EQU     8540
ERROR_SAM_INIT_FAILURE                          EQU     8541
ERROR_DS_DRA_SCHEMA_INFO_SHIP                   EQU     8542
ERROR_DS_DRA_SCHEMA_CONFLICT                    EQU     8543
ERROR_DS_DRA_EARLIER_SCHEMA_CONFLICT            EQU     8544
ERROR_DS_DRA_OBJ_NC_MISMATCH                    EQU     8545
ERROR_DS_NC_STILL_HAS_DSAS                      EQU     8546
ERROR_DS_GC_REQUIRED                            EQU     8547
ERROR_DS_LOCAL_MEMBER_OF_LOCAL_ONLY             EQU     8548
ERROR_DS_NO_FPO_IN_UNIVERSAL_GROUPS             EQU     8549
ERROR_DS_CANT_ADD_TO_GC                         EQU     8550
ERROR_DS_NO_CHECKPOINT_WITH_PDC                 EQU     8551
ERROR_DS_SOURCE_AUDITING_NOT_ENABLED            EQU     8552
ERROR_DS_CANT_CREATE_IN_NONDOMAIN_NC            EQU     8553
ERROR_DS_INVALID_NAME_FOR_SPN                   EQU     8554
ERROR_DS_FILTER_USES_CONTRUCTED_ATTRS           EQU     8555
ERROR_DS_UNICODEPWD_NOT_IN_QUOTES               EQU     8556
ERROR_DS_MACHINE_ACCOUNT_QUOTA_EXCEEDED         EQU     8557
ERROR_DS_MUST_BE_RUN_ON_DST_DC                  EQU     8558
ERROR_DS_SRC_DC_MUST_BE_SP4_OR_GREATER          EQU     8559
ERROR_DS_CANT_TREE_DELETE_CRITICAL_OBJ          EQU     8560
ERROR_DS_INIT_FAILURE_CONSOLE                   EQU     8561
ERROR_DS_SAM_INIT_FAILURE_CONSOLE               EQU     8562
ERROR_DS_FOREST_VERSION_TOO_HIGH                EQU     8563
ERROR_DS_DOMAIN_VERSION_TOO_HIGH                EQU     8564
ERROR_DS_FOREST_VERSION_TOO_LOW                 EQU     8565
ERROR_DS_DOMAIN_VERSION_TOO_LOW                 EQU     8566
ERROR_DS_INCOMPATIBLE_VERSION                   EQU     8567
ERROR_DS_LOW_DSA_VERSION                        EQU     8568
ERROR_DS_NO_BEHAVIOR_VERSION_IN_MIXEDDOMAIN     EQU     8569
ERROR_DS_NOT_SUPPORTED_SORT_ORDER               EQU     8570
ERROR_DS_NAME_NOT_UNIQUE                        EQU     8571
ERROR_DS_MACHINE_ACCOUNT_CREATED_PRENT4         EQU     8572
ERROR_DS_OUT_OF_VERSION_STORE                   EQU     8573
ERROR_DS_INCOMPATIBLE_CONTROLS_USED             EQU     8574
ERROR_DS_NO_REF_DOMAIN                          EQU     8575
ERROR_DS_RESERVED_LINK_ID                       EQU     8576
ERROR_DS_LINK_ID_NOT_AVAILABLE                  EQU     8577
ERROR_DS_AG_CANT_HAVE_UNIVERSAL_MEMBER          EQU     8578
ERROR_DS_MODIFYDN_DISALLOWED_BY_INSTANCE_TYPE   EQU     8579
ERROR_DS_NO_OBJECT_MOVE_IN_SCHEMA_NC            EQU     8580
ERROR_DS_MODIFYDN_DISALLOWED_BY_FLAG            EQU     8581
ERROR_DS_MODIFYDN_WRONG_GRANDPARENT             EQU     8582
ERROR_DS_NAME_ERROR_TRUST_REFERRAL              EQU     8583
ERROR_NOT_SUPPORTED_ON_STANDARD_SERVER          EQU     8584
ERROR_DS_CANT_ACCESS_REMOTE_PART_OF_AD          EQU     8585
ERROR_DS_CR_IMPOSSIBLE_TO_VALIDATE_V2           EQU     8586
ERROR_DS_THREAD_LIMIT_EXCEEDED                  EQU     8587
ERROR_DS_NOT_CLOSEST                            EQU     8588
ERROR_DS_CANT_DERIVE_SPN_WITHOUT_SERVER_REF     EQU     8589
ERROR_DS_SINGLE_USER_MODE_FAILED                EQU     8590
ERROR_DS_NTDSCRIPT_SYNTAX_ERROR                 EQU     8591
ERROR_DS_NTDSCRIPT_PROCESS_ERROR                EQU     8592
ERROR_DS_DIFFERENT_REPL_EPOCHS                  EQU     8593
ERROR_DS_DRS_EXTENSIONS_CHANGED                 EQU     8594
ERROR_DS_REPLICA_SET_CHANGE_NOT_ALLOWED_ON_DISABLED_CR EQU 8595
ERROR_DS_NO_MSDS_INTID                          EQU     8596
ERROR_DS_DUP_MSDS_INTID                         EQU     8597
ERROR_DS_EXISTS_IN_RDNATTID                     EQU     8598
ERROR_DS_AUTHORIZATION_FAILED                   EQU     8599
ERROR_DS_INVALID_SCRIPT                         EQU     8600
ERROR_DS_REMOTE_CROSSREF_OP_FAILED              EQU     8601
ERROR_DS_CROSS_REF_BUSY                         EQU     8602
ERROR_DS_CANT_DERIVE_SPN_FOR_DELETED_DOMAIN     EQU     8603
ERROR_DS_CANT_DEMOTE_WITH_WRITEABLE_NC          EQU     8604
ERROR_DS_DUPLICATE_ID_FOUND                     EQU     8605
ERROR_DS_INSUFFICIENT_ATTR_TO_CREATE_OBJECT     EQU     8606
ERROR_DS_GROUP_CONVERSION_ERROR                 EQU     8607
ERROR_DS_CANT_MOVE_APP_BASIC_GROUP              EQU     8608
ERROR_DS_CANT_MOVE_APP_QUERY_GROUP              EQU     8609
ERROR_DS_ROLE_NOT_VERIFIED                      EQU     8610
ERROR_DS_WKO_CONTAINER_CANNOT_BE_SPECIAL        EQU     8611
ERROR_DS_DOMAIN_RENAME_IN_PROGRESS              EQU     8612
ERROR_DS_EXISTING_AD_CHILD_NC                   EQU     8613
ERROR_DS_REPL_LIFETIME_EXCEEDED                 EQU     8614
ERROR_DS_DISALLOWED_IN_SYSTEM_CONTAINER         EQU     8615
ERROR_DS_LDAP_SEND_QUEUE_FULL                   EQU     8616
ERROR_DS_DRA_OUT_SCHEDULE_WINDOW                EQU     8617
ERROR_DS_POLICY_NOT_KNOWN                       EQU     8618
ERROR_NO_SITE_SETTINGS_OBJECT                   EQU     8619
ERROR_NO_SECRETS                                EQU     8620
ERROR_NO_WRITABLE_DC_FOUND                      EQU     8621
ERROR_DS_NO_SERVER_OBJECT                       EQU     8622
ERROR_DS_NO_NTDSA_OBJECT                        EQU     8623
ERROR_DS_NON_ASQ_SEARCH                         EQU     8624
ERROR_DS_AUDIT_FAILURE                          EQU     8625
ERROR_DS_INVALID_SEARCH_FLAG_SUBTREE            EQU     8626
ERROR_DS_INVALID_SEARCH_FLAG_TUPLE              EQU     8627
ERROR_DS_HIERARCHY_TABLE_TOO_DEEP               EQU     8628
ERROR_DS_DRA_CORRUPT_UTD_VECTOR                 EQU     8629
ERROR_DS_DRA_SECRETS_DENIED                     EQU     8630
ERROR_DS_RESERVED_MAPI_ID                       EQU     8631
ERROR_DS_MAPI_ID_NOT_AVAILABLE                  EQU     8632
ERROR_DS_DRA_MISSING_KRBTGT_SECRET              EQU     8633
ERROR_DS_DOMAIN_NAME_EXISTS_IN_FOREST           EQU     8634
ERROR_DS_FLAT_NAME_EXISTS_IN_FOREST             EQU     8635
ERROR_INVALID_USER_PRINCIPAL_NAME               EQU     8636
ERROR_DS_OID_MAPPED_GROUP_CANT_HAVE_MEMBERS     EQU     8637
ERROR_DS_OID_NOT_FOUND                          EQU     8638
ERROR_DS_DRA_RECYCLED_TARGET                    EQU     8639
DNS_ERROR_RESPONSE_CODES_BASE                   EQU     9000
DNS_ERROR_RCODE_NO_ERROR                        EQU     NO_ERROR
DNS_ERROR_MASK                                  EQU     DNS_ERROR_RESPONSE_CODES_BASE
DNS_ERROR_RCODE_FORMAT_ERROR                    EQU     9001
DNS_ERROR_RCODE_SERVER_FAILURE                  EQU     9002
DNS_ERROR_RCODE_NAME_ERROR                      EQU     9003
DNS_ERROR_RCODE_NOT_IMPLEMENTED                 EQU     9004
DNS_ERROR_RCODE_REFUSED                         EQU     9005
DNS_ERROR_RCODE_YXDOMAIN                        EQU     9006
DNS_ERROR_RCODE_YXRRSET                         EQU     9007
DNS_ERROR_RCODE_NXRRSET                         EQU     9008
DNS_ERROR_RCODE_NOTAUTH                         EQU     9009
DNS_ERROR_RCODE_NOTZONE                         EQU     9010
DNS_ERROR_RCODE_BADSIG                          EQU     9016
DNS_ERROR_RCODE_BADKEY                          EQU     9017
DNS_ERROR_RCODE_BADTIME                         EQU     9018
DNS_ERROR_RCODE_LAST                            EQU     DNS_ERROR_RCODE_BADTIME
DNS_ERROR_PACKET_FMT_BASE                       EQU     9500
DNS_INFO_NO_RECORDS                             EQU     9501
DNS_ERROR_BAD_PACKET                            EQU     9502
DNS_ERROR_NO_PACKET                             EQU     9503
DNS_ERROR_RCODE                                 EQU     9504
DNS_ERROR_UNSECURE_PACKET                       EQU     9505
DNS_STATUS_PACKET_UNSECURE                      EQU     DNS_ERROR_UNSECURE_PACKET
DNS_ERROR_NO_MEMORY                             EQU     ERROR_OUTOFMEMORY
DNS_ERROR_INVALID_NAME                          EQU     ERROR_INVALID_NAME
DNS_ERROR_INVALID_DATA                          EQU     ERROR_INVALID_DATA
DNS_ERROR_GENERAL_API_BASE                      EQU     9550
DNS_ERROR_INVALID_TYPE                          EQU     9551
DNS_ERROR_INVALID_IP_ADDRESS                    EQU     9552
DNS_ERROR_INVALID_PROPERTY                      EQU     9553
DNS_ERROR_TRY_AGAIN_LATER                       EQU     9554
DNS_ERROR_NOT_UNIQUE                            EQU     9555
DNS_ERROR_NON_RFC_NAME                          EQU     9556
DNS_STATUS_FQDN                                 EQU     9557
DNS_STATUS_DOTTED_NAME                          EQU     9558
DNS_STATUS_SINGLE_PART_NAME                     EQU     9559
DNS_ERROR_INVALID_NAME_CHAR                     EQU     9560
DNS_ERROR_NUMERIC_NAME                          EQU     9561
DNS_ERROR_NOT_ALLOWED_ON_ROOT_SERVER            EQU     9562
DNS_ERROR_NOT_ALLOWED_UNDER_DELEGATION          EQU     9563
DNS_ERROR_CANNOT_FIND_ROOT_HINTS                EQU     9564
DNS_ERROR_INCONSISTENT_ROOT_HINTS               EQU     9565
DNS_ERROR_DWORD_VALUE_TOO_SMALL                 EQU     9566
DNS_ERROR_DWORD_VALUE_TOO_LARGE                 EQU     9567
DNS_ERROR_BACKGROUND_LOADING                    EQU     9568
DNS_ERROR_NOT_ALLOWED_ON_RODC                   EQU     9569
DNS_ERROR_NOT_ALLOWED_UNDER_DNAME               EQU     9570
DNS_ERROR_DELEGATION_REQUIRED                   EQU     9571
DNS_ERROR_INVALID_POLICY_TABLE                  EQU     9572
DNS_ERROR_ZONE_BASE                             EQU     9600
DNS_ERROR_ZONE_DOES_NOT_EXIST                   EQU     9601
DNS_ERROR_NO_ZONE_INFO                          EQU     9602
DNS_ERROR_INVALID_ZONE_OPERATION                EQU     9603
DNS_ERROR_ZONE_CONFIGURATION_ERROR              EQU     9604
DNS_ERROR_ZONE_HAS_NO_SOA_RECORD                EQU     9605
DNS_ERROR_ZONE_HAS_NO_NS_RECORDS                EQU     9606
DNS_ERROR_ZONE_LOCKED                           EQU     9607
DNS_ERROR_ZONE_CREATION_FAILED                  EQU     9608
DNS_ERROR_ZONE_ALREADY_EXISTS                   EQU     9609
DNS_ERROR_AUTOZONE_ALREADY_EXISTS               EQU     9610
DNS_ERROR_INVALID_ZONE_TYPE                     EQU     9611
DNS_ERROR_SECONDARY_REQUIRES_MASTER_IP          EQU     9612
DNS_ERROR_ZONE_NOT_SECONDARY                    EQU     9613
DNS_ERROR_NEED_SECONDARY_ADDRESSES              EQU     9614
DNS_ERROR_WINS_INIT_FAILED                      EQU     9615
DNS_ERROR_NEED_WINS_SERVERS                     EQU     9616
DNS_ERROR_NBSTAT_INIT_FAILED                    EQU     9617
DNS_ERROR_SOA_DELETE_INVALID                    EQU     9618
DNS_ERROR_FORWARDER_ALREADY_EXISTS              EQU     9619
DNS_ERROR_ZONE_REQUIRES_MASTER_IP               EQU     9620
DNS_ERROR_ZONE_IS_SHUTDOWN                      EQU     9621
DNS_ERROR_DATAFILE_BASE                         EQU     9650
DNS_ERROR_PRIMARY_REQUIRES_DATAFILE             EQU     9651
DNS_ERROR_INVALID_DATAFILE_NAME                 EQU     9652
DNS_ERROR_DATAFILE_OPEN_FAILURE                 EQU     9653
DNS_ERROR_FILE_WRITEBACK_FAILED                 EQU     9654
DNS_ERROR_DATAFILE_PARSING                      EQU     9655
DNS_ERROR_DATABASE_BASE                         EQU     9700
DNS_ERROR_RECORD_DOES_NOT_EXIST                 EQU     9701
DNS_ERROR_RECORD_FORMAT                         EQU     9702
DNS_ERROR_NODE_CREATION_FAILED                  EQU     9703
DNS_ERROR_UNKNOWN_RECORD_TYPE                   EQU     9704
DNS_ERROR_RECORD_TIMED_OUT                      EQU     9705
DNS_ERROR_NAME_NOT_IN_ZONE                      EQU     9706
DNS_ERROR_CNAME_LOOP                            EQU     9707
DNS_ERROR_NODE_IS_CNAME                         EQU     9708
DNS_ERROR_CNAME_COLLISION                       EQU     9709
DNS_ERROR_RECORD_ONLY_AT_ZONE_ROOT              EQU     9710
DNS_ERROR_RECORD_ALREADY_EXISTS                 EQU     9711
DNS_ERROR_SECONDARY_DATA                        EQU     9712
DNS_ERROR_NO_CREATE_CACHE_DATA                  EQU     9713
DNS_ERROR_NAME_DOES_NOT_EXIST                   EQU     9714
DNS_WARNING_PTR_CREATE_FAILED                   EQU     9715
DNS_WARNING_DOMAIN_UNDELETED                    EQU     9716
DNS_ERROR_DS_UNAVAILABLE                        EQU     9717
DNS_ERROR_DS_ZONE_ALREADY_EXISTS                EQU     9718
DNS_ERROR_NO_BOOTFILE_IF_DS_ZONE                EQU     9719
DNS_ERROR_NODE_IS_DNAME                         EQU     9720
DNS_ERROR_DNAME_COLLISION                       EQU     9721
DNS_ERROR_ALIAS_LOOP                            EQU     9722
DNS_ERROR_OPERATION_BASE                        EQU     9750
DNS_INFO_AXFR_COMPLETE                          EQU     9751
DNS_ERROR_AXFR                                  EQU     9752
DNS_INFO_ADDED_LOCAL_WINS                       EQU     9753
DNS_ERROR_SECURE_BASE                           EQU     9800
DNS_STATUS_CONTINUE_NEEDED                      EQU     9801
DNS_ERROR_SETUP_BASE                            EQU     9850
DNS_ERROR_NO_TCPIP                              EQU     9851
DNS_ERROR_NO_DNS_SERVERS                        EQU     9852
DNS_ERROR_DP_BASE                               EQU     9900
DNS_ERROR_DP_DOES_NOT_EXIST                     EQU     9901
DNS_ERROR_DP_ALREADY_EXISTS                     EQU     9902
DNS_ERROR_DP_NOT_ENLISTED                       EQU     9903
DNS_ERROR_DP_ALREADY_ENLISTED                   EQU     9904
DNS_ERROR_DP_NOT_AVAILABLE                      EQU     9905
DNS_ERROR_DP_FSMO_ERROR                         EQU     9906

WSABASEERR                                      EQU     10000
WSAEINTR                                        EQU     10004
WSAEBADF                                        EQU     10009
WSAEACCES                                       EQU     10013
WSAEFAULT                                       EQU     10014
WSAEINVAL                                       EQU     10022
WSAEMFILE                                       EQU     10024
WSAEWOULDBLOCK                                  EQU     10035
WSAEINPROGRESS                                  EQU     10036
WSAEALREADY                                     EQU     10037
WSAENOTSOCK                                     EQU     10038
WSAEDESTADDRREQ                                 EQU     10039
WSAEMSGSIZE                                     EQU     10040
WSAEPROTOTYPE                                   EQU     10041
WSAENOPROTOOPT                                  EQU     10042
WSAEPROTONOSUPPORT                              EQU     10043
WSAESOCKTNOSUPPORT                              EQU     10044
WSAEOPNOTSUPP                                   EQU     10045
WSAEPFNOSUPPORT                                 EQU     10046
WSAEAFNOSUPPORT                                 EQU     10047
WSAEADDRINUSE                                   EQU     10048
WSAEADDRNOTAVAIL                                EQU     10049
WSAENETDOWN                                     EQU     10050
WSAENETUNREACH                                  EQU     10051
WSAENETRESET                                    EQU     10052
WSAECONNABORTED                                 EQU     10053
WSAECONNRESET                                   EQU     10054
WSAENOBUFS                                      EQU     10055
WSAEISCONN                                      EQU     10056
WSAENOTCONN                                     EQU     10057
WSAESHUTDOWN                                    EQU     10058
WSAETOOMANYREFS                                 EQU     10059
WSAETIMEDOUT                                    EQU     10060
WSAECONNREFUSED                                 EQU     10061
WSAELOOP                                        EQU     10062
WSAENAMETOOLONG                                 EQU     10063
WSAEHOSTDOWN                                    EQU     10064
WSAEHOSTUNREACH                                 EQU     10065
WSAENOTEMPTY                                    EQU     10066
WSAEPROCLIM                                     EQU     10067
WSAEUSERS                                       EQU     10068
WSAEDQUOT                                       EQU     10069
WSAESTALE                                       EQU     10070
WSAEREMOTE                                      EQU     10071
WSASYSNOTREADY                                  EQU     10091
WSAVERNOTSUPPORTED                              EQU     10092
WSANOTINITIALISED                               EQU     10093
WSAEDISCON                                      EQU     10101
WSAENOMORE                                      EQU     10102
WSAECANCELLED                                   EQU     10103
WSAEINVALIDPROCTABLE                            EQU     10104
WSAEINVALIDPROVIDER                             EQU     10105
WSAEPROVIDERFAILEDINIT                          EQU     10106
WSASYSCALLFAILURE                               EQU     10107
WSASERVICE_NOT_FOUND                            EQU     10108
WSATYPE_NOT_FOUND                               EQU     10109
WSA_E_NO_MORE                                   EQU     10110
WSA_E_CANCELLED                                 EQU     10111
WSAEREFUSED                                     EQU     10112
WSAHOST_NOT_FOUND                               EQU     11001
WSATRY_AGAIN                                    EQU     11002
WSANO_RECOVERY                                  EQU     11003
WSANO_DATA                                      EQU     11004
WSA_QOS_RECEIVERS                               EQU     11005
WSA_QOS_SENDERS                                 EQU     11006
WSA_QOS_NO_SENDERS                              EQU     11007
WSA_QOS_NO_RECEIVERS                            EQU     11008
WSA_QOS_REQUEST_CONFIRMED                       EQU     11009
WSA_QOS_ADMISSION_FAILURE                       EQU     11010
WSA_QOS_POLICY_FAILURE                          EQU     11011
WSA_QOS_BAD_STYLE                               EQU     11012
WSA_QOS_BAD_OBJECT                              EQU     11013
WSA_QOS_TRAFFIC_CTRL_ERROR                      EQU     11014
WSA_QOS_GENERIC_ERROR                           EQU     11015
WSA_QOS_ESERVICETYPE                            EQU     11016
WSA_QOS_EFLOWSPEC                               EQU     11017
WSA_QOS_EPROVSPECBUF                            EQU     11018
WSA_QOS_EFILTERSTYLE                            EQU     11019
WSA_QOS_EFILTERTYPE                             EQU     11020
WSA_QOS_EFILTERCOUNT                            EQU     11021
WSA_QOS_EOBJLENGTH                              EQU     11022
WSA_QOS_EFLOWCOUNT                              EQU     11023
WSA_QOS_EUNKOWNPSOBJ                            EQU     11024
WSA_QOS_EPOLICYOBJ                              EQU     11025
WSA_QOS_EFLOWDESC                               EQU     11026
WSA_QOS_EPSFLOWSPEC                             EQU     11027
WSA_QOS_EPSFILTERSPEC                           EQU     11028
WSA_QOS_ESDMODEOBJ                              EQU     11029
WSA_QOS_ESHAPERATEOBJ                           EQU     11030
WSA_QOS_RESERVED_PETYPE                         EQU     11031
WSA_SECURE_HOST_NOT_FOUND                       EQU     11032
WSA_IPSEC_NAME_POLICY_ERROR                     EQU     11033

ERROR_IPSEC_QM_POLICY_EXISTS                    EQU     13000
ERROR_IPSEC_QM_POLICY_NOT_FOUND                 EQU     13001
ERROR_IPSEC_QM_POLICY_IN_USE                    EQU     13002
ERROR_IPSEC_MM_POLICY_EXISTS                    EQU     13003
ERROR_IPSEC_MM_POLICY_NOT_FOUND                 EQU     13004
ERROR_IPSEC_MM_POLICY_IN_USE                    EQU     13005
ERROR_IPSEC_MM_FILTER_EXISTS                    EQU     13006
ERROR_IPSEC_MM_FILTER_NOT_FOUND                 EQU     13007
ERROR_IPSEC_TRANSPORT_FILTER_EXISTS             EQU     13008
ERROR_IPSEC_TRANSPORT_FILTER_NOT_FOUND          EQU     13009
ERROR_IPSEC_MM_AUTH_EXISTS                      EQU     13010
ERROR_IPSEC_MM_AUTH_NOT_FOUND                   EQU     13011
ERROR_IPSEC_MM_AUTH_IN_USE                      EQU     13012
ERROR_IPSEC_DEFAULT_MM_POLICY_NOT_FOUND         EQU     13013
ERROR_IPSEC_DEFAULT_MM_AUTH_NOT_FOUND           EQU     13014
ERROR_IPSEC_DEFAULT_QM_POLICY_NOT_FOUND         EQU     13015
ERROR_IPSEC_TUNNEL_FILTER_EXISTS                EQU     13016
ERROR_IPSEC_TUNNEL_FILTER_NOT_FOUND             EQU     13017
ERROR_IPSEC_MM_FILTER_PENDING_DELETION          EQU     13018
ERROR_IPSEC_TRANSPORT_FILTER_PENDING_DELETION   EQU     13019
ERROR_IPSEC_TUNNEL_FILTER_PENDING_DELETION      EQU     13020
ERROR_IPSEC_MM_POLICY_PENDING_DELETION          EQU     13021
ERROR_IPSEC_MM_AUTH_PENDING_DELETION            EQU     13022
ERROR_IPSEC_QM_POLICY_PENDING_DELETION          EQU     13023
WARNING_IPSEC_MM_POLICY_PRUNED                  EQU     13024
WARNING_IPSEC_QM_POLICY_PRUNED                  EQU     13025
ERROR_IPSEC_IKE_NEG_STATUS_BEGIN                EQU     13800
ERROR_IPSEC_IKE_AUTH_FAIL                       EQU     13801
ERROR_IPSEC_IKE_ATTRIB_FAIL                     EQU     13802
ERROR_IPSEC_IKE_NEGOTIATION_PENDING             EQU     13803
ERROR_IPSEC_IKE_GENERAL_PROCESSING_ERROR        EQU     13804
ERROR_IPSEC_IKE_TIMED_OUT                       EQU     13805
ERROR_IPSEC_IKE_NO_CERT                         EQU     13806
ERROR_IPSEC_IKE_SA_DELETED                      EQU     13807
ERROR_IPSEC_IKE_SA_REAPED                       EQU     13808
ERROR_IPSEC_IKE_MM_ACQUIRE_DROP                 EQU     13809
ERROR_IPSEC_IKE_QM_ACQUIRE_DROP                 EQU     13810
ERROR_IPSEC_IKE_QUEUE_DROP_MM                   EQU     13811
ERROR_IPSEC_IKE_QUEUE_DROP_NO_MM                EQU     13812
ERROR_IPSEC_IKE_DROP_NO_RESPONSE                EQU     13813
ERROR_IPSEC_IKE_MM_DELAY_DROP                   EQU     13814
ERROR_IPSEC_IKE_QM_DELAY_DROP                   EQU     13815
ERROR_IPSEC_IKE_ERROR                           EQU     13816
ERROR_IPSEC_IKE_CRL_FAILED                      EQU     13817
ERROR_IPSEC_IKE_INVALID_KEY_USAGE               EQU     13818
ERROR_IPSEC_IKE_INVALID_CERT_TYPE               EQU     13819
ERROR_IPSEC_IKE_NO_PRIVATE_KEY                  EQU     13820
ERROR_IPSEC_IKE_SIMULTANEOUS_REKEY              EQU     13821
ERROR_IPSEC_IKE_DH_FAIL                         EQU     13822
ERROR_IPSEC_IKE_CRITICAL_PAYLOAD_NOT_RECOGNIZED EQU     13823
ERROR_IPSEC_IKE_INVALID_HEADER                  EQU     13824
ERROR_IPSEC_IKE_NO_POLICY                       EQU     13825
ERROR_IPSEC_IKE_INVALID_SIGNATURE               EQU     13826
ERROR_IPSEC_IKE_KERBEROS_ERROR                  EQU     13827
ERROR_IPSEC_IKE_NO_PUBLIC_KEY                   EQU     13828
ERROR_IPSEC_IKE_PROCESS_ERR                     EQU     13829
ERROR_IPSEC_IKE_PROCESS_ERR_SA                  EQU     13830
ERROR_IPSEC_IKE_PROCESS_ERR_PROP                EQU     13831
ERROR_IPSEC_IKE_PROCESS_ERR_TRANS               EQU     13832
ERROR_IPSEC_IKE_PROCESS_ERR_KE                  EQU     13833
ERROR_IPSEC_IKE_PROCESS_ERR_ID                  EQU     13834
ERROR_IPSEC_IKE_PROCESS_ERR_CERT                EQU     13835
ERROR_IPSEC_IKE_PROCESS_ERR_CERT_REQ            EQU     13836
ERROR_IPSEC_IKE_PROCESS_ERR_HASH                EQU     13837
ERROR_IPSEC_IKE_PROCESS_ERR_SIG                 EQU     13838
ERROR_IPSEC_IKE_PROCESS_ERR_NONCE               EQU     13839
ERROR_IPSEC_IKE_PROCESS_ERR_NOTIFY              EQU     13840
ERROR_IPSEC_IKE_PROCESS_ERR_DELETE              EQU     13841
ERROR_IPSEC_IKE_PROCESS_ERR_VENDOR              EQU     13842
ERROR_IPSEC_IKE_INVALID_PAYLOAD                 EQU     13843
ERROR_IPSEC_IKE_LOAD_SOFT_SA                    EQU     13844
ERROR_IPSEC_IKE_SOFT_SA_TORN_DOWN               EQU     13845
ERROR_IPSEC_IKE_INVALID_COOKIE                  EQU     13846
ERROR_IPSEC_IKE_NO_PEER_CERT                    EQU     13847
ERROR_IPSEC_IKE_PEER_CRL_FAILED                 EQU     13848
ERROR_IPSEC_IKE_POLICY_CHANGE                   EQU     13849
ERROR_IPSEC_IKE_NO_MM_POLICY                    EQU     13850
ERROR_IPSEC_IKE_NOTCBPRIV                       EQU     13851
ERROR_IPSEC_IKE_SECLOADFAIL                     EQU     13852
ERROR_IPSEC_IKE_FAILSSPINIT                     EQU     13853
ERROR_IPSEC_IKE_FAILQUERYSSP                    EQU     13854
ERROR_IPSEC_IKE_SRVACQFAIL                      EQU     13855
ERROR_IPSEC_IKE_SRVQUERYCRED                    EQU     13856
ERROR_IPSEC_IKE_GETSPIFAIL                      EQU     13857
ERROR_IPSEC_IKE_INVALID_FILTER                  EQU     13858
ERROR_IPSEC_IKE_OUT_OF_MEMORY                   EQU     13859
ERROR_IPSEC_IKE_ADD_UPDATE_KEY_FAILED           EQU     13860
ERROR_IPSEC_IKE_INVALID_POLICY                  EQU     13861
ERROR_IPSEC_IKE_UNKNOWN_DOI                     EQU     13862
ERROR_IPSEC_IKE_INVALID_SITUATION               EQU     13863
ERROR_IPSEC_IKE_DH_FAILURE                      EQU     13864
ERROR_IPSEC_IKE_INVALID_GROUP                   EQU     13865
ERROR_IPSEC_IKE_ENCRYPT                         EQU     13866
ERROR_IPSEC_IKE_DECRYPT                         EQU     13867
ERROR_IPSEC_IKE_POLICY_MATCH                    EQU     13868
ERROR_IPSEC_IKE_UNSUPPORTED_ID                  EQU     13869
ERROR_IPSEC_IKE_INVALID_HASH                    EQU     13870
ERROR_IPSEC_IKE_INVALID_HASH_ALG                EQU     13871
ERROR_IPSEC_IKE_INVALID_HASH_SIZE               EQU     13872
ERROR_IPSEC_IKE_INVALID_ENCRYPT_ALG             EQU     13873
ERROR_IPSEC_IKE_INVALID_AUTH_ALG                EQU     13874
ERROR_IPSEC_IKE_INVALID_SIG                     EQU     13875
ERROR_IPSEC_IKE_LOAD_FAILED                     EQU     13876
ERROR_IPSEC_IKE_RPC_DELETE                      EQU     13877
ERROR_IPSEC_IKE_BENIGN_REINIT                   EQU     13878
ERROR_IPSEC_IKE_INVALID_RESPONDER_LIFETIME_NOTIFY EQU   13879
ERROR_IPSEC_IKE_INVALID_MAJOR_VERSION           EQU     13880
ERROR_IPSEC_IKE_INVALID_CERT_KEYLEN             EQU     13881
ERROR_IPSEC_IKE_MM_LIMIT                        EQU     13882
ERROR_IPSEC_IKE_NEGOTIATION_DISABLED            EQU     13883
ERROR_IPSEC_IKE_QM_LIMIT                        EQU     13884
ERROR_IPSEC_IKE_MM_EXPIRED                      EQU     13885
ERROR_IPSEC_IKE_PEER_MM_ASSUMED_INVALID         EQU     13886
ERROR_IPSEC_IKE_CERT_CHAIN_POLICY_MISMATCH      EQU     13887
ERROR_IPSEC_IKE_UNEXPECTED_MESSAGE_ID           EQU     13888
ERROR_IPSEC_IKE_INVALID_AUTH_PAYLOAD            EQU     13889
ERROR_IPSEC_IKE_DOS_COOKIE_SENT                 EQU     13890
ERROR_IPSEC_IKE_SHUTTING_DOWN                   EQU     13891
ERROR_IPSEC_IKE_CGA_AUTH_FAILED                 EQU     13892
ERROR_IPSEC_IKE_PROCESS_ERR_NATOA               EQU     13893
ERROR_IPSEC_IKE_INVALID_MM_FOR_QM               EQU     13894
ERROR_IPSEC_IKE_QM_EXPIRED                      EQU     13895
ERROR_IPSEC_IKE_TOO_MANY_FILTERS                EQU     13896
ERROR_IPSEC_IKE_NEG_STATUS_END                  EQU     13897
ERROR_IPSEC_IKE_KILL_DUMMY_NAP_TUNNEL           EQU     13898
ERROR_IPSEC_IKE_INNER_IP_ASSIGNMENT_FAILURE     EQU     13899
ERROR_IPSEC_IKE_REQUIRE_CP_PAYLOAD_MISSING      EQU     13900
ERROR_IPSEC_KEY_MODULE_IMPERSONATION_NEGOTIATION_PENDING EQU 13901
ERROR_IPSEC_IKE_COEXISTENCE_SUPPRESS            EQU     13902
ERROR_IPSEC_IKE_RATELIMIT_DROP                  EQU     13903
ERROR_IPSEC_IKE_PEER_DOESNT_SUPPORT_MOBIKE      EQU     13904
ERROR_IPSEC_IKE_AUTHORIZATION_FAILURE           EQU     13905
ERROR_IPSEC_IKE_STRONG_CRED_AUTHORIZATION_FAILURE EQU   13906
ERROR_IPSEC_IKE_AUTHORIZATION_FAILURE_WITH_OPTIONAL_RETRY EQU 13907
ERROR_IPSEC_IKE_STRONG_CRED_AUTHORIZATION_AND_CERTMAP_FAILURE EQU 13908
ERROR_IPSEC_IKE_NEG_STATUS_EXTENDED_END         EQU     13909
ERROR_IPSEC_BAD_SPI                             EQU     13910
ERROR_IPSEC_SA_LIFETIME_EXPIRED                 EQU     13911
ERROR_IPSEC_WRONG_SA                            EQU     13912
ERROR_IPSEC_REPLAY_CHECK_FAILED                 EQU     13913
ERROR_IPSEC_INVALID_PACKET                      EQU     13914
ERROR_IPSEC_INTEGRITY_CHECK_FAILED              EQU     13915
ERROR_IPSEC_CLEAR_TEXT_DROP                     EQU     13916
ERROR_IPSEC_AUTH_FIREWALL_DROP                  EQU     13917
ERROR_IPSEC_THROTTLE_DROP                       EQU     13918
ERROR_IPSEC_DOSP_BLOCK                          EQU     13925
ERROR_IPSEC_DOSP_RECEIVED_MULTICAST             EQU     13926
ERROR_IPSEC_DOSP_INVALID_PACKET                 EQU     13927
ERROR_IPSEC_DOSP_STATE_LOOKUP_FAILED            EQU     13928
ERROR_IPSEC_DOSP_MAX_ENTRIES                    EQU     13929
ERROR_IPSEC_DOSP_KEYMOD_NOT_ALLOWED             EQU     13930
ERROR_IPSEC_DOSP_NOT_INSTALLED                  EQU     13931
ERROR_IPSEC_DOSP_MAX_PER_IP_RATELIMIT_QUEUES    EQU     13932
ERROR_SXS_SECTION_NOT_FOUND                     EQU     14000
ERROR_SXS_CANT_GEN_ACTCTX                       EQU     14001
ERROR_SXS_INVALID_ACTCTXDATA_FORMAT             EQU     14002
ERROR_SXS_ASSEMBLY_NOT_FOUND                    EQU     14003
ERROR_SXS_MANIFEST_FORMAT_ERROR                 EQU     14004
ERROR_SXS_MANIFEST_PARSE_ERROR                  EQU     14005
ERROR_SXS_ACTIVATION_CONTEXT_DISABLED           EQU     14006
ERROR_SXS_KEY_NOT_FOUND                         EQU     14007
ERROR_SXS_VERSION_CONFLICT                      EQU     14008
ERROR_SXS_WRONG_SECTION_TYPE                    EQU     14009
ERROR_SXS_THREAD_QUERIES_DISABLED               EQU     14010
ERROR_SXS_PROCESS_DEFAULT_ALREADY_SET           EQU     14011
ERROR_SXS_UNKNOWN_ENCODING_GROUP                EQU     14012
ERROR_SXS_UNKNOWN_ENCODING                      EQU     14013
ERROR_SXS_INVALID_XML_NAMESPACE_URI             EQU     14014
ERROR_SXS_ROOT_MANIFEST_DEPENDENCY_NOT_INSTALLED EQU    14015
ERROR_SXS_LEAF_MANIFEST_DEPENDENCY_NOT_INSTALLED EQU    14016
ERROR_SXS_INVALID_ASSEMBLY_IDENTITY_ATTRIBUTE   EQU     14017
ERROR_SXS_MANIFEST_MISSING_REQUIRED_DEFAULT_NAMESPACE EQU 14018
ERROR_SXS_MANIFEST_INVALID_REQUIRED_DEFAULT_NAMESPACE EQU 14019
ERROR_SXS_PRIVATE_MANIFEST_CROSS_PATH_WITH_REPARSE_POINT EQU 14020
ERROR_SXS_DUPLICATE_DLL_NAME                    EQU     14021
ERROR_SXS_DUPLICATE_WINDOWCLASS_NAME            EQU     14022
ERROR_SXS_DUPLICATE_CLSID                       EQU     14023
ERROR_SXS_DUPLICATE_IID                         EQU     14024
ERROR_SXS_DUPLICATE_TLBID                       EQU     14025
ERROR_SXS_DUPLICATE_PROGID                      EQU     14026
ERROR_SXS_DUPLICATE_ASSEMBLY_NAME               EQU     14027
ERROR_SXS_FILE_HASH_MISMATCH                    EQU     14028
ERROR_SXS_POLICY_PARSE_ERROR                    EQU     14029
ERROR_SXS_XML_E_MISSINGQUOTE                    EQU     14030
ERROR_SXS_XML_E_COMMENTSYNTAX                   EQU     14031
ERROR_SXS_XML_E_BADSTARTNAMECHAR                EQU     14032
ERROR_SXS_XML_E_BADNAMECHAR                     EQU     14033
ERROR_SXS_XML_E_BADCHARINSTRING                 EQU     14034
ERROR_SXS_XML_E_XMLDECLSYNTAX                   EQU     14035
ERROR_SXS_XML_E_BADCHARDATA                     EQU     14036
ERROR_SXS_XML_E_MISSINGWHITESPACE               EQU     14037
ERROR_SXS_XML_E_EXPECTINGTAGEND                 EQU     14038
ERROR_SXS_XML_E_MISSINGSEMICOLON                EQU     14039
ERROR_SXS_XML_E_UNBALANCEDPAREN                 EQU     14040
ERROR_SXS_XML_E_INTERNALERROR                   EQU     14041
ERROR_SXS_XML_E_UNEXPECTED_WHITESPACE           EQU     14042
ERROR_SXS_XML_E_INCOMPLETE_ENCODING             EQU     14043
ERROR_SXS_XML_E_MISSING_PAREN                   EQU     14044
ERROR_SXS_XML_E_EXPECTINGCLOSEQUOTE             EQU     14045
ERROR_SXS_XML_E_MULTIPLE_COLONS                 EQU     14046
ERROR_SXS_XML_E_INVALID_DECIMAL                 EQU     14047
ERROR_SXS_XML_E_INVALID_HEXIDECIMAL             EQU     14048
ERROR_SXS_XML_E_INVALID_UNICODE                 EQU     14049
ERROR_SXS_XML_E_WHITESPACEORQUESTIONMARK        EQU     14050
ERROR_SXS_XML_E_UNEXPECTEDENDTAG                EQU     14051
ERROR_SXS_XML_E_UNCLOSEDTAG                     EQU     14052
ERROR_SXS_XML_E_DUPLICATEATTRIBUTE              EQU     14053
ERROR_SXS_XML_E_MULTIPLEROOTS                   EQU     14054
ERROR_SXS_XML_E_INVALIDATROOTLEVEL              EQU     14055
ERROR_SXS_XML_E_BADXMLDECL                      EQU     14056
ERROR_SXS_XML_E_MISSINGROOT                     EQU     14057
ERROR_SXS_XML_E_UNEXPECTEDEOF                   EQU     14058
ERROR_SXS_XML_E_BADPEREFINSUBSET                EQU     14059
ERROR_SXS_XML_E_UNCLOSEDSTARTTAG                EQU     14060
ERROR_SXS_XML_E_UNCLOSEDENDTAG                  EQU     14061
ERROR_SXS_XML_E_UNCLOSEDSTRING                  EQU     14062
ERROR_SXS_XML_E_UNCLOSEDCOMMENT                 EQU     14063
ERROR_SXS_XML_E_UNCLOSEDDECL                    EQU     14064
ERROR_SXS_XML_E_UNCLOSEDCDATA                   EQU     14065
ERROR_SXS_XML_E_RESERVEDNAMESPACE               EQU     14066
ERROR_SXS_XML_E_INVALIDENCODING                 EQU     14067
ERROR_SXS_XML_E_INVALIDSWITCH                   EQU     14068
ERROR_SXS_XML_E_BADXMLCASE                      EQU     14069
ERROR_SXS_XML_E_INVALID_STANDALONE              EQU     14070
ERROR_SXS_XML_E_UNEXPECTED_STANDALONE           EQU     14071
ERROR_SXS_XML_E_INVALID_VERSION                 EQU     14072
ERROR_SXS_XML_E_MISSINGEQUALS                   EQU     14073
ERROR_SXS_PROTECTION_RECOVERY_FAILED            EQU     14074
ERROR_SXS_PROTECTION_PUBLIC_KEY_TOO_SHORT       EQU     14075
ERROR_SXS_PROTECTION_CATALOG_NOT_VALID          EQU     14076
ERROR_SXS_UNTRANSLATABLE_HRESULT                EQU     14077
ERROR_SXS_PROTECTION_CATALOG_FILE_MISSING       EQU     14078
ERROR_SXS_MISSING_ASSEMBLY_IDENTITY_ATTRIBUTE   EQU     14079
ERROR_SXS_INVALID_ASSEMBLY_IDENTITY_ATTRIBUTE_NAME EQU  14080
ERROR_SXS_ASSEMBLY_MISSING                      EQU     14081
ERROR_SXS_CORRUPT_ACTIVATION_STACK              EQU     14082
ERROR_SXS_CORRUPTION                            EQU     14083
ERROR_SXS_EARLY_DEACTIVATION                    EQU     14084
ERROR_SXS_INVALID_DEACTIVATION                  EQU     14085
ERROR_SXS_MULTIPLE_DEACTIVATION                 EQU     14086
ERROR_SXS_PROCESS_TERMINATION_REQUESTED         EQU     14087
ERROR_SXS_RELEASE_ACTIVATION_CONTEXT            EQU     14088
ERROR_SXS_SYSTEM_DEFAULT_ACTIVATION_CONTEXT_EMPTY EQU   14089
ERROR_SXS_INVALID_IDENTITY_ATTRIBUTE_VALUE      EQU     14090
ERROR_SXS_INVALID_IDENTITY_ATTRIBUTE_NAME       EQU     14091
ERROR_SXS_IDENTITY_DUPLICATE_ATTRIBUTE          EQU     14092
ERROR_SXS_IDENTITY_PARSE_ERROR                  EQU     14093
ERROR_MALFORMED_SUBSTITUTION_STRING             EQU     14094
ERROR_SXS_INCORRECT_PUBLIC_KEY_TOKEN            EQU     14095
ERROR_UNMAPPED_SUBSTITUTION_STRING              EQU     14096
ERROR_SXS_ASSEMBLY_NOT_LOCKED                   EQU     14097
ERROR_SXS_COMPONENT_STORE_CORRUPT               EQU     14098
ERROR_ADVANCED_INSTALLER_FAILED                 EQU     14099
ERROR_XML_ENCODING_MISMATCH                     EQU     14100
ERROR_SXS_MANIFEST_IDENTITY_SAME_BUT_CONTENTS_DIFFERENT EQU 14101
ERROR_SXS_IDENTITIES_DIFFERENT                  EQU     14102
ERROR_SXS_ASSEMBLY_IS_NOT_A_DEPLOYMENT          EQU     14103
ERROR_SXS_FILE_NOT_PART_OF_ASSEMBLY             EQU     14104
ERROR_SXS_MANIFEST_TOO_BIG                      EQU     14105
ERROR_SXS_SETTING_NOT_REGISTERED                EQU     14106
ERROR_SXS_TRANSACTION_CLOSURE_INCOMPLETE        EQU     14107
ERROR_SMI_PRIMITIVE_INSTALLER_FAILED            EQU     14108
ERROR_GENERIC_COMMAND_FAILED                    EQU     14109
ERROR_SXS_FILE_HASH_MISSING                     EQU     14110
ERROR_EVT_INVALID_CHANNEL_PATH                  EQU     15000
ERROR_EVT_INVALID_QUERY                         EQU     15001
ERROR_EVT_PUBLISHER_METADATA_NOT_FOUND          EQU     15002
ERROR_EVT_EVENT_TEMPLATE_NOT_FOUND              EQU     15003
ERROR_EVT_INVALID_PUBLISHER_NAME                EQU     15004
ERROR_EVT_INVALID_EVENT_DATA                    EQU     15005
ERROR_EVT_CHANNEL_NOT_FOUND                     EQU     15007
ERROR_EVT_MALFORMED_XML_TEXT                    EQU     15008
ERROR_EVT_SUBSCRIPTION_TO_DIRECT_CHANNEL        EQU     15009
ERROR_EVT_CONFIGURATION_ERROR                   EQU     15010
ERROR_EVT_QUERY_RESULT_STALE                    EQU     15011
ERROR_EVT_QUERY_RESULT_INVALID_POSITION         EQU     15012
ERROR_EVT_NON_VALIDATING_MSXML                  EQU     15013
ERROR_EVT_FILTER_ALREADYSCOPED                  EQU     15014
ERROR_EVT_FILTER_NOTELTSET                      EQU     15015
ERROR_EVT_FILTER_INVARG                         EQU     15016
ERROR_EVT_FILTER_INVTEST                        EQU     15017
ERROR_EVT_FILTER_INVTYPE                        EQU     15018
ERROR_EVT_FILTER_PARSEERR                       EQU     15019
ERROR_EVT_FILTER_UNSUPPORTEDOP                  EQU     15020
ERROR_EVT_FILTER_UNEXPECTEDTOKEN                EQU     15021
ERROR_EVT_INVALID_OPERATION_OVER_ENABLED_DIRECT_CHANNEL EQU 15022
ERROR_EVT_INVALID_CHANNEL_PROPERTY_VALUE        EQU     15023
ERROR_EVT_INVALID_PUBLISHER_PROPERTY_VALUE      EQU     15024
ERROR_EVT_CHANNEL_CANNOT_ACTIVATE               EQU     15025
ERROR_EVT_FILTER_TOO_COMPLEX                    EQU     15026
ERROR_EVT_MESSAGE_NOT_FOUND                     EQU     15027
ERROR_EVT_MESSAGE_ID_NOT_FOUND                  EQU     15028
ERROR_EVT_UNRESOLVED_VALUE_INSERT               EQU     15029
ERROR_EVT_UNRESOLVED_PARAMETER_INSERT           EQU     15030
ERROR_EVT_MAX_INSERTS_REACHED                   EQU     15031
ERROR_EVT_EVENT_DEFINITION_NOT_FOUND            EQU     15032
ERROR_EVT_MESSAGE_LOCALE_NOT_FOUND              EQU     15033
ERROR_EVT_VERSION_TOO_OLD                       EQU     15034
ERROR_EVT_VERSION_TOO_NEW                       EQU     15035
ERROR_EVT_CANNOT_OPEN_CHANNEL_OF_QUERY          EQU     15036
ERROR_EVT_PUBLISHER_DISABLED                    EQU     15037
ERROR_EVT_FILTER_OUT_OF_RANGE                   EQU     15038
ERROR_EC_SUBSCRIPTION_CANNOT_ACTIVATE           EQU     15080
ERROR_EC_LOG_DISABLED                           EQU     15081
ERROR_EC_CIRCULAR_FORWARDING                    EQU     15082
ERROR_EC_CREDSTORE_FULL                         EQU     15083
ERROR_EC_CRED_NOT_FOUND                         EQU     15084
ERROR_EC_NO_ACTIVE_CHANNEL                      EQU     15085
ERROR_MUI_FILE_NOT_FOUND                        EQU     15100
ERROR_MUI_INVALID_FILE                          EQU     15101
ERROR_MUI_INVALID_RC_CONFIG                     EQU     15102
ERROR_MUI_INVALID_LOCALE_NAME                   EQU     15103
ERROR_MUI_INVALID_ULTIMATEFALLBACK_NAME         EQU     15104
ERROR_MUI_FILE_NOT_LOADED                       EQU     15105
ERROR_RESOURCE_ENUM_USER_STOP                   EQU     15106
ERROR_MUI_INTLSETTINGS_UILANG_NOT_INSTALLED     EQU     15107
ERROR_MUI_INTLSETTINGS_INVALID_LOCALE_NAME      EQU     15108
ERROR_MCA_INVALID_CAPABILITIES_STRING           EQU     15200
ERROR_MCA_INVALID_VCP_VERSION                   EQU     15201
ERROR_MCA_MONITOR_VIOLATES_MCCS_SPECIFICATION   EQU     15202
ERROR_MCA_MCCS_VERSION_MISMATCH                 EQU     15203
ERROR_MCA_UNSUPPORTED_MCCS_VERSION              EQU     15204
ERROR_MCA_INTERNAL_ERROR                        EQU     15205
ERROR_MCA_INVALID_TECHNOLOGY_TYPE_RETURNED      EQU     15206
ERROR_MCA_UNSUPPORTED_COLOR_TEMPERATURE         EQU     15207
ERROR_AMBIGUOUS_SYSTEM_DEVICE                   EQU     15250
ERROR_SYSTEM_DEVICE_NOT_FOUND                   EQU     15299
ERROR_HASH_NOT_SUPPORTED                        EQU     15300
ERROR_HASH_NOT_PRESENT                          EQU     15301
SEVERITY_SUCCESS                                EQU     0
SEVERITY_ERROR                                  EQU     1

E_UNEXPECTED                                    EQU     8000FFFFH

INTERNET_ERROR_BASE                             EQU     12000
ERROR_INTERNET_OUT_OF_HANDLES                   EQU     (INTERNET_ERROR_BASE + 1)
ERROR_INTERNET_TIMEOUT                          EQU     (INTERNET_ERROR_BASE + 2)
ERROR_INTERNET_EXTENDED_ERROR                   EQU     (INTERNET_ERROR_BASE + 3)
ERROR_INTERNET_INTERNAL_ERROR                   EQU     (INTERNET_ERROR_BASE + 4)
ERROR_INTERNET_INVALID_URL                      EQU     (INTERNET_ERROR_BASE + 5)
ERROR_INTERNET_UNRECOGNIZED_SCHEME              EQU     (INTERNET_ERROR_BASE + 6)
ERROR_INTERNET_NAME_NOT_RESOLVED                EQU     (INTERNET_ERROR_BASE + 7)
ERROR_INTERNET_PROTOCOL_NOT_FOUND               EQU     (INTERNET_ERROR_BASE + 8)
ERROR_INTERNET_INVALID_OPTION                   EQU     (INTERNET_ERROR_BASE + 9)
ERROR_INTERNET_BAD_OPTION_LENGTH                EQU     (INTERNET_ERROR_BASE + 10)
ERROR_INTERNET_OPTION_NOT_SETTABLE              EQU     (INTERNET_ERROR_BASE + 11)
ERROR_INTERNET_SHUTDOWN                         EQU     (INTERNET_ERROR_BASE + 12)
ERROR_INTERNET_INCORRECT_USER_NAME              EQU     (INTERNET_ERROR_BASE + 13)
ERROR_INTERNET_INCORRECT_PASSWORD               EQU     (INTERNET_ERROR_BASE + 14)
ERROR_INTERNET_LOGIN_FAILURE                    EQU     (INTERNET_ERROR_BASE + 15)
ERROR_INTERNET_INVALID_OPERATION                EQU     (INTERNET_ERROR_BASE + 16)
ERROR_INTERNET_OPERATION_CANCELLED              EQU     (INTERNET_ERROR_BASE + 17)
ERROR_INTERNET_INCORRECT_HANDLE_TYPE            EQU     (INTERNET_ERROR_BASE + 18)
ERROR_INTERNET_INCORRECT_HANDLE_STATE           EQU     (INTERNET_ERROR_BASE + 19)
ERROR_INTERNET_NOT_PROXY_REQUEST                EQU     (INTERNET_ERROR_BASE + 20)
ERROR_INTERNET_REGISTRY_VALUE_NOT_FOUND         EQU     (INTERNET_ERROR_BASE + 21)
ERROR_INTERNET_BAD_REGISTRY_PARAMETER           EQU     (INTERNET_ERROR_BASE + 22)
ERROR_INTERNET_NO_DIRECT_ACCESS                 EQU     (INTERNET_ERROR_BASE + 23)
ERROR_INTERNET_NO_CONTEXT                       EQU     (INTERNET_ERROR_BASE + 24)
ERROR_INTERNET_NO_CALLBACK                      EQU     (INTERNET_ERROR_BASE + 25)
ERROR_INTERNET_REQUEST_PENDING                  EQU     (INTERNET_ERROR_BASE + 26)
ERROR_INTERNET_INCORRECT_FORMAT                 EQU     (INTERNET_ERROR_BASE + 27)
ERROR_INTERNET_ITEM_NOT_FOUND                   EQU     (INTERNET_ERROR_BASE + 28)
ERROR_INTERNET_CANNOT_CONNECT                   EQU     (INTERNET_ERROR_BASE + 29)
ERROR_INTERNET_CONNECTION_ABORTED               EQU     (INTERNET_ERROR_BASE + 30)
ERROR_INTERNET_CONNECTION_RESET                 EQU     (INTERNET_ERROR_BASE + 31)
ERROR_INTERNET_FORCE_RETRY                      EQU     (INTERNET_ERROR_BASE + 32)
ERROR_INTERNET_INVALID_PROXY_REQUEST            EQU     (INTERNET_ERROR_BASE + 33)
ERROR_INTERNET_NEED_UI                          EQU     (INTERNET_ERROR_BASE + 34)
ERROR_INTERNET_HANDLE_EXISTS                    EQU     (INTERNET_ERROR_BASE + 36)
ERROR_INTERNET_SEC_CERT_DATE_INVALID            EQU     (INTERNET_ERROR_BASE + 37)
ERROR_INTERNET_SEC_CERT_CN_INVALID              EQU     (INTERNET_ERROR_BASE + 38)
ERROR_INTERNET_HTTP_TO_HTTPS_ON_REDIR           EQU     (INTERNET_ERROR_BASE + 39)
ERROR_INTERNET_HTTPS_TO_HTTP_ON_REDIR           EQU     (INTERNET_ERROR_BASE + 40)
ERROR_INTERNET_MIXED_SECURITY                   EQU     (INTERNET_ERROR_BASE + 41)
ERROR_INTERNET_CHG_POST_IS_NON_SECURE           EQU     (INTERNET_ERROR_BASE + 42)
ERROR_INTERNET_POST_IS_NON_SECURE               EQU     (INTERNET_ERROR_BASE + 43)
ERROR_INTERNET_CLIENT_AUTH_CERT_NEEDED          EQU     (INTERNET_ERROR_BASE + 44)
ERROR_INTERNET_INVALID_CA                       EQU     (INTERNET_ERROR_BASE + 45)
ERROR_INTERNET_CLIENT_AUTH_NOT_SETUP            EQU     (INTERNET_ERROR_BASE + 46)
ERROR_INTERNET_ASYNC_THREAD_FAILED              EQU     (INTERNET_ERROR_BASE + 47)
ERROR_INTERNET_REDIRECT_SCHEME_CHANGE           EQU     (INTERNET_ERROR_BASE + 48)
ERROR_INTERNET_DIALOG_PENDING                   EQU     (INTERNET_ERROR_BASE + 49)
ERROR_INTERNET_RETRY_DIALOG                     EQU     (INTERNET_ERROR_BASE + 50)
ERROR_INTERNET_HTTPS_HTTP_SUBMIT_REDIR          EQU     (INTERNET_ERROR_BASE + 52)
ERROR_INTERNET_INSERT_CDROM                     EQU     (INTERNET_ERROR_BASE + 53)
ERROR_FTP_TRANSFER_IN_PROGRESS                  EQU     (INTERNET_ERROR_BASE + 110)
ERROR_FTP_DROPPED                               EQU     (INTERNET_ERROR_BASE + 111)
ERROR_FTP_NO_PASSIVE_MODE                       EQU     (INTERNET_ERROR_BASE + 112)
ERROR_GOPHER_PROTOCOL_ERROR                     EQU     (INTERNET_ERROR_BASE + 130)
ERROR_GOPHER_NOT_FILE                           EQU     (INTERNET_ERROR_BASE + 131)
ERROR_GOPHER_DATA_ERROR                         EQU     (INTERNET_ERROR_BASE + 132)
ERROR_GOPHER_END_OF_DATA                        EQU     (INTERNET_ERROR_BASE + 133)
ERROR_GOPHER_INVALID_LOCATOR                    EQU     (INTERNET_ERROR_BASE + 134)
ERROR_GOPHER_INCORRECT_LOCATOR_TYPE             EQU      (INTERNET_ERROR_BASE + 135)
ERROR_GOPHER_NOT_GOPHER_PLUS                    EQU     (INTERNET_ERROR_BASE + 136)
ERROR_GOPHER_ATTRIBUTE_NOT_FOUND                EQU     (INTERNET_ERROR_BASE + 137)
ERROR_GOPHER_UNKNOWN_LOCATOR                    EQU     (INTERNET_ERROR_BASE + 138)
ERROR_HTTP_HEADER_NOT_FOUND                     EQU     (INTERNET_ERROR_BASE + 150)
ERROR_HTTP_DOWNLEVEL_SERVER                     EQU     (INTERNET_ERROR_BASE + 151)
ERROR_HTTP_INVALID_SERVER_RESPONSE              EQU     (INTERNET_ERROR_BASE + 152)
ERROR_HTTP_INVALID_HEADER                       EQU     (INTERNET_ERROR_BASE + 153)
ERROR_HTTP_INVALID_QUERY_REQUEST                EQU     (INTERNET_ERROR_BASE + 154)
ERROR_HTTP_HEADER_ALREADY_EXISTS                EQU     (INTERNET_ERROR_BASE + 155)
ERROR_HTTP_REDIRECT_FAILED                      EQU     (INTERNET_ERROR_BASE + 156)
ERROR_HTTP_NOT_REDIRECTED                       EQU     (INTERNET_ERROR_BASE + 160)
ERROR_HTTP_COOKIE_NEEDS_CONFIRMATION            EQU     (INTERNET_ERROR_BASE + 161)
ERROR_HTTP_COOKIE_DECLINED                      EQU     (INTERNET_ERROR_BASE + 162)
ERROR_HTTP_REDIRECT_NEEDS_CONFIRMATION          EQU     (INTERNET_ERROR_BASE + 168)
ERROR_INTERNET_SECURITY_CHANNEL_ERROR           EQU     (INTERNET_ERROR_BASE + 157)
ERROR_INTERNET_UNABLE_TO_CACHE_FILE             EQU     (INTERNET_ERROR_BASE + 158)
ERROR_INTERNET_TCPIP_NOT_INSTALLED              EQU     (INTERNET_ERROR_BASE + 159)
ERROR_INTERNET_DISCONNECTED                     EQU     (INTERNET_ERROR_BASE + 163)
ERROR_INTERNET_SERVER_UNREACHABLE               EQU     (INTERNET_ERROR_BASE + 164)
ERROR_INTERNET_PROXY_SERVER_UNREACHABLE         EQU     (INTERNET_ERROR_BASE + 165)
ERROR_INTERNET_BAD_AUTO_PROXY_SCRIPT            EQU     (INTERNET_ERROR_BASE + 166)
ERROR_INTERNET_UNABLE_TO_DOWNLOAD_SCRIPT        EQU     (INTERNET_ERROR_BASE + 167)
ERROR_INTERNET_SEC_INVALID_CERT                 EQU     (INTERNET_ERROR_BASE + 169)
ERROR_INTERNET_SEC_CERT_REVOKED                 EQU     (INTERNET_ERROR_BASE + 170)
ERROR_INTERNET_FAILED_DUETOSECURITYCHECK        EQU     (INTERNET_ERROR_BASE + 171)
ERROR_INTERNET_NOT_INITIALIZED                  EQU     (INTERNET_ERROR_BASE + 172)
ERROR_INTERNET_NEED_MSN_SSPI_PKG                EQU     (INTERNET_ERROR_BASE + 173)
ERROR_INTERNET_LOGIN_FAILURE_DISPLAY_ENTITY_BODY EQU    (INTERNET_ERROR_BASE + 174)
INTERNET_ERROR_LAST                             EQU     ERROR_INTERNET_LOGIN_FAILURE_DISPLAY_ENTITY_BODY

IFDEF APP_WIN64
    E_NOTIMPL                                   EQU     80000001H
    E_OUTOFMEMORY                               EQU     80000002H
    E_INVALIDARG                                EQU     80000003H
    E_NOINTERFACE                               EQU     80000004H
    E_POINTER                                   EQU     80000005H
    E_HANDLE                                    EQU     80000006H
    E_ABORT                                     EQU     80000007H
    E_FAIL                                      EQU     80000008H
    E_ACCESSDENIED                              EQU     80000009H
ELSE
    NOERROR                                     EQU     0
    E_NOTIMPL                                   EQU     80004001H
    E_OUTOFMEMORY                               EQU     8007000EH
    E_INVALIDARG                                EQU     80070057H
    E_NOINTERFACE                               EQU     80004002H
    E_POINTER                                   EQU     80004003H
    E_HANDLE                                    EQU     80070006H
    E_ABORT                                     EQU     80004004H
    E_FAIL                                      EQU     80004005H
    E_ACCESSDENIED                              EQU     80070005H
ENDIF

E_PENDING                                       EQU     8000000AH


CO_E_INIT_TLS                                   EQU     80004006H
CO_E_INIT_SHARED_ALLOCATOR                      EQU     80004007H
CO_E_INIT_MEMORY_ALLOCATOR                      EQU     80004008H
CO_E_INIT_CLASS_CACHE                           EQU     80004009H
CO_E_INIT_RPC_CHANNEL                           EQU     8000400AH
CO_E_INIT_TLS_SET_CHANNEL_CONTROL               EQU     8000400BH
CO_E_INIT_TLS_CHANNEL_CONTROL                   EQU     8000400CH
CO_E_INIT_UNACCEPTED_USER_ALLOCATOR             EQU     8000400DH
CO_E_INIT_SCM_MUTEX_EXISTS                      EQU     8000400EH
CO_E_INIT_SCM_FILE_MAPPING_EXISTS               EQU     8000400FH
CO_E_INIT_SCM_MAP_VIEW_OF_FILE                  EQU     80004010H
CO_E_INIT_SCM_EXEC_FAILURE                      EQU     80004011H
CO_E_INIT_ONLY_SINGLE_THREADED                  EQU     80004012H
CO_E_CANT_REMOTE                                EQU     80004013H
CO_E_BAD_SERVER_NAME                            EQU     80004014H
CO_E_WRONG_SERVER_IDENTITY                      EQU     80004015H
CO_E_OLE1DDE_DISABLED                           EQU     80004016H
CO_E_RUNAS_SYNTAX                               EQU     80004017H
CO_E_CREATEPROCESS_FAILURE                      EQU     80004018H
CO_E_RUNAS_CREATEPROCESS_FAILURE                EQU     80004019H
CO_E_RUNAS_LOGON_FAILURE                        EQU     8000401AH
CO_E_LAUNCH_PERMSSION_DENIED                    EQU     8000401BH
CO_E_START_SERVICE_FAILURE                      EQU     8000401CH
CO_E_REMOTE_COMMUNICATION_FAILURE               EQU     8000401DH
CO_E_SERVER_START_TIMEOUT                       EQU     8000401EH
CO_E_CLSREG_INCONSISTENT                        EQU     8000401FH
CO_E_IIDREG_INCONSISTENT                        EQU     80004020H
CO_E_NOT_SUPPORTED                              EQU     80004021H
CO_E_RELOAD_DLL                                 EQU     80004022H
CO_E_MSI_ERROR                                  EQU     80004023H
CO_E_ATTEMPT_TO_CREATE_OUTSIDE_CLIENT_CONTEXT   EQU     80004024H
CO_E_SERVER_PAUSED                              EQU     80004025H
CO_E_SERVER_NOT_PAUSED                          EQU     80004026H
CO_E_CLASS_DISABLED                             EQU     80004027H
CO_E_CLRNOTAVAILABLE                            EQU     80004028H
CO_E_ASYNC_WORK_REJECTED                        EQU     80004029H
CO_E_SERVER_INIT_TIMEOUT                        EQU     8000402AH
CO_E_NO_SECCTX_IN_ACTIVATE                      EQU     8000402BH
CO_E_TRACKER_CONFIG                             EQU     80004030H
CO_E_THREADPOOL_CONFIG                          EQU     80004031H
CO_E_SXS_CONFIG                                 EQU     80004032H
CO_E_MALFORMED_SPN                              EQU     80004033H
CO_E_FAILEDTOIMPERSONATE                        EQU     80010123H
CO_E_FAILEDTOGETSECCTX                          EQU     80010124H
CO_E_FAILEDTOOPENTHREADTOKEN                    EQU     80010125H
CO_E_FAILEDTOGETTOKENINFO                       EQU     80010126H
CO_E_TRUSTEEDOESNTMATCHCLIENT                   EQU     80010127H
CO_E_FAILEDTOQUERYCLIENTBLANKET                 EQU     80010128H
CO_E_FAILEDTOSETDACL                            EQU     80010129H
CO_E_ACCESSCHECKFAILED                          EQU     8001012AH
CO_E_NETACCESSAPIFAILED                         EQU     8001012BH
CO_E_WRONGTRUSTEENAMESYNTAX                     EQU     8001012CH
CO_E_INVALIDSID                                 EQU     8001012DH
CO_E_CONVERSIONFAILED                           EQU     8001012EH
CO_E_NOMATCHINGSIDFOUND                         EQU     8001012FH
CO_E_LOOKUPACCSIDFAILED                         EQU     80010130H
CO_E_NOMATCHINGNAMEFOUND                        EQU     80010131H
CO_E_LOOKUPACCNAMEFAILED                        EQU     80010132H
CO_E_SETSERLHNDLFAILED                          EQU     80010133H
CO_E_FAILEDTOGETWINDIR                          EQU     80010134H
CO_E_PATHTOOLONG                                EQU     80010135H
CO_E_FAILEDTOGENUUID                            EQU     80010136H
CO_E_FAILEDTOCREATEFILE                         EQU     80010137H
CO_E_FAILEDTOCLOSEHANDLE                        EQU     80010138H
CO_E_EXCEEDSYSACLLIMIT                          EQU     80010139H
CO_E_ACESINWRONGORDER                           EQU     8001013AH
CO_E_INCOMPATIBLESTREAMVERSION                  EQU     8001013BH
CO_E_FAILEDTOOPENPROCESSTOKEN                   EQU     8001013CH
CO_E_DECODEFAILED                               EQU     8001013DH
CO_E_ACNOTINITIALIZED                           EQU     8001013FH
CO_E_CANCEL_DISABLED                            EQU     80010140H

S_OK                                            EQU     0
S_FALSE                                         EQU     1

OLE_E_FIRST                                     EQU     80040000H
OLE_E_LAST                                      EQU     800400FFH
OLE_S_FIRST                                     EQU     00040000H
OLE_S_LAST                                      EQU     000400FFH
OLE_E_OLEVERB                                   EQU     80040000H
OLE_E_ADVF                                      EQU     80040001H
OLE_E_ENUM_NOMORE                               EQU     80040002H
OLE_E_ADVISENOTSUPPORTED                        EQU     80040003H
OLE_E_NOCONNECTION                              EQU     80040004H
OLE_E_NOTRUNNING                                EQU     80040005H
OLE_E_NOCACHE                                   EQU     80040006H
OLE_E_BLANK                                     EQU     80040007H
OLE_E_CLASSDIFF                                 EQU     80040008H
OLE_E_CANT_GETMONIKER                           EQU     80040009H
OLE_E_CANT_BINDTOSOURCE                         EQU     8004000AH
OLE_E_STATIC                                    EQU     8004000BH
OLE_E_PROMPTSAVECANCELLED                       EQU     8004000CH
OLE_E_INVALIDRECT                               EQU     8004000DH
OLE_E_WRONGCOMPOBJ                              EQU     8004000EH
OLE_E_INVALIDHWND                               EQU     8004000FH
OLE_E_NOT_INPLACEACTIVE                         EQU     80040010H
OLE_E_CANTCONVERT                               EQU     80040011H
OLE_E_NOSTORAGE                                 EQU     80040012H

DV_E_FORMATETC                                  EQU     80040064H
DV_E_DVTARGETDEVICE                             EQU     80040065H
DV_E_STGMEDIUM                                  EQU     80040066H
DV_E_STATDATA                                   EQU     80040067H
DV_E_LINDEX                                     EQU     80040068H
DV_E_TYMED                                      EQU     80040069H
DV_E_CLIPFORMAT                                 EQU     8004006AH
DV_E_DVASPECT                                   EQU     8004006BH
DV_E_DVTARGETDEVICE_SIZE                        EQU     8004006CH
DV_E_NOIVIEWOBJECT                              EQU     8004006DH

DRAGDROP_E_FIRST                                EQU     80040100H
DRAGDROP_E_LAST                                 EQU     8004010FH
DRAGDROP_S_FIRST                                EQU     00040100H
DRAGDROP_S_LAST                                 EQU     0004010FH
DRAGDROP_E_NOTREGISTERED                        EQU     80040100H
DRAGDROP_E_ALREADYREGISTERED                    EQU     80040101H
DRAGDROP_E_INVALIDHWND                          EQU     80040102H

CLASSFACTORY_E_FIRST                            EQU     80040110H
CLASSFACTORY_E_LAST                             EQU     8004011FH
CLASSFACTORY_S_FIRST                            EQU     00040110H
CLASSFACTORY_S_LAST                             EQU     0004011FH

CLASS_E_NOAGGREGATION                           EQU     80040110H
CLASS_E_CLASSNOTAVAILABLE                       EQU     80040111H
CLASS_E_NOTLICENSED                             EQU     80040112H

MARSHAL_E_FIRST                                 EQU     80040120H
MARSHAL_E_LAST                                  EQU     8004012FH
MARSHAL_S_FIRST                                 EQU     00040120H
MARSHAL_S_LAST                                  EQU     0004012FH

DATA_E_FIRST                                    EQU     80040130H
DATA_E_LAST                                     EQU     8004013FH
DATA_S_FIRST                                    EQU     00040130H
DATA_S_LAST                                     EQU     0004013FH

VIEW_E_FIRST                                    EQU     80040140H
VIEW_E_LAST                                     EQU     8004014FH
VIEW_S_FIRST                                    EQU     00040140H
VIEW_S_LAST                                     EQU     0004014FH
VIEW_E_DRAW                                     EQU     80040140H

REGDB_E_FIRST                                   EQU     80040150H
REGDB_E_LAST                                    EQU     8004015FH
REGDB_S_FIRST                                   EQU     00040150H
REGDB_S_LAST                                    EQU     0004015FH
REGDB_E_READREGDB                               EQU     80040150H
REGDB_E_WRITEREGDB                              EQU     80040151H
REGDB_E_KEYMISSING                              EQU     80040152H
REGDB_E_INVALIDVALUE                            EQU     80040153H
REGDB_E_CLASSNOTREG                             EQU     80040154H
REGDB_E_IIDNOTREG                               EQU     80040155H
REGDB_E_BADTHREADINGMODEL                       EQU     80040156H

CAT_E_FIRST                                     EQU     80040160H
CAT_E_LAST                                      EQU     80040161H
CAT_E_CATIDNOEXIST                              EQU     80040160H
CAT_E_NODESCRIPTION                             EQU     80040161H

CS_E_FIRST                                      EQU     80040164H
CS_E_LAST                                       EQU     8004016FH
CS_E_PACKAGE_NOTFOUND                           EQU     80040164H
CS_E_NOT_DELETABLE                              EQU     80040165H
CS_E_CLASS_NOTFOUND                             EQU     80040166H
CS_E_INVALID_VERSION                            EQU     80040167H
CS_E_NO_CLASSSTORE                              EQU     80040168H
CS_E_OBJECT_NOTFOUND                            EQU     80040169H
CS_E_OBJECT_ALREADY_EXISTS                      EQU     8004016AH
CS_E_INVALID_PATH                               EQU     8004016BH
CS_E_NETWORK_ERROR                              EQU     8004016CH
CS_E_ADMIN_LIMIT_EXCEEDED                       EQU     8004016DH
CS_E_SCHEMA_MISMATCH                            EQU     8004016EH
CS_E_INTERNAL_ERROR                             EQU     8004016FH

CACHE_E_FIRST                                   EQU     80040170H
CACHE_E_LAST                                    EQU     8004017FH
CACHE_S_FIRST                                   EQU     00040170H
CACHE_S_LAST                                    EQU     0004017FH
CACHE_E_NOCACHE_UPDATED                         EQU     80040170H

OLEOBJ_E_FIRST                                  EQU     80040180H
OLEOBJ_E_LAST                                   EQU     8004018FH
OLEOBJ_S_FIRST                                  EQU     00040180H
OLEOBJ_S_LAST                                   EQU     0004018FH
OLEOBJ_E_NOVERBS                                EQU     80040180H
OLEOBJ_E_INVALIDVERB                            EQU     80040181H

CLIENTSITE_E_FIRST                              EQU     80040190H
CLIENTSITE_E_LAST                               EQU     8004019FH
CLIENTSITE_S_FIRST                              EQU     00040190H
CLIENTSITE_S_LAST                               EQU     0004019FH

INPLACE_E_NOTUNDOABLE                           EQU     800401A0H
INPLACE_E_NOTOOLSPACE                           EQU     800401A1H
INPLACE_E_FIRST                                 EQU     800401A0H
INPLACE_E_LAST                                  EQU     800401AFH
INPLACE_S_FIRST                                 EQU     000401A0H
INPLACE_S_LAST                                  EQU     000401AFH

ENUM_E_FIRST                                    EQU     800401B0H
ENUM_E_LAST                                     EQU     800401BFH
ENUM_S_FIRST                                    EQU     000401B0H
ENUM_S_LAST                                     EQU     000401BFH

CONVERT10_E_FIRST                               EQU     800401C0H
CONVERT10_E_LAST                                EQU     800401CFH
CONVERT10_S_FIRST                               EQU     000401C0H
CONVERT10_S_LAST                                EQU     000401CFH
CONVERT10_E_OLESTREAM_GET                       EQU     800401C0H
CONVERT10_E_OLESTREAM_PUT                       EQU     800401C1H
CONVERT10_E_OLESTREAM_FMT                       EQU     800401C2H
CONVERT10_E_OLESTREAM_BITMAP_TO_DIB             EQU     800401C3H
CONVERT10_E_STG_FMT                             EQU     800401C4H
CONVERT10_E_STG_NO_STD_STREAM                   EQU     800401C5H
CONVERT10_E_STG_DIB_TO_BITMAP                   EQU     800401C6H

CLIPBRD_E_FIRST                                 EQU     800401D0H
CLIPBRD_E_LAST                                  EQU     800401DFH
CLIPBRD_S_FIRST                                 EQU     000401D0H
CLIPBRD_S_LAST                                  EQU     000401DFH
CLIPBRD_E_CANT_OPEN                             EQU     800401D0H
CLIPBRD_E_CANT_EMPTY                            EQU     800401D1H
CLIPBRD_E_CANT_SET                              EQU     800401D2H
CLIPBRD_E_BAD_DATA                              EQU     800401D3H
CLIPBRD_E_CANT_CLOSE                            EQU     800401D4H

MK_E_FIRST                                      EQU     800401E0H
MK_E_LAST                                       EQU     800401EFH
MK_S_FIRST                                      EQU     000401E0H
MK_S_LAST                                       EQU     000401EFH
MK_E_CONNECTMANUALLY                            EQU     800401E0H
MK_E_EXCEEDEDDEADLINE                           EQU     800401E1H
MK_E_NEEDGENERIC                                EQU     800401E2H
MK_E_UNAVAILABLE                                EQU     800401E3H
MK_E_SYNTAX                                     EQU     800401E4H
MK_E_NOOBJECT                                   EQU     800401E5H
MK_E_INVALIDEXTENSION                           EQU     800401E6H
MK_E_INTERMEDIATEINTERFACENOTSUPPORTED          EQU     800401E7H
MK_E_NOTBINDABLE                                EQU     800401E8H
MK_E_NOTBOUND                                   EQU     800401E9H
MK_E_CANTOPENFILE                               EQU     800401EAH
MK_E_MUSTBOTHERUSER                             EQU     800401EBH
MK_E_NOINVERSE                                  EQU     800401ECH
MK_E_NOSTORAGE                                  EQU     800401EDH
MK_E_NOPREFIX                                   EQU     800401EEH
MK_E_ENUMERATION_FAILED                         EQU     800401EFH
MK_E_NO_NORMALIZED                              EQU     80080007H

CO_E_FIRST                                      EQU     800401F0H
CO_E_LAST                                       EQU     800401FFH
CO_S_FIRST                                      EQU     000401F0H
CO_S_LAST                                       EQU     000401FFH
CO_E_NOTINITIALIZED                             EQU     800401F0H
CO_E_ALREADYINITIALIZED                         EQU     800401F1H
CO_E_CANTDETERMINECLASS                         EQU     800401F2H
CO_E_CLASSSTRING                                EQU     800401F3H
CO_E_IIDSTRING                                  EQU     800401F4H
CO_E_APPNOTFOUND                                EQU     800401F5H
CO_E_APPSINGLEUSE                               EQU     800401F6H
CO_E_ERRORINAPP                                 EQU     800401F7H
CO_E_DLLNOTFOUND                                EQU     800401F8H
CO_E_ERRORINDLL                                 EQU     800401F9H
CO_E_WRONGOSFORAPP                              EQU     800401FAH
CO_E_OBJNOTREG                                  EQU     800401FBH
CO_E_OBJISREG                                   EQU     800401FCH
CO_E_OBJNOTCONNECTED                            EQU     800401FDH
CO_E_APPDIDNTREG                                EQU     800401FEH
CO_E_RELEASED                                   EQU     800401FFH
CO_E_CLASS_CREATE_FAILED                        EQU     80080001H
CO_E_SCM_ERROR                                  EQU     80080002H
CO_E_SCM_RPC_FAILURE                            EQU     80080003H
CO_E_BAD_PATH                                   EQU     80080004H
CO_E_SERVER_EXEC_FAILURE                        EQU     80080005H
CO_E_OBJSRV_RPC_FAILURE                         EQU     80080006H
CO_E_SERVER_STOPPING                            EQU     80080008H
CO_S_NOTALLINTERFACES                           EQU     00080012H
CO_S_MACHINENAMENOTFOUND                        EQU     00080013H
CO_E_MISSING_DISPLAYNAME                        EQU     80080015H
CO_E_RUNAS_VALUE_MUST_BE_AAA                    EQU     80080016H
CO_E_ELEVATION_DISABLED                         EQU     80080017H

EVENT_E_FIRST                                   EQU     80040200H
EVENT_E_LAST                                    EQU     8004021FH
EVENT_S_FIRST                                   EQU     00040200H
EVENT_S_LAST                                    EQU     0004021FH
EVENT_S_SOME_SUBSCRIBERS_FAILED                 EQU     00040200H
EVENT_E_ALL_SUBSCRIBERS_FAILED                  EQU     80040201H
EVENT_S_NOSUBSCRIBERS                           EQU     00040202H
EVENT_E_QUERYSYNTAX                             EQU     80040203H
EVENT_E_QUERYFIELD                              EQU     80040204H
EVENT_E_INTERNALEXCEPTION                       EQU     80040205H
EVENT_E_INTERNALERROR                           EQU     80040206H
EVENT_E_INVALID_PER_USER_SID                    EQU     80040207H
EVENT_E_USER_EXCEPTION                          EQU     80040208H
EVENT_E_TOO_MANY_METHODS                        EQU     80040209H
EVENT_E_MISSING_EVENTCLASS                      EQU     8004020AH
EVENT_E_NOT_ALL_REMOVED                         EQU     8004020BH
EVENT_E_COMPLUS_NOT_INSTALLED                   EQU     8004020CH
EVENT_E_CANT_MODIFY_OR_DELETE_UNCONFIGURED_OBJECT EQU   8004020DH
EVENT_E_CANT_MODIFY_OR_DELETE_CONFIGURED_OBJECT EQU     8004020EH
EVENT_E_INVALID_EVENT_CLASS_PARTITION           EQU     8004020FH
EVENT_E_PER_USER_SID_NOT_LOGGED_ON              EQU     80040210H

XACT_E_FIRST                                    EQU     8004D000H
XACT_E_LAST                                     EQU     8004D02BH
XACT_S_FIRST                                    EQU     0004D000H
XACT_S_LAST                                     EQU     0004D010H
XACT_E_ALREADYOTHERSINGLEPHASE                  EQU     8004D000H
XACT_E_CANTRETAIN                               EQU     8004D001H
XACT_E_COMMITFAILED                             EQU     8004D002H
XACT_E_COMMITPREVENTED                          EQU     8004D003H
XACT_E_HEURISTICABORT                           EQU     8004D004H
XACT_E_HEURISTICCOMMIT                          EQU     8004D005H
XACT_E_HEURISTICDAMAGE                          EQU     8004D006H
XACT_E_HEURISTICDANGER                          EQU     8004D007H
XACT_E_ISOLATIONLEVEL                           EQU     8004D008H
XACT_E_NOASYNC                                  EQU     8004D009H
XACT_E_NOENLIST                                 EQU     8004D00AH
XACT_E_NOISORETAIN                              EQU     8004D00BH
XACT_E_NORESOURCE                               EQU     8004D00CH
XACT_E_NOTCURRENT                               EQU     8004D00DH
XACT_E_NOTRANSACTION                            EQU     8004D00EH
XACT_E_NOTSUPPORTED                             EQU     8004D00FH
XACT_E_UNKNOWNRMGRID                            EQU     8004D010H
XACT_E_WRONGSTATE                               EQU     8004D011H
XACT_E_WRONGUOW                                 EQU     8004D012H
XACT_E_XTIONEXISTS                              EQU     8004D013H
XACT_E_NOIMPORTOBJECT                           EQU     8004D014H
XACT_E_INVALIDCOOKIE                            EQU     8004D015H
XACT_E_INDOUBT                                  EQU     8004D016H
XACT_E_NOTIMEOUT                                EQU     8004D017H
XACT_E_ALREADYINPROGRESS                        EQU     8004D018H
XACT_E_ABORTED                                  EQU     8004D019H
XACT_E_LOGFULL                                  EQU     8004D01AH
XACT_E_TMNOTAVAILABLE                           EQU     8004D01BH
XACT_E_CONNECTION_DOWN                          EQU     8004D01CH
XACT_E_CONNECTION_DENIED                        EQU     8004D01DH
XACT_E_REENLISTTIMEOUT                          EQU     8004D01EH
XACT_E_TIP_CONNECT_FAILED                       EQU     8004D01FH
XACT_E_TIP_PROTOCOL_ERROR                       EQU     8004D020H
XACT_E_TIP_PULL_FAILED                          EQU     8004D021H
XACT_E_DEST_TMNOTAVAILABLE                      EQU     8004D022H
XACT_E_TIP_DISABLED                             EQU     8004D023H
XACT_E_NETWORK_TX_DISABLED                      EQU     8004D024H
XACT_E_PARTNER_NETWORK_TX_DISABLED              EQU     8004D025H
XACT_E_XA_TX_DISABLED                           EQU     8004D026H
XACT_E_UNABLE_TO_READ_DTC_CONFIG                EQU     8004D027H
XACT_E_UNABLE_TO_LOAD_DTC_PROXY                 EQU     8004D028H
XACT_E_ABORTING                                 EQU     8004D029H
XACT_E_PUSH_COMM_FAILURE                        EQU     8004D02AH
XACT_E_PULL_COMM_FAILURE                        EQU     8004D02BH
XACT_E_LU_TX_DISABLED                           EQU     8004D02CH
XACT_E_CLERKNOTFOUND                            EQU     8004D080H
XACT_E_CLERKEXISTS                              EQU     8004D081H
XACT_E_RECOVERYINPROGRESS                       EQU     8004D082H
XACT_E_TRANSACTIONCLOSED                        EQU     8004D083H
XACT_E_INVALIDLSN                               EQU     8004D084H
XACT_E_REPLAYREQUEST                            EQU     8004D085H
XACT_S_ASYNC                                    EQU     0004D000H
XACT_S_DEFECT                                   EQU     0004D001H
XACT_S_READONLY                                 EQU     0004D002H
XACT_S_SOMENORETAIN                             EQU     0004D003H
XACT_S_OKINFORM                                 EQU     0004D004H
XACT_S_MADECHANGESCONTENT                       EQU     0004D005H
XACT_S_MADECHANGESINFORM                        EQU     0004D006H
XACT_S_ALLNORETAIN                              EQU     0004D007H
XACT_S_ABORTING                                 EQU     0004D008H
XACT_S_SINGLEPHASE                              EQU     0004D009H
XACT_S_LOCALLY_OK                               EQU     0004D00AH
XACT_S_LASTRESOURCEMANAGER                      EQU     0004D010H

CONTEXT_E_FIRST                                 EQU     8004E000H
CONTEXT_E_LAST                                  EQU     8004E02FH
CONTEXT_S_FIRST                                 EQU     0004E000H
CONTEXT_S_LAST                                  EQU     0004E02FH
CONTEXT_E_ABORTED                               EQU     8004E002H
CONTEXT_E_ABORTING                              EQU     8004E003H
CONTEXT_E_NOCONTEXT                             EQU     8004E004H
CONTEXT_E_WOULD_DEADLOCK                        EQU     8004E005H
CONTEXT_E_SYNCH_TIMEOUT                         EQU     8004E006H
CONTEXT_E_OLDREF                                EQU     8004E007H
CONTEXT_E_ROLENOTFOUND                          EQU     8004E00CH
CONTEXT_E_TMNOTAVAILABLE                        EQU     8004E00FH
CONTEXT_E_NOJIT                                 EQU     8004E026H
CONTEXT_E_NOTRANSACTION                         EQU     8004E027H

CO_E_ACTIVATIONFAILED                           EQU     8004E021H
CO_E_ACTIVATIONFAILED_EVENTLOGGED               EQU     8004E022H
CO_E_ACTIVATIONFAILED_CATALOGERROR              EQU     8004E023H
CO_E_ACTIVATIONFAILED_TIMEOUT                   EQU     8004E024H
CO_E_INITIALIZATIONFAILED                       EQU     8004E025H
CO_E_THREADINGMODEL_CHANGED                     EQU     8004E028H
CO_E_NOIISINTRINSICS                            EQU     8004E029H
CO_E_NOCOOKIES                                  EQU     8004E02AH
CO_E_DBERROR                                    EQU     8004E02BH
CO_E_NOTPOOLED                                  EQU     8004E02CH
CO_E_NOTCONSTRUCTED                             EQU     8004E02DH
CO_E_NOSYNCHRONIZATION                          EQU     8004E02EH
CO_E_ISOLEVELMISMATCH                           EQU     8004E02FH
CO_E_CALL_OUT_OF_TX_SCOPE_NOT_ALLOWED           EQU     8004E030H
CO_E_EXIT_TRANSACTION_SCOPE_NOT_CALLED          EQU     8004E031H

OLE_S_USEREG                                    EQU     00040000H
OLE_S_STATIC                                    EQU     00040001H
OLE_S_MAC_CLIPFORMAT                            EQU     00040002H

DRAGDROP_S_DROP                                 EQU     00040100H
DRAGDROP_S_CANCEL                               EQU     00040101H
DRAGDROP_S_USEDEFAULTCURSORS                    EQU     00040102H

DATA_S_SAMEFORMATETC                            EQU     00040130H
VIEW_S_ALREADY_FROZEN                           EQU     00040140H

CACHE_S_FORMATETC_NOTSUPPORTED                  EQU     00040170H
CACHE_S_SAMECACHE                               EQU     00040171H
CACHE_S_SOMECACHES_NOTUPDATED                   EQU     00040172H

OLEOBJ_S_INVALIDVERB                            EQU     00040180H
OLEOBJ_S_CANNOT_DOVERB_NOW                      EQU     00040181H
OLEOBJ_S_INVALIDHWND                            EQU     00040182H

INPLACE_S_TRUNCATED                             EQU     000401A0H
CONVERT10_S_NO_PRESENTATION                     EQU     000401C0H

MK_S_REDUCED_TO_SELF                            EQU     000401E2H
MK_S_ME                                         EQU     000401E4H
MK_S_HIM                                        EQU     000401E5H
MK_S_US                                         EQU     000401E6H
MK_S_MONIKERALREADYREGISTERED                   EQU     000401E7H

SCHED_S_TASK_READY                              EQU     00041300H
SCHED_S_TASK_RUNNING                            EQU     00041301H
SCHED_S_TASK_DISABLED                           EQU     00041302H
SCHED_S_TASK_HAS_NOT_RUN                        EQU     00041303H
SCHED_S_TASK_NO_MORE_RUNS                       EQU     00041304H
SCHED_S_TASK_NOT_SCHEDULED                      EQU     00041305H
SCHED_S_TASK_TERMINATED                         EQU     00041306H
SCHED_S_TASK_NO_VALID_TRIGGERS                  EQU     00041307H
SCHED_S_EVENT_TRIGGER                           EQU     00041308H
SCHED_E_TRIGGER_NOT_FOUND                       EQU     80041309H
SCHED_E_TASK_NOT_READY                          EQU     8004130AH
SCHED_E_TASK_NOT_RUNNING                        EQU     8004130BH
SCHED_E_SERVICE_NOT_INSTALLED                   EQU     8004130CH
SCHED_E_CANNOT_OPEN_TASK                        EQU     8004130DH
SCHED_E_INVALID_TASK                            EQU     8004130EH
SCHED_E_ACCOUNT_INFORMATION_NOT_SET             EQU     8004130FH
SCHED_E_ACCOUNT_NAME_NOT_FOUND                  EQU     80041310H
SCHED_E_ACCOUNT_DBASE_CORRUPT                   EQU     80041311H
SCHED_E_NO_SECURITY_SERVICES                    EQU     80041312H
SCHED_E_UNKNOWN_OBJECT_VERSION                  EQU     80041313H
SCHED_E_UNSUPPORTED_ACCOUNT_OPTION              EQU     80041314H
SCHED_E_SERVICE_NOT_RUNNING                     EQU     80041315H
SCHED_E_UNEXPECTEDNODE                          EQU     80041316H
SCHED_E_NAMESPACE                               EQU     80041317H
SCHED_E_INVALIDVALUE                            EQU     80041318H
SCHED_E_MISSINGNODE                             EQU     80041319H
SCHED_E_MALFORMEDXML                            EQU     8004131AH
SCHED_S_SOME_TRIGGERS_FAILED                    EQU     0004131BH
SCHED_S_BATCH_LOGON_PROBLEM                     EQU     0004131CH
SCHED_E_TOO_MANY_NODES                          EQU     8004131DH
SCHED_E_PAST_END_BOUNDARY                       EQU     8004131EH
SCHED_E_ALREADY_RUNNING                         EQU     8004131FH
SCHED_E_USER_NOT_LOGGED_ON                      EQU     80041320H
SCHED_E_INVALID_TASK_HASH                       EQU     80041321H
SCHED_E_SERVICE_NOT_AVAILABLE                   EQU     80041322H
SCHED_E_SERVICE_TOO_BUSY                        EQU     80041323H
SCHED_E_TASK_ATTEMPTED                          EQU     80041324H
SCHED_S_TASK_QUEUED                             EQU     00041325H
SCHED_E_TASK_DISABLED                           EQU     80041326H
SCHED_E_TASK_NOT_V1_COMPAT                      EQU     80041327H
SCHED_E_START_ON_DEMAND                         EQU     80041328H

MEM_E_INVALID_ROOT                              EQU     80080009H
MEM_E_INVALID_LINK                              EQU     80080010H
MEM_E_INVALID_SIZE                              EQU     80080011H

DISP_E_UNKNOWNINTERFACE                         EQU     80020001H
DISP_E_MEMBERNOTFOUND                           EQU     80020003H
DISP_E_PARAMNOTFOUND                            EQU     80020004H
DISP_E_TYPEMISMATCH                             EQU     80020005H
DISP_E_UNKNOWNNAME                              EQU     80020006H
DISP_E_NONAMEDARGS                              EQU     80020007H
DISP_E_BADVARTYPE                               EQU     80020008H
DISP_E_EXCEPTION                                EQU     80020009H
DISP_E_OVERFLOW                                 EQU     8002000AH
DISP_E_BADINDEX                                 EQU     8002000BH
DISP_E_UNKNOWNLCID                              EQU     8002000CH
DISP_E_ARRAYISLOCKED                            EQU     8002000DH
DISP_E_BADPARAMCOUNT                            EQU     8002000EH
DISP_E_PARAMNOTOPTIONAL                         EQU     8002000FH
DISP_E_BADCALLEE                                EQU     80020010H
DISP_E_NOTACOLLECTION                           EQU     80020011H
DISP_E_DIVBYZERO                                EQU     80020012H
DISP_E_BUFFERTOOSMALL                           EQU     80020013H

TYPE_E_BUFFERTOOSMALL                           EQU     80028016H
TYPE_E_FIELDNOTFOUND                            EQU     80028017H
TYPE_E_INVDATAREAD                              EQU     80028018H
TYPE_E_UNSUPFORMAT                              EQU     80028019H
TYPE_E_REGISTRYACCESS                           EQU     8002801CH
TYPE_E_LIBNOTREGISTERED                         EQU     8002801DH
TYPE_E_UNDEFINEDTYPE                            EQU     80028027H
TYPE_E_QUALIFIEDNAMEDISALLOWED                  EQU     80028028H
TYPE_E_INVALIDSTATE                             EQU     80028029H
TYPE_E_WRONGTYPEKIND                            EQU     8002802AH
TYPE_E_ELEMENTNOTFOUND                          EQU     8002802BH
TYPE_E_AMBIGUOUSNAME                            EQU     8002802CH
TYPE_E_NAMECONFLICT                             EQU     8002802DH
TYPE_E_UNKNOWNLCID                              EQU     8002802EH
TYPE_E_DLLFUNCTIONNOTFOUND                      EQU     8002802FH
TYPE_E_BADMODULEKIND                            EQU     800288BDH
TYPE_E_SIZETOOBIG                               EQU     800288C5H
TYPE_E_DUPLICATEID                              EQU     800288C6H
TYPE_E_INVALIDID                                EQU     800288CFH
TYPE_E_TYPEMISMATCH                             EQU     80028CA0H
TYPE_E_OUTOFBOUNDS                              EQU     80028CA1H
TYPE_E_IOERROR                                  EQU     80028CA2H
TYPE_E_CANTCREATETMPFILE                        EQU     80028CA3H
TYPE_E_CANTLOADLIBRARY                          EQU     80029C4AH
TYPE_E_INCONSISTENTPROPFUNCS                    EQU     80029C83H
TYPE_E_CIRCULARTYPE                             EQU     80029C84H

STG_E_INVALIDFUNCTION                           EQU     80030001H
STG_E_FILENOTFOUND                              EQU     80030002H
STG_E_PATHNOTFOUND                              EQU     80030003H
STG_E_TOOMANYOPENFILES                          EQU     80030004H
STG_E_ACCESSDENIED                              EQU     80030005H
STG_E_INVALIDHANDLE                             EQU     80030006H
STG_E_INSUFFICIENTMEMORY                        EQU     80030008H
STG_E_INVALIDPOINTER                            EQU     80030009H
STG_E_NOMOREFILES                               EQU     80030012H
STG_E_DISKISWRITEPROTECTED                      EQU     80030013H
STG_E_SEEKERROR                                 EQU     80030019H
STG_E_WRITEFAULT                                EQU     8003001DH
STG_E_READFAULT                                 EQU     8003001EH
STG_E_SHAREVIOLATION                            EQU     80030020H
STG_E_LOCKVIOLATION                             EQU     80030021H
STG_E_FILEALREADYEXISTS                         EQU     80030050H
STG_E_INVALIDPARAMETER                          EQU     80030057H
STG_E_MEDIUMFULL                                EQU     80030070H
STG_E_PROPSETMISMATCHED                         EQU     800300F0H
STG_E_ABNORMALAPIEXIT                           EQU     800300FAH
STG_E_INVALIDHEADER                             EQU     800300FBH
STG_E_INVALIDNAME                               EQU     800300FCH
STG_E_UNKNOWN                                   EQU     800300FDH
STG_E_UNIMPLEMENTEDFUNCTION                     EQU     800300FEH
STG_E_INVALIDFLAG                               EQU     800300FFH
STG_E_INUSE                                     EQU     80030100H
STG_E_NOTCURRENT                                EQU     80030101H
STG_E_REVERTED                                  EQU     80030102H
STG_E_CANTSAVE                                  EQU     80030103H
STG_E_OLDFORMAT                                 EQU     80030104H
STG_E_OLDDLL                                    EQU     80030105H
STG_E_SHAREREQUIRED                             EQU     80030106H
STG_E_NOTFILEBASEDSTORAGE                       EQU     80030107H
STG_E_EXTANTMARSHALLINGS                        EQU     80030108H
STG_E_DOCFILECORRUPT                            EQU     80030109H
STG_E_BADBASEADDRESS                            EQU     80030110H
STG_E_DOCFILETOOLARGE                           EQU     80030111H
STG_E_NOTSIMPLEFORMAT                           EQU     80030112H
STG_E_INCOMPLETE                                EQU     80030201H
STG_E_TERMINATED                                EQU     80030202H
STG_S_CONVERTED                                 EQU     00030200H
STG_S_BLOCK                                     EQU     00030201H
STG_S_RETRYNOW                                  EQU     00030202H
STG_S_MONITORING                                EQU     00030203H
STG_S_MULTIPLEOPENS                             EQU     00030204H
STG_S_CONSOLIDATIONFAILED                       EQU     00030205H
STG_S_CANNOTCONSOLIDATE                         EQU     00030206H
STG_E_STATUS_COPY_PROTECTION_FAILURE            EQU     80030305H
STG_E_CSS_AUTHENTICATION_FAILURE                EQU     80030306H
STG_E_CSS_KEY_NOT_PRESENT                       EQU     80030307H
STG_E_CSS_KEY_NOT_ESTABLISHED                   EQU     80030308H
STG_E_CSS_SCRAMBLED_SECTOR                      EQU     80030309H
STG_E_CSS_REGION_MISMATCH                       EQU     8003030AH
STG_E_RESETS_EXHAUSTED                          EQU     8003030BH

RPC_E_CALL_REJECTED                             EQU     80010001H
RPC_E_CALL_CANCELED                             EQU     80010002H
RPC_E_CANTPOST_INSENDCALL                       EQU     80010003H
RPC_E_CANTCALLOUT_INASYNCCALL                   EQU     80010004H
RPC_E_CANTCALLOUT_INEXTERNALCALL                EQU     80010005H
RPC_E_CONNECTION_TERMINATED                     EQU     80010006H
RPC_E_SERVER_DIED                               EQU     80010007H
RPC_E_CLIENT_DIED                               EQU     80010008H
RPC_E_INVALID_DATAPACKET                        EQU     80010009H
RPC_E_CANTTRANSMIT_CALL                         EQU     8001000AH
RPC_E_CLIENT_CANTMARSHAL_DATA                   EQU     8001000BH
RPC_E_CLIENT_CANTUNMARSHAL_DATA                 EQU     8001000CH
RPC_E_SERVER_CANTMARSHAL_DATA                   EQU     8001000DH
RPC_E_SERVER_CANTUNMARSHAL_DATA                 EQU     8001000EH
RPC_E_INVALID_DATA                              EQU     8001000FH
RPC_E_INVALID_PARAMETER                         EQU     80010010H
RPC_E_CANTCALLOUT_AGAIN                         EQU     80010011H
RPC_E_SERVER_DIED_DNE                           EQU     80010012H
RPC_E_SYS_CALL_FAILED                           EQU     80010100H
RPC_E_OUT_OF_RESOURCES                          EQU     80010101H
RPC_E_ATTEMPTED_MULTITHREAD                     EQU     80010102H
RPC_E_NOT_REGISTERED                            EQU     80010103H
RPC_E_FAULT                                     EQU     80010104H
RPC_E_SERVERFAULT                               EQU     80010105H
RPC_E_CHANGED_MODE                              EQU     80010106H
RPC_E_INVALIDMETHOD                             EQU     80010107H
RPC_E_DISCONNECTED                              EQU     80010108H
RPC_E_RETRY                                     EQU     80010109H
RPC_E_SERVERCALL_RETRYLATER                     EQU     8001010AH
RPC_E_SERVERCALL_REJECTED                       EQU     8001010BH
RPC_E_INVALID_CALLDATA                          EQU     8001010CH
RPC_E_CANTCALLOUT_ININPUTSYNCCALL               EQU     8001010DH
RPC_E_WRONG_THREAD                              EQU     8001010EH
RPC_E_THREAD_NOT_INIT                           EQU     8001010FH
RPC_E_VERSION_MISMATCH                          EQU     80010110H
RPC_E_INVALID_HEADER                            EQU     80010111H
RPC_E_INVALID_EXTENSION                         EQU     80010112H
RPC_E_INVALID_IPID                              EQU     80010113H
RPC_E_INVALID_OBJECT                            EQU     80010114H
RPC_S_CALLPENDING                               EQU     80010115H
RPC_S_WAITONTIMER                               EQU     80010116H
RPC_E_CALL_COMPLETE                             EQU     80010117H
RPC_E_UNSECURE_CALL                             EQU     80010118H
RPC_E_TOO_LATE                                  EQU     80010119H
RPC_E_NO_GOOD_SECURITY_PACKAGES                 EQU     8001011AH
RPC_E_ACCESS_DENIED                             EQU     8001011BH
RPC_E_REMOTE_DISABLED                           EQU     8001011CH
RPC_E_INVALID_OBJREF                            EQU     8001011DH
RPC_E_NO_CONTEXT                                EQU     8001011EH
RPC_E_TIMEOUT                                   EQU     8001011FH
RPC_E_NO_SYNC                                   EQU     80010120H
RPC_E_FULLSIC_REQUIRED                          EQU     80010121H
RPC_E_INVALID_STD_NAME                          EQU     80010122H
RPC_E_UNEXPECTED                                EQU     8001FFFFH

ERROR_AUDITING_DISABLED                         EQU     0C0090001H

ERROR_ALL_SIDS_FILTERED                         EQU     0C0090002H
ERROR_BIZRULES_NOT_ENABLED                      EQU     0C0090003H
NTE_BAD_UID                                     EQU     80090001H
NTE_BAD_HASH                                    EQU     80090002H
NTE_BAD_KEY                                     EQU     80090003H
NTE_BAD_LEN                                     EQU     80090004H
NTE_BAD_DATA                                    EQU     80090005H
NTE_BAD_SIGNATURE                               EQU     80090006H
NTE_BAD_VER                                     EQU     80090007H
NTE_BAD_ALGID                                   EQU     80090008H
NTE_BAD_FLAGS                                   EQU     80090009H
NTE_BAD_TYPE                                    EQU     8009000AH
NTE_BAD_KEY_STATE                               EQU     8009000BH
NTE_BAD_HASH_STATE                              EQU     8009000CH
NTE_NO_KEY                                      EQU     8009000DH
NTE_NO_MEMORY                                   EQU     8009000EH
NTE_EXISTS                                      EQU     8009000FH
NTE_PERM                                        EQU     80090010H
NTE_NOT_FOUND                                   EQU     80090011H
NTE_DOUBLE_ENCRYPT                              EQU     80090012H
NTE_BAD_PROVIDER                                EQU     80090013H
NTE_BAD_PROV_TYPE                               EQU     80090014H
NTE_BAD_PUBLIC_KEY                              EQU     80090015H
NTE_BAD_KEYSET                                  EQU     80090016H
NTE_PROV_TYPE_NOT_DEF                           EQU     80090017H
NTE_PROV_TYPE_ENTRY_BAD                         EQU     80090018H
NTE_KEYSET_NOT_DEF                              EQU     80090019H
NTE_KEYSET_ENTRY_BAD                            EQU     8009001AH
NTE_PROV_TYPE_NO_MATCH                          EQU     8009001BH
NTE_SIGNATURE_FILE_BAD                          EQU     8009001CH
NTE_PROVIDER_DLL_FAIL                           EQU     8009001DH
NTE_PROV_DLL_NOT_FOUND                          EQU     8009001EH
NTE_BAD_KEYSET_PARAM                            EQU     8009001FH
NTE_FAIL                                        EQU     80090020H
NTE_SYS_ERR                                     EQU     80090021H
NTE_SILENT_CONTEXT                              EQU     80090022H
NTE_TOKEN_KEYSET_STORAGE_FULL                   EQU     80090023H
NTE_TEMPORARY_PROFILE                           EQU     80090024H
NTE_FIXEDPARAMETER                              EQU     80090025H
NTE_INVALID_HANDLE                              EQU     80090026H
NTE_INVALID_PARAMETER                           EQU     80090027H
NTE_BUFFER_TOO_SMALL                            EQU     80090028H
NTE_NOT_SUPPORTED                               EQU     80090029H
NTE_NO_MORE_ITEMS                               EQU     8009002AH
NTE_BUFFERS_OVERLAP                             EQU     8009002BH
NTE_DECRYPTION_FAILURE                          EQU     8009002CH
NTE_INTERNAL_ERROR                              EQU     8009002DH
NTE_UI_REQUIRED                                 EQU     8009002EH
NTE_HMAC_NOT_SUPPORTED                          EQU     8009002FH

SEC_E_INSUFFICIENT_MEMORY                       EQU     80090300H
SEC_E_INVALID_HANDLE                            EQU     80090301H
SEC_E_UNSUPPORTED_FUNCTION                      EQU     80090302H
SEC_E_TARGET_UNKNOWN                            EQU     80090303H
SEC_E_INTERNAL_ERROR                            EQU     80090304H
SEC_E_SECPKG_NOT_FOUND                          EQU     80090305H
SEC_E_NOT_OWNER                                 EQU     80090306H
SEC_E_CANNOT_INSTALL                            EQU     80090307H
SEC_E_INVALID_TOKEN                             EQU     80090308H
SEC_E_CANNOT_PACK                               EQU     80090309H
SEC_E_QOP_NOT_SUPPORTED                         EQU     8009030AH
SEC_E_NO_IMPERSONATION                          EQU     8009030BH
SEC_E_LOGON_DENIED                              EQU     8009030CH
SEC_E_UNKNOWN_CREDENTIALS                       EQU     8009030DH
SEC_E_NO_CREDENTIALS                            EQU     8009030EH
SEC_E_MESSAGE_ALTERED                           EQU     8009030FH
SEC_E_OUT_OF_SEQUENCE                           EQU     80090310H
SEC_E_NO_AUTHENTICATING_AUTHORITY               EQU     80090311H
SEC_I_CONTINUE_NEEDED                           EQU     00090312H
SEC_I_COMPLETE_NEEDED                           EQU     00090313H
SEC_I_COMPLETE_AND_CONTINUE                     EQU     00090314H
SEC_I_LOCAL_LOGON                               EQU     00090315H
SEC_E_BAD_PKGID                                 EQU     80090316H
SEC_E_CONTEXT_EXPIRED                           EQU     80090317H
SEC_I_CONTEXT_EXPIRED                           EQU     00090317H
SEC_E_INCOMPLETE_MESSAGE                        EQU     80090318H
SEC_E_INCOMPLETE_CREDENTIALS                    EQU     80090320H
SEC_E_BUFFER_TOO_SMALL                          EQU     80090321H
SEC_I_INCOMPLETE_CREDENTIALS                    EQU     00090320H
SEC_I_RENEGOTIATE                               EQU     00090321H
SEC_E_WRONG_PRINCIPAL                           EQU     80090322H
SEC_I_NO_LSA_CONTEXT                            EQU     00090323H
SEC_E_TIME_SKEW                                 EQU     80090324H
SEC_E_UNTRUSTED_ROOT                            EQU     80090325H
SEC_E_ILLEGAL_MESSAGE                           EQU     80090326H
SEC_E_CERT_UNKNOWN                              EQU     80090327H
SEC_E_CERT_EXPIRED                              EQU     80090328H
SEC_E_ENCRYPT_FAILURE                           EQU     80090329H
SEC_E_DECRYPT_FAILURE                           EQU     80090330H
SEC_E_ALGORITHM_MISMATCH                        EQU     80090331H
SEC_E_SECURITY_QOS_FAILED                       EQU     80090332H
SEC_E_UNFINISHED_CONTEXT_DELETED                EQU     80090333H
SEC_E_NO_TGT_REPLY                              EQU     80090334H
SEC_E_NO_IP_ADDRESSES                           EQU     80090335H
SEC_E_WRONG_CREDENTIAL_HANDLE                   EQU     80090336H
SEC_E_CRYPTO_SYSTEM_INVALID                     EQU     80090337H
SEC_E_MAX_REFERRALS_EXCEEDED                    EQU     80090338H
SEC_E_MUST_BE_KDC                               EQU     80090339H
SEC_E_STRONG_CRYPTO_NOT_SUPPORTED               EQU     8009033AH
SEC_E_TOO_MANY_PRINCIPALS                       EQU     8009033BH
SEC_E_NO_PA_DATA                                EQU     8009033CH
SEC_E_PKINIT_NAME_MISMATCH                      EQU     8009033DH
SEC_E_SMARTCARD_LOGON_REQUIRED                  EQU     8009033EH
SEC_E_SHUTDOWN_IN_PROGRESS                      EQU     8009033FH
SEC_E_KDC_INVALID_REQUEST                       EQU     80090340H
SEC_E_KDC_UNABLE_TO_REFER                       EQU     80090341H
SEC_E_KDC_UNKNOWN_ETYPE                         EQU     80090342H
SEC_E_UNSUPPORTED_PREAUTH                       EQU     80090343H
SEC_E_DELEGATION_REQUIRED                       EQU     80090345H
SEC_E_BAD_BINDINGS                              EQU     80090346H
SEC_E_MULTIPLE_ACCOUNTS                         EQU     80090347H
SEC_E_NO_KERB_KEY                               EQU     80090348H
SEC_E_CERT_WRONG_USAGE                          EQU     80090349H
SEC_E_DOWNGRADE_DETECTED                        EQU     80090350H
SEC_E_SMARTCARD_CERT_REVOKED                    EQU     80090351H
SEC_E_ISSUING_CA_UNTRUSTED                      EQU     80090352H
SEC_E_REVOCATION_OFFLINE_C                      EQU     80090353H
SEC_E_PKINIT_CLIENT_FAILURE                     EQU     80090354H
SEC_E_SMARTCARD_CERT_EXPIRED                    EQU     80090355H
SEC_E_NO_S4U_PROT_SUPPORT                       EQU     80090356H
SEC_E_CROSSREALM_DELEGATION_FAILURE             EQU     80090357H
SEC_E_REVOCATION_OFFLINE_KDC                    EQU     80090358H
SEC_E_ISSUING_CA_UNTRUSTED_KDC                  EQU     80090359H
SEC_E_KDC_CERT_EXPIRED                          EQU     8009035AH
SEC_E_KDC_CERT_REVOKED                          EQU     8009035BH
SEC_I_SIGNATURE_NEEDED                          EQU     0009035CH
SEC_E_INVALID_PARAMETER                         EQU     8009035DH
SEC_E_DELEGATION_POLICY                         EQU     8009035EH
SEC_E_POLICY_NLTM_ONLY                          EQU     8009035FH
SEC_I_NO_RENEGOTIATION                          EQU     00090360H
SEC_E_NO_CONTEXT                                EQU     80090361H
SEC_E_PKU2U_CERT_FAILURE                        EQU     80090362H
SEC_E_MUTUAL_AUTH_FAILED                        EQU     80090363H
SEC_E_NO_SPM                                    EQU     SEC_E_INTERNAL_ERROR
SEC_E_NOT_SUPPORTED                             EQU     SEC_E_UNSUPPORTED_FUNCTION

CRYPT_E_MSG_ERROR                               EQU     80091001H
CRYPT_E_UNKNOWN_ALGO                            EQU     80091002H
CRYPT_E_OID_FORMAT                              EQU     80091003H
CRYPT_E_INVALID_MSG_TYPE                        EQU     80091004H
CRYPT_E_UNEXPECTED_ENCODING                     EQU     80091005H
CRYPT_E_AUTH_ATTR_MISSING                       EQU     80091006H
CRYPT_E_HASH_VALUE                              EQU     80091007H
CRYPT_E_INVALID_INDEX                           EQU     80091008H
CRYPT_E_ALREADY_DECRYPTED                       EQU     80091009H
CRYPT_E_NOT_DECRYPTED                           EQU     8009100AH
CRYPT_E_RECIPIENT_NOT_FOUND                     EQU     8009100BH
CRYPT_E_CONTROL_TYPE                            EQU     8009100CH
CRYPT_E_ISSUER_SERIALNUMBER                     EQU     8009100DH
CRYPT_E_SIGNER_NOT_FOUND                        EQU     8009100EH
CRYPT_E_ATTRIBUTES_MISSING                      EQU     8009100FH
CRYPT_E_STREAM_MSG_NOT_READY                    EQU     80091010H
CRYPT_E_STREAM_INSUFFICIENT_DATA                EQU     80091011H
CRYPT_I_NEW_PROTECTION_REQUIRED                 EQU     00091012H
CRYPT_E_BAD_LEN                                 EQU     80092001H
CRYPT_E_BAD_ENCODE                              EQU     80092002H
CRYPT_E_FILE_ERROR                              EQU     80092003H
CRYPT_E_NOT_FOUND                               EQU     80092004H
CRYPT_E_EXISTS                                  EQU     80092005H
CRYPT_E_NO_PROVIDER                             EQU     80092006H
CRYPT_E_SELF_SIGNED                             EQU     80092007H
CRYPT_E_DELETED_PREV                            EQU     80092008H
CRYPT_E_NO_MATCH                                EQU     80092009H
CRYPT_E_UNEXPECTED_MSG_TYPE                     EQU     8009200AH
CRYPT_E_NO_KEY_PROPERTY                         EQU     8009200BH
CRYPT_E_NO_DECRYPT_CERT                         EQU     8009200CH
CRYPT_E_BAD_MSG                                 EQU     8009200DH
CRYPT_E_NO_SIGNER                               EQU     8009200EH
CRYPT_E_PENDING_CLOSE                           EQU     8009200FH
CRYPT_E_REVOKED                                 EQU     80092010H
CRYPT_E_NO_REVOCATION_DLL                       EQU     80092011H
CRYPT_E_NO_REVOCATION_CHECK                     EQU     80092012H
CRYPT_E_REVOCATION_OFFLINE                      EQU     80092013H
CRYPT_E_NOT_IN_REVOCATION_DATABASE              EQU     80092014H
CRYPT_E_INVALID_NUMERIC_STRING                  EQU     80092020H
CRYPT_E_INVALID_PRINTABLE_STRING                EQU     80092021H
CRYPT_E_INVALID_IA5_STRING                      EQU     80092022H
CRYPT_E_INVALID_X500_STRING                     EQU     80092023H
CRYPT_E_NOT_CHAR_STRING                         EQU     80092024H
CRYPT_E_FILERESIZED                             EQU     80092025H
CRYPT_E_SECURITY_SETTINGS                       EQU     80092026H
CRYPT_E_NO_VERIFY_USAGE_DLL                     EQU     80092027H
CRYPT_E_NO_VERIFY_USAGE_CHECK                   EQU     80092028H
CRYPT_E_VERIFY_USAGE_OFFLINE                    EQU     80092029H
CRYPT_E_NOT_IN_CTL                              EQU     8009202AH
CRYPT_E_NO_TRUSTED_SIGNER                       EQU     8009202BH
CRYPT_E_MISSING_PUBKEY_PARA                     EQU     8009202CH
CRYPT_E_OSS_ERROR                               EQU     80093000H
CRYPT_E_ASN1_ERROR                              EQU     80093100H
CRYPT_E_ASN1_INTERNAL                           EQU     80093101H
CRYPT_E_ASN1_EOD                                EQU     80093102H
CRYPT_E_ASN1_CORRUPT                            EQU     80093103H
CRYPT_E_ASN1_LARGE                              EQU     80093104H
CRYPT_E_ASN1_CONSTRAINT                         EQU     80093105H
CRYPT_E_ASN1_MEMORY                             EQU     80093106H
CRYPT_E_ASN1_OVERFLOW                           EQU     80093107H
CRYPT_E_ASN1_BADPDU                             EQU     80093108H
CRYPT_E_ASN1_BADARGS                            EQU     80093109H
CRYPT_E_ASN1_BADREAL                            EQU     8009310AH
CRYPT_E_ASN1_BADTAG                             EQU     8009310BH
CRYPT_E_ASN1_CHOICE                             EQU     8009310CH
CRYPT_E_ASN1_RULE                               EQU     8009310DH
CRYPT_E_ASN1_UTF8                               EQU     8009310EH
CRYPT_E_ASN1_PDU_TYPE                           EQU     80093133H
CRYPT_E_ASN1_NYI                                EQU     80093134H
CRYPT_E_ASN1_EXTENDED                           EQU     80093201H
CRYPT_E_ASN1_NOEOD                              EQU     80093202H

OSS_MORE_BUF                                    EQU     80093001H
OSS_NEGATIVE_UINTEGER                           EQU     80093002H
OSS_PDU_RANGE                                   EQU     80093003H
OSS_MORE_INPUT                                  EQU     80093004H
OSS_DATA_ERROR                                  EQU     80093005H
OSS_BAD_ARG                                     EQU     80093006H
OSS_BAD_VERSION                                 EQU     80093007H
OSS_OUT_MEMORY                                  EQU     80093008H
OSS_PDU_MISMATCH                                EQU     80093009H
OSS_LIMITED                                     EQU     8009300AH
OSS_BAD_PTR                                     EQU     8009300BH
OSS_BAD_TIME                                    EQU     8009300CH
OSS_INDEFINITE_NOT_SUPPORTED                    EQU     8009300DH
OSS_MEM_ERROR                                   EQU     8009300EH
OSS_BAD_TABLE                                   EQU     8009300FH
OSS_TOO_LONG                                    EQU     80093010H
OSS_CONSTRAINT_VIOLATED                         EQU     80093011H
OSS_FATAL_ERROR                                 EQU     80093012H
OSS_ACCESS_SERIALIZATION_ERROR                  EQU     80093013H
OSS_NULL_TBL                                    EQU     80093014H
OSS_NULL_FCN                                    EQU     80093015H
OSS_BAD_ENCRULES                                EQU     80093016H
OSS_UNAVAIL_ENCRULES                            EQU     80093017H
OSS_CANT_OPEN_TRACE_WINDOW                      EQU     80093018H
OSS_UNIMPLEMENTED                               EQU     80093019H
OSS_OID_DLL_NOT_LINKED                          EQU     8009301AH
OSS_CANT_OPEN_TRACE_FILE                        EQU     8009301BH
OSS_TRACE_FILE_ALREADY_OPEN                     EQU     8009301CH
OSS_TABLE_MISMATCH                              EQU     8009301DH
OSS_TYPE_NOT_SUPPORTED                          EQU     8009301EH
OSS_REAL_DLL_NOT_LINKED                         EQU     8009301FH
OSS_REAL_CODE_NOT_LINKED                        EQU     80093020H
OSS_OUT_OF_RANGE                                EQU     80093021H
OSS_COPIER_DLL_NOT_LINKED                       EQU     80093022H
OSS_CONSTRAINT_DLL_NOT_LINKED                   EQU     80093023H
OSS_COMPARATOR_DLL_NOT_LINKED                   EQU     80093024H
OSS_COMPARATOR_CODE_NOT_LINKED                  EQU     80093025H
OSS_MEM_MGR_DLL_NOT_LINKED                      EQU     80093026H
OSS_PDV_DLL_NOT_LINKED                          EQU     80093027H
OSS_PDV_CODE_NOT_LINKED                         EQU     80093028H
OSS_API_DLL_NOT_LINKED                          EQU     80093029H
OSS_BERDER_DLL_NOT_LINKED                       EQU     8009302AH
OSS_PER_DLL_NOT_LINKED                          EQU     8009302BH
OSS_OPEN_TYPE_ERROR                             EQU     8009302CH
OSS_MUTEX_NOT_CREATED                           EQU     8009302DH
OSS_CANT_CLOSE_TRACE_FILE                       EQU     8009302EH

CERTSRV_E_BAD_REQUESTSUBJECT                    EQU     80094001H
CERTSRV_E_NO_REQUEST                            EQU     80094002H
CERTSRV_E_BAD_REQUESTSTATUS                     EQU     80094003H
CERTSRV_E_PROPERTY_EMPTY                        EQU     80094004H
CERTSRV_E_INVALID_CA_CERTIFICATE                EQU     80094005H
CERTSRV_E_SERVER_SUSPENDED                      EQU     80094006H
CERTSRV_E_ENCODING_LENGTH                       EQU     80094007H
CERTSRV_E_ROLECONFLICT                          EQU     80094008H
CERTSRV_E_RESTRICTEDOFFICER                     EQU     80094009H
CERTSRV_E_KEY_ARCHIVAL_NOT_CONFIGURED           EQU     8009400AH
CERTSRV_E_NO_VALID_KRA                          EQU     8009400BH
CERTSRV_E_BAD_REQUEST_KEY_ARCHIVAL              EQU     8009400CH
CERTSRV_E_NO_CAADMIN_DEFINED                    EQU     8009400DH
CERTSRV_E_BAD_RENEWAL_CERT_ATTRIBUTE            EQU     8009400EH
CERTSRV_E_NO_DB_SESSIONS                        EQU     8009400FH
CERTSRV_E_ALIGNMENT_FAULT                       EQU     80094010H
CERTSRV_E_ENROLL_DENIED                         EQU     80094011H
CERTSRV_E_TEMPLATE_DENIED                       EQU     80094012H
CERTSRV_E_DOWNLEVEL_DC_SSL_OR_UPGRADE           EQU     80094013H
CERTSRV_E_ADMIN_DENIED_REQUEST                  EQU     80094014H
CERTSRV_E_NO_POLICY_SERVER                      EQU     80094015H
CERTSRV_E_UNSUPPORTED_CERT_TYPE                 EQU     80094800H
CERTSRV_E_NO_CERT_TYPE                          EQU     80094801H
CERTSRV_E_TEMPLATE_CONFLICT                     EQU     80094802H
CERTSRV_E_SUBJECT_ALT_NAME_REQUIRED             EQU     80094803H
CERTSRV_E_ARCHIVED_KEY_REQUIRED                 EQU     80094804H
CERTSRV_E_SMIME_REQUIRED                        EQU     80094805H
CERTSRV_E_BAD_RENEWAL_SUBJECT                   EQU     80094806H
CERTSRV_E_BAD_TEMPLATE_VERSION                  EQU     80094807H
CERTSRV_E_TEMPLATE_POLICY_REQUIRED              EQU     80094808H
CERTSRV_E_SIGNATURE_POLICY_REQUIRED             EQU     80094809H
CERTSRV_E_SIGNATURE_COUNT                       EQU     8009480AH
CERTSRV_E_SIGNATURE_REJECTED                    EQU     8009480BH
CERTSRV_E_ISSUANCE_POLICY_REQUIRED              EQU     8009480CH
CERTSRV_E_SUBJECT_UPN_REQUIRED                  EQU     8009480DH
CERTSRV_E_SUBJECT_DIRECTORY_GUID_REQUIRED       EQU     8009480EH
CERTSRV_E_SUBJECT_DNS_REQUIRED                  EQU     8009480FH
CERTSRV_E_ARCHIVED_KEY_UNEXPECTED               EQU     80094810H
CERTSRV_E_KEY_LENGTH                            EQU     80094811H
CERTSRV_E_SUBJECT_EMAIL_REQUIRED                EQU     80094812H
CERTSRV_E_UNKNOWN_CERT_TYPE                     EQU     80094813H
CERTSRV_E_CERT_TYPE_OVERLAP                     EQU     80094814H
CERTSRV_E_TOO_MANY_SIGNATURES                   EQU     80094815H

XENROLL_E_KEY_NOT_EXPORTABLE                    EQU     80095000H
XENROLL_E_CANNOT_ADD_ROOT_CERT                  EQU     80095001H
XENROLL_E_RESPONSE_KA_HASH_NOT_FOUND            EQU     80095002H
XENROLL_E_RESPONSE_UNEXPECTED_KA_HASH           EQU     80095003H
XENROLL_E_RESPONSE_KA_HASH_MISMATCH             EQU     80095004H
XENROLL_E_KEYSPEC_SMIME_MISMATCH                EQU     80095005H

TRUST_E_SYSTEM_ERROR                            EQU     80096001H
TRUST_E_NO_SIGNER_CERT                          EQU     80096002H
TRUST_E_COUNTER_SIGNER                          EQU     80096003H
TRUST_E_CERT_SIGNATURE                          EQU     80096004H
TRUST_E_TIME_STAMP                              EQU     80096005H
TRUST_E_BAD_DIGEST                              EQU     80096010H
TRUST_E_BASIC_CONSTRAINTS                       EQU     80096019H
TRUST_E_FINANCIAL_CRITERIA                      EQU     8009601EH
TRUST_E_PROVIDER_UNKNOWN                        EQU     800B0001H
TRUST_E_ACTION_UNKNOWN                          EQU     800B0002H
TRUST_E_SUBJECT_FORM_UNKNOWN                    EQU     800B0003H
TRUST_E_SUBJECT_NOT_TRUSTED                     EQU     800B0004H

MSSIPOTF_E_OUTOFMEMRANGE                        EQU     80097001H
MSSIPOTF_E_CANTGETOBJECT                        EQU     80097002H
MSSIPOTF_E_NOHEADTABLE                          EQU     80097003H
MSSIPOTF_E_BAD_MAGICNUMBER                      EQU     80097004H
MSSIPOTF_E_BAD_OFFSET_TABLE                     EQU     80097005H
MSSIPOTF_E_TABLE_TAGORDER                       EQU     80097006H
MSSIPOTF_E_TABLE_LONGWORD                       EQU     80097007H
MSSIPOTF_E_BAD_FIRST_TABLE_PLACEMENT            EQU     80097008H
MSSIPOTF_E_TABLES_OVERLAP                       EQU     80097009H
MSSIPOTF_E_TABLE_PADBYTES                       EQU     8009700AH
MSSIPOTF_E_FILETOOSMALL                         EQU     8009700BH
MSSIPOTF_E_TABLE_CHECKSUM                       EQU     8009700CH
MSSIPOTF_E_FILE_CHECKSUM                        EQU     8009700DH
MSSIPOTF_E_FAILED_POLICY                        EQU     80097010H
MSSIPOTF_E_FAILED_HINTS_CHECK                   EQU     80097011H
MSSIPOTF_E_NOT_OPENTYPE                         EQU     80097012H
MSSIPOTF_E_FILE                                 EQU     80097013H
MSSIPOTF_E_CRYPT                                EQU     80097014H
MSSIPOTF_E_BADVERSION                           EQU     80097015H
MSSIPOTF_E_DSIG_STRUCTURE                       EQU     80097016H
MSSIPOTF_E_PCONST_CHECK                         EQU     80097017H
MSSIPOTF_E_STRUCTURE                            EQU     80097018H

ERROR_CRED_REQUIRES_CONFIRMATION                EQU     80097019H
NTE_OP_OK                                       EQU     0

DIGSIG_E_ENCODE                                 EQU     800B0005H
DIGSIG_E_DECODE                                 EQU     800B0006H
DIGSIG_E_EXTENSIBILITY                          EQU     800B0007H
DIGSIG_E_CRYPTO                                 EQU     800B0008H

PERSIST_E_SIZEDEFINITE                          EQU     800B0009H
PERSIST_E_SIZEINDEFINITE                        EQU     800B000AH
PERSIST_E_NOTSELFSIZING                         EQU     800B000BH

TRUST_E_NOSIGNATURE                             EQU     800B0100H
TRUST_E_FAIL                                    EQU     800B010BH
TRUST_E_EXPLICIT_DISTRUST                       EQU     800B0111H

CERT_E_EXPIRED                                  EQU     800B0101H
CERT_E_VALIDITYPERIODNESTING                    EQU     800B0102H
CERT_E_ROLE                                     EQU     800B0103H
CERT_E_PATHLENCONST                             EQU     800B0104H
CERT_E_CRITICAL                                 EQU     800B0105H
CERT_E_PURPOSE                                  EQU     800B0106H
CERT_E_ISSUERCHAINING                           EQU     800B0107H
CERT_E_MALFORMED                                EQU     800B0108H
CERT_E_UNTRUSTEDROOT                            EQU     800B0109H
CERT_E_CHAINING                                 EQU     800B010AH
CERT_E_REVOKED                                  EQU     800B010CH
CERT_E_UNTRUSTEDTESTROOT                        EQU     800B010DH
CERT_E_REVOCATION_FAILURE                       EQU     800B010EH
CERT_E_CN_NO_MATCH                              EQU     800B010FH
CERT_E_WRONG_USAGE                              EQU     800B0110H
CERT_E_UNTRUSTEDCA                              EQU     800B0112H
CERT_E_INVALID_POLICY                           EQU     800B0113H
CERT_E_INVALID_NAME                             EQU     800B0114H

SPAPI_E_EXPECTED_SECTION_NAME                   EQU     800F0000H
SPAPI_E_BAD_SECTION_NAME_LINE                   EQU     800F0001H
SPAPI_E_SECTION_NAME_TOO_LONG                   EQU     800F0002H
SPAPI_E_GENERAL_SYNTAX                          EQU     800F0003H
SPAPI_E_WRONG_INF_STYLE                         EQU     800F0100H
SPAPI_E_SECTION_NOT_FOUND                       EQU     800F0101H
SPAPI_E_LINE_NOT_FOUND                          EQU     800F0102H
SPAPI_E_NO_BACKUP                               EQU     800F0103H
SPAPI_E_NO_ASSOCIATED_CLASS                     EQU     800F0200H
SPAPI_E_CLASS_MISMATCH                          EQU     800F0201H
SPAPI_E_DUPLICATE_FOUND                         EQU     800F0202H
SPAPI_E_NO_DRIVER_SELECTED                      EQU     800F0203H
SPAPI_E_KEY_DOES_NOT_EXIST                      EQU     800F0204H
SPAPI_E_INVALID_DEVINST_NAME                    EQU     800F0205H
SPAPI_E_INVALID_CLASS                           EQU     800F0206H
SPAPI_E_DEVINST_ALREADY_EXISTS                  EQU     800F0207H
SPAPI_E_DEVINFO_NOT_REGISTERED                  EQU     800F0208H
SPAPI_E_INVALID_REG_PROPERTY                    EQU     800F0209H
SPAPI_E_NO_INF                                  EQU     800F020AH
SPAPI_E_NO_SUCH_DEVINST                         EQU     800F020BH
SPAPI_E_CANT_LOAD_CLASS_ICON                    EQU     800F020CH
SPAPI_E_INVALID_CLASS_INSTALLER                 EQU     800F020DH
SPAPI_E_DI_DO_DEFAULT                           EQU     800F020EH
SPAPI_E_DI_NOFILECOPY                           EQU     800F020FH
SPAPI_E_INVALID_HWPROFILE                       EQU     800F0210H
SPAPI_E_NO_DEVICE_SELECTED                      EQU     800F0211H
SPAPI_E_DEVINFO_LIST_LOCKED                     EQU     800F0212H
SPAPI_E_DEVINFO_DATA_LOCKED                     EQU     800F0213H
SPAPI_E_DI_BAD_PATH                             EQU     800F0214H
SPAPI_E_NO_CLASSINSTALL_PARAMS                  EQU     800F0215H
SPAPI_E_FILEQUEUE_LOCKED                        EQU     800F0216H
SPAPI_E_BAD_SERVICE_INSTALLSECT                 EQU     800F0217H
SPAPI_E_NO_CLASS_DRIVER_LIST                    EQU     800F0218H
SPAPI_E_NO_ASSOCIATED_SERVICE                   EQU     800F0219H
SPAPI_E_NO_DEFAULT_DEVICE_INTERFACE             EQU     800F021AH
SPAPI_E_DEVICE_INTERFACE_ACTIVE                 EQU     800F021BH
SPAPI_E_DEVICE_INTERFACE_REMOVED                EQU     800F021CH
SPAPI_E_BAD_INTERFACE_INSTALLSECT               EQU     800F021DH
SPAPI_E_NO_SUCH_INTERFACE_CLASS                 EQU     800F021EH
SPAPI_E_INVALID_REFERENCE_STRING                EQU     800F021FH
SPAPI_E_INVALID_MACHINENAME                     EQU     800F0220H
SPAPI_E_REMOTE_COMM_FAILURE                     EQU     800F0221H
SPAPI_E_MACHINE_UNAVAILABLE                     EQU     800F0222H
SPAPI_E_NO_CONFIGMGR_SERVICES                   EQU     800F0223H
SPAPI_E_INVALID_PROPPAGE_PROVIDER               EQU     800F0224H
SPAPI_E_NO_SUCH_DEVICE_INTERFACE                EQU     800F0225H
SPAPI_E_DI_POSTPROCESSING_REQUIRED              EQU     800F0226H
SPAPI_E_INVALID_COINSTALLER                     EQU     800F0227H
SPAPI_E_NO_COMPAT_DRIVERS                       EQU     800F0228H
SPAPI_E_NO_DEVICE_ICON                          EQU     800F0229H
SPAPI_E_INVALID_INF_LOGCONFIG                   EQU     800F022AH
SPAPI_E_DI_DONT_INSTALL                         EQU     800F022BH
SPAPI_E_INVALID_FILTER_DRIVER                   EQU     800F022CH
SPAPI_E_NON_WINDOWS_NT_DRIVER                   EQU     800F022DH
SPAPI_E_NON_WINDOWS_DRIVER                      EQU     800F022EH
SPAPI_E_NO_CATALOG_FOR_OEM_INF                  EQU     800F022FH
SPAPI_E_DEVINSTALL_QUEUE_NONNATIVE              EQU     800F0230H
SPAPI_E_NOT_DISABLEABLE                         EQU     800F0231H
SPAPI_E_CANT_REMOVE_DEVINST                     EQU     800F0232H
SPAPI_E_INVALID_TARGET                          EQU     800F0233H
SPAPI_E_DRIVER_NONNATIVE                        EQU     800F0234H
SPAPI_E_IN_WOW64                                EQU     800F0235H
SPAPI_E_SET_SYSTEM_RESTORE_POINT                EQU     800F0236H
SPAPI_E_INCORRECTLY_COPIED_INF                  EQU     800F0237H
SPAPI_E_SCE_DISABLED                            EQU     800F0238H
SPAPI_E_UNKNOWN_EXCEPTION                       EQU     800F0239H
SPAPI_E_PNP_REGISTRY_ERROR                      EQU     800F023AH
SPAPI_E_REMOTE_REQUEST_UNSUPPORTED              EQU     800F023BH
SPAPI_E_NOT_AN_INSTALLED_OEM_INF                EQU     800F023CH
SPAPI_E_INF_IN_USE_BY_DEVICES                   EQU     800F023DH
SPAPI_E_DI_FUNCTION_OBSOLETE                    EQU     800F023EH
SPAPI_E_NO_AUTHENTICODE_CATALOG                 EQU     800F023FH
SPAPI_E_AUTHENTICODE_DISALLOWED                 EQU     800F0240H
SPAPI_E_AUTHENTICODE_TRUSTED_PUBLISHER          EQU     800F0241H
SPAPI_E_AUTHENTICODE_TRUST_NOT_ESTABLISHED      EQU     800F0242H
SPAPI_E_AUTHENTICODE_PUBLISHER_NOT_TRUSTED      EQU     800F0243H
SPAPI_E_SIGNATURE_OSATTRIBUTE_MISMATCH          EQU     800F0244H
SPAPI_E_ONLY_VALIDATE_VIA_AUTHENTICODE          EQU     800F0245H
SPAPI_E_DEVICE_INSTALLER_NOT_READY              EQU     800F0246H
SPAPI_E_DRIVER_STORE_ADD_FAILED                 EQU     800F0247H
SPAPI_E_DEVICE_INSTALL_BLOCKED                  EQU     800F0248H
SPAPI_E_DRIVER_INSTALL_BLOCKED                  EQU     800F0249H
SPAPI_E_WRONG_INF_TYPE                          EQU     800F024AH
SPAPI_E_FILE_HASH_NOT_IN_CATALOG                EQU     800F024BH
SPAPI_E_DRIVER_STORE_DELETE_FAILED              EQU     800F024CH
SPAPI_E_UNRECOVERABLE_STACK_OVERFLOW            EQU     800F0300H
SPAPI_E_ERROR_NOT_INSTALLED                     EQU     800F1000H

SCARD_S_SUCCESS                                 EQU     NO_ERROR
SCARD_F_INTERNAL_ERROR                          EQU     80100001H
SCARD_E_CANCELLED                               EQU     80100002H
SCARD_E_INVALID_HANDLE                          EQU     80100003H
SCARD_E_INVALID_PARAMETER                       EQU     80100004H
SCARD_E_INVALID_TARGET                          EQU     80100005H
SCARD_E_NO_MEMORY                               EQU     80100006H
SCARD_F_WAITED_TOO_LONG                         EQU     80100007H
SCARD_E_INSUFFICIENT_BUFFER                     EQU     80100008H
SCARD_E_UNKNOWN_READER                          EQU     80100009H
SCARD_E_TIMEOUT                                 EQU     8010000AH
SCARD_E_SHARING_VIOLATION                       EQU     8010000BH
SCARD_E_NO_SMARTCARD                            EQU     8010000CH
SCARD_E_UNKNOWN_CARD                            EQU     8010000DH
SCARD_E_CANT_DISPOSE                            EQU     8010000EH
SCARD_E_PROTO_MISMATCH                          EQU     8010000FH
SCARD_E_NOT_READY                               EQU     80100010H
SCARD_E_INVALID_VALUE                           EQU     80100011H
SCARD_E_SYSTEM_CANCELLED                        EQU     80100012H
SCARD_F_COMM_ERROR                              EQU     80100013H
SCARD_F_UNKNOWN_ERROR                           EQU     80100014H
SCARD_E_INVALID_ATR                             EQU     80100015H
SCARD_E_NOT_TRANSACTED                          EQU     80100016H
SCARD_E_READER_UNAVAILABLE                      EQU     80100017H
SCARD_P_SHUTDOWN                                EQU     80100018H
SCARD_E_PCI_TOO_SMALL                           EQU     80100019H
SCARD_E_READER_UNSUPPORTED                      EQU     8010001AH
SCARD_E_DUPLICATE_READER                        EQU     8010001BH
SCARD_E_CARD_UNSUPPORTED                        EQU     8010001CH
SCARD_E_NO_SERVICE                              EQU     8010001DH
SCARD_E_SERVICE_STOPPED                         EQU     8010001EH
SCARD_E_UNEXPECTED                              EQU     8010001FH
SCARD_E_ICC_INSTALLATION                        EQU     80100020H
SCARD_E_ICC_CREATEORDER                         EQU     80100021H
SCARD_E_UNSUPPORTED_FEATURE                     EQU     80100022H
SCARD_E_DIR_NOT_FOUND                           EQU     80100023H
SCARD_E_FILE_NOT_FOUND                          EQU     80100024H
SCARD_E_NO_DIR                                  EQU     80100025H
SCARD_E_NO_FILE                                 EQU     80100026H
SCARD_E_NO_ACCESS                               EQU     80100027H
SCARD_E_WRITE_TOO_MANY                          EQU     80100028H
SCARD_E_BAD_SEEK                                EQU     80100029H
SCARD_E_INVALID_CHV                             EQU     8010002AH
SCARD_E_UNKNOWN_RES_MNG                         EQU     8010002BH
SCARD_E_NO_SUCH_CERTIFICATE                     EQU     8010002CH
SCARD_E_CERTIFICATE_UNAVAILABLE                 EQU     8010002DH
SCARD_E_NO_READERS_AVAILABLE                    EQU     8010002EH
SCARD_E_COMM_DATA_LOST                          EQU     8010002FH
SCARD_E_NO_KEY_CONTAINER                        EQU     80100030H
SCARD_E_SERVER_TOO_BUSY                         EQU     80100031H
SCARD_E_PIN_CACHE_EXPIRED                       EQU     80100032H
SCARD_E_NO_PIN_CACHE                            EQU     80100033H
SCARD_E_READ_ONLY_CARD                          EQU     80100034H
SCARD_W_UNSUPPORTED_CARD                        EQU     80100065H
SCARD_W_UNRESPONSIVE_CARD                       EQU     80100066H
SCARD_W_UNPOWERED_CARD                          EQU     80100067H
SCARD_W_RESET_CARD                              EQU     80100068H
SCARD_W_REMOVED_CARD                            EQU     80100069H
SCARD_W_SECURITY_VIOLATION                      EQU     8010006AH
SCARD_W_WRONG_CHV                               EQU     8010006BH
SCARD_W_CHV_BLOCKED                             EQU     8010006CH
SCARD_W_EOF                                     EQU     8010006DH
SCARD_W_CANCELLED_BY_USER                       EQU     8010006EH
SCARD_W_CARD_NOT_AUTHENTICATED                  EQU     8010006FH
SCARD_W_CACHE_ITEM_NOT_FOUND                    EQU     80100070H
SCARD_W_CACHE_ITEM_STALE                        EQU     80100071H
SCARD_W_CACHE_ITEM_TOO_BIG                      EQU     80100072H

COMADMIN_E_OBJECTERRORS                         EQU     80110401H
COMADMIN_E_OBJECTINVALID                        EQU     80110402H
COMADMIN_E_KEYMISSING                           EQU     80110403H
COMADMIN_E_ALREADYINSTALLED                     EQU     80110404H
COMADMIN_E_APP_FILE_WRITEFAIL                   EQU     80110407H
COMADMIN_E_APP_FILE_READFAIL                    EQU     80110408H
COMADMIN_E_APP_FILE_VERSION                     EQU     80110409H
COMADMIN_E_BADPATH                              EQU     8011040AH
COMADMIN_E_APPLICATIONEXISTS                    EQU     8011040BH
COMADMIN_E_ROLEEXISTS                           EQU     8011040CH
COMADMIN_E_CANTCOPYFILE                         EQU     8011040DH
COMADMIN_E_NOUSER                               EQU     8011040FH
COMADMIN_E_INVALIDUSERIDS                       EQU     80110410H
COMADMIN_E_NOREGISTRYCLSID                      EQU     80110411H
COMADMIN_E_BADREGISTRYPROGID                    EQU     80110412H
COMADMIN_E_AUTHENTICATIONLEVEL                  EQU     80110413H
COMADMIN_E_USERPASSWDNOTVALID                   EQU     80110414H
COMADMIN_E_CLSIDORIIDMISMATCH                   EQU     80110418H
COMADMIN_E_REMOTEINTERFACE                      EQU     80110419H
COMADMIN_E_DLLREGISTERSERVER                    EQU     8011041AH
COMADMIN_E_NOSERVERSHARE                        EQU     8011041BH
COMADMIN_E_DLLLOADFAILED                        EQU     8011041DH
COMADMIN_E_BADREGISTRYLIBID                     EQU     8011041EH
COMADMIN_E_APPDIRNOTFOUND                       EQU     8011041FH
COMADMIN_E_REGISTRARFAILED                      EQU     80110423H
COMADMIN_E_COMPFILE_DOESNOTEXIST                EQU     80110424H
COMADMIN_E_COMPFILE_LOADDLLFAIL                 EQU     80110425H
COMADMIN_E_COMPFILE_GETCLASSOBJ                 EQU     80110426H
COMADMIN_E_COMPFILE_CLASSNOTAVAIL               EQU     80110427H
COMADMIN_E_COMPFILE_BADTLB                      EQU     80110428H
COMADMIN_E_COMPFILE_NOTINSTALLABLE              EQU     80110429H
COMADMIN_E_NOTCHANGEABLE                        EQU     8011042AH
COMADMIN_E_NOTDELETEABLE                        EQU     8011042BH
COMADMIN_E_SESSION                              EQU     8011042CH
COMADMIN_E_COMP_MOVE_LOCKED                     EQU     8011042DH
COMADMIN_E_COMP_MOVE_BAD_DEST                   EQU     8011042EH
COMADMIN_E_REGISTERTLB                          EQU     80110430H
COMADMIN_E_SYSTEMAPP                            EQU     80110433H
COMADMIN_E_COMPFILE_NOREGISTRAR                 EQU     80110434H
COMADMIN_E_COREQCOMPINSTALLED                   EQU     80110435H
COMADMIN_E_SERVICENOTINSTALLED                  EQU     80110436H
COMADMIN_E_PROPERTYSAVEFAILED                   EQU     80110437H
COMADMIN_E_OBJECTEXISTS                         EQU     80110438H
COMADMIN_E_COMPONENTEXISTS                      EQU     80110439H
COMADMIN_E_REGFILE_CORRUPT                      EQU     8011043BH
COMADMIN_E_PROPERTY_OVERFLOW                    EQU     8011043CH
COMADMIN_E_NOTINREGISTRY                        EQU     8011043EH
COMADMIN_E_OBJECTNOTPOOLABLE                    EQU     8011043FH
COMADMIN_E_APPLID_MATCHES_CLSID                 EQU     80110446H
COMADMIN_E_ROLE_DOES_NOT_EXIST                  EQU     80110447H
COMADMIN_E_START_APP_NEEDS_COMPONENTS           EQU     80110448H
COMADMIN_E_REQUIRES_DIFFERENT_PLATFORM          EQU     80110449H
COMADMIN_E_CAN_NOT_EXPORT_APP_PROXY             EQU     8011044AH
COMADMIN_E_CAN_NOT_START_APP                    EQU     8011044BH
COMADMIN_E_CAN_NOT_EXPORT_SYS_APP               EQU     8011044CH
COMADMIN_E_CANT_SUBSCRIBE_TO_COMPONENT          EQU     8011044DH
COMADMIN_E_EVENTCLASS_CANT_BE_SUBSCRIBER        EQU     8011044EH
COMADMIN_E_LIB_APP_PROXY_INCOMPATIBLE           EQU     8011044FH
COMADMIN_E_BASE_PARTITION_ONLY                  EQU     80110450H
COMADMIN_E_START_APP_DISABLED                   EQU     80110451H
COMADMIN_E_CAT_DUPLICATE_PARTITION_NAME         EQU     80110457H
COMADMIN_E_CAT_INVALID_PARTITION_NAME           EQU     80110458H
COMADMIN_E_CAT_PARTITION_IN_USE                 EQU     80110459H
COMADMIN_E_FILE_PARTITION_DUPLICATE_FILES       EQU     8011045AH
COMADMIN_E_CAT_IMPORTED_COMPONENTS_NOT_ALLOWED  EQU     8011045BH
COMADMIN_E_AMBIGUOUS_APPLICATION_NAME           EQU     8011045CH
COMADMIN_E_AMBIGUOUS_PARTITION_NAME             EQU     8011045DH
COMADMIN_E_REGDB_NOTINITIALIZED                 EQU     80110472H
COMADMIN_E_REGDB_NOTOPEN                        EQU     80110473H
COMADMIN_E_REGDB_SYSTEMERR                      EQU     80110474H
COMADMIN_E_REGDB_ALREADYRUNNING                 EQU     80110475H
COMADMIN_E_MIG_VERSIONNOTSUPPORTED              EQU     80110480H
COMADMIN_E_MIG_SCHEMANOTFOUND                   EQU     80110481H
COMADMIN_E_CAT_BITNESSMISMATCH                  EQU     80110482H
COMADMIN_E_CAT_UNACCEPTABLEBITNESS              EQU     80110483H
COMADMIN_E_CAT_WRONGAPPBITNESS                  EQU     80110484H
COMADMIN_E_CAT_PAUSE_RESUME_NOT_SUPPORTED       EQU     80110485H
COMADMIN_E_CAT_SERVERFAULT                      EQU     80110486H

COMQC_E_APPLICATION_NOT_QUEUED                  EQU     80110600H
COMQC_E_NO_QUEUEABLE_INTERFACES                 EQU     80110601H
COMQC_E_QUEUING_SERVICE_NOT_AVAILABLE           EQU     80110602H
COMQC_E_NO_IPERSISTSTREAM                       EQU     80110603H
COMQC_E_BAD_MESSAGE                             EQU     80110604H
COMQC_E_UNAUTHENTICATED                         EQU     80110605H
COMQC_E_UNTRUSTED_ENQUEUER                      EQU     80110606H

MSDTC_E_DUPLICATE_RESOURCE                      EQU     80110701H

COMADMIN_E_OBJECT_PARENT_MISSING                EQU     80110808H
COMADMIN_E_OBJECT_DOES_NOT_EXIST                EQU     80110809H
COMADMIN_E_APP_NOT_RUNNING                      EQU     8011080AH
COMADMIN_E_INVALID_PARTITION                    EQU     8011080BH
COMADMIN_E_SVCAPP_NOT_POOLABLE_OR_RECYCLABLE    EQU     8011080DH
COMADMIN_E_USER_IN_SET                          EQU     8011080EH
COMADMIN_E_CANTRECYCLELIBRARYAPPS               EQU     8011080FH
COMADMIN_E_CANTRECYCLESERVICEAPPS               EQU     80110811H
COMADMIN_E_PROCESSALREADYRECYCLED               EQU     80110812H
COMADMIN_E_PAUSEDPROCESSMAYNOTBERECYCLED        EQU     80110813H
COMADMIN_E_CANTMAKEINPROCSERVICE                EQU     80110814H
COMADMIN_E_PROGIDINUSEBYCLSID                   EQU     80110815H
COMADMIN_E_DEFAULT_PARTITION_NOT_IN_SET         EQU     80110816H
COMADMIN_E_RECYCLEDPROCESSMAYNOTBEPAUSED        EQU     80110817H
COMADMIN_E_PARTITION_ACCESSDENIED               EQU     80110818H
COMADMIN_E_PARTITION_MSI_ONLY                   EQU     80110819H
COMADMIN_E_LEGACYCOMPS_NOT_ALLOWED_IN_1_0_FORMAT EQU    8011081AH
COMADMIN_E_LEGACYCOMPS_NOT_ALLOWED_IN_NONBASE_PARTITIONS EQU 8011081BH
COMADMIN_E_COMP_MOVE_SOURCE                     EQU     8011081CH
COMADMIN_E_COMP_MOVE_DEST                       EQU     8011081DH
COMADMIN_E_COMP_MOVE_PRIVATE                    EQU     8011081EH
COMADMIN_E_BASEPARTITION_REQUIRED_IN_SET        EQU     8011081FH
COMADMIN_E_CANNOT_ALIAS_EVENTCLASS              EQU     80110820H
COMADMIN_E_PRIVATE_ACCESSDENIED                 EQU     80110821H
COMADMIN_E_SAFERINVALID                         EQU     80110822H
COMADMIN_E_REGISTRY_ACCESSDENIED                EQU     80110823H
COMADMIN_E_PARTITIONS_DISABLED                  EQU     80110824H

ERROR_FLT_IO_COMPLETE                           EQU     001F0001H
ERROR_FLT_NO_HANDLER_DEFINED                    EQU     801F0001H
ERROR_FLT_CONTEXT_ALREADY_DEFINED               EQU     801F0002H
ERROR_FLT_INVALID_ASYNCHRONOUS_REQUEST          EQU     801F0003H
ERROR_FLT_DISALLOW_FAST_IO                      EQU     801F0004H
ERROR_FLT_INVALID_NAME_REQUEST                  EQU     801F0005H
ERROR_FLT_NOT_SAFE_TO_POST_OPERATION            EQU     801F0006H
ERROR_FLT_NOT_INITIALIZED                       EQU     801F0007H
ERROR_FLT_FILTER_NOT_READY                      EQU     801F0008H
ERROR_FLT_POST_OPERATION_CLEANUP                EQU     801F0009H
ERROR_FLT_INTERNAL_ERROR                        EQU     801F000AH
ERROR_FLT_DELETING_OBJECT                       EQU     801F000BH
ERROR_FLT_MUST_BE_NONPAGED_POOL                 EQU     801F000CH
ERROR_FLT_DUPLICATE_ENTRY                       EQU     801F000DH
ERROR_FLT_CBDQ_DISABLED                         EQU     801F000EH
ERROR_FLT_DO_NOT_ATTACH                         EQU     801F000FH
ERROR_FLT_DO_NOT_DETACH                         EQU     801F0010H
ERROR_FLT_INSTANCE_ALTITUDE_COLLISION           EQU     801F0011H
ERROR_FLT_INSTANCE_NAME_COLLISION               EQU     801F0012H
ERROR_FLT_FILTER_NOT_FOUND                      EQU     801F0013H
ERROR_FLT_VOLUME_NOT_FOUND                      EQU     801F0014H
ERROR_FLT_INSTANCE_NOT_FOUND                    EQU     801F0015H
ERROR_FLT_CONTEXT_ALLOCATION_NOT_FOUND          EQU     801F0016H
ERROR_FLT_INVALID_CONTEXT_REGISTRATION          EQU     801F0017H
ERROR_FLT_NAME_CACHE_MISS                       EQU     801F0018H
ERROR_FLT_NO_DEVICE_OBJECT                      EQU     801F0019H
ERROR_FLT_VOLUME_ALREADY_MOUNTED                EQU     801F001AH
ERROR_FLT_ALREADY_ENLISTED                      EQU     801F001BH
ERROR_FLT_CONTEXT_ALREADY_LINKED                EQU     801F001CH
ERROR_FLT_NO_WAITER_FOR_REPLY                   EQU     801F0020H

ERROR_HUNG_DISPLAY_DRIVER_THREAD                EQU     80260001H

DWM_E_COMPOSITIONDISABLED                       EQU     80263001H
DWM_E_REMOTING_NOT_SUPPORTED                    EQU     80263002H
DWM_E_NO_REDIRECTION_SURFACE_AVAILABLE          EQU     80263003H
DWM_E_NOT_QUEUING_PRESENTS                      EQU     80263004H
DWM_E_ADAPTER_NOT_FOUND                         EQU     80263005H
DWM_S_GDI_REDIRECTION_SURFACE                   EQU     00263005H

ERROR_MONITOR_NO_DESCRIPTOR                     EQU     00261001H
ERROR_MONITOR_UNKNOWN_DESCRIPTOR_FORMAT         EQU     00261002H
ERROR_MONITOR_INVALID_DESCRIPTOR_CHECKSUM       EQU     0C0261003H
ERROR_MONITOR_INVALID_STANDARD_TIMING_BLOCK     EQU     0C0261004H
ERROR_MONITOR_WMI_DATABLOCK_REGISTRATION_FAILED EQU     0C0261005H
ERROR_MONITOR_INVALID_SERIAL_NUMBER_MONDSC_BLOCK EQU    0C0261006H
ERROR_MONITOR_INVALID_USER_FRIENDLY_MONDSC_BLOCK EQU    0C0261007H
ERROR_MONITOR_NO_MORE_DESCRIPTOR_DATA           EQU     0C0261008H
ERROR_MONITOR_INVALID_DETAILED_TIMING_BLOCK     EQU     0C0261009H
ERROR_MONITOR_INVALID_MANUFACTURE_DATE          EQU     0C026100AH

ERROR_GRAPHICS_NOT_EXCLUSIVE_MODE_OWNER         EQU     0C0262000H
ERROR_GRAPHICS_INSUFFICIENT_DMA_BUFFER          EQU     0C0262001H
ERROR_GRAPHICS_INVALID_DISPLAY_ADAPTER          EQU     0C0262002H
ERROR_GRAPHICS_ADAPTER_WAS_RESET                EQU     0C0262003H
ERROR_GRAPHICS_INVALID_DRIVER_MODEL             EQU     0C0262004H
ERROR_GRAPHICS_PRESENT_MODE_CHANGED             EQU     0C0262005H
ERROR_GRAPHICS_PRESENT_OCCLUDED                 EQU     0C0262006H
ERROR_GRAPHICS_PRESENT_DENIED                   EQU     0C0262007H
ERROR_GRAPHICS_CANNOTCOLORCONVERT               EQU     0C0262008H
ERROR_GRAPHICS_DRIVER_MISMATCH                  EQU     0C0262009H
ERROR_GRAPHICS_PARTIAL_DATA_POPULATED           EQU     04026200AH
ERROR_GRAPHICS_PRESENT_REDIRECTION_DISABLED     EQU     0C026200BH
ERROR_GRAPHICS_PRESENT_UNOCCLUDED               EQU     0C026200CH
ERROR_GRAPHICS_NO_VIDEO_MEMORY                  EQU     0C0262100H
ERROR_GRAPHICS_CANT_LOCK_MEMORY                 EQU     0C0262101H
ERROR_GRAPHICS_ALLOCATION_BUSY                  EQU     0C0262102H
ERROR_GRAPHICS_TOO_MANY_REFERENCES              EQU     0C0262103H
ERROR_GRAPHICS_TRY_AGAIN_LATER                  EQU     0C0262104H
ERROR_GRAPHICS_TRY_AGAIN_NOW                    EQU     0C0262105H
ERROR_GRAPHICS_ALLOCATION_INVALID               EQU     0C0262106H
ERROR_GRAPHICS_UNSWIZZLING_APERTURE_UNAVAILABLE EQU     0C0262107H
ERROR_GRAPHICS_UNSWIZZLING_APERTURE_UNSUPPORTED EQU     0C0262108H
ERROR_GRAPHICS_CANT_EVICT_PINNED_ALLOCATION     EQU     0C0262109H
ERROR_GRAPHICS_INVALID_ALLOCATION_USAGE         EQU     0C0262110H
ERROR_GRAPHICS_CANT_RENDER_LOCKED_ALLOCATION    EQU     0C0262111H
ERROR_GRAPHICS_ALLOCATION_CLOSED                EQU     0C0262112H
ERROR_GRAPHICS_INVALID_ALLOCATION_INSTANCE      EQU     0C0262113H
ERROR_GRAPHICS_INVALID_ALLOCATION_HANDLE        EQU     0C0262114H
ERROR_GRAPHICS_WRONG_ALLOCATION_DEVICE          EQU     0C0262115H
ERROR_GRAPHICS_ALLOCATION_CONTENT_LOST          EQU     0C0262116H
ERROR_GRAPHICS_GPU_EXCEPTION_ON_DEVICE          EQU     0C0262200H
ERROR_GRAPHICS_INVALID_VIDPN_TOPOLOGY           EQU     0C0262300H
ERROR_GRAPHICS_VIDPN_TOPOLOGY_NOT_SUPPORTED     EQU     0C0262301H
ERROR_GRAPHICS_VIDPN_TOPOLOGY_CURRENTLY_NOT_SUPPORTED EQU 0C0262302H
ERROR_GRAPHICS_INVALID_VIDPN                    EQU     0C0262303H
ERROR_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE     EQU     0C0262304H
ERROR_GRAPHICS_INVALID_VIDEO_PRESENT_TARGET     EQU     0C0262305H
ERROR_GRAPHICS_VIDPN_MODALITY_NOT_SUPPORTED     EQU     0C0262306H
ERROR_GRAPHICS_MODE_NOT_PINNED                  EQU     000262307H
ERROR_GRAPHICS_INVALID_VIDPN_SOURCEMODESET      EQU     0C0262308H
ERROR_GRAPHICS_INVALID_VIDPN_TARGETMODESET      EQU     0C0262309H
ERROR_GRAPHICS_INVALID_FREQUENCY                EQU     0C026230AH
ERROR_GRAPHICS_INVALID_ACTIVE_REGION            EQU     0C026230BH
ERROR_GRAPHICS_INVALID_TOTAL_REGION             EQU     0C026230CH
ERROR_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE_MODE EQU    0C0262310H
ERROR_GRAPHICS_INVALID_VIDEO_PRESENT_TARGET_MODE EQU    0C0262311H
ERROR_GRAPHICS_PINNED_MODE_MUST_REMAIN_IN_SET   EQU     0C0262312H
ERROR_GRAPHICS_PATH_ALREADY_IN_TOPOLOGY         EQU     0C0262313H
ERROR_GRAPHICS_MODE_ALREADY_IN_MODESET          EQU     0C0262314H
ERROR_GRAPHICS_INVALID_VIDEOPRESENTSOURCESET    EQU     0C0262315H
ERROR_GRAPHICS_INVALID_VIDEOPRESENTTARGETSET    EQU     0C0262316H
ERROR_GRAPHICS_SOURCE_ALREADY_IN_SET            EQU     0C0262317H
ERROR_GRAPHICS_TARGET_ALREADY_IN_SET            EQU     0C0262318H
ERROR_GRAPHICS_INVALID_VIDPN_PRESENT_PATH       EQU     0C0262319H
ERROR_GRAPHICS_NO_RECOMMENDED_VIDPN_TOPOLOGY    EQU     0C026231AH
ERROR_GRAPHICS_INVALID_MONITOR_FREQUENCYRANGESET EQU    0C026231BH
ERROR_GRAPHICS_INVALID_MONITOR_FREQUENCYRANGE   EQU     0C026231CH
ERROR_GRAPHICS_FREQUENCYRANGE_NOT_IN_SET        EQU     0C026231DH
ERROR_GRAPHICS_NO_PREFERRED_MODE                EQU     00026231EH
ERROR_GRAPHICS_FREQUENCYRANGE_ALREADY_IN_SET    EQU     0C026231FH
ERROR_GRAPHICS_STALE_MODESET                    EQU     0C0262320H
ERROR_GRAPHICS_INVALID_MONITOR_SOURCEMODESET    EQU     0C0262321H
ERROR_GRAPHICS_INVALID_MONITOR_SOURCE_MODE      EQU     0C0262322H
ERROR_GRAPHICS_NO_RECOMMENDED_FUNCTIONAL_VIDPN  EQU     0C0262323H
ERROR_GRAPHICS_MODE_ID_MUST_BE_UNIQUE           EQU     0C0262324H
ERROR_GRAPHICS_EMPTY_ADAPTER_MONITOR_MODE_SUPPORT_INTERSECTION EQU 0C0262325H
ERROR_GRAPHICS_VIDEO_PRESENT_TARGETS_LESS_THAN_SOURCES EQU 0C0262326H
ERROR_GRAPHICS_PATH_NOT_IN_TOPOLOGY             EQU     0C0262327H
ERROR_GRAPHICS_ADAPTER_MUST_HAVE_AT_LEAST_ONE_SOURCE EQU 0C0262328H
ERROR_GRAPHICS_ADAPTER_MUST_HAVE_AT_LEAST_ONE_TARGET EQU 0C0262329H
ERROR_GRAPHICS_INVALID_MONITORDESCRIPTORSET     EQU     0C026232AH
ERROR_GRAPHICS_INVALID_MONITORDESCRIPTOR        EQU     0C026232BH
ERROR_GRAPHICS_MONITORDESCRIPTOR_NOT_IN_SET     EQU     0C026232CH
ERROR_GRAPHICS_MONITORDESCRIPTOR_ALREADY_IN_SET EQU     0C026232DH
ERROR_GRAPHICS_MONITORDESCRIPTOR_ID_MUST_BE_UNIQUE EQU  0C026232EH
ERROR_GRAPHICS_INVALID_VIDPN_TARGET_SUBSET_TYPE EQU     0C026232FH
ERROR_GRAPHICS_RESOURCES_NOT_RELATED            EQU     0C0262330H
ERROR_GRAPHICS_SOURCE_ID_MUST_BE_UNIQUE         EQU     0C0262331H
ERROR_GRAPHICS_TARGET_ID_MUST_BE_UNIQUE         EQU     0C0262332H
ERROR_GRAPHICS_NO_AVAILABLE_VIDPN_TARGET        EQU     0C0262333H
ERROR_GRAPHICS_MONITOR_COULD_NOT_BE_ASSOCIATED_WITH_ADAPTER EQU 0C0262334H
ERROR_GRAPHICS_NO_VIDPNMGR                      EQU     0C0262335H
ERROR_GRAPHICS_NO_ACTIVE_VIDPN                  EQU     0C0262336H
ERROR_GRAPHICS_STALE_VIDPN_TOPOLOGY             EQU     0C0262337H
ERROR_GRAPHICS_MONITOR_NOT_CONNECTED            EQU     0C0262338H
ERROR_GRAPHICS_SOURCE_NOT_IN_TOPOLOGY           EQU     0C0262339H
ERROR_GRAPHICS_INVALID_PRIMARYSURFACE_SIZE      EQU     0C026233AH
ERROR_GRAPHICS_INVALID_VISIBLEREGION_SIZE       EQU     0C026233BH
ERROR_GRAPHICS_INVALID_STRIDE                   EQU     0C026233CH
ERROR_GRAPHICS_INVALID_PIXELFORMAT              EQU     0C026233DH
ERROR_GRAPHICS_INVALID_COLORBASIS               EQU     0C026233EH
ERROR_GRAPHICS_INVALID_PIXELVALUEACCESSMODE     EQU     0C026233FH
ERROR_GRAPHICS_TARGET_NOT_IN_TOPOLOGY           EQU     0C0262340H
ERROR_GRAPHICS_NO_DISPLAY_MODE_MANAGEMENT_SUPPORT EQU   0C0262341H
ERROR_GRAPHICS_VIDPN_SOURCE_IN_USE              EQU     0C0262342H
ERROR_GRAPHICS_CANT_ACCESS_ACTIVE_VIDPN         EQU     0C0262343H
ERROR_GRAPHICS_INVALID_PATH_IMPORTANCE_ORDINAL  EQU     0C0262344H
ERROR_GRAPHICS_INVALID_PATH_CONTENT_GEOMETRY_TRANSFORMATION EQU 0C0262345H
ERROR_GRAPHICS_PATH_CONTENT_GEOMETRY_TRANSFORMATION_NOT_SUPPORTED EQU 0C0262346H
ERROR_GRAPHICS_INVALID_GAMMA_RAMP               EQU     0C0262347H
ERROR_GRAPHICS_GAMMA_RAMP_NOT_SUPPORTED         EQU     0C0262348H
ERROR_GRAPHICS_MULTISAMPLING_NOT_SUPPORTED      EQU     0C0262349H
ERROR_GRAPHICS_MODE_NOT_IN_MODESET              EQU     0C026234AH
ERROR_GRAPHICS_DATASET_IS_EMPTY                 EQU     00026234BH
ERROR_GRAPHICS_NO_MORE_ELEMENTS_IN_DATASET      EQU     00026234CH
ERROR_GRAPHICS_INVALID_VIDPN_TOPOLOGY_RECOMMENDATION_REASON EQU 0C026234DH
ERROR_GRAPHICS_INVALID_PATH_CONTENT_TYPE        EQU     0C026234EH
ERROR_GRAPHICS_INVALID_COPYPROTECTION_TYPE      EQU     0C026234FH
ERROR_GRAPHICS_UNASSIGNED_MODESET_ALREADY_EXISTS EQU    0C0262350H
ERROR_GRAPHICS_PATH_CONTENT_GEOMETRY_TRANSFORMATION_NOT_PINNED EQU 00262351H
ERROR_GRAPHICS_INVALID_SCANLINE_ORDERING        EQU     0C0262352H
ERROR_GRAPHICS_TOPOLOGY_CHANGES_NOT_ALLOWED     EQU     0C0262353H
ERROR_GRAPHICS_NO_AVAILABLE_IMPORTANCE_ORDINALS EQU     0C0262354H
ERROR_GRAPHICS_INCOMPATIBLE_PRIVATE_FORMAT      EQU     0C0262355H
ERROR_GRAPHICS_INVALID_MODE_PRUNING_ALGORITHM   EQU     0C0262356H
ERROR_GRAPHICS_INVALID_MONITOR_CAPABILITY_ORIGIN EQU    0C0262357H
ERROR_GRAPHICS_INVALID_MONITOR_FREQUENCYRANGE_CONSTRAINT EQU 0C0262358H
ERROR_GRAPHICS_MAX_NUM_PATHS_REACHED            EQU     0C0262359H
ERROR_GRAPHICS_CANCEL_VIDPN_TOPOLOGY_AUGMENTATION EQU   0C026235AH
ERROR_GRAPHICS_INVALID_CLIENT_TYPE              EQU     0C026235BH
ERROR_GRAPHICS_CLIENTVIDPN_NOT_SET              EQU     0C026235CH
ERROR_GRAPHICS_SPECIFIED_CHILD_ALREADY_CONNECTED EQU    0C0262400H
ERROR_GRAPHICS_CHILD_DESCRIPTOR_NOT_SUPPORTED   EQU     0C0262401H
ERROR_GRAPHICS_UNKNOWN_CHILD_STATUS             EQU     04026242FH
ERROR_GRAPHICS_NOT_A_LINKED_ADAPTER             EQU     0C0262430H
ERROR_GRAPHICS_LEADLINK_NOT_ENUMERATED          EQU     0C0262431H
ERROR_GRAPHICS_CHAINLINKS_NOT_ENUMERATED        EQU     0C0262432H
ERROR_GRAPHICS_ADAPTER_CHAIN_NOT_READY          EQU     0C0262433H
ERROR_GRAPHICS_CHAINLINKS_NOT_STARTED           EQU     0C0262434H
ERROR_GRAPHICS_CHAINLINKS_NOT_POWERED_ON        EQU     0C0262435H
ERROR_GRAPHICS_INCONSISTENT_DEVICE_LINK_STATE   EQU     0C0262436H
ERROR_GRAPHICS_LEADLINK_START_DEFERRED          EQU     040262437H
ERROR_GRAPHICS_NOT_POST_DEVICE_DRIVER           EQU     0C0262438H
ERROR_GRAPHICS_POLLING_TOO_FREQUENTLY           EQU     040262439H
ERROR_GRAPHICS_START_DEFERRED                   EQU     04026243AH
ERROR_GRAPHICS_ADAPTER_ACCESS_NOT_EXCLUDED      EQU     0C026243BH
ERROR_GRAPHICS_OPM_NOT_SUPPORTED                EQU     0C0262500H
ERROR_GRAPHICS_COPP_NOT_SUPPORTED               EQU     0C0262501H
ERROR_GRAPHICS_UAB_NOT_SUPPORTED                EQU     0C0262502H
ERROR_GRAPHICS_OPM_INVALID_ENCRYPTED_PARAMETERS EQU     0C0262503H
ERROR_GRAPHICS_OPM_NO_VIDEO_OUTPUTS_EXIST       EQU     0C0262505H
ERROR_GRAPHICS_OPM_INTERNAL_ERROR               EQU     0C026250BH
ERROR_GRAPHICS_OPM_INVALID_HANDLE               EQU     0C026250CH
ERROR_GRAPHICS_PVP_INVALID_CERTIFICATE_LENGTH   EQU     0C026250EH
ERROR_GRAPHICS_OPM_SPANNING_MODE_ENABLED        EQU     0C026250FH
ERROR_GRAPHICS_OPM_THEATER_MODE_ENABLED         EQU     0C0262510H
ERROR_GRAPHICS_PVP_HFS_FAILED                   EQU     0C0262511H
ERROR_GRAPHICS_OPM_INVALID_SRM                  EQU     0C0262512H
ERROR_GRAPHICS_OPM_OUTPUT_DOES_NOT_SUPPORT_HDCP EQU     0C0262513H
ERROR_GRAPHICS_OPM_OUTPUT_DOES_NOT_SUPPORT_ACP  EQU     0C0262514H
ERROR_GRAPHICS_OPM_OUTPUT_DOES_NOT_SUPPORT_CGMSA EQU    0C0262515H
ERROR_GRAPHICS_OPM_HDCP_SRM_NEVER_SET           EQU     0C0262516H
ERROR_GRAPHICS_OPM_RESOLUTION_TOO_HIGH          EQU     0C0262517H
ERROR_GRAPHICS_OPM_ALL_HDCP_HARDWARE_ALREADY_IN_USE EQU 0C0262518H
ERROR_GRAPHICS_OPM_VIDEO_OUTPUT_NO_LONGER_EXISTS EQU    0C026251AH
ERROR_GRAPHICS_OPM_SESSION_TYPE_CHANGE_IN_PROGRESS EQU  0C026251BH
ERROR_GRAPHICS_OPM_VIDEO_OUTPUT_DOES_NOT_HAVE_COPP_SEMANTICS EQU 0C026251CH
ERROR_GRAPHICS_OPM_INVALID_INFORMATION_REQUEST  EQU     0C026251DH
ERROR_GRAPHICS_OPM_DRIVER_INTERNAL_ERROR        EQU     0C026251EH
ERROR_GRAPHICS_OPM_VIDEO_OUTPUT_DOES_NOT_HAVE_OPM_SEMANTICS EQU 0C026251FH
ERROR_GRAPHICS_OPM_SIGNALING_NOT_SUPPORTED      EQU     0C0262520H
ERROR_GRAPHICS_OPM_INVALID_CONFIGURATION_REQUEST EQU    0C0262521H
ERROR_GRAPHICS_I2C_NOT_SUPPORTED                EQU     0C0262580H
ERROR_GRAPHICS_I2C_DEVICE_DOES_NOT_EXIST        EQU     0C0262581H
ERROR_GRAPHICS_I2C_ERROR_TRANSMITTING_DATA      EQU     0C0262582H
ERROR_GRAPHICS_I2C_ERROR_RECEIVING_DATA         EQU     0C0262583H
ERROR_GRAPHICS_DDCCI_VCP_NOT_SUPPORTED          EQU     0C0262584H
ERROR_GRAPHICS_DDCCI_INVALID_DATA               EQU     0C0262585H
ERROR_GRAPHICS_DDCCI_MONITOR_RETURNED_INVALID_TIMING_STATUS_BYTE EQU 0C0262586H
ERROR_GRAPHICS_MCA_INVALID_CAPABILITIES_STRING  EQU     0C0262587H
ERROR_GRAPHICS_MCA_INTERNAL_ERROR               EQU     0C0262588H
ERROR_GRAPHICS_DDCCI_INVALID_MESSAGE_COMMAND    EQU     0C0262589H
ERROR_GRAPHICS_DDCCI_INVALID_MESSAGE_LENGTH     EQU     0C026258AH
ERROR_GRAPHICS_DDCCI_INVALID_MESSAGE_CHECKSUM   EQU     0C026258BH
ERROR_GRAPHICS_INVALID_PHYSICAL_MONITOR_HANDLE  EQU     0C026258CH
ERROR_GRAPHICS_MONITOR_NO_LONGER_EXISTS         EQU     0C026258DH
ERROR_GRAPHICS_DDCCI_CURRENT_CURRENT_VALUE_GREATER_THAN_MAXIMUM_VALUE EQU 0C02625D8H
ERROR_GRAPHICS_MCA_INVALID_VCP_VERSION          EQU     0C02625D9H
ERROR_GRAPHICS_MCA_MONITOR_VIOLATES_MCCS_SPECIFICATION EQU 0C02625DAH
ERROR_GRAPHICS_MCA_MCCS_VERSION_MISMATCH        EQU     0C02625DBH
ERROR_GRAPHICS_MCA_UNSUPPORTED_MCCS_VERSION     EQU     0C02625DCH
ERROR_GRAPHICS_MCA_INVALID_TECHNOLOGY_TYPE_RETURNED EQU 0C02625DEH
ERROR_GRAPHICS_MCA_UNSUPPORTED_COLOR_TEMPERATURE EQU    0C02625DFH
ERROR_GRAPHICS_ONLY_CONSOLE_SESSION_SUPPORTED   EQU     0C02625E0H
ERROR_GRAPHICS_NO_DISPLAY_DEVICE_CORRESPONDS_TO_NAME EQU 0C02625E1H
ERROR_GRAPHICS_DISPLAY_DEVICE_NOT_ATTACHED_TO_DESKTOP EQU 0C02625E2H
ERROR_GRAPHICS_MIRRORING_DEVICES_NOT_SUPPORTED  EQU     0C02625E3H
ERROR_GRAPHICS_INVALID_POINTER                  EQU     0C02625E4H
ERROR_GRAPHICS_NO_MONITORS_CORRESPOND_TO_DISPLAY_DEVICE EQU 0C02625E5H
ERROR_GRAPHICS_PARAMETER_ARRAY_TOO_SMALL        EQU     0C02625E6H
ERROR_GRAPHICS_INTERNAL_ERROR                   EQU     0C02625E7H
ERROR_GRAPHICS_SESSION_TYPE_CHANGE_IN_PROGRESS  EQU     0C02605E8H

TPM_E_ERROR_MASK                                EQU     80280000H
TPM_E_AUTHFAIL                                  EQU     80280001H
TPM_E_BADINDEX                                  EQU     80280002H
TPM_E_BAD_PARAMETER                             EQU     80280003H
TPM_E_AUDITFAILURE                              EQU     80280004H
TPM_E_CLEAR_DISABLED                            EQU     80280005H
TPM_E_DEACTIVATED                               EQU     80280006H
TPM_E_DISABLED                                  EQU     80280007H
TPM_E_DISABLED_CMD                              EQU     80280008H
TPM_E_FAIL                                      EQU     80280009H
TPM_E_BAD_ORDINAL                               EQU     8028000AH
TPM_E_INSTALL_DISABLED                          EQU     8028000BH
TPM_E_INVALID_KEYHANDLE                         EQU     8028000CH
TPM_E_KEYNOTFOUND                               EQU     8028000DH
TPM_E_INAPPROPRIATE_ENC                         EQU     8028000EH
TPM_E_MIGRATEFAIL                               EQU     8028000FH
TPM_E_INVALID_PCR_INFO                          EQU     80280010H
TPM_E_NOSPACE                                   EQU     80280011H
TPM_E_NOSRK                                     EQU     80280012H
TPM_E_NOTSEALED_BLOB                            EQU     80280013H
TPM_E_OWNER_SET                                 EQU     80280014H
TPM_E_RESOURCES                                 EQU     80280015H
TPM_E_SHORTRANDOM                               EQU     80280016H
TPM_E_SIZE                                      EQU     80280017H
TPM_E_WRONGPCRVAL                               EQU     80280018H
TPM_E_BAD_PARAM_SIZE                            EQU     80280019H
TPM_E_SHA_THREAD                                EQU     8028001AH
TPM_E_SHA_ERROR                                 EQU     8028001BH
TPM_E_FAILEDSELFTEST                            EQU     8028001CH
TPM_E_AUTH2FAIL                                 EQU     8028001DH
TPM_E_BADTAG                                    EQU     8028001EH
TPM_E_IOERROR                                   EQU     8028001FH
TPM_E_ENCRYPT_ERROR                             EQU     80280020H
TPM_E_DECRYPT_ERROR                             EQU     80280021H
TPM_E_INVALID_AUTHHANDLE                        EQU     80280022H
TPM_E_NO_ENDORSEMENT                            EQU     80280023H
TPM_E_INVALID_KEYUSAGE                          EQU     80280024H
TPM_E_WRONG_ENTITYTYPE                          EQU     80280025H
TPM_E_INVALID_POSTINIT                          EQU     80280026H
TPM_E_INAPPROPRIATE_SIG                         EQU     80280027H
TPM_E_BAD_KEY_PROPERTY                          EQU     80280028H
TPM_E_BAD_MIGRATION                             EQU     80280029H
TPM_E_BAD_SCHEME                                EQU     8028002AH
TPM_E_BAD_DATASIZE                              EQU     8028002BH
TPM_E_BAD_MODE                                  EQU     8028002CH
TPM_E_BAD_PRESENCE                              EQU     8028002DH
TPM_E_BAD_VERSION                               EQU     8028002EH
TPM_E_NO_WRAP_TRANSPORT                         EQU     8028002FH
TPM_E_AUDITFAIL_UNSUCCESSFUL                    EQU     80280030H
TPM_E_AUDITFAIL_SUCCESSFUL                      EQU     80280031H
TPM_E_NOTRESETABLE                              EQU     80280032H
TPM_E_NOTLOCAL                                  EQU     80280033H
TPM_E_BAD_TYPE                                  EQU     80280034H
TPM_E_INVALID_RESOURCE                          EQU     80280035H
TPM_E_NOTFIPS                                   EQU     80280036H
TPM_E_INVALID_FAMILY                            EQU     80280037H
TPM_E_NO_NV_PERMISSION                          EQU     80280038H
TPM_E_REQUIRES_SIGN                             EQU     80280039H
TPM_E_KEY_NOTSUPPORTED                          EQU     8028003AH
TPM_E_AUTH_CONFLICT                             EQU     8028003BH
TPM_E_AREA_LOCKED                               EQU     8028003CH
TPM_E_BAD_LOCALITY                              EQU     8028003DH
TPM_E_READ_ONLY                                 EQU     8028003EH
TPM_E_PER_NOWRITE                               EQU     8028003FH
TPM_E_FAMILYCOUNT                               EQU     80280040H
TPM_E_WRITE_LOCKED                              EQU     80280041H
TPM_E_BAD_ATTRIBUTES                            EQU     80280042H
TPM_E_INVALID_STRUCTURE                         EQU     80280043H
TPM_E_KEY_OWNER_CONTROL                         EQU     80280044H
TPM_E_BAD_COUNTER                               EQU     80280045H
TPM_E_NOT_FULLWRITE                             EQU     80280046H
TPM_E_CONTEXT_GAP                               EQU     80280047H
TPM_E_MAXNVWRITES                               EQU     80280048H
TPM_E_NOOPERATOR                                EQU     80280049H
TPM_E_RESOURCEMISSING                           EQU     8028004AH
TPM_E_DELEGATE_LOCK                             EQU     8028004BH
TPM_E_DELEGATE_FAMILY                           EQU     8028004CH
TPM_E_DELEGATE_ADMIN                            EQU     8028004DH
TPM_E_TRANSPORT_NOTEXCLUSIVE                    EQU     8028004EH
TPM_E_OWNER_CONTROL                             EQU     8028004FH
TPM_E_DAA_RESOURCES                             EQU     80280050H
TPM_E_DAA_INPUT_DATA0                           EQU     80280051H
TPM_E_DAA_INPUT_DATA1                           EQU     80280052H
TPM_E_DAA_ISSUER_SETTINGS                       EQU     80280053H
TPM_E_DAA_TPM_SETTINGS                          EQU     80280054H
TPM_E_DAA_STAGE                                 EQU     80280055H
TPM_E_DAA_ISSUER_VALIDITY                       EQU     80280056H
TPM_E_DAA_WRONG_W                               EQU     80280057H
TPM_E_BAD_HANDLE                                EQU     80280058H
TPM_E_BAD_DELEGATE                              EQU     80280059H
TPM_E_BADCONTEXT                                EQU     8028005AH
TPM_E_TOOMANYCONTEXTS                           EQU     8028005BH
TPM_E_MA_TICKET_SIGNATURE                       EQU     8028005CH
TPM_E_MA_DESTINATION                            EQU     8028005DH
TPM_E_MA_SOURCE                                 EQU     8028005EH
TPM_E_MA_AUTHORITY                              EQU     8028005FH
TPM_E_PERMANENTEK                               EQU     80280061H
TPM_E_BAD_SIGNATURE                             EQU     80280062H
TPM_E_NOCONTEXTSPACE                            EQU     80280063H
TPM_E_COMMAND_BLOCKED                           EQU     80280400H
TPM_E_INVALID_HANDLE                            EQU     80280401H
TPM_E_DUPLICATE_VHANDLE                         EQU     80280402H
TPM_E_EMBEDDED_COMMAND_BLOCKED                  EQU     80280403H
TPM_E_EMBEDDED_COMMAND_UNSUPPORTED              EQU     80280404H
TPM_E_RETRY                                     EQU     80280800H
TPM_E_NEEDS_SELFTEST                            EQU     80280801H
TPM_E_DOING_SELFTEST                            EQU     80280802H
TPM_E_DEFEND_LOCK_RUNNING                       EQU     80280803H

TBS_E_INTERNAL_ERROR                            EQU     80284001H
TBS_E_BAD_PARAMETER                             EQU     80284002H
TBS_E_INVALID_OUTPUT_POINTER                    EQU     80284003H
TBS_E_INVALID_CONTEXT                           EQU     80284004H
TBS_E_INSUFFICIENT_BUFFER                       EQU     80284005H
TBS_E_IOERROR                                   EQU     80284006H
TBS_E_INVALID_CONTEXT_PARAM                     EQU     80284007H
TBS_E_SERVICE_NOT_RUNNING                       EQU     80284008H
TBS_E_TOO_MANY_TBS_CONTEXTS                     EQU     80284009H
TBS_E_TOO_MANY_RESOURCES                        EQU     8028400AH
TBS_E_SERVICE_START_PENDING                     EQU     8028400BH
TBS_E_PPI_NOT_SUPPORTED                         EQU     8028400CH
TBS_E_COMMAND_CANCELED                          EQU     8028400DH
TBS_E_BUFFER_TOO_LARGE                          EQU     8028400EH
TBS_E_TPM_NOT_FOUND                             EQU     8028400FH
TBS_E_SERVICE_DISABLED                          EQU     80284010H
TBS_E_NO_EVENT_LOG                              EQU     80284011H

TPMAPI_E_INVALID_STATE                          EQU     80290100H
TPMAPI_E_NOT_ENOUGH_DATA                        EQU     80290101H
TPMAPI_E_TOO_MUCH_DATA                          EQU     80290102H
TPMAPI_E_INVALID_OUTPUT_POINTER                 EQU     80290103H
TPMAPI_E_INVALID_PARAMETER                      EQU     80290104H
TPMAPI_E_OUT_OF_MEMORY                          EQU     80290105H
TPMAPI_E_BUFFER_TOO_SMALL                       EQU     80290106H
TPMAPI_E_INTERNAL_ERROR                         EQU     80290107H
TPMAPI_E_ACCESS_DENIED                          EQU     80290108H
TPMAPI_E_AUTHORIZATION_FAILED                   EQU     80290109H
TPMAPI_E_INVALID_CONTEXT_HANDLE                 EQU     8029010AH
TPMAPI_E_TBS_COMMUNICATION_ERROR                EQU     8029010BH
TPMAPI_E_TPM_COMMAND_ERROR                      EQU     8029010CH
TPMAPI_E_MESSAGE_TOO_LARGE                      EQU     8029010DH
TPMAPI_E_INVALID_ENCODING                       EQU     8029010EH
TPMAPI_E_INVALID_KEY_SIZE                       EQU     8029010FH
TPMAPI_E_ENCRYPTION_FAILED                      EQU     80290110H
TPMAPI_E_INVALID_KEY_PARAMS                     EQU     80290111H
TPMAPI_E_INVALID_MIGRATION_AUTHORIZATION_BLOB   EQU     80290112H
TPMAPI_E_INVALID_PCR_INDEX                      EQU     80290113H
TPMAPI_E_INVALID_DELEGATE_BLOB                  EQU     80290114H
TPMAPI_E_INVALID_CONTEXT_PARAMS                 EQU     80290115H
TPMAPI_E_INVALID_KEY_BLOB                       EQU     80290116H
TPMAPI_E_INVALID_PCR_DATA                       EQU     80290117H
TPMAPI_E_INVALID_OWNER_AUTH                     EQU     80290118H
TPMAPI_E_FIPS_RNG_CHECK_FAILED                  EQU     80290119H
TPMAPI_E_EMPTY_TCG_LOG                          EQU     8029011AH
TPMAPI_E_INVALID_TCG_LOG_ENTRY                  EQU     8029011BH
TPMAPI_E_TCG_SEPARATOR_ABSENT                   EQU     8029011CH
TPMAPI_E_TCG_INVALID_DIGEST_ENTRY               EQU     8029011DH

TBSIMP_E_BUFFER_TOO_SMALL                       EQU     80290200H
TBSIMP_E_CLEANUP_FAILED                         EQU     80290201H
TBSIMP_E_INVALID_CONTEXT_HANDLE                 EQU     80290202H
TBSIMP_E_INVALID_CONTEXT_PARAM                  EQU     80290203H
TBSIMP_E_TPM_ERROR                              EQU     80290204H
TBSIMP_E_HASH_BAD_KEY                           EQU     80290205H
TBSIMP_E_DUPLICATE_VHANDLE                      EQU     80290206H
TBSIMP_E_INVALID_OUTPUT_POINTER                 EQU     80290207H
TBSIMP_E_INVALID_PARAMETER                      EQU     80290208H
TBSIMP_E_RPC_INIT_FAILED                        EQU     80290209H
TBSIMP_E_SCHEDULER_NOT_RUNNING                  EQU     8029020AH
TBSIMP_E_COMMAND_CANCELED                       EQU     8029020BH
TBSIMP_E_OUT_OF_MEMORY                          EQU     8029020CH
TBSIMP_E_LIST_NO_MORE_ITEMS                     EQU     8029020DH
TBSIMP_E_LIST_NOT_FOUND                         EQU     8029020EH
TBSIMP_E_NOT_ENOUGH_SPACE                       EQU     8029020FH
TBSIMP_E_NOT_ENOUGH_TPM_CONTEXTS                EQU     80290210H
TBSIMP_E_COMMAND_FAILED                         EQU     80290211H
TBSIMP_E_UNKNOWN_ORDINAL                        EQU     80290212H
TBSIMP_E_RESOURCE_EXPIRED                       EQU     80290213H
TBSIMP_E_INVALID_RESOURCE                       EQU     80290214H
TBSIMP_E_NOTHING_TO_UNLOAD                      EQU     80290215H
TBSIMP_E_HASH_TABLE_FULL                        EQU     80290216H
TBSIMP_E_TOO_MANY_TBS_CONTEXTS                  EQU     80290217H
TBSIMP_E_TOO_MANY_RESOURCES                     EQU     80290218H
TBSIMP_E_PPI_NOT_SUPPORTED                      EQU     80290219H
TBSIMP_E_TPM_INCOMPATIBLE                       EQU     8029021AH
TBSIMP_E_NO_EVENT_LOG                           EQU     8029021BH

TPM_E_PPI_ACPI_FAILURE                          EQU     80290300H
TPM_E_PPI_USER_ABORT                            EQU     80290301H
TPM_E_PPI_BIOS_FAILURE                          EQU     80290302H
TPM_E_PPI_NOT_SUPPORTED                         EQU     80290303H

PLA_E_DCS_NOT_FOUND                             EQU     80300002H
PLA_E_DCS_IN_USE                                EQU     803000AAH
PLA_E_TOO_MANY_FOLDERS                          EQU     80300045H
PLA_E_NO_MIN_DISK                               EQU     80300070H
PLA_E_DCS_ALREADY_EXISTS                        EQU     803000B7H
PLA_S_PROPERTY_IGNORED                          EQU     00300100H
PLA_E_PROPERTY_CONFLICT                         EQU     80300101H
PLA_E_DCS_SINGLETON_REQUIRED                    EQU     80300102H
PLA_E_CREDENTIALS_REQUIRED                      EQU     80300103H
PLA_E_DCS_NOT_RUNNING                           EQU     80300104H
PLA_E_CONFLICT_INCL_EXCL_API                    EQU     80300105H
PLA_E_NETWORK_EXE_NOT_VALID                     EQU     80300106H
PLA_E_EXE_ALREADY_CONFIGURED                    EQU     80300107H
PLA_E_EXE_PATH_NOT_VALID                        EQU     80300108H
PLA_E_DC_ALREADY_EXISTS                         EQU     80300109H
PLA_E_DCS_START_WAIT_TIMEOUT                    EQU     8030010AH
PLA_E_DC_START_WAIT_TIMEOUT                     EQU     8030010BH
PLA_E_REPORT_WAIT_TIMEOUT                       EQU     8030010CH
PLA_E_NO_DUPLICATES                             EQU     8030010DH
PLA_E_EXE_FULL_PATH_REQUIRED                    EQU     8030010EH
PLA_E_INVALID_SESSION_NAME                      EQU     8030010FH
PLA_E_PLA_CHANNEL_NOT_ENABLED                   EQU     80300110H
PLA_E_TASKSCHED_CHANNEL_NOT_ENABLED             EQU     80300111H
PLA_E_RULES_MANAGER_FAILED                      EQU     80300112H
PLA_E_CABAPI_FAILURE                            EQU     80300113H

FVE_E_LOCKED_VOLUME                             EQU     80310000H
FVE_E_NOT_ENCRYPTED                             EQU     80310001H
FVE_E_NO_TPM_BIOS                               EQU     80310002H
FVE_E_NO_MBR_METRIC                             EQU     80310003H
FVE_E_NO_BOOTSECTOR_METRIC                      EQU     80310004H
FVE_E_NO_BOOTMGR_METRIC                         EQU     80310005H
FVE_E_WRONG_BOOTMGR                             EQU     80310006H
FVE_E_SECURE_KEY_REQUIRED                       EQU     80310007H
FVE_E_NOT_ACTIVATED                             EQU     80310008H
FVE_E_ACTION_NOT_ALLOWED                        EQU     80310009H
FVE_E_AD_SCHEMA_NOT_INSTALLED                   EQU     8031000AH
FVE_E_AD_INVALID_DATATYPE                       EQU     8031000BH
FVE_E_AD_INVALID_DATASIZE                       EQU     8031000CH
FVE_E_AD_NO_VALUES                              EQU     8031000DH
FVE_E_AD_ATTR_NOT_SET                           EQU     8031000EH
FVE_E_AD_GUID_NOT_FOUND                         EQU     8031000FH
FVE_E_BAD_INFORMATION                           EQU     80310010H
FVE_E_TOO_SMALL                                 EQU     80310011H
FVE_E_SYSTEM_VOLUME                             EQU     80310012H
FVE_E_FAILED_WRONG_FS                           EQU     80310013H
FVE_E_BAD_PARTITION_SIZE                        EQU     80310014H
FVE_E_NOT_SUPPORTED                             EQU     80310015H
FVE_E_BAD_DATA                                  EQU     80310016H
FVE_E_VOLUME_NOT_BOUND                          EQU     80310017H
FVE_E_TPM_NOT_OWNED                             EQU     80310018H
FVE_E_NOT_DATA_VOLUME                           EQU     80310019H
FVE_E_AD_INSUFFICIENT_BUFFER                    EQU     8031001AH
FVE_E_CONV_READ                                 EQU     8031001BH
FVE_E_CONV_WRITE                                EQU     8031001CH
FVE_E_KEY_REQUIRED                              EQU     8031001DH
FVE_E_CLUSTERING_NOT_SUPPORTED                  EQU     8031001EH
FVE_E_VOLUME_BOUND_ALREADY                      EQU     8031001FH
FVE_E_OS_NOT_PROTECTED                          EQU     80310020H
FVE_E_PROTECTION_DISABLED                       EQU     80310021H
FVE_E_RECOVERY_KEY_REQUIRED                     EQU     80310022H
FVE_E_FOREIGN_VOLUME                            EQU     80310023H
FVE_E_OVERLAPPED_UPDATE                         EQU     80310024H
FVE_E_TPM_SRK_AUTH_NOT_ZERO                     EQU     80310025H
FVE_E_FAILED_SECTOR_SIZE                        EQU     80310026H
FVE_E_FAILED_AUTHENTICATION                     EQU     80310027H
FVE_E_NOT_OS_VOLUME                             EQU     80310028H
FVE_E_AUTOUNLOCK_ENABLED                        EQU     80310029H
FVE_E_WRONG_BOOTSECTOR                          EQU     8031002AH
FVE_E_WRONG_SYSTEM_FS                           EQU     8031002BH
FVE_E_POLICY_PASSWORD_REQUIRED                  EQU     8031002CH
FVE_E_CANNOT_SET_FVEK_ENCRYPTED                 EQU     8031002DH
FVE_E_CANNOT_ENCRYPT_NO_KEY                     EQU     8031002EH
FVE_E_BOOTABLE_CDDVD                            EQU     80310030H
FVE_E_PROTECTOR_EXISTS                          EQU     80310031H
FVE_E_RELATIVE_PATH                             EQU     80310032H
FVE_E_PROTECTOR_NOT_FOUND                       EQU     80310033H
FVE_E_INVALID_KEY_FORMAT                        EQU     80310034H
FVE_E_INVALID_PASSWORD_FORMAT                   EQU     80310035H
FVE_E_FIPS_RNG_CHECK_FAILED                     EQU     80310036H
FVE_E_FIPS_PREVENTS_RECOVERY_PASSWORD           EQU     80310037H
FVE_E_FIPS_PREVENTS_EXTERNAL_KEY_EXPORT         EQU     80310038H
FVE_E_NOT_DECRYPTED                             EQU     80310039H
FVE_E_INVALID_PROTECTOR_TYPE                    EQU     8031003AH
FVE_E_NO_PROTECTORS_TO_TEST                     EQU     8031003BH
FVE_E_KEYFILE_NOT_FOUND                         EQU     8031003CH
FVE_E_KEYFILE_INVALID                           EQU     8031003DH
FVE_E_KEYFILE_NO_VMK                            EQU     8031003EH
FVE_E_TPM_DISABLED                              EQU     8031003FH
FVE_E_NOT_ALLOWED_IN_SAFE_MODE                  EQU     80310040H
FVE_E_TPM_INVALID_PCR                           EQU     80310041H
FVE_E_TPM_NO_VMK                                EQU     80310042H
FVE_E_PIN_INVALID                               EQU     80310043H
FVE_E_AUTH_INVALID_APPLICATION                  EQU     80310044H
FVE_E_AUTH_INVALID_CONFIG                       EQU     80310045H
FVE_E_FIPS_DISABLE_PROTECTION_NOT_ALLOWED       EQU     80310046H
FVE_E_FS_NOT_EXTENDED                           EQU     80310047H
FVE_E_FIRMWARE_TYPE_NOT_SUPPORTED               EQU     80310048H
FVE_E_NO_LICENSE                                EQU     80310049H
FVE_E_NOT_ON_STACK                              EQU     8031004AH
FVE_E_FS_MOUNTED                                EQU     8031004BH
FVE_E_TOKEN_NOT_IMPERSONATED                    EQU     8031004CH
FVE_E_DRY_RUN_FAILED                            EQU     8031004DH
FVE_E_REBOOT_REQUIRED                           EQU     8031004EH
FVE_E_DEBUGGER_ENABLED                          EQU     8031004FH
FVE_E_RAW_ACCESS                                EQU     80310050H
FVE_E_RAW_BLOCKED                               EQU     80310051H
FVE_E_BCD_APPLICATIONS_PATH_INCORRECT           EQU     80310052H
FVE_E_NOT_ALLOWED_IN_VERSION                    EQU     80310053H
FVE_E_NO_AUTOUNLOCK_MASTER_KEY                  EQU     80310054H
FVE_E_MOR_FAILED                                EQU     80310055H
FVE_E_HIDDEN_VOLUME                             EQU     80310056H
FVE_E_TRANSIENT_STATE                           EQU     80310057H
FVE_E_PUBKEY_NOT_ALLOWED                        EQU     80310058H
FVE_E_VOLUME_HANDLE_OPEN                        EQU     80310059H
FVE_E_NO_FEATURE_LICENSE                        EQU     8031005AH
FVE_E_INVALID_STARTUP_OPTIONS                   EQU     8031005BH
FVE_E_POLICY_RECOVERY_PASSWORD_NOT_ALLOWED      EQU     8031005CH
FVE_E_POLICY_RECOVERY_PASSWORD_REQUIRED         EQU     8031005DH
FVE_E_POLICY_RECOVERY_KEY_NOT_ALLOWED           EQU     8031005EH
FVE_E_POLICY_RECOVERY_KEY_REQUIRED              EQU     8031005FH
FVE_E_POLICY_STARTUP_PIN_NOT_ALLOWED            EQU     80310060H
FVE_E_POLICY_STARTUP_PIN_REQUIRED               EQU     80310061H
FVE_E_POLICY_STARTUP_KEY_NOT_ALLOWED            EQU     80310062H
FVE_E_POLICY_STARTUP_KEY_REQUIRED               EQU     80310063H
FVE_E_POLICY_STARTUP_PIN_KEY_NOT_ALLOWED        EQU     80310064H
FVE_E_POLICY_STARTUP_PIN_KEY_REQUIRED           EQU     80310065H
FVE_E_POLICY_STARTUP_TPM_NOT_ALLOWED            EQU     80310066H
FVE_E_POLICY_STARTUP_TPM_REQUIRED               EQU     80310067H
FVE_E_POLICY_INVALID_PIN_LENGTH                 EQU     80310068H
FVE_E_KEY_PROTECTOR_NOT_SUPPORTED               EQU     80310069H
FVE_E_POLICY_PASSPHRASE_NOT_ALLOWED             EQU     8031006AH
FVE_E_POLICY_PASSPHRASE_REQUIRED                EQU     8031006BH
FVE_E_FIPS_PREVENTS_PASSPHRASE                  EQU     8031006CH
FVE_E_OS_VOLUME_PASSPHRASE_NOT_ALLOWED          EQU     8031006DH
FVE_E_INVALID_BITLOCKER_OID                     EQU     8031006EH
FVE_E_VOLUME_TOO_SMALL                          EQU     8031006FH
FVE_E_DV_NOT_SUPPORTED_ON_FS                    EQU     80310070H
FVE_E_DV_NOT_ALLOWED_BY_GP                      EQU     80310071H
FVE_E_POLICY_USER_CERTIFICATE_NOT_ALLOWED       EQU     80310072H
FVE_E_POLICY_USER_CERTIFICATE_REQUIRED          EQU     80310073H
FVE_E_POLICY_USER_CERT_MUST_BE_HW               EQU     80310074H
FVE_E_POLICY_USER_CONFIGURE_FDV_AUTOUNLOCK_NOT_ALLOWED EQU 80310075H
FVE_E_POLICY_USER_CONFIGURE_RDV_AUTOUNLOCK_NOT_ALLOWED EQU 80310076H
FVE_E_POLICY_USER_CONFIGURE_RDV_NOT_ALLOWED     EQU     80310077H
FVE_E_POLICY_USER_ENABLE_RDV_NOT_ALLOWED        EQU     80310078H
FVE_E_POLICY_USER_DISABLE_RDV_NOT_ALLOWED       EQU     80310079H
FVE_E_POLICY_INVALID_PASSPHRASE_LENGTH          EQU     80310080H
FVE_E_POLICY_PASSPHRASE_TOO_SIMPLE              EQU     80310081H
FVE_E_RECOVERY_PARTITION                        EQU     80310082H
FVE_E_POLICY_CONFLICT_FDV_RK_OFF_AUK_ON         EQU     80310083H
FVE_E_POLICY_CONFLICT_RDV_RK_OFF_AUK_ON         EQU     80310084H
FVE_E_NON_BITLOCKER_OID                         EQU     80310085H
FVE_E_POLICY_PROHIBITS_SELFSIGNED               EQU     80310086H
FVE_E_POLICY_CONFLICT_RO_AND_STARTUP_KEY_REQUIRED EQU   80310087H
FVE_E_CONV_RECOVERY_FAILED                      EQU     80310088H
FVE_E_VIRTUALIZED_SPACE_TOO_BIG                 EQU     80310089H
FVE_E_POLICY_CONFLICT_OSV_RP_OFF_ADB_ON         EQU     80310090H
FVE_E_POLICY_CONFLICT_FDV_RP_OFF_ADB_ON         EQU     80310091H
FVE_E_POLICY_CONFLICT_RDV_RP_OFF_ADB_ON         EQU     80310092H
FVE_E_NON_BITLOCKER_KU                          EQU     80310093H
FVE_E_PRIVATEKEY_AUTH_FAILED                    EQU     80310094H
FVE_E_REMOVAL_OF_DRA_FAILED                     EQU     80310095H
FVE_E_OPERATION_NOT_SUPPORTED_ON_VISTA_VOLUME   EQU     80310096H
FVE_E_CANT_LOCK_AUTOUNLOCK_ENABLED_VOLUME       EQU     80310097H
FVE_E_FIPS_HASH_KDF_NOT_ALLOWED                 EQU     80310098H
FVE_E_ENH_PIN_INVALID                           EQU     80310099H
FVE_E_INVALID_PIN_CHARS                         EQU     8031009AH
FVE_E_INVALID_DATUM_TYPE                        EQU     8031009BH

FWP_E_CALLOUT_NOT_FOUND                         EQU     80320001H
FWP_E_CONDITION_NOT_FOUND                       EQU     80320002H
FWP_E_FILTER_NOT_FOUND                          EQU     80320003H
FWP_E_LAYER_NOT_FOUND                           EQU     80320004H
FWP_E_PROVIDER_NOT_FOUND                        EQU     80320005H
FWP_E_PROVIDER_CONTEXT_NOT_FOUND                EQU     80320006H
FWP_E_SUBLAYER_NOT_FOUND                        EQU     80320007H
FWP_E_NOT_FOUND                                 EQU     80320008H
FWP_E_ALREADY_EXISTS                            EQU     80320009H
FWP_E_IN_USE                                    EQU     8032000AH
FWP_E_DYNAMIC_SESSION_IN_PROGRESS               EQU     8032000BH
FWP_E_WRONG_SESSION                             EQU     8032000CH
FWP_E_NO_TXN_IN_PROGRESS                        EQU     8032000DH
FWP_E_TXN_IN_PROGRESS                           EQU     8032000EH
FWP_E_TXN_ABORTED                               EQU     8032000FH
FWP_E_SESSION_ABORTED                           EQU     80320010H
FWP_E_INCOMPATIBLE_TXN                          EQU     80320011H
FWP_E_TIMEOUT                                   EQU     80320012H
FWP_E_NET_EVENTS_DISABLED                       EQU     80320013H
FWP_E_INCOMPATIBLE_LAYER                        EQU     80320014H
FWP_E_KM_CLIENTS_ONLY                           EQU     80320015H
FWP_E_LIFETIME_MISMATCH                         EQU     80320016H
FWP_E_BUILTIN_OBJECT                            EQU     80320017H
FWP_E_TOO_MANY_CALLOUTS                         EQU     80320018H
FWP_E_NOTIFICATION_DROPPED                      EQU     80320019H
FWP_E_TRAFFIC_MISMATCH                          EQU     8032001AH
FWP_E_INCOMPATIBLE_SA_STATE                     EQU     8032001BH
FWP_E_NULL_POINTER                              EQU     8032001CH
FWP_E_INVALID_ENUMERATOR                        EQU     8032001DH
FWP_E_INVALID_FLAGS                             EQU     8032001EH
FWP_E_INVALID_NET_MASK                          EQU     8032001FH
FWP_E_INVALID_RANGE                             EQU     80320020H
FWP_E_INVALID_INTERVAL                          EQU     80320021H
FWP_E_ZERO_LENGTH_ARRAY                         EQU     80320022H
FWP_E_NULL_DISPLAY_NAME                         EQU     80320023H
FWP_E_INVALID_ACTION_TYPE                       EQU     80320024H
FWP_E_INVALID_WEIGHT                            EQU     80320025H
FWP_E_MATCH_TYPE_MISMATCH                       EQU     80320026H
FWP_E_TYPE_MISMATCH                             EQU     80320027H
FWP_E_OUT_OF_BOUNDS                             EQU     80320028H
FWP_E_RESERVED                                  EQU     80320029H
FWP_E_DUPLICATE_CONDITION                       EQU     8032002AH
FWP_E_DUPLICATE_KEYMOD                          EQU     8032002BH
FWP_E_ACTION_INCOMPATIBLE_WITH_LAYER            EQU     8032002CH
FWP_E_ACTION_INCOMPATIBLE_WITH_SUBLAYER         EQU     8032002DH
FWP_E_CONTEXT_INCOMPATIBLE_WITH_LAYER           EQU     8032002EH
FWP_E_CONTEXT_INCOMPATIBLE_WITH_CALLOUT         EQU     8032002FH
FWP_E_INCOMPATIBLE_AUTH_METHOD                  EQU     80320030H
FWP_E_INCOMPATIBLE_DH_GROUP                     EQU     80320031H
FWP_E_EM_NOT_SUPPORTED                          EQU     80320032H
FWP_E_NEVER_MATCH                               EQU     80320033H
FWP_E_PROVIDER_CONTEXT_MISMATCH                 EQU     80320034H
FWP_E_INVALID_PARAMETER                         EQU     80320035H
FWP_E_TOO_MANY_SUBLAYERS                        EQU     80320036H
FWP_E_CALLOUT_NOTIFICATION_FAILED               EQU     80320037H
FWP_E_INVALID_AUTH_TRANSFORM                    EQU     80320038H
FWP_E_INVALID_CIPHER_TRANSFORM                  EQU     80320039H
FWP_E_DROP_NOICMP                               EQU     80320104H
FWP_E_INCOMPATIBLE_CIPHER_TRANSFORM             EQU     8032003AH
FWP_E_INVALID_TRANSFORM_COMBINATION             EQU     8032003BH
FWP_E_DUPLICATE_AUTH_METHOD                     EQU     8032003CH

WS_S_ASYNC                                      EQU     003D0000H
WS_S_END                                        EQU     003D0001H
WS_E_INVALID_FORMAT                             EQU     803D0000H
WS_E_OBJECT_FAULTED                             EQU     803D0001H
WS_E_NUMERIC_OVERFLOW                           EQU     803D0002H
WS_E_INVALID_OPERATION                          EQU     803D0003H
WS_E_OPERATION_ABORTED                          EQU     803D0004H
WS_E_ENDPOINT_ACCESS_DENIED                     EQU     803D0005H
WS_E_OPERATION_TIMED_OUT                        EQU     803D0006H
WS_E_OPERATION_ABANDONED                        EQU     803D0007H
WS_E_QUOTA_EXCEEDED                             EQU     803D0008H
WS_E_NO_TRANSLATION_AVAILABLE                   EQU     803D0009H
WS_E_SECURITY_VERIFICATION_FAILURE              EQU     803D000AH
WS_E_ADDRESS_IN_USE                             EQU     803D000BH
WS_E_ADDRESS_NOT_AVAILABLE                      EQU     803D000CH
WS_E_ENDPOINT_NOT_FOUND                         EQU     803D000DH
WS_E_ENDPOINT_NOT_AVAILABLE                     EQU     803D000EH
WS_E_ENDPOINT_FAILURE                           EQU     803D000FH
WS_E_ENDPOINT_UNREACHABLE                       EQU     803D0010H
WS_E_ENDPOINT_ACTION_NOT_SUPPORTED              EQU     803D0011H
WS_E_ENDPOINT_TOO_BUSY                          EQU     803D0012H
WS_E_ENDPOINT_FAULT_RECEIVED                    EQU     803D0013H
WS_E_ENDPOINT_DISCONNECTED                      EQU     803D0014H
WS_E_PROXY_FAILURE                              EQU     803D0015H
WS_E_PROXY_ACCESS_DENIED                        EQU     803D0016H
WS_E_NOT_SUPPORTED                              EQU     803D0017H
WS_E_PROXY_REQUIRES_BASIC_AUTH                  EQU     803D0018H
WS_E_PROXY_REQUIRES_DIGEST_AUTH                 EQU     803D0019H
WS_E_PROXY_REQUIRES_NTLM_AUTH                   EQU     803D001AH
WS_E_PROXY_REQUIRES_NEGOTIATE_AUTH              EQU     803D001BH
WS_E_SERVER_REQUIRES_BASIC_AUTH                 EQU     803D001CH
WS_E_SERVER_REQUIRES_DIGEST_AUTH                EQU     803D001DH
WS_E_SERVER_REQUIRES_NTLM_AUTH                  EQU     803D001EH
WS_E_SERVER_REQUIRES_NEGOTIATE_AUTH             EQU     803D001FH
WS_E_INVALID_ENDPOINT_URL                       EQU     803D0020H
WS_E_OTHER                                      EQU     803D0021H
WS_E_SECURITY_TOKEN_EXPIRED                     EQU     803D0022H
WS_E_SECURITY_SYSTEM_FAILURE                    EQU     803D0023H

ERROR_NDIS_INTERFACE_CLOSING                    EQU     080340002H
ERROR_NDIS_BAD_VERSION                          EQU     080340004H
ERROR_NDIS_BAD_CHARACTERISTICS                  EQU     080340005H
ERROR_NDIS_ADAPTER_NOT_FOUND                    EQU     080340006H
ERROR_NDIS_OPEN_FAILED                          EQU     080340007H
ERROR_NDIS_DEVICE_FAILED                        EQU     080340008H
ERROR_NDIS_MULTICAST_FULL                       EQU     080340009H
ERROR_NDIS_MULTICAST_EXISTS                     EQU     08034000AH
ERROR_NDIS_MULTICAST_NOT_FOUND                  EQU     08034000BH
ERROR_NDIS_REQUEST_ABORTED                      EQU     08034000CH
ERROR_NDIS_RESET_IN_PROGRESS                    EQU     08034000DH
ERROR_NDIS_NOT_SUPPORTED                        EQU     0803400BBH
ERROR_NDIS_INVALID_PACKET                       EQU     08034000FH
ERROR_NDIS_ADAPTER_NOT_READY                    EQU     080340011H
ERROR_NDIS_INVALID_LENGTH                       EQU     080340014H
ERROR_NDIS_INVALID_DATA                         EQU     080340015H
ERROR_NDIS_BUFFER_TOO_SHORT                     EQU     080340016H
ERROR_NDIS_INVALID_OID                          EQU     080340017H
ERROR_NDIS_ADAPTER_REMOVED                      EQU     080340018H
ERROR_NDIS_UNSUPPORTED_MEDIA                    EQU     080340019H
ERROR_NDIS_GROUP_ADDRESS_IN_USE                 EQU     08034001AH
ERROR_NDIS_FILE_NOT_FOUND                       EQU     08034001BH
ERROR_NDIS_ERROR_READING_FILE                   EQU     08034001CH
ERROR_NDIS_ALREADY_MAPPED                       EQU     08034001DH
ERROR_NDIS_RESOURCE_CONFLICT                    EQU     08034001EH
ERROR_NDIS_MEDIA_DISCONNECTED                   EQU     08034001FH
ERROR_NDIS_INVALID_ADDRESS                      EQU     080340022H
ERROR_NDIS_INVALID_DEVICE_REQUEST               EQU     080340010H
ERROR_NDIS_PAUSED                               EQU     08034002AH
ERROR_NDIS_INTERFACE_NOT_FOUND                  EQU     08034002BH
ERROR_NDIS_UNSUPPORTED_REVISION                 EQU     08034002CH
ERROR_NDIS_INVALID_PORT                         EQU     08034002DH
ERROR_NDIS_INVALID_PORT_STATE                   EQU     08034002EH
ERROR_NDIS_LOW_POWER_STATE                      EQU     08034002FH
ERROR_NDIS_DOT11_AUTO_CONFIG_ENABLED            EQU     080342000H
ERROR_NDIS_DOT11_MEDIA_IN_USE                   EQU     080342001H
ERROR_NDIS_DOT11_POWER_STATE_INVALID            EQU     080342002H
ERROR_NDIS_PM_WOL_PATTERN_LIST_FULL             EQU     080342003H
ERROR_NDIS_PM_PROTOCOL_OFFLOAD_LIST_FULL        EQU     080342004H
ERROR_NDIS_INDICATION_REQUIRED                  EQU     000340001H
ERROR_NDIS_OFFLOAD_POLICY                       EQU     0C034100FH
ERROR_NDIS_OFFLOAD_CONNECTION_REJECTED          EQU     0C0341012H
ERROR_NDIS_OFFLOAD_PATH_REJECTED                EQU     0C0341013H

ERROR_HV_INVALID_HYPERCALL_CODE                 EQU     0C0350002H
ERROR_HV_INVALID_HYPERCALL_INPUT                EQU     0C0350003H
ERROR_HV_INVALID_ALIGNMENT                      EQU     0C0350004H
ERROR_HV_INVALID_PARAMETER                      EQU     0C0350005H
ERROR_HV_ACCESS_DENIED                          EQU     0C0350006H
ERROR_HV_INVALID_PARTITION_STATE                EQU     0C0350007H
ERROR_HV_OPERATION_DENIED                       EQU     0C0350008H
ERROR_HV_UNKNOWN_PROPERTY                       EQU     0C0350009H
ERROR_HV_PROPERTY_VALUE_OUT_OF_RANGE            EQU     0C035000AH
ERROR_HV_INSUFFICIENT_MEMORY                    EQU     0C035000BH
ERROR_HV_PARTITION_TOO_DEEP                     EQU     0C035000CH
ERROR_HV_INVALID_PARTITION_ID                   EQU     0C035000DH
ERROR_HV_INVALID_VP_INDEX                       EQU     0C035000EH
ERROR_HV_INVALID_PORT_ID                        EQU     0C0350011H
ERROR_HV_INVALID_CONNECTION_ID                  EQU     0C0350012H
ERROR_HV_INSUFFICIENT_BUFFERS                   EQU     0C0350013H
ERROR_HV_NOT_ACKNOWLEDGED                       EQU     0C0350014H
ERROR_HV_ACKNOWLEDGED                           EQU     0C0350016H
ERROR_HV_INVALID_SAVE_RESTORE_STATE             EQU     0C0350017H
ERROR_HV_INVALID_SYNIC_STATE                    EQU     0C0350018H
ERROR_HV_OBJECT_IN_USE                          EQU     0C0350019H
ERROR_HV_INVALID_PROXIMITY_DOMAIN_INFO          EQU     0C035001AH
ERROR_HV_NO_DATA                                EQU     0C035001BH
ERROR_HV_INACTIVE                               EQU     0C035001CH
ERROR_HV_NO_RESOURCES                           EQU     0C035001DH
ERROR_HV_FEATURE_UNAVAILABLE                    EQU     0C035001EH
ERROR_HV_NOT_PRESENT                            EQU     0C0351000H

ERROR_VID_DUPLICATE_HANDLER                     EQU     0C0370001H
ERROR_VID_TOO_MANY_HANDLERS                     EQU     0C0370002H
ERROR_VID_QUEUE_FULL                            EQU     0C0370003H
ERROR_VID_HANDLER_NOT_PRESENT                   EQU     0C0370004H
ERROR_VID_INVALID_OBJECT_NAME                   EQU     0C0370005H
ERROR_VID_PARTITION_NAME_TOO_LONG               EQU     0C0370006H
ERROR_VID_MESSAGE_QUEUE_NAME_TOO_LONG           EQU     0C0370007H
ERROR_VID_PARTITION_ALREADY_EXISTS              EQU     0C0370008H
ERROR_VID_PARTITION_DOES_NOT_EXIST              EQU     0C0370009H
ERROR_VID_PARTITION_NAME_NOT_FOUND              EQU     0C037000AH
ERROR_VID_MESSAGE_QUEUE_ALREADY_EXISTS          EQU     0C037000BH
ERROR_VID_EXCEEDED_MBP_ENTRY_MAP_LIMIT          EQU     0C037000CH
ERROR_VID_MB_STILL_REFERENCED                   EQU     0C037000DH
ERROR_VID_CHILD_GPA_PAGE_SET_CORRUPTED          EQU     0C037000EH
ERROR_VID_INVALID_NUMA_SETTINGS                 EQU     0C037000FH
ERROR_VID_INVALID_NUMA_NODE_INDEX               EQU     0C0370010H
ERROR_VID_NOTIFICATION_QUEUE_ALREADY_ASSOCIATED EQU     0C0370011H
ERROR_VID_INVALID_MEMORY_BLOCK_HANDLE           EQU     0C0370012H
ERROR_VID_PAGE_RANGE_OVERFLOW                   EQU     0C0370013H
ERROR_VID_INVALID_MESSAGE_QUEUE_HANDLE          EQU     0C0370014H
ERROR_VID_INVALID_GPA_RANGE_HANDLE              EQU     0C0370015H
ERROR_VID_NO_MEMORY_BLOCK_NOTIFICATION_QUEUE    EQU     0C0370016H
ERROR_VID_MEMORY_BLOCK_LOCK_COUNT_EXCEEDED      EQU     0C0370017H
ERROR_VID_INVALID_PPM_HANDLE                    EQU     0C0370018H
ERROR_VID_MBPS_ARE_LOCKED                       EQU     0C0370019H
ERROR_VID_MESSAGE_QUEUE_CLOSED                  EQU     0C037001AH
ERROR_VID_VIRTUAL_PROCESSOR_LIMIT_EXCEEDED      EQU     0C037001BH
ERROR_VID_STOP_PENDING                          EQU     0C037001CH
ERROR_VID_INVALID_PROCESSOR_STATE               EQU     0C037001DH
ERROR_VID_EXCEEDED_KM_CONTEXT_COUNT_LIMIT       EQU     0C037001EH
ERROR_VID_KM_INTERFACE_ALREADY_INITIALIZED      EQU     0C037001FH
ERROR_VID_MB_PROPERTY_ALREADY_SET_RESET         EQU     0C0370020H
ERROR_VID_MMIO_RANGE_DESTROYED                  EQU     0C0370021H
ERROR_VID_INVALID_CHILD_GPA_PAGE_SET            EQU     0C0370022H
ERROR_VID_RESERVE_PAGE_SET_IS_BEING_USED        EQU     0C0370023H
ERROR_VID_RESERVE_PAGE_SET_TOO_SMALL            EQU     0C0370024H
ERROR_VID_MBP_ALREADY_LOCKED_USING_RESERVED_PAGE EQU    0C0370025H
ERROR_VID_MBP_COUNT_EXCEEDED_LIMIT              EQU     0C0370026H
ERROR_VID_SAVED_STATE_CORRUPT                   EQU     0C0370027H
ERROR_VID_SAVED_STATE_UNRECOGNIZED_ITEM         EQU     0C0370028H
ERROR_VID_SAVED_STATE_INCOMPATIBLE              EQU     0C0370029H
ERROR_VID_REMOTE_NODE_PARENT_GPA_PAGES_USED     EQU     080370001H

ERROR_VOLMGR_INCOMPLETE_REGENERATION            EQU     080380001H
ERROR_VOLMGR_INCOMPLETE_DISK_MIGRATION          EQU     080380002H
ERROR_VOLMGR_DATABASE_FULL                      EQU     0C0380001H
ERROR_VOLMGR_DISK_CONFIGURATION_CORRUPTED       EQU     0C0380002H
ERROR_VOLMGR_DISK_CONFIGURATION_NOT_IN_SYNC     EQU     0C0380003H
ERROR_VOLMGR_PACK_CONFIG_UPDATE_FAILED          EQU     0C0380004H
ERROR_VOLMGR_DISK_CONTAINS_NON_SIMPLE_VOLUME    EQU     0C0380005H
ERROR_VOLMGR_DISK_DUPLICATE                     EQU     0C0380006H
ERROR_VOLMGR_DISK_DYNAMIC                       EQU     0C0380007H
ERROR_VOLMGR_DISK_ID_INVALID                    EQU     0C0380008H
ERROR_VOLMGR_DISK_INVALID                       EQU     0C0380009H
ERROR_VOLMGR_DISK_LAST_VOTER                    EQU     0C038000AH
ERROR_VOLMGR_DISK_LAYOUT_INVALID                EQU     0C038000BH
ERROR_VOLMGR_DISK_LAYOUT_NON_BASIC_BETWEEN_BASIC_PARTITIONS EQU 0C038000CH
ERROR_VOLMGR_DISK_LAYOUT_NOT_CYLINDER_ALIGNED   EQU     0C038000DH
ERROR_VOLMGR_DISK_LAYOUT_PARTITIONS_TOO_SMALL   EQU     0C038000EH
ERROR_VOLMGR_DISK_LAYOUT_PRIMARY_BETWEEN_LOGICAL_PARTITIONS EQU 0C038000FH
ERROR_VOLMGR_DISK_LAYOUT_TOO_MANY_PARTITIONS    EQU     0C0380010H
ERROR_VOLMGR_DISK_MISSING                       EQU     0C0380011H
ERROR_VOLMGR_DISK_NOT_EMPTY                     EQU     0C0380012H
ERROR_VOLMGR_DISK_NOT_ENOUGH_SPACE              EQU     0C0380013H
ERROR_VOLMGR_DISK_REVECTORING_FAILED            EQU     0C0380014H
ERROR_VOLMGR_DISK_SECTOR_SIZE_INVALID           EQU     0C0380015H
ERROR_VOLMGR_DISK_SET_NOT_CONTAINED             EQU     0C0380016H
ERROR_VOLMGR_DISK_USED_BY_MULTIPLE_MEMBERS      EQU     0C0380017H
ERROR_VOLMGR_DISK_USED_BY_MULTIPLE_PLEXES       EQU     0C0380018H
ERROR_VOLMGR_DYNAMIC_DISK_NOT_SUPPORTED         EQU     0C0380019H
ERROR_VOLMGR_EXTENT_ALREADY_USED                EQU     0C038001AH
ERROR_VOLMGR_EXTENT_NOT_CONTIGUOUS              EQU     0C038001BH
ERROR_VOLMGR_EXTENT_NOT_IN_PUBLIC_REGION        EQU     0C038001CH
ERROR_VOLMGR_EXTENT_NOT_SECTOR_ALIGNED          EQU     0C038001DH
ERROR_VOLMGR_EXTENT_OVERLAPS_EBR_PARTITION      EQU     0C038001EH
ERROR_VOLMGR_EXTENT_VOLUME_LENGTHS_DO_NOT_MATCH EQU     0C038001FH
ERROR_VOLMGR_FAULT_TOLERANT_NOT_SUPPORTED       EQU     0C0380020H
ERROR_VOLMGR_INTERLEAVE_LENGTH_INVALID          EQU     0C0380021H
ERROR_VOLMGR_MAXIMUM_REGISTERED_USERS           EQU     0C0380022H
ERROR_VOLMGR_MEMBER_IN_SYNC                     EQU     0C0380023H
ERROR_VOLMGR_MEMBER_INDEX_DUPLICATE             EQU     0C0380024H
ERROR_VOLMGR_MEMBER_INDEX_INVALID               EQU     0C0380025H
ERROR_VOLMGR_MEMBER_MISSING                     EQU     0C0380026H
ERROR_VOLMGR_MEMBER_NOT_DETACHED                EQU     0C0380027H
ERROR_VOLMGR_MEMBER_REGENERATING                EQU     0C0380028H
ERROR_VOLMGR_ALL_DISKS_FAILED                   EQU     0C0380029H
ERROR_VOLMGR_NO_REGISTERED_USERS                EQU     0C038002AH
ERROR_VOLMGR_NO_SUCH_USER                       EQU     0C038002BH
ERROR_VOLMGR_NOTIFICATION_RESET                 EQU     0C038002CH
ERROR_VOLMGR_NUMBER_OF_MEMBERS_INVALID          EQU     0C038002DH
ERROR_VOLMGR_NUMBER_OF_PLEXES_INVALID           EQU     0C038002EH
ERROR_VOLMGR_PACK_DUPLICATE                     EQU     0C038002FH
ERROR_VOLMGR_PACK_ID_INVALID                    EQU     0C0380030H
ERROR_VOLMGR_PACK_INVALID                       EQU     0C0380031H
ERROR_VOLMGR_PACK_NAME_INVALID                  EQU     0C0380032H
ERROR_VOLMGR_PACK_OFFLINE                       EQU     0C0380033H
ERROR_VOLMGR_PACK_HAS_QUORUM                    EQU     0C0380034H
ERROR_VOLMGR_PACK_WITHOUT_QUORUM                EQU     0C0380035H
ERROR_VOLMGR_PARTITION_STYLE_INVALID            EQU     0C0380036H
ERROR_VOLMGR_PARTITION_UPDATE_FAILED            EQU     0C0380037H
ERROR_VOLMGR_PLEX_IN_SYNC                       EQU     0C0380038H
ERROR_VOLMGR_PLEX_INDEX_DUPLICATE               EQU     0C0380039H
ERROR_VOLMGR_PLEX_INDEX_INVALID                 EQU     0C038003AH
ERROR_VOLMGR_PLEX_LAST_ACTIVE                   EQU     0C038003BH
ERROR_VOLMGR_PLEX_MISSING                       EQU     0C038003CH
ERROR_VOLMGR_PLEX_REGENERATING                  EQU     0C038003DH
ERROR_VOLMGR_PLEX_TYPE_INVALID                  EQU     0C038003EH
ERROR_VOLMGR_PLEX_NOT_RAID5                     EQU     0C038003FH
ERROR_VOLMGR_PLEX_NOT_SIMPLE                    EQU     0C0380040H
ERROR_VOLMGR_STRUCTURE_SIZE_INVALID             EQU     0C0380041H
ERROR_VOLMGR_TOO_MANY_NOTIFICATION_REQUESTS     EQU     0C0380042H
ERROR_VOLMGR_TRANSACTION_IN_PROGRESS            EQU     0C0380043H
ERROR_VOLMGR_UNEXPECTED_DISK_LAYOUT_CHANGE      EQU     0C0380044H
ERROR_VOLMGR_VOLUME_CONTAINS_MISSING_DISK       EQU     0C0380045H
ERROR_VOLMGR_VOLUME_ID_INVALID                  EQU     0C0380046H
ERROR_VOLMGR_VOLUME_LENGTH_INVALID              EQU     0C0380047H
ERROR_VOLMGR_VOLUME_LENGTH_NOT_SECTOR_SIZE_MULTIPLE EQU 0C0380048H
ERROR_VOLMGR_VOLUME_NOT_MIRRORED                EQU     0C0380049H
ERROR_VOLMGR_VOLUME_NOT_RETAINED                EQU     0C038004AH
ERROR_VOLMGR_VOLUME_OFFLINE                     EQU     0C038004BH
ERROR_VOLMGR_VOLUME_RETAINED                    EQU     0C038004CH
ERROR_VOLMGR_NUMBER_OF_EXTENTS_INVALID          EQU     0C038004DH
ERROR_VOLMGR_DIFFERENT_SECTOR_SIZE              EQU     0C038004EH
ERROR_VOLMGR_BAD_BOOT_DISK                      EQU     0C038004FH
ERROR_VOLMGR_PACK_CONFIG_OFFLINE                EQU     0C0380050H
ERROR_VOLMGR_PACK_CONFIG_ONLINE                 EQU     0C0380051H
ERROR_VOLMGR_NOT_PRIMARY_PACK                   EQU     0C0380052H
ERROR_VOLMGR_PACK_LOG_UPDATE_FAILED             EQU     0C0380053H
ERROR_VOLMGR_NUMBER_OF_DISKS_IN_PLEX_INVALID    EQU     0C0380054H
ERROR_VOLMGR_NUMBER_OF_DISKS_IN_MEMBER_INVALID  EQU     0C0380055H
ERROR_VOLMGR_VOLUME_MIRRORED                    EQU     0C0380056H
ERROR_VOLMGR_PLEX_NOT_SIMPLE_SPANNED            EQU     0C0380057H
ERROR_VOLMGR_NO_VALID_LOG_COPIES                EQU     0C0380058H
ERROR_VOLMGR_PRIMARY_PACK_PRESENT               EQU     0C0380059H
ERROR_VOLMGR_NUMBER_OF_DISKS_INVALID            EQU     0C038005AH
ERROR_VOLMGR_MIRROR_NOT_SUPPORTED               EQU     0C038005BH
ERROR_VOLMGR_RAID5_NOT_SUPPORTED                EQU     0C038005CH

ERROR_BCD_NOT_ALL_ENTRIES_IMPORTED              EQU     080390001H
ERROR_BCD_TOO_MANY_ELEMENTS                     EQU     0C0390002H
ERROR_BCD_NOT_ALL_ENTRIES_SYNCHRONIZED          EQU     080390003H

ERROR_VHD_DRIVE_FOOTER_MISSING                  EQU     0C03A0001H
ERROR_VHD_DRIVE_FOOTER_CHECKSUM_MISMATCH        EQU     0C03A0002H
ERROR_VHD_DRIVE_FOOTER_CORRUPT                  EQU     0C03A0003H
ERROR_VHD_FORMAT_UNKNOWN                        EQU     0C03A0004H
ERROR_VHD_FORMAT_UNSUPPORTED_VERSION            EQU     0C03A0005H
ERROR_VHD_SPARSE_HEADER_CHECKSUM_MISMATCH       EQU     0C03A0006H
ERROR_VHD_SPARSE_HEADER_UNSUPPORTED_VERSION     EQU     0C03A0007H
ERROR_VHD_SPARSE_HEADER_CORRUPT                 EQU     0C03A0008H
ERROR_VHD_BLOCK_ALLOCATION_FAILURE              EQU     0C03A0009H
ERROR_VHD_BLOCK_ALLOCATION_TABLE_CORRUPT        EQU     0C03A000AH
ERROR_VHD_INVALID_BLOCK_SIZE                    EQU     0C03A000BH
ERROR_VHD_BITMAP_MISMATCH                       EQU     0C03A000CH
ERROR_VHD_PARENT_VHD_NOT_FOUND                  EQU     0C03A000DH
ERROR_VHD_CHILD_PARENT_ID_MISMATCH              EQU     0C03A000EH
ERROR_VHD_CHILD_PARENT_TIMESTAMP_MISMATCH       EQU     0C03A000FH
ERROR_VHD_METADATA_READ_FAILURE                 EQU     0C03A0010H
ERROR_VHD_METADATA_WRITE_FAILURE                EQU     0C03A0011H
ERROR_VHD_INVALID_SIZE                          EQU     0C03A0012H
ERROR_VHD_INVALID_FILE_SIZE                     EQU     0C03A0013H

ERROR_VIRTDISK_PROVIDER_NOT_FOUND               EQU     0C03A0014H
ERROR_VIRTDISK_NOT_VIRTUAL_DISK                 EQU     0C03A0015H
ERROR_VHD_PARENT_VHD_ACCESS_DENIED              EQU     0C03A0016H
ERROR_VHD_CHILD_PARENT_SIZE_MISMATCH            EQU     0C03A0017H
ERROR_VHD_DIFFERENCING_CHAIN_CYCLE_DETECTED     EQU     0C03A0018H
ERROR_VHD_DIFFERENCING_CHAIN_ERROR_IN_PARENT    EQU     0C03A0019H
ERROR_VIRTUAL_DISK_LIMITATION                   EQU     0C03A001AH
ERROR_VHD_INVALID_TYPE                          EQU     0C03A001BH
ERROR_VHD_INVALID_STATE                         EQU     0C03A001CH
ERROR_VIRTDISK_UNSUPPORTED_DISK_SECTOR_SIZE     EQU     0C03A001DH
ERROR_QUERY_STORAGE_ERROR                       EQU     0803A0001H

SDIAG_E_CANCELLED                               EQU     803C0100H
SDIAG_E_SCRIPT                                  EQU     803C0101H
SDIAG_E_POWERSHELL                              EQU     803C0102H
SDIAG_E_MANAGEDHOST                             EQU     803C0103H
SDIAG_E_NOVERIFIER                              EQU     803C0104H
SDIAG_S_CANNOTRUN                               EQU     003C0105H
SDIAG_E_DISABLED                                EQU     803C0106H
SDIAG_E_TRUST                                   EQU     803C0107H
SDIAG_E_CANNOTRUN                               EQU     803C0108H
SDIAG_E_VERSION                                 EQU     803C0109H
SDIAG_E_RESOURCE                                EQU     803C010AH
SDIAG_E_ROOTCAUSE                               EQU     803C010BH

E_MBN_CONTEXT_NOT_ACTIVATED                     EQU     80548201H
E_MBN_BAD_SIM                                   EQU     80548202H
E_MBN_DATA_CLASS_NOT_AVAILABLE                  EQU     80548203H
E_MBN_INVALID_ACCESS_STRING                     EQU     80548204H
E_MBN_MAX_ACTIVATED_CONTEXTS                    EQU     80548205H
E_MBN_PACKET_SVC_DETACHED                       EQU     80548206H
E_MBN_PROVIDER_NOT_VISIBLE                      EQU     80548207H
E_MBN_RADIO_POWER_OFF                           EQU     80548208H
E_MBN_SERVICE_NOT_ACTIVATED                     EQU     80548209H
E_MBN_SIM_NOT_INSERTED                          EQU     8054820AH
E_MBN_VOICE_CALL_IN_PROGRESS                    EQU     8054820BH
E_MBN_INVALID_CACHE                             EQU     8054820CH
E_MBN_NOT_REGISTERED                            EQU     8054820DH
E_MBN_PROVIDERS_NOT_FOUND                       EQU     8054820EH
E_MBN_PIN_NOT_SUPPORTED                         EQU     8054820FH
E_MBN_PIN_REQUIRED                              EQU     80548210H
E_MBN_PIN_DISABLED                              EQU     80548211H
E_MBN_FAILURE                                   EQU     80548212H
E_MBN_INVALID_PROFILE                           EQU     80548218H
E_MBN_DEFAULT_PROFILE_EXIST                     EQU     80548219H
E_MBN_SMS_ENCODING_NOT_SUPPORTED                EQU     80548220H
E_MBN_SMS_FILTER_NOT_SUPPORTED                  EQU     80548221H
E_MBN_SMS_INVALID_MEMORY_INDEX                  EQU     80548222H
E_MBN_SMS_LANG_NOT_SUPPORTED                    EQU     80548223H
E_MBN_SMS_MEMORY_FAILURE                        EQU     80548224H
E_MBN_SMS_NETWORK_TIMEOUT                       EQU     80548225H
E_MBN_SMS_UNKNOWN_SMSC_ADDRESS                  EQU     80548226H
E_MBN_SMS_FORMAT_NOT_SUPPORTED                  EQU     80548227H
E_MBN_SMS_OPERATION_NOT_ALLOWED                 EQU     80548228H
E_MBN_SMS_MEMORY_FULL                           EQU     80548229H

UI_E_CREATE_FAILED                              EQU     802A0001H
UI_E_SHUTDOWN_CALLED                            EQU     802A0002H
UI_E_ILLEGAL_REENTRANCY                         EQU     802A0003H
UI_E_OBJECT_SEALED                              EQU     802A0004H
UI_E_VALUE_NOT_SET                              EQU     802A0005H
UI_E_VALUE_NOT_DETERMINED                       EQU     802A0006H
UI_E_INVALID_OUTPUT                             EQU     802A0007H
UI_E_BOOLEAN_EXPECTED                           EQU     802A0008H
UI_E_DIFFERENT_OWNER                            EQU     802A0009H
UI_E_AMBIGUOUS_MATCH                            EQU     802A000AH
UI_E_FP_OVERFLOW                                EQU     802A000BH
UI_E_WRONG_THREAD                               EQU     802A000CH
UI_E_STORYBOARD_ACTIVE                          EQU     802A0101H
UI_E_STORYBOARD_NOT_PLAYING                     EQU     802A0102H
UI_E_START_KEYFRAME_AFTER_END                   EQU     802A0103H
UI_E_END_KEYFRAME_NOT_DETERMINED                EQU     802A0104H
UI_E_LOOPS_OVERLAP                              EQU     802A0105H
UI_E_TRANSITION_ALREADY_USED                    EQU     802A0106H
UI_E_TRANSITION_NOT_IN_STORYBOARD               EQU     802A0107H
UI_E_TRANSITION_ECLIPSED                        EQU     802A0108H
UI_E_TIME_BEFORE_LAST_UPDATE                    EQU     802A0109H
UI_E_TIMER_CLIENT_ALREADY_CONNECTED             EQU     802A010AH

IF (NTDDI_VERSION GE NTDDI_WINNT4)
    CRITICAL_SECTION_NO_DEBUG_INFO              EQU     001000000H
    STARTF_USEHOTKEY                            EQU     00000200H
    STARTF_TITLEISLINKNAME                      EQU     00000800H
    STARTF_TITLEISAPPID                         EQU     000001000H
    STARTF_PREVENTPINNING                       EQU     000002000H
ENDIF

IF (NTDDI_VERSION GE NTDDI_WIN2K)
    MOVEFILE_CREATE_HARDLINK                    EQU     000000010H
    MOVEFILE_FAIL_IF_NOT_TRACKABLE              EQU     000000020H

    ACTCTX_FLAG_PROCESSOR_ARCHITECTURE_VALID    EQU     000000001H
    ACTCTX_FLAG_LANGID_VALID                    EQU     000000002H
    ACTCTX_FLAG_ASSEMBLY_DIRECTORY_VALID        EQU     000000004H
    ACTCTX_FLAG_RESOURCE_NAME_VALID             EQU     000000008H
    ACTCTX_FLAG_SET_PROCESS_DEFAULT             EQU     000000010H
    ACTCTX_FLAG_APPLICATION_NAME_VALID          EQU     000000020H
    ACTCTX_FLAG_SOURCE_IS_ASSEMBLYREF           EQU     000000040H
    ACTCTX_FLAG_HMODULE_VALID                   EQU     000000080H

    DEACTIVATE_ACTCTX_FLAG_FORCE_EARLY_DEACTIVATION EQU 000000001H

    FIND_ACTCTX_SECTION_KEY_RETURN_HACTCTX      EQU     000000001H
    FIND_ACTCTX_SECTION_KEY_RETURN_FLAGS        EQU     000000002H
    FIND_ACTCTX_SECTION_KEY_RETURN_ASSEMBLY_METADATA EQU 000000004H

    QUERY_ACTCTX_FLAG_USE_ACTIVE_ACTCTX         EQU     000000004H
    QUERY_ACTCTX_FLAG_ACTCTX_IS_HMODULE         EQU     000000008H
    QUERY_ACTCTX_FLAG_ACTCTX_IS_ADDRESS         EQU     000000010H
    QUERY_ACTCTX_FLAG_NO_ADDREF                 EQU     080000000H
ENDIF

IF (NTDDI_VERSION GE NTDDI_WINXP)
    FileBasicInfo                               EQU     0
    FileStandardInfo                            EQU     1
    FileNameInfo                                EQU     2
    FileRenameInfo                              EQU     3
    FileDispositionInfo                         EQU     4
    FileAllocationInfo                          EQU     5
    FileEndOfFileInfo                           EQU     6
    FileStreamInfo                              EQU     7
    FileCompressionInfo                         EQU     8
    FileAttributeTagInfo                        EQU     9
    FileIdBothDirectoryInfo                     EQU     10
    FileIdBothDirectoryRestartInfo              EQU     11
    MaximumFileInfoByHandleClass                EQU     11

    IF (NTDDI_VERSION EQ NTDDI_WINXP)
        FileIdType                              EQU     0
        MaximumFileIdType                       EQU     1
    ELSE
        FileIdType                              EQU     00H
        ObjectIdType                            EQU     01H
        ExtendedFileIdType                      EQU     02H
        MaximumFileIdType                       EQU     03H
    ENDIF

    FIBER_FLAG_FLOAT_SWITCH                     EQU     01H

    GET_SYSTEM_WOW64_DIRECTORY_NAME_A_A         EQU     <GetSystemWow64DirectoryA>
    GET_SYSTEM_WOW64_DIRECTORY_NAME_A_W         EQU     L("GetSystemWow64DirectoryA")
    GET_SYSTEM_WOW64_DIRECTORY_NAME_A_T         EQU     <GetSystemWow64DirectoryA>
    GET_SYSTEM_WOW64_DIRECTORY_NAME_W_A         EQU     <GetSystemWow64DirectoryW>
    GET_SYSTEM_WOW64_DIRECTORY_NAME_W_W         EQU     L("GetSystemWow64DirectoryW")
    GET_SYSTEM_WOW64_DIRECTORY_NAME_W_T         EQU     L("GetSystemWow64DirectoryW")

    FindStreamInfoStandard                       EQU     00H
    FindStreamInfoMaxInfoLevel                   EQU     01H

    IFDEF APP_UNICODE
        GET_SYSTEM_WOW64_DIRECTORY_NAME_T_A EQU GET_SYSTEM_WOW64_DIRECTORY_NAME_A_W
        GET_SYSTEM_WOW64_DIRECTORY_NAME_T_W EQU GET_SYSTEM_WOW64_DIRECTORY_NAME_W_W
        GET_SYSTEM_WOW64_DIRECTORY_NAME_T_T EQU GET_SYSTEM_WOW64_DIRECTORY_NAME_W_T
    ELSE
        GET_SYSTEM_WOW64_DIRECTORY_NAME_T_A EQU GET_SYSTEM_WOW64_DIRECTORY_NAME_A_A
        GET_SYSTEM_WOW64_DIRECTORY_NAME_T_W EQU GET_SYSTEM_WOW64_DIRECTORY_NAME_W_A
        GET_SYSTEM_WOW64_DIRECTORY_NAME_T_T EQU GET_SYSTEM_WOW64_DIRECTORY_NAME_A_T
    ENDIF
ENDIF

IF (NTDDI_VERSION GE NTDDI_VISTA)
    PROCESS_DEP_ENABLE                          EQU     000000001H
    PROCESS_DEP_DISABLE_ATL_THUNK_EMULATION     EQU     000000002H

    REMOTE_PROTOCOL_INFO_FLAG_LOOPBACK          EQU     000000001H
    REMOTE_PROTOCOL_INFO_FLAG_OFFLINE           EQU     000000002H

    FILE_SKIP_COMPLETION_PORT_ON_SUCCESS        EQU     01H
    FILE_SKIP_SET_EVENT_ON_HANDLE               EQU     02H

    PROC_THREAD_ATTRIBUTE_NUMBER                EQU     00000FFFFH
    PROC_THREAD_ATTRIBUTE_THREAD                EQU     000010000H
    PROC_THREAD_ATTRIBUTE_INPUT                 EQU     000020000H
    PROC_THREAD_ATTRIBUTE_ADDITIVE              EQU     000040000H
    PROTECTION_LEVEL_SAME                       EQU     0FFFFFFFFH

    IFNDEF _USE_FULL_PROC_THREAD_ATTRIBUTE
        _USE_FULL_PROC_THREAD_ATTRIBUTE         EQU     1
        ProcThreadAttributeParentProcess        EQU     0
        ProcThreadAttributeHandleList           EQU     2
        ProcThreadAttributeProtectionLevel      EQU     11
    ENDIF

    IoPriorityHintVeryLow                       EQU     0
    IoPriorityHintLow                           EQU     01H
    IoPriorityHintNormal                        EQU     02H
    MaximumIoPriorityHintType                   EQU     03H

    SYMBOLIC_LINK_FLAG_DIRECTORY                EQU     01H
    VALID_SYMBOLIC_LINK_FLAGS                   EQU     SYMBOLIC_LINK_FLAG_DIRECTORY
ENDIF

IF (NTDDI_VERSION GE NTDDI_WIN7)
    UMS_VERSION                                 EQU     RTL_UMS_VERSION
    UMS_THREAD_INFO_CLASS                       TYPEDEF DWORD
    UMS_SCHEDULER_REASON                        TYPEDEF DWORD

    ProcThreadAttributeGroupAffinity            EQU     3
    ProcThreadAttributePreferredNode            EQU     4
    ProcThreadAttributeIdealProcessor           EQU     5
    ProcThreadAttributeUmsThread                EQU     6
    ProcThreadAttributeMitigationPolicy         EQU     7

    PROCESS_CREATION_MITIGATION_POLICY_DEP_ENABLE EQU   001H
    PROCESS_CREATION_MITIGATION_POLICY_DEP_ATL_THUNK_ENABLE EQU 002H
    PROCESS_CREATION_MITIGATION_POLICY_SEHOP_ENABLE EQU 004H

    COPYFILE2_CALLBACK_NONE                     EQU     00H
    COPYFILE2_CALLBACK_CHUNK_STARTED            EQU     01H
    COPYFILE2_CALLBACK_CHUNK_FINISHED           EQU     02H
    COPYFILE2_CALLBACK_STREAM_STARTED           EQU     03H
    COPYFILE2_CALLBACK_STREAM_FINISHED          EQU     04H
    COPYFILE2_CALLBACK_POLL_CONTINUE            EQU     05H
    COPYFILE2_CALLBACK_ERROR                    EQU     06H
    COPYFILE2_CALLBACK_MAX                      EQU     07H

    COPYFILE2_PROGRESS_CONTINUE                 EQU     00H
    COPYFILE2_PROGRESS_CANCEL                   EQU     01H
    COPYFILE2_PROGRESS_STOP                     EQU     02H
    COPYFILE2_PROGRESS_QUIET                    EQU     03H
    COPYFILE2_PROGRESS_PAUSE                    EQU     04H

    COPYFILE2_PHASE_NONE                        EQU     00H
    COPYFILE2_PHASE_PREPARE_SOURCE              EQU     01H
    COPYFILE2_PHASE_PREPARE_DEST                EQU     02H
    COPYFILE2_PHASE_READ_SOURCE                 EQU     03H
    COPYFILE2_PHASE_WRITE_DESTINATION           EQU     04H
    COPYFILE2_PHASE_SERVER_COPY                 EQU     05H
    COPYFILE2_PHASE_NAMEGRAFT_COPY              EQU     06H
    COPYFILE2_PHASE_MAX EQU                     EQU     07H

    COPYFILE2_MESSAGE_COPY_OFFLOAD              EQU     000000001H
ENDIF

IF (NTDDI_VERSION GE NTDDI_WIN8)
    STORAGE_INFO_FLAGS_ALIGNED_DEVICE           EQU     000000001H
    STORAGE_INFO_OFFSET_UNKNOWN                 EQU     0FFFFFFFFH

    REMOTE_PROTOCOL_INFO_FLAG_PERSISTENT_HANDLE EQU     000000004H

    RPI_FLAG_SMB2_SHARECAP_TIMEWARP             EQU     000000002H
    RPI_FLAG_SMB2_SHARECAP_DFS                  EQU     000000008H
    RPI_FLAG_SMB2_SHARECAP_CONTINUOUS_AVAILABILITY EQU  000000010H
    RPI_FLAG_SMB2_SHARECAP_SCALEOUT             EQU     000000020H
    RPI_FLAG_SMB2_SHARECAP_CLUSTER              EQU     000000040H

    RPI_SMB2_FLAG_SERVERCAP_DFS                 EQU     000000001H
    RPI_SMB2_FLAG_SERVERCAP_LEASING             EQU     000000002H
    RPI_SMB2_FLAG_SERVERCAP_LARGEMTU            EQU     000000004H
    RPI_SMB2_FLAG_SERVERCAP_MULTICHANNEL        EQU     000000008H
    RPI_SMB2_FLAG_SERVERCAP_PERSISTENT_HANDLES  EQU     000000010H
    RPI_SMB2_FLAG_SERVERCAP_DIRECTORY_LEASING   EQU     000000020H

    RESTORE_LAST_ERROR_NAME_A                   EQU     <RestoreLastError>
    RESTORE_LAST_ERROR_NAME_W                   EQU     L("RestoreLastError")
    IFDEF APP_UNICODE
        RESTORE_LAST_ERROR_NAME                 EQU     RESTORE_LAST_ERROR_NAME_W
    ELSE
        RESTORE_LAST_ERROR_NAME                 EQU     RESTORE_LAST_ERROR_NAME_A
    ENDIF

    ProcThreadAttributeSecurityCapabilities     EQU     9

    PROCESS_CREATION_MITIGATION_POLICY_FORCE_RELOCATE_IMAGES_MASK                   EQU (000000003H SHL 8)
    PROCESS_CREATION_MITIGATION_POLICY_FORCE_RELOCATE_IMAGES_DEFER                  EQU (000000000H SHL 8)
    PROCESS_CREATION_MITIGATION_POLICY_FORCE_RELOCATE_IMAGES_ALWAYS_ON              EQU (000000001H SHL 8)
    PROCESS_CREATION_MITIGATION_POLICY_FORCE_RELOCATE_IMAGES_ALWAYS_OFF             EQU (000000002H SHL 8)
    PROCESS_CREATION_MITIGATION_POLICY_FORCE_RELOCATE_IMAGES_ALWAYS_ON_REQ_RELOCS   EQU (000000003H SHL 8)
    PROCESS_CREATION_MITIGATION_POLICY_HEAP_TERMINATE_MASK                          EQU (000000003H SHL 12)
    PROCESS_CREATION_MITIGATION_POLICY_HEAP_TERMINATE_DEFER                         EQU (000000000H SHL 12)
    PROCESS_CREATION_MITIGATION_POLICY_HEAP_TERMINATE_ALWAYS_ON                     EQU (000000001H SHL 12)
    PROCESS_CREATION_MITIGATION_POLICY_HEAP_TERMINATE_ALWAYS_OFF                    EQU (000000002H SHL 12)
    PROCESS_CREATION_MITIGATION_POLICY_HEAP_TERMINATE_RESERVED                      EQU (000000003H SHL 12)
    PROCESS_CREATION_MITIGATION_POLICY_BOTTOM_UP_ASLR_MASK                          EQU (000000003H SHL 16)
    PROCESS_CREATION_MITIGATION_POLICY_BOTTOM_UP_ASLR_DEFER                         EQU (000000000H SHL 16)
    PROCESS_CREATION_MITIGATION_POLICY_BOTTOM_UP_ASLR_ALWAYS_ON                     EQU (000000001H SHL 16)
    PROCESS_CREATION_MITIGATION_POLICY_BOTTOM_UP_ASLR_ALWAYS_OFF                    EQU (000000002H SHL 16)
    PROCESS_CREATION_MITIGATION_POLICY_BOTTOM_UP_ASLR_RESERVED                      EQU (000000003H SHL 16)
    PROCESS_CREATION_MITIGATION_POLICY_HIGH_ENTROPY_ASLR_MASK                       EQU (000000003H SHL 20)
    PROCESS_CREATION_MITIGATION_POLICY_HIGH_ENTROPY_ASLR_DEFER                      EQU (000000000H SHL 20)
    PROCESS_CREATION_MITIGATION_POLICY_HIGH_ENTROPY_ASLR_ALWAYS_ON                  EQU (000000001H SHL 20)
    PROCESS_CREATION_MITIGATION_POLICY_HIGH_ENTROPY_ASLR_ALWAYS_OFF                 EQU (000000002H SHL 20)
    PROCESS_CREATION_MITIGATION_POLICY_HIGH_ENTROPY_ASLR_RESERVED                   EQU (000000003H SHL 20)
    PROCESS_CREATION_MITIGATION_POLICY_STRICT_HANDLE_CHECKS_MASK                    EQU (000000003H SHL 24)
    PROCESS_CREATION_MITIGATION_POLICY_STRICT_HANDLE_CHECKS_DEFER                   EQU (000000000H SHL 24)
    PROCESS_CREATION_MITIGATION_POLICY_STRICT_HANDLE_CHECKS_ALWAYS_ON               EQU (000000001H SHL 24)
    PROCESS_CREATION_MITIGATION_POLICY_STRICT_HANDLE_CHECKS_ALWAYS_OFF              EQU (000000002H SHL 24)
    PROCESS_CREATION_MITIGATION_POLICY_STRICT_HANDLE_CHECKS_RESERVED                EQU (000000003H SHL 24)
    PROCESS_CREATION_MITIGATION_POLICY_WIN32K_SYSTEM_CALL_DISABLE_MASK              EQU (000000003H SHL 28)
    PROCESS_CREATION_MITIGATION_POLICY_WIN32K_SYSTEM_CALL_DISABLE_DEFER             EQU (000000000H SHL 28)
    PROCESS_CREATION_MITIGATION_POLICY_WIN32K_SYSTEM_CALL_DISABLE_ALWAYS_ON         EQU (000000001H SHL 28)
    PROCESS_CREATION_MITIGATION_POLICY_WIN32K_SYSTEM_CALL_DISABLE_ALWAYS_OFF        EQU (000000002H SHL 28)
    PROCESS_CREATION_MITIGATION_POLICY_WIN32K_SYSTEM_CALL_DISABLE_RESERVED          EQU (000000003H SHL 28)
    PROCESS_CREATION_MITIGATION_POLICY_EXTENSION_POINT_DISABLE_MASK                 EQU (000000003H SHL 32)
    PROCESS_CREATION_MITIGATION_POLICY_EXTENSION_POINT_DISABLE_DEFER                EQU (000000000H SHL 32)
    PROCESS_CREATION_MITIGATION_POLICY_EXTENSION_POINT_DISABLE_ALWAYS_ON            EQU (000000001H SHL 32)
    PROCESS_CREATION_MITIGATION_POLICY_EXTENSION_POINT_DISABLE_ALWAYS_OFF           EQU (000000002H SHL 32)
    PROCESS_CREATION_MITIGATION_POLICY_EXTENSION_POINT_DISABLE_RESERVED             EQU (000000003H SHL 32)
    PROCESS_CREATION_MITIGATION_POLICY_PROHIBIT_DYNAMIC_CODE_MASK                   EQU (000000003H SHL 36)
    PROCESS_CREATION_MITIGATION_POLICY_PROHIBIT_DYNAMIC_CODE_DEFER                  EQU (000000000H SHL 36)
    PROCESS_CREATION_MITIGATION_POLICY_PROHIBIT_DYNAMIC_CODE_ALWAYS_ON              EQU (000000001H SHL 36)
    PROCESS_CREATION_MITIGATION_POLICY_PROHIBIT_DYNAMIC_CODE_ALWAYS_OFF             EQU (000000002H SHL 36)
    PROCESS_CREATION_MITIGATION_POLICY_PROHIBIT_DYNAMIC_CODE_RESERVED               EQU (000000003H SHL 36)
    PROCESS_CREATION_MITIGATION_POLICY_BLOCK_NON_MICROSOFT_BINARIES_MASK            EQU (000000003H SHL 44)
    PROCESS_CREATION_MITIGATION_POLICY_BLOCK_NON_MICROSOFT_BINARIES_DEFER           EQU (000000000H SHL 44)
    PROCESS_CREATION_MITIGATION_POLICY_BLOCK_NON_MICROSOFT_BINARIES_ALWAYS_ON       EQU (000000001H SHL 44)
    PROCESS_CREATION_MITIGATION_POLICY_BLOCK_NON_MICROSOFT_BINARIES_ALWAYS_OFF      EQU (000000002H SHL 44)
    PROCESS_CREATION_MITIGATION_POLICY_BLOCK_NON_MICROSOFT_BINARIES_RESERVED        EQU (000000003H SHL 44)

    OPERATION_API_VERSION                       EQU     1

    OPERATION_START_TRACE_CURRENT_THREAD        EQU     01H

    OPERATION_END_DISCARD                       EQU     01H
ENDIF

INVALID_HANDLE_VALUE                            EQU     (-1)
INVALID_FILE_SIZE                               EQU     0FFFFFFFFH
INVALID_SET_FILE_POINTER                        EQU     (-1)
INVALID_FILE_ATTRIBUTES                         EQU     (-1)

FILE_BEGIN                                      EQU     0
FILE_CURRENT                                    EQU     1
FILE_END                                        EQU     2
TIME_ZONE_ID_INVALID                            EQU     0FFFFFFFFH
WAIT_FAILED                                     EQU     0FFFFFFFFH
WAIT_OBJECT_0                                   EQU     0
WAIT_ABANDONED                                  EQU     00000080H
WAIT_ABANDONED_0                                EQU     00000080H
WAIT_IO_COMPLETION                              EQU     000000C0H
STILL_ACTIVE                                    EQU     00000103H

EXCEPTION_ACCESS_VIOLATION                      EQU     0C0000005H
EXCEPTION_DATATYPE_MISALIGNMENT                 EQU     80000002H
EXCEPTION_BREAKPOINT                            EQU     80000003H
EXCEPTION_SINGLE_STEP                           EQU     80000004H
EXCEPTION_ARRAY_BOUNDS_EXCEEDED                 EQU     0C000008CH
EXCEPTION_FLT_DENORMAL_OPERAND                  EQU     0C000008DH
EXCEPTION_FLT_DIVIDE_BY_ZERO                    EQU     0C000008EH
EXCEPTION_FLT_INEXACT_RESULT                    EQU     0C000008FH
EXCEPTION_FLT_INVALID_OPERATION                 EQU     0C0000090H
EXCEPTION_FLT_OVERFLOW                          EQU     0C0000091H
EXCEPTION_FLT_STACK_CHECK                       EQU     0C0000092H
EXCEPTION_FLT_UNDERFLOW                         EQU     0C0000093H
EXCEPTION_INT_DIVIDE_BY_ZERO                    EQU     0C0000094H
EXCEPTION_INT_OVERFLOW                          EQU     0C0000095H
EXCEPTION_PRIV_INSTRUCTION                      EQU     0C0000096H
EXCEPTION_IN_PAGE_ERROR                         EQU     0C0000006H
EXCEPTION_ILLEGAL_INSTRUCTION                   EQU     0C000001DH
EXCEPTION_NONCONTINUABLE_EXCEPTION              EQU     0C0000025H
EXCEPTION_STACK_OVERFLOW                        EQU     0C00000FDH
EXCEPTION_INVALID_DISPOSITION                   EQU     0C0000026H
EXCEPTION_GUARD_PAGE                            EQU     080000001H
EXCEPTION_INVALID_HANDLE                        EQU     0C0000008H
CONTROL_C_EXIT                                  EQU     0C000013AH
EXCEPTION_POSSIBLE_DEADLOCK                     EQU     STATUS_POSSIBLE_DEADLOCK

FILE_FLAG_WRITE_THROUGH                         EQU     80000000H
FILE_FLAG_OVERLAPPED                            EQU     40000000H
FILE_FLAG_NO_BUFFERING                          EQU     20000000H
FILE_FLAG_RANDOM_ACCESS                         EQU     10000000H
FILE_FLAG_SEQUENTIAL_SCAN                       EQU     08000000H
FILE_FLAG_DELETE_ON_CLOSE                       EQU     04000000H
FILE_FLAG_BACKUP_SEMANTICS                      EQU     02000000H
FILE_FLAG_POSIX_SEMANTICS                       EQU     01000000H
FILE_FLAG_OPEN_REPARSE_POINT                    EQU     00200000H
FILE_FLAG_OPEN_NO_RECALL                        EQU     00100000H
FILE_FLAG_FIRST_PIPE_INSTANCE                   EQU     00080000H

CREATE_NEW                                      EQU     1
CREATE_ALWAYS                                   EQU     2
OPEN_EXISTING                                   EQU     3
OPEN_ALWAYS                                     EQU     4
TRUNCATE_EXISTING                               EQU     5

PROGRESS_CONTINUE                               EQU     0
PROGRESS_CANCEL                                 EQU     1
PROGRESS_STOP                                   EQU     2
PROGRESS_QUIET                                  EQU     3

CALLBACK_CHUNK_FINISHED                         EQU     00000000H
CALLBACK_STREAM_SWITCH                          EQU     00000001H

COPY_FILE_FAIL_IF_EXISTS                        EQU     00000001H
COPY_FILE_RESTARTABLE                           EQU     00000002H
COPY_FILE_OPEN_SOURCE_FOR_WRITE                 EQU     00000004H

REPLACEFILE_WRITE_THROUGH                       EQU     00000001H
REPLACEFILE_IGNORE_MERGE_ERRORS                 EQU     00000002H

PIPE_ACCESS_INBOUND                             EQU     00000001H
PIPE_ACCESS_OUTBOUND                            EQU     00000002H
PIPE_ACCESS_DUPLEX                              EQU     00000003H

PIPE_CLIENT_END                                 EQU     00000000H
PIPE_SERVER_END                                 EQU     00000001H

PIPE_WAIT                                       EQU     00000000H
PIPE_NOWAIT                                     EQU     00000001H
PIPE_READMODE_BYTE                              EQU     00000000H
PIPE_READMODE_MESSAGE                           EQU     00000002H
PIPE_TYPE_BYTE                                  EQU     00000000H
PIPE_TYPE_MESSAGE                               EQU     00000004H
PIPE_ACCEPT_REMOTE_CLIENTS                      EQU     00000000H
PIPE_REJECT_REMOTE_CLIENTS                      EQU     00000008H

PIPE_UNLIMITED_INSTANCES                        EQU     255

SecurityAnonymous                               EQU     0
SecurityIdentification                          EQU     1
SecurityImpersonation                           EQU     2
SecurityDelegation                              EQU     3

SECURITY_ANONYMOUS                              EQU     (SecurityAnonymous SHL 16)
SECURITY_IDENTIFICATION                         EQU     (SecurityIdentification SHL 16)
SECURITY_IMPERSONATION                          EQU     (SecurityImpersonation SHL 16)
SECURITY_DELEGATION                             EQU     (SecurityDelegation SHL 16)
SECURITY_CONTEXT_TRACKING                       EQU     00040000H
SECURITY_EFFECTIVE_ONLY                         EQU     00080000H
SECURITY_SQOS_PRESENT                           EQU     00100000H
SECURITY_VALID_SQOS_FLAGS                       EQU     001F0000H

DELETE                                          EQU     10000H
READ_CONTROL                                    EQU     20000H
WRITE_DAC                                       EQU     40000H
WRITE_OWNER                                     EQU     80000H

SYNCHRONIZE                                     EQU     100000H
STANDARD_RIGHTS_READ                            EQU     READ_CONTROL
STANDARD_RIGHTS_WRITE                           EQU     READ_CONTROL
STANDARD_RIGHTS_EXECUTE                         EQU     READ_CONTROL
STANDARD_RIGHTS_REQUIRED                        EQU     0F0000H
STANDARD_RIGHTS_ALL                             EQU     1F0000H

MUTANT_QUERY_STATE                              EQU     0001H
MUTANT_ALL_ACCESS                               EQU     (STANDARD_RIGHTS_REQUIRED + SYNCHRONIZE + MUTANT_QUERY_STATE)

MUTEX_MODIFY_STATE                              EQU     MUTANT_QUERY_STATE
MUTEX_ALL_ACCESS                                EQU     MUTANT_ALL_ACCESS

SP_SERIALCOMM                                   EQU     00000001H

PST_UNSPECIFIED                                 EQU     00000000H
PST_RS232                                       EQU     00000001H
PST_PARALLELPORT                                EQU     00000002H
PST_RS422                                       EQU     00000003H
PST_RS423                                       EQU     00000004H
PST_RS449                                       EQU     00000005H
PST_MODEM                                       EQU     00000006H
PST_FAX                                         EQU     00000021H
PST_SCANNER                                     EQU     00000022H
PST_NETWORK_BRIDGE                              EQU     00000100H
PST_LAT                                         EQU     00000101H
PST_TCPIP_TELNET                                EQU     00000102H
PST_X25                                         EQU     00000103H

PCF_DTRDSR                                      EQU     0001H
PCF_RTSCTS                                      EQU     0002H
PCF_RLSD                                        EQU     0004H
PCF_PARITY_CHECK                                EQU     0008H
PCF_XONXOFF                                     EQU     0010H
PCF_SETXCHAR                                    EQU     0020H
PCF_TOTALTIMEOUTS                               EQU     0040H
PCF_INTTIMEOUTS                                 EQU     0080H
PCF_SPECIALCHARS                                EQU     0100H
PCF_16BITMODE                                   EQU     0200H

SP_PARITY                                       EQU     0001H
SP_BAUD                                         EQU     0002H
SP_DATABITS                                     EQU     0004H
SP_STOPBITS                                     EQU     0008H
SP_HANDSHAKING                                  EQU     0010H
SP_PARITY_CHECK                                 EQU     0020H
SP_RLSD                                         EQU     0040H

BAUD_075                                        EQU     00000001H
BAUD_110                                        EQU     00000002H
BAUD_134_5                                      EQU     00000004H
BAUD_150                                        EQU     00000008H
BAUD_300                                        EQU     00000010H
BAUD_600                                        EQU     00000020H
BAUD_1200                                       EQU     00000040H
BAUD_1800                                       EQU     00000080H
BAUD_2400                                       EQU     00000100H
BAUD_4800                                       EQU     00000200H
BAUD_7200                                       EQU     00000400H
BAUD_9600                                       EQU     00000800H
BAUD_14400                                      EQU     00001000H
BAUD_19200                                      EQU     00002000H
BAUD_38400                                      EQU     00004000H
BAUD_56K                                        EQU     00008000H
BAUD_128K                                       EQU     00010000H
BAUD_115200                                     EQU     00020000H
BAUD_57600                                      EQU     00040000H
BAUD_USER                                       EQU     10000000H

DATABITS_5                                      EQU     0001H
DATABITS_6                                      EQU     0002H
DATABITS_7                                      EQU     0004H
DATABITS_8                                      EQU     0008H
DATABITS_16                                     EQU     0010H
DATABITS_16X                                    EQU     0020H

STOPBITS_10                                     EQU     0001H
STOPBITS_15                                     EQU     0002H
STOPBITS_20                                     EQU     0004H

PARITY_NONE                                     EQU     0100H
PARITY_ODD                                      EQU     0200H
PARITY_EVEN                                     EQU     0400H
PARITY_MARK                                     EQU     0800H
PARITY_SPACE                                    EQU     1000H

COMMPROP_INITIALIZED                            EQU     0E73CF52EH

DTR_CONTROL_DISABLE                             EQU     00H
DTR_CONTROL_ENABLE                              EQU     01H
DTR_CONTROL_HANDSHAKE                           EQU     02H

RTS_CONTROL_DISABLE                             EQU     00H
RTS_CONTROL_ENABLE                              EQU     01H
RTS_CONTROL_HANDSHAKE                           EQU     02H
RTS_CONTROL_TOGGLE                              EQU     03H

GMEM_FIXED                                      EQU     0000H
GMEM_MOVEABLE                                   EQU     0002H
GMEM_NOCOMPACT                                  EQU     0010H
GMEM_NODISCARD                                  EQU     0020H
GMEM_ZEROINIT                                   EQU     0040H
GMEM_MODIFY                                     EQU     0080H
GMEM_DISCARDABLE                                EQU     0100H
GMEM_NOT_BANKED                                 EQU     1000H
GMEM_SHARE                                      EQU     2000H
GMEM_DDESHARE                                   EQU     2000H
GMEM_NOTIFY                                     EQU     4000H
GMEM_LOWER                                      EQU     GMEM_NOT_BANKED
GMEM_VALID_FLAGS                                EQU     7F72H
GMEM_INVALID_HANDLE                             EQU     8000H
GMEM_DISCARDED                                  EQU     4000H
GMEM_LOCKCOUNT                                  EQU     00FFH

GHND                                            EQU     (GMEM_MOVEABLE OR GMEM_ZEROINIT)
GPTR                                            EQU     (GMEM_FIXED OR GMEM_ZEROINIT)

LMEM_FIXED                                      EQU     0000H
LMEM_MOVEABLE                                   EQU     0002H
LMEM_NOCOMPACT                                  EQU     0010H
LMEM_NODISCARD                                  EQU     0020H
LMEM_ZEROINIT                                   EQU     0040H
LMEM_MODIFY                                     EQU     0080H
LMEM_DISCARDABLE                                EQU     0F00H
LMEM_VALID_FLAGS                                EQU     0F72H
LMEM_INVALID_HANDLE                             EQU     8000H
LMEM_DISCARDED                                  EQU     4000H
LMEM_LOCKCOUNT                                  EQU     00FFH

LHND                                            EQU     (LMEM_MOVEABLE OR LMEM_ZEROINIT)
LPTR                                            EQU     (LMEM_FIXED OR LMEM_ZEROINIT)

NONZEROLHND                                     EQU     LMEM_MOVEABLE
NONZEROLPTR                                     EQU     LMEM_FIXED

DEBUG_PROCESS                                   EQU     00000001H
DEBUG_ONLY_THIS_PROCESS                         EQU     00000002H

CREATE_SUSPENDED                                EQU     00000004H
DETACHED_PROCESS                                EQU     00000008H
CREATE_NEW_CONSOLE                              EQU     00000010H
NORMAL_PRIORITY_CLASS                           EQU     00000020H
IDLE_PRIORITY_CLASS                             EQU     00000040H
HIGH_PRIORITY_CLASS                             EQU     00000080H
REALTIME_PRIORITY_CLASS                         EQU     00000100H
CREATE_NEW_PROCESS_GROUP                        EQU     00000200H
CREATE_UNICODE_ENVIRONMENT                      EQU     00000400H
CREATE_SEPARATE_WOW_VDM                         EQU     00000800H
CREATE_SHARED_WOW_VDM                           EQU     00001000H
CREATE_FORCEDOS                                 EQU     00002000H
BELOW_NORMAL_PRIORITY_CLASS                     EQU     00004000H
ABOVE_NORMAL_PRIORITY_CLASS                     EQU     00008000H
CREATE_BREAKAWAY_FROM_JOB                       EQU     01000000H
CREATE_WITH_USERPROFILE                         EQU     02000000H
CREATE_DEFAULT_ERROR_MODE                       EQU     04000000H
CREATE_NO_WINDOW                                EQU     08000000H
PROFILE_USER                                    EQU     10000000H
PROFILE_KERNEL                                  EQU     20000000H
PROFILE_SERVER                                  EQU     40000000H

THREAD_BASE_PRIORITY_MIN                        EQU     (-2)
THREAD_BASE_PRIORITY_MAX                        EQU     2
THREAD_BASE_PRIORITY_LOWRT                      EQU     15
THREAD_BASE_PRIORITY_IDLE                       EQU     (-15)

THREAD_PRIORITY_LOWEST                          EQU     THREAD_BASE_PRIORITY_MIN
THREAD_PRIORITY_BELOW_NORMAL                    EQU     (THREAD_PRIORITY_LOWEST + 1)
THREAD_PRIORITY_NORMAL                          EQU     0
THREAD_PRIORITY_HIGHEST                         EQU     THREAD_BASE_PRIORITY_MAX
THREAD_PRIORITY_ABOVE_NORMAL                    EQU     (THREAD_PRIORITY_HIGHEST - 1)
THREAD_PRIORITY_ERROR_RETURN                    EQU     MAXLONG
THREAD_PRIORITY_TIME_CRITICAL                   EQU     THREAD_BASE_PRIORITY_LOWRT
THREAD_PRIORITY_IDLE                            EQU     THREAD_BASE_PRIORITY_IDLE

APPLICATION_ERROR_MASK                          EQU     020000000H
ERROR_SEVERITY_SUCCESS                          EQU     000000000H
ERROR_SEVERITY_INFORMATIONAL                    EQU     040000000H
ERROR_SEVERITY_WARNING                          EQU     080000000H
ERROR_SEVERITY_ERROR                            EQU     0C0000000H

EXCEPTION_DEBUG_EVENT                           EQU     1
CREATE_THREAD_DEBUG_EVENT                       EQU     2
CREATE_PROCESS_DEBUG_EVENT                      EQU     3
EXIT_THREAD_DEBUG_EVENT                         EQU     4
EXIT_PROCESS_DEBUG_EVENT                        EQU     5
LOAD_DLL_DEBUG_EVENT                            EQU     6
UNLOAD_DLL_DEBUG_EVENT                          EQU     7
OUTPUT_DEBUG_STRING_EVENT                       EQU     8
RIP_EVENT                                       EQU     9

IFNDEF EXCEPTION_MAXIMUM_PARAMETERS
    EXCEPTION_MAXIMUM_PARAMETERS                EQU     15
ENDIF

DRIVE_UNKNOWN                                   EQU     0
DRIVE_NO_ROOT_DIR                               EQU     1
DRIVE_REMOVABLE                                 EQU     2
DRIVE_FIXED                                     EQU     3
DRIVE_REMOTE                                    EQU     4
DRIVE_CDROM                                     EQU     5
DRIVE_RAMDISK                                   EQU     6

FILE_TYPE_UNKNOWN                               EQU     0000H
FILE_TYPE_DISK                                  EQU     0001H
FILE_TYPE_CHAR                                  EQU     0002H
FILE_TYPE_PIPE                                  EQU     0003H
FILE_TYPE_REMOTE                                EQU     8000H

STD_INPUT_HANDLE                                EQU     (-10)
STD_OUTPUT_HANDLE                               EQU     (-11)
STD_ERROR_HANDLE                                EQU     (-12)

NOPARITY                                        EQU     0
ODDPARITY                                       EQU     1
EVENPARITY                                      EQU     2
MARKPARITY                                      EQU     3
SPACEPARITY                                     EQU     4

ONESTOPBIT                                      EQU     0
ONE5STOPBITS                                    EQU     1
TWOSTOPBITS                                     EQU     2

IGNORE                                          EQU     0
INFINITE                                        EQU     0FFFFFFFFH

CBR_110                                         EQU     110
CBR_300                                         EQU     300
CBR_600                                         EQU     600
CBR_1200                                        EQU     1200
CBR_2400                                        EQU     2400
CBR_4800                                        EQU     4800
CBR_9600                                        EQU     9600
CBR_14400                                       EQU     14400
CBR_19200                                       EQU     19200
CBR_38400                                       EQU     38400
CBR_56000                                       EQU     56000
CBR_57600                                       EQU     57600
CBR_115200                                      EQU     115200
CBR_128000                                      EQU     128000
CBR_256000                                      EQU     256000

CE_RXOVER                                       EQU     0001H
CE_OVERRUN                                      EQU     0002H
CE_RXPARITY                                     EQU     0004H
CE_FRAME                                        EQU     0008H
CE_BREAK                                        EQU     0010H
CE_TXFULL                                       EQU     0100H
CE_PTO                                          EQU     0200H
CE_IOE                                          EQU     0400H
CE_DNS                                          EQU     0800H
CE_OOP                                          EQU     1000H
CE_MODE                                         EQU     8000H

IE_BADID                                        EQU     (-1)
IE_OPEN                                         EQU     (-2)
IE_NOPEN                                        EQU     (-3)
IE_MEMORY                                       EQU     (-4)
IE_DEFAULT                                      EQU     (-5)
IE_HARDWARE                                     EQU     (-10)
IE_BYTESIZE                                     EQU     (-11)
IE_BAUDRATE                                     EQU     (-12)

EV_RXCHAR                                       EQU     0001H
EV_RXFLAG                                       EQU     0002H
EV_TXEMPTY                                      EQU     0004H
EV_CTS                                          EQU     0008H
EV_DSR                                          EQU     0010H
EV_RLSD                                         EQU     0020H
EV_BREAK                                        EQU     0040H
EV_ERR                                          EQU     0080H
EV_RING                                         EQU     0100H
EV_PERR                                         EQU     0200H
EV_RX80FULL                                     EQU     0400H
EV_EVENT1                                       EQU     0800H
EV_EVENT2                                       EQU     1000H

SETXOFF                                         EQU     1
SETXON                                          EQU     2
SETRTS                                          EQU     3
CLRRTS                                          EQU     4
SETDTR                                          EQU     5
CLRDTR                                          EQU     6
RESETDEV                                        EQU     7
SETBREAK                                        EQU     8
CLRBREAK                                        EQU     9

PURGE_TXABORT                                   EQU     0001H
PURGE_RXABORT                                   EQU     0002H
PURGE_TXCLEAR                                   EQU     0004H
PURGE_RXCLEAR                                   EQU     0008H

LPTx                                            EQU     80H

MS_CTS_ON                                       EQU     0010H
MS_DSR_ON                                       EQU     0020H
MS_RING_ON                                      EQU     0040H
MS_RLSD_ON                                      EQU     0080H

S_QUEUEEMPTY                                    EQU     0
S_THRESHOLD                                     EQU     1
S_ALLTHRESHOLD                                  EQU     2

S_NORMAL                                        EQU     0
S_LEGATO                                        EQU     1
S_STACCATO                                      EQU     2

S_PERIOD512                                     EQU     0
S_PERIOD1024                                    EQU     1
S_PERIOD2048                                    EQU     2
S_PERIODVOICE                                   EQU     3
S_WHITE512                                      EQU     4
S_WHITE1024                                     EQU     5
S_WHITE2048                                     EQU     6
S_WHITEVOICE                                    EQU     7

S_SERDVNA                                       EQU     (-1)
S_SEROFM                                        EQU     (-2)
S_SERMACT                                       EQU     (-3)
S_SERQFUL                                       EQU     (-4)
S_SERBDNT                                       EQU     (-5)
S_SERDLN                                        EQU     (-6)
S_SERDCC                                        EQU     (-7)
S_SERDTP                                        EQU     (-8)
S_SERDVL                                        EQU     (-9)
S_SERDMD                                        EQU     (-10)
S_SERDSH                                        EQU     (-11)
S_SERDPT                                        EQU     (-12)
S_SERDFQ                                        EQU     (-13)
S_SERDDR                                        EQU     (-14)
S_SERDSR                                        EQU     (-15)
S_SERDST                                        EQU     (-16)

NMPWAIT_WAIT_FOREVER                            EQU     0FFFFFFFFH
NMPWAIT_NOWAIT                                  EQU     000000001H
NMPWAIT_USE_DEFAULT_WAIT                        EQU     000000000H

FS_CASE_IS_PRESERVED                            EQU     2
FS_CASE_SENSITIVE                               EQU     1
FS_UNICODE_STORED_ON_DISK                       EQU     4
FS_PERSISTENT_ACLS                              EQU     8

FS_VOL_IS_COMPRESSED                            EQU     8000H

FS_FILE_COMPRESSION                             EQU     10H
FS_FILE_ENCRYPTION                              EQU     00020000H

FILE_MAP_COPY                                   EQU     1
FILE_MAP_WRITE                                  EQU     2
FILE_MAP_READ                                   EQU     4
FILE_MAP_ALL_ACCESS                             EQU     10H

OF_READ                                         EQU     00000000H
OF_WRITE                                        EQU     00000001H
OF_READWRITE                                    EQU     00000002H
OF_SHARE_COMPAT                                 EQU     00000000H
OF_SHARE_EXCLUSIVE                              EQU     00000010H
OF_SHARE_DENY_WRITE                             EQU     00000020H
OF_SHARE_DENY_READ                              EQU     00000030H
OF_SHARE_DENY_NONE                              EQU     00000040H
OF_PARSE                                        EQU     00000100H
OF_DELETE                                       EQU     00000200H
OF_VERIFY                                       EQU     00000400H
OF_CANCEL                                       EQU     00000800H
OF_CREATE                                       EQU     00001000H
OF_PROMPT                                       EQU     00002000H
OF_EXIST                                        EQU     00004000H
OF_REOPEN                                       EQU     00008000H

MAXINTATOM                                      EQU     0C000H
INVALID_ATOM                                    EQU     0

PROCESS_HEAP_REGION                             EQU     0001H
PROCESS_HEAP_UNCOMMITTED_RANGE                  EQU     0002H
PROCESS_HEAP_ENTRY_BUSY                         EQU     0004H
PROCESS_HEAP_ENTRY_MOVEABLE                     EQU     0010H
PROCESS_HEAP_ENTRY_DDESHARE                     EQU     0020H

SCS_32BIT_BINARY                                EQU     0
SCS_DOS_BINARY                                  EQU     1
SCS_WOW_BINARY                                  EQU     2
SCS_PIF_BINARY                                  EQU     3
SCS_POSIX_BINARY                                EQU     4
SCS_OS216_BINARY                                EQU     5
SCS_64BIT_BINARY                                EQU     6

IFDEF APP_WIN64
    SCS_THIS_PLATFORM_BINARY                    EQU     SCS_64BIT_BINARY
ELSE
    SCS_THIS_PLATFORM_BINARY                    EQU     SCS_32BIT_BINARY
ENDIF

SEM_FAILCRITICALERRORS                          EQU     0001H
SEM_NOGPFAULTERRORBOX                           EQU     0002H
SEM_NOALIGNMENTFAULTEXCEPT                      EQU     0004H
SEM_NOOPENFILEERRORBOX                          EQU     8000H

LOCKFILE_FAIL_IMMEDIATELY                       EQU     00000001H
LOCKFILE_EXCLUSIVE_LOCK                         EQU     00000002H

HANDLE_FLAG_INHERIT                             EQU     00000001H
HANDLE_FLAG_PROTECT_FROM_CLOSE                  EQU     00000002H

HINSTANCE_ERROR                                 EQU     32

GET_TAPE_MEDIA_INFORMATION                      EQU     0
GET_TAPE_DRIVE_INFORMATION                      EQU     1

SET_TAPE_MEDIA_INFORMATION                      EQU     0
SET_TAPE_DRIVE_INFORMATION                      EQU     1

FORMAT_MESSAGE_ALLOCATE_BUFFER                  EQU     00000100H
FORMAT_MESSAGE_IGNORE_INSERTS                   EQU     00000200H
FORMAT_MESSAGE_FROM_STRING                      EQU     00000400H
FORMAT_MESSAGE_FROM_HMODULE                     EQU     00000800H
FORMAT_MESSAGE_FROM_SYSTEM                      EQU     00001000H
FORMAT_MESSAGE_ARGUMENT_ARRAY                   EQU     00002000H
FORMAT_MESSAGE_MAX_WIDTH_MASK                   EQU     000000FFH

FILE_ENCRYPTABLE                                EQU     0
FILE_IS_ENCRYPTED                               EQU     1
FILE_SYSTEM_ATTR                                EQU     2
FILE_ROOT_DIR                                   EQU     3
FILE_SYSTEM_DIR                                 EQU     4
FILE_UNKNOWN                                    EQU     5
FILE_SYSTEM_NOT_SUPPORT                         EQU     6
FILE_USER_DISALLOWED                            EQU     7
FILE_READ_ONLY                                  EQU     8
FILE_DIR_DISALLOWED                             EQU     9

EFS_USE_RECOVERY_KEYS                           EQU     1

CREATE_FOR_IMPORT                               EQU     1
CREATE_FOR_DIR                                  EQU     2

TLS_OUT_OF_INDEXES                              EQU     0FFFFFFFFH

BACKUP_INVALID                                  EQU     00000000H
BACKUP_DATA                                     EQU     00000001H
BACKUP_EA_DATA                                  EQU     00000002H
BACKUP_SECURITY_DATA                            EQU     00000003H
BACKUP_ALTERNATE_DATA                           EQU     00000004H
BACKUP_LINK                                     EQU     00000005H
BACKUP_PROPERTY_DATA                            EQU     00000006H
BACKUP_OBJECT_ID                                EQU     00000007H
BACKUP_REPARSE_DATA                             EQU     00000008H
BACKUP_SPARSE_BLOCK                             EQU     00000009H
BACKUP_TXFS_DATA                                EQU     0000000AH

STREAM_NORMAL_ATTRIBUTE                         EQU     00000000H
STREAM_MODIFIED_WHEN_READ                       EQU     00000001H
STREAM_CONTAINS_SECURITY                        EQU     00000002H
STREAM_CONTAINS_PROPERTIES                      EQU     00000004H
STREAM_SPARSE_ATTRIBUTE                         EQU     00000008H

STARTF_USESHOWWINDOW                            EQU     00000001H
STARTF_USESIZE                                  EQU     00000002H
STARTF_USEPOSITION                              EQU     00000004H
STARTF_USECOUNTCHARS                            EQU     00000008H
STARTF_USEFILLATTRIBUTE                         EQU     00000010H
STARTF_RUNFULLSCREEN                            EQU     00000020H
STARTF_FORCEONFEEDBACK                          EQU     00000040H
STARTF_FORCEOFFFEEDBACK                         EQU     00000080H
STARTF_USESTDHANDLES                            EQU     00000100H

SHUTDOWN_NORETRY                                EQU     00000001H

FIND_RESOURCE_DIRECTORY_TYPES                   EQU     00100H
FIND_RESOURCE_DIRECTORY_NAMES                   EQU     00200H
FIND_RESOURCE_DIRECTORY_LANGUAGES               EQU     00400H
RESOURCE_ENUM_LN                                EQU     00001H
RESOURCE_ENUM_MUI                               EQU     00002H
RESOURCE_ENUM_MUI_SYSTEM                        EQU     00004H
RESOURCE_ENUM_VALIDATE                          EQU     00008H
RESOURCE_ENUM_MODULE_EXACT                      EQU     00010H

SUPPORT_LANG_NUMBER                             EQU     32

GET_MODULE_HANDLE_EX_FLAG_PIN                   EQU     000000001H
GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT    EQU     000000002H
GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS          EQU     000000004H

DONT_RESOLVE_DLL_REFERENCES                     EQU     00000001H
LOAD_LIBRARY_AS_DATAFILE                        EQU     00000002H
LOAD_WITH_ALTERED_SEARCH_PATH                   EQU     00000008H

LOAD_IGNORE_CODE_AUTHZ_LEVEL                    EQU     000000010H
LOAD_LIBRARY_AS_IMAGE_RESOURCE                  EQU     000000020H
LOAD_LIBRARY_AS_DATAFILE_EXCLUSIVE              EQU     000000040H
LOAD_LIBRARY_REQUIRE_SIGNED_TARGET              EQU     000000080H
LOAD_LIBRARY_SEARCH_DLL_LOAD_DIR                EQU     000000100H
LOAD_LIBRARY_SEARCH_APPLICATION_DIR             EQU     000000200H
LOAD_LIBRARY_SEARCH_USER_DIRS                   EQU     000000400H
LOAD_LIBRARY_SEARCH_SYSTEM32                    EQU     000000800H
LOAD_LIBRARY_SEARCH_DEFAULT_DIRS                EQU     000001000H

DDD_RAW_TARGET_PATH                             EQU     00000001H
DDD_REMOVE_DEFINITION                           EQU     00000002H
DDD_EXACT_MATCH_ON_REMOVE                       EQU     00000004H
DDD_NO_BROADCAST_SYSTEM                         EQU     00000008H
DDD_LUID_BROADCAST_DRIVE                        EQU     00000010H

FIND_FIRST_EX_CASE_SENSITIVE                    EQU     00000001H
FIND_FIRST_EX_LARGE_FETCH                       EQU     00000002H

MOVEFILE_REPLACE_EXISTING                       EQU     00000001H
MOVEFILE_COPY_ALLOWED                           EQU     00000002H
MOVEFILE_DELAY_UNTIL_REBOOT                     EQU     00000004H
MOVEFILE_WRITE_THROUGH                          EQU     00000008H
MOVEFILE_CREATE_HARDLINK                        EQU     00000010H
MOVEFILE_FAIL_IF_NOT_TRACKABLE                  EQU     00000020H

EVENTLOG_FULL_INFO                              EQU     0

MAX_COMPUTERNAME_LENGTH                         EQU     15

LOGON32_LOGON_INTERACTIVE                       EQU     2
LOGON32_LOGON_NETWORK                           EQU     3
LOGON32_LOGON_BATCH                             EQU     4
LOGON32_LOGON_SERVICE                           EQU     5
LOGON32_LOGON_UNLOCK                            EQU     7
LOGON32_LOGON_NETWORK_CLEARTEXT                 EQU     8
LOGON32_LOGON_NEW_CREDENTIALS                   EQU     9

LOGON32_PROVIDER_DEFAULT                        EQU     0
LOGON32_PROVIDER_WINNT35                        EQU     1
LOGON32_PROVIDER_WINNT40                        EQU     2
LOGON32_PROVIDER_WINNT50                        EQU     3
LOGON32_PROVIDER_VIRTUAL                        EQU     4

LOGON_WITH_PROFILE                              EQU     00000001H
LOGON_NETCREDENTIALS_ONLY                       EQU     00000002H
LOGON_ZERO_PASSWORD_BUFFER                      EQU     80000000H

MAX_MANGLED_SITE                                EQU     27

HW_PROFILE_GUIDLEN                              EQU     39
MAX_PROFILE_LEN                                 EQU     80

DOCKINFO_UNDOCKED                               EQU     1
DOCKINFO_DOCKED                                 EQU     2
DOCKINFO_USER_SUPPLIED                          EQU     4
DOCKINFO_USER_UNDOCKED                          EQU     (DOCKINFO_USER_SUPPLIED OR DOCKINFO_UNDOCKED)
DOCKINFO_USER_DOCKED                            EQU     (DOCKINFO_USER_SUPPLIED OR DOCKINFO_DOCKED)

TC_NORMAL                                       EQU     0
TC_HARDERR                                      EQU     1
TC_GP_TRAP                                      EQU     2
TC_SIGNAL                                       EQU     3

AC_LINE_OFFLINE                                 EQU     00H
AC_LINE_ONLINE                                  EQU     01H
AC_LINE_BACKUP_POWER                            EQU     02H
AC_LINE_UNKNOWN                                 EQU     0FFH

BATTERY_FLAG_HIGH                               EQU     01H
BATTERY_FLAG_LOW                                EQU     02H
BATTERY_FLAG_CRITICAL                           EQU     04H
BATTERY_FLAG_CHARGING                           EQU     08H
BATTERY_FLAG_NO_BATTERY                         EQU     80H
BATTERY_FLAG_UNKNOWN                            EQU     0FFH
BATTERY_PERCENTAGE_UNKNOWN                      EQU     0FFH
BATTERY_LIFE_UNKNOWN                            EQU     0FFFFFFFFH

MAX_LEADBYTES                                   EQU     12
MAX_DEFAULTCHAR                                 EQU     2

HIGH_SURROGATE_START                            EQU     0D800H
HIGH_SURROGATE_END                              EQU     0DBFFH
LOW_SURROGATE_START                             EQU     0DC00H
LOW_SURROGATE_END                               EQU     0DFFFH

MB_PRECOMPOSED                                  EQU     000000001H
MB_COMPOSITE                                    EQU     000000002H
MB_USEGLYPHCHARS                                EQU     000000004H
MB_ERR_INVALID_CHARS                            EQU     000000008H

WC_COMPOSITECHECK                               EQU     000000200H
WC_DISCARDNS                                    EQU     000000010H
WC_SEPCHARS                                     EQU     000000020H
WC_DEFAULTCHAR                                  EQU     000000040H

WC_ERR_INVALID_CHARS                            EQU     000000080H
WC_NO_BEST_FIT_CHARS                            EQU     000000400H

CT_CTYPE1                                       EQU     000000001H
CT_CTYPE2                                       EQU     000000002H
CT_CTYPE3                                       EQU     000000004H

C1_UPPER                                        EQU     00001H
C1_LOWER                                        EQU     00002H
C1_DIGIT                                        EQU     00004H
C1_SPACE                                        EQU     00008H
C1_PUNCT                                        EQU     00010H
C1_CNTRL                                        EQU     00020H
C1_BLANK                                        EQU     00040H
C1_XDIGIT                                       EQU     00080H
C1_ALPHA                                        EQU     00100H
C1_DEFINED                                      EQU     00200H

C2_LEFTTORIGHT                                  EQU     00001H
C2_RIGHTTOLEFT                                  EQU     00002H
C2_EUROPENUMBER                                 EQU     00003H
C2_EUROPESEPARATOR                              EQU     00004H
C2_EUROPETERMINATOR                             EQU     00005H
C2_ARABICNUMBER                                 EQU     00006H
C2_COMMONSEPARATOR                              EQU     00007H
C2_BLOCKSEPARATOR                               EQU     00008H
C2_SEGMENTSEPARATOR                             EQU     00009H
C2_WHITESPACE                                   EQU     0000AH
C2_OTHERNEUTRAL                                 EQU     0000BH
C2_NOTAPPLICABLE                                EQU     00000H

C3_NONSPACING                                   EQU     00001H
C3_DIACRITIC                                    EQU     00002H
C3_VOWELMARK                                    EQU     00004H
C3_SYMBOL                                       EQU     00008H
C3_KATAKANA                                     EQU     00010H
C3_HIRAGANA                                     EQU     00020H
C3_HALFWIDTH                                    EQU     00040H
C3_FULLWIDTH                                    EQU     00080H
C3_IDEOGRAPH                                    EQU     00100H
C3_KASHIDA                                      EQU     00200H
C3_LEXICAL                                      EQU     00400H
C3_HIGHSURROGATE                                EQU     00800H
C3_LOWSURROGATE                                 EQU     01000H
C3_ALPHA                                        EQU     08000H
C3_NOTAPPLICABLE                                EQU     00000H

NORM_IGNORECASE                                 EQU     000000001H
NORM_IGNORENONSPACE                             EQU     000000002H
NORM_IGNORESYMBOLS                              EQU     000000004H
LINGUISTIC_IGNORECASE                           EQU     000000010H
LINGUISTIC_IGNOREDIACRITIC                      EQU     000000020H
NORM_IGNOREKANATYPE                             EQU     000010000H
NORM_IGNOREWIDTH                                EQU     000020000H
NORM_LINGUISTIC_CASING                          EQU     008000000H

MAP_FOLDCZONE                                   EQU     000000010H
MAP_PRECOMPOSED                                 EQU     000000020H
MAP_COMPOSITE                                   EQU     000000040H
MAP_FOLDDIGITS                                  EQU     000000080H
MAP_EXPAND_LIGATURES                            EQU     000002000H

LCMAP_LOWERCASE                                 EQU     000000100H
LCMAP_UPPERCASE                                 EQU     000000200H
LCMAP_TITLECASE                                 EQU     000000300H
LCMAP_SORTKEY                                   EQU     000000400H
LCMAP_BYTEREV                                   EQU     000000800H
LCMAP_HIRAGANA                                  EQU     000100000H
LCMAP_KATAKANA                                  EQU     000200000H
LCMAP_HALFWIDTH                                 EQU     000400000H
LCMAP_FULLWIDTH                                 EQU     000800000H
LCMAP_LINGUISTIC_CASING                         EQU     001000000H
LCMAP_SIMPLIFIED_CHINESE                        EQU     002000000H
LCMAP_TRADITIONAL_CHINESE                       EQU     004000000H
LCMAP_SORTHANDLE                                EQU     020000000H
LCMAP_HASH                                      EQU     000040000H

FIND_STARTSWITH                                 EQU     000100000H
FIND_ENDSWITH                                   EQU     000200000H
FIND_FROMSTART                                  EQU     000400000H
FIND_FROMEND                                    EQU     000800000H

LGRPID_INSTALLED                                EQU     000000001H
LGRPID_SUPPORTED                                EQU     000000002H

LCID_INSTALLED                                  EQU     000000001H
LCID_SUPPORTED                                  EQU     000000002H
LCID_ALTERNATE_SORTS                            EQU     000000004H

LOCALE_ALL                                      EQU     0
LOCALE_WINDOWS                                  EQU     000000001H
LOCALE_SUPPLEMENTAL                             EQU     000000002H
LOCALE_ALTERNATE_SORTS                          EQU     000000004H
LOCALE_REPLACEMENT                              EQU     000000008H
LOCALE_NEUTRALDATA                              EQU     000000010H
LOCALE_SPECIFICDATA                             EQU     000000020H

CP_INSTALLED                                    EQU     000000001H
CP_SUPPORTED                                    EQU     000000002H

SORT_STRINGSORT                                 EQU     000001000H
SORT_DIGITSASNUMBERS                            EQU     000000008H

CSTR_LESS_THAN                                  EQU     1
CSTR_EQUAL                                      EQU     2
CSTR_GREATER_THAN                               EQU     3

CP_ACP                                          EQU     0
CP_OEMCP                                        EQU     1
CP_MACCP                                        EQU     2
CP_THREAD_ACP                                   EQU     3
CP_SYMBOL                                       EQU     42
CP_UTF7                                         EQU     65000
CP_UTF8                                         EQU     65001

CTRY_DEFAULT                                    EQU     0
CTRY_ALBANIA                                    EQU     355
CTRY_ALGERIA                                    EQU     213
CTRY_ARGENTINA                                  EQU     54
CTRY_ARMENIA                                    EQU     374
CTRY_AUSTRALIA                                  EQU     61
CTRY_AUSTRIA                                    EQU     43
CTRY_AZERBAIJAN                                 EQU     994
CTRY_BAHRAIN                                    EQU     973
CTRY_BELARUS                                    EQU     375
CTRY_BELGIUM                                    EQU     32
CTRY_BELIZE                                     EQU     501
CTRY_BOLIVIA                                    EQU     591
CTRY_BRAZIL                                     EQU     55
CTRY_BRUNEI_DARUSSALAM                          EQU     673
CTRY_BULGARIA                                   EQU     359
CTRY_CANADA                                     EQU     2
CTRY_CARIBBEAN                                  EQU     1
CTRY_CHILE                                      EQU     56
CTRY_COLOMBIA                                   EQU     57
CTRY_COSTA_RICA                                 EQU     506
CTRY_CROATIA                                    EQU     385
CTRY_CZECH                                      EQU     420
CTRY_DENMARK                                    EQU     45
CTRY_DOMINICAN_REPUBLIC                         EQU     1
CTRY_ECUADOR                                    EQU     593
CTRY_EGYPT                                      EQU     20
CTRY_EL_SALVADOR                                EQU     503
CTRY_ESTONIA                                    EQU     372
CTRY_FAEROE_ISLANDS                             EQU     298
CTRY_FINLAND                                    EQU     358
CTRY_FRANCE                                     EQU     33
CTRY_GEORGIA                                    EQU     995
CTRY_GERMANY                                    EQU     49
CTRY_GREECE                                     EQU     30
CTRY_GUATEMALA                                  EQU     502
CTRY_HONDURAS                                   EQU     504
CTRY_HONG_KONG                                  EQU     852
CTRY_HUNGARY                                    EQU     36
CTRY_ICELAND                                    EQU     354
CTRY_INDIA                                      EQU     91
CTRY_INDONESIA                                  EQU     62
CTRY_IRAN                                       EQU     981
CTRY_IRAQ                                       EQU     964
CTRY_IRELAND                                    EQU     353
CTRY_ISRAEL                                     EQU     972
CTRY_ITALY                                      EQU     39
CTRY_JAMAICA                                    EQU     1
CTRY_JAPAN                                      EQU     81
CTRY_JORDAN                                     EQU     962
CTRY_KAZAKSTAN                                  EQU     7
CTRY_KENYA                                      EQU     254
CTRY_KUWAIT                                     EQU     965
CTRY_KYRGYZSTAN                                 EQU     996
CTRY_LATVIA                                     EQU     371
CTRY_LEBANON                                    EQU     961
CTRY_LIBYA                                      EQU     218
CTRY_LIECHTENSTEIN                              EQU     41
CTRY_LITHUANIA                                  EQU     370
CTRY_LUXEMBOURG                                 EQU     352
CTRY_MACAU                                      EQU     853
CTRY_MACEDONIA                                  EQU     389
CTRY_MALAYSIA                                   EQU     60
CTRY_MALDIVES                                   EQU     960
CTRY_MEXICO                                     EQU     52
CTRY_MONACO                                     EQU     33
CTRY_MONGOLIA                                   EQU     976
CTRY_MOROCCO                                    EQU     212
CTRY_NETHERLANDS                                EQU     31
CTRY_NEW_ZEALAND                                EQU     64
CTRY_NICARAGUA                                  EQU     505
CTRY_NORWAY                                     EQU     47
CTRY_OMAN                                       EQU     968
CTRY_PAKISTAN                                   EQU     92
CTRY_PANAMA                                     EQU     507
CTRY_PARAGUAY                                   EQU     595
CTRY_PERU                                       EQU     51
CTRY_PHILIPPINES                                EQU     63
CTRY_POLAND                                     EQU     48
CTRY_PORTUGAL                                   EQU     351
CTRY_PRCHINA                                    EQU     86
CTRY_PUERTO_RICO                                EQU     1
CTRY_QATAR                                      EQU     974
CTRY_ROMANIA                                    EQU     40
CTRY_RUSSIA                                     EQU     7
CTRY_SAUDI_ARABIA                               EQU     966
CTRY_SERBIA                                     EQU     381
CTRY_SINGAPORE                                  EQU     65
CTRY_SLOVAK                                     EQU     421
CTRY_SLOVENIA                                   EQU     386
CTRY_SOUTH_AFRICA                               EQU     27
CTRY_SOUTH_KOREA                                EQU     82
CTRY_SPAIN                                      EQU     34
CTRY_SWEDEN                                     EQU     46
CTRY_SWITZERLAND                                EQU     41
CTRY_SYRIA                                      EQU     963
CTRY_TAIWAN                                     EQU     886
CTRY_TATARSTAN                                  EQU     7
CTRY_THAILAND                                   EQU     66
CTRY_TRINIDAD_Y_TOBAGO                          EQU     1
CTRY_TUNISIA                                    EQU     216
CTRY_TURKEY                                     EQU     90
CTRY_UAE                                        EQU     971
CTRY_UKRAINE                                    EQU     380
CTRY_UNITED_KINGDOM                             EQU     44
CTRY_UNITED_STATES                              EQU     1
CTRY_URUGUAY                                    EQU     598
CTRY_UZBEKISTAN                                 EQU     7
CTRY_VENEZUELA                                  EQU     58
CTRY_VIET_NAM                                   EQU     84
CTRY_YEMEN                                      EQU     967
CTRY_ZIMBABWE                                   EQU     263

LOCALE_NOUSEROVERRIDE                           EQU     080000000H
LOCALE_USE_CP_ACP                               EQU     040000000H
LOCALE_RETURN_NUMBER                            EQU     020000000H
LOCALE_RETURN_GENITIVE_NAMES                    EQU     010000000H
LOCALE_ALLOW_NEUTRAL_NAMES                      EQU     008000000H

LOCALE_SLOCALIZEDDISPLAYNAME                    EQU     000000002H
LOCALE_SENGLISHDISPLAYNAME                      EQU     000000072H
LOCALE_SNATIVEDISPLAYNAME                       EQU     000000073H
LOCALE_SLOCALIZEDLANGUAGENAME                   EQU     00000006fH
LOCALE_SENGLISHLANGUAGENAME                     EQU     000001001H
LOCALE_SNATIVELANGUAGENAME                      EQU     000000004H
LOCALE_SLOCALIZEDCOUNTRYNAME                    EQU     000000006H
LOCALE_SENGLISHCOUNTRYNAME                      EQU     000001002H
LOCALE_SNATIVECOUNTRYNAME                       EQU     000000008H

LOCALE_SLANGUAGE                                EQU     000000002H

LOCALE_SLANGDISPLAYNAME                         EQU     00000006fH

LOCALE_SENGLANGUAGE                             EQU     000001001H
LOCALE_SNATIVELANGNAME                          EQU     000000004H
LOCALE_SCOUNTRY                                 EQU     000000006H
LOCALE_SENGCOUNTRY                              EQU     000001002H
LOCALE_SNATIVECTRYNAME                          EQU     000000008H

LOCALE_ILANGUAGE                                EQU     000000001H
LOCALE_SABBREVLANGNAME                          EQU     000000003H
LOCALE_ICOUNTRY                                 EQU     000000005H
LOCALE_SABBREVCTRYNAME                          EQU     000000007H
LOCALE_IGEOID                                   EQU     00000005BH
LOCALE_IDEFAULTLANGUAGE                         EQU     000000009H
LOCALE_IDEFAULTCOUNTRY                          EQU     00000000AH
LOCALE_IDEFAULTCODEPAGE                         EQU     00000000BH
LOCALE_IDEFAULTANSICODEPAGE                     EQU     000001004H
LOCALE_IDEFAULTMACCODEPAGE                      EQU     000001011H
LOCALE_SLIST                                    EQU     00000000CH
LOCALE_IMEASURE                                 EQU     00000000DH
LOCALE_SDECIMAL                                 EQU     00000000EH
LOCALE_STHOUSAND                                EQU     00000000FH
LOCALE_SGROUPING                                EQU     000000010H
LOCALE_IDIGITS                                  EQU     000000011H
LOCALE_ILZERO                                   EQU     000000012H
LOCALE_INEGNUMBER                               EQU     000001010H
LOCALE_SNATIVEDIGITS                            EQU     000000013H
LOCALE_SCURRENCY                                EQU     000000014H
LOCALE_SINTLSYMBOL                              EQU     000000015H
LOCALE_SMONDECIMALSEP                           EQU     000000016H
LOCALE_SMONTHOUSANDSEP                          EQU     000000017H
LOCALE_SMONGROUPING                             EQU     000000018H
LOCALE_ICURRDIGITS                              EQU     000000019H
LOCALE_IINTLCURRDIGITS                          EQU     00000001AH
LOCALE_ICURRENCY                                EQU     00000001BH
LOCALE_INEGCURR                                 EQU     00000001CH
LOCALE_SDATE                                    EQU     00000001DH
LOCALE_STIME                                    EQU     00000001EH
LOCALE_SSHORTDATE                               EQU     00000001FH
LOCALE_SLONGDATE                                EQU     000000020H
LOCALE_STIMEFORMAT                              EQU     000001003H
LOCALE_IDATE                                    EQU     000000021H
LOCALE_ILDATE                                   EQU     000000022H
LOCALE_ITIME                                    EQU     000000023H
LOCALE_ITIMEMARKPOSN                            EQU     000001005H
LOCALE_ICENTURY                                 EQU     000000024H
LOCALE_ITLZERO                                  EQU     000000025H
LOCALE_IDAYLZERO                                EQU     000000026H
LOCALE_IMONLZERO                                EQU     000000027H
LOCALE_S1159                                    EQU     000000028H
LOCALE_S2359                                    EQU     000000029H
LOCALE_ICALENDARTYPE                            EQU     000001009H
LOCALE_IOPTIONALCALENDAR                        EQU     00000100BH
LOCALE_IFIRSTDAYOFWEEK                          EQU     00000100CH
LOCALE_IFIRSTWEEKOFYEAR                         EQU     00000100DH
LOCALE_SDAYNAME1                                EQU     00000002AH
LOCALE_SDAYNAME2                                EQU     00000002BH
LOCALE_SDAYNAME3                                EQU     00000002CH
LOCALE_SDAYNAME4                                EQU     00000002DH
LOCALE_SDAYNAME5                                EQU     00000002EH
LOCALE_SDAYNAME6                                EQU     00000002FH
LOCALE_SDAYNAME7                                EQU     000000030H
LOCALE_SABBREVDAYNAME1                          EQU     000000031H
LOCALE_SABBREVDAYNAME2                          EQU     000000032H
LOCALE_SABBREVDAYNAME3                          EQU     000000033H
LOCALE_SABBREVDAYNAME4                          EQU     000000034H
LOCALE_SABBREVDAYNAME5                          EQU     000000035H
LOCALE_SABBREVDAYNAME6                          EQU     000000036H
LOCALE_SABBREVDAYNAME7                          EQU     000000037H
LOCALE_SMONTHNAME1                              EQU     000000038H
LOCALE_SMONTHNAME2                              EQU     000000039H
LOCALE_SMONTHNAME3                              EQU     00000003AH
LOCALE_SMONTHNAME4                              EQU     00000003BH
LOCALE_SMONTHNAME5                              EQU     00000003CH
LOCALE_SMONTHNAME6                              EQU     00000003DH
LOCALE_SMONTHNAME7                              EQU     00000003EH
LOCALE_SMONTHNAME8                              EQU     00000003FH
LOCALE_SMONTHNAME9                              EQU     000000040H
LOCALE_SMONTHNAME10                             EQU     000000041H
LOCALE_SMONTHNAME11                             EQU     000000042H
LOCALE_SMONTHNAME12                             EQU     000000043H
LOCALE_SMONTHNAME13                             EQU     00000100EH
LOCALE_SABBREVMONTHNAME1                        EQU     000000044H
LOCALE_SABBREVMONTHNAME2                        EQU     000000045H
LOCALE_SABBREVMONTHNAME3                        EQU     000000046H
LOCALE_SABBREVMONTHNAME4                        EQU     000000047H
LOCALE_SABBREVMONTHNAME5                        EQU     000000048H
LOCALE_SABBREVMONTHNAME6                        EQU     000000049H
LOCALE_SABBREVMONTHNAME7                        EQU     00000004AH
LOCALE_SABBREVMONTHNAME8                        EQU     00000004BH
LOCALE_SABBREVMONTHNAME9                        EQU     00000004CH
LOCALE_SABBREVMONTHNAME10                       EQU     00000004DH
LOCALE_SABBREVMONTHNAME11                       EQU     00000004EH
LOCALE_SABBREVMONTHNAME12                       EQU     00000004FH
LOCALE_SABBREVMONTHNAME13                       EQU     00000100FH
LOCALE_SPOSITIVESIGN                            EQU     000000050H
LOCALE_SNEGATIVESIGN                            EQU     000000051H
LOCALE_IPOSSIGNPOSN                             EQU     000000052H
LOCALE_INEGSIGNPOSN                             EQU     000000053H
LOCALE_IPOSSYMPRECEDES                          EQU     000000054H
LOCALE_IPOSSEPBYSPACE                           EQU     000000055H
LOCALE_INEGSYMPRECEDES                          EQU     000000056H
LOCALE_INEGSEPBYSPACE                           EQU     000000057H

LOCALE_FONTSIGNATURE                            EQU     000000058H
LOCALE_SISO639LANGNAME                          EQU     000000059H
LOCALE_SISO3166CTRYNAME                         EQU     00000005AH

LOCALE_IDEFAULTEBCDICCODEPAGE                   EQU     000001012H
LOCALE_IPAPERSIZE                               EQU     00000100AH
LOCALE_SENGCURRNAME                             EQU     000001007H
LOCALE_SNATIVECURRNAME                          EQU     000001008H
LOCALE_SYEARMONTH                               EQU     000001006H
LOCALE_SSORTNAME                                EQU     000001013H
LOCALE_IDIGITSUBSTITUTION                       EQU     000001014H

LOCALE_SNAME                                    EQU     00000005CH
LOCALE_SDURATION                                EQU     00000005DH
LOCALE_SKEYBOARDSTOINSTALL                      EQU     00000005EH
LOCALE_SSHORTESTDAYNAME1                        EQU     000000060H
LOCALE_SSHORTESTDAYNAME2                        EQU     000000061H
LOCALE_SSHORTESTDAYNAME3                        EQU     000000062H
LOCALE_SSHORTESTDAYNAME4                        EQU     000000063H
LOCALE_SSHORTESTDAYNAME5                        EQU     000000064H
LOCALE_SSHORTESTDAYNAME6                        EQU     000000065H
LOCALE_SSHORTESTDAYNAME7                        EQU     000000066H
LOCALE_SISO639LANGNAME2                         EQU     000000067H
LOCALE_SISO3166CTRYNAME2                        EQU     000000068H
LOCALE_SNAN                                     EQU     000000069H
LOCALE_SPOSINFINITY                             EQU     00000006AH
LOCALE_SNEGINFINITY                             EQU     00000006BH
LOCALE_SSCRIPTS                                 EQU     00000006CH
LOCALE_SPARENT                                  EQU     00000006DH
LOCALE_SCONSOLEFALLBACKNAME                     EQU     00000006EH

LOCALE_IREADINGLAYOUT                           EQU     000000070H
LOCALE_INEUTRAL                                 EQU     000000071H
LOCALE_INEGATIVEPERCENT                         EQU     000000074H
LOCALE_IPOSITIVEPERCENT                         EQU     000000075H
LOCALE_SPERCENT                                 EQU     000000076H
LOCALE_SPERMILLE                                EQU     000000077H
LOCALE_SMONTHDAY                                EQU     000000078H
LOCALE_SSHORTTIME                               EQU     000000079H
LOCALE_SOPENTYPELANGUAGETAG                     EQU     00000007AH
LOCALE_SSORTLOCALE                              EQU     00000007BH

TIME_NOMINUTESORSECONDS                         EQU     000000001H
TIME_NOSECONDS                                  EQU     000000002H
TIME_NOTIMEMARKER                               EQU     000000004H
TIME_FORCE24HOURFORMAT                          EQU     000000008H

DATE_SHORTDATE                                  EQU     000000001H
DATE_LONGDATE                                   EQU     000000002H
DATE_USE_ALT_CALENDAR                           EQU     000000004H
DATE_YEARMONTH                                  EQU     000000008H
DATE_LTRREADING                                 EQU     000000010H
DATE_RTLREADING                                 EQU     000000020H
DATE_AUTOLAYOUT                                 EQU     000000040H

CAL_NOUSEROVERRIDE                              EQU     LOCALE_NOUSEROVERRIDE
CAL_USE_CP_ACP                                  EQU     LOCALE_USE_CP_ACP
CAL_RETURN_NUMBER                               EQU     LOCALE_RETURN_NUMBER
CAL_RETURN_GENITIVE_NAMES                       EQU     LOCALE_RETURN_GENITIVE_NAMES

CAL_ICALINTVALUE                                EQU     000000001H
CAL_SCALNAME                                    EQU     000000002H
CAL_IYEAROFFSETRANGE                            EQU     000000003H
CAL_SERASTRING                                  EQU     000000004H
CAL_SSHORTDATE                                  EQU     000000005H
CAL_SLONGDATE                                   EQU     000000006H
CAL_SDAYNAME1                                   EQU     000000007H
CAL_SDAYNAME2                                   EQU     000000008H
CAL_SDAYNAME3                                   EQU     000000009H
CAL_SDAYNAME4                                   EQU     00000000AH
CAL_SDAYNAME5                                   EQU     00000000BH
CAL_SDAYNAME6                                   EQU     00000000CH
CAL_SDAYNAME7                                   EQU     00000000DH
CAL_SABBREVDAYNAME1                             EQU     00000000EH
CAL_SABBREVDAYNAME2                             EQU     00000000FH
CAL_SABBREVDAYNAME3                             EQU     000000010H
CAL_SABBREVDAYNAME4                             EQU     000000011H
CAL_SABBREVDAYNAME5                             EQU     000000012H
CAL_SABBREVDAYNAME6                             EQU     000000013H
CAL_SABBREVDAYNAME7                             EQU     000000014H

CAL_SMONTHNAME1                                 EQU     000000015H
CAL_SMONTHNAME2                                 EQU     000000016H
CAL_SMONTHNAME3                                 EQU     000000017H
CAL_SMONTHNAME4                                 EQU     000000018H
CAL_SMONTHNAME5                                 EQU     000000019H
CAL_SMONTHNAME6                                 EQU     00000001AH
CAL_SMONTHNAME7                                 EQU     00000001BH
CAL_SMONTHNAME8                                 EQU     00000001CH
CAL_SMONTHNAME9                                 EQU     00000001DH
CAL_SMONTHNAME10                                EQU     00000001EH
CAL_SMONTHNAME11                                EQU     00000001FH
CAL_SMONTHNAME12                                EQU     000000020H
CAL_SMONTHNAME13                                EQU     000000021H
CAL_SABBREVMONTHNAME1                           EQU     000000022H
CAL_SABBREVMONTHNAME2                           EQU     000000023H
CAL_SABBREVMONTHNAME3                           EQU     000000024H
CAL_SABBREVMONTHNAME4                           EQU     000000025H
CAL_SABBREVMONTHNAME5                           EQU     000000026H
CAL_SABBREVMONTHNAME6                           EQU     000000027H
CAL_SABBREVMONTHNAME7                           EQU     000000028H
CAL_SABBREVMONTHNAME8                           EQU     000000029H
CAL_SABBREVMONTHNAME9                           EQU     00000002AH
CAL_SABBREVMONTHNAME10                          EQU     00000002BH
CAL_SABBREVMONTHNAME11                          EQU     00000002CH
CAL_SABBREVMONTHNAME12                          EQU     00000002DH
CAL_SABBREVMONTHNAME13                          EQU     00000002EH

CAL_SYEARMONTH                                  EQU     00000002FH
CAL_ITWODIGITYEARMAX                            EQU     000000030H

CAL_SSHORTESTDAYNAME1                           EQU     000000031H
CAL_SSHORTESTDAYNAME2                           EQU     000000032H
CAL_SSHORTESTDAYNAME3                           EQU     000000033H
CAL_SSHORTESTDAYNAME4                           EQU     000000034H
CAL_SSHORTESTDAYNAME5                           EQU     000000035H
CAL_SSHORTESTDAYNAME6                           EQU     000000036H
CAL_SSHORTESTDAYNAME7                           EQU     000000037H

CAL_SMONTHDAY                                   EQU     000000038H
CAL_SABBREVERASTRING                            EQU     000000039H

ENUM_ALL_CALENDARS                              EQU     0FFFFFFFFH

CAL_GREGORIAN                                   EQU     1
CAL_GREGORIAN_US                                EQU     2
CAL_JAPAN                                       EQU     3
CAL_TAIWAN                                      EQU     4
CAL_KOREA                                       EQU     5
CAL_HIJRI                                       EQU     6
CAL_THAI                                        EQU     7
CAL_HEBREW                                      EQU     8
CAL_GREGORIAN_ME_FRENCH                         EQU     9
CAL_GREGORIAN_ARABIC                            EQU     10
CAL_GREGORIAN_XLIT_ENGLISH                      EQU     11
CAL_GREGORIAN_XLIT_FRENCH                       EQU     12
CAL_UMALQURA                                    EQU     23

LGRPID_WESTERN_EUROPE                           EQU     00001H
LGRPID_CENTRAL_EUROPE                           EQU     00002H
LGRPID_BALTIC                                   EQU     00003H
LGRPID_GREEK                                    EQU     00004H
LGRPID_CYRILLIC                                 EQU     00005H
LGRPID_TURKIC                                   EQU     00006H
LGRPID_TURKISH                                  EQU     00006H
LGRPID_JAPANESE                                 EQU     00007H
LGRPID_KOREAN                                   EQU     00008H
LGRPID_TRADITIONAL_CHINESE                      EQU     00009H
LGRPID_SIMPLIFIED_CHINESE                       EQU     0000AH
LGRPID_THAI                                     EQU     0000BH
LGRPID_HEBREW                                   EQU     0000CH
LGRPID_ARABIC                                   EQU     0000DH
LGRPID_VIETNAMESE                               EQU     0000EH
LGRPID_INDIC                                    EQU     0000FH
LGRPID_GEORGIAN                                 EQU     00010H
LGRPID_ARMENIAN                                 EQU     00011H

MUI_LANGUAGE_ID                                 EQU     0004H
MUI_LANGUAGE_NAME                               EQU     0008H
MUI_MERGE_SYSTEM_FALLBACK                       EQU     0010H
MUI_MERGE_USER_FALLBACK                         EQU     0020H
MUI_UI_FALLBACK                                 EQU     (MUI_MERGE_SYSTEM_FALLBACK OR MUI_MERGE_USER_FALLBACK)
MUI_THREAD_LANGUAGES                            EQU     0040H
MUI_CONSOLE_FILTER                              EQU     0100H
MUI_COMPLEX_SCRIPT_FILTER                       EQU     0200H
MUI_RESET_FILTERS                               EQU     0001H
MUI_USER_PREFERRED_UI_LANGUAGES                 EQU     0010H
MUI_USE_INSTALLED_LANGUAGES                     EQU     0020H
MUI_USE_SEARCH_ALL_LANGUAGES                    EQU     0040H
MUI_LANG_NEUTRAL_PE_FILE                        EQU     0100H
MUI_NON_LANG_NEUTRAL_FILE                       EQU     0200H
MUI_MACHINE_LANGUAGE_SETTINGS                   EQU     0400H
MUI_FILETYPE_NOT_LANGUAGE_NEUTRAL               EQU     0001H
MUI_FILETYPE_LANGUAGE_NEUTRAL_MAIN              EQU     0002H
MUI_FILETYPE_LANGUAGE_NEUTRAL_MUI               EQU     0004H
MUI_QUERY_TYPE                                  EQU     0001H
MUI_QUERY_CHECKSUM                              EQU     0002H
MUI_QUERY_LANGUAGE_NAME                         EQU     0004H
MUI_QUERY_RESOURCE_TYPES                        EQU     0008H
MUI_FILEINFO_VERSION                            EQU     0001H
MUI_FULL_LANGUAGE                               EQU     0001H
MUI_PARTIAL_LANGUAGE                            EQU     0002H
MUI_LIP_LANGUAGE                                EQU     0004H
MUI_LANGUAGE_INSTALLED                          EQU     0020H
MUI_LANGUAGE_LICENSED                           EQU     0040H

COMPARE_STRING                                  EQU     0001H

GEOID                                           TYPEDEF DWORD
GEOTYPE                                         TYPEDEF DWORD
GEOCLASS                                        TYPEDEF DWORD
GEOID_NOT_AVAILABLE                             EQU     (-1)

GEO_NATION                                      EQU     00001H
GEO_LATITUDE                                    EQU     00002H
GEO_LONGITUDE                                   EQU     00003H
GEO_ISO2                                        EQU     00004H
GEO_ISO3                                        EQU     00005H
GEO_RFC1766                                     EQU     00006H
GEO_LCID                                        EQU     00007H
GEO_FRIENDLYNAME                                EQU     00008H
GEO_OFFICIALNAME                                EQU     00009H
GEO_TIMEZONES                                   EQU     0000AH
GEO_OFFICIALLANGUAGES                           EQU     0000BH
GEO_ISO_UN_NUMBER                               EQU     0000CH
GEO_PARENT                                      EQU     0000DH

GEOCLASS_NATION                                 EQU     16
GEOCLASS_REGION                                 EQU     14
GEOCLASS_ALL                                    EQU     0

NormalizationOther                              EQU     0
NormalizationC                                  EQU     01H
NormalizationD                                  EQU     02H
NormalizationKC                                 EQU     05H
NormalizationKD                                 EQU     06H

IDN_ALLOW_UNASSIGNED                            EQU     001H
IDN_USE_STD3_ASCII_RULES                        EQU     002H
IDN_EMAIL_ADDRESS                               EQU     004H
IDN_RAW_PUNYCODE                                EQU     008H

VS_ALLOW_LATIN                                  EQU     00001H

GSS_ALLOW_INHERITED_COMMON                      EQU     00001H

MUI_FORMAT_REG_COMPAT                           EQU     00001H
MUI_FORMAT_INF_COMPAT                           EQU     00002H
MUI_VERIFY_FILE_EXISTS                          EQU     00004H
MUI_SKIP_STRING_CACHE                           EQU     00008H
MUI_IMMUTABLE_LOOKUP                            EQU     00010H

LOCALE_NAME_USER_DEFAULT                        EQU     NULL
LOCALE_NAME_INVARIANT                           TEXTEQU <L"">
LOCALE_NAME_SYSTEM_DEFAULT                      TEXTEQU <L"!x-sys-default-locale">

GetFileExInfoStandard                           EQU     0
GetFileExMaxInfoLevel                           EQU     1

FindExInfoStandard                              EQU     0
FindExInfoMaxInfoLevel                          EQU     1

FindExSearchNameMatch                           EQU     0
FindExSearchLimitToDirectories                  EQU     1
FindExSearchLimitToDevices                      EQU     2
FindExSearchMaxSearchOp                         EQU     3

EVENTLOG_FULL_INFORMATION STRUCT ALIGNMODE
    dwFull  DD  ?
EVENTLOG_FULL_INFORMATION ENDS

ComputerNameNetBIOS                             EQU     0
ComputerNameDnsHostname                         EQU     1
ComputerNameDnsDomain                           EQU     2
ComputerNameDnsFullyQualified                   EQU     3
ComputerNamePhysicalNetBIOS                     EQU     4
ComputerNamePhysicalDnsHostname                 EQU     5
ComputerNamePhysicalDnsDomain                   EQU     6
ComputerNamePhysicalDnsFullyQualified           EQU     7
ComputerNameMax                                 EQU     8

LowMemoryResourceNotification                   EQU     0
HighMemoryResourceNotification                  EQU     1

WinNullSid                                      EQU     0
WinWorldSid                                     EQU     1
WinLocalSid                                     EQU     2
WinCreatorOwnerSid                              EQU     3
WinCreatorGroupSid                              EQU     4
WinCreatorOwnerServerSid                        EQU     5
WinCreatorGroupServerSid                        EQU     6
WinNtAuthoritySid                               EQU     7
WinDialupSid                                    EQU     8
WinNetworkSid                                   EQU     9
WinBatchSid                                     EQU     10
WinInteractiveSid                               EQU     11
WinServiceSid                                   EQU     12
WinAnonymousSid                                 EQU     13
WinProxySid                                     EQU     14
WinEnterpriseControllersSid                     EQU     15
WinSelfSid                                      EQU     16
WinAuthenticatedUserSid                         EQU     17
WinRestrictedCodeSid                            EQU     18
WinTerminalServerSid                            EQU     19
WinRemoteLogonIdSid                             EQU     20
WinLogonIdsSid                                  EQU     21
WinLocalSystemSid                               EQU     22
WinLocalServiceSid                              EQU     23
WinNetworkServiceSid                            EQU     24
WinBuiltinDomainSid                             EQU     25
WinBuiltinAdministratorsSid                     EQU     26
WinBuiltinUsersSid                              EQU     27
WinBuiltinGuestsSid                             EQU     28
WinBuiltinPowerUsersSid                         EQU     29
WinBuiltinAccountOperatorsSid                   EQU     30
WinBuiltinSystemOperatorsSid                    EQU     31
WinBuiltinPrintOperatorsSid                     EQU     32
WinBuiltinBackupOperatorsSid                    EQU     33
WinBuiltinReplicatorSid                         EQU     34
WinBuiltinPreWindows2000CompatibleAccessSid     EQU     35
WinBuiltinRemoteDesktopUsersSid                 EQU     36
WinBuiltinNetworkConfigurationOperatorsSid      EQU     37
WinAccountAdministratorSid                      EQU     38
WinAccountGuestSid                              EQU     39
WinAccountKrbtgtSid                             EQU     40
WinAccountDomainAdminsSid                       EQU     41
WinAccountDomainUsersSid                        EQU     42
WinAccountDomainGuestsSid                       EQU     43
WinAccountComputersSid                          EQU     44
WinAccountControllersSid                        EQU     45
WinAccountCertAdminsSid                         EQU     46
WinAccountSchemaAdminsSid                       EQU     47
WinAccountEnterpriseAdminsSid                   EQU     48
WinAccountPolicyAdminsSid                       EQU     49
WinAccountRasAndIasServersSid                   EQU     50
WinNTLMAuthenticationSid                        EQU     51
WinDigestAuthenticationSid                      EQU     52
WinSChannelAuthenticationSid                    EQU     53
WinThisOrganizationSid                          EQU     54
WinOtherOrganizationSid                         EQU     55
WinBuiltinIncomingForestTrustBuildersSid        EQU     56
WinBuiltinPerfMonitoringUsersSid                EQU     57
WinBuiltinPerfLoggingUsersSid                   EQU     58
WinBuiltinAuthorizationAccessSid                EQU     59
WinBuiltinTerminalServerLicenseServersSid       EQU     60
WinBuiltinDCOMUsersSid                          EQU     61
WinBuiltinIUsersSid                             EQU     62
WinIUserSid                                     EQU     63
WinBuiltinCryptoOperatorsSid                    EQU     64
WinUntrustedLabelSid                            EQU     65
WinLowLabelSid                                  EQU     66
WinMediumLabelSid                               EQU     67
WinHighLabelSid                                 EQU     68
WinSystemLabelSid                               EQU     69
WinWriteRestrictedCodeSid                       EQU     70
WinCreatorOwnerRightsSid                        EQU     71
WinCacheablePrincipalsGroupSid                  EQU     72
WinNonCacheablePrincipalsGroupSid               EQU     73
WinEnterpriseReadonlyControllersSid             EQU     74
WinAccountReadonlyControllersSid                EQU     75
WinBuiltinEventLogReadersGroup                  EQU     76
WinNewEnterpriseReadonlyControllersSid          EQU     77
WinBuiltinCertSvcDComAccessGroup                EQU     78

ProcessMemoryPriority                           EQU     00H
ProcessInformationClassMax                      EQU     01H

ExceptionContinueExecution                      EQU     00H
ExceptionContinueSearch                         EQU     01H
ExceptionNestedException                        EQU     02H
ExceptionCollidedUnwind                         EQU     03H

EXCEPTION_EXECUTE_HANDLER                       EQU     1
EXCEPTION_CONTINUE_SEARCH                       EQU     0
EXCEPTION_CONTINUE_EXECUTION                    EQU     (-1)

DEPPolicyAlwaysOff                              EQU     00H
DEPPolicyAlwaysOn                               EQU     01H
DEPPolicyOptIn                                  EQU     02H
DEPPolicyOptOut                                 EQU     03H
DEPTotalPolicyCount                             EQU     04H

OVERWRITE_HIDDEN                                EQU     4
EFSRPC_SECURE_ONLY                              EQU     8

ATOM_FLAG_GLOBAL                                EQU     02H

BASE_SEARCH_PATH_ENABLE_SAFE_SEARCHMODE         EQU     01H
BASE_SEARCH_PATH_DISABLE_SAFE_SEARCHMODE        EQU     010000H
BASE_SEARCH_PATH_PERMANENT                      EQU     08000H
BASE_SEARCH_PATH_INVALID_FLAGS                  EQU     (NOT 018001H)

EXPAND_LOCAL_DRIVES                             EQU     1

RESTART_MAX_CMD_LINE                            EQU     1024
RESTART_NO_CRASH                                EQU     1
RESTART_NO_HANG                                 EQU     2
RESTART_NO_PATCH                                EQU     4

RESTART_NO_REBOOT                               EQU     8
RECOVERY_DEFAULT_PING_INTERVAL                  EQU     5000
RECOVERY_MAX_PING_INTERVAL                      EQU     (5 * 60 * 1000)

PSP_DEFAULT                                     EQU     000000000H
PSP_DLGINDIRECT                                 EQU     000000001H
PSP_USEHICON                                    EQU     000000002H
PSP_USEICONID                                   EQU     000000004H
PSP_USETITLE                                    EQU     000000008H
PSP_RTLREADING                                  EQU     000000010H
PSP_HASHELP                                     EQU     000000020H
PSP_USEREFPARENT                                EQU     000000040H
PSP_USECALLBACK                                 EQU     000000080H
PSP_PREMATURE                                   EQU     000000400H
PSP_HIDEHEADER                                  EQU     000000800H
PSP_USEHEADERTITLE                              EQU     000001000H
PSP_USEHEADERSUBTITLE                           EQU     000002000H

PSPCB_ADDREF                                    EQU     0
PSPCB_RELEASE                                   EQU     1
PSPCB_CREATE                                    EQU     2

PSH_DEFAULT                                     EQU     000000000H
PSH_PROPTITLE                                   EQU     000000001H
PSH_USEHICON                                    EQU     000000002H
PSH_USEICONID                                   EQU     000000004H
PSH_PROPSHEETPAGE                               EQU     000000008H
PSH_WIZARDHASFINISH                             EQU     000000010H
PSH_WIZARD                                      EQU     000000020H
PSH_USEPSTARTPAGE                               EQU     000000040H
PSH_NOAPPLYNOW                                  EQU     000000080H
PSH_USECALLBACK                                 EQU     000000100H
PSH_HASHELP                                     EQU     000000200H
PSH_MODELESS                                    EQU     000000400H
PSH_RTLREADING                                  EQU     000000800H
PSH_WIZARDCONTEXTHELP                           EQU     000001000H
PSH_WIZARD_LITE                                 EQU     000400000H
PSH_NOCONTEXTHELP                               EQU     002000000H

PSH_WIZARD97                                    EQU     000002000H
PSH_WATERMARK                                   EQU     000008000H
PSH_USEHBMWATERMARK                             EQU     000010000H
PSH_USEHPLWATERMARK                             EQU     000020000H
PSH_STRETCHWATERMARK                            EQU     000040000H
PSH_HEADER                                      EQU     000080000H
PSH_USEHBMHEADER                                EQU     000100000H
PSH_USEPAGELANG                                 EQU     000200000H

PSCB_INITIALIZED                                EQU     1
PSCB_PRECREATE                                  EQU     2

PSN_FIRST                                       EQU     (0 - 200)
PSN_LAST                                        EQU     (0 - 299)

PSN_SETACTIVE                                   EQU     (PSN_FIRST - 0)
PSN_KILLACTIVE                                  EQU     (PSN_FIRST - 1)
PSN_APPLY                                       EQU     (PSN_FIRST - 2)
PSN_RESET                                       EQU     (PSN_FIRST - 3)
PSN_HELP                                        EQU     (PSN_FIRST - 5)
PSN_WIZBACK                                     EQU     (PSN_FIRST - 6)
PSN_WIZNEXT                                     EQU     (PSN_FIRST - 7)
PSN_WIZFINISH                                   EQU     (PSN_FIRST - 8)
PSN_QUERYCANCEL                                 EQU     (PSN_FIRST - 9)
PSN_GETOBJECT                                   EQU     (PSN_FIRST - 10)
PSN_TRANSLATEACCELERATOR                        EQU     (PSN_FIRST - 12)
PSN_QUERYINITIALFOCUS                           EQU     (PSN_FIRST - 13)

PSNRET_NOERROR                                  EQU     0
PSNRET_INVALID                                  EQU     1
PSNRET_INVALID_NOCHANGEPAGE                     EQU     2
PSNRET_MESSAGEHANDLED                           EQU     3

PSM_SETCURSEL                                   EQU     (WM_USER + 101)
PSM_REMOVEPAGE                                  EQU     (WM_USER + 102)
PSM_ADDPAGE                                     EQU     (WM_USER + 103)
PSM_CHANGED                                     EQU     (WM_USER + 104)
PSM_RESTARTWINDOWS                              EQU     (WM_USER + 105)
PSM_REBOOTSYSTEM                                EQU     (WM_USER + 106)
PSM_CANCELTOCLOSE                               EQU     (WM_USER + 107)
PSM_QUERYSIBLINGS                               EQU     (WM_USER + 108)
PSM_UNCHANGED                                   EQU     (WM_USER + 109)
PSM_APPLY                                       EQU     (WM_USER + 110)
PSM_SETTITLEA                                   EQU     (WM_USER + 111)
PSM_SETWIZBUTTONS                               EQU     (WM_USER + 112)
PSM_PRESSBUTTON                                 EQU     (WM_USER + 113)
PSM_SETCURSELID                                 EQU     (WM_USER + 114)
PSM_SETFINISHTEXTA                              EQU     (WM_USER + 115)
PSM_GETTABCONTROL                               EQU     (WM_USER + 116)
PSM_ISDIALOGMESSAGE                             EQU     (WM_USER + 117)
PSM_GETCURRENTPAGEHWND                          EQU     (WM_USER + 118)
PSM_SETTITLEW                                   EQU     (WM_USER + 120)
PSM_SETFINISHTEXTW                              EQU     (WM_USER + 121)
PSM_SETHEADERTITLEA                             EQU     (WM_USER + 125)
PSM_SETHEADERTITLEW                             EQU     (WM_USER + 126)
PSM_SETHEADERSUBTITLEA                          EQU     (WM_USER + 127)
PSM_SETHEADERSUBTITLEW                          EQU     (WM_USER + 128)
PSM_HWNDTOINDEX                                 EQU     (WM_USER + 129)
PSM_INDEXTOHWND                                 EQU     (WM_USER + 130)
PSM_PAGETOINDEX                                 EQU     (WM_USER + 131)
PSM_INDEXTOPAGE                                 EQU     (WM_USER + 132)
PSM_IDTOINDEX                                   EQU     (WM_USER + 133)
PSM_INDEXTOID                                   EQU     (WM_USER + 134)
PSM_GETRESULT                                   EQU     (WM_USER + 135)
PSM_RECALCPAGESIZES                             EQU     (WM_USER + 136)

PSWIZB_BACK                                     EQU     000000001H
PSWIZB_NEXT                                     EQU     000000002H
PSWIZB_FINISH                                   EQU     000000004H
PSWIZB_DISABLEDFINISH                           EQU     000000008H

PSBTN_BACK                                      EQU     0
PSBTN_NEXT                                      EQU     1
PSBTN_FINISH                                    EQU     2
PSBTN_OK                                        EQU     3
PSBTN_APPLYNOW                                  EQU     4
PSBTN_CANCEL                                    EQU     5
PSBTN_HELP                                      EQU     6
PSBTN_MAX                                       EQU     6

ID_PSRESTARTWINDOWS                             EQU     02H
ID_PSREBOOTSYSTEM                               EQU     (ID_PSRESTARTWINDOWS OR 01H)

WIZ_CXDLG                                       EQU     276
WIZ_CYDLG                                       EQU     140

WIZ_CXBMP                                       EQU     80

WIZ_BODYX                                       EQU     92
WIZ_BODYCX                                      EQU     184

PROP_SM_CXDLG                                   EQU     212
PROP_SM_CYDLG                                   EQU     188

PROP_MED_CXDLG                                  EQU     227
PROP_MED_CYDLG                                  EQU     215

PROP_LG_CXDLG                                   EQU     252
PROP_LG_CYDLG                                   EQU     218

;====================================== rasapi32 ==========================================;
RASBASE                                         EQU     600
SUCCESS                                         EQU     0

PENDING                                         EQU     (RASBASE+0)
ERROR_INVALID_PORT_HANDLE                       EQU     (RASBASE+1)
ERROR_PORT_ALREADY_OPEN                         EQU     (RASBASE+2)
ERROR_BUFFER_TOO_SMALL                          EQU     (RASBASE+3)
ERROR_WRONG_INFO_SPECIFIED                      EQU     (RASBASE+4)
ERROR_CANNOT_SET_PORT_INFO                      EQU     (RASBASE+5)
ERROR_PORT_NOT_CONNECTED                        EQU     (RASBASE+6)
ERROR_EVENT_INVALID                             EQU     (RASBASE+7)
ERROR_DEVICE_DOES_NOT_EXIST                     EQU     (RASBASE+8)
ERROR_DEVICETYPE_DOES_NOT_EXIST                 EQU     (RASBASE+9)
ERROR_BUFFER_INVALID                            EQU     (RASBASE+10)
ERROR_ROUTE_NOT_AVAILABLE                       EQU     (RASBASE+11)
ERROR_ROUTE_NOT_ALLOCATED                       EQU     (RASBASE+12)
ERROR_INVALID_COMPRESSION_SPECIFIED             EQU     (RASBASE+13)
ERROR_OUT_OF_BUFFERS                            EQU     (RASBASE+14)
ERROR_PORT_NOT_FOUND                            EQU     (RASBASE+15)
ERROR_ASYNC_REQUEST_PENDING                     EQU     (RASBASE+16)
ERROR_ALREADY_DISCONNECTING                     EQU     (RASBASE+17)
ERROR_PORT_NOT_OPEN                             EQU     (RASBASE+18)
ERROR_PORT_DISCONNECTED                         EQU     (RASBASE+19)
ERROR_NO_ENDPOINTS                              EQU     (RASBASE+20)
ERROR_CANNOT_OPEN_PHONEBOOK                     EQU     (RASBASE+21)
ERROR_CANNOT_LOAD_PHONEBOOK                     EQU     (RASBASE+22)
ERROR_CANNOT_FIND_PHONEBOOK_ENTRY               EQU     (RASBASE+23)
ERROR_CANNOT_WRITE_PHONEBOOK                    EQU     (RASBASE+24)
ERROR_CORRUPT_PHONEBOOK                         EQU     (RASBASE+25)
ERROR_CANNOT_LOAD_STRING                        EQU     (RASBASE+26)
ERROR_KEY_NOT_FOUND                             EQU     (RASBASE+27)
ERROR_DISCONNECTION                             EQU     (RASBASE+28)
ERROR_REMOTE_DISCONNECTION                      EQU     (RASBASE+29)
ERROR_HARDWARE_FAILURE                          EQU     (RASBASE+30)
ERROR_USER_DISCONNECTION                        EQU     (RASBASE+31)
ERROR_INVALID_SIZE                              EQU     (RASBASE+32)
ERROR_PORT_NOT_AVAILABLE                        EQU     (RASBASE+33)
ERROR_CANNOT_PROJECT_CLIENT                     EQU     (RASBASE+34)
ERROR_UNKNOWN                                   EQU     (RASBASE+35)
ERROR_WRONG_DEVICE_ATTACHED                     EQU     (RASBASE+36)
ERROR_BAD_STRING                                EQU     (RASBASE+37)
ERROR_REQUEST_TIMEOUT                           EQU     (RASBASE+38)
ERROR_CANNOT_GET_LANA                           EQU     (RASBASE+39)
ERROR_NETBIOS_ERROR                             EQU     (RASBASE+40)
ERROR_SERVER_OUT_OF_RESOURCES                   EQU     (RASBASE+41)
ERROR_NAME_EXISTS_ON_NET                        EQU     (RASBASE+42)
ERROR_SERVER_GENERAL_NET_FAILURE                EQU     (RASBASE+43)
WARNING_MSG_ALIAS_NOT_ADDED                     EQU     (RASBASE+44)
ERROR_AUTH_INTERNAL                             EQU     (RASBASE+45)
ERROR_RESTRICTED_LOGON_HOURS                    EQU     (RASBASE+46)
ERROR_ACCT_DISABLED                             EQU     (RASBASE+47)
ERROR_PASSWD_EXPIRED                            EQU     (RASBASE+48)
ERROR_NO_DIALIN_PERMISSION                      EQU     (RASBASE+49)
ERROR_SERVER_NOT_RESPONDING                     EQU     (RASBASE+50)
ERROR_FROM_DEVICE                               EQU     (RASBASE+51)
ERROR_UNRECOGNIZED_RESPONSE                     EQU     (RASBASE+52)
ERROR_MACRO_NOT_FOUND                           EQU     (RASBASE+53)
ERROR_MACRO_NOT_DEFINED                         EQU     (RASBASE+54)
ERROR_MESSAGE_MACRO_NOT_FOUND                   EQU     (RASBASE+55)
ERROR_DEFAULTOFF_MACRO_NOT_FOUND                EQU     (RASBASE+56)
ERROR_FILE_COULD_NOT_BE_OPENED                  EQU     (RASBASE+57)
ERROR_DEVICENAME_TOO_LONG                       EQU     (RASBASE+58)
ERROR_DEVICENAME_NOT_FOUND                      EQU     (RASBASE+59)
ERROR_NO_RESPONSES                              EQU     (RASBASE+60)
ERROR_NO_COMMAND_FOUND                          EQU     (RASBASE+61)
ERROR_WRONG_KEY_SPECIFIED                       EQU     (RASBASE+62)
ERROR_UNKNOWN_DEVICE_TYPE                       EQU     (RASBASE+63)
ERROR_ALLOCATING_MEMORY                         EQU     (RASBASE+64)
ERROR_PORT_NOT_CONFIGURED                       EQU     (RASBASE+65)
ERROR_DEVICE_NOT_READY                          EQU     (RASBASE+66)
ERROR_READING_INI_FILE                          EQU     (RASBASE+67)
ERROR_NO_CONNECTION                             EQU     (RASBASE+68)
ERROR_BAD_USAGE_IN_INI_FILE                     EQU     (RASBASE+69)
ERROR_READING_SECTIONNAME                       EQU     (RASBASE+70)
ERROR_READING_DEVICETYPE                        EQU     (RASBASE+71)
ERROR_READING_DEVICENAME                        EQU     (RASBASE+72)
ERROR_READING_USAGE                             EQU     (RASBASE+73)
ERROR_READING_MAXCONNECTBPS                     EQU     (RASBASE+74)
ERROR_READING_MAXCARRIERBPS                     EQU     (RASBASE+75)
ERROR_LINE_BUSY                                 EQU     (RASBASE+76)
ERROR_VOICE_ANSWER                              EQU     (RASBASE+77)
ERROR_NO_ANSWER                                 EQU     (RASBASE+78)
ERROR_NO_CARRIER                                EQU     (RASBASE+79)
ERROR_NO_DIALTONE                               EQU     (RASBASE+80)
ERROR_IN_COMMAND                                EQU     (RASBASE+81)
ERROR_WRITING_SECTIONNAME                       EQU     (RASBASE+82)
ERROR_WRITING_DEVICETYPE                        EQU     (RASBASE+83)
ERROR_WRITING_DEVICENAME                        EQU     (RASBASE+84)
ERROR_WRITING_MAXCONNECTBPS                     EQU     (RASBASE+85)
ERROR_WRITING_MAXCARRIERBPS                     EQU     (RASBASE+86)
ERROR_WRITING_USAGE                             EQU     (RASBASE+87)
ERROR_WRITING_DEFAULTOFF                        EQU     (RASBASE+88)
ERROR_READING_DEFAULTOFF                        EQU     (RASBASE+89)
ERROR_EMPTY_INI_FILE                            EQU     (RASBASE+90)
ERROR_AUTHENTICATION_FAILURE                    EQU     (RASBASE+91)
ERROR_PORT_OR_DEVICE                            EQU     (RASBASE+92)
ERROR_NOT_BINARY_MACRO                          EQU     (RASBASE+93)
ERROR_DCB_NOT_FOUND                             EQU     (RASBASE+94)
ERROR_STATE_MACHINES_NOT_STARTED                EQU     (RASBASE+95)
ERROR_STATE_MACHINES_ALREADY_STARTED            EQU     (RASBASE+96)
ERROR_PARTIAL_RESPONSE_LOOPING                  EQU     (RASBASE+97)
ERROR_UNKNOWN_RESPONSE_KEY                      EQU     (RASBASE+98)
ERROR_RECV_BUF_FULL                             EQU     (RASBASE+99)
ERROR_CMD_TOO_LONG                              EQU     (RASBASE+100)
ERROR_UNSUPPORTED_BPS                           EQU     (RASBASE+101)
ERROR_UNEXPECTED_RESPONSE                       EQU     (RASBASE+102)
ERROR_INTERACTIVE_MODE                          EQU     (RASBASE+103)
ERROR_BAD_CALLBACK_NUMBER                       EQU     (RASBASE+104)
ERROR_INVALID_AUTH_STATE                        EQU     (RASBASE+105)
ERROR_WRITING_INITBPS                           EQU     (RASBASE+106)
ERROR_X25_DIAGNOSTIC                            EQU     (RASBASE+107)
ERROR_ACCT_EXPIRED                              EQU     (RASBASE+108)
ERROR_CHANGING_PASSWORD                         EQU     (RASBASE+109)
ERROR_OVERRUN                                   EQU     (RASBASE+110)
ERROR_RASMAN_CANNOT_INITIALIZE                  EQU     (RASBASE+111)
ERROR_BIPLEX_PORT_NOT_AVAILABLE                 EQU     (RASBASE+112)
ERROR_NO_ACTIVE_ISDN_LINES                      EQU     (RASBASE+113)
ERROR_NO_ISDN_CHANNELS_AVAILABLE                EQU     (RASBASE+114)
ERROR_TOO_MANY_LINE_ERRORS                      EQU     (RASBASE+115)
ERROR_IP_CONFIGURATION                          EQU     (RASBASE+116)
ERROR_NO_IP_ADDRESSES                           EQU     (RASBASE+117)
ERROR_PPP_TIMEOUT                               EQU     (RASBASE+118)
ERROR_PPP_REMOTE_TERMINATED                     EQU     (RASBASE+119)
ERROR_PPP_NO_PROTOCOLS_CONFIGURED               EQU     (RASBASE+120)
ERROR_PPP_NO_RESPONSE                           EQU     (RASBASE+121)
ERROR_PPP_INVALID_PACKET                        EQU     (RASBASE+122)
ERROR_PHONE_NUMBER_TOO_LONG                     EQU     (RASBASE+123)
ERROR_IPXCP_NO_DIALOUT_CONFIGURED               EQU     (RASBASE+124)
ERROR_IPXCP_NO_DIALIN_CONFIGURED                EQU     (RASBASE+125)
ERROR_IPXCP_DIALOUT_ALREADY_ACTIVE              EQU     (RASBASE+126)
ERROR_ACCESSING_TCPCFGDLL                       EQU     (RASBASE+127)
ERROR_NO_IP_RAS_ADAPTER                         EQU     (RASBASE+128)
ERROR_SLIP_REQUIRES_IP                          EQU     (RASBASE+129)
ERROR_PROJECTION_NOT_COMPLETE                   EQU     (RASBASE+130)
ERROR_PROTOCOL_NOT_CONFIGURED                   EQU     (RASBASE+131)
ERROR_PPP_NOT_CONVERGING                        EQU     (RASBASE+132)
ERROR_PPP_CP_REJECTED                           EQU     (RASBASE+133)
ERROR_PPP_LCP_TERMINATED                        EQU     (RASBASE+134)
ERROR_PPP_REQUIRED_ADDRESS_REJECTED             EQU     (RASBASE+135)
ERROR_PPP_NCP_TERMINATED                        EQU     (RASBASE+136)
ERROR_PPP_LOOPBACK_DETECTED                     EQU     (RASBASE+137)
ERROR_PPP_NO_ADDRESS_ASSIGNED                   EQU     (RASBASE+138)
ERROR_CANNOT_USE_LOGON_CREDENTIALS              EQU     (RASBASE+139)
ERROR_TAPI_CONFIGURATION                        EQU     (RASBASE+140)
ERROR_NO_LOCAL_ENCRYPTION                       EQU     (RASBASE+141)
ERROR_NO_REMOTE_ENCRYPTION                      EQU     (RASBASE+142)
ERROR_REMOTE_REQUIRES_ENCRYPTION                EQU     (RASBASE+143)
ERROR_IPXCP_NET_NUMBER_CONFLICT                 EQU     (RASBASE+144)
ERROR_INVALID_SMM                               EQU     (RASBASE+145)
ERROR_SMM_UNINITIALIZED                         EQU     (RASBASE+146)
ERROR_NO_MAC_FOR_PORT                           EQU     (RASBASE+147)
ERROR_SMM_TIMEOUT                               EQU     (RASBASE+148)
ERROR_BAD_PHONE_NUMBER                          EQU     (RASBASE+149)
ERROR_WRONG_MODULE                              EQU     (RASBASE+150)
ERROR_INVALID_CALLBACK_NUMBER                   EQU     (RASBASE+151)
ERROR_SCRIPT_SYNTAX                             EQU     (RASBASE+152)
RASBASEEND                                      EQU     (RASBASE+152)

;============================= Browse for folders =============================
IFNDEF BIF_RETURNONLYFSDIRS
    BIF_RETURNONLYFSDIRS                        EQU         00000001H
ENDIF

IFNDEF BIF_DONTGOBELOWDOMAIN
    BIF_DONTGOBELOWDOMAIN                       EQU         00000002H
ENDIF

IFNDEF BIF_STATUSTEXT
    BIF_STATUSTEXT                              EQU         00000004H
ENDIF

IFNDEF BIF_RETURNFSANCESTORS
    BIF_RETURNFSANCESTORS                       EQU         00000008H
ENDIF

IFNDEF BIF_EDITBOX
    BIF_EDITBOX                                 EQU         00000010H
ENDIF

IFNDEF BIF_VALIDATE
    BIF_VALIDATE                                EQU         00000020H
ENDIF

IFNDEF BIF_NEWDIALOGSTYLE
    BIF_NEWDIALOGSTYLE                          EQU         00000040H
ENDIF

IFNDEF BIF_BROWSEINCLUDEURLS
    BIF_BROWSEINCLUDEURLS                       EQU         00000080H
ENDIF

IFNDEF BIF_UAHINT
    BIF_UAHINT                                  EQU         00000100H
ENDIF

IFNDEF BIF_NONEWFOLDERBUTTON
    BIF_NONEWFOLDERBUTTON                       EQU         00000200H
ENDIF

IFNDEF BIF_NOTRANSLATETARGETS
    BIF_NOTRANSLATETARGETS                      EQU         00000400H
ENDIF

IFNDEF BIF_BROWSEFORCOMPUTER
    BIF_BROWSEFORCOMPUTER                       EQU         00001000H
ENDIF

IFNDEF BIF_BROWSEFORPRINTER
    BIF_BROWSEFORPRINTER                        EQU         00002000H
ENDIF

IFNDEF BIF_BROWSEINCLUDEFILES
    BIF_BROWSEINCLUDEFILES                      EQU         00004000H
ENDIF

IFNDEF BIF_SHAREABLE
    BIF_SHAREABLE                               EQU         00008000H
ENDIF

IFNDEF BIF_BROWSEFILEJUNCTIONS
    BIF_BROWSEFILEJUNCTIONS                     EQU         00010000H
ENDIF

IFNDEF BIF_USENEWUI
    BIF_USENEWUI                                EQU         (BIF_EDITBOX OR BIF_NEWDIALOGSTYLE)
ENDIF

IFNDEF BFFM_INITIALIZED
    BFFM_INITIALIZED                            EQU         00000001H
ENDIF

IFNDEF BFFM_SELCHANGED
    BFFM_SELCHANGED                             EQU         00000002H
ENDIF

IFNDEF BFFM_VALIDATEFAILEDA
    BFFM_VALIDATEFAILEDA                        EQU         00000003H
ENDIF

IFNDEF BFFM_VALIDATEFAILEDW
    BFFM_VALIDATEFAILEDW                        EQU         00000004H
ENDIF

IFNDEF BFFM_IUNKNOWN
    BFFM_IUNKNOWN                               EQU         00000005H
ENDIF

IFNDEF BFFM_SETSTATUSTEXTA
    BFFM_SETSTATUSTEXTA                         EQU         (WM_USER + 100)
ENDIF

IFNDEF BFFM_ENABLEOK
    BFFM_ENABLEOK                               EQU         (WM_USER + 101)
ENDIF

IFNDEF BFFM_SETSELECTIONA
    BFFM_SETSELECTIONA                          EQU         (WM_USER + 102)
ENDIF

IFNDEF BFFM_SETSELECTIONW
    BFFM_SETSELECTIONW                          EQU         (WM_USER + 103)
ENDIF

IFNDEF BFFM_SETSTATUSTEXTW
    BFFM_SETSTATUSTEXTW                         EQU         (WM_USER + 104)
ENDIF

IFNDEF BFFM_SETOKTEXT
    BFFM_SETOKTEXT                              EQU         (WM_USER + 105)
ENDIF

IFNDEF BFFM_SETEXPANDED
    BFFM_SETEXPANDED                            EQU         (WM_USER + 106)
ENDIF

IFNDEF CSIDL_DESKTOP
    CSIDL_DESKTOP                               EQU         00000H
    CSIDL_INTERNET                              EQU         00001H
    CSIDL_PROGRAMS                              EQU         00002H
    CSIDL_CONTROLS                              EQU         00003H
    CSIDL_PRINTERS                              EQU         00004H
    CSIDL_PERSONAL                              EQU         00005H
    CSIDL_FAVORITES                             EQU         00006H
    CSIDL_STARTUP                               EQU         00007H
    CSIDL_RECENT                                EQU         00008H
    CSIDL_SENDTO                                EQU         00009H
    CSIDL_BITBUCKET                             EQU         0000AH
    CSIDL_STARTMENU                             EQU         0000BH
    CSIDL_MYDOCUMENTS                           EQU         CSIDL_PERSONAL
    CSIDL_MYMUSIC                               EQU         0000DH
    CSIDL_MYVIDEO                               EQU         0000EH
    CSIDL_DESKTOPDIRECTORY                      EQU         00010H
    CSIDL_DRIVES                                EQU         00011H
    CSIDL_NETWORK                               EQU         00012H
    CSIDL_NETHOOD                               EQU         00013H
    CSIDL_FONTS                                 EQU         00014H
    CSIDL_TEMPLATES                             EQU         00015H
    CSIDL_COMMON_STARTMENU                      EQU         00016H
    CSIDL_COMMON_PROGRAMS                       EQU         00017H
    CSIDL_COMMON_STARTUP                        EQU         00018H
    CSIDL_COMMON_DESKTOPDIRECTORY               EQU         00019H
    CSIDL_APPDATA                               EQU         0001AH
    CSIDL_PRINTHOOD                             EQU         0001BH
    CSIDL_LOCAL_APPDATA                         EQU         0001CH
    CSIDL_ALTSTARTUP                            EQU         0001DH
    CSIDL_COMMON_ALTSTARTUP                     EQU         0001EH
    CSIDL_COMMON_FAVORITES                      EQU         0001FH
    CSIDL_INTERNET_CACHE                        EQU         00020H
    CSIDL_COOKIES                               EQU         00021H
    CSIDL_HISTORY                               EQU         00022H
    CSIDL_COMMON_APPDATA                        EQU         00023H
    CSIDL_WINDOWS                               EQU         00024H
    CSIDL_SYSTEM                                EQU         00025H
    CSIDL_PROGRAM_FILES                         EQU         00026H
    CSIDL_MYPICTURES                            EQU         00027H
    CSIDL_PROFILE                               EQU         00028H
    CSIDL_SYSTEMX86                             EQU         00029H
    CSIDL_PROGRAM_FILESX86                      EQU         0002AH
    CSIDL_PROGRAM_FILES_COMMON                  EQU         0002BH
    CSIDL_PROGRAM_FILES_COMMONX86               EQU         0002CH
    CSIDL_COMMON_TEMPLATES                      EQU         0002DH
    CSIDL_COMMON_DOCUMENTS                      EQU         0002EH
    CSIDL_COMMON_ADMINTOOLS                     EQU         0002FH
    CSIDL_ADMINTOOLS                            EQU         00030H
    CSIDL_CONNECTIONS                           EQU         00031H
    CSIDL_COMMON_MUSIC                          EQU         00035H
    CSIDL_COMMON_PICTURES                       EQU         00036H
    CSIDL_COMMON_VIDEO                          EQU         00037H
    CSIDL_RESOURCES                             EQU         00038H
    CSIDL_RESOURCES_LOCALIZED                   EQU         00039H
    CSIDL_COMMON_OEM_LINKS                      EQU         0003AH
    CSIDL_CDBURN_AREA                           EQU         0003BH
    CSIDL_COMPUTERSNEARME                       EQU         0003DH

    CSIDL_FLAG_CREATE                           EQU         08000H
    CSIDL_FLAG_DONT_VERIFY                      EQU         04000H
    CSIDL_FLAG_NO_ALIAS                         EQU         01000H
    CSIDL_FLAG_PER_USER_INIT                    EQU         00800H
    CSIDL_FLAG_MASK                             EQU         0FF00H
ENDIF

;==============================================================================

IFDEF APP_UNICODE
    PSM_SETTITLE EQU <PSM_SETTITLEW>
    PSM_SETFINISHTEXT EQU <PSM_SETFINISHTEXTW>
    PSM_SETHEADERTITLE EQU <PSM_SETHEADERTITLEW>
    PSM_SETHEADERSUBTITLE EQU <PSM_SETHEADERSUBTITLEW>
    IFNDEF BFFM_VALIDATEFAILED
        BFFM_VALIDATEFAILED EQU <BFFM_VALIDATEFAILEDW>
	ENDIF
    IFNDEF BFFM_SETSELECTION
        BFFM_SETSELECTION EQU <BFFM_SETSELECTIONW>
    ENDIF
    IFNDEF BFFM_SETSTATUSTEXT
        BFFM_SETSTATUSTEXT EQU <BFFM_SETSTATUSTEXTW>
    ENDIF
ELSE
    PSM_SETTITLE EQU <PSM_SETTITLEA>
    PSM_SETFINISHTEXT EQU <PSM_SETFINISHTEXTA>
    PSM_SETHEADERTITLE EQU <PSM_SETHEADERTITLEA>
    PSM_SETHEADERSUBTITLE EQU <PSM_SETHEADERSUBTITLEA>
    IFNDEF BFFM_VALIDATEFAILED
        BFFM_VALIDATEFAILED EQU <BFFM_VALIDATEFAILEDA>
	ENDIF
    IFNDEF BFFM_SETSELECTION
        BFFM_SETSELECTION EQU <BFFM_SETSELECTIONA>
    ENDIF
    IFNDEF BFFM_SETSTATUSTEXT
        BFFM_SETSTATUSTEXT EQU <BFFM_SETSTATUSTEXTA>
    ENDIF
ENDIF

;======================================== Structures ======================================;
Unknown STRUCT ALIGNMODE
    QueryInterface  XPTR ?
    AddRef          XPTR ?
    Release         XPTR ?
Unknown ENDS

Dispatch STRUCT ALIGNMODE
    GetTypeInfoCount XPTR ?
    GetTypeInfo      XPTR ?
    GetIDsOfNames    XPTR ?
    _Invoke          XPTR ?
Dispatch ENDS

GUID STRUCT ALIGNMODE
    Data1   DD  ?
    Data2   DW  ?
    Data3   DW  ?
    Data4   DB  8 DUP(?)
GUID ENDS

LARGE_INTEGER UNION ALIGNMODE
    STRUCT
        LowPart  DD ?
        HighPart DD ?
    ENDS
    STRUCT u
        LowPart  DD ?
        HighPart DD ?
    ENDS
    QuadPart     DQ ?
LARGE_INTEGER ENDS

ULARGE_INTEGER UNION ALIGNMODE
    STRUCT
        LowPart  DD ?
        HighPart DD ?
    ENDS
    STRUCT u
        LowPart  DD ?
        HighPart DD ?
    ENDS
    QuadPart     DQ ?
ULARGE_INTEGER ENDS

IFNDEF STRING_DEFINED
	STRING_DEFINED EQU 1
	STRING STRUCT ALIGNMODE
		_Length         DW   ?
		MaximumLength   DW   ?
		Buffer          XPTR ?
	STRING ENDS
    ANSI_STRING                             TYPEDEF STRING
    OEM_STRING                              TYPEDEF STRING
    PSTRING                                 TYPEDEF XPTR
    POEM_STRING                             TYPEDEF PSTRING
ENDIF

IFNDEF UNICODE_STRING_DEFINED
	UNICODE_STRING_DEFINED EQU 1
	UNICODE_STRING STRUCT ALIGNMODE
		_Length         DW   ?
		MaximumLength   DW   ?
                        DD   ?   ;For Align 8
		Buffer          XPTR ?
	UNICODE_STRING      ENDS
    PUNICODE_STRING                         TYPEDEF XPTR
ENDIF

DBGPARAM STRUCT ALIGNMODE
    lpszName    DW  32 DUP(?)
    rglpszZones DW  512 DUP(?)
    ulZoneMask  DD  ?
DBGPARAM ENDS

IF (NTDDI_VERSION GE NTDDI_WIN2K)
    ACTCTXA STRUCT ALIGNMODE
        cbSize                  DD   ?
        dwFlags                 DD   ?
        lpSource                XPTR ?
        wProcessorArchitecture  DW   ?
        wLangId                 LANGID ?
        lpAssemblyDirectory     XPTR ?
        lpResourceName          XPTR ?
        lpApplicationName       XPTR ?
        hModule                 HMODULE ?
    ACTCTXA ENDS

    ACTCTXW STRUCT ALIGNMODE
        cbSize                  DD   ?
        dwFlags                 DD   ?
        lpSource                XPTR ?
        wProcessorArchitecture  DW   ?
        wLangId                 LANGID ?
        lpAssemblyDirectory     XPTR ?
        lpResourceName          XPTR ?
        lpApplicationName       XPTR ?
        hModule                 HMODULE ?
    ACTCTXW ENDS

    ACTCTX_SECTION_KEYED_DATA_2600 STRUCT ALIGNMODE
        cbSize                      DD   ?
        ulDataFormatVersion         DD   ?
        lpData                      XPTR ?
        ulLength                    DD   ?
        lpSectionGlobalData         XPTR ?
        ulSectionGlobalDataLength   DD   ?
        lpSectionBase               XPTR ?
        ulSectionTotalLength        DD   ?
        hActCtx                     HANDLE ?
        ulAssemblyRosterIndex       DD   ?
    ACTCTX_SECTION_KEYED_DATA_2600 ENDS

    ACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA STRUCT ALIGNMODE
        lpInformation             XPTR ?
        lpSectionBase             XPTR ?
        ulSectionLength           DD   ?
        lpSectionGlobalDataBase   XPTR ?
        ulSectionGlobalDataLength DD   ?
    ACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA ENDS

    ACTCTX_SECTION_KEYED_DATA STRUCT ALIGNMODE
        cbSize                      DD   ?
        ulDataFormatVersion         DD   ?
        lpData                      XPTR ?
        ulLength                    DD   ?
        lpSectionGlobalData         XPTR ?
        ulSectionGlobalDataLength   DD   ?
        lpSectionBase               XPTR ?
        ulSectionTotalLength        DD   ?
        hActCtx                     HANDLE ?
        ulAssemblyRosterIndex       DD   ?
        ulFlags                     DD   ?
        AssemblyMetadata            ACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA <>
    ACTCTX_SECTION_KEYED_DATA ENDS

    ACTIVATION_CONTEXT_BASIC_INFORMATION STRUCT ALIGNMODE
       hActCtx HANDLE ?
       dwFlags DD  ?
    ACTIVATION_CONTEXT_BASIC_INFORMATION ENDS

    IFDEF APP_UNICODE
        ACTCTX EQU <ACTCTXW>
    ELSE
        ACTCTX EQU <ACTCTXA>
    ENDIF
ENDIF

IF (NTDDI_VERSION GE NTDDI_WINXP)
    FILE_BASIC_INFO STRUCT ALIGNMODE
        CreationTime    LARGE_INTEGER <>
        LastAccessTime  LARGE_INTEGER <>
        LastWriteTime   LARGE_INTEGER <>
        ChangeTime      LARGE_INTEGER <>
        FileAttributes  DD            ?
    FILE_BASIC_INFO ENDS

    FILE_STANDARD_INFO STRUCT ALIGNMODE
        AllocationSize  LARGE_INTEGER <>
        EndOfFile       LARGE_INTEGER <>
        NumberOfLinks   DD      ?
        DeletePending   BOOL    ?
        Directory       BOOL    ?
    FILE_STANDARD_INFO ENDS

    FILE_NAME_INFO STRUCT ALIGNMODE
        FileNameLength  DD      ?
        FileName        WCHAR   ?
    FILE_NAME_INFO ENDS

    FILE_RENAME_INFO STRUCT ALIGNMODE
        ReplaceIfExists BOOL    ?
        RootDirectory   HANDLE  ?
        FileNameLength  DD      ?
        FileName        WCHAR   ?
    FILE_RENAME_INFO ENDS

    FILE_ALLOCATION_INFO STRUCT ALIGNMODE
        AllocationSize  LARGE_INTEGER <>
    FILE_ALLOCATION_INFO ENDS

    FILE_END_OF_FILE_INFO STRUCT ALIGNMODE
        EndOfFile   LARGE_INTEGER <>
    FILE_END_OF_FILE_INFO ENDS

    FILE_STREAM_INFO STRUCT ALIGNMODE
        NextEntryOffset      DD     ?
        StreamNameLength     DD     ?
        StreamSize           LARGE_INTEGER <>
        StreamAllocationSize LARGE_INTEGER <>
        StreamName           WCHAR  ?
    FILE_STREAM_INFO ENDS

    FILE_COMPRESSION_INFO STRUCT ALIGNMODE
        CompressedFileSize   LARGE_INTEGER <>
        CompressionFormat    DW     ?
        CompressionUnitShift CHAR   ?
        ChunkShift           CHAR   ?
        ClusterShift         CHAR   ?
        Reserved             CHAR   3 DUP(?)
    FILE_COMPRESSION_INFO ENDS

    FILE_ATTRIBUTE_TAG_INFO STRUCT ALIGNMODE
        FileAttributes  DD  ?
        ReparseTag      DD  ?
    FILE_ATTRIBUTE_TAG_INFO ENDS

    FILE_DISPOSITION_INFO STRUCT ALIGNMODE
        DeleteFile  BOOL ?
    FILE_DISPOSITION_INFO ENDS

    FILE_ID_BOTH_DIR_INFO STRUCT ALIGNMODE
        NextEntryOffset DD      ?
        FileIndex       DD      ?
        CreationTime    LARGE_INTEGER <>
        LastAccessTime  LARGE_INTEGER <>
        LastWriteTime   LARGE_INTEGER <>
        ChangeTime      LARGE_INTEGER <>
        EndOfFile       LARGE_INTEGER <>
        AllocationSize  LARGE_INTEGER <>
        FileAttributes  DD      ?
        FileNameLength  DD      ?
        EaSize          DD      ?
        ShortNameLength CHAR    ?
        ShortName       WCHAR   12 DUP(?)
        FileId          LARGE_INTEGER <>
        FileName        WCHAR   ?
    FILE_ID_BOTH_DIR_INFO ENDS

    FILE_FULL_DIR_INFO STRUCT ALIGNMODE
        NextEntryOffset DD  ?
        FileIndex       DD  ?
        CreationTime    LARGE_INTEGER <>
        LastAccessTime  LARGE_INTEGER <>
        LastWriteTime   LARGE_INTEGER <>
        ChangeTime      LARGE_INTEGER <>
        EndOfFile       LARGE_INTEGER <>
        AllocationSize  LARGE_INTEGER <>
        FileAttributes  DD  ?
        FileNameLength  DD  ?
        EaSize          DD  ?
        FileName        DW  1 DUP(?)
    FILE_FULL_DIR_INFO ENDS

    FILE_IO_PRIORITY_HINT_INFO STRUCT ALIGNMODE
        PriorityHint    DD  ?
    FILE_IO_PRIORITY_HINT_INFO ENDS

    FILE_ID_128 STRUCT ALIGNMODE
        Identifier  DB 16 DUP(?)
    FILE_ID_128 ENDS

    FILE_ID_DESCRIPTOR STRUCT ALIGNMODE
        dwSize      DD   ?
        _Type       ENUM ?
        UNION u
            FileId  LARGE_INTEGER <>
            IF (NTDDI_VERSION GE NTDDI_VISTA)
                ObjectId    GUID <>
                IF (NTDDI_VERSION GE NTDDI_WIN8)
                    ExtendedFileId FILE_ID_128 <>
                ENDIF
            ENDIF
        ENDS
    FILE_ID_DESCRIPTOR ENDS

    WIN32_FIND_STREAM_DATA STRUCT ALIGNMODE
        StreamSize  LARGE_INTEGER <>
        cStreamName DW  (MAX_PATH + 36) DUP(?)
    WIN32_FIND_STREAM_DATA ENDS

    STARTUPINFOA STRUCT ALIGNMODE
        cb              DD     ?
        lpReserved      XPTR   ?
        lpDesktop       XPTR   ?
        lpTitle         XPTR   ?
        dwX             DD     ?
        dwY             DD     ?
        dwXSize         DD     ?
        dwYSize         DD     ?
        dwXCountChars   DD     ?
        dwYCountChars   DD     ?
        dwFillAttribute DD     ?
        dwFlags         DD     ?
        wShowWindow     DW     ?
        cbReserved2     DW     ?
        lpReserved2     XPTR   ?
        hStdInput       HANDLE ?
        hStdOutput      HANDLE ?
        hStdError       HANDLE ?
    STARTUPINFOA ENDS

    STARTUPINFOW STRUCT ALIGNMODE
        cb              DD     ?
        lpReserved      XPTR   ?
        lpDesktop       XPTR   ?
        lpTitle         XPTR   ?
        dwX             DD     ?
        dwY             DD     ?
        dwXSize         DD     ?
        dwYSize         DD     ?
        dwXCountChars   DD     ?
        dwYCountChars   DD     ?
        dwFillAttribute DD     ?
        dwFlags         DD     ?
        wShowWindow     DW     ?
        cbReserved2     DW     ?
        lpReserved2     XPTR   ?
        hStdInput       HANDLE ?
        hStdOutput      HANDLE ?
        hStdError       HANDLE ?
    STARTUPINFOW ENDS

    IFDEF APP_UNICODE
        STARTUPINFO EQU <STARTUPINFOW>
    ELSE
        STARTUPINFO EQU <STARTUPINFOA>
    ENDIF
ENDIF

IF (NTDDI_VERSION GE NTDDI_VISTA)
    STARTUPINFOEXA STRUCT ALIGNMODE
        StartupInfo     STARTUPINFOA <>
        lpAttributeList XPTR    ?
    STARTUPINFOEXA ENDS

    STARTUPINFOEXW STRUCT ALIGNMODE
        StartupInfo     STARTUPINFOW <>
        lpAttributeList XPTR    ?
    STARTUPINFOEXW ENDS

    IFDEF APP_UNICODE
        STARTUPINFOEX EQU <STARTUPINFOEXW>
    ELSE
        STARTUPINFOEX EQU <STARTUPINFOEXA>
    ENDIF

    FILE_REMOTE_PROTOCOL_INFO STRUCT ALIGNMODE
        StructureVersion     DW ?
        StructureSize        DW ?
        Protocol             DD ?
        ProtocolMajorVersion DW ?
        ProtocolMinorVersion DW ?
        ProtocolRevision     DW ?
        Reserved             DW 8 DUP(?)
        Flags                DD ?
        STRUCT GenericReserved
            Reserved         DD 8 DUP(?)
        ENDS
        IF (NTDDI_VERSION LT NTDDI_WIN8)
            STRUCT ProtocolSpecificReserved
                Reserved     DD 16 DUP(?)
            ENDS
        ELSE
            UNION ProtocolSpecific
                STRUCT Smb2
                    STRUCT Server
                        Capabilities DD ?
                    ENDS
                    STRUCT Share
                        Capabilities DD ?
                        CachingFlags DD ?
                    ENDS
                ENDS
                Reserved     DD 16 DUP(?)
            ENDS
        ENDIF 
    FILE_REMOTE_PROTOCOL_INFO ENDS
ENDIF

IF (NTDDI_VERSION GE NTDDI_WIN7)
    UMS_SCHEDULER_STARTUP_INFO STRUCT ALIGNMODE
       UmsVersion      DD   ?
       CompletionList  XPTR ?
       SchedulerProc   XPTR ?
       SchedulerParam  XPTR ?
    UMS_SCHEDULER_STARTUP_INFO ENDS

    UMS_SYSTEM_THREAD_INFORMATION STRUCT ALIGNMODE
        UmsVersion               ULONG ?
        STRUCT
            IsUmsSchedulerThread ULONG ?
            IsUmsWorkerThread    ULONG ?
        ENDS
    UMS_SYSTEM_THREAD_INFORMATION ENDS

    COPYFILE2_MESSAGE STRUCT ALIGNMODE
        _type       DD  ?
        dwPadding   DD  ?
        UNION Info
            STRUCT ChunkStarted
                dwStreamNumber   DD ?
                dwReserved       DD ?
                hSourceFile      HANDLE ?
                hDestinationFile HANDLE ?
                uliChunkNumber   ULARGE_INTEGER <>
                uliChunkSize     ULARGE_INTEGER <>
                uliStreamSize    ULARGE_INTEGER <>
                uliTotalFileSize ULARGE_INTEGER <>
            ENDS
            STRUCT ChunkFinished
                dwStreamNumber            DD     ?
                dwFlags                   DD     ?
                hSourceFile               HANDLE ?
                hDestinationFile          HANDLE ?
                uliChunkNumber            ULARGE_INTEGER <>
                uliChunkSize              ULARGE_INTEGER <>
                uliStreamSize             ULARGE_INTEGER <>
                uliStreamBytesTransferred ULARGE_INTEGER <>
                uliTotalFileSize          ULARGE_INTEGER <>
                uliTotalBytesTransferred  ULARGE_INTEGER <>
            ENDS
           STRUCT StreamStarted
                dwStreamNumber      DD     ?
                dwReserved          DD     ?
                hSourceFile         HANDLE ?
                hDestinationFile    HANDLE ?
                uliStreamSize       ULARGE_INTEGER <>
                uliTotalFileSize    ULARGE_INTEGER <>
            ENDS
            STRUCT StreamFinished
                dwStreamNumber            DD     ?
                dwReserved                DD     ?
                hSourceFile               HANDLE ?
                hDestinationFile          HANDLE ?
                uliStreamSize             ULARGE_INTEGER <>
                uliStreamBytesTransferred ULARGE_INTEGER <>
                uliTotalFileSize          ULARGE_INTEGER <>
                uliTotalBytesTransferred  ULARGE_INTEGER <>
            ENDS
            STRUCT PollContinue
                dwReserved  DD  ?
            ENDS
            STRUCT Error
                CopyPhase                   DD  ?
                dwStreamNumber              DD  ?
                hrFailure                   HRESULT ?
                dwReserved                  DD  ?
                uliChunkNumber              ULARGE_INTEGER <>
                uliStreamSize               ULARGE_INTEGER <>
                uliStreamBytesTransferred   ULARGE_INTEGER <>
                uliTotalFileSize            ULARGE_INTEGER <>
                uliTotalBytesTransferred    ULARGE_INTEGER <>
            ENDS
        ENDS
    COPYFILE2_MESSAGE ENDS

    COPYFILE2_EXTENDED_PARAMETERS STRUCT ALIGNMODE
        dwSize              DD   ?
        dwCopyFlags         DD   ?
        pfCancel            XPTR ?
        pProgressRoutine    XPTR ?
        pvCallbackContext   XPTR ?
    COPYFILE2_EXTENDED_PARAMETERS ENDS
ENDIF

IF (NTDDI_VERSION GE NTDDI_WIN8)
    FILE_ALIGNMENT_INFO STRUCT ALIGNMODE
        AlignmentRequirement DWORD ?
    FILE_ALIGNMENT_INFO ENDS

    FILE_STORAGE_INFO STRUCT ALIGNMODE
        LogicalBytesPerSector                DD  ?
        PhysicalBytesPerSectorForAtomicity   DD  ?
        PhysicalBytesPerSectorForPerformance DD  ?
        FileSystemEffectivePhysicalBytesPerSectorForAtomicity DD ?
        Flags                                DD  ?
        ByteOffsetForSectorAlignment         DD  ?
        ByteOffsetForPartitionAlignment      DD  ?
    FILE_STORAGE_INFO ENDS

    FILE_ID_INFO STRUCT ALIGNMODE
        VolumeSerialNumber  DQ  ?
        FileId              FILE_ID_128 <>
    FILE_ID_INFO ENDS

    FILE_ID_EXTD_DIR_INFO STRUCT ALIGNMODE
        NextEntryOffset     DD  ?
        FileIndex           DD  ?
        CreationTime        LARGE_INTEGER <> 
        LastAccessTime      LARGE_INTEGER <> 
        LastWriteTime       LARGE_INTEGER <> 
        ChangeTime          LARGE_INTEGER <> 
        EndOfFile           LARGE_INTEGER <> 
        AllocationSize      LARGE_INTEGER <> 
        FileAttributes      DD  ?
        FileNameLength      DD  ?
        EaSize              DD  ?
        ReparsePointTag     DD  ?
        FileId              FILE_ID_128 <>
        FileName            DW  1 DUP(?)
    FILE_ID_EXTD_DIR_INFO ENDS

    OPERATION_START_PARAMETERS STRUCT ALIGNMODE
        Version     DD  ?
        OperationId DD  ?
        Flags       DD  ?
    OPERATION_START_PARAMETERS ENDS

    OPERATION_END_PARAMETERS STRUCT ALIGNMODE
        Version     DD  ?
        OperationId DD  ?
        Flags       DD  ?
    OPERATION_END_PARAMETERS ENDS
ENDIF

CPINFO STRUCT ALIGNMODE
    MaxCharSize DD  ?
    DefaultChar DB  MAX_DEFAULTCHAR DUP(?)
    LeadByte    DB  MAX_LEADBYTES DUP(?)
CPINFO ENDS

CPINFOEXA STRUCT ALIGNMODE
    MaxCharSize         DD  ?
    DefaultChar         DB  MAX_DEFAULTCHAR DUP(?)
    LeadByte            DB  MAX_LEADBYTES DUP(?)
    UnicodeDefaultChar  DW  ?
    CodePage            DD  ?
    CodePageName        DB  MAX_PATH DUP(?)
CPINFOEXA ENDS

CPINFOEXW STRUCT ALIGNMODE
    MaxCharSize         DD  ?
    DefaultChar         DB  MAX_DEFAULTCHAR DUP(?)
    LeadByte            DB  MAX_LEADBYTES DUP(?)
    UnicodeDefaultChar  DW  ?
    CodePage            DD  ?
    CodePageName        DW  MAX_PATH DUP(?)
CPINFOEXW ENDS

NUMBERFMTA STRUCT ALIGNMODE
    NumDigits       DD   ?
    LeadingZero     DD   ?
    Grouping        DD   ?
    lpDecimalSep    XPTR ?
    lpThousandSep   XPTR ?
    NegativeOrder   DD   ?
NUMBERFMTA ENDS

NUMBERFMTW STRUCT ALIGNMODE
    NumDigits       DD   ?
    LeadingZero     DD   ?
    Grouping        DD   ?
    lpDecimalSep    XPTR ?
    lpThousandSep   XPTR ?
    NegativeOrder   DD   ?
NUMBERFMTW ENDS

CURRENCYFMTA STRUCT ALIGNMODE
    NumDigits        DD   ?
    LeadingZero      DD   ?
    Grouping         DD   ?
    lpDecimalSep     XPTR ?
    lpThousandSep    XPTR ?
    NegativeOrder    DD   ?
    PositiveOrder    DD   ?
    lpCurrencySymbol XPTR ?
CURRENCYFMTA ENDS

CURRENCYFMTW STRUCT ALIGNMODE
    NumDigits        DD   ?
    LeadingZero      DD   ?
    Grouping         DD   ?
    lpDecimalSep     XPTR ?
    lpThousandSep    XPTR ?
    NegativeOrder    DD   ?
    PositiveOrder    DD   ?
    lpCurrencySymbol XPTR ?
CURRENCYFMTW ENDS

NLSVERSIONINFO STRUCT ALIGNMODE
    dwNLSVersionInfoSize    DD   ?
    dwNLSVersion            DD   ?
    dwDefinedVersion        DD   ?
    IF (NTDDI_VERSION GE NTDDI_WIN8)
        dwEffectiveId       DD   ?
        guidCustomVersion   GUID <>
    ENDIF
NLSVERSIONINFO ENDS

NLSVERSIONINFOEX STRUCT ALIGNMODE
    dwNLSVersionInfoSize    DD   ?
    dwNLSVersion            DD   ?
    dwDefinedVersion        DD   ?
    dwEffectiveId           DD   ?
    guidCustomVersion       GUID <>
NLSVERSIONINFOEX ENDS

FILEMUIINFO STRUCT ALIGNMODE
    dwSize               DD ?
    dwVersion            DD ?
    dwFileType           DD ?
    pChecksum            DB 16 DUP(?)
    pServiceChecksum     DB 16 DUP(?)
    dwLanguageNameOffset DD ?
    dwTypeIDMainSize     DD ?
    dwTypeIDMainOffset   DD ?
    dwTypeNameMainOffset DD ?
    dwTypeIDMUISize      DD ?
    dwTypeIDMUIOffset    DD ?
    dwTypeNameMUIOffset  DD ?
    abBuffer             DB 8 DUP(?)
FILEMUIINFO ENDS

OVERLAPPED STRUCT ALIGNMODE
    Internal     XPTR ?
    InternalHigh XPTR ?
    UNION u
        STRUCT s
            _Offset     DD  ?
            OffsetHigh  DD  ?
        ENDS
        Pointer  XPTR ?
    ENDS
    hEvent       HANDLE ?
OVERLAPPED ENDS

OVERLAPPED_ENTRY STRUCT ALIGNMODE
    lpCompletionKey XPTR ?
    lpOverlapped    XPTR ?
    Internal        XPTR ?
    dwNumberOfBytesTransferred DD   ?
OVERLAPPED_ENTRY ENDS

SECURITY_ATTRIBUTES STRUCT ALIGNMODE
    nLength              DD   ?
    lpSecurityDescriptor XPTR ?
    bInheritHandle       DD   ?
SECURITY_ATTRIBUTES ENDS

PROCESS_INFORMATION STRUCT ALIGNMODE
    hProcess        HANDLE ?
    hThread         HANDLE ?
    dwProcessId     DD  ?
    dwThreadId      DD  ?
PROCESS_INFORMATION ENDS

FILETIME STRUCT ALIGNMODE
    dwLowDateTime   DD  ?
    dwHighDateTime  DD  ?
FILETIME ENDS

SYSTEMTIME STRUCT ALIGNMODE
    wYear           DW  ?
    wMonth          DW  ?
    wDayOfWeek      DW  ?
    wDay            DW  ?
    wHour           DW  ?
    wMinute         DW  ?
    wSecond         DW  ?
    wMilliseconds   DW  ?
SYSTEMTIME ENDS

COMMPROP STRUCT ALIGNMODE
    wPacketLength       DW  ?
    wPacketVersion      DW  ?
    dwServiceMask       DD  ?
    dwReserved1         DD  ?
    dwMaxTxQueue        DD  ?
    dwMaxRxQueue        DD  ?
    dwMaxBaud           DD  ?
    dwProvSubType       DD  ?
    dwProvCapabilities  DD  ?
    dwSettableParams    DD  ?
    dwSettableBaud      DD  ?
    wSettableData       DW  ?
    wSettableStopParity DW  ?
    dwCurrentTxQueue    DD  ?
    dwCurrentRxQueue    DD  ?
    dwProvSpec1         DD  ?
    dwProvSpec2         DD  ?
    wcProvChar          DW  ?
COMMPROP ENDS

COMSTAT STRUCT ALIGNMODE
    fCtsHold    DD  ?
    fDsrHold    DD  ?
    fRlsdHold   DD  ?
    fXoffHold   DD  ?
    fXoffSent   DD  ?
    fEof        DD  ?
    fTxim       DD  ?
    fReserved   DD  ?
    cbInQue     DD  ?
    cbOutQue    DD  ?
COMSTAT ENDS

DCB STRUCT ALIGNMODE
    DCBlength   DD     ?
    BaudRate    DD     ?
    fbits       DD     ?
    wReserved   DW     ?
    XonLim      DW     ?
    XoffLim     DW     ?
    ByteSize    DB     ?
    Parity      DB     ?
    StopBits    DB     ?
    XonChar     DB     ?
    XoffChar    DB     ?
    ErrorChar   DB     ?
    EofChar     DB     ?
    EvtChar     DB     ?
    wReserved1  DW     ?
DCB ENDS

COMMTIMEOUTS STRUCT ALIGNMODE
    ReadIntervalTimeout         DD  ?
    ReadTotalTimeoutMultiplier  DD  ?
    ReadTotalTimeoutConstant    DD  ?
    WriteTotalTimeoutMultiplier DD  ?
    WriteTotalTimeoutConstant   DD  ?
COMMTIMEOUTS ENDS

COMMCONFIG STRUCT ALIGNMODE
    dwSize              DD  ?
    wVersion            DW  ?
    wReserved           DW  ?
    dcb                 DCB <>
    dwProviderSubType   DD  ?
    dwProviderOffset    DD  ?
    dwProviderSize      DD  ?
    wcProviderData      DW  ?
COMMCONFIG ENDS

SYSTEM_INFO STRUCT ALIGNMODE
    wProcessorArchitecture          DW   ?
    wReserved                       DW   ?
    dwPageSize                      DD   ?
    lpMinimumApplicationAddress     XPTR ?
    lpMaximumApplicationAddress     XPTR ?
    dwActiveProcessorMask           XPTR ?
    dwNumberOfProcessors            DD   ?
    dwProcessorType                 DD   ?
    dwAllocationGranularity         DD   ?
    wProcessorLevel                 DW   ?
    wProcessorRevision              DW   ?
SYSTEM_INFO ENDS

MEMORYSTATUS STRUCT ALIGNMODE
    dwLength        DD  ?
    dwMemoryLoad    DD  ?
    dwTotalPhys     SIZE_T ?
    dwAvailPhys     SIZE_T ?
    dwTotalPageFile SIZE_T ?
    dwAvailPageFile SIZE_T ?
    dwTotalVirtual  SIZE_T ?
    dwAvailVirtual  SIZE_T ?
MEMORYSTATUS ENDS

EXCEPTION_RECORD STRUCT ALIGNMODE
    ExceptionCode        DD    ?
    ExceptionFlags       DD    ?
    ExceptionRecord      XPTR  ?
    ExceptionAddress     PVOID ?
    NumberParameters     DD    ?
    ExceptionInformation XPTR  EXCEPTION_MAXIMUM_PARAMETERS DUP(?)
EXCEPTION_RECORD ENDS
PEXCEPTION_RECORD                               TYPEDEF XPTR 

EXCEPTION_DEBUG_INFO STRUCT ALIGNMODE
    ExceptionRecord EXCEPTION_RECORD <>
    dwFirstChance   DD  ?
EXCEPTION_DEBUG_INFO ENDS

CREATE_THREAD_DEBUG_INFO STRUCT ALIGNMODE
    hThread             HANDLE ?
    lpThreadLocalBase   XPTR   ?
    lpStartAddress      XPTR   ?
CREATE_THREAD_DEBUG_INFO ENDS

CREATE_PROCESS_DEBUG_INFO STRUCT ALIGNMODE
    hFile                   HANDLE ?
    hProcess                HANDLE ?
    hThread                 HANDLE ?
    lpBaseOfImage           XPTR ?
    dwDebugInfoFileOffset   DD   ?
    nDebugInfoSize          DD   ?
    lpThreadLocalBase       XPTR ?
    lpStartAddress          XPTR ?
    lpImageName             XPTR ?
    fUnicode                DW   ?
CREATE_PROCESS_DEBUG_INFO ENDS

EXIT_THREAD_DEBUG_INFO STRUCT ALIGNMODE
    dwExitCode  DD  ?
EXIT_THREAD_DEBUG_INFO ENDS

EXIT_PROCESS_DEBUG_INFO STRUCT ALIGNMODE
    dwExitCode  DD  ?
EXIT_PROCESS_DEBUG_INFO ENDS

LOAD_DLL_DEBUG_INFO STRUCT ALIGNMODE
    hFile                   HANDLE ?
    lpBaseOfDll             XPTR ?
    dwDebugInfoFileOffset   DD   ?
    nDebugInfoSize          DD   ?
    lpImageName             XPTR ?
    fUnicode                DW   ?
LOAD_DLL_DEBUG_INFO ENDS

UNLOAD_DLL_DEBUG_INFO STRUCT ALIGNMODE
    lpBaseOfDll XPTR ?
UNLOAD_DLL_DEBUG_INFO ENDS

OUTPUT_DEBUG_STRING_INFO STRUCT ALIGNMODE
    lpDebugStringData   XPTR ?
    fUnicode            DW   ?
    nDebugStringLength  DW   ?
OUTPUT_DEBUG_STRING_INFO ENDS

RIP_INFO STRUCT ALIGNMODE
    dwError     DD  ?
    dwType      DD  ?
RIP_INFO ENDS

DEBUGSTRUCT UNION
  Exception         EXCEPTION_DEBUG_INFO <{?,?,?,?,?,EXCEPTION_MAXIMUM_PARAMETERS dup(?)},?>
  CreateThread      CREATE_THREAD_DEBUG_INFO <?,?,?>
  CreateProcessInfo CREATE_PROCESS_DEBUG_INFO <?,?,?,?,?,?,?,?,?,?>
  ExitThread        EXIT_THREAD_DEBUG_INFO <?>
  ExitProcess       EXIT_PROCESS_DEBUG_INFO <?>
  LoadDll           LOAD_DLL_DEBUG_INFO <?,?,?,?,?,?>
  UnloadDll         UNLOAD_DLL_DEBUG_INFO <?>
  DebugString       OUTPUT_DEBUG_STRING_INFO <?,?,?>
  RipInfo           RIP_INFO <?,?>
DEBUGSTRUCT ENDS

DEBUG_EVENT STRUCT ALIGNMODE
    dwDebugEventCode    DD  ?
    dwProcessId         DD  ?
    dwThreadId          DD  ?
    u                   DEBUGSTRUCT <>
DEBUG_EVENT ENDS

OFS_MAXPATHNAME                                 EQU     128

OFSTRUCT STRUCT ALIGNMODE
    cBytes      DB  ?
    fFixedDisk  DB  ?
    nErrCode    DW  ?
    Reserved1   DW  ?
    Reserved2   DW  ?
    szPathName  DB  OFS_MAXPATHNAME DUP(?)
OFSTRUCT ENDS

MEMORYSTATUSEX STRUCT ALIGNMODE
    dwLength                DD  ?
    dwMemoryLoad            DD  ?
    ullTotalPhys            DQ  ?
    ullAvailPhys            DQ  ?
    ullTotalPageFile        DQ  ?
    ullAvailPageFile        DQ  ?
    ullTotalVirtual         DQ  ?
    ullAvailVirtual         DQ  ?
    ullAvailExtendedVirtual DQ  ?
MEMORYSTATUSEX ENDS

PROCESS_HEAP_ENTRY STRUCT ALIGNMODE
    lpData          XPTR ?
    cbData          DD   ?
    cbOverhead      DB   ?
    iRegionIndex    DB   ?
    wFlags          DW   ?
    UNION u
        STRUCT Block
            hMem        DD  ?
            dwReserved  DD  3 DUP(?)
        ENDS
        STRUCT Region
            dwCommittedSize     DD   ?
            dwUnCommittedSize   DD   ?
            lpFirstBlock        XPTR ?
            lpLastBlock         XPTR ?
        ENDS
    ENDS
PROCESS_HEAP_ENTRY ENDS

BY_HANDLE_FILE_INFORMATION STRUCT ALIGNMODE
    dwFileAttributes        DD  ?
    ftCreationTime          FILETIME <>
    ftLastAccessTime        FILETIME <>
    ftLastWriteTime         FILETIME <>
    dwVolumeSerialNumber    DD  ?
    nFileSizeHigh           DD  ?
    nFileSizeLow            DD  ?
    nNumberOfLinks          DD  ?
    nFileIndexHigh          DD  ?
    nFileIndexLow           DD  ?
BY_HANDLE_FILE_INFORMATION ENDS

TIME_ZONE_INFORMATION STRUCT ALIGNMODE
    Bias            DD  ?
    StandardName    DW  32 DUP(?)
    StandardDate    SYSTEMTIME <>
    StandardBias    DD  ?
    DaylightName    DW  32 DUP(?)
    DaylightDate    SYSTEMTIME <>
    DaylightBias    DD  ?
TIME_ZONE_INFORMATION ENDS

DYNAMIC_TIME_ZONE_INFORMATION STRUCT ALIGNMODE
    Bias            DD  ?
    StandardName    DW  32 DUP(?)
    StandardDate    SYSTEMTIME <> 
    StandardBias    DD  ?
    DaylightName    DW  32 DUP(?)
    DaylightDate    SYSTEMTIME <> 
    DaylightBias    DD  ?
    TimeZoneKeyName DW  128 DUP(?)
    DynamicDaylightTimeDisabled DB  ?
DYNAMIC_TIME_ZONE_INFORMATION ENDS

WIN32_STREAM_ID STRUCT ALIGNMODE
    dwStreamId          DD  ?
    dwStreamAttributes  DD  ?
    _Size               LARGE_INTEGER <>
    dwStreamNameSize    DD  ?
    cStreamName         DW  ANYSIZE_ARRAY DUP(?)
WIN32_STREAM_ID ENDS

IFNDEF BROWSEINFO
    BROWSEINFOA STRUCT ALIGNMODE
        hwndOwner      HWND    ?
        pidlRoot       XWORD   ?
        pszDisplayName LPTSTR  ?
        lpszTitle      LPCTSTR ?
        ulFlags        DD      ?
        lpfn           XPTR    ?
        lParam         LPARAM  ?
        iImage         DD      ?
    BROWSEINFOA ENDS

    BROWSEINFOW STRUCT ALIGNMODE
        hwndOwner      HWND    ?
        pidlRoot       XWORD   ?
        pszDisplayName LPTSTR  ?
        lpszTitle      LPCTSTR ?
        ulFlags        DD      ?
        lpfn           XPTR    ?
        lParam         LPARAM  ?
        iImage         DD      ?
    BROWSEINFOW ENDS
ENDIF

WIN32_FIND_DATAA STRUCT ALIGNMODE
    dwFileAttributes   DD  ?
    ftCreationTime     FILETIME <>
    ftLastAccessTime   FILETIME <>
    ftLastWriteTime    FILETIME <>
    nFileSizeHigh      DD  ?
    nFileSizeLow       DD  ?
    dwReserved0        DD  ?
    dwReserved1        DD  ?
    cFileName          DB  MAX_PATH DUP(?)
    cAlternateFileName DB  14 DUP(?)
WIN32_FIND_DATAA ENDS

WIN32_FIND_DATAW STRUCT ALIGNMODE
    dwFileAttributes   DD  ?
    ftCreationTime     FILETIME <>
    ftLastAccessTime   FILETIME <>
    ftLastWriteTime    FILETIME <>
    nFileSizeHigh      DD  ?
    nFileSizeLow       DD  ?
    dwReserved0        DD  ?
    dwReserved1        DD  ?
    cFileName          WCHAR MAX_PATH DUP(?)
    cAlternateFileName WCHAR 14 DUP(?)
WIN32_FIND_DATAW ENDS

WIN32_FILE_ATTRIBUTE_DATA STRUCT ALIGNMODE
    dwFileAttributes    DD  ?
    ftCreationTime      FILETIME <>
    ftLastAccessTime    FILETIME <>
    ftLastWriteTime     FILETIME <>
    nFileSizeHigh       DD  ?
    nFileSizeLow        DD  ?
WIN32_FILE_ATTRIBUTE_DATA ENDS

HW_PROFILE_INFOA STRUCT ALIGNMODE
    dwDockInfo         DD  ?
    szHwProfileGuid    CHAR HW_PROFILE_GUIDLEN DUP(?)
    szHwProfileName    CHAR MAX_PROFILE_LEN DUP(?)
HW_PROFILE_INFOA ENDS

HW_PROFILE_INFOW STRUCT ALIGNMODE
    dwDockInfo         DD  ?
    szHwProfileGuid    WCHAR HW_PROFILE_GUIDLEN DUP(?)
    szHwProfileName    WCHAR MAX_PROFILE_LEN DUP(?)
HW_PROFILE_INFOW ENDS

SYSTEM_POWER_STATUS STRUCT ALIGNMODE
    ACLineStatus        DB  ?
    BatteryFlag         DB  ?
    BatteryLifePercent  DB  ?
    Reserved1           DB  ?
    BatteryLifeTime     DD  ?
    BatteryFullLifeTime DD  ?
SYSTEM_POWER_STATUS ENDS

ENUMUILANG STRUCT ALIGNMODE
    NumOfEnumUILang     DD   ?
    SizeOfEnumUIBuffer  DD   ?
    pEnumUIBuffer       XPTR ?
ENUMUILANG ENDS

REASON_CONTEXT STRUCT ALIGNMODE
    Version     DD     ?
    Flags       DD     ?
    UNION Reason
        STRUCT Detailed
            LocalizedReasonModule HMODULE ?
            LocalizedReasonId     DD   ?
            ReasonStringCount     DD   ?
            ReasonStrings         XPTR ?
        ENDS
        SimpleReasonString        XPTR ?
    ENDS
REASON_CONTEXT ENDS
POWER_REQUEST_CONTEXT                           TYPEDEF REASON_CONTEXT
PPOWER_REQUEST_CONTEXT                          TYPEDEF XPTR
LPPOWER_REQUEST_CONTEXT                         TYPEDEF XPTR

IFDEF APP_UNICODE
    BROWSEINFO EQU <BROWSEINFOW>
    WIN32_FIND_DATA EQU <WIN32_FIND_DATAW>
    HW_PROFILE_INFO EQU <HW_PROFILE_INFOW>
    CPINFOEX EQU <CPINFOEXW>
    NUMBERFMT EQU <NUMBERFMTW>
    CURRENCYFMT EQU <CURRENCYFMTW>
ELSE
    BROWSEINFO EQU <BROWSEINFOA>
    WIN32_FIND_DATA EQU <WIN32_FIND_DATAA>
    HW_PROFILE_INFO EQU <HW_PROFILE_INFOA>
    CPINFOEX EQU <CPINFOEXA>
    NUMBERFMT EQU <NUMBERFMTA>
    CURRENCYFMT EQU <CURRENCYFMTA>
ENDIF

ENDIF ;WINDOWS_INC
