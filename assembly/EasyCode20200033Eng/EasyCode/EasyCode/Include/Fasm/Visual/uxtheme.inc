; ====================================================;
;                                                     ;
;     uxtheme.inc for EC v2 Fasm visual projects      ;
;                   (version 1.0.2)                   ;
;                                                     ;
;         Copyright © Ramon Sala - 2018-2020          ;
;                                                     ;
; ====================================================;

if  ~defined UXTHEME_INC
define UXTHEME_INC 1

if ~defined TYPEDEF
    macro TYPEDEF type, base {
        restruc type
        purge type

        struc type [v] \{ \common . base v \}
        macro type [v] \{ \common base v \}

        virtual at 0
            local label, sizeof
            label type ?
            sizeof = $ - label
            sizeof.#type = sizeof
            SIZEOF.#type = sizeof
            SizeOf.#type = sizeof
        end virtual
    }
end if

if ~defined COLORREF
    TYPEDEF                   COLORREF, dd
end if

if ~defined BOOL
    TYPEDEF                   BOOL, dd
end if

if ~defined LPARAM
    TYPEDEF                   LPARAM, xptr
end if

if ~defined HANDLE
    TYPEDEF                   HANDLE, xptr
end if

MAX_THEMECOLOR                equ     64
MAX_THEMESIZE                 equ     64

;TA_PROPERTY
TAP_FLAGS                     equ      0
TAP_TRANSFORMCOUNT            equ      1
TAP_STAGGERDELAY              equ      2
TAP_STAGGERDELAYCAP           equ      3
TAP_STAGGERDELAYFACTOR        equ      4
TAP_ZORDER                    equ      5

;TA_PROPERTY_FLAG
TAPF_NONE                     equ      0H
TAPF_HASSTAGGER               equ      1H
TAPF_ISRTLAWARE               equ      2H
TAPF_ALLOWCOLLECTION          equ      4H
TAPF_HASBACKGROUND            equ      8H 
TAPF_HASPERSPECTIVE           equ     10H

;TA_TRANSFORM_TYPE
TYPEDEF                       TA_TRANSFORM_TYPE, dd
TATT_TRANSLATE_2D             equ      0
TATT_SCALE_2D                 equ      1
TATT_OPACITY                  equ      2
TATT_CLIP                     equ      3

;TA_TRANSFORM_FLAG
TYPEDEF                       TA_TRANSFORM_FLAG, dd
TATF_NONE                     equ      0
TATF_TARGETVALUES_USER        equ      1
TATF_HASINITIALVALUES         equ      2
TATF_HASORIGINVALUES          equ      4

struct TA_TRANSFORM
        eTransformType        TA_TRANSFORM_TYPE     ?
        dwTimingFunctionId    dd                    ?
        dwStartTime           dd                    ?
        dwDurationTime        dd                    ?
        eFlags                TA_TRANSFORM_FLAG     ?
ends

struct TA_TRANSFORM_2D
       header                 TA_TRANSFORM
       rX                     dd                    ? ; Float
       rY                     dd                    ? ; Float 
       rInitialX              dd                    ? ; Float
       rInitialY              dd                    ? ; Float
       rOriginX               dd                    ? ; Float
       rOriginY               dd                    ? ; Float
ends

struct TA_TRANSFORM_OPACITY
       header                 TA_TRANSFORM
       rOpacity               dd                    ? ; Float
       rInitialOpacity        dd                    ? ; Float
ends

struct TA_TRANSFORM_CLIP
       header                 TA_TRANSFORM
       rLeft                  dd                    ? ; Float
       rTop                   dd                    ? ; Float
       rRight                 dd                    ? ; Float
       rBottom                dd                    ? ; Float
       rInitialLeft           dd                    ? ; Float
       rInitialTop            dd                    ? ; Float
       rInitialRight          dd                    ? ; Float
       rInitialBottom         dd                    ? ; Float
ends

;TA_TIMINGFUNCTION_TYPE
TYPEDEF                       TA_TIMINGFUNCTION_TYPE, dd
TTFT_UNDEFINED                equ                   0
TTFT_CUBIC_BEZIER             equ                   1

struct TA_TIMINGFUNCTION
       eTimingFunctionType    TA_TIMINGFUNCTION_TYPE ?
ends

