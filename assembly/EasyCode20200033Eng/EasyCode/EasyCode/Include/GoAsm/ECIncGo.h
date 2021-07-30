#IFDEF APP_WIN64
	#DEFINE				XWORD	DQ
	#DEFINE				LXWORD	8
#ELSE
	#DEFINE				XWORD	DD
	#DEFINE				LXWORD	4
#ENDIF

;===========================================================================
; Object type constants
;===========================================================================
ecDialogBox				Equ		1
ecMDIWindow				Equ		2
ecWindow				Equ		3
ecStatic				Equ		4
ecEdit					Equ		5
ecGroup					Equ		6
ecButton				Equ		7
ecCheck					Equ		8
ecRadio					Equ		9
ecList					Equ		10
ecCombo					Equ		11
ecPicture				Equ		12
ecImage					Equ		13
ecHScroll				Equ		14
ecVScroll				Equ		15
ecRichEdit				Equ		16
ecTreeView				Equ		17
ecListView				Equ		18
ecToolBar				Equ		19
ecStatusBar				Equ		20
ecProgressBar			Equ		21
ecSlider				Equ		22
ecTabStrip	 			Equ		23
ecUpDown				Equ		24
ecAnimate				Equ		25
ecIpAddress				Equ		26
ecImageCombo			Equ		27
ecCalendar				Equ		28
ecDateTime				Equ		29
ecHotKey				Equ		30
ecPager					Equ		31
ecImageList				Equ		32
ecHeader				Equ		33
ecRebar					Equ		34
ecThread				Equ		35
ecSysLink				Equ		36
ecUser					Equ		50


;===========================================================================
; Registry constants
;===========================================================================
ecClassesRoot			Equ		HKEY_CLASSES_ROOT
ecCurrentUser			Equ		HKEY_CURRENT_USER
ecLocalMachine			Equ		HKEY_LOCAL_MACHINE
ecUsers					Equ		HKEY_USERS
ecPerformanceData		Equ		HKEY_PERFORMANCE_DATA
ecCurrentConfig			Equ		HKEY_CURRENT_CONFIG
ecDynData				Equ		HKEY_DYN_DATA


;===========================================================================
; Scale mode constants
;===========================================================================
ecPixels				Equ		0
ecTwips					Equ		1


;===========================================================================
; Mouse cursor constants
;===========================================================================
ecDefault				Equ		0
ecArrow					Equ		1
ecIBeam					Equ		2
ecWait					Equ		3
ecCross					Equ		4
ecUpArrow				Equ		5
ecSizeAll				Equ		6
ecSizeNWSE				Equ		7
ecSizeNESW				Equ		8
ecSizeWE				Equ		9
ecSizeNS				Equ		10
ecNoDrop				Equ		11
ecAppStarting			Equ		12
ecHelp					Equ		13
ecCustom				Equ		14


;===========================================================================
; Drawing style constants
;===========================================================================
ecSolid					Equ		0
ecDash					Equ		1
ecDot					Equ		2
ecDashDot				Equ		3
ecDashDotDot			Equ		4
ecNull					Equ		5
ecInsideFrame			Equ		6


;===========================================================================
; Align constants
;===========================================================================
ecNone					Equ		0
ecAlignTop				Equ		1
ecAlignBottom			Equ		2
ecAlignLeft				Equ		3
ecAlignRight			Equ		4


;===========================================================================
; Scroll bars constants
;===========================================================================
ecNone					Equ		0
ecHorizontal			Equ		1
ecVertical				Equ		2
ecBoth					Equ		3


;===========================================================================
; Show mode constants
;===========================================================================
ecHidden				Equ		(-1)
ecNormal				Equ		0
ecMinimized				Equ		1
ecMaximized				Equ		2

;===========================================================================
; Mode constants
;===========================================================================
ecModeless				Equ		0
ecModal					Equ		1


;===========================================================================
; Center Window constants
;===========================================================================
ecLeft					Equ		0
ecCenter				Equ		1
ecRight					Equ		2


;===========================================================================
; OS System constants
;===========================================================================
ecWin95					Equ		1
ecWin98					Equ		2
ecWinME					Equ		2
ecWinNT					Equ		3
ecWin2K					Equ		4
ecWinXP					Equ		5
ecWinVista				Equ		6
ecWin7					Equ		7
ecWinSeven				Equ		7
ecWin8					Equ		8
ecWin81					Equ		9
ecWin10					Equ		10
ecWinSever2003			Equ		11
ecWinHomeServer			Equ		12
ecWinServer2008			Equ		13
ecWinServer2008R2		Equ		14
ecWinSever2012			Equ		15
ecWinSever2012R2		Equ		16
ecWinSever2016			Equ		17


;===========================================================================
; FindString method constants
;===========================================================================
ecMatchCase				Equ		1
ecWholeWord				Equ		2


