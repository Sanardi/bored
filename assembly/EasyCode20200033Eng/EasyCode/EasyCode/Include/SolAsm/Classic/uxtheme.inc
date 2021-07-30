; ====================================================;
;                                                     ;
;    uxtheme.inc for EC v2 SolAsm classic projects    ;
;                   (version 1.0.4)                   ;
;                                                     ;
;         Copyright © Ramon Sala - 2018-2020          ;
;                                                     ;
; ====================================================;

#ifndef UXTHEME_INC
UXTHEME_INC equ 1

MAX_THEMECOLOR                                  equ     64
MAX_THEMESIZE                                   equ     64

;TA_PROPERTY
TAP_FLAGS                                       equ     0
TAP_TRANSFORMCOUNT                              equ     1
TAP_STAGGERDELAY                                equ     2
TAP_STAGGERDELAYCAP                             equ     3
TAP_STAGGERDELAYFACTOR                          equ     4
TAP_ZORDER                                      equ     5

;TA_PROPERTY_FLAG
TAPF_NONE                                       equ     0H
TAPF_HASSTAGGER                                 equ     1H
TAPF_ISRTLAWARE                                 equ     2H
TAPF_ALLOWCOLLECTION                            equ     4H
TAPF_HASBACKGROUND                              equ     8H 
TAPF_HASPERSPECTIVE                             equ     10H

TATT_TRANSLATE_2D                               equ     0
TATT_SCALE_2D                                   equ     1
TATT_OPACITY                                    equ     2
TATT_CLIP                                       equ     3

;TA_TRANSFORM_FLAG
TATF_NONE                                       equ     0
TATF_TARGETVALUES_USER                          equ     1
TATF_HASINITIALVALUES                           equ     2
TATF_HASORIGINVALUES                            equ     4

;TA_TIMINGFUNCTION_TYPE
TTFT_UNDEFINED                                  equ     0
TTFT_CUBIC_BEZIER                               equ     1

OTD_FORCE_RECT_SIZING                           equ     1
OTD_NONCLIENT                                   equ     2
OTD_VALIDBITS                                   equ     <OTD_FORCE_RECT_SIZING or OTD_NONCLIENT>

DTBG_CLIPRECT                                   equ     1H
DTBG_DRAWSOLID                                  equ     2H
DTBG_OMITBORDER                                 equ     4H
DTBG_OMITCONTENT                                equ     8H
DTBG_COMPUTINGREGION                            equ     10H
DTBG_MIRRORDC                                   equ     20H 
DTBG_NOMIRROR                                   equ     40H
DTBG_VALIDBITS                                  equ     <DTBG_CLIPRECT or DTBG_DRAWSOLID or DTBG_OMITBORDER or DTBG_OMITCONTENT or DTBG_COMPUTINGREGION or DTBG_MIRRORDC or DTBG_NOMIRROR>

DTT_GRAYED                                      equ     1H
DTT_FLAGS2VALIDBITS                             equ     (DTT_GRAYED)

;THEMESIZE
TS_MIN                                          equ     0
TS_TRUE                                         equ     1
TS_DRAW                                         equ     2

HTTB_BACKGROUNDSEG                              equ     0H
HTTB_FIXEDBORDER                                equ     2H
HTTB_CAPTION                                    equ     4H
HTTB_RESIZINGBORDER_LEFT                        equ     10H
HTTB_RESIZINGBORDER_TOP                         equ     20H
HTTB_RESIZINGBORDER_RIGHT                       equ     40H
HTTB_RESIZINGBORDER_BOTTOM                      equ     80H
HTTB_RESIZINGBORDER                             equ     <HTTB_RESIZINGBORDER_LEFT or HTTB_RESIZINGBORDER_TOP or HTTB_RESIZINGBORDER_RIGHT or HTTB_RESIZINGBORDER_BOTTOM>
HTTB_SIZINGTEMPLATE                             equ     100H
HTTB_SYSTEMSIZINGMARGINS                        equ     200H

;PROPERTYORIGIN
PO_STATE                                        equ     0
PO_PART                                         equ     1
PO_CLASS                                        equ     2
PO_GLOBAL                                       equ     3
PO_NOTFOUND                                     equ     4

