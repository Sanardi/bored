; =================================================================;
;                                                                  ;
;  UIAutomationCoreApi.inc for Easy Code 2.0 64-bit Masm projects  ;
;                         (version 1.0.0)                          ;
;                                                                  ;
;                  Copyright © Ramon Sala - 2020                   ;
;                                                                  ;
; =================================================================;

IFNDEF UIAUTOMATIONCOREAPI_INC
UIAUTOMATIONCOREAPI_INC EQU 1

UIA_E_ELEMENTNOTENABLED                         EQU     80040200H
UIA_E_ELEMENTNOTAVAILABLE                       EQU     80040201H
UIA_E_NOCLICKABLEPOINT                          EQU     80040202H
UIA_E_PROXYASSEMBLYNOTLOADED                    EQU     80040203H

UIA_E_NOTSUPPORTED                              EQU     80040204H

UIA_E_INVALIDOPERATION                          EQU     80131509H
UIA_E_TIMEOUT                                   EQU     80131505H

UiaAppendRuntimeId                              EQU     3
UiaRootObjectId                                 EQU     (-25)

IFNDEF UIAUTOMATIONCLIENT_INC
    ;TreeScope Enumeration
    TreeScope_None                              EQU     00H
    TreeScope_Element                           EQU     01H
    TreeScope_Children                          EQU     02H
    TreeScope_Descendants                       EQU     04H
    TreeScope_Parent                            EQU     08H
    TreeScope_Ancestors                         EQU     010H
    TreeScope_Subtree                           EQU     (TreeScope_Element OR TreeScope_Children OR TreeScope_Descendants)

    ;AutomationElementMode Enumeration
    AutomationElementMode_None                  EQU     0
    AutomationElementMode_Full                  EQU     1

    ;PropertyConditionFlags Enumeration
    PropertyConditionFlags_None                 EQU     00H
    PropertyConditionFlags_IgnoreCase           EQU     01H

    ;TreeTraversalOptions Enumeration
    TreeTraversalOptions_Default                EQU     00H
    TreeTraversalOptions_PostOrder              EQU     01H
    TreeTraversalOptions_LastToFirstOrder       EQU     02H
ENDIF

;NormalizeState Enumeration
NormalizeState_None                             EQU     0
NormalizeState_View                             EQU     1
NormalizeState_Custom                           EQU     2

;ProviderType Enumeration
ProviderType_BaseHwnd                           EQU     0
ProviderType_Proxy                              EQU     1
ProviderType_NonClientArea                      EQU     2

;AutomationIdentifierType Enumeration
AutomationIdentifierType_Property               EQU     0
AutomationIdentifierType_Pattern                EQU     1
AutomationIdentifierType_Event                  EQU     2
AutomationIdentifierType_ControlType            EQU     3
AutomationIdentifierType_TextAttribute          EQU     4
AutomationIdentifierType_LandmarkType           EQU     5
AutomationIdentifierType_Annotation             EQU     6
AutomationIdentifierType_Changes                EQU     7
AutomationIdentifierType_Style                  EQU     8

;EventArgsType Enumeration
EventArgsType_Simple                            EQU     0
EventArgsType_PropertyChanged                   EQU     1
EventArgsType_StructureChanged                  EQU     2
EventArgsType_AsyncContentLoaded                EQU     3
EventArgsType_WindowClosed                      EQU     4
EventArgsType_TextEditTextChanged               EQU     5
EventArgsType_Changes                           EQU     6
EventArgsType_Notification                      EQU     7

;AsyncContentLoadedState Enumeration            EQU     0
AsyncContentLoadedState_Beginning               EQU     1
AsyncContentLoadedState_Progress                EQU     2
AsyncContentLoadedState_Completed               EQU     3

