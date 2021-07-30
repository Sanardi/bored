; =====================================================;
;                                                      ;
;  uxtheme.inc for Easy Code 2.0 64-bit Masm projects  ;
;                   (version 1.0.5)                    ;
;                                                      ;
;       Copyright © Héctor A. Medina - 2015-2020       ;
;                                                      ;
; =====================================================;

IFNDEF UXTHEME_INC
UXTHEME_INC   EQU     1

MAX_THEMECOLOR                                  EQU     64
MAX_THEMESIZE                                   EQU     64

;TA_PROPERTY
TAP_FLAGS                                       EQU     0
TAP_TRANSFORMCOUNT                              EQU     1
TAP_STAGGERDELAY                                EQU     2
TAP_STAGGERDELAYCAP                             EQU     3
TAP_STAGGERDELAYFACTOR                          EQU     4
TAP_ZORDER                                      EQU     5

;TA_PROPERTY_FLAG
TAPF_NONE                                       EQU     0H
TAPF_HASSTAGGER                                 EQU     1H
TAPF_ISRTLAWARE                                 EQU     2H
TAPF_ALLOWCOLLECTION                            EQU     4H
TAPF_HASBACKGROUND                              EQU     8H 
TAPF_HASPERSPECTIVE                             EQU     10H

;TA_TRANSFORM_TYPE
TA_TRANSFORM_TYPE                               TYPEDEF DWORD
TATT_TRANSLATE_2D                               EQU     0
TATT_SCALE_2D                                   EQU     1
TATT_OPACITY                                    EQU     2
TATT_CLIP                                       EQU     3

;TA_TRANSFORM_FLAG
TA_TRANSFORM_FLAG                               TYPEDEF DWORD
TATF_NONE                                       EQU     0
TATF_TARGETVALUES_USER                          EQU     1
TATF_HASINITIALVALUES                           EQU     2
TATF_HASORIGINVALUES                            EQU     4

;TA_TIMINGFUNCTION_TYPE
TA_TIMINGFUNCTION_TYPE                          TYPEDEF DWORD
TTFT_UNDEFINED                                  EQU     0
TTFT_CUBIC_BEZIER                               EQU     1

OTD_FORCE_RECT_SIZING                           EQU     1
OTD_NONCLIENT                                   EQU     2
OTD_VALIDBITS                                   EQU     (OTD_FORCE_RECT_SIZING OR OTD_NONCLIENT)

DTBG_CLIPRECT                                   EQU     1H
DTBG_DRAWSOLID                                  EQU     2H
DTBG_OMITBORDER                                 EQU     4H
DTBG_OMITCONTENT                                EQU     8H
DTBG_COMPUTINGREGION                            EQU     10H
DTBG_MIRRORDC                                   EQU     20H 
DTBG_NOMIRROR                                   EQU     40H
DTBG_VALIDBITS                                  EQU     (DTBG_CLIPRECT OR DTBG_DRAWSOLID OR DTBG_OMITBORDER OR DTBG_OMITCONTENT OR DTBG_COMPUTINGREGION OR DTBG_MIRRORDC OR DTBG_NOMIRROR)

DTT_GRAYED                                      EQU     1H
DTT_FLAGS2VALIDBITS                             EQU     (DTT_GRAYED)

;THEMESIZE
TS_MIN                                          EQU     0
TS_TRUE                                         EQU     1
TS_DRAW                                         EQU     2

HTTB_BACKGROUNDSEG                              EQU     0H
HTTB_FIXEDBORDER                                EQU     2H
HTTB_CAPTION                                    EQU     4H
HTTB_RESIZINGBORDER_LEFT                        EQU     10H
HTTB_RESIZINGBORDER_TOP                         EQU     20H
HTTB_RESIZINGBORDER_RIGHT                       EQU     40H
HTTB_RESIZINGBORDER_BOTTOM                      EQU     80H
HTTB_RESIZINGBORDER                             EQU     (HTTB_RESIZINGBORDER_LEFT OR HTTB_RESIZINGBORDER_TOP OR HTTB_RESIZINGBORDER_RIGHT OR HTTB_RESIZINGBORDER_BOTTOM)
HTTB_SIZINGTEMPLATE                             EQU     100H
HTTB_SYSTEMSIZINGMARGINS                        EQU     200H