ETDT_DISABLE                                    equ     1H
ETDT_ENABLE                                     equ     2H
ETDT_USETABTEXTURE                              equ     4H
ETDT_ENABLETAB                                  equ     <ETDT_ENABLE or ETDT_USETABTEXTURE>

#if NTDDI_VERSION >= NTDDI_VISTA
    ETDT_USEAEROWIZARDTABTEXTURE                equ     8H
    ETDT_ENABLEAEROWIZARDTAB                    equ     <ETDT_ENABLE or ETDT_USEAEROWIZARDTABTEXTURE>
    ETDT_VALIDBITS                              equ     <ETDT_DISABLE or ETDT_ENABLE or ETDT_USETABTEXTURE or ETDT_USEAEROWIZARDTABTEXTURE>
#endif

STAP_ALLOW_NONCLIENT                            equ     <1 shl 0>
STAP_ALLOW_CONTROLS                             equ     <1 shl 1>
STAP_ALLOW_WEBCONTENT                           equ     <1 shl 2>
STAP_VALIDBITS                                  equ     <STAP_ALLOW_NONCLIENT or STAP_ALLOW_CONTROLS or STAP_ALLOW_WEBCONTENT>

;SZ_THDOCPROP_DISPLAYNAME                        du      'DisplayName',0
;SZ_THDOCPROP_CANONICALNAME                      du      'ThemeName',0
;SZ_THDOCPROP_TOOLTIP                            du      'ToolTip',0
;SZ_THDOCPROP_AUTHOR                             du      'author',0

GBF_DIRECT                                      equ     1H
GBF_COPY                                        equ     2H
GBF_VALIDBITS                                   equ     <GBF_DIRECT or GBF_COPY>

#if NTDDI_VERSION >= NTDDI_VISTA
    DTPB_WINDOWDC                               equ     1H
    DTPB_USECTLCOLORSTATIC                      equ     2H
    DTPB_USEERASEBKGND                          equ     4H

    ;WINDOWTHEMEATTRIBUTETYPE
    WTA_NONCLIENT                               equ     1

    WTNCA_NODRAWCAPTION                         equ     1H
    WTNCA_NODRAWICON                            equ     2H
    WTNCA_NOSYSMENU                             equ     4H
    WTNCA_NOMIRRORHELP                          equ     8H
    WTNCA_VALIDBITS                             equ     <WTNCA_NODRAWCAPTION or WTNCA_NODRAWICON or WTNCA_NOSYSMENU or WTNCA_NOMIRRORHELP>
#endif

DTT_TEXTCOLOR                                   equ     <1 shl 0>
DTT_BORDERCOLOR                                 equ     <1 shl 1>
DTT_SHADOWCOLOR                                 equ     <1 shl 2>
DTT_SHADOWTYPE                                  equ     <1 shl 3>
DTT_SHADOWOFFSET                                equ     <1 shl 4>
DTT_BORDERSIZE                                  equ     <1 shl 5>
DTT_FONTPROP                                    equ     <1 shl 6>
DTT_COLORPROP                                   equ     <1 shl 7>
DTT_STATEID                                     equ     <1 shl 8>
DTT_CALCRECT                                    equ     <1 shl 9>
DTT_APPLYOVERLAY                                equ     <1 shl 10>
DTT_GLOWSIZE                                    equ     <1 shl 11>
DTT_CALLBACK                                    equ     <1 shl 12>
DTT_COMPOSITED                                  equ     <1 shl 13>
DTT_VALIDBITS                                   equ     <DTT_TEXTCOLOR or DTT_BORDERCOLOR or DTT_SHADOWCOLOR or DTT_SHADOWTYPE or DTT_SHADOWOFFSET or DTT_BORDERSIZE or DTT_FONTPROP or DTT_COLORPROP or DTT_STATEID or DTT_CALCRECT or DTT_APPLYOVERLAY or DTT_GLOWSIZE or DTT_COMPOSITED>

define HPAINTBUFFER                             xword

;_BP_BUFFERFORMAT
BPBF_COMPATIBLEBITMAP                           equ     0
BPBF_DIB                                        equ     1
BPBF_TOPDOWNDIB                                 equ     2
BPBF_TOPDOWNMONODIB                             equ     3

