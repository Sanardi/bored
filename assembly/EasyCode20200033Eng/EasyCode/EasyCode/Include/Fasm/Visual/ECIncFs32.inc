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
p_AutoSize				= 1 * 4
p_BackColor				= 2 * 4
p_crBackColor			= 3 * 4
p_Brush					= 4 * 4
p_CaseStyle				= 5 * 4
p_Center				= 6 * 4
p_CursorIcon			= 7 * 4
p_CursorShape			= 8 * 4
p_DisableClose			= 9 * 4
p_DrawingStyle			= 10 * 4
p_DrawingWidth			= 11 * 4
p_Enabled				= 12 * 4
p_Focus					= 13 * 4
p_Font					= 14 * 4
p_FontBold				= 15 * 4
p_FontItalic			= 16 * 4
p_FontName				= 17 * 4
p_FontSize				= 18 * 4
p_FontStrikethru		= 19 * 4
p_FontUnderline			= 20 * 4
p_ForeColor				= 21 * 4
p_crForeColor			= 22 * 4
p_Height				= 23 * 4
p_hWnd					= 24 * 4
p_hWndClient			= 25 * 4
p_IconBig				= 26 * 4
p_IconSmall				= 27 * 4
p_ImageHeight			= 28 * 4
p_ImageType				= 29 * 4
p_ImageWidth			= 30 * 4
p_KeepSize				= 31 * 4
p_Left					= 32 * 4
p_Main					= 33 * 4
p_MaxLength				= 34 * 4
p_MDIChild				= 35 * 4
p_Menu					= 36 * 4
p_Name					= 37 * 4
p_NoPrefix				= 38 * 4
p_Offset				= 39 * 4
p_Parent				= 40 * 4
p_PasswordChar			= 41 * 4
p_Pen					= 42 * 4
p_Picture				= 43 * 4
p_RightToLeft			= 44 * 4
p_ScaleMode				= 45 * 4
p_ScrollBars			= 46 * 4
p_ShowMode				= 47 * 4
p_Stretch				= 48 * 4
p_TabOrder				= 49 * 4
p_TabStop				= 50 * 4
p_Text					= 51 * 4
p_TextAlignment			= 52 * 4
p_TextLength			= 53 * 4
p_Timer					= 54 * 4
p_TimerID				= 55 * 4
p_Top					= 56 * 4
p_Transparent			= 57 * 4
p_Type					= 58 * 4
p_Value					= 59 * 4
p_Visible				= 60 * 4
p_Width					= 61 * 4
p_WindowProc			= 62 * 4
p_WndOldControlProc		= 63 * 4
p_DialogID				= 64 * 4
p_Children				= 65 * 4
p_DefButton				= 66 * 4
p_ExStyle				= 67 * 4
p_Style					= 68 * 4
p_ButtonStruct			= 69 * 4
p_OldFont				= 70 * 4
p_ToolTip				= 71 * 4
p_MouseLeave			= 72 * 4
p_PropertyCount			= 73 * 4

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
	regEsp		dd		?
	regEbp		dd		?
	regEip		dd		?
	lCode		dd		?
	Description	dd		?
ends


;===========================================================================
; App Object struct
;===========================================================================
struct ECApplication
	Accel		dd		?
	CommandLine	dd		?
	FileName	dd		?
	Header		dd		?
	Instance	dd		?
	Main		dd		?
	Major		dd		?
	Minor		dd		?
	Previous	dd		?
	Revision	dd		?
	Path		dd		?
	ProcessID	dd		?
	ThreadID	dd		?
ends


;===========================================================================
; StatusBar Object struct
;===========================================================================
struct STBPANNEL
	nWidth		dd		?
	nBevel		dd		?
	lpszText	dd		?
ends


;===========================================================================
; ImageList Object struct
;===========================================================================
struct IMAGESTRUCT
	lType		dd		?
	lpszResID	dd		?
ends


;===========================================================================
; Header Object struct
;===========================================================================
struct ITEMSTRUCT
	iImage		dd		?
	nWidth		dd		?
	lTextAlign	dd		?
	lpszText	dd		?
