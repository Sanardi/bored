;EasyCodeName=ECService,1
.Const

#IFNDEF WTS_CURRENT_SERVER_HANDLE
	#Define WTS_CURRENT_SERVER_HANDLE	0
#ENDIF

.Data

hInst				DD			NULL

ECServTable			SERVICE_TABLE_ENTRY
ECServTableEnd		SERVICE_TABLE_ENTRY
ECServStat			SERVICE_STATUS

szServName		 	DB			'ECService', 0
hServStat		 	DD			0
stopServiceEvent	DD			0

szSwapFile          DB          'C:\ECService.Txt', 0
hFile               DD          0
CRLF                DB          0DH, 0AH
STOP_Flag           DD          0
hThreadID           DD          0

.Code

start:
	Invoke GetModuleHandle, NULL
	Mov [hInst], Eax
	Call Main
	Invoke ExitProcess, 0

Main Frame
	Mov D[ECServTable.lpServiceName], Offset szServName
	Mov D[ECServTable.lpServiceProc], Offset ServMain
	Invoke StartServiceCtrlDispatcher, Addr ECServTable
	Cmp Eax, NULL
	Jne > L2
	Invoke GetLastError
	Cmp Eax, ERROR_FAILED_SERVICE_CONTROLLER_CONNECT
	Jne >
	;Failed service controller
	        Invoke MessageBox, NULL, 'NO Service Connect', Addr szServName, MB_OK + MB_ICONERROR
	Jmp > L2

:	Cmp Eax, ERROR_INVALID_DATA
	Jne >
	;Invalid data
            Invoke MessageBox, NULL, 'Invalid Data', Addr szServName, MB_OK + MB_ICONERROR
	Jmp > L2

:	Cmp Eax, ERROR_SERVICE_ALREADY_RUNNING
	Jne > L2
	;Service already running
            Invoke MessageBox, NULL, 'Service Already Running', Addr szServName, MB_OK + MB_ICONERROR
L2:	Ret
EndF

ServMain Frame ArgCnt, Args
	Invoke RegisterServiceCtrlHandler, Addr szServName, Offset ServiceControlHandler
	Cmp Eax, NULL
	Je >> L2

	Mov [hServStat], Eax
	Mov D[ECServStat.dwServiceType], SERVICE_WIN32_OWN_PROCESS
	Mov D[ECServStat.dwServiceSpecificExitCode], NO_ERROR
	Mov D[ECServStat.dwWin32ExitCode], NO_ERROR
	Mov D[ECServStat.dwWaitHint], 3000
	Mov D[ECServStat.dwCurrentState], SERVICE_START_PENDING
	Mov D[ECServStat.dwControlsAccepted], 0
	Mov D[ECServStat.dwCheckPoint], 1
	Invoke SetServiceStatus, [hServStat], Addr ECServStat

	Invoke CreateEvent, NULL, TRUE, FALSE, NULL
	Mov D[stopServiceEvent], Eax

	Mov D[ECServStat.dwControlsAccepted], (SERVICE_ACCEPT_STOP | SERVICE_ACCEPT_SHUTDOWN | SERVICE_ACCEPT_PAUSE_CONTINUE)
	Mov D[ECServStat.dwCurrentState], SERVICE_RUNNING
	Mov D[ECServStat.dwWin32ExitCode], NO_ERROR
	Mov D[ECServStat.dwWaitHint], 0
	Mov D[ECServStat.dwCheckPoint], 1
	Invoke SetServiceStatus, [hServStat], Addr ECServStat
	;---
	Invoke ECServiceFunction
	;---
	Invoke WaitForSingleObject, [stopServiceEvent], INFINITE
	Invoke CloseHandle, [stopServiceEvent]
	Mov D[stopServiceEvent], 0

        Mov D[STOP_Flag], 0
        Invoke DeleteFile, Addr szSwapFile
L2:	Ret
EndF

ServiceControlHandler Frame CtrlCode
	Cmp D[CtrlCode], SERVICE_CONTROL_INTERROGATE
	Jne >
	;
	Jmp >> L4

:	Cmp D[CtrlCode], SERVICE_CONTROL_SHUTDOWN
	Jne >
L2:	Mov D[ECServStat.dwCurrentState], SERVICE_STOP_PENDING
	Jne >
	Invoke SetServiceStatus, [hServStat], Addr ECServStat
	;---PRE-STOP WORK---------
            Mov D[STOP_Flag], 1
	;-------------------------
	Mov D[ECServStat.dwCurrentState], SERVICE_STOPPED
	Invoke SetServiceStatus, [hServStat], Addr ECServStat
	Invoke SetEvent, Addr stopServiceEvent
	Jmp >> L4

:	Cmp D[CtrlCode], SERVICE_CONTROL_STOP
	Je < L2

:	Cmp D[CtrlCode], SERVICE_CONTROL_PAUSE
	Jne >
	Mov D[ECServStat.dwCurrentState], SERVICE_PAUSE_PENDING
	Invoke SetServiceStatus, [hServStat], Addr ECServStat
	;---PRE-PAUSE WORK--------
             Invoke OpenThread, THREAD_SUSPEND_RESUME, NULL, [hThreadID]
             Invoke SuspendThread, Eax
	;-------------------------
	Mov D[ECServStat.dwCurrentState], SERVICE_PAUSED
	Invoke SetServiceStatus, [hServStat], Addr ECServStat
	Jmp > L4

:	Cmp D[CtrlCode], SERVICE_CONTROL_CONTINUE
	Jne > L4

	Mov D[ECServStat.dwCurrentState], SERVICE_CONTINUE_PENDING
	Invoke SetServiceStatus, [hServStat], Addr ECServStat
	;---PRE-CONTINUE WORK-----
             Invoke OpenThread, THREAD_SUSPEND_RESUME, NULL, [hThreadID]
             Invoke ResumeThread, Eax
	;-------------------------
	Mov D[ECServStat.dwCurrentState], SERVICE_RUNNING
	Invoke SetServiceStatus, [hServStat], Addr ECServStat

L4:	Ret
EndF

ECServiceFunction Frame
	;--------------
	; Service code
	;--------------
	    Uses Edx
	    Local S_T:SYSTEMTIME
        Local Renglon [MAX_PATH]:B

    Invoke GetCurrentThreadId
    Mov [hThreadID], Eax

L1: Invoke GetLocalTime, Addr S_T
    Invoke GetTimeFormat, LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, Addr S_T, \
            NULL, Addr Renglon, MAX_PATH - 1
    ;--
    Invoke lstrcat, Addr Renglon, Addr CRLF
    Invoke CreateFile, Addr szSwapFile, GENERIC_WRITE + GENERIC_READ, FILE_SHARE_READ + \
            FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, NULL, NULL
            Mov [hFile], Eax
            Invoke SetFilePointer, [hFile], 0, NULL, FILE_BEGIN
            Invoke lstrlen, Addr Renglon
            Mov Edx, Eax
            Push Eax
            Invoke WriteFile, [hFile], Addr Renglon, Edx, Esp, NULL
            Pop Eax
    Invoke CloseHandle, [hFile]
    ;--
       Invoke Sleep, 1000
       Cmp D[STOP_Flag], 0
       Jz << L1

	Ret
EndF
