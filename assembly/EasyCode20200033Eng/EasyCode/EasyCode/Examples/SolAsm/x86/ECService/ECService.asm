;EasyCodeName=ECService,1
.data

hInst               dd                      NULL

ECServTable         SERVICE_TABLE_ENTRYA    ?
ECServStat          SERVICE_STATUS          ?
S_T                 SYSTEMTIME              ?

szServName          db                      'ECService', 0
hServStat           dd                      0
stopServiceEvent    dd                      0

szSwapFile          db                      'C:\ECService.Txt', 0
hFile               dd                      0
CRLF                db                      0DH, 0AH, 0
STOP_Flag           dd                      0
hThreadID           dd                      0

.code

Start:
    invoke GetModuleHandle, NULL
    mov [hInst], eax
    invoke Main
    invoke ExitProcess, 0

proc Main
    mov [ECServTable.lpServiceName], szServName
    mov [ECServTable.lpServiceProc], ServMain
    invoke StartServiceCtrlDispatcher, ECServTable
    .if eax == NULL
        invoke GetLastError
        .if eax == ERROR_FAILED_SERVICE_CONTROLLER_CONNECT
            invoke MessageBox, NULL, <TextStr "NO Service Connect">, szServName, <MB_OK+MB_ICONERROR>
        .elseif eax == ERROR_INVALID_DATA
            invoke MessageBox, NULL, <TextStr "Invalid Data">, szServName, <MB_OK+MB_ICONERROR>
        .elseif eax == ERROR_SERVICE_ALREADY_RUNNING
            invoke MessageBox, NULL, <TextStr "Service Already Running">, szServName, <MB_OK+MB_ICONERROR>
        .endif
    .else
        invoke MessageBox, NULL, <TextStr "Service OK">, szServName, <MB_OK+MB_ICONERROR>
        ;
    .endif
    ret
endp

proc ServMain
    arg ArgCnt, Args

    invoke RegisterServiceCtrlHandler, szServName, ServiceControlHandler
    .if eax != NULL
        mov [hServStat], eax
        mov [ECServStat.dwServiceType], SERVICE_WIN32_OWN_PROCESS
        mov [ECServStat.dwServiceSpecificExitCode], NO_ERROR
        mov [ECServStat.dwWin32ExitCode], NO_ERROR
        mov [ECServStat.dwWaitHint], 3000
        mov [ECServStat.dwCurrentState], SERVICE_START_PENDING
        mov [ECServStat.dwControlsAccepted], 0
        mov [ECServStat.dwCheckPoint], 1
        invoke SetServiceStatus, [hServStat], ECServStat

        invoke CreateEvent, NULL, TRUE, FALSE, NULL
        mov [stopServiceEvent], eax

        mov [ECServStat.dwControlsAccepted], <SERVICE_ACCEPT_STOP or SERVICE_ACCEPT_SHUTDOWN or SERVICE_ACCEPT_PAUSE_CONTINUE>
        mov [ECServStat.dwCurrentState], SERVICE_RUNNING
        mov [ECServStat.dwWin32ExitCode], NO_ERROR
        mov [ECServStat.dwWaitHint], 0
        mov [ECServStat.dwCheckPoint], 1
        invoke SetServiceStatus, [hServStat], ECServStat
        ;---
        invoke ECServiceFunction
        ;---
        invoke WaitForSingleObject, [stopServiceEvent], INFINITE
        invoke CloseHandle, [stopServiceEvent]
        mov [stopServiceEvent], 0

        mov [STOP_Flag], 0
        invoke DeleteFile, szSwapFile
    .else
        invoke MessageBox, NULL, <TextStr "RegisterServiceCtrlHandler Err.">, szServName, <MB_OK+MB_ICONERROR>
    .endif
    ret
endp

proc ServiceControlHandler
    arg CtrlCode

    .if [CtrlCode] == SERVICE_CONTROL_INTERROGATE
        ;
    .elseif [CtrlCode] == SERVICE_CONTROL_SHUTDOWN
L2:     mov [ECServStat.dwCurrentState], SERVICE_STOP_PENDING
        invoke SetServiceStatus, [hServStat], ECServStat
        ;---PRE-STOP WORK---------
        mov [STOP_Flag], 1
        ;-------------------------
        mov [ECServStat.dwCurrentState], SERVICE_STOPPED
        invoke SetServiceStatus, [hServStat], ECServStat
        invoke SetEvent, [stopServiceEvent]
    .elseif [CtrlCode] == SERVICE_CONTROL_STOP
        jmp L2
    .elseif [CtrlCode] == SERVICE_CONTROL_PAUSE
        mov [ECServStat.dwCurrentState], SERVICE_PAUSE_PENDING
        invoke SetServiceStatus, [hServStat], ECServStat
        ;---PRE-PAUSE WORK--------
        invoke OpenThread, THREAD_SUSPEND_RESUME, NULL, [hThreadID]
        invoke SuspendThread, eax
        ;-------------------------
        mov [ECServStat.dwCurrentState], SERVICE_PAUSED
        invoke SetServiceStatus, [hServStat], ECServStat
    .elseif [CtrlCode] == SERVICE_CONTROL_CONTINUE
        mov [ECServStat.dwCurrentState], SERVICE_CONTINUE_PENDING
        invoke SetServiceStatus, [hServStat], ECServStat
        ;---PRE-CONTINUE WORK-----
        invoke OpenThread, THREAD_SUSPEND_RESUME, NULL, [hThreadID]
        invoke ResumeThread, eax
        ;-------------------------
        mov [ECServStat.dwCurrentState], SERVICE_RUNNING
        invoke SetServiceStatus, [hServStat], ECServStat
    .endif
    ret
endp

proc ECServiceFunction
    local dwBytes, Renglon [60]

    invoke GetCurrentThreadId
    mov [hThreadID], eax

L2: invoke GetLocalTime, S_T
    invoke GetTimeFormat, LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, S_T, NULL, addr [Renglon], <MAX_PATH-1>
    ;--
    invoke lstrcat, addr [Renglon], CRLF
    invoke CreateFile, szSwapFile, <GENERIC_WRITE+GENERIC_READ>, <FILE_SHARE_READ+FILE_SHARE_WRITE>, NULL, OPEN_ALWAYS, NULL, NULL
    mov [hFile], eax
    invoke SetFilePointer, [hFile], 0, NULL, FILE_BEGIN
    invoke lstrlen, addr [Renglon]
    mov edx, eax
    invoke WriteFile, [hFile], addr [Renglon], edx, addr [dwBytes], NULL
    invoke CloseHandle, [hFile]
    ;--
    invoke Sleep, 1000
    mov eax, [STOP_Flag]
    or eax,eax
    jz L2
    ;--------------
    ret
endp