.Data
RuntimeId_Property_GUID                         GUID    <0A39EEBFAH, 07FBAH, 04C89H, {0B4H, 0D4H, 0B9H, 09EH, 02DH, 0E7H, 0D1H, 060H}>
BoundingRectangle_Property_GUID                 GUID    <07bbfe8b2H, 03bfcH, 048ddH, {0b7H, 029H, 0c7H, 094H, 0b8H, 046H, 0e9H, 0a1H}>
ProcessId_Property_GUID                         GUID    <040499998H, 09c31H, 04245H, {0a4H, 003H, 087H, 032H, 00eH, 059H, 0eaH, 0f6H}>
ControlType_Property_GUID                       GUID    <0ca774feaH, 028acH, 04bc2H, {094H, 0caH, 0acH, 0ecH, 06dH, 06cH, 010H, 0a3H}>
LocalizedControlType_Property_GUID              GUID    <08763404fH, 0a1bdH, 0452aH, {089H, 0c4H, 03fH, 001H, 0d3H, 083H, 038H, 006H}>
Name_Property_GUID                              GUID    <0c3a6921bH, 04a99H, 044f1H, {0bcH, 0a6H, 061H, 018H, 070H, 052H, 0c4H, 031H}>
AcceleratorKey_Property_GUID                    GUID    <0514865dfH, 02557H, 04cb9H, {0aeH, 0edH, 06cH, 0edH, 008H, 04cH, 0e5H, 02cH}>
AccessKey_Property_GUID                         GUID    <006827b12H, 0a7f9H, 04a15H, {091H, 07cH, 0ffH, 0a5H, 0adH, 03eH, 0b0H, 0a7H}>
HasKeyboardFocus_Property_GUID                  GUID    <0cf8afd39H, 03f46H, 04800H, {096H, 056H, 0b2H, 0bfH, 012H, 052H, 099H, 005H}>
IsKeyboardFocusable_Property_GUID               GUID    <0f7b8552aH, 00859H, 04b37H, {0b9H, 0cbH, 051H, 0e7H, 020H, 092H, 0f2H, 09fH}>
IsEnabled_Property_GUID                         GUID    <02109427fH, 0da60H, 04fedH, {0bfH, 01bH, 026H, 04bH, 0dcH, 0e6H, 0ebH, 03aH}>
AutomationId_Property_GUID                      GUID    <0c82c0500H, 0b60eH, 04310H, {0a2H, 067H, 030H, 03cH, 053H, 01fH, 08eH, 0e5H}>
ClassName_Property_GUID                         GUID    <0157b7215H, 0894fH, 04b65H, {084H, 0e2H, 0aaH, 0c0H, 0daH, 008H, 0b1H, 06bH}>
HelpText_Property_GUID                          GUID    <008555685H, 00977H, 045c7H, {0a7H, 0a6H, 0abH, 0afH, 056H, 084H, 012H, 01aH}>
ClickablePoint_Property_GUID                    GUID    <00196903bH, 0b203H, 04818H, {0a9H, 0f3H, 0f0H, 08eH, 067H, 05fH, 023H, 041H}>
Culture_Property_GUID                           GUID    <0e2d74f27H, 03d79H, 04dc2H, {0b8H, 08bH, 030H, 044H, 096H, 03aH, 08aH, 0fbH}>
IsControlElement_Property_GUID                  GUID    <095f35085H, 0abccH, 04afdH, {0a5H, 0f4H, 0dbH, 0b4H, 06cH, 023H, 00fH, 0dbH}>
IsContentElement_Property_GUID                  GUID    <04bda64a8H, 0f5d8H, 0480bH, {081H, 055H, 0efH, 02eH, 089H, 0adH, 0b6H, 072H}>
LabeledBy_Property_GUID                         GUID    <0e5b8924bH, 0fc8aH, 04a35H, {080H, 031H, 0cfH, 078H, 0acH, 043H, 0e5H, 05eH}>
IsPassword_Property_GUID                        GUID    <0e8482eb1H, 0687cH, 0497bH, {0beH, 0bcH, 003H, 0beH, 053H, 0ecH, 014H, 054H}>
NewNativeWindowHandle_Property_GUID             GUID    <05196b33bH, 0380aH, 04982H, {095H, 0e1H, 091H, 0f3H, 0efH, 060H, 0e0H, 024H}>
ItemType_Property_GUID                          GUID    <0cdda434dH, 06222H, 0413bH, {0a6H, 08aH, 032H, 05dH, 0d1H, 0d4H, 00fH, 039H}>
IsOffscreen_Property_GUID                       GUID    <003c3d160H, 0db79H, 042dbH, {0a2H, 0efH, 01cH, 023H, 01eH, 0edH, 0e5H, 007H}>
Orientation_Property_GUID                       GUID    <0a01eee62H, 03884H, 04415H, {088H, 07eH, 067H, 08eH, 0c2H, 01eH, 039H, 0baH}>
FrameworkId_Property_GUID                       GUID    <0dbfd9900H, 07e1aH, 04f58H, {0b6H, 01bH, 070H, 063H, 012H, 00fH, 077H, 03bH}>
IsRequiredForForm_Property_GUID                 GUID    <04f5f43cfH, 059fbH, 04bdeH, {0a2H, 070H, 060H, 02eH, 05eH, 011H, 041H, 0e9H}>
ItemStatus_Property_GUID                        GUID    <051de0321H, 03973H, 043e7H, {089H, 013H, 00bH, 008H, 0e8H, 013H, 0c3H, 07fH}>
AriaRole_Property_GUID                          GUID    <0dd207b95H, 0be4aH, 04e0dH, {0b7H, 027H, 063H, 0acH, 0e9H, 04bH, 069H, 016H}>
AriaProperties_Property_GUID                    GUID    <04213678cH, 0e025H, 04922H, {0beH, 0b5H, 0e4H, 03bH, 0a0H, 08eH, 062H, 021H}>
IsDataValidForForm_Property_GUID                GUID    <0445ac684H, 0c3fcH, 04dd9H, {0acH, 0f8H, 084H, 05aH, 057H, 092H, 096H, 0baH}>
ControllerFor_Property_GUID                     GUID    <051124c8aH, 0a5d2H, 04f13H, {09bH, 0e6H, 07fH, 0a8H, 0baH, 09dH, 03aH, 090H}>
DescribedBy_Property_GUID                       GUID    <07c5865b8H, 09992H, 040fdH, {08dH, 0b0H, 06bH, 0f1H, 0d3H, 017H, 0f9H, 098H}>
FlowsTo_Property_GUID                           GUID    <0e4f33d20H, 0559aH, 047fbH, {0a8H, 030H, 0f9H, 0cbH, 04fH, 0f1H, 0a7H, 00aH}>
ProviderDescription_Property_GUID               GUID    <0dca5708aH, 0c16bH, 04cd9H, {0b8H, 089H, 0beH, 0b1H, 06aH, 080H, 049H, 004H}>
OptimizeForVisualContent_Property_GUID          GUID    <06a852250H, 0c75aH, 04e5dH, {0b8H, 058H, 0e3H, 081H, 0b0H, 0f7H, 088H, 061H}>
IsDockPatternAvailable_Property_GUID            GUID    <02600a4c4H, 02ff8H, 04c96H, {0aeH, 031H, 08fH, 0e6H, 019H, 0a1H, 03cH, 06cH}>
IsExpandCollapsePatternAvailable_Property_GUID  GUID    <0929d3806H, 05287H, 04725H, {0aaH, 016H, 022H, 02aH, 0fcH, 063H, 0d5H, 095H}>
IsGridItemPatternAvailable_Property_GUID        GUID    <05a43e524H, 0f9a2H, 04b12H, {084H, 0c8H, 0b4H, 08aH, 03eH, 0feH, 0ddH, 034H}>
IsGridPatternAvailable_Property_GUID            GUID    <05622c26cH, 0f0efH, 04f3bH, {097H, 0cbH, 071H, 04cH, 008H, 068H, 058H, 08bH}>
IsInvokePatternAvailable_Property_GUID          GUID    <04e725738H, 08364H, 04679H, {0aaH, 06cH, 0f3H, 0f4H, 019H, 031H, 0f7H, 050H}>
IsMultipleViewPatternAvailable_Property_GUID    GUID    <0ff0a31ebH, 08e25H, 0469dH, {08dH, 06eH, 0e7H, 071H, 0a2H, 07cH, 01bH, 090H}>
IsRangeValuePatternAvailable_Property_GUID      GUID    <0fda4244aH, 0eb4dH, 043ffH, {0b5H, 0adH, 0edH, 036H, 0d3H, 073H, 0ecH, 04cH}>
IsScrollPatternAvailable_Property_GUID          GUID    <03ebb7b4aH, 0828aH, 04b57H, {09dH, 022H, 02fH, 0eaH, 016H, 032H, 0edH, 00dH}>
IsScrollItemPatternAvailable_Property_GUID      GUID    <01cad1a05H, 00927H, 04b76H, {097H, 0e1H, 00fH, 0cdH, 0b2H, 009H, 0b9H, 08aH}>
IsSelectionItemPatternAvailable_Property_GUID   GUID    <08becd62dH, 00bc3H, 04109H, {0beH, 0e2H, 08eH, 067H, 015H, 029H, 00eH, 068H}>
IsSelectionPatternAvailable_Property_GUID       GUID    <0f588acbeH, 0c769H, 04838H, {09aH, 060H, 026H, 086H, 0dcH, 011H, 088H, 0c4H}>
IsTablePatternAvailable_Property_GUID           GUID    <0cb83575fH, 045c2H, 04048H, {09cH, 076H, 015H, 097H, 015H, 0a1H, 039H, 0dfH}>
IsTableItemPatternAvailable_Property_GUID       GUID    <0eb36b40dH, 08ea4H, 0489bH, {0a0H, 013H, 0e6H, 00dH, 059H, 051H, 0feH, 034H}>
IsTextPatternAvailable_Property_GUID            GUID    <0fbe2d69dH, 0aff6H, 04a45H, {082H, 0e2H, 0fcH, 092H, 0a8H, 02fH, 059H, 017H}>
IsTogglePatternAvailable_Property_GUID          GUID    <078686d53H, 0fcd0H, 04b83H, {09bH, 078H, 058H, 032H, 0ceH, 063H, 0bbH, 05bH}>
IsTransformPatternAvailable_Property_GUID       GUID    <0a7f78804H, 0d68bH, 04077H, {0a5H, 0c6H, 07aH, 05eH, 0a1H, 0acH, 031H, 0c5H}>
IsValuePatternAvailable_Property_GUID           GUID    <00b5020a7H, 02119H, 0473bH, {0beH, 037H, 05cH, 0ebH, 098H, 0bbH, 0fbH, 022H}>
IsWindowPatternAvailable_Property_GUID          GUID    <0e7a57bb1H, 05888H, 04155H, {098H, 0dcH, 0b4H, 022H, 0fdH, 057H, 0f2H, 0bcH}>
IsLegacyIAccessiblePatternAvailable_Property_GUID GUID  <0d8ebd0c7H, 0929aH, 04ee7H, {08dH, 03aH, 0d3H, 0d9H, 044H, 013H, 002H, 07bH}>
IsItemContainerPatternAvailable_Property_GUID   GUID    <0624b5ca7H, 0fe40H, 04957H, {0a0H, 019H, 020H, 0c4H, 0cfH, 011H, 092H, 00fH}>
IsVirtualizedItemPatternAvailable_Property_GUID GUID    <0302cb151H, 02ac8H, 045d6H, {097H, 07bH, 0d2H, 0b3H, 0a5H, 0a5H, 03fH, 020H}>
IsSynchronizedInputPatternAvailable_Property_GUID GUID  <075d69cc5H, 0d2bfH, 04943H, {087H, 06eH, 0b4H, 05bH, 062H, 0a6H, 0ccH, 066H}>
IsObjectModelPatternAvailable_Property_GUID     GUID    <06b21d89bH, 02841H, 0412fH, {08eH, 0f2H, 015H, 0caH, 095H, 023H, 018H, 0baH}>
IsAnnotationPatternAvailable_Property_GUID      GUID    <00b5b3238H, 06d5cH, 041b6H, {0bcH, 0c4H, 05eH, 080H, 07fH, 065H, 051H, 0c4H}>
IsTextPattern2Available_Property_GUID           GUID    <041cf921dH, 0e3f1H, 04b22H, {09cH, 081H, 0e1H, 0c3H, 0edH, 033H, 01cH, 022H}>
IsTextEditPatternAvailable_Property_GUID        GUID    <07843425cH, 08b32H, 0484cH, {09aH, 0b5H, 0e3H, 020H, 005H, 071H, 0ffH, 0daH}>
IsCustomNavigationPatternAvailable_Property_GUID GUID   <08f8e80d4H, 02351H, 048e0H, {087H, 04aH, 054H, 0aaH, 073H, 013H, 088H, 09aH}>
IsStylesPatternAvailable_Property_GUID          GUID    <027f353d3H, 0459cH, 04b59H, {0a4H, 090H, 050H, 061H, 01dH, 0acH, 0afH, 0b5H}>
IsSpreadsheetPatternAvailable_Property_GUID     GUID    <06ff43732H, 0e4b4H, 04555H, {097H, 0bcH, 0ecH, 0dbH, 0bcH, 04dH, 018H, 088H}>
IsSpreadsheetItemPatternAvailable_Property_GUID GUID    <09fe79b2aH, 02f94H, 043fdH, {099H, 06bH, 054H, 09eH, 031H, 06fH, 04aH, 0cdH}>
IsTransformPattern2Available_Property_GUID      GUID    <025980b4bH, 0be04H, 04710H, {0abH, 04aH, 0fdH, 0a3H, 01dH, 0bdH, 028H, 095H}>
IsTextChildPatternAvailable_Property_GUID       GUID    <0559e65dfH, 030ffH, 043b5H, {0b5H, 0edH, 05bH, 028H, 03bH, 080H, 0c7H, 0e9H}>
IsDragPatternAvailable_Property_GUID            GUID    <0e997a7b7H, 01d39H, 04ca7H, {0beH, 00fH, 027H, 07fH, 0cfH, 056H, 005H, 0ccH}>
IsDropTargetPatternAvailable_Property_GUID      GUID    <00686b62eH, 08e19H, 04aafH, {087H, 03dH, 038H, 04fH, 06dH, 03bH, 092H, 0beH}>
IsPeripheral_Property_GUID                      GUID    <0da758276H, 07ed5H, 049d4H, {08eH, 068H, 0ecH, 0c9H, 0a2H, 0d3H, 000H, 0ddH}>
PositionInSet_Property_GUID                     GUID    <033d1dc54H, 0641eH, 04d76H, {0a6H, 0b1H, 013H, 0f3H, 041H, 0c1H, 0f8H, 096H}>
SizeOfSet_Property_GUID                         GUID    <01600d33cH, 03b9fH, 04369H, {094H, 031H, 0aaH, 029H, 03fH, 034H, 04cH, 0f1H}>
Level_Property_GUID                             GUID    <0242ac529H, 0cd36H, 0400fH, {0aaH, 0d9H, 078H, 076H, 0efH, 03aH, 0f6H, 027H}>
AnnotationTypes_Property_GUID                   GUID    <064b71f76H, 053c4H, 04696H, {0a2H, 019H, 020H, 0e9H, 040H, 0c9H, 0a1H, 076H}>
AnnotationObjects_Property_GUID                 GUID    <0310910c8H, 07c6eH, 04f20H, {0beH, 0cdH, 04aH, 0afH, 06dH, 019H, 011H, 056H}>
LandmarkType_Property_GUID                      GUID    <0454045f2H, 06f61H, 049f7H, {0a4H, 0f8H, 0b5H, 0f0H, 0cfH, 082H, 0daH, 01eH}>
LocalizedLandmarkType_Property_GUID             GUID    <07ac81980H, 0eafbH, 04fb2H, {0bfH, 091H, 0f4H, 085H, 0beH, 0f5H, 0e8H, 0e1H}>
FullDescription_Property_GUID                   GUID    <00d4450ffH, 06aefH, 04f33H, {095H, 0ddH, 07bH, 0efH, 0a7H, 02aH, 043H, 091H}>
Value_Value_Property_GUID                       GUID    <0e95f5e64H, 0269fH, 04a85H, {0baH, 099H, 040H, 092H, 0c3H, 0eaH, 029H, 086H}>
Value_IsReadOnly_Property_GUID                  GUID    <0eb090f30H, 0e24cH, 04799H, {0a7H, 005H, 00dH, 024H, 07bH, 0c0H, 037H, 0f8H}>
RangeValue_Value_Property_GUID                  GUID    <0131f5d98H, 0c50cH, 0489dH, {0abH, 0e5H, 0aeH, 022H, 008H, 098H, 0c5H, 0f7H}>
RangeValue_IsReadOnly_Property_GUID             GUID    <025fa1055H, 0debfH, 04373H, {0a7H, 09eH, 01fH, 01aH, 019H, 008H, 0d3H, 0c4H}>
RangeValue_Minimum_Property_GUID                GUID    <078cbd3b2H, 0684dH, 04860H, {0afH, 093H, 0d1H, 0f9H, 05cH, 0b0H, 022H, 0fdH}>
RangeValue_Maximum_Property_GUID                GUID    <019319914H, 0f979H, 04b35H, {0a1H, 0a6H, 0d3H, 07eH, 005H, 043H, 034H, 073H}>
RangeValue_LargeChange_Property_GUID            GUID    <0a1f96325H, 03a3dH, 04b44H, {08eH, 01fH, 04aH, 046H, 0d9H, 084H, 040H, 019H}>
RangeValue_SmallChange_Property_GUID            GUID    <081c2c457H, 03941H, 04107H, {099H, 075H, 013H, 097H, 060H, 0f7H, 0c0H, 072H}>
Scroll_HorizontalScrollPercent_Property_GUID    GUID    <0c7c13c0eH, 0eb21H, 047ffH, {0acH, 0c4H, 0b5H, 0a3H, 035H, 00fH, 051H, 091H}>
Scroll_HorizontalViewSize_Property_GUID         GUID    <070c2e5d4H, 0fcb0H, 04713H, {0a9H, 0aaH, 0afH, 092H, 0ffH, 079H, 0e4H, 0cdH}>
Scroll_VerticalScrollPercent_Property_GUID      GUID    <06c8d7099H, 0b2a8H, 04948H, {0bfH, 0f7H, 03cH, 0f9H, 005H, 08bH, 0feH, 0fbH}>
Scroll_VerticalViewSize_Property_GUID           GUID    <0de6a2e22H, 0d8c7H, 040c5H, {083H, 0baH, 0e5H, 0f6H, 081H, 0d5H, 031H, 008H}>
Scroll_HorizontallyScrollable_Property_GUID     GUID    <08b925147H, 028cdH, 049aeH, {0bdH, 063H, 0f4H, 041H, 018H, 0d2H, 0e7H, 019H}>
Scroll_VerticallyScrollable_Property_GUID       GUID    <089164798H, 00068H, 04315H, {0b8H, 09aH, 01eH, 07cH, 0fbH, 0bcH, 03dH, 0fcH}>
Selection_Selection_Property_GUID               GUID    <0aa6dc2a2H, 00e2bH, 04d38H, {096H, 0d5H, 034H, 0e4H, 070H, 0b8H, 018H, 053H}>
Selection_CanSelectMultiple_Property_GUID       GUID    <049d73da5H, 0c883H, 04500H, {088H, 03dH, 08fH, 0cfH, 08dH, 0afH, 06cH, 0beH}>
Selection_IsSelectionRequired_Property_GUID     GUID    <0b1ae4422H, 063feH, 044e7H, {0a5H, 0a5H, 0a7H, 038H, 0c8H, 029H, 0b1H, 09aH}>
Grid_RowCount_Property_GUID                     GUID    <02a9505bfH, 0c2ebH, 04fb6H, {0b3H, 056H, 082H, 045H, 0aeH, 053H, 070H, 03eH}>
Grid_ColumnCount_Property_GUID                  GUID    <0fe96f375H, 044aaH, 04536H, {0acH, 07aH, 02aH, 075H, 0d7H, 01aH, 03eH, 0fcH}>
GridItem_Row_Property_GUID                      GUID    <06223972aH, 0c945H, 04563H, {093H, 029H, 0fdH, 0c9H, 074H, 0afH, 025H, 053H}>
GridItem_Column_Property_GUID                   GUID    <0c774c15cH, 062c0H, 04519H, {08bH, 0dcH, 047H, 0beH, 057H, 03cH, 08aH, 0d5H}>
GridItem_RowSpan_Property_GUID                  GUID    <04582291cH, 0466bH, 04e93H, {08eH, 083H, 03dH, 017H, 015H, 0ecH, 00cH, 05eH}>
GridItem_ColumnSpan_Property_GUID               GUID    <0583ea3f5H, 086d0H, 04b08H, {0a6H, 0ecH, 02cH, 054H, 063H, 0ffH, 0c1H, 009H}>
GridItem_Parent_Property_GUID                   GUID    <09d912252H, 0b97fH, 04eccH, {085H, 010H, 0eaH, 00eH, 033H, 042H, 07cH, 072H}>
Dock_DockPosition_Property_GUID                 GUID    <06d67f02eH, 0c0b0H, 04b10H, {0b5H, 0b9H, 018H, 0d6H, 0ecH, 0f9H, 087H, 060H}>
ExpandCollapse_ExpandCollapseState_Property_GUID GUID   <0275a4c48H, 085a7H, 04f69H, {0abH, 0a0H, 0afH, 015H, 076H, 010H, 000H, 02bH}>
MultipleView_CurrentView_Property_GUID          GUID    <07a81a67aH, 0b94fH, 04875H, {091H, 08bH, 065H, 0c8H, 0d2H, 0f9H, 098H, 0e5H}>
MultipleView_SupportedViews_Property_GUID       GUID    <08d5db9fdH, 0ce3cH, 04ae7H, {0b7H, 088H, 040H, 00aH, 03cH, 064H, 055H, 047H}>
Window_CanMaximize_Property_GUID                GUID    <064fff53fH, 0635dH, 041c1H, {095H, 00cH, 0cbH, 05aH, 0dfH, 0beH, 028H, 0e3H}>
Window_CanMinimize_Property_GUID                GUID    <0b73b4625H, 05988H, 04b97H, {0b4H, 0c2H, 0a6H, 0feH, 06eH, 078H, 0c8H, 0c6H}>
Window_WindowVisualState_Property_GUID          GUID    <04ab7905fH, 0e860H, 0453eH, {0a3H, 00aH, 0f6H, 043H, 01eH, 05dH, 0aaH, 0d5H}>
Window_WindowInteractionState_Property_GUID     GUID    <04fed26a4H, 00455H, 04fa2H, {0b2H, 01cH, 0c4H, 0daH, 02dH, 0b1H, 0ffH, 09cH}>
Window_IsModal_Property_GUID                    GUID    <0ff4e6892H, 037b9H, 04fcaH, {085H, 032H, 0ffH, 0e6H, 074H, 0ecH, 0feH, 0edH}>
Window_IsTopmost_Property_GUID                  GUID    <0ef7d85d3H, 00937H, 04962H, {092H, 041H, 0b6H, 023H, 045H, 0f2H, 040H, 041H}>
SelectionItem_IsSelected_Property_GUID          GUID    <0f122835fH, 0cd5fH, 043dfH, {0b7H, 09dH, 04bH, 084H, 09eH, 09eH, 060H, 020H}>
SelectionItem_SelectionContainer_Property_GUID  GUID    <0a4365b6eH, 09c1eH, 04b63H, {08bH, 053H, 0c2H, 042H, 01dH, 0d1H, 0e8H, 0fbH}>
Table_RowHeaders_Property_GUID                  GUID    <0d9e35b87H, 06eb8H, 04562H, {0aaH, 0c6H, 0a8H, 0a9H, 007H, 052H, 036H, 0a8H}>
Table_ColumnHeaders_Property_GUID               GUID    <0aff1d72bH, 0968dH, 042b1H, {0b4H, 059H, 015H, 00bH, 029H, 09dH, 0a6H, 064H}>
Table_RowOrColumnMajor_Property_GUID            GUID    <083be75c3H, 029feH, 04a30H, {085H, 0e1H, 02aH, 062H, 077H, 0fdH, 010H, 06eH}>
TableItem_RowHeaderItems_Property_GUID          GUID    <0b3f853a0H, 00574H, 04cd8H, {0bcH, 0d7H, 0edH, 059H, 023H, 057H, 02dH, 097H}>
TableItem_ColumnHeaderItems_Property_GUID       GUID    <0967a56a3H, 074b6H, 0431eH, {08dH, 0e6H, 099H, 0c4H, 011H, 003H, 01cH, 058H}>
Toggle_ToggleState_Property_GUID                GUID    <0b23cdc52H, 022c2H, 04c6cH, {09dH, 0edH, 0f5H, 0c4H, 022H, 047H, 09eH, 0deH}>
Transform_CanMove_Property_GUID                 GUID    <01b75824dH, 0208bH, 04fdfH, {0bcH, 0cdH, 0f1H, 0f4H, 0e5H, 074H, 01fH, 04fH}>
Transform_CanResize_Property_GUID               GUID    <0bb98dca5H, 04c1aH, 041d4H, {0a4H, 0f6H, 0ebH, 0c1H, 028H, 064H, 041H, 080H}>
Transform_CanRotate_Property_GUID               GUID    <010079b48H, 03849H, 0476fH, {0acH, 096H, 044H, 0a9H, 05cH, 084H, 040H, 0d9H}>
LegacyIAccessible_ChildId_Property_GUID         GUID    <09a191b5dH, 09ef2H, 04787H, {0a4H, 059H, 0dcH, 0deH, 088H, 05dH, 0d4H, 0e8H}>
LegacyIAccessible_Name_Property_GUID            GUID    <0caeb063dH, 040aeH, 04869H, {0aaH, 05aH, 01bH, 08eH, 05dH, 066H, 067H, 039H}>
LegacyIAccessible_Value_Property_GUID           GUID    <0b5c5b0b6H, 08217H, 04a77H, {097H, 0a5H, 019H, 00aH, 085H, 0edH, 001H, 056H}>
LegacyIAccessible_Description_Property_GUID     GUID    <046448418H, 07d70H, 04ea9H, {09dH, 027H, 0b7H, 0e7H, 075H, 0cfH, 02aH, 0d7H}>
LegacyIAccessible_Role_Property_GUID            GUID    <06856e59fH, 0cbafH, 04e31H, {093H, 0e8H, 0bcH, 0bfH, 06fH, 07eH, 049H, 01cH}>
LegacyIAccessible_State_Property_GUID           GUID    <0df985854H, 02281H, 04340H, {0abH, 09cH, 0c6H, 00eH, 02cH, 058H, 003H, 0f6H}>
LegacyIAccessible_Help_Property_GUID            GUID    <094402352H, 0161cH, 04b77H, {0a9H, 08dH, 0a8H, 072H, 0ccH, 033H, 094H, 07aH}>
LegacyIAccessible_KeyboardShortcut_Property_GUID GUID   <08f6909acH, 000b8H, 04259H, {0a4H, 01cH, 096H, 062H, 066H, 0d4H, 03aH, 08aH}>
LegacyIAccessible_Selection_Property_GUID       GUID    <08aa8b1e0H, 00891H, 040ccH, {08bH, 006H, 090H, 0d7H, 0d4H, 016H, 062H, 019H}>
LegacyIAccessible_DefaultAction_Property_GUID   GUID    <03b331729H, 0eaadH, 04502H, {0b8H, 05fH, 092H, 061H, 056H, 022H, 091H, 03cH}>
Annotation_AnnotationTypeId_Property_GUID       GUID    <020ae484fH, 069efH, 04c48H, {08fH, 05bH, 0c4H, 093H, 08bH, 020H, 06aH, 0c7H}>
Annotation_AnnotationTypeName_Property_GUID     GUID    <09b818892H, 05ac9H, 04af9H, {0aaH, 096H, 0f5H, 08aH, 077H, 0b0H, 058H, 0e3H}>
Annotation_Author_Property_GUID                 GUID    <07a528462H, 09c5cH, 04a03H, {0a9H, 074H, 08bH, 030H, 07aH, 099H, 037H, 0f2H}>
Annotation_DateTime_Property_GUID               GUID    <099b5ca5dH, 01acfH, 0414bH, {0a4H, 0d0H, 06bH, 035H, 00bH, 004H, 075H, 078H}>
Annotation_Target_Property_GUID                 GUID    <0b71b302dH, 02104H, 044adH, {09cH, 05cH, 009H, 02bH, 049H, 007H, 0d7H, 00fH}>
Styles_StyleId_Property_GUID                    GUID    <0da82852fH, 03817H, 04233H, {082H, 0afH, 002H, 027H, 09eH, 072H, 0ccH, 077H}>
Styles_StyleName_Property_GUID                  GUID    <01c12b035H, 005d1H, 04f55H, {09eH, 08eH, 014H, 089H, 0f3H, 0ffH, 055H, 00dH}>
Styles_FillColor_Property_GUID                  GUID    <063eff97aH, 0a1c5H, 04b1dH, {084H, 0ebH, 0b7H, 065H, 0f2H, 0edH, 0d6H, 032H}>
Styles_FillPatternStyle_Property_GUID           GUID    <081cf651fH, 0482bH, 04451H, {0a3H, 00aH, 0e1H, 054H, 05eH, 055H, 04fH, 0b8H}>
Styles_Shape_Property_GUID                      GUID    <0c71a23f8H, 0778cH, 0400dH, {084H, 058H, 03bH, 054H, 03eH, 052H, 069H, 084H}>
Styles_FillPatternColor_Property_GUID           GUID    <0939a59feH, 08fbdH, 04e75H, {0a2H, 071H, 0acH, 045H, 095H, 019H, 051H, 063H}>
Styles_ExtendedProperties_Property_GUID         GUID    <0f451cda0H, 0ba0aH, 04681H, {0b0H, 0b0H, 00dH, 0bdH, 0b5H, 03eH, 058H, 0f3H}>
SpreadsheetItem_Formula_Property_GUID           GUID    <0e602e47dH, 01b47H, 04beaH, {087H, 0cfH, 03bH, 00bH, 00bH, 05cH, 015H, 0b6H}>
SpreadsheetItem_AnnotationObjects_Property_GUID GUID    <0a3194c38H, 0c9bcH, 04604H, {093H, 096H, 0aeH, 03fH, 09fH, 045H, 07fH, 07bH}>
SpreadsheetItem_AnnotationTypes_Property_GUID   GUID    <0c70c51d0H, 0d602H, 04b45H, {0afH, 0bcH, 0b4H, 071H, 02bH, 096H, 0d7H, 02bH}>
Transform2_CanZoom_Property_GUID                GUID    <0f357e890H, 0a756H, 04359H, {09cH, 0a6H, 086H, 070H, 02bH, 0f8H, 0f3H, 081H}>
LiveSetting_Property_GUID                       GUID    <0c12bcd8eH, 02a8eH, 04950H, {08aH, 0e7H, 036H, 025H, 011H, 01dH, 058H, 0ebH}>
Drag_IsGrabbed_Property_GUID                    GUID    <045f206f3H, 075ccH, 04ccaH, {0a9H, 0b9H, 0fcH, 0dfH, 0b9H, 082H, 0d8H, 0a2H}>
Drag_GrabbedItems_Property_GUID                 GUID    <077c1562cH, 07b86H, 04b21H, {09eH, 0d7H, 03cH, 0efH, 0daH, 06fH, 04cH, 043H}>
Drag_DropEffect_Property_GUID                   GUID    <0646f2779H, 048d3H, 04b23H, {089H, 002H, 04bH, 0f1H, 000H, 000H, 05dH, 0f3H}>
Drag_DropEffects_Property_GUID                  GUID    <0f5d61156H, 07ce6H, 049beH, {0a8H, 036H, 092H, 069H, 0dcH, 0ecH, 092H, 00fH}>
DropTarget_DropTargetEffect_Property_GUID       GUID    <08bb75975H, 0a0caH, 04981H, {0b8H, 018H, 087H, 0fcH, 066H, 0e9H, 050H, 09dH}>
DropTarget_DropTargetEffects_Property_GUID      GUID    <0bc1dd4edH, 0cb89H, 045f1H, {0a5H, 092H, 0e0H, 03bH, 008H, 0aeH, 079H, 00fH}>
Transform2_ZoomLevel_Property_GUID              GUID    <0eee29f1aH, 0f4a2H, 04b5bH, {0acH, 065H, 095H, 0cfH, 093H, 028H, 033H, 087H}>
Transform2_ZoomMinimum_Property_GUID            GUID    <0742ccc16H, 04ad1H, 04e07H, {096H, 0feH, 0b1H, 022H, 0c6H, 0e6H, 0b2H, 02bH}>
Transform2_ZoomMaximum_Property_GUID            GUID    <042ab6b77H, 0ceb0H, 04ecaH, {0b8H, 02aH, 06cH, 0faH, 05fH, 0a1H, 0fcH, 008H}>
FlowsFrom_Property_GUID                         GUID    <05c6844fH,  019deH, 048f8H, {095H, 0faH, 088H, 0dH,  05bH, 0fH,  0d6H, 015H}>
FillColor_Property_GUID                         GUID    <06e0ec4d0H, 0e2a8H, 04a56H, {09dH, 0e7H, 095H, 033H, 089H, 093H, 03bH, 039H}>
OutlineColor_Property_GUID                      GUID    <0c395d6c0H, 04b55H, 04762H, {0a0H, 073H, 0fdH, 030H, 03aH, 063H, 04fH, 052H}>
FillType_Property_GUID                          GUID    <0c6fc74e4H, 08cb9H, 0429cH, {0a9H, 0e1H, 09bH, 0c4H, 0acH, 037H, 02bH, 062H}>
VisualEffects_Property_GUID                     GUID    <0e61a8565H, 0aad9H, 046d7H, {09eH, 070H, 04eH, 08aH, 084H, 020H, 0d4H, 020H}>
OutlineThickness_Property_GUID                  GUID    <013e67cc7H, 0dac2H, 04888H, {0bdH, 0d3H, 037H, 05cH, 062H, 0faH, 096H, 018H}>
CenterPoint_Property_GUID                       GUID    <0cb00c08H,  0540cH, 04edbH, {094H, 045H, 026H, 035H, 09eH, 0a6H, 097H, 085H}>
Rotation_Property_GUID                          GUID    <0767cdc7dH, 0aec0H, 04110H, {0adH, 032H, 030H, 0edH, 0d4H, 003H, 049H, 02eH}>
Size_Property_GUID                              GUID    <02b5f761dH, 0f885H, 04404H, {097H, 03fH, 09bH, 01dH, 098H, 0e3H, 06dH, 08fH}>
ToolTipOpened_Event_GUID                        GUID    <03f4b97ffH, 02edcH, 0451dH, {0bcH, 0a4H, 095H, 0a3H, 018H, 08dH, 05bH, 003H}>
ToolTipClosed_Event_GUID                        GUID    <0276d71efH, 024a9H, 049b6H, {08eH, 097H, 0daH, 098H, 0b4H, 001H, 0bbH, 0cdH}>
StructureChanged_Event_GUID                     GUID    <059977961H, 03eddH, 04b11H, {0b1H, 03bH, 067H, 06bH, 02aH, 02aH, 06cH, 0a9H}>
MenuOpened_Event_GUID                           GUID    <0ebe2e945H, 066caH, 04ed1H, {09fH, 0f8H, 02aH, 0d7H, 0dfH, 00aH, 01bH, 008H}>
AutomationPropertyChanged_Event_GUID            GUID    <02527fba1H, 08d7aH, 04630H, {0a4H, 0ccH, 0e6H, 063H, 015H, 094H, 02fH, 052H}>
AutomationFocusChanged_Event_GUID               GUID    <0b68a1f17H, 0f60dH, 041a7H, {0a3H, 0ccH, 0b0H, 052H, 092H, 015H, 05fH, 0e0H}>
AsyncContentLoaded_Event_GUID                   GUID    <05fdee11cH, 0d2faH, 04fb9H, {090H, 04eH, 05cH, 0beH, 0e8H, 094H, 0d5H, 0efH}>
MenuClosed_Event_GUID                           GUID    <03cf1266eH, 01582H, 04041H, {0acH, 0d7H, 088H, 0a3H, 05aH, 096H, 052H, 097H}>
LayoutInvalidated_Event_GUID                    GUID    <0ed7d6544H, 0a6bdH, 04595H, {09bH, 0aeH, 03dH, 028H, 094H, 06cH, 0c7H, 015H}>
Invoke_Invoked_Event_GUID                       GUID    <0dfd699f0H, 0c915H, 049ddH, {0b4H, 022H, 0ddH, 0e7H, 085H, 0c3H, 0d2H, 04bH}>
SelectionItem_ElementAddedToSelectionEvent_Event_GUID GUID  <03c822dd1H, 0c407H, 04dbaH, {091H, 0ddH, 079H, 0d4H, 0aeH, 0d0H, 0aeH, 0c6H}>
SelectionItem_ElementRemovedFromSelectionEvent_Event_GUID GUID  <0097FA8A9H, 07079H, 041AFH, {08BH, 09CH, 009H, 034H, 0D8H, 030H, 05EH, 05CH}>
SelectionItem_ElementSelectedEvent_Event_GUID   GUID    <0b9c7dbfbH, 04ebeH, 04532H, {0aaH, 0f4H, 000H, 08cH, 0f6H, 047H, 023H, 03cH}>
Selection_InvalidatedEvent_Event_GUID           GUID    <0cac14904H, 016b4H, 04b53H, {08eH, 047H, 04cH, 0b1H, 0dfH, 026H, 07bH, 0b7H}>
Text_TextSelectionChangedEvent_Event_GUID       GUID    <0918edaa1H, 071b3H, 049aeH, {097H, 041H, 079H, 0beH, 0b8H, 0d3H, 058H, 0f3H}>
Text_TextChangedEvent_Event_GUID                GUID    <04a342082H, 0f483H, 048c4H, {0acH, 011H, 0a8H, 04bH, 043H, 05eH, 02aH, 084H}>
Window_WindowOpened_Event_GUID                  GUID    <0d3e81d06H, 0de45H, 04f2fH, {096H, 033H, 0deH, 09eH, 002H, 0fbH, 065H, 0afH}>
Window_WindowClosed_Event_GUID                  GUID    <0edf141f8H, 0fa67H, 04e22H, {0bbH, 0f7H, 094H, 04eH, 005H, 073H, 05eH, 0e2H}>
MenuModeStart_Event_GUID                        GUID    <018d7c631H, 0166aH, 04ac9H, {0aeH, 03bH, 0efH, 04bH, 054H, 020H, 0e6H, 081H}>
MenuModeEnd_Event_GUID                          GUID    <09ecd4c9fH, 080ddH, 047b8H, {082H, 067H, 05aH, 0ecH, 006H, 0bbH, 02cH, 0ffH}>
InputReachedTarget_Event_GUID                   GUID    <093ed549aH, 00549H, 040f0H, {0beH, 0dbH, 028H, 0e4H, 04fH, 07dH, 0e2H, 0a3H}>
InputReachedOtherElement_Event_GUID             GUID    <0ed201d8aH, 04e6cH, 0415eH, {0a8H, 074H, 024H, 060H, 0c9H, 0b6H, 06bH, 0a8H}>
InputDiscarded_Event_GUID                       GUID    <07f36c367H, 07b18H, 0417cH, {097H, 0e3H, 09dH, 058H, 0ddH, 0c9H, 044H, 0abH}>
SystemAlert_Event_GUID                          GUID    <0d271545dH, 07a3aH, 047a7H, {084H, 074H, 081H, 0d2H, 09aH, 024H, 051H, 0c9H}>
LiveRegionChanged_Event_GUID                    GUID    <0102d5e90H, 0e6a9H, 041b6H, {0b1H, 0c5H, 0a9H, 0b1H, 092H, 09dH, 095H, 010H}>
HostedFragmentRootsInvalidated_Event_GUID       GUID    <0e6bdb03eH, 00921H, 04ec5H, {08dH, 0cfH, 0eaH, 0e8H, 077H, 0b0H, 042H, 06bH}>
Drag_DragStart_Event_GUID                       GUID    <0883a480bH, 03aa9H, 0429dH, {095H, 0e4H, 0d9H, 0c8H, 0d0H, 011H, 0f0H, 0ddH}>
Drag_DragCancel_Event_GUID                      GUID    <0c3ede6faH, 03451H, 04e0fH, {09eH, 071H, 0dfH, 09cH, 028H, 0aH, 046H, 057H}>
Drag_DragComplete_Event_GUID                    GUID    <038e96188H, 0ef1fH, 0463eH, {091H, 0caH, 03aH, 077H, 092H, 0c2H, 09cH, 0afH}>
DropTarget_DragEnter_Event_GUID                 GUID    <0aad9319bH, 0032cH, 04a88H, {096H, 01dH, 01cH, 0f5H, 079H, 058H, 01eH, 034H}>
DropTarget_DragLeave_Event_GUID                 GUID    <0f82eb15H,  024a2H, 04988H, {092H, 017H, 0deH, 016H, 02aH, 0eeH, 027H, 02bH}>
DropTarget_Dropped_Event_GUID                   GUID    <0622cead8H, 01edbH, 04a3dH, {0abH, 0bcH, 0beH, 022H, 011H, 0ffH, 068H, 0b5H}>
Invoke_Pattern_GUID                             GUID    <0d976c2fcH, 066eaH, 04a6eH, {0b2H, 08fH, 0c2H, 04cH, 075H, 046H, 0adH, 037H}>
Selection_Pattern_GUID                          GUID    <066e3b7e8H, 0d821H, 04d25H, {087H, 061H, 043H, 05dH, 02cH, 08bH, 025H, 03fH}>
Value_Pattern_GUID                              GUID    <017faad9eH, 0c877H, 0475bH, {0b9H, 033H, 077H, 033H, 027H, 079H, 0b6H, 037H}>
RangeValue_Pattern_GUID                         GUID    <018b00d87H, 0b1c9H, 0476aH, {0bfH, 0bdH, 05fH, 00bH, 0dbH, 092H, 06fH, 063H}>
Scroll_Pattern_GUID                             GUID    <0895fa4b4H, 0759dH, 04c50H, {08eH, 015H, 003H, 046H, 006H, 072H, 000H, 03cH}>
ExpandCollapse_Pattern_GUID                     GUID    <0ae05efa2H, 0f9d1H, 0428aH, {083H, 04cH, 053H, 0a5H, 0c5H, 02fH, 09bH, 08bH}>
Grid_Pattern_GUID                               GUID    <0260a2ccbH, 093a8H, 04e44H, {0a4H, 0c1H, 03dH, 0f3H, 097H, 0f2H, 0b0H, 02bH}>
GridItem_Pattern_GUID                           GUID    <0f2d5c877H, 0a462H, 04957H, {0a2H, 0a5H, 02cH, 096H, 0b3H, 003H, 0bcH, 063H}>
MultipleView_Pattern_GUID                       GUID    <0547a6ae4H, 0113fH, 047c4H, {085H, 00fH, 0dbH, 04dH, 0faH, 046H, 06bH, 01dH}>
Window_Pattern_GUID                             GUID    <027901735H, 0c760H, 04994H, {0adH, 011H, 059H, 019H, 0e6H, 006H, 0b1H, 010H}>
SelectionItem_Pattern_GUID                      GUID    <09bc64eebH, 087c7H, 04b28H, {094H, 0bbH, 04dH, 09fH, 0a4H, 037H, 0b6H, 0efH}>
Dock_Pattern_GUID                               GUID    <09cbaa846H, 083c8H, 0428dH, {082H, 07fH, 07eH, 060H, 063H, 0feH, 006H, 020H}>
Table_Pattern_GUID                              GUID    <0c415218eH, 0a028H, 0461eH, {0aaH, 092H, 08fH, 092H, 05cH, 0f7H, 093H, 051H}>
TableItem_Pattern_GUID                          GUID    <0df1343bdH, 01888H, 04a29H, {0a5H, 00cH, 0b9H, 02eH, 06dH, 0e3H, 07fH, 06fH}>
Text_Pattern_GUID                               GUID    <08615f05dH, 07de5H, 044fdH, {0a6H, 079H, 02cH, 0a4H, 0b4H, 060H, 033H, 0a8H}>
Toggle_Pattern_GUID                             GUID    <00b419760H, 0e2f4H, 043ffH, {08cH, 05fH, 094H, 057H, 0c8H, 02bH, 056H, 0e9H}>
Transform_Pattern_GUID                          GUID    <024b46fdbH, 0587eH, 049f1H, {09cH, 04aH, 0d8H, 0e9H, 08bH, 066H, 04bH, 07bH}>
ScrollItem_Pattern_GUID                         GUID    <04591d005H, 0a803H, 04d5cH, {0b4H, 0d5H, 08dH, 028H, 000H, 0f9H, 006H, 0a7H}>
LegacyIAccessible_Pattern_GUID                  GUID    <054cc0a9fH, 03395H, 048afH, {0baH, 08dH, 073H, 0f8H, 056H, 090H, 0f3H, 0e0H}>
ItemContainer_Pattern_GUID                      GUID    <03d13da0fH, 08b9aH, 04a99H, {085H, 0faH, 0c5H, 0c9H, 0a6H, 09fH, 01eH, 0d4H}>
VirtualizedItem_Pattern_GUID                    GUID    <0f510173eH, 02e71H, 045e9H, {0a6H, 0e5H, 062H, 0f6H, 0edH, 082H, 089H, 0d5H}>
SynchronizedInput_Pattern_GUID                  GUID    <005c288a6H, 0c47bH, 0488bH, {0b6H, 053H, 033H, 097H, 07aH, 055H, 01bH, 08bH}>
ObjectModel_Pattern_GUID                        GUID    <03e04acfeH, 008fcH, 047ecH, {096H, 0bcH, 035H, 03fH, 0a3H, 0b3H, 04aH, 0a7H}>
Annotation_Pattern_GUID                         GUID    <0f6c72ad7H, 0356cH, 04850H, {092H, 091H, 031H, 06fH, 060H, 08aH, 08cH, 084H}>
Text_Pattern2_GUID                              GUID    <0498479a2H, 05b22H, 0448dH, {0b6H, 0e4H, 064H, 074H, 090H, 086H, 006H, 098H}>
TextEdit_Pattern_GUID                           GUID    <069f3ff89H, 05af9H, 04c75H, {093H, 040H, 0f2H, 0deH, 029H, 02eH, 045H, 091H}>
CustomNavigation_Pattern_GUID                   GUID    <0afea938aH, 0621eH, 04054H, {0bbH, 02cH, 02fH, 046H, 011H, 04dH, 0acH, 03fH}>
Styles_Pattern_GUID                             GUID    <01ae62655H, 0da72H, 04d60H, {0a1H, 053H, 0e5H, 0aaH, 069H, 088H, 0e3H, 0bfH}>
Spreadsheet_Pattern_GUID                        GUID    <06a5b24c9H, 09d1eH, 04b85H, {09eH, 044H, 0c0H, 02eH, 031H, 069H, 0b1H, 00bH}>
SpreadsheetItem_Pattern_GUID                    GUID    <032cf83ffH, 0f1a8H, 04a8cH, {086H, 058H, 0d4H, 07bH, 0a7H, 04eH, 020H, 0baH}>
Tranform_Pattern2_GUID                          GUID    <08afcfd07H, 0a369H, 044deH, {098H, 08bH, 02fH, 07fH, 0f4H, 09fH, 0b8H, 0a8H}>
TextChild_Pattern_GUID                          GUID    <07533cab7H, 03bfeH, 041efH, {09eH, 085H, 0e2H, 063H, 08cH, 0beH, 016H, 09eH}>
Drag_Pattern_GUID                               GUID    <0c0bee21fH, 0ccb3H, 04fedH, {099H, 05bH, 011H, 04fH, 06eH, 03dH, 027H, 028H}>
DropTarget_Pattern_GUID                         GUID    <00bcbec56H, 0bd34H, 04b7bH, {09fH, 0d5H, 026H, 059H, 090H, 05eH, 0a3H, 0dcH}>
Button_Control_GUID                             GUID    <05a78e369H, 0c6a1H, 04f33H, {0a9H, 0d7H, 079H, 0f2H, 00dH, 00cH, 078H, 08eH}>
Calendar_Control_GUID                           GUID    <08913eb88H, 000e5H, 046bcH, {08eH, 04eH, 014H, 0a7H, 086H, 0e1H, 065H, 0a1H}>
CheckBox_Control_GUID                           GUID    <0fb50f922H, 0a3dbH, 049c0H, {08bH, 0c3H, 006H, 0daH, 0d5H, 057H, 078H, 0e2H}>
ComboBox_Control_GUID                           GUID    <054cb426cH, 02f33H, 04fffH, {0aaH, 0a1H, 0aeH, 0f6H, 00dH, 0acH, 05dH, 0ebH}>
Edit_Control_GUID                               GUID    <06504a5c8H, 02c86H, 04f87H, {0aeH, 07bH, 01aH, 0bdH, 0dcH, 081H, 00cH, 0f9H}>
Hyperlink_Control_GUID                          GUID    <08a56022cH, 0b00dH, 04d15H, {08fH, 0f0H, 05bH, 06bH, 026H, 06eH, 05eH, 002H}>
Image_Control_GUID                              GUID    <02d3736e4H, 06b16H, 04c57H, {0a9H, 062H, 0f9H, 032H, 060H, 0a7H, 052H, 043H}>
ListItem_Control_GUID                           GUID    <07b3717f2H, 044d1H, 04a58H, {098H, 0a8H, 0f1H, 02aH, 09bH, 08fH, 078H, 0e2H}>
List_Control_GUID                               GUID    <09b149ee1H, 07ccaH, 04cfcH, {09aH, 0f1H, 0caH, 0c7H, 0bdH, 0ddH, 030H, 031H}>
Menu_Control_GUID                               GUID    <02e9b1440H, 00ea8H, 041fdH, {0b3H, 074H, 0c1H, 0eaH, 06fH, 050H, 03cH, 0d1H}>
MenuBar_Control_GUID                            GUID    <0cc384250H, 00e7bH, 04ae8H, {095H, 0aeH, 0a0H, 08fH, 026H, 01bH, 052H, 0eeH}>
MenuItem_Control_GUID                           GUID    <0f45225d3H, 0d0a0H, 049d8H, {098H, 034H, 09aH, 000H, 00dH, 02aH, 0edH, 0dcH}>
ProgressBar_Control_GUID                        GUID    <0228c9f86H, 0c36cH, 047bbH, {09fH, 0b6H, 0a5H, 083H, 04bH, 0fcH, 053H, 0a4H}>
RadioButton_Control_GUID                        GUID    <03bdb49dbH, 0fe2cH, 04483H, {0b3H, 0e1H, 0e5H, 07fH, 021H, 094H, 040H, 0c6H}>
ScrollBar_Control_GUID                          GUID    <0daf34b36H, 05065H, 04946H, {0b2H, 02fH, 092H, 059H, 05fH, 0c0H, 075H, 01aH}>
Slider_Control_GUID                             GUID    <0b033c24bH, 03b35H, 04ceaH, {0b6H, 009H, 076H, 036H, 082H, 0faH, 066H, 00bH}>
Spinner_Control_GUID                            GUID    <060cc4b38H, 03cb1H, 04161H, {0b4H, 042H, 0c6H, 0b7H, 026H, 0c1H, 078H, 025H}>
StatusBar_Control_GUID                          GUID    <0d45e7d1bH, 05873H, 0475fH, {095H, 0a4H, 004H, 033H, 0e1H, 0f1H, 0b0H, 00aH}>
Tab_Control_GUID                                GUID    <038cd1f2dH, 0337aH, 04bd2H, {0a5H, 0e3H, 0adH, 0b4H, 069H, 0e3H, 00bH, 0d3H}>
TabItem_Control_GUID                            GUID    <02c6a634fH, 0921bH, 04e6eH, {0b2H, 06eH, 008H, 0fcH, 0b0H, 079H, 08fH, 04cH}>
Text_Control_GUID                               GUID    <0ae9772dcH, 0d331H, 04f09H, {0beH, 020H, 07eH, 06dH, 0faH, 0f0H, 07bH, 00aH}>
ToolBar_Control_GUID                            GUID    <08f06b751H, 0e182H, 04e98H, {088H, 093H, 022H, 084H, 054H, 03aH, 07dH, 0ceH}>
ToolTip_Control_GUID                            GUID    <005ddc6d1H, 02137H, 04768H, {098H, 0eaH, 073H, 0f5H, 02fH, 071H, 034H, 0f3H}>
Tree_Control_GUID                               GUID    <07561349cH, 0d241H, 043f4H, {099H, 008H, 0b5H, 0f0H, 091H, 0beH, 0e6H, 011H}>
TreeItem_Control_GUID                           GUID    <062c9feb9H, 08ffcH, 04878H, {0a3H, 0a4H, 096H, 0b0H, 030H, 031H, 05cH, 018H}>
Custom_Control_GUID                             GUID    <0f29ea0c3H, 0adb7H, 0430aH, {0baH, 090H, 0e5H, 02cH, 073H, 013H, 0e6H, 0edH}>
Group_Control_GUID                              GUID    <0ad50aa1cH, 0e8c8H, 04774H, {0aeH, 01bH, 0ddH, 086H, 0dfH, 00bH, 03bH, 0dcH}>
Thumb_Control_GUID                              GUID    <0701ca877H, 0e310H, 04dd6H, {0b6H, 044H, 079H, 07eH, 04fH, 0aeH, 0a2H, 013H}>
DataGrid_Control_GUID                           GUID    <084b783afH, 0d103H, 04b0aH, {084H, 015H, 0e7H, 039H, 042H, 041H, 00fH, 04bH}>
DataItem_Control_GUID                           GUID    <0a0177842H, 0d94fH, 042a5H, {081H, 04bH, 060H, 068H, 0adH, 0dcH, 08dH, 0a5H}>
Document_Control_GUID                           GUID    <03cd6bb6fH, 06f08H, 04562H, {0b2H, 029H, 0e4H, 0e2H, 0fcH, 07aH, 09eH, 0b4H}>
SplitButton_Control_GUID                        GUID    <07011f01fH, 04aceH, 04901H, {0b4H, 061H, 092H, 00aH, 06fH, 01cH, 0a6H, 050H}>
Window_Control_GUID                             GUID    <0e13a7242H, 0f462H, 04f4dH, {0aeH, 0c1H, 053H, 0b2H, 08dH, 06cH, 032H, 090H}>
Pane_Control_GUID                               GUID    <05c2b3f5bH, 09182H, 042a3H, {08dH, 0ecH, 08cH, 004H, 0c1H, 0eeH, 063H, 04dH}>
Header_Control_GUID                             GUID    <05b90cbceH, 078fbH, 04614H, {082H, 0b6H, 055H, 04dH, 074H, 071H, 08eH, 067H}>
HeaderItem_Control_GUID                         GUID    <0e6bc12cbH, 07c8eH, 049cfH, {0b1H, 068H, 04aH, 093H, 0a3H, 02bH, 0ebH, 0b0H}>
Table_Control_GUID                              GUID    <0773bfa0eH, 05bc4H, 04debH, {092H, 01bH, 0deH, 07bH, 032H, 006H, 022H, 09eH}>
TitleBar_Control_GUID                           GUID    <098aa55bfH, 03bb0H, 04b65H, {083H, 06eH, 02eH, 0a3H, 00dH, 0bcH, 017H, 01fH}>
Separator_Control_GUID                          GUID    <08767eba3H, 02a63H, 04ab0H, {0acH, 08dH, 0aaH, 050H, 0e2H, 03dH, 0e9H, 078H}>
SemanticZoom_Control_GUID                       GUID    <05FD34A43H, 0061EH, 042C8H, {0B5H, 089H, 09DH, 0CCH, 0F7H, 04BH, 0C4H, 03AH}>
AppBar_Control_GUID                             GUID    <06114908DH, 0CC02H, 04D37H, {087H, 05BH, 0B5H, 030H, 0C7H, 013H, 095H, 054H}>
Text_AnimationStyle_Attribute_GUID              GUID    <0628209f0H, 07c9aH, 04d57H, {0beH, 064H, 01fH, 018H, 036H, 057H, 01fH, 0f5H}>
Text_BackgroundColor_Attribute_GUID             GUID    <0fdc49a07H, 0583dH, 04f17H, {0adH, 027H, 077H, 0fcH, 083H, 02aH, 03cH, 00bH}>
Text_BulletStyle_Attribute_GUID                 GUID    <0c1097c90H, 0d5c4H, 04237H, {097H, 081H, 03bH, 0ecH, 08bH, 0a5H, 04eH, 048H}>
Text_CapStyle_Attribute_GUID                    GUID    <0fb059c50H, 092ccH, 049a5H, {0baH, 08fH, 00aH, 0a8H, 072H, 0bbH, 0a2H, 0f3H}>
Text_Culture_Attribute_GUID                     GUID    <0c2025af9H, 0a42dH, 04cedH, {0a1H, 0fbH, 0c6H, 074H, 063H, 015H, 022H, 02eH}>
Text_FontName_Attribute_GUID                    GUID    <064e63ba8H, 0f2e5H, 0476eH, {0a4H, 077H, 017H, 034H, 0feH, 0aaH, 0f7H, 026H}>
Text_FontSize_Attribute_GUID                    GUID    <0dc5eeeffH, 00506H, 04673H, {093H, 0f2H, 037H, 07eH, 04aH, 08eH, 001H, 0f1H}>
Text_FontWeight_Attribute_GUID                  GUID    <06fc02359H, 0b316H, 04f5fH, {0b4H, 001H, 0f1H, 0ceH, 055H, 074H, 018H, 053H}>
Text_ForegroundColor_Attribute_GUID             GUID    <072d1c95dH, 05e60H, 0471aH, {096H, 0b1H, 06cH, 01bH, 03bH, 077H, 0a4H, 036H}>
Text_HorizontalTextAlignment_Attribute_GUID     GUID    <004ea6161H, 0fba3H, 0477aH, {095H, 02aH, 0bbH, 032H, 06dH, 002H, 06aH, 05bH}>
Text_IndentationFirstLine_Attribute_GUID        GUID    <0206f9ad5H, 0c1d3H, 0424aH, {081H, 082H, 06dH, 0a9H, 0a7H, 0f3H, 0d6H, 032H}>
Text_IndentationLeading_Attribute_GUID          GUID    <05cf66bacH, 02d45H, 04a4bH, {0b6H, 0c9H, 0f7H, 022H, 01dH, 028H, 015H, 0b0H}>
Text_IndentationTrailing_Attribute_GUID         GUID    <097ff6c0fH, 01ce4H, 0408aH, {0b6H, 07bH, 094H, 0d8H, 03eH, 0b6H, 09bH, 0f2H}>
Text_IsHidden_Attribute_GUID                    GUID    <0360182fbH, 0bdd7H, 047f6H, {0abH, 069H, 019H, 0e3H, 03fH, 08aH, 033H, 044H}>
Text_IsItalic_Attribute_GUID                    GUID    <0fce12a56H, 01336H, 04a34H, {096H, 063H, 01bH, 0abH, 047H, 023H, 093H, 020H}>
Text_IsReadOnly_Attribute_GUID                  GUID    <0a738156bH, 0ca3eH, 0495eH, {095H, 014H, 083H, 03cH, 044H, 00fH, 0ebH, 011H}>
Text_IsSubscript_Attribute_GUID                 GUID    <0f0ead858H, 08f53H, 0413cH, {087H, 03fH, 01aH, 07dH, 07fH, 05eH, 00dH, 0e4H}>
Text_IsSuperscript_Attribute_GUID               GUID    <0da706ee4H, 0b3aaH, 04645H, {0a4H, 01fH, 0cdH, 025H, 015H, 07dH, 0eaH, 076H}>
Text_MarginBottom_Attribute_GUID                GUID    <07ee593c4H, 072b4H, 04cacH, {092H, 071H, 03eH, 0d2H, 04bH, 00eH, 04dH, 042H}>
Text_MarginLeading_Attribute_GUID               GUID    <09e9242d0H, 05ed0H, 04900H, {08eH, 08aH, 0eeH, 0ccH, 003H, 083H, 05aH, 0fcH}>
Text_MarginTop_Attribute_GUID                   GUID    <0683d936fH, 0c9b9H, 04a9aH, {0b3H, 0d9H, 0d2H, 00dH, 033H, 031H, 01eH, 02aH}>
Text_MarginTrailing_Attribute_GUID              GUID    <0af522f98H, 0999dH, 040afH, {0a5H, 0b2H, 001H, 069H, 0d0H, 034H, 020H, 002H}>
Text_OutlineStyles_Attribute_GUID               GUID    <05b675b27H, 0db89H, 046feH, {097H, 00cH, 061H, 04dH, 052H, 03bH, 0b9H, 07dH}>
Text_OverlineColor_Attribute_GUID               GUID    <083ab383aH, 0fd43H, 040daH, {0abH, 03eH, 0ecH, 0f8H, 016H, 05cH, 0bbH, 06dH}>
Text_OverlineStyle_Attribute_GUID               GUID    <00a234d66H, 0617eH, 0427fH, {087H, 01dH, 0e1H, 0ffH, 01eH, 00cH, 021H, 03fH}>
Text_StrikethroughColor_Attribute_GUID          GUID    <0bfe15a18H, 08c41H, 04c5aH, {09aH, 00bH, 004H, 0afH, 00eH, 007H, 0f4H, 087H}>
Text_StrikethroughStyle_Attribute_GUID          GUID    <072913ef1H, 0da00H, 04f01H, {089H, 09cH, 0acH, 05aH, 085H, 077H, 0a3H, 007H}>
Text_Tabs_Attribute_GUID                        GUID    <02e68d00bH, 092feH, 042d8H, {089H, 09aH, 0a7H, 084H, 0aaH, 044H, 054H, 0a1H}>
Text_TextFlowDirections_Attribute_GUID          GUID    <08bdf8739H, 0f420H, 0423eH, {0afH, 077H, 020H, 0a5H, 0d9H, 073H, 0a9H, 007H}>
Text_UnderlineColor_Attribute_GUID              GUID    <0bfa12c73H, 0fde2H, 04473H, {0bfH, 064H, 010H, 036H, 0d6H, 0aaH, 00fH, 045H}>
Text_UnderlineStyle_Attribute_GUID              GUID    <05f3b21c0H, 0ede4H, 044bdH, {09cH, 036H, 038H, 053H, 003H, 08cH, 0bfH, 0ebH}>
Text_AnnotationTypes_Attribute_GUID             GUID    <0ad2eb431H, 0ee4eH, 04be1H, {0a7H, 0baH, 055H, 059H, 015H, 05aH, 073H, 0efH}>
Text_AnnotationObjects_Attribute_GUID           GUID    <0ff41cf68H, 0e7abH, 040b9H, {08cH, 072H, 072H, 0a8H, 0edH, 094H, 001H, 07dH}>
Text_StyleName_Attribute_GUID                   GUID    <022c9e091H, 04d66H, 045d8H, {0a8H, 028H, 073H, 07bH, 0abH, 04cH, 098H, 0a7H}>
Text_StyleId_Attribute_GUID                     GUID    <014c300deH, 0c32bH, 0449bH, {0abH, 07cH, 0b0H, 0e0H, 078H, 09aH, 0eaH, 05dH}>
Text_Link_Attribute_GUID                        GUID    <0b38ef51dH, 09e8dH, 04e46H, {091H, 044H, 056H, 0ebH, 0e1H, 077H, 032H, 09bH}>
Text_IsActive_Attribute_GUID                    GUID    <0f5a4e533H, 0e1b8H, 0436bH, {093H, 05dH, 0b5H, 07aH, 0a3H, 0f5H, 058H, 0c4H}>
Text_SelectionActiveEnd_Attribute_GUID          GUID    <01f668cc3H, 09bbfH, 0416bH, {0b0H, 0a2H, 0f8H, 09fH, 086H, 0f6H, 061H, 02cH}>
Text_CaretPosition_Attribute_GUID               GUID    <0b227b131H, 09889H, 04752H, {0a9H, 01bH, 073H, 03eH, 0fdH, 0c5H, 0c5H, 0a0H}>
Text_CaretBidiMode_Attribute_GUID               GUID    <0929ee7a6H, 051d3H, 04715H, {096H, 0dcH, 0b6H, 094H, 0faH, 024H, 0a1H, 068H}>
Text_BeforeParagraphSpacing_Attribute_GUID      GUID    <0be7b0ab1H, 0c822H, 04a24H, {085H, 0e9H, 0c8H, 0f2H, 065H, 0fH, 0c7H, 09cH}>
Text_AfterParagraphSpacing_Attribute_GUID       GUID    <0588cbb38H, 0e62fH, 0497cH, {0b5H, 0d1H, 0ccH, 0dfH, 0eH, 0e8H, 023H, 0d8H}>
Text_LineSpacing_Attribute_GUID                 GUID    <063ff70aeH, 0d943H, 04b47H, {08aH, 0b7H, 0a7H, 0a0H, 033H, 0d3H, 021H, 04bH}>
Text_BeforeSpacing_Attribute_GUID               GUID    <0be7b0ab1H, 0c822H, 04a24H, {085H, 0e9H, 0c8H, 0f2H, 065H, 0fH,  0c7H, 09cH}>
Text_AfterSpacing_Attribute_GUID                GUID    <0588cbb38H, 0e62fH, 0497cH, {0b5H, 0d1H, 0ccH, 0dfH, 0eH, 0e8H,  023H, 0d8H}>
Text_SayAsInterpretAs_Attribute_GUID            GUID    <0b38ad6acH, 0eee1H, 04b6eH, {088H, 0ccH, 001H, 04cH, 0efH, 0a9H, 03fH, 0cbH}>
TextEdit_TextChanged_Event_GUID                 GUID    <0120b0308H, 0ec22H, 04eb8H, {09cH, 098H, 098H, 067H, 0cdH, 0a1H, 0b1H, 065H}>
TextEdit_ConversionTargetChanged_Event_GUID     GUID    <03388c183H, 0ed4fH, 04c8bH, {09bH, 0aaH, 036H, 04dH, 051H, 0d8H, 084H, 07fH}>
Changes_Event_GUID                              GUID    <07df26714H, 0614fH, 04e05H, {094H, 088H, 071H, 06cH, 05bH, 0a1H, 094H, 036H}>
Annotation_Custom_GUID                          GUID    <09ec82750H, 03931H, 04952H, {085H, 0bcH, 01dH, 0bfH, 0f7H, 08aH, 043H, 0e3H}>
Annotation_SpellingError_GUID                   GUID    <0ae85567eH, 09eceH, 0423fH, {081H, 0b7H, 096H, 0c4H, 03dH, 053H, 0e5H, 00eH}>
Annotation_GrammarError_GUID                    GUID    <0757a048dH, 04518H, 041c6H, {085H, 04cH, 0dcH, 000H, 09bH, 07cH, 0fbH, 053H}>
Annotation_Comment_GUID                         GUID    <0fd2fda30H, 026b3H, 04c06H, {08bH, 0c7H, 098H, 0f1H, 053H, 02eH, 046H, 0fdH}>
Annotation_FormulaError_GUID                    GUID    <095611982H, 00cabH, 046d5H, {0a2H, 0f0H, 0e3H, 00dH, 019H, 005H, 0f8H, 0bfH}>
Annotation_TrackChanges_GUID                    GUID    <021e6e888H, 0dc14H, 04016H, {0acH, 027H, 019H, 005H, 053H, 0c8H, 0c4H, 070H}>
Annotation_Header_GUID                          GUID    <0867b409bH, 0b216H, 04472H, {0a2H, 019H, 052H, 05eH, 031H, 006H, 081H, 0f8H}>
Annotation_Footer_GUID                          GUID    <0cceab046H, 01833H, 047aaH, {080H, 080H, 070H, 01eH, 0d0H, 0b0H, 0c8H, 032H}>
Annotation_Highlighted_GUID                     GUID    <0757c884eH, 08083H, 04081H, {08bH, 09cH, 0e8H, 07fH, 050H, 072H, 0f0H, 0e4H}>
Annotation_Endnote_GUID                         GUID    <07565725cH, 02d99H, 04839H, {096H, 00dH, 033H, 0d3H, 0b8H, 066H, 0abH, 0a5H}>
Annotation_Footnote_GUID                        GUID    <03de10e21H, 04125H, 042dbH, {086H, 020H, 0beH, 080H, 083H, 008H, 006H, 024H}>
Annotation_InsertionChange_GUID                 GUID    <00dbeb3a6H, 0df15H, 04164H, {0a3H, 0c0H, 0e2H, 01aH, 08cH, 0e9H, 031H, 0c4H}>
Annotation_DeletionChange_GUID                  GUID    <0be3d5b05H, 0951dH, 042e7H, {090H, 01dH, 0adH, 0c8H, 0c2H, 0cfH, 034H, 0d0H}>
Annotation_MoveChange_GUID                      GUID    <09da587ebH, 023e5H, 04490H, {0b3H, 085H, 01aH, 022H, 0ddH, 0c8H, 0b1H, 087H}>
Annotation_FormatChange_GUID                    GUID    <0eb247345H, 0d4f1H, 041ceH, {08eH, 052H, 0f7H, 09bH, 069H, 063H, 05eH, 048H}>
Annotation_UnsyncedChange_GUID                  GUID    <01851116aH, 00e47H, 04b30H, {08cH, 0b5H, 0d7H, 0daH, 0e4H, 0fbH, 0cdH, 01bH}>
Annotation_EditingLockedChange_GUID             GUID    <0c31f3e1cH, 07423H, 04dacH, {083H, 048H, 041H, 0f0H, 099H, 0ffH, 06fH, 064H}>
Annotation_ExternalChange_GUID                  GUID    <075a05b31H, 05f11H, 042fdH, {088H, 07dH, 0dfH, 0a0H, 010H, 0dbH, 023H, 092H}>
Annotation_ConflictingChange_GUID               GUID    <098af8802H, 0517cH, 0459fH, {0afH, 013H, 001H, 06dH, 03fH, 0abH, 087H, 07eH}>
Annotation_Author_GUID                          GUID    <0f161d3a7H, 0f81bH, 04128H, {0b1H, 07fH, 071H, 0f6H, 090H, 091H, 045H, 020H}>
Annotation_AdvancedProofingIssue_GUID           GUID    <0dac7b72cH, 0c0f2H, 04b84H, {0b9H, 00dH, 05fH, 0afH, 0c0H, 0f0H, 0efH, 01cH}>
Annotation_DataValidationError_GUID             GUID    <0c8649fa8H, 09775H, 0437eH, {0adH, 046H, 0e7H, 009H, 0d9H, 03cH, 023H, 043H}>
Annotation_CircularReferenceError_GUID          GUID    <025bd9cf4H, 01745H, 04659H, {0baH, 067H, 072H, 07fH, 003H, 018H, 0c6H, 016H}>
Annotation_Mathematics_GUID                     GUID    <0eaab634bH, 026d0H, 040c1H, {080H, 073H, 057H, 0caH, 01cH, 063H, 03cH, 09bH}>