ends


;===========================================================================
; Rebar Object struct
;===========================================================================
struct BANDSTRUCT
	lHeader		dd		?
	lLength		dd		?
	lMinHeight	dd		?
	lMinWidth	dd		?
	dwStyle		dd		?
	hBitmap		dd		?
	hWndChild	dd		?
	lpszBitmap	dd		?
	lpszChild	dd		?
	lpszText	dd		?
ends


;===========================================================================
; CPU Info struct
;===========================================================================
struct CPUINFO
	Description  db 32 dup(?)
	Stepping     dd ?
	Family       dd ?
	Model        dd ?
	CPUType      dd ?
	ModelID      dd ?
	FeaturesID   dd ?
	ExFeaturesID dd ?
ends

;===========================================================================
; Get properties
;===========================================================================
extrn '_GetAlign@4' as GetAlign:dword
extrn '_GetAutoSize@4' as GetAutoSize:dword
extrn '_GetBackColor@4' as GetBackColor:dword
extrn '_GetCancel@4' as GetCancel:dword
extrn '_GetCaseStyle@4' as GetCaseStyle:dword
extrn '_GetCursorIcon@4' as GetCursorIcon:dword
extrn '_GetCursorShape@4' as GetCursorShape:dword
extrn '_GetDefault@4' as GetDefault:dword
extrn '_GetDrawFocus@4' as GetDrawFocus:dword
extrn '_GetDrawingStyle@4' as GetDrawingStyle:dword
extrn '_GetDrawingWidth@4' as GetDrawingWidth:dword
extrn '_GetEnabled@4' as GetEnabled:dword
extrn '_GetFlickerFree@4' as GetFlickerFree:dword
extrn '_GetFont@4' as GetFont:dword
extrn '_GetFontBold@4' as GetFontBold:dword
extrn '_GetFontItalic@4' as GetFontItalic:dword
extrn '_GetFontName@8' as GetFontName:dword
extrn '_GetFontNameA@8' as GetFontNameA:dword
extrn '_GetFontNameW@8' as GetFontNameW:dword
extrn '_GetFontSize@4' as GetFontSize:dword
extrn '_GetFontStrikethru@4' as GetFontStrikethru:dword
extrn '_GetFontUnderline@4' as GetFontUnderline:dword
extrn '_GetForeColor@4' as GetForeColor:dword
extrn '_GetHeight@4' as GetHeight:dword
extrn '_GetIconBig@4' as GetIconBig:dword
extrn '_GetIconSmall@4' as GetIconSmall:dword
extrn '_GetLayoutRTL@4' as GetLayoutRTL:dword
extrn '_GetLeft@4' as GetLeft:dword
extrn '_GetMaxValue@4' as GetMaxValue:dword
extrn '_GetMaxLength@4' as GetMaxLength:dword
extrn '_GetMDIChild@4' as GetMDIChild:dword
extrn '_GetMinValue@4' as GetMinValue:dword
extrn '_GetMultiLine@4' as GetMultiLine:dword
extrn '_GetName@8' as GetName:dword
extrn '_GetNameA@8' as GetNameA:dword
extrn '_GetNameW@8' as GetNameW:dword
extrn '_GetNoPrefix@4' as GetNoPrefix:dword
extrn '_GetPageSize@4' as GetPageSize:dword
extrn '_GetPasswordChar@4' as GetPasswordChar:dword
extrn '_GetPicture@4' as GetPicture:dword
extrn '_GetPicturePosition@4' as GetPicturePosition:dword
extrn '_GetRightToLeft@4' as GetRightToLeft:dword
extrn '_GetScaleMode@4' as GetScaleMode:dword
extrn '_GetScrollBars@4' as GetScrollBars:dword
extrn '_GetShowMode@4' as GetShowMode:dword
extrn '_GetStretch@4' as GetStretch:dword
extrn '_GetTabOrder@4' as GetTabOrder:dword
extrn '_GetTabStop@4' as GetTabStop:dword
extrn '_GetText@8' as GetText:dword
extrn '_GetTextA@8' as GetTextA:dword
extrn '_GetTextW@8' as GetTextW:dword
extrn '_GetTextAlignment@4' as GetTextAlignment:dword
extrn '_GetTimerInterval@4' as GetTimerInterval:dword
extrn '_GetTop@4' as GetTop:dword
extrn '_GetType@4' as GetType:dword
extrn '_GetValue@4' as GetValue:dword
extrn '_GetVisible@4' as GetVisible:dword
extrn '_GetVisibleRows@4' as GetVisibleRows:dword
extrn '_GetWidth@4' as GetWidth:dword

