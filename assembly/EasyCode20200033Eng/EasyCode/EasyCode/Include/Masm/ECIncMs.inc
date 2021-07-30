IFNDEF ALIGNMODE
    IFDEF APP_WIN64
        IFDEF POASM_COMPILER
            ALIGNMODE   TEXTEQU <>
        ELSE
            ALIGNMODE   TEXTEQU <16>
        ENDIF
        XWORD       TYPEDEF QWord
    ELSE
        ALIGNMODE   TEXTEQU <4>
        XWORD       TYPEDEF DWord
    ENDIF
ENDIF

;===========================================================================
; Object type constants
;===========================================================================
ecDialogBox             Equ     1
ecMDIWindow             Equ     2
ecWindow                Equ     3
ecStatic                Equ     4
ecEdit                  Equ     5
ecGroup                 Equ     6
ecButton                Equ     7
ecCheck                 Equ     8
ecRadio                 Equ     9
ecList                  Equ     10
ecCombo                 Equ     11
ecPicture               Equ     12
ecImage                 Equ     13
ecHScroll               Equ     14
ecVScroll               Equ     15
ecRichEdit              Equ     16
ecTreeView              Equ     17
ecListView              Equ     18
ecToolBar               Equ     19
ecStatusBar             Equ     20
ecProgressBar           Equ     21
ecSlider                Equ     22
ecTabStrip              Equ     23
ecUpDown                Equ     24
ecAnimate               Equ     25
ecIpAddress             Equ     26
ecImageCombo            Equ     27
ecCalendar              Equ     28
ecDateTime              Equ     29
ecHotKey                Equ     30
ecPager                 Equ     31
ecImageList             Equ     32
ecHeader                Equ     33
ecRebar                 Equ     34
ecThread                Equ     35
ecSysLink				Equ		36
ecUser                  Equ     50


;===========================================================================
; Registry constants
;===========================================================================
ecClassesRoot           Equ     HKEY_CLASSES_ROOT
ecCurrentUser           Equ     HKEY_CURRENT_USER
ecLocalMachine          Equ     HKEY_LOCAL_MACHINE
ecUsers                 Equ     HKEY_USERS
ecPerformanceData       Equ     HKEY_PERFORMANCE_DATA
ecCurrentConfig         Equ     HKEY_CURRENT_CONFIG
ecDynData               Equ     HKEY_DYN_DATA


;===========================================================================
; Scale mode constants
;===========================================================================
ecPixels                Equ     0
ecTwips                 Equ     1


;===========================================================================
; Mouse cursor constants
;===========================================================================
ecDefault               Equ     0
ecArrow                 Equ     1
ecIBeam                 Equ     2
ecWait                  Equ     3
ecCross                 Equ     4
ecUpArrow               Equ     5
ecSizeAll               Equ     6
ecSizeNWSE              Equ     7
ecSizeNESW              Equ     8
ecSizeWE                Equ     9
ecSizeNS                Equ     10
ecNoDrop                Equ     11
ecAppStarting           Equ     12
ecHelp                  Equ     13
ecCustom                Equ     14


;===========================================================================
; Drawing style constants
;===========================================================================
ecSolid                 Equ     0
ecDash                  Equ     1
ecDot                   Equ     2
ecDashDot               Equ     3
ecDashDotDot            Equ     4
ecNull                  Equ     5
ecInsideFrame           Equ     6


;===========================================================================
; Align constants
;===========================================================================
ecNone                  Equ     0
ecAlignTop              Equ     1
ecAlignBottom           Equ     2
ecAlignLeft             Equ     3
ecAlignRight            Equ     4


;===========================================================================
; Scroll bars constants
;===========================================================================
ecNone                  Equ     0
ecHorizontal            Equ     1
ecVertical              Equ     2
ecBoth                  Equ     3


;===========================================================================
; Show mode constants
;===========================================================================
ecHidden                Equ     (-1)
ecNormal                Equ     0
ecMinimized             Equ     1
ecMaximized             Equ     2

