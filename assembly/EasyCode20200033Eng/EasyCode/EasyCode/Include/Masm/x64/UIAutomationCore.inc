; ==============================================================;
;                                                               ;
;  UIAutomationCore.inc for Easy Code 2.0 64-bit Masm projects  ;
;                        (version 1.0.0)                        ;
;                                                               ;
;                 Copyright © Ramon Sala - 2020                 ;
;                                                               ;
; ==============================================================;

IFNDEF UIAUTOMATIONCORE_INC
UIAUTOMATIONCORE_INC    EQU 1

;NavigateDirection Enumeration
NavigateDirection_Parent                        EQU     0
NavigateDirection_NextSibling                   EQU     1
NavigateDirection_PreviousSibling               EQU     2
NavigateDirection_FirstChild                    EQU     3
NavigateDirection_LastChild                     EQU     4

;ProviderOptions Enumeration
ProviderOptions_ClientSideProvider              EQU     01H
ProviderOptions_ServerSideProvider              EQU     02H
ProviderOptions_NonClientAreaProvider           EQU     04H
ProviderOptions_OverrideProvider                EQU     08H
ProviderOptions_ProviderOwnsSetFocus            EQU     010H
ProviderOptions_UseComThreading                 EQU     020H
ProviderOptions_RefuseNonClientSupport          EQU     040H
ProviderOptions_HasNativeIAccessible            EQU     080H
ProviderOptions_UseClientCoordinates            EQU     0100H

;TextEditChangeType Enumeration
TextEditChangeType_None                         EQU     0
TextEditChangeType_AutoCorrect                  EQU     1
TextEditChangeType_Composition                  EQU     2
TextEditChangeType_CompositionFinalized         EQU     3

;OrientationType Enumeration
OrientationType_None                            EQU     0
OrientationType_Horizontal                      EQU     1
OrientationType_Vertical                        EQU     2

;DockPosition Enumeration
DockPosition_Top                                EQU     0
DockPosition_Left                               EQU     1
DockPosition_Bottom                             EQU     2
DockPosition_Right                              EQU     3
DockPosition_Fill                               EQU     4
DockPosition_None                               EQU     5

;ExpandCollapseState Enumeration
ExpandCollapseState_Collapsed                   EQU     0
ExpandCollapseState_Expanded                    EQU     1
ExpandCollapseState_PartiallyExpanded           EQU     2
ExpandCollapseState_LeafNode                    EQU     3

;ScrollAmount Enumeration
ScrollAmount_LargeDecrement                     EQU     0
ScrollAmount_SmallDecrement                     EQU     1
ScrollAmount_NoAmount                           EQU     2
ScrollAmount_LargeIncrement                     EQU     3
ScrollAmount_SmallIncrement                     EQU     4

;RowOrColumnMajor Enumeration
RowOrColumnMajor_RowMajor                       EQU     0
RowOrColumnMajor_ColumnMajor                    EQU     1
RowOrColumnMajor_Indeterminate                  EQU     2

;ToggleState Enumeration
ToggleState_Off                                 EQU     0
ToggleState_On                                  EQU     1
ToggleState_Indeterminate                       EQU     2

;WindowVisualState Enumeration
WindowVisualState_Normal                        EQU     0
WindowVisualState_Maximized                     EQU     1
WindowVisualState_Minimized                     EQU     2

;SynchronizedInputType Enumeration
SynchronizedInputType_KeyUp                     EQU     01H
SynchronizedInputType_KeyDown                   EQU     02H
SynchronizedInputType_LeftMouseUp               EQU     04H
SynchronizedInputType_LeftMouseDown             EQU     08H
SynchronizedInputType_RightMouseUp              EQU     010H
SynchronizedInputType_RightMouseDown            EQU     020H

;TextUnit Enumeration
TextUnit_Character                              EQU     0
TextUnit_Format                                 EQU     1
TextUnit_Word                                   EQU     2
TextUnit_Line                                   EQU     3
TextUnit_Paragraph                              EQU     4
TextUnit_Page                                   EQU     5
TextUnit_Document                               EQU     6

;TextPatternRangeEndpoint Enumeration
TextPatternRangeEndpoint_Start                  EQU     0
TextPatternRangeEndpoint_End                    EQU     1

;SupportedTextSelection Enumeration
SupportedTextSelection_None                     EQU     0
SupportedTextSelection_Single                   EQU     1
SupportedTextSelection_Multiple                 EQU     2

;LiveSetting Enumeration
Off                                             EQU     0
Polite                                          EQU     1
Assertive                                       EQU     2

;ActiveEnd Enumeration
ActiveEnd_None                                  EQU     0
ActiveEnd_Start                                 EQU     1
ActiveEnd_End                                   EQU     2

;CaretPosition Enumeration
CaretPosition_Unknown                           EQU     0
CaretPosition_EndOfLine                         EQU     1
CaretPosition_BeginningOfLine                   EQU     2

;CaretBidiMode Enumeration
CaretBidiMode_LTR                               EQU     0
CaretBidiMode_RTL                               EQU     1

;ZoomUnit Enumeration
ZoomUnit_NoAmount                               EQU     0
ZoomUnit_LargeDecrement                         EQU     1
ZoomUnit_SmallDecrement                         EQU     2
ZoomUnit_LargeIncrement                         EQU     3
ZoomUnit_SmallIncrement                         EQU     4

;AnimationStyle Enumeration
AnimationStyle_None                             EQU     0
AnimationStyle_LasVegasLights                   EQU     1
AnimationStyle_BlinkingBackground               EQU     2
AnimationStyle_SparkleText                      EQU     3
AnimationStyle_MarchingBlackAnts                EQU     4
AnimationStyle_MarchingRedAnts                  EQU     5
AnimationStyle_Shimmer                          EQU     6
AnimationStyle_Other                            EQU     (-1)

;BulletStyle Enumeration
BulletStyle_None                                EQU     0
BulletStyle_HollowRoundBullet                   EQU     1
BulletStyle_FilledRoundBullet                   EQU     2
BulletStyle_HollowSquareBullet                  EQU     3
BulletStyle_FilledSquareBullet                  EQU     4
BulletStyle_DashBullet                          EQU     5
BulletStyle_Other                               EQU     (-1)

;CapStyle Enumeration
CapStyle_None                                   EQU     0
CapStyle_SmallCap                               EQU     1
CapStyle_AllCap                                 EQU     2
CapStyle_AllPetiteCaps                          EQU     3
CapStyle_PetiteCaps                             EQU     4
CapStyle_Unicase                                EQU     5
CapStyle_Titling                                EQU     6
CapStyle_Other                                  EQU     (-1)

;FlowDirections Enumeration
FlowDirections_Default                          EQU     0
FlowDirections_RightToLeft                      EQU     1
FlowDirections_BottomToTop                      EQU     2
FlowDirections_Vertical                         EQU     4

;HorizontalTextAlignment Enumeration
HorizontalTextAlignment_Left                    EQU     0
HorizontalTextAlignment_Centered                EQU     1
HorizontalTextAlignment_Right                   EQU     2
HorizontalTextAlignment_Justified               EQU     3

;OutlineStyles Enumeration
OutlineStyles_None                              EQU     0
OutlineStyles_Outline                           EQU     1
OutlineStyles_Shadow                            EQU     2
OutlineStyles_Engraved                          EQU     4
OutlineStyles_Embossed                          EQU     8

;TextDecorationLineStyle Enumeration
TextDecorationLineStyle_None                    EQU     0
TextDecorationLineStyle_Single                  EQU     1
TextDecorationLineStyle_WordsOnly               EQU     2
TextDecorationLineStyle_Double                  EQU     3
TextDecorationLineStyle_Dot                     EQU     4
TextDecorationLineStyle_Dash                    EQU     5
TextDecorationLineStyle_DashDot                 EQU     6
TextDecorationLineStyle_DashDotDot              EQU     7
TextDecorationLineStyle_Wavy                    EQU     8
TextDecorationLineStyle_ThickSingle             EQU     9
TextDecorationLineStyle_DoubleWavy              EQU     11
TextDecorationLineStyle_ThickWavy               EQU     12
TextDecorationLineStyle_LongDash                EQU     13
TextDecorationLineStyle_ThickDash               EQU     14
TextDecorationLineStyle_ThickDashDot            EQU     15
TextDecorationLineStyle_ThickDashDotDot         EQU     16
TextDecorationLineStyle_ThickDot                EQU     17
TextDecorationLineStyle_ThickLongDash           EQU     18
TextDecorationLineStyle_Other                   EQU     (-1)

PROPERTYID                                      TYPEDEF DWORD
PATTERNID                                       TYPEDEF DWORD
EVENTID                                         TYPEDEF DWORD
TEXTATTRIBUTEID                                 TYPEDEF DWORD
CONTROLTYPEID                                   TYPEDEF DWORD

UiaRect STRUCT ALIGNMODE
    left   REAL8 ?
    top    REAL8 ?
    width1 REAL8 ?
    height REAL8 ?
UiaRect ENDS

UiaPoint STRUCT ALIGNMODE
    x REAL8 ?
    y REAL8 ?
UiaPoint ENDS

IFNDEF _IRawElementProviderSimple_INTERFACE_DEFINED_
    _IRawElementProviderSimple_INTERFACE_DEFINED_   EQU 1

    IRawElementProviderSimple_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FIRawElementProviderSimple_QueryInterface TYPEDEF PTR IRawElementProviderSimple_QueryInterface

    IRawElementProviderSimple_get_ProviderOptions TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIRawElementProviderSimple_get_ProviderOptions TYPEDEF PTR IRawElementProviderSimple_get_ProviderOptions

    IRawElementProviderSimple_GetPatternProvider TYPEDEF PROTO :XWORD, patternId:XWORD, pRetVal:XPTR
    FIRawElementProviderSimple_GetPatternProvider TYPEDEF PTR IRawElementProviderSimple_GetPatternProvider

    IRawElementProviderSimple_GetPropertyValue TYPEDEF PROTO :XWORD, propertyId:XWORD, pRetVal:XPTR
    FIRawElementProviderSimple_GetPropertyValue TYPEDEF PTR IRawElementProviderSimple_GetPropertyValue

    IRawElementProviderSimple_get_HostRawElementProvider TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIRawElementProviderSimple_get_HostRawElementProvider TYPEDEF PTR IRawElementProviderSimple_get_HostRawElementProvider

    STIRawElementProviderSimple STRUCT
        QueryInterface              FIRawElementProviderSimple_QueryInterface ?
        AddRef                      XPTR ?
        Release                     XPTR ?
        get_ProviderOptions         FIRawElementProviderSimple_get_ProviderOptions ?
        GetPatternProvider          FIRawElementProviderSimple_GetPatternProvider ?
        GetPropertyValue            FIRawElementProviderSimple_GetPropertyValue ?
        get_HostRawElementProvider  FIRawElementProviderSimple_get_HostRawElementProvider ?
    STIRawElementProviderSimple ENDS

    IRawElementProviderSimple MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIRawElementProviderSimple PTR[PPVREGISTER]).>, <&Function,ppvIRawElementProviderSimple>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF 
        mov PPVREGISTER, ppvIRawElementProviderSimple
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_IRawElementProviderSimple_INTERFACE_DEFINED_

IFNDEF _IRawElementProviderSimple2_INTERFACE_DEFINED_
    _IRawElementProviderSimple2_INTERFACE_DEFINED_  EQU 1

    IRawElementProviderSimple2_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FIRawElementProviderSimple2_QueryInterface TYPEDEF PTR IRawElementProviderSimple2_QueryInterface

    IRawElementProviderSimple2_get_ProviderOptions TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIRawElementProviderSimple2_get_ProviderOptions TYPEDEF PTR IRawElementProviderSimple2_get_ProviderOptions

    IRawElementProviderSimple2_GetPatternProvider TYPEDEF PROTO :XWORD, patternId:XWORD, pRetVal:XPTR
    FIRawElementProviderSimple2_GetPatternProvider TYPEDEF PTR IRawElementProviderSimple2_GetPatternProvider

    IRawElementProviderSimple2_GetPropertyValue TYPEDEF PROTO :XWORD, propertyId:XWORD, pRetVal:XPTR
    FIRawElementProviderSimple2_GetPropertyValue TYPEDEF PTR IRawElementProviderSimple2_GetPropertyValue

    IRawElementProviderSimple2_get_HostRawElementProvider TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIRawElementProviderSimple2_get_HostRawElementProvider TYPEDEF PTR IRawElementProviderSimple2_get_HostRawElementProvider

    STIRawElementProviderSimple2 STRUCT
        QueryInterface              FIRawElementProviderSimple2_QueryInterface ?
        AddRef                      XPTR ?
        Release                     XPTR ?
        get_ProviderOptions         FIRawElementProviderSimple2_get_ProviderOptions ?
        GetPatternProvider          FIRawElementProviderSimple2_GetPatternProvider ?
        GetPropertyValue            FIRawElementProviderSimple2_GetPropertyValue ?
        get_HostRawElementProvider  FIRawElementProviderSimple2_get_HostRawElementProvider ?
        ShowContextMenu             XPTR ?
    STIRawElementProviderSimple2 ENDS
 
    IRawElementProviderSimple2 MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIRawElementProviderSimple2 PTR[PPVREGISTER]).>, <&Function,ppvIRawElementProviderSimple2>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF 
        mov PPVREGISTER, ppvIRawElementProviderSimple2
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_IRawElementProviderSimple2_INTERFACE_DEFINED_