;===========================================================================
; Set properties
;===========================================================================
extrn '_SetAlign@8' as SetAlign:dword
extrn '_SetAutoSize@8' as SetAutoSize:dword
extrn '_SetBackColor@8' as SetBackColor:dword
extrn '_SetCursorIcon@8' as SetCursorIcon:dword
extrn '_SetCursorShape@8' as SetCursorShape:dword
extrn '_SetDefault@8' as SetDefault:dword
extrn '_SetDrawFocus@8' as SetDrawFocus:dword
extrn '_SetDrawingStyle@8' as SetDrawingStyle:dword
extrn '_SetDrawingWidth@8' as SetDrawingWidth:dword
extrn '_SetEnabled@8' as SetEnabled:dword
extrn '_SetFlickerFree@8' as SetFlickerFree:dword
extrn '_SetFontBold@8' as SetFontBold:dword
extrn '_SetFontItalic@8' as SetFontItalic:dword
extrn '_SetFontName@8' as SetFontName:dword
extrn '_SetFontNameA@8' as SetFontNameA:dword
extrn '_SetFontNameW@8' as SetFontNameW:dword
extrn '_SetFontSize@8' as SetFontSize:dword
extrn '_SetFontStrikethru@8' as SetFontStrikethru:dword
extrn '_SetFontUnderline@8' as SetFontUnderline:dword
extrn '_SetForeColor@8' as SetForeColor:dword
extrn '_SetHeight@8' as SetHeight:dword
extrn '_SetIconBig@8' as SetIconBig:dword
extrn '_SetIconSmall@8' as SetIconSmall:dword
extrn '_SetLayoutRTL@8' as SetLayoutRTL:dword
extrn '_SetLeft@8' as SetLeft:dword
extrn '_SetMarquee@12' as SetMarquee:dword
extrn '_SetMaxValue@8' as SetMaxValue:dword
extrn '_SetMaxLength@8' as SetMaxLength:dword
extrn '_SetMinValue@8' as SetMinValue:dword
extrn '_SetPageSize@8' as SetPageSize:dword
extrn '_SetPasswordChar@8' as SetPasswordChar:dword
extrn '_SetPicture@8' as SetPicture:dword
extrn '_SetPicturePosition@8' as SetPicturePosition:dword
extrn '_SetRightToLeft@8' as SetRightToLeft:dword
extrn '_SetScrollBars@8' as SetScrollBars:dword
extrn '_SetShowMode@8' as SetShowMode:dword
extrn '_SetTabStop@8' as SetTabStop:dword
extrn '_SetText@8' as SetText:dword
extrn '_SetTextA@8' as SetTextA:dword
extrn '_SetTextW@8' as SetTextW:dword
extrn '_SetTimerInterval@8' as SetTimerInterval:dword
extrn '_SetTop@8' as SetTop:dword
extrn '_SetValue@8' as SetValue:dword
extrn '_SetVisible@8' as SetVisible:dword
extrn '_SetVisibleRows@8' as SetVisibleRows:dword
extrn '_SetWidth@8' as SetWidth:dword