Changes_Summary_GUID                            GUID    <0313d65a6H, 0e60fH, 04d62H, {098H, 061H, 055H, 0afH, 0d7H, 028H, 0d2H, 007H}>

StyleId_Custom_GUID                             GUID    <0ef2edd3eH, 0a999H, 04b7cH, {0a3H, 078H, 009H, 0bbH, 0d5H, 02aH, 035H, 016H}>
StyleId_Heading1_GUID                           GUID    <07f7e8f69H, 06866H, 04621H, {093H, 00cH, 09aH, 05dH, 00cH, 0a5H, 096H, 01cH}>
StyleId_Heading2_GUID                           GUID    <0baa9b241H, 05c69H, 0469dH, {085H, 0adH, 047H, 047H, 037H, 0b5H, 02bH, 014H}>
StyleId_Heading3_GUID                           GUID    <0bf8be9d2H, 0d8b8H, 04ec5H, {08cH, 052H, 09cH, 0fbH, 00dH, 003H, 059H, 070H}>
StyleId_Heading4_GUID                           GUID    <08436ffc0H, 09578H, 045fcH, {083H, 0a4H, 0ffH, 040H, 005H, 033H, 015H, 0ddH}>
StyleId_Heading5_GUID                           GUID    <0909f424dH, 00dbfH, 0406eH, {097H, 0bbH, 04eH, 077H, 03dH, 097H, 098H, 0f7H}>
StyleId_Heading6_GUID                           GUID    <089d23459H, 05d5bH, 04824H, {0a4H, 020H, 011H, 0d3H, 0edH, 082H, 0e4H, 00fH}>
StyleId_Heading7_GUID                           GUID    <0a3790473H, 0e9aeH, 0422dH, {0b8H, 0e3H, 03bH, 067H, 05cH, 061H, 081H, 0a4H}>
StyleId_Heading8_GUID                           GUID    <02bc14145H, 0a40cH, 04881H, {084H, 0aeH, 0f2H, 023H, 056H, 085H, 038H, 00cH}>
StyleId_Heading9_GUID                           GUID    <0c70d9133H, 0bb2aH, 043d3H, {08aH, 0c6H, 033H, 065H, 078H, 084H, 0b0H, 0f0H}>
StyleId_Title_GUID                              GUID    <015d8201aH, 0ffcfH, 0481fH, {0b0H, 0a1H, 030H, 0b6H, 03bH, 0e9H, 08fH, 007H}>
StyleId_Subtitle_GUID                           GUID    <0b5d9fc17H, 05d6fH, 04420H, {0b4H, 039H, 07cH, 0b1H, 09aH, 0d4H, 034H, 0e2H}>
StyleId_Normal_GUID                             GUID    <0cd14d429H, 0e45eH, 04475H, {0a1H, 0c5H, 07fH, 09eH, 06bH, 0e9H, 06eH, 0baH}>
StyleId_Emphasis_GUID                           GUID    <0ca6e7dbeH, 0355eH, 04820H, {095H, 0a0H, 092H, 05fH, 004H, 01dH, 034H, 070H}>
StyleId_Quote_GUID                              GUID    <05d1c21eaH, 08195H, 04f6cH, {087H, 0eaH, 05dH, 0abH, 0ecH, 0e6H, 04cH, 01dH}>
StyleId_BulletedList_GUID                       GUID    <05963ed64H, 06426H, 04632H, {08cH, 0afH, 0a3H, 02aH, 0d4H, 002H, 0d9H, 01aH}>
StyleId_NumberedList_GUID                       GUID    <01e96dbd5H, 064c3H, 043d0H, {0b1H, 0eeH, 0b5H, 03bH, 006H, 0e3H, 0edH, 0dfH}>
Notification_Event_GUID                         GUID    <072c5a2f7H, 09788H, 0480fH, {0b8H, 0ebH, 04dH, 0eeH, 000H, 0f6H, 018H, 06fH}>

