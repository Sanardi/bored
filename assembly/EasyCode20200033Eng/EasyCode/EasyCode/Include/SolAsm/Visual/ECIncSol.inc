;===========================================================================
; Object type constants
;===========================================================================
ecDialogBox             equ     1
ecMDIWindow             equ     2
ecWindow                equ     3
ecStatic                equ     4
ecEdit                  equ     5
ecGroup                 equ     6
ecButton                equ     7
ecCheck                 equ     8
ecRadio                 equ     9
ecList                  equ     10
ecCombo                 equ     11
ecPicture               equ     12
ecImage                 equ     13
ecHScroll               equ     14
ecVScroll               equ     15
ecRichEdit              equ     16
ecTreeView              equ     17
ecListView              equ     18
ecToolBar               equ     19
ecStatusBar             equ     20
ecProgressBar           equ     21
ecSlider                equ     22
ecTabStrip              equ     23
ecUpDown                equ     24
ecAnimate               equ     25
ecIpAddress             equ     26
ecImageCombo            equ     27
ecCalendar              equ     28
ecDateTime              equ     29
ecHotKey                equ     30
ecPager                 equ     31
ecImageList             equ     32
ecHeader                equ     33
ecRebar                 equ     34
ecThread                equ     35
ecSysLink               equ     36
ecUser                  equ     50


;===========================================================================
; Registry constants
;===========================================================================
ecClassesRoot           equ     80000000H
ecCurrentUser           equ     80000001H
ecLocalMachine          equ     80000002H
ecUsers                 equ     80000003H
ecPerformanceData       equ     80000004H
ecCurrentConfig         equ     80000005H
ecDynData               equ     80000006H


;===========================================================================
; Scale mode constants
;===========================================================================
ecPixels                equ     0
ecTwips                 equ     1


;===========================================================================
; Mouse cursor constants
;===========================================================================
ecDefault               equ     0
ecArrow                 equ     1
ecIBeam                 equ     2
ecWait                  equ     3
ecCross                 equ     4
ecUpArrow               equ     5
ecSizeAll               equ     6
ecSizeNWSE              equ     7
ecSizeNESW              equ     8
ecSizeWE                equ     9
ecSizeNS                equ     10
ecNoDrop                equ     11
ecAppStarting           equ     12
ecHelp                  equ     13
ecCustom                equ     14


;===========================================================================
; Drawing style constants
;===========================================================================
ecSolid                 equ     0
ecDash                  equ     1
ecDot                   equ     2
ecDashDot               equ     3
ecDashDotDot            equ     4
ecNull                  equ     5
ecInsideFrame           equ     6


;===========================================================================
; Align constants
;===========================================================================
ecNone                  equ     0
ecAlignTop              equ     1
ecAlignBottom           equ     2
ecAlignLeft             equ     3
ecAlignRight            equ     4


;===========================================================================
; Scroll bars constants
;===========================================================================
ecHorizontal            equ     1
ecVertical              equ     2
ecBoth                  equ     3


;===========================================================================
; Show mode constants
;===========================================================================
ecHidden                equ     (-1)
ecNormal                equ     0
ecMinimized             equ     1
ecMaximized             equ     2

;===========================================================================
; Mode constants
;===========================================================================
ecModeless              equ     0
ecModal                 equ     1


;===========================================================================
; Center Window constants
;===========================================================================
ecLeft                  equ     0
ecCenter                equ     1
ecRight                 equ     2


;===========================================================================
; OS System constants
;===========================================================================
ecWin95					equ		1
ecWin98					equ		2
ecWinME					equ		2
ecWinNT					equ		3
ecWin2K					equ		4
ecWinXP					equ		5
ecWinVista				equ		6
ecWin7					equ		7
ecWinSeven				equ		7
ecWin8					equ		8
ecWin81					equ		9
ecWin10					equ		10
ecWinSever2003			equ		11
ecWinHomeServer			equ		12
ecWinServer2008			equ		13
ecWinServer2008R2		equ		14
ecWinSever2012			equ		15
ecWinSever2012R2		equ		16
ecWinSever2016			equ		17