IFNDEF _IRawElementProviderFragment_INTERFACE_DEFINED_
    _IRawElementProviderFragment_INTERFACE_DEFINED_ EQU 1

    IRawElementProviderFragment_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FIRawElementProviderFragment_QueryInterface TYPEDEF PTR IRawElementProviderFragment_QueryInterface

    IRawElementProviderFragment_Navigate TYPEDEF PROTO :XWORD, direction:XWORD, pRetVal:XPTR
    FIRawElementProviderFragment_Navigate TYPEDEF PTR IRawElementProviderFragment_Navigate

    IRawElementProviderFragment_GetRuntimeId TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIRawElementProviderFragment_GetRuntimeId TYPEDEF PTR IRawElementProviderFragment_GetRuntimeId

    IRawElementProviderFragment_get_BoundingRectangle TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIRawElementProviderFragment_get_BoundingRectangle TYPEDEF PTR IRawElementProviderFragment_get_BoundingRectangle

    IRawElementProviderFragment_GetEmbeddedFragmentRoots TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIRawElementProviderFragment_GetEmbeddedFragmentRoots TYPEDEF PTR IRawElementProviderFragment_GetEmbeddedFragmentRoots

    IRawElementProviderFragment_get_FragmentRoot TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIRawElementProviderFragment_get_FragmentRoot TYPEDEF PTR IRawElementProviderFragment_get_FragmentRoot

    STIRawElementProviderFragment STRUCT
        QueryInterface              FIRawElementProviderFragment_QueryInterface ?
        AddRef                      XPTR ?
        Release                     XPTR ?
        Navigate                    FIRawElementProviderFragment_Navigate ?
        GetRuntimeId                FIRawElementProviderFragment_GetRuntimeId ?
        get_BoundingRectangle       FIRawElementProviderFragment_get_BoundingRectangle ?
        GetEmbeddedFragmentRoots    FIRawElementProviderFragment_GetEmbeddedFragmentRoots ?
        SetFocus1                   XPTR ?
        get_FragmentRoot            FIRawElementProviderFragment_get_FragmentRoot ?
    STIRawElementProviderFragment ENDS
 
    IRawElementProviderFragment MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIRawElementProviderFragment PTR[PPVREGISTER]).>, <&Function,ppvIRawElementProviderFragment>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF 
        mov PPVREGISTER, ppvIRawElementProviderFragment
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_IRawElementProviderFragment_INTERFACE_DEFINED_

IFNDEF _IRawElementProviderFragmentRoot_INTERFACE_DEFINED_
    _IRawElementProviderFragmentRoot_INTERFACE_DEFINED_ EQU 1

    IRawElementProviderFragmentRoot_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FIRawElementProviderFragmentRoot_QueryInterface TYPEDEF PTR IRawElementProviderFragmentRoot_QueryInterface

    IRawElementProviderFragmentRoot_ElementProviderFromPoint TYPEDEF PROTO :XWORD, x:REAL8, y:REAL8, pRetVal:XPTR
    FIRawElementProviderFragmentRoot_ElementProviderFromPoint TYPEDEF PTR IRawElementProviderFragmentRoot_ElementProviderFromPoint

    IRawElementProviderFragmentRoot_GetFocus1 TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIRawElementProviderFragmentRoot_GetFocus1 TYPEDEF PTR IRawElementProviderFragmentRoot_GetFocus1

    STIRawElementProviderFragmentRoot STRUCT
        QueryInterface              FIRawElementProviderFragmentRoot_QueryInterface ?
        AddRef                      XPTR ?
        Release                     XPTR ?
        ElementProviderFromPoint    FIRawElementProviderFragmentRoot_ElementProviderFromPoint ?
        GetFocus1                   FIRawElementProviderFragmentRoot_GetFocus1 ?
    STIRawElementProviderFragmentRoot ENDS
 
    IRawElementProviderFragmentRoot MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIRawElementProviderFragmentRoot PTR[PPVREGISTER]).>, <&Function,ppvIRawElementProviderFragmentRoot>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF 
        mov PPVREGISTER, ppvIRawElementProviderFragmentRoot
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_IRawElementProviderFragmentRoot_INTERFACE_DEFINED_

IFNDEF _IRawElementProviderAdviseEvents_INTERFACE_DEFINED_
    _IRawElementProviderAdviseEvents_INTERFACE_DEFINED_ EQU 1

    IRawElementProviderAdviseEvents_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FIRawElementProviderAdviseEvents_QueryInterface TYPEDEF PTR IRawElementProviderAdviseEvents_QueryInterface

    IRawElementProviderAdviseEvents_AdviseEventAdded TYPEDEF PROTO :XWORD, eventId:XWORD, propertyIDs:XPTR
    FIRawElementProviderAdviseEvents_AdviseEventAdded TYPEDEF PTR IRawElementProviderAdviseEvents_AdviseEventAdded

    IRawElementProviderAdviseEvents_AdviseEventRemoved TYPEDEF PROTO :XWORD, eventId:XWORD, propertyIDs:XPTR
    FIRawElementProviderAdviseEvents_AdviseEventRemoved TYPEDEF PTR IRawElementProviderAdviseEvents_AdviseEventRemoved

    STIRawElementProviderAdviseEvents STRUCT
        QueryInterface      FIRawElementProviderAdviseEvents_QueryInterface ?
        AddRef              XPTR ?
        Release             XPTR ?
        AdviseEventAdded    FIRawElementProviderAdviseEvents_AdviseEventAdded ?
        AdviseEventRemoved  FIRawElementProviderAdviseEvents_AdviseEventRemoved ?
    STIRawElementProviderAdviseEvents ENDS
 
    IRawElementProviderAdviseEvents MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIRawElementProviderAdviseEvents PTR[PPVREGISTER]).>, <&Function,ppvIRawElementProviderAdviseEvents>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF 
        mov PPVREGISTER, ppvIRawElementProviderAdviseEvents
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_IRawElementProviderAdviseEvents_INTERFACE_DEFINED_

IFNDEF _IRawElementProviderHwndOverride_INTERFACE_DEFINED_
    _IRawElementProviderHwndOverride_INTERFACE_DEFINED_ EQU 1

    IRawElementProviderHwndOverride_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FIRawElementProviderHwndOverride_QueryInterface TYPEDEF PTR IRawElementProviderHwndOverride_QueryInterface

    IRawElementProviderHwndOverride_GetOverrideProviderForHwnd TYPEDEF PROTO :XWORD, hwnd:HWND, pRetVal:XPTR
    FIRawElementProviderHwndOverride_GetOverrideProviderForHwnd TYPEDEF PTR IRawElementProviderHwndOverride_GetOverrideProviderForHwnd

    STIRawElementProviderHwndOverride STRUCT
        QueryInterface              FIRawElementProviderHwndOverride_QueryInterface ?
        AddRef                      XPTR ?
        Release                     XPTR ?
        GetOverrideProviderForHwnd  FIRawElementProviderHwndOverride_GetOverrideProviderForHwnd ?
    STIRawElementProviderHwndOverride ENDS
 
    IRawElementProviderHwndOverride MACRO  Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIRawElementProviderHwndOverride PTR[PPVREGISTER]).>, <&Function,ppvIRawElementProviderHwndOverride>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF 
        mov PPVREGISTER, ppvIRawElementProviderHwndOverride
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_IRawElementProviderHwndOverride_INTERFACE_DEFINED_

IFNDEF _IRawElementProviderWindowlessSite_INTERFACE_DEFINED_
    _IRawElementProviderWindowlessSite_INTERFACE_DEFINED_   EQU 1

    IRawElementProviderWindowlessSite_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FIRawElementProviderWindowlessSite_QueryInterface TYPEDEF PTR IRawElementProviderWindowlessSite_QueryInterface

    IRawElementProviderWindowlessSite_GetAdjacentFragment TYPEDEF PROTO :XWORD, direction:XWORD, ppParent:XPTR
    FIRawElementProviderWindowlessSite_GetAdjacentFragment TYPEDEF PTR IRawElementProviderWindowlessSite_GetAdjacentFragment

    IRawElementProviderWindowlessSite_GetRuntimeIdPrefix TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIRawElementProviderWindowlessSite_GetRuntimeIdPrefix TYPEDEF PTR IRawElementProviderWindowlessSite_GetRuntimeIdPrefix

    STIRawElementProviderWindowlessSite STRUCT
        QueryInterface      FIRawElementProviderWindowlessSite_QueryInterface ?
        AddRef              XPTR ?
        Release             XPTR ?
        GetAdjacentFragment FIRawElementProviderWindowlessSite_GetAdjacentFragment ?
        GetRuntimeIdPrefix  FIRawElementProviderWindowlessSite_GetRuntimeIdPrefix ?
    STIRawElementProviderWindowlessSite ENDS
 
    IRawElementProviderWindowlessSite MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIRawElementProviderWindowlessSite PTR[PPVREGISTER]).>, <&Function,ppvIRawElementProviderWindowlessSite>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF 
        mov PPVREGISTER, ppvIRawElementProviderWindowlessSite
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_IRawElementProviderWindowlessSite_INTERFACE_DEFINED_

IFNDEF _IRawElementProviderHostingAccessibles_INTERFACE_DEFINED_
    _IRawElementProviderHostingAccessibles_INTERFACE_DEFINED_   EQU 1

    IRawElementProviderHostingAccessibles_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FIRawElementProviderHostingAccessibles_QueryInterface TYPEDEF PTR IRawElementProviderHostingAccessibles_QueryInterface

    IRawElementProviderHostingAccessibles_GetEmbeddedAccessibles TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIRawElementProviderHostingAccessibles_GetEmbeddedAccessibles TYPEDEF PTR IRawElementProviderHostingAccessibles_GetEmbeddedAccessibles

    STIRawElementProviderHostingAccessibles STRUCT
        QueryInterface          FIRawElementProviderHostingAccessibles_QueryInterface ?
        AddRef                  XPTR ?
        Release                 XPTR ?
        GetEmbeddedAccessibles  FIRawElementProviderHostingAccessibles_GetEmbeddedAccessibles ?
    STIRawElementProviderHostingAccessibles ENDS

    IRawElementProviderHostingAccessibles MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIRawElementProviderHostingAccessibles PTR[PPVREGISTER]).>, <&Function,ppvIRawElementProviderHostingAccessibles>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF 
        mov PPVREGISTER, ppvIRawElementProviderHostingAccessibles
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_IRawElementProviderHostingAccessibles_INTERFACE_DEFINED_

IFNDEF _UIA_LIBRARY_DEFINED_
    _UIA_LIBRARY_DEFINED_   EQU 1

    ;UIAutomationType Enumeration
    UIAutomationType_Int                        EQU     01H
    UIAutomationType_Bool                       EQU     02H
    UIAutomationType_String                     EQU     03H
    UIAutomationType_Double                     EQU     04H
    UIAutomationType_Point                      EQU     05H
    UIAutomationType_Rect                       EQU     06H
    UIAutomationType_Element                    EQU     07H
    UIAutomationType_Array                      EQU     010000H
    UIAutomationType_Out                        EQU     020000H
    UIAutomationType_IntArray                   EQU     (UIAutomationType_Int OR UIAutomationType_Array)
    UIAutomationType_BoolArray                  EQU     (UIAutomationType_Bool OR UIAutomationType_Array)
    UIAutomationType_StringArray                EQU     (UIAutomationType_String OR UIAutomationType_Array)
    UIAutomationType_DoubleArray                EQU     (UIAutomationType_Double OR UIAutomationType_Array)
    UIAutomationType_PointArray                 EQU     (UIAutomationType_Point OR UIAutomationType_Array)
    UIAutomationType_RectArray                  EQU     (UIAutomationType_Rect OR UIAutomationType_Array)
    UIAutomationType_ElementArray               EQU     (UIAutomationType_Element OR UIAutomationType_Array)
    UIAutomationType_OutInt                     EQU     (UIAutomationType_Int OR UIAutomationType_Out)
    UIAutomationType_OutBool                    EQU     (UIAutomationType_Bool OR UIAutomationType_Out)
    UIAutomationType_OutString                  EQU     (UIAutomationType_String OR UIAutomationType_Out)
    UIAutomationType_OutDouble                  EQU     (UIAutomationType_Double OR UIAutomationType_Out)
    UIAutomationType_OutPoint                   EQU     (UIAutomationType_Point OR UIAutomationType_Out)
    UIAutomationType_OutRect                    EQU     (UIAutomationType_Rect OR UIAutomationType_Out)
    UIAutomationType_OutElement                 EQU     (UIAutomationType_Element OR UIAutomationType_Out)
    UIAutomationType_OutIntArray                EQU     ((UIAutomationType_Int OR UIAutomationType_Array) OR UIAutomationType_Out)
    UIAutomationType_OutBoolArray               EQU     ((UIAutomationType_Bool OR UIAutomationType_Array) OR UIAutomationType_Out)
    UIAutomationType_OutStringArray             EQU     ((UIAutomationType_String OR UIAutomationType_Array) OR UIAutomationType_Out)
    UIAutomationType_OutDoubleArray             EQU     ((UIAutomationType_Double OR UIAutomationType_Array) OR UIAutomationType_Out)
    UIAutomationType_OutPointArray              EQU     ((UIAutomationType_Point OR UIAutomationType_Array) OR UIAutomationType_Out)
    UIAutomationType_OutRectArray               EQU     ((UIAutomationType_Rect OR UIAutomationType_Array) OR UIAutomationType_Out)
    UIAutomationType_OutElementArray            EQU     ((UIAutomationType_Element OR UIAutomationType_Array) OR UIAutomationType_Out)

    UIAutomationPropertyInfo STRUCT ALIGNMODE
        guid                GUID  <>
        pProgrammaticName   XPTR  ?
        atype               DWORD ?
    UIAutomationPropertyInfo ENDS

    UIAutomationEventInfo STRUCT ALIGNMODE
        guid                GUID <>
        pProgrammaticName   XPTR ?
    UIAutomationEventInfo ENDS

    UIAutomationMethodInfo STRUCT ALIGNMODE
        pProgrammaticName   XPTR  ?
        doSetFocus          DWORD ?
        cInParameters       DWORD ?
        cOutParameters      DWORD ?
        pParameterTypes     XPTR  ?
        pParameterNames     XPTR  ?
    UIAutomationMethodInfo ENDS

