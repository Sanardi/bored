;===========================================================================
; RSEditor constants
;===========================================================================

GWL_EDITORDATA			Equ		0

ECC_WIN95 				Equ   	1
ECC_WIN98 				Equ   	2
ECC_WINME 				Equ   	2
ECC_WINNT 				Equ   	3
ECC_WIN2K 				Equ   	4
ECC_WINXP 				Equ   	5
ECC_WINVISTA 			Equ   	6
ECC_WIN7 				Equ   	7
ECC_WINSEVEN 			Equ   	7


;===========================================================================
; RSEditor structures
;===========================================================================

LINE Struct
	lpszText			LPLONG 		?
	lLength 			LONG 		?
	lMaxLength			LONG		?
	lState				LONG		?
LINE EndS

EDITCHILD Struct
	hWnd				HWND		?
	hWndVScroll			HWND		?
	bNoSelection		BOOL		?
	lCurCol				LONG		?
	lCurLine			LONG		?
	lLastCol			LONG		?
	lPaint				LONG		?
	lRealCol			LONG		?
	lSelStart			LONG		?
	lTopLine			LONG		?
	lTopLineIndex		LONG		?
	lVScrollPage		LONG		?
	rc					RECT		<?>
	chrPos				RSSCHARSEL 	<?>
	chrSel				RSSCHARSEL 	<?>
EDITCHILD EndS

EDITPARENT Struct
	hWnd				HWND		?
	hWndParent			HWND		?
	hWndFind			HWND		?
	Editor				EDITCHILD	<?>
	Mirror				EDITCHILD	<?>
	hWndFocus			HWND		?
	hWndGrip			HWND		?
	hWndHScroll			HWND		?
	hWndNoGrip			HWND		?
	hWndSplitter		HWND		?
	hWndTimer			HWND		?
	bAutoIndent			BOOL		?
	bBigEndian			BOOL		?
	bCaret				BOOL		?
	bChangeEvent		BOOL		?
	bHideGrip			BOOL		?
	bHideSelection		BOOL		?
	bHScrollChanged		BOOL		?
	bInsert				BOOL		?
	bModified			BOOL		?
	bReadOnly			BOOL		?
	bRedraw				BOOL		?
	bSpacesToTab		BOOL		?
	bTabToSpaces		BOOL		?
	bTextUnicode		BOOL		?
	bTextUnicodeUTF8	BOOL		?
	bWriteBom			BOOL		?
	lCaretWidth			LONG		?
	lCtrlID				LONG		?
	lHScrollMax			LONG		?
	lHScrollPage		LONG		?
	lHScrollPos			LONG		?
	lLastUndoCount		LONG		?
	lLines				LONG		?
	lMaxIndex			LONG		?
	lMaxLines			LONG		?
	lMaxTextLength		LONG		?
	lMaxUndo			LONG		?
	lMouseWheelUnits	LONG		?
	lSelBarWidth		LONG		?
	lVScrollCounter		LONG		?
	uVScrollTimer		UINT		?
	lTabSize			LONG		?
	lUndoCount			LONG		?
	dwEventMask			DWord		?
	hHeap				HANDLE		?
	lpszBuffer			LPSTR		?
	lpszLine			LPSTR		?
	lpszNextText		LPSTR		?
	lpLinesPointer		LPLONG		?
	lpTextPointer		LPLONG		?
	lpUndoPointer		LPLONG		?
	RSIsAlphaProcAddr	WNDPROC		?
	hFont				HFONT		?
	hBackBrush			HBRUSH		?
	hLockedBrush		HBRUSH		?
	hMarginBrush		HBRUSH		?
	hSelectBrush		HBRUSH		?
	hMem				HDC			?
	hBitmap				HBITMAP		?
	rc					RECT		<?>
	szFont				SIZEL		<?>
	crBackColor			COLORREF	?
	crTextColor 		COLORREF	?
	crBackSelect 		COLORREF	?
	crTextSelect 		COLORREF	?
	crBackMargin		COLORREF	?
	crBackLocked		COLORREF	?
	crTextLocked		COLORREF	?
EDITPARENT EndS

EDITUNDO Struct
	lpszText			LPSTR		?
	lTopLine			LONG		?
	chrPos				RSSCHARSEL	<?>
EDITUNDO EndS