SID_IsUIAutomationObject                        GUID    <0b96fdb85H, 07204H, 04724H, {084H, 02bH, 0c7H, 005H, 09dH, 0edH, 0b9H, 0d0H}>
SID_ControlElementProvider                      GUID    <0f4791d68H, 0e254H, 04ba3H, {09aH, 053H, 026H, 0a5H, 0c5H, 049H, 079H, 046H}>

IsSelectionPattern2Available_Property_GUID      GUID    <0490806fbH, 06e89H, 04a47H, {083H, 019H, 0d2H, 066H, 0e5H, 011H, 0f0H, 021H}>
Selection2_FirstSelectedItem_Property_GUID      GUID    <0cc24ea67H, 0369cH, 04e55H, {09fH, 0f7H, 038H, 0daH, 069H, 054H, 00cH, 029H}>
Selection2_LastSelectedItem_Property_GUID       GUID    <0cf7bda90H, 02d83H, 049f8H, {086H, 00cH, 09cH, 0e3H, 094H, 0cfH, 089H, 0b4H}>
Selection2_CurrentSelectedItem_Property_GUID    GUID    <034257c26H, 083b5H, 041a6H, {093H, 09cH, 0aeH, 084H, 01cH, 013H, 062H, 036H}>
Selection2_ItemCount_Property_GUID              GUID    <0bb49eb9fH, 0456dH, 04048H, {0b5H, 091H, 09cH, 020H, 026H, 0b8H, 046H, 036H}>
Selection_Pattern2_GUID                         GUID    <0FBA25CABH, 0AB98H, 049F7H, {0A7H, 0DCH, 0FEH, 053H, 09DH, 0C1H, 05BH, 0E7H}>