UIAutomationPatternInfo STRUCT ALIGNMODE
    guid                GUID  <>
    pProgrammaticName   XPTR  ?
    providerInterfaceId GUID  <>
    clientInterfaceId   GUID  <>
    cProperties         DWORD ?
    pProperties         XPTR  ?
    cMethods            DWORD ?
    pMethods            XPTR  ?
    cEvents             DWORD ?
    pEvents             XPTR  ?
    pPatternHandler     XPTR  ?
UIAutomationPatternInfo ENDS

IFNDEF _UIA_OtherConstants_MODULE_DEFINED_
    _UIA_OtherConstants_MODULE_DEFINED_         EQU     1
ENDIF ;_UIA_OtherConstants_MODULE_DEFINED_

IFNDEF _IAccessibleEx_INTERFACE_DEFINED_
    _IAccessibleEx_INTERFACE_DEFINED_           EQU     1

    IAccessibleEx_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FIAccessibleEx_QueryInterface TYPEDEF PTR IAccessibleEx_QueryInterface

    IAccessibleEx_GetObjectForChild TYPEDEF PROTO :XWORD, idChild:XWORD, pRetVal:XPTR
    FIAccessibleEx_GetObjectForChild TYPEDEF PTR IAccessibleEx_GetObjectForChild

    IAccessibleEx_GetIAccessiblePair TYPEDEF PROTO :XWORD, ppAcc:XPTR, pidChild:XPTR
    FIAccessibleEx_GetIAccessiblePair TYPEDEF PTR IAccessibleEx_GetIAccessiblePair

    IAccessibleEx_GetRuntimeId TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIAccessibleEx_GetRuntimeId TYPEDEF PTR IAccessibleEx_GetRuntimeId

    IAccessibleEx_ConvertReturnedElement TYPEDEF PROTO :XWORD, pIn:XPTR, ppRetValOut:XPTR
    FIAccessibleEx_ConvertReturnedElement TYPEDEF PTR IAccessibleEx_ConvertReturnedElement

    STIAccessibleEx STRUCT
        QueryInterface          FIAccessibleEx_QueryInterface ?
        AddRef                  XPTR ?
        Release                 XPTR ?
        GetObjectForChild       FIAccessibleEx_GetObjectForChild ?
        GetIAccessiblePair      FIAccessibleEx_GetIAccessiblePair ?
        GetRuntimeId            FIAccessibleEx_GetRuntimeId ?
        ConvertReturnedElement  FIAccessibleEx_ConvertReturnedElement ?
    STIAccessibleEx ENDS

    IAccessibleEx MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STIAccessibleEx PTR[PPVREGISTER])., &Function,ppvIAccessibleEx
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvIAccessibleEx
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_IAccessibleEx_INTERFACE_DEFINED_

IFNDEF _IProxyProviderWinEventSink_INTERFACE_DEFINED_
    _IProxyProviderWinEventSink_INTERFACE_DEFINED_  EQU 1

    IProxyProviderWinEventSink_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FIProxyProviderWinEventSink_QueryInterface TYPEDEF PTR IProxyProviderWinEventSink_QueryInterface

    IProxyProviderWinEventSink_AddAutomationPropertyChangedEvent TYPEDEF PROTO :XWORD, pProvider:XPTR, id:XWORD, newValue:VARIANT 
    FIProxyProviderWinEventSink_AddAutomationPropertyChangedEvent TYPEDEF PTR IProxyProviderWinEventSink_AddAutomationPropertyChangedEvent

    IProxyProviderWinEventSink_AddAutomationEvent TYPEDEF PROTO :XWORD, pProvider:XPTR, id:XWORD 
    FIProxyProviderWinEventSink_AddAutomationEvent TYPEDEF PTR IProxyProviderWinEventSink_AddAutomationEvent

    IProxyProviderWinEventSink_AddStructureChangedEvent TYPEDEF PROTO :XWORD, pProvider:XPTR, structureChangeType:XWORD, runtimeId:XWORD
    FIProxyProviderWinEventSink_AddStructureChangedEvent TYPEDEF PTR IProxyProviderWinEventSink_AddStructureChangedEvent

    STIProxyProviderWinEventSink STRUCT
        QueryInterface                      FIProxyProviderWinEventSink_QueryInterface ?
        AddRef                              XPTR ?
        Release                             XPTR ?
        AddAutomationPropertyChangedEvent   FIProxyProviderWinEventSink_AddAutomationPropertyChangedEvent ?
        AddAutomationEvent                  FIProxyProviderWinEventSink_AddAutomationEvent ?
        AddStructureChangedEvent            FIProxyProviderWinEventSink_AddStructureChangedEvent ?
    STIProxyProviderWinEventSink ENDS
 
    IProxyProviderWinEventSink MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STIProxyProviderWinEventSink PTR[PPVREGISTER])., &Function,ppvIProxyProviderWinEventSink
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvIProxyProviderWinEventSink
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_IProxyProviderWinEventSink_INTERFACE_DEFINED_

IFNDEF _IProxyProviderWinEventHandler_INTERFACE_DEFINED_
    _IProxyProviderWinEventHandler_INTERFACE_DEFINED_   EQU 1

    IProxyProviderWinEventHandler_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FIProxyProviderWinEventHandler_QueryInterface TYPEDEF PTR IProxyProviderWinEventHandler_QueryInterface

    IProxyProviderWinEventHandler_RespondToWinEvent TYPEDEF PROTO :XWORD, idWinEvent:XWORD, hwnd:HWND, idObject:XWORD, idChild:XWORD, pSink:XPTR
    FIProxyProviderWinEventHandler_RespondToWinEvent TYPEDEF PTR IProxyProviderWinEventHandler_RespondToWinEvent

    STIProxyProviderWinEventHandler STRUCT
        QueryInterface      FIProxyProviderWinEventHandler_QueryInterface ?
        AddRef              XPTR ?
        Release             XPTR ?
        RespondToWinEvent   FIProxyProviderWinEventHandler_RespondToWinEvent ?
    STIProxyProviderWinEventHandler ENDS
 
    IProxyProviderWinEventHandler MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STIProxyProviderWinEventHandler PTR[PPVREGISTER])., &Function,ppvIProxyProviderWinEventHandler
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvIProxyProviderWinEventHandler
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_IProxyProviderWinEventHandler_INTERFACE_DEFINED_

IFNDEF _IAccessibleHostingElementProviders_INTERFACE_DEFINED_
    _IAccessibleHostingElementProviders_INTERFACE_DEFINED_  EQU 1

    IAccessibleHostingElementProviders_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FIAccessibleHostingElementProviders_QueryInterface TYPEDEF PTR IAccessibleHostingElementProviders_QueryInterface

    IAccessibleHostingElementProviders_GetEmbeddedFragmentRoots TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIAccessibleHostingElementProviders_GetEmbeddedFragmentRoots TYPEDEF PTR IAccessibleHostingElementProviders_GetEmbeddedFragmentRoots

    IAccessibleHostingElementProviders_GetObjectIdForProvider TYPEDEF PROTO :XWORD, pProvider:XPTR, pidObject:XPTR
    FIAccessibleHostingElementProviders_GetObjectIdForProvider TYPEDEF PTR IAccessibleHostingElementProviders_GetObjectIdForProvider

    STIAccessibleHostingElementProviders STRUCT
        QueryInterface              FIAccessibleHostingElementProviders_QueryInterface ?
        AddRef                      XPTR ?
        Release                     XPTR ?
        GetEmbeddedFragmentRoots    FIAccessibleHostingElementProviders_GetEmbeddedFragmentRoots ?
        GetObjectIdForProvider      FIAccessibleHostingElementProviders_GetObjectIdForProvider ?
    STIAccessibleHostingElementProviders ENDS

    IAccessibleHostingElementProviders MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STIAccessibleHostingElementProviders PTR[PPVREGISTER])., &Function,ppvIAccessibleHostingElementProviders
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvIAccessibleHostingElementProviders
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_IAccessibleHostingElementProviders_INTERFACE_DEFINED_

IFNDEF _IDockProvider_INTERFACE_DEFINED_
    _IDockProvider_INTERFACE_DEFINED_   EQU 1

    IDockProvider_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FIDockProvider_QueryInterface TYPEDEF PTR IDockProvider_QueryInterface

    IDockProvider_get_DockPosition TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIDockProvider_get_DockPosition TYPEDEF PTR IDockProvider_get_DockPosition

    STIDockProvider STRUCT
        QueryInterface      FIDockProvider_QueryInterface ?
        AddRef              XPTR ?
        Release             XPTR ?
        SetDockPosition     XPTR ?
        get_DockPosition    FIDockProvider_get_DockPosition ?
    STIDockProvider ENDS
 
    IDockProvider MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STIDockProvider PTR[PPVREGISTER])., &Function,ppvIDockProvider
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvIDockProvider
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_IDockProvider_INTERFACE_DEFINED_

IFNDEF _IExpandCollapseProvider_INTERFACE_DEFINED_
    _IExpandCollapseProvider_INTERFACE_DEFINED_ EQU 1

    IExpandCollapseProvider_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FIExpandCollapseProvider_QueryInterface TYPEDEF PTR IExpandCollapseProvider_QueryInterface

    IExpandCollapseProvider_get_ExpandCollapseState TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIExpandCollapseProvider_get_ExpandCollapseState TYPEDEF PTR IExpandCollapseProvider_get_ExpandCollapseState

    STIExpandCollapseProvider STRUCT
        QueryInterface          FIExpandCollapseProvider_QueryInterface ?
        AddRef                  XPTR ?
        Release                 XPTR ?
        Expand                  XPTR ?
        Collapse                XPTR ?
        get_ExpandCollapseState FIExpandCollapseProvider_get_ExpandCollapseState ?
    STIExpandCollapseProvider ENDS
 
    IExpandCollapseProvider MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STIExpandCollapseProvider PTR[PPVREGISTER])., &Function,ppvIExpandCollapseProvider
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvIExpandCollapseProvider
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_IExpandCollapseProvider_INTERFACE_DEFINED_

IFNDEF _IGridProvider_INTERFACE_DEFINED_
    _IGridProvider_INTERFACE_DEFINED_   EQU 1

    IGridProvider_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FIGridProvider_QueryInterface TYPEDEF PTR IGridProvider_QueryInterface

    IGridProvider_GetItem TYPEDEF PROTO :XWORD, row:XWORD, column:XWORD, pRetVal:XPTR
    FIGridProvider_GetItem TYPEDEF PTR IGridProvider_GetItem

    IGridProvider_get_RowCount TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIGridProvider_get_RowCount TYPEDEF PTR IGridProvider_get_RowCount

    IGridProvider_get_ColumnCount TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIGridProvider_get_ColumnCount TYPEDEF PTR IGridProvider_get_ColumnCount

    STIGridProvider STRUCT
        QueryInterface  FIGridProvider_QueryInterface ?
        AddRef          XPTR ?
        Release         XPTR ?
        GetItem         FIGridProvider_GetItem ?
        get_RowCount    FIGridProvider_get_RowCount ?
        get_ColumnCount FIGridProvider_get_ColumnCount ?
    STIGridProvider ENDS
 
    IGridProvider MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STIGridProvider PTR[PPVREGISTER])., &Function,ppvIGridProvider
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvIGridProvider
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_IGridProvider_INTERFACE_DEFINED_

IFNDEF _IGridItemProvider_INTERFACE_DEFINED_
    _IGridItemProvider_INTERFACE_DEFINED_   EQU 1

    IGridItemProvider_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FIGridItemProvider_QueryInterface TYPEDEF PTR IGridItemProvider_QueryInterface

    IGridItemProvider_get_Row TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIGridItemProvider_get_Row TYPEDEF PTR IGridItemProvider_get_Row

    IGridItemProvider_get_Column TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIGridItemProvider_get_Column TYPEDEF PTR IGridItemProvider_get_Column

    IGridItemProvider_get_RowSpan TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIGridItemProvider_get_RowSpan TYPEDEF PTR IGridItemProvider_get_RowSpan

    IGridItemProvider_get_ColumnSpan TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIGridItemProvider_get_ColumnSpan TYPEDEF PTR IGridItemProvider_get_ColumnSpan

    IGridItemProvider_get_ContainingGrid TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIGridItemProvider_get_ContainingGrid TYPEDEF PTR IGridItemProvider_get_ContainingGrid

    STIGridItemProvider STRUCT
        QueryInterface      FIGridItemProvider_QueryInterface ?
        AddRef              XPTR ?
        Release             XPTR ?
        get_Row             FIGridItemProvider_get_Row ?
        get_Column          FIGridItemProvider_get_Column ?
        get_RowSpan         FIGridItemProvider_get_RowSpan ?
        get_ColumnSpan      FIGridItemProvider_get_ColumnSpan ?
        get_ContainingGrid  FIGridItemProvider_get_ContainingGrid ?
    STIGridItemProvider ENDS
 
    IGridItemProvider MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STIGridItemProvider PTR[PPVREGISTER])., &Function,ppvIGridItemProvider
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvIGridItemProvider
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_IGridItemProvider_INTERFACE_DEFINED_