;===========================================================================
; FindString method constants
;===========================================================================
ecMatchCase             equ     1
ecWholeWord             equ     2


;===========================================================================
; String method constants
;===========================================================================
ecBinary                equ     0
ecDecimal               equ     1
ecHexa                  equ     2
ecOctal                 equ     3


;===========================================================================
; Open text file constants
;===========================================================================
ecRead                  equ     GENERIC_READ
ecWrite                 equ     GENERIC_WRITE

ecCreateNew             equ     CREATE_NEW
ecCreateAlways          equ     CREATE_ALWAYS
ecOpenExisting          equ     OPEN_EXISTING
ecOpenAlways            equ     OPEN_ALWAYS
ecTruncateExisting      equ     TRUNCATE_EXISTING


;===========================================================================
; Easy Code messages
;===========================================================================
ECM_LINKCLICKED         equ     WM_USER+1030
ECM_LINKPUSHED          equ     ECM_LINKCLICKED
ECM_AFTERCREATE         equ     WM_USER+1049
ECM_REDRAWBACKGROUND    equ     WM_USER+1054
ECM_SOCK                equ     WM_USER+1100


;===========================================================================
; Object properties enumeration
;===========================================================================
p_Align                 equ     0
p_AutoSize              equ     1*xword_size
p_BackColor             equ     2*xword_size
p_crBackColor           equ     3*xword_size
p_Brush                 equ     4*xword_size
p_CaseStyle             equ     5*xword_size
p_Center                equ     6*xword_size
p_CursorIcon            equ     7*xword_size
p_CursorShape           equ     8*xword_size
p_DisableClose          equ     9*xword_size
p_DrawingStyle          equ     10*xword_size
p_DrawingWidth          equ     11*xword_size
p_Enabled               equ     12*xword_size
p_Focus                 equ     13*xword_size
p_Font                  equ     14*xword_size
p_FontBold              equ     15*xword_size
p_FontItalic            equ     16*xword_size
p_FontName              equ     17*xword_size
p_FontSize              equ     18*xword_size
p_FontStrikethru        equ     19*xword_size
p_FontUnderline         equ     20*xword_size
p_ForeColor             equ     21*xword_size
p_crForeColor           equ     22*xword_size
p_Height                equ     23*xword_size
p_hWnd                  equ     24*xword_size
p_hWndClient            equ     25*xword_size
p_IconBig               equ     26*xword_size
p_IconSmall             equ     27*xword_size
p_ImageHeight           equ     28*xword_size
p_ImageType             equ     29*xword_size
p_ImageWidth            equ     30*xword_size
p_KeepSize              equ     31*xword_size
p_Left                  equ     32*xword_size
p_Main                  equ     33*xword_size
p_MaxLength             equ     34*xword_size
p_MDIChild              equ     35*xword_size
p_Menu                  equ     36*xword_size
p_Name                  equ     37*xword_size
p_NoPrefix              equ     38*xword_size
p_Offset                equ     39*xword_size
p_Parent                equ     40*xword_size
p_PasswordChar          equ     41*xword_size
p_Pen                   equ     42*xword_size
p_Picture               equ     43*xword_size
p_RightToLeft           equ     44*xword_size
p_ScaleMode             equ     45*xword_size
p_ScrollBars            equ     46*xword_size
p_ShowMode              equ     47*xword_size
p_Stretch               equ     48*xword_size
p_TabOrder              equ     49*xword_size
p_TabStop               equ     50*xword_size
p_Text                  equ     51*xword_size
p_TextAlignment         equ     52*xword_size
p_TextLength            equ     53*xword_size
p_Timer                 equ     54*xword_size
p_TimerID               equ     55*xword_size
p_Top                   equ     56*xword_size
p_Transparent           equ     57*xword_size
p_Type                  equ     58*xword_size
p_Value                 equ     59*xword_size
p_Visible               equ     60*xword_size
p_Width                 equ     61*xword_size
p_WindowProc            equ     62*xword_size
p_WndOldControlProc     equ     63*xword_size
p_DialogID              equ     64*xword_size
p_Children              equ     65*xword_size
p_DefButton             equ     66*xword_size
p_ExStyle               equ     67*xword_size
p_Style                 equ     68*xword_size
p_ButtonStruct          equ     69*xword_size
p_OldFont               equ     70*xword_size
p_ToolTip               equ     71*xword_size
p_MouseLeave            equ     72*xword_size
p_PropertyCount         equ     73*xword_size

