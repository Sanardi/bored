;EasyCodeName=ECService,1
.Const

ECSRVNAME        TextEqu            <"ECService">

.Data?

.Data

hInst            HINSTANCE  NULL

ECServTable      SERVICE_TABLE_ENTRY <0>
ECServStat       SERVICE_STATUS      <0>

szServName       DB                   ECSRVNAME, 0
hServStat        DQ                   0
stopServiceEvent DQ                   0

szSwapFile       DB                   'C:\ECService.Txt', 0
hFile            DQ                   0
CRLF             DB                   0DH, 0AH
STOP_Flag        DD                   0
hThreadID        DQ                   0

.Code

start Proc FastCall Frame
    Invoke GetModuleHandle, NULL
    Mov hInst, Rax
    Invoke Main
    Invoke ExitProcess, 0
start EndP

Main Proc FastCall Private Frame
    Lea Rax, szServName
    Mov ECServTable.lpServiceName, Rax
    Lea Rax, ServMain
    Mov ECServTable.lpServiceProc, Rax
    Invoke StartServiceCtrlDispatcher, Addr ECServTable
    .If Rax == NULL
        Invoke GetLastError
        .If Rax == ERROR_FAILED_SERVICE_CONTROLLER_CONNECT
            Invoke MessageBox, NULL, TextAddr("NO Service Connect"), Addr szServName, MB_OK + MB_ICONERROR
        .ElseIf Rax == ERROR_INVALID_DATA
            Invoke MessageBox, NULL, TextAddr("Invalid Data"), Addr szServName, MB_OK + MB_ICONERROR
        .ElseIf Rax == ERROR_SERVICE_ALREADY_RUNNING
            Invoke MessageBox, NULL, TextAddr("Service Already Running"), Addr szServName, MB_OK + MB_ICONERROR
        .EndIf
    .Else
        Invoke MessageBox, NULL, TextAddr("Service OK"), Addr szServName, MB_OK + MB_ICONERROR
        ;
    .EndIf
    Ret
Main EndP

ServMain Proc FastCall Frame ArgCnt:QWord, Args:LPSTR
    Mov ArgCnt, Rcx
    Mov Args, Rdx

    Invoke RegisterServiceCtrlHandler, Addr szServName, Offset ServiceControlHandler
    .If Rax != NULL
        Mov hServStat, Rax
        Mov ECServStat.dwServiceType, SERVICE_WIN32_OWN_PROCESS
        Mov ECServStat.dwServiceSpecificExitCode, NO_ERROR
        Mov ECServStat.dwWin32ExitCode, NO_ERROR
        Mov ECServStat.dwWaitHint, 3000
        Mov ECServStat.dwCurrentState, SERVICE_START_PENDING
        Mov ECServStat.dwControlsAccepted, 0
        Mov ECServStat.dwCheckPoint, 1
        Invoke SetServiceStatus, hServStat, Addr ECServStat

        Invoke CreateEvent, NULL, TRUE, FALSE, NULL
        Mov stopServiceEvent, Rax

        Mov ECServStat.dwControlsAccepted, SERVICE_ACCEPT_STOP + SERVICE_ACCEPT_SHUTDOWN + SERVICE_ACCEPT_PAUSE_CONTINUE
        Mov ECServStat.dwCurrentState, SERVICE_RUNNING
        Mov ECServStat.dwWin32ExitCode, NO_ERROR
        Mov ECServStat.dwWaitHint, 0
        Mov ECServStat.dwCheckPoint, 1
        Invoke SetServiceStatus, hServStat, Addr ECServStat
        ;---
        Invoke ECServiceFunction
        ;---
        Invoke WaitForSingleObject, stopServiceEvent, INFINITE
        Invoke CloseHandle, stopServiceEvent
        Mov stopServiceEvent, 0

        Mov STOP_Flag, 0
        Invoke DeleteFile, Addr szSwapFile
    .Else
        Invoke MessageBox, NULL, TextAddr("RegisterServiceCtrlHandler Err."), Addr szServName, MB_OK + MB_ICONERROR
        ;
    .EndIf
    Ret
ServMain EndP

ServiceControlHandler Proc FastCall Frame CtrlCode:QWord
    Mov CtrlCode, Rcx

    .If CtrlCode == SERVICE_CONTROL_INTERROGATE
        ;
    .ElseIf CtrlCode == SERVICE_CONTROL_SHUTDOWN
L1:     Mov ECServStat.dwCurrentState, SERVICE_STOP_PENDING
        Invoke SetServiceStatus, hServStat, Addr ECServStat
        ;---PRE-STOP WORK---------
            Mov STOP_Flag, 1
        ;-------------------------
        Mov ECServStat.dwCurrentState, SERVICE_STOPPED
        Invoke SetServiceStatus, hServStat, Addr ECServStat
        Invoke SetEvent, Addr stopServiceEvent
    .ElseIf CtrlCode == SERVICE_CONTROL_STOP
        Jmp L1
    .ElseIf CtrlCode == SERVICE_CONTROL_PAUSE
        Mov ECServStat.dwCurrentState, SERVICE_PAUSE_PENDING
        Invoke SetServiceStatus, hServStat, Addr ECServStat
        ;---PRE-PAUSE WORK--------
             Invoke OpenThread, THREAD_SUSPEND_RESUME, NULL, hThreadID
             Invoke SuspendThread, Rax
        ;-------------------------
        Mov ECServStat.dwCurrentState, SERVICE_PAUSED
        Invoke SetServiceStatus, hServStat, Addr ECServStat
    .ElseIf CtrlCode == SERVICE_CONTROL_CONTINUE
        Mov ECServStat.dwCurrentState, SERVICE_CONTINUE_PENDING
        Invoke SetServiceStatus, hServStat, Addr ECServStat
        ;---PRE-CONTINUE WORK-----
             Invoke OpenThread, THREAD_SUSPEND_RESUME, NULL, hThreadID
             Invoke ResumeThread, Rax
        ;-------------------------
        Mov ECServStat.dwCurrentState, SERVICE_RUNNING
        Invoke SetServiceStatus, hServStat, Addr ECServStat
    .EndIf
    Ret
ServiceControlHandler EndP

ECServiceFunction Proc FastCall Frame Uses Rbx
    ;--------------
    ; Service code
    Local S_T:SYSTEMTIME
    Local Renglon[MAX_PATH]:CHAR

    Invoke GetCurrentThreadId
    Mov hThreadID, Rax

L1: Invoke GetLocalTime, Addr S_T
    Invoke GetTimeFormat, LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, Addr S_T, \
            NULL, Addr Renglon, MAX_PATH - 1
    ;--
    Invoke lstrcat, Addr Renglon, Addr CRLF
    Invoke CreateFile, Addr szSwapFile, GENERIC_WRITE + GENERIC_READ, FILE_SHARE_READ + \
            FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, NULL, NULL
            Mov hFile, Rax
            Invoke SetFilePointer, hFile, 0, NULL, FILE_BEGIN
            Invoke lstrlen, Addr Renglon
            Mov Rbx, Rax
            Push Rax
            Invoke WriteFile, hFile, Addr Renglon, Rbx, Rsp, NULL
            Pop Rax
    Invoke CloseHandle, hFile
    ;--
       Invoke Sleep, 1000
       .If STOP_Flag == 0
           Jmp L1
       .EndIf
    ;--------------
    Ret
ECServiceFunction EndP