IFNDEF _IInvokeProvider_INTERFACE_DEFINED_
    _IInvokeProvider_INTERFACE_DEFINED_ EQU 1

    IInvokeProvider_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FIInvokeProvider_QueryInterface TYPEDEF PTR IInvokeProvider_QueryInterface

    STIInvokeProvider STRUCT
        QueryInterface  FIInvokeProvider_QueryInterface ?
        AddRef          XPTR ?
        Release         XPTR ?
        invoke1         XPTR ?
    STIInvokeProvider ENDS
 
    IInvokeProvider MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STIInvokeProvider PTR[PPVREGISTER])., &Function,ppvIInvokeProvider
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvIInvokeProvider
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_IInvokeProvider_INTERFACE_DEFINED_

IFNDEF _IMultipleViewProvider_INTERFACE_DEFINED_
    _IMultipleViewProvider_INTERFACE_DEFINED_   EQU 1

    IMultipleViewProvider_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FIMultipleViewProvider_QueryInterface TYPEDEF PTR IMultipleViewProvider_QueryInterface

    IMultipleViewProvider_GetViewName TYPEDEF PROTO :XWORD, viewId:XWORD, pRetVal:XPTR
    FIMultipleViewProvider_GetViewName TYPEDEF PTR IMultipleViewProvider_GetViewName

    IMultipleViewProvider_get_CurrentView TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIMultipleViewProvider_get_CurrentView TYPEDEF PTR IMultipleViewProvider_get_CurrentView

    IMultipleViewProvider_GetSupportedViews TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIMultipleViewProvider_GetSupportedViews TYPEDEF PTR IMultipleViewProvider_GetSupportedViews

    STIMultipleViewProvider STRUCT
        QueryInterface      FIMultipleViewProvider_QueryInterface ?
        AddRef              XPTR ?
        Release             XPTR ?
        GetViewName         FIMultipleViewProvider_GetViewName ?
        SetCurrentView      XPTR ?
        get_CurrentView     FIMultipleViewProvider_get_CurrentView ?
        GetSupportedViews   FIMultipleViewProvider_GetSupportedViews ?
    STIMultipleViewProvider ENDS
 
    IMultipleViewProvider MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STIMultipleViewProvider PTR[PPVREGISTER])., &Function,ppvIMultipleViewProvider
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvIMultipleViewProvider
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_IMultipleViewProvider_INTERFACE_DEFINED_

IFNDEF _IRangeValueProvider_INTERFACE_DEFINED_
    _IRangeValueProvider_INTERFACE_DEFINED_ EQU 1

    IRangeValueProvider_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FIRangeValueProvider_QueryInterface TYPEDEF PTR IRangeValueProvider_QueryInterface

    IRangeValueProvider_SetValue TYPEDEF PROTO :XWORD, val:REAL8 
    FIRangeValueProvider_SetValue TYPEDEF PTR IRangeValueProvider_SetValue

    IRangeValueProvider_get_Value TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIRangeValueProvider_get_Value TYPEDEF PTR IRangeValueProvider_get_Value

    IRangeValueProvider_get_IsReadOnly TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIRangeValueProvider_get_IsReadOnly TYPEDEF PTR IRangeValueProvider_get_IsReadOnly

    IRangeValueProvider_get_Maximum TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIRangeValueProvider_get_Maximum TYPEDEF PTR IRangeValueProvider_get_Maximum

    IRangeValueProvider_get_Minimum TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIRangeValueProvider_get_Minimum TYPEDEF PTR IRangeValueProvider_get_Minimum

    IRangeValueProvider_get_LargeChange TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIRangeValueProvider_get_LargeChange TYPEDEF PTR IRangeValueProvider_get_LargeChange

    IRangeValueProvider_get_SmallChange TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIRangeValueProvider_get_SmallChange TYPEDEF PTR IRangeValueProvider_get_SmallChange

    STIRangeValueProvider STRUCT
        QueryInterface  FIRangeValueProvider_QueryInterface ?
        AddRef          XPTR ?
        Release         XPTR ?
        SetValue        FIRangeValueProvider_SetValue ?
        get_Value       FIRangeValueProvider_get_Value ?
        get_IsReadOnly  FIRangeValueProvider_get_IsReadOnly ?
        get_Maximum     FIRangeValueProvider_get_Maximum ?
        get_Minimum     FIRangeValueProvider_get_Minimum ?
        get_LargeChange FIRangeValueProvider_get_LargeChange ?
        get_SmallChange FIRangeValueProvider_get_SmallChange ?
    STIRangeValueProvider ENDS
 
    IRangeValueProvider MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STIRangeValueProvider PTR[PPVREGISTER])., &Function,ppvIRangeValueProvider
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvIRangeValueProvider
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_IRangeValueProvider_INTERFACE_DEFINED_

IFNDEF _IScrollItemProvider_INTERFACE_DEFINED_
    _IScrollItemProvider_INTERFACE_DEFINED_ EQU 1

    IScrollItemProvider_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FIScrollItemProvider_QueryInterface TYPEDEF PTR IScrollItemProvider_QueryInterface

    STIScrollItemProvider STRUCT
        QueryInterface  FIScrollItemProvider_QueryInterface ?
        AddRef          XPTR ?
        Release         XPTR ?
        ScrollIntoView  XPTR ?
    STIScrollItemProvider ENDS
 
    IScrollItemProvider MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STIScrollItemProvider PTR[PPVREGISTER])., &Function,ppvIScrollItemProvider
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvIScrollItemProvider
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_IScrollItemProvider_INTERFACE_DEFINED_

IFNDEF _ISelectionProvider_INTERFACE_DEFINED_
    _ISelectionProvider_INTERFACE_DEFINED_  EQU 1

    ISelectionProvider_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FISelectionProvider_QueryInterface TYPEDEF PTR ISelectionProvider_QueryInterface

    ISelectionProvider_GetSelection TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FISelectionProvider_GetSelection TYPEDEF PTR ISelectionProvider_GetSelection

    ISelectionProvider_get_CanSelectMultiple TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FISelectionProvider_get_CanSelectMultiple TYPEDEF PTR ISelectionProvider_get_CanSelectMultiple

    ISelectionProvider_get_IsSelectionRequired TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FISelectionProvider_get_IsSelectionRequired TYPEDEF PTR ISelectionProvider_get_IsSelectionRequired

    STISelectionProvider STRUCT
        QueryInterface          FISelectionProvider_QueryInterface ?
        AddRef                  XPTR ?
        Release                 XPTR ?
        GetSelection            FISelectionProvider_GetSelection ?
        get_CanSelectMultiple   FISelectionProvider_get_CanSelectMultiple ?
        get_IsSelectionRequired FISelectionProvider_get_IsSelectionRequired ?
    STISelectionProvider ENDS
 
    ISelectionProvider MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STISelectionProvider PTR[PPVREGISTER])., &Function,ppvISelectionProvider
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvISelectionProvider
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_ISelectionProvider_INTERFACE_DEFINED_

IFNDEF _IScrollProvider_INTERFACE_DEFINED_
    _IScrollProvider_INTERFACE_DEFINED_ EQU 1

    IScrollProvider_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FIScrollProvider_QueryInterface TYPEDEF PTR IScrollProvider_QueryInterface

    IScrollProvider_SetScrollPercent TYPEDEF PROTO :XWORD, horizontalPercent:REAL8, verticalPercent:REAL8 
    FIScrollProvider_SetScrollPercent TYPEDEF PTR IScrollProvider_SetScrollPercent

    IScrollProvider_get_HorizontalScrollPercent TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIScrollProvider_get_HorizontalScrollPercent TYPEDEF PTR IScrollProvider_get_HorizontalScrollPercent

    IScrollProvider_get_VerticalScrollPercent TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIScrollProvider_get_VerticalScrollPercent TYPEDEF PTR IScrollProvider_get_VerticalScrollPercent

    IScrollProvider_get_HorizontalViewSize TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIScrollProvider_get_HorizontalViewSize TYPEDEF PTR IScrollProvider_get_HorizontalViewSize

    IScrollProvider_get_VerticalViewSize TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIScrollProvider_get_VerticalViewSize TYPEDEF PTR IScrollProvider_get_VerticalViewSize

    IScrollProvider_get_HorizontallyScrollable TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIScrollProvider_get_HorizontallyScrollable TYPEDEF PTR IScrollProvider_get_HorizontallyScrollable

    IScrollProvider_get_VerticallyScrollable TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIScrollProvider_get_VerticallyScrollable TYPEDEF PTR IScrollProvider_get_VerticallyScrollable

    STIScrollProvider STRUCT
        QueryInterface              FIScrollProvider_QueryInterface ?
        AddRef                      XPTR ?
        Release                     XPTR ?
        Scroll                      XPTR ?
        SetScrollPercent            FIScrollProvider_SetScrollPercent ?
        get_HorizontalScrollPercent FIScrollProvider_get_HorizontalScrollPercent ?
        get_VerticalScrollPercent   FIScrollProvider_get_VerticalScrollPercent ?
        get_HorizontalViewSize      FIScrollProvider_get_HorizontalViewSize ?
        get_VerticalViewSize        FIScrollProvider_get_VerticalViewSize ?
        get_HorizontallyScrollable  FIScrollProvider_get_HorizontallyScrollable ?
        get_VerticallyScrollable    FIScrollProvider_get_VerticallyScrollable ?
    STIScrollProvider ENDS
 
    IScrollProvider MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STIScrollProvider PTR[PPVREGISTER])., &Function,ppvIScrollProvider
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvIScrollProvider
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_IScrollProvider_INTERFACE_DEFINED_

IFNDEF _ISelectionItemProvider_INTERFACE_DEFINED_
    _ISelectionItemProvider_INTERFACE_DEFINED_  EQU 1

    ISelectionItemProvider_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FISelectionItemProvider_QueryInterface TYPEDEF PTR ISelectionItemProvider_QueryInterface

    ISelectionItemProvider_get_IsSelected TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FISelectionItemProvider_get_IsSelected TYPEDEF PTR ISelectionItemProvider_get_IsSelected

    ISelectionItemProvider_get_SelectionContainer TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FISelectionItemProvider_get_SelectionContainer TYPEDEF PTR ISelectionItemProvider_get_SelectionContainer

    STISelectionItemProvider STRUCT
        QueryInterface          FISelectionItemProvider_QueryInterface ?
        AddRef                  XPTR ?
        Release                 XPTR ?
        Select1                 XPTR ?
        AddToSelection          XPTR ?
        RemoveFromSelection     XPTR ?
        get_IsSelected          FISelectionItemProvider_get_IsSelected ?
        get_SelectionContainer  FISelectionItemProvider_get_SelectionContainer ?
    STISelectionItemProvider ENDS
 
    ISelectionItemProvider MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STISelectionItemProvider PTR[PPVREGISTER])., &Function,ppvISelectionItemProvider
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvISelectionItemProvider
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_ISelectionItemProvider_INTERFACE_DEFINED_

IFNDEF _ISynchronizedInputProvider_INTERFACE_DEFINED_
    _ISynchronizedInputProvider_INTERFACE_DEFINED_  EQU 1

    ISynchronizedInputProvider_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FISynchronizedInputProvider_QueryInterface TYPEDEF PTR ISynchronizedInputProvider_QueryInterface

    STISynchronizedInputProvider STRUCT
        QueryInterface  FISynchronizedInputProvider_QueryInterface ?
        AddRef          XPTR ?
        Release         XPTR ?
        StartListening  XPTR ?
        Cancel          XPTR ?
    STISynchronizedInputProvider ENDS
 
    ISynchronizedInputProvider MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STISynchronizedInputProvider PTR[PPVREGISTER])., &Function,ppvISynchronizedInputProvider
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvISynchronizedInputProvider
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_ISynchronizedInputProvider_INTERFACE_DEFINED_

IFNDEF _ITableProvider_INTERFACE_DEFINED_
    _ITableProvider_INTERFACE_DEFINED_  EQU 1

    ITableProvider_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FITableProvider_QueryInterface TYPEDEF PTR ITableProvider_QueryInterface

    ITableProvider_GetRowHeaders TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FITableProvider_GetRowHeaders TYPEDEF PTR ITableProvider_GetRowHeaders

    ITableProvider_GetColumnHeaders TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FITableProvider_GetColumnHeaders TYPEDEF PTR ITableProvider_GetColumnHeaders

    ITableProvider_get_RowOrColumnMajor TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FITableProvider_get_RowOrColumnMajor TYPEDEF PTR ITableProvider_get_RowOrColumnMajor

    STITableProvider STRUCT
        QueryInterface          FITableProvider_QueryInterface ?
        AddRef                  XPTR ?
        Release                 XPTR ?
        GetRowHeaders           FITableProvider_GetRowHeaders ?
        GetColumnHeaders        FITableProvider_GetColumnHeaders ?
        get_RowOrColumnMajor    FITableProvider_get_RowOrColumnMajor ?
    STITableProvider ENDS
 
    ITableProvider MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STITableProvider PTR[PPVREGISTER])., &Function,ppvITableProvider
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvITableProvider
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_ITableProvider_INTERFACE_DEFINED_

