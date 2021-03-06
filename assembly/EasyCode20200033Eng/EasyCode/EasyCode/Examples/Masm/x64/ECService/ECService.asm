;EasyCodeName=ECService,1
.Const

ECSRVNAME        TextEqu      		<"ECService">

.Data?

.Data

hInst		     HINSTANCE	NULL

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

start Proc
	ECInvoke GetModuleHandle, NULL
	Mov hInst, Rax
	ECInvoke Main
	ECInvoke ExitProcess, 0
start EndP

Main Proc Private
	Lea Rax, szServName
	Mov ECServTable.lpServiceName, Rax
	Lea Rax, ServMain
	Mov ECServTable.lpServiceProc, Rax
	ECInvoke StartServiceCtrlDispatcher, Addr ECServTable
	Cmp Rax, NULL
	Je @F
	;=====================
	; Write your code here
	;=====================
	Jmp L2

@@:	ECInvoke GetLastError
	Cmp Rax, ERROR_FAILED_SERVICE_CONTROLLER_CONNECT
	Jne @F
	;
	        ECInvoke MessageBox, NULL, TextAddr("NO Service Connect"), Addr szServName, MB_OK + MB_ICONERROR
	        Jmp L2

@@:	Cmp Rax, ERROR_INVALID_DATA
	Jne @F
	;
            ECInvoke MessageBox, NULL, TextAddr("Invalid Data"), Addr szServName, MB_OK + MB_ICONERROR
	        Jmp L2

@@:	Cmp Rax, ERROR_SERVICE_ALREADY_RUNNING
	Jne L2
	        ECInvoke MessageBox, NULL, TextAddr("Service Already Running"), Addr szServName, MB_OK + MB_ICONERROR
	;---
L2:	Ret
Main EndP

ServMain Proc ArgCnt:QWord, Args:LPSTR
	Mov ArgCnt, Rcx
	Mov Args, Rdx

	ECInvoke RegisterServiceCtrlHandler, Addr szServName, Offset ServiceControlHandler
	Cmp Rax, NULL
	Je L2
	Mov hServStat, Rax
	Mov ECServStat.dwServiceType, SERVICE_WIN32_OWN_PROCESS
	Mov ECServStat.dwServiceSpecificExitCode, NO_ERROR
	Mov ECServStat.dwWin32ExitCode, NO_ERROR
	Mov ECServStat.dwWaitHint, 3000
	Mov ECServStat.dwCurrentState, SERVICE_START_PENDING
	Mov ECServStat.dwControlsAccepted, 0
	Mov ECServStat.dwCheckPoint, 1
	ECInvoke SetServiceStatus, hServStat, Addr ECServStat

	ECInvoke CreateEvent, NULL, TRUE, FALSE, NULL
	Mov stopServiceEvent, Rax

	Mov ECServStat.dwControlsAccepted, SERVICE_ACCEPT_STOP + SERVICE_ACCEPT_SHUTDOWN + SERVICE_ACCEPT_PAUSE_CONTINUE
	Mov ECServStat.dwCurrentState, SERVICE_RUNNING
	Mov ECServStat.dwWin32ExitCode, NO_ERROR
	Mov ECServStat.dwWaitHint, 0
	Mov ECServStat.dwCheckPoint, 1
	ECInvoke SetServiceStatus, hServStat, Addr ECServStat
	;---
	ECInvoke ECServiceFunction
	;---
	ECInvoke WaitForSingleObject, stopServiceEvent, INFINITE
	ECInvoke CloseHandle, stopServiceEvent
	Mov stopServiceEvent, 0

    Mov STOP_Flag, 0
    ECInvoke DeleteFile, Addr szSwapFile
L2:	Ret
ServMain EndP

ServiceControlHandler Proc CtrlCode:QWord
	Mov CtrlCode, Rcx

	Cmp CtrlCode, SERVICE_CONTROL_INTERROGATE
	Jne @F
	;---
	Jmp L4

@@:	Cmp CtrlCode, SERVICE_CONTROL_SHUTDOWN
	Jne @F
L1:	Mov ECServStat.dwCurrentState, SERVICE_STOP_PENDING
	ECInvoke SetServiceStatus, hServStat, Addr ECServStat
	;---PRE-STOP WORK---------
    Mov STOP_Flag, 1
	;-------------------------
	Mov ECServStat.dwCurrentState, SERVICE_STOPPED
	ECInvoke SetServiceStatus, hServStat, Addr ECServStat
	ECInvoke SetEvent, Addr stopServiceEvent
	Jmp L4

@@:	Cmp CtrlCode, SERVICE_CONTROL_STOP
	Je L1

@@:	Cmp CtrlCode, SERVICE_CONTROL_PAUSE
	Jne @F
	Mov ECServStat.dwCurrentState, SERVICE_PAUSE_PENDING
	ECInvoke SetServiceStatus, hServStat, Addr ECServStat
	;---PRE-PAUSE WORK--------
	ECInvoke OpenThread, THREAD_SUSPEND_RESUME, NULL, hThreadID
    ECInvoke SuspendThread, Rax
	;-------------------------
	Mov ECServStat.dwCurrentState, SERVICE_PAUSED
	ECInvoke SetServiceStatus, hServStat, Addr ECServStat
	Jmp L4

@@:	Cmp CtrlCode, SERVICE_CONTROL_CONTINUE
	Jne L4

	Mov ECServStat.dwCurrentState, SERVICE_CONTINUE_PENDING
	ECInvoke SetServiceStatus, hServStat, Addr ECServStat
	;---PRE-CONTINUE WORK-----
	ECInvoke OpenThread, THREAD_SUSPEND_RESUME, NULL, hThreadID
	ECInvoke ResumeThread, Rax
	;-------------------------
	Mov ECServStat.dwCurrentState, SERVICE_RUNNING
	ECInvoke SetServiceStatus, hServStat, Addr ECServStat
L4:	Ret
ServiceControlHandler EndP

ECServiceFunction Proc
	;--------------
	; Service code
	;--------------
	Local S_T:SYSTEMTIME
	Local Renglon[MAX_PATH]:CHAR

    ECInvoke GetCurrentThreadId
    Mov hThreadID, Rax

L2: ECInvoke GetLocalTime, Addr S_T
    ECInvoke GetTimeFormat, LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, Addr S_T, \
    						NULL, Addr Renglon, MAX_PATH - 1
    ;--
    ECInvoke lstrcat, Addr Renglon, Addr CRLF
    ECInvoke CreateFile, Addr szSwapFile, GENERIC_WRITE + GENERIC_READ, FILE_SHARE_READ + \
						FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, NULL, NULL
	Mov hFile, Rax
	ECInvoke SetFilePointer, hFile, 0, NULL, FILE_BEGIN
	ECInvoke lstrlen, Addr Renglon
	ECInvoke WriteFile, hFile, Addr Renglon, Rax, Rsp, NULL
    ECInvoke CloseHandle, hFile
    ;--
	ECInvoke Sleep, 1000
	Cmp STOP_Flag, 0
	Jz L2
	Ret
ECServiceFunction EndP
