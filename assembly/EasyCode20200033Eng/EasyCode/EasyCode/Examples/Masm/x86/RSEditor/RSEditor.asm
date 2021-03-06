;EasyCodeName=RSEditor,1
.Const

.Data?

RSrect					RECT		<?>
RSsci					SCROLLINFO	<?>


.Data

RSszEditorParentClass	DB			'RSEditorParentClass', 0
RSszEditorChildClass	DB			'RSEditorChildClass', 0
RSszScrollBar			DB			'ScrollBar', 0
RSszStatic				DB			'Static', 0
RSEditorCtrl			DB			'RS Editor', 0

RSszChar				DB			4 Dup(0)

RSbMargin				BOOL		FALSE
RSbAppUnicode			BOOL		FALSE
RSbSelBarDblClk			BOOL		FALSE
RSlHScrollHeight		LONG		0
RSlVScrollWidth			LONG		0
RSlLineFormat			LONG		RSC_CR_LF
RSdwPageSize			DWord		4096
RShInst					HINSTANCE	NULL
RShIBeam				HCURSOR		NULL
RShArrow				HCURSOR		NULL
RShRArrow				HCURSOR		NULL
RShBookmark				HICON		NULL
RShSizeNS				HCURSOR		NULL

lpUCaseTableA			LPLONG		NULL
lpUCaseTableW			LPLONG		NULL

RSptCaret				POINTL		<0>
RSszText				SIZEL		<0>

RSFont					RSSEDITFONT <0>


.Code

DllEntryPoint Proc Uses Ebx Edi Esi hInstance:HINSTANCE, dwReason:DWord, lpvReserved:LPVOID
	Local wc:WNDCLASSEX, sysinfo:SYSTEM_INFO

	.If dwReason == DLL_PROCESS_ATTACH
		Mov Eax, hInstance
		Mov RShInst, Eax
		Mov wc.hInstance, Eax
		Mov wc.cbSize, SizeOf WNDCLASSEX
		Mov wc.style, CS_GLOBALCLASS
		Mov wc.lpfnWndProc, Offset RSEditorParentProc
		Mov wc.cbClsExtra, 0
		Mov wc.cbWndExtra, 4
		Mov wc.hIcon, NULL
		Mov wc.hIconSm, NULL
		Mov wc.hCursor, NULL
		Mov wc.hbrBackground, NULL
		Mov wc.lpszMenuName, NULL
		Mov wc.lpszClassName, Offset RSszEditorParentClass
		Mov wc.hIconSm, NULL
		Invoke RegisterClassEx, Addr wc

		Mov wc.style, CS_DBLCLKS
		Mov wc.lpfnWndProc, Offset RSEditorChildProc
		Mov wc.lpszClassName, Offset RSszEditorChildClass
		Invoke RegisterClassEx, Addr wc

		Invoke GetSystemInfo, Addr sysinfo
		Mov Eax, sysinfo.dwPageSize
		Mov RSdwPageSize, Eax

		Invoke LoadImage, 0, OCR_IBEAM, IMAGE_CURSOR, 0, 0, (LR_DEFAULTSIZE Or LR_LOADMAP3DCOLORS Or LR_SHARED)
		Mov RShIBeam, Eax
		Invoke LoadImage, 0, OCR_NORMAL, IMAGE_CURSOR, 0, 0, (LR_DEFAULTSIZE Or LR_LOADMAP3DCOLORS Or LR_SHARED)
		Mov RShArrow, Eax
		Invoke LoadImage, 0, OCR_SIZENS, IMAGE_CURSOR, 0, 0, (LR_DEFAULTSIZE Or LR_LOADMAP3DCOLORS Or LR_SHARED)
		Mov RShSizeNS, Eax
		Invoke LoadImage, RShInst, IDI_BOOKMARK, IMAGE_ICON, 0, 0, (LR_DEFAULTSIZE Or LR_LOADMAP3DCOLORS Or LR_SHARED)
		Mov RShBookmark, Eax
		Invoke LoadImage, RShInst, IDC_RARROW, IMAGE_CURSOR, 0, 0, (LR_DEFAULTSIZE Or LR_LOADMAP3DCOLORS Or LR_SHARED)
		Mov RShRArrow, Eax
	.ElseIf dwReason == DLL_PROCESS_DETACH
		Invoke DestroyIcon, RShBookmark
		Invoke DestroyCursor, RShIBeam
		Invoke DestroyCursor, RShArrow
		Invoke DestroyCursor, RShSizeNS
		Invoke DestroyCursor, RShRArrow
		Invoke UnregisterClass, Offset RSszEditorParentClass, RShInst
		Invoke UnregisterClass, Offset RSszEditorChildClass, RShInst
	.ElseIf dwReason == DLL_THREAD_ATTACH

	.ElseIf dwReason == DLL_THREAD_DETACH

	.EndIf
	Return TRUE
DllEntryPoint EndP

RSCreateEditor Proc Uses Ecx Edx hWndParent:HWND, dwStyle:DWord, dwExStyle:DWord, lLeft:LONG, lTop:LONG, lWidth:LONG, lHeight:LONG, lCtrlID:LONG, bAppUnicode:BOOL
	Local lParam:LONG

	Mov Eax, bAppUnicode
	Mov RSbAppUnicode, Eax
	Mov Eax, dwStyle
	And Eax, (WS_HSCROLL Or WS_VSCROLL)
	Mov lParam, Eax
	.If (dwStyle & RSS_SPLIT)
		Or lParam, RSS_SPLIT
	.EndIf
	And dwStyle, (Not (WS_HSCROLL Or WS_VSCROLL))
	Or dwStyle, WS_CHILD
	Invoke CreateWindowEx, dwExStyle, Addr RSszEditorParentClass, NULL, dwStyle, lLeft, lTop, lWidth, lHeight, hWndParent, lCtrlID, RShInst, Addr lParam
	Ret
RSCreateEditor EndP

RSEditorParentProc Proc Uses Ebx Edi Esi hWnd:HWND, uMsg:UINT, wParam:WPARAM, lParam:LPARAM
	Local dwTemp:DWord, rc:RECT

	Invoke GetWindowLong, hWnd, GWL_EDITORDATA
	Mov Ebx, Eax
	.If uMsg == WM_CREATE
		Invoke VirtualAlloc, 0, RSdwPageSize, MEM_COMMIT, PAGE_READWRITE
		Mov Ebx, Eax
		Invoke SetWindowLong, hWnd, GWL_EDITORDATA, Eax
		Mov Eax, SizeOf EDITPARENT
		Shr Eax, 2
		Add Eax, 2
		Shl Eax, 2
		Add Eax, Ebx
		Mov [Ebx].EDITPARENT.lpszBuffer, Eax
		Mov Eax, hWnd
		Mov [Ebx].EDITPARENT.hWnd, Eax
		Invoke GetParent, Eax
		Mov [Ebx].EDITPARENT.hWndParent, Eax
		Lea Eax, RSIsCharAlphaProc
		Mov [Ebx].EDITPARENT.RSIsAlphaProcAddr, Eax
		Mov Eax, RSdwPageSize
		Shl Eax, 1
		Invoke RSAllocateEditorMemory, Eax
		Invoke RSInitEditor
		Mov [Ebx].EDITPARENT.bBigEndian, FALSE
		Mov [Ebx].EDITPARENT.bTextUnicode, FALSE
		Mov [Ebx].EDITPARENT.bTextUnicodeUTF8, FALSE
		Mov [Ebx].EDITPARENT.bWriteBom, TRUE
		Invoke RSGetBytes, MIN_LINE_SIZE
		Add [Ebx].EDITPARENT.lpszNextText, Eax
		Mov [Ebx].EDITPARENT.bRedraw, TRUE
		Mov [Ebx].EDITPARENT.lCaretWidth, 1
		Mov [Ebx].EDITPARENT.lSelBarWidth, 14
		Mov [Ebx].EDITPARENT.lMouseWheelUnits, 3
		Mov [Ebx].EDITPARENT.lTabSize, 4
		Mov [Ebx].EDITPARENT.dwEventMask, (RSV_CHANGE Or RSV_KILLFOCUS Or RSV_HSCROLL Or RSV_SELCHANGE Or RSV_SETFOCUS Or RSV_UPDATE Or RSV_VSCROLL)
		Mov [Ebx].EDITPARENT.crBackColor, (80000000H Or COLOR_WINDOW)
		Mov [Ebx].EDITPARENT.crTextColor, (80000000H Or COLOR_WINDOWTEXT)
		Mov [Ebx].EDITPARENT.crBackSelect, (80000000H Or COLOR_HIGHLIGHT)
		Mov [Ebx].EDITPARENT.crTextSelect, (80000000H Or COLOR_HIGHLIGHTTEXT)
		Mov [Ebx].EDITPARENT.crBackMargin, 00E0E0E0H
		Mov [Ebx].EDITPARENT.crBackLocked, 00F0F0F0H
		Mov [Ebx].EDITPARENT.crTextLocked, 00808080H
		Mov Edi, lParam
		Mov Eax, [Edi].CREATESTRUCT.hMenu
		And Eax, 0000FFFFH
		Mov [Edi].CREATESTRUCT.hMenu, Eax
		Mov [Ebx].EDITPARENT.lCtrlID, Eax

		Invoke RSSendMessage, [Ebx].EDITPARENT.hWndParent, RSM_GETUCASETABLES, Addr lpUCaseTableA, Addr lpUCaseTableW

		Mov Edi, [Edi].CREATESTRUCT.lpCreateParams
		Mov Edi, [Edi]

		Test Edi, RSS_SPLIT
		Jz @F
		Invoke CreateWindowEx, WS_EX_DLGMODALFRAME, Addr RSszStatic, NULL, (WS_CHILD Or WS_VISIBLE Or WS_CLIPSIBLINGS Or SS_NOTIFY), 0, 0, 0, 0, hWnd, NULL, RShInst, 0
		Mov [Ebx].EDITPARENT.hWndSplitter, Eax

@@:		Invoke CreateWindowEx, 0, Addr RSszEditorChildClass, NULL, (WS_CHILD Or WS_VISIBLE Or WS_CLIPCHILDREN Or WS_CLIPSIBLINGS), 0, 0, 0, 0, hWnd, NULL, RShInst, 0
		Mov [Ebx].EDITPARENT.Editor.hWnd, Eax
		Test Edi, WS_VSCROLL
		Jz @F
		Invoke CreateWindowEx, 0, Addr RSszScrollBar, NULL, (WS_CHILD Or WS_VISIBLE Or WS_DISABLED Or SBS_VERT), 0, 0, 0, 0, [Ebx].EDITPARENT.Editor.hWnd, NULL, RShInst, 0
		Mov [Ebx].EDITPARENT.Editor.hWndVScroll, Eax

@@:		Test Edi, WS_HSCROLL
		Jz @F
		Invoke CreateWindowEx, 0, Addr RSszScrollBar, NULL, (WS_CHILD Or WS_VISIBLE Or WS_DISABLED Or SBS_HORZ), 0, 0, 0, 0, hWnd, NULL, RShInst, 0
		Mov [Ebx].EDITPARENT.hWndHScroll, Eax
		Invoke CreateWindowEx, 0, Addr RSszScrollBar, NULL, (WS_CHILD Or WS_VISIBLE Or SBS_SIZEGRIP), 0, 0, 0, 0, hWnd, NULL, RShInst, 0
		Mov [Ebx].EDITPARENT.hWndGrip, Eax
		Invoke CreateWindowEx, 0, Addr RSszStatic, NULL, (WS_CHILD Or WS_VISIBLE Or SS_NOTIFY), 0, 0, 0, 0, hWnd, NULL, RShInst, 0
		Mov [Ebx].EDITPARENT.hWndNoGrip, Eax

@@:		Lea Esi, [Ebx].EDITPARENT.Editor

		Invoke GetDC, [Esi].EDITCHILD.hWnd
		Mov Edi, Eax
		Invoke CreateCompatibleDC, Eax
		Mov [Ebx].EDITPARENT.hMem, Eax
		Invoke SetBkMode, Eax, TRANSPARENT
		Invoke ReleaseDC, [Esi].EDITCHILD.hWnd, Edi

		Invoke RSSetEditorColors
		Mov RSFont.lPoints, 10
		Mov RSFont.lWeight, FW_NORMAL
		.If [Ebx].EDITPARENT.bTextUnicode
			Mov Eax, TextStrW("Courier New")
		.Else
			Mov Eax, TextStr("Courier New")
		.EndIf
		Invoke RSCopyString, Addr RSFont.szFaceName, Eax
		Invoke RSSendMessage, hWnd, RSM_CREATEFONT, TRUE, Addr RSFont

		Invoke GetWindowLong, [Ebx].EDITPARENT.hWndHScroll, GWL_WNDPROC
		Invoke SetWindowLong, [Ebx].EDITPARENT.hWndHScroll, GWL_USERDATA, Eax
		Invoke SetWindowLong, [Ebx].EDITPARENT.hWndHScroll, GWL_WNDPROC, Addr RSEditorHScrollProc

		Mov Eax, [Ebx].EDITPARENT.Editor.hWnd
		Mov [Ebx].EDITPARENT.hWndFocus, Eax
		Invoke SetFocus, Eax
		Mov RSsci.cbSize, SizeOf SCROLLINFO
		Mov RSsci.fMask, SIF_ALL
		Invoke GetScrollInfo, [Ebx].EDITPARENT.Editor.hWndVScroll, SB_CTL, Addr RSsci
		.If [Ebx].EDITPARENT.hWndSplitter
			Invoke GetWindowLong, [Ebx].EDITPARENT.hWndSplitter, GWL_WNDPROC
			Invoke SetWindowLong, [Ebx].EDITPARENT.hWndSplitter, GWL_USERDATA, Eax
			Invoke SetWindowLong, [Ebx].EDITPARENT.hWndSplitter, GWL_WNDPROC, Addr RSEditorSplitterProc
		.EndIf
		Invoke SetWindowPos, [Ebx].EDITPARENT.Editor.hWnd, HWND_TOP, 0, 0, 0, 0, (SWP_NOMOVE Or SWP_NOSIZE)
		Invoke SetWindowPos, [Ebx].EDITPARENT.hWndSplitter, HWND_TOP, 0, 0, 0, 0, (SWP_NOMOVE OR SWP_NOSIZE)
L2:		Xor Eax, Eax
		Jmp L6
	.ElseIf uMsg == WM_APPCOMMAND
		Invoke DefWindowProc, hWnd, uMsg, wParam, lParam
		Jmp L6
	.ElseIf uMsg == WM_SETCURSOR
		Mov Eax, wParam
		.If Eax == hWnd
			Invoke SetClassLong, hWnd, GCL_HCURSOR, RShArrow
			Push Eax
			Invoke DefWindowProc, hWnd, uMsg, wParam, lParam
			Pop Eax
			Invoke SetClassLong, hWnd, GCL_HCURSOR, Eax
			Mov Eax, TRUE
			Jmp L6
		.EndIf
	.ElseIf uMsg == WM_SETFOCUS
		Invoke GetFocus
		Mov Edx, [Ebx].EDITPARENT.Editor.hWnd
		.If Edx != [Ebx].EDITPARENT.hWndFocus
			Mov Edx, [Ebx].EDITPARENT.Mirror.hWnd
		.EndIf
		.If Eax != Edx
			Invoke SetFocus, Edx
		.EndIf
		Jmp L2
	.ElseIf uMsg == WM_LBUTTONDOWN || uMsg == WM_RBUTTONDOWN || uMsg == WM_MBUTTONDOWN
		Invoke GetFocus
		.If Eax != [Ebx].EDITPARENT.hWndFocus
			Invoke SetFocus, [Ebx].EDITPARENT.hWndFocus
		.EndIf
	.ElseIf uMsg == WM_KEYDOWN || uMsg == WM_CHAR || uMsg == WM_KEYUP
		Invoke SetFocus, [Ebx].EDITPARENT.hWndFocus
		Invoke SendMessage, [Ebx].EDITPARENT.hWndFocus, uMsg, wParam, lParam
		Jmp L6
	.ElseIf uMsg == WM_HSCROLL
		Invoke PostMessage, [Ebx].EDITPARENT.hWndFocus, uMsg, wParam, lParam
		Jmp L2
	.ElseIf uMsg == WM_GETTEXT
		Shr wParam, 1
		Push [Ebx].EDITPARENT.dwEventMask
		Mov [Ebx].EDITPARENT.dwEventMask, 0
		Mov Eax, [Ebx].EDITPARENT.hWndFocus
		.If Eax == [Ebx].EDITPARENT.Editor.hWnd
			Lea Esi, [Ebx].EDITPARENT.Editor
		.Else
			Lea Esi, [Ebx].EDITPARENT.Mirror
		.EndIf
		Push [Esi].EDITCHILD.chrPos.lMin
		Push [Esi].EDITCHILD.chrPos.lMax
		Mov [Esi].EDITCHILD.chrPos.lMin, 0
		Mov Eax, wParam
		Dec Eax
		.If Eax > SDWord Ptr [Ebx].EDITPARENT.lMaxIndex
			Mov Eax, [Ebx].EDITPARENT.lMaxIndex
		.EndIf
		Mov wParam, Eax
		Mov [Esi].EDITCHILD.chrPos.lMax, Eax
		Invoke RSGetSelectedText, lParam, Eax, TRUE
		Pop [Esi].EDITCHILD.chrPos.lMax
		Pop [Esi].EDITCHILD.chrPos.lMin
		Pop [Ebx].EDITPARENT.dwEventMask
		Mov Eax, wParam
		Jmp L6
	.ElseIf uMsg == WM_GETTEXTLENGTH
		Xor Eax, Eax
		Xor Ecx, Ecx
		Mov Edx, [Ebx].EDITPARENT.lpLinesPointer
@@:		Add Eax, [Edx].LINE.lLength
		Add Edx, SizeOf LINE
		Inc Ecx
		Cmp Ecx, [Ebx].EDITPARENT.lLines
		Jle @B
		Mov Ecx, [Ebx].EDITPARENT.lLines
		.If RSlLineFormat == RSC_CR_LF
			Shl Ecx, 1
		.EndIf
		Add Eax, Ecx
		Jmp L6
	.ElseIf uMsg == WM_SETFONT
		Mov Eax, wParam
		Xchg Eax, [Ebx].EDITPARENT.hFont
		.If Eax != NULL && Eax != [Ebx].EDITPARENT.hFont
			Invoke DeleteObject, Eax
		.EndIf
L4:		.If [Ebx].EDITPARENT.Editor.hWnd != NULL
			Invoke SendMessage, [Ebx].EDITPARENT.Editor.hWnd, uMsg, wParam, lParam
		.EndIf
		.If [Ebx].EDITPARENT.Mirror.hWnd != NULL
			Invoke SendMessage, [Ebx].EDITPARENT.Mirror.hWnd, uMsg, wParam, lParam
		.EndIf
		Jmp L6
	.ElseIf uMsg == WM_SETTEXT
		Invoke RSCheckTextFormat, lParam
		Invoke RSSetNewText, lParam
		Mov Eax, TRUE
		Jmp L6
	.ElseIf uMsg == RSM_CHANGEACTIVEEDITOR
		Mov Eax, [Ebx].EDITPARENT.Mirror.hWnd
		.If Eax
			.If Eax == [Ebx].EDITPARENT.hWndFocus
				Lea Esi, [Ebx].EDITPARENT.Editor
			.Else
				Lea Esi, [Ebx].EDITPARENT.Mirror
			.EndIf
			Invoke SetFocus, [Esi].EDITCHILD.hWnd
			Invoke RSSetSelection, [Esi].EDITCHILD.chrSel.lMin, [Esi].EDITCHILD.chrSel.lMax, 0
			Mov [Esi].EDITCHILD.lPaint, PAINT_ALL
			Invoke RSRedrawEditor, [Esi].EDITCHILD.hWnd, FALSE
			Invoke RSSendNotifyMessage, EN_SELCHANGE
		.Else
			Invoke MessageBeep, MB_OK
		.EndIf
		Jmp L6
	.ElseIf uMsg == RSM_CREATEFONT
		Mov [Ebx].EDITPARENT.bRedraw, FALSE
		Invoke GlobalAlloc, GPTR, 132
		Mov dwTemp, Eax
		Invoke RtlMoveMemory, Addr RSFont, lParam, SizeOf RSSEDITFONT
		Mov Esi, RSFont.lPoints
		Invoke GetDC, hWnd
		Mov Edi, Eax
		Invoke GetDeviceCaps, Edi, LOGPIXELSY
		Mul Esi
		Mov Esi, 72
		Xor Edx, Edx
		Div Esi
		Mov Esi, Eax
		Neg Esi
		Invoke ReleaseDC, hWnd, Edi
		Mov rc.left, (IS_TEXT_UNICODE_ASCII16 Or IS_TEXT_UNICODE_REVERSE_ASCII16 Or IS_TEXT_UNICODE_CONTROLS Or IS_TEXT_UNICODE_REVERSE_CONTROLS)
		Invoke IsTextUnicode, Addr RSFont.szFaceName, 10, Addr rc.left
		.If [Ebx].EDITPARENT.bTextUnicode
			.If Eax
				Invoke lstrcpynW, dwTemp, Addr RSFont.szFaceName, (LF_FACESIZE + 1)
			.Else
				Invoke MultiByteToWideChar, CP_ACP, 0, Addr RSFont.szFaceName, (-1), dwTemp, 128
			.EndIf
			Mov Eax, DEFAULT_CHARSET
		.Else
			.If Eax
				Invoke RSConvertToMultibyte, Addr RSFont.szFaceName, dwTemp, (LF_FACESIZE + 1)
			.Else
				Invoke lstrcpynA, dwTemp, Addr RSFont.szFaceName, (LF_FACESIZE + 1)
			.EndIf
			Mov Eax, ANSI_CHARSET
		.EndIf
		Mov RSFont.dwCharSet, Eax
		Push dwTemp
		Push 0
		Push 0
		Push 0
		Push 0
		Push RSFont.dwCharSet
		Push RSFont.bStrikethru
		Push RSFont.bUnderline
		Push RSFont.bItalic
		Push RSFont.lWeight
		Push 0
		Push 0
		Push 0
		Push Esi
		.If [Ebx].EDITPARENT.bTextUnicode
			Call CreateFontW
		.Else
			Call CreateFontA
		.EndIf
		Mov Esi, Eax
		Invoke GlobalFree, dwTemp
		Invoke RSSendMessage, hWnd, WM_SETFONT, Esi, wParam
		Invoke RSSetUCaseTable
		Mov Eax, Esi
		Mov [Ebx].EDITPARENT.bRedraw, TRUE
		Jmp L6
	.ElseIf uMsg == EM_CANPASTE
		.If wParam == (-1)
			.If ([Ebx].EDITPARENT.bTextUnicode)
				Mov wParam, CF_UNICODETEXT
			.Else
				Mov wParam, CF_TEXT
			.EndIf
		.EndIf
		Invoke IsClipboardFormatAvailable, wParam
		.If (!Eax)
			.If (wParam == CF_TEXT)
				Mov wParam, CF_UNICODETEXT
			.Else
				Mov wParam, CF_TEXT
			.EndIf
			Invoke IsClipboardFormatAvailable, wParam
		.EndIf
		Jmp L6
	.ElseIf uMsg == RSM_CLEARUNDOBUFFER || uMsg == EM_EMPTYUNDOBUFFER
		Invoke RSClearUndoEntryFrom, 0
		Mov [Ebx].EDITPARENT.lUndoCount, 0
		Mov [Ebx].EDITPARENT.lLastUndoCount, 0
		Jmp L6
	.ElseIf uMsg == RSM_GETHIDESELECTION
		Mov Eax, [Ebx].EDITPARENT.bHideSelection
		Jmp L6
	.ElseIf uMsg == RSM_GETLASTPOSITION
		Mov Eax, [Ebx].EDITPARENT.lMaxIndex
		Jmp L6
	.ElseIf uMsg == EM_GETMODIFY
		Mov Eax, [Ebx].EDITPARENT.bModified
		Jmp L6
	.ElseIf uMsg == RSM_GETSELBARWIDTH
		Mov Eax, [Ebx].EDITPARENT.lSelBarWidth
		Jmp L6
	.ElseIf uMsg == RSM_GETTABSIZE
		Mov Eax, [Ebx].EDITPARENT.lTabSize
		Jmp L6
	.ElseIf uMsg == RSM_GETTABTOSPACES
		Mov Eax, [Ebx].EDITPARENT.bTabToSpaces
		Jmp L6
	.ElseIf uMsg == RSM_GETTEXTFORMAT
		Mov Eax, 1
		.If [Ebx].EDITPARENT.bTextUnicode
			Inc Eax
			.If [Ebx].EDITPARENT.bBigEndian
				Inc Eax
			.ElseIf [Ebx].EDITPARENT.bTextUnicodeUTF8
				Add Eax, 2
			.EndIf
		.EndIf
		Jmp L6
	.ElseIf uMsg == RSM_GETLINECOUNT
		Mov Eax, [Ebx].EDITPARENT.lLines
		Jmp L6
	.ElseIf uMsg == RSM_ISTEXTUNICODE
		Mov Eax, [Ebx].EDITPARENT.bTextUnicode
		Jmp L6
	.ElseIf uMsg == RSM_ISTEXTUNICODEUTF8
		Mov Eax, [Ebx].EDITPARENT.bTextUnicodeUTF8
		Jmp L6
	.ElseIf uMsg == EM_LINESCROLL
		Invoke SendMessage, [Ebx].EDITPARENT.hWndFocus, uMsg, 0, lParam
		Jmp L4
	.ElseIf uMsg == RSM_OPENFILE
		Xor Eax, Eax
		Mov wParam, Eax
		.If lParam
			Push MAX_PATH
			Push lParam
			Push lParam
			.If RSbAppUnicode
				Call GetShortPathNameW
			.Else
				Call GetShortPathName
			.EndIf
			Push NULL
			Push FILE_ATTRIBUTE_NORMAL
			Push OPEN_EXISTING
			Push NULL
			Push (FILE_SHARE_READ Or FILE_SHARE_WRITE)
			Push GENERIC_READ
			Push lParam
			.If RSbAppUnicode
				Call CreateFileW
			.Else
				Call CreateFile
			.EndIf
			.If Eax != INVALID_HANDLE_VALUE
				Mov Edi, Eax
				Push [Ebx].EDITPARENT.dwEventMask
				Mov [Ebx].EDITPARENT.dwEventMask, 0
				Invoke RSDestroyMirror
				Invoke GetFileSize, Edi, NULL
				Mov Edx, Eax
				Invoke RSAllocateEditorMemory, Edx
				Invoke RSInitEditor
				Mov [Ebx].EDITPARENT.bBigEndian, FALSE
				Mov [Ebx].EDITPARENT.bTextUnicode, FALSE
				Mov [Ebx].EDITPARENT.bTextUnicodeUTF8, FALSE
				Lea Esi, [Ebx].EDITPARENT.Editor
				Invoke RSInvalidateEditor, [Esi].EDITCHILD.hWnd, TRUE
				Invoke RSUpdateScrollBars, (SCROLL_HORZ Or SCROLL_VERT)
				Mov [Esi].EDITCHILD.lPaint, PAINT_ALL
				.If Edx
					Mov wParam, Edx
					Push Esi
					Add Edx, 4
					Invoke VirtualAlloc, 0, Edx, MEM_COMMIT, PAGE_READWRITE
					Mov Esi, Eax
					Invoke ReadFile, Edi, Esi, 2, Addr dwTemp, NULL
					Invoke RSSendMessage, [Ebx].EDITPARENT.hWndParent, RSL_GETPLATFORM, 0, 0
					.If (RSbAppUnicode || Eax > SDWord Ptr ECC_WINME)
						.If (Word Ptr [Esi] == 0FEFFH || Word Ptr [Esi] == 0FFFEH)
							Sub wParam, 2
							.If (Word Ptr [Esi] == 0FFFEH)
								Mov [Ebx].EDITPARENT.bBigEndian, TRUE
							.EndIf
							Mov [Ebx].EDITPARENT.bTextUnicode, TRUE
						.ElseIf (Word Ptr [Esi] == 0BBEFH) ;UTF-8
							Invoke ReadFile, Edi, Esi, 1, Addr dwTemp, NULL
							Cmp Byte Ptr [Esi], 0BFH
							Jne L5
							Sub wParam, 3
							Mov [Ebx].EDITPARENT.bTextUnicodeUTF8, TRUE
							Mov [Ebx].EDITPARENT.bTextUnicode, TRUE
						.Else
L5:							Invoke SetFilePointer, Edi, 0, 0, FILE_BEGIN
							Invoke ReadFile, Edi, Esi, wParam, Addr dwTemp, NULL
							Mov dwTemp, (IS_TEXT_UNICODE_ASCII16 OR IS_TEXT_UNICODE_REVERSE_ASCII16 OR IS_TEXT_UNICODE_CONTROLS OR IS_TEXT_UNICODE_REVERSE_CONTROLS)
							Mov Edx, 8
							.If (SDWord Ptr wParam > Edx)
								Mov Edx, wParam
							.EndIf
							Invoke IsTextUnicode, Esi, Edx, Addr dwTemp
							.If Eax
								Mov dwTemp, (IS_TEXT_UNICODE_REVERSE_ASCII16 OR IS_TEXT_UNICODE_REVERSE_CONTROLS)
								Invoke IsTextUnicode, Esi, wParam, Addr dwTemp
								.If Eax
									Mov [Ebx].EDITPARENT.bBigEndian, TRUE
								.EndIf
								Mov Eax, TRUE
							.Else
								Invoke RSIsUTF8Text, Esi, wParam
								Or Eax, Eax
								Jz L5A
								Mov [Ebx].EDITPARENT.bTextUnicodeUTF8, Eax
							.EndIf
							.If Eax
								Mov [Ebx].EDITPARENT.bTextUnicode, TRUE
							.EndIf
							Jmp L5A
						.EndIf
					.ElseIf (Word Ptr [Esi] == 0FEFFH || Word Ptr [Esi] == 0FFFEH || Word Ptr [Esi] == 0BBEFH)
						Invoke RSSendMessage, [Ebx].EDITPARENT.hWndParent, RSM_SHOWMESSAGEBOX, RSC_ERRORUNICODE, 0
						Invoke CloseHandle, Edi
						Invoke VirtualFree, Esi, 0, MEM_RELEASE
						Pop Esi
						Pop [Ebx].EDITPARENT.dwEventMask
						Xor Eax, Eax
						Jmp L6
					.Else
						Invoke SetFilePointer, Edi, 0, 0, FILE_BEGIN
					.EndIf
					Invoke ReadFile, Edi, Esi, wParam, Addr dwTemp, NULL
L5A:				Invoke CloseHandle, Edi
					Invoke RSSendMessage, hWnd, RSM_CREATEFONT, TRUE, Addr RSFont
					Mov Edi, Esi
					Pop Esi
					Invoke RSSetText, Edi, [Ebx].EDITPARENT.lpTextPointer, wParam
					Invoke VirtualFree, Edi, 0, MEM_RELEASE
				.EndIf
				Mov [Ebx].EDITPARENT.bModified, FALSE
				Pop [Ebx].EDITPARENT.dwEventMask
				Invoke RSSetSelection, 0, 0, 0
				Mov Eax, wParam
			.EndIf
		.EndIf
		Jmp L6
	.ElseIf uMsg == RSM_SAVEFILE
		Invoke RSResizeBuffer, RSC_TEXT, (-1)
		Invoke RSCheckTextFormat, wParam
		Push MAX_PATH
		Push lParam
		Push lParam
		.If RSbAppUnicode
			Call GetShortPathNameW
		.Else
			Call GetShortPathName
		.EndIf
		Push NULL
		Push FILE_ATTRIBUTE_NORMAL
		Push CREATE_ALWAYS
		Push NULL
		Push (FILE_SHARE_READ Or FILE_SHARE_WRITE)
		Push GENERIC_WRITE
		Push lParam
		.If RSbAppUnicode
			Call CreateFileW
		.Else
			Call CreateFile
		.EndIf
		Cmp Eax, INVALID_HANDLE_VALUE
		Je L6
		Mov Edi, Eax
		.If ([Ebx].EDITPARENT.bTextUnicode)
			.If [Ebx].EDITPARENT.bWriteBom
				.If ([Ebx].EDITPARENT.bTextUnicodeUTF8)
					Mov Edx, TextStrA(0EFH, 0BBH, 0BFH)
					Mov Ecx, 3
				.ElseIf ([Ebx].EDITPARENT.bBigEndian)
					Mov Edx, TextStrA(0FEH, 0FFH)
					Mov Ecx, 2
				.Else
					Mov Edx, TextStrA(0FFH, 0FEH)
					Mov Ecx, 2
				.EndIf
				Invoke WriteFile, Edi, Edx, Ecx, Addr dwTemp, NULL
			.EndIf
		.EndIf
		Mov Eax, [Ebx].EDITPARENT.lMaxIndex
		Add Eax, [Ebx].EDITPARENT.lLines
		Push Eax
		Add Eax, 2
		Invoke RSGetBytes, Eax
		Invoke VirtualAlloc, 0, Eax, MEM_COMMIT, PAGE_READWRITE
		Mov Esi, Eax
		Pop Ecx
		.If (RSlLineFormat == RSC_CR || RSlLineFormat == RSC_LF)
			Push Edi
			Push Esi
			Mov Edi, [Ebx].EDITPARENT.lpTextPointer
			.If ([Ebx].EDITPARENT.bTextUnicode)
@@:				Mov Ax, Word Ptr [Edi]
				Or Ax, Ax
				Jz L5B
				.If (Ax == VK_RETURN && RSlLineFormat == RSC_LF)
					Mov Ax, LF
				.EndIf
				.If [Ebx].EDITPARENT.bBigEndian
					Xchg Ah, Al
				.EndIf
				Mov Word Ptr [Esi], Ax
				Add Edi, 2
				Add Esi, 2
				Jmp @B
			.Else
@@:				Mov Al, Byte Ptr [Edi]
				Or Al, Al
				Jz L5B
				.If (Al == VK_RETURN && RSlLineFormat == RSC_LF)
					Mov Al, LF
				.EndIf
				Mov Byte Ptr [Esi], Al
				Inc Edi
				Inc Esi
				Jmp @B
			.EndIf
L5B:		Pop Esi
			Mov Eax, Edi
			Sub Eax, [Ebx].EDITPARENT.lpTextPointer
			Invoke RSGetChars, Eax
			Pop Edi
		.Else
			Invoke RSTextToClipboard, Esi, [Ebx].EDITPARENT.lpTextPointer, [Ebx].EDITPARENT.lMaxIndex, TRUE
		.EndIf
		.If [Ebx].EDITPARENT.bTextUnicodeUTF8
			Invoke RSEncodeUTF8, Esi, Eax
		.Else
			Invoke RSGetBytes, Eax
		.EndIf
		Mov Ecx, Eax
		Invoke WriteFile, Edi, Esi, Ecx, Addr dwTemp, NULL
		Invoke CloseHandle, Edi
		Invoke VirtualFree, Esi, 0, MEM_RELEASE
		Invoke SetFileAttributes, lParam, FILE_ATTRIBUTE_ARCHIVE
		Mov [Ebx].EDITPARENT.bModified, FALSE
		Push [Ebx].EDITPARENT.lUndoCount
		Pop [Ebx].EDITPARENT.lLastUndoCount
		Jmp L6
	.ElseIf uMsg == RSM_SETAUTOINDENT
		Mov Eax, wParam
		Xchg [Ebx].EDITPARENT.bAutoIndent, Eax
		Jmp L6
	.ElseIf uMsg == RSM_SETCHARPROCADDRESS
		Mov Eax, lParam
		Or Eax, Eax
		Jnz @F
		Lea Eax, RSIsCharAlphaProc
@@:		Xchg [Ebx].EDITPARENT.RSIsAlphaProcAddr, Eax
		Jmp L6
	.ElseIf uMsg == RSM_SETHIDEGRIP
		Mov Eax, wParam
		Mov [Ebx].EDITPARENT.bHideGrip, Eax
		Invoke SendMessage, hWnd, WM_WINDOWPOSCHANGED, 0, 0
		Jmp L6
	.ElseIf uMsg == RSM_SETHIDESELECTION
		Mov Eax, wParam
		Xchg [Ebx].EDITPARENT.bHideSelection, Eax
		Push Eax
		Invoke SendMessage, [Ebx].EDITPARENT.Editor.hWnd, uMsg, wParam, lParam
		.If [Ebx].EDITPARENT.Mirror.hWnd
			Invoke SendMessage, [Ebx].EDITPARENT.Mirror.hWnd, uMsg, wParam, lParam
		.EndIf
		Invoke SetFocus, hWnd
		Pop Eax
		Jmp L6
	.ElseIf uMsg == EM_SETMODIFY
		Mov Eax, wParam
		Mov [Ebx].EDITPARENT.bModified, Eax
		Jmp L6
	.ElseIf uMsg == EM_SETREADONLY
		Mov Eax, wParam
		Mov [Ebx].EDITPARENT.bReadOnly, Eax
		Jmp L6
	.ElseIf uMsg == RSM_SETSEARCHHANDLE
		Mov Eax, lParam
		Mov [Ebx].EDITPARENT.hWndFind, Eax
		Jmp L6
	.ElseIf uMsg == RSM_SETSELBARWIDTH
		Mov Eax, wParam
		Mov [Ebx].EDITPARENT.lSelBarWidth, Eax
		Invoke RSCheckScrollWidth
		Invoke InvalidateRect, hWnd, NULL, TRUE
		Invoke SendMessage, hWnd, WM_PAINT, 0, 0
		Jmp L6
	.ElseIf uMsg == RSM_SETTABSIZE
		Mov Eax, wParam
		Mov [Ebx].EDITPARENT.lTabSize, Eax
		Invoke SendMessage, [Ebx].EDITPARENT.Editor.hWnd, uMsg, wParam, lParam
		Jmp L6
	.ElseIf uMsg == RSM_SETTABTOSPACES
		Mov Eax, wParam
		Mov [Ebx].EDITPARENT.bTabToSpaces, Eax
		Jmp L6
	.ElseIf uMsg == RSM_SETSPACESTOTAB
		Mov Eax, wParam
		Mov [Ebx].EDITPARENT.bSpacesToTab, Eax
		Jmp L6
	.ElseIf uMsg == RSM_SETWRITEBOM
		Mov Eax, wParam
		Xchg Eax, [Ebx].EDITPARENT.bWriteBom
		Jmp L6
	.ElseIf uMsg == RSM_SETTEXTUNICODE
		Invoke RSInitEditor
		Mov Eax, [Ebx].EDITPARENT.bTextUnicodeUTF8
		Shl Eax, 16
		Or Eax, [Ebx].EDITPARENT.bTextUnicode
		Push Eax
		.If (!RSbAppUnicode)
			Mov [Ebx].EDITPARENT.bBigEndian, FALSE
			Mov [Ebx].EDITPARENT.bTextUnicode, FALSE
			Mov [Ebx].EDITPARENT.bTextUnicodeUTF8, FALSE
		.Else
			Mov Eax, lParam
			Mov [Ebx].EDITPARENT.bBigEndian, Eax
			Mov Eax, wParam
			Shr Eax, 16
			Mov [Ebx].EDITPARENT.bTextUnicodeUTF8, Eax
			.If Eax
				Mov [Ebx].EDITPARENT.bTextUnicode, TRUE
				Mov [Ebx].EDITPARENT.bBigEndian, FALSE
			.Else
				Mov Eax, wParam
				And Eax, 0000FFFFH
				Mov [Ebx].EDITPARENT.bTextUnicode, Eax
			.EndIf
			.If (![Ebx].EDITPARENT.bTextUnicode)
				Mov [Ebx].EDITPARENT.bBigEndian, FALSE
			.EndIf
		.EndIf
		Invoke SendMessage, hWnd, RSM_CREATEFONT, TRUE, Addr RSFont
		Pop Eax
		Jmp L6
	.ElseIf uMsg == WM_SYSCOLORCHANGE
		Invoke RSSetEditorColors
	.ElseIf uMsg == WM_WINDOWPOSCHANGED
		Invoke GetClientRect, hWnd, Addr [Ebx].EDITPARENT.rc
		.If SDWord Ptr [Ebx].EDITPARENT.rc.bottom > 0
			Invoke GetSystemMetrics, SM_CXVSCROLL
			Mov RSlVScrollWidth, Eax ;Width in pixels of a vertical scroll bar
			.If [Ebx].EDITPARENT.hWndHScroll != NULL
				Invoke GetSystemMetrics, SM_CYHSCROLL
				Mov RSlHScrollHeight, Eax ;Height in pixels of a horizontal scroll bar
				Mov Ecx, [Ebx].EDITPARENT.rc.right
				.If [Ebx].EDITPARENT.Editor.hWndVScroll != NULL
					Sub Ecx, RSlVScrollWidth
				.EndIf
				Mov Edx, [Ebx].EDITPARENT.rc.bottom
				Sub Edx, RSlHScrollHeight
				Push Ecx
				Push Edx
				Invoke MoveWindow, [Ebx].EDITPARENT.hWndHScroll, 0, Edx, Ecx, RSlVScrollWidth, TRUE
				Invoke GetWindowLong, [Ebx].EDITPARENT.hWndParent, GWL_STYLE
				Pop Edx
				Pop Ecx

				.If [Ebx].EDITPARENT.Editor.hWndVScroll != NULL
					Mov Edi, [Ebx].EDITPARENT.hWndNoGrip
					Mov Esi, [Ebx].EDITPARENT.hWndGrip
					Test Eax, WS_MAXIMIZE
					.If (Zero? && ![Ebx].EDITPARENT.bHideGrip)
						Xchg Edi, Esi
					.EndIf
					Invoke MoveWindow, Edi, Ecx, Edx, RSlVScrollWidth, RSlHScrollHeight, TRUE
					Invoke MoveWindow, Esi, 0, 0, 0, 0, TRUE
				.EndIf
			.EndIf
			.If [Ebx].EDITPARENT.hWndSplitter
				.If [Ebx].EDITPARENT.Mirror.hWnd
					Invoke RSGetChildWindowPos, [Ebx].EDITPARENT.hWndSplitter, Addr rc
					Mov Eax, rc.top
					Add Eax, 6
					Mov Ecx, [Ebx].EDITPARENT.rc.bottom
					Sub Ecx, RSlHScrollHeight
					.If Eax > Ecx
						Sub Ecx, 6
						Invoke MoveWindow, [Ebx].EDITPARENT.hWndSplitter, 0, Ecx, [Ebx].EDITPARENT.rc.right, 6, TRUE
					.Else
						Invoke SetWindowPos, [Ebx].EDITPARENT.hWndSplitter, NULL, 0, 0, [Ebx].EDITPARENT.rc.right, 6, (SWP_NOZORDER Or SWP_NOMOVE)
					.EndIf
				.Else
					Mov Eax, [Ebx].EDITPARENT.rc.right
					Sub Eax, RSlVScrollWidth
					Invoke MoveWindow, [Ebx].EDITPARENT.hWndSplitter, Eax, 0, RSlVScrollWidth, 6, TRUE
				.EndIf
			.EndIf
			Invoke RSResizeChilds, FALSE
			Lea Esi, [Ebx].EDITPARENT.Editor
			Mov Eax, [Esi].EDITCHILD.hWnd
			.If Eax != [Ebx].EDITPARENT.hWndFocus
				Lea Esi, [Ebx].EDITPARENT.Mirror
			.EndIf
		.EndIf
		Jmp L2
	.ElseIf uMsg == WM_DESTROY
		Invoke DestroyWindow, [Ebx].EDITPARENT.Editor.hWnd
		.If [Ebx].EDITPARENT.Mirror.hWnd != NULL
			Invoke DestroyWindow, [Ebx].EDITPARENT.Mirror.hWnd
		.EndIf
		.If [Ebx].EDITPARENT.hWndSplitter
			Invoke GetWindowLong, [Ebx].EDITPARENT.hWndSplitter, GWL_USERDATA
			Invoke SetWindowLong, [Ebx].EDITPARENT.hWndSplitter, GWL_WNDPROC, Eax
			Invoke DestroyWindow, [Ebx].EDITPARENT.hWndSplitter
		.EndIf
		Invoke DestroyWindow, [Ebx].EDITPARENT.hWndHScroll
		Invoke DestroyWindow, [Ebx].EDITPARENT.hWndGrip
		Invoke DestroyWindow, [Ebx].EDITPARENT.hWndNoGrip
		Invoke DeleteObject, [Ebx].EDITPARENT.hFont
		Invoke RSReleaseEditorMemory

		.If ([Ebx].EDITPARENT.hBitmap)
			Invoke SelectObject, [Ebx].EDITPARENT.hMem, NULL
			Invoke DeleteObject, [Ebx].EDITPARENT.hBitmap
		.EndIf
		Invoke DeleteDC, [Ebx].EDITPARENT.hMem
		Mov [Ebx].EDITPARENT.hMem, NULL

		Invoke DeleteObject, [Ebx].EDITPARENT.hBackBrush
		Invoke DeleteObject, [Ebx].EDITPARENT.hLockedBrush
		Invoke DeleteObject, [Ebx].EDITPARENT.hMarginBrush
		Invoke DeleteObject, [Ebx].EDITPARENT.hSelectBrush

		Invoke RSFreeLineMemory
		Invoke VirtualFree, Ebx, 0, MEM_RELEASE
		Invoke SetWindowLong, hWnd, GWL_EDITORDATA, 0
	.ElseIf (SDWord Ptr uMsg >= WM_CUT && SDWord Ptr uMsg <= WM_PENWINLAST)
@@:		Invoke SendMessage, [Ebx].EDITPARENT.hWndFocus, uMsg, wParam, lParam
		Jmp L6
	.ElseIf (SDWord Ptr uMsg >= RSM_FIRST && SDWord Ptr uMsg <= RSM_LAST)
		Jmp @B
	.ElseIf (SDWord Ptr uMsg >= EM_GETSEL && SDWord Ptr uMsg <= EM_GETIMESTATUS)
		Jmp @B
	.ElseIf (SDWord Ptr uMsg >= EM_CANPASTE && SDWord Ptr uMsg <= EM_SETZOOM)
		Invoke SendMessage, [Ebx].EDITPARENT.hWndFocus, uMsg, wParam, lParam
		Jmp @B
	.EndIf
	Invoke DefWindowProc, hWnd, uMsg, wParam, lParam
L6:	Ret
RSEditorParentProc EndP

RSEditorChildProc Proc Uses Ebx Edi Esi hWnd:HWND, uMsg:UINT, wParam:WPARAM, lParam:LPARAM
	Local lTemp:LONG, rc:RECT

	Invoke GetWindowLong, hWnd, GWL_EDITORDATA
	Mov Ebx, Eax
	.If Eax
		Mov Eax, hWnd
		.If Eax == [Ebx].EDITPARENT.Editor.hWnd
			Lea Esi, [Ebx].EDITPARENT.Editor
		.Else
			Lea Esi, [Ebx].EDITPARENT.Mirror
		.EndIf
	.EndIf
	.If uMsg == WM_CREATE
		Invoke GetParent, hWnd
		Invoke GetWindowLong, Eax, GWL_EDITORDATA
		Mov Ebx, Eax
		Invoke SetWindowLong, hWnd, GWL_EDITORDATA, Eax
		Mov Edi, lParam
		Mov Edi, [Edi].CREATESTRUCT.lpCreateParams
		.If Edi
			Lea Edi, [Ebx].EDITPARENT.Editor
			Lea Esi, [Ebx].EDITPARENT.Mirror
			Invoke RtlMoveMemory, Esi, Edi, SizeOf EDITCHILD
			.If [Edi].EDITCHILD.hWndVScroll
				Invoke CreateWindowEx, 0, Addr RSszScrollBar, NULL, (WS_CHILD Or WS_VISIBLE Or WS_DISABLED Or SBS_VERT), 0, 0, 0, 0, hWnd, NULL, RShInst, 0
				Mov [Esi].EDITCHILD.hWndVScroll, Eax
			.EndIf
			Mov Eax, hWnd
			Mov [Ebx].EDITPARENT.Mirror.hWnd, Eax
		.EndIf
L2:		Xor Eax, Eax
		Jmp L4
	.ElseIf uMsg == WM_PAINT
		Invoke RSSendCommandMessage, EN_UPDATE
		Invoke RSOnPaint, hWnd
		.If [Esi].EDITCHILD.lPaint == (-1)
			Invoke RSUpdateScrollBars, SCROLL_VERT
		.EndIf
		Mov [Esi].EDITCHILD.lPaint, PAINT_NONE
		Jmp L2
	.ElseIf uMsg == WM_SETCURSOR
		Invoke RSSetEditorCursor, hWnd, uMsg, wParam, lParam
		Mov Eax, TRUE
		Jmp L4
	.ElseIf uMsg == WM_KILLFOCUS
		Invoke DefWindowProc, hWnd, uMsg, wParam, lParam
		Invoke RSKillScrollTimer
		Invoke DestroyCaret
		Mov Eax, wParam
		.While Eax
			.If Eax == [Ebx].EDITPARENT.hWndFind
				Jmp @F
			.EndIf
			Invoke GetParent, Eax
		.EndW
		Push [Ebx].EDITPARENT.bHideSelection
		Pop [Esi].EDITCHILD.bNoSelection
		Invoke InvalidateRect, hWnd, NULL, FALSE
@@:		Mov [Ebx].EDITPARENT.bCaret, FALSE
		Invoke RSSendCommandMessage, EN_KILLFOCUS
		Jmp L2
	.ElseIf uMsg == WM_SETFOCUS
		Mov Eax, hWnd
		Mov [Ebx].EDITPARENT.hWndFocus, Eax
		Mov [Esi].EDITCHILD.bNoSelection, FALSE
		Invoke IsWindowVisible, hWnd
		.If Eax
			Invoke InvalidateRect, hWnd, NULL, FALSE
			Invoke RSSetCaret
		.EndIf
		Invoke RSSendCommandMessage, EN_SETFOCUS
		Jmp L2
	.ElseIf uMsg == WM_KEYDOWN || uMsg == WM_CHAR
		Mov lTemp, 0
		Invoke GetKeyState, VK_CONTROL
		And Eax, 00008000H
		Jz @F
		Or lTemp, KEY_CTRL
@@:		Invoke GetKeyState, VK_SHIFT
		And Eax, 00008000H
		Jz @F
		Or lTemp, KEY_SHIFT
@@:		Invoke GetKeyState, VK_MENU
		And Eax, 00008000H
		Jz @F
		Or lTemp, KEY_ALT
@@:		.If uMsg == WM_KEYDOWN
			Invoke RSOnKeyDown, hWnd, wParam, lTemp
		.Else
			Invoke RSOnChar, hWnd, wParam, lTemp
		.EndIf
		Jmp L4
	.ElseIf uMsg == WM_MOUSEACTIVATE
		Push [Ebx].EDITPARENT.hWndFocus
		Invoke SetFocus, hWnd
		Pop Eax
		.If (Eax != [Ebx].EDITPARENT.hWndFocus)
			Invoke RSSendNotifyMessage, EN_SELCHANGE
		.EndIf
		Mov Eax, MA_ACTIVATE
		Jmp L4
	.ElseIf uMsg == WM_LBUTTONDOWN
		LoWord lParam
		Cwde
		Cmp Eax, [Ebx].EDITPARENT.lSelBarWidth
		Jge @F
		Mov RSbMargin, TRUE
		Invoke RSOnMarginMouseMessage, uMsg, wParam, lParam
		Invoke SetCapture, hWnd
		Jmp L2
@@:		Invoke RSOnEditorMouseMessage, uMsg, wParam, lParam
		.If ((wParam & MK_SHIFT) || (wParam & MK_CONTROL))
			Mov Eax, [Esi].EDITCHILD.chrSel.lMin
			Mov [Esi].EDITCHILD.lPaint, PAINT_ALL
		.EndIf
		Mov [Esi].EDITCHILD.lSelStart, Eax
		Invoke RSSetSelection, [Esi].EDITCHILD.chrPos.lMin, [Esi].EDITCHILD.chrPos.lMax, 0
		Invoke SetCapture, hWnd
		Jmp L2
	.ElseIf uMsg == WM_RBUTTONDOWN || uMsg == WM_MBUTTONDOWN
		LoWord lParam
		Cwde
		Cmp Eax, [Ebx].EDITPARENT.lSelBarWidth
		Jge @F
		Mov RSbMargin, TRUE
@@:		.If uMsg == WM_RBUTTONDOWN || uMsg == WM_MBUTTONDOWN
			Invoke RSOnEditorMouseMessage, uMsg, wParam, lParam
			.If uMsg == WM_RBUTTONDOWN
				Mov Ecx, [Esi].EDITCHILD.chrPos.lMin
				.If (Ecx == SDWord Ptr [Esi].EDITCHILD.chrPos.lMax || Eax < SDWord Ptr [Esi].EDITCHILD.chrPos.lMin || Eax >= SDWord Ptr [Esi].EDITCHILD.chrPos.lMax)
					Mov [Esi].EDITCHILD.chrPos.lMin, Eax
					Mov [Esi].EDITCHILD.chrPos.lMax, Eax
					Invoke RSSetSelection, [Esi].EDITCHILD.chrPos.lMin, [Esi].EDITCHILD.chrPos.lMax, 0
				.EndIf
			.ElseIf RSbMargin
				Push [Esi].EDITCHILD.lCurLine
				Invoke RSGetLineFromChar, Eax
				Mov [Esi].EDITCHILD.lCurLine, Eax
				Invoke RSToggleBookmark, hWnd, FALSE
				Pop [Esi].EDITCHILD.lCurLine
				Mov [Esi].EDITCHILD.lPaint, PAINT_ALL
				Invoke RSInvalidateEditor, hWnd, TRUE
				Invoke RSSendMessage, [Ebx].EDITPARENT.hWndParent, RSM_UPDATEEDITFUNCTIONS, 0, 0
			.EndIf
		.EndIf
	.ElseIf uMsg == WM_MOUSEMOVE
		.If (wParam & MK_LBUTTON)
			Cmp RSbSelBarDblClk, FALSE
			Jne L2
			Invoke GetCapture
			.If Eax == hWnd
				.If [Ebx].EDITPARENT.uVScrollTimer == 0
					Invoke RSWatchScrollTimer, hWnd
					.If RSbMargin
						Invoke RSOnMarginMouseMessage, uMsg, wParam, lParam
					.Else
						Invoke RSOnEditorMouseMessage, uMsg, wParam, lParam
					.EndIf
				.EndIf
			.EndIf
		.EndIf
		Jmp L2
	.ElseIf uMsg == WM_LBUTTONUP
		Invoke RSKillScrollTimer
		Mov RSbSelBarDblClk, FALSE
		Mov RSbMargin, FALSE
		Invoke ReleaseCapture
		Jmp L2
	.ElseIf uMsg == WM_LBUTTONDBLCLK
		Invoke RSSendNotifyMessage, NM_DBLCLK
		LoWord lParam
		Cwde
		Cmp Eax, [Ebx].EDITPARENT.lSelBarWidth
		Jge @F
		Invoke SendMessage, hWnd, WM_LBUTTONDOWN, wParam, lParam
		Invoke RSNextBookmark
		Mov RSbSelBarDblClk, TRUE
		Jmp L2
@@:		Invoke RSSelectWord, [Esi].EDITCHILD.chrPos.lMin, FALSE
		Invoke RSSetSelection, [Esi].EDITCHILD.chrPos.lMin, [Esi].EDITCHILD.chrPos.lMax, 0
		Jmp L2
	.ElseIf uMsg == WM_RBUTTONDBLCLK
		Invoke RSPrevBookmark
	.ElseIf uMsg == WM_MBUTTONDBLCLK
		Invoke SendMessage, hWnd, WM_MBUTTONDOWN, wParam, lParam
	.ElseIf uMsg == WM_MOUSEWHEEL || uMsg == WM_MOUSEHWHEEL
		HiWord wParam
		Mov Ecx, [Ebx].EDITPARENT.lMouseWheelUnits
		Cmp Ax, 0
		Jl @F
		Neg Ecx
@@:		Xor Eax, Eax
		.If (uMsg == WM_MOUSEHWHEEL)
			Xchg Eax, Ecx
		.EndIf
		Invoke RSScroll, Ecx, Eax
		Invoke RSUpdateScrollBars, (SCROLL_VERT)
		Invoke RSInvalidateEditor, hWnd, TRUE
		Jmp L2
	.ElseIf uMsg == WM_RBUTTONUP || uMsg == WM_MBUTTONUP
		Mov RSbMargin, FALSE
		.If uMsg == WM_RBUTTONUP
			LoWord lParam
			Cwde
			Cmp Eax, [Ebx].EDITPARENT.lSelBarWidth
			Jl L4
			Invoke SetFocus, hWnd
			Mov wParam, 0
			Invoke GetKeyState, VK_CONTROL
			And Eax, 00008000H
			Jz @F
			Or wParam, MK_CONTROL
@@:			Invoke GetKeyState, VK_SHIFT
			And Eax, 00008000H
			Jz @F
			Or wParam, MK_SHIFT
@@:			HiWord lParam
			Cwde
			Cmp Eax, 0
			Jge @F
			Xor Eax, Eax
@@:			Mov rc.top, Eax
			LoWord lParam
			Cwde
			Cmp Eax, 0
			Jge @F
			Xor Eax, Eax
@@:			Mov rc.left, Eax
			Invoke ClientToScreen, hWnd, Addr rc
			Invoke RSSendMessage, [Ebx].EDITPARENT.hWndParent, RSM_RBUTTONCLICKED, wParam, Addr rc
			Jmp L2
		.EndIf
	.ElseIf uMsg == WM_HSCROLL
		Mov RSsci.fMask, SIF_ALL
		Invoke GetScrollInfo, lParam, SB_CTL, Addr RSsci
		Mov Eax, wParam
		And Eax, 0FFFFH
		Mov Ecx, [Ebx].EDITPARENT.szFont.x
		Cmp Eax, SB_LINERIGHT
		Je @F
		Mov Ecx, [Ebx].EDITPARENT.szFont.x
		Neg Ecx
		Cmp Eax, SB_LINELEFT
		Je @F
		Mov Ecx, [Ebx].EDITPARENT.lHScrollPage
		Cmp Eax, SB_PAGERIGHT
		Je @F
		Mov Ecx, [Ebx].EDITPARENT.lHScrollPage
		Neg Ecx
		Cmp Eax, SB_PAGELEFT
		Je @F
		Mov Ecx, RSsci.nTrackPos
		Sub Ecx, [Ebx].EDITPARENT.lHScrollPos
		Cmp Eax, SB_THUMBTRACK
		Je @F
		Cmp Eax, SB_THUMBPOSITION
		Jne L2
@@:		Invoke RSScroll, 0, Ecx
		Invoke RSUpdateScrollBars, SCROLL_HORZ
		Mov [Esi].EDITCHILD.lPaint, PAINT_ALL
		Invoke RSInvalidateEditor, hWnd, TRUE
		Invoke RSSendCommandMessage, EN_HSCROLL
		Jmp L2
	.ElseIf uMsg == WM_VSCROLL
		Mov RSsci.fMask, SIF_ALL
		Invoke GetScrollInfo, lParam, SB_CTL, Addr RSsci
		Mov Eax, wParam
		And Eax, 0FFFFH
		Mov Ecx, 1
		Cmp Eax, SB_LINEDOWN
		Je @F
		Mov Ecx, (-1)
		Cmp Eax, SB_LINEUP
		Je @F
		Mov Ecx, [Esi].EDITCHILD.lVScrollPage
		Cmp Eax, SB_PAGEDOWN
		Je @F
		Mov Ecx, [Esi].EDITCHILD.lVScrollPage
		Neg Ecx
		Cmp Eax, SB_PAGEUP
		Je @F
		Mov Ecx, RSsci.nTrackPos
		Sub Ecx, [Esi].EDITCHILD.lTopLine
		Cmp Eax, SB_THUMBTRACK
		Je @F
		Cmp Eax, SB_THUMBPOSITION
		Jne L2
@@:		Invoke RSScroll, Ecx, 0
		Invoke RSUpdateScrollBars, SCROLL_VERT
		Mov [Esi].EDITCHILD.lPaint, PAINT_ALL
		Invoke RSInvalidateEditor, hWnd, TRUE
		Invoke RSSendCommandMessage, EN_VSCROLL
		Jmp L2
	.ElseIf uMsg == WM_SETFONT
		Invoke GetDC, hWnd
		Mov Edi, Eax
		Invoke SelectObject, Edi, [Ebx].EDITPARENT.hFont
		Push Eax
		Push [Ebx].EDITPARENT.lpszBuffer
		Push Edi
		.If [Ebx].EDITPARENT.bTextUnicode
			Call GetTextMetricsW
		.Else
			Call GetTextMetricsA
		.EndIf
		Pop Eax
		Invoke SelectObject, Edi, Eax
		Invoke ReleaseDC, hWnd, Edi

		Mov Edx, [Ebx].EDITPARENT.lpszBuffer
		Mov Eax, [Edx].TEXTMETRIC.tmHeight
		Add Eax, [Edx].TEXTMETRIC.tmExternalLeading
		Mov [Ebx].EDITPARENT.szFont.y, Eax
		Mov Eax, [Edx].TEXTMETRIC.tmAveCharWidth
		Add Eax, [Edx].TEXTMETRIC.tmOverhang
		Mov [Ebx].EDITPARENT.szFont.x, Eax
		Mov [Ebx].EDITPARENT.lHScrollMax, 0

		Mov Eax, [Ebx].EDITPARENT.lpszBuffer
		Mov DWord Ptr [Eax], 0
		Invoke GetWindowRect, [Ebx].EDITPARENT.hWnd, Addr rc
		Push Esi
		Mov Edi, rc.bottom
		Sub Edi, rc.top
		Mov Esi, rc.right
		Sub Esi, rc.left
		Dec Edi
		Invoke SetWindowPos, [Ebx].EDITPARENT.hWnd, 0, 0, 0, Esi, Edi, (SWP_NOZORDER Or SWP_NOMOVE)
		Inc Edi
		Invoke SetWindowPos, [Ebx].EDITPARENT.hWnd, 0, 0, 0, Esi, Edi, (SWP_NOZORDER Or SWP_NOMOVE)
		Pop Esi
		Invoke RSSetPosition, [Esi].EDITCHILD.chrSel.lMin, [Esi].EDITCHILD.chrSel.lMax
		Invoke RSSetSelection, [Esi].EDITCHILD.chrSel.lMin, [Esi].EDITCHILD.chrSel.lMax, 0
		.If lParam != 0
			Invoke RSInvalidateEditor, hWnd, TRUE
		.EndIf
		Jmp L2
	.ElseIf uMsg == EM_CANREDO
		Xor Eax, Eax
		.If ([Ebx].EDITPARENT.lpUndoPointer && (![Ebx].EDITPARENT.bReadOnly))
			Mov Edx, [Ebx].EDITPARENT.lUndoCount
			Shl Edx, 4
			Add Edx, [Ebx].EDITPARENT.lpUndoPointer
			.If DWord Ptr [Edx] != NULL
				Mov Eax, TRUE
			.EndIf
		.EndIf
		Jmp L4
	.ElseIf uMsg == EM_CANUNDO
		Xor Eax, Eax
		.If [Ebx].EDITPARENT.lpUndoPointer && ![Ebx].EDITPARENT.bReadOnly
			Mov Edx, [Ebx].EDITPARENT.lUndoCount
			Dec Edx
			Jl L4
			Shl Edx, 4
			Add Edx, [Ebx].EDITPARENT.lpUndoPointer
			.If DWord Ptr [Edx] != NULL
				Mov Eax, TRUE
			.EndIf
		.EndIf
		Jmp L4
	.ElseIf uMsg == RSM_CLEARBOOKMARKS
		Mov Edx, [Ebx].EDITPARENT.lpLinesPointer
		Xor Ecx, Ecx
		.While Ecx <= SDWord Ptr [Ebx].EDITPARENT.lLines
			And [Edx].LINE.lState, (Not STATE_BOOKMARK)
			Add Edx, SizeOf LINE
			Inc Ecx		
		.EndW
		Mov [Esi].EDITCHILD.lPaint, PAINT_ALL
		Invoke RSInvalidateEditor, hWnd, TRUE ;FALSE
		Jmp L4
	.ElseIf uMsg == RSM_FINDTEXT
		Invoke RSFindText, wParam, lParam
		.If Eax != (-1)
			.If (wParam & RSC_SELECTTEXT)
				Push Eax
				Mov [Esi].EDITCHILD.lPaint, PAINT_ALL
				Mov Eax, lParam
				Invoke RSGetTextLength, [Eax].RSSFINDTEXT.lpstr
				Pop Ecx
				Add Eax, Ecx
				.If (wParam & RSC_CENTERSELECTION)
					Invoke RSCenterSelection, Ecx, Eax
				.EndIf
				Invoke RSSetSelection, Ecx, Eax, 0
				Invoke RSCheckHorizontalPos
				Mov Eax, Ecx
			.EndIf
		.EndIf
		Jmp L4
	.ElseIf uMsg == RSM_GETBACKCOLOR
		Mov Eax, [Ebx].EDITPARENT.crBackColor
		Jmp L4
	.ElseIf uMsg == RSM_GETBACKMARGIN
		Mov Eax, [Ebx].EDITPARENT.crBackMargin
		Jmp L4
	.ElseIf uMsg == RSM_GETBACKSELECT
		Mov Eax, [Ebx].EDITPARENT.crBackSelect
		Jmp L4
	.ElseIf uMsg == RSM_GETCURRENTLINE
		Mov Eax, [Esi].EDITCHILD.lCurLine
		Jmp L4
	.ElseIf uMsg == RSM_GETEVENTMASK
		Mov Eax, [Ebx].EDITPARENT.dwEventMask
		Jmp L4
	.ElseIf uMsg == EM_GETFIRSTVISIBLELINE
		Mov Eax, [Esi].EDITCHILD.lTopLine
		Jmp L4
	.ElseIf uMsg == EM_GETLINE
		Invoke RSGetLine, wParam, lParam
		Jmp L4
	.ElseIf uMsg == RSM_GETLINEINDEX
		Invoke RSGetLineIndex, wParam
		Jmp L4
	.ElseIf uMsg == RSM_GETLINELENGTH
		Invoke RSGetLine, wParam, lParam
		Jmp L4
	.ElseIf uMsg == RSM_GETLINESAVEFORMAT
		Mov Eax, RSlLineFormat
		Ret
	.ElseIf uMsg == RSM_GETLOCKEDBACKCOLOR
		Mov Eax, [Ebx].EDITPARENT.crBackLocked
		Jmp L4
	.ElseIf uMsg == RSM_GETLOCKEDTEXTCOLOR
		Mov Eax, [Ebx].EDITPARENT.crTextLocked
		Jmp L4
	.ElseIf uMsg == RSM_GETNEXTBOOKMARK
		Invoke RSGetNextBookmark
		Jmp L4
	.ElseIf uMsg == RSM_GETPOSITION
		.If wParam != NULL
			Mov Edx, wParam
			Mov Eax, [Esi].EDITCHILD.lCurLine
			Inc Eax
			Mov DWord Ptr [Edx], Eax
		.EndIf
		.If lParam != NULL
			Mov Edx, lParam
			Mov Eax, [Esi].EDITCHILD.lRealCol
			Inc Eax
			Mov DWord Ptr [Edx], Eax
		.EndIf
		Jmp L4
	.ElseIf uMsg == RSM_GETPREVBOOKMARK
		Invoke RSGetPreviousBookmark
		Jmp L4
	.ElseIf uMsg == RSM_GETPREVNEXTBOOKMARK
		Mov Eax, (-1)
		.If wParam
			Invoke RSGetPreviousBookmark
			Mov Edx, wParam
			Mov DWord Ptr [Edx], Eax
		.EndIf
		.If lParam
			Invoke RSGetNextBookmark
			Mov Edx, lParam
			Mov DWord Ptr [Edx], Eax
		.EndIf
		Jmp L4
	.ElseIf uMsg == RSM_GETSELECTEDTEXT
		Xor Eax, Eax
		.If (lParam != NULL)
			Invoke RSGetSelectedText, lParam, wParam, TRUE
			Push Eax
			Invoke RSGetBytes, Eax
			Mov Edx, Eax
			Add Edx, lParam
			.If [Ebx].EDITPARENT.bTextUnicode
				Mov Word Ptr [Edx], 0
			.Else
				Mov Byte Ptr [Edx], 0
			.EndIf
			Pop Eax
		.EndIf
		Jmp L4
	.ElseIf uMsg == RSM_GETSELECTION || uMsg == EM_GETSEL
		.If wParam != NULL
			Mov Edx, wParam
			Mov Eax, [Esi].EDITCHILD.chrPos.lMin
			Mov DWord Ptr [Edx], Eax
		.EndIf
		.If lParam != NULL
			Mov Edx, lParam
			Mov Eax, [Esi].EDITCHILD.chrPos.lMax
			Mov DWord Ptr [Edx], Eax
		.EndIf
		Jmp L4
	.ElseIf uMsg == RSM_GETSELTEXTLENGTH
		Invoke RSGetSelectedTextLength
		Jmp L4
	.ElseIf uMsg == RSM_GETTEXTCOLOR
		Mov Eax, [Ebx].EDITPARENT.crTextColor
		Jmp L4
	.ElseIf uMsg == RSM_GETTEXTSELECT
		Mov Eax, [Ebx].EDITPARENT.crTextSelect
		Jmp L4
	.ElseIf uMsg == RSM_GETTOPLINEINDEX
		Mov Eax, [Esi].EDITCHILD.lTopLineIndex
		Jmp L4
	.ElseIf uMsg == RSM_GETWORDFIRSTPOSITION
		Mov Eax, lParam
		.If Eax == (-1)
			Mov Eax, [Esi].EDITCHILD.chrPos.lMin
		.EndIf
		Invoke RSGetWordPosition, Eax, TRUE
		Jmp L4
	.ElseIf uMsg == RSM_GETWORDLASTPOSITION
		Mov Eax, lParam
		.If Eax == (-1)
			Mov Eax, [Esi].EDITCHILD.chrPos.lMin
		.EndIf
		Invoke RSGetWordPosition, Eax, FALSE
		Jmp L4
	.ElseIf uMsg == RSM_GETWORDUNDERCURSOR
		Xor Eax, Eax
		.If lParam
			Push [Ebx].EDITPARENT.dwEventMask
			Mov [Ebx].EDITPARENT.dwEventMask, 0
			Mov Eax, lParam
			Mov Word Ptr [Eax], 0
			Push [Esi].EDITCHILD.chrSel.lMin
			Push [Esi].EDITCHILD.chrSel.lMax
			Invoke RSSelectWord, [Esi].EDITCHILD.chrPos.lMin, FALSE
			Invoke RSGetSelectedText, lParam, wParam, TRUE
			Pop [Esi].EDITCHILD.chrSel.lMax
			Pop [Esi].EDITCHILD.chrSel.lMin
			Push Eax
			Invoke RSGetBytes, Eax
			Add Eax, lParam
			.If [Ebx].EDITPARENT.bTextUnicode
				Mov Word Ptr [Eax], 0
			.Else
				Mov Byte Ptr [Eax], 0
			.EndIf
			Invoke RSSetPosition, [Esi].EDITCHILD.chrSel.lMin, [Esi].EDITCHILD.chrSel.lMax
			Pop Eax
			Pop [Ebx].EDITPARENT.dwEventMask
		.EndIf
		Jmp L4
	.ElseIf uMsg == RSM_GOTONEXTBOOKMARK
		Invoke RSNextBookmark
		Jmp L4
	.ElseIf uMsg == RSM_GOTOPREVBOOKMARK
		Invoke RSPrevBookmark
		Jmp L4
	.ElseIf uMsg == RSM_ISCURRENTLINEBOOKMARKED
		Mov Edx, [Esi].EDITCHILD.lCurLine
		Shl Edx, 4
		Add Edx, [Ebx].EDITPARENT.lpLinesPointer
		Mov Eax, [Edx].LINE.lState
		And Eax, STATE_BOOKMARK
		Jmp L4
	.ElseIf uMsg == EM_LINEFROMCHAR
		Mov Eax, wParam
		.If Eax == (-1)
			Mov Eax, [Esi].EDITCHILD.chrPos.lMin
		.EndIf
		Invoke RSGetLineFromChar, Eax
		Jmp L4
	.ElseIf uMsg == EM_LINEINDEX
		Mov Eax, wParam
		.If Eax == (-1)
			Mov Eax, [Esi].EDITCHILD.lCurLine
		.EndIf
		Invoke RSGetLineIndex, Eax
		Jmp L4
	.ElseIf uMsg == EM_LINESCROLL
		Invoke RSScroll, lParam, wParam
		Jmp L4
	.ElseIf uMsg == RSM_LOCKLINES
		Invoke RSLockLines, wParam, lParam
		Jmp L4
	.ElseIf uMsg == WM_CUT || uMsg == WM_COPY
		Mov Eax, [Esi].EDITCHILD.chrPos.lMax
		Cmp Eax, [Esi].EDITCHILD.chrPos.lMin
		Jle L2
		Invoke OpenClipboard, hWnd
		Invoke RSGetSelectedTextLength
		.If Eax
			Mov Edi, Eax
			Invoke EmptyClipboard
			Add Edi, 2
			Invoke RSGetBytes, Edi
			Invoke GlobalAlloc, (GMEM_MOVEABLE Or GMEM_ZEROINIT), Eax
			Mov Edi, Eax
			Invoke GlobalLock, Edi
			Mov lTemp, Eax
			Invoke RSGetSelectedText, lTemp, (-1), TRUE
			Invoke GlobalUnlock, lTemp
			.If ([Ebx].EDITPARENT.bTextUnicode)
				Mov Eax, CF_UNICODETEXT
			.Else
				Mov Eax, CF_TEXT
			.EndIf
			Invoke SetClipboardData, Eax, Edi
		.EndIf
		Invoke CloseClipboard
		Cmp uMsg, WM_CUT
		Jne @F
		Cmp [Ebx].EDITPARENT.bReadOnly, FALSE
		Jne @F
		Invoke RSReplaceSelection, NULL, 0
		Or Eax, Eax
		Jz @F
		Invoke RSSetSelection, [Esi].EDITCHILD.chrPos.lMin, [Esi].EDITCHILD.chrPos.lMin, 0
		Invoke RSSendCommandMessage, EN_CHANGE
@@:		Cmp uMsg, WM_COPY
		Jne L2
		Invoke RSSendMessage, [Ebx].EDITPARENT.hWndParent, RSM_UPDATEEDITFUNCTIONS, 0, 0
		Jmp L2
	.ElseIf uMsg == WM_PASTE
		.If ![Ebx].EDITPARENT.bReadOnly
			Invoke SendMessage, [Ebx].EDITPARENT.hWnd, EM_CANPASTE, (-1), 0
			.If Eax
				.If ([Ebx].EDITPARENT.bTextUnicode)
					Invoke RSPasteText, hWnd, CF_UNICODETEXT
					Or Eax, Eax
					Jnz L2
					Mov Eax, CF_TEXT
					Call CheckOtherFormats
				.Else
					Invoke RSPasteText, hWnd, CF_TEXT
					Or Eax, Eax
					Jnz L2
					Mov Eax, CF_UNICODETEXT
					Call CheckOtherFormats
				.EndIf
			.EndIf
		.EndIf
		Jmp L2
	.ElseIf uMsg == EM_REDO
		Invoke SendMessage, hWnd, EM_CANREDO, 0, 0
		.If Eax
			Invoke RSRedo
		.EndIf
		Jmp L4
	.ElseIf uMsg == RSM_REDRAWEDITOR
		Mov [Esi].EDITCHILD.lPaint, PAINT_ALL
		Invoke RSInvalidateEditor, hWnd, TRUE
		Jmp L4
	.ElseIf uMsg == RSM_REPLACESELECTION
		Xor Edi, Edi
		Invoke RSGetTextLength, lParam
		Or Eax, Eax
		Jz @F
		Inc Eax
		Invoke RSGetBytes, Eax
		Invoke VirtualAlloc, 0, Eax, MEM_COMMIT, PAGE_READWRITE
		Mov Edi, Eax
		Invoke RSClipboardToText, Edi, lParam
@@:		Invoke RSReplaceSelection, Edi, 0
		Push Eax
		Or Eax, Eax
		Jz @F
		.If wParam
			Invoke RSSetSelection, [Esi].EDITCHILD.chrPos.lMin, [Esi].EDITCHILD.chrPos.lMax, 0
			Invoke RSSendCommandMessage, EN_CHANGE
		.EndIf
@@:		Or Edi, Edi
		Jz @F
		Invoke VirtualFree, Edi, 0, MEM_RELEASE
@@:		Pop Eax
		Jmp L4
	.ElseIf uMsg == EM_SCROLL
		Invoke SendMessage, hWnd, WM_VSCROLL, wParam, [Esi].EDITCHILD.hWndVScroll
		Jmp L4
	.ElseIf uMsg == RSM_SELECTALLTEXT
		Mov [Esi].EDITCHILD.lPaint, PAINT_ALL
		Invoke RSSetSelection, 0, [Ebx].EDITPARENT.lMaxIndex, 0
		Jmp L2
	.ElseIf uMsg == RSM_SETBACKCOLOR
		Invoke RSGetRealColor, lParam
		Mov [Ebx].EDITPARENT.crBackColor, Eax
		.If wParam
			Invoke RSSetEditorColors
		.EndIf
		Jmp L4
	.ElseIf uMsg == RSM_SETBACKMARGIN
		Invoke RSGetRealColor, lParam
		Mov [Ebx].EDITPARENT.crBackMargin, Eax
		.If wParam
			Invoke RSSetEditorColors
		.EndIf
		Jmp L4
	.ElseIf uMsg == RSM_SETBACKSELECT
		Invoke RSGetRealColor, lParam
		Mov [Ebx].EDITPARENT.crBackSelect, Eax
		.If wParam
			Invoke RSSetEditorColors
		.EndIf
		Jmp L4
	.ElseIf uMsg == RSM_SETEVENTMASK
		Mov Eax, wParam
		Xchg [Ebx].EDITPARENT.dwEventMask, Eax
		Jmp L4
	.ElseIf uMsg == RSM_SETHIDESELECTION || uMsg == EM_HIDESELECTION
		Mov Eax, wParam
		Mov [Esi].EDITCHILD.bNoSelection, Eax
		Mov [Esi].EDITCHILD.lPaint, PAINT_ALL
		Invoke RSRedrawEditor, hWnd, TRUE
		Jmp L4
	.ElseIf uMsg == RSM_SETINDENT
		Invoke RSGetLineFromChar, [Esi].EDITCHILD.chrPos.lMin
		Mov Edx, Eax
		Invoke RSGetLineFromChar, [Esi].EDITCHILD.chrPos.lMax
		Mov lTemp, Eax
		Mov Ecx, Eax
		Invoke RSGetLineIndex, Eax
		.If Ecx && [Esi].EDITCHILD.chrPos.lMax == Eax
			Dec Ecx
		.EndIf
		Invoke RSIsBlockEditable, Edx, Ecx
		.If Eax
			.If lTemp == Edx
				Mov lTemp, FALSE
				Push [Esi].EDITCHILD.chrSel.lMin
				Push [Esi].EDITCHILD.chrSel.lMax
				Invoke RSGetLineIndex, Edx
				.If wParam
					Shl Edx, 4
					Add Edx, [Ebx].EDITPARENT.lpLinesPointer
					Mov Ecx, [Edx].LINE.lpszText
					.If (SDWord Ptr [Edx].LINE.lLength > 0 && Word Ptr [Ecx] == VK_TAB)
						Inc Eax
						Invoke RSSetPosition, Eax, Eax
						Invoke RSOnChar, [Esi].EDITCHILD.hWnd, VK_BACK, 0
						Mov lTemp, TRUE
						Mov Eax, (-1)
					.Else
						Xor Eax, Eax
					.EndIf
				.Else
					Invoke RSSetPosition, Eax, Eax
					Invoke RSOnChar, [Esi].EDITCHILD.hWnd, VK_TAB, 0
					Mov lTemp, TRUE
					Mov Eax, 1
				.EndIf
				Pop Ecx
				Pop Edx
				Add Ecx, Eax
				Add Edx, Eax
				Invoke RSSetSelection, Edx, Ecx, 0
				Mov Eax, lTemp
			.Else
				Invoke RSGetLineIndex, Edx
				Mov [Esi].EDITCHILD.chrPos.lMin, Eax
				Invoke RSGetLineIndex, lTemp
				.If Eax < SDWord Ptr [Esi].EDITCHILD.chrPos.lMax
					Mov Ecx, lTemp
					.If Ecx < SDWord Ptr [Ebx].EDITPARENT.lLines
						Inc lTemp
						Invoke RSGetLineIndex, lTemp
					.EndIf
				.EndIf
				Mov [Esi].EDITCHILD.chrPos.lMax, Eax

				Mov Eax, [Esi].EDITCHILD.chrSel.lMax
				.If Eax < SDWord Ptr [Esi].EDITCHILD.chrSel.lMin
					Invoke RSSetPosition, [Esi].EDITCHILD.chrPos.lMax, [Esi].EDITCHILD.chrPos.lMin
				.Else
					Invoke RSSetPosition, [Esi].EDITCHILD.chrPos.lMin, [Esi].EDITCHILD.chrPos.lMax
				.EndIf
				Invoke RSAddRemoveChar, Edx, lTemp, wParam
			.EndIf
		.EndIf
		Jmp L4
	.ElseIf uMsg == RSM_SETLINESAVEFORMAT
		Mov Eax, (-1)
		.If wParam >= RSC_CR_LF && wParam >= RSC_LF
			Mov Eax, wParam
			Xchg RSlLineFormat, Eax
		.EndIf
		Jmp L4
	.ElseIf uMsg == RSM_SETLOCKEDBACKCOLOR
		Invoke RSGetRealColor, lParam
		Mov [Ebx].EDITPARENT.crBackLocked, Eax
		.If wParam
			Invoke RSSetEditorColors
		.EndIf
		Jmp L4
	.ElseIf uMsg == RSM_SETLOCKEDTEXTCOLOR
		Invoke RSGetRealColor, lParam
		Mov [Ebx].EDITPARENT.crTextLocked, Eax
		.If wParam
			Invoke RSSetEditorColors
		.EndIf
		Jmp L4
	.ElseIf uMsg == RSM_SETREDRAWFLAG
		Mov Eax, wParam
		Mov [Ebx].EDITPARENT.bRedraw, Eax
		.If Eax
			.If lParam
				Mov [Esi].EDITCHILD.lPaint, PAINT_ALL
				Invoke RSSetSelection, [Esi].EDITCHILD.chrSel.lMin, [Esi].EDITCHILD.chrSel.lMax, 0
			.EndIf
		.EndIf
		Jmp L4
	.ElseIf uMsg == RSM_SETSELECTION || uMsg == EM_SETSEL
		Mov [Esi].EDITCHILD.lPaint, PAINT_ALL
		Mov Eax, wParam
		Cmp Eax, 0
		Jge @F
		Xor Eax, Eax
@@:		Mov [Esi].EDITCHILD.chrPos.lMin, Eax
		Mov Eax, lParam
		Cmp Eax, 0
		Jge @F
		Xor Eax, Eax
@@:		Cmp Eax, [Ebx].EDITPARENT.lMaxIndex
		Jle @F
		Mov Eax, [Ebx].EDITPARENT.lMaxIndex
@@:		Mov [Esi].EDITCHILD.chrPos.lMax, Eax
		Invoke RSSetSelection, [Esi].EDITCHILD.chrPos.lMin, Eax, 0
		Jmp L4
	.ElseIf uMsg == RSM_SETTABSIZE
		Mov [Esi].EDITCHILD.lPaint, PAINT_ALL
		Invoke RSInvalidateEditor, hWnd, TRUE
		Jmp L4
	.ElseIf uMsg == RSM_SETTEXTCOLOR
		Invoke RSGetRealColor, lParam
		Mov [Ebx].EDITPARENT.crTextColor, Eax
		.If wParam
			Invoke RSSetEditorColors
		.EndIf
		Jmp L4
	.ElseIf uMsg == RSM_SETTEXTSELECT
		Invoke RSGetRealColor, lParam
		Mov [Ebx].EDITPARENT.crTextSelect, Eax
		.If wParam
			Invoke RSSetEditorColors
		.EndIf
		Jmp L4
	.ElseIf uMsg == RSM_SETTOPLINE
		Invoke RSSetTopLine, wParam, TRUE
		Jmp L4
	.ElseIf uMsg == RSM_SKIPEMPTYLINE
		Mov Edx, [Esi].EDITCHILD.lCurLine
		Shl Edx, 4
		Add Edx, [Ebx].EDITPARENT.lpLinesPointer
		Mov Ecx, [Edx].LINE.lLength
		Mov Edx, [Edx].LINE.lpszText
		.While (Ecx > SDWord Ptr 0)
			.If [Ebx].EDITPARENT.bTextUnicode
				Mov Ax, Word Ptr [Edx]
				Add Edx, 2
			.Else
				Xor Ah, Ah
				Mov Al, Byte Ptr [Edx]
				Inc Edx
			.EndIf
			Cmp Ax, VK_RETURN
			Je @F
			.If Ax != VK_SPACE && Ax != VK_TAB
				Jmp L4
			.EndIf
			Dec Ecx
		.EndW
@@:		Mov Eax, [Esi].EDITCHILD.lCurLine
		Inc Eax
		Invoke RSGetLineIndex, Eax
		Cmp Eax, (-1)
		Je L4
		Invoke RSSetSelection, Eax, Eax, 0
		Jmp L4
	.ElseIf uMsg == RSM_TOGGLEBOOKMARK
		Invoke RSToggleBookmark, hWnd, TRUE
		Jmp L4
	.ElseIf uMsg == RSM_UNLOCKLINES
		Invoke RSUnlockLines, wParam, lParam
		Jmp L4
	.ElseIf uMsg == WM_UNDO || uMsg == EM_UNDO
		Invoke SendMessage, hWnd, EM_CANUNDO, 0, 0
		.If Eax
			Invoke RSUndo
		.EndIf
		Jmp L4
	.ElseIf uMsg == WM_TIMER
		Mov Eax, hWnd
		.If Eax == [Ebx].EDITPARENT.hWndTimer
			Cmp [Ebx].EDITPARENT.lVScrollCounter, 0
			Jle @F
			Dec [Ebx].EDITPARENT.lVScrollCounter
			Jmp L2
@@:			Mov lTemp, MK_LBUTTON
			Invoke GetKeyState, VK_CONTROL
			And Eax, 00008000H
			Jz @F
			Or lTemp, MK_CONTROL
@@:			Invoke GetKeyState, VK_SHIFT
			And Eax, 00008000H
			Jz @F
			Or lTemp, MK_SHIFT
@@:			Invoke RSOnTimer, hWnd, wParam, lTemp
		.EndIf
		Jmp L2
	.ElseIf uMsg == WM_WINDOWPOSCHANGED
		Mov [Esi].EDITCHILD.lPaint, PAINT_ALL
		Invoke GetClientRect, hWnd, Addr [Esi].EDITCHILD.rc
		Invoke InvalidateRect, hWnd, NULL, FALSE
		.If [Esi].EDITCHILD.hWndVScroll != NULL
			Cmp [Esi].EDITCHILD.rc.right, 0
			Jle @F
			Invoke RSGetChildWindowPos, hWnd, Addr rc
			.If [Esi].EDITCHILD.hWndVScroll
				Mov Eax, [Esi].EDITCHILD.rc.right
				Mov Eax, RSlVScrollWidth
				Sub [Esi].EDITCHILD.rc.right, Eax
				Mov Edx, rc.bottom
				Mov Ecx, rc.top
				Sub Edx, Ecx
				Mov Eax, hWnd
				.If Eax == [Ebx].EDITPARENT.Mirror.hWnd
					Xor Ecx, Ecx
					Mov Edx, [Esi].EDITCHILD.rc.bottom
					Sub Edx, [Esi].EDITCHILD.rc.top
				.Else
					.If [Ebx].EDITPARENT.Mirror.hWnd == NULL && [Ebx].EDITPARENT.hWndSplitter
						Sub Edx, 6
						Add Ecx, 6
					.EndIf
				.EndIf
				Invoke MoveWindow, [Esi].EDITCHILD.hWndVScroll, [Esi].EDITCHILD.rc.right, Ecx, RSlVScrollWidth, Edx, TRUE
			.EndIf
		.EndIf
@@:		Mov RSsci.fMask, SIF_ALL
		Invoke GetScrollInfo, [Esi].EDITCHILD.hWndVScroll, SB_CTL, Addr RSsci
		Mov Ecx, [Ebx].EDITPARENT.szFont.y
		.If Ecx
			Mov Eax, [Esi].EDITCHILD.rc.bottom
			Xor Edx, Edx
			Div Ecx
			Mov [Esi].EDITCHILD.lVScrollPage, Eax
			Mov RSsci.nPage, Eax
		.EndIf
		Cmp Eax, [Ebx].EDITPARENT.lLines
		Jl @F
		Mov [Esi].EDITCHILD.lTopLine, 0
		Mov [Esi].EDITCHILD.lTopLineIndex, 0
		Mov RSsci.nPos, 0
		Mov RSsci.nTrackPos, 0
		Or RSsci.fMask, SIF_DISABLENOSCROLL
		Mov Eax, [Ebx].EDITPARENT.lLines
		Mov RSsci.nMax, Eax
		Invoke SetScrollInfo, [Esi].EDITCHILD.hWndVScroll, SB_CTL, Addr RSsci, TRUE
@@:		Invoke RSCheckScrollWidth
		Invoke GetCapture
		Mov Ecx, SCROLL_VERT
		.If Eax != [Ebx].EDITPARENT.hWndSplitter
			Mov Ecx, (SCROLL_HORZ Or SCROLL_VERT)
		.EndIf
		Invoke RSUpdateScrollBars, Ecx
		Mov Eax, [Ebx].EDITPARENT.lLines
		Inc Eax
		Sub Eax, [Esi].EDITCHILD.lVScrollPage
		Cmp Eax, [Esi].EDITCHILD.lTopLine
		Jg @F
		Mov Eax, [Ebx].EDITPARENT.lLines
		Inc Eax
		Sub Eax, [Esi].EDITCHILD.lVScrollPage
		Sub Eax, [Esi].EDITCHILD.lTopLine
		Jz @F
		Invoke RSScroll, Eax, 0
@@:		Mov Eax, hWnd
		.If Eax == [Ebx].EDITPARENT.hWndFocus
			Invoke RSSetCaret
		.EndIf
		Jmp L2
	.ElseIf uMsg == WM_DESTROY
		.If [Esi].EDITCHILD.hWndVScroll != NULL
			Invoke DestroyWindow, [Esi].EDITCHILD.hWndVScroll
		.EndIf
	.EndIf
	Invoke DefWindowProc, hWnd, uMsg, wParam, lParam
L4:	Ret

CheckOtherFormats:
	Invoke RSPasteText, hWnd, Eax
	.If Eax == 0
		Invoke RSPasteText, hWnd, CF_OEMTEXT
	.EndIf
	Retn
RSEditorChildProc EndP

RSEditorSplitterProc Proc Uses Ebx Edi Esi hWnd:HWND, uMsg:UINT, wParam:WPARAM, lParam:LPARAM
	Invoke GetParent, hWnd
	Invoke GetWindowLong, Eax, GWL_EDITORDATA
	Mov Ebx, Eax
	.If uMsg == WM_SETCURSOR
		Invoke SetClassLong, hWnd, GCL_HCURSOR, RShSizeNS
		Push Eax
		Invoke DefWindowProc, hWnd, uMsg, wParam, lParam
		Pop Eax
		Invoke SetClassLong, hWnd, GCL_HCURSOR, Eax
		Mov Eax, TRUE
		Jmp L4
	.ElseIf uMsg == WM_LBUTTONDOWN
		.If (wParam & MK_LBUTTON)
			Invoke SetCapture, hWnd
			Invoke RSGetChildWindowPos, hWnd, Addr RSrect
			Invoke MoveWindow, hWnd, 0, RSrect.top, [Ebx].EDITPARENT.rc.right, 6, TRUE
			.If [Ebx].EDITPARENT.Mirror.hWnd == NULL
				Invoke GetFocus
				Push Eax
				Invoke GetWindowLong, [Ebx].EDITPARENT.Editor.hWnd, GWL_EXSTYLE
				Mov Edi, Eax
				Invoke GetWindowLong, [Ebx].EDITPARENT.Editor.hWnd, GWL_STYLE
				Mov Edx, Eax
				Mov Ecx, [Ebx].EDITPARENT.rc.bottom
				Sub Ecx, RSrect.bottom
				Invoke CreateWindowEx, Edi, Addr RSszEditorChildClass, NULL, Edx, 0, RSrect.bottom, [Ebx].EDITPARENT.rc.right, Ecx, [Ebx].EDITPARENT.hWnd, NULL, RShInst, Addr lParam
				Invoke SetFocus, Eax
				Pop Eax
				Invoke SetFocus, Eax
			.EndIf
L2:			Xor Eax, Eax
			Jmp L4
		.EndIf
	.ElseIf uMsg == WM_MOUSEMOVE
		.If (wParam & MK_LBUTTON)
			HiWord lParam
			Cwde
			Cdq
			Add RSrect.top, Eax
			.If (SDWord Ptr RSrect.top < 0)
				Mov RSrect.top, 0
			.Else
				Mov Eax, [Ebx].EDITPARENT.rc.bottom
				Sub Eax, RSlHScrollHeight
				Sub Eax, 6
				.If Eax < SDword Ptr RSrect.top
					Mov RSrect.top, Eax
				.EndIf
			.EndIf
			Invoke SetFocus, [Ebx].EDITPARENT.Editor.hWnd
			Invoke MoveWindow, hWnd, 0, RSrect.top, [Ebx].EDITPARENT.rc.right, 6, TRUE
			Invoke RSResizeChilds, TRUE
			Jmp L2
		.EndIf
	.ElseIf uMsg == WM_LBUTTONUP
		Invoke GetCapture
		.If Eax == hWnd
			Mov Eax, RSlHScrollHeight
			.If SDWord Ptr RSrect.top <= Eax
				Push [Ebx].EDITPARENT.Editor.hWnd
				Push [Ebx].EDITPARENT.Editor.hWndVScroll
				Lea Edx, [Ebx].EDITPARENT.Mirror
				Lea Edi, [Ebx].EDITPARENT.Editor
				Invoke RtlMoveMemory, Edi, Edx, SizeOf EDITCHILD
				Pop [Ebx].EDITPARENT.Editor.hWndVScroll
				Pop [Ebx].EDITPARENT.Editor.hWnd
				Mov Esi, Edi
@@:				Push [Esi].EDITCHILD.lTopLine
				Invoke RSDestroyMirror
				Mov [Ebx].EDITPARENT.bRedraw, FALSE
				Pop Eax
				Invoke RSSetTopLine, Eax, FALSE
				Mov [Ebx].EDITPARENT.bRedraw, TRUE
				Invoke RSRedrawEditor, [Esi].EDITCHILD.hWnd, FALSE
				Invoke RSSendNotifyMessage, EN_SELCHANGE
			.Else
				Invoke RSGetEditorDataPointer
				Mov Esi, Eax
				Mov Eax, [Ebx].EDITPARENT.rc.bottom
				Mov Ecx, RSlHScrollHeight
				Shl Ecx, 1
				Sub Eax, Ecx
				Sub Eax, 6
				Cmp RSrect.top, Eax
				Jge @B
			.EndIf
		.EndIf
		Invoke ReleaseCapture
		Jmp L2
	.ElseIf uMsg == WM_RBUTTONDOWN
		Invoke SetFocus, [Ebx].EDITPARENT.hWnd
	.ElseIf uMsg == WM_LBUTTONDBLCLK
		Invoke RSSendMessage, hWnd, WM_LBUTTONDOWN, wParam, lParam
	.EndIf
	Invoke GetWindowLong, hWnd, GWL_USERDATA
	Invoke CallWindowProc, Eax, hWnd, uMsg, wParam, lParam
L4:	Ret
RSEditorSplitterProc EndP

RSEditorHScrollProc Proc Uses Ebx Edi Esi hWnd:HWND, uMsg:UINT, wParam:WPARAM, lParam:LPARAM
	.If uMsg == WM_RBUTTONDOWN
		Invoke GetParent, hWnd
		Invoke SetFocus, Eax
	.EndIf
	Invoke GetWindowLong, hWnd, GWL_USERDATA
	Invoke CallWindowProc, Eax, hWnd, uMsg, wParam, lParam
@@:	Ret
RSEditorHScrollProc EndP

;On enter Ebx = Pointer to editor parent's data, Edx = Pointer to line's data
RSAddCharsToLine Proc Private Uses Ecx Edi Esi lpszChars:LPSTR, lLength:LONG, lpChrInf:LPLONG
	Cmp lLength, 0
	Jle L2
	Mov Edi, lpChrInf
	Mov Eax, [Edx].LINE.lLength
	Add Eax, lLength
	Cmp Eax, [Edx].LINE.lMaxLength
	Jl @F
	Inc Eax
	Sub Eax, [Edx].LINE.lMaxLength
	Invoke RSResizeLine, [Edi].RSSCHARINFO.lLine, Eax
@@:	Mov Eax, lpszChars
	Cmp [Ebx].EDITPARENT.bTextUnicode, FALSE
	Jne AddCharsToLineW
	Cmp Byte Ptr [Eax], VK_RETURN
	Jne @F
	Cmp lLength, 1
	Jne @F
	Mov Ecx, [Edi].RSSCHARINFO.lLineOffset
	Add Ecx, [Edx].LINE.lpszText
	Mov Eax, lpszChars
	Mov Al, Byte Ptr [Eax]
	Mov Byte Ptr [Ecx], Al
	Inc [Edx].LINE.lLength
	Ret
@@:	Mov Ecx, [Edx].LINE.lpszText
	Add Ecx, [Edi].RSSCHARINFO.lLineOffset
	Mov Esi, Ecx
	Add Esi, lLength
	Mov Eax, [Edx].LINE.lLength
	Sub Eax, [Edi].RSSCHARINFO.lLineOffset
	Jle @F
	Invoke RSMoveChars, Esi, Ecx, Eax
@@:	Mov Esi, lpszChars
	Mov Eax, [Edx].LINE.lLength
	Add Eax, lLength
	Mov [Edx].LINE.lLength, Eax
@@:	Mov Al, [Esi]
	Mov [Ecx], Al
	Inc Ecx
	Inc Esi
	Dec lLength
	Jnz @B
	Mov Eax, [Edx].LINE.lpszText
	Add Eax, [Edx].LINE.lLength
	Cmp Byte Ptr [Eax - 1], VK_RETURN
	Je L2
	Mov Byte Ptr [Eax], 0
L2:	Ret

AddCharsToLineW:
	Cmp Word Ptr [Eax], VK_RETURN
	Jne @F
	Cmp lLength, 1
	Jne @F
	Invoke RSGetBytes, [Edi].RSSCHARINFO.lLineOffset
	Mov Ecx, Eax
	Add Ecx, [Edx].LINE.lpszText
	Mov Eax, lpszChars
	Mov Ax, Word Ptr [Eax]
	Mov Word Ptr [Ecx], Ax
	Inc [Edx].LINE.lLength
	Ret
@@:	Mov Ecx, [Edx].LINE.lpszText
	Mov Eax, [Edi].RSSCHARINFO.lLineOffset
	Shl Eax, 1
	Add Ecx, Eax
	Mov Esi, lLength
	Shl Esi, 1
	Add Esi, Ecx
	Mov Eax, [Edx].LINE.lLength
	Sub Eax, [Edi].RSSCHARINFO.lLineOffset
	Jle @F
	Invoke RSMoveChars, Esi, Ecx, Eax
@@:	Mov Esi, lpszChars
	Mov Eax, [Edx].LINE.lLength
	Add Eax, lLength
	Mov [Edx].LINE.lLength, Eax
@@:	Mov Ax, Word Ptr [Esi]
	Mov Word Ptr [Ecx], Ax
	Add Ecx, 2
	Add Esi, 2
	Dec lLength
	Jnz @B
	Mov Eax, [Edx].LINE.lLength
	Shl Eax, 1
	Add Eax, [Edx].LINE.lpszText
	Cmp Word Ptr [Eax - 2], VK_RETURN
	Je L2
	Mov Word Ptr [Eax], 0
	Jmp L2
RSAddCharsToLine EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to editor child's data
RSAddRemoveChar Proc Private Uses Ecx Edx Edi lFirstLine:LONG, lLastLine:LONG, bRemove:BOOL
	Local bRevSel:BOOL, bReturn:BOOL
	Local lLines:LONG, dwEventMask:DWord

	Xor Eax, Eax
	Mov bRevSel, Eax
	Mov bReturn, Eax
	Mov Ecx, lLastLine
	Sub Ecx, lFirstLine
	Jg @F
L2:	Ret

@@:	Mov lLines, Ecx
	Cmp [Ebx].EDITPARENT.bTextUnicode, FALSE
	Jne AddRemoveCharW
	Invoke RSCheckBufferSize, Ecx, RSC_TEXT
	Mov Eax, [Esi].EDITCHILD.chrSel.lMax
	.If Eax < SDWord Ptr [Esi].EDITCHILD.chrSel.lMin
		Mov bRevSel, TRUE
	.EndIf
	Mov Eax, [Esi].EDITCHILD.chrPos.lMax
	Sub Eax, [Esi].EDITCHILD.chrPos.lMin
	Add Eax, Ecx
	Inc Eax
	Shr Eax, 2
	Inc Eax
	Shl Eax, 2
	Invoke	VirtualAlloc, 0, Eax, MEM_COMMIT, PAGE_READWRITE
	Mov Edi, Eax
	Mov Eax, [Ebx].EDITPARENT.dwEventMask
	Mov dwEventMask, Eax
	Mov Eax, RSV_SELCHANGE
	Not Eax
	And Eax, dwEventMask
	Mov [Ebx].EDITPARENT.dwEventMask, Eax
	Invoke SendMessage, [Esi].EDITCHILD.hWnd, WM_SETREDRAW, FALSE, 0
	Mov Ecx, Edi
	Mov Edx, lFirstLine
	Shl Edx, 4
	Add Edx, [Ebx].EDITPARENT.lpLinesPointer
	Push Esi
	.If bRemove
		.While SDWord Ptr lLines > 0
			Mov Esi, [Edx].LINE.lpszText
			Mov Eax, [Edx].LINE.lLength
			.If (Byte Ptr [Esi] == VK_TAB || Byte Ptr [Esi] == ' ')
				Inc Esi
				Dec Eax
				Mov bReturn, TRUE
			.EndIf
			Invoke RSMoveChars, Ecx, Esi, Eax
			Add Ecx, Eax
			Add Edx, SizeOf LINE
			Dec lLines
		.EndW
	.Else
		Mov bReturn, TRUE
		.While SDWord Ptr lLines > 0
			Mov Esi, [Edx].LINE.lpszText
			.If Byte Ptr [Esi] != VK_RETURN || [Edx].LINE.lLength == 0
				Mov Byte Ptr [Ecx], VK_TAB
				Inc Ecx
			.EndIf
			Invoke RSMoveChars, Ecx, Esi, [Edx].LINE.lLength
			Invoke RSGetBytes, Eax
			Add Ecx, Eax
			Add Edx, SizeOf LINE
			Dec lLines
		.EndW
	.EndIf
L4:	Pop Esi
	.If bReturn
		Invoke RSReplaceSelection, Edi, 0
	.EndIf
	Invoke VirtualFree, Edi, 0, MEM_RELEASE
	Mov Eax, dwEventMask
	Mov [Ebx].EDITPARENT.dwEventMask, Eax
	Invoke SendMessage, [Esi].EDITCHILD.hWnd, WM_SETREDRAW, TRUE, 0
	Invoke RSGetLineIndex, lFirstLine
	Mov Ecx, Eax
	Invoke RSGetLineIndex, lLastLine
	Mov Edx, Eax
	.If bRevSel
		Xchg Ecx, Edx
	.EndIf
	Invoke RSSetSelection, Ecx, Edx, 0
	Invoke RSGetLineIndex, [Esi].EDITCHILD.lTopLine
	Mov [Esi].EDITCHILD.lTopLineIndex, Eax
	Invoke RSSendCommandMessage, EN_CHANGE
	Mov [Esi].EDITCHILD.lPaint, PAINT_ALL
	Invoke RSInvalidateEditor, [Esi].EDITCHILD.hWnd, TRUE
	Return bReturn

AddRemoveCharW:
	Shl Ecx, 1
	Invoke RSCheckBufferSize, Ecx, RSC_TEXT
	Mov Eax, [Esi].EDITCHILD.chrSel.lMax
	.If Eax < SDWord Ptr [Esi].EDITCHILD.chrSel.lMin
		Mov bRevSel, TRUE
	.EndIf
	Mov Eax, [Esi].EDITCHILD.chrPos.lMax
	Sub Eax, [Esi].EDITCHILD.chrPos.lMin
	Shl Eax, 1
	Add Eax, Ecx
	Inc Eax
	Shr Eax, 2
	Inc Eax
	Shl Eax, 2
	Invoke	VirtualAlloc, 0, Eax, MEM_COMMIT, PAGE_READWRITE
	Mov Edi, Eax
	Mov Eax, [Ebx].EDITPARENT.dwEventMask
	Mov dwEventMask, Eax
	Mov Eax, RSV_SELCHANGE
	Not Eax
	And Eax, dwEventMask
	Mov [Ebx].EDITPARENT.dwEventMask, Eax
	Invoke SendMessage, [Esi].EDITCHILD.hWnd, WM_SETREDRAW, FALSE, 0
	Mov Ecx, Edi
	Mov Edx, lFirstLine
	Shl Edx, 4
	Add Edx, [Ebx].EDITPARENT.lpLinesPointer
	Push Esi
	.If bRemove
		.While SDWord Ptr lLines > 0
			Mov Esi, [Edx].LINE.lpszText
			Mov Eax, [Edx].LINE.lLength
			.If (Word Ptr [Esi] == VK_TAB || Word Ptr [Esi] == ' ')
				Add Esi, 2
				Dec Eax
				Mov bReturn, TRUE
			.EndIf
			Invoke RSMoveChars, Ecx, Esi, Eax
			Shl Eax, 1
			Add Ecx, Eax
			Add Edx, SizeOf LINE
			Dec lLines
		.EndW
	.Else
		Mov bReturn, TRUE
		.While SDWord Ptr lLines > 0
			Mov Esi, [Edx].LINE.lpszText
			.If Word Ptr [Esi] != VK_RETURN || [Edx].LINE.lLength == 0
				Mov Word Ptr [Ecx], VK_TAB
				Add Ecx, 2
			.EndIf
			Invoke RSMoveChars, Ecx, Esi, [Edx].LINE.lLength
			Invoke RSGetBytes, Eax
			Add Ecx, Eax
			Add Edx, SizeOf LINE
			Dec lLines
		.EndW
	.EndIf
	Jmp L4
RSAddRemoveChar EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to editor child's data
RSAdjustMirrorDelete Proc Private Uses Ecx Esi lFirstLine:LONG, lLastLine:LONG, lMin:LONG, lMax:LONG, bScrollBars:BOOL
	Mov Eax, [Ebx].EDITPARENT.Editor.hWnd
	.If Eax == [Ebx].EDITPARENT.hWndFocus
		Lea Esi, [Ebx].EDITPARENT.Mirror
	.Else
		Lea Esi, [Ebx].EDITPARENT.Editor
	.EndIf
	Mov Ecx, lLastLine
	.If Ecx == lFirstLine
		Mov Eax, [Esi].EDITCHILD.lTopLine
		Jmp @F
	.Else
		Mov Eax, lFirstLine
		.If SDWord Ptr [Esi].EDITCHILD.lTopLine >= Ecx
			Sub Ecx, Eax
			Mov Eax, [Esi].EDITCHILD.lTopLine
			Sub Eax, Ecx
			Jmp @F
		.ElseIf SDWord Ptr [Esi].EDITCHILD.lTopLine >= Eax
@@:			Invoke RSSetTopLine, Eax, FALSE
		.EndIf
	.EndIf
	Mov Ecx, lMin
	Mov Eax, lMax
	.If Eax <= SDWord Ptr [Esi].EDITCHILD.chrPos.lMin
		Sub Eax, Ecx
		Sub [Esi].EDITCHILD.chrPos.lMin, Eax
		Sub [Esi].EDITCHILD.chrPos.lMax, Eax
		Sub [Esi].EDITCHILD.chrSel.lMin, Eax
		Sub [Esi].EDITCHILD.chrSel.lMax, Eax
		Invoke RSSetPosition, [Esi].EDITCHILD.chrSel.lMin, [Esi].EDITCHILD.chrSel.lMax
	.ElseIf Ecx <= SDWord Ptr [Esi].EDITCHILD.chrPos.lMin || Ecx <= SDWord Ptr [Esi].EDITCHILD.chrPos.lMax
		Mov [Esi].EDITCHILD.chrPos.lMin, Ecx
		Mov [Esi].EDITCHILD.chrPos.lMax, Ecx
		Mov [Esi].EDITCHILD.chrSel.lMin, Ecx
		Mov [Esi].EDITCHILD.chrSel.lMax, Ecx
		Invoke RSSetPosition, Ecx, Ecx
	.EndIf
	.If bScrollBars
		Invoke RSUpdateScrollBars, (SCROLL_HORZ Or SCROLL_VERT)
	.EndIf
	Ret
RSAdjustMirrorDelete EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to editor child's data
RSAdjustMirrorInsert Proc Private Uses Esi lFirstLine:LONG, lPos:LONG, lChars:LONG, lLines:LONG
	Mov Eax, [Ebx].EDITPARENT.Editor.hWnd
	.If Eax == [Ebx].EDITPARENT.hWndFocus
		Lea Esi, [Ebx].EDITPARENT.Mirror
	.Else
		Lea Esi, [Ebx].EDITPARENT.Editor
	.EndIf
	Mov Eax, lFirstLine
	.If Eax <= SDWord Ptr [Esi].EDITCHILD.lTopLine
		Mov Eax, [Esi].EDITCHILD.lTopLine
		Add Eax, lLines
		Invoke RSSetTopLine, Eax, FALSE
	.EndIf
	Mov Eax, lPos
	.If Eax <= SDWord Ptr [Esi].EDITCHILD.chrPos.lMin
		Mov Eax, lChars
		Add [Esi].EDITCHILD.chrPos.lMin, Eax
		Add [Esi].EDITCHILD.chrPos.lMax, Eax
		Add [Esi].EDITCHILD.chrSel.lMin, Eax
		Add [Esi].EDITCHILD.chrSel.lMax, Eax
		Invoke RSSetPosition, [Esi].EDITCHILD.chrSel.lMin, [Esi].EDITCHILD.chrSel.lMax
	.EndIf
	Invoke RSUpdateScrollBars, (SCROLL_HORZ Or SCROLL_VERT)
	Ret
RSAdjustMirrorInsert EndP

;On enter Ebx = Pointer to editor parent's data
RSAllocateEditorMemory Proc Private Uses Ecx Edi Edx lTextLength:DWord
	Invoke RSReleaseEditorMemory
	Mov Eax, lTextLength
	Xor Edx,Edx
	Div RSdwPageSize
	Inc Eax
	Mul RSdwPageSize
	Mov [Ebx].EDITPARENT.lMaxTextLength, Eax
	Invoke VirtualAlloc, 0, Eax, MEM_COMMIT, PAGE_READWRITE
	.If Eax
		Mov [Ebx].EDITPARENT.lpTextPointer, Eax
	.Else
		Mov [Ebx].EDITPARENT.lMaxTextLength, 0
	.EndIf

	.If Eax
		Mov Edi, [Ebx].EDITPARENT.lMaxTextLength
		Or Edi, Edi
		Jz @F
		Sub [Ebx].EDITPARENT.lMaxTextLength, 4
@@:		Shr Edi, 3
		Cmp Edi, RSdwPageSize
		Jnc @F
		Mov Edi, RSdwPageSize
@@:		Invoke VirtualAlloc, 0, Edi, MEM_COMMIT, PAGE_READWRITE
		.If Eax
			Mov [Ebx].EDITPARENT.lpLinesPointer, Eax
		.EndIf
		Shr Edi, 4
		Dec Edi
		Mov [Ebx].EDITPARENT.lMaxLines, Edi

		Invoke HeapCreate, 0, 0, 0
		Mov [Ebx].EDITPARENT.hHeap, Eax
		Mov Eax, [Ebx].EDITPARENT.lMaxTextLength
		Shr Eax, 2	;Divide by 4
		Invoke VirtualAlloc, 0, Eax, MEM_COMMIT, PAGE_READWRITE
		.If Eax
			Mov [Ebx].EDITPARENT.lpUndoPointer, Eax
			Shr Edi, 4
			Mov [Ebx].EDITPARENT.lMaxUndo, Edi
		.EndIf
		Mov [Ebx].EDITPARENT.lUndoCount, 0
		Mov [Ebx].EDITPARENT.lLastUndoCount, 0
	.EndIf
	Ret
RSAllocateEditorMemory EndP

;On enter Ebx = Pointer to editor parent's data
RSAllocateLineMemory Proc Private lpszTxt:LPSTR, lChars:LONG
	Xor Ecx, Ecx
	Mov Edx, lpszTxt
	Xor Eax, Eax
	Cmp [Ebx].EDITPARENT.bTextUnicode, FALSE
	Jne AllocateLineMemoryW
A2:	.While (Eax < SDWord Ptr lChars)
		.If (Byte Ptr [Edx + Eax] == VK_TAB)
			Call SetSpaces
			Inc Eax
			Jmp A2
		.EndIf
		Inc Ecx
		Inc Eax
	.EndW
	.If (SDWord Ptr Eax > Ecx)
		Mov Ecx, Eax
	.EndIf
	Add Ecx, 2
L2:	.If (Ecx > SDWord Ptr 2048)
		Push Ecx
		Invoke RSFreeLineMemory
		Pop Ecx
		Invoke VirtualAlloc, 0, Ecx, MEM_COMMIT, PAGE_READWRITE
		Mov [Ebx].EDITPARENT.lpszLine, Eax
	.Else
		Mov Eax, [Ebx].EDITPARENT.lpszBuffer
		Mov [Ebx].EDITPARENT.lpszLine, Eax
	.EndIf
	Ret

AllocateLineMemoryW:
	Shl lChars, 1
W2:	.While (Eax < SDWord Ptr lChars)
		.If (Word Ptr [Edx + Eax] == VK_TAB)
			Call SetSpaces
			Add Eax, 2
			Jmp W2
		.EndIf
		Add Ecx, 2
		Add Eax, 2
	.EndW
	.If (SDWord Ptr Eax > Ecx)
		Mov Ecx, Eax
	.EndIf
	Add Ecx, 4
	Jmp L2


SetSpaces:
	Push Eax
	Push Edx
	Mov Edx, Ecx
	Mov Eax, [Ebx].EDITPARENT.lTabSize
	Dec Eax
	And Edx, Eax
	Inc Eax
	Sub Eax, Edx
	Add Ecx, Eax
	Pop Edx
	Pop Eax
	Retn
RSAllocateLineMemory EndP

;On enter Ebx = Pointer to editor parent's data
RSAllocateMoreMemory Proc Private Uses Ecx Edx Edi Esi lCurrentBytes:LONG
	Mov Eax, lCurrentBytes
	Add Eax, [Ebx].EDITPARENT.lTabSize
	.If Eax >= SDWord Ptr [Ebx].EDITPARENT.lMaxTextLength
		Mov Esi, [Ebx].EDITPARENT.lpTextPointer
		Push Esi
		Xor Edx, Edx
		Div RSdwPageSize
		Add Eax, 2
		Mul RSdwPageSize
		Mov [Ebx].EDITPARENT.lMaxTextLength, Eax
		Sub [Ebx].EDITPARENT.lMaxTextLength, 4
		Invoke VirtualAlloc, 0, Eax, MEM_COMMIT, PAGE_READWRITE
		Mov Edi, Eax
		Mov [Ebx].EDITPARENT.lpTextPointer, Eax
		Mov Edx, [Ebx].EDITPARENT.lpLinesPointer
		Mov [Edx].LINE.lpszText, Edi
		Mov Ecx, lCurrentBytes
		.While Ecx
			.If [Ebx].EDITPARENT.bTextUnicode
				Mov Ax, Word Ptr [Esi]
				Mov Word Ptr [Edi], Ax
				Add Esi, 2
				Add Edi, 2
				.If Ax == VK_RETURN
					Add Edx, SizeOf LINE
					Mov [Edx].LINE.lpszText, Edi
					Mov [Ebx].EDITPARENT.lpszNextText, Edi
				.EndIf
				Sub Ecx, 2
			.Else
				Mov Al, Byte Ptr [Esi]
				Mov Byte Ptr [Edi], Al
				Inc Esi
				Inc Edi
				.If Al == VK_RETURN
					Add Edx, SizeOf LINE
					Mov [Edx].LINE.lpszText, Edi
					Mov [Ebx].EDITPARENT.lpszNextText, Edi
				.EndIf
				Dec Ecx
			.EndIf
		.EndW
		Pop Esi
		Invoke VirtualFree, Esi, 0, MEM_RELEASE
		Mov Eax, TRUE
		Jmp L2
	.EndIf
	Xor Eax, Eax
L2:	Ret
RSAllocateMoreMemory EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to editor child's data
RSCanDelete Proc Private
	Local ChrInfMin:RSSCHARINFO, ChrInfMax:RSSCHARINFO

	Invoke RSGetCharInfo, [Esi].EDITCHILD.chrPos.lMin, Addr ChrInfMin
	Invoke RSGetCharInfo, [Esi].EDITCHILD.chrPos.lMax, Addr ChrInfMax
	Invoke RSIsBlockEditable, ChrInfMin.lLine, ChrInfMax.lLine
	Ret
RSCanDelete EndP

;On enter Esi = Pointer to editor child's data
RSCenterSelection Proc Private Uses Ecx Edi lMin:LONG, lMax:LONG
	Invoke RSGetLineFromChar, lMax
	Mov Edi, Eax
	Invoke RSIsLineInClientArea, Eax
	Or Eax, Eax
	Jnz @F
	Mov Ecx, [Esi].EDITCHILD.lVScrollPage
	Shr Ecx, 1
	Sub Edi, Ecx
	Jl @F
	Sub Edi, [Esi].EDITCHILD.lTopLine
	Invoke RSScroll, Edi, 0
@@:	Xor Eax, Eax
	Sub Eax, [Ebx].EDITPARENT.lHScrollPos
	Invoke RSScroll, 0, Eax
	Mov Eax, lMax
	Ret
RSCenterSelection EndP

;On enter Ebx = Pointer to editor parent's data
RSCheckBufferSize Proc Private Uses Ecx lSize:LONG, ecType:LONG
	.If (ecType & RSC_TEXT)
		Mov Ecx, [Ebx].EDITPARENT.lpszNextText
		Sub Ecx, [Ebx].EDITPARENT.lpTextPointer
		Add Ecx, lSize
		Cmp Ecx, [Ebx].EDITPARENT.lMaxTextLength
		Jl @F
		Invoke RSResizeBuffer, RSC_TEXT, lSize
		Ret
	.ElseIf (ecType & RSC_LINES)
		Mov Eax, [Ebx].EDITPARENT.lLines
		Add Eax, lSize
		Cmp Eax, [Ebx].EDITPARENT.lMaxLines
		Jl @F
		Invoke RSResizeBuffer, RSC_LINES, lSize
		Ret
	.ElseIf (ecType & RSC_UNDO)
		Mov Eax, [Ebx].EDITPARENT.lUndoCount
		Cmp Eax, SDWord Ptr [Ebx].EDITPARENT.lMaxUndo
		Jl @F
		Invoke RSResizeBuffer, RSC_UNDO, lSize
		Ret
	.EndIf
@@:	Xor Eax, Eax
	Ret
RSCheckBufferSize EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to editor child's data
RSCheckHorizontalPos Proc Private
	Mov Eax, RSszText.x
	Add Eax, [Ebx].EDITPARENT.lSelBarWidth
	Add Eax, [Ebx].EDITPARENT.lCaretWidth
	Cmp Eax, [Esi].EDITCHILD.rc.right
	Jg @F
	Mov Eax, [Ebx].EDITPARENT.lHScrollPos
	Or Eax, Eax
	Jz @F
	Neg Eax
	Invoke RSScroll, 0, Eax
	Cmp [Esi].EDITCHILD.lPaint, PAINT_NONE
	Je @F
	Invoke RSInvalidateEditor, [Esi].EDITCHILD.hWnd, TRUE
@@:	Ret
RSCheckHorizontalPos EndP

;On enter Esi = Pointer to text buffer, Ecx = Relative offset to buffer pointed by Esi
RSCheckIfUTF8 Proc Private Uses Edi
	Mov Ah, Byte Ptr [Esi + Ecx]
	Inc Ecx
	Mov Edi, Ecx
	Xchg Al, Ah
	Mov Cx, Ax
	And Ch, 11100000B
	.If Ch == 11000000B
		And Cl, 11000000B
		.If Cl == 10000000B
			Mov Cl, Al
			Xor Al, Al
			And Ah, 00011111B
			Shr Ax, 2
			And Cl, 00111111B
			Or Al, Cl
		.Else
@@:			Dec Edi
			Mov Ax, 0FFFFH
		.EndIf
	.Else
		Mov Ch, Ah
		And Ch, 11110000B
		Cmp Ch, 11100000B
		Jne @B
		And Cl, 11000000B
		Cmp Cl, 10000000B
		Jne @B
		Mov Cl, Al
		Xor Al, Al
		And Ah, 00001111B
		Shr Ax, 2
		And Cl, 00111111B
		Or Al, Cl
		Mov Cl, Byte Ptr [Esi + Edi]
		Mov Ch, Cl
		And Ch, 11000000B
		Cmp Ch, 10000000B
		Jne @B
		Inc Edi
		And Cl, 00111111B
		Shl Ax, 6
		Or Al, Cl
	.EndIf
	Mov Ecx, Edi
	Ret
RSCheckIfUTF8 EndP

;On enter Ebx = Pointer to editor parent's data, Edi = Line address
RSCheckLineLength Proc Private Uses Ecx Edx Edi lLength:LONG
	Local sz:SIZEL

	Invoke GetDC, [Ebx].EDITPARENT.Editor.hWnd
	Mov Edi, Eax
	Invoke SelectObject, Edi, [Ebx].EDITPARENT.hFont
	Push Eax
	Invoke RSGetTextExtentPoint32, Edi, [Ebx].EDITPARENT.lpszLine, lLength, Addr sz
	Pop Eax
	Invoke SelectObject, Edi, Eax
	Invoke ReleaseDC, [Ebx].EDITPARENT.Editor.hWnd, Edi
	Mov Eax, sz.x
	.If Eax > SDWord Ptr [Ebx].EDITPARENT.lHScrollMax
		Mov [Ebx].EDITPARENT.lHScrollMax, Eax
		Invoke RSUpdateScrollBars, SCROLL_HORZ
		Mov [Ebx].EDITPARENT.bHScrollChanged, TRUE
	.EndIf
	Mov Eax, lLength
	Ret
RSCheckLineLength EndP

;On enter Ebx = Pointer to editor parent's data
RSCheckModified Proc Private
	Mov Eax, [Ebx].EDITPARENT.lUndoCount
	.If Eax == [Ebx].EDITPARENT.lLastUndoCount
		Mov [Ebx].EDITPARENT.bModified, FALSE
	.EndIf
	Ret
RSCheckModified EndP

RSCheckScrollWidth Proc Private
	Mov RSsci.fMask, SIF_ALL
	Invoke GetScrollInfo, [Ebx].EDITPARENT.hWndHScroll, SB_CTL, Addr RSsci
	Xor Eax, Eax
	.If [Ebx].EDITPARENT.szFont.x
		Invoke RSGetEditorDataPointer
		Mov Eax, [Eax].EDITCHILD.rc.right
		Sub Eax, [Ebx].EDITPARENT.lSelBarWidth
		Mov Ecx, RSlVScrollWidth
		Sub Eax, Ecx
		Mov [Ebx].EDITPARENT.lHScrollPage, Eax
	.EndIf
	Cmp Eax, [Ebx].EDITPARENT.lHScrollMax
	Jl @F
	Mov [Ebx].EDITPARENT.lHScrollPos, 0
	Mov [Ebx].EDITPARENT.lHScrollMax, 0
	Mov RSsci.nPos, 0
	Mov RSsci.nTrackPos, 0
	Or RSsci.fMask, SIF_DISABLENOSCROLL
	Mov Eax, [Ebx].EDITPARENT.lHScrollMax
	Mov RSsci.nMax, Eax
	Invoke SetScrollInfo, [Ebx].EDITPARENT.hWndHScroll, SB_CTL, Addr RSsci, TRUE
@@:	Ret
RSCheckScrollWidth EndP

;On enter Ebx = Pointer to editor parent's data
RSCheckTextFormat Proc Private Uses Esi lFormat:LONG
	Cmp lFormat, 1
	Jl L2
	Cmp lFormat, 4
	Jle @F
L2:	Ret

@@:	Xor Esi, Esi
	Mov Eax, [Ebx].EDITPARENT.lMaxIndex
	Add Eax, [Ebx].EDITPARENT.lLines
	Add Eax, 2
	Invoke RSGetBytes, Eax
	.If lFormat == 1 ;ANSI text
		.If [Ebx].EDITPARENT.bTextUnicode
			Shr Eax, 1
			Invoke VirtualAlloc, 0, Eax, MEM_COMMIT, PAGE_READWRITE
			Mov Esi, Eax
			Mov Eax, [Ebx].EDITPARENT.lMaxIndex
			Add Eax, [Ebx].EDITPARENT.lLines
			Invoke RSConvertToMultibyte, [Ebx].EDITPARENT.lpTextPointer, Esi, Eax
			Mov [Ebx].EDITPARENT.bTextUnicode, FALSE
			Mov [Ebx].EDITPARENT.bBigEndian, FALSE
			Mov [Ebx].EDITPARENT.bTextUnicodeUTF8, FALSE
L4:			Invoke RSSetNewText, Esi
			Invoke VirtualFree, Esi, 0, MEM_RELEASE
			.If lFormat == 3	;Unicode big endian text
				Mov [Ebx].EDITPARENT.bBigEndian, TRUE
			.ElseIf lFormat == 4	;UTF-8
				Mov [Ebx].EDITPARENT.bTextUnicodeUTF8, TRUE
			.EndIf
			Jmp L2
		.EndIf
	.Else
		Mov [Ebx].EDITPARENT.bBigEndian, FALSE
		Mov [Ebx].EDITPARENT.bTextUnicodeUTF8, FALSE
		.If (![Ebx].EDITPARENT.bTextUnicode)
			Shl Eax, 1
			Invoke VirtualAlloc, 0, Eax, MEM_COMMIT, PAGE_READWRITE
			Mov Esi, Eax
			Mov Eax, [Ebx].EDITPARENT.lMaxIndex
			Add Eax, [Ebx].EDITPARENT.lLines
			Invoke MultiByteToWideChar, CP_ACP, 0, [Ebx].EDITPARENT.lpTextPointer, (-1), Esi, Eax
			Mov [Ebx].EDITPARENT.bTextUnicode, TRUE
			Jmp L4
		.EndIf
		.If lFormat == 3	;Unicode big endian text
			Mov [Ebx].EDITPARENT.bBigEndian, TRUE
		.ElseIf lFormat == 4	;UTF-8
			Mov [Ebx].EDITPARENT.bTextUnicodeUTF8, TRUE
		.EndIf
	.EndIf
	Jmp L2
RSCheckTextFormat EndP

;On enter Ebx = Pointer to editor parent's data
RSClearUndoEntry Proc Private Uses Ecx Edx Esi lEntry:LONG
	Mov Esi, lEntry
	Shl Esi, 4
	Add Esi, [Ebx].EDITPARENT.lpUndoPointer
	Mov Eax, [Esi].EDITUNDO.lpszText
	Or Eax, Eax
	Jz @F
	Invoke HeapFree, [Ebx].EDITPARENT.hHeap, 0, [Esi].EDITUNDO.lpszText
	Mov [Esi].EDITUNDO.lpszText, NULL
	Mov Eax, TRUE
@@:	Mov [Esi].EDITUNDO.lTopLine, 0
	Mov [Esi].EDITUNDO.chrPos.lMin, 0
	Mov [Esi].EDITUNDO.chrPos.lMax, 0
	Ret
RSClearUndoEntry EndP

;On enter Ebx = Pointer to editor parent's data
RSClearUndoEntryFrom Proc Private Uses Edx lEntry:LONG
	Mov Edx, lEntry
	.While Edx < SDWord Ptr [Ebx].EDITPARENT.lMaxUndo
		Invoke RSClearUndoEntry, Edx
		Or Eax, Eax
		Jz @F
		Inc Edx
	.EndW
@@:	Ret
RSClearUndoEntryFrom EndP

;On enter Ebx = Pointer to editor parent's data
RSClipboardToText Proc Private Uses Edi Esi lpszDest:LPLONG, lpszSource:LPLONG
	Mov Esi, lpszSource
	Mov Edi, lpszDest
	Cmp [Ebx].EDITPARENT.bTextUnicode, FALSE
	Jne ClipboardToTextW
	Mov Al, Byte Ptr [Esi]
	Cmp Al, LF
	Jne A4
	Mov Al, VK_RETURN
	Jmp A4
A2:	Inc Esi
	Mov Al, Byte Ptr [Esi]
	Cmp Al, LF
	Jne A4
	Cmp Byte Ptr [Esi - 1], VK_RETURN
	Je A2
	Mov Al, VK_RETURN
A4:	Mov Byte Ptr [Edi], Al
	Inc Edi
	Or Al, Al
	Jnz A2
L2:	Ret

ClipboardToTextW:
	Mov Ax, Word Ptr [Esi]
	Cmp Ax, LF
	Jne W4
	Mov Ax, VK_RETURN
	Jmp W4
W2:	Add Esi, 2
	Mov Ax, Word Ptr [Esi]
	Cmp Ax, LF
	Jne W4
	Cmp Word Ptr [Esi - 2], VK_RETURN
	Je W2
	Mov Ax, VK_RETURN
W4:	Mov Word Ptr [Edi], Ax
	Add Edi, 2
	Or Ax, Ax
	Jnz W2
	Jmp L2
RSClipboardToText EndP

RSConvertToMultibyte Proc Private lpszWideChar:LPWSTR, lpszMultibyte:LPSTR, cchMultibyte:DWord
	Invoke WideCharToMultiByte, CP_ACP, 0, lpszWideChar, (-1), lpszMultibyte, cchMultibyte, NULL, NULL
	Ret
RSConvertToMultibyte EndP

;On enter Ebx = Pointer to editor parent's data
RSCopyString Proc Private Uses Ecx Edx lpszDest:LPSTR, lpszSource:LPSTR
	Push lpszSource
	Push lpszDest
	.If [Ebx].EDITPARENT.bTextUnicode
		Mov Eax, lstrcpyW
	.Else
		Mov Eax, lstrcpy
	.EndIf
	Call Eax
	Ret
RSCopyString EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to editor child's data
RSDeleteSelection Proc Private Uses Ecx Edx Edi lpChrInfMin:LPLONG, lpChrInfMax:LPLONG
	Local lMin:LONG, lState:LONG
	Local ChrInfMin:RSSCHARINFO, ChrInfMax:RSSCHARINFO

	Xor Eax, Eax
	Mov Ecx, [Esi].EDITCHILD.chrPos.lMin
	.If Ecx != [Esi].EDITCHILD.chrPos.lMax
		Invoke RtlMoveMemory, Addr ChrInfMin, lpChrInfMin, SizeOf RSSCHARINFO
		Invoke RtlMoveMemory, Addr ChrInfMax, lpChrInfMax, SizeOf RSSCHARINFO
		Mov Edx, ChrInfMin.lLine
		.If Edx == ChrInfMax.lLine
			Mov [Esi].EDITCHILD.lPaint, PAINT_LINE
			Shl Edx, 4
			Add Edx, [Ebx].EDITPARENT.lpLinesPointer
			Mov Edi, [Edx].LINE.lpszText
			Mov Eax, [Edx].LINE.lLength
			Mov Ecx, [Esi].EDITCHILD.chrPos.lMax
			Sub Ecx, ChrInfMin.lLineIndex
			Sub Eax, Ecx
			Push Eax
			Invoke RSGetBytes, Ecx
			Mov Ecx, Eax
			Add Ecx, Edi
			Mov Eax, [Esi].EDITCHILD.chrPos.lMin
			Sub Eax, ChrInfMin.lLineIndex
			Invoke RSGetBytes, Eax
			Add Edi, Eax
			Pop Eax
			Or Eax, Eax
			Jnz @F
			Mov Byte Ptr [Edi], 0
			Cmp [Ebx].EDITPARENT.bTextUnicode, FALSE
			Je @F
			Mov Byte Ptr [Edi + 1], 0
@@:			Invoke RSMoveChars, Edi, Ecx, Eax
			Mov Eax, [Esi].EDITCHILD.chrPos.lMax
			Sub Eax, [Esi].EDITCHILD.chrPos.lMin
			Sub [Edx].LINE.lLength, Eax
			Mov Ecx, [Edx].LINE.lpszText
			Mov Edx, [Edx].LINE.lLength
			.If [Ebx].EDITPARENT.bTextUnicode
				Shl Edx, 1
				Add Ecx, Edx
				.If Edx
					.If (Word Ptr [Ecx - 2] != VK_RETURN)
						Mov Word Ptr [Ecx], 0
					.EndIf
				.Else
					.If (Word Ptr [Ecx] != VK_RETURN)
						Mov Word Ptr [Ecx], 0
					.EndIf
				.EndIf
			.Else
				Add Ecx, Edx
				.If Edx
					.If (Byte Ptr [Ecx - 1] != VK_RETURN)
						Mov Byte Ptr [Ecx], 0
					.EndIf
				.Else
					.If (Byte Ptr [Ecx] != VK_RETURN)
						Mov Byte Ptr [Ecx], 0
					.EndIf
				.EndIf
			.EndIf
		.Else
			Mov lState, (-1)
			Mov [Esi].EDITCHILD.lPaint, PAINT_FROM_LINE
			.If ChrInfMin.lLineOffset || ChrInfMax.lLineOffset
				Mov lMin, Edx
				Shl Edx, 4
				Add Edx, [Ebx].EDITPARENT.lpLinesPointer
				Mov Eax, ChrInfMin.lLineOffset
				Mov [Edx].LINE.lLength, Eax
				Mov Ecx, ChrInfMax.lLine
				Shl Ecx, 4
				Add Ecx, [Ebx].EDITPARENT.lpLinesPointer
				.If (ChrInfMin.lLineOffset == 0)
					Mov Eax, [Ecx].LINE.lState
					Mov lState, Eax
				.EndIf
				Mov Eax, [Ecx].LINE.lLength
				Sub Eax, ChrInfMax.lLineOffset
				Add Eax, [Edx].LINE.lLength
				.If Eax > SDWord Ptr [Edx].LINE.lMaxLength
					Sub Eax, [Edx].LINE.lMaxLength
					Invoke RSResizeLine, ChrInfMin.lLine, Eax
					Mov Edx, ChrInfMin.lLine
					Shl Edx, 4
					Add Edx, [Ebx].EDITPARENT.lpLinesPointer
					Mov Ecx, ChrInfMax.lLine
					Shl Ecx, 4
					Add Ecx, [Ebx].EDITPARENT.lpLinesPointer
				.EndIf
				Push Esi
				Mov Esi, [Ecx].LINE.lpszText
				Invoke RSGetBytes, ChrInfMax.lLineOffset
				Add Esi, Eax
				Mov Edi, [Edx].LINE.lpszText
				Invoke RSGetBytes, ChrInfMin.lLineOffset
				Add Edi, Eax
				Mov Eax, [Ecx].LINE.lLength
				Sub Eax, ChrInfMax.lLineOffset
				Invoke RSMoveChars, Edi, Esi, Eax
				Add [Edx].LINE.lLength, Eax
				Inc ChrInfMin.lLine
				Inc ChrInfMax.lLine
				Pop Esi
			.EndIf
			Mov Ecx, ChrInfMax.lLine
			Mov Edi, Ecx
			Shl Edi, 4
			Add Edi, [Ebx].EDITPARENT.lpLinesPointer
			Mov Edx, ChrInfMin.lLine
			Shl Edx, 4
			Add Edx, [Ebx].EDITPARENT.lpLinesPointer
@@:			Cmp Ecx, [Ebx].EDITPARENT.lLines
			Jg @F
			Mov Eax, [Edi]
			Mov [Edx], Eax
			Mov Eax, [Edi + 4]
			Mov [Edx + 4], Eax
			Mov Eax, [Edi + 8]
			Mov [Edx + 8], Eax
			Mov Eax, [Edi + 12]
			Mov [Edx + 12], Eax
			Add Edx, SizeOf LINE
			Add Edi, SizeOf LINE
			Inc Ecx
			Jmp @B
@@:			.If lState != (-1)
				Mov Edx, lMin
				Shl Edx, 4
				Add Edx, [Ebx].EDITPARENT.lpLinesPointer
				Mov Eax, lState
				Mov [Edx].LINE.lState, Eax
			.EndIf
			Mov Eax, ChrInfMax.lLine
			Sub Eax, ChrInfMin.lLine
			Sub [Ebx].EDITPARENT.lLines, Eax
			Jge @F
			Xor Eax, Eax
			Mov [Ebx].EDITPARENT.lLines, Eax
@@:			Mov Eax, [Esi].EDITCHILD.chrPos.lMax
			Sub Eax, [Esi].EDITCHILD.chrPos.lMin
		.EndIf
		Sub [Ebx].EDITPARENT.lMaxIndex, Eax
		Mov Eax, [Esi].EDITCHILD.chrPos.lMin
		Mov [Esi].EDITCHILD.chrPos.lMax, Eax
		Mov Edx, lpChrInfMin
		Mov Eax, ChrInfMin.lLine
		Mov [Edx].RSSCHARINFO.lLine, Eax
		Mov Eax, TRUE
	.EndIf
	Ret
RSDeleteSelection EndP

;On enter Ebx = Pointer to editor parent's data
RSDestroyMirror Proc Private Uses Esi
	Invoke SetFocus, [Ebx].EDITPARENT.Editor.hWnd
	.If [Ebx].EDITPARENT.Mirror.hWnd
		Invoke DestroyWindow, [Ebx].EDITPARENT.Mirror.hWnd
		Mov [Ebx].EDITPARENT.Mirror.hWnd, NULL
	.EndIf
	Mov [Ebx].EDITPARENT.Editor.bNoSelection, FALSE
	Mov Eax, [Ebx].EDITPARENT.rc.right
	Sub Eax, RSlVScrollWidth
	Invoke MoveWindow, [Ebx].EDITPARENT.hWndSplitter, Eax, 0, RSlVScrollWidth, 6, TRUE
	Invoke RSResizeChilds, FALSE
	Lea Esi, [Ebx].EDITPARENT.Editor
	Invoke RSSetSelection, [Esi].EDITCHILD.chrPos.lMin, [Esi].EDITCHILD.chrPos.lMax, 0
	Ret
RSDestroyMirror EndP

;On Exit Esi = Pointer to UTF-8 encoded text
RSEncodeUTF8 Proc Private Uses Ebx Edi lpszText:LPSTR, lTextLength:LONG
	Mov Eax, lTextLength
	Add Eax, 2
	Shl Eax, 1
	Add Eax, lTextLength
	Invoke VirtualAlloc, 0, Eax, MEM_COMMIT, PAGE_READWRITE
	Mov Edi, Eax
	Xor Ecx, Ecx
	Xor Edx, Edx
	Shl lTextLength, 1
	Mov Esi, lpszText
	.While (Ecx < SDWord Ptr lTextLength)
		Mov Ax, Word Ptr [Esi + Ecx]
		Cmp Ax, 128
		Jnc @F
		Mov Byte Ptr [Edi + Edx], Al
		Inc Edx
		Jmp L4
@@:		Cmp Ax, 2048
		Jnc @F
		Mov Bx, Ax
		Shl Bx, 2
		And Bh, 00011111B
		Or Bh, 11000000B
L2:		And Al, 00111111B
		Or Al, 10000000B
		Mov Byte Ptr [Edi + Edx], Bh
		Inc Edx
		Mov Byte Ptr [Edi + Edx], Al
		Inc Edx
		Jmp L4
@@:		Mov Bh, Ah
		Shr Bh, 4
		And Bh, 00001111B
		Or Bh, 11100000B
		Mov Byte Ptr [Edi + Edx], Bh
		Inc Edx
		And Ah, 00001111B
		Mov Bx, Ax
		Shl Bx, 2
		And Bh, 00111111B
		Or Bh, 10000000B
		Jmp L2
L4:		Add Ecx, 2
	.EndW
	Push Edx
	Invoke VirtualFree, Esi, 0, MEM_RELEASE
	Mov Esi, Edi
	Pop Eax
	Ret
RSEncodeUTF8 EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to editor child's data
RSExpandTabs Proc Private Uses Ecx Edx Edi lpLineAddress:LPLONG, lpExpandedCol:DWord
	Local bSetCol:BOOL, lLength:LONG
	Local lLineLength:LONG

	Mov Eax, lpExpandedCol
	Or Eax, Eax
	Jz @F
	Mov DWord Ptr [Eax], 0
	Mov Eax, TRUE
@@:	Mov bSetCol, Eax
	Mov lLength, 0
	Mov Edx, lpLineAddress
	Mov Edi, [Edx].LINE.lpszText
	Mov Eax, [Edx].LINE.lLength
	.If Eax
		Mov lLineLength, Eax
		Mov Ecx, lpExpandedCol
		Or Ecx, Ecx
		Jz @F
		Mov [Ecx], Eax
@@:		Invoke RSAllocateLineMemory, [Edx].LINE.lpszText, Eax
		Mov Edx, [Ebx].EDITPARENT.lpszLine
		Xor Ecx, Ecx
		Cmp [Ebx].EDITPARENT.bTextUnicode, FALSE
		Jne ExpandTabsW
A2:		Cmp bSetCol, FALSE
		Je @F
		Cmp Ecx, [Esi].EDITCHILD.lCurCol
		Jl @F
		Mov Eax, lLength
		Push Ecx
		Mov Ecx, lpExpandedCol
		Mov [Ecx], Eax
		Pop Ecx
		Mov bSetCol, FALSE
@@:		Mov Al, Byte Ptr [Edi + Ecx]
		Or Al, Al
		Jz L4
		Cmp Ecx, lLineLength
		Jnc L4
		Cmp Al, VK_RETURN
		Jne @F
		Mov Byte Ptr [Edx], ' '
		Inc Edx
		Inc lLength
		Jmp L4
@@:		Cmp Al, VK_TAB
		Je @F
		Mov Byte Ptr [Edx], Al
		Inc lLength
		Inc Ecx
		Inc Edx
		Jmp A2
@@:		Push Ecx
		Mov Eax, lLength
		Mov Ecx, [Ebx].EDITPARENT.lTabSize
		Dec Ecx
		And Eax, Ecx
		Inc Ecx
		Sub Ecx, Eax
		Push Ecx
@@:		Mov Byte Ptr [Edx + Ecx], ' '
		Dec Ecx
		Jge @B
		Pop Eax
		Pop Ecx
		Add Edx, Eax
		Add lLength, Eax
		Inc Ecx
		Jmp A2
L4:		Mov Word Ptr [Edx], 0
		Mov Eax, lLength
	.EndIf
	Ret

ExpandTabsW:
	Cmp bSetCol, FALSE
	Je @F
	Cmp Ecx, [Esi].EDITCHILD.lCurCol
	Jl @F
	Mov Eax, lLength
	Push Ecx
	Mov Ecx, lpExpandedCol
	Mov [Ecx], Eax
	Pop Ecx
	Mov bSetCol, FALSE
@@:	Mov Eax, Ecx
	Shl Eax, 1
	Mov Ax, Word Ptr [Edi + Eax]
	Or Ax, Ax
	Jz L4
	Cmp Ecx, lLineLength
	Jnc L4
	Cmp Ax, VK_RETURN
	Jne @F
	Mov Word Ptr [Edx], ' '
	Add Edx, 2
	Inc lLength
	Jmp L4
@@:	Cmp Ax, VK_TAB
	Je @F
	Mov Word Ptr [Edx], Ax
	Inc lLength
	Inc Ecx
	Add Edx, 2
	Jmp ExpandTabsW
@@:	Push Ecx
	Mov Eax, lLength
	Mov Ecx, [Ebx].EDITPARENT.lTabSize
	Dec Ecx
	And Eax, Ecx
	Inc Ecx
	Sub Ecx, Eax
	Push Ecx
	Shl Ecx, 1
@@:	Mov Word Ptr [Edx + Ecx], ' '
	Sub Ecx, 2
	Jge @B
	Pop Eax
	Pop Ecx
	Add lLength, Eax
	Shl Eax, 1
	Add Edx, Eax
	Inc Ecx
	Jmp ExpandTabsW
RSExpandTabs EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to editor child's data
RSExpandTabsAndGetSel Proc Private Uses Ecx Edx Edi lpLineAddress:LPLONG, lLineIndex:LONG, lpChr:DWord
	Local bMin:BOOL, bMax:BOOL
	Local lLength:LONG, lLineLength:LONG

	Invoke RSAllocateLineMemory, [Edi].LINE.lpszText, [Edi].LINE.lLength
	Mov Eax, [Edi].LINE.lLength
	Mov lLength, Eax
	Mov lLineLength, Eax
	Xor Eax, Eax
	Mov bMin, Eax
	Mov bMax, Eax
	Mov Edi, lpChr
	Mov [Edi].RSSCHARSEL.lMin, Eax
	Mov [Edi].RSSCHARSEL.lMax, Eax
	Mov Eax, [Esi].EDITCHILD.chrPos.lMin
	Cmp [Ebx].EDITPARENT.bTextUnicode, FALSE
	Jne ExpandTabsAndGetSelW
	Cmp Eax, [Esi].EDITCHILD.chrPos.lMax
	Je A4
	Mov Ecx, lLineIndex
	Add Ecx, lLength
	Cmp Eax, Ecx
	Jge A4
	Cmp Eax, lLineIndex
	Jl @F
	Mov bMin, TRUE
	Mov bMax, TRUE
	Sub Eax, lLineIndex
	Mov [Edi].RSSCHARSEL.lMin, Eax
	Mov Eax, [Esi].EDITCHILD.chrPos.lMax
	Jmp A2
@@:	Mov Eax, [Esi].EDITCHILD.chrPos.lMax
	Cmp Eax, lLineIndex
	Jle A4
	Mov bMin, TRUE
	Mov bMax, TRUE
	Mov [Edi].RSSCHARSEL.lMin, 0
A2:	Sub Eax, lLineIndex
	Cmp Eax, lLength
	Jle @F
	Mov Eax, lLength
@@:	Mov [Edi].RSSCHARSEL.lMax, Eax

A4:	Mov lLength, 0
	Mov Edx, lpLineAddress
	Mov Edi, [Edx].LINE.lpszText
	Mov Edx, [Ebx].EDITPARENT.lpszLine
	Xor Ecx, Ecx
A6:	Cmp bMin, FALSE
	Je @F
	Mov Eax, lpChr
	Cmp Ecx, [Eax].RSSCHARSEL.lMin
	Jl @F
	Push lLength
	Pop [Eax].RSSCHARSEL.lMin
	Mov bMin, FALSE
@@:	Cmp bMax, FALSE
	Je @F
	Mov Eax, lpChr
	Cmp Ecx, [Eax].RSSCHARSEL.lMax
	Jl @F
	Push lLength
	Pop [Eax].RSSCHARSEL.lMax
	Mov bMax, FALSE
@@:	Mov Al, Byte Ptr [Edi + Ecx]
	Or Al, Al
	Jz L8
	Cmp Ecx, lLineLength
	Jnc L8
	Cmp Al, VK_RETURN
	Jne @F
	Mov Byte Ptr [Edx], VK_SPACE
	Inc Edx
	Inc lLength
	Jmp L8
@@:	Cmp Al, VK_TAB
	Je @F
	Mov Byte Ptr [Edx], Al
	Inc lLength
	Inc Ecx
	Inc Edx
	Jmp A6
@@:	Push Ecx
	Mov Eax, lLength
	Mov Ecx, [Ebx].EDITPARENT.lTabSize
	Dec Ecx
	And Eax, Ecx
	Inc Ecx
	Sub Ecx, Eax
	Push Ecx
@@:	Mov Byte Ptr [Edx + Ecx], VK_SPACE
	Dec Ecx
	Jge @B
	Pop Eax
	Pop Ecx
	Add Edx, Eax
	Add lLength, Eax
	Inc Ecx
	Jmp A6
L8:	Cmp bMax, FALSE
	Je @F
	Mov Eax, lpChr
	Push lLength
	Pop [Eax].RSSCHARSEL.lMax
@@:	Mov Word Ptr [Edx], 0
	Mov Eax, lLength
	Ret

ExpandTabsAndGetSelW:
	Cmp Eax, [Esi].EDITCHILD.chrPos.lMax
	Je W4
	Mov Ecx, lLineIndex
	Add Ecx, lLength
	Cmp Eax, Ecx
	Jge W4
	Cmp Eax, lLineIndex
	Jl @F
	Mov bMin, TRUE
	Mov bMax, TRUE
	Sub Eax, lLineIndex
	Mov [Edi].RSSCHARSEL.lMin, Eax
	Mov Eax, [Esi].EDITCHILD.chrPos.lMax
	Jmp W2
@@:	Mov Eax, [Esi].EDITCHILD.chrPos.lMax
	Cmp Eax, lLineIndex
	Jle W4
	Mov bMin, TRUE
	Mov bMax, TRUE
	Mov [Edi].RSSCHARSEL.lMin, 0
W2:	Sub Eax, lLineIndex
	Cmp Eax, lLength
	Jle @F
	Mov Eax, lLength
@@:	Mov [Edi].RSSCHARSEL.lMax, Eax

W4:	Mov lLength, 0
	Mov Edx, lpLineAddress
	Mov Edi, [Edx].LINE.lpszText
	Mov Edx, [Ebx].EDITPARENT.lpszLine
	Xor Ecx, Ecx
W6:	Cmp bMin, FALSE
	Je @F
	Mov Eax, lpChr
	Cmp Ecx, [Eax].RSSCHARSEL.lMin
	Jl @F
	Push lLength
	Pop [Eax].RSSCHARSEL.lMin
	Mov bMin, FALSE
@@:	Cmp bMax, FALSE
	Je @F
	Mov Eax, lpChr
	Cmp Ecx, [Eax].RSSCHARSEL.lMax
	Jl @F
	Push lLength
	Pop [Eax].RSSCHARSEL.lMax
	Mov bMax, FALSE
@@:	Mov Eax, Ecx
	Shl Eax, 1
	Mov Ax, Word Ptr [Edi + Eax]
	Or Ax, Ax
	Jz L8
	Cmp Ecx, lLineLength
	Jnc L8
	Cmp Ax, VK_RETURN
	Jne @F
	Mov Word Ptr [Edx], VK_SPACE
	Add Edx, 2
	Inc lLength
	Jmp L8
@@:	Cmp Ax, VK_TAB
	Je @F
	Mov Word Ptr [Edx], Ax
	Inc lLength
	Inc Ecx
	Add Edx, 2
	Jmp W6
@@:	Push Ecx
	Mov Eax, lLength
	Mov Ecx, [Ebx].EDITPARENT.lTabSize
	Dec Ecx
	And Eax, Ecx
	Inc Ecx
	Sub Ecx, Eax
	Push Ecx
	Shl Ecx, 1
@@:	Mov Word Ptr [Edx + Ecx], VK_SPACE
	Sub Ecx, 2
	Jge @B
	Pop Eax
	Pop Ecx
	Add lLength, Eax
	Shl Eax, 1
	Add Edx, Eax
	Inc Ecx
	Jmp W6
RSExpandTabsAndGetSel EndP

;On enter Ebx = Pointer to editor parent's data
RSFindFirstValidChar Proc Private Uses Edi lpszBuf:LPSTR
	Mov Edi, lpszBuf
	.If [Ebx].EDITPARENT.bTextUnicode
@@:		Mov Ax, Word Ptr [Edi]
		Cmp Ax, VK_RETURN
		Je L2
		Or Ax, Ax
		Jz L2
		Add Edi, 2
		Cmp Ax, ' '
		Je @B
		Cmp Ax, VK_TAB
		Je @B
		Sub Edi, 2
	.Else
@@:		Mov Al, [Edi]
		Cmp Al, VK_RETURN
		Je L2
		Or Al, Al
		Jz L2
		Inc Edi
		Cmp Al, ' '
		Je @B
		Cmp Al, VK_TAB
		Je @B
		Dec Edi
	.EndIf
L2:	Mov Eax, Edi
	Sub Eax, lpszBuf
	Invoke RSGetChars, Eax
	Ret
RSFindFirstValidChar EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to active editor child's data
RSFindNextWord Proc Private Uses Ecx Edx Edi lIndex:LONG
	Local bAlphaNumeric:BOOL, ChrInf:RSSCHARINFO

	Invoke RSGetCharInfo, lIndex, Addr ChrInf
	Mov Edx, ChrInf.lLine
	Shl Edx, 4
	Add Edx, [Ebx].EDITPARENT.lpLinesPointer
	Mov Edi, [Edx].LINE.lpszText
	Mov Ecx, ChrInf.lLineOffset
	Cmp [Ebx].EDITPARENT.bTextUnicode, FALSE
	Jne FindNextWordW
	Cmp Ecx, [Edx].LINE.lLength
	Jl A2
	Inc ChrInf.lLine
	Mov Eax, ChrInf.lLine
	Cmp Eax, [Ebx].EDITPARENT.lLines
	Jle @F
	Mov Eax, [Esi].EDITCHILD.chrPos.lMax
	Ret
@@:	Add Edx, SizeOf LINE
	Mov Edi, [Edx].LINE.lpszText
	Mov Eax, [Edx].LINE.lLength
	Add ChrInf.lLineIndex, Eax
	Xor Ecx, Ecx
	Mov ChrInf.lLineOffset, Ecx
A2:	Movzx Eax, Byte Ptr [Edi + Ecx]
	Cmp Eax, ' '
	Je A8
	Cmp Eax, VK_TAB
	Je A8
	Invoke RSIsCharAlphaNumeric, Eax
	Mov bAlphaNumeric, Eax
A4:	Inc Ecx
	Cmp Ecx, [Edx].LINE.lLength
	Jl A6
	Movzx Eax, Byte Ptr [Edi + Ecx - 1]
	Cmp Eax, VK_RETURN
	Jne @F
	Add Edx, SizeOf LINE
	Mov Eax, ChrInf.lLine
	Inc Eax
	Cmp Eax, [Ebx].EDITPARENT.lLines
	Jle @F
	Mov Eax, [Esi].EDITCHILD.chrPos.lMax
	Ret
@@:	Mov Edi, [Edx].LINE.lpszText
	Add ChrInf.lLineIndex, Ecx
	Xor Ecx, Ecx
	Mov ChrInf.lLineOffset, Ecx
A6:	Movzx Eax, Byte Ptr [Edi + Ecx]
	Or Ecx, Ecx
	Jz A8
	Cmp Eax, VK_RETURN
	Je A8
	Invoke RSIsCharAlphaNumeric, Eax
	Cmp Eax, bAlphaNumeric
	Je A4
A8:	Mov Eax, Ecx
	Dec Eax
@@:	Inc Eax
	Cmp Byte Ptr [Edi + Eax], ' '
	Je @B
	Cmp Byte Ptr [Edi + Eax], VK_TAB
	Je @B
L2:	Add Eax, ChrInf.lLineIndex
	Ret

FindNextWordW:
	Cmp Ecx, [Edx].LINE.lLength
	Jl W2
	Inc ChrInf.lLine
	Mov Eax, ChrInf.lLine
	Cmp Eax, [Ebx].EDITPARENT.lLines
	Jle @F
	Mov Eax, [Esi].EDITCHILD.chrPos.lMax
	Ret
@@:	Add Edx, SizeOf LINE
	Mov Edi, [Edx].LINE.lpszText
	Mov Eax, [Edx].LINE.lLength
	Add ChrInf.lLineIndex, Eax
	Xor Ecx, Ecx
	Mov ChrInf.lLineOffset, Ecx
W2:	Mov Eax, Ecx
	Shl Eax, 1
	Movzx Eax, Word Ptr [Edi + Eax]
	Cmp Eax, ' '
	Je W8
	Cmp Eax, VK_TAB
	Je W8
	Invoke RSIsCharAlphaNumeric, Eax
	Mov bAlphaNumeric, Eax
W4:	Inc Ecx
	Cmp Ecx, [Edx].LINE.lLength
	Jl W6
	Movzx Eax, Byte Ptr [Edi + Ecx - 2]
	Cmp Eax, VK_RETURN
	Jne @F
	Add Edx, SizeOf LINE
	Mov Eax, ChrInf.lLine
	Inc Eax
	Cmp Eax, [Ebx].EDITPARENT.lLines
	Jle @F
	Mov Eax, [Esi].EDITCHILD.chrPos.lMax
	Ret
@@:	Mov Edi, [Edx].LINE.lpszText
	Add ChrInf.lLineIndex, Ecx
	Xor Ecx, Ecx
	Mov ChrInf.lLineOffset, Ecx
W6:	Mov Eax, Ecx
	Shl Eax, 1
	Movzx Eax, Word Ptr [Edi + Eax]
	Or Ecx, Ecx
	Jz W8
	Cmp Eax, VK_RETURN
	Je W8
	Invoke RSIsCharAlphaNumeric, Eax
	Cmp Eax, bAlphaNumeric
	Je W4
W8:	Mov Eax, Ecx
	Shl Eax, 1
	Sub Eax, 2
@@:	Add Eax, 2
	Cmp Word Ptr [Edi + Eax], ' '
	Je @B
	Cmp Word Ptr [Edi + Eax], VK_TAB
	Je @B
	Shr Eax, 1
	Jmp L2
RSFindNextWord EndP

;On enter Ebx = Pointer to editor parent's data
RSFindPrevWord Proc Private Uses Ecx Edx Edi lIndex:LONG
	Local bAlphaNumeric:BOOL, ChrInf:RSSCHARINFO

	Invoke RSGetCharInfo, lIndex, Addr ChrInf
	Mov Edx, ChrInf.lLine
	Shl Edx, 4
	Add Edx, [Ebx].EDITPARENT.lpLinesPointer
	Mov Edi, [Edx].LINE.lpszText
	Mov Ecx, ChrInf.lLineOffset
	Cmp [Ebx].EDITPARENT.bTextUnicode, FALSE
	Jne FindPrevWordW
	Cmp Ecx, 0
	Jg A2
	Dec ChrInf.lLine
	Jge @F
	Xor Eax, Eax
	Ret
@@:	Sub Edx, SizeOf LINE
	Mov Edi, [Edx].LINE.lpszText
	Mov Ecx, [Edx].LINE.lLength
	Sub ChrInf.lLineIndex, Ecx
	Dec Ecx
	Mov ChrInf.lLineOffset, Ecx
	Inc Ecx
A2:	Dec Ecx
	Cmp Byte Ptr [Edi + Ecx], VK_SPACE
	Je A2
	Cmp Byte Ptr [Edi + Ecx], VK_TAB
	Je A2
	Movzx Eax, Byte Ptr [Edi + Ecx]
	Cmp Eax, VK_RETURN
	Jne @F
	Or Ecx, Ecx
	Jz A4
	Movzx Eax, Byte Ptr [Edi + Ecx - 1]
@@:	Invoke RSIsCharAlphaNumeric, Eax
	Mov bAlphaNumeric, Eax
A4:	Dec Ecx
	Cmp Ecx, 0
	Jge A6
	Sub Edx, SizeOf LINE
	Cmp Edx, [Ebx].EDITPARENT.lpLinesPointer
	Jge @F
	Xor Eax, Eax
	Ret
@@:	Mov Edi, [Edx].LINE.lpszText
	Mov Ecx, [Edx].LINE.lLength
	Sub ChrInf.lLineIndex, Ecx
	Dec Ecx
	Mov ChrInf.lLineOffset, Ecx
A6:	Movzx Eax, Byte Ptr [Edi + Ecx]
	Cmp Eax, VK_RETURN
	Je L2
	Cmp Eax, VK_SPACE
	Je L2
	Cmp Eax, VK_TAB
	Je L2
	Invoke RSIsCharAlphaNumeric, Eax
	Cmp Eax, bAlphaNumeric
	Je A4
L2:	Mov Eax, Ecx
	Inc Eax
	Add Eax, ChrInf.lLineIndex
	Ret

FindPrevWordW:
	Cmp Ecx, 0
	Jg W2
	Dec ChrInf.lLine
	Jge @F
	Xor Eax, Eax
	Ret
@@:	Sub Edx, SizeOf LINE
	Mov Edi, [Edx].LINE.lpszText
	Mov Ecx, [Edx].LINE.lLength
	Sub ChrInf.lLineIndex, Ecx
	Dec Ecx
	Mov ChrInf.lLineOffset, Ecx
	Inc Ecx
W2:	Dec Ecx
	Mov Eax, Ecx
	Shl Eax, 1
	Cmp Word Ptr [Edi + Eax], VK_SPACE
	Je W2
	Cmp Word Ptr [Edi + Eax], VK_TAB
	Je W2
	Movzx Eax, Word Ptr [Edi + Eax]
	Cmp Eax, VK_RETURN
	Jne @F
	Or Ecx, Ecx
	Jz W4
	Mov Eax, Ecx
	Shl Eax, 1
	Movzx Eax, Word Ptr [Edi + Eax - 2]
@@:	Invoke RSIsCharAlphaNumeric, Eax
	Mov bAlphaNumeric, Eax
W4:	Dec Ecx
	Cmp Ecx, 0
	Jge W6
	Sub Edx, SizeOf LINE
	Cmp Edx, [Ebx].EDITPARENT.lpLinesPointer
	Jge @F
	Xor Eax, Eax
	Ret
@@:	Mov Edi, [Edx].LINE.lpszText
	Mov Ecx, [Edx].LINE.lLength
	Sub ChrInf.lLineIndex, Ecx
	Dec Ecx
	Mov ChrInf.lLineOffset, Ecx
W6:	Mov Eax, Ecx
	Shl Eax, 1
	Movzx Eax, Word Ptr [Edi + Eax]
	Cmp Eax, VK_RETURN
	Je L2
	Cmp Eax, VK_SPACE
	Je L2
	Cmp Eax, VK_TAB
	Je L2
	Invoke RSIsCharAlphaNumeric, Eax
	Cmp Eax, bAlphaNumeric
	Je W4
	Jmp L2
RSFindPrevWord EndP

;;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to editor child's data
RSFindText Proc Private Uses Edi Esi lFlags:LONG, lpFindText:LPLONG
	Local lTextLength:LONG, lpChildData:LPLONG
	Local ChrInfMin:RSSCHARINFO, ChrInfMax:RSSCHARINFO

	Mov Edi, lpFindText
	.If Edi
		Mov lpChildData, Esi
		Mov Eax, [Edi].RSSFINDTEXT.lpstr
		Mov Ax, Word Ptr [Eax]
		.If (![Ebx].EDITPARENT.bTextUnicode)
			Xor Ah, Ah
		.EndIf
		.If (Ax != 0)
			Invoke RSGetTextLength, [Edi].RSSFINDTEXT.lpstr
			Mov lTextLength, Eax
			Mov Ecx, [Edi].RSSFINDTEXT.chr.lMin
			Cmp Ecx, [Edi].RSSFINDTEXT.chr.lMax
			Je L6
			.If (lFlags & RSC_DOWN)
				.If Ecx == (-1)
					Xor Eax, Eax
				.Else
					Cmp Ecx, 0
					Jl L6
					Mov Eax, [Ebx].EDITPARENT.lMaxIndex
					Cmp Ecx, Eax
					Jg @F
					Mov Eax, Ecx
				.EndIf
@@:				Mov Edx, Eax
				Mov Ecx, [Ebx].EDITPARENT.lMaxIndex
				.If [Edi].RSSFINDTEXT.chr.lMax != (-1)
					.If SDWord Ptr [Edi].RSSFINDTEXT.chr.lMax < (-1)
						Jmp L6
					.ElseIf Ecx > SDWord Ptr [Edi].RSSFINDTEXT.chr.lMax
						Mov Ecx, [Edi].RSSFINDTEXT.chr.lMax
					.EndIf
				.EndIf
				Cmp Ecx, Edx
				Jle L6
			.Else
				.If Ecx == (-1) || Ecx >= SDWord Ptr [Ebx].EDITPARENT.lMaxIndex
					Mov Eax, [Ebx].EDITPARENT.lMaxIndex
				.Else
					Mov Eax, [Edi].RSSFINDTEXT.chr.lMin
				.EndIf
				Mov Ecx, Eax
				Mov Edx, [Ebx].EDITPARENT.lMaxIndex
				.If SDWord Ptr [Edi].RSSFINDTEXT.chr.lMax > Edx || SDWord Ptr [Edi].RSSFINDTEXT.chr.lMax < (-1)
					Jmp L6
				.Else
					Mov Edx, [Edi].RSSFINDTEXT.chr.lMax
					.If [Edi].RSSFINDTEXT.chr.lMax == (-1)
						Xor Edx, Edx
					.EndIf
				.EndIf
				Cmp Ecx, Edx
				Jle L6
			.EndIf
			Invoke RSGetCharInfo, Edx, Addr ChrInfMin
			Invoke RSGetCharInfo, Ecx, Addr ChrInfMax
			.If (lFlags & RSC_DOWN)
				Mov Edx, ChrInfMin.lLine
			.Else
				Mov Edx, ChrInfMax.lLine
				Mov Eax, ChrInfMax.lLineOffset
			.EndIf
			Mov Esi, Edx
			Shl Edx, 4
			Add Edx, [Ebx].EDITPARENT.lpLinesPointer
			Cmp [Edx].LINE.lLength, 0
			Jle L4
			Mov Ecx, [Edx].LINE.lpszText
			.If (lFlags & RSC_DOWN)
				Invoke RSGetBytes, ChrInfMin.lLineOffset
				Add Ecx, Eax
				Mov Eax, [Edx].LINE.lLength
				Sub Eax, ChrInfMin.lLineOffset
			.Else
				Mov Eax, ChrInfMax.lLineOffset
				Inc Eax
			.EndIf
			Jmp @F
L2:			Mov Ecx, [Edx].LINE.lpszText
			Mov Eax, [Edx].LINE.lLength
			.If (lFlags & RSC_DOWN)
				.If Esi == ChrInfMax.lLine
					Mov Eax, ChrInfMax.lLineOffset
					Inc Eax
				.EndIf
			.Else
				.If Esi == ChrInfMin.lLine
					Invoke RSGetBytes, ChrInfMin.lLineOffset
					Add Ecx, Eax
					Mov Eax, [Edx].LINE.lLength
					Sub Eax, ChrInfMin.lLineOffset
				.EndIf
			.EndIf
@@:			Dec Eax
			Jle L4
			.If (Esi == [Ebx].EDITPARENT.lLines)
				.If [Ebx].EDITPARENT.bTextUnicode
					Shl Eax, 1
					.If Word Ptr [Ecx + Eax - 2] != VK_RETURN
						Add Eax, 2
					.EndIf
					Shr Eax, 1
				.Else
					.If Byte Ptr [Ecx + Eax - 1] != VK_RETURN
						Inc Eax
					.EndIf
				.EndIf
			.EndIf
			.If (lFlags & RSC_DOWN)
				.If (lFlags & RSC_MATCHCASE)
					Invoke RSSearchCaseDown, Ecx, Eax, lTextLength, [Edi].RSSFINDTEXT.lpstr, lFlags
				.Else
					Invoke RSSearchNoCaseDown, Ecx, Eax, lTextLength, [Edi].RSSFINDTEXT.lpstr, lFlags
				.EndIf
			.Else
				.If (lFlags & RSC_MATCHCASE)
					Invoke RSSearchCaseUp, Ecx, Eax, lTextLength, [Edi].RSSFINDTEXT.lpstr, lFlags
				.Else
					Invoke RSSearchNoCaseUp, Ecx, Eax, lTextLength, [Edi].RSSFINDTEXT.lpstr, lFlags
				.EndIf
			.EndIf
			.If Eax != (-1)
				.If Esi == ChrInfMin.lLine
					Add Eax, ChrInfMin.lLineOffset
				.EndIf
				Mov Ecx, Eax
				Mov Eax, Esi
				Mov Esi, lpChildData
				Invoke RSGetLineIndex, Eax
				Add Eax, Ecx
				Ret
			.EndIf
L4:			.If (lFlags & RSC_DOWN)
				Add Edx, SizeOf LINE
				Inc Esi
				Cmp Esi, ChrInfMax.lLine
				Jle L2
			.Else
				Sub Edx, SizeOf LINE
				Dec Esi
				Jl L6
				Cmp Esi, ChrInfMin.lLine
				Jge L2
			.EndIf
		.EndIf
	.EndIf
L6:	Mov Eax, (-1)
	Ret
RSFindText EndP

;On enter Ebx = Pointer to editor parent's data
RSFreeLineMemory Proc Private
	.If [Ebx].EDITPARENT.lpszLine
		Mov Eax, [Ebx].EDITPARENT.lpszLine
		.If (Eax != [Ebx].EDITPARENT.lpszBuffer)
			Invoke VirtualFree, [Ebx].EDITPARENT.lpszLine, 0, MEM_RELEASE
		.EndIf
		Mov [Ebx].EDITPARENT.lpszLine, NULL
	.EndIf
	Ret
RSFreeLineMemory EndP

;On enter Ebx = Pointer to editor parent's data
RSGetBytes Proc Private lChars:LONG
	Mov Eax, lChars
	.If ([Ebx].EDITPARENT.bTextUnicode)
		Shl Eax, 1
	.EndIf
	Ret
RSGetBytes EndP

;On enter Ebx = Pointer to editor parent's data
RSGetCharInfo Proc Private Uses Ecx Edx Edi Esi lIndex:LONG, lpChrInf:DWord
	Mov Eax, lIndex
	Cmp Eax, [Ebx].EDITPARENT.lMaxIndex
	Jle @F
L2:	Mov Eax, (-1)
	Ret
@@:	Cmp Eax, 0
	Jl L2
	Invoke RSGetEditorDataPointer
	Mov Ecx, [Eax].EDITCHILD.lTopLineIndex
	Mov Edx, [Eax].EDITCHILD.lTopLine
	.If Ecx > SDWord Ptr [Ebx].EDITPARENT.lMaxIndex
		Xor Ecx, Ecx
		Xor Edx, Edx
	.EndIf
	Mov Edi, Edx
	Shl Edi, 4
	Add Edi, [Ebx].EDITPARENT.lpLinesPointer
	Mov Eax, lIndex
	Cmp Eax, Ecx
	Jl L8
L4:	Mov Esi, Ecx
	Add Ecx, [Edi].LINE.lLength
	Cmp Eax, Ecx
	Jl L6	;Found
	Cmp Edx, [Ebx].EDITPARENT.lLines
	Jl @F
	Cmp Eax, Ecx
	Jg L2
L6:	Sub Eax, Esi
	Mov Ecx, lpChrInf
	Mov [Ecx].RSSCHARINFO.lLineIndex, Esi
	Mov [Ecx].RSSCHARINFO.lLineOffset, Eax
	Mov [Ecx].RSSCHARINFO.lLine, Edx
	Invoke RSGetBytes, Eax
	Add Eax, [Edi].LINE.lpszText
	Ret
@@:	Add Edi, SizeOf LINE
	Inc Edx
	Jmp L4

L8:	Cmp Edx, 0
	Jg @F
	Cmp Eax, Ecx
	Jl L2
@@:	Sub Edi, SizeOf LINE
	Dec Edx
	Sub Ecx, [Edi].LINE.lLength
	Mov Esi, Ecx
	Cmp Eax, Ecx
	Jge L6	;Found
	Jmp L8
RSGetCharInfo EndP

;On enter Ebx = Pointer to editor parent's data
RSGetChars Proc Private lBytes:LONG
	Mov Eax, lBytes
	.If ([Ebx].EDITPARENT.bTextUnicode)
		Shr Eax, 1
	.EndIf
	Ret
RSGetChars EndP

RSGetChildWindowPos Proc Private Uses Edi hWnd:HWND, lpRect:LPLONG
	Mov Edi, lpRect
	Invoke GetWindowRect, hWnd, Edi
	.If Eax
		Mov Eax, [Edi].RECT.right
		Sub Eax, [Edi].RECT.left
		Push Eax
		Mov Eax, [Edi].RECT.bottom
		Sub Eax, [Edi].RECT.top
		Push Eax
		Invoke ScreenToClient, [Ebx].EDITPARENT.hWnd, Edi
		Pop Eax
		Add Eax, [Edi].RECT.top
		Mov [Edi].RECT.bottom, Eax
		Pop Eax
		Add Eax, [Edi].RECT.left
		Mov [Edi].RECT.right, Eax
	.EndIf
	Ret
RSGetChildWindowPos EndP

;On enter Ebx = Pointer to editor parent's data
RSGetEditorDataPointer Proc Private
	Mov Eax, [Ebx].EDITPARENT.hWndFocus
	.If (!Eax) || Eax == [Ebx].EDITPARENT.Editor.hWnd
		Lea Eax, [Ebx].EDITPARENT.Editor
	.Else
		Lea Eax, [Ebx].EDITPARENT.Mirror
	.EndIf
	Ret
RSGetEditorDataPointer EndP

;On enter Esi = Pointer to editor child's data
RSGetIndex Proc Private Uses Ecx Edx lLine:LONG, bUp:BOOL
	Mov Eax, [Ebx].EDITPARENT.lLines
	Cmp Eax, lLine
	Jge @F
	Mov lLine, Eax
@@:	Mov Eax, [Esi].EDITCHILD.chrSel.lMax
	Sub Eax, [Esi].EDITCHILD.lCurCol
	Mov Edx, [Esi].EDITCHILD.lCurLine
	Shl Edx, 4
	Add Edx, [Ebx].EDITPARENT.lpLinesPointer
	.If bUp
		Mov Ecx, [Esi].EDITCHILD.lCurLine
		Sub Ecx, lLine
		Jle L2
@@:		Sub Edx, SizeOf LINE
		Sub Eax, [Edx].LINE.lLength
		Dec Ecx
		Jnz @B
	.Else
		Mov Ecx, lLine
		Sub Ecx, [Esi].EDITCHILD.lCurLine
		Jle L2
@@:		Add Eax, [Edx].LINE.lLength
		Add Edx, SizeOf LINE
		Dec Ecx
		Jnz @B
	.EndIf
L2:	Mov Ecx, Eax
	Invoke RSGetNoTabExpandPosition, Edx, [Esi].EDITCHILD.lLastCol
	Add Eax, Ecx
	Ret
RSGetIndex EndP

;On enter Ebx = Pointer to parent's data
RSGetLastIndex Proc Private Uses Edx lpLine:LPLONG
	Mov Eax, [Ebx].EDITPARENT.lLines
	.If lpLine != NULL
		Mov Edx, lpLine
		Mov DWord Ptr [Edx], Eax
	.EndIf
	Mov Edx, Eax
	Shl Edx, 4
	Add Edx, [Ebx].EDITPARENT.lpLinesPointer
	Invoke RSGetLineIndex, Eax
	Add Eax, [Edx].LINE.lLength
	Ret
RSGetLastIndex EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to editor child's data
RSGetLine Proc Private lLine:LONG, lpszBuf:LPSTR
	Xor Eax, Eax
	Mov Edx, lLine
	.If Edx == (-1)
		Mov Edx, [Esi].EDITCHILD.lCurLine
	.EndIf
	.If (Edx >= SDWord Ptr 0 && Edx <= SDWord Ptr [Ebx].EDITPARENT.lLines)
		Shl Edx, 4
		Add Edx, [Ebx].EDITPARENT.lpLinesPointer
		Mov Eax, [Edx].LINE.lLength
		.If (lpszBuf != NULL)
			Mov Eax, lpszBuf
			Movzx Ecx, Word Ptr [Eax]
			Mov Word Ptr [Eax], 0
			.If Ecx > SDWord Ptr [Edx].LINE.lLength
				Mov Ecx, [Edx].LINE.lLength
			.EndIf
			Invoke RSMoveChars, lpszBuf, [Edx].LINE.lpszText, Ecx
		.EndIf
	.EndIf
	Ret
RSGetLine EndP

;On enter Ebx = Pointer to editor parent's data
RSGetLineFromChar Proc Private lIndex:LONG
	Local ChrInf:RSSCHARINFO

	Invoke RSGetCharInfo, lIndex, Addr ChrInf
	Mov Eax, ChrInf.lLine
	Ret
RSGetLineFromChar EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to editor child's data
RSGetLineIndex Proc Private Uses Edx Edi lLine:LONG
	Mov Eax, (-1)
	Mov Edx, [Ebx].EDITPARENT.lLines
	Cmp lLine, Edx
	Jg L4
	Cmp lLine, 0
	Jl L4
	Mov Edx, [Esi].EDITCHILD.lTopLine
	Mov Eax, [Esi].EDITCHILD.lTopLineIndex
	.If Edx > SDWord Ptr [Ebx].EDITPARENT.lLines
		Xor Eax, Eax
		Xor Edx, Edx
	.EndIf
	Mov Edi, Edx
	Shl Edx, 4
	Add Edx, [Ebx].EDITPARENT.lpLinesPointer
	Cmp lLine, Edi
	Jl L2
@@:	Cmp Edi, lLine
	Jge L4
	Add Eax, [Edx].LINE.lLength
	Add Edx, SizeOf LINE
	Inc Edi
	Jmp @B

L2:	Cmp Edi, lLine
	Jle L4
	Dec Edi
	Sub Edx, SizeOf LINE
	Sub Eax, [Edx].LINE.lLength
	Jmp L2
L4:	Ret
RSGetLineIndex EndP

;On enter Ebx = Pointer to editor parent's data
RSGetLines Proc Private lpszBuf:LPSTR
	Xor Ecx, Ecx
	Mov Edx, lpszBuf
	.If Edx
		.If [Ebx].EDITPARENT.bTextUnicode
			.If (Edx && Word Ptr [Edx])
@@:				Mov Ax, Word Ptr [Edx]
				Add Edx, 2
				Or Ax, Ax
				Jz L4
				Cmp Ax, VK_RETURN
				Jne @B
				Inc Ecx
				Jmp @B
			.EndIf
		.Else
			.If (Edx && Byte Ptr [Edx])
@@:				Mov Al, Byte Ptr [Edx]
				Inc Edx
				Or Al, Al
				Jz L4
				Cmp Al, VK_RETURN
				Jne @B
				Inc Ecx
				Jmp @B
			.EndIf
		.EndIf
	.EndIf
L4:	Mov Eax, Ecx
	Ret
RSGetLines EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to editor child's data
RSGetNextBookmark Proc Private Uses Ecx Edx
	Mov Ecx, [Esi].EDITCHILD.lCurLine
	Inc Ecx
	Cmp Ecx, SDWord Ptr [Ebx].EDITPARENT.lLines
	Jg @F
	Mov Edx, Ecx
	Shl Edx, 4
	Add Edx, [Ebx].EDITPARENT.lpLinesPointer
	.While Ecx <= SDWord Ptr [Ebx].EDITPARENT.lLines
		.If ([Edx].LINE.lState & STATE_BOOKMARK)
			Mov Eax, Ecx
			Ret
		.EndIf
		Add Edx, SizeOf LINE
		Inc Ecx
	.EndW
@@:	Mov Eax, (-1)
	Ret
RSGetNextBookmark EndP

;On enter Ebx = Pointer to parent's data
RSGetNoTabExpandPosition Proc Private Uses Ecx Edx Edi lLineAddr:LPLONG, lExpandedPos:LONG
	Local lLength:LONG, lTabs:LONG

	Mov Edx, lLineAddr
	Mov Eax, [Edx].LINE.lLength
	Or Eax, Eax
	Jnz @F
	Ret
@@:	Mov lLength, Eax
	Mov Eax, [Ebx].EDITPARENT.lTabSize
	Mov lTabs, Eax
	Dec lTabs
	Xor Ecx, Ecx
	Mov Edi, [Edx].LINE.lpszText
	Xor Edx, Edx
	Cmp [Ebx].EDITPARENT.bTextUnicode, FALSE
	Jne GetNoTabExpandPositionW
A2:	Cmp Ecx, lLength
	Jg A8
	Cmp Edx, lExpandedPos
	Jne @F
	Mov Eax, Ecx
	Jmp A8
@@:	Cmp Byte Ptr [Edi + Ecx], VK_TAB
	Je @F
	Inc Edx
	Jmp A6
@@:	Push Edx
	And Edx, lTabs
	Mov Eax, [Ebx].EDITPARENT.lTabSize
	Sub Eax, Edx
	Pop Edx
A4:	Cmp Eax, 0 ;Al
	Jle A6
	Inc Edx
	Cmp Edx, lExpandedPos
	Jne @F
	Push Ecx
	Mov Ecx, [Ebx].EDITPARENT.lTabSize
	Shr Cl, 1
	Cmp Al, Cl
	Pop Ecx
	Jc A6
	Dec Ecx
	Jmp A6
@@:	Dec Al
	Jmp A4
A6:	Cmp Edx, lExpandedPos
	Jne @F
	Inc Ecx
	Mov Eax, Ecx
	Jmp A8
@@:	Inc Ecx
	Jmp A2
A8:	Cmp Ecx, lLength
	Jl L2
	Mov Eax, lLength
	Or Eax, Eax
	Jz L2
	Cmp Byte Ptr [Edi + Eax - 1], VK_RETURN
	Jne L2
	Dec Eax
L2:	Ret

GetNoTabExpandPositionW:
	Cmp Ecx, lLength
	Jg W8
	Cmp Edx, lExpandedPos
	Jne @F
	Mov Eax, Ecx
	Jmp W8
@@:	Mov Eax, Ecx
	Shl Eax, 1
	Cmp Word Ptr [Edi + Eax], VK_TAB
	Je @F
	Inc Edx
	Jmp W6
@@:	Push Edx
	And Edx, lTabs
	Mov Eax, [Ebx].EDITPARENT.lTabSize
	Sub Eax, Edx
	Pop Edx
W4:	Cmp Eax, 0
	Jle W6
	Inc Edx
	Cmp Edx, lExpandedPos
	Jne @F
	Push Ecx
	Mov Ecx, [Ebx].EDITPARENT.lTabSize
	Shr Cx, 1
	Cmp Ax, Cx
	Pop Ecx
	Jc W6
	Dec Ecx
	Jmp W6
@@:	Dec Ax
	Jmp W4
W6:	Cmp Edx, lExpandedPos
	Jne @F
	Inc Ecx
	Mov Eax, Ecx
	Jmp W8
@@:	Inc Ecx
	Jmp GetNoTabExpandPositionW
W8:	Cmp Ecx, lLength
	Jl L2
	Mov Eax, lLength
	Or Eax, Eax
	Jz L2
	Shl Eax, 1
	Cmp Word Ptr [Edi + Eax - 2], VK_RETURN
	Jne @F
	Sub Eax, 2
@@:	Shr Eax, 1
	Jmp L2
RSGetNoTabExpandPosition EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to editor child's data
RSGetPreviousBookmark Proc Private Uses Ecx Edx
	Mov Ecx, [Esi].EDITCHILD.lCurLine
	Dec Ecx
	Jl @F
	Mov Edx, Ecx
	Shl Edx, 4
	Add Edx, [Ebx].EDITPARENT.lpLinesPointer
	.While SDWord Ptr Ecx >= 0
		.If ([Edx].LINE.lState & STATE_BOOKMARK)
			Mov Eax, Ecx
			Ret
		.EndIf
		Sub Edx, SizeOf LINE
		Dec Ecx
	.EndW
@@:	Mov Eax, (-1)
	Ret
RSGetPreviousBookmark EndP

RSGetRealColor Proc Private crColor:COLORREF
	Mov Eax, crColor
	Test Eax, 0FF000000H
	Jz @F
	And Eax, 000000FFH
	Invoke GetSysColor, Eax
@@:	Ret
RSGetRealColor EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to active editor child's data
RSGetSelectedText Proc Private Uses Ecx Edx Edi lpszBuf:LPSTR, lChars:LONG, bClipboard:BOOL
	Local ChrInfMin:RSSCHARINFO, ChrInfMax:RSSCHARINFO

	Mov Edi, lpszBuf
	Push [Esi].EDITCHILD.chrPos.lMax
	Push [Ebx].EDITPARENT.dwEventMask
	Invoke RSGetCharInfo, [Esi].EDITCHILD.chrPos.lMin, Addr ChrInfMin
	Cmp lChars, (-1)
	Je L2
	Invoke RSGetSelectedTextLength
	Cmp Eax, lChars
	Jle L2
	Mov [Ebx].EDITPARENT.dwEventMask, 0
	Mov Eax, [Esi].EDITCHILD.chrPos.lMin
	Add Eax, lChars
	Mov [Esi].EDITCHILD.chrPos.lMax, Eax
@@:	Invoke RSGetSelectedTextLength
	Cmp Eax, lChars
	Jle L2
	Dec [Esi].EDITCHILD.chrPos.lMax
	Jmp @B
L2:	Invoke RSGetCharInfo, [Esi].EDITCHILD.chrPos.lMax, Addr ChrInfMax
	Mov Edx, ChrInfMin.lLine
	Shl Edx, 4
	Add Edx, [Ebx].EDITPARENT.lpLinesPointer
	Invoke RSGetBytes, ChrInfMin.lLineOffset
	Mov Ecx, Eax
	Add Ecx, [Edx].LINE.lpszText
	Mov Eax, ChrInfMin.lLine
	.If Eax == ChrInfMax.lLine
		Mov Eax, [Esi].EDITCHILD.chrPos.lMax
		Sub Eax, [Esi].EDITCHILD.chrPos.lMin
	.Else
		Mov Eax, [Edx].LINE.lLength
		Sub Eax, ChrInfMin.lLineOffset
	.EndIf
	.If bClipboard
		Invoke RSTextToClipboard, Edi, Ecx, Eax, FALSE
	.Else
		Invoke RSMoveChars, Edi, Ecx, Eax
	.EndIf
	Invoke RSGetBytes, Eax
	Add Edi, Eax
	Mov Ecx, ChrInfMin.lLine
	.If Ecx != ChrInfMax.lLine
@@:		Add Edx, SizeOf LINE
		Inc Ecx
		Cmp Ecx, ChrInfMax.lLine
		Jge @F
		.If bClipboard
			Invoke RSTextToClipboard, Edi, [Edx].LINE.lpszText, [Edx].LINE.lLength, FALSE
		.Else
			Invoke RSMoveChars, Edi, [Edx].LINE.lpszText, [Edx].LINE.lLength
		.EndIf
		Invoke RSGetBytes, Eax
		Add Edi, Eax
		Jmp @B
@@:		.If bClipboard
			Invoke RSTextToClipboard, Edi, [Edx].LINE.lpszText, ChrInfMax.lLineOffset, FALSE
		.Else
			Invoke RSMoveChars, Edi, [Edx].LINE.lpszText, ChrInfMax.lLineOffset
		.EndIf
		Invoke RSGetBytes, Eax
		Add Edi, Eax
	.EndIf
	Pop [Ebx].EDITPARENT.dwEventMask
	Pop [Esi].EDITCHILD.chrPos.lMax
	Sub Edi, lpszBuf
	Invoke RSGetChars, Edi
	Ret
RSGetSelectedText EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to active editor child's data
RSGetSelectedTextLength Proc Private Uses Ecx Edx Edi
	Local ChrInfMin:RSSCHARINFO, ChrInfMax:RSSCHARINFO

	Invoke RSGetCharInfo, [Esi].EDITCHILD.chrPos.lMin, Addr ChrInfMin
	Invoke RSGetCharInfo, [Esi].EDITCHILD.chrPos.lMax, Addr ChrInfMax
	Xor Edi, Edi
	Mov Eax, ChrInfMin.lLine
	Mov Edx, Eax
	Shl Edx, 4
	Add Edx, [Ebx].EDITPARENT.lpLinesPointer
	Mov Ecx, [Edx].LINE.lpszText
	Add Ecx, ChrInfMin.lLineOffset
	.If Eax == ChrInfMax.lLine
		Mov Eax, [Esi].EDITCHILD.chrPos.lMax
		Sub Eax, [Esi].EDITCHILD.chrPos.lMin
	.Else
		Mov Eax, [Edx].LINE.lLength
		Sub Eax, ChrInfMin.lLineOffset
		Inc Eax
	.EndIf
	Add Edi, Eax
	Mov Ecx, ChrInfMin.lLine
	.If Ecx != ChrInfMax.lLine
@@:		Add Edx, SizeOf LINE
		Inc Ecx
		Cmp Ecx, ChrInfMax.lLine
		Jge @F
		Add Edi, [Edx].LINE.lLength
		Inc Edi
		Jmp @B
@@:		Add Edi, ChrInfMax.lLineOffset
	.EndIf
	Mov Eax, Edi
	Ret
RSGetSelectedTextLength EndP

;On enter Ebx = Pointer to editor parent's data
RSGetTextExtentExPoint Proc Private hdc:HDC, lpszStr:LPCSTR, cchString:LONG, nMaxExtent:LONG, lpnFit:LPINT, alpDx:LPINT, lpSize:DWord
	Push lpSize
	Push alpDx
	Push lpnFit
	Push nMaxExtent
	Push cchString
	Push lpszStr
	Push hdc
	.If [Ebx].EDITPARENT.bTextUnicode
		Mov Eax, GetTextExtentExPointW
	.Else
		Mov Eax, GetTextExtentExPointA
	.EndIf
	Call Eax
	Ret
RSGetTextExtentExPoint EndP

;On enter Ebx = Pointer to editor parent's data
RSGetTextExtentPoint32 Proc Private hdc:HDC, lpString:LPCSTR, cbString:LONG, lpSize:DWord
	Push lpSize
	Push cbString
	Push lpString
	Push hdc
	.If [Ebx].EDITPARENT.bTextUnicode
		Mov Eax, GetTextExtentPoint32W
	.Else
		Mov Eax, GetTextExtentPoint32A
	.EndIf
	Call Eax
	Ret
RSGetTextExtentPoint32 EndP

;On enter Ebx = Pointer to editor parent's data
RSGetTextLength Proc Private Uses Ecx Edx lpszBuf:LPSTR
	Push lpszBuf
	.If ([Ebx].EDITPARENT.bTextUnicode)
		Mov Eax, lstrlenW
	.Else
		Mov Eax, lstrlen
	.EndIf
	Call Eax
	Ret
RSGetTextLength EndP

;On enter Esi = Pointer to text buffer, Ecx = Relative offset to buffer pointed by Esi
RSGetWideCharFromUTF8 Proc Private Uses Edi
	Mov Ah, Byte Ptr [Esi + Ecx]
	Inc Ecx
	Mov Edi, Ecx
	Xchg Al, Ah
	Mov Cx, Ax
	And Ch, 11100000B
	.If Ch == 11000000B
		And Cl, 11000000B
		.If Cl == 10000000B
			Mov Cl, Al
			Xor Al, Al
			And Ah, 00011111B
			Shr Ax, 2
			And Cl, 00111111B
			Or Al, Cl
		.Else
@@:			Dec Edi
			Mov Ax, 0FFFFH
		.EndIf
	.Else
		Mov Ch, Ah
		And Ch, 11110000B
		Cmp Ch, 11100000B
		Jne @B
		And Cl, 11000000B
		Cmp Cl, 10000000B
		Jne @B
		Mov Cl, Al
		Xor Al, Al
		And Ah, 00001111B
		Shr Ax, 2
		And Cl, 00111111B
		Or Al, Cl
		Mov Cl, Byte Ptr [Esi + Edi]
		Mov Ch, Cl
		And Ch, 11000000B
		Cmp Ch, 10000000B
		Jne @B
		Inc Edi
		And Cl, 00111111B
		Shl Ax, 6
		Or Al, Cl
	.EndIf
	Mov Ecx, Edi
	Ret
RSGetWideCharFromUTF8 EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to active editor child's data
RSGetWordPosition Proc Private lIndex:LONG, bStart:BOOL
	Mov Eax, (-1)
	Mov Ecx, lIndex
	Cmp Ecx, 0
	Jge @F
	Ret
@@:	Cmp Ecx, [Ebx].EDITPARENT.lMaxIndex
	Jle @F
	Ret
@@:	Push [Ebx].EDITPARENT.dwEventMask
	Mov [Ebx].EDITPARENT.dwEventMask, 0
	Push [Esi].EDITCHILD.chrSel.lMin
	Push [Esi].EDITCHILD.chrSel.lMax
	Invoke RSSelectWord, lIndex, FALSE
	Pop [Esi].EDITCHILD.chrSel.lMax
	Pop [Esi].EDITCHILD.chrSel.lMin
	.If bStart
		Mov Eax, [Esi].EDITCHILD.chrPos.lMin
	.Else
		Mov Eax, [Esi].EDITCHILD.chrPos.lMax
	.EndIf
	Push Eax
	Invoke RSSetPosition, [Esi].EDITCHILD.chrSel.lMin, [Esi].EDITCHILD.chrSel.lMax
	Pop Eax
	Pop [Ebx].EDITPARENT.dwEventMask
	Ret
RSGetWordPosition EndP

;On enter Ebx = Pointer to editor parent's data
RSHeapAlloc Proc Private Uses Ecx Edx lChars:LONG
	Invoke RSGetBytes, lChars
	Invoke HeapAlloc, [Ebx].EDITPARENT.hHeap, HEAP_ZERO_MEMORY, Eax
	.If (!Eax)
		IFDEF (DEBUG)
			Invoke GetLastError
			.If (Eax == ERROR_NOT_ENOUGH_MEMORY)
				Push Eax
				Invoke RSClearUndoEntryFrom, 0
				Mov [Ebx].EDITPARENT.lUndoCount, 0
				Mov [Ebx].EDITPARENT.lLastUndoCount, 0
				Invoke MessageBox, [Ebx].EDITPARENT.hWndParent, TextStr ("Undo buffer has been emptied."), Addr RSEditorCtrl, (MB_ICONERROR OR MB_OK)
				Invoke RSGetBytes, lChars
				Invoke HeapAlloc, [Ebx].EDITPARENT.hHeap, HEAP_ZERO_MEMORY, Eax
				Pop Eax
				Invoke SetLastError, Eax
			.EndIf
		ENDIF
		.If (!Eax)
			Invoke RSShowMemoryError
		.EndIf
	.EndIf
	Ret
RSHeapAlloc EndP

;On enter Ebx = Pointer to editor parent's data
RSInitEditor Proc Private Uses Edx
	Mov [Ebx].EDITPARENT.bInsert, TRUE
	Mov [Ebx].EDITPARENT.lLines, 0
	Mov Edx, [Ebx].EDITPARENT.lpLinesPointer
	Mov Eax, [Ebx].EDITPARENT.lpTextPointer
	Mov [Ebx].EDITPARENT.lpszNextText, Eax
	Mov [Edx].LINE.lpszText, Eax
	Mov DWord Ptr [Eax], 0
	Mov [Ebx].EDITPARENT.lMaxIndex, 0
	Mov [Edx].LINE.lMaxLength, MIN_LINE_SIZE
	Mov [Ebx].EDITPARENT.bModified, FALSE
	Mov [Ebx].EDITPARENT.Editor.lPaint, PAINT_ALL
	Mov [Ebx].EDITPARENT.Editor.lTopLine, 0
	Mov [Ebx].EDITPARENT.Editor.lTopLineIndex, 0
	Mov [Ebx].EDITPARENT.Editor.chrPos.lMin, 0
	Mov [Ebx].EDITPARENT.Editor.chrPos.lMax, 0
	Mov [Ebx].EDITPARENT.Editor.lCurLine, 0
	Mov [Ebx].EDITPARENT.Editor.lCurCol, 0
	Mov [Ebx].EDITPARENT.Editor.lLastCol, 0
	Mov [Ebx].EDITPARENT.Editor.lRealCol, 0
	.If [Ebx].EDITPARENT.Mirror.hWnd != NULL
		Invoke DestroyWindow, [Ebx].EDITPARENT.Mirror.hWnd
	.EndIf
	Ret
RSInitEditor EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to active editor child's data
RSInsertText Proc Private Uses Ecx Edx Edi lpszBuf:LPSTR, lLength:LONG, lLines:LONG
	Local lpszTemp1:LPSTR, lpszTemp2:LPSTR
	Local lState:LONG, ChrInf:RSSCHARINFO

	Mov Edi, lpszBuf
	Invoke RSGetCharInfo, [Esi].EDITCHILD.chrPos.lMin, Addr ChrInf
	Mov Ecx, lLines
	Push [Ebx].EDITPARENT.dwEventMask
	Mov [Ebx].EDITPARENT.dwEventMask, 0
	Cmp [Ebx].EDITPARENT.bTextUnicode, FALSE
	Jne InsertTextW
	.If Ecx
		Mov [Esi].EDITCHILD.lPaint, PAINT_ALL
		Invoke RSCheckBufferSize, Ecx, RSC_LINES
		Cmp Eax, (-1)
		Jne @F
A2:		Pop [Ebx].EDITPARENT.dwEventMask
		Ret
@@:		Mov Edx, ChrInf.lLine
		Shl Edx, 4
		Add Edx, [Ebx].EDITPARENT.lpLinesPointer
		Mov Eax, [Edx].LINE.lLength
		Add Eax, lLength
		Invoke RSGetBytes, Eax
		Invoke RSCheckBufferSize, Eax, RSC_TEXT
		Cmp Eax, (-1)
		Je A2
		Mov lpszTemp1, NULL
		Mov lpszTemp2, NULL
		Push Ecx
		.If ChrInf.lLineOffset
			Mov Eax, ChrInf.lLineOffset
			Inc Eax
			Invoke RSGetBytes, Eax
			Push Edx
			Invoke GlobalAlloc, GPTR, Eax
			Mov lpszTemp1, Eax
			Pop Edx
			Mov Eax, [Edx].LINE.lState
			Mov lState, Eax
			Mov [Edx].LINE.lState, 0
			Invoke RSMoveChars, lpszTemp1, [Edx].LINE.lpszText, ChrInf.lLineOffset
		.EndIf
		Mov Eax, [Edx].LINE.lLength
		Sub Eax, ChrInf.lLineOffset
		Jz @F
		Mov Ecx, Eax
		Push Ecx
		Push Edx
		Inc Ecx
		Invoke RSGetBytes, Ecx
		Invoke GlobalAlloc, GPTR, Eax
		Mov lpszTemp2, Eax
		Pop Edx
		Pop Ecx
		Invoke RSGetBytes, ChrInf.lLineOffset
		Add Eax, [Edx].LINE.lpszText
		Invoke RSMoveChars, lpszTemp2, Eax, Ecx
@@:		Pop Ecx
		Push Ecx
		Push Edi
		Mov Edx, [Ebx].EDITPARENT.lLines
		Mov Edi, Edx
		Shl Edx, 4
		Add Edx, [Ebx].EDITPARENT.lpLinesPointer
		Add Edi, Ecx
		Shl Edi, 4
		Add Edi, [Ebx].EDITPARENT.lpLinesPointer
		Mov Eax, [Ebx].EDITPARENT.lLines
		Sub Eax, ChrInf.lLine
		Add [Ebx].EDITPARENT.lLines, Ecx
		.If Eax
			Mov Ecx, Eax
			Inc Ecx
			.While Ecx
				Mov Eax, [Edx]
				Mov [Edi], Eax
				Mov Eax, [Edx + 4]
				Mov [Edi + 4], Eax
				Mov Eax, [Edx + 8]
				Mov [Edi + 8], Eax
				Mov Eax, [Edx + 12]
				Mov [Edi + 12], Eax
				Sub Edx, SizeOf LINE
				Sub Edi, SizeOf LINE
				Dec Ecx
			.EndW
		.EndIf
		Pop Edi
		Pop Ecx
		.If Byte Ptr [Edi]
			Mov [Esi].EDITCHILD.lPaint, PAINT_FROM_PREV_LINE
			Push Esi
			Mov Esi, [Ebx].EDITPARENT.lpszNextText
			.If lpszTemp1
				Invoke RSGetTextLength, lpszTemp1
				Push Eax
				Invoke RSMoveChars, Esi, lpszTemp1, Eax
				Pop Eax
				Invoke RSGetBytes, Eax
				Add Esi, Eax
			.EndIf
@@:			Mov Al, Byte Ptr [Edi]
			.If Al
				Mov Byte Ptr [Esi], Al
				Inc Esi
				Inc Edi
				.If Al == VK_RETURN
					Mov Eax, Esi
					Sub Eax, [Ebx].EDITPARENT.lpszNextText
					Invoke RSSetLineInfo, ChrInf.lLine, Eax
					.If lpszTemp1
						Push Ecx
						Invoke GlobalFree, lpszTemp1
						Mov lpszTemp1, NULL
						Pop Ecx
						Mov Edx, ChrInf.lLine
						Shl Edx, 4
						Add Edx, [Ebx].EDITPARENT.lpLinesPointer
						Mov Eax, lState
						Mov [Edx].LINE.lState, Eax
					.EndIf
					Inc ChrInf.lLine
					Dec Ecx
				.EndIf
				Cmp Ecx, 0
				Jg @B
			.EndIf
			Mov Edx, [Ebx].EDITPARENT.lLines
			.If Edx <= SDWord Ptr ChrInf.lLine
				Shl Edx, 4
				Add Edx, [Ebx].EDITPARENT.lpLinesPointer
				Mov Eax, [Ebx].EDITPARENT.lpszNextText
				Mov [Edx].LINE.lpszText, Eax
				Mov [Edx].LINE.lLength, 0
				Mov [Edx].LINE.lState, 0
				Mov [Edx].LINE.lMaxLength, 1
				Invoke RSGetBytes, 1
				Add [Ebx].EDITPARENT.lpszNextText, Eax
			.EndIf
			Pop Esi
		.EndIf
		.If lpszTemp1
			Invoke GlobalFree, lpszTemp1
			Mov lpszTemp1, NULL
		.EndIf
		Mov Edx, ChrInf.lLine
		Shl Edx, 4
		Add Edx, [Ebx].EDITPARENT.lpLinesPointer
		.If Byte Ptr [Edi]
			Push Esi
			Mov Esi, [Ebx].EDITPARENT.lpszNextText
@@:			Mov Al, Byte Ptr [Edi]
			Mov Byte Ptr [Esi], Al
			Or Al, Al
			Jz @F
			Inc Esi
			Inc Edi
			Jmp @B
@@:			Cmp lpszTemp2, NULL
			Je A4
			Mov Ecx, lpszTemp2
@@:			Mov Al, Byte Ptr [Ecx]
			Or Al, Al
			Jz @F
			Mov Byte Ptr [Esi], Al
			Inc Esi
			Inc Ecx
			Jmp @B
@@:			Push Edx
			Invoke GlobalFree, lpszTemp2
			Mov lpszTemp2, NULL
			Pop Edx
A4:			Mov Eax, Esi
			Sub Eax, [Ebx].EDITPARENT.lpszNextText
			Push [Edx].LINE.lState
			Invoke RSSetLineInfo, ChrInf.lLine, Eax
			Pop [Edx].LINE.lState
			Inc [Edx].LINE.lMaxLength
			Inc [Ebx].EDITPARENT.lpszNextText
			Pop Esi
		.Else
			.If lpszTemp2 == NULL
				Mov Eax, ChrInf.lLine
				Cmp Eax, [Ebx].EDITPARENT.lLines
				Jl @F
				Cmp lpszTemp1, NULL
				Je @F
				Mov Eax, [Ebx].EDITPARENT.lpszNextText
				Mov [Edx].LINE.lpszText, Eax
				Mov [Edx].LINE.lLength, 0
				Mov [Edx].LINE.lState, 0
				Mov [Edx].LINE.lMaxLength, 1
				Invoke RSGetBytes, 1
				Add [Ebx].EDITPARENT.lpszNextText, Eax
			.Else
				Mov [Edx].LINE.lLength, 0
			.EndIf
		.EndIf
@@:		.If lpszTemp2
			Invoke RSGetTextLength, lpszTemp2
			Mov Ecx, Eax
			Mov Eax, [Edx].LINE.lLength
			Mov ChrInf.lLineOffset, Eax
			Invoke RSAddCharsToLine, lpszTemp2, Ecx, Addr ChrInf
			Invoke GlobalFree, lpszTemp2
		.EndIf
	.Else
		Mov Edx, ChrInf.lLine
		Shl Edx, 4
		Add Edx, [Ebx].EDITPARENT.lpLinesPointer
		Mov [Esi].EDITCHILD.lPaint, PAINT_LINE
		Cmp lLength, 1
		Jg @F
		Mov Ecx, [Edx].LINE.lpszText
		Invoke RSGetBytes, ChrInf.lLineOffset
		Add Ecx, Eax
		Cmp Byte Ptr [Ecx], VK_RETURN
		Je @F
		Mov Eax, ChrInf.lLineOffset
		Cmp Eax, [Edx].LINE.lLength
		Je @F
		Cmp [Ebx].EDITPARENT.bInsert, FALSE
		Jne @F
		Mov Al, Byte Ptr [Edi]
		Mov Byte Ptr [Ecx], Al
		Mov Eax, lLength
		Jmp L2
@@:		Invoke RSAddCharsToLine, Edi, lLength, Addr ChrInf
	.EndIf
	Mov Eax, lLength
	Add [Ebx].EDITPARENT.lMaxIndex, Eax
L2:	Pop [Ebx].EDITPARENT.dwEventMask
	Add [Esi].EDITCHILD.chrPos.lMin, Eax
	Add [Esi].EDITCHILD.chrPos.lMax, Eax
	Ret

InsertTextW:
	.If Ecx
		Mov [Esi].EDITCHILD.lPaint, PAINT_ALL
		Invoke RSCheckBufferSize, Ecx, RSC_LINES
		Cmp Eax, (-1)
		Jne @F
W2:		Pop [Ebx].EDITPARENT.dwEventMask
		Ret
@@:		Mov Edx, ChrInf.lLine
		Shl Edx, 4
		Add Edx, [Ebx].EDITPARENT.lpLinesPointer
		Mov Eax, [Edx].LINE.lLength
		Add Eax, lLength
		Invoke RSGetBytes, Eax
		Invoke RSCheckBufferSize, Eax, RSC_TEXT
		Cmp Eax, (-1)
		Je W2
		Mov lpszTemp1, NULL
		Mov lpszTemp2, NULL
		Push Ecx
		.If ChrInf.lLineOffset
			Mov Eax, ChrInf.lLineOffset
			Inc Eax
			Invoke RSGetBytes, Eax
			Push Edx
			Invoke GlobalAlloc, GPTR, Eax
			Mov lpszTemp1, Eax
			Pop Edx
			Mov Eax, [Edx].LINE.lState
			Mov lState, Eax
			Mov [Edx].LINE.lState, 0
			Invoke RSMoveChars, lpszTemp1, [Edx].LINE.lpszText, ChrInf.lLineOffset
		.EndIf
		Mov Eax, [Edx].LINE.lLength
		Sub Eax, ChrInf.lLineOffset
		Jz @F
		Mov Ecx, Eax
		Push Ecx
		Push Edx
		Inc Ecx
		Invoke RSGetBytes, Ecx
		Invoke GlobalAlloc, GPTR, Eax
		Mov lpszTemp2, Eax
		Pop Edx
		Pop Ecx
		Invoke RSGetBytes, ChrInf.lLineOffset
		Add Eax, [Edx].LINE.lpszText
		Invoke RSMoveChars, lpszTemp2, Eax, Ecx
@@:		Pop Ecx
		Push Ecx
		Push Edi
		Mov Edx, [Ebx].EDITPARENT.lLines
		Mov Edi, Edx
		Shl Edx, 4
		Add Edx, [Ebx].EDITPARENT.lpLinesPointer
		Add Edi, Ecx
		Shl Edi, 4
		Add Edi, [Ebx].EDITPARENT.lpLinesPointer
		Mov Eax, [Ebx].EDITPARENT.lLines
		Sub Eax, ChrInf.lLine
		Add [Ebx].EDITPARENT.lLines, Ecx
		.If Eax
			Mov Ecx, Eax
			Inc Ecx
			.While Ecx
				Mov Eax, [Edx]
				Mov [Edi], Eax
				Mov Eax, [Edx + 4]
				Mov [Edi + 4], Eax
				Mov Eax, [Edx + 8]
				Mov [Edi + 8], Eax
				Mov Eax, [Edx + 12]
				Mov [Edi + 12], Eax
				Sub Edx, SizeOf LINE
				Sub Edi, SizeOf LINE
				Dec Ecx
			.EndW
		.EndIf
		Pop Edi
		Pop Ecx
		.If Word Ptr [Edi]
			Mov [Esi].EDITCHILD.lPaint, PAINT_FROM_PREV_LINE
			Push Esi
			Mov Esi, [Ebx].EDITPARENT.lpszNextText
			.If lpszTemp1
				Invoke RSGetTextLength, lpszTemp1
				Push Eax
				Invoke RSMoveChars, Esi, lpszTemp1, Eax
				Pop Eax
				Invoke RSGetBytes, Eax
				Add Esi, Eax
			.EndIf
@@:			Mov Ax, Word Ptr [Edi]
			.If Ax
				Mov Word Ptr [Esi], Ax
				Add Esi, 2
				Add Edi, 2
				.If Ax == VK_RETURN
					Mov Eax, Esi
					Sub Eax, [Ebx].EDITPARENT.lpszNextText
					Invoke RSSetLineInfo, ChrInf.lLine, Eax
					.If lpszTemp1
						Push Ecx
						Invoke GlobalFree, lpszTemp1
						Mov lpszTemp1, NULL
						Pop Ecx
						Mov Edx, ChrInf.lLine
						Shl Edx, 4
						Add Edx, [Ebx].EDITPARENT.lpLinesPointer
						Mov Eax, lState
						Mov [Edx].LINE.lState, Eax
					.EndIf
					Inc ChrInf.lLine
					Dec Ecx
				.EndIf
				Cmp Ecx, 0
				Jg @B
			.EndIf
			Mov Edx, [Ebx].EDITPARENT.lLines
			.If Edx <= SDWord Ptr ChrInf.lLine
				Shl Edx, 4
				Add Edx, [Ebx].EDITPARENT.lpLinesPointer
				Mov Eax, [Ebx].EDITPARENT.lpszNextText
				Mov [Edx].LINE.lpszText, Eax
				Mov [Edx].LINE.lLength, 0
				Mov [Edx].LINE.lState, 0
				Mov [Edx].LINE.lMaxLength, 1
				Invoke RSGetBytes, 1
				Add [Ebx].EDITPARENT.lpszNextText, Eax
			.EndIf
			Pop Esi
		.EndIf
		.If lpszTemp1
			Invoke GlobalFree, lpszTemp1
			Mov lpszTemp1, NULL
		.EndIf
		Mov Edx, ChrInf.lLine
		Shl Edx, 4
		Add Edx, [Ebx].EDITPARENT.lpLinesPointer
		.If Word Ptr [Edi]
			Push Esi
			Mov Esi, [Ebx].EDITPARENT.lpszNextText
@@:			Mov Ax, Word Ptr [Edi]
			Mov Word Ptr [Esi], Ax
			Or Ax, Ax
			Jz @F
			Add Esi, 2
			Add Edi, 2
			Jmp @B
@@:			Cmp lpszTemp2, NULL
			Je W4
			Mov Ecx, lpszTemp2
@@:			Mov Ax, Word Ptr [Ecx]
			Or Ax, Ax
			Jz @F
			Mov Word Ptr [Esi], Ax
			Add Esi, 2
			Add Ecx, 2
			Jmp @B
@@:			Push Edx
			Invoke GlobalFree, lpszTemp2
			Mov lpszTemp2, NULL
			Pop Edx
W4:			Mov Eax, Esi
			Sub Eax, [Ebx].EDITPARENT.lpszNextText
			Push [Edx].LINE.lState
			Invoke RSSetLineInfo, ChrInf.lLine, Eax
			Pop [Edx].LINE.lState
			Inc [Edx].LINE.lMaxLength
			Inc [Ebx].EDITPARENT.lpszNextText
			Pop Esi
		.Else
			.If lpszTemp2 == NULL
				Mov Eax, ChrInf.lLine
				Cmp Eax, [Ebx].EDITPARENT.lLines
				Jl @F
				Cmp lpszTemp1, NULL
				Je @F
				Mov Eax, [Ebx].EDITPARENT.lpszNextText
				Mov [Edx].LINE.lpszText, Eax
				Mov [Edx].LINE.lLength, 0
				Mov [Edx].LINE.lState, 0
				Mov [Edx].LINE.lMaxLength, 1
				Invoke RSGetBytes, 1
				Add [Ebx].EDITPARENT.lpszNextText, Eax
			.Else
				Mov [Edx].LINE.lLength, 0
			.EndIf
		.EndIf
@@:		.If lpszTemp2
			Invoke RSGetTextLength, lpszTemp2
			Mov Ecx, Eax
			Mov Eax, [Edx].LINE.lLength
			Mov ChrInf.lLineOffset, Eax
			Invoke RSAddCharsToLine, lpszTemp2, Ecx, Addr ChrInf
			Invoke GlobalFree, lpszTemp2
		.EndIf
	.Else
		Mov Edx, ChrInf.lLine
		Shl Edx, 4
		Add Edx, [Ebx].EDITPARENT.lpLinesPointer
		Mov [Esi].EDITCHILD.lPaint, PAINT_LINE
		Cmp lLength, 1
		Jg @F
		Mov Ecx, [Edx].LINE.lpszText
		Invoke RSGetBytes, ChrInf.lLineOffset
		Add Ecx, Eax
		Cmp Word Ptr [Ecx], VK_RETURN
		Je @F
		Mov Eax, ChrInf.lLineOffset
		Cmp Eax, [Edx].LINE.lLength
		Je @F
		Cmp [Ebx].EDITPARENT.bInsert, FALSE
		Jne @F
		Mov Ax, Word Ptr [Edi]
		Mov Word Ptr [Ecx], Ax
		Mov Eax, lLength
		Jmp L2
@@:		Invoke RSAddCharsToLine, Edi, lLength, Addr ChrInf
	.EndIf
	Mov Eax, lLength
	Add [Ebx].EDITPARENT.lMaxIndex, Eax
	Jmp L2
RSInsertText EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to editor child's data
RSInvalidateEditor Proc Private Uses Esi hWnd:HWND, bNow:BOOL
	.If [Ebx].EDITPARENT.bRedraw
		Invoke RSRedrawEditor, hWnd, bNow
		.If [Ebx].EDITPARENT.Mirror.hWnd
			Mov Eax, hWnd
			.If Eax == [Ebx].EDITPARENT.Mirror.hWnd
				Lea Esi, [Ebx].EDITPARENT.Editor
				Mov Eax, [Esi].EDITCHILD.hWnd
			.Else
				Lea Esi, [Ebx].EDITPARENT.Mirror
				Mov Eax, [Esi].EDITCHILD.hWnd
			.EndIf
			Mov [Esi].EDITCHILD.lPaint, PAINT_ALL
			Invoke RSRedrawEditor, Eax, bNow
		.EndIf
	.EndIf
	Ret
RSInvalidateEditor EndP

;On enter Ebx = Pointer to editor parent's data
RSIsBlockEditable Proc Private Uses Ecx Edx lFirstLine:LONG, lLastLine:LONG
	Mov Ecx, lFirstLine
	Mov Edx, Ecx
	Shl Edx, 4
	Add Edx, [Ebx].EDITPARENT.lpLinesPointer
	.While Ecx <= SDWord Ptr lLastLine
		.If ([Edx].LINE.lState & STATE_LOCKED)
			Invoke MessageBeep, MB_OK
			Xor Eax, Eax
			Ret
		.EndIf
		Add Edx, SizeOf LINE
		Inc Ecx
	.EndW
	Mov Eax, TRUE
	Ret
RSIsBlockEditable EndP

;On enter Ebx = Pointer to editor parent's data
RSIsCharAlphaNumeric Proc Private Uses Ecx Edx lChar:LONG
	Push lChar
	Call [Ebx].EDITPARENT.RSIsAlphaProcAddr
	Or Eax, Eax
	Jz @F
	Ret
@@:	Invoke IsCharAlphaNumeric, lChar
	Ret
RSIsCharAlphaNumeric EndP

RSIsCharAlphaProc Proc Private Uses Ecx Edx lChar:LONG
	Invoke IsCharAlpha, lChar
	Ret
RSIsCharAlphaProc EndP

;On enter Esi = Pointer to active editor child's data
RSIsLineInClientArea Proc Private lLine:LONG
	Mov Eax, [Esi].EDITCHILD.lTopLine
	Cmp lLine, Eax
	Jl @F
	Add Eax, [Esi].EDITCHILD.lVScrollPage
	Dec Eax
	Cmp lLine, Eax
	Jg @F
	Mov Eax, TRUE
	Ret
@@:	Xor Eax, Eax
	Ret
RSIsLineInClientArea EndP

RSIsUTF8Text Proc Private Uses Esi lpszTxt:LPSTR, lLength:LONG
	Mov Esi, lpszTxt
	Xor Ecx, Ecx
@@:	Cmp Ecx, lLength
	Jge @F
	Xor Ah, Ah
	Mov Al, Byte Ptr [Esi + Ecx]
	Inc Ecx
	Cmp Al, 0C0H
	Jc @B
	Invoke RSGetWideCharFromUTF8
	Cmp Ax, 0FFFFH
	Je @F
	Mov Eax, TRUE
L2:	Ret

@@:	Xor Eax, Eax
	Jmp L2
RSIsUTF8Text EndP

;On enter Ebx = Pointer to editor parent's data, Edx = Pointer to line data
RSIsWholeWord Proc Private Uses Esi lpszString:LPSTR, lOffset:LONG, lSearchLength:LONG
	Mov Esi, lpszString
	Cmp [Ebx].EDITPARENT.bTextUnicode, FALSE
	Jne IsWholeWordW
	Add Esi, lOffset
	Cmp lOffset, 0
	Je @F
	Movzx Eax, Byte Ptr [Esi - 1]
	Invoke RSIsCharAlphaNumeric, Eax
	Or Eax, Eax
	Jnz L4
@@:	Add Esi, lSearchLength
	Movzx Eax, Byte Ptr [Esi]
L2:	Invoke RSIsCharAlphaNumeric, Eax
	Or Eax, Eax
	Jnz L4
	Mov Eax, lOffset
	Ret
L4:	Mov Eax, (-1)
	Ret

IsWholeWordW:
	Shl lOffset, 1
	Add Esi, lOffset
	Cmp lOffset, 0
	Je @F
	Movzx Eax, Word Ptr [Esi - 2]
	Invoke RSIsCharAlphaNumeric, Eax
	Or Eax, Eax
	Jnz L4
@@:	Invoke RSGetBytes, lSearchLength
	Add Esi, Eax
	Movzx Eax, Word Ptr [Esi]
	Jmp L2
RSIsWholeWord EndP

;On enter Ebx = Pointer to editor parent's data
RSKillScrollTimer Proc Private
	.If [Ebx].EDITPARENT.uVScrollTimer != 0
		Invoke KillTimer, [Ebx].EDITPARENT.hWnd, [Ebx].EDITPARENT.uVScrollTimer
		Mov [Ebx].EDITPARENT.uVScrollTimer, 0
		Mov [Ebx].EDITPARENT.hWndTimer, NULL
	.EndIf
	Ret
RSKillScrollTimer EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to active editor child's data
RSLockLines Proc Private lFirst:LONG, lLast:LONG
	Mov Ecx, lFirst
	Cmp Ecx, 0
	Jge @F
L2:	Xor Eax, Eax
	Ret
@@:	Cmp Ecx, SDWord Ptr [Ebx].EDITPARENT.lLines
	Jg L2
	Mov Eax, lLast
	Cmp Eax, Ecx
	Jl L2
	Cmp Eax, 0
	Jl L2
	Cmp Eax, SDWord Ptr [Ebx].EDITPARENT.lLines
	Jg L2
	Mov Edx, Ecx
	Shl Edx, 4
	Add Edx, [Ebx].EDITPARENT.lpLinesPointer
	.While Ecx <= SDWord Ptr lLast
		Or [Edx].LINE.lState, STATE_LOCKED
		Inc Ecx
		Add Edx, SizeOf LINE
	.EndW
	Mov [Esi].EDITCHILD.lPaint, PAINT_ALL
	Invoke RSInvalidateEditor, [Esi].EDITCHILD.hWnd, TRUE ;FALSE
	Ret
RSLockLines EndP

;On enter Ebx = Pointer to editor parent's data
RSModifyUndo Proc Private Uses Ecx Edx Edi Esi lpszSource:LPSTR, lpszNewChar:LPSTR, lOffset:LONG
	Mov Esi, lpszSource
	Mov Edi, [Ebx].EDITPARENT.lpszBuffer
	Xor Edx, Edx
	Cmp [Ebx].EDITPARENT.bTextUnicode, FALSE
	Jne ModifyUndoW
A2:	Mov Al, Byte Ptr [Esi]
	Cmp Edx, lOffset
	Jne @F
	Mov Eax, lpszNewChar
	Mov Al, Byte Ptr [Eax]
	Mov Byte Ptr [Edi], Al
	Inc Edi
	Mov Al, Byte Ptr [Esi]
	Or Al, Al
	Jz @F
	Cmp [Ebx].EDITPARENT.bInsert, FALSE
	Jne @F
	Inc Esi
@@:	Mov Byte Ptr [Edi], Al
	Or Al, Al
	Jz L2
	Inc Esi
	Inc Edi
	Inc Edx
	Jmp A2
L2:	Ret

ModifyUndoW:
	Mov Ax, Word Ptr [Esi]
	Cmp Edx, lOffset
	Jne @F
	Mov Eax, lpszNewChar
	Mov Ax, Word Ptr [Eax]
	Mov Word Ptr [Edi], Ax
	Add Edi, 2
	Mov Ax, Word Ptr [Esi]
	Or Ax, Ax
	Jz @F
	Cmp [Ebx].EDITPARENT.bInsert, FALSE
	Jne @F
	Add Esi, 2
@@:	Mov Word Ptr [Edi], Ax
	Or Ax, Ax
	Jz L2
	Add Esi, 2
	Add Edi, 2
	Inc Edx
	Jmp ModifyUndoW
RSModifyUndo EndP

RSMoveChars Proc Private Uses Ecx Edx lpDest:LPLONG, lpSource:LPLONG, lChars:LONG
	Mov Eax, lChars
	.If (Eax > SDWord Ptr 0)
		Invoke RSGetBytes, Eax
		Invoke RtlMoveMemory, lpDest, lpSource, Eax
		Mov Eax, lChars
	.EndIf
	Ret
RSMoveChars EndP

;On enter Esi = Pointer to active editor child's data
RSNextBookmark Proc Private
	Invoke RSGetNextBookmark
	.If Eax != (-1)
		Invoke RSGetLineIndex, Eax
		Invoke RSSetSelection, Eax, Eax, 0
		Mov Eax, TRUE
	.EndIf
	Ret
RSNextBookmark EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to active editor child's data
RSOnChar Proc Private Uses Edi hWnd:HWND, wParam:WPARAM, lKeyState:LONG
	Local ChrInf:RSSCHARINFO

	Cmp wParam, VK_RETURN
	Je @F
	Cmp wParam, VK_TAB
	Je @F
	Cmp wParam, VK_BACK
	Je @F
	Cmp wParam, VK_SPACE
	Jge @F
L2:	Xor Eax, Eax
	Ret
@@:	.If wParam == VK_BACK
		Cmp [Esi].EDITCHILD.chrPos.lMin, 0
		Jle L2
		Mov Eax, [Esi].EDITCHILD.chrPos.lMin
		.If Eax == [Esi].EDITCHILD.chrPos.lMax
			Dec Eax
			Xchg [Esi].EDITCHILD.chrPos.lMin, Eax
L4:			Mov Ecx, Eax
			Invoke RSCanDelete
			.If (!Eax)
				Mov [Esi].EDITCHILD.chrPos.lMin, Ecx
				Ret
			.EndIf
		.EndIf
		Invoke RSReplaceSelection, NULL, wParam
		.If (!Eax)
			Ret
		.EndIf
	.ElseIf wParam == 127 ;Ctrl+VK_BACK
		.If !(lKeyState & KEY_CTRL)
			Jmp L2
		.EndIf
		.If (lKeyState & KEY_SHIFT)
			Jmp L2
		.EndIf
		Invoke RSFindPrevWord, [Esi].EDITCHILD.chrPos.lMin
		Cmp Eax, [Esi].EDITCHILD.chrPos.lMin
		Je L2
		Xchg [Esi].EDITCHILD.chrPos.lMin, Eax
		Jmp L4
	.Else
		Mov Eax, wParam
		.If [Ebx].EDITPARENT.bTextUnicode
			Mov Word Ptr RSszChar[0], Ax
			Mov Word Ptr RSszChar[2], 0
		.Else
			Mov RSszChar[0], Al
			Mov RSszChar[1], 0
		.EndIf
		.If Eax == VK_TAB && [Ebx].EDITPARENT.bTabToSpaces
			Mov RSszChar[0], ' '
			Invoke RSGetCharInfo, [Esi].EDITCHILD.chrPos.lMin, Addr ChrInf
			Mov Eax, ChrInf.lLineOffset
			Mov Ecx, [Ebx].EDITPARENT.lTabSize
			Dec Ecx
			And Eax, Ecx
			Inc Ecx
			Sub Ecx, Eax
			.While Ecx
				Invoke RSReplaceSelection, Addr RSszChar, VK_SPACE
				.If (!Eax)
					Ret
				.EndIf
				Dec Ecx
			.EndW
		.ElseIf Eax == VK_RETURN && [Ebx].EDITPARENT.bAutoIndent
			Invoke RSGetCharInfo, [Esi].EDITCHILD.chrPos.lMin, Addr ChrInf
			Mov Edx, [Esi].EDITCHILD.lCurLine
			Shl Edx, 4
			Add Edx, [Ebx].EDITPARENT.lpLinesPointer
			Mov Ecx, [Edx].LINE.lLength
			Mov Edx,[Edx].LINE.lpszText
			Mov Edi, [Ebx].EDITPARENT.lpszBuffer
			.If [Ebx].EDITPARENT.bTextUnicode
				Mov Word Ptr [Edi], VK_RETURN
				Add Edi, 2
			.Else
				Mov Byte Ptr [Edi], VK_RETURN
				Inc Edi
			.EndIf
			.If ChrInf.lLineOffset
				.While Ecx > SDWord Ptr 0
@@:					.If [Ebx].EDITPARENT.bTextUnicode
						Mov Ax, Word Ptr [Edx]
						.If Ax != ' ' && Ax != VK_TAB
							.Break
						.EndIf
						Mov Word Ptr [Edi], Ax
						Add Edi, 2
						Add Edx, 2
					.Else
						Mov Al, Byte Ptr [Edx]
						.If Al != ' ' && Al != VK_TAB
							.Break
						.EndIf
						Mov Byte Ptr [Edi], Al
						Inc Edi
						Inc Edx
					.EndIf
					Dec Ecx
				.EndW
			.EndIf
			.If [Ebx].EDITPARENT.bTextUnicode
				Mov Word Ptr [Edi], 0
			.Else
				Mov Byte Ptr [Edi], 0
			.EndIf
			Invoke RSReplaceSelection, [Ebx].EDITPARENT.lpszBuffer, wParam
		.Else
			Invoke RSReplaceSelection, Addr RSszChar, wParam
			.If (!Eax)
				Ret
			.EndIf
		.EndIf
	.EndIf
	Invoke RSSetSelection, [Esi].EDITCHILD.chrPos.lMin, [Esi].EDITCHILD.chrPos.lMax, wParam
	Invoke RSSendCommandMessage, EN_CHANGE
	Xor Eax, Eax
	Ret
RSOnChar EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to active editor child's data
RSOnEditorMouseMessage Proc Private Uses Ecx Edx Edi uMsg:ULONG, wParam:WPARAM, lParam:LPARAM
	Local l1:LONG, lExpandedCol:LONG
	Local pt:POINTL, sz:SIZEL

	Mov [Esi].EDITCHILD.lPaint, PAINT_ALL
	HiWord lParam
	Cwde
	Cdq
	IDiv [Ebx].EDITPARENT.szFont.y
	Add Eax, [Esi].EDITCHILD.lTopLine
	Jge @F
	Xor Eax, Eax
@@:	Mov pt.y, Eax
	Cmp Eax, [Ebx].EDITPARENT.lLines
	Jle @F
	Mov Eax, [Ebx].EDITPARENT.lMaxIndex
	Jmp L2
@@:	LoWord lParam
	Cwde
	Cdq
	Sub Eax, [Ebx].EDITPARENT.lSelBarWidth
	Cmp Eax, 0
	Jge @F
	Xor Eax, Eax
@@:	Mov pt.x, Eax
	Mov Edx, pt.y
	Shl Edx, 4
	Add Edx, [Ebx].EDITPARENT.lpLinesPointer
	Invoke RSExpandTabs, Edx, NULL
	Push Edx
	Push Eax
	Invoke GetDC, [Esi].EDITCHILD.hWnd
	Mov Edi, Eax
	Invoke SelectObject, Edi, [Ebx].EDITPARENT.hFont
	Pop Ecx
	Push Eax

	Mov Eax, pt.x
	Add Eax, [Ebx].EDITPARENT.lHScrollPos
	Mov l1, Eax
	Mov lExpandedCol, 0
	Or Ecx, Ecx
	Jz @F
	Invoke RSGetTextExtentExPoint, Edi, [Ebx].EDITPARENT.lpszLine, Ecx, l1, Addr lExpandedCol, NULL, Addr sz
@@:	Invoke RSGetTextExtentPoint32, Edi, [Ebx].EDITPARENT.lpszLine, lExpandedCol, Addr sz
	Mov Eax, l1
	Sub Eax, sz.x
	Mov l1, Eax
	Mov Ecx, [Ebx].EDITPARENT.lpszLine
	Mov sz.x, 0
	.If Ecx
		Invoke RSGetBytes, lExpandedCol
		Add Ecx, Eax
		Invoke RSGetTextExtentPoint32, Edi, Ecx, 1, Addr sz
	.EndIf
	Mov Eax, sz.x
	Shr Eax, 1
	.If SDWord Ptr l1 >= Eax
		Inc lExpandedCol
	.EndIf

	Pop Eax
	Invoke SelectObject, Edi, Eax
	Invoke ReleaseDC, [Esi].EDITCHILD.hWnd, Edi
	Invoke RSFreeLineMemory
	Pop Edx
	Invoke RSGetNoTabExpandPosition, Edx, lExpandedCol
	Mov Ecx, Eax
	Invoke RSGetLineIndex, pt.y
	Add Eax, Ecx
L2:	Mov pt.x, Eax
	.If (wParam & MK_SHIFT && uMsg == WM_LBUTTONDOWN)
		Mov Ecx, [Esi].EDITCHILD.chrSel.lMin
		Mov [Esi].EDITCHILD.chrPos.lMin, Ecx
	.EndIf
	Cmp uMsg, WM_RBUTTONDOWN
	Je L4
	Cmp uMsg, WM_MBUTTONDOWN
	Je L4
	.If (wParam & MK_CONTROL)
		.If uMsg == WM_LBUTTONDOWN && !(wParam & MK_SHIFT)
			Mov Ecx, [Esi].EDITCHILD.chrPos.lMin
			.If Ecx == [Esi].EDITCHILD.chrPos.lMax || Eax < Ecx || Eax > [Esi].EDITCHILD.chrPos.lMax
				Invoke RSSelectWord, Eax, FALSE
				Mov Eax, [Esi].EDITCHILD.chrPos.lMax
			.Else
				Mov [Esi].EDITCHILD.chrPos.lMin, Eax
			.EndIf
			Mov [Esi].EDITCHILD.lPaint, PAINT_ALL
		.Else
			Invoke RSSelectWord, [Esi].EDITCHILD.chrSel.lMin, TRUE
			Mov Eax, [Esi].EDITCHILD.chrSel.lMin
			.If Eax == [Esi].EDITCHILD.chrSel.lMax
				.If SDWord Ptr pt.x > Eax
					Mov Eax, [Esi].EDITCHILD.chrPos.lMin
				.Else
					Mov Eax, [Esi].EDITCHILD.chrPos.lMax
				.EndIf
			.Else
				.If SDWord Ptr pt.x > Eax
					Mov Eax, [Esi].EDITCHILD.chrPos.lMin
				.Else
					.If Eax > [Esi].EDITCHILD.chrPos.lMax
						Mov Eax, [Esi].EDITCHILD.chrSel.lMin
					.Else
						Mov Eax, [Esi].EDITCHILD.chrPos.lMax
					.EndIf
				.EndIf
			.EndIf
			Mov pt.y, Eax
			Invoke RSSelectWord, pt.x, TRUE
			Mov Eax, [Esi].EDITCHILD.chrSel.lMin
			.If SDWord Ptr pt.x > Eax
				Mov Eax, [Esi].EDITCHILD.chrPos.lMax
			.Else
				Mov Eax, [Esi].EDITCHILD.chrPos.lMin
			.EndIf
			Push pt.y
			Pop [Esi].EDITCHILD.chrPos.lMin
		.EndIf
	.ElseIf !(wParam & MK_SHIFT)
		Mov [Esi].EDITCHILD.chrPos.lMin, Eax
	.EndIf
	.If (!(wParam & MK_SHIFT) || uMsg == WM_LBUTTONDOWN)
		Mov [Esi].EDITCHILD.chrPos.lMax, Eax
	.EndIf
	.If uMsg == WM_MOUSEMOVE
		.If Eax > SDWord Ptr [Esi].EDITCHILD.lSelStart
			.If ((wParam & MK_SHIFT) || (wParam & MK_CONTROL))
				Invoke RSSetSelection, [Esi].EDITCHILD.chrPos.lMin, [Esi].EDITCHILD.chrPos.lMax, 0
			.Else
				Invoke RSSetSelection, [Esi].EDITCHILD.lSelStart, [Esi].EDITCHILD.chrPos.lMax, 0
			.EndIf
		.Else
			.If ((wParam & MK_SHIFT) || (wParam & MK_CONTROL))
				Invoke RSSetSelection, [Esi].EDITCHILD.chrSel.lMin, [Esi].EDITCHILD.chrSel.lMax, 0
			.Else
				Invoke RSSetSelection, [Esi].EDITCHILD.lSelStart, [Esi].EDITCHILD.chrPos.lMin, 0
			.EndIf
		.EndIf
	.EndIf
L4:	Ret
RSOnEditorMouseMessage EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to active editor child's data
RSOnKeyDown Proc Private Uses Edi hWnd:HWND, wParam:WPARAM, lKeyState:LONG
	Local bTextChanged:BOOL, lMin:LONG
	Local lMax:LONG, ChrInf:RSSCHARINFO

	Mov bTextChanged, FALSE
	Mov Edi, [Esi].EDITCHILD.lCurLine
	Shl Edi, 4
	Add Edi, [Ebx].EDITPARENT.lpLinesPointer
	.If wParam == VK_SHIFT || wParam == VK_CONTROL || wParam == VK_MENU
		Jmp L8
	.ElseIf (lKeyState & KEY_CTRL)
		.If !(lKeyState & KEY_SHIFT) && !(lKeyState & KEY_ALT)
			.If wParam == 65 ;Ctrl+A
				Mov [Esi].EDITCHILD.lPaint, PAINT_ALL
				Invoke RSSetSelection, 0, [Ebx].EDITPARENT.lMaxIndex, wParam
				Jmp L8
			.ElseIf wParam == 67 || wParam == VK_INSERT ;Ctrl+C or Ctrl+Insert
				Invoke SendMessage, hWnd, WM_COPY, 0, 0
				Jmp L8
			.ElseIf wParam == 86 ;Ctrl+V
				.If ![Ebx].EDITPARENT.bReadOnly
					Invoke SendMessage, hWnd, WM_PASTE, 0, 0
				.EndIf
				Jmp L8
			.ElseIf wParam == 88 ;Ctrl+X
				.If ![Ebx].EDITPARENT.bReadOnly
					Invoke SendMessage, hWnd, WM_CUT, 0, 0
				.EndIf
				Jmp L8
			.ElseIf wParam == 89 ;Ctrl+Y
				.If ![Ebx].EDITPARENT.bReadOnly
					Invoke SendMessage, hWnd, EM_REDO, 0, 0
				.EndIf
				Jmp L8
			.ElseIf wParam == 90 ;Ctrl+Z
				.If ![Ebx].EDITPARENT.bReadOnly
					Invoke SendMessage, hWnd, WM_UNDO, 0, 0
				.EndIf
				Jmp L8
			.EndIf
		.EndIf
	.ElseIf !(lKeyState & KEY_SHIFT) && !(lKeyState & KEY_ALT)
		.If wParam == VK_ESCAPE
			Mov Eax, [Esi].EDITCHILD.chrPos.lMax
			.If Eax != [Esi].EDITCHILD.chrPos.lMin
				Mov Eax, [Esi].EDITCHILD.chrSel.lMax
				Mov [Esi].EDITCHILD.chrPos.lMin, Eax
				Mov [Esi].EDITCHILD.chrPos.lMax, Eax
				Invoke RSSetSelection, Eax, Eax, wParam
			.EndIf
			Jmp L8
		.ElseIf wParam == VK_INSERT
			Xor [Ebx].EDITPARENT.bInsert, 1
			Invoke RSSetSelection, [Esi].EDITCHILD.chrSel.lMin, [Esi].EDITCHILD.chrSel.lMax, 0
			Invoke RSSetCaret
			Jmp L8
		.ElseIf wParam == VK_F6
			Invoke SendMessage, [Ebx].EDITPARENT.hWnd, RSM_CHANGEACTIVEEDITOR, 0, 0
			Ret
		.EndIf
	.EndIf
	.If (lKeyState & KEY_SHIFT) && !(lKeyState & KEY_CTRL) && !(lKeyState & KEY_ALT)
		.If wParam == VK_INSERT ;Shift+Insert
			.If ![Ebx].EDITPARENT.bReadOnly
				Invoke SendMessage, hWnd, WM_PASTE, 0, 0
				Jmp L8
			.EndIf
		.EndIf
	.EndIf
	Mov Eax, [Esi].EDITCHILD.chrSel.lMin
	Mov lMin, Eax
	Mov Eax, [Esi].EDITCHILD.chrSel.lMax
	Mov lMax, Eax
	Invoke RSGetLineIndex, [Esi].EDITCHILD.lCurLine
	Mov Ecx, Eax
	.If wParam == VK_DELETE
		Invoke RSCanDelete
		.If !Eax
L1:			Ret
		.EndIf
		.If !(lKeyState & KEY_SHIFT) && !(lKeyState & KEY_ALT)
			.If (lKeyState & KEY_CTRL)
				Invoke RSFindNextWord, [Esi].EDITCHILD.chrPos.lMax
				Mov Ecx, [Esi].EDITCHILD.chrPos.lMax
				.If Eax != Ecx || Ecx != [Esi].EDITCHILD.chrPos.lMin
					Xchg Eax, [Esi].EDITCHILD.chrPos.lMax
					Mov lMax, Eax
					Invoke RSCanDelete
					Or Eax, Eax
					Jnz @F
					Mov Eax, lMax
					Mov [Esi].EDITCHILD.chrPos.lMax, Eax
					Jmp L8
				.EndIf
			.Else
				Mov Eax, [Esi].EDITCHILD.chrPos.lMax
				.If Eax == [Esi].EDITCHILD.chrPos.lMin
					Cmp Eax, [Ebx].EDITPARENT.lMaxIndex
					Jnc L8
					Inc [Esi].EDITCHILD.chrPos.lMax
					Invoke RSCanDelete
					.If (!Eax)
						Dec [Esi].EDITCHILD.chrPos.lMax
						Jmp L8
					.EndIf
				.EndIf
@@:				Invoke RSReplaceSelection, NULL, wParam
				Or Eax, Eax
				Jz L1
				Mov lMin, (-1)
				Mov [Esi].EDITCHILD.lPaint, PAINT_FROM_PREV_LINE ;Invoke RSInvalidateEditor, hWnd, TRUE ;FALSE
			.EndIf
			Mov [Ebx].EDITPARENT.bModified, TRUE
			Mov bTextChanged, TRUE
		.EndIf
	.ElseIf wParam == VK_HOME
		.If (lKeyState & KEY_CTRL)
			Invoke RSGetLineIndex, 0
			.If (lKeyState & KEY_SHIFT)
				Mov [Esi].EDITCHILD.chrPos.lMax, Eax
				Mov Eax, [Esi].EDITCHILD.chrSel.lMin
				Mov [Esi].EDITCHILD.chrPos.lMin, Eax
			.Else
				Mov [Esi].EDITCHILD.chrPos.lMin, Eax
				Mov [Esi].EDITCHILD.chrPos.lMax, Eax
			.EndIf
L2:			Mov [Esi].EDITCHILD.lPaint, PAINT_ALL
		.ElseIf (lKeyState & KEY_SHIFT)
			Invoke RSToggleLineStart
			Add Eax, Ecx
			Mov Edx, Eax
			Mov Eax, [Esi].EDITCHILD.chrSel.lMax
			.If [Esi].EDITCHILD.chrSel.lMin != Eax
				Mov Eax, [Esi].EDITCHILD.chrSel.lMin
				Mov [Esi].EDITCHILD.chrPos.lMin, Eax
			.EndIf
			Mov Eax, Edx
			Mov [Esi].EDITCHILD.chrPos.lMax, Eax
			Mov [Esi].EDITCHILD.lPaint, PAINT_LINE
		.Else
			Mov [Esi].EDITCHILD.lPaint, PAINT_LINE
			Mov Eax, [Esi].EDITCHILD.chrPos.lMin
			.If Eax != [Esi].EDITCHILD.chrPos.lMax
				Invoke RSGetCharInfo, [Esi].EDITCHILD.chrPos.lMax, Addr ChrInf
				Mov Edx, ChrInf.lLine
				Invoke RSGetCharInfo, [Esi].EDITCHILD.chrPos.lMin, Addr ChrInf
				.If Edx != ChrInf.lLine
					Invoke RSSetPosition, [Esi].EDITCHILD.chrPos.lMin, [Esi].EDITCHILD.chrPos.lMin
					Mov Ecx, ChrInf.lLineIndex
					Mov Eax, [Esi].EDITCHILD.chrPos.lMin
				.EndIf
			.EndIf
			Invoke RSToggleLineStart
			Add Eax, Ecx
			Mov [Esi].EDITCHILD.chrPos.lMin, Eax
			Mov [Esi].EDITCHILD.chrPos.lMax, Eax
		.EndIf
	.ElseIf wParam == VK_END
		.If (lKeyState & KEY_CTRL)
			Invoke RSGetLastIndex, NULL
			.If (lKeyState & KEY_SHIFT)
				Mov Edx, [Esi].EDITCHILD.chrSel.lMax
				.If Edx < SDWord Ptr [Esi].EDITCHILD.chrSel.lMin
					Mov Edx, [Esi].EDITCHILD.chrPos.lMax
					Mov [Esi].EDITCHILD.chrPos.lMin, Edx
				.EndIf
			.Else
				Mov [Esi].EDITCHILD.chrPos.lMin, Eax
			.EndIf
			Mov [Esi].EDITCHILD.chrPos.lMax, Eax
			Mov [Esi].EDITCHILD.lPaint, PAINT_ALL
		.ElseIf (lKeyState & KEY_SHIFT)
			Mov Edx, [Edi].LINE.lpszText
			Mov Eax, [Esi].EDITCHILD.chrSel.lMax
			.If Eax < [Esi].EDITCHILD.chrSel.lMin
				Mov Eax, [Esi].EDITCHILD.chrPos.lMax
				Mov [Esi].EDITCHILD.chrPos.lMin, Eax
				Mov Eax, [Edi].LINE.lLength
				.If Eax
					Invoke RSGetBytes, Eax
					.If [Ebx].EDITPARENT.bTextUnicode
						.If Word Ptr [Edx + Eax - 2] == VK_RETURN
							Sub Eax, 2
						.EndIf
					.Else
						.If Byte Ptr [Edx + Eax - 1] == VK_RETURN
							Dec Eax
						.EndIf
					.EndIf
					Invoke RSGetChars, Eax
				.EndIf
				Add Eax, Ecx
				Mov [Esi].EDITCHILD.chrPos.lMax, Eax
			.Else
				Mov Eax, [Edi].LINE.lLength
				.If Eax
					Invoke RSGetBytes, Eax
					.If [Ebx].EDITPARENT.bTextUnicode
						.If Word Ptr [Edx + Eax - 2] == VK_RETURN
							Sub Eax, 2
						.EndIf
					.Else
						.If Byte Ptr [Edx + Eax - 1] == VK_RETURN
							Dec Eax
						.EndIf
					.EndIf
					Invoke RSGetChars, Eax
				.EndIf
				Add Eax, Ecx
				Mov [Esi].EDITCHILD.chrPos.lMax, Eax
			.EndIf
			Mov [Esi].EDITCHILD.lPaint, PAINT_LINE
			Jmp L5
		.Else
			Mov [Esi].EDITCHILD.lPaint, PAINT_LINE
			Mov Eax, [Esi].EDITCHILD.chrPos.lMax
			.If Eax != [Esi].EDITCHILD.chrPos.lMin
				Invoke RSGetCharInfo, [Esi].EDITCHILD.chrPos.lMin, Addr ChrInf
				Mov Edx, ChrInf.lLine
				Invoke RSGetCharInfo, [Esi].EDITCHILD.chrPos.lMax, Addr ChrInf
				.If Edx != ChrInf.lLine
					Invoke RSSetPosition, [Esi].EDITCHILD.chrPos.lMax, [Esi].EDITCHILD.chrPos.lMax
					Mov Ecx, ChrInf.lLineIndex
					Mov Edi, ChrInf.lLine
					Shl Edi, 4
					Add Edi, [Ebx].EDITPARENT.lpLinesPointer
				.EndIf
			.EndIf
			Mov Edx, [Edi].LINE.lpszText
			Mov Eax, [Edi].LINE.lLength
			.If Eax
				Invoke RSGetBytes, Eax
				.If [Ebx].EDITPARENT.bTextUnicode
					.If Word Ptr [Edx + Eax - 2] == VK_RETURN
						Sub Eax, 2
					.EndIf
				.Else
					.If Byte Ptr [Edx + Eax - 1] == VK_RETURN
						Dec Eax
					.EndIf
				.EndIf
				Invoke RSGetChars, Eax
			.EndIf
			Add Eax, Ecx
			Mov [Esi].EDITCHILD.chrPos.lMin, Eax
			Mov [Esi].EDITCHILD.chrPos.lMax, Eax
		.EndIf
	.ElseIf wParam == VK_LEFT
		.If ([Esi].EDITCHILD.chrPos.lMin == Ecx)
			.If (Ecx> SDWord Ptr 0)
				Mov Eax, [Esi].EDITCHILD.lCurLine
				Dec Eax
				.If (Eax >= SDWord Ptr 0)
					Invoke RSGetLineIndex, Eax
					Mov Ecx, Eax
				.EndIf
			.EndIf
		.EndIf
		.If (lKeyState & KEY_CTRL)
			Invoke RSFindPrevWord, [Esi].EDITCHILD.chrSel.lMax
			Mov Edx, Eax
			Mov Eax, [Esi].EDITCHILD.chrSel.lMin
			.If (Eax != [Esi].EDITCHILD.chrSel.lMax && !(lKeyState & KEY_SHIFT))
				Mov Eax, [Esi].EDITCHILD.chrPos.lMin
				Mov [Esi].EDITCHILD.chrPos.lMax, Eax
				Jmp @F
			.Else
				Mov [Esi].EDITCHILD.chrPos.lMin, Eax
				.If Eax == [Esi].EDITCHILD.chrSel.lMax
					.If (SDWord Ptr [Esi].EDITCHILD.chrPos.lMin > Ecx)
						Mov [Esi].EDITCHILD.chrPos.lMax, Edx
					.EndIf
				.Else
					Mov [Esi].EDITCHILD.chrPos.lMax, Edx
				.EndIf
				.If (lKeyState & KEY_SHIFT)
@@:					Mov [Esi].EDITCHILD.lPaint, PAINT_LINE
				.Else
					Mov Eax, [Esi].EDITCHILD.chrPos.lMax
					Mov [Esi].EDITCHILD.chrPos.lMin, Eax
				.EndIf
			.EndIf
		.ElseIf (lKeyState & KEY_SHIFT)
			Mov Eax, [Esi].EDITCHILD.chrSel.lMax
			.If Eax == [Esi].EDITCHILD.chrSel.lMin
				.If (SDWord Ptr [Esi].EDITCHILD.chrPos.lMin > Ecx)
					Dec [Esi].EDITCHILD.chrPos.lMax
				.EndIf
			.Else
				Mov Edx, [Esi].EDITCHILD.chrSel.lMin
				Mov [Esi].EDITCHILD.chrPos.lMin, Edx
				.If (SDWord Ptr [Esi].EDITCHILD.chrSel.lMax > Ecx || SDWord Ptr [Esi].EDITCHILD.chrSel.lMax > 0)
					Dec Eax
				.EndIf
				Mov [Esi].EDITCHILD.chrPos.lMax, Eax
			.EndIf
			Jmp @B
		.Else
			Mov Eax, [Esi].EDITCHILD.chrSel.lMax
			.If (Eax == [Esi].EDITCHILD.chrSel.lMin)
				.If (SDWord Ptr [Esi].EDITCHILD.chrPos.lMin > Ecx)
					Dec [Esi].EDITCHILD.chrPos.lMin
					Dec [Esi].EDITCHILD.chrPos.lMax
				.EndIf
			.Else
				Mov Eax, [Esi].EDITCHILD.chrPos.lMin
				Mov [Esi].EDITCHILD.chrPos.lMax, Eax
			.EndIf
		.EndIf
	.ElseIf wParam == VK_RIGHT
		Mov Edx, [Ebx].EDITPARENT.lMaxIndex
		.If (lKeyState & KEY_CTRL)
			Mov Eax, [Esi].EDITCHILD.chrSel.lMin
			.If (Eax != [Esi].EDITCHILD.chrSel.lMax && !(lKeyState & KEY_SHIFT))
				Mov Eax, [Esi].EDITCHILD.chrPos.lMax
				Mov [Esi].EDITCHILD.chrPos.lMin, Eax
				Jmp @F
			.Else
				Mov [Esi].EDITCHILD.chrPos.lMin, Eax
				Invoke RSFindNextWord, [Esi].EDITCHILD.chrSel.lMax
				Mov [Esi].EDITCHILD.chrPos.lMax, Eax
				.If (lKeyState & KEY_SHIFT)
@@:					Mov [Esi].EDITCHILD.lPaint, PAINT_FROM_PREV_LINE
				.Else
					Mov Eax, [Esi].EDITCHILD.chrPos.lMax
					Mov [Esi].EDITCHILD.chrPos.lMin, Eax
				.EndIf
			.EndIf
		.ElseIf (lKeyState & KEY_SHIFT)
			Mov Eax, [Esi].EDITCHILD.chrSel.lMax
			.If Eax == [Esi].EDITCHILD.chrSel.lMin
				.If (SDWord Ptr [Esi].EDITCHILD.chrPos.lMax < Edx)
					Inc [Esi].EDITCHILD.chrPos.lMax
				.EndIf
			.Else
				Mov Ecx, [Esi].EDITCHILD.chrSel.lMin
				Mov [Esi].EDITCHILD.chrPos.lMin, Ecx
				.If (SDWord Ptr [Esi].EDITCHILD.chrSel.lMax < Edx)
					Inc Eax
				.EndIf
				Mov [Esi].EDITCHILD.chrPos.lMax, Eax
			.EndIf
			Jmp @B
		.Else
			Mov Eax, [Esi].EDITCHILD.chrSel.lMax
			.If (Eax == [Esi].EDITCHILD.chrSel.lMin)
				.If (SDWord Ptr [Esi].EDITCHILD.chrPos.lMax < Edx)
					Inc [Esi].EDITCHILD.chrPos.lMin
					Inc [Esi].EDITCHILD.chrPos.lMax
				.EndIf
			.Else
				Mov Eax, [Esi].EDITCHILD.chrPos.lMax
				Mov [Esi].EDITCHILD.chrPos.lMin, Eax
			.EndIf
		.EndIf
	.ElseIf wParam == VK_UP
		Mov Edx, 0
		.If (lKeyState & KEY_CTRL) && !(lKeyState & KEY_SHIFT)
			Mov Eax, [Esi].EDITCHILD.chrSel.lMax
			.If Eax != [Esi].EDITCHILD.chrSel.lMin
				Invoke RSSetSelection, Eax, Eax, wParam
			.EndIf
			.If SDWord Ptr [Esi].EDITCHILD.lTopLine > Edx
				Invoke RSScroll, (-1), 0
				Invoke RSGetLineFromChar, [Esi].EDITCHILD.chrPos.lMin
				Mov Edx, Eax
				Mov Eax, [Esi].EDITCHILD.lVScrollPage
				Add Eax, [Esi].EDITCHILD.lTopLine
				Cmp Edx, Eax
				Jl @F
				Dec Edx
				Invoke RSGetIndex, Edx, TRUE
				Invoke RSSetSelection, Eax, Eax, wParam
@@:				Invoke RSInvalidateEditor, hWnd, FALSE
				Jmp L5
			.EndIf
		.Else
			Mov Ecx, [Esi].EDITCHILD.lCurLine
			.If !(lKeyState & KEY_SHIFT)
				Mov Eax, [Esi].EDITCHILD.chrPos.lMin
				Cmp Eax, [Esi].EDITCHILD.chrPos.lMax
				Je @F
				Invoke RSGetLineFromChar, [Esi].EDITCHILD.chrPos.lMin
				Mov Ecx, Eax
			.EndIf
@@:			Cmp Ecx, Edx
			Jle L4
			Dec Ecx
L4:			Mov [Esi].EDITCHILD.lPaint, PAINT_FROM_PREV_LINE
			Xor Eax, Eax
			.If wParam == VK_UP
				Inc Eax
			.EndIf
			.If (lKeyState & KEY_SHIFT)
				Invoke RSGetIndex, Ecx, Eax
				Mov Ecx, [Esi].EDITCHILD.chrSel.lMin
				Cmp Ecx, [Esi].EDITCHILD.chrSel.lMax
				Jle @F
				Mov [Esi].EDITCHILD.chrPos.lMin, Ecx
@@:				Mov [Esi].EDITCHILD.chrPos.lMax, Eax
			.Else
				Invoke RSGetIndex, Ecx, Eax
				Mov [Esi].EDITCHILD.chrPos.lMin, Eax
				Mov [Esi].EDITCHILD.chrPos.lMax, Eax
			.EndIf
		.EndIf
	.ElseIf wParam == VK_DOWN
		Mov Edx, [Ebx].EDITPARENT.lLines
		.If (lKeyState & KEY_CTRL) && !(lKeyState & KEY_SHIFT)
			Mov Eax, [Esi].EDITCHILD.chrSel.lMax
			.If Eax != [Esi].EDITCHILD.chrSel.lMin
				Invoke RSSetSelection, Eax, Eax, wParam
			.EndIf
			Mov Eax, [Esi].EDITCHILD.lCurLine
			.If Eax < Edx
				Invoke RSScroll, 1, 0
				Invoke RSGetLineFromChar, [Esi].EDITCHILD.chrPos.lMax
				Mov Edx, Eax
				Cmp Edx, [Esi].EDITCHILD.lTopLine
				Jge @F
				Invoke RSGetIndex, [Esi].EDITCHILD.lTopLine, FALSE
				Invoke RSSetSelection, Eax, Eax, wParam
@@:				Invoke RSInvalidateEditor, hWnd, FALSE
				Jmp L5
			.EndIf
		.Else
			Mov Eax, [Esi].EDITCHILD.chrPos.lMax
			Mov Ecx, [Esi].EDITCHILD.lCurLine
			.If !(lKeyState & KEY_SHIFT)
				Cmp Eax, [Esi].EDITCHILD.chrPos.lMin
				Je @F
				Invoke RSGetLineFromChar, [Esi].EDITCHILD.chrPos.lMax
				Mov Ecx, Eax
			.EndIf
@@:			Cmp Ecx, Edx
			Jge L4
			Inc Ecx
			Jmp L4
		.EndIf
	.ElseIf wParam == VK_PRIOR
		.If !(lKeyState & KEY_CTRL)
			Mov Eax, [Ebx].EDITPARENT.lLines
			.If Eax > SDWord Ptr [Esi].EDITCHILD.lVScrollPage
				Xor Ecx, Ecx
				.If (SDWord Ptr [Esi].EDITCHILD.lTopLine > 0)
					Mov Ecx, [Esi].EDITCHILD.lCurLine
					Sub Ecx, [Esi].EDITCHILD.lTopLine
				.EndIf
				Mov Eax, [Esi].EDITCHILD.lTopLine
				Sub Eax, [Esi].EDITCHILD.lVScrollPage
				Inc Eax
				Jge @F
				Xor Eax, Eax
@@:				Push Eax
				Add Eax, Ecx
				Invoke RSGetIndex, Eax, TRUE
				Mov Edx, Eax
				Mov Eax, [Esi].EDITCHILD.chrSel.lMin
				.If (Eax > SDWord Ptr [Esi].EDITCHILD.chrSel.lMax)
					.If (lKeyState & KEY_SHIFT)
						Mov [Esi].EDITCHILD.chrPos.lMin, Eax
					.Else
						Mov [Esi].EDITCHILD.chrPos.lMax, Edx
					.EndIf
					Mov [Esi].EDITCHILD.chrPos.lMax, Edx
				.Else
					Mov [Esi].EDITCHILD.chrPos.lMax, Edx
					.If !(lKeyState & KEY_SHIFT)
						Mov [Esi].EDITCHILD.chrPos.lMin, Edx
					.EndIf
				.EndIf
				Pop Eax
				Invoke RSSetTopLine, Eax, TRUE
			.Else
				.If !(lKeyState & KEY_SHIFT)
					Mov [Esi].EDITCHILD.chrPos.lMin, 0
				.EndIf
				Mov [Esi].EDITCHILD.chrPos.lMax, 0
			.EndIf
			Mov [Esi].EDITCHILD.lPaint, PAINT_ALL
		.EndIf
	.ElseIf wParam == VK_NEXT
		.If !(lKeyState & KEY_CTRL)
			Mov Eax, [Ebx].EDITPARENT.lLines
			.If Eax > SDWord Ptr [Esi].EDITCHILD.lVScrollPage
				Mov Ecx, [Esi].EDITCHILD.lCurLine
				Sub Ecx, [Esi].EDITCHILD.lTopLine
				Mov Eax, [Esi].EDITCHILD.lTopLine
				Add Eax, [Esi].EDITCHILD.lVScrollPage
				Dec Eax
				Cmp Eax, [Ebx].EDITPARENT.lLines
				Jle @F
				Mov Eax, [Ebx].EDITPARENT.lLines
				Sub Eax, [Esi].EDITCHILD.lVScrollPage
@@:				Push Eax
				Add Eax, Ecx
				Cmp Eax, [Ebx].EDITPARENT.lLines
				Jle @F
				Mov Eax, [Ebx].EDITPARENT.lLines
@@:				Invoke RSGetIndex, Eax, FALSE
				Mov Edx, Eax
				Mov Eax, [Esi].EDITCHILD.chrSel.lMin
				.If (Eax > SDWord Ptr [Esi].EDITCHILD.chrSel.lMax)
					.If (lKeyState & KEY_SHIFT)
						Mov [Esi].EDITCHILD.chrPos.lMin, Eax
					.Else
						Mov [Esi].EDITCHILD.chrPos.lMin, Edx
					.EndIf
					Mov [Esi].EDITCHILD.chrPos.lMax, Edx
				.Else
					Mov [Esi].EDITCHILD.chrPos.lMax, Edx
					.If !(lKeyState & KEY_SHIFT)
						Mov [Esi].EDITCHILD.chrPos.lMin, Edx
					.EndIf
				.EndIf
				Pop Eax
				Invoke RSSetTopLine, Eax, TRUE
			.Else
				Invoke RSGetLastIndex, NULL
				Mov [Esi].EDITCHILD.chrPos.lMax, Eax
				.If !(lKeyState & KEY_SHIFT)
					Mov [Esi].EDITCHILD.chrPos.lMin, Eax
				.EndIf
			.EndIf
			Mov [Esi].EDITCHILD.lPaint, PAINT_ALL
		.EndIf
	.EndIf
L5:	Mov Eax, lMin
	Mov Ecx, lMax
	.If (Eax != [Esi].EDITCHILD.chrPos.lMin || Ecx != [Esi].EDITCHILD.chrPos.lMax || SDWord Ptr [Ebx].EDITPARENT.lHScrollPos > 0)
@@:		Invoke RSSetSelection, [Esi].EDITCHILD.chrPos.lMin, [Esi].EDITCHILD.chrPos.lMax, wParam
	.Else
		Invoke RSSetPosition, [Esi].EDITCHILD.chrPos.lMin, [Esi].EDITCHILD.chrPos.lMax
		Mov Ecx, [Esi].EDITCHILD.lRealCol
		Cmp wParam, VK_DELETE
		Je L6
		Cmp wParam, VK_HOME
		Je L6
		Cmp wParam, VK_END
		Je L6
		Cmp wParam, VK_LEFT
		Je L6
		Cmp wParam, VK_RIGHT
		Je L6
		Mov Ecx, [Esi].EDITCHILD.lLastCol
L6:		Mov [Esi].EDITCHILD.lLastCol, Ecx
		Invoke RSGetLineFromChar, [Esi].EDITCHILD.chrSel.lMax
		Invoke RSIsLineInClientArea, Eax
		Or Eax, Eax
		Jz @B
	.EndIf
	.If bTextChanged
		Invoke RSSendCommandMessage, EN_CHANGE
	.EndIf
L8:	Xor Eax, Eax
	Jmp L1
RSOnKeyDown EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to active editor child's data
RSOnMarginMouseMessage Proc Private Uses Ecx Edx Edi uMsg:ULONG, wParam:WPARAM, lParam:LPARAM
	Mov [Esi].EDITCHILD.lPaint, PAINT_ALL
	HiWord lParam
	Cwde
	Cdq
	IDiv [Ebx].EDITPARENT.szFont.y
	Add Eax, [Esi].EDITCHILD.lTopLine
	Cmp Eax, 0
	Jge @F
	Xor Eax, Eax
@@:	Cmp Eax, [Ebx].EDITPARENT.lLines
	Jle @F
	Mov Eax, [Ebx].EDITPARENT.lMaxIndex
	.If uMsg == WM_LBUTTONDOWN
		Mov [Esi].EDITCHILD.chrPos.lMin, Eax
	.ElseIf uMsg == WM_MOUSEMOVE
		Mov Ecx, [Esi].EDITCHILD.lSelStart
		Mov [Esi].EDITCHILD.chrPos.lMin, Ecx
	.EndIf
	Jmp L2
@@:	Mov Edx, Eax
	Shl Edx, 4
	Add Edx, [Ebx].EDITPARENT.lpLinesPointer
	Invoke RSGetLineIndex, Eax
	.If uMsg == WM_LBUTTONDOWN
		.If (wParam & MK_CONTROL)
			Mov [Esi].EDITCHILD.lSelStart, 0
			Mov [Esi].EDITCHILD.chrPos.lMin, 0
			Mov Eax, [Ebx].EDITPARENT.lMaxIndex
			Mov [Esi].EDITCHILD.chrPos.lMax, Eax
			Invoke RSSetPosition, [Esi].EDITCHILD.chrPos.lMin, [Esi].EDITCHILD.chrPos.lMax
			Invoke RSInvalidateEditor, [Esi].EDITCHILD.hWnd, FALSE
			Ret
		.ElseIf (wParam & MK_SHIFT)
			Push Eax
			Mov Eax, [Esi].EDITCHILD.chrSel.lMin
			.If Eax == [Esi].EDITCHILD.chrSel.lMax
				Invoke RSGetLineIndex, [Esi].EDITCHILD.lCurLine
			.Else
				Invoke RSGetLineFromChar, Eax
				Invoke RSGetLineIndex, Eax
			.EndIf
			Mov [Esi].EDITCHILD.lSelStart, Eax
			Mov [Esi].EDITCHILD.chrPos.lMin, Eax
			Pop Eax
			Add Eax, [Edx].LINE.lLength
		.Else
			Mov [Esi].EDITCHILD.lSelStart, Eax
			Mov [Esi].EDITCHILD.chrPos.lMin, Eax
			Add Eax, [Edx].LINE.lLength
		.EndIf
	.ElseIf uMsg == WM_MOUSEMOVE
		.If Eax < [Esi].EDITCHILD.lSelStart
			Mov Ecx, [Esi].EDITCHILD.chrPos.lMax
			Mov [Esi].EDITCHILD.lSelStart, Ecx
			Mov [Esi].EDITCHILD.chrPos.lMin, Ecx
		.Else
			Mov Ecx, [Esi].EDITCHILD.chrPos.lMin
			Mov [Esi].EDITCHILD.lSelStart, Ecx
			Add Eax, [Edx].LINE.lLength
		.EndIf
	.EndIf
L2:	Mov [Esi].EDITCHILD.chrPos.lMax, Eax
	Invoke RSSetSelection, [Esi].EDITCHILD.chrPos.lMin, [Esi].EDITCHILD.chrPos.lMax, 0
	Ret
RSOnMarginMouseMessage EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to active editor child's data
RSOnPaint Proc Private Uses Edi hWnd
	Local lCurrentLine:LONG, lBottom:LONG, lLeft:LONG
	Local lRight:LONG, lIndex:LONG, chr:RSSCHARSEL
	Local hOldhdc:HDC, rc:RECT, ps:PAINTSTRUCT

	Invoke GetUpdateRect, hWnd, NULL, FALSE
	.If Eax
		Invoke BeginPaint, hWnd, Addr ps
		Mov hOldhdc, Eax
		Mov Eax, [Ebx].EDITPARENT.hMem
		Mov ps.hdc, Eax

		Xor Edx, Edx
		Mov Eax, ps.rcPaint.top
		Div [Ebx].EDITPARENT.szFont.y
		Mov Ecx, Eax
		Mul [Ebx].EDITPARENT.szFont.y
		Mov ps.rcPaint.top, Eax
		Add Ecx, [Esi].EDITCHILD.lTopLine

		Mov lCurrentLine, Ecx
		Invoke RSGetLineIndex, Ecx
		Mov lIndex, Eax

		Invoke SelectObject, ps.hdc, [Ebx].EDITPARENT.hFont
		Push Eax
		Invoke SetTextColor, ps.hdc, [Ebx].EDITPARENT.crTextColor
		Mov ps.rcPaint.left, 0
		Mov Eax, [Ebx].EDITPARENT.lSelBarWidth
		Mov ps.rcPaint.right, Eax
		Mov Eax, ps.rcPaint.right
		Sub Eax, [Ebx].EDITPARENT.lHScrollPos
		Mov ps.rcPaint.left, Eax
		Mov lLeft, Eax
		Add Eax, [Ebx].EDITPARENT.Editor.rc.right
		Add Eax, [Ebx].EDITPARENT.lHScrollPos
		Mov ps.rcPaint.right, Eax
		Mov lRight, Eax
		Mov Eax, ps.rcPaint.bottom
		Add Eax, [Ebx].EDITPARENT.szFont.y
		Mov lBottom, Eax
		Mov Edi, lCurrentLine
		Shl Edi, 4
		Add Edi, [Ebx].EDITPARENT.lpLinesPointer

		Invoke CopyRect, Addr rc, Addr ps.rcPaint
		Mov ps.rcPaint.top, 0
		Mov Eax, [Ebx].EDITPARENT.szFont.y
		Mov ps.rcPaint.bottom, Eax
		Mov Eax, rc.top

L2:		Add Eax, [Ebx].EDITPARENT.szFont.y
		Mov rc.bottom, Eax

		Mov ps.rcPaint.left, 0
		Mov Eax, [Ebx].EDITPARENT.lSelBarWidth
		Mov ps.rcPaint.right, Eax
		Invoke FillRect, ps.hdc, Addr ps.rcPaint, [Ebx].EDITPARENT.hMarginBrush

		Mov Eax, lCurrentLine
		Cmp Eax, [Ebx].EDITPARENT.lLines
		Jg L4

		Test [Edi].LINE.lState, STATE_BOOKMARK
		Jz L4
		Mov Edx, [Ebx].EDITPARENT.lSelBarWidth
		Sub Edx, 12
		Mov Eax, [Ebx].EDITPARENT.szFont.y
		Shr Eax, 1
		Sub Eax, 4
		Invoke DrawIcon, ps.hdc, Edx, Eax, RShBookmark

L4:		Invoke BitBlt, hOldhdc, 0, rc.top, ps.rcPaint.right, ps.rcPaint.bottom, ps.hdc, 0, 0, SRCCOPY
		Mov Eax, lLeft
		Mov ps.rcPaint.left, Eax
		Sub Eax, [Ebx].EDITPARENT.lSelBarWidth
		Mov Eax, lRight
		Mov ps.rcPaint.right, Eax

		Mov Eax, lCurrentLine
		Cmp Eax, [Ebx].EDITPARENT.lLines
		Jle L6
		Invoke FillRect, ps.hdc, Addr ps.rcPaint, [Ebx].EDITPARENT.hBackBrush
		Jmp L8

L6:		Invoke RSExpandTabsAndGetSel, Edi, lIndex, Addr chr
		Xor Edx, Edx
		Test [Edi].LINE.lState, STATE_LOCKED
		Jz @F
		Mov Edx, TRUE
@@:		Invoke RSCheckLineLength, Eax
		Invoke RSPaintText, Addr ps, Addr chr, Eax, Edx

L8:		Invoke BitBlt, hOldhdc, [Ebx].EDITPARENT.lSelBarWidth, rc.top, ps.rcPaint.right, ps.rcPaint.bottom, ps.hdc, [Ebx].EDITPARENT.lSelBarWidth, 0, SRCCOPY

		Mov Eax, lCurrentLine
		Cmp Eax, [Ebx].EDITPARENT.lLines
		Jge @F
		Mov Eax, [Edi].LINE.lLength
		Add lIndex, Eax
		Add Edi, SizeOf LINE
@@:		Inc lCurrentLine
		Mov Eax, rc.top
		Add Eax, [Ebx].EDITPARENT.szFont.y
		Mov rc.top, Eax
		Cmp Eax, lBottom
		Jle L2

		Pop Eax
		Invoke SelectObject, ps.hdc, Eax

		Mov Eax, hOldhdc
		Mov ps.hdc, Eax
		Invoke EndPaint, hWnd, Addr ps
		;Invoke RSFreeLineMemory
	.EndIf
	Ret
RSOnPaint EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to active editor child's data
RSOnTimer Proc Private hWnd:HWND, uID:ULONG, wParam:WPARAM
	Local pt:POINTL

	Invoke RSSetScrollCounter, hWnd, Addr pt
	Mov [Ebx].EDITPARENT.lVScrollCounter, Eax
	Invoke GetCapture
	.If Eax == hWnd && SDWord Ptr [Ebx].EDITPARENT.lVScrollCounter > 0
		Mov Eax, pt.y
		Mov Ecx, Eax
		And Ecx, 80000000H
		Shl Eax, 16
		Or Eax, Ecx
		Mov Ecx, pt.x
		Mov Edx, Ecx
		Shr Edx, 16
		And Dx, 8000H
		And Ecx, 0000FFFFH
		Or Cx, Dx
		Or Ax, Cx
		.If RSbMargin
			Invoke RSOnMarginMouseMessage, WM_MOUSEMOVE, wParam, Eax
		.Else
			Invoke RSOnEditorMouseMessage, WM_MOUSEMOVE, wParam, Eax
		.EndIf
	.Else
		Invoke RSKillScrollTimer
	.EndIf
	Ret
RSOnTimer EndP

;On enter Ebx = Pointer to editor parent's data
RSPaintLine Proc Private Uses Edi lpPs:DWord, lpszText:LPSTR, lLength:LONG, bLocked:BOOL
	Local lPos:LONG, sz:SIZEL

	Mov Edi, lpPs
	.If bLocked
		Invoke FillRect, [Edi].PAINTSTRUCT.hdc, Addr [Edi].PAINTSTRUCT.rcPaint, [Ebx].EDITPARENT.hLockedBrush
		Mov Eax, [Ebx].EDITPARENT.crTextLocked
	.Else
		Invoke FillRect, [Edi].PAINTSTRUCT.hdc, Addr [Edi].PAINTSTRUCT.rcPaint, [Ebx].EDITPARENT.hBackBrush
		Mov Eax, [Ebx].EDITPARENT.crTextColor
	.EndIf
	Invoke SetTextColor, [Edi].PAINTSTRUCT.hdc, Eax
	.If (SDWord Ptr lLength < 512) ;4096
		Invoke RSTextOut, [Edi].PAINTSTRUCT.hdc, [Edi].PAINTSTRUCT.rcPaint.left, [Edi].PAINTSTRUCT.rcPaint.top, lpszText, lLength
	.Else
		Push Esi
		Mov Esi, lpszText
		Mov lPos, 0
		Mov Edx, lPos
		.While (Edx < SDWord Ptr lLength)
			Mov Eax, 511 ;4095
			.If lPos
				Mov Ecx, Eax
				.If [Ebx].EDITPARENT.bTextUnicode
					Shl Ecx, 1
				.EndIf
				Add Esi, Ecx
			.EndIf
			Add Edx, Eax
			.If (Edx > SDWord Ptr lLength)
				Mov Eax, lLength
				Sub Eax, lPos
			.EndIf
			Push Eax
			Invoke RSTextOut, [Edi].PAINTSTRUCT.hdc, [Edi].PAINTSTRUCT.rcPaint.left, [Edi].PAINTSTRUCT.rcPaint.top, Esi, Eax
			Pop Edx
			Add lPos, Edx
			Invoke RSGetTextExtentPoint32, [Edi].PAINTSTRUCT.hdc, Esi, Edx, Addr sz
			Mov Eax, sz.x
			Add [Edi].PAINTSTRUCT.rcPaint.left, Eax
			Mov Eax, [Edi].PAINTSTRUCT.rcPaint.left
			Mov Edx, lPos
		.EndW
		Pop Esi
	.EndIf
	Invoke SetTextColor, [Edi].PAINTSTRUCT.hdc, [Ebx].EDITPARENT.crTextColor
	Ret
RSPaintLine EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to editor child's data
RSPaintText Proc Private Uses Edi Esi lpPs:DWord, lpChr:DWord, lLength:BOOL, bLocked:BOOL
	Local lPos:LONG, sz:SIZEL, sz1:SIZEL

	Mov Ecx, lLength
	Mov Edx, [Ebx].EDITPARENT.lpszLine
	Cmp [Esi].EDITCHILD.bNoSelection, FALSE
	Je @F
L2:	Invoke RSPaintLine, lpPs, Edx, Ecx, bLocked
	Ret
@@:	Mov Edi, lpChr
	Mov Eax, [Edi].RSSCHARSEL.lMin
	Cmp Eax, [Edi].RSSCHARSEL.lMax
	Je L2

	Mov Esi, lpPs
	Push [Esi].PAINTSTRUCT.rcPaint.right
	Cmp [Edi].RSSCHARSEL.lMin, 0
	Jg L4
	Mov Eax, lLength
	Cmp [Edi].RSSCHARSEL.lMax, Eax
	Jl @F
	Invoke FillRect, [Esi].PAINTSTRUCT.hdc, Addr [Esi].PAINTSTRUCT.rcPaint, [Ebx].EDITPARENT.hSelectBrush
	Invoke SetTextColor, [Esi].PAINTSTRUCT.hdc, [Ebx].EDITPARENT.crTextSelect
	.If (SDWord Ptr lLength < 512) ;4096
		Invoke RSTextOut, [Esi].PAINTSTRUCT.hdc, [Esi].PAINTSTRUCT.rcPaint.left, [Esi].PAINTSTRUCT.rcPaint.top, [Ebx].EDITPARENT.lpszLine, lLength
	.Else
		Mov Eax, lLength
		Call PaintLongSelLine
	.EndIf
	Invoke RSGetTextExtentPoint32, [Esi].PAINTSTRUCT.hdc, [Ebx].EDITPARENT.lpszLine, lLength, Addr sz
	Mov Eax, sz.x
	Add [Esi].PAINTSTRUCT.rcPaint.left, Eax
	.If bLocked
		Mov Eax, [Ebx].EDITPARENT.hLockedBrush
	.Else
		Mov Eax, [Ebx].EDITPARENT.hBackBrush
	.EndIf
	Invoke FillRect, [Esi].PAINTSTRUCT.hdc, Addr [Esi].PAINTSTRUCT.rcPaint, Eax
	Invoke SetTextColor, [Esi].PAINTSTRUCT.hdc, [Ebx].EDITPARENT.crTextColor
	Pop Eax
	Ret
@@:	Invoke RSGetTextExtentPoint32, [Esi].PAINTSTRUCT.hdc, [Ebx].EDITPARENT.lpszLine, [Edi].RSSCHARSEL.lMax, Addr sz
	Mov Eax, [Esi].PAINTSTRUCT.rcPaint.left
	Add Eax, sz.x
	Mov [Esi].PAINTSTRUCT.rcPaint.right, Eax
	Invoke FillRect, [Esi].PAINTSTRUCT.hdc, Addr [Esi].PAINTSTRUCT.rcPaint, [Ebx].EDITPARENT.hSelectBrush
	Invoke SetTextColor, [Esi].PAINTSTRUCT.hdc, [Ebx].EDITPARENT.crTextSelect
	.If (SDWord Ptr lLength < 512) ;4096
		Invoke RSTextOut, [Esi].PAINTSTRUCT.hdc, [Esi].PAINTSTRUCT.rcPaint.left, [Esi].PAINTSTRUCT.rcPaint.top, [Ebx].EDITPARENT.lpszLine, [Edi].RSSCHARSEL.lMax
	.Else
		Mov Eax, [Edi].RSSCHARSEL.lMax
		Call PaintLongSelLine
	.EndIf

	Mov Eax, [Esi].PAINTSTRUCT.rcPaint.right
	Mov [Esi].PAINTSTRUCT.rcPaint.left, Eax
	Pop [Esi].PAINTSTRUCT.rcPaint.right
	Mov Eax, lLength
	Sub Eax, [Edi].RSSCHARSEL.lMax
	Mov Ecx, Eax
	Mov Edx, [Ebx].EDITPARENT.lpszLine
	Invoke RSGetBytes, [Edi].RSSCHARSEL.lMax
	Add Edx, Eax
	Jmp L2
L4:	Invoke RSGetTextExtentPoint32, [Esi].PAINTSTRUCT.hdc, [Ebx].EDITPARENT.lpszLine, [Edi].RSSCHARSEL.lMin, Addr sz
	Mov Eax, sz.x
	Add Eax, [Esi].PAINTSTRUCT.rcPaint.left
	Mov [Esi].PAINTSTRUCT.rcPaint.right, Eax
	.If bLocked
		Invoke SetTextColor, [Esi].PAINTSTRUCT.hdc, [Ebx].EDITPARENT.crTextLocked
		Mov Eax, [Ebx].EDITPARENT.hLockedBrush
	.Else
		Mov Eax, [Ebx].EDITPARENT.hBackBrush
	.EndIf
	Invoke FillRect, [Esi].PAINTSTRUCT.hdc, Addr [Esi].PAINTSTRUCT.rcPaint, Eax
	.If (SDWord Ptr lLength < 512) ;4096
		Invoke RSTextOut, [Esi].PAINTSTRUCT.hdc, [Esi].PAINTSTRUCT.rcPaint.left, [Esi].PAINTSTRUCT.rcPaint.top, [Ebx].EDITPARENT.lpszLine, [Edi].RSSCHARSEL.lMin
	.Else
		Mov Eax, [Edi].RSSCHARSEL.lMin
		Call PaintLongSelLine
	.EndIf
	Mov Eax, [Esi].PAINTSTRUCT.rcPaint.right
	Mov [Esi].PAINTSTRUCT.rcPaint.left, Eax
	Mov Ecx, [Edi].RSSCHARSEL.lMax
	Mov Eax, [Edi].RSSCHARSEL.lMin
	Sub Ecx, Eax
	Invoke RSGetBytes, Eax
	Mov Edx, [Ebx].EDITPARENT.lpszLine
	Add Edx, Eax
	Push Ecx
	Push Edx
	Invoke RSGetTextExtentPoint32, [Esi].PAINTSTRUCT.hdc, Edx, Ecx, Addr sz
	Mov Eax, sz.x
	Add Eax, [Esi].PAINTSTRUCT.rcPaint.left
	Mov [Esi].PAINTSTRUCT.rcPaint.right, Eax
	Invoke FillRect, [Esi].PAINTSTRUCT.hdc, Addr [Esi].PAINTSTRUCT.rcPaint, [Ebx].EDITPARENT.hSelectBrush
	Invoke SetTextColor, [Esi].PAINTSTRUCT.hdc, [Ebx].EDITPARENT.crTextSelect
	Pop Edx
	Pop Ecx
	.If (SDWord Ptr lLength < 512) ;4096
		Invoke RSTextOut, [Esi].PAINTSTRUCT.hdc, [Esi].PAINTSTRUCT.rcPaint.left, [Esi].PAINTSTRUCT.rcPaint.top, Edx, Ecx
	.Else
		Push [Ebx].EDITPARENT.lpszLine
		Mov [Ebx].EDITPARENT.lpszLine, Edx
		Mov Eax, Ecx
		Call PaintLongSelLine
		Pop [Ebx].EDITPARENT.lpszLine
	.EndIf
	Mov Eax, [Esi].PAINTSTRUCT.rcPaint.right
	Mov [Esi].PAINTSTRUCT.rcPaint.left, Eax
	Pop [Esi].PAINTSTRUCT.rcPaint.right
	Mov Ecx, lLength
	Mov Eax, [Edi].RSSCHARSEL.lMax
	Sub Ecx, Eax
	Invoke RSGetBytes, Eax
	Mov Edx, [Ebx].EDITPARENT.lpszLine
	Add Edx, Eax
	Jmp L2

PaintLongSelLine:
	Push lLength
	Mov lLength, Eax
	Push [Esi].PAINTSTRUCT.rcPaint.left
	Push Edi
	Mov Edi, [Ebx].EDITPARENT.lpszLine
	Mov lPos, 0
	Mov Edx, lPos
	.While (Edx < SDWord Ptr lLength)
		Mov Eax, 511 ;4095
		.If lPos
			Mov Ecx, Eax
			.If [Ebx].EDITPARENT.bTextUnicode
				Shl Ecx, 1
			.EndIf
			Add Edi, Ecx
		.EndIf
		Add Edx, Eax
		.If (Edx > SDWord Ptr lLength)
			Mov Eax, lLength
			Sub Eax, lPos
		.EndIf
		Push Eax
		Invoke RSTextOut, [Esi].PAINTSTRUCT.hdc, [Esi].PAINTSTRUCT.rcPaint.left, [Esi].PAINTSTRUCT.rcPaint.top, Edi, Eax
		Pop Edx
		Add lPos, Edx
		Invoke RSGetTextExtentPoint32, [Esi].PAINTSTRUCT.hdc, Edi, Edx, Addr sz1
		Mov Eax, sz1.x
		Add [Esi].PAINTSTRUCT.rcPaint.left, Eax
		Mov Eax, [Esi].PAINTSTRUCT.rcPaint.left
		Mov Edx, lPos
	.EndW
	Pop Edi
	Pop [Esi].PAINTSTRUCT.rcPaint.left
	Invoke RSGetTextExtentPoint32, [Esi].PAINTSTRUCT.hdc, [Ebx].EDITPARENT.lpszLine, lLength, Addr sz1
	Pop lLength
	Retn
RSPaintText EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to editor child's data
RSPasteText Proc Private Uses Edi hWnd:HWND, uFormat:UINT
	Local lpszTemp:LPSTR

	Invoke OpenClipboard, hWnd
	.If Eax
		Invoke GetClipboardData, uFormat
		.If (Eax != NULL)
			Mov Edi, Eax
			Invoke CloseClipboard
			Push Edi
			Invoke GlobalLock, Edi
			Mov Edi, Eax
			Invoke RSGetTextLength, Eax
			Add Eax, 2
			Push Eax
			Invoke RSGetBytes, Eax
			Invoke VirtualAlloc, 0, Eax, MEM_COMMIT, PAGE_READWRITE
			Mov lpszTemp, Eax
			Pop Eax
			.If ([Ebx].EDITPARENT.bTextUnicode && uFormat == CF_TEXT)
				Invoke MultiByteToWideChar, CP_ACP, 0, Edi, (-1), lpszTemp, Eax
			.EndIf
			Invoke RSClipboardToText, lpszTemp, Edi
			Pop Edi
			Invoke GlobalUnlock, Edi
			Push [Ebx].EDITPARENT.bInsert
			Mov [Ebx].EDITPARENT.bInsert, TRUE
			Invoke RSReplaceSelection, lpszTemp, 0
			Pop [Ebx].EDITPARENT.bInsert
			Push Eax
			Mov [Esi].EDITCHILD.lPaint, PAINT_ALL
			Invoke VirtualFree, lpszTemp, 0, MEM_RELEASE
			Pop Eax
		.EndIf
		.If Eax
			Invoke RSSetSelection, [Esi].EDITCHILD.chrPos.lMin, [Esi].EDITCHILD.chrPos.lMin, 0
			Invoke RSSendCommandMessage, EN_CHANGE
			Mov Eax, TRUE
		.EndIf
	.EndIf
	Ret
RSPasteText EndP

;On enter Esi = Pointer to editor child's data
RSPrevBookmark Proc Private
	Invoke RSGetPreviousBookmark
	.If Eax != (-1)
		Invoke RSGetLineIndex, Eax
		Invoke RSSetSelection, Eax, Eax, 0
		Mov Eax, TRUE
	.EndIf
	Ret
RSPrevBookmark EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to editor child's data
RSRedo Proc Private Uses Ecx Edx Edi
	Local lLength1:LONG, lLength2:LONG, bNoText:BOOL

	Xor Eax, Eax
	Mov Edx, [Ebx].EDITPARENT.lUndoCount
	Shl Edx, 4
	Add Edx, [Ebx].EDITPARENT.lpUndoPointer
	.If DWord Ptr [Edx]
		Push [Ebx].EDITPARENT.dwEventMask
		Mov [Ebx].EDITPARENT.dwEventMask, 0
		Mov Edi, DWord Ptr [Edx]
		Invoke RSGetTextLength, Edi
		Mov lLength1, Eax
		Inc Eax
		Invoke RSGetBytes, Eax
		Add Edi, Eax
		Invoke RSGetTextLength, Edi
		Mov lLength2, Eax
		Mov Eax, [Edx].EDITUNDO.chrPos.lMin
		.If Eax <= SDWord Ptr [Edx].EDITUNDO.chrPos.lMax
			Mov [Esi].EDITCHILD.chrPos.lMin, Eax
			Mov Eax, [Edx].EDITUNDO.chrPos.lMax
			Mov [Esi].EDITCHILD.chrPos.lMax, Eax
		.Else
			Mov [Esi].EDITCHILD.chrPos.lMax, Eax
			Mov Eax, [Edx].EDITUNDO.chrPos.lMax
			Mov [Esi].EDITCHILD.chrPos.lMin, Eax
		.EndIf
		Invoke RSCanDelete
		.If (!Eax)
			Mov Eax, [Esi].EDITCHILD.chrSel.lMin
			Mov Ecx, [Esi].EDITCHILD.chrSel.lMax
			Cmp Ecx, Eax
			Jge @F
			Xchg Eax, Ecx
@@:			Mov [Esi].EDITCHILD.chrPos.lMin, Eax
			Mov [Esi].EDITCHILD.chrPos.lMax, Ecx
			Pop [Ebx].EDITPARENT.dwEventMask
			Xor Eax, Eax
			Ret
		.EndIf
		Invoke RSReplaceSelection, Edi, (-1)
		.If (!Eax)
			Pop [Ebx].EDITPARENT.dwEventMask
			Ret
		.EndIf

		Mov bNoText, TRUE
		.If [Ebx].EDITPARENT.bTextUnicode
			.While (Word Ptr [Edi])
				.If (Word Ptr [Edi] > 32)
					Mov bNoText, FALSE
					.Break
				.EndIf
				Add Edi, 2
			.EndW
		.Else
			.While (Byte Ptr [Edi])
				.If (Byte Ptr [Edi] > 32)
					Mov bNoText, FALSE
					.Break
				.EndIf
				Inc Edi
			.EndW
		.EndIf
		Mov [Esi].EDITCHILD.lPaint, PAINT_ALL
		Mov Eax, [Edx].EDITUNDO.chrPos.lMin
		.If Eax > SDWord Ptr [Edx].EDITUNDO.chrPos.lMax
			Mov Eax, [Edx].EDITUNDO.chrPos.lMax
		.EndIf
		Mov Edi, Eax
		Add Eax, lLength2
		.If (lLength2 == 1 || bNoText)
			Mov Edi, Eax
		.EndIf
		Mov Ecx, Eax
		Inc [Ebx].EDITPARENT.lUndoCount
		Invoke RSGetLineFromChar, [Edx].EDITUNDO.chrPos.lMin
		Invoke RSIsLineInClientArea, Eax
		.If (!Eax)
			Invoke RSSetTopLine, [Edx].EDITUNDO.lTopLine, FALSE
			Mov [Esi].EDITCHILD.lPaint, PAINT_ALL
		.EndIf
		Invoke RSCheckModified
		Pop [Ebx].EDITPARENT.dwEventMask
		Mov Eax, [Edx].EDITUNDO.chrPos.lMin
		.If Eax == [Edx].EDITUNDO.chrPos.lMax && SDWord Ptr lLength2 <= 2
			Mov Edi, Ecx
		.EndIf
		Invoke RSSetSelection, Edi, Ecx, 0
		Invoke RSCheckHorizontalPos
		Invoke RSSendCommandMessage, EN_CHANGE
		Mov Eax, TRUE
	.EndIf
	Ret
RSRedo EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to editor child's data
RSRedrawEditor Proc Private Uses Ecx Edx hWnd:HWND, bNow:BOOL
	Local rc:RECT

	.If (hWnd != NULL && [Ebx].EDITPARENT.bRedraw)
		Invoke CopyRect, Addr rc, Addr [Esi].EDITCHILD.rc
		.If [Esi].EDITCHILD.lPaint != PAINT_NONE
			.If [Esi].EDITCHILD.lPaint == PAINT_LINE
				Mov Eax, [Esi].EDITCHILD.lCurLine
				Sub Eax, [Esi].EDITCHILD.lTopLine
				Mul [Ebx].EDITPARENT.szFont.y
				Mov rc.top, Eax
				Add Eax, [Ebx].EDITPARENT.szFont.y
				Mov rc.bottom, Eax
			.ElseIf [Esi].EDITCHILD.lPaint == PAINT_FROM_LINE || [Esi].EDITCHILD.lPaint == PAINT_FROM_PREV_LINE
				Mov Eax, [Esi].EDITCHILD.lCurLine
				Sub Eax, [Esi].EDITCHILD.lTopLine
				.If [Esi].EDITCHILD.lPaint != PAINT_FROM_LINE
					Dec Eax
				.EndIf
				Cmp Eax, 0
				Jge @F
				Xor Eax, Eax
@@:				Mul [Ebx].EDITPARENT.szFont.y
				Mov rc.top, Eax
			.EndIf
			Invoke InvalidateRect, hWnd, Addr rc, FALSE
			.If bNow
				Invoke SendMessage, hWnd, WM_PAINT, 0, 0
			.EndIf
		.EndIf
		Mov Eax, hWnd
		.If Eax == [Ebx].EDITPARENT.hWndFocus
			Invoke RSSetCaret
		.EndIf
	.EndIf
	Ret
RSRedrawEditor EndP

;On enter Ebx = Pointer to editor parent's data
RSReleaseEditorMemory Proc Private Uses Ecx Edx
	.If [Ebx].EDITPARENT.lpTextPointer != NULL
		Invoke VirtualFree, [Ebx].EDITPARENT.lpTextPointer, 0, MEM_RELEASE
		Mov [Ebx].EDITPARENT.lpTextPointer, NULL
	.EndIf
	Mov [Ebx].EDITPARENT.lpszNextText, NULL
	Mov [Ebx].EDITPARENT.lMaxTextLength, 0
	Mov [Ebx].EDITPARENT.lHScrollMax, 0
	.If [Ebx].EDITPARENT.lpLinesPointer != NULL
		Invoke VirtualFree, [Ebx].EDITPARENT.lpLinesPointer, 0, MEM_RELEASE
		Mov [Ebx].EDITPARENT.lpLinesPointer, NULL
	.EndIf
	Mov [Ebx].EDITPARENT.lMaxLines, 0
	.If [Ebx].EDITPARENT.lpUndoPointer != NULL
		Invoke RSClearUndoEntryFrom, 0
		Invoke VirtualFree, [Ebx].EDITPARENT.lpUndoPointer, 0, MEM_RELEASE
		Mov [Ebx].EDITPARENT.lpUndoPointer, NULL
	.EndIf
	Mov [Ebx].EDITPARENT.lMaxUndo, 0
	Mov [Ebx].EDITPARENT.lUndoCount, 0
	Mov [Ebx].EDITPARENT.lLastUndoCount, 0
	.If [Ebx].EDITPARENT.hHeap != NULL
		Invoke HeapDestroy, [Ebx].EDITPARENT.hHeap
		Mov [Ebx].EDITPARENT.hHeap, NULL
	.EndIf
	Ret
RSReleaseEditorMemory EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to editor child's data
RSReplaceSelection Proc Private Uses Ecx Edx Edi lpszBuf:LPSTR, lKey:LONG
	Local lLength:LONG, ChrInfMin:RSSCHARINFO
	Local lLines:LONG, ChrInfMax:RSSCHARINFO

	Cmp [Ebx].EDITPARENT.bReadOnly, FALSE
	Je @F
L2:	Xor Eax, Eax
	Ret
@@:	Invoke RSGetCharInfo, [Esi].EDITCHILD.chrPos.lMin, Addr ChrInfMin
	Invoke RSGetCharInfo, [Esi].EDITCHILD.chrPos.lMax, Addr ChrInfMax
	Invoke RSIsBlockEditable, ChrInfMin.lLine, ChrInfMax.lLine
	Or Eax, Eax
	Jz L2
	Mov Eax, lpszBuf
	Or Eax, Eax
	Jz @F
	Invoke RSGetTextLength, Eax
@@:	Mov lLength, Eax
	Mov Edx, lpszBuf

	Invoke RSGetLines, Edx
	Mov lLines, Eax

	Push [Ebx].EDITPARENT.bInsert
	Mov Eax, [Esi].EDITCHILD.chrPos.lMin
	.If Eax != [Esi].EDITCHILD.chrPos.lMax
		Mov [Ebx].EDITPARENT.bInsert, TRUE
	.EndIf
	;Push [Esi].EDITCHILD.chrPos.lMax
	Cmp lKey, (-1)
	Je @F
	.If (![Ebx].EDITPARENT.bInsert)
		.If lLength == 1
			Mov Edx, ChrInfMin.lLine
			Shl Edx, 4
			Add Edx, [Ebx].EDITPARENT.lpLinesPointer
			Mov Eax, [Edx].LINE.lpszText
			Add Eax, ChrInfMin.lLineOffset
			Mov Ax, Word Ptr [Eax]
			.If (![Ebx].EDITPARENT.bTextUnicode)
				Xor Ah, Ah
			.EndIf
			.If (Ax != VK_RETURN)
				Mov Eax, ChrInfMin.lLineOffset
				.If Eax < SDWord Ptr [Edx].LINE.lLength
					Inc [Esi].EDITCHILD.chrPos.lMax
				.EndIf
			.EndIf
		.EndIf
	.EndIf
	Invoke RSSaveUndo, lpszBuf, lLength
@@:	Mov Eax, [Esi].EDITCHILD.chrPos.lMax
	;Pop [Esi].EDITCHILD.chrPos.lMax
	Cmp Eax, [Esi].EDITCHILD.chrPos.lMin
	Je @F
	;Mov [Esi].EDITCHILD.chrPos.lMax, Eax
	.If [Ebx].EDITPARENT.Mirror.hWnd
		.If lLength
			Xor Edi, Edi
		.Else
			Mov Edi, TRUE
		.EndIf
		Push [Esi].EDITCHILD.chrPos.lMin
		Push [Esi].EDITCHILD.chrPos.lMax
	.EndIf
	Invoke RSDeleteSelection, Addr ChrInfMin, Addr ChrInfMax
	Invoke RSIsLineInClientArea, ChrInfMin.lLine
	.If (!Eax)
		Mov Eax, ChrInfMin.lLine
		Mov Ecx, [Esi].EDITCHILD.lVScrollPage
		Shr Ecx, 1
		Sub Eax, Ecx
		.If Sign?
			Mov Eax, [Esi].EDITCHILD.lTopLine
		.EndIf
		Sub Eax, [Esi].EDITCHILD.lTopLine
		Invoke RSSetTopLine, Eax, FALSE
	.EndIf
	.If [Ebx].EDITPARENT.Mirror.hWnd
		Pop Edx
		Pop Eax
		Invoke RSAdjustMirrorDelete, ChrInfMin.lLine, ChrInfMax.lLine, Eax, Edx, Edi
	.EndIf
	Mov [Ebx].EDITPARENT.bChangeEvent, TRUE
	Mov [Ebx].EDITPARENT.bModified, TRUE
@@:	.If lLength
		.If [Ebx].EDITPARENT.Mirror.hWnd
			Push [Esi].EDITCHILD.chrPos.lMin
			Push [Ebx].EDITPARENT.lMaxIndex
			Push [Ebx].EDITPARENT.lLines
		.EndIf
		Mov [Ebx].EDITPARENT.bInsert, TRUE
		Invoke RSInsertText, lpszBuf, lLength, lLines
		.If [Ebx].EDITPARENT.Mirror.hWnd
			Mov Ecx, [Ebx].EDITPARENT.lLines
			Pop Eax
			Sub Ecx, Eax
			Mov Edx, [Ebx].EDITPARENT.lMaxIndex
			Pop Eax
			Sub Edx, Eax
			Pop Eax
			Invoke RSAdjustMirrorInsert, ChrInfMin.lLine, Eax, Edx, Ecx
		.EndIf
		Mov [Ebx].EDITPARENT.bChangeEvent, TRUE
		Mov [Ebx].EDITPARENT.bModified, TRUE
	.EndIf
	Pop [Ebx].EDITPARENT.bInsert
	Mov Eax, [Ebx].EDITPARENT.bChangeEvent
	Ret
RSReplaceSelection EndP

;On enter Ebx = Pointer to editor parent's data
RSResizeBuffer Proc Private Uses Ecx Edx Edi Esi ecType:LONG, lSize:LONG
	Push [Ebx].EDITPARENT.dwEventMask
	Mov [Ebx].EDITPARENT.dwEventMask, 0
	Test ecType, RSC_TEXT
	Jz L6
	Xor Edx, Edx
	Mov Eax, [Ebx].EDITPARENT.lMaxTextLength
	Add Eax, 4
	Cmp lSize, (-1)
	Je @F
	Invoke RSGetBytes, Eax
	Add Eax, lSize
	Div RSdwPageSize
	Inc Eax
	Mul RSdwPageSize
	Invoke RSGetChars, Eax
@@:	Mov [Ebx].EDITPARENT.lMaxTextLength, Eax
	Invoke RSGetBytes, Eax
	Invoke VirtualAlloc, 0, Eax, MEM_COMMIT, PAGE_READWRITE
	Or Eax, Eax
	Jnz @F
L2:	Pop [Ebx].EDITPARENT.dwEventMask
	Mov Eax, (-1)
	Ret
@@:	Mov Esi, Eax
	Sub [Ebx].EDITPARENT.lMaxTextLength, 4
	Push Esi
	Mov Edi, [Ebx].EDITPARENT.lLines
	Mov Edx, [Ebx].EDITPARENT.lpLinesPointer
@@:	Mov Ecx, [Edx].LINE.lLength
	Mov [Edx].LINE.lMaxLength, Ecx
	Invoke RSMoveChars, Esi, [Edx].LINE.lpszText, Ecx
	Mov [Edx].LINE.lpszText, Esi
	Add Edx, SizeOf LINE
	Invoke RSGetBytes, Ecx
	Add Esi, Eax
	Dec Edi
	Jge @B
	Mov [Ebx].EDITPARENT.lpszNextText, Esi
	Invoke VirtualFree, [Ebx].EDITPARENT.lpTextPointer, 0, MEM_RELEASE
	Pop Esi
	Mov [Ebx].EDITPARENT.lpTextPointer, Esi
L4:	Pop [Ebx].EDITPARENT.dwEventMask
	Mov Eax, TRUE
	Ret
L6:	Test ecType, RSC_LINES
	Jz @F
	Mov Eax, [Ebx].EDITPARENT.lMaxLines
	Inc Eax
	Mov Ecx, Eax
	Shr Ecx, 1
	Add Eax, Ecx
	.If lSize != 1
		Add Eax, lSize
	.EndIf
	Mov Edi, Eax
	Shl Eax, 4
	Invoke VirtualAlloc, 0, Eax, MEM_COMMIT, PAGE_READWRITE
	Or Eax, Eax
	Jz L2
	Mov Esi, Eax
	Dec Edi
	Mov Eax, [Ebx].EDITPARENT.lMaxLines
	Shl Eax, 4
	Invoke RtlMoveMemory, Esi, [Ebx].EDITPARENT.lpLinesPointer, Eax
	Invoke VirtualFree, [Ebx].EDITPARENT.lpLinesPointer, 0, MEM_RELEASE
	Mov [Ebx].EDITPARENT.lpLinesPointer, Esi
	Mov [Ebx].EDITPARENT.lMaxLines, Edi
	Jmp L4
@@:	Test ecType, RSC_UNDO
	Jz L4
	Mov Eax, [Ebx].EDITPARENT.lMaxUndo
	Add Eax, lSize
	Mov Edi, Eax ;[Ebx].EDITPARENT.lMaxUndo
	Shl Eax, 4
	Invoke VirtualAlloc, 0, Eax, MEM_COMMIT, PAGE_READWRITE
	Or Eax, Eax
	Jz L2
	Mov Esi, Eax
	Mov Eax, [Ebx].EDITPARENT.lMaxUndo
	Shl Eax, 4
	Invoke RtlMoveMemory, Esi, [Ebx].EDITPARENT.lpUndoPointer, Eax
	Invoke VirtualFree, [Ebx].EDITPARENT.lpUndoPointer, 0, MEM_RELEASE
	Mov [Ebx].EDITPARENT.lpUndoPointer, Esi
	Mov [Ebx].EDITPARENT.lMaxUndo, Edi
	Jmp L4
RSResizeBuffer EndP

;On enter Ebx = Pointer to editor parent's data
RSResizeChilds Proc Private Uses Edi Esi bRepaint:BOOL
	Local rc:RECT

	.If [Ebx].EDITPARENT.Mirror.hWnd == NULL
		Mov Edx, [Ebx].EDITPARENT.rc.bottom
		Sub Edx, RSlHScrollHeight
		Invoke MoveWindow, [Ebx].EDITPARENT.Editor.hWnd, 0, 0, [Ebx].EDITPARENT.rc.right, Edx, TRUE
	.Else
		Invoke RSGetChildWindowPos, [Ebx].EDITPARENT.hWndSplitter, Addr rc
		Invoke MoveWindow, [Ebx].EDITPARENT.Editor.hWnd, 0, 0, [Ebx].EDITPARENT.rc.right, rc.top, TRUE
		Mov Eax, [Ebx].EDITPARENT.rc.bottom
		Sub Eax, rc.bottom
		Sub Eax, RSlHScrollHeight
		Invoke MoveWindow, [Ebx].EDITPARENT.Mirror.hWnd, 0, rc.bottom, [Ebx].EDITPARENT.rc.right, Eax, TRUE
	.EndIf
	Invoke GetDC, [Ebx].EDITPARENT.Editor.hWnd
	Mov Edi, Eax
	Invoke CreateCompatibleBitmap, Edi, [Ebx].EDITPARENT.Editor.rc.right, [Ebx].EDITPARENT.szFont.y
	Mov [Ebx].EDITPARENT.hBitmap, Eax
	Invoke SelectObject, [Ebx].EDITPARENT.hMem, Eax
	.If Eax
		Invoke DeleteObject, Eax
	.EndIf
	Invoke SetBkMode, [Ebx].EDITPARENT.hMem, TRANSPARENT
	Invoke ReleaseDC, [Ebx].EDITPARENT.Editor.hWnd, Edi
	.If bRepaint
		Invoke RedrawWindow, [Ebx].EDITPARENT.Editor.hWnd, NULL, NULL, (RDW_INVALIDATE Or RDW_UPDATENOW Or RDW_ALLCHILDREN)
		.If [Ebx].EDITPARENT.Mirror.hWnd != NULL
			Invoke RedrawWindow, [Ebx].EDITPARENT.Mirror.hWnd, NULL, NULL, (RDW_INVALIDATE Or RDW_UPDATENOW Or RDW_ALLCHILDREN)
		.EndIf
	.EndIf
	Ret
RSResizeChilds EndP

;On enter Ebx = Pointer to editor parent's data
RSResizeLine Proc Private Uses Ecx Edx Edi lLine:LONG, lChars:LONG
	Mov Edx, lLine
	Shl Edx, 4
	Add Edx, [Ebx].EDITPARENT.lpLinesPointer
	Mov Ecx, [Edx].LINE.lMaxLength ;lLength
	Add Ecx, lChars
	Invoke RSGetBytes, Ecx
	Invoke RSCheckBufferSize, Eax, RSC_TEXT
	Mov Edi, [Ebx].EDITPARENT.lpszNextText
	Invoke RSMoveChars, Edi, [Edx].LINE.lpszText, [Edx].LINE.lLength
	Mov [Edx].LINE.lpszText, Edi
	Mov [Edx].LINE.lMaxLength, Ecx
	Invoke RSGetBytes, Ecx
	Add [Ebx].EDITPARENT.lpszNextText, Eax
	Ret
RSResizeLine EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to editor child's data
RSSaveUndo Proc Private Uses Ecx Edx Edi lpszBuf:LPSTR, lLength:LONG
	Local bAlphaNumeric:BOOL, lLength1:LONG
	Local lOffset:LONG, lpsz:LPSTR

	.If [Ebx].EDITPARENT.lpUndoPointer
		Mov Edx, [Esi].EDITCHILD.chrPos.lMin
		Cmp [Ebx].EDITPARENT.bTextUnicode, FALSE
		Jne SaveUndoW
		Cmp Edx, [Esi].EDITCHILD.chrPos.lMax
		Jne A2
		Cmp lLength, 1
		Jne A2
		Mov Edx, lpszBuf
		Or Edx, Edx
		Jz A2
		Cmp Byte Ptr [Edx], VK_TAB
		Je @F
		Cmp Byte Ptr [Edx], ' '
		Jl A2
@@:		Movzx Eax, Byte Ptr [Edx]
		Invoke RSIsCharAlphaNumeric, Eax
		Mov bAlphaNumeric, Eax
		.If (SDWord Ptr [Ebx].EDITPARENT.lUndoCount > 0)
			Mov Edi, [Ebx].EDITPARENT.lUndoCount
			Dec Edi
			Shl Edi, 4
			Add Edi, [Ebx].EDITPARENT.lpUndoPointer
			Cmp [Edi].EDITUNDO.lpszText, NULL
			Je A2
			Invoke RSGetTextLength, [Edi].EDITUNDO.lpszText
			Inc Eax
			Invoke RSGetBytes, Eax
			Add Eax, [Edi].EDITUNDO.lpszText
			Invoke RSGetTextLength, Eax
			Cmp Eax, 1024
			Jg A2
			Mov Ecx, [Edi].EDITUNDO.chrPos.lMin
			Mov Edx, [Edi].EDITUNDO.chrPos.lMax
			Cmp Edx, Ecx
			Jge @F
			Xchg Ecx, Edx
@@:			Add Eax, Ecx
			Cmp [Esi].EDITCHILD.chrPos.lMin, Ecx
			Jl A2
			Cmp [Esi].EDITCHILD.chrPos.lMin, Eax
			Jg A2
			Mov Eax, [Esi].EDITCHILD.chrPos.lMin
			Sub Eax, Ecx
			Mov lOffset, Eax
			Invoke RSGetTextLength, [Edi].EDITUNDO.lpszText
			Inc Eax
			Mov lLength1, Eax
			Invoke RSGetBytes, Eax
			Mov Ecx, Eax
			Add Ecx, [Edi].EDITUNDO.lpszText
			Movzx Eax, Byte Ptr [Ecx]
			Invoke RSIsCharAlphaNumeric, Eax
			.If bAlphaNumeric
				Or Eax, Eax
				Jz A2
			.Else
				Or Eax, Eax
				Jnz A2
				Mov Al, Byte Ptr [Ecx]
				Or Al, Al
				Je A2
				Cmp Al, VK_RETURN
				Je A2
				Mov Edx, lpszBuf
				.If (Al == VK_TAB || Al == ' ')
					Cmp Byte Ptr [Edx], VK_TAB
					Je @F
					Cmp Byte Ptr [Edx], ' '
					Jne A2
				.ElseIf (Byte Ptr [Edx] == VK_TAB || Byte Ptr [Edx] == ' ')
					Cmp Al, VK_TAB
					Je @F
					Cmp Al, ' '
					Jne A2
				.EndIf
			.EndIf
@@:			Invoke RSModifyUndo, Ecx, lpszBuf, lOffset
			Invoke RSGetBytes, 2
			Push Eax
			Invoke RSGetTextLength, [Ebx].EDITPARENT.lpszBuffer
			Pop Ecx
			Add Eax, Ecx
			Add Eax, lLength1
			Invoke RSHeapAlloc, Eax
			.If Eax
				Mov lpsz, Eax
				Invoke lstrcpy, Eax, [Edi].EDITUNDO.lpszText
				Invoke RSGetBytes, lLength1
				Add Eax, lpsz
				Invoke lstrcpy, Eax, [Ebx].EDITPARENT.lpszBuffer
				Invoke HeapFree, [Ebx].EDITPARENT.hHeap, 0, [Edi].EDITUNDO.lpszText
				Mov Eax, lpsz
				Mov [Edi].EDITUNDO.lpszText, Eax
			.EndIf
			Ret
		.EndIf
A2:		Mov Edi, [Ebx].EDITPARENT.lUndoCount
		Invoke RSClearUndoEntry, Edi
		Shl Edi, 4
		Add Edi, [Ebx].EDITPARENT.lpUndoPointer
		Mov Eax, lpszBuf
		Or Eax, Eax
		Jz @F
		Mov Eax, lLength
		Invoke RSGetBytes, Eax
@@:		Push Eax
		Invoke RSGetBytes, 2
		Pop Ecx
		Add Eax, Ecx
		Mov Ecx, [Esi].EDITCHILD.chrPos.lMax
		Sub Ecx, [Esi].EDITCHILD.chrPos.lMin
		Push Ecx
		Push Eax
		Invoke RSGetBytes, Ecx
		Pop Ecx
		Add Eax, Ecx
		Pop Ecx
		Invoke RSHeapAlloc, Eax
		.If Eax
			Mov [Edi].EDITUNDO.lpszText, Eax
			Or Ecx, Ecx
			Jz @F
			Invoke RSGetSelectedText, Eax, (-1), FALSE
@@:			Cmp lpszBuf, NULL
			Je @F
			Inc Ecx
			Invoke RSGetBytes, Ecx
			Add Eax, [Edi].EDITUNDO.lpszText
			Invoke lstrcpy, Eax, lpszBuf
@@:			Mov Eax, [Esi].EDITCHILD.lTopLine
			Mov [Edi].EDITUNDO.lTopLine, Eax
			Mov Eax, [Esi].EDITCHILD.chrSel.lMin
			.If Eax == [Esi].EDITCHILD.chrSel.lMax
				Mov Eax, [Esi].EDITCHILD.chrPos.lMin
				Mov [Edi].EDITUNDO.chrPos.lMin, Eax
				Mov Eax, [Esi].EDITCHILD.chrPos.lMax
				Mov [Edi].EDITUNDO.chrPos.lMax, Eax
			.Else
				Mov [Edi].EDITUNDO.chrPos.lMin, Eax
				Mov Eax, [Esi].EDITCHILD.chrSel.lMax
				Mov [Edi].EDITUNDO.chrPos.lMax, Eax
			.EndIf
			Inc [Ebx].EDITPARENT.lUndoCount
			Invoke RSCheckBufferSize, 256, RSC_UNDO
			Invoke RSClearUndoEntryFrom, [Ebx].EDITPARENT.lUndoCount
		.EndIf
	.EndIf
L2:	Ret

SaveUndoW:
	Cmp Edx, [Esi].EDITCHILD.chrPos.lMax
	Jne W2
	Cmp lLength, 1
	Jne W2
	Mov Edx, lpszBuf
	Or Edx, Edx
	Jz W2
	Cmp Word Ptr [Edx], VK_TAB
	Je @F
	Cmp Word Ptr [Edx], ' '
	Jl W2
@@:	Movzx Eax, Word Ptr [Edx]
	Invoke RSIsCharAlphaNumeric, Eax
	Mov bAlphaNumeric, Eax
	.If (SDWord Ptr [Ebx].EDITPARENT.lUndoCount > 0)
		Mov Edi, [Ebx].EDITPARENT.lUndoCount
		Dec Edi
		Shl Edi, 4
		Add Edi, [Ebx].EDITPARENT.lpUndoPointer
		Cmp [Edi].EDITUNDO.lpszText, NULL
		Je W2
		Invoke RSGetTextLength, [Edi].EDITUNDO.lpszText
		Inc Eax
		Invoke RSGetBytes, Eax
		Add Eax, [Edi].EDITUNDO.lpszText
		Invoke RSGetTextLength, Eax
		Cmp Eax, 1024
		Jg W2
		Mov Ecx, [Edi].EDITUNDO.chrPos.lMin
		Mov Edx, [Edi].EDITUNDO.chrPos.lMax
		Cmp Edx, Ecx
		Jge @F
		Xchg Ecx, Edx
@@:		Add Eax, Ecx
		Cmp [Esi].EDITCHILD.chrPos.lMin, Ecx
		Jl W2
		Cmp [Esi].EDITCHILD.chrPos.lMin, Eax
		Jg W2
		Mov Eax, [Esi].EDITCHILD.chrPos.lMin
		Sub Eax, Ecx
		Mov lOffset, Eax
		Invoke RSGetTextLength, [Edi].EDITUNDO.lpszText
		Inc Eax
		Mov lLength1, Eax
		Invoke RSGetBytes, Eax
		Mov Ecx, Eax
		Add Ecx, [Edi].EDITUNDO.lpszText
		Movzx Eax, Word Ptr [Ecx]
		Invoke RSIsCharAlphaNumeric, Eax
		.If bAlphaNumeric
			Or Eax, Eax
			Jz W2
		.Else
			Or Eax, Eax
			Jnz W2
			Mov Ax, Word Ptr [Ecx]
			Or Ax, Ax
			Jz W2
			Cmp Ax, VK_RETURN
			Je W2
			Mov Edx, lpszBuf
			.If (Ax == VK_TAB || Ax == ' ')
				Cmp Word Ptr [Edx], VK_TAB
				Je @F
				Cmp Word Ptr [Edx], ' '
				Jne W2
			.ElseIf (Word Ptr [Edx] == VK_TAB || Word Ptr [Edx] == ' ')
				Cmp Ax, VK_TAB
				Je @F
				Cmp Ax, ' '
				Jne W2
			.EndIf
		.EndIf
@@:		Invoke RSModifyUndo, Ecx, lpszBuf, lOffset
		Invoke RSGetBytes, 2
		Push Eax
		Invoke RSGetTextLength, [Ebx].EDITPARENT.lpszBuffer
		Pop Ecx
		Add Eax, Ecx
		Add Eax, lLength1
		Invoke RSHeapAlloc, Eax
		.If Eax
			Mov lpsz, Eax
			Invoke lstrcpyW, Eax, [Edi].EDITUNDO.lpszText
			Invoke RSGetBytes, lLength1
			Add Eax, lpsz
			Invoke lstrcpyW, Eax, [Ebx].EDITPARENT.lpszBuffer
			Invoke HeapFree, [Ebx].EDITPARENT.hHeap, 0, [Edi].EDITUNDO.lpszText
			Mov Eax, lpsz
			Mov [Edi].EDITUNDO.lpszText, Eax
		.EndIf
		Ret
	.EndIf
W2:	Mov Edi, [Ebx].EDITPARENT.lUndoCount
	Invoke RSClearUndoEntry, Edi
	Shl Edi, 4
	Add Edi, [Ebx].EDITPARENT.lpUndoPointer
	Mov Eax, lpszBuf
	Or Eax, Eax
	Jz @F
	Mov Eax, lLength
	Invoke RSGetBytes, Eax
@@:	Push Eax
	Invoke RSGetBytes, 2
	Pop Ecx
	Add Eax, Ecx
	Mov Ecx, [Esi].EDITCHILD.chrPos.lMax
	Sub Ecx, [Esi].EDITCHILD.chrPos.lMin
	Push Ecx
	Push Eax
	Invoke RSGetBytes, Ecx
	Pop Ecx
	Add Eax, Ecx
	Pop Ecx
	Invoke RSHeapAlloc, Eax
	.If Eax
		Mov [Edi].EDITUNDO.lpszText, Eax
		Or Ecx, Ecx
		Jz @F
		Invoke RSGetSelectedText, Eax, (-1), FALSE
@@:		Cmp lpszBuf, NULL
		Je @F
		Inc Ecx
		Invoke RSGetBytes, Ecx
		Add Eax, [Edi].EDITUNDO.lpszText
		Invoke lstrcpyW, Eax, lpszBuf
@@:		Mov Eax, [Esi].EDITCHILD.lTopLine
		Mov [Edi].EDITUNDO.lTopLine, Eax
		Mov Eax, [Esi].EDITCHILD.chrSel.lMin
		.If Eax == [Esi].EDITCHILD.chrSel.lMax
			Mov Eax, [Esi].EDITCHILD.chrPos.lMin
			Mov [Edi].EDITUNDO.chrPos.lMin, Eax
			Mov Eax, [Esi].EDITCHILD.chrPos.lMax
			Mov [Edi].EDITUNDO.chrPos.lMax, Eax
		.Else
			Mov [Edi].EDITUNDO.chrPos.lMin, Eax
			Mov Eax, [Esi].EDITCHILD.chrSel.lMax
			Mov [Edi].EDITUNDO.chrPos.lMax, Eax
		.EndIf
		Inc [Ebx].EDITPARENT.lUndoCount
		Invoke RSCheckBufferSize, 256, RSC_UNDO
		Invoke RSClearUndoEntryFrom, [Ebx].EDITPARENT.lUndoCount
	.EndIf
	Jmp L2
RSSaveUndo EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to editor child's data
RSScroll Proc Private Uses Edx Edi lLines:LONG, lColumns:LONG
	Mov Edi, lLines
	Cmp Edi, 0
	Je L4
	Mov Eax, [Ebx].EDITPARENT.lLines
	Cmp Eax, 0
	Jle L4
	Add Edi, [Esi].EDITCHILD.lTopLine
	Cmp Edi, 0
	Jge @F
	Xor Edi, Edi
@@:	Cmp lLines, 0
	Jl L2
	Inc Eax
	Cmp Eax, [Esi].EDITCHILD.lVScrollPage
	Jle L4
	Sub Eax, [Esi].EDITCHILD.lVScrollPage
	Cmp Eax, Edi
	Jge L2
	Mov Edi, Eax
	Cmp [Esi].EDITCHILD.lTopLine, Eax
	Jle L2
	Cmp lLines, 0
	Jg L4
L2:	Cmp Edi, [Esi].EDITCHILD.lTopLine
	Je L4

	Mov [Esi].EDITCHILD.lPaint, PAINT_ALL
	Invoke RSGetLineIndex, Edi
	Mov [Esi].EDITCHILD.lTopLineIndex, Eax
	Mov [Esi].EDITCHILD.lTopLine, Edi

L4:	Cmp lColumns, 0
	Je L6
	Mov Edi, lColumns
	Add Edi, [Ebx].EDITPARENT.lHScrollPos
	Cmp Edi, 0
	Jge @F
	Xor Edi, Edi
@@:	Mov Eax, [Ebx].EDITPARENT.lHScrollMax
	Cmp Eax, 0
	Jle L6
	Sub Eax, [Ebx].EDITPARENT.lHScrollPage
	Cmp Eax, Edi
	Jge @F
	Mov Edi, Eax
@@:	Cmp Edi, [Ebx].EDITPARENT.lHScrollPos
	Jne @F
	Ret
@@:	Mov [Esi].EDITCHILD.lPaint, PAINT_ALL
	Mov [Ebx].EDITPARENT.lHScrollPos, Edi
	.If [Ebx].EDITPARENT.Mirror.hWnd
		Mov [Ebx].EDITPARENT.Mirror.lPaint, PAINT_ALL
	.EndIf
L6:	Ret
RSScroll EndP

;On enter Ebx = Pointer to editor parent's data
RSSearchCaseDown Proc Private Uses Ecx Edx Edi Esi lpszString:LPSTR, lChars:LONG, lSearchLength:LONG, lpszSearch:LPSTR, lFlags:LONG
	Mov Esi, lpszString
	Mov Ecx, lChars
	Cmp [Ebx].EDITPARENT.bTextUnicode, FALSE
	Jne SearchCaseDownW
A2:	Cmp Ecx, lSearchLength
	Jl L2
	Mov Edi, lpszSearch
	Push Ecx
	Push Esi
@@:	Mov Ah, Byte Ptr [Edi]
	Or Ah, Ah
	Jz @F
	Mov Al, Byte Ptr [Esi]
	Inc Esi
	Inc Edi
	Cmp Al, Ah
	Je @B
	Pop Esi
	Pop Ecx
A4:	Dec Ecx
	Inc Esi
	Jmp A2
@@:	Pop Eax
	Mov Esi, Eax
	Pop Ecx
	Sub Eax, lpszString
	.If (lFlags & RSC_WHOLEWORD)
		Mov Edx, Eax
		Invoke RSIsWholeWord, lpszString, Eax, lSearchLength
		Cmp Eax, (-1)
		Je A4
		Mov Eax, Edx
	.EndIf
	Jmp L4
L2:	Mov Eax, (-1)
	Jmp L4

SearchCaseDownW:
	Cmp Ecx, lSearchLength
	Jl L2
	Mov Edi, lpszSearch
	Push Ecx
	Push Esi
@@:	Mov Dx, Word Ptr [Edi]
	Or Dx, Dx
	Jz @F
	Mov Ax, Word Ptr [Esi]
	Add Esi, 2
	Add Edi, 2
	Cmp Ax, Dx
	Je @B
	Pop Esi
	Pop Ecx
W2:	Dec Ecx
	Add Esi, 2
	Jmp SearchCaseDownW
@@:	Pop Eax
	Mov Esi, Eax
	Pop Ecx
	Sub Eax, lpszString
	Shr Eax, 1
	.If (lFlags & RSC_WHOLEWORD)
		Mov Edx, Eax
		Invoke RSIsWholeWord, lpszString, Eax, lSearchLength
		Cmp Eax, (-1)
		Je W2
		Mov Eax, Edx
	.EndIf
L4:	Ret
RSSearchCaseDown EndP

;On enter Ebx = Pointer to editor parent's data
RSSearchCaseUp Proc Private Uses Ecx Edx Esi Edi lpszString:LPSTR, lChars:LONG, lSearchLength:LONG, lpszSearch:LPSTR, lFlags:LONG
	Mov Esi, lpszString
	Cmp [Ebx].EDITPARENT.bTextUnicode, FALSE
	Jne SearchCaseUpW
	Mov Ecx, lChars
	Sub Ecx, lSearchLength
	Jl L2
	Add Esi, Ecx
	Xor Eax, Eax
A2:	Mov Edi, lpszSearch
	Push Ecx
	Push Esi
@@:	Mov Ah, Byte Ptr [Edi]
	Or Ah, Ah
	Jz @F
	Mov Al, Byte Ptr [Esi]
	Inc Esi
	Inc Edi
	Cmp Al, Ah
	Je @B
	Pop Esi
	Pop Ecx
A4:	Dec Ecx
	Jl L2
	Dec Esi
	Jmp A2
@@:	Pop Eax
	Mov Esi, Eax
	Pop Ecx
	Sub Eax, lpszString
	.If (lFlags & RSC_WHOLEWORD)
		Mov Edx, Eax
		Invoke RSIsWholeWord, lpszString, Eax, lSearchLength
		Cmp Eax, (-1)
		Je A4
		Mov Eax, Edx
	.EndIf
	Jmp L4
L2:	Mov Eax, (-1)
	Jmp L4

SearchCaseUpW:
	Mov Eax, lChars
	Sub Eax, lSearchLength
	Jl L2
	Mov Ecx, Eax
	Shl Eax, 1
	Add Esi, Eax
W2:	Mov Edi, lpszSearch
	Push Ecx
	Push Esi
@@:	Mov Dx, Word Ptr [Edi]
	Or Dx, Dx
	Jz @F
	Mov Ax, Word Ptr [Esi]
	Add Esi, 2
	Add Edi, 2
	Cmp Ax, Dx
	Je @B
	Pop Esi
	Pop Ecx
W4:	Dec Ecx
	Jl L2
	Sub Esi, 2
	Jmp W2
@@:	Pop Eax
	Mov Esi, Eax
	Pop Ecx
	Sub Eax, lpszString
	Shr Eax, 1
	.If (lFlags & RSC_WHOLEWORD)
		Mov Edx, Eax
		Invoke RSIsWholeWord, lpszString, Eax, lSearchLength
		Cmp Eax, (-1)
		Je W4
		Mov Eax, Edx
	.EndIf
L4:	Ret
RSSearchCaseUp EndP

;On enter Ebx = Pointer to editor parent's data
RSSearchNoCaseDown Proc Private Uses Ebx Ecx Edx Edi Esi lpszString:LPSTR, lChars:LONG, lSearchLength:LONG, lpszSearch:LPSTR, lFlags:LONG
	Local dwRegEbx:DWord

	Mov dwRegEbx, Ebx
	Mov Esi, lpszString
	Mov Ecx, lChars
	Xor Eax, Eax
	Cmp [Ebx].EDITPARENT.bTextUnicode, FALSE
	Jne SearchNoCaseDownW
	Mov Ebx, lpUCaseTableA
A2:	Cmp Ecx, lSearchLength
	Jl L2
	Mov Edi, lpszSearch
	Push Ecx
	Push Esi
@@:	Movzx Eax, Byte Ptr [Edi]
	Or Al, Al
	Jz @F
	Mov Dl, Byte Ptr [Ebx + Eax]
	Movzx Eax, Byte Ptr [Esi]
	Mov Al, Byte Ptr [Ebx + Eax]
	Inc Esi
	Inc Edi
	Cmp Al, Dl
	Je @B
	Pop Esi
	Pop Ecx
A4:	Dec Ecx
	Inc Esi
	Jmp A2
@@:	Pop Eax
	Mov Esi, Eax
	Pop Ecx
	Sub Eax, lpszString
	.If (lFlags & RSC_WHOLEWORD)
		Mov Edx, Eax
		Xchg Ebx, dwRegEbx
		Invoke RSIsWholeWord, lpszString, Eax, lSearchLength
		Xchg Ebx, dwRegEbx
		Cmp Eax, (-1)
		Je A4
		Mov Eax, Edx
	.EndIf
	Jmp L4
L2:	Mov Eax, (-1)
	Jmp L4

SearchNoCaseDownW:
	Mov Ebx, lpUCaseTableW
W2:	Cmp Ecx, lSearchLength
	Jl L2
	Mov Edi, lpszSearch
	Push Ecx
	Push Esi
@@:	Movzx Eax, Word Ptr [Edi]
	Or Ax, Ax
	Jz @F
	Shl Eax, 1
	Mov Dx, Word Ptr [Ebx + Eax]
	Movzx Eax, Word Ptr [Esi]
	Shl Eax, 1
	Mov Ax, Word Ptr [Ebx + Eax]
	Add Esi, 2
	Add Edi, 2
	Cmp Ax, Dx
	Je @B
	Pop Esi
	Pop Ecx
W4:	Dec Ecx
	Add Esi, 2
	Jmp W2
@@:	Pop Eax
	Mov Esi, Eax
	Pop Ecx
	Sub Eax, lpszString
	Shr Eax, 1
	.If (lFlags & RSC_WHOLEWORD)
		Mov Edx, Eax
		Xchg Ebx, dwRegEbx
		Invoke RSIsWholeWord, lpszString, Eax, lSearchLength
		Xchg Ebx, dwRegEbx
		Cmp Eax, (-1)
		Je W4
		Mov Eax, Edx
	.EndIf
L4:	Ret
RSSearchNoCaseDown EndP

;On enter Ebx = Pointer to editor parent's data
RSSearchNoCaseUp Proc Private Uses Ebx Ecx Edx Edi Esi lpszString:LPSTR, lChars:LONG, lSearchLength:LONG, lpszSearch:LPSTR, lFlags:LONG
	Local dwRegEbx:DWord

	Mov dwRegEbx, Ebx
	Mov Esi, lpszString
	Cmp [Ebx].EDITPARENT.bTextUnicode, FALSE
	Jne SearchNoCaseUpW
	Mov Ebx, lpUCaseTableA
	Mov Ecx, lChars
	Sub Ecx, lSearchLength
	Jl L2
	Add Esi, Ecx
	Xor Eax, Eax
A2:	Mov Edi, lpszSearch
	Push Ecx
	Push Esi
@@:	Movzx Eax, Byte Ptr [Edi]
	Or Al, Al
	Jz @F
	Mov Dl, Byte Ptr [Ebx + Eax]
	Movzx Eax, Byte Ptr [Esi]
	Mov Al, Byte Ptr [Ebx + Eax]
	Inc Esi
	Inc Edi
	Cmp Al, Dl
	Je @B
	Pop Esi
	Pop Ecx
A4:	Dec Ecx
	Jl L2
	Dec Esi
	Jmp A2
@@:	Pop Eax
	Mov Esi, Eax
	Pop Ecx
	Sub Eax, lpszString
	.If (lFlags & RSC_WHOLEWORD)
		Mov Edx, Eax
		Xchg Ebx, dwRegEbx
		Invoke RSIsWholeWord, lpszString, Eax, lSearchLength
		Xchg Ebx, dwRegEbx
		Cmp Eax, (-1)
		Je A4
		Mov Eax, Edx
	.EndIf
	Jmp L4
L2:	Mov Eax, (-1)
	Jmp L4

SearchNoCaseUpW:
	Mov Ebx, lpUCaseTableW
	Mov Eax, lChars
	Sub Eax, lSearchLength
	Jl L2
	Mov Ecx, Eax
	Shl Eax, 1
	Add Esi, Eax
	Xor Eax, Eax
W2:	Mov Edi, lpszSearch
	Push Ecx
	Push Esi
@@:	Movzx Eax, Word Ptr [Edi]
	Or Ax, Ax
	Jz @F
	Shl Eax, 1
	Mov Dx, Word Ptr [Ebx + Eax]
	Movzx Eax, Word Ptr [Esi]
	Shl Eax, 1
	Mov Ax, Word Ptr [Ebx + Eax]
	Add Esi, 2
	Add Edi, 2
	Cmp Ax, Dx
	Je @B
	Pop Esi
	Pop Ecx
W4:	Dec Ecx
	Jl L2
	Sub Esi, 2
	Jmp W2
@@:	Pop Eax
	Mov Esi, Eax
	Pop Ecx
	Sub Eax, lpszString
	Shr Eax, 1
	.If (lFlags & RSC_WHOLEWORD)
		Mov Edx, Eax
		Xchg Ebx, dwRegEbx
		Invoke RSIsWholeWord, lpszString, Eax, lSearchLength
		Xchg Ebx, dwRegEbx
		Cmp Eax, (-1)
		Je W4
		Mov Eax, Edx
	.EndIf
L4:	Ret
RSSearchNoCaseUp EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to editor child's data
RSSelectWord Proc Private Uses Ecx Edx Edi lIndex:LONG, bSpaces:BOOL
	Local ChrInf:RSSCHARINFO

	Mov [Esi].EDITCHILD.lPaint, PAINT_LINE
	Invoke RSGetCharInfo, lIndex, Addr ChrInf
	Cmp Eax, (-1)
	Jne @F
L2:	Ret

@@:	Mov Edx, ChrInf.lLine
	Shl Edx, 4
	Add Edx, [Ebx].EDITPARENT.lpLinesPointer
	Mov Edi, [Edx].LINE.lpszText
	Mov Ecx, ChrInf.lLineOffset
	.If [Edx].LINE.lLength == 0
L4:		Add Ecx, ChrInf.lLineIndex
		Mov [Esi].EDITCHILD.chrPos.lMin, Ecx
		Mov [Esi].EDITCHILD.chrPos.lMax, Ecx
		Jmp L2
	.EndIf
	Invoke RSGetBytes, Ecx
	Cmp [Ebx].EDITPARENT.bTextUnicode, FALSE
	Jne SelectWordW
	.If (Ecx == [Edx].LINE.lLength || Byte Ptr [Edi + Eax] == VK_RETURN || Byte Ptr [Edi + Eax] == ' ')
		Or Ecx, Ecx
		Jz L4
		Dec Ecx
	.ElseIf (Byte Ptr [Edi + Eax] == VK_TAB)
		Add Ecx, ChrInf.lLineIndex
		Mov [Esi].EDITCHILD.chrPos.lMin, Ecx
		Inc Ecx
		Mov [Esi].EDITCHILD.chrPos.lMax, Ecx
		Ret
	.EndIf
	Movzx Eax, Byte Ptr [Edi + Eax]
	Cmp Eax, VK_SPACE
	Je @F
	Cmp Eax, VK_TAB
	Je @F
	Cmp Eax, VK_RETURN
	Je @F
	Invoke RSIsCharAlphaNumeric, Eax
	.If Eax
@@:		Inc Ecx
		Cmp Ecx, [Edx].LINE.lLength
		Jge @F
		Invoke RSGetBytes, Ecx
		Movzx Eax, Byte Ptr [Edi + Eax]
		Invoke RSIsCharAlphaNumeric, Eax
		Or Eax, Eax
		Jnz @B
@@:		Add Ecx, ChrInf.lLineIndex
		Mov [Esi].EDITCHILD.chrPos.lMax, Ecx
		Mov Ecx, ChrInf.lLineOffset
@@:		Dec Ecx
		Jl @F
		Invoke RSGetBytes, Ecx
		Movzx Eax, Byte Ptr [Edi + Eax]
		Invoke RSIsCharAlphaNumeric, Eax
		Or Eax, Eax
		Jnz @B
@@:		Inc Ecx
		Add Ecx, ChrInf.lLineIndex
		Mov [Esi].EDITCHILD.chrPos.lMin, Ecx
	.Else
@@:		Invoke RSGetBytes, Ecx
		Cmp Byte Ptr [Edi + Eax], VK_RETURN
		Je @F
		Cmp Ecx, [Edx].LINE.lLength
		Jge @F
		Cmp Byte Ptr [Edi + Eax], ' '
		Je @F
		Inc Ecx
		Inc Eax
		Cmp Byte Ptr [Edi + Eax], VK_TAB
		Je @F
		Cmp Ecx, [Edx].LINE.lLength
		Jge @F
		Movzx Eax, Byte Ptr [Edi + Ecx]
		Invoke RSIsCharAlphaNumeric, Eax
		Or Eax, Eax
		Jz @B
@@:		Add Ecx, ChrInf.lLineIndex
		Mov [Esi].EDITCHILD.chrPos.lMax, Ecx
		Mov Ecx, ChrInf.lLineOffset
@@:		Dec Ecx
		Jl @F
		Invoke RSGetBytes, Ecx
		Cmp Byte Ptr [Edi + Eax], VK_TAB
		Je @F
		Cmp Byte Ptr [Edi + Eax], ' '
		Je @F
		Movzx Eax, Byte Ptr [Edi + Eax]
		Invoke RSIsCharAlphaNumeric, Eax
		Or Eax, Eax
		Jz @B
@@:		Inc Ecx
		Add Ecx, ChrInf.lLineIndex
		Mov [Esi].EDITCHILD.chrPos.lMin, Ecx
	.EndIf
	Jmp L2

SelectWordW:
	.If (Ecx == [Edx].LINE.lLength || Word Ptr [Edi + Eax] == VK_RETURN || Word Ptr [Edi + Eax] == ' ')
		Or Ecx, Ecx
		Jz L4
		Dec Ecx
	.ElseIf (Word Ptr [Edi + Eax] == VK_TAB)
		Add Ecx, ChrInf.lLineIndex
		Mov [Esi].EDITCHILD.chrPos.lMin, Ecx
		Inc Ecx
		Mov [Esi].EDITCHILD.chrPos.lMax, Ecx
		Ret
	.EndIf
	Movzx Eax, Word Ptr [Edi + Eax]
	Cmp Eax, VK_SPACE
	Je @F
	Cmp Eax, VK_TAB
	Je @F
	Cmp Eax, VK_RETURN
	Je @F
	Invoke RSIsCharAlphaNumeric, Eax
	.If Eax
@@:		Inc Ecx
		Cmp Ecx, [Edx].LINE.lLength
		Jge @F
		Invoke RSGetBytes, Ecx
		Movzx Eax, Word Ptr [Edi + Eax]
		Invoke RSIsCharAlphaNumeric, Eax
		Or Eax, Eax
		Jnz @B
@@:		Add Ecx, ChrInf.lLineIndex
		Mov [Esi].EDITCHILD.chrPos.lMax, Ecx
		Mov Ecx, ChrInf.lLineOffset
@@:		Dec Ecx
		Jl @F
		Invoke RSGetBytes, Ecx
		Movzx Eax, Word Ptr [Edi + Eax]
		Invoke RSIsCharAlphaNumeric, Eax
		Or Eax, Eax
		Jnz @B
@@:		Inc Ecx
		Add Ecx, ChrInf.lLineIndex
		Mov [Esi].EDITCHILD.chrPos.lMin, Ecx
	.Else
@@:		Invoke RSGetBytes, Ecx
		Cmp Word Ptr [Edi + Eax], VK_RETURN
		Je @F
		Cmp Ecx, [Edx].LINE.lLength
		Jge @F
		Cmp Word Ptr [Edi + Eax], ' '
		Je @F
		Inc Ecx
		Add Eax, 2
		Cmp Word Ptr [Edi + Eax], VK_TAB
		Je @F
		Cmp Ecx, [Edx].LINE.lLength
		Jge @F
		Movzx Eax, Byte Ptr [Edi + Eax]
		Invoke RSIsCharAlphaNumeric, Eax
		Or Eax, Eax
		Jz @B
@@:		Add Ecx, ChrInf.lLineIndex
		Mov [Esi].EDITCHILD.chrPos.lMax, Ecx
		Mov Ecx, ChrInf.lLineOffset
@@:		Dec Ecx
		Jl @F
		Invoke RSGetBytes, Ecx
		Cmp Word Ptr [Edi + Eax], VK_TAB
		Je @F
		Cmp Word Ptr [Edi + Eax], ' '
		Je @F
		Movzx Eax, Word Ptr [Edi + Eax]
		Invoke RSIsCharAlphaNumeric, Eax
		Or Eax, Eax
		Jz @B
@@:		Inc Ecx
		Add Ecx, ChrInf.lLineIndex
		Mov [Esi].EDITCHILD.chrPos.lMin, Ecx
	.EndIf
	Jmp L2
RSSelectWord EndP

;On enter Ebx = Pointer to editor parent's data
RSSendCommandMessage Proc Private Uses Ecx Edx lCode:LONG
	.If lCode == EN_CHANGE
		.If [Ebx].EDITPARENT.bChangeEvent
			Mov [Ebx].EDITPARENT.bChangeEvent, FALSE
			.If ([Ebx].EDITPARENT.dwEventMask & RSV_CHANGE)
@@:				Mov Eax, lCode
				Shl Eax, 16
				Or Eax, [Ebx].EDITPARENT.lCtrlID
				Invoke RSSendMessage, [Ebx].EDITPARENT.hWndParent, WM_COMMAND, Eax, [Ebx].EDITPARENT.hWnd
			.EndIf
		.EndIf
	.ElseIf lCode == EN_UPDATE
		.If ([Ebx].EDITPARENT.dwEventMask & RSV_UPDATE)
			Jmp @B
		.EndIf
	.ElseIf lCode == EN_KILLFOCUS
		.If ([Ebx].EDITPARENT.dwEventMask & RSV_KILLFOCUS)
			Jmp @B
		.EndIf
	.ElseIf lCode == EN_SETFOCUS
		.If ([Ebx].EDITPARENT.dwEventMask & RSV_SETFOCUS)
			Jmp @B
		.EndIf
	.ElseIf lCode == EN_HSCROLL
		.If ([Ebx].EDITPARENT.dwEventMask & RSV_HSCROLL)
			Jmp @B
		.EndIf
	.ElseIf lCode == EN_VSCROLL
		.If ([Ebx].EDITPARENT.dwEventMask & RSV_VSCROLL)
			Jmp @B
		.EndIf
	.EndIf
	Ret
RSSendCommandMessage EndP

;On enter Ebx = Pointer to editor parent's data
RSSendMessage Proc Private hWnd:HWND, uMsg:ULONG, wParam:WPARAM, lParam:LPARAM
	Push lParam
	Push wParam
	Push uMsg
	Push hWnd
	.If [Ebx].EDITPARENT.bTextUnicode
		Mov Eax, SendMessageW
	.Else
		Mov Eax, SendMessage
	.EndIf
	Call Eax
	Ret
RSSendMessage EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to editor child's data
RSSendNotifyMessage Proc Private Uses Ecx Edx uCode:ULONG
	Local sch:SELCHANGE

	Mov Eax, [Ebx].EDITPARENT.hWnd
	Mov sch.nmhdr.hwndFrom, Eax
	Move sch.nmhdr.idFrom, [Ebx].EDITPARENT.lCtrlID
	Mov Eax, uCode
	Mov sch.nmhdr.code, Eax
	Cmp uCode, EN_SELCHANGE
	Jne L2
	Mov Eax, [Esi].EDITCHILD.chrPos.lMax
	Mov sch.chrg.cpMax, Eax
	Mov Ecx, SEL_EMPTY
	Sub Eax, [Esi].EDITCHILD.chrPos.lMin
	Jz @F
	Mov Ecx, SEL_TEXT
	Cmp Eax, 1
	Je @F
	Or Ecx, SEL_MULTICHAR
@@:	Mov sch.seltyp, Cx
	Mov Eax, [Esi].EDITCHILD.chrPos.lMin
	Mov sch.chrg.cpMin, Eax
L2:	Invoke RSSendMessage, [Ebx].EDITPARENT.hWndParent, WM_NOTIFY, [Ebx].EDITPARENT.lCtrlID, Addr sch
	Ret
RSSendNotifyMessage EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to editor child's data
RSSetCaret Proc Private Uses Ecx Edx
	Local pt:POINTL

	Cmp [Ebx].EDITPARENT.bReadOnly, FALSE
	Je @F
	Ret
@@:	Mov Eax, RSszText.x
	Sub Eax, [Ebx].EDITPARENT.lHScrollPos
	Add Eax, [Ebx].EDITPARENT.lSelBarWidth
	Cmp Eax, [Ebx].EDITPARENT.lSelBarWidth
	Jge @F
	Sub Eax, [Ebx].EDITPARENT.lSelBarWidth
@@:	Mov pt.x, Eax
	Mov Eax, [Ebx].EDITPARENT.lCaretWidth
	Cmp [Ebx].EDITPARENT.bInsert, FALSE
	Jne @F
	Mov Eax, RSptCaret.x
@@:	Invoke CreateCaret, [Esi].EDITCHILD.hWnd, NULL, Eax, [Ebx].EDITPARENT.szFont.y
	Mov [Ebx].EDITPARENT.bCaret, FALSE

	Mov Ecx, [Ebx].EDITPARENT.szFont.y
	Mov Eax, [Esi].EDITCHILD.lCurLine
	Sub Eax, [Esi].EDITCHILD.lTopLine
	Mul Ecx
	Mov pt.y, Eax
	Invoke SetCaretPos, pt.x, pt.y
	Mov Eax, [Esi].EDITCHILD.chrPos.lMin
	Cmp Eax, [Esi].EDITCHILD.chrPos.lMax
	Jne L2
	Cmp [Ebx].EDITPARENT.bCaret, FALSE
	Je @F
	Ret
@@:	Mov [Ebx].EDITPARENT.bCaret, TRUE
	Invoke ShowCaret, [Ebx].EDITPARENT.hWndFocus
	Ret
L2:	Cmp [Ebx].EDITPARENT.bCaret, FALSE
	Jne @F
	Ret
@@:	Mov [Ebx].EDITPARENT.bCaret, FALSE
	Invoke HideCaret, [Ebx].EDITPARENT.hWndFocus
	Ret
RSSetCaret EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to editor child's data
RSSetEditorColors Proc Private
	Invoke RSGetRealColor, [Ebx].EDITPARENT.crBackColor
	Mov [Ebx].EDITPARENT.crBackColor, Eax
	Invoke CreateSolidBrush, Eax
	Xchg [Ebx].EDITPARENT.hBackBrush, Eax
	Invoke DeleteObject, Eax
	Invoke RSGetRealColor, [Ebx].EDITPARENT.crTextColor
	Mov [Ebx].EDITPARENT.crTextColor, Eax
	Invoke RSGetRealColor, [Ebx].EDITPARENT.crBackSelect
	Mov [Ebx].EDITPARENT.crBackSelect, Eax
	Invoke CreateSolidBrush, Eax
	Xchg [Ebx].EDITPARENT.hSelectBrush, Eax
	Invoke DeleteObject, Eax
	Invoke RSGetRealColor, [Ebx].EDITPARENT.crTextSelect
	Mov [Ebx].EDITPARENT.crTextSelect, Eax
	Invoke RSGetRealColor, [Ebx].EDITPARENT.crBackMargin
	Mov [Ebx].EDITPARENT.crBackMargin, Eax
	Invoke CreateSolidBrush, Eax
	Xchg [Ebx].EDITPARENT.hMarginBrush, Eax
	Invoke DeleteObject, Eax
	Invoke RSGetRealColor, [Ebx].EDITPARENT.crBackLocked
	Mov [Ebx].EDITPARENT.crBackLocked, Eax
	Invoke CreateSolidBrush, Eax
	Xchg [Ebx].EDITPARENT.hLockedBrush, Eax
	Invoke DeleteObject, Eax
	Mov [Esi].EDITCHILD.lPaint, PAINT_ALL
	Invoke RSInvalidateEditor, [Esi].EDITCHILD.hWnd, TRUE
	Ret
RSSetEditorColors EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to editor child's data
RSSetEditorCursor Proc Private Uses Ecx Edx hWnd:HWND, uMsg:ULONG, wParam:WPARAM, lParam:LPARAM
	Local pt:POINTL

	Invoke GetCursorPos, Addr pt
	Invoke ScreenToClient, [hWnd], Addr pt
	Mov Ecx, [RShIBeam]
	Mov Eax, [pt.x]
	Cmp Eax, [Ebx].EDITPARENT.lSelBarWidth
	Jge L2
	Mov Ecx, [RShRArrow]
L2:	Cmp Eax, [Esi].EDITCHILD.rc.right
	Jle L4
	Mov Ecx, [RShArrow]
L4:	Invoke SetClassLong, hWnd, GCL_HCURSOR, Ecx
	Push Eax
	Invoke DefWindowProc, hWnd, uMsg, wParam, lParam
	Pop Eax
	Invoke SetClassLong, hWnd, GCL_HCURSOR, Eax
	Ret
RSSetEditorCursor EndP

;On enter Ebx = Pointer to editor parent's data
RSSetLineInfo Proc Private Uses Edx lLine:LONG, lBytesLength:LONG
	Invoke RSCheckBufferSize, 1, RSC_LINES
	Mov Edx, lLine
	Shl Edx, 4
	Add Edx, [Ebx].EDITPARENT.lpLinesPointer
	Mov Eax, [Ebx].EDITPARENT.lpszNextText
	Mov [Edx].LINE.lpszText, Eax
	Mov Eax, lBytesLength
	Add [Ebx].EDITPARENT.lpszNextText, Eax
	Invoke RSGetChars, Eax
	Mov [Edx].LINE.lLength, Eax
	Mov [Edx].LINE.lMaxLength, Eax
	Mov [Edx].LINE.lState, 0
	Ret
RSSetLineInfo EndP

;On enter Ebx = Pointer to editor parent's data
RSSetNewText Proc Private Uses Esi lpszText:LPSTR
	Push [Ebx].EDITPARENT.dwEventMask
	Mov [Ebx].EDITPARENT.dwEventMask, 0
	Invoke RSDestroyMirror
	Mov Eax, lpszText
	Or Eax, Eax
	Jz @F
	Invoke RSGetTextLength, lpszText
	Add Eax, 2
@@:	Invoke RSGetBytes, Eax
	Mov Edx, Eax
	Invoke RSAllocateEditorMemory, Eax
	Invoke RSInitEditor
	Push Edx
	.If (!RSbAppUnicode)
		Mov [Ebx].EDITPARENT.bBigEndian, FALSE
		Mov [Ebx].EDITPARENT.bTextUnicode, FALSE
		Mov [Ebx].EDITPARENT.bTextUnicodeUTF8, FALSE
	.EndIf
	Invoke SendMessage, [Ebx].EDITPARENT.hWnd, RSM_CREATEFONT, TRUE, Addr RSFont
	Pop Edx
	Or Edx, Edx
	Jz @F
	Invoke RSSetText, lpszText, [Ebx].EDITPARENT.lpTextPointer, (-1)
@@:	Pop [Ebx].EDITPARENT.dwEventMask
	Lea Esi, [Ebx].EDITPARENT.Editor
	Invoke RSSetSelection, 0, 0, 0
	Invoke InvalidateRect, [Esi].EDITCHILD.hWnd, NULL, FALSE
	Invoke RSSetCaret
	Invoke RSUpdateScrollBars, (SCROLL_HORZ Or SCROLL_VERT)
	Mov [Ebx].EDITPARENT.bModified, FALSE
	Ret
RSSetNewText EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to editor child's data
RSSetPosition Proc Private Uses Ecx Edx Edi lMin:LONG, lMax:LONG
	Local ChrInf:RSSCHARINFO

	Mov Ecx, lMin
	Mov Edx, lMax
	Cmp Ecx, 0
	Jge @F
	Ret
@@:	Cmp Edx, 0
	Jge @F
	Ret
@@:	Cmp Ecx, [Ebx].EDITPARENT.lMaxIndex
	Jle @F
	Ret
@@:	Cmp Edx, [Ebx].EDITPARENT.lMaxIndex
	Jle @F
	Ret
@@:	Cmp Ecx, Edx
	Jne @F
	Mov Eax, [Esi].EDITCHILD.chrSel.lMin
	Cmp Eax, [Esi].EDITCHILD.chrSel.lMax
	Je @F
	Mov [Esi].EDITCHILD.lPaint, PAINT_ALL
@@:	Xor Eax, Eax
	Cmp Ecx, [Esi].EDITCHILD.chrSel.lMin
	Je @F
	Inc Eax
@@:	Mov [Esi].EDITCHILD.chrSel.lMin, Ecx
	Cmp Edx, [Esi].EDITCHILD.chrSel.lMax
	Je @F
	Inc Eax
@@:	Mov [Esi].EDITCHILD.chrSel.lMax, Edx
	Mov Edi, Eax
	Invoke RSGetCharInfo, Edx, Addr ChrInf
	Mov Edx, ChrInf.lLine
	Mov Ecx, ChrInf.lLineOffset
	Mov [Esi].EDITCHILD.lCurLine, Edx
	Mov [Esi].EDITCHILD.lCurCol, Ecx
	Mov Ecx, [Esi].EDITCHILD.chrSel.lMin
	Mov Edx, [Esi].EDITCHILD.chrSel.lMax
	Cmp Ecx, Edx
	Jle @F
	Xchg Ecx, Edx
@@:	Mov [Esi].EDITCHILD.chrPos.lMin, Ecx
	Mov [Esi].EDITCHILD.chrPos.lMax, Edx
	Mov Eax, Edi
	Ret
RSSetPosition EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to active editor child's data
RSSetScrollCounter Proc Private Uses Edi hWnd:HWND, lpPt:LPLONG
	Local rc:RECT

	Invoke GetClientRect, hWnd, Addr rc
	Mov Edi, lpPt
	Invoke GetCursorPos, Edi
	Invoke ScreenToClient, hWnd, Edi
	Xor Edx, Edx
	Mov Ecx, [Ebx].EDITPARENT.szFont.y
	Mov Eax, rc.bottom
	Div Ecx
	Mul Ecx
	Mov rc.bottom, Eax
	Xor Eax, Eax
	Mov Edx, [Edi].POINTL.y
	.If Edx < SDWord Ptr rc.top
		Sub Eax, Ecx
		Mov [Edi].POINTL.y, Eax
		Shr Ecx, 1
		Mov Eax, 6
		Sub rc.top, Ecx
		.If Edx < SDWord Ptr rc.top
			Mov Eax, 2
			Sub [Edi].POINTL.y, Ecx
		.EndIf
		Sub rc.top, Ecx
		.If Edx < SDWord Ptr rc.top
			Shl Ecx, 1
			Sub [Edi].POINTL.y, Ecx
			Mov Eax, 1
		.EndIf
	.ElseIf Edx > SDWord Ptr rc.bottom
		Mov Eax, rc.bottom
		Add Eax, 2 ;Ecx
		Mov [Edi].POINTL.y, Eax
		Shr Ecx, 1
		Mov Eax, 6
		Add rc.bottom, Ecx
		.If Edx > SDWord Ptr rc.bottom
			Add [Edi].POINTL.y, Ecx
			Mov Eax, 2
		.EndIf
		Add rc.bottom, Ecx
		.If Edx > SDWord Ptr rc.bottom
			Add [Edi].POINTL.y, Ecx
			Mov Eax, 1
		.EndIf
	.EndIf
	Mov [Ebx].EDITPARENT.lVScrollCounter, Eax
	Ret
RSSetScrollCounter EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to editor child's data
RSSetSelection Proc Private Uses Ecx Edx Edi lMin:LONG, lMax:LONG, lKey:LONG
	Invoke RSSetPosition, lMin, lMax
	.If ([Ebx].EDITPARENT.bRedraw)
L1:		Push Eax
		Mov Eax, [Esi].EDITCHILD.lTopLine
		Add Eax, [Esi].EDITCHILD.lVScrollPage
		Cmp [Esi].EDITCHILD.lCurLine, Eax
		Jl @F
		Mov Ecx, [Esi].EDITCHILD.lCurLine
		Sub Ecx, Eax
		Inc Ecx
		Invoke RSScroll, Ecx, 0
		Jmp L2
@@:		Mov Ecx, [Esi].EDITCHILD.lCurLine
		Cmp Ecx, [Esi].EDITCHILD.lTopLine
		Jl @F ;Jge L2
		Cmp lKey, VK_DELETE
		Jne L2
		Mov Eax, [Ebx].EDITPARENT.lLines
		Cmp Eax, [Esi].EDITCHILD.lVScrollPage
		Jge L2
		Xor Ecx, Ecx
@@:		Sub Ecx, [Esi].EDITCHILD.lTopLine
		Jz L2
		Invoke RSScroll, Ecx, 0
L2:		Mov Edx, [Esi].EDITCHILD.lCurLine
		Shl Edx, 4
		Add Edx, [Ebx].EDITPARENT.lpLinesPointer
		Invoke RSExpandTabs, Edx, Addr [Esi].EDITCHILD.lRealCol
		Invoke GetDC, [Esi].EDITCHILD.hWnd
		Mov Edi, Eax
		Invoke SelectObject, Edi, [Ebx].EDITPARENT.hFont
		Push Eax
		Mov RSszText.x, 0
		.If [Ebx].EDITPARENT.lpszLine
			Invoke RSGetTextExtentPoint32, Edi, [Ebx].EDITPARENT.lpszLine, [Esi].EDITCHILD.lRealCol, Addr RSszText
		.Else
			Mov [Esi].EDITCHILD.lRealCol, 0
		.EndIf
		Cmp [Ebx].EDITPARENT.bInsert, FALSE
		Jne @F
		Mov Edx, [Ebx].EDITPARENT.lpszLine
		.If Edx
			Add Edx, [Esi].EDITCHILD.lRealCol
			Invoke RSGetTextExtentPoint32, Edi, Edx, 1, Addr RSptCaret
		.Else
			Mov Eax, [Ebx].EDITPARENT.szFont.x
			Mov RSptCaret.x, Eax
			Mov Eax, [Ebx].EDITPARENT.szFont.y
			Mov RSptCaret.y, Eax
		.EndIf
@@:		Pop Eax
		Invoke SelectObject, Edi, Eax
		Invoke ReleaseDC, [Esi].EDITCHILD.hWnd, Edi
		;Invoke RSFreeLineMemory
		Mov Eax, RSszText.x
		Mov Edi, Eax

		Add Eax, [Ebx].EDITPARENT.lSelBarWidth
		Add Eax, [Ebx].EDITPARENT.lCaretWidth
		Mov Edx, [Esi].EDITCHILD.rc.right
		Add Edx, [Ebx].EDITPARENT.lHScrollPos
		Cmp Eax, Edx
		Jg @F
		Mov Eax, Edi
		Cmp Eax, [Ebx].EDITPARENT.lHScrollPos
		Jg L4
		Sub Eax, [Ebx].EDITPARENT.lHScrollPos
		Jg L4
		Invoke RSScroll, 0, Eax
		Jmp L4
@@:		Cmp [Esi].EDITCHILD.rc.right, 0
		Jle L4
		Sub Eax, Edx
		Mov Ecx, [Ebx].EDITPARENT.szFont.x
		Shl Ecx, 3
		Add Eax, Ecx
		Invoke RSScroll, 0, Eax
L4:		Invoke RSUpdateScrollBars, (SCROLL_HORZ Or SCROLL_VERT)
		Mov Eax, [Esi].EDITCHILD.lLastCol
		Cmp lKey, VK_UP
		Je @F
		Cmp lKey, VK_DOWN
		Je @F
		Cmp lKey, VK_PRIOR
		Je @F
		Cmp lKey, VK_NEXT
		Je @F
		Mov Eax, [Esi].EDITCHILD.lRealCol
@@:		Mov [Esi].EDITCHILD.lLastCol, Eax
		Pop Edx
		.If Edx || [Esi].EDITCHILD.lPaint
			Invoke RSInvalidateEditor, [Esi].EDITCHILD.hWnd, TRUE
		.EndIf
		Cmp [Ebx].EDITPARENT.bHScrollChanged, FALSE
		Je @F
		Mov [Ebx].EDITPARENT.bHScrollChanged, FALSE
		Mov [Esi].EDITCHILD.lPaint, PAINT_LINE
		Jmp L1
@@:		Or Edx, Edx
		Je @F
		Mov Eax, [Ebx].EDITPARENT.dwEventMask
		And Eax, RSV_SELCHANGE
		Jz @F
		Invoke RSSendNotifyMessage, EN_SELCHANGE
	.EndIf
@@:	Ret
RSSetSelection EndP

;On enter Ebx = Pointer to editor parent's data
RSSetText Proc Private Uses Ecx Edx Edi Esi lpszSource:LPSTR, lpszDest:LPSTR, lTextLength:LONG
	Local bUTF8:BOOL, lLength:LONG
	Local lEdx:LONG

	Push [Ebx].EDITPARENT.dwEventMask
	Mov [Ebx].EDITPARENT.dwEventMask, 0
	Invoke RSDestroyMirror
	.If lTextLength == (-1)
		Invoke RSGetTextLength, lpszSource
		Invoke RSGetBytes, Eax
		Mov lTextLength, Eax
	.EndIf
	Xor Ecx, Ecx
	Xor Edx, Edx
	Mov lLength, Edx
	Mov lEdx, Edx
	Mov bUTF8, FALSE
	Mov Esi, lpszSource
	Mov Edi, lpszDest
	Cmp [Ebx].EDITPARENT.bTextUnicode, FALSE
	Jne SetTextW
L2:	.While (Ecx < SDWord Ptr lTextLength)
		Invoke RSAllocateMoreMemory, Edx
		.If Eax
			Mov Edi, [Ebx].EDITPARENT.lpTextPointer
		.EndIf
		Mov Al, Byte Ptr [Esi + Ecx]
		Inc Ecx
		.If Al == VK_RETURN
			Mov Al, LF
@@:			Mov Byte Ptr [Edi + Edx], VK_RETURN
			Inc Edx
			.If Byte Ptr [Esi + Ecx] == Al
				Inc Ecx
			.EndIf
			Mov Eax, Edx
			Sub Eax, lLength
			Invoke RSSetLineInfo, [Ebx].EDITPARENT.lLines, Eax
			Inc [Ebx].EDITPARENT.lLines
			Mov lLength, Edx
			Mov lEdx, Edx
			Inc [Ebx].EDITPARENT.lMaxIndex
		.ElseIf Al == LF
			Mov Al, VK_RETURN
			Jmp @B
		.Else
			.If (Al == VK_SPACE && [Ebx].EDITPARENT.bSpacesToTab)
				.If (Ecx < SDWord Ptr lTextLength && Byte Ptr [Esi + Ecx] == VK_SPACE)
					Call RSSpacesToTab
					Jc @F
					Add Ecx, Eax
					Dec Eax
					Add lEdx, Eax
					Mov Al, VK_TAB
					Jmp @F
				.EndIf
			.EndIf
			.If (Al == VK_TAB && [Ebx].EDITPARENT.bTabToSpaces)
				Invoke RSTabToSpaces, lLength
			.ElseIf Al
@@:				Mov [Edi + Edx], Al
				Inc Edx
				Inc lEdx
				Inc [Ebx].EDITPARENT.lMaxIndex
			.EndIf
		.EndIf
	.EndW
L4:	Mov Eax, Edx
	Mov Edx, [Ebx].EDITPARENT.lLines
	Shl Edx, 4
	Add Edx, [Ebx].EDITPARENT.lpLinesPointer
	Sub Eax, lLength
	Invoke RSGetChars, Eax
	Mov [Edx].LINE.lLength, Eax
	Cmp Eax, 1
	Jge @F
	Mov Eax, 1
@@:	Mov [Edx].LINE.lMaxLength, Eax
	Mov Ecx, [Ebx].EDITPARENT.lpszNextText
	Mov [Edx].LINE.lpszText, Ecx
	Mov Eax, [Edx].LINE.lLength
	Invoke RSGetBytes, Eax
	Add Eax, Ecx
	Mov Word Ptr [Eax], 0
	Invoke RSGetBytes, [Edx].LINE.lMaxLength
	Add Ecx, Eax
	Mov [Ebx].EDITPARENT.lpszNextText, Ecx
	Mov Word Ptr [Ecx], 0
	Pop [Ebx].EDITPARENT.dwEventMask
	Lea Esi, [Ebx].EDITPARENT.Editor
	Invoke RSSetCaret
	Invoke RSUpdateScrollBars, (SCROLL_HORZ Or SCROLL_VERT)
	Ret

SetTextW:
	Cmp [Ebx].EDITPARENT.bTextUnicodeUTF8, FALSE
	Jne SetTextUTF8
	.While (Ecx < SDWord Ptr lTextLength)
		Invoke RSAllocateMoreMemory, Edx
		.If Eax
			Mov Edi, [Ebx].EDITPARENT.lpTextPointer
		.EndIf
		Mov Ax, Word Ptr [Esi + Ecx]
		.If [Ebx].EDITPARENT.bBigEndian
			Xchg Ah, Al
		.EndIf
		Add Ecx, 2
		.If Ax == VK_RETURN
			Mov Ax, LF
@@:			.If [Ebx].EDITPARENT.bBigEndian
				Xchg Ah, Al
			.EndIf
			Mov Word Ptr [Edi + Edx], VK_RETURN
			Add Edx, 2
			.If (Word Ptr [Esi + Ecx] == Ax)
				Add Ecx, 2
			.EndIf
			Mov Eax, Edx
			Sub Eax, lLength
			Invoke RSSetLineInfo, [Ebx].EDITPARENT.lLines, Eax
			Inc [Ebx].EDITPARENT.lLines
			Mov lLength, Edx
			Mov lEdx, Edx
			Inc [Ebx].EDITPARENT.lMaxIndex
		.ElseIf Ax == LF
			Mov Ax, VK_RETURN
			Jmp @B
		.Else
			.If (Ax == VK_SPACE && [Ebx].EDITPARENT.bSpacesToTab)
				.If (Ecx < SDWord Ptr lTextLength && Word Ptr [Esi + Ecx] == VK_SPACE)
					Call RSSpacesToTab
					Jc @F
					Add Ecx, Eax
					Sub Eax, 2
					Add lEdx, Eax
					Mov Ax, VK_TAB
					Jmp @F
				.EndIf
			.EndIf
			.If (Ax == VK_TAB && [Ebx].EDITPARENT.bTabToSpaces)
				Invoke RSTabToSpaces, lLength
			.Else
@@:				Mov Word Ptr [Edi + Edx], Ax
				Add Edx, 2
				Add lEdx, 2
				Inc [Ebx].EDITPARENT.lMaxIndex
			.EndIf
		.EndIf
	.EndW
	Jmp L4

SetTextUTF8:
	Mov bUTF8, TRUE
	.While (Ecx < SDWord Ptr lTextLength)
		Invoke RSAllocateMoreMemory, Edx
		.If Eax
			Mov Edi, [Ebx].EDITPARENT.lpTextPointer
		.EndIf
		Xor Ah, Ah
		Mov Al, Byte Ptr [Esi + Ecx]
		Inc Ecx
		Cmp Al, 0C0H
		Jc @F
		Invoke RSCheckIfUTF8
@@:		.If Ax == VK_RETURN
			Mov Ax, LF
@@:			Mov Word Ptr [Edi + Edx], VK_RETURN
			Add Edx, 2
			.If (Byte Ptr [Esi + Ecx] == Al)
				Inc Ecx
			.EndIf
			Mov Eax, Edx
			Sub Eax, lLength
			Invoke RSSetLineInfo, [Ebx].EDITPARENT.lLines, Eax
			Inc [Ebx].EDITPARENT.lLines
			Mov lLength, Edx
			Mov lEdx, Edx
			Inc [Ebx].EDITPARENT.lMaxIndex
		.ElseIf Ax == LF
			Mov Ax, VK_RETURN
			Jmp @B
		.Else
			.If (Ax == VK_SPACE && [Ebx].EDITPARENT.bSpacesToTab)
				.If (Ecx < SDWord Ptr lTextLength && Byte Ptr [Esi + Ecx] == VK_SPACE)
					Call RSSpacesToTab
					Jc @F
					Add Ecx, Eax
					Shl Eax, 1
					Sub Eax, 2
					Add lEdx, Eax
					Mov Ax, VK_TAB
					Jmp @F
				.EndIf
			.EndIf
			.If (Ax == VK_TAB && [Ebx].EDITPARENT.bTabToSpaces)
				Invoke RSTabToSpaces, lLength
			.Else
@@:				Mov Word Ptr [Edi + Edx], Ax
				Add Edx, 2
				Add lEdx, 2
				Inc [Ebx].EDITPARENT.lMaxIndex
			.EndIf
		.EndIf
	.EndW
	Jmp L4

RSSpacesToTab:
	Push Edx
	Mov Eax, lEdx
	Sub Eax, lLength
	.If [Ebx].EDITPARENT.bTextUnicode
		Shr Eax, 1
	.EndIf
	Mov Edx, [Ebx].EDITPARENT.lTabSize
	Dec Edx
	And Eax, Edx
	Inc Edx
	Sub Edx, Eax
	.If bUTF8
		Push Edx
		Mov Eax, Edx
		Add Edx, Ecx
		Sub Edx, 2
		.While (Eax > SDWord Ptr 0)
			.If (Byte Ptr [Esi + Edx] != VK_SPACE)
				Pop Eax
				Mov Al, Byte Ptr [Esi + Ecx - 1]
				Stc
				Jmp @F
			.EndIf
			Dec Edx
			Dec Eax
		.EndW
		Dec Ecx
		Pop Eax
		Clc
	.ElseIf [Ebx].EDITPARENT.bTextUnicode
		Push Edx
		Mov Eax, Edx
		Shl Edx, 1
		Add Edx, Ecx
		Sub Edx, 4
		.While (Eax > SDWord Ptr 0)
			.If (Word Ptr [Esi + Edx] != VK_SPACE)
				Pop Eax
				Mov Ax, Word Ptr [Esi + Ecx - 2]
				Stc
				Jmp @F
			.EndIf
			Sub Edx, 2
			Dec Eax
		.EndW
		Sub Ecx, 2
		Pop Eax
		Shl Eax, 1
		Clc
	.Else
		Push Edx
		Mov Eax, Edx
		Add Edx, Ecx
		Sub Edx, 2
		.While (Eax > SDWord Ptr 0)
			.If (Byte Ptr [Esi + Edx] != VK_SPACE)
				Pop Eax
				Mov Al, Byte Ptr [Esi + Ecx - 1]
				Stc
				Jmp @F
			.EndIf
			Dec Edx
			Dec Eax
		.EndW
		Dec Ecx
		Pop Eax
		Clc
	.EndIf
@@:	Pop Edx
	Retn
RSSetText EndP

;On enter Esi = Pointer to editor child's data
RSSetTopLine Proc Private lLine:LONG, bRedraw:BOOL
	Push [Esi].EDITCHILD.lTopLine
	Mov [Esi].EDITCHILD.lTopLine, 0
	Mov [Esi].EDITCHILD.lTopLineIndex, 0
	Invoke RSScroll, lLine, 0
	Invoke RSUpdateScrollBars, SCROLL_VERT
	.If bRedraw
		Invoke RSInvalidateEditor, [Esi].EDITCHILD.hWnd, TRUE
	.EndIf
	Pop Eax
	Ret
RSSetTopLine EndP

;On enter Ebx = Pointer to editor parent's data
RSSetUCaseTable Proc Private Uses Ebx Ecx Edx Edi Esi
	Local lChars:LONG

	Xor Eax, Eax
	Mov Edi, Eax
	Cmp [Ebx].EDITPARENT.bTextUnicode, FALSE
	Jne SetUCaseTableW
	Xor Ebx, Ebx
	Mov lChars, 256
	Mov Esi, lpUCaseTableA
	.While (Edi < SDWord Ptr lChars)
		Mov Word Ptr [Esi + Edi], Bx
		Invoke IsCharAlpha, Ebx
		Or Eax, Eax
		Jz @F
		Invoke CharUpper, Ebx
		Mov Word Ptr [Esi + Edi], Ax
@@:		Inc Edi
		Inc Ebx
	.EndW
L2:	Ret

SetUCaseTableW:
	Xor Ebx, Ebx
	Mov lChars, (65536 * 2)
	Mov Esi, lpUCaseTableW
	.While (Edi < SDWord Ptr lChars)
		Mov Word Ptr [Esi + Edi], Bx
		Invoke IsCharAlphaW, Ebx
		Or Eax, Eax
		Jz @F
		Invoke CharUpperW, Ebx
		Mov Word Ptr [Esi + Edi], Ax
@@:		Add Edi, 2
		Inc Ebx
	.EndW
	Jmp L2
RSSetUCaseTable EndP

;On enter Ebx = Pointer to editor parent's data
RSShowMemoryError Proc Private
	Invoke GetLastError
	.If Eax == ERROR_NOT_ENOUGH_MEMORY
		Mov Eax, RSC_ERRORNOMEMORY
	.Else
		Mov Eax, RSC_ERRORMEMALLOC
	.EndIf
	Invoke RSSendMessage, [Ebx].EDITPARENT.hWndParent, RSM_SHOWMESSAGEBOX, Eax, 0
	Xor Eax, Eax
	Ret
RSShowMemoryError EndP

;On enter Ebx = Pointer to editor parent's data, Edi = Pointer to Text buffer, Edx = Offset inside Text buffer
RSTabToSpaces Proc Private Uses Ecx lLength:LONG
	Mov Eax, Edx
	Sub Eax, lLength
	.If [Ebx].EDITPARENT.bTextUnicode
		Shr Eax, 1
	.EndIf
	Mov Ecx, [Ebx].EDITPARENT.lTabSize
	Dec Ecx
	And Eax, Ecx
	Inc Ecx
	Sub Ecx, Eax
	.While Ecx
		.If [Ebx].EDITPARENT.bTextUnicode
			Mov Word Ptr [Edi + Edx], VK_SPACE
			Add Edx, 2
			Inc [Ebx].EDITPARENT.lMaxIndex
		.Else
			Mov Byte Ptr [Edi + Edx], VK_SPACE
			Inc Edx
			Inc [Ebx].EDITPARENT.lMaxIndex
		.EndIf
		Dec Ecx
	.EndW
	Ret
RSTabToSpaces EndP

;On enter Ebx = Pointer to editor parent's data
RSTextOut Proc Private hdc:HDC, nXStart:LONG, nYStart:LONG, lpString:LPCTSTR, cbString:LONG
	Push cbString
	Push lpString
	Push nYStart
	Push nXStart
	Push hdc
	.If [Ebx].EDITPARENT.bTextUnicode
		Mov Eax, TextOutW
	.Else
		Mov Eax, TextOutA
	.EndIf
	Call Eax
	Ret
RSTextOut EndP

;On enter Ebx = Pointer to editor parent's data
RSTextToClipboard Proc Private Uses Ecx Edi Esi lpszDest:LPLONG, lpszSource:LPLONG, lChars:LONG, bSaving:BOOL
	Cmp lChars, 0
	Jg @F
	Xor Eax, Eax
	Ret
@@:	Mov Esi, lpszSource
	Mov Edi, lpszDest
	Mov Ecx, lChars
	Cmp [Ebx].EDITPARENT.bTextUnicode, FALSE
	Jne TextToClipboardW
A2:	Mov Al, [Esi]
	Mov [Edi], Al
	Inc Esi
	Inc Edi
	Cmp Al, VK_RETURN
	Jne @F
	Mov Byte Ptr [Edi], LF
	Inc Edi
@@:	Dec Ecx
	Jnz A2
	Mov Eax, Edi
	Sub Eax, lpszDest
L2:	Ret

TextToClipboardW:
	Mov Ax, Word Ptr [Esi]
	.If (bSaving && [Ebx].EDITPARENT.bBigEndian)
		Xchg Ah, Al
	.EndIf
	Mov Word Ptr [Edi], Ax
	Add Esi, 2
	Add Edi, 2
	.If (bSaving && [Ebx].EDITPARENT.bBigEndian)
		Cmp Ax, CR_BE
		Jne @F
		Mov Ax, LF_BE
	.Else
		Cmp Ax, VK_RETURN
		Jne @F
		Mov Ax, LF
	.EndIf
	Mov Word Ptr [Edi], Ax
	Add Edi, 2
@@:	Dec Ecx
	Jnz TextToClipboardW
	Mov Eax, Edi
	Sub Eax, lpszDest
	Shr Eax, 1
	Jmp L2
RSTextToClipboard EndP

;On enter Esi = Pointer to editor child's data
RSToggleBookmark Proc Private hWnd:HWND, bRedraw:BOOL
	Mov Edx, [Esi].EDITCHILD.lCurLine
	Shl Edx, 4
	Add Edx, [Ebx].EDITPARENT.lpLinesPointer
	Xor DWord Ptr [Edx].LINE.lState, STATE_BOOKMARK
	.If bRedraw
		Mov [Esi].EDITCHILD.lPaint, PAINT_LINE
		Invoke RSInvalidateEditor, hWnd, TRUE
	.EndIf
	Ret
RSToggleBookmark EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to editor child's data
RSToggleLineStart Proc Private Uses Edx
	Mov Edx, [Esi].EDITCHILD.lCurLine
	Shl Edx, 4
	Add Edx, [Ebx].EDITPARENT.lpLinesPointer
	.If [Edx].LINE.lLength
		Invoke RSFindFirstValidChar, [Edx].LINE.lpszText
		Cmp Eax, [Esi].EDITCHILD.lCurCol
		Jne @F
	.EndIf
	Xor Eax, Eax
@@:	Ret
RSToggleLineStart EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to editor child's data
RSUndo Proc Private Uses Ecx Edx Edi
	Local bNoText:BOOL

	Xor Eax, Eax
	Mov Edx, [Ebx].EDITPARENT.lUndoCount
	Dec Edx
	Jl L4
	Shl Edx, 4
	Add Edx, [Ebx].EDITPARENT.lpUndoPointer
	.If DWord Ptr [Edx]
		Push [Ebx].EDITPARENT.dwEventMask
		Mov [Ebx].EDITPARENT.dwEventMask, 0
		Mov Edi, DWord Ptr [Edx]
		Invoke RSGetTextLength, Edi
		Inc Eax
		Invoke RSGetBytes, Eax
		Add Eax, Edi
		Invoke RSGetTextLength, Eax
		Mov Ecx, Eax
		Mov Eax, [Edx].EDITUNDO.chrPos.lMin
		.If Eax <= SDWord Ptr [Edx].EDITUNDO.chrPos.lMax
			Mov [Esi].EDITCHILD.chrPos.lMin, Eax
			Add Eax, Ecx
			Mov [Esi].EDITCHILD.chrPos.lMax, Eax
		.Else
			Mov Eax, [Edx].EDITUNDO.chrPos.lMax
			Mov [Esi].EDITCHILD.chrPos.lMin, Eax
			Add Eax, Ecx
			Mov [Esi].EDITCHILD.chrPos.lMax, Eax
		.EndIf
		Invoke RSCanDelete
		.If (!Eax)
			Mov Eax, [Esi].EDITCHILD.chrSel.lMin
			Mov Ecx, [Esi].EDITCHILD.chrSel.lMax
			Cmp Ecx, Eax
			Jge @F
			Xchg Eax, Ecx
@@:			Mov [Esi].EDITCHILD.chrPos.lMin, Eax
			Mov [Esi].EDITCHILD.chrPos.lMax, Ecx
			Pop [Ebx].EDITPARENT.dwEventMask
			Xor Eax, Eax
			Ret
		.EndIf
		Invoke RSReplaceSelection, Edi, (-1)
		.If (!Eax)
			Pop [Ebx].EDITPARENT.dwEventMask
			Ret
		.EndIf

		Mov bNoText, TRUE
		.If [Ebx].EDITPARENT.bTextUnicode
			.While (Word Ptr [Edi])
				.If (Word Ptr [Edi] > 32)
					Mov bNoText, FALSE
					.Break
				.EndIf
				Add Edi, 2
			.EndW
		.Else
			.While (Byte Ptr [Edi])
				.If (Byte Ptr [Edi] > 32)
					Mov bNoText, FALSE
					.Break
				.EndIf
				Inc Edi
			.EndW
		.EndIf
		Mov [Esi].EDITCHILD.lPaint, PAINT_ALL
		Mov Edi, [Edx].EDITUNDO.chrPos.lMin
		Mov Eax, [Edx].EDITUNDO.chrPos.lMax
		.If Eax > SDWord Ptr [Edx].EDITUNDO.chrPos.lMin
			Mov Ecx, [Edx].EDITUNDO.chrPos.lMax
			Sub Ecx, [Edx].EDITUNDO.chrPos.lMin
		.Else
			Mov Ecx, [Edx].EDITUNDO.chrPos.lMin
			Sub Ecx, [Edx].EDITUNDO.chrPos.lMax
		.EndIf
		.If (Ecx == 1 || bNoText)
			Mov Edi, Eax
		.EndIf
		Mov Ecx, Eax
		Dec [Ebx].EDITPARENT.lUndoCount
		Jge @F
		Mov [Ebx].EDITPARENT.lUndoCount, 0
@@:		Invoke RSGetLineFromChar, [Edx].EDITUNDO.chrPos.lMin
		Invoke RSIsLineInClientArea, Eax
		.If (!Eax)
			Invoke RSSetTopLine, [Edx].EDITUNDO.lTopLine, FALSE
		.EndIf
		Invoke RSCheckModified
		Pop [Ebx].EDITPARENT.dwEventMask
		Mov Eax, [Edx].EDITUNDO.chrPos.lMin
		.If Eax == [Edx].EDITUNDO.chrPos.lMax
			Mov Edi, Ecx
		.EndIf
		Invoke RSSetSelection, Edi, Ecx, 0
		Invoke RSCheckHorizontalPos
		Invoke RSSendCommandMessage, EN_CHANGE
		Mov Eax, TRUE
	.EndIf
L4:	Ret
RSUndo EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to active editor child's data
RSUnlockLines Proc Private lFirst:LONG, lLast:LONG
	Mov Ecx, lFirst
	Cmp Ecx, 0
	Jge @F
L2:	Xor Eax, Eax
	Ret
@@:	Cmp Ecx, SDWord Ptr [Ebx].EDITPARENT.lLines
	Jg L2
	Mov Eax, lLast
	Cmp Eax, Ecx
	Jl L2
	Cmp Eax, 0
	Jl L2
	Cmp Eax, SDWord Ptr [Ebx].EDITPARENT.lLines
	Jg L2
	Mov Edx, Ecx
	Shl Edx, 4
	Add Edx, [Ebx].EDITPARENT.lpLinesPointer
	.While Ecx <= SDWord Ptr lLast
		And [Edx].LINE.lState, (Not STATE_LOCKED)
		Inc Ecx
		Add Edx, SizeOf LINE
	.EndW
	Mov [Esi].EDITCHILD.lPaint, PAINT_ALL
	Invoke RSInvalidateEditor, [Esi].EDITCHILD.hWnd, TRUE ;FALSE
	Mov Eax, TRUE
	Ret
RSUnlockLines EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to editor child's data
RSUpdateScrollBars Proc Private Uses Ecx Edx ecBar:LONG
	.If (ecBar & SCROLL_HORZ)
		.If [Ebx].EDITPARENT.hWndHScroll != NULL
			Mov RSsci.fMask, SIF_ALL
			Mov Eax, [Ebx].EDITPARENT.lHScrollPos
			Mov RSsci.nPos, Eax
			Mov Eax, [Ebx].EDITPARENT.lHScrollPage
			Mov RSsci.nPage, Eax
			Mov RSsci.nMin, 0
			Mov Eax, [Ebx].EDITPARENT.lHScrollMax
			Mov RSsci.nMax, Eax
			.If (Eax >= SDWord Ptr [Ebx].EDITPARENT.lHScrollPage && SDWord Ptr [Ebx].EDITPARENT.lHScrollPage > 0)
				Invoke EnableWindow, [Ebx].EDITPARENT.hWndHScroll, TRUE
			.Else
				Or RSsci.fMask, SIF_DISABLENOSCROLL
			.EndIf
			Invoke SetScrollInfo, [Ebx].EDITPARENT.hWndHScroll, SB_CTL, Addr RSsci, TRUE
		.EndIf
	.EndIf
	.If (ecBar & SCROLL_VERT)
		.If [Esi].EDITCHILD.hWndVScroll != NULL
			Mov Eax, [Esi].EDITCHILD.lVScrollPage
			Cmp Eax, [Ebx].EDITPARENT.lLines
			Jle @F
			Mov [Esi].EDITCHILD.lTopLine, 0
			Mov [Esi].EDITCHILD.lTopLineIndex, 0
@@:			Mov RSsci.fMask, SIF_ALL
			Mov Eax, [Esi].EDITCHILD.lTopLine
			Mov RSsci.nPos, Eax
			Mov Eax, [Esi].EDITCHILD.lVScrollPage
			Mov RSsci.nPage, Eax
			Mov RSsci.nMin, 0
			Mov Eax, [Ebx].EDITPARENT.lLines
			Mov RSsci.nMax, Eax
			.If (Eax >= SDWord Ptr [Esi].EDITCHILD.lVScrollPage && SDWord Ptr [Esi].EDITCHILD.lVScrollPage > 0)
				Invoke EnableWindow, [Esi].EDITCHILD.hWndVScroll, TRUE
			.Else
				Or RSsci.fMask, SIF_DISABLENOSCROLL
			.EndIf
			Invoke SetScrollInfo, [Esi].EDITCHILD.hWndVScroll, SB_CTL, Addr RSsci, TRUE
		.EndIf
	.EndIf
	Ret
RSUpdateScrollBars EndP

;On enter Ebx = Pointer to editor parent's data, Esi = Pointer to active editor child's data
RSWatchScrollTimer Proc Private hWnd:HWND
	Local pt:POINTL

	Invoke RSSetScrollCounter, hWnd, Addr pt
	.If Eax
		.If [Ebx].EDITPARENT.uVScrollTimer == 0
			Mov Eax, hWnd
			Mov [Ebx].EDITPARENT.hWndTimer, Eax
			Invoke SetTimer, hWnd, 1, 10, NULL
			Mov [Ebx].EDITPARENT.uVScrollTimer, Eax
		.EndIf
	.Else
		Invoke RSKillScrollTimer
	.EndIf
	Ret
RSWatchScrollTimer EndP

End DllEntryPoint