struct TA_CUBIC_BEZIER
       header                 TA_TIMINGFUNCTION
       rX0                    dd                    ? ; Float
       rY0                    dd                    ? ; Float
       rX1                    dd                    ? ; Float
       rY1                    dd                    ? ; Float
ends

OTD_FORCE_RECT_SIZING         equ                   1
OTD_NONCLIENT                 equ                   2
OTD_VALIDBITS                 equ                   (OTD_FORCE_RECT_SIZING or OTD_NONCLIENT)

DTBG_CLIPRECT                 equ                   1H
DTBG_DRAWSOLID                equ                   2H
DTBG_OMITBORDER               equ                   4H
DTBG_OMITCONTENT              equ                   8H
DTBG_COMPUTINGREGION          equ                  10H
DTBG_MIRRORDC                 equ                  20H 
DTBG_NOMIRROR                 equ                  40H
DTBG_VALIDBITS                equ                  (DTBG_CLIPRECT or DTBG_DRAWSOLID or DTBG_OMITBORDER or DTBG_OMITCONTENT or \
                                                   DTBG_COMPUTINGREGION or DTBG_MIRRORDC or DTBG_NOMIRROR)

BCN_FIRST                     equ                  (0 - 1250)
BCN_LAST                      equ                  (0 - 1350)
BCN_HOTITEMCHANGE             equ                  (BCN_FIRST + 0001H)
BCN_DROPDOWN                  equ                  (BCN_FIRST + 0002H)

TMT_CSSNAME                   equ                  1401
TMT_XMLNAME                   equ                  1402

struct DTBGOPTS
      dwSize                  dd                    ? 
      dwFlags                 dd                    ? 
      rcClip                  RECT
ends

struct NMBCHOTITEM
      hdr                     NMHDR
      dwFlags                 dd                    ?
ends

DTT_GRAYED                    equ                   1H
DTT_FLAGS2VALIDBITS           equ                   (DTT_GRAYED)

;THEMESIZE
TS_MIN                        equ                   0
TS_TRUE                       equ                   1
TS_DRAW                       equ                   2

HTTB_BACKGROUNDSEG            equ                   0H
HTTB_FIXEDBORDER              equ                   2H
HTTB_CAPTION                  equ                   4H
HTTB_RESIZINGBORDER_LEFT      equ                  10H
HTTB_RESIZINGBORDER_TOP       equ                  20H
HTTB_RESIZINGBORDER_RIGHT     equ                  40H
HTTB_RESIZINGBORDER_BOTTOM    equ                  80H
HTTB_RESIZINGBORDER           equ                 (HTTB_RESIZINGBORDER_LEFT or HTTB_RESIZINGBORDER_TOP or HTTB_RESIZINGBORDER_RIGHT or HTTB_RESIZINGBORDER_BOTTOM)
HTTB_SIZINGTEMPLATE           equ                 100H
HTTB_SYSTEMSIZINGMARGINS      equ                 200H

struct MARGINS
      cxLeftWidth             dd                    ? 
      cxRightWidth            dd                    ? 
      cyTopHeight             dd                    ? 
      cyBottomHeight          dd                    ? 
ends

if (NTDDI_VERSION >= NTDDI_VISTA)
    MAX_INTLIST_COUNT         equ                  402
else
    MAX_INTLIST_COUNT         equ                   10
end if

struct INTLIST
      iValueCount             dd                    ?
      iValues                 dd                    MAX_INTLIST_COUNT DUP (?)
ends


;PROPERTYORIGIN
PO_STATE                      equ                    0
PO_PART                       equ                    1
PO_CLASS                      equ                    2
PO_GLOBAL                     equ                    3
PO_NOTFOUND                   equ                    4

ETDT_DISABLE                  equ                    1H
ETDT_ENABLE                   equ                    2H
ETDT_USETABTEXTURE            equ                    4H
ETDT_ENABLETAB                equ                    (ETDT_ENABLE or ETDT_USETABTEXTURE)


if (NTDDI_VERSION >= NTDDI_VISTA)
    ETDT_USEAEROWIZARDTABTEXTURE equ                8H
    ETDT_ENABLEAEROWIZARDTAB  equ                   (ETDT_ENABLE or ETDT_USEAEROWIZARDTABTEXTURE)
    ETDT_VALIDBITS            equ                   (ETDT_DISABLE or ETDT_ENABLE or ETDT_USETABTEXTURE or ETDT_USEAEROWIZARDTABTEXTURE)