;===========================================================================
; Mode constants
;===========================================================================
ecModeless              Equ     0
ecModal                 Equ     1


;===========================================================================
; Center Window constants
;===========================================================================
ecLeft                  Equ     0
ecCenter                Equ     1
ecRight                 Equ     2


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
ecBinary                Equ     0
ecDecimal               Equ     1
ecHexa                  Equ     2
ecOctal                 Equ     3


;===========================================================================
; Open text file constants
;===========================================================================
ecRead                  Equ     GENERIC_READ
ecWrite                 Equ     GENERIC_WRITE

ecCreateNew             Equ     CREATE_NEW
ecCreateAlways          Equ     CREATE_ALWAYS
ecOpenExisting          Equ     OPEN_EXISTING
ecOpenAlways            Equ     OPEN_ALWAYS
ecTruncateExisting      Equ     TRUNCATE_EXISTING


;===========================================================================
; Easy Code messages
;===========================================================================
ECM_LINKCLICKED         Equ     (WM_USER + 1030)
ECM_LINKPUSHED          Equ     ECM_LINKCLICKED
ECM_AFTERCREATE         Equ     (WM_USER + 1049)
ECM_REDRAWBACKGROUND    Equ     (WM_USER + 1054)
ECM_SOCK				Equ		(WM_USER + 1100)


;===========================================================================
; Object properties enumeration
;===========================================================================
p_Align                 Equ     0
p_AutoSize              Equ     1 * XWORD
p_BackColor             Equ     2 * XWORD
p_crBackColor           Equ     3 * XWORD
p_Brush                 Equ     4 * XWORD
p_CaseStyle             Equ     5 * XWORD
p_Center                Equ     6 * XWORD
p_CursorIcon            Equ     7 * XWORD
p_CursorShape           Equ     8 * XWORD
p_DisableClose          Equ     9 * XWORD
p_DrawingStyle          Equ     10 * XWORD
p_DrawingWidth          Equ     11 * XWORD
p_Enabled               Equ     12 * XWORD
p_Focus                 Equ     13 * XWORD
p_Font                  Equ     14 * XWORD
p_FontBold              Equ     15 * XWORD
p_FontItalic            Equ     16 * XWORD
p_FontName              Equ     17 * XWORD
p_FontSize              Equ     18 * XWORD
p_FontStrikethru        Equ     19 * XWORD
p_FontUnderline         Equ     20 * XWORD
p_ForeColor             Equ     21 * XWORD
p_crForeColor           Equ     22 * XWORD
p_Height                Equ     23 * XWORD
p_hWnd                  Equ     24 * XWORD
p_hWndClient            Equ     25 * XWORD
p_IconBig               Equ     26 * XWORD
p_IconSmall             Equ     27 * XWORD
p_ImageHeight           Equ     28 * XWORD
p_ImageType             Equ     29 * XWORD
p_ImageWidth            Equ     30 * XWORD
p_KeepSize              Equ     31 * XWORD
p_Left                  Equ     32 * XWORD
p_Main                  Equ     33 * XWORD
p_MaxLength             Equ     34 * XWORD
p_MDIChild              Equ     35 * XWORD
p_Menu                  Equ     36 * XWORD
p_Name                  Equ     37 * XWORD
p_NoPrefix              Equ     38 * XWORD
p_Offset                Equ     39 * XWORD
p_Parent                Equ     40 * XWORD
p_PasswordChar          Equ     41 * XWORD
p_Pen                   Equ     42 * XWORD
p_Picture               Equ     43 * XWORD
p_RightToLeft           Equ     44 * XWORD
p_ScaleMode             Equ     45 * XWORD
p_ScrollBars            Equ     46 * XWORD
p_ShowMode              Equ     47 * XWORD
p_Stretch               Equ     48 * XWORD
p_TabOrder              Equ     49 * XWORD
p_TabStop               Equ     50 * XWORD
p_Text                  Equ     51 * XWORD
p_TextAlignment         Equ     52 * XWORD
p_TextLength            Equ     53 * XWORD
p_Timer                 Equ     54 * XWORD
p_TimerID               Equ     55 * XWORD
p_Top                   Equ     56 * XWORD
p_Transparent           Equ     57 * XWORD
p_Type                  Equ     58 * XWORD
p_Value                 Equ     59 * XWORD
p_Visible               Equ     60 * XWORD
p_Width                 Equ     61 * XWORD
p_WindowProc            Equ     62 * XWORD
p_WndOldControlProc     Equ     63 * XWORD
p_DialogID              Equ     64 * XWORD
p_Children              Equ     65 * XWORD
p_DefButton             Equ     66 * XWORD
p_ExStyle               Equ     67 * XWORD
p_Style                 Equ     68 * XWORD
p_ButtonStruct          Equ     69 * XWORD
p_OldFont               Equ     70 * XWORD
p_ToolTip               Equ     71 * XWORD
p_MouseLeave            Equ     72 * XWORD
p_PropertyCount         Equ     73 * XWORD

