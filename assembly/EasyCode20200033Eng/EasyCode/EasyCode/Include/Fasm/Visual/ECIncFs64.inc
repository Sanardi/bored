;===========================================================================
; Object type constants
;===========================================================================
ecDialogBox				= 1
ecMDIWindow				= 2
ecWindow				= 3
ecStatic				= 4
ecEdit					= 5
ecGroup					= 6
ecButton				= 7
ecCheck					= 8
ecRadio					= 9
ecList					= 10
ecCombo					= 11
ecPicture				= 12
ecImage					= 13
ecHScroll				= 14
ecVScroll				= 15
ecRichEdit				= 16
ecTreeView				= 17
ecListView				= 18
ecToolBar				= 19
ecStatusBar				= 20
ecProgressBar			= 21
ecSlider				= 22
ecTabStrip	 			= 23
ecUpDown				= 24
ecAnimate				= 25
ecIpAddress				= 26
ecImageCombo			= 27
ecCalendar				= 28
ecDateTime				= 29
ecHotKey				= 30
ecPager					= 31
ecImageList				= 32
ecHeader				= 33
ecRebar					= 34
ecThread				= 35
ecSysLink				= 36
ecUser					= 50


;===========================================================================
; Registry constants
;===========================================================================
ecClassesRoot			= HKEY_CLASSES_ROOT
ecCurrentUser			= HKEY_CURRENT_USER
ecLocalMachine			= HKEY_LOCAL_MACHINE
ecUsers					= HKEY_USERS
ecPerformanceData		= HKEY_PERFORMANCE_DATA
ecCurrentConfig			= HKEY_CURRENT_CONFIG
ecDynData				= HKEY_DYN_DATA


;===========================================================================
; Scale mode constants
;===========================================================================
ecPixels				= 0
ecTwips					= 1


;===========================================================================
; Mouse cursor constants
;===========================================================================
ecDefault				= 0
ecArrow					= 1
ecIBeam					= 2
ecWait					= 3
ecCross					= 4
ecUpArrow				= 5
ecSizeAll				= 6
ecSizeNWSE				= 7
ecSizeNESW				= 8
ecSizeWE				= 9
ecSizeNS				= 10
ecNoDrop				= 11
ecAppStarting			= 12
ecHelp					= 13
ecCustom				= 14


;===========================================================================
; Drawing style constants
;===========================================================================
ecSolid					= 0
ecDash					= 1
ecDot					= 2
ecDashDot				= 3
ecDashDotDot			= 4
ecNull					= 5
ecInsideFrame			= 6


;===========================================================================
; Align constants
;===========================================================================
ecNone					= 0
ecAlignTop				= 1
ecAlignBottom			= 2
ecAlignLeft				= 3
ecAlignRight			= 4


;===========================================================================
; Scroll bars constants
;===========================================================================
ecNone					= 0
ecHorizontal			= 1
ecVertical				= 2
ecBoth					= 3


;===========================================================================
; Show mode constants
;===========================================================================
ecHidden				= (-1)
ecNormal				= 0
ecMinimized				= 1
ecMaximized				= 2

;===========================================================================
; Mode constants
;===========================================================================
ecModeless				= 0
ecModal					= 1


;===========================================================================
; Center Window constants
;===========================================================================
ecLeft					= 0
ecCenter				= 1
ecRight					= 2


;===========================================================================
; OS System constants
;===========================================================================
ecWin95					= 1
ecWin98					= 2
ecWinME					= 2
ecWinNT					= 3
ecWin2K					= 4
ecWinXP					= 5
ecWinVista				= 6
ecWin7					= 7
ecWinSeven				= 7
ecWin8					= 8
ecWin81					= 9
ecWin10					= 10
ecWinSever2003			= 11
ecWinHomeServer			= 12
ecWinServer2008			= 13
ecWinServer2008R2		= 14
ecWinSever2012			= 15
ecWinSever2012R2		= 16
ecWinSever2016			= 17


;===========================================================================
; FindString method constants
;===========================================================================
ecMatchCase				= 1
ecWholeWord				= 2


;===========================================================================
; String method constants
;===========================================================================
ecBinary				= 0
ecDecimal				= 1
ecHexa					= 2
ecOctal					= 3


;===========================================================================
; Open text file constants
;===========================================================================
ecRead					= GENERIC_READ
ecWrite					= GENERIC_WRITE