end if

STAP_ALLOW_NONCLIENT          equ                   (1 shl 0)
STAP_ALLOW_CONTROLS           equ                   (1 shl 1)
STAP_ALLOW_WEBCONTENT         equ                   (1 shl 2)
STAP_VALIDBITS                equ                   (STAP_ALLOW_NONCLIENT or STAP_ALLOW_CONTROLS or STAP_ALLOW_WEBCONTENT)


SZ_THDOCPROP_DISPLAYNAME      du                    'DisplayName', 0
SZ_THDOCPROP_CANONICALNAME    du                    'ThemeName', 0
SZ_THDOCPROP_TOOLTIP          du                    'ToolTip', 0
SZ_THDOCPROP_AUTHOR           du                    'author', 0


GBF_DIRECT                    equ                    1H
GBF_COPY                      equ                    2H
GBF_VALIDBITS                 equ                    (GBF_DIRECT or GBF_COPY)

if (NTDDI_VERSION >= NTDDI_VISTA)
    DTPB_WINDOWDC             equ                    1H
    DTPB_USECTLCOLORSTATIC    equ                    2H
    DTPB_USEERASEBKGND        equ                    4H

    ;WINDOWTHEMEATTRIBUTETYPE
    WTA_NONCLIENT             equ                    1

    struct WTA_OPTIONS
        dwFlags               dd                     ?
        dwMask                dd                     ?
    ends

    WTNCA_NODRAWCAPTION       equ                    1H
    WTNCA_NODRAWICON          equ                    2H
    WTNCA_NOSYSMENU           equ                    4H
    WTNCA_NOMIRRORHELP        equ                    8H
    WTNCA_VALIDBITS           equ                    (WTNCA_NODRAWCAPTION or WTNCA_NODRAWICON or WTNCA_NOSYSMENU or WTNCA_NOMIRRORHELP)
end if


DTT_TEXTCOLOR                 equ                    (1 shl 0)   
DTT_BORDERCOLOR               equ                    (1 shl 1)     
DTT_SHADOWCOLOR               equ                    (1 shl 2)   
DTT_SHADOWTYPE                equ                    (1 shl 3)    
DTT_SHADOWOFFSET              equ                    (1 shl 4)  
DTT_BORDERSIZE                equ                    (1 shl 5)   
DTT_FONTPROP                  equ                    (1 shl 6)     
DTT_COLORPROP                 equ                    (1 shl 7)    
DTT_STATEID                   equ                    (1 shl 8)   
DTT_CALCRECT                  equ                    (1 shl 9)   
DTT_APPLYOVERLAY              equ                    (1 shl 10)  
DTT_GLOWSIZE                  equ                    (1 shl 11)    
DTT_CALLBACK                  equ                    (1 shl 12)     
DTT_COMPOSITED                equ                    (1 shl 13)    
DTT_VALIDBITS                 equ                    (DTT_TEXTCOLOR or DTT_BORDERCOLOR or DTT_SHADOWCOLOR or DTT_SHADOWTYPE or \
                                                      DTT_SHADOWOFFSET or DTT_BORDERSIZE or DTT_FONTPROP or DTT_COLORPROP or \
                                                      DTT_STATEID or DTT_CALCRECT or DTT_APPLYOVERLAY or DTT_GLOWSIZE or DTT_COMPOSITED)

struct DTTOPTS
      dwSize                  dd                     ?
      dwFlags                 dd                     ?
      crText                  COLORREF               ?
      crBorder                COLORREF               ?
      crShadow                COLORREF               ?
      iTextShadowType         dd                     ?
      ptShadowOffset          POINT
      iBorderSize             dd                     ?
      iFontPropId             dd                     ?
      iColorPropId            dd                     ?
      iStateId                dd                     ?
      fApplyOverlay           BOOL                   ?
      iGlowSize               dd                     ?
      pfnDrawTextCallback     xptr                   ?
      lParam                  LPARAM                 ?
ends

TYPEDEF                       HPAINTBUFFER, HANDLE


;_BP_BUFFERFORMAT
BPBF_COMPATIBLEBITMAP         equ                    0
BPBF_DIB                      equ                    1
BPBF_TOPDOWNDIB               equ                    2
BPBF_TOPDOWNMONODIB           equ                    3