p_Alignment             Equ     p_AutoSize
p_AlignMode             Equ     p_Transparent
p_AutoRedraw            Equ     p_PasswordChar
p_BandCount             Equ     p_DrawingStyle
p_BandStruct            Equ     p_ButtonStruct
p_Border                Equ     p_CaseStyle
p_ButtonCount           Equ     p_DrawingStyle
p_ButtonHeight          Equ     p_CaseStyle
p_ButtonSize            Equ     p_Center
p_ButtonWidth           Equ     p_Center
p_Cancel                Equ     p_AutoSize
p_ChildOffset           Equ     p_OldFont
p_ColorQuality          Equ     p_TextAlignment
p_CurrentX              Equ     p_NoPrefix
p_CurrentY              Equ     p_Offset
p_Default               Equ     p_DisableClose
p_DisableNoScroll       Equ     p_DisableClose
p_DrawFlags             Equ     p_Value
p_DrawFocus             Equ     p_Transparent
p_FlickerFree           Equ     p_DisableClose
p_GripperCursor         Equ     p_NoPrefix
p_HideSelection         Equ     p_AutoSize
p_HitTest               Equ     p_Offset
p_HyperColor            Equ     p_ScrollBars
p_HyperLink             Equ     p_MaxLength
p_ImageCount            Equ     p_Transparent
p_ImageList             Equ     p_DrawingStyle
p_ImageStruct           Equ     p_ButtonStruct
p_Indentation           Equ     p_CaseStyle
p_ItemCount             Equ     p_DrawingStyle
p_ItemStruct            Equ     p_ButtonStruct
p_KeyPreview            Equ     p_NoPrefix
p_LvwExStyle            Equ     p_TextAlignment
p_MaxValue              Equ     p_ScrollBars
p_MinValue              Equ     p_ShowMode
p_Modal                 Equ     p_Stretch
p_MultiLine             Equ     p_NoPrefix
p_NormalStyle           Equ     p_Style
p_OwnerDraw             Equ     p_DrawingStyle
p_PageSize              Equ     p_TextAlignment
p_PannelCount           Equ     p_DrawingStyle
p_PannelStruct          Equ     p_ButtonStruct
p_PicturePosition       Equ     p_MaxLength
p_SelStart              Equ     p_Offset
p_SelEnd                Equ     p_Stretch
p_TabCount              Equ     p_DrawingStyle
p_TabStruct             Equ     p_ButtonStruct
p_TickFrequency         Equ     p_Transparent
p_ToolTipText           Equ     p_ToolTip
p_VisibleRows           Equ     p_MaxLength


;===========================================================================
; Error Object STRUCT
;===========================================================================
ECErrorStruct STRUCT ALIGNMODE
	IFDEF APP_WIN64
	    regRsp      QWORD ?
	    regRbp      QWORD ?
	    regRip      QWORD ?
	ELSE
	    regEsp      DWORD ?
	    regEbp      DWORD ?
	    regEip      DWORD ?
	ENDIF
    lCode       	XWORD ?
    Description 	XWORD ?