;ConditionType Enumeration
ConditionType_True                              EQU     0
ConditionType_False                             EQU     1
ConditionType_Property                          EQU     2
ConditionType_And                               EQU     3
ConditionType_Or                                EQU     4
ConditionType_Not                               EQU     5

UIA_IAFP_DEFAULT                                EQU     0000H
UIA_IAFP_UNWRAP_BRIDGE                          EQU     0001H

UIA_PFIA_DEFAULT                                EQU     0000H
UIA_PFIA_UNWRAP_BRIDGE                          EQU     0001H

;======================================== Structures ======================================;
UiaCondition STRUCT ALIGNMODE
    ConditionType DWORD ?
UiaCondition ENDS

UiaPropertyCondition STRUCT ALIGNMODE
    ConditionType   DWORD   ?
    PropertyId      DWORD   ?
    _Value          VARIANT <>
    Flags           DWORD   ?
UiaPropertyCondition ENDS

UiaAndOrCondition STRUCT ALIGNMODE
    ConditionType   DWORD ?
    ppConditions    XPTR  ?
    cConditions     DWORD ?
UiaAndOrCondition ENDS

UiaNotCondition STRUCT ALIGNMODE
    ConditionType   DWORD ?
    pCondition      XPTR  ?
UiaNotCondition ENDS

