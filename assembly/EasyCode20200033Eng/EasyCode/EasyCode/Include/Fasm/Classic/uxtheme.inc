; ====================================================;
;                                                     ;
;     uxtheme.inc for EC v2 Fasm classic projects     ;
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

import uxtheme,\
BeginBufferedAnimation, 'BeginBufferedAnimation',\
BeginBufferedPaint, 'BeginBufferedPaint',\
BeginPanningFeedback, 'BeginPanningFeedback',\
BufferedPaintClear, 'BufferedPaintClear',\
BufferedPaintInit, 'BufferedPaintInit',\
BufferedPaintRenderAnimation, 'BufferedPaintRenderAnimation',\
BufferedPaintSetAlpha, 'BufferedPaintSetAlpha',\
BufferedPaintStopAllAnimations, 'BufferedPaintStopAllAnimations',\
BufferedPaintUnInit, 'BufferedPaintUnInit',\
CloseThemeData, 'CloseThemeData',\
DrawThemeBackground, 'DrawThemeBackground',\
DrawThemeBackgroundEx, 'DrawThemeBackgroundEx',\
DrawThemeEdge, 'DrawThemeEdge',\
DrawThemeIcon, 'DrawThemeIcon',\
DrawThemeParentBackground, 'DrawThemeParentBackground',\
DrawThemeParentBackgroundEx, 'DrawThemeParentBackgroundEx',\
DrawThemeText, 'DrawThemeText',\
DrawThemeTextEx, 'DrawThemeTextEx',\
EnableThemeDialogTexture, 'EnableThemeDialogTexture',\
EnableTheming, 'EnableTheming',\
EndBufferedAnimation, 'EndBufferedAnimation',\
EndBufferedPaint, 'EndBufferedPaint',\
EndPanningFeedback, 'EndPanningFeedback',\
GetBufferedPaintBits, 'GetBufferedPaintBits',\
GetBufferedPaintDC, 'GetBufferedPaintDC',\
GetBufferedPaintTargetDC, 'GetBufferedPaintTargetDC',\
GetBufferedPaintTargetRect, 'GetBufferedPaintTargetRect',\
GetCurrentThemeName, 'GetCurrentThemeName',\
GetThemeAnimationProperty, 'GetThemeAnimationProperty',\
GetThemeAnimationTransform, 'GetThemeAnimationTransform',\
GetThemeAppProperties, 'GetThemeAppProperties',\
GetThemeBackgroundContentRect, 'GetThemeBackgroundContentRect',\
GetThemeBackgroundExtent, 'GetThemeBackgroundExtent',\
GetThemeBackgroundRegion, 'GetThemeBackgroundRegion',\
GetThemeBitmap, 'GetThemeBitmap',\
GetThemeBool, 'GetThemeBool',\
GetThemeColor, 'GetThemeColor',\
GetThemeDocumentationProperty, 'GetThemeDocumentationProperty',\
GetThemeEnumValue, 'GetThemeEnumValue',\
GetThemeFilename, 'GetThemeFilename',\
GetThemeFont, 'GetThemeFont',\
GetThemeInt, 'GetThemeInt',\
GetThemeIntList, 'GetThemeIntList',\
GetThemeMargins, 'GetThemeMargins',\
GetThemeMetric, 'GetThemeMetric',\
GetThemePartSize, 'GetThemePartSize',\
GetThemePosition, 'GetThemePosition',\
GetThemePropertyOrigin, 'GetThemePropertyOrigin',\
GetThemeRect, 'GetThemeRect',\
GetThemeStream, 'GetThemeStream',\
GetThemeString, 'GetThemeString',\
GetThemeSysBool, 'GetThemeSysBool',\
GetThemeSysColor, 'GetThemeSysColor',\
GetThemeSysColorBrush, 'GetThemeSysColorBrush',\
GetThemeSysFont, 'GetThemeSysFont',\
GetThemeSysInt, 'GetThemeSysInt',\
GetThemeSysSize, 'GetThemeSysSize',\
GetThemeSysString, 'GetThemeSysString',\
GetThemeTextExtent, 'GetThemeTextExtent',\
GetThemeTextMetrics, 'GetThemeTextMetrics',\
GetThemeTimingFunction, 'GetThemeTimingFunction',\
GetThemeTransitionDuration, 'GetThemeTransitionDuration',\
GetWindowTheme, 'GetWindowTheme',\
HitTestThemeBackground, 'HitTestThemeBackground',\
IsAppThemed, 'IsAppThemed',\
IsCompositionActive, 'IsCompositionActive',\
IsThemeActive, 'IsThemeActive',\
IsThemeBackgroundPartiallyTransparent, 'IsThemeBackgroundPartiallyTransparent',\
IsThemeDialogTextureEnabled, 'IsThemeDialogTextureEnabled',\
IsThemePartDefined, 'IsThemePartDefined',\
OpenThemeData, 'OpenThemeData',\
OpenThemeDataEx, 'OpenThemeDataEx',\
SetThemeAppProperties, 'SetThemeAppProperties',\
SetWindowTheme, 'SetWindowTheme',\
SetWindowThemeAttribute, 'SetWindowThemeAttribute',\
UpdatePanningFeedback, 'UpdatePanningFeedback'

end if ;UXTHEME_INC