;_BP_ANIMATIONSTYLE
TYPEDEF                       BP_ANIMATIONSTYLE, dd
BPAS_NONE                     equ                    0
BPAS_LINEAR                   equ                    1
BPAS_CUBIC                    equ                    2
BPAS_SINE                     equ                    3

struct BP_ANIMATIONPARAMS
      cbSize                  dd                     ?
      dwFlags                 dd                     ?
      style                   BP_ANIMATIONSTYLE      ?
      dwDuration              dd                     ?
ends

BPPF_ERASE                    equ                    1H
BPPF_NOCLIP                   equ                    2H
BPPF_NONCLIENT                equ                    4H

struct BP_PAINTPARAMS
      cbSize                  dd                     ?
      dwFlags                 dd                     ?
      prcExclude              xptr                   ?
      pBlendFunction          xptr                   ?
ends

if defined APP_WIN64
    if (NTDDI_VERSION >= NTDDI_VISTA)
       extrn '__imp_BeginBufferedAnimation' as BeginBufferedAnimation:qword
       extrn '__imp_BeginBufferedPaint' as BeginBufferedPaint:qword
    end if
    if (NTDDI_VERSION >= NTDDI_WIN7)
       extrn '__imp_BeginPanningFeedback' as BeginPanningFeedback:qword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_BufferedPaintClear' as BufferedPaintClear:qword
        extrn '__imp_BufferedPaintInit' as BufferedPaintInit:qword
        extrn '__imp_BufferedPaintRenderAnimation' as BufferedPaintRenderAnimation:qword
        extrn '__imp_BufferedPaintSetAlpha' as BufferedPaintSetAlpha:qword
        extrn '__imp_BufferedPaintStopAllAnimations' as BufferedPaintStopAllAnimations:qword
        extrn '__imp_BufferedPaintUnInit' as BufferedPaintUnInit:qword
    end if
    extrn '__imp_CloseThemeData' as CloseThemeData:qword
    if (NTDDI_VERSION >= NTDDI_WIN8)
        extrn '__imp_DllCanUnloadNow' as DllCanUnloadNow:qword
        extrn '__imp_DllGetActivationFactory' as DllGetActivationFactory:qword
    end if
    extrn '__imp_DrawThemeBackground' as DrawThemeBackground:qword
    extrn '__imp_DrawThemeBackgroundEx' as DrawThemeBackgroundEx:qword
    extrn '__imp_DrawThemeEdge' as DrawThemeEdge:qword
    extrn '__imp_DrawThemeIcon' as DrawThemeIcon:qword
    extrn '__imp_DrawThemeParentBackground' as DrawThemeParentBackground:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_DrawThemeParentBackgroundEx' as DrawThemeParentBackgroundEx:qword
        extrn '__imp_DrawThemeTextEx' as DrawThemeTextEx:qword
    end if
    extrn '__imp_DrawThemeText' as DrawThemeText:qword
    extrn '__imp_EnableThemeDialogTexture' as EnableThemeDialogTexture:qword
    extrn '__imp_EnableTheming' as EnableTheming:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_EndBufferedAnimation' as EndBufferedAnimation:qword
        extrn '__imp_EndBufferedPaint' as EndBufferedPaint:qword
    end if
    if (NTDDI_VERSION >= NTDDI_WIN7)
        extrn '__imp_EndPanningFeedback' as EndPanningFeedback:qword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_GetBufferedPaintBits' as GetBufferedPaintBits:qword
        extrn '__imp_GetBufferedPaintDC' as GetBufferedPaintDC:qword
        extrn '__imp_GetBufferedPaintTargetDC' as GetBufferedPaintTargetDC:qword
        extrn '__imp_GetBufferedPaintTargetRect' as GetBufferedPaintTargetRect:qword
    end if
    if (NTDDI_VERSION >= NTDDI_WIN81)
        extrn '__imp_GetColorFromPreference' as GetColorFromPreference:qword
        extrn '__imp_GetImmersiveColorFromColorSetEx' as GetImmersiveColorFromColorSetEx:qword
        extrn '__imp_GetImmersiveUserColorSetPreference' as GetImmersiveUserColorSetPreference:qword
    end if
    extrn '__imp_GetCurrentThemeName' as GetCurrentThemeName:qword
    if (NTDDI_VERSION >= NTDDI_WIN8)
        extrn '__imp_GetThemeAnimationProperty' as GetThemeAnimationProperty:qword
        extrn '__imp_GetThemeAnimationTransform' as GetThemeAnimationTransform:qword
    end if
    extrn '__imp_GetThemeAppProperties' as GetThemeAppProperties:qword
    extrn '__imp_GetThemeBackgroundContentRect' as GetThemeBackgroundContentRect:qword
    extrn '__imp_GetThemeBackgroundExtent' as GetThemeBackgroundExtent:qword
    extrn '__imp_GetThemeBackgroundRegion' as GetThemeBackgroundRegion:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_GetThemeBitmap' as GetThemeBitmap:qword
    end if
    extrn '__imp_GetThemeBool' as GetThemeBool:qword
    extrn '__imp_GetThemeColor' as GetThemeColor:qword
    extrn '__imp_GetThemeDocumentationProperty' as GetThemeDocumentationProperty:qword
    extrn '__imp_GetThemeEnumValue' as GetThemeEnumValue:qword
    extrn '__imp_GetThemeFilename' as GetThemeFilename:qword
    extrn '__imp_GetThemeFont' as GetThemeFont:qword
    extrn '__imp_GetThemeInt' as GetThemeInt:qword
    extrn '__imp_GetThemeIntList' as GetThemeIntList:qword
    extrn '__imp_GetThemeMargins' as GetThemeMargins:qword
    extrn '__imp_GetThemeMetric' as GetThemeMetric:qword
    extrn '__imp_GetThemePartSize' as GetThemePartSize:qword
    extrn '__imp_GetThemePosition' as GetThemePosition:qword
    extrn '__imp_GetThemePropertyOrigin' as GetThemePropertyOrigin:qword
    extrn '__imp_GetThemeRect' as GetThemeRect:qword
    extrn '__imp_GetThemeStream' as GetThemeStream:qword
    extrn '__imp_GetThemeString' as GetThemeString:qword
    extrn '__imp_GetThemeSysBool' as GetThemeSysBool:qword
    extrn '__imp_GetThemeSysColor' as GetThemeSysColor:qword
    extrn '__imp_GetThemeSysColorBrush' as GetThemeSysColorBrush:qword
    extrn '__imp_GetThemeSysFont' as GetThemeSysFont:qword
    extrn '__imp_GetThemeSysInt' as GetThemeSysInt:qword
    extrn '__imp_GetThemeSysSize' as GetThemeSysSize:qword
    extrn '__imp_GetThemeSysString' as GetThemeSysString:qword
    extrn '__imp_GetThemeTextExtent' as GetThemeTextExtent:qword
    extrn '__imp_GetThemeTextMetrics' as GetThemeTextMetrics:qword
    if (NTDDI_VERSION >= NTDDI_WIN8)
        extrn '__imp_GetThemeTimingFunction' as GetThemeTimingFunction:qword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_GetThemeTransitionDuration' as GetThemeTransitionDuration:qword
    end if
    if (NTDDI_VERSION >= NTDDI_WIN81)
        extrn '__imp_GetUserColorPreference' as GetUserColorPreference:qword
    end if
    extrn '__imp_GetWindowTheme' as GetWindowTheme:qword
    extrn '__imp_HitTestThemeBackground' as HitTestThemeBackground:qword
    extrn '__imp_IsAppThemed' as IsAppThemed:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_IsCompositionActive' as IsCompositionActive:qword
    end if
    extrn '__imp_IsThemeActive' as IsThemeActive:qword
    extrn '__imp_IsThemeBackgroundPartiallyTransparent' as IsThemeBackgroundPartiallyTransparent:qword
    extrn '__imp_IsThemeDialogTextureEnabled' as IsThemeDialogTextureEnabled:qword
    extrn '__imp_IsThemePartDefined' as IsThemePartDefined:qword
    extrn '__imp_OpenThemeData' as OpenThemeData:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_OpenThemeDataEx' as OpenThemeDataEx:qword
    end if
    extrn '__imp_SetThemeAppProperties' as SetThemeAppProperties:qword
    extrn '__imp_SetWindowTheme' as SetWindowTheme:qword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_SetWindowThemeAttribute' as SetWindowThemeAttribute:qword
    end if
    extrn '__imp_ThemeInitApiHook' as ThemeInitApiHook:qword
    if (NTDDI_VERSION >= NTDDI_WIN7)
        if (NTDDI_VERSION <> NTDDI_WIN81)
            extrn '__imp_UpdatePanningFeedback' as UpdatePanningFeedback:qword
        end if
    end if