;_BP_ANIMATIONSTYLE
BPAS_NONE                                       equ     0
BPAS_LINEAR                                     equ     1
BPAS_CUBIC                                      equ     2
BPAS_SINE                                       equ     3

BPPF_ERASE                                      equ     1H
BPPF_NOCLIP                                     equ     2H
BPPF_NONCLIENT                                  equ     4H

uahLoadInit                                     equ     0
uahStop                                         equ     1
uahShutdown                                     equ     2

BCN_FIRST                                       equ     (0-1250)
BCN_LAST                                        equ     (0-1350)
BCN_HOTITEMCHANGE                               equ     (BCN_FIRST+0001H)
BCN_DROPDOWN                                    equ     (BCN_FIRST+0002H)

TMT_CSSNAME                                     equ     1401
TMT_XMLNAME                                     equ     1402

;======================================== Structures ======================================;
struc TA_TRANSFORM
    eTransformType     dd ?
    dwTimingFunctionId dd ?
    dwStartTime        dd ?
    dwDurationTime     dd ?
    eFlags             dd ?
ends

struc TA_TRANSFORM_2D
    header    TA_TRANSFORM ?
    rX        dd           ? ;REAL4
    rY        dd           ? ;REAL4
    rInitialX dd           ? ;REAL4
    rInitialY dd           ? ;REAL4
    rOriginX  dd           ? ;REAL4
    rOriginY  dd           ? ;REAL4
ends

struc TA_TRANSFORM_OPACITY
    header          TA_TRANSFORM ? ;REAL4
    rOpacity        dd           ? ;REAL4
    rInitialOpacity dd           ? ;REAL4
ends

struc TA_TRANSFORM_CLIP
    header         TA_TRANSFORM ?
    rLeft          dd           ? ;REAL4
    rTop           dd           ? ;REAL4
    rRight         dd           ? ;REAL4
    rBottom        dd           ? ;REAL4
    rInitialLeft   dd           ? ;REAL4
    rInitialTop    dd           ? ;REAL4
    rInitialRight  dd           ? ;REAL4
    rInitialBottom dd           ? ;REAL4
ends

struc TA_TIMINGFUNCTION
    eTimingFunctionType dd ?
ends

struc TA_CUBIC_BEZIER
    header TA_TIMINGFUNCTION ?
    rX0    dd                ? ;REAL4
    rY0    dd                ? ;REAL4
    rX1    dd                ? ;REAL4
    rY1    dd                ? ;REAL4
ends

struc DTBGOPTS
    dwSize  dd   ?
    dwFlags dd   ?
    rcClip  RECT ?
ends

struc MARGINS
    cxLeftWidth    dd ?
    cxRightWidth   dd ?
    cyTopHeight    dd ?
    cyBottomHeight dd ?
ends

#if NTDDI_VERSION >= NTDDI_VISTA
    INTLIST
        iValueCount dd ?
        iValues     rd  MAX_INTLIST_COUNT
    ends

    WTA_OPTIONS
        dwFlags dd ?
        dwMask  dd ?
    ends
#endif

struc DTTOPTS
    dwSize              dd       ?
    dwFlags             dd       ?
    crText              COLORREF ?
    crBorder            COLORREF ?
    crShadow            COLORREF ?
    iTextShadowType     dd       ?
    ptShadowOffset      POINT    ?
    iBorderSize         dd       ?
    iFontPropId         dd       ?
    iColorPropId        dd       ?
    iStateId            dd       ?
    fApplyOverlay       dd       ?
    iGlowSize           dd       ?
    pfnDrawTextCallback xword    ?
    lParam              xword    ?
ends

struc BP_ANIMATIONPARAMS
    cbSize     dd ?
    dwFlags    dd ?
    style      dd ?
    dwDuration dd ?
ends

struc BP_PAINTPARAMS
    cbSize         dd    ?
    dwFlags        dd    ?
    prcExclude     xword ?
    pBlendFunction xword ?
ends

struc NMBCHOTITEM
    hdr     NMHDR ?
    dwFlags dd    ?
ends

;======================================== Functions =======================================;
#if COFF_FORMAT == 1
    from_lib uxtheme.lib
#else
    from_dll uxtheme.dll