IF NTDDI_VERSION GE NTDDI_VISTA
    MAX_INTLIST_COUNT                           EQU     402
ELSE
    MAX_INTLIST_COUNT                           EQU     10
ENDIF

;PROPERTYORIGIN
PO_STATE                                        EQU     0
PO_PART                                         EQU     1
PO_CLASS                                        EQU     2
PO_GLOBAL                                       EQU     3
PO_NOTFOUND                                     EQU     4

ETDT_DISABLE                                    EQU     1H
ETDT_ENABLE                                     EQU     2H
ETDT_USETABTEXTURE                              EQU     4H
ETDT_ENABLETAB                                  EQU     (ETDT_ENABLE OR ETDT_USETABTEXTURE)

IF NTDDI_VERSION GE NTDDI_VISTA
ETDT_USEAEROWIZARDTABTEXTURE                    EQU     8H
ETDT_ENABLEAEROWIZARDTAB                        EQU     (ETDT_ENABLE OR ETDT_USEAEROWIZARDTABTEXTURE)
ETDT_VALIDBITS                                  EQU     (ETDT_DISABLE OR ETDT_ENABLE OR ETDT_USETABTEXTURE OR ETDT_USEAEROWIZARDTABTEXTURE)
ENDIF

STAP_ALLOW_NONCLIENT                            EQU     (1 SHL 0)
STAP_ALLOW_CONTROLS                             EQU     (1 SHL 1)
STAP_ALLOW_WEBCONTENT                           EQU     (1 SHL 2)
STAP_VALIDBITS                                  EQU     (STAP_ALLOW_NONCLIENT OR STAP_ALLOW_CONTROLS OR STAP_ALLOW_WEBCONTENT)


SZ_THDOCPROP_DISPLAYNAME                        EQU     L("DisplayName")
SZ_THDOCPROP_CANONICALNAME                      EQU     L("ThemeName")
SZ_THDOCPROP_TOOLTIP                            EQU     L("ToolTip")
SZ_THDOCPROP_AUTHOR                             EQU     L("author")

GBF_DIRECT                                      EQU     1H
GBF_COPY                                        EQU     2H
GBF_VALIDBITS                                   EQU     (GBF_DIRECT OR GBF_COPY)

IF NTDDI_VERSION GE NTDDI_VISTA
    DTPB_WINDOWDC                               EQU     1H
    DTPB_USECTLCOLORSTATIC                      EQU     2H
    DTPB_USEERASEBKGND                          EQU     4H

    ;WINDOWTHEMEATTRIBUTETYPE
    WTA_NONCLIENT                               EQU     1

    WTNCA_NODRAWCAPTION                         EQU     1H
    WTNCA_NODRAWICON                            EQU     2H
    WTNCA_NOSYSMENU                             EQU     4H
    WTNCA_NOMIRRORHELP                          EQU     8H
    WTNCA_VALIDBITS                             EQU     (WTNCA_NODRAWCAPTION OR WTNCA_NODRAWICON OR WTNCA_NOSYSMENU OR WTNCA_NOMIRRORHELP)
ENDIF

DTT_TEXTCOLOR                                   EQU     (1 SHL 0)   
DTT_BORDERCOLOR                                 EQU     (1 SHL 1)     
DTT_SHADOWCOLOR                                 EQU     (1 SHL 2)   
DTT_SHADOWTYPE                                  EQU     (1 SHL 3)    
DTT_SHADOWOFFSET                                EQU     (1 SHL 4)  
DTT_BORDERSIZE                                  EQU     (1 SHL 5)   
DTT_FONTPROP                                    EQU     (1 SHL 6)     
DTT_COLORPROP                                   EQU     (1 SHL 7)    
DTT_STATEID                                     EQU     (1 SHL 8)   
DTT_CALCRECT                                    EQU     (1 SHL 9)   
DTT_APPLYOVERLAY                                EQU     (1 SHL 10)  
DTT_GLOWSIZE                                    EQU     (1 SHL 11)    
DTT_CALLBACK                                    EQU     (1 SHL 12)     
DTT_COMPOSITED                                  EQU     (1 SHL 13)    
DTT_VALIDBITS                                   EQU     (DTT_TEXTCOLOR OR DTT_BORDERCOLOR OR DTT_SHADOWCOLOR OR DTT_SHADOWTYPE OR \
                                                        DTT_SHADOWOFFSET OR DTT_BORDERSIZE OR DTT_FONTPROP OR DTT_COLORPROP OR \
                                                        DTT_STATEID OR DTT_CALCRECT OR DTT_APPLYOVERLAY OR DTT_GLOWSIZE OR DTT_COMPOSITED)