IFNDEF _ITableItemProvider_INTERFACE_DEFINED_
    _ITableItemProvider_INTERFACE_DEFINED_  EQU 1

    ITableItemProvider_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FITableItemProvider_QueryInterface TYPEDEF PTR ITableItemProvider_QueryInterface

    ITableItemProvider_GetRowHeaderItems TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FITableItemProvider_GetRowHeaderItems TYPEDEF PTR ITableItemProvider_GetRowHeaderItems

    ITableItemProvider_GetColumnHeaderItems TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FITableItemProvider_GetColumnHeaderItems TYPEDEF PTR ITableItemProvider_GetColumnHeaderItems

    STITableItemProvider STRUCT
        QueryInterface          FITableItemProvider_QueryInterface ?
        AddRef                  XPTR ?
        Release                 XPTR ?
        GetRowHeaderItems       FITableItemProvider_GetRowHeaderItems ?
        GetColumnHeaderItems    FITableItemProvider_GetColumnHeaderItems ?
    STITableItemProvider ENDS
 
    ITableItemProvider MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STITableItemProvider PTR[PPVREGISTER])., &Function,ppvITableItemProvider
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvITableItemProvider
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_ITableItemProvider_INTERFACE_DEFINED_

IFNDEF _IToggleProvider_INTERFACE_DEFINED_
    _IToggleProvider_INTERFACE_DEFINED_ EQU 1

    IToggleProvider_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FIToggleProvider_QueryInterface TYPEDEF PTR IToggleProvider_QueryInterface

    IToggleProvider_get_ToggleState TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIToggleProvider_get_ToggleState TYPEDEF PTR IToggleProvider_get_ToggleState

    STIToggleProvider STRUCT
        QueryInterface  FIToggleProvider_QueryInterface ?
        AddRef          XPTR ?
        Release         XPTR ?
        Toggle          XPTR ?
        get_ToggleState FIToggleProvider_get_ToggleState ?
    STIToggleProvider ENDS
 
    IToggleProvider MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STIToggleProvider PTR[PPVREGISTER])., &Function,ppvIToggleProvider
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvIToggleProvider
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_IToggleProvider_INTERFACE_DEFINED_

IFNDEF _ITransformProvider_INTERFACE_DEFINED_
    _ITransformProvider_INTERFACE_DEFINED_  EQU 1

    ITransformProvider_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FITransformProvider_QueryInterface TYPEDEF PTR ITransformProvider_QueryInterface

    ITransformProvider_Move TYPEDEF PROTO :XWORD, x:REAL8, y:REAL8 
    FITransformProvider_Move TYPEDEF PTR ITransformProvider_Move

    ITransformProvider_Resize TYPEDEF PROTO :XWORD, width1:REAL8, height:REAL8 
    FITransformProvider_Resize TYPEDEF PTR ITransformProvider_Resize

    ITransformProvider_Rotate TYPEDEF PROTO :XWORD, degrees:REAL8 
    FITransformProvider_Rotate TYPEDEF PTR ITransformProvider_Rotate

    ITransformProvider_get_CanMove TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FITransformProvider_get_CanMove TYPEDEF PTR ITransformProvider_get_CanMove

    ITransformProvider_get_CanResize TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FITransformProvider_get_CanResize TYPEDEF PTR ITransformProvider_get_CanResize

    ITransformProvider_get_CanRotate TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FITransformProvider_get_CanRotate TYPEDEF PTR ITransformProvider_get_CanRotate

    STITransformProvider STRUCT
        QueryInterface  FITransformProvider_QueryInterface ?
        AddRef          XPTR ?
        Release         XPTR ?
        Move            FITransformProvider_Move ?
        Resize          FITransformProvider_Resize ?
        Rotate          FITransformProvider_Rotate ?
        get_CanMove     FITransformProvider_get_CanMove ?
        get_CanResize   FITransformProvider_get_CanResize ?
        get_CanRotate   FITransformProvider_get_CanRotate ?
    STITransformProvider ENDS
 
    ITransformProvider MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STITransformProvider PTR[PPVREGISTER])., &Function,ppvITransformProvider
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvITransformProvider
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_ITransformProvider_INTERFACE_DEFINED_

IFNDEF _IValueProvider_INTERFACE_DEFINED_
    _IValueProvider_INTERFACE_DEFINED_  EQU 1

    IValueProvider_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FIValueProvider_QueryInterface TYPEDEF PTR IValueProvider_QueryInterface

    IValueProvider_SetValue TYPEDEF PROTO :XWORD, val:XWORD
    FIValueProvider_SetValue TYPEDEF PTR IValueProvider_SetValue

    IValueProvider_get_Value TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIValueProvider_get_Value TYPEDEF PTR IValueProvider_get_Value

    IValueProvider_get_IsReadOnly TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIValueProvider_get_IsReadOnly TYPEDEF PTR IValueProvider_get_IsReadOnly

    STIValueProvider STRUCT
        QueryInterface  FIValueProvider_QueryInterface ?
        AddRef          XPTR ?
        Release         XPTR ?
        SetValue        FIValueProvider_SetValue ?
        get_Value       FIValueProvider_get_Value ?
        get_IsReadOnly  FIValueProvider_get_IsReadOnly ?
    STIValueProvider ENDS
 
    IValueProvider MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STIValueProvider PTR[PPVREGISTER])., &Function,ppvIValueProvider
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvIValueProvider
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_IValueProvider_INTERFACE_DEFINED_

IFNDEF _IWindowProvider_INTERFACE_DEFINED_
    _IWindowProvider_INTERFACE_DEFINED_ EQU 1

    IWindowProvider_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FIWindowProvider_QueryInterface TYPEDEF PTR IWindowProvider_QueryInterface

    IWindowProvider_WaitForInputIdle1 TYPEDEF PROTO :XWORD, milliseconds:XWORD, pRetVal:XPTR
    FIWindowProvider_WaitForInputIdle1 TYPEDEF PTR IWindowProvider_WaitForInputIdle1

    IWindowProvider_get_CanMaximize TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIWindowProvider_get_CanMaximize TYPEDEF PTR IWindowProvider_get_CanMaximize

    IWindowProvider_get_CanMinimize TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIWindowProvider_get_CanMinimize TYPEDEF PTR IWindowProvider_get_CanMinimize

    IWindowProvider_get_IsModal TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIWindowProvider_get_IsModal TYPEDEF PTR IWindowProvider_get_IsModal

    IWindowProvider_get_WindowVisualState TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIWindowProvider_get_WindowVisualState TYPEDEF PTR IWindowProvider_get_WindowVisualState

    IWindowProvider_get_WindowInteractionState TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIWindowProvider_get_WindowInteractionState TYPEDEF PTR IWindowProvider_get_WindowInteractionState

    IWindowProvider_get_IsTopmost TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIWindowProvider_get_IsTopmost TYPEDEF PTR IWindowProvider_get_IsTopmost

    STIWindowProvider STRUCT
        QueryInterface              FIWindowProvider_QueryInterface ?
        AddRef                      XPTR ?
        Release                     XPTR ?
        SetVisualState              XPTR ?
        Close                       XPTR ?
        WaitForInputIdle1           FIWindowProvider_WaitForInputIdle1 ?
        get_CanMaximize             FIWindowProvider_get_CanMaximize ?
        get_CanMinimize             FIWindowProvider_get_CanMinimize ?
        get_IsModal                 FIWindowProvider_get_IsModal ?
        get_WindowVisualState       FIWindowProvider_get_WindowVisualState ?
        get_WindowInteractionState  FIWindowProvider_get_WindowInteractionState ?
        get_IsTopmost               FIWindowProvider_get_IsTopmost ?
    STIWindowProvider ENDS
 
    IWindowProvider MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STIWindowProvider PTR[PPVREGISTER])., &Function,ppvIWindowProvider
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvIWindowProvider
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_IWindowProvider_INTERFACE_DEFINED_

IFNDEF _ILegacyIAccessibleProvider_INTERFACE_DEFINED_
    _ILegacyIAccessibleProvider_INTERFACE_DEFINED_  EQU 1

    ILegacyIAccessibleProvider_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FILegacyIAccessibleProvider_QueryInterface TYPEDEF PTR ILegacyIAccessibleProvider_QueryInterface

    ILegacyIAccessibleProvider_SetValue TYPEDEF PROTO :XWORD, szValue:XWORD
    FILegacyIAccessibleProvider_SetValue TYPEDEF PTR ILegacyIAccessibleProvider_SetValue

    ILegacyIAccessibleProvider_GetIAccessible TYPEDEF PROTO :XWORD, ppAccessible:XPTR
    FILegacyIAccessibleProvider_GetIAccessible TYPEDEF PTR ILegacyIAccessibleProvider_GetIAccessible

    ILegacyIAccessibleProvider_get_ChildId TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FILegacyIAccessibleProvider_get_ChildId TYPEDEF PTR ILegacyIAccessibleProvider_get_ChildId

    ILegacyIAccessibleProvider_get_Name TYPEDEF PROTO :XWORD, pszName:XPTR
    FILegacyIAccessibleProvider_get_Name TYPEDEF PTR ILegacyIAccessibleProvider_get_Name

    ILegacyIAccessibleProvider_get_Value TYPEDEF PROTO :XWORD, pszValue:XPTR
    FILegacyIAccessibleProvider_get_Value TYPEDEF PTR ILegacyIAccessibleProvider_get_Value

    ILegacyIAccessibleProvider_get_Description TYPEDEF PROTO :XWORD, pszDescription:XPTR
    FILegacyIAccessibleProvider_get_Description TYPEDEF PTR ILegacyIAccessibleProvider_get_Description

    ILegacyIAccessibleProvider_get_Role TYPEDEF PROTO :XWORD, pdwRole:XPTR
    FILegacyIAccessibleProvider_get_Role TYPEDEF PTR ILegacyIAccessibleProvider_get_Role

    ILegacyIAccessibleProvider_get_State TYPEDEF PROTO :XWORD, pdwState:XPTR
    FILegacyIAccessibleProvider_get_State TYPEDEF PTR ILegacyIAccessibleProvider_get_State

    ILegacyIAccessibleProvider_get_Help TYPEDEF PROTO :XWORD, pszHelp:XPTR
    FILegacyIAccessibleProvider_get_Help TYPEDEF PTR ILegacyIAccessibleProvider_get_Help

    ILegacyIAccessibleProvider_get_KeyboardShortcut TYPEDEF PROTO :XWORD, pszKeyboardShortcut:XPTR
    FILegacyIAccessibleProvider_get_KeyboardShortcut TYPEDEF PTR ILegacyIAccessibleProvider_get_KeyboardShortcut

    ILegacyIAccessibleProvider_GetSelection TYPEDEF PROTO :XWORD, pvarSelectedChildren:XPTR
    FILegacyIAccessibleProvider_GetSelection TYPEDEF PTR ILegacyIAccessibleProvider_GetSelection

    ILegacyIAccessibleProvider_get_DefaultAction TYPEDEF PROTO :XWORD, pszDefaultAction:XPTR
    FILegacyIAccessibleProvider_get_DefaultAction TYPEDEF PTR ILegacyIAccessibleProvider_get_DefaultAction

    STILegacyIAccessibleProvider STRUCT
        QueryInterface          FILegacyIAccessibleProvider_QueryInterface ?
        AddRef                  XPTR ?
        Release                 XPTR ?
        Select1                 XPTR ?
        DoDefaultAction         XPTR ?
        SetValue                FILegacyIAccessibleProvider_SetValue ?
        GetIAccessible          FILegacyIAccessibleProvider_GetIAccessible ?
        get_ChildId             FILegacyIAccessibleProvider_get_ChildId ?
        get_Name                FILegacyIAccessibleProvider_get_Name ?
        get_Value               FILegacyIAccessibleProvider_get_Value ?
        get_Description         FILegacyIAccessibleProvider_get_Description ?
        get_Role                FILegacyIAccessibleProvider_get_Role ?
        get_State               FILegacyIAccessibleProvider_get_State ?
        get_Help                FILegacyIAccessibleProvider_get_Help ?
        get_KeyboardShortcut    FILegacyIAccessibleProvider_get_KeyboardShortcut ?
        GetSelection            FILegacyIAccessibleProvider_GetSelection ?
        get_DefaultAction       FILegacyIAccessibleProvider_get_DefaultAction ?
    STILegacyIAccessibleProvider ENDS
 
    ILegacyIAccessibleProvider MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STILegacyIAccessibleProvider PTR[PPVREGISTER])., &Function,ppvILegacyIAccessibleProvider
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvILegacyIAccessibleProvider
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_ILegacyIAccessibleProvider_INTERFACE_DEFINED_
 
IFNDEF _IItemContainerProvider_INTERFACE_DEFINED_
    _IItemContainerProvider_INTERFACE_DEFINED_  EQU 1

    IItemContainerProvider_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FIItemContainerProvider_QueryInterface TYPEDEF PTR IItemContainerProvider_QueryInterface

    IItemContainerProvider_FindItemByProperty TYPEDEF PROTO :XWORD, pStartAfter:XPTR, propertyId:XWORD, value:VARIANT, pFound:XPTR
    FIItemContainerProvider_FindItemByProperty TYPEDEF PTR IItemContainerProvider_FindItemByProperty

    STIItemContainerProvider STRUCT
        QueryInterface      FIItemContainerProvider_QueryInterface ?
        AddRef              XPTR ?
        Release             XPTR ?
        FindItemByProperty  FIItemContainerProvider_FindItemByProperty ?
    STIItemContainerProvider ENDS

    IItemContainerProvider MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STIItemContainerProvider PTR[PPVREGISTER])., &Function,ppvIItemContainerProvider
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvIItemContainerProvider
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_IItemContainerProvider_INTERFACE_DEFINED_