#endif

#if NTDDI_VERSION >= NTDDI_VISTA
    import BeginBufferedAnimation
    import BeginBufferedPaint
#endif
#if NTDDI_VERSION >= NTDDI_WIN7
    import BeginPanningFeedback
#endif
#if NTDDI_VERSION >= NTDDI_VISTA
    import BufferedPaintClear
    import BufferedPaintInit
    import BufferedPaintRenderAnimation
    import BufferedPaintSetAlpha
    import BufferedPaintStopAllAnimations
    import BufferedPaintUnInit
#endif
import CloseThemeData
#if NTDDI_VERSION >= NTDDI_WIN8
    #ifndef DllCanUnloadNow
        import DllCanUnloadNow
    #endif
    import DllGetActivationFactory
    #ifndef DllGetClassObject
        import DllGetClassObject
    #endif
#endif
import DrawThemeBackground
import DrawThemeBackgroundEx
import DrawThemeEdge
import DrawThemeIcon
import DrawThemeParentBackground
#if NTDDI_VERSION >= NTDDI_VISTA
    import DrawThemeParentBackgroundEx
    import DrawThemeTextEx
#endif
import DrawThemeText
import EnableThemeDialogTexture
import EnableTheming
#if NTDDI_VERSION >= NTDDI_VISTA
    import EndBufferedAnimation
    import EndBufferedPaint
#endif
#if NTDDI_VERSION >= NTDDI_WIN7
    import EndPanningFeedback
#endif
#if NTDDI_VERSION >= NTDDI_VISTA
    import GetBufferedPaintBits
    import GetBufferedPaintDC
    import GetBufferedPaintTargetDC
    import GetBufferedPaintTargetRect
#endif
#if NTDDI_VERSION >= NTDDI_WIN81
    import GetColorFromPreference
    import GetImmersiveColorFromColorSetEx
    import GetImmersiveUserColorSetPreference
#endif
import GetCurrentThemeName
#if NTDDI_VERSION >= NTDDI_WIN8
    import GetThemeAnimationProperty
    import GetThemeAnimationTransform
#endif
import GetThemeAppProperties
import GetThemeBackgroundContentRect
import GetThemeBackgroundExtent
import GetThemeBackgroundRegion
#if NTDDI_VERSION >= NTDDI_VISTA
    import GetThemeBitmap
#endif
import GetThemeBool
import GetThemeColor
import GetThemeDocumentationProperty
import GetThemeEnumValue
import GetThemeFilename
import GetThemeFont
import GetThemeInt
import GetThemeIntList
import GetThemeMargins
import GetThemeMetric
import GetThemePartSize
import GetThemePosition
import GetThemePropertyOrigin
import GetThemeRect
import GetThemeStream
import GetThemeString
import GetThemeSysBool
import GetThemeSysColor
import GetThemeSysColorBrush
import GetThemeSysFont
import GetThemeSysInt
import GetThemeSysSize
import GetThemeSysString
import GetThemeTextExtent
import GetThemeTextMetrics
#if NTDDI_VERSION >= NTDDI_WIN8
    import GetThemeTimingFunction
#endif
#if NTDDI_VERSION >= NTDDI_VISTA
    import GetThemeTransitionDuration
#endif
#if NTDDI_VERSION >= NTDDI_WIN81
    import GetUserColorPreference
#endif
import GetWindowTheme
import HitTestThemeBackground
import IsAppThemed
#if NTDDI_VERSION >= NTDDI_VISTA
    import IsCompositionActive
#endif
import IsThemeActive
import IsThemeBackgroundPartiallyTransparent
import IsThemeDialogTextureEnabled
import IsThemePartDefined
import OpenThemeData
#if NTDDI_VERSION >= NTDDI_VISTA
    import OpenThemeDataEx
#endif
import SetThemeAppProperties
import SetWindowTheme
#if NTDDI_VERSION >= NTDDI_VISTA
    import SetWindowThemeAttribute
#endif
import ThemeInitApiHook
#if NTDDI_VERSION >= NTDDI_WIN7
    #if NTDDI_VERSION != NTDDI_WIN81
        import UpdatePanningFeedback
    #endif
#endif

#endif ;UXTHEME_INC