ECErrorStruct ENDS


;===========================================================================
; App Object STRUCT
;===========================================================================
ECApplication STRUCT ALIGNMODE
    Accel       XWORD ?
    CommandLine XWORD ?
    FileName    XWORD ?
    Header      XWORD ?
    Instance    XWORD ?
    Main        XWORD ?
    Major       XWORD ?
    Minor       XWORD ?
    Previous    XWORD ?
    Revision    XWORD ?
    Path        XWORD ?
    ProcessID   XWORD ?
    ThreadID    XWORD ?
ECApplication ENDS


;===========================================================================
; StatusBar Object STRUCT
;===========================================================================
STBPANNEL STRUCT ALIGNMODE
    nWidth      DWORD ?
    nBevel      DWORD ?
    lpszText    XWORD ?
STBPANNEL ENDS


;===========================================================================
; ImageList Object STRUCT
;===========================================================================
IMAGESTRUCT STRUCT ALIGNMODE
    lType       XWORD ?
    lpszResID   XWORD ?
IMAGESTRUCT ENDS


;===========================================================================
; Header Object STRUCT
;===========================================================================
ITEMSTRUCT STRUCT ALIGNMODE
    iImage      XWORD ?
    nWidth      XWORD ?
    lTextAlign  XWORD ?
    lpszText    XWORD ?
ITEMSTRUCT ENDS


;===========================================================================
; Rebar Object STRUCT
;===========================================================================
BANDSTRUCT STRUCT ALIGNMODE
    lHeader     XWORD ?
    lLength     XWORD ?
    lMinHeight  XWORD ?
    lMinWidth   XWORD ?
    dwStyle     XWORD ?
    hBitmap     XWORD ?
    hWndChild   XWORD ?
    lpszBitmap  XWORD ?
    lpszChild   XWORD ?
    lpszText    XWORD ?
BANDSTRUCT ENDS


;===========================================================================
; CPU Info STRUCT
;===========================================================================
CPUINFO STRUCT ALIGNMODE
    Description  DB    32 Dup(?)
    Stepping     XWORD ?
    Family       XWORD ?
    Model        XWORD ?
    CPUType      XWORD ?
    ModelID      XWORD ?
    FeaturesID   XWORD ?
    ExFeaturesID XWORD ?
CPUINFO ENDS


;===========================================================================
; Get properties prototypes
;===========================================================================
GetAlign                Proto   :XWORD
GetAutoSize             Proto   :XWORD
GetBackColor            Proto   :XWORD
GetCancel               Proto   :XWORD
GetCaseStyle            Proto   :XWORD
GetCursorIcon           Proto   :XWORD
GetCursorShape          Proto   :XWORD
GetDefault              Proto   :XWORD
GetDrawFocus            Proto   :XWORD
GetDrawingStyle         Proto   :XWORD
GetDrawingWidth         Proto   :XWORD
GetEnabled              Proto   :XWORD
GetFlickerFree          Proto   :XWORD
GetFont                 Proto   :XWORD
GetFontBold             Proto   :XWORD
GetFontItalic           Proto   :XWORD
GetFontName             Proto   :XWORD, :XWORD
GetFontNameA            Proto   :XWORD, :XWORD
GetFontNameW            Proto   :XWORD, :XWORD
GetFontSize             Proto   :XWORD
GetFontStrikethru       Proto   :XWORD
GetFontUnderline        Proto   :XWORD
GetForeColor            Proto   :XWORD
GetHeight               Proto   :XWORD
GetIconBig              Proto   :XWORD
GetIconSmall            Proto   :XWORD
GetLayoutRTL            Proto   :XWORD
GetLeft                 Proto   :XWORD
GetMaxValue             Proto   :XWORD
GetMaxLength            Proto   :XWORD
GetMDIChild             Proto   :XWORD
GetMinValue             Proto   :XWORD
GetMultiLine            Proto   :XWORD
GetName                 Proto   :XWORD, :XWORD
GetNameA                Proto   :XWORD, :XWORD
GetNameW                Proto   :XWORD, :XWORD
GetNoPrefix             Proto   :XWORD
GetPageSize             Proto   :XWORD
GetPasswordChar         Proto   :XWORD
GetPicture              Proto   :XWORD
GetPicturePosition      Proto   :XWORD
GetRightToLeft          Proto   :XWORD
GetScaleMode            Proto   :XWORD
GetScrollBars           Proto   :XWORD
GetShowMode             Proto   :XWORD
GetStretch              Proto   :XWORD
GetTabOrder             Proto   :XWORD
GetTabStop              Proto   :XWORD
GetText                 Proto   :XWORD, :XWORD
GetTextA                Proto   :XWORD, :XWORD
GetTextW                Proto   :XWORD, :XWORD
GetTextAlignment        Proto   :XWORD
GetTimerInterval        Proto   :XWORD
GetTop                  Proto   :XWORD
GetType                 Proto   :XWORD
GetValue                Proto   :XWORD
GetVisible              Proto   :XWORD
GetVisibleRows          Proto   :XWORD
GetWidth                Proto   :XWORD