ecCreateNew				= CREATE_NEW
ecCreateAlways			= CREATE_ALWAYS
ecOpenExisting			= OPEN_EXISTING
ecOpenAlways			= OPEN_ALWAYS
ecTruncateExisting		= TRUNCATE_EXISTING


;===========================================================================
; Easy Code messages
;===========================================================================
ECM_LINKCLICKED			= (WM_USER + 1030)
ECM_LINKPUSHED			= ECM_LINKCLICKED
ECM_AFTERCREATE			= (WM_USER + 1049)
ECM_REDRAWBACKGROUND	= (WM_USER + 1054)
ECM_SOCK                = (WM_USER + 1100)


;===========================================================================
; Object properties enumeration
;===========================================================================
p_Align					= 0
p_AutoSize				= 1 * 8
p_BackColor				= 2 * 8
p_crBackColor			= 3 * 8
p_Brush					= 4 * 8
p_CaseStyle				= 5 * 8
p_Center				= 6 * 8
p_CursorIcon			= 7 * 8
p_CursorShape			= 8 * 8
p_DisableClose			= 9 * 8
p_DrawingStyle			= 10 * 8
p_DrawingWidth			= 11 * 8
p_Enabled				= 12 * 8
p_Focus					= 13 * 8
p_Font					= 14 * 8
p_FontBold				= 15 * 8
p_FontItalic			= 16 * 8
p_FontName				= 17 * 8
p_FontSize				= 18 * 8
p_FontStrikethru		= 19 * 8
p_FontUnderline			= 20 * 8
p_ForeColor				= 21 * 8
p_crForeColor			= 22 * 8
p_Height				= 23 * 8
p_hWnd					= 24 * 8
p_hWndClient			= 25 * 8
p_IconBig				= 26 * 8
p_IconSmall				= 27 * 8
p_ImageHeight			= 28 * 8
p_ImageType				= 29 * 8
p_ImageWidth			= 30 * 8
p_KeepSize				= 31 * 8
p_Left					= 32 * 8
p_Main					= 33 * 8
p_MaxLength				= 34 * 8
p_MDIChild				= 35 * 8
p_Menu					= 36 * 8
p_Name					= 37 * 8
p_NoPrefix				= 38 * 8
p_Offset				= 39 * 8
p_Parent				= 40 * 8
p_PasswordChar			= 41 * 8
p_Pen					= 42 * 8
p_Picture				= 43 * 8
p_RightToLeft			= 44 * 8
p_ScaleMode				= 45 * 8
p_ScrollBars			= 46 * 8
p_ShowMode				= 47 * 8
p_Stretch				= 48 * 8
p_TabOrder				= 49 * 8
p_TabStop				= 50 * 8
p_Text					= 51 * 8
p_TextAlignment			= 52 * 8
p_TextLength			= 53 * 8
p_Timer					= 54 * 8
p_TimerID				= 55 * 8
p_Top					= 56 * 8
p_Transparent			= 57 * 8
p_Type					= 58 * 8
p_Value					= 59 * 8
p_Visible				= 60 * 8
p_Width					= 61 * 8
p_WindowProc			= 62 * 8
p_WndOldControlProc		= 63 * 8
p_DialogID				= 64 * 8
p_Children				= 65 * 8
p_DefButton				= 66 * 8
p_ExStyle				= 67 * 8
p_Style					= 68 * 8
p_ButtonStruct			= 69 * 8
p_OldFont				= 70 * 8
p_ToolTip				= 71 * 8
p_MouseLeave			= 72 * 8
p_PropertyCount			= 73 * 8