p_Alignment             equ     p_AutoSize
p_AlignMode             equ     p_Transparent
p_AutoRedraw            equ     p_PasswordChar
p_BandCount             equ     p_DrawingStyle
p_BandStruct            equ     p_ButtonStruct
p_Border                equ     p_CaseStyle
p_ButtonCount           equ     p_DrawingStyle
p_ButtonHeight          equ     p_CaseStyle
p_ButtonSize            equ     p_Center
p_ButtonWidth           equ     p_Center
p_Cancel                equ     p_AutoSize
p_ChildOffset           equ     p_OldFont
p_ColorQuality          equ     p_TextAlignment
p_CurrentX              equ     p_NoPrefix
p_CurrentY              equ     p_Offset
p_Default               equ     p_DisableClose
p_DisableNoScroll       equ     p_DisableClose
p_DrawFlags             equ     p_Value
p_DrawFocus             equ     p_Transparent
p_FlickerFree           equ     p_DisableClose
p_GripperCursor         equ     p_NoPrefix
p_HideSelection         equ     p_AutoSize
p_HitTest               equ     p_Offset
p_HyperColor            equ     p_ScrollBars
p_HyperLink             equ     p_MaxLength
p_ImageCount            equ     p_Transparent
p_ImageList             equ     p_DrawingStyle
p_ImageStruct           equ     p_ButtonStruct
p_Indentation           equ     p_CaseStyle
p_ItemCount             equ     p_DrawingStyle
p_ItemStruct            equ     p_ButtonStruct
p_KeyPreview            equ     p_NoPrefix
p_LvwExStyle            equ     p_TextAlignment
p_MaxValue              equ     p_ScrollBars
p_MinValue              equ     p_ShowMode
p_Modal                 equ     p_Stretch
p_MultiLine             equ     p_NoPrefix
p_NormalStyle           equ     p_Style
p_OwnerDraw             equ     p_DrawingStyle
p_PageSize              equ     p_TextAlignment
p_PannelCount           equ     p_DrawingStyle
p_PannelStruct          equ     p_ButtonStruct
p_PicturePosition       equ     p_MaxLength
p_SelStart              equ     p_Offset
p_SelEnd                equ     p_Stretch
p_TabCount              equ     p_DrawingStyle
p_TabStruct             equ     p_ButtonStruct
p_TickFrequency         equ     p_Transparent
p_ToolTipText           equ     p_ToolTip
p_VisibleRows           equ     p_MaxLength


#ifdef APP_WIN64
    align 16
#else
    align 4
#endif

;===========================================================================
; Error Object STRUCT
;===========================================================================
struc ECErrorStruct
    #ifdef APP_WIN64
        regRsp      dq ?
        regRbp      dq ?
        regRip      dq ?
    #else
        regEsp      dd ?
        regEbp      dd ?
        regEip      dd ?
    #endif
    lCode           xword ?
    Description     xword ?
ends


;===========================================================================
; App Object STRUCT
;===========================================================================
struc ECApplication
    Accel       xword ?
    CommandLine xword ?
    FileName    xword ?
    Header      xword ?
    Instance    xword ?
    Main        xword ?
    Major       xword ?
    Minor       xword ?
    Previous    xword ?
    Revision    xword ?
    Path        xword ?
    ProcessID   xword ?
    ThreadID    xword ?
ends


;===========================================================================
; StatusBar Object STRUCT
;===========================================================================
struc STBPANNEL
    nWidth      dd    ?
    nBevel      dd    ?
    lpszText    dd    ?
    #ifdef APP_WIN64
                dd    ?
    #endif
ends


;===========================================================================
; ImageList Object STRUCT
;===========================================================================
struc IMAGESTRUCT
    lType       xword ?
    lpszResID   xword ?
