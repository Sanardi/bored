;EasyCodeName=ECService,1
section '.data' data readable writeable

hInst				dq						NULL

ECServTable			SERVICE_TABLE_ENTRYA
ECServStat			SERVICE_STATUS

szServName			db						'ECService', 0
hServStat			dq						0
stopServiceEvent	dq						0

szSwapFile			db						'C:\ECService.Txt', 0
hFile				dq						0
CRLF				db						0DH, 0AH, 0
STOP_Flag			dq						0
hThreadID			dq						0

section '.text' code readable executable

proc start
	invoke GetModuleHandle, NULL
	mov [hInst], rax
	fastcall Main
	invoke ExitProcess, 0
endp

proc Main
	mov [ECServTable.lpServiceName], szServName
	mov [ECServTable.lpServiceProc], ServMain
	invoke StartServiceCtrlDispatcher, ECServTable
	.if rax = NULL
		invoke GetLastError
		.if rax = ERROR_FAILED_SERVICE_CONTROLLER_CONNECT
			invoke MessageBox, NULL, 'NO Service Connect', szServName, MB_OK + MB_ICONERROR
		.elseif rax = ERROR_INVALID_DATA
			invoke MessageBox, NULL, 'Invalid Data', szServName, MB_OK + MB_ICONERROR
		.elseif rax = ERROR_SERVICE_ALREADY_RUNNING
			invoke MessageBox, NULL, 'Service Already Running', szServName, MB_OK + MB_ICONERROR
		.endif
	.else
		invoke MessageBox, NULL, 'Service OK', szServName, MB_OK + MB_ICONERROR
	.endif
	ret
endp

proc ServMain ArgCnt:QWORD, Args:QWORD
	mov [ArgCnt], rcx
	mov [Args], rdx

	invoke RegisterServiceCtrlHandler, szServName, ServiceControlHandler
	.if rax <> NULL
		mov [hServStat], rax
		mov [ECServStat.dwServiceType], SERVICE_WIN32_OWN_PROCESS
		mov [ECServStat.dwServiceSpecificExitCode], NO_ERROR
		mov [ECServStat.dwWin32ExitCode], NO_ERROR
		mov [ECServStat.dwWaitHint], 3000
		mov [ECServStat.dwCurrentState], SERVICE_START_PENDING
		mov [ECServStat.dwControlsAccepted], 0
		mov [ECServStat.dwCheckPoint], 1
		invoke SetServiceStatus, [hServStat], ECServStat

		invoke CreateEvent, NULL, TRUE, FALSE, NULL
		mov [stopServiceEvent], rax

		mov [ECServStat.dwControlsAccepted], SERVICE_ACCEPT_STOP or SERVICE_ACCEPT_SHUTDOWN or SERVICE_ACCEPT_PAUSE_CONTINUE
		mov [ECServStat.dwCurrentState], SERVICE_RUNNING
		mov [ECServStat.dwWin32ExitCode], NO_ERROR
		mov [ECServStat.dwWaitHint], 0
		mov [ECServStat.dwCheckPoint], 1
		invoke SetServiceStatus, [hServStat], ECServStat
		;---
		fastcall ECServiceFunction
		;---
		invoke WaitForSingleObject, [stopServiceEvent], INFINITE
		invoke CloseHandle, [stopServiceEvent]
		mov [stopServiceEvent], 0

        mov [STOP_Flag], 0
        invoke DeleteFile, szSwapFile
	.else
		invoke MessageBox, NULL, 'RegisterServiceCtrlHandler Err.', szServName, MB_OK or MB_ICONERROR
	.endif
	ret
endp

proc ServiceControlHandler CtrlCode:QWORD
	mov [CtrlCode], rcx

	.if [CtrlCode] = SERVICE_CONTROL_INTERROGATE
		;
	.elseif [CtrlCode] = SERVICE_CONTROL_SHUTDOWN
L2:		mov [ECServStat.dwCurrentState], SERVICE_STOP_PENDING
		invoke SetServiceStatus, [hServStat], ECServStat
		;---PRE-STOP WORK---------
		mov [STOP_Flag], 1
		;-------------------------
		mov [ECServStat.dwCurrentState], SERVICE_STOPPED
		invoke SetServiceStatus, [hServStat], ECServStat
		invoke SetEvent, [stopServiceEvent]
	.elseif [CtrlCode] = SERVICE_CONTROL_STOP
		jmp L2
	.elseif [CtrlCode] = SERVICE_CONTROL_PAUSE
		mov [ECServStat.dwCurrentState], SERVICE_PAUSE_PENDING
		invoke SetServiceStatus, [hServStat], ECServStat
		;---PRE-PAUSE WORK--------
		invoke OpenThread, THREAD_SUSPEND_RESUME, NULL, [hThreadID]
		invoke SuspendThread, rax
		;-------------------------
		mov [ECServStat.dwCurrentState], SERVICE_PAUSED
		invoke SetServiceStatus, [hServStat], ECServStat
	.elseif [CtrlCode] = SERVICE_CONTROL_CONTINUE
		mov [ECServStat.dwCurrentState], SERVICE_CONTINUE_PENDING
		invoke SetServiceStatus, [hServStat], ECServStat
		;---PRE-CONTINUE WORK-----
		invoke OpenThread, THREAD_SUSPEND_RESUME, NULL, [hThreadID]
		invoke ResumeThread, rax
		;-------------------------
		mov [ECServStat.dwCurrentState], SERVICE_RUNNING
		invoke SetServiceStatus, [hServStat], ECServStat
	.endif
	ret
endp

proc ECServiceFunction
	;--------------
	; Service code
	;--------------
	local dwBytes:QWORD, S_T:SYSTEMTIME
	local Renglon[MAX_PATH]:BYTE

	invoke GetCurrentThreadId
	mov [hThreadID], rax

L4:	invoke GetLocalTime, addr S_T
	invoke GetTimeFormat, LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, addr S_T, \
						  NULL, addr Renglon, MAX_PATH - 1
	;--
	invoke lstrcat, addr Renglon, CRLF
	invoke CreateFile, szSwapFile, GENERIC_WRITE + GENERIC_READ, \
            		   FILE_SHARE_READ + FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, NULL, NULL
	mov [hFile], rax
	invoke SetFilePointer, [hFile], 0, NULL, FILE_BEGIN
	invoke lstrlen, addr Renglon
	mov r8, rax
	invoke WriteFile, [hFile], addr Renglon, r8, addr dwBytes, NULL
	invoke CloseHandle, [hFile]
	;--
	invoke Sleep, 1000
	.if [STOP_Flag] = 0
		jmp L4
	.endif
	;--------------
	ret
endp