UiaCacheRequest STRUCT ALIGNMODE
    pViewCondition          XPTR  ?
    Scope                   DWORD ?
    pProperties             XPTR  ?
    cProperties             DWORD ?
    pPatterns               XPTR  ?
    cPatterns               DWORD ?
    automationElementMode   DWORD ?
UiaCacheRequest ENDS

UiaFindParams STRUCT ALIGNMODE
    MaxDepth        DWORD ?
    FindFirst       DWORD ?
    ExcludeRoot     DWORD ?
    pFindCondition  XPTR  ?
UiaFindParams ENDS

UiaEventArgs STRUCT ALIGNMODE
    _Type   DWORD ?
    EventId DWORD ?
UiaEventArgs ENDS

UiaPropertyChangedEventArgs STRUCT ALIGNMODE
    _Type       DWORD   ?
    EventId     DWORD   ?
    PropertyId  DWORD   ?
    OldValue    VARIANT <>
    NewValue    VARIANT <>
UiaPropertyChangedEventArgs ENDS

UiaStructureChangedEventArgs STRUCT ALIGNMODE
    _Type               DWORD ?
    EventId             DWORD ?
    StructureChangeType DWORD ?
    pRuntimeId          XPTR  ?
    cRuntimeIdLen       DWORD ?
UiaStructureChangedEventArgs ENDS