ends


;===========================================================================
; Header Object STRUCT
;===========================================================================
struc ITEMSTRUCT
    iImage      xword ?
    nWidth      xword ?
    lTextAlign  xword ?
    lpszText    xword ?
ends


;===========================================================================
; Rebar Object STRUCT
;===========================================================================
struc BANDSTRUCT
    lHeader     xword ?
    lLength     xword ?
    lMinHeight  xword ?
    lMinWidth   xword ?
    dwStyle     xword ?
    hBitmap     xword ?
    hWndChild   xword ?
    lpszBitmap  xword ?
    lpszChild   xword ?
    lpszText    xword ?
ends


;===========================================================================
; CPU Info STRUCT
;===========================================================================
struc CPUINFO
    Description  rb    32
    Stepping     xword ?
    Family       xword ?
    Model        xword ?
    CPUType      xword ?
    ModelID      xword ?
    FeaturesID   xword ?
    ExFeaturesID xword ?
ends


;===========================================================================
; Get properties prototypes
;===========================================================================
#ifdef APP_WIN64
    #ifdef STATIC_LIB
        from_lib ECLib64.lib
    #else
        from_lib ECDll64.lib
    #endif
#else
    #ifdef STATIC_LIB
        from_lib ECLib32.lib
    #else
        from_lib ECDll32.lib
    #endif
#endif

