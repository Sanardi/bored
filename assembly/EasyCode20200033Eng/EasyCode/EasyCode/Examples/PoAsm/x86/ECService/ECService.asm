;EasyCodeName=ECService,1
.Const

ECSRVNAME        TextEqu      		<"ECService">

IFNDEF WTS_CURRENT_SERVER_HANDLE
	WTS_CURRENT_SERVER_HANDLE		Equ  0
ENDIF

.Data?

.Data

hInst		     HINSTANCE	NULL

ECServTable      SERVICE_TABLE_ENTRY <0>
ECServTableEnd   SERVICE_TABLE_ENTRY <0>
ECServStat       SERVICE_STATUS      <0>

szServName       DB                   ECSRVNAME, 0
hServStat        DD                   0
stopServiceEvent DD                   0

szSwapFile       DB                   'C:\ECService.Txt', 0
hFile            DD                   0
CRLF             DB                   0DH, 0AH
STOP_Flag        DD                   0
hThreadID        DD                   0

.Code

start:
	Invoke GetModuleHandle, NULL
	Mov hInst, Eax
	Call Main
	Invoke ExitProcess, 0

Main Proc Private
	Mov ECServTable.lpServiceName, Offset szServName
	Mov ECServTable.lpServiceProc, Offset ServMain
	Invoke StartServiceCtrlDispatcher, Addr ECServTable
	.If Eax == NULL
		Invoke GetLastError
		.If Eax == ERROR_FAILED_SERVICE_CONTROLLER_CONNECT
            Invoke MessageBox, NULL, TextAddr("NO Service Connect"), Addr szServName, MB_OK + MB_ICONERROR
		.ElseIf Eax == ERROR_INVALID_DATA
            Invoke MessageBox, NULL, TextAddr("Invalid Data"), Addr szServName, MB_OK + MB_ICONERROR
		.ElseIf Eax == ERROR_SERVICE_ALREADY_RUNNING
            Invoke MessageBox, NULL, TextAddr("Service Already Running"), Addr szServName, MB_OK + MB_ICONERROR
		.EndIf
	.Else
        Invoke MessageBox, NULL, TextAddr("Service OK"), Addr szServName, MB_OK + MB_ICONERROR
		;
	.EndIf
	Ret
Main EndP

ServMain Proc ArgCnt:DWord, Args:LPSTR
	Invoke RegisterServiceCtrlHandler, Addr szServName, Offset ServiceControlHandler
	.If Eax != NULL
		Mov hServStat, Eax
		Mov ECServStat.dwServiceType, SERVICE_WIN32_OWN_PROCESS
		Mov ECServStat.dwServiceSpecificExitCode, NO_ERROR
		Mov ECServStat.dwWin32ExitCode, NO_ERROR
		Mov ECServStat.dwWaitHint, 3000
		Mov ECServStat.dwCurrentState, SERVICE_START_PENDING
		Mov ECServStat.dwControlsAccepted, 0
		Mov ECServStat.dwCheckPoint, 1
		Invoke SetServiceStatus, hServStat, Addr ECServStat

		Invoke CreateEvent, NULL, TRUE, FALSE, NULL
		Mov stopServiceEvent, Eax

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

ServiceControlHandler Proc CtrlCode:DWord
	.If CtrlCode == SERVICE_CONTROL_INTERROGATE
		;
	.ElseIf CtrlCode == SERVICE_CONTROL_SHUTDOWN
L1:		Mov ECServStat.dwCurrentState, SERVICE_STOP_PENDING
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
             Invoke SuspendThread, Eax
		;-------------------------
		Mov ECServStat.dwCurrentState, SERVICE_PAUSED
		Invoke SetServiceStatus, hServStat, Addr ECServStat
	.ElseIf CtrlCode == SERVICE_CONTROL_CONTINUE
		Mov ECServStat.dwCurrentState, SERVICE_CONTINUE_PENDING
		Invoke SetServiceStatus, hServStat, Addr ECServStat
		;---PRE-CONTINUE WORK-----
             Invoke OpenThread, THREAD_SUSPEND_RESUME, NULL, hThreadID
             Invoke ResumeThread, Eax
		;-------------------------
		Mov ECServStat.dwCurrentState, SERVICE_RUNNING
		Invoke SetServiceStatus, hServStat, Addr ECServStat
	.EndIf
	Ret
ServiceControlHandler EndP

ECServiceFunction Proc
	;--------------
	; Service code
    Local S_T:SYSTEMTIME
    Local Renglon[MAX_PATH]:CHAR

    Invoke GetCurrentThreadId
    Mov hThreadID, Eax

L1: Invoke GetLocalTime, Addr S_T
    Invoke GetTimeFormat, LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, Addr S_T, \
            NULL, Addr Renglon, MAX_PATH - 1
    ;--
    Invoke lstrcat, Addr Renglon, Addr CRLF
    Invoke CreateFile, Addr szSwapFile, GENERIC_WRITE + GENERIC_READ, FILE_SHARE_READ + \
            FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, NULL, NULL
            Mov hFile, Eax
            Invoke SetFilePointer, hFile, 0, NULL, FILE_BEGIN
            Invoke lstrlen, Addr Renglon
            Mov Edx, Eax
            Push Eax
            Invoke WriteFile, hFile, Addr Renglon, Edx, Esp, NULL
            Pop Eax
    Invoke CloseHandle, hFile
    ;--
       Invoke Sleep, 1000
       .If STOP_Flag == 0
       	   Jmp L1
       .EndIf
	;--------------
	Ret
ECServiceFunction EndP

End start