;===========================================================================
; Easy Code Methods
;===========================================================================
extrn '_AddCharToString@8' as AddCharToString:dword
extrn '_AddCharToStringA@8' as AddCharToStringA:dword
extrn '_AddCharToStringW@8' as AddCharToStringW:dword
extrn '_AddCollectionItem@8' as AddCollectionItem:dword
extrn '_AddCollectionItemA@8' as AddCollectionItemA:dword
extrn '_AddCollectionItemW@8' as AddCollectionItemW:dword
extrn '_CallDefaultProc@16' as CallDefaultProc:dword
extrn '_Circle@24' as Circle:dword
extrn '_Create@16' as Create:dword
extrn '_CreateCollection@4' as CreateCollection:dword
extrn '_CreateCollectionA@4' as CreateCollectionA:dword
extrn '_CreateCollectionW@4' as CreateCollectionW:dword
extrn '_DeleteRegistryKey@8' as DeleteRegistryKey:dword
extrn '_DeleteRegistryKeyA@8' as DeleteRegistryKeyA:dword
extrn '_DeleteRegistryKeyW@8' as DeleteRegistryKeyW:dword
extrn '_DeleteRegistryValue@12' as DeleteRegistryValue:dword
extrn '_DeleteRegistryValueA@12' as DeleteRegistryValueA:dword
extrn '_DeleteRegistryValueW@12' as DeleteRegistryValueW:dword
extrn '_DestroyCollection@4' as DestroyCollection:dword
extrn '_DoEvents@0' as DoEvents:dword
extrn '_EmptyCollection@4' as EmptyCollection:dword
extrn '_EndModal@8' as EndModal:dword
extrn '_Eof@4' as Eof:dword
extrn '_FileExists@4' as FileExists:dword
extrn '_FileExistsA@4' as FileExistsA:dword
extrn '_FileExistsW@4' as FileExistsW:dword
extrn '_FillMemoryBlock@12' as FillMemoryBlock:dword
extrn '_FindChar@8' as FindChar:dword
extrn '_FindCharA@8' as FindCharA:dword
extrn '_FindCharW@8' as FindCharW:dword
extrn '_FindCharRev@8' as FindCharRev:dword
extrn '_FindCharRevA@8' as FindCharRevA:dword
extrn '_FindCharRevW@8' as FindCharRevW:dword
extrn '_FindCollectionExactItem@8' as FindCollectionExactItem:dword
extrn '_FindCollectionExactItemA@8' as FindCollectionExactItemA:dword
extrn '_FindCollectionExactItemW@8' as FindCollectionExactItemW:dword
extrn '_FindCollectionItem@8' as FindCollectionItem:dword
extrn '_FindCollectionItemA@8' as FindCollectionItemA:dword
extrn '_FindCollectionItemW@8' as FindCollectionItemW:dword
extrn '_FindString@12' as FindString:dword
extrn '_FindStringA@12' as FindStringA:dword
extrn '_FindStringW@12' as FindStringW:dword
extrn '_GetAppVersion@4' as GetAppVersion:dword
extrn '_GetAppVersionA@4' as GetAppVersionA:dword
extrn '_GetAppVersionW@4' as GetAppVersionW:dword
extrn '_GetChildRect@8' as GetChildRect:dword
extrn '_GetCollectionCount@4' as GetCollectionCount:dword
extrn '_GetCollectionItem@12' as GetCollectionItem:dword
extrn '_GetCollectionItemA@12' as GetCollectionItemA:dword
extrn '_GetCollectionItemW@12' as GetCollectionItemW:dword
extrn '_GetCollectionItemLength@8' as GetCollectionItemLength:dword
extrn '_GetCPUInfo@4' as GetCPUInfo:dword
extrn '_GetCurrentX@4' as GetCurrentX:dword
extrn '_GetCurrentY@4' as GetCurrentY:dword
extrn '_GetMDIClient@4' as GetMDIClient:dword
extrn '_GetOwnerWindow@4' as GetOwnerWindow:dword
extrn '_GetPlatform@4' as GetPlatform:dword
extrn '_GetPlatformA@4' as GetPlatformA:dword
extrn '_GetPlatformW@4' as GetPlatformW:dword
extrn '_GetRegistryValue@16' as GetRegistryValue:dword
extrn '_GetRegistryValueA@16' as GetRegistryValueA:dword
extrn '_GetRegistryValueW@16' as GetRegistryValueW:dword
extrn '_GetStringLength@4' as GetStringLength:dword
extrn '_GetStringLengthA@4' as GetStringLengthA:dword
extrn '_GetStringLengthW@4' as GetStringLengthW:dword
extrn '_GetToolTipHandle@4' as GetToolTipHandle:dword
extrn '_GetWindowItem@8' as GetWindowItem:dword
extrn '_InsertCollectionItem@12' as InsertCollectionItem:dword
extrn '_InsertCollectionItemA@12' as InsertCollectionItemA:dword
extrn '_InsertCollectionItemW@12' as InsertCollectionItemW:dword
extrn '_Is64BitVersion@0' as Is64BitVersion:dword
extrn '_IsAppUnicode@0' as IsAppUnicode:dword
extrn '_IsModal@4' as IsModal:dword
extrn '_IsUserAdministrator@0' as IsUserAdministrator:dword
extrn '_IsWow64@4' as IsWow64:dword
extrn '_Left@8' as Left:dword
extrn '_LeftA@8' as LeftA:dword
extrn '_LeftW@8' as LeftW:dword
extrn '_Line@28' as Line:dword
extrn '_LTrim@4' as LTrim:dword
extrn '_LTrimA@4' as LTrimA:dword
extrn '_LTrimW@4' as LTrimW:dword
extrn '_MakeFullPath@8' as MakeFullPath:dword
extrn '_MakeFullPathA@8' as MakeFullPathA:dword
extrn '_MakeFullPathW@8' as MakeFullPathW:dword
extrn '_Mid@12' as Mid:dword
extrn '_MidA@12' as MidA:dword
extrn '_MidW@12' as MidW:dword
extrn '_OpenTextFile@12' as OpenTextFile:dword
extrn '_OpenTextFileA@12' as OpenTextFileA:dword
extrn '_OpenTextFileW@12' as OpenTextFileW:dword
extrn '_OutputString@8' as OutputString:dword
extrn '_OutputStringA@8' as OutputStringA:dword
extrn '_OutputStringW@8' as OutputStringW:dword
extrn '_Print@8' as Print:dword
extrn '_PrintA@8' as PrintA:dword
extrn '_PrintW@8' as PrintW:dword
extrn '_ReadTextLine@8' as ReadTextLine:dword
extrn '_ReadTextLineA@8' as ReadTextLineA:dword
extrn '_ReadTextLineW@8' as ReadTextLineW:dword
extrn '_Refresh@4' as Refresh:dword
extrn '_RemoveCollectionItem@8' as RemoveCollectionItem:dword
extrn '_Right@8' as Right:dword
extrn '_RightA@8' as RightA:dword
extrn '_RightW@8' as RightW:dword
extrn '_RTrim@4' as RTrim:dword
extrn '_RTrimA@4' as RTrimA:dword
extrn '_RTrimW@4' as RTrimW:dword
extrn '_SetCueBanner@12' as SetCueBanner:dword
extrn '_SetCurrentX@8' as SetCurrentX:dword
extrn '_SetCurrentY@8' as SetCurrentY:dword
extrn '_SetDefaultCursor@0' as SetDefaultCursor:dword
extrn '_SetRegistryValue@16' as SetRegistryValue:dword
extrn '_SetRegistryValueA@16' as SetRegistryValueA:dword
extrn '_SetRegistryValueW@16' as SetRegistryValueW:dword
extrn '_SetWaitCursor@4' as SetWaitCursor:dword
extrn '_String@12' as String:dword
extrn '_StringA@12' as StringA:dword
extrn '_StringW@12' as StringW:dword
extrn '_Trim@4' as Trim:dword
extrn '_TrimA@4' as TrimA:dword
extrn '_TrimW@4' as TrimW:dword
extrn '_Update@4' as Update:dword
extrn '_Value@4' as Value:dword
extrn '_ValueA@4' as ValueA:dword
extrn '_ValueW@4' as ValueW:dword
extrn '_WriteTextLine@8' as WriteTextLine:dword
extrn '_WriteTextLineA@8' as WriteTextLineA:dword
extrn '_WriteTextLineW@8' as WriteTextLineW:dword