#ifdef APP_WIN64
    ;===========================================================================
    ; Get properties prototypes
    ;===========================================================================
    import GetAlign
    import GetAutoSize
    import GetBackColor
    import GetCancel
    import GetCaseStyle
    import GetCursorIcon
    import GetCursorShape
    import GetDefault
    import GetDrawFocus
    import GetDrawingStyle
    import GetDrawingWidth
    import GetEnabled
    import GetFlickerFree
    import GetFont
    import GetFontBold
    import GetFontItalic
    import GetFontName
    import GetFontNameA
    import GetFontNameW
    import GetFontSize
    import GetFontStrikethru
    import GetFontUnderline
    import GetForeColor
    import GetHeight
    import GetIconBig
    import GetIconSmall
    import GetLayoutRTL
    import GetLeft
    import GetMaxValue
    import GetMaxLength
    import GetMDIChild
    import GetMinValue
    import GetMultiLine
    import GetName
    import GetNameA
    import GetNameW
    import GetNoPrefix
    import GetPageSize
    import GetPasswordChar
    import GetPicture
    import GetPicturePosition
    import GetRightToLeft
    import GetScaleMode
    import GetScrollBars
    import GetShowMode
    import GetStretch
    import GetTabOrder
    import GetTabStop
    import GetText
    import GetTextA
    import GetTextW
    import GetTextAlignment
    import GetTimerInterval
    import GetTop
    import GetType
    import GetValue
    import GetVisible
    import GetVisibleRows
    import GetWidth

    ;===========================================================================
    ; Set properties prototypes
    ;===========================================================================
    import SetAlign
    import SetAutoSize
    import SetBackColor
    import SetCursorIcon
    import SetCursorShape
    import SetDefault
    import SetDrawFocus
    import SetDrawingStyle
    import SetDrawingWidth
    import SetEnabled
    import SetFlickerFree
    import SetFontBold
    import SetFontItalic
    import SetFontName
    import SetFontNameA
    import SetFontNameW
    import SetFontSize
    import SetFontStrikethru
    import SetFontUnderline
    import SetForeColor
    import SetHeight
    import SetIconBig
    import SetIconSmall
    import SetLayoutRTL
    import SetLeft
    import SetMarquee
    import SetMaxValue
    import SetMaxLength
    import SetMinValue
    import SetPageSize
    import SetPasswordChar
    import SetPicture
    import SetPicturePosition
    import SetRightToLeft
    import SetScrollBars
    import SetShowMode
    import SetTabStop
    import SetText
    import SetTextA
    import SetTextW
    import SetTimerInterval
    import SetTop
    import SetValue
    import SetVisible
    import SetVisibleRows
    import SetWidth

    ;===========================================================================
    ; Methods prototypes
    ;===========================================================================
    import AddCharToString
    import AddCharToStringA
    import AddCharToStringW
    import AddCollectionItem
    import AddCollectionItemA
    import AddCollectionItemW
    import CallDefaultProc
    import Circle
    import Create
    import CreateCollection
    import CreateCollectionA
    import CreateCollectionW
    import DeleteRegistryKey
    import DeleteRegistryKeyA
    import DeleteRegistryKeyW
    import DeleteRegistryValue
    import DeleteRegistryValueA
    import DeleteRegistryValueW
    import DestroyCollection
    import DoEvents
    import EmptyCollection
    import EndModal
    import Eof
    import FileExists
    import FileExistsA
    import FileExistsW
    import FillMemoryBlock
    import FindChar
    import FindCharA
    import FindCharW
    import FindCharRev
    import FindCharRevA
    import FindCharRevW
    import FindCollectionExactItem
    import FindCollectionExactItemA
    import FindCollectionExactItemW
    import FindCollectionItem
    import FindCollectionItemA
    import FindCollectionItemW
    import FindString
    import FindStringA
    import FindStringW
    import GetAppVersion
    import GetAppVersionA
    import GetAppVersionW
    import GetChildRect
    import GetCollectionCount
    import GetCollectionItem
    import GetCollectionItemA
    import GetCollectionItemW
    import GetCollectionItemLength
    import GetCPUInfo
    import GetCurrentX
    import GetCurrentY
    import GetMDIClient
    import GetOwnerWindow
    import GetPlatform
    import GetPlatformA
    import GetPlatformW
    import GetRegistryValue
    import GetRegistryValueA
    import GetRegistryValueW
    import GetStringLength
    import GetStringLengthA
    import GetStringLengthW
    import GetToolTipHandle
    import GetWindowItem
    import InsertCollectionItem
    import InsertCollectionItemA
    import InsertCollectionItemW
    import Is64BitVersion
    import IsAppUnicode
    import IsModal
    import IsUserAdministrator
    import IsWow64
    import Left
    import LeftA
    import LeftW
    import Line
    import LTrim
    import LTrimA
    import LTrimW
    import MakeFullPath
    import MakeFullPathA
    import MakeFullPathW
    import Mid
    import MidA
    import MidW
    import OpenTextFile
    import OpenTextFileA
    import OpenTextFileW
    import OutputBuffer
    import OutputString
    import OutputStringA
    import OutputStringW
    import Print
    import PrintA
    import PrintW
    import ReadTextLine
    import ReadTextLineA
    import ReadTextLineW
    import Refresh
    import RemoveCollectionItem
    import Right
    import RightA
    import RightW
    import RTrim
    import RTrimA
    import RTrimW
    import SetCueBanner
    import SetCurrentX
    import SetCurrentY
    import SetDefaultCursor
    import SetRegistryValue
    import SetRegistryValueA
    import SetRegistryValueW
    import SetWaitCursor
    import String
    import StringA
    import StringW
    import Trim
    import TrimA
    import TrimW
    import Update
    import Value
    import ValueA
    import ValueW
    import WriteTextLine
    import WriteTextLineA
    import WriteTextLineW
