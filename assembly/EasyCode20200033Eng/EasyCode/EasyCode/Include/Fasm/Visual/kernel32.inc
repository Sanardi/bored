; ====================================================;
;                                                     ;
;     kernel32.inc for EC v2 Fasm visual projects     ;
;                   (version 1.0.5)                   ;
;                                                     ;
;         Copyright © Ramon Sala - 2018-2020          ;
;                                                     ;
; ====================================================;

if ~defined KERNEL32_INC
define KERNEL32_INC 1

SIZE_OF_80387_REGISTERS                         equ     80
MAXIMUM_SUPPORTED_EXTENSION                     equ     512

if ~defined EXCEPTION_MAXIMUM_PARAMETERS
    EXCEPTION_MAXIMUM_PARAMETERS                equ     15
end if

ExceptionContinueExecution                      equ     00H
ExceptionContinueSearch                         equ     01H
ExceptionNestedException                        equ     02H
ExceptionCollidedUnwind                         equ     03H

IMAGE_BASE                                      equ     400000H

if  ~defined COORD_DEF
    COORD_DEF equ 1
    struct COORD
        X dw ?
        Y dw ?
    ends
end if

if  ~defined CONSOLE_FONT_INFO_DEF
    CONSOLE_FONT_INFO_DEF equ 1
    struct CONSOLE_FONT_INFO
        nFont      dd    ?
        dwFontSize COORD
    ends
end if

if  ~defined OSVERSIONINFOEX_DEF
    OSVERSIONINFOEX_DEF equ 1
    struct OSVERSIONINFOEXA
        dwOSVersionInfoSize dd ?
        dwMajorVersion      dd ?
        dwMinorVersion      dd ?
        dwBuildNumber       dd ?
        dwPlatformId        dd ?
        szCSDVersion        db 128 dup(?)
        wServicePackMajor   dw  ?
        wServicePackMinor   dw  ?
        wSuiteMask          dw  ?
        wProductType        db  ?
        wReserved           db  ?
    ends
    struct OSVERSIONINFOEXW
        dwOSVersionInfoSize dd ?
        dwMajorVersion      dd ?
        dwMinorVersion      dd ?
        dwBuildNumber       dd ?
        dwPlatformId        dd ?
        szCSDVersion        dw 128 dup(?)
        wServicePackMajor   dw  ?
        wServicePackMinor   dw  ?
        wSuiteMask          dw  ?
        wProductType        db  ?
        wReserved           db  ?
    ends
    api OSVERSIONINFOEX
end if

if ~defined CONTEXT_DEF
    CONTEXT_DEF equ 1
    struct M128A
        Low_    dq ?
        High_   dq ?
    ends

    struct FLOATING_SAVE_AREA
        ControlWord     dd ?
        StatusWord      dd ?
        TagWord         dd ?
        ErrorOffset     dd ?
        ErrorSelector   dd ?
        DataOffset      dd ?
        DataSelector    dd ?
        RegisterArea    db SIZE_OF_80387_REGISTERS dup(?)
        Cr0NpxState     dd ?
    ends

    if defined APP_WIN64
        struct CONTEXT
            P1Home                  dq ?
            P2Home                  dq ?
            P3Home                  dq ?
            P4Home                  dq ?
            P5Home                  dq ?
            P6Home                  dq ?
            ContextFlags            dd ?
            MxCsr                   dd ?
            SegCs                   dw ?
            SegDs                   dw ?
            SegEs                   dw ?
            SegFs                   dw ?
            SegGs                   dw ?
            SegSs                   dw ?
            EFlags                  dd ?
            _Dr0                    dq ?
            _Dr1                    dq ?
            _Dr2                    dq ?
            _Dr3                    dq ?
            _Dr6                    dq ?
            _Dr7                    dq ?
            regRax                  dq ?
            regRcx                  dq ?
            regRdx                  dq ?
            regRbx                  dq ?
            regRsp                  dq ?
            regRbp                  dq ?
            regRsi                  dq ?
            regRdi                  dq ?
            regR8                   dq ?
            regR9                   dq ?
            regR10                  dq ?
            regR11                  dq ?
            regR12                  dq ?
            regR13                  dq ?
            regR14                  dq ?
            regR15                  dq ?
            regRip                  dq ?
            regXmm0                 M128A
            regXmm1                 M128A
            regXmm2                 M128A
            regXmm3                 M128A
            regXmm4                 M128A
            regXmm5                 M128A
            regXmm6                 M128A
            regXmm7                 M128A
            regXmm8                 M128A
            regXmm9                 M128A
            regXmm10                M128A
            regXmm11                M128A
            regXmm12                M128A
            regXmm13                M128A
            regXmm14                M128A
            regXmm15                M128A
            FltSave                 FLOATING_SAVE_AREA
            Fill                    dd ?
            DebugControl            dq ?
            LastBranchToRip         dq ?
            LastBranchFromRip       dq ?
            LastExceptionToRip      dq ?
            LastExceptionFromRip    dq ?
            Fill1                   dq ?
        ends
    else
        struct CONTEXT
            ContextFlags      dd ?
            iDr0              dd ?
            iDr1              dd ?
            iDr2              dd ?
            iDr3              dd ?
            iDr6              dd ?
            iDr7              dd ?
            FloatSave         FLOATING_SAVE_AREA
            regGs             dd ?
            regFs             dd ?
            regEs             dd ?
            regDs             dd ?
            regEdi            dd ?
            regEsi            dd ?
            regEbx            dd ?
            regEdx            dd ?
            regEcx            dd ?
            regEax            dd ?
            regEbp            dd ?
            regEip            dd ?
            regCs             dd ?
            regFlag           dd ?
            regEsp            dd ?
            regSs             dd ?
            ExtendedRegisters db MAXIMUM_SUPPORTED_EXTENSION dup(?)
        ends
    end if
end if

if ~defined DISPATCHER_CONTEXT_DEF
    DISPATCHER_CONTEXT_DEF equ 1
    struct DISPATCHER_CONTEXT
        ControlPc        xptr ? 
        ImageBase        xptr ?
        FunctionEntry    xptr ?
        EstablisherFrame xptr ?
        TargetIp         xptr ?
        ContextRecord    xptr ?
        LanguageHandler  xptr ?
        HandlerData      xptr ?
        HistoryTable     xptr ?
        ScopeIndex       dd   ?
        Fill0            dd   ?
    ends
end if

if ~defined EXCEPTION_RECORD32_DEF
    EXCEPTION_RECORD32_DEF equ 1
    struct EXCEPTION_RECORD32
        ExceptionCode        dd ?
        ExceptionFlags       dd ?
        ExceptionRecord      dd ?
        ExceptionAddress     dd ?
        NumberParameters     dd ?
        ExceptionInformation dd EXCEPTION_MAXIMUM_PARAMETERS dup(?)
    ends
end if

if ~defined EXCEPTION_RECORD64_DEF
    EXCEPTION_RECORD64_DEF equ 1
    struct EXCEPTION_RECORD64
        ExceptionCode        dd ?
        ExceptionFlags       dd ?
        ExceptionRecord      dq ?
        ExceptionAddress     dq ?
        NumberParameters     dd ?
        __unusedAlignment    dd ?
        ExceptionInformation dq EXCEPTION_MAXIMUM_PARAMETERS dup(?)
    ends
end if

if ~defined EXCEPTION_POINTERS_DEF
    EXCEPTION_POINTERS_DEF equ 1
    struct EXCEPTION_POINTERS
        ExceptionRecord xptr ?
        ContextRecord   xptr ?
    ends
end if

struct LIST_ENTRY32
    Flink   dd  ?
    Blink   dd  ?
ends

struct LIST_ENTRY64
    Flink   dq ?
    Blink   dq ?
ends

struct GENERIC_MAPPING
    GenericRead     dd ?
    GenericWrite    dd ?
    GenericExecute  dd ?
    GenericAll      dd ?
ends

if defined APP_WIN64
    if (NTDDI_VERSION >= NTDDI_WINXP)
        extrn '__imp___C_specific_handler' as __C_specific_handler:qword
        extrn '__imp___chkstk' as __chkstk:qword
    end if
    extrn '__imp__hread' as _hread:qword
    extrn '__imp__hwrite' as _hwrite:qword
    extrn '__imp__lclose' as _lclose:qword
    extrn '__imp__lcreat' as _lcreat:qword
    extrn '__imp__llseek' as _llseek:qword
    extrn '__imp__lopen' as _lopen:qword
    extrn '__imp__lread' as _lread:qword
    extrn '__imp__lwrite' as _lwrite:qword
    extrn '__imp_AddAtomA' as AddAtomA:qword
    extrn '__imp_AddAtomW' as AddAtomW:qword
    extrn '__imp_AllocConsole' as AllocConsole:qword
    extrn '__imp_AreFileApisANSI' as AreFileApisANSI:qword
    extrn '__imp_BackupRead' as BackupRead:qword
    extrn '__imp_BackupSeek' as BackupSeek:qword
    extrn '__imp_BackupWrite' as BackupWrite:qword
    extrn '__imp_Beep' as Beep:qword
    extrn '__imp_BeginUpdateResourceA' as BeginUpdateResourceA:qword
    extrn '__imp_BeginUpdateResourceW' as BeginUpdateResourceW:qword
    extrn '__imp_BuildCommDCBA' as BuildCommDCBA:qword
    extrn '__imp_BuildCommDCBAndTimeoutsA' as BuildCommDCBAndTimeoutsA:qword
    extrn '__imp_BuildCommDCBAndTimeoutsW' as BuildCommDCBAndTimeoutsW:qword
    extrn '__imp_BuildCommDCBW' as BuildCommDCBW:qword
    extrn '__imp_CallNamedPipeA' as CallNamedPipeA:qword
    extrn '__imp_CallNamedPipeW' as CallNamedPipeW:qword
    extrn '__imp_ClearCommBreak' as ClearCommBreak:qword
    extrn '__imp_ClearCommError' as ClearCommError:qword
    extrn '__imp_CloseHandle' as CloseHandle:qword
    extrn '__imp_CloseProfileUserMapping' as CloseProfileUserMapping:qword
    extrn '__imp_CommConfigDialogA' as CommConfigDialogA:qword
    extrn '__imp_CommConfigDialogW' as CommConfigDialogW:qword
    extrn '__imp_CompareFileTime' as CompareFileTime:qword
    extrn '__imp_CompareStringA' as CompareStringA:qword
    extrn '__imp_CompareStringW' as CompareStringW:qword
    extrn '__imp_ConnectNamedPipe' as ConnectNamedPipe:qword
    extrn '__imp_ContinueDebugEvent' as ContinueDebugEvent:qword
    extrn '__imp_ConvertDefaultLocale' as ConvertDefaultLocale:qword
    extrn '__imp_CopyFileA' as CopyFileA:qword
    extrn '__imp_CopyFileW' as CopyFileW:qword
    extrn '__imp_CreateConsoleScreenBuffer' as CreateConsoleScreenBuffer:qword
    extrn '__imp_CreateDirectoryA' as CreateDirectoryA:qword
    extrn '__imp_CreateDirectoryExA' as CreateDirectoryExA:qword
    extrn '__imp_CreateDirectoryExW' as CreateDirectoryExW:qword
    extrn '__imp_CreateDirectoryW' as CreateDirectoryW:qword
    extrn '__imp_CreateEventA' as CreateEventA:qword
    extrn '__imp_CreateEventW' as CreateEventW:qword
    extrn '__imp_CreateFileA' as CreateFileA:qword
    extrn '__imp_CreateFileMappingA' as CreateFileMappingA:qword
    extrn '__imp_CreateFileMappingW' as CreateFileMappingW:qword
    extrn '__imp_CreateFileW' as CreateFileW:qword
    extrn '__imp_CreateIoCompletionPort' as CreateIoCompletionPort:qword
    extrn '__imp_CreateMailslotA' as CreateMailslotA:qword
    extrn '__imp_CreateMailslotW' as CreateMailslotW:qword
    extrn '__imp_CreateMutexA' as CreateMutexA:qword
    extrn '__imp_CreateMutexW' as CreateMutexW:qword
    extrn '__imp_CreateNamedPipeA' as CreateNamedPipeA:qword
    extrn '__imp_CreateNamedPipeW' as CreateNamedPipeW:qword
    extrn '__imp_CreatePipe' as CreatePipe:qword
    extrn '__imp_CreateProcessA' as CreateProcessA:qword
    extrn '__imp_CreateProcessW' as CreateProcessW:qword
    extrn '__imp_CreateRemoteThread' as CreateRemoteThread:qword
    extrn '__imp_CreateSemaphoreA' as CreateSemaphoreA:qword
    extrn '__imp_CreateSemaphoreW' as CreateSemaphoreW:qword
    extrn '__imp_CreateTapePartition' as CreateTapePartition:qword
    extrn '__imp_CreateThread' as CreateThread:qword
    extrn '__imp_CreateToolhelp32Snapshot' as CreateToolhelp32Snapshot:qword
    extrn '__imp_DebugActiveProcess' as DebugActiveProcess:qword
    extrn '__imp_DebugBreak' as DebugBreak:qword
    extrn '__imp_DefineDosDeviceA' as DefineDosDeviceA:qword
    extrn '__imp_DefineDosDeviceW' as DefineDosDeviceW:qword
    extrn '__imp_DeleteAtom' as DeleteAtom:qword
    extrn '__imp_DeleteCriticalSection' as DeleteCriticalSection:qword
    extrn '__imp_DeleteFileA' as DeleteFileA:qword
    extrn '__imp_DeleteFileW' as DeleteFileW:qword
    extrn '__imp_DeviceIoControl' as DeviceIoControl:qword
    extrn '__imp_DisableThreadLibraryCalls' as DisableThreadLibraryCalls:qword
    extrn '__imp_DisconnectNamedPipe' as DisconnectNamedPipe:qword
    extrn '__imp_DosDateTimeToFileTime' as DosDateTimeToFileTime:qword
    extrn '__imp_DuplicateHandle' as DuplicateHandle:qword
    extrn '__imp_EndUpdateResourceA' as EndUpdateResourceA:qword
    extrn '__imp_EndUpdateResourceW' as EndUpdateResourceW:qword
    extrn '__imp_EnterCriticalSection' as EnterCriticalSection:qword
    extrn '__imp_EnumCalendarInfoA' as EnumCalendarInfoA:qword
    extrn '__imp_EnumCalendarInfoW' as EnumCalendarInfoW:qword
    extrn '__imp_EnumDateFormatsA' as EnumDateFormatsA:qword
    extrn '__imp_EnumDateFormatsW' as EnumDateFormatsW:qword
    extrn '__imp_EnumResourceLanguagesA' as EnumResourceLanguagesA:qword
    extrn '__imp_EnumResourceLanguagesW' as EnumResourceLanguagesW:qword
    extrn '__imp_EnumResourceNamesA' as EnumResourceNamesA:qword
    extrn '__imp_EnumResourceNamesW' as EnumResourceNamesW:qword
    extrn '__imp_EnumResourceTypesA' as EnumResourceTypesA:qword
    extrn '__imp_EnumResourceTypesW' as EnumResourceTypesW:qword
    extrn '__imp_EnumSystemCodePagesA' as EnumSystemCodePagesA:qword
    extrn '__imp_EnumSystemCodePagesW' as EnumSystemCodePagesW:qword
    extrn '__imp_EnumSystemLocalesA' as EnumSystemLocalesA:qword
    extrn '__imp_EnumSystemLocalesW' as EnumSystemLocalesW:qword
    extrn '__imp_EnumTimeFormatsA' as EnumTimeFormatsA:qword
    extrn '__imp_EnumTimeFormatsW' as EnumTimeFormatsW:qword
    extrn '__imp_EraseTape' as EraseTape:qword
    extrn '__imp_EscapeCommFunction' as EscapeCommFunction:qword
    extrn '__imp_ExitProcess' as ExitProcess:qword
    extrn '__imp_ExitThread' as ExitThread:qword
    extrn '__imp_ExpandEnvironmentStringsA' as ExpandEnvironmentStringsA:qword
    extrn '__imp_ExpandEnvironmentStringsW' as ExpandEnvironmentStringsW:qword
    extrn '__imp_FatalAppExitA' as FatalAppExitA:qword
    extrn '__imp_FatalAppExitW' as FatalAppExitW:qword
    extrn '__imp_FatalExit' as FatalExit:qword
    extrn '__imp_FileTimeToDosDateTime' as FileTimeToDosDateTime:qword
    extrn '__imp_FileTimeToLocalFileTime' as FileTimeToLocalFileTime:qword
    extrn '__imp_FileTimeToSystemTime' as FileTimeToSystemTime:qword
    extrn '__imp_FillConsoleOutputAttribute' as FillConsoleOutputAttribute:qword
    extrn '__imp_FillConsoleOutputCharacterA' as FillConsoleOutputCharacterA:qword
    extrn '__imp_FillConsoleOutputCharacterW' as FillConsoleOutputCharacterW:qword
    extrn '__imp_FindAtomA' as FindAtomA:qword
    extrn '__imp_FindAtomW' as FindAtomW:qword
    extrn '__imp_FindClose' as FindClose:qword
    extrn '__imp_FindCloseChangeNotification' as FindCloseChangeNotification:qword
    extrn '__imp_FindFirstChangeNotificationA' as FindFirstChangeNotificationA:qword
    extrn '__imp_FindFirstChangeNotificationW' as FindFirstChangeNotificationW:qword
    extrn '__imp_FindFirstFileA' as FindFirstFileA:qword
    extrn '__imp_FindFirstFileW' as FindFirstFileW:qword
    extrn '__imp_FindNextChangeNotification' as FindNextChangeNotification:qword
    extrn '__imp_FindNextFileA' as FindNextFileA:qword
    extrn '__imp_FindNextFileW' as FindNextFileW:qword
    extrn '__imp_FindResourceA' as FindResourceA:qword
    extrn '__imp_FindResourceExA' as FindResourceExA:qword
    extrn '__imp_FindResourceExW' as FindResourceExW:qword
    extrn '__imp_FindResourceW' as FindResourceW:qword
    extrn '__imp_FlushConsoleInputBuffer' as FlushConsoleInputBuffer:qword
    extrn '__imp_FlushFileBuffers' as FlushFileBuffers:qword
    extrn '__imp_FlushInstructionCache' as FlushInstructionCache:qword
    extrn '__imp_FlushViewOfFile' as FlushViewOfFile:qword
    extrn '__imp_FoldStringA' as FoldStringA:qword
    extrn '__imp_FoldStringW' as FoldStringW:qword
    extrn '__imp_FormatMessageA' as FormatMessageA:qword
    extrn '__imp_FormatMessageW' as FormatMessageW:qword
    extrn '__imp_FreeConsole' as FreeConsole:qword
    extrn '__imp_FreeEnvironmentStringsA' as FreeEnvironmentStringsA:qword
    extrn '__imp_FreeEnvironmentStringsW' as FreeEnvironmentStringsW:qword
    extrn '__imp_FreeLibrary' as FreeLibrary:qword
    extrn '__imp_FreeLibraryAndExitThread' as FreeLibraryAndExitThread:qword
    extrn '__imp_FreeResource' as FreeResource:qword
    extrn '__imp_GenerateConsoleCtrlEvent' as GenerateConsoleCtrlEvent:qword
    extrn '__imp_GetACP' as GetACP:qword
    extrn '__imp_GetAtomNameA' as GetAtomNameA:qword
    extrn '__imp_GetAtomNameW' as GetAtomNameW:qword
    extrn '__imp_GetBinaryTypeA' as GetBinaryTypeA:qword
    extrn '__imp_GetBinaryTypeW' as GetBinaryTypeW:qword
    extrn '__imp_GetCommandLineA' as GetCommandLineA:qword
    extrn '__imp_GetCommandLineW' as GetCommandLineW:qword
    extrn '__imp_GetCommConfig' as GetCommConfig:qword
    extrn '__imp_GetCommMask' as GetCommMask:qword
    extrn '__imp_GetCommModemStatus' as GetCommModemStatus:qword
    extrn '__imp_GetCommProperties' as GetCommProperties:qword
    extrn '__imp_GetCommState' as GetCommState:qword
    extrn '__imp_GetCommTimeouts' as GetCommTimeouts:qword
    extrn '__imp_GetCompressedFileSizeA' as GetCompressedFileSizeA:qword
    extrn '__imp_GetCompressedFileSizeW' as GetCompressedFileSizeW:qword
    extrn '__imp_GetComputerNameA' as GetComputerNameA:qword
    extrn '__imp_GetComputerNameW' as GetComputerNameW:qword
    extrn '__imp_GetConsoleCP' as GetConsoleCP:qword
    extrn '__imp_GetConsoleCursorInfo' as GetConsoleCursorInfo:qword
    extrn '__imp_GetConsoleMode' as GetConsoleMode:qword
    extrn '__imp_GetConsoleOutputCP' as GetConsoleOutputCP:qword
    extrn '__imp_GetConsoleScreenBufferInfo' as GetConsoleScreenBufferInfo:qword
    extrn '__imp_GetConsoleTitleA' as GetConsoleTitleA:qword
    extrn '__imp_GetConsoleTitleW' as GetConsoleTitleW:qword
    extrn '__imp_GetCPInfo' as GetCPInfo:qword
    extrn '__imp_GetCurrencyFormatA' as GetCurrencyFormatA:qword
    extrn '__imp_GetCurrencyFormatW' as GetCurrencyFormatW:qword
    extrn '__imp_GetCurrentDirectoryA' as GetCurrentDirectoryA:qword
    extrn '__imp_GetCurrentDirectoryW' as GetCurrentDirectoryW:qword
    extrn '__imp_GetCurrentProcess' as GetCurrentProcess:qword
    extrn '__imp_GetCurrentProcessId' as GetCurrentProcessId:qword
    extrn '__imp_GetCurrentThread' as GetCurrentThread:qword
    extrn '__imp_GetCurrentThreadId' as GetCurrentThreadId:qword
    extrn '__imp_GetDateFormatA' as GetDateFormatA:qword
    extrn '__imp_GetDateFormatW' as GetDateFormatW:qword
    extrn '__imp_GetDefaultCommConfigA' as GetDefaultCommConfigA:qword
    extrn '__imp_GetDefaultCommConfigW' as GetDefaultCommConfigW:qword
    extrn '__imp_GetDiskFreeSpaceA' as GetDiskFreeSpaceA:qword
    extrn '__imp_GetDiskFreeSpaceExA' as GetDiskFreeSpaceExA:qword
    extrn '__imp_GetDiskFreeSpaceExW' as GetDiskFreeSpaceExW:qword
    extrn '__imp_GetDiskFreeSpaceW' as GetDiskFreeSpaceW:qword
    extrn '__imp_GetDriveTypeA' as GetDriveTypeA:qword
    extrn '__imp_GetDriveTypeW' as GetDriveTypeW:qword
    extrn '__imp_GetEnvironmentStringsA' as GetEnvironmentStringsA:qword
    extrn '__imp_GetEnvironmentStringsW' as GetEnvironmentStringsW:qword
    extrn '__imp_GetEnvironmentVariableA' as GetEnvironmentVariableA:qword
    extrn '__imp_GetEnvironmentVariableW' as GetEnvironmentVariableW:qword
    if (NTDDI_VERSION = NTDDI_WIN95 | NTDDI_VERSION = NTDDI_WIN98_ME | NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_GetErrorMode' as GetErrorMode:qword
    end if
    extrn '__imp_GetExitCodeProcess' as GetExitCodeProcess:qword
    extrn '__imp_GetExitCodeThread' as GetExitCodeThread:qword
    extrn '__imp_GetFileAttributesA' as GetFileAttributesA:qword
    extrn '__imp_GetFileAttributesW' as GetFileAttributesW:qword
    extrn '__imp_GetFileInformationByHandle' as GetFileInformationByHandle:qword
    extrn '__imp_GetFileSize' as GetFileSize:qword
    extrn '__imp_GetFileTime' as GetFileTime:qword
    extrn '__imp_GetFileType' as GetFileType:qword
    extrn '__imp_GetFullPathNameA' as GetFullPathNameA:qword
    extrn '__imp_GetFullPathNameW' as GetFullPathNameW:qword
    extrn '__imp_GetHandleInformation' as GetHandleInformation:qword
    extrn '__imp_GetLargestConsoleWindowSize' as GetLargestConsoleWindowSize:qword
    extrn '__imp_GetLastError' as GetLastError:qword
    extrn '__imp_GetLocaleInfoA' as GetLocaleInfoA:qword
    extrn '__imp_GetLocaleInfoW' as GetLocaleInfoW:qword
    extrn '__imp_GetLocalTime' as GetLocalTime:qword
    extrn '__imp_GetLogicalDrives' as GetLogicalDrives:qword
    extrn '__imp_GetLogicalDriveStringsA' as GetLogicalDriveStringsA:qword
    extrn '__imp_GetLogicalDriveStringsW' as GetLogicalDriveStringsW:qword
    extrn '__imp_GetMailslotInfo' as GetMailslotInfo:qword
    extrn '__imp_GetModuleFileNameA' as GetModuleFileNameA:qword
    extrn '__imp_GetModuleFileNameW' as GetModuleFileNameW:qword
    extrn '__imp_GetModuleHandleA' as GetModuleHandleA:qword
    extrn '__imp_GetModuleHandleW' as GetModuleHandleW:qword
    extrn '__imp_GetNamedPipeHandleStateA' as GetNamedPipeHandleStateA:qword
    extrn '__imp_GetNamedPipeHandleStateW' as GetNamedPipeHandleStateW:qword
    extrn '__imp_GetNamedPipeInfo' as GetNamedPipeInfo:qword
    extrn '__imp_GetNumberFormatA' as GetNumberFormatA:qword
    extrn '__imp_GetNumberFormatW' as GetNumberFormatW:qword
    extrn '__imp_GetNumberOfConsoleInputEvents' as GetNumberOfConsoleInputEvents:qword
    extrn '__imp_GetNumberOfConsoleMouseButtons' as GetNumberOfConsoleMouseButtons:qword
    extrn '__imp_GetOEMCP' as GetOEMCP:qword
    extrn '__imp_GetOverlappedResult' as GetOverlappedResult:qword
    extrn '__imp_GetPriorityClass' as GetPriorityClass:qword
    extrn '__imp_GetPrivateProfileIntA' as GetPrivateProfileIntA:qword
    extrn '__imp_GetPrivateProfileIntW' as GetPrivateProfileIntW:qword
    extrn '__imp_GetPrivateProfileSectionA' as GetPrivateProfileSectionA:qword
    extrn '__imp_GetPrivateProfileSectionNamesA' as GetPrivateProfileSectionNamesA:qword
    extrn '__imp_GetPrivateProfileSectionNamesW' as GetPrivateProfileSectionNamesW:qword
    extrn '__imp_GetPrivateProfileSectionW' as GetPrivateProfileSectionW:qword
    extrn '__imp_GetPrivateProfileStringA' as GetPrivateProfileStringA:qword
    extrn '__imp_GetPrivateProfileStringW' as GetPrivateProfileStringW:qword
    extrn '__imp_GetPrivateProfileStructA' as GetPrivateProfileStructA:qword
    extrn '__imp_GetPrivateProfileStructW' as GetPrivateProfileStructW:qword
    extrn '__imp_GetProcAddress' as GetProcAddress:qword
    extrn '__imp_GetProcessAffinityMask' as GetProcessAffinityMask:qword
    extrn '__imp_GetProcessHeap' as GetProcessHeap:qword
    extrn '__imp_GetProcessHeaps' as GetProcessHeaps:qword
    extrn '__imp_GetProcessShutdownParameters' as GetProcessShutdownParameters:qword
    extrn '__imp_GetProcessTimes' as GetProcessTimes:qword
    extrn '__imp_GetProcessVersion' as GetProcessVersion:qword
    extrn '__imp_GetProcessWorkingSetSize' as GetProcessWorkingSetSize:qword
    extrn '__imp_GetProfileIntA' as GetProfileIntA:qword
    extrn '__imp_GetProfileIntW' as GetProfileIntW:qword
    extrn '__imp_GetProfileSectionA' as GetProfileSectionA:qword
    extrn '__imp_GetProfileSectionW' as GetProfileSectionW:qword
    extrn '__imp_GetProfileStringA' as GetProfileStringA:qword
    extrn '__imp_GetProfileStringW' as GetProfileStringW:qword
    extrn '__imp_GetQueuedCompletionStatus' as GetQueuedCompletionStatus:qword
    extrn '__imp_GetShortPathNameA' as GetShortPathNameA:qword
    extrn '__imp_GetShortPathNameW' as GetShortPathNameW:qword
    extrn '__imp_GetStartupInfoA' as GetStartupInfoA:qword
    extrn '__imp_GetStartupInfoW' as GetStartupInfoW:qword
    extrn '__imp_GetStdHandle' as GetStdHandle:qword
    extrn '__imp_GetStringTypeA' as GetStringTypeA:qword
    extrn '__imp_GetStringTypeExA' as GetStringTypeExA:qword
    extrn '__imp_GetStringTypeExW' as GetStringTypeExW:qword
    extrn '__imp_GetStringTypeW' as GetStringTypeW:qword
    extrn '__imp_GetSystemDefaultLangID' as GetSystemDefaultLangID:qword
    extrn '__imp_GetSystemDefaultLCID' as GetSystemDefaultLCID:qword
    extrn '__imp_GetSystemDirectoryA' as GetSystemDirectoryA:qword
    extrn '__imp_GetSystemDirectoryW' as GetSystemDirectoryW:qword
    extrn '__imp_GetSystemInfo' as GetSystemInfo:qword
    extrn '__imp_GetSystemPowerStatus' as GetSystemPowerStatus:qword
    extrn '__imp_GetSystemTime' as GetSystemTime:qword
    extrn '__imp_GetSystemTimeAdjustment' as GetSystemTimeAdjustment:qword
    extrn '__imp_GetSystemTimeAsFileTime' as GetSystemTimeAsFileTime:qword
    extrn '__imp_GetTapeParameters' as GetTapeParameters:qword
    extrn '__imp_GetTapePosition' as GetTapePosition:qword
    extrn '__imp_GetTapeStatus' as GetTapeStatus:qword
    extrn '__imp_GetTempFileNameA' as GetTempFileNameA:qword
    extrn '__imp_GetTempFileNameW' as GetTempFileNameW:qword
    extrn '__imp_GetTempPathA' as GetTempPathA:qword
    extrn '__imp_GetTempPathW' as GetTempPathW:qword
    extrn '__imp_GetThreadContext' as GetThreadContext:qword
    extrn '__imp_GetThreadLocale' as GetThreadLocale:qword
    extrn '__imp_GetThreadPriority' as GetThreadPriority:qword
    extrn '__imp_GetThreadSelectorEntry' as GetThreadSelectorEntry:qword
    extrn '__imp_GetThreadTimes' as GetThreadTimes:qword
    extrn '__imp_GetTickCount' as GetTickCount:qword
    extrn '__imp_GetTimeFormatA' as GetTimeFormatA:qword
    extrn '__imp_GetTimeFormatW' as GetTimeFormatW:qword
    extrn '__imp_GetTimeZoneInformation' as GetTimeZoneInformation:qword
    extrn '__imp_GetUserDefaultLangID' as GetUserDefaultLangID:qword
    extrn '__imp_GetUserDefaultLCID' as GetUserDefaultLCID:qword
    extrn '__imp_GetVersion' as GetVersion:qword
    extrn '__imp_GetVersionExA' as GetVersionExA:qword
    extrn '__imp_GetVersionExW' as GetVersionExW:qword
    extrn '__imp_GetVolumeInformationA' as GetVolumeInformationA:qword
    extrn '__imp_GetVolumeInformationW' as GetVolumeInformationW:qword
    extrn '__imp_GetWindowsDirectoryA' as GetWindowsDirectoryA:qword
    extrn '__imp_GetWindowsDirectoryW' as GetWindowsDirectoryW:qword
    extrn '__imp_GlobalAddAtomA' as GlobalAddAtomA:qword
    extrn '__imp_GlobalAddAtomW' as GlobalAddAtomW:qword
    extrn '__imp_GlobalAlloc' as GlobalAlloc:qword
    extrn '__imp_GlobalCompact' as GlobalCompact:qword
    extrn '__imp_GlobalDeleteAtom' as GlobalDeleteAtom:qword
    extrn '__imp_GlobalFindAtomA' as GlobalFindAtomA:qword
    extrn '__imp_GlobalFindAtomW' as GlobalFindAtomW:qword
    extrn '__imp_GlobalFix' as GlobalFix:qword
    extrn '__imp_GlobalFlags' as GlobalFlags:qword
    extrn '__imp_GlobalFree' as GlobalFree:qword
    extrn '__imp_GlobalGetAtomNameA' as GlobalGetAtomNameA:qword
    extrn '__imp_GlobalGetAtomNameW' as GlobalGetAtomNameW:qword
    extrn '__imp_GlobalHandle' as GlobalHandle:qword
    extrn '__imp_GlobalLock' as GlobalLock:qword
    extrn '__imp_GlobalMemoryStatus' as GlobalMemoryStatus:qword
    extrn '__imp_GlobalReAlloc' as GlobalReAlloc:qword
    extrn '__imp_GlobalSize' as GlobalSize:qword
    extrn '__imp_GlobalUnfix' as GlobalUnfix:qword
    extrn '__imp_GlobalUnlock' as GlobalUnlock:qword
    extrn '__imp_GlobalUnWire' as GlobalUnWire:qword
    extrn '__imp_GlobalWire' as GlobalWire:qword
    extrn '__imp_Heap32First' as Heap32First:qword
    extrn '__imp_Heap32ListFirst' as Heap32ListFirst:qword
    extrn '__imp_Heap32ListNext' as Heap32ListNext:qword
    extrn '__imp_Heap32Next' as Heap32Next:qword
    extrn '__imp_HeapAlloc' as HeapAlloc:qword
    extrn '__imp_HeapCompact' as HeapCompact:qword
    extrn '__imp_HeapCreate' as HeapCreate:qword
    extrn '__imp_HeapDestroy' as HeapDestroy:qword
    extrn '__imp_HeapFree' as HeapFree:qword
    extrn '__imp_HeapLock' as HeapLock:qword
    extrn '__imp_HeapReAlloc' as HeapReAlloc:qword
    extrn '__imp_HeapSize' as HeapSize:qword
    extrn '__imp_HeapUnlock' as HeapUnlock:qword
    extrn '__imp_HeapValidate' as HeapValidate:qword
    extrn '__imp_HeapWalk' as HeapWalk:qword
    extrn '__imp_InitAtomTable' as InitAtomTable:qword
    extrn '__imp_InitializeCriticalSection' as InitializeCriticalSection:qword
    extrn '__imp_IsBadCodePtr' as IsBadCodePtr:qword
    extrn '__imp_IsBadHugeReadPtr' as IsBadHugeReadPtr:qword
    extrn '__imp_IsBadHugeWritePtr' as IsBadHugeWritePtr:qword
    extrn '__imp_IsBadReadPtr' as IsBadReadPtr:qword
    extrn '__imp_IsBadStringPtrA' as IsBadStringPtrA:qword
    extrn '__imp_IsBadStringPtrW' as IsBadStringPtrW:qword
    extrn '__imp_IsBadWritePtr' as IsBadWritePtr:qword
    extrn '__imp_IsDBCSLeadByte' as IsDBCSLeadByte:qword
    extrn '__imp_IsDBCSLeadByteEx' as IsDBCSLeadByteEx:qword
    extrn '__imp_IsValidCodePage' as IsValidCodePage:qword
    extrn '__imp_IsValidLocale' as IsValidLocale:qword
    extrn '__imp_LCMapStringA' as LCMapStringA:qword
    extrn '__imp_LCMapStringW' as LCMapStringW:qword
    extrn '__imp_LeaveCriticalSection' as LeaveCriticalSection:qword
    extrn '__imp_LoadLibraryA' as LoadLibraryA:qword
    extrn '__imp_LoadLibraryExA' as LoadLibraryExA:qword
    extrn '__imp_LoadLibraryExW' as LoadLibraryExW:qword
    extrn '__imp_LoadLibraryW' as LoadLibraryW:qword
    extrn '__imp_LoadModule' as LoadModule:qword
    extrn '__imp_LoadResource' as LoadResource:qword
    extrn '__imp_LocalAlloc' as LocalAlloc:qword
    extrn '__imp_LocalCompact' as LocalCompact:qword
    extrn '__imp_LocalFileTimeToFileTime' as LocalFileTimeToFileTime:qword
    extrn '__imp_LocalFlags' as LocalFlags:qword
    extrn '__imp_LocalFree' as LocalFree:qword
    extrn '__imp_LocalHandle' as LocalHandle:qword
    extrn '__imp_LocalLock' as LocalLock:qword
    extrn '__imp_LocalReAlloc' as LocalReAlloc:qword
    extrn '__imp_LocalShrink' as LocalShrink:qword
    extrn '__imp_LocalSize' as LocalSize:qword
    extrn '__imp_LocalUnlock' as LocalUnlock:qword
    extrn '__imp_LockFile' as LockFile:qword
    extrn '__imp_LockFileEx' as LockFileEx:qword
    extrn '__imp_LockResource' as LockResource:qword
    extrn '__imp_lstrcatA' as lstrcatA:qword
    extrn '__imp_lstrcatW' as lstrcatW:qword
    extrn '__imp_lstrcmpA' as lstrcmpA:qword
    extrn '__imp_lstrcmpiA' as lstrcmpiA:qword
    extrn '__imp_lstrcmpiW' as lstrcmpiW:qword
    extrn '__imp_lstrcmpW' as lstrcmpW:qword
    extrn '__imp_lstrcpyA' as lstrcpyA:qword
    extrn '__imp_lstrcpynA' as lstrcpynA:qword
    extrn '__imp_lstrcpynW' as lstrcpynW:qword
    extrn '__imp_lstrcpyW' as lstrcpyW:qword
    extrn '__imp_lstrlenA' as lstrlenA:qword
    extrn '__imp_lstrlenW' as lstrlenW:qword
    extrn '__imp_MapViewOfFile' as MapViewOfFile:qword
    extrn '__imp_MapViewOfFileEx' as MapViewOfFileEx:qword
    extrn '__imp_MoveFileA' as MoveFileA:qword
    extrn '__imp_MoveFileExA' as MoveFileExA:qword
    extrn '__imp_MoveFileExW' as MoveFileExW:qword
    extrn '__imp_MoveFileW' as MoveFileW:qword
    extrn '__imp_MulDiv' as MulDiv:qword
    extrn '__imp_MultiByteToWideChar' as MultiByteToWideChar:qword
    extrn '__imp_OpenEventA' as OpenEventA:qword
    extrn '__imp_OpenEventW' as OpenEventW:qword
    extrn '__imp_OpenFile' as OpenFile:qword
    extrn '__imp_OpenFileMappingA' as OpenFileMappingA:qword
    extrn '__imp_OpenFileMappingW' as OpenFileMappingW:qword
    extrn '__imp_OpenMutexA' as OpenMutexA:qword
    extrn '__imp_OpenMutexW' as OpenMutexW:qword
    extrn '__imp_OpenProcess' as OpenProcess:qword
    extrn '__imp_OpenProfileUserMapping' as OpenProfileUserMapping:qword
    extrn '__imp_OpenSemaphoreA' as OpenSemaphoreA:qword
    extrn '__imp_OpenSemaphoreW' as OpenSemaphoreW:qword
    extrn '__imp_OutputDebugStringA' as OutputDebugStringA:qword
    extrn '__imp_OutputDebugStringW' as OutputDebugStringW:qword
    extrn '__imp_PeekConsoleInputA' as PeekConsoleInputA:qword
    extrn '__imp_PeekConsoleInputW' as PeekConsoleInputW:qword
    extrn '__imp_PeekNamedPipe' as PeekNamedPipe:qword
    extrn '__imp_PostQueuedCompletionStatus' as PostQueuedCompletionStatus:qword
    extrn '__imp_PrepareTape' as PrepareTape:qword
    extrn '__imp_PulseEvent' as PulseEvent:qword
    extrn '__imp_PurgeComm' as PurgeComm:qword
    extrn '__imp_QueryDosDeviceA' as QueryDosDeviceA:qword
    extrn '__imp_QueryDosDeviceW' as QueryDosDeviceW:qword
    extrn '__imp_QueryPerformanceCounter' as QueryPerformanceCounter:qword
    extrn '__imp_QueryPerformanceFrequency' as QueryPerformanceFrequency:qword
    extrn '__imp_QueueUserAPC' as QueueUserAPC:qword
    extrn '__imp_RaiseException' as RaiseException:qword
    extrn '__imp_ReadConsoleA' as ReadConsoleA:qword
    extrn '__imp_ReadConsoleInputA' as ReadConsoleInputA:qword
    extrn '__imp_ReadConsoleInputW' as ReadConsoleInputW:qword
    extrn '__imp_ReadConsoleOutputA' as ReadConsoleOutputA:qword
    extrn '__imp_ReadConsoleOutputAttribute' as ReadConsoleOutputAttribute:qword
    extrn '__imp_ReadConsoleOutputCharacterA' as ReadConsoleOutputCharacterA:qword
    extrn '__imp_ReadConsoleOutputCharacterW' as ReadConsoleOutputCharacterW:qword
    extrn '__imp_ReadConsoleOutputW' as ReadConsoleOutputW:qword
    extrn '__imp_ReadConsoleW' as ReadConsoleW:qword
    extrn '__imp_ReadFile' as ReadFile:qword
    extrn '__imp_ReadFileEx' as ReadFileEx:qword
    extrn '__imp_ReadProcessMemory' as ReadProcessMemory:qword
    extrn '__imp_ReleaseMutex' as ReleaseMutex:qword
    extrn '__imp_ReleaseSemaphore' as ReleaseSemaphore:qword
    extrn '__imp_RemoveDirectoryA' as RemoveDirectoryA:qword
    extrn '__imp_RemoveDirectoryW' as RemoveDirectoryW:qword
    extrn '__imp_ResetEvent' as ResetEvent:qword
    extrn '__imp_ResumeThread' as ResumeThread:qword
    extrn '__imp_RtlFillMemory' as RtlFillMemory:qword
    extrn '__imp_RtlMoveMemory' as RtlMoveMemory:qword
    extrn '__imp_RtlUnwind' as RtlUnwind:qword
    extrn '__imp_RtlZeroMemory' as RtlZeroMemory:qword
    extrn '__imp_ScrollConsoleScreenBufferA' as ScrollConsoleScreenBufferA:qword
    extrn '__imp_ScrollConsoleScreenBufferW' as ScrollConsoleScreenBufferW:qword
    extrn '__imp_SearchPathA' as SearchPathA:qword
    extrn '__imp_SearchPathW' as SearchPathW:qword
    extrn '__imp_SetCommBreak' as SetCommBreak:qword
    extrn '__imp_SetCommConfig' as SetCommConfig:qword
    extrn '__imp_SetCommMask' as SetCommMask:qword
    extrn '__imp_SetCommState' as SetCommState:qword
    extrn '__imp_SetCommTimeouts' as SetCommTimeouts:qword
    extrn '__imp_SetComputerNameA' as SetComputerNameA:qword
    extrn '__imp_SetComputerNameW' as SetComputerNameW:qword
    extrn '__imp_SetConsoleActiveScreenBuffer' as SetConsoleActiveScreenBuffer:qword
    extrn '__imp_SetConsoleCP' as SetConsoleCP:qword
    extrn '__imp_SetConsoleCtrlHandler' as SetConsoleCtrlHandler:qword
    extrn '__imp_SetConsoleCursorInfo' as SetConsoleCursorInfo:qword
    extrn '__imp_SetConsoleCursorPosition' as SetConsoleCursorPosition:qword
    extrn '__imp_SetConsoleMode' as SetConsoleMode:qword
    extrn '__imp_SetConsoleOutputCP' as SetConsoleOutputCP:qword
    extrn '__imp_SetConsoleScreenBufferSize' as SetConsoleScreenBufferSize:qword
    extrn '__imp_SetConsoleTextAttribute' as SetConsoleTextAttribute:qword
    extrn '__imp_SetConsoleTitleA' as SetConsoleTitleA:qword
    extrn '__imp_SetConsoleTitleW' as SetConsoleTitleW:qword
    extrn '__imp_SetConsoleWindowInfo' as SetConsoleWindowInfo:qword
    extrn '__imp_SetCurrentDirectoryA' as SetCurrentDirectoryA:qword
    extrn '__imp_SetCurrentDirectoryW' as SetCurrentDirectoryW:qword
    extrn '__imp_SetDefaultCommConfigA' as SetDefaultCommConfigA:qword
    extrn '__imp_SetDefaultCommConfigW' as SetDefaultCommConfigW:qword
    extrn '__imp_SetEndOfFile' as SetEndOfFile:qword
    extrn '__imp_SetEnvironmentVariableA' as SetEnvironmentVariableA:qword
    extrn '__imp_SetEnvironmentVariableW' as SetEnvironmentVariableW:qword
    extrn '__imp_SetErrorMode' as SetErrorMode:qword
    extrn '__imp_SetEvent' as SetEvent:qword
    extrn '__imp_SetFileApisToANSI' as SetFileApisToANSI:qword
    extrn '__imp_SetFileApisToOEM' as SetFileApisToOEM:qword
    extrn '__imp_SetFileAttributesA' as SetFileAttributesA:qword
    extrn '__imp_SetFileAttributesW' as SetFileAttributesW:qword
    extrn '__imp_SetFilePointer' as SetFilePointer:qword
    extrn '__imp_SetFileTime' as SetFileTime:qword
    extrn '__imp_SetHandleCount' as SetHandleCount:qword
    extrn '__imp_SetHandleInformation' as SetHandleInformation:qword
    extrn '__imp_SetLastError' as SetLastError:qword
    extrn '__imp_SetLocaleInfoA' as SetLocaleInfoA:qword
    extrn '__imp_SetLocaleInfoW' as SetLocaleInfoW:qword
    extrn '__imp_SetLocalTime' as SetLocalTime:qword
    extrn '__imp_SetMailslotInfo' as SetMailslotInfo:qword
    extrn '__imp_SetNamedPipeHandleState' as SetNamedPipeHandleState:qword
    extrn '__imp_SetPriorityClass' as SetPriorityClass:qword
    extrn '__imp_SetProcessShutdownParameters' as SetProcessShutdownParameters:qword
    extrn '__imp_SetProcessWorkingSetSize' as SetProcessWorkingSetSize:qword
    extrn '__imp_SetStdHandle' as SetStdHandle:qword
    extrn '__imp_SetSystemPowerState' as SetSystemPowerState:qword
    extrn '__imp_SetSystemTime' as SetSystemTime:qword
    extrn '__imp_SetSystemTimeAdjustment' as SetSystemTimeAdjustment:qword
    extrn '__imp_SetTapeParameters' as SetTapeParameters:qword
    extrn '__imp_SetTapePosition' as SetTapePosition:qword
    extrn '__imp_SetThreadAffinityMask' as SetThreadAffinityMask:qword
    extrn '__imp_SetThreadContext' as SetThreadContext:qword
    extrn '__imp_SetThreadLocale' as SetThreadLocale:qword
    extrn '__imp_SetThreadPriority' as SetThreadPriority:qword
    extrn '__imp_SetTimeZoneInformation' as SetTimeZoneInformation:qword
    extrn '__imp_SetUnhandledExceptionFilter' as SetUnhandledExceptionFilter:qword
    extrn '__imp_SetupComm' as SetupComm:qword
    extrn '__imp_SetVolumeLabelA' as SetVolumeLabelA:qword
    extrn '__imp_SetVolumeLabelW' as SetVolumeLabelW:qword
    extrn '__imp_SizeofResource' as SizeofResource:qword
    extrn '__imp_Sleep' as Sleep:qword
    extrn '__imp_SleepEx' as SleepEx:qword
    extrn '__imp_SuspendThread' as SuspendThread:qword
    extrn '__imp_SystemTimeToFileTime' as SystemTimeToFileTime:qword
    extrn '__imp_SystemTimeToTzSpecificLocalTime' as SystemTimeToTzSpecificLocalTime:qword
    extrn '__imp_TerminateProcess' as TerminateProcess:qword
    extrn '__imp_TerminateThread' as TerminateThread:qword
    extrn '__imp_Thread32First' as Thread32First:qword
    extrn '__imp_Thread32Next' as Thread32Next:qword
    extrn '__imp_TlsAlloc' as TlsAlloc:qword
    extrn '__imp_TlsFree' as TlsFree:qword
    extrn '__imp_TlsGetValue' as TlsGetValue:qword
    extrn '__imp_TlsSetValue' as TlsSetValue:qword
    extrn '__imp_Toolhelp32ReadProcessMemory' as Toolhelp32ReadProcessMemory:qword
    extrn '__imp_TransactNamedPipe' as TransactNamedPipe:qword
    extrn '__imp_TransmitCommChar' as TransmitCommChar:qword
    extrn '__imp_UnhandledExceptionFilter' as UnhandledExceptionFilter:qword
    extrn '__imp_UnlockFile' as UnlockFile:qword
    extrn '__imp_UnlockFileEx' as UnlockFileEx:qword
    extrn '__imp_UnmapViewOfFile' as UnmapViewOfFile:qword
    extrn '__imp_UpdateResourceA' as UpdateResourceA:qword
    extrn '__imp_UpdateResourceW' as UpdateResourceW:qword
    extrn '__imp_VirtualAlloc' as VirtualAlloc:qword
    extrn '__imp_VirtualFree' as VirtualFree:qword
    extrn '__imp_VirtualLock' as VirtualLock:qword
    extrn '__imp_VirtualProtect' as VirtualProtect:qword
    extrn '__imp_VirtualProtectEx' as VirtualProtectEx:qword
    extrn '__imp_VirtualQuery' as VirtualQuery:qword
    extrn '__imp_VirtualQueryEx' as VirtualQueryEx:qword
    extrn '__imp_VirtualUnlock' as VirtualUnlock:qword
    extrn '__imp_WaitCommEvent' as WaitCommEvent:qword
    extrn '__imp_WaitForDebugEvent' as WaitForDebugEvent:qword
    extrn '__imp_WaitForMultipleObjects' as WaitForMultipleObjects:qword
    extrn '__imp_WaitForMultipleObjectsEx' as WaitForMultipleObjectsEx:qword
    extrn '__imp_WaitForSingleObject' as WaitForSingleObject:qword
    extrn '__imp_WaitForSingleObjectEx' as WaitForSingleObjectEx:qword
    extrn '__imp_WaitNamedPipeA' as WaitNamedPipeA:qword
    extrn '__imp_WaitNamedPipeW' as WaitNamedPipeW:qword
    extrn '__imp_WideCharToMultiByte' as WideCharToMultiByte:qword
    extrn '__imp_WinExec' as WinExec:qword
    extrn '__imp_WriteConsoleA' as WriteConsoleA:qword
    extrn '__imp_WriteConsoleInputA' as WriteConsoleInputA:qword
    extrn '__imp_WriteConsoleInputW' as WriteConsoleInputW:qword
    extrn '__imp_WriteConsoleOutputA' as WriteConsoleOutputA:qword
    extrn '__imp_WriteConsoleOutputAttribute' as WriteConsoleOutputAttribute:qword
    extrn '__imp_WriteConsoleOutputCharacterA' as WriteConsoleOutputCharacterA:qword
    extrn '__imp_WriteConsoleOutputCharacterW' as WriteConsoleOutputCharacterW:qword
    extrn '__imp_WriteConsoleOutputW' as WriteConsoleOutputW:qword
    extrn '__imp_WriteConsoleW' as WriteConsoleW:qword
    extrn '__imp_WriteFile' as WriteFile:qword
    extrn '__imp_WriteFileEx' as WriteFileEx:qword
    extrn '__imp_WritePrivateProfileSectionA' as WritePrivateProfileSectionA:qword
    extrn '__imp_WritePrivateProfileSectionW' as WritePrivateProfileSectionW:qword
    extrn '__imp_WritePrivateProfileStringA' as WritePrivateProfileStringA:qword
    extrn '__imp_WritePrivateProfileStringW' as WritePrivateProfileStringW:qword
    extrn '__imp_WritePrivateProfileStructA' as WritePrivateProfileStructA:qword
    extrn '__imp_WritePrivateProfileStructW' as WritePrivateProfileStructW:qword
    extrn '__imp_WriteProcessMemory' as WriteProcessMemory:qword
    extrn '__imp_WriteProfileSectionA' as WriteProfileSectionA:qword
    extrn '__imp_WriteProfileSectionW' as WriteProfileSectionW:qword
    extrn '__imp_WriteProfileStringA' as WriteProfileStringA:qword
    extrn '__imp_WriteProfileStringW' as WriteProfileStringW:qword
    extrn '__imp_WriteTapemark' as WriteTapemark:qword

    GetFreeSpace equ GlobalMemoryStatus

    LockSegment equ GlobalFix
    UnlockSegment equ GlobalUnfix
    GetCurrentTime equ GetTickCount
    MoveMemory equ RtlMoveMemory
    FillMemory equ RtlFillMemory
    ZeroMemory equ RtlZeroMemory

    if (NTDDI_VERSION >= NTDDI_WIN98_ME)
        extrn '__imp_CancelDeviceWakeupRequest' as CancelDeviceWakeupRequest:qword
        extrn '__imp_CancelIo' as CancelIo:qword
        extrn '__imp_ConvertThreadToFiber' as ConvertThreadToFiber:qword
        extrn '__imp_CopyFileExA' as CopyFileExA:qword
        extrn '__imp_CopyFileExW' as CopyFileExW:qword
        extrn '__imp_CreateFiber' as CreateFiber:qword
        extrn '__imp_CreateWaitableTimerA' as CreateWaitableTimerA:qword
        extrn '__imp_CreateWaitableTimerW' as CreateWaitableTimerW:qword
        extrn '__imp_DeleteFiber' as DeleteFiber:qword
        extrn '__imp_EnumCalendarInfoExA' as EnumCalendarInfoExA:qword
        extrn '__imp_EnumCalendarInfoExW' as EnumCalendarInfoExW:qword
        extrn '__imp_EnumDateFormatsExA' as EnumDateFormatsExA:qword
        extrn '__imp_EnumDateFormatsExW' as EnumDateFormatsExW:qword
        extrn '__imp_FindFirstFileExA' as FindFirstFileExA:qword
        extrn '__imp_FindFirstFileExW' as FindFirstFileExW:qword
        extrn '__imp_GetCalendarInfoA' as GetCalendarInfoA:qword
        extrn '__imp_GetCalendarInfoW' as GetCalendarInfoW:qword
        extrn '__imp_GetCPInfoExA' as GetCPInfoExA:qword
        extrn '__imp_GetCPInfoExW' as GetCPInfoExW:qword
        extrn '__imp_GetDevicePowerState' as GetDevicePowerState:qword
        extrn '__imp_GetFileAttributesExA' as GetFileAttributesExA:qword
        extrn '__imp_GetFileAttributesExW' as GetFileAttributesExW:qword
        if (NTDDI_VERSION >= NTDDI_WINNT4)
            extrn '__imp_GetLongPathNameA' as GetLongPathNameA:qword
            extrn '__imp_GetLongPathNameW' as GetLongPathNameW:qword
            extrn '__imp_RequestDeviceWakeup' as RequestDeviceWakeup:qword
            extrn '__imp_RequestWakeupLatency' as RequestWakeupLatency:qword
            extrn '__imp_ResetWriteWatch' as ResetWriteWatch:qword
            extrn '__imp_SetCalendarInfoA' as SetCalendarInfoA:qword
            extrn '__imp_SetCalendarInfoW' as SetCalendarInfoW:qword
            extrn '__imp_SetMessageWaitingIndicator' as SetMessageWaitingIndicator:qword
            api GetLongPathName,\
                SetCalendarInfo
        end if
        extrn '__imp_GetProcessPriorityBoost' as GetProcessPriorityBoost:qword
        extrn '__imp_GetThreadPriorityBoost' as GetThreadPriorityBoost:qword
        extrn '__imp_IsDebuggerPresent' as IsDebuggerPresent:qword
        extrn '__imp_IsProcessorFeaturePresent' as IsProcessorFeaturePresent:qword
        extrn '__imp_IsSystemResumeAutomatic' as IsSystemResumeAutomatic:qword
        extrn '__imp_OpenWaitableTimerA' as OpenWaitableTimerA:qword
        extrn '__imp_OpenWaitableTimerW' as OpenWaitableTimerW:qword
        extrn '__imp_ReadDirectoryChangesW' as ReadDirectoryChangesW:qword
        extrn '__imp_ReadFileScatter' as ReadFileScatter:qword
        extrn '__imp_SetCriticalSectionSpinCount' as SetCriticalSectionSpinCount:qword
        extrn '__imp_SetProcessAffinityMask' as SetProcessAffinityMask:qword
        extrn '__imp_SetProcessPriorityBoost' as SetProcessPriorityBoost:qword
        extrn '__imp_SetThreadExecutionState' as SetThreadExecutionState:qword
        extrn '__imp_SetThreadIdealProcessor' as SetThreadIdealProcessor:qword
        extrn '__imp_SetThreadPriorityBoost' as SetThreadPriorityBoost:qword
        extrn '__imp_SetWaitableTimer' as SetWaitableTimer:qword
        extrn '__imp_SignalObjectAndWait' as SignalObjectAndWait:qword
        extrn '__imp_SwitchToFiber' as SwitchToFiber:qword
        extrn '__imp_SwitchToThread' as SwitchToThread:qword
        extrn '__imp_VirtualAllocEx' as VirtualAllocEx:qword
        extrn '__imp_VirtualFreeEx' as VirtualFreeEx:qword
        extrn '__imp_WriteFileGather' as WriteFileGather:qword
        api CopyFileEx,\
            CreateWaitableTimer,\
            EnumCalendarInfoEx,\
            EnumDateFormatsEx,\
            FindFirstFileEx,\
            GetCalendarInfo,\
            GetCPInfoEx,\
            GetFileAttributesEx,\
            OpenWaitableTimer
    end if

    if (NTDDI_VERSION >= NTDDI_WINNT4)
        extrn '__imp_AddConsoleAliasA' as AddConsoleAliasA:qword
        extrn '__imp_AddConsoleAliasW' as AddConsoleAliasW:qword
        extrn '__imp_ConsoleMenuControl' as ConsoleMenuControl:qword
        extrn '__imp_CreateTimerQueue' as CreateTimerQueue:qword
        extrn '__imp_DuplicateConsoleHandle' as DuplicateConsoleHandle:qword
        extrn '__imp_ExitVDM' as ExitVDM:qword
        extrn '__imp_ExpungeConsoleCommandHistoryA' as ExpungeConsoleCommandHistoryA:qword
        extrn '__imp_ExpungeConsoleCommandHistoryW' as ExpungeConsoleCommandHistoryW:qword
        extrn '__imp_GetConsoleAliasA' as GetConsoleAliasA:qword
        extrn '__imp_GetConsoleAliasesA' as GetConsoleAliasesA:qword
        extrn '__imp_GetConsoleAliasesW' as GetConsoleAliasesW:qword
        extrn '__imp_GetConsoleAliasesLengthA' as GetConsoleAliasesLengthA:qword
        extrn '__imp_GetConsoleAliasesLengthW' as GetConsoleAliasesLengthW:qword
        extrn '__imp_GetConsoleAliasExesA' as GetConsoleAliasExesA:qword
        extrn '__imp_GetConsoleAliasExesW' as GetConsoleAliasExesW:qword
        extrn '__imp_GetConsoleAliasExesLengthA' as GetConsoleAliasExesLengthA:qword
        extrn '__imp_GetConsoleAliasExesLengthW' as GetConsoleAliasExesLengthW:qword
        extrn '__imp_GetConsoleAliasW' as GetConsoleAliasW:qword
        extrn '__imp_GetModuleHandleExA' as GetModuleHandleExA:qword
        extrn '__imp_GetModuleHandleExW' as GetModuleHandleExW:qword
        extrn '__imp_GetNextVDMCommand' as GetNextVDMCommand:qword
        extrn '__imp_GetNumberOfConsoleFonts' as GetNumberOfConsoleFonts:qword
        extrn '__imp_GetProcessIoCounters' as GetProcessIoCounters:qword
        extrn '__imp_GetVDMCurrentDirectories' as GetVDMCurrentDirectories:qword
        extrn '__imp_InvalidateConsoleDIBits' as InvalidateConsoleDIBits:qword
        extrn '__imp_OpenConsoleW' as OpenConsoleW:qword
        extrn '__imp_ReadConsoleInputExA' as ReadConsoleInputExA:qword
        extrn '__imp_ReadConsoleInputExW' as ReadConsoleInputExW:qword
        extrn '__imp_SetConsoleCursor' as SetConsoleCursor:qword
        extrn '__imp_SetConsoleHardwareState' as SetConsoleHardwareState:qword
        extrn '__imp_SetConsoleIcon' as SetConsoleIcon:qword
        extrn '__imp_SetConsoleMaximumWindowSize' as SetConsoleMaximumWindowSize:qword
        extrn '__imp_SetConsoleNumberOfCommandsA' as SetConsoleNumberOfCommandsA:qword
        extrn '__imp_SetConsoleNumberOfCommandsW' as SetConsoleNumberOfCommandsW:qword
        extrn '__imp_SetConsolePalette' as SetConsolePalette:qword
        extrn '__imp_SetLastConsoleEventActive' as SetLastConsoleEventActive:qword
        extrn '__imp_SetVDMCurrentDirectories' as SetVDMCurrentDirectories:qword
        extrn '__imp_ShowConsoleCursor' as ShowConsoleCursor:qword
        extrn '__imp_VerifyVersionInfoA' as VerifyVersionInfoA:qword
        extrn '__imp_VerifyVersionInfoW' as VerifyVersionInfoW:qword
        api AddConsoleAlias,\
            ExpungeConsoleCommandHistory,\
            GetConsoleAlias,\
            GetConsoleAliasExes,\
            GetConsoleAliasExesLength,\
            GetConsoleAliases,\
            GetConsoleAliasesLength,\
            GetModuleHandleEx,\
            ReadConsoleInputEx,\
            SetConsoleNumberOfCommands,\
            VerifyVersionInfo
    end if

    if (NTDDI_VERSION >= NTDDI_WIN2K)
        extrn '__imp_AllocateUserPhysicalPages' as AllocateUserPhysicalPages:qword
        extrn '__imp_AssignProcessToJobObject' as AssignProcessToJobObject:qword
        extrn '__imp_BindIoCompletionCallback' as BindIoCompletionCallback:qword
        extrn '__imp_ChangeTimerQueueTimer' as ChangeTimerQueueTimer:qword
        extrn '__imp_CreateHardLinkA' as CreateHardLinkA:qword
        extrn '__imp_CreateHardLinkW' as CreateHardLinkW:qword
        extrn '__imp_CreateJobObjectA' as CreateJobObjectA:qword
        extrn '__imp_CreateJobObjectW' as CreateJobObjectW:qword
        extrn '__imp_CreateTimerQueueTimer' as CreateTimerQueueTimer:qword
        extrn '__imp_DelayLoadFailureHook' as DelayLoadFailureHook:qword
        extrn '__imp_DeleteTimerQueue' as DeleteTimerQueue:qword
        extrn '__imp_DeleteVolumeMountPointA' as DeleteVolumeMountPointA:qword
        extrn '__imp_DeleteVolumeMountPointW' as DeleteVolumeMountPointW:qword
        extrn '__imp_DnsHostnameToComputerNameA' as DnsHostnameToComputerNameA:qword
        extrn '__imp_DnsHostnameToComputerNameW' as DnsHostnameToComputerNameW:qword
        extrn '__imp_DosPathToSessionPathA' as DosPathToSessionPathA:qword
        extrn '__imp_DosPathToSessionPathW' as DosPathToSessionPathW:qword
        extrn '__imp_EnumLanguageGroupLocalesA' as EnumLanguageGroupLocalesA:qword
        extrn '__imp_EnumLanguageGroupLocalesW' as EnumLanguageGroupLocalesW:qword
        extrn '__imp_EnumSystemLanguageGroupsA' as EnumSystemLanguageGroupsA:qword
        extrn '__imp_EnumSystemLanguageGroupsW' as EnumSystemLanguageGroupsW:qword
        extrn '__imp_EnumUILanguagesA' as EnumUILanguagesA:qword
        extrn '__imp_EnumUILanguagesW' as EnumUILanguagesW:qword
        extrn '__imp_FindFirstVolumeA' as FindFirstVolumeA:qword
        extrn '__imp_FindFirstVolumeMountPointA' as FindFirstVolumeMountPointA:qword
        extrn '__imp_FindFirstVolumeMountPointW' as FindFirstVolumeMountPointW:qword
        extrn '__imp_FindFirstVolumeW' as FindFirstVolumeW:qword
        extrn '__imp_FindNextVolumeA' as FindNextVolumeA:qword
        extrn '__imp_FindNextVolumeMountPointA' as FindNextVolumeMountPointA:qword
        extrn '__imp_FindNextVolumeMountPointW' as FindNextVolumeMountPointW:qword
        extrn '__imp_FindNextVolumeW' as FindNextVolumeW:qword
        extrn '__imp_FindVolumeClose' as FindVolumeClose:qword
        extrn '__imp_FindVolumeMountPointClose' as FindVolumeMountPointClose:qword
        extrn '__imp_FreeUserPhysicalPages' as FreeUserPhysicalPages:qword
        extrn '__imp_GetComputerNameExA' as GetComputerNameExA:qword
        extrn '__imp_GetComputerNameExW' as GetComputerNameExW:qword
        extrn '__imp_GetConsoleNlsMode' as GetConsoleNlsMode:qword
        extrn '__imp_GetConsoleWindow' as GetConsoleWindow:qword
        extrn '__imp_GetFileSizeEx' as GetFileSizeEx:qword
        extrn '__imp_GetSystemDefaultUILanguage' as GetSystemDefaultUILanguage:qword
        extrn '__imp_GetSystemWindowsDirectoryA' as GetSystemWindowsDirectoryA:qword
        extrn '__imp_GetSystemWindowsDirectoryW' as GetSystemWindowsDirectoryW:qword
        extrn '__imp_GetUserDefaultUILanguage' as GetUserDefaultUILanguage:qword
        extrn '__imp_GetVolumeNameForVolumeMountPointA' as GetVolumeNameForVolumeMountPointA:qword
        extrn '__imp_GetVolumeNameForVolumeMountPointW' as GetVolumeNameForVolumeMountPointW:qword
        extrn '__imp_GetVolumePathNameA' as GetVolumePathNameA:qword
        extrn '__imp_GetVolumePathNameW' as GetVolumePathNameW:qword
        extrn '__imp_GlobalMemoryStatusEx' as GlobalMemoryStatusEx:qword
        extrn '__imp_IsValidLanguageGroup' as IsValidLanguageGroup:qword
        extrn '__imp_MapUserPhysicalPages' as MapUserPhysicalPages:qword
        extrn '__imp_MapUserPhysicalPagesScatter' as MapUserPhysicalPagesScatter:qword
        extrn '__imp_MoveFileWithProgressA' as MoveFileWithProgressA:qword
        extrn '__imp_MoveFileWithProgressW' as MoveFileWithProgressW:qword
        extrn '__imp_OpenJobObjectA' as OpenJobObjectA:qword
        extrn '__imp_OpenJobObjectW' as OpenJobObjectW:qword
        extrn '__imp_OpenThread' as OpenThread:qword
        extrn '__imp_PrivCopyFileExW' as PrivCopyFileExW:qword
        extrn '__imp_ProcessIdToSessionId' as ProcessIdToSessionId:qword
        extrn '__imp_QueryInformationJobObject' as QueryInformationJobObject:qword
        extrn '__imp_RegisterWaitForSingleObject' as RegisterWaitForSingleObject:qword
        extrn '__imp_ReplaceFileA' as ReplaceFileA:qword
        extrn '__imp_ReplaceFileW' as ReplaceFileW:qword
        extrn '__imp_SetComputerNameExA' as SetComputerNameExA:qword
        extrn '__imp_SetComputerNameExW' as SetComputerNameExW:qword
        extrn '__imp_SetConsoleNlsMode' as SetConsoleNlsMode:qword
        extrn '__imp_SetConsoleOS2OemFormat' as SetConsoleOS2OemFormat:qword
        extrn '__imp_SetFilePointerEx' as SetFilePointerEx:qword
        extrn '__imp_SetInformationJobObject' as SetInformationJobObject:qword
        extrn '__imp_SetTermsrvAppInstallMode' as SetTermsrvAppInstallMode:qword
        extrn '__imp_SetTimerQueueTimer' as SetTimerQueueTimer:qword
        extrn '__imp_SetVolumeMountPointA' as SetVolumeMountPointA:qword
        extrn '__imp_SetVolumeMountPointW' as SetVolumeMountPointW:qword
        extrn '__imp_TerminateJobObject' as TerminateJobObject:qword
        extrn '__imp_UnregisterWait' as UnregisterWait:qword
        extrn '__imp_VerSetConditionMask' as VerSetConditionMask:qword
        api CreateHardLink,\
            CreateJobObject,\
            DeleteVolumeMountPoint,\
            DnsHostnameToComputerName,\
            DosPathToSessionPath,\
            EnumLanguageGroupLocales,\
            EnumSystemLanguageGroups,\
            EnumUILanguages,\
            FindActCtxSectionString,\
            FindFirstVolume,\
            FindFirstVolumeMountPoint,\
            FindNextVolume,\
            FindNextVolumeMountPoint,\
            GetComputerNameEx,\
            GetSystemWindowsDirectory,\
            GetVolumeNameForVolumeMountPoint,\
            GetVolumePathName,\
            MoveFileWithProgress,\
            OpenJobObject,\
            ReplaceFile,\
            SetComputerNameEx,\
            SetVolumeMountPoint
    end if

    if (NTDDI_VERSION >= NTDDI_WINXP)
        extrn '__imp_ActivateActCtx' as ActivateActCtx:qword
        extrn '__imp_AddLocalAlternateComputerNameA' as AddLocalAlternateComputerNameA:qword
        extrn '__imp_AddLocalAlternateComputerNameW' as AddLocalAlternateComputerNameW:qword
        extrn '__imp_AddRefActCtx' as AddRefActCtx:qword
        extrn '__imp_AddVectoredExceptionHandler' as AddVectoredExceptionHandler:qword
        extrn '__imp_AttachConsole' as AttachConsole:qword
        extrn '__imp_CancelWaitableTimer' as CancelWaitableTimer:qword
        extrn '__imp_ConvertFiberToThread' as ConvertFiberToThread:qword
        extrn '__imp_CreateActCtxA' as CreateActCtxA:qword
        extrn '__imp_CreateActCtxW' as CreateActCtxW:qword
        extrn '__imp_CreateFiberEx' as CreateFiberEx:qword
        extrn '__imp_CreateJobSet' as CreateJobSet:qword
        extrn '__imp_CreateMemoryResourceNotification' as CreateMemoryResourceNotification:qword
        extrn '__imp_CreateProcessInternalA' as CreateProcessInternalA:qword
        extrn '__imp_CreateProcessInternalW' as CreateProcessInternalW:qword
        extrn '__imp_DeactivateActCtx' as DeactivateActCtx:qword
        extrn '__imp_DebugActiveProcessStop' as DebugActiveProcessStop:qword
        extrn '__imp_DebugBreakProcess' as DebugBreakProcess:qword
        extrn '__imp_DebugSetProcessKillOnExit' as DebugSetProcessKillOnExit:qword
        extrn '__imp_DeleteTimerQueueEx' as DeleteTimerQueueEx:qword
        extrn '__imp_DeleteTimerQueueTimer' as DeleteTimerQueueTimer:qword
        extrn '__imp_EnumerateLocalComputerNamesA' as EnumerateLocalComputerNamesA:qword
        extrn '__imp_EnumerateLocalComputerNamesW' as EnumerateLocalComputerNamesW:qword
        extrn '__imp_EnumSystemGeoID' as EnumSystemGeoID:qword
        extrn '__imp_FindActCtxSectionGuid' as FindActCtxSectionGuid:qword
        extrn '__imp_FindActCtxSectionStringA' as FindActCtxSectionStringA:qword
        extrn '__imp_FindActCtxSectionStringW' as FindActCtxSectionStringW:qword
        extrn '__imp_FlsAlloc' as FlsAlloc:qword
        extrn '__imp_FlsFree' as FlsFree:qword
        extrn '__imp_FlsGetValue' as FlsGetValue:qword
        extrn '__imp_FlsSetValue' as FlsSetValue:qword
        extrn '__imp_GetConsoleDisplayMode' as GetConsoleDisplayMode:qword
        extrn '__imp_GetConsoleFontInfo' as GetConsoleFontInfo:qword
        extrn '__imp_GetConsoleFontSize' as GetConsoleFontSize:qword
        extrn '__imp_GetConsoleProcessList' as GetConsoleProcessList:qword
        extrn '__imp_GetConsoleSelectionInfo' as GetConsoleSelectionInfo:qword
        extrn '__imp_GetCurrentActCtx' as GetCurrentActCtx:qword
        extrn '__imp_GetCurrentConsoleFont' as GetCurrentConsoleFont:qword
        extrn '__imp_GetDllDirectoryA' as GetDllDirectoryA:qword
        extrn '__imp_GetDllDirectoryW' as GetDllDirectoryW:qword
        extrn '__imp_GetGeoInfoA' as GetGeoInfoA:qword
        extrn '__imp_GetGeoInfoW' as GetGeoInfoW:qword
        extrn '__imp_GetNativeSystemInfo' as GetNativeSystemInfo:qword
        extrn '__imp_GetProcessId' as GetProcessId:qword
        extrn '__imp_GetSystemWow64DirectoryA' as GetSystemWow64DirectoryA:qword
        extrn '__imp_GetSystemWow64DirectoryW' as GetSystemWow64DirectoryW:qword
        extrn '__imp_GetThreadId' as GetThreadId:qword
        extrn '__imp_GetUserGeoID' as GetUserGeoID:qword
        extrn '__imp_GetVolumePathNamesForVolumeNameA' as GetVolumePathNamesForVolumeNameA:qword
        extrn '__imp_GetVolumePathNamesForVolumeNameW' as GetVolumePathNamesForVolumeNameW:qword
        extrn '__imp_GetWriteWatch' as GetWriteWatch:qword
        extrn '__imp_HeapQueryInformation' as HeapQueryInformation:qword
        extrn '__imp_HeapSetInformation' as HeapSetInformation:qword
        extrn '__imp_InitializeCriticalSectionAndSpinCount' as InitializeCriticalSectionAndSpinCount:qword
        extrn '__imp_InitializeSListHead' as InitializeSListHead:qword
        extrn '__imp_InterlockedFlushSList' as InterlockedFlushSList:qword
        extrn '__imp_InterlockedPopEntrySList' as InterlockedPopEntrySList:qword
        extrn '__imp_InterlockedPushEntrySList' as InterlockedPushEntrySList:qword
        extrn '__imp_IsProcessInJob' as IsProcessInJob:qword
        extrn '__imp_Module32First' as Module32First:qword
        extrn '__imp_Module32FirstW' as Module32FirstW:qword
        extrn '__imp_Module32Next' as Module32Next:qword
        extrn '__imp_Module32NextW' as Module32NextW:qword
        extrn '__imp_Process32First' as Process32First:qword
        extrn '__imp_Process32FirstW' as Process32FirstW:qword
        extrn '__imp_Process32Next' as Process32Next:qword
        extrn '__imp_Process32NextW' as Process32NextW:qword
        extrn '__imp_QueryActCtxW' as QueryActCtxW:qword
        extrn '__imp_QueryDepthSList' as QueryDepthSList:qword
        extrn '__imp_QueryMemoryResourceNotification' as QueryMemoryResourceNotification:qword
        extrn '__imp_QueueUserWorkItem' as QueueUserWorkItem:qword
        extrn '__imp_ReleaseActCtx' as ReleaseActCtx:qword
        extrn '__imp_RemoveVectoredExceptionHandler' as RemoveVectoredExceptionHandler:qword
        if (NTDDI_VERSION >= NTDDI_WIN8)
            extrn '__imp_ResolveDelayLoadedAPI' as ResolveDelayLoadedAPI:qword
            extrn '__imp_ResolveDelayLoadsFromDll' as ResolveDelayLoadsFromDll:qword
        end if
        extrn '__imp_RtlCaptureContext' as RtlCaptureContext:qword
        extrn '__imp_RtlCaptureStackBackTrace' as RtlCaptureStackBackTrace:qword
        extrn '__imp_RtlRaiseException' as RtlRaiseException:qword
        extrn '__imp_SetConsoleDisplayMode' as SetConsoleDisplayMode:qword
        extrn '__imp_SetConsoleFont' as SetConsoleFont:qword
        extrn '__imp_SetFileShortNameA' as SetFileShortNameA:qword
        extrn '__imp_SetFileShortNameW' as SetFileShortNameW:qword
        extrn '__imp_SetFileValidData' as SetFileValidData:qword
        extrn '__imp_SetLocalPrimaryComputerNameA' as SetLocalPrimaryComputerNameA:qword
        extrn '__imp_SetLocalPrimaryComputerNameW' as SetLocalPrimaryComputerNameW:qword
        extrn '__imp_SetThreadUILanguage' as SetThreadUILanguage:qword
        extrn '__imp_SetUserGeoID' as SetUserGeoID:qword
        extrn '__imp_TryEnterCriticalSection' as TryEnterCriticalSection:qword
        extrn '__imp_TzSpecificLocalTimeToSystemTime' as TzSpecificLocalTimeToSystemTime:qword
        extrn '__imp_uaw_lstrcmpiW' as uaw_lstrcmpiW:qword
        extrn '__imp_uaw_lstrcmpW' as uaw_lstrcmpW:qword
        extrn '__imp_uaw_lstrlenW' as uaw_lstrlenW:qword
        extrn '__imp_uaw_wcschr' as uaw_wcschr:qword
        extrn '__imp_uaw_wcscpy' as uaw_wcscpy:qword
        extrn '__imp_uaw_wcsicmp' as uaw_wcsicmp:qword
        extrn '__imp_uaw_wcslen' as uaw_wcslen:qword
        extrn '__imp_uaw_wcsrchr' as uaw_wcsrchr:qword
        extrn '__imp_UnregisterWaitEx' as UnregisterWaitEx:qword
        extrn '__imp_ZombifyActCtx' as ZombifyActCtx:qword

        CaptureStackBackTrace equ RtlCaptureStackBackTrace

        if defined APP_WIN64 | NTDDI_VERSION >= NTDDI_WINXPSP3 | NTDDI_VERSION >= NTDDI_WS03SP1
            extrn '__imp_EnumSystemFirmwareTables' as EnumSystemFirmwareTables:qword
            extrn '__imp_GetLogicalProcessorInformation' as GetLogicalProcessorInformation:qword
            extrn '__imp_GetNumaHighestNodeNumber' as GetNumaHighestNodeNumber:qword
            extrn '__imp_GetSystemFileCacheSize' as GetSystemFileCacheSize:qword
            extrn '__imp_GetSystemFirmwareTable' as GetSystemFirmwareTable:qword
            extrn '__imp_RemoveVectoredContinueHandler' as RemoveVectoredContinueHandler:qword
            extrn '__imp_SetSystemFileCacheSize' as SetSystemFileCacheSize:qword
            extrn '__imp_SetThreadStackGuarantee' as SetThreadStackGuarantee:qword
            extrn '__imp_Wow64DisableWow64FsRedirection' as Wow64DisableWow64FsRedirection:qword
            extrn '__imp_Wow64RevertWow64FsRedirection' as Wow64RevertWow64FsRedirection:qword
        end if

        if defined APP_WIN64
            extrn '__imp_RtlAddFunctionTable' as RtlAddFunctionTable:qword
            extrn '__imp_RtlDeleteFunctionTable' as RtlDeleteFunctionTable:qword
            extrn '__imp_RtlInstallFunctionTableCallback' as RtlInstallFunctionTableCallback:qword
            extrn '__imp_RtlLookupFunctionEntry' as RtlLookupFunctionEntry:qword
            extrn '__imp_RtlPcToFileHeader' as RtlPcToFileHeader:qword
            extrn '__imp_RtlRestoreContext' as RtlRestoreContext:qword
            extrn '__imp_RtlUnwindEx' as RtlUnwindEx:qword
            extrn '__imp_RtlVirtualUnwind' as RtlVirtualUnwind:qword
        else
            extrn '__imp_RtlVirtualUnwind' as RtlVirtualUnwind:qword
        end if

        api AddLocalAlternateComputerName,\
            CreateActCtx,\
            CreateProcessInternal,\
            EnumerateLocalComputerNames,\
            GetDllDirectory,\
            GetGeoInfo,\
            GetSystemWow64Directory,\
            GetVolumePathNamesForVolumeName,\
            SetFileShortName,\
            SetLocalPrimaryComputerName
    end if

    if (NTDDI_VERSION >= NTDDI_WINXPSP1)
        extrn '__imp_CheckNameLegalDOS8Dot3A' as CheckNameLegalDOS8Dot3A:qword
        extrn '__imp_CheckNameLegalDOS8Dot3W' as CheckNameLegalDOS8Dot3W:qword
        extrn '__imp_CheckRemoteDebuggerPresent' as CheckRemoteDebuggerPresent:qword
        extrn '__imp_ConvertThreadToFiberEx' as ConvertThreadToFiberEx:qword
        extrn '__imp_GetFirmwareEnvironmentVariableA' as GetFirmwareEnvironmentVariableA:qword
        extrn '__imp_GetFirmwareEnvironmentVariableW' as GetFirmwareEnvironmentVariableW:qword
        extrn '__imp_GetProcessHandleCount' as GetProcessHandleCount:qword
        extrn '__imp_GetSystemRegistryQuota' as GetSystemRegistryQuota:qword
        extrn '__imp_GetSystemTimes' as GetSystemTimes:qword
        extrn '__imp_GetThreadIOPendingFlag' as GetThreadIOPendingFlag:qword
        extrn '__imp_SetFirmwareEnvironmentVariableA' as SetFirmwareEnvironmentVariableA:qword
        extrn '__imp_SetFirmwareEnvironmentVariableW' as SetFirmwareEnvironmentVariableW:qword
        api CheckNameLegalDOS8Dot3,\
            GetFirmwareEnvironmentVariable,\
            SetFirmwareEnvironmentVariable
    end if

    if (NTDDI_VERSION >= NTDDI_WINXPSP2)
        extrn '__imp_GetNumaAvailableMemoryNode' as GetNumaAvailableMemoryNode:qword
        extrn '__imp_GetNumaNodeProcessorMask' as GetNumaNodeProcessorMask:qword
        extrn '__imp_GetNumaProcessorNode' as GetNumaProcessorNode:qword
    end if

    if (NTDDI_VERSION >= NTDDI_WINXPSP2 | NTDDI_VERSION >= NTDDI_WS03SP1)
        extrn '__imp_DecodePointer' as DecodePointer:qword
        extrn '__imp_DecodeSystemPointer' as DecodeSystemPointer:qword
        extrn '__imp_EncodePointer' as EncodePointer:qword
        extrn '__imp_EncodeSystemPointer' as EncodeSystemPointer:qword
        extrn '__imp_IsWow64Process' as IsWow64Process:qword
    end if

    if (NTDDI_VERSION >= NTDDI_WINXPSP3)
        extrn '__imp_GetSystemDEPPolicy' as GetSystemDEPPolicy:qword
        extrn '__imp_GetProcessDEPPolicy' as GetProcessDEPPolicy:qword
        extrn '__imp_SetProcessDEPPolicy' as SetProcessDEPPolicy:qword
    end if

    if (NTDDI_VERSION >= NTDDI_WS03)
        extrn '__imp_FindFirstStreamW' as FindFirstStreamW:qword
        extrn '__imp_FindNextStreamW' as FindNextStreamW:qword
        extrn '__imp_GetLargePageMinimum' as GetLargePageMinimum:qword
        extrn '__imp_GetProcessIdOfThread' as GetProcessIdOfThread:qword
        extrn '__imp_GetProcessWorkingSetSizeEx' as GetProcessWorkingSetSizeEx:qword
        extrn '__imp_ReOpenFile' as ReOpenFile:qword
        extrn '__imp_SetDllDirectoryA' as SetDllDirectoryA:qword
        extrn '__imp_SetDllDirectoryW' as SetDllDirectoryW:qword
        extrn '__imp_SetEnvironmentStringsA' as SetEnvironmentStringsA:qword
        extrn '__imp_SetEnvironmentStringsW' as SetEnvironmentStringsW:qword
        extrn '__imp_SetProcessWorkingSetSizeEx' as SetProcessWorkingSetSizeEx:qword
        extrn '__imp_Wow64EnableWow64FsRedirection' as Wow64EnableWow64FsRedirection:qword
        extrn '__imp_WTSGetActiveConsoleSessionId' as WTSGetActiveConsoleSessionId:qword
        api SetDllDirectory,\
            SetEnvironmentStrings
    end if

    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_AcquireSRWLockExclusive' as AcquireSRWLockExclusive:qword
        extrn '__imp_AcquireSRWLockShared' as AcquireSRWLockShared:qword
        extrn '__imp_AddDllDirectory' as AddDllDirectory:qword
        extrn '__imp_AddSIDToBoundaryDescriptor' as AddSIDToBoundaryDescriptor:qword
        extrn '__imp_AddVectoredContinueHandler' as AddVectoredContinueHandler:qword
        extrn '__imp_AdjustCalendarDate' as AdjustCalendarDate:qword
        extrn '__imp_AllocateUserPhysicalPagesNuma' as AllocateUserPhysicalPagesNuma:qword
        extrn '__imp_ApplicationRecoveryFinished' as ApplicationRecoveryFinished:qword
        extrn '__imp_ApplicationRecoveryInProgress' as ApplicationRecoveryInProgress:qword
        extrn '__imp_CallbackMayRunLong' as CallbackMayRunLong:qword
        extrn '__imp_CancelIoEx' as CancelIoEx:qword
        extrn '__imp_CancelSynchronousIo' as CancelSynchronousIo:qword
        extrn '__imp_CancelThreadpoolIo' as CancelThreadpoolIo:qword
        extrn '__imp_CheckElevationEnabled' as CheckElevationEnabled:qword
        extrn '__imp_ClosePrivateNamespace' as ClosePrivateNamespace:qword
        extrn '__imp_CloseThreadpool' as CloseThreadpool:qword
        extrn '__imp_CloseThreadpoolCleanupGroup' as CloseThreadpoolCleanupGroup:qword
        extrn '__imp_CloseThreadpoolCleanupGroupMembers' as CloseThreadpoolCleanupGroupMembers:qword
        extrn '__imp_CloseThreadpoolIo' as CloseThreadpoolIo:qword
        extrn '__imp_CloseThreadpoolTimer' as CloseThreadpoolTimer:qword
        extrn '__imp_CloseThreadpoolWait' as CloseThreadpoolWait:qword
        extrn '__imp_CloseThreadpoolWork' as CloseThreadpoolWork:qword
        extrn '__imp_CompareStringEx' as CompareStringEx:qword
        extrn '__imp_CompareStringOrdinal' as CompareStringOrdinal:qword
        extrn '__imp_ConvertCalDateTimeToSystemTime' as ConvertCalDateTimeToSystemTime:qword
        extrn '__imp_ConvertSystemTimeToCalDateTime' as ConvertSystemTimeToCalDateTime:qword
        extrn '__imp_CopyFileTransactedA' as CopyFileTransactedA:qword
        extrn '__imp_CopyFileTransactedW' as CopyFileTransactedW:qword
        extrn '__imp_CreateBoundaryDescriptorA' as CreateBoundaryDescriptorA:qword
        extrn '__imp_CreateBoundaryDescriptorW' as CreateBoundaryDescriptorW:qword
        extrn '__imp_CreateDirectoryTransactedA' as CreateDirectoryTransactedA:qword
        extrn '__imp_CreateDirectoryTransactedW' as CreateDirectoryTransactedW:qword
        extrn '__imp_CreateEventExA' as CreateEventExA:qword
        extrn '__imp_CreateEventExW' as CreateEventExW:qword
        extrn '__imp_CreateFileMappingNumaA' as CreateFileMappingNumaA:qword
        extrn '__imp_CreateFileMappingNumaW' as CreateFileMappingNumaW:qword
        extrn '__imp_CreateFileTransactedA' as CreateFileTransactedA:qword
        extrn '__imp_CreateFileTransactedW' as CreateFileTransactedW:qword
        extrn '__imp_CreateHardLinkTransactedA' as CreateHardLinkTransactedA:qword
        extrn '__imp_CreateHardLinkTransactedW' as CreateHardLinkTransactedW:qword
        extrn '__imp_CreateMutexExA' as CreateMutexExA:qword
        extrn '__imp_CreateMutexExW' as CreateMutexExW:qword
        extrn '__imp_CreatePrivateNamespaceA' as CreatePrivateNamespaceA:qword
        extrn '__imp_CreatePrivateNamespaceW' as CreatePrivateNamespaceW:qword
        extrn '__imp_CreateSemaphoreExA' as CreateSemaphoreExA:qword
        extrn '__imp_CreateSemaphoreExW' as CreateSemaphoreExW:qword
        extrn '__imp_CreateSymbolicLinkA' as CreateSymbolicLinkA:qword
        extrn '__imp_CreateSymbolicLinkTransactedA' as CreateSymbolicLinkTransactedA:qword
        extrn '__imp_CreateSymbolicLinkTransactedW' as CreateSymbolicLinkTransactedW:qword
        extrn '__imp_CreateSymbolicLinkW' as CreateSymbolicLinkW:qword
        extrn '__imp_CreateThreadpool' as CreateThreadpool:qword
        extrn '__imp_CreateThreadpoolCleanupGroup' as CreateThreadpoolCleanupGroup:qword
        extrn '__imp_CreateThreadpoolIo' as CreateThreadpoolIo:qword
        extrn '__imp_CreateThreadpoolTimer' as CreateThreadpoolTimer:qword
        extrn '__imp_CreateThreadpoolWait' as CreateThreadpoolWait:qword
        extrn '__imp_CreateThreadpoolWork' as CreateThreadpoolWork:qword
        extrn '__imp_CreateWaitableTimerExA' as CreateWaitableTimerExA:qword
        extrn '__imp_CreateWaitableTimerExW' as CreateWaitableTimerExW:qword
        extrn '__imp_DeleteBoundaryDescriptor' as DeleteBoundaryDescriptor:qword
        extrn '__imp_DeleteFileTransactedA' as DeleteFileTransactedA:qword
        extrn '__imp_DeleteFileTransactedW' as DeleteFileTransactedW:qword
        extrn '__imp_DeleteProcThreadAttributeList' as DeleteProcThreadAttributeList:qword
        extrn '__imp_DisassociateCurrentThreadFromCallback' as DisassociateCurrentThreadFromCallback:qword
        extrn '__imp_EnumCalendarInfoExEx' as EnumCalendarInfoExEx:qword
        extrn '__imp_EnumDateFormatsExEx' as EnumDateFormatsExEx:qword
        extrn '__imp_EnumResourceLanguagesExA' as EnumResourceLanguagesExA:qword
        extrn '__imp_EnumResourceLanguagesExW' as EnumResourceLanguagesExW:qword
        extrn '__imp_EnumResourceNamesExA' as EnumResourceNamesExA:qword
        extrn '__imp_EnumResourceNamesExW' as EnumResourceNamesExW:qword
        extrn '__imp_EnumResourceTypesExA' as EnumResourceTypesExA:qword
        extrn '__imp_EnumResourceTypesExW' as EnumResourceTypesExW:qword
        extrn '__imp_EnumSystemLocalesEx' as EnumSystemLocalesEx:qword
        extrn '__imp_EnumTimeFormatsEx' as EnumTimeFormatsEx:qword
        extrn '__imp_FindFirstFileNameTransactedW' as FindFirstFileNameTransactedW:qword
        extrn '__imp_FindFirstFileNameW' as FindFirstFileNameW:qword
        extrn '__imp_FindFirstFileTransactedA' as FindFirstFileTransactedA:qword
        extrn '__imp_FindFirstFileTransactedW' as FindFirstFileTransactedW:qword
        extrn '__imp_FindFirstStreamTransactedW' as FindFirstStreamTransactedW:qword
        extrn '__imp_FindNextFileNameW' as FindNextFileNameW:qword
        extrn '__imp_FindNLSString' as FindNLSString:qword
        extrn '__imp_FindNLSStringEx' as FindNLSStringEx:qword
        extrn '__imp_FlushProcessWriteBuffers' as FlushProcessWriteBuffers:qword
        extrn '__imp_FreeLibraryWhenCallbackReturns' as FreeLibraryWhenCallbackReturns:qword
        extrn '__imp_GetApplicationRecoveryCallback' as GetApplicationRecoveryCallback:qword
        extrn '__imp_GetApplicationRestartSettings' as GetApplicationRestartSettings:qword
        extrn '__imp_GetCalendarDateFormatEx' as GetCalendarDateFormatEx:qword
        extrn '__imp_GetCalendarInfoEx' as GetCalendarInfoEx:qword
        extrn '__imp_GetCalendarSupportedDateRange' as GetCalendarSupportedDateRange:qword
        extrn '__imp_GetComPlusPackageInstallStatus' as GetComPlusPackageInstallStatus:qword
        extrn '__imp_GetCompressedFileSizeTransactedA' as GetCompressedFileSizeTransactedA:qword
        extrn '__imp_GetCompressedFileSizeTransactedW' as GetCompressedFileSizeTransactedW:qword
        extrn '__imp_GetConsoleHistoryInfo' as GetConsoleHistoryInfo:qword
        extrn '__imp_GetConsoleOriginalTitleA' as GetConsoleOriginalTitleA:qword
        extrn '__imp_GetConsoleOriginalTitleW' as GetConsoleOriginalTitleW:qword
        extrn '__imp_GetConsoleScreenBufferInfoEx' as GetConsoleScreenBufferInfoEx:qword
        extrn '__imp_GetCurrencyFormatEx' as GetCurrencyFormatEx:qword
        extrn '__imp_GetCurrentConsoleFontEx' as GetCurrentConsoleFontEx:qword
        extrn '__imp_GetCurrentProcessorNumber' as GetCurrentProcessorNumber:qword
        extrn '__imp_GetDateFormatEx' as GetDateFormatEx:qword
        extrn '__imp_GetDurationFormat' as GetDurationFormat:qword
        extrn '__imp_GetDurationFormatEx' as GetDurationFormatEx:qword
        extrn '__imp_GetDynamicTimeZoneInformation' as GetDynamicTimeZoneInformation:qword
        extrn '__imp_GetFileAttributesTransactedA' as GetFileAttributesTransactedA:qword
        extrn '__imp_GetFileAttributesTransactedW' as GetFileAttributesTransactedW:qword
        extrn '__imp_GetFileBandwidthReservation' as GetFileBandwidthReservation:qword
        extrn '__imp_GetFileInformationByHandleEx' as GetFileInformationByHandleEx:qword
        extrn '__imp_GetFileMUIInfo' as GetFileMUIInfo:qword
        extrn '__imp_GetFileMUIPath' as GetFileMUIPath:qword
        extrn '__imp_GetFinalPathNameByHandleA' as GetFinalPathNameByHandleA:qword
        extrn '__imp_GetFinalPathNameByHandleW' as GetFinalPathNameByHandleW:qword
        extrn '__imp_GetFullPathNameTransactedA' as GetFullPathNameTransactedA:qword
        extrn '__imp_GetFullPathNameTransactedW' as GetFullPathNameTransactedW:qword
        extrn '__imp_GetLocaleInfoEx' as GetLocaleInfoEx:qword
        extrn '__imp_GetLongPathNameTransactedA' as GetLongPathNameTransactedA:qword
        extrn '__imp_GetLongPathNameTransactedW' as GetLongPathNameTransactedW:qword
        extrn '__imp_GetNamedPipeAttribute' as GetNamedPipeAttribute:qword
        extrn '__imp_GetNamedPipeClientComputerNameA' as GetNamedPipeClientComputerNameA:qword
        extrn '__imp_GetNamedPipeClientComputerNameW' as GetNamedPipeClientComputerNameW:qword
        extrn '__imp_GetNamedPipeClientProcessId' as GetNamedPipeClientProcessId:qword
        extrn '__imp_GetNamedPipeClientSessionId' as GetNamedPipeClientSessionId:qword
        extrn '__imp_GetNamedPipeServerProcessId' as GetNamedPipeServerProcessId:qword
        extrn '__imp_GetNamedPipeServerSessionId' as GetNamedPipeServerSessionId:qword
        extrn '__imp_GetNLSVersion' as GetNLSVersion:qword
        extrn '__imp_GetNLSVersionEx' as GetNLSVersionEx:qword
        extrn '__imp_GetNumaProximityNode' as GetNumaProximityNode:qword
        extrn '__imp_GetNumberFormatEx' as GetNumberFormatEx:qword
        extrn '__imp_GetProductInfo' as GetProductInfo:qword
        extrn '__imp_GetQueuedCompletionStatusEx' as GetQueuedCompletionStatusEx:qword
        extrn '__imp_GetStringScripts' as GetStringScripts:qword
        extrn '__imp_GetSystemDefaultLocaleName' as GetSystemDefaultLocaleName:qword
        extrn '__imp_GetSystemPreferredUILanguages' as GetSystemPreferredUILanguages:qword
        extrn '__imp_GetThreadPreferredUILanguages' as GetThreadPreferredUILanguages:qword
        extrn '__imp_GetThreadUILanguage' as GetThreadUILanguage:qword
        extrn '__imp_GetTickCount64' as GetTickCount64:qword
        extrn '__imp_GetTimeFormatEx' as GetTimeFormatEx:qword
        extrn '__imp_GetUILanguageInfo' as GetUILanguageInfo:qword
        extrn '__imp_GetUserDefaultLocaleName' as GetUserDefaultLocaleName:qword
        extrn '__imp_GetUserPreferredUILanguages' as GetUserPreferredUILanguages:qword
        extrn '__imp_GetVolumeInformationByHandleW' as GetVolumeInformationByHandleW:qword
        extrn '__imp_IdnToAscii' as IdnToAscii:qword
        extrn '__imp_IdnToNameprepUnicode' as IdnToNameprepUnicode:qword
        extrn '__imp_IdnToUnicode' as IdnToUnicode:qword
        extrn '__imp_InitOnceBeginInitialize' as InitOnceBeginInitialize:qword
        extrn '__imp_InitOnceComplete' as InitOnceComplete:qword
        extrn '__imp_InitOnceExecuteOnce' as InitOnceExecuteOnce:qword
        extrn '__imp_InitOnceInitialize' as InitOnceInitialize:qword
        extrn '__imp_InitializeConditionVariable' as InitializeConditionVariable:qword
        extrn '__imp_InitializeCriticalSectionEx' as InitializeCriticalSectionEx:qword
        extrn '__imp_InitializeProcThreadAttributeList' as InitializeProcThreadAttributeList:qword
        extrn '__imp_InitializeSRWLock' as InitializeSRWLock:qword
        extrn '__imp_InterlockedPushListSList' as InterlockedPushListSList:qword
        extrn '__imp_IsCalendarLeapDay' as IsCalendarLeapDay:qword
        extrn '__imp_IsCalendarLeapMonth' as IsCalendarLeapMonth:qword
        extrn '__imp_IsCalendarLeapYear' as IsCalendarLeapYear:qword
        extrn '__imp_IsNLSDefinedString' as IsNLSDefinedString:qword
        extrn '__imp_IsNormalizedString' as IsNormalizedString:qword
        extrn '__imp_IsThreadAFiber' as IsThreadAFiber:qword
        extrn '__imp_IsThreadpoolTimerSet' as IsThreadpoolTimerSet:qword
        if (NTDDI_VERSION <> NTDDI_WIN81)
            extrn '__imp_IsTimeZoneRedirectionEnabled' as IsTimeZoneRedirectionEnabled:qword
        end if
        extrn '__imp_IsValidCalDateTime' as IsValidCalDateTime:qword
        extrn '__imp_IsValidLocaleName' as IsValidLocaleName:qword
        extrn '__imp_LCIDToLocaleName' as LCIDToLocaleName:qword
        extrn '__imp_LCMapStringEx' as LCMapStringEx:qword
        extrn '__imp_LeaveCriticalSectionWhenCallbackReturns' as LeaveCriticalSectionWhenCallbackReturns:qword
        extrn '__imp_LoadStringBaseExW' as LoadStringBaseExW:qword
        extrn '__imp_LoadStringBaseW' as LoadStringBaseW:qword
        extrn '__imp_LocaleNameToLCID' as LocaleNameToLCID:qword
        extrn '__imp_MapViewOfFileExNuma' as MapViewOfFileExNuma:qword
        extrn '__imp_MoveFileTransactedA' as MoveFileTransactedA:qword
        extrn '__imp_MoveFileTransactedW' as MoveFileTransactedW:qword
        extrn '__imp_NeedCurrentDirectoryForExePathA' as NeedCurrentDirectoryForExePathA:qword
        extrn '__imp_NeedCurrentDirectoryForExePathW' as NeedCurrentDirectoryForExePathW:qword
        extrn '__imp_NormalizeString' as NormalizeString:qword
        extrn '__imp_OpenFileById' as OpenFileById:qword
        extrn '__imp_OpenPrivateNamespaceA' as OpenPrivateNamespaceA:qword
        extrn '__imp_OpenPrivateNamespaceW' as OpenPrivateNamespaceW:qword
        extrn '__imp_QueryActCtxSettingsW' as QueryActCtxSettingsW:qword
        extrn '__imp_QueryFullProcessImageNameA' as QueryFullProcessImageNameA:qword
        extrn '__imp_QueryFullProcessImageNameW' as QueryFullProcessImageNameW:qword
        extrn '__imp_QueryIdleProcessorCycleTime' as QueryIdleProcessorCycleTime:qword
        extrn '__imp_QueryProcessCycleTime' as QueryProcessCycleTime:qword
        extrn '__imp_QueryThreadCycleTime' as QueryThreadCycleTime:qword
        extrn '__imp_RegisterApplicationRecoveryCallback' as RegisterApplicationRecoveryCallback:qword
        extrn '__imp_RegisterApplicationRestart' as RegisterApplicationRestart:qword
        extrn '__imp_ReleaseMutexWhenCallbackReturns' as ReleaseMutexWhenCallbackReturns:qword
        extrn '__imp_ReleaseSRWLockExclusive' as ReleaseSRWLockExclusive:qword
        extrn '__imp_ReleaseSRWLockShared' as ReleaseSRWLockShared:qword
        extrn '__imp_ReleaseSemaphoreWhenCallbackReturns' as ReleaseSemaphoreWhenCallbackReturns:qword
        extrn '__imp_RemoveDirectoryTransactedA' as RemoveDirectoryTransactedA:qword
        extrn '__imp_RemoveDirectoryTransactedW' as RemoveDirectoryTransactedW:qword
        extrn '__imp_RemoveDllDirectory' as RemoveDllDirectory:qword
        extrn '__imp_ReplacePartitionUnit' as ReplacePartitionUnit:qword
        extrn '__imp_SetConsoleHistoryInfo' as SetConsoleHistoryInfo:qword
        extrn '__imp_SetConsoleScreenBufferInfoEx' as SetConsoleScreenBufferInfoEx:qword
        extrn '__imp_SetCurrentConsoleFontEx' as SetCurrentConsoleFontEx:qword
        extrn '__imp_SetDefaultDllDirectories' as SetDefaultDllDirectories:qword
        extrn '__imp_SetDynamicTimeZoneInformation' as SetDynamicTimeZoneInformation:qword
        extrn '__imp_SetEventWhenCallbackReturns' as SetEventWhenCallbackReturns:qword
        extrn '__imp_SetFileAttributesTransactedA' as SetFileAttributesTransactedA:qword
        extrn '__imp_SetFileAttributesTransactedW' as SetFileAttributesTransactedW:qword
        extrn '__imp_SetFileBandwidthReservation' as SetFileBandwidthReservation:qword
        extrn '__imp_SetFileCompletionNotificationModes' as SetFileCompletionNotificationModes:qword
        extrn '__imp_SetFileInformationByHandle' as SetFileInformationByHandle:qword
        extrn '__imp_SetFileIoOverlappedRange' as SetFileIoOverlappedRange:qword
        extrn '__imp_SetNamedPipeAttribute' as SetNamedPipeAttribute:qword
        extrn '__imp_SetThreadpoolThreadMaximum' as SetThreadpoolThreadMaximum:qword
        extrn '__imp_SetThreadpoolThreadMinimum' as SetThreadpoolThreadMinimum:qword
        extrn '__imp_SetThreadpoolTimer' as SetThreadpoolTimer:qword
        extrn '__imp_SetThreadpoolWait' as SetThreadpoolWait:qword
        if (NTDDI_VERSION >= NTDDI_WIN8)
            extrn '__imp_SetThreadpoolWaitEx' as SetThreadpoolWaitEx:qword
        end if
        extrn '__imp_SetThreadPreferredUILanguages' as SetThreadPreferredUILanguages:qword
        extrn '__imp_SleepConditionVariableCS' as SleepConditionVariableCS:qword
        extrn '__imp_SleepConditionVariableSRW' as SleepConditionVariableSRW:qword
        extrn '__imp_StartThreadpoolIo' as StartThreadpoolIo:qword
        extrn '__imp_SubmitThreadpoolWork' as SubmitThreadpoolWork:qword
        extrn '__imp_TrySubmitThreadpoolCallback' as TrySubmitThreadpoolCallback:qword
        extrn '__imp_UnregisterApplicationRecoveryCallback' as UnregisterApplicationRecoveryCallback:qword
        extrn '__imp_UnregisterApplicationRestart' as UnregisterApplicationRestart:qword
        extrn '__imp_UpdateCalendarDayOfWeek' as UpdateCalendarDayOfWeek:qword
        extrn '__imp_UpdateProcThreadAttribute' as UpdateProcThreadAttribute:qword
        extrn '__imp_VerifyScripts' as VerifyScripts:qword
        extrn '__imp_VirtualAllocExNuma' as VirtualAllocExNuma:qword
        extrn '__imp_WaitForThreadpoolIoCallbacks' as WaitForThreadpoolIoCallbacks:qword
        extrn '__imp_WaitForThreadpoolTimerCallbacks' as WaitForThreadpoolTimerCallbacks:qword
        extrn '__imp_WaitForThreadpoolWaitCallbacks' as WaitForThreadpoolWaitCallbacks:qword
        extrn '__imp_WaitForThreadpoolWorkCallbacks' as WaitForThreadpoolWorkCallbacks:qword
        extrn '__imp_WakeAllConditionVariable' as WakeAllConditionVariable:qword
        extrn '__imp_WakeConditionVariable' as WakeConditionVariable:qword
        extrn '__imp_WerGetFlags' as WerGetFlags:qword
        extrn '__imp_WerRegisterFile' as WerRegisterFile:qword
        extrn '__imp_WerRegisterMemoryBlock' as WerRegisterMemoryBlock:qword
        extrn '__imp_WerSetFlags' as WerSetFlags:qword
        extrn '__imp_WerUnregisterFile' as WerUnregisterFile:qword
        extrn '__imp_WerUnregisterMemoryBlock' as WerUnregisterMemoryBlock:qword
        extrn '__imp_Wow64GetThreadContext' as Wow64GetThreadContext:qword
        extrn '__imp_Wow64SetThreadContext' as Wow64SetThreadContext:qword
        extrn '__imp_Wow64SuspendThread' as Wow64SuspendThread:qword
        api CopyFileTransacted,\
            CreateBoundaryDescriptor,\
            CreateDirectoryTransacted,\
            CreateEventEx,\
            CreateFileMappingNuma,\
            CreateFileTransacted,\
            CreateHardLinkTransacted,\
            CreateMutexEx,\
            CreatePrivateNamespace,\
            CreateSemaphoreEx,\
            CreateSymbolicLink,\
            CreateSymbolicLinkTransacted,\
            CreateWaitableTimerEx,\
            DeleteFileTransacted,\
            EnumResourceLanguagesEx,\
            EnumResourceNamesEx,\
            EnumResourceTypesEx,\
            FindFirstFileTransacted,\
            GetCompressedFileSizeTransacted,\
            GetConsoleOriginalTitle,\
            GetFileAttributesTransacted,\
            GetFinalPathNameByHandle,\
            GetFullPathNameTransacted,\
            GetLongPathNameTransacted,\
            GetNamedPipeClientComputerName,\
            MoveFileTransacted,\
            NeedCurrentDirectoryForExePath,\
            OpenPrivateNamespace,\
            QueryFullProcessImageName,\
            RemoveDirectoryTransacted,\
            SetFileAttributesTransacted
    end if

    if (NTDDI_VERSION >= NTDDI_VISTASP1)
        extrn '__imp_AddSecureMemoryCacheCallback' as AddSecureMemoryCacheCallback:qword
        extrn '__imp_GetPhysicallyInstalledSystemMemory' as GetPhysicallyInstalledSystemMemory:qword
        extrn '__imp_GetTimeZoneInformationForYear' as GetTimeZoneInformationForYear:qword
        extrn '__imp_QueryProcessAffinityUpdateMode' as QueryProcessAffinityUpdateMode:qword
        extrn '__imp_RemoveSecureMemoryCacheCallback' as RemoveSecureMemoryCacheCallback:qword
        extrn '__imp_SetProcessAffinityUpdateMode' as SetProcessAffinityUpdateMode:qword
    end if

    if (NTDDI_VERSION >= NTDDI_WIN7)
        extrn '__imp_AddIntegrityLabelToBoundaryDescriptor' as AddIntegrityLabelToBoundaryDescriptor:qword
        extrn '__imp_BaseFormatTimeOut' as BaseFormatTimeOut:qword
        extrn '__imp_BaseGetNamedObjectDirectory' as BaseGetNamedObjectDirectory:qword
        extrn '__imp_Basep8BitStringToDynamicUnicodeString' as Basep8BitStringToDynamicUnicodeString:qword
        extrn '__imp_CreateRemoteThreadEx' as CreateRemoteThreadEx:qword
        extrn '__imp_DisableThreadProfiling' as DisableThreadProfiling:qword
        extrn '__imp_EnableThreadProfiling' as EnableThreadProfiling:qword
        extrn '__imp_FindStringOrdinal' as FindStringOrdinal:qword
        extrn '__imp_GetActiveProcessorCount' as GetActiveProcessorCount:qword
        extrn '__imp_GetActiveProcessorGroupCount' as GetActiveProcessorGroupCount:qword
        extrn '__imp_GetCurrentProcessorNumberEx' as GetCurrentProcessorNumberEx:qword
        extrn '__imp_GetLogicalProcessorInformationEx' as GetLogicalProcessorInformationEx:qword
        extrn '__imp_GetMaximumProcessorCount' as GetMaximumProcessorCount:qword
        extrn '__imp_GetMaximumProcessorGroupCount' as GetMaximumProcessorGroupCount:qword
        extrn '__imp_GetNumaAvailableMemoryNodeEx' as GetNumaAvailableMemoryNodeEx:qword
        extrn '__imp_GetNumaNodeNumberFromHandle' as GetNumaNodeNumberFromHandle:qword
        extrn '__imp_GetNumaNodeProcessorMaskEx' as GetNumaNodeProcessorMaskEx:qword
        extrn '__imp_GetNumaProcessorNodeEx' as GetNumaProcessorNodeEx:qword
        extrn '__imp_GetNumaProximityNodeEx' as GetNumaProximityNodeEx:qword
        extrn '__imp_GetProcessGroupAffinity' as GetProcessGroupAffinity:qword
        extrn '__imp_GetProcessorSystemCycleTime' as GetProcessorSystemCycleTime:qword
        extrn '__imp_GetProcessPreferredUILanguages' as GetProcessPreferredUILanguages:qword
        extrn '__imp_GetProcessUserModeExceptionPolicy' as GetProcessUserModeExceptionPolicy:qword
        extrn '__imp_GetThreadErrorMode' as GetThreadErrorMode:qword
        extrn '__imp_GetThreadGroupAffinity' as GetThreadGroupAffinity:qword
        extrn '__imp_GetThreadIdealProcessorEx' as GetThreadIdealProcessorEx:qword
        extrn '__imp_K32EmptyWorkingSet' as K32EmptyWorkingSet:qword
        extrn '__imp_K32EnumDeviceDrivers' as K32EnumDeviceDrivers:qword
        extrn '__imp_K32EnumPageFilesA' as K32EnumPageFilesA:qword
        extrn '__imp_K32EnumPageFilesW' as K32EnumPageFilesW:qword
        extrn '__imp_K32EnumProcessModules' as K32EnumProcessModules:qword
        extrn '__imp_K32EnumProcessModulesEx' as K32EnumProcessModulesEx:qword
        extrn '__imp_K32EnumProcesses' as K32EnumProcesses:qword
        extrn '__imp_K32GetDeviceDriverBaseNameA' as K32GetDeviceDriverBaseNameA:qword
        extrn '__imp_K32GetDeviceDriverBaseNameW' as K32GetDeviceDriverBaseNameW:qword
        extrn '__imp_K32GetDeviceDriverFileNameA' as K32GetDeviceDriverFileNameA:qword
        extrn '__imp_K32GetDeviceDriverFileNameW' as K32GetDeviceDriverFileNameW:qword
        extrn '__imp_K32GetMappedFileNameA' as K32GetMappedFileNameA:qword
        extrn '__imp_K32GetMappedFileNameW' as K32GetMappedFileNameW:qword
        extrn '__imp_K32GetModuleBaseNameA' as K32GetModuleBaseNameA:qword
        extrn '__imp_K32GetModuleBaseNameW' as K32GetModuleBaseNameW:qword
        extrn '__imp_K32GetModuleFileNameExA' as K32GetModuleFileNameExA:qword
        extrn '__imp_K32GetModuleFileNameExW' as K32GetModuleFileNameExW:qword
        extrn '__imp_K32GetModuleInformation' as K32GetModuleInformation:qword
        extrn '__imp_K32GetPerformanceInfo' as K32GetPerformanceInfo:qword
        extrn '__imp_K32GetProcessImageFileNameA' as K32GetProcessImageFileNameA:qword
        extrn '__imp_K32GetProcessImageFileNameW' as K32GetProcessImageFileNameW:qword
        extrn '__imp_K32GetProcessMemoryInfo' as K32GetProcessMemoryInfo:qword
        extrn '__imp_K32GetWsChanges' as K32GetWsChanges:qword
        extrn '__imp_K32GetWsChangesEx' as K32GetWsChangesEx:qword
        extrn '__imp_K32InitializeProcessForWsWatch' as K32InitializeProcessForWsWatch:qword
        extrn '__imp_K32QueryWorkingSet' as K32QueryWorkingSet:qword
        extrn '__imp_K32QueryWorkingSetEx' as K32QueryWorkingSetEx:qword
        extrn '__imp_LoadAppInitDlls' as LoadAppInitDlls:qword
        extrn '__imp_NotifyUILanguageChange' as NotifyUILanguageChange:qword
        extrn '__imp_PowerClearRequest' as PowerClearRequest:qword
        extrn '__imp_PowerCreateRequest' as PowerCreateRequest:qword
        extrn '__imp_PowerSetRequest' as PowerSetRequest:qword
        extrn '__imp_QueryIdleProcessorCycleTimeEx' as QueryIdleProcessorCycleTimeEx:qword
        extrn '__imp_QueryThreadProfiling' as QueryThreadProfiling:qword
        extrn '__imp_QueryThreadpoolStackInformation' as QueryThreadpoolStackInformation:qword
        extrn '__imp_QueryUnbiasedInterruptTime' as QueryUnbiasedInterruptTime:qword
        extrn '__imp_RaiseFailFastException' as RaiseFailFastException:qword
        extrn '__imp_ReadThreadProfilingData' as ReadThreadProfilingData:qword
        extrn '__imp_ResolveLocaleName' as ResolveLocaleName:qword
        extrn '__imp_RtlCompareMemory' as RtlCompareMemory:qword
        extrn '__imp_RtlCopyMemory' as RtlCopyMemory:qword
        extrn '__imp_SetProcessPreferredUILanguages' as SetProcessPreferredUILanguages:qword
        if (NTDDI_VERSION < NTDDI_WIN8)
            extrn '__imp_SetProcessUserModeExceptionPolicy' as SetProcessUserModeExceptionPolicy:qword
        end if
        extrn '__imp_SetSearchPathMode' as SetSearchPathMode:qword
        extrn '__imp_SetStdHandleEx' as SetStdHandleEx:qword
        extrn '__imp_SetThreadErrorMode' as SetThreadErrorMode:qword
        extrn '__imp_SetThreadGroupAffinity' as SetThreadGroupAffinity:qword
        extrn '__imp_SetThreadIdealProcessorEx' as SetThreadIdealProcessorEx:qword
        extrn '__imp_SetThreadpoolStackInformation' as SetThreadpoolStackInformation:qword
        extrn '__imp_SystemTimeToTzSpecificLocalTimeEx' as SystemTimeToTzSpecificLocalTimeEx:qword
        extrn '__imp_TryAcquireSRWLockExclusive' as TryAcquireSRWLockExclusive:qword
        extrn '__imp_TryAcquireSRWLockShared' as TryAcquireSRWLockShared:qword
        extrn '__imp_TzSpecificLocalTimeToSystemTimeEx' as TzSpecificLocalTimeToSystemTimeEx:qword
        extrn '__imp_WerRegisterRuntimeExceptionModule' as WerRegisterRuntimeExceptionModule:qword
        extrn '__imp_WerUnregisterRuntimeExceptionModule' as WerUnregisterRuntimeExceptionModule:qword
        extrn '__imp_Wow64GetThreadSelectorEntry' as Wow64GetThreadSelectorEntry:qword
        CopyMemory equ RtlCopyMemory
        extrn '__imp_CreateUmsCompletionList' as CreateUmsCompletionList:qword
        extrn '__imp_CreateUmsThreadContext' as CreateUmsThreadContext:qword
        extrn '__imp_DeleteUmsCompletionList' as DeleteUmsCompletionList:qword
        extrn '__imp_DeleteUmsThreadContext' as DeleteUmsThreadContext:qword
        extrn '__imp_DequeueUmsCompletionListItems' as DequeueUmsCompletionListItems:qword
        extrn '__imp_EnterUmsSchedulingMode' as EnterUmsSchedulingMode:qword
        extrn '__imp_ExecuteUmsThread' as ExecuteUmsThread:qword
        extrn '__imp_GetCurrentUmsThread' as GetCurrentUmsThread:qword
        extrn '__imp_GetNextUmsListItem' as GetNextUmsListItem:qword
        extrn '__imp_GetUmsCompletionListEvent' as GetUmsCompletionListEvent:qword
        extrn '__imp_GetUmsSystemThreadInformation' as GetUmsSystemThreadInformation:qword
        extrn '__imp_QueryUmsThreadInformation' as QueryUmsThreadInformation:qword
        extrn '__imp_SetUmsThreadInformation' as SetUmsThreadInformation:qword
        extrn '__imp_UmsThreadYield' as UmsThreadYield:qword

        api K32EnumPageFiles,\
            K32GetDeviceDriverBaseName,\
            K32GetDeviceDriverFileName,\
            K32GetMappedFileName,\
            K32GetModuleBaseName,\
            K32GetModuleFileNameEx,\
            K32GetProcessImageFileName
    end if

    if (NTDDI_VERSION >= NTDDI_WIN7SP1)
        extrn '__imp_CopyContext' as CopyContext:qword
        extrn '__imp_GetEnabledXStateFeatures' as GetEnabledXStateFeatures:qword
        extrn '__imp_GetXStateFeaturesMask' as GetXStateFeaturesMask:qword
        extrn '__imp_InitializeContext' as InitializeContext:qword
        extrn '__imp_LocateXStateFeature' as LocateXStateFeature:qword
        extrn '__imp_SetXStateFeaturesMask' as SetXStateFeaturesMask:qword
    end if

    if (NTDDI_VERSION >= NTDDI_WIN8)
        if (NTDDI_VERSION = NTDDI_WIN8)
            extrn '__imp_AcquireStateLock' as AcquireStateLock:qword
        end if
        extrn '__imp_AddResourceAttributeAce' as AddResourceAttributeAce:qword
        extrn '__imp_AddScopedPolicyIDAce' as AddScopedPolicyIDAce:qword
        if (NTDDI_VERSION = NTDDI_WIN8)
            extrn '__imp_CalloutOnFiberStack' as CalloutOnFiberStack:qword
            extrn '__imp_CopyExtendedContext' as CopyExtendedContext:qword
        end if
        extrn '__imp_CeipIsOptedIn' as CeipIsOptedIn:qword
        extrn '__imp_CheckTokenCapability' as CheckTokenCapability:qword
        extrn '__imp_CheckTokenMembershipEx' as CheckTokenMembershipEx:qword
        extrn '__imp_ClosePackageInfo' as ClosePackageInfo:qword
        extrn '__imp_CopyFile2' as CopyFile2:qword
        extrn '__imp_CreateFile2' as CreateFile2:qword
        extrn '__imp_CreateFileMappingFromApp' as CreateFileMappingFromApp:qword
        extrn '__imp_GetAppContainerNamedObjectPath' as GetAppContainerNamedObjectPath:qword
        extrn '__imp_GetApplicationUserModelId' as GetApplicationUserModelId:qword
        extrn '__imp_GetCachedSigningLevel' as GetCachedSigningLevel:qword
        extrn '__imp_GetCurrentApplicationUserModelId' as GetCurrentApplicationUserModelId:qword
        extrn '__imp_GetCurrentPackageFamilyName' as GetCurrentPackageFamilyName:qword
        extrn '__imp_GetCurrentPackageFullName' as GetCurrentPackageFullName:qword
        extrn '__imp_GetCurrentPackageId' as GetCurrentPackageId:qword
        extrn '__imp_GetCurrentPackageInfo' as GetCurrentPackageInfo:qword
        extrn '__imp_GetCurrentPackagePath' as GetCurrentPackagePath:qword
        extrn '__imp_GetCurrentThreadStackLimits' as GetCurrentThreadStackLimits:qword
        extrn '__imp_GetFirmwareEnvironmentVariableExA' as GetFirmwareEnvironmentVariableExA:qword
        extrn '__imp_GetFirmwareEnvironmentVariableExW' as GetFirmwareEnvironmentVariableExW:qword
        extrn '__imp_GetFirmwareType' as GetFirmwareType:qword
        extrn '__imp_GetMemoryErrorHandlingCapabilities' as GetMemoryErrorHandlingCapabilities:qword
        extrn '__imp_GetOverlappedResultEx' as GetOverlappedResultEx:qword
        extrn '__imp_GetPackageFamilyName' as GetPackageFamilyName:qword
        extrn '__imp_GetPackageFullName' as GetPackageFullName:qword
        extrn '__imp_GetPackageId' as GetPackageId:qword
        extrn '__imp_GetPackageInfo' as GetPackageInfo:qword
        extrn '__imp_GetPackagePath' as GetPackagePath:qword
        extrn '__imp_GetPackagesByPackageFamily' as GetPackagesByPackageFamily:qword
        extrn '__imp_GetProcessInformation' as GetProcessInformation:qword
        extrn '__imp_GetProcessMitigationPolicy' as GetProcessMitigationPolicy:qword
        extrn '__imp_GetSystemTimePreciseAsFileTime' as GetSystemTimePreciseAsFileTime:qword
        extrn '__imp_GetThreadInformation' as GetThreadInformation:qword
        extrn '__imp_GlobalAddAtomExA' as GlobalAddAtomExA:qword
        extrn '__imp_GlobalAddAtomExW' as GlobalAddAtomExW:qword
        extrn '__imp_InterlockedPushListSListEx' as InterlockedPushListSListEx:qword
        extrn '__imp_IsNativeVhdBoot' as IsNativeVhdBoot:qword
        extrn '__imp_IsValidNLSVersion' as IsValidNLSVersion:qword
        extrn '__imp_LoadPackagedLibrary' as LoadPackagedLibrary:qword
        extrn '__imp_MapViewOfFileFromApp' as MapViewOfFileFromApp:qword
        extrn '__imp_OpenPackageInfoByFullName' as OpenPackageInfoByFullName:qword
        extrn '__imp_PackageFamilyNameFromFullName' as PackageFamilyNameFromFullName:qword
        extrn '__imp_PackageFamilyNameFromId' as PackageFamilyNameFromId:qword
        extrn '__imp_PackageFullNameFromId' as PackageFullNameFromId:qword
        extrn '__imp_PackageIdFromFullName' as PackageIdFromFullName:qword
        extrn '__imp_PackageNameAndPublisherIdFromFamilyName' as PackageNameAndPublisherIdFromFamilyName:qword
        extrn '__imp_PrefetchVirtualMemory' as PrefetchVirtualMemory:qword
        extrn '__imp_RegCopyTreeW' as RegCopyTreeW:qword
        extrn '__imp_RegisterBadMemoryNotification' as RegisterBadMemoryNotification:qword
        extrn '__imp_RestoreLastError' as RestoreLastError:qword
        extrn '__imp_SetCachedSigningLevel' as SetCachedSigningLevel:qword
        extrn '__imp_SetFirmwareEnvironmentVariableExA' as SetFirmwareEnvironmentVariableExA:qword
        extrn '__imp_SetFirmwareEnvironmentVariableExW' as SetFirmwareEnvironmentVariableExW:qword
        extrn '__imp_SetProcessInformation' as SetProcessInformation:qword
        extrn '__imp_SetProcessMitigationPolicy' as SetProcessMitigationPolicy:qword
        extrn '__imp_SetThreadInformation' as SetThreadInformation:qword
        extrn '__imp_UnregisterBadMemoryNotification' as UnregisterBadMemoryNotification:qword
        api GetFirmwareEnvironmentVariableEx,\
            GlobalAddAtomEx,\
            SetFirmwareEnvironmentVariableEx
    end if

    if (NTDDI_VERSION >= NTDDI_WIN81)
        extrn '__imp_DeleteSynchronizationBarrier' as DeleteSynchronizationBarrier:qword
        extrn '__imp_EnterSynchronizationBarrier' as EnterSynchronizationBarrier:qword
        extrn '__imp_FindPackagesByPackageFamily' as FindPackagesByPackageFamily:qword
        extrn '__imp_FormatApplicationUserModelId' as FormatApplicationUserModelId:qword
        extrn '__imp_GetPackageApplicationIds' as GetPackageApplicationIds:qword
        extrn '__imp_GetPackagePathByFullName' as GetPackagePathByFullName:qword
        extrn '__imp_GetStagedPackagePathByFullName' as GetStagedPackagePathByFullName:qword
        extrn '__imp_InitializeSynchronizationBarrier' as InitializeSynchronizationBarrier:qword
        extrn '__imp_InstallELAMCertificateInfo' as InstallELAMCertificateInfo:qword
        extrn '__imp_IsProcessCritical' as IsProcessCritical:qword
        extrn '__imp_OOBEComplete' as OOBEComplete:qword
        extrn '__imp_ParseApplicationUserModelId' as ParseApplicationUserModelId:qword
        extrn '__imp_PssCaptureSnapshot' as PssCaptureSnapshot:qword
        extrn '__imp_PssDuplicateSnapshot' as PssDuplicateSnapshot:qword
        extrn '__imp_PssFreeSnapshot' as PssFreeSnapshot:qword
        extrn '__imp_PssQuerySnapshot' as PssQuerySnapshot:qword
        extrn '__imp_PssWalkMarkerCreate' as PssWalkMarkerCreate:qword
        extrn '__imp_PssWalkMarkerFree' as PssWalkMarkerFree:qword
        extrn '__imp_PssWalkMarkerGetPosition' as PssWalkMarkerGetPosition:qword
        extrn '__imp_PssWalkMarkerSeekToBeginning' as PssWalkMarkerSeekToBeginning:qword
        extrn '__imp_PssWalkMarkerSetPosition' as PssWalkMarkerSetPosition:qword
        extrn '__imp_PssWalkSnapshot' as PssWalkSnapshot:qword
        extrn '__imp_RegisterWaitUntilOOBECompleted' as RegisterWaitUntilOOBECompleted:qword
        extrn '__imp_UnregisterWaitUntilOOBECompleted' as UnregisterWaitUntilOOBECompleted:qword
    end if

    if (NTDDI_VERSION >= NTDDI_WIN10)
        extrn '__imp_CreateEnclave' as CreateEnclave:qword
        extrn '__imp_DiscardVirtualMemory' as DiscardVirtualMemory:qword
        extrn '__imp_FreeMemoryJobObject' as FreeMemoryJobObject:qword
        extrn '__imp_GetProcessDefaultCpuSets' as GetProcessDefaultCpuSets:qword
        extrn '__imp_GetSystemCpuSetInformation' as GetSystemCpuSetInformation:qword
        extrn '__imp_GetThreadSelectedCpuSets' as GetThreadSelectedCpuSets:qword
        extrn '__imp_InitializeEnclave' as InitializeEnclave:qword
        extrn '__imp_IsEnclaveTypeSupported' as IsEnclaveTypeSupported:qword
        extrn '__imp_LoadEnclaveData' as LoadEnclaveData:qword
        extrn '__imp_OfferVirtualMemory' as OfferVirtualMemory:qword
        extrn '__imp_QueryIoRateControlInformationJobObject' as QueryIoRateControlInformationJobObject:qword
        extrn '__imp_QueryProtectedPolicy' as QueryProtectedPolicy:qword
        extrn '__imp_ReclaimVirtualMemory' as ReclaimVirtualMemory:qword
        extrn '__imp_SetIoRateControlInformationJobObject' as SetIoRateControlInformationJobObject:qword
        extrn '__imp_SetProcessDefaultCpuSets' as SetProcessDefaultCpuSets:qword
        extrn '__imp_SetProtectedPolicy' as SetProtectedPolicy:qword
        extrn '__imp_SetThreadSelectedCpuSets' as SetThreadSelectedCpuSets:qword
        extrn '__imp_WaitForDebugEventEx' as WaitForDebugEventEx:qword
    end if

    api AddAtom,\
        BeginUpdateResource,\
        BuildCommDCB,\
        BuildCommDCBAndTimeouts,\
        CallNamedPipe,\
        CommConfigDialog,\
        CompareString,\
        CopyFile,\
        CreateDirectory,\
        CreateDirectoryEx,\
        CreateEvent,\
        CreateFile,\
        CreateFileMapping,\
        CreateMailslot,\
        CreateMutex,\
        CreateNamedPipe,\
        CreateProcess,\
        CreateSemaphore,\
        DefineDosDevice,\
        DeleteFile,\
        EndUpdateResource,\
        EnumCalendarInfo,\
        EnumDateFormats,\
        EnumResourceLanguages,\
        EnumResourceNames,\
        EnumResourceTypes,\
        EnumSystemCodePages,\
        EnumSystemLocales,\
        EnumTimeFormats,\
        ExpandEnvironmentStrings,\
        FatalAppExit,\
        FillConsoleOutputCharacter,\
        FindAtom,\
        FindFirstChangeNotification,\
        FindFirstFile,\
        FindNextFile,\
        FindResource,\
        FindResourceEx,\
        FoldString,\
        FormatMessage,\
        FreeEnvironmentStrings,\
        GetAtomName,\
        GetBinaryType,\
        GetCommandLine,\
        GetCompressedFileSize,\
        GetComputerName,\
        GetConsoleTitle,\
        GetCurrencyFormat,\
        GetCurrentDirectory,\
        GetDateFormat,\
        GetDefaultCommConfig,\
        GetDiskFreeSpace,\
        GetDiskFreeSpaceEx,\
        GetDriveType,\
        GetEnvironmentStrings,\
        GetEnvironmentVariable,\
        GetFileAttributes,\
        GetFullPathName,\
        GetLocaleInfo,\
        GetLogicalDriveStrings,\
        GetModuleFileName,\
        GetModuleHandle,\
        GetNamedPipeHandleState,\
        GetNumberFormat,\
        GetPrivateProfileInt,\
        GetPrivateProfileSection,\
        GetPrivateProfileSectionNames,\
        GetPrivateProfileString,\
        GetPrivateProfileStruct,\
        GetProfileInt,\
        GetProfileSection,\
        GetProfileString,\
        GetShortPathName,\
        GetStartupInfo,\
        GetStringType,\
        GetStringTypeEx,\
        GetSystemDirectory,\
        GetTempFileName,\
        GetTempPath,\
        GetTimeFormat,\
        GetVersionEx,\
        GetVolumeInformation,\
        GetWindowsDirectory,\
        GlobalAddAtom,\
        GlobalFindAtom,\
        GlobalGetAtomName,\
        IsBadStringPtr,\
        LCMapString,\
        LoadLibrary,\
        LoadLibraryEx,\
        lstrcat,\
        lstrcmp,\
        lstrcmpi,\
        lstrcpy,\
        lstrcpyn,\
        lstrlen,\
        MoveFile,\
        MoveFileEx,\
        OpenEvent,\
        OpenFileMapping,\
        OpenMutex,\
        OpenSemaphore,\
        OutputDebugString,\
        PeekConsoleInput,\
        QueryDosDevice,\
        ReadConsole,\
        ReadConsoleInput,\
        ReadConsoleOutput,\
        ReadConsoleOutputCharacter,\
        RemoveDirectory,\
        ScrollConsoleScreenBuffer,\
        SearchPath,\
        SetComputerName,\
        SetConsoleTitle,\
        SetCurrentDirectory,\
        SetDefaultCommConfig,\
        SetEnvironmentVariable,\
        SetFileAttributes,\
        SetLocaleInfo,\
        SetVolumeLabel,\
        UpdateResource,\
        WaitNamedPipe,\
        WriteConsole,\
        WriteConsoleInput,\
        WriteConsoleOutput,\
        WriteConsoleOutputCharacter,\
        WritePrivateProfileSection,\
        WritePrivateProfileString,\
        WritePrivateProfileStruct,\
        WriteProfileSection,\
        WriteProfileString
else
    extrn '__imp___hread@12' as _hread:dword
    extrn '__imp___hwrite@12' as _hwrite:dword
    extrn '__imp___lclose@4' as _lclose:dword
    extrn '__imp___lcreat@8' as _lcreat:dword
    extrn '__imp___llseek@12' as _llseek:dword
    extrn '__imp___lopen@8' as _lopen:dword
    extrn '__imp___lread@12' as _lread:dword
    extrn '__imp___lwrite@12' as _lwrite:dword
    extrn '__imp__AddAtomA@4' as AddAtomA:dword
    extrn '__imp__AddAtomW@4' as AddAtomW:dword
    extrn '__imp__AllocConsole@0' as AllocConsole:dword
    extrn '__imp__AreFileApisANSI@0' as AreFileApisANSI:dword
    extrn '__imp__BackupRead@28' as BackupRead:dword
    extrn '__imp__BackupSeek@24' as BackupSeek:dword
    extrn '__imp__BackupWrite@28' as BackupWrite:dword
    extrn '__imp__Beep@8' as Beep:dword
    extrn '__imp__BeginUpdateResourceA@8' as BeginUpdateResourceA:dword
    extrn '__imp__BeginUpdateResourceW@8' as BeginUpdateResourceW:dword
    extrn '__imp__BuildCommDCBA@8' as BuildCommDCBA:dword
    extrn '__imp__BuildCommDCBAndTimeoutsA@12' as BuildCommDCBAndTimeoutsA:dword
    extrn '__imp__BuildCommDCBAndTimeoutsW@12' as BuildCommDCBAndTimeoutsW:dword
    extrn '__imp__BuildCommDCBW@8' as BuildCommDCBW:dword
    extrn '__imp__CallNamedPipeA@28' as CallNamedPipeA:dword
    extrn '__imp__CallNamedPipeW@28' as CallNamedPipeW:dword
    extrn '__imp__ClearCommBreak@4' as ClearCommBreak:dword
    extrn '__imp__ClearCommError@12' as ClearCommError:dword
    extrn '__imp__CloseHandle@4' as CloseHandle:dword
    ;extrn '__imp__CloseProfileUserMapping@0' as CloseProfileUserMapping:dword ;Not present in MASM32 kernel32.lib
    extrn '__imp__CommConfigDialogA@12' as CommConfigDialogA:dword
    extrn '__imp__CommConfigDialogW@12' as CommConfigDialogW:dword
    extrn '__imp__CompareFileTime@8' as CompareFileTime:dword
    extrn '__imp__CompareStringA@24' as CompareStringA:dword
    extrn '__imp__CompareStringW@24' as CompareStringW:dword
    extrn '__imp__ConnectNamedPipe@8' as ConnectNamedPipe:dword
    extrn '__imp__ContinueDebugEvent@12' as ContinueDebugEvent:dword
    extrn '__imp__ConvertDefaultLocale@4' as ConvertDefaultLocale:dword
    extrn '__imp__CopyFileA@12' as CopyFileA:dword
    extrn '__imp__CopyFileW@12' as CopyFileW:dword
    extrn '__imp__CreateConsoleScreenBuffer@20' as CreateConsoleScreenBuffer:dword
    extrn '__imp__CreateDirectoryA@8' as CreateDirectoryA:dword
    extrn '__imp__CreateDirectoryExA@12' as CreateDirectoryExA:dword
    extrn '__imp__CreateDirectoryExW@12' as CreateDirectoryExW:dword
    extrn '__imp__CreateDirectoryW@8' as CreateDirectoryW:dword
    extrn '__imp__CreateEventA@16' as CreateEventA:dword
    extrn '__imp__CreateEventW@16' as CreateEventW:dword
    extrn '__imp__CreateFileA@28' as CreateFileA:dword
    extrn '__imp__CreateFileMappingA@24' as CreateFileMappingA:dword
    extrn '__imp__CreateFileMappingW@24' as CreateFileMappingW:dword
    extrn '__imp__CreateFileW@28' as CreateFileW:dword
    extrn '__imp__CreateIoCompletionPort@16' as CreateIoCompletionPort:dword
    extrn '__imp__CreateMailslotA@16' as CreateMailslotA:dword
    extrn '__imp__CreateMailslotW@16' as CreateMailslotW:dword
    extrn '__imp__CreateMutexA@12' as CreateMutexA:dword
    extrn '__imp__CreateMutexW@12' as CreateMutexW:dword
    extrn '__imp__CreateNamedPipeA@32' as CreateNamedPipeA:dword
    extrn '__imp__CreateNamedPipeW@32' as CreateNamedPipeW:dword
    extrn '__imp__CreatePipe@16' as CreatePipe:dword
    extrn '__imp__CreateProcessA@40' as CreateProcessA:dword
    extrn '__imp__CreateProcessW@40' as CreateProcessW:dword
    extrn '__imp__CreateRemoteThread@28' as CreateRemoteThread:dword
    extrn '__imp__CreateSemaphoreA@16' as CreateSemaphoreA:dword
    extrn '__imp__CreateSemaphoreW@16' as CreateSemaphoreW:dword
    extrn '__imp__CreateTapePartition@16' as CreateTapePartition:dword
    extrn '__imp__CreateThread@24' as CreateThread:dword
    extrn '__imp__CreateToolhelp32Snapshot@8' as CreateToolhelp32Snapshot:dword
    extrn '__imp__DebugActiveProcess@4' as DebugActiveProcess:dword
    extrn '__imp__DebugBreak@0' as DebugBreak:dword
    extrn '__imp__DefineDosDeviceA@12' as DefineDosDeviceA:dword
    extrn '__imp__DefineDosDeviceW@12' as DefineDosDeviceW:dword
    extrn '__imp__DeleteAtom@4' as DeleteAtom:dword
    extrn '__imp__DeleteCriticalSection@4' as DeleteCriticalSection:dword
    extrn '__imp__DeleteFileA@4' as DeleteFileA:dword
    extrn '__imp__DeleteFileW@4' as DeleteFileW:dword
    extrn '__imp__DeviceIoControl@32' as DeviceIoControl:dword
    extrn '__imp__DisableThreadLibraryCalls@4' as DisableThreadLibraryCalls:dword
    extrn '__imp__DisconnectNamedPipe@4' as DisconnectNamedPipe:dword
    extrn '__imp__DosDateTimeToFileTime@12' as DosDateTimeToFileTime:dword
    extrn '__imp__DuplicateHandle@28' as DuplicateHandle:dword
    extrn '__imp__EndUpdateResourceA@8' as EndUpdateResourceA:dword
    extrn '__imp__EndUpdateResourceW@8' as EndUpdateResourceW:dword
    extrn '__imp__EnterCriticalSection@4' as EnterCriticalSection:dword
    extrn '__imp__EnumCalendarInfoA@16' as EnumCalendarInfoA:dword
    extrn '__imp__EnumCalendarInfoW@16' as EnumCalendarInfoW:dword
    extrn '__imp__EnumDateFormatsA@12' as EnumDateFormatsA:dword
    extrn '__imp__EnumDateFormatsW@12' as EnumDateFormatsW:dword
    extrn '__imp__EnumResourceLanguagesA@20' as EnumResourceLanguagesA:dword
    extrn '__imp__EnumResourceLanguagesW@20' as EnumResourceLanguagesW:dword
    extrn '__imp__EnumResourceNamesA@16' as EnumResourceNamesA:dword
    extrn '__imp__EnumResourceNamesW@16' as EnumResourceNamesW:dword
    extrn '__imp__EnumResourceTypesA@12' as EnumResourceTypesA:dword
    extrn '__imp__EnumResourceTypesW@12' as EnumResourceTypesW:dword
    extrn '__imp__EnumSystemCodePagesA@8' as EnumSystemCodePagesA:dword
    extrn '__imp__EnumSystemCodePagesW@8' as EnumSystemCodePagesW:dword
    extrn '__imp__EnumSystemLocalesA@8' as EnumSystemLocalesA:dword
    extrn '__imp__EnumSystemLocalesW@8' as EnumSystemLocalesW:dword
    extrn '__imp__EnumTimeFormatsA@12' as EnumTimeFormatsA:dword
    extrn '__imp__EnumTimeFormatsW@12' as EnumTimeFormatsW:dword
    extrn '__imp__EraseTape@12' as EraseTape:dword
    extrn '__imp__EscapeCommFunction@8' as EscapeCommFunction:dword
    extrn '__imp__ExitProcess@4' as ExitProcess:dword
    extrn '__imp__ExitThread@4' as ExitThread:dword
    extrn '__imp__ExpandEnvironmentStringsA@12' as ExpandEnvironmentStringsA:dword
    extrn '__imp__ExpandEnvironmentStringsW@12' as ExpandEnvironmentStringsW:dword
    extrn '__imp__FatalAppExitA@8' as FatalAppExitA:dword
    extrn '__imp__FatalAppExitW@8' as FatalAppExitW:dword
    extrn '__imp__FatalExit@4' as FatalExit:dword
    extrn '__imp__FileTimeToDosDateTime@12' as FileTimeToDosDateTime:dword
    extrn '__imp__FileTimeToLocalFileTime@8' as FileTimeToLocalFileTime:dword
    extrn '__imp__FileTimeToSystemTime@8' as FileTimeToSystemTime:dword
    extrn '__imp__FillConsoleOutputAttribute@20' as FillConsoleOutputAttribute:dword
    extrn '__imp__FillConsoleOutputCharacterA@20' as FillConsoleOutputCharacterA:dword
    extrn '__imp__FillConsoleOutputCharacterW@20' as FillConsoleOutputCharacterW:dword
    extrn '__imp__FindAtomA@4' as FindAtomA:dword
    extrn '__imp__FindAtomW@4' as FindAtomW:dword
    extrn '__imp__FindClose@4' as FindClose:dword
    extrn '__imp__FindCloseChangeNotification@4' as FindCloseChangeNotification:dword
    extrn '__imp__FindFirstChangeNotificationA@12' as FindFirstChangeNotificationA:dword
    extrn '__imp__FindFirstChangeNotificationW@12' as FindFirstChangeNotificationW:dword
    extrn '__imp__FindFirstFileA@8' as FindFirstFileA:dword
    extrn '__imp__FindFirstFileW@8' as FindFirstFileW:dword
    extrn '__imp__FindNextChangeNotification@4' as FindNextChangeNotification:dword
    extrn '__imp__FindNextFileA@8' as FindNextFileA:dword
    extrn '__imp__FindNextFileW@8' as FindNextFileW:dword
    extrn '__imp__FindResourceA@12' as FindResourceA:dword
    extrn '__imp__FindResourceExA@16' as FindResourceExA:dword
    extrn '__imp__FindResourceExW@16' as FindResourceExW:dword
    extrn '__imp__FindResourceW@12' as FindResourceW:dword
    extrn '__imp__FlushConsoleInputBuffer@4' as FlushConsoleInputBuffer:dword
    extrn '__imp__FlushFileBuffers@4' as FlushFileBuffers:dword
    extrn '__imp__FlushInstructionCache@12' as FlushInstructionCache:dword
    extrn '__imp__FlushViewOfFile@8' as FlushViewOfFile:dword
    extrn '__imp__FoldStringA@20' as FoldStringA:dword
    extrn '__imp__FoldStringW@20' as FoldStringW:dword
    extrn '__imp__FormatMessageA@28' as FormatMessageA:dword
    extrn '__imp__FormatMessageW@28' as FormatMessageW:dword
    extrn '__imp__FreeConsole@0' as FreeConsole:dword
    extrn '__imp__FreeEnvironmentStringsA@4' as FreeEnvironmentStringsA:dword
    extrn '__imp__FreeEnvironmentStringsW@4' as FreeEnvironmentStringsW:dword
    extrn '__imp__FreeLibrary@4' as FreeLibrary:dword
    extrn '__imp__FreeLibraryAndExitThread@8' as FreeLibraryAndExitThread:dword
    extrn '__imp__FreeResource@4' as FreeResource:dword
    extrn '__imp__GenerateConsoleCtrlEvent@8' as GenerateConsoleCtrlEvent:dword
    extrn '__imp__GetACP@0' as GetACP:dword
    extrn '__imp__GetAtomNameA@12' as GetAtomNameA:dword
    extrn '__imp__GetAtomNameW@12' as GetAtomNameW:dword
    extrn '__imp__GetBinaryTypeA@8' as GetBinaryTypeA:dword
    extrn '__imp__GetBinaryTypeW@8' as GetBinaryTypeW:dword
    extrn '__imp__GetCommandLineA@0' as GetCommandLineA:dword
    extrn '__imp__GetCommandLineW@0' as GetCommandLineW:dword
    extrn '__imp__GetCommConfig@12' as GetCommConfig:dword
    extrn '__imp__GetCommMask@8' as GetCommMask:dword
    extrn '__imp__GetCommModemStatus@8' as GetCommModemStatus:dword
    extrn '__imp__GetCommProperties@8' as GetCommProperties:dword
    extrn '__imp__GetCommState@8' as GetCommState:dword
    extrn '__imp__GetCommTimeouts@8' as GetCommTimeouts:dword
    extrn '__imp__GetCompressedFileSizeA@8' as GetCompressedFileSizeA:dword
    extrn '__imp__GetCompressedFileSizeW@8' as GetCompressedFileSizeW:dword
    extrn '__imp__GetComputerNameA@8' as GetComputerNameA:dword
    extrn '__imp__GetComputerNameW@8' as GetComputerNameW:dword
    extrn '__imp__GetConsoleCP@0' as GetConsoleCP:dword
    extrn '__imp__GetConsoleCursorInfo@8' as GetConsoleCursorInfo:dword
    extrn '__imp__GetConsoleMode@8' as GetConsoleMode:dword
    extrn '__imp__GetConsoleOutputCP@0' as GetConsoleOutputCP:dword
    extrn '__imp__GetConsoleScreenBufferInfo@8' as GetConsoleScreenBufferInfo:dword
    extrn '__imp__GetConsoleTitleA@8' as GetConsoleTitleA:dword
    extrn '__imp__GetConsoleTitleW@8' as GetConsoleTitleW:dword
    extrn '__imp__GetCPInfo@8' as GetCPInfo:dword
    extrn '__imp__GetCurrencyFormatA@24' as GetCurrencyFormatA:dword
    extrn '__imp__GetCurrencyFormatW@24' as GetCurrencyFormatW:dword
    extrn '__imp__GetCurrentDirectoryA@8' as GetCurrentDirectoryA:dword
    extrn '__imp__GetCurrentDirectoryW@8' as GetCurrentDirectoryW:dword
    extrn '__imp__GetCurrentProcess@0' as GetCurrentProcess:dword
    extrn '__imp__GetCurrentProcessId@0' as GetCurrentProcessId:dword
    extrn '__imp__GetCurrentThread@0' as GetCurrentThread:dword
    extrn '__imp__GetCurrentThreadId@0' as GetCurrentThreadId:dword
    extrn '__imp__GetDateFormatA@24' as GetDateFormatA:dword
    extrn '__imp__GetDateFormatW@24' as GetDateFormatW:dword
    extrn '__imp__GetDefaultCommConfigA@12' as GetDefaultCommConfigA:dword
    extrn '__imp__GetDefaultCommConfigW@12' as GetDefaultCommConfigW:dword
    extrn '__imp__GetDiskFreeSpaceA@20' as GetDiskFreeSpaceA:dword
    extrn '__imp__GetDiskFreeSpaceExA@16' as GetDiskFreeSpaceExA:dword
    extrn '__imp__GetDiskFreeSpaceExW@16' as GetDiskFreeSpaceExW:dword
    extrn '__imp__GetDiskFreeSpaceW@20' as GetDiskFreeSpaceW:dword
    extrn '__imp__GetDriveTypeA@4' as GetDriveTypeA:dword
    extrn '__imp__GetDriveTypeW@4' as GetDriveTypeW:dword
    extrn '__imp__GetEnvironmentStringsA@0' as GetEnvironmentStringsA:dword
    extrn '__imp__GetEnvironmentStringsW@0' as GetEnvironmentStringsW:dword
    extrn '__imp__GetEnvironmentVariableA@12' as GetEnvironmentVariableA:dword
    extrn '__imp__GetEnvironmentVariableW@12' as GetEnvironmentVariableW:dword
    ;   ------------------------------ Not present in MASM32 kernel32.lib -------------------------------
    ;    if (NTDDI_VERSION = NTDDI_WIN95 | NTDDI_VERSION = NTDDI_WIN98_ME | NTDDI_VERSION >= NTDDI_VISTA)
    ;        extrn '__imp__GetErrorMode@0' as GetErrorMode:dword
    ;    end if
    ;   -------------------------------------------------------------------------------------------------
    extrn '__imp__GetExitCodeProcess@8' as GetExitCodeProcess:dword
    extrn '__imp__GetExitCodeThread@8' as GetExitCodeThread:dword
    extrn '__imp__GetFileAttributesA@4' as GetFileAttributesA:dword
    extrn '__imp__GetFileAttributesW@4' as GetFileAttributesW:dword
    extrn '__imp__GetFileInformationByHandle@8' as GetFileInformationByHandle:dword
    extrn '__imp__GetFileSize@8' as GetFileSize:dword
    extrn '__imp__GetFileTime@16' as GetFileTime:dword
    extrn '__imp__GetFileType@4' as GetFileType:dword
    extrn '__imp__GetFullPathNameA@16' as GetFullPathNameA:dword
    extrn '__imp__GetFullPathNameW@16' as GetFullPathNameW:dword
    ;    if (NTDDI_VERSION = NTDDI_WIN95 | NTDDI_VERSION = NTDDI_WIN98_ME | NTDDI_VERSION = NTDDI_WINXP | NTDDI_VERSION = NTDDI_VISTA)
    ;        extrn '__imp__GetHandleContext@4' as GetHandleContext:dword ;Not present in MASM32 kernel32.lib
    ;        extrn '__imp__SetHandleContext@8' as SetHandleContext:dword ;Not present in MASM32 kernel32.lib
    ;    end if
    extrn '__imp__GetHandleInformation@8' as GetHandleInformation:dword
    extrn '__imp__GetLargestConsoleWindowSize@4' as GetLargestConsoleWindowSize:dword
    extrn '__imp__GetLastError@0' as GetLastError:dword
    extrn '__imp__GetLocaleInfoA@16' as GetLocaleInfoA:dword
    extrn '__imp__GetLocaleInfoW@16' as GetLocaleInfoW:dword
    extrn '__imp__GetLocalTime@4' as GetLocalTime:dword
    extrn '__imp__GetLogicalDrives@0' as GetLogicalDrives:dword
    extrn '__imp__GetLogicalDriveStringsA@8' as GetLogicalDriveStringsA:dword
    extrn '__imp__GetLogicalDriveStringsW@8' as GetLogicalDriveStringsW:dword
    extrn '__imp__GetMailslotInfo@20' as GetMailslotInfo:dword
    extrn '__imp__GetModuleFileNameA@12' as GetModuleFileNameA:dword
    extrn '__imp__GetModuleFileNameW@12' as GetModuleFileNameW:dword
    extrn '__imp__GetModuleHandleA@4' as GetModuleHandleA:dword
    extrn '__imp__GetModuleHandleW@4' as GetModuleHandleW:dword
    extrn '__imp__GetNamedPipeHandleStateA@28' as GetNamedPipeHandleStateA:dword
    extrn '__imp__GetNamedPipeHandleStateW@28' as GetNamedPipeHandleStateW:dword
    extrn '__imp__GetNamedPipeInfo@20' as GetNamedPipeInfo:dword
    extrn '__imp__GetNumberFormatA@24' as GetNumberFormatA:dword
    extrn '__imp__GetNumberFormatW@24' as GetNumberFormatW:dword
    extrn '__imp__GetNumberOfConsoleInputEvents@8' as GetNumberOfConsoleInputEvents:dword
    extrn '__imp__GetNumberOfConsoleMouseButtons@4' as GetNumberOfConsoleMouseButtons:dword
    extrn '__imp__GetOEMCP@0' as GetOEMCP:dword
    extrn '__imp__GetOverlappedResult@16' as GetOverlappedResult:dword
    extrn '__imp__GetPriorityClass@4' as GetPriorityClass:dword
    extrn '__imp__GetPrivateProfileIntA@16' as GetPrivateProfileIntA:dword
    extrn '__imp__GetPrivateProfileIntW@16' as GetPrivateProfileIntW:dword
    extrn '__imp__GetPrivateProfileSectionA@16' as GetPrivateProfileSectionA:dword
    extrn '__imp__GetPrivateProfileSectionNamesA@12' as GetPrivateProfileSectionNamesA:dword
    extrn '__imp__GetPrivateProfileSectionNamesW@12' as GetPrivateProfileSectionNamesW:dword
    extrn '__imp__GetPrivateProfileSectionW@16' as GetPrivateProfileSectionW:dword
    extrn '__imp__GetPrivateProfileStringA@24' as GetPrivateProfileStringA:dword
    extrn '__imp__GetPrivateProfileStringW@24' as GetPrivateProfileStringW:dword
    extrn '__imp__GetPrivateProfileStructA@20' as GetPrivateProfileStructA:dword
    extrn '__imp__GetPrivateProfileStructW@20' as GetPrivateProfileStructW:dword
    extrn '__imp__GetProcAddress@8' as GetProcAddress:dword
    extrn '__imp__GetProcessAffinityMask@12' as GetProcessAffinityMask:dword
    extrn '__imp__GetProcessHeap@0' as GetProcessHeap:dword
    extrn '__imp__GetProcessHeaps@8' as GetProcessHeaps:dword
    extrn '__imp__GetProcessShutdownParameters@8' as GetProcessShutdownParameters:dword
    extrn '__imp__GetProcessTimes@20' as GetProcessTimes:dword
    extrn '__imp__GetProcessVersion@4' as GetProcessVersion:dword
    extrn '__imp__GetProcessWorkingSetSize@12' as GetProcessWorkingSetSize:dword
    extrn '__imp__GetProfileIntA@12' as GetProfileIntA:dword
    extrn '__imp__GetProfileIntW@12' as GetProfileIntW:dword
    extrn '__imp__GetProfileSectionA@12' as GetProfileSectionA:dword
    extrn '__imp__GetProfileSectionW@12' as GetProfileSectionW:dword
    extrn '__imp__GetProfileStringA@20' as GetProfileStringA:dword
    extrn '__imp__GetProfileStringW@20' as GetProfileStringW:dword
    extrn '__imp__GetQueuedCompletionStatus@20' as GetQueuedCompletionStatus:dword
    extrn '__imp__GetShortPathNameA@12' as GetShortPathNameA:dword
    extrn '__imp__GetShortPathNameW@12' as GetShortPathNameW:dword
    extrn '__imp__GetStartupInfoA@4' as GetStartupInfoA:dword
    extrn '__imp__GetStartupInfoW@4' as GetStartupInfoW:dword
    extrn '__imp__GetStdHandle@4' as GetStdHandle:dword
    extrn '__imp__GetStringTypeA@20' as GetStringTypeA:dword
    extrn '__imp__GetStringTypeExA@20' as GetStringTypeExA:dword
    extrn '__imp__GetStringTypeExW@20' as GetStringTypeExW:dword
    extrn '__imp__GetStringTypeW@16' as GetStringTypeW:dword
    extrn '__imp__GetSystemDefaultLangID@0' as GetSystemDefaultLangID:dword
    extrn '__imp__GetSystemDefaultLCID@0' as GetSystemDefaultLCID:dword
    extrn '__imp__GetSystemDirectoryA@8' as GetSystemDirectoryA:dword
    extrn '__imp__GetSystemDirectoryW@8' as GetSystemDirectoryW:dword
    extrn '__imp__GetSystemInfo@4' as GetSystemInfo:dword
    extrn '__imp__GetSystemPowerStatus@4' as GetSystemPowerStatus:dword
    extrn '__imp__GetSystemTime@4' as GetSystemTime:dword
    extrn '__imp__GetSystemTimeAdjustment@12' as GetSystemTimeAdjustment:dword
    extrn '__imp__GetSystemTimeAsFileTime@4' as GetSystemTimeAsFileTime:dword
    extrn '__imp__GetTapeParameters@16' as GetTapeParameters:dword
    extrn '__imp__GetTapePosition@20' as GetTapePosition:dword
    extrn '__imp__GetTapeStatus@4' as GetTapeStatus:dword
    extrn '__imp__GetTempFileNameA@16' as GetTempFileNameA:dword
    extrn '__imp__GetTempFileNameW@16' as GetTempFileNameW:dword
    extrn '__imp__GetTempPathA@8' as GetTempPathA:dword
    extrn '__imp__GetTempPathW@8' as GetTempPathW:dword
    extrn '__imp__GetThreadContext@8' as GetThreadContext:dword
    extrn '__imp__GetThreadLocale@0' as GetThreadLocale:dword
    extrn '__imp__GetThreadPriority@4' as GetThreadPriority:dword
    extrn '__imp__GetThreadSelectorEntry@12' as GetThreadSelectorEntry:dword
    extrn '__imp__GetThreadTimes@20' as GetThreadTimes:dword
    extrn '__imp__GetTickCount@0' as GetTickCount:dword
    extrn '__imp__GetTimeFormatA@24' as GetTimeFormatA:dword
    extrn '__imp__GetTimeFormatW@24' as GetTimeFormatW:dword
    extrn '__imp__GetTimeZoneInformation@4' as GetTimeZoneInformation:dword
    extrn '__imp__GetUserDefaultLangID@0' as GetUserDefaultLangID:dword
    extrn '__imp__GetUserDefaultLCID@0' as GetUserDefaultLCID:dword
    extrn '__imp__GetVersion@0' as GetVersion:dword
    extrn '__imp__GetVersionExA@4' as GetVersionExA:dword
    extrn '__imp__GetVersionExW@4' as GetVersionExW:dword
    extrn '__imp__GetVolumeInformationA@32' as GetVolumeInformationA:dword
    extrn '__imp__GetVolumeInformationW@32' as GetVolumeInformationW:dword
    extrn '__imp__GetWindowsDirectoryA@8' as GetWindowsDirectoryA:dword
    extrn '__imp__GetWindowsDirectoryW@8' as GetWindowsDirectoryW:dword
    extrn '__imp__GlobalAddAtomA@4' as GlobalAddAtomA:dword
    extrn '__imp__GlobalAddAtomW@4' as GlobalAddAtomW:dword
    extrn '__imp__GlobalAlloc@8' as GlobalAlloc:dword
    extrn '__imp__GlobalCompact@4' as GlobalCompact:dword
    extrn '__imp__GlobalDeleteAtom@4' as GlobalDeleteAtom:dword
    extrn '__imp__GlobalFindAtomA@4' as GlobalFindAtomA:dword
    extrn '__imp__GlobalFindAtomW@4' as GlobalFindAtomW:dword
    extrn '__imp__GlobalFix@4' as GlobalFix:dword
    extrn '__imp__GlobalFlags@4' as GlobalFlags:dword
    extrn '__imp__GlobalFree@4' as GlobalFree:dword
    extrn '__imp__GlobalGetAtomNameA@12' as GlobalGetAtomNameA:dword
    extrn '__imp__GlobalGetAtomNameW@12' as GlobalGetAtomNameW:dword
    extrn '__imp__GlobalHandle@4' as GlobalHandle:dword
    extrn '__imp__GlobalLock@4' as GlobalLock:dword
    extrn '__imp__GlobalMemoryStatus@4' as GlobalMemoryStatus:dword
    extrn '__imp__GlobalReAlloc@12' as GlobalReAlloc:dword
    extrn '__imp__GlobalSize@4' as GlobalSize:dword
    extrn '__imp__GlobalUnfix@4' as GlobalUnfix:dword
    extrn '__imp__GlobalUnlock@4' as GlobalUnlock:dword
    extrn '__imp__GlobalUnWire@4' as GlobalUnWire:dword
    extrn '__imp__GlobalWire@4' as GlobalWire:dword
    extrn '__imp__Heap32First@12' as Heap32First:dword
    extrn '__imp__Heap32ListFirst@8' as Heap32ListFirst:dword
    extrn '__imp__Heap32ListNext@8' as Heap32ListNext:dword
    extrn '__imp__Heap32Next@4' as Heap32Next:dword
    extrn '__imp__HeapAlloc@12' as HeapAlloc:dword
    extrn '__imp__HeapCompact@8' as HeapCompact:dword
    extrn '__imp__HeapCreate@12' as HeapCreate:dword
    extrn '__imp__HeapDestroy@4' as HeapDestroy:dword
    extrn '__imp__HeapFree@12' as HeapFree:dword
    extrn '__imp__HeapLock@4' as HeapLock:dword
    extrn '__imp__HeapReAlloc@16' as HeapReAlloc:dword
    extrn '__imp__HeapSize@12' as HeapSize:dword
    extrn '__imp__HeapUnlock@4' as HeapUnlock:dword
    extrn '__imp__HeapValidate@12' as HeapValidate:dword
    extrn '__imp__HeapWalk@8' as HeapWalk:dword
    extrn '__imp__InitAtomTable@4' as InitAtomTable:dword
    extrn '__imp__InitializeCriticalSection@4' as InitializeCriticalSection:dword
    extrn '__imp__IsBadCodePtr@4' as IsBadCodePtr:dword
    extrn '__imp__IsBadHugeReadPtr@8' as IsBadHugeReadPtr:dword
    extrn '__imp__IsBadHugeWritePtr@8' as IsBadHugeWritePtr:dword
    extrn '__imp__IsBadReadPtr@8' as IsBadReadPtr:dword
    extrn '__imp__IsBadStringPtrA@8' as IsBadStringPtrA:dword
    extrn '__imp__IsBadStringPtrW@8' as IsBadStringPtrW:dword
    extrn '__imp__IsBadWritePtr@8' as IsBadWritePtr:dword
    extrn '__imp__IsDBCSLeadByte@4' as IsDBCSLeadByte:dword
    extrn '__imp__IsDBCSLeadByteEx@8' as IsDBCSLeadByteEx:dword
    extrn '__imp__IsValidCodePage@4' as IsValidCodePage:dword
    extrn '__imp__IsValidLocale@8' as IsValidLocale:dword
    extrn '__imp__LCMapStringA@24' as LCMapStringA:dword
    extrn '__imp__LCMapStringW@24' as LCMapStringW:dword
    extrn '__imp__LeaveCriticalSection@4' as LeaveCriticalSection:dword
    extrn '__imp__LoadLibraryA@4' as LoadLibraryA:dword
    extrn '__imp__LoadLibraryExA@12' as LoadLibraryExA:dword
    extrn '__imp__LoadLibraryExW@12' as LoadLibraryExW:dword
    extrn '__imp__LoadLibraryW@4' as LoadLibraryW:dword
    extrn '__imp__LoadModule@8' as LoadModule:dword
    extrn '__imp__LoadResource@8' as LoadResource:dword
    extrn '__imp__LocalAlloc@8' as LocalAlloc:dword
    extrn '__imp__LocalCompact@4' as LocalCompact:dword
    extrn '__imp__LocalFileTimeToFileTime@8' as LocalFileTimeToFileTime:dword
    extrn '__imp__LocalFlags@4' as LocalFlags:dword
    extrn '__imp__LocalFree@4' as LocalFree:dword
    extrn '__imp__LocalHandle@4' as LocalHandle:dword
    extrn '__imp__LocalLock@4' as LocalLock:dword
    extrn '__imp__LocalReAlloc@12' as LocalReAlloc:dword
    extrn '__imp__LocalShrink@8' as LocalShrink:dword
    extrn '__imp__LocalSize@4' as LocalSize:dword
    extrn '__imp__LocalUnlock@4' as LocalUnlock:dword
    extrn '__imp__LockFile@20' as LockFile:dword
    extrn '__imp__LockFileEx@24' as LockFileEx:dword
    extrn '__imp__LockResource@4' as LockResource:dword
    extrn '__imp__lstrcatA@8' as lstrcatA:dword
    extrn '__imp__lstrcatW@8' as lstrcatW:dword
    extrn '__imp__lstrcmpA@8' as lstrcmpA:dword
    extrn '__imp__lstrcmpiA@8' as lstrcmpiA:dword
    extrn '__imp__lstrcmpiW@8' as lstrcmpiW:dword
    extrn '__imp__lstrcmpW@8' as lstrcmpW:dword
    extrn '__imp__lstrcpyA@8' as lstrcpyA:dword
    extrn '__imp__lstrcpynA@12' as lstrcpynA:dword
    extrn '__imp__lstrcpynW@12' as lstrcpynW:dword
    extrn '__imp__lstrcpyW@8' as lstrcpyW:dword
    extrn '__imp__lstrlenA@4' as lstrlenA:dword
    extrn '__imp__lstrlenW@4' as lstrlenW:dword
    extrn '__imp__MapViewOfFile@20' as MapViewOfFile:dword
    extrn '__imp__MapViewOfFileEx@24' as MapViewOfFileEx:dword
    extrn '__imp__MoveFileA@8' as MoveFileA:dword
    extrn '__imp__MoveFileExA@12' as MoveFileExA:dword
    extrn '__imp__MoveFileExW@12' as MoveFileExW:dword
    extrn '__imp__MoveFileW@8' as MoveFileW:dword
    extrn '__imp__MulDiv@12' as MulDiv:dword
    extrn '__imp__MultiByteToWideChar@24' as MultiByteToWideChar:dword
    extrn '__imp__OpenEventA@12' as OpenEventA:dword
    extrn '__imp__OpenEventW@12' as OpenEventW:dword
    extrn '__imp__OpenFile@12' as OpenFile:dword
    extrn '__imp__OpenFileMappingA@12' as OpenFileMappingA:dword
    extrn '__imp__OpenFileMappingW@12' as OpenFileMappingW:dword
    extrn '__imp__OpenMutexA@12' as OpenMutexA:dword
    extrn '__imp__OpenMutexW@12' as OpenMutexW:dword
    extrn '__imp__OpenProcess@12' as OpenProcess:dword
    ;extrn '__imp__OpenProfileUserMapping@0' as OpenProfileUserMapping:dword ;Not present in MASM32 kernel32.lib
    extrn '__imp__OpenSemaphoreA@12' as OpenSemaphoreA:dword
    extrn '__imp__OpenSemaphoreW@12' as OpenSemaphoreW:dword
    extrn '__imp__OutputDebugStringA@4' as OutputDebugStringA:dword
    extrn '__imp__OutputDebugStringW@4' as OutputDebugStringW:dword
    extrn '__imp__PeekConsoleInputA@16' as PeekConsoleInputA:dword
    extrn '__imp__PeekConsoleInputW@16' as PeekConsoleInputW:dword
    extrn '__imp__PeekNamedPipe@24' as PeekNamedPipe:dword
    extrn '__imp__PostQueuedCompletionStatus@16' as PostQueuedCompletionStatus:dword
    extrn '__imp__PrepareTape@12' as PrepareTape:dword
    extrn '__imp__PulseEvent@4' as PulseEvent:dword
    extrn '__imp__PurgeComm@8' as PurgeComm:dword
    extrn '__imp__QueryDosDeviceA@12' as QueryDosDeviceA:dword
    extrn '__imp__QueryDosDeviceW@12' as QueryDosDeviceW:dword
    extrn '__imp__QueryPerformanceCounter@4' as QueryPerformanceCounter:dword
    extrn '__imp__QueryPerformanceFrequency@4' as QueryPerformanceFrequency:dword
    extrn '__imp__QueueUserAPC@12' as QueueUserAPC:dword
    extrn '__imp__RaiseException@16' as RaiseException:dword
    extrn '__imp__ReadConsoleA@20' as ReadConsoleA:dword
    extrn '__imp__ReadConsoleInputA@16' as ReadConsoleInputA:dword
    extrn '__imp__ReadConsoleInputW@16' as ReadConsoleInputW:dword
    extrn '__imp__ReadConsoleOutputA@20' as ReadConsoleOutputA:dword
    extrn '__imp__ReadConsoleOutputAttribute@20' as ReadConsoleOutputAttribute:dword
    extrn '__imp__ReadConsoleOutputCharacterA@20' as ReadConsoleOutputCharacterA:dword
    extrn '__imp__ReadConsoleOutputCharacterW@20' as ReadConsoleOutputCharacterW:dword
    extrn '__imp__ReadConsoleOutputW@20' as ReadConsoleOutputW:dword
    extrn '__imp__ReadConsoleW@20' as ReadConsoleW:dword
    extrn '__imp__ReadFile@20' as ReadFile:dword
    extrn '__imp__ReadFileEx@20' as ReadFileEx:dword
    extrn '__imp__ReadProcessMemory@20' as ReadProcessMemory:dword
    extrn '__imp__ReleaseMutex@4' as ReleaseMutex:dword
    extrn '__imp__ReleaseSemaphore@12' as ReleaseSemaphore:dword
    extrn '__imp__RemoveDirectoryA@4' as RemoveDirectoryA:dword
    extrn '__imp__RemoveDirectoryW@4' as RemoveDirectoryW:dword
    extrn '__imp__ResetEvent@4' as ResetEvent:dword
    extrn '__imp__ResumeThread@4' as ResumeThread:dword
    extrn '__imp__RtlFillMemory@12' as RtlFillMemory:dword
    extrn '__imp__RtlMoveMemory@12' as RtlMoveMemory:dword
    extrn '__imp__RtlZeroMemory@8' as RtlZeroMemory:dword
    extrn '__imp__RtlUnwind@16' as RtlUnwind:dword
    extrn '__imp__ScrollConsoleScreenBufferA@20' as ScrollConsoleScreenBufferA:dword
    extrn '__imp__ScrollConsoleScreenBufferW@20' as ScrollConsoleScreenBufferW:dword
    extrn '__imp__SearchPathA@24' as SearchPathA:dword
    extrn '__imp__SearchPathW@24' as SearchPathW:dword
    extrn '__imp__SetCommBreak@4' as SetCommBreak:dword
    extrn '__imp__SetCommConfig@12' as SetCommConfig:dword
    extrn '__imp__SetCommMask@8' as SetCommMask:dword
    extrn '__imp__SetCommState@8' as SetCommState:dword
    extrn '__imp__SetCommTimeouts@8' as SetCommTimeouts:dword
    extrn '__imp__SetComputerNameA@4' as SetComputerNameA:dword
    extrn '__imp__SetComputerNameW@4' as SetComputerNameW:dword
    extrn '__imp__SetConsoleActiveScreenBuffer@4' as SetConsoleActiveScreenBuffer:dword
    extrn '__imp__SetConsoleCP@4' as SetConsoleCP:dword
    extrn '__imp__SetConsoleCtrlHandler@8' as SetConsoleCtrlHandler:dword
    extrn '__imp__SetConsoleCursorInfo@8' as SetConsoleCursorInfo:dword
    extrn '__imp__SetConsoleCursorPosition@8' as SetConsoleCursorPosition:dword
    extrn '__imp__SetConsoleMode@8' as SetConsoleMode:dword
    extrn '__imp__SetConsoleOutputCP@4' as SetConsoleOutputCP:dword
    extrn '__imp__SetConsoleScreenBufferSize@8' as SetConsoleScreenBufferSize:dword
    extrn '__imp__SetConsoleTextAttribute@8' as SetConsoleTextAttribute:dword
    extrn '__imp__SetConsoleTitleA@4' as SetConsoleTitleA:dword
    extrn '__imp__SetConsoleTitleW@4' as SetConsoleTitleW:dword
    extrn '__imp__SetConsoleWindowInfo@12' as SetConsoleWindowInfo:dword
    extrn '__imp__SetCurrentDirectoryA@4' as SetCurrentDirectoryA:dword
    extrn '__imp__SetCurrentDirectoryW@4' as SetCurrentDirectoryW:dword
    extrn '__imp__SetDefaultCommConfigA@12' as SetDefaultCommConfigA:dword
    extrn '__imp__SetDefaultCommConfigW@12' as SetDefaultCommConfigW:dword
    extrn '__imp__SetEndOfFile@4' as SetEndOfFile:dword
    extrn '__imp__SetEnvironmentVariableA@8' as SetEnvironmentVariableA:dword
    extrn '__imp__SetEnvironmentVariableW@8' as SetEnvironmentVariableW:dword
    extrn '__imp__SetErrorMode@4' as SetErrorMode:dword
    extrn '__imp__SetEvent@4' as SetEvent:dword
    extrn '__imp__SetFileApisToANSI@0' as SetFileApisToANSI:dword
    extrn '__imp__SetFileApisToOEM@0' as SetFileApisToOEM:dword
    extrn '__imp__SetFileAttributesA@8' as SetFileAttributesA:dword
    extrn '__imp__SetFileAttributesW@8' as SetFileAttributesW:dword
    extrn '__imp__SetFilePointer@16' as SetFilePointer:dword
    extrn '__imp__SetFileTime@16' as SetFileTime:dword
    extrn '__imp__SetHandleCount@4' as SetHandleCount:dword
    extrn '__imp__SetHandleInformation@12' as SetHandleInformation:dword
    extrn '__imp__SetLastError@4' as SetLastError:dword
    extrn '__imp__SetLocaleInfoA@12' as SetLocaleInfoA:dword
    extrn '__imp__SetLocaleInfoW@12' as SetLocaleInfoW:dword
    extrn '__imp__SetLocalTime@4' as SetLocalTime:dword
    extrn '__imp__SetMailslotInfo@8' as SetMailslotInfo:dword
    extrn '__imp__SetNamedPipeHandleState@16' as SetNamedPipeHandleState:dword
    extrn '__imp__SetPriorityClass@8' as SetPriorityClass:dword
    extrn '__imp__SetProcessShutdownParameters@8' as SetProcessShutdownParameters:dword
    extrn '__imp__SetProcessWorkingSetSize@12' as SetProcessWorkingSetSize:dword
    extrn '__imp__SetStdHandle@8' as SetStdHandle:dword
    extrn '__imp__SetSystemPowerState@8' as SetSystemPowerState:dword
    extrn '__imp__SetSystemTime@4' as SetSystemTime:dword
    extrn '__imp__SetSystemTimeAdjustment@8' as SetSystemTimeAdjustment:dword
    extrn '__imp__SetTapeParameters@12' as SetTapeParameters:dword
    extrn '__imp__SetTapePosition@24' as SetTapePosition:dword
    extrn '__imp__SetThreadAffinityMask@8' as SetThreadAffinityMask:dword
    extrn '__imp__SetThreadContext@8' as SetThreadContext:dword
    extrn '__imp__SetThreadLocale@4' as SetThreadLocale:dword
    extrn '__imp__SetThreadPriority@8' as SetThreadPriority:dword
    extrn '__imp__SetTimeZoneInformation@4' as SetTimeZoneInformation:dword
    extrn '__imp__SetUnhandledExceptionFilter@4' as SetUnhandledExceptionFilter:dword
    extrn '__imp__SetupComm@12' as SetupComm:dword
    extrn '__imp__SetVolumeLabelA@8' as SetVolumeLabelA:dword
    extrn '__imp__SetVolumeLabelW@8' as SetVolumeLabelW:dword
    extrn '__imp__SizeofResource@8' as SizeofResource:dword
    extrn '__imp__Sleep@4' as Sleep:dword
    extrn '__imp__SleepEx@8' as SleepEx:dword
    extrn '__imp__SuspendThread@4' as SuspendThread:dword
    extrn '__imp__SystemTimeToFileTime@8' as SystemTimeToFileTime:dword
    extrn '__imp__SystemTimeToTzSpecificLocalTime@12' as SystemTimeToTzSpecificLocalTime:dword
    extrn '__imp__TerminateProcess@8' as TerminateProcess:dword
    extrn '__imp__TerminateThread@8' as TerminateThread:dword
    extrn '__imp__Thread32First@8' as Thread32First:dword
    extrn '__imp__Thread32Next@8' as Thread32Next:dword
    extrn '__imp__TlsAlloc@0' as TlsAlloc:dword
    extrn '__imp__TlsFree@4' as TlsFree:dword
    extrn '__imp__TlsGetValue@4' as TlsGetValue:dword
    extrn '__imp__TlsSetValue@8' as TlsSetValue:dword
    extrn '__imp__Toolhelp32ReadProcessMemory@20' as Toolhelp32ReadProcessMemory:dword
    extrn '__imp__TransactNamedPipe@28' as TransactNamedPipe:dword
    extrn '__imp__TransmitCommChar@8' as TransmitCommChar:dword
    extrn '__imp__UnhandledExceptionFilter@4' as UnhandledExceptionFilter:dword
    extrn '__imp__UnlockFile@20' as UnlockFile:dword
    extrn '__imp__UnlockFileEx@20' as UnlockFileEx:dword
    extrn '__imp__UnmapViewOfFile@4' as UnmapViewOfFile:dword
    extrn '__imp__UpdateResourceA@24' as UpdateResourceA:dword
    extrn '__imp__UpdateResourceW@24' as UpdateResourceW:dword
    extrn '__imp__VirtualAlloc@16' as VirtualAlloc:dword
    extrn '__imp__VirtualFree@12' as VirtualFree:dword
    extrn '__imp__VirtualLock@8' as VirtualLock:dword
    extrn '__imp__VirtualProtect@16' as VirtualProtect:dword
    extrn '__imp__VirtualProtectEx@20' as VirtualProtectEx:dword
    extrn '__imp__VirtualQuery@12' as VirtualQuery:dword
    extrn '__imp__VirtualQueryEx@16' as VirtualQueryEx:dword
    extrn '__imp__VirtualUnlock@8' as VirtualUnlock:dword
    extrn '__imp__WaitCommEvent@12' as WaitCommEvent:dword
    extrn '__imp__WaitForDebugEvent@8' as WaitForDebugEvent:dword
    extrn '__imp__WaitForMultipleObjects@16' as WaitForMultipleObjects:dword
    extrn '__imp__WaitForMultipleObjectsEx@20' as WaitForMultipleObjectsEx:dword
    extrn '__imp__WaitForSingleObject@8' as WaitForSingleObject:dword
    extrn '__imp__WaitForSingleObjectEx@12' as WaitForSingleObjectEx:dword
    extrn '__imp__WaitNamedPipeA@8' as WaitNamedPipeA:dword
    extrn '__imp__WaitNamedPipeW@8' as WaitNamedPipeW:dword
    extrn '__imp__WideCharToMultiByte@32' as WideCharToMultiByte:dword
    extrn '__imp__WinExec@8' as WinExec:dword
    extrn '__imp__WriteConsoleA@20' as WriteConsoleA:dword
    extrn '__imp__WriteConsoleInputA@16' as WriteConsoleInputA:dword
    extrn '__imp__WriteConsoleInputW@16' as WriteConsoleInputW:dword
    extrn '__imp__WriteConsoleOutputA@20' as WriteConsoleOutputA:dword
    extrn '__imp__WriteConsoleOutputAttribute@20' as WriteConsoleOutputAttribute:dword
    extrn '__imp__WriteConsoleOutputCharacterA@20' as WriteConsoleOutputCharacterA:dword
    extrn '__imp__WriteConsoleOutputCharacterW@20' as WriteConsoleOutputCharacterW:dword
    extrn '__imp__WriteConsoleOutputW@20' as WriteConsoleOutputW:dword
    extrn '__imp__WriteConsoleW@20' as WriteConsoleW:dword
    extrn '__imp__WriteFile@20' as WriteFile:dword
    extrn '__imp__WriteFileEx@20' as WriteFileEx:dword
    extrn '__imp__WritePrivateProfileSectionA@12' as WritePrivateProfileSectionA:dword
    extrn '__imp__WritePrivateProfileSectionW@12' as WritePrivateProfileSectionW:dword
    extrn '__imp__WritePrivateProfileStringA@16' as WritePrivateProfileStringA:dword
    extrn '__imp__WritePrivateProfileStringW@16' as WritePrivateProfileStringW:dword
    extrn '__imp__WritePrivateProfileStructA@20' as WritePrivateProfileStructA:dword
    extrn '__imp__WritePrivateProfileStructW@20' as WritePrivateProfileStructW:dword
    extrn '__imp__WriteProcessMemory@20' as WriteProcessMemory:dword
    extrn '__imp__WriteProfileSectionA@8' as WriteProfileSectionA:dword
    extrn '__imp__WriteProfileSectionW@8' as WriteProfileSectionW:dword
    extrn '__imp__WriteProfileStringA@12' as WriteProfileStringA:dword
    extrn '__imp__WriteProfileStringW@12' as WriteProfileStringW:dword
    extrn '__imp__WriteTapemark@16' as WriteTapemark:dword

    GetFreeSpace equ GlobalMemoryStatus

    LockSegment equ GlobalFix
    UnlockSegment equ GlobalUnfix
    GetCurrentTime equ GetTickCount
    MoveMemory equ RtlMoveMemory
    FillMemory equ RtlFillMemory
    ZeroMemory equ RtlZeroMemory

    if (NTDDI_VERSION >= NTDDI_WIN98_ME)
        extrn '__imp__CancelDeviceWakeupRequest@4' as CancelDeviceWakeupRequest:dword
        extrn '__imp__CancelIo@4' as CancelIo:dword
        extrn '__imp__ConvertThreadToFiber@4' as ConvertThreadToFiber:dword
        extrn '__imp__CopyFileExA@24' as CopyFileExA:dword
        extrn '__imp__CopyFileExW@24' as CopyFileExW:dword
        extrn '__imp__CreateFiber@12' as CreateFiber:dword
        extrn '__imp__CreateWaitableTimerA@12' as CreateWaitableTimerA:dword
        extrn '__imp__CreateWaitableTimerW@12' as CreateWaitableTimerW:dword
        extrn '__imp__DeleteFiber@4' as DeleteFiber:dword
        extrn '__imp__EnumCalendarInfoExA@16' as EnumCalendarInfoExA:dword
        extrn '__imp__EnumCalendarInfoExW@16' as EnumCalendarInfoExW:dword
        extrn '__imp__EnumDateFormatsExA@12' as EnumDateFormatsExA:dword
        extrn '__imp__EnumDateFormatsExW@12' as EnumDateFormatsExW:dword
        extrn '__imp__FindFirstFileExA@24' as FindFirstFileExA:dword
        extrn '__imp__FindFirstFileExW@24' as FindFirstFileExW:dword
        extrn '__imp__GetCalendarInfoA@24' as GetCalendarInfoA:dword
        extrn '__imp__GetCalendarInfoW@24' as GetCalendarInfoW:dword
        extrn '__imp__GetCPInfoExA@12' as GetCPInfoExA:dword
        extrn '__imp__GetCPInfoExW@12' as GetCPInfoExW:dword
        extrn '__imp__GetDevicePowerState@8' as GetDevicePowerState:dword
        extrn '__imp__GetFileAttributesExA@12' as GetFileAttributesExA:dword
        extrn '__imp__GetFileAttributesExW@12' as GetFileAttributesExW:dword
        if (NTDDI_VERSION NTDDI_WINNT4)
            extrn '__imp__GetLongPathNameA@12' as GetLongPathNameA:dword
            extrn '__imp__GetLongPathNameW@12' as GetLongPathNameW:dword
            extrn '__imp__RequestDeviceWakeup@4' as RequestDeviceWakeup:dword
            extrn '__imp__RequestWakeupLatency@4' as RequestWakeupLatency:dword
            extrn '__imp__ResetWriteWatch@8' as ResetWriteWatch:dword
            extrn '__imp__SetCalendarInfoA@16' as SetCalendarInfoA:dword
            extrn '__imp__SetCalendarInfoW@16' as SetCalendarInfoW:dword
            extrn '__imp__SetMessageWaitingIndicator@8' as SetMessageWaitingIndicator:dword
            api GetLongPathName,\
                SetCalendarInfo
        end if
        extrn '__imp__GetProcessPriorityBoost@8' as GetProcessPriorityBoost:dword
        extrn '__imp__GetThreadPriorityBoost@8' as GetThreadPriorityBoost:dword
        extrn '__imp__InterlockedExchangeAdd@8' as InterlockedExchangeAdd:dword
        extrn '__imp__IsDebuggerPresent@0' as IsDebuggerPresent:dword
        extrn '__imp__IsProcessorFeaturePresent@4' as IsProcessorFeaturePresent:dword
        extrn '__imp__IsSystemResumeAutomatic@0' as IsSystemResumeAutomatic:dword
        extrn '__imp__OpenWaitableTimerA@12' as OpenWaitableTimerA:dword
        extrn '__imp__OpenWaitableTimerW@12' as OpenWaitableTimerW:dword
        extrn '__imp__ReadDirectoryChangesW@32' as ReadDirectoryChangesW:dword
        extrn '__imp__ReadFileScatter@20' as ReadFileScatter:dword
        extrn '__imp__SetCriticalSectionSpinCount@8' as SetCriticalSectionSpinCount:dword
        extrn '__imp__SetProcessAffinityMask@8' as SetProcessAffinityMask:dword
        extrn '__imp__SetProcessPriorityBoost@8' as SetProcessPriorityBoost:dword
        extrn '__imp__SetThreadExecutionState@4' as SetThreadExecutionState:dword
        extrn '__imp__SetThreadIdealProcessor@8' as SetThreadIdealProcessor:dword
        extrn '__imp__SetThreadPriorityBoost@8' as SetThreadPriorityBoost:dword
        extrn '__imp__SetWaitableTimer@24' as SetWaitableTimer:dword
        extrn '__imp__SignalObjectAndWait@16' as SignalObjectAndWait:dword
        extrn '__imp__SwitchToFiber@4' as SwitchToFiber:dword
        extrn '__imp__SwitchToThread@0' as SwitchToThread:dword
        extrn '__imp__VirtualAllocEx@20' as VirtualAllocEx:dword
        extrn '__imp__VirtualFreeEx@16' as VirtualFreeEx:dword
        extrn '__imp__WriteFileGather@20' as WriteFileGather:dword
        api CopyFileEx,\
            CreateWaitableTimer,\
            EnumCalendarInfoEx,\
            EnumDateFormatsEx,\
            FindFirstFileEx,\
            GetCalendarInfo,\
            GetCPInfoEx,\
            GetFileAttributesEx,\
            OpenWaitableTimer
    end if

    if (NTDDI_VERSION >= NTDDI_WINNT4)
        extrn '__imp__AddConsoleAliasA@12' as AddConsoleAliasA:dword
        extrn '__imp__AddConsoleAliasW@12' as AddConsoleAliasW:dword
        extrn '__imp__ConsoleMenuControl@12' as ConsoleMenuControl:dword
        extrn '__imp__CreateTimerQueue@0' as CreateTimerQueue:dword
        extrn '__imp__DuplicateConsoleHandle@16' as DuplicateConsoleHandle:dword
        extrn '__imp__ExitVDM@8' as ExitVDM:dword
        extrn '__imp__ExpungeConsoleCommandHistoryA@4' as ExpungeConsoleCommandHistoryA:dword
        extrn '__imp__ExpungeConsoleCommandHistoryW@4' as ExpungeConsoleCommandHistoryW:dword
        extrn '__imp__GetConsoleAliasA@16' as GetConsoleAliasA:dword
        extrn '__imp__GetConsoleAliasesA@12' as GetConsoleAliasesA:dword
        extrn '__imp__GetConsoleAliasesW@12' as GetConsoleAliasesW:dword
        extrn '__imp__GetConsoleAliasesLengthA@4' as GetConsoleAliasesLengthA:dword
        extrn '__imp__GetConsoleAliasesLengthW@4' as GetConsoleAliasesLengthW:dword
        extrn '__imp__GetConsoleAliasExesA@8' as GetConsoleAliasExesA:dword
        extrn '__imp__GetConsoleAliasExesW@8' as GetConsoleAliasExesW:dword
        extrn '__imp__GetConsoleAliasExesLengthA@0' as GetConsoleAliasExesLengthA:dword
        extrn '__imp__GetConsoleAliasExesLengthW@0' as GetConsoleAliasExesLengthW:dword
        extrn '__imp__GetConsoleAliasW@16' as GetConsoleAliasW:dword
        extrn '__imp__GetModuleHandleExA@12' as GetModuleHandleExA:dword
        extrn '__imp__GetModuleHandleExW@12' as GetModuleHandleExW:dword
        extrn '__imp__GetNextVDMCommand@4' as GetNextVDMCommand:dword
        extrn '__imp__GetNumberOfConsoleFonts@0' as GetNumberOfConsoleFonts:dword
        extrn '__imp__GetProcessIoCounters@8' as GetProcessIoCounters:dword
        extrn '__imp__GetVDMCurrentDirectories@8' as GetVDMCurrentDirectories:dword
        extrn '__imp__InvalidateConsoleDIBits@8' as InvalidateConsoleDIBits:dword
        extrn '__imp__OpenConsoleW@16' as OpenConsoleW:dword
        extrn '__imp__ReadConsoleInputExA@20' as ReadConsoleInputExA:dword
        extrn '__imp__ReadConsoleInputExW@20' as ReadConsoleInputExW:dword
        extrn '__imp__SetConsoleCursor@8' as SetConsoleCursor:dword
        extrn '__imp__SetConsoleHardwareState@8' as SetConsoleHardwareState:dword
        extrn '__imp__SetConsoleIcon@4' as SetConsoleIcon:dword
        extrn '__imp__SetConsoleMaximumWindowSize@8' as SetConsoleMaximumWindowSize:dword
        extrn '__imp__SetConsoleNumberOfCommandsA@8' as SetConsoleNumberOfCommandsA:dword
        extrn '__imp__SetConsoleNumberOfCommandsW@8' as SetConsoleNumberOfCommandsW:dword
        extrn '__imp__SetConsolePalette@4' as SetConsolePalette:dword
        extrn '__imp__SetLastConsoleEventActive@0' as SetLastConsoleEventActive:dword
        extrn '__imp__SetVDMCurrentDirectories@8' as SetVDMCurrentDirectories:dword
        extrn '__imp__ShowConsoleCursor@8' as ShowConsoleCursor:dword
        extrn '__imp__VerifyVersionInfoA@12' as VerifyVersionInfoA:dword
        extrn '__imp__VerifyVersionInfoW@12' as VerifyVersionInfoW:dword
        api AddConsoleAlias,\
            ExpungeConsoleCommandHistory,\
            GetConsoleAlias,\
            GetConsoleAliasExes,\
            GetConsoleAliasExesLength,\
            GetConsoleAliases,\
            GetConsoleAliasesLength,\
            GetModuleHandleEx,\
            ReadConsoleInputEx,\
            SetConsoleNumberOfCommands,\
            VerifyVersionInfo
    end if

    if (NTDDI_VERSION >= NTDDI_WIN2K)
        extrn '__imp__AllocateUserPhysicalPages@12' as AllocateUserPhysicalPages:dword
        extrn '__imp__AssignProcessToJobObject@8' as AssignProcessToJobObject:dword
        extrn '__imp__BindIoCompletionCallback@12' as BindIoCompletionCallback:dword
        extrn '__imp__ChangeTimerQueueTimer@16' as ChangeTimerQueueTimer:dword
        extrn '__imp__CreateHardLinkA@12' as CreateHardLinkA:dword
        extrn '__imp__CreateHardLinkW@12' as CreateHardLinkW:dword
        extrn '__imp__CreateJobObjectA@8' as CreateJobObjectA:dword
        extrn '__imp__CreateJobObjectW@8' as CreateJobObjectW:dword
        extrn '__imp__CreateTimerQueueTimer@28' as CreateTimerQueueTimer:dword
        extrn '__imp__DelayLoadFailureHook@8' as DelayLoadFailureHook:dword
        extrn '__imp__DeleteTimerQueue@4' as DeleteTimerQueue:dword
        extrn '__imp__DeleteVolumeMountPointA@4' as DeleteVolumeMountPointA:dword
        extrn '__imp__DeleteVolumeMountPointW@4' as DeleteVolumeMountPointW:dword
        extrn '__imp__DnsHostnameToComputerNameA@12' as DnsHostnameToComputerNameA:dword
        extrn '__imp__DnsHostnameToComputerNameW@12' as DnsHostnameToComputerNameW:dword
        extrn '__imp__DosPathToSessionPathA@12' as DosPathToSessionPathA:dword
        extrn '__imp__DosPathToSessionPathW@12' as DosPathToSessionPathW:dword
        extrn '__imp__EnumLanguageGroupLocalesA@16' as EnumLanguageGroupLocalesA:dword
        extrn '__imp__EnumLanguageGroupLocalesW@16' as EnumLanguageGroupLocalesW:dword
        extrn '__imp__EnumSystemLanguageGroupsA@12' as EnumSystemLanguageGroupsA:dword
        extrn '__imp__EnumSystemLanguageGroupsW@12' as EnumSystemLanguageGroupsW:dword
        extrn '__imp__EnumUILanguagesA@12' as EnumUILanguagesA:dword
        extrn '__imp__EnumUILanguagesW@12' as EnumUILanguagesW:dword
        extrn '__imp__FindFirstVolumeA@8' as FindFirstVolumeA:dword
        extrn '__imp__FindFirstVolumeMountPointA@12' as FindFirstVolumeMountPointA:dword
        extrn '__imp__FindFirstVolumeMountPointW@12' as FindFirstVolumeMountPointW:dword
        extrn '__imp__FindFirstVolumeW@8' as FindFirstVolumeW:dword
        extrn '__imp__FindNextVolumeA@12' as FindNextVolumeA:dword
        extrn '__imp__FindNextVolumeMountPointA@12' as FindNextVolumeMountPointA:dword
        extrn '__imp__FindNextVolumeMountPointW@12' as FindNextVolumeMountPointW:dword
        extrn '__imp__FindNextVolumeW@12' as FindNextVolumeW:dword
        extrn '__imp__FindVolumeClose@4' as FindVolumeClose:dword
        extrn '__imp__FindVolumeMountPointClose@4' as FindVolumeMountPointClose:dword
        extrn '__imp__FreeUserPhysicalPages@12' as FreeUserPhysicalPages:dword
        extrn '__imp__GetComputerNameExA@12' as GetComputerNameExA:dword
        extrn '__imp__GetComputerNameExW@12' as GetComputerNameExW:dword
        extrn '__imp__GetConsoleNlsMode@0' as GetConsoleNlsMode:dword
        extrn '__imp__GetConsoleWindow@0' as GetConsoleWindow:dword
        extrn '__imp__GetFileSizeEx@8' as GetFileSizeEx:dword
        extrn '__imp__GetSystemDefaultUILanguage@0' as GetSystemDefaultUILanguage:dword
        extrn '__imp__GetSystemWindowsDirectoryA@8' as GetSystemWindowsDirectoryA:dword
        extrn '__imp__GetSystemWindowsDirectoryW@8' as GetSystemWindowsDirectoryW:dword
        extrn '__imp__GetUserDefaultUILanguage@0' as GetUserDefaultUILanguage:dword
        extrn '__imp__GetVolumeNameForVolumeMountPointA@12' as GetVolumeNameForVolumeMountPointA:dword
        extrn '__imp__GetVolumeNameForVolumeMountPointW@12' as GetVolumeNameForVolumeMountPointW:dword
        extrn '__imp__GetVolumePathNameA@12' as GetVolumePathNameA:dword
        extrn '__imp__GetVolumePathNameW@12' as GetVolumePathNameW:dword
        extrn '__imp__GlobalMemoryStatusEx@4' as GlobalMemoryStatusEx:dword
        extrn '__imp__IsValidLanguageGroup@8' as IsValidLanguageGroup:dword
        extrn '__imp__MapUserPhysicalPages@12' as MapUserPhysicalPages:dword
        extrn '__imp__MapUserPhysicalPagesScatter@12' as MapUserPhysicalPagesScatter:dword
        extrn '__imp__MoveFileWithProgressA@20' as MoveFileWithProgressA:dword
        extrn '__imp__MoveFileWithProgressW@20' as MoveFileWithProgressW:dword
        if (NTDDI_VERSION < NTDDI_VISTA)
            extrn '__imp__OpenDataFile@8' as OpenDataFile:dword
        end if
        extrn '__imp__OpenJobObjectA@12' as OpenJobObjectA:dword
        extrn '__imp__OpenJobObjectW@12' as OpenJobObjectW:dword
        extrn '__imp__OpenThread@12' as OpenThread:dword
        extrn '__imp__PrivCopyFileExW@24' as PrivCopyFileExW:dword
        extrn '__imp__ProcessIdToSessionId@8' as ProcessIdToSessionId:dword
        extrn '__imp__QueryInformationJobObject@20' as QueryInformationJobObject:dword
        extrn '__imp__RegisterWaitForSingleObject@24' as RegisterWaitForSingleObject:dword
        extrn '__imp__ReplaceFileA@24' as ReplaceFileA:dword
        extrn '__imp__ReplaceFileW@24' as ReplaceFileW:dword
        extrn '__imp__SetComputerNameExA@8' as SetComputerNameExA:dword
        extrn '__imp__SetComputerNameExW@8' as SetComputerNameExW:dword
        extrn '__imp__SetConsoleNlsMode@8' as SetConsoleNlsMode:dword
        extrn '__imp__SetConsoleOS2OemFormat@4' as SetConsoleOS2OemFormat:dword
        extrn '__imp__SetFilePointerEx@16' as SetFilePointerEx:dword
        extrn '__imp__SetInformationJobObject@16' as SetInformationJobObject:dword
        extrn '__imp__SetTermsrvAppInstallMode@4' as SetTermsrvAppInstallMode:dword
        extrn '__imp__SetTimerQueueTimer@24' as SetTimerQueueTimer:dword
        extrn '__imp__SetVolumeMountPointA@8' as SetVolumeMountPointA:dword
        extrn '__imp__SetVolumeMountPointW@8' as SetVolumeMountPointW:dword
        extrn '__imp__TerminateJobObject@8' as TerminateJobObject:dword
        extrn '__imp__UnregisterWait@4' as UnregisterWait:dword
        extrn '__imp__VerSetConditionMask@12' as VerSetConditionMask:dword
        api CreateHardLink,\
            CreateJobObject,\
            DeleteVolumeMountPoint,\
            DnsHostnameToComputerName,\
            DosPathToSessionPath,\
            EnumLanguageGroupLocales,\
            EnumSystemLanguageGroups,\
            EnumUILanguages,\
            FindActCtxSectionString,\
            FindFirstVolume,\
            FindFirstVolumeMountPoint,\
            FindNextVolume,\
            FindNextVolumeMountPoint,\
            GetComputerNameEx,\
            GetSystemWindowsDirectory,\
            GetVolumeNameForVolumeMountPoint,\
            GetVolumePathName,\
            MoveFileWithProgress,\
            OpenJobObject,\
            ReplaceFile,\
            SetComputerNameEx,\
            SetVolumeMountPoint
    end if

    if (NTDDI_VERSION >= NTDDI_WINXP)
        extrn '__imp__ActivateActCtx@8' as ActivateActCtx:dword
        extrn '__imp__AddLocalAlternateComputerNameA@8' as AddLocalAlternateComputerNameA:dword
        extrn '__imp__AddLocalAlternateComputerNameW@8' as AddLocalAlternateComputerNameW:dword
        extrn '__imp__AddRefActCtx@4' as AddRefActCtx:dword
        extrn '__imp__AddVectoredExceptionHandler@8' as AddVectoredExceptionHandler:dword
        extrn '__imp__AttachConsole@4' as AttachConsole:dword
        extrn '__imp__CancelWaitableTimer@4' as CancelWaitableTimer:dword
        extrn '__imp__ConvertFiberToThread@0' as ConvertFiberToThread:dword
        extrn '__imp__CreateActCtxA@4' as CreateActCtxA:dword
        extrn '__imp__CreateActCtxW@4' as CreateActCtxW:dword
        extrn '__imp__CreateFiberEx@20' as CreateFiberEx:dword
        extrn '__imp__CreateJobSet@12' as CreateJobSet:dword
        extrn '__imp__CreateMemoryResourceNotification@4' as CreateMemoryResourceNotification:dword
        extrn '__imp__CreateProcessInternalA@40' as CreateProcessInternalA:dword
        extrn '__imp__CreateProcessInternalW@40' as CreateProcessInternalW:dword
        extrn '__imp__DeactivateActCtx@8' as DeactivateActCtx:dword
        extrn '__imp__DebugActiveProcessStop@4' as DebugActiveProcessStop:dword
        extrn '__imp__DebugBreakProcess@4' as DebugBreakProcess:dword
        extrn '__imp__DebugSetProcessKillOnExit@4' as DebugSetProcessKillOnExit:dword
        extrn '__imp__DeleteTimerQueueEx@8' as DeleteTimerQueueEx:dword
        extrn '__imp__DeleteTimerQueueTimer@12' as DeleteTimerQueueTimer:dword
        extrn '__imp__EnumerateLocalComputerNamesA@16' as EnumerateLocalComputerNamesA:dword
        extrn '__imp__EnumerateLocalComputerNamesW@16' as EnumerateLocalComputerNamesW:dword
        extrn '__imp__EnumSystemGeoID@12' as EnumSystemGeoID:dword
        extrn '__imp__FindActCtxSectionGuid@20' as FindActCtxSectionGuid:dword
        extrn '__imp__FindActCtxSectionStringA@20' as FindActCtxSectionStringA:dword
        extrn '__imp__FindActCtxSectionStringW@20' as FindActCtxSectionStringW:dword
        extrn '__imp__FlsAlloc@4' as FlsAlloc:dword
        extrn '__imp__FlsFree@4' as FlsFree:dword
        extrn '__imp__FlsGetValue@4' as FlsGetValue:dword
        extrn '__imp__FlsSetValue@8' as FlsSetValue:dword
        extrn '__imp__GetConsoleDisplayMode@4' as GetConsoleDisplayMode:dword
        extrn '__imp__GetConsoleFontInfo@12' as GetConsoleFontInfo:dword
        extrn '__imp__GetConsoleFontSize@8' as GetConsoleFontSize:dword
        extrn '__imp__GetConsoleProcessList@8' as GetConsoleProcessList:dword
        extrn '__imp__GetConsoleSelectionInfo@4' as GetConsoleSelectionInfo:dword
        extrn '__imp__GetCurrentActCtx@4' as GetCurrentActCtx:dword
        extrn '__imp__GetCurrentConsoleFont@12' as GetCurrentConsoleFont:dword
        extrn '__imp__GetDllDirectoryA@8' as GetDllDirectoryA:dword
        extrn '__imp__GetDllDirectoryW@8' as GetDllDirectoryW:dword
        extrn '__imp__GetGeoInfoA@20' as GetGeoInfoA:dword
        extrn '__imp__GetGeoInfoW@20' as GetGeoInfoW:dword
        extrn '__imp__GetProcessId@4' as GetProcessId:dword
        extrn '__imp__GetNativeSystemInfo@4' as GetNativeSystemInfo:dword
        extrn '__imp__GetSystemWow64DirectoryA@8' as GetSystemWow64DirectoryA:dword
        extrn '__imp__GetSystemWow64DirectoryW@8' as GetSystemWow64DirectoryW:dword
        extrn '__imp__GetThreadId@4' as GetThreadId:dword
        extrn '__imp__GetUserGeoID@4' as GetUserGeoID:dword
        extrn '__imp__GetVolumePathNamesForVolumeNameA@16' as GetVolumePathNamesForVolumeNameA:dword
        extrn '__imp__GetVolumePathNamesForVolumeNameW@16' as GetVolumePathNamesForVolumeNameW:dword
        extrn '__imp__GetWriteWatch@24' as GetWriteWatch:dword
        extrn '__imp__HeapQueryInformation@20' as HeapQueryInformation:dword
        extrn '__imp__HeapSetInformation@16' as HeapSetInformation:dword
        extrn '__imp__InitializeCriticalSectionAndSpinCount@8' as InitializeCriticalSectionAndSpinCount:dword
        extrn '__imp__InitializeSListHead@4' as InitializeSListHead:dword
        extrn '__imp__InterlockedFlushSList@4' as InterlockedFlushSList:dword
        extrn '__imp__InterlockedPopEntrySList@4' as InterlockedPopEntrySList:dword
        extrn '__imp__InterlockedPushEntrySList@8' as InterlockedPushEntrySList:dword
        extrn '__imp__IsProcessInJob@12' as IsProcessInJob:dword
        extrn '__imp__Module32First@8' as Module32First:dword
        extrn '__imp__Module32FirstW@8' as Module32FirstW:dword
        extrn '__imp__Module32Next@8' as Module32Next:dword
        extrn '__imp__Module32NextW@8' as Module32NextW:dword
        extrn '__imp__Process32First@8' as Process32First:dword
        extrn '__imp__Process32FirstW@8' as Process32FirstW:dword
        extrn '__imp__Process32Next@8' as Process32Next:dword
        extrn '__imp__Process32NextW@8' as Process32NextW:dword
        extrn '__imp__QueryActCtxW@28' as QueryActCtxW:dword
        extrn '__imp__QueryDepthSList@4' as QueryDepthSList:dword
        extrn '__imp__QueryMemoryResourceNotification@8' as QueryMemoryResourceNotification:dword
        extrn '__imp__QueueUserWorkItem@12' as QueueUserWorkItem:dword
        extrn '__imp__ReleaseActCtx@4' as ReleaseActCtx:dword
        extrn '__imp__RemoveVectoredExceptionHandler@4' as RemoveVectoredExceptionHandler:dword
        if (NTDDI_VERSION >= NTDDI_WIN8)
            extrn '__imp__ResolveDelayLoadedAPI@24' as ResolveDelayLoadedAPI:dword
            extrn '__imp__ResolveDelayLoadsFromDll@12' as ResolveDelayLoadsFromDll:dword
        end if
        extrn '__imp__RtlCaptureContext@4' as RtlCaptureContext:dword
        extrn '__imp__RtlCaptureStackBackTrace@16' as RtlCaptureStackBackTrace:dword
        extrn '__imp__RtlRaiseException@4' as RtlRaiseException:dword
        extrn '__imp__SetConsoleDisplayMode@12' as SetConsoleDisplayMode:dword
        extrn '__imp__SetConsoleFont@8' as SetConsoleFont:dword
        extrn '__imp__SetFileShortNameA@8' as SetFileShortNameA:dword
        extrn '__imp__SetFileShortNameW@8' as SetFileShortNameW:dword
        extrn '__imp__SetFileValidData@8' as SetFileValidData:dword
        extrn '__imp__SetLocalPrimaryComputerNameA@8' as SetLocalPrimaryComputerNameA:dword
        extrn '__imp__SetLocalPrimaryComputerNameW@8' as SetLocalPrimaryComputerNameW:dword
        extrn '__imp__SetThreadUILanguage@4' as SetThreadUILanguage:dword
        extrn '__imp__SetUserGeoID@4' as SetUserGeoID:dword
        extrn '__imp__TryEnterCriticalSection@4' as TryEnterCriticalSection:dword
        extrn '__imp__TzSpecificLocalTimeToSystemTime@12' as TzSpecificLocalTimeToSystemTime:dword
        extrn '__imp__uaw_lstrcmpiW@8' as uaw_lstrcmpiW:dword
        extrn '__imp__uaw_lstrcmpW@8' as uaw_lstrcmpW:dword
        extrn '__imp__uaw_lstrlenW@4' as uaw_lstrlenW:dword
        extrn '__imp__uaw_wcschr@8' as uaw_wcschr:dword
        extrn '__imp__uaw_wcscpy@8' as uaw_wcscpy:dword
        extrn '__imp__uaw_wcsicmp@8' as uaw_wcsicmp:dword
        extrn '__imp__uaw_wcslen@4' as uaw_wcslen:dword
        extrn '__imp__uaw_wcsrchr@8' as uaw_wcsrchr:dword
        extrn '__imp__UnregisterWaitEx@8' as UnregisterWaitEx:dword
        extrn '__imp__ZombifyActCtx@4' as ZombifyActCtx:dword

        CaptureStackBackTrace equ RtlCaptureStackBackTrace

        api AddLocalAlternateComputerName,\
            CreateActCtx,\
            CreateProcessInternal,\
            EnumerateLocalComputerNames,\
            GetDllDirectory,\
            GetGeoInfo,\
            GetSystemWow64Directory,\
            GetVolumePathNamesForVolumeName,\
            SetFileShortName,\
            SetLocalPrimaryComputerName
    end if

    if (NTDDI_VERSION >= NTDDI_WINXPSP1)
        extrn '__imp__CheckNameLegalDOS8Dot3A@20' as CheckNameLegalDOS8Dot3A:dword
        extrn '__imp__CheckNameLegalDOS8Dot3W@20' as CheckNameLegalDOS8Dot3W:dword
        extrn '__imp__CheckRemoteDebuggerPresent@8' as CheckRemoteDebuggerPresent:dword
        extrn '__imp__ConvertThreadToFiberEx@8' as ConvertThreadToFiberEx:dword
        extrn '__imp__GetFirmwareEnvironmentVariableA@16' as GetFirmwareEnvironmentVariableA:dword
        extrn '__imp__GetFirmwareEnvironmentVariableW@16' as GetFirmwareEnvironmentVariableW:dword
        extrn '__imp__GetProcessHandleCount@8' as GetProcessHandleCount:dword
        extrn '__imp__GetSystemRegistryQuota@8' as GetSystemRegistryQuota:dword
        extrn '__imp__GetSystemTimes@12' as GetSystemTimes:dword
        extrn '__imp__GetThreadIOPendingFlag@8' as GetThreadIOPendingFlag:dword
        extrn '__imp__SetFirmwareEnvironmentVariableA@16' as SetFirmwareEnvironmentVariableA:dword
        extrn '__imp__SetFirmwareEnvironmentVariableW@16' as SetFirmwareEnvironmentVariableW:dword
        api CheckNameLegalDOS8Dot3,\
            GetFirmwareEnvironmentVariable,\
            SetFirmwareEnvironmentVariable
    end if

    if (NTDDI_VERSION >= NTDDI_WINXPSP2)
        extrn '__imp__GetNumaAvailableMemoryNode@8' as GetNumaAvailableMemoryNode:dword
        extrn '__imp__GetNumaNodeProcessorMask@8' as GetNumaNodeProcessorMask:dword
        extrn '__imp__GetNumaProcessorNode@8' as GetNumaProcessorNode:dword
    end if

    if (NTDDI_VERSION >= NTDDI_WINXPSP2 | NTDDI_VERSION >= NTDDI_WS03SP1)
        extrn '__imp__DecodePointer@4' as DecodePointer:dword
        extrn '__imp__DecodeSystemPointer@4' as DecodeSystemPointer:dword
        extrn '__imp__EncodePointer@4' as EncodePointer:dword
        extrn '__imp__EncodeSystemPointer@4' as EncodeSystemPointer:dword
        extrn '__imp__IsWow64Process@8' as IsWow64Process:dword
    end if

    if (NTDDI_VERSION >= NTDDI_WINXPSP3)
        extrn '__imp__GetSystemDEPPolicy@0' as GetSystemDEPPolicy:dword
        extrn '__imp__GetProcessDEPPolicy@12' as GetProcessDEPPolicy:dword
        extrn '__imp__SetProcessDEPPolicy@4' as SetProcessDEPPolicy:dword
    end if

    if (NTDDI_VERSION >= NTDDI_WS03)
        extrn '__imp__FindFirstStreamW@16' as FindFirstStreamW:dword
        extrn '__imp__FindNextStreamW@8' as FindNextStreamW:dword
        extrn '__imp__GetLargePageMinimum@0' as GetLargePageMinimum:dword
        extrn '__imp__GetProcessIdOfThread@4' as GetProcessIdOfThread:dword
        extrn '__imp__GetProcessWorkingSetSizeEx@16' as GetProcessWorkingSetSizeEx:dword
        extrn '__imp__ReOpenFile@16' as ReOpenFile:dword
        extrn '__imp__SetDllDirectoryA@4' as SetDllDirectoryA:dword
        extrn '__imp__SetDllDirectoryW@4' as SetDllDirectoryW:dword
        extrn '__imp__SetEnvironmentStringsA@4' as SetEnvironmentStringsA:dword
        extrn '__imp__SetEnvironmentStringsW@4' as SetEnvironmentStringsW:dword
        extrn '__imp__SetProcessWorkingSetSizeEx@16' as SetProcessWorkingSetSizeEx:dword
        extrn '__imp__Wow64EnableWow64FsRedirection@4' as Wow64EnableWow64FsRedirection:dword
        extrn '__imp__WTSGetActiveConsoleSessionId@0' as WTSGetActiveConsoleSessionId:dword
        api SetDllDirectory,\
            SetEnvironmentStrings
    end if

    if (NTDDI_VERSION <= NTDDI_VISTA)
        extrn '__imp__InterlockedCompareExchange@12' as InterlockedCompareExchange:dword
        ;extrn '__imp__InterlockedCompareExchange64@12' as InterlockedCompareExchange64:dword ;Not present in MASM32 kernel32.lib
        extrn '__imp__InterlockedDecrement@4' as InterlockedDecrement:dword
        extrn '__imp__InterlockedExchange@8' as InterlockedExchange:dword
        extrn '__imp__InterlockedIncrement@4' as InterlockedIncrement:dword
    end if

    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__AcquireSRWLockExclusive@4' as AcquireSRWLockExclusive:dword
        extrn '__imp__AcquireSRWLockShared@4' as AcquireSRWLockShared:dword
        extrn '__imp__AddDllDirectory@4' as AddDllDirectory:dword
        extrn '__imp__AddSIDToBoundaryDescriptor@8' as AddSIDToBoundaryDescriptor:dword
        extrn '__imp__AddVectoredContinueHandler@8' as AddVectoredContinueHandler:dword
        extrn '__imp__AdjustCalendarDate@8' as AdjustCalendarDate:dword
        extrn '__imp__AllocateUserPhysicalPagesNuma@16' as AllocateUserPhysicalPagesNuma:dword
        extrn '__imp__ApplicationRecoveryFinished@4' as ApplicationRecoveryFinished:dword
        extrn '__imp__ApplicationRecoveryInProgress@4' as ApplicationRecoveryInProgress:dword
        extrn '__imp__CallbackMayRunLong@4' as CallbackMayRunLong:dword
        extrn '__imp__CancelIoEx@8' as CancelIoEx:dword
        extrn '__imp__CancelSynchronousIo@4' as CancelSynchronousIo:dword
        extrn '__imp__CancelThreadpoolIo@4' as CancelThreadpoolIo:dword
        extrn '__imp__CheckElevationEnabled@4' as CheckElevationEnabled:dword
        extrn '__imp__ClosePrivateNamespace@8' as ClosePrivateNamespace:dword
        extrn '__imp__CloseThreadpool@4' as CloseThreadpool:dword
        extrn '__imp__CloseThreadpoolCleanupGroup@4' as CloseThreadpoolCleanupGroup:dword
        extrn '__imp__CloseThreadpoolCleanupGroupMembers@12' as CloseThreadpoolCleanupGroupMembers:dword
        extrn '__imp__CloseThreadpoolIo@4' as CloseThreadpoolIo:dword
        extrn '__imp__CloseThreadpoolTimer@4' as CloseThreadpoolTimer:dword
        extrn '__imp__CloseThreadpoolWait@4' as CloseThreadpoolWait:dword
        extrn '__imp__CloseThreadpoolWork@4' as CloseThreadpoolWork:dword
        extrn '__imp__CompareStringEx@36' as CompareStringEx:dword
        extrn '__imp__CompareStringOrdinal@20' as CompareStringOrdinal:dword
        extrn '__imp__ConvertCalDateTimeToSystemTime@8' as ConvertCalDateTimeToSystemTime:dword
        extrn '__imp__ConvertSystemTimeToCalDateTime@12' as ConvertSystemTimeToCalDateTime:dword
        extrn '__imp__CopyFileTransactedA@28' as CopyFileTransactedA:dword
        extrn '__imp__CopyFileTransactedW@28' as CopyFileTransactedW:dword
        extrn '__imp__CreateBoundaryDescriptorA@8' as CreateBoundaryDescriptorA:dword
        extrn '__imp__CreateBoundaryDescriptorW@8' as CreateBoundaryDescriptorW:dword
        extrn '__imp__CreateDirectoryTransactedA@16' as CreateDirectoryTransactedA:dword
        extrn '__imp__CreateDirectoryTransactedW@16' as CreateDirectoryTransactedW:dword
        extrn '__imp__CreateEventExA@16' as CreateEventExA:dword
        extrn '__imp__CreateEventExW@16' as CreateEventExW:dword
        extrn '__imp__CreateFileMappingNumaA@28' as CreateFileMappingNumaA:dword
        extrn '__imp__CreateFileMappingNumaW@28' as CreateFileMappingNumaW:dword
        extrn '__imp__CreateFileTransactedA@40' as CreateFileTransactedA:dword
        extrn '__imp__CreateFileTransactedW@40' as CreateFileTransactedW:dword
        extrn '__imp__CreateHardLinkTransactedA@16' as CreateHardLinkTransactedA:dword
        extrn '__imp__CreateHardLinkTransactedW@16' as CreateHardLinkTransactedW:dword
        extrn '__imp__CreateMutexExA@16' as CreateMutexExA:dword
        extrn '__imp__CreateMutexExW@16' as CreateMutexExW:dword
        extrn '__imp__CreatePrivateNamespaceA@12' as CreatePrivateNamespaceA:dword
        extrn '__imp__CreatePrivateNamespaceW@12' as CreatePrivateNamespaceW:dword
        extrn '__imp__CreateSemaphoreExA@24' as CreateSemaphoreExA:dword
        extrn '__imp__CreateSemaphoreExW@24' as CreateSemaphoreExW:dword
        extrn '__imp__CreateSymbolicLinkA@12' as CreateSymbolicLinkA:dword
        extrn '__imp__CreateSymbolicLinkTransactedA@16' as CreateSymbolicLinkTransactedA:dword
        extrn '__imp__CreateSymbolicLinkTransactedW@16' as CreateSymbolicLinkTransactedW:dword
        extrn '__imp__CreateSymbolicLinkW@12' as CreateSymbolicLinkW:dword
        extrn '__imp__CreateThreadpool@4' as CreateThreadpool:dword
        extrn '__imp__CreateThreadpoolCleanupGroup@0' as CreateThreadpoolCleanupGroup:dword
        extrn '__imp__CreateThreadpoolIo@16' as CreateThreadpoolIo:dword
        extrn '__imp__CreateThreadpoolTimer@12' as CreateThreadpoolTimer:dword
        extrn '__imp__CreateThreadpoolWait@12' as CreateThreadpoolWait:dword
        extrn '__imp__CreateThreadpoolWork@12' as CreateThreadpoolWork:dword
        extrn '__imp__CreateWaitableTimerExA@16' as CreateWaitableTimerExA:dword
        extrn '__imp__CreateWaitableTimerExW@16' as CreateWaitableTimerExW:dword
        extrn '__imp__DeleteBoundaryDescriptor@4' as DeleteBoundaryDescriptor:dword
        extrn '__imp__DeleteFileTransactedA@8' as DeleteFileTransactedA:dword
        extrn '__imp__DeleteFileTransactedW@8' as DeleteFileTransactedW:dword
        extrn '__imp__DeleteProcThreadAttributeList@4' as DeleteProcThreadAttributeList:dword
        extrn '__imp__DisassociateCurrentThreadFromCallback@4' as DisassociateCurrentThreadFromCallback:dword
        extrn '__imp__EnumCalendarInfoExEx@24' as EnumCalendarInfoExEx:dword
        extrn '__imp__EnumDateFormatsExEx@16' as EnumDateFormatsExEx:dword
        extrn '__imp__EnumResourceLanguagesExA@28' as EnumResourceLanguagesExA:dword
        extrn '__imp__EnumResourceLanguagesExW@28' as EnumResourceLanguagesExW:dword
        extrn '__imp__EnumResourceNamesExA@24' as EnumResourceNamesExA:dword
        extrn '__imp__EnumResourceNamesExW@24' as EnumResourceNamesExW:dword
        extrn '__imp__EnumResourceTypesExA@20' as EnumResourceTypesExA:dword
        extrn '__imp__EnumResourceTypesExW@20' as EnumResourceTypesExW:dword
        extrn '__imp__EnumSystemLocalesEx@16' as EnumSystemLocalesEx:dword
        extrn '__imp__EnumTimeFormatsEx@16' as EnumTimeFormatsEx:dword
        extrn '__imp__FindFirstFileNameTransactedW@20' as FindFirstFileNameTransactedW:dword
        extrn '__imp__FindFirstFileNameW@16' as FindFirstFileNameW:dword
        extrn '__imp__FindFirstFileTransactedA@28' as FindFirstFileTransactedA:dword
        extrn '__imp__FindFirstFileTransactedW@28' as FindFirstFileTransactedW:dword
        extrn '__imp__FindFirstStreamTransactedW@20' as FindFirstStreamTransactedW:dword
        extrn '__imp__FindNextFileNameW@12' as FindNextFileNameW:dword
        extrn '__imp__FindNLSString@28' as FindNLSString:dword
        extrn '__imp__FindNLSStringEx@40' as FindNLSStringEx:dword
        extrn '__imp__FlushProcessWriteBuffers@0' as FlushProcessWriteBuffers:dword
        extrn '__imp__FreeLibraryWhenCallbackReturns@8' as FreeLibraryWhenCallbackReturns:dword
        extrn '__imp__GetApplicationRecoveryCallback@20' as GetApplicationRecoveryCallback:dword
        extrn '__imp__GetApplicationRestartSettings@16' as GetApplicationRestartSettings:dword
        extrn '__imp__GetCalendarDateFormatEx@24' as GetCalendarDateFormatEx:dword
        extrn '__imp__GetCalendarInfoEx@28' as GetCalendarInfoEx:dword
        extrn '__imp__GetCalendarSupportedDateRange@12' as GetCalendarSupportedDateRange:dword
        extrn '__imp__GetComPlusPackageInstallStatus@0' as GetComPlusPackageInstallStatus:dword
        extrn '__imp__GetCompressedFileSizeTransactedA@12' as GetCompressedFileSizeTransactedA:dword
        extrn '__imp__GetCompressedFileSizeTransactedW@12' as GetCompressedFileSizeTransactedW:dword
        extrn '__imp__GetConsoleHistoryInfo@4' as GetConsoleHistoryInfo:dword
        extrn '__imp__GetConsoleOriginalTitleA@8' as GetConsoleOriginalTitleA:dword
        extrn '__imp__GetConsoleOriginalTitleW@8' as GetConsoleOriginalTitleW:dword
        extrn '__imp__GetConsoleScreenBufferInfoEx@8' as GetConsoleScreenBufferInfoEx:dword
        extrn '__imp__GetCurrencyFormatEx@24' as GetCurrencyFormatEx:dword
        extrn '__imp__GetCurrentConsoleFontEx@12' as GetCurrentConsoleFontEx:dword
        extrn '__imp__GetCurrentProcessorNumber@0' as GetCurrentProcessorNumber:dword
        extrn '__imp__GetDateFormatEx@28' as GetDateFormatEx:dword
        extrn '__imp__GetDurationFormat@28' as GetDurationFormat:dword
        extrn '__imp__GetDurationFormatEx@28' as GetDurationFormatEx:dword
        extrn '__imp__GetDynamicTimeZoneInformation@4' as GetDynamicTimeZoneInformation:dword
        extrn '__imp__GetFileAttributesTransactedA@16' as GetFileAttributesTransactedA:dword
        extrn '__imp__GetFileAttributesTransactedW@16' as GetFileAttributesTransactedW:dword
        extrn '__imp__GetFileBandwidthReservation@24' as GetFileBandwidthReservation:dword
        extrn '__imp__GetFileInformationByHandleEx@16' as GetFileInformationByHandleEx:dword
        extrn '__imp__GetFileMUIInfo@16' as GetFileMUIInfo:dword
        extrn '__imp__GetFileMUIPath@28' as GetFileMUIPath:dword
        extrn '__imp__GetFinalPathNameByHandleA@16' as GetFinalPathNameByHandleA:dword
        extrn '__imp__GetFinalPathNameByHandleW@16' as GetFinalPathNameByHandleW:dword
        extrn '__imp__GetFullPathNameTransactedA@20' as GetFullPathNameTransactedA:dword
        extrn '__imp__GetFullPathNameTransactedW@20' as GetFullPathNameTransactedW:dword
        extrn '__imp__GetLocaleInfoEx@16' as GetLocaleInfoEx:dword
        extrn '__imp__GetLongPathNameTransactedA@16' as GetLongPathNameTransactedA:dword
        extrn '__imp__GetLongPathNameTransactedW@16' as GetLongPathNameTransactedW:dword
        extrn '__imp__GetNamedPipeAttribute@20' as GetNamedPipeAttribute:dword
        extrn '__imp__GetNamedPipeClientComputerNameA@12' as GetNamedPipeClientComputerNameA:dword
        extrn '__imp__GetNamedPipeClientComputerNameW@12' as GetNamedPipeClientComputerNameW:dword
        extrn '__imp__GetNamedPipeClientProcessId@8' as GetNamedPipeClientProcessId:dword
        extrn '__imp__GetNamedPipeClientSessionId@8' as GetNamedPipeClientSessionId:dword
        extrn '__imp__GetNamedPipeServerProcessId@8' as GetNamedPipeServerProcessId:dword
        extrn '__imp__GetNamedPipeServerSessionId@8' as GetNamedPipeServerSessionId:dword
        extrn '__imp__GetNLSVersion@12' as GetNLSVersion:dword
        extrn '__imp__GetNLSVersionEx@12' as GetNLSVersionEx:dword
        extrn '__imp__GetNumaProximityNode@8' as GetNumaProximityNode:dword
        extrn '__imp__GetNumberFormatEx@24' as GetNumberFormatEx:dword
        extrn '__imp__GetProductInfo@20' as GetProductInfo:dword
        extrn '__imp__GetQueuedCompletionStatusEx@24' as GetQueuedCompletionStatusEx:dword
        extrn '__imp__GetStringScripts@20' as GetStringScripts:dword
        extrn '__imp__GetSystemDefaultLocaleName@8' as GetSystemDefaultLocaleName:dword
        extrn '__imp__GetSystemPreferredUILanguages@16' as GetSystemPreferredUILanguages:dword
        extrn '__imp__GetThreadPreferredUILanguages@16' as GetThreadPreferredUILanguages:dword
        extrn '__imp__GetThreadUILanguage@0' as GetThreadUILanguage:dword
        extrn '__imp__GetTickCount64@0' as GetTickCount64:dword
        extrn '__imp__GetTimeFormatEx@24' as GetTimeFormatEx:dword
        extrn '__imp__GetUILanguageInfo@20' as GetUILanguageInfo:dword
        extrn '__imp__GetUserDefaultLocaleName@8' as GetUserDefaultLocaleName:dword
        extrn '__imp__GetUserPreferredUILanguages@16' as GetUserPreferredUILanguages:dword
        extrn '__imp__GetVolumeInformationByHandleW@32' as GetVolumeInformationByHandleW:dword
        extrn '__imp__IdnToAscii@20' as IdnToAscii:dword
        extrn '__imp__IdnToNameprepUnicode@20' as IdnToNameprepUnicode:dword
        extrn '__imp__IdnToUnicode@20' as IdnToUnicode:dword
        extrn '__imp__InitOnceBeginInitialize@16' as InitOnceBeginInitialize:dword
        extrn '__imp__InitOnceComplete@12' as InitOnceComplete:dword
        extrn '__imp__InitOnceExecuteOnce@16' as InitOnceExecuteOnce:dword
        extrn '__imp__InitOnceInitialize@4' as InitOnceInitialize:dword
        extrn '__imp__InitializeConditionVariable@4' as InitializeConditionVariable:dword
        extrn '__imp__InitializeCriticalSectionEx@12' as InitializeCriticalSectionEx:dword
        extrn '__imp__InitializeProcThreadAttributeList@16' as InitializeProcThreadAttributeList:dword
        extrn '__imp__InitializeSRWLock@4' as InitializeSRWLock:dword
        extrn '__imp__InterlockedPushListSList@16' as InterlockedPushListSList:dword
        extrn '__imp__IsCalendarLeapDay@20' as IsCalendarLeapDay:dword
        extrn '__imp__IsCalendarLeapMonth@16' as IsCalendarLeapMonth:dword
        extrn '__imp__IsCalendarLeapYear@12' as IsCalendarLeapYear:dword
        extrn '__imp__IsNLSDefinedString@20' as IsNLSDefinedString:dword
        extrn '__imp__IsNormalizedString@12' as IsNormalizedString:dword
        extrn '__imp__IsThreadAFiber@0' as IsThreadAFiber:dword
        extrn '__imp__IsThreadpoolTimerSet@4' as IsThreadpoolTimerSet:dword
        if (NTDDI_VERSION NTDDI_WIN81)
            extrn '__imp__IsTimeZoneRedirectionEnabled@0' as IsTimeZoneRedirectionEnabled:dword
        end if
        extrn '__imp__IsValidCalDateTime@8' as IsValidCalDateTime:dword
        extrn '__imp__IsValidLocaleName@4' as IsValidLocaleName:dword
        extrn '__imp__LCIDToLocaleName@16' as LCIDToLocaleName:dword
        extrn '__imp__LCMapStringEx@36' as LCMapStringEx:dword
        extrn '__imp__LeaveCriticalSectionWhenCallbackReturns@8' as LeaveCriticalSectionWhenCallbackReturns:dword
        extrn '__imp__LoadStringBaseExW@20' as LoadStringBaseExW:dword
        extrn '__imp__LoadStringBaseW@16' as LoadStringBaseW:dword
        extrn '__imp__LocaleNameToLCID@8' as LocaleNameToLCID:dword
        extrn '__imp__MapViewOfFileExNuma@28' as MapViewOfFileExNuma:dword
        extrn '__imp__MoveFileTransactedA@24' as MoveFileTransactedA:dword
        extrn '__imp__MoveFileTransactedW@24' as MoveFileTransactedW:dword
        extrn '__imp__NeedCurrentDirectoryForExePathA@4' as NeedCurrentDirectoryForExePathA:dword
        extrn '__imp__NeedCurrentDirectoryForExePathW@4' as NeedCurrentDirectoryForExePathW:dword
        extrn '__imp__NormalizeString@20' as NormalizeString:dword
        extrn '__imp__OpenFileById@24' as OpenFileById:dword
        extrn '__imp__OpenPrivateNamespaceA@8' as OpenPrivateNamespaceA:dword
        extrn '__imp__OpenPrivateNamespaceW@8' as OpenPrivateNamespaceW:dword
        extrn '__imp__QueryActCtxSettingsW@28' as QueryActCtxSettingsW:dword
        extrn '__imp__QueryFullProcessImageNameA@16' as QueryFullProcessImageNameA:dword
        extrn '__imp__QueryFullProcessImageNameW@16' as QueryFullProcessImageNameW:dword
        extrn '__imp__QueryIdleProcessorCycleTime@8' as QueryIdleProcessorCycleTime:dword
        extrn '__imp__QueryProcessCycleTime@8' as QueryProcessCycleTime:dword
        extrn '__imp__QueryThreadCycleTime@8' as QueryThreadCycleTime:dword
        extrn '__imp__RegisterApplicationRecoveryCallback@16' as RegisterApplicationRecoveryCallback:dword
        extrn '__imp__RegisterApplicationRestart@8' as RegisterApplicationRestart:dword
        extrn '__imp__ReleaseMutexWhenCallbackReturns@8' as ReleaseMutexWhenCallbackReturns:dword
        extrn '__imp__ReleaseSRWLockExclusive@4' as ReleaseSRWLockExclusive:dword
        extrn '__imp__ReleaseSRWLockShared@4' as ReleaseSRWLockShared:dword
        extrn '__imp__ReleaseSemaphoreWhenCallbackReturns@12' as ReleaseSemaphoreWhenCallbackReturns:dword
        extrn '__imp__RemoveDirectoryTransactedA@8' as RemoveDirectoryTransactedA:dword
        extrn '__imp__RemoveDirectoryTransactedW@8' as RemoveDirectoryTransactedW:dword
        extrn '__imp__RemoveDllDirectory@4' as RemoveDllDirectory:dword
        extrn '__imp__ReplacePartitionUnit@12' as ReplacePartitionUnit:dword
        extrn '__imp__SetConsoleHistoryInfo@4' as SetConsoleHistoryInfo:dword
        extrn '__imp__SetConsoleScreenBufferInfoEx@8' as SetConsoleScreenBufferInfoEx:dword
        extrn '__imp__SetCurrentConsoleFontEx@12' as SetCurrentConsoleFontEx:dword
        extrn '__imp__SetDefaultDllDirectories@4' as SetDefaultDllDirectories:dword
        extrn '__imp__SetDynamicTimeZoneInformation@4' as SetDynamicTimeZoneInformation:dword
        extrn '__imp__SetEventWhenCallbackReturns@8' as SetEventWhenCallbackReturns:dword
        extrn '__imp__SetFileAttributesTransactedA@12' as SetFileAttributesTransactedA:dword
        extrn '__imp__SetFileAttributesTransactedW@12' as SetFileAttributesTransactedW:dword
        extrn '__imp__SetFileBandwidthReservation@24' as SetFileBandwidthReservation:dword
        extrn '__imp__SetFileCompletionNotificationModes@8' as SetFileCompletionNotificationModes:dword
        extrn '__imp__SetFileInformationByHandle@16' as SetFileInformationByHandle:dword
        extrn '__imp__SetFileIoOverlappedRange@12' as SetFileIoOverlappedRange:dword
        extrn '__imp__SetNamedPipeAttribute@20' as SetNamedPipeAttribute:dword
        extrn '__imp__SetThreadpoolThreadMaximum@8' as SetThreadpoolThreadMaximum:dword
        extrn '__imp__SetThreadpoolThreadMinimum@8' as SetThreadpoolThreadMinimum:dword
        extrn '__imp__SetThreadpoolTimer@16' as SetThreadpoolTimer:dword
        extrn '__imp__SetThreadpoolWait@12' as SetThreadpoolWait:dword
        if (NTDDI_VERSION >= NTDDI_WIN8)
            extrn '__imp__SetThreadpoolWaitEx@12' as SetThreadpoolWaitEx:dword
        end if
        extrn '__imp__SetThreadPreferredUILanguages@12' as SetThreadPreferredUILanguages:dword
        extrn '__imp__SleepConditionVariableCS@12' as SleepConditionVariableCS:dword
        extrn '__imp__SleepConditionVariableSRW@16' as SleepConditionVariableSRW:dword
        extrn '__imp__StartThreadpoolIo@4' as StartThreadpoolIo:dword
        extrn '__imp__SubmitThreadpoolWork@4' as SubmitThreadpoolWork:dword
        extrn '__imp__TrySubmitThreadpoolCallback@12' as TrySubmitThreadpoolCallback:dword
        extrn '__imp__UnregisterApplicationRecoveryCallback@0' as UnregisterApplicationRecoveryCallback:dword
        extrn '__imp__UnregisterApplicationRestart@0' as UnregisterApplicationRestart:dword
        extrn '__imp__UpdateCalendarDayOfWeek@4' as UpdateCalendarDayOfWeek:dword
        extrn '__imp__UpdateProcThreadAttribute@28' as UpdateProcThreadAttribute:dword
        extrn '__imp__VerifyScripts@20' as VerifyScripts:dword
        extrn '__imp__VirtualAllocExNuma@24' as VirtualAllocExNuma:dword
        extrn '__imp__WaitForThreadpoolIoCallbacks@8' as WaitForThreadpoolIoCallbacks:dword
        extrn '__imp__WaitForThreadpoolTimerCallbacks@8' as WaitForThreadpoolTimerCallbacks:dword
        extrn '__imp__WaitForThreadpoolWaitCallbacks@8' as WaitForThreadpoolWaitCallbacks:dword
        extrn '__imp__WaitForThreadpoolWorkCallbacks@8' as WaitForThreadpoolWorkCallbacks:dword
        extrn '__imp__WakeAllConditionVariable@4' as WakeAllConditionVariable:dword
        extrn '__imp__WakeConditionVariable@4' as WakeConditionVariable:dword
        extrn '__imp__WerGetFlags@8' as WerGetFlags:dword
        extrn '__imp__WerRegisterFile@12' as WerRegisterFile:dword
        extrn '__imp__WerRegisterMemoryBlock@8' as WerRegisterMemoryBlock:dword
        extrn '__imp__WerSetFlags@4' as WerSetFlags:dword
        extrn '__imp__WerUnregisterFile@4' as WerUnregisterFile:dword
        extrn '__imp__WerUnregisterMemoryBlock@4' as WerUnregisterMemoryBlock:dword
        extrn '__imp__Wow64GetThreadContext@8' as Wow64GetThreadContext:dword
        extrn '__imp__Wow64SetThreadContext@8' as Wow64SetThreadContext:dword
        extrn '__imp__Wow64SuspendThread@4' as Wow64SuspendThread:dword
        api CopyFileTransacted,\
            CreateBoundaryDescriptor,\
            CreateDirectoryTransacted,\
            CreateEventEx,\
            CreateFileMappingNuma,\
            CreateFileTransacted,\
            CreateHardLinkTransacted,\
            CreateMutexEx,\
            CreatePrivateNamespace,\
            CreateSemaphoreEx,\
            CreateSymbolicLink,\
            CreateSymbolicLinkTransacted,\
            CreateWaitableTimerEx,\
            DeleteFileTransacted,\
            EnumResourceLanguagesEx,\
            EnumResourceNamesEx,\
            EnumResourceTypesEx,\
            FindFirstFileTransacted,\
            GetCompressedFileSizeTransacted,\
            GetConsoleOriginalTitle,\
            GetFileAttributesTransacted,\
            GetFinalPathNameByHandle,\
            GetFullPathNameTransacted,\
            GetLongPathNameTransacted,\
            GetNamedPipeClientComputerName,\
            MoveFileTransacted,\
            NeedCurrentDirectoryForExePath,\
            OpenPrivateNamespace,\
            QueryFullProcessImageName,\
            RemoveDirectoryTransacted,\
            SetFileAttributesTransacted
    end if

    if (NTDDI_VERSION >= NTDDI_VISTASP1)
        extrn '__imp__AddSecureMemoryCacheCallback@4' as AddSecureMemoryCacheCallback:dword
        extrn '__imp__GetPhysicallyInstalledSystemMemory@4' as GetPhysicallyInstalledSystemMemory:dword
        extrn '__imp__GetTimeZoneInformationForYear@12' as GetTimeZoneInformationForYear:dword
        extrn '__imp__QueryProcessAffinityUpdateMode@8' as QueryProcessAffinityUpdateMode:dword
        extrn '__imp__RemoveSecureMemoryCacheCallback@4' as RemoveSecureMemoryCacheCallback:dword
        extrn '__imp__SetProcessAffinityUpdateMode@8' as SetProcessAffinityUpdateMode:dword
    end if

    if (NTDDI_VERSION >= NTDDI_WIN7)
        extrn '__imp__AddIntegrityLabelToBoundaryDescriptor@8' as AddIntegrityLabelToBoundaryDescriptor:dword
        extrn '__imp__BaseFormatTimeOut@8' as BaseFormatTimeOut:dword
        extrn '__imp__BaseGetNamedObjectDirectory@4' as BaseGetNamedObjectDirectory:dword
        extrn '__imp__Basep8BitStringToDynamicUnicodeString@8' as Basep8BitStringToDynamicUnicodeString:dword
        extrn '__imp__CreateRemoteThreadEx@32' as CreateRemoteThreadEx:dword
        extrn '__imp__DisableThreadProfiling@4' as DisableThreadProfiling:dword
        extrn '__imp__EnableThreadProfiling@16' as EnableThreadProfiling:dword
        extrn '__imp__FindStringOrdinal@24' as FindStringOrdinal:dword
        extrn '__imp__GetActiveProcessorCount@4' as GetActiveProcessorCount:dword
        extrn '__imp__GetActiveProcessorGroupCount@0' as GetActiveProcessorGroupCount:dword
        extrn '__imp__GetCurrentProcessorNumberEx@4' as GetCurrentProcessorNumberEx:dword
        extrn '__imp__GetLogicalProcessorInformationEx@12' as GetLogicalProcessorInformationEx:dword
        extrn '__imp__GetMaximumProcessorCount@4' as GetMaximumProcessorCount:dword
        extrn '__imp__GetMaximumProcessorGroupCount@0' as GetMaximumProcessorGroupCount:dword
        extrn '__imp__GetNumaAvailableMemoryNodeEx@8' as GetNumaAvailableMemoryNodeEx:dword
        extrn '__imp__GetNumaNodeNumberFromHandle@8' as GetNumaNodeNumberFromHandle:dword
        extrn '__imp__GetNumaNodeProcessorMaskEx@8' as GetNumaNodeProcessorMaskEx:dword
        extrn '__imp__GetNumaProcessorNodeEx@8' as GetNumaProcessorNodeEx:dword
        extrn '__imp__GetNumaProximityNodeEx@8' as GetNumaProximityNodeEx:dword
        extrn '__imp__GetProcessGroupAffinity@12' as GetProcessGroupAffinity:dword
        extrn '__imp__GetProcessorSystemCycleTime@12' as GetProcessorSystemCycleTime:dword
        extrn '__imp__GetProcessPreferredUILanguages@16' as GetProcessPreferredUILanguages:dword
        extrn '__imp__GetProcessUserModeExceptionPolicy@4' as GetProcessUserModeExceptionPolicy:dword
        extrn '__imp__GetThreadErrorMode@0' as GetThreadErrorMode:dword
        extrn '__imp__GetThreadGroupAffinity@8' as GetThreadGroupAffinity:dword
        extrn '__imp__GetThreadIdealProcessorEx@8' as GetThreadIdealProcessorEx:dword
        extrn '__imp__K32EmptyWorkingSet@4' as K32EmptyWorkingSet:dword
        extrn '__imp__K32EnumDeviceDrivers@12' as K32EnumDeviceDrivers:dword
        extrn '__imp__K32EnumPageFilesA@8' as K32EnumPageFilesA:dword
        extrn '__imp__K32EnumPageFilesW@8' as K32EnumPageFilesW:dword
        extrn '__imp__K32EnumProcessModules@16' as K32EnumProcessModules:dword
        extrn '__imp__K32EnumProcessModulesEx@20' as K32EnumProcessModulesEx:dword
        extrn '__imp__K32EnumProcesses@12' as K32EnumProcesses:dword
        extrn '__imp__K32GetDeviceDriverBaseNameA@12' as K32GetDeviceDriverBaseNameA:dword
        extrn '__imp__K32GetDeviceDriverBaseNameW@12' as K32GetDeviceDriverBaseNameW:dword
        extrn '__imp__K32GetDeviceDriverFileNameA@12' as K32GetDeviceDriverFileNameA:dword
        extrn '__imp__K32GetDeviceDriverFileNameW@12' as K32GetDeviceDriverFileNameW:dword
        extrn '__imp__K32GetMappedFileNameA@16' as K32GetMappedFileNameA:dword
        extrn '__imp__K32GetMappedFileNameW@16' as K32GetMappedFileNameW:dword
        extrn '__imp__K32GetModuleBaseNameA@16' as K32GetModuleBaseNameA:dword
        extrn '__imp__K32GetModuleBaseNameW@16' as K32GetModuleBaseNameW:dword
        extrn '__imp__K32GetModuleFileNameExA@16' as K32GetModuleFileNameExA:dword
        extrn '__imp__K32GetModuleFileNameExW@16' as K32GetModuleFileNameExW:dword
        extrn '__imp__K32GetModuleInformation@16' as K32GetModuleInformation:dword
        extrn '__imp__K32GetPerformanceInfo@8' as K32GetPerformanceInfo:dword
        extrn '__imp__K32GetProcessImageFileNameA@12' as K32GetProcessImageFileNameA:dword
        extrn '__imp__K32GetProcessImageFileNameW@12' as K32GetProcessImageFileNameW:dword
        extrn '__imp__K32GetProcessMemoryInfo@12' as K32GetProcessMemoryInfo:dword
        extrn '__imp__K32GetWsChanges@12' as K32GetWsChanges:dword
        extrn '__imp__K32GetWsChangesEx@12' as K32GetWsChangesEx:dword
        extrn '__imp__K32InitializeProcessForWsWatch@4' as K32InitializeProcessForWsWatch:dword
        extrn '__imp__K32QueryWorkingSet@12' as K32QueryWorkingSet:dword
        extrn '__imp__K32QueryWorkingSetEx@12' as K32QueryWorkingSetEx:dword
        extrn '__imp__LoadAppInitDlls@0' as LoadAppInitDlls:dword
        extrn '__imp__NotifyUILanguageChange@20' as NotifyUILanguageChange:dword
        extrn '__imp__PowerClearRequest@8' as PowerClearRequest:dword
        extrn '__imp__PowerCreateRequest@4' as PowerCreateRequest:dword
        extrn '__imp__PowerSetRequest@8' as PowerSetRequest:dword
        extrn '__imp__QueryIdleProcessorCycleTimeEx@12' as QueryIdleProcessorCycleTimeEx:dword
        extrn '__imp__QueryThreadProfiling@8' as QueryThreadProfiling:dword
        extrn '__imp__QueryThreadpoolStackInformation@8' as QueryThreadpoolStackInformation:dword
        extrn '__imp__QueryUnbiasedInterruptTime@4' as QueryUnbiasedInterruptTime:dword
        extrn '__imp__RaiseFailFastException@12' as RaiseFailFastException:dword
        extrn '__imp__ReadThreadProfilingData@12' as ReadThreadProfilingData:dword
        extrn '__imp__RegCloseKey@4' as RegCloseKey:dword
        extrn '__imp__ResolveLocaleName@12' as ResolveLocaleName:dword
        extrn '__imp__RtlCompareMemory@12' as RtlCompareMemory:dword
        extrn '__imp__RtlCopyMemory@12' as RtlCopyMemory:dword
        extrn '__imp__SetProcessPreferredUILanguages@12' as SetProcessPreferredUILanguages:dword
        if (NTDDI_VERSION < NTDDI_WIN8)
            extrn '__imp__SetProcessUserModeExceptionPolicy@4' as SetProcessUserModeExceptionPolicy:dword
        end if
        extrn '__imp__SetSearchPathMode@4' as SetSearchPathMode:dword
        extrn '__imp__SetStdHandleEx@12' as SetStdHandleEx:dword
        extrn '__imp__SetThreadErrorMode@8' as SetThreadErrorMode:dword
        extrn '__imp__SetThreadGroupAffinity@12' as SetThreadGroupAffinity:dword
        extrn '__imp__SetThreadIdealProcessorEx@12' as SetThreadIdealProcessorEx:dword
        extrn '__imp__SetThreadpoolStackInformation@8' as SetThreadpoolStackInformation:dword
        extrn '__imp__SystemTimeToTzSpecificLocalTimeEx@12' as SystemTimeToTzSpecificLocalTimeEx:dword
        extrn '__imp__TryAcquireSRWLockExclusive@4' as TryAcquireSRWLockExclusive:dword
        extrn '__imp__TryAcquireSRWLockShared@4' as TryAcquireSRWLockShared:dword
        extrn '__imp__TzSpecificLocalTimeToSystemTimeEx@12' as TzSpecificLocalTimeToSystemTimeEx:dword
        extrn '__imp__WerRegisterRuntimeExceptionModule@8' as WerRegisterRuntimeExceptionModule:dword
        extrn '__imp__WerUnregisterRuntimeExceptionModule@8' as WerUnregisterRuntimeExceptionModule:dword
        extrn '__imp__Wow64GetThreadSelectorEntry@12' as Wow64GetThreadSelectorEntry:dword
        CopyMemory equ RtlCopyMemory

        api K32EnumPageFiles,\
            K32GetDeviceDriverBaseName,\
            K32GetDeviceDriverFileName,\
            K32GetMappedFileName,\
            K32GetModuleBaseName,\
            K32GetModuleFileNameEx,\
            K32GetProcessImageFileName
    end if

    if (NTDDI_VERSION >= NTDDI_WIN7SP1)
        extrn '__imp__CopyContext@12' as CopyContext:dword
        extrn '__imp__GetEnabledXStateFeatures@0' as GetEnabledXStateFeatures:dword
        extrn '__imp__GetXStateFeaturesMask@8' as GetXStateFeaturesMask:dword
        extrn '__imp__InitializeContext@16' as InitializeContext:dword
        extrn '__imp__LocateXStateFeature@12' as LocateXStateFeature:dword
        extrn '__imp__SetXStateFeaturesMask@8' as SetXStateFeaturesMask:dword
    end if

    if (NTDDI_VERSION >= NTDDI_WIN8)
        if (NTDDI_VERSION = NTDDI_WIN8)
            extrn '__imp__AcquireStateLock@4' as AcquireStateLock:dword
        end if
        extrn '__imp__AddResourceAttributeAce@28' as AddResourceAttributeAce:dword
        extrn '__imp__AddScopedPolicyIDAce@20' as AddScopedPolicyIDAce:dword
        if (NTDDI_VERSION = NTDDI_WIN8)
            extrn '__imp__CalloutOnFiberStack@12' as CalloutOnFiberStack:dword
            extrn '__imp__CopyExtendedContext@12' as CopyExtendedContext:dword
        end if
        extrn '__imp__CeipIsOptedIn@0' as CeipIsOptedIn:dword
        extrn '__imp__CheckTokenCapability@12' as CheckTokenCapability:dword
        extrn '__imp__CheckTokenMembershipEx@16' as CheckTokenMembershipEx:dword
        extrn '__imp__ClosePackageInfo@4' as ClosePackageInfo:dword
        extrn '__imp__CopyFile2@12' as CopyFile2:dword
        extrn '__imp__CreateFile2@20' as CreateFile2:dword
        extrn '__imp__CreateFileMappingFromApp@20' as CreateFileMappingFromApp:dword
        extrn '__imp__GetAppContainerNamedObjectPath@20' as GetAppContainerNamedObjectPath:dword
        extrn '__imp__GetApplicationUserModelId@12' as GetApplicationUserModelId:dword
        extrn '__imp__GetCachedSigningLevel@24' as GetCachedSigningLevel:dword
        extrn '__imp__GetCurrentApplicationUserModelId@8' as GetCurrentApplicationUserModelId:dword
        extrn '__imp__GetCurrentPackageFamilyName@8' as GetCurrentPackageFamilyName:dword
        extrn '__imp__GetCurrentPackageFullName@8' as GetCurrentPackageFullName:dword
        extrn '__imp__GetCurrentPackageId@8' as GetCurrentPackageId:dword
        extrn '__imp__GetCurrentPackageInfo@16' as GetCurrentPackageInfo:dword
        extrn '__imp__GetCurrentPackagePath@8' as GetCurrentPackagePath:dword
        extrn '__imp__GetCurrentThreadStackLimits@8' as GetCurrentThreadStackLimits:dword
        extrn '__imp__GetFirmwareEnvironmentVariableExA@20' as GetFirmwareEnvironmentVariableExA:dword
        extrn '__imp__GetFirmwareEnvironmentVariableExW@20' as GetFirmwareEnvironmentVariableExW:dword
        extrn '__imp__GetFirmwareType@4' as GetFirmwareType:dword
        extrn '__imp__GetMemoryErrorHandlingCapabilities@4' as GetMemoryErrorHandlingCapabilities:dword
        extrn '__imp__GetOverlappedResultEx@20' as GetOverlappedResultEx:dword
        extrn '__imp__GetPackageFamilyName@12' as GetPackageFamilyName:dword
        extrn '__imp__GetPackageFullName@12' as GetPackageFullName:dword
        extrn '__imp__GetPackageId@12' as GetPackageId:dword
        extrn '__imp__GetPackageInfo@20' as GetPackageInfo:dword
        extrn '__imp__GetPackagePath@16' as GetPackagePath:dword
        extrn '__imp__GetPackagesByPackageFamily@20' as GetPackagesByPackageFamily:dword
        extrn '__imp__GetProcessInformation@16' as GetProcessInformation:dword
        extrn '__imp__GetProcessMitigationPolicy@16' as GetProcessMitigationPolicy:dword
        extrn '__imp__GetSystemTimePreciseAsFileTime@4' as GetSystemTimePreciseAsFileTime:dword
        extrn '__imp__GetThreadInformation@16' as GetThreadInformation:dword
        extrn '__imp__GlobalAddAtomExA@8' as GlobalAddAtomExA:dword
        extrn '__imp__GlobalAddAtomExW@8' as GlobalAddAtomExW:dword
        extrn '__imp__InterlockedPushListSListEx@16' as InterlockedPushListSListEx:dword
        extrn '__imp__IsNativeVhdBoot@4' as IsNativeVhdBoot:dword
        extrn '__imp__IsValidNLSVersion@12' as IsValidNLSVersion:dword
        extrn '__imp__LoadPackagedLibrary@8' as LoadPackagedLibrary:dword
        extrn '__imp__MapViewOfFileFromApp@16' as MapViewOfFileFromApp:dword
        extrn '__imp__OpenPackageInfoByFullName@12' as OpenPackageInfoByFullName:dword
        extrn '__imp__PackageFamilyNameFromFullName@12' as PackageFamilyNameFromFullName:dword
        extrn '__imp__PackageFamilyNameFromId@12' as PackageFamilyNameFromId:dword
        extrn '__imp__PackageFullNameFromId@12' as PackageFullNameFromId:dword
        extrn '__imp__PackageIdFromFullName@16' as PackageIdFromFullName:dword
        extrn '__imp__PackageNameAndPublisherIdFromFamilyName@20' as PackageNameAndPublisherIdFromFamilyName:dword
        extrn '__imp__PrefetchVirtualMemory@16' as PrefetchVirtualMemory:dword
        extrn '__imp__RegCopyTreeW@12' as RegCopyTreeW:dword
        extrn '__imp__RegisterBadMemoryNotification@4' as RegisterBadMemoryNotification:dword
        extrn '__imp__RestoreLastError@4' as RestoreLastError:dword
        extrn '__imp__SetCachedSigningLevel@16' as SetCachedSigningLevel:dword
        extrn '__imp__SetFirmwareEnvironmentVariableExA@20' as SetFirmwareEnvironmentVariableExA:dword
        extrn '__imp__SetFirmwareEnvironmentVariableExW@20' as SetFirmwareEnvironmentVariableExW:dword
        extrn '__imp__SetProcessInformation@16' as SetProcessInformation:dword
        extrn '__imp__SetProcessMitigationPolicy@12' as SetProcessMitigationPolicy:dword
        extrn '__imp__SetThreadInformation@16' as SetThreadInformation:dword
        extrn '__imp__UnregisterBadMemoryNotification@4' as UnregisterBadMemoryNotification:dword
        api GetFirmwareEnvironmentVariableEx,\
            GlobalAddAtomEx,\
            SetFirmwareEnvironmentVariableEx
    end if

    if (NTDDI_VERSION >= NTDDI_WIN81)
        extrn '__imp__DeleteSynchronizationBarrier@4' as DeleteSynchronizationBarrier:dword
        extrn '__imp__EnterSynchronizationBarrier@8' as EnterSynchronizationBarrier:dword
        extrn '__imp__FindPackagesByPackageFamily@28' as FindPackagesByPackageFamily:dword
        extrn '__imp__FormatApplicationUserModelId@16' as FormatApplicationUserModelId:dword
        extrn '__imp__GetPackageApplicationIds@16' as GetPackageApplicationIds:dword
        extrn '__imp__GetPackagePathByFullName@12' as GetPackagePathByFullName:dword
        extrn '__imp__GetStagedPackagePathByFullName@12' as GetStagedPackagePathByFullName:dword
        extrn '__imp__InitializeSynchronizationBarrier@12' as InitializeSynchronizationBarrier:dword
        extrn '__imp__InstallELAMCertificateInfo@4' as InstallELAMCertificateInfo:dword
        extrn '__imp__IsProcessCritical@8' as IsProcessCritical:dword
        extrn '__imp__OOBEComplete@4' as OOBEComplete:dword
        extrn '__imp__ParseApplicationUserModelId@20' as ParseApplicationUserModelId:dword
        extrn '__imp__PssCaptureSnapshot@16' as PssCaptureSnapshot:dword
        extrn '__imp__PssDuplicateSnapshot@20' as PssDuplicateSnapshot:dword
        extrn '__imp__PssFreeSnapshot@8' as PssFreeSnapshot:dword
        extrn '__imp__PssQuerySnapshot@16' as PssQuerySnapshot:dword
        extrn '__imp__PssWalkMarkerCreate@8' as PssWalkMarkerCreate:dword
        extrn '__imp__PssWalkMarkerFree@4' as PssWalkMarkerFree:dword
        extrn '__imp__PssWalkMarkerGetPosition@8' as PssWalkMarkerGetPosition:dword
        extrn '__imp__PssWalkMarkerSeekToBeginning@4' as PssWalkMarkerSeekToBeginning:dword
        extrn '__imp__PssWalkMarkerSetPosition@8' as PssWalkMarkerSetPosition:dword
        extrn '__imp__PssWalkSnapshot@20' as PssWalkSnapshot:dword
        extrn '__imp__RegisterWaitUntilOOBECompleted@12' as RegisterWaitUntilOOBECompleted:dword
        extrn '__imp__UnregisterWaitUntilOOBECompleted@4' as UnregisterWaitUntilOOBECompleted:dword
    end if

    if (NTDDI_VERSION >= NTDDI_WIN10)
        extrn '__imp__CreateEnclave@32' as CreateEnclave:dword
        extrn '__imp__DiscardVirtualMemory@8' as DiscardVirtualMemory:dword
        extrn '__imp__FreeMemoryJobObject@4' as FreeMemoryJobObject:dword
        extrn '__imp__GetProcessDefaultCpuSets@16' as GetProcessDefaultCpuSets:dword
        extrn '__imp__GetSystemCpuSetInformation@20' as GetSystemCpuSetInformation:dword
        extrn '__imp__GetThreadSelectedCpuSets@16' as GetThreadSelectedCpuSets:dword
        extrn '__imp__InitializeEnclave@20' as InitializeEnclave:dword
        extrn '__imp__IsEnclaveTypeSupported@4' as IsEnclaveTypeSupported:dword
        extrn '__imp__LoadEnclaveData@36' as LoadEnclaveData:dword
        extrn '__imp__OfferVirtualMemory@12' as OfferVirtualMemory:dword
        extrn '__imp__QueryIoRateControlInformationJobObject@16' as QueryIoRateControlInformationJobObject:dword
        extrn '__imp__QueryProtectedPolicy@8' as QueryProtectedPolicy:dword
        extrn '__imp__ReclaimVirtualMemory@8' as ReclaimVirtualMemory:dword
        extrn '__imp__SetIoRateControlInformationJobObject@8' as SetIoRateControlInformationJobObject:dword
        extrn '__imp__SetProcessDefaultCpuSets@12' as SetProcessDefaultCpuSets:dword
        extrn '__imp__SetProtectedPolicy@12' as SetProtectedPolicy:dword
        extrn '__imp__SetThreadSelectedCpuSets@12' as SetThreadSelectedCpuSets:dword
        extrn '__imp__WaitForDebugEventEx@8' as WaitForDebugEventEx:dword
    end if

    api AddAtom,\
        BeginUpdateResource,\
        BuildCommDCB,\
        BuildCommDCBAndTimeouts,\
        CallNamedPipe,\
        CommConfigDialog,\
        CompareString,\
        CopyFile,\
        CreateDirectory,\
        CreateDirectoryEx,\
        CreateEvent,\
        CreateFile,\
        CreateFileMapping,\
        CreateMailslot,\
        CreateMutex,\
        CreateNamedPipe,\
        CreateProcess,\
        CreateSemaphore,\
        DefineDosDevice,\
        DeleteFile,\
        EndUpdateResource,\
        EnumCalendarInfo,\
        EnumDateFormats,\
        EnumResourceLanguages,\
        EnumResourceNames,\
        EnumResourceTypes,\
        EnumSystemCodePages,\
        EnumSystemLocales,\
        EnumTimeFormats,\
        ExpandEnvironmentStrings,\
        FatalAppExit,\
        FillConsoleOutputCharacter,\
        FindAtom,\
        FindFirstChangeNotification,\
        FindFirstFile,\
        FindNextFile,\
        FindResource,\
        FindResourceEx,\
        FoldString,\
        FormatMessage,\
        FreeEnvironmentStrings,\
        GetAtomName,\
        GetBinaryType,\
        GetCommandLine,\
        GetCompressedFileSize,\
        GetComputerName,\
        GetConsoleTitle,\
        GetCurrencyFormat,\
        GetCurrentDirectory,\
        GetDateFormat,\
        GetDefaultCommConfig,\
        GetDiskFreeSpace,\
        GetDiskFreeSpaceEx,\
        GetDriveType,\
        GetEnvironmentStrings,\
        GetEnvironmentVariable,\
        GetFileAttributes,\
        GetFullPathName,\
        GetLocaleInfo,\
        GetLogicalDriveStrings,\
        GetModuleFileName,\
        GetModuleHandle,\
        GetNamedPipeHandleState,\
        GetNumberFormat,\
        GetPrivateProfileInt,\
        GetPrivateProfileSection,\
        GetPrivateProfileSectionNames,\
        GetPrivateProfileString,\
        GetPrivateProfileStruct,\
        GetProfileInt,\
        GetProfileSection,\
        GetProfileString,\
        GetShortPathName,\
        GetStartupInfo,\
        GetStringType,\
        GetStringTypeEx,\
        GetSystemDirectory,\
        GetTempFileName,\
        GetTempPath,\
        GetTimeFormat,\
        GetVersionEx,\
        GetVolumeInformation,\
        GetWindowsDirectory,\
        GlobalAddAtom,\
        GlobalFindAtom,\
        GlobalGetAtomName,\
        IsBadStringPtr,\
        LCMapString,\
        LoadLibrary,\
        LoadLibraryEx,\
        lstrcat,\
        lstrcmp,\
        lstrcmpi,\
        lstrcpy,\
        lstrcpyn,\
        lstrlen,\
        MoveFile,\
        MoveFileEx,\
        OpenEvent,\
        OpenFileMapping,\
        OpenMutex,\
        OpenSemaphore,\
        OutputDebugString,\
        PeekConsoleInput,\
        QueryDosDevice,\
        ReadConsole,\
        ReadConsoleInput,\
        ReadConsoleOutput,\
        ReadConsoleOutputCharacter,\
        RemoveDirectory,\
        ScrollConsoleScreenBuffer,\
        SearchPath,\
        SetComputerName,\
        SetConsoleTitle,\
        SetCurrentDirectory,\
        SetDefaultCommConfig,\
        SetEnvironmentVariable,\
        SetFileAttributes,\
        SetLocaleInfo,\
        SetVolumeLabel,\
        UpdateResource,\
        WaitNamedPipe,\
        WriteConsole,\
        WriteConsoleInput,\
        WriteConsoleOutput,\
        WriteConsoleOutputCharacter,\
        WritePrivateProfileSection,\
        WritePrivateProfileString,\
        WritePrivateProfileStruct,\
        WriteProfileSection,\
        WriteProfileString
end if

;======================= Undocumented functions (unknown arguments) =======================;
;if defined APP_WIN64
;    if  ~defined __imp___misaligned_access
;        extrn '__imp___misaligned_access' as __misaligned_access:qword
;    end if
;    extrn '__imp_ActivateActCtxWorker' as ActivateActCtxWorker:qword
;    extrn '__imp_AddRefActCtxWorker' as AddRefActCtxWorker:qword
;    extrn '__imp_AppContainerDeriveSidFromMoniker' as AppContainerDeriveSidFromMoniker:qword
;    extrn '__imp_AppContainerFreeMemory' as AppContainerFreeMemory:qword
;    extrn '__imp_AppContainerLookupDisplayNameMrtReference' as AppContainerLookupDisplayNameMrtReference:qword
;    extrn '__imp_AppContainerLookupMoniker' as AppContainerLookupMoniker:qword
;    extrn '__imp_AppContainerRegisterSid' as AppContainerRegisterSid:qword
;    extrn '__imp_AppContainerUnregisterSid' as AppContainerUnregisterSid:qword
;    extrn '__imp_AppXFreeMemory' as AppXFreeMemory:qword
;    extrn '__imp_AppXGetApplicationData' as AppXGetApplicationData:qword
;    extrn '__imp_AppXGetDevelopmentMode' as AppXGetDevelopmentMode:qword
;    extrn '__imp_AppXGetOSMaxVersionTested' as AppXGetOSMaxVersionTested:qword
;    extrn '__imp_AppXGetOSMinVersion' as AppXGetOSMinVersion:qword
;    extrn '__imp_AppXGetPackageCapabilities' as AppXGetPackageCapabilities:qword
;    extrn '__imp_AppXGetPackageSid' as AppXGetPackageSid:qword
;    extrn '__imp_AppXGetPackageState' as AppXGetPackageState:qword
;    extrn '__imp_AppXLookupDisplayName' as AppXLookupDisplayName:qword
;    extrn '__imp_AppXLookupMoniker' as AppXLookupMoniker:qword
;    extrn '__imp_AppXSetPackageState' as AppXSetPackageState:qword
;    extrn '__imp_BaseCheckAppcompatCache' as BaseCheckAppcompatCache:qword
;    extrn '__imp_BaseCheckAppcompatCacheEx' as BaseCheckAppcompatCacheEx:qword
;    extrn '__imp_BaseCheckAppcompatCacheExWorker' as BaseCheckAppcompatCacheExWorker:qword
;    extrn '__imp_BaseCheckAppcompatCacheWorker' as BaseCheckAppcompatCacheWorker:qword
;    extrn '__imp_BaseCheckElevation' as BaseCheckElevation:qword
;    extrn '__imp_BaseCheckRunApp' as BaseCheckRunApp:qword
;    extrn '__imp_BaseCleanupAppcompatCacheSupport' as BaseCleanupAppcompatCacheSupport:qword
;    extrn '__imp_BaseCleanupAppcompatCacheSupportWorker' as BaseCleanupAppcompatCacheSupportWorker:qword
;    extrn '__imp_BaseDestroyVDMEnvironment' as BaseDestroyVDMEnvironment:qword
;    extrn '__imp_BaseDllReadWriteIniFile' as BaseDllReadWriteIniFile:qword
;    extrn '__imp_BaseDumpAppcompatCache' as BaseDumpAppcompatCache:qword
;    extrn '__imp_BaseDumpAppcompatCacheWorker' as BaseDumpAppcompatCacheWorker:qword
;    extrn '__imp_BaseElevationPostProcessing' as BaseElevationPostProcessing:qword
;    extrn '__imp_BaseFlushAppcompatCache' as BaseFlushAppcompatCache:qword
;    extrn '__imp_BaseFlushAppcompatCacheWorker' as BaseFlushAppcompatCacheWorker:qword
;    extrn '__imp_BaseFormatObjectAttributes' as BaseFormatObjectAttributes:qword
;    extrn '__imp_BaseFreeAppCompatDataForProcessWorker' as BaseFreeAppCompatDataForProcessWorker:qword
;    extrn '__imp_BaseGenerateAppCompatData' as BaseGenerateAppCompatData:qword
;    extrn '__imp_BaseInitAppcompatCacheSupport' as BaseInitAppcompatCacheSupport:qword
;    extrn '__imp_BaseInitAppcompatCacheSupportWorker' as BaseInitAppcompatCacheSupportWorker:qword
;    extrn '__imp_BaseIsAppcompatInfrastructureDisabled' as BaseIsAppcompatInfrastructureDisabled:qword
;    extrn '__imp_BaseIsAppcompatInfrastructureDisabledWorker' as BaseIsAppcompatInfrastructureDisabledWorker:qword
;    extrn '__imp_BaseIsDosApplication' as BaseIsDosApplication:qword
;    extrn '__imp_BaseProcessInitPostImport' as BaseProcessInitPostImport:qword
;    extrn '__imp_BaseProcessStart' as BaseProcessStart:qword
;    extrn '__imp_BaseQueryModuleData' as BaseQueryModuleData:qword
;    extrn '__imp_BaseReadAppCompatDataForProcessWorker' as BaseReadAppCompatDataForProcessWorker:qword
;    extrn '__imp_BaseSetLastNTError' as BaseSetLastNTError:qword
;    extrn '__imp_BaseThreadInitThunk' as BaseThreadInitThunk:qword
;    extrn '__imp_BaseThreadStart' as BaseThreadStart:qword
;    extrn '__imp_BaseUpdateAppcompatCache' as BaseUpdateAppcompatCache:qword
;    extrn '__imp_BaseUpdateAppcompatCacheWorker' as BaseUpdateAppcompatCacheWorker:qword
;    extrn '__imp_BaseUpdateVDMEntry' as BaseUpdateVDMEntry:qword
;    extrn '__imp_BaseVerifyUnicodeString' as BaseVerifyUnicodeString:qword
;    extrn '__imp_BaseWriteErrorElevationRequiredEvent' as BaseWriteErrorElevationRequiredEvent:qword
;    extrn '__imp_BasepAllocateActivationContextActivationBlock' as BasepAllocateActivationContextActivationBlock:qword
;    extrn '__imp_BasepAnsiStringToDynamicUnicodeString' as BasepAnsiStringToDynamicUnicodeString:qword
;    extrn '__imp_BasepAppCompatHookDLL' as BasepAppCompatHookDLL:qword
;    extrn '__imp_BasepAppContainerEnvironmentExtension' as BasepAppContainerEnvironmentExtension:qword
;    extrn '__imp_BasepAppXExtension' as BasepAppXExtension:qword
;    extrn '__imp_BasepCheckAppCompat' as BasepCheckAppCompat:qword
;    extrn '__imp_BasepCheckBadapp' as BasepCheckBadapp:qword
;    extrn '__imp_BasepCheckWebBladeHashes' as BasepCheckWebBladeHashes:qword
;    extrn '__imp_BasepCheckWinSaferRestrictions' as BasepCheckWinSaferRestrictions:qword
;    extrn '__imp_BasepConstructSxsCreateProcessMessage' as BasepConstructSxsCreateProcessMessage:qword
;    extrn '__imp_BasepCopyEncryption' as BasepCopyEncryption:qword
;    extrn '__imp_BasepFreeActivationContextActivationBlock' as BasepFreeActivationContextActivationBlock:qword
;    extrn '__imp_BasepFreeAppCompatData' as BasepFreeAppCompatData:qword
;    extrn '__imp_BasepGetAppCompatData' as BasepGetAppCompatData:qword
;    extrn '__imp_BasepGetComputerNameFromNtPath' as BasepGetComputerNameFromNtPath:qword
;    extrn '__imp_BasepGetExeArchType' as BasepGetExeArchType:qword
;    extrn '__imp_BasepIsProcessAllowed' as BasepIsProcessAllowed:qword
;    extrn '__imp_BasepMapModuleHandle' as BasepMapModuleHandle:qword
;    extrn '__imp_BasepNotifyLoadStringResource' as BasepNotifyLoadStringResource:qword
;    extrn '__imp_BasepPostSuccessAppXExtension' as BasepPostSuccessAppXExtension:qword
;    extrn '__imp_BasepProcessInvalidImage' as BasepProcessInvalidImage:qword
;    extrn '__imp_BasepQueryAppCompat' as BasepQueryAppCompat:qword
;    extrn '__imp_BasepReleaseAppXContext' as BasepReleaseAppXContext:qword
;    extrn '__imp_BasepReleaseSxsCreateProcessUtilityStruct' as BasepReleaseSxsCreateProcessUtilityStruct:qword
;    extrn '__imp_BasepReportFault' as BasepReportFault:qword
;    extrn '__imp_BasepSetFileEncryptionCompression' as BasepSetFileEncryptionCompression:qword
;    extrn '__imp_CancelTimerQueueTimer' as CancelTimerQueueTimer:qword
;    extrn '__imp_CheckAllowDecryptedRemoteDestinationPolicy' as CheckAllowDecryptedRemoteDestinationPolicy:qword
;    extrn '__imp_CheckElevation' as CheckElevation:qword
;    extrn '__imp_CheckForReadOnlyResource' as CheckForReadOnlyResource:qword
;    extrn '__imp_CheckForReadOnlyResourceFilter' as CheckForReadOnlyResourceFilter:qword
;    extrn '__imp_CloseConsoleHandle' as CloseConsoleHandle:qword
;    extrn '__imp_CloseState' as CloseState:qword
;    extrn '__imp_CloseStateAtom' as CloseStateAtom:qword
;    extrn '__imp_CloseStateChangeNotification' as CloseStateChangeNotification:qword
;    extrn '__imp_CloseStateContainer' as CloseStateContainer:qword
;    extrn '__imp_CloseStateLock' as CloseStateLock:qword
;    extrn '__imp_CmdBatNotification' as CmdBatNotification:qword
;    extrn '__imp_CommitStateAtom' as CommitStateAtom:qword
;    extrn '__imp_CompareCalendarDates' as CompareCalendarDates:qword
;    extrn '__imp_ConsoleIMERoutine' as ConsoleIMERoutine:qword
;    extrn '__imp_ConvertNLSDayOfWeekToWin32DayOfWeek' as ConvertNLSDayOfWeekToWin32DayOfWeek:qword
;    extrn '__imp_CreateActCtxWWorker' as CreateActCtxWWorkerqword
;    extrn '__imp_CreateNlsSecurityDescriptor' as CreateNlsSecurityDescriptor:qword
;    extrn '__imp_CreateSocketHandle' as CreateSocketHandle:qword
;    extrn '__imp_CreateStateAtom' as CreateStateAtom:qword
;    extrn '__imp_CreateStateChangeNotification' as CreateStateChangeNotification:qword
;    extrn '__imp_CreateStateContainer' as CreateStateContainer:qword
;    extrn '__imp_CreateStateLock' as CreateStateLock:qword
;    extrn '__imp_CreateStateSubcontainer' as CreateStateSubcontainer:qword
;    extrn '__imp_CtrlRoutine' as CtrlRoutine:qword
;    extrn '__imp_DeactivateActCtxWorker' as DeactivateActCtxWorker:qword
;    extrn '__imp_DeleteStateAtomValue' as DeleteStateAtomValue:qword
;    extrn '__imp_DeleteStateContainer' as DeleteStateContainer:qword
;    extrn '__imp_DeleteStateContainerValue' as DeleteStateContainerValue:qword
;    extrn '__imp_DnsHostnameToComputerNameExW' as DnsHostnameToComputerNameExW:qword
;    extrn '__imp_DuplicateEncryptionInfoFileExt' as DuplicateEncryptionInfoFileExt:qword
;    extrn '__imp_DuplicateStateContainerHandle' as DuplicateStateContainerHandle:qword
;    extrn '__imp_EnumerateStateAtomValues' as EnumerateStateAtomValues:qword
;    extrn '__imp_EnumerateStateContainerItems' as EnumerateStateContainerItems:qword
;    extrn '__imp_FindActCtxSectionGuidWorker' as FindActCtxSectionGuidWorker:qword
;    extrn '__imp_FindActCtxSectionStringWWorker' as FindActCtxSectionStringWWorker:qword
;    extrn '__imp_GetAppContainerAce' as GetAppContainerAceqword
;    extrn '__imp_GetApplicationRecoveryCallbackWorker' as GetApplicationRecoveryCallbackWorker:qword
;    extrn '__imp_GetApplicationRestartSettingsWorker' as GetApplicationRestartSettingsWorker:qword
;    extrn '__imp_GetCalendarDateFormat' as GetCalendarDateFormat:qword
;    extrn '__imp_GetCalendarDaysInMonth' as GetCalendarDaysInMonth:qword
;    extrn '__imp_GetCalendarDifferenceInDays' as GetCalendarDifferenceInDays:qword
;    extrn '__imp_GetCalendarMonthsInYear' as GetCalendarMonthsInYear:qword
;    extrn '__imp_GetCalendarWeekNumber' as GetCalendarWeekNumber:qword
;    extrn '__imp_GetConsoleCharType' as GetConsoleCharType:qword
;    extrn '__imp_GetConsoleCommandHistoryA' as GetConsoleCommandHistoryA:qword
;    extrn '__imp_GetConsoleCommandHistoryW' as GetConsoleCommandHistoryW:qword
;    extrn '__imp_GetConsoleCommandHistoryLengthA' as GetConsoleCommandHistoryLengthA:qword
;    extrn '__imp_GetConsoleCommandHistoryLengthW' as GetConsoleCommandHistoryLengthW:qword
;    extrn '__imp_GetConsoleCursorMode' as GetConsoleCursorMode:qword
;    extrn '__imp_GetConsoleHardwareState' as GetConsoleHardwareState:qword
;    extrn '__imp_GetConsoleInputExeNameA' as GetConsoleInputExeNameA:qword
;    extrn '__imp_GetConsoleInputExeNameW' as GetConsoleInputExeNameW:qword
;    extrn '__imp_GetConsoleInputWaitHandle' as GetConsoleInputWaitHandle:qword
;    extrn '__imp_GetConsoleKeyboardLayoutNameA' as GetConsoleKeyboardLayoutNameA:qword
;    extrn '__imp_GetConsoleKeyboardLayoutNameW' as GetConsoleKeyboardLayoutNameW:qword
;    extrn '__imp_GetCPFileNameFromRegistry' as GetCPFileNameFromRegistry:qword
;    extrn '__imp_GetCurrentActCtxWorker' as GetCurrentActCtxWorker:qword
;    extrn '__imp_GetDateFormatAWorker' as GetDateFormatAWorker:qword
;    extrn '__imp_GetDateFormatWWorker' as GetDateFormatWWorkerqword
;    extrn '__imp_GetDefaultSortkeySize' as GetDefaultSortkeySize:qword
;    extrn '__imp_GetEncryptedFileVersionExt' as GetEncryptedFileVersionExt:qword
;    extrn '__imp_GetEraNameCountedString' as GetEraNameCountedString:qword
;    extrn '__imp_GetHivePath' as GetHivePath:qword
;    extrn '__imp_GetLinguistLangSize' as GetLinguistLangSize:qword
;    extrn '__imp_GetNlsSectionName' as GetNlsSectionName:qword
;    extrn '__imp_GetRoamingLastObservedChangeTime' as GetRoamingLastObservedChangeTime:qword
;    extrn '__imp_GetSerializedAtomBytes' as GetSerializedAtomBytes:qword
;    extrn '__imp_GetStateContainerDepth' as GetStateContainerDepth:qword
;    extrn '__imp_GetStateFolder' as GetStateFolder:qword
;    extrn '__imp_GetStateRootFolder' as GetStateRootFolder:qword
;    extrn '__imp_GetStateSettingsFolder' as GetStateSettingsFolder:qword
;    extrn '__imp_GetStateVersion' as GetStateVersion:qword
;    extrn '__imp_GetSystemAppDataFolder' as GetSystemAppDataFolder:qword
;    extrn '__imp_GetSystemAppDataKey' as GetSystemAppDataKey:qword
;    extrn '__imp_GetTimeFormatAWorker' as GetTimeFormatAWorker:qword
;    extrn '__imp_GetTimeFormatWWorker' as GetTimeFormatWWorker:qword
;    extrn '__imp_HeapSummary' as HeapSummary:qword
;    extrn '__imp_HeapCreateTagsW' as HeapCreateTagsW:qword
;    extrn '__imp_HeapExtend' as HeapExtend:qword
;    extrn '__imp_HeapQueryTagW' as HeapQueryTagW:qword
;    extrn '__imp_HeapUsage' as HeapUsage:qword
;    extrn '__imp_IsValidUILanguage' as IsValidUILanguage:qword
;    extrn '__imp_NlsCheckPolicy' as NlsCheckPolicy:qword
;    extrn '__imp_NlsConvertIntegerToString' as NlsConvertIntegerToString:qword
;    extrn '__imp_NlsEventDataDescCreate' as NlsEventDataDescCreate:qword
;    extrn '__imp_NlsGetCacheUpdateCount' as NlsGetCacheUpdateCount:qword
;    extrn '__imp_NlsResetProcessLocale' as NlsResetProcessLocale:qword
;    extrn '__imp_NlsUpdateLocale' as NlsUpdateLocale:qword
;    extrn '__imp_NlsUpdateSystemLocale' as NlsUpdateSystemLocale:qword
;    extrn '__imp_NlsWriteEtwEvent' as NlsWriteEtwEvent:qword
;    extrn '__imp_NotifyMountMgr' as NotifyMountMgr:qword
;    extrn '__imp_NtVdm64CreateProcessInternalW' as NtVdm64CreateProcessInternalW:qword
;    extrn '__imp_OpenConsoleWStub' as OpenConsoleWStub:qword
;    extrn '__imp_OpenState' as OpenState:qword
;    extrn '__imp_OpenStateAtom' as OpenStateAtom:qword
;    extrn '__imp_OpenStateExplicit' as OpenStateExplicit:qword
;    extrn '__imp_OverrideRoamingDataModificationTimesInRange' as OverrideRoamingDataModificationTimesInRange:qword
;    extrn '__imp_PssWalkMarkerRewind' as PssWalkMarkerRewind:qword
;    extrn '__imp_PssWalkMarkerSeek' as PssWalkMarkerSeek:qword
;    extrn '__imp_PssWalkMarkerTell' as PssWalkMarkerTell:qword
;    extrn '__imp_PrivMoveFileIdentityW' as PrivMoveFileIdentityW:qword
;    extrn '__imp_PublishStateChangeNotification' as PublishStateChangeNotification:qword
;    extrn '__imp_QueryActCtxSettingsWWorker' as QueryActCtxSettingsWWorker:qword
;    extrn '__imp_QueryActCtxWWorker' as QueryActCtxWWorker:qword
;    extrn '__imp_QueryStateAtomValueInfo' as QueryStateAtomValueInfo:qword
;    extrn '__imp_QueryStateContainerItemInfo' as QueryStateContainerItemInfo:qword
;    extrn '__imp_QuirkGetData2Worker' as QuirkGetData2Worker:qword
;    extrn '__imp_QuirkGetDataWorker' as QuirkGetDataWorker:qword
;    extrn '__imp_QuirkIsEnabled2Worker' as QuirkIsEnabled2Worker:qword
;    extrn '__imp_QuirkIsEnabled3Worker' as QuirkIsEnabled3Worker:qword
;    extrn '__imp_QuirkIsEnabledForPackage2Worker' as QuirkIsEnabledForPackage2Worker:qword
;    extrn '__imp_QuirkIsEnabledForPackage3Worker' as QuirkIsEnabledForPackage3Worker:qword
;    extrn '__imp_QuirkIsEnabledForPackage4Worker' as QuirkIsEnabledForPackage4Worker:qword
;    extrn '__imp_QuirkIsEnabledForPackageWorker' as QuirkIsEnabledForPackageWorker:qword
;    extrn '__imp_QuirkIsEnabledForProcessWorker' as QuirkIsEnabledForProcessWorker:qword
;    extrn '__imp_QuirkIsEnabledWorker' as QuirkIsEnabledWorker:qword
;    extrn '__imp_RaiseInvalid16BitExeError' as RaiseInvalid16BitExeError:qword
;    extrn '__imp_ReadStateAtomValue' as ReadStateAtomValue:qword
;    extrn '__imp_ReadStateContainerValue' as ReadStateContainerValue:qword
;    extrn '__imp_RegisterConsoleIME' as RegisterConsoleIME:qword
;    extrn '__imp_RegisterConsoleOS2' as RegisterConsoleOS2:qword
;    extrn '__imp_RegisterConsoleVDM' as RegisterConsoleOS2:qword
;    extrn '__imp_RegisterStateChangeNotification' as RegisterStateChangeNotification:qword
;    extrn '__imp_RegisterStateLock' as RegisterStateLock:qword
;    extrn '__imp_RegisterWaitForInputIdle' as RegisterWaitForInputIdle:qword
;    extrn '__imp_RegisterWaitForSingleObjectEx' as RegisterWaitForSingleObjectEx:qword
;    extrn '__imp_RegisterWowBaseHandlers' as RegisterWowBaseHandlers:qword
;    extrn '__imp_RegisterWowExec' as RegisterWowExec:qword
;    extrn '__imp_RegKrnGetGlobalState' as RegKrnGetGlobalState:qword
;    extrn '__imp_RegKrnInitialize' as RegKrnInitialize:qword
;    extrn '__imp_ReleaseActCtxWorker' as ReleaseActCtxWorker:qword
;    extrn '__imp_ReleaseStateLock' as ReleaseStateLock:qword
;    extrn '__imp_RemoveLocalAlternateComputerNameA' as RemoveLocalAlternateComputerNameA:qword
;    extrn '__imp_RemoveLocalAlternateComputerNameW' as RemoveLocalAlternateComputerNameW:qword
;    extrn '__imp_ResetState' as ResetState:qword
;    extrn '__imp_SetClientDynamicTimeZoneInformation' as SetClientDynamicTimeZoneInformation:qword
;    extrn '__imp_SetClientTimeZoneInformation' as SetClientTimeZoneInformation:qword
;    extrn '__imp_SetComPlusPackageInstallStatus' as SetComPlusPackageInstallStatus:qword
;    extrn '__imp_SetComputerNameEx2W' as SetComputerNameEx2W:qword
;    extrn '__imp_SetConsoleCommandHistoryMode' as SetComputerNameEx2W:qword
;    extrn '__imp_SetConsoleCursorMode' as SetConsoleCursorMode:qword
;    extrn '__imp_SetConsoleInputExeNameA' as SetConsoleInputExeNameA:qword
;    extrn '__imp_SetConsoleInputExeNameW' as SetConsoleInputExeNameW:qword
;    extrn '__imp_SetConsoleKeyShortcuts' as SetConsoleKeyShortcuts:qword
;    extrn '__imp_SetConsoleLocalEUDC' as SetConsoleLocalEUDC:qword
;    extrn '__imp_SetConsoleMenuClose' as SetConsoleMenuClose:qword
;    extrn '__imp_SetCPGlobal' as SetCPGlobal:qword
;    extrn '__imp_SetRoamingLastObservedChangeTime' as SetRoamingLastObservedChangeTime:qword
;    extrn '__imp_SetStateVersion' as SetStateVersion:qword
;    extrn '__imp_SetThreadpoolTimerEx' as SetThreadpoolTimerEx:qword
;    extrn '__imp_SetVolumeMountPointWStub' as SetVolumeMountPointWStub:qword
;    extrn '__imp_SetWaitableTimerEx' as SetWaitableTimerEx:qword
;    extrn '__imp_SortCloseHandle' as SortCloseHandle:qword
;    extrn '__imp_SortGetHandle' as SortGetHandle:qword
;    extrn '__imp_SubscribeStateChangeNotification' as SubscribeStateChangeNotification:qword
;    extrn '__imp_TermsrvConvertSysRootToUserDir' as TermsrvConvertSysRootToUserDir:qword
;    extrn '__imp_TermsrvAppInstallMode' as TermsrvAppInstallMode:qword
;    extrn '__imp_TermsrvCreateRegEntry' as TermsrvCreateRegEntry:qword
;    extrn '__imp_TermsrvDeleteKey' as TermsrvDeleteKey:qword
;    extrn '__imp_TermsrvDeleteValue' as TermsrvDeleteValue:qword
;    extrn '__imp_TermsrvGetPreSetValue' as TermsrvGetPreSetValue:qword
;    extrn '__imp_TermsrvGetWindowsDirectoryA' as TermsrvGetWindowsDirectoryA:qword
;    extrn '__imp_TermsrvGetWindowsDirectoryW' as TermsrvGetWindowsDirectoryW:qword
;    extrn '__imp_TermsrvOpenRegEntry' as TermsrvOpenRegEntry:qword
;    extrn '__imp_TermsrvOpenUserClasses' as TermsrvOpenUserClasses:qword
;    extrn '__imp_TermsrvRestoreKey' as TermsrvRestoreKey:qword
;    extrn '__imp_TermsrvSetKeySecurity' as TermsrvSetKeySecurity:qword
;    extrn '__imp_TermsrvSetValueKey' as TermsrvSetValueKey:qword
;    extrn '__imp_TermsrvSyncUserIniFileExt' as TermsrvSyncUserIniFileExt:qword
;    extrn '__imp_UnmapViewOfFileEx' as UnmapViewOfFileEx:qword
;    extrn '__imp_UnregisterConsoleIME' as UnregisterConsoleIME:qword
;    extrn '__imp_UTRegister' as UTRegister:qword
;    extrn '__imp_UTUnRegister' as UTUnRegister:qword
;    extrn '__imp_UnregisterStateChangeNotification' as UnregisterStateChangeNotification:qword
;    extrn '__imp_UnregisterStateLock' as UnregisterStateLock:qword
;    extrn '__imp_UnsubscribeStateChangeNotification' as UnsubscribeStateChangeNotification:qword
;    extrn '__imp_ValidateLCType' as ValidateLCType:qword
;    extrn '__imp_ValidateLocale' as ValidateLocale:qword
;    extrn '__imp_VDMConsoleOperation' as VDMConsoleOperation:qword
;    extrn '__imp_VDMOperationStarted' as VDMOperationStarted:qword
;    extrn '__imp_VerifyConsoleIoHandle' as VerifyConsoleIoHandle:qword
;    extrn '__imp_WerGetFlagsWorker' as WerGetFlagsWorker:qword
;    extrn '__imp_WerRegisterFileWorker' as WerGetFlagsWorker:qword
;    extrn '__imp_WerRegisterMemoryBlockWorker' as WerRegisterMemoryBlockWorker:qword
;    extrn '__imp_WerRegisterRuntimeExceptionModuleWorker' as WerRegisterRuntimeExceptionModuleWorker:qword
;    extrn '__imp_WerSetFlagsWorker' as WerSetFlagsWorker:qword
;    extrn '__imp_WerUnregisterFileWorker' as WerUnregisterFileWorker:qword
;    extrn '__imp_WerUnregisterMemoryBlockWorker' as WerUnregisterMemoryBlockWorker:qword
;    extrn '__imp_WerUnregisterRuntimeExceptionModuleWorker' as WerUnregisterRuntimeExceptionModuleWorker:qword
;    extrn '__imp_WerpCleanupMessageMapping' as WerpCleanupMessageMapping:qword
;    extrn '__imp_WerpGetDebugger' as WerpGetDebugger:qword
;    extrn '__imp_WerpInitiateRemoteRecovery' as WerpInitiateRemoteRecovery:qword
;    extrn '__imp_WerpLaunchAeDebug' as WerpLaunchAeDebug:qword
;    extrn '__imp_WerpNotifyLoadStringResource' as WerpNotifyLoadStringResource:qword
;    extrn '__imp_WerpNotifyLoadStringResourceEx' as WerpNotifyLoadStringResourceEx:qword
;    extrn '__imp_WerpNotifyLoadStringResourceWorker' as WerpNotifyLoadStringResourceWorker:qword
;    extrn '__imp_WerpNotifyUseStringResource' as WerpNotifyUseStringResource:qword
;    extrn '__imp_WerpNotifyUseStringResourceWorker' as WerpNotifyUseStringResourceWorker:qword
;    extrn '__imp_WerpStringLookup' as WerpStringLookup:qword
;    extrn '__imp_WriteConsoleInputVDMA' as WriteConsoleInputVDMA:qword
;    extrn '__imp_WriteConsoleInputVDMW' as WriteConsoleInputVDMW:qword
;    extrn '__imp_WriteStateAtomValue' as WriteStateAtomValue:qword
;    extrn '__imp_WriteStateContainerValue' as WriteStateContainerValue:qword
;    extrn '__imp_ZombifyActCtxWorker' as ZombifyActCtxWorker:qword
;else
;    extrn '__imp__ActivateActCtxWorker@??' as ActivateActCtxWorker:dword
;    extrn '__imp__AddRefActCtxWorker@??' as AddRefActCtxWorker:dword
;    extrn '__imp__AppContainerDeriveSidFromMoniker@??' as AppContainerDeriveSidFromMoniker:dword
;    extrn '__imp__AppContainerFreeMemory@??' as AppContainerFreeMemory:dword
;    extrn '__imp__AppContainerLookupDisplayNameMrtReference@??' as AppContainerLookupDisplayNameMrtReference:dword
;    extrn '__imp__AppContainerLookupMoniker@??' as AppContainerLookupMoniker:dword
;    extrn '__imp__AppContainerRegisterSid@??' as AppContainerRegisterSid:dword
;    extrn '__imp__AppContainerUnregisterSid@??' as AppContainerUnregisterSid:dword
;    extrn '__imp__AppXFreeMemory@??' as AppXFreeMemory:dword
;    extrn '__imp__AppXGetApplicationData@??' as AppXGetApplicationData:dword
;    extrn '__imp__AppXGetDevelopmentMode@??' as AppXGetDevelopmentMode:dword
;    extrn '__imp__AppXGetOSMaxVersionTested@??' as AppXGetOSMaxVersionTested:dword
;    extrn '__imp__AppXGetOSMinVersion@??' as AppXGetOSMinVersion:dword
;    extrn '__imp__AppXGetPackageCapabilities@??' as AppXGetPackageCapabilities:dword
;    extrn '__imp__AppXGetPackageSid@??' as AppXGetPackageSid:dword
;    extrn '__imp__AppXGetPackageState@??' as AppXGetPackageState:dword
;    extrn '__imp__AppXLookupDisplayName@??' as AppXLookupDisplayName:dword
;    extrn '__imp__AppXLookupMoniker@??' as AppXLookupMoniker:dword
;    extrn '__imp__AppXSetPackageState@??' as AppXSetPackageState:dword
;    extrn '__imp__BaseCheckAppcompatCache@??' as BaseCheckAppcompatCache:dword
;    extrn '__imp__BaseCheckAppcompatCacheEx@??' as BaseCheckAppcompatCacheEx:dword
;    extrn '__imp__BaseCheckAppcompatCacheExWorker@??' as BaseCheckAppcompatCacheExWorker:dword
;    extrn '__imp__BaseCheckAppcompatCacheWorker@??' as BaseCheckAppcompatCacheWorker:dword
;    extrn '__imp__BaseCheckElevation@??' as BaseCheckElevation:dword
;    extrn '__imp__BaseCheckRunApp@??' as BaseCheckRunApp:dword
;    extrn '__imp__BaseCleanupAppcompatCacheSupport@??' as BaseCleanupAppcompatCacheSupport:dword
;    extrn '__imp__BaseCleanupAppcompatCacheSupportWorker@??' as BaseCleanupAppcompatCacheSupportWorker:dword
;    extrn '__imp__BaseDestroyVDMEnvironment@??' as BaseDestroyVDMEnvironment:dword
;    extrn '__imp__BaseDllReadWriteIniFile@??' as BaseDllReadWriteIniFile:dword
;    extrn '__imp__BaseDumpAppcompatCache@??' as BaseDumpAppcompatCache:dword
;    extrn '__imp__BaseDumpAppcompatCacheWorker@??' as BaseDumpAppcompatCacheWorker:dword
;    extrn '__imp__BaseElevationPostProcessing@??' as BaseElevationPostProcessing:dword
;    extrn '__imp__BaseFlushAppcompatCache@??' as BaseFlushAppcompatCache:dword
;    extrn '__imp__BaseFlushAppcompatCacheWorker@??' as BaseFlushAppcompatCacheWorker:dword
;    extrn '__imp__BaseFormatObjectAttributes@??' as BaseFormatObjectAttributes:dword
;    extrn '__imp__BasepFreeAppCompatData@??' as BasepFreeAppCompatData:dword
;    extrn '__imp__BaseGenerateAppCompatData@??' as BaseGenerateAppCompatData:dword
;    extrn '__imp__BaseInitAppcompatCacheSupport@??' as BaseInitAppcompatCacheSupport:dword
;    extrn '__imp__BaseInitAppcompatCacheSupportWorker@??' as BaseInitAppcompatCacheSupportWorker:dword
;    extrn '__imp__BaseIsAppcompatInfrastructureDisabled@??' as BaseIsAppcompatInfrastructureDisabled:dword
;    extrn '__imp__BaseIsAppcompatInfrastructureDisabledWorker@??' as BaseIsAppcompatInfrastructureDisabledWorker:dword
;    extrn '__imp__BaseIsDosApplication@??' as BaseIsDosApplication:dword
;    extrn '__imp__BaseProcessInitPostImport@??' as BaseProcessInitPostImport:dword
;    extrn '__imp__BaseProcessStart@??' as BaseProcessStart:dword
;    extrn '__imp__BaseQueryModuleData@??' as BaseQueryModuleData:dword
;    extrn '__imp__BaseReadAppCompatDataForProcessWorker@??' as BaseReadAppCompatDataForProcessWorker:dword
;    extrn '__imp__BaseSetLastNTError@??' as BaseSetLastNTError:dword
;    extrn '__imp__BaseThreadInitThunk@??' as BaseThreadInitThunk:dword
;    extrn '__imp__BaseThreadStart@??' as BaseThreadStart:dword
;    extrn '__imp__BaseUpdateAppcompatCache@??' as BaseUpdateAppcompatCache:dword
;    extrn '__imp__BaseUpdateAppcompatCacheWorker@??' as BaseUpdateAppcompatCacheWorker:dword
;    extrn '__imp__BaseUpdateVDMEntry@??' as BaseUpdateVDMEntry:dword
;    extrn '__imp__BaseVerifyUnicodeString@??' as BaseVerifyUnicodeString:dword
;    extrn '__imp__BaseWriteErrorElevationRequiredEvent@??' as BaseWriteErrorElevationRequiredEvent:dword
;    extrn '__imp__BasepAllocateActivationContextActivationBlock@??' as BasepAllocateActivationContextActivationBlock:dword
;    extrn '__imp__BasepAnsiStringToDynamicUnicodeString@??' as BasepAnsiStringToDynamicUnicodeString:dword
;    extrn '__imp__BasepAppCompatHookDLL@??' as BasepAppCompatHookDLL:dword
;    extrn '__imp__BasepAppContainerEnvironmentExtension@??' as BasepAppContainerEnvironmentExtension:dword
;    extrn '__imp__BasepAppXExtension@??' as BasepAppXExtension:dword
;    extrn '__imp__BasepCheckAppCompat@??' as BasepCheckAppCompat:dword
;    extrn '__imp__BasepCheckBadapp@??' as BasepCheckBadapp:dword
;    extrn '__imp__BasepCheckWebBladeHashes@??' as BasepCheckWebBladeHashes:dword
;    extrn '__imp__BasepCheckWinSaferRestrictions@??' as BasepCheckWinSaferRestrictions:dword
;    extrn '__imp__BasepConstructSxsCreateProcessMessage@??' as BasepConstructSxsCreateProcessMessage:dword
;    extrn '__imp__BasepCopyEncryption@??' as BasepCopyEncryption:dword
;    extrn '__imp__BasepFreeActivationContextActivationBlock@??' as BasepFreeActivationContextActivationBlock:dword
;    extrn '__imp__BaseFreeAppCompatDataForProcessWorker@??' as BaseFreeAppCompatDataForProcessWorker:dword
;    extrn '__imp__BasepGetAppCompatData@??' as BasepGetAppCompatData:dword
;    extrn '__imp__BasepGetComputerNameFromNtPath@??' as BasepGetComputerNameFromNtPath:dword
;    extrn '__imp__BasepGetExeArchType@??' as BasepGetExeArchType:dword
;    extrn '__imp__BasepIsProcessAllowed@??' as BasepIsProcessAllowed:dword
;    extrn '__imp__BasepMapModuleHandle@??' as BasepMapModuleHandle:dword
;    extrn '__imp__BasepNotifyLoadStringResource@??' as BasepNotifyLoadStringResource:dword
;    extrn '__imp__BasepPostSuccessAppXExtension@??' as BasepPostSuccessAppXExtension:dword
;    extrn '__imp__BasepProcessInvalidImage@??' as BasepProcessInvalidImage:dword
;    extrn '__imp__BasepQueryAppCompat@??' as BasepQueryAppCompat:dword
;    extrn '__imp__BasepReleaseAppXContext@??' as BasepReleaseAppXContext:dword
;    extrn '__imp__BasepReleaseSxsCreateProcessUtilityStruct@??' as BasepReleaseSxsCreateProcessUtilityStruct:dword
;    extrn '__imp__BasepReportFault@??' as BasepReportFault:dword
;    extrn '__imp__BasepSetFileEncryptionCompression@??' as BasepSetFileEncryptionCompression:dword
;    extrn '__imp__CancelTimerQueueTimer@??' as CancelTimerQueueTimer:dword
;    extrn '__imp__CheckAllowDecryptedRemoteDestinationPolicy@??' as CheckAllowDecryptedRemoteDestinationPolicy:dword
;    extrn '__imp__CheckElevation@??' as CheckElevation:dword
;    extrn '__imp__CheckForReadOnlyResource@??' as CheckForReadOnlyResource:dword
;    extrn '__imp__CheckForReadOnlyResourceFilter@??' as CheckForReadOnlyResourceFilter:dword
;    extrn '__imp__CloseConsoleHandle@??' as CloseConsoleHandle:dword
;    extrn '__imp__CloseState@??' as CloseState:dword
;    extrn '__imp__CloseStateAtom@??' as CloseStateAtom:dword
;    extrn '__imp__CloseStateChangeNotification@??' as CloseStateChangeNotification:dword
;    extrn '__imp__CloseStateContainer@??' as CloseStateContainer:dword
;    extrn '__imp__CloseStateLock@??' as CloseStateLock:dword
;    extrn '__imp__CmdBatNotification@??' as CmdBatNotification:dword
;    extrn '__imp__CommitStateAtom@??' as CommitStateAtom:dword
;    extrn '__imp__CompareCalendarDates@??' as CompareCalendarDates:dword
;    extrn '__imp__ConsoleIMERoutine@??' as ConsoleIMERoutine:dword
;    extrn '__imp__ConvertNLSDayOfWeekToWin32DayOfWeek@??' as ConvertNLSDayOfWeekToWin32DayOfWeek:dword
;    extrn '__imp__CreateActCtxWWorker@??' as CreateActCtxWWorkerqword
;    extrn '__imp__CreateNlsSecurityDescriptor@??' as CreateNlsSecurityDescriptor:dword
;    extrn '__imp__CreateSocketHandle@??' as CreateSocketHandle:dword
;    extrn '__imp__CreateStateAtom@??' as CreateStateAtom:dword
;    extrn '__imp__CreateStateChangeNotification@??' as CreateStateChangeNotification:dword
;    extrn '__imp__CreateStateContainer@??' as CreateStateContainer:dword
;    extrn '__imp__CreateStateLock@??' as CreateStateLock:dword
;    extrn '__imp__CreateStateSubcontainer@??' as CreateStateSubcontainer:dword
;    extrn '__imp__CtrlRoutine@??' as CtrlRoutine:dword
;    extrn '__imp__DeactivateActCtxWorker@??' as DeactivateActCtxWorker:dword
;    extrn '__imp__DeleteStateAtomValue@??' as DeleteStateAtomValue:dword
;    extrn '__imp__DeleteStateContainer@??' as DeleteStateContainer:dword
;    extrn '__imp__DeleteStateContainerValue@??' as DeleteStateContainerValue:dword
;    extrn '__imp__DnsHostnameToComputerNameExW@??' as DnsHostnameToComputerNameExW:dword
;    extrn '__imp__DuplicateEncryptionInfoFileExt@??' as DuplicateEncryptionInfoFileExt:dword
;    extrn '__imp__DuplicateStateContainerHandle@??' as DuplicateStateContainerHandle:dword
;    extrn '__imp__EnumerateStateAtomValues@??' as EnumerateStateAtomValues:dword
;    extrn '__imp__EnumerateStateContainerItems@??' as EnumerateStateContainerItems:dword
;    extrn '__imp__FindActCtxSectionGuidWorker@??' as FindActCtxSectionGuidWorker:dword
;    extrn '__imp__FindActCtxSectionStringWWorker@??' as FindActCtxSectionStringWWorker:dword
;    extrn '__imp__GetAppContainerAce@??' as GetAppContainerAceqword
;    extrn '__imp__GetApplicationRecoveryCallbackWorker@??' as GetApplicationRecoveryCallbackWorker:dword
;    extrn '__imp__GetApplicationRestartSettingsWorker@??' as GetApplicationRestartSettingsWorker:dword
;    extrn '__imp__GetCalendarDateFormat@??' as GetCalendarDateFormat:dword
;    extrn '__imp__GetCalendarDaysInMonth@??' as GetCalendarDaysInMonth:dword
;    extrn '__imp__GetCalendarDifferenceInDays@??' as GetCalendarDifferenceInDays:dword
;    extrn '__imp__GetCalendarMonthsInYear@??' as GetCalendarMonthsInYear:dword
;    extrn '__imp__GetCalendarWeekNumber@??' as GetCalendarWeekNumber:dword
;    extrn '__imp__GetConsoleCharType@??' as GetConsoleCharType:dword
;    extrn '__imp__GetConsoleCommandHistoryA@??' as GetConsoleCommandHistoryA:dword
;    extrn '__imp__GetConsoleCommandHistoryW@??' as GetConsoleCommandHistoryW:dword
;    extrn '__imp__GetConsoleCommandHistoryLengthA@??' as GetConsoleCommandHistoryLengthA:dword
;    extrn '__imp__GetConsoleCommandHistoryLengthW@??' as GetConsoleCommandHistoryLengthW:dword
;    extrn '__imp__GetConsoleCursorMode@??' as GetConsoleCursorMode:dword
;    extrn '__imp__GetConsoleHardwareState@??' as GetConsoleHardwareState:dword
;    extrn '__imp__GetConsoleInputExeNameA@??' as GetConsoleInputExeNameA:dword
;    extrn '__imp__GetConsoleInputExeNameW@??' as GetConsoleInputExeNameW:dword
;    extrn '__imp__GetConsoleInputWaitHandle@??' as GetConsoleInputWaitHandle:dword
;    extrn '__imp__GetConsoleKeyboardLayoutNameA@??' as GetConsoleKeyboardLayoutNameA:dword
;    extrn '__imp__GetConsoleKeyboardLayoutNameW@??' as GetConsoleKeyboardLayoutNameW:dword
;    extrn '__imp__GetCPFileNameFromRegistry@??' as GetCPFileNameFromRegistry:dword
;    extrn '__imp__GetCurrentActCtxWorker@??' as GetCurrentActCtxWorker:dword
;    extrn '__imp__GetDateFormatAWorker@??' as GetDateFormatAWorker:dword
;    extrn '__imp__GetDateFormatWWorker@??' as GetDateFormatWWorkerqword
;    extrn '__imp__GetDefaultSortkeySize@??' as GetDefaultSortkeySize:dword
;    extrn '__imp__GetEncryptedFileVersionExt@??' as GetEncryptedFileVersionExt:dword
;    extrn '__imp__GetEraNameCountedString@??' as GetEraNameCountedString:dword
;    extrn '__imp__GetHivePath@??' as GetHivePath:dword
;    extrn '__imp__GetLinguistLangSize@??' as GetLinguistLangSize:dword
;    extrn '__imp__GetNlsSectionName@??' as GetNlsSectionName:dword
;    extrn '__imp__GetRoamingLastObservedChangeTime@??' as GetRoamingLastObservedChangeTime:dword
;    extrn '__imp__GetSerializedAtomBytes@??' as GetSerializedAtomBytes:dword
;    extrn '__imp__GetStateContainerDepth@??' as GetStateContainerDepth:dword
;    extrn '__imp__GetStateFolder@??' as GetStateFolder:dword
;    extrn '__imp__GetStateRootFolder@??' as GetStateRootFolder:dword
;    extrn '__imp__GetStateSettingsFolder@??' as GetStateSettingsFolder:dword
;    extrn '__imp__GetStateVersion@??' as GetStateVersion:dword
;    extrn '__imp__GetSystemAppDataFolder@??' as GetSystemAppDataFolder:dword
;    extrn '__imp__GetSystemAppDataKey@??' as GetSystemAppDataKey:dword
;    extrn '__imp__GetTimeFormatAWorker@??' as GetTimeFormatAWorker:dword
;    extrn '__imp__GetTimeFormatWWorker@??' as GetTimeFormatWWorker:dword
;    extrn '__imp__HeapSummary@??' as HeapSummary:dword
;    extrn '__imp__HeapCreateTagsW@??' as HeapCreateTagsW:dword
;    extrn '__imp__HeapExtend@??' as HeapExtend:dword
;    extrn '__imp__HeapQueryTagW@??' as HeapQueryTagW:dword
;    extrn '__imp__HeapUsage@??' as HeapUsage:dword
;    extrn '__imp__IsValidUILanguage@??' as IsValidUILanguage:dword
;    extrn '__imp__NlsCheckPolicy@??' as NlsCheckPolicy:dword
;    extrn '__imp__NlsConvertIntegerToString@??' as NlsConvertIntegerToString:dword
;    extrn '__imp__NlsEventDataDescCreate@??' as NlsEventDataDescCreate:dword
;    extrn '__imp__NlsGetCacheUpdateCount@??' as NlsGetCacheUpdateCount:dword
;    extrn '__imp__NlsResetProcessLocale@??' as NlsResetProcessLocale:dword
;    extrn '__imp__NlsUpdateLocale@??' as NlsUpdateLocale:dword
;    extrn '__imp__NlsUpdateSystemLocale@??' as NlsUpdateSystemLocale:dword
;    extrn '__imp__NlsWriteEtwEvent@??' as NlsWriteEtwEvent:dword
;    extrn '__imp__NotifyMountMgr@??' as NotifyMountMgr:dword
;    extrn '__imp__NtVdm64CreateProcessInternalW@??' as NtVdm64CreateProcessInternalW:dword
;    extrn '__imp__OpenConsoleWStub@??' as OpenConsoleWStub:dword
;    extrn '__imp__OpenState@??' as OpenState:dword
;    extrn '__imp__OpenStateAtom@??' as OpenStateAtom:dword
;    extrn '__imp__OpenStateExplicit@??' as OpenStateExplicit:dword
;    extrn '__imp__OverrideRoamingDataModificationTimesInRange@??' as OverrideRoamingDataModificationTimesInRange:dword
;    extrn '__imp__PssWalkMarkerRewind@??' as PssWalkMarkerRewind:dword
;    extrn '__imp__PssWalkMarkerSeek@??' as PssWalkMarkerSeek:dword
;    extrn '__imp__PssWalkMarkerTell@??' as PssWalkMarkerTell:dword
;    extrn '__imp__PrivMoveFileIdentityW@??' as PrivMoveFileIdentityW:dword
;    extrn '__imp__PublishStateChangeNotification@??' as PublishStateChangeNotification:dword
;    extrn '__imp__QueryActCtxSettingsWWorker@??' as QueryActCtxSettingsWWorker:dword
;    extrn '__imp__QueryActCtxWWorker@??' as QueryActCtxWWorker:dword
;    extrn '__imp__QueryStateAtomValueInfo@??' as QueryStateAtomValueInfo:dword
;    extrn '__imp__QueryStateContainerItemInfo@??' as QueryStateContainerItemInfo:dword
;    extrn '__imp__QuirkGetData2Worker@??' as QuirkGetData2Worker:dword
;    extrn '__imp__QuirkGetDataWorker@??' as QuirkGetDataWorker:dword
;    extrn '__imp__QuirkIsEnabled2Worker@??' as QuirkIsEnabled2Worker:dword
;    extrn '__imp__QuirkIsEnabled3Worker@??' as QuirkIsEnabled3Worker:dword
;    extrn '__imp__QuirkIsEnabledForPackage2Worker@??' as QuirkIsEnabledForPackage2Worker:dword
;    extrn '__imp__QuirkIsEnabledForPackage3Worker@??' as QuirkIsEnabledForPackage3Worker:dword
;    extrn '__imp__QuirkIsEnabledForPackage4Worker@??' as QuirkIsEnabledForPackage4Worker:dword
;    extrn '__imp__QuirkIsEnabledForPackageWorker@??' as QuirkIsEnabledForPackageWorker:dword
;    extrn '__imp__QuirkIsEnabledForProcessWorker@??' as QuirkIsEnabledForProcessWorker:dword
;    extrn '__imp__QuirkIsEnabledWorker@??' as QuirkIsEnabledWorker:dword
;    extrn '__imp__RaiseInvalid16BitExeError@??' as RaiseInvalid16BitExeError:dword
;    extrn '__imp__ReadStateAtomValue@??' as ReadStateAtomValue:dword
;    extrn '__imp__ReadStateContainerValue@??' as ReadStateContainerValue:dword
;    extrn '__imp__RegisterConsoleIME@??' as RegisterConsoleIME:dword
;    extrn '__imp__RegisterConsoleOS2@??' as RegisterConsoleOS2:dword
;    extrn '__imp__RegisterConsoleVDM@??' as RegisterConsoleOS2:dword
;    extrn '__imp__RegisterStateChangeNotification@??' as RegisterStateChangeNotification:dword
;    extrn '__imp__RegisterStateLock@??' as RegisterStateLock:dword
;    extrn '__imp__RegisterWaitForInputIdle@??' as RegisterWaitForInputIdle:dword
;    extrn '__imp__RegisterWaitForSingleObjectEx@??' as RegisterWaitForSingleObjectEx:dword
;    extrn '__imp__RegisterWowBaseHandlers@??' as RegisterWowBaseHandlers:dword
;    extrn '__imp__RegisterWowExec@??' as RegisterWowExec:dword
;    extrn '__imp__RegKrnGetGlobalState@??' as RegKrnGetGlobalState:dword
;    extrn '__imp__RegKrnInitialize@??' as RegKrnInitialize:dword
;    extrn '__imp__ReleaseActCtxWorker@??' as ReleaseActCtxWorker:dword
;    extrn '__imp__ReleaseStateLock@??' as ReleaseStateLock:dword
;    extrn '__imp__RemoveLocalAlternateComputerNameA@??' as RemoveLocalAlternateComputerNameA:dword
;    extrn '__imp__RemoveLocalAlternateComputerNameW@??' as RemoveLocalAlternateComputerNameW:dword
;    extrn '__imp__ResetState@??' as ResetState:dword
;    extrn '__imp__SetClientDynamicTimeZoneInformation@??' as SetClientDynamicTimeZoneInformation:dword
;    extrn '__imp__SetClientTimeZoneInformation@??' as SetClientTimeZoneInformation:dword
;    extrn '__imp__SetComPlusPackageInstallStatus@??' as SetComPlusPackageInstallStatus:dword
;    extrn '__imp__SetComputerNameEx2W@??' as SetComputerNameEx2W:dword
;    extrn '__imp__SetConsoleCommandHistoryMode@??' as SetComputerNameEx2W:dword
;    extrn '__imp__SetConsoleCursorMode@??' as SetConsoleCursorMode:dword
;    extrn '__imp__SetConsoleInputExeNameA@??' as SetConsoleInputExeNameA:dword
;    extrn '__imp__SetConsoleInputExeNameW@??' as SetConsoleInputExeNameW:dword
;    extrn '__imp__SetConsoleKeyShortcuts@??' as SetConsoleKeyShortcuts:dword
;    extrn '__imp__SetConsoleLocalEUDC@??' as SetConsoleLocalEUDC:dword
;    extrn '__imp__SetConsoleMenuClose@??' as SetConsoleMenuClose:dword
;    extrn '__imp__SetCPGlobal@??' as SetCPGlobal:dword
;    extrn '__imp__SetRoamingLastObservedChangeTime@??' as SetRoamingLastObservedChangeTime:dword
;    extrn '__imp__SetStateVersion@??' as SetStateVersion:dword
;    extrn '__imp__SetThreadpoolTimerEx@??' as SetThreadpoolTimerEx:dword
;    extrn '__imp__SetVolumeMountPointWStub@??' as SetVolumeMountPointWStub:dword
;    extrn '__imp__SetWaitableTimerEx@??' as SetWaitableTimerEx:dword
;    extrn '__imp__SortCloseHandle@??' as SortCloseHandle:dword
;    extrn '__imp__SortGetHandle@??' as SortGetHandle:dword
;    extrn '__imp__SubscribeStateChangeNotification@??' as SubscribeStateChangeNotification:dword
;    extrn '__imp__TermsrvConvertSysRootToUserDir@??' as TermsrvConvertSysRootToUserDir:dword
;    extrn '__imp__TermsrvAppInstallMode@??' as TermsrvAppInstallMode:dword
;    extrn '__imp__TermsrvCreateRegEntry@??' as TermsrvCreateRegEntry:dword
;    extrn '__imp__TermsrvDeleteKey@??' as TermsrvDeleteKey:dword
;    extrn '__imp__TermsrvDeleteValue@??' as TermsrvDeleteValue:dword
;    extrn '__imp__TermsrvGetPreSetValue@??' as TermsrvGetPreSetValue:dword
;    extrn '__imp__TermsrvGetWindowsDirectoryA@??' as TermsrvGetWindowsDirectoryA:dword
;    extrn '__imp__TermsrvGetWindowsDirectoryW@??' as TermsrvGetWindowsDirectoryW:dword
;    extrn '__imp__TermsrvOpenRegEntry@??' as TermsrvOpenRegEntry:dword
;    extrn '__imp__TermsrvOpenUserClasses@??' as TermsrvOpenUserClasses:dword
;    extrn '__imp__TermsrvRestoreKey@??' as TermsrvRestoreKey:dword
;    extrn '__imp__TermsrvSetKeySecurity@??' as TermsrvSetKeySecurity:dword
;    extrn '__imp__TermsrvSetValueKey@??' as TermsrvSetValueKey:dword
;    extrn '__imp__TermsrvSyncUserIniFileExt@??' as TermsrvSyncUserIniFileExt:dword
;    extrn '__imp__UnmapViewOfFileEx@??' as UnmapViewOfFileEx:dword
;    extrn '__imp__UnregisterConsoleIME@??' as UnregisterConsoleIME:dword
;    extrn '__imp__UTRegister@??' as UTRegister:dword
;    extrn '__imp__UTUnRegister@??' as UTUnRegister:dword
;    extrn '__imp__UnregisterStateChangeNotification@??' as UnregisterStateChangeNotification:dword
;    extrn '__imp__UnregisterStateLock@??' as UnregisterStateLock:dword
;    extrn '__imp__UnsubscribeStateChangeNotification@??' as UnsubscribeStateChangeNotification:dword
;    extrn '__imp__ValidateLCType@??' as ValidateLCType:dword
;    extrn '__imp__ValidateLocale@??' as ValidateLocale:dword
;    extrn '__imp__VDMConsoleOperation@??' as VDMConsoleOperation:dword
;    extrn '__imp__VDMOperationStarted@??' as VDMOperationStarted:dword
;    extrn '__imp__VerifyConsoleIoHandle@??' as VerifyConsoleIoHandle:dword
;    extrn '__imp__WerGetFlagsWorker@??' as WerGetFlagsWorker:dword
;    extrn '__imp__WerRegisterFileWorker@??' as WerGetFlagsWorker:dword
;    extrn '__imp__WerRegisterMemoryBlockWorker@??' as WerRegisterMemoryBlockWorker:dword
;    extrn '__imp__WerRegisterRuntimeExceptionModuleWorker@??' as WerRegisterRuntimeExceptionModuleWorker:dword
;    extrn '__imp__WerSetFlagsWorker@??' as WerSetFlagsWorker:dword
;    extrn '__imp__WerUnregisterFileWorker@??' as WerUnregisterFileWorker:dword
;    extrn '__imp__WerUnregisterMemoryBlockWorker@??' as WerUnregisterMemoryBlockWorker:dword
;    extrn '__imp__WerUnregisterRuntimeExceptionModuleWorker@??' as WerUnregisterRuntimeExceptionModuleWorker:dword
;    extrn '__imp__WerpCleanupMessageMapping@??' as WerpCleanupMessageMapping:dword
;    extrn '__imp__WerpGetDebugger@??' as WerpGetDebugger:dword
;    extrn '__imp__WerpInitiateRemoteRecovery@??' as WerpInitiateRemoteRecovery:dword
;    extrn '__imp__WerpLaunchAeDebug@??' as WerpLaunchAeDebug:dword
;    extrn '__imp__WerpNotifyLoadStringResource@??' as WerpNotifyLoadStringResource:dword
;    extrn '__imp__WerpNotifyLoadStringResourceEx@??' as WerpNotifyLoadStringResourceEx:dword
;    extrn '__imp__WerpNotifyLoadStringResourceWorker@??' as WerpNotifyLoadStringResourceWorker:dword
;    extrn '__imp__WerpNotifyUseStringResource@??' as WerpNotifyUseStringResource:dword
;    extrn '__imp__WerpNotifyUseStringResourceWorker@??' as WerpNotifyUseStringResourceWorker:dword
;    extrn '__imp__WerpStringLookup@??' as WerpStringLookup:dword
;    extrn '__imp__WriteConsoleInputVDMA@??' as WriteConsoleInputVDMA:dword
;    extrn '__imp__WriteConsoleInputVDMW@??' as WriteConsoleInputVDMW:dword
;    extrn '__imp__WriteStateAtomValue@??' as WriteStateAtomValue:dword
;    extrn '__imp__WriteStateContainerValue@??' as WriteStateContainerValue:dword
;    extrn '__imp__ZombifyActCtxWorker@??' as ZombifyActCtxWorker:dword
;end if

;api GetConsoleCommandHistory,\
;    GetConsoleCommandHistoryLength,\
;    GetConsoleInputExeName,\
;    GetConsoleKeyboardLayoutName,\
;    RemoveLocalAlternateComputerName,\
;    SetConsoleInputExeName,\
;    TermsrvGetWindowsDirectory,\
;    WriteConsoleInputVDM

end if ;KERNEL32_INC