UiaTextEditTextChangedEventArgs STRUCT ALIGNMODE
    _Type               DWORD ?
    EventId             DWORD ?
    TextEditChangeType  DWORD ?
    pTextChange         XPTR  ?
UiaTextEditTextChangedEventArgs ENDS

UiaChangesEventArgs STRUCT ALIGNMODE
    _Type           DWORD ?
    EventId         DWORD ?
    EventIdCount    DWORD ?
    pUiaChanges     XPTR  ?
UiaChangesEventArgs ENDS

UiaAsyncContentLoadedEventArgs STRUCT ALIGNMODE
    _Type                   DWORD ?
    EventId                 DWORD ?
    AsyncContentLoadedState DWORD ?
    PercentComplete         REAL8 ?
UiaAsyncContentLoadedEventArgs ENDS

UiaWindowClosedEventArgs STRUCT ALIGNMODE
    _Type           DWORD ?
    EventId         DWORD ?
    pRuntimeId      XPTR  ?
    cRuntimeIdLen   DWORD ?
UiaWindowClosedEventArgs ENDS

;======================================== Functions =======================================;
DockPattern_SetDockPosition PROTO :XWORD, :XWORD
ExpandCollapsePattern_Collapse PROTO :XWORD
ExpandCollapsePattern_Expand PROTO :XWORD
GridPattern_GetItem PROTO :XWORD, :XWORD, :XWORD, :XPTR
InvokePattern_Invoke PROTO :XWORD
ItemContainerPattern_FindItemByProperty PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XPTR
LegacyIAccessiblePattern_DoDefaultAction PROTO :XWORD
LegacyIAccessiblePattern_GetIAccessible PROTO :XWORD, :XPTR
LegacyIAccessiblePattern_Select PROTO :XWORD, :XWORD
LegacyIAccessiblePattern_SetValue PROTO :XPTR
MultipleViewPattern_GetViewName PROTO :XWORD, :XPTR
MultipleViewPattern_SetCurrentView PROTO :XWORD, :XWORD
RangeValuePattern_SetValue PROTO :XWORD, :XWORD
ScrollItemPattern_ScrollIntoView PROTO :XWORD
ScrollPattern_Scroll PROTO :XWORD, :XWORD, :XWORD
ScrollPattern_SetScrollPercent Proto :XWORD, :Real8, :Real8
SelectionItemPattern_AddToSelection PROTO :XWORD
SelectionItemPattern_RemoveFromSelection PROTO :XWORD
SelectionItemPattern_Select PROTO :XWORD
IF (NTDDI_VERSION GE NTDDI_WIN10)
    StartIgnoringLeaks PROTO
    StopIgnoringLeaks PROTO