#else
    ;===========================================================================
    ; Get properties prototypes
    ;===========================================================================
    extern GetAlign alias _GetAlign@4
    extern GetAutoSize alias _GetAutoSize@4
    extern GetBackColor alias _GetBackColor@4
    extern GetCancel alias _GetCancel@4
    extern GetCaseStyle alias _GetCaseStyle@4
    extern GetCursorIcon alias _GetCursorIcon@4
    extern GetCursorShape alias _GetCursorShape@4
    extern GetDefault alias _GetDefault@4
    extern GetDrawFocus alias _GetDrawFocus@4
    extern GetDrawingStyle alias _GetDrawingStyle@4
    extern GetDrawingWidth alias _GetDrawingWidth@4
    extern GetEnabled alias _GetEnabled@4
    extern GetFlickerFree alias _GetFlickerFree@4
    extern GetFont alias _GetFont@4
    extern GetFontBold alias _GetFontBold@4
    extern GetFontItalic alias _GetFontItalic@4
    extern GetFontName alias _GetFontName@8
    extern GetFontNameA alias _GetFontNameA@8
    extern GetFontNameW alias _GetFontNameW@8
    extern GetFontSize alias _GetFontSize@4
    extern GetFontStrikethru alias _GetFontStrikethru@4
    extern GetFontUnderline alias _GetFontUnderline@4
    extern GetForeColor alias _GetForeColor@4
    extern GetHeight alias _GetHeight@4
    extern GetIconBig alias _GetIconBig@4
    extern GetIconSmall alias _GetIconSmall@4
    extern GetLayoutRTL alias _GetLayoutRTL@4
    extern GetLeft alias _GetLeft@4
    extern GetMaxValue alias _GetMaxValue@4
    extern GetMaxLength alias _GetMaxLength@4
    extern GetMDIChild alias _GetMDIChild@4
    extern GetMinValue alias _GetMinValue@4
    extern GetMultiLine alias _GetMultiLine@4
    extern GetName alias _GetName@8
    extern GetNameA alias _GetNameA@8
    extern GetNameW alias _GetNameW@8
    extern GetNoPrefix alias _GetNoPrefix@4
    extern GetPageSize alias _GetPageSize@4
    extern GetPasswordChar alias _GetPasswordChar@4
    extern GetPicture alias _GetPicture@4
    extern GetPicturePosition alias _GetPicturePosition@4
    extern GetRightToLeft alias _GetRightToLeft@4
    extern GetScaleMode alias _GetScaleMode@4
    extern GetScrollBars alias _GetScrollBars@4
    extern GetShowMode alias _GetShowMode@4
    extern GetStretch alias _GetStretch@4
    extern GetTabOrder alias _GetTabOrder@4
    extern GetTabStop alias _GetTabStop@4
    extern GetText alias _GetText@8
    extern GetTextA alias _GetTextA@8
    extern GetTextW alias _GetTextW@8
    extern GetTextAlignment alias _GetTextAlignment@4
    extern GetTimerInterval alias _GetTimerInterval@4
    extern GetTop alias _GetTop@4
    extern GetType alias _GetType@4
    extern GetValue alias _GetValue@4
    extern GetVisible alias _GetVisible@4
    extern GetVisibleRows alias _GetVisibleRows@4
    extern GetWidth alias _GetWidth@4

    ;===========================================================================
    ; Set properties prototypes
    ;===========================================================================
    extern SetAlign alias _SetAlign@8
    extern SetAutoSize alias _SetAutoSize@8
    extern SetBackColor alias _SetBackColor@8
    extern SetCursorIcon alias _SetCursorIcon@8
    extern SetCursorShape alias _SetCursorShape@8
    extern SetDefault alias _SetDefault@8
    extern SetDrawFocus alias _SetDrawFocus@8
    extern SetDrawingStyle alias _SetDrawingStyle@8
    extern SetDrawingWidth alias _SetDrawingWidth@8
    extern SetEnabled alias _SetEnabled@8
    extern SetFlickerFree alias _SetFlickerFree@8
    extern SetFontBold alias _SetFontBold@8
    extern SetFontItalic alias _SetFontItalic@8
    extern SetFontName alias _SetFontName@8
    extern SetFontNameA alias _SetFontNameA@8
    extern SetFontNameW alias _SetFontNameW@8
    extern SetFontSize alias _SetFontSize@8
    extern SetFontStrikethru alias _SetFontStrikethru@8
    extern SetFontUnderline alias _SetFontUnderline@8
    extern SetForeColor alias _SetForeColor@8
    extern SetHeight alias _SetHeight@8
    extern SetIconBig alias _SetIconBig@8
    extern SetIconSmall alias _SetIconSmall@8
    extern SetLayoutRTL alias _SetLayoutRTL@8
    extern SetLeft alias _SetLeft@8
    extern SetMarquee alias _SetMarquee@12
    extern SetMaxValue alias _SetMaxValue@8
    extern SetMaxLength alias _SetMaxLength@8
    extern SetMinValue alias _SetMinValue@8
    extern SetPageSize alias _SetPageSize@8
    extern SetPasswordChar alias _SetPasswordChar@8
    extern SetPicture alias _SetPicture@8
    extern SetPicturePosition alias _SetPicturePosition@8
    extern SetRightToLeft alias _SetRightToLeft@8
    extern SetScrollBars alias _SetScrollBars@8
    extern SetShowMode alias _SetShowMode@8
    extern SetTabStop alias _SetTabStop@8
    extern SetText alias _SetText@8
    extern SetTextA alias _SetTextA@8
    extern SetTextW alias _SetTextW@8
    extern SetTimerInterval alias _SetTimerInterval@8
    extern SetTop alias _SetTop@8
    extern SetValue alias _SetValue@8
    extern SetVisible alias _SetVisible@8
    extern SetVisibleRows alias _SetVisibleRows@8
    extern SetWidth alias _SetWidth@8

    ;===========================================================================
    ; Methods prototypes
    ;===========================================================================
    extern AddCharToString alias _AddCharToString@8
    extern AddCharToStringA alias _AddCharToStringA@8
    extern AddCharToStringW alias _AddCharToStringW@8
    extern AddCollectionItem alias _AddCollectionItem@8
    extern AddCollectionItemA alias _AddCollectionItemA@8
    extern AddCollectionItemW alias _AddCollectionItemW@8
    extern CallDefaultProc alias _CallDefaultProc@16
    extern Circle alias _Circle@24
    extern Create alias _Create@16
    extern CreateCollection alias _CreateCollection@4
    extern CreateCollectionA alias _CreateCollectionA@4
    extern CreateCollectionW alias _CreateCollectionW@4
    extern DeleteRegistryKey alias _DeleteRegistryKey@8
    extern DeleteRegistryKeyA alias _DeleteRegistryKeyA@8
    extern DeleteRegistryKeyW alias _DeleteRegistryKeyW@8
    extern DeleteRegistryValue alias _DeleteRegistryValue@12
    extern DeleteRegistryValueA alias _DeleteRegistryValueA@12
    extern DeleteRegistryValueW alias _DeleteRegistryValueW@12
    extern DestroyCollection alias _DestroyCollection@4
    extern DoEvents alias _DoEvents@0
    extern EmptyCollection alias _EmptyCollection@4
    extern EndModal alias _EndModal@8
    extern Eof alias _Eof@4
    extern FileExists alias _FileExists@4
    extern FileExistsA alias _FileExistsA@4
    extern FillMemoryBlock alias _FillMemoryBlock@12
    extern FileExistsW alias _FileExistsW@4
    extern FindChar alias _FindChar@8
    extern FindCharA alias _FindCharA@8
    extern FindCharW alias _FindCharW@8
    extern FindCharRev alias _FindCharRev@8
    extern FindCharRevA alias _FindCharRevA@8
    extern FindCharRevW alias _FindCharRevW@8
    extern FindCollectionExactItem alias _FindCollectionExactItem@8
    extern FindCollectionExactItemA alias _FindCollectionExactItemA@8
    extern FindCollectionExactItemW alias _FindCollectionExactItemW@8
    extern FindCollectionItem alias _FindCollectionItem@8
    extern FindCollectionItemA alias _FindCollectionItemA@8
    extern FindCollectionItemW alias _FindCollectionItemW@8
    extern GetAppVersion alias _GetAppVersion@4
    extern GetAppVersionA alias _GetAppVersionA@4
    extern GetAppVersionW alias _GetAppVersionW@4
    extern GetChildRect alias _GetChildRect@8
    extern GetCollectionCount alias _GetCollectionCount@4
    extern GetCollectionItem alias _GetCollectionItem@12
    extern GetCollectionItemA alias _GetCollectionItemA@12
    extern GetCollectionItemW alias _GetCollectionItemW@12
    extern GetCollectionItemLength alias _GetCollectionItemLength@8
    extern GetCPUInfo alias _GetCPUInfo@4
    extern GetCurrentX alias _GetCurrentX@4
    extern GetCurrentY alias _GetCurrentY@4
    extern GetMDIClient alias _GetMDIClient@4
    extern GetOwnerWindow alias _GetOwnerWindow@4
    extern GetPlatform alias _GetPlatform@4
    extern GetPlatformA alias _GetPlatformA@4
    extern GetPlatformW alias _GetPlatformW@4
    extern GetRegistryValue alias _GetRegistryValue@16
    extern GetRegistryValueA alias _GetRegistryValueA@16
    extern GetRegistryValueW alias _GetRegistryValueW@16
    extern GetStringLength alias _GetStringLength@4
    extern GetStringLengthA alias _GetStringLengthA@4
    extern GetStringLengthW alias _GetStringLengthW@4
    extern GetToolTipHandle alias _GetToolTipHandle@4
    extern GetWindowItem alias _GetWindowItem@8
    extern InsertCollectionItem alias _InsertCollectionItem@12
    extern InsertCollectionItemA alias _InsertCollectionItemA@12
    extern InsertCollectionItemW alias _InsertCollectionItemW@12
    extern Is64BitVersion alias _Is64BitVersion@0
    extern IsAppUnicode alias _IsAppUnicode@0
    extern IsModal alias _IsModal@4
    extern IsUserAdministrator alias _IsUserAdministrator@0
    extern IsWow64 alias _IsWow64@4
    extern Left alias _Left@8
    extern LeftA alias _LeftA@8
    extern LeftW alias _LeftW@8
    extern Line alias _Line@28
    extern LTrim alias _LTrim@4
    extern LTrimA alias _LTrimA@4
    extern LTrimW alias _LTrimW@4
    extern MakeFullPath alias _MakeFullPath@8
    extern MakeFullPathA alias _MakeFullPathA@8
    extern MakeFullPathW alias _MakeFullPathW@8
    extern Mid alias _Mid@12
    extern MidA alias _MidA@12
    extern MidW alias _MidW@12
    extern OpenTextFile alias _OpenTextFile@12
    extern OpenTextFileA alias _OpenTextFileA@12
    extern OpenTextFileW alias _OpenTextFileW@12
    extern OutputBuffer alias _OutputBuffer@8
    extern OutputString alias _OutputString@8
    extern OutputStringA alias _OutputStringA@8
    extern OutputStringW alias _OutputStringW@8
    extern Print alias _Print@8
    extern PrintA alias _PrintA@8
    extern PrintW alias _PrintW@8
    extern ReadTextLine alias _ReadTextLine@8
    extern ReadTextLineA alias _ReadTextLineA@8
    extern ReadTextLineW alias _ReadTextLineW@8
    extern Refresh alias _Refresh@4
    extern RemoveCollectionItem alias _RemoveCollectionItem@8
    extern Right alias _Right@8
    extern RightA alias _RightA@8
    extern RightW alias _RightW@8
    extern RTrim alias _RTrim@4
    extern RTrimA alias _RTrimA@4
    extern RTrimW alias _RTrimW@4
    extern SetCueBanner alias _SetCueBanner@12
    extern SetCurrentX alias _SetCurrentX@8
    extern SetCurrentY alias _SetCurrentY@8
    extern SetDefaultCursor alias _SetDefaultCursor@0
    extern SetRegistryValue alias _SetRegistryValue@16
    extern SetRegistryValueA alias _SetRegistryValueA@16
    extern SetRegistryValueW alias _SetRegistryValueW@16
    extern SetWaitCursor alias _SetWaitCursor@4
    extern String alias _String@12
    extern StringA alias _StringA@12
    extern StringW alias _StringW@12
    extern Trim alias _Trim@4
    extern TrimA alias _TrimA@4
    extern TrimW alias _TrimW@4
    extern Update alias _Update@4
    extern Value alias _Value@4
    extern ValueA alias _ValueA@4
    extern ValueW alias _ValueW@4
    extern WriteTextLine alias _WriteTextLine@8
    extern WriteTextLineA alias _WriteTextLineA@8
    extern WriteTextLineW alias _WriteTextLineW@8
#endif