HPAINTBUFFER                                    TYPEDEF HANDLE

;_BP_BUFFERFORMAT
BPBF_COMPATIBLEBITMAP                           EQU     0
BPBF_DIB                                        EQU     1
BPBF_TOPDOWNDIB                                 EQU     2
BPBF_TOPDOWNMONODIB                             EQU     3

;_BP_ANIMATIONSTYLE
BP_ANIMATIONSTYLE                               TYPEDEF DWORD
BPAS_NONE                                       EQU     0
BPAS_LINEAR                                     EQU     1
BPAS_CUBIC                                      EQU     2
BPAS_SINE                                       EQU     3

uahLoadInit                                     EQU     0
uahStop                                         EQU     1
uahShutdown                                     EQU     2

BPPF_ERASE                                      EQU     1H
BPPF_NOCLIP                                     EQU     2H
BPPF_NONCLIENT                                  EQU     4H

BCN_FIRST                                       EQU     (0 - 1250)
BCN_LAST                                        EQU     (0 - 1350)
BCN_HOTITEMCHANGE                               EQU     (BCN_FIRST + 0001H)
BCN_DROPDOWN                                    EQU     (BCN_FIRST + 0002H)

TMT_CSSNAME                                     EQU     1401
TMT_XMLNAME                                     EQU     1402


;======================================== Structures ======================================;
TA_TRANSFORM STRUCT ALIGNMODE
    eTransformType     TA_TRANSFORM_TYPE ?
    dwTimingFunctionId DWORD             ?
    dwStartTime        DWORD             ?
    dwDurationTime     DWORD             ?
    eFlags             TA_TRANSFORM_FLAG ?
TA_TRANSFORM ENDS

TA_TRANSFORM_2D STRUCT ALIGNMODE
    header    TA_TRANSFORM <>
    rX        REAL4        ?
    rY        REAL4        ?
    rInitialX REAL4        ?
    rInitialY REAL4        ?
    rOriginX  REAL4        ?
    rOriginY  REAL4        ?
TA_TRANSFORM_2D ENDS

TA_TRANSFORM_OPACITY STRUCT ALIGNMODE
    header          TA_TRANSFORM <>
    rOpacity        REAL4        ?
    rInitialOpacity REAL4        ?
TA_TRANSFORM_OPACITY ENDS

TA_TRANSFORM_CLIP STRUCT ALIGNMODE
    header         TA_TRANSFORM <>
    rLeft          REAL4        ?
    rTop           REAL4        ?
    rRight         REAL4        ?
    rBottom        REAL4        ?
    rInitialLeft   REAL4        ?
    rInitialTop    REAL4        ?
    rInitialRight  REAL4        ?
    rInitialBottom REAL4        ?
TA_TRANSFORM_CLIP ENDS

TA_TIMINGFUNCTION STRUCT ALIGNMODE
    eTimingFunctionType TA_TIMINGFUNCTION_TYPE ?
TA_TIMINGFUNCTION ENDS

TA_CUBIC_BEZIER STRUCT ALIGNMODE
    header TA_TIMINGFUNCTION <>
    rX0    REAL4             ?
    rY0    REAL4             ?
    rX1    REAL4             ?
    rY1    REAL4             ?
TA_CUBIC_BEZIER ENDS

DTBGOPTS STRUCT ALIGNMODE
    dwSize  DWORD ?
    dwFlags DWORD ?
    rcClip  RECT  <>
DTBGOPTS ENDS

MARGINS STRUCT ALIGNMODE
    cxLeftWidth    DWORD ?
    cxRightWidth   DWORD ?
    cyTopHeight    DWORD ?
    cyBottomHeight DWORD ?
MARGINS ENDS