IFNDEF _IVirtualizedItemProvider_INTERFACE_DEFINED_
    _IVirtualizedItemProvider_INTERFACE_DEFINED_    EQU 1

    IVirtualizedItemProvider_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FIVirtualizedItemProvider_QueryInterface TYPEDEF PTR IVirtualizedItemProvider_QueryInterface

    STIVirtualizedItemProvider STRUCT
        QueryInterface  FIVirtualizedItemProvider_QueryInterface ?
        AddRef          XPTR ?
        Release         XPTR ?
        Realize         XPTR ?
    STIVirtualizedItemProvider ENDS
 
    IVirtualizedItemProvider MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STIVirtualizedItemProvider PTR[PPVREGISTER])., &Function,ppvIVirtualizedItemProvider
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvIVirtualizedItemProvider
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_IVirtualizedItemProvider_INTERFACE_DEFINED_

IFNDEF _IObjectModelProvider_INTERFACE_DEFINED_
    _IObjectModelProvider_INTERFACE_DEFINED_    EQU 1

    IObjectModelProvider_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FIObjectModelProvider_QueryInterface TYPEDEF PTR IObjectModelProvider_QueryInterface

    IObjectModelProvider_GetUnderlyingObjectModel TYPEDEF PROTO :XWORD, ppUnknown:XPTR
    FIObjectModelProvider_GetUnderlyingObjectModel TYPEDEF PTR IObjectModelProvider_GetUnderlyingObjectModel

    STIObjectModelProvider STRUCT
        QueryInterface              FIObjectModelProvider_QueryInterface ?
        AddRef                      XPTR ?
        Release                     XPTR ?
        GetUnderlyingObjectModel    FIObjectModelProvider_GetUnderlyingObjectModel ?
    STIObjectModelProvider ENDS

 
    IObjectModelProvider MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STIObjectModelProvider PTR[PPVREGISTER])., &Function,ppvIObjectModelProvider
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvIObjectModelProvider
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_IObjectModelProvider_INTERFACE_DEFINED_

IFNDEF _IAnnotationProvider_INTERFACE_DEFINED_
    _IAnnotationProvider_INTERFACE_DEFINED_ EQU 1

    IAnnotationProvider_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FIAnnotationProvider_QueryInterface TYPEDEF PTR IAnnotationProvider_QueryInterface

    IAnnotationProvider_get_AnnotationTypeId TYPEDEF PROTO :XWORD, retVal:XWORD
    FIAnnotationProvider_get_AnnotationTypeId TYPEDEF PTR IAnnotationProvider_get_AnnotationTypeId

    IAnnotationProvider_get_AnnotationTypeName TYPEDEF PROTO :XWORD, retVal:XWORD
    FIAnnotationProvider_get_AnnotationTypeName TYPEDEF PTR IAnnotationProvider_get_AnnotationTypeName

    IAnnotationProvider_get_Author TYPEDEF PROTO :XWORD, retVal:XPTR
    FIAnnotationProvider_get_Author TYPEDEF PTR IAnnotationProvider_get_Author

    IAnnotationProvider_get_DateTime TYPEDEF PROTO :XWORD, retVal:XPTR
    FIAnnotationProvider_get_DateTime TYPEDEF PTR IAnnotationProvider_get_DateTime

    IAnnotationProvider_get_Target TYPEDEF PROTO :XWORD, retVal:XPTR
    FIAnnotationProvider_get_Target TYPEDEF PTR IAnnotationProvider_get_Target

    STIAnnotationProvider STRUCT
        QueryInterface          FIAnnotationProvider_QueryInterface ?
        AddRef                  XPTR ?
        Release                 XPTR ?
        get_AnnotationTypeId    FIAnnotationProvider_get_AnnotationTypeId ?
        get_AnnotationTypeName  FIAnnotationProvider_get_AnnotationTypeName ?
        get_Author              FIAnnotationProvider_get_Author ?
        get_DateTime            FIAnnotationProvider_get_DateTime ?
        get_Target              FIAnnotationProvider_get_Target ?
    STIAnnotationProvider ENDS
 
    IAnnotationProvider MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STIAnnotationProvider PTR[PPVREGISTER])., &Function,ppvIAnnotationProvider
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvIAnnotationProvider
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_IAnnotationProvider_INTERFACE_DEFINED_

IFNDEF _IStylesProvider_INTERFACE_DEFINED_
    _IStylesProvider_INTERFACE_DEFINED_ EQU 1

    IStylesProvider_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FIStylesProvider_QueryInterface TYPEDEF PTR IStylesProvider_QueryInterface

    IStylesProvider_get_StyleId TYPEDEF PROTO :XWORD, retVal:XWORD
    FIStylesProvider_get_StyleId TYPEDEF PTR IStylesProvider_get_StyleId

    IStylesProvider_get_StyleName TYPEDEF PROTO :XWORD, retVal:XWORD
    FIStylesProvider_get_StyleName TYPEDEF PTR IStylesProvider_get_StyleName

    IStylesProvider_get_FillColor TYPEDEF PROTO :XWORD, retVal:XWORD
    FIStylesProvider_get_FillColor TYPEDEF PTR IStylesProvider_get_FillColor

    IStylesProvider_get_FillPatternStyle TYPEDEF PROTO :XWORD, retVal:XWORD
    FIStylesProvider_get_FillPatternStyle TYPEDEF PTR IStylesProvider_get_FillPatternStyle

    IStylesProvider_get_Shape TYPEDEF PROTO :XWORD, retVal:XWORD
    FIStylesProvider_get_Shape TYPEDEF PTR IStylesProvider_get_Shape

    IStylesProvider_get_FillPatternColor TYPEDEF PROTO :XWORD, retVal:XWORD
    FIStylesProvider_get_FillPatternColor TYPEDEF PTR IStylesProvider_get_FillPatternColor

    IStylesProvider_get_ExtendedProperties TYPEDEF PROTO :XWORD, retVal:XWORD
    FIStylesProvider_get_ExtendedProperties TYPEDEF PTR IStylesProvider_get_ExtendedProperties

    STIStylesProvider STRUCT
        QueryInterface          FIStylesProvider_QueryInterface ?
        AddRef                  XPTR ?
        Release                 XPTR ?
        get_StyleId             FIStylesProvider_get_StyleId ?
        get_StyleName           FIStylesProvider_get_StyleName ?
        get_FillColor           FIStylesProvider_get_FillColor ?
        get_FillPatternStyle    FIStylesProvider_get_FillPatternStyle ?
        get_Shape               FIStylesProvider_get_Shape ?
        get_FillPatternColor    FIStylesProvider_get_FillPatternColor ?
        get_ExtendedProperties  FIStylesProvider_get_ExtendedProperties ?
    STIStylesProvider ENDS
 
    IStylesProvider MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STIStylesProvider PTR[PPVREGISTER])., &Function,ppvIStylesProvider
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvIStylesProvider
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_IStylesProvider_INTERFACE_DEFINED_

IFNDEF _ISpreadsheetProvider_INTERFACE_DEFINED_
    _ISpreadsheetProvider_INTERFACE_DEFINED_    EQU 1

    ISpreadsheetProvider_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FISpreadsheetProvider_QueryInterface TYPEDEF PTR ISpreadsheetProvider_QueryInterface

    ISpreadsheetProvider_GetItemByName TYPEDEF PROTO :XWORD, aname:XWORD, pRetVal:XPTR
    FISpreadsheetProvider_GetItemByName TYPEDEF PTR ISpreadsheetProvider_GetItemByName

    STISpreadsheetProvider STRUCT
        QueryInterface  FISpreadsheetProvider_QueryInterface ?
        AddRef          XPTR ?
        Release         XPTR ?
        GetItemByName   FISpreadsheetProvider_GetItemByName ?
    STISpreadsheetProvider ENDS
 
    ISpreadsheetProvider MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STISpreadsheetProvider PTR[PPVREGISTER])., &Function,ppvISpreadsheetProvider
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvISpreadsheetProvider
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_ISpreadsheetProvider_INTERFACE_DEFINED_

IFNDEF _ISpreadsheetItemProvider_INTERFACE_DEFINED_
    _ISpreadsheetItemProvider_INTERFACE_DEFINED_    EQU 1

    ISpreadsheetItemProvider_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FISpreadsheetItemProvider_QueryInterface TYPEDEF PTR ISpreadsheetItemProvider_QueryInterface

    ISpreadsheetItemProvider_get_Formula TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FISpreadsheetItemProvider_get_Formula TYPEDEF PTR ISpreadsheetItemProvider_get_Formula

    ISpreadsheetItemProvider_GetAnnotationObjects TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FISpreadsheetItemProvider_GetAnnotationObjects TYPEDEF PTR ISpreadsheetItemProvider_GetAnnotationObjects

    ISpreadsheetItemProvider_GetAnnotationTypes TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FISpreadsheetItemProvider_GetAnnotationTypes TYPEDEF PTR ISpreadsheetItemProvider_GetAnnotationTypes

    STISpreadsheetItemProvider STRUCT
        QueryInterface          FISpreadsheetItemProvider_QueryInterface ?
        AddRef                  XPTR ?
        Release                 XPTR ?
        get_Formula             FISpreadsheetItemProvider_get_Formula ?
        GetAnnotationObjects    FISpreadsheetItemProvider_GetAnnotationObjects ?
        GetAnnotationTypes      FISpreadsheetItemProvider_GetAnnotationTypes ?
    STISpreadsheetItemProvider ENDS
 
    ISpreadsheetItemProvider MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STISpreadsheetItemProvider PTR[PPVREGISTER])., &Function,ppvISpreadsheetItemProvider
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvISpreadsheetItemProvider
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_ISpreadsheetItemProvider_INTERFACE_DEFINED_

IFNDEF _ITransformProvider2_INTERFACE_DEFINED_
    _ITransformProvider2_INTERFACE_DEFINED_ EQU 1

    ITransformProvider2_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FITransformProvider2_QueryInterface TYPEDEF PTR ITransformProvider2_QueryInterface

    ITransformProvider2_Move TYPEDEF PROTO :XWORD, x:REAL8, y:REAL8 
    FITransformProvider2_Move TYPEDEF PTR ITransformProvider2_Move

    ITransformProvider2_Resize TYPEDEF PROTO :XWORD, width1:REAL8, height:REAL8 
    FITransformProvider2_Resize TYPEDEF PTR ITransformProvider2_Resize

    ITransformProvider2_Rotate TYPEDEF PROTO :XWORD, degrees:REAL8 
    FITransformProvider2_Rotate TYPEDEF PTR ITransformProvider2_Rotate

    ITransformProvider2_get_CanMove TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FITransformProvider2_get_CanMove TYPEDEF PTR ITransformProvider2_get_CanMove

    ITransformProvider2_get_CanResize TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FITransformProvider2_get_CanResize TYPEDEF PTR ITransformProvider2_get_CanResize

    ITransformProvider2_get_CanRotate TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FITransformProvider2_get_CanRotate TYPEDEF PTR ITransformProvider2_get_CanRotate

    ITransformProvider2_Zoom TYPEDEF PROTO :XWORD, zoom:REAL8 
    FITransformProvider2_Zoom TYPEDEF PTR ITransformProvider2_Zoom

    ITransformProvider2_get_CanZoom TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FITransformProvider2_get_CanZoom TYPEDEF PTR ITransformProvider2_get_CanZoom

    ITransformProvider2_get_ZoomLevel TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FITransformProvider2_get_ZoomLevel TYPEDEF PTR ITransformProvider2_get_ZoomLevel

    ITransformProvider2_get_ZoomMinimum TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FITransformProvider2_get_ZoomMinimum TYPEDEF PTR ITransformProvider2_get_ZoomMinimum

    ITransformProvider2_get_ZoomMaximum TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FITransformProvider2_get_ZoomMaximum TYPEDEF PTR ITransformProvider2_get_ZoomMaximum

    STITransformProvider2 STRUCT
        QueryInterface  FITransformProvider2_QueryInterface ?
        AddRef          XPTR ?
        Release         XPTR ?
        Move            FITransformProvider2_Move ?
        Resize          FITransformProvider2_Resize ?
        Rotate          FITransformProvider2_Rotate ?
        get_CanMove     FITransformProvider2_get_CanMove ?
        get_CanResize   FITransformProvider2_get_CanResize ?
        get_CanRotate   FITransformProvider2_get_CanRotate ?
        Zoom            FITransformProvider2_Zoom ?
        get_CanZoom     FITransformProvider2_get_CanZoom ?
        get_ZoomLevel   FITransformProvider2_get_ZoomLevel ?
        get_ZoomMinimum FITransformProvider2_get_ZoomMinimum ?
        get_ZoomMaximum FITransformProvider2_get_ZoomMaximum ?
        ZoomByUnit      XPTR ?
    STITransformProvider2 ENDS

    ITransformProvider2 MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STITransformProvider2 PTR[PPVREGISTER])., &Function,ppvITransformProvider2
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvITransformProvider2
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_ITransformProvider2_INTERFACE_DEFINED_

IFNDEF _IDragProvider_INTERFACE_DEFINED_
    _IDragProvider_INTERFACE_DEFINED_   EQU 1

    IDragProvider_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FIDragProvider_QueryInterface TYPEDEF PTR IDragProvider_QueryInterface

    IDragProvider_get_IsGrabbed TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIDragProvider_get_IsGrabbed TYPEDEF PTR IDragProvider_get_IsGrabbed

    IDragProvider_get_DropEffect TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIDragProvider_get_DropEffect TYPEDEF PTR IDragProvider_get_DropEffect

    IDragProvider_get_DropEffects TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIDragProvider_get_DropEffects TYPEDEF PTR IDragProvider_get_DropEffects

    IDragProvider_GetGrabbedItems TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIDragProvider_GetGrabbedItems TYPEDEF PTR IDragProvider_GetGrabbedItems

    STIDragProvider STRUCT
        QueryInterface  FIDragProvider_QueryInterface ?
        AddRef          XPTR ?
        Release         XPTR ?
        get_IsGrabbed   FIDragProvider_get_IsGrabbed ?
        get_DropEffect  FIDragProvider_get_DropEffect ?
        get_DropEffects FIDragProvider_get_DropEffects ?
        GetGrabbedItems FIDragProvider_GetGrabbedItems ?
    STIDragProvider ENDS
 
    IDragProvider MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STIDragProvider PTR[PPVREGISTER])., &Function,ppvIDragProvider
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvIDragProvider
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_IDragProvider_INTERFACE_DEFINED_