p_Alignment				= p_AutoSize
p_AlignMode				= p_Transparent
p_AutoRedraw			= p_PasswordChar
p_BandCount				= p_DrawingStyle
p_BandStruct			= p_ButtonStruct
p_Border				= p_CaseStyle
p_ButtonCount			= p_DrawingStyle
p_ButtonHeight			= p_CaseStyle
p_ButtonSize			= p_Center
p_ButtonWidth			= p_Center
p_Cancel				= p_AutoSize
p_ChildOffset			= p_OldFont
p_ColorQuality			= p_TextAlignment
p_CurrentX				= p_NoPrefix
p_CurrentY				= p_Offset
p_Default				= p_DisableClose
p_DisableNoScroll		= p_DisableClose
p_DrawFlags				= p_Value
p_DrawFocus				= p_Transparent
p_FlickerFree			= p_DisableClose
p_GripperCursor			= p_NoPrefix
p_HideSelection			= p_AutoSize
p_HitTest				= p_Offset
p_HyperColor			= p_ScrollBars
p_HyperLink				= p_MaxLength
p_ImageCount			= p_Transparent
p_ImageList				= p_DrawingStyle
p_ImageStruct			= p_ButtonStruct
p_Indentation			= p_CaseStyle
p_ItemCount				= p_DrawingStyle
p_ItemStruct			= p_ButtonStruct
p_KeyPreview			= p_NoPrefix
p_LvwExStyle			= p_TextAlignment
p_MaxValue				= p_ScrollBars
p_MinValue				= p_ShowMode
p_Modal					= p_Stretch
p_MultiLine				= p_NoPrefix
p_NormalStyle			= p_Style
p_OwnerDraw				= p_DrawingStyle
p_PageSize				= p_TextAlignment
p_PannelCount			= p_DrawingStyle
p_PannelStruct			= p_ButtonStruct
p_PicturePosition		= p_MaxLength
p_SelStart				= p_Offset
p_SelEnd				= p_Stretch
p_TabCount				= p_DrawingStyle
p_TabStruct				= p_ButtonStruct
p_TickFrequency			= p_Transparent
p_ToolTipText			= p_ToolTip
p_VisibleRows			= p_MaxLength


;===========================================================================
; Error Object struct
;===========================================================================
struct ECErrorStruct
	regRsp		dq		?
	regRbp		dq		?
	regRip		dq		?
	lCode		dq		?
	Description	dq		?
ends


;===========================================================================
; App Object struct
;===========================================================================
struct ECApplication
	Accel		dq		?
	CommandLine	dq		?
	FileName	dq		?
	Header		dq		?
	Instance	dq		?
	Main		dq		?
	Major		dq		?
	Minor		dq		?
	Previous	dq		?
	Revision	dq		?
	Path		dq		?
	ProcessID	dq		?
	ThreadID	dq		?
ends


;===========================================================================
; StatusBar Object struct
;===========================================================================
struct STBPANNEL
	nWidth		dd		?
	nBevel		dd		?
	lpszText	dq		?
ends


;===========================================================================
; ImageList Object struct
;===========================================================================
struct IMAGESTRUCT
	lType		dq		?
	lpszResID	dq		?
ends


;===========================================================================
; Header Object struct
;===========================================================================
struct ITEMSTRUCT
	iImage		dq		?
	nWidth		dq		?
	lTextAlign	dq		?
	lpszText	dq		?
ends


;===========================================================================
; Rebar Object struct
;===========================================================================
struct BANDSTRUCT
	lHeader		dq		?
	lLength		dq		?
	lMinHeight	dq		?
	lMinWidth	dq		?
	dwStyle		dq		?
	hBitmap		dq		?
	hWndChild	dq		?
	lpszBitmap	dq		?
	lpszChild	dq		?
	lpszText	dq		?
ends


;===========================================================================
; CPU Info struct
;===========================================================================
struct CPUINFO
	Description  db 32 dup(?)
	Stepping     dq ?
	Family       dq ?
	Model        dq ?
	CPUType      dq ?
	ModelID      dq ?
	FeaturesID   dq ?
	ExFeaturesID dq ?
ends