IF NTDDI_VERSION GE NTDDI_VISTA
    INTLIST STRUCT ALIGNMODE
        iValueCount DWORD ?
        iValues     DWORD  MAX_INTLIST_COUNT DUP (?)
    INTLIST ENDS

    WTA_OPTIONS STRUCT ALIGNMODE
        dwFlags DWORD ?
        dwMask  DWORD ?
    WTA_OPTIONS ENDS
ENDIF

DTTOPTS STRUCT ALIGNMODE
    dwSize              DWORD    ?
    dwFlags             DWORD    ?
    crText              COLORREF ?
    crBorder            COLORREF ?
    crShadow            COLORREF ?
    iTextShadowType     DWORD    ?
    ptShadowOffset      POINT    <>
    iBorderSize         DWORD    ?
    iFontPropId         DWORD    ?
    iColorPropId        DWORD    ?
    iStateId            DWORD    ?
    fApplyOverlay       BOOL     ?
    iGlowSize           DWORD    ?
    pfnDrawTextCallback XPTR     ?
    lParam              LPARAM   ?
DTTOPTS ENDS

BP_ANIMATIONPARAMS STRUCT ALIGNMODE
    cbSize     DWORD             ?
    dwFlags    DWORD             ?
    style      BP_ANIMATIONSTYLE ?
    dwDuration DWORD             ?
BP_ANIMATIONPARAMS ENDS

BP_PAINTPARAMS STRUCT ALIGNMODE
    cbSize         DWORD ?
    dwFlags        DWORD ?
    prcExclude     XPTR  ?
    pBlendFunction XPTR  ?
BP_PAINTPARAMS ENDS

NMBCHOTITEM STRUCT ALIGNMODE
    hdr     NMHDR <>
    dwFlags DWORD ?
NMBCHOTITEM ENDS


;======================================== Functions =======================================;
IF (NTDDI_VERSION GE NTDDI_VISTA)
    BeginBufferedAnimation PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
    BeginBufferedPaint PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
ENDIF
IF (NTDDI_VERSION GE NTDDI_WIN7)
    BeginPanningFeedback PROTO :XWORD
ENDIF
IF (NTDDI_VERSION GE NTDDI_VISTA)
    BufferedPaintClear PROTO :XWORD,:XWORD
    BufferedPaintInit PROTO
    BufferedPaintRenderAnimation PROTO :XWORD,:XWORD
    BufferedPaintSetAlpha PROTO :XWORD,:XWORD,:XWORD
    BufferedPaintStopAllAnimations PROTO :XWORD
    BufferedPaintUnInit PROTO
ENDIF
CloseThemeData PROTO  :XWORD
IF (NTDDI_VERSION GE NTDDI_WIN8)
    IFNDEF DllCanUnloadNow
        DllCanUnloadNow PROTO
    ENDIF
    DllGetActivationFactory PROTO :XWORD,:XWORD
    IFNDEF DllGetClassObject
        DllGetClassObject PROTO :XWORD,:XWORD,:XWORD
    ENDIF
ENDIF
DrawThemeBackground PROTO  :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
DrawThemeBackgroundEx PROTO  :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
DrawThemeEdge PROTO  :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
DrawThemeIcon PROTO  :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
DrawThemeParentBackground PROTO  :XWORD,:XWORD,:XWORD
IF (NTDDI_VERSION GE NTDDI_VISTA)
    DrawThemeParentBackgroundEx PROTO :XWORD,:XWORD,:XWORD,:XWORD
    DrawThemeTextEx PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
ENDIF
DrawThemeText PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
EnableThemeDialogTexture PROTO  :XWORD,:XWORD
EnableTheming PROTO :XWORD
IF (NTDDI_VERSION GE NTDDI_VISTA)
    EndBufferedAnimation PROTO :XWORD,:XWORD
    EndBufferedPaint PROTO :XWORD,:XWORD
ENDIF
IF (NTDDI_VERSION GE NTDDI_WIN7)
    EndPanningFeedback PROTO :XWORD,:XWORD
ENDIF
IF (NTDDI_VERSION GE NTDDI_VISTA)
    GetBufferedPaintBits PROTO :XWORD,:XWORD,:XWORD
    GetBufferedPaintDC PROTO :XWORD
    GetBufferedPaintTargetDC PROTO :XWORD
    GetBufferedPaintTargetRect PROTO :XWORD,:XWORD