;===========================================================================
; Set properties prototypes
;===========================================================================
SetAlign                Proto   :XWORD, :XWORD
SetAutoSize             Proto   :XWORD, :XWORD
SetBackColor            Proto   :XWORD, :XWORD
SetCursorIcon           Proto   :XWORD, :XWORD
SetCursorShape          Proto   :XWORD, :XWORD
SetDefault              Proto   :XWORD, :XWORD
SetDrawFocus            Proto   :XWORD, :XWORD
SetDrawingStyle         Proto   :XWORD, :XWORD
SetDrawingWidth         Proto   :XWORD, :XWORD
SetEnabled              Proto   :XWORD, :XWORD
SetFlickerFree          Proto   :XWORD, :XWORD
SetFontBold             Proto   :XWORD, :XWORD
SetFontItalic           Proto   :XWORD, :XWORD
SetFontName             Proto   :XWORD, :XWORD
SetFontNameA            Proto   :XWORD, :XWORD
SetFontNameW            Proto   :XWORD, :XWORD
SetFontSize             Proto   :XWORD, :XWORD
SetFontStrikethru       Proto   :XWORD, :XWORD
SetFontUnderline        Proto   :XWORD, :XWORD
SetForeColor            Proto   :XWORD, :XWORD
SetHeight               Proto   :XWORD, :XWORD
SetIconBig              Proto   :XWORD, :XWORD
SetIconSmall            Proto   :XWORD, :XWORD
SetLayoutRTL            Proto   :XWORD, :XWORD
SetLeft                 Proto   :XWORD, :XWORD
SetMarquee              Proto   :XWORD, :XWORD, :XWORD
SetMaxValue             Proto   :XWORD, :XWORD
SetMaxLength            Proto   :XWORD, :XWORD
SetMinValue             Proto   :XWORD, :XWORD
SetPageSize             Proto   :XWORD, :XWORD
SetPasswordChar         Proto   :XWORD, :XWORD
SetPicture              Proto   :XWORD, :XWORD
SetPicturePosition      Proto   :XWORD, :XWORD
SetRightToLeft          Proto   :XWORD, :XWORD
SetScrollBars           Proto   :XWORD, :XWORD
SetShowMode             Proto   :XWORD, :XWORD
SetTabStop              Proto   :XWORD, :XWORD
SetText                 Proto   :XWORD, :XWORD
SetTextA                Proto   :XWORD, :XWORD
SetTextW                Proto   :XWORD, :XWORD
SetTimerInterval        Proto   :XWORD, :XWORD
SetTop                  Proto   :XWORD, :XWORD
SetValue                Proto   :XWORD, :XWORD
SetVisible              Proto   :XWORD, :XWORD
SetVisibleRows          Proto   :XWORD, :XWORD
SetWidth                Proto   :XWORD, :XWORD


