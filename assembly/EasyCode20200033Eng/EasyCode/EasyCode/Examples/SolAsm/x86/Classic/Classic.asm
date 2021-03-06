;EasyCodeName=Classic,1
IDC_BUTTON2		equ	1001

.data

szClassName		db	'EasyCodeSolarAsmTest', 0
szTitle			db	'SolAsm 32-bit resources test', 0
szTahoma		db	'Tahoma', 0
hInst			dd	0
hFont			dd	0

wc				WNDCLASSEX ?
msg				MSG        ?
icc				INITCOMMONCONTROLSEX ? ;Remove this line only if common controls are not going to be used

.code

proc Start
	invoke GetModuleHandle, NULL
	mov [hInst], eax
	invoke GetCommandLine
	invoke WinMain, [hInst], NULL, eax, SW_SHOWDEFAULT
	invoke ExitProcess, eax
endp

proc WinMain
	arg hInstance, hPrevInst, lpCmdLine, nCmdShow

	;==========================================================================
	;Remove this lines, and the corresponding 'comctl32.inc' and 'comctl32.lib'
	;files from project explorer, if you are not going to use common controls.
	mov edi, icc
	mov [edi+INITCOMMONCONTROLSEX.dwSize], size INITCOMMONCONTROLSEX
	mov [edi+INITCOMMONCONTROLSEX.dwICC], 03FFFH ;(ICC_WIN95_CLASSES+ICC_DATE_CLASSES+ICC_USEREX_CLASSES+ICC_COOL_CLASSES+ICC_INTERNET_CLASSES+ICC_PAGESCROLLER_CLASS+ICC_NATIVEFNTCTL_CLASS)
	invoke InitCommonControlsEx, icc
	;===========================================================================

	mov [wc.cbSize], size WNDCLASSEX
	mov [wc.style], CS_DBLCLKS
	mov eax, WindowProcedure
	mov [wc.lpfnWndProc], eax
	mov [wc.cbClsExtra], 0
	mov [wc.cbWndExtra], 0
	mov eax, [hInstance]
	mov [wc.hInstance], eax
	mov [wc.hIcon], NULL
	invoke LoadImage, NULL, OCR_NORMAL, IMAGE_CURSOR, 0, 0, (LR_DEFAULTSIZE+LR_LOADMAP3DCOLORS+LR_SHARED)
	mov [wc.hCursor], eax
	mov [wc.hbrBackground], (COLOR_BTNFACE+1)
	mov [wc.lpszMenuName], NULL
	mov eax, szClassName
	mov [wc.lpszClassName], eax
	mov [wc.hIconSm], NULL

	invoke RegisterClassEx, wc
	invoke CreateWindowEx, 0, szClassName, szTitle, (WS_OVERLAPPEDWINDOW+WS_VISIBLE), 200, 200, 600, 480, NULL, NULL, [hInst], NULL
	push eax
	invoke ShowWindow, eax, [nCmdShow]
	pop eax
	invoke UpdateWindow, eax

L2:	invoke GetMessage, msg, NULL, 0, 0
	cmp eax, 0
	jle L4
	invoke TranslateMessage, msg
	invoke DispatchMessage, msg
	jmp L2

L4:	invoke UnregisterClass, szClassName, [hInst]
	invoke DestroyCursor, [wc.hCursor]
	mov eax, [msg.wParam]
	ret
endp

proc WindowProcedure
	arg hWnd, uMsg, wParam, lParam

	.if [uMsg] == WM_CREATE
		;===================
		; Initalization code
		;===================
		invoke CreateFont, -12, 0, 0, 0, 400, 0, 0, 0, ANSI_CHARSET, 0, 0, 0, 0, szTahoma
		mov [hFont], eax
		invoke LoadMenuIndirect, IDR_MENU1
		invoke SetMenu, [hWnd], eax
		invoke CreateWindowEx, 0, <TextStr "BUTTON">, <TextStr "&Show dialog">, (WS_CHILD+WS_VISIBLE), 460, 380, 110, 26, [hWnd], IDC_BUTTON2, [hInst], NULL
		invoke SendMessage, eax, WM_SETFONT, [hFont], TRUE
		xor eax, eax
		jmp L2
    .elseif [uMsg] == WM_COMMAND
    	.if [lParam] == NULL
    		.if [wParam] == MENU_EXIT
    			invoke SendMessage, [hWnd], WM_CLOSE, 0, 0
    		.endif
    	.else
    		mov eax, [wParam]
	    	LoWord eax
	    	.if ax == IDC_BUTTON2
    			mov eax, [wParam]
	    		HiWord eax
	    		.if ax == BN_CLICKED
	    			invoke DialogBoxIndirectParam, [hInst], IDD_DIALOG1, [hWnd], Dlg_Proc, 0
	    			mov eax, TRUE
	    			jmp L2
	    		.endif
	    	.endif
	    .endif
    .elseif [uMsg] == WM_DESTROY
		;===========
		; Final code
		;===========
		invoke DeleteObject, [hFont]
		invoke PostQuitMessage, 0
		jmp L2
	.endif
	invoke DefWindowProc, [hWnd], [uMsg], [wParam], [lParam]
L2:	ret
endp

proc Dlg_Proc
	arg hWnd, uMsg, wParam, lParam

	.if [uMsg] == WM_INITDIALOG
		invoke GetDlgItem, [hWnd], IDC_BUTTON1
		invoke SendMessage, eax, WM_SETFONT, [hFont], TRUE
    .elseif [uMsg] == WM_COMMAND
    	mov eax, [wParam]
    	LoWord eax
    	.if ax == IDC_BUTTON1
    		mov eax, [wParam]
    		HiWord eax
    		.if ax == BN_CLICKED
    			invoke SendMessage, [hWnd], WM_CLOSE, 0, 0
    			mov eax, TRUE
    			jmp L2
    		.endif
    	.endif
	.elseif [uMsg] == WM_CLOSE
		invoke EndDialog, [hWnd], IDOK
		mov eax, TRUE
		jmp L2
	.endif
	xor eax, eax
L2:	ret
endp