else
    if (NTDDI_VERSION >= NTDDI_VISTA)
       extrn '__imp__BeginBufferedAnimation@32' as BeginBufferedAnimation:dword
       extrn '__imp__BeginBufferedPaint@20' as BeginBufferedPaint:dword
    end if
    if (NTDDI_VERSION >= NTDDI_WIN7)
       extrn '__imp__BeginPanningFeedback@4' as BeginPanningFeedback:dword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__BufferedPaintClear@8' as BufferedPaintClear:dword
        extrn '__imp__BufferedPaintInit@0' as BufferedPaintInit:dword
        extrn '__imp__BufferedPaintRenderAnimation@8' as BufferedPaintRenderAnimation:dword
        extrn '__imp__BufferedPaintSetAlpha@12' as BufferedPaintSetAlpha:dword
        extrn '__imp__BufferedPaintStopAllAnimations@4' as BufferedPaintStopAllAnimations:dword
        extrn '__imp__BufferedPaintUnInit@0' as BufferedPaintUnInit:dword
    end if
    extrn '__imp__CloseThemeData@4' as CloseThemeData:dword
    if (NTDDI_VERSION >= NTDDI_WIN8)
        extrn '__imp__DllCanUnloadNow@0' as DllCanUnloadNow:dword
        extrn '__imp__DllGetActivationFactory@8' as DllGetActivationFactory:dword
    end if
    extrn '__imp__DrawThemeBackground@24' as DrawThemeBackground:dword
    extrn '__imp__DrawThemeBackgroundEx@24' as DrawThemeBackgroundEx:dword
    extrn '__imp__DrawThemeEdge@32' as DrawThemeEdge:dword
    extrn '__imp__DrawThemeIcon@28' as DrawThemeIcon:dword
    extrn '__imp__DrawThemeParentBackground@12' as DrawThemeParentBackground:dword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__DrawThemeParentBackgroundEx@16' as DrawThemeParentBackgroundEx:dword
        extrn '__imp_DrawThemeTextEx@36' as DrawThemeTextEx:dword
    end if
    extrn '__imp__DrawThemeText@36' as DrawThemeText:dword
    extrn '__imp__EnableThemeDialogTexture@8' as EnableThemeDialogTexture:dword
    extrn '__imp__EnableTheming@4' as EnableTheming:dword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__EndBufferedAnimation@8' as EndBufferedAnimation:dword
        extrn '__imp__EndBufferedPaint@8' as EndBufferedPaint:dword
    end if
    if (NTDDI_VERSION >= NTDDI_WIN7)
        extrn '__imp__EndPanningFeedback@8' as EndPanningFeedback:dword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__GetBufferedPaintBits@12' as GetBufferedPaintBits:dword
        extrn '__imp__GetBufferedPaintDC@4' as GetBufferedPaintDC:dword
        extrn '__imp__GetBufferedPaintTargetDC@4' as GetBufferedPaintTargetDC:dword
        extrn '__imp__GetBufferedPaintTargetRect@8' as GetBufferedPaintTargetDC:dword
    end if
    if (NTDDI_VERSION >= NTDDI_WIN81)
        extrn '__imp__GetColorFromPreference@4' as GetColorFromPreference:dword
        extrn '__imp__GetImmersiveColorFromColorSetEx@16' as GetImmersiveColorFromColorSetEx:dword
        extrn '__imp__GetImmersiveUserColorSetPreference@8' as GetImmersiveUserColorSetPreference:dword
    end if
    extrn '__imp__GetCurrentThemeName@24' as GetCurrentThemeName:dword
    if (NTDDI_VERSION >= NTDDI_WIN8)
        extrn '__imp__GetThemeAnimationProperty@28' as GetThemeAnimationProperty:dword
        extrn '__imp__GetThemeAnimationTransform@28' as GetThemeAnimationTransform:dword
    end if
    extrn '__imp__GetThemeAppProperties@0' as GetThemeAppProperties:dword
    extrn '__imp__GetThemeBackgroundContentRect@24' as GetThemeBackgroundContentRect:dword
    extrn '__imp__GetThemeBackgroundExtent@24' as GetThemeBackgroundExtent:dword
    extrn '__imp__GetThemeBackgroundRegion@24' as GetThemeBackgroundRegion:dword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__GetThemeBitmap@24' as GetThemeBitmap:dword
    end if
    extrn '__imp__GetThemeBool@20' as GetThemeBool:dword
    extrn '__imp__GetThemeColor@20' as GetThemeColor:dword
    extrn '__imp__GetThemeDocumentationProperty@16' as GetThemeDocumentationProperty:dword
    extrn '__imp__GetThemeEnumValue@20' as GetThemeEnumValue:dword
    extrn '__imp__GetThemeFilename@24' as GetThemeFilename:dword
    extrn '__imp__GetThemeFont@24' as GetThemeFont:dword
    extrn '__imp__GetThemeInt@20' as GetThemeInt:dword
    extrn '__imp__GetThemeIntList@20' as GetThemeIntList:dword
    extrn '__imp__GetThemeMargins@28' as GetThemeMargins:dword
    extrn '__imp__GetThemeMetric@24' as GetThemeMetric:dword
    extrn '__imp__GetThemePartSize@28' as GetThemePartSize:dword
    extrn '__imp__GetThemePosition@20' as GetThemePosition:dword
    extrn '__imp__GetThemePropertyOrigin@20' as GetThemePropertyOrigin:dword
    extrn '__imp__GetThemeRect@20' as GetThemeRect:dword
    ;extrn '__imp__GetThemeStream@28' as GetThemeStream:dword ;Not present in MASM32 uxtheme.ib
    extrn '__imp__GetThemeString@24' as GetThemeString:dword
    extrn '__imp__GetThemeSysBool@8' as GetThemeSysBool:dword
    extrn '__imp__GetThemeSysColor@8' as GetThemeSysColor:dword
    extrn '__imp__GetThemeSysColorBrush@8' as GetThemeSysColorBrush:dword
    extrn '__imp__GetThemeSysFont@12' as GetThemeSysFont:dword
    extrn '__imp__GetThemeSysInt@12' as GetThemeSysInt:dword
    extrn '__imp__GetThemeSysSize@8' as GetThemeSysSize:dword
    extrn '__imp__GetThemeSysString@16' as GetThemeSysString:dword
    extrn '__imp__GetThemeTextExtent@36' as GetThemeTextExtent:dword
    extrn '__imp__GetThemeTextMetrics@20' as GetThemeTextMetrics:dword
    if (NTDDI_VERSION >= NTDDI_WIN8)
        extrn '__imp__GetThemeTimingFunction@20' as GetThemeTimingFunction:dword
    end if
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__GetThemeTransitionDuration@24' as GetThemeTransitionDuration:dword
    end if
    if (NTDDI_VERSION >= NTDDI_WIN81)
        extrn '__imp__GetUserColorPreference@8' as GetThemeTransitionDuration:dword
    end if
    extrn '__imp__GetWindowTheme@4' as GetWindowTheme:dword
    extrn '__imp__HitTestThemeBackground@40' as HitTestThemeBackground:dword
    extrn '__imp__IsAppThemed@0' as IsAppThemed:dword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__IsCompositionActive@0' as IsCompositionActive:dword
    end if
    extrn '__imp__IsThemeActive@0' as IsThemeActive:dword
    extrn '__imp__IsThemeBackgroundPartiallyTransparent@12' as IsThemeBackgroundPartiallyTransparent:dword
    extrn '__imp__IsThemeDialogTextureEnabled@4' as IsThemeDialogTextureEnabled:dword
    extrn '__imp__IsThemePartDefined@12' as IsThemePartDefined:dword
    extrn '__imp__OpenThemeData@8' as OpenThemeData:dword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__OpenThemeDataEx@12' as OpenThemeDataEx:dword
    end if
    extrn '__imp__SetThemeAppProperties@4' as SetThemeAppProperties:dword
    extrn '__imp__SetWindowTheme@12' as SetWindowTheme:dword
    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__SetWindowThemeAttribute@16' as SetWindowTheme:dword
    end if
    ;extrn '__imp__ThemeInitApiHook@8' as ThemeInitApiHook:dword ;Not present in MASM32 uxtheme.ib
    if (NTDDI_VERSION >= NTDDI_WIN7)
        if (NTDDI_VERSION <> NTDDI_WIN81)
            extrn '__imp__UpdatePanningFeedback@16' as UpdatePanningFeedback:dword
        end if
    end if
end if

end if ;UXTHEME_INC