IFNDEF _IDropTargetProvider_INTERFACE_DEFINED_
    _IDropTargetProvider_INTERFACE_DEFINED_ EQU 1

    IDropTargetProvider_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FIDropTargetProvider_QueryInterface TYPEDEF PTR IDropTargetProvider_QueryInterface

    IDropTargetProvider_get_DropTargetEffect TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIDropTargetProvider_get_DropTargetEffect TYPEDEF PTR IDropTargetProvider_get_DropTargetEffect

    IDropTargetProvider_get_DropTargetEffects TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FIDropTargetProvider_get_DropTargetEffects TYPEDEF PTR IDropTargetProvider_get_DropTargetEffects

    STIDropTargetProvider STRUCT
        QueryInterface          FIDropTargetProvider_QueryInterface ?
        AddRef                  XPTR ?
        Release                 XPTR ?
        get_DropTargetEffect    FIDropTargetProvider_get_DropTargetEffect ?
        get_DropTargetEffects   FIDropTargetProvider_get_DropTargetEffects ?
    STIDropTargetProvider ENDS

    IDropTargetProvider MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STIDropTargetProvider PTR[PPVREGISTER])., &Function,ppvIDropTargetProvider
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvIDropTargetProvider
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_IDropTargetProvider_INTERFACE_DEFINED_

IFNDEF _ITextRangeProvider_INTERFACE_DEFINED_
    _ITextRangeProvider_INTERFACE_DEFINED_  EQU 1

    ITextRangeProvider_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FITextRangeProvider_QueryInterface TYPEDEF PTR ITextRangeProvider_QueryInterface

    ITextRangeProvider_Clone TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FITextRangeProvider_Clone TYPEDEF PTR ITextRangeProvider_Clone

    ITextRangeProvider_Compare TYPEDEF PROTO :XWORD, range:XWORD, pRetVal:XPTR
    FITextRangeProvider_Compare TYPEDEF PTR ITextRangeProvider_Compare

    ITextRangeProvider_CompareEndpoints TYPEDEF PROTO :XWORD, endpoint:XWORD, targetRange:XWORD, targetEndpoint:XWORD, pRetVal:XPTR
    FITextRangeProvider_CompareEndpoints TYPEDEF PTR ITextRangeProvider_CompareEndpoints

    ITextRangeProvider_FindAttribute TYPEDEF PROTO :XWORD, attributeId:XWORD, val:VARIANT, backward:XWORD, pRetVal:XPTR
    FITextRangeProvider_FindAttribute TYPEDEF PTR ITextRangeProvider_FindAttribute

    ITextRangeProvider_FindText1 TYPEDEF PROTO :XWORD, text:XWORD, backward:XWORD, ignoreCase:XWORD, pRetVal:XPTR
    FITextRangeProvider_FindText1 TYPEDEF PTR ITextRangeProvider_FindText1

    ITextRangeProvider_GetAttributeValue TYPEDEF PROTO :XWORD, attributeId:XWORD, pRetVal:XPTR
    FITextRangeProvider_GetAttributeValue TYPEDEF PTR ITextRangeProvider_GetAttributeValue

    ITextRangeProvider_GetBoundingRectangles TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FITextRangeProvider_GetBoundingRectangles TYPEDEF PTR ITextRangeProvider_GetBoundingRectangles

    ITextRangeProvider_GetEnclosingElement TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FITextRangeProvider_GetEnclosingElement TYPEDEF PTR ITextRangeProvider_GetEnclosingElement

    ITextRangeProvider_GetText TYPEDEF PROTO :XWORD, maxLength:XWORD, pRetVal:XPTR
    FITextRangeProvider_GetText TYPEDEF PTR ITextRangeProvider_GetText

    ITextRangeProvider_Move TYPEDEF PROTO :XWORD, unit:XWORD, count:XWORD, pRetVal:XPTR
    FITextRangeProvider_Move TYPEDEF PTR ITextRangeProvider_Move

    ITextRangeProvider_MoveEndpointByUnit TYPEDEF PROTO :XWORD, endpoint:XWORD, unit:XWORD, count:XWORD, pRetVal:XPTR
    FITextRangeProvider_MoveEndpointByUnit TYPEDEF PTR ITextRangeProvider_MoveEndpointByUnit

    ITextRangeProvider_MoveEndpointByRange TYPEDEF PROTO :XWORD, endpoint:XWORD, targetRange:XWORD, targetEndpoint:XWORD 
    FITextRangeProvider_MoveEndpointByRange TYPEDEF PTR ITextRangeProvider_MoveEndpointByRange

    ITextRangeProvider_GetChildren TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FITextRangeProvider_GetChildren TYPEDEF PTR ITextRangeProvider_GetChildren

    STITextRangeProvider STRUCT
        QueryInterface          FITextRangeProvider_QueryInterface ?
        AddRef                  XPTR ?
        Release                 XPTR ?
        Clone                   FITextRangeProvider_Clone ?
        Compare                 FITextRangeProvider_Compare ?
        CompareEndpoints        FITextRangeProvider_CompareEndpoints ?
        ExpandToEnclosingUnit   XPTR ?
        FindAttribute           FITextRangeProvider_FindAttribute ?
        FindText1               FITextRangeProvider_FindText1 ?
        GetAttributeValue       FITextRangeProvider_GetAttributeValue ?
        GetBoundingRectangles   FITextRangeProvider_GetBoundingRectangles ?
        GetEnclosingElement     FITextRangeProvider_GetEnclosingElement ?
        GetText                 FITextRangeProvider_GetText ?
        Move                    FITextRangeProvider_Move ?
        MoveEndpointByUnit      FITextRangeProvider_MoveEndpointByUnit ?
        MoveEndpointByRange     FITextRangeProvider_MoveEndpointByRange ?
        Select1                 XPTR ?
        AddToSelection          XPTR ?
        RemoveFromSelection     XPTR ?
        ScrollIntoView          XPTR ?
        GetChildren             FITextRangeProvider_GetChildren ?
    STITextRangeProvider ENDS
 
    ITextRangeProvider MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STITextRangeProvider PTR[PPVREGISTER])., &Function,ppvITextRangeProvider
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvITextRangeProvider
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_ITextRangeProvider_INTERFACE_DEFINED_

IFNDEF _ITextProvider_INTERFACE_DEFINED_
    _ITextProvider_INTERFACE_DEFINED_   EQU 1

    ITextProvider_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FITextProvider_QueryInterface TYPEDEF PTR ITextProvider_QueryInterface

    ITextProvider_GetSelection TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FITextProvider_GetSelection TYPEDEF PTR ITextProvider_GetSelection

    ITextProvider_GetVisibleRanges TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FITextProvider_GetVisibleRanges TYPEDEF PTR ITextProvider_GetVisibleRanges

    ITextProvider_RangeFromChild TYPEDEF PROTO :XWORD, childElement:XWORD, pRetVal:XPTR
    FITextProvider_RangeFromChild TYPEDEF PTR ITextProvider_RangeFromChild

    ITextProvider_RangeFromPoint TYPEDEF PROTO :XWORD, point:UiaPoint, pRetVal:XPTR
    FITextProvider_RangeFromPoint TYPEDEF PTR ITextProvider_RangeFromPoint

    ITextProvider_get_DocumentRange TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FITextProvider_get_DocumentRange TYPEDEF PTR ITextProvider_get_DocumentRange

    ITextProvider_get_SupportedTextSelection TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FITextProvider_get_SupportedTextSelection TYPEDEF PTR ITextProvider_get_SupportedTextSelection

    STITextProvider STRUCT
        QueryInterface              FITextProvider_QueryInterface ?
        AddRef                      XPTR ?
        Release                     XPTR ?
        GetSelection                FITextProvider_GetSelection ?
        GetVisibleRanges            FITextProvider_GetVisibleRanges ?
        RangeFromChild              FITextProvider_RangeFromChild ?
        RangeFromPoint              FITextProvider_RangeFromPoint ?
        get_DocumentRange           FITextProvider_get_DocumentRange ?
        get_SupportedTextSelection  FITextProvider_get_SupportedTextSelection ?
    STITextProvider ENDS

    ITextProvider MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STITextProvider PTR[PPVREGISTER])., &Function,ppvITextProvider
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvITextProvider
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_ITextProvider_INTERFACE_DEFINED_

IFNDEF _ITextProvider2_INTERFACE_DEFINED_
    _ITextProvider2_INTERFACE_DEFINED_  EQU 1

    ITextProvider2_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FITextProvider2_QueryInterface TYPEDEF PTR ITextProvider2_QueryInterface

    ITextProvider2_GetSelection TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FITextProvider2_GetSelection TYPEDEF PTR ITextProvider2_GetSelection

    ITextProvider2_GetVisibleRanges TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FITextProvider2_GetVisibleRanges TYPEDEF PTR ITextProvider2_GetVisibleRanges

    ITextProvider2_RangeFromChild TYPEDEF PROTO :XWORD, childElement:XWORD, pRetVal:XPTR
    FITextProvider2_RangeFromChild TYPEDEF PTR ITextProvider2_RangeFromChild

    ITextProvider2_RangeFromPoint TYPEDEF PROTO :XWORD, point:UiaPoint, pRetVal:XPTR
    FITextProvider2_RangeFromPoint TYPEDEF PTR ITextProvider2_RangeFromPoint

    ITextProvider2_get_DocumentRange TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FITextProvider2_get_DocumentRange TYPEDEF PTR ITextProvider2_get_DocumentRange

    ITextProvider2_get_SupportedTextSelection TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FITextProvider2_get_SupportedTextSelection TYPEDEF PTR ITextProvider2_get_SupportedTextSelection

    ITextProvider2_RangeFromAnnotation TYPEDEF PROTO :XWORD, annotationElement:XWORD, pRetVal:XPTR
    FITextProvider2_RangeFromAnnotation TYPEDEF PTR ITextProvider2_RangeFromAnnotation

    ITextProvider2_GetCaretRange TYPEDEF PROTO :XWORD, isActive:XWORD, pRetVal:XPTR
    FITextProvider2_GetCaretRange TYPEDEF PTR ITextProvider2_GetCaretRange

    STITextProvider2 STRUCT
        QueryInterface              FITextProvider2_QueryInterface ?
        AddRef                      XPTR ?
        Release                     XPTR ?
        GetSelection                FITextProvider2_GetSelection ?
        GetVisibleRanges            FITextProvider2_GetVisibleRanges ?
        RangeFromChild              FITextProvider2_RangeFromChild ?
        RangeFromPoint              FITextProvider2_RangeFromPoint ?
        get_DocumentRange           FITextProvider2_get_DocumentRange ?
        get_SupportedTextSelection  FITextProvider2_get_SupportedTextSelection ?
        RangeFromAnnotation         FITextProvider2_RangeFromAnnotation ?
        GetCaretRange               FITextProvider2_GetCaretRange ?
    STITextProvider2 ENDS

    ITextProvider2 MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STITextProvider2 PTR[PPVREGISTER])., &Function,ppvITextProvider2
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvITextProvider2
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_ITextProvider2_INTERFACE_DEFINED_

IFNDEF _ITextEditProvider_INTERFACE_DEFINED_
    _ITextEditProvider_INTERFACE_DEFINED_   EQU 1

    ITextEditProvider_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FITextEditProvider_QueryInterface TYPEDEF PTR ITextEditProvider_QueryInterface

    ITextEditProvider_GetSelection TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FITextEditProvider_GetSelection TYPEDEF PTR ITextEditProvider_GetSelection

    ITextEditProvider_GetVisibleRanges TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FITextEditProvider_GetVisibleRanges TYPEDEF PTR ITextEditProvider_GetVisibleRanges

    ITextEditProvider_RangeFromChild TYPEDEF PROTO :XWORD, childElement:XWORD, pRetVal:XPTR
    FITextEditProvider_RangeFromChild TYPEDEF PTR ITextEditProvider_RangeFromChild

    ITextEditProvider_RangeFromPoint TYPEDEF PROTO :XWORD, point:UiaPoint, pRetVal:XPTR
    FITextEditProvider_RangeFromPoint TYPEDEF PTR ITextEditProvider_RangeFromPoint

    ITextEditProvider_get_DocumentRange TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FITextEditProvider_get_DocumentRange TYPEDEF PTR ITextEditProvider_get_DocumentRange

    ITextEditProvider_get_SupportedTextSelection TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FITextEditProvider_get_SupportedTextSelection TYPEDEF PTR ITextEditProvider_get_SupportedTextSelection

    ITextEditProvider_GetActiveComposition TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FITextEditProvider_GetActiveComposition TYPEDEF PTR ITextEditProvider_GetActiveComposition

    ITextEditProvider_GetConversionTarget TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FITextEditProvider_GetConversionTarget TYPEDEF PTR ITextEditProvider_GetConversionTarget

    STITextEditProvider STRUCT
        QueryInterface              FITextEditProvider_QueryInterface ?
        AddRef                      XPTR ?
        Release                     XPTR ?
        GetSelection                FITextEditProvider_GetSelection ?
        GetVisibleRanges            FITextEditProvider_GetVisibleRanges ?
        RangeFromChild              FITextEditProvider_RangeFromChild ?
        RangeFromPoint              FITextEditProvider_RangeFromPoint ?
        get_DocumentRange           FITextEditProvider_get_DocumentRange ?
        get_SupportedTextSelection  FITextEditProvider_get_SupportedTextSelection ?
        GetActiveComposition        FITextEditProvider_GetActiveComposition ?
        GetConversionTarget         FITextEditProvider_GetConversionTarget ?
    STITextEditProvider ENDS
 
    ITextEditProvider MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STITextEditProvider PTR[PPVREGISTER])., &Function,ppvITextEditProvider
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvITextEditProvider
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_ITextEditProvider_INTERFACE_DEFINED_