ENDIF
SynchronizedInputPattern_Cancel PROTO :XWORD
SynchronizedInputPattern_StartListening PROTO :XWORD, :XWORD
TextPattern_GetSelection PROTO :XWORD, :XPTR
TextPattern_GetVisibleRanges PROTO :XWORD, :XPTR
TextPattern_RangeFromChild PROTO :XWORD, :XWORD, :XPTR
TextPattern_RangeFromPoint PROTO :XWORD, :XWORD, :XPTR
TextPattern_get_DocumentRange PROTO :XWORD, :XPTR
TextPattern_get_SupportedTextSelection PROTO :XWORD, :XPTR
TextRange_AddToSelection PROTO :XWORD
TextRange_Clone PROTO :XWORD, :XPTR
TextRange_Compare PROTO :XWORD, :XWORD, :XPTR
TextRange_CompareEndpoints PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XPTR
TextRange_ExpandToEnclosingUnit PROTO :XWORD, :XWORD
TextRange_FindAttribute PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XPTR
TextRange_FindText PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XPTR
TextRange_GetAttributeValue PROTO :XWORD, :XWORD, :XPTR
TextRange_GetBoundingRectangles PROTO :XWORD, :XPTR
TextRange_GetChildren PROTO :XWORD, :XPTR
TextRange_GetEnclosingElement PROTO :XWORD, :XPTR
TextRange_GetText PROTO :XWORD, :XWORD, :XPTR
TextRange_Move PROTO :XWORD, :XWORD, :XWORD, :XPTR
TextRange_MoveEndpointByRange PROTO :XWORD, :XWORD, :XWORD, :XWORD
TextRange_MoveEndpointByUnit PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XPTR
TextRange_RemoveFromSelection PROTO :XWORD
TextRange_ScrollIntoView PROTO :XWORD, :XWORD
TextRange_Select PROTO :XWORD
TogglePattern_Toggle PROTO :XWORD
TransformPattern_Move PROTO :XWORD, :REAL8, :REAL8
TransformPattern_Resize PROTO :XWORD, :REAL8, :REAL8
TransformPattern_Rotate PROTO :XWORD, :REAL8
UiaAddEvent PROTO :XWORD, :XWORD, :XPTR, :XWORD, :XPTR, :XWORD, :XPTR, :XPTR
UiaClientsAreListening PROTO
IF (NTDDI_VERSION GE NTDDI_WIN81)
    UiaDisconnectAllProviders PROTO
    UiaDisconnectProvider PROTO :XPTR
ENDIF
UiaEventAddWindow PROTO :XWORD, :XWORD
UiaEventRemoveWindow PROTO :XWORD, :XWORD
UiaFind PROTO :XWORD, :XPTR, :XPTR, :XPTR, :XPTR, :XPTR
UiaGetErrorDescription PROTO :XPTR
UiaGetPatternProvider PROTO :XWORD, :XWORD, :XPTR
UiaGetPropertyValue PROTO :XWORD, :XWORD, :XPTR
UiaGetReservedMixedAttributeValue PROTO :XPTR
UiaGetReservedNotSupportedValue PROTO :XPTR
UiaGetRootNode PROTO :XPTR
UiaGetRuntimeId PROTO :XWORD, :XPTR
UiaGetUpdatedCache PROTO :XWORD, :XPTR, :XWORD, :XPTR, :XPTR, :XPTR
UiaHPatternObjectFromVariant PROTO :XPTR, :XPTR
UiaHTextRangeFromVariant PROTO :XPTR, :XPTR
UiaHUiaNodeFromVariant PROTO :XPTR, :XPTR
UiaHasServerSideProvider PROTO :XWORD
UiaHostProviderFromHwnd PROTO :XWORD, :XPTR
IF (NTDDI_VERSION GE NTDDI_WIN81)
    UiaIAccessibleFromProvider PROTO :XPTR, :XWORD, :XPTR, :XPTR
ENDIF
UiaLookupId PROTO :XWORD, :XPTR
UiaNavigate PROTO :XWORD, :XWORD, :XPTR, :XPTR, :XPTR, :XPTR
UiaNodeFromFocus PROTO :XPTR, :XPTR, :XPTR
UiaNodeFromHandle PROTO :XWORD, :XPTR
UiaNodeFromPoint PROTO :REAL8, :REAL8, :XPTR, :XPTR, :XPTR
UiaNodeFromProvider PROTO :XPTR, :XPTR
UiaNodeRelease PROTO :XWORD
UiaPatternRelease PROTO :XWORD
IF (NTDDI_VERSION GE NTDDI_WIN81)
    UiaProviderForNonClient PROTO :XWORD, :XWORD, :XWORD, :XPTR
    UiaProviderFromIAccessible PROTO :XPTR, :XWORD, :XWORD, :XPTR
ENDIF
UiaRaiseAsyncContentLoadedEvent PROTO :XPTR, :XWORD, :XWORD
UiaRaiseAutomationEvent PROTO :XPTR, :XWORD
UiaRaiseAutomationPropertyChangedEvent PROTO :XPTR, :XWORD, :XWORD, :XWORD
IF (NTDDI_VERSION GE NTDDI_WIN10)
    UiaRaiseChangesEvent PROTO :XPTR, :XWORD, :XPTR
    UiaRaiseNotificationEvent PROTO :XPTR, :XWORD, :XWORD, :XWORD, :XWORD
ENDIF
UiaRaiseStructureChangedEvent PROTO :XPTR, :XWORD, :XPTR, :XWORD
IF (NTDDI_VERSION GE NTDDI_WIN81)
    UiaRaiseTextEditTextChangedEvent PROTO :XPTR, :XWORD, :XPTR
ENDIF
UiaRegisterProviderCallback PROTO :XPTR
UiaRemoveEvent PROTO :XWORD
UiaReturnRawElementProvider PROTO :XWORD, :XWORD, :XWORD, :XPTR
UiaSetFocus PROTO :XWORD
UiaTextRangeRelease PROTO :XWORD
ValuePattern_SetValue PROTO :XWORD, :XWORD
VirtualizedItemPattern_Realize PROTO :XWORD
WindowPattern_Close PROTO :XWORD
WindowPattern_SetWindowVisualState PROTO :XWORD, :XWORD
WindowPattern_WaitForInputIdle PROTO :XWORD, :XWORD, :XPTR


;======================= Undocumented functions (unknown arguments) =======================;
;IF (NTDDI_VERSION GE NTDDI_WIN10)
;    IgnoreLeaksInCurrentlyTrackedMemory PROTO
;    InitializeChannelBasedConnectionForProviderProxy PROTO
;    IsIgnoringLeaks PROTO
;    PostTestCheckForLeaks PROTO
;    UpdateErrorLoggingCallback PROTO
;ENDIF

ENDIF ;UIAUTOMATIONCOREAPI_INC