;===========================================================================
; Get properties
;===========================================================================
extrn 'GetAlign' as GetAlign:qword
extrn 'GetAutoSize' as GetAutoSize:qword
extrn 'GetBackColor' as GetBackColor:qword
extrn 'GetCancel' as GetCancel:qword
extrn 'GetCaseStyle' as GetCaseStyle:qword
extrn 'GetCursorIcon' as GetCursorIcon:qword
extrn 'GetCursorShape' as GetCursorShape:qword
extrn 'GetDefault' as GetDefault:qword
extrn 'GetDrawFocus' as GetDrawFocus:qword
extrn 'GetDrawingStyle' as GetDrawingStyle:qword
extrn 'GetDrawingWidth' as GetDrawingWidth:qword
extrn 'GetEnabled' as GetEnabled:qword
extrn 'GetFlickerFree' as GetFlickerFree:qword
extrn 'GetFont' as GetFont:qword
extrn 'GetFontBold' as GetFontBold:qword
extrn 'GetFontItalic' as GetFontItalic:qword
extrn 'GetFontName' as GetFontName:qword
extrn 'GetFontNameA' as GetFontNameA:qword
extrn 'GetFontNameW' as GetFontNameW:qword
extrn 'GetFontSize' as GetFontSize:qword
extrn 'GetFontStrikethru' as GetFontStrikethru:qword
extrn 'GetFontUnderline' as GetFontUnderline:qword
extrn 'GetForeColor' as GetForeColor:qword
extrn 'GetHeight' as GetHeight:qword
extrn 'GetIconBig' as GetIconBig:qword
extrn 'GetIconSmall' as GetIconSmall:qword
extrn 'GetLayoutRTL' as GetLayoutRTL:qword
extrn 'GetLeft' as GetLeft:qword
extrn 'GetMaxValue' as GetMaxValue:qword
extrn 'GetMaxLength' as GetMaxLength:qword
extrn 'GetMDIChild' as GetMDIChild:qword
extrn 'GetMinValue' as GetMinValue:qword
extrn 'GetMultiLine' as GetMultiLine:qword
extrn 'GetName' as GetName:qword
extrn 'GetNameA' as GetNameA:qword
extrn 'GetNameW' as GetNameW:qword
extrn 'GetNoPrefix' as GetNoPrefix:qword
extrn 'GetPageSize' as GetPageSize:qword
extrn 'GetPasswordChar' as GetPasswordChar:qword
extrn 'GetPicture' as GetPicture:qword
extrn 'GetPicturePosition' as GetPicturePosition:qword
extrn 'GetRightToLeft' as GetRightToLeft:qword
extrn 'GetScaleMode' as GetScaleMode:qword
extrn 'GetScrollBars' as GetScrollBars:qword
extrn 'GetShowMode' as GetShowMode:qword
extrn 'GetStretch' as GetStretch:qword
extrn 'GetTabOrder' as GetTabOrder:qword
extrn 'GetTabStop' as GetTabStop:qword
extrn 'GetText' as GetText:qword
extrn 'GetTextA' as GetTextA:qword
extrn 'GetTextW' as GetTextW:qword
extrn 'GetTextAlignment' as GetTextAlignment:qword
extrn 'GetTimerInterval' as GetTimerInterval:qword
extrn 'GetTop' as GetTop:qword
extrn 'GetType' as GetType:qword
extrn 'GetValue' as GetValue:qword
extrn 'GetVisible' as GetVisible:qword
extrn 'GetVisibleRows' as GetVisibleRows:qword
extrn 'GetWidth' as GetWidth:qword

;===========================================================================
; Set properties
;===========================================================================
extrn 'SetAlign' as SetAlign:qword
extrn 'SetAutoSize' as SetAutoSize:qword
extrn 'SetBackColor' as SetBackColor:qword
extrn 'SetCursorIcon' as SetCursorIcon:qword
extrn 'SetCursorShape' as SetCursorShape:qword
extrn 'SetDefault' as SetDefault:qword
extrn 'SetDrawFocus' as SetDrawFocus:qword
extrn 'SetDrawingStyle' as SetDrawingStyle:qword
extrn 'SetDrawingWidth' as SetDrawingWidth:qword
extrn 'SetEnabled' as SetEnabled:qword
extrn 'SetFlickerFree' as SetFlickerFree:qword
extrn 'SetFontBold' as SetFontBold:qword
extrn 'SetFontItalic' as SetFontItalic:qword
extrn 'SetFontName' as SetFontName:qword
extrn 'SetFontNameA' as SetFontNameA:qword
extrn 'SetFontNameW' as SetFontNameW:qword
extrn 'SetFontSize' as SetFontSize:qword
extrn 'SetFontStrikethru' as SetFontStrikethru:qword
extrn 'SetFontUnderline' as SetFontUnderline:qword
extrn 'SetForeColor' as SetForeColor:qword
extrn 'SetHeight' as SetHeight:qword
extrn 'SetIconBig' as SetIconBig:qword
extrn 'SetIconSmall' as SetIconSmall:qword
extrn 'SetLayoutRTL' as SetLayoutRTL:qword
extrn 'SetLeft' as SetLeft:qword
extrn 'SetMarquee' as SetMarquee:qword
extrn 'SetMaxValue' as SetMaxValue:qword
extrn 'SetMaxLength' as SetMaxLength:qword
extrn 'SetMinValue' as SetMinValue:qword
extrn 'SetPageSize' as SetPageSize:qword
extrn 'SetPasswordChar' as SetPasswordChar:qword
extrn 'SetPicture' as SetPicture:qword
extrn 'SetPicturePosition' as SetPicturePosition:qword
extrn 'SetRightToLeft' as SetRightToLeft:qword
extrn 'SetScrollBars' as SetScrollBars:qword
extrn 'SetShowMode' as SetShowMode:qword
extrn 'SetTabStop' as SetTabStop:qword
extrn 'SetText' as SetText:qword
extrn 'SetTextA' as SetTextA:qword
extrn 'SetTextW' as SetTextW:qword
extrn 'SetTimerInterval' as SetTimerInterval:qword
extrn 'SetTop' as SetTop:qword
extrn 'SetValue' as SetValue:qword
extrn 'SetVisible' as SetVisible:qword
extrn 'SetVisibleRows' as SetVisibleRows:qword
extrn 'SetWidth' as SetWidth:qword


