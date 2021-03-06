;EasyCodeName=ECService,1
section '.data' data readable writeable

hInst		     	dd						NULL

ECServTable        	SERVICE_TABLE_ENTRYA
ECServStat         	SERVICE_STATUS

szServName       	db						'ECService', 0
hServStat        	dd						0
stopServiceEvent	dd						0

szSwapFile			db						'C:\ECService.Txt', 0
hFile				dd						0
CRLF				db						0DH, 0AH, 0
STOP_Flag			dd						0
hThreadID			dd						0

section '.text' code readable executable

start:
	invoke GetModuleHandle, NULL
	mov [hInst], eax
	stdcall Main
	invoke ExitProcess, 0

proc Main
	mov [ECServTable.lpServiceName], szServName
	mov [ECServTable.lpServiceProc], ServMain
	invoke StartServiceCtrlDispatcher, ECServTable
	.if eax = NULL
		invoke GetLastError
		.if eax = ERROR_FAILED_SERVICE_CONTROLLER_CONNECT
            invoke MessageBox, NULL, 'NO Service Connect', szServName, MB_OK + MB_ICONERROR
		.elseif eax = ERROR_INVALID_DATA
            invoke MessageBox, NULL, 'Invalid Data', szServName, MB_OK + MB_ICONERROR
		.elseif eax = ERROR_SERVICE_ALREADY_RUNNING
            invoke MessageBox, NULL, 'Service Already Running', szServName, MB_OK + MB_ICONERROR
		.endif
	.else
        invoke MessageBox, NULL, 'Service OK', szServName, MB_OK + MB_ICONERROR
		;
	.endif
	ret
endp

proc ServMain ArgCnt:DWORD, Args:DWORD
	invoke RegisterServiceCtrlHandler, szServName, ServiceControlHandler
	.if eax <> NULL
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

		mov [ECServStat.dwControlsAccepted], SERVICE_ACCEPT_STOP or SERVICE_ACCEPT_SHUTDOWN or SERVICE_ACCEPT_PAUSE_CONTINUE
		mov [ECServStat.dwCurrentState], SERVICE_RUNNING
		mov [ECServStat.dwWin32ExitCode], NO_ERROR
		mov [ECServStat.dwWaitHint], 0
		mov [ECServStat.dwCheckPoint], 1
		invoke SetServiceStatus, [hServStat], ECServStat
		;---
		stdcall ECServiceFunction
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

proc ServiceControlHandler CtrlCode:DWORD
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
		invoke SuspendThread, eax
		;-------------------------
		mov [ECServStat.dwCurrentState], SERVICE_PAUSED
		invoke SetServiceStatus, [hServStat], ECServStat
	.elseif [CtrlCode] = SERVICE_CONTROL_CONTINUE
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
	;--------------
	; Service code
	;--------------
	local dwBytes:DWORD, S_T:SYSTEMTIME
	local Renglon[MAX_PATH]:BYTE

	invoke GetCurrentThreadId
	mov [hThreadID], eax

L4:	invoke GetLocalTime, addr S_T
	invoke GetTimeFormat, LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, addr S_T, \
						  NULL, addr Renglon, MAX_PATH - 1
	;--
	invoke lstrcat, addr Renglon, CRLF
	invoke CreateFile, szSwapFile, GENERIC_WRITE + GENERIC_READ, \
            		   FILE_SHARE_READ + FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, NULL, NULL
	mov [hFile], eax
	invoke SetFilePointer, [hFile], 0, NULL, FILE_BEGIN
	invoke lstrlen, addr Renglon
	mov edx, eax
;	mov [dwBytes], 0
	push eax
	invoke WriteFile, [hFile], addr Renglon, edx, esp, NULL
	pop eax
	invoke CloseHandle, [hFile]
	;--
	invoke Sleep, 1000
	.if [STOP_Flag] = 0
		jmp L4
	.endif
	;--------------
	ret
endp