ENDIF
IF (NTDDI_VERSION GE NTDDI_WIN81)
    GetColorFromPreference PROTO :XWORD
    GetImmersiveColorFromColorSetEx PROTO :XWORD,:XWORD,:XWORD,:XWORD
    GetImmersiveUserColorSetPreference PROTO :XWORD,:XWORD
ENDIF
GetCurrentThemeName PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
IF (NTDDI_VERSION GE NTDDI_WIN8)
    GetThemeAnimationProperty PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
    GetThemeAnimationTransform PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
ENDIF
GetThemeAppProperties PROTO
GetThemeBackgroundContentRect PROTO  :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
GetThemeBackgroundExtent PROTO  :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
GetThemeBackgroundRegion PROTO  :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
IF (NTDDI_VERSION GE NTDDI_VISTA)
    GetThemeBitmap PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
ENDIF
GetThemeBool PROTO  :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
GetThemeColor PROTO  :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
GetThemeDocumentationProperty PROTO  :XWORD,:XWORD,:XWORD,:XWORD
GetThemeEnumValue PROTO  :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
GetThemeFilename PROTO  :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
GetThemeFont PROTO  :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
GetThemeInt PROTO  :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
GetThemeIntList PROTO  :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
GetThemeMargins PROTO  :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
GetThemeMetric PROTO  :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
GetThemePartSize PROTO  :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
GetThemePosition PROTO  :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
GetThemePropertyOrigin PROTO  :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
GetThemeRect PROTO  :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
GetThemeStream PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
GetThemeString PROTO  :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
GetThemeSysBool PROTO  :XWORD,:XWORD
GetThemeSysColor PROTO  :XWORD,:XWORD
GetThemeSysColorBrush PROTO  :XWORD,:XWORD
GetThemeSysFont PROTO  :XWORD,:XWORD,:XWORD
GetThemeSysInt PROTO  :XWORD,:XWORD,:XWORD
GetThemeSysSize PROTO  :XWORD,:XWORD
GetThemeSysString PROTO  :XWORD,:XWORD,:XWORD,:XWORD
GetThemeTextExtent PROTO  :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
GetThemeTextMetrics PROTO  :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
IF (NTDDI_VERSION GE NTDDI_WIN8)
    GetThemeTimingFunction PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD
ENDIF
IF (NTDDI_VERSION GE NTDDI_VISTA)
    GetThemeTransitionDuration PROTO :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
ENDIF
IF (NTDDI_VERSION GE NTDDI_WIN81)
    GetUserColorPreference PROTO :XWORD,:XWORD
ENDIF
GetWindowTheme PROTO  :XWORD
HitTestThemeBackground PROTO  :XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD,:XWORD
IsAppThemed PROTO
IF (NTDDI_VERSION GE NTDDI_VISTA)
    IsCompositionActive PROTO
ENDIF
IsThemeActive PROTO
IsThemeBackgroundPartiallyTransparent PROTO  :XWORD,:XWORD,:XWORD
IsThemeDialogTextureEnabled PROTO  :XWORD
IsThemePartDefined PROTO  :XWORD,:XWORD,:XWORD
OpenThemeData PROTO  :XWORD,:XWORD
IF (NTDDI_VERSION GE NTDDI_VISTA)
    OpenThemeDataEx PROTO :XWORD,:XWORD,:XWORD
ENDIF
SetThemeAppProperties PROTO  :XWORD
SetWindowTheme PROTO  :XWORD,:XWORD,:XWORD
IF (NTDDI_VERSION GE NTDDI_VISTA)
    SetWindowThemeAttribute PROTO :XWORD,:XWORD,:XWORD,:XWORD
ENDIF
ThemeInitApiHook PROTO :XWORD, :XWORD
IF (NTDDI_VERSION GE NTDDI_WIN7)
    IF (NTDDI_VERSION NE NTDDI_WIN81)
        UpdatePanningFeedback PROTO :XWORD,:XWORD,:XWORD,:XWORD
    ENDIF
ENDIF

ENDIF ;UXTHEME_INC