;===========================================================================
; String method constants
;===========================================================================
ecBinary				Equ		0
ecDecimal				Equ		1
ecHexa					Equ		2
ecOctal					Equ		3


;===========================================================================
; Open text file constants
;===========================================================================
ecRead					Equ		GENERIC_READ
ecWrite					Equ		GENERIC_WRITE

ecCreateNew				Equ		CREATE_NEW
ecCreateAlways			Equ		CREATE_ALWAYS
ecOpenExisting			Equ		OPEN_EXISTING
ecOpenAlways			Equ		OPEN_ALWAYS
ecTruncateExisting		Equ		TRUNCATE_EXISTING


;===========================================================================
; Easy Code messages
;===========================================================================
ECM_LINKCLICKED			Equ		(WM_USER + 1030)
ECM_LINKPUSHED			Equ		ECM_LINKCLICKED
ECM_AFTERCREATE			Equ		(WM_USER + 1049)
ECM_REDRAWBACKGROUND	Equ		(WM_USER + 1054)
ECM_SOCK                Equ		(WM_USER + 1100)


;===========================================================================
; Object properties enumeration
;===========================================================================
p_Align					Equ		0 * LXWORD
p_AutoSize				Equ		1 * LXWORD
p_BackColor				Equ		2 * LXWORD
p_crBackColor			Equ		3 * LXWORD
p_Brush					Equ		4 * LXWORD
p_CaseStyle				Equ		5 * LXWORD
p_Center				Equ		6 * LXWORD
p_CursorIcon			Equ		7 * LXWORD
p_CursorShape			Equ		8 * LXWORD
p_DisableClose			Equ		9 * LXWORD
p_DrawingStyle			Equ		10 * LXWORD
p_DrawingWidth			Equ		11 * LXWORD
p_Enabled				Equ		12 * LXWORD
p_Focus					Equ		13 * LXWORD
p_Font					Equ		14 * LXWORD
p_FontBold				Equ		15 * LXWORD
p_FontItalic			Equ		16 * LXWORD
p_FontName				Equ		17 * LXWORD
p_FontSize				Equ		18 * LXWORD
p_FontStrikethru		Equ		19 * LXWORD
p_FontUnderline			Equ		20 * LXWORD
p_ForeColor				Equ		21 * LXWORD
p_crForeColor			Equ		22 * LXWORD
p_Height				Equ		23 * LXWORD
p_hWnd					Equ		24 * LXWORD
p_hWndClient			Equ		25 * LXWORD
p_IconBig				Equ		26 * LXWORD
p_IconSmall				Equ		27 * LXWORD
p_ImageHeight			Equ		28 * LXWORD
p_ImageType				Equ		29 * LXWORD
p_ImageWidth			Equ		30 * LXWORD
p_KeepSize				Equ		31 * LXWORD
p_Left					Equ		32 * LXWORD
p_Main					Equ		33 * LXWORD
p_MaxLength				Equ		34 * LXWORD
p_MDIChild				Equ		35 * LXWORD
p_Menu					Equ		36 * LXWORD
p_Name					Equ		37 * LXWORD
p_NoPrefix				Equ		38 * LXWORD
p_Offset				Equ		39 * LXWORD
p_Parent				Equ		40 * LXWORD
p_PasswordChar			Equ		41 * LXWORD
p_Pen					Equ		42 * LXWORD
p_Picture				Equ		43 * LXWORD
p_RightToLeft			Equ		44 * LXWORD
p_ScaleMode				Equ		45 * LXWORD
p_ScrollBars			Equ		46 * LXWORD
p_ShowMode				Equ		47 * LXWORD
p_Stretch				Equ		48 * LXWORD
p_TabOrder				Equ		49 * LXWORD
p_TabStop				Equ		50 * LXWORD
p_Text					Equ		51 * LXWORD
p_TextAlignment			Equ		52 * LXWORD
p_TextLength			Equ		53 * LXWORD
p_Timer					Equ		54 * LXWORD
p_TimerID				Equ		55 * LXWORD
p_Top					Equ		56 * LXWORD
p_Transparent			Equ		57 * LXWORD
p_Type					Equ		58 * LXWORD
p_Value					Equ		59 * LXWORD
p_Visible				Equ		60 * LXWORD
p_Width					Equ		61 * LXWORD
p_WindowProc			Equ		62 * LXWORD
p_WndOldControlProc		Equ		63 * LXWORD
p_DialogID				Equ		64 * LXWORD
p_Children				Equ		65 * LXWORD
p_DefButton				Equ		66 * LXWORD
p_ExStyle				Equ		67 * LXWORD
p_Style					Equ		68 * LXWORD
p_ButtonStruct			Equ		69 * LXWORD
p_OldFont				Equ		70 * LXWORD
p_ToolTip				Equ		71 * LXWORD
p_MouseLeave			Equ		72 * LXWORD
p_PropertyCount			Equ		73 * LXWORD

