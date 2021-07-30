; ====================================================;
;                                                     ;
;    windows.inc for EC v2 SolAsm classic projects    ;
;                   (version 1.0.10)                  ;
;                                                     ;
;         Copyright © Ramon Sala - 2018-2021          ;
;                                                     ;
; ====================================================;

#ifndef WINDOWS_INC
WINDOWS_INC equ 1

#ifndef xword_def
    xword_def equ 1
    #ifdef APP_WIN64
        xword_size equ 8
        define xword dq
    #else
        xword_size equ 4
        define xword dd
    #endif
#endif

section "code"  class_code
section "data"  class_data
section "idata" class_imports
section "reloc" class_relocs
section "edata" class_exports
section "bss"   class_bss
section "rsrc"  class_rsrc

;========================================= windef =========================================;
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
NTDDI_WINBLUE                                   equ     006030000H
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

LF_FACESIZE                                     equ     32
L_MAX_URL_LENGTH                                equ     (2048+32+3)
CBEMAXSTRLEN                                    equ     260
MAX_LINKID_TEXT                                 equ     48
LF_FULLFACESIZE                                 equ     64
ELF_VENDOR_SIZE                                 equ     4
MM_MAX_NUMAXES                                  equ     16
MM_MAX_AXES_NAMELEN                             equ     16
CCHDEVICENAME                                   equ     32
SIZE_OF_80387_REGISTERS                         equ     80
MAXIMUM_SUPPORTED_EXTENSION                     equ     512
UNWIND_HISTORY_TABLE_SIZE                       equ     12
SID_HASH_SIZE                                   equ     32
POLICY_AUDIT_SUBCATEGORY_COUNT                  equ     56
TOKEN_SOURCE_LENGTH                             equ     8
POWER_SYSTEM_MAXIMUM                            equ     7
PROC_IDLE_BUCKET_COUNT                          equ     6
NUM_DISCHARGE_POLICIES                          equ     4
IMAGE_SIZEOF_SHORT_NAME                         equ     8
MAXLOGICALLOGNAMESIZE                           equ     256
MAX_TRANSACTION_DESCRIPTION_LENGTH              equ     64

RAS_MaxAreaCode                                 equ     10
RAS_MaxPhoneNumber                              equ     128
RAS_MaxDeviceType                               equ     16
RAS_MaxIpAddress                                equ     15
RAS_MaxIpxAddress                               equ     21
RAS_MaxPadType                                  equ     32
RAS_MaxX25Address                               equ     200
RAS_MaxFacilities                               equ     200
RAS_MaxUserData                                 equ     200
#if NTDDI_VERSION >= NTDDI_WINNT4
    RAS_MaxEntryName                            equ     256
    RAS_MaxDeviceName                           equ     128
    RAS_MaxCallbackNumber                       equ     RAS_MaxPhoneNumber
#else
    RAS_MaxEntryName                            equ     20
    RAS_MaxDeviceName                           equ     32
    RAS_MaxCallbackNumber                       equ     48
#endif

define COLORREF                                 dd

POINTER_DEVICE_PRODUCT_STRING_MAX               equ     520
CCHILDREN_TITLEBAR                              equ     5
CCHILDREN_SCROLLBAR                             equ     5
define TA_TRANSFORM_TYPE                        dd
define TA_TRANSFORM_FLAG                        dd
define TA_TIMINGFUNCTION_TYPE                   dd
define BP_ANIMATIONSTYLE                        dd
#if NTDDI_VERSION >= NTDDI_VISTA
    MAX_INTLIST_COUNT                           equ     402
#else
    MAX_INTLIST_COUNT                           equ     10
#endif

MIXER_SHORT_NAME_CHARS                          equ     16
MIXER_LONG_NAME_CHARS                           equ     64
MAXPNAMELEN                                     equ     32
MAX_JOYSTICKOEMVXDNAME                          equ     260

#ifdef APP_WIN64
    MAXIMUM_PROCESSORS                          equ     64
#else
    MAXIMUM_PROCESSORS                          equ     32
#endif 
MAX_SUPPORTED_OS_NUM                            equ     4

WM_USER_DEF equ 1
WM_USER                                         equ     400H

MAXLONG                                         equ     07FFFFFFFH

MAX_PATH                                        equ     260

ANYSIZE_ARRAY                                   equ     1

NULL                                            equ     0
FALSE                                           equ     0
TRUE                                            equ     1

Normal                                          equ     0000000H
ReadOnly                                        equ     0000001H
Hidden                                          equ     0000010H
System                                          equ     0000100H
vLabel                                          equ     0001000H
SubDir                                          equ     0010000H
Archive                                         equ     0100000H
Black                                           equ     0000000H
Blue                                            equ     0FF0000H
Green                                           equ     000FF00H
Cyan                                            equ     0FFFF00H
Red                                             equ     00000FFH
Magenta                                         equ     0FF00FFH
Yellow                                          equ     000FFFFH
White                                           equ     0FFFFFFH
Gray                                            equ     0080808H

HFILE_ERROR                                     equ     (-1)

DM_UPDATE                                       equ     1
DM_COPY                                         equ     2
DM_PROMPT                                       equ     4
DM_MODIFY                                       equ     8

DM_COPIES                                       equ     000000100H
DM_COLLATE                                      equ     000008000H

DM_IN_BUFFER                                    equ     DM_MODIFY
DM_IN_PROMPT                                    equ     DM_PROMPT
DM_OUT_BUFFER                                   equ     DM_COPY
DM_OUT_DEFAULT                                  equ     DM_UPDATE

MCI_CLOSE                                       equ     0804H
MCI_PLAY                                        equ     0806H
MCI_SEEK                                        equ     0807H
MCI_STOP                                        equ     0808H
MCI_PAUSE                                       equ     0809H
MCI_STEP                                        equ     080EH
MCI_RECORD                                      equ     080FH
MCI_SAVE                                        equ     0813H
MCI_CUT                                         equ     0851H
MCI_COPY                                        equ     0852H
MCI_PASTE                                       equ     0853H
MCI_RESUME                                      equ     0855H
MCI_DELETE                                      equ     0856H

MCI_MODE_NOT_READY                              equ     (MCI_STRING_OFFSET+12)
MCI_MODE_STOP                                   equ     (MCI_STRING_OFFSET+13)
MCI_MODE_PLAY                                   equ     (MCI_STRING_OFFSET+14)
MCI_MODE_RECORD                                 equ     (MCI_STRING_OFFSET+15)
MCI_MODE_SEEK                                   equ     (MCI_STRING_OFFSET+16)
MCI_MODE_PAUSE                                  equ     (MCI_STRING_OFFSET+17)
MCI_MODE_OPEN                                   equ     (MCI_STRING_OFFSET+18)

CNLEN                                           equ     15
LM20_CNLEN                                      equ     15
DNLEN                                           equ     CNLEN
LM20_DNLEN                                      equ     LM20_CNLEN
UNCLEN                                          equ     (CNLEN+2)
LM20_UNCLEN                                     equ     (LM20_CNLEN+2)
NNLEN                                           equ     80
LM20_NNLEN                                      equ     12
RMLEN                                           equ     (UNCLEN+1+NNLEN)
LM20_RMLEN                                      equ     (LM20_UNCLEN+1+LM20_NNLEN)
SNLEN                                           equ     80
LM20_SNLEN                                      equ     15
STXTLEN                                         equ     256
LM20_STXTLEN                                    equ     63
PATHLEN                                         equ     256
LM20_PATHLEN                                    equ     256
DEVLEN                                          equ     80
LM20_DEVLEN                                     equ     8
EVLEN                                           equ     16
UNLEN                                           equ     256
LM20_UNLEN                                      equ     20
GNLEN                                           equ     UNLEN
LM20_GNLEN                                      equ     LM20_UNLEN
PWLEN                                           equ     256
LM20_PWLEN                                      equ     14
SHPWLEN                                         equ     8
CLTYPE_LEN                                      equ     12
MAXCOMMENTSZ                                    equ     256
LM20_MAXCOMMENTSZ                               equ     48
QNLEN                                           equ     NNLEN
LM20_QNLEN                                      equ     LM20_NNLEN
ALERTSZ                                         equ     128
MAXDEVENTRIES                                   equ     32
NETBIOS_NAME_LEN                                equ     16
MAX_PREFERRED_LENGTH                            equ     (-1)
CRYPT_KEY_LEN                                   equ     7
CRYPT_TXT_LEN                                   equ     8
ENCRYPTED_PWLEN                                 equ     16
SESSION_PWLEN                                   equ     24
SESSION_CRYPT_KLEN                              equ     21
PARM_ERROR_UNKNOWN                              equ     (-1)
PARM_ERROR_NONE                                 equ     0
PARMNUM_BASE_INFOLEVEL                          equ     1000
PLATFORM_ID_DOS                                 equ     300
PLATFORM_ID_OS2                                 equ     400
PLATFORM_ID_NT                                  equ     500
PLATFORM_ID_OSF                                 equ     600
PLATFORM_ID_VMS                                 equ     700
MIN_LANMAN_MESSAGE_ID                           equ     NERR_BASE
MAX_LANMAN_MESSAGE_ID                           equ     5799

;====================================== winerror ==========================================;
FACILITY_XPS                                    equ     82
FACILITY_WINRM                                  equ     51
FACILITY_WINDOWSUPDATE                          equ     36
FACILITY_WINDOWS_DEFENDER                       equ     80
FACILITY_WINDOWS_CE                             equ     24
FACILITY_WINDOWS                                equ     8
FACILITY_USERMODE_VOLMGR                        equ     56
FACILITY_USERMODE_VIRTUALIZATION                equ     55
FACILITY_USERMODE_VHD                           equ     58
FACILITY_URT                                    equ     19
FACILITY_UMI                                    equ     22
FACILITY_UI                                     equ     42
FACILITY_TPM_SOFTWARE                           equ     41
FACILITY_TPM_SERVICES                           equ     40
FACILITY_SXS                                    equ     23
FACILITY_STORAGE                                equ     3
FACILITY_STATE_MANAGEMENT                       equ     34
FACILITY_SSPI                                   equ     9
FACILITY_SCARD                                  equ     16
FACILITY_SHELL                                  equ     39
FACILITY_SETUPAPI                               equ     15
FACILITY_SECURITY                               equ     9
FACILITY_SDIAG                                  equ     60
FACILITY_RPC                                    equ     1
FACILITY_RAS                                    equ     83
FACILITY_PLA                                    equ     48
FACILITY_OPC                                    equ     81
FACILITY_WIN32                                  equ     7
FACILITY_CONTROL                                equ     10
FACILITY_WEBSERVICES                            equ     61
FACILITY_NULL                                   equ     0
FACILITY_NDIS                                   equ     52
FACILITY_METADIRECTORY                          equ     35
FACILITY_MSMQ                                   equ     14
FACILITY_MEDIASERVER                            equ     13
FACILITY_MBN                                    equ     84
FACILITY_INTERNET                               equ     12
FACILITY_ITF                                    equ     4
FACILITY_USERMODE_HYPERVISOR                    equ     53
FACILITY_HTTP                                   equ     25
FACILITY_GRAPHICS                               equ     38
FACILITY_FWP                                    equ     50
FACILITY_FVE                                    equ     49
FACILITY_USERMODE_FILTER_MANAGER                equ     31
FACILITY_DPLAY                                  equ     21
FACILITY_DISPATCH                               equ     2
FACILITY_DIRECTORYSERVICE                       equ     37
FACILITY_CONFIGURATION                          equ     33
FACILITY_COMPLUS                                equ     17
FACILITY_USERMODE_COMMONLOG                     equ     26
FACILITY_CMI                                    equ     54
FACILITY_CERT                                   equ     11
FACILITY_BCD                                    equ     57
FACILITY_BACKGROUNDCOPY                         equ     32
FACILITY_ACS                                    equ     20
FACILITY_AAF                                    equ     18
FACILITY_USB_ERROR_CODE                         equ     010H
FACILITY_TERMINAL_SERVER                        equ     0AH
FACILITY_SXS_ERROR_CODE                         equ     015H
FACILITY_RPC_STUBS                              equ     03H
FACILITY_RPC_RUNTIME                            equ     02H
FACILITY_IO_ERROR_CODE                          equ     04H
FACILITY_HID_ERROR_CODE                         equ     011H
FACILITY_FIREWIRE_ERROR_CODE                    equ     012H
FACILITY_DEBUGGER                               equ     01H
FACILITY_CLUSTER_ERROR_CODE                     equ     013H
FACILITY_ACPI_ERROR_CODE                        equ     014H
ERROR_SUCCESS                                   equ     0
NO_ERROR                                        equ     0
SEC_E_OK                                        equ     00000000H
STATUS_SUCCESS                                  equ     00000000H
STATUS_SEVERITY_WARNING                         equ     02H
STATUS_SEVERITY_SUCCESS                         equ     00H
STATUS_SEVERITY_INFORMATIONAL                   equ     01H
STATUS_SEVERITY_ERROR                           equ     03H
STATUS_WAIT_1                                   equ     000000001H
STATUS_WAIT_2                                   equ     000000002H
STATUS_WAIT_3                                   equ     000000003H
STATUS_WAIT_63                                  equ     00000003FH
STATUS_ABANDONED                                equ     000000080H
STATUS_ABANDONED_WAIT_63                        equ     0000000BFH
STATUS_KERNEL_APC                               equ     000000100H
STATUS_ALERTED                                  equ     000000101H
STATUS_REPARSE                                  equ     000000104H
STATUS_MORE_ENTRIES                             equ     000000105H
STATUS_NOT_ALL_ASSIGNED                         equ     000000106H
STATUS_SOME_NOT_MAPPED                          equ     000000107H
STATUS_OPLOCK_BREAK_IN_PROGRESS                 equ     000000108H
STATUS_VOLUME_MOUNTED                           equ     000000109H
STATUS_RXACT_COMMITTED                          equ     00000010AH
STATUS_NOTIFY_CLEANUP                           equ     00000010BH
STATUS_NOTIFY_ENUM_DIR                          equ     00000010CH
STATUS_NO_QUOTAS_FOR_ACCOUNT                    equ     00000010DH
STATUS_PRIMARY_TRANSPORT_CONNECT_FAILED         equ     00000010EH
STATUS_PAGE_FAULT_TRANSITION                    equ     000000110H
STATUS_PAGE_FAULT_DEMAND_ZERO                   equ     000000111H
STATUS_PAGE_FAULT_COPY_ON_WRITE                 equ     000000112H
STATUS_PAGE_FAULT_GUARD_PAGE                    equ     000000113H
STATUS_PAGE_FAULT_PAGING_FILE                   equ     000000114H
STATUS_CACHE_PAGE_LOCKED                        equ     000000115H
STATUS_CRASH_DUMP                               equ     000000116H
STATUS_BUFFER_ALL_ZEROS                         equ     000000117H
STATUS_REPARSE_OBJECT                           equ     000000118H
STATUS_RESOURCE_REQUIREMENTS_CHANGED            equ     000000119H
STATUS_TRANSLATION_COMPLETE                     equ     000000120H
STATUS_DS_MEMBERSHIP_EVALUATED_LOCALLY          equ     000000121H
STATUS_NOTHING_TO_TERMINATE                     equ     000000122H
STATUS_PROCESS_NOT_IN_JOB                       equ     000000123H
STATUS_PROCESS_IN_JOB                           equ     000000124H
STATUS_VOLSNAP_HIBERNATE_READY                  equ     000000125H
STATUS_FSFILTER_OP_COMPLETED_SUCCESSFULLY       equ     000000126H
STATUS_OBJECT_NAME_EXISTS                       equ     040000000H
STATUS_THREAD_WAS_SUSPENDED                     equ     040000001H
STATUS_WORKING_SET_LIMIT_RANGE                  equ     040000002H
STATUS_IMAGE_NOT_AT_BASE                        equ     040000003H
STATUS_RXACT_STATE_CREATED                      equ     040000004H
STATUS_LOCAL_USER_SESSION_KEY                   equ     040000006H
STATUS_BAD_CURRENT_DIRECTORY                    equ     040000007H
STATUS_SERIAL_MORE_WRITES                       equ     040000008H
STATUS_REGISTRY_RECOVERED                       equ     040000009H
STATUS_FT_READ_RECOVERY_FROM_BACKUP             equ     04000000AH
STATUS_FT_WRITE_RECOVERY                        equ     04000000BH
STATUS_SERIAL_COUNTER_TIMEOUT                   equ     04000000CH
STATUS_NULL_LM_PASSWORD                         equ     04000000DH
STATUS_IMAGE_MACHINE_TYPE_MISMATCH              equ     04000000EH
STATUS_RECEIVE_PARTIAL                          equ     04000000FH
STATUS_RECEIVE_EXPEDITED                        equ     040000010H
STATUS_RECEIVE_PARTIAL_EXPEDITED                equ     040000011H
STATUS_EVENT_DONE                               equ     040000012H
STATUS_EVENT_PENDING                            equ     040000013H
STATUS_CHECKING_FILE_SYSTEM                     equ     040000014H
STATUS_FATAL_APP_EXIT                           equ     040000015H
STATUS_PREDEFINED_HANDLE                        equ     040000016H
STATUS_WAS_UNLOCKED                             equ     040000017H
STATUS_SERVICE_NOTIFICATION                     equ     040000018H
STATUS_WAS_LOCKED                               equ     040000019H
STATUS_LOG_HARD_ERROR                           equ     04000001AH
STATUS_ALREADY_WIN32                            equ     04000001BH
STATUS_WX86_UNSIMULATE                          equ     04000001CH
STATUS_WX86_CONTINUE                            equ     04000001DH
STATUS_WX86_SINGLE_STEP                         equ     04000001EH
STATUS_WX86_BREAKPOINT                          equ     04000001FH
STATUS_WX86_EXCEPTION_CONTINUE                  equ     040000020H
STATUS_WX86_EXCEPTION_LASTCHANCE                equ     040000021H
STATUS_WX86_EXCEPTION_CHAIN                     equ     040000022H
STATUS_IMAGE_MACHINE_TYPE_MISMATCH_EXE          equ     040000023H
STATUS_NO_YIELD_PERFORMED                       equ     040000024H
STATUS_TIMER_RESUME_IGNORED                     equ     040000025H
STATUS_ARBITRATION_UNHANDLED                    equ     040000026H
STATUS_CARDBUS_NOT_SUPPORTED                    equ     040000027H
STATUS_WX86_CREATEWX86TIB                       equ     040000028H
STATUS_MP_PROCESSOR_MISMATCH                    equ     040000029H
STATUS_HIBERNATED                               equ     04000002AH
STATUS_RESUME_HIBERNATION                       equ     04000002BH
STATUS_FIRMWARE_UPDATED                         equ     04000002CH
STATUS_DRIVERS_LEAKING_LOCKED_PAGES             equ     04000002DH
DBG_REPLY_LATER                                 equ     040010001H
DBG_UNABLE_TO_PROVIDE_HANDLE                    equ     040010002H
DBG_PRINTEXCEPTION_C                            equ     040010006H
DBG_RIPEXCEPTION                                equ     040010007H
STATUS_BUFFER_OVERFLOW                          equ     080000005H
STATUS_NO_MORE_FILES                            equ     080000006H
STATUS_WAKE_SYSTEM_DEBUGGER                     equ     080000007H
STATUS_HANDLES_CLOSED                           equ     08000000AH
STATUS_NO_INHERITANCE                           equ     08000000BH
STATUS_GUID_SUBSTITUTION_MADE                   equ     08000000CH
STATUS_PARTIAL_COPY                             equ     08000000DH
STATUS_DEVICE_PAPER_EMPTY                       equ     08000000EH
STATUS_DEVICE_POWERED_OFF                       equ     08000000FH
STATUS_DEVICE_OFF_LINE                          equ     080000010H
STATUS_DEVICE_BUSY                              equ     080000011H
STATUS_NO_MORE_EAS                              equ     080000012H
STATUS_INVALID_EA_NAME                          equ     080000013H
STATUS_EA_LIST_INCONSISTENT                     equ     080000014H
STATUS_INVALID_EA_FLAG                          equ     080000015H
STATUS_VERIFY_REQUIRED                          equ     080000016H
STATUS_EXTRANEOUS_INFORMATION                   equ     080000017H
STATUS_RXACT_COMMIT_NECESSARY                   equ     080000018H
STATUS_NO_MORE_ENTRIES                          equ     08000001AH
STATUS_FILEMARK_DETECTED                        equ     08000001BH
STATUS_MEDIA_CHANGED                            equ     08000001CH
STATUS_BUS_RESET                                equ     08000001DH
STATUS_END_OF_MEDIA                             equ     08000001EH
STATUS_BEGINNING_OF_MEDIA                       equ     08000001FH
STATUS_MEDIA_CHECK                              equ     080000020H
STATUS_SETMARK_DETECTED                         equ     080000021H
STATUS_NO_DATA_DETECTED                         equ     080000022H
STATUS_REDIRECTOR_HAS_OPEN_HANDLES              equ     080000023H
STATUS_SERVER_HAS_OPEN_HANDLES                  equ     080000024H
STATUS_ALREADY_DISCONNECTED                     equ     080000025H
STATUS_LONGJUMP                                 equ     080000026H
STATUS_CLEANER_CARTRIDGE_INSTALLED              equ     080000027H
STATUS_PLUGPLAY_QUERY_VETOED                    equ     080000028H
STATUS_UNWIND_CONSOLIDATE                       equ     080000029H
STATUS_REGISTRY_HIVE_RECOVERED                  equ     08000002AH
STATUS_DLL_MIGHT_BE_INSECURE                    equ     08000002BH
STATUS_DLL_MIGHT_BE_INCOMPATIBLE                equ     08000002CH
STATUS_CLUSTER_NODE_ALREADY_UP                  equ     080130001H
STATUS_CLUSTER_NODE_ALREADY_DOWN                equ     080130002H
STATUS_CLUSTER_NETWORK_ALREADY_ONLINE           equ     080130003H
STATUS_CLUSTER_NETWORK_ALREADY_OFFLINE          equ     080130004H
STATUS_CLUSTER_NODE_ALREADY_MEMBER              equ     080130005H
STATUS_UNSUCCESSFUL                             equ     0C0000001H
STATUS_NOT_IMPLEMENTED                          equ     0C0000002H
STATUS_INVALID_INFO_CLASS                       equ     0C0000003H
STATUS_INFO_LENGTH_MISMATCH                     equ     0C0000004H
STATUS_PAGEFILE_QUOTA                           equ     0C0000007H
STATUS_BAD_INITIAL_STACK                        equ     0C0000009H
STATUS_BAD_INITIAL_PC                           equ     0C000000AH
STATUS_INVALID_CID                              equ     0C000000BH
STATUS_TIMER_NOT_CANCELED                       equ     0C000000CH
STATUS_INVALID_PARAMETER                        equ     0C000000DH
STATUS_NO_SUCH_DEVICE                           equ     0C000000EH
STATUS_NO_SUCH_FILE                             equ     0C000000FH
STATUS_INVALID_DEVICE_REQUEST                   equ     0C0000010H
STATUS_END_OF_FILE                              equ     0C0000011H
STATUS_WRONG_VOLUME                             equ     0C0000012H
STATUS_NO_MEDIA_IN_DEVICE                       equ     0C0000013H
STATUS_UNRECOGNIZED_MEDIA                       equ     0C0000014H
STATUS_NONEXISTENT_SECTOR                       equ     0C0000015H
STATUS_MORE_PROCESSING_REQUIRED                 equ     0C0000016H
STATUS_CONFLICTING_ADDRESSES                    equ     0C0000018H
STATUS_NOT_MAPPED_VIEW                          equ     0C0000019H
STATUS_UNABLE_TO_FREE_VM                        equ     0C000001AH
STATUS_UNABLE_TO_DELETE_SECTION                 equ     0C000001BH
STATUS_INVALID_SYSTEM_SERVICE                   equ     0C000001CH
STATUS_INVALID_LOCK_SEQUENCE                    equ     0C000001EH
STATUS_INVALID_VIEW_SIZE                        equ     0C000001FH
STATUS_INVALID_FILE_FOR_SECTION                 equ     0C0000020H
STATUS_ALREADY_COMMITTED                        equ     0C0000021H
STATUS_ACCESS_DENIED                            equ     0C0000022H
STATUS_BUFFER_TOO_SMALL                         equ     0C0000023H
STATUS_OBJECT_TYPE_MISMATCH                     equ     0C0000024H
STATUS_UNWIND                                   equ     0C0000027H
STATUS_BAD_STACK                                equ     0C0000028H
STATUS_INVALID_UNWIND_TARGET                    equ     0C0000029H
STATUS_NOT_LOCKED                               equ     0C000002AH
STATUS_PARITY_ERROR                             equ     0C000002BH
STATUS_UNABLE_TO_DECOMMIT_VM                    equ     0C000002CH
STATUS_NOT_COMMITTED                            equ     0C000002DH
STATUS_INVALID_PORT_ATTRIBUTES                  equ     0C000002EH
STATUS_PORT_MESSAGE_TOO_LONG                    equ     0C000002FH
STATUS_INVALID_PARAMETER_MIX                    equ     0C0000030H
STATUS_INVALID_QUOTA_LOWER                      equ     0C0000031H
STATUS_DISK_CORRUPT_ERROR                       equ     0C0000032H
STATUS_OBJECT_NAME_INVALID                      equ     0C0000033H
STATUS_OBJECT_NAME_NOT_FOUND                    equ     0C0000034H
STATUS_OBJECT_NAME_COLLISION                    equ     0C0000035H
STATUS_PORT_DISCONNECTED                        equ     0C0000037H
STATUS_DEVICE_ALREADY_ATTACHED                  equ     0C0000038H
STATUS_OBJECT_PATH_INVALID                      equ     0C0000039H
STATUS_OBJECT_PATH_NOT_FOUND                    equ     0C000003AH
STATUS_OBJECT_PATH_SYNTAX_BAD                   equ     0C000003BH
STATUS_DATA_OVERRUN                             equ     0C000003CH
STATUS_DATA_LATE_ERROR                          equ     0C000003DH
STATUS_DATA_ERROR                               equ     0C000003EH
STATUS_CRC_ERROR                                equ     0C000003FH
STATUS_SECTION_TOO_BIG                          equ     0C0000040H
STATUS_PORT_CONNECTION_REFUSED                  equ     0C0000041H
STATUS_INVALID_PORT_HANDLE                      equ     0C0000042H
STATUS_SHARING_VIOLATION                        equ     0C0000043H
STATUS_QUOTA_EXCEEDED                           equ     0C0000044H
STATUS_INVALID_PAGE_PROTECTION                  equ     0C0000045H
STATUS_MUTANT_NOT_OWNED                         equ     0C0000046H
STATUS_SEMAPHORE_LIMIT_EXCEEDED                 equ     0C0000047H
STATUS_PORT_ALREADY_SET                         equ     0C0000048H
STATUS_SECTION_NOT_IMAGE                        equ     0C0000049H
STATUS_SUSPEND_COUNT_EXCEEDED                   equ     0C000004AH
STATUS_THREAD_IS_TERMINATING                    equ     0C000004BH
STATUS_BAD_WORKING_SET_LIMIT                    equ     0C000004CH
STATUS_INCOMPATIBLE_FILE_MAP                    equ     0C000004DH
STATUS_SECTION_PROTECTION                       equ     0C000004EH
STATUS_EAS_NOT_SUPPORTED                        equ     0C000004FH
STATUS_EA_TOO_LARGE                             equ     0C0000050H
STATUS_NONEXISTENT_EA_ENTRY                     equ     0C0000051H
STATUS_NO_EAS_ON_FILE                           equ     0C0000052H
STATUS_EA_CORRUPT_ERROR                         equ     0C0000053H
STATUS_FILE_LOCK_CONFLICT                       equ     0C0000054H
STATUS_LOCK_NOT_GRANTED                         equ     0C0000055H
STATUS_DELETE_PENDING                           equ     0C0000056H
STATUS_CTL_FILE_NOT_SUPPORTED                   equ     0C0000057H
STATUS_UNKNOWN_REVISION                         equ     0C0000058H
STATUS_REVISION_MISMATCH                        equ     0C0000059H
STATUS_INVALID_OWNER                            equ     0C000005AH
STATUS_INVALID_PRIMARY_GROUP                    equ     0C000005BH
STATUS_NO_IMPERSONATION_TOKEN                   equ     0C000005CH
STATUS_CANT_DISABLE_MANDATORY                   equ     0C000005DH
STATUS_NO_LOGON_SERVERS                         equ     0C000005EH
STATUS_NO_SUCH_LOGON_SESSION                    equ     0C000005FH
STATUS_NO_SUCH_PRIVILEGE                        equ     0C0000060H
STATUS_PRIVILEGE_NOT_HELD                       equ     0C0000061H
STATUS_INVALID_ACCOUNT_NAME                     equ     0C0000062H
STATUS_USER_EXISTS                              equ     0C0000063H
STATUS_NO_SUCH_USER                             equ     0C0000064H
STATUS_GROUP_EXISTS                             equ     0C0000065H
STATUS_NO_SUCH_GROUP                            equ     0C0000066H
STATUS_MEMBER_IN_GROUP                          equ     0C0000067H
STATUS_MEMBER_NOT_IN_GROUP                      equ     0C0000068H
STATUS_LAST_ADMIN                               equ     0C0000069H
STATUS_WRONG_PASSWORD                           equ     0C000006AH
STATUS_ILL_FORMED_PASSWORD                      equ     0C000006BH
STATUS_PASSWORD_RESTRICTION                     equ     0C000006CH
STATUS_LOGON_FAILURE                            equ     0C000006DH
STATUS_ACCOUNT_RESTRICTION                      equ     0C000006EH
STATUS_INVALID_LOGON_HOURS                      equ     0C000006FH
STATUS_INVALID_WORKSTATION                      equ     0C0000070H
STATUS_PASSWORD_EXPIRED                         equ     0C0000071H
STATUS_ACCOUNT_DISABLED                         equ     0C0000072H
STATUS_NONE_MAPPED                              equ     0C0000073H
STATUS_TOO_MANY_LUIDS_REQUESTED                 equ     0C0000074H
STATUS_LUIDS_EXHAUSTED                          equ     0C0000075H
STATUS_INVALID_SUB_AUTHORITY                    equ     0C0000076H
STATUS_INVALID_ACL                              equ     0C0000077H
STATUS_INVALID_SID                              equ     0C0000078H
STATUS_INVALID_SECURITY_DESCR                   equ     0C0000079H
STATUS_PROCEDURE_NOT_FOUND                      equ     0C000007AH
STATUS_INVALID_IMAGE_FORMAT                     equ     0C000007BH
STATUS_NO_TOKEN                                 equ     0C000007CH
STATUS_BAD_INHERITANCE_ACL                      equ     0C000007DH
STATUS_RANGE_NOT_LOCKED                         equ     0C000007EH
STATUS_DISK_FULL                                equ     0C000007FH
STATUS_SERVER_DISABLED                          equ     0C0000080H
STATUS_SERVER_NOT_DISABLED                      equ     0C0000081H
STATUS_TOO_MANY_GUIDS_REQUESTED                 equ     0C0000082H
STATUS_GUIDS_EXHAUSTED                          equ     0C0000083H
STATUS_INVALID_ID_AUTHORITY                     equ     0C0000084H
STATUS_AGENTS_EXHAUSTED                         equ     0C0000085H
STATUS_INVALID_VOLUME_LABEL                     equ     0C0000086H
STATUS_SECTION_NOT_EXTENDED                     equ     0C0000087H
STATUS_NOT_MAPPED_DATA                          equ     0C0000088H
STATUS_RESOURCE_DATA_NOT_FOUND                  equ     0C0000089H
STATUS_RESOURCE_TYPE_NOT_FOUND                  equ     0C000008AH
STATUS_RESOURCE_NAME_NOT_FOUND                  equ     0C000008BH
STATUS_TOO_MANY_PAGING_FILES                    equ     0C0000097H
STATUS_FILE_INVALID                             equ     0C0000098H
STATUS_ALLOTTED_SPACE_EXCEEDED                  equ     0C0000099H
STATUS_INSUFFICIENT_RESOURCES                   equ     0C000009AH
STATUS_DFS_EXIT_PATH_FOUND                      equ     0C000009BH
STATUS_DEVICE_DATA_ERROR                        equ     0C000009CH
STATUS_DEVICE_NOT_CONNECTED                     equ     0C000009DH
STATUS_DEVICE_POWER_FAILURE                     equ     0C000009EH
STATUS_FREE_VM_NOT_AT_BASE                      equ     0C000009FH
STATUS_MEMORY_NOT_ALLOCATED                     equ     0C00000A0H
STATUS_WORKING_SET_QUOTA                        equ     0C00000A1H
STATUS_MEDIA_WRITE_PROTECTED                    equ     0C00000A2H
STATUS_DEVICE_NOT_READY                         equ     0C00000A3H
STATUS_INVALID_GROUP_ATTRIBUTES                 equ     0C00000A4H
STATUS_BAD_IMPERSONATION_LEVEL                  equ     0C00000A5H
STATUS_CANT_OPEN_ANONYMOUS                      equ     0C00000A6H
STATUS_BAD_VALIDATION_CLASS                     equ     0C00000A7H
STATUS_BAD_TOKEN_TYPE                           equ     0C00000A8H
STATUS_BAD_MASTER_BOOT_RECORD                   equ     0C00000A9H
STATUS_INSTRUCTION_MISALIGNMENT                 equ     0C00000AAH
STATUS_INSTANCE_NOT_AVAILABLE                   equ     0C00000ABH
STATUS_PIPE_NOT_AVAILABLE                       equ     0C00000ACH
STATUS_INVALID_PIPE_STATE                       equ     0C00000ADH
STATUS_PIPE_BUSY                                equ     0C00000AEH
STATUS_ILLEGAL_FUNCTION                         equ     0C00000AFH
STATUS_PIPE_DISCONNECTED                        equ     0C00000B0H
STATUS_PIPE_CLOSING                             equ     0C00000B1H
STATUS_PIPE_CONNECTED                           equ     0C00000B2H
STATUS_PIPE_LISTENING                           equ     0C00000B3H
STATUS_INVALID_READ_MODE                        equ     0C00000B4H
STATUS_IO_TIMEOUT                               equ     0C00000B5H
STATUS_FILE_FORCED_CLOSED                       equ     0C00000B6H
STATUS_PROFILING_NOT_STARTED                    equ     0C00000B7H
STATUS_PROFILING_NOT_STOPPED                    equ     0C00000B8H
STATUS_COULD_NOT_INTERPRET                      equ     0C00000B9H
STATUS_FILE_IS_A_DIRECTORY                      equ     0C00000BAH
STATUS_NOT_SUPPORTED                            equ     0C00000BBH
STATUS_REMOTE_NOT_LISTENING                     equ     0C00000BCH
STATUS_DUPLICATE_NAME                           equ     0C00000BDH
STATUS_BAD_NETWORK_PATH                         equ     0C00000BEH
STATUS_NETWORK_BUSY                             equ     0C00000BFH
STATUS_DEVICE_DOES_NOT_EXIST                    equ     0C00000C0H
STATUS_TOO_MANY_COMMANDS                        equ     0C00000C1H
STATUS_ADAPTER_HARDWARE_ERROR                   equ     0C00000C2H
STATUS_INVALID_NETWORK_RESPONSE                 equ     0C00000C3H
STATUS_UNEXPECTED_NETWORK_ERROR                 equ     0C00000C4H
STATUS_BAD_REMOTE_ADAPTER                       equ     0C00000C5H
STATUS_PRINT_QUEUE_FULL                         equ     0C00000C6H
STATUS_NO_SPOOL_SPACE                           equ     0C00000C7H
STATUS_PRINT_CANCELLED                          equ     0C00000C8H
STATUS_NETWORK_NAME_DELETED                     equ     0C00000C9H
STATUS_NETWORK_ACCESS_DENIED                    equ     0C00000CAH
STATUS_BAD_DEVICE_TYPE                          equ     0C00000CBH
STATUS_BAD_NETWORK_NAME                         equ     0C00000CCH
STATUS_TOO_MANY_NAMES                           equ     0C00000CDH
STATUS_TOO_MANY_SESSIONS                        equ     0C00000CEH
STATUS_SHARING_PAUSED                           equ     0C00000CFH
STATUS_REQUEST_NOT_ACCEPTED                     equ     0C00000D0H
STATUS_REDIRECTOR_PAUSED                        equ     0C00000D1H
STATUS_NET_WRITE_FAULT                          equ     0C00000D2H
STATUS_PROFILING_AT_LIMIT                       equ     0C00000D3H
STATUS_NOT_SAME_DEVICE                          equ     0C00000D4H
STATUS_FILE_RENAMED                             equ     0C00000D5H
STATUS_VIRTUAL_CIRCUIT_CLOSED                   equ     0C00000D6H
STATUS_NO_SECURITY_ON_OBJECT                    equ     0C00000D7H
STATUS_CANT_WAIT                                equ     0C00000D8H
STATUS_PIPE_EMPTY                               equ     0C00000D9H
STATUS_CANT_ACCESS_DOMAIN_INFO                  equ     0C00000DAH
STATUS_CANT_TERMINATE_SELF                      equ     0C00000DBH
STATUS_INVALID_SERVER_STATE                     equ     0C00000DCH
STATUS_INVALID_DOMAIN_STATE                     equ     0C00000DDH
STATUS_INVALID_DOMAIN_ROLE                      equ     0C00000DEH
STATUS_NO_SUCH_DOMAIN                           equ     0C00000DFH
STATUS_DOMAIN_EXISTS                            equ     0C00000E0H
STATUS_DOMAIN_LIMIT_EXCEEDED                    equ     0C00000E1H
STATUS_OPLOCK_NOT_GRANTED                       equ     0C00000E2H
STATUS_INVALID_OPLOCK_PROTOCOL                  equ     0C00000E3H
STATUS_INTERNAL_DB_CORRUPTION                   equ     0C00000E4H
STATUS_INTERNAL_ERROR                           equ     0C00000E5H
STATUS_GENERIC_NOT_MAPPED                       equ     0C00000E6H
STATUS_BAD_DESCRIPTOR_FORMAT                    equ     0C00000E7H
STATUS_INVALID_USER_BUFFER                      equ     0C00000E8H
STATUS_UNEXPECTED_IO_ERROR                      equ     0C00000E9H
STATUS_UNEXPECTED_MM_CREATE_ERR                 equ     0C00000EAH
STATUS_UNEXPECTED_MM_MAP_ERROR                  equ     0C00000EBH
STATUS_UNEXPECTED_MM_EXTEND_ERR                 equ     0C00000ECH
STATUS_NOT_LOGON_PROCESS                        equ     0C00000EDH
STATUS_LOGON_SESSION_EXISTS                     equ     0C00000EEH
STATUS_INVALID_PARAMETER_1                      equ     0C00000EFH
STATUS_INVALID_PARAMETER_2                      equ     0C00000F0H
STATUS_INVALID_PARAMETER_3                      equ     0C00000F1H
STATUS_INVALID_PARAMETER_4                      equ     0C00000F2H
STATUS_INVALID_PARAMETER_5                      equ     0C00000F3H
STATUS_INVALID_PARAMETER_6                      equ     0C00000F4H
STATUS_INVALID_PARAMETER_7                      equ     0C00000F5H
STATUS_INVALID_PARAMETER_8                      equ     0C00000F6H
STATUS_INVALID_PARAMETER_9                      equ     0C00000F7H
STATUS_INVALID_PARAMETER_10                     equ     0C00000F8H
STATUS_INVALID_PARAMETER_11                     equ     0C00000F9H
STATUS_INVALID_PARAMETER_12                     equ     0C00000FAH
STATUS_REDIRECTOR_NOT_STARTED                   equ     0C00000FBH
STATUS_REDIRECTOR_STARTED                       equ     0C00000FCH
STATUS_NO_SUCH_PACKAGE                          equ     0C00000FEH
STATUS_BAD_FUNCTION_TABLE                       equ     0C00000FFH
STATUS_VARIABLE_NOT_FOUND                       equ     0C0000100H
STATUS_DIRECTORY_NOT_EMPTY                      equ     0C0000101H
STATUS_FILE_CORRUPT_ERROR                       equ     0C0000102H
STATUS_NOT_A_DIRECTORY                          equ     0C0000103H
STATUS_BAD_LOGON_SESSION_STATE                  equ     0C0000104H
STATUS_LOGON_SESSION_COLLISION                  equ     0C0000105H
STATUS_NAME_TOO_LONG                            equ     0C0000106H
STATUS_FILES_OPEN                               equ     0C0000107H
STATUS_CONNECTION_IN_USE                        equ     0C0000108H
STATUS_MESSAGE_NOT_FOUND                        equ     0C0000109H
STATUS_PROCESS_IS_TERMINATING                   equ     0C000010AH
STATUS_INVALID_LOGON_TYPE                       equ     0C000010BH
STATUS_NO_GUID_TRANSLATION                      equ     0C000010CH
STATUS_CANNOT_IMPERSONATE                       equ     0C000010DH
STATUS_IMAGE_ALREADY_LOADED                     equ     0C000010EH
STATUS_ABIOS_NOT_PRESENT                        equ     0C000010FH
STATUS_ABIOS_LID_NOT_EXIST                      equ     0C0000110H
STATUS_ABIOS_LID_ALREADY_OWNED                  equ     0C0000111H
STATUS_ABIOS_NOT_LID_OWNER                      equ     0C0000112H
STATUS_ABIOS_INVALID_COMMAND                    equ     0C0000113H
STATUS_ABIOS_INVALID_LID                        equ     0C0000114H
STATUS_ABIOS_SELECTOR_NOT_AVAILABLE             equ     0C0000115H
STATUS_ABIOS_INVALID_SELECTOR                   equ     0C0000116H
STATUS_NO_LDT                                   equ     0C0000117H
STATUS_INVALID_LDT_SIZE                         equ     0C0000118H
STATUS_INVALID_LDT_OFFSET                       equ     0C0000119H
STATUS_INVALID_LDT_DESCRIPTOR                   equ     0C000011AH
STATUS_INVALID_IMAGE_NE_FORMAT                  equ     0C000011BH
STATUS_RXACT_INVALID_STATE                      equ     0C000011CH
STATUS_RXACT_COMMIT_FAILURE                     equ     0C000011DH
STATUS_MAPPED_FILE_SIZE_ZERO                    equ     0C000011EH
STATUS_TOO_MANY_OPENED_FILES                    equ     0C000011FH
STATUS_CANCELLED                                equ     0C0000120H
STATUS_CANNOT_DELETE                            equ     0C0000121H
STATUS_INVALID_COMPUTER_NAME                    equ     0C0000122H
STATUS_FILE_DELETED                             equ     0C0000123H
STATUS_SPECIAL_ACCOUNT                          equ     0C0000124H
STATUS_SPECIAL_GROUP                            equ     0C0000125H
STATUS_SPECIAL_USER                             equ     0C0000126H
STATUS_MEMBERS_PRIMARY_GROUP                    equ     0C0000127H
STATUS_FILE_CLOSED                              equ     0C0000128H
STATUS_TOO_MANY_THREADS                         equ     0C0000129H
STATUS_THREAD_NOT_IN_PROCESS                    equ     0C000012AH
STATUS_TOKEN_ALREADY_IN_USE                     equ     0C000012BH
STATUS_PAGEFILE_QUOTA_EXCEEDED                  equ     0C000012CH
STATUS_COMMITMENT_LIMIT                         equ     0C000012DH
STATUS_INVALID_IMAGE_LE_FORMAT                  equ     0C000012EH
STATUS_INVALID_IMAGE_NOT_MZ                     equ     0C000012FH
STATUS_INVALID_IMAGE_PROTECT                    equ     0C0000130H
STATUS_INVALID_IMAGE_WIN_16                     equ     0C0000131H
STATUS_LOGON_SERVER_CONFLICT                    equ     0C0000132H
STATUS_TIME_DIFFERENCE_AT_DC                    equ     0C0000133H
STATUS_SYNCHRONIZATION_REQUIRED                 equ     0C0000134H
STATUS_DLL_NOT_FOUND                            equ     0C0000135H
STATUS_OPEN_FAILED                              equ     0C0000136H
STATUS_IO_PRIVILEGE_FAILED                      equ     0C0000137H
STATUS_ORDINAL_NOT_FOUND                        equ     0C0000138H
STATUS_ENTRYPOINT_NOT_FOUND                     equ     0C0000139H
STATUS_LOCAL_DISCONNECT                         equ     0C000013BH
STATUS_REMOTE_DISCONNECT                        equ     0C000013CH
STATUS_REMOTE_RESOURCES                         equ     0C000013DH
STATUS_LINK_FAILED                              equ     0C000013EH
STATUS_LINK_TIMEOUT                             equ     0C000013FH
STATUS_INVALID_CONNECTION                       equ     0C0000140H
STATUS_INVALID_ADDRESS                          equ     0C0000141H
STATUS_DLL_INIT_FAILED                          equ     0C0000142H
STATUS_MISSING_SYSTEMFILE                       equ     0C0000143H
STATUS_UNHANDLED_EXCEPTION                      equ     0C0000144H
STATUS_APP_INIT_FAILURE                         equ     0C0000145H
STATUS_PAGEFILE_CREATE_FAILED                   equ     0C0000146H
STATUS_NO_PAGEFILE                              equ     0C0000147H
STATUS_INVALID_LEVEL                            equ     0C0000148H
STATUS_WRONG_PASSWORD_CORE                      equ     0C0000149H
STATUS_ILLEGAL_FLOAT_CONTEXT                    equ     0C000014AH
STATUS_PIPE_BROKEN                              equ     0C000014BH
STATUS_REGISTRY_CORRUPT                         equ     0C000014CH
STATUS_REGISTRY_IO_FAILED                       equ     0C000014DH
STATUS_NO_EVENT_PAIR                            equ     0C000014EH
STATUS_UNRECOGNIZED_VOLUME                      equ     0C000014FH
STATUS_SERIAL_NO_DEVICE_INITED                  equ     0C0000150H
STATUS_NO_SUCH_ALIAS                            equ     0C0000151H
STATUS_MEMBER_NOT_IN_ALIAS                      equ     0C0000152H
STATUS_MEMBER_IN_ALIAS                          equ     0C0000153H
STATUS_ALIAS_EXISTS                             equ     0C0000154H
STATUS_LOGON_NOT_GRANTED                        equ     0C0000155H
STATUS_TOO_MANY_SECRETS                         equ     0C0000156H
STATUS_SECRET_TOO_LONG                          equ     0C0000157H
STATUS_INTERNAL_DB_ERROR                        equ     0C0000158H
STATUS_FULLSCREEN_MODE                          equ     0C0000159H
STATUS_TOO_MANY_CONTEXT_IDS                     equ     0C000015AH
STATUS_LOGON_TYPE_NOT_GRANTED                   equ     0C000015BH
STATUS_NOT_REGISTRY_FILE                        equ     0C000015CH
STATUS_NT_CROSS_ENCRYPTION_REQUIRED             equ     0C000015DH
STATUS_DOMAIN_CTRLR_CONFIG_ERROR                equ     0C000015EH
STATUS_FT_MISSING_MEMBER                        equ     0C000015FH
STATUS_ILL_FORMED_SERVICE_ENTRY                 equ     0C0000160H
STATUS_ILLEGAL_CHARACTER                        equ     0C0000161H
STATUS_UNMAPPABLE_CHARACTER                     equ     0C0000162H
STATUS_UNDEFINED_CHARACTER                      equ     0C0000163H
STATUS_FLOPPY_VOLUME                            equ     0C0000164H
STATUS_FLOPPY_ID_MARK_NOT_FOUND                 equ     0C0000165H
STATUS_FLOPPY_WRONG_CYLINDER                    equ     0C0000166H
STATUS_FLOPPY_UNKNOWN_ERROR                     equ     0C0000167H
STATUS_FLOPPY_BAD_REGISTERS                     equ     0C0000168H
STATUS_DISK_RECALIBRATE_FAILED                  equ     0C0000169H
STATUS_DISK_OPERATION_FAILED                    equ     0C000016AH
STATUS_DISK_RESET_FAILED                        equ     0C000016BH
STATUS_SHARED_IRQ_BUSY                          equ     0C000016CH
STATUS_FT_ORPHANING                             equ     0C000016DH
STATUS_BIOS_FAILED_TO_CONNECT_INTERRUPT         equ     0C000016EH
STATUS_PARTITION_FAILURE                        equ     0C0000172H
STATUS_INVALID_BLOCK_LENGTH                     equ     0C0000173H
STATUS_DEVICE_NOT_PARTITIONED                   equ     0C0000174H
STATUS_UNABLE_TO_LOCK_MEDIA                     equ     0C0000175H
STATUS_UNABLE_TO_UNLOAD_MEDIA                   equ     0C0000176H
STATUS_EOM_OVERFLOW                             equ     0C0000177H
STATUS_NO_MEDIA                                 equ     0C0000178H
STATUS_NO_SUCH_MEMBER                           equ     0C000017AH
STATUS_INVALID_MEMBER                           equ     0C000017BH
STATUS_KEY_DELETED                              equ     0C000017CH
STATUS_NO_LOG_SPACE                             equ     0C000017DH
STATUS_TOO_MANY_SIDS                            equ     0C000017EH
STATUS_LM_CROSS_ENCRYPTION_REQUIRED             equ     0C000017FH
STATUS_KEY_HAS_CHILDREN                         equ     0C0000180H
STATUS_CHILD_MUST_BE_VOLATILE                   equ     0C0000181H
STATUS_DEVICE_CONFIGURATION_ERROR               equ     0C0000182H
STATUS_DRIVER_INTERNAL_ERROR                    equ     0C0000183H
STATUS_INVALID_DEVICE_STATE                     equ     0C0000184H
STATUS_IO_DEVICE_ERROR                          equ     0C0000185H
STATUS_DEVICE_PROTOCOL_ERROR                    equ     0C0000186H
STATUS_BACKUP_CONTROLLER                        equ     0C0000187H
STATUS_LOG_FILE_FULL                            equ     0C0000188H
STATUS_TOO_LATE                                 equ     0C0000189H
STATUS_NO_TRUST_LSA_SECRET                      equ     0C000018AH
STATUS_NO_TRUST_SAM_ACCOUNT                     equ     0C000018BH
STATUS_TRUSTED_DOMAIN_FAILURE                   equ     0C000018CH
STATUS_TRUSTED_RELATIONSHIP_FAILURE             equ     0C000018DH
STATUS_EVENTLOG_FILE_CORRUPT                    equ     0C000018EH
STATUS_EVENTLOG_CANT_START                      equ     0C000018FH
STATUS_TRUST_FAILURE                            equ     0C0000190H
STATUS_MUTANT_LIMIT_EXCEEDED                    equ     0C0000191H
STATUS_NETLOGON_NOT_STARTED                     equ     0C0000192H
STATUS_ACCOUNT_EXPIRED                          equ     0C0000193H
STATUS_POSSIBLE_DEADLOCK                        equ     0C0000194H
STATUS_NETWORK_CREDENTIAL_CONFLICT              equ     0C0000195H
STATUS_REMOTE_SESSION_LIMIT                     equ     0C0000196H
STATUS_EVENTLOG_FILE_CHANGED                    equ     0C0000197H
STATUS_NOLOGON_INTERDOMAIN_TRUST_ACCOUNT        equ     0C0000198H
STATUS_NOLOGON_WORKSTATION_TRUST_ACCOUNT        equ     0C0000199H
STATUS_NOLOGON_SERVER_TRUST_ACCOUNT             equ     0C000019AH
STATUS_DOMAIN_TRUST_INCONSISTENT                equ     0C000019BH
STATUS_FS_DRIVER_REQUIRED                       equ     0C000019CH
STATUS_NO_USER_SESSION_KEY                      equ     0C0000202H
STATUS_USER_SESSION_DELETED                     equ     0C0000203H
STATUS_RESOURCE_LANG_NOT_FOUND                  equ     0C0000204H
STATUS_INSUFF_SERVER_RESOURCES                  equ     0C0000205H
STATUS_INVALID_BUFFER_SIZE                      equ     0C0000206H
STATUS_INVALID_ADDRESS_COMPONENT                equ     0C0000207H
STATUS_INVALID_ADDRESS_WILDCARD                 equ     0C0000208H
STATUS_TOO_MANY_ADDRESSES                       equ     0C0000209H
STATUS_ADDRESS_ALREADY_EXISTS                   equ     0C000020AH
STATUS_ADDRESS_CLOSED                           equ     0C000020BH
STATUS_CONNECTION_DISCONNECTED                  equ     0C000020CH
STATUS_CONNECTION_RESET                         equ     0C000020DH
STATUS_TOO_MANY_NODES                           equ     0C000020EH
STATUS_TRANSACTION_ABORTED                      equ     0C000020FH
STATUS_TRANSACTION_TIMED_OUT                    equ     0C0000210H
STATUS_TRANSACTION_NO_RELEASE                   equ     0C0000211H
STATUS_TRANSACTION_NO_MATCH                     equ     0C0000212H
STATUS_TRANSACTION_RESPONDED                    equ     0C0000213H
STATUS_TRANSACTION_INVALID_ID                   equ     0C0000214H
STATUS_TRANSACTION_INVALID_TYPE                 equ     0C0000215H
STATUS_NOT_SERVER_SESSION                       equ     0C0000216H
STATUS_NOT_CLIENT_SESSION                       equ     0C0000217H
STATUS_CANNOT_LOAD_REGISTRY_FILE                equ     0C0000218H
STATUS_DEBUG_ATTACH_FAILED                      equ     0C0000219H
STATUS_SYSTEM_PROCESS_TERMINATED                equ     0C000021AH
STATUS_DATA_NOT_ACCEPTED                        equ     0C000021BH
STATUS_NO_BROWSER_SERVERS_FOUND                 equ     0C000021CH
STATUS_VDM_HARD_ERROR                           equ     0C000021DH
STATUS_DRIVER_CANCEL_TIMEOUT                    equ     0C000021EH
STATUS_REPLY_MESSAGE_MISMATCH                   equ     0C000021FH
STATUS_MAPPED_ALIGNMENT                         equ     0C0000220H
STATUS_IMAGE_CHECKSUM_MISMATCH                  equ     0C0000221H
STATUS_LOST_WRITEBEHIND_DATA                    equ     0C0000222H
STATUS_CLIENT_SERVER_PARAMETERS_INVALID         equ     0C0000223H
STATUS_PASSWORD_MUST_CHANGE                     equ     0C0000224H
STATUS_NOT_FOUND                                equ     0C0000225H
STATUS_NOT_TINY_STREAM                          equ     0C0000226H
STATUS_RECOVERY_FAILURE                         equ     0C0000227H
STATUS_STACK_OVERFLOW_READ                      equ     0C0000228H
STATUS_FAIL_CHECK                               equ     0C0000229H
STATUS_DUPLICATE_OBJECTID                       equ     0C000022AH
STATUS_OBJECTID_EXISTS                          equ     0C000022BH
STATUS_CONVERT_TO_LARGE                         equ     0C000022CH
STATUS_RETRY                                    equ     0C000022DH
STATUS_FOUND_OUT_OF_SCOPE                       equ     0C000022EH
STATUS_ALLOCATE_BUCKET                          equ     0C000022FH
STATUS_PROPSET_NOT_FOUND                        equ     0C0000230H
STATUS_MARSHALL_OVERFLOW                        equ     0C0000231H
STATUS_INVALID_VARIANT                          equ     0C0000232H
STATUS_DOMAIN_CONTROLLER_NOT_FOUND              equ     0C0000233H
STATUS_ACCOUNT_LOCKED_OUT                       equ     0C0000234H
STATUS_HANDLE_NOT_CLOSABLE                      equ     0C0000235H
STATUS_CONNECTION_REFUSED                       equ     0C0000236H
STATUS_GRACEFUL_DISCONNECT                      equ     0C0000237H
STATUS_ADDRESS_ALREADY_ASSOCIATED               equ     0C0000238H
STATUS_ADDRESS_NOT_ASSOCIATED                   equ     0C0000239H
STATUS_CONNECTION_INVALID                       equ     0C000023AH
STATUS_CONNECTION_ACTIVE                        equ     0C000023BH
STATUS_NETWORK_UNREACHABLE                      equ     0C000023CH
STATUS_HOST_UNREACHABLE                         equ     0C000023DH
STATUS_PROTOCOL_UNREACHABLE                     equ     0C000023EH
STATUS_PORT_UNREACHABLE                         equ     0C000023FH
STATUS_REQUEST_ABORTED                          equ     0C0000240H
STATUS_CONNECTION_ABORTED                       equ     0C0000241H
STATUS_BAD_COMPRESSION_BUFFER                   equ     0C0000242H
STATUS_USER_MAPPED_FILE                         equ     0C0000243H
STATUS_AUDIT_FAILED                             equ     0C0000244H
STATUS_TIMER_RESOLUTION_NOT_SET                 equ     0C0000245H
STATUS_CONNECTION_COUNT_LIMIT                   equ     0C0000246H
STATUS_LOGIN_TIME_RESTRICTION                   equ     0C0000247H
STATUS_LOGIN_WKSTA_RESTRICTION                  equ     0C0000248H
STATUS_IMAGE_MP_UP_MISMATCH                     equ     0C0000249H
STATUS_INSUFFICIENT_LOGON_INFO                  equ     0C0000250H
STATUS_BAD_DLL_ENTRYPOINT                       equ     0C0000251H
STATUS_BAD_SERVICE_ENTRYPOINT                   equ     0C0000252H
STATUS_LPC_REPLY_LOST                           equ     0C0000253H
STATUS_IP_ADDRESS_CONFLICT1                     equ     0C0000254H
STATUS_IP_ADDRESS_CONFLICT2                     equ     0C0000255H
STATUS_REGISTRY_QUOTA_LIMIT                     equ     0C0000256H
STATUS_PATH_NOT_COVERED                         equ     0C0000257H
STATUS_NO_CALLBACK_ACTIVE                       equ     0C0000258H
STATUS_LICENSE_QUOTA_EXCEEDED                   equ     0C0000259H
STATUS_PWD_TOO_SHORT                            equ     0C000025AH
STATUS_PWD_TOO_RECENT                           equ     0C000025BH
STATUS_PWD_HISTORY_CONFLICT                     equ     0C000025CH
STATUS_PLUGPLAY_NO_DEVICE                       equ     0C000025EH
STATUS_UNSUPPORTED_COMPRESSION                  equ     0C000025FH
STATUS_INVALID_HW_PROFILE                       equ     0C0000260H
STATUS_INVALID_PLUGPLAY_DEVICE_PATH             equ     0C0000261H
STATUS_DRIVER_ORDINAL_NOT_FOUND                 equ     0C0000262H
STATUS_DRIVER_ENTRYPOINT_NOT_FOUND              equ     0C0000263H
STATUS_RESOURCE_NOT_OWNED                       equ     0C0000264H
STATUS_TOO_MANY_LINKS                           equ     0C0000265H
STATUS_QUOTA_LIST_INCONSISTENT                  equ     0C0000266H
STATUS_FILE_IS_OFFLINE                          equ     0C0000267H
STATUS_EVALUATION_EXPIRATION                    equ     0C0000268H
STATUS_ILLEGAL_DLL_RELOCATION                   equ     0C0000269H
STATUS_LICENSE_VIOLATION                        equ     0C000026AH
STATUS_DLL_INIT_FAILED_LOGOFF                   equ     0C000026BH
STATUS_DRIVER_UNABLE_TO_LOAD                    equ     0C000026CH
STATUS_DFS_UNAVAILABLE                          equ     0C000026DH
STATUS_VOLUME_DISMOUNTED                        equ     0C000026EH
STATUS_WX86_INTERNAL_ERROR                      equ     0C000026FH
STATUS_WX86_FLOAT_STACK_CHECK                   equ     0C0000270H
STATUS_VALIDATE_CONTINUE                        equ     0C0000271H
STATUS_NO_MATCH                                 equ     0C0000272H
STATUS_NO_MORE_MATCHES                          equ     0C0000273H
STATUS_NOT_A_REPARSE_POINT                      equ     0C0000275H
STATUS_IO_REPARSE_TAG_INVALID                   equ     0C0000276H
STATUS_IO_REPARSE_TAG_MISMATCH                  equ     0C0000277H
STATUS_IO_REPARSE_DATA_INVALID                  equ     0C0000278H
STATUS_IO_REPARSE_TAG_NOT_HANDLED               equ     0C0000279H
STATUS_REPARSE_POINT_NOT_RESOLVED               equ     0C0000280H
STATUS_DIRECTORY_IS_A_REPARSE_POINT             equ     0C0000281H
STATUS_RANGE_LIST_CONFLICT                      equ     0C0000282H
STATUS_SOURCE_ELEMENT_EMPTY                     equ     0C0000283H
STATUS_DESTINATION_ELEMENT_FULL                 equ     0C0000284H
STATUS_ILLEGAL_ELEMENT_ADDRESS                  equ     0C0000285H
STATUS_MAGAZINE_NOT_PRESENT                     equ     0C0000286H
STATUS_REINITIALIZATION_NEEDED                  equ     0C0000287H
STATUS_DEVICE_REQUIRES_CLEANING                 equ     080000288H
STATUS_DEVICE_DOOR_OPEN                         equ     080000289H
STATUS_ENCRYPTION_FAILED                        equ     0C000028AH
STATUS_DECRYPTION_FAILED                        equ     0C000028BH
STATUS_RANGE_NOT_FOUND                          equ     0C000028CH
STATUS_NO_RECOVERY_POLICY                       equ     0C000028DH
STATUS_NO_EFS                                   equ     0C000028EH
STATUS_WRONG_EFS                                equ     0C000028FH
STATUS_NO_USER_KEYS                             equ     0C0000290H
STATUS_FILE_NOT_ENCRYPTED                       equ     0C0000291H
STATUS_NOT_EXPORT_FORMAT                        equ     0C0000292H
STATUS_FILE_ENCRYPTED                           equ     0C0000293H
STATUS_WAKE_SYSTEM                              equ     040000294H
STATUS_WMI_GUID_NOT_FOUND                       equ     0C0000295H
STATUS_WMI_INSTANCE_NOT_FOUND                   equ     0C0000296H
STATUS_WMI_ITEMID_NOT_FOUND                     equ     0C0000297H
STATUS_WMI_TRY_AGAIN                            equ     0C0000298H
STATUS_SHARED_POLICY                            equ     0C0000299H
STATUS_POLICY_OBJECT_NOT_FOUND                  equ     0C000029AH
STATUS_POLICY_ONLY_IN_DS                        equ     0C000029BH
STATUS_VOLUME_NOT_UPGRADED                      equ     0C000029CH
STATUS_REMOTE_STORAGE_NOT_ACTIVE                equ     0C000029DH
STATUS_REMOTE_STORAGE_MEDIA_ERROR               equ     0C000029EH
STATUS_NO_TRACKING_SERVICE                      equ     0C000029FH
STATUS_SERVER_SID_MISMATCH                      equ     0C00002A0H
STATUS_DS_NO_ATTRIBUTE_OR_VALUE                 equ     0C00002A1H
STATUS_DS_INVALID_ATTRIBUTE_SYNTAX              equ     0C00002A2H
STATUS_DS_ATTRIBUTE_TYPE_UNDEFINED              equ     0C00002A3H
STATUS_DS_ATTRIBUTE_OR_VALUE_EXISTS             equ     0C00002A4H
STATUS_DS_BUSY                                  equ     0C00002A5H
STATUS_DS_UNAVAILABLE                           equ     0C00002A6H
STATUS_DS_NO_RIDS_ALLOCATED                     equ     0C00002A7H
STATUS_DS_NO_MORE_RIDS                          equ     0C00002A8H
STATUS_DS_INCORRECT_ROLE_OWNER                  equ     0C00002A9H
STATUS_DS_RIDMGR_INIT_ERROR                     equ     0C00002AAH
STATUS_DS_OBJ_CLASS_VIOLATION                   equ     0C00002ABH
STATUS_DS_CANT_ON_NON_LEAF                      equ     0C00002ACH
STATUS_DS_CANT_ON_RDN                           equ     0C00002ADH
STATUS_DS_CANT_MOD_OBJ_CLASS                    equ     0C00002AEH
STATUS_DS_CROSS_DOM_MOVE_FAILED                 equ     0C00002AFH
STATUS_DS_GC_NOT_AVAILABLE                      equ     0C00002B0H
STATUS_DIRECTORY_SERVICE_REQUIRED               equ     0C00002B1H
STATUS_REPARSE_ATTRIBUTE_CONFLICT               equ     0C00002B2H
STATUS_CANT_ENABLE_DENY_ONLY                    equ     0C00002B3H
STATUS_DEVICE_REMOVED                           equ     0C00002B6H
STATUS_JOURNAL_DELETE_IN_PROGRESS               equ     0C00002B7H
STATUS_JOURNAL_NOT_ACTIVE                       equ     0C00002B8H
STATUS_NOINTERFACE                              equ     0C00002B9H
STATUS_DS_ADMIN_LIMIT_EXCEEDED                  equ     0C00002C1H
STATUS_DRIVER_FAILED_SLEEP                      equ     0C00002C2H
STATUS_MUTUAL_AUTHENTICATION_FAILED             equ     0C00002C3H
STATUS_CORRUPT_SYSTEM_FILE                      equ     0C00002C4H
STATUS_DATATYPE_MISALIGNMENT_ERROR              equ     0C00002C5H
STATUS_WMI_READ_ONLY                            equ     0C00002C6H
STATUS_WMI_SET_FAILURE                          equ     0C00002C7H
STATUS_COMMITMENT_MINIMUM                       equ     0C00002C8H
STATUS_TRANSPORT_FULL                           equ     0C00002CAH
STATUS_DS_SAM_INIT_FAILURE                      equ     0C00002CBH
STATUS_ONLY_IF_CONNECTED                        equ     0C00002CCH
STATUS_DS_SENSITIVE_GROUP_VIOLATION             equ     0C00002CDH
STATUS_PNP_RESTART_ENUMERATION                  equ     0C00002CEH
STATUS_JOURNAL_ENTRY_DELETED                    equ     0C00002CFH
STATUS_DS_CANT_MOD_PRIMARYGROUPID               equ     0C00002D0H
STATUS_SYSTEM_IMAGE_BAD_SIGNATURE               equ     0C00002D1H
STATUS_PNP_REBOOT_REQUIRED                      equ     0C00002D2H
STATUS_POWER_STATE_INVALID                      equ     0C00002D3H
STATUS_DS_INVALID_GROUP_TYPE                    equ     0C00002D4H
STATUS_DS_NO_NEST_GLOBALGROUP_IN_MIXEDDOMAIN    equ     0C00002D5H
STATUS_DS_NO_NEST_LOCALGROUP_IN_MIXEDDOMAIN     equ     0C00002D6H
STATUS_DS_GLOBAL_CANT_HAVE_LOCAL_MEMBER         equ     0C00002D7H
STATUS_DS_GLOBAL_CANT_HAVE_UNIVERSAL_MEMBER     equ     0C00002D8H
STATUS_DS_UNIVERSAL_CANT_HAVE_LOCAL_MEMBER      equ     0C00002D9H
STATUS_DS_GLOBAL_CANT_HAVE_CROSSDOMAIN_MEMBER   equ     0C00002DAH
STATUS_DS_LOCAL_CANT_HAVE_CROSSDOMAIN_LOCAL_MEMBER equ  0C00002DBH
STATUS_DS_HAVE_PRIMARY_MEMBERS                  equ     0C00002DCH
STATUS_WMI_NOT_SUPPORTED                        equ     0C00002DDH
STATUS_INSUFFICIENT_POWER                       equ     0C00002DEH
STATUS_SAM_NEED_BOOTKEY_PASSWORD                equ     0C00002DFH
STATUS_SAM_NEED_BOOTKEY_FLOPPY                  equ     0C00002E0H
STATUS_DS_CANT_START                            equ     0C00002E1H
STATUS_DS_INIT_FAILURE                          equ     0C00002E2H
STATUS_SAM_INIT_FAILURE                         equ     0C00002E3H
STATUS_DS_GC_REQUIRED                           equ     0C00002E4H
STATUS_DS_LOCAL_MEMBER_OF_LOCAL_ONLY            equ     0C00002E5H
STATUS_DS_NO_FPO_IN_UNIVERSAL_GROUPS            equ     0C00002E6H
STATUS_DS_MACHINE_ACCOUNT_QUOTA_EXCEEDED        equ     0C00002E7H
STATUS_MULTIPLE_FAULT_VIOLATION                 equ     0C00002E8H
STATUS_CURRENT_DOMAIN_NOT_ALLOWED               equ     0C00002E9H
STATUS_CANNOT_MAKE                              equ     0C00002EAH
STATUS_SYSTEM_SHUTDOWN                          equ     0C00002EBH
STATUS_DS_INIT_FAILURE_CONSOLE                  equ     0C00002ECH
STATUS_DS_SAM_INIT_FAILURE_CONSOLE              equ     0C00002EDH
STATUS_UNFINISHED_CONTEXT_DELETED               equ     0C00002EEH
STATUS_NO_TGT_REPLY                             equ     0C00002EFH
STATUS_OBJECTID_NOT_FOUND                       equ     0C00002F0H
STATUS_NO_IP_ADDRESSES                          equ     0C00002F1H
STATUS_WRONG_CREDENTIAL_HANDLE                  equ     0C00002F2H
STATUS_CRYPTO_SYSTEM_INVALID                    equ     0C00002F3H
STATUS_MAX_REFERRALS_EXCEEDED                   equ     0C00002F4H
STATUS_MUST_BE_KDC                              equ     0C00002F5H
STATUS_STRONG_CRYPTO_NOT_SUPPORTED              equ     0C00002F6H
STATUS_TOO_MANY_PRINCIPALS                      equ     0C00002F7H
STATUS_NO_PA_DATA                               equ     0C00002F8H
STATUS_PKINIT_NAME_MISMATCH                     equ     0C00002F9H
STATUS_SMARTCARD_LOGON_REQUIRED                 equ     0C00002FAH
STATUS_KDC_INVALID_REQUEST                      equ     0C00002FBH
STATUS_KDC_UNABLE_TO_REFER                      equ     0C00002FCH
STATUS_KDC_UNKNOWN_ETYPE                        equ     0C00002FDH
STATUS_SHUTDOWN_IN_PROGRESS                     equ     0C00002FEH
STATUS_SERVER_SHUTDOWN_IN_PROGRESS              equ     0C00002FFH
STATUS_NOT_SUPPORTED_ON_SBS                     equ     0C0000300H
STATUS_WMI_GUID_DISCONNECTED                    equ     0C0000301H
STATUS_WMI_ALREADY_DISABLED                     equ     0C0000302H
STATUS_WMI_ALREADY_ENABLED                      equ     0C0000303H
STATUS_MFT_TOO_FRAGMENTED                       equ     0C0000304H
STATUS_COPY_PROTECTION_FAILURE                  equ     0C0000305H
STATUS_CSS_AUTHENTICATION_FAILURE               equ     0C0000306H
STATUS_CSS_KEY_NOT_PRESENT                      equ     0C0000307H
STATUS_CSS_KEY_NOT_ESTABLISHED                  equ     0C0000308H
STATUS_CSS_SCRAMBLED_SECTOR                     equ     0C0000309H
STATUS_CSS_REGION_MISMATCH                      equ     0C000030AH
STATUS_CSS_RESETS_EXHAUSTED                     equ     0C000030BH
STATUS_PKINIT_FAILURE                           equ     0C0000320H
STATUS_SMARTCARD_SUBSYSTEM_FAILURE              equ     0C0000321H
STATUS_NO_KERB_KEY                              equ     0C0000322H
STATUS_HOST_DOWN                                equ     0C0000350H
STATUS_UNSUPPORTED_PREAUTH                      equ     0C0000351H
STATUS_EFS_ALG_BLOB_TOO_BIG                     equ     0C0000352H
STATUS_PORT_NOT_SET                             equ     0C0000353H
STATUS_DEBUGGER_INACTIVE                        equ     0C0000354H
STATUS_DS_VERSION_CHECK_FAILURE                 equ     0C0000355H
STATUS_AUDITING_DISABLED                        equ     0C0000356H
STATUS_PRENT4_MACHINE_ACCOUNT                   equ     0C0000357H
STATUS_DS_AG_CANT_HAVE_UNIVERSAL_MEMBER         equ     0C0000358H
STATUS_INVALID_IMAGE_WIN_32                     equ     0C0000359H
STATUS_INVALID_IMAGE_WIN_64                     equ     0C000035AH
STATUS_BAD_BINDINGS                             equ     0C000035BH
STATUS_NETWORK_SESSION_EXPIRED                  equ     0C000035CH
STATUS_APPHELP_BLOCK                            equ     0C000035DH
STATUS_ALL_SIDS_FILTERED                        equ     0C000035EH
STATUS_NOT_SAFE_MODE_DRIVER                     equ     0C000035FH
STATUS_ACCESS_DISABLED_BY_POLICY_DEFAULT        equ     0C0000361H
STATUS_ACCESS_DISABLED_BY_POLICY_PATH           equ     0C0000362H
STATUS_ACCESS_DISABLED_BY_POLICY_PUBLISHER      equ     0C0000363H
STATUS_ACCESS_DISABLED_BY_POLICY_OTHER          equ     0C0000364H
STATUS_FAILED_DRIVER_ENTRY                      equ     0C0000365H
STATUS_DEVICE_ENUMERATION_ERROR                 equ     0C0000366H
STATUS_WAIT_FOR_OPLOCK                          equ     000000367H
STATUS_MOUNT_POINT_NOT_RESOLVED                 equ     0C0000368H
STATUS_INVALID_DEVICE_OBJECT_PARAMETER          equ     0C0000369H
STATUS_MCA_OCCURED                              equ     0C000036AH
STATUS_DRIVER_BLOCKED_CRITICAL                  equ     0C000036BH
STATUS_DRIVER_BLOCKED                           equ     0C000036CH
STATUS_DRIVER_DATABASE_ERROR                    equ     0C000036DH
STATUS_SYSTEM_HIVE_TOO_LARGE                    equ     0C000036EH
STATUS_INVALID_IMPORT_OF_NON_DLL                equ     0C000036FH
STATUS_DS_SHUTTING_DOWN                         equ     040000370H
STATUS_SMARTCARD_WRONG_PIN                      equ     0C0000380H
STATUS_SMARTCARD_CARD_BLOCKED                   equ     0C0000381H
STATUS_SMARTCARD_CARD_NOT_AUTHENTICATED         equ     0C0000382H
STATUS_SMARTCARD_NO_CARD                        equ     0C0000383H
STATUS_SMARTCARD_NO_KEY_CONTAINER               equ     0C0000384H
STATUS_SMARTCARD_NO_CERTIFICATE                 equ     0C0000385H
STATUS_SMARTCARD_NO_KEYSET                      equ     0C0000386H
STATUS_SMARTCARD_IO_ERROR                       equ     0C0000387H
STATUS_DOWNGRADE_DETECTED                       equ     0C0000388H
STATUS_SMARTCARD_CERT_REVOKED                   equ     0C0000389H
STATUS_ISSUING_CA_UNTRUSTED                     equ     0C000038AH
STATUS_REVOCATION_OFFLINE_C                     equ     0C000038BH
STATUS_PKINIT_CLIENT_FAILURE                    equ     0C000038CH
STATUS_SMARTCARD_CERT_EXPIRED                   equ     0C000038DH
STATUS_DRIVER_FAILED_PRIOR_UNLOAD               equ     0C000038EH
STATUS_SMARTCARD_SILENT_CONTEXT                 equ     0C000038FH
STATUS_PER_USER_TRUST_QUOTA_EXCEEDED            equ     0C0000401H
STATUS_ALL_USER_TRUST_QUOTA_EXCEEDED            equ     0C0000402H
STATUS_USER_DELETE_TRUST_QUOTA_EXCEEDED         equ     0C0000403H
STATUS_DS_NAME_NOT_UNIQUE                       equ     0C0000404H
STATUS_DS_DUPLICATE_ID_FOUND                    equ     0C0000405H
STATUS_DS_GROUP_CONVERSION_ERROR                equ     0C0000406H
STATUS_VOLSNAP_PREPARE_HIBERNATE                equ     0C0000407H
STATUS_USER2USER_REQUIRED                       equ     0C0000408H
STATUS_STACK_BUFFER_OVERRUN                     equ     0C0000409H
STATUS_NO_S4U_PROT_SUPPORT                      equ     0C000040AH
STATUS_CROSSREALM_DELEGATION_FAILURE            equ     0C000040BH
STATUS_REVOCATION_OFFLINE_KDC                   equ     0C000040CH
STATUS_ISSUING_CA_UNTRUSTED_KDC                 equ     0C000040DH
STATUS_KDC_CERT_EXPIRED                         equ     0C000040EH
STATUS_KDC_CERT_REVOKED                         equ     0C000040FH
STATUS_PARAMETER_QUOTA_EXCEEDED                 equ     0C0000410H
STATUS_HIBERNATION_FAILURE                      equ     0C0000411H
STATUS_DELAY_LOAD_FAILED                        equ     0C0000412H
STATUS_AUTHENTICATION_FIREWALL_FAILED           equ     0C0000413H
STATUS_VDM_DISALLOWED                           equ     0C0000414H
STATUS_HUNG_DISPLAY_DRIVER_THREAD               equ     0C0000415H
STATUS_WOW_ASSERTION                            equ     0C0009898H
ERROR_INVALID_FUNCTION                          equ     1
ERROR_FILE_NOT_FOUND                            equ     2
ERROR_PATH_NOT_FOUND                            equ     3
ERROR_TOO_MANY_OPEN_FILES                       equ     4
ERROR_ACCESS_DENIED                             equ     5
ERROR_INVALID_HANDLE                            equ     6
ERROR_ARENA_TRASHED                             equ     7
ERROR_NOT_ENOUGH_MEMORY                         equ     8
ERROR_INVALID_BLOCK                             equ     9
ERROR_BAD_ENVIRONMENT                           equ     10
ERROR_BAD_FORMAT                                equ     11
ERROR_INVALID_ACCESS                            equ     12
ERROR_INVALID_DATA                              equ     13
ERROR_OUTOFMEMORY                               equ     14
ERROR_INVALID_DRIVE                             equ     15
ERROR_CURRENT_DIRECTORY                         equ     16
ERROR_NOT_SAME_DEVICE                           equ     17
ERROR_NO_MORE_FILES                             equ     18
ERROR_WRITE_PROTECT                             equ     19
ERROR_BAD_UNIT                                  equ     20
ERROR_NOT_READY                                 equ     21
ERROR_BAD_COMMAND                               equ     22
ERROR_CRC                                       equ     23
ERROR_BAD_LENGTH                                equ     24
ERROR_SEEK                                      equ     25
ERROR_NOT_DOS_DISK                              equ     26
ERROR_SECTOR_NOT_FOUND                          equ     27
ERROR_OUT_OF_PAPER                              equ     28
ERROR_WRITE_FAULT                               equ     29
ERROR_READ_FAULT                                equ     30
ERROR_GEN_FAILURE                               equ     31
ERROR_SHARING_VIOLATION                         equ     32
ERROR_LOCK_VIOLATION                            equ     33
ERROR_WRONG_DISK                                equ     34
ERROR_SHARING_BUFFER_EXCEEDED                   equ     36
ERROR_HANDLE_EOF                                equ     38
ERROR_HANDLE_DISK_FULL                          equ     39
ERROR_NOT_SUPPORTED                             equ     50
ERROR_REM_NOT_LIST                              equ     51
ERROR_DUP_NAME                                  equ     52
ERROR_BAD_NETPATH                               equ     53
ERROR_NETWORK_BUSY                              equ     54
ERROR_DEV_NOT_EXIST                             equ     55
ERROR_TOO_MANY_CMDS                             equ     56
ERROR_ADAP_HDW_ERR                              equ     57
ERROR_BAD_NET_RESP                              equ     58
ERROR_UNEXP_NET_ERR                             equ     59
ERROR_BAD_REM_ADAP                              equ     60
ERROR_PRINTQ_FULL                               equ     61
ERROR_NO_SPOOL_SPACE                            equ     62
ERROR_PRINT_CANCELLED                           equ     63
ERROR_NETNAME_DELETED                           equ     64
ERROR_NETWORK_ACCESS_DENIED                     equ     65
ERROR_BAD_DEV_TYPE                              equ     66
ERROR_BAD_NET_NAME                              equ     67
ERROR_TOO_MANY_NAMES                            equ     68
ERROR_TOO_MANY_SESS                             equ     69
ERROR_SHARING_PAUSED                            equ     70
ERROR_REQ_NOT_ACCEP                             equ     71
ERROR_REDIR_PAUSED                              equ     72
ERROR_FILE_EXISTS                               equ     80
ERROR_CANNOT_MAKE                               equ     82
ERROR_FAIL_I24                                  equ     83
ERROR_OUT_OF_STRUCTURES                         equ     84
ERROR_ALREADY_ASSIGNED                          equ     85
ERROR_INVALID_PASSWORD                          equ     86
ERROR_INVALID_PARAMETER                         equ     87
ERROR_NET_WRITE_FAULT                           equ     88
ERROR_NO_PROC_SLOTS                             equ     89
ERROR_TOO_MANY_SEMAPHORES                       equ     100
ERROR_EXCL_SEM_ALREADY_OWNED                    equ     101
ERROR_SEM_IS_SET                                equ     102
ERROR_TOO_MANY_SEM_REQUESTS                     equ     103
ERROR_INVALID_AT_INTERRUPT_TIME                 equ     104
ERROR_SEM_OWNER_DIED                            equ     105
ERROR_SEM_USER_LIMIT                            equ     106
ERROR_DISK_CHANGE                               equ     107
ERROR_DRIVE_LOCKED                              equ     108
ERROR_BROKEN_PIPE                               equ     109
ERROR_OPEN_FAILED                               equ     110
ERROR_BUFFER_OVERFLOW                           equ     111
ERROR_DISK_FULL                                 equ     112
ERROR_NO_MORE_SEARCH_HANDLES                    equ     113
ERROR_INVALID_TARGET_HANDLE                     equ     114
ERROR_INVALID_CATEGORY                          equ     117
ERROR_INVALID_VERIFY_SWITCH                     equ     118
ERROR_BAD_DRIVER_LEVEL                          equ     119
ERROR_CALL_NOT_IMPLEMENTED                      equ     120
ERROR_SEM_TIMEOUT                               equ     121
ERROR_INSUFFICIENT_BUFFER                       equ     122
ERROR_INVALID_NAME                              equ     123
ERROR_INVALID_LEVEL                             equ     124
ERROR_NO_VOLUME_LABEL                           equ     125
ERROR_MOD_NOT_FOUND                             equ     126
ERROR_PROC_NOT_FOUND                            equ     127
ERROR_WAIT_NO_CHILDREN                          equ     128
ERROR_CHILD_NOT_COMPLETE                        equ     129
ERROR_DIRECT_ACCESS_HANDLE                      equ     130
ERROR_NEGATIVE_SEEK                             equ     131
ERROR_SEEK_ON_DEVICE                            equ     132
ERROR_IS_JOIN_TARGET                            equ     133
ERROR_IS_JOINED                                 equ     134
ERROR_IS_SUBSTED                                equ     135
ERROR_NOT_JOINED                                equ     136
ERROR_NOT_SUBSTED                               equ     137
ERROR_JOIN_TO_JOIN                              equ     138
ERROR_SUBST_TO_SUBST                            equ     139
ERROR_JOIN_TO_SUBST                             equ     140
ERROR_SUBST_TO_JOIN                             equ     141
ERROR_BUSY_DRIVE                                equ     142
ERROR_SAME_DRIVE                                equ     143
ERROR_DIR_NOT_ROOT                              equ     144
ERROR_DIR_NOT_EMPTY                             equ     145
ERROR_IS_SUBST_PATH                             equ     146
ERROR_IS_JOIN_PATH                              equ     147
ERROR_PATH_BUSY                                 equ     148
ERROR_IS_SUBST_TARGET                           equ     149
ERROR_SYSTEM_TRACE                              equ     150
ERROR_INVALID_EVENT_COUNT                       equ     151
ERROR_TOO_MANY_MUXWAITERS                       equ     152
ERROR_INVALID_LIST_FORMAT                       equ     153
ERROR_LABEL_TOO_LONG                            equ     154
ERROR_TOO_MANY_TCBS                             equ     155
ERROR_SIGNAL_REFUSED                            equ     156
ERROR_DISCARDED                                 equ     157
ERROR_NOT_LOCKED                                equ     158
ERROR_BAD_THREADID_ADDR                         equ     159
ERROR_BAD_ARGUMENTS                             equ     160
ERROR_BAD_PATHNAME                              equ     161
ERROR_SIGNAL_PENDING                            equ     162
ERROR_MAX_THRDS_REACHED                         equ     164
ERROR_LOCK_FAILED                               equ     167
ERROR_BUSY                                      equ     170
ERROR_CANCEL_VIOLATION                          equ     173
ERROR_ATOMIC_LOCKS_NOT_SUPPORTED                equ     174
ERROR_INVALID_SEGMENT_NUMBER                    equ     180
ERROR_INVALID_ORDINAL                           equ     182
ERROR_ALREADY_EXISTS                            equ     183
ERROR_INVALID_FLAG_NUMBER                       equ     186
ERROR_SEM_NOT_FOUND                             equ     187
ERROR_INVALID_STARTING_CODESEG                  equ     188
ERROR_INVALID_STACKSEG                          equ     189
ERROR_INVALID_MODULETYPE                        equ     190
ERROR_INVALID_EXE_SIGNATURE                     equ     191
ERROR_EXE_MARKED_INVALID                        equ     192
ERROR_BAD_EXE_FORMAT                            equ     193
ERROR_ITERATED_DATA_EXCEEDS_64k                 equ     194
ERROR_INVALID_MINALLOCSIZE                      equ     195
ERROR_DYNLINK_FROM_INVALID_RING                 equ     196
ERROR_IOPL_NOT_ENABLED                          equ     197
ERROR_INVALID_SEGDPL                            equ     198
ERROR_AUTODATASEG_EXCEEDS_64k                   equ     199
ERROR_RING2SEG_MUST_BE_MOVABLE                  equ     200
ERROR_RELOC_CHAIN_XEEDS_SEGLIM                  equ     201
ERROR_INFLOOP_IN_RELOC_CHAIN                    equ     202
ERROR_ENVVAR_NOT_FOUND                          equ     203
ERROR_NO_SIGNAL_SENT                            equ     205
ERROR_FILENAME_EXCED_RANGE                      equ     206
ERROR_RING2_STACK_IN_USE                        equ     207
ERROR_META_EXPANSION_TOO_LONG                   equ     208
ERROR_INVALID_SIGNAL_NUMBER                     equ     209
ERROR_THREAD_1_INACTIVE                         equ     210
ERROR_LOCKED                                    equ     212
ERROR_TOO_MANY_MODULES                          equ     214
ERROR_NESTING_NOT_ALLOWED                       equ     215
ERROR_EXE_MACHINE_TYPE_MISMATCH                 equ     216
ERROR_EXE_CANNOT_MODIFY_SIGNED_BINARY           equ     217
ERROR_EXE_CANNOT_MODIFY_STRONG_SIGNED_BINARY    equ     218
ERROR_FILE_CHECKED_OUT                          equ     220
ERROR_CHECKOUT_REQUIRED                         equ     221
ERROR_BAD_FILE_TYPE                             equ     222
ERROR_FILE_TOO_LARGE                            equ     223
ERROR_FORMS_AUTH_REQUIRED                       equ     224
ERROR_VIRUS_INFECTED                            equ     225
ERROR_VIRUS_DELETED                             equ     226
ERROR_PIPE_LOCAL                                equ     229
ERROR_BAD_PIPE                                  equ     230
ERROR_PIPE_BUSY                                 equ     231
ERROR_NO_DATA                                   equ     232
ERROR_PIPE_NOT_CONNECTED                        equ     233
ERROR_MORE_DATA                                 equ     234
ERROR_VC_DISCONNECTED                           equ     240
ERROR_INVALID_EA_NAME                           equ     254
ERROR_EA_LIST_INCONSISTENT                      equ     255
WAIT_TIMEOUT                                    equ     258
ERROR_NO_MORE_ITEMS                             equ     259
ERROR_CANNOT_COPY                               equ     266
ERROR_DIRECTORY                                 equ     267
ERROR_EAS_DIDNT_FIT                             equ     275
ERROR_EA_FILE_CORRUPT                           equ     276
ERROR_EA_TABLE_FULL                             equ     277
ERROR_INVALID_EA_HANDLE                         equ     278
ERROR_EAS_NOT_SUPPORTED                         equ     282
ERROR_NOT_OWNER                                 equ     288
ERROR_TOO_MANY_POSTS                            equ     298
ERROR_PARTIAL_COPY                              equ     299
ERROR_OPLOCK_NOT_GRANTED                        equ     300
ERROR_INVALID_OPLOCK_PROTOCOL                   equ     301
ERROR_DISK_TOO_FRAGMENTED                       equ     302
ERROR_DELETE_PENDING                            equ     303
ERROR_INCOMPATIBLE_WITH_GLOBAL_SHORT_NAME_REGISTRY_SETTING equ 304
ERROR_SHORT_NAMES_NOT_ENABLED_ON_VOLUME         equ     305
ERROR_SECURITY_STREAM_IS_INCONSISTENT           equ     306
ERROR_INVALID_LOCK_RANGE                        equ     307
ERROR_IMAGE_SUBSYSTEM_NOT_PRESENT               equ     308
ERROR_NOTIFICATION_GUID_ALREADY_DEFINED         equ     309
ERROR_MR_MID_NOT_FOUND                          equ     317
ERROR_SCOPE_NOT_FOUND                           equ     318
ERROR_FAIL_NOACTION_REBOOT                      equ     350
ERROR_FAIL_SHUTDOWN                             equ     351
ERROR_FAIL_RESTART                              equ     352
ERROR_MAX_SESSIONS_REACHED                      equ     353
ERROR_THREAD_MODE_ALREADY_BACKGROUND            equ     400
ERROR_THREAD_MODE_NOT_BACKGROUND                equ     401
ERROR_PROCESS_MODE_ALREADY_BACKGROUND           equ     402
ERROR_PROCESS_MODE_NOT_BACKGROUND               equ     403
ERROR_INVALID_ADDRESS                           equ     487
ERROR_USER_PROFILE_LOAD                         equ     500
ERROR_ARITHMETIC_OVERFLOW                       equ     534
ERROR_PIPE_CONNECTED                            equ     535
ERROR_PIPE_LISTENING                            equ     536
ERROR_VERIFIER_STOP                             equ     537
ERROR_ABIOS_ERROR                               equ     538
ERROR_WX86_WARNING                              equ     539
ERROR_WX86_ERROR                                equ     540
ERROR_TIMER_NOT_CANCELED                        equ     541
ERROR_UNWIND                                    equ     542
ERROR_BAD_STACK                                 equ     543
ERROR_INVALID_UNWIND_TARGET                     equ     544
ERROR_INVALID_PORT_ATTRIBUTES                   equ     545
ERROR_PORT_MESSAGE_TOO_LONG                     equ     546
ERROR_INVALID_QUOTA_LOWER                       equ     547
ERROR_DEVICE_ALREADY_ATTACHED                   equ     548
ERROR_INSTRUCTION_MISALIGNMENT                  equ     549
ERROR_PROFILING_NOT_STARTED                     equ     550
ERROR_PROFILING_NOT_STOPPED                     equ     551
ERROR_COULD_NOT_INTERPRET                       equ     552
ERROR_PROFILING_AT_LIMIT                        equ     553
ERROR_CANT_WAIT                                 equ     554
ERROR_CANT_TERMINATE_SELF                       equ     555
ERROR_UNEXPECTED_MM_CREATE_ERR                  equ     556
ERROR_UNEXPECTED_MM_MAP_ERROR                   equ     557
ERROR_UNEXPECTED_MM_EXTEND_ERR                  equ     558
ERROR_BAD_FUNCTION_TABLE                        equ     559
ERROR_NO_GUID_TRANSLATION                       equ     560
ERROR_INVALID_LDT_SIZE                          equ     561
ERROR_INVALID_LDT_OFFSET                        equ     563
ERROR_INVALID_LDT_DESCRIPTOR                    equ     564
ERROR_TOO_MANY_THREADS                          equ     565
ERROR_THREAD_NOT_IN_PROCESS                     equ     566
ERROR_PAGEFILE_QUOTA_EXCEEDED                   equ     567
ERROR_LOGON_SERVER_CONFLICT                     equ     568
ERROR_SYNCHRONIZATION_REQUIRED                  equ     569
ERROR_NET_OPEN_FAILED                           equ     570
ERROR_IO_PRIVILEGE_FAILED                       equ     571
ERROR_CONTROL_C_EXIT                            equ     572
ERROR_MISSING_SYSTEMFILE                        equ     573
ERROR_UNHANDLED_EXCEPTION                       equ     574
ERROR_APP_INIT_FAILURE                          equ     575
ERROR_PAGEFILE_CREATE_FAILED                    equ     576
ERROR_INVALID_IMAGE_HASH                        equ     577
ERROR_NO_PAGEFILE                               equ     578
ERROR_ILLEGAL_FLOAT_CONTEXT                     equ     579
ERROR_NO_EVENT_PAIR                             equ     580
ERROR_DOMAIN_CTRLR_CONFIG_ERROR                 equ     581
ERROR_ILLEGAL_CHARACTER                         equ     582
ERROR_UNDEFINED_CHARACTER                       equ     583
ERROR_FLOPPY_VOLUME                             equ     584
ERROR_BIOS_FAILED_TO_CONNECT_INTERRUPT          equ     585
ERROR_BACKUP_CONTROLLER                         equ     586
ERROR_MUTANT_LIMIT_EXCEEDED                     equ     587
ERROR_FS_DRIVER_REQUIRED                        equ     588
ERROR_CANNOT_LOAD_REGISTRY_FILE                 equ     589
ERROR_DEBUG_ATTACH_FAILED                       equ     590
ERROR_SYSTEM_PROCESS_TERMINATED                 equ     591
ERROR_DATA_NOT_ACCEPTED                         equ     592
ERROR_VDM_HARD_ERROR                            equ     593
ERROR_DRIVER_CANCEL_TIMEOUT                     equ     594
ERROR_REPLY_MESSAGE_MISMATCH                    equ     595
ERROR_LOST_WRITEBEHIND_DATA                     equ     596
ERROR_CLIENT_SERVER_PARAMETERS_INVALID          equ     597
ERROR_NOT_TINY_STREAM                           equ     598
ERROR_STACK_OVERFLOW_READ                       equ     599
ERROR_CONVERT_TO_LARGE                          equ     600
ERROR_FOUND_OUT_OF_SCOPE                        equ     601
ERROR_ALLOCATE_BUCKET                           equ     602
ERROR_MARSHALL_OVERFLOW                         equ     603
ERROR_INVALID_VARIANT                           equ     604
ERROR_BAD_COMPRESSION_BUFFER                    equ     605
ERROR_AUDIT_FAILED                              equ     606
ERROR_TIMER_RESOLUTION_NOT_SET                  equ     607
ERROR_INSUFFICIENT_LOGON_INFO                   equ     608
ERROR_BAD_DLL_ENTRYPOINT                        equ     609
ERROR_BAD_SERVICE_ENTRYPOINT                    equ     610
ERROR_IP_ADDRESS_CONFLICT1                      equ     611
ERROR_IP_ADDRESS_CONFLICT2                      equ     612
ERROR_REGISTRY_QUOTA_LIMIT                      equ     613
ERROR_NO_CALLBACK_ACTIVE                        equ     614
ERROR_PWD_TOO_SHORT                             equ     615
ERROR_PWD_TOO_RECENT                            equ     616
ERROR_PWD_HISTORY_CONFLICT                      equ     617
ERROR_UNSUPPORTED_COMPRESSION                   equ     618
ERROR_INVALID_HW_PROFILE                        equ     619
ERROR_INVALID_PLUGPLAY_DEVICE_PATH              equ     620
ERROR_QUOTA_LIST_INCONSISTENT                   equ     621
ERROR_EVALUATION_EXPIRATION                     equ     622
ERROR_ILLEGAL_DLL_RELOCATION                    equ     623
ERROR_DLL_INIT_FAILED_LOGOFF                    equ     624
ERROR_VALIDATE_CONTINUE                         equ     625
ERROR_NO_MORE_MATCHES                           equ     626
ERROR_RANGE_LIST_CONFLICT                       equ     627
ERROR_SERVER_SID_MISMATCH                       equ     628
ERROR_CANT_ENABLE_DENY_ONLY                     equ     629
ERROR_FLOAT_MULTIPLE_FAULTS                     equ     630
ERROR_FLOAT_MULTIPLE_TRAPS                      equ     631
ERROR_NOINTERFACE                               equ     632
ERROR_DRIVER_FAILED_SLEEP                       equ     633
ERROR_CORRUPT_SYSTEM_FILE                       equ     634
ERROR_COMMITMENT_MINIMUM                        equ     635
ERROR_PNP_RESTART_ENUMERATION                   equ     636
ERROR_SYSTEM_IMAGE_BAD_SIGNATURE                equ     637
ERROR_PNP_REBOOT_REQUIRED                       equ     638
ERROR_INSUFFICIENT_POWER                        equ     639
ERROR_MULTIPLE_FAULT_VIOLATION                  equ     640
ERROR_SYSTEM_SHUTDOWN                           equ     641
ERROR_PORT_NOT_SET                              equ     642
ERROR_DS_VERSION_CHECK_FAILURE                  equ     643
ERROR_RANGE_NOT_FOUND                           equ     644
ERROR_NOT_SAFE_MODE_DRIVER                      equ     646
ERROR_FAILED_DRIVER_ENTRY                       equ     647
ERROR_DEVICE_ENUMERATION_ERROR                  equ     648
ERROR_MOUNT_POINT_NOT_RESOLVED                  equ     649
ERROR_INVALID_DEVICE_OBJECT_PARAMETER           equ     650
ERROR_MCA_OCCURED                               equ     651
ERROR_DRIVER_DATABASE_ERROR                     equ     652
ERROR_SYSTEM_HIVE_TOO_LARGE                     equ     653
ERROR_DRIVER_FAILED_PRIOR_UNLOAD                equ     654
ERROR_VOLSNAP_PREPARE_HIBERNATE                 equ     655
ERROR_HIBERNATION_FAILURE                       equ     656
ERROR_FILE_SYSTEM_LIMITATION                    equ     665
ERROR_ASSERTION_FAILURE                         equ     668
ERROR_ACPI_ERROR                                equ     669
ERROR_WOW_ASSERTION                             equ     670
ERROR_PNP_BAD_MPS_TABLE                         equ     671
ERROR_PNP_TRANSLATION_FAILED                    equ     672
ERROR_PNP_IRQ_TRANSLATION_FAILED                equ     673
ERROR_PNP_INVALID_ID                            equ     674
ERROR_WAKE_SYSTEM_DEBUGGER                      equ     675
ERROR_HANDLES_CLOSED                            equ     676
ERROR_EXTRANEOUS_INFORMATION                    equ     677
ERROR_RXACT_COMMIT_NECESSARY                    equ     678
ERROR_MEDIA_CHECK                               equ     679
ERROR_GUID_SUBSTITUTION_MADE                    equ     680
ERROR_STOPPED_ON_SYMLINK                        equ     681
ERROR_LONGJUMP                                  equ     682
ERROR_PLUGPLAY_QUERY_VETOED                     equ     683
ERROR_UNWIND_CONSOLIDATE                        equ     684
ERROR_REGISTRY_HIVE_RECOVERED                   equ     685
ERROR_DLL_MIGHT_BE_INSECURE                     equ     686
ERROR_DLL_MIGHT_BE_INCOMPATIBLE                 equ     687
ERROR_DBG_EXCEPTION_NOT_HANDLED                 equ     688
ERROR_DBG_REPLY_LATER                           equ     689
ERROR_DBG_UNABLE_TO_PROVIDE_HANDLE              equ     690
ERROR_DBG_TERMINATE_THREAD                      equ     691
ERROR_DBG_TERMINATE_PROCESS                     equ     692
ERROR_DBG_CONTROL_C                             equ     693
ERROR_DBG_PRINTEXCEPTION_C                      equ     694
ERROR_DBG_RIPEXCEPTION                          equ     695
ERROR_DBG_CONTROL_BREAK                         equ     696
ERROR_DBG_COMMAND_EXCEPTION                     equ     697
ERROR_OBJECT_NAME_EXISTS                        equ     698
ERROR_THREAD_WAS_SUSPENDED                      equ     699
ERROR_IMAGE_NOT_AT_BASE                         equ     700
ERROR_RXACT_STATE_CREATED                       equ     701
ERROR_SEGMENT_NOTIFICATION                      equ     702
ERROR_BAD_CURRENT_DIRECTORY                     equ     703
ERROR_FT_READ_RECOVERY_FROM_BACKUP              equ     704
ERROR_FT_WRITE_RECOVERY                         equ     705
ERROR_IMAGE_MACHINE_TYPE_MISMATCH               equ     706
ERROR_RECEIVE_PARTIAL                           equ     707
ERROR_RECEIVE_EXPEDITED                         equ     708
ERROR_RECEIVE_PARTIAL_EXPEDITED                 equ     709
ERROR_EVENT_DONE                                equ     710
ERROR_EVENT_PENDING                             equ     711
ERROR_CHECKING_FILE_SYSTEM                      equ     712
ERROR_FATAL_APP_EXIT                            equ     713
ERROR_PREDEFINED_HANDLE                         equ     714
ERROR_WAS_UNLOCKED                              equ     715
ERROR_SERVICE_NOTIFICATION                      equ     716
ERROR_WAS_LOCKED                                equ     717
ERROR_LOG_HARD_ERROR                            equ     718
ERROR_ALREADY_WIN32                             equ     719
ERROR_IMAGE_MACHINE_TYPE_MISMATCH_EXE           equ     720
ERROR_NO_YIELD_PERFORMED                        equ     721
ERROR_TIMER_RESUME_IGNORED                      equ     722
ERROR_ARBITRATION_UNHANDLED                     equ     723
ERROR_CARDBUS_NOT_SUPPORTED                     equ     724
ERROR_MP_PROCESSOR_MISMATCH                     equ     725
ERROR_HIBERNATED                                equ     726
ERROR_RESUME_HIBERNATION                        equ     727
ERROR_FIRMWARE_UPDATED                          equ     728
ERROR_DRIVERS_LEAKING_LOCKED_PAGES              equ     729
ERROR_WAKE_SYSTEM                               equ     730
ERROR_WAIT_1                                    equ     731
ERROR_WAIT_2                                    equ     732
ERROR_WAIT_3                                    equ     733
ERROR_WAIT_63                                   equ     734
ERROR_ABANDONED_WAIT_0                          equ     735
ERROR_ABANDONED_WAIT_63                         equ     736
ERROR_USER_APC                                  equ     737
ERROR_KERNEL_APC                                equ     738
ERROR_ALERTED                                   equ     739
ERROR_ELEVATION_REQUIRED                        equ     740
ERROR_REPARSE                                   equ     741
ERROR_OPLOCK_BREAK_IN_PROGRESS                  equ     742
ERROR_VOLUME_MOUNTED                            equ     743
ERROR_RXACT_COMMITTED                           equ     744
ERROR_NOTIFY_CLEANUP                            equ     745
ERROR_PRIMARY_TRANSPORT_CONNECT_FAILED          equ     746
ERROR_PAGE_FAULT_TRANSITION                     equ     747
ERROR_PAGE_FAULT_DEMAND_ZERO                    equ     748
ERROR_PAGE_FAULT_COPY_ON_WRITE                  equ     749
ERROR_PAGE_FAULT_GUARD_PAGE                     equ     750
ERROR_PAGE_FAULT_PAGING_FILE                    equ     751
ERROR_CACHE_PAGE_LOCKED                         equ     752
ERROR_CRASH_DUMP                                equ     753
ERROR_BUFFER_ALL_ZEROS                          equ     754
ERROR_REPARSE_OBJECT                            equ     755
ERROR_RESOURCE_REQUIREMENTS_CHANGED             equ     756
ERROR_TRANSLATION_COMPLETE                      equ     757
ERROR_NOTHING_TO_TERMINATE                      equ     758
ERROR_PROCESS_NOT_IN_JOB                        equ     759
ERROR_PROCESS_IN_JOB                            equ     760
ERROR_VOLSNAP_HIBERNATE_READY                   equ     761
ERROR_FSFILTER_OP_COMPLETED_SUCCESSFULLY        equ     762
ERROR_INTERRUPT_VECTOR_ALREADY_CONNECTED        equ     763
ERROR_INTERRUPT_STILL_CONNECTED                 equ     764
ERROR_WAIT_FOR_OPLOCK                           equ     765
ERROR_DBG_EXCEPTION_HANDLED                     equ     766
ERROR_DBG_CONTINUE                              equ     767
ERROR_CALLBACK_POP_STACK                        equ     768
ERROR_COMPRESSION_DISABLED                      equ     769
ERROR_CANTFETCHBACKWARDS                        equ     770
ERROR_CANTSCROLLBACKWARDS                       equ     771
ERROR_ROWSNOTRELEASED                           equ     772
ERROR_BAD_ACCESSOR_FLAGS                        equ     773
ERROR_ERRORS_ENCOUNTERED                        equ     774
ERROR_NOT_CAPABLE                               equ     775
ERROR_REQUEST_OUT_OF_SEQUENCE                   equ     776
ERROR_VERSION_PARSE_ERROR                       equ     777
ERROR_BADSTARTPOSITION                          equ     778
ERROR_MEMORY_HARDWARE                           equ     779
ERROR_DISK_REPAIR_DISABLED                      equ     780
ERROR_INSUFFICIENT_RESOURCE_FOR_SPECIFIED_SHARED_SECTION_SIZE equ 781
ERROR_SYSTEM_POWERSTATE_TRANSITION              equ     782
ERROR_SYSTEM_POWERSTATE_COMPLEX_TRANSITION      equ     783
ERROR_MCA_EXCEPTION                             equ     784
ERROR_ACCESS_AUDIT_BY_POLICY                    equ     785
ERROR_ACCESS_DISABLED_NO_SAFER_UI_BY_POLICY     equ     786
ERROR_ABANDON_HIBERFILE                         equ     787
ERROR_LOST_WRITEBEHIND_DATA_NETWORK_DISCONNECTED equ 788
ERROR_LOST_WRITEBEHIND_DATA_NETWORK_SERVER_ERROR equ 789
ERROR_LOST_WRITEBEHIND_DATA_LOCAL_DISK_ERROR    equ     790
ERROR_BAD_MCFG_TABLE                            equ     791
ERROR_OPLOCK_SWITCHED_TO_NEW_HANDLE             equ     800
ERROR_CANNOT_GRANT_REQUESTED_OPLOCK             equ     801
ERROR_CANNOT_BREAK_OPLOCK                       equ     802
ERROR_OPLOCK_HANDLE_CLOSED                      equ     803
ERROR_NO_ACE_CONDITION                          equ     804
ERROR_INVALID_ACE_CONDITION                     equ     805
ERROR_EA_ACCESS_DENIED                          equ     994
ERROR_OPERATION_ABORTED                         equ     995
ERROR_IO_INCOMPLETE                             equ     996
ERROR_IO_PENDING                                equ     997
ERROR_NOACCESS                                  equ     998
ERROR_SWAPERROR                                 equ     999
ERROR_STACK_OVERFLOW                            equ     1001
ERROR_INVALID_MESSAGE                           equ     1002
ERROR_CAN_NOT_COMPLETE                          equ     1003
ERROR_INVALID_FLAGS                             equ     1004
ERROR_UNRECOGNIZED_VOLUME                       equ     1005
ERROR_FILE_INVALID                              equ     1006
ERROR_FULLSCREEN_MODE                           equ     1007
ERROR_NO_TOKEN                                  equ     1008
ERROR_BADDB                                     equ     1009
ERROR_BADKEY                                    equ     1010
ERROR_CANTOPEN                                  equ     1011
ERROR_CANTREAD                                  equ     1012
ERROR_CANTWRITE                                 equ     1013
ERROR_REGISTRY_RECOVERED                        equ     1014
ERROR_REGISTRY_CORRUPT                          equ     1015
ERROR_REGISTRY_IO_FAILED                        equ     1016
ERROR_NOT_REGISTRY_FILE                         equ     1017
ERROR_KEY_DELETED                               equ     1018
ERROR_NO_LOG_SPACE                              equ     1019
ERROR_KEY_HAS_CHILDREN                          equ     1020
ERROR_CHILD_MUST_BE_VOLATILE                    equ     1021
ERROR_NOTIFY_ENUM_DIR                           equ     1022
ERROR_DEPENDENT_SERVICES_RUNNING                equ     1051
ERROR_INVALID_SERVICE_CONTROL                   equ     1052
ERROR_SERVICE_REQUEST_TIMEOUT                   equ     1053
ERROR_SERVICE_NO_THREAD                         equ     1054
ERROR_SERVICE_DATABASE_LOCKED                   equ     1055
ERROR_SERVICE_ALREADY_RUNNING                   equ     1056
ERROR_INVALID_SERVICE_ACCOUNT                   equ     1057
ERROR_SERVICE_DISABLED                          equ     1058
ERROR_CIRCULAR_DEPENDENCY                       equ     1059
ERROR_SERVICE_DOES_NOT_EXIST                    equ     1060
ERROR_SERVICE_CANNOT_ACCEPT_CTRL                equ     1061
ERROR_SERVICE_NOT_ACTIVE                        equ     1062
ERROR_FAILED_SERVICE_CONTROLLER_CONNECT         equ     1063
ERROR_EXCEPTION_IN_SERVICE                      equ     1064
ERROR_DATABASE_DOES_NOT_EXIST                   equ     1065
ERROR_SERVICE_SPECIFIC_ERROR                    equ     1066
ERROR_PROCESS_ABORTED                           equ     1067
ERROR_SERVICE_DEPENDENCY_FAIL                   equ     1068
ERROR_SERVICE_LOGON_FAILED                      equ     1069
ERROR_SERVICE_START_HANG                        equ     1070
ERROR_INVALID_SERVICE_LOCK                      equ     1071
ERROR_SERVICE_MARKED_FOR_DELETE                 equ     1072
ERROR_SERVICE_EXISTS                            equ     1073
ERROR_ALREADY_RUNNING_LKG                       equ     1074
ERROR_SERVICE_DEPENDENCY_DELETED                equ     1075
ERROR_BOOT_ALREADY_ACCEPTED                     equ     1076
ERROR_SERVICE_NEVER_STARTED                     equ     1077
ERROR_DUPLICATE_SERVICE_NAME                    equ     1078
ERROR_DIFFERENT_SERVICE_ACCOUNT                 equ     1079
ERROR_CANNOT_DETECT_DRIVER_FAILURE              equ     1080
ERROR_CANNOT_DETECT_PROCESS_ABORT               equ     1081
ERROR_NO_RECOVERY_PROGRAM                       equ     1082
ERROR_SERVICE_NOT_IN_EXE                        equ     1083
ERROR_NOT_SAFEBOOT_SERVICE                      equ     1084
ERROR_END_OF_MEDIA                              equ     1100
ERROR_FILEMARK_DETECTED                         equ     1101
ERROR_BEGINNING_OF_MEDIA                        equ     1102
ERROR_SETMARK_DETECTED                          equ     1103
ERROR_NO_DATA_DETECTED                          equ     1104
ERROR_PARTITION_FAILURE                         equ     1105
ERROR_INVALID_BLOCK_LENGTH                      equ     1106
ERROR_DEVICE_NOT_PARTITIONED                    equ     1107
ERROR_UNABLE_TO_LOCK_MEDIA                      equ     1108
ERROR_UNABLE_TO_UNLOAD_MEDIA                    equ     1109
ERROR_MEDIA_CHANGED                             equ     1110
ERROR_BUS_RESET                                 equ     1111
ERROR_NO_MEDIA_IN_DRIVE                         equ     1112
ERROR_NO_UNICODE_TRANSLATION                    equ     1113
ERROR_DLL_INIT_FAILED                           equ     1114
ERROR_SHUTDOWN_IN_PROGRESS                      equ     1115
ERROR_NO_SHUTDOWN_IN_PROGRESS                   equ     1116
ERROR_IO_DEVICE                                 equ     1117
ERROR_SERIAL_NO_DEVICE                          equ     1118
ERROR_IRQ_BUSY                                  equ     1119
ERROR_MORE_WRITES                               equ     1120
ERROR_COUNTER_TIMEOUT                           equ     1121
ERROR_FLOPPY_ID_MARK_NOT_FOUND                  equ     1122
ERROR_FLOPPY_WRONG_CYLINDER                     equ     1123
ERROR_FLOPPY_UNKNOWN_ERROR                      equ     1124
ERROR_FLOPPY_BAD_REGISTERS                      equ     1125
ERROR_DISK_RECALIBRATE_FAILED                   equ     1126
ERROR_DISK_OPERATION_FAILED                     equ     1127
ERROR_DISK_RESET_FAILED                         equ     1128
ERROR_EOM_OVERFLOW                              equ     1129
ERROR_NOT_ENOUGH_SERVER_MEMORY                  equ     1130
ERROR_POSSIBLE_DEADLOCK                         equ     1131
ERROR_MAPPED_ALIGNMENT                          equ     1132
ERROR_SET_POWER_STATE_VETOED                    equ     1140
ERROR_SET_POWER_STATE_FAILED                    equ     1141
ERROR_TOO_MANY_LINKS                            equ     1142
ERROR_OLD_WIN_VERSION                           equ     1150
ERROR_APP_WRONG_OS                              equ     1151
ERROR_SINGLE_INSTANCE_APP                       equ     1152
ERROR_RMODE_APP                                 equ     1153
ERROR_INVALID_DLL                               equ     1154
ERROR_NO_ASSOCIATION                            equ     1155
ERROR_DDE_FAIL                                  equ     1156
ERROR_DLL_NOT_FOUND                             equ     1157
ERROR_NO_MORE_USER_HANDLES                      equ     1158
ERROR_MESSAGE_SYNC_ONLY                         equ     1159
ERROR_SOURCE_ELEMENT_EMPTY                      equ     1160
ERROR_DESTINATION_ELEMENT_FULL                  equ     1161
ERROR_ILLEGAL_ELEMENT_ADDRESS                   equ     1162
ERROR_MAGAZINE_NOT_PRESENT                      equ     1163
ERROR_DEVICE_REINITIALIZATION_NEEDED            equ     1164
ERROR_DEVICE_REQUIRES_CLEANING                  equ     1165
ERROR_DEVICE_DOOR_OPEN                          equ     1166
ERROR_DEVICE_NOT_CONNECTED                      equ     1167
ERROR_NOT_FOUND                                 equ     1168
ERROR_NO_MATCH                                  equ     1169
ERROR_SET_NOT_FOUND                             equ     1170
ERROR_POINT_NOT_FOUND                           equ     1171
ERROR_NO_TRACKING_SERVICE                       equ     1172
ERROR_NO_VOLUME_ID                              equ     1173
ERROR_UNABLE_TO_REMOVE_REPLACED                 equ     1175
ERROR_UNABLE_TO_MOVE_REPLACEMENT                equ     1176
ERROR_UNABLE_TO_MOVE_REPLACEMENT_2              equ     1177
ERROR_JOURNAL_DELETE_IN_PROGRESS                equ     1178
ERROR_JOURNAL_NOT_ACTIVE                        equ     1179
ERROR_POTENTIAL_FILE_FOUND                      equ     1180
ERROR_JOURNAL_ENTRY_DELETED                     equ     1181
ERROR_SHUTDOWN_IS_SCHEDULED                     equ     1190
ERROR_SHUTDOWN_USERS_LOGGED_ON                  equ     1191
ERROR_BAD_DEVICE                                equ     1200
ERROR_CONNECTION_UNAVAIL                        equ     1201
ERROR_DEVICE_ALREADY_REMEMBERED                 equ     1202
ERROR_NO_NET_OR_BAD_PATH                        equ     1203
ERROR_BAD_PROVIDER                              equ     1204
ERROR_CANNOT_OPEN_PROFILE                       equ     1205
ERROR_BAD_PROFILE                               equ     1206
ERROR_NOT_CONTAINER                             equ     1207
ERROR_EXTENDED_ERROR                            equ     1208
ERROR_INVALID_GROUPNAME                         equ     1209
ERROR_INVALID_COMPUTERNAME                      equ     1210
ERROR_INVALID_EVENTNAME                         equ     1211
ERROR_INVALID_DOMAINNAME                        equ     1212
ERROR_INVALID_SERVICENAME                       equ     1213
ERROR_INVALID_NETNAME                           equ     1214
ERROR_INVALID_SHARENAME                         equ     1215
ERROR_INVALID_PASSWORDNAME                      equ     1216
ERROR_INVALID_MESSAGENAME                       equ     1217
ERROR_INVALID_MESSAGEDEST                       equ     1218
ERROR_SESSION_CREDENTIAL_CONFLICT               equ     1219
ERROR_REMOTE_SESSION_LIMIT_EXCEEDED             equ     1220
ERROR_DUP_DOMAINNAME                            equ     1221
ERROR_NO_NETWORK                                equ     1222
ERROR_CANCELLED                                 equ     1223
ERROR_USER_MAPPED_FILE                          equ     1224
ERROR_CONNECTION_REFUSED                        equ     1225
ERROR_GRACEFUL_DISCONNECT                       equ     1226
ERROR_ADDRESS_ALREADY_ASSOCIATED                equ     1227
ERROR_ADDRESS_NOT_ASSOCIATED                    equ     1228
ERROR_CONNECTION_INVALID                        equ     1229
ERROR_CONNECTION_ACTIVE                         equ     1230
ERROR_NETWORK_UNREACHABLE                       equ     1231
ERROR_HOST_UNREACHABLE                          equ     1232
ERROR_PROTOCOL_UNREACHABLE                      equ     1233
ERROR_PORT_UNREACHABLE                          equ     1234
ERROR_REQUEST_ABORTED                           equ     1235
ERROR_CONNECTION_ABORTED                        equ     1236
ERROR_RETRY                                     equ     1237
ERROR_CONNECTION_COUNT_LIMIT                    equ     1238
ERROR_LOGIN_TIME_RESTRICTION                    equ     1239
ERROR_LOGIN_WKSTA_RESTRICTION                   equ     1240
ERROR_INCORRECT_ADDRESS                         equ     1241
ERROR_ALREADY_REGISTERED                        equ     1242
ERROR_SERVICE_NOT_FOUND                         equ     1243
ERROR_NOT_AUTHENTICATED                         equ     1244
ERROR_NOT_LOGGED_ON                             equ     1245
ERROR_CONTINUE                                  equ     1246
ERROR_ALREADY_INITIALIZED                       equ     1247
ERROR_NO_MORE_DEVICES                           equ     1248
ERROR_NO_SUCH_SITE                              equ     1249
ERROR_DOMAIN_CONTROLLER_EXISTS                  equ     1250
ERROR_ONLY_IF_CONNECTED                         equ     1251
ERROR_OVERRIDE_NOCHANGES                        equ     1252
ERROR_BAD_USER_PROFILE                          equ     1253
ERROR_NOT_SUPPORTED_ON_SBS                      equ     1254
ERROR_SERVER_SHUTDOWN_IN_PROGRESS               equ     1255
ERROR_HOST_DOWN                                 equ     1256
ERROR_NON_ACCOUNT_SID                           equ     1257
ERROR_NON_DOMAIN_SID                            equ     1258
ERROR_APPHELP_BLOCK                             equ     1259
ERROR_ACCESS_DISABLED_BY_POLICY                 equ     1260
ERROR_REG_NAT_CONSUMPTION                       equ     1261
ERROR_CSCSHARE_OFFLINE                          equ     1262
ERROR_PKINIT_FAILURE                            equ     1263
ERROR_SMARTCARD_SUBSYSTEM_FAILURE               equ     1264
ERROR_DOWNGRADE_DETECTED                        equ     1265
ERROR_MACHINE_LOCKED                            equ     1271
ERROR_CALLBACK_SUPPLIED_INVALID_DATA            equ     1273
ERROR_SYNC_FOREGROUND_REFRESH_REQUIRED          equ     1274
ERROR_DRIVER_BLOCKED                            equ     1275
ERROR_INVALID_IMPORT_OF_NON_DLL                 equ     1276
ERROR_ACCESS_DISABLED_WEBBLADE                  equ     1277
ERROR_ACCESS_DISABLED_WEBBLADE_TAMPER           equ     1278
ERROR_RECOVERY_FAILURE                          equ     1279
ERROR_ALREADY_FIBER                             equ     1280
ERROR_ALREADY_THREAD                            equ     1281
ERROR_STACK_BUFFER_OVERRUN                      equ     1282
ERROR_PARAMETER_QUOTA_EXCEEDED                  equ     1283
ERROR_DEBUGGER_INACTIVE                         equ     1284
ERROR_DELAY_LOAD_FAILED                         equ     1285
ERROR_VDM_DISALLOWED                            equ     1286
ERROR_UNIDENTIFIED_ERROR                        equ     1287
ERROR_INVALID_CRUNTIME_PARAMETER                equ     1288
ERROR_BEYOND_VDL                                equ     1289
ERROR_INCOMPATIBLE_SERVICE_SID_TYPE             equ     1290
ERROR_DRIVER_PROCESS_TERMINATED                 equ     1291
ERROR_IMPLEMENTATION_LIMIT                      equ     1292
ERROR_PROCESS_IS_PROTECTED                      equ     1293
ERROR_SERVICE_NOTIFY_CLIENT_LAGGING             equ     1294
ERROR_DISK_QUOTA_EXCEEDED                       equ     1295
ERROR_CONTENT_BLOCKED                           equ     1296
ERROR_INCOMPATIBLE_SERVICE_PRIVILEGE            equ     1297
ERROR_APP_HANG                                  equ     1298
ERROR_INVALID_LABEL                             equ     1299
ERROR_NOT_ALL_ASSIGNED                          equ     1300
ERROR_SOME_NOT_MAPPED                           equ     1301
ERROR_NO_QUOTAS_FOR_ACCOUNT                     equ     1302
ERROR_LOCAL_USER_SESSION_KEY                    equ     1303
ERROR_NULL_LM_PASSWORD                          equ     1304
ERROR_UNKNOWN_REVISION                          equ     1305
ERROR_REVISION_MISMATCH                         equ     1306
ERROR_INVALID_OWNER                             equ     1307
ERROR_INVALID_PRIMARY_GROUP                     equ     1308
ERROR_NO_IMPERSONATION_TOKEN                    equ     1309
ERROR_CANT_DISABLE_MANDATORY                    equ     1310
ERROR_NO_LOGON_SERVERS                          equ     1311
ERROR_NO_SUCH_LOGON_SESSION                     equ     1312
ERROR_NO_SUCH_PRIVILEGE                         equ     1313
ERROR_PRIVILEGE_NOT_HELD                        equ     1314
ERROR_INVALID_ACCOUNT_NAME                      equ     1315
ERROR_USER_EXISTS                               equ     1316
ERROR_NO_SUCH_USER                              equ     1317
ERROR_GROUP_EXISTS                              equ     1318
ERROR_NO_SUCH_GROUP                             equ     1319
ERROR_MEMBER_IN_GROUP                           equ     1320
ERROR_MEMBER_NOT_IN_GROUP                       equ     1321
ERROR_LAST_ADMIN                                equ     1322
ERROR_WRONG_PASSWORD                            equ     1323
ERROR_ILL_FORMED_PASSWORD                       equ     1324
ERROR_PASSWORD_RESTRICTION                      equ     1325
ERROR_LOGON_FAILURE                             equ     1326
ERROR_ACCOUNT_RESTRICTION                       equ     1327
ERROR_INVALID_LOGON_HOURS                       equ     1328
ERROR_INVALID_WORKSTATION                       equ     1329
ERROR_PASSWORD_EXPIRED                          equ     1330
ERROR_ACCOUNT_DISABLED                          equ     1331
ERROR_NONE_MAPPED                               equ     1332
ERROR_TOO_MANY_LUIDS_REQUESTED                  equ     1333
ERROR_LUIDS_EXHAUSTED                           equ     1334
ERROR_INVALID_SUB_AUTHORITY                     equ     1335
ERROR_INVALID_ACL                               equ     1336
ERROR_INVALID_SID                               equ     1337
ERROR_INVALID_SECURITY_DESCR                    equ     1338
ERROR_BAD_INHERITANCE_ACL                       equ     1340
ERROR_SERVER_DISABLED                           equ     1341
ERROR_SERVER_NOT_DISABLED                       equ     1342
ERROR_INVALID_ID_AUTHORITY                      equ     1343
ERROR_ALLOTTED_SPACE_EXCEEDED                   equ     1344
ERROR_INVALID_GROUP_ATTRIBUTES                  equ     1345
ERROR_BAD_IMPERSONATION_LEVEL                   equ     1346
ERROR_CANT_OPEN_ANONYMOUS                       equ     1347
ERROR_BAD_VALIDATION_CLASS                      equ     1348
ERROR_BAD_TOKEN_TYPE                            equ     1349
ERROR_NO_SECURITY_ON_OBJECT                     equ     1350
ERROR_CANT_ACCESS_DOMAIN_INFO                   equ     1351
ERROR_INVALID_SERVER_STATE                      equ     1352
ERROR_INVALID_DOMAIN_STATE                      equ     1353
ERROR_INVALID_DOMAIN_ROLE                       equ     1354
ERROR_NO_SUCH_DOMAIN                            equ     1355
ERROR_DOMAIN_EXISTS                             equ     1356
ERROR_DOMAIN_LIMIT_EXCEEDED                     equ     1357
ERROR_INTERNAL_DB_CORRUPTION                    equ     1358
ERROR_INTERNAL_ERROR                            equ     1359
ERROR_GENERIC_NOT_MAPPED                        equ     1360
ERROR_BAD_DESCRIPTOR_FORMAT                     equ     1361
ERROR_NOT_LOGON_PROCESS                         equ     1362
ERROR_LOGON_SESSION_EXISTS                      equ     1363
ERROR_NO_SUCH_PACKAGE                           equ     1364
ERROR_BAD_LOGON_SESSION_STATE                   equ     1365
ERROR_LOGON_SESSION_COLLISION                   equ     1366
ERROR_INVALID_LOGON_TYPE                        equ     1367
ERROR_CANNOT_IMPERSONATE                        equ     1368
ERROR_RXACT_INVALID_STATE                       equ     1369
ERROR_RXACT_COMMIT_FAILURE                      equ     1370
ERROR_SPECIAL_ACCOUNT                           equ     1371
ERROR_SPECIAL_GROUP                             equ     1372
ERROR_SPECIAL_USER                              equ     1373
ERROR_MEMBERS_PRIMARY_GROUP                     equ     1374
ERROR_TOKEN_ALREADY_IN_USE                      equ     1375
ERROR_NO_SUCH_ALIAS                             equ     1376
ERROR_MEMBER_NOT_IN_ALIAS                       equ     1377
ERROR_MEMBER_IN_ALIAS                           equ     1378
ERROR_ALIAS_EXISTS                              equ     1379
ERROR_LOGON_NOT_GRANTED                         equ     1380
ERROR_TOO_MANY_SECRETS                          equ     1381
ERROR_SECRET_TOO_LONG                           equ     1382
ERROR_INTERNAL_DB_ERROR                         equ     1383
ERROR_TOO_MANY_CONTEXT_IDS                      equ     1384
ERROR_LOGON_TYPE_NOT_GRANTED                    equ     1385
ERROR_NT_CROSS_ENCRYPTION_REQUIRED              equ     1386
ERROR_NO_SUCH_MEMBER                            equ     1387
ERROR_INVALID_MEMBER                            equ     1388
ERROR_TOO_MANY_SIDS                             equ     1389
ERROR_LM_CROSS_ENCRYPTION_REQUIRED              equ     1390
ERROR_NO_INHERITANCE                            equ     1391
ERROR_FILE_CORRUPT                              equ     1392
ERROR_DISK_CORRUPT                              equ     1393
ERROR_NO_USER_SESSION_KEY                       equ     1394
ERROR_LICENSE_QUOTA_EXCEEDED                    equ     1395
ERROR_WRONG_TARGET_NAME                         equ     1396
ERROR_MUTUAL_AUTH_FAILED                        equ     1397
ERROR_TIME_SKEW                                 equ     1398
ERROR_CURRENT_DOMAIN_NOT_ALLOWED                equ     1399
ERROR_INVALID_WINDOW_HANDLE                     equ     1400
ERROR_INVALID_MENU_HANDLE                       equ     1401
ERROR_INVALID_CURSOR_HANDLE                     equ     1402
ERROR_INVALID_ACCEL_HANDLE                      equ     1403
ERROR_INVALID_HOOK_HANDLE                       equ     1404
ERROR_INVALID_DWP_HANDLE                        equ     1405
ERROR_TLW_WITH_WSCHILD                          equ     1406
ERROR_CANNOT_FIND_WND_CLASS                     equ     1407
ERROR_WINDOW_OF_OTHER_THREAD                    equ     1408
ERROR_HOTKEY_ALREADY_REGISTERED                 equ     1409
ERROR_CLASS_ALREADY_EXISTS                      equ     1410
ERROR_CLASS_DOES_NOT_EXIST                      equ     1411
ERROR_CLASS_HAS_WINDOWS                         equ     1412
ERROR_INVALID_INDEX                             equ     1413
ERROR_INVALID_ICON_HANDLE                       equ     1414
ERROR_PRIVATE_DIALOG_INDEX                      equ     1415
ERROR_LISTBOX_ID_NOT_FOUND                      equ     1416
ERROR_NO_WILDCARD_CHARACTERS                    equ     1417
ERROR_CLIPBOARD_NOT_OPEN                        equ     1418
ERROR_HOTKEY_NOT_REGISTERED                     equ     1419
ERROR_WINDOW_NOT_DIALOG                         equ     1420
ERROR_CONTROL_ID_NOT_FOUND                      equ     1421
ERROR_INVALID_COMBOBOX_MESSAGE                  equ     1422
ERROR_WINDOW_NOT_COMBOBOX                       equ     1423
ERROR_INVALID_EDIT_HEIGHT                       equ     1424
ERROR_DC_NOT_FOUND                              equ     1425
ERROR_INVALID_HOOK_FILTER                       equ     1426
ERROR_INVALID_FILTER_PROC                       equ     1427
ERROR_HOOK_NEEDS_HMOD                           equ     1428
ERROR_GLOBAL_ONLY_HOOK                          equ     1429
ERROR_JOURNAL_HOOK_SET                          equ     1430
ERROR_HOOK_NOT_INSTALLED                        equ     1431
ERROR_INVALID_LB_MESSAGE                        equ     1432
ERROR_SETCOUNT_ON_BAD_LB                        equ     1433
ERROR_LB_WITHOUT_TABSTOPS                       equ     1434
ERROR_DESTROY_OBJECT_OF_OTHER_THREAD            equ     1435
ERROR_CHILD_WINDOW_MENU                         equ     1436
ERROR_NO_SYSTEM_MENU                            equ     1437
ERROR_INVALID_MSGBOX_STYLE                      equ     1438
ERROR_INVALID_SPI_VALUE                         equ     1439
ERROR_SCREEN_ALREADY_LOCKED                     equ     1440
ERROR_HWNDS_HAVE_DIFF_PARENT                    equ     1441
ERROR_NOT_CHILD_WINDOW                          equ     1442
ERROR_INVALID_GW_COMMAND                        equ     1443
ERROR_INVALID_THREAD_ID                         equ     1444
ERROR_NON_MDICHILD_WINDOW                       equ     1445
ERROR_POPUP_ALREADY_ACTIVE                      equ     1446
ERROR_NO_SCROLLBARS                             equ     1447
ERROR_INVALID_SCROLLBAR_RANGE                   equ     1448
ERROR_INVALID_SHOWWIN_COMMAND                   equ     1449
ERROR_NO_SYSTEM_RESOURCES                       equ     1450
ERROR_NONPAGED_SYSTEM_RESOURCES                 equ     1451
ERROR_PAGED_SYSTEM_RESOURCES                    equ     1452
ERROR_WORKING_SET_QUOTA                         equ     1453
ERROR_PAGEFILE_QUOTA                            equ     1454
ERROR_COMMITMENT_LIMIT                          equ     1455
ERROR_MENU_ITEM_NOT_FOUND                       equ     1456
ERROR_INVALID_KEYBOARD_HANDLE                   equ     1457
ERROR_HOOK_TYPE_NOT_ALLOWED                     equ     1458
ERROR_REQUIRES_INTERACTIVE_WINDOWSTATION        equ     1459
ERROR_TIMEOUT                                   equ     1460
ERROR_INVALID_MONITOR_HANDLE                    equ     1461
ERROR_INCORRECT_SIZE                            equ     1462
ERROR_SYMLINK_CLASS_DISABLED                    equ     1463
ERROR_SYMLINK_NOT_SUPPORTED                     equ     1464
ERROR_XML_PARSE_ERROR                           equ     1465
ERROR_XMLDSIG_ERROR                             equ     1466
ERROR_RESTART_APPLICATION                       equ     1467
ERROR_WRONG_COMPARTMENT                         equ     1468
ERROR_AUTHIP_FAILURE                            equ     1469
ERROR_NO_NVRAM_RESOURCES                        equ     1470
ERROR_EVENTLOG_FILE_CORRUPT                     equ     1500
ERROR_EVENTLOG_CANT_START                       equ     1501
ERROR_LOG_FILE_FULL                             equ     1502
ERROR_EVENTLOG_FILE_CHANGED                     equ     1503
ERROR_INVALID_TASK_NAME                         equ     1550
ERROR_INVALID_TASK_INDEX                        equ     1551
ERROR_THREAD_ALREADY_IN_TASK                    equ     1552
ERROR_INSTALL_SERVICE_FAILURE                   equ     1601
ERROR_INSTALL_USEREXIT                          equ     1602
ERROR_INSTALL_FAILURE                           equ     1603
ERROR_INSTALL_SUSPEND                           equ     1604
ERROR_UNKNOWN_PRODUCT                           equ     1605
ERROR_UNKNOWN_FEATURE                           equ     1606
ERROR_UNKNOWN_COMPONENT                         equ     1607
ERROR_UNKNOWN_PROPERTY                          equ     1608
ERROR_INVALID_HANDLE_STATE                      equ     1609
ERROR_BAD_CONFIGURATION                         equ     1610
ERROR_INDEX_ABSENT                              equ     1611
ERROR_INSTALL_SOURCE_ABSENT                     equ     1612
ERROR_INSTALL_PACKAGE_VERSION                   equ     1613
ERROR_PRODUCT_UNINSTALLED                       equ     1614
ERROR_BAD_QUERY_SYNTAX                          equ     1615
ERROR_INVALID_FIELD                             equ     1616
ERROR_DEVICE_REMOVED                            equ     1617
ERROR_INSTALL_ALREADY_RUNNING                   equ     1618
ERROR_INSTALL_PACKAGE_OPEN_FAILED               equ     1619
ERROR_INSTALL_PACKAGE_INVALID                   equ     1620
ERROR_INSTALL_UI_FAILURE                        equ     1621
ERROR_INSTALL_LOG_FAILURE                       equ     1622
ERROR_INSTALL_LANGUAGE_UNSUPPORTED              equ     1623
ERROR_INSTALL_TRANSFORM_FAILURE                 equ     1624
ERROR_INSTALL_PACKAGE_REJECTED                  equ     1625
ERROR_FUNCTION_NOT_CALLED                       equ     1626
ERROR_FUNCTION_FAILED                           equ     1627
ERROR_INVALID_TABLE                             equ     1628
ERROR_DATATYPE_MISMATCH                         equ     1629
ERROR_UNSUPPORTED_TYPE                          equ     1630
ERROR_CREATE_FAILED                             equ     1631
ERROR_INSTALL_TEMP_UNWRITABLE                   equ     1632
ERROR_INSTALL_PLATFORM_UNSUPPORTED              equ     1633
ERROR_INSTALL_NOTUSED                           equ     1634
ERROR_PATCH_PACKAGE_OPEN_FAILED                 equ     1635
ERROR_PATCH_PACKAGE_INVALID                     equ     1636
ERROR_PATCH_PACKAGE_UNSUPPORTED                 equ     1637
ERROR_PRODUCT_VERSION                           equ     1638
ERROR_INVALID_COMMAND_LINE                      equ     1639
ERROR_INSTALL_REMOTE_DISALLOWED                 equ     1640
ERROR_SUCCESS_REBOOT_INITIATED                  equ     1641
ERROR_PATCH_TARGET_NOT_FOUND                    equ     1642
ERROR_PATCH_PACKAGE_REJECTED                    equ     1643
ERROR_INSTALL_TRANSFORM_REJECTED                equ     1644
ERROR_INSTALL_REMOTE_PROHIBITED                 equ     1645
ERROR_PATCH_REMOVAL_UNSUPPORTED                 equ     1646
ERROR_UNKNOWN_PATCH                             equ     1647
ERROR_PATCH_NO_SEQUENCE                         equ     1648
ERROR_PATCH_REMOVAL_DISALLOWED                  equ     1649
ERROR_INVALID_PATCH_XML                         equ     1650
ERROR_PATCH_MANAGED_ADVERTISED_PRODUCT          equ     1651
ERROR_INSTALL_SERVICE_SAFEBOOT                  equ     1652
ERROR_FAIL_FAST_EXCEPTION                       equ     1653
RPC_S_INVALID_STRING_BINDING                    equ     1700
RPC_S_WRONG_KIND_OF_BINDING                     equ     1701
RPC_S_INVALID_BINDING                           equ     1702
RPC_S_PROTSEQ_NOT_SUPPORTED                     equ     1703
RPC_S_INVALID_RPC_PROTSEQ                       equ     1704
RPC_S_INVALID_STRING_UUID                       equ     1705
RPC_S_INVALID_ENDPOINT_FORMAT                   equ     1706
RPC_S_INVALID_NET_ADDR                          equ     1707
RPC_S_NO_ENDPOINT_FOUND                         equ     1708
RPC_S_INVALID_TIMEOUT                           equ     1709
RPC_S_OBJECT_NOT_FOUND                          equ     1710
RPC_S_ALREADY_REGISTERED                        equ     1711
RPC_S_TYPE_ALREADY_REGISTERED                   equ     1712
RPC_S_ALREADY_LISTENING                         equ     1713
RPC_S_NO_PROTSEQS_REGISTERED                    equ     1714
RPC_S_NOT_LISTENING                             equ     1715
RPC_S_UNKNOWN_MGR_TYPE                          equ     1716
RPC_S_UNKNOWN_IF                                equ     1717
RPC_S_NO_BINDINGS                               equ     1718
RPC_S_NO_PROTSEQS                               equ     1719
RPC_S_CANT_CREATE_ENDPOINT                      equ     1720
RPC_S_OUT_OF_RESOURCES                          equ     1721
RPC_S_SERVER_UNAVAILABLE                        equ     1722
RPC_S_SERVER_TOO_BUSY                           equ     1723
RPC_S_INVALID_NETWORK_OPTIONS                   equ     1724
RPC_S_NO_CALL_ACTIVE                            equ     1725
RPC_S_CALL_FAILED                               equ     1726
RPC_S_CALL_FAILED_DNE                           equ     1727
RPC_S_PROTOCOL_ERROR                            equ     1728
RPC_S_PROXY_ACCESS_DENIED                       equ     1729
RPC_S_UNSUPPORTED_TRANS_SYN                     equ     1730
RPC_S_UNSUPPORTED_TYPE                          equ     1732
RPC_S_INVALID_TAG                               equ     1733
RPC_S_INVALID_BOUND                             equ     1734
RPC_S_NO_ENTRY_NAME                             equ     1735
RPC_S_INVALID_NAME_SYNTAX                       equ     1736
RPC_S_UNSUPPORTED_NAME_SYNTAX                   equ     1737
RPC_S_UUID_NO_ADDRESS                           equ     1739
RPC_S_DUPLICATE_ENDPOINT                        equ     1740
RPC_S_UNKNOWN_AUTHN_TYPE                        equ     1741
RPC_S_MAX_CALLS_TOO_SMALL                       equ     1742
RPC_S_STRING_TOO_LONG                           equ     1743
RPC_S_PROTSEQ_NOT_FOUND                         equ     1744
RPC_S_PROCNUM_OUT_OF_RANGE                      equ     1745
RPC_S_BINDING_HAS_NO_AUTH                       equ     1746
RPC_S_UNKNOWN_AUTHN_SERVICE                     equ     1747
RPC_S_UNKNOWN_AUTHN_LEVEL                       equ     1748
RPC_S_INVALID_AUTH_IDENTITY                     equ     1749
RPC_S_UNKNOWN_AUTHZ_SERVICE                     equ     1750
EPT_S_INVALID_ENTRY                             equ     1751
EPT_S_CANT_PERFORM_OP                           equ     1752
EPT_S_NOT_REGISTERED                            equ     1753
RPC_S_NOTHING_TO_EXPORT                         equ     1754
RPC_S_INCOMPLETE_NAME                           equ     1755
RPC_S_INVALID_VERS_OPTION                       equ     1756
RPC_S_NO_MORE_MEMBERS                           equ     1757
RPC_S_NOT_ALL_OBJS_UNEXPORTED                   equ     1758
RPC_S_INTERFACE_NOT_FOUND                       equ     1759
RPC_S_ENTRY_ALREADY_EXISTS                      equ     1760
RPC_S_ENTRY_NOT_FOUND                           equ     1761
RPC_S_NAME_SERVICE_UNAVAILABLE                  equ     1762
RPC_S_INVALID_NAF_ID                            equ     1763
RPC_S_CANNOT_SUPPORT                            equ     1764
RPC_S_NO_CONTEXT_AVAILABLE                      equ     1765
RPC_S_INTERNAL_ERROR                            equ     1766
RPC_S_ZERO_DIVIDE                               equ     1767
RPC_S_ADDRESS_ERROR                             equ     1768
RPC_S_FP_DIV_ZERO                               equ     1769
RPC_S_FP_UNDERFLOW                              equ     1770
RPC_S_FP_OVERFLOW                               equ     1771
RPC_X_NO_MORE_ENTRIES                           equ     1772
RPC_X_SS_CHAR_TRANS_OPEN_FAIL                   equ     1773
RPC_X_SS_CHAR_TRANS_SHORT_FILE                  equ     1774
RPC_X_SS_IN_NULL_CONTEXT                        equ     1775
RPC_X_SS_CONTEXT_DAMAGED                        equ     1777
RPC_X_SS_HANDLES_MISMATCH                       equ     1778
RPC_X_SS_CANNOT_GET_CALL_HANDLE                 equ     1779
RPC_X_NULL_REF_POINTER                          equ     1780
RPC_X_ENUM_VALUE_OUT_OF_RANGE                   equ     1781
RPC_X_BYTE_COUNT_TOO_SMALL                      equ     1782
RPC_X_BAD_STUB_DATA                             equ     1783
ERROR_INVALID_USER_BUFFER                       equ     1784
ERROR_UNRECOGNIZED_MEDIA                        equ     1785
ERROR_NO_TRUST_LSA_SECRET                       equ     1786
ERROR_NO_TRUST_SAM_ACCOUNT                      equ     1787
ERROR_TRUSTED_DOMAIN_FAILURE                    equ     1788
ERROR_TRUSTED_RELATIONSHIP_FAILURE              equ     1789
ERROR_TRUST_FAILURE                             equ     1790
RPC_S_CALL_IN_PROGRESS                          equ     1791
ERROR_NETLOGON_NOT_STARTED                      equ     1792
ERROR_ACCOUNT_EXPIRED                           equ     1793
ERROR_REDIRECTOR_HAS_OPEN_HANDLES               equ     1794
ERROR_PRINTER_DRIVER_ALREADY_INSTALLED          equ     1795
ERROR_UNKNOWN_PORT                              equ     1796
ERROR_UNKNOWN_PRINTER_DRIVER                    equ     1797
ERROR_UNKNOWN_PRINTPROCESSOR                    equ     1798
ERROR_INVALID_SEPARATOR_FILE                    equ     1799
ERROR_INVALID_PRIORITY                          equ     1800
ERROR_INVALID_PRINTER_NAME                      equ     1801
ERROR_PRINTER_ALREADY_EXISTS                    equ     1802
ERROR_INVALID_PRINTER_COMMAND                   equ     1803
ERROR_INVALID_DATATYPE                          equ     1804
ERROR_INVALID_ENVIRONMENT                       equ     1805
RPC_S_NO_MORE_BINDINGS                          equ     1806
ERROR_NOLOGON_INTERDOMAIN_TRUST_ACCOUNT         equ     1807
ERROR_NOLOGON_WORKSTATION_TRUST_ACCOUNT         equ     1808
ERROR_NOLOGON_SERVER_TRUST_ACCOUNT              equ     1809
ERROR_DOMAIN_TRUST_INCONSISTENT                 equ     1810
ERROR_SERVER_HAS_OPEN_HANDLES                   equ     1811
ERROR_RESOURCE_DATA_NOT_FOUND                   equ     1812
ERROR_RESOURCE_TYPE_NOT_FOUND                   equ     1813
ERROR_RESOURCE_NAME_NOT_FOUND                   equ     1814
ERROR_RESOURCE_LANG_NOT_FOUND                   equ     1815
ERROR_NOT_ENOUGH_QUOTA                          equ     1816
RPC_S_NO_INTERFACES                             equ     1817
RPC_S_CALL_CANCELLED                            equ     1818
RPC_S_BINDING_INCOMPLETE                        equ     1819
RPC_S_COMM_FAILURE                              equ     1820
RPC_S_UNSUPPORTED_AUTHN_LEVEL                   equ     1821
RPC_S_NO_PRINC_NAME                             equ     1822
RPC_S_NOT_RPC_ERROR                             equ     1823
RPC_S_UUID_LOCAL_ONLY                           equ     1824
RPC_S_SEC_PKG_ERROR                             equ     1825
RPC_S_NOT_CANCELLED                             equ     1826
RPC_X_INVALID_ES_ACTION                         equ     1827
RPC_X_WRONG_ES_VERSION                          equ     1828
RPC_X_WRONG_STUB_VERSION                        equ     1829
RPC_X_INVALID_PIPE_OBJECT                       equ     1830
RPC_X_WRONG_PIPE_ORDER                          equ     1831
RPC_X_WRONG_PIPE_VERSION                        equ     1832
RPC_S_COOKIE_AUTH_FAILED                        equ     1833
RPC_S_GROUP_MEMBER_NOT_FOUND                    equ     1898
EPT_S_CANT_CREATE                               equ     1899
RPC_S_INVALID_OBJECT                            equ     1900
ERROR_INVALID_TIME                              equ     1901
ERROR_INVALID_FORM_NAME                         equ     1902
ERROR_INVALID_FORM_SIZE                         equ     1903
ERROR_ALREADY_WAITING                           equ     1904
ERROR_PRINTER_DELETED                           equ     1905
ERROR_INVALID_PRINTER_STATE                     equ     1906
ERROR_PASSWORD_MUST_CHANGE                      equ     1907
ERROR_DOMAIN_CONTROLLER_NOT_FOUND               equ     1908
ERROR_ACCOUNT_LOCKED_OUT                        equ     1909
OR_INVALID_OXID                                 equ     1910
OR_INVALID_OID                                  equ     1911
OR_INVALID_SET                                  equ     1912
RPC_S_SEND_INCOMPLETE                           equ     1913
RPC_S_INVALID_ASYNC_HANDLE                      equ     1914
RPC_S_INVALID_ASYNC_CALL                        equ     1915
RPC_X_PIPE_CLOSED                               equ     1916
RPC_X_PIPE_DISCIPLINE_ERROR                     equ     1917
RPC_X_PIPE_EMPTY                                equ     1918
ERROR_NO_SITENAME                               equ     1919
ERROR_CANT_ACCESS_FILE                          equ     1920
ERROR_CANT_RESOLVE_FILENAME                     equ     1921
RPC_S_ENTRY_TYPE_MISMATCH                       equ     1922
RPC_S_NOT_ALL_OBJS_EXPORTED                     equ     1923
RPC_S_INTERFACE_NOT_EXPORTED                    equ     1924
RPC_S_PROFILE_NOT_ADDED                         equ     1925
RPC_S_PRF_ELT_NOT_ADDED                         equ     1926
RPC_S_PRF_ELT_NOT_REMOVED                       equ     1927
RPC_S_GRP_ELT_NOT_ADDED                         equ     1928
RPC_S_GRP_ELT_NOT_REMOVED                       equ     1929
ERROR_KM_DRIVER_BLOCKED                         equ     1930
ERROR_CONTEXT_EXPIRED                           equ     1931
ERROR_PER_USER_TRUST_QUOTA_EXCEEDED             equ     1932
ERROR_ALL_USER_TRUST_QUOTA_EXCEEDED             equ     1933
ERROR_USER_DELETE_TRUST_QUOTA_EXCEEDED          equ     1934
ERROR_AUTHENTICATION_FIREWALL_FAILED            equ     1935
ERROR_REMOTE_PRINT_CONNECTIONS_BLOCKED          equ     1936
ERROR_NTLM_BLOCKED                              equ     1937
ERROR_INVALID_PIXEL_FORMAT                      equ     2000
ERROR_BAD_DRIVER                                equ     2001
ERROR_INVALID_WINDOW_STYLE                      equ     2002
ERROR_METAFILE_NOT_SUPPORTED                    equ     2003
ERROR_TRANSFORM_NOT_SUPPORTED                   equ     2004
ERROR_CLIPPING_NOT_SUPPORTED                    equ     2005
ERROR_INVALID_CMM                               equ     2010
ERROR_INVALID_PROFILE                           equ     2011
ERROR_TAG_NOT_FOUND                             equ     2012
ERROR_TAG_NOT_PRESENT                           equ     2013
ERROR_DUPLICATE_TAG                             equ     2014
ERROR_PROFILE_NOT_ASSOCIATED_WITH_DEVICE        equ     2015
ERROR_PROFILE_NOT_FOUND                         equ     2016
ERROR_INVALID_COLORSPACE                        equ     2017
ERROR_ICM_NOT_ENABLED                           equ     2018
ERROR_DELETING_ICM_XFORM                        equ     2019
ERROR_INVALID_TRANSFORM                         equ     2020
ERROR_COLORSPACE_MISMATCH                       equ     2021
ERROR_INVALID_COLORINDEX                        equ     2022
ERROR_PROFILE_DOES_NOT_MATCH_DEVICE             equ     2023
ERROR_CONNECTED_OTHER_PASSWORD                  equ     2108
ERROR_CONNECTED_OTHER_PASSWORD_DEFAULT          equ     2109
ERROR_BAD_USERNAME                              equ     2202
ERROR_NOT_CONNECTED                             equ     2250
ERROR_OPEN_FILES                                equ     2401
ERROR_ACTIVE_CONNECTIONS                        equ     2402
ERROR_DEVICE_IN_USE                             equ     2404
ERROR_UNKNOWN_PRINT_MONITOR                     equ     3000
ERROR_PRINTER_DRIVER_IN_USE                     equ     3001
ERROR_SPOOL_FILE_NOT_FOUND                      equ     3002
ERROR_SPL_NO_STARTDOC                           equ     3003
ERROR_SPL_NO_ADDJOB                             equ     3004
ERROR_PRINT_PROCESSOR_ALREADY_INSTALLED         equ     3005
ERROR_PRINT_MONITOR_ALREADY_INSTALLED           equ     3006
ERROR_INVALID_PRINT_MONITOR                     equ     3007
ERROR_PRINT_MONITOR_IN_USE                      equ     3008
ERROR_PRINTER_HAS_JOBS_QUEUED                   equ     3009
ERROR_SUCCESS_REBOOT_REQUIRED                   equ     3010
ERROR_SUCCESS_RESTART_REQUIRED                  equ     3011
ERROR_PRINTER_NOT_FOUND                         equ     3012
ERROR_PRINTER_DRIVER_WARNED                     equ     3013
ERROR_PRINTER_DRIVER_BLOCKED                    equ     3014
ERROR_PRINTER_DRIVER_PACKAGE_IN_USE             equ     3015
ERROR_CORE_DRIVER_PACKAGE_NOT_FOUND             equ     3016
ERROR_FAIL_REBOOT_REQUIRED                      equ     3017
ERROR_FAIL_REBOOT_INITIATED                     equ     3018
ERROR_PRINTER_DRIVER_DOWNLOAD_NEEDED            equ     3019
ERROR_PRINT_JOB_RESTART_REQUIRED                equ     3020
ERROR_IO_REISSUE_AS_CACHED                      equ     3950
ERROR_WINS_INTERNAL                             equ     4000
ERROR_CAN_NOT_DEL_LOCAL_WINS                    equ     4001
ERROR_STATIC_INIT                               equ     4002
ERROR_INC_BACKUP                                equ     4003
ERROR_FULL_BACKUP                               equ     4004
ERROR_REC_NON_EXISTENT                          equ     4005
ERROR_RPL_NOT_ALLOWED                           equ     4006
PEERDIST_ERROR_CONTENTINFO_VERSION_UNSUPPORTED  equ     4050
PEERDIST_ERROR_CANNOT_PARSE_CONTENTINFO         equ     4051
PEERDIST_ERROR_MISSING_DATA                     equ     4052
PEERDIST_ERROR_NO_MORE                          equ     4053
PEERDIST_ERROR_NOT_INITIALIZED                  equ     4054
PEERDIST_ERROR_ALREADY_INITIALIZED              equ     4055
PEERDIST_ERROR_SHUTDOWN_IN_PROGRESS             equ     4056
PEERDIST_ERROR_INVALIDATED                      equ     4057
PEERDIST_ERROR_ALREADY_EXISTS                   equ     4058
PEERDIST_ERROR_OPERATION_NOTFOUND               equ     4059
PEERDIST_ERROR_ALREADY_COMPLETED                equ     4060
PEERDIST_ERROR_OUT_OF_BOUNDS                    equ     4061
PEERDIST_ERROR_VERSION_UNSUPPORTED              equ     4062
PEERDIST_ERROR_INVALID_CONFIGURATION            equ     4063
PEERDIST_ERROR_NOT_LICENSED                     equ     4064
PEERDIST_ERROR_SERVICE_UNAVAILABLE              equ     4065
ERROR_DHCP_ADDRESS_CONFLICT                     equ     4100
ERROR_WMI_GUID_NOT_FOUND                        equ     4200
ERROR_WMI_INSTANCE_NOT_FOUND                    equ     4201
ERROR_WMI_ITEMID_NOT_FOUND                      equ     4202
ERROR_WMI_TRY_AGAIN                             equ     4203
ERROR_WMI_DP_NOT_FOUND                          equ     4204
ERROR_WMI_UNRESOLVED_INSTANCE_REF               equ     4205
ERROR_WMI_ALREADY_ENABLED                       equ     4206
ERROR_WMI_GUID_DISCONNECTED                     equ     4207
ERROR_WMI_SERVER_UNAVAILABLE                    equ     4208
ERROR_WMI_DP_FAILED                             equ     4209
ERROR_WMI_INVALID_MOF                           equ     4210
ERROR_WMI_INVALID_REGINFO                       equ     4211
ERROR_WMI_ALREADY_DISABLED                      equ     4212
ERROR_WMI_READ_ONLY                             equ     4213
ERROR_WMI_SET_FAILURE                           equ     4214
ERROR_INVALID_MEDIA                             equ     4300
ERROR_INVALID_LIBRARY                           equ     4301
ERROR_INVALID_MEDIA_POOL                        equ     4302
ERROR_DRIVE_MEDIA_MISMATCH                      equ     4303
ERROR_MEDIA_OFFLINE                             equ     4304
ERROR_LIBRARY_OFFLINE                           equ     4305
ERROR_EMPTY                                     equ     4306
ERROR_NOT_EMPTY                                 equ     4307
ERROR_MEDIA_UNAVAILABLE                         equ     4308
ERROR_RESOURCE_DISABLED                         equ     4309
ERROR_INVALID_CLEANER                           equ     4310
ERROR_UNABLE_TO_CLEAN                           equ     4311
ERROR_OBJECT_NOT_FOUND                          equ     4312
ERROR_DATABASE_FAILURE                          equ     4313
ERROR_DATABASE_FULL                             equ     4314
ERROR_MEDIA_INCOMPATIBLE                        equ     4315
ERROR_RESOURCE_NOT_PRESENT                      equ     4316
ERROR_INVALID_OPERATION                         equ     4317
ERROR_MEDIA_NOT_AVAILABLE                       equ     4318
ERROR_DEVICE_NOT_AVAILABLE                      equ     4319
ERROR_REQUEST_REFUSED                           equ     4320
ERROR_INVALID_DRIVE_OBJECT                      equ     4321
ERROR_LIBRARY_FULL                              equ     4322
ERROR_MEDIUM_NOT_ACCESSIBLE                     equ     4323
ERROR_UNABLE_TO_LOAD_MEDIUM                     equ     4324
ERROR_UNABLE_TO_INVENTORY_DRIVE                 equ     4325
ERROR_UNABLE_TO_INVENTORY_SLOT                  equ     4326
ERROR_UNABLE_TO_INVENTORY_TRANSPORT             equ     4327
ERROR_TRANSPORT_FULL                            equ     4328
ERROR_CONTROLLING_IEPORT                        equ     4329
ERROR_UNABLE_TO_EJECT_MOUNTED_MEDIA             equ     4330
ERROR_CLEANER_SLOT_SET                          equ     4331
ERROR_CLEANER_SLOT_NOT_SET                      equ     4332
ERROR_CLEANER_CARTRIDGE_SPENT                   equ     4333
ERROR_UNEXPECTED_OMID                           equ     4334
ERROR_CANT_DELETE_LAST_ITEM                     equ     4335
ERROR_MESSAGE_EXCEEDS_MAX_SIZE                  equ     4336
ERROR_VOLUME_CONTAINS_SYS_FILES                 equ     4337
ERROR_INDIGENOUS_TYPE                           equ     4338
ERROR_NO_SUPPORTING_DRIVES                      equ     4339
ERROR_CLEANER_CARTRIDGE_INSTALLED               equ     4340
ERROR_IEPORT_FULL                               equ     4341
ERROR_FILE_OFFLINE                              equ     4350
ERROR_REMOTE_STORAGE_NOT_ACTIVE                 equ     4351
ERROR_REMOTE_STORAGE_MEDIA_ERROR                equ     4352
ERROR_NOT_A_REPARSE_POINT                       equ     4390
ERROR_REPARSE_ATTRIBUTE_CONFLICT                equ     4391
ERROR_INVALID_REPARSE_DATA                      equ     4392
ERROR_REPARSE_TAG_INVALID                       equ     4393
ERROR_REPARSE_TAG_MISMATCH                      equ     4394
ERROR_VOLUME_NOT_SIS_ENABLED                    equ     4500
ERROR_DEPENDENT_RESOURCE_EXISTS                 equ     5001
ERROR_DEPENDENCY_NOT_FOUND                      equ     5002
ERROR_DEPENDENCY_ALREADY_EXISTS                 equ     5003
ERROR_RESOURCE_NOT_ONLINE                       equ     5004
ERROR_HOST_NODE_NOT_AVAILABLE                   equ     5005
ERROR_RESOURCE_NOT_AVAILABLE                    equ     5006
ERROR_RESOURCE_NOT_FOUND                        equ     5007
ERROR_SHUTDOWN_CLUSTER                          equ     5008
ERROR_CANT_EVICT_ACTIVE_NODE                    equ     5009
ERROR_OBJECT_ALREADY_EXISTS                     equ     5010
ERROR_OBJECT_IN_LIST                            equ     5011
ERROR_GROUP_NOT_AVAILABLE                       equ     5012
ERROR_GROUP_NOT_FOUND                           equ     5013
ERROR_GROUP_NOT_ONLINE                          equ     5014
ERROR_HOST_NODE_NOT_RESOURCE_OWNER              equ     5015
ERROR_HOST_NODE_NOT_GROUP_OWNER                 equ     5016
ERROR_RESMON_CREATE_FAILED                      equ     5017
ERROR_RESMON_ONLINE_FAILED                      equ     5018
ERROR_RESOURCE_ONLINE                           equ     5019
ERROR_QUORUM_RESOURCE                           equ     5020
ERROR_NOT_QUORUM_CAPABLE                        equ     5021
ERROR_CLUSTER_SHUTTING_DOWN                     equ     5022
ERROR_INVALID_STATE                             equ     5023
ERROR_RESOURCE_PROPERTIES_STORED                equ     5024
ERROR_NOT_QUORUM_CLASS                          equ     5025
ERROR_CORE_RESOURCE                             equ     5026
ERROR_QUORUM_RESOURCE_ONLINE_FAILED             equ     5027
ERROR_QUORUMLOG_OPEN_FAILED                     equ     5028
ERROR_CLUSTERLOG_CORRUPT                        equ     5029
ERROR_CLUSTERLOG_RECORD_EXCEEDS_MAXSIZE         equ     5030
ERROR_CLUSTERLOG_EXCEEDS_MAXSIZE                equ     5031
ERROR_CLUSTERLOG_CHKPOINT_NOT_FOUND             equ     5032
ERROR_CLUSTERLOG_NOT_ENOUGH_SPACE               equ     5033
ERROR_QUORUM_OWNER_ALIVE                        equ     5034
ERROR_NETWORK_NOT_AVAILABLE                     equ     5035
ERROR_NODE_NOT_AVAILABLE                        equ     5036
ERROR_ALL_NODES_NOT_AVAILABLE                   equ     5037
ERROR_RESOURCE_FAILED                           equ     5038
ERROR_CLUSTER_INVALID_NODE                      equ     5039
ERROR_CLUSTER_NODE_EXISTS                       equ     5040
ERROR_CLUSTER_JOIN_IN_PROGRESS                  equ     5041
ERROR_CLUSTER_NODE_NOT_FOUND                    equ     5042
ERROR_CLUSTER_LOCAL_NODE_NOT_FOUND              equ     5043
ERROR_CLUSTER_NETWORK_EXISTS                    equ     5044
ERROR_CLUSTER_NETWORK_NOT_FOUND                 equ     5045
ERROR_CLUSTER_NETINTERFACE_EXISTS               equ     5046
ERROR_CLUSTER_NETINTERFACE_NOT_FOUND            equ     5047
ERROR_CLUSTER_INVALID_REQUEST                   equ     5048
ERROR_CLUSTER_INVALID_NETWORK_PROVIDER          equ     5049
ERROR_CLUSTER_NODE_DOWN                         equ     5050
ERROR_CLUSTER_NODE_UNREACHABLE                  equ     5051
ERROR_CLUSTER_NODE_NOT_MEMBER                   equ     5052
ERROR_CLUSTER_JOIN_NOT_IN_PROGRESS              equ     5053
ERROR_CLUSTER_INVALID_NETWORK                   equ     5054
ERROR_CLUSTER_NODE_UP                           equ     5056
ERROR_CLUSTER_IPADDR_IN_USE                     equ     5057
ERROR_CLUSTER_NODE_NOT_PAUSED                   equ     5058
ERROR_CLUSTER_NO_SECURITY_CONTEXT               equ     5059
ERROR_CLUSTER_NETWORK_NOT_INTERNAL              equ     5060
ERROR_CLUSTER_NODE_ALREADY_UP                   equ     5061
ERROR_CLUSTER_NODE_ALREADY_DOWN                 equ     5062
ERROR_CLUSTER_NETWORK_ALREADY_ONLINE            equ     5063
ERROR_CLUSTER_NETWORK_ALREADY_OFFLINE           equ     5064
ERROR_CLUSTER_NODE_ALREADY_MEMBER               equ     5065
ERROR_CLUSTER_LAST_INTERNAL_NETWORK             equ     5066
ERROR_CLUSTER_NETWORK_HAS_DEPENDENTS            equ     5067
ERROR_INVALID_OPERATION_ON_QUORUM               equ     5068
ERROR_DEPENDENCY_NOT_ALLOWED                    equ     5069
ERROR_CLUSTER_NODE_PAUSED                       equ     5070
ERROR_NODE_CANT_HOST_RESOURCE                   equ     5071
ERROR_CLUSTER_NODE_NOT_READY                    equ     5072
ERROR_CLUSTER_NODE_SHUTTING_DOWN                equ     5073
ERROR_CLUSTER_JOIN_ABORTED                      equ     5074
ERROR_CLUSTER_INCOMPATIBLE_VERSIONS             equ     5075
ERROR_CLUSTER_MAXNUM_OF_RESOURCES_EXCEEDED      equ     5076
ERROR_CLUSTER_SYSTEM_CONFIG_CHANGED             equ     5077
ERROR_CLUSTER_RESOURCE_TYPE_NOT_FOUND           equ     5078
ERROR_CLUSTER_RESTYPE_NOT_SUPPORTED             equ     5079
ERROR_CLUSTER_RESNAME_NOT_FOUND                 equ     5080
ERROR_CLUSTER_NO_RPC_PACKAGES_REGISTERED        equ     5081
ERROR_CLUSTER_OWNER_NOT_IN_PREFLIST             equ     5082
ERROR_CLUSTER_DATABASE_SEQMISMATCH              equ     5083
ERROR_RESMON_INVALID_STATE                      equ     5084
ERROR_CLUSTER_GUM_NOT_LOCKER                    equ     5085
ERROR_QUORUM_DISK_NOT_FOUND                     equ     5086
ERROR_DATABASE_BACKUP_CORRUPT                   equ     5087
ERROR_CLUSTER_NODE_ALREADY_HAS_DFS_ROOT         equ     5088
ERROR_RESOURCE_PROPERTY_UNCHANGEABLE            equ     5089
ERROR_CLUSTER_MEMBERSHIP_INVALID_STATE          equ     5890
ERROR_CLUSTER_QUORUMLOG_NOT_FOUND               equ     5891
ERROR_CLUSTER_MEMBERSHIP_HALT                   equ     5892
ERROR_CLUSTER_INSTANCE_ID_MISMATCH              equ     5893
ERROR_CLUSTER_NETWORK_NOT_FOUND_FOR_IP          equ     5894
ERROR_CLUSTER_PROPERTY_DATA_TYPE_MISMATCH       equ     5895
ERROR_CLUSTER_EVICT_WITHOUT_CLEANUP             equ     5896
ERROR_CLUSTER_PARAMETER_MISMATCH                equ     5897
ERROR_NODE_CANNOT_BE_CLUSTERED                  equ     5898
ERROR_CLUSTER_WRONG_OS_VERSION                  equ     5899
ERROR_CLUSTER_CANT_CREATE_DUP_CLUSTER_NAME      equ     5900
ERROR_CLUSCFG_ALREADY_COMMITTED                 equ     5901
ERROR_CLUSCFG_ROLLBACK_FAILED                   equ     5902
ERROR_CLUSCFG_SYSTEM_DISK_DRIVE_LETTER_CONFLICT equ     5903
ERROR_CLUSTER_OLD_VERSION                       equ     5904
ERROR_CLUSTER_MISMATCHED_COMPUTER_ACCT_NAME     equ     5905
ERROR_CLUSTER_NO_NET_ADAPTERS                   equ     5906
ERROR_CLUSTER_POISONED                          equ     5907
ERROR_CLUSTER_GROUP_MOVING                      equ     5908
ERROR_CLUSTER_RESOURCE_TYPE_BUSY                equ     5909
ERROR_RESOURCE_CALL_TIMED_OUT                   equ     5910
ERROR_INVALID_CLUSTER_IPV6_ADDRESS              equ     5911
ERROR_CLUSTER_INTERNAL_INVALID_FUNCTION         equ     5912
ERROR_CLUSTER_PARAMETER_OUT_OF_BOUNDS           equ     5913
ERROR_CLUSTER_PARTIAL_SEND                      equ     5914
ERROR_CLUSTER_REGISTRY_INVALID_FUNCTION         equ     5915
ERROR_CLUSTER_INVALID_STRING_TERMINATION        equ     5916
ERROR_CLUSTER_INVALID_STRING_FORMAT             equ     5917
ERROR_CLUSTER_DATABASE_TRANSACTION_IN_PROGRESS  equ     5918
ERROR_CLUSTER_DATABASE_TRANSACTION_NOT_IN_PROGRESS equ  5919
ERROR_CLUSTER_NULL_DATA                         equ     5920
ERROR_CLUSTER_PARTIAL_READ                      equ     5921
ERROR_CLUSTER_PARTIAL_WRITE                     equ     5922
ERROR_CLUSTER_CANT_DESERIALIZE_DATA             equ     5923
ERROR_DEPENDENT_RESOURCE_PROPERTY_CONFLICT      equ     5924
ERROR_CLUSTER_NO_QUORUM                         equ     5925
ERROR_CLUSTER_INVALID_IPV6_NETWORK              equ     5926
ERROR_CLUSTER_INVALID_IPV6_TUNNEL_NETWORK       equ     5927
ERROR_QUORUM_NOT_ALLOWED_IN_THIS_GROUP          equ     5928
ERROR_DEPENDENCY_TREE_TOO_COMPLEX               equ     5929
ERROR_EXCEPTION_IN_RESOURCE_CALL                equ     5930
ERROR_CLUSTER_RHS_FAILED_INITIALIZATION         equ     5931
ERROR_CLUSTER_NOT_INSTALLED                     equ     5932
ERROR_CLUSTER_RESOURCES_MUST_BE_ONLINE_ON_THE_SAME_NODE equ 5933
ERROR_CLUSTER_MAX_NODES_IN_CLUSTER              equ     5934
ERROR_CLUSTER_TOO_MANY_NODES                    equ     5935
ERROR_CLUSTER_OBJECT_ALREADY_USED               equ     5936
ERROR_NONCORE_GROUPS_FOUND                      equ     5937
ERROR_FILE_SHARE_RESOURCE_CONFLICT              equ     5938
ERROR_CLUSTER_EVICT_INVALID_REQUEST             equ     5939
ERROR_CLUSTER_SINGLETON_RESOURCE                equ     5940
ERROR_CLUSTER_GROUP_SINGLETON_RESOURCE          equ     5941
ERROR_CLUSTER_RESOURCE_PROVIDER_FAILED          equ     5942
ERROR_CLUSTER_RESOURCE_CONFIGURATION_ERROR      equ     5943
ERROR_CLUSTER_GROUP_BUSY                        equ     5944
ERROR_CLUSTER_NOT_SHARED_VOLUME                 equ     5945
ERROR_CLUSTER_INVALID_SECURITY_DESCRIPTOR       equ     5946
ERROR_CLUSTER_SHARED_VOLUMES_IN_USE             equ     5947
ERROR_CLUSTER_USE_SHARED_VOLUMES_API            equ     5948
ERROR_CLUSTER_BACKUP_IN_PROGRESS                equ     5949
ERROR_NON_CSV_PATH                              equ     5950
ERROR_CSV_VOLUME_NOT_LOCAL                      equ     5951
ERROR_CLUSTER_WATCHDOG_TERMINATING              equ     5952
ERROR_ENCRYPTION_FAILED                         equ     6000
ERROR_DECRYPTION_FAILED                         equ     6001
ERROR_FILE_ENCRYPTED                            equ     6002
ERROR_NO_RECOVERY_POLICY                        equ     6003
ERROR_NO_EFS                                    equ     6004
ERROR_WRONG_EFS                                 equ     6005
ERROR_NO_USER_KEYS                              equ     6006
ERROR_FILE_NOT_ENCRYPTED                        equ     6007
ERROR_NOT_EXPORT_FORMAT                         equ     6008
ERROR_FILE_READ_ONLY                            equ     6009
ERROR_DIR_EFS_DISALLOWED                        equ     6010
ERROR_EFS_SERVER_NOT_TRUSTED                    equ     6011
ERROR_BAD_RECOVERY_POLICY                       equ     6012
ERROR_EFS_ALG_BLOB_TOO_BIG                      equ     6013
ERROR_VOLUME_NOT_SUPPORT_EFS                    equ     6014
ERROR_EFS_DISABLED                              equ     6015
ERROR_EFS_VERSION_NOT_SUPPORT                   equ     6016
ERROR_CS_ENCRYPTION_INVALID_SERVER_RESPONSE     equ     6017
ERROR_CS_ENCRYPTION_UNSUPPORTED_SERVER          equ     6018
ERROR_CS_ENCRYPTION_EXISTING_ENCRYPTED_FILE     equ     6019
ERROR_CS_ENCRYPTION_NEW_ENCRYPTED_FILE          equ     6020
ERROR_CS_ENCRYPTION_FILE_NOT_CSE                equ     6021
ERROR_ENCRYPTION_POLICY_DENIES_OPERATION        equ     6022
ERROR_NO_BROWSER_SERVERS_FOUND                  equ     6118
SCHED_E_SERVICE_NOT_LOCALSYSTEM                 equ     6200
ERROR_LOG_SECTOR_INVALID                        equ     6600
ERROR_LOG_SECTOR_PARITY_INVALID                 equ     6601
ERROR_LOG_SECTOR_REMAPPED                       equ     6602
ERROR_LOG_BLOCK_INCOMPLETE                      equ     6603
ERROR_LOG_INVALID_RANGE                         equ     6604
ERROR_LOG_BLOCKS_EXHAUSTED                      equ     6605
ERROR_LOG_READ_CONTEXT_INVALID                  equ     6606
ERROR_LOG_RESTART_INVALID                       equ     6607
ERROR_LOG_BLOCK_VERSION                         equ     6608
ERROR_LOG_BLOCK_INVALID                         equ     6609
ERROR_LOG_READ_MODE_INVALID                     equ     6610
ERROR_LOG_NO_RESTART                            equ     6611
ERROR_LOG_METADATA_CORRUPT                      equ     6612
ERROR_LOG_METADATA_INVALID                      equ     6613
ERROR_LOG_METADATA_INCONSISTENT                 equ     6614
ERROR_LOG_RESERVATION_INVALID                   equ     6615
ERROR_LOG_CANT_DELETE                           equ     6616
ERROR_LOG_CONTAINER_LIMIT_EXCEEDED              equ     6617
ERROR_LOG_START_OF_LOG                          equ     6618
ERROR_LOG_POLICY_ALREADY_INSTALLED              equ     6619
ERROR_LOG_POLICY_NOT_INSTALLED                  equ     6620
ERROR_LOG_POLICY_INVALID                        equ     6621
ERROR_LOG_POLICY_CONFLICT                       equ     6622
ERROR_LOG_PINNED_ARCHIVE_TAIL                   equ     6623
ERROR_LOG_RECORD_NONEXISTENT                    equ     6624
ERROR_LOG_RECORDS_RESERVED_INVALID              equ     6625
ERROR_LOG_SPACE_RESERVED_INVALID                equ     6626
ERROR_LOG_TAIL_INVALID                          equ     6627
ERROR_LOG_FULL                                  equ     6628
ERROR_COULD_NOT_RESIZE_LOG                      equ     6629
ERROR_LOG_MULTIPLEXED                           equ     6630
ERROR_LOG_DEDICATED                             equ     6631
ERROR_LOG_ARCHIVE_NOT_IN_PROGRESS               equ     6632
ERROR_LOG_ARCHIVE_IN_PROGRESS                   equ     6633
ERROR_LOG_EPHEMERAL                             equ     6634
ERROR_LOG_NOT_ENOUGH_CONTAINERS                 equ     6635
ERROR_LOG_CLIENT_ALREADY_REGISTERED             equ     6636
ERROR_LOG_CLIENT_NOT_REGISTERED                 equ     6637
ERROR_LOG_FULL_HANDLER_IN_PROGRESS              equ     6638
ERROR_LOG_CONTAINER_READ_FAILED                 equ     6639
ERROR_LOG_CONTAINER_WRITE_FAILED                equ     6640
ERROR_LOG_CONTAINER_OPEN_FAILED                 equ     6641
ERROR_LOG_CONTAINER_STATE_INVALID               equ     6642
ERROR_LOG_STATE_INVALID                         equ     6643
ERROR_LOG_PINNED                                equ     6644
ERROR_LOG_METADATA_FLUSH_FAILED                 equ     6645
ERROR_LOG_INCONSISTENT_SECURITY                 equ     6646
ERROR_LOG_APPENDED_FLUSH_FAILED                 equ     6647
ERROR_LOG_PINNED_RESERVATION                    equ     6648
ERROR_INVALID_TRANSACTION                       equ     6700
ERROR_TRANSACTION_NOT_ACTIVE                    equ     6701
ERROR_TRANSACTION_REQUEST_NOT_VALID             equ     6702
ERROR_TRANSACTION_NOT_REQUESTED                 equ     6703
ERROR_TRANSACTION_ALREADY_ABORTED               equ     6704
ERROR_TRANSACTION_ALREADY_COMMITTED             equ     6705
ERROR_TM_INITIALIZATION_FAILED                  equ     6706
ERROR_RESOURCEMANAGER_READ_ONLY                 equ     6707
ERROR_TRANSACTION_NOT_JOINED                    equ     6708
ERROR_TRANSACTION_SUPERIOR_EXISTS               equ     6709
ERROR_CRM_PROTOCOL_ALREADY_EXISTS               equ     6710
ERROR_TRANSACTION_PROPAGATION_FAILED            equ     6711
ERROR_CRM_PROTOCOL_NOT_FOUND                    equ     6712
ERROR_TRANSACTION_INVALID_MARSHALL_BUFFER       equ     6713
ERROR_CURRENT_TRANSACTION_NOT_VALID             equ     6714
ERROR_TRANSACTION_NOT_FOUND                     equ     6715
ERROR_RESOURCEMANAGER_NOT_FOUND                 equ     6716
ERROR_ENLISTMENT_NOT_FOUND                      equ     6717
ERROR_TRANSACTIONMANAGER_NOT_FOUND              equ     6718
ERROR_TRANSACTIONMANAGER_NOT_ONLINE             equ     6719
ERROR_TRANSACTIONMANAGER_RECOVERY_NAME_COLLISION equ    6720
ERROR_TRANSACTION_NOT_ROOT                      equ     6721
ERROR_TRANSACTION_OBJECT_EXPIRED                equ     6722
ERROR_TRANSACTION_RESPONSE_NOT_ENLISTED         equ     6723
ERROR_TRANSACTION_RECORD_TOO_LONG               equ     6724
ERROR_IMPLICIT_TRANSACTION_NOT_SUPPORTED        equ     6725
ERROR_TRANSACTION_INTEGRITY_VIOLATED            equ     6726
ERROR_TRANSACTIONMANAGER_IDENTITY_MISMATCH      equ     6727
ERROR_RM_CANNOT_BE_FROZEN_FOR_SNAPSHOT          equ     6728
ERROR_TRANSACTION_MUST_WRITETHROUGH             equ     6729
ERROR_TRANSACTION_NO_SUPERIOR                   equ     6730
ERROR_HEURISTIC_DAMAGE_POSSIBLE                 equ     6731
ERROR_TRANSACTIONAL_CONFLICT                    equ     6800
ERROR_RM_NOT_ACTIVE                             equ     6801
ERROR_RM_METADATA_CORRUPT                       equ     6802
ERROR_DIRECTORY_NOT_RM                          equ     6803
ERROR_TRANSACTIONS_UNSUPPORTED_REMOTE           equ     6805
ERROR_LOG_RESIZE_INVALID_SIZE                   equ     6806
ERROR_OBJECT_NO_LONGER_EXISTS                   equ     6807
ERROR_STREAM_MINIVERSION_NOT_FOUND              equ     6808
ERROR_STREAM_MINIVERSION_NOT_VALID              equ     6809
ERROR_MINIVERSION_INACCESSIBLE_FROM_SPECIFIED_TRANSACTION equ 6810
ERROR_CANT_OPEN_MINIVERSION_WITH_MODIFY_INTENT  equ     6811
ERROR_CANT_CREATE_MORE_STREAM_MINIVERSIONS      equ     6812
ERROR_REMOTE_FILE_VERSION_MISMATCH              equ     6814
ERROR_HANDLE_NO_LONGER_VALID                    equ     6815
ERROR_NO_TXF_METADATA                           equ     6816
ERROR_LOG_CORRUPTION_DETECTED                   equ     6817
ERROR_CANT_RECOVER_WITH_HANDLE_OPEN             equ     6818
ERROR_RM_DISCONNECTED                           equ     6819
ERROR_ENLISTMENT_NOT_SUPERIOR                   equ     6820
ERROR_RECOVERY_NOT_NEEDED                       equ     6821
ERROR_RM_ALREADY_STARTED                        equ     6822
ERROR_FILE_IDENTITY_NOT_PERSISTENT              equ     6823
ERROR_CANT_BREAK_TRANSACTIONAL_DEPENDENCY       equ     6824
ERROR_CANT_CROSS_RM_BOUNDARY                    equ     6825
ERROR_TXF_DIR_NOT_EMPTY                         equ     6826
ERROR_INDOUBT_TRANSACTIONS_EXIST                equ     6827
ERROR_TM_VOLATILE                               equ     6828
ERROR_ROLLBACK_TIMER_EXPIRED                    equ     6829
ERROR_TXF_ATTRIBUTE_CORRUPT                     equ     6830
ERROR_EFS_NOT_ALLOWED_IN_TRANSACTION            equ     6831
ERROR_TRANSACTIONAL_OPEN_NOT_ALLOWED            equ     6832
ERROR_LOG_GROWTH_FAILED                         equ     6833
ERROR_TRANSACTED_MAPPING_UNSUPPORTED_REMOTE     equ     6834
ERROR_TXF_METADATA_ALREADY_PRESENT              equ     6835
ERROR_TRANSACTION_SCOPE_CALLBACKS_NOT_SET       equ     6836
ERROR_TRANSACTION_REQUIRED_PROMOTION            equ     6837
ERROR_CANNOT_EXECUTE_FILE_IN_TRANSACTION        equ     6838
ERROR_TRANSACTIONS_NOT_FROZEN                   equ     6839
ERROR_TRANSACTION_FREEZE_IN_PROGRESS            equ     6840
ERROR_NOT_SNAPSHOT_VOLUME                       equ     6841
ERROR_NO_SAVEPOINT_WITH_OPEN_FILES              equ     6842
ERROR_DATA_LOST_REPAIR                          equ     6843
ERROR_SPARSE_NOT_ALLOWED_IN_TRANSACTION         equ     6844
ERROR_TM_IDENTITY_MISMATCH                      equ     6845
ERROR_FLOATED_SECTION                           equ     6846
ERROR_CANNOT_ACCEPT_TRANSACTED_WORK             equ     6847
ERROR_CANNOT_ABORT_TRANSACTIONS                 equ     6848
ERROR_BAD_CLUSTERS                              equ     6849
ERROR_COMPRESSION_NOT_ALLOWED_IN_TRANSACTION    equ     6850
ERROR_VOLUME_DIRTY                              equ     6851
ERROR_NO_LINK_TRACKING_IN_TRANSACTION           equ     6852
ERROR_OPERATION_NOT_SUPPORTED_IN_TRANSACTION    equ     6853
ERROR_EXPIRED_HANDLE                            equ     6854
ERROR_TRANSACTION_NOT_ENLISTED                  equ     6855
ERROR_CTX_WINSTATION_NAME_INVALID               equ     7001
ERROR_CTX_INVALID_PD                            equ     7002
ERROR_CTX_PD_NOT_FOUND                          equ     7003
ERROR_CTX_WD_NOT_FOUND                          equ     7004
ERROR_CTX_CANNOT_MAKE_EVENTLOG_ENTRY            equ     7005
ERROR_CTX_SERVICE_NAME_COLLISION                equ     7006
ERROR_CTX_CLOSE_PENDING                         equ     7007
ERROR_CTX_NO_OUTBUF                             equ     7008
ERROR_CTX_MODEM_INF_NOT_FOUND                   equ     7009
ERROR_CTX_INVALID_MODEMNAME                     equ     7010
ERROR_CTX_MODEM_RESPONSE_ERROR                  equ     7011
ERROR_CTX_MODEM_RESPONSE_TIMEOUT                equ     7012
ERROR_CTX_MODEM_RESPONSE_NO_CARRIER             equ     7013
ERROR_CTX_MODEM_RESPONSE_NO_DIALTONE            equ     7014
ERROR_CTX_MODEM_RESPONSE_BUSY                   equ     7015
ERROR_CTX_MODEM_RESPONSE_VOICE                  equ     7016
ERROR_CTX_TD_ERROR                              equ     7017
ERROR_CTX_WINSTATION_NOT_FOUND                  equ     7022
ERROR_CTX_WINSTATION_ALREADY_EXISTS             equ     7023
ERROR_CTX_WINSTATION_BUSY                       equ     7024
ERROR_CTX_BAD_VIDEO_MODE                        equ     7025
ERROR_CTX_GRAPHICS_INVALID                      equ     7035
ERROR_CTX_LOGON_DISABLED                        equ     7037
ERROR_CTX_NOT_CONSOLE                           equ     7038
ERROR_CTX_CLIENT_QUERY_TIMEOUT                  equ     7040
ERROR_CTX_CONSOLE_DISCONNECT                    equ     7041
ERROR_CTX_CONSOLE_CONNECT                       equ     7042
ERROR_CTX_SHADOW_DENIED                         equ     7044
ERROR_CTX_WINSTATION_ACCESS_DENIED              equ     7045
ERROR_CTX_INVALID_WD                            equ     7049
ERROR_CTX_SHADOW_INVALID                        equ     7050
ERROR_CTX_SHADOW_DISABLED                       equ     7051
ERROR_CTX_CLIENT_LICENSE_IN_USE                 equ     7052
ERROR_CTX_CLIENT_LICENSE_NOT_SET                equ     7053
ERROR_CTX_LICENSE_NOT_AVAILABLE                 equ     7054
ERROR_CTX_LICENSE_CLIENT_INVALID                equ     7055
ERROR_CTX_LICENSE_EXPIRED                       equ     7056
ERROR_CTX_SHADOW_NOT_RUNNING                    equ     7057
ERROR_CTX_SHADOW_ENDED_BY_MODE_CHANGE           equ     7058
ERROR_ACTIVATION_COUNT_EXCEEDED                 equ     7059
ERROR_CTX_WINSTATIONS_DISABLED                  equ     7060
ERROR_CTX_ENCRYPTION_LEVEL_REQUIRED             equ     7061
ERROR_CTX_SESSION_IN_USE                        equ     7062
ERROR_CTX_NO_FORCE_LOGOFF                       equ     7063
ERROR_CTX_ACCOUNT_RESTRICTION                   equ     7064
ERROR_RDP_PROTOCOL_ERROR                        equ     7065
ERROR_CTX_CDM_CONNECT                           equ     7066
ERROR_CTX_CDM_DISCONNECT                        equ     7067
ERROR_CTX_SECURITY_LAYER_ERROR                  equ     7068
ERROR_TS_INCOMPATIBLE_SESSIONS                  equ     7069
ERROR_TS_VIDEO_SUBSYSTEM_ERROR                  equ     7070
FRS_ERR_INVALID_API_SEQUENCE                    equ     8001
FRS_ERR_STARTING_SERVICE                        equ     8002
FRS_ERR_STOPPING_SERVICE                        equ     8003
FRS_ERR_INTERNAL_API                            equ     8004
FRS_ERR_INTERNAL                                equ     8005
FRS_ERR_SERVICE_COMM                            equ     8006
FRS_ERR_INSUFFICIENT_PRIV                       equ     8007
FRS_ERR_AUTHENTICATION                          equ     8008
FRS_ERR_PARENT_INSUFFICIENT_PRIV                equ     8009
FRS_ERR_PARENT_AUTHENTICATION                   equ     8010
FRS_ERR_CHILD_TO_PARENT_COMM                    equ     8011
FRS_ERR_PARENT_TO_CHILD_COMM                    equ     8012
FRS_ERR_SYSVOL_POPULATE                         equ     8013
FRS_ERR_SYSVOL_POPULATE_TIMEOUT                 equ     8014
FRS_ERR_SYSVOL_IS_BUSY                          equ     8015
FRS_ERR_SYSVOL_DEMOTE                           equ     8016
FRS_ERR_INVALID_SERVICE_PARAMETER               equ     8017
DS_S_SUCCESS                                    equ     NO_ERROR
ERROR_DS_NOT_INSTALLED                          equ     8200
ERROR_DS_MEMBERSHIP_EVALUATED_LOCALLY           equ     8201
ERROR_DS_NO_ATTRIBUTE_OR_VALUE                  equ     8202
ERROR_DS_INVALID_ATTRIBUTE_SYNTAX               equ     8203
ERROR_DS_ATTRIBUTE_TYPE_UNDEFINED               equ     8204
ERROR_DS_ATTRIBUTE_OR_VALUE_EXISTS              equ     8205
ERROR_DS_BUSY                                   equ     8206
ERROR_DS_UNAVAILABLE                            equ     8207
ERROR_DS_NO_RIDS_ALLOCATED                      equ     8208
ERROR_DS_NO_MORE_RIDS                           equ     8209
ERROR_DS_INCORRECT_ROLE_OWNER                   equ     8210
ERROR_DS_RIDMGR_INIT_ERROR                      equ     8211
ERROR_DS_OBJ_CLASS_VIOLATION                    equ     8212
ERROR_DS_CANT_ON_NON_LEAF                       equ     8213
ERROR_DS_CANT_ON_RDN                            equ     8214
ERROR_DS_CANT_MOD_OBJ_CLASS                     equ     8215
ERROR_DS_CROSS_DOM_MOVE_ERROR                   equ     8216
ERROR_DS_GC_NOT_AVAILABLE                       equ     8217
ERROR_SHARED_POLICY                             equ     8218
ERROR_POLICY_OBJECT_NOT_FOUND                   equ     8219
ERROR_POLICY_ONLY_IN_DS                         equ     8220
ERROR_PROMOTION_ACTIVE                          equ     8221
ERROR_NO_PROMOTION_ACTIVE                       equ     8222
ERROR_DS_OPERATIONS_ERROR                       equ     8224
ERROR_DS_PROTOCOL_ERROR                         equ     8225
ERROR_DS_TIMELIMIT_EXCEEDED                     equ     8226
ERROR_DS_SIZELIMIT_EXCEEDED                     equ     8227
ERROR_DS_ADMIN_LIMIT_EXCEEDED                   equ     8228
ERROR_DS_COMPARE_FALSE                          equ     8229
ERROR_DS_COMPARE_TRUE                           equ     8230
ERROR_DS_AUTH_METHOD_NOT_SUPPORTED              equ     8231
ERROR_DS_STRONG_AUTH_REQUIRED                   equ     8232
ERROR_DS_INAPPROPRIATE_AUTH                     equ     8233
ERROR_DS_AUTH_UNKNOWN                           equ     8234
ERROR_DS_REFERRAL                               equ     8235
ERROR_DS_UNAVAILABLE_CRIT_EXTENSION             equ     8236
ERROR_DS_CONFIDENTIALITY_REQUIRED               equ     8237
ERROR_DS_INAPPROPRIATE_MATCHING                 equ     8238
ERROR_DS_CONSTRAINT_VIOLATION                   equ     8239
ERROR_DS_NO_SUCH_OBJECT                         equ     8240
ERROR_DS_ALIAS_PROBLEM                          equ     8241
ERROR_DS_INVALID_DN_SYNTAX                      equ     8242
ERROR_DS_IS_LEAF                                equ     8243
ERROR_DS_ALIAS_DEREF_PROBLEM                    equ     8244
ERROR_DS_UNWILLING_TO_PERFORM                   equ     8245
ERROR_DS_LOOP_DETECT                            equ     8246
ERROR_DS_NAMING_VIOLATION                       equ     8247
ERROR_DS_OBJECT_RESULTS_TOO_LARGE               equ     8248
ERROR_DS_AFFECTS_MULTIPLE_DSAS                  equ     8249
ERROR_DS_SERVER_DOWN                            equ     8250
ERROR_DS_LOCAL_ERROR                            equ     8251
ERROR_DS_ENCODING_ERROR                         equ     8252
ERROR_DS_DECODING_ERROR                         equ     8253
ERROR_DS_FILTER_UNKNOWN                         equ     8254
ERROR_DS_PARAM_ERROR                            equ     8255
ERROR_DS_NOT_SUPPORTED                          equ     8256
ERROR_DS_NO_RESULTS_RETURNED                    equ     8257
ERROR_DS_CONTROL_NOT_FOUND                      equ     8258
ERROR_DS_CLIENT_LOOP                            equ     8259
ERROR_DS_REFERRAL_LIMIT_EXCEEDED                equ     8260
ERROR_DS_SORT_CONTROL_MISSING                   equ     8261
ERROR_DS_OFFSET_RANGE_ERROR                     equ     8262
ERROR_DS_ROOT_MUST_BE_NC                        equ     8301
ERROR_DS_ADD_REPLICA_INHIBITED                  equ     8302
ERROR_DS_ATT_NOT_DEF_IN_SCHEMA                  equ     8303
ERROR_DS_MAX_OBJ_SIZE_EXCEEDED                  equ     8304
ERROR_DS_OBJ_STRING_NAME_EXISTS                 equ     8305
ERROR_DS_NO_RDN_DEFINED_IN_SCHEMA               equ     8306
ERROR_DS_RDN_DOESNT_MATCH_SCHEMA                equ     8307
ERROR_DS_NO_REQUESTED_ATTS_FOUND                equ     8308
ERROR_DS_USER_BUFFER_TO_SMALL                   equ     8309
ERROR_DS_ATT_IS_NOT_ON_OBJ                      equ     8310
ERROR_DS_ILLEGAL_MOD_OPERATION                  equ     8311
ERROR_DS_OBJ_TOO_LARGE                          equ     8312
ERROR_DS_BAD_INSTANCE_TYPE                      equ     8313
ERROR_DS_MASTERDSA_REQUIRED                     equ     8314
ERROR_DS_OBJECT_CLASS_REQUIRED                  equ     8315
ERROR_DS_MISSING_REQUIRED_ATT                   equ     8316
ERROR_DS_ATT_NOT_DEF_FOR_CLASS                  equ     8317
ERROR_DS_ATT_ALREADY_EXISTS                     equ     8318
ERROR_DS_CANT_ADD_ATT_VALUES                    equ     8320
ERROR_DS_SINGLE_VALUE_CONSTRAINT                equ     8321
ERROR_DS_RANGE_CONSTRAINT                       equ     8322
ERROR_DS_ATT_VAL_ALREADY_EXISTS                 equ     8323
ERROR_DS_CANT_REM_MISSING_ATT                   equ     8324
ERROR_DS_CANT_REM_MISSING_ATT_VAL               equ     8325
ERROR_DS_ROOT_CANT_BE_SUBREF                    equ     8326
ERROR_DS_NO_CHAINING                            equ     8327
ERROR_DS_NO_CHAINED_EVAL                        equ     8328
ERROR_DS_NO_PARENT_OBJECT                       equ     8329
ERROR_DS_PARENT_IS_AN_ALIAS                     equ     8330
ERROR_DS_CANT_MIX_MASTER_AND_REPS               equ     8331
ERROR_DS_CHILDREN_EXIST                         equ     8332
ERROR_DS_OBJ_NOT_FOUND                          equ     8333
ERROR_DS_ALIASED_OBJ_MISSING                    equ     8334
ERROR_DS_BAD_NAME_SYNTAX                        equ     8335
ERROR_DS_ALIAS_POINTS_TO_ALIAS                  equ     8336
ERROR_DS_CANT_DEREF_ALIAS                       equ     8337
ERROR_DS_OUT_OF_SCOPE                           equ     8338
ERROR_DS_OBJECT_BEING_REMOVED                   equ     8339
ERROR_DS_CANT_DELETE_DSA_OBJ                    equ     8340
ERROR_DS_GENERIC_ERROR                          equ     8341
ERROR_DS_DSA_MUST_BE_INT_MASTER                 equ     8342
ERROR_DS_CLASS_NOT_DSA                          equ     8343
ERROR_DS_INSUFF_ACCESS_RIGHTS                   equ     8344
ERROR_DS_ILLEGAL_SUPERIOR                       equ     8345
ERROR_DS_ATTRIBUTE_OWNED_BY_SAM                 equ     8346
ERROR_DS_NAME_TOO_MANY_PARTS                    equ     8347
ERROR_DS_NAME_TOO_LONG                          equ     8348
ERROR_DS_NAME_VALUE_TOO_LONG                    equ     8349
ERROR_DS_NAME_UNPARSEABLE                       equ     8350
ERROR_DS_NAME_TYPE_UNKNOWN                      equ     8351
ERROR_DS_NOT_AN_OBJECT                          equ     8352
ERROR_DS_SEC_DESC_TOO_SHORT                     equ     8353
ERROR_DS_SEC_DESC_INVALID                       equ     8354
ERROR_DS_NO_DELETED_NAME                        equ     8355
ERROR_DS_SUBREF_MUST_HAVE_PARENT                equ     8356
ERROR_DS_NCNAME_MUST_BE_NC                      equ     8357
ERROR_DS_CANT_ADD_SYSTEM_ONLY                   equ     8358
ERROR_DS_CLASS_MUST_BE_CONCRETE                 equ     8359
ERROR_DS_INVALID_DMD                            equ     8360
ERROR_DS_OBJ_GUID_EXISTS                        equ     8361
ERROR_DS_NOT_ON_BACKLINK                        equ     8362
ERROR_DS_NO_CROSSREF_FOR_NC                     equ     8363
ERROR_DS_SHUTTING_DOWN                          equ     8364
ERROR_DS_UNKNOWN_OPERATION                      equ     8365
ERROR_DS_INVALID_ROLE_OWNER                     equ     8366
ERROR_DS_COULDNT_CONTACT_FSMO                   equ     8367
ERROR_DS_CROSS_NC_DN_RENAME                     equ     8368
ERROR_DS_CANT_MOD_SYSTEM_ONLY                   equ     8369
ERROR_DS_REPLICATOR_ONLY                        equ     8370
ERROR_DS_OBJ_CLASS_NOT_DEFINED                  equ     8371
ERROR_DS_OBJ_CLASS_NOT_SUBCLASS                 equ     8372
ERROR_DS_NAME_REFERENCE_INVALID                 equ     8373
ERROR_DS_CROSS_REF_EXISTS                       equ     8374
ERROR_DS_CANT_DEL_MASTER_CROSSREF               equ     8375
ERROR_DS_SUBTREE_NOTIFY_NOT_NC_HEAD             equ     8376
ERROR_DS_NOTIFY_FILTER_TOO_COMPLEX              equ     8377
ERROR_DS_DUP_RDN                                equ     8378
ERROR_DS_DUP_OID                                equ     8379
ERROR_DS_DUP_MAPI_ID                            equ     8380
ERROR_DS_DUP_SCHEMA_ID_GUID                     equ     8381
ERROR_DS_DUP_LDAP_DISPLAY_NAME                  equ     8382
ERROR_DS_SEMANTIC_ATT_TEST                      equ     8383
ERROR_DS_SYNTAX_MISMATCH                        equ     8384
ERROR_DS_EXISTS_IN_MUST_HAVE                    equ     8385
ERROR_DS_EXISTS_IN_MAY_HAVE                     equ     8386
ERROR_DS_NONEXISTENT_MAY_HAVE                   equ     8387
ERROR_DS_NONEXISTENT_MUST_HAVE                  equ     8388
ERROR_DS_AUX_CLS_TEST_FAIL                      equ     8389
ERROR_DS_NONEXISTENT_POSS_SUP                   equ     8390
ERROR_DS_SUB_CLS_TEST_FAIL                      equ     8391
ERROR_DS_BAD_RDN_ATT_ID_SYNTAX                  equ     8392
ERROR_DS_EXISTS_IN_AUX_CLS                      equ     8393
ERROR_DS_EXISTS_IN_SUB_CLS                      equ     8394
ERROR_DS_EXISTS_IN_POSS_SUP                     equ     8395
ERROR_DS_RECALCSCHEMA_FAILED                    equ     8396
ERROR_DS_TREE_DELETE_NOT_FINISHED               equ     8397
ERROR_DS_CANT_DELETE                            equ     8398
ERROR_DS_ATT_SCHEMA_REQ_ID                      equ     8399
ERROR_DS_BAD_ATT_SCHEMA_SYNTAX                  equ     8400
ERROR_DS_CANT_CACHE_ATT                         equ     8401
ERROR_DS_CANT_CACHE_CLASS                       equ     8402
ERROR_DS_CANT_REMOVE_ATT_CACHE                  equ     8403
ERROR_DS_CANT_REMOVE_CLASS_CACHE                equ     8404
ERROR_DS_CANT_RETRIEVE_DN                       equ     8405
ERROR_DS_MISSING_SUPREF                         equ     8406
ERROR_DS_CANT_RETRIEVE_INSTANCE                 equ     8407
ERROR_DS_CODE_INCONSISTENCY                     equ     8408
ERROR_DS_DATABASE_ERROR                         equ     8409
ERROR_DS_GOVERNSID_MISSING                      equ     8410
ERROR_DS_MISSING_EXPECTED_ATT                   equ     8411
ERROR_DS_NCNAME_MISSING_CR_REF                  equ     8412
ERROR_DS_SECURITY_CHECKING_ERROR                equ     8413
ERROR_DS_SCHEMA_NOT_LOADED                      equ     8414
ERROR_DS_SCHEMA_ALLOC_FAILED                    equ     8415
ERROR_DS_ATT_SCHEMA_REQ_SYNTAX                  equ     8416
ERROR_DS_GCVERIFY_ERROR                         equ     8417
ERROR_DS_DRA_SCHEMA_MISMATCH                    equ     8418
ERROR_DS_CANT_FIND_DSA_OBJ                      equ     8419
ERROR_DS_CANT_FIND_EXPECTED_NC                  equ     8420
ERROR_DS_CANT_FIND_NC_IN_CACHE                  equ     8421
ERROR_DS_CANT_RETRIEVE_CHILD                    equ     8422
ERROR_DS_SECURITY_ILLEGAL_MODIFY                equ     8423
ERROR_DS_CANT_REPLACE_HIDDEN_REC                equ     8424
ERROR_DS_BAD_HIERARCHY_FILE                     equ     8425
ERROR_DS_BUILD_HIERARCHY_TABLE_FAILED           equ     8426
ERROR_DS_CONFIG_PARAM_MISSING                   equ     8427
ERROR_DS_COUNTING_AB_INDICES_FAILED             equ     8428
ERROR_DS_HIERARCHY_TABLE_MALLOC_FAILED          equ     8429
ERROR_DS_INTERNAL_FAILURE                       equ     8430
ERROR_DS_UNKNOWN_ERROR                          equ     8431
ERROR_DS_ROOT_REQUIRES_CLASS_TOP                equ     8432
ERROR_DS_REFUSING_FSMO_ROLES                    equ     8433
ERROR_DS_MISSING_FSMO_SETTINGS                  equ     8434
ERROR_DS_UNABLE_TO_SURRENDER_ROLES              equ     8435
ERROR_DS_DRA_GENERIC                            equ     8436
ERROR_DS_DRA_INVALID_PARAMETER                  equ     8437
ERROR_DS_DRA_BUSY                               equ     8438
ERROR_DS_DRA_BAD_DN                             equ     8439
ERROR_DS_DRA_BAD_NC                             equ     8440
ERROR_DS_DRA_DN_EXISTS                          equ     8441
ERROR_DS_DRA_INTERNAL_ERROR                     equ     8442
ERROR_DS_DRA_INCONSISTENT_DIT                   equ     8443
ERROR_DS_DRA_CONNECTION_FAILED                  equ     8444
ERROR_DS_DRA_BAD_INSTANCE_TYPE                  equ     8445
ERROR_DS_DRA_OUT_OF_MEM                         equ     8446
ERROR_DS_DRA_MAIL_PROBLEM                       equ     8447
ERROR_DS_DRA_REF_ALREADY_EXISTS                 equ     8448
ERROR_DS_DRA_REF_NOT_FOUND                      equ     8449
ERROR_DS_DRA_OBJ_IS_REP_SOURCE                  equ     8450
ERROR_DS_DRA_DB_ERROR                           equ     8451
ERROR_DS_DRA_NO_REPLICA                         equ     8452
ERROR_DS_DRA_ACCESS_DENIED                      equ     8453
ERROR_DS_DRA_NOT_SUPPORTED                      equ     8454
ERROR_DS_DRA_RPC_CANCELLED                      equ     8455
ERROR_DS_DRA_SOURCE_DISABLED                    equ     8456
ERROR_DS_DRA_SINK_DISABLED                      equ     8457
ERROR_DS_DRA_NAME_COLLISION                     equ     8458
ERROR_DS_DRA_SOURCE_REINSTALLED                 equ     8459
ERROR_DS_DRA_MISSING_PARENT                     equ     8460
ERROR_DS_DRA_PREEMPTED                          equ     8461
ERROR_DS_DRA_ABANDON_SYNC                       equ     8462
ERROR_DS_DRA_SHUTDOWN                           equ     8463
ERROR_DS_DRA_INCOMPATIBLE_PARTIAL_SET           equ     8464
ERROR_DS_DRA_SOURCE_IS_PARTIAL_REPLICA          equ     8465
ERROR_DS_DRA_EXTN_CONNECTION_FAILED             equ     8466
ERROR_DS_INSTALL_SCHEMA_MISMATCH                equ     8467
ERROR_DS_DUP_LINK_ID                            equ     8468
ERROR_DS_NAME_ERROR_RESOLVING                   equ     8469
ERROR_DS_NAME_ERROR_NOT_FOUND                   equ     8470
ERROR_DS_NAME_ERROR_NOT_UNIQUE                  equ     8471
ERROR_DS_NAME_ERROR_NO_MAPPING                  equ     8472
ERROR_DS_NAME_ERROR_DOMAIN_ONLY                 equ     8473
ERROR_DS_NAME_ERROR_NO_SYNTACTICAL_MAPPING      equ     8474
ERROR_DS_CONSTRUCTED_ATT_MOD                    equ     8475
ERROR_DS_WRONG_OM_OBJ_CLASS                     equ     8476
ERROR_DS_DRA_REPL_PENDING                       equ     8477
ERROR_DS_DS_REQUIRED                            equ     8478
ERROR_DS_INVALID_LDAP_DISPLAY_NAME              equ     8479
ERROR_DS_NON_BASE_SEARCH                        equ     8480
ERROR_DS_CANT_RETRIEVE_ATTS                     equ     8481
ERROR_DS_BACKLINK_WITHOUT_LINK                  equ     8482
ERROR_DS_EPOCH_MISMATCH                         equ     8483
ERROR_DS_SRC_NAME_MISMATCH                      equ     8484
ERROR_DS_SRC_AND_DST_NC_IDENTICAL               equ     8485
ERROR_DS_DST_NC_MISMATCH                        equ     8486
ERROR_DS_NOT_AUTHORITIVE_FOR_DST_NC             equ     8487
ERROR_DS_SRC_GUID_MISMATCH                      equ     8488
ERROR_DS_CANT_MOVE_DELETED_OBJECT               equ     8489
ERROR_DS_PDC_OPERATION_IN_PROGRESS              equ     8490
ERROR_DS_CROSS_DOMAIN_CLEANUP_REQD              equ     8491
ERROR_DS_ILLEGAL_XDOM_MOVE_OPERATION            equ     8492
ERROR_DS_CANT_WITH_ACCT_GROUP_MEMBERSHPS        equ     8493
ERROR_DS_NC_MUST_HAVE_NC_PARENT                 equ     8494
ERROR_DS_CR_IMPOSSIBLE_TO_VALIDATE              equ     8495
ERROR_DS_DST_DOMAIN_NOT_NATIVE                  equ     8496
ERROR_DS_MISSING_INFRASTRUCTURE_CONTAINER       equ     8497
ERROR_DS_CANT_MOVE_ACCOUNT_GROUP                equ     8498
ERROR_DS_CANT_MOVE_RESOURCE_GROUP               equ     8499
ERROR_DS_INVALID_SEARCH_FLAG                    equ     8500
ERROR_DS_NO_TREE_DELETE_ABOVE_NC                equ     8501
ERROR_DS_COULDNT_LOCK_TREE_FOR_DELETE           equ     8502
ERROR_DS_COULDNT_IDENTIFY_OBJECTS_FOR_TREE_DELETE equ   8503
ERROR_DS_SAM_INIT_FAILURE                       equ     8504
ERROR_DS_SENSITIVE_GROUP_VIOLATION              equ     8505
ERROR_DS_CANT_MOD_PRIMARYGROUPID                equ     8506
ERROR_DS_ILLEGAL_BASE_SCHEMA_MOD                equ     8507
ERROR_DS_NONSAFE_SCHEMA_CHANGE                  equ     8508
ERROR_DS_SCHEMA_UPDATE_DISALLOWED               equ     8509
ERROR_DS_CANT_CREATE_UNDER_SCHEMA               equ     8510
ERROR_DS_INSTALL_NO_SRC_SCH_VERSION             equ     8511
ERROR_DS_INSTALL_NO_SCH_VERSION_IN_INIFILE      equ     8512
ERROR_DS_INVALID_GROUP_TYPE                     equ     8513
ERROR_DS_NO_NEST_GLOBALGROUP_IN_MIXEDDOMAIN     equ     8514
ERROR_DS_NO_NEST_LOCALGROUP_IN_MIXEDDOMAIN      equ     8515
ERROR_DS_GLOBAL_CANT_HAVE_LOCAL_MEMBER          equ     8516
ERROR_DS_GLOBAL_CANT_HAVE_UNIVERSAL_MEMBER      equ     8517
ERROR_DS_UNIVERSAL_CANT_HAVE_LOCAL_MEMBER       equ     8518
ERROR_DS_GLOBAL_CANT_HAVE_CROSSDOMAIN_MEMBER    equ     8519
ERROR_DS_LOCAL_CANT_HAVE_CROSSDOMAIN_LOCAL_MEMBER equ   8520
ERROR_DS_HAVE_PRIMARY_MEMBERS                   equ     8521
ERROR_DS_STRING_SD_CONVERSION_FAILED            equ     8522
ERROR_DS_NAMING_MASTER_GC                       equ     8523
ERROR_DS_DNS_LOOKUP_FAILURE                     equ     8524
ERROR_DS_COULDNT_UPDATE_SPNS                    equ     8525
ERROR_DS_CANT_RETRIEVE_SD                       equ     8526
ERROR_DS_KEY_NOT_UNIQUE                         equ     8527
ERROR_DS_WRONG_LINKED_ATT_SYNTAX                equ     8528
ERROR_DS_SAM_NEED_BOOTKEY_PASSWORD              equ     8529
ERROR_DS_SAM_NEED_BOOTKEY_FLOPPY                equ     8530
ERROR_DS_CANT_START                             equ     8531
ERROR_DS_INIT_FAILURE                           equ     8532
ERROR_DS_NO_PKT_PRIVACY_ON_CONNECTION           equ     8533
ERROR_DS_SOURCE_DOMAIN_IN_FOREST                equ     8534
ERROR_DS_DESTINATION_DOMAIN_NOT_IN_FOREST       equ     8535
ERROR_DS_DESTINATION_AUDITING_NOT_ENABLED       equ     8536
ERROR_DS_CANT_FIND_DC_FOR_SRC_DOMAIN            equ     8537
ERROR_DS_SRC_OBJ_NOT_GROUP_OR_USER              equ     8538
ERROR_DS_SRC_SID_EXISTS_IN_FOREST               equ     8539
ERROR_DS_SRC_AND_DST_OBJECT_CLASS_MISMATCH      equ     8540
ERROR_SAM_INIT_FAILURE                          equ     8541
ERROR_DS_DRA_SCHEMA_INFO_SHIP                   equ     8542
ERROR_DS_DRA_SCHEMA_CONFLICT                    equ     8543
ERROR_DS_DRA_EARLIER_SCHEMA_CONFLICT            equ     8544
ERROR_DS_DRA_OBJ_NC_MISMATCH                    equ     8545
ERROR_DS_NC_STILL_HAS_DSAS                      equ     8546
ERROR_DS_GC_REQUIRED                            equ     8547
ERROR_DS_LOCAL_MEMBER_OF_LOCAL_ONLY             equ     8548
ERROR_DS_NO_FPO_IN_UNIVERSAL_GROUPS             equ     8549
ERROR_DS_CANT_ADD_TO_GC                         equ     8550
ERROR_DS_NO_CHECKPOINT_WITH_PDC                 equ     8551
ERROR_DS_SOURCE_AUDITING_NOT_ENABLED            equ     8552
ERROR_DS_CANT_CREATE_IN_NONDOMAIN_NC            equ     8553
ERROR_DS_INVALID_NAME_FOR_SPN                   equ     8554
ERROR_DS_FILTER_USES_CONTRUCTED_ATTRS           equ     8555
ERROR_DS_UNICODEPWD_NOT_IN_QUOTES               equ     8556
ERROR_DS_MACHINE_ACCOUNT_QUOTA_EXCEEDED         equ     8557
ERROR_DS_MUST_BE_RUN_ON_DST_DC                  equ     8558
ERROR_DS_SRC_DC_MUST_BE_SP4_OR_GREATER          equ     8559
ERROR_DS_CANT_TREE_DELETE_CRITICAL_OBJ          equ     8560
ERROR_DS_INIT_FAILURE_CONSOLE                   equ     8561
ERROR_DS_SAM_INIT_FAILURE_CONSOLE               equ     8562
ERROR_DS_FOREST_VERSION_TOO_HIGH                equ     8563
ERROR_DS_DOMAIN_VERSION_TOO_HIGH                equ     8564
ERROR_DS_FOREST_VERSION_TOO_LOW                 equ     8565
ERROR_DS_DOMAIN_VERSION_TOO_LOW                 equ     8566
ERROR_DS_INCOMPATIBLE_VERSION                   equ     8567
ERROR_DS_LOW_DSA_VERSION                        equ     8568
ERROR_DS_NO_BEHAVIOR_VERSION_IN_MIXEDDOMAIN     equ     8569
ERROR_DS_NOT_SUPPORTED_SORT_ORDER               equ     8570
ERROR_DS_NAME_NOT_UNIQUE                        equ     8571
ERROR_DS_MACHINE_ACCOUNT_CREATED_PRENT4         equ     8572
ERROR_DS_OUT_OF_VERSION_STORE                   equ     8573
ERROR_DS_INCOMPATIBLE_CONTROLS_USED             equ     8574
ERROR_DS_NO_REF_DOMAIN                          equ     8575
ERROR_DS_RESERVED_LINK_ID                       equ     8576
ERROR_DS_LINK_ID_NOT_AVAILABLE                  equ     8577
ERROR_DS_AG_CANT_HAVE_UNIVERSAL_MEMBER          equ     8578
ERROR_DS_MODIFYDN_DISALLOWED_BY_INSTANCE_TYPE   equ     8579
ERROR_DS_NO_OBJECT_MOVE_IN_SCHEMA_NC            equ     8580
ERROR_DS_MODIFYDN_DISALLOWED_BY_FLAG            equ     8581
ERROR_DS_MODIFYDN_WRONG_GRANDPARENT             equ     8582
ERROR_DS_NAME_ERROR_TRUST_REFERRAL              equ     8583
ERROR_NOT_SUPPORTED_ON_STANDARD_SERVER          equ     8584
ERROR_DS_CANT_ACCESS_REMOTE_PART_OF_AD          equ     8585
ERROR_DS_CR_IMPOSSIBLE_TO_VALIDATE_V2           equ     8586
ERROR_DS_THREAD_LIMIT_EXCEEDED                  equ     8587
ERROR_DS_NOT_CLOSEST                            equ     8588
ERROR_DS_CANT_DERIVE_SPN_WITHOUT_SERVER_REF     equ     8589
ERROR_DS_SINGLE_USER_MODE_FAILED                equ     8590
ERROR_DS_NTDSCRIPT_SYNTAX_ERROR                 equ     8591
ERROR_DS_NTDSCRIPT_PROCESS_ERROR                equ     8592
ERROR_DS_DIFFERENT_REPL_EPOCHS                  equ     8593
ERROR_DS_DRS_EXTENSIONS_CHANGED                 equ     8594
ERROR_DS_REPLICA_SET_CHANGE_NOT_ALLOWED_ON_DISABLED_CR equ 8595
ERROR_DS_NO_MSDS_INTID                          equ     8596
ERROR_DS_DUP_MSDS_INTID                         equ     8597
ERROR_DS_EXISTS_IN_RDNATTID                     equ     8598
ERROR_DS_AUTHORIZATION_FAILED                   equ     8599
ERROR_DS_INVALID_SCRIPT                         equ     8600
ERROR_DS_REMOTE_CROSSREF_OP_FAILED              equ     8601
ERROR_DS_CROSS_REF_BUSY                         equ     8602
ERROR_DS_CANT_DERIVE_SPN_FOR_DELETED_DOMAIN     equ     8603
ERROR_DS_CANT_DEMOTE_WITH_WRITEABLE_NC          equ     8604
ERROR_DS_DUPLICATE_ID_FOUND                     equ     8605
ERROR_DS_INSUFFICIENT_ATTR_TO_CREATE_OBJECT     equ     8606
ERROR_DS_GROUP_CONVERSION_ERROR                 equ     8607
ERROR_DS_CANT_MOVE_APP_BASIC_GROUP              equ     8608
ERROR_DS_CANT_MOVE_APP_QUERY_GROUP              equ     8609
ERROR_DS_ROLE_NOT_VERIFIED                      equ     8610
ERROR_DS_WKO_CONTAINER_CANNOT_BE_SPECIAL        equ     8611
ERROR_DS_DOMAIN_RENAME_IN_PROGRESS              equ     8612
ERROR_DS_EXISTING_AD_CHILD_NC                   equ     8613
ERROR_DS_REPL_LIFETIME_EXCEEDED                 equ     8614
ERROR_DS_DISALLOWED_IN_SYSTEM_CONTAINER         equ     8615
ERROR_DS_LDAP_SEND_QUEUE_FULL                   equ     8616
ERROR_DS_DRA_OUT_SCHEDULE_WINDOW                equ     8617
ERROR_DS_POLICY_NOT_KNOWN                       equ     8618
ERROR_NO_SITE_SETTINGS_OBJECT                   equ     8619
ERROR_NO_SECRETS                                equ     8620
ERROR_NO_WRITABLE_DC_FOUND                      equ     8621
ERROR_DS_NO_SERVER_OBJECT                       equ     8622
ERROR_DS_NO_NTDSA_OBJECT                        equ     8623
ERROR_DS_NON_ASQ_SEARCH                         equ     8624
ERROR_DS_AUDIT_FAILURE                          equ     8625
ERROR_DS_INVALID_SEARCH_FLAG_SUBTREE            equ     8626
ERROR_DS_INVALID_SEARCH_FLAG_TUPLE              equ     8627
ERROR_DS_HIERARCHY_TABLE_TOO_DEEP               equ     8628
ERROR_DS_DRA_CORRUPT_UTD_VECTOR                 equ     8629
ERROR_DS_DRA_SECRETS_DENIED                     equ     8630
ERROR_DS_RESERVED_MAPI_ID                       equ     8631
ERROR_DS_MAPI_ID_NOT_AVAILABLE                  equ     8632
ERROR_DS_DRA_MISSING_KRBTGT_SECRET              equ     8633
ERROR_DS_DOMAIN_NAME_EXISTS_IN_FOREST           equ     8634
ERROR_DS_FLAT_NAME_EXISTS_IN_FOREST             equ     8635
ERROR_INVALID_USER_PRINCIPAL_NAME               equ     8636
ERROR_DS_OID_MAPPED_GROUP_CANT_HAVE_MEMBERS     equ     8637
ERROR_DS_OID_NOT_FOUND                          equ     8638
ERROR_DS_DRA_RECYCLED_TARGET                    equ     8639
DNS_ERROR_RESPONSE_CODES_BASE                   equ     9000
DNS_ERROR_RCODE_NO_ERROR                        equ     NO_ERROR
DNS_ERROR_MASK                                  equ     DNS_ERROR_RESPONSE_CODES_BASE
DNS_ERROR_RCODE_FORMAT_ERROR                    equ     9001
DNS_ERROR_RCODE_SERVER_FAILURE                  equ     9002
DNS_ERROR_RCODE_NAME_ERROR                      equ     9003
DNS_ERROR_RCODE_NOT_IMPLEMENTED                 equ     9004
DNS_ERROR_RCODE_REFUSED                         equ     9005
DNS_ERROR_RCODE_YXDOMAIN                        equ     9006
DNS_ERROR_RCODE_YXRRSET                         equ     9007
DNS_ERROR_RCODE_NXRRSET                         equ     9008
DNS_ERROR_RCODE_NOTAUTH                         equ     9009
DNS_ERROR_RCODE_NOTZONE                         equ     9010
DNS_ERROR_RCODE_BADSIG                          equ     9016
DNS_ERROR_RCODE_BADKEY                          equ     9017
DNS_ERROR_RCODE_BADTIME                         equ     9018
DNS_ERROR_RCODE_LAST                            equ     DNS_ERROR_RCODE_BADTIME
DNS_ERROR_PACKET_FMT_BASE                       equ     9500
DNS_INFO_NO_RECORDS                             equ     9501
DNS_ERROR_BAD_PACKET                            equ     9502
DNS_ERROR_NO_PACKET                             equ     9503
DNS_ERROR_RCODE                                 equ     9504
DNS_ERROR_UNSECURE_PACKET                       equ     9505
DNS_STATUS_PACKET_UNSECURE                      equ     DNS_ERROR_UNSECURE_PACKET
DNS_ERROR_NO_MEMORY                             equ     ERROR_OUTOFMEMORY
DNS_ERROR_INVALID_NAME                          equ     ERROR_INVALID_NAME
DNS_ERROR_INVALID_DATA                          equ     ERROR_INVALID_DATA
DNS_ERROR_GENERAL_API_BASE                      equ     9550
DNS_ERROR_INVALID_TYPE                          equ     9551
DNS_ERROR_INVALID_IP_ADDRESS                    equ     9552
DNS_ERROR_INVALID_PROPERTY                      equ     9553
DNS_ERROR_TRY_AGAIN_LATER                       equ     9554
DNS_ERROR_NOT_UNIQUE                            equ     9555
DNS_ERROR_NON_RFC_NAME                          equ     9556
DNS_STATUS_FQDN                                 equ     9557
DNS_STATUS_DOTTED_NAME                          equ     9558
DNS_STATUS_SINGLE_PART_NAME                     equ     9559
DNS_ERROR_INVALID_NAME_CHAR                     equ     9560
DNS_ERROR_NUMERIC_NAME                          equ     9561
DNS_ERROR_NOT_ALLOWED_ON_ROOT_SERVER            equ     9562
DNS_ERROR_NOT_ALLOWED_UNDER_DELEGATION          equ     9563
DNS_ERROR_CANNOT_FIND_ROOT_HINTS                equ     9564
DNS_ERROR_INCONSISTENT_ROOT_HINTS               equ     9565
DNS_ERROR_DWORD_VALUE_TOO_SMALL                 equ     9566
DNS_ERROR_DWORD_VALUE_TOO_LARGE                 equ     9567
DNS_ERROR_BACKGROUND_LOADING                    equ     9568
DNS_ERROR_NOT_ALLOWED_ON_RODC                   equ     9569
DNS_ERROR_NOT_ALLOWED_UNDER_DNAME               equ     9570
DNS_ERROR_DELEGATION_REQUIRED                   equ     9571
DNS_ERROR_INVALID_POLICY_TABLE                  equ     9572
DNS_ERROR_ZONE_BASE                             equ     9600
DNS_ERROR_ZONE_DOES_NOT_EXIST                   equ     9601
DNS_ERROR_NO_ZONE_INFO                          equ     9602
DNS_ERROR_INVALID_ZONE_OPERATION                equ     9603
DNS_ERROR_ZONE_CONFIGURATION_ERROR              equ     9604
DNS_ERROR_ZONE_HAS_NO_SOA_RECORD                equ     9605
DNS_ERROR_ZONE_HAS_NO_NS_RECORDS                equ     9606
DNS_ERROR_ZONE_LOCKED                           equ     9607
DNS_ERROR_ZONE_CREATION_FAILED                  equ     9608
DNS_ERROR_ZONE_ALREADY_EXISTS                   equ     9609
DNS_ERROR_AUTOZONE_ALREADY_EXISTS               equ     9610
DNS_ERROR_INVALID_ZONE_TYPE                     equ     9611
DNS_ERROR_SECONDARY_REQUIRES_MASTER_IP          equ     9612
DNS_ERROR_ZONE_NOT_SECONDARY                    equ     9613
DNS_ERROR_NEED_SECONDARY_ADDRESSES              equ     9614
DNS_ERROR_WINS_INIT_FAILED                      equ     9615
DNS_ERROR_NEED_WINS_SERVERS                     equ     9616
DNS_ERROR_NBSTAT_INIT_FAILED                    equ     9617
DNS_ERROR_SOA_DELETE_INVALID                    equ     9618
DNS_ERROR_FORWARDER_ALREADY_EXISTS              equ     9619
DNS_ERROR_ZONE_REQUIRES_MASTER_IP               equ     9620
DNS_ERROR_ZONE_IS_SHUTDOWN                      equ     9621
DNS_ERROR_DATAFILE_BASE                         equ     9650
DNS_ERROR_PRIMARY_REQUIRES_DATAFILE             equ     9651
DNS_ERROR_INVALID_DATAFILE_NAME                 equ     9652
DNS_ERROR_DATAFILE_OPEN_FAILURE                 equ     9653
DNS_ERROR_FILE_WRITEBACK_FAILED                 equ     9654
DNS_ERROR_DATAFILE_PARSING                      equ     9655
DNS_ERROR_DATABASE_BASE                         equ     9700
DNS_ERROR_RECORD_DOES_NOT_EXIST                 equ     9701
DNS_ERROR_RECORD_FORMAT                         equ     9702
DNS_ERROR_NODE_CREATION_FAILED                  equ     9703
DNS_ERROR_UNKNOWN_RECORD_TYPE                   equ     9704
DNS_ERROR_RECORD_TIMED_OUT                      equ     9705
DNS_ERROR_NAME_NOT_IN_ZONE                      equ     9706
DNS_ERROR_CNAME_LOOP                            equ     9707
DNS_ERROR_NODE_IS_CNAME                         equ     9708
DNS_ERROR_CNAME_COLLISION                       equ     9709
DNS_ERROR_RECORD_ONLY_AT_ZONE_ROOT              equ     9710
DNS_ERROR_RECORD_ALREADY_EXISTS                 equ     9711
DNS_ERROR_SECONDARY_DATA                        equ     9712
DNS_ERROR_NO_CREATE_CACHE_DATA                  equ     9713
DNS_ERROR_NAME_DOES_NOT_EXIST                   equ     9714
DNS_WARNING_PTR_CREATE_FAILED                   equ     9715
DNS_WARNING_DOMAIN_UNDELETED                    equ     9716
DNS_ERROR_DS_UNAVAILABLE                        equ     9717
DNS_ERROR_DS_ZONE_ALREADY_EXISTS                equ     9718
DNS_ERROR_NO_BOOTFILE_IF_DS_ZONE                equ     9719
DNS_ERROR_NODE_IS_DNAME                         equ     9720
DNS_ERROR_DNAME_COLLISION                       equ     9721
DNS_ERROR_ALIAS_LOOP                            equ     9722
DNS_ERROR_OPERATION_BASE                        equ     9750
DNS_INFO_AXFR_COMPLETE                          equ     9751
DNS_ERROR_AXFR                                  equ     9752
DNS_INFO_ADDED_LOCAL_WINS                       equ     9753
DNS_ERROR_SECURE_BASE                           equ     9800
DNS_STATUS_CONTINUE_NEEDED                      equ     9801
DNS_ERROR_SETUP_BASE                            equ     9850
DNS_ERROR_NO_TCPIP                              equ     9851
DNS_ERROR_NO_DNS_SERVERS                        equ     9852
DNS_ERROR_DP_BASE                               equ     9900
DNS_ERROR_DP_DOES_NOT_EXIST                     equ     9901
DNS_ERROR_DP_ALREADY_EXISTS                     equ     9902
DNS_ERROR_DP_NOT_ENLISTED                       equ     9903
DNS_ERROR_DP_ALREADY_ENLISTED                   equ     9904
DNS_ERROR_DP_NOT_AVAILABLE                      equ     9905
DNS_ERROR_DP_FSMO_ERROR                         equ     9906

WSABASEERR                                      equ     10000
WSAEINTR                                        equ     10004
WSAEBADF                                        equ     10009
WSAEACCES                                       equ     10013
WSAEFAULT                                       equ     10014
WSAEINVAL                                       equ     10022
WSAEMFILE                                       equ     10024
WSAEWOULDBLOCK                                  equ     10035
WSAEINPROGRESS                                  equ     10036
WSAEALREADY                                     equ     10037
WSAENOTSOCK                                     equ     10038
WSAEDESTADDRREQ                                 equ     10039
WSAEMSGSIZE                                     equ     10040
WSAEPROTOTYPE                                   equ     10041
WSAENOPROTOOPT                                  equ     10042
WSAEPROTONOSUPPORT                              equ     10043
WSAESOCKTNOSUPPORT                              equ     10044
WSAEOPNOTSUPP                                   equ     10045
WSAEPFNOSUPPORT                                 equ     10046
WSAEAFNOSUPPORT                                 equ     10047
WSAEADDRINUSE                                   equ     10048
WSAEADDRNOTAVAIL                                equ     10049
WSAENETDOWN                                     equ     10050
WSAENETUNREACH                                  equ     10051
WSAENETRESET                                    equ     10052
WSAECONNABORTED                                 equ     10053
WSAECONNRESET                                   equ     10054
WSAENOBUFS                                      equ     10055
WSAEISCONN                                      equ     10056
WSAENOTCONN                                     equ     10057
WSAESHUTDOWN                                    equ     10058
WSAETOOMANYREFS                                 equ     10059
WSAETIMEDOUT                                    equ     10060
WSAECONNREFUSED                                 equ     10061
WSAELOOP                                        equ     10062
WSAENAMETOOLONG                                 equ     10063
WSAEHOSTDOWN                                    equ     10064
WSAEHOSTUNREACH                                 equ     10065
WSAENOTEMPTY                                    equ     10066
WSAEPROCLIM                                     equ     10067
WSAEUSERS                                       equ     10068
WSAEDQUOT                                       equ     10069
WSAESTALE                                       equ     10070
WSAEREMOTE                                      equ     10071
WSASYSNOTREADY                                  equ     10091
WSAVERNOTSUPPORTED                              equ     10092
WSANOTINITIALISED                               equ     10093
WSAEDISCON                                      equ     10101
WSAENOMORE                                      equ     10102
WSAECANCELLED                                   equ     10103
WSAEINVALIDPROCTABLE                            equ     10104
WSAEINVALIDPROVIDER                             equ     10105
WSAEPROVIDERFAILEDINIT                          equ     10106
WSASYSCALLFAILURE                               equ     10107
WSASERVICE_NOT_FOUND                            equ     10108
WSATYPE_NOT_FOUND                               equ     10109
WSA_E_NO_MORE                                   equ     10110
WSA_E_CANCELLED                                 equ     10111
WSAEREFUSED                                     equ     10112
WSAHOST_NOT_FOUND                               equ     11001
WSATRY_AGAIN                                    equ     11002
WSANO_RECOVERY                                  equ     11003
WSANO_DATA                                      equ     11004
WSA_QOS_RECEIVERS                               equ     11005
WSA_QOS_SENDERS                                 equ     11006
WSA_QOS_NO_SENDERS                              equ     11007
WSA_QOS_NO_RECEIVERS                            equ     11008
WSA_QOS_REQUEST_CONFIRMED                       equ     11009
WSA_QOS_ADMISSION_FAILURE                       equ     11010
WSA_QOS_POLICY_FAILURE                          equ     11011
WSA_QOS_BAD_STYLE                               equ     11012
WSA_QOS_BAD_OBJECT                              equ     11013
WSA_QOS_TRAFFIC_CTRL_ERROR                      equ     11014
WSA_QOS_GENERIC_ERROR                           equ     11015
WSA_QOS_ESERVICETYPE                            equ     11016
WSA_QOS_EFLOWSPEC                               equ     11017
WSA_QOS_EPROVSPECBUF                            equ     11018
WSA_QOS_EFILTERSTYLE                            equ     11019
WSA_QOS_EFILTERTYPE                             equ     11020
WSA_QOS_EFILTERCOUNT                            equ     11021
WSA_QOS_EOBJLENGTH                              equ     11022
WSA_QOS_EFLOWCOUNT                              equ     11023
WSA_QOS_EUNKOWNPSOBJ                            equ     11024
WSA_QOS_EPOLICYOBJ                              equ     11025
WSA_QOS_EFLOWDESC                               equ     11026
WSA_QOS_EPSFLOWSPEC                             equ     11027
WSA_QOS_EPSFILTERSPEC                           equ     11028
WSA_QOS_ESDMODEOBJ                              equ     11029
WSA_QOS_ESHAPERATEOBJ                           equ     11030
WSA_QOS_RESERVED_PETYPE                         equ     11031
WSA_SECURE_HOST_NOT_FOUND                       equ     11032
WSA_IPSEC_NAME_POLICY_ERROR                     equ     11033

ERROR_IPSEC_QM_POLICY_EXISTS                    equ     13000
ERROR_IPSEC_QM_POLICY_NOT_FOUND                 equ     13001
ERROR_IPSEC_QM_POLICY_IN_USE                    equ     13002
ERROR_IPSEC_MM_POLICY_EXISTS                    equ     13003
ERROR_IPSEC_MM_POLICY_NOT_FOUND                 equ     13004
ERROR_IPSEC_MM_POLICY_IN_USE                    equ     13005
ERROR_IPSEC_MM_FILTER_EXISTS                    equ     13006
ERROR_IPSEC_MM_FILTER_NOT_FOUND                 equ     13007
ERROR_IPSEC_TRANSPORT_FILTER_EXISTS             equ     13008
ERROR_IPSEC_TRANSPORT_FILTER_NOT_FOUND          equ     13009
ERROR_IPSEC_MM_AUTH_EXISTS                      equ     13010
ERROR_IPSEC_MM_AUTH_NOT_FOUND                   equ     13011
ERROR_IPSEC_MM_AUTH_IN_USE                      equ     13012
ERROR_IPSEC_DEFAULT_MM_POLICY_NOT_FOUND         equ     13013
ERROR_IPSEC_DEFAULT_MM_AUTH_NOT_FOUND           equ     13014
ERROR_IPSEC_DEFAULT_QM_POLICY_NOT_FOUND         equ     13015
ERROR_IPSEC_TUNNEL_FILTER_EXISTS                equ     13016
ERROR_IPSEC_TUNNEL_FILTER_NOT_FOUND             equ     13017
ERROR_IPSEC_MM_FILTER_PENDING_DELETION          equ     13018
ERROR_IPSEC_TRANSPORT_FILTER_PENDING_DELETION   equ     13019
ERROR_IPSEC_TUNNEL_FILTER_PENDING_DELETION      equ     13020
ERROR_IPSEC_MM_POLICY_PENDING_DELETION          equ     13021
ERROR_IPSEC_MM_AUTH_PENDING_DELETION            equ     13022
ERROR_IPSEC_QM_POLICY_PENDING_DELETION          equ     13023
WARNING_IPSEC_MM_POLICY_PRUNED                  equ     13024
WARNING_IPSEC_QM_POLICY_PRUNED                  equ     13025
ERROR_IPSEC_IKE_NEG_STATUS_BEGIN                equ     13800
ERROR_IPSEC_IKE_AUTH_FAIL                       equ     13801
ERROR_IPSEC_IKE_ATTRIB_FAIL                     equ     13802
ERROR_IPSEC_IKE_NEGOTIATION_PENDING             equ     13803
ERROR_IPSEC_IKE_GENERAL_PROCESSING_ERROR        equ     13804
ERROR_IPSEC_IKE_TIMED_OUT                       equ     13805
ERROR_IPSEC_IKE_NO_CERT                         equ     13806
ERROR_IPSEC_IKE_SA_DELETED                      equ     13807
ERROR_IPSEC_IKE_SA_REAPED                       equ     13808
ERROR_IPSEC_IKE_MM_ACQUIRE_DROP                 equ     13809
ERROR_IPSEC_IKE_QM_ACQUIRE_DROP                 equ     13810
ERROR_IPSEC_IKE_QUEUE_DROP_MM                   equ     13811
ERROR_IPSEC_IKE_QUEUE_DROP_NO_MM                equ     13812
ERROR_IPSEC_IKE_DROP_NO_RESPONSE                equ     13813
ERROR_IPSEC_IKE_MM_DELAY_DROP                   equ     13814
ERROR_IPSEC_IKE_QM_DELAY_DROP                   equ     13815
ERROR_IPSEC_IKE_ERROR                           equ     13816
ERROR_IPSEC_IKE_CRL_FAILED                      equ     13817
ERROR_IPSEC_IKE_INVALID_KEY_USAGE               equ     13818
ERROR_IPSEC_IKE_INVALID_CERT_TYPE               equ     13819
ERROR_IPSEC_IKE_NO_PRIVATE_KEY                  equ     13820
ERROR_IPSEC_IKE_SIMULTANEOUS_REKEY              equ     13821
ERROR_IPSEC_IKE_DH_FAIL                         equ     13822
ERROR_IPSEC_IKE_CRITICAL_PAYLOAD_NOT_RECOGNIZED equ     13823
ERROR_IPSEC_IKE_INVALID_HEADER                  equ     13824
ERROR_IPSEC_IKE_NO_POLICY                       equ     13825
ERROR_IPSEC_IKE_INVALID_SIGNATURE               equ     13826
ERROR_IPSEC_IKE_KERBEROS_ERROR                  equ     13827
ERROR_IPSEC_IKE_NO_PUBLIC_KEY                   equ     13828
ERROR_IPSEC_IKE_PROCESS_ERR                     equ     13829
ERROR_IPSEC_IKE_PROCESS_ERR_SA                  equ     13830
ERROR_IPSEC_IKE_PROCESS_ERR_PROP                equ     13831
ERROR_IPSEC_IKE_PROCESS_ERR_TRANS               equ     13832
ERROR_IPSEC_IKE_PROCESS_ERR_KE                  equ     13833
ERROR_IPSEC_IKE_PROCESS_ERR_ID                  equ     13834
ERROR_IPSEC_IKE_PROCESS_ERR_CERT                equ     13835
ERROR_IPSEC_IKE_PROCESS_ERR_CERT_REQ            equ     13836
ERROR_IPSEC_IKE_PROCESS_ERR_HASH                equ     13837
ERROR_IPSEC_IKE_PROCESS_ERR_SIG                 equ     13838
ERROR_IPSEC_IKE_PROCESS_ERR_NONCE               equ     13839
ERROR_IPSEC_IKE_PROCESS_ERR_NOTIFY              equ     13840
ERROR_IPSEC_IKE_PROCESS_ERR_DELETE              equ     13841
ERROR_IPSEC_IKE_PROCESS_ERR_VENDOR              equ     13842
ERROR_IPSEC_IKE_INVALID_PAYLOAD                 equ     13843
ERROR_IPSEC_IKE_LOAD_SOFT_SA                    equ     13844
ERROR_IPSEC_IKE_SOFT_SA_TORN_DOWN               equ     13845
ERROR_IPSEC_IKE_INVALID_COOKIE                  equ     13846
ERROR_IPSEC_IKE_NO_PEER_CERT                    equ     13847
ERROR_IPSEC_IKE_PEER_CRL_FAILED                 equ     13848
ERROR_IPSEC_IKE_POLICY_CHANGE                   equ     13849
ERROR_IPSEC_IKE_NO_MM_POLICY                    equ     13850
ERROR_IPSEC_IKE_NOTCBPRIV                       equ     13851
ERROR_IPSEC_IKE_SECLOADFAIL                     equ     13852
ERROR_IPSEC_IKE_FAILSSPINIT                     equ     13853
ERROR_IPSEC_IKE_FAILQUERYSSP                    equ     13854
ERROR_IPSEC_IKE_SRVACQFAIL                      equ     13855
ERROR_IPSEC_IKE_SRVQUERYCRED                    equ     13856
ERROR_IPSEC_IKE_GETSPIFAIL                      equ     13857
ERROR_IPSEC_IKE_INVALID_FILTER                  equ     13858
ERROR_IPSEC_IKE_OUT_OF_MEMORY                   equ     13859
ERROR_IPSEC_IKE_ADD_UPDATE_KEY_FAILED           equ     13860
ERROR_IPSEC_IKE_INVALID_POLICY                  equ     13861
ERROR_IPSEC_IKE_UNKNOWN_DOI                     equ     13862
ERROR_IPSEC_IKE_INVALID_SITUATION               equ     13863
ERROR_IPSEC_IKE_DH_FAILURE                      equ     13864
ERROR_IPSEC_IKE_INVALID_GROUP                   equ     13865
ERROR_IPSEC_IKE_ENCRYPT                         equ     13866
ERROR_IPSEC_IKE_DECRYPT                         equ     13867
ERROR_IPSEC_IKE_POLICY_MATCH                    equ     13868
ERROR_IPSEC_IKE_UNSUPPORTED_ID                  equ     13869
ERROR_IPSEC_IKE_INVALID_HASH                    equ     13870
ERROR_IPSEC_IKE_INVALID_HASH_ALG                equ     13871
ERROR_IPSEC_IKE_INVALID_HASH_SIZE               equ     13872
ERROR_IPSEC_IKE_INVALID_ENCRYPT_ALG             equ     13873
ERROR_IPSEC_IKE_INVALID_AUTH_ALG                equ     13874
ERROR_IPSEC_IKE_INVALID_SIG                     equ     13875
ERROR_IPSEC_IKE_LOAD_FAILED                     equ     13876
ERROR_IPSEC_IKE_RPC_DELETE                      equ     13877
ERROR_IPSEC_IKE_BENIGN_REINIT                   equ     13878
ERROR_IPSEC_IKE_INVALID_RESPONDER_LIFETIME_NOTIFY equ   13879
ERROR_IPSEC_IKE_INVALID_MAJOR_VERSION           equ     13880
ERROR_IPSEC_IKE_INVALID_CERT_KEYLEN             equ     13881
ERROR_IPSEC_IKE_MM_LIMIT                        equ     13882
ERROR_IPSEC_IKE_NEGOTIATION_DISABLED            equ     13883
ERROR_IPSEC_IKE_QM_LIMIT                        equ     13884
ERROR_IPSEC_IKE_MM_EXPIRED                      equ     13885
ERROR_IPSEC_IKE_PEER_MM_ASSUMED_INVALID         equ     13886
ERROR_IPSEC_IKE_CERT_CHAIN_POLICY_MISMATCH      equ     13887
ERROR_IPSEC_IKE_UNEXPECTED_MESSAGE_ID           equ     13888
ERROR_IPSEC_IKE_INVALID_AUTH_PAYLOAD            equ     13889
ERROR_IPSEC_IKE_DOS_COOKIE_SENT                 equ     13890
ERROR_IPSEC_IKE_SHUTTING_DOWN                   equ     13891
ERROR_IPSEC_IKE_CGA_AUTH_FAILED                 equ     13892
ERROR_IPSEC_IKE_PROCESS_ERR_NATOA               equ     13893
ERROR_IPSEC_IKE_INVALID_MM_FOR_QM               equ     13894
ERROR_IPSEC_IKE_QM_EXPIRED                      equ     13895
ERROR_IPSEC_IKE_TOO_MANY_FILTERS                equ     13896
ERROR_IPSEC_IKE_NEG_STATUS_END                  equ     13897
ERROR_IPSEC_IKE_KILL_DUMMY_NAP_TUNNEL           equ     13898
ERROR_IPSEC_IKE_INNER_IP_ASSIGNMENT_FAILURE     equ     13899
ERROR_IPSEC_IKE_REQUIRE_CP_PAYLOAD_MISSING      equ     13900
ERROR_IPSEC_KEY_MODULE_IMPERSONATION_NEGOTIATION_PENDING equ 13901
ERROR_IPSEC_IKE_COEXISTENCE_SUPPRESS            equ     13902
ERROR_IPSEC_IKE_RATELIMIT_DROP                  equ     13903
ERROR_IPSEC_IKE_PEER_DOESNT_SUPPORT_MOBIKE      equ     13904
ERROR_IPSEC_IKE_AUTHORIZATION_FAILURE           equ     13905
ERROR_IPSEC_IKE_STRONG_CRED_AUTHORIZATION_FAILURE equ   13906
ERROR_IPSEC_IKE_AUTHORIZATION_FAILURE_WITH_OPTIONAL_RETRY equ 13907
ERROR_IPSEC_IKE_STRONG_CRED_AUTHORIZATION_AND_CERTMAP_FAILURE equ 13908
ERROR_IPSEC_IKE_NEG_STATUS_EXTENDED_END         equ     13909
ERROR_IPSEC_BAD_SPI                             equ     13910
ERROR_IPSEC_SA_LIFETIME_EXPIRED                 equ     13911
ERROR_IPSEC_WRONG_SA                            equ     13912
ERROR_IPSEC_REPLAY_CHECK_FAILED                 equ     13913
ERROR_IPSEC_INVALID_PACKET                      equ     13914
ERROR_IPSEC_INTEGRITY_CHECK_FAILED              equ     13915
ERROR_IPSEC_CLEAR_TEXT_DROP                     equ     13916
ERROR_IPSEC_AUTH_FIREWALL_DROP                  equ     13917
ERROR_IPSEC_THROTTLE_DROP                       equ     13918
ERROR_IPSEC_DOSP_BLOCK                          equ     13925
ERROR_IPSEC_DOSP_RECEIVED_MULTICAST             equ     13926
ERROR_IPSEC_DOSP_INVALID_PACKET                 equ     13927
ERROR_IPSEC_DOSP_STATE_LOOKUP_FAILED            equ     13928
ERROR_IPSEC_DOSP_MAX_ENTRIES                    equ     13929
ERROR_IPSEC_DOSP_KEYMOD_NOT_ALLOWED             equ     13930
ERROR_IPSEC_DOSP_NOT_INSTALLED                  equ     13931
ERROR_IPSEC_DOSP_MAX_PER_IP_RATELIMIT_QUEUES    equ     13932
ERROR_SXS_SECTION_NOT_FOUND                     equ     14000
ERROR_SXS_CANT_GEN_ACTCTX                       equ     14001
ERROR_SXS_INVALID_ACTCTXDATA_FORMAT             equ     14002
ERROR_SXS_ASSEMBLY_NOT_FOUND                    equ     14003
ERROR_SXS_MANIFEST_FORMAT_ERROR                 equ     14004
ERROR_SXS_MANIFEST_PARSE_ERROR                  equ     14005
ERROR_SXS_ACTIVATION_CONTEXT_DISABLED           equ     14006
ERROR_SXS_KEY_NOT_FOUND                         equ     14007
ERROR_SXS_VERSION_CONFLICT                      equ     14008
ERROR_SXS_WRONG_SECTION_TYPE                    equ     14009
ERROR_SXS_THREAD_QUERIES_DISABLED               equ     14010
ERROR_SXS_PROCESS_DEFAULT_ALREADY_SET           equ     14011
ERROR_SXS_UNKNOWN_ENCODING_GROUP                equ     14012
ERROR_SXS_UNKNOWN_ENCODING                      equ     14013
ERROR_SXS_INVALID_XML_NAMESPACE_URI             equ     14014
ERROR_SXS_ROOT_MANIFEST_DEPENDENCY_NOT_INSTALLED equ    14015
ERROR_SXS_LEAF_MANIFEST_DEPENDENCY_NOT_INSTALLED equ    14016
ERROR_SXS_INVALID_ASSEMBLY_IDENTITY_ATTRIBUTE   equ     14017
ERROR_SXS_MANIFEST_MISSING_REQUIRED_DEFAULT_NAMESPACE equ 14018
ERROR_SXS_MANIFEST_INVALID_REQUIRED_DEFAULT_NAMESPACE equ 14019
ERROR_SXS_PRIVATE_MANIFEST_CROSS_PATH_WITH_REPARSE_POINT equ 14020
ERROR_SXS_DUPLICATE_DLL_NAME                    equ     14021
ERROR_SXS_DUPLICATE_WINDOWCLASS_NAME            equ     14022
ERROR_SXS_DUPLICATE_CLSID                       equ     14023
ERROR_SXS_DUPLICATE_IID                         equ     14024
ERROR_SXS_DUPLICATE_TLBID                       equ     14025
ERROR_SXS_DUPLICATE_PROGID                      equ     14026
ERROR_SXS_DUPLICATE_ASSEMBLY_NAME               equ     14027
ERROR_SXS_FILE_HASH_MISMATCH                    equ     14028
ERROR_SXS_POLICY_PARSE_ERROR                    equ     14029
ERROR_SXS_XML_E_MISSINGQUOTE                    equ     14030
ERROR_SXS_XML_E_COMMENTSYNTAX                   equ     14031
ERROR_SXS_XML_E_BADSTARTNAMECHAR                equ     14032
ERROR_SXS_XML_E_BADNAMECHAR                     equ     14033
ERROR_SXS_XML_E_BADCHARINSTRING                 equ     14034
ERROR_SXS_XML_E_XMLDECLSYNTAX                   equ     14035
ERROR_SXS_XML_E_BADCHARDATA                     equ     14036
ERROR_SXS_XML_E_MISSINGWHITESPACE               equ     14037
ERROR_SXS_XML_E_EXPECTINGTAGEND                 equ     14038
ERROR_SXS_XML_E_MISSINGSEMICOLON                equ     14039
ERROR_SXS_XML_E_UNBALANCEDPAREN                 equ     14040
ERROR_SXS_XML_E_INTERNALERROR                   equ     14041
ERROR_SXS_XML_E_UNEXPECTED_WHITESPACE           equ     14042
ERROR_SXS_XML_E_INCOMPLETE_ENCODING             equ     14043
ERROR_SXS_XML_E_MISSING_PAREN                   equ     14044
ERROR_SXS_XML_E_EXPECTINGCLOSEQUOTE             equ     14045
ERROR_SXS_XML_E_MULTIPLE_COLONS                 equ     14046
ERROR_SXS_XML_E_INVALID_DECIMAL                 equ     14047
ERROR_SXS_XML_E_INVALID_HEXIDECIMAL             equ     14048
ERROR_SXS_XML_E_INVALID_UNICODE                 equ     14049
ERROR_SXS_XML_E_WHITESPACEORQUESTIONMARK        equ     14050
ERROR_SXS_XML_E_UNEXPECTEDENDTAG                equ     14051
ERROR_SXS_XML_E_UNCLOSEDTAG                     equ     14052
ERROR_SXS_XML_E_DUPLICATEATTRIBUTE              equ     14053
ERROR_SXS_XML_E_MULTIPLEROOTS                   equ     14054
ERROR_SXS_XML_E_INVALIDATROOTLEVEL              equ     14055
ERROR_SXS_XML_E_BADXMLDECL                      equ     14056
ERROR_SXS_XML_E_MISSINGROOT                     equ     14057
ERROR_SXS_XML_E_UNEXPECTEDEOF                   equ     14058
ERROR_SXS_XML_E_BADPEREFINSUBSET                equ     14059
ERROR_SXS_XML_E_UNCLOSEDSTARTTAG                equ     14060
ERROR_SXS_XML_E_UNCLOSEDENDTAG                  equ     14061
ERROR_SXS_XML_E_UNCLOSEDSTRING                  equ     14062
ERROR_SXS_XML_E_UNCLOSEDCOMMENT                 equ     14063
ERROR_SXS_XML_E_UNCLOSEDDECL                    equ     14064
ERROR_SXS_XML_E_UNCLOSEDCDATA                   equ     14065
ERROR_SXS_XML_E_RESERVEDNAMESPACE               equ     14066
ERROR_SXS_XML_E_INVALIDENCODING                 equ     14067
ERROR_SXS_XML_E_INVALIDSWITCH                   equ     14068
ERROR_SXS_XML_E_BADXMLCASE                      equ     14069
ERROR_SXS_XML_E_INVALID_STANDALONE              equ     14070
ERROR_SXS_XML_E_UNEXPECTED_STANDALONE           equ     14071
ERROR_SXS_XML_E_INVALID_VERSION                 equ     14072
ERROR_SXS_XML_E_MISSINGEQUALS                   equ     14073
ERROR_SXS_PROTECTION_RECOVERY_FAILED            equ     14074
ERROR_SXS_PROTECTION_PUBLIC_KEY_TOO_SHORT       equ     14075
ERROR_SXS_PROTECTION_CATALOG_NOT_VALID          equ     14076
ERROR_SXS_UNTRANSLATABLE_HRESULT                equ     14077
ERROR_SXS_PROTECTION_CATALOG_FILE_MISSING       equ     14078
ERROR_SXS_MISSING_ASSEMBLY_IDENTITY_ATTRIBUTE   equ     14079
ERROR_SXS_INVALID_ASSEMBLY_IDENTITY_ATTRIBUTE_NAME equ  14080
ERROR_SXS_ASSEMBLY_MISSING                      equ     14081
ERROR_SXS_CORRUPT_ACTIVATION_STACK              equ     14082
ERROR_SXS_CORRUPTION                            equ     14083
ERROR_SXS_EARLY_DEACTIVATION                    equ     14084
ERROR_SXS_INVALID_DEACTIVATION                  equ     14085
ERROR_SXS_MULTIPLE_DEACTIVATION                 equ     14086
ERROR_SXS_PROCESS_TERMINATION_REQUESTED         equ     14087
ERROR_SXS_RELEASE_ACTIVATION_CONTEXT            equ     14088
ERROR_SXS_SYSTEM_DEFAULT_ACTIVATION_CONTEXT_EMPTY equ   14089
ERROR_SXS_INVALID_IDENTITY_ATTRIBUTE_VALUE      equ     14090
ERROR_SXS_INVALID_IDENTITY_ATTRIBUTE_NAME       equ     14091
ERROR_SXS_IDENTITY_DUPLICATE_ATTRIBUTE          equ     14092
ERROR_SXS_IDENTITY_PARSE_ERROR                  equ     14093
ERROR_MALFORMED_SUBSTITUTION_STRING             equ     14094
ERROR_SXS_INCORRECT_PUBLIC_KEY_TOKEN            equ     14095
ERROR_UNMAPPED_SUBSTITUTION_STRING              equ     14096
ERROR_SXS_ASSEMBLY_NOT_LOCKED                   equ     14097
ERROR_SXS_COMPONENT_STORE_CORRUPT               equ     14098
ERROR_ADVANCED_INSTALLER_FAILED                 equ     14099
ERROR_XML_ENCODING_MISMATCH                     equ     14100
ERROR_SXS_MANIFEST_IDENTITY_SAME_BUT_CONTENTS_DIFFERENT equ 14101
ERROR_SXS_IDENTITIES_DIFFERENT                  equ     14102
ERROR_SXS_ASSEMBLY_IS_NOT_A_DEPLOYMENT          equ     14103
ERROR_SXS_FILE_NOT_PART_OF_ASSEMBLY             equ     14104
ERROR_SXS_MANIFEST_TOO_BIG                      equ     14105
ERROR_SXS_SETTING_NOT_REGISTERED                equ     14106
ERROR_SXS_TRANSACTION_CLOSURE_INCOMPLETE        equ     14107
ERROR_SMI_PRIMITIVE_INSTALLER_FAILED            equ     14108
ERROR_GENERIC_COMMAND_FAILED                    equ     14109
ERROR_SXS_FILE_HASH_MISSING                     equ     14110
ERROR_EVT_INVALID_CHANNEL_PATH                  equ     15000
ERROR_EVT_INVALID_QUERY                         equ     15001
ERROR_EVT_PUBLISHER_METADATA_NOT_FOUND          equ     15002
ERROR_EVT_EVENT_TEMPLATE_NOT_FOUND              equ     15003
ERROR_EVT_INVALID_PUBLISHER_NAME                equ     15004
ERROR_EVT_INVALID_EVENT_DATA                    equ     15005
ERROR_EVT_CHANNEL_NOT_FOUND                     equ     15007
ERROR_EVT_MALFORMED_XML_TEXT                    equ     15008
ERROR_EVT_SUBSCRIPTION_TO_DIRECT_CHANNEL        equ     15009
ERROR_EVT_CONFIGURATION_ERROR                   equ     15010
ERROR_EVT_QUERY_RESULT_STALE                    equ     15011
ERROR_EVT_QUERY_RESULT_INVALID_POSITION         equ     15012
ERROR_EVT_NON_VALIDATING_MSXML                  equ     15013
ERROR_EVT_FILTER_ALREADYSCOPED                  equ     15014
ERROR_EVT_FILTER_NOTELTSET                      equ     15015
ERROR_EVT_FILTER_INVARG                         equ     15016
ERROR_EVT_FILTER_INVTEST                        equ     15017
ERROR_EVT_FILTER_INVTYPE                        equ     15018
ERROR_EVT_FILTER_PARSEERR                       equ     15019
ERROR_EVT_FILTER_UNSUPPORTEDOP                  equ     15020
ERROR_EVT_FILTER_UNEXPECTEDTOKEN                equ     15021
ERROR_EVT_INVALID_OPERATION_OVER_ENABLED_DIRECT_CHANNEL equ 15022
ERROR_EVT_INVALID_CHANNEL_PROPERTY_VALUE        equ     15023
ERROR_EVT_INVALID_PUBLISHER_PROPERTY_VALUE      equ     15024
ERROR_EVT_CHANNEL_CANNOT_ACTIVATE               equ     15025
ERROR_EVT_FILTER_TOO_COMPLEX                    equ     15026
ERROR_EVT_MESSAGE_NOT_FOUND                     equ     15027
ERROR_EVT_MESSAGE_ID_NOT_FOUND                  equ     15028
ERROR_EVT_UNRESOLVED_VALUE_INSERT               equ     15029
ERROR_EVT_UNRESOLVED_PARAMETER_INSERT           equ     15030
ERROR_EVT_MAX_INSERTS_REACHED                   equ     15031
ERROR_EVT_EVENT_DEFINITION_NOT_FOUND            equ     15032
ERROR_EVT_MESSAGE_LOCALE_NOT_FOUND              equ     15033
ERROR_EVT_VERSION_TOO_OLD                       equ     15034
ERROR_EVT_VERSION_TOO_NEW                       equ     15035
ERROR_EVT_CANNOT_OPEN_CHANNEL_OF_QUERY          equ     15036
ERROR_EVT_PUBLISHER_DISABLED                    equ     15037
ERROR_EVT_FILTER_OUT_OF_RANGE                   equ     15038
ERROR_EC_SUBSCRIPTION_CANNOT_ACTIVATE           equ     15080
ERROR_EC_LOG_DISABLED                           equ     15081
ERROR_EC_CIRCULAR_FORWARDING                    equ     15082
ERROR_EC_CREDSTORE_FULL                         equ     15083
ERROR_EC_CRED_NOT_FOUND                         equ     15084
ERROR_EC_NO_ACTIVE_CHANNEL                      equ     15085
ERROR_MUI_FILE_NOT_FOUND                        equ     15100
ERROR_MUI_INVALID_FILE                          equ     15101
ERROR_MUI_INVALID_RC_CONFIG                     equ     15102
ERROR_MUI_INVALID_LOCALE_NAME                   equ     15103
ERROR_MUI_INVALID_ULTIMATEFALLBACK_NAME         equ     15104
ERROR_MUI_FILE_NOT_LOADED                       equ     15105
ERROR_RESOURCE_ENUM_USER_STOP                   equ     15106
ERROR_MUI_INTLSETTINGS_UILANG_NOT_INSTALLED     equ     15107
ERROR_MUI_INTLSETTINGS_INVALID_LOCALE_NAME      equ     15108
ERROR_MCA_INVALID_CAPABILITIES_STRING           equ     15200
ERROR_MCA_INVALID_VCP_VERSION                   equ     15201
ERROR_MCA_MONITOR_VIOLATES_MCCS_SPECIFICATION   equ     15202
ERROR_MCA_MCCS_VERSION_MISMATCH                 equ     15203
ERROR_MCA_UNSUPPORTED_MCCS_VERSION              equ     15204
ERROR_MCA_INTERNAL_ERROR                        equ     15205
ERROR_MCA_INVALID_TECHNOLOGY_TYPE_RETURNED      equ     15206
ERROR_MCA_UNSUPPORTED_COLOR_TEMPERATURE         equ     15207
ERROR_AMBIGUOUS_SYSTEM_DEVICE                   equ     15250
ERROR_SYSTEM_DEVICE_NOT_FOUND                   equ     15299
ERROR_HASH_NOT_SUPPORTED                        equ     15300
ERROR_HASH_NOT_PRESENT                          equ     15301
SEVERITY_SUCCESS                                equ     0
SEVERITY_ERROR                                  equ     1

E_UNEXPECTED                                    equ     8000FFFFH

INTERNET_ERROR_BASE                             equ     12000
ERROR_INTERNET_OUT_OF_HANDLES                   equ     (INTERNET_ERROR_BASE+1)
ERROR_INTERNET_TIMEOUT                          equ     (INTERNET_ERROR_BASE+2)
ERROR_INTERNET_EXTENDED_ERROR                   equ     (INTERNET_ERROR_BASE+3)
ERROR_INTERNET_INTERNAL_ERROR                   equ     (INTERNET_ERROR_BASE+4)
ERROR_INTERNET_INVALID_URL                      equ     (INTERNET_ERROR_BASE+5)
ERROR_INTERNET_UNRECOGNIZED_SCHEME              equ     (INTERNET_ERROR_BASE+6)
ERROR_INTERNET_NAME_NOT_RESOLVED                equ     (INTERNET_ERROR_BASE+7)
ERROR_INTERNET_PROTOCOL_NOT_FOUND               equ     (INTERNET_ERROR_BASE+8)
ERROR_INTERNET_INVALID_OPTION                   equ     (INTERNET_ERROR_BASE+9)
ERROR_INTERNET_BAD_OPTION_LENGTH                equ     (INTERNET_ERROR_BASE+10)
ERROR_INTERNET_OPTION_NOT_SETTABLE              equ     (INTERNET_ERROR_BASE+11)
ERROR_INTERNET_SHUTDOWN                         equ     (INTERNET_ERROR_BASE+12)
ERROR_INTERNET_INCORRECT_USER_NAME              equ     (INTERNET_ERROR_BASE+13)
ERROR_INTERNET_INCORRECT_PASSWORD               equ     (INTERNET_ERROR_BASE+14)
ERROR_INTERNET_LOGIN_FAILURE                    equ     (INTERNET_ERROR_BASE+15)
ERROR_INTERNET_INVALID_OPERATION                equ     (INTERNET_ERROR_BASE+16)
ERROR_INTERNET_OPERATION_CANCELLED              equ     (INTERNET_ERROR_BASE+17)
ERROR_INTERNET_INCORRECT_HANDLE_TYPE            equ     (INTERNET_ERROR_BASE+18)
ERROR_INTERNET_INCORRECT_HANDLE_STATE           equ     (INTERNET_ERROR_BASE+19)
ERROR_INTERNET_NOT_PROXY_REQUEST                equ     (INTERNET_ERROR_BASE+20)
ERROR_INTERNET_REGISTRY_VALUE_NOT_FOUND         equ     (INTERNET_ERROR_BASE+21)
ERROR_INTERNET_BAD_REGISTRY_PARAMETER           equ     (INTERNET_ERROR_BASE+22)
ERROR_INTERNET_NO_DIRECT_ACCESS                 equ     (INTERNET_ERROR_BASE+23)
ERROR_INTERNET_NO_CONTEXT                       equ     (INTERNET_ERROR_BASE+24)
ERROR_INTERNET_NO_CALLBACK                      equ     (INTERNET_ERROR_BASE+25)
ERROR_INTERNET_REQUEST_PENDING                  equ     (INTERNET_ERROR_BASE+26)
ERROR_INTERNET_INCORRECT_FORMAT                 equ     (INTERNET_ERROR_BASE+27)
ERROR_INTERNET_ITEM_NOT_FOUND                   equ     (INTERNET_ERROR_BASE+28)
ERROR_INTERNET_CANNOT_CONNECT                   equ     (INTERNET_ERROR_BASE+29)
ERROR_INTERNET_CONNECTION_ABORTED               equ     (INTERNET_ERROR_BASE+30)
ERROR_INTERNET_CONNECTION_RESET                 equ     (INTERNET_ERROR_BASE+31)
ERROR_INTERNET_FORCE_RETRY                      equ     (INTERNET_ERROR_BASE+32)
ERROR_INTERNET_INVALID_PROXY_REQUEST            equ     (INTERNET_ERROR_BASE+33)
ERROR_INTERNET_NEED_UI                          equ     (INTERNET_ERROR_BASE+34)
ERROR_INTERNET_HANDLE_EXISTS                    equ     (INTERNET_ERROR_BASE+36)
ERROR_INTERNET_SEC_CERT_DATE_INVALID            equ     (INTERNET_ERROR_BASE+37)
ERROR_INTERNET_SEC_CERT_CN_INVALID              equ     (INTERNET_ERROR_BASE+38)
ERROR_INTERNET_HTTP_TO_HTTPS_ON_REDIR           equ     (INTERNET_ERROR_BASE+39)
ERROR_INTERNET_HTTPS_TO_HTTP_ON_REDIR           equ     (INTERNET_ERROR_BASE+40)
ERROR_INTERNET_MIXED_SECURITY                   equ     (INTERNET_ERROR_BASE+41)
ERROR_INTERNET_CHG_POST_IS_NON_SECURE           equ     (INTERNET_ERROR_BASE+42)
ERROR_INTERNET_POST_IS_NON_SECURE               equ     (INTERNET_ERROR_BASE+43)
ERROR_INTERNET_CLIENT_AUTH_CERT_NEEDED          equ     (INTERNET_ERROR_BASE+44)
ERROR_INTERNET_INVALID_CA                       equ     (INTERNET_ERROR_BASE+45)
ERROR_INTERNET_CLIENT_AUTH_NOT_SETUP            equ     (INTERNET_ERROR_BASE+46)
ERROR_INTERNET_ASYNC_THREAD_FAILED              equ     (INTERNET_ERROR_BASE+47)
ERROR_INTERNET_REDIRECT_SCHEME_CHANGE           equ     (INTERNET_ERROR_BASE+48)
ERROR_INTERNET_DIALOG_PENDING                   equ     (INTERNET_ERROR_BASE+49)
ERROR_INTERNET_RETRY_DIALOG                     equ     (INTERNET_ERROR_BASE+50)
ERROR_INTERNET_HTTPS_HTTP_SUBMIT_REDIR          equ     (INTERNET_ERROR_BASE+52)
ERROR_INTERNET_INSERT_CDROM                     equ     (INTERNET_ERROR_BASE+53)
ERROR_FTP_TRANSFER_IN_PROGRESS                  equ     (INTERNET_ERROR_BASE+110)
ERROR_FTP_DROPPED                               equ     (INTERNET_ERROR_BASE+111)
ERROR_FTP_NO_PASSIVE_MODE                       equ     (INTERNET_ERROR_BASE+112)
ERROR_GOPHER_PROTOCOL_ERROR                     equ     (INTERNET_ERROR_BASE+130)
ERROR_GOPHER_NOT_FILE                           equ     (INTERNET_ERROR_BASE+131)
ERROR_GOPHER_DATA_ERROR                         equ     (INTERNET_ERROR_BASE+132)
ERROR_GOPHER_END_OF_DATA                        equ     (INTERNET_ERROR_BASE+133)
ERROR_GOPHER_INVALID_LOCATOR                    equ     (INTERNET_ERROR_BASE+134)
ERROR_GOPHER_INCORRECT_LOCATOR_TYPE             equ      (INTERNET_ERROR_BASE+135)
ERROR_GOPHER_NOT_GOPHER_PLUS                    equ     (INTERNET_ERROR_BASE+136)
ERROR_GOPHER_ATTRIBUTE_NOT_FOUND                equ     (INTERNET_ERROR_BASE+137)
ERROR_GOPHER_UNKNOWN_LOCATOR                    equ     (INTERNET_ERROR_BASE+138)
ERROR_HTTP_HEADER_NOT_FOUND                     equ     (INTERNET_ERROR_BASE+150)
ERROR_HTTP_DOWNLEVEL_SERVER                     equ     (INTERNET_ERROR_BASE+151)
ERROR_HTTP_INVALID_SERVER_RESPONSE              equ     (INTERNET_ERROR_BASE+152)
ERROR_HTTP_INVALID_HEADER                       equ     (INTERNET_ERROR_BASE+153)
ERROR_HTTP_INVALID_QUERY_REQUEST                equ     (INTERNET_ERROR_BASE+154)
ERROR_HTTP_HEADER_ALREADY_EXISTS                equ     (INTERNET_ERROR_BASE+155)
ERROR_HTTP_REDIRECT_FAILED                      equ     (INTERNET_ERROR_BASE+156)
ERROR_HTTP_NOT_REDIRECTED                       equ     (INTERNET_ERROR_BASE+160)
ERROR_HTTP_COOKIE_NEEDS_CONFIRMATION            equ     (INTERNET_ERROR_BASE+161)
ERROR_HTTP_COOKIE_DECLINED                      equ     (INTERNET_ERROR_BASE+162)
ERROR_HTTP_REDIRECT_NEEDS_CONFIRMATION          equ     (INTERNET_ERROR_BASE+168)
ERROR_INTERNET_SECURITY_CHANNEL_ERROR           equ     (INTERNET_ERROR_BASE+157)
ERROR_INTERNET_UNABLE_TO_CACHE_FILE             equ     (INTERNET_ERROR_BASE+158)
ERROR_INTERNET_TCPIP_NOT_INSTALLED              equ     (INTERNET_ERROR_BASE+159)
ERROR_INTERNET_DISCONNECTED                     equ     (INTERNET_ERROR_BASE+163)
ERROR_INTERNET_SERVER_UNREACHABLE               equ     (INTERNET_ERROR_BASE+164)
ERROR_INTERNET_PROXY_SERVER_UNREACHABLE         equ     (INTERNET_ERROR_BASE+165)
ERROR_INTERNET_BAD_AUTO_PROXY_SCRIPT            equ     (INTERNET_ERROR_BASE+166)
ERROR_INTERNET_UNABLE_TO_DOWNLOAD_SCRIPT        equ     (INTERNET_ERROR_BASE+167)
ERROR_INTERNET_SEC_INVALID_CERT                 equ     (INTERNET_ERROR_BASE+169)
ERROR_INTERNET_SEC_CERT_REVOKED                 equ     (INTERNET_ERROR_BASE+170)
ERROR_INTERNET_FAILED_DUETOSECURITYCHECK        equ     (INTERNET_ERROR_BASE+171)
ERROR_INTERNET_NOT_INITIALIZED                  equ     (INTERNET_ERROR_BASE+172)
ERROR_INTERNET_NEED_MSN_SSPI_PKG                equ     (INTERNET_ERROR_BASE+173)
ERROR_INTERNET_LOGIN_FAILURE_DISPLAY_ENTITY_BODY equ    (INTERNET_ERROR_BASE+174)
INTERNET_ERROR_LAST                             equ     ERROR_INTERNET_LOGIN_FAILURE_DISPLAY_ENTITY_BODY

#ifdef APP_WIN64
    E_NOTIMPL                                   equ     80000001H
    E_OUTOFMEMORY                               equ     80000002H
    E_INVALIDARG                                equ     80000003H
    E_NOINTERFACE                               equ     80000004H
    E_POINTER                                   equ     80000005H
    E_HANDLE                                    equ     80000006H
    E_ABORT                                     equ     80000007H
    E_FAIL                                      equ     80000008H
    E_ACCESSDENIED                              equ     80000009H
#else
    NOERROR                                     equ     0
    E_NOTIMPL                                   equ     80004001H
    E_OUTOFMEMORY                               equ     8007000EH
    E_INVALIDARG                                equ     80070057H
    E_NOINTERFACE                               equ     80004002H
    E_POINTER                                   equ     80004003H
    E_HANDLE                                    equ     80070006H
    E_ABORT                                     equ     80004004H
    E_FAIL                                      equ     80004005H
    E_ACCESSDENIED                              equ     80070005H
#endif

E_PENDING                                       equ     8000000AH


CO_E_INIT_TLS                                   equ     80004006H
CO_E_INIT_SHARED_ALLOCATOR                      equ     80004007H
CO_E_INIT_MEMORY_ALLOCATOR                      equ     80004008H
CO_E_INIT_CLASS_CACHE                           equ     80004009H
CO_E_INIT_RPC_CHANNEL                           equ     8000400AH
CO_E_INIT_TLS_SET_CHANNEL_CONTROL               equ     8000400BH
CO_E_INIT_TLS_CHANNEL_CONTROL                   equ     8000400CH
CO_E_INIT_UNACCEPTED_USER_ALLOCATOR             equ     8000400DH
CO_E_INIT_SCM_MUTEX_EXISTS                      equ     8000400EH
CO_E_INIT_SCM_FILE_MAPPING_EXISTS               equ     8000400FH
CO_E_INIT_SCM_MAP_VIEW_OF_FILE                  equ     80004010H
CO_E_INIT_SCM_EXEC_FAILURE                      equ     80004011H
CO_E_INIT_ONLY_SINGLE_THREADED                  equ     80004012H
CO_E_CANT_REMOTE                                equ     80004013H
CO_E_BAD_SERVER_NAME                            equ     80004014H
CO_E_WRONG_SERVER_IDENTITY                      equ     80004015H
CO_E_OLE1DDE_DISABLED                           equ     80004016H
CO_E_RUNAS_SYNTAX                               equ     80004017H
CO_E_CREATEPROCESS_FAILURE                      equ     80004018H
CO_E_RUNAS_CREATEPROCESS_FAILURE                equ     80004019H
CO_E_RUNAS_LOGON_FAILURE                        equ     8000401AH
CO_E_LAUNCH_PERMSSION_DENIED                    equ     8000401BH
CO_E_START_SERVICE_FAILURE                      equ     8000401CH
CO_E_REMOTE_COMMUNICATION_FAILURE               equ     8000401DH
CO_E_SERVER_START_TIMEOUT                       equ     8000401EH
CO_E_CLSREG_INCONSISTENT                        equ     8000401FH
CO_E_IIDREG_INCONSISTENT                        equ     80004020H
CO_E_NOT_SUPPORTED                              equ     80004021H
CO_E_RELOAD_DLL                                 equ     80004022H
CO_E_MSI_ERROR                                  equ     80004023H
CO_E_ATTEMPT_TO_CREATE_OUTSIDE_CLIENT_CONTEXT   equ     80004024H
CO_E_SERVER_PAUSED                              equ     80004025H
CO_E_SERVER_NOT_PAUSED                          equ     80004026H
CO_E_CLASS_DISABLED                             equ     80004027H
CO_E_CLRNOTAVAILABLE                            equ     80004028H
CO_E_ASYNC_WORK_REJECTED                        equ     80004029H
CO_E_SERVER_INIT_TIMEOUT                        equ     8000402AH
CO_E_NO_SECCTX_IN_ACTIVATE                      equ     8000402BH
CO_E_TRACKER_CONFIG                             equ     80004030H
CO_E_THREADPOOL_CONFIG                          equ     80004031H
CO_E_SXS_CONFIG                                 equ     80004032H
CO_E_MALFORMED_SPN                              equ     80004033H
CO_E_FAILEDTOIMPERSONATE                        equ     80010123H
CO_E_FAILEDTOGETSECCTX                          equ     80010124H
CO_E_FAILEDTOOPENTHREADTOKEN                    equ     80010125H
CO_E_FAILEDTOGETTOKENINFO                       equ     80010126H
CO_E_TRUSTEEDOESNTMATCHCLIENT                   equ     80010127H
CO_E_FAILEDTOQUERYCLIENTBLANKET                 equ     80010128H
CO_E_FAILEDTOSETDACL                            equ     80010129H
CO_E_ACCESSCHECKFAILED                          equ     8001012AH
CO_E_NETACCESSAPIFAILED                         equ     8001012BH
CO_E_WRONGTRUSTEENAMESYNTAX                     equ     8001012CH
CO_E_INVALIDSID                                 equ     8001012DH
CO_E_CONVERSIONFAILED                           equ     8001012EH
CO_E_NOMATCHINGSIDFOUND                         equ     8001012FH
CO_E_LOOKUPACCSIDFAILED                         equ     80010130H
CO_E_NOMATCHINGNAMEFOUND                        equ     80010131H
CO_E_LOOKUPACCNAMEFAILED                        equ     80010132H
CO_E_SETSERLHNDLFAILED                          equ     80010133H
CO_E_FAILEDTOGETWINDIR                          equ     80010134H
CO_E_PATHTOOLONG                                equ     80010135H
CO_E_FAILEDTOGENUUID                            equ     80010136H
CO_E_FAILEDTOCREATEFILE                         equ     80010137H
CO_E_FAILEDTOCLOSEHANDLE                        equ     80010138H
CO_E_EXCEEDSYSACLLIMIT                          equ     80010139H
CO_E_ACESINWRONGORDER                           equ     8001013AH
CO_E_INCOMPATIBLESTREAMVERSION                  equ     8001013BH
CO_E_FAILEDTOOPENPROCESSTOKEN                   equ     8001013CH
CO_E_DECODEFAILED                               equ     8001013DH
CO_E_ACNOTINITIALIZED                           equ     8001013FH
CO_E_CANCEL_DISABLED                            equ     80010140H

S_OK                                            equ     0
S_FALSE                                         equ     1

OLE_E_FIRST                                     equ     80040000H
OLE_E_LAST                                      equ     800400FFH
OLE_S_FIRST                                     equ     00040000H
OLE_S_LAST                                      equ     000400FFH
OLE_E_OLEVERB                                   equ     80040000H
OLE_E_ADVF                                      equ     80040001H
OLE_E_ENUM_NOMORE                               equ     80040002H
OLE_E_ADVISENOTSUPPORTED                        equ     80040003H
OLE_E_NOCONNECTION                              equ     80040004H
OLE_E_NOTRUNNING                                equ     80040005H
OLE_E_NOCACHE                                   equ     80040006H
OLE_E_BLANK                                     equ     80040007H
OLE_E_CLASSDIFF                                 equ     80040008H
OLE_E_CANT_GETMONIKER                           equ     80040009H
OLE_E_CANT_BINDTOSOURCE                         equ     8004000AH
OLE_E_STATIC                                    equ     8004000BH
OLE_E_PROMPTSAVECANCELLED                       equ     8004000CH
OLE_E_INVALIDRECT                               equ     8004000DH
OLE_E_WRONGCOMPOBJ                              equ     8004000EH
OLE_E_INVALIDHWND                               equ     8004000FH
OLE_E_NOT_INPLACEACTIVE                         equ     80040010H
OLE_E_CANTCONVERT                               equ     80040011H
OLE_E_NOSTORAGE                                 equ     80040012H

DV_E_FORMATETC                                  equ     80040064H
DV_E_DVTARGETDEVICE                             equ     80040065H
DV_E_STGMEDIUM                                  equ     80040066H
DV_E_STATDATA                                   equ     80040067H
DV_E_LINDEX                                     equ     80040068H
DV_E_TYMED                                      equ     80040069H
DV_E_CLIPFORMAT                                 equ     8004006AH
DV_E_DVASPECT                                   equ     8004006BH
DV_E_DVTARGETDEVICE_SIZE                        equ     8004006CH
DV_E_NOIVIEWOBJECT                              equ     8004006DH

DRAGDROP_E_FIRST                                equ     80040100H
DRAGDROP_E_LAST                                 equ     8004010FH
DRAGDROP_S_FIRST                                equ     00040100H
DRAGDROP_S_LAST                                 equ     0004010FH
DRAGDROP_E_NOTREGISTERED                        equ     80040100H
DRAGDROP_E_ALREADYREGISTERED                    equ     80040101H
DRAGDROP_E_INVALIDHWND                          equ     80040102H

CLASSFACTORY_E_FIRST                            equ     80040110H
CLASSFACTORY_E_LAST                             equ     8004011FH
CLASSFACTORY_S_FIRST                            equ     00040110H
CLASSFACTORY_S_LAST                             equ     0004011FH

CLASS_E_NOAGGREGATION                           equ     80040110H
CLASS_E_CLASSNOTAVAILABLE                       equ     80040111H
CLASS_E_NOTLICENSED                             equ     80040112H

MARSHAL_E_FIRST                                 equ     80040120H
MARSHAL_E_LAST                                  equ     8004012FH
MARSHAL_S_FIRST                                 equ     00040120H
MARSHAL_S_LAST                                  equ     0004012FH

DATA_E_FIRST                                    equ     80040130H
DATA_E_LAST                                     equ     8004013FH
DATA_S_FIRST                                    equ     00040130H
DATA_S_LAST                                     equ     0004013FH

VIEW_E_FIRST                                    equ     80040140H
VIEW_E_LAST                                     equ     8004014FH
VIEW_S_FIRST                                    equ     00040140H
VIEW_S_LAST                                     equ     0004014FH
VIEW_E_DRAW                                     equ     80040140H

REGDB_E_FIRST                                   equ     80040150H
REGDB_E_LAST                                    equ     8004015FH
REGDB_S_FIRST                                   equ     00040150H
REGDB_S_LAST                                    equ     0004015FH
REGDB_E_READREGDB                               equ     80040150H
REGDB_E_WRITEREGDB                              equ     80040151H
REGDB_E_KEYMISSING                              equ     80040152H
REGDB_E_INVALIDVALUE                            equ     80040153H
REGDB_E_CLASSNOTREG                             equ     80040154H
REGDB_E_IIDNOTREG                               equ     80040155H
REGDB_E_BADTHREADINGMODEL                       equ     80040156H

CAT_E_FIRST                                     equ     80040160H
CAT_E_LAST                                      equ     80040161H
CAT_E_CATIDNOEXIST                              equ     80040160H
CAT_E_NODESCRIPTION                             equ     80040161H

CS_E_FIRST                                      equ     80040164H
CS_E_LAST                                       equ     8004016FH
CS_E_PACKAGE_NOTFOUND                           equ     80040164H
CS_E_NOT_DELETABLE                              equ     80040165H
CS_E_CLASS_NOTFOUND                             equ     80040166H
CS_E_INVALID_VERSION                            equ     80040167H
CS_E_NO_CLASSSTORE                              equ     80040168H
CS_E_OBJECT_NOTFOUND                            equ     80040169H
CS_E_OBJECT_ALREADY_EXISTS                      equ     8004016AH
CS_E_INVALID_PATH                               equ     8004016BH
CS_E_NETWORK_ERROR                              equ     8004016CH
CS_E_ADMIN_LIMIT_EXCEEDED                       equ     8004016DH
CS_E_SCHEMA_MISMATCH                            equ     8004016EH
CS_E_INTERNAL_ERROR                             equ     8004016FH

CACHE_E_FIRST                                   equ     80040170H
CACHE_E_LAST                                    equ     8004017FH
CACHE_S_FIRST                                   equ     00040170H
CACHE_S_LAST                                    equ     0004017FH
CACHE_E_NOCACHE_UPDATED                         equ     80040170H

OLEOBJ_E_FIRST                                  equ     80040180H
OLEOBJ_E_LAST                                   equ     8004018FH
OLEOBJ_S_FIRST                                  equ     00040180H
OLEOBJ_S_LAST                                   equ     0004018FH
OLEOBJ_E_NOVERBS                                equ     80040180H
OLEOBJ_E_INVALIDVERB                            equ     80040181H

CLIENTSITE_E_FIRST                              equ     80040190H
CLIENTSITE_E_LAST                               equ     8004019FH
CLIENTSITE_S_FIRST                              equ     00040190H
CLIENTSITE_S_LAST                               equ     0004019FH

INPLACE_E_NOTUNDOABLE                           equ     800401A0H
INPLACE_E_NOTOOLSPACE                           equ     800401A1H
INPLACE_E_FIRST                                 equ     800401A0H
INPLACE_E_LAST                                  equ     800401AFH
INPLACE_S_FIRST                                 equ     000401A0H
INPLACE_S_LAST                                  equ     000401AFH

ENUM_E_FIRST                                    equ     800401B0H
ENUM_E_LAST                                     equ     800401BFH
ENUM_S_FIRST                                    equ     000401B0H
ENUM_S_LAST                                     equ     000401BFH

CONVERT10_E_FIRST                               equ     800401C0H
CONVERT10_E_LAST                                equ     800401CFH
CONVERT10_S_FIRST                               equ     000401C0H
CONVERT10_S_LAST                                equ     000401CFH
CONVERT10_E_OLESTREAM_GET                       equ     800401C0H
CONVERT10_E_OLESTREAM_PUT                       equ     800401C1H
CONVERT10_E_OLESTREAM_FMT                       equ     800401C2H
CONVERT10_E_OLESTREAM_BITMAP_TO_DIB             equ     800401C3H
CONVERT10_E_STG_FMT                             equ     800401C4H
CONVERT10_E_STG_NO_STD_STREAM                   equ     800401C5H
CONVERT10_E_STG_DIB_TO_BITMAP                   equ     800401C6H

CLIPBRD_E_FIRST                                 equ     800401D0H
CLIPBRD_E_LAST                                  equ     800401DFH
CLIPBRD_S_FIRST                                 equ     000401D0H
CLIPBRD_S_LAST                                  equ     000401DFH
CLIPBRD_E_CANT_OPEN                             equ     800401D0H
CLIPBRD_E_CANT_EMPTY                            equ     800401D1H
CLIPBRD_E_CANT_SET                              equ     800401D2H
CLIPBRD_E_BAD_DATA                              equ     800401D3H
CLIPBRD_E_CANT_CLOSE                            equ     800401D4H

MK_E_FIRST                                      equ     800401E0H
MK_E_LAST                                       equ     800401EFH
MK_S_FIRST                                      equ     000401E0H
MK_S_LAST                                       equ     000401EFH
MK_E_CONNECTMANUALLY                            equ     800401E0H
MK_E_EXCEEDEDDEADLINE                           equ     800401E1H
MK_E_NEEDGENERIC                                equ     800401E2H
MK_E_UNAVAILABLE                                equ     800401E3H
MK_E_SYNTAX                                     equ     800401E4H
MK_E_NOOBJECT                                   equ     800401E5H
MK_E_INVALIDEXTENSION                           equ     800401E6H
MK_E_INTERMEDIATEINTERFACENOTSUPPORTED          equ     800401E7H
MK_E_NOTBINDABLE                                equ     800401E8H
MK_E_NOTBOUND                                   equ     800401E9H
MK_E_CANTOPENFILE                               equ     800401EAH
MK_E_MUSTBOTHERUSER                             equ     800401EBH
MK_E_NOINVERSE                                  equ     800401ECH
MK_E_NOSTORAGE                                  equ     800401EDH
MK_E_NOPREFIX                                   equ     800401EEH
MK_E_ENUMERATION_FAILED                         equ     800401EFH
MK_E_NO_NORMALIZED                              equ     80080007H

CO_E_FIRST                                      equ     800401F0H
CO_E_LAST                                       equ     800401FFH
CO_S_FIRST                                      equ     000401F0H
CO_S_LAST                                       equ     000401FFH
CO_E_NOTINITIALIZED                             equ     800401F0H
CO_E_ALREADYINITIALIZED                         equ     800401F1H
CO_E_CANTDETERMINECLASS                         equ     800401F2H
CO_E_CLASSSTRING                                equ     800401F3H
CO_E_IIDSTRING                                  equ     800401F4H
CO_E_APPNOTFOUND                                equ     800401F5H
CO_E_APPSINGLEUSE                               equ     800401F6H
CO_E_ERRORINAPP                                 equ     800401F7H
CO_E_DLLNOTFOUND                                equ     800401F8H
CO_E_ERRORINDLL                                 equ     800401F9H
CO_E_WRONGOSFORAPP                              equ     800401FAH
CO_E_OBJNOTREG                                  equ     800401FBH
CO_E_OBJISREG                                   equ     800401FCH
CO_E_OBJNOTCONNECTED                            equ     800401FDH
CO_E_APPDIDNTREG                                equ     800401FEH
CO_E_RELEASED                                   equ     800401FFH
CO_E_CLASS_CREATE_FAILED                        equ     80080001H
CO_E_SCM_ERROR                                  equ     80080002H
CO_E_SCM_RPC_FAILURE                            equ     80080003H
CO_E_BAD_PATH                                   equ     80080004H
CO_E_SERVER_EXEC_FAILURE                        equ     80080005H
CO_E_OBJSRV_RPC_FAILURE                         equ     80080006H
CO_E_SERVER_STOPPING                            equ     80080008H
CO_S_NOTALLINTERFACES                           equ     00080012H
CO_S_MACHINENAMENOTFOUND                        equ     00080013H
CO_E_MISSING_DISPLAYNAME                        equ     80080015H
CO_E_RUNAS_VALUE_MUST_BE_AAA                    equ     80080016H
CO_E_ELEVATION_DISABLED                         equ     80080017H

EVENT_E_FIRST                                   equ     80040200H
EVENT_E_LAST                                    equ     8004021FH
EVENT_S_FIRST                                   equ     00040200H
EVENT_S_LAST                                    equ     0004021FH
EVENT_S_SOME_SUBSCRIBERS_FAILED                 equ     00040200H
EVENT_E_ALL_SUBSCRIBERS_FAILED                  equ     80040201H
EVENT_S_NOSUBSCRIBERS                           equ     00040202H
EVENT_E_QUERYSYNTAX                             equ     80040203H
EVENT_E_QUERYFIELD                              equ     80040204H
EVENT_E_INTERNALEXCEPTION                       equ     80040205H
EVENT_E_INTERNALERROR                           equ     80040206H
EVENT_E_INVALID_PER_USER_SID                    equ     80040207H
EVENT_E_USER_EXCEPTION                          equ     80040208H
EVENT_E_TOO_MANY_METHODS                        equ     80040209H
EVENT_E_MISSING_EVENTCLASS                      equ     8004020AH
EVENT_E_NOT_ALL_REMOVED                         equ     8004020BH
EVENT_E_COMPLUS_NOT_INSTALLED                   equ     8004020CH
EVENT_E_CANT_MODIFY_OR_DELETE_UNCONFIGURED_OBJECT equ   8004020DH
EVENT_E_CANT_MODIFY_OR_DELETE_CONFIGURED_OBJECT equ     8004020EH
EVENT_E_INVALID_EVENT_CLASS_PARTITION           equ     8004020FH
EVENT_E_PER_USER_SID_NOT_LOGGED_ON              equ     80040210H

XACT_E_FIRST                                    equ     8004D000H
XACT_E_LAST                                     equ     8004D02BH
XACT_S_FIRST                                    equ     0004D000H
XACT_S_LAST                                     equ     0004D010H
XACT_E_ALREADYOTHERSINGLEPHASE                  equ     8004D000H
XACT_E_CANTRETAIN                               equ     8004D001H
XACT_E_COMMITFAILED                             equ     8004D002H
XACT_E_COMMITPREVENTED                          equ     8004D003H
XACT_E_HEURISTICABORT                           equ     8004D004H
XACT_E_HEURISTICCOMMIT                          equ     8004D005H
XACT_E_HEURISTICDAMAGE                          equ     8004D006H
XACT_E_HEURISTICDANGER                          equ     8004D007H
XACT_E_ISOLATIONLEVEL                           equ     8004D008H
XACT_E_NOASYNC                                  equ     8004D009H
XACT_E_NOENLIST                                 equ     8004D00AH
XACT_E_NOISORETAIN                              equ     8004D00BH
XACT_E_NORESOURCE                               equ     8004D00CH
XACT_E_NOTCURRENT                               equ     8004D00DH
XACT_E_NOTRANSACTION                            equ     8004D00EH
XACT_E_NOTSUPPORTED                             equ     8004D00FH
XACT_E_UNKNOWNRMGRID                            equ     8004D010H
XACT_E_WRONGSTATE                               equ     8004D011H
XACT_E_WRONGUOW                                 equ     8004D012H
XACT_E_XTIONEXISTS                              equ     8004D013H
XACT_E_NOIMPORTOBJECT                           equ     8004D014H
XACT_E_INVALIDCOOKIE                            equ     8004D015H
XACT_E_INDOUBT                                  equ     8004D016H
XACT_E_NOTIMEOUT                                equ     8004D017H
XACT_E_ALREADYINPROGRESS                        equ     8004D018H
XACT_E_ABORTED                                  equ     8004D019H
XACT_E_LOGFULL                                  equ     8004D01AH
XACT_E_TMNOTAVAILABLE                           equ     8004D01BH
XACT_E_CONNECTION_DOWN                          equ     8004D01CH
XACT_E_CONNECTION_DENIED                        equ     8004D01DH
XACT_E_REENLISTTIMEOUT                          equ     8004D01EH
XACT_E_TIP_CONNECT_FAILED                       equ     8004D01FH
XACT_E_TIP_PROTOCOL_ERROR                       equ     8004D020H
XACT_E_TIP_PULL_FAILED                          equ     8004D021H
XACT_E_DEST_TMNOTAVAILABLE                      equ     8004D022H
XACT_E_TIP_DISABLED                             equ     8004D023H
XACT_E_NETWORK_TX_DISABLED                      equ     8004D024H
XACT_E_PARTNER_NETWORK_TX_DISABLED              equ     8004D025H
XACT_E_XA_TX_DISABLED                           equ     8004D026H
XACT_E_UNABLE_TO_READ_DTC_CONFIG                equ     8004D027H
XACT_E_UNABLE_TO_LOAD_DTC_PROXY                 equ     8004D028H
XACT_E_ABORTING                                 equ     8004D029H
XACT_E_PUSH_COMM_FAILURE                        equ     8004D02AH
XACT_E_PULL_COMM_FAILURE                        equ     8004D02BH
XACT_E_LU_TX_DISABLED                           equ     8004D02CH
XACT_E_CLERKNOTFOUND                            equ     8004D080H
XACT_E_CLERKEXISTS                              equ     8004D081H
XACT_E_RECOVERYINPROGRESS                       equ     8004D082H
XACT_E_TRANSACTIONCLOSED                        equ     8004D083H
XACT_E_INVALIDLSN                               equ     8004D084H
XACT_E_REPLAYREQUEST                            equ     8004D085H
XACT_S_ASYNC                                    equ     0004D000H
XACT_S_DEFECT                                   equ     0004D001H
XACT_S_READONLY                                 equ     0004D002H
XACT_S_SOMENORETAIN                             equ     0004D003H
XACT_S_OKINFORM                                 equ     0004D004H
XACT_S_MADECHANGESCONTENT                       equ     0004D005H
XACT_S_MADECHANGESINFORM                        equ     0004D006H
XACT_S_ALLNORETAIN                              equ     0004D007H
XACT_S_ABORTING                                 equ     0004D008H
XACT_S_SINGLEPHASE                              equ     0004D009H
XACT_S_LOCALLY_OK                               equ     0004D00AH
XACT_S_LASTRESOURCEMANAGER                      equ     0004D010H

CONTEXT_E_FIRST                                 equ     8004E000H
CONTEXT_E_LAST                                  equ     8004E02FH
CONTEXT_S_FIRST                                 equ     0004E000H
CONTEXT_S_LAST                                  equ     0004E02FH
CONTEXT_E_ABORTED                               equ     8004E002H
CONTEXT_E_ABORTING                              equ     8004E003H
CONTEXT_E_NOCONTEXT                             equ     8004E004H
CONTEXT_E_WOULD_DEADLOCK                        equ     8004E005H
CONTEXT_E_SYNCH_TIMEOUT                         equ     8004E006H
CONTEXT_E_OLDREF                                equ     8004E007H
CONTEXT_E_ROLENOTFOUND                          equ     8004E00CH
CONTEXT_E_TMNOTAVAILABLE                        equ     8004E00FH
CONTEXT_E_NOJIT                                 equ     8004E026H
CONTEXT_E_NOTRANSACTION                         equ     8004E027H

CO_E_ACTIVATIONFAILED                           equ     8004E021H
CO_E_ACTIVATIONFAILED_EVENTLOGGED               equ     8004E022H
CO_E_ACTIVATIONFAILED_CATALOGERROR              equ     8004E023H
CO_E_ACTIVATIONFAILED_TIMEOUT                   equ     8004E024H
CO_E_INITIALIZATIONFAILED                       equ     8004E025H
CO_E_THREADINGMODEL_CHANGED                     equ     8004E028H
CO_E_NOIISINTRINSICS                            equ     8004E029H
CO_E_NOCOOKIES                                  equ     8004E02AH
CO_E_DBERROR                                    equ     8004E02BH
CO_E_NOTPOOLED                                  equ     8004E02CH
CO_E_NOTCONSTRUCTED                             equ     8004E02DH
CO_E_NOSYNCHRONIZATION                          equ     8004E02EH
CO_E_ISOLEVELMISMATCH                           equ     8004E02FH
CO_E_CALL_OUT_OF_TX_SCOPE_NOT_ALLOWED           equ     8004E030H
CO_E_EXIT_TRANSACTION_SCOPE_NOT_CALLED          equ     8004E031H

OLE_S_USEREG                                    equ     00040000H
OLE_S_STATIC                                    equ     00040001H
OLE_S_MAC_CLIPFORMAT                            equ     00040002H

DRAGDROP_S_DROP                                 equ     00040100H
DRAGDROP_S_CANCEL                               equ     00040101H
DRAGDROP_S_USEDEFAULTCURSORS                    equ     00040102H

DATA_S_SAMEFORMATETC                            equ     00040130H
VIEW_S_ALREADY_FROZEN                           equ     00040140H

CACHE_S_FORMATETC_NOTSUPPORTED                  equ     00040170H
CACHE_S_SAMECACHE                               equ     00040171H
CACHE_S_SOMECACHES_NOTUPDATED                   equ     00040172H

OLEOBJ_S_INVALIDVERB                            equ     00040180H
OLEOBJ_S_CANNOT_DOVERB_NOW                      equ     00040181H
OLEOBJ_S_INVALIDHWND                            equ     00040182H

INPLACE_S_TRUNCATED                             equ     000401A0H
CONVERT10_S_NO_PRESENTATION                     equ     000401C0H

MK_S_REDUCED_TO_SELF                            equ     000401E2H
MK_S_ME                                         equ     000401E4H
MK_S_HIM                                        equ     000401E5H
MK_S_US                                         equ     000401E6H
MK_S_MONIKERALREADYREGISTERED                   equ     000401E7H

SCHED_S_TASK_READY                              equ     00041300H
SCHED_S_TASK_RUNNING                            equ     00041301H
SCHED_S_TASK_DISABLED                           equ     00041302H
SCHED_S_TASK_HAS_NOT_RUN                        equ     00041303H
SCHED_S_TASK_NO_MORE_RUNS                       equ     00041304H
SCHED_S_TASK_NOT_SCHEDULED                      equ     00041305H
SCHED_S_TASK_TERMINATED                         equ     00041306H
SCHED_S_TASK_NO_VALID_TRIGGERS                  equ     00041307H
SCHED_S_EVENT_TRIGGER                           equ     00041308H
SCHED_E_TRIGGER_NOT_FOUND                       equ     80041309H
SCHED_E_TASK_NOT_READY                          equ     8004130AH
SCHED_E_TASK_NOT_RUNNING                        equ     8004130BH
SCHED_E_SERVICE_NOT_INSTALLED                   equ     8004130CH
SCHED_E_CANNOT_OPEN_TASK                        equ     8004130DH
SCHED_E_INVALID_TASK                            equ     8004130EH
SCHED_E_ACCOUNT_INFORMATION_NOT_SET             equ     8004130FH
SCHED_E_ACCOUNT_NAME_NOT_FOUND                  equ     80041310H
SCHED_E_ACCOUNT_DBASE_CORRUPT                   equ     80041311H
SCHED_E_NO_SECURITY_SERVICES                    equ     80041312H
SCHED_E_UNKNOWN_OBJECT_VERSION                  equ     80041313H
SCHED_E_UNSUPPORTED_ACCOUNT_OPTION              equ     80041314H
SCHED_E_SERVICE_NOT_RUNNING                     equ     80041315H
SCHED_E_UNEXPECTEDNODE                          equ     80041316H
SCHED_E_NAMESPACE                               equ     80041317H
SCHED_E_INVALIDVALUE                            equ     80041318H
SCHED_E_MISSINGNODE                             equ     80041319H
SCHED_E_MALFORMEDXML                            equ     8004131AH
SCHED_S_SOME_TRIGGERS_FAILED                    equ     0004131BH
SCHED_S_BATCH_LOGON_PROBLEM                     equ     0004131CH
SCHED_E_TOO_MANY_NODES                          equ     8004131DH
SCHED_E_PAST_END_BOUNDARY                       equ     8004131EH
SCHED_E_ALREADY_RUNNING                         equ     8004131FH
SCHED_E_USER_NOT_LOGGED_ON                      equ     80041320H
SCHED_E_INVALID_TASK_HASH                       equ     80041321H
SCHED_E_SERVICE_NOT_AVAILABLE                   equ     80041322H
SCHED_E_SERVICE_TOO_BUSY                        equ     80041323H
SCHED_E_TASK_ATTEMPTED                          equ     80041324H
SCHED_S_TASK_QUEUED                             equ     00041325H
SCHED_E_TASK_DISABLED                           equ     80041326H
SCHED_E_TASK_NOT_V1_COMPAT                      equ     80041327H
SCHED_E_START_ON_DEMAND                         equ     80041328H

MEM_E_INVALID_ROOT                              equ     80080009H
MEM_E_INVALID_LINK                              equ     80080010H
MEM_E_INVALID_SIZE                              equ     80080011H

DISP_E_UNKNOWNINTERFACE                         equ     80020001H
DISP_E_MEMBERNOTFOUND                           equ     80020003H
DISP_E_PARAMNOTFOUND                            equ     80020004H
DISP_E_TYPEMISMATCH                             equ     80020005H
DISP_E_UNKNOWNNAME                              equ     80020006H
DISP_E_NONAMEDARGS                              equ     80020007H
DISP_E_BADVARTYPE                               equ     80020008H
DISP_E_EXCEPTION                                equ     80020009H
DISP_E_OVERFLOW                                 equ     8002000AH
DISP_E_BADINDEX                                 equ     8002000BH
DISP_E_UNKNOWNLCID                              equ     8002000CH
DISP_E_ARRAYISLOCKED                            equ     8002000DH
DISP_E_BADPARAMCOUNT                            equ     8002000EH
DISP_E_PARAMNOTOPTIONAL                         equ     8002000FH
DISP_E_BADCALLEE                                equ     80020010H
DISP_E_NOTACOLLECTION                           equ     80020011H
DISP_E_DIVBYZERO                                equ     80020012H
DISP_E_BUFFERTOOSMALL                           equ     80020013H

TYPE_E_BUFFERTOOSMALL                           equ     80028016H
TYPE_E_FIELDNOTFOUND                            equ     80028017H
TYPE_E_INVDATAREAD                              equ     80028018H
TYPE_E_UNSUPFORMAT                              equ     80028019H
TYPE_E_REGISTRYACCESS                           equ     8002801CH
TYPE_E_LIBNOTREGISTERED                         equ     8002801DH
TYPE_E_UNDEFINEDTYPE                            equ     80028027H
TYPE_E_QUALIFIEDNAMEDISALLOWED                  equ     80028028H
TYPE_E_INVALIDSTATE                             equ     80028029H
TYPE_E_WRONGTYPEKIND                            equ     8002802AH
TYPE_E_ELEMENTNOTFOUND                          equ     8002802BH
TYPE_E_AMBIGUOUSNAME                            equ     8002802CH
TYPE_E_NAMECONFLICT                             equ     8002802DH
TYPE_E_UNKNOWNLCID                              equ     8002802EH
TYPE_E_DLLFUNCTIONNOTFOUND                      equ     8002802FH
TYPE_E_BADMODULEKIND                            equ     800288BDH
TYPE_E_SIZETOOBIG                               equ     800288C5H
TYPE_E_DUPLICATEID                              equ     800288C6H
TYPE_E_INVALIDID                                equ     800288CFH
TYPE_E_TYPEMISMATCH                             equ     80028CA0H
TYPE_E_OUTOFBOUNDS                              equ     80028CA1H
TYPE_E_IOERROR                                  equ     80028CA2H
TYPE_E_CANTCREATETMPFILE                        equ     80028CA3H
TYPE_E_CANTLOADLIBRARY                          equ     80029C4AH
TYPE_E_INCONSISTENTPROPFUNCS                    equ     80029C83H
TYPE_E_CIRCULARTYPE                             equ     80029C84H

STG_E_INVALIDFUNCTION                           equ     80030001H
STG_E_FILENOTFOUND                              equ     80030002H
STG_E_PATHNOTFOUND                              equ     80030003H
STG_E_TOOMANYOPENFILES                          equ     80030004H
STG_E_ACCESSDENIED                              equ     80030005H
STG_E_INVALIDHANDLE                             equ     80030006H
STG_E_INSUFFICIENTMEMORY                        equ     80030008H
STG_E_INVALIDPOINTER                            equ     80030009H
STG_E_NOMOREFILES                               equ     80030012H
STG_E_DISKISWRITEPROTECTED                      equ     80030013H
STG_E_SEEKERROR                                 equ     80030019H
STG_E_WRITEFAULT                                equ     8003001DH
STG_E_READFAULT                                 equ     8003001EH
STG_E_SHAREVIOLATION                            equ     80030020H
STG_E_LOCKVIOLATION                             equ     80030021H
STG_E_FILEALREADYEXISTS                         equ     80030050H
STG_E_INVALIDPARAMETER                          equ     80030057H
STG_E_MEDIUMFULL                                equ     80030070H
STG_E_PROPSETMISMATCHED                         equ     800300F0H
STG_E_ABNORMALAPIEXIT                           equ     800300FAH
STG_E_INVALIDHEADER                             equ     800300FBH
STG_E_INVALIDNAME                               equ     800300FCH
STG_E_UNKNOWN                                   equ     800300FDH
STG_E_UNIMPLEMENTEDFUNCTION                     equ     800300FEH
STG_E_INVALIDFLAG                               equ     800300FFH
STG_E_INUSE                                     equ     80030100H
STG_E_NOTCURRENT                                equ     80030101H
STG_E_REVERTED                                  equ     80030102H
STG_E_CANTSAVE                                  equ     80030103H
STG_E_OLDFORMAT                                 equ     80030104H
STG_E_OLDDLL                                    equ     80030105H
STG_E_SHAREREQUIRED                             equ     80030106H
STG_E_NOTFILEBASEDSTORAGE                       equ     80030107H
STG_E_EXTANTMARSHALLINGS                        equ     80030108H
STG_E_DOCFILECORRUPT                            equ     80030109H
STG_E_BADBASEADDRESS                            equ     80030110H
STG_E_DOCFILETOOLARGE                           equ     80030111H
STG_E_NOTSIMPLEFORMAT                           equ     80030112H
STG_E_INCOMPLETE                                equ     80030201H
STG_E_TERMINATED                                equ     80030202H
STG_S_CONVERTED                                 equ     00030200H
STG_S_BLOCK                                     equ     00030201H
STG_S_RETRYNOW                                  equ     00030202H
STG_S_MONITORING                                equ     00030203H
STG_S_MULTIPLEOPENS                             equ     00030204H
STG_S_CONSOLIDATIONFAILED                       equ     00030205H
STG_S_CANNOTCONSOLIDATE                         equ     00030206H
STG_E_STATUS_COPY_PROTECTION_FAILURE            equ     80030305H
STG_E_CSS_AUTHENTICATION_FAILURE                equ     80030306H
STG_E_CSS_KEY_NOT_PRESENT                       equ     80030307H
STG_E_CSS_KEY_NOT_ESTABLISHED                   equ     80030308H
STG_E_CSS_SCRAMBLED_SECTOR                      equ     80030309H
STG_E_CSS_REGION_MISMATCH                       equ     8003030AH
STG_E_RESETS_EXHAUSTED                          equ     8003030BH

RPC_E_CALL_REJECTED                             equ     80010001H
RPC_E_CALL_CANCELED                             equ     80010002H
RPC_E_CANTPOST_INSENDCALL                       equ     80010003H
RPC_E_CANTCALLOUT_INASYNCCALL                   equ     80010004H
RPC_E_CANTCALLOUT_INEXTERNALCALL                equ     80010005H
RPC_E_CONNECTION_TERMINATED                     equ     80010006H
RPC_E_SERVER_DIED                               equ     80010007H
RPC_E_CLIENT_DIED                               equ     80010008H
RPC_E_INVALID_DATAPACKET                        equ     80010009H
RPC_E_CANTTRANSMIT_CALL                         equ     8001000AH
RPC_E_CLIENT_CANTMARSHAL_DATA                   equ     8001000BH
RPC_E_CLIENT_CANTUNMARSHAL_DATA                 equ     8001000CH
RPC_E_SERVER_CANTMARSHAL_DATA                   equ     8001000DH
RPC_E_SERVER_CANTUNMARSHAL_DATA                 equ     8001000EH
RPC_E_INVALID_DATA                              equ     8001000FH
RPC_E_INVALID_PARAMETER                         equ     80010010H
RPC_E_CANTCALLOUT_AGAIN                         equ     80010011H
RPC_E_SERVER_DIED_DNE                           equ     80010012H
RPC_E_SYS_CALL_FAILED                           equ     80010100H
RPC_E_OUT_OF_RESOURCES                          equ     80010101H
RPC_E_ATTEMPTED_MULTITHREAD                     equ     80010102H
RPC_E_NOT_REGISTERED                            equ     80010103H
RPC_E_FAULT                                     equ     80010104H
RPC_E_SERVERFAULT                               equ     80010105H
RPC_E_CHANGED_MODE                              equ     80010106H
RPC_E_INVALIDMETHOD                             equ     80010107H
RPC_E_DISCONNECTED                              equ     80010108H
RPC_E_RETRY                                     equ     80010109H
RPC_E_SERVERCALL_RETRYLATER                     equ     8001010AH
RPC_E_SERVERCALL_REJECTED                       equ     8001010BH
RPC_E_INVALID_CALLDATA                          equ     8001010CH
RPC_E_CANTCALLOUT_ININPUTSYNCCALL               equ     8001010DH
RPC_E_WRONG_THREAD                              equ     8001010EH
RPC_E_THREAD_NOT_INIT                           equ     8001010FH
RPC_E_VERSION_MISMATCH                          equ     80010110H
RPC_E_INVALID_HEADER                            equ     80010111H
RPC_E_INVALID_EXTENSION                         equ     80010112H
RPC_E_INVALID_IPID                              equ     80010113H
RPC_E_INVALID_OBJECT                            equ     80010114H
RPC_S_CALLPENDING                               equ     80010115H
RPC_S_WAITONTIMER                               equ     80010116H
RPC_E_CALL_COMPLETE                             equ     80010117H
RPC_E_UNSECURE_CALL                             equ     80010118H
RPC_E_TOO_LATE                                  equ     80010119H
RPC_E_NO_GOOD_SECURITY_PACKAGES                 equ     8001011AH
RPC_E_ACCESS_DENIED                             equ     8001011BH
RPC_E_REMOTE_DISABLED                           equ     8001011CH
RPC_E_INVALID_OBJREF                            equ     8001011DH
RPC_E_NO_CONTEXT                                equ     8001011EH
RPC_E_TIMEOUT                                   equ     8001011FH
RPC_E_NO_SYNC                                   equ     80010120H
RPC_E_FULLSIC_REQUIRED                          equ     80010121H
RPC_E_INVALID_STD_NAME                          equ     80010122H
RPC_E_UNEXPECTED                                equ     8001FFFFH

ERROR_AUDITING_DISABLED                         equ     0C0090001H

ERROR_ALL_SIDS_FILTERED                         equ     0C0090002H
ERROR_BIZRULES_NOT_ENABLED                      equ     0C0090003H
NTE_BAD_UID                                     equ     80090001H
NTE_BAD_HASH                                    equ     80090002H
NTE_BAD_KEY                                     equ     80090003H
NTE_BAD_LEN                                     equ     80090004H
NTE_BAD_DATA                                    equ     80090005H
NTE_BAD_SIGNATURE                               equ     80090006H
NTE_BAD_VER                                     equ     80090007H
NTE_BAD_ALGID                                   equ     80090008H
NTE_BAD_FLAGS                                   equ     80090009H
NTE_BAD_TYPE                                    equ     8009000AH
NTE_BAD_KEY_STATE                               equ     8009000BH
NTE_BAD_HASH_STATE                              equ     8009000CH
NTE_NO_KEY                                      equ     8009000DH
NTE_NO_MEMORY                                   equ     8009000EH
NTE_EXISTS                                      equ     8009000FH
NTE_PERM                                        equ     80090010H
NTE_NOT_FOUND                                   equ     80090011H
NTE_DOUBLE_ENCRYPT                              equ     80090012H
NTE_BAD_PROVIDER                                equ     80090013H
NTE_BAD_PROV_TYPE                               equ     80090014H
NTE_BAD_PUBLIC_KEY                              equ     80090015H
NTE_BAD_KEYSET                                  equ     80090016H
NTE_PROV_TYPE_NOT_DEF                           equ     80090017H
NTE_PROV_TYPE_ENTRY_BAD                         equ     80090018H
NTE_KEYSET_NOT_DEF                              equ     80090019H
NTE_KEYSET_ENTRY_BAD                            equ     8009001AH
NTE_PROV_TYPE_NO_MATCH                          equ     8009001BH
NTE_SIGNATURE_FILE_BAD                          equ     8009001CH
NTE_PROVIDER_DLL_FAIL                           equ     8009001DH
NTE_PROV_DLL_NOT_FOUND                          equ     8009001EH
NTE_BAD_KEYSET_PARAM                            equ     8009001FH
NTE_FAIL                                        equ     80090020H
NTE_SYS_ERR                                     equ     80090021H
NTE_SILENT_CONTEXT                              equ     80090022H
NTE_TOKEN_KEYSET_STORAGE_FULL                   equ     80090023H
NTE_TEMPORARY_PROFILE                           equ     80090024H
NTE_FIXEDPARAMETER                              equ     80090025H
NTE_INVALID_HANDLE                              equ     80090026H
NTE_INVALID_PARAMETER                           equ     80090027H
NTE_BUFFER_TOO_SMALL                            equ     80090028H
NTE_NOT_SUPPORTED                               equ     80090029H
NTE_NO_MORE_ITEMS                               equ     8009002AH
NTE_BUFFERS_OVERLAP                             equ     8009002BH
NTE_DECRYPTION_FAILURE                          equ     8009002CH
NTE_INTERNAL_ERROR                              equ     8009002DH
NTE_UI_REQUIRED                                 equ     8009002EH
NTE_HMAC_NOT_SUPPORTED                          equ     8009002FH

SEC_E_INSUFFICIENT_MEMORY                       equ     80090300H
SEC_E_INVALID_HANDLE                            equ     80090301H
SEC_E_UNSUPPORTED_FUNCTION                      equ     80090302H
SEC_E_TARGET_UNKNOWN                            equ     80090303H
SEC_E_INTERNAL_ERROR                            equ     80090304H
SEC_E_SECPKG_NOT_FOUND                          equ     80090305H
SEC_E_NOT_OWNER                                 equ     80090306H
SEC_E_CANNOT_INSTALL                            equ     80090307H
SEC_E_INVALID_TOKEN                             equ     80090308H
SEC_E_CANNOT_PACK                               equ     80090309H
SEC_E_QOP_NOT_SUPPORTED                         equ     8009030AH
SEC_E_NO_IMPERSONATION                          equ     8009030BH
SEC_E_LOGON_DENIED                              equ     8009030CH
SEC_E_UNKNOWN_CREDENTIALS                       equ     8009030DH
SEC_E_NO_CREDENTIALS                            equ     8009030EH
SEC_E_MESSAGE_ALTERED                           equ     8009030FH
SEC_E_OUT_OF_SEQUENCE                           equ     80090310H
SEC_E_NO_AUTHENTICATING_AUTHORITY               equ     80090311H
SEC_I_CONTINUE_NEEDED                           equ     00090312H
SEC_I_COMPLETE_NEEDED                           equ     00090313H
SEC_I_COMPLETE_AND_CONTINUE                     equ     00090314H
SEC_I_LOCAL_LOGON                               equ     00090315H
SEC_E_BAD_PKGID                                 equ     80090316H
SEC_E_CONTEXT_EXPIRED                           equ     80090317H
SEC_I_CONTEXT_EXPIRED                           equ     00090317H
SEC_E_INCOMPLETE_MESSAGE                        equ     80090318H
SEC_E_INCOMPLETE_CREDENTIALS                    equ     80090320H
SEC_E_BUFFER_TOO_SMALL                          equ     80090321H
SEC_I_INCOMPLETE_CREDENTIALS                    equ     00090320H
SEC_I_RENEGOTIATE                               equ     00090321H
SEC_E_WRONG_PRINCIPAL                           equ     80090322H
SEC_I_NO_LSA_CONTEXT                            equ     00090323H
SEC_E_TIME_SKEW                                 equ     80090324H
SEC_E_UNTRUSTED_ROOT                            equ     80090325H
SEC_E_ILLEGAL_MESSAGE                           equ     80090326H
SEC_E_CERT_UNKNOWN                              equ     80090327H
SEC_E_CERT_EXPIRED                              equ     80090328H
SEC_E_ENCRYPT_FAILURE                           equ     80090329H
SEC_E_DECRYPT_FAILURE                           equ     80090330H
SEC_E_ALGORITHM_MISMATCH                        equ     80090331H
SEC_E_SECURITY_QOS_FAILED                       equ     80090332H
SEC_E_UNFINISHED_CONTEXT_DELETED                equ     80090333H
SEC_E_NO_TGT_REPLY                              equ     80090334H
SEC_E_NO_IP_ADDRESSES                           equ     80090335H
SEC_E_WRONG_CREDENTIAL_HANDLE                   equ     80090336H
SEC_E_CRYPTO_SYSTEM_INVALID                     equ     80090337H
SEC_E_MAX_REFERRALS_EXCEEDED                    equ     80090338H
SEC_E_MUST_BE_KDC                               equ     80090339H
SEC_E_STRONG_CRYPTO_NOT_SUPPORTED               equ     8009033AH
SEC_E_TOO_MANY_PRINCIPALS                       equ     8009033BH
SEC_E_NO_PA_DATA                                equ     8009033CH
SEC_E_PKINIT_NAME_MISMATCH                      equ     8009033DH
SEC_E_SMARTCARD_LOGON_REQUIRED                  equ     8009033EH
SEC_E_SHUTDOWN_IN_PROGRESS                      equ     8009033FH
SEC_E_KDC_INVALID_REQUEST                       equ     80090340H
SEC_E_KDC_UNABLE_TO_REFER                       equ     80090341H
SEC_E_KDC_UNKNOWN_ETYPE                         equ     80090342H
SEC_E_UNSUPPORTED_PREAUTH                       equ     80090343H
SEC_E_DELEGATION_REQUIRED                       equ     80090345H
SEC_E_BAD_BINDINGS                              equ     80090346H
SEC_E_MULTIPLE_ACCOUNTS                         equ     80090347H
SEC_E_NO_KERB_KEY                               equ     80090348H
SEC_E_CERT_WRONG_USAGE                          equ     80090349H
SEC_E_DOWNGRADE_DETECTED                        equ     80090350H
SEC_E_SMARTCARD_CERT_REVOKED                    equ     80090351H
SEC_E_ISSUING_CA_UNTRUSTED                      equ     80090352H
SEC_E_REVOCATION_OFFLINE_C                      equ     80090353H
SEC_E_PKINIT_CLIENT_FAILURE                     equ     80090354H
SEC_E_SMARTCARD_CERT_EXPIRED                    equ     80090355H
SEC_E_NO_S4U_PROT_SUPPORT                       equ     80090356H
SEC_E_CROSSREALM_DELEGATION_FAILURE             equ     80090357H
SEC_E_REVOCATION_OFFLINE_KDC                    equ     80090358H
SEC_E_ISSUING_CA_UNTRUSTED_KDC                  equ     80090359H
SEC_E_KDC_CERT_EXPIRED                          equ     8009035AH
SEC_E_KDC_CERT_REVOKED                          equ     8009035BH
SEC_I_SIGNATURE_NEEDED                          equ     0009035CH
SEC_E_INVALID_PARAMETER                         equ     8009035DH
SEC_E_DELEGATION_POLICY                         equ     8009035EH
SEC_E_POLICY_NLTM_ONLY                          equ     8009035FH
SEC_I_NO_RENEGOTIATION                          equ     00090360H
SEC_E_NO_CONTEXT                                equ     80090361H
SEC_E_PKU2U_CERT_FAILURE                        equ     80090362H
SEC_E_MUTUAL_AUTH_FAILED                        equ     80090363H
SEC_E_NO_SPM                                    equ     SEC_E_INTERNAL_ERROR
SEC_E_NOT_SUPPORTED                             equ     SEC_E_UNSUPPORTED_FUNCTION

CRYPT_E_MSG_ERROR                               equ     80091001H
CRYPT_E_UNKNOWN_ALGO                            equ     80091002H
CRYPT_E_OID_FORMAT                              equ     80091003H
CRYPT_E_INVALID_MSG_TYPE                        equ     80091004H
CRYPT_E_UNEXPECTED_ENCODING                     equ     80091005H
CRYPT_E_AUTH_ATTR_MISSING                       equ     80091006H
CRYPT_E_HASH_VALUE                              equ     80091007H
CRYPT_E_INVALID_INDEX                           equ     80091008H
CRYPT_E_ALREADY_DECRYPTED                       equ     80091009H
CRYPT_E_NOT_DECRYPTED                           equ     8009100AH
CRYPT_E_RECIPIENT_NOT_FOUND                     equ     8009100BH
CRYPT_E_CONTROL_TYPE                            equ     8009100CH
CRYPT_E_ISSUER_SERIALNUMBER                     equ     8009100DH
CRYPT_E_SIGNER_NOT_FOUND                        equ     8009100EH
CRYPT_E_ATTRIBUTES_MISSING                      equ     8009100FH
CRYPT_E_STREAM_MSG_NOT_READY                    equ     80091010H
CRYPT_E_STREAM_INSUFFICIENT_DATA                equ     80091011H
CRYPT_I_NEW_PROTECTION_REQUIRED                 equ     00091012H
CRYPT_E_BAD_LEN                                 equ     80092001H
CRYPT_E_BAD_ENCODE                              equ     80092002H
CRYPT_E_FILE_ERROR                              equ     80092003H
CRYPT_E_NOT_FOUND                               equ     80092004H
CRYPT_E_EXISTS                                  equ     80092005H
CRYPT_E_NO_PROVIDER                             equ     80092006H
CRYPT_E_SELF_SIGNED                             equ     80092007H
CRYPT_E_DELETED_PREV                            equ     80092008H
CRYPT_E_NO_MATCH                                equ     80092009H
CRYPT_E_UNEXPECTED_MSG_TYPE                     equ     8009200AH
CRYPT_E_NO_KEY_PROPERTY                         equ     8009200BH
CRYPT_E_NO_DECRYPT_CERT                         equ     8009200CH
CRYPT_E_BAD_MSG                                 equ     8009200DH
CRYPT_E_NO_SIGNER                               equ     8009200EH
CRYPT_E_PENDING_CLOSE                           equ     8009200FH
CRYPT_E_REVOKED                                 equ     80092010H
CRYPT_E_NO_REVOCATION_DLL                       equ     80092011H
CRYPT_E_NO_REVOCATION_CHECK                     equ     80092012H
CRYPT_E_REVOCATION_OFFLINE                      equ     80092013H
CRYPT_E_NOT_IN_REVOCATION_DATABASE              equ     80092014H
CRYPT_E_INVALID_NUMERIC_STRING                  equ     80092020H
CRYPT_E_INVALID_PRINTABLE_STRING                equ     80092021H
CRYPT_E_INVALID_IA5_STRING                      equ     80092022H
CRYPT_E_INVALID_X500_STRING                     equ     80092023H
CRYPT_E_NOT_CHAR_STRING                         equ     80092024H
CRYPT_E_FILERESIZED                             equ     80092025H
CRYPT_E_SECURITY_SETTINGS                       equ     80092026H
CRYPT_E_NO_VERIFY_USAGE_DLL                     equ     80092027H
CRYPT_E_NO_VERIFY_USAGE_CHECK                   equ     80092028H
CRYPT_E_VERIFY_USAGE_OFFLINE                    equ     80092029H
CRYPT_E_NOT_IN_CTL                              equ     8009202AH
CRYPT_E_NO_TRUSTED_SIGNER                       equ     8009202BH
CRYPT_E_MISSING_PUBKEY_PARA                     equ     8009202CH
CRYPT_E_OSS_ERROR                               equ     80093000H
CRYPT_E_ASN1_ERROR                              equ     80093100H
CRYPT_E_ASN1_INTERNAL                           equ     80093101H
CRYPT_E_ASN1_EOD                                equ     80093102H
CRYPT_E_ASN1_CORRUPT                            equ     80093103H
CRYPT_E_ASN1_LARGE                              equ     80093104H
CRYPT_E_ASN1_CONSTRAINT                         equ     80093105H
CRYPT_E_ASN1_MEMORY                             equ     80093106H
CRYPT_E_ASN1_OVERFLOW                           equ     80093107H
CRYPT_E_ASN1_BADPDU                             equ     80093108H
CRYPT_E_ASN1_BADARGS                            equ     80093109H
CRYPT_E_ASN1_BADREAL                            equ     8009310AH
CRYPT_E_ASN1_BADTAG                             equ     8009310BH
CRYPT_E_ASN1_CHOICE                             equ     8009310CH
CRYPT_E_ASN1_RULE                               equ     8009310DH
CRYPT_E_ASN1_UTF8                               equ     8009310EH
CRYPT_E_ASN1_PDU_TYPE                           equ     80093133H
CRYPT_E_ASN1_NYI                                equ     80093134H
CRYPT_E_ASN1_EXTENDED                           equ     80093201H
CRYPT_E_ASN1_NOEOD                              equ     80093202H

OSS_MORE_BUF                                    equ     80093001H
OSS_NEGATIVE_UINTEGER                           equ     80093002H
OSS_PDU_RANGE                                   equ     80093003H
OSS_MORE_INPUT                                  equ     80093004H
OSS_DATA_ERROR                                  equ     80093005H
OSS_BAD_ARG                                     equ     80093006H
OSS_BAD_VERSION                                 equ     80093007H
OSS_OUT_MEMORY                                  equ     80093008H
OSS_PDU_MISMATCH                                equ     80093009H
OSS_LIMITED                                     equ     8009300AH
OSS_BAD_PTR                                     equ     8009300BH
OSS_BAD_TIME                                    equ     8009300CH
OSS_INDEFINITE_NOT_SUPPORTED                    equ     8009300DH
OSS_MEM_ERROR                                   equ     8009300EH
OSS_BAD_TABLE                                   equ     8009300FH
OSS_TOO_LONG                                    equ     80093010H
OSS_CONSTRAINT_VIOLATED                         equ     80093011H
OSS_FATAL_ERROR                                 equ     80093012H
OSS_ACCESS_SERIALIZATION_ERROR                  equ     80093013H
OSS_NULL_TBL                                    equ     80093014H
OSS_NULL_FCN                                    equ     80093015H
OSS_BAD_ENCRULES                                equ     80093016H
OSS_UNAVAIL_ENCRULES                            equ     80093017H
OSS_CANT_OPEN_TRACE_WINDOW                      equ     80093018H
OSS_UNIMPLEMENTED                               equ     80093019H
OSS_OID_DLL_NOT_LINKED                          equ     8009301AH
OSS_CANT_OPEN_TRACE_FILE                        equ     8009301BH
OSS_TRACE_FILE_ALREADY_OPEN                     equ     8009301CH
OSS_TABLE_MISMATCH                              equ     8009301DH
OSS_TYPE_NOT_SUPPORTED                          equ     8009301EH
OSS_REAL_DLL_NOT_LINKED                         equ     8009301FH
OSS_REAL_CODE_NOT_LINKED                        equ     80093020H
OSS_OUT_OF_RANGE                                equ     80093021H
OSS_COPIER_DLL_NOT_LINKED                       equ     80093022H
OSS_CONSTRAINT_DLL_NOT_LINKED                   equ     80093023H
OSS_COMPARATOR_DLL_NOT_LINKED                   equ     80093024H
OSS_COMPARATOR_CODE_NOT_LINKED                  equ     80093025H
OSS_MEM_MGR_DLL_NOT_LINKED                      equ     80093026H
OSS_PDV_DLL_NOT_LINKED                          equ     80093027H
OSS_PDV_CODE_NOT_LINKED                         equ     80093028H
OSS_API_DLL_NOT_LINKED                          equ     80093029H
OSS_BERDER_DLL_NOT_LINKED                       equ     8009302AH
OSS_PER_DLL_NOT_LINKED                          equ     8009302BH
OSS_OPEN_TYPE_ERROR                             equ     8009302CH
OSS_MUTEX_NOT_CREATED                           equ     8009302DH
OSS_CANT_CLOSE_TRACE_FILE                       equ     8009302EH

CERTSRV_E_BAD_REQUESTSUBJECT                    equ     80094001H
CERTSRV_E_NO_REQUEST                            equ     80094002H
CERTSRV_E_BAD_REQUESTSTATUS                     equ     80094003H
CERTSRV_E_PROPERTY_EMPTY                        equ     80094004H
CERTSRV_E_INVALID_CA_CERTIFICATE                equ     80094005H
CERTSRV_E_SERVER_SUSPENDED                      equ     80094006H
CERTSRV_E_ENCODING_LENGTH                       equ     80094007H
CERTSRV_E_ROLECONFLICT                          equ     80094008H
CERTSRV_E_RESTRICTEDOFFICER                     equ     80094009H
CERTSRV_E_KEY_ARCHIVAL_NOT_CONFIGURED           equ     8009400AH
CERTSRV_E_NO_VALID_KRA                          equ     8009400BH
CERTSRV_E_BAD_REQUEST_KEY_ARCHIVAL              equ     8009400CH
CERTSRV_E_NO_CAADMIN_DEFINED                    equ     8009400DH
CERTSRV_E_BAD_RENEWAL_CERT_ATTRIBUTE            equ     8009400EH
CERTSRV_E_NO_DB_SESSIONS                        equ     8009400FH
CERTSRV_E_ALIGNMENT_FAULT                       equ     80094010H
CERTSRV_E_ENROLL_DENIED                         equ     80094011H
CERTSRV_E_TEMPLATE_DENIED                       equ     80094012H
CERTSRV_E_DOWNLEVEL_DC_SSL_OR_UPGRADE           equ     80094013H
CERTSRV_E_ADMIN_DENIED_REQUEST                  equ     80094014H
CERTSRV_E_NO_POLICY_SERVER                      equ     80094015H
CERTSRV_E_UNSUPPORTED_CERT_TYPE                 equ     80094800H
CERTSRV_E_NO_CERT_TYPE                          equ     80094801H
CERTSRV_E_TEMPLATE_CONFLICT                     equ     80094802H
CERTSRV_E_SUBJECT_ALT_NAME_REQUIRED             equ     80094803H
CERTSRV_E_ARCHIVED_KEY_REQUIRED                 equ     80094804H
CERTSRV_E_SMIME_REQUIRED                        equ     80094805H
CERTSRV_E_BAD_RENEWAL_SUBJECT                   equ     80094806H
CERTSRV_E_BAD_TEMPLATE_VERSION                  equ     80094807H
CERTSRV_E_TEMPLATE_POLICY_REQUIRED              equ     80094808H
CERTSRV_E_SIGNATURE_POLICY_REQUIRED             equ     80094809H
CERTSRV_E_SIGNATURE_COUNT                       equ     8009480AH
CERTSRV_E_SIGNATURE_REJECTED                    equ     8009480BH
CERTSRV_E_ISSUANCE_POLICY_REQUIRED              equ     8009480CH
CERTSRV_E_SUBJECT_UPN_REQUIRED                  equ     8009480DH
CERTSRV_E_SUBJECT_DIRECTORY_GUID_REQUIRED       equ     8009480EH
CERTSRV_E_SUBJECT_DNS_REQUIRED                  equ     8009480FH
CERTSRV_E_ARCHIVED_KEY_UNEXPECTED               equ     80094810H
CERTSRV_E_KEY_LENGTH                            equ     80094811H
CERTSRV_E_SUBJECT_EMAIL_REQUIRED                equ     80094812H
CERTSRV_E_UNKNOWN_CERT_TYPE                     equ     80094813H
CERTSRV_E_CERT_TYPE_OVERLAP                     equ     80094814H
CERTSRV_E_TOO_MANY_SIGNATURES                   equ     80094815H

XENROLL_E_KEY_NOT_EXPORTABLE                    equ     80095000H
XENROLL_E_CANNOT_ADD_ROOT_CERT                  equ     80095001H
XENROLL_E_RESPONSE_KA_HASH_NOT_FOUND            equ     80095002H
XENROLL_E_RESPONSE_UNEXPECTED_KA_HASH           equ     80095003H
XENROLL_E_RESPONSE_KA_HASH_MISMATCH             equ     80095004H
XENROLL_E_KEYSPEC_SMIME_MISMATCH                equ     80095005H

TRUST_E_SYSTEM_ERROR                            equ     80096001H
TRUST_E_NO_SIGNER_CERT                          equ     80096002H
TRUST_E_COUNTER_SIGNER                          equ     80096003H
TRUST_E_CERT_SIGNATURE                          equ     80096004H
TRUST_E_TIME_STAMP                              equ     80096005H
TRUST_E_BAD_DIGEST                              equ     80096010H
TRUST_E_BASIC_CONSTRAINTS                       equ     80096019H
TRUST_E_FINANCIAL_CRITERIA                      equ     8009601EH
TRUST_E_PROVIDER_UNKNOWN                        equ     800B0001H
TRUST_E_ACTION_UNKNOWN                          equ     800B0002H
TRUST_E_SUBJECT_FORM_UNKNOWN                    equ     800B0003H
TRUST_E_SUBJECT_NOT_TRUSTED                     equ     800B0004H

MSSIPOTF_E_OUTOFMEMRANGE                        equ     80097001H
MSSIPOTF_E_CANTGETOBJECT                        equ     80097002H
MSSIPOTF_E_NOHEADTABLE                          equ     80097003H
MSSIPOTF_E_BAD_MAGICNUMBER                      equ     80097004H
MSSIPOTF_E_BAD_OFFSET_TABLE                     equ     80097005H
MSSIPOTF_E_TABLE_TAGORDER                       equ     80097006H
MSSIPOTF_E_TABLE_LONGWORD                       equ     80097007H
MSSIPOTF_E_BAD_FIRST_TABLE_PLACEMENT            equ     80097008H
MSSIPOTF_E_TABLES_OVERLAP                       equ     80097009H
MSSIPOTF_E_TABLE_PADBYTES                       equ     8009700AH
MSSIPOTF_E_FILETOOSMALL                         equ     8009700BH
MSSIPOTF_E_TABLE_CHECKSUM                       equ     8009700CH
MSSIPOTF_E_FILE_CHECKSUM                        equ     8009700DH
MSSIPOTF_E_FAILED_POLICY                        equ     80097010H
MSSIPOTF_E_FAILED_HINTS_CHECK                   equ     80097011H
MSSIPOTF_E_NOT_OPENTYPE                         equ     80097012H
MSSIPOTF_E_FILE                                 equ     80097013H
MSSIPOTF_E_CRYPT                                equ     80097014H
MSSIPOTF_E_BADVERSION                           equ     80097015H
MSSIPOTF_E_DSIG_STRUCTURE                       equ     80097016H
MSSIPOTF_E_PCONST_CHECK                         equ     80097017H
MSSIPOTF_E_STRUCTURE                            equ     80097018H

ERROR_CRED_REQUIRES_CONFIRMATION                equ     80097019H
NTE_OP_OK                                       equ     0

DIGSIG_E_ENCODE                                 equ     800B0005H
DIGSIG_E_DECODE                                 equ     800B0006H
DIGSIG_E_EXTENSIBILITY                          equ     800B0007H
DIGSIG_E_CRYPTO                                 equ     800B0008H

PERSIST_E_SIZEDEFINITE                          equ     800B0009H
PERSIST_E_SIZEINDEFINITE                        equ     800B000AH
PERSIST_E_NOTSELFSIZING                         equ     800B000BH

TRUST_E_NOSIGNATURE                             equ     800B0100H
TRUST_E_FAIL                                    equ     800B010BH
TRUST_E_EXPLICIT_DISTRUST                       equ     800B0111H

CERT_E_EXPIRED                                  equ     800B0101H
CERT_E_VALIDITYPERIODNESTING                    equ     800B0102H
CERT_E_ROLE                                     equ     800B0103H
CERT_E_PATHLENCONST                             equ     800B0104H
CERT_E_CRITICAL                                 equ     800B0105H
CERT_E_PURPOSE                                  equ     800B0106H
CERT_E_ISSUERCHAINING                           equ     800B0107H
CERT_E_MALFORMED                                equ     800B0108H
CERT_E_UNTRUSTEDROOT                            equ     800B0109H
CERT_E_CHAINING                                 equ     800B010AH
CERT_E_REVOKED                                  equ     800B010CH
CERT_E_UNTRUSTEDTESTROOT                        equ     800B010DH
CERT_E_REVOCATION_FAILURE                       equ     800B010EH
CERT_E_CN_NO_MATCH                              equ     800B010FH
CERT_E_WRONG_USAGE                              equ     800B0110H
CERT_E_UNTRUSTEDCA                              equ     800B0112H
CERT_E_INVALID_POLICY                           equ     800B0113H
CERT_E_INVALID_NAME                             equ     800B0114H

SPAPI_E_EXPECTED_SECTION_NAME                   equ     800F0000H
SPAPI_E_BAD_SECTION_NAME_LINE                   equ     800F0001H
SPAPI_E_SECTION_NAME_TOO_LONG                   equ     800F0002H
SPAPI_E_GENERAL_SYNTAX                          equ     800F0003H
SPAPI_E_WRONG_INF_STYLE                         equ     800F0100H
SPAPI_E_SECTION_NOT_FOUND                       equ     800F0101H
SPAPI_E_LINE_NOT_FOUND                          equ     800F0102H
SPAPI_E_NO_BACKUP                               equ     800F0103H
SPAPI_E_NO_ASSOCIATED_CLASS                     equ     800F0200H
SPAPI_E_CLASS_MISMATCH                          equ     800F0201H
SPAPI_E_DUPLICATE_FOUND                         equ     800F0202H
SPAPI_E_NO_DRIVER_SELECTED                      equ     800F0203H
SPAPI_E_KEY_DOES_NOT_EXIST                      equ     800F0204H
SPAPI_E_INVALID_DEVINST_NAME                    equ     800F0205H
SPAPI_E_INVALID_CLASS                           equ     800F0206H
SPAPI_E_DEVINST_ALREADY_EXISTS                  equ     800F0207H
SPAPI_E_DEVINFO_NOT_REGISTERED                  equ     800F0208H
SPAPI_E_INVALID_REG_PROPERTY                    equ     800F0209H
SPAPI_E_NO_INF                                  equ     800F020AH
SPAPI_E_NO_SUCH_DEVINST                         equ     800F020BH
SPAPI_E_CANT_LOAD_CLASS_ICON                    equ     800F020CH
SPAPI_E_INVALID_CLASS_INSTALLER                 equ     800F020DH
SPAPI_E_DI_DO_DEFAULT                           equ     800F020EH
SPAPI_E_DI_NOFILECOPY                           equ     800F020FH
SPAPI_E_INVALID_HWPROFILE                       equ     800F0210H
SPAPI_E_NO_DEVICE_SELECTED                      equ     800F0211H
SPAPI_E_DEVINFO_LIST_LOCKED                     equ     800F0212H
SPAPI_E_DEVINFO_DATA_LOCKED                     equ     800F0213H
SPAPI_E_DI_BAD_PATH                             equ     800F0214H
SPAPI_E_NO_CLASSINSTALL_PARAMS                  equ     800F0215H
SPAPI_E_FILEQUEUE_LOCKED                        equ     800F0216H
SPAPI_E_BAD_SERVICE_INSTALLSECT                 equ     800F0217H
SPAPI_E_NO_CLASS_DRIVER_LIST                    equ     800F0218H
SPAPI_E_NO_ASSOCIATED_SERVICE                   equ     800F0219H
SPAPI_E_NO_DEFAULT_DEVICE_INTERFACE             equ     800F021AH
SPAPI_E_DEVICE_INTERFACE_ACTIVE                 equ     800F021BH
SPAPI_E_DEVICE_INTERFACE_REMOVED                equ     800F021CH
SPAPI_E_BAD_INTERFACE_INSTALLSECT               equ     800F021DH
SPAPI_E_NO_SUCH_INTERFACE_CLASS                 equ     800F021EH
SPAPI_E_INVALID_REFERENCE_STRING                equ     800F021FH
SPAPI_E_INVALID_MACHINENAME                     equ     800F0220H
SPAPI_E_REMOTE_COMM_FAILURE                     equ     800F0221H
SPAPI_E_MACHINE_UNAVAILABLE                     equ     800F0222H
SPAPI_E_NO_CONFIGMGR_SERVICES                   equ     800F0223H
SPAPI_E_INVALID_PROPPAGE_PROVIDER               equ     800F0224H
SPAPI_E_NO_SUCH_DEVICE_INTERFACE                equ     800F0225H
SPAPI_E_DI_POSTPROCESSING_REQUIRED              equ     800F0226H
SPAPI_E_INVALID_COINSTALLER                     equ     800F0227H
SPAPI_E_NO_COMPAT_DRIVERS                       equ     800F0228H
SPAPI_E_NO_DEVICE_ICON                          equ     800F0229H
SPAPI_E_INVALID_INF_LOGCONFIG                   equ     800F022AH
SPAPI_E_DI_DONT_INSTALL                         equ     800F022BH
SPAPI_E_INVALID_FILTER_DRIVER                   equ     800F022CH
SPAPI_E_NON_WINDOWS_NT_DRIVER                   equ     800F022DH
SPAPI_E_NON_WINDOWS_DRIVER                      equ     800F022EH
SPAPI_E_NO_CATALOG_FOR_OEM_INF                  equ     800F022FH
SPAPI_E_DEVINSTALL_QUEUE_NONNATIVE              equ     800F0230H
SPAPI_E_NOT_DISABLEABLE                         equ     800F0231H
SPAPI_E_CANT_REMOVE_DEVINST                     equ     800F0232H
SPAPI_E_INVALID_TARGET                          equ     800F0233H
SPAPI_E_DRIVER_NONNATIVE                        equ     800F0234H
SPAPI_E_IN_WOW64                                equ     800F0235H
SPAPI_E_SET_SYSTEM_RESTORE_POINT                equ     800F0236H
SPAPI_E_INCORRECTLY_COPIED_INF                  equ     800F0237H
SPAPI_E_SCE_DISABLED                            equ     800F0238H
SPAPI_E_UNKNOWN_EXCEPTION                       equ     800F0239H
SPAPI_E_PNP_REGISTRY_ERROR                      equ     800F023AH
SPAPI_E_REMOTE_REQUEST_UNSUPPORTED              equ     800F023BH
SPAPI_E_NOT_AN_INSTALLED_OEM_INF                equ     800F023CH
SPAPI_E_INF_IN_USE_BY_DEVICES                   equ     800F023DH
SPAPI_E_DI_FUNCTION_OBSOLETE                    equ     800F023EH
SPAPI_E_NO_AUTHENTICODE_CATALOG                 equ     800F023FH
SPAPI_E_AUTHENTICODE_DISALLOWED                 equ     800F0240H
SPAPI_E_AUTHENTICODE_TRUSTED_PUBLISHER          equ     800F0241H
SPAPI_E_AUTHENTICODE_TRUST_NOT_ESTABLISHED      equ     800F0242H
SPAPI_E_AUTHENTICODE_PUBLISHER_NOT_TRUSTED      equ     800F0243H
SPAPI_E_SIGNATURE_OSATTRIBUTE_MISMATCH          equ     800F0244H
SPAPI_E_ONLY_VALIDATE_VIA_AUTHENTICODE          equ     800F0245H
SPAPI_E_DEVICE_INSTALLER_NOT_READY              equ     800F0246H
SPAPI_E_DRIVER_STORE_ADD_FAILED                 equ     800F0247H
SPAPI_E_DEVICE_INSTALL_BLOCKED                  equ     800F0248H
SPAPI_E_DRIVER_INSTALL_BLOCKED                  equ     800F0249H
SPAPI_E_WRONG_INF_TYPE                          equ     800F024AH
SPAPI_E_FILE_HASH_NOT_IN_CATALOG                equ     800F024BH
SPAPI_E_DRIVER_STORE_DELETE_FAILED              equ     800F024CH
SPAPI_E_UNRECOVERABLE_STACK_OVERFLOW            equ     800F0300H
SPAPI_E_ERROR_NOT_INSTALLED                     equ     800F1000H

SCARD_S_SUCCESS                                 equ     NO_ERROR
SCARD_F_INTERNAL_ERROR                          equ     80100001H
SCARD_E_CANCELLED                               equ     80100002H
SCARD_E_INVALID_HANDLE                          equ     80100003H
SCARD_E_INVALID_PARAMETER                       equ     80100004H
SCARD_E_INVALID_TARGET                          equ     80100005H
SCARD_E_NO_MEMORY                               equ     80100006H
SCARD_F_WAITED_TOO_LONG                         equ     80100007H
SCARD_E_INSUFFICIENT_BUFFER                     equ     80100008H
SCARD_E_UNKNOWN_READER                          equ     80100009H
SCARD_E_TIMEOUT                                 equ     8010000AH
SCARD_E_SHARING_VIOLATION                       equ     8010000BH
SCARD_E_NO_SMARTCARD                            equ     8010000CH
SCARD_E_UNKNOWN_CARD                            equ     8010000DH
SCARD_E_CANT_DISPOSE                            equ     8010000EH
SCARD_E_PROTO_MISMATCH                          equ     8010000FH
SCARD_E_NOT_READY                               equ     80100010H
SCARD_E_INVALID_VALUE                           equ     80100011H
SCARD_E_SYSTEM_CANCELLED                        equ     80100012H
SCARD_F_COMM_ERROR                              equ     80100013H
SCARD_F_UNKNOWN_ERROR                           equ     80100014H
SCARD_E_INVALID_ATR                             equ     80100015H
SCARD_E_NOT_TRANSACTED                          equ     80100016H
SCARD_E_READER_UNAVAILABLE                      equ     80100017H
SCARD_P_SHUTDOWN                                equ     80100018H
SCARD_E_PCI_TOO_SMALL                           equ     80100019H
SCARD_E_READER_UNSUPPORTED                      equ     8010001AH
SCARD_E_DUPLICATE_READER                        equ     8010001BH
SCARD_E_CARD_UNSUPPORTED                        equ     8010001CH
SCARD_E_NO_SERVICE                              equ     8010001DH
SCARD_E_SERVICE_STOPPED                         equ     8010001EH
SCARD_E_UNEXPECTED                              equ     8010001FH
SCARD_E_ICC_INSTALLATION                        equ     80100020H
SCARD_E_ICC_CREATEORDER                         equ     80100021H
SCARD_E_UNSUPPORTED_FEATURE                     equ     80100022H
SCARD_E_DIR_NOT_FOUND                           equ     80100023H
SCARD_E_FILE_NOT_FOUND                          equ     80100024H
SCARD_E_NO_DIR                                  equ     80100025H
SCARD_E_NO_FILE                                 equ     80100026H
SCARD_E_NO_ACCESS                               equ     80100027H
SCARD_E_WRITE_TOO_MANY                          equ     80100028H
SCARD_E_BAD_SEEK                                equ     80100029H
SCARD_E_INVALID_CHV                             equ     8010002AH
SCARD_E_UNKNOWN_RES_MNG                         equ     8010002BH
SCARD_E_NO_SUCH_CERTIFICATE                     equ     8010002CH
SCARD_E_CERTIFICATE_UNAVAILABLE                 equ     8010002DH
SCARD_E_NO_READERS_AVAILABLE                    equ     8010002EH
SCARD_E_COMM_DATA_LOST                          equ     8010002FH
SCARD_E_NO_KEY_CONTAINER                        equ     80100030H
SCARD_E_SERVER_TOO_BUSY                         equ     80100031H
SCARD_E_PIN_CACHE_EXPIRED                       equ     80100032H
SCARD_E_NO_PIN_CACHE                            equ     80100033H
SCARD_E_READ_ONLY_CARD                          equ     80100034H
SCARD_W_UNSUPPORTED_CARD                        equ     80100065H
SCARD_W_UNRESPONSIVE_CARD                       equ     80100066H
SCARD_W_UNPOWERED_CARD                          equ     80100067H
SCARD_W_RESET_CARD                              equ     80100068H
SCARD_W_REMOVED_CARD                            equ     80100069H
SCARD_W_SECURITY_VIOLATION                      equ     8010006AH
SCARD_W_WRONG_CHV                               equ     8010006BH
SCARD_W_CHV_BLOCKED                             equ     8010006CH
SCARD_W_EOF                                     equ     8010006DH
SCARD_W_CANCELLED_BY_USER                       equ     8010006EH
SCARD_W_CARD_NOT_AUTHENTICATED                  equ     8010006FH
SCARD_W_CACHE_ITEM_NOT_FOUND                    equ     80100070H
SCARD_W_CACHE_ITEM_STALE                        equ     80100071H
SCARD_W_CACHE_ITEM_TOO_BIG                      equ     80100072H

COMADMIN_E_OBJECTERRORS                         equ     80110401H
COMADMIN_E_OBJECTINVALID                        equ     80110402H
COMADMIN_E_KEYMISSING                           equ     80110403H
COMADMIN_E_ALREADYINSTALLED                     equ     80110404H
COMADMIN_E_APP_FILE_WRITEFAIL                   equ     80110407H
COMADMIN_E_APP_FILE_READFAIL                    equ     80110408H
COMADMIN_E_APP_FILE_VERSION                     equ     80110409H
COMADMIN_E_BADPATH                              equ     8011040AH
COMADMIN_E_APPLICATIONEXISTS                    equ     8011040BH
COMADMIN_E_ROLEEXISTS                           equ     8011040CH
COMADMIN_E_CANTCOPYFILE                         equ     8011040DH
COMADMIN_E_NOUSER                               equ     8011040FH
COMADMIN_E_INVALIDUSERIDS                       equ     80110410H
COMADMIN_E_NOREGISTRYCLSID                      equ     80110411H
COMADMIN_E_BADREGISTRYPROGID                    equ     80110412H
COMADMIN_E_AUTHENTICATIONLEVEL                  equ     80110413H
COMADMIN_E_USERPASSWDNOTVALID                   equ     80110414H
COMADMIN_E_CLSIDORIIDMISMATCH                   equ     80110418H
COMADMIN_E_REMOTEINTERFACE                      equ     80110419H
COMADMIN_E_DLLREGISTERSERVER                    equ     8011041AH
COMADMIN_E_NOSERVERSHARE                        equ     8011041BH
COMADMIN_E_DLLLOADFAILED                        equ     8011041DH
COMADMIN_E_BADREGISTRYLIBID                     equ     8011041EH
COMADMIN_E_APPDIRNOTFOUND                       equ     8011041FH
COMADMIN_E_REGISTRARFAILED                      equ     80110423H
COMADMIN_E_COMPFILE_DOESNOTEXIST                equ     80110424H
COMADMIN_E_COMPFILE_LOADDLLFAIL                 equ     80110425H
COMADMIN_E_COMPFILE_GETCLASSOBJ                 equ     80110426H
COMADMIN_E_COMPFILE_CLASSNOTAVAIL               equ     80110427H
COMADMIN_E_COMPFILE_BADTLB                      equ     80110428H
COMADMIN_E_COMPFILE_NOTINSTALLABLE              equ     80110429H
COMADMIN_E_NOTCHANGEABLE                        equ     8011042AH
COMADMIN_E_NOTDELETEABLE                        equ     8011042BH
COMADMIN_E_SESSION                              equ     8011042CH
COMADMIN_E_COMP_MOVE_LOCKED                     equ     8011042DH
COMADMIN_E_COMP_MOVE_BAD_DEST                   equ     8011042EH
COMADMIN_E_REGISTERTLB                          equ     80110430H
COMADMIN_E_SYSTEMAPP                            equ     80110433H
COMADMIN_E_COMPFILE_NOREGISTRAR                 equ     80110434H
COMADMIN_E_COREQCOMPINSTALLED                   equ     80110435H
COMADMIN_E_SERVICENOTINSTALLED                  equ     80110436H
COMADMIN_E_PROPERTYSAVEFAILED                   equ     80110437H
COMADMIN_E_OBJECTEXISTS                         equ     80110438H
COMADMIN_E_COMPONENTEXISTS                      equ     80110439H
COMADMIN_E_REGFILE_CORRUPT                      equ     8011043BH
COMADMIN_E_PROPERTY_OVERFLOW                    equ     8011043CH
COMADMIN_E_NOTINREGISTRY                        equ     8011043EH
COMADMIN_E_OBJECTNOTPOOLABLE                    equ     8011043FH
COMADMIN_E_APPLID_MATCHES_CLSID                 equ     80110446H
COMADMIN_E_ROLE_DOES_NOT_EXIST                  equ     80110447H
COMADMIN_E_START_APP_NEEDS_COMPONENTS           equ     80110448H
COMADMIN_E_REQUIRES_DIFFERENT_PLATFORM          equ     80110449H
COMADMIN_E_CAN_NOT_EXPORT_APP_PROXY             equ     8011044AH
COMADMIN_E_CAN_NOT_START_APP                    equ     8011044BH
COMADMIN_E_CAN_NOT_EXPORT_SYS_APP               equ     8011044CH
COMADMIN_E_CANT_SUBSCRIBE_TO_COMPONENT          equ     8011044DH
COMADMIN_E_EVENTCLASS_CANT_BE_SUBSCRIBER        equ     8011044EH
COMADMIN_E_LIB_APP_PROXY_INCOMPATIBLE           equ     8011044FH
COMADMIN_E_BASE_PARTITION_ONLY                  equ     80110450H
COMADMIN_E_START_APP_DISABLED                   equ     80110451H
COMADMIN_E_CAT_DUPLICATE_PARTITION_NAME         equ     80110457H
COMADMIN_E_CAT_INVALID_PARTITION_NAME           equ     80110458H
COMADMIN_E_CAT_PARTITION_IN_USE                 equ     80110459H
COMADMIN_E_FILE_PARTITION_DUPLICATE_FILES       equ     8011045AH
COMADMIN_E_CAT_IMPORTED_COMPONENTS_NOT_ALLOWED  equ     8011045BH
COMADMIN_E_AMBIGUOUS_APPLICATION_NAME           equ     8011045CH
COMADMIN_E_AMBIGUOUS_PARTITION_NAME             equ     8011045DH
COMADMIN_E_REGDB_NOTINITIALIZED                 equ     80110472H
COMADMIN_E_REGDB_NOTOPEN                        equ     80110473H
COMADMIN_E_REGDB_SYSTEMERR                      equ     80110474H
COMADMIN_E_REGDB_ALREADYRUNNING                 equ     80110475H
COMADMIN_E_MIG_VERSIONNOTSUPPORTED              equ     80110480H
COMADMIN_E_MIG_SCHEMANOTFOUND                   equ     80110481H
COMADMIN_E_CAT_BITNESSMISMATCH                  equ     80110482H
COMADMIN_E_CAT_UNACCEPTABLEBITNESS              equ     80110483H
COMADMIN_E_CAT_WRONGAPPBITNESS                  equ     80110484H
COMADMIN_E_CAT_PAUSE_RESUME_NOT_SUPPORTED       equ     80110485H
COMADMIN_E_CAT_SERVERFAULT                      equ     80110486H

COMQC_E_APPLICATION_NOT_QUEUED                  equ     80110600H
COMQC_E_NO_QUEUEABLE_INTERFACES                 equ     80110601H
COMQC_E_QUEUING_SERVICE_NOT_AVAILABLE           equ     80110602H
COMQC_E_NO_IPERSISTSTREAM                       equ     80110603H
COMQC_E_BAD_MESSAGE                             equ     80110604H
COMQC_E_UNAUTHENTICATED                         equ     80110605H
COMQC_E_UNTRUSTED_ENQUEUER                      equ     80110606H

MSDTC_E_DUPLICATE_RESOURCE                      equ     80110701H

COMADMIN_E_OBJECT_PARENT_MISSING                equ     80110808H
COMADMIN_E_OBJECT_DOES_NOT_EXIST                equ     80110809H
COMADMIN_E_APP_NOT_RUNNING                      equ     8011080AH
COMADMIN_E_INVALID_PARTITION                    equ     8011080BH
COMADMIN_E_SVCAPP_NOT_POOLABLE_OR_RECYCLABLE    equ     8011080DH
COMADMIN_E_USER_IN_SET                          equ     8011080EH
COMADMIN_E_CANTRECYCLELIBRARYAPPS               equ     8011080FH
COMADMIN_E_CANTRECYCLESERVICEAPPS               equ     80110811H
COMADMIN_E_PROCESSALREADYRECYCLED               equ     80110812H
COMADMIN_E_PAUSEDPROCESSMAYNOTBERECYCLED        equ     80110813H
COMADMIN_E_CANTMAKEINPROCSERVICE                equ     80110814H
COMADMIN_E_PROGIDINUSEBYCLSID                   equ     80110815H
COMADMIN_E_DEFAULT_PARTITION_NOT_IN_SET         equ     80110816H
COMADMIN_E_RECYCLEDPROCESSMAYNOTBEPAUSED        equ     80110817H
COMADMIN_E_PARTITION_ACCESSDENIED               equ     80110818H
COMADMIN_E_PARTITION_MSI_ONLY                   equ     80110819H
COMADMIN_E_LEGACYCOMPS_NOT_ALLOWED_IN_1_0_FORMAT equ    8011081AH
COMADMIN_E_LEGACYCOMPS_NOT_ALLOWED_IN_NONBASE_PARTITIONS equ 8011081BH
COMADMIN_E_COMP_MOVE_SOURCE                     equ     8011081CH
COMADMIN_E_COMP_MOVE_DEST                       equ     8011081DH
COMADMIN_E_COMP_MOVE_PRIVATE                    equ     8011081EH
COMADMIN_E_BASEPARTITION_REQUIRED_IN_SET        equ     8011081FH
COMADMIN_E_CANNOT_ALIAS_EVENTCLASS              equ     80110820H
COMADMIN_E_PRIVATE_ACCESSDENIED                 equ     80110821H
COMADMIN_E_SAFERINVALID                         equ     80110822H
COMADMIN_E_REGISTRY_ACCESSDENIED                equ     80110823H
COMADMIN_E_PARTITIONS_DISABLED                  equ     80110824H

ERROR_FLT_IO_COMPLETE                           equ     001F0001H
ERROR_FLT_NO_HANDLER_DEFINED                    equ     801F0001H
ERROR_FLT_CONTEXT_ALREADY_DEFINED               equ     801F0002H
ERROR_FLT_INVALID_ASYNCHRONOUS_REQUEST          equ     801F0003H
ERROR_FLT_DISALLOW_FAST_IO                      equ     801F0004H
ERROR_FLT_INVALID_NAME_REQUEST                  equ     801F0005H
ERROR_FLT_NOT_SAFE_TO_POST_OPERATION            equ     801F0006H
ERROR_FLT_NOT_INITIALIZED                       equ     801F0007H
ERROR_FLT_FILTER_NOT_READY                      equ     801F0008H
ERROR_FLT_POST_OPERATION_CLEANUP                equ     801F0009H
ERROR_FLT_INTERNAL_ERROR                        equ     801F000AH
ERROR_FLT_DELETING_OBJECT                       equ     801F000BH
ERROR_FLT_MUST_BE_NONPAGED_POOL                 equ     801F000CH
ERROR_FLT_DUPLICATE_ENTRY                       equ     801F000DH
ERROR_FLT_CBDQ_DISABLED                         equ     801F000EH
ERROR_FLT_DO_NOT_ATTACH                         equ     801F000FH
ERROR_FLT_DO_NOT_DETACH                         equ     801F0010H
ERROR_FLT_INSTANCE_ALTITUDE_COLLISION           equ     801F0011H
ERROR_FLT_INSTANCE_NAME_COLLISION               equ     801F0012H
ERROR_FLT_FILTER_NOT_FOUND                      equ     801F0013H
ERROR_FLT_VOLUME_NOT_FOUND                      equ     801F0014H
ERROR_FLT_INSTANCE_NOT_FOUND                    equ     801F0015H
ERROR_FLT_CONTEXT_ALLOCATION_NOT_FOUND          equ     801F0016H
ERROR_FLT_INVALID_CONTEXT_REGISTRATION          equ     801F0017H
ERROR_FLT_NAME_CACHE_MISS                       equ     801F0018H
ERROR_FLT_NO_DEVICE_OBJECT                      equ     801F0019H
ERROR_FLT_VOLUME_ALREADY_MOUNTED                equ     801F001AH
ERROR_FLT_ALREADY_ENLISTED                      equ     801F001BH
ERROR_FLT_CONTEXT_ALREADY_LINKED                equ     801F001CH
ERROR_FLT_NO_WAITER_FOR_REPLY                   equ     801F0020H

ERROR_HUNG_DISPLAY_DRIVER_THREAD                equ     80260001H

DWM_E_COMPOSITIONDISABLED                       equ     80263001H
DWM_E_REMOTING_NOT_SUPPORTED                    equ     80263002H
DWM_E_NO_REDIRECTION_SURFACE_AVAILABLE          equ     80263003H
DWM_E_NOT_QUEUING_PRESENTS                      equ     80263004H
DWM_E_ADAPTER_NOT_FOUND                         equ     80263005H
DWM_S_GDI_REDIRECTION_SURFACE                   equ     00263005H

ERROR_MONITOR_NO_DESCRIPTOR                     equ     00261001H
ERROR_MONITOR_UNKNOWN_DESCRIPTOR_FORMAT         equ     00261002H
ERROR_MONITOR_INVALID_DESCRIPTOR_CHECKSUM       equ     0C0261003H
ERROR_MONITOR_INVALID_STANDARD_TIMING_BLOCK     equ     0C0261004H
ERROR_MONITOR_WMI_DATABLOCK_REGISTRATION_FAILED equ     0C0261005H
ERROR_MONITOR_INVALID_SERIAL_NUMBER_MONDSC_BLOCK equ    0C0261006H
ERROR_MONITOR_INVALID_USER_FRIENDLY_MONDSC_BLOCK equ    0C0261007H
ERROR_MONITOR_NO_MORE_DESCRIPTOR_DATA           equ     0C0261008H
ERROR_MONITOR_INVALID_DETAILED_TIMING_BLOCK     equ     0C0261009H
ERROR_MONITOR_INVALID_MANUFACTURE_DATE          equ     0C026100AH

ERROR_GRAPHICS_NOT_EXCLUSIVE_MODE_OWNER         equ     0C0262000H
ERROR_GRAPHICS_INSUFFICIENT_DMA_BUFFER          equ     0C0262001H
ERROR_GRAPHICS_INVALID_DISPLAY_ADAPTER          equ     0C0262002H
ERROR_GRAPHICS_ADAPTER_WAS_RESET                equ     0C0262003H
ERROR_GRAPHICS_INVALID_DRIVER_MODEL             equ     0C0262004H
ERROR_GRAPHICS_PRESENT_MODE_CHANGED             equ     0C0262005H
ERROR_GRAPHICS_PRESENT_OCCLUDED                 equ     0C0262006H
ERROR_GRAPHICS_PRESENT_DENIED                   equ     0C0262007H
ERROR_GRAPHICS_CANNOTCOLORCONVERT               equ     0C0262008H
ERROR_GRAPHICS_DRIVER_MISMATCH                  equ     0C0262009H
ERROR_GRAPHICS_PARTIAL_DATA_POPULATED           equ     04026200AH
ERROR_GRAPHICS_PRESENT_REDIRECTION_DISABLED     equ     0C026200BH
ERROR_GRAPHICS_PRESENT_UNOCCLUDED               equ     0C026200CH
ERROR_GRAPHICS_NO_VIDEO_MEMORY                  equ     0C0262100H
ERROR_GRAPHICS_CANT_LOCK_MEMORY                 equ     0C0262101H
ERROR_GRAPHICS_ALLOCATION_BUSY                  equ     0C0262102H
ERROR_GRAPHICS_TOO_MANY_REFERENCES              equ     0C0262103H
ERROR_GRAPHICS_TRY_AGAIN_LATER                  equ     0C0262104H
ERROR_GRAPHICS_TRY_AGAIN_NOW                    equ     0C0262105H
ERROR_GRAPHICS_ALLOCATION_INVALID               equ     0C0262106H
ERROR_GRAPHICS_UNSWIZZLING_APERTURE_UNAVAILABLE equ     0C0262107H
ERROR_GRAPHICS_UNSWIZZLING_APERTURE_UNSUPPORTED equ     0C0262108H
ERROR_GRAPHICS_CANT_EVICT_PINNED_ALLOCATION     equ     0C0262109H
ERROR_GRAPHICS_INVALID_ALLOCATION_USAGE         equ     0C0262110H
ERROR_GRAPHICS_CANT_RENDER_LOCKED_ALLOCATION    equ     0C0262111H
ERROR_GRAPHICS_ALLOCATION_CLOSED                equ     0C0262112H
ERROR_GRAPHICS_INVALID_ALLOCATION_INSTANCE      equ     0C0262113H
ERROR_GRAPHICS_INVALID_ALLOCATION_HANDLE        equ     0C0262114H
ERROR_GRAPHICS_WRONG_ALLOCATION_DEVICE          equ     0C0262115H
ERROR_GRAPHICS_ALLOCATION_CONTENT_LOST          equ     0C0262116H
ERROR_GRAPHICS_GPU_EXCEPTION_ON_DEVICE          equ     0C0262200H
ERROR_GRAPHICS_INVALID_VIDPN_TOPOLOGY           equ     0C0262300H
ERROR_GRAPHICS_VIDPN_TOPOLOGY_NOT_SUPPORTED     equ     0C0262301H
ERROR_GRAPHICS_VIDPN_TOPOLOGY_CURRENTLY_NOT_SUPPORTED equ 0C0262302H
ERROR_GRAPHICS_INVALID_VIDPN                    equ     0C0262303H
ERROR_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE     equ     0C0262304H
ERROR_GRAPHICS_INVALID_VIDEO_PRESENT_TARGET     equ     0C0262305H
ERROR_GRAPHICS_VIDPN_MODALITY_NOT_SUPPORTED     equ     0C0262306H
ERROR_GRAPHICS_MODE_NOT_PINNED                  equ     000262307H
ERROR_GRAPHICS_INVALID_VIDPN_SOURCEMODESET      equ     0C0262308H
ERROR_GRAPHICS_INVALID_VIDPN_TARGETMODESET      equ     0C0262309H
ERROR_GRAPHICS_INVALID_FREQUENCY                equ     0C026230AH
ERROR_GRAPHICS_INVALID_ACTIVE_REGION            equ     0C026230BH
ERROR_GRAPHICS_INVALID_TOTAL_REGION             equ     0C026230CH
ERROR_GRAPHICS_INVALID_VIDEO_PRESENT_SOURCE_MODE equ    0C0262310H
ERROR_GRAPHICS_INVALID_VIDEO_PRESENT_TARGET_MODE equ    0C0262311H
ERROR_GRAPHICS_PINNED_MODE_MUST_REMAIN_IN_SET   equ     0C0262312H
ERROR_GRAPHICS_PATH_ALREADY_IN_TOPOLOGY         equ     0C0262313H
ERROR_GRAPHICS_MODE_ALREADY_IN_MODESET          equ     0C0262314H
ERROR_GRAPHICS_INVALID_VIDEOPRESENTSOURCESET    equ     0C0262315H
ERROR_GRAPHICS_INVALID_VIDEOPRESENTTARGETSET    equ     0C0262316H
ERROR_GRAPHICS_SOURCE_ALREADY_IN_SET            equ     0C0262317H
ERROR_GRAPHICS_TARGET_ALREADY_IN_SET            equ     0C0262318H
ERROR_GRAPHICS_INVALID_VIDPN_PRESENT_PATH       equ     0C0262319H
ERROR_GRAPHICS_NO_RECOMMENDED_VIDPN_TOPOLOGY    equ     0C026231AH
ERROR_GRAPHICS_INVALID_MONITOR_FREQUENCYRANGESET equ    0C026231BH
ERROR_GRAPHICS_INVALID_MONITOR_FREQUENCYRANGE   equ     0C026231CH
ERROR_GRAPHICS_FREQUENCYRANGE_NOT_IN_SET        equ     0C026231DH
ERROR_GRAPHICS_NO_PREFERRED_MODE                equ     00026231EH
ERROR_GRAPHICS_FREQUENCYRANGE_ALREADY_IN_SET    equ     0C026231FH
ERROR_GRAPHICS_STALE_MODESET                    equ     0C0262320H
ERROR_GRAPHICS_INVALID_MONITOR_SOURCEMODESET    equ     0C0262321H
ERROR_GRAPHICS_INVALID_MONITOR_SOURCE_MODE      equ     0C0262322H
ERROR_GRAPHICS_NO_RECOMMENDED_FUNCTIONAL_VIDPN  equ     0C0262323H
ERROR_GRAPHICS_MODE_ID_MUST_BE_UNIQUE           equ     0C0262324H
ERROR_GRAPHICS_EMPTY_ADAPTER_MONITOR_MODE_SUPPORT_INTERSECTION equ 0C0262325H
ERROR_GRAPHICS_VIDEO_PRESENT_TARGETS_LESS_THAN_SOURCES equ 0C0262326H
ERROR_GRAPHICS_PATH_NOT_IN_TOPOLOGY             equ     0C0262327H
ERROR_GRAPHICS_ADAPTER_MUST_HAVE_AT_LEAST_ONE_SOURCE equ 0C0262328H
ERROR_GRAPHICS_ADAPTER_MUST_HAVE_AT_LEAST_ONE_TARGET equ 0C0262329H
ERROR_GRAPHICS_INVALID_MONITORDESCRIPTORSET     equ     0C026232AH
ERROR_GRAPHICS_INVALID_MONITORDESCRIPTOR        equ     0C026232BH
ERROR_GRAPHICS_MONITORDESCRIPTOR_NOT_IN_SET     equ     0C026232CH
ERROR_GRAPHICS_MONITORDESCRIPTOR_ALREADY_IN_SET equ     0C026232DH
ERROR_GRAPHICS_MONITORDESCRIPTOR_ID_MUST_BE_UNIQUE equ  0C026232EH
ERROR_GRAPHICS_INVALID_VIDPN_TARGET_SUBSET_TYPE equ     0C026232FH
ERROR_GRAPHICS_RESOURCES_NOT_RELATED            equ     0C0262330H
ERROR_GRAPHICS_SOURCE_ID_MUST_BE_UNIQUE         equ     0C0262331H
ERROR_GRAPHICS_TARGET_ID_MUST_BE_UNIQUE         equ     0C0262332H
ERROR_GRAPHICS_NO_AVAILABLE_VIDPN_TARGET        equ     0C0262333H
ERROR_GRAPHICS_MONITOR_COULD_NOT_BE_ASSOCIATED_WITH_ADAPTER equ 0C0262334H
ERROR_GRAPHICS_NO_VIDPNMGR                      equ     0C0262335H
ERROR_GRAPHICS_NO_ACTIVE_VIDPN                  equ     0C0262336H
ERROR_GRAPHICS_STALE_VIDPN_TOPOLOGY             equ     0C0262337H
ERROR_GRAPHICS_MONITOR_NOT_CONNECTED            equ     0C0262338H
ERROR_GRAPHICS_SOURCE_NOT_IN_TOPOLOGY           equ     0C0262339H
ERROR_GRAPHICS_INVALID_PRIMARYSURFACE_SIZE      equ     0C026233AH
ERROR_GRAPHICS_INVALID_VISIBLEREGION_SIZE       equ     0C026233BH
ERROR_GRAPHICS_INVALID_STRIDE                   equ     0C026233CH
ERROR_GRAPHICS_INVALID_PIXELFORMAT              equ     0C026233DH
ERROR_GRAPHICS_INVALID_COLORBASIS               equ     0C026233EH
ERROR_GRAPHICS_INVALID_PIXELVALUEACCESSMODE     equ     0C026233FH
ERROR_GRAPHICS_TARGET_NOT_IN_TOPOLOGY           equ     0C0262340H
ERROR_GRAPHICS_NO_DISPLAY_MODE_MANAGEMENT_SUPPORT equ   0C0262341H
ERROR_GRAPHICS_VIDPN_SOURCE_IN_USE              equ     0C0262342H
ERROR_GRAPHICS_CANT_ACCESS_ACTIVE_VIDPN         equ     0C0262343H
ERROR_GRAPHICS_INVALID_PATH_IMPORTANCE_ORDINAL  equ     0C0262344H
ERROR_GRAPHICS_INVALID_PATH_CONTENT_GEOMETRY_TRANSFORMATION equ 0C0262345H
ERROR_GRAPHICS_PATH_CONTENT_GEOMETRY_TRANSFORMATION_NOT_SUPPORTED equ 0C0262346H
ERROR_GRAPHICS_INVALID_GAMMA_RAMP               equ     0C0262347H
ERROR_GRAPHICS_GAMMA_RAMP_NOT_SUPPORTED         equ     0C0262348H
ERROR_GRAPHICS_MULTISAMPLING_NOT_SUPPORTED      equ     0C0262349H
ERROR_GRAPHICS_MODE_NOT_IN_MODESET              equ     0C026234AH
ERROR_GRAPHICS_DATASET_IS_EMPTY                 equ     00026234BH
ERROR_GRAPHICS_NO_MORE_ELEMENTS_IN_DATASET      equ     00026234CH
ERROR_GRAPHICS_INVALID_VIDPN_TOPOLOGY_RECOMMENDATION_REASON equ 0C026234DH
ERROR_GRAPHICS_INVALID_PATH_CONTENT_TYPE        equ     0C026234EH
ERROR_GRAPHICS_INVALID_COPYPROTECTION_TYPE      equ     0C026234FH
ERROR_GRAPHICS_UNASSIGNED_MODESET_ALREADY_EXISTS equ    0C0262350H
ERROR_GRAPHICS_PATH_CONTENT_GEOMETRY_TRANSFORMATION_NOT_PINNED equ 00262351H
ERROR_GRAPHICS_INVALID_SCANLINE_ORDERING        equ     0C0262352H
ERROR_GRAPHICS_TOPOLOGY_CHANGES_NOT_ALLOWED     equ     0C0262353H
ERROR_GRAPHICS_NO_AVAILABLE_IMPORTANCE_ORDINALS equ     0C0262354H
ERROR_GRAPHICS_INCOMPATIBLE_PRIVATE_FORMAT      equ     0C0262355H
ERROR_GRAPHICS_INVALID_MODE_PRUNING_ALGORITHM   equ     0C0262356H
ERROR_GRAPHICS_INVALID_MONITOR_CAPABILITY_ORIGIN equ    0C0262357H
ERROR_GRAPHICS_INVALID_MONITOR_FREQUENCYRANGE_CONSTRAINT equ 0C0262358H
ERROR_GRAPHICS_MAX_NUM_PATHS_REACHED            equ     0C0262359H
ERROR_GRAPHICS_CANCEL_VIDPN_TOPOLOGY_AUGMENTATION equ   0C026235AH
ERROR_GRAPHICS_INVALID_CLIENT_TYPE              equ     0C026235BH
ERROR_GRAPHICS_CLIENTVIDPN_NOT_SET              equ     0C026235CH
ERROR_GRAPHICS_SPECIFIED_CHILD_ALREADY_CONNECTED equ    0C0262400H
ERROR_GRAPHICS_CHILD_DESCRIPTOR_NOT_SUPPORTED   equ     0C0262401H
ERROR_GRAPHICS_UNKNOWN_CHILD_STATUS             equ     04026242FH
ERROR_GRAPHICS_NOT_A_LINKED_ADAPTER             equ     0C0262430H
ERROR_GRAPHICS_LEADLINK_NOT_ENUMERATED          equ     0C0262431H
ERROR_GRAPHICS_CHAINLINKS_NOT_ENUMERATED        equ     0C0262432H
ERROR_GRAPHICS_ADAPTER_CHAIN_NOT_READY          equ     0C0262433H
ERROR_GRAPHICS_CHAINLINKS_NOT_STARTED           equ     0C0262434H
ERROR_GRAPHICS_CHAINLINKS_NOT_POWERED_ON        equ     0C0262435H
ERROR_GRAPHICS_INCONSISTENT_DEVICE_LINK_STATE   equ     0C0262436H
ERROR_GRAPHICS_LEADLINK_START_DEFERRED          equ     040262437H
ERROR_GRAPHICS_NOT_POST_DEVICE_DRIVER           equ     0C0262438H
ERROR_GRAPHICS_POLLING_TOO_FREQUENTLY           equ     040262439H
ERROR_GRAPHICS_START_DEFERRED                   equ     04026243AH
ERROR_GRAPHICS_ADAPTER_ACCESS_NOT_EXCLUDED      equ     0C026243BH
ERROR_GRAPHICS_OPM_NOT_SUPPORTED                equ     0C0262500H
ERROR_GRAPHICS_COPP_NOT_SUPPORTED               equ     0C0262501H
ERROR_GRAPHICS_UAB_NOT_SUPPORTED                equ     0C0262502H
ERROR_GRAPHICS_OPM_INVALID_ENCRYPTED_PARAMETERS equ     0C0262503H
ERROR_GRAPHICS_OPM_NO_VIDEO_OUTPUTS_EXIST       equ     0C0262505H
ERROR_GRAPHICS_OPM_INTERNAL_ERROR               equ     0C026250BH
ERROR_GRAPHICS_OPM_INVALID_HANDLE               equ     0C026250CH
ERROR_GRAPHICS_PVP_INVALID_CERTIFICATE_LENGTH   equ     0C026250EH
ERROR_GRAPHICS_OPM_SPANNING_MODE_ENABLED        equ     0C026250FH
ERROR_GRAPHICS_OPM_THEATER_MODE_ENABLED         equ     0C0262510H
ERROR_GRAPHICS_PVP_HFS_FAILED                   equ     0C0262511H
ERROR_GRAPHICS_OPM_INVALID_SRM                  equ     0C0262512H
ERROR_GRAPHICS_OPM_OUTPUT_DOES_NOT_SUPPORT_HDCP equ     0C0262513H
ERROR_GRAPHICS_OPM_OUTPUT_DOES_NOT_SUPPORT_ACP  equ     0C0262514H
ERROR_GRAPHICS_OPM_OUTPUT_DOES_NOT_SUPPORT_CGMSA equ    0C0262515H
ERROR_GRAPHICS_OPM_HDCP_SRM_NEVER_SET           equ     0C0262516H
ERROR_GRAPHICS_OPM_RESOLUTION_TOO_HIGH          equ     0C0262517H
ERROR_GRAPHICS_OPM_ALL_HDCP_HARDWARE_ALREADY_IN_USE equ 0C0262518H
ERROR_GRAPHICS_OPM_VIDEO_OUTPUT_NO_LONGER_EXISTS equ    0C026251AH
ERROR_GRAPHICS_OPM_SESSION_TYPE_CHANGE_IN_PROGRESS equ  0C026251BH
ERROR_GRAPHICS_OPM_VIDEO_OUTPUT_DOES_NOT_HAVE_COPP_SEMANTICS equ 0C026251CH
ERROR_GRAPHICS_OPM_INVALID_INFORMATION_REQUEST  equ     0C026251DH
ERROR_GRAPHICS_OPM_DRIVER_INTERNAL_ERROR        equ     0C026251EH
ERROR_GRAPHICS_OPM_VIDEO_OUTPUT_DOES_NOT_HAVE_OPM_SEMANTICS equ 0C026251FH
ERROR_GRAPHICS_OPM_SIGNALING_NOT_SUPPORTED      equ     0C0262520H
ERROR_GRAPHICS_OPM_INVALID_CONFIGURATION_REQUEST equ    0C0262521H
ERROR_GRAPHICS_I2C_NOT_SUPPORTED                equ     0C0262580H
ERROR_GRAPHICS_I2C_DEVICE_DOES_NOT_EXIST        equ     0C0262581H
ERROR_GRAPHICS_I2C_ERROR_TRANSMITTING_DATA      equ     0C0262582H
ERROR_GRAPHICS_I2C_ERROR_RECEIVING_DATA         equ     0C0262583H
ERROR_GRAPHICS_DDCCI_VCP_NOT_SUPPORTED          equ     0C0262584H
ERROR_GRAPHICS_DDCCI_INVALID_DATA               equ     0C0262585H
ERROR_GRAPHICS_DDCCI_MONITOR_RETURNED_INVALID_TIMING_STATUS_BYTE equ 0C0262586H
ERROR_GRAPHICS_MCA_INVALID_CAPABILITIES_STRING  equ     0C0262587H
ERROR_GRAPHICS_MCA_INTERNAL_ERROR               equ     0C0262588H
ERROR_GRAPHICS_DDCCI_INVALID_MESSAGE_COMMAND    equ     0C0262589H
ERROR_GRAPHICS_DDCCI_INVALID_MESSAGE_LENGTH     equ     0C026258AH
ERROR_GRAPHICS_DDCCI_INVALID_MESSAGE_CHECKSUM   equ     0C026258BH
ERROR_GRAPHICS_INVALID_PHYSICAL_MONITOR_HANDLE  equ     0C026258CH
ERROR_GRAPHICS_MONITOR_NO_LONGER_EXISTS         equ     0C026258DH
ERROR_GRAPHICS_DDCCI_CURRENT_CURRENT_VALUE_GREATER_THAN_MAXIMUM_VALUE equ 0C02625D8H
ERROR_GRAPHICS_MCA_INVALID_VCP_VERSION          equ     0C02625D9H
ERROR_GRAPHICS_MCA_MONITOR_VIOLATES_MCCS_SPECIFICATION equ 0C02625DAH
ERROR_GRAPHICS_MCA_MCCS_VERSION_MISMATCH        equ     0C02625DBH
ERROR_GRAPHICS_MCA_UNSUPPORTED_MCCS_VERSION     equ     0C02625DCH
ERROR_GRAPHICS_MCA_INVALID_TECHNOLOGY_TYPE_RETURNED equ 0C02625DEH
ERROR_GRAPHICS_MCA_UNSUPPORTED_COLOR_TEMPERATURE equ    0C02625DFH
ERROR_GRAPHICS_ONLY_CONSOLE_SESSION_SUPPORTED   equ     0C02625E0H
ERROR_GRAPHICS_NO_DISPLAY_DEVICE_CORRESPONDS_TO_NAME equ 0C02625E1H
ERROR_GRAPHICS_DISPLAY_DEVICE_NOT_ATTACHED_TO_DESKTOP equ 0C02625E2H
ERROR_GRAPHICS_MIRRORING_DEVICES_NOT_SUPPORTED  equ     0C02625E3H
ERROR_GRAPHICS_INVALID_POINTER                  equ     0C02625E4H
ERROR_GRAPHICS_NO_MONITORS_CORRESPOND_TO_DISPLAY_DEVICE equ 0C02625E5H
ERROR_GRAPHICS_PARAMETER_ARRAY_TOO_SMALL        equ     0C02625E6H
ERROR_GRAPHICS_INTERNAL_ERROR                   equ     0C02625E7H
ERROR_GRAPHICS_SESSION_TYPE_CHANGE_IN_PROGRESS  equ     0C02605E8H

TPM_E_ERROR_MASK                                equ     80280000H
TPM_E_AUTHFAIL                                  equ     80280001H
TPM_E_BADINDEX                                  equ     80280002H
TPM_E_BAD_PARAMETER                             equ     80280003H
TPM_E_AUDITFAILURE                              equ     80280004H
TPM_E_CLEAR_DISABLED                            equ     80280005H
TPM_E_DEACTIVATED                               equ     80280006H
TPM_E_DISABLED                                  equ     80280007H
TPM_E_DISABLED_CMD                              equ     80280008H
TPM_E_FAIL                                      equ     80280009H
TPM_E_BAD_ORDINAL                               equ     8028000AH
TPM_E_INSTALL_DISABLED                          equ     8028000BH
TPM_E_INVALID_KEYHANDLE                         equ     8028000CH
TPM_E_KEYNOTFOUND                               equ     8028000DH
TPM_E_INAPPROPRIATE_ENC                         equ     8028000EH
TPM_E_MIGRATEFAIL                               equ     8028000FH
TPM_E_INVALID_PCR_INFO                          equ     80280010H
TPM_E_NOSPACE                                   equ     80280011H
TPM_E_NOSRK                                     equ     80280012H
TPM_E_NOTSEALED_BLOB                            equ     80280013H
TPM_E_OWNER_SET                                 equ     80280014H
TPM_E_RESOURCES                                 equ     80280015H
TPM_E_SHORTRANDOM                               equ     80280016H
TPM_E_SIZE                                      equ     80280017H
TPM_E_WRONGPCRVAL                               equ     80280018H
TPM_E_BAD_PARAM_SIZE                            equ     80280019H
TPM_E_SHA_THREAD                                equ     8028001AH
TPM_E_SHA_ERROR                                 equ     8028001BH
TPM_E_FAILEDSELFTEST                            equ     8028001CH
TPM_E_AUTH2FAIL                                 equ     8028001DH
TPM_E_BADTAG                                    equ     8028001EH
TPM_E_IOERROR                                   equ     8028001FH
TPM_E_ENCRYPT_ERROR                             equ     80280020H
TPM_E_DECRYPT_ERROR                             equ     80280021H
TPM_E_INVALID_AUTHHANDLE                        equ     80280022H
TPM_E_NO_ENDORSEMENT                            equ     80280023H
TPM_E_INVALID_KEYUSAGE                          equ     80280024H
TPM_E_WRONG_ENTITYTYPE                          equ     80280025H
TPM_E_INVALID_POSTINIT                          equ     80280026H
TPM_E_INAPPROPRIATE_SIG                         equ     80280027H
TPM_E_BAD_KEY_PROPERTY                          equ     80280028H
TPM_E_BAD_MIGRATION                             equ     80280029H
TPM_E_BAD_SCHEME                                equ     8028002AH
TPM_E_BAD_DATASIZE                              equ     8028002BH
TPM_E_BAD_MODE                                  equ     8028002CH
TPM_E_BAD_PRESENCE                              equ     8028002DH
TPM_E_BAD_VERSION                               equ     8028002EH
TPM_E_NO_WRAP_TRANSPORT                         equ     8028002FH
TPM_E_AUDITFAIL_UNSUCCESSFUL                    equ     80280030H
TPM_E_AUDITFAIL_SUCCESSFUL                      equ     80280031H
TPM_E_NOTRESETABLE                              equ     80280032H
TPM_E_NOTLOCAL                                  equ     80280033H
TPM_E_BAD_TYPE                                  equ     80280034H
TPM_E_INVALID_RESOURCE                          equ     80280035H
TPM_E_NOTFIPS                                   equ     80280036H
TPM_E_INVALID_FAMILY                            equ     80280037H
TPM_E_NO_NV_PERMISSION                          equ     80280038H
TPM_E_REQUIRES_SIGN                             equ     80280039H
TPM_E_KEY_NOTSUPPORTED                          equ     8028003AH
TPM_E_AUTH_CONFLICT                             equ     8028003BH
TPM_E_AREA_LOCKED                               equ     8028003CH
TPM_E_BAD_LOCALITY                              equ     8028003DH
TPM_E_READ_ONLY                                 equ     8028003EH
TPM_E_PER_NOWRITE                               equ     8028003FH
TPM_E_FAMILYCOUNT                               equ     80280040H
TPM_E_WRITE_LOCKED                              equ     80280041H
TPM_E_BAD_ATTRIBUTES                            equ     80280042H
TPM_E_INVALID_STRUCTURE                         equ     80280043H
TPM_E_KEY_OWNER_CONTROL                         equ     80280044H
TPM_E_BAD_COUNTER                               equ     80280045H
TPM_E_NOT_FULLWRITE                             equ     80280046H
TPM_E_CONTEXT_GAP                               equ     80280047H
TPM_E_MAXNVWRITES                               equ     80280048H
TPM_E_NOOPERATOR                                equ     80280049H
TPM_E_RESOURCEMISSING                           equ     8028004AH
TPM_E_DELEGATE_LOCK                             equ     8028004BH
TPM_E_DELEGATE_FAMILY                           equ     8028004CH
TPM_E_DELEGATE_ADMIN                            equ     8028004DH
TPM_E_TRANSPORT_NOTEXCLUSIVE                    equ     8028004EH
TPM_E_OWNER_CONTROL                             equ     8028004FH
TPM_E_DAA_RESOURCES                             equ     80280050H
TPM_E_DAA_INPUT_DATA0                           equ     80280051H
TPM_E_DAA_INPUT_DATA1                           equ     80280052H
TPM_E_DAA_ISSUER_SETTINGS                       equ     80280053H
TPM_E_DAA_TPM_SETTINGS                          equ     80280054H
TPM_E_DAA_STAGE                                 equ     80280055H
TPM_E_DAA_ISSUER_VALIDITY                       equ     80280056H
TPM_E_DAA_WRONG_W                               equ     80280057H
TPM_E_BAD_HANDLE                                equ     80280058H
TPM_E_BAD_DELEGATE                              equ     80280059H
TPM_E_BADCONTEXT                                equ     8028005AH
TPM_E_TOOMANYCONTEXTS                           equ     8028005BH
TPM_E_MA_TICKET_SIGNATURE                       equ     8028005CH
TPM_E_MA_DESTINATION                            equ     8028005DH
TPM_E_MA_SOURCE                                 equ     8028005EH
TPM_E_MA_AUTHORITY                              equ     8028005FH
TPM_E_PERMANENTEK                               equ     80280061H
TPM_E_BAD_SIGNATURE                             equ     80280062H
TPM_E_NOCONTEXTSPACE                            equ     80280063H
TPM_E_COMMAND_BLOCKED                           equ     80280400H
TPM_E_INVALID_HANDLE                            equ     80280401H
TPM_E_DUPLICATE_VHANDLE                         equ     80280402H
TPM_E_EMBEDDED_COMMAND_BLOCKED                  equ     80280403H
TPM_E_EMBEDDED_COMMAND_UNSUPPORTED              equ     80280404H
TPM_E_RETRY                                     equ     80280800H
TPM_E_NEEDS_SELFTEST                            equ     80280801H
TPM_E_DOING_SELFTEST                            equ     80280802H
TPM_E_DEFEND_LOCK_RUNNING                       equ     80280803H

TBS_E_INTERNAL_ERROR                            equ     80284001H
TBS_E_BAD_PARAMETER                             equ     80284002H
TBS_E_INVALID_OUTPUT_POINTER                    equ     80284003H
TBS_E_INVALID_CONTEXT                           equ     80284004H
TBS_E_INSUFFICIENT_BUFFER                       equ     80284005H
TBS_E_IOERROR                                   equ     80284006H
TBS_E_INVALID_CONTEXT_PARAM                     equ     80284007H
TBS_E_SERVICE_NOT_RUNNING                       equ     80284008H
TBS_E_TOO_MANY_TBS_CONTEXTS                     equ     80284009H
TBS_E_TOO_MANY_RESOURCES                        equ     8028400AH
TBS_E_SERVICE_START_PENDING                     equ     8028400BH
TBS_E_PPI_NOT_SUPPORTED                         equ     8028400CH
TBS_E_COMMAND_CANCELED                          equ     8028400DH
TBS_E_BUFFER_TOO_LARGE                          equ     8028400EH
TBS_E_TPM_NOT_FOUND                             equ     8028400FH
TBS_E_SERVICE_DISABLED                          equ     80284010H
TBS_E_NO_EVENT_LOG                              equ     80284011H

TPMAPI_E_INVALID_STATE                          equ     80290100H
TPMAPI_E_NOT_ENOUGH_DATA                        equ     80290101H
TPMAPI_E_TOO_MUCH_DATA                          equ     80290102H
TPMAPI_E_INVALID_OUTPUT_POINTER                 equ     80290103H
TPMAPI_E_INVALID_PARAMETER                      equ     80290104H
TPMAPI_E_OUT_OF_MEMORY                          equ     80290105H
TPMAPI_E_BUFFER_TOO_SMALL                       equ     80290106H
TPMAPI_E_INTERNAL_ERROR                         equ     80290107H
TPMAPI_E_ACCESS_DENIED                          equ     80290108H
TPMAPI_E_AUTHORIZATION_FAILED                   equ     80290109H
TPMAPI_E_INVALID_CONTEXT_HANDLE                 equ     8029010AH
TPMAPI_E_TBS_COMMUNICATION_ERROR                equ     8029010BH
TPMAPI_E_TPM_COMMAND_ERROR                      equ     8029010CH
TPMAPI_E_MESSAGE_TOO_LARGE                      equ     8029010DH
TPMAPI_E_INVALID_ENCODING                       equ     8029010EH
TPMAPI_E_INVALID_KEY_SIZE                       equ     8029010FH
TPMAPI_E_ENCRYPTION_FAILED                      equ     80290110H
TPMAPI_E_INVALID_KEY_PARAMS                     equ     80290111H
TPMAPI_E_INVALID_MIGRATION_AUTHORIZATION_BLOB   equ     80290112H
TPMAPI_E_INVALID_PCR_INDEX                      equ     80290113H
TPMAPI_E_INVALID_DELEGATE_BLOB                  equ     80290114H
TPMAPI_E_INVALID_CONTEXT_PARAMS                 equ     80290115H
TPMAPI_E_INVALID_KEY_BLOB                       equ     80290116H
TPMAPI_E_INVALID_PCR_DATA                       equ     80290117H
TPMAPI_E_INVALID_OWNER_AUTH                     equ     80290118H
TPMAPI_E_FIPS_RNG_CHECK_FAILED                  equ     80290119H
TPMAPI_E_EMPTY_TCG_LOG                          equ     8029011AH
TPMAPI_E_INVALID_TCG_LOG_ENTRY                  equ     8029011BH
TPMAPI_E_TCG_SEPARATOR_ABSENT                   equ     8029011CH
TPMAPI_E_TCG_INVALID_DIGEST_ENTRY               equ     8029011DH

TBSIMP_E_BUFFER_TOO_SMALL                       equ     80290200H
TBSIMP_E_CLEANUP_FAILED                         equ     80290201H
TBSIMP_E_INVALID_CONTEXT_HANDLE                 equ     80290202H
TBSIMP_E_INVALID_CONTEXT_PARAM                  equ     80290203H
TBSIMP_E_TPM_ERROR                              equ     80290204H
TBSIMP_E_HASH_BAD_KEY                           equ     80290205H
TBSIMP_E_DUPLICATE_VHANDLE                      equ     80290206H
TBSIMP_E_INVALID_OUTPUT_POINTER                 equ     80290207H
TBSIMP_E_INVALID_PARAMETER                      equ     80290208H
TBSIMP_E_RPC_INIT_FAILED                        equ     80290209H
TBSIMP_E_SCHEDULER_NOT_RUNNING                  equ     8029020AH
TBSIMP_E_COMMAND_CANCELED                       equ     8029020BH
TBSIMP_E_OUT_OF_MEMORY                          equ     8029020CH
TBSIMP_E_LIST_NO_MORE_ITEMS                     equ     8029020DH
TBSIMP_E_LIST_NOT_FOUND                         equ     8029020EH
TBSIMP_E_NOT_ENOUGH_SPACE                       equ     8029020FH
TBSIMP_E_NOT_ENOUGH_TPM_CONTEXTS                equ     80290210H
TBSIMP_E_COMMAND_FAILED                         equ     80290211H
TBSIMP_E_UNKNOWN_ORDINAL                        equ     80290212H
TBSIMP_E_RESOURCE_EXPIRED                       equ     80290213H
TBSIMP_E_INVALID_RESOURCE                       equ     80290214H
TBSIMP_E_NOTHING_TO_UNLOAD                      equ     80290215H
TBSIMP_E_HASH_TABLE_FULL                        equ     80290216H
TBSIMP_E_TOO_MANY_TBS_CONTEXTS                  equ     80290217H
TBSIMP_E_TOO_MANY_RESOURCES                     equ     80290218H
TBSIMP_E_PPI_NOT_SUPPORTED                      equ     80290219H
TBSIMP_E_TPM_INCOMPATIBLE                       equ     8029021AH
TBSIMP_E_NO_EVENT_LOG                           equ     8029021BH

TPM_E_PPI_ACPI_FAILURE                          equ     80290300H
TPM_E_PPI_USER_ABORT                            equ     80290301H
TPM_E_PPI_BIOS_FAILURE                          equ     80290302H
TPM_E_PPI_NOT_SUPPORTED                         equ     80290303H

PLA_E_DCS_NOT_FOUND                             equ     80300002H
PLA_E_DCS_IN_USE                                equ     803000AAH
PLA_E_TOO_MANY_FOLDERS                          equ     80300045H
PLA_E_NO_MIN_DISK                               equ     80300070H
PLA_E_DCS_ALREADY_EXISTS                        equ     803000B7H
PLA_S_PROPERTY_IGNORED                          equ     00300100H
PLA_E_PROPERTY_CONFLICT                         equ     80300101H
PLA_E_DCS_SINGLETON_REQUIRED                    equ     80300102H
PLA_E_CREDENTIALS_REQUIRED                      equ     80300103H
PLA_E_DCS_NOT_RUNNING                           equ     80300104H
PLA_E_CONFLICT_INCL_EXCL_API                    equ     80300105H
PLA_E_NETWORK_EXE_NOT_VALID                     equ     80300106H
PLA_E_EXE_ALREADY_CONFIGURED                    equ     80300107H
PLA_E_EXE_PATH_NOT_VALID                        equ     80300108H
PLA_E_DC_ALREADY_EXISTS                         equ     80300109H
PLA_E_DCS_START_WAIT_TIMEOUT                    equ     8030010AH
PLA_E_DC_START_WAIT_TIMEOUT                     equ     8030010BH
PLA_E_REPORT_WAIT_TIMEOUT                       equ     8030010CH
PLA_E_NO_DUPLICATES                             equ     8030010DH
PLA_E_EXE_FULL_PATH_REQUIRED                    equ     8030010EH
PLA_E_INVALID_SESSION_NAME                      equ     8030010FH
PLA_E_PLA_CHANNEL_NOT_ENABLED                   equ     80300110H
PLA_E_TASKSCHED_CHANNEL_NOT_ENABLED             equ     80300111H
PLA_E_RULES_MANAGER_FAILED                      equ     80300112H
PLA_E_CABAPI_FAILURE                            equ     80300113H

FVE_E_LOCKED_VOLUME                             equ     80310000H
FVE_E_NOT_ENCRYPTED                             equ     80310001H
FVE_E_NO_TPM_BIOS                               equ     80310002H
FVE_E_NO_MBR_METRIC                             equ     80310003H
FVE_E_NO_BOOTSECTOR_METRIC                      equ     80310004H
FVE_E_NO_BOOTMGR_METRIC                         equ     80310005H
FVE_E_WRONG_BOOTMGR                             equ     80310006H
FVE_E_SECURE_KEY_REQUIRED                       equ     80310007H
FVE_E_NOT_ACTIVATED                             equ     80310008H
FVE_E_ACTION_NOT_ALLOWED                        equ     80310009H
FVE_E_AD_SCHEMA_NOT_INSTALLED                   equ     8031000AH
FVE_E_AD_INVALID_DATATYPE                       equ     8031000BH
FVE_E_AD_INVALID_DATASIZE                       equ     8031000CH
FVE_E_AD_NO_VALUES                              equ     8031000DH
FVE_E_AD_ATTR_NOT_SET                           equ     8031000EH
FVE_E_AD_GUID_NOT_FOUND                         equ     8031000FH
FVE_E_BAD_INFORMATION                           equ     80310010H
FVE_E_TOO_SMALL                                 equ     80310011H
FVE_E_SYSTEM_VOLUME                             equ     80310012H
FVE_E_FAILED_WRONG_FS                           equ     80310013H
FVE_E_BAD_PARTITION_SIZE                        equ     80310014H
FVE_E_NOT_SUPPORTED                             equ     80310015H
FVE_E_BAD_DATA                                  equ     80310016H
FVE_E_VOLUME_NOT_BOUND                          equ     80310017H
FVE_E_TPM_NOT_OWNED                             equ     80310018H
FVE_E_NOT_DATA_VOLUME                           equ     80310019H
FVE_E_AD_INSUFFICIENT_BUFFER                    equ     8031001AH
FVE_E_CONV_READ                                 equ     8031001BH
FVE_E_CONV_WRITE                                equ     8031001CH
FVE_E_KEY_REQUIRED                              equ     8031001DH
FVE_E_CLUSTERING_NOT_SUPPORTED                  equ     8031001EH
FVE_E_VOLUME_BOUND_ALREADY                      equ     8031001FH
FVE_E_OS_NOT_PROTECTED                          equ     80310020H
FVE_E_PROTECTION_DISABLED                       equ     80310021H
FVE_E_RECOVERY_KEY_REQUIRED                     equ     80310022H
FVE_E_FOREIGN_VOLUME                            equ     80310023H
FVE_E_OVERLAPPED_UPDATE                         equ     80310024H
FVE_E_TPM_SRK_AUTH_NOT_ZERO                     equ     80310025H
FVE_E_FAILED_SECTOR_SIZE                        equ     80310026H
FVE_E_FAILED_AUTHENTICATION                     equ     80310027H
FVE_E_NOT_OS_VOLUME                             equ     80310028H
FVE_E_AUTOUNLOCK_ENABLED                        equ     80310029H
FVE_E_WRONG_BOOTSECTOR                          equ     8031002AH
FVE_E_WRONG_SYSTEM_FS                           equ     8031002BH
FVE_E_POLICY_PASSWORD_REQUIRED                  equ     8031002CH
FVE_E_CANNOT_SET_FVEK_ENCRYPTED                 equ     8031002DH
FVE_E_CANNOT_ENCRYPT_NO_KEY                     equ     8031002EH
FVE_E_BOOTABLE_CDDVD                            equ     80310030H
FVE_E_PROTECTOR_EXISTS                          equ     80310031H
FVE_E_RELATIVE_PATH                             equ     80310032H
FVE_E_PROTECTOR_NOT_FOUND                       equ     80310033H
FVE_E_INVALID_KEY_FORMAT                        equ     80310034H
FVE_E_INVALID_PASSWORD_FORMAT                   equ     80310035H
FVE_E_FIPS_RNG_CHECK_FAILED                     equ     80310036H
FVE_E_FIPS_PREVENTS_RECOVERY_PASSWORD           equ     80310037H
FVE_E_FIPS_PREVENTS_EXTERNAL_KEY_EXPORT         equ     80310038H
FVE_E_NOT_DECRYPTED                             equ     80310039H
FVE_E_INVALID_PROTECTOR_TYPE                    equ     8031003AH
FVE_E_NO_PROTECTORS_TO_TEST                     equ     8031003BH
FVE_E_KEYFILE_NOT_FOUND                         equ     8031003CH
FVE_E_KEYFILE_INVALID                           equ     8031003DH
FVE_E_KEYFILE_NO_VMK                            equ     8031003EH
FVE_E_TPM_DISABLED                              equ     8031003FH
FVE_E_NOT_ALLOWED_IN_SAFE_MODE                  equ     80310040H
FVE_E_TPM_INVALID_PCR                           equ     80310041H
FVE_E_TPM_NO_VMK                                equ     80310042H
FVE_E_PIN_INVALID                               equ     80310043H
FVE_E_AUTH_INVALID_APPLICATION                  equ     80310044H
FVE_E_AUTH_INVALID_CONFIG                       equ     80310045H
FVE_E_FIPS_DISABLE_PROTECTION_NOT_ALLOWED       equ     80310046H
FVE_E_FS_NOT_EXTENDED                           equ     80310047H
FVE_E_FIRMWARE_TYPE_NOT_SUPPORTED               equ     80310048H
FVE_E_NO_LICENSE                                equ     80310049H
FVE_E_NOT_ON_STACK                              equ     8031004AH
FVE_E_FS_MOUNTED                                equ     8031004BH
FVE_E_TOKEN_NOT_IMPERSONATED                    equ     8031004CH
FVE_E_DRY_RUN_FAILED                            equ     8031004DH
FVE_E_REBOOT_REQUIRED                           equ     8031004EH
FVE_E_DEBUGGER_ENABLED                          equ     8031004FH
FVE_E_RAW_ACCESS                                equ     80310050H
FVE_E_RAW_BLOCKED                               equ     80310051H
FVE_E_BCD_APPLICATIONS_PATH_INCORRECT           equ     80310052H
FVE_E_NOT_ALLOWED_IN_VERSION                    equ     80310053H
FVE_E_NO_AUTOUNLOCK_MASTER_KEY                  equ     80310054H
FVE_E_MOR_FAILED                                equ     80310055H
FVE_E_HIDDEN_VOLUME                             equ     80310056H
FVE_E_TRANSIENT_STATE                           equ     80310057H
FVE_E_PUBKEY_NOT_ALLOWED                        equ     80310058H
FVE_E_VOLUME_HANDLE_OPEN                        equ     80310059H
FVE_E_NO_FEATURE_LICENSE                        equ     8031005AH
FVE_E_INVALID_STARTUP_OPTIONS                   equ     8031005BH
FVE_E_POLICY_RECOVERY_PASSWORD_NOT_ALLOWED      equ     8031005CH
FVE_E_POLICY_RECOVERY_PASSWORD_REQUIRED         equ     8031005DH
FVE_E_POLICY_RECOVERY_KEY_NOT_ALLOWED           equ     8031005EH
FVE_E_POLICY_RECOVERY_KEY_REQUIRED              equ     8031005FH
FVE_E_POLICY_STARTUP_PIN_NOT_ALLOWED            equ     80310060H
FVE_E_POLICY_STARTUP_PIN_REQUIRED               equ     80310061H
FVE_E_POLICY_STARTUP_KEY_NOT_ALLOWED            equ     80310062H
FVE_E_POLICY_STARTUP_KEY_REQUIRED               equ     80310063H
FVE_E_POLICY_STARTUP_PIN_KEY_NOT_ALLOWED        equ     80310064H
FVE_E_POLICY_STARTUP_PIN_KEY_REQUIRED           equ     80310065H
FVE_E_POLICY_STARTUP_TPM_NOT_ALLOWED            equ     80310066H
FVE_E_POLICY_STARTUP_TPM_REQUIRED               equ     80310067H
FVE_E_POLICY_INVALID_PIN_LENGTH                 equ     80310068H
FVE_E_KEY_PROTECTOR_NOT_SUPPORTED               equ     80310069H
FVE_E_POLICY_PASSPHRASE_NOT_ALLOWED             equ     8031006AH
FVE_E_POLICY_PASSPHRASE_REQUIRED                equ     8031006BH
FVE_E_FIPS_PREVENTS_PASSPHRASE                  equ     8031006CH
FVE_E_OS_VOLUME_PASSPHRASE_NOT_ALLOWED          equ     8031006DH
FVE_E_INVALID_BITLOCKER_OID                     equ     8031006EH
FVE_E_VOLUME_TOO_SMALL                          equ     8031006FH
FVE_E_DV_NOT_SUPPORTED_ON_FS                    equ     80310070H
FVE_E_DV_NOT_ALLOWED_BY_GP                      equ     80310071H
FVE_E_POLICY_USER_CERTIFICATE_NOT_ALLOWED       equ     80310072H
FVE_E_POLICY_USER_CERTIFICATE_REQUIRED          equ     80310073H
FVE_E_POLICY_USER_CERT_MUST_BE_HW               equ     80310074H
FVE_E_POLICY_USER_CONFIGURE_FDV_AUTOUNLOCK_NOT_ALLOWED equ 80310075H
FVE_E_POLICY_USER_CONFIGURE_RDV_AUTOUNLOCK_NOT_ALLOWED equ 80310076H
FVE_E_POLICY_USER_CONFIGURE_RDV_NOT_ALLOWED     equ     80310077H
FVE_E_POLICY_USER_ENABLE_RDV_NOT_ALLOWED        equ     80310078H
FVE_E_POLICY_USER_DISABLE_RDV_NOT_ALLOWED       equ     80310079H
FVE_E_POLICY_INVALID_PASSPHRASE_LENGTH          equ     80310080H
FVE_E_POLICY_PASSPHRASE_TOO_SIMPLE              equ     80310081H
FVE_E_RECOVERY_PARTITION                        equ     80310082H
FVE_E_POLICY_CONFLICT_FDV_RK_OFF_AUK_ON         equ     80310083H
FVE_E_POLICY_CONFLICT_RDV_RK_OFF_AUK_ON         equ     80310084H
FVE_E_NON_BITLOCKER_OID                         equ     80310085H
FVE_E_POLICY_PROHIBITS_SELFSIGNED               equ     80310086H
FVE_E_POLICY_CONFLICT_RO_AND_STARTUP_KEY_REQUIRED equ   80310087H
FVE_E_CONV_RECOVERY_FAILED                      equ     80310088H
FVE_E_VIRTUALIZED_SPACE_TOO_BIG                 equ     80310089H
FVE_E_POLICY_CONFLICT_OSV_RP_OFF_ADB_ON         equ     80310090H
FVE_E_POLICY_CONFLICT_FDV_RP_OFF_ADB_ON         equ     80310091H
FVE_E_POLICY_CONFLICT_RDV_RP_OFF_ADB_ON         equ     80310092H
FVE_E_NON_BITLOCKER_KU                          equ     80310093H
FVE_E_PRIVATEKEY_AUTH_FAILED                    equ     80310094H
FVE_E_REMOVAL_OF_DRA_FAILED                     equ     80310095H
FVE_E_OPERATION_NOT_SUPPORTED_ON_VISTA_VOLUME   equ     80310096H
FVE_E_CANT_LOCK_AUTOUNLOCK_ENABLED_VOLUME       equ     80310097H
FVE_E_FIPS_HASH_KDF_NOT_ALLOWED                 equ     80310098H
FVE_E_ENH_PIN_INVALID                           equ     80310099H
FVE_E_INVALID_PIN_CHARS                         equ     8031009AH
FVE_E_INVALID_DATUM_TYPE                        equ     8031009BH

FWP_E_CALLOUT_NOT_FOUND                         equ     80320001H
FWP_E_CONDITION_NOT_FOUND                       equ     80320002H
FWP_E_FILTER_NOT_FOUND                          equ     80320003H
FWP_E_LAYER_NOT_FOUND                           equ     80320004H
FWP_E_PROVIDER_NOT_FOUND                        equ     80320005H
FWP_E_PROVIDER_CONTEXT_NOT_FOUND                equ     80320006H
FWP_E_SUBLAYER_NOT_FOUND                        equ     80320007H
FWP_E_NOT_FOUND                                 equ     80320008H
FWP_E_ALREADY_EXISTS                            equ     80320009H
FWP_E_IN_USE                                    equ     8032000AH
FWP_E_DYNAMIC_SESSION_IN_PROGRESS               equ     8032000BH
FWP_E_WRONG_SESSION                             equ     8032000CH
FWP_E_NO_TXN_IN_PROGRESS                        equ     8032000DH
FWP_E_TXN_IN_PROGRESS                           equ     8032000EH
FWP_E_TXN_ABORTED                               equ     8032000FH
FWP_E_SESSION_ABORTED                           equ     80320010H
FWP_E_INCOMPATIBLE_TXN                          equ     80320011H
FWP_E_TIMEOUT                                   equ     80320012H
FWP_E_NET_EVENTS_DISABLED                       equ     80320013H
FWP_E_INCOMPATIBLE_LAYER                        equ     80320014H
FWP_E_KM_CLIENTS_ONLY                           equ     80320015H
FWP_E_LIFETIME_MISMATCH                         equ     80320016H
FWP_E_BUILTIN_OBJECT                            equ     80320017H
FWP_E_TOO_MANY_CALLOUTS                         equ     80320018H
FWP_E_NOTIFICATION_DROPPED                      equ     80320019H
FWP_E_TRAFFIC_MISMATCH                          equ     8032001AH
FWP_E_INCOMPATIBLE_SA_STATE                     equ     8032001BH
FWP_E_NULL_POINTER                              equ     8032001CH
FWP_E_INVALID_ENUMERATOR                        equ     8032001DH
FWP_E_INVALID_FLAGS                             equ     8032001EH
FWP_E_INVALID_NET_MASK                          equ     8032001FH
FWP_E_INVALID_RANGE                             equ     80320020H
FWP_E_INVALID_INTERVAL                          equ     80320021H
FWP_E_ZERO_LENGTH_ARRAY                         equ     80320022H
FWP_E_NULL_DISPLAY_NAME                         equ     80320023H
FWP_E_INVALID_ACTION_TYPE                       equ     80320024H
FWP_E_INVALID_WEIGHT                            equ     80320025H
FWP_E_MATCH_TYPE_MISMATCH                       equ     80320026H
FWP_E_TYPE_MISMATCH                             equ     80320027H
FWP_E_OUT_OF_BOUNDS                             equ     80320028H
FWP_E_RESERVED                                  equ     80320029H
FWP_E_DUPLICATE_CONDITION                       equ     8032002AH
FWP_E_DUPLICATE_KEYMOD                          equ     8032002BH
FWP_E_ACTION_INCOMPATIBLE_WITH_LAYER            equ     8032002CH
FWP_E_ACTION_INCOMPATIBLE_WITH_SUBLAYER         equ     8032002DH
FWP_E_CONTEXT_INCOMPATIBLE_WITH_LAYER           equ     8032002EH
FWP_E_CONTEXT_INCOMPATIBLE_WITH_CALLOUT         equ     8032002FH
FWP_E_INCOMPATIBLE_AUTH_METHOD                  equ     80320030H
FWP_E_INCOMPATIBLE_DH_GROUP                     equ     80320031H
FWP_E_EM_NOT_SUPPORTED                          equ     80320032H
FWP_E_NEVER_MATCH                               equ     80320033H
FWP_E_PROVIDER_CONTEXT_MISMATCH                 equ     80320034H
FWP_E_INVALID_PARAMETER                         equ     80320035H
FWP_E_TOO_MANY_SUBLAYERS                        equ     80320036H
FWP_E_CALLOUT_NOTIFICATION_FAILED               equ     80320037H
FWP_E_INVALID_AUTH_TRANSFORM                    equ     80320038H
FWP_E_INVALID_CIPHER_TRANSFORM                  equ     80320039H
FWP_E_DROP_NOICMP                               equ     80320104H
FWP_E_INCOMPATIBLE_CIPHER_TRANSFORM             equ     8032003AH
FWP_E_INVALID_TRANSFORM_COMBINATION             equ     8032003BH
FWP_E_DUPLICATE_AUTH_METHOD                     equ     8032003CH

WS_S_ASYNC                                      equ     003D0000H
WS_S_END                                        equ     003D0001H
WS_E_INVALID_FORMAT                             equ     803D0000H
WS_E_OBJECT_FAULTED                             equ     803D0001H
WS_E_NUMERIC_OVERFLOW                           equ     803D0002H
WS_E_INVALID_OPERATION                          equ     803D0003H
WS_E_OPERATION_ABORTED                          equ     803D0004H
WS_E_ENDPOINT_ACCESS_DENIED                     equ     803D0005H
WS_E_OPERATION_TIMED_OUT                        equ     803D0006H
WS_E_OPERATION_ABANDONED                        equ     803D0007H
WS_E_QUOTA_EXCEEDED                             equ     803D0008H
WS_E_NO_TRANSLATION_AVAILABLE                   equ     803D0009H
WS_E_SECURITY_VERIFICATION_FAILURE              equ     803D000AH
WS_E_ADDRESS_IN_USE                             equ     803D000BH
WS_E_ADDRESS_NOT_AVAILABLE                      equ     803D000CH
WS_E_ENDPOINT_NOT_FOUND                         equ     803D000DH
WS_E_ENDPOINT_NOT_AVAILABLE                     equ     803D000EH
WS_E_ENDPOINT_FAILURE                           equ     803D000FH
WS_E_ENDPOINT_UNREACHABLE                       equ     803D0010H
WS_E_ENDPOINT_ACTION_NOT_SUPPORTED              equ     803D0011H
WS_E_ENDPOINT_TOO_BUSY                          equ     803D0012H
WS_E_ENDPOINT_FAULT_RECEIVED                    equ     803D0013H
WS_E_ENDPOINT_DISCONNECTED                      equ     803D0014H
WS_E_PROXY_FAILURE                              equ     803D0015H
WS_E_PROXY_ACCESS_DENIED                        equ     803D0016H
WS_E_NOT_SUPPORTED                              equ     803D0017H
WS_E_PROXY_REQUIRES_BASIC_AUTH                  equ     803D0018H
WS_E_PROXY_REQUIRES_DIGEST_AUTH                 equ     803D0019H
WS_E_PROXY_REQUIRES_NTLM_AUTH                   equ     803D001AH
WS_E_PROXY_REQUIRES_NEGOTIATE_AUTH              equ     803D001BH
WS_E_SERVER_REQUIRES_BASIC_AUTH                 equ     803D001CH
WS_E_SERVER_REQUIRES_DIGEST_AUTH                equ     803D001DH
WS_E_SERVER_REQUIRES_NTLM_AUTH                  equ     803D001EH
WS_E_SERVER_REQUIRES_NEGOTIATE_AUTH             equ     803D001FH
WS_E_INVALID_ENDPOINT_URL                       equ     803D0020H
WS_E_OTHER                                      equ     803D0021H
WS_E_SECURITY_TOKEN_EXPIRED                     equ     803D0022H
WS_E_SECURITY_SYSTEM_FAILURE                    equ     803D0023H

ERROR_NDIS_INTERFACE_CLOSING                    equ     080340002H
ERROR_NDIS_BAD_VERSION                          equ     080340004H
ERROR_NDIS_BAD_CHARACTERISTICS                  equ     080340005H
ERROR_NDIS_ADAPTER_NOT_FOUND                    equ     080340006H
ERROR_NDIS_OPEN_FAILED                          equ     080340007H
ERROR_NDIS_DEVICE_FAILED                        equ     080340008H
ERROR_NDIS_MULTICAST_FULL                       equ     080340009H
ERROR_NDIS_MULTICAST_EXISTS                     equ     08034000AH
ERROR_NDIS_MULTICAST_NOT_FOUND                  equ     08034000BH
ERROR_NDIS_REQUEST_ABORTED                      equ     08034000CH
ERROR_NDIS_RESET_IN_PROGRESS                    equ     08034000DH
ERROR_NDIS_NOT_SUPPORTED                        equ     0803400BBH
ERROR_NDIS_INVALID_PACKET                       equ     08034000FH
ERROR_NDIS_ADAPTER_NOT_READY                    equ     080340011H
ERROR_NDIS_INVALID_LENGTH                       equ     080340014H
ERROR_NDIS_INVALID_DATA                         equ     080340015H
ERROR_NDIS_BUFFER_TOO_SHORT                     equ     080340016H
ERROR_NDIS_INVALID_OID                          equ     080340017H
ERROR_NDIS_ADAPTER_REMOVED                      equ     080340018H
ERROR_NDIS_UNSUPPORTED_MEDIA                    equ     080340019H
ERROR_NDIS_GROUP_ADDRESS_IN_USE                 equ     08034001AH
ERROR_NDIS_FILE_NOT_FOUND                       equ     08034001BH
ERROR_NDIS_ERROR_READING_FILE                   equ     08034001CH
ERROR_NDIS_ALREADY_MAPPED                       equ     08034001DH
ERROR_NDIS_RESOURCE_CONFLICT                    equ     08034001EH
ERROR_NDIS_MEDIA_DISCONNECTED                   equ     08034001FH
ERROR_NDIS_INVALID_ADDRESS                      equ     080340022H
ERROR_NDIS_INVALID_DEVICE_REQUEST               equ     080340010H
ERROR_NDIS_PAUSED                               equ     08034002AH
ERROR_NDIS_INTERFACE_NOT_FOUND                  equ     08034002BH
ERROR_NDIS_UNSUPPORTED_REVISION                 equ     08034002CH
ERROR_NDIS_INVALID_PORT                         equ     08034002DH
ERROR_NDIS_INVALID_PORT_STATE                   equ     08034002EH
ERROR_NDIS_LOW_POWER_STATE                      equ     08034002FH
ERROR_NDIS_DOT11_AUTO_CONFIG_ENABLED            equ     080342000H
ERROR_NDIS_DOT11_MEDIA_IN_USE                   equ     080342001H
ERROR_NDIS_DOT11_POWER_STATE_INVALID            equ     080342002H
ERROR_NDIS_PM_WOL_PATTERN_LIST_FULL             equ     080342003H
ERROR_NDIS_PM_PROTOCOL_OFFLOAD_LIST_FULL        equ     080342004H
ERROR_NDIS_INDICATION_REQUIRED                  equ     000340001H
ERROR_NDIS_OFFLOAD_POLICY                       equ     0C034100FH
ERROR_NDIS_OFFLOAD_CONNECTION_REJECTED          equ     0C0341012H
ERROR_NDIS_OFFLOAD_PATH_REJECTED                equ     0C0341013H

ERROR_HV_INVALID_HYPERCALL_CODE                 equ     0C0350002H
ERROR_HV_INVALID_HYPERCALL_INPUT                equ     0C0350003H
ERROR_HV_INVALID_ALIGNMENT                      equ     0C0350004H
ERROR_HV_INVALID_PARAMETER                      equ     0C0350005H
ERROR_HV_ACCESS_DENIED                          equ     0C0350006H
ERROR_HV_INVALID_PARTITION_STATE                equ     0C0350007H
ERROR_HV_OPERATION_DENIED                       equ     0C0350008H
ERROR_HV_UNKNOWN_PROPERTY                       equ     0C0350009H
ERROR_HV_PROPERTY_VALUE_OUT_OF_RANGE            equ     0C035000AH
ERROR_HV_INSUFFICIENT_MEMORY                    equ     0C035000BH
ERROR_HV_PARTITION_TOO_DEEP                     equ     0C035000CH
ERROR_HV_INVALID_PARTITION_ID                   equ     0C035000DH
ERROR_HV_INVALID_VP_INDEX                       equ     0C035000EH
ERROR_HV_INVALID_PORT_ID                        equ     0C0350011H
ERROR_HV_INVALID_CONNECTION_ID                  equ     0C0350012H
ERROR_HV_INSUFFICIENT_BUFFERS                   equ     0C0350013H
ERROR_HV_NOT_ACKNOWLEDGED                       equ     0C0350014H
ERROR_HV_ACKNOWLEDGED                           equ     0C0350016H
ERROR_HV_INVALID_SAVE_RESTORE_STATE             equ     0C0350017H
ERROR_HV_INVALID_SYNIC_STATE                    equ     0C0350018H
ERROR_HV_OBJECT_IN_USE                          equ     0C0350019H
ERROR_HV_INVALID_PROXIMITY_DOMAIN_INFO          equ     0C035001AH
ERROR_HV_NO_DATA                                equ     0C035001BH
ERROR_HV_INACTIVE                               equ     0C035001CH
ERROR_HV_NO_RESOURCES                           equ     0C035001DH
ERROR_HV_FEATURE_UNAVAILABLE                    equ     0C035001EH
ERROR_HV_NOT_PRESENT                            equ     0C0351000H

ERROR_VID_DUPLICATE_HANDLER                     equ     0C0370001H
ERROR_VID_TOO_MANY_HANDLERS                     equ     0C0370002H
ERROR_VID_QUEUE_FULL                            equ     0C0370003H
ERROR_VID_HANDLER_NOT_PRESENT                   equ     0C0370004H
ERROR_VID_INVALID_OBJECT_NAME                   equ     0C0370005H
ERROR_VID_PARTITION_NAME_TOO_LONG               equ     0C0370006H
ERROR_VID_MESSAGE_QUEUE_NAME_TOO_LONG           equ     0C0370007H
ERROR_VID_PARTITION_ALREADY_EXISTS              equ     0C0370008H
ERROR_VID_PARTITION_DOES_NOT_EXIST              equ     0C0370009H
ERROR_VID_PARTITION_NAME_NOT_FOUND              equ     0C037000AH
ERROR_VID_MESSAGE_QUEUE_ALREADY_EXISTS          equ     0C037000BH
ERROR_VID_EXCEEDED_MBP_ENTRY_MAP_LIMIT          equ     0C037000CH
ERROR_VID_MB_STILL_REFERENCED                   equ     0C037000DH
ERROR_VID_CHILD_GPA_PAGE_SET_CORRUPTED          equ     0C037000EH
ERROR_VID_INVALID_NUMA_SETTINGS                 equ     0C037000FH
ERROR_VID_INVALID_NUMA_NODE_INDEX               equ     0C0370010H
ERROR_VID_NOTIFICATION_QUEUE_ALREADY_ASSOCIATED equ     0C0370011H
ERROR_VID_INVALID_MEMORY_BLOCK_HANDLE           equ     0C0370012H
ERROR_VID_PAGE_RANGE_OVERFLOW                   equ     0C0370013H
ERROR_VID_INVALID_MESSAGE_QUEUE_HANDLE          equ     0C0370014H
ERROR_VID_INVALID_GPA_RANGE_HANDLE              equ     0C0370015H
ERROR_VID_NO_MEMORY_BLOCK_NOTIFICATION_QUEUE    equ     0C0370016H
ERROR_VID_MEMORY_BLOCK_LOCK_COUNT_EXCEEDED      equ     0C0370017H
ERROR_VID_INVALID_PPM_HANDLE                    equ     0C0370018H
ERROR_VID_MBPS_ARE_LOCKED                       equ     0C0370019H
ERROR_VID_MESSAGE_QUEUE_CLOSED                  equ     0C037001AH
ERROR_VID_VIRTUAL_PROCESSOR_LIMIT_EXCEEDED      equ     0C037001BH
ERROR_VID_STOP_PENDING                          equ     0C037001CH
ERROR_VID_INVALID_PROCESSOR_STATE               equ     0C037001DH
ERROR_VID_EXCEEDED_KM_CONTEXT_COUNT_LIMIT       equ     0C037001EH
ERROR_VID_KM_INTERFACE_ALREADY_INITIALIZED      equ     0C037001FH
ERROR_VID_MB_PROPERTY_ALREADY_SET_RESET         equ     0C0370020H
ERROR_VID_MMIO_RANGE_DESTROYED                  equ     0C0370021H
ERROR_VID_INVALID_CHILD_GPA_PAGE_SET            equ     0C0370022H
ERROR_VID_RESERVE_PAGE_SET_IS_BEING_USED        equ     0C0370023H
ERROR_VID_RESERVE_PAGE_SET_TOO_SMALL            equ     0C0370024H
ERROR_VID_MBP_ALREADY_LOCKED_USING_RESERVED_PAGE equ    0C0370025H
ERROR_VID_MBP_COUNT_EXCEEDED_LIMIT              equ     0C0370026H
ERROR_VID_SAVED_STATE_CORRUPT                   equ     0C0370027H
ERROR_VID_SAVED_STATE_UNRECOGNIZED_ITEM         equ     0C0370028H
ERROR_VID_SAVED_STATE_INCOMPATIBLE              equ     0C0370029H
ERROR_VID_REMOTE_NODE_PARENT_GPA_PAGES_USED     equ     080370001H

ERROR_VOLMGR_INCOMPLETE_REGENERATION            equ     080380001H
ERROR_VOLMGR_INCOMPLETE_DISK_MIGRATION          equ     080380002H
ERROR_VOLMGR_DATABASE_FULL                      equ     0C0380001H
ERROR_VOLMGR_DISK_CONFIGURATION_CORRUPTED       equ     0C0380002H
ERROR_VOLMGR_DISK_CONFIGURATION_NOT_IN_SYNC     equ     0C0380003H
ERROR_VOLMGR_PACK_CONFIG_UPDATE_FAILED          equ     0C0380004H
ERROR_VOLMGR_DISK_CONTAINS_NON_SIMPLE_VOLUME    equ     0C0380005H
ERROR_VOLMGR_DISK_DUPLICATE                     equ     0C0380006H
ERROR_VOLMGR_DISK_DYNAMIC                       equ     0C0380007H
ERROR_VOLMGR_DISK_ID_INVALID                    equ     0C0380008H
ERROR_VOLMGR_DISK_INVALID                       equ     0C0380009H
ERROR_VOLMGR_DISK_LAST_VOTER                    equ     0C038000AH
ERROR_VOLMGR_DISK_LAYOUT_INVALID                equ     0C038000BH
ERROR_VOLMGR_DISK_LAYOUT_NON_BASIC_BETWEEN_BASIC_PARTITIONS equ 0C038000CH
ERROR_VOLMGR_DISK_LAYOUT_NOT_CYLINDER_ALIGNED   equ     0C038000DH
ERROR_VOLMGR_DISK_LAYOUT_PARTITIONS_TOO_SMALL   equ     0C038000EH
ERROR_VOLMGR_DISK_LAYOUT_PRIMARY_BETWEEN_LOGICAL_PARTITIONS equ 0C038000FH
ERROR_VOLMGR_DISK_LAYOUT_TOO_MANY_PARTITIONS    equ     0C0380010H
ERROR_VOLMGR_DISK_MISSING                       equ     0C0380011H
ERROR_VOLMGR_DISK_NOT_EMPTY                     equ     0C0380012H
ERROR_VOLMGR_DISK_NOT_ENOUGH_SPACE              equ     0C0380013H
ERROR_VOLMGR_DISK_REVECTORING_FAILED            equ     0C0380014H
ERROR_VOLMGR_DISK_SECTOR_SIZE_INVALID           equ     0C0380015H
ERROR_VOLMGR_DISK_SET_NOT_CONTAINED             equ     0C0380016H
ERROR_VOLMGR_DISK_USED_BY_MULTIPLE_MEMBERS      equ     0C0380017H
ERROR_VOLMGR_DISK_USED_BY_MULTIPLE_PLEXES       equ     0C0380018H
ERROR_VOLMGR_DYNAMIC_DISK_NOT_SUPPORTED         equ     0C0380019H
ERROR_VOLMGR_EXTENT_ALREADY_USED                equ     0C038001AH
ERROR_VOLMGR_EXTENT_NOT_CONTIGUOUS              equ     0C038001BH
ERROR_VOLMGR_EXTENT_NOT_IN_PUBLIC_REGION        equ     0C038001CH
ERROR_VOLMGR_EXTENT_NOT_SECTOR_ALIGNED          equ     0C038001DH
ERROR_VOLMGR_EXTENT_OVERLAPS_EBR_PARTITION      equ     0C038001EH
ERROR_VOLMGR_EXTENT_VOLUME_LENGTHS_DO_NOT_MATCH equ     0C038001FH
ERROR_VOLMGR_FAULT_TOLERANT_NOT_SUPPORTED       equ     0C0380020H
ERROR_VOLMGR_INTERLEAVE_LENGTH_INVALID          equ     0C0380021H
ERROR_VOLMGR_MAXIMUM_REGISTERED_USERS           equ     0C0380022H
ERROR_VOLMGR_MEMBER_IN_SYNC                     equ     0C0380023H
ERROR_VOLMGR_MEMBER_INDEX_DUPLICATE             equ     0C0380024H
ERROR_VOLMGR_MEMBER_INDEX_INVALID               equ     0C0380025H
ERROR_VOLMGR_MEMBER_MISSING                     equ     0C0380026H
ERROR_VOLMGR_MEMBER_NOT_DETACHED                equ     0C0380027H
ERROR_VOLMGR_MEMBER_REGENERATING                equ     0C0380028H
ERROR_VOLMGR_ALL_DISKS_FAILED                   equ     0C0380029H
ERROR_VOLMGR_NO_REGISTERED_USERS                equ     0C038002AH
ERROR_VOLMGR_NO_SUCH_USER                       equ     0C038002BH
ERROR_VOLMGR_NOTIFICATION_RESET                 equ     0C038002CH
ERROR_VOLMGR_NUMBER_OF_MEMBERS_INVALID          equ     0C038002DH
ERROR_VOLMGR_NUMBER_OF_PLEXES_INVALID           equ     0C038002EH
ERROR_VOLMGR_PACK_DUPLICATE                     equ     0C038002FH
ERROR_VOLMGR_PACK_ID_INVALID                    equ     0C0380030H
ERROR_VOLMGR_PACK_INVALID                       equ     0C0380031H
ERROR_VOLMGR_PACK_NAME_INVALID                  equ     0C0380032H
ERROR_VOLMGR_PACK_OFFLINE                       equ     0C0380033H
ERROR_VOLMGR_PACK_HAS_QUORUM                    equ     0C0380034H
ERROR_VOLMGR_PACK_WITHOUT_QUORUM                equ     0C0380035H
ERROR_VOLMGR_PARTITION_STYLE_INVALID            equ     0C0380036H
ERROR_VOLMGR_PARTITION_UPDATE_FAILED            equ     0C0380037H
ERROR_VOLMGR_PLEX_IN_SYNC                       equ     0C0380038H
ERROR_VOLMGR_PLEX_INDEX_DUPLICATE               equ     0C0380039H
ERROR_VOLMGR_PLEX_INDEX_INVALID                 equ     0C038003AH
ERROR_VOLMGR_PLEX_LAST_ACTIVE                   equ     0C038003BH
ERROR_VOLMGR_PLEX_MISSING                       equ     0C038003CH
ERROR_VOLMGR_PLEX_REGENERATING                  equ     0C038003DH
ERROR_VOLMGR_PLEX_TYPE_INVALID                  equ     0C038003EH
ERROR_VOLMGR_PLEX_NOT_RAID5                     equ     0C038003FH
ERROR_VOLMGR_PLEX_NOT_SIMPLE                    equ     0C0380040H
ERROR_VOLMGR_STRUCTURE_SIZE_INVALID             equ     0C0380041H
ERROR_VOLMGR_TOO_MANY_NOTIFICATION_REQUESTS     equ     0C0380042H
ERROR_VOLMGR_TRANSACTION_IN_PROGRESS            equ     0C0380043H
ERROR_VOLMGR_UNEXPECTED_DISK_LAYOUT_CHANGE      equ     0C0380044H
ERROR_VOLMGR_VOLUME_CONTAINS_MISSING_DISK       equ     0C0380045H
ERROR_VOLMGR_VOLUME_ID_INVALID                  equ     0C0380046H
ERROR_VOLMGR_VOLUME_LENGTH_INVALID              equ     0C0380047H
ERROR_VOLMGR_VOLUME_LENGTH_NOT_SECTOR_SIZE_MULTIPLE equ 0C0380048H
ERROR_VOLMGR_VOLUME_NOT_MIRRORED                equ     0C0380049H
ERROR_VOLMGR_VOLUME_NOT_RETAINED                equ     0C038004AH
ERROR_VOLMGR_VOLUME_OFFLINE                     equ     0C038004BH
ERROR_VOLMGR_VOLUME_RETAINED                    equ     0C038004CH
ERROR_VOLMGR_NUMBER_OF_EXTENTS_INVALID          equ     0C038004DH
ERROR_VOLMGR_DIFFERENT_SECTOR_SIZE              equ     0C038004EH
ERROR_VOLMGR_BAD_BOOT_DISK                      equ     0C038004FH
ERROR_VOLMGR_PACK_CONFIG_OFFLINE                equ     0C0380050H
ERROR_VOLMGR_PACK_CONFIG_ONLINE                 equ     0C0380051H
ERROR_VOLMGR_NOT_PRIMARY_PACK                   equ     0C0380052H
ERROR_VOLMGR_PACK_LOG_UPDATE_FAILED             equ     0C0380053H
ERROR_VOLMGR_NUMBER_OF_DISKS_IN_PLEX_INVALID    equ     0C0380054H
ERROR_VOLMGR_NUMBER_OF_DISKS_IN_MEMBER_INVALID  equ     0C0380055H
ERROR_VOLMGR_VOLUME_MIRRORED                    equ     0C0380056H
ERROR_VOLMGR_PLEX_NOT_SIMPLE_SPANNED            equ     0C0380057H
ERROR_VOLMGR_NO_VALID_LOG_COPIES                equ     0C0380058H
ERROR_VOLMGR_PRIMARY_PACK_PRESENT               equ     0C0380059H
ERROR_VOLMGR_NUMBER_OF_DISKS_INVALID            equ     0C038005AH
ERROR_VOLMGR_MIRROR_NOT_SUPPORTED               equ     0C038005BH
ERROR_VOLMGR_RAID5_NOT_SUPPORTED                equ     0C038005CH

ERROR_BCD_NOT_ALL_ENTRIES_IMPORTED              equ     080390001H
ERROR_BCD_TOO_MANY_ELEMENTS                     equ     0C0390002H
ERROR_BCD_NOT_ALL_ENTRIES_SYNCHRONIZED          equ     080390003H

ERROR_VHD_DRIVE_FOOTER_MISSING                  equ     0C03A0001H
ERROR_VHD_DRIVE_FOOTER_CHECKSUM_MISMATCH        equ     0C03A0002H
ERROR_VHD_DRIVE_FOOTER_CORRUPT                  equ     0C03A0003H
ERROR_VHD_FORMAT_UNKNOWN                        equ     0C03A0004H
ERROR_VHD_FORMAT_UNSUPPORTED_VERSION            equ     0C03A0005H
ERROR_VHD_SPARSE_HEADER_CHECKSUM_MISMATCH       equ     0C03A0006H
ERROR_VHD_SPARSE_HEADER_UNSUPPORTED_VERSION     equ     0C03A0007H
ERROR_VHD_SPARSE_HEADER_CORRUPT                 equ     0C03A0008H
ERROR_VHD_BLOCK_ALLOCATION_FAILURE              equ     0C03A0009H
ERROR_VHD_BLOCK_ALLOCATION_TABLE_CORRUPT        equ     0C03A000AH
ERROR_VHD_INVALID_BLOCK_SIZE                    equ     0C03A000BH
ERROR_VHD_BITMAP_MISMATCH                       equ     0C03A000CH
ERROR_VHD_PARENT_VHD_NOT_FOUND                  equ     0C03A000DH
ERROR_VHD_CHILD_PARENT_ID_MISMATCH              equ     0C03A000EH
ERROR_VHD_CHILD_PARENT_TIMESTAMP_MISMATCH       equ     0C03A000FH
ERROR_VHD_METADATA_READ_FAILURE                 equ     0C03A0010H
ERROR_VHD_METADATA_WRITE_FAILURE                equ     0C03A0011H
ERROR_VHD_INVALID_SIZE                          equ     0C03A0012H
ERROR_VHD_INVALID_FILE_SIZE                     equ     0C03A0013H

ERROR_VIRTDISK_PROVIDER_NOT_FOUND               equ     0C03A0014H
ERROR_VIRTDISK_NOT_VIRTUAL_DISK                 equ     0C03A0015H
ERROR_VHD_PARENT_VHD_ACCESS_DENIED              equ     0C03A0016H
ERROR_VHD_CHILD_PARENT_SIZE_MISMATCH            equ     0C03A0017H
ERROR_VHD_DIFFERENCING_CHAIN_CYCLE_DETECTED     equ     0C03A0018H
ERROR_VHD_DIFFERENCING_CHAIN_ERROR_IN_PARENT    equ     0C03A0019H
ERROR_VIRTUAL_DISK_LIMITATION                   equ     0C03A001AH
ERROR_VHD_INVALID_TYPE                          equ     0C03A001BH
ERROR_VHD_INVALID_STATE                         equ     0C03A001CH
ERROR_VIRTDISK_UNSUPPORTED_DISK_SECTOR_SIZE     equ     0C03A001DH
ERROR_QUERY_STORAGE_ERROR                       equ     0803A0001H

SDIAG_E_CANCELLED                               equ     803C0100H
SDIAG_E_SCRIPT                                  equ     803C0101H
SDIAG_E_POWERSHELL                              equ     803C0102H
SDIAG_E_MANAGEDHOST                             equ     803C0103H
SDIAG_E_NOVERIFIER                              equ     803C0104H
SDIAG_S_CANNOTRUN                               equ     003C0105H
SDIAG_E_DISABLED                                equ     803C0106H
SDIAG_E_TRUST                                   equ     803C0107H
SDIAG_E_CANNOTRUN                               equ     803C0108H
SDIAG_E_VERSION                                 equ     803C0109H
SDIAG_E_RESOURCE                                equ     803C010AH
SDIAG_E_ROOTCAUSE                               equ     803C010BH

E_MBN_CONTEXT_NOT_ACTIVATED                     equ     80548201H
E_MBN_BAD_SIM                                   equ     80548202H
E_MBN_DATA_CLASS_NOT_AVAILABLE                  equ     80548203H
E_MBN_INVALID_ACCESS_STRING                     equ     80548204H
E_MBN_MAX_ACTIVATED_CONTEXTS                    equ     80548205H
E_MBN_PACKET_SVC_DETACHED                       equ     80548206H
E_MBN_PROVIDER_NOT_VISIBLE                      equ     80548207H
E_MBN_RADIO_POWER_OFF                           equ     80548208H
E_MBN_SERVICE_NOT_ACTIVATED                     equ     80548209H
E_MBN_SIM_NOT_INSERTED                          equ     8054820AH
E_MBN_VOICE_CALL_IN_PROGRESS                    equ     8054820BH
E_MBN_INVALID_CACHE                             equ     8054820CH
E_MBN_NOT_REGISTERED                            equ     8054820DH
E_MBN_PROVIDERS_NOT_FOUND                       equ     8054820EH
E_MBN_PIN_NOT_SUPPORTED                         equ     8054820FH
E_MBN_PIN_REQUIRED                              equ     80548210H
E_MBN_PIN_DISABLED                              equ     80548211H
E_MBN_FAILURE                                   equ     80548212H
E_MBN_INVALID_PROFILE                           equ     80548218H
E_MBN_DEFAULT_PROFILE_EXIST                     equ     80548219H
E_MBN_SMS_ENCODING_NOT_SUPPORTED                equ     80548220H
E_MBN_SMS_FILTER_NOT_SUPPORTED                  equ     80548221H
E_MBN_SMS_INVALID_MEMORY_INDEX                  equ     80548222H
E_MBN_SMS_LANG_NOT_SUPPORTED                    equ     80548223H
E_MBN_SMS_MEMORY_FAILURE                        equ     80548224H
E_MBN_SMS_NETWORK_TIMEOUT                       equ     80548225H
E_MBN_SMS_UNKNOWN_SMSC_ADDRESS                  equ     80548226H
E_MBN_SMS_FORMAT_NOT_SUPPORTED                  equ     80548227H
E_MBN_SMS_OPERATION_NOT_ALLOWED                 equ     80548228H
E_MBN_SMS_MEMORY_FULL                           equ     80548229H

UI_E_CREATE_FAILED                              equ     802A0001H
UI_E_SHUTDOWN_CALLED                            equ     802A0002H
UI_E_ILLEGAL_REENTRANCY                         equ     802A0003H
UI_E_OBJECT_SEALED                              equ     802A0004H
UI_E_VALUE_NOT_SET                              equ     802A0005H
UI_E_VALUE_NOT_DETERMINED                       equ     802A0006H
UI_E_INVALID_OUTPUT                             equ     802A0007H
UI_E_BOOLEAN_EXPECTED                           equ     802A0008H
UI_E_DIFFERENT_OWNER                            equ     802A0009H
UI_E_AMBIGUOUS_MATCH                            equ     802A000AH
UI_E_FP_OVERFLOW                                equ     802A000BH
UI_E_WRONG_THREAD                               equ     802A000CH
UI_E_STORYBOARD_ACTIVE                          equ     802A0101H
UI_E_STORYBOARD_NOT_PLAYING                     equ     802A0102H
UI_E_START_KEYFRAME_AFTER_END                   equ     802A0103H
UI_E_END_KEYFRAME_NOT_DETERMINED                equ     802A0104H
UI_E_LOOPS_OVERLAP                              equ     802A0105H
UI_E_TRANSITION_ALREADY_USED                    equ     802A0106H
UI_E_TRANSITION_NOT_IN_STORYBOARD               equ     802A0107H
UI_E_TRANSITION_ECLIPSED                        equ     802A0108H
UI_E_TIME_BEFORE_LAST_UPDATE                    equ     802A0109H
UI_E_TIMER_CLIENT_ALREADY_CONNECTED             equ     802A010AH

#if NTDDI_VERSION >= NTDDI_WINNT4
    CRITICAL_SECTION_NO_DEBUG_INFO              equ     001000000H
    STARTF_USEHOTKEY                            equ     00000200H
    STARTF_TITLEISLINKNAME                      equ     00000800H
    STARTF_TITLEISAPPID                         equ     000001000H
    STARTF_PREVENTPINNING                       equ     000002000H
#endif

#if NTDDI_VERSION >= NTDDI_WIN2K
    MOVEFILE_CREATE_HARDLINK                    equ     000000010H
    MOVEFILE_FAIL_IF_NOT_TRACKABLE              equ     000000020H

    ACTCTX_FLAG_PROCESSOR_ARCHITECTURE_VALID    equ     000000001H
    ACTCTX_FLAG_LANGID_VALID                    equ     000000002H
    ACTCTX_FLAG_ASSEMBLY_DIRECTORY_VALID        equ     000000004H
    ACTCTX_FLAG_RESOURCE_NAME_VALID             equ     000000008H
    ACTCTX_FLAG_SET_PROCESS_DEFAULT             equ     000000010H
    ACTCTX_FLAG_APPLICATION_NAME_VALID          equ     000000020H
    ACTCTX_FLAG_SOURCE_IS_ASSEMBLYREF           equ     000000040H
    ACTCTX_FLAG_HMODULE_VALID                   equ     000000080H

    DEACTIVATE_ACTCTX_FLAG_FORCE_EARLY_DEACTIVATION equ 000000001H

    FIND_ACTCTX_SECTION_KEY_RETURN_HACTCTX      equ     000000001H
    FIND_ACTCTX_SECTION_KEY_RETURN_FLAGS        equ     000000002H
    FIND_ACTCTX_SECTION_KEY_RETURN_ASSEMBLY_METADATA equ 000000004H

    QUERY_ACTCTX_FLAG_USE_ACTIVE_ACTCTX         equ     000000004H
    QUERY_ACTCTX_FLAG_ACTCTX_IS_HMODULE         equ     000000008H
    QUERY_ACTCTX_FLAG_ACTCTX_IS_ADDRESS         equ     000000010H
    QUERY_ACTCTX_FLAG_NO_ADDREF                 equ     080000000H
#endif

#if NTDDI_VERSION >= NTDDI_WINXP
    FileBasicInfo                               equ     0
    FileStandardInfo                            equ     1
    FileNameInfo                                equ     2
    FileRenameInfo                              equ     3
    FileDispositionInfo                         equ     4
    FileAllocationInfo                          equ     5
    FileEndOfFileInfo                           equ     6
    FileStreamInfo                              equ     7
    FileCompressionInfo                         equ     8
    FileAttributeTagInfo                        equ     9
    FileIdBothDirectoryInfo                     equ     10
    FileIdBothDirectoryRestartInfo              equ     11
    MaximumFileInfoByHandleClass                equ     11

    #if NTDDI_VERSION == NTDDI_WINXP
        FileIdType                              equ     0
        MaximumFileIdType                       equ     1
    #else
        FileIdType                              equ     00H
        ObjectIdType                            equ     01H
        ExtendedFileIdType                      equ     02H
        MaximumFileIdType                       equ     03H
    #endif

    FIBER_FLAG_FLOAT_SWITCH                     equ     01H

    FindStreamInfoStandard                      equ     00H
    FindStreamInfoMaxInfoLevel                  equ     01H
 #endif

#if NTDDI_VERSION >= NTDDI_VISTA
    PROCESS_DEP_ENABLE                          equ     000000001H
    PROCESS_DEP_DISABLE_ATL_THUNK_EMULATION     equ     000000002H

    REMOTE_PROTOCOL_INFO_FLAG_LOOPBACK          equ     000000001H
    REMOTE_PROTOCOL_INFO_FLAG_OFFLINE           equ     000000002H

    FILE_SKIP_COMPLETION_PORT_ON_SUCCESS        equ     01H
    FILE_SKIP_SET_EVENT_ON_HANDLE               equ     02H

    PROC_THREAD_ATTRIBUTE_NUMBER                equ     00000FFFFH
    PROC_THREAD_ATTRIBUTE_THREAD                equ     000010000H
    PROC_THREAD_ATTRIBUTE_INPUT                 equ     000020000H
    PROC_THREAD_ATTRIBUTE_ADDITIVE              equ     000040000H
    PROTECTION_LEVEL_SAME                       equ     0FFFFFFFFH

    GDIREGISTERDDRAWPACKETVERSION               equ     01H

    #ifndef _USE_FULL_PROC_THREAD_ATTRIBUTE
        _USE_FULL_PROC_THREAD_ATTRIBUTE         equ     1
        ProcThreadAttributeParentProcess        equ     0
        ProcThreadAttributeHandleList           equ     2
        ProcThreadAttributeProtectionLevel      equ     11
    #endif

    IoPriorityHintVeryLow                       equ     0
    IoPriorityHintLow                           equ     01H
    IoPriorityHintNormal                        equ     02H
    MaximumIoPriorityHintType                   equ     03H

    SYMBOLIC_LINK_FLAG_DIRECTORY                equ     01H
    VALID_SYMBOLIC_LINK_FLAGS                   equ     SYMBOLIC_LINK_FLAG_DIRECTORY
#endif

#if NTDDI_VERSION >= NTDDI_WIN7
    UMS_VERSION                                 equ     RTL_UMS_VERSION
    define UMS_THREAD_INFO_CLASS                dd
    define UMS_SCHEDULER_REASON                 dd

    ProcThreadAttributeGroupAffinity            equ     3
    ProcThreadAttributePreferredNode            equ     4
    ProcThreadAttributeIdealProcessor           equ     5
    ProcThreadAttributeUmsThread                equ     6
    ProcThreadAttributeMitigationPolicy         equ     7

    PROCESS_CREATION_MITIGATION_POLICY_DEP_ENABLE equ   001H
    PROCESS_CREATION_MITIGATION_POLICY_DEP_ATL_THUNK_ENABLE equ 002H
    PROCESS_CREATION_MITIGATION_POLICY_SEHOP_ENABLE equ 004H

    COPYFILE2_CALLBACK_NONE                     equ     00H
    COPYFILE2_CALLBACK_CHUNK_STARTED            equ     01H
    COPYFILE2_CALLBACK_CHUNK_FINISHED           equ     02H
    COPYFILE2_CALLBACK_STREAM_STARTED           equ     03H
    COPYFILE2_CALLBACK_STREAM_FINISHED          equ     04H
    COPYFILE2_CALLBACK_POLL_CONTINUE            equ     05H
    COPYFILE2_CALLBACK_ERROR                    equ     06H
    COPYFILE2_CALLBACK_MAX                      equ     07H

    COPYFILE2_PROGRESS_CONTINUE                 equ     00H
    COPYFILE2_PROGRESS_CANCEL                   equ     01H
    COPYFILE2_PROGRESS_STOP                     equ     02H
    COPYFILE2_PROGRESS_QUIET                    equ     03H
    COPYFILE2_PROGRESS_PAUSE                    equ     04H

    COPYFILE2_PHASE_NONE                        equ     00H
    COPYFILE2_PHASE_PREPARE_SOURCE              equ     01H
    COPYFILE2_PHASE_PREPARE_DEST                equ     02H
    COPYFILE2_PHASE_READ_SOURCE                 equ     03H
    COPYFILE2_PHASE_WRITE_DESTINATION           equ     04H
    COPYFILE2_PHASE_SERVER_COPY                 equ     05H
    COPYFILE2_PHASE_NAMEGRAFT_COPY              equ     06H
    COPYFILE2_PHASE_MAX                         equ     07H

    COPYFILE2_MESSAGE_COPY_OFFLOAD              equ     000000001H
#endif

#if NTDDI_VERSION >= NTDDI_WIN8
    STORAGE_INFO_FLAGS_ALIGNED_DEVICE           equ     000000001H
    STORAGE_INFO_OFFSET_UNKNOWN                 equ     0FFFFFFFFH

    REMOTE_PROTOCOL_INFO_FLAG_PERSISTENT_HANDLE equ     000000004H

    RPI_FLAG_SMB2_SHARECAP_TIMEWARP             equ     000000002H
    RPI_FLAG_SMB2_SHARECAP_DFS                  equ     000000008H
    RPI_FLAG_SMB2_SHARECAP_CONTINUOUS_AVAILABILITY equ  000000010H
    RPI_FLAG_SMB2_SHARECAP_SCALEOUT             equ     000000020H
    RPI_FLAG_SMB2_SHARECAP_CLUSTER              equ     000000040H

    RPI_SMB2_FLAG_SERVERCAP_DFS                 equ     000000001H
    RPI_SMB2_FLAG_SERVERCAP_LEASING             equ     000000002H
    RPI_SMB2_FLAG_SERVERCAP_LARGEMTU            equ     000000004H
    RPI_SMB2_FLAG_SERVERCAP_MULTICHANNEL        equ     000000008H
    RPI_SMB2_FLAG_SERVERCAP_PERSISTENT_HANDLES  equ     000000010H
    RPI_SMB2_FLAG_SERVERCAP_DIRECTORY_LEASING   equ     000000020H

    ProcThreadAttributeSecurityCapabilities     equ     9

    PROCESS_CREATION_MITIGATION_POLICY_FORCE_RELOCATE_IMAGES_MASK                   equ <000000003H shl 8>
    PROCESS_CREATION_MITIGATION_POLICY_FORCE_RELOCATE_IMAGES_DEFER                  equ <000000000H shl 8>
    PROCESS_CREATION_MITIGATION_POLICY_FORCE_RELOCATE_IMAGES_ALWAYS_ON              equ <000000001H shl 8>
    PROCESS_CREATION_MITIGATION_POLICY_FORCE_RELOCATE_IMAGES_ALWAYS_OFF             equ <000000002H shl 8>
    PROCESS_CREATION_MITIGATION_POLICY_FORCE_RELOCATE_IMAGES_ALWAYS_ON_REQ_RELOCS   equ <000000003H shl 8>
    PROCESS_CREATION_MITIGATION_POLICY_HEAP_TERMINATE_MASK                          equ <000000003H shl 12>
    PROCESS_CREATION_MITIGATION_POLICY_HEAP_TERMINATE_DEFER                         equ <000000000H shl 12>
    PROCESS_CREATION_MITIGATION_POLICY_HEAP_TERMINATE_ALWAYS_ON                     equ <000000001H shl 12>
    PROCESS_CREATION_MITIGATION_POLICY_HEAP_TERMINATE_ALWAYS_OFF                    equ <000000002H shl 12>
    PROCESS_CREATION_MITIGATION_POLICY_HEAP_TERMINATE_RESERVED                      equ <000000003H shl 12>
    PROCESS_CREATION_MITIGATION_POLICY_BOTTOM_UP_ASLR_MASK                          equ <000000003H shl 16>
    PROCESS_CREATION_MITIGATION_POLICY_BOTTOM_UP_ASLR_DEFER                         equ <000000000H shl 16>
    PROCESS_CREATION_MITIGATION_POLICY_BOTTOM_UP_ASLR_ALWAYS_ON                     equ <000000001H shl 16>
    PROCESS_CREATION_MITIGATION_POLICY_BOTTOM_UP_ASLR_ALWAYS_OFF                    equ <000000002H shl 16>
    PROCESS_CREATION_MITIGATION_POLICY_BOTTOM_UP_ASLR_RESERVED                      equ <000000003H shl 16>
    PROCESS_CREATION_MITIGATION_POLICY_HIGH_ENTROPY_ASLR_MASK                       equ <000000003H shl 20>
    PROCESS_CREATION_MITIGATION_POLICY_HIGH_ENTROPY_ASLR_DEFER                      equ <000000000H shl 20>
    PROCESS_CREATION_MITIGATION_POLICY_HIGH_ENTROPY_ASLR_ALWAYS_ON                  equ <000000001H shl 20>
    PROCESS_CREATION_MITIGATION_POLICY_HIGH_ENTROPY_ASLR_ALWAYS_OFF                 equ <000000002H shl 20>
    PROCESS_CREATION_MITIGATION_POLICY_HIGH_ENTROPY_ASLR_RESERVED                   equ <000000003H shl 20>
    PROCESS_CREATION_MITIGATION_POLICY_STRICT_HANDLE_CHECKS_MASK                    equ <000000003H shl 24>
    PROCESS_CREATION_MITIGATION_POLICY_STRICT_HANDLE_CHECKS_DEFER                   equ <000000000H shl 24>
    PROCESS_CREATION_MITIGATION_POLICY_STRICT_HANDLE_CHECKS_ALWAYS_ON               equ <000000001H shl 24>
    PROCESS_CREATION_MITIGATION_POLICY_STRICT_HANDLE_CHECKS_ALWAYS_OFF              equ <000000002H shl 24>
    PROCESS_CREATION_MITIGATION_POLICY_STRICT_HANDLE_CHECKS_RESERVED                equ <000000003H shl 24>
    PROCESS_CREATION_MITIGATION_POLICY_WIN32K_SYSTEM_CALL_DISABLE_MASK              equ <000000003H shl 28>
    PROCESS_CREATION_MITIGATION_POLICY_WIN32K_SYSTEM_CALL_DISABLE_DEFER             equ <000000000H shl 28>
    PROCESS_CREATION_MITIGATION_POLICY_WIN32K_SYSTEM_CALL_DISABLE_ALWAYS_ON         equ <000000001H shl 28>
    PROCESS_CREATION_MITIGATION_POLICY_WIN32K_SYSTEM_CALL_DISABLE_ALWAYS_OFF        equ <000000002H shl 28>
    PROCESS_CREATION_MITIGATION_POLICY_WIN32K_SYSTEM_CALL_DISABLE_RESERVED          equ <000000003H shl 28>
    PROCESS_CREATION_MITIGATION_POLICY_EXTENSION_POINT_DISABLE_MASK                 equ <000000003H shl 32>
    PROCESS_CREATION_MITIGATION_POLICY_EXTENSION_POINT_DISABLE_DEFER                equ <000000000H shl 32>
    PROCESS_CREATION_MITIGATION_POLICY_EXTENSION_POINT_DISABLE_ALWAYS_ON            equ <000000001H shl 32>
    PROCESS_CREATION_MITIGATION_POLICY_EXTENSION_POINT_DISABLE_ALWAYS_OFF           equ <000000002H shl 32>
    PROCESS_CREATION_MITIGATION_POLICY_EXTENSION_POINT_DISABLE_RESERVED             equ <000000003H shl 32>
    PROCESS_CREATION_MITIGATION_POLICY_PROHIBIT_DYNAMIC_CODE_MASK                   equ <000000003H shl 36>
    PROCESS_CREATION_MITIGATION_POLICY_PROHIBIT_DYNAMIC_CODE_DEFER                  equ <000000000H shl 36>
    PROCESS_CREATION_MITIGATION_POLICY_PROHIBIT_DYNAMIC_CODE_ALWAYS_ON              equ <000000001H shl 36>
    PROCESS_CREATION_MITIGATION_POLICY_PROHIBIT_DYNAMIC_CODE_ALWAYS_OFF             equ <000000002H shl 36>
    PROCESS_CREATION_MITIGATION_POLICY_PROHIBIT_DYNAMIC_CODE_RESERVED               equ <000000003H shl 36>
    PROCESS_CREATION_MITIGATION_POLICY_BLOCK_NON_MICROSOFT_BINARIES_MASK            equ <000000003H shl 44>
    PROCESS_CREATION_MITIGATION_POLICY_BLOCK_NON_MICROSOFT_BINARIES_DEFER           equ <000000000H shl 44>
    PROCESS_CREATION_MITIGATION_POLICY_BLOCK_NON_MICROSOFT_BINARIES_ALWAYS_ON       equ <000000001H shl 44>
    PROCESS_CREATION_MITIGATION_POLICY_BLOCK_NON_MICROSOFT_BINARIES_ALWAYS_OFF      equ <000000002H shl 44>
    PROCESS_CREATION_MITIGATION_POLICY_BLOCK_NON_MICROSOFT_BINARIES_RESERVED        equ <000000003H shl 44>

    OPERATION_API_VERSION                       equ     1

    OPERATION_START_TRACE_CURRENT_THREAD        equ     01H

    OPERATION_END_DISCARD                       equ     01H
#endif

INVALID_HANDLE_VALUE                            equ     (-1)
INVALID_FILE_SIZE                               equ     0FFFFFFFFH
INVALID_SET_FILE_POINTER                        equ     (-1)
INVALID_FILE_ATTRIBUTES                         equ     (-1)

FILE_BEGIN                                      equ     0
FILE_CURRENT                                    equ     1
FILE_END                                        equ     2
TIME_ZONE_ID_INVALID                            equ     0FFFFFFFFH
WAIT_FAILED                                     equ     0FFFFFFFFH
WAIT_OBJECT_0                                   equ     0
WAIT_ABANDONED                                  equ     00000080H
WAIT_ABANDONED_0                                equ     00000080H
WAIT_IO_COMPLETION                              equ     000000C0H
STILL_ACTIVE                                    equ     00000103H

EXCEPTION_ACCESS_VIOLATION                      equ     0C0000005H
EXCEPTION_DATATYPE_MISALIGNMENT                 equ     80000002H
EXCEPTION_BREAKPOINT                            equ     80000003H
EXCEPTION_SINGLE_STEP                           equ     80000004H
EXCEPTION_ARRAY_BOUNDS_EXCEEDED                 equ     0C000008CH
EXCEPTION_FLT_DENORMAL_OPERAND                  equ     0C000008DH
EXCEPTION_FLT_DIVIDE_BY_ZERO                    equ     0C000008EH
EXCEPTION_FLT_INEXACT_RESULT                    equ     0C000008FH
EXCEPTION_FLT_INVALID_OPERATION                 equ     0C0000090H
EXCEPTION_FLT_OVERFLOW                          equ     0C0000091H
EXCEPTION_FLT_STACK_CHECK                       equ     0C0000092H
EXCEPTION_FLT_UNDERFLOW                         equ     0C0000093H
EXCEPTION_INT_DIVIDE_BY_ZERO                    equ     0C0000094H
EXCEPTION_INT_OVERFLOW                          equ     0C0000095H
EXCEPTION_PRIV_INSTRUCTION                      equ     0C0000096H
EXCEPTION_IN_PAGE_ERROR                         equ     0C0000006H
EXCEPTION_ILLEGAL_INSTRUCTION                   equ     0C000001DH
EXCEPTION_NONCONTINUABLE_EXCEPTION              equ     0C0000025H
EXCEPTION_STACK_OVERFLOW                        equ     0C00000FDH
EXCEPTION_INVALID_DISPOSITION                   equ     0C0000026H
EXCEPTION_GUARD_PAGE                            equ     080000001H
EXCEPTION_INVALID_HANDLE                        equ     0C0000008H
CONTROL_C_EXIT                                  equ     0C000013AH
EXCEPTION_POSSIBLE_DEADLOCK                     equ     STATUS_POSSIBLE_DEADLOCK

FILE_FLAG_WRITE_THROUGH                         equ     80000000H
FILE_FLAG_OVERLAPPED                            equ     40000000H
FILE_FLAG_NO_BUFFERING                          equ     20000000H
FILE_FLAG_RANDOM_ACCESS                         equ     10000000H
FILE_FLAG_SEQUENTIAL_SCAN                       equ     08000000H
FILE_FLAG_DELETE_ON_CLOSE                       equ     04000000H
FILE_FLAG_BACKUP_SEMANTICS                      equ     02000000H
FILE_FLAG_POSIX_SEMANTICS                       equ     01000000H
FILE_FLAG_OPEN_REPARSE_POINT                    equ     00200000H
FILE_FLAG_OPEN_NO_RECALL                        equ     00100000H
FILE_FLAG_FIRST_PIPE_INSTANCE                   equ     00080000H

CREATE_NEW                                      equ     1
CREATE_ALWAYS                                   equ     2
OPEN_EXISTING                                   equ     3
OPEN_ALWAYS                                     equ     4
TRUNCATE_EXISTING                               equ     5

PROGRESS_CONTINUE                               equ     0
PROGRESS_CANCEL                                 equ     1
PROGRESS_STOP                                   equ     2
PROGRESS_QUIET                                  equ     3

CALLBACK_CHUNK_FINISHED                         equ     00000000H
CALLBACK_STREAM_SWITCH                          equ     00000001H

COPY_FILE_FAIL_IF_EXISTS                        equ     00000001H
COPY_FILE_RESTARTABLE                           equ     00000002H
COPY_FILE_OPEN_SOURCE_FOR_WRITE                 equ     00000004H

REPLACEFILE_WRITE_THROUGH                       equ     00000001H
REPLACEFILE_IGNORE_MERGE_ERRORS                 equ     00000002H

PIPE_ACCESS_INBOUND                             equ     00000001H
PIPE_ACCESS_OUTBOUND                            equ     00000002H
PIPE_ACCESS_DUPLEX                              equ     00000003H

PIPE_CLIENT_END                                 equ     00000000H
PIPE_SERVER_END                                 equ     00000001H

PIPE_WAIT                                       equ     00000000H
PIPE_NOWAIT                                     equ     00000001H
PIPE_READMODE_BYTE                              equ     00000000H
PIPE_READMODE_MESSAGE                           equ     00000002H
PIPE_TYPE_BYTE                                  equ     00000000H
PIPE_TYPE_MESSAGE                               equ     00000004H
PIPE_ACCEPT_REMOTE_CLIENTS                      equ     00000000H
PIPE_REJECT_REMOTE_CLIENTS                      equ     00000008H

PIPE_UNLIMITED_INSTANCES                        equ     255

SecurityAnonymous                               equ     0
SecurityIdentification                          equ     1
SecurityImpersonation                           equ     2
SecurityDelegation                              equ     3

SECURITY_ANONYMOUS                              equ     <SecurityAnonymous shl 16>
SECURITY_IDENTIFICATION                         equ     <SecurityIdentification shl 16>
SECURITY_IMPERSONATION                          equ     <SecurityImpersonation shl 16>
SECURITY_DELEGATION                             equ     <SecurityDelegation shl 16>
SECURITY_CONTEXT_TRACKING                       equ     00040000H
SECURITY_EFFECTIVE_ONLY                         equ     00080000H
SECURITY_SQOS_PRESENT                           equ     00100000H
SECURITY_VALID_SQOS_FLAGS                       equ     001F0000H

DELETE                                          equ     10000H
READ_CONTROL                                    equ     20000H
WRITE_DAC                                       equ     40000H
WRITE_OWNER                                     equ     80000H

SYNCHRONIZE                                     equ     100000H
STANDARD_RIGHTS_READ                            equ     READ_CONTROL
STANDARD_RIGHTS_WRITE                           equ     READ_CONTROL
STANDARD_RIGHTS_EXECUTE                         equ     READ_CONTROL
STANDARD_RIGHTS_REQUIRED                        equ     0F0000H
STANDARD_RIGHTS_ALL                             equ     1F0000H

MUTANT_QUERY_STATE                              equ     0001H
MUTANT_ALL_ACCESS                               equ     <STANDARD_RIGHTS_REQUIRED or SYNCHRONIZE or MUTANT_QUERY_STATE>

MUTEX_MODIFY_STATE                              equ     MUTANT_QUERY_STATE
MUTEX_ALL_ACCESS                                equ     MUTANT_ALL_ACCESS

SP_SERIALCOMM                                   equ     00000001H

PST_UNSPECIFIED                                 equ     00000000H
PST_RS232                                       equ     00000001H
PST_PARALLELPORT                                equ     00000002H
PST_RS422                                       equ     00000003H
PST_RS423                                       equ     00000004H
PST_RS449                                       equ     00000005H
PST_MODEM                                       equ     00000006H
PST_FAX                                         equ     00000021H
PST_SCANNER                                     equ     00000022H
PST_NETWORK_BRIDGE                              equ     00000100H
PST_LAT                                         equ     00000101H
PST_TCPIP_TELNET                                equ     00000102H
PST_X25                                         equ     00000103H

PCF_DTRDSR                                      equ     0001H
PCF_RTSCTS                                      equ     0002H
PCF_RLSD                                        equ     0004H
PCF_PARITY_CHECK                                equ     0008H
PCF_XONXOFF                                     equ     0010H
PCF_SETXCHAR                                    equ     0020H
PCF_TOTALTIMEOUTS                               equ     0040H
PCF_INTTIMEOUTS                                 equ     0080H
PCF_SPECIALCHARS                                equ     0100H
PCF_16BITMODE                                   equ     0200H

SP_PARITY                                       equ     0001H
SP_BAUD                                         equ     0002H
SP_DATABITS                                     equ     0004H
SP_STOPBITS                                     equ     0008H
SP_HANDSHAKING                                  equ     0010H
SP_PARITY_CHECK                                 equ     0020H
SP_RLSD                                         equ     0040H

BAUD_075                                        equ     00000001H
BAUD_110                                        equ     00000002H
BAUD_134_5                                      equ     00000004H
BAUD_150                                        equ     00000008H
BAUD_300                                        equ     00000010H
BAUD_600                                        equ     00000020H
BAUD_1200                                       equ     00000040H
BAUD_1800                                       equ     00000080H
BAUD_2400                                       equ     00000100H
BAUD_4800                                       equ     00000200H
BAUD_7200                                       equ     00000400H
BAUD_9600                                       equ     00000800H
BAUD_14400                                      equ     00001000H
BAUD_19200                                      equ     00002000H
BAUD_38400                                      equ     00004000H
BAUD_56K                                        equ     00008000H
BAUD_128K                                       equ     00010000H
BAUD_115200                                     equ     00020000H
BAUD_57600                                      equ     00040000H
BAUD_USER                                       equ     10000000H

DATABITS_5                                      equ     0001H
DATABITS_6                                      equ     0002H
DATABITS_7                                      equ     0004H
DATABITS_8                                      equ     0008H
DATABITS_16                                     equ     0010H
DATABITS_16X                                    equ     0020H

STOPBITS_10                                     equ     0001H
STOPBITS_15                                     equ     0002H
STOPBITS_20                                     equ     0004H

PARITY_NONE                                     equ     0100H
PARITY_ODD                                      equ     0200H
PARITY_EVEN                                     equ     0400H
PARITY_MARK                                     equ     0800H
PARITY_SPACE                                    equ     1000H

COMMPROP_INITIALIZED                            equ     0E73CF52EH

DTR_CONTROL_DISABLE                             equ     00H
DTR_CONTROL_ENABLE                              equ     01H
DTR_CONTROL_HANDSHAKE                           equ     02H

RTS_CONTROL_DISABLE                             equ     00H
RTS_CONTROL_ENABLE                              equ     01H
RTS_CONTROL_HANDSHAKE                           equ     02H
RTS_CONTROL_TOGGLE                              equ     03H

GMEM_FIXED                                      equ     0000H
GMEM_MOVEABLE                                   equ     0002H
GMEM_NOCOMPACT                                  equ     0010H
GMEM_NODISCARD                                  equ     0020H
GMEM_ZEROINIT                                   equ     0040H
GMEM_MODIFY                                     equ     0080H
GMEM_DISCARDABLE                                equ     0100H
GMEM_NOT_BANKED                                 equ     1000H
GMEM_SHARE                                      equ     2000H
GMEM_DDESHARE                                   equ     2000H
GMEM_NOTIFY                                     equ     4000H
GMEM_LOWER                                      equ     GMEM_NOT_BANKED
GMEM_VALID_FLAGS                                equ     7F72H
GMEM_INVALID_HANDLE                             equ     8000H
GMEM_DISCARDED                                  equ     4000H
GMEM_LOCKCOUNT                                  equ     00FFH

GHND                                            equ     <GMEM_MOVEABLE or GMEM_ZEROINIT>
GPTR                                            equ     <GMEM_FIXED or GMEM_ZEROINIT>

LMEM_FIXED                                      equ     0000H
LMEM_MOVEABLE                                   equ     0002H
LMEM_NOCOMPACT                                  equ     0010H
LMEM_NODISCARD                                  equ     0020H
LMEM_ZEROINIT                                   equ     0040H
LMEM_MODIFY                                     equ     0080H
LMEM_DISCARDABLE                                equ     0F00H
LMEM_VALID_FLAGS                                equ     0F72H
LMEM_INVALID_HANDLE                             equ     8000H
LMEM_DISCARDED                                  equ     4000H
LMEM_LOCKCOUNT                                  equ     00FFH

LHND                                            equ     <LMEM_MOVEABLE or LMEM_ZEROINIT>
LPTR                                            equ     <LMEM_FIXED or LMEM_ZEROINIT>

NONZEROLHND                                     equ     LMEM_MOVEABLE
NONZEROLPTR                                     equ     LMEM_FIXED

DEBUG_PROCESS                                   equ     00000001H
DEBUG_ONLY_THIS_PROCESS                         equ     00000002H

CREATE_SUSPENDED                                equ     00000004H
DETACHED_PROCESS                                equ     00000008H
CREATE_NEW_CONSOLE                              equ     00000010H
NORMAL_PRIORITY_CLASS                           equ     00000020H
IDLE_PRIORITY_CLASS                             equ     00000040H
HIGH_PRIORITY_CLASS                             equ     00000080H
REALTIME_PRIORITY_CLASS                         equ     00000100H
CREATE_NEW_PROCESS_GROUP                        equ     00000200H
CREATE_UNICODE_ENVIRONMENT                      equ     00000400H
CREATE_SEPARATE_WOW_VDM                         equ     00000800H
CREATE_SHARED_WOW_VDM                           equ     00001000H
CREATE_FORCEDOS                                 equ     00002000H
BELOW_NORMAL_PRIORITY_CLASS                     equ     00004000H
ABOVE_NORMAL_PRIORITY_CLASS                     equ     00008000H
CREATE_BREAKAWAY_FROM_JOB                       equ     01000000H
CREATE_WITH_USERPROFILE                         equ     02000000H
CREATE_DEFAULT_ERROR_MODE                       equ     04000000H
CREATE_NO_WINDOW                                equ     08000000H
PROFILE_USER                                    equ     10000000H
PROFILE_KERNEL                                  equ     20000000H
PROFILE_SERVER                                  equ     40000000H

THREAD_BASE_PRIORITY_MIN                        equ     (-2)
THREAD_BASE_PRIORITY_MAX                        equ     2
THREAD_BASE_PRIORITY_LOWRT                      equ     15
THREAD_BASE_PRIORITY_IDLE                       equ     (-15)

THREAD_PRIORITY_LOWEST                          equ     THREAD_BASE_PRIORITY_MIN
THREAD_PRIORITY_BELOW_NORMAL                    equ     (THREAD_PRIORITY_LOWEST+1)
THREAD_PRIORITY_NORMAL                          equ     0
THREAD_PRIORITY_HIGHEST                         equ     THREAD_BASE_PRIORITY_MAX
THREAD_PRIORITY_ABOVE_NORMAL                    equ     (THREAD_PRIORITY_HIGHEST-1)
THREAD_PRIORITY_ERROR_RETURN                    equ     MAXLONG
THREAD_PRIORITY_TIME_CRITICAL                   equ     THREAD_BASE_PRIORITY_LOWRT
THREAD_PRIORITY_IDLE                            equ     THREAD_BASE_PRIORITY_IDLE

APPLICATION_ERROR_MASK                          equ     020000000H
ERROR_SEVERITY_SUCCESS                          equ     000000000H
ERROR_SEVERITY_INFORMATIONAL                    equ     040000000H
ERROR_SEVERITY_WARNING                          equ     080000000H
ERROR_SEVERITY_ERROR                            equ     0C0000000H

EXCEPTION_DEBUG_EVENT                           equ     1
CREATE_THREAD_DEBUG_EVENT                       equ     2
CREATE_PROCESS_DEBUG_EVENT                      equ     3
EXIT_THREAD_DEBUG_EVENT                         equ     4
EXIT_PROCESS_DEBUG_EVENT                        equ     5
LOAD_DLL_DEBUG_EVENT                            equ     6
UNLOAD_DLL_DEBUG_EVENT                          equ     7
OUTPUT_DEBUG_STRING_EVENT                       equ     8
RIP_EVENT                                       equ     9

EXCEPTION_MAXIMUM_PARAMETERS                    equ     15

DRIVE_UNKNOWN                                   equ     0
DRIVE_NO_ROOT_DIR                               equ     1
DRIVE_REMOVABLE                                 equ     2
DRIVE_FIXED                                     equ     3
DRIVE_REMOTE                                    equ     4
DRIVE_CDROM                                     equ     5
DRIVE_RAMDISK                                   equ     6

FILE_TYPE_UNKNOWN                               equ     0000H
FILE_TYPE_DISK                                  equ     0001H
FILE_TYPE_CHAR                                  equ     0002H
FILE_TYPE_PIPE                                  equ     0003H
FILE_TYPE_REMOTE                                equ     8000H

STD_INPUT_HANDLE                                equ     (-10)
STD_OUTPUT_HANDLE                               equ     (-11)
STD_ERROR_HANDLE                                equ     (-12)

NOPARITY                                        equ     0
ODDPARITY                                       equ     1
EVENPARITY                                      equ     2
MARKPARITY                                      equ     3
SPACEPARITY                                     equ     4

ONESTOPBIT                                      equ     0
ONE5STOPBITS                                    equ     1
TWOSTOPBITS                                     equ     2

IGNORE                                          equ     0
INFINITE                                        equ     0FFFFFFFFH

CBR_110                                         equ     110
CBR_300                                         equ     300
CBR_600                                         equ     600
CBR_1200                                        equ     1200
CBR_2400                                        equ     2400
CBR_4800                                        equ     4800
CBR_9600                                        equ     9600
CBR_14400                                       equ     14400
CBR_19200                                       equ     19200
CBR_38400                                       equ     38400
CBR_56000                                       equ     56000
CBR_57600                                       equ     57600
CBR_115200                                      equ     115200
CBR_128000                                      equ     128000
CBR_256000                                      equ     256000

CE_RXOVER                                       equ     0001H
CE_OVERRUN                                      equ     0002H
CE_RXPARITY                                     equ     0004H
CE_FRAME                                        equ     0008H
CE_BREAK                                        equ     0010H
CE_TXFULL                                       equ     0100H
CE_PTO                                          equ     0200H
CE_IOE                                          equ     0400H
CE_DNS                                          equ     0800H
CE_OOP                                          equ     1000H
CE_MODE                                         equ     8000H

IE_BADID                                        equ     (-1)
IE_OPEN                                         equ     (-2)
IE_NOPEN                                        equ     (-3)
IE_MEMORY                                       equ     (-4)
IE_DEFAULT                                      equ     (-5)
IE_HARDWARE                                     equ     (-10)
IE_BYTESIZE                                     equ     (-11)
IE_BAUDRATE                                     equ     (-12)

EV_RXCHAR                                       equ     0001H
EV_RXFLAG                                       equ     0002H
EV_TXEMPTY                                      equ     0004H
EV_CTS                                          equ     0008H
EV_DSR                                          equ     0010H
EV_RLSD                                         equ     0020H
EV_BREAK                                        equ     0040H
EV_ERR                                          equ     0080H
EV_RING                                         equ     0100H
EV_PERR                                         equ     0200H
EV_RX80FULL                                     equ     0400H
EV_EVENT1                                       equ     0800H
EV_EVENT2                                       equ     1000H

SETXOFF                                         equ     1
SETXON                                          equ     2
SETRTS                                          equ     3
CLRRTS                                          equ     4
SETDTR                                          equ     5
CLRDTR                                          equ     6
RESETDEV                                        equ     7
SETBREAK                                        equ     8
CLRBREAK                                        equ     9

PURGE_TXABORT                                   equ     0001H
PURGE_RXABORT                                   equ     0002H
PURGE_TXCLEAR                                   equ     0004H
PURGE_RXCLEAR                                   equ     0008H

LPTx                                            equ     80H

MS_CTS_ON                                       equ     0010H
MS_DSR_ON                                       equ     0020H
MS_RING_ON                                      equ     0040H
MS_RLSD_ON                                      equ     0080H

S_QUEUEEMPTY                                    equ     0
S_THRESHOLD                                     equ     1
S_ALLTHRESHOLD                                  equ     2

S_NORMAL                                        equ     0
S_LEGATO                                        equ     1
S_STACCATO                                      equ     2

S_PERIOD512                                     equ     0
S_PERIOD1024                                    equ     1
S_PERIOD2048                                    equ     2
S_PERIODVOICE                                   equ     3
S_WHITE512                                      equ     4
S_WHITE1024                                     equ     5
S_WHITE2048                                     equ     6
S_WHITEVOICE                                    equ     7

S_SERDVNA                                       equ     (-1)
S_SEROFM                                        equ     (-2)
S_SERMACT                                       equ     (-3)
S_SERQFUL                                       equ     (-4)
S_SERBDNT                                       equ     (-5)
S_SERDLN                                        equ     (-6)
S_SERDCC                                        equ     (-7)
S_SERDTP                                        equ     (-8)
S_SERDVL                                        equ     (-9)
S_SERDMD                                        equ     (-10)
S_SERDSH                                        equ     (-11)
S_SERDPT                                        equ     (-12)
S_SERDFQ                                        equ     (-13)
S_SERDDR                                        equ     (-14)
S_SERDSR                                        equ     (-15)
S_SERDST                                        equ     (-16)

NMPWAIT_WAIT_FOREVER                            equ     0FFFFFFFFH
NMPWAIT_NOWAIT                                  equ     000000001H
NMPWAIT_USE_DEFAULT_WAIT                        equ     000000000H

FS_CASE_IS_PRESERVED                            equ     2
FS_CASE_SENSITIVE                               equ     1
FS_UNICODE_STORED_ON_DISK                       equ     4
FS_PERSISTENT_ACLS                              equ     8

FS_VOL_IS_COMPRESSED                            equ     8000H

FS_FILE_COMPRESSION                             equ     10H
FS_FILE_ENCRYPTION                              equ     00020000H

FILE_MAP_COPY                                   equ     1
FILE_MAP_WRITE                                  equ     2
FILE_MAP_READ                                   equ     4
FILE_MAP_ALL_ACCESS                             equ     10H

OF_READ                                         equ     00000000H
OF_WRITE                                        equ     00000001H
OF_READWRITE                                    equ     00000002H
OF_SHARE_COMPAT                                 equ     00000000H
OF_SHARE_EXCLUSIVE                              equ     00000010H
OF_SHARE_DENY_WRITE                             equ     00000020H
OF_SHARE_DENY_READ                              equ     00000030H
OF_SHARE_DENY_NONE                              equ     00000040H
OF_PARSE                                        equ     00000100H
OF_DELETE                                       equ     00000200H
OF_VERIFY                                       equ     00000400H
OF_CANCEL                                       equ     00000800H
OF_CREATE                                       equ     00001000H
OF_PROMPT                                       equ     00002000H
OF_EXIST                                        equ     00004000H
OF_REOPEN                                       equ     00008000H

MAXINTATOM                                      equ     0C000H
INVALID_ATOM                                    equ     0

PROCESS_HEAP_REGION                             equ     0001H
PROCESS_HEAP_UNCOMMITTED_RANGE                  equ     0002H
PROCESS_HEAP_ENTRY_BUSY                         equ     0004H
PROCESS_HEAP_ENTRY_MOVEABLE                     equ     0010H
PROCESS_HEAP_ENTRY_DDESHARE                     equ     0020H

SCS_32BIT_BINARY                                equ     0
SCS_DOS_BINARY                                  equ     1
SCS_WOW_BINARY                                  equ     2
SCS_PIF_BINARY                                  equ     3
SCS_POSIX_BINARY                                equ     4
SCS_OS216_BINARY                                equ     5
SCS_64BIT_BINARY                                equ     6

#ifdef APP_WIN64
    SCS_THIS_PLATFORM_BINARY                    equ     SCS_64BIT_BINARY
#else
    SCS_THIS_PLATFORM_BINARY                    equ     SCS_32BIT_BINARY
#endif

SEM_FAILCRITICALERRORS                          equ     0001H
SEM_NOGPFAULTERRORBOX                           equ     0002H
SEM_NOALIGNMENTFAULTEXCEPT                      equ     0004H
SEM_NOOPENFILEERRORBOX                          equ     8000H

LOCKFILE_FAIL_IMMEDIATELY                       equ     00000001H
LOCKFILE_EXCLUSIVE_LOCK                         equ     00000002H

HANDLE_FLAG_INHERIT                             equ     00000001H
HANDLE_FLAG_PROTECT_FROM_CLOSE                  equ     00000002H

HINSTANCE_ERROR                                 equ     32

GET_TAPE_MEDIA_INFORMATION                      equ     0
GET_TAPE_DRIVE_INFORMATION                      equ     1

SET_TAPE_MEDIA_INFORMATION                      equ     0
SET_TAPE_DRIVE_INFORMATION                      equ     1

FORMAT_MESSAGE_ALLOCATE_BUFFER                  equ     00000100H
FORMAT_MESSAGE_IGNORE_INSERTS                   equ     00000200H
FORMAT_MESSAGE_FROM_STRING                      equ     00000400H
FORMAT_MESSAGE_FROM_HMODULE                     equ     00000800H
FORMAT_MESSAGE_FROM_SYSTEM                      equ     00001000H
FORMAT_MESSAGE_ARGUMENT_ARRAY                   equ     00002000H
FORMAT_MESSAGE_MAX_WIDTH_MASK                   equ     000000FFH

FILE_ENCRYPTABLE                                equ     0
FILE_IS_ENCRYPTED                               equ     1
FILE_SYSTEM_ATTR                                equ     2
FILE_ROOT_DIR                                   equ     3
FILE_SYSTEM_DIR                                 equ     4
FILE_UNKNOWN                                    equ     5
FILE_SYSTEM_NOT_SUPPORT                         equ     6
FILE_USER_DISALLOWED                            equ     7
FILE_READ_ONLY                                  equ     8
FILE_DIR_DISALLOWED                             equ     9

EFS_USE_RECOVERY_KEYS                           equ     1

CREATE_FOR_IMPORT                               equ     1
CREATE_FOR_DIR                                  equ     2

TLS_OUT_OF_INDEXES                              equ     0FFFFFFFFH

BACKUP_INVALID                                  equ     00000000H
BACKUP_DATA                                     equ     00000001H
BACKUP_EA_DATA                                  equ     00000002H
BACKUP_SECURITY_DATA                            equ     00000003H
BACKUP_ALTERNATE_DATA                           equ     00000004H
BACKUP_LINK                                     equ     00000005H
BACKUP_PROPERTY_DATA                            equ     00000006H
BACKUP_OBJECT_ID                                equ     00000007H
BACKUP_REPARSE_DATA                             equ     00000008H
BACKUP_SPARSE_BLOCK                             equ     00000009H
BACKUP_TXFS_DATA                                equ     0000000AH

STREAM_NORMAL_ATTRIBUTE                         equ     00000000H
STREAM_MODIFIED_WHEN_READ                       equ     00000001H
STREAM_CONTAINS_SECURITY                        equ     00000002H
STREAM_CONTAINS_PROPERTIES                      equ     00000004H
STREAM_SPARSE_ATTRIBUTE                         equ     00000008H

STARTF_USESHOWWINDOW                            equ     00000001H
STARTF_USESIZE                                  equ     00000002H
STARTF_USEPOSITION                              equ     00000004H
STARTF_USECOUNTCHARS                            equ     00000008H
STARTF_USEFILLATTRIBUTE                         equ     00000010H
STARTF_RUNFULLSCREEN                            equ     00000020H
STARTF_FORCEONFEEDBACK                          equ     00000040H
STARTF_FORCEOFFFEEDBACK                         equ     00000080H
STARTF_USESTDHANDLES                            equ     00000100H

SHUTDOWN_NORETRY                                equ     00000001H

FIND_RESOURCE_DIRECTORY_TYPES                   equ     00100H
FIND_RESOURCE_DIRECTORY_NAMES                   equ     00200H
FIND_RESOURCE_DIRECTORY_LANGUAGES               equ     00400H
RESOURCE_ENUM_LN                                equ     00001H
RESOURCE_ENUM_MUI                               equ     00002H
RESOURCE_ENUM_MUI_SYSTEM                        equ     00004H
RESOURCE_ENUM_VALIDATE                          equ     00008H
RESOURCE_ENUM_MODULE_EXACT                      equ     00010H

SUPPORT_LANG_NUMBER                             equ     32

GET_MODULE_HANDLE_EX_FLAG_PIN                   equ     000000001H
GET_MODULE_HANDLE_EX_FLAG_UNCHANGED_REFCOUNT    equ     000000002H
GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS          equ     000000004H

DONT_RESOLVE_DLL_REFERENCES                     equ     00000001H
LOAD_LIBRARY_AS_DATAFILE                        equ     00000002H
LOAD_WITH_ALTERED_SEARCH_PATH                   equ     00000008H

LOAD_IGNORE_CODE_AUTHZ_LEVEL                    equ     000000010H
LOAD_LIBRARY_AS_IMAGE_RESOURCE                  equ     000000020H
LOAD_LIBRARY_AS_DATAFILE_EXCLUSIVE              equ     000000040H
LOAD_LIBRARY_REQUIRE_SIGNED_TARGET              equ     000000080H
LOAD_LIBRARY_SEARCH_DLL_LOAD_DIR                equ     000000100H
LOAD_LIBRARY_SEARCH_APPLICATION_DIR             equ     000000200H
LOAD_LIBRARY_SEARCH_USER_DIRS                   equ     000000400H
LOAD_LIBRARY_SEARCH_SYSTEM32                    equ     000000800H
LOAD_LIBRARY_SEARCH_DEFAULT_DIRS                equ     000001000H

DDD_RAW_TARGET_PATH                             equ     00000001H
DDD_REMOVE_DEFINITION                           equ     00000002H
DDD_EXACT_MATCH_ON_REMOVE                       equ     00000004H
DDD_NO_BROADCAST_SYSTEM                         equ     00000008H
DDD_LUID_BROADCAST_DRIVE                        equ     00000010H

FIND_FIRST_EX_CASE_SENSITIVE                    equ     00000001H
FIND_FIRST_EX_LARGE_FETCH                       equ     00000002H

MOVEFILE_REPLACE_EXISTING                       equ     00000001H
MOVEFILE_COPY_ALLOWED                           equ     00000002H
MOVEFILE_DELAY_UNTIL_REBOOT                     equ     00000004H
MOVEFILE_WRITE_THROUGH                          equ     00000008H

EVENTLOG_FULL_INFO                              equ     0

MAX_COMPUTERNAME_LENGTH                         equ     15

LOGON32_LOGON_INTERACTIVE                       equ     2
LOGON32_LOGON_NETWORK                           equ     3
LOGON32_LOGON_BATCH                             equ     4
LOGON32_LOGON_SERVICE                           equ     5
LOGON32_LOGON_UNLOCK                            equ     7
LOGON32_LOGON_NETWORK_CLEARTEXT                 equ     8
LOGON32_LOGON_NEW_CREDENTIALS                   equ     9

LOGON32_PROVIDER_DEFAULT                        equ     0
LOGON32_PROVIDER_WINNT35                        equ     1
LOGON32_PROVIDER_WINNT40                        equ     2
LOGON32_PROVIDER_WINNT50                        equ     3
LOGON32_PROVIDER_VIRTUAL                        equ     4

LOGON_WITH_PROFILE                              equ     00000001H
LOGON_NETCREDENTIALS_ONLY                       equ     00000002H
LOGON_ZERO_PASSWORD_BUFFER                      equ     80000000H

MAX_MANGLED_SITE                                equ     27

HW_PROFILE_GUIDLEN                              equ     39
MAX_PROFILE_LEN                                 equ     80

DOCKINFO_UNDOCKED                               equ     1
DOCKINFO_DOCKED                                 equ     2
DOCKINFO_USER_SUPPLIED                          equ     4
DOCKINFO_USER_UNDOCKED                          equ     <DOCKINFO_USER_SUPPLIED or DOCKINFO_UNDOCKED>
DOCKINFO_USER_DOCKED                            equ     <DOCKINFO_USER_SUPPLIED or DOCKINFO_DOCKED>

TC_NORMAL                                       equ     0
TC_HARDERR                                      equ     1
TC_GP_TRAP                                      equ     2
TC_SIGNAL                                       equ     3

AC_LINE_OFFLINE                                 equ     00H
AC_LINE_ONLINE                                  equ     01H
AC_LINE_BACKUP_POWER                            equ     02H
AC_LINE_UNKNOWN                                 equ     0FFH

BATTERY_FLAG_HIGH                               equ     01H
BATTERY_FLAG_LOW                                equ     02H
BATTERY_FLAG_CRITICAL                           equ     04H
BATTERY_FLAG_CHARGING                           equ     08H
BATTERY_FLAG_NO_BATTERY                         equ     80H
BATTERY_FLAG_UNKNOWN                            equ     0FFH
BATTERY_PERCENTAGE_UNKNOWN                      equ     0FFH
BATTERY_LIFE_UNKNOWN                            equ     0FFFFFFFFH

MAX_LEADBYTES                                   equ     12
MAX_DEFAULTCHAR                                 equ     2

HIGH_SURROGATE_START                            equ     0D800H
HIGH_SURROGATE_END                              equ     0DBFFH
LOW_SURROGATE_START                             equ     0DC00H
LOW_SURROGATE_END                               equ     0DFFFH

MB_PRECOMPOSED                                  equ     000000001H
MB_COMPOSITE                                    equ     000000002H
MB_USEGLYPHCHARS                                equ     000000004H
MB_ERR_INVALID_CHARS                            equ     000000008H

WC_COMPOSITECHECK                               equ     000000200H
WC_DISCARDNS                                    equ     000000010H
WC_SEPCHARS                                     equ     000000020H
WC_DEFAULTCHAR                                  equ     000000040H

WC_ERR_INVALID_CHARS                            equ     000000080H
WC_NO_BEST_FIT_CHARS                            equ     000000400H

CT_CTYPE1                                       equ     000000001H
CT_CTYPE2                                       equ     000000002H
CT_CTYPE3                                       equ     000000004H

C1_UPPER                                        equ     00001H
C1_LOWER                                        equ     00002H
C1_DIGIT                                        equ     00004H
C1_SPACE                                        equ     00008H
C1_PUNCT                                        equ     00010H
C1_CNTRL                                        equ     00020H
C1_BLANK                                        equ     00040H
C1_XDIGIT                                       equ     00080H
C1_ALPHA                                        equ     00100H
C1_DEFINED                                      equ     00200H

C2_LEFTTORIGHT                                  equ     00001H
C2_RIGHTTOLEFT                                  equ     00002H
C2_EUROPENUMBER                                 equ     00003H
C2_EUROPESEPARATOR                              equ     00004H
C2_EUROPETERMINATOR                             equ     00005H
C2_ARABICNUMBER                                 equ     00006H
C2_COMMONSEPARATOR                              equ     00007H
C2_BLOCKSEPARATOR                               equ     00008H
C2_SEGMENTSEPARATOR                             equ     00009H
C2_WHITESPACE                                   equ     0000AH
C2_OTHERNEUTRAL                                 equ     0000BH
C2_NOTAPPLICABLE                                equ     00000H

C3_NONSPACING                                   equ     00001H
C3_DIACRITIC                                    equ     00002H
C3_VOWELMARK                                    equ     00004H
C3_SYMBOL                                       equ     00008H
C3_KATAKANA                                     equ     00010H
C3_HIRAGANA                                     equ     00020H
C3_HALFWIDTH                                    equ     00040H
C3_FULLWIDTH                                    equ     00080H
C3_IDEOGRAPH                                    equ     00100H
C3_KASHIDA                                      equ     00200H
C3_LEXICAL                                      equ     00400H
C3_HIGHSURROGATE                                equ     00800H
C3_LOWSURROGATE                                 equ     01000H
C3_ALPHA                                        equ     08000H
C3_NOTAPPLICABLE                                equ     00000H

NORM_IGNORECASE                                 equ     000000001H
NORM_IGNORENONSPACE                             equ     000000002H
NORM_IGNORESYMBOLS                              equ     000000004H
LINGUISTIC_IGNORECASE                           equ     000000010H
LINGUISTIC_IGNOREDIACRITIC                      equ     000000020H
NORM_IGNOREKANATYPE                             equ     000010000H
NORM_IGNOREWIDTH                                equ     000020000H
NORM_LINGUISTIC_CASING                          equ     008000000H

MAP_FOLDCZONE                                   equ     000000010H
MAP_PRECOMPOSED                                 equ     000000020H
MAP_COMPOSITE                                   equ     000000040H
MAP_FOLDDIGITS                                  equ     000000080H
MAP_EXPAND_LIGATURES                            equ     000002000H

LCMAP_LOWERCASE                                 equ     000000100H
LCMAP_UPPERCASE                                 equ     000000200H
LCMAP_TITLECASE                                 equ     000000300H
LCMAP_SORTKEY                                   equ     000000400H
LCMAP_BYTEREV                                   equ     000000800H
LCMAP_HIRAGANA                                  equ     000100000H
LCMAP_KATAKANA                                  equ     000200000H
LCMAP_HALFWIDTH                                 equ     000400000H
LCMAP_FULLWIDTH                                 equ     000800000H
LCMAP_LINGUISTIC_CASING                         equ     001000000H
LCMAP_SIMPLIFIED_CHINESE                        equ     002000000H
LCMAP_TRADITIONAL_CHINESE                       equ     004000000H
LCMAP_SORTHANDLE                                equ     020000000H
LCMAP_HASH                                      equ     000040000H

FIND_STARTSWITH                                 equ     000100000H
FIND_ENDSWITH                                   equ     000200000H
FIND_FROMSTART                                  equ     000400000H
FIND_FROMEND                                    equ     000800000H

LGRPID_INSTALLED                                equ     000000001H
LGRPID_SUPPORTED                                equ     000000002H

LCID_INSTALLED                                  equ     000000001H
LCID_SUPPORTED                                  equ     000000002H
LCID_ALTERNATE_SORTS                            equ     000000004H

LOCALE_ALL                                      equ     0
LOCALE_WINDOWS                                  equ     000000001H
LOCALE_SUPPLEMENTAL                             equ     000000002H
LOCALE_ALTERNATE_SORTS                          equ     000000004H
LOCALE_REPLACEMENT                              equ     000000008H
LOCALE_NEUTRALDATA                              equ     000000010H
LOCALE_SPECIFICDATA                             equ     000000020H

CP_INSTALLED                                    equ     000000001H
CP_SUPPORTED                                    equ     000000002H

SORT_STRINGSORT                                 equ     000001000H
SORT_DIGITSASNUMBERS                            equ     000000008H

CSTR_LESS_THAN                                  equ     1
CSTR_EQUAL                                      equ     2
CSTR_GREATER_THAN                               equ     3

CP_ACP                                          equ     0
CP_OEMCP                                        equ     1
CP_MACCP                                        equ     2
CP_THREAD_ACP                                   equ     3
CP_SYMBOL                                       equ     42
CP_UTF7                                         equ     65000
CP_UTF8                                         equ     65001

CTRY_DEFAULT                                    equ     0
CTRY_ALBANIA                                    equ     355
CTRY_ALGERIA                                    equ     213
CTRY_ARGENTINA                                  equ     54
CTRY_ARMENIA                                    equ     374
CTRY_AUSTRALIA                                  equ     61
CTRY_AUSTRIA                                    equ     43
CTRY_AZERBAIJAN                                 equ     994
CTRY_BAHRAIN                                    equ     973
CTRY_BELARUS                                    equ     375
CTRY_BELGIUM                                    equ     32
CTRY_BELIZE                                     equ     501
CTRY_BOLIVIA                                    equ     591
CTRY_BRAZIL                                     equ     55
CTRY_BRUNEI_DARUSSALAM                          equ     673
CTRY_BULGARIA                                   equ     359
CTRY_CANADA                                     equ     2
CTRY_CARIBBEAN                                  equ     1
CTRY_CHILE                                      equ     56
CTRY_COLOMBIA                                   equ     57
CTRY_COSTA_RICA                                 equ     506
CTRY_CROATIA                                    equ     385
CTRY_CZECH                                      equ     420
CTRY_DENMARK                                    equ     45
CTRY_DOMINICAN_REPUBLIC                         equ     1
CTRY_ECUADOR                                    equ     593
CTRY_EGYPT                                      equ     20
CTRY_EL_SALVADOR                                equ     503
CTRY_ESTONIA                                    equ     372
CTRY_FAEROE_ISLANDS                             equ     298
CTRY_FINLAND                                    equ     358
CTRY_FRANCE                                     equ     33
CTRY_GEORGIA                                    equ     995
CTRY_GERMANY                                    equ     49
CTRY_GREECE                                     equ     30
CTRY_GUATEMALA                                  equ     502
CTRY_HONDURAS                                   equ     504
CTRY_HONG_KONG                                  equ     852
CTRY_HUNGARY                                    equ     36
CTRY_ICELAND                                    equ     354
CTRY_INDIA                                      equ     91
CTRY_INDONESIA                                  equ     62
CTRY_IRAN                                       equ     981
CTRY_IRAQ                                       equ     964
CTRY_IRELAND                                    equ     353
CTRY_ISRAEL                                     equ     972
CTRY_ITALY                                      equ     39
CTRY_JAMAICA                                    equ     1
CTRY_JAPAN                                      equ     81
CTRY_JORDAN                                     equ     962
CTRY_KAZAKSTAN                                  equ     7
CTRY_KENYA                                      equ     254
CTRY_KUWAIT                                     equ     965
CTRY_KYRGYZSTAN                                 equ     996
CTRY_LATVIA                                     equ     371
CTRY_LEBANON                                    equ     961
CTRY_LIBYA                                      equ     218
CTRY_LIECHTENSTEIN                              equ     41
CTRY_LITHUANIA                                  equ     370
CTRY_LUXEMBOURG                                 equ     352
CTRY_MACAU                                      equ     853
CTRY_MACEDONIA                                  equ     389
CTRY_MALAYSIA                                   equ     60
CTRY_MALDIVES                                   equ     960
CTRY_MEXICO                                     equ     52
CTRY_MONACO                                     equ     33
CTRY_MONGOLIA                                   equ     976
CTRY_MOROCCO                                    equ     212
CTRY_NETHERLANDS                                equ     31
CTRY_NEW_ZEALAND                                equ     64
CTRY_NICARAGUA                                  equ     505
CTRY_NORWAY                                     equ     47
CTRY_OMAN                                       equ     968
CTRY_PAKISTAN                                   equ     92
CTRY_PANAMA                                     equ     507
CTRY_PARAGUAY                                   equ     595
CTRY_PERU                                       equ     51
CTRY_PHILIPPINES                                equ     63
CTRY_POLAND                                     equ     48
CTRY_PORTUGAL                                   equ     351
CTRY_PRCHINA                                    equ     86
CTRY_PUERTO_RICO                                equ     1
CTRY_QATAR                                      equ     974
CTRY_ROMANIA                                    equ     40
CTRY_RUSSIA                                     equ     7
CTRY_SAUDI_ARABIA                               equ     966
CTRY_SERBIA                                     equ     381
CTRY_SINGAPORE                                  equ     65
CTRY_SLOVAK                                     equ     421
CTRY_SLOVENIA                                   equ     386
CTRY_SOUTH_AFRICA                               equ     27
CTRY_SOUTH_KOREA                                equ     82
CTRY_SPAIN                                      equ     34
CTRY_SWEDEN                                     equ     46
CTRY_SWITZERLAND                                equ     41
CTRY_SYRIA                                      equ     963
CTRY_TAIWAN                                     equ     886
CTRY_TATARSTAN                                  equ     7
CTRY_THAILAND                                   equ     66
CTRY_TRINIDAD_Y_TOBAGO                          equ     1
CTRY_TUNISIA                                    equ     216
CTRY_TURKEY                                     equ     90
CTRY_UAE                                        equ     971
CTRY_UKRAINE                                    equ     380
CTRY_UNITED_KINGDOM                             equ     44
CTRY_UNITED_STATES                              equ     1
CTRY_URUGUAY                                    equ     598
CTRY_UZBEKISTAN                                 equ     7
CTRY_VENEZUELA                                  equ     58
CTRY_VIET_NAM                                   equ     84
CTRY_YEMEN                                      equ     967
CTRY_ZIMBABWE                                   equ     263

LOCALE_NOUSEROVERRIDE                           equ     080000000H
LOCALE_USE_CP_ACP                               equ     040000000H
LOCALE_RETURN_NUMBER                            equ     020000000H
LOCALE_RETURN_GENITIVE_NAMES                    equ     010000000H
LOCALE_ALLOW_NEUTRAL_NAMES                      equ     008000000H

LOCALE_SLOCALIZEDDISPLAYNAME                    equ     000000002H
LOCALE_SENGLISHDISPLAYNAME                      equ     000000072H
LOCALE_SNATIVEDISPLAYNAME                       equ     000000073H
LOCALE_SLOCALIZEDLANGUAGENAME                   equ     00000006fH
LOCALE_SENGLISHLANGUAGENAME                     equ     000001001H
LOCALE_SNATIVELANGUAGENAME                      equ     000000004H
LOCALE_SLOCALIZEDCOUNTRYNAME                    equ     000000006H
LOCALE_SENGLISHCOUNTRYNAME                      equ     000001002H
LOCALE_SNATIVECOUNTRYNAME                       equ     000000008H

LOCALE_SLANGUAGE                                equ     000000002H

LOCALE_SLANGDISPLAYNAME                         equ     00000006fH

LOCALE_SENGLANGUAGE                             equ     000001001H
LOCALE_SNATIVELANGNAME                          equ     000000004H
LOCALE_SCOUNTRY                                 equ     000000006H
LOCALE_SENGCOUNTRY                              equ     000001002H
LOCALE_SNATIVECTRYNAME                          equ     000000008H

LOCALE_ILANGUAGE                                equ     000000001H
LOCALE_SABBREVLANGNAME                          equ     000000003H
LOCALE_ICOUNTRY                                 equ     000000005H
LOCALE_SABBREVCTRYNAME                          equ     000000007H
LOCALE_IGEOID                                   equ     00000005BH
LOCALE_IDEFAULTLANGUAGE                         equ     000000009H
LOCALE_IDEFAULTCOUNTRY                          equ     00000000AH
LOCALE_IDEFAULTCODEPAGE                         equ     00000000BH
LOCALE_IDEFAULTANSICODEPAGE                     equ     000001004H
LOCALE_IDEFAULTMACCODEPAGE                      equ     000001011H
LOCALE_SLIST                                    equ     00000000CH
LOCALE_IMEASURE                                 equ     00000000DH
LOCALE_SDECIMAL                                 equ     00000000EH
LOCALE_STHOUSAND                                equ     00000000FH
LOCALE_SGROUPING                                equ     000000010H
LOCALE_IDIGITS                                  equ     000000011H
LOCALE_ILZERO                                   equ     000000012H
LOCALE_INEGNUMBER                               equ     000001010H
LOCALE_SNATIVEDIGITS                            equ     000000013H
LOCALE_SCURRENCY                                equ     000000014H
LOCALE_SINTLSYMBOL                              equ     000000015H
LOCALE_SMONDECIMALSEP                           equ     000000016H
LOCALE_SMONTHOUSANDSEP                          equ     000000017H
LOCALE_SMONGROUPING                             equ     000000018H
LOCALE_ICURRDIGITS                              equ     000000019H
LOCALE_IINTLCURRDIGITS                          equ     00000001AH
LOCALE_ICURRENCY                                equ     00000001BH
LOCALE_INEGCURR                                 equ     00000001CH
LOCALE_SDATE                                    equ     00000001DH
LOCALE_STIME                                    equ     00000001EH
LOCALE_SSHORTDATE                               equ     00000001FH
LOCALE_SLONGDATE                                equ     000000020H
LOCALE_STIMEFORMAT                              equ     000001003H
LOCALE_IDATE                                    equ     000000021H
LOCALE_ILDATE                                   equ     000000022H
LOCALE_ITIME                                    equ     000000023H
LOCALE_ITIMEMARKPOSN                            equ     000001005H
LOCALE_ICENTURY                                 equ     000000024H
LOCALE_ITLZERO                                  equ     000000025H
LOCALE_IDAYLZERO                                equ     000000026H
LOCALE_IMONLZERO                                equ     000000027H
LOCALE_S1159                                    equ     000000028H
LOCALE_S2359                                    equ     000000029H
LOCALE_ICALENDARTYPE                            equ     000001009H
LOCALE_IOPTIONALCALENDAR                        equ     00000100BH
LOCALE_IFIRSTDAYOFWEEK                          equ     00000100CH
LOCALE_IFIRSTWEEKOFYEAR                         equ     00000100DH
LOCALE_SDAYNAME1                                equ     00000002AH
LOCALE_SDAYNAME2                                equ     00000002BH
LOCALE_SDAYNAME3                                equ     00000002CH
LOCALE_SDAYNAME4                                equ     00000002DH
LOCALE_SDAYNAME5                                equ     00000002EH
LOCALE_SDAYNAME6                                equ     00000002FH
LOCALE_SDAYNAME7                                equ     000000030H
LOCALE_SABBREVDAYNAME1                          equ     000000031H
LOCALE_SABBREVDAYNAME2                          equ     000000032H
LOCALE_SABBREVDAYNAME3                          equ     000000033H
LOCALE_SABBREVDAYNAME4                          equ     000000034H
LOCALE_SABBREVDAYNAME5                          equ     000000035H
LOCALE_SABBREVDAYNAME6                          equ     000000036H
LOCALE_SABBREVDAYNAME7                          equ     000000037H
LOCALE_SMONTHNAME1                              equ     000000038H
LOCALE_SMONTHNAME2                              equ     000000039H
LOCALE_SMONTHNAME3                              equ     00000003AH
LOCALE_SMONTHNAME4                              equ     00000003BH
LOCALE_SMONTHNAME5                              equ     00000003CH
LOCALE_SMONTHNAME6                              equ     00000003DH
LOCALE_SMONTHNAME7                              equ     00000003EH
LOCALE_SMONTHNAME8                              equ     00000003FH
LOCALE_SMONTHNAME9                              equ     000000040H
LOCALE_SMONTHNAME10                             equ     000000041H
LOCALE_SMONTHNAME11                             equ     000000042H
LOCALE_SMONTHNAME12                             equ     000000043H
LOCALE_SMONTHNAME13                             equ     00000100EH
LOCALE_SABBREVMONTHNAME1                        equ     000000044H
LOCALE_SABBREVMONTHNAME2                        equ     000000045H
LOCALE_SABBREVMONTHNAME3                        equ     000000046H
LOCALE_SABBREVMONTHNAME4                        equ     000000047H
LOCALE_SABBREVMONTHNAME5                        equ     000000048H
LOCALE_SABBREVMONTHNAME6                        equ     000000049H
LOCALE_SABBREVMONTHNAME7                        equ     00000004AH
LOCALE_SABBREVMONTHNAME8                        equ     00000004BH
LOCALE_SABBREVMONTHNAME9                        equ     00000004CH
LOCALE_SABBREVMONTHNAME10                       equ     00000004DH
LOCALE_SABBREVMONTHNAME11                       equ     00000004EH
LOCALE_SABBREVMONTHNAME12                       equ     00000004FH
LOCALE_SABBREVMONTHNAME13                       equ     00000100FH
LOCALE_SPOSITIVESIGN                            equ     000000050H
LOCALE_SNEGATIVESIGN                            equ     000000051H
LOCALE_IPOSSIGNPOSN                             equ     000000052H
LOCALE_INEGSIGNPOSN                             equ     000000053H
LOCALE_IPOSSYMPRECEDES                          equ     000000054H
LOCALE_IPOSSEPBYSPACE                           equ     000000055H
LOCALE_INEGSYMPRECEDES                          equ     000000056H
LOCALE_INEGSEPBYSPACE                           equ     000000057H

LOCALE_FONTSIGNATURE                            equ     000000058H
LOCALE_SISO639LANGNAME                          equ     000000059H
LOCALE_SISO3166CTRYNAME                         equ     00000005AH

LOCALE_IDEFAULTEBCDICCODEPAGE                   equ     000001012H
LOCALE_IPAPERSIZE                               equ     00000100AH
LOCALE_SENGCURRNAME                             equ     000001007H
LOCALE_SNATIVECURRNAME                          equ     000001008H
LOCALE_SYEARMONTH                               equ     000001006H
LOCALE_SSORTNAME                                equ     000001013H
LOCALE_IDIGITSUBSTITUTION                       equ     000001014H

LOCALE_SNAME                                    equ     00000005CH
LOCALE_SDURATION                                equ     00000005DH
LOCALE_SKEYBOARDSTOINSTALL                      equ     00000005EH
LOCALE_SSHORTESTDAYNAME1                        equ     000000060H
LOCALE_SSHORTESTDAYNAME2                        equ     000000061H
LOCALE_SSHORTESTDAYNAME3                        equ     000000062H
LOCALE_SSHORTESTDAYNAME4                        equ     000000063H
LOCALE_SSHORTESTDAYNAME5                        equ     000000064H
LOCALE_SSHORTESTDAYNAME6                        equ     000000065H
LOCALE_SSHORTESTDAYNAME7                        equ     000000066H
LOCALE_SISO639LANGNAME2                         equ     000000067H
LOCALE_SISO3166CTRYNAME2                        equ     000000068H
LOCALE_SNAN                                     equ     000000069H
LOCALE_SPOSINFINITY                             equ     00000006AH
LOCALE_SNEGINFINITY                             equ     00000006BH
LOCALE_SSCRIPTS                                 equ     00000006CH
LOCALE_SPARENT                                  equ     00000006DH
LOCALE_SCONSOLEFALLBACKNAME                     equ     00000006EH

LOCALE_IREADINGLAYOUT                           equ     000000070H
LOCALE_INEUTRAL                                 equ     000000071H
LOCALE_INEGATIVEPERCENT                         equ     000000074H
LOCALE_IPOSITIVEPERCENT                         equ     000000075H
LOCALE_SPERCENT                                 equ     000000076H
LOCALE_SPERMILLE                                equ     000000077H
LOCALE_SMONTHDAY                                equ     000000078H
LOCALE_SSHORTTIME                               equ     000000079H
LOCALE_SOPENTYPELANGUAGETAG                     equ     00000007AH
LOCALE_SSORTLOCALE                              equ     00000007BH

TIME_NOMINUTESORSECONDS                         equ     000000001H
TIME_NOSECONDS                                  equ     000000002H
TIME_NOTIMEMARKER                               equ     000000004H
TIME_FORCE24HOURFORMAT                          equ     000000008H

DATE_SHORTDATE                                  equ     000000001H
DATE_LONGDATE                                   equ     000000002H
DATE_USE_ALT_CALENDAR                           equ     000000004H
DATE_YEARMONTH                                  equ     000000008H
DATE_LTRREADING                                 equ     000000010H
DATE_RTLREADING                                 equ     000000020H
DATE_AUTOLAYOUT                                 equ     000000040H

CAL_NOUSEROVERRIDE                              equ     LOCALE_NOUSEROVERRIDE
CAL_USE_CP_ACP                                  equ     LOCALE_USE_CP_ACP
CAL_RETURN_NUMBER                               equ     LOCALE_RETURN_NUMBER
CAL_RETURN_GENITIVE_NAMES                       equ     LOCALE_RETURN_GENITIVE_NAMES

CAL_ICALINTVALUE                                equ     000000001H
CAL_SCALNAME                                    equ     000000002H
CAL_IYEAROFFSETRANGE                            equ     000000003H
CAL_SERASTRING                                  equ     000000004H
CAL_SSHORTDATE                                  equ     000000005H
CAL_SLONGDATE                                   equ     000000006H
CAL_SDAYNAME1                                   equ     000000007H
CAL_SDAYNAME2                                   equ     000000008H
CAL_SDAYNAME3                                   equ     000000009H
CAL_SDAYNAME4                                   equ     00000000AH
CAL_SDAYNAME5                                   equ     00000000BH
CAL_SDAYNAME6                                   equ     00000000CH
CAL_SDAYNAME7                                   equ     00000000DH
CAL_SABBREVDAYNAME1                             equ     00000000EH
CAL_SABBREVDAYNAME2                             equ     00000000FH
CAL_SABBREVDAYNAME3                             equ     000000010H
CAL_SABBREVDAYNAME4                             equ     000000011H
CAL_SABBREVDAYNAME5                             equ     000000012H
CAL_SABBREVDAYNAME6                             equ     000000013H
CAL_SABBREVDAYNAME7                             equ     000000014H

CAL_SMONTHNAME1                                 equ     000000015H
CAL_SMONTHNAME2                                 equ     000000016H
CAL_SMONTHNAME3                                 equ     000000017H
CAL_SMONTHNAME4                                 equ     000000018H
CAL_SMONTHNAME5                                 equ     000000019H
CAL_SMONTHNAME6                                 equ     00000001AH
CAL_SMONTHNAME7                                 equ     00000001BH
CAL_SMONTHNAME8                                 equ     00000001CH
CAL_SMONTHNAME9                                 equ     00000001DH
CAL_SMONTHNAME10                                equ     00000001EH
CAL_SMONTHNAME11                                equ     00000001FH
CAL_SMONTHNAME12                                equ     000000020H
CAL_SMONTHNAME13                                equ     000000021H
CAL_SABBREVMONTHNAME1                           equ     000000022H
CAL_SABBREVMONTHNAME2                           equ     000000023H
CAL_SABBREVMONTHNAME3                           equ     000000024H
CAL_SABBREVMONTHNAME4                           equ     000000025H
CAL_SABBREVMONTHNAME5                           equ     000000026H
CAL_SABBREVMONTHNAME6                           equ     000000027H
CAL_SABBREVMONTHNAME7                           equ     000000028H
CAL_SABBREVMONTHNAME8                           equ     000000029H
CAL_SABBREVMONTHNAME9                           equ     00000002AH
CAL_SABBREVMONTHNAME10                          equ     00000002BH
CAL_SABBREVMONTHNAME11                          equ     00000002CH
CAL_SABBREVMONTHNAME12                          equ     00000002DH
CAL_SABBREVMONTHNAME13                          equ     00000002EH

CAL_SYEARMONTH                                  equ     00000002FH
CAL_ITWODIGITYEARMAX                            equ     000000030H

CAL_SSHORTESTDAYNAME1                           equ     000000031H
CAL_SSHORTESTDAYNAME2                           equ     000000032H
CAL_SSHORTESTDAYNAME3                           equ     000000033H
CAL_SSHORTESTDAYNAME4                           equ     000000034H
CAL_SSHORTESTDAYNAME5                           equ     000000035H
CAL_SSHORTESTDAYNAME6                           equ     000000036H
CAL_SSHORTESTDAYNAME7                           equ     000000037H

CAL_SMONTHDAY                                   equ     000000038H
CAL_SABBREVERASTRING                            equ     000000039H

ENUM_ALL_CALENDARS                              equ     0FFFFFFFFH

CAL_GREGORIAN                                   equ     1
CAL_GREGORIAN_US                                equ     2
CAL_JAPAN                                       equ     3
CAL_TAIWAN                                      equ     4
CAL_KOREA                                       equ     5
CAL_HIJRI                                       equ     6
CAL_THAI                                        equ     7
CAL_HEBREW                                      equ     8
CAL_GREGORIAN_ME_FRENCH                         equ     9
CAL_GREGORIAN_ARABIC                            equ     10
CAL_GREGORIAN_XLIT_ENGLISH                      equ     11
CAL_GREGORIAN_XLIT_FRENCH                       equ     12
CAL_UMALQURA                                    equ     23

LGRPID_WESTERN_EUROPE                           equ     00001H
LGRPID_CENTRAL_EUROPE                           equ     00002H
LGRPID_BALTIC                                   equ     00003H
LGRPID_GREEK                                    equ     00004H
LGRPID_CYRILLIC                                 equ     00005H
LGRPID_TURKIC                                   equ     00006H
LGRPID_TURKISH                                  equ     00006H
LGRPID_JAPANESE                                 equ     00007H
LGRPID_KOREAN                                   equ     00008H
LGRPID_TRADITIONAL_CHINESE                      equ     00009H
LGRPID_SIMPLIFIED_CHINESE                       equ     0000AH
LGRPID_THAI                                     equ     0000BH
LGRPID_HEBREW                                   equ     0000CH
LGRPID_ARABIC                                   equ     0000DH
LGRPID_VIETNAMESE                               equ     0000EH
LGRPID_INDIC                                    equ     0000FH
LGRPID_GEORGIAN                                 equ     00010H
LGRPID_ARMENIAN                                 equ     00011H

MUI_LANGUAGE_ID                                 equ     0004H
MUI_LANGUAGE_NAME                               equ     0008H
MUI_MERGE_SYSTEM_FALLBACK                       equ     0010H
MUI_MERGE_USER_FALLBACK                         equ     0020H
MUI_UI_FALLBACK                                 equ     <MUI_MERGE_SYSTEM_FALLBACK or MUI_MERGE_USER_FALLBACK>
MUI_THREAD_LANGUAGES                            equ     0040H
MUI_CONSOLE_FILTER                              equ     0100H
MUI_COMPLEX_SCRIPT_FILTER                       equ     0200H
MUI_RESET_FILTERS                               equ     0001H
MUI_USER_PREFERRED_UI_LANGUAGES                 equ     0010H
MUI_USE_INSTALLED_LANGUAGES                     equ     0020H
MUI_USE_SEARCH_ALL_LANGUAGES                    equ     0040H
MUI_LANG_NEUTRAL_PE_FILE                        equ     0100H
MUI_NON_LANG_NEUTRAL_FILE                       equ     0200H
MUI_MACHINE_LANGUAGE_SETTINGS                   equ     0400H
MUI_FILETYPE_NOT_LANGUAGE_NEUTRAL               equ     0001H
MUI_FILETYPE_LANGUAGE_NEUTRAL_MAIN              equ     0002H
MUI_FILETYPE_LANGUAGE_NEUTRAL_MUI               equ     0004H
MUI_QUERY_TYPE                                  equ     0001H
MUI_QUERY_CHECKSUM                              equ     0002H
MUI_QUERY_LANGUAGE_NAME                         equ     0004H
MUI_QUERY_RESOURCE_TYPES                        equ     0008H
MUI_FILEINFO_VERSION                            equ     0001H
MUI_FULL_LANGUAGE                               equ     0001H
MUI_PARTIAL_LANGUAGE                            equ     0002H
MUI_LIP_LANGUAGE                                equ     0004H
MUI_LANGUAGE_INSTALLED                          equ     0020H
MUI_LANGUAGE_LICENSED                           equ     0040H

COMPARE_STRING                                  equ     0001H

define GEOID                                    dd
define GEOTYPE                                  dd
define GEOCLASS                                 dd
GEOID_NOT_AVAILABLE                             equ     (-1)

GEO_NATION                                      equ     00001H
GEO_LATITUDE                                    equ     00002H
GEO_LONGITUDE                                   equ     00003H
GEO_ISO2                                        equ     00004H
GEO_ISO3                                        equ     00005H
GEO_RFC1766                                     equ     00006H
GEO_LCID                                        equ     00007H
GEO_FRIENDLYNAME                                equ     00008H
GEO_OFFICIALNAME                                equ     00009H
GEO_TIMEZONES                                   equ     0000AH
GEO_OFFICIALLANGUAGES                           equ     0000BH
GEO_ISO_UN_NUMBER                               equ     0000CH
GEO_PARENT                                      equ     0000DH

GEOCLASS_NATION                                 equ     16
GEOCLASS_REGION                                 equ     14
GEOCLASS_ALL                                    equ     0

NormalizationOther                              equ     0
NormalizationC                                  equ     01H
NormalizationD                                  equ     02H
NormalizationKC                                 equ     05H
NormalizationKD                                 equ     06H

IDN_ALLOW_UNASSIGNED                            equ     001H
IDN_USE_STD3_ASCII_RULES                        equ     002H
IDN_EMAIL_ADDRESS                               equ     004H
IDN_RAW_PUNYCODE                                equ     008H

VS_ALLOW_LATIN                                  equ     00001H

GSS_ALLOW_INHERITED_COMMON                      equ     00001H

MUI_FORMAT_REG_COMPAT                           equ     00001H
MUI_FORMAT_INF_COMPAT                           equ     00002H
MUI_VERIFY_FILE_EXISTS                          equ     00004H
MUI_SKIP_STRING_CACHE                           equ     00008H
MUI_IMMUTABLE_LOOKUP                            equ     00010H

LOCALE_NAME_USER_DEFAULT                        equ     NULL

GetFileExInfoStandard                           equ     0
GetFileExMaxInfoLevel                           equ     1

FindExInfoStandard                              equ     0
FindExInfoMaxInfoLevel                          equ     1

FindExSearchNameMatch                           equ     0
FindExSearchLimitToDirectories                  equ     1
FindExSearchLimitToDevices                      equ     2
FindExSearchMaxSearchOp                         equ     3

ComputerNameNetBIOS                             equ     0
ComputerNameDnsHostname                         equ     1
ComputerNameDnsDomain                           equ     2
ComputerNameDnsFullyQualified                   equ     3
ComputerNamePhysicalNetBIOS                     equ     4
ComputerNamePhysicalDnsHostname                 equ     5
ComputerNamePhysicalDnsDomain                   equ     6
ComputerNamePhysicalDnsFullyQualified           equ     7
ComputerNameMax                                 equ     8

LowMemoryResourceNotification                   equ     0
HighMemoryResourceNotification                  equ     1

WinNullSid                                      equ     0
WinWorldSid                                     equ     1
WinLocalSid                                     equ     2
WinCreatorOwnerSid                              equ     3
WinCreatorGroupSid                              equ     4
WinCreatorOwnerServerSid                        equ     5
WinCreatorGroupServerSid                        equ     6
WinNtAuthoritySid                               equ     7
WinDialupSid                                    equ     8
WinNetworkSid                                   equ     9
WinBatchSid                                     equ     10
WinInteractiveSid                               equ     11
WinServiceSid                                   equ     12
WinAnonymousSid                                 equ     13
WinProxySid                                     equ     14
WinEnterpriseControllersSid                     equ     15
WinSelfSid                                      equ     16
WinAuthenticatedUserSid                         equ     17
WinRestrictedCodeSid                            equ     18
WinTerminalServerSid                            equ     19
WinRemoteLogonIdSid                             equ     20
WinLogonIdsSid                                  equ     21
WinLocalSystemSid                               equ     22
WinLocalServiceSid                              equ     23
WinNetworkServiceSid                            equ     24
WinBuiltinDomainSid                             equ     25
WinBuiltinAdministratorsSid                     equ     26
WinBuiltinUsersSid                              equ     27
WinBuiltinGuestsSid                             equ     28
WinBuiltinPowerUsersSid                         equ     29
WinBuiltinAccountOperatorsSid                   equ     30
WinBuiltinSystemOperatorsSid                    equ     31
WinBuiltinPrintOperatorsSid                     equ     32
WinBuiltinBackupOperatorsSid                    equ     33
WinBuiltinReplicatorSid                         equ     34
WinBuiltinPreWindows2000CompatibleAccessSid     equ     35
WinBuiltinRemoteDesktopUsersSid                 equ     36
WinBuiltinNetworkConfigurationOperatorsSid      equ     37
WinAccountAdministratorSid                      equ     38
WinAccountGuestSid                              equ     39
WinAccountKrbtgtSid                             equ     40
WinAccountDomainAdminsSid                       equ     41
WinAccountDomainUsersSid                        equ     42
WinAccountDomainGuestsSid                       equ     43
WinAccountComputersSid                          equ     44
WinAccountControllersSid                        equ     45
WinAccountCertAdminsSid                         equ     46
WinAccountSchemaAdminsSid                       equ     47
WinAccountEnterpriseAdminsSid                   equ     48
WinAccountPolicyAdminsSid                       equ     49
WinAccountRasAndIasServersSid                   equ     50
WinNTLMAuthenticationSid                        equ     51
WinDigestAuthenticationSid                      equ     52
WinSChannelAuthenticationSid                    equ     53
WinThisOrganizationSid                          equ     54
WinOtherOrganizationSid                         equ     55
WinBuiltinIncomingForestTrustBuildersSid        equ     56
WinBuiltinPerfMonitoringUsersSid                equ     57
WinBuiltinPerfLoggingUsersSid                   equ     58
WinBuiltinAuthorizationAccessSid                equ     59
WinBuiltinTerminalServerLicenseServersSid       equ     60
WinBuiltinDCOMUsersSid                          equ     61
WinBuiltinIUsersSid                             equ     62
WinIUserSid                                     equ     63
WinBuiltinCryptoOperatorsSid                    equ     64
WinUntrustedLabelSid                            equ     65
WinLowLabelSid                                  equ     66
WinMediumLabelSid                               equ     67
WinHighLabelSid                                 equ     68
WinSystemLabelSid                               equ     69
WinWriteRestrictedCodeSid                       equ     70
WinCreatorOwnerRightsSid                        equ     71
WinCacheablePrincipalsGroupSid                  equ     72
WinNonCacheablePrincipalsGroupSid               equ     73
WinEnterpriseReadonlyControllersSid             equ     74
WinAccountReadonlyControllersSid                equ     75
WinBuiltinEventLogReadersGroup                  equ     76
WinNewEnterpriseReadonlyControllersSid          equ     77
WinBuiltinCertSvcDComAccessGroup                equ     78

ProcessMemoryPriority                           equ     00H
ProcessInformationClassMax                      equ     01H

ExceptionContinueExecution                      equ     00H
ExceptionContinueSearch                         equ     01H
ExceptionNestedException                        equ     02H
ExceptionCollidedUnwind                         equ     03H

EXCEPTION_EXECUTE_HANDLER                       equ     1
EXCEPTION_CONTINUE_SEARCH                       equ     0
EXCEPTION_CONTINUE_EXECUTION                    equ     (-1)

DEPPolicyAlwaysOff                              equ     00H
DEPPolicyAlwaysOn                               equ     01H
DEPPolicyOptIn                                  equ     02H
DEPPolicyOptOut                                 equ     03H
DEPTotalPolicyCount                             equ     04H

OVERWRITE_HIDDEN                                equ     4
EFSRPC_SECURE_ONLY                              equ     8

ATOM_FLAG_GLOBAL                                equ     02H

BASE_SEARCH_PATH_ENABLE_SAFE_SEARCHMODE         equ     01H
BASE_SEARCH_PATH_DISABLE_SAFE_SEARCHMODE        equ     010000H
BASE_SEARCH_PATH_PERMANENT                      equ     08000H
BASE_SEARCH_PATH_INVALID_FLAGS                  equ     <not 018001H>

EXPAND_LOCAL_DRIVES                             equ     1

RESTART_MAX_CMD_LINE                            equ     1024
RESTART_NO_CRASH                                equ     1
RESTART_NO_HANG                                 equ     2
RESTART_NO_PATCH                                equ     4

RESTART_NO_REBOOT                               equ     8
RECOVERY_DEFAULT_PING_INTERVAL                  equ     5000
RECOVERY_MAX_PING_INTERVAL                      equ     (5*60*1000)

PSP_DEFAULT                                     equ     000000000H
PSP_DLGINDIRECT                                 equ     000000001H
PSP_USEHICON                                    equ     000000002H
PSP_USEICONID                                   equ     000000004H
PSP_USETITLE                                    equ     000000008H
PSP_RTLREADING                                  equ     000000010H
PSP_HASHELP                                     equ     000000020H
PSP_USEREFPARENT                                equ     000000040H
PSP_USECALLBACK                                 equ     000000080H
PSP_PREMATURE                                   equ     000000400H
PSP_HIDEHEADER                                  equ     000000800H
PSP_USEHEADERTITLE                              equ     000001000H
PSP_USEHEADERSUBTITLE                           equ     000002000H

PSPCB_ADDREF                                    equ     0
PSPCB_RELEASE                                   equ     1
PSPCB_CREATE                                    equ     2

PSH_DEFAULT                                     equ     000000000H
PSH_PROPTITLE                                   equ     000000001H
PSH_USEHICON                                    equ     000000002H
PSH_USEICONID                                   equ     000000004H
PSH_PROPSHEETPAGE                               equ     000000008H
PSH_WIZARDHASFINISH                             equ     000000010H
PSH_WIZARD                                      equ     000000020H
PSH_USEPSTARTPAGE                               equ     000000040H
PSH_NOAPPLYNOW                                  equ     000000080H
PSH_USECALLBACK                                 equ     000000100H
PSH_HASHELP                                     equ     000000200H
PSH_MODELESS                                    equ     000000400H
PSH_RTLREADING                                  equ     000000800H
PSH_WIZARDCONTEXTHELP                           equ     000001000H
PSH_WIZARD_LITE                                 equ     000400000H
PSH_NOCONTEXTHELP                               equ     002000000H

PSH_WIZARD97                                    equ     000002000H
PSH_WATERMARK                                   equ     000008000H
PSH_USEHBMWATERMARK                             equ     000010000H
PSH_USEHPLWATERMARK                             equ     000020000H
PSH_STRETCHWATERMARK                            equ     000040000H
PSH_HEADER                                      equ     000080000H
PSH_USEHBMHEADER                                equ     000100000H
PSH_USEPAGELANG                                 equ     000200000H

PSCB_INITIALIZED                                equ     1
PSCB_PRECREATE                                  equ     2

PSN_FIRST                                       equ     (0-200)
PSN_LAST                                        equ     (0-299)

PSN_SETACTIVE                                   equ     (PSN_FIRST-0)
PSN_KILLACTIVE                                  equ     (PSN_FIRST-1)
PSN_APPLY                                       equ     (PSN_FIRST-2)
PSN_RESET                                       equ     (PSN_FIRST-3)
PSN_HELP                                        equ     (PSN_FIRST-5)
PSN_WIZBACK                                     equ     (PSN_FIRST-6)
PSN_WIZNEXT                                     equ     (PSN_FIRST-7)
PSN_WIZFINISH                                   equ     (PSN_FIRST-8)
PSN_QUERYCANCEL                                 equ     (PSN_FIRST-9)
PSN_GETOBJECT                                   equ     (PSN_FIRST-10)
PSN_TRANSLATEACCELERATOR                        equ     (PSN_FIRST-12)
PSN_QUERYINITIALFOCUS                           equ     (PSN_FIRST-13)

PSNRET_NOERROR                                  equ     0
PSNRET_INVALID                                  equ     1
PSNRET_INVALID_NOCHANGEPAGE                     equ     2
PSNRET_MESSAGEHANDLED                           equ     3

PSM_SETCURSEL                                   equ     (WM_USER+101)
PSM_REMOVEPAGE                                  equ     (WM_USER+102)
PSM_ADDPAGE                                     equ     (WM_USER+103)
PSM_CHANGED                                     equ     (WM_USER+104)
PSM_RESTARTWINDOWS                              equ     (WM_USER+105)
PSM_REBOOTSYSTEM                                equ     (WM_USER+106)
PSM_CANCELTOCLOSE                               equ     (WM_USER+107)
PSM_QUERYSIBLINGS                               equ     (WM_USER+108)
PSM_UNCHANGED                                   equ     (WM_USER+109)
PSM_APPLY                                       equ     (WM_USER+110)
PSM_SETTITLEA                                   equ     (WM_USER+111)
PSM_SETWIZBUTTONS                               equ     (WM_USER+112)
PSM_PRESSBUTTON                                 equ     (WM_USER+113)
PSM_SETCURSELID                                 equ     (WM_USER+114)
PSM_SETFINISHTEXTA                              equ     (WM_USER+115)
PSM_GETTABCONTROL                               equ     (WM_USER+116)
PSM_ISDIALOGMESSAGE                             equ     (WM_USER+117)
PSM_GETCURRENTPAGEHWND                          equ     (WM_USER+118)
PSM_SETTITLEW                                   equ     (WM_USER+120)
PSM_SETFINISHTEXTW                              equ     (WM_USER+121)
PSM_SETHEADERTITLEA                             equ     (WM_USER+125)
PSM_SETHEADERTITLEW                             equ     (WM_USER+126)
PSM_SETHEADERSUBTITLEA                          equ     (WM_USER+127)
PSM_SETHEADERSUBTITLEW                          equ     (WM_USER+128)
PSM_HWNDTOINDEX                                 equ     (WM_USER+129)
PSM_INDEXTOHWND                                 equ     (WM_USER+130)
PSM_PAGETOINDEX                                 equ     (WM_USER+131)
PSM_INDEXTOPAGE                                 equ     (WM_USER+132)
PSM_IDTOINDEX                                   equ     (WM_USER+133)
PSM_INDEXTOID                                   equ     (WM_USER+134)
PSM_GETRESULT                                   equ     (WM_USER+135)
PSM_RECALCPAGESIZES                             equ     (WM_USER+136)

PSWIZB_BACK                                     equ     000000001H
PSWIZB_NEXT                                     equ     000000002H
PSWIZB_FINISH                                   equ     000000004H
PSWIZB_DISABLEDFINISH                           equ     000000008H

PSBTN_BACK                                      equ     0
PSBTN_NEXT                                      equ     1
PSBTN_FINISH                                    equ     2
PSBTN_OK                                        equ     3
PSBTN_APPLYNOW                                  equ     4
PSBTN_CANCEL                                    equ     5
PSBTN_HELP                                      equ     6
PSBTN_MAX                                       equ     6

ID_PSRESTARTWINDOWS                             equ     02H
ID_PSREBOOTSYSTEM                               equ     <ID_PSRESTARTWINDOWS or 01H>

WIZ_CXDLG                                       equ     276
WIZ_CYDLG                                       equ     140

WIZ_CXBMP                                       equ     80

WIZ_BODYX                                       equ     92
WIZ_BODYCX                                      equ     184

PROP_SM_CXDLG                                   equ     212
PROP_SM_CYDLG                                   equ     188

PROP_MED_CXDLG                                  equ     227
PROP_MED_CYDLG                                  equ     215

PROP_LG_CXDLG                                   equ     252
PROP_LG_CYDLG                                   equ     218

ADAPTER_NAME_LENGTH                             equ     256
ADAPTER_DESCRIPTION_LENGTH                      equ     256

AP_NAME_LENGTH                                  equ     256

DOT11_OI_MAX_LENGTH                             equ     5
DOT11_OI_MIN_LENGTH                             equ     3

DOT11_SSID_MAX_LENGTH                           equ     32
DOT11_RATE_SET_MAX_LENGTH                       equ     126

WLAN_MAX_NAME_LENGTH                            equ     L2_PROFILE_MAX_NAME_LENGTH

WLAN_MAX_PHY_TYPE_NUMBER                        equ     8

WLAN_MAX_PHY_INDEX                              equ    64

PARMNUM_ALL                                     equ     0

;====================================== rasapi32 ==========================================;
RASBASE                                         equ     600
SUCCESS                                         equ     0

PENDING                                         equ     (RASBASE+0)
ERROR_INVALID_PORT_HANDLE                       equ     (RASBASE+1)
ERROR_PORT_ALREADY_OPEN                         equ     (RASBASE+2)
ERROR_BUFFER_TOO_SMALL                          equ     (RASBASE+3)
ERROR_WRONG_INFO_SPECIFIED                      equ     (RASBASE+4)
ERROR_CANNOT_SET_PORT_INFO                      equ     (RASBASE+5)
ERROR_PORT_NOT_CONNECTED                        equ     (RASBASE+6)
ERROR_EVENT_INVALID                             equ     (RASBASE+7)
ERROR_DEVICE_DOES_NOT_EXIST                     equ     (RASBASE+8)
ERROR_DEVICETYPE_DOES_NOT_EXIST                 equ     (RASBASE+9)
ERROR_BUFFER_INVALID                            equ     (RASBASE+10)
ERROR_ROUTE_NOT_AVAILABLE                       equ     (RASBASE+11)
ERROR_ROUTE_NOT_ALLOCATED                       equ     (RASBASE+12)
ERROR_INVALID_COMPRESSION_SPECIFIED             equ     (RASBASE+13)
ERROR_OUT_OF_BUFFERS                            equ     (RASBASE+14)
ERROR_PORT_NOT_FOUND                            equ     (RASBASE+15)
ERROR_ASYNC_REQUEST_PENDING                     equ     (RASBASE+16)
ERROR_ALREADY_DISCONNECTING                     equ     (RASBASE+17)
ERROR_PORT_NOT_OPEN                             equ     (RASBASE+18)
ERROR_PORT_DISCONNECTED                         equ     (RASBASE+19)
ERROR_NO_ENDPOINTS                              equ     (RASBASE+20)
ERROR_CANNOT_OPEN_PHONEBOOK                     equ     (RASBASE+21)
ERROR_CANNOT_LOAD_PHONEBOOK                     equ     (RASBASE+22)
ERROR_CANNOT_FIND_PHONEBOOK_ENTRY               equ     (RASBASE+23)
ERROR_CANNOT_WRITE_PHONEBOOK                    equ     (RASBASE+24)
ERROR_CORRUPT_PHONEBOOK                         equ     (RASBASE+25)
ERROR_CANNOT_LOAD_STRING                        equ     (RASBASE+26)
ERROR_KEY_NOT_FOUND                             equ     (RASBASE+27)
ERROR_DISCONNECTION                             equ     (RASBASE+28)
ERROR_REMOTE_DISCONNECTION                      equ     (RASBASE+29)
ERROR_HARDWARE_FAILURE                          equ     (RASBASE+30)
ERROR_USER_DISCONNECTION                        equ     (RASBASE+31)
ERROR_INVALID_SIZE                              equ     (RASBASE+32)
ERROR_PORT_NOT_AVAILABLE                        equ     (RASBASE+33)
ERROR_CANNOT_PROJECT_CLIENT                     equ     (RASBASE+34)
ERROR_UNKNOWN                                   equ     (RASBASE+35)
ERROR_WRONG_DEVICE_ATTACHED                     equ     (RASBASE+36)
ERROR_BAD_STRING                                equ     (RASBASE+37)
ERROR_REQUEST_TIMEOUT                           equ     (RASBASE+38)
ERROR_CANNOT_GET_LANA                           equ     (RASBASE+39)
ERROR_NETBIOS_ERROR                             equ     (RASBASE+40)
ERROR_SERVER_OUT_OF_RESOURCES                   equ     (RASBASE+41)
ERROR_NAME_EXISTS_ON_NET                        equ     (RASBASE+42)
ERROR_SERVER_GENERAL_NET_FAILURE                equ     (RASBASE+43)
WARNING_MSG_ALIAS_NOT_ADDED                     equ     (RASBASE+44)
ERROR_AUTH_INTERNAL                             equ     (RASBASE+45)
ERROR_RESTRICTED_LOGON_HOURS                    equ     (RASBASE+46)
ERROR_ACCT_DISABLED                             equ     (RASBASE+47)
ERROR_PASSWD_EXPIRED                            equ     (RASBASE+48)
ERROR_NO_DIALIN_PERMISSION                      equ     (RASBASE+49)
ERROR_SERVER_NOT_RESPONDING                     equ     (RASBASE+50)
ERROR_FROM_DEVICE                               equ     (RASBASE+51)
ERROR_UNRECOGNIZED_RESPONSE                     equ     (RASBASE+52)
ERROR_MACRO_NOT_FOUND                           equ     (RASBASE+53)
ERROR_MACRO_NOT_DEFINED                         equ     (RASBASE+54)
ERROR_MESSAGE_MACRO_NOT_FOUND                   equ     (RASBASE+55)
ERROR_DEFAULTOFF_MACRO_NOT_FOUND                equ     (RASBASE+56)
ERROR_FILE_COULD_NOT_BE_OPENED                  equ     (RASBASE+57)
ERROR_DEVICENAME_TOO_LONG                       equ     (RASBASE+58)
ERROR_DEVICENAME_NOT_FOUND                      equ     (RASBASE+59)
ERROR_NO_RESPONSES                              equ     (RASBASE+60)
ERROR_NO_COMMAND_FOUND                          equ     (RASBASE+61)
ERROR_WRONG_KEY_SPECIFIED                       equ     (RASBASE+62)
ERROR_UNKNOWN_DEVICE_TYPE                       equ     (RASBASE+63)
ERROR_ALLOCATING_MEMORY                         equ     (RASBASE+64)
ERROR_PORT_NOT_CONFIGURED                       equ     (RASBASE+65)
ERROR_DEVICE_NOT_READY                          equ     (RASBASE+66)
ERROR_READING_INI_FILE                          equ     (RASBASE+67)
ERROR_NO_CONNECTION                             equ     (RASBASE+68)
ERROR_BAD_USAGE_IN_INI_FILE                     equ     (RASBASE+69)
ERROR_READING_SECTIONNAME                       equ     (RASBASE+70)
ERROR_READING_DEVICETYPE                        equ     (RASBASE+71)
ERROR_READING_DEVICENAME                        equ     (RASBASE+72)
ERROR_READING_USAGE                             equ     (RASBASE+73)
ERROR_READING_MAXCONNECTBPS                     equ     (RASBASE+74)
ERROR_READING_MAXCARRIERBPS                     equ     (RASBASE+75)
ERROR_LINE_BUSY                                 equ     (RASBASE+76)
ERROR_VOICE_ANSWER                              equ     (RASBASE+77)
ERROR_NO_ANSWER                                 equ     (RASBASE+78)
ERROR_NO_CARRIER                                equ     (RASBASE+79)
ERROR_NO_DIALTONE                               equ     (RASBASE+80)
ERROR_IN_COMMAND                                equ     (RASBASE+81)
ERROR_WRITING_SECTIONNAME                       equ     (RASBASE+82)
ERROR_WRITING_DEVICETYPE                        equ     (RASBASE+83)
ERROR_WRITING_DEVICENAME                        equ     (RASBASE+84)
ERROR_WRITING_MAXCONNECTBPS                     equ     (RASBASE+85)
ERROR_WRITING_MAXCARRIERBPS                     equ     (RASBASE+86)
ERROR_WRITING_USAGE                             equ     (RASBASE+87)
ERROR_WRITING_DEFAULTOFF                        equ     (RASBASE+88)
ERROR_READING_DEFAULTOFF                        equ     (RASBASE+89)
ERROR_EMPTY_INI_FILE                            equ     (RASBASE+90)
ERROR_AUTHENTICATION_FAILURE                    equ     (RASBASE+91)
ERROR_PORT_OR_DEVICE                            equ     (RASBASE+92)
ERROR_NOT_BINARY_MACRO                          equ     (RASBASE+93)
ERROR_DCB_NOT_FOUND                             equ     (RASBASE+94)
ERROR_STATE_MACHINES_NOT_STARTED                equ     (RASBASE+95)
ERROR_STATE_MACHINES_ALREADY_STARTED            equ     (RASBASE+96)
ERROR_PARTIAL_RESPONSE_LOOPING                  equ     (RASBASE+97)
ERROR_UNKNOWN_RESPONSE_KEY                      equ     (RASBASE+98)
ERROR_RECV_BUF_FULL                             equ     (RASBASE+99)
ERROR_CMD_TOO_LONG                              equ     (RASBASE+100)
ERROR_UNSUPPORTED_BPS                           equ     (RASBASE+101)
ERROR_UNEXPECTED_RESPONSE                       equ     (RASBASE+102)
ERROR_INTERACTIVE_MODE                          equ     (RASBASE+103)
ERROR_BAD_CALLBACK_NUMBER                       equ     (RASBASE+104)
ERROR_INVALID_AUTH_STATE                        equ     (RASBASE+105)
ERROR_WRITING_INITBPS                           equ     (RASBASE+106)
ERROR_X25_DIAGNOSTIC                            equ     (RASBASE+107)
ERROR_ACCT_EXPIRED                              equ     (RASBASE+108)
ERROR_CHANGING_PASSWORD                         equ     (RASBASE+109)
ERROR_OVERRUN                                   equ     (RASBASE+110)
ERROR_RASMAN_CANNOT_INITIALIZE                  equ     (RASBASE+111)
ERROR_BIPLEX_PORT_NOT_AVAILABLE                 equ     (RASBASE+112)
ERROR_NO_ACTIVE_ISDN_LINES                      equ     (RASBASE+113)
ERROR_NO_ISDN_CHANNELS_AVAILABLE                equ     (RASBASE+114)
ERROR_TOO_MANY_LINE_ERRORS                      equ     (RASBASE+115)
ERROR_IP_CONFIGURATION                          equ     (RASBASE+116)
ERROR_NO_IP_ADDRESSES                           equ     (RASBASE+117)
ERROR_PPP_TIMEOUT                               equ     (RASBASE+118)
ERROR_PPP_REMOTE_TERMINATED                     equ     (RASBASE+119)
ERROR_PPP_NO_PROTOCOLS_CONFIGURED               equ     (RASBASE+120)
ERROR_PPP_NO_RESPONSE                           equ     (RASBASE+121)
ERROR_PPP_INVALID_PACKET                        equ     (RASBASE+122)
ERROR_PHONE_NUMBER_TOO_LONG                     equ     (RASBASE+123)
ERROR_IPXCP_NO_DIALOUT_CONFIGURED               equ     (RASBASE+124)
ERROR_IPXCP_NO_DIALIN_CONFIGURED                equ     (RASBASE+125)
ERROR_IPXCP_DIALOUT_ALREADY_ACTIVE              equ     (RASBASE+126)
ERROR_ACCESSING_TCPCFGDLL                       equ     (RASBASE+127)
ERROR_NO_IP_RAS_ADAPTER                         equ     (RASBASE+128)
ERROR_SLIP_REQUIRES_IP                          equ     (RASBASE+129)
ERROR_PROJECTION_NOT_COMPLETE                   equ     (RASBASE+130)
ERROR_PROTOCOL_NOT_CONFIGURED                   equ     (RASBASE+131)
ERROR_PPP_NOT_CONVERGING                        equ     (RASBASE+132)
ERROR_PPP_CP_REJECTED                           equ     (RASBASE+133)
ERROR_PPP_LCP_TERMINATED                        equ     (RASBASE+134)
ERROR_PPP_REQUIRED_ADDRESS_REJECTED             equ     (RASBASE+135)
ERROR_PPP_NCP_TERMINATED                        equ     (RASBASE+136)
ERROR_PPP_LOOPBACK_DETECTED                     equ     (RASBASE+137)
ERROR_PPP_NO_ADDRESS_ASSIGNED                   equ     (RASBASE+138)
ERROR_CANNOT_USE_LOGON_CREDENTIALS              equ     (RASBASE+139)
ERROR_TAPI_CONFIGURATION                        equ     (RASBASE+140)
ERROR_NO_LOCAL_ENCRYPTION                       equ     (RASBASE+141)
ERROR_NO_REMOTE_ENCRYPTION                      equ     (RASBASE+142)
ERROR_REMOTE_REQUIRES_ENCRYPTION                equ     (RASBASE+143)
ERROR_IPXCP_NET_NUMBER_CONFLICT                 equ     (RASBASE+144)
ERROR_INVALID_SMM                               equ     (RASBASE+145)
ERROR_SMM_UNINITIALIZED                         equ     (RASBASE+146)
ERROR_NO_MAC_FOR_PORT                           equ     (RASBASE+147)
ERROR_SMM_TIMEOUT                               equ     (RASBASE+148)
ERROR_BAD_PHONE_NUMBER                          equ     (RASBASE+149)
ERROR_WRONG_MODULE                              equ     (RASBASE+150)
ERROR_INVALID_CALLBACK_NUMBER                   equ     (RASBASE+151)
ERROR_SCRIPT_SYNTAX                             equ     (RASBASE+152)
RASBASEEND                                      equ     (RASBASE+152)

CLSCTX_ACTIVATE_32_BIT_SERVER                   equ     00040000H
CLSCTX_ACTIVATE_64_BIT_SERVER                   equ     00080000H
CLSCTX_ACTIVATE_AAA_AS_IU                       equ     00800000H
CLSCTX_ALL                                      equ     00000007H
CLSCTX_APPCONTAINER                             equ     00400000H
CLSCTX_DISABLE_AAA                              equ     00008000H
CLSCTX_ENABLE_AAA                               equ     00010000H
CLSCTX_ENABLE_CLOAKING                          equ     00100000H
CLSCTX_ENABLE_CODE_DOWNLOAD                     equ     00002000H
CLSCTX_ESERVER_HANDLER                          equ     00000100H
CLSCTX_FROM_DEFAULT_CONTEXT                     equ     00020000H
CLSCTX_INPROC                                   equ     00000003H
CLSCTX_INPROC_HANDLER                           equ     00000002H
CLSCTX_INPROC_HANDLER16                         equ     00000020H
CLSCTX_INPROC_HANDLERX86                        equ     00000080H
CLSCTX_INPROC_SERVER                            equ     00000001H
CLSCTX_INPROC_SERVER16                          equ     00000008H
CLSCTX_INPROC_SERVERX86                         equ     00000040H
CLSCTX_LOCAL_SERVER                             equ     00000004H
CLSCTX_NO_CODE_DOWNLOAD                         equ     00000400H
CLSCTX_NO_CUSTOM_MARSHAL                        equ     00001000H
CLSCTX_NO_FAILURE_LOG                           equ     00004000H
CLSCTX_PS_DLL                                   equ     80000000H
CLSCTX_REMOTE_SERVER                            equ     00000010H
CLSCTX_RESERVED1                                equ     00000040H
CLSCTX_RESERVED2                                equ     00000080H
CLSCTX_RESERVED3                                equ     00000100H
CLSCTX_RESERVED4                                equ     00000200H
CLSCTX_RESERVED5                                equ     00000800H
CLSCTX_SERVER                                   equ     00000005H

;VARENUM enum
VT_EMPTY                                        equ     0000H
VT_NULL                                         equ     0001H
VT_I2                                           equ     0002H
VT_I4                                           equ     0003H
VT_R4                                           equ     0004H
VT_R8                                           equ     0005H
VT_CY                                           equ     0006H
VT_DATE                                         equ     0007H
VT_BSTR                                         equ     0008H
VT_DISPATCH                                     equ     0009H
VT_ERROR                                        equ     000AH
VT_BOOL                                         equ     000BH
VT_VARIANT                                      equ     000CH
VT_UNKNOWN                                      equ     000DH
VT_DECIMAL                                      equ     000EH
VT_I1                                           equ     0010H
VT_UI1                                          equ     0011H
VT_UI2                                          equ     0012H
VT_UI4                                          equ     0013H
VT_I8                                           equ     0014H
VT_UI8                                          equ     0015H
VT_INT                                          equ     0016H
VT_UINT                                         equ     0017H
VT_VOID                                         equ     0018H
VT_HRESULT                                      equ     0019H
VT_PTR                                          equ     001AH
VT_SAFEARRAY                                    equ     001BH
VT_CARRAY                                       equ     001CH
VT_USERDEFINED                                  equ     001DH
VT_LPSTR                                        equ     001EH
VT_LPWSTR                                       equ     001FH
VT_RECORD                                       equ     0024H
VT_INT_PTR                                      equ     0025H
VT_UINT_PTR                                     equ     0026H
VT_ARRAY                                        equ     2000H
VT_BYREF                                        equ     4000H
VT_ILLEGAL                                      equ     0FFFFH
VT_ILLEGALMASKED                                equ     0FFFH

;============================= Browse for folders =============================
BIF_RETURNONLYFSDIRS                            equ         00000001H
BIF_DONTGOBELOWDOMAIN                           equ         00000002H
BIF_STATUSTEXT                                  equ         00000004H
BIF_RETURNFSANCESTORS                           equ         00000008H
BIF_EDITBOX                                     equ         00000010H
BIF_VALIDATE                                    equ         00000020H
BIF_NEWDIALOGSTYLE                              equ         00000040H
BIF_BROWSEINCLUDEURLS                           equ         00000080H
BIF_UAHINT                                      equ         00000100H
BIF_NONEWFOLDERBUTTON                           equ         00000200H
BIF_NOTRANSLATETARGETS                          equ         00000400H
BIF_BROWSEFORCOMPUTER                           equ         00001000H
BIF_BROWSEFORPRINTER                            equ         00002000H
BIF_BROWSEINCLUDEFILES                          equ         00004000H
BIF_SHAREABLE                                   equ         00008000H
BIF_BROWSEFILEJUNCTIONS                         equ         00010000H
BIF_USENEWUI                                    equ         <BIF_EDITBOX or BIF_NEWDIALOGSTYLE>
BFFM_INITIALIZED                                equ         00000001H
BFFM_SELCHANGED                                 equ         00000002H
BFFM_VALIDATEFAILEDA                            equ         00000003H
BFFM_VALIDATEFAILEDW                            equ         00000004H
BFFM_IUNKNOWN                                   equ         00000005H
BFFM_SETSTATUSTEXTA                             equ         (WM_USER+100)
BFFM_ENABLEOK                                   equ         (WM_USER+101)
BFFM_SETSELECTIONA                              equ         (WM_USER+102)
BFFM_SETSELECTIONW                              equ         (WM_USER+103)
BFFM_SETSTATUSTEXTW                             equ         (WM_USER+104)
BFFM_SETOKTEXT                                  equ         (WM_USER+105)
BFFM_SETEXPANDED                                equ         (WM_USER+106)
CSIDL_DESKTOP                                   equ         00000H
CSIDL_INTERNET                                  equ         00001H
CSIDL_PROGRAMS                                  equ         00002H
CSIDL_CONTROLS                                  equ         00003H
CSIDL_PRINTERS                                  equ         00004H
CSIDL_PERSONAL                                  equ         00005H
CSIDL_FAVORITES                                 equ         00006H
CSIDL_STARTUP                                   equ         00007H
CSIDL_RECENT                                    equ         00008H
CSIDL_SENDTO                                    equ         00009H
CSIDL_BITBUCKET                                 equ         0000AH
CSIDL_STARTMENU                                 equ         0000BH
CSIDL_MYDOCUMENTS                               equ         CSIDL_PERSONAL
CSIDL_MYMUSIC                                   equ         0000DH
CSIDL_MYVIDEO                                   equ         0000EH
CSIDL_DESKTOPDIRECTORY                          equ         00010H
CSIDL_DRIVES                                    equ         00011H
CSIDL_NETWORK                                   equ         00012H
CSIDL_NETHOOD                                   equ         00013H
CSIDL_FONTS                                     equ         00014H
CSIDL_TEMPLATES                                 equ         00015H
CSIDL_COMMON_STARTMENU                          equ         00016H
CSIDL_COMMON_PROGRAMS                           equ         00017H
CSIDL_COMMON_STARTUP                            equ         00018H
CSIDL_COMMON_DESKTOPDIRECTORY                   equ         00019H
CSIDL_APPDATA                                   equ         0001AH
CSIDL_PRINTHOOD                                 equ         0001BH
CSIDL_LOCAL_APPDATA                             equ         0001CH
CSIDL_ALTSTARTUP                                equ         0001DH
CSIDL_COMMON_ALTSTARTUP                         equ         0001EH
CSIDL_COMMON_FAVORITES                          equ         0001FH
CSIDL_INTERNET_CACHE                            equ         00020H
CSIDL_COOKIES                                   equ         00021H
CSIDL_HISTORY                                   equ         00022H
CSIDL_COMMON_APPDATA                            equ         00023H
CSIDL_WINDOWS                                   equ         00024H
CSIDL_SYSTEM                                    equ         00025H
CSIDL_PROGRAM_FILES                             equ         00026H
CSIDL_MYPICTURES                                equ         00027H
CSIDL_PROFILE                                   equ         00028H
CSIDL_SYSTEMX86                                 equ         00029H
CSIDL_PROGRAM_FILESX86                          equ         0002AH
CSIDL_PROGRAM_FILES_COMMON                      equ         0002BH
CSIDL_PROGRAM_FILES_COMMONX86                   equ         0002CH
CSIDL_COMMON_TEMPLATES                          equ         0002DH
CSIDL_COMMON_DOCUMENTS                          equ         0002EH
CSIDL_COMMON_ADMINTOOLS                         equ         0002FH
CSIDL_ADMINTOOLS                                equ         00030H
CSIDL_CONNECTIONS                               equ         00031H
CSIDL_COMMON_MUSIC                              equ         00035H
CSIDL_COMMON_PICTURES                           equ         00036H
CSIDL_COMMON_VIDEO                              equ         00037H
CSIDL_RESOURCES                                 equ         00038H
CSIDL_RESOURCES_LOCALIZED                       equ         00039H
CSIDL_COMMON_OEM_LINKS                          equ         0003AH
CSIDL_CDBURN_AREA                               equ         0003BH
CSIDL_COMPUTERSNEARME                           equ         0003DH

CSIDL_FLAG_CREATE                               equ         08000H
CSIDL_FLAG_DONT_VERIFY                          equ         04000H
CSIDL_FLAG_NO_ALIAS                             equ         01000H
CSIDL_FLAG_PER_USER_INIT                        equ         00800H
CSIDL_FLAG_MASK                                 equ         0FF00H

#ifdef APP_UNICODE
    define PSM_SETTITLE PSM_SETTITLEW
    define PSM_SETFINISHTEXT PSM_SETFINISHTEXTW
    define PSM_SETHEADERTITLE PSM_SETHEADERTITLEW
    define PSM_SETHEADERSUBTITLE PSM_SETHEADERSUBTITLEW
	define BFFM_VALIDATEFAILED BFFM_VALIDATEFAILEDW
    define BFFM_SETSELECTION BFFM_SETSELECTIONW
    define BFFM_SETSTATUSTEXT BFFM_SETSTATUSTEXTW
#else
    define PSM_SETTITLE PSM_SETTITLEA
    define PSM_SETFINISHTEXT PSM_SETFINISHTEXTA
    define PSM_SETHEADERTITLE PSM_SETHEADERTITLEA
    define PSM_SETHEADERSUBTITLE PSM_SETHEADERSUBTITLEA
	define BFFM_VALIDATEFAILED BFFM_VALIDATEFAILEDA
    define BFFM_SETSELECTION BFFM_SETSELECTIONA
    define BFFM_SETSTATUSTEXT BFFM_SETSTATUSTEXTA
#endif

;======================================== Structures ======================================;
#ifdef APP_WIN64
    align 16
#else
    align 4
#endif

struc RECT
    left    dd    ?
    top     dd    ?
    right   dd    ?
    bottom  dd    ?
ends

struc RECTL
    left    dd    ?
    top     dd    ?
    right   dd    ?
    bottom  dd    ?
ends

struc POINT
    x   dd  ?
    y   dd  ?
ends

struc POINTL
    x   dd  ?
    y   dd  ?
ends

struc SIZEL
    x   dd  ?
    y   dd  ?
ends

struc POINTS
    x   dw  ?
    y   dw  ?
ends

struc LUID
    LowPart     dd  ?
    HighPart    dd  ?
ends

struc Unknown
    QueryInterface  xword ?
    AddRef          xword ?
    Release         xword ?
ends

struc Dispatch
    QueryInterface  xword ?
    AddRef          xword ?
    Release         xword ?
ends

struc GUID
    Data1   dd  ?
    Data2   dw  ?
    Data3   dw  ?
    Data4   rb  8
ends

struc DUMMYSTRUCTNAME
    LowPart                                     dd      ?
    HighPart                                    dd      ?
ends

struc u
    LowPart                                     dd      ?
    HighPart                                    dd      ?
ends

struct LARGE_INTEGER
    union
        DUMMYSTRUCTNAME ?
        u               ?
        QuadPart dq     ?
    endu
ends

struct ULARGE_INTEGER
    union
        DUMMYSTRUCTNAME ?
        u               ?
        QuadPart dq     ?
    endu
ends

struc STRING
    _Length         dw    ?
    MaximumLength   dw    ?
    Buffer          xword ?
ends
ANSI_STRING                                 equ STRING
OEM_STRING                                  equ STRING
PSTRING                                     equ xword
POEM_STRING                                 equ PSTRING

struc UNICODE_STRING
    _Length         dw    ?
    MaximumLength   dw    ?
    Buffer          xword ?
ends
define PUNICODE_STRING                      xword

struc DBGPARAM
    lpszName    rw  32
    rglpszZones rw  512
    ulZoneMask  dd  ?
ends

struc ACTCTXA
    cbSize                  dd    ?
    dwFlags                 dd    ?
    lpSource                xword ?
    wProcessorArchitecture  dw    ?
    wLangId                 dw    ?
    lpAssemblyDirectory     xword ?
    lpResourceName          xword ? 
    lpApplicationName       xword ?
    hModule                 xword ?
ends

struc ACTCTXW
    cbSize                  dd    ?
    dwFlags                 dd    ?
    lpSource                xword ?
    wProcessorArchitecture  dw    ?
    wLangId                 dw    ?
    lpAssemblyDirectory     dw    ?
    lpResourceName          xword ?
    lpApplicationName       xword ?
    hModule                 xword ?
ends

struc ACTCTX_SECTION_KEYED_DATA_2600
    cbSize                    dd    ?
    ulDataFormatVersion       dd    ?
    lpData                    xword ?
    ulLength                  dd    ?
    lpSectionGlobalData       xword ?
    ulSectionGlobalDataLength dd    ?
    lpSectionBase             xword ?
    ulSectionTotalLength      dd    ?
    hActCtx                   xword ?
    ulAssemblyRosterIndex     dd    ?
ends

struc ACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA
    lpInformation             xword ?
    lpSectionBase             xword ?
    ulSectionLength           dd    ?
    lpSectionGlobalDataBase   xword ?
    ulSectionGlobalDataLength dd    ?
ends

struc ACTCTX_SECTION_KEYED_DATA
    cbSize                    dd    ?
    ulDataFormatVersion       dd    ?
    lpData                    xword ?
    ulLength                  dd    ?
    lpSectionGlobalData       xword ?
    ulSectionGlobalDataLength dd    ?
    lpSectionBase             xword ?
    ulSectionTotalLength      dd    ?
    hActCtx                   xword ?
    ulAssemblyRosterIndex     dd    ?
    ulFlags                   dd    ?
    AssemblyMetadata          ACTCTX_SECTION_KEYED_DATA_ASSEMBLY_METADATA ?
ends

struc ACTIVATION_CONTEXT_BASIC_INFORMATION
   hActCtx xword ?
   dwFlags dd    ?
ends

struc FILE_BASIC_INFO
    CreationTime    LARGE_INTEGER ?
    LastAccessTime  LARGE_INTEGER ?
    LastWriteTime   LARGE_INTEGER ?
    ChangeTime      LARGE_INTEGER ?
    FileAttributes  dd            ?
ends

struc FILE_STANDARD_INFO
    AllocationSize  LARGE_INTEGER ?
    EndOfFile       LARGE_INTEGER ?
    NumberOfLinks   dd      ?
    DeletePending   dd      ?
    Directory       dd      ?
ends

struc FILE_NAME_INFO
    FileNameLength  dd ?
    FileName        dw ?
ends

struc FILE_RENAME_INFO
    ReplaceIfExists dd    ?
    RootDirectory   xword ?
    FileNameLength  dd    ?
    FileName        dw    ?
ends

struc FILE_ALLOCATION_INFO
    AllocationSize  LARGE_INTEGER ?
ends

struc FILE_END_OF_FILE_INFO
    EndOfFile   LARGE_INTEGER ?
ends

struc FILE_STREAM_INFO
    NextEntryOffset      dd     ?
    StreamNameLength     dd     ?
    StreamSize           LARGE_INTEGER ?
    StreamAllocationSize LARGE_INTEGER ?
    StreamName           dw  ?
ends

struc FILE_COMPRESSION_INFO
    CompressedFileSize   LARGE_INTEGER ?
    CompressionFormat    dw   ?
    CompressionUnitShift db   ?
    ChunkShift           db   ?
    ClusterShift         db   ?
    Reserved             db   3
ends

struc FILE_ATTRIBUTE_TAG_INFO
    FileAttributes  dd  ?
    ReparseTag      dd  ?
ends

struc FILE_DISPOSITION_INFO
    DeleteFile  dd ?
ends

struc FILE_ID_BOTH_DIR_INFO
    NextEntryOffset dd      ?
    FileIndex       dd      ?
    CreationTime    LARGE_INTEGER ?
    LastAccessTime  LARGE_INTEGER ?
    LastWriteTime   LARGE_INTEGER ?
    ChangeTime      LARGE_INTEGER ?
    EndOfFile       LARGE_INTEGER ?
    AllocationSize  LARGE_INTEGER ?
    FileAttributes  dd      ?
    FileNameLength  dd      ?
    EaSize          dd      ?
    ShortNameLength db      ?
    ShortName       dw      12
    FileId          LARGE_INTEGER ?
    FileName        rw      1
ends

struc FILE_FULL_DIR_INFO
    NextEntryOffset dd  ?
    FileIndex       dd  ?
    CreationTime    LARGE_INTEGER ?
    LastAccessTime  LARGE_INTEGER ?
    LastWriteTime   LARGE_INTEGER ?
    ChangeTime      LARGE_INTEGER ?
    EndOfFile       LARGE_INTEGER ?
    AllocationSize  LARGE_INTEGER ?
    FileAttributes  dd  ?
    FileNameLength  dd  ?
    EaSize          dd  ?
    FileName        rw  1
ends

struc FILE_IO_PRIORITY_HINT_INFO
    PriorityHint dd  ?
ends

struc FILE_ID_128
    Identifier  rb 16
ends

struc FILE_ID_DESCRIPTOR
    dwSize      dd    ?
    _Type       xword ?
    union
        FileId  LARGE_INTEGER ?
        #if NTDDI_VERSION >= NTDDI_VISTA
            ObjectId    GUID ?
            #if NTDDI_VERSION >= NTDDI_WIN8
                ExtendedFileId FILE_ID_128 ?
            #endif
        #endif
    endu
ends

struc WIN32_FIND_STREAM_DATA
    StreamSize  LARGE_INTEGER ?
    cStreamName rw  (MAX_PATH+36)
ends

struc STARTUPINFOA
    cb              dd    ?
    lpReserved      xword ?
    lpDesktop       xword ?
    lpTitle         xword ?
    dwX             dd    ?
    dwY             dd    ?
    dwXSize         dd    ?
    dwYSize         dd    ?
    dwXCountChars   dd    ?
    dwYCountChars   dd    ?
    dwFillAttribute dd    ?
    dwFlags         dd    ?
    wShowWindow     dw    ?
    cbReserved2     dw    ?
    lpReserved2     xword ?
    hStdInput       xword ?
    hStdOutput      xword ?
    hStdError       xword ?
ends

struc STARTUPINFOW
    cb              dd    ?
    lpReserved      xword ?
    lpDesktop       xword ?
    lpTitle         xword ?
    dwX             dd    ?
    dwY             dd    ?
    dwXSize         dd    ?
    dwYSize         dd    ?
    dwXCountChars   dd    ?
    dwYCountChars   dd    ?
    dwFillAttribute dd    ?
    dwFlags         dd    ?
    wShowWindow     dw    ?
    cbReserved2     dw    ?
    lpReserved2     xword ?
    hStdInput       xword ?
    hStdOutput      xword ?
    hStdError       xword ?
ends

struc STARTUPINFOEXA
    StartupInfo     STARTUPINFOA ?
    lpAttributeList xword   ?
ends

struc STARTUPINFOEXW
    StartupInfo     STARTUPINFOW ?
    lpAttributeList xword   ?
ends

struc UMS_SCHEDULER_STARTUP_INFO
   UmsVersion      dd    ?
   CompletionList  xword ?
   SchedulerProc   xword ?
   SchedulerParam  xword ?
ends

struc UMS_SYSTEM_THREAD_INFORMATION
    UmsVersion           dd ?
    IsUmsSchedulerThread dd ?
    IsUmsWorkerThread    dd ?
ends

struc COPYFILE2_EXTENDED_PARAMETERS
    dwSize              dd    ?
    dwCopyFlags         dd    ?
    pfCancel            xword ?
    pProgressRoutine    xword ?
    pvCallbackContext   xword ?
ends

struc FILE_ALIGNMENT_INFO
    AlignmentRequirement dd ?
ends

struc FILE_STORAGE_INFO
    LogicalBytesPerSector                dd  ?
    PhysicalBytesPerSectorForAtomicity   dd  ?
    PhysicalBytesPerSectorForPerformance dd  ?
    FileSystemEffectivePhysicalBytesPerSectorForAtomicity dd ?
    Flags                                dd  ?
    ByteOffsetForSectorAlignment         dd  ?
    ByteOffsetForPartitionAlignment      dd  ?
ends

struc FILE_ID_INFO
    VolumeSerialNumber  dq  ?
    FileId              FILE_ID_128 ?
ends

struc FILE_ID_EXTD_DIR_INFO
    NextEntryOffset     dd  ?
    FileIndex           dd  ?
    CreationTime        LARGE_INTEGER ? 
    LastAccessTime      LARGE_INTEGER ? 
    LastWriteTime       LARGE_INTEGER ? 
    ChangeTime          LARGE_INTEGER ? 
    EndOfFile           LARGE_INTEGER ? 
    AllocationSize      LARGE_INTEGER ? 
    FileAttributes      dd  ?
    FileNameLength      dd  ?
    EaSize              dd  ?
    ReparsePointTag     dd  ?
    FileId              FILE_ID_128 ?
    FileName            rw  1
ends

struc OPERATION_START_PARAMETERS
    Version     dd  ?
    OperationId dd  ?
    Flags       dd  ?
ends

struc OPERATION_END_PARAMETERS
    Version     dd  ?
    OperationId dd  ?
    Flags       dd  ?
ends

struc CPINFO
    MaxCharSize dd  ?
    DefaultChar rb  MAX_DEFAULTCHAR
    LeadByte    rb  MAX_LEADBYTES
ends

struc CPINFOEXA
    MaxCharSize         dd  ?
    DefaultChar         rb  MAX_DEFAULTCHAR
    LeadByte            rb  MAX_LEADBYTES
    UnicodeDefaultChar  dw  ?
    CodePage            dd  ?
    CodePageName        rb  MAX_PATH
ends

struc CPINFOEXW
    MaxCharSize         dd  ?
    DefaultChar         rb  MAX_DEFAULTCHAR
    LeadByte            rb  MAX_LEADBYTES
    UnicodeDefaultChar  dw  ?
    CodePage            dd  ?
    CodePageName        rw  MAX_PATH
ends

struc NUMBERFMTA
    NumDigits       dd    ?
    LeadingZero     dd    ?
    Grouping        dd    ?
    lpDecimalSep    xword ?
    lpThousandSep   xword ?
    NegativeOrder   dd    ?
ends

struc NUMBERFMTW
    NumDigits       dd    ?
    LeadingZero     dd    ?
    Grouping        dd    ?
    lpDecimalSep    xword ?
    lpThousandSep   xword ?
    NegativeOrder   dd    ?
ends

struc CURRENCYFMTA
    NumDigits        dd    ?
    LeadingZero      dd    ?
    Grouping         dd    ?
    lpDecimalSep     xword ?
    lpThousandSep    xword ?
    NegativeOrder    dd    ? 
    PositiveOrder    dd    ?
    lpCurrencySymbol xword ?
ends

struc CURRENCYFMTW
    NumDigits        dd    ?
    LeadingZero      dd    ?
    Grouping         dd    ?
    lpDecimalSep     xword ?
    lpThousandSep    xword ?
    NegativeOrder    dd    ?
    PositiveOrder    dd    ?
    lpCurrencySymbol xword ?
ends

struc NLSVERSIONINFO
    dwNLSVersionInfoSize    dd   ?
    dwNLSVersion            dd   ?
    dwDefinedVersion        dd   ?
    #if NTDDI_VERSION >= NTDDI_WIN8
        dwEffectiveId       dd   ?
        guidCustomVersion   GUID ?
    #endif
ends

struc NLSVERSIONINFOEX
    dwNLSVersionInfoSize    dd   ?
    dwNLSVersion            dd   ?
    dwDefinedVersion        dd   ?
    dwEffectiveId           dd   ?
    guidCustomVersion       GUID ?
ends

struc FILEMUIINFO
    dwSize               dd ?
    dwVersion            dd ?
    dwFileType           dd ?
    pChecksum            rb 16
    pServiceChecksum     rb 16
    dwLanguageNameOffset dd ?
    dwTypeIDMainSize     dd ?
    dwTypeIDMainOffset   dd ?
    dwTypeNameMainOffset dd ?
    dwTypeIDMUISize      dd ?
    dwTypeIDMUIOffset    dd ?
    dwTypeNameMUIOffset  dd ?
    abBuffer             rb 8
ends

struc OVERLAPPED
    Internal     xword ?
    InternalHigh xword ?
    Pointer      xword ?
    hEvent       xword ?
ends

struc OVERLAPPED_ENTRY
    lpCompletionKey xword ?
    lpOverlapped    xword ?
    Internal        xword ?
    dwNumberOfBytesTransferred dd ?
ends

struc SECURITY_ATTRIBUTES
    nLength              dd    ?
    lpSecurityDescriptor xword ?
    bInheritHandle       dd    ?
ends

struc PROCESS_INFORMATION
    hProcess        xword ?
    hThread         xword ?
    dwProcessId     dd    ?
    dwThreadId      dd    ?
ends

struc FILETIME
    dwLowDateTime   dd  ?
    dwHighDateTime  dd  ?
ends

struc SYSTEMTIME
    wYear           dw  ?
    wMonth          dw  ?
    wDayOfWeek      dw  ?
    wDay            dw  ?
    wHour           dw  ?
    wMinute         dw  ?
    wSecond         dw  ?
    wMilliseconds   dw  ?
ends

struc COMMPROP
    wPacketLength       dw  ?
    wPacketVersion      dw  ?
    dwServiceMask       dd  ?
    dwReserved1         dd  ?
    dwMaxTxQueue        dd  ?
    dwMaxRxQueue        dd  ?
    dwMaxBaud           dd  ?
    dwProvSubType       dd  ?
    dwProvCapabilities  dd  ?
    dwSettableParams    dd  ?
    dwSettableBaud      dd  ?
    wSettableData       dw  ?
    wSettableStopParity dw  ?
    dwCurrentTxQueue    dd  ?
    dwCurrentRxQueue    dd  ?
    dwProvSpec1         dd  ?
    dwProvSpec2         dd  ?
    wcProvChar          dw  ?
ends

struc COMSTAT
    fCtsHold    dd  ?
    fDsrHold    dd  ?
    fRlsdHold   dd  ?
    fXoffHold   dd  ?
    fXoffSent   dd  ?
    fEof        dd  ?
    fTxim       dd  ?
    fReserved   dd  ?
    cbInQue     dd  ?
    cbOutQue    dd  ?
ends

struc DCB
    DCBlength   dd     ?
    BaudRate    dd     ?
    fbits       dd     ?
    wReserved   dw     ?
    XonLim      dw     ?
    XoffLim     dw     ?
    ByteSize    db     ?
    Parity      db     ?
    StopBits    db     ?
    XonChar     db     ?
    XoffChar    db     ?
    ErrorChar   db     ?
    EofChar     db     ?
    EvtChar     db     ?
    wReserved1  dw     ?
ends

struc COMMTIMEOUTS
    ReadIntervalTimeout         dd  ?
    ReadTotalTimeoutMultiplier  dd  ?
    ReadTotalTimeoutConstant    dd  ?
    WriteTotalTimeoutMultiplier dd  ?
    WriteTotalTimeoutConstant   dd  ?
ends

struc COMMCONFIG
    dwSize              dd  ?
    wVersion            dw  ?
    wReserved           dw  ?
    dcb                 DCB ?
    dwProviderSubType   dd  ?
    dwProviderOffset    dd  ?
    dwProviderSize      dd  ?
    wcProviderData      dw  ?
ends

struc SYSTEM_INFO
    wProcessorArchitecture          dw    ?
    wReserved                       dw    ?
    dwPageSize                      dd    ?
    lpMinimumApplicationAddress     xword ?
    lpMaximumApplicationAddress     xword ?
    dwActiveProcessorMask           xword ?
    dwNumberOfProcessors            dd    ?
    dwProcessorType                 dd    ?
    dwAllocationGranularity         dd    ?
    wProcessorLevel                 dw    ?
    wProcessorRevision              dw    ?
ends

struc MEMORYSTATUS
    dwLength        dd    ?
    dwMemoryLoad    dd    ?
    dwTotalPhys     xword ?
    dwAvailPhys     xword ?
    dwTotalPageFile xword ?
    dwAvailPageFile xword ?
    dwTotalVirtual  xword ?
    dwAvailVirtual  xword ?
ends

struc EXCEPTION_RECORD
    ExceptionCode        dd    ?
    ExceptionFlags       dd    ?
    ExceptionRecord      xword ?
    ExceptionAddress     xword ?
    NumberParameters     dd    ?
    #ifdef APP_WIN64
        ExceptionInformation rq EXCEPTION_MAXIMUM_PARAMETERS
    #else
        ExceptionInformation rd EXCEPTION_MAXIMUM_PARAMETERS
    #endif
ends
define PEXCEPTION_RECORD                        xword

struc EXCEPTION_DEBUG_INFO
    ExceptionRecord EXCEPTION_RECORD ?
    dwFirstChance   dd  ?
ends

struc CREATE_THREAD_DEBUG_INFO
    hThread             xword ?
    lpThreadLocalBase   xword ?
    lpStartAddress      xword ?
ends

struc CREATE_PROCESS_DEBUG_INFO
    hFile                   xword ?
    hProcess                xword ?
    hThread                 xword ?
    lpBaseOfImage           xword ?
    dwDebugInfoFileOffset   dd    ?
    nDebugInfoSize          dd    ?
    lpThreadLocalBase       xword ?
    lpStartAddress          xword ?
    lpImageName             xword ?
    fUnicode                dw    ?
ends

struc EXIT_THREAD_DEBUG_INFO
    dwExitCode  dd  ?
ends

struc EXIT_PROCESS_DEBUG_INFO
    dwExitCode  dd  ?
ends

struc LOAD_DLL_DEBUG_INFO
    hFile                   xword ?
    lpBaseOfDll             xword ?
    dwDebugInfoFileOffset   dd    ?
    nDebugInfoSize          dd    ?
    lpImageName             xword ?
    fUnicode                dw    ?
ends

struc UNLOAD_DLL_DEBUG_INFO
    lpBaseOfDll xword ?
ends

struc OUTPUT_DEBUG_STRING_INFO
    lpDebugStringData   xword ?
    fUnicode            dw    ?
    nDebugStringLength  dw    ?
ends

struc RIP_INFO
    dwError     dd  ?
    dwType      dd  ?
ends

struc DEBUG_EVENT
    dwDebugEventCode    dd  ?
    dwProcessId         dd  ?
    dwThreadId          dd  ?
    union
        Exception         EXCEPTION_DEBUG_INFO ?
        CreateThread      CREATE_THREAD_DEBUG_INFO ?
        CreateProcessInfo CREATE_PROCESS_DEBUG_INFO ?
        ExitThread        EXIT_THREAD_DEBUG_INFO ?
        ExitProcess       EXIT_PROCESS_DEBUG_INFO ?
        LoadDll           LOAD_DLL_DEBUG_INFO ?
        UnloadDll         UNLOAD_DLL_DEBUG_INFO ?
        DebugString       OUTPUT_DEBUG_STRING_INFO ?
        RipInfo           RIP_INFO ?
    endu
ends

OFS_MAXPATHNAME         equ     128

struc OFSTRUCT
    cBytes      db  ?
    fFixedDisk  db  ?
    nErrCode    dw  ?
    Reserved1   dw  ?
    Reserved2   dw  ?
    szPathName  rb  OFS_MAXPATHNAME
ends

struc MEMORYSTATUSEX
    dwLength                dd  ?
    dwMemoryLoad            dd  ?
    ullTotalPhys            dq  ?
    ullAvailPhys            dq  ?
    ullTotalPageFile        dq  ?
    ullAvailPageFile        dq  ?
    ullTotalVirtual         dq  ?
    ullAvailVirtual         dq  ?
    ullAvailExtendedVirtual dq  ?
ends

struc BY_HANDLE_FILE_INFORMATION
    dwFileAttributes        dd  ?
    ftCreationTime          FILETIME ?
    ftLastAccessTime        FILETIME ?
    ftLastWriteTime         FILETIME ?
    dwVolumeSerialNumber    dd  ?
    nFileSizeHigh           dd  ?
    nFileSizeLow            dd  ?
    nNumberOfLinks          dd  ?
    nFileIndexHigh          dd  ?
    nFileIndexLow           dd  ?
ends

struc TIME_ZONE_INFORMATION
    Bias            dd  ?
    StandardName    rw  32
    StandardDate    SYSTEMTIME ?
    StandardBias    dd  ?
    DaylightName    rw  32
    DaylightDate    SYSTEMTIME ?
    DaylightBias    dd  ?
ends

struc DYNAMIC_TIME_ZONE_INFORMATION
    Bias            dd  ?
    StandardName    rw  32
    StandardDate    SYSTEMTIME ? 
    StandardBias    dd  ?
    DaylightName    rw  32
    DaylightDate    SYSTEMTIME ? 
    DaylightBias    dd  ?
    TimeZoneKeyName rw  128
    DynamicDaylightTimeDisabled db  ?
ends

struc WIN32_STREAM_ID
    dwStreamId          dd  ?
    dwStreamAttributes  dd  ?
    _Size               LARGE_INTEGER ?
    dwStreamNameSize    dd  ?
    cStreamName         rw  ANYSIZE_ARRAY
ends

struc BROWSEINFOA
    hwndOwner      xword ?
    pidlRoot       xword ?
    pszDisplayName xword ?
    lpszTitle      xword ?
    ulFlags        dd    ?
    lpfn           xword ?
    lParam         xword ?
    iImage         dd    ?
ends

struc BROWSEINFOW
    hwndOwner      xword ?
    pidlRoot       xword ?
    pszDisplayName xword ?
    lpszTitle      xword ?
    ulFlags        dd    ?
    lpfn           xword ?
    lParam         xword ?
    iImage         dd    ?
ends

struc WIN32_FIND_DATAA
    dwFileAttributes   dd  ?
    ftCreationTime     FILETIME ?
    ftLastAccessTime   FILETIME ?
    ftLastWriteTime    FILETIME ?
    nFileSizeHigh      dd  ?
    nFileSizeLow       dd  ?
    dwReserved0        dd  ?
    dwReserved1        dd  ?
    cFileName          rb  MAX_PATH
    cAlternateFileName rb  14
ends

struc WIN32_FIND_DATAW
    dwFileAttributes   dd  ?
    ftCreationTime     FILETIME ?
    ftLastAccessTime   FILETIME ?
    ftLastWriteTime    FILETIME ?
    nFileSizeHigh      dd  ?
    nFileSizeLow       dd  ?
    dwReserved0        dd  ?
    dwReserved1        dd  ?
    cFileName          rw MAX_PATH
    cAlternateFileName rw 14
ends

struc WIN32_FILE_ATTRIBUTE_DATA
    dwFileAttributes    dd  ?
    ftCreationTime      FILETIME ?
    ftLastAccessTime    FILETIME ?
    ftLastWriteTime     FILETIME ?
    nFileSizeHigh       dd  ?
    nFileSizeLow        dd  ?
ends

struc HW_PROFILE_INFOA
    dwDockInfo         dd ?
    szHwProfileGuid    rb HW_PROFILE_GUIDLEN
    szHwProfileName    rb MAX_PROFILE_LEN
ends

struc HW_PROFILE_INFOW
    dwDockInfo         dd ?
    szHwProfileGuid    rw HW_PROFILE_GUIDLEN
    szHwProfileName    rw MAX_PROFILE_LEN
ends

struc SYSTEM_POWER_STATUS
    ACLineStatus        db  ?
    BatteryFlag         db  ?
    BatteryLifePercent  db  ?
    Reserved1           db  ?
    BatteryLifeTime     dd  ?
    BatteryFullLifeTime dd  ?
ends

struc ENUMUILANG
    NumOfEnumUILang     dd   ?
    SizeOfEnumUIBuffer  dd   ?
    pEnumUIBuffer       xword ?
ends

;======================================== advapi32 =======================================;
struc SERVICE_DESCRIPTIONA
    lpDescription  xword ?
ends

struc SERVICE_DESCRIPTIONW
    lpDescription  xword ?
ends

struc SC_ACTION
    _Type  dd ?
    Delay  dd ?
ends

struc SERVICE_FAILURE_ACTIONSA
    dwResetPeriod  dd    ?
    lpRebootMsg    xword ?
    lpCommand      xword ?
    cActions       dd    ?
    lpsaActions    xword ?
ends

struc SERVICE_FAILURE_ACTIONSW
    dwResetPeriod  dd    ?
    lpRebootMsg    xword ?
    lpCommand      xword ?
    cActions       dd    ?
    lpsaActions    xword ?
ends

struc SERVICE_STATUS
    dwServiceType             dd  ?
    dwCurrentState            dd  ?
    dwControlsAccepted        dd  ?
    dwWin32ExitCode           dd  ?
    dwServiceSpecificExitCode dd  ?
    dwCheckPoint              dd  ?
    dwWaitHint                dd  ?
ends

struc SERVICE_STATUS_PROCESS
    dwServiceType             dd  ?
    dwCurrentState            dd  ?
    dwControlsAccepted        dd  ?
    dwWin32ExitCode           dd  ?
    dwServiceSpecificExitCode dd  ?
    dwCheckPoint              dd  ?
    dwWaitHint                dd  ?
    dwProcessId               dd  ?
    dwServiceFlags            dd  ?
ends

struc ENUM_SERVICE_STATUSA
    lpServiceName  xword  ?
    lpDisplayName  xword  ?
    ServiceStatus  SERVICE_STATUS ?
ends

struc ENUM_SERVICE_STATUSW
    lpServiceName  xword  ?
    lpDisplayName  xword  ?
    ServiceStatus  SERVICE_STATUS ?
ends

struc ENUM_SERVICE_STATUS_PROCESSA
    lpServiceName        xword  ?
    lpDisplayName        xword  ?
    ServiceStatusProcess SERVICE_STATUS_PROCESS ?
ends

struc ENUM_SERVICE_STATUS_PROCESSW
    lpServiceName        xword  ?
    lpDisplayName        xword  ?
    ServiceStatusProcess SERVICE_STATUS_PROCESS ?
ends

struc QUERY_SERVICE_LOCK_STATUSA
    fIsLocked      dd    ?
    lpLockOwner    xword ?
    dwLockDuration dd    ?
ends

struc QUERY_SERVICE_LOCK_STATUSW
    fIsLocked      dd    ?
    lpLockOwner    xword ?
    dwLockDuration dd    ?
ends

struc QUERY_SERVICE_CONFIGA
    dwServiceType      dd    ?
    dwStartType        dd    ?
    dwErrorControl     dd    ?
    lpBinaryPathName   xword ?
    lpLoadOrderGroup   xword ?
    dwTagId            dd    ?
    lpDependencies     xword ?
    lpServiceStartName xword ?
    lpDisplayName      xword ?
ends

struc QUERY_SERVICE_CONFIGW
    dwServiceType      dd    ?
    dwStartType        dd    ?
    dwErrorControl     dd    ?
    lpBinaryPathName   xword ?
    lpLoadOrderGroup   xword ?
    dwTagId            dd    ?
    lpDependencies     xword ?
    lpServiceStartName xword ?
    lpDisplayName      xword ?
ends

struc SERVICE_TABLE_ENTRYA
    lpServiceName  xword ?
    lpServiceProc  xword ?
ends

struc SERVICE_TABLE_ENTRYW
    lpServiceName  xword ?
    lpServiceProc  xword ?
ends

struc INHERITED_FROMA
    GenerationGap   dd    ?
    AncestorName    xword ?
ends

struc INHERITED_FROMW
    GenerationGap   dd    ?
    AncestorName    xword ?
ends

struc OBJECTS_AND_SID
    ObjectsPresent          dd    ?
    ObjectTypeGuid          GUID  ?
    InheritedObjectTypeGuid GUID  ?
    pSid                    xword ?
ends

struc OBJECTS_AND_NAME_A
    ObjectsPresent          dd    ?
    ObjectType              xword ?
    ObjectTypeName          xword ?
    InheritedObjectTypeName xword ?
    ptstrName               xword ?
ends

struc OBJECTS_AND_NAME_W
    ObjectsPresent          dd    ?
    ObjectType              xword ?
    ObjectTypeName          xword ?
    InheritedObjectTypeName xword ?
    ptstrName               xword ?
ends

struc TRUSTEE_A
    pMultipleTrustee         xword ?
    MultipleTrusteeOperation xword ?
    TrusteeForm              xword ?
    TrusteeType              xword ?
    ptstrName                xword ?
ends

struc TRUSTEE_W
    pMultipleTrustee         xword ?
    MultipleTrusteeOperation xword ?
    TrusteeForm              xword ?
    TrusteeType              xword ?
    ptstrName                xword ?
ends

struc EXPLICIT_ACCESSA
    grfAccessPermissions dd        ?
    grfAccessMode        xword     ?
    grfInheritance       dd        ?
    Trustee              TRUSTEE_A ?
ends
define EXPLICIT_ACCESS_A EXPLICIT_ACCESSA

struc EXPLICIT_ACCESSW
    grfAccessPermissions dd        ?
    grfAccessMode        xword     ?
    grfInheritance       dd        ?
    Trustee              TRUSTEE_W ?
ends
define EXPLICIT_ACCESS_W EXPLICIT_ACCESSW

struc ACTRL_ACCESS_ENTRYA
    Trustee            TRUSTEE_A ?
    fAccessFlags       dd        ?
    Access             dd        ?
    ProvSpecificAccess dd        ?
    Inheritance        dd        ?
    lpInheritProperty  xword     ?
ends

struc ACTRL_ACCESS_ENTRYW
    Trustee            TRUSTEE_W ?
    fAccessFlags       dd        ?
    Access             dd        ?
    ProvSpecificAccess dd        ?
    Inheritance        dd        ?
    lpInheritProperty  xword     ?
ends

struc ACTRL_ACCESS_ENTRY_LISTA
    cEntries    dd    ?
    pAccessList xword ?
ends

struc ACTRL_ACCESS_ENTRY_LISTW
    cEntries    dd    ?
    pAccessList xword ?
ends

struc ACTRL_PROPERTY_ENTRYA
    lpProperty       xword ?
    pAccessEntryList xword ?
    fListFlags       dd    ?
ends

struc ACTRL_PROPERTY_ENTRYW
    lpProperty       xword ?
    pAccessEntryList xword ?
    fListFlags       dd    ?
ends

struc ACTRL_ALISTA
    cEntries            dd    ?
    pPropertyAccessList xword ?
ends

struc ACTRL_ALISTW
    cEntries            dd    ?
    pPropertyAccessList xword ?
ends

struc TRUSTEE_ACCESSA
    lpProperty      xword ?
    Access          dd    ?
    fAccessFlags    dd    ?
    fReturnedAccess dd    ?
ends

struc TRUSTEE_ACCESSW
    lpProperty      xword ?
    Access          dd    ?
    fAccessFlags    dd    ?
    fReturnedAccess dd    ?
ends

struc ACTRL_OVERLAPPED
    union
        Provider    xword ?
        Reserved1   dd    ?
    endu
    Reserved2   dd    ?
    hEvent      xword ?
ends

struc ACTRL_ACCESS_INFOA
    fAccessPermission      dd    ?
    lpAccessPermissionName xword ?
ends

struc ACTRL_ACCESS_INFOW
    fAccessPermission      dd    ?
    lpAccessPermissionName xword ?
ends

struc ACTRL_CONTROL_INFOA
    lpControlId   xword ?
    lpControlName xword ?
ends

struc ACTRL_CONTROL_INFOW
    lpControlId   xword ?
    lpControlName xword ?
ends

struc ACTRL_AUDITA
    cEntries            dd    ?
    pPropertyAccessList xword ?
ends

struc ACTRL_AUDITW
    cEntries            dd    ?
    pPropertyAccessList xword ?
ends

struc FN_OBJECT_MGR_FUNCTIONS
    Placeholder dd  ?
ends

;======================================== comctl32 =======================================;
struc NMHDR
    hwndFrom xword  ?
    idFrom   xword  ?
    _code    dd     ?
    #ifdef APP_WIN64
        dd     ?
    #endif
ends

struc NMTVSTATEIMAGECHANGING
    hdr                 NMHDR ?
    hti                 xword ?
    iOldStateImageIndex dd    ?
    iNewStateImageIndex dd    ?
ends

struc INITCOMMONCONTROLSEX
    dwSize dd  ?
    dwICC  dd  ?
ends

struc COLORSCHEME
    dwSize          dd ?
    clrBtnHighlight dd ?
    clrBtnShadow    dd ?
ends

struc NMTOOLTIPSCREATED
    hdr          NMHDR ?
    hwndToolTips xword ?
ends

struc NMMOUSE
    hdr        NMHDR ?
    dwItemSpec dd    ?
    dwItemData dd    ?
    pt         POINT ?
    dwHitInfo  dd    ?
ends

struc NMCLICK
    hdr         NMHDR ?
    dwItemSpec  dd    ?
    dwItemData  dd    ?
    pt          POINT ?
    dwHitInfo   dd    ?
ends

struc NMOBJECTNOTIFY
    hdr     NMHDR ?
    iItem   dd    ?
    piid    xword ?
    pObject xword ?
    hResult dd    ?
    dwFlags dd    ?
ends

struc NMKEY
    hdr     NMHDR ?
    nVKey   dd    ?
    uFlags  dd    ?
ends

struc NMCHAR
    hdr        NMHDR ?
    chr        dd    ?
    dwItemPrev dd    ?
    dwItemNext dd    ?
ends

struc NMCUSTOMTEXT
    hdr      NMHDR ?
    hDC      xword   ?
    lpString xword   ?
    nCount   dd      ?
    lpRect   xword   ?
    uFormat  dd      ?
    fLink    dd      ?
ends

struc NMCUSTOMDRAW
    hdr         NMHDR ?
    dwDrawStage dd    ?
    hdc         xword ?
    rc          RECT  ?
    dwItemSpec  xword ?
    uItemState  dd    ?
    lItemlParam xword ?
ends

struc NMTTCUSTOMDRAW
    nmcd       NMCUSTOMDRAW ?
    uDrawFlags dd           ?
ends

struc IMAGELISTDRAWPARAMS
    cbSize   dd       ?
    himl     xword    ?
    i        dd       ?
    hdcDst   xword    ?
    x        dd       ?
    y        dd       ?
    _cx      dd       ?
    cy       dd       ?
    xBitmap  dd       ?
    yBitmap  dd       ?
    rgbBk    dd       ?
    rgbFg    dd       ?
    fStyle   dd       ?
    dwRop    dd       ?
    fState   dd       ?
    _Frame   dd       ?
    crEffect dd       ?
ends

struc IMAGEINFO
    hbmImage xword ?
    hbmMask  xword ?
    Unused1  dd    ?
    Unused2  dd    ?
    rcImage  RECT  ?
ends

struc HDTEXTFILTERA
    pszText     xword ?
    cchTextMax  dd    ?
ends

struc HDTEXTFILTERW
    pszText     xword ?
    cchTextMax  dd    ?
ends

struc HDITEMA
    _mask        dd      ?
    cxy          dd      ?
    pszText      xword   ?
    hbm          xword   ?
    cchTextMax   dd      ?
    fmt          dd      ?
    lParam       xword   ?
    iImage       dd      ?
    iOrder       dd      ?
    #if NTDDI_VERSION >= NTDDI_WIN2K
        _type    dd      ?
        pvFilter xword   ?
    #endif
    #if NTDDI_VERSION >= NTDDI_VISTA
        state    dd      ?
    #endif
ends

struc HDITEMW
    _mask        dd      ?
    cxy          dd      ?
    pszText      xword   ?
    hbm          xword   ?
    cchTextMax   dd      ?
    fmt          dd      ?
    lParam       xword   ?
    iImage       dd      ?
    iOrder       dd      ?
    #if NTDDI_VERSION >= NTDDI_WIN2K
        _type    dd      ?
        pvFilter xword   ?
    #endif
    #if NTDDI_VERSION >= NTDDI_VISTA
        state    dd      ?
    #endif
ends

#ifdef APP_UNICODE
    HDITEMW_V1_SIZE equ size HDITEMW
#else
    HDITEMA_V1_SIZE equ size HDITEMA
#endif

struc HDLAYOUT
    prc   xword ?
    pwpos xword ?
ends
define HD_LAYOUT HDLAYOUT

struc HDHITTESTINFO
    pt    POINT ?
    flags dd    ?
    iItem dd    ?
ends
define HD_HITTESTINFO HDHITTESTINFO

struc NMHEADERA
    hdr     NMHDR ?
    iItem   dd    ?
    iButton dd    ?
    pitem   xword ?
ends

struc NMHEADERW
    hdr     NMHDR ?
    iItem   dd    ?
    iButton dd    ?
    pitem   xword ?
ends

struc NMHDDISPINFOA
    hdr        NMHDR  ?
    iItem      dd     ?
    _mask      dd     ?
    pszText    xword  ?
    cchTextMax dd     ?
    iImage     dd     ?
    lParam     xword  ?
ends

struc NMHDDISPINFOW
    hdr        NMHDR  ?
    iItem      dd     ?
    _mask      dd     ?
    pszText    xword  ?
    cchTextMax dd     ?
    iImage     dd     ?
    lParam     xword  ?
ends

struc NMHDFILTERBTNCLICK
    hdr     NMHDR ?
    iItem   dd    ?
    rc      RECT  ?
ends

struc TBBUTTON
    iBitmap       dd    ?
    idCommand     dd    ?
    fsState       db    ?
    fsStyle       db    ?
    #ifdef APP_WIN64
        bReserved rb    6
    #else
        bReserved rb    2
    #endif
    dwData        xword ?
    iString       xword ?
ends

struc COLORMAP
    _from dd ?
    to    dd ?
ends

struc NMTBCUSTOMDRAW
    nmcd                 NMCUSTOMDRAW ?
    hbrMonoDither        xword        ?
    hbrLines             xword        ?
    hpenLines            xword        ?
    clrText              dd           ?
    clrMark              dd           ?
    clrTextHighlight     dd           ?
    clrBtnFace           dd           ?
    clrBtnHighlight      dd           ?
    clrHighlightHotTrack dd           ?
    rcText               RECT         ?
    nStringBkMode        dd           ?
    nHLStringBkMode      dd           ?
    iListGap             dd           ?
ends

struc TBADDBITMAP
    hInst  xword ?
    nID    xword ?
ends

struc TBSAVEPARAMSA
    hkr          xword ?
    pszSubKey    xword ?
    pszValueName xword ?
ends

struc TBSAVEPARAMSW
    hkr          xword ?
    pszSubKey    xword ?
    pszValueName xword ?
ends

struc TBINSERTMARK
    iButton dd  ?
    dwFlags dd  ?
ends

struc TBREPLACEBITMAP
    hInstOld xword ?
    nIDOld   xword ?
    hInstNew xword ?
    nIDNew   xword ?
    nButtons dd    ?
ends

struc TBBUTTONINFOA
    cbSize     dd    ?
    dwMask     dd    ?
    idCommand  dd    ?
    iImage     dd    ?
    fsState    db    ?
    fsStyle    db    ?
    lx         dw    ?
    lParam     xword ?
    pszText    xword ?
    cchText    dd    ?
    #if NTDDI_VERSION >= NTDDI_VISTA
        iImageLabel dd   ?
    #endif
ends

struc TBBUTTONINFOW
    cbSize     dd    ?
    dwMask     dd    ?
    idCommand  dd    ?
    iImage     dd    ?
    fsState    db    ?
    fsStyle    db    ?
    lx         dw    ?
    lParam     xword ?
    pszText    xword ?
    cchText    dd    ?
    #if NTDDI_VERSION >= NTDDI_VISTA
        iImageLabel dd   ?
    #endif
ends

struc NMTBSAVE
    hdr      NMHDR ?
    pData    xword ?
    pCurrent xword ?
    cbData   dd    ?
    iItem    dd    ?
    cButtons dd    ?
    tbButton TBBUTTON ?
ends

struc NMTBRESTORE
    hdr      NMHDR ?
    pData    xword      ?
    pCurrent xword      ?
    cbData   dd         ?
    iItem    dd         ?
    cButtons dd         ?
    cbBytesPerRecord dd ?
    tbButton TBBUTTON ?
ends

struc NMTBHOTITEM
    hdr     NMHDR ?
    idOld   dd    ?
    idNew   dd    ?
    dwFlags dd    ?
ends

struc NMTBGETINFOTIPA
    hdr        NMHDR ?
    pszText    xword ?
    cchTextMax dd    ?
    iItem      dd    ?
    lParam     xword ?
ends

struc NMTBGETINFOTIPW
    hdr        NMHDR ?
    pszText    xword ?
    cchTextMax dd    ?
    iItem      dd    ?
    lParam     xword ?
ends

struc NMTBDISPINFOA
    hdr       NMHDR ?
    dwMask    dd    ?
    idCommand dd    ?
    lParam    xword ?
    iImage    dd    ?
    pszText   xword ?
    cchText   dd    ?
ends

struc NMTBDISPINFOW
    hdr       NMHDR ?
    dwMask    dd    ?
    idCommand dd    ?
    lParam    xword ?
    iImage    dd    ?
    pszText   xword ?
    cchText   dd    ?
ends

struc NMTOOLBARA
    hdr      NMHDR    ?
    iItem    dd       ?
    tbButton TBBUTTON ?
    cchText  dd       ?
    pszText  xword    ?
    rcButton RECT     ?
ends

struc NMTOOLBARW
    hdr      NMHDR    ?
    iItem    dd       ?
    tbButton TBBUTTON ?
    cchText  dd       ?
    pszText  xword    ?
    rcButton RECT     ?
ends

struc TBMETRICS
    cbSize          dd ?
    dwMask          dd ?
    cxPad           dd ?
    cyPad           dd ?
    cxBarPad        dd ?
    cyBarPad        dd ?
    cxButtonSpacing dd ?
    cyButtonSpacing dd ?
ends

struc REBARINFO
    cbSize dd    ?
    fMask  dd    ?
    himl   xword ?
ends

struc REBARBANDINFOA
    cbSize      dd         ?
    fMask       dd         ?
    fStyle      dd         ?
    clrFore     dd         ?
    clrBack     dd         ?
    lpText      xword      ?
    cch         dd         ?
    iImage      dd         ?
    hwndChild   xword      ?
    cxMinChild  dd         ?
    cyMinChild  dd         ?
    _cx         dd         ?
    hbmBack     xword      ?
    wID         dd         ?
    cyChild     dd         ?
    cyMaxChild  dd         ?
    cyIntegral  dd         ?
    cxIdeal     dd         ?
    lParam      xword      ?
    cxHeader    dd         ?
    rcChevronLocation RECT ?
    uChevronState     dd   ?
ends
REBARBANDINFOA_V3_SIZE equ size REBARBANDINFOA

struc REBARBANDINFOW
    cbSize      dd         ?
    fMask       dd         ?
    fStyle      dd         ?
    clrFore     dd         ?
    clrBack     dd         ?
    lpText      xword      ?
    cch         dd         ?
    iImage      dd         ?
    hwndChild   xword      ?
    cxMinChild  dd         ?
    cyMinChild  dd         ?
    _cx         dd         ?
    hbmBack     xword      ?
    wID         dd         ?
    cyChild     dd         ?
    cyMaxChild  dd         ?
    cyIntegral  dd         ?
    cxIdeal     dd         ?
    lParam      xword      ?
    cxHeader    dd         ?
    rcChevronLocation RECT ?
    uChevronState     dd   ?
ends
REBARBANDINFOW_V3_SIZE equ size REBARBANDINFOW

struc NMREBARCHILDSIZE
    hdr     NMHDR ?
    uBand   dd    ?
    wID     dd    ?
    rcChild RECT  ?
    rcBand  RECT  ?
ends

struc NMREBAR
    hdr    NMHDR ?
    dwMask dd    ?
    uBand  dd    ?
    fStyle dd    ?
    wID    dd    ?
    lParam xword ?
ends

struc NMRBAUTOSIZE
    hdr      NMHDR ?
    fChanged dd    ?
    rcTarget RECT  ?
    rcActual RECT  ?
ends

struc RBHITTESTINFO
    pt    POINT ?
    flags dd    ?
    iBand dd    ?
ends
define RB_HITTESTINFO RBHITTESTINFO

struc NMREBARAUTOBREAK
    hdr           NMHDR ?
    uBand         dd    ?
    wID           dd    ?
    lParam        xword ?
    uMsg          dd    ?
    fStyleCurrent dd    ?
    fAutoBreak    dd    ?
ends

struc NMREBARSPLITTER
    hdr      NMHDR ?
    rcSizing RECT  ?
ends

struc TOOLINFOA
    cbSize     dd    ?
    uFlags     dd    ?
    hwnd       xword ?
    uId        xword ?
    rect       RECT  ?
    hInst      xword ?
    lpszText   xword ?
    lParam     xword ?
    lpReserved xword ?
ends

struc TTTOOLINFOA
    cbSize     dd    ?
    uFlags     dd    ?
    hwnd       xword ?
    uId        xword ?
    rect       RECT  ?
    hInst      xword ?
    lpszText   xword ?
    lParam     xword ?
    lpReserved xword ?
ends
TOOLINFOA_V1_SIZE equ size TTTOOLINFOA

struc TOOLINFOW
    cbSize     dd    ?
    uFlags     dd    ?
    hwnd       xword ?
    uId        xword ?
    rect       RECT  ?
    hInst      xword ?
    lpszText   xword ?
    lParam     xword ?
    lpReserved xword ?
ends

struc TTTOOLINFOW
    cbSize     dd    ?
    uFlags     dd    ?
    hwnd       xword ?
    uId        xword ?
    rect       RECT  ?
    hInst      xword ?
    lpszText   xword ?
    lParam     xword ?
    lpReserved xword ?
ends
TOOLINFOW_V1_SIZE equ size TTTOOLINFOW

struc TTHITTESTINFOA
    hwnd xword       ?
    pt   POINT       ?
    ti   TTTOOLINFOA ?
ends

struc TTHITTESTINFOW
    hwnd xword       ?
    pt   POINT       ?
    ti   TTTOOLINFOW ?
ends

struc NMTTDISPINFOA
    hdr      NMHDR ?
    lpszText xword ?
    _szText  rb    80
    hInst    xword ?
    uFlags   dd    ?
    lParam   xword ?
ends
NMTTDISPINFOA_V1_SIZE equ size NMTTDISPINFOA

struc NMTTDISPINFOW
    hdr      NMHDR ?
    lpszText xword ?
    _szText  rw    80
    hInst    xword ?
    uFlags   dd    ?
    lParam   xword ?
ends
NMTTDISPINFOW_V1_SIZE equ size NMTTDISPINFOW

struc TOOLTIPTEXTA
    hdr      NMHDR ?
    lpszText xword ?
    _szText  rb    80
    hInst    xword ?
    uFlags   dd    ?
    lParam   xword ?
ends

struc TOOLTIPTEXTW
    hdr      NMHDR ?
    lpszText xword ?
    _szText  rw    80
    hInst    xword ?
    uFlags   dd    ?
    lParam   xword ?
ends

struc TTGETTITLE
    dwSize       dd   ?
    uTitleBitmap dd   ?
    cch          dd   ?
    pszTitle     xword ?
ends

struc NMTRBTHUMBPOSCHANGING
    hdr     NMHDR ?
    dwPos   dd    ?
    nReason dd    ?
ends

struc DRAGLISTINFO
    uNotification dd    ?
    hWnd          xword ?
    ptCursor      POINT ?
ends

struc UDACCEL
    nSec dd ?
    nInc dd ?
ends

struc NMUPDOWN
    hdr     NMHDR ?
    iPos    dd    ?
    iDelta  dd    ?
ends
define NM_UPDOWN NMUPDOWN

struc PBRANGE
    iLow  dd  ?
    iHigh dd  ?
ends

struc NMLVEMPTYMARKUP
    hdr      NMHDR ?
    dwFlags  dd    ?
    szMarkup rw L_MAX_URL_LENGTH
ends

struc LVFOOTERITEM
    _mask       dd    ?
    iItem       dd    ?
    pszText     xword ?
    cchTextMax  dd    ?
    state       dd    ?
    stateMask   dd    ?
ends

struc LVFOOTERINFO
    _mask       dd    ?
    pszText     xword ?
    cchTextMax  dd    ?
    cItems      dd    ?
ends

struc LVITEMA
    _mask       dd     ?
    iItem       dd     ?
    iSubItem    dd     ?
    state       dd     ?
    stateMask   dd     ?
    pszText     xword  ?
    cchTextMax  dd     ?
    iImage      dd     ?
    lParam      xword ?
    iIndent     dd     ?
    #if NTDDI_VERSION >= NTDDI_WINXP
        iGroupId  dd   ?
        cColumns  dd   ?
        puColumns dd   ?
    #endif
    #if NTDDI_VERSION >= NTDDI_VISTA
        piColFmt  dd   ?
        iGroup    dd   ?
    #endif
ends

struc LVITEMW
    _mask       dd     ?
    iItem       dd     ?
    iSubItem    dd     ?
    state       dd     ?
    stateMask   dd     ?
    pszText     xword  ?
    cchTextMax  dd     ?
    iImage      dd     ?
    lParam      xword ?
    iIndent     dd     ?
    #if NTDDI_VERSION >= NTDDI_WINXP
        iGroupId  dd   ?
        cColumns  dd   ?
        puColumns dd   ?
    #endif
    #if NTDDI_VERSION >= NTDDI_VISTA
        piColFmt  dd   ?
        iGroup    dd   ?
    #endif
ends

struc LVFINDINFOA
    flags       dd    ?
    psz         xword ?
    lParam      xword ?
    pt          POINT ?
    vkDirection dd    ?
ends

struc LVFINDINFOW
    flags       dd    ?
    psz         xword ?
    lParam      xword ?
    pt          POINT ?
    vkDirection dd    ?
ends

struc LVHITTESTINFO
    pt       POINT ?
    flags    dd    ?
    iItem    dd    ?
    iSubItem dd    ?
    iGroup   dd    ?
ends
define LV_HITTESTINFO LVHITTESTINFO

struc LVCOLUMNA
    _mask       dd    ?
    fmt         dd    ?
    _cx         dd    ?
    pszText     xword ?
    cchTextMax  dd    ?
    iSubItem    dd    ?
    iImage      dd    ?
    iOrder      dd    ?
    #if NTDDI_VERSION >= NTDDI_VISTA
        cxMin     dd  ?
        cxDefault dd  ?
        cxIdeal   dd  ?
    #endif
ends

struc LVCOLUMNW
    _mask       dd    ?
    fmt         dd    ?
    _cx         dd    ?
    pszText     xword ?
    cchTextMax  dd    ?
    iSubItem    dd    ?
    iImage      dd    ?
    iOrder      dd    ?
    #if NTDDI_VERSION >= NTDDI_VISTA
        cxMin     dd  ?
        cxDefault dd  ?
        cxIdeal   dd  ?
    #endif
ends

struc LVBKIMAGEA
    ulFlags         dd    ?
    hbm             xword ?
    pszImage        xword ?
    cchImageMax     dd    ?
    xOffsetPercent  dd    ?
    yOffsetPercent  dd    ?
ends

struc LVBKIMAGEW
    ulFlags         dd    ?
    hbm             xword ?
    pszImage        xword ?
    cchImageMax     dd    ?
    xOffsetPercent  dd    ?
    yOffsetPercent  dd    ?
ends

struc NMLISTVIEW
    hdr       NMHDR ?
    iItem     dd    ?
    iSubItem  dd    ?
    uNewState dd    ?
    uOldState dd    ?
    uChanged  dd    ?
    ptAction  POINT ?
    lParam    xword ?
ends
define NM_LISTVIEW NMLISTVIEW

struc NMITEMACTIVATE
    hdr       NMHDR ?
    iItem     dd    ?
    iSubItem  dd    ?
    uNewState dd    ?
    uOldState dd    ?
    uChanged  dd    ?
    ptAction  POINT ?
    lParam    xword ?
    uKeyFlags dd    ?
ends

struc NMLVCUSTOMDRAW
    nmcd      NMCUSTOMDRAW ?
    clrText   dd ?
    clrTextBk dd ?
    iSubItem  dd ?
ends

struc NMLVCACHEHINT
    hdr   NMHDR ?
    iFrom dd    ?
    iTo   dd    ?
ends
define NM_CACHEHINT NMLVCACHEHINT

struc NMLVFINDITEMA
    hdr     NMHDR ?
    iStart  dd    ?
    lvfi    LVFINDINFOA ?
ends

struc NMLVFINDITEMW
    hdr     NMHDR ?
    iStart  dd    ?
    lvfi    LVFINDINFOW ?
ends

struc NMLVODSTATECHANGE
    hdr       NMHDR ?
    iFrom     dd    ?
    iTo       dd    ?
    uNewState dd    ?
    uOldState dd    ?
ends
define NM_ODSTATECHANGE NMLVODSTATECHANGE

struc NMLVDISPINFOA
    hdr  NMHDR   ?
    item LVITEMA ?
ends

struc NMLVDISPINFOW
    hdr  NMHDR   ?
    item LVITEMW ?
ends

struc NMLVKEYDOWN
    hdr   NMHDR ?
    wVKey dw    ?
    flags dd    ?
ends

struc LV_KEYDOWN
    hdr   NMHDR ?
    wVKey dw    ?
    flags dd    ?
ends

struc NMLVGETINFOTIPA
    hdr        NMHDR  ?
    dwFlags    dd     ?
    pszText    xword  ?
    cchTextMax dd     ?
    iItem      dd     ?
    iSubItem   dd     ?
    lParam     xword  ?
ends

struc NMLVGETINFOTIPW
    hdr        NMHDR  ?
    dwFlags    dd     ?
    pszText    xword  ?
    cchTextMax dd     ?
    iItem      dd     ?
    iSubItem   dd     ?
    lParam     xword  ?
ends

struc TVITEMA
    _mask           dd    ?
    hItem           xword ?
    state           dd    ?
    stateMask       dd    ?
    pszText         xword ?
    cchTextMax      dd    ? 
    iImage          dd    ?
    iSelectedImage  dd    ?
    cChildren       dd    ?
    lParam          xword ?
ends
define TV_ITEMA TVITEMA

struc TVITEMW
    _mask           dd    ?
    hItem           xword ?
    state           dd    ?
    stateMask       dd    ?
    pszText         xword ?
    cchTextMax      dd    ? 
    iImage          dd    ?
    iSelectedImage  dd    ?
    cChildren       dd    ?
    lParam          xword ?
ends
define TV_ITEMW TVITEMW

struc TVITEMEXA
    _mask           dd    ?
    hItem           xword ?
    state           dd    ?
    stateMask       dd    ?
    pszText         xword ?
    cchTextMax      dd    ? 
    iImage          dd    ?
    iSelectedImage  dd    ?
    cChildren       dd    ?
    lParam          xword ?
    iIntegral       dd    ?
    #if NTDDI_VERSION >= NTDDI_VISTA
        uStateEx    dd    ?
        hwnd        xword ?
        iExpandedImage dd ?
    #endif
    #if NTDDI_VERSION >= NTDDI_WIN7
        iReserved   dd        ?
    #endif
ends
define TV_ITEMEXA TVITEMEXA

struc TVITEMEXW
    _mask           dd    ?
    hItem           xword ?
    state           dd    ?
    stateMask       dd    ?
    pszText         xword ?
    cchTextMax      dd    ? 
    iImage          dd    ?
    iSelectedImage  dd    ?
    cChildren       dd    ?
    lParam          xword ?
    iIntegral       dd    ?
    #if NTDDI_VERSION >= NTDDI_VISTA
        uStateEx    dd    ?
        hwnd        xword ?
        iExpandedImage dd ?
    #endif
    #if NTDDI_VERSION >= NTDDI_WIN7
        iReserved   dd    ?
    #endif
ends
define TV_ITEMEXW TVITEMEXW

struc TVGETITEMPARTRECTINFO
    hti     xword ?
    prc     xword ?
    partID  dd    ?
ends

struc TVINSERTSTRUCTA
    hParent      xword ?
    hInsertAfter xword ?
    union
        itemex  TVITEMEXA ?
        item    TVITEMA   ?
    endu
ends
define TV_INSERTSTRUCTA TVINSERTSTRUCTA

struc TVINSERTSTRUCTW
    hParent      xword ?
    hInsertAfter xword ?
    union
        itemex  TVITEMEXW ?
        item    TVITEMW   ?
    endu
ends
define TV_INSERTSTRUCTW TVINSERTSTRUCTW

struc TVHITTESTINFO
    pt    POINT  ?
    flags dd     ?
    hItem xword  ?
ends

struc TVSORTCB
    hParent     xword ?
    lpfnCompare xword ?
    lParam      xword ?
ends
define TV_SORTCB TVSORTCB

struc NMTREEVIEWA
    hdr     NMHDR   ?
    action  dd      ?
    itemOld TVITEMA ?
    itemNew TVITEMA ?
    ptDrag  POINT   ?
ends

struc NMTREEVIEWW
    hdr     NMHDR   ?
    action  dd      ?
    itemOld TVITEMW ?
    itemNew TVITEMW ?
    ptDrag  POINT   ?
ends

struc NMTVDISPINFOA
    hdr  NMHDR   ?
    item TVITEMA ?
ends

struc NMTVDISPINFOW
    hdr  NMHDR   ?
    item TVITEMW ?
ends

struc NMTVDISPINFOEXA
    hdr  NMHDR     ?
    item TVITEMEXA ?
ends

struc NMTVDISPINFOEXW
    hdr  NMHDR     ?
    item TVITEMEXW ?
ends

struc NMTVKEYDOWN
    hdr   NMHDR ?
    wVKey dw    ?
    flags dd    ?
ends
define TV_KEYDOWN NMTVKEYDOWN

struc NMTVCUSTOMDRAW
    nmcd      NMCUSTOMDRAW ?
    clrText   dd           ?
    clrTextBk dd           ?
    iLevel    dd           ?
ends

struc NMTVGETINFOTIPA
    hdr         NMHDR ?
    pszText     xword ?
    cchTextMax  dd    ?
    hItem       xword ?
    lParam      xword ?
ends

struc NMTVGETINFOTIPW
    hdr         NMHDR ?
    pszText     xword ?
    cchTextMax  dd    ?
    hItem       xword ?
    lParam      xword ?
ends

struc NMTVITEMCHANGE
    hdr        NMHDR ?
    uChanged   dd    ?
    hItem      xword ?
    uStateNew  dd    ?
    uStateOld  dd    ?
    lParam     xword ?
ends

struc NMTVASYNCDRAW
    hdr            NMHDR ?
    pimldp         xword ?
    hr             dd    ?
    hItem          xword ?
    lParam         xword ?
    dwRetFlags     dd    ?
    iRetImageIndex dd    ?
ends

struc COMBOBOXEXITEMA
    _mask           dd    ?
    iItem           xword ?
    pszText         xword ?
    cchTextMax      dd    ?
    iImage          dd    ?
    iSelectedImage  dd    ?
    iOverlay        dd    ?
    iIndent         dd    ?
    lParam          xword ?
ends

struc COMBOBOXEXITEMW
    _mask           dd    ?
    iItem           xword ?
    pszText         xword ?
    cchTextMax      dd    ?
    iImage          dd    ?
    iSelectedImage  dd    ?
    iOverlay        dd    ?
    iIndent         dd    ?
    lParam          xword ?
ends

struc NMCOMBOBOXEXA
    hdr     NMHDR ?
    ceItem  COMBOBOXEXITEMA ?
ends

struc NMCOMBOBOXEXW
    hdr     NMHDR ?
    ceItem  COMBOBOXEXITEMW ?
ends

struc NMCBEDRAGBEGINA
    hdr     NMHDR ?
    iItemid dd  ?
    _szText rb  CBEMAXSTRLEN
ends

struc NMCBEDRAGBEGINW
    hdr     NMHDR ?
    iItemid dd    ?
    _szText rw    CBEMAXSTRLEN
ends

struc NMCBEENDEDITA
    hdr           NMHDR ?
    fChanged      dd ?
    iNewSelection dd ?
    _szText       rb CBEMAXSTRLEN
    iWhy          dd ?
ends

struc NMCBEENDEDITW
    hdr           NMHDR ?
    fChanged      dd ?
    iNewSelection dd ?
    _szText       rw CBEMAXSTRLEN
    iWhy          dd ?
ends

struc TCITEMHEADERA
    _mask       dd    ?
    lpReserved1 dd    ?
    lpReserved2 dd    ?
    pszText     xword ?
    cchTextMax  dd    ?
    iImage      dd    ?
ends

struc TCITEMHEADERW
    _mask       dd    ?
    lpReserved1 dd    ?
    lpReserved2 dd    ?
    pszText     xword ?
    cchTextMax  dd    ?
    iImage      dd    ?
ends

struc TCITEMA
    _mask       dd    ?
    dwState     dd    ?
    dwStateMask dd    ?
    pszText     xword ?
    cchTextMax  dd    ?
    iImage      dd    ?
    lParam      xword ?
ends

struc TCITEMW
    _mask       dd    ?
    dwState     dd    ?
    dwStateMask dd    ?
    pszText     xword ?
    cchTextMax  dd    ?
    iImage      dd    ?
    lParam      xword ?
ends

struc TCHITTESTINFO
    pt    POINT ?
    flags dd    ?
ends
define TC_HITTESTINFO TCHITTESTINFO

struc NMTCKEYDOWN
    hdr   NMHDR ?
    wVKey dw    ?
    flags dd    ?
ends
define TC_KEYDOWN NMTCKEYDOWN

struc MCGRIDINFO
    cbSize     dd     ?
    dwPart     dd     ?
    dwFlags    dd     ?
    iCalendar  dd     ?
    iRow       dd     ?
    iCol       dd     ?
    bSelected  dd     ?
    stStart    SYSTEMTIME ?
    stEnd      SYSTEMTIME ?
    rc         RECT   ?
    pszName    xword  ?
    cchName    xword  ?
ends

struc MCHITTESTINFO
    cbSize  dd    ?
    pt      POINT ?
    uHit    dd    ?
    _st     SYSTEMTIME ?
    #if NTDDI_VERSION >= NTDDI_VISTA
        rc      RECT ?
        iOffset dd   ?
        iRow    dd   ?
        iCol    dd   ?
    #endif
ends

struc NMSELCHANGE
    nmhdr       NMHDR ?
    stSelStart  SYSTEMTIME ?
    stSelEnd    SYSTEMTIME ?
ends

struc NMDAYSTATE
    nmhdr       NMHDR ?
    stStart     SYSTEMTIME ?
    cDayState   dd ?
    prgDayState xword ?
ends

#if NTDDI_VERSION >= NTDDI_VISTA
    struc DATETIMEPICKERINFO
        cbSize       dd    ?
        rcCheck      RECT  ?
        stateCheck   dd    ?
        rcButton     RECT  ?
        stateButton  dd    ?
        hwndEdit     xword ?
        hwndUD       xword ?
        hwndDropDown xword ?
    ends
#endif

struc NMDATETIMECHANGE
    nmhdr   NMHDR ?
    dwFlags dd    ?
    _st     SYSTEMTIME ?
ends

struc NMDATETIMESTRINGA
    nmhdr         NMHDR ?
    pszUserString xword ?
    _st           SYSTEMTIME ?
    dwFlags       dd    ?
ends

struc NMDATETIMESTRINGW
    nmhdr         NMHDR ?
    pszUserString xword ?
    _st           SYSTEMTIME ?
    dwFlags       dd    ?
ends

struc NMDATETIMEWMKEYDOWNA
    nmhdr     NMHDR ?
    nVirtKey  dd    ?
    pszFormat xword ?
    _st       SYSTEMTIME ?
ends

struc NMDATETIMEWMKEYDOWNW
    nmhdr     NMHDR ?
    nVirtKey  dd    ?
    pszFormat xword ?
    _st       SYSTEMTIME ?
ends

struc NMDATETIMEFORMATA
    nmhdr         NMHDR ?
    pszFormat     xword ?
    _st           SYSTEMTIME ?
    pszDisplay    xword ?
    szDisplay     rb    64
ends

struc NMDATETIMEFORMATW
    nmhdr         NMHDR ?
    pszFormat     xword ?
    _st           SYSTEMTIME ?
    pszDisplay    xword ?
    szDisplay     rw  64
ends

struc NMDATETIMEFORMATQUERYA
    nmhdr     NMHDR ?
    pszFormat xword ?
    szMax     SIZEL ?
ends

struc NMDATETIMEFORMATQUERYW
    nmhdr     NMHDR ?
    pszFormat xword ?
    szMax     SIZEL ?
ends

struc NMIPADDRESS
    hdr     NMHDR ?
    iField  dd ?
    iValue  dd ?
ends

struc NMPGSCROLL
    hdr      NMHDR ?
    fwKeys   dd    ?
    rcParent RECT  ?
    iDir     dd    ?
    iXpos    dd    ?
    iYpos    dd    ?
    iScroll  dd    ?
ends

struc NMPGCALCSIZE
    hdr     NMHDR ?
    dwFlag  dd    ?
    iWidth  dd    ?
    iHeight dd    ?
ends

struc LITEM
    _mask       dd ?
    iLink       dd ?
    state       dd ?
    stateMask   dd ?
    szID        rw MAX_LINKID_TEXT
    szUrl       rw L_MAX_URL_LENGTH
ends

struc LHITTESTINFO
    pt   POINT ?
    item LITEM ?
ends

struc NMLINK
    hdr  NMHDR ?
    item LITEM ?
ends

struc TASKDIALOG_BUTTON
    ButtonID     dd    ?
    szButtonText xword ?
ends

struc TASKDIALOGCONFIG
    cbSize          dd    ?
    hwndParent      xword ?
    hInstance       xword ?
    dwFlags         xword ?
    dwCommonButtons xword ?
    pszWindowTitle  xword ?
    union
        hMainIcon   xword ?
        pszMainIcon xword ?
    endu
    pszMainInstruction      xword ?
    pszContent              xword ?
    cButtons                dd    ?
    pButtons                xword ?
    nDefaultButton          dd    ?
    cRadioButtons           dd    ?
    pRadioButtons           xword ?
    nDefaultRadioButton     dd    ?
    pszVerificationText     xword ?
    pszExpandedInformation  xword ?
    pszExpandedControlText  xword ?
    pszCollapsedControlText xword ?
    union
        hFooterIcon     xword ?
        pszFooterIcon   xword ?
    endu
    pszFooter       xword ?
    pfCallback      xword ?
    lpCallbackData  xword ?
    cxWidth         dd    ?
ends

struc MRUINFO
    cbSize      dd    ?
    uMax        dd    ?
    fFlags      dd    ?
    hKey        xword ?
    lpszSubKey  xword ?
    lpfnCompare xword ?
ends

struc PROPSHEETHEADERA
    dwSize              dd    ?
    dwFlags             dd    ?
    hwndParent          xword ?
    hInstance           xword ?
    union
        hIcon           xword ?
        pszIcon         xword ?
    endu
    pszCaption          xword ?
    nPages              dd    ?
    union
        nStartPage      dd    ?
        pStartPage      xword ?
    endu
    union
        ppsp            xword ?
        phpage          xword ?
    endu
    pfnCallback         xword ?
    union
        hbmWatermark    xword ?
        pszbmWatermark  xword ?
    endu
    hplWatermark        xword ?
    union
        hbmHeader       xword ?
        pszbmHeader     xword ?
    endu
ends

struc PROPSHEETHEADERW
    dwSize              dd    ?
    dwFlags             dd    ?
    hwndParent          xword ?
    hInstance           xword ?
    union
        hIcon           xword ?
        pszIcon         xword ?
    endu
    pszCaption          xword ?
    nPages              dd    ?
    union
        nStartPage      dd    ?
        pStartPage      xword ?
    endu
    union
        ppsp            xword ?
        phpage          xword ?
    endu
    pfnCallback         xword ?
    union
        hbmWatermark    xword ?
        pszbmWatermark  xword ?
    endu
    hplWatermark        xword ?
    union
        hbmHeader       xword ?
        pszbmHeader     xword ?
    endu
ends

struc PROPSHEETPAGEA
    dwSize           dd    ?
    dwFlags          dd    ?
    hInstance        xword ?
    union
        pszTemplate  xword ?
        pResource    xword ?
    endu
    union
        hIcon        xword ?
        pszIcon      xword ?
    endu
    pszTitle         xword ?
    pfnDlgProc       xword ?
    lParam           xword ?
    pfnCallback      xword ?
    pcRefParent      dd    ?
    #if NTDDI_VERSION >= NTDDI_WIN2K
        pszHeaderTitle    dd ?
        pszHeaderSubTitle dd ?
    #endif
    #if NTDDI_VERSION >= NTDDI_WINXP
        hActCtx      xword ?
    #endif
ends

struc PROPSHEETPAGEW
    dwSize           dd    ?
    dwFlags          dd    ?
    hInstance        xword ?
    union
        pszTemplate  xword ?
        pResource    xword ?
    endu
    union
        hIcon        xword ?
        pszIcon      xword ?
    endu
    pszTitle         xword ?
    pfnDlgProc       xword ?
    lParam           xword ?
    pfnCallback      xword ?
    pcRefParent      dd    ?
    #if NTDDI_VERSION >= NTDDI_WIN2K
        pszHeaderTitle    dd ?
        pszHeaderSubTitle dd ?
    #endif
    #if NTDDI_VERSION >= NTDDI_WINXP
        hActCtx      xword ?
    #endif
ends

;======================================== comdlg32 =======================================;
struc OPENFILENAMEA
    lStructSize         dd    ?
    #ifdef APP_WIN64
                        dd    ? ;Padding
    #endif
    hwndOwner           xword ?
    hInstance           xword ?
    lpstrFilter         xword ?
    lpstrCustomFilter   xword ?
    nMaxCustFilter      dd    ?
    nFilterIndex        dd    ?
    lpstrFile           xword ?
    nMaxFile            dd    ?
    #ifdef APP_WIN64
                        dd    ? ;Padding
    #endif
    lpstrFileTitle      xword ?
    nMaxFileTitle       dd    ?
    lpstrInitialDir     xword ?
    lpstrTitle          xword ?
    Flags               dd    ?
    nFileOffset         dw    ?
    nFileExtension      dw    ?
    lpstrDefExt         xword ?
    lCustData           xword ?
    lpfnHook            xword ?
    lpTmplateName       xword ?
    #if NTDDI_VERSION >= NTDDI_WIN2K
        pvReserved    xword   ?
        dwReserved    dd      ?
        FlagsEx       dd      ?
    #endif
ends

struc OPENFILENAMEW
    lStructSize         dd    ?
    #ifdef APP_WIN64
                        dd    ? ;Padding
    #endif
    hwndOwner           xword ?
    hInstance           xword ?
    lpstrFilter         xword ?
    lpstrCustomFilter   xword ?
    nMaxCustFilter      dd    ?
    nFilterIndex        dd    ?
    lpstrFile           xword ?
    nMaxFile            dd    ?
    #ifdef APP_WIN64
                        dd    ? ;Padding
    #endif
    lpstrFileTitle      xword ?
    nMaxFileTitle       dd    ?
    lpstrInitialDir     xword ?
    lpstrTitle          xword ?
    Flags               dd    ?
    nFileOffset         dw    ?
    nFileExtension      dw    ?
    lpstrDefExt         xword ?
    lCustData           xword ?
    lpfnHook            xword ?
    lpTmplateName       xword ?
    #if NTDDI_VERSION >= NTDDI_WIN2K
        pvReserved    xword   ?
        dwReserved    dd      ?
        FlagsEx       dd      ?
    #endif
ends

struc OFNOTIFYA
    hdr     NMHDR ?
    lpOFN   xword ?
    pszFile xword ?
ends

struc OFNOTIFYW
    hdr     NMHDR ?
    lpOFN   xword ?
    pszFile xword ?
ends

struc OFNOTIFYEXA
    hdr     NMHDR ?
    lpOFN   xword ?
    psf     xword ?
    pidl    xword ?
ends

struc OFNOTIFYEXW
    hdr     NMHDR ?
    lpOFN   xword ?
    psf     xword ?
    pidl    xword ?
ends

struc CHOOSECOLORA
    lStructSize     dd    ?
    hwndOwner       xword ?
    hInstance       xword ?
    rgbResult       dd    ?
    lpCustColors    xword ?
    Flags           dd    ?
    lCustData       xword ?
    lpfnHook        xword ?
    lpTemplateName  xword ?
ends

struc CHOOSECOLORW
    lStructSize     dd    ?
    hwndOwner       xword ?
    hInstance       xword ?
    rgbResult       dd    ?
    lpCustColors    xword ?
    Flags           dd    ?
    lCustData       xword ?
    lpfnHook        xword ?
    lpTemplateName  xword ?
ends

struc FINDREPLACEA
    lStructSize      dd    ?
    hwndOwner        xword ?
    hInstance        xword ?
    Flags            xword ?
    lpstrFindWhat    xword ?
    lpstrReplaceWith dd    ?
    wFindWhatLen     dw    ?
    wReplaceWithLen  dw    ?
    lCustData        xword ?
    lpfnHook         xword ?
    lpTemplateName   xword ?
ends

struc FINDREPLACEW
    lStructSize      dd    ?
    hwndOwner        xword ?
    hInstance        xword ?
    Flags            xword ?
    lpstrFindWhat    xword ?
    lpstrReplaceWith dd    ?
    wFindWhatLen     dw    ?
    wReplaceWithLen  dw    ?
    lCustData        xword ?
    lpfnHook         xword ?
    lpTemplateName   xword ?
ends

struc CHOOSEFONTA
    lStructSize    dd    ?
    hwndOwner      xword ?
    hDC            xword ?
    lpLogFont      xword ?
    iPointSize     dd    ?
    Flags          dd    ?
    rgbColors      dd    ?
    lCustData      xword ?
    lpfnHook       xword ?
    lpTemplateName xword ?
    hInstance      xword ?
    lpszStyle      xword ?
    nFontType      dw    ?
    missAlignment  dw    ?
    nSizeMin       dd    ?
    nSizeMax       dd    ?
ends

struc CHOOSEFONTW
    lStructSize    dd    ?
    hwndOwner      xword ?
    hDC            xword ?
    lpLogFont      xword ?
    iPointSize     dd    ?
    Flags          dd    ?
    rgbColors      dd    ?
    lCustData      xword ?
    lpfnHook       xword ?
    lpTemplateName xword ?
    hInstance      xword ?
    lpszStyle      xword ?
    nFontType      dw    ?
    missAlignment  dw    ?
    nSizeMin       dd    ?
    nSizeMax       dd    ?
ends

struc PRINTDLGA
    lStructSize         dd    ?
    hwndOwner           xword ?
    hDevMode            xword ?
    hDevNames           xword ?
    hDC                 xword ?
    Flags               dd    ?
    nFromPage           dw    ?
    nToPage             dw    ?
    nMinPage            dw    ?
    nMaxPage            dw    ?
    nCopies             dw    ?
    hInstance           xword ?
    lCustData           xword ?
    lpfnPrintHook       xword ?
    lpfnSetupHook       xword ?
    lpPrintTemplateName xword ?
    lpSetupTemplateName xword ?
    hPrintTemplate      xword ?
    hSetupTemplate      xword ?
ends

struc PRINTDLGW
    lStructSize         dd    ?
    hwndOwner           xword ?
    hDevMode            xword ?
    hDevNames           xword ?
    hDC                 xword ?
    Flags               dd    ?
    nFromPage           dw    ?
    nToPage             dw    ?
    nMinPage            dw    ?
    nMaxPage            dw    ?
    nCopies             dw    ?
    hInstance           xword ?
    lCustData           xword ?
    lpfnPrintHook       xword ?
    lpfnSetupHook       xword ?
    lpPrintTemplateName xword ?
    lpSetupTemplateName xword ?
    hPrintTemplate      xword ?
    hSetupTemplate      xword ?
ends

struc PRINTDLGEXA
    lStructSize         dd    ?
    hwndOwner           xword ?
    hDevMode            xword ?
    hDevNames           xword ?
    hDC                 xword ?
    Flags               dd    ?
    Flags2              dd    ?
    ExclusionFlags      dd    ?
    nPageRanges         dd    ?
    nMaxPageRanges      dd    ?
    lpPageRanges        xword ?
    nMinPage            dd    ?
    nMaxPage            dd    ?
    nCopies             dd    ?
    hInstance           xword ?
    lpPrintTemplateName xword ?
    lpCallback          xword ?
    nPropertyPages      dd    ?
    lphPropertyPages    xword ?
    nStartPage          dd    ?
    dwResultAction      dd    ?
ends

struc PRINTDLGEXW
    lStructSize         dd    ?
    hwndOwner           xword ?
    hDevMode            xword ?
    hDevNames           xword ?
    hDC                 xword ?
    Flags               dd    ?
    Flags2              dd    ?
    ExclusionFlags      dd    ?
    nPageRanges         dd    ?
    nMaxPageRanges      dd    ?
    lpPageRanges        xword ?
    nMinPage            dd    ?
    nMaxPage            dd    ?
    nCopies             dd    ?
    hInstance           xword ?
    lpPrintTemplateName xword ?
    lpCallback          xword ?
    nPropertyPages      dd    ?
    lphPropertyPages    xword ?
    nStartPage          dd    ?
    dwResultAction      dd    ?
ends

struc DEVNAMES
    wDriverOffset dw ?
    wDeviceOffset dw ?
    wOutputOffset dw ?
    wDefault      dw ?
ends

struc PAGESETUPDLGA
    lStructSize             dd    ?
    hwndOwner               xword ?
    hDevMode                xword ?
    hDevNames               xword ?
    Flags                   dd    ?
    ptPaperSize             POINT ?
    rtMinMargin             RECT  ?
    rtMargin                RECT  ?
    hInstance               xword ?
    lCustData               xword ?
    lpfnPageSetupHook       xword ?
    lpfnPagePaintHook       xword ?
    lpPageSetupTemplateName xword ?
    hPageSetupTemplate      xword ?
ends

struc PAGESETUPDLGW
    lStructSize             dd    ?
    hwndOwner               xword ?
    hDevMode                xword ?
    hDevNames               xword ?
    Flags                   dd    ?
    ptPaperSize             POINT ?
    rtMinMargin             RECT  ?
    rtMargin                RECT  ?
    hInstance               xword ?
    lCustData               xword ?
    lpfnPageSetupHook       xword ?
    lpfnPagePaintHook       xword ?
    lpPageSetupTemplateName xword ?
    hPageSetupTemplate      xword ?
ends

struc PRINTPAGERANGE
    nFromPage dd  ?
    nToPage   dd  ?
ends

;======================================== gdi32 =======================================;
struc DRAWPATRECT
    ptPosition  POINT ?
    ptSize      POINT ?
    wStyle      dw  ?
    wPattern    dw  ?
ends

struc PSINJECTDATA
    DataBytes       dd  ?
    InjectionPoint  dd  ?
    Flags           dd  ?
    Reserved        dd  ?
ends

struc PSFEATURE_OUTPUT
    bPageIndependent dd ?
    bSetPageDevice   dd ?
ends

struc PSFEATURE_CUSTPAPER
    lOrientation    dd  ?
    lWidth          dd  ?
    lHeight         dd  ?
    lWidthOffset    dd  ?
    lHeightOffset   dd  ?
ends

struc XFORM
    eM11    dd  ?
    eM12    dd  ?
    eM21    dd  ?
    eM22    dd  ?
    elx     dd  ?
    eDy     dd  ?
ends

struc BITMAP
    bmType       dd    ?
    bmWidth      dd    ?
    bmHeight     dd    ?
    bmWidthBytes dd    ?
    bmPlanes     dw    ?
    bmBitsPixel  dw    ?
    bmBits       xword ?
ends

struc RGBTRIPLE
    rgbtBlue    db  ?
    rgbtGreen   db  ?
    rgbtRed     db  ?
ends

struc RGBQUAD
    rgbBlue     db  ?
    rgbGreen    db  ?
    rgbRed      db  ?
    rgbReserved db  ?
ends

struc CIEXYZ
    ciexyzX dd  ?
    ciexyzY dd  ?
    ciexyzZ dd  ?
ends

struc CIEXYZTRIPLE
    ciexyzRed   CIEXYZ ?
    ciexyzGreen CIEXYZ ?
    ciexyzBlue  CIEXYZ ?
ends

struc LOGCOLORSPACEA
    lcsSignature  dd ?
    lcsVersion    dd ?
    lcsSize       dd ?
    lcsCSType     dd ?
    lcsIntent     dd ?
    lcsEndpoints  CIEXYZTRIPLE ?
    lcsGammaRed   dd ?
    lcsGammaGreen dd ?
    lcsGammaBlue  dd ?
    lcsFilename   rb MAX_PATH
ends

struc LOGCOLORSPACEW
    lcsSignature  dd ?
    lcsVersion    dd ?
    lcsSize       dd ?
    lcsCSType     dd ?
    lcsIntent     dd ?
    lcsEndpoints  CIEXYZTRIPLE ?
    lcsGammaRed   dd ?
    lcsGammaGreen dd ?
    lcsGammaBlue  dd ?
    lcsFilename   rw MAX_PATH
ends

struc BITMAPCOREHEADER
    bcSize      dd  ?
    bcWidth     dw  ?
    bcHeight    dw  ?
    bcPlanes    dw  ?
    bcBitCount  dw  ?
ends

struc BITMAPINFOHEADER
    biSize          dd  ?
    biWidth         dd  ?
    biHeight        dd  ?
    biPlanes        dw  ?
    biBitCount      dw  ?
    biCompression   dd  ?
    biSizeImage     dd  ?
    biXPelsPerMeter dd  ?
    biYPelsPerMeter dd  ?
    biClrUsed       dd  ?
    biClrImportant  dd  ?
ends

struc BITMAPV4HEADER
    bV4Size          dd ?
    bV4Width         dd ?
    bV4Height        dd ?
    bV4Planes        dw ?
    bV4BitCount      dw ?
    bV4V4Compression dd ?
    bV4SizeImage     dd ?
    bV4XPelsPerMeter dd ?
    bV4YPelsPerMeter dd ?
    bV4ClrUsed       dd ?
    bV4ClrImportant  dd ?
    bV4RedMask       dd ?
    bV4GreenMask     dd ?
    bV4BlueMask      dd ?
    bV4AlphaMask     dd ?
    bV4CSType        dd ?
    bV4Endpoints     CIEXYZTRIPLE ?
    bV4GammaRed      dd ?
    bV4GammaGreen    dd ?
    bV4GammaBlue     dd ?
ends

struc BITMAPV5HEADER
    bV5Size          dd ?
    bV5Width         dd ?
    bV5Height        dd ?
    bV5Planes        dw ?
    bV5BitCount      dw ?
    bV5Compression   dd ?
    bV5SizeImage     dd ?
    bV5XPelsPerMeter dd ?
    bV5YPelsPerMeter dd ?
    bV5ClrUsed       dd ?
    bV5ClrImportant  dd ?
    bV5RedMask       dd ?
    bV5GreenMask     dd ?
    bV5BlueMask      dd ?
    bV5AlphaMask     dd ?
    bV5CSType        dd ?
    bV5Endpoints     CIEXYZTRIPLE ?
    bV5GammaRed      dd ?
    bV5GammaGreen    dd ?
    bV5GammaBlue     dd ?
    bV5Intent        dd ?
    bV5ProfileData   dd ?
    bV5ProfileSize   dd ?
    bV5Reserved      dd ?
ends

struc BITMAPINFO
    bmiHeader BITMAPINFOHEADER ?
    bmiColors RGBQUAD ?
ends

struc BITMAPCOREINFO
    bmciHeader BITMAPCOREHEADER ?
    bmciColors RGBTRIPLE ?
ends

struc BITMAPFILEHEADER
    bfType      dw  ?
    bfSize      dd  ?
    bfReserved1 dw  ?
    bfReserved2 dw  ?
    bfOffBits   dd  ?
ends

struc FONTSIGNATURE
    fsUsb   rd 4
    fsCsb   rd 2
ends

struc CHARSETINFO
    ciCharset       dd  ?
    ciACP           dd  ?
    _fs             FONTSIGNATURE ?
ends

struc LOCALESIGNATURE
    lsUsb           rd 4
    lsCsbDefault    rd 2
    lsCsbSupported  rd 2
ends

struc HANDLETABLE
    objectHandle    rd 1
ends

struc METARECORD
    rdSize      dd ?
    rdFunction  dw ?
    rdParm      rw 1
ends

struc METAFILEPICT
    mm   dd ?
    xExt dd ?
    yExt dd ?
    hMF  dd ?
ends

struc METAHEADER
    mtType          dw  ?
    mtHeaderSize    dw  ?
    mtVersion       dw  ?
    mtSize          dd  ?
    mtNoObjects     dw  ?
    mtMaxRecord     dd  ?
    mtNoParameters  dw  ?
ends

struc ENHMETARECORD
    iType   dd ?
    nSize   dd ?
    dParm   rd 1
ends

struc ENHMETAHEADER
    iType           dd    ?
    nSize           dd    ?
    rclBounds       RECT  ?
    rclFrame        RECT  ?
    dSignature      dd    ?
    nVersion        dd    ?
    nBytes          dd    ?
    nRecords        dd    ?
    nHandles        dw    ?
    sReserved       dw    ?
    nDescription    dd    ?
    offDescription  dd    ?
    nPalEntries     dd    ?
    szlDevice       SIZEL ?
    szlMillimeters  SIZEL ?
    #if NTDDI_VERSION >= NTDDI_WINNT4
        cbPixelFormat   dd  ?
        offPixelFormat  dd  ?
        bOpenGL         dd  ?
    #endif
    #if NTDDI_VERSION >= NTDDI_WIN2K
        szlMicrometers SIZEL ?
    #endif
ends

struc ENHMETAHEADER3
    iType           dd    ?
    nSize           dd    ?
    rclBounds       RECT  ?
    rclFrame        RECT  ?
    dSignature      dd    ?
    nVersion        dd    ?
    nBytes          dd    ?
    nRecords        dd    ?
    nHandles        dw    ?
    sReserved       dw    ?
    nDescription    dd    ?
    offDescription  dd    ?
    nPalEntries     dd    ?
    szlDevice       SIZEL ?
    szlMillimeters  SIZEL ?
ends

struc TEXTMETRICA
    tmHeight            dd  ?
    tmAscent            dd  ?
    tmDescent           dd  ?
    tmInternalLeading   dd  ?
    tmExternalLeading   dd  ?
    tmAveCharWidth      dd  ?
    tmMaxCharWidth      dd  ?
    tmWeight            dd  ?
    tmOverhang          dd  ?
    tmDigitizedAspectX  dd  ?
    tmDigitizedAspectY  dd  ?
    tmFirstChar         db  ?
    tmLastChar          db  ?
    tmDefaultChar       db  ?
    tmBreakChar         db  ?
    tmItalic            db  ?
    tmUnderlined        db  ?
    tmStruckOut         db  ?
    tmPitchAndFamily    db  ?
    tmCharSet           db  ?
ends

struc TEXTMETRICW
    tmHeight            dd  ?
    tmAscent            dd  ?
    tmDescent           dd  ?
    tmInternalLeading   dd  ?
    tmExternalLeading   dd  ?
    tmAveCharWidth      dd  ?
    tmMaxCharWidth      dd  ?
    tmWeight            dd  ?
    tmOverhang          dd  ?
    tmDigitizedAspectX  dd  ?
    tmDigitizedAspectY  dd  ?
    tmFirstChar         dw  ?
    tmLastChar          dw  ?
    tmDefaultChar       dw  ?
    tmBreakChar         dw  ?
    tmItalic            db  ?
    tmUnderlined        db  ?
    tmStruckOut         db  ?
    tmPitchAndFamily    db  ?
    tmCharSet           db  ?
ends

struc NEWTEXTMETRICA
    tmHeight            dd  ?
    tmAscent            dd  ?
    tmDescent           dd  ?
    tmInternalLeading   dd  ?
    tmExternalLeading   dd  ?
    tmAveCharWidth      dd  ?
    tmMaxCharWidth      dd  ?
    tmWeight            dd  ?
    tmOverhang          dd  ?
    tmDigitizedAspectX  dd  ?
    tmDigitizedAspectY  dd  ?
    tmFirstChar         db  ?
    tmLastChar          db  ?
    tmDefaultChar       db  ?
    tmBreakChar         db  ?
    tmItalic            db  ?
    tmUnderlined        db  ?
    tmStruckOut         db  ?
    tmPitchAndFamily    db  ?
    tmCharSet           db  ?
    ntmFlags            dd  ?
    ntmSizeEM           dd  ?
    ntmCellHeight       dd  ?
    ntmAvgWidth         dd  ?
ends

struc NEWTEXTMETRICW
    tmHeight            dd  ?
    tmAscent            dd  ?
    tmDescent           dd  ?
    tmInternalLeading   dd  ?
    tmExternalLeading   dd  ?
    tmAveCharWidth      dd  ?
    tmMaxCharWidth      dd  ?
    tmWeight            dd  ?
    tmOverhang          dd  ?
    tmDigitizedAspectX  dd  ?
    tmDigitizedAspectY  dd  ?
    tmFirstChar         dw  ?
    tmLastChar          dw  ?
    tmDefaultChar       dw  ?
    tmBreakChar         dw  ?
    tmItalic            db  ?
    tmUnderlined        db  ?
    tmStruckOut         db  ?
    tmPitchAndFamily    db  ?
    tmCharSet           db  ?
    ntmFlags            dd  ?
    ntmSizeEM           dd  ?
    ntmCellHeight       dd  ?
    ntmAvgWidth         dd  ?
ends

struc NEWTEXTMETRICEXA
    ntmTm       NEWTEXTMETRICA ?
    ntmFontSig  FONTSIGNATURE ?
ends

struc NEWTEXTMETRICEXW
    ntmTm       NEWTEXTMETRICW ?
    ntmFontSig  FONTSIGNATURE ?
ends

struc PELARRAY
    paXCount dd ?
    paYCount dd ?
    paXExt   dd ?
    paYExt   dd ?
    paRGBs   db ?
ends

struc LOGBRUSH
    lbStyle dd    ?
    lbColor dd    ?
    lbHatch xword ?
ends

struc LOGPEN
    lopnStyle dd    ?
    lopnWidth POINT ?
    lopnColor dd    ?
ends

struc EXTLOGPEN
    elpPenStyle   dd    ?
    elpWidth      dd    ?
    elpBrushStyle dd    ?
    elpColor      dd    ?
    elpHatch      xword ?
    elpNumEntries dd    ?
    elpStyleEntry rd    1
ends

struc PALETTEENTRY
    peRed   db  ?
    peGreen db  ?
    peBlue  db  ?
    peFlags db  ?
ends

struc LOGPALETTE
    palVersion      dw  ?
    palNumEntries   dw  ?
    palPalEntry     PALETTEENTRY ?
ends

struc LOGFONTA
    lfHeight         dd ?
    lfWidth          dd ?
    lfEscapement     dd ?
    lfOrientation    dd ?
    lfWeight         dd ?
    lfItalic         db ?
    lfUnderline      db ?
    lfStrikeOut      db ?
    lfCharSet        db ?
    lfOutPrecision   db ?
    lfClipPrecision  db ?
    lfQuality        db ?
    lfPitchAndFamily db ?
    lfFaceName       rb LF_FACESIZE
ends

struc LOGFONTW
    lfHeight         dd ?
    lfWidth          dd ?
    lfEscapement     dd ?
    lfOrientation    dd ?
    lfWeight         dd ?
    lfItalic         db ?
    lfUnderline      db ?
    lfStrikeOut      db ?
    lfCharSet        db ?
    lfOutPrecision   db ?
    lfClipPrecision  db ?
    lfQuality        db ?
    lfPitchAndFamily db ?
    lfFaceName       rw LF_FACESIZE
ends

struc ENUMLOGFONTA
    elfLogFont  LOGFONTA ?
    elfFullName rb LF_FULLFACESIZE
    elfStyle    rb LF_FACESIZE
ends

struc ENUMLOGFONTW
    elfLogFont  LOGFONTW ?
    elfFullName rw LF_FULLFACESIZE
    elfStyle    rw LF_FACESIZE
ends

struc ENUMLOGFONTEXA
    elfLogFont  LOGFONTA ?
    elfFullName rb LF_FULLFACESIZE
    elfStyle    rb LF_FACESIZE
    elfScript   rb LF_FACESIZE
ends

struc ENUMLOGFONTEXW
    elfLogFont  LOGFONTW ?
    elfFullName rw LF_FULLFACESIZE
    elfStyle    rw LF_FACESIZE
    elfScript   rw LF_FACESIZE
ends

struc PANOSE
    bFamilyType      db ?
    bSerifStyle      db ?
    bWeight          db ?
    bProportion      db ?
    bContrast        db ?
    bStrokeVariation db ?
    bArmStyle        db ?
    bLetterform      db ?
    bMidline         db ?
    bXHeight         db ?
ends

struc EXTLOGFONTA
    elfLogFont   LOGFONTA ?
    elfFullName  rb LF_FULLFACESIZE
    elfStyle     rb LF_FACESIZE
    elfVersion   dd ?
    elfStyleSize dd ?
    elfMatch     dd ?
    elfReserved  dd ?
    elfVendorId  rb ELF_VENDOR_SIZE
    elfCulture   dd ?
    elfPanose    PANOSE ?
ends

struc EXTLOGFONTW
    elfLogFont   LOGFONTW ?
    elfFullName  rw LF_FULLFACESIZE
    elfStyle     rw LF_FACESIZE
    elfVersion   dd ?
    elfStyleSize dd ?
    elfMatch     dd ?
    elfReserved  dd ?
    elfVendorId  rb ELF_VENDOR_SIZE
    elfCulture   dd ?
    elfPanose    PANOSE ?
ends

struc DISPLAY_DEVICEA
    cb           dd ?
    DeviceName   rb 32
    DeviceString rb 128
    StateFlags   dd ?
ends

struc DISPLAY_DEVICEW
    cb           dd ?
    DeviceName   rw 32
    DeviceString rw 128
    StateFlags   dd ?
ends

struc RGNDATAHEADER
    dwSize   dd ?
    iType    dd ?
    nCount   dd ?
    nRgnSize dd ?
    rcBound  RECT ?
ends

struc RGNDATA
    rdh     RGNDATAHEADER ?
    Buffer  rb 1
ends

struc ABC
    abcA dd ?
    abcB dd ?
    abcC dd ?
ends

struc ABCFLOAT
    abcfA dd ?
    abcfB dd ?
    abcfC dd ?
ends

struc OUTLINETEXTMETRICA
    otmSize                 dd  ?
    otmTextMetrics          TEXTMETRICA ?
    otmFiller               db  ?
    otmPanoseNumber         PANOSE ?
    otmfsSelection          dd  ?
    otmfsType               dd  ?
    otmsCharSlopeRise       dd  ?
    otmsCharSlopeRun        dd  ?
    otmItalicAngle          dd  ?
    otmEMSquare             dd  ?
    otmAscent               dd  ?
    otmDescent              dd  ?
    otmLineGap              dd  ?
    otmsCapEmHeight         dd  ?
    otmsXHeight             dd  ?
    otmrcFontBox            RECT ?
    otmMacAscent            dd  ?
    otmMacDescent           dd  ?
    otmMacLineGap           dd  ?
    otmusMinimumPPEM        dd  ?
    otmptSubscriptSize      POINT ?
    otmptSubscriptOffset    POINT ?
    otmptSuperscriptSize    POINT ?
    otmptSuperscriptOffset  POINT ?
    otmsStrikeoutSize       dd  ?
    otmsStrikeoutPosition   dd  ?
    otmsUnderscoreSize      dd  ?
    otmsUnderscorePosition  dd  ?
    otmpFamilyName          dd  ?
    otmpFaceName            dd  ?
    otmpStyleName           dd  ?
    otmpFullName            dd  ?
ends

struc OUTLINETEXTMETRICW
    otmSize                 dd  ?
    otmTextMetrics          TEXTMETRICW ?
    otmFiller               db  ?
    otmPanoseNumber         PANOSE ?
    otmfsSelection          dd  ?
    otmfsType               dd  ?
    otmsCharSlopeRise       dd  ?
    otmsCharSlopeRun        dd  ?
    otmItalicAngle          dd  ?
    otmEMSquare             dd  ?
    otmAscent               dd  ?
    otmDescent              dd  ?
    otmLineGap              dd  ?
    otmsCapEmHeight         dd  ?
    otmsXHeight             dd  ?
    otmrcFontBox            RECT ?
    otmMacAscent            dd  ?
    otmMacDescent           dd  ?
    otmMacLineGap           dd  ?
    otmusMinimumPPEM        dd  ?
    otmptSubscriptSize      POINT ?
    otmptSubscriptOffset    POINT ?
    otmptSuperscriptSize    POINT ?
    otmptSuperscriptOffset  POINT ?
    otmsStrikeoutSize       dd  ?
    otmsStrikeoutPosition   dd  ?
    otmsUnderscoreSize      dd  ?
    otmsUnderscorePosition  dd  ?
    otmpFamilyName          dd  ?
    otmpFaceName            dd  ?
    otmpStyleName           dd  ?
    otmpFullName            dd  ?
ends

struc POLYTEXTA
    x       dd  ?
    y       dd  ?
    n       dd  ?
    lpstr   dd  ?
    uiFlags dd  ?
    _rcl    RECT ?
    pdx     dd  ?
ends

struc POLYTEXTW
    x       dd  ?
    y       dd  ?
    n       dd  ?
    lpstr   dd  ?
    uiFlags dd  ?
    _rcl    RECT ?
    pdx     dd  ?
ends

struc FIXED
    fract   dw  ?
    value   dw  ?
ends

struc MAT2
    eM11 FIXED ?
    eM12 FIXED ?
    eM21 FIXED ?
    eM22 FIXED ?
ends

struc GLYPHMETRICS
    gmBlackBoxX     dd  ?
    gmBlackBoxY     dd  ?
    gmptGlyphOrigin POINT ?
    gmCellIncX      dw  ?
    gmCellIncY      dw  ?
ends

struc POINTFX
    x FIXED ?
    y FIXED ?
ends

struc TTPOLYCURVE
    wType   dw  ?
    cpfx    dw  ?
    apfx    POINTFX ?
ends

struc TTPOLYGONHEADER
    cb       dd  ?
    dwType   dd  ?
    pfxStart POINTFX ?
ends

struc GCP_RESULTSA
    lStructSize dd  ?
    lpOutString dd  ?
    lpOrder     dd  ?
    lpDx        dd  ?
    lpCaretPos  dd  ?
    lpClass     dd  ?
    lpGlyphs    dd  ?
    nGlyphs     dd  ?
    nMaxFit     dd  ?
ends

struc GCP_RESULTSW
    lStructSize dd  ?
    lpOutString dd  ?
    lpOrder     dd  ?
    lpDx        dd  ?
    lpCaretPos  dd  ?
    lpClass     dd  ?
    lpGlyphs    dd  ?
    nGlyphs     dd  ?
    nMaxFit     dd  ?
ends

struc RASTERIZER_STATUS
    nSize       dw  ?
    wFlags      dw  ?
    nLanguageID dw  ?
ends

struc PIXELFORMATDESCRIPTOR
    nSize           dw  ?
    nVersion        dw  ?
    dwFlags         dd  ?
    iPixelType      db  ?
    cColorBits      db  ?
    cRedBits        db  ?
    cRedShift       db  ?
    cGreenBits      db  ?
    cGreenShift     db  ?
    cBlueBits       db  ?
    cBlueShift      db  ?
    cAlphaBits      db  ?
    cAlphaShift     db  ?
    cAccumBits      db  ?
    cAccumRedBits   db  ?
    cAccumGreenBits db  ?
    cAccumBlueBits  db  ?
    cAccumAlphaBits db  ?
    cDepthBits      db  ?
    cStencilBits    db  ?
    cAuxBuffers     db  ?
    iLayerType      db  ?
    bReserved       db  ?
    dwLayerMask     dd  ?
    dwVisibleMask   dd  ?
    dwDamageMask    dd  ?
ends

struc WCRANGE
    wcLow   dw  ?
    cGlyphs dw  ?
ends

struc GLYPHSET
    cbThis           dd ?
    flAccel          dd ?
    cGlyphsSupported dd ?
    cRanges          dd ?
    ranges           WCRANGE ?
ends

struc DESIGNVECTOR
    dvReserved  dd  ?
    dvNumAxes   dd  ?
    dvValues    rd MM_MAX_NUMAXES
ends

struc AXISINFOA
    axMinValue  dd  ?
    axMaxValue  dd  ?
    axAxisName  rb MM_MAX_AXES_NAMELEN
ends

struc AXISINFOW
    axMinValue  dd  ?
    axMaxValue  dd  ?
    axAxisName  rw MM_MAX_AXES_NAMELEN
ends

struc AXESLISTA
    axlReserved dd ?
    axlNumAxes  dd ?
    axlAxisInfo rs AXISINFOA,MM_MAX_NUMAXES
ends

struc AXESLISTW
    axlReserved dd ?
    axlNumAxes  dd ?
    axlAxisInfo rs AXISINFOW,MM_MAX_NUMAXES
ends

struc ENUMLOGFONTEXDVA
    elfEnumLogfontEx ENUMLOGFONTEXA ?
    elfDesignVector  DESIGNVECTOR ?
ends

struc ENUMLOGFONTEXDVW
    elfEnumLogfontEx ENUMLOGFONTEXW ?
    elfDesignVector  DESIGNVECTOR ?
ends

struc ENUMTEXTMETRICA
    etmNewTextMetricEx NEWTEXTMETRICEXA ?
    etmAxesList        AXESLISTA ?
ends

struc ENUMTEXTMETRICW
    etmNewTextMetricEx NEWTEXTMETRICEXW ?
    etmAxesList        AXESLISTW ?
ends

struc TRIVERTEX
    x       dd  ?
    y       dd  ?
    _Red    dw  ?
    _Green  dw  ?
    _Blue   dw  ?
    Alpha   dw  ?
ends

struc GRADIENT_TRIANGLE
    Vertex1 dd  ?
    Vertex2 dd  ?
    Vertex3 dd  ?
ends

struc GRADIENT_RECT
    UpperLeft   dd  ?
    LowerRight  dd  ?
ends

struc BLENDFUNCTION
    BlendOp             db  ?
    BlendFlags          db  ?
    SourceConstantAlpha db  ?
    AlphaFormat         db  ?
ends

struc DIBSECTION
    dsBm        BITMAP ?
    dsBmih      BITMAPINFOHEADER ?
    dsBitfields rd    3
    dshSection  xword ?
    dsOffset    dd    ?
ends

struc COLORADJUSTMENT
    caSize              dw  ?
    caFlags             dw  ?
    caIlluminantIndex   dw  ?
    caRedGamma          dw  ?
    caGreenGamma        dw  ?
    caBlueGamma         dw  ?
    caReferenceBlack    dw  ?
    caReferenceWhite    dw  ?
    caContrast          dw  ?
    caBrightness        dw  ?
    caColorfulness      dw  ?
    caRedGreenTint      dw  ?
ends

struc DOCINFOA
    cbSize       dd  ?
    lpszDocName  dd  ?
    lpszOutput   dd  ?
    #if NTDDI_VERSION >= NTDDI_WINNT4
        lpszDatatype dd  ?
        fwType       dd  ?
    #endif
ends

struc DOCINFOW
    cbSize       dd  ?
    lpszDocName  dd  ?
    lpszOutput   dd  ?
    #if NTDDI_VERSION >= NTDDI_WINNT4
        lpszDatatype dd  ?
        fwType       dd  ?
    #endif
ends

struc KERNINGPAIR
    wFirst      dw  ?
    wSecond     dw  ?
    iKernAmount dd  ?
ends

struc EMR
    iType dd  ?
    nSize dd  ?
ends

struc ABORTPATH
    emr EMR ?
ends

struc EMRTEXT
    ptlReference POINT ?
    nChars       dd  ?
    offString    dd  ?
    fOptions     dd  ?
    _rcl         RECT ?
    offDx        dd  ?
ends

struc EMRABORTPATH
    emr EMR ?
ends

struc EMRBEGINPATH
    emr EMR ?
ends

struc EMRENDPATH
    emr EMR ?
ends

struc EMRCLOSEFIGURE
    emr EMR ?
ends

struc EMRFLATTENPATH
    emr EMR ?
ends

struc EMRWIDENPATH
    emr EMR ?
ends

struc EMRSETMETARGN
    emr EMR ?
ends

struc EMRSAVEDC
    emr EMR ?
ends

struc EMRREALIZEPALETTE
    emr EMR ?
ends

struc EMRSELECTCLIPPATH
    emr     EMR ?
    iMode   dd  ?
ends

struc EMRSETMITERLIMIT
    emr         EMR ?
    eMiterLimit dd  ?
ends

struc EMRRESTOREDC
    emr         EMR ?
    iRelative   dd  ?
ends

struc EMRSETARCDIRECTION
    emr           EMR ?
    iArcDirection dd  ?
ends

struc EMRSETMAPPERFLAGS
    emr     EMR ?
    dwFlags dd  ?
ends

struc EMRSETBKCOLOR
    emr     EMR ?
    crColor dd  ?
ends

struc EMRSETTEXTCOLOR
    emr     EMR ?
    crColor dd  ?
ends

struc EMRSELECTOBJECT
    emr      EMR ?
    ihObject dd  ?
ends

struc EMRDELETEOBJECT
    emr      EMR ?
    ihObject dd  ?
ends

struc EMRSELECTCOLORSPACE
    emr     EMR ?
    ihCS    dd  ?
ends

struc EMRDELETECOLORSPACE
    emr     EMR ?
    ihCS    dd  ?
ends

struc EMRSELECTPALETTE
    emr     EMR ?
    ihPal   dd  ?
ends

struc EMRRESIZEPALETTE
    emr      EMR ?
    ihPal    dd  ?
    cEntries dd  ?
ends

struc EMRSETPALETTEENTRIES
    emr         EMR ?
    ihPal       dd  ?
    iStart      dd  ?
    cEntries    dd  ?
    aPalEntries PALETTEENTRY ?
ends

struc EMRSETCOLORADJUSTMENT
    emr             EMR ?
    ColorAdjustment COLORADJUSTMENT ?
ends

struc EMRGDICOMMENT
    emr     EMR ?
    cbData  dd  ?
    Data    rb  1
ends

struc EMREOF
    emr             EMR ?
    nPalEntries     dd  ?
    offPalEntries   dd  ?
    nSizeLast       dd  ?
ends

struc EMRLINETO
    emr EMR ?
    ptl POINT ?
ends

struc EMRMOVETOEX
    emr EMR ?
    ptl POINT ?
ends

struc EMROFFSETCLIPRGN
    emr       EMR ?
    ptlOffset POINT ?
ends

struc EMRFILLPATH
    emr         EMR ?
    rclBounds   RECT ?
ends

struc EMRSTROKEANDFILLPATH
    emr         EMR ?
    rclBounds   RECT ?
ends

struc EMRSTROKEPATH
    emr         EMR ?
    rclBounds   RECT ?
ends

struc EMREXCLUDECLIPRECT
    emr     EMR ?
    rclClip RECT ?
ends

struc EMRINTERSECTCLIPRECT
    emr     EMR ?
    rclClip RECT ?
ends

struc EMRSETVIEWPORTORGEX
    emr       EMR ?
    ptlOrigin POINT ?
ends

struc EMRSETWINDOWORGEX
    emr       EMR ?
    ptlOrigin POINT ?
ends

struc EMRSETBRUSHORGEX
    emr       EMR ?
    ptlOrigin POINT ?
ends

struc EMRSETVIEWPORTEXTEX
    emr       EMR ?
    szlExtent SIZEL ?
ends

struc EMRSETWINDOWEXTEX
    emr       EMR ?
    szlExtent SIZEL ?
ends

struc EMRSCALEVIEWPORTEXTEX
    emr     EMR ?
    xNum    dd  ?
    xDenom  dd  ?
    yNum    dd  ?
    yDenom  dd  ?
ends

struc EMRSCALEWINDOWEXTEX
    emr     EMR ?
    xNum    dd  ?
    xDenom  dd  ?
    yNum    dd  ?
    yDenom  dd  ?
ends

struc EMRSETWORLDTRANSFORM
    emr     EMR ?
    xform   XFORM ?
ends

struc EMRMODIFYWORLDTRANSFORM
    emr     EMR ?
    xform   XFORM ?
    iMode   dd  ?
ends

struc EMRSETPIXELV
    emr      EMR ?
    ptlPixel POINT ?
    crColor  dd  ?
ends

struc EMREXTFLOODFILL
    emr      EMR ?
    ptlStart POINT ?
    crColor  dd  ?
    iMode    dd  ?
ends

struc EMRELLIPSE
    emr    EMR ?
    rclBox RECT ?
ends

struc EMRRECTANGLE
    emr    EMR ?
    rclBox RECT ?
ends

struc EMRROUNDRECT
    emr       EMR ?
    rclBox    RECT ?
    szlCorner SIZEL ?
ends

struc EMRARC
    emr      EMR ?
    rclBox   RECT ?
    ptlStart POINT ?
    ptlEnd   POINT ?
ends

struc EMRARCTO
    emr      EMR ?
    rclBox   RECT ?
    ptlStart POINT ?
    ptlEnd   POINT ?
ends

struc EMRCHORD
    emr      EMR ?
    rclBox   RECT ?
    ptlStart POINT ?
    ptlEnd   POINT ?
ends

struc EMRPIE
    emr      EMR ?
    rclBox   RECT ?
    ptlStart POINT ?
    ptlEnd   POINT ?
ends

struc EMRANGLEARC
    emr         EMR ?
    ptlCenter   POINT ?
    nRadius     dd  ?
    eStartAngle dd  ?
    eSweepAngle dd  ?
ends

struc EMRPOLYLINE
    emr         EMR ?
    rclBounds   RECT ?
    cptl        dd  ?
    aptl        POINT ?
ends

struc EMRPOLYBEZIER
    emr         EMR ?
    rclBounds   RECT ?
    cptl        dd  ?
    aptl        POINT ?
ends

struc EMRPOLYGON
    emr         EMR ?
    rclBounds   RECT ?
    cptl        dd  ?
    aptl        POINT ?
ends

struc EMRPOLYBEZIERTO
    emr         EMR ?
    rclBounds   RECT ?
    cptl        dd  ?
    aptl        POINT ?
ends

struc EMRPOLYLINETO
    emr         EMR ?
    rclBounds   RECT ?
    cptl        dd  ?
    aptl        POINT ?
ends

struc EMRPOLYLINE16
    emr         EMR ?
    rclBounds   RECT ?
    cpts        dd  ?
    apts        POINTS ?
ends

struc EMRPOLYBEZIER16
    emr         EMR ?
    rclBounds   RECT ?
    cpts        dd  ?
    apts        POINTS ?
ends

struc EMRPOLYGON16
    emr         EMR ?
    rclBounds   RECT ?
    cpts        dd  ?
    apts        POINTS ?
ends

struc EMRPOLYBEZIERTO16
    emr         EMR ?
    rclBounds   RECT ?
    cpts        dd  ?
    apts        POINTS ?
ends

struc EMRPOLYLINETO16
    emr         EMR ?
    rclBounds   RECT ?
    cpts        dd  ?
    apts        POINTS ?
ends

struc EMRPOLYDRAW
    emr         EMR ?
    rclBounds   RECT ?
    cptl        dd  ?
    aptl        POINT ?
    abTypes     rb  1
ends

struc EMRPOLYDRAW16
    emr         EMR ?
    rclBounds   RECT ?
    cpts        dd ?
    apts        POINTS ?
    abTypes     rb 1
ends

struc EMRPOLYPOLYLINE
    emr         EMR ?
    rclBounds   RECT ?
    nPolys      dd ?
    cptl        dd ?
    aPolyCounts rd 1
    aptl        POINT ?
ends

struc EMRPOLYPOLYGON
    emr         EMR ?
    rclBounds   RECT ?
    nPolys      dd ?
    cptl        dd ?
    aPolyCounts rd 1
    aptl        POINT ?
ends

struc EMRPOLYPOLYLINE16
    emr         EMR ?
    rclBounds   RECT ?
    nPolys      dd ?
    cpts        dd ?
    aPolyCounts rd 1
    apts        POINTS ?
ends

struc EMRPOLYPOLYGON16
    emr         EMR ?
    rclBounds   RECT ?
    nPolys      dd ?
    cpts        dd ?
    aPolyCounts rd 1
    apts        POINTS ?
ends

struc EMRINVERTRGN
    emr         EMR ?
    rclBounds   RECT ?
    cbRgnData   dd ?
    RgnData     rb 1
ends

struc EMRPAINTRGN
    emr         EMR ?
    rclBounds   RECT ?
    cbRgnData   dd ?
    RgnData     rb 1
ends

struc EMRFILLRGN
    emr         EMR ?
    rclBounds   RECT ?
    cbRgnData   dd ?
    ihBrush     dd ?
    RgnData     rb 1
ends

struc EMRFRAMERGN
    emr         EMR ?
    rclBounds   RECT ?
    cbRgnData   dd ?
    ihBrush     dd ?
    szlStroke   SIZEL ?
    RgnData     rb 1
ends

struc EMRGRADIENTFILL
    emr         EMR ?
    rclBounds   RECT ?
    nVer        dd ?
    nTri        dd ?
    ulMode      dd ?
    Ver         TRIVERTEX ?
ends

struc EMRTRANSPARENTBLT
    emr          EMR ?
    rclBounds    RECT ?
    xDest        dd ?
    yDest        dd ?
    cxDest       dd ?
    cyDest       dd ?
    dwRop        dd ?
    xSrc         dd ?
    ySrc         dd ?
    xformSrc     XFORM ?
    crBkColorSrc dd ?
    iUsageSrc    dd ?
    offBmiSrc    dd ?
    cbBmiSrc     dd ?
    offBitsSrc   dd ?
    cbBitsSrc    dd ?
    cxSrc        dd ?
    cySrc        dd ?
ends

struc EMREXTSELECTCLIPRGN
    emr         EMR ?
    cbRgnData   dd ?
    iMode       dd ?
    RgnData     rb 1
ends

struc EMREXTTEXTOUTA
    emr           EMR ?
    rclBounds     RECT ?
    iGraphicsMode dd ?
    exScale       dd ?
    eyScale       dd ?
    emrtext       EMRTEXT ?
ends

struc EMREXTTEXTOUTW
    emr           EMR ?
    rclBounds     RECT ?
    iGraphicsMode dd ?
    exScale       dd ?
    eyScale       dd ?
    emrtext       EMRTEXT ?
ends

struc EMRPOLYTEXTOUTA
    emr           EMR ?
    rclBounds     RECT ?
    iGraphicsMode dd ?
    exScale       dd ?
    eyScale       dd ?
    cStrings      dd ?
    aemrtext      EMRTEXT ?
ends

struc EMRPOLYTEXTOUTW
    emr           EMR ?
    rclBounds     RECT ?
    iGraphicsMode dd ?
    exScale       dd ?
    eyScale       dd ?
    cStrings      dd ?
    aemrtext      EMRTEXT ?
ends

struc EMRBITBLT
    emr          EMR ?
    rclBounds    RECT ?
    xDest        dd ?
    yDest        dd ?
    cxDest       dd ?
    cyDest       dd ?
    dwRop        dd ?
    xSrc         dd ?
    ySrc         dd ?
    xformSrc     XFORM ?
    crBkColorSrc dd ?
    iUsageSrc    dd ?
    offBmiSrc    dd ?
    cbBmiSrc     dd ?
    offBitsSrc   dd ?
    cbBitsSrc    dd ?
ends

struc EMRSTRETCHBLT
    emr          EMR ?
    rclBounds    RECT ?
    xDest        dd ?
    yDest        dd ?
    cxDest       dd ?
    cyDest       dd ?
    dwRop        dd ?
    xSrc         dd ?
    ySrc         dd ?
    xformSrc     XFORM ?
    crBkColorSrc dd ?
    iUsageSrc    dd ?
    offBmiSrc    dd ?
    cbBmiSrc     dd ?
    offBitsSrc   dd ?
    cbBitsSrc    dd ?
    cxSrc        dd ?
    cySrc        dd ?
ends

struc EMRMASKBLT
    emr          EMR ?
    rclBounds    RECT ?
    xDest        dd ?
    yDest        dd ?
    cxDest       dd ?
    cyDest       dd ?
    dwRop        dd ?
    xSrc         dd ?
    ySrc         dd ?
    xformSrc     XFORM ?
    crBkColorSrc dd ?
    iUsageSrc    dd ?
    offBmiSrc    dd ?
    cbBmiSrc     dd ?
    offBitsSrc   dd ?
    cbBitsSrc    dd ?
    xMask        dd ?
    yMask        dd ?
    iUsageMask   dd ?
    offBmiMask   dd ?
    cbBmiMask    dd ?
    offBitsMask  dd ?
    cbBitsMask   dd ?
ends

struc EMRPLGBLT
    emr          EMR ?
    rclBounds    RECT ?
    aptlDest     rs POINT,3
    xSrc         dd ?
    ySrc         dd ?
    cxSrc        dd ?
    cySrc        dd ?
    xformSrc     XFORM ?
    crBkColorSrc dd ?
    iUsageSrc    dd ?
    offBmiSrc    dd ?
    cbBmiSrc     dd ?
    offBitsSrc   dd ?
    cbBitsSrc    dd ?
    xMask        dd ?
    yMask        dd ?
    iUsageMask   dd ?
    offBmiMask   dd ?
    cbBmiMask    dd ?
    offBitsMask  dd ?
    cbBitsMask   dd ?
ends

struc EMRSETDIBITSTODEVICE
    emr         EMR ?
    rclBounds   RECT ?
    xDest       dd  ?
    yDest       dd  ?
    xSrc        dd  ?
    ySrc        dd  ?
    cxSrc       dd  ?
    cySrc       dd  ?
    offBmiSrc   dd  ?
    cbBmiSrc    dd  ?
    offBitsSrc  dd  ?
    cbBitsSrc   dd  ?
    iUsageSrc   dd  ?
    iStartScan  dd  ?
    cScans      dd  ?
ends

struc EMRSTRETCHDIBITS
    emr         EMR ?
    rclBounds   RECT ?
    xDest       dd  ?
    yDest       dd  ?
    xSrc        dd  ?
    ySrc        dd  ?
    cxSrc       dd  ?
    cySrc       dd  ?
    offBmiSrc   dd  ?
    cbBmiSrc    dd  ?
    offBitsSrc  dd  ?
    cbBitsSrc   dd  ?
    iUsageSrc   dd  ?
    dwRop       dd  ?
    cxDest      dd  ?
    cyDest      dd  ?
ends

struc EMRALPHABLE
    emr          EMR ?
    rclBounds    RECT ?
    xDest        dd ?
    yDest        dd ?
    cxDest       dd ?
    cyDest       dd ?
    dwRop        dd ?
    xSrc         dd ?
    ySrc         dd ?
    xformSrc     XFORM ?
    crBkColorSrc dd ?
    iUsageSrc    dd ?
    offBmiSrc    dd ?
    cbBmiSrc     dd ?
    offBitsSrc   dd ?
    cbBitsSrc    dd ?
    cxSrc        dd ?
    cySrc        dd ?
ends

struc EMREMRTRANSPARENTBLT
    emr          EMR ?
    rclBounds    RECT ?
    xDest        dd ?
    yDest        dd ?
    cxDest       dd ?
    cyDest       dd ?
    dwRop        dd ?
    xSrc         dd ?
    ySrc         dd ?
    xformSrc     XFORM ?
    crBkColorSrc dd ?
    iUsageSrc    dd ?
    offBmiSrc    dd ?
    cbBmiSrc     dd ?
    offBitsSrc   dd ?
    cbBitsSrc    dd ?
    cxSrc        dd ?
    cySrc        dd ?
ends

struc EMREXTCREATEFONTINDIRECTA
    emr     EMR ?
    ihFont  dd ?
    elfw    EXTLOGFONTA ?
ends

struc EMREXTCREATEFONTINDIRECTW
    emr     EMR ?
    ihFont  dd ?
    elfw    EXTLOGFONTW ?
ends

struc EMRCREATEPALETTE
    emr     EMR ?
    ihPal   dd ?
    lgpl    LOGPALETTE ?
ends

struc EMRCREATECOLORSPACE
    emr  EMR ?
    ihCS dd ?
    lcs  LOGCOLORSPACEW ?
ends

struc EMRSETCOLORSPACE
    emr  EMR ?
    ihCS dd ?
ends

struc EMREXTESCAPE
    emr         EMR ?
    iEscape     dd ?
    cbEscData   dd ?
    EscData     db ?
ends

struc EMRNAMEDESCAPE
    emr         EMR ?
    iEscape     dd ?
    cbDriver    dd ?
    cbEscData   dd ?
    EscData     db ?
ends

struc EMRCREATEPEN
    emr     EMR ?
    ihPen   dd ?
    lopn    LOGPEN ?
ends

struc EMREXTCREATEPEN
    emr     EMR ?
    ihPen   dd ?
    offBmi  dd ?
    cbBmi   dd ?
    offBits dd ?
    cbBits  dd ?
    elp     EXTLOGPEN ?
ends

struc EMRCREATEBRUSHINDIRECT
    emr     EMR ?
    ihBrush dd ?
    lb      LOGBRUSH ?
ends

struc EMRCREATEMONOBRUSH
    emr     EMR ?
    ihBrush dd ?
    iUsage  dd ?
    offBmi  dd ?
    cbBmi   dd ?
    offBits dd ?
    cbBits  dd ?
ends

struc EMRCREATEDIBPATTERNBRUSHPT
    emr     EMR ?
    ihBrush dd ?
    iUsage  dd ?
    offBmi  dd ?
    cbBmi   dd ?
    offBits dd ?
    cbBits  dd ?
ends

struc EMRFORMAT
    dSignature  dd  ?
    nVersion    dd  ?
    cbData      dd  ?
    offData     dd  ?
ends

struc EMRGLSRECORD
    emr     EMR ?
    cbData  dd ?
    Data    rb 1
ends

struc EMRGLSBOUNDEDRECORD
    emr         EMR ?
    rclBounds   RECT ?
    cbData      dd ?
    Data        rb 1
ends

struc EMRPIXELFORMAT
    emr EMR ?
    pfd PIXELFORMATDESCRIPTOR ?
ends

struc EMRSETICMPROFILE
    emr     EMR ?
    dwFlags dd ?
    cbName  dd ?
    cbData  dd ?
    Data    rb 1
ends

struc EMRCREATECOLORSPACEW
    emr     EMR ?
    ihCS    dd ?
    lcs     LOGCOLORSPACEW ?
    dwFlags dd ?
    cbData  dd ?
    Data    db ?
ends

struc COLORMATCHTOTARGET
    emr      EMR ?
    dwAction dd ?
    dwFlags  dd ?
    cbName   dd ?
    cbData   dd ?
    Data     db ?
ends

struc COLORCORRECTPALETTE
    emr         EMR ?
    ihPalette   dd ?
    nFirstEntry dd ?
    nPalEntries dd ?
    nReserved   dd ?
ends

struc EMRALPHABLEND
    emr          EMR ?
    rclBounds    RECT ?
    xDest        dd ?
    yDest        dd ?
    cxDest       dd ?
    cyDest       dd ?
    dwRop        dd ?
    xSrc         dd ?
    ySrc         dd ?
    xformSrc     XFORM ?
    crBkColorSrc dd ?
    iUsageSrc    dd ?
    offBmiSrc    dd ?
    cbBmiSrc     dd ?
    offBitsSrc   dd ?
    cbBitsSrc    dd ?
    cxSrc        dd ?
    cySrc        dd ?
ends

struc POINTFLOAT
    x dd  ?
    y dd  ?
ends

struc GLYPHMETRICSFLOAT
    gmfBlackBoxX     dd ?
    gmfBlackBoxY     dd ?
    gmfptGlyphOrigin POINTFLOAT ?
    gmfCellIncX      dd ?
    gmfCellIncY      dd ?
ends

struc LAYERPLANEDESCRIPTOR
    nSize           dw  ?
    nVersion        dw  ?
    dwFlags         dd  ?
    iPixelType      db  ?
    cColorBits      db  ?
    cRedBits        db  ?
    cRedShift       db  ?
    cGreenBits      db  ?
    cGreenShift     db  ?
    cBlueBits       db  ?
    cBlueShift      db  ?
    cAlphaBits      db  ?
    cAlphaShift     db  ?
    cAccumBits      db  ?
    cAccumRedBits   db  ?
    cAccumGreenBits db  ?
    cAccumBlueBits  db  ?
    cAccumAlphaBits db  ?
    cDepthBits      db  ?
    cStencilBits    db  ?
    cAuxBuffers     db  ?
    iLayerPlane     db  ?
    bReserved       db  ?
    crTransparent   dd  ?
ends

struc WGLSWAP
    hdc     dd  ?
    uiFlags dd  ?
ends

struc GDIREGISTERDDRAWPACKET
    dwSize          dd    ?
    dwVersion       dd    ?
    pfnDdMarshal    xword ?
    pfnDdUnmarshal  xword ?
    pfnDdRelease    xword ?
ends

struc DISPLAYCONFIG_RATIONAL
    Numerator   dd  ?
    Denominator dd  ?
ends

struc DISPLAYCONFIG_2DREGION
    _cx dd  ?
    cy  dd  ?
ends

struc DISPLAYCONFIG_VIDEO_SIGNAL_INFO
    pixelRate        dq ?
    hSyncFreq        DISPLAYCONFIG_RATIONAL ?
    vSyncFreq        DISPLAYCONFIG_RATIONAL ?
    activeSize       DISPLAYCONFIG_2DREGION ?
    totalSize        DISPLAYCONFIG_2DREGION ?
    videoStandard    dd ?
    scanLineOrdering dd ?
ends

struc DISPLAYCONFIG_SOURCE_MODE
    _width      dd ?
    height      dd ?
    pixelFormat dd ?
    position    POINT ?
ends

struc DISPLAYCONFIG_TARGET_MODE
    targetVideoSignalInfo DISPLAYCONFIG_VIDEO_SIGNAL_INFO ?
ends

struc DISPLAYCONFIG_MODE_INFO
    infoType    dd ?
    id          dd ?
    adapterId   LUID ?
    union
        targetMode DISPLAYCONFIG_TARGET_MODE ?
        sourceMode DISPLAYCONFIG_SOURCE_MODE ?
    endu
ends

struc DISPLAYCONFIG_PATH_SOURCE_INFO
    adapterId   LUID ?
    id          dd ?
    modeInfoIdx dd ?
    statusFlags dd ?
ends

struc DISPLAYCONFIG_PATH_TARGET_INFO
    adapterId        LUID ?
    id               dd ?
    modeInfoIdx      dd ?
    outputTechnology dd ?
    rotation         dd ?
    scaling          dd ?
    refreshRate      DISPLAYCONFIG_RATIONAL ?
    scanLineOrdering dd ?
    targetAvailable  dd ?
    statusFlags      dd ?
ends

struc DISPLAYCONFIG_PATH_INFO
    sourceInfo DISPLAYCONFIG_PATH_SOURCE_INFO ?
    targetInfo DISPLAYCONFIG_PATH_SOURCE_INFO ?
    flags      dd ?
ends

struc DISPLAYCONFIG_DEVICE_INFO_HEADER
    _type     dd ?
    _size     dd ?
    adapterId LUID ?
    id        dd ?
ends

struc DISPLAYCONFIG_SOURCE_DEVICE_NAME
    header            DISPLAYCONFIG_DEVICE_INFO_HEADER ?
    viewGdiDeviceName rw CCHDEVICENAME
ends

struc DISPLAYCONFIG_TARGET_DEVICE_NAME
    header                    DISPLAYCONFIG_DEVICE_INFO_HEADER ?
    flags                     dd ?
    outputTechnology          dd ?
    edidManufactureId         dw ?
    edidProductCodeId         dw ?
    connectorInstance         dd ?
    monitorFriendlyDeviceName rw 64
    monitorDevicePath         rw 128
ends

struc DISPLAYCONFIG_TARGET_PREFERRED_MODE
    header      DISPLAYCONFIG_DEVICE_INFO_HEADER ?
    _width      dd ?
    height      dd ?
    targetMode  dd ?
ends

struc DISPLAYCONFIG_ADAPTER_NAME
    header            DISPLAYCONFIG_DEVICE_INFO_HEADER ?
    adapterDevicePath rw 128
ends

;======================================== gdiplus =======================================;
struc GdiplusStartupInput
    GdiplusVersion              dd ?
    DebugEventCallback          dd ?
    SuppressBackgroundThread    dd ?
    SuppressExternalCodecs      dd ?
ends

struc PointF
    x   dd ? ;real4
    y   dd ? ;real4
ends

struc RectF
    _Left   dd ? ;real4
    _Top    dd ? ;real4
    _Right  dd ? ;real4
    Bottom  dd ? ;real4
ends

struc SizeF
    sx  dd ? ;real4
    sy  dd ? ;real4
ends

struc COLORBYTES
    BlueByte    db ?
    GreenByte   db ?
    RedByte     db ?
    AlphaByte   db ?
ends

struc COLORLONG
    longval dd ?
ends

struc ImageCodecInfo
    ClassID             GUID ?
    FormatID            GUID ?
    CodecName           dd ?
    DllName             dd ?
    FormatDescription   dd ?
    FilenameExtension   dd ?
    MimeType            dd ?
    flags               dd ?
    Version             dd ?
    SigCount            dd ?
    SigSize             dd ?
    SigPattern          dd ?
    SigMask             dd ?
ends

struc EncoderParameter
    pGUID           dd ?
    NumberOfValues  dd ?
    vType           dd ?
    value           dd ?
ends

struc EncoderParameters
    Count       dd ?
    Parameter   EncoderParameter ?
ends

struc ColorPalette
    flags   dd ?
    Count   dd ?
    Entries dd ?
ends

struc ColorMatrix
    m11 dd ? ;real4
    m12 dd ? ;real4
    m13 dd ? ;real4
    m14 dd ? ;real4
    m15 dd ? ;real4
    m21 dd ? ;real4
    m22 dd ? ;real4
    m23 dd ? ;real4
    m24 dd ? ;real4
    m25 dd ? ;real4
    m31 dd ? ;real4
    m32 dd ? ;real4
    m33 dd ? ;real4
    m34 dd ? ;real4
    m35 dd ? ;real4
    m41 dd ? ;real4
    m42 dd ? ;real4
    m43 dd ? ;real4
    m44 dd ? ;real4
    m45 dd ? ;real4
    m51 dd ? ;real4
    m52 dd ? ;real4
    m53 dd ? ;real4
    m54 dd ? ;real4
    m55 dd ? ;real4
ends

struc BitmapData
    nWidth      dd ?
    nHeight     dd ?
    Stride      dd ?
    PixelFormat dd ?
    Scan0       dd ?
    Reserved    dd ?
ends

struc PathData
    Count   dd ?
    pPoint  dd ?
    types   dd ?
ends

struc PropertyItem
    propId  dd ?
    _length dd ?
    nType   dw ?
    value   dd ?
ends

struc CharacterRange
    First   dd ?
    _length dd ?
ends

struc PWMFRect16
    nLEFT   dw ?
    nTop    dw ?
    nRIGHT  dw ?
    nBottom dw ?
ends

struc WmfPlaceableFileHeader
    Key         dd ?
    Hmf         dw ?
    boundingBox PWMFRect16 ?
    Inch        dw ?
    Reserved    dd ?
    Checksum    dw ?
ends

struc MetafileHeader
    mType               dd ?
    msize               dd ?
    Version             dd ?
    EmfPlusFlags        dd ?
    DpiX                dd ? ;real4
    DpiY                dd ? ;real4
    x                   dd ?
    y                   dd ?
    nWIDTH              dd ?
    Height              dd ?
    EmfHeader           ENHMETAHEADER3 ?
    EmfPlusHeaderSize   dd ?
    LogicalDpiX         dd ?
    LogicalDpiY         dd ?
ends

;======================================== kernel32 =======================================;
struc FLOAT128
    LowPart     dq ?
    HighPart    dq ?
ends

struc LIST_ENTRY
    Flink   xword ?
    Blink   xword ?
ends

struc COORD
    X dw ?
    Y dw ?
ends

struc CONSOLE_FONT_INFO
    nFont      dd    ?
    dwFontSize COORD ?
ends

struc OSVERSIONINFOEXA
    dwOSVersionInfoSize dd  ?
    dwMajorVersion      dd  ?
    dwMinorVersion      dd  ?
    dwBuildNumber       dd  ?
    dwPlatformId        dd  ?
    szCSDVersion        rb  128
    wServicePackMajor   dw  ?
    wServicePackMinor   dw  ?
    wSuiteMask          dw  ?
    wProductType        db  ?
    wReserved           db  ?
ends

struc OSVERSIONINFOEXW
    dwOSVersionInfoSize dd  ?
    dwMajorVersion      dd  ?
    dwMinorVersion      dd  ?
    dwBuildNumber       dd  ?
    dwPlatformId        dd  ?
    szCSDVersion        rw  128
    wServicePackMajor   dw  ?
    wServicePackMinor   dw  ?
    wSuiteMask          dw  ?
    wProductType        db  ?
    wReserved           db  ?
ends

struc SINGLE_LIST_ENTRY
    Next    xword ?
ends

struc SLIST_ENTRY
    Next    xword ?
ends

struc LIST_ENTRY32
    Flink   dd  ?
    Blink   dd  ?
ends

struc LIST_ENTRY64
    Flink   dq ?
    Blink   dq ?
ends

struc OBJECTID
    Lineage     GUID ?
    Uniquifier  dd ?
ends

struc M128A
    _Low    dq ?
    _High   dq ?
ends

struc XSAVE_FORMAT
    ControlWord      dw ?
    StatusWord       dw ?
    TagWord          db ?
    Reserved1        db ?
    ErrorOpcode      dw ?
    ErrorOffset      dd ?
    ErrorSelector    dw ?
    Reserved2        dw ?
    DataOffset       dd ?
    DataSelector     dw ?
    Reserved3        dw ?
    MxCsr            dd ?
    MxCsr_Mask       dd ?
    FloatRegisters   rs M128A,8
    #ifdef APP_WIN64
        XmmRegisters rs M128A,16
    #else
        XmmRegisters rs M128A,8
    #endif 
    Reserved4        rb 96
ends

struc XMM_SAVE_AREA32
    ControlWord     dw ?
    StatusWord      dw ?
    TagWord         db ?
    Reserved1       db ?
    ErrorOpcode     dw ?
    ErrorOffset     dd ?
    ErrorSelector   dw ?
    Reserved2       dw ?
    DataOffset      dd ?
    DataSelector    dw ?
    Reserved3       dw ?
    MxCsr           dd ?
    MxCsr_Mask      dd ?
    FloatRegisters  rs M128A,8
    XmmRegisters    rs M128A,16
    Reserved4       rb 96
ends

struc FLOATING_SAVE_AREA
    ControlWord     dd ?
    StatusWord      dd ?
    TagWord         dd ?
    ErrorOffset     dd ?
    ErrorSelector   dd ?
    DataOffset      dd ?
    DataSelector    dd ?
    RegisterArea    rb SIZE_OF_80387_REGISTERS
    Cr0NpxState     dd ?
ends

struc RUNTIME_FUNCTION
    BeginAddress        dd ?
    EndAddress          dd ?
    UnwindInfoAddress   dd ?
ends

#ifdef APP_WIN64
    CONTEXT_CONTROL                             equ     <CONTEXT_AMD64 or 01H>
    CONTEXT_INTEGER                             equ     <CONTEXT_AMD64 or 02H>
    CONTEXT_SEGMENTS                            equ     <CONTEXT_AMD64 or 04H>
    CONTEXT_FLOATING_POINT                      equ     <CONTEXT_AMD64 or 08H>
    CONTEXT_DEBUG_REGISTERS                     equ     <CONTEXT_AMD64 or 10H>

    CONTEXT_FULL                                equ     <CONTEXT_CONTROL or CONTEXT_INTEGER or CONTEXT_FLOATING_POINT>

    CONTEXT_ALL                                 equ     <CONTEXT_CONTROL or CONTEXT_INTEGER or CONTEXT_SEGMENTS or CONTEXT_FLOATING_POINT or CONTEXT_DEBUG_REGISTERS>

    CONTEXT_EXCEPTION_ACTIVE                    equ     08000000H
    CONTEXT_SERVICE_ACTIVE                      equ     10000000H
    CONTEXT_EXCEPTION_REQUEST                   equ     40000000H
    CONTEXT_EXCEPTION_REPORTING                 equ     80000000H

    struc CONTEXT
        P1Home       dq ?
        P2Home       dq ?
        P3Home       dq ?
        P4Home       dq ?
        P5Home       dq ?
        P6Home       dq ?
        ContextFlags dd ?
        MxCsr        dd ?
        regCs        dw ?
        regDs        dw ?
        regEs        dw ?
        regFs        dw ?
        regGs        dw ?
        regSs        dw ?
        regFlag      dd ?
        _Dr0         dq ?
        _Dr1         dq ?
        _Dr2         dq ?
        _Dr3         dq ?
        _Dr6         dq ?
        _Dr7         dq ?
        regRax       dq ?
        regRcx       dq ?
        regRdx       dq ?
        regRbx       dq ?
        regRsp       dq ?
        regRbp       dq ?
        regRsi       dq ?
        regRdi       dq ?
        regR8        dq ?
        regR9        dq ?
        regR10       dq ?
        regR11       dq ?
        regR12       dq ?
        regR13       dq ?
        regR14       dq ?
        regR15       dq ?
        regRip       dq ?
        union
            FltSave XMM_SAVE_AREA32 ?
        endu
        VectorRegister       rs M128A,26
        VectorControl        dq ?
        DebugControl         dq ?
        LastBranchToRip      dq ?
        LastBranchFromRip    dq ?
        LastExceptionToRip   dq ?
        LastExceptionFromRip dq ?
    ends

    struc UNWIND_HISTORY_TABLE
        Count       dd ?
        LocalHint   db ?
        GlobalHint  db ?
        Search      db ?
        Once        db ?
        LowAddress  dq ?
        HighAddress dq ?
        _Entry      rs RECT,12
    ends

    struc FRAME_POINTERS
        MemoryStackFp   dq ?
        BackingStoreFp  dq ?
    ends
#else
    CONTEXT_CONTROL                             equ     <CONTEXT_i386 or 00000001H>
    CONTEXT_INTEGER                             equ     <CONTEXT_i386 or 00000002H>
    CONTEXT_SEGMENTS                            equ     <CONTEXT_i386 or 00000004H>
    CONTEXT_FLOATING_POINT                      equ     <CONTEXT_i386 or 00000008H>
    CONTEXT_DEBUG_REGISTERS                     equ     <CONTEXT_i386 or 00000010H>
    CONTEXT_EXTENDED_REGISTERS                  equ     <CONTEXT_i386 or 00000020H>
    CONTEXT_FULL                                equ     <CONTEXT_CONTROL or CONTEXT_INTEGER or CONTEXT_SEGMENTS>
    CONTEXT_ALL                                 equ     <CONTEXT_CONTROL or CONTEXT_INTEGER or CONTEXT_SEGMENTS or CONTEXT_FLOATING_POINT or CONTEXT_DEBUG_REGISTERS or CONTEXT_EXTENDED_REGISTERS>

    struc CONTEXT
        ContextFlags        dd ?
        _Dr0                dd ?
        _Dr1                dd ?
        _Dr2                dd ?
        _Dr3                dd ?
        _Dr6                dd ?
        _Dr7                dd ?
        FloatSave           FLOATING_SAVE_AREA ?
        regGs               dd ?
        regFs               dd ?
        regEs               dd ?
        regDs               dd ?
        regEdi              dd ?
        regEsi              dd ?
        regEbx              dd ?
        regEdx              dd ?
        regEcx              dd ?
        regEax              dd ?
        regEbp              dd ?
        regEip              dd ?
        regCs               dd ?
        regFlag             dd ?
        regEsp              dd ?
        regSs               dd ?
        ExtendedRegisters   rb MAXIMUM_SUPPORTED_EXTENSION
    ends

    struc UNWIND_HISTORY_TABLE_ENTRY
        ImageBase     xword ?
        FunctionEntry xword ?
    ends

    struc UNWIND_HISTORY_TABLE
        Count       dd ?
        LocalHint   db ?
        GlobalHint  db ?
        Search      db ?
        Once        db ?
        LowAddress  dd ?
        HighAddress dd ?
        _Entry      rs UNWIND_HISTORY_TABLE_ENTRY,UNWIND_HISTORY_TABLE_SIZE
    ends
#endif

struc DISPATCHER_CONTEXT
    ControlPc        dq    ? 
    ImageBase        dq    ?
    FunctionEntry    xword ?
    EstablisherFrame dq    ?
    TargetIp         dq    ?
    ContextRecord    xword ?
    LanguageHandler  xword ?
    HandlerData      xword ?
    HistoryTable     xword ?
    ScopeIndex       dd    ?
    Fill0            dd    ?
ends

struc EXCEPTION_RECORD32
    ExceptionCode        dd ?
    ExceptionFlags       dd ?
    ExceptionRecord      dd ?
    ExceptionAddress     dd ?
    NumberParameters     dd ?
    ExceptionInformation rd EXCEPTION_MAXIMUM_PARAMETERS
ends

struc EXCEPTION_RECORD64
    ExceptionCode        dd ?
    ExceptionFlags       dd ?
    ExceptionRecord      dq ?
    ExceptionAddress     dq ?
    NumberParameters     dd ?
    __unusedAlignment    dd ?
    ExceptionInformation rq EXCEPTION_MAXIMUM_PARAMETERS
ends

struc EXCEPTION_POINTERS
    ExceptionRecord xword ?
    ContextRecord   xword ?
ends

struc GENERIC_MAPPING
    GenericRead     dd ?
    GenericWrite    dd ?
    GenericExecute  dd ?
    GenericAll      dd ?
ends

struc LUID_AND_ATTRIBUTES
    Luid            LUID ?
    Attributes      dd   ?
ends

struc SID_IDENTIFIER_AUTHORITY
    Value   rb 6
ends

struc SID
    Revision            db ?
    SubAuthorityCount   db ?
    IdentifierAuthority SID_IDENTIFIER_AUTHORITY ?
    SubAuthority        dd ?
ends

struc SID_AND_ATTRIBUTES
    Sid         xword ?
    Attributes  dd    ?
ends

struc SID_AND_ATTRIBUTES_HASH
    SidCount    dd    ?
    SidAttr     xword ?
    Hash        rq    SID_HASH_SIZE
ends

struc ACL
    AclRevision db ?
    Sbz1        db ?
    AclSize     dw ?
    AceCount    dw ?
    Sbz2        dw ?
ends

struc ACE_HEADER
    AceType     db ?
    AceFlags    db ?
    AceSize     dw ?
ends

struc ACCESS_ALLOWED_ACE
    Header      ACE_HEADER ?
    _Mask       dd ?
    SidStart    dd ?
ends

struc ACCESS_DENIED_ACE
    Header      ACE_HEADER ?
    _Mask       dd ?
    SidStart    dd ?
ends

struc SYSTEM_AUDIT_ACE
    Header   ACE_HEADER ?
    _Mask    dd ?
    SidStart dd ?
ends

struc SYSTEM_ALARM_ACE
    Header   ACE_HEADER ?
    _Mask    dd ?
    SidStart dd ?
ends

struc SYSTEM_RESOURCE_ATTRIBUTE_ACE
    Header      ACE_HEADER ?
    imask       dd ?
    SidStart    dd ?
ends

struc SYSTEM_SCOPED_POLICY_ID_ACE
    Header      ACE_HEADER ?
    imask       dd ?
    SidStart    dd ?
ends

struc SYSTEM_MANDATORY_LABEL_ACE
    Header      ACE_HEADER ?
    _Mask       dd ?
    SidStart    dd ?
ends

struc SYSTEM_PROCESS_TRUST_LABEL_ACE
    Header      ACE_HEADER ?
    _Mask       dd ?
    SidStart    dd ?
ends

struc ACCESS_ALLOWED_OBJECT_ACE
    Header              ACE_HEADER ?
    _Mask               dd ?
    Flags               dd ?
    ObjectType          GUID ?
    InheritedObjectType GUID ?
    SidStart            dd ?
ends

struc ACCESS_DENIED_OBJECT_ACE
    Header              ACE_HEADER ?
    _Mask               dd ?
    Flags               dd ?
    ObjectType          GUID ?
    InheritedObjectType GUID ?
    SidStart            dd ?
ends

struc SYSTEM_AUDIT_OBJECT_ACE
    Header              ACE_HEADER ?
    _Mask               dd ?
    Flags               dd ?
    ObjectType          GUID ?
    InheritedObjectType GUID ?
    SidStart            dd ?
ends

struc SYSTEM_ALARM_OBJECT_ACE
    Header              ACE_HEADER ?
    _Mask               dd ?
    Flags               dd ?
    ObjectType          GUID ?
    InheritedObjectType GUID ?
    SidStart            dd ?
ends

struc ACCESS_ALLOWED_CALLBACK_ACE
    Header      ACE_HEADER ?
    _Mask       dd ?
    SidStart    dd ?
ends

struc ACCESS_DENIED_CALLBACK_ACE
    Header      ACE_HEADER ?
    _Mask       dd ?
    SidStart    dd ?
ends

struc SYSTEM_AUDIT_CALLBACK_ACE
    Header      ACE_HEADER ?
    _Mask       dd ?
    SidStart    dd ?
ends

struc SYSTEM_ALARM_CALLBACK_ACE
    Header      ACE_HEADER ?
    _Mask       dd ?
    SidStart    dd ?
ends

struc ACCESS_ALLOWED_CALLBACK_OBJECT_ACE
    Header              ACE_HEADER ?
    _Mask               dd ?
    Flags               dd ?
    ObjectType          GUID ?
    InheritedObjectType GUID ?
    SidStart            dd ?
ends

struc ACCESS_DENIED_CALLBACK_OBJECT_ACE
    Header              ACE_HEADER ?
    _Mask               dd ?
    Flags               dd ?
    ObjectType          GUID ?
    InheritedObjectType GUID ?
    SidStart            dd ?
ends

struc SYSTEM_AUDIT_CALLBACK_OBJECT_ACE
    Header              ACE_HEADER ?
    _Mask               dd ?
    Flags               dd ?
    ObjectType          GUID ?
    InheritedObjectType GUID ?
    SidStart            dd ?
ends

struc SYSTEM_ALARM_CALLBACK_OBJECT_ACE
    Header              ACE_HEADER ?
    _Mask               dd ?
    Flags               dd ?
    ObjectType          GUID ?
    InheritedObjectType GUID ?
    SidStart            dd ?
ends

struc ACL_REVISION_INFORMATION
    AclRevision     dd  ?
ends

struc ACL_SIZE_INFORMATION
    AceCount        dd  ?
    AclBytesInUse   dd  ?
    AclBytesFree    dd  ?
ends

struc SECURITY_DESCRIPTOR_RELATIVE
    Revision    db  ?
    Sbz1        db  ?
    Control     dw  ?
    Owner       dd  ?
    _Group      dd  ?
    Sacl        dd  ?
    Dacl        dd  ?
ends

struc SECURITY_DESCRIPTOR
    Revision    db ?
    Sbz1        db ?
    Control     dw ?
    Owner       dd ?
    _Group      dd ?
    Sacl        dd ?
    Dacl        dd ?
ends

struc SECURITY_OBJECT_AI_PARAMS
    _Size           dd  ?
    ConstraintMask  dd  ?
ends

struc OBJECT_TYPE_LIST
    Level       dw  ?
    Sbz         dw  ?
    ObjectType  xword ?
ends

struc PRIVILEGE_SET
    PrivilegeCount  dd  ?
    Control         dd  ?
    Privilege       rs LUID_AND_ATTRIBUTES,ANYSIZE_ARRAY
ends

struc ACCESS_REASONS
    Data    rd 32
ends

struc SE_SECURITY_DESCRIPTOR
    _Size               dd   ?
    Flags               dd   ?
    SecurityDescriptor  xword ?
ends

struc SE_ACCESS_REQUEST
    _Size                   dd    ?
    SeSecurityDescriptor    xword ?
    DesiredAccess           dd    ?
    PreviouslyGrantedAccess dd    ?
    PrincipalSelfSid        xword ?
    GenericMapping          xword ?
    ObjectTypeListCount     dd    ?
    ObjectTypeList          xword ?
ends

struc SE_ACCESS_REPLY
    _Size           dd   ?
    ResultListCount dd   ?
    GrantedAccess   xword ?
    AccessStatus    xword ?
    AccessReason    xword ?
    Privileges      xword ?
ends

struc TOKEN_USER
    User    SID_AND_ATTRIBUTES ?
ends

struc TOKEN_GROUPS
    GroupCount  dd ?
    Groups      rs SID_AND_ATTRIBUTES,ANYSIZE_ARRAY
ends

struc TOKEN_PRIVILEGES
    PrivilegeCount  dd ?
    Privileges      rs LUID_AND_ATTRIBUTES,ANYSIZE_ARRAY
ends

struc TOKEN_OWNER
    Owner   xword ?
ends

struc TOKEN_PRIMARY_GROUP
    PrimaryGroup    xword ?
ends

struc TOKEN_USER_CLAIMS
    UserClaims  xword ?
ends

struc TOKEN_DEVICE_CLAIMS
    DeviceClaims    xword ?
ends

struc TOKEN_GROUPS_AND_PRIVILEGES
    SidCount            dd    ?
    SidLength           dd    ?
    Sids                xword ?
    RestrictedSidCount  dd    ?
    RestrictedSidLength dd    ?
    RestrictedSids      xword ?
    PrivilegeCount      dd    ?
    PrivilegeLength     dd    ?
    Privileges          xword ?
    AuthenticationId    LUID  ?
ends

struc TOKEN_LINKED_TOKEN
    LinkedToken     xword ?
ends

struc TOKEN_ELEVATION
    TokenIsElevated dd  ?
ends

struc TOKEN_MANDATORY_LABEL
    _Label  SID_AND_ATTRIBUTES ?
ends

struc TOKEN_MANDATORY_POLICY
    Policy  dd  ?
ends

struc TOKEN_ACCESS_INFORMATION
    SidHash             xword ?
    RestrictedSidHash   xword ?
    Privileges          xword ?
    AuthenticationId    LUID  ?
    _TokenType          dd    ?
    ImpersonationLevel  dd    ?
    MandatoryPolicy     TOKEN_MANDATORY_POLICY ?
    Flags               dd    ?
    AppContainerNumber  dd    ?
    PackageSid          xword ?
    CapabilitiesHash    xword ?
    TrustLevelSid       xword ?
ends

struc TOKEN_DEFAULT_DACL
    DefaultDacl xword ?
ends

struc TOKEN_AUDIT_POLICY
    PerUserPolicy   rb  <(POLICY_AUDIT_SUBCATEGORY_COUNT shr 1) + 1>
ends

struc TOKEN_SOURCE
    SourceName       rb TOKEN_SOURCE_LENGTH
    SourceIdentifier LUID ?
ends

struc TOKEN_STATISTICS
    TokenId             LUID ?
    AuthenticationId    LUID ?
    ExpirationTime      LARGE_INTEGER ?
    _TokenType          dd ?
    ImpersonationLevel  dd ?
    DynamicCharged      dd ?
    DynamicAvailable    dd ?
    GroupCount          dd ?
    PrivilegeCount      dd ?
    ModifiedId          LUID ?
ends

struc TOKEN_CONTROL
    TokenId          LUID ?
    AuthenticationId LUID ?
    ModifiedId       LUID ?
    _TokenSource     TOKEN_SOURCE ?
ends

struc TOKEN_ORIGIN
    OriginatingLogonSession LUID ?
ends

struc TOKEN_APPCONTAINER_INFORMATION
    TokenAppContainer   xword ?
ends

struc TOKEN_SID_INFORMATION
    Sid     xword ?
ends

struc SECURITY_QUALITY_OF_SERVICE
    _Length             dd ?
    ImpersonationLevel  dd ?
    ContextTrackingMode db ?
    EffectiveOnly       db ?
ends

struc SE_IMPERSONATION_STATE
    Token           xword ?
    CopyOnOpen      db    ?
    EffectiveOnly   db    ?
    Level           dd    ?
ends

struc NT_TIB
    ExceptionList   xword ?
    StackBase       xword ?
    StackLimit      xword ?
    SubSystemTib    xword ?
    union
        FiberData   xword ?
        Version     dd    ?
    endu
    ArbitraryUserPointer xword ?
    Self            xword ?
ends

struc NT_TIB32
    ExceptionList   dd  ?
    StackBase       dd  ?
    StackLimit      dd  ?
    SubSystemTib    dd  ?
    union
        FiberData   dd  ?
        Version     dd  ?
    endu
    ArbitraryUserPointer dd ?
    Self            dd  ?
ends

struc NT_TIB64
    ExceptionList   dq  ?
    StackBase       dq  ?
    StackLimit      dq  ?
    SubSystemTib    dq  ?
    union
        FiberData   dq  ?
        Version     dd  ?
    endu
    ArbitraryUserPointer dq ?
    Self            dq  ?
ends

struc QUOTA_LIMITS
    PagedPoolLimit          xword ?
    NonPagedPoolLimit       xword ?
    MinimumWorkingSetSize   xword ?
    MaximumWorkingSetSize   xword ?
    PagefileLimit           xword ?
    TimeLimit               LARGE_INTEGER ?
ends

struc RATE_QUOTA_LIMIT
    union
        RateData    dd ?
        RatePercent dd ?
    endu
ends

struc QUOTA_LIMITS_EX
    PagedPoolLimit          xword ?
    NonPagedPoolLimit       xword ?
    MinimumWorkingSetSize   xword ?
    MaximumWorkingSetSize   xword ?
    PagefileLimit           xword ?
    TimeLimit               LARGE_INTEGER ?
    WorkingSetLimit         xword ?
    Reserved2               xword ?
    Reserved3               xword ?
    Reserved4               xword ?
    Flags                   dd    ?
    CpuRateLimit            RATE_QUOTA_LIMIT ?
ends

struc IO_COUNTERS
    ReadOperationCount  dq ?
    WriteOperationCount dq ?
    OtherOperationCount dq ?
    ReadTransferCount   dq ?
    WriteTransferCount  dq ?
    OtherTransferCount  dq ?
ends

struc JOBOBJECT_BASIC_ACCOUNTING_INFORMATION
    TotalUserTime               LARGE_INTEGER ?
    TotalKernelTime             LARGE_INTEGER ?
    ThisPeriodTotalUserTime     LARGE_INTEGER ?
    ThisPeriodTotalKernelTime   LARGE_INTEGER ?
    TotalPageFaultCount         dd ?
    TotalProcesses              dd ?
    ActiveProcesses             dd ?
    TotalTerminatedProcesses    dd ?
ends

struc JOBOBJECT_BASIC_LIMIT_INFORMATION
    PerProcessUserTimeLimit LARGE_INTEGER ?
    PerJobUserTimeLimit     LARGE_INTEGER ?
    LimitFlags              dd    ?
    MinimumWorkingSetSize   xword ?
    MaximumWorkingSetSize   xword ?
    ActiveProcessLimit      dd    ?
    Affinity                xword ?
    PriorityClass           dd    ?
    SchedulingClass         dd    ?
ends

struc JOBOBJECT_EXTENDED_LIMIT_INFORMATION
    BasicLimitInformation   JOBOBJECT_BASIC_LIMIT_INFORMATION ?
    IoInfo                  IO_COUNTERS ?
    ProcessMemoryLimit      xword ?
    JobMemoryLimit          xword ?
    PeakProcessMemoryUsed   xword ?
    PeakJobMemoryUsed       xword ?
ends

struc JOBOBJECT_BASIC_PROCESS_ID_LIST
    NumberOfAssignedProcesses   dd    ?
    NumberOfProcessIdsInList    dd    ?
    ProcessIdList               xword ?
ends

struc JOBOBJECT_BASIC_UI_RESTRICTIONS
    UIRestrictionsClass dd  ?
ends

struc JOBOBJECT_SECURITY_LIMIT_INFORMATION
    SecurityLimitFlags  dd    ?
    JobToken            xword ?
    SidsToDisable       xword ?
    PrivilegesToDelete  xword ?
    RestrictedSids      xword ?
ends

struc JOBOBJECT_END_OF_JOB_TIME_INFORMATION
    EndOfJobTimeAction  dd  ?
ends

struc JOBOBJECT_ASSOCIATE_COMPLETION_PORT
    CompletionKey   xword ?
    CompletionPort  xword ?
ends

struc JOBOBJECT_BASIC_AND_IO_ACCOUNTING_INFORMATION
    BasicInfo   JOBOBJECT_BASIC_ACCOUNTING_INFORMATION ?
    IoInfo      IO_COUNTERS ?
ends

struc CACHE_DESCRIPTOR
    Level           db  ?
    Associativity   db  ?
    LineSize        dw  ?
    _Size           dd  ?
    _Type           dd  ?
ends

struc SYSTEM_LOGICAL_PROCESSOR_INFORMATION
    ProcessorMask   xword ?
    Relationship    dd    ?
    union
        Flags       db    ?
        NodeNumber  dd    ?
        Cache       CACHE_DESCRIPTOR ?
        Reserved    rq    2
    endu
ends

struc MEMORY_BASIC_INFORMATION
    BaseAddress         xword ?
    AllocationBase      xword ?
    AllocationProtect   dd    ?
    RegionSize          xword ?
    State               dd    ?
    Protect             dd    ?
    _Type               dd    ?
ends

struc MEMORY_BASIC_INFORMATION32
    BaseAddress         dd  ?
    AllocationBase      dd  ?
    AllocationProtect   dd  ?
    RegionSize          dd  ?
    State               dd  ?
    Protect             dd  ?
    _Type               dd  ?
ends

struc MEMORY_BASIC_INFORMATION64
    BaseAddress         dq ?
    AllocationBase      dq ?
    AllocationProtect   dd ?
    __alignment1        dd ?
    RegionSize          dq ?
    State               dd ?
    Protect             dd ?
    _Type               dd ?
    __alignment2        dd ?
ends

struc FILE_NOTIFY_INFORMATION
    NextEntryOffset dd  ?
    Action          dd  ?
    FileNameLength  dd  ?
    FileName        rw  1
ends

struc FILE_SEGMENT_ELEMENT
    union
        Buffer      xword ?
        Alignment   dq    ?
    endu
ends

struc GREPBUF
    DataBuffer  xword ?
ends

struc REPARSE_GUID_DATA_BUFFER
    ReparseTag           dd ?
    ReparseDataLength    dw ?
    Reserved             dw ?
    ReparseGuid          GUID ?
    GenericReparseBuffer GREPBUF ?
ends

struc CM_POWER_DATA
    PD_Size                 dd    ?
    PD_MostRecentPowerState dd    ?
    PD_Capabilities         dd    ?
    PD_D1Latency            dd    ?
    PD_D2Latency            dd    ?
    PD_D3Latency            dd    ?
    PD_PowerStateMapping    rd POWER_SYSTEM_MAXIMUM
    PD_DeepestSystemWake    dd    ?
ends

struc PO_TRANSITION_VETO_REASON
    ResourceId       dd ?
    ModuleNameOffset dd ?
ends

struc PO_TRANSITION_VETO_WINDOW
    Handle  xword ?
ends

struc PO_TRANSITION_VETO_SERVICE
    ServiceNameOffset   dd  ?
ends

struc PO_TRANSITION_VETO_DRIVER
    InstancePathOffset  dd  ?
    DriverNameOffset    dd  ?
ends

struc PO_TRANSITION_VETO
    _Type       dd ?
    Reason      PO_TRANSITION_VETO_REASON ?
    ProcessId   dd ?
    union
        Window  PO_TRANSITION_VETO_WINDOW ?
        Service PO_TRANSITION_VETO_SERVICE ?
        Driver  PO_TRANSITION_VETO_DRIVER ?
    endu
ends

struc PO_TRANSITION_VETOES
    Count   dd ?
    Vetoes  rs PO_TRANSITION_VETO,ANYSIZE_ARRAY
ends

struc SET_POWER_SETTING_VALUE
    Version         dd ?
    Guid            GUID ?
    PowerCondition  dd ?
    DataLength      dd ?
    Data            rb ANYSIZE_ARRAY
ends

struc NOTIFY_USER_POWER_SETTING
    Guid    GUID ?
ends

struc APPLICATIONLAUNCH_SETTING_VALUE
    ActivationTime   LARGE_INTEGER ?
    Flags            dd ?
    ButtonInstanceID dd ?
ends

struc PO_WAKE_SOURCE_HEADER
    _Type   xword ?
    _Size   dd    ?
ends

struc PO_WAKE_SOURCE_DEVICE
    Header       PO_WAKE_SOURCE_HEADER ?
    InstancePath dw ?
ends

struc PO_WAKE_SOURCE_FIXED
    Header              PO_WAKE_SOURCE_HEADER ?
    FixedWakeSourceType xword ?
ends

struc PO_WAKE_SOURCE_INFO
    Count   dd ?
    Offsets dd ?
ends

struc PO_WAKE_SOURCE_HISTORY
    Count   dd ?
    Offsets dd ?
ends

struc BATTERY_REPORTING_SCALE
    Granularity dd ?
    Capacity    dd ?
ends

struc PPM_SIMULATED_PROCESSOR_LOAD
    Enabled     db ?
    PercentBusy rb MAXIMUM_PROCESSORS
ends

struc PPM_WMI_LEGACY_PERFSTATE
    Frequency        dd ?
    Flags            dd ?
    PercentFrequency dd ?
ends

struc PPM_WMI_IDLE_STATE
    Latency         dd ?
    Power           dd ?
    TimeCheck       dd ?
    PromotePercent  dd ?
    DemotePercent   dd ?
    StateType       dd ?
    Reserved        dd ?
    StateFlags      dd ?
    Context         dd ?
    IdleHandler     dd ?
    Reserved1       dd ?
ends

struc PPM_WMI_IDLE_STATES
    _Type            dd ?
    Count            dd ?
    TargetState      dd ?
    OldState         dd ?
    TargetProcessors dq ?
    State            rs PPM_WMI_IDLE_STATE,ANYSIZE_ARRAY
ends

struc PPM_WMI_PERF_STATE
    Frequency        dd ?
    Power            dd ?
    PercentFrequency db ?
    IncreaseLevel    db ?
    DecreaseLevel    db ?
    _Type            db ?
    IncreaseTime     dd ?
    DecreaseTime     dd ?
    Control          dq ?
    Status           dq ?
    HitCount         dd ?
    Reserved1        dd ?
    Reserved2        dq ?
    Reserved3        dq ?
ends

struc PPM_WMI_PERF_STATES
    Count               dd ?
    MaxFrequency        dd ?
    CurrentState        dd ?
    MaxPerfState        dd ?
    MinPerfState        dd ?
    LowestPerfState     dd ?
    ThermalConstraint   dd ?
    BusyAdjThreshold    dd ?
    PolicyType          dd ?
    _Type               dd ?
    Reserved            dd ?
    TimerInterval       dd ?
    TargetProcessors    dq ?
    PStateHandler       dd ?
    PStateContext       dd ?
    TStateHandler       dd ?
    TStateContext       dd ?
    FeedbackHandler     dd ?
    Reserved1           dd ?
    Reserved2           dq ?
    State               rs PPM_WMI_PERF_STATE,ANYSIZE_ARRAY
ends

struc PPM_IDLE_STATE_ACCOUNTING
    IdleTransitions     dd ?
    FailedTransitions   dd ?
    InvalidBucketIndex  dd ?
    TotalTime           dq ?
    IdleTimeBuckets     rd PROC_IDLE_BUCKET_COUNT
ends

struc PPM_IDLE_ACCOUNTING
    StateCount          dd ?
    TotalTransitions    dd ?
    ResetCount          dd ?
    StartTime           dq ?
    State               rs PPM_IDLE_STATE_ACCOUNTING,ANYSIZE_ARRAY
ends

struc PPM_PERFSTATE_EVENT
    State       dd ?
    Status      dd ?
    Latency     dd ?
    Speed       dd ?
    Processor   dd ?
ends

struc PPM_PERFSTATE_DOMAIN_EVENT
    State       dd ?
    Latency     dd ?
    Speed       dd ?
    Processors  dq ?
ends

struc PPM_IDLESTATE_EVENT
    NewState    dd ?
    OldState    dd ?
    Processors  dq ?
ends

struc PPM_THERMALCHANGE_EVENT
    ThermalConstraint   dd ?
    Processors          dq ?
ends

struc PPM_THERMAL_POLICY_EVENT
    Mode        db ?
    Processors  dq ?
ends

struc POWER_ACTION_POLICY
    Action      xword ?
    Flags       dd    ?
    EventCode   dd    ?
ends

struc SYSTEM_POWER_LEVEL
    Enable          db    ?
    Spare           rb    3
    BatteryLevel    dd    ?
    PowerPolicy     POWER_ACTION_POLICY ?
    MinSystemState  xword ?
ends

struc SYSTEM_POWER_POLICY
    Revision             dd    ?
    PowerButton          POWER_ACTION_POLICY ?
    SleepButton          POWER_ACTION_POLICY ?
    LidClose             POWER_ACTION_POLICY ?
    LidOpenWake          xword ?
    Reserved             dd    ?
    Idle                 POWER_ACTION_POLICY ?
    IdleTimeout          dd    ?
    IdleSensitivity      db    ?
    DynamicThrottle      db    ?
    Spare2               rb    2
    MinSleep             xword ?
    MaxSleep             xword ?
    ReducedLatencySleep  xword ?
    WinLogonFlags        dd    ?
    Spare3               dd    ?
    DozeS4Timeout        dd    ?
    BroadcastCapacityResolution dd ?
    DischargePolicy      rs SYSTEM_POWER_LEVEL,NUM_DISCHARGE_POLICIES
    VideoTimeout         dd    ?
    VideoDimDisplay      db    ?
    VideoReserved        rd    3
    SpindownTimeout      dd    ?
    OptimizeForPower     db    ?
    FanThrottleTolerance db    ?
    ForcedThrottle       db    ?
    MinThrottle          db    ?
    OverThrottled        POWER_ACTION_POLICY ?
ends

struc PROCESSOR_IDLESTATE_INFO
    TimeCheck       dd ?
    DemotePercent   db ?
    PromotePercent  db ?
    Spare           rb 2
ends

struc PROCESSOR_POWER_POLICY_INFO
    TimeCheck       dd ?
    DemoteLimit     dd ?
    PromoteLimit    dd ?
    DemotePercent   db ?
    PromotePercent  db ?
    Spare           rb 2
    Reserved        dd ?
    AllowPromotion  dd ?
    AllowDemotion   dd ?
ends

struc PROCESSOR_POWER_POLICY
    Revision        dd ?
    DynamicThrottle db ?
    Spare           rb 3
    DisableCStates  dd ?
    Reserved        dd ?
    PolicyCount     dd ?
    Policy          rs PROCESSOR_POWER_POLICY_INFO,3
ends

struc ADMINISTRATOR_POWER_POLICY
    MinSleep            xword ?
    MaxSleep            xword ?
    MinVideoTimeout     dd    ?
    MaxVideoTimeout     dd    ?
    MinSpindownTimeout  dd    ?
    MaxSpindownTimeout  dd    ?
ends

struc SYSTEM_POWER_CAPABILITIES
    PowerButtonPresent      db    ?
    SleepButtonPresent      db    ?
    LidPresent              db    ?
    SystemS1                db    ?
    SystemS2                db    ?
    SystemS3                db    ?
    SystemS4                db    ?
    SystemS5                db    ?
    HiberFilePresent        db    ?
    FullWake                db    ?
    VideoDimPresent         db    ?
    ApmPresent              db    ?
    UpsPresent              db    ?
    ThermalControl          db    ?
    ProcessorThrottle       db    ?
    ProcessorMinThrottle    db    ?
    ProcessorMaxThrottle    db    ?
    HiberBoot               db    ?
    WakeAlarmPresent        db    ?
    AoAc                    db    ?
    DiskSpinDown            db    ?
    spare3                  rb    8
    SystemBatteriesPresent  db    ?
    BatteriesAreShortTerm   db    ?
    BatteryScale            rs    BATTERY_REPORTING_SCALE,3
    AcOnLineWake            xword ?
    SoftLidWake             xword ?
    RtcWake                 xword ?
    MinDeviceWakeState      xword ?
    DefaultLowLatencyWake   xword ?
ends

struc SYSTEM_BATTERY_STATE
    AcOnLine          db ?  
    BatteryPresent    db ?
    Charging          db ?
    Discharging       db ?
    Spare1            rb 4
    MaxCapacity       dd ?
    RemainingCapacity dd ?
    Rate              dd ?
    EstimatedTime     dd ?
    DefaultAlert1     dd ?
    DefaultAlert2     dd ?
ends

struc IMAGE_DOS_HEADER
    e_magic     dw ?
    e_cblp      dw ?
    e_cp        dw ?
    e_crlc      dw ?
    e_cparhdr   dw ?
    e_minalloc  dw ?
    e_maxalloc  dw ?
    e_ss        dw ?
    e_sp        dw ?
    e_csum      dw ?
    e_ip        dw ?
    e_cs        dw ?
    e_lfarlc    dw ?
    e_ovno      dw ?
    e_res       rw 4
    e_oemid     dw ?
    e_oeminfo   dw ?
    e_res2      rw 10
    e_lfanew    dd ?
ends

struc IMAGE_OS2_HEADER
    ne_magic        dw ?
    ne_ver          db ?
    ne_rev          db ?
    ne_enttab       dw ?
    ne_cbenttab     dw ?
    ne_crc          dd ?
    ne_flags        dw ?
    ne_autodata     dw ?
    ne_heap         dw ?
    ne_stack        dw ?
    ne_csip         dd ?
    ne_sssp         dd ?
    ne_cseg         dw ?
    ne_cmod         dw ?
    ne_cbnrestab    dw ?
    ne_segtab       dw ?
    ne_rsrctab      dw ?
    ne_restab       dw ?
    ne_modtab       dw ?
    ne_imptab       dw ?
    ne_nrestab      dd ?
    ne_cmovent      dw ?
    ne_align        dw ?
    ne_cres         dw ?
    ne_exetyp       db ?
    ne_flagsothers  db ?
    ne_pretthunks   dw ?
    ne_psegrefbytes dw ?
    ne_swaparea     dw ?
    ne_expver       dw ?
ends

struc IMAGE_VXD_HEADER
    e32_magic           dw ?
    e32_border          db ?
    e32_worder          db ?
    e32_level           dd ?
    e32_cpu             dw ?
    e32_os              dw ?
    e32_ver             dd ?
    e32_mflags          dd ?
    e32_mpages          dd ?
    e32_startobj        dd ?
    e32_eip             dd ?
    e32_stackobj        dd ?
    e32_esp             dd ?
    e32_pagesize        dd ?
    e32_lastpagesize    dd ?
    e32_fixupsize       dd ?
    e32_fixupsum        dd ?
    e32_ldrsize         dd ?
    e32_ldrsum          dd ?
    e32_objtab          dd ?
    e32_objcnt          dd ?
    e32_objmap          dd ?
    e32_itermap         dd ?
    e32_rsrctab         dd ?
    e32_rsrccnt         dd ?
    e32_restab          dd ?
    e32_enttab          dd ?
    e32_dirtab          dd ?
    e32_dircnt          dd ?
    e32_fpagetab        dd ?
    e32_frectab         dd ?
    e32_impmod          dd ?
    e32_impmodcnt       dd ?
    e32_impproc         dd ?
    e32_pagesum         dd ?
    e32_datapage        dd ?
    e32_preload         dd ?
    e32_nrestab         dd ?
    e32_cbnrestab       dd ?
    e32_nressum         dd ?
    e32_autodata        dd ?
    e32_debuginfo       dd ?
    e32_debuglen        dd ?
    e32_instpreload     dd ?
    e32_instdemand      dd ?
    e32_heapsize        dd ?
    e32_res3            rb 12
    e32_winresoff       dd ?
    e32_winreslen       dd ?
    e32_devid           dw ?
    e32_ddkver          dw ?
ends

struc IMAGE_FILE_HEADER
    Machine              dw ?
    NumberOfSections     dw ?
    TimeDateStamp        dd ?
    PointerToSymbolTable dd ?
    NumberOfSymbols      dd ?
    SizeOfOptionalHeader dw ?
    Characteristics      dw ?
ends

struc IMAGE_DATA_DIRECTORY
    VirtualAddress  dd  ?
    _Size           dd  ?
ends

IMAGE_NUMBEROF_DIRECTORY_ENTRIES                equ     16

struc IMAGE_OPTIONAL_HEADER32
    Magic                       dw  ?
    MajorLinkerVersion          db  ?
    MinorLinkerVersion          db  ?
    SizeOfCode                  dd  ?
    SizeOfInitializedData       dd  ?
    SizeOfUninitializedData     dd  ?
    AddressOfEntryPoint         dd  ?
    BaseOfCode                  dd  ?
    BaseOfData                  dd  ?
    ImageBase                   dd  ?
    SectionAlignment            dd  ?
    FileAlignment               dd  ?
    MajorOperatingSystemVersion dw  ?
    MinorOperatingSystemVersion dw  ?
    MajorImageVersion           dw  ?
    MinorImageVersion           dw  ?
    MajorSubsystemVersion       dw  ?
    MinorSubsystemVersion       dw  ?
    Win32VersionValue           dd  ?
    SizeOfImage                 dd  ?
    SizeOfHeaders               dd  ?
    CheckSum                    dd  ?
    Subsystem                   dw  ?
    DllCharacteristics          dw  ?
    SizeOfStackReserve          dd  ?
    SizeOfStackCommit           dd  ?
    SizeOfHeapReserve           dd  ?
    SizeOfHeapCommit            dd  ?
    LoaderFlags                 dd  ?
    NumberOfRvaAndSizes         dd  ?
    DataDirectory               rs IMAGE_DATA_DIRECTORY,IMAGE_NUMBEROF_DIRECTORY_ENTRIES
ends

struc IMAGE_OPTIONAL_HEADER64
    Magic                       dw ?
    MajorLinkerVersion          db ?
    MinorLinkerVersion          db ?
    SizeOfCode                  dd ?
    SizeOfInitializedData       dd ?
    SizeOfUninitializedData     dd ?
    AddressOfEntryPoint         dd ?
    BaseOfCode                  dd ?
    ImageBase                   dq ?
    SectionAlignment            dd ?
    FileAlignment               dd ?
    MajorOperatingSystemVersion dw ?
    MinorOperatingSystemVersion dw ?
    MajorImageVersion           dw ?
    MinorImageVersion           dw ?
    MajorSubsystemVersion       dw ?
    MinorSubsystemVersion       dw ?
    Win32VersionValue           dd ?
    SizeOfImage                 dd ?
    SizeOfHeaders               dd ?
    CheckSum                    dd ?
    Subsystem                   dw ?
    DllCharacteristics          dw ?
    SizeOfStackReserve          dq ?
    SizeOfStackCommit           dq ?
    SizeOfHeapReserve           dq ?
    SizeOfHeapCommit            dq ?
    LoaderFlags                 dd ?
    NumberOfRvaAndSizes         dd ?
    DataDirectory               rs IMAGE_DATA_DIRECTORY,IMAGE_NUMBEROF_DIRECTORY_ENTRIES
ends

struc IMAGE_ROM_OPTIONAL_HEADER
    Magic                   dw  ?
    MajorLinkerVersion      db  ?
    MinorLinkerVersion      db  ?
    SizeOfCode              dd  ?
    SizeOfInitializedData   dd  ?
    SizeOfUninitializedData dd  ?
    AddressOfEntryPoint     dd  ?
    BaseOfCode              dd  ?
    BaseOfData              dd  ?
    BaseOfBss               dd  ?
    GprMask                 dd  ?
    CprMask                 rd  4
    GpValue                 dd  ?
ends

struc IMAGE_NT_HEADERS32
    Signature       dd ?
    FileHeader      IMAGE_FILE_HEADER ?
    OptionalHeader  IMAGE_OPTIONAL_HEADER32 ?
ends

struc IMAGE_NT_HEADERS64
    Signature       dd ?
    FileHeader      IMAGE_FILE_HEADER ?
    OptionalHeader  IMAGE_OPTIONAL_HEADER64 ?
ends

struc IMAGE_NT_HEADERS
    Signature       dd ?
    FileHeader      IMAGE_FILE_HEADER ?
    OptionalHeader  IMAGE_OPTIONAL_HEADER32 ?
ends

struc IMAGE_ROM_HEADERS
    FileHeader      IMAGE_FILE_HEADER ?
    OptionalHeader  IMAGE_ROM_OPTIONAL_HEADER ?
ends

struc ANON_OBJECT_HEADER
    Sig1            dw ?
    Sig2            dw ?
    Version         dw ?
    Machine         dw ?
    TimeDateStamp   dd ?
    ClassID         GUID ?
    SizeOfData      dd ?
ends

struc ANON_OBJECT_HEADER_V2
    Sig1            dw ?
    Sig2            dw ?
    Version         dw ?
    Machine         dw ?
    TimeDateStamp   dd ?
    ClassID         GUID ?
    SizeOfData      dd ?
    Flags           dd ?
    MetaDataSize    dd ?
    MetaDataOffset  dd ?
ends

struc IMAGE_SECTION_HEADER
    _Name                rb IMAGE_SIZEOF_SHORT_NAME
    union
        PhysicalAddress  dd ?
        VirtualSize      dd ?
    endu
    VirtualAddress       dd ?
    SizeOfRawData        dd ?
    PointerToRawData     dd ?
    PointerToRelocations dd ?
    PointerToLinenumbers dd ?
    NumberOfRelocations  dw ?
    NumberOfLinenumbers  dw ?
    Characteristics      dd ?
ends

struc IMAGE_AUX_SYMBOL_TOKEN_DEF
    bAuxType            db  ?
    bReserved           db  ?
    SymbolTableIndex    dd  ?
    rgbReserved         rb  12
ends

struc IMAGE_RELOCATION
    union
        VirtualAddress  dd ?
        RelocCount      dd ?
    endu
    SymbolTableIndex    dd ?
    _Type               dw ?
ends

struc IMAGE_LINENUMBER
    union
        SymbolTableIndex    dd  ?
        VirtualAddress      dd  ?
    endu
    Linenumber              dw  ?
ends

struc IMAGE_BASE_RELOCATION
    VirtualAddress  dd ?
    SizeOfBlock     dd ?
    TypeOffset      rw 1
ends

struc IMAGE_ARCHIVE_MEMBER_HEADER
    _Name       rb 16
    _Date       rb 12
    UserID      rb 6
    GroupID     rb 6
    Mode        rb 8
    _Size       rb 10
    EndHeader   rb 2
ends

struc IMAGE_EXPORT_DIRECTORY
    Characteristics         dd ?
    TimeDateStamp           dd ?
    MajorVersion            dw ?
    MinorVersion            dw ?
    _Name                   dd ?
    _Base                   dd ?
    NumberOfFunctions       dd ?
    NumberOfNames           dd ?
    AddressOfFunctions      dd ?
    AddressOfNames          dd ?
    AddressOfNameOrdinals   dd ?
ends

struc IMAGE_IMPORT_BY_NAME
    Hint    dw  ?
    _Name   db  ?
ends

struc IMAGE_THUNK_DATA64
    union
        ForwarderString xword ?
        Function        xword ?
        Ordinal         dd    ?
        AddressOfData   xword ?
    endu
ends

struc IMAGE_THUNK_DATA32
    union
        ForwarderString xword ?
        Function        xword ?
        Ordinal         dq    ?
        AddressOfData   xword ?
    endu
ends

struc IMAGE_TLS_DIRECTORY32
    StartAddressOfRawData   dd ?
    EndAddressOfRawData     dd ?
    AddressOfIndex          dd ?
    AddressOfCallBacks      dd ?
    SizeOfZeroFill          dd ?
    Characteristics         dd ?
ends

struc IMAGE_TLS_DIRECTORY64
    StartAddressOfRawData   dq ?
    EndAddressOfRawData     dq ?
    AddressOfIndex          dq ?
    AddressOfCallBacks      dq ?
    SizeOfZeroFill          dd ?
    Characteristics         dd ?
ends

struc IMAGE_IMPORT_DESCRIPTOR
    union
        Characteristics     dd   ?
        OriginalFirstThunk  xword ?
    endu
    TimeDateStamp           dd   ?
    ForwarderChain          dd   ?
    _Name                   dd   ?
    FirstThunk              xword ?
ends

struc IMAGE_BOUND_IMPORT_DESCRIPTOR
    TimeDateStamp               dd  ?
    OffsetModuleName            dw  ?
    NumberOfModuleForwarderRefs dw  ?
ends

struc IMAGE_BOUND_FORWARDER_REF
    TimeDateStamp       dd  ?
    OffsetModuleName    dw  ?
    Reserved            dw  ?
ends

struc IMAGE_RESOURCE_DIRECTORY
    Characteristics      dd ?
    TimeDateStamp        dd ?
    MajorVersion         dw ?
    MinorVersion         dw ?
    NumberOfNamedEntries dw ?
    NumberOfIdEntries    dw ?
ends

struc IMAGE_RESOURCE_DIRECTORY_STRING
    _Length     dw ?
    NameString  db ?
ends

struc IMAGE_RESOURCE_DIR_STRING_U
    _Length     dw ?
    NameString  dw ?
ends

struc IMAGE_RESOURCE_DATA_ENTRY
    OffsetToData    dd  ?
    _size           dd  ?
    CodePage        dd  ?
    Reserved        dd  ?
ends

struc IMAGE_LOAD_CONFIG_DIRECTORY32
    _Size                           dd    ?
    TimeDateStamp                   dd    ?
    MajorVersion                    dw    ?
    MinorVersion                    dw    ?
    GlobalFlagsClear                dd    ?
    GlobalFlagsSet                  dd    ?
    CriticalSectionDefaultTimeout   dd    ?
    DeCommitFreeBlockThreshold      dd    ?
    DeCommitTotalFreeThreshold      dd    ?
    LockPrefixTable                 dd    ?
    MaximumAllocationSize           dd    ?
    VirtualMemoryThreshold          dd    ?
    ProcessHeapFlags                dd    ?
    ProcessAffinityMask             dd    ?
    CSDVersion                      dw    ?
    Reserved1                       dw    ?
    EditList                        dd    ?
    SecurityCookie                  dd    ?
    SEHandlerTable                  dd    ?
    SEHandlerCount                  dd    ?
ends

struc IMAGE_LOAD_CONFIG_DIRECTORY64
    _Size                           dd ?
    TimeDateStamp                   dd ?
    MajorVersion                    dw ?
    MinorVersion                    dw ?
    GlobalFlagsClear                dd ?
    GlobalFlagsSet                  dd ?
    CriticalSectionDefaultTimeout   dd ?
    DeCommitFreeBlockThreshold      dq ?
    DeCommitTotalFreeThreshold      dq ?
    LockPrefixTable                 dq ?
    MaximumAllocationSize           dq ?
    VirtualMemoryThreshold          dq ?
    ProcessAffinityMask             dq ?
    ProcessHeapFlags                dd ?
    CSDVersion                      dw ?
    Reserved1                       dw ?
    EditList                        dq ?
    SecurityCookie                  dq ?
    SEHandlerTable                  dq ?
    SEHandlerCount                  dq ?
ends

struc IMAGE_RUNTIME_FUNCTION_ENTRY
    BeginAddress        xword ?
    EndAddress          xword ?
    UnwindInfoAddress   xword ?
ends

define IMAGE_IA64_RUNTIME_FUNCTION_ENTRY        IMAGE_RUNTIME_FUNCTION_ENTRY

struc UNWIND_CODE
    union
        CodeOffset db ?
        UnwindOp   db ?
        OpInfo     db ?
    endu
    FrameOffset    dw ?
ends

struc UNWIND_INFO
    Version         db ?
    Flags           db ?
    SizeOfProlog    db ?
    CountOfCodes    db ?
    FrameRegister   db ?
    FrameOffset     db ?
    UnwindCode      UNWIND_CODE ?
ends

struc IMAGE_CE_RUNTIME_FUNCTION_ENTRY
    FuncStart     dd ?
    PrologLen     dd ?
    FuncLen       dd ?
    ThirtyTwoBit  dd ?
    ExceptionFlag dd ?
ends

struc IMAGE_DEBUG_DIRECTORY
    Characteristics     dd  ?
    TimeDateStamp       dd  ?
    MajorVersion        dw  ?
    MinorVersion        dw  ?
    _Type               dd  ?
    SizeOfData          dd  ?
    AddressOfRawData    dd  ?
    PointerToRawData    dd  ?
ends

struc IMAGE_COFF_SYMBOLS_HEADER
    NumberOfSymbols         dd  ?
    LvaToFirstSymbol        dd  ?
    NumberOfLinenumbers     dd  ?
    LvaToFirstLinenumber    dd  ?
    RvaToFirstByteOfCode    dd  ?
    RvaToLastByteOfCode     dd  ?
    RvaToFirstByteOfData    dd  ?
    RvaToLastByteOfData     dd  ?
ends

struc FPO_DATA
    ulOffStart  dd  ?
    cbProcSize  dd  ?
    cdwLocals   dd  ?
    cdwParams   dw  ?
    cbProlog    dw  ?
    cbRegs      dw  ?
    fHasSEH     dw  ?
    fUseBP      dw  ?
    reserved    dw  ?
    cbFrame     dw  ?
ends

struc IMAGE_DEBUG_MISC
    DataType    dd ?
    _Length     dd ?
    Unicode     db ?
    Reserved    rb 3
    Data        db ?
ends

struc IMAGE_FUNCTION_ENTRY32
    StartingAddress dd  ?
    EndingAddress   dd  ?
    EndOfPrologue   dd  ?
ends

struc IMAGE_FUNCTION_ENTRY64
    StartingAddress dq ?
    EndingAddress   dq ?
    union
        EndOfPrologue       dq ?
        UnwindInfoAddress   dq ?
    endu
ends

struc IMAGE_SEPARATE_DEBUG_HEADER
    Signature           dw ?
    Flags               dw ?
    Machine             dw ?
    Characteristics     dw ?
    TimeDateStamp       dd ?
    CheckSum            dd ?
    ImageBase           dd ?
    SizeOfImage         dd ?
    NumberOfSections    dd ?
    ExportedNamesSize   dd ?
    DebugDirectorySize  dd ?
    SectionAlignment    dd ?
    Reserved            rd 2
ends

struc IMAGE_ARCHITECTURE_ENTRY
    FixupInstRVA    dd ?
    NewInst         dd ?
ends

struc IMPORT_OBJECT_HEADER
    Sig1            dw ?
    Sig2            dw ?
    Version         dw ?
    Machine         dw ?
    TimeDateStamp   dd ?
    SizeOfData      dd ?
    union
        Ordinal     dw ?
        Hint        dw ?
    endu
    _Type           dw ?
    NameType        dw ?
    Reserved        dw ?
ends

struc MESSAGE_RESOURCE_ENTRY
    _Length     dw ?
    Flags       dw ?
    _Text       rb 1
ends

struc MESSAGE_RESOURCE_BLOCK
    LowId           dd  ?
    HighId          dd  ?
    OffsetToEntries dd  ?
ends

struc MESSAGE_RESOURCE_DATA
    NumberOfBlocks  dd ?
    Blocks          MESSAGE_RESOURCE_BLOCK ?
ends

struc RTL_CRITICAL_SECTION_DEBUG
    _Type                   dw    ?
    CreatorBackTraceIndex   dw    ?
    CriticalSection         xword ?
    ProcessLocksList        LIST_ENTRY ?
    EntryCount              dd    ?
    ContentionCount         dd    ?
    Spare                   rd    2
ends
define RTL_RESOURCE_DEBUG                       RTL_CRITICAL_SECTION_DEBUG

struc RTL_CRITICAL_SECTION
    DebugInfo       xword ?
    LockCount       dd    ?
    RecursionCount  dd    ?
    OwningThread    xword ?
    LockSemaphore   xword ?
    SpinCount       dd    ?
ends

struc RTL_CONDITION_VARIABLE
    _Ptr    xword ?
ends

struc EVENTLOGRECORD
    _Length             dd  ?
    Reserved            dd  ?
    RecordNumber        dd  ?
    TimeGenerated       dd  ?
    TimeWritten         dd  ?
    EventID             dd  ?
    EventType           dw  ?
    NumStrings          dw  ?
    EventCategory       dw  ?
    ReservedFlags       dw  ?
    ClosingRecordNumber dd  ?
    StringOffset        dd  ?
    UserSidLength       dd  ?
    UserSidOffset       dd  ?
    DataLength          dd  ?
    DataOffset          dd  ?
ends

struc EVENTSFORLOGFILE
    ulSize              dd ?
    szLogicalLogFile    rw MAXLOGICALLOGNAMESIZE
    ulNumRecords        dd ?
    pEventLogRecords    EVENTLOGRECORD ?
ends

struc PACKEDEVENTINFO
    ulSize                  dd ?
    ulNumEventsForLogFile   dd ?
    ulOffsets               dd ?
ends

struc ACTIVATION_CONTEXT_QUERY_INDEX
    ulAssemblyIndex         dd ?
    ulFileIndexInAssembly   dd ?
ends

struc ASSEMBLY_FILE_DETAILED_INFORMATION
    ulFlags             dd   ?
    ulFilenameLength    dd   ?
    ulPathLength        dd   ?
    lpFileName          xword ?
    lpFilePath          xword ?
ends

struc ACTIVATION_CONTEXT_ASSEMBLY_DETAILED_INFORMATION
    ulFlags                             dd    ?
    ulEncodedAssemblyIdentityLength     dd    ?
    ulManifestPathType                  dd    ?
    ulManifestPathLength                dd    ?
    liManifestLastWriteTime             LARGE_INTEGER ?
    ulPolicyPathType                    dd    ?
    ulPolicyPathLength                  dd    ?
    liPolicyLastWriteTime               LARGE_INTEGER ?
    ulMetadataSatelliteRosterIndex      dd    ?
    ulManifestVersionMajor              dd    ?
    ulManifestVersionMinor              dd    ?
    ulPolicyVersionMajor                dd    ?
    ulPolicyVersionMinor                dd    ?
    ulAssemblyDirectoryNameLength       dd    ?
    lpAssemblyEncodedAssemblyIdentity   xword ?
    lpAssemblyManifestPath              xword ?
    lpAssemblyPolicyPath                xword ?
    lpAssemblyDirectoryName             xword ?
    ulFileCount                         dd    ?
ends

struc ACTIVATION_CONTEXT_RUN_LEVEL_INFORMATION
    ulFlags     dd    ?
    RunLevel    xword ?
    UiAccess    dd    ?
ends

struc COMPATIBILITY_CONTEXT_ELEMENT
    Id      GUID ?
    _Type   dw ?
ends

struc ACTIVATION_CONTEXT_DETAILED_INFORMATION
    dwFlags                         dd   ?
    ulFormatVersion                 dd   ?
    ulAssemblyCount                 dd   ?
    ulRootManifestPathType          dd   ?
    ulRootManifestPathChars         dd   ?
    ulRootConfigurationPathType     dd   ?
    ulRootConfigurationPathChars    dd   ?
    ulAppDirPathType                dd   ?
    ulAppDirPathChars               dd   ?
    lpRootManifestPath              xword ?
    lpRootConfigurationPath         xword ?
    lpAppDirPath                    xword ?
ends

struc ACTIVATION_CONTEXT_COMPATIBILITY_INFORMATION
    ElementCount    dd ?
    Elements        COMPATIBILITY_CONTEXT_ELEMENT ?
ends

struc SUPPORTED_OS_INFO
    OsCount         dw  ?
    MitigationExist dw  ?
    OsList          rw  MAX_SUPPORTED_OS_NUM
ends

struc HARDWARE_COUNTER_DATA
    _Type       dd  ?
    Reserved    dd  ?
    Value       dq  ?
ends

struc PERFORMANCE_DATA
    _Size               dw ?
    Version             db ?
    HwCountersCount     db ?
    ContextSwitchCount  dd ?
    WaitReasonBitMap    dq ?
    CycleTime           dq ?
    RetryCount          dd ?
    Reserved            dd ?
    HwCounters          rs HARDWARE_COUNTER_DATA,16
ends

struc TAPE_ERASE
    _Type       dd  ?
    Immediate   db  ?
ends

struc TAPE_PREPARE
    Operation   dd  ?
    Immediate   db  ?
ends

struc TAPE_WRITE_MARKS
    _Type       dd  ?
    Count       dd  ?
    Immediate   db  ?
ends

struc TAPE_GET_POSITION
    _Type       dd  ?
    Partition   dd  ?
    _Offset     LARGE_INTEGER ?
ends

struc TAPE_SET_POSITION
    Method      dd ?
    Partition   dd ?
    _Offset     LARGE_INTEGER ?
    Immediate   db ?
ends

struc TAPE_GET_DRIVE_PARAMETERS
    ECC                     db  ?
    Compression             db  ?
    DataPadding             db  ?
    ReportSetmarks          db  ?
    DefaultBlockSize        dd  ?
    MaximumBlockSize        dd  ?
    MinimumBlockSize        dd  ?
    MaximumPartitionCount   dd  ?
    FeaturesLow             dd  ?
    FeaturesHigh            dd  ?
    EOTWarningZoneSize      dd  ?
ends

struc TAPE_SET_DRIVE_PARAMETERS
    ECC                 db  ?
    Compression         db  ?
    DataPadding         db  ?
    ReportSetmarks      db  ?
    EOTWarningZoneSize  dd  ?
ends

struc TAPE_GET_MEDIA_PARAMETERS
    Capacity        LARGE_INTEGER ?
    Remaining       LARGE_INTEGER ?
    BlockSize       dd ?
    PartitionCount  dd ?
    WriteProtected  db ?
ends

struc TAPE_SET_MEDIA_PARAMETERS
    BlockSize   dd  ?
ends

struc TAPE_CREATE_PARTITION
    Method  dd  ?
    Count   dd  ?
    _Size   dd  ?
ends

struc TAPE_WMI_OPERATIONS
    Method          dd    ?
    DataBufferSize  dd    ?
    DataBuffer      xword ?
ends

struc TRANSACTION_BASIC_INFORMATION
    TransactionId   GUID ?
    State           dd ?
    Outcome         dd ?
ends

struc TRANSACTIONMANAGER_BASIC_INFORMATION
    TmIdentity   GUID ?
    VirtualClock LARGE_INTEGER ?
ends

struc TRANSACTIONMANAGER_LOG_INFORMATION
    LogIdentity GUID ?
ends

struc TRANSACTIONMANAGER_LOGPATH_INFORMATION
    LogPathLength   dd ?
    LogPath         rw 1
ends

struc TRANSACTIONMANAGER_RECOVERY_INFORMATION
    LastRecoveredLsn dq ?
ends

struc TRANSACTIONMANAGER_OLDEST_INFORMATION
    OldestTransactionGuid GUID ?
ends

struc TRANSACTION_PROPERTIES_INFORMATION
    IsolationLevel      dd ?
    IsolationFlags      dd ?
    Timeout             LARGE_INTEGER ?
    Outcome             dd ?
    DescriptionLength   dd ?
    Description         rw 1
ends

struc TRANSACTION_BIND_INFORMATION
    TmHandle xword ?
ends

struc TRANSACTION_ENLISTMENT_PAIR
    EnlistmentId        GUID ?
    ResourceManagerId   GUID ?
ends

struc TRANSACTION_ENLISTMENTS_INFORMATION
    NumberOfEnlistments dd ?
    EnlistmentPair      TRANSACTION_ENLISTMENT_PAIR ?
ends

struc TRANSACTION_SUPERIOR_ENLISTMENT_INFORMATION
    SuperiorEnlistmentPair TRANSACTION_ENLISTMENT_PAIR ?
ends

struc TRANSACTION_LIST_ENTRY
    uow GUID ?
ends

struc TRANSACTION_LIST_INFORMATION
    NumberOfTransactions    dd ?
    TransactionInformation  TRANSACTION_LIST_ENTRY ?
ends

struc RESOURCEMANAGER_BASIC_INFORMATION
    ResourceManagerId   GUID ?
    DescriptionLength   dd    ?
    Description         rw    1
ends

struc RESOURCEMANAGER_COMPLETION_INFORMATION
    IoCompletionPortHandle  xword ?
    CompletionKey           xword ?
ends

struc ENLISTMENT_BASIC_INFORMATION   
    EnlistmentId        GUID ?
    TransactionId       GUID ?
    ResourceManagerId   GUID ?
ends

struc ENLISTMENT_CRM_INFORMATION
    CrmTransactionManagerId GUID ?
    CrmResourceManagerId    GUID ?
    CrmEnlistmentId         GUID ?
ends

struc KTMOBJECT_CURSOR
    LastQuery       GUID ?
    ObjectIdCount   dd ?
    ObjectIds       GUID ?
ends

struc TP_POOL_STACK_INFORMATION
    StackReserve    dd ?
    StackCommit     dd ?
ends

struc TRANSACTION_NOTIFICATION
    TransactionKey          xword ?
    TransactionNotification dd    ?
    TmVirtualClock          LARGE_INTEGER ?
    ArgumentLength          dd    ?
ends

struc TRANSACTION_NOTIFICATION_RECOVERY_ARGUMENT
    EnlistmentId    GUID ?
    uow             GUID ?
ends

struc TRANSACTION_NOTIFICATION_TM_ONLINE_ARGUMENT
    TmIdentity  GUID ?
    Flags       dd   ?
ends

struc TRANSACTION_NOTIFICATION_SAVEPOINT_ARGUMENT
    SavepointId dd  ?
ends

struc TRANSACTION_NOTIFICATION_PROPAGATE_ARGUMENT
    PropagationCookie   dd ?
    uow                 GUID ?
    TmIdentity          GUID ?
    BufferLength        dd ?
ends

struc TRANSACTION_NOTIFICATION_MARSHAL_ARGUMENT
    MarshalCookie   dd ?
    uow             GUID ?
ends

struc KCRM_MARSHAL_HEADER
    VersionMajor dd ?
    VersionMinor dd ?
    NumProtocols dd ?
    Unused       dd ?
ends

struc KCRM_TRANSACTION_BLOB
    uow             GUID ?
    TmIdentity      GUID ?
    IsolationLevel  dd ?
    IsolationFlags  dd ?
    Timeout         dd ?
    Description     rw MAX_TRANSACTION_DESCRIPTION_LENGTH
ends

struc KCRM_PROTOCOL_BLOB
    ProtocolId              GUID ?
    StaticInfoLength        dd ?
    TransactionIdInfoLength dd ?
    Unused1                 dd ?
    Unused2                 dd ?
ends

struc IMAGE_COR20_HEADER
    cb                  dd ?
    MajorRuntimeVersion dw ?
    MinorRuntimeVersion dw ?
    MetaData            IMAGE_DATA_DIRECTORY ?
    Flags               dd ?
    union
        EntryPointToken dw ?
        EntryPointRVA   dw ?
    endu
    Resources               IMAGE_DATA_DIRECTORY ?
    StrongNameSignature     IMAGE_DATA_DIRECTORY ?
    CodeManagerTable        IMAGE_DATA_DIRECTORY ?
    VTableFixups            IMAGE_DATA_DIRECTORY ?
    ExportAddressTableJumps IMAGE_DATA_DIRECTORY ?
    ManagedNativeHeader     IMAGE_DATA_DIRECTORY ?
ends

struc RTL_RUN_ONCE
    aPtr xword ?
ends

struc RTL_BARRIER
    Reserved1   dd    ?
    Reserved2   dd    ?
    Reserved3   xword ?
                xword ?
    Reserved4   dd    ?
    Reserved5   dd    ?
ends

struc PROCESSOR_NUMBER
    _Group   dw ?
    Number   db ?
    Reserved db ?
ends

struc GROUP_AFFINITY
    _Mask    xword ?
    _Group   dw    ?
    Reserved rw    3
ends


;======================================== netapi32 =======================================;
struc USE_INFO_0
    ui0_local  xword ?
    ui0_remote xword ?
ends

struc USE_INFO_1
    ui1_local    xword ?
    ui1_remote   xword ?
    ui1_password xword ?
    ui1_status   dd    ?
    ui1_asg_type dd    ?
    ui1_refcount dd    ?
    ui1_usecount dd    ?
ends

struc USE_INFO_2
    ui2_local      xword ?
    ui2_remote     xword ?
    ui2_password   xword ?
    ui2_status     dd    ?
    ui2_asg_type   dd    ?
    ui2_refcount   dd    ?
    ui2_usecount   dd    ?
    ui2_username   xword ?
    ui2_domainname xword ?
ends

struc USE_INFO_3
    ui3_ui2   USE_INFO_2 ?
    ui3_flags dd ?
ends

;======================================= odbc32 =======================================;
struc DATE_STRUCT
    year  dw ?
    month dw ?
    day   dw ?
ends

struc SQL_DATE_STRUCT
    year  dw ?
    month dw ?
    day   dw ?
ends

struc TIME_STRUCT
    hour   dw ?
    minute dw ?
    second dw ?
ends

struc SQL_TIME_STRUCT
    hour   dw ?
    minute dw ?
    second dw ?
ends

struc TIMESTAMP_STRUCT
    year     dw ?
    month    dw ?
    day      dw ?
    hour     dw ?
    minute   dw ?
    second   dw ?
    fraction dd ?
ends

struc SQL_TIMESTAMP_STRUCT
    year     dw ?
    month    dw ?
    day      dw ?
    hour     dw ?
    minute   dw ?
    second   dw ?
    fraction dd ?
ends

struc SQL_YEAR_MONTH_STRUCT
    year  dd ?
    month dd ?
ends

struc SQL_DAY_SECOND_STRUCT
    day      dd ?
    hour     dd ?
    minute   dd ?
    second   dd ?
    fraction dd ?
ends

struc SQL_INTERVAL_STRUCT
    interval_type dd ?
    interval_sign dd ?
    union
        year_month SQL_YEAR_MONTH_STRUCT ?
        day_second SQL_DAY_SECOND_STRUCT ?
     endu
ends
SQL_MAX_NUMERIC_LEN equ 16

struc SQL_NUMERIC_STRUCT
    precision db ?
    scale     db ?
    sign      db ?
    val       rb SQL_MAX_NUMERIC_LEN
ends

struc SQLGUID
    Data1 dd ?
    Data2 dw ?
    Data3 dw ?
    Data4 rb 8
ends

;======================================== ole32 =======================================;
struc DRAG_FLAVORINFO
    cfFormat    dd ?
    FlavorFlags dd ?
    fAddData    dd ?
    reserved    dd ?
ends

struc OleMBarRec
    reserved dd ?
ends

struc OLESTREAMVTBL
    Get    xword ?
    Put    xword ?
ends

struc OLESTREAM
    lpstbl xword ?
ends

;======================================== oleaut32 =======================================;
struc NUMPARSE
    cDig       dd ?
    dwInFlags  dd ?
    dwOutFlags dd ?
    cchUsed    dd ?
    nBaseShift dd ?
    nPwr10     dd ?
ends

struc UDATE
    _st SYSTEMTIME ?
    wDayOfYear  dw ?
ends

struc PARAMDATA
    szName     xword ?
    vt         dw    ?
ends

struc METHODDATA
    szName     xword ?
    ppdata     xword ?
    dispid     dd   ?
    iMeth      dd   ?
    cc         dd   ?
    cArgs      dd   ?
    wFlags     dw   ?
    vtReturn   dw   ?
ends

struc INTERFACEDATA
    pmethdata  xword ?
    cMembers   dd   ?
ends

;======================================== opengl32 =======================================;
struct AUX_EVENTREC
    event   dd ?
    data    rb 4
ends

struct AUX_RGBImageRec
    sizeX   dd ?
    sizeY   dd ?
    data    dd ?
ends

;======================================== rasapi32 =======================================;
struc RASCONNA
    dwSize       dd    ?
    hrasconn     xword ?
    szEntryName  rb    <RAS_MaxEntryName+1>
    szDeviceType rb    <RAS_MaxDeviceType+1>
    szDeviceName rb    <RAS_MaxDeviceName+1>
    szPhonebook  rb    MAX_PATH
    dwSubEntry   dd    ?
ends

struc RASCONNW
    dwSize       dd    ?
    hrasconn     xword ?
    szEntryName  rw    <RAS_MaxEntryName+1>
    szDeviceType rw    <RAS_MaxDeviceType+1>
    szDeviceName rw    <RAS_MaxDeviceName+1>
    szPhonebook  rw    MAX_PATH
    dwSubEntry   dd    ?
ends

struc RASCONNSTATUSA
    dwSize        dd    ?
    rasconnstate  xword ?
    dwError       dd    ?
    szDeviceType  rb    <RAS_MaxDeviceType+1>
    szDeviceName  rb    <RAS_MaxDeviceName+1>
    szPhoneNumber rb    <RAS_MaxPhoneNumber+1>
ends

struc RASCONNSTATUSW
    dwSize        dd    ?
    rasconnstate  xword ?
    dwError       dd    ?
    szDeviceType  rw    <RAS_MaxDeviceType+1>
    szDeviceName  rw    <RAS_MaxDeviceName+1>
    szPhoneNumber rw    <RAS_MaxPhoneNumber+1>
ends

struc RASDIALPARAMSA
    dwSize           dd ?
    szEntryName      rb <RAS_MaxEntryName+1>
    szPhoneNumber    rb <RAS_MaxPhoneNumber+1>
    szCallbackNumber rb <RAS_MaxCallbackNumber+1>
    szUserName       rb <UNLEN+1>
    szPassword       rb <PWLEN+1>
    szDomain         rb <DNLEN+1>
    dwSubEntry       dd ?
    dwCallbackId     dd ?
ends

struc RASDIALPARAMSW
    dwSize           dd ?
    szEntryName      rw <RAS_MaxEntryName+1>
    szPhoneNumber    rw <RAS_MaxPhoneNumber+1>
    szCallbackNumber rw <RAS_MaxCallbackNumber+1>
    szUserName       rw <UNLEN+1>
    szPassword       rw <PWLEN+1>
    szDomain         rw <DNLEN+1>
    dwSubEntry       dd ?
    dwCallbackId     dd ?
ends

struc RASDIALEXTENSIONS
    dwSize      dd    ?
    dwfOptions  dd    ?
    hwndParent  xword ?
    reserved    dd    ?
ends

struc RASENTRYNAMEA
    dwSize      dd ?
    szEntryName rb <RAS_MaxEntryName+1>
ends

struc RASENTRYNAMEW
    dwSize      dd ?
    szEntryName rw <RAS_MaxEntryName+1>
ends

struc RASAMBA
    dwSize          dd ?
    dwError         dd ?
    szNetBiosError  rb <NETBIOS_NAME_LEN+1>
    bLana           db ?
ends

struc RASAMBW
    dwSize          dd ?
    dwError         dd ?
    szNetBiosError  rw <NETBIOS_NAME_LEN+1>
    bLana           db ?
ends

struc RASPPPNBFA
    dwSize            dd ?
    dwError           dd ?
    dwNetBiosError    dd ?
    szNetBiosError    rb <NETBIOS_NAME_LEN+1>
    szWorkstationName rb <NETBIOS_NAME_LEN+1>
    bLana             db ?
ends

struc RASPPPNBFW
    dwSize            dd ?
    dwError           dd ?
    dwNetBiosError    dd ?
    szNetBiosError    rw <NETBIOS_NAME_LEN+1>
    szWorkstationName rw <NETBIOS_NAME_LEN+1>
    bLana             db ?
ends

struc RASPPPIPXA
    dwSize       dd ?
    dwError      dd ?
    szIpxAddress rb <RAS_MaxIpxAddress+1>
ends

struc RASPPPIPXW
    dwSize       dd ?
    dwError      dd ?
    szIpxAddress rw <RAS_MaxIpxAddress+1>
ends

struc RASPPPIPA
    dwSize            dd ?
    dwError           dd ?
    szIpAddress       rb <RAS_MaxIpAddress+1>
    szServerIpAddress rb <RAS_MaxIpAddress+1>
ends

struc RASPPPIPW
    dwSize            dd ?
    dwError           dd ?
    szIpAddress       rw <RAS_MaxIpAddress+1>
    szServerIpAddress rw <RAS_MaxIpAddress+1>
ends

struc RASPPPLCP
    dwSize   dd ?
    fBundled dd ?
ends

struc RASSLIPA
    dwSize      dd ?
    dwError     dd ?
    szIpAddress rb <RAS_MaxIpAddress+1>
ends

struc RASSLIPW
    dwSize      dd ?
    dwError     dd ?
    szIpAddress rb <RAS_MaxIpAddress+1>
ends

struc RASDEVINFOA
    dwSize       dd ?
    szDeviceType rb <RAS_MaxDeviceType+1>
    szDeviceName rb <RAS_MaxDeviceName+1>
ends

struc RASDEVINFOW
    dwSize       dd ?
    szDeviceType rw <RAS_MaxDeviceType+1>
    szDeviceName rw <RAS_MaxDeviceName+1>
ends

struc RASCTRYINFO
    dwSize              dd ?
    dwCountryID         dd ?
    dwNextCountryID     dd ?
    dwCountryCode       dd ?
    dwCountryNameOffset dd ?
ends
RASCTRYINFOA equ <RASCTRYINFO>
RASCTRYINFOW equ <RASCTRYINFO>

struc RASIPADDR
    a   db ?
    b   db ?
    _c  db ?
    d   db ?
ends

struc RASENTRYA
    dwSize                      dd ?
    dwfOptions                  dd ?
    dwCountryID                 dd ?
    dwCountryCode               dd ?
    szAreaCode                  rb <RAS_MaxAreaCode+1>
    szLocalPhoneNumber          rb <RAS_MaxPhoneNumber+1>
    dwAlternateOffset           dd ?
    ipaddr                      RASIPADDR ?
    ipaddrDns                   RASIPADDR ?
    ipaddrDnsAlt                RASIPADDR ?
    ipaddrWins                  RASIPADDR ?
    ipaddrWinsAlt               RASIPADDR ?
    dwFrameSize                 dd ?
    dwfNetProtocols             dd ?
    dwFramingProtocol           dd ?
    szScript                    rb MAX_PATH
    szAutodialDll               rb MAX_PATH
    szAutodialFunc              rb MAX_PATH
    szDeviceType                rb <RAS_MaxDeviceType+1>
    szDeviceName                rb <RAS_MaxDeviceName+1>
    szX25PadType                rb <RAS_MaxPadType+1>
    szX25Address                rb <RAS_MaxX25Address+1>
    szX25Facilities             rb <RAS_MaxFacilities+1>
    szX25UserData               rb <RAS_MaxUserData+1>
    dwChannels                  dd ?
    dwReserved1                 dd ?
    dwReserved2                 dd ?
    dwSubEntries                dd ?
    dwDialMode                  dd ?
    dwDialExtraPercent          dd ?
    dwDialExtraSampleSeconds    dd ?
    dwHangUpExtraPercent        dd ?
    dwHangUpExtraSampleSeconds  dd ?
    dwIdleDisconnectSeconds     dd ?
ends

struc RASENTRYW
    dwSize                      dd ?
    dwfOptions                  dd ?
    dwCountryID                 dd ?
    dwCountryCode               dd ?
    szAreaCode                  dw <RAS_MaxAreaCode+1>
    szLocalPhoneNumber          dw <RAS_MaxPhoneNumber+1>
    dwAlternateOffset           dd ?
    ipaddr                      RASIPADDR ?
    ipaddrDns                   RASIPADDR ?
    ipaddrDnsAlt                RASIPADDR ?
    ipaddrWins                  RASIPADDR ?
    ipaddrWinsAlt               RASIPADDR ?
    dwFrameSize                 dd ?
    dwfNetProtocols             dd ?
    dwFramingProtocol           dd ?
    szScript                    rw MAX_PATH
    szAutodialDll               rw MAX_PATH
    szAutodialFunc              rw MAX_PATH
    szDeviceType                rw <RAS_MaxDeviceType+1>
    szDeviceName                rw <RAS_MaxDeviceName+1>
    szX25PadType                rw <RAS_MaxPadType+1>
    szX25Address                rw <RAS_MaxX25Address+1>
    szX25Facilities             rw <RAS_MaxFacilities+1>
    szX25UserData               rw <RAS_MaxUserData+1>
    dwChannels                  dd ?
    dwReserved1                 dd ?
    dwReserved2                 dd ?
    dwSubEntries                dd ?
    dwDialMode                  dd ?
    dwDialExtraPercent          dd ?
    dwDialExtraSampleSeconds    dd ?
    dwHangUpExtraPercent        dd ?
    dwHangUpExtraSampleSeconds  dd ?
    dwIdleDisconnectSeconds     dd ?
ends

struc RASADPARAMS
    dwSize      dd    ?
    hwndOwner   xword ?
    dwFlags     dd    ?
    xDlg        dd    ?
    yDlg        dd    ?
ends

struc RASSUBENTRYA
    dwSize              dd ?
    dwfFlags            dd ?
    szDeviceType        rb <RAS_MaxDeviceType+1>
    szDeviceName        rb <RAS_MaxDeviceName+1>
    szLocalPhoneNumber  rb <RAS_MaxPhoneNumber+1>
    dwAlternateOffset   dd ?
ends

struc RASSUBENTRYW
    dwSize              dd ?
    dwfFlags            dd ?
    szDeviceType        rw <RAS_MaxDeviceType+1>
    szDeviceName        rw <RAS_MaxDeviceName+1>
    szLocalPhoneNumber  rw <RAS_MaxPhoneNumber+1>
    dwAlternateOffset   dd ?
ends

struc RASCREDENTIALSA
    dwSize      dd ?
    dwMask      dd ?
    szUserName  rb <UNLEN+1>
    szPassword  rb <PWLEN+1>
    szDomain    rb <DNLEN+1>
ends

struc RASCREDENTIALSW
    dwSize      dd ?
    dwMask      dd ?
    szUserName  rw <UNLEN+1>
    szPassword  rw <PWLEN+1>
    szDomain    rw <DNLEN+1>
ends

struc RASAUTODIALENTRYA
    dwSize            dd ?
    dwFlags           dd ?
    dwDialingLocation dd ?  
    szEntry           rb <RAS_MaxEntryName+1>
ends

struc RASAUTODIALENTRYW
    dwSize            dd ?
    dwFlags           dd ?
    dwDialingLocation dd ?  
    szEntry           rw <RAS_MaxEntryName+1>
ends

;======================================== shell32 =======================================;
struc DRAGINFOA
    uSize       dd    ?
    pt          POINT ?
    fNC         dd    ?
    lpFileList  xword ?
    grfKeyState dd    ?
ends

struc DRAGINFOW
    uSize       dd    ?
    pt          POINT ?
    fNC         dd    ?
    lpFileList  xword ?
    grfKeyState dd    ?
ends

struc APPBARDATA
    cbSize           dd     ?
    hWnd             xword  ?
    uCallbackMessage dd     ?
    uEdge            dd     ?
    rc               RECT   ?
    lParam           xword  ?
ends

struc SHFILEOPSTRUCTA
    hwnd                   xword ?
    wFunc                  dd    ?
    pFrom                  xword ?
    pTo                    xword ?
    fFlags                 dw    ?
    fAnyOperationsAborted  dd    ?
    hNameMappings          xword ?
    lpszProgressTitle      xword ?
ends

struc SHFILEOPSTRUCTW
    hwnd                   xword ?
    wFunc                  dd    ?
    pFrom                  xword ?
    pTo                    xword ?
    fFlags                 dw    ?
    fAnyOperationsAborted  dd    ?
    hNameMappings          xword ?
    lpszProgressTitle      xword ?
ends

struc SHNAMEMAPPINGA
    pszOldPath xword ?
    pszNewPath xword ?
    cchOldPath dd    ?
    cchNewPath dd    ?
ends

struc SHNAMEMAPPINGW
    pszOldPath xword ?
    pszNewPath xword ?
    cchOldPath dd    ?
    cchNewPath dd    ?
ends

struc SHELLEXECUTEINFOA
    cbSize         dd    ?
    fMask          dd    ?
    hwnd           xword ?
    lpVerb         xword ?
    lpFile         xword ?
    lpParameters   xword ?
    lpDirectory    xword ?
    nShow          dd    ?
    hInstApp       xword ?
    lpIDList       xword ?
    lpClass        xword ?
    hkeyClass      xword ?
    dwHotKey       dd    ?
    union
        hIcon      xword ?
        hMonitor   xword ?
    endu
    hProcess       xword ?
ends

struc SHELLEXECUTEINFOW
    cbSize         dd    ?
    fMask          dd    ?
    hwnd           xword ?
    lpVerb         xword ?
    lpFile         xword ?
    lpParameters   xword ?
    lpDirectory    xword ?
    nShow          dd    ?
    hInstApp       xword ?
    lpIDList       xword ?
    lpClass        xword ?
    hkeyClass      xword ?
    dwHotKey       dd    ?
    union
        hIcon      xword ?
        hMonitor   xword ?
    endu
    hProcess       xword ?
ends

struc SHCREATEPROCESSINFOW
    cbSize               dd    ?
    fMask                dd    ?
    hwnd                 xword ?
    pszFile              xword ?
    pszParameters        xword ?
    pszCurrentDirectory  xword ?
    hUserToken           xword ?
    lpProcessAttributes  xword ?
    lpThreadAttributes   xword ?
    bInheritHandles      dd    ?
    dwCreationFlags      dd    ?
    lpStartupInfo        xword ?
    lpProcessInformation xword ?
ends

struc ASSOCIATIONELEMENT
    ac         dd    ?
    hkClass    xword ?
    pszClass   xword ?
ends

struc SHQUERYRBINFO
    cbSize      dd    ?
    i64Size     dq    ?
    i64NumItems dq    ?
ends

struc NOTIFYICONDATAA
    cbSize              dd    ?
    hWnd                xword ?
    uID                 dd    ?
    uFlags              dd    ?
    uCallbackMessage    dd    ?
    hIcon               xword ?
    #if NTDDI_VERSION < NTDDI_WIN2K
        szTip           rb    64
    #endif
    #if NTDDI_VERSION >= NTDDI_WIN2K
        szTip           rb    128
        dwState         dd   ?
        dwStateMask     dd   ?
        szInfo          rb   256
        union
            uTimeout    dd   ?
            uVersion    dd   ?
        endu
        szInfoTitle     rb   64
        dwInfoFlags     dd   ?
    #endif 
    #if NTDDI_VERSION >= NTDDI_WINXP
        guidItem        GUID ?
    #endif
    #if NTDDI_VERSION >= NTDDI_VISTA
        hBalloonIcon    xword ?
    #endif
ends

struc NOTIFYICONDATAW
    cbSize              dd    ?
    hWnd                xword ?
    uID                 dd    ?
    uFlags              dd    ?
    uCallbackMessage    dd    ?
    hIcon               xword ?
    #if NTDDI_VERSION < NTDDI_WIN2K
        szTip           rw    64
    #endif
    #if NTDDI_VERSION >= NTDDI_WIN2K
        szTip           rw   128
        dwState         dd   ?
        dwStateMask     dd   ?
        szInfo          rw   256
        union
            uTimeout    dd   ?
            uVersion    dd   ?
        endu
        szInfoTitle     rw   64
        dwInfoFlags     dd   ?
    #endif 
    #if NTDDI_VERSION >= NTDDI_WINXP
        guidItem        GUID ?
    #endif
    #if NTDDI_VERSION >= NTDDI_VISTA
        hBalloonIcon    xword ?
    #endif
ends

struc NOTIFYICONIDENTIFIER
    cbSize     dd    ?
    hWnd       xword ?
    uID        dd    ?
    guidItem   GUID  ?
ends

struc SHFILEINFOA
    hIcon           xword ?
    iIcon           dd    ?
    dwAttributes    dd    ?
    szDisplayName   rb    MAX_PATH
    szTypeName      rb    80
ends

struc SHFILEINFOW
    hIcon           xword ?
    iIcon           dd    ?
    dwAttributes    dd    ?
    szDisplayName   rw    MAX_PATH
    szTypeName      rw    80
ends

struc SHSTOCKICONINFO
    cbSize         dd    ?
    hIcon          xword ?
    iSysImageIndex dd    ?
    iIcon          dd    ?
    szPath         rw    MAX_PATH
ends

struc OPEN_PRINTER_PROPS_INFOA
    dwSize       dd    ?
    pszSheetName xword ?
    uSheetIndex  dd    ?
    dwFlags      dd    ?
    bModal       dd    ?
ends

struc OPEN_PRINTER_PROPS_INFOW
    dwSize       dd    ?
    pszSheetName xword ?
    uSheetIndex  dd    ?
    dwFlags      dd    ?
    bModal       dd    ?
ends

struc NC_ADDRESS
    pAddrInfo      xword ?
    PortNumber     dw    ?
    PrefixLength   db    ?
ends

struc DLLVERSIONINFO
    cbSize          dd  ?
    dwMajorVersion  dd  ?
    dwMinorVersion  dd  ?
    dwBuildNumber   dd  ?
    dwPlatformID    dd  ?
ends

struc RUNASNEWUSERPARAM
    eventName rw 56
    execFile  rw MAX_PATH
    arguments rw MAX_PATH
    padding   rw 1536
    directory rw (MAX_PATH-4)
ends

;======================================== user32 =======================================;
struc POINTER_DEVICE_INFO
    displayOrientation  dd    ?
    device              xword ?
    pointerDeviceType   xword ?
    _monitor            xword ?
    startingCursorId    dd    ?
    maxActiveContacts   dw    ?
    productString       rw    POINTER_DEVICE_PRODUCT_STRING_MAX
ends

struc POINTER_DEVICE_PROPERTY
    logicalMin   dd ?
    logicalMax   dd ?
    physicalMin  dd ?
    physicalMax  dd ?
    unit         dd ?
    unitExponent dd ?
    usagePageId  dw ?
    usageId      dw ?
ends

struc POINTER_DEVICE_CURSOR_INFO
    cursorId dd ?
    cursor   xword   ?
ends

struc POWERBROADCAST_SETTING
    PowerSetting rs GUID,1
    DataLength   dd ?
    Data         db ?
ends

struc TOUCHPREDICTIONPARAMETERS
    cbSize          dd ?
    dwLatency       dd ?
    dwSampleTime    dd ?
    bUseHWTimeStamp dd ?
ends

struc ICONINFOEXA
    cbSize      dd    ?
    fIcon       dd    ?
    xHotspot    dd    ?
    yHotspot    dd    ?
    hbmMask     xword ?
    hbmColor    xword ?
    wResID      dw    ?
    szModName   rb    MAX_PATH
    szResName   rb    MAX_PATH
ends

struc ICONINFOEXW
    cbSize      dd    ?
    fIcon       dd    ?
    xHotspot    dd    ?
    yHotspot    dd    ?
    hbmMask     xword ?
    hbmColor    xword ?
    wResID      dw    ?
    szModName   rw    MAX_PATH
    szResName   rw    MAX_PATH
ends

struc RAWINPUTDEVICELIST
    hDevice xword ?
    dwType  dd    ?
ends

struc RAWINPUTDEVICE
    usUsagePage dw    ?
    usUsage     dw    ?
    dwFlags     dd    ?
    hwndTarget  xword ?
ends

struc RAWHID
    dwSizeHid   dd ?
    dwCount     dd ?
    bRawData    rb 1
ends

struc RAWINPUTHEADER
    dwType  dd    ?
    dwSize  dd    ?
    hDevice xword ?
    wParam  xword ?
ends

struc RAWKEYBOARD
    MakeCode         dw ?
    Flags            dw ?
    Reserved         dw ?
    VKey             dw ?
    Message          dd ?
    ExtraInformation dd ?
ends

struc RID_DEVICE_INFO_MOUSE
    dwId                dd ?
    dwNumberOfButtons   dd ?
    dwSampleRate        dd ?
    fHasHorizontalWheel dd ?
ends

struc RID_DEVICE_INFO_KEYBOARD
    dwType                  dd ?
    dwSubType               dd ?
    dwKeyboardMode          dd ?
    dwNumberOfFunctionKeys  dd ?
    dwNumberOfIndicators    dd ?
    dwNumberOfKeysTotal     dd ?
ends

struc RID_DEVICE_INFO_HID
    dwVendorId      dd ?
    dwProductId     dd ?
    dwVersionNumber dd ?
    usUsagePage     dw ?
    usUsage         dw ?
ends

struc RID_DEVICE_INFO
    cbSize  dd ?
    dwType  dd ?
    union
        mouse    rs RID_DEVICE_INFO_MOUSE,1
        keyboard rs RID_DEVICE_INFO_KEYBOARD,1
        hid      rs RID_DEVICE_INFO_HID,1
    endu
ends

struc AUDIODESCRIPTION
    cbSize  dd  ?
    Enabled dd  ?
    Locale  dd  ?
ends

struc CBT_CREATEWNDA
    lpcs            xword ?
    hwndInsertAfter xword ?
ends

struc CBT_CREATEWNDW
    lpcs            xword ?
    hwndInsertAfter xword ?
ends

struc CBTACTIVATESTRUCT
    fMouse      dd    ?
    hWndActive  xword ?
ends

struc WTSSESSION_NOTIFICATION
    cbSize      dd ?
    dwSessionId dd ?
ends

struc SHELLHOOKINFO
    hwnd xword ?
    rc   rs    RECT,1
ends

struc EVENTMSG
    message dd    ?
    paramL  dd    ?
    paramH  dd    ?
    time    dd    ?
    hwnd    xword ?
ends

struc CWPSTRUCT
    lParam  xword ?
    wParam  xword ?
    message dd    ?
    hwnd    xword ?
ends

struc CWPRETSTRUCT
    lResult xword ?
    lParam  xword ?
    wParam  xword ?
    message dd    ?
    hwnd    xword ?
ends

struc KBDLLHOOKSTRUCT
    vkCode      dd    ?
    scanCode    dd    ?
    flags       dd    ?
    time        dd    ?
    dwExtraInfo xword ?
ends

struc MSLLHOOKSTRUCT
    pt          rs    POINT,1
    mouseData   dd    ?
    flags       dd    ?
    time        dd    ?
    dwExtraInfo xword ?
ends

struc DEBUGHOOKINFO
    idThread            dd    ?
    idThreadInstaller   dd    ?
    lParam              xword ?
    wParam              xword ?
    _code               dd    ?
ends

struc MOUSEHOOKSTRUCT
    pt              rs    POINT,1
    hwnd            xword ?
    wHitTestCode    dd    ?
    dwExtraInfo     xword ?
ends

struc MOUSEHOOKSTRUCTEX
    MouseHookStruct rs MOUSEHOOKSTRUCT,1
    mouseData       dd ?
ends

struc HARDWAREHOOKSTRUCT
    hwnd    xword ?
    message dd    ?
    wParam  xword ?
    lParam  xword ?
ends

struc MOUSEMOVEPOINT
    x           dd    ?
    y           dd    ?
    time        dd    ?
    dwExtraInfo xword ?
ends

struc USEROBJECTFLAGS
    fInherit    dd ?
    fReserved   dd ?
    dwFlags     dd ?
ends

struc WNDCLASSEXA
    cbSize          dd    ?
    style           dd    ?
    lpfnWndProc     xword ?
    cbClsExtra      dd    ?
    cbWndExtra      dd    ?
    hInstance       xword ?
    hIcon           xword ?
    hCursor         xword ?
    hbrBackground   xword ?
    lpszMenuName    xword ?
    lpszClassName   xword ?
    hIconSm         xword ?
ends

struc WNDCLASSEXW
    cbSize          dd    ?
    style           dd    ?
    lpfnWndProc     xword ?
    cbClsExtra      dd    ?
    cbWndExtra      dd    ?
    hInstance       xword ?
    hIcon           xword ?
    hCursor         xword ?
    hbrBackground   xword ?
    lpszMenuName    xword ?
    lpszClassName   xword ?
    hIconSm         xword ?
ends

struc WNDCLASSA
    style           dd    ?
    lpfnWndProc     xword ?
    cbClsExtra      dd    ?
    cbWndExtra      dd    ?
    hInstance       xword ?
    hIcon           xword ?
    hCursor         xword ?
    hbrBackground   xword ?
    lpszMenuName    xword ?
    lpszClassName   xword ?
ends

struc WNDCLASSW
    style           dd    ?
    lpfnWndProc     xword ?
    cbClsExtra      dd    ?
    cbWndExtra      dd    ?
    hInstance       xword ?
    hIcon           xword ?
    hCursor         xword ?
    hbrBackground   xword ?
    lpszMenuName    xword ?
    lpszClassName   xword ?
ends

struc MSG
    hwnd    xword ?
    message dd    ?
    wParam  xword ?
    lParam  xword ?
    time    dd    ?
    pt      rs    POINT,1
ends

struc MINMAXINFO
    ptReserved      rs POINT,1
    ptMaxSize       rs POINT,1
    ptMaxPosition   rs POINT,1
    ptMinTrackSize  rs POINT,1
    ptMaxTrackSize  rs POINT,1
ends

struc COPYDATASTRUCT
    dwData xword ?
    cbData dd    ?
    lpData xword ?
ends

struc MDINEXTMENU
    hmenuIn     xword ?
    hmenuNext   xword ?
    hwndNext    xword ?
ends

struc WINDOWPOS
    hwnd            xword ?
    hwndInsertAfter xword ?
    x               dd    ?
    y               dd    ?
    lx              dd    ?
    cy              dd    ?
    flags           dd    ?
ends

struc NCCALCSIZE_PARAMS
    rgrc  rs    RECT,3
    lppos xword ?
ends

struc TRACKMOUSEEVENT
    cbSize      dd    ?
    dwFlags     dd    ?
    hwndTrack   xword ?
    dwHoverTime dd    ?
ends

struc ACCEL
    fVirt db  ?
    key   dw  ?
    cmd   dw  ?
ends

struc PAINTSTRUCT
    hdc         xword ?
    fErase      dd    ?
    rcPaint     rs    RECT,1
    fRestore    dd    ?
    fIncUpdate  dd    ?
    rgbReserved rb    32
ends

struc CREATESTRUCTA
    lpCreateParams  xword ?
    hInstance       xword ?
    hMenu           xword ?
    hwndParent      xword ?
    cy              dd    ?
    _cx             dd    ?
    y               dd    ?
    x               dd    ?
    style           dd    ?
    lpszName        xword ?
    lpszClass       xword ?
    dwExStyle       dd    ?
ends

struc CREATESTRUCTW
    lpCreateParams  xword ?
    hInstance       xword ?
    hMenu           xword ?
    hwndParent      xword ?
    cy              dd    ?
    _cx             dd    ?
    y               dd    ?
    x               dd    ?
    style           dd    ?
    lpszName        xword ?
    lpszClass       xword ?
    dwExStyle       dd    ?
ends

struc WINDOWPLACEMENT
    _length          dd ?
    flags            dd ?
    showCmd          dd ?
    ptMinPosition    rs POINT,1
    ptMaxPosition    rs POINT,1
    rcNormalPosition rs RECT,1
ends

struc STYLESTRUCT
    styleOld dd ?
    styleNew dd ?
ends

struc MEASUREITEMSTRUCT
    CtlType     dd    ?
    CtlID       dd    ?
    itemID      dd    ?
    itemWidth   dd    ?
    itemHeight  dd    ?
    itemData    xword ?
ends

struc DRAWITEMSTRUCT
    CtlType     dd    ?
    CtlID       dd    ?
    itemID      dd    ?
    itemAction  dd    ?
    itemState   dd    ?
    hwndItem    xword ?
    hDC         xword ?
    rcItem      rs    RECT,1
    itemData    xword ?
ends

struc DELETEITEMSTRUCT
    CtlType     dd    ?
    CtlID       dd    ?
    itemID      dd    ?
    hwndItem    xword ?
    itemData    xword ?
ends

struc COMPAREITEMSTRUCT
    CtlType     dd    ?
    CtlID       dd    ?
    hwndItem    xword ?
    itemID1     dd    ?
    itemData1   xword ?
    itemID2     dd    ?
    itemData2   xword ?
    dwLocaleId  dd    ?
ends

struc FLASHWINFO
    cbSize      dd    ?
    hwnd        xword ?
    dwFlags     dd    ?
    uCount      dd    ?
    dwTimeout   dd    ?
ends

struc DLGTEMPLATE
    style           dd  ?
    dwExtendedStyle dd  ?
    cdit            dw  ?
    x               dw  ?
    y               dw  ?
    _cx             dw  ?
    cy              dw  ?
ends

struc DLGITEMTEMPLATE
    style           dd  ?
    dwExtendedStyle dd  ?
    x               dw  ?
    y               dw  ?
    _cx             dw  ?
    cy              dw  ?
    id              dw  ?
ends

struc MOUSEINPUT
    _dx         dd    ?
    dy          dd    ?
    mouseData   dd    ?
    dwFlags     dd    ?
    time        dd    ?
    dwExtraInfo xword ?
ends

struc KEYBDINPUT
    wVk         dw    ?
    wScan       dw    ?
    dwFlags     dd    ?
    time        dd    ?
    dwExtraInfo xword ?
ends

struc HARDWAREINPUT
    uMsg    dd  ?
    wParamL dw  ?
    wParamH dw  ?
ends

struc INPUT
    _type  dd  ?
    union
        mi rs MOUSEINPUT,1
        ki rs KEYBDINPUT,1
        hi rs HARDWAREINPUT,1
    endu
ends

struc LASTINPUTINFO
    cbSize dd ?
    dwTime dd ?
ends

struc TPMPARAMS
    cbSize    dd ?
    rcExclude rs RECT,1
ends

struc MENUINFO
    cbSize          dd    ?
    fMask           dd    ?
    dwStyle         dd    ?
    cyMax           dd    ?
    hbrBack         xword ?
    dwContextHelpID dd    ?
    dwMenuData      xword ?
ends

struc MENUGETOBJECTINFO
    dwFlags dd    ?
    uPos    dd    ?
    hmenu   xword ?
    riid    xword ?
    pvObj   xword ?
ends

struc MENUITEMINFOA
    cbSize          dd    ?
    fMask           dd    ?
    fType           dd    ?
    fState          dd    ?
    wID             dd    ?
                    dd    ? ;Padding
    hSubMenu        xword ?
    hbmpChecked     xword ?
    hbmpUnchecked   xword ?
    dwItemData      xword ?
    dwTypeData      xword ?
    cch             dd    ?
                    dd    ? ;Padding
    hbmpItem        xword ?
ends

struc MENUITEMINFOW
    cbSize          dd    ?
    fMask           dd    ?
    fType           dd    ?
    fState          dd    ?
    wID             dd    ?
                    dd    ? ;Padding
    hSubMenu        xword ?
    hbmpChecked     xword ?
    hbmpUnchecked   xword ?
    dwItemData      xword ?
    dwTypeData      xword ?
    cch             dd    ?
                    dd    ? ;Padding
    hbmpItem        xword ?
ends

struc DROPSTRUCT
    hwndSource      xword ?
    hwndSink        xword ?
    wFmt            dd    ?
    dwData          xword ?
    ptDrop          rs    POINT,1
    dwControlData   dd    ?
ends

struc DRAWTEXTPARAMS
    cbSize        dd ?
    iTabLength    dd ?
    iLeftMargin   dd ?
    iRightMargin  dd ?
    uiLengthDrawn dd ?
ends

struc HELPINFO
    cbSize       dd    ?
    iContextType dd    ?
    iCtrlId      dd    ?
    hItemHandle  xword ?
    dwContextId  dd    ?
    MousePos     rs    POINT,1
ends

struc MSGBOXPARAMSA
    cbSize              dd    ?
    hwndOwner           xword ?
    hInstance           xword ?
    lpszText            xword ?
    lpszCaption         xword ?
    dwStyle             dd    ?
    lpszIcon            xword ?
    dwContextHelpId     xword ?
    lpfnMsgBoxCallback  xword ?
    dwLanguageId        dd    ?
ends

struc MSGBOXPARAMSW
    cbSize              dd    ?
    hwndOwner           xword ?
    hInstance           xword ?
    lpszText            xword ?
    lpszCaption         xword ?
    dwStyle             dd    ?
    lpszIcon            xword ?
    dwContextHelpId     xword ?
    lpfnMsgBoxCallback  xword ?
    dwLanguageId        dd    ?
ends

struc MENUITEMTEMPLATEHEADER
    versionNumber dw ?
    _offset       dw ?
ends

struc MENUITEMTEMPLATE
    mtOption dw ? 
    mtID     dw ?
    mtString dw ?
ends

struc ICONINFO
    fIcon    dd    ?
    xHotspot dd    ?
    yHotspot dd    ?
    hbmMask  xword ?
    hbmColor xword ?
ends

struc CURSORSHAPE
    xHotSpot  dd  ?
    yHotSpot  dd  ?
    _cx       dd  ?
    cy        dd  ?
    cbWidth   dd  ?
    Planes    db  ?
    BitsPixel db  ?
ends

struc SCROLLINFO
    cbSize    dd ?
    fMask     dd ?
    nMin      dd ?
    nMax      dd ?
    nPage     dd ?
    nPos      dd ?
    nTrackPos dd ?
ends

struc MDICREATESTRUCTA
    szClass xword ?
    szTitle xword ?
    hOwner  xword ?
    x       dd    ?
    y       dd    ?
    _cx     dd    ?
    cy      dd    ?
    style   dd    ?
    lParam  xword ?
ends

struc MDICREATESTRUCTW
    szClass xword ?
    szTitle xword ?
    hOwner  xword ?
    x       dd    ?
    y       dd    ?
    _cx     dd    ?
    cy      dd    ?
    style   dd    ?
    lParam  xword ?
ends

struc CLIENTCREATESTRUCT
    hWindowMenu  xword ?
    idFirstChild dd    ?
ends

struc MULTIKEYHELPA
    mkSize      dd ?
    mkKeylist   db ?
    szKeyphrase db ?
ends

struc MULTIKEYHELPW
    mkSize      dd ?
    mkKeylist   dw ?
    szKeyphrase dw ?
ends

struc HELPWININFOA
    wStructSize dd ?
    x           dd ?
    y           dd ?
    _dx         dd ?
    dy          dd ?
    wMax        dd ?
    rgchMember  rb 2
ends

struc HELPWININFOW
    wStructSize dd ?
    x           dd ?
    y           dd ?
    _dx         dd ?
    dy          dd ?
    wMax        dd ?
    rgchMember  rw 2
ends

struc NONCLIENTMETRICSA
    cbSize           dd       ?
    iBorderWidth     dd       ?
    iScrollWidth     dd       ?
    iScrollHeight    dd       ?
    iCaptionWidth    dd       ?
    iCaptionHeight   dd       ?
    lfCaptionFont    rs       LOGFONTA,1
    iSmCaptionWidth  dd       ?
    iSmCaptionHeight dd       ?
    lfSmCaptionFont  rs       LOGFONTA,1
    iMenuWidth       dd       ?
    iMenuHeight      dd       ?
    lfMenuFont       rs       LOGFONTA,1
    lfStatusFont     rs       LOGFONTA,1
    lfMessageFont    rs       LOGFONTA,1
    #if NTDDI_VERSION >= NTDDI_VISTA
        iPaddedBorderWidth dd ?
    #endif
ends

struc NONCLIENTMETRICSW
    cbSize           dd       ?
    iBorderWidth     dd       ?
    iScrollWidth     dd       ?
    iScrollHeight    dd       ?
    iCaptionWidth    dd       ?
    iCaptionHeight   dd       ?
    lfCaptionFont    rs       LOGFONTW,1
    iSmCaptionWidth  dd       ?
    iSmCaptionHeight dd       ?
    lfSmCaptionFont  rs       LOGFONTW,1
    iMenuWidth       dd       ?
    iMenuHeight      dd       ?
    lfMenuFont       rs       LOGFONTW,1
    lfStatusFont     rs       LOGFONTW,1
    lfMessageFont    rs       LOGFONTW,1
    #if NTDDI_VERSION >= NTDDI_VISTA
        iPaddedBorderWidth dd ?
    #endif
ends

struc MINIMIZEDMETRICS
    cbSize   dd ?
    iWidth   dd ?
    iHorzGap dd ?
    iVertGap dd ?
    iArrange dd ?
ends

struc ICONMETRICSA
    cbSize       dd ?
    iHorzSpacing dd ?
    iVertSpacing dd ?
    iTitleWrap   dd ?
    lfFont       rs LOGFONTA,1
ends

struc ICONMETRICSW
    cbSize       dd ?
    iHorzSpacing dd ?
    iVertSpacing dd ?
    iTitleWrap   dd ?
    lfFont       rs LOGFONTW,1
ends

struc ANIMATIONINFO
    cbSize      dd ?
    iMinAnimate dd ?
ends

struc SERIALKEYSA
    cbSize          dd    ?
    dwFlags         dd    ?
    lpszActivePort  xword ?
    lpszPort        xword ?
    iBaudRate       dd    ?
    iPortState      dd    ?
    iActive         dd    ?
ends

struc SERIALKEYSW
    cbSize          dd    ?
    dwFlags         dd    ?
    lpszActivePort  xword ?
    lpszPort        xword ?
    iBaudRate       dd    ?
    iPortState      dd    ?
    iActive         dd    ? 
ends

struc HIGHCONTRASTA
    cbSize            dd    ?
    dwFlags           dd    ?
    lpszDefaultScheme xword ?
ends

struc HIGHCONTRASTW
    cbSize            dd    ?
    dwFlags           dd    ?
    lpszDefaultScheme xword ?
ends

struc FILTERKEYS
    cbSize      dd ?
    dwFlags     dd ?
    iWaitMSec   dd ?
    iDelayMSec  dd ?
    iRepeatMSec dd ?
    iBounceMSec dd ?
ends

struc STICKYKEYS
    cbSize  dd ?
    dwFlags dd ?
ends

struc MOUSEKEYS
    cbSize          dd ?
    dwFlags         dd ?
    iMaxSpeed       dd ?
    iTimeToMaxSpeed dd ?
    iCtrlSpeed      dd ?
    dwReserved1     dd ?
    dwReserved2     dd ?
ends

struc TOGGLEKEYS
    cbSize  dd ?
    dwFlags dd ?
ends

struc ACCESSTIMEOUT
    cbSize       dd ?
    dwFlags      dd ?
    iTimeOutMSec dd ?
ends

struc SOUNDSENTRYA
    cbSize                  dd    ?
    dwFlags                 dd    ?
    iFSTextEffect           dd    ?
    iFSTextEffectMSec       dd    ?
    iFSTextEffectColorBits  dd    ?
    iFSGrafEffect           dd    ?
    iFSGrafEffectMSec       dd    ?
    iFSGrafEffectColor      dd    ?
    iWindowsEffect          dd    ?
    iWindowsEffectMSec      dd    ?
    lpszWindowsEffectDLL    xword ?
    iWindowsEffectOrdinal   dd    ?
ends

struc SOUNDSENTRYW
    cbSize                  dd    ?
    dwFlags                 dd    ?
    iFSTextEffect           dd    ?
    iFSTextEffectMSec       dd    ?
    iFSTextEffectColorBits  dd    ?
    iFSGrafEffect           dd    ?
    iFSGrafEffectMSec       dd    ?
    iFSGrafEffectColor      dd    ?
    iWindowsEffect          dd    ?
    iWindowsEffectMSec      dd    ?
    lpszWindowsEffectDLL    xword ?
    iWindowsEffectOrdinal   dd    ?
ends

struc MONITORINFO
    cbSize      dd ?
    rcMonitor   rs RECT,1
    rcWork      rs RECT,1
    dwFlags     dd ?
ends

struc MONITORINFOEXA
    cbSize      dd ?
    rcMonitor   rs RECT,1
    rcWork      rs RECT,1
    dwFlags     dd ?
    szDevice    rb CCHDEVICENAME
ends

struc MONITORINFOEXW
    cbSize      dd ?
    rcMonitor   rs RECT,1
    rcWork      rs RECT,1
    dwFlags     dd ?
    szDevice    rw CCHDEVICENAME
ends

struc GUITHREADINFO
    cbSize          dd    ?
    flags           dd    ?
    hwndActive      xword ?
    hwndFocus       xword ?
    hwndCapture     xword ?
    hwndMenuOwner   xword ?
    hwndMoveSize    xword ?
    hwndCaret       xword ?
    rcCaret         rs    RECT,1
ends

struc CURSORINFO
    cbSize      dd    ?
    flags       dd    ?
    hCursor     xword ?
    ptScreenPos rs    POINT,1
ends

struc WINDOWINFO
    cbSize          dd ?
    rcWindow        rs RECT,1
    rcClient        rs RECT,1
    dwStyle         dd ?
    dwExStyle       dd ?
    dwOtherStuff    dd ?
    cxWindowBorders dd ?
    cyWindowBorders dd ?
    atomWindowType  dw ?
    wCreatorVersion dw ?
ends

struc TITLEBARINFO
    cbSize      dd ?
    rcTitleBar  rs RECT,1
    rgstate     rd (CCHILDREN_TITLEBAR+1)
ends

struc TITLEBARINFOEX
    cbSize      dd ?
    rcTitleBar  rs RECT,1
    rgstate     rd (CCHILDREN_TITLEBAR+1)
    rgrect      rs RECT,(CCHILDREN_TITLEBAR+1)
ends

struc MENUBARINFO
    cbSize      dd    ?
    rcBar       rs    RECT,1
    hMenu       xword ?
    hwndMenu    xword ?
    fBarFocused dd    ?
    fFocused    dd    ?
ends

struc SCROLLBARINFO
    cbSize        dd ?
    rcScrollBar   rs RECT,1
    dxyLineButton dd ?
    xyThumbTop    dd ?
    xyThumbBottom dd ?
    bogus         dd ?
    rgstate       dd (CCHILDREN_SCROLLBAR+1)
ends

struc COMBOBOXINFO
    cbSize      dd    ?
    rcItem      rs    RECT,1
    rcButton    rs    RECT,1
    stateButton dd    ?
    hwndCombo   xword ?
    hwndItem    xword ?
    hwndList    xword ?
ends

struc ALTTABINFO
    cbSize    dd ?
    cItems    dd ?
    cColumns  dd ?
    cRows     dd ?
    iColFocus dd ?
    iRowFocus dd ?
    cxItem    dd ?
    cyItem    dd ?
    ptStart   rs POINT,1
ends

struc TOUCHINPUT
    x           dd    ?
    y           dd    ?
    hSource     xword ?
    dwID        dd    ?
    dwFlags     dd    ?
    dwMask      dd    ?
    dwTime      dd    ?
    dwExtraInfo xword ?
    cxContact   dd    ?
    cyContact   dd    ?
ends

struc POINTER_INFO
    pointerType            xword ?
    pointerId              dd    ?
    frameId                dd    ?
    pointerFlags           xword ?
    sourceDevice           xword ?
    hwndTarget             xword ?
    ptPixelLocation        rs    POINT,1
    ptHimetricLocation     rs    POINT,1
    ptPixelLocationRaw     rs    POINT,1
    ptHimetricLocationRaw  rs    POINT,1
    dwTime                 dd    ?
    historyCount           dd    ?
    InputData              dd    ?
    dwKeyStates            dd    ?
    PerformanceCount       dq    ?
    ButtonChangeType       xword ?
ends

struc POINTER_TOUCH_INFO
    pointerInfo  rs    POINTER_INFO,1
    touchFlags   xword ?
    touchMask    xword ?
    rcContact    rs    RECT,1
    rcContactRaw rs    RECT,1
    orientation  dd    ?
    pressure     dd    ?
ends

struc POINTER_PEN_INFO
    pointerInfo rs    POINTER_INFO,1
    penFlags    xword ?
    penMask     xword ?
    pressure    dd    ?
    rotation    dd    ?
    tiltX       dd    ?
    tiltY       dd    ?
ends

struc TOUCH_HIT_TESTING_PROXIMITY_EVALUATION
    score         dw ?
    adjustedPoint rs POINT,1
ends

struc TOUCH_HIT_TESTING_INPUT
    pointerId               dd ?
    point                   rs POINT,1
    boundingBox             rs RECT,1
    nonOccludedBoundingBox  rs RECT,1
    orientation             dd ?
ends

struc CHANGEFILTERSTRUCT
    cbSize    dd  ?
    ExtStatus dd  ?
ends

struc GESTUREINFO
    cbSize       dd    ?
    dwFlags      dd    ?
    dwID         dd    ?
    hwndTarget   xword ?
    ptsLocation  rs    POINTS,1
    dwInstanceID dd    ?
    dwSequenceID dd    ?
    ullArguments xword ?
    cbExtraArgs  dd    ?
ends

struc GESTURENOTIFYSTRUCT
    cbSize       dd     ?
    dwFlags      dd     ?
    hwndTarget   xword  ?
    ptsLocation  POINTS ?
    dwInstanceID dd     ?
ends

struc GESTURECONFIG
    dwID    dd  ?
    dwWant  dd  ?
    dwBlock dd  ?
ends

;======================================== vfw32 =======================================;
struct ICOPEN
    dwSize      dd    ?
    fccType     dd    ?
    fccHandler  dd    ?
    dwVersion   dd    ?
    dwFlags     dd    ?
    dwError     dd    ?
    pV1Reserved xword ?
    pV2Reserved xword ?
    dnDevNode   dd    ?
ends

struct ICINFO
    dwSize        dd ?
    fccType       dd ?
    fccHandler    dd ?
    dwFlags       dd ?
    dwVersion     dd ?
    dwVersionICM  dd ?
    szName        rw 16
    szDescription rw 128
    szDriver      rw 128
ends

struct ICCOMPRESS
    dwFlags     dd    ?
    lpbiOutput  xword ?
    lpOutput    xword ?
    lpbiInput   xword ?
    lpInput     xword ?
    lpckid      xword ?
    lpdwFlags   xword ?
    lFrameNum   dd    ?
    dwFrameSize dd    ?
    dwQuality   dd    ?
    lpbiPrev    xword ?
    lpPrev      xword ?
ends

struct ICCOMPRESSFRAMES
    dwFlags            dd    ?
    lpbiOutput         xword ?
    lOutput            xword ?
    lpbiInput          xword ?
    lInput             xword ?
    lStartFrame        dd    ?
    lFrameCount        dd    ?
    lQuality           dd    ?
    lDataRate          dd    ?
    lKeyRate           dd    ?
    dwRate             dd    ?
    dwScale            dd    ?
    dwOverheadPerFrame dd    ?
    dwReserved2        dd    ?
    GetData            xword ?
    PutData            xword ?
ends

struct ICSETSTATUSPROC
    dwFlags    dd    ?
    lParam     xword ?
    fpfnStatus xword ?
ends

struct ICDECOMPRESS
    dwFlags    dd    ?
    lpbiInput  xword ?
    lpInput    xword ?
    lpbiOutput xword ?
    lpOutput   xword ?
    ckid       dd    ?
ends

struct ICDECOMPRESSEX
    dwFlags dd    ?
    lpbiSrc xword ?
    lpSrc   xword ?
    lpbiDst xword ?
    lpDst   xword ?
    xDst    dd    ?
    yDst    dd    ?
    dxDst   dd    ?
    dyDst   dd    ?
    xSrc    dd    ?
    ySrc    dd    ?
    dxSrc   dd    ?
    dySrc   dd    ?
ends

struct ICDRAWBEGIN
    dwFlags dd    ?
    hpal    xword ?
    hwnd    xword ?
    hdc     xword ?
    xDst    dd    ?
    yDst    dd    ?
    dxDst   dd    ?
    dyDst   dd    ?
    lpbi    xword ?
    xSrc    dd    ?
    ySrc    dd    ?
    dxSrc   dd    ?
    dySrc   dd    ?
    dwRate  dd    ?
    dwScale dd    ?
ends

struct ICDRAW
    dwFlags  dd    ?
    lpFormat xword ?
    lpData   xword ?
    cbData   dd    ?
    lTime    dd    ?
ends

struct ICDRAWSUGGEST
    lpbiIn          xword ?
    lpbiSuggest     xword ?
    dxSrc           dd    ?
    dySrc           dd    ?
    dxDst           dd    ?
    dyDst           dd    ?
    hicDecompressor xword ?
ends

struct ICPALETTE
    dwFlags dd    ?
    iStart  dd    ?
    iLen    dd    ?
    lppe    xword ?
ends

struct COMPVARS
    cbSize     dd    ?
    dwFlags    dd    ?
    hic        xword ?
    fccType    dd    ?
    fccHandler dd    ?
    lpbiIn     xword ?
    lpbiOut    xword ?
    lpBitsOut  xword ?
    lpBitsPrev xword ?
    lFrame     dd    ?
    lKey       dd    ?
    lDataRate  dd    ?
    lQ         dd    ?
    lKeyCount  dd    ?
    lpState    xword ?
    cbState    dd    ?
ends

struct DRAWDIBTIME
    timeCount      dd ?
    timeDraw       dd ?
    timeDecompress dd ?
    timeDither     dd ?
    timeStretch    dd ?
    timeBlt        dd ?
    timeSetDIBits  dd ?
ends

struct MainAVIHeader
    dwMicroSecPerFrame    dd ?
    dwMaxBytesPerSec      dd ?
    dwPaddingGranularity  dd ?
    dwFlags               dd ?
    dwTotalFrames         dd ?
    dwInitialFrames       dd ?
    dwStreams             dd ?
    dwSuggestedBufferSize dd ?
    dwWidth               dd ?
    dwHeight              dd ?
    dwReserved            rd 4
ends

struct AVIStreamHeader
    fccType               dd ?
    fccHandler            dd ?
    dwFlags               dd ?
    wPriority             dw ?
    wLanguage             dw ?
    dwInitialFrames       dd ?
    dwScale               dd ?
    dwRate                dd ?
    dwStart               dd ?
    dwLength              dd ?
    dwSuggestedBufferSize dd ?
    dwQuality             dd ?
    dwSampleSize          dd ?
    rcFrame               rs RECT,1
ends

struct AVIINDEXENTRY
    ckid          dd ?
    dwFlags       dd ?
    dwChunkOffset dd ?
    dwChunkLength dd ?
ends

struct AVIPALCHANGE
    bFirstEntry db ?
    bNumEntries db ?
    wFlags      dw ?
    peNew       rs PALETTEENTRY,1
ends

struct AVISTREAMINFOA
    fccType               dd ?
    fccHandler            dd ?
    dwFlags               dd ?
    dwCaps                dd ?
    wPriority             dw ?
    wLanguage             dw ?
    dwScale               dd ?
    dwRate                dd ?
    dwStart               dd ?
    dwLength              dd ?
    dwInitialFrames       dd ?
    dwSuggestedBufferSize dd ?
    dwQuality             dd ?
    dwSampleSize          dd ?
    rcFrame               rs RECT,1
    dwEditCount           dd ?
    dwFormatChangeCount   dd ?
    szName                rb 64
ends

struct AVISTREAMINFOW
    fccType               dd ?
    fccHandler            dd ?
    dwFlags               dd ?
    dwCaps                dd ?
    wPriority             dw ?
    wLanguage             dw ?
    dwScale               dd ?
    dwRate                dd ?
    dwStart               dd ?
    dwLength              dd ?
    dwInitialFrames       dd ?
    dwSuggestedBufferSize dd ?
    dwQuality             dd ?
    dwSampleSize          dd ?
    rcFrame               rs RECT,1
    dwEditCount           dd ?
    dwFormatChangeCount   dd ?
    szName                rw 64
ends

struct AVIFILEINFOA
    dwMaxBytesPerSec      dd ?
    dwFlags               dd ?
    dwCaps                dd ?
    dwStreams             dd ?
    dwSuggestedBufferSize dd ?
    dwWidth               dd ?
    dwHeight              dd ?
    dwScale               dd ?
    dwRate                dd ?
    dwLength              dd ?
    dwEditCount           dd ?
    szFileType            rb 64
ends

struct AVIFILEINFOW
    dwMaxBytesPerSec      dd ?
    dwFlags               dd ?
    dwCaps                dd ?
    dwStreams             dd ?
    dwSuggestedBufferSize dd ?
    dwWidth               dd ?
    dwHeight              dd ?
    dwScale               dd ?
    dwRate                dd ?
    dwLength              dd ?
    dwEditCount           dd ?
    szFileType            rw 64
ends

struct AVICOMPRESSOPTIONS
    fccType           dd    ?
    fccHandler        dd    ?
    dwKeyFrameEvery   dd    ?
    dwQuality         dd    ?
    dwBytesPerSecond  dd    ?
    dwFlags           dd    ?
    lpFormat          xword ?
    cbFormat          dd    ?
    lpParms           xword ?
    cbParms           dd    ?
    dwInterleaveEvery dd    ?
ends

struct IAVIStream
;    union
;        struct
;            QueryInterface  xword   ?
;            AddRef          xword   ?
;            Release         xword   ?
;        ends
        IUnknown            rs Unknown,1
;    ends
    Create                  xword   ?
    Info                    xword   ?
    FindSample              xword   ?
    ReadFormat              xword   ?
    SetFormat               xword   ?
    Read                    xword   ?
    Write                   xword   ?
    Delete                  xword   ?
    ReadData                xword   ?
    WriteData               xword   ?
    SetInfo                 xword   ?
ends

struct IAVIStreaming
;    union
;        struct
;            QueryInterface      xword   ?
;            AddRef              xword   ?
;            Release             xword   ?
;        ends
        IUnknown                rs Unknown,1
;    ends
    Begin                       xword   ?
    _End                        xword   ?
ends

struct IAVIEditStream
;    union
;        struct
;            QueryInterface      xword   ?
;            AddRef              xword   ?
;            Release             xword   ?
;        ends
        IUnknown                rs Unknown,1
;    ends
    Cut                         xword   ?
    Copy                        xword   ?
    Paste                       xword   ?
    Clone                       xword   ?
    SetInfo                     xword   ?
ends

struct IAVIFile
;    union
;        struct
;            QueryInterface      xword   ?
;            AddRef              xword   ?
;            Release             xword   ?
;        ends
        IUnknown                rs Unknown,1
;    ends
    Info                        xword   ?
    GetStream                   xword   ?
    CreateStream                xword   ?
    WriteData                   xword   ?
    ReadData                    xword   ?
    EndRecord                   xword   ?
    DeleteStream                xword   ?
ends

struct IGetFrame
;    union
;        struct
;            QueryInterface      xword   ?
;            AddRef              xword   ?
;            Release             xword   ?
;        ends
        IUnknown                rs Unknown,1
;    ends
    GetFrame                    xword   ?
    Begin                       xword   ?
    _End                        xword   ?
    SetFormat                   xword   ?
ends

struct VIDEOHDR
    lpData         xword ?
    dwBufferLength dd    ?
    dwBytesUsed    dd    ?
    dwTimeCaptured dd    ?
    dwUser         dd    ?
    dwFlags        dd    ?
    dwReserved     db    4*xword_size
ends

struct CHANNEL_CAPS
    dwFlags            dd ?
    dwSrcRectXMod      dd ?
    dwSrcRectYMod      dd ?
    dwSrcRectWidthMod  dd ?
    dwSrcRectHeightMod dd ?
    dwDstRectXMod      dd ?
    dwDstRectYMod      dd ?
    dwDstRectWidthMod  dd ?
    dwDstRectHeightMod dd ?
ends

struct CAPDRIVERCAPS
    wDeviceIndex            dd    ?
    fHasOverlay             dd    ?
    fHasDlgVideoSource      dd    ?
    fHasDlgVideoFormat      dd    ?
    fHasDlgVideoDisplay     dd    ?
    fCaptureInitialized     dd    ?
    fDriverSuppliesPalettes dd    ?
    hVideoIn                xword ?
    hVideoOut               xword ?
    hVideoExtIn             xword ?
    hVideoExtOut            xword ?
ends

struct CAPSTATUS
    uiImageWidth                dd    ?
    uiImageHeight               dd    ?
    fLiveWindow                 dd    ?
    fOverlayWindow              dd    ?
    _fScale                     dd    ?
    ptScroll                    rs POINT,1
    fUsingDefaultPalette        dd    ?
    fAudioHardware              dd    ?
    fCapFileExists              dd    ?
    dwCurrentVideoFrame         dd    ?
    dwCurrentVideoFramesDropped dd    ?
    dwCurrentWaveSamples        dd    ?
    dwCurrentTimeElapsedMS      dd    ?
    hPalCurrent                 xword ?
    fCapturingNow               dd    ?
    dwReturn                    dd    ?
    wNumVideoAllocated          dd    ?
    wNumAudioAllocated          dd    ?
ends

struct CAPTUREPARMS
    dwRequestMicroSecPerFrame dd ?
    fMakeUserHitOKToCapture   dd ?
    wPercentDropForError      dd ?
    fYield                    dd ?
    dwIndexSize               dd ?
    wChunkGranularity         dd ?
    fUsingDOSMemory           dd ?
    wNumVideoRequested        dd ?
    fCaptureAudio             dd ?
    wNumAudioRequested        dd ?
    vKeyAbort                 dd ?
    fAbortLeftMouse           dd ?
    fAbortRightMouse          dd ?
    fLimitEnabled             dd ?
    wTimeLimit                dd ?
    fMCIControl               dd ?
    fStepMCIDevice            dd ?
    dwMCIStartTime            dd ?
    dwMCIStopTime             dd ?
    fStepCaptureAt2x          dd ?
    wStepCaptureAverageFrames dd ?
    dwAudioBufferSize         dd ?
    fDisableWriteCache        dd ?
    AVStreamMaster            dd ?
ends

struct CAPINFOCHUNK
    fccInfoID dd    ?
    lpData    xword ?
    cbData    dd    ?
ends

;======================================== winmm =======================================;
struc s
    dwMinimum dd ?
    dwMaximum dd ?
ends

struc MIXERCONTROLA
    cbStruct          dd ?
    dwControlID       dd ?
    dwControlType     dd ?
    fdwControl        dd ?
    cMultipleItems    dd ?
    szShortName       rb MIXER_SHORT_NAME_CHARS
    szName            rb MIXER_LONG_NAME_CHARS
    s                    ?
    union
        cSteps        dd ?
        cbCustomData  dd ?
        _dwReserved   rd 6
    endu
ends

struc MIXERCONTROLW
    cbStruct          dd ?
    dwControlID       dd ?
    dwControlType     dd ?
    fdwControl        dd ?
    cMultipleItems    dd ?
    szShortName       rw MIXER_SHORT_NAME_CHARS
    szName            rw MIXER_LONG_NAME_CHARS
    s                    ?
    union
        cSteps        dd ?
        cbCustomData  dd ?
        _dwReserved   rd 6
    endu
ends

struc SMPTE
    hour   db ?
    min    db ?
    sec    db ?
    _frame db ?
    fps    db ?
    dummy  db ?
    pad    rb 2
ends

struc MMTIME
    wType          dd ?
    union
        ms         dd ?
        sample     dd ?
        cb         dd ?
        ticks      dd ?
        smpte      SMPTE ?
        songptrpos dd ?
    endu
ends

struc DRVCONFIGINFOEX
    dwDCISize          dd   ?
    lpszDCISectionName xword ?
    lpszDCIAliasName   xword ?
    dnDevNode          dd   ?
ends

struc WAVEHDR
    lpData          xword ?
    dwBufferLength  dd ?
    dwBytesRecorded dd ?
    dwUser          xword ?
    dwFlags         dd ?
    dwLoops         dd ?
    lpNext          xword ?
    reserved        dd ?
ends

struc WAVEOUTCAPSA
    wMid           dw ?
    wPid           dw ?
    vDriverVersion dd ?
    szPname        rb MAXPNAMELEN
    dwFormats      dd ?
    wChannels      dw ?
    wReserved1     dw ?
    dwSupport      dd ?
ends

struc WAVEOUTCAPSW
    wMid           dw ?
    wPid           dw ?
    vDriverVersion dd ?
    szPname        rw MAXPNAMELEN
    dwFormats      dd ?
    wChannels      dw ?
    wReserved1     dw ?
    dwSupport      dd ?
ends

struc WAVEOUTCAPS2A
    wMid             dw ?
    wPid             dw ?
    vDriverVersion   dd ?
    szPname          rb MAXPNAMELEN
    dwFormats        dd ?
    wChannels        dw ?
    wReserved1       dw ?
    dwSupport        dd ?
    ManufacturerGuid GUID ?
    ProductGuid      GUID ?
    NameGuid         GUID ?
ends

struc WAVEOUTCAPS2W
    wMid             dw ?
    wPid             dw ?
    vDriverVersion   dd ?
    szPname          rw MAXPNAMELEN
    dwFormats        dd ?
    wChannels        dw ?
    wReserved1       dw ?
    dwSupport        dd ?
    ManufacturerGuid GUID ?
    ProductGuid      GUID ?
    NameGuid         GUID ?
ends

struc WAVEINCAPSA
    wMid           dw ?
    wPid           dw ?
    vDriverVersion dd ?
    szPname        rb MAXPNAMELEN
    dwFormats      dd ?
    wChannels      dw ?
    wReserved1     dw ?
ends

struc WAVEINCAPSW
    wMid           dw ?
    wPid           dw ?
    vDriverVersion dd ?
    szPname        rw MAXPNAMELEN
    dwFormats      dd ?
    wChannels      dw ?
    wReserved1     dw ?
ends

struc WAVEINCAPS2A
    wMid             dw ?
    wPid             dw ?
    vDriverVersion   dd ?
    szPname          rb MAXPNAMELEN
    dwFormats        dd ?
    wChannels        dw ?
    wReserved1       dw ?
    ManufacturerGuid GUID ?
    ProductGuid      GUID ?
    NameGuid         GUID ?
ends

struc WAVEINCAPS2W
    wMid             dw ?
    wPid             dw ?
    vDriverVersion   dd ?
    szPname          rw MAXPNAMELEN
    dwFormats        dd ?
    wChannels        dw ?
    wReserved1       dw ?
    ManufacturerGuid GUID ?
    ProductGuid      GUID ?
    NameGuid         GUID ?
ends

struc WAVEFORMAT
    wFormatTag      dw  ?
    nChannels       dw  ?
    nSamplesPerSec  dd  ?
    nAvgBytesPerSec dd  ?
    nBlockAlign     dw  ?
ends
    
struc PCMWAVEFORMAT
    wf              WAVEFORMAT ?
    wBitsPerSample  dw  ?
ends

struc WAVEFORMATEX
    wFormatTag      dw  ?
    nChannels       dw  ?
    nSamplesPerSec  dd  ?
    nAvgBytesPerSec dd  ?
    nBlockAlign     dw  ?
    wBitsPerSample  dw  ?
    cbSize          dw  ?
ends

struc MIDIOUTCAPSA
    wMid           dw ?
    wPid           dw ?
    vDriverVersion dd ?
    szPname        rb MAXPNAMELEN
    wTechnology    dw ?
    wVoices        dw ?
    wNotes         dw ?
    wChannelMask   dw ?
    dwSupport      dd ?
ends

struc MIDIOUTCAPSW
    wMid           dw ?
    wPid           dw ?
    vDriverVersion dd ?
    szPname        rw MAXPNAMELEN
    wTechnology    dw ?
    wVoices        dw ?
    wNotes         dw ?
    wChannelMask   dw ?
    dwSupport      dd ?
ends

struc MIDIOUTCAPS2A
    wMid             dw ?
    wPid             dw ?
    vDriverVersion   dd ?
    szPname          rb MAXPNAMELEN
    wTechnology      dw ?
    wVoices          dw ?
    wNotes           dw ?
    wChannelMask     dw ?
    dwSupport        dd ?
    ManufacturerGuid GUID ?
    ProductGuid      GUID ?
    NameGuid         GUID ?
ends

struc MIDIOUTCAPS2W
    wMid             dw ?
    wPid             dw ?
    vDriverVersion   dd ?
    szPname          rw MAXPNAMELEN
    wTechnology      dw ?
    wVoices          dw ?
    wNotes           dw ?
    wChannelMask     dw ?
    dwSupport        dd ?
    ManufacturerGuid GUID ?
    ProductGuid      GUID ?
    NameGuid         GUID ?
ends

struc MIDIINCAPSA
    wMid           dw ?
    wPid           dw ?
    vDriverVersion dd ?
    szPname        rb MAXPNAMELEN
    dwSupport      dd ?
ends

struc MIDIINCAPSW
    wMid           dw ?
    wPid           dw ?
    vDriverVersion dd ?
    szPname        rw MAXPNAMELEN
    dwSupport      dd ?
ends

struc MIDIINCAPS2A
    wMid             dw ?
    wPid             dw ?
    vDriverVersion   dd ?
    szPname          rb MAXPNAMELEN
    dwSupport        dd ?
    ManufacturerGuid GUID ?
    ProductGuid      GUID ?
    NameGuid         GUID ?
ends

struc MIDIINCAPS2W
    wMid             dw ?
    wPid             dw ?
    vDriverVersion   dd ?
    szPname          rw MAXPNAMELEN
    dwSupport        dd ?
    ManufacturerGuid GUID ?
    ProductGuid      GUID ?
    NameGuid         GUID ?
ends

struc MIDIHDR
    lpData          xword ?
    dwBufferLength  dd ?
    dwBytesRecorded dd ?
    dwUser          xword ?
    dwFlags         dd ?
    lpNext          dd ?
    reserved        xword ?
    dwOffset        dd ?
    dwReserved      db 8*xword_size
ends

struc MIDIEVENT
    dwDeltaTime     dd ?
    dwStreamID      dd ?
    dwEvent         dd ?
    dwParms         dd ?
ends

struc MIDISTRMBUFFVER
    dwVersion       dd ?
    dwMid           dd ?
    dwOEMVersion    dd ?
ends

struc MIDIPROPTIMEDIV
    cbStruct        dd ?
    dwTimeDiv       dd ?
ends

struc MIDIPROPTEMPO
    cbStruct        dd ?
    dwTempo         dd ?
ends

struc AUXCAPSA
    wMid           dw ?
    wPid           dw ?
    vDriverVersion dd ?
    szPname        rb MAXPNAMELEN
    wTechnology    dw ?
    wReserved1     dw ?
    dwSupport      dd ?
ends

struc AUXCAPSW
    wMid           dw ?
    wPid           dw ?
    vDriverVersion dd ?
    szPname        rw MAXPNAMELEN
    wTechnology    dw ?
    wReserved1     dw ?
    dwSupport      dd ?
ends

struc AUXCAPS2A
    wMid             dw ?
    wPid             dw ?
    vDriverVersion   dd ?
    szPname          rb MAXPNAMELEN
    wTechnology      dw ?
    wReserved1       dw ?
    dwSupport        dd ?
    ManufacturerGuid GUID ?
    ProductGuid      GUID ?
    NameGuid         GUID ?
ends

struc AUXCAPS2W
    wMid             dw ?
    wPid             dw ?
    vDriverVersion   dd ?
    szPname          rw MAXPNAMELEN
    wTechnology      dw ?
    wReserved1       dw ?
    dwSupport        dd ?
    ManufacturerGuid GUID ?
    ProductGuid      GUID ?
    NameGuid         GUID ?
ends

struc MIXERCAPSA
    wMid           dw ?
    wPid           dw ?
    vDriverVersion dd ?
    szPname        rb MAXPNAMELEN
    fdwSupport     dd ?
    cDestinations  dd ?
ends

struc MIXERCAPSW
    wMid           dw ?
    wPid           dw ?
    vDriverVersion dd ?
    szPname        rw MAXPNAMELEN
    fdwSupport     dd ?
    cDestinations  dd ?
ends

struc MIXERCAPS2A
    wMid             dw ?
    wPid             dw ?
    vDriverVersion   dd ?
    szPname          rb MAXPNAMELEN
    fdwSupport       dd ?
    cDestinations    dd ?
    ManufacturerGuid GUID ?
    ProductGuid      GUID ?
    NameGuid         GUID ?
ends

struc MIXERCAPS2W
    wMid             dw ?
    wPid             dw ?
    vDriverVersion   dd ?
    szPname          rw MAXPNAMELEN
    fdwSupport       dd ?
    cDestinations    dd ?
    ManufacturerGuid GUID ?
    ProductGuid      GUID ?
    NameGuid         GUID ?
ends

struc TARGETA
    dwType         dd ?
    dwDeviceID     dd ?
    wMid           dw ?
    wPid           dw ?
    vDriverVersion dd ?
    szPname        rb MAXPNAMELEN
ends

struc TARGETW
    dwType         dd ?
    dwDeviceID     dd ?
    wMid           dw ?
    wPid           dw ?
    vDriverVersion dd ?
    szPname        rw MAXPNAMELEN
ends

struc MIXERLINEA
    cbStruct        dd   ?
    dwDestination   dd   ?
    dwSource        dd   ?
    dwLineID        dd   ?
    fdwLine         dd   ?
    dwUser          xword ?
    dwComponentType dd   ?
    cChannels       dd   ?
    cConnections    dd   ?
    cControls       dd   ?
    szShortName     rb   MIXER_SHORT_NAME_CHARS
    szName          rb   MIXER_LONG_NAME_CHARS
    Target          TARGETA ?
ends

struc MIXERLINEW
    cbStruct        dd   ?
    dwDestination   dd   ?
    dwSource        dd   ?
    dwLineID        dd   ?
    fdwLine         dd   ?
    dwUser          xword ?
    dwComponentType dd   ?
    cChannels       dd   ?
    cConnections    dd   ?
    cControls       dd   ?
    szShortName     rw   MIXER_SHORT_NAME_CHARS
    szName          rw   MIXER_LONG_NAME_CHARS
    Target          TARGETW ?
ends

struc MIXERLINECONTROLSA
    cbStruct          dd ?
    dwLineID          dd ?
    union
        dwControlID   dd ?
        dwControlType dd ?
    endu
    cControls         dd ?
    cbmxctrl          dd ?
    pamxctrl          xword ?
ends

struc MIXERLINECONTROLSW
    cbStruct          dd ?
    dwLineID          dd ?
    union
        dwControlID   dd ?
        dwControlType dd ?
    endu
    cControls         dd ?
    cbmxctrl          dd ?
    pamxctrl          xword ?
ends

struc MIXERCONTROLDETAILS
    cbStruct           dd ?
    dwControlID        dd ?
    cChannels          dd ?
    union
        hwndOwner      xword ?
        cMultipleItems dd ?
    endu
    cbDetails          dd ?
    paDetails          xword ?
ends

struc MIXERCONTROLDETAILS_LISTTEXTA
    dwParam1           dd ?
    dwParam2           dd ?
    szName             rb MIXER_LONG_NAME_CHARS
ends

struc MIXERCONTROLDETAILS_LISTTEXTW
    dwParam1           dd ?
    dwParam2           dd ?
    szName             rw MIXER_LONG_NAME_CHARS
ends

struc MIXERCONTROLDETAILS_BOOLEAN
    fValue  dd ?
ends

struc MIXERCONTROLDETAILS_SIGNED
    lValue  dd ?
ends

struc MIXERCONTROLDETAILS_UNSIGNED
    dwValue dd ?
ends

struc TIMECAPS
    wPeriodMin dd ?
    wPeriodMax dd ?
ends

struc JOYCAPSA
    wMid        dw ?
    wPid        dw ?
    szPname     rb MAXPNAMELEN
    wXmin       dd ?
    wXmax       dd ?
    wYmin       dd ?
    wYmax       dd ?
    wZmin       dd ?
    wZmax       dd ?
    wNumButtons dd ?
    wPeriodMin  dd ?
    wPeriodMax  dd ?
    wRmin       dd ?
    wRmax       dd ?
    wUmin       dd ?
    wUmax       dd ?
    wVmin       dd ?
    wVmax       dd ?
    wCaps       dd ?
    wMaxAxes    dd ?
    wNumAxes    dd ?
    wMaxButtons dd ?
    szRegKey    rb MAXPNAMELEN
    szOEMVxD    rb MAX_JOYSTICKOEMVXDNAME
ends

struc JOYCAPSW
    wMid        dw ?
    wPid        dw ?
    szPname     rw MAXPNAMELEN
    wXmin       dd ?
    wXmax       dd ?
    wYmin       dd ?
    wYmax       dd ?
    wZmin       dd ?
    wZmax       dd ?
    wNumButtons dd ?
    wPeriodMin  dd ?
    wPeriodMax  dd ?
    wRmin       dd ?
    wRmax       dd ?
    wUmin       dd ?
    wUmax       dd ?
    wVmin       dd ?
    wVmax       dd ?
    wCaps       dd ?
    wMaxAxes    dd ?
    wNumAxes    dd ?
    wMaxButtons dd ?
    szRegKey    rw MAXPNAMELEN
    szOEMVxD    rw MAX_JOYSTICKOEMVXDNAME
ends

struc JOYCAPS2A
    wMid             dw ?
    wPid             dw ?
    szPname          rb MAXPNAMELEN
    wXmin            dd ?
    wXmax            dd ?
    wYmin            dd ?
    wYmax            dd ?
    wZmin            dd ?
    wZmax            dd ?
    wNumButtons      dd ?
    wPeriodMin       dd ?
    wPeriodMax       dd ?
    wRmin            dd ?
    wRmax            dd ?
    wUmin            dd ?
    wUmax            dd ?
    wVmin            dd ?
    wVmax            dd ?
    wCaps            dd ?
    wMaxAxes         dd ?
    wNumAxes         dd ?
    wMaxButtons      dd ?
    szRegKey         rb MAXPNAMELEN
    szOEMVxD         rb MAX_JOYSTICKOEMVXDNAME
    ManufacturerGuid GUID ?
    ProductGuid      GUID ?
    NameGuid         GUID ?
ends

struc JOYCAPS2W
    wMid             dw ?
    wPid             dw ?
    szPname          rw MAXPNAMELEN
    wXmin            dd ?
    wXmax            dd ?
    wYmin            dd ?
    wYmax            dd ?
    wZmin            dd ?
    wZmax            dd ?
    wNumButtons      dd ?
    wPeriodMin       dd ?
    wPeriodMax       dd ?
    wRmin            dd ?
    wRmax            dd ?
    wUmin            dd ?
    wUmax            dd ?
    wVmin            dd ?
    wVmax            dd ?
    wCaps            dd ?
    wMaxAxes         dd ?
    wNumAxes         dd ?
    wMaxButtons      dd ?
    szRegKey         rw MAXPNAMELEN
    szOEMVxD         rw MAX_JOYSTICKOEMVXDNAME
    ManufacturerGuid GUID ?
    ProductGuid      GUID ?
    NameGuid         GUID ?
ends

struc JOYINFO
    wXpos    dd ?
    wYpos    dd ?
    wZpos    dd ?
    wButtons dd ?
ends

struc JOYINFOEX
    dwSize         dd ?
    dwFlags        dd ?
    dwXpos         dd ?
    dwYpos         dd ?
    dwZpos         dd ?
    dwRpos         dd ?
    dwUpos         dd ?
    dwVpos         dd ?
    dwButtons      dd ?
    dwButtonNumber dd ?
    dwPOV          dd ?
    dwReserved1    dd ?
    dwReserved2    dd ?
ends

struc MMIOINFO
    dwFlags     dd    ?
    fccIOProc   dd    ?
    pIOProc     xword ?
    wErrorRet   dd    ?
    htask       xword ?
    cchBuffer   dd    ?
    pchBuffer   xword ?
    pchNext     xword ?
    pchEndRead  xword ?
    pchEndWrite xword ?
    lBufOffset  dd    ?
    lDiskOffset dd    ?
    adwInfo     rd    3
    dwReserved1 dd    ?
    dwReserved2 dd    ?
    hmmio       xword ?
ends

struc MMCKINFO
    ckid         dd ?
    cksize       dd ?
    fccType      dd ?
    dwDataOffset dd ?
    dwFlags      dd ?
ends

struc MCI_GENERIC_PARMS
    dwCallback xword ?
ends

struc MCI_OPEN_PARMSA
    dwCallback       xword ?
    wDeviceID        dd    ?
    lpstrDeviceType  xword ?
    lpstrElementName xword ?
    lpstrAlias       xword ?
ends

struc MCI_OPEN_PARMSW
    dwCallback       xword ?
    wDeviceID        dd    ?
    lpstrDeviceType  xword ?
    lpstrElementName xword ?
    lpstrAlias       xword ?
ends

struc MCI_PLAY_PARMS
    dwCallback xword ?
    dwFrom     dd    ?
    dwTo       dd    ?
ends

struc MCI_SEEK_PARMS
    dwCallback xword ?
    dwTo       dd    ?
ends

struc MCI_STATUS_PARMS
    dwCallback xword ?
    dwReturn   xword ?
    dwItem     dd    ?
    dwTrack    dd    ?
ends

struc MCI_INFO_PARMSA
    dwCallback  xword ?
    lpstrReturn xword ?
    dwRetSize   dd    ?
ends

struc MCI_INFO_PARMSW
    dwCallback  xword ?
    lpstrReturn xword ?
    dwRetSize   dd    ?
ends

struc MCI_GETDEVCAPS_PARMS
    dwCallback xword ?
    dwReturn   dd    ?
    dwItem     dd    ?
ends

struc MCI_SYSINFO_PARMSA
    dwCallback  xword ?
    lpstrReturn xword ?
    dwRetSize   dd    ?
    dwNumber    dd    ?
    wDeviceType dd    ?
ends

struc MCI_SYSINFO_PARMSW
    dwCallback  xword ?
    lpstrReturn xword ?
    dwRetSize   dd    ?
    dwNumber    dd    ?
    wDeviceType dd    ?
ends

struc MCI_SET_PARMS
    dwCallback   xword ?
    dwTimeFormat dd    ?
    dwAudio      dd    ?
ends

struc MCI_BREAK_PARMS
    dwCallback xword ?
    nVirtKey   dd    ?
    hwndBreak  xword ?
ends

struc MCI_SAVE_PARMSA
    dwCallback xword ?
    lpfilename xword ?
ends

struc MCI_SAVE_PARMSW
    dwCallback xword ?
    lpfilename xword ?
ends

struc MCI_LOAD_PARMSA
    dwCallback xword ?
    lpfilename xword ?
ends

struc MCI_LOAD_PARMSW
    dwCallback xword ?
    lpfilename xword ?
ends

struc MCI_RECORD_PARMS
    dwCallback xword ?
    dwFrom     dd    ?
    dwTo       dd    ?
ends

struc MCI_VD_PLAY_PARMS
    dwCallback xword ?
    dwFrom     dd    ?
    dwTo       dd    ?
    dwSpeed    dd    ?
ends

struc MCI_VD_STEP_PARMS
    dwCallback xword ?
    dwFrames   dd    ?
ends

struc MCI_VD_ESCAPE_PARMSA
    dwCallback   xword ?
    lpstrCommand xword ?
ends

struc MCI_VD_ESCAPE_PARMSW
    dwCallback   xword ?
    lpstrCommand xword ?
ends

struc MCI_WAVE_OPEN_PARMSA
    dwCallback       xword ?
    wDeviceID        dd    ?
    lpstrDeviceType  xword ?
    lpstrElementName xword ?
    lpstrAlias       xword ?
    dwBufferSeconds  dd    ?
ends

struc MCI_WAVE_OPEN_PARMSW
    dwCallback       xword ?
    wDeviceID        dd    ?
    lpstrDeviceType  xword ?
    lpstrElementName xword ?
    lpstrAlias       xword ?
    dwBufferSeconds  dd    ?
ends

struc MCI_WAVE_DELETE_PARMS
    dwCallback xword ?
    dwFrom     dd    ?
    dwTo       dd    ?
ends

struc MCI_WAVE_SET_PARMS
    dwCallback      xword ?
    dwTimeFormat    dd    ?
    dwAudio         dd    ?
    wInput          dd    ?
    wOutput         dd    ?
    wFormatTag      dw    ?
    wReserved2      dw    ?
    nChannels       dw    ?
    wReserved3      dw    ?
    nSamplesPerSec  dd    ?
    nAvgBytesPerSec dd    ?
    nBlockAlign     dw    ?
    wReserved4      dw    ?
    wBitsPerSample  dw    ?
    wReserved5      dw    ?
ends

struc MCI_SEQ_SET_PARMS
    dwCallback   xword ?
    dwTimeFormat dd    ?
    dwAudio      dd    ?
    dwTempo      dd    ?
    dwPort       dd    ?
    dwSlave      dd    ?
    dwMaster     dd    ?
    dwOffset     dd    ?
ends

struc MCI_ANIM_OPEN_PARMSA
    dwCallback       xword ?
    wDeviceID        dd    ?
    lpstrDeviceType  xword ?
    lpstrElementName xword ?
    lpstrAlias       xword ?
    dwStyle          dd    ?
    hWndParent       xword ?
ends

struc MCI_ANIM_OPEN_PARMSW
    dwCallback       xword ?
    wDeviceID        dd    ?
    lpstrDeviceType  xword ?
    lpstrElementName xword ?
    lpstrAlias       xword ?
    dwStyle          dd    ?
    hWndParent       xword ?
ends

struc MCI_ANIM_PLAY_PARMS
    dwCallback xword ?
    dwFrom     dd    ?
    dwTo       dd    ?
    dwSpeed    dd    ?
ends

struc MCI_ANIM_STEP_PARMS
    dwCallback xword ?
    dwFrames   dd    ?
ends

struc MCI_ANIM_WINDOW_PARMSA
    dwCallback xword ?
    union
        hWnd   xword ?
        hwnd   xword ?
    endu
    nCmdShow   dd    ?
    lpstrText  xword ?
ends

struc MCI_ANIM_WINDOW_PARMSW
    dwCallback xword ?
    union
        hWnd   xword ?
        hwnd   xword ?
    endu
    nCmdShow   dd    ?
    lpstrText  xword ?
ends

struc MCI_ANIM_RECT_PARMS
    dwCallback   xword  ?
    #ifdef MCI_USE_OFFEXT
        ptOffset POINT ?
        ptExtent POINT ?
    #else
        rc       RECT  ?
    #endif
ends

struc MCI_ANIM_UPDATE_PARMS
    dwCallback xword ?
    rc         RECT  ?
    hDC        xword ?
ends

struc MCI_OVLY_OPEN_PARMSA
    dwCallback       xword ?
    wDeviceID        dd    ?
    lpstrDeviceType  xword ?
    lpstrElementName xword ?
    lpstrAlias       xword ?
    dwStyle          dd    ?
    hWndParent       xword ?
ends

struc MCI_OVLY_OPEN_PARMSW
    dwCallback       xword ?
    wDeviceID        dd    ?
    lpstrDeviceType  xword ?
    lpstrElementName xword ?
    lpstrAlias       xword ?
    dwStyle          dd    ?
    hWndParent       xword ?
ends

struc MCI_OVLY_WINDOW_PARMSA
    dwCallback xword ?
    hWnd       xword ?
    nCmdShow   dd    ?
    lpstrText  xword ?
ends

struc MCI_OVLY_WINDOW_PARMSW
    dwCallback xword ?
    hWnd       xword ?
    nCmdShow   dd    ?
    lpstrText  xword ?
ends

struc MCI_OVLY_RECT_PARMS
    dwCallback   xword ?
    rc           RECT  ?
ends

struc MCI_OVLY_SAVE_PARMSA
    dwCallback xword ?
    lpfilename xword ?
    rc         RECT  ?
ends

struc MCI_OVLY_SAVE_PARMSW
    dwCallback xword ?
    lpfilename xword ?
    rc         RECT  ?
ends

struc MCI_OVLY_LOAD_PARMSA
    dwCallback xword ?
    lpfilename xword ?
    rc         RECT  ?
ends

struc MCI_OVLY_LOAD_PARMSW
    dwCallback xword ?
    lpfilename xword ?
    rc         RECT  ?
ends

;======================================== wlanapi ======================================;
struc ADAPTER_INFO
    name                        rw ADAPTER_NAME_LENGTH
    description                 rw ADAPTER_DESCRIPTION_LENGTH
ends

struc MAC_ADDRESS
    addr                        rb      6
                                rb      2 ;Padding for WIN64
ends

struc AP_INFO
    _name                       rb      AP_NAME_LENGTH
    rssi                        dd      ?
    mac_address                 MAC_ADDRESS ?
ends

struc DOT11_OI
    OILength    dw ?
    OI          rb DOT11_OI_MAX_LENGTH
ends

struc DOT11_AUTH_CIPHER_PAIR
    AuthAlgoId      dd   ?
    CipherAlgoId    dd   ?
ends

struc DOT11_SSID
   uSSIDLength                  dd ?
   ucSSID                       rb DOT11_SSID_MAX_LENGTH
ends

struc DOT11_MAC_ADDRESS
    ucDot11MacAddress           rb      6
                                rb      2 ;Padding for WIN64
ends

struc DOT11_NETWORK
    dot11Ssid       DOT11_SSID ?
    dot11BssType    xword ?
ends

struc DOT11_ACCESSNETWORKOPTIONS
    AccessNetworkType   db ?
    Internet            db ?
    ASRA                db ?
    ESR                 db ?
    UESA                db ?
                        rb 3 ;Padding for WIN64
ends

struc DOT11_VENUEINFO
    VenueGroup  db ?
    VenueType   db ?
                rb 2 ;Padding for WIN64
ends

struc WLAN_PROFILE_INFO
    strProfileName  rw WLAN_MAX_NAME_LENGTH
    dwFlags         dd ?
ends

struc WLAN_INTERFACE_INFO
    InterfaceGuid               GUID   ?
    strInterfaceDescription     rw     256
    isState                     xword  ?
                                rb 2 ;Padding for WIN64
ends

struc WLAN_INTERFACE_INFO_LIST
    dwNumberOfItems             dd   ?
    dwIndex                     dd   ?
    InterfaceInfo               WLAN_INTERFACE_INFO ?
ends

struc WLAN_ASSOCIATION_ATTRIBUTES
    dot11Ssid           DOT11_SSID ?
    dot11BssType        dd    ?
    dot11Bssid          DOT11_MAC_ADDRESS ?
    dot11PhyType        dd    ?
    uDot11PhyIndex      dd    ?
    wlanSignalQuality   xword ?
    ulRxRate            dd    ?
    ulTxRate            dd    ?
ends

struc WLAN_SECURITY_ATTRIBUTES
    bSecurityEnabled        dd ?
    bOneXEnabled            dd ?
    dot11AuthAlgorithm      dd ?
    dot11CipherAlgorithm    dd ?
ends

struc WLAN_AVAILABLE_NETWORK
    strProfileName              rw WLAN_MAX_NAME_LENGTH
    dot11Ssid                   DOT11_SSID ?
    dot11BssType                dd ?
    uNumberOfBssids             dd ?
    bNetworkConnectable         dd ?
    wlanNotConnectableReason    dd ?
    uNumberOfPhyTypes           dd ?
    dot11PhyTypes               rd WLAN_MAX_PHY_TYPE_NUMBER
    bMorePhyTypes               dd ?
    wlanSignalQuality           dd ?
    bSecurityEnabled            dd ?
    dot11DefaultAuthAlgorithm   dd ?
    dot11DefaultCipherAlgorithm dd ?
    dwFlags                     dd ?
    dwReserved                  dd ?
ends

struc WLAN_AVAILABLE_NETWORK_V2
    strProfileName              rw WLAN_MAX_NAME_LENGTH
    dot11Ssid                   DOT11_SSID ?
    dot11BssType                dd ?
    uNumberOfBssids             dd ?
    bNetworkConnectable         dd ?
    wlanNotConnectableReason    dd ?
    uNumberOfPhyTypes           dd ?
    dot11PhyTypes               rd WLAN_MAX_PHY_TYPE_NUMBER
    bMorePhyTypes               dd ?
    wlanSignalQuality           dd ?
    bSecurityEnabled            dd ?
    dot11DefaultAuthAlgorithm   dd ?
    dot11DefaultCipherAlgorithm dd ?
    dwFlags                     dd ?
    AccessNetworkOptions        DOT11_ACCESSNETWORKOPTIONS ?
    dot11HESSID                 xword ?
    VenueInfo                   DOT11_VENUEINFO ?
    dwReserved                  dd ?
ends

struc WLAN_AVAILABLE_NETWORK_LIST
    dwNumberOfItems dd   ?
    dwIndex         dd   ?
    Network         rs WLAN_AVAILABLE_NETWORK,1
ends

struc WLAN_RAW_DATA
    dwDataSize  dd ?
    DataBlob    rb 1
                rb 3 ;Padding for WIN64
ends

struc WLAN_RATE_SET
    uRateSetLength  dd ?
    usRateSet       rw DOT11_RATE_SET_MAX_LENGTH
                    rb 2 ;Padding for WIN64
ends
    
struc WLAN_BSS_ENTRY
    dot11Ssid                   DOT11_SSID  ?
    uPhyId                      dd ?
    dot11Bssid                  DOT11_MAC_ADDRESS ?
    dot11BssType                dd ?
    dot11BssPhyType             dd ?
    lRssi                       dd ?
    uLinkQuality                dd ?
    bInRegDomain                db ?
    usBeaconPeriod              dw ?
                                rb 3 ;Padding for WIN64
    ullTimestamp                dq ?
    ullHostTimestamp            dq ?
    usCapabilityInformation     dw ?
                                dw ? ;Padding for WIN64
    ulChCenterFrequency         dd ?
    wlanRateSet                 WLAN_RATE_SET ?
    ulIeOffset                  dd ?
    ulIeSize                    dd ?
ends

struc WLAN_BSS_LIST
     dwTotalSize                dd   ?
     dwNumberOfItems            dd   ?
     wlanBssEntries             rs WLAN_BSS_ENTRY,1
ends

struc WLAN_CONNECTION_ATTRIBUTES
    isState                     dd ?
    wlanConnectionMode          dd ?
    strProfileName              rw WLAN_MAX_NAME_LENGTH
    wlanAssociationAttributes   WLAN_ASSOCIATION_ATTRIBUTES ?
    wlanSecurityAttributes      WLAN_SECURITY_ATTRIBUTES ?
ends

struc WLAN_PHY_RADIO_STATE
    dwPhyIndex              dd ?
    dot11SoftwareRadioState dd ?
    dot11HardwareRadioState dd ?
                            dd ?    ;Padding for WIN64
ends

struc WLAN_RADIO_STATE
    dwNumberOfPhys  dd ?
    PhyRadioState   rs WLAN_PHY_RADIO_STATE,1
    rs WLAN_PHY_RADIO_STATE,WLAN_MAX_PHY_INDEX-1
ends

struc WLAN_MSM_NOTIFICATION_DATA
    wlanConnectionMode  dd ?
    strProfileName      rw WLAN_MAX_NAME_LENGTH
    dot11Ssid           DOT11_SSID ?
    dot11BssType        dd ?
    dot11MacAddr        DOT11_MAC_ADDRESS ?
    bSecurityEnabled    dd ?
    bFirstPeer          dd ?
    bLastPeer           dd ?
    wlanReasonCode      dd ?
ends

struc WLAN_CONNECTION_NOTIFICATION_DATA
    wlanConnectionMode      dd ?
    strProfileName          rw WLAN_MAX_NAME_LENGTH
    dot11Ssid               DOT11_SSID ?
    dot11BssType            dd ?
    bSecurityEnabled        dd ?
    wlanReasonCode          dd ?
    dwFlags                 dd ?
    strProfileXml           rw 1
                            rb 2 ;Padding for WIN64
ends

;======================================== Miscellanoeus ======================================;

struc CY
    Lo  dd ?
    Hi  dd ?
ends

struc DECIMAL
    Hi32 dd ?
    Lo64 dq ?
ends


#ifdef APP_UNICODE
    define ACTCTX ACTCTXW
    define STARTUPINFO STARTUPINFOW
    define STARTUPINFOEX STARTUPINFOEXW
    define CPINFOEX CPINFOEXW
    define NUMBERFMT NUMBERFMTW
    define CURRENCYFMT CURRENCYFMTW
    define BROWSEINFO BROWSEINFOW
    define WIN32_FIND_DATA WIN32_FIND_DATAW
    define HW_PROFILE_INFO HW_PROFILE_INFOW

    define SERVICE_DESCRIPTION SERVICE_DESCRIPTIONW
    define SERVICE_FAILURE_ACTIONS SERVICE_FAILURE_ACTIONSW
    define QUERY_SERVICE_LOCK_STATUS QUERY_SERVICE_LOCK_STATUSW
    define QUERY_SERVICE_CONFIG QUERY_SERVICE_CONFIGW
    define SERVICE_TABLE_ENTRY SERVICE_TABLE_ENTRYW
    define ENUM_SERVICE_STATUS ENUM_SERVICE_STATUSW
    define ENUM_SERVICE_STATUS_PROCESS ENUM_SERVICE_STATUS_PROCESSW
    define INHERITED_FROM INHERITED_FROMW
    define OBJECTS_AND_NAME OBJECTS_AND_NAME_W
    define TRUSTEE TRUSTEE_W
    define EXPLICIT_ACCESS EXPLICIT_ACCESSW
    define ACTRL_ACCESS_ENTRY ACTRL_ACCESS_ENTRYW
    define ACTRL_ACCESS_ENTRY_LIST ACTRL_ACCESS_ENTRY_LISTW
    define ACTRL_PROPERTY_ENTRY ACTRL_PROPERTY_ENTRYW
    define ACTRL_ALIST ACTRL_ALISTW
    define TRUSTEE_ACCESS TRUSTEE_ACCESSW
    define ACTRL_ACCESS_INFO ACTRL_ACCESS_INFOW
    define ACTRL_CONTROL_INFO ACTRL_CONTROL_INFOW
    define ACTRL_AUDIT ACTRL_AUDITW

    define COMBOBOXEXITEM COMBOBOXEXITEMW
    define HD_ITEM HDITEMW
    define HD_NOTIFY NMHEADERW
    define HD_TEXTFILTER HDTEXTFILTERW
    define HDITEM HDITEMW
    define HDITEM_V1_SIZE HDITEMW_V1_SIZE
    define HDM_GETITEM HDM_GETITEMW
    define HDM_INSERTITEM HDM_INSERTITEMW
    define HDM_SETITEM HDM_SETITEMW
    define HDN_BEGINTRACK HDN_BEGINTRACKW
    define HDN_DIVIDERDBLCLICK HDN_DIVIDERDBLCLICKW
    define HDN_ENDTRACK HDN_ENDTRACKW
    define HDN_GETDISPINFO HDN_GETDISPINFOW
    define HDN_ITEMCHANGED HDN_ITEMCHANGEDW
    define HDN_ITEMCHANGING HDN_ITEMCHANGINGW
    define HDN_ITEMCLICK HDN_ITEMCLICKW
    define HDN_ITEMDBLCLICK HDN_ITEMDBLCLICKW
    define HDN_TRACK HDN_TRACKW
    define HOTKEY_CLASS HOTKEY_CLASSW
    define HDTEXTFILTER  HDTEXTFILTERW
    define LV_COLUMN LVCOLUMNW
    define LV_DISPINFO NMLVDISPINFOW
    define LV_FINDINFO LVFINDINFOW
    define LV_ITEM LVITEMW
    define LVBKIMAGE LVBKIMAGEW
    define LVCOLUMN LVCOLUMNW
    define LVFINDINFO LVFINDINFOW
    define LVITEM LVITEMW
    define LVM_EDITLABEL LVM_EDITLABELW
    define LVM_FINDITEM LVM_FINDITEMW
    define LVM_GETBKIMAGE LVM_GETBKIMAGEW
    define LVM_GETCOLUMN LVM_GETCOLUMNW
    define LVM_GETISEARCHSTRING LVM_GETISEARCHSTRINGW
    define LVM_GETITEM LVM_GETITEMW
    define LVM_GETITEMTEXT LVM_GETITEMTEXTW
    define LVM_GETSTRINGWIDTH LVM_GETSTRINGWIDTHW
    define LVM_INSERTCOLUMN LVM_INSERTCOLUMNW
    define LVM_INSERTITEM LVM_INSERTITEMW
    define LVM_SETBKIMAGE LVM_SETBKIMAGEW
    define LVM_SETCOLUMN LVM_SETCOLUMNW
    define LVM_SETITEM LVM_SETITEMW
    define LVM_SETITEMTEXT LVM_SETITEMTEXTW
    define LVN_BEGINLABELEDIT LVN_BEGINLABELEDITW
    define LVN_ENDLABELEDIT LVN_ENDLABELEDITW
    define LVN_GETDISPINFO LVN_GETDISPINFOW
    define LVN_GETINFOTIP LVN_GETINFOTIPW
    define LVN_INCREMENTALSEARCH LVN_INCREMENTALSEARCHW
    define LVN_ODFINDITEM LVN_ODFINDITEMW
    define LVN_SETDISPINFO LVN_SETDISPINFOW
    define MONTHCAL_CLASS MONTHCAL_CLASSW
    define NMLVFINDITEM NMLVFINDITEMW
    define NM_FINDITEM NMLVFINDITEMW
    define NM_TREEVIEW NMTREEVIEWW
    define NMCBEDRAGBEGIN NMCBEDRAGBEGINW
    define NMCBEENDEDIT NMCBEENDEDITW
    define NMCOMBOBOXEX NMCOMBOBOXEXW
    define NMDATETIMEFORMAT NMDATETIMEFORMATW
    define NMDATETIMEFORMATQUERY NMDATETIMEFORMATQUERYW
    define NMDATETIMESTRING NMDATETIMESTRINGW
    define NMDATETIMEWMKEYDOWN NMDATETIMEWMKEYDOWNAW
    define NMHDDISPINFO NMHDDISPINFOW
    define NMHEADER NMHEADERW
    define NMLVDISPINFO NMLVDISPINFOW
    define NMLVGETINFOTIP NMLVGETINFOTIPW
    define NMTBDISPINFO NMTBDISPINFOW
    define NMTBGETINFOTIP NMTBGETINFOTIPW
    define NMTOOLBAR NMTOOLBARW
    define NMTREEVIEW NMTREEVIEWW
    define NMTTDISPINFO NMTTDISPINFOW
    define NMTTDISPINFO_V1_SIZE NMTTDISPINFOW_V1_SIZE
    define NMTVDISPINFO NMTVDISPINFOW
    define NMTVDISPINFOEX NMTVDISPINFOEXW
    define NMTVGETINFOTIP NMTVGETINFOTIPW
    define PROGRESS_CLASS PROGRESS_CLASSW
    define PROPSHEETHEADER PROPSHEETHEADERW
    define PROPSHEETPAGE PROPSHEETPAGEW
    define PROPSHEETHEADER_V1_SIZE PROPSHEETHEADERW_V1_SIZEW
    define RB_GETBANDINFO RB_GETBANDINFOW
    define RB_INSERTBAND RB_INSERTBANDW
    define RB_SETBANDINFO RB_SETBANDINFOW
    define REBARBANDINFO REBARBANDINFOW
    define REBARBANDINFO_V3_SIZE REBARBANDINFOW_V3_SIZE
    define REBARCLASSNAME REBARCLASSNAMEW
    define SB_GETTEXT SB_GETTEXTW
    define SB_GETTEXTLENGTH SB_GETTEXTLENGTHW
    define SB_GETTIPTEXT SB_GETTIPTEXTW
    define SB_SETTEXT SB_SETTEXTW
    define SB_SETTIPTEXT SB_SETTIPTEXTW
    define STATUSCLASSNAME STATUSCLASSNAMEW
    define TB_ADDBUTTONS TB_ADDBUTTONSW
    define TB_ADDSTRING TB_ADDSTRINGW
    define TB_GETBUTTONINFO TB_GETBUTTONINFOW
    define TB_GETBUTTONTEXT TB_GETBUTTONTEXTW
    define TB_GETSTRING TB_GETSTRINGW
    define TB_INSERTBUTTON TB_INSERTBUTTONW
    define TB_MAPACCELERATOR TB_MAPACCELERATORW
    define TB_SAVERESTORE TB_SAVERESTOREW
    define TB_SETBUTTONINFO TB_SETBUTTONINFOW
    define TBBUTTONINFO TBBUTTONINFOW
    define TBN_GETBUTTONINFO TBN_GETBUTTONINFOW
    define TBN_GETDISPINFO TBN_GETDISPINFOW
    define TBN_GETINFOTIP TBN_GETINFOTIPW
    define TBNOTIFY NMTOOLBARW
    define TBSAVEPARAMS TBSAVEPARAMSW
    define TC_ITEM TCITEMW
    define TC_ITEMHEADER TCITEMHEADERW
    define TCITEM TCITEMW
    define TCITEMHEADER TCITEMHEADERW
    define TCM_GETITEM TCM_GETITEMW
    define TCM_INSERTITEM TCM_INSERTITEMW
    define TCM_SETITEM TCM_SETITEMW
    define TOOLBARCLASSNAME TOOLBARCLASSNAMEW
    define TOOLINFO TTTOOLINFOW
    define TOOLINFO_V1_SIZE TOOLINFOW_V1_SIZE
    define TOOLTIPS_CLASS TOOLTIPS_CLASSW
    define TOOLTIPTEXT TOOLTIPTEXTW
    define TRACKBAR_CLASS TRACKBAR_CLASSW
    define TTHITTESTINFO TTHITTESTINFOW
    define TTM_ADDTOOL TTM_ADDTOOLW
    define TTM_DELTOOL TTM_DELTOOLW
    define TTM_ENUMTOOLS TTM_ENUMTOOLSW
    define TTM_GETCURRENTTOOL TTM_GETCURRENTTOOLW
    define TTM_GETTEXT TTM_GETTEXTW
    define TTM_GETTOOLINFO TTM_GETTOOLINFOW
    define TTM_HITTEST TTM_HITTESTW
    define TTM_NEWTOOLRECT TTM_NEWTOOLRECTW
    define TTM_SETTITLE TTM_SETTITLEW
    define TTM_SETTOOLINFO TTM_SETTOOLINFOW
    define TTM_UPDATETIPTEXT TTM_UPDATETIPTEXTW
    define TTN_GETDISPINFO TTN_GETDISPINFOW
    define TTN_NEEDTEXT TTN_NEEDTEXTW
    define TTTOOLINFO TTTOOLINFOW
    define TT_HITTESTINFO TTHITTESTINFOW
    define TV_DISPINFO NMTVDISPINFOW
    define TV_DISPINFOEX NMTVDISPINFOEXW
    define TV_INSERTSTRUCT TVINSERTSTRUCTW
    define TV_ITEM TVITEMW
    define TV_ITEMEX TVITEMEXW
    define TVINSERTSTRUCT TVINSERTSTRUCTW
    define TVITEM TVITEMW
    define TVITEMEX TVITEMEXW
    define TVM_EDITLABEL TVM_EDITLABELW
    define TVM_GETISEARCHSTRING TVM_GETISEARCHSTRINGW
    define TVM_GETITEM TVM_GETITEMW
    define TVM_INSERTITEM TVM_INSERTITEMW
    define TVM_SETITEM TVM_SETITEMW
    define TVN_BEGINDRAG TVN_BEGINDRAGW
    define TVN_BEGINLABELEDIT TVN_BEGINLABELEDITW
    define TVN_BEGINRDRAG TVN_BEGINRDRAGW
    define TVN_DELETEITEM TVN_DELETEITEMW
    define TVN_ENDLABELEDIT TVN_ENDLABELEDITW
    define TVN_GETDISPINFO TVN_GETDISPINFOW
    define TVN_GETINFOTIP TVN_GETINFOTIPW
    define TVN_ITEMCHANGED TVN_ITEMCHANGEDW
    define TVN_ITEMCHANGING TVN_ITEMCHANGINGW
    define TVN_ITEMEXPANDED TVN_ITEMEXPANDEDW
    define TVN_ITEMEXPANDING TVN_ITEMEXPANDINGW
    define TVN_SELCHANGED TVN_SELCHANGEDW
    define TVN_SELCHANGING TVN_SELCHANGINGW
    define TVN_SETDISPINFO TVN_SETDISPINFOW
    define WC_IPADDRESS WC_IPADDRESSW
    define WC_LISTVIEW WC_LISTVIEWW
    define WC_NATIVEFONTCTL WC_NATIVEFONTCTLW
    define WC_PAGESCROLLER WC_PAGESCROLLERW
    define WC_TABCONTROL WC_TABCONTROLW
    define WC_TREEVIEW WC_TREEVIEWW

    define OPENFILENAME OPENFILENAMEW
    define OFNOTIFY OFNOTIFYW
    define OFNOTIFYEX OFNOTIFYEXW
    define CHOOSECOLOR CHOOSECOLORW
    define FINDREPLACE FINDREPLACEW
    define CHOOSEFONT CHOOSEFONTW
    define PRINTDLG PRINTDLGW
    define PRINTDLGEX PRINTDLGEXW
    define PAGESETUPDLG PAGESETUPDLGW

    define AXESLIST AXESLISTW
    define AXISINFO AXISINFOW
    define DISPLAY_DEVICE DISPLAY_DEVICEW
    define DOCINFO DOCINFOW
    define EMREXTTEXTOUT EMREXTTEXTOUTW
    define EMRPOLYTEXTOUT EMRPOLYTEXTOUTW
    define EMREXTCREATEFONTINDIRECT EMREXTCREATEFONTINDIRECTW
    define ENUMLOGFONT ENUMLOGFONTW
    define ENUMLOGFONTEX ENUMLOGFONTEXW
    define ENUMLOGFONTEXDV ENUMLOGFONTEXDVW
    define ENUMTEXTMETRIC ENUMTEXTMETRICW
    define EXTLOGFONT EXTLOGFONTW
    define GCP_RESULTS GCP_RESULTSW
    define LOGCOLORSPACE LOGCOLORSPACEW
    define LOGFONT LOGFONTW
    define NEWTEXTMETRIC NEWTEXTMETRICW
    define NEWTEXTMETRICEX NEWTEXTMETRICEXW
    define OUTLINETEXTMETRIC OUTLINETEXTMETRICW
    define TEXTMETRIC TEXTMETRICW
    define POLYTEXT POLYTEXTW

    define OSVERSIONINFOEX OSVERSIONINFOEXW
    define IMAGE_FUNCTION_ENTRY IMAGE_FUNCTION_ENTRY64
    define IMAGE_THUNK_DATA IMAGE_THUNK_DATA64
    define IMAGE_TLS_DIRECTORY IMAGE_TLS_DIRECTORY64
    define IMAGE_LOAD_CONFIG_DIRECTORY IMAGE_LOAD_CONFIG_DIRECTORY64

    define RASSUBENTRY RASSUBENTRYW
    define RASCREDENTIALS RASCREDENTIALSW
    define RASAUTODIALENTRY RASAUTODIALENTRYW
    define RASCONN RASCONNW
    define RASCONNSTATUS RASCONNSTATUSW
    define RASDIALPARAMS RASDIALPARAMSW
    define RASENTRYNAME RASENTRYNAMEW
    define RASAMB RASAMBW
    define RASPPPNBF RASPPPNBFW
    define RASPPPIPX RASPPPIPXW
    define RASPPPIP RASPPPIPW
    define RASSLIP RASSLIPW
    define RASDEVINFO RASDEVINFOW
    define RASENTRY RASENTRYW

    define DRAGINFO DRAGINFOW
    define SHFILEOPSTRUCT SHFILEOPSTRUCTW
    define SHNAMEMAPPING SHNAMEMAPPINGW
    define SHELLEXECUTEINFO SHELLEXECUTEINFOW
    define NOTIFYICONDATA NOTIFYICONDATAW
    define SHFILEINFO SHFILEINFOW
    define OPEN_PRINTER_PROPS_INFO OPEN_PRINTER_PROPS_INFOW

    define ICONINFOEX ICONINFOEXW
    define CBT_CREATEWND CBT_CREATEWNDW
    define WNDCLASSEX WNDCLASSEXW
    define WNDCLASS WNDCLASSW
    define CREATESTRUCT CREATESTRUCTW
    define MENUITEMINFO MENUITEMINFOW
    define MSGBOXPARAMS MSGBOXPARAMSW
    define MDICREATESTRUCT MDICREATESTRUCTW
    define MULTIKEYHELP MULTIKEYHELPW
    define HELPWININFO HELPWININFOW
    define NONCLIENTMETRICS NONCLIENTMETRICSW
    define ICONMETRICS ICONMETRICSW
    define SERIALKEYS SERIALKEYSW
    define HIGHCONTRAST HIGHCONTRASTW
    define SOUNDSENTRY SOUNDSENTRYW
    define MONITORINFOEX MONITORINFOEXW

    define AVISTREAMINFO AVISTREAMINFOA
    define AVIFILEINFO  AVIFILEINFOA

    define MIXERCONTROL MIXERCONTROLW
    define WAVEOUTCAPS WAVEOUTCAPSW
    define WAVEOUTCAPS2 WAVEOUTCAPS2W
    define WAVEINCAPS WAVEINCAPSW
    define WAVEINCAPS2 WAVEINCAPS2W
    define MIDIOUTCAPS MIDIOUTCAPSW
    define MIDIOUTCAPS2 MIDIOUTCAPS2W
    define MIDIINCAPS MIDIINCAPSW
    define MIDIINCAPS2 MIDIINCAPS2W
    define AUXCAPS AUXCAPSW
    define AUXCAPS2 AUXCAPS2W
    define MIXERCAPS MIXERCAPSW
    define MIXERCAPS2 MIXERCAPS2W
    define TARGET TARGETW
    define MIXERLINE MIXERLINEW
    define MIXERLINECONTROLS MIXERLINECONTROLSW
    define MIXERCONTROLDETAILS_LISTTEXT MIXERCONTROLDETAILS_LISTTEXTW
    define JOYCAPS JOYCAPSW
    define JOYCAPS2 JOYCAPS2W
    define MCI_OPEN_PARMS MCI_OPEN_PARMSW
    define MCI_INFO_PARMS MCI_INFO_PARMSW
    define MCI_SYSINFO_PARMS MCI_SYSINFO_PARMSW
    define MCI_SAVE_PARMS MCI_SAVE_PARMSW
    define MCI_LOAD_PARMS MCI_LOAD_PARMSW
    define MCI_VD_ESCAPE_PARMS MCI_VD_ESCAPE_PARMSW
    define MCI_WAVE_OPEN_PARMS MCI_WAVE_OPEN_PARMSW
    define MCI_ANIM_OPEN_PARMS MCI_ANIM_OPEN_PARMSW
    define MCI_ANIM_WINDOW_PARMS MCI_ANIM_WINDOW_PARMSW
    define MCI_OVLY_OPEN_PARMS MCI_OVLY_OPEN_PARMSW
    define MCI_OVLY_WINDOW_PARMS MCI_OVLY_WINDOW_PARMSW
    define MCI_OVLY_SAVE_PARMS MCI_OVLY_SAVE_PARMSW
    define MCI_OVLY_LOAD_PARMS MCI_OVLY_LOAD_PARMSW
#else
    define ACTCTX ACTCTXA
    define STARTUPINFO STARTUPINFOA
    define STARTUPINFOEX STARTUPINFOEXA
    define CPINFOEX CPINFOEXA
    define NUMBERFMT NUMBERFMTA
    define CURRENCYFMT CURRENCYFMTA
    define BROWSEINFO BROWSEINFOA
    define WIN32_FIND_DATA WIN32_FIND_DATAA
    define HW_PROFILE_INFO HW_PROFILE_INFOA

    define SERVICE_DESCRIPTION SERVICE_DESCRIPTIONA
    define SERVICE_FAILURE_ACTIONS SERVICE_FAILURE_ACTIONSA
    define QUERY_SERVICE_LOCK_STATUS QUERY_SERVICE_LOCK_STATUSA
    define QUERY_SERVICE_CONFIG QUERY_SERVICE_CONFIGA
    define SERVICE_TABLE_ENTRY SERVICE_TABLE_ENTRYA
    define ENUM_SERVICE_STATUS ENUM_SERVICE_STATUSA
    define ENUM_SERVICE_STATUS_PROCESS ENUM_SERVICE_STATUS_PROCESSA
    define INHERITED_FROM INHERITED_FROMA
    define OBJECTS_AND_NAME OBJECTS_AND_NAME_A
    define TRUSTEE TRUSTEE_A
    define EXPLICIT_ACCESS EXPLICIT_ACCESSA
    define ACTRL_ACCESS_ENTRY ACTRL_ACCESS_ENTRYA
    define ACTRL_ACCESS_ENTRY_LIST ACTRL_ACCESS_ENTRY_LISTA
    define ACTRL_PROPERTY_ENTRY ACTRL_PROPERTY_ENTRYA
    define ACTRL_ALIST ACTRL_ALISTA
    define TRUSTEE_ACCESS TRUSTEE_ACCESSA
    define ACTRL_ACCESS_INFO ACTRL_ACCESS_INFOA
    define ACTRL_CONTROL_INFO ACTRL_CONTROL_INFOA
    define ACTRL_AUDIT ACTRL_AUDITA

    define COMBOBOXEXITEM COMBOBOXEXITEMA
    define HD_ITEM HDITEMA
    define HD_NOTIFY NMHEADERA
    define HD_TEXTFILTER HDTEXTFILTERA
    define HDITEM HDITEMA
    define HDITEM_V1_SIZE HDITEMA_V1_SIZE
    define HDM_GETITEM HDM_GETITEMA
    define HDM_INSERTITEM HDM_INSERTITEMA
    define HDM_SETITEM HDM_SETITEMA
    define HDN_BEGINTRACK HDN_BEGINTRACKA
    define HDN_DIVIDERDBLCLICK HDN_DIVIDERDBLCLICKA
    define HDN_ENDTRACK HDN_ENDTRACKA
    define HDN_GETDISPINFO HDN_GETDISPINFOA
    define HDN_ITEMCHANGED HDN_ITEMCHANGEDA
    define HDN_ITEMCHANGING HDN_ITEMCHANGINGA
    define HDN_ITEMCLICK HDN_ITEMCLICKA
    define HDN_ITEMDBLCLICK HDN_ITEMDBLCLICKA
    define HDN_TRACK HDN_TRACKA
    define HOTKEY_CLASS HOTKEY_CLASSA
    define HDTEXTFILTER  HDTEXTFILTERA
    define LV_COLUMN LVCOLUMNA
    define LV_DISPINFO NMLVDISPINFOA
    define LV_FINDINFO LVFINDINFOA
    define LV_ITEM LVITEMA
    define LVBKIMAGE LVBKIMAGEA
    define LVCOLUMN LVCOLUMNA
    define LVFINDINFO LVFINDINFOA
    define LVITEM LVITEMA
    define LVM_EDITLABEL LVM_EDITLABELA
    define LVM_FINDITEM LVM_FINDITEMA
    define LVM_GETBKIMAGE LVM_GETBKIMAGEA
    define LVM_GETCOLUMN LVM_GETCOLUMNA
    define LVM_GETISEARCHSTRING LVM_GETISEARCHSTRINGA
    define LVM_GETITEM LVM_GETITEMA
    define LVM_GETITEMTEXT LVM_GETITEMTEXTA
    define LVM_GETSTRINGWIDTH LVM_GETSTRINGWIDTHA
    define LVM_INSERTCOLUMN LVM_INSERTCOLUMNA
    define LVM_INSERTITEM LVM_INSERTITEMA
    define LVM_SETBKIMAGE LVM_SETBKIMAGEA
    define LVM_SETCOLUMN LVM_SETCOLUMNA
    define LVM_SETITEM LVM_SETITEMA
    define LVM_SETITEMTEXT LVM_SETITEMTEXTA
    define LVN_BEGINLABELEDIT LVN_BEGINLABELEDITA
    define LVN_ENDLABELEDIT LVN_ENDLABELEDITA
    define LVN_GETDISPINFO LVN_GETDISPINFOA
    define LVN_GETINFOTIP LVN_GETINFOTIPA
    define LVN_INCREMENTALSEARCH LVN_INCREMENTALSEARCHA
    define LVN_ODFINDITEM LVN_ODFINDITEMA
    define LVN_SETDISPINFO LVN_SETDISPINFOA
    define MONTHCAL_CLASS MONTHCAL_CLASSA
    define NMLVFINDITEM NMLVFINDITEMA
    define NM_FINDITEM NMLVFINDITEMA
    define NM_TREEVIEW NMTREEVIEWA
    define NMCBEDRAGBEGIN NMCBEDRAGBEGINA
    define NMCBEENDEDIT NMCBEENDEDITA
    define NMCOMBOBOXEX NMCOMBOBOXEXA
    define NMDATETIMEFORMAT NMDATETIMEFORMATA
    define NMDATETIMEFORMATQUERY NMDATETIMEFORMATQUERYA
    define NMDATETIMESTRING NMDATETIMESTRINGA
    define NMDATETIMEWMKEYDOWN NMDATETIMEWMKEYDOWNAA
    define NMHDDISPINFO NMHDDISPINFOA
    define NMHEADER NMHEADERA
    define NMLVDISPINFO NMLVDISPINFOA
    define NMLVGETINFOTIP NMLVGETINFOTIPA
    define NMTBDISPINFO NMTBDISPINFOA
    define NMTBGETINFOTIP NMTBGETINFOTIPA
    define NMTOOLBAR NMTOOLBARA
    define NMTREEVIEW NMTREEVIEWA
    define NMTTDISPINFO NMTTDISPINFOA
    define NMTTDISPINFO_V1_SIZE NMTTDISPINFOA_V1_SIZE
    define NMTVDISPINFO NMTVDISPINFOA
    define NMTVDISPINFOEX NMTVDISPINFOEXA
    define NMTVGETINFOTIP NMTVGETINFOTIPA
    define PROGRESS_CLASS PROGRESS_CLASSA
    define PROPSHEETHEADER PROPSHEETHEADERA
    define PROPSHEETPAGE PROPSHEETPAGEA
    define PROPSHEETHEADER_V1_SIZE PROPSHEETHEADERW_V1_SIZEA
    define RB_GETBANDINFO RB_GETBANDINFOA
    define RB_INSERTBAND RB_INSERTBANDA
    define RB_SETBANDINFO RB_SETBANDINFOA
    define REBARBANDINFO REBARBANDINFOA
    define REBARBANDINFO_V3_SIZE REBARBANDINFOA_V3_SIZE
    define REBARCLASSNAME REBARCLASSNAMEA
    define SB_GETTEXT SB_GETTEXTA
    define SB_GETTEXTLENGTH SB_GETTEXTLENGTHA
    define SB_GETTIPTEXT SB_GETTIPTEXTA
    define SB_SETTEXT SB_SETTEXTA
    define SB_SETTIPTEXT SB_SETTIPTEXTA
    define STATUSCLASSNAME STATUSCLASSNAMEA
    define TB_ADDBUTTONS TB_ADDBUTTONSA
    define TB_ADDSTRING TB_ADDSTRINGA
    define TB_GETBUTTONINFO TB_GETBUTTONINFOA
    define TB_GETBUTTONTEXT TB_GETBUTTONTEXTA
    define TB_GETSTRING TB_GETSTRINGA
    define TB_INSERTBUTTON TB_INSERTBUTTONA
    define TB_MAPACCELERATOR TB_MAPACCELERATORA
    define TB_SAVERESTORE TB_SAVERESTOREA
    define TB_SETBUTTONINFO TB_SETBUTTONINFOA
    define TBBUTTONINFO TBBUTTONINFOA
    define TBN_GETBUTTONINFO TBN_GETBUTTONINFOA
    define TBN_GETDISPINFO TBN_GETDISPINFOA
    define TBN_GETINFOTIP TBN_GETINFOTIPA
    define TBNOTIFY NMTOOLBARA
    define TBSAVEPARAMS TBSAVEPARAMSA
    define TC_ITEM TCITEMA
    define TC_ITEMHEADER TCITEMHEADERA
    define TCITEM TCITEMA
    define TCITEMHEADER TCITEMHEADERA
    define TCM_GETITEM TCM_GETITEMA
    define TCM_INSERTITEM TCM_INSERTITEMA
    define TCM_SETITEM TCM_SETITEMA
    define TOOLBARCLASSNAME TOOLBARCLASSNAMEA
    define TOOLINFO TTTOOLINFOA
    define TOOLINFO_V1_SIZE TOOLINFOA_V1_SIZE
    define TOOLTIPS_CLASS TOOLTIPS_CLASSA
    define TOOLTIPTEXT TOOLTIPTEXTA
    define TRACKBAR_CLASS TRACKBAR_CLASSA
    define TTHITTESTINFO TTHITTESTINFOA
    define TTM_ADDTOOL TTM_ADDTOOLA
    define TTM_DELTOOL TTM_DELTOOLA
    define TTM_ENUMTOOLS TTM_ENUMTOOLSA
    define TTM_GETCURRENTTOOL TTM_GETCURRENTTOOLA
    define TTM_GETTEXT TTM_GETTEXTA
    define TTM_GETTOOLINFO TTM_GETTOOLINFOA
    define TTM_HITTEST TTM_HITTESTA
    define TTM_NEWTOOLRECT TTM_NEWTOOLRECTA
    define TTM_SETTITLE TTM_SETTITLEA
    define TTM_SETTOOLINFO TTM_SETTOOLINFOA
    define TTM_UPDATETIPTEXT TTM_UPDATETIPTEXTA
    define TTN_GETDISPINFO TTN_GETDISPINFOA
    define TTN_NEEDTEXT TTN_NEEDTEXTA
    define TTTOOLINFO TTTOOLINFOA
    define TT_HITTESTINFO TTHITTESTINFOA
    define TV_DISPINFO NMTVDISPINFOA
    define TV_DISPINFOEX NMTVDISPINFOEXA
    define TV_INSERTSTRUCT TVINSERTSTRUCTA
    define TV_ITEM TVITEMA
    define TV_ITEMEX TVITEMEXA
    define TVINSERTSTRUCT TVINSERTSTRUCTA
    define TVITEM TVITEMA
    define TVITEMEX TVITEMEXA
    define TVM_EDITLABEL TVM_EDITLABELA
    define TVM_GETISEARCHSTRING TVM_GETISEARCHSTRINGA
    define TVM_GETITEM TVM_GETITEMA
    define TVM_INSERTITEM TVM_INSERTITEMA
    define TVM_SETITEM TVM_SETITEMA
    define TVN_BEGINDRAG TVN_BEGINDRAGA
    define TVN_BEGINLABELEDIT TVN_BEGINLABELEDITA
    define TVN_BEGINRDRAG TVN_BEGINRDRAGA
    define TVN_DELETEITEM TVN_DELETEITEMA
    define TVN_ENDLABELEDIT TVN_ENDLABELEDITA
    define TVN_GETDISPINFO TVN_GETDISPINFOA
    define TVN_GETINFOTIP TVN_GETINFOTIPA
    define TVN_ITEMCHANGED TVN_ITEMCHANGEDA
    define TVN_ITEMCHANGING TVN_ITEMCHANGINGA
    define TVN_ITEMEXPANDED TVN_ITEMEXPANDEDA
    define TVN_ITEMEXPANDING TVN_ITEMEXPANDINGA
    define TVN_SELCHANGED TVN_SELCHANGEDA
    define TVN_SELCHANGING TVN_SELCHANGINGA
    define TVN_SETDISPINFO TVN_SETDISPINFOA
    define WC_IPADDRESS WC_IPADDRESSA
    define WC_LISTVIEW WC_LISTVIEWA
    define WC_NATIVEFONTCTL WC_NATIVEFONTCTLA
    define WC_PAGESCROLLER WC_PAGESCROLLERA
    define WC_TABCONTROL WC_TABCONTROLA
    define WC_TREEVIEW WC_TREEVIEWA

    define OPENFILENAME OPENFILENAMEA
    define OFNOTIFY OFNOTIFYA
    define OFNOTIFYEX OFNOTIFYEXA
    define CHOOSECOLOR CHOOSECOLORA
    define FINDREPLACE FINDREPLACEA
    define CHOOSEFONT CHOOSEFONTA
    define PRINTDLG PRINTDLGA
    define PRINTDLGEX PRINTDLGEXA
    define PAGESETUPDLG PAGESETUPDLGA

    define AXESLIST AXESLISTA
    define AXISINFO AXISINFOA
    define DISPLAY_DEVICE DISPLAY_DEVICEA
    define DOCINFO DOCINFOA
    define EMREXTTEXTOUT EMREXTTEXTOUTA
    define EMRPOLYTEXTOUT EMRPOLYTEXTOUTA
    define EMREXTCREATEFONTINDIRECT EMREXTCREATEFONTINDIRECTA
    define ENUMLOGFONT ENUMLOGFONTA
    define ENUMLOGFONTEX ENUMLOGFONTEXA
    define ENUMLOGFONTEXDV ENUMLOGFONTEXDVA
    define ENUMTEXTMETRIC ENUMTEXTMETRICA
    define EXTLOGFONT EXTLOGFONTA
    define GCP_RESULTS GCP_RESULTSA
    define LOGCOLORSPACE LOGCOLORSPACEA
    define LOGFONT LOGFONTA
    define NEWTEXTMETRIC NEWTEXTMETRICA
    define NEWTEXTMETRICEX NEWTEXTMETRICEXA
    define OUTLINETEXTMETRIC OUTLINETEXTMETRICA
    define TEXTMETRIC TEXTMETRICA
    define POLYTEXT POLYTEXTA

    define OSVERSIONINFOEX OSVERSIONINFOEXA
    define IMAGE_FUNCTION_ENTRY IMAGE_FUNCTION_ENTRY32
    define IMAGE_THUNK_DATA IMAGE_THUNK_DATA32
    define IMAGE_TLS_DIRECTORY IMAGE_TLS_DIRECTORY32
    define IMAGE_LOAD_CONFIG_DIRECTORY IMAGE_LOAD_CONFIG_DIRECTORY32

    define RASSUBENTRY RASSUBENTRYA
    define RASCREDENTIALS RASCREDENTIALSA
    define RASAUTODIALENTRY RASAUTODIALENTRYA
    define RASCONN RASCONNA
    define RASCONNSTATUS RASCONNSTATUSA
    define RASDIALPARAMS RASDIALPARAMSA
    define RASENTRYNAME RASENTRYNAMEA
    define RASAMB RASAMBA
    define RASPPPNBF RASPPPNBFA
    define RASPPPIPX RASPPPIPXA
    define RASPPPIP RASPPPIPA
    define RASSLIP RASSLIPA
    define RASDEVINFO RASDEVINFOA
    define RASENTRY RASENTRYA

    define DRAGINFO DRAGINFOA
    define SHFILEOPSTRUCT SHFILEOPSTRUCTA
    define SHNAMEMAPPING SHNAMEMAPPINGA
    define SHELLEXECUTEINFO SHELLEXECUTEINFOA
    define NOTIFYICONDATA NOTIFYICONDATAA
    define SHFILEINFO SHFILEINFOA
    define OPEN_PRINTER_PROPS_INFO OPEN_PRINTER_PROPS_INFOA

    define ICONINFOEX ICONINFOEXA
    define CBT_CREATEWND CBT_CREATEWNDA
    define WNDCLASSEX WNDCLASSEXA
    define WNDCLASS WNDCLASSA
    define CREATESTRUCT CREATESTRUCTA
    define MENUITEMINFO MENUITEMINFOA
    define MSGBOXPARAMS MSGBOXPARAMSA
    define MDICREATESTRUCT MDICREATESTRUCTA
    define MULTIKEYHELP MULTIKEYHELPA
    define HELPWININFO HELPWININFOA
    define NONCLIENTMETRICS NONCLIENTMETRICSA
    define ICONMETRICS ICONMETRICSA
    define SERIALKEYS SERIALKEYSA
    define HIGHCONTRAST HIGHCONTRASTA
    define SOUNDSENTRY SOUNDSENTRYA
    define MONITORINFOEX MONITORINFOEXA

    define AVISTREAMINFO AVISTREAMINFOA
    define AVIFILEINFO  AVIFILEINFOA

    define MIXERCONTROL MIXERCONTROLA
    define WAVEOUTCAPS WAVEOUTCAPSA
    define WAVEOUTCAPS2 WAVEOUTCAPS2A
    define WAVEINCAPS WAVEINCAPSA
    define WAVEINCAPS2 WAVEINCAPS2A
    define MIDIOUTCAPS MIDIOUTCAPSA
    define MIDIOUTCAPS2 MIDIOUTCAPS2A
    define MIDIINCAPS MIDIINCAPSA
    define MIDIINCAPS2 MIDIINCAPS2A
    define AUXCAPS AUXCAPSA
    define AUXCAPS2 AUXCAPS2A
    define MIXERCAPS MIXERCAPSA
    define MIXERCAPS2 MIXERCAPS2A
    define TARGET TARGETA
    define MIXERLINE MIXERLINEA
    define MIXERLINECONTROLS MIXERLINECONTROLSA
    define MIXERCONTROLDETAILS_LISTTEXT MIXERCONTROLDETAILS_LISTTEXTA
    define JOYCAPS JOYCAPSA
    define JOYCAPS2 JOYCAPS2A
    define MCI_OPEN_PARMS MCI_OPEN_PARMSA
    define MCI_INFO_PARMS MCI_INFO_PARMSA
    define MCI_SYSINFO_PARMS MCI_SYSINFO_PARMSA
    define MCI_SAVE_PARMS MCI_SAVE_PARMSA
    define MCI_LOAD_PARMS MCI_LOAD_PARMSA
    define MCI_VD_ESCAPE_PARMS MCI_VD_ESCAPE_PARMSA
    define MCI_WAVE_OPEN_PARMS MCI_WAVE_OPEN_PARMSA
    define MCI_ANIM_OPEN_PARMS MCI_ANIM_OPEN_PARMSA
    define MCI_ANIM_WINDOW_PARMS MCI_ANIM_WINDOW_PARMSA
    define MCI_OVLY_OPEN_PARMS MCI_OVLY_OPEN_PARMSA
    define MCI_OVLY_WINDOW_PARMS MCI_OVLY_WINDOW_PARMSA
    define MCI_OVLY_SAVE_PARMS MCI_OVLY_SAVE_PARMSA
    define MCI_OVLY_LOAD_PARMS MCI_OVLY_LOAD_PARMSA
#endif

#endif ;WINDOWS_INC