IFNDEF _ITextRangeProvider2_INTERFACE_DEFINED_
    _ITextRangeProvider2_INTERFACE_DEFINED_ EQU 1

    ITextRangeProvider2_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FITextRangeProvider2_QueryInterface TYPEDEF PTR ITextRangeProvider2_QueryInterface

    ITextRangeProvider2_Clone TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FITextRangeProvider2_Clone TYPEDEF PTR ITextRangeProvider2_Clone

    ITextRangeProvider2_Compare TYPEDEF PROTO :XWORD, range:XWORD, pRetVal:XPTR
    FITextRangeProvider2_Compare TYPEDEF PTR ITextRangeProvider2_Compare

    ITextRangeProvider2_CompareEndpoints TYPEDEF PROTO :XWORD, endpoint:XWORD, targetRange:XWORD, targetEndpoint:XWORD, pRetVal:XPTR
    FITextRangeProvider2_CompareEndpoints TYPEDEF PTR ITextRangeProvider2_CompareEndpoints

    ITextRangeProvider2_FindAttribute TYPEDEF PROTO :XWORD, attributeId:XWORD, val:VARIANT, backward:XWORD, pRetVal:XPTR
    FITextRangeProvider2_FindAttribute TYPEDEF PTR ITextRangeProvider2_FindAttribute

    ITextRangeProvider2_FindText1 TYPEDEF PROTO :XWORD, text:XWORD, backward:XWORD, ignoreCase:XWORD, pRetVal:XPTR
    FITextRangeProvider2_FindText1 TYPEDEF PTR ITextRangeProvider2_FindText1

    ITextRangeProvider2_GetAttributeValue TYPEDEF PROTO :XWORD, attributeId:XWORD, pRetVal:XPTR
    FITextRangeProvider2_GetAttributeValue TYPEDEF PTR ITextRangeProvider2_GetAttributeValue

    ITextRangeProvider2_GetBoundingRectangles TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FITextRangeProvider2_GetBoundingRectangles TYPEDEF PTR ITextRangeProvider2_GetBoundingRectangles

    ITextRangeProvider2_GetEnclosingElement TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FITextRangeProvider2_GetEnclosingElement TYPEDEF PTR ITextRangeProvider2_GetEnclosingElement

    ITextRangeProvider2_GetText TYPEDEF PROTO :XWORD, maxLength:XWORD, pRetVal:XPTR
    FITextRangeProvider2_GetText TYPEDEF PTR ITextRangeProvider2_GetText

    ITextRangeProvider2_Move TYPEDEF PROTO :XWORD, unit:XWORD, count:XWORD, pRetVal:XPTR
    FITextRangeProvider2_Move TYPEDEF PTR ITextRangeProvider2_Move

    ITextRangeProvider2_MoveEndpointByUnit TYPEDEF PROTO :XWORD, endpoint:XWORD, unit:XWORD, count:XWORD, pRetVal:XPTR
    FITextRangeProvider2_MoveEndpointByUnit TYPEDEF PTR ITextRangeProvider2_MoveEndpointByUnit

    ITextRangeProvider2_MoveEndpointByRange TYPEDEF PROTO :XWORD, endpoint:XWORD, targetRange:XWORD, targetEndpoint:XWORD 
    FITextRangeProvider2_MoveEndpointByRange TYPEDEF PTR ITextRangeProvider2_MoveEndpointByRange

    ITextRangeProvider2_GetChildren TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FITextRangeProvider2_GetChildren TYPEDEF PTR ITextRangeProvider2_GetChildren

    STITextRangeProvider2 STRUCT
        QueryInterface          FITextRangeProvider2_QueryInterface ?
        AddRef                  XPTR ?
        Release                 XPTR ?
        Clone                   FITextRangeProvider2_Clone ?
        Compare                 FITextRangeProvider2_Compare ?
        CompareEndpoints        FITextRangeProvider2_CompareEndpoints ?
        ExpandToEnclosingUnit   XPTR ?
        FindAttribute           FITextRangeProvider2_FindAttribute ?
        FindText1               FITextRangeProvider2_FindText1 ?
        GetAttributeValue       FITextRangeProvider2_GetAttributeValue ?
        GetBoundingRectangles   FITextRangeProvider2_GetBoundingRectangles ?
        GetEnclosingElement     FITextRangeProvider2_GetEnclosingElement ?
        GetText                 FITextRangeProvider2_GetText ?
        Move                    FITextRangeProvider2_Move ?
        MoveEndpointByUnit      FITextRangeProvider2_MoveEndpointByUnit ?
        MoveEndpointByRange     FITextRangeProvider2_MoveEndpointByRange ?
        Select1                 XPTR ?
        AddToSelection          XPTR ?
        RemoveFromSelection     XPTR ?
        ScrollIntoView          XPTR ?
        GetChildren             FITextRangeProvider2_GetChildren ?
        ShowContextMenu         XPTR ?
    STITextRangeProvider2 ENDS
 
    ITextRangeProvider2 MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STITextRangeProvider2 PTR[PPVREGISTER])., &Function,ppvITextRangeProvider2
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvITextRangeProvider2
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_ITextRangeProvider2_INTERFACE_DEFINED_

IFNDEF _ITextChildProvider_INTERFACE_DEFINED_
    _ITextChildProvider_INTERFACE_DEFINED_  EQU 1

    ITextChildProvider_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FITextChildProvider_QueryInterface TYPEDEF PTR ITextChildProvider_QueryInterface

    ITextChildProvider_get_TextContainer TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FITextChildProvider_get_TextContainer TYPEDEF PTR ITextChildProvider_get_TextContainer

    ITextChildProvider_get_TextRange TYPEDEF PROTO :XWORD, pRetVal:XPTR
    FITextChildProvider_get_TextRange TYPEDEF PTR ITextChildProvider_get_TextRange

    STITextChildProvider STRUCT
        QueryInterface      FITextChildProvider_QueryInterface ?
        AddRef              XPTR ?
        Release             XPTR ?
        get_TextContainer   FITextChildProvider_get_TextContainer ?
        get_TextRange       FITextChildProvider_get_TextRange ?
    STITextChildProvider ENDS
 
    ITextChildProvider MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STITextChildProvider PTR[PPVREGISTER])., &Function,ppvITextChildProvider
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvITextChildProvider
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_ITextChildProvider_INTERFACE_DEFINED_

IFNDEF _ICustomNavigationProvider_INTERFACE_DEFINED_
    _ICustomNavigationProvider_INTERFACE_DEFINED_   EQU 1

    ICustomNavigationProvider_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FICustomNavigationProvider_QueryInterface TYPEDEF PTR ICustomNavigationProvider_QueryInterface

    ICustomNavigationProvider_Navigate TYPEDEF PROTO :XWORD, direction:XWORD, pRetVal:XPTR
    FICustomNavigationProvider_Navigate TYPEDEF PTR ICustomNavigationProvider_Navigate

    STICustomNavigationProvider STRUCT
        QueryInterface  FICustomNavigationProvider_QueryInterface ?
        AddRef          XPTR ?
        Release         XPTR ?
        Navigate        FICustomNavigationProvider_Navigate ?
    STICustomNavigationProvider ENDS
 
    ICustomNavigationProvider MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STICustomNavigationProvider PTR[PPVREGISTER])., &Function,ppvICustomNavigationProvider
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvICustomNavigationProvider
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_ICustomNavigationProvider_INTERFACE_DEFINED_

IFNDEF _IUIAutomationPatternInstance_INTERFACE_DEFINED_
    _IUIAutomationPatternInstance_INTERFACE_DEFINED_ EQU 1

    IUIAutomationPatternInstance_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FIUIAutomationPatternInstance_QueryInterface TYPEDEF PTR IUIAutomationPatternInstance_QueryInterface

    IUIAutomationPatternInstance_GetProperty1 TYPEDEF PROTO :XWORD, index:XWORD, cached:XWORD, atype:XWORD, pPtr:XPTR
    FIUIAutomationPatternInstance_GetProperty1 TYPEDEF PTR IUIAutomationPatternInstance_GetProperty1

    IUIAutomationPatternInstance_CallMethod TYPEDEF PROTO :XWORD, index:XWORD, pParams:XPTR, cParams:XWORD 
    FIUIAutomationPatternInstance_CallMethod TYPEDEF PTR IUIAutomationPatternInstance_CallMethod

    STIUIAutomationPatternInstance STRUCT
        QueryInterface  FIUIAutomationPatternInstance_QueryInterface ?
        AddRef          XPTR ?
        Release         XPTR ?
        GetProperty1    FIUIAutomationPatternInstance_GetProperty1 ?
        CallMethod      FIUIAutomationPatternInstance_CallMethod ?
    STIUIAutomationPatternInstance ENDS
 
    IUIAutomationPatternInstance MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STIUIAutomationPatternInstance PTR[PPVREGISTER])., &Function,ppvIUIAutomationPatternInstance
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvIUIAutomationPatternInstance
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_IUIAutomationPatternInstance_INTERFACE_DEFINED_

IFNDEF _IUIAutomationPatternHandler_INTERFACE_DEFINED_
    _IUIAutomationPatternHandler_INTERFACE_DEFINED_ EQU 1

    IUIAutomationPatternHandler_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FIUIAutomationPatternHandler_QueryInterface TYPEDEF PTR IUIAutomationPatternHandler_QueryInterface

    IUIAutomationPatternHandler_CreateClientWrapper TYPEDEF PROTO :XWORD, pPatternInstance:XPTR, pClientWrapper:XPTR
    FIUIAutomationPatternHandler_CreateClientWrapper TYPEDEF PTR IUIAutomationPatternHandler_CreateClientWrapper

    IUIAutomationPatternHandler_Dispatch TYPEDEF PROTO :XWORD, pTarget:XPTR, index:XWORD, pParams:XPTR, cParams:XWORD 
    FIUIAutomationPatternHandler_Dispatch TYPEDEF PTR IUIAutomationPatternHandler_Dispatch

    STIUIAutomationPatternHandler STRUCT
        QueryInterface      FIUIAutomationPatternHandler_QueryInterface ?
        AddRef              XPTR ?
        Release             XPTR ?
        CreateClientWrapper FIUIAutomationPatternHandler_CreateClientWrapper ?
        Dispatch            FIUIAutomationPatternHandler_Dispatch ?
    STIUIAutomationPatternHandler ENDS
 
    IUIAutomationPatternHandler MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STIUIAutomationPatternHandler PTR[PPVREGISTER])., &Function,ppvIUIAutomationPatternHandler
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvIUIAutomationPatternHandler
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_IUIAutomationPatternHandler_INTERFACE_DEFINED_

IFNDEF _IUIAutomationRegistrar_INTERFACE_DEFINED_
    _IUIAutomationRegistrar_INTERFACE_DEFINED_  EQU 1

    IUIAutomationRegistrar_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FIUIAutomationRegistrar_QueryInterface TYPEDEF PTR IUIAutomationRegistrar_QueryInterface

    IUIAutomationRegistrar_RegisterProperty TYPEDEF PROTO :XWORD, property:XWORD, propertyId:XWORD
    FIUIAutomationRegistrar_RegisterProperty TYPEDEF PTR IUIAutomationRegistrar_RegisterProperty

    IUIAutomationRegistrar_RegisterEvent TYPEDEF PROTO :XWORD, event:XWORD, eventId:XWORD
    FIUIAutomationRegistrar_RegisterEvent TYPEDEF PTR IUIAutomationRegistrar_RegisterEvent

    IUIAutomationRegistrar_RegisterPattern TYPEDEF PROTO :XWORD, pattern:XWORD, pPatternId:XPTR, pPatternAvailablePropertyId:XPTR, propertyIdCount:XWORD, pPropertyIds:XPTR, eventIdCount:XWORD, pEventIds:XPTR
    FIUIAutomationRegistrar_RegisterPattern TYPEDEF PTR IUIAutomationRegistrar_RegisterPattern

    STIUIAutomationRegistrar STRUCT
        QueryInterface      FIUIAutomationRegistrar_QueryInterface ?
        AddRef              XPTR ?
        Release             XPTR ?
        RegisterProperty    FIUIAutomationRegistrar_RegisterProperty ?
        RegisterEvent       FIUIAutomationRegistrar_RegisterEvent ?
        RegisterPattern     FIUIAutomationRegistrar_RegisterPattern ?
    STIUIAutomationRegistrar ENDS
 
    IUIAutomationRegistrar MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, args
            IFIDNI &arg, PPVREGISTER
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI &pInterface, PPVREGISTER
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR invoke (STIUIAutomationRegistrar PTR[PPVREGISTER])., &Function,ppvIUIAutomationRegistrar
        IFNB args
            InvokeInterface CATSTR InvokeInterface, , , &args 
        ENDIF 
        mov PPVREGISTER, ppvIUIAutomationRegistrar
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM
ENDIF ;_IUIAutomationRegistrar_INTERFACE_DEFINED_

ENDIF ;_UIA_LIBRARY_DEFINED_

ENDIF ;UIAUTOMATIONCORE_INC