;===========================================================================
; Methods prototypes
;===========================================================================
AddCharToString             Proto   :XWORD, :XWORD
AddCharToStringA            Proto   :XWORD, :XWORD
AddCharToStringW            Proto   :XWORD, :XWORD
AddCollectionItem           Proto   :XWORD, :XWORD
AddCollectionItemA          Proto   :XWORD, :XWORD
AddCollectionItemW          Proto   :XWORD, :XWORD
CallDefaultProc             Proto   :XWORD, :XWORD, :XWORD, :XWORD
Circle                      Proto   :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
Create                      Proto   :XWORD, :XWORD, :XWORD, :XWORD
CreateCollection            Proto   :XWORD
CreateCollectionA           Proto   :XWORD
CreateCollectionW           Proto   :XWORD
DeleteRegistryKey           Proto   :XWORD, :XWORD
DeleteRegistryKeyA          Proto   :XWORD, :XWORD
DeleteRegistryKeyW          Proto   :XWORD, :XWORD
DeleteRegistryValue         Proto   :XWORD, :XWORD, :XWORD
DeleteRegistryValueA        Proto   :XWORD, :XWORD, :XWORD
DeleteRegistryValueW        Proto   :XWORD, :XWORD, :XWORD
DestroyCollection           Proto   :XWORD
DoEvents                    Proto
EmptyCollection             Proto   :XWORD
EndModal                    Proto   :XWORD, :XWORD
Eof                         Proto   :XWORD
FileExists                  Proto   :XWORD
FileExistsA                 Proto   :XWORD
FileExistsW                 Proto   :XWORD
FillMemoryBlock             Proto   :XWORD, :XWORD, :XWORD
FindChar                    Proto   :XWORD, :XWORD
FindCharA                   Proto   :XWORD, :XWORD
FindCharW                   Proto   :XWORD, :XWORD
FindCharRev                 Proto   :XWORD, :XWORD
FindCharRevA                Proto   :XWORD, :XWORD
FindCharRevW                Proto   :XWORD, :XWORD
FindCollectionExactItem     Proto   :XWORD, :XWORD
FindCollectionExactItemA    Proto   :XWORD, :XWORD
FindCollectionExactItemW    Proto   :XWORD, :XWORD
FindCollectionItem          Proto   :XWORD, :XWORD
FindCollectionItemA         Proto   :XWORD, :XWORD
FindCollectionItemW         Proto   :XWORD, :XWORD
FindString					Proto	:XWORD, :XWORD, :XWORD
FindStringA					Proto	:XWORD, :XWORD, :XWORD
FindStringW					Proto	:XWORD, :XWORD, :XWORD
GetAppVersion               Proto   :XWORD
GetAppVersionA              Proto   :XWORD
GetAppVersionW              Proto   :XWORD
GetChildRect                Proto   :XWORD, :XWORD
GetCollectionCount          Proto   :XWORD
GetCollectionItem           Proto   :XWORD, :XWORD, :XWORD
GetCollectionItemA          Proto   :XWORD, :XWORD, :XWORD
GetCollectionItemW          Proto   :XWORD, :XWORD, :XWORD
GetCollectionItemLength     Proto   :XWORD, :XWORD
GetCPUInfo                  Proto   :XWORD
GetCurrentX                 Proto   :XWORD
GetCurrentY                 Proto   :XWORD
GetMDIClient                Proto   :XWORD
GetOwnerWindow              Proto   :XWORD
GetPlatform                 Proto   :XWORD
GetPlatformA                Proto   :XWORD
GetPlatformW                Proto   :XWORD
GetRegistryValue            Proto   :XWORD, :XWORD, :XWORD, :XWORD
GetRegistryValueA           Proto   :XWORD, :XWORD, :XWORD, :XWORD
GetRegistryValueW           Proto   :XWORD, :XWORD, :XWORD, :XWORD
GetStringLength             Proto   :XWORD
GetStringLengthA            Proto   :XWORD
GetStringLengthW            Proto   :XWORD
GetToolTipHandle            Proto   :XWORD
GetWindowItem               Proto   :XWORD, :XWORD
InsertCollectionItem        Proto   :XWORD, :XWORD, :XWORD
InsertCollectionItemA       Proto   :XWORD, :XWORD, :XWORD
InsertCollectionItemW       Proto   :XWORD, :XWORD, :XWORD
Is64BitVersion              Proto
IsAppUnicode                Proto
IsModal                     Proto   :XWORD
IsUserAdministrator         Proto
IsWow64                     Proto   :XWORD
Left                        Proto   :XWORD, :XWORD
LeftA                       Proto   :XWORD, :XWORD
LeftW                       Proto   :XWORD, :XWORD
Line                        Proto   :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
LTrim                       Proto   :XWORD
LTrimA                      Proto   :XWORD
LTrimW                      Proto   :XWORD
MakeFullPath                Proto   :XWORD, :XWORD
MakeFullPathA               Proto   :XWORD, :XWORD
MakeFullPathW               Proto   :XWORD, :XWORD
Mid                         Proto   :XWORD, :XWORD, :XWORD
MidA                        Proto   :XWORD, :XWORD, :XWORD
MidW                        Proto   :XWORD, :XWORD, :XWORD
OpenTextFile                Proto   :XWORD, :XWORD, :XWORD
OpenTextFileA               Proto   :XWORD, :XWORD, :XWORD
OpenTextFileW               Proto   :XWORD, :XWORD, :XWORD
OutputBuffer                Proto   :XWORD, :XWORD
OutputString                Proto   :XWORD, :XWORD
OutputStringA               Proto   :XWORD, :XWORD
OutputStringW               Proto   :XWORD, :XWORD
Print                       Proto   :XWORD, :XWORD
PrintA                      Proto   :XWORD, :XWORD
PrintW                      Proto   :XWORD, :XWORD
ReadTextLine                Proto   :XWORD, :XWORD
ReadTextLineA               Proto   :XWORD, :XWORD
ReadTextLineW               Proto   :XWORD, :XWORD
Refresh                     Proto   :XWORD
RemoveCollectionItem        Proto   :XWORD, :XWORD
Right                       Proto   :XWORD, :XWORD
RightA                      Proto   :XWORD, :XWORD
RightW                      Proto   :XWORD, :XWORD
RTrim                       Proto   :XWORD
RTrimA                      Proto   :XWORD
RTrimW                      Proto   :XWORD
SetCueBanner                Proto   :XWORD, :XWORD, :XWORD
SetCurrentX                 Proto   :XWORD, :XWORD
SetCurrentY                 Proto   :XWORD, :XWORD
SetDefaultCursor            Proto
SetRegistryValue            Proto   :XWORD, :XWORD, :XWORD, :XWORD
SetRegistryValueA           Proto   :XWORD, :XWORD, :XWORD, :XWORD
SetRegistryValueW           Proto   :XWORD, :XWORD, :XWORD, :XWORD
SetWaitCursor               Proto   :XWORD
String                      Proto   :XWORD, :XWORD, :XWORD
StringA                     Proto   :XWORD, :XWORD, :XWORD
StringW                     Proto   :XWORD, :XWORD, :XWORD
Trim                        Proto   :XWORD
TrimA                       Proto   :XWORD
TrimW                       Proto   :XWORD
Update                      Proto   :XWORD
Value                       Proto   :XWORD
ValueA                      Proto   :XWORD
ValueW                      Proto   :XWORD
WriteTextLine               Proto   :XWORD, :XWORD
WriteTextLineA              Proto   :XWORD, :XWORD
WriteTextLineW              Proto   :XWORD, :XWORD