;===========================================================================
; Easy Code Methods
;===========================================================================
extrn 'AddCharToString' as AddCharToString:qword
extrn 'AddCharToStringA' as AddCharToStringA:qword
extrn 'AddCharToStringW' as AddCharToStringW:qword
extrn 'AddCollectionItem' as AddCollectionItem:qword
extrn 'AddCollectionItemA' as AddCollectionItemA:qword
extrn 'AddCollectionItemW' as AddCollectionItemW:qword
extrn 'CallDefaultProc' as CallDefaultProc:qword
extrn 'Circle' as Circle:qword
extrn 'Create' as Create:qword
extrn 'CreateCollection' as CreateCollection:qword
extrn 'CreateCollectionA' as CreateCollectionA:qword
extrn 'CreateCollectionW' as CreateCollectionW:qword
extrn 'DeleteRegistryKey' as DeleteRegistryKey:qword
extrn 'DeleteRegistryKeyA' as DeleteRegistryKeyA:qword
extrn 'DeleteRegistryKeyW' as DeleteRegistryKeyW:qword
extrn 'DeleteRegistryValue' as DeleteRegistryValue:qword
extrn 'DeleteRegistryValueA' as DeleteRegistryValueA:qword
extrn 'DeleteRegistryValueW' as DeleteRegistryValueW:qword
extrn 'DestroyCollection' as DestroyCollection:qword
extrn 'DoEvents' as DoEvents:qword
extrn 'EmptyCollection' as EmptyCollection:qword
extrn 'EndModal' as EndModal:qword
extrn 'Eof' as Eof:qword
extrn 'FileExists' as FileExists:qword
extrn 'FileExistsA' as FileExistsA:qword
extrn 'FileExistsW' as FileExistsW:qword
extrn 'FillMemoryBlock' as FillMemoryBlock:qword
extrn 'FindChar' as FindChar:qword
extrn 'FindChar' as FindChar:qword
extrn 'FindCharA' as FindCharA:qword
extrn 'FindCharW' as FindCharW:qword
extrn 'FindCharRev' as FindCharRev:qword
extrn 'FindCharRevA' as FindCharRevA:qword
extrn 'FindCharRevW' as FindCharRevW:qword
extrn 'FindCollectionExactItem' as FindCollectionExactItem:qword
extrn 'FindCollectionExactItemA' as FindCollectionExactItemA:qword
extrn 'FindCollectionExactItemW' as FindCollectionExactItemW:qword
extrn 'FindCollectionItem' as FindCollectionItem:qword
extrn 'FindCollectionItemA' as FindCollectionItemA:qword
extrn 'FindCollectionItemW' as FindCollectionItemW:qword
extrn 'FindString' as FindString:qword
extrn 'FindStringA' as FindStringA:qword
extrn 'FindStringW' as FindStringW:qword
extrn 'GetAppVersion' as GetAppVersion:qword
extrn 'GetAppVersionA' as GetAppVersionA:qword
extrn 'GetAppVersionW' as GetAppVersionW:qword
extrn 'GetChildRect' as GetChildRect:qword
extrn 'GetCollectionCount' as GetCollectionCount:qword
extrn 'GetCollectionItem' as GetCollectionItem:qword
extrn 'GetCollectionItemA' as GetCollectionItemA:qword
extrn 'GetCollectionItemW' as GetCollectionItemW:qword
extrn 'GetCollectionItemLength' as GetCollectionItemLength:qword
extrn 'GetCPUInfo' as GetCPUInfo:qword
extrn 'GetCurrentX' as GetCurrentX:qword
extrn 'GetCurrentY' as GetCurrentY:qword
extrn 'GetMDIClient' as GetMDIClient:qword
extrn 'GetOwnerWindow' as GetOwnerWindow:qword
extrn 'GetPlatform' as GetPlatform:qword
extrn 'GetPlatformA' as GetPlatformA:qword
extrn 'GetPlatformW' as GetPlatformW:qword
extrn 'GetRegistryValue' as GetRegistryValue:qword
extrn 'GetRegistryValueA' as GetRegistryValueA:qword
extrn 'GetRegistryValueW' as GetRegistryValueW:qword
extrn 'GetStringLength' as GetStringLength:qword
extrn 'GetStringLengthA' as GetStringLengthA:qword
extrn 'GetStringLengthW' as GetStringLengthW:qword
extrn 'GetToolTipHandle' as GetToolTipHandle:qword
extrn 'GetWindowItem' as GetWindowItem:qword
extrn 'InsertCollectionItem' as InsertCollectionItem:qword
extrn 'InsertCollectionItemA' as InsertCollectionItemA:qword
extrn 'InsertCollectionItemW' as InsertCollectionItemW:qword
extrn 'Is64BitVersion' as Is64BitVersion:qword
extrn 'IsAppUnicode' as IsAppUnicode:qword
extrn 'IsModal' as IsModal:qword
extrn 'IsUserAdministrator' as IsUserAdministrator:qword
extrn 'IsWow64' as IsWow64:qword
extrn 'Left' as Left:qword
extrn 'LeftA' as LeftA:qword
extrn 'LeftW' as LeftW:qword
extrn 'Line' as Line:qword
extrn 'LTrim' as LTrim:qword
extrn 'LTrimA' as LTrimA:qword
extrn 'LTrimW' as LTrimW:qword
extrn 'MakeFullPath' as MakeFullPath:qword
extrn 'MakeFullPathA' as MakeFullPathA:qword
extrn 'MakeFullPathW' as MakeFullPathW:qword
extrn 'Mid' as Mid:qword
extrn 'MidA' as MidA:qword
extrn 'MidW' as MidW:qword
extrn 'OpenTextFile' as OpenTextFile:qword
extrn 'OpenTextFileA' as OpenTextFileA:qword
extrn 'OpenTextFileW' as OpenTextFileW:qword
extrn 'OutputString' as OutputString:qword
extrn 'OutputStringA' as OutputStringA:qword
extrn 'OutputStringW' as OutputStringW:qword
extrn 'Print' as Print:qword
extrn 'PrintA' as PrintA:qword
extrn 'PrintW' as PrintW:qword
extrn 'ReadTextLine' as ReadTextLine:qword
extrn 'ReadTextLineA' as ReadTextLineA:qword
extrn 'ReadTextLineW' as ReadTextLineW:qword
extrn 'Refresh' as Refresh:qword
extrn 'RemoveCollectionItem' as RemoveCollectionItem:qword
extrn 'Right' as Right:qword
extrn 'RightA' as RightA:qword
extrn 'RightW' as RightW:qword
extrn 'RTrim' as RTrim:qword
extrn 'RTrimA' as RTrimA:qword
extrn 'RTrimW' as RTrimW:qword
extrn 'SetCueBanner' as SetCueBanner:qword
extrn 'SetCurrentX' as SetCurrentX:qword
extrn 'SetCurrentY' as SetCurrentY:qword
extrn 'SetDefaultCursor' as SetDefaultCursor:qword
extrn 'SetRegistryValue' as SetRegistryValue:qword
extrn 'SetRegistryValueA' as SetRegistryValueA:qword
extrn 'SetRegistryValueW' as SetRegistryValueW:qword
extrn 'SetWaitCursor' as SetWaitCursor:qword
extrn 'String' as String:qword
extrn 'StringA' as StringA:qword
extrn 'StringW' as StringW:qword
extrn 'Trim' as Trim:qword
extrn 'TrimA' as TrimA:qword
extrn 'TrimW' as TrimW:qword
extrn 'Update' as Update:qword
extrn 'Value' as Value:qword
extrn 'ValueA' as ValueA:qword
extrn 'ValueW' as ValueW:qword
extrn 'WriteTextLine' as WriteTextLine:qword
extrn 'WriteTextLineA' as WriteTextLineA:qword
extrn 'WriteTextLineW' as WriteTextLineW:qword