p_Alignment				Equ		p_AutoSize
p_AlignMode				Equ		p_Transparent
p_AutoRedraw			Equ		p_PasswordChar
p_BandCount				Equ		p_DrawingStyle
p_BandStruct			Equ		p_ButtonStruct
p_Border				Equ		p_CaseStyle
p_ButtonCount			Equ		p_DrawingStyle
p_ButtonHeight			Equ		p_CaseStyle
p_ButtonSize			Equ		p_Center
p_ButtonWidth			Equ		p_Center
p_Cancel				Equ		p_AutoSize
p_ChildOffset			Equ		p_OldFont
p_ColorQuality			Equ		p_TextAlignment
p_CurrentX				Equ		p_NoPrefix
p_CurrentY				Equ		p_Offset
p_Default				Equ		p_DisableClose
p_DisableNoScroll		Equ		p_DisableClose
p_DrawFlags				Equ		p_Value
p_DrawFocus				Equ		p_Transparent
p_FlickerFree			Equ		p_DisableClose
p_GripperCursor			Equ		p_NoPrefix
p_HideSelection			Equ		p_AutoSize
p_HitTest				Equ		p_Offset
p_HyperColor			Equ		p_ScrollBars
p_HyperLink				Equ		p_MaxLength
p_ImageCount			Equ		p_Transparent
p_ImageList				Equ		p_DrawingStyle
p_ImageStruct			Equ		p_ButtonStruct
p_Indentation			Equ		p_CaseStyle
p_ItemCount				Equ		p_DrawingStyle
p_ItemStruct			Equ		p_ButtonStruct
p_KeyPreview			Equ		p_NoPrefix
p_LvwExStyle			Equ		p_TextAlignment
p_MaxValue				Equ		p_ScrollBars
p_MinValue				Equ		p_ShowMode
p_Modal					Equ		p_Stretch
p_MultiLine				Equ		p_NoPrefix
p_NormalStyle			Equ		p_Style
p_OwnerDraw				Equ		p_DrawingStyle
p_PageSize				Equ		p_TextAlignment
p_PannelCount			Equ		p_DrawingStyle
p_PannelStruct			Equ		p_ButtonStruct
p_PicturePosition		Equ		p_MaxLength
p_SelStart				Equ		p_Offset
p_SelEnd				Equ		p_Stretch
p_TabCount				Equ		p_DrawingStyle
p_TabStruct				Equ		p_ButtonStruct
p_TickFrequency			Equ		p_Transparent
p_ToolTipText			Equ		p_ToolTip
p_VisibleRows			Equ		p_MaxLength


;===========================================================================
; Error Object struct
;===========================================================================
ECErrorStruct Struct
	#IFDEF APP_WIN64
		regRsp		DQ	  ?
		regRbp		DQ	  ?
		regRip		DQ	  ?
	#ELSE
		regEsp		DD	  ?
		regEbp		DD	  ?
		regEip		DD	  ?
	#ENDIF
	lCode			XWORD ?
	Description		XWORD ?
EndS


;===========================================================================
; App Object struct
;===========================================================================
ECApplication Struct
	Accel		XWORD ?
	CommandLine	XWORD ?
	FileName	XWORD ?
	Header		XWORD ?
	Instance	XWORD ?
	Main		XWORD ?
	Major		XWORD ?
	Minor		XWORD ?
	Previous	XWORD ?
	Revision	XWORD ?
	Path		XWORD ?
	ProcessID	XWORD ?
	ThreadID	XWORD ?
EndS


;===========================================================================
; StatusBar Object struct
;===========================================================================
STBPANNEL Struct
	nWidth		DD	  ?
	nBevel		DD	  ?
	lpszText	XWORD ?
EndS


;===========================================================================
; ImageList Object struct
;===========================================================================
IMAGESTRUCT Struct
	lType		XWORD ?
	lpszResID	XWORD ?
EndS


;===========================================================================
; Header Object struct
;===========================================================================
ITEMSTRUCT Struct
	iImage		XWORD ?
	nWidth		XWORD ?
	lTextAlign	XWORD ?
	lpszText	XWORD ?
EndS


;===========================================================================
; Rebar Object struct
;===========================================================================
BANDSTRUCT Struct
	lHeader		XWORD ?
	lLength		XWORD ?
	lMinHeight	XWORD ?
	lMinWidth	XWORD ?
	dwStyle		XWORD ?
	hBitmap		XWORD ?
	hWndChild	XWORD ?
	lpszBitmap	XWORD ?
	lpszChild	XWORD ?
	lpszText	XWORD ?
EndS


;===========================================================================
; CPU Info struct
;===========================================================================
CPUINFO Struct
	Description  DB	   32 Dup ?
	Stepping     XWORD 0
	Family       XWORD 0
	Model        XWORD 0
	CPUType      XWORD 0
	ModelID      XWORD 0
	FeaturesID   XWORD 0
	ExFeaturesID XWORD 0
EndS
