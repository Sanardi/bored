;EasyCodeName=ECService,1
.data

hInst				dq						NULL
Renglon				rb						MAX_PATH

ECServTable			SERVICE_TABLE_ENTRYA	?
ECServStat			SERVICE_STATUS			?
S_T					SYSTEMTIME				?

szServName			db						'ECService', 0
hServStat			dq						0
stopServiceEvent	dq						0

szSwapFile			db						'C:\ECService.Txt', 0
hFile				dq						0
CRLF				db						0DH, 0AH, 0
STOP_Flag			dd						0
hThreadID			dq						0

.code

proc Start win64
	invoke GetModuleHandle, NULL
	mov [hInst], rax
	invoke Main
	invoke ExitProcess, 0
	ret
endp

proc Main win64 uses rdi
	mov rdi, ECServTable
    mov rax, szServName
	mov [rdi+SERVICE_TABLE_ENTRYA.lpServiceName], rax
    mov rax, ServMain
    mov [rdi+SERVICE_TABLE_ENTRYA.lpServiceProc], rax
	invoke StartServiceCtrlDispatcher, ECServTable
	.if rax == NULL
		invoke GetLastError
        .if rax == ERROR_FAILED_SERVICE_CONTROLLER_CONNECT
            invoke MessageBox, NULL, <TextStr "NO Service Connect">, szServName, <MB_OK+MB_ICONERROR>
        .elseif rax == ERROR_INVALID_DATA
            invoke MessageBox, NULL, <TextStr "Invalid Data">, szServName, <MB_OK+MB_ICONERROR>
        .elseif rax == ERROR_SERVICE_ALREADY_RUNNING
            invoke MessageBox, NULL, <TextStr "Service Already Running">, szServName, <MB_OK+MB_ICONERROR>
        .endif
	.else
        invoke MessageBox, NULL, <TextStr "Service OK">, szServName, <MB_OK+MB_ICONERROR>
	.endif
	ret
endp

proc ServMain win64 uses rdi
	arg ArgCnt, Args

	mov [ArgCnt], rcx
	mov [Args], rdx

	invoke RegisterServiceCtrlHandler, szServName, ServiceControlHandler
	.if rax != NULL
		mov [hServStat], rax
		mov rdi, ECServStat
		mov [rdi+SERVICE_STATUS.dwServiceType], SERVICE_WIN32_OWN_PROCESS
		mov [rdi+SERVICE_STATUS.dwServiceSpecificExitCode], NO_ERROR
		mov [rdi+SERVICE_STATUS.dwWin32ExitCode], NO_ERROR
		mov [rdi+SERVICE_STATUS.dwWaitHint], 3000
		mov [rdi+SERVICE_STATUS.dwCurrentState], SERVICE_START_PENDING
		mov [rdi+SERVICE_STATUS.dwControlsAccepted], 0
		mov [rdi+SERVICE_STATUS.dwCheckPoint], 1
		invoke SetServiceStatus, [hServStat], ECServStat

		invoke CreateEvent, NULL, TRUE, FALSE, NULL
		mov [stopServiceEvent], rax

		mov [rdi+SERVICE_STATUS.dwControlsAccepted], <SERVICE_ACCEPT_STOP or SERVICE_ACCEPT_SHUTDOWN or SERVICE_ACCEPT_PAUSE_CONTINUE>
		mov [rdi+SERVICE_STATUS.dwCurrentState], SERVICE_RUNNING
		mov [rdi+SERVICE_STATUS.dwWin32ExitCode], NO_ERROR
		mov [rdi+SERVICE_STATUS.dwWaitHint], 0
		mov [rdi+SERVICE_STATUS.dwCheckPoint], 1
		invoke SetServiceStatus, [hServStat], ECServStat
		;---
		invoke ECServiceFunction
		;---
		invoke WaitForSingleObject, [stopServiceEvent], INFINITE
		invoke CloseHandle, [stopServiceEvent]
		mov [stopServiceEvent], 0

		xor eax, eax
        mov [STOP_Flag], eax
        invoke DeleteFile, szSwapFile
	.else
		invoke MessageBox, NULL, <TextStr "RegisterServiceCtrlHandler Err.">, szServName, <MB_OK+MB_ICONERROR>
	.endif
	ret
endp

proc ServiceControlHandler win64 uses rdi
	arg CtrlCode
	mov [CtrlCode], rcx

	mov rdi, ECServStat
	.if [CtrlCode] == SERVICE_CONTROL_INTERROGATE
		;
	.elseif [CtrlCode] == SERVICE_CONTROL_SHUTDOWN
L2:		mov [rdi+SERVICE_STATUS.dwCurrentState], SERVICE_STOP_PENDING
		invoke SetServiceStatus, [hServStat], ECServStat
		;---PRE-STOP WORK---------
		mov eax, 1
		mov [STOP_Flag], eax
		;-------------------------
		mov [rdi+SERVICE_STATUS.dwCurrentState], SERVICE_STOPPED
		invoke SetServiceStatus, [hServStat], ECServStat
		invoke SetEvent, [stopServiceEvent]
	.elseif [CtrlCode] == SERVICE_CONTROL_STOP
		jmp L2
	.elseif [CtrlCode] == SERVICE_CONTROL_PAUSE
		mov [rdi+SERVICE_STATUS.dwCurrentState], SERVICE_PAUSE_PENDING
		invoke SetServiceStatus, [hServStat], ECServStat
		;---PRE-PAUSE WORK--------
		invoke OpenThread, THREAD_SUSPEND_RESUME, NULL, [hThreadID]
		invoke SuspendThread, rax
		;-------------------------
		mov [rdi+SERVICE_STATUS.dwCurrentState], SERVICE_PAUSED
		invoke SetServiceStatus, [hServStat], ECServStat
	.elseif [CtrlCode] == SERVICE_CONTROL_CONTINUE
		mov [rdi+SERVICE_STATUS.dwCurrentState], SERVICE_CONTINUE_PENDING
		invoke SetServiceStatus, [hServStat], ECServStat
		;---PRE-CONTINUE WORK-----
		invoke OpenThread, THREAD_SUSPEND_RESUME, NULL, [hThreadID]
		invoke ResumeThread, rax
		;-------------------------
		mov [rdi+SERVICE_STATUS.dwCurrentState], SERVICE_RUNNING
		invoke SetServiceStatus, [hServStat], ECServStat
	.endif
	ret
endp

proc ECServiceFunction win64
    local dwBytes

	invoke GetCurrentThreadId
	mov [hThreadID], rax

L2:	invoke GetLocalTime, S_T
	invoke GetTimeFormat, LOCALE_USER_DEFAULT, LOCALE_NOUSEROVERRIDE, S_T, NULL, Renglon, <MAX_PATH-1>
	;--
	invoke lstrcat, Renglon, CRLF
	invoke CreateFile, szSwapFile, GENERIC_WRITE+GENERIC_READ, FILE_SHARE_READ+FILE_SHARE_WRITE, NULL, OPEN_ALWAYS, NULL, NULL
	mov [hFile], rax
	invoke SetFilePointer, [hFile], 0, NULL, FILE_BEGIN
	invoke lstrlen, Renglon
	mov r8, rax
	invoke WriteFile, [hFile], Renglon, r8, addr [dwBytes], NULL
	invoke CloseHandle, [hFile]
	;--
	invoke Sleep, 1000
	mov eax, [STOP_Flag]
	or eax,eax
	jz L2
	;--------------
	ret
endp
