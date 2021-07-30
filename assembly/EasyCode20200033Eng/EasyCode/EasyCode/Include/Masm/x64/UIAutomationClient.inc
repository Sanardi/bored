; ==============================================================;
;                                                               ;
; UIAutomationClient.inc for Easy Code 2.0 64-bit Masm projects ;
;                        (version 1.0.1)                        ;
;                                                               ;
;                 Copyright © Ramon Sala - 2020                 ;
;                                                               ;
; ==============================================================;

IFNDEF UIAUTOMATIONCLIENT_INC
UIAUTOMATIONCLIENT_INC  EQU 1

IFNDEF UIAUTOMATIONCORE_INC
    Include UIAutomationCore.inc
ENDIF

IFNDEF UIAUTOMATIONCOREAPI_INC
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

IFNDEF _UIA_PatternIds_MODULE_DEFINED_
    _UIA_PatternIds_MODULE_DEFINED_ EQU 1

    UIA_InvokePatternId                         EQU     10000
    UIA_SelectionPatternId                      EQU     10001
    UIA_ValuePatternId                          EQU     10002
    UIA_RangeValuePatternId                     EQU     10003
    UIA_ScrollPatternId                         EQU     10004
    UIA_ExpandCollapsePatternId                 EQU     10005
    UIA_GridPatternId                           EQU     10006
    UIA_GridItemPatternId                       EQU     10007
    UIA_MultipleViewPatternId                   EQU     10008
    UIA_WindowPatternId                         EQU     10009
    UIA_SelectionItemPatternId                  EQU     10010
    UIA_DockPatternId                           EQU     10011
    UIA_TablePatternId                          EQU     10012
    UIA_TableItemPatternId                      EQU     10013
    UIA_TextPatternId                           EQU     10014
    UIA_TogglePatternId                         EQU     10015
    UIA_TransformPatternId                      EQU     10016
    UIA_ScrollItemPatternId                     EQU     10017
    UIA_LegacyIAccessiblePatternId              EQU     10018
    UIA_ItemContainerPatternId                  EQU     10019
    UIA_VirtualizedItemPatternId                EQU     10020
    UIA_SynchronizedInputPatternId              EQU     10021
    UIA_ObjectModelPatternId                    EQU     10022
    UIA_AnnotationPatternId                     EQU     10023
    UIA_TextPattern2Id                          EQU     10024
    UIA_StylesPatternId                         EQU     10025
    UIA_SpreadsheetPatternId                    EQU     10026
    UIA_SpreadsheetItemPatternId                EQU     10027
    UIA_TransformPattern2Id                     EQU     10028
    UIA_TextChildPatternId                      EQU     10029
    UIA_DragPatternId                           EQU     10030
    UIA_DropTargetPatternId                     EQU     10031
    UIA_TextEditPatternId                       EQU     10032
    UIA_CustomNavigationPatternId               EQU     10033
ENDIF ;_UIA_PatternIds_MODULE_DEFINED_

IFNDEF _UIA_EventIds_MODULE_DEFINED_
    _UIA_EventIds_MODULE_DEFINED_   EQU 1

    UIA_ToolTipOpenedEventId                    EQU     20000
    UIA_ToolTipClosedEventId                    EQU     20001
    UIA_StructureChangedEventId                 EQU     20002
    UIA_MenuOpenedEventId                       EQU     20003
    UIA_AutomationPropertyChangedEventId        EQU     20004
    UIA_AutomationFocusChangedEventId           EQU     20005
    UIA_AsyncContentLoadedEventId               EQU     20006
    UIA_MenuClosedEventId                       EQU     20007
    UIA_LayoutInvalidatedEventId                EQU     20008
    UIA_Invoke_InvokedEventId                   EQU     20009
    UIA_SelectionItem_ElementAddedToSelectionEventId EQU     20010
    UIA_SelectionItem_ElementRemovedFromSelectionEventId EQU 20011
    UIA_SelectionItem_ElementSelectedEventId    EQU     20012
    UIA_Selection_InvalidatedEventId            EQU     20013
    UIA_Text_TextSelectionChangedEventId        EQU     20014
    UIA_Text_TextChangedEventId                 EQU     20015
    UIA_Window_WindowOpenedEventId              EQU     20016
    UIA_Window_WindowClosedEventId              EQU     20017
    UIA_MenuModeStartEventId                    EQU     20018
    UIA_MenuModeEndEventId                      EQU     20019
    UIA_InputReachedTargetEventId               EQU     20020
    UIA_InputReachedOtherElementEventId         EQU     20021
    UIA_InputDiscardedEventId                   EQU     20022
    UIA_SystemAlertEventId                      EQU     20023
    UIA_LiveRegionChangedEventId                EQU     20024
    UIA_HostedFragmentRootsInvalidatedEventId   EQU     20025
    UIA_Drag_DragStartEventId                   EQU     20026
    UIA_Drag_DragCancelEventId                  EQU     20027
    UIA_Drag_DragCompleteEventId                EQU     20028
    UIA_DropTarget_DragEnterEventId             EQU     20029
    UIA_DropTarget_DragLeaveEventId             EQU     20030
    UIA_DropTarget_DroppedEventId               EQU     20031
    UIA_TextEdit_TextChangedEventId             EQU     20032
    UIA_TextEdit_ConversionTargetChangedEventId EQU     20033
ENDIF ;_UIA_EventIds_MODULE_DEFINED_

IFNDEF _UIA_PropertyIds_MODULE_DEFINED_
    _UIA_PropertyIds_MODULE_DEFINED_    EQU 1

    UIA_RuntimeIdPropertyId                     EQU     30000
    UIA_BoundingRectanglePropertyId             EQU     30001
    UIA_ProcessIdPropertyId                     EQU     30002
    UIA_ControlTypePropertyId                   EQU     30003
    UIA_LocalizedControlTypePropertyId          EQU     30004
    UIA_NamePropertyId                          EQU     30005
    UIA_AcceleratorKeyPropertyId                EQU     30006
    UIA_AccessKeyPropertyId                     EQU     30007
    UIA_HasKeyboardFocusPropertyId              EQU     30008
    UIA_IsKeyboardFocusablePropertyId           EQU     30009
    UIA_IsEnabledPropertyId                     EQU     30010
    UIA_AutomationIdPropertyId                  EQU     30011
    UIA_ClassNamePropertyId                     EQU     30012
    UIA_HelpTextPropertyId                      EQU     30013
    UIA_ClickablePointPropertyId                EQU     30014
    UIA_CulturePropertyId                       EQU     30015
    UIA_IsControlElementPropertyId              EQU     30016
    UIA_IsContentElementPropertyId              EQU     30017
    UIA_LabeledByPropertyId                     EQU     30018
    UIA_IsPasswordPropertyId                    EQU     30019
    UIA_NativeWindowHandlePropertyId            EQU     30020
    UIA_ItemTypePropertyId                      EQU     30021
    UIA_IsOffscreenPropertyId                   EQU     30022
    UIA_OrientationPropertyId                   EQU     30023
    UIA_FrameworkIdPropertyId                   EQU     30024
    UIA_IsRequiredForFormPropertyId             EQU     30025
    UIA_ItemStatusPropertyId                    EQU     30026
    UIA_IsDockPatternAvailablePropertyId        EQU     30027
    UIA_IsExpandCollapsePatternAvailablePropertyId EQU  30028
    UIA_IsGridItemPatternAvailablePropertyId    EQU     30029
    UIA_IsGridPatternAvailablePropertyId        EQU     30030
    UIA_IsInvokePatternAvailablePropertyId      EQU     30031
    UIA_IsMultipleViewPatternAvailablePropertyId EQU    30032
    UIA_IsRangeValuePatternAvailablePropertyId  EQU     30033
    UIA_IsScrollPatternAvailablePropertyId      EQU     30034
    UIA_IsScrollItemPatternAvailablePropertyId  EQU     30035
    UIA_IsSelectionItemPatternAvailablePropertyId EQU   30036
    UIA_IsSelectionPatternAvailablePropertyId   EQU     30037
    UIA_IsTablePatternAvailablePropertyId       EQU     30038
    UIA_IsTableItemPatternAvailablePropertyId   EQU     30039
    UIA_IsTextPatternAvailablePropertyId        EQU     30040
    UIA_IsTogglePatternAvailablePropertyId      EQU     30041
    UIA_IsTransformPatternAvailablePropertyId   EQU     30042
    UIA_IsValuePatternAvailablePropertyId       EQU     30043
    UIA_IsWindowPatternAvailablePropertyId      EQU     30044
    UIA_ValueValuePropertyId                    EQU     30045
    UIA_ValueIsReadOnlyPropertyId               EQU     30046
    UIA_RangeValueValuePropertyId               EQU     30047
    UIA_RangeValueIsReadOnlyPropertyId          EQU     30048
    UIA_RangeValueMinimumPropertyId             EQU     30049
    UIA_RangeValueMaximumPropertyId             EQU     30050
    UIA_RangeValueLargeChangePropertyId         EQU     30051
    UIA_RangeValueSmallChangePropertyId         EQU     30052
    UIA_ScrollHorizontalScrollPercentPropertyId EQU     30053
    UIA_ScrollHorizontalViewSizePropertyId      EQU     30054
    UIA_ScrollVerticalScrollPercentPropertyId   EQU     30055
    UIA_ScrollVerticalViewSizePropertyId        EQU     30056
    UIA_ScrollHorizontallyScrollablePropertyId  EQU     30057
    UIA_ScrollVerticallyScrollablePropertyId    EQU     30058
    UIA_SelectionSelectionPropertyId            EQU     30059
    UIA_SelectionCanSelectMultiplePropertyId    EQU     30060
    UIA_SelectionIsSelectionRequiredPropertyId  EQU     30061
    UIA_GridRowCountPropertyId                  EQU     30062
    UIA_GridColumnCountPropertyId               EQU     30063
    UIA_GridItemRowPropertyId                   EQU     30064
    UIA_GridItemColumnPropertyId                EQU     30065
    UIA_GridItemRowSpanPropertyId               EQU     30066
    UIA_GridItemColumnSpanPropertyId            EQU     30067
    UIA_GridItemContainingGridPropertyId        EQU     30068
    UIA_DockDockPositionPropertyId              EQU     30069
    UIA_ExpandCollapseExpandCollapseStatePropertyId EQU 30070
    UIA_MultipleViewCurrentViewPropertyId       EQU     30071
    UIA_MultipleViewSupportedViewsPropertyId    EQU     30072
    UIA_WindowCanMaximizePropertyId             EQU     30073
    UIA_WindowCanMinimizePropertyId             EQU     30074
    UIA_WindowWindowVisualStatePropertyId       EQU     30075
    UIA_WindowWindowInteractionStatePropertyId  EQU     30076
    UIA_WindowIsModalPropertyId                 EQU     30077
    UIA_WindowIsTopmostPropertyId               EQU     30078
    UIA_SelectionItemIsSelectedPropertyId       EQU     30079
    UIA_SelectionItemSelectionContainerPropertyId EQU   30080
    UIA_TableRowHeadersPropertyId               EQU     30081
    UIA_TableColumnHeadersPropertyId            EQU     30082
    UIA_TableRowOrColumnMajorPropertyId         EQU     30083
    UIA_TableItemRowHeaderItemsPropertyId       EQU     30084
    UIA_TableItemColumnHeaderItemsPropertyId    EQU     30085
    UIA_ToggleToggleStatePropertyId             EQU     30086
    UIA_TransformCanMovePropertyId              EQU     30087
    UIA_TransformCanResizePropertyId            EQU     30088
    UIA_TransformCanRotatePropertyId            EQU     30089
    UIA_IsLegacyIAccessiblePatternAvailablePropertyId EQU 30090
    UIA_LegacyIAccessibleChildIdPropertyId      EQU     30091
    UIA_LegacyIAccessibleNamePropertyId         EQU     30092
    UIA_LegacyIAccessibleValuePropertyId        EQU     30093
    UIA_LegacyIAccessibleDescriptionPropertyId  EQU     30094
    UIA_LegacyIAccessibleRolePropertyId         EQU     30095
    UIA_LegacyIAccessibleStatePropertyId        EQU     30096
    UIA_LegacyIAccessibleHelpPropertyId         EQU     30097
    UIA_LegacyIAccessibleKeyboardShortcutPropertyId EQU 30098
    UIA_LegacyIAccessibleSelectionPropertyId    EQU     30099
    UIA_LegacyIAccessibleDefaultActionPropertyId EQU    30100
    UIA_AriaRolePropertyId                      EQU     30101
    UIA_AriaPropertiesPropertyId                EQU     30102
    UIA_IsDataValidForFormPropertyId            EQU     30103
    UIA_ControllerForPropertyId                 EQU     30104
    UIA_DescribedByPropertyId                   EQU     30105
    UIA_FlowsToPropertyId                       EQU     30106
    UIA_ProviderDescriptionPropertyId           EQU     30107
    UIA_IsItemContainerPatternAvailablePropertyId EQU   30108
    UIA_IsVirtualizedItemPatternAvailablePropertyId EQU 30109
    UIA_IsSynchronizedInputPatternAvailablePropertyId EQU 30110
    UIA_OptimizeForVisualContentPropertyId      EQU     30111
    UIA_IsObjectModelPatternAvailablePropertyId EQU     30112
    UIA_AnnotationAnnotationTypeIdPropertyId    EQU     30113
    UIA_AnnotationAnnotationTypeNamePropertyId  EQU     30114
    UIA_AnnotationAuthorPropertyId              EQU     30115
    UIA_AnnotationDateTimePropertyId            EQU     30116
    UIA_AnnotationTargetPropertyId              EQU     30117
    UIA_IsAnnotationPatternAvailablePropertyId  EQU     30118
    UIA_IsTextPattern2AvailablePropertyId       EQU     30119
    UIA_StylesStyleIdPropertyId                 EQU     30120
    UIA_StylesStyleNamePropertyId               EQU     30121
    UIA_StylesFillColorPropertyId               EQU     30122
    UIA_StylesFillPatternStylePropertyId        EQU     30123
    UIA_StylesShapePropertyId                   EQU     30124
    UIA_StylesFillPatternColorPropertyId        EQU     30125
    UIA_StylesExtendedPropertiesPropertyId      EQU     30126
    UIA_IsStylesPatternAvailablePropertyId      EQU     30127
    UIA_IsSpreadsheetPatternAvailablePropertyId EQU     30128
    UIA_SpreadsheetItemFormulaPropertyId        EQU     30129
    UIA_SpreadsheetItemAnnotationObjectsPropertyId EQU  30130
    UIA_SpreadsheetItemAnnotationTypesPropertyId EQU    30131
    UIA_IsSpreadsheetItemPatternAvailablePropertyId EQU 30132
    UIA_Transform2CanZoomPropertyId             EQU     30133
    UIA_IsTransformPattern2AvailablePropertyId  EQU     30134
    UIA_LiveSettingPropertyId                   EQU     30135
    UIA_IsTextChildPatternAvailablePropertyId   EQU     30136
    UIA_IsDragPatternAvailablePropertyId        EQU     30137
    UIA_DragIsGrabbedPropertyId                 EQU     30138
    UIA_DragDropEffectPropertyId                EQU     30139
    UIA_DragDropEffectsPropertyId               EQU     30140
    UIA_IsDropTargetPatternAvailablePropertyId  EQU     30141
    UIA_DropTargetDropTargetEffectPropertyId    EQU     30142
    UIA_DropTargetDropTargetEffectsPropertyId   EQU     30143
    UIA_DragGrabbedItemsPropertyId              EQU     30144
    UIA_Transform2ZoomLevelPropertyId           EQU     30145
    UIA_Transform2ZoomMinimumPropertyId         EQU     30146
    UIA_Transform2ZoomMaximumPropertyId         EQU     30147
    UIA_FlowsFromPropertyId                     EQU     30148
    UIA_IsTextEditPatternAvailablePropertyId    EQU     30149
    UIA_IsPeripheralPropertyId                  EQU     30150
    UIA_IsCustomNavigationPatternAvailablePropertyId EQU 30151
    UIA_PositionInSetPropertyId                 EQU     30152
    UIA_SizeOfSetPropertyId                     EQU     30153
    UIA_LevelPropertyId                         EQU     30154
    UIA_AnnotationTypesPropertyId               EQU     30155
    UIA_AnnotationObjectsPropertyId             EQU     30156
    UIA_LandmarkTypePropertyId                  EQU     30157
    UIA_LocalizedLandmarkTypePropertyId         EQU     30158
    UIA_FullDescriptionPropertyId               EQU     30159
ENDIF ;_UIA_PropertyIds_MODULE_DEFINED_

IFNDEF _UIA_TextAttributeIds_MODULE_DEFINED_
    _UIA_TextAttributeIds_MODULE_DEFINED_   EQU 1

    UIA_AnimationStyleAttributeId               EQU     40000
    UIA_BackgroundColorAttributeId              EQU     40001
    UIA_BulletStyleAttributeId                  EQU     40002
    UIA_CapStyleAttributeId                     EQU     40003
    UIA_CultureAttributeId                      EQU     40004
    UIA_FontNameAttributeId                     EQU     40005
    UIA_FontSizeAttributeId                     EQU     40006
    UIA_FontWeightAttributeId                   EQU     40007
    UIA_ForegroundColorAttributeId              EQU     40008
    UIA_HorizontalTextAlignmentAttributeId      EQU     40009
    UIA_IndentationFirstLineAttributeId         EQU     40010
    UIA_IndentationLeadingAttributeId           EQU     40011
    UIA_IndentationTrailingAttributeId          EQU     40012
    UIA_IsHiddenAttributeId                     EQU     40013
    UIA_IsItalicAttributeId                     EQU     40014
    UIA_IsReadOnlyAttributeId                   EQU     40015
    UIA_IsSubscriptAttributeId                  EQU     40016
    UIA_IsSuperscriptAttributeId                EQU     40017
    UIA_MarginBottomAttributeId                 EQU     40018
    UIA_MarginLeadingAttributeId                EQU     40019
    UIA_MarginTopAttributeId                    EQU     40020
    UIA_MarginTrailingAttributeId               EQU     40021
    UIA_OutlineStylesAttributeId                EQU     40022
    UIA_OverlineColorAttributeId                EQU     40023
    UIA_OverlineStyleAttributeId                EQU     40024
    UIA_StrikethroughColorAttributeId           EQU     40025
    UIA_StrikethroughStyleAttributeId           EQU     40026
    UIA_TabsAttributeId                         EQU     40027
    UIA_TextFlowDirectionsAttributeId           EQU     40028
    UIA_UnderlineColorAttributeId               EQU     40029
    UIA_UnderlineStyleAttributeId               EQU     40030
    UIA_AnnotationTypesAttributeId              EQU     40031
    UIA_AnnotationObjectsAttributeId            EQU     40032
    UIA_StyleNameAttributeId                    EQU     40033
    UIA_StyleIdAttributeId                      EQU     40034
    UIA_LinkAttributeId                         EQU     40035
    UIA_IsActiveAttributeId                     EQU     40036
    UIA_SelectionActiveEndAttributeId           EQU     40037
    UIA_CaretPositionAttributeId                EQU     40038
    UIA_CaretBidiModeAttributeId                EQU     40039
ENDIF ;_UIA_TextAttributeIds_MODULE_DEFINED_

IFNDEF _UIA_ControlTypeIds_MODULE_DEFINED_
    _UIA_ControlTypeIds_MODULE_DEFINED_ EQU 1

    UIA_ButtonControlTypeId                     EQU     50000
    UIA_CalendarControlTypeId                   EQU     50001
    UIA_CheckBoxControlTypeId                   EQU     50002
    UIA_ComboBoxControlTypeId                   EQU     50003
    UIA_EditControlTypeId                       EQU     50004
    UIA_HyperlinkControlTypeId                  EQU     50005
    UIA_ImageControlTypeId                      EQU     50006
    UIA_ListItemControlTypeId                   EQU     50007
    UIA_ListControlTypeId                       EQU     50008
    UIA_MenuControlTypeId                       EQU     50009
    UIA_MenuBarControlTypeId                    EQU     50010
    UIA_MenuItemControlTypeId                   EQU     50011
    UIA_ProgressBarControlTypeId                EQU     50012
    UIA_RadioButtonControlTypeId                EQU     50013
    UIA_ScrollBarControlTypeId                  EQU     50014
    UIA_SliderControlTypeId                     EQU     50015
    UIA_SpinnerControlTypeId                    EQU     50016
    UIA_StatusBarControlTypeId                  EQU     50017
    UIA_TabControlTypeId                        EQU     50018
    UIA_TabItemControlTypeId                    EQU     50019
    UIA_TextControlTypeId                       EQU     50020
    UIA_ToolBarControlTypeId                    EQU     50021
    UIA_ToolTipControlTypeId                    EQU     50022
    UIA_TreeControlTypeId                       EQU     50023
    UIA_TreeItemControlTypeId                   EQU     50024
    UIA_CustomControlTypeId                     EQU     50025
    UIA_GroupControlTypeId                      EQU     50026
    UIA_ThumbControlTypeId                      EQU     50027
    UIA_DataGridControlTypeId                   EQU     50028
    UIA_DataItemControlTypeId                   EQU     50029
    UIA_DocumentControlTypeId                   EQU     50030
    UIA_SplitButtonControlTypeId                EQU     50031
    UIA_WindowControlTypeId                     EQU     50032
    UIA_PaneControlTypeId                       EQU     50033
    UIA_HeaderControlTypeId                     EQU     50034
    UIA_HeaderItemControlTypeId                 EQU     50035
    UIA_TableControlTypeId                      EQU     50036
    UIA_TitleBarControlTypeId                   EQU     50037
    UIA_SeparatorControlTypeId                  EQU     50038
    UIA_SemanticZoomControlTypeId               EQU     50039
    UIA_AppBarControlTypeId                     EQU     50040
ENDIF ;_UIA_ControlTypeIds_MODULE_DEFINED_

IFNDEF _UIA_AnnotationTypes_MODULE_DEFINED_
    _UIA_AnnotationTypes_MODULE_DEFINED_    EQU 1

    AnnotationType_Unknown                      EQU     60000
    AnnotationType_SpellingError                EQU     60001
    AnnotationType_GrammarError                 EQU     60002
    AnnotationType_Comment                      EQU     60003
    AnnotationType_FormulaError                 EQU     60004
    AnnotationType_TrackChanges                 EQU     60005
    AnnotationType_Header                       EQU     60006
    AnnotationType_Footer                       EQU     60007
    AnnotationType_Highlighted                  EQU     60008
    AnnotationType_Endnote                      EQU     60009
    AnnotationType_Footnote                     EQU     60010
    AnnotationType_InsertionChange              EQU     60011
    AnnotationType_DeletionChange               EQU     60012
    AnnotationType_MoveChange                   EQU     60013
    AnnotationType_FormatChange                 EQU     60014
    AnnotationType_UnsyncedChange               EQU     60015
    AnnotationType_EditingLockedChange          EQU     60016
    AnnotationType_ExternalChange               EQU     60017
    AnnotationType_ConflictingChange            EQU     60018
    AnnotationType_Author                       EQU     60019
    AnnotationType_AdvancedProofingIssue        EQU     60020
    AnnotationType_DataValidationError          EQU     60021
    AnnotationType_CircularReferenceError       EQU     60022
ENDIF ;_UIA_AnnotationTypes_MODULE_DEFINED_

IFNDEF _UIA_StyleIds_MODULE_DEFINED_
    _UIA_StyleIds_MODULE_DEFINED_   EQU 1

    StyleId_Custom                              EQU     70000
    StyleId_Heading1                            EQU     70001
    StyleId_Heading2                            EQU     70002
    StyleId_Heading3                            EQU     70003
    StyleId_Heading4                            EQU     70004
    StyleId_Heading5                            EQU     70005
    StyleId_Heading6                            EQU     70006
    StyleId_Heading7                            EQU     70007
    StyleId_Heading8                            EQU     70008
    StyleId_Heading9                            EQU     70009
    StyleId_Title                               EQU     70010
    StyleId_Subtitle                            EQU     70011
    StyleId_Normal                              EQU     70012
    StyleId_Emphasis                            EQU     70013
    StyleId_Quote                               EQU     70014
    StyleId_BulletedList                        EQU     70015
    StyleId_NumberedList                        EQU     70016
ENDIF ;_UIA_StyleIds_MODULE_DEFINED_

IFNDEF _UIA_LandmarkTypeIds_MODULE_DEFINED_
    _UIA_LandmarkTypeIds_MODULE_DEFINED_    EQU 1

    UIA_CustomLandmarkTypeId                    EQU     80000
    UIA_FormLandmarkTypeId                      EQU     80001
    UIA_MainLandmarkTypeId                      EQU     80002
    UIA_NavigationLandmarkTypeId                EQU     80003
    UIA_SearchLandmarkTypeId                    EQU     80004
ENDIF ;_UIA_LandmarkTypeIds_MODULE_DEFINED_

IFNDEF _UIA_ChangeIds_MODULE_DEFINED_
    _UIA_ChangeIds_MODULE_DEFINED_  EQU 1

    UIA_SummaryChangeId                         EQU     90000
ENDIF ;_UIA_ChangeIds_MODULE_DEFINED_

ExtendedProperty STRUCT ALIGNMODE
    PropertyName  XWORD ?
    PropertyValue XWORD ?
ExtendedProperty ENDS

IUIAutomationVtbl STRUCT ALIGNMODE
    QueryInterface                              XWORD ?
    AddRef                                      XWORD ?
    Release                                     XWORD ?
    CompareElements                             XWORD ?
    CompareRuntimeIds                           XWORD ?
    GetRootElement                              XWORD ?
    ElementFromHandle                           XWORD ?
    ElementFromPoint                            XWORD ?
    GetFocusedElement                           XWORD ?
    GetRootElementBuildCache                    XWORD ?
    ElementFromHandleBuildCache                 XWORD ?
    ElementFromPointBuildCache                  XWORD ?
    GetFocusedElementBuildCache                 XWORD ?
    CreateTreeWalker                            XWORD ?
    get_ControlViewWalker                       XWORD ?
    get_ContentViewWalker                       XWORD ?
    get_RawViewWalker                           XWORD ?
    get_RawViewCondition                        XWORD ?
    get_ControlViewCondition                    XWORD ?
    get_ContentViewCondition                    XWORD ?
    CreateCacheRequest                          XWORD ?
    CreateTrueCondition                         XWORD ?
    CreateFalseCondition                        XWORD ?
    CreatePropertyCondition                     XWORD ?
    CreatePropertyConditionEx                   XWORD ?
    CreateAndCondition                          XWORD ?
    CreateAndConditionFromArray                 XWORD ?
    CreateAndConditionFromNativeArray           XWORD ?
    CreateOrCondition                           XWORD ?
    CreateOrConditionFromArray                  XWORD ?
    CreateOrConditionFromNativeArray            XWORD ?
    CreateNotCondition                          XWORD ?
    AddAutomationEventHandler                   XWORD ?
    RemoveAutomationEventHandler                XWORD ?
    AddPropertyChangedEventHandlerNativeArray   XWORD ?
    AddPropertyChangedEventHandler              XWORD ?
    RemovePropertyChangedEventHandler           XWORD ?
    AddStructureChangedEventHandler             XWORD ?
    RemoveStructureChangedEventHandler          XWORD ?
    AddFocusChangedEventHandler                 XWORD ?
    RemoveFocusChangedEventHandler              XWORD ?
    RemoveAllEventHandlers                      XWORD ?
    IntNativeArrayToSafeArray                   XWORD ?
    IntSafeArrayToNativeArray                   XWORD ?
    RectToVariant                               XWORD ?
    VariantToRect                               XWORD ?
    SafeArrayToRectNativeArray                  XWORD ?
    CreateProxyFactoryEntry                     XWORD ?
    Get_ProxyFactoryMapping                     XWORD ?
    GetPropertyProgrammaticName                 XWORD ?
    GetPatternProgrammaticName                  XWORD ?
    PollForPotentialSupportedPatterns           XWORD ?
    PollForPotentialSupportedProperties         XWORD ?
    CheckNotSupported                           XWORD ?
    Get_ReservedNotSupportedValue               XWORD ?
    Get_ReservedMixedAttributeValue             XWORD ?
    ElementFromIAccessible                      XWORD ?
    ElementFromIAccessibleBuildCache            XWORD ?
IUIAutomationVtbl ENDS

IUIAutomationElementVtbl STRUCT ALIGNMODE
    QueryInterface                              XWORD ?
    AddRef                                      XWORD ?
    Release                                     XWORD ?
    SetFocus                                    XWORD ?
    GetRuntimeId                                XWORD ?
    FindFirst                                   XWORD ?
    FindAll                                     XWORD ?
    FindFirstBuildCache                         XWORD ?
    FindAllBuildCache                           XWORD ?
    BuildUpdatedCache                           XWORD ?
    GetCurrentPropertyValue                     XWORD ?
    GetCurrentPropertyValueEx                   XWORD ?
    GetCachedPropertyValue                      XWORD ?
    GetCachedPropertyValueEx                    XWORD ?
    GetCurrentPatternAs                         XWORD ?
    GetCachedPatternAs                          XWORD ?
    GetCurrentPattern                           XWORD ?
    GetCachedPattern                            XWORD ?
    GetCachedParent                             XWORD ?
    GetCachedChildren                           XWORD ?
    Get_CurrentProcessId                        XWORD ?
    Get_CurrentControlType                      XWORD ?
    Get_CurrentLocalizedControlType             XWORD ?
    Get_CurrentName                             XWORD ?
    Get_CurrentAcceleratorKey                   XWORD ?
    Get_CurrentAccessKey                        XWORD ?
    Get_CurrentHasKeyboardFocus                 XWORD ?
    Get_CurrentIsKeyboardFocusable              XWORD ?
    Get_CurrentIsEnabled                        XWORD ?
    Get_CurrentAutomationId                     XWORD ?
    Get_CurrentClassName                        XWORD ?
    Get_CurrentHelpText                         XWORD ?
    Get_CurrentCulture                          XWORD ?
    Get_CurrentIsControlElement                 XWORD ?
    Get_CurrentIsContentElement                 XWORD ?
    Get_CurrentIsPassword                       XWORD ?
    Get_CurrentNativeWindowHandle               XWORD ?
    Get_CurrentItemType                         XWORD ?
    Get_CurrentIsOffscreen                      XWORD ?
    Get_CurrentOrientation                      XWORD ?
    Get_CurrentFrameworkId                      XWORD ?
    Get_CurrentIsRequiredForForm                XWORD ?
    Get_CurrentItemStatus                       XWORD ?
    Get_CurrentBoundingRectangle                XWORD ?
    Get_CurrentLabeledBy                        XWORD ?
    Get_CurrentAriaRole                         XWORD ?
    Get_CurrentAriaProperties                   XWORD ?
    Get_CurrentIsDataValidForForm               XWORD ?
    Get_CurrentControllerFor                    XWORD ?
    Get_CurrentDescribedBy                      XWORD ?
    Get_CurrentFlowsTo                          XWORD ?
    Get_CurrentProviderDescription              XWORD ?
    Get_CachedProcessId                         XWORD ?
    Get_CachedControlType                       XWORD ?
    Get_CachedLocalizedControlType              XWORD ?
    Get_CachedName                              XWORD ?
    Get_CachedAcceleratorKey                    XWORD ?
    Get_CachedAccessKey                         XWORD ?
    Get_CachedHasKeyboardFocus                  XWORD ?
    Get_CachedIsKeyboardFocusable               XWORD ?
    Get_CachedIsEnabled                         XWORD ?
    Get_CachedAutomationId                      XWORD ?
    Get_CachedClassName                         XWORD ?
    Get_CachedHelpText                          XWORD ?
    Get_CachedCulture                           XWORD ?
    Get_CachedIsControlElement                  XWORD ?
    Get_CachedIsContentElement                  XWORD ?
    Get_CachedIsPassword                        XWORD ?
    Get_CachedNativeWindowHandle                XWORD ?
    Get_CachedItemType                          XWORD ?
    Get_CachedIsOffscreen                       XWORD ?
    Get_CachedOrientation                       XWORD ?
    Get_CachedFrameworkId                       XWORD ?
    Get_CachedIsRequiredForForm                 XWORD ?
    Get_CachedItemStatus                        XWORD ?
    Get_CachedBoundingRectangle                 XWORD ?
    Get_CachedLabeledBy                         XWORD ?
    Get_CachedAriaRole                          XWORD ?
    Get_CachedAriaProperties                    XWORD ?
    Get_CachedIsDataValidForForm                XWORD ?
    Get_CachedControllerFor                     XWORD ?
    Get_CachedDescribedBy                       XWORD ?
    Get_CachedFlowsTo                           XWORD ?
    Get_CachedProviderDescription               XWORD ?
    GetClickablePoint                           XWORD ?
IUIAutomationElementVtbl ENDS

IUIAutomationTreeWalkerVtbl STRUCT ALIGNMODE
    QueryInterface                              XWORD ?
    AddRef                                      XWORD ?
    Release                                     XWORD ?
    GetParentElement                            XWORD ?
    GetFirstChildElement                        XWORD ?
    GetLastChildElement                         XWORD ?
    GetNextSiblingElement                       XWORD ?
    GetPreviousSiblingElement                   XWORD ?
    NormalizeElement                            XWORD ?
    GetParentElementBuildCache                  XWORD ?
    GetFirstChildElementBuildCache              XWORD ?
    GetLastChildElementBuildCache               XWORD ?
    GetNextSiblingElementBuildCache             XWORD ?
    GetPreviousSiblingElementBuildCache         XWORD ?
    NormalizeElementBuildCache                  XWORD ?
    get_Condition                               XWORD ?
IUIAutomationTreeWalkerVtbl ENDS

IUIAutomationConditionVtbl STRUCT ALIGNMODE
    QueryInterface                              XWORD ?
    AddRef                                      XWORD ?
    Release                                     XWORD ?
                                                XWORD ?
                                                XWORD ?
                                                XWORD ?
                                                XWORD ?
IUIAutomationConditionVtbl ENDS

IUIAutomationElementArrayVtbl STRUCT ALIGNMODE
    QueryInterface                              XWORD ?
    AddRef                                      XWORD ?
    Release                                     XWORD ?
    get_Length                                  XWORD ?
    GetElement                                  XWORD ?
IUIAutomationElementArrayVtbl ENDS

IUIAutomationValuePatternVtbl STRUCT ALIGNMODE
    QueryInterface                              XWORD ?
    AddRef                                      XWORD ?
    Release                                     XWORD ?
    SetValue_                                   XWORD ?
    get_CurrentValue                            XWORD ?
    get_CurrentIsReadOnly                       XWORD ?
    get_CachedValue                             XWORD ?
    get_CachedIsReadOnly                        XWORD ?
IUIAutomationValuePatternVtbl ENDS

IUIAutomationSelectionItemPatternVtbl STRUCT ALIGNMODE
    QueryInterface                              QWord ?
    AddRef                                      QWord ?
    Release                                     QWord ?
    Select                                      QWord ?
    AddToSelection                              QWord ?
    RemoveFromSelection                         QWord ?
    get_CurrentIsSelected                       QWord ?
    get_CurrentSelectionContainer               QWord ?
    get_CachedIsSelected                        QWord ?
    get_CachedSelectionContainer                QWord ?
IUIAutomationSelectionItemPatternVtbl ENDS

IUIAutomationLegacyIAccessiblePatternVtbl STRUCT ALIGNMODE
    QueryInterface                              QWord ?
    AddRef                                      QWord ?
    Release                                     QWord ?
    Select                                      QWord ?
    DoDefaultAction                             QWord ?
    SetValue_                                   QWord ?
    get_CurrentChildId                          QWord ?
    get_CurrentName                             QWord ?
    get_CurrentValue                            QWord ?
    get_CurrentDescription                      QWord ?
    get_CurrentRole                             QWord ?
    get_CurrentState                            QWord ?
    get_CurrentHelp                             QWord ?
    get_CurrentKeyboardShortcut                 QWord ?
    GetCurrentSelection                         QWord ?
    get_CurrentDefaultAction                    QWord ?
    get_CachedChildId                           QWord ?
    get_CachedName                              QWord ?
    get_CachedValue                             QWord ?
    get_CachedDescription                       QWord ?
    get_CachedRole                              QWord ?
    get_CachedState                             QWord ?
    get_CachedHelp                              QWord ?
    get_CachedKeyboardShortcut                  QWord ?
    GetCachedSelection                          QWord ?
    get_CachedDefaultAction                     QWord ?
    GetIAccessible                              QWord ?
IUIAutomationLegacyIAccessiblePatternVtbl ENDS

IUIAutomationInvokePatternVtbl STRUCT ALIGNMODE
    QueryInterface                              QWord ?
    AddRef                                      QWord ?
    Release                                     QWord ?
    Invoke_                                     QWord ?
IUIAutomationInvokePatternVtbl ENDS

ISelectionItemProviderVtbl STRUCT ALIGNMODE
    QueryInterface                              QWord ?
    AddRef                                      QWord ?
    Release                                     QWord ?
    Select                                      QWord ?
    AddToSelection                              QWord ?
    RemoveFromSelection                         QWord ?
    get_IsSelected                              QWord ?
    get_SelectionContainer                      QWord ?
ISelectionItemProviderVtbl ENDS

IFNDEF _IUIAutomationElement_INTERFACE_DEFINED_
    _IUIAutomationElement_INTERFACE_DEFINED_    EQU 1

    IUIAutomationElement_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XPTR
    FIUIAutomationElement_QueryInterface TYPEDEF PTR IUIAutomationElement_QueryInterface

    IUIAutomationElement_GetRuntimeId TYPEDEF PROTO :XWORD, runtimeId:XWORD
    FIUIAutomationElement_GetRuntimeId TYPEDEF PTR IUIAutomationElement_GetRuntimeId

    IUIAutomationElement_FindFirst TYPEDEF PROTO :XWORD, scope:XWORD, condition:XWORD, found:XWORD
    FIUIAutomationElement_FindFirst TYPEDEF PTR IUIAutomationElement_FindFirst

    IUIAutomationElement_FindAll TYPEDEF PROTO :XWORD, scope:XWORD, condition:XWORD, found:XWORD
    FIUIAutomationElement_FindAll TYPEDEF PTR IUIAutomationElement_FindAll

    IUIAutomationElement_FindFirstBuildCache TYPEDEF PROTO :XWORD, scope:XWORD, condition:XWORD, cacheRequest:XWORD, found:XWORD
    FIUIAutomationElement_FindFirstBuildCache TYPEDEF PTR IUIAutomationElement_FindFirstBuildCache

    IUIAutomationElement_FindAllBuildCache TYPEDEF PROTO :XWORD, scope:XWORD, condition:XWORD, cacheRequest:XWORD, found:XWORD
    FIUIAutomationElement_FindAllBuildCache TYPEDEF PTR IUIAutomationElement_FindAllBuildCache

    IUIAutomationElement_BuildUpdatedCache TYPEDEF PROTO :XWORD, cacheRequest:XWORD, updatedElement:XWORD
    FIUIAutomationElement_BuildUpdatedCache TYPEDEF PTR IUIAutomationElement_BuildUpdatedCache

    IUIAutomationElement_GetCurrentPropertyValue TYPEDEF PROTO :XWORD, propertyId:XWORD, retVal:XWORD
    FIUIAutomationElement_GetCurrentPropertyValue TYPEDEF PTR IUIAutomationElement_GetCurrentPropertyValue

    IUIAutomationElement_GetCurrentPropertyValueEx TYPEDEF PROTO :XWORD, propertyId:XWORD, ignoreDefaultValue:XWORD, retVal:XWORD
    FIUIAutomationElement_GetCurrentPropertyValueEx TYPEDEF PTR IUIAutomationElement_GetCurrentPropertyValueEx

    IUIAutomationElement_GetCachedPropertyValue TYPEDEF PROTO :XWORD, propertyId:XWORD, retVal:XWORD
    FIUIAutomationElement_GetCachedPropertyValue TYPEDEF PTR IUIAutomationElement_GetCachedPropertyValue

    IUIAutomationElement_GetCachedPropertyValueEx TYPEDEF PROTO :XWORD, propertyId:XWORD, ignoreDefaultValue:XWORD, retVal:XWORD
    FIUIAutomationElement_GetCachedPropertyValueEx TYPEDEF PTR IUIAutomationElement_GetCachedPropertyValueEx

    IUIAutomationElement_GetCurrentPatternAs TYPEDEF PROTO :XWORD, patternId:XWORD, riid:XWORD, patternObject:XWORD
    FIUIAutomationElement_GetCurrentPatternAs TYPEDEF PTR IUIAutomationElement_GetCurrentPatternAs

    IUIAutomationElement_GetCachedPatternAs TYPEDEF PROTO :XWORD, patternId:XWORD, riid:XWORD, patternObject:XWORD
    FIUIAutomationElement_GetCachedPatternAs TYPEDEF PTR IUIAutomationElement_GetCachedPatternAs

    IUIAutomationElement_GetCurrentPattern TYPEDEF PROTO :XWORD, patternId:XWORD, patternObject:XWORD
    FIUIAutomationElement_GetCurrentPattern TYPEDEF PTR IUIAutomationElement_GetCurrentPattern

    IUIAutomationElement_GetCachedPattern TYPEDEF PROTO :XWORD, patternId:XWORD, patternObject:XWORD
    FIUIAutomationElement_GetCachedPattern TYPEDEF PTR IUIAutomationElement_GetCachedPattern

    IUIAutomationElement_GetCachedParent TYPEDEF PROTO :XWORD, parent:XWORD
    FIUIAutomationElement_GetCachedParent TYPEDEF PTR IUIAutomationElement_GetCachedParent

    IUIAutomationElement_GetCachedChildren TYPEDEF PROTO :XWORD, children:XWORD
    FIUIAutomationElement_GetCachedChildren TYPEDEF PTR IUIAutomationElement_GetCachedChildren

    IUIAutomationElement_get_CurrentProcessId TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CurrentProcessId TYPEDEF PTR IUIAutomationElement_get_CurrentProcessId

    IUIAutomationElement_get_CurrentControlType TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CurrentControlType TYPEDEF PTR IUIAutomationElement_get_CurrentControlType

    IUIAutomationElement_get_CurrentLocalizedControlType TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CurrentLocalizedControlType TYPEDEF PTR IUIAutomationElement_get_CurrentLocalizedControlType

    IUIAutomationElement_get_CurrentName TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CurrentName TYPEDEF PTR IUIAutomationElement_get_CurrentName

    IUIAutomationElement_get_CurrentAcceleratorKey TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CurrentAcceleratorKey TYPEDEF PTR IUIAutomationElement_get_CurrentAcceleratorKey

    IUIAutomationElement_get_CurrentAccessKey TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CurrentAccessKey TYPEDEF PTR IUIAutomationElement_get_CurrentAccessKey

    IUIAutomationElement_get_CurrentHasKeyboardFocus TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CurrentHasKeyboardFocus TYPEDEF PTR IUIAutomationElement_get_CurrentHasKeyboardFocus

    IUIAutomationElement_get_CurrentIsKeyboardFocusable TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CurrentIsKeyboardFocusable TYPEDEF PTR IUIAutomationElement_get_CurrentIsKeyboardFocusable

    IUIAutomationElement_get_CurrentIsEnabled TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CurrentIsEnabled TYPEDEF PTR IUIAutomationElement_get_CurrentIsEnabled

    IUIAutomationElement_get_CurrentAutomationId TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CurrentAutomationId TYPEDEF PTR IUIAutomationElement_get_CurrentAutomationId

    IUIAutomationElement_get_CurrentClassName TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CurrentClassName TYPEDEF PTR IUIAutomationElement_get_CurrentClassName

    IUIAutomationElement_get_CurrentHelpText TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CurrentHelpText TYPEDEF PTR IUIAutomationElement_get_CurrentHelpText

    IUIAutomationElement_get_CurrentCulture TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CurrentCulture TYPEDEF PTR IUIAutomationElement_get_CurrentCulture

    IUIAutomationElement_get_CurrentIsControlElement TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CurrentIsControlElement TYPEDEF PTR IUIAutomationElement_get_CurrentIsControlElement

    IUIAutomationElement_get_CurrentIsContentElement TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CurrentIsContentElement TYPEDEF PTR IUIAutomationElement_get_CurrentIsContentElement

    IUIAutomationElement_get_CurrentIsPassword TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CurrentIsPassword TYPEDEF PTR IUIAutomationElement_get_CurrentIsPassword

    IUIAutomationElement_get_CurrentNativeWindowHandle TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CurrentNativeWindowHandle TYPEDEF PTR IUIAutomationElement_get_CurrentNativeWindowHandle

    IUIAutomationElement_get_CurrentItemType TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CurrentItemType TYPEDEF PTR IUIAutomationElement_get_CurrentItemType

    IUIAutomationElement_get_CurrentIsOffscreen TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CurrentIsOffscreen TYPEDEF PTR IUIAutomationElement_get_CurrentIsOffscreen

    IUIAutomationElement_get_CurrentOrientation TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CurrentOrientation TYPEDEF PTR IUIAutomationElement_get_CurrentOrientation

    IUIAutomationElement_get_CurrentFrameworkId TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CurrentFrameworkId TYPEDEF PTR IUIAutomationElement_get_CurrentFrameworkId

    IUIAutomationElement_get_CurrentIsRequiredForForm TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CurrentIsRequiredForForm TYPEDEF PTR IUIAutomationElement_get_CurrentIsRequiredForForm

    IUIAutomationElement_get_CurrentItemStatus TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CurrentItemStatus TYPEDEF PTR IUIAutomationElement_get_CurrentItemStatus

    IUIAutomationElement_get_CurrentBoundingRectangle TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CurrentBoundingRectangle TYPEDEF PTR IUIAutomationElement_get_CurrentBoundingRectangle

    IUIAutomationElement_get_CurrentLabeledBy TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CurrentLabeledBy TYPEDEF PTR IUIAutomationElement_get_CurrentLabeledBy

    IUIAutomationElement_get_CurrentAriaRole TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CurrentAriaRole TYPEDEF PTR IUIAutomationElement_get_CurrentAriaRole

    IUIAutomationElement_get_CurrentAriaProperties TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CurrentAriaProperties TYPEDEF PTR IUIAutomationElement_get_CurrentAriaProperties

    IUIAutomationElement_get_CurrentIsDataValidForForm TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CurrentIsDataValidForForm TYPEDEF PTR IUIAutomationElement_get_CurrentIsDataValidForForm

    IUIAutomationElement_get_CurrentControllerFor TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CurrentControllerFor TYPEDEF PTR IUIAutomationElement_get_CurrentControllerFor

    IUIAutomationElement_get_CurrentDescribedBy TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CurrentDescribedBy TYPEDEF PTR IUIAutomationElement_get_CurrentDescribedBy

    IUIAutomationElement_get_CurrentFlowsTo TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CurrentFlowsTo TYPEDEF PTR IUIAutomationElement_get_CurrentFlowsTo

    IUIAutomationElement_get_CurrentProviderDescription TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CurrentProviderDescription TYPEDEF PTR IUIAutomationElement_get_CurrentProviderDescription

    IUIAutomationElement_get_CachedProcessId TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CachedProcessId TYPEDEF PTR IUIAutomationElement_get_CachedProcessId

    IUIAutomationElement_get_CachedControlType TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CachedControlType TYPEDEF PTR IUIAutomationElement_get_CachedControlType

    IUIAutomationElement_get_CachedLocalizedControlType TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CachedLocalizedControlType TYPEDEF PTR IUIAutomationElement_get_CachedLocalizedControlType

    IUIAutomationElement_get_CachedName TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CachedName TYPEDEF PTR IUIAutomationElement_get_CachedName

    IUIAutomationElement_get_CachedAcceleratorKey TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CachedAcceleratorKey TYPEDEF PTR IUIAutomationElement_get_CachedAcceleratorKey

    IUIAutomationElement_get_CachedAccessKey TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CachedAccessKey TYPEDEF PTR IUIAutomationElement_get_CachedAccessKey

    IUIAutomationElement_get_CachedHasKeyboardFocus TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CachedHasKeyboardFocus TYPEDEF PTR IUIAutomationElement_get_CachedHasKeyboardFocus

    IUIAutomationElement_get_CachedIsKeyboardFocusable TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CachedIsKeyboardFocusable TYPEDEF PTR IUIAutomationElement_get_CachedIsKeyboardFocusable

    IUIAutomationElement_get_CachedIsEnabled TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CachedIsEnabled TYPEDEF PTR IUIAutomationElement_get_CachedIsEnabled

    IUIAutomationElement_get_CachedAutomationId TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CachedAutomationId TYPEDEF PTR IUIAutomationElement_get_CachedAutomationId

    IUIAutomationElement_get_CachedClassName TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CachedClassName TYPEDEF PTR IUIAutomationElement_get_CachedClassName

    IUIAutomationElement_get_CachedHelpText TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CachedHelpText TYPEDEF PTR IUIAutomationElement_get_CachedHelpText

    IUIAutomationElement_get_CachedCulture TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CachedCulture TYPEDEF PTR IUIAutomationElement_get_CachedCulture

    IUIAutomationElement_get_CachedIsControlElement TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CachedIsControlElement TYPEDEF PTR IUIAutomationElement_get_CachedIsControlElement

    IUIAutomationElement_get_CachedIsContentElement TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CachedIsContentElement TYPEDEF PTR IUIAutomationElement_get_CachedIsContentElement

    IUIAutomationElement_get_CachedIsPassword TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CachedIsPassword TYPEDEF PTR IUIAutomationElement_get_CachedIsPassword

    IUIAutomationElement_get_CachedNativeWindowHandle TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CachedNativeWindowHandle TYPEDEF PTR IUIAutomationElement_get_CachedNativeWindowHandle

    IUIAutomationElement_get_CachedItemType TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CachedItemType TYPEDEF PTR IUIAutomationElement_get_CachedItemType

    IUIAutomationElement_get_CachedIsOffscreen TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CachedIsOffscreen TYPEDEF PTR IUIAutomationElement_get_CachedIsOffscreen

    IUIAutomationElement_get_CachedOrientation TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CachedOrientation TYPEDEF PTR IUIAutomationElement_get_CachedOrientation

    IUIAutomationElement_get_CachedFrameworkId TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CachedFrameworkId TYPEDEF PTR IUIAutomationElement_get_CachedFrameworkId

    IUIAutomationElement_get_CachedIsRequiredForForm TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CachedIsRequiredForForm TYPEDEF PTR IUIAutomationElement_get_CachedIsRequiredForForm

    IUIAutomationElement_get_CachedItemStatus TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CachedItemStatus TYPEDEF PTR IUIAutomationElement_get_CachedItemStatus

    IUIAutomationElement_get_CachedBoundingRectangle TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CachedBoundingRectangle TYPEDEF PTR IUIAutomationElement_get_CachedBoundingRectangle

    IUIAutomationElement_get_CachedLabeledBy TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CachedLabeledBy TYPEDEF PTR IUIAutomationElement_get_CachedLabeledBy

    IUIAutomationElement_get_CachedAriaRole TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CachedAriaRole TYPEDEF PTR IUIAutomationElement_get_CachedAriaRole

    IUIAutomationElement_get_CachedAriaProperties TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CachedAriaProperties TYPEDEF PTR IUIAutomationElement_get_CachedAriaProperties

    IUIAutomationElement_get_CachedIsDataValidForForm TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CachedIsDataValidForForm TYPEDEF PTR IUIAutomationElement_get_CachedIsDataValidForForm

    IUIAutomationElement_get_CachedControllerFor TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CachedControllerFor TYPEDEF PTR IUIAutomationElement_get_CachedControllerFor

    IUIAutomationElement_get_CachedDescribedBy TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CachedDescribedBy TYPEDEF PTR IUIAutomationElement_get_CachedDescribedBy

    IUIAutomationElement_get_CachedFlowsTo TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CachedFlowsTo TYPEDEF PTR IUIAutomationElement_get_CachedFlowsTo

    IUIAutomationElement_get_CachedProviderDescription TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement_get_CachedProviderDescription TYPEDEF PTR IUIAutomationElement_get_CachedProviderDescription

    IUIAutomationElement_GetClickablePoint TYPEDEF PROTO :XWORD, clickable:XWORD, gotClickable:XWORD
    FIUIAutomationElement_GetClickablePoint TYPEDEF PTR IUIAutomationElement_GetClickablePoint

    STIUIAutomationElement STRUCT
        QueryInterface                  FIUIAutomationElement_QueryInterface ?
        AddRef                          XPTR ?
        Release                         XPTR ?
        SetFocus1                       XPTR ?
        GetRuntimeId                    FIUIAutomationElement_GetRuntimeId ?
        FindFirst                       FIUIAutomationElement_FindFirst ?
        FindAll                         FIUIAutomationElement_FindAll ?
        FindFirstBuildCache             FIUIAutomationElement_FindFirstBuildCache ?
        FindAllBuildCache               FIUIAutomationElement_FindAllBuildCache ?
        BuildUpdatedCache               FIUIAutomationElement_BuildUpdatedCache ?
        GetCurrentPropertyValue         FIUIAutomationElement_GetCurrentPropertyValue ?
        GetCurrentPropertyValueEx       FIUIAutomationElement_GetCurrentPropertyValueEx ?
        GetCachedPropertyValue          FIUIAutomationElement_GetCachedPropertyValue ?
        GetCachedPropertyValueEx        FIUIAutomationElement_GetCachedPropertyValueEx ?
        GetCurrentPatternAs             FIUIAutomationElement_GetCurrentPatternAs ?
        GetCachedPatternAs              FIUIAutomationElement_GetCachedPatternAs ?
        GetCurrentPattern               FIUIAutomationElement_GetCurrentPattern ?
        GetCachedPattern                FIUIAutomationElement_GetCachedPattern ?
        GetCachedParent                 FIUIAutomationElement_GetCachedParent ?
        GetCachedChildren               FIUIAutomationElement_GetCachedChildren ?
        get_CurrentProcessId            FIUIAutomationElement_get_CurrentProcessId ?
        get_CurrentControlType          FIUIAutomationElement_get_CurrentControlType ?
        get_CurrentLocalizedControlType FIUIAutomationElement_get_CurrentLocalizedControlType ?
        get_CurrentName                 FIUIAutomationElement_get_CurrentName ?
        get_CurrentAcceleratorKey       FIUIAutomationElement_get_CurrentAcceleratorKey ?
        get_CurrentAccessKey            FIUIAutomationElement_get_CurrentAccessKey ?
        get_CurrentHasKeyboardFocus     FIUIAutomationElement_get_CurrentHasKeyboardFocus ?
        get_CurrentIsKeyboardFocusable  FIUIAutomationElement_get_CurrentIsKeyboardFocusable ?
        get_CurrentIsEnabled            FIUIAutomationElement_get_CurrentIsEnabled ?
        get_CurrentAutomationId         FIUIAutomationElement_get_CurrentAutomationId ?
        get_CurrentClassName            FIUIAutomationElement_get_CurrentClassName ?
        get_CurrentHelpText             FIUIAutomationElement_get_CurrentHelpText ?
        get_CurrentCulture              FIUIAutomationElement_get_CurrentCulture ?
        get_CurrentIsControlElement     FIUIAutomationElement_get_CurrentIsControlElement ?
        get_CurrentIsContentElement     FIUIAutomationElement_get_CurrentIsContentElement ?
        get_CurrentIsPassword           FIUIAutomationElement_get_CurrentIsPassword ?
        get_CurrentNativeWindowHandle   FIUIAutomationElement_get_CurrentNativeWindowHandle ?
        get_CurrentItemType             FIUIAutomationElement_get_CurrentItemType ?
        get_CurrentIsOffscreen          FIUIAutomationElement_get_CurrentIsOffscreen ?
        get_CurrentOrientation          FIUIAutomationElement_get_CurrentOrientation ?
        get_CurrentFrameworkId          FIUIAutomationElement_get_CurrentFrameworkId ?
        get_CurrentIsRequiredForForm    FIUIAutomationElement_get_CurrentIsRequiredForForm ?
        get_CurrentItemStatus           FIUIAutomationElement_get_CurrentItemStatus ?
        get_CurrentBoundingRectangle    FIUIAutomationElement_get_CurrentBoundingRectangle ?
        get_CurrentLabeledBy            FIUIAutomationElement_get_CurrentLabeledBy ?
        get_CurrentAriaRole             FIUIAutomationElement_get_CurrentAriaRole ?
        get_CurrentAriaProperties       FIUIAutomationElement_get_CurrentAriaProperties ?
        get_CurrentIsDataValidForForm   FIUIAutomationElement_get_CurrentIsDataValidForForm ?
        get_CurrentControllerFor        FIUIAutomationElement_get_CurrentControllerFor ?
        get_CurrentDescribedBy          FIUIAutomationElement_get_CurrentDescribedBy ?
        get_CurrentFlowsTo              FIUIAutomationElement_get_CurrentFlowsTo ?
        get_CurrentProviderDescription  FIUIAutomationElement_get_CurrentProviderDescription ?
        get_CachedProcessId             FIUIAutomationElement_get_CachedProcessId ?
        get_CachedControlType           FIUIAutomationElement_get_CachedControlType ?
        get_CachedLocalizedControlType  FIUIAutomationElement_get_CachedLocalizedControlType ?
        get_CachedName                  FIUIAutomationElement_get_CachedName ?
        get_CachedAcceleratorKey        FIUIAutomationElement_get_CachedAcceleratorKey ?
        get_CachedAccessKey             FIUIAutomationElement_get_CachedAccessKey ?
        get_CachedHasKeyboardFocus      FIUIAutomationElement_get_CachedHasKeyboardFocus ?
        get_CachedIsKeyboardFocusable   FIUIAutomationElement_get_CachedIsKeyboardFocusable ?
        get_CachedIsEnabled             FIUIAutomationElement_get_CachedIsEnabled ?
        get_CachedAutomationId          FIUIAutomationElement_get_CachedAutomationId ?
        get_CachedClassName             FIUIAutomationElement_get_CachedClassName ?
        get_CachedHelpText              FIUIAutomationElement_get_CachedHelpText ?
        get_CachedCulture               FIUIAutomationElement_get_CachedCulture ?
        get_CachedIsControlElement      FIUIAutomationElement_get_CachedIsControlElement ?
        get_CachedIsContentElement      FIUIAutomationElement_get_CachedIsContentElement ?
        get_CachedIsPassword            FIUIAutomationElement_get_CachedIsPassword ?
        get_CachedNativeWindowHandle    FIUIAutomationElement_get_CachedNativeWindowHandle ?
        get_CachedItemType              FIUIAutomationElement_get_CachedItemType ?
        get_CachedIsOffscreen           FIUIAutomationElement_get_CachedIsOffscreen ?
        get_CachedOrientation           FIUIAutomationElement_get_CachedOrientation ?
        get_CachedFrameworkId           FIUIAutomationElement_get_CachedFrameworkId ?
        get_CachedIsRequiredForForm     FIUIAutomationElement_get_CachedIsRequiredForForm ?
        get_CachedItemStatus            FIUIAutomationElement_get_CachedItemStatus ?
        get_CachedBoundingRectangle     FIUIAutomationElement_get_CachedBoundingRectangle ?
        get_CachedLabeledBy             FIUIAutomationElement_get_CachedLabeledBy ?
        get_CachedAriaRole              FIUIAutomationElement_get_CachedAriaRole ?
        get_CachedAriaProperties        FIUIAutomationElement_get_CachedAriaProperties ?
        get_CachedIsDataValidForForm    FIUIAutomationElement_get_CachedIsDataValidForForm ?
        get_CachedControllerFor         FIUIAutomationElement_get_CachedControllerFor ?
        get_CachedDescribedBy           FIUIAutomationElement_get_CachedDescribedBy ?
        get_CachedFlowsTo               FIUIAutomationElement_get_CachedFlowsTo ?
        get_CachedProviderDescription   FIUIAutomationElement_get_CachedProviderDescription ?
        GetClickablePoint               FIUIAutomationElement_GetClickablePoint ?
    STIUIAutomationElement ENDS
 
    IUIAutomationElement MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationElement PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationElement>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationElement
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;_IUIAutomationElement_INTERFACE_DEFINED_

IFNDEF _IUIAutomationElementArray_INTERFACE_DEFINED_
    _IUIAutomationElementArray_INTERFACE_DEFINED_   EQU 1

    IUIAutomationElementArray_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationElementArray_QueryInterface TYPEDEF PTR IUIAutomationElementArray_QueryInterface

    IUIAutomationElementArray_get_Length TYPEDEF PROTO :XWORD, length1:XWORD
    FIUIAutomationElementArray_get_Length TYPEDEF PTR IUIAutomationElementArray_get_Length

    IUIAutomationElementArray_GetElement TYPEDEF PROTO :XWORD, index:XWORD, element:XWORD
    FIUIAutomationElementArray_GetElement TYPEDEF PTR IUIAutomationElementArray_GetElement

    STIUIAutomationElementArray STRUCT
        QueryInterface  FIUIAutomationElementArray_QueryInterface ?
        AddRef          XPTR ?
        Release         XPTR ?
        get_Length      FIUIAutomationElementArray_get_Length ?
        GetElement      FIUIAutomationElementArray_GetElement ?
    STIUIAutomationElementArray ENDS
 
    IUIAutomationElementArray MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationElementArray PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationElementArray>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationElementArray
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;_IUIAutomationElementArray_INTERFACE_DEFINED_

IFNDEF _IUIAutomationCondition_INTERFACE_DEFINED_
    _IUIAutomationCondition_INTERFACE_DEFINED_  EQU 1
    
    IUIAutomationCondition_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationCondition_QueryInterface TYPEDEF PTR IUIAutomationCondition_QueryInterface

    STIUIAutomationCondition STRUCT
        QueryInterface          FIUIAutomationCondition_QueryInterface ?
        AddRef                  XPTR ?
        Release                 XPTR ?
    STIUIAutomationCondition ENDS
 
    IUIAutomationCondition MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationCondition PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationCondition>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationCondition
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;_IUIAutomationCondition_INTERFACE_DEFINED_

IFNDEF _IUIAutomationBoolCondition_INTERFACE_DEFINED_
    _IUIAutomationBoolCondition_INTERFACE_DEFINED_  EQU 1
    
    IUIAutomationBoolCondition_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationBoolCondition_QueryInterface TYPEDEF PTR IUIAutomationBoolCondition_QueryInterface

    IUIAutomationBoolCondition_get_BooleanValue TYPEDEF PROTO :XWORD, boolVal:XWORD
    FIUIAutomationBoolCondition_get_BooleanValue TYPEDEF PTR IUIAutomationBoolCondition_get_BooleanValue

    STIUIAutomationBoolCondition STRUCT
        QueryInterface      FIUIAutomationBoolCondition_QueryInterface ?
        AddRef              XPTR ?
        Release             XPTR ?
        get_BooleanValue    FIUIAutomationBoolCondition_get_BooleanValue ?
    STIUIAutomationBoolCondition ENDS
 
    IUIAutomationBoolCondition MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationBoolCondition PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationBoolCondition>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationBoolCondition
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;_IUIAutomationBoolCondition_INTERFACE_DEFINED_

IFNDEF _IUIAutomationPropertyCondition_INTERFACE_DEFINED_
    _IUIAutomationPropertyCondition_INTERFACE_DEFINED_  EQU 1

    IUIAutomationPropertyCondition_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationPropertyCondition_QueryInterface TYPEDEF PTR IUIAutomationPropertyCondition_QueryInterface

    IUIAutomationPropertyCondition_get_PropertyId TYPEDEF PROTO :XWORD, propertyId:XWORD
    FIUIAutomationPropertyCondition_get_PropertyId TYPEDEF PTR IUIAutomationPropertyCondition_get_PropertyId

    IUIAutomationPropertyCondition_get_PropertyValue TYPEDEF PROTO :XWORD, propertyValue:XWORD
    FIUIAutomationPropertyCondition_get_PropertyValue TYPEDEF PTR IUIAutomationPropertyCondition_get_PropertyValue

    IUIAutomationPropertyCondition_get_PropertyConditionFlags TYPEDEF PROTO :XWORD, flags:XWORD
    FIUIAutomationPropertyCondition_get_PropertyConditionFlags TYPEDEF PTR IUIAutomationPropertyCondition_get_PropertyConditionFlags

    STIUIAutomationPropertyCondition STRUCT
        QueryInterface              FIUIAutomationPropertyCondition_QueryInterface ?
        AddRef                      XPTR ?
        Release                     XPTR ?
        get_PropertyId              FIUIAutomationPropertyCondition_get_PropertyId ?
        get_PropertyValue           FIUIAutomationPropertyCondition_get_PropertyValue ?
        get_PropertyConditionFlags  FIUIAutomationPropertyCondition_get_PropertyConditionFlags ?
    STIUIAutomationPropertyCondition ENDS

    IUIAutomationPropertyCondition MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationPropertyCondition PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationPropertyCondition>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationPropertyCondition
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;_IUIAutomationPropertyCondition_INTERFACE_DEFINED_

IFNDEF _IUIAutomationAndCondition_INTERFACE_DEFINED_
    _IUIAutomationAndCondition_INTERFACE_DEFINED_   EQU 1

    IUIAutomationAndCondition_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationAndCondition_QueryInterface TYPEDEF PTR IUIAutomationAndCondition_QueryInterface

    IUIAutomationAndCondition_get_ChildCount TYPEDEF PROTO :XWORD, childCount:XWORD
    FIUIAutomationAndCondition_get_ChildCount TYPEDEF PTR IUIAutomationAndCondition_get_ChildCount

    IUIAutomationAndCondition_GetChildrenAsNativeArray TYPEDEF PROTO :XWORD, childArray:XWORD, childArrayCount:XWORD
    FIUIAutomationAndCondition_GetChildrenAsNativeArray TYPEDEF PTR IUIAutomationAndCondition_GetChildrenAsNativeArray

    IUIAutomationAndCondition_GetChildren TYPEDEF PROTO :XWORD, childArray:XWORD
    FIUIAutomationAndCondition_GetChildren TYPEDEF PTR IUIAutomationAndCondition_GetChildren

    STIUIAutomationAndCondition STRUCT
        QueryInterface              FIUIAutomationAndCondition_QueryInterface ?
        AddRef                      XPTR ?
        Release                     XPTR ?
        get_ChildCount              FIUIAutomationAndCondition_get_ChildCount ?
        GetChildrenAsNativeArray    FIUIAutomationAndCondition_GetChildrenAsNativeArray ?
        GetChildren                 FIUIAutomationAndCondition_GetChildren ?
    STIUIAutomationAndCondition ENDS
 
    IUIAutomationAndCondition MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationAndCondition PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationAndCondition>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationAndCondition
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;_IUIAutomationAndCondition_INTERFACE_DEFINED_

IFNDEF _IUIAutomationOrCondition_INTERFACE_DEFINED_
    _IUIAutomationOrCondition_INTERFACE_DEFINED_    EQU 1

    IUIAutomationOrCondition_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationOrCondition_QueryInterface TYPEDEF PTR IUIAutomationOrCondition_QueryInterface

    IUIAutomationOrCondition_get_ChildCount TYPEDEF PROTO :XWORD, childCount:XWORD
    FIUIAutomationOrCondition_get_ChildCount TYPEDEF PTR IUIAutomationOrCondition_get_ChildCount

    IUIAutomationOrCondition_GetChildrenAsNativeArray TYPEDEF PROTO :XWORD, childArray:XWORD, childArrayCount:XWORD
    FIUIAutomationOrCondition_GetChildrenAsNativeArray TYPEDEF PTR IUIAutomationOrCondition_GetChildrenAsNativeArray

    IUIAutomationOrCondition_GetChildren TYPEDEF PROTO :XWORD, childArray:XWORD
    FIUIAutomationOrCondition_GetChildren TYPEDEF PTR IUIAutomationOrCondition_GetChildren

    STIUIAutomationOrCondition STRUCT
        QueryInterface              FIUIAutomationOrCondition_QueryInterface ?
        AddRef                      XPTR ?
        Release                     XPTR ?
        get_ChildCount              FIUIAutomationOrCondition_get_ChildCount ?
        GetChildrenAsNativeArray    FIUIAutomationOrCondition_GetChildrenAsNativeArray ?
        GetChildren                 FIUIAutomationOrCondition_GetChildren ?
    STIUIAutomationOrCondition ENDS
 
    IUIAutomationOrCondition MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationOrCondition PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationOrCondition>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationOrCondition
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;_IUIAutomationOrCondition_INTERFACE_DEFINED_

IFNDEF _IUIAutomationNotCondition_INTERFACE_DEFINED_
    _IUIAutomationNotCondition_INTERFACE_DEFINED_   EQU 1

    IUIAutomationNotCondition_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationNotCondition_QueryInterface TYPEDEF PTR IUIAutomationNotCondition_QueryInterface

    IUIAutomationNotCondition_GetChild TYPEDEF PROTO :XWORD, condition:XWORD
    FIUIAutomationNotCondition_GetChild TYPEDEF PTR IUIAutomationNotCondition_GetChild

    STIUIAutomationNotCondition STRUCT
        QueryInterface  FIUIAutomationNotCondition_QueryInterface ?
        AddRef          XPTR ?
        Release         XPTR ?
        GetChild        FIUIAutomationNotCondition_GetChild ?
    STIUIAutomationNotCondition ENDS
 
    IUIAutomationNotCondition MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationNotCondition PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationNotCondition>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationNotCondition
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;_IUIAutomationNotCondition_INTERFACE_DEFINED_

IFNDEF _IUIAutomationCacheRequest_INTERFACE_DEFINED_
    _IUIAutomationCacheRequest_INTERFACE_DEFINED_   EQU 1

    IUIAutomationCacheRequest_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationCacheRequest_QueryInterface TYPEDEF PTR IUIAutomationCacheRequest_QueryInterface

    IUIAutomationCacheRequest_Clone TYPEDEF PROTO :XWORD, clonedRequest:XWORD
    FIUIAutomationCacheRequest_Clone TYPEDEF PTR IUIAutomationCacheRequest_Clone

    IUIAutomationCacheRequest_get_TreeScope TYPEDEF PROTO :XWORD, scope:XWORD
    FIUIAutomationCacheRequest_get_TreeScope TYPEDEF PTR IUIAutomationCacheRequest_get_TreeScope

    IUIAutomationCacheRequest_get_TreeFilter TYPEDEF PROTO :XWORD, filter:XWORD
    FIUIAutomationCacheRequest_get_TreeFilter TYPEDEF PTR IUIAutomationCacheRequest_get_TreeFilter

    IUIAutomationCacheRequest_put_TreeFilter TYPEDEF PROTO :XWORD, filter:XWORD
    FIUIAutomationCacheRequest_put_TreeFilter TYPEDEF PTR IUIAutomationCacheRequest_put_TreeFilter

    IUIAutomationCacheRequest_get_AutomationElementMode TYPEDEF PROTO :XWORD, Mode1:XWORD
    FIUIAutomationCacheRequest_get_AutomationElementMode TYPEDEF PTR IUIAutomationCacheRequest_get_AutomationElementMode

    STIUIAutomationCacheRequest STRUCT
        QueryInterface              FIUIAutomationCacheRequest_QueryInterface ?
        AddRef                      XPTR ?
        Release                     XPTR ?
        AddProperty1                XPTR ?
        AddPattern                  XPTR ?
        Clone                       FIUIAutomationCacheRequest_Clone ?
        get_TreeScope               FIUIAutomationCacheRequest_get_TreeScope ?
        put_TreeScope               XPTR ?
        get_TreeFilter              FIUIAutomationCacheRequest_get_TreeFilter ?
        put_TreeFilter              FIUIAutomationCacheRequest_put_TreeFilter ?
        get_AutomationElementMode   FIUIAutomationCacheRequest_get_AutomationElementMode ?
        put_AutomationElementMode   XPTR ?
    STIUIAutomationCacheRequest ENDS
 
    IUIAutomationCacheRequest MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationCacheRequest PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationCacheRequest>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationCacheRequest
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;_IUIAutomationCacheRequest_INTERFACE_DEFINED_

IFNDEF _IUIAutomationTreeWalker_INTERFACE_DEFINED_
    _IUIAutomationTreeWalker_INTERFACE_DEFINED_ EQU 1

    IUIAutomationTreeWalker_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationTreeWalker_QueryInterface TYPEDEF PTR IUIAutomationTreeWalker_QueryInterface

    IUIAutomationTreeWalker_GetParentElement TYPEDEF PROTO :XWORD, element:XWORD, parent:XWORD
    FIUIAutomationTreeWalker_GetParentElement TYPEDEF PTR IUIAutomationTreeWalker_GetParentElement

    IUIAutomationTreeWalker_GetFirstChildElement TYPEDEF PROTO :XWORD, element:XWORD, first:XWORD
    FIUIAutomationTreeWalker_GetFirstChildElement TYPEDEF PTR IUIAutomationTreeWalker_GetFirstChildElement

    IUIAutomationTreeWalker_GetLastChildElement TYPEDEF PROTO :XWORD, element:XWORD, last:XWORD
    FIUIAutomationTreeWalker_GetLastChildElement TYPEDEF PTR IUIAutomationTreeWalker_GetLastChildElement

    IUIAutomationTreeWalker_GetNextSiblingElement TYPEDEF PROTO :XWORD, element:XWORD, next:XWORD
    FIUIAutomationTreeWalker_GetNextSiblingElement TYPEDEF PTR IUIAutomationTreeWalker_GetNextSiblingElement

    IUIAutomationTreeWalker_GetPreviousSiblingElement TYPEDEF PROTO :XWORD, element:XWORD, previous:XWORD
    FIUIAutomationTreeWalker_GetPreviousSiblingElement TYPEDEF PTR IUIAutomationTreeWalker_GetPreviousSiblingElement

    IUIAutomationTreeWalker_NormalizeElement TYPEDEF PROTO :XWORD, element:XWORD, normalized:XWORD
    FIUIAutomationTreeWalker_NormalizeElement TYPEDEF PTR IUIAutomationTreeWalker_NormalizeElement

    IUIAutomationTreeWalker_GetParentElementBuildCache TYPEDEF PROTO :XWORD, element:XWORD, cacheRequest:XWORD, parent:XWORD
    FIUIAutomationTreeWalker_GetParentElementBuildCache TYPEDEF PTR IUIAutomationTreeWalker_GetParentElementBuildCache

    IUIAutomationTreeWalker_GetFirstChildElementBuildCache TYPEDEF PROTO :XWORD, element:XWORD, cacheRequest:XWORD, first:XWORD
    FIUIAutomationTreeWalker_GetFirstChildElementBuildCache TYPEDEF PTR IUIAutomationTreeWalker_GetFirstChildElementBuildCache

    IUIAutomationTreeWalker_GetLastChildElementBuildCache TYPEDEF PROTO :XWORD, element:XWORD, cacheRequest:XWORD, last:XWORD
    FIUIAutomationTreeWalker_GetLastChildElementBuildCache TYPEDEF PTR IUIAutomationTreeWalker_GetLastChildElementBuildCache

    IUIAutomationTreeWalker_GetNextSiblingElementBuildCache TYPEDEF PROTO :XWORD, element:XWORD, cacheRequest:XWORD, next:XWORD
    FIUIAutomationTreeWalker_GetNextSiblingElementBuildCache TYPEDEF PTR IUIAutomationTreeWalker_GetNextSiblingElementBuildCache

    IUIAutomationTreeWalker_GetPreviousSiblingElementBuildCache TYPEDEF PROTO :XWORD, element:XWORD, cacheRequest:XWORD, previous:XWORD
    FIUIAutomationTreeWalker_GetPreviousSiblingElementBuildCache TYPEDEF PTR IUIAutomationTreeWalker_GetPreviousSiblingElementBuildCache

    IUIAutomationTreeWalker_NormalizeElementBuildCache TYPEDEF PROTO :XWORD, element:XWORD, cacheRequest:XWORD, normalized:XWORD
    FIUIAutomationTreeWalker_NormalizeElementBuildCache TYPEDEF PTR IUIAutomationTreeWalker_NormalizeElementBuildCache

    IUIAutomationTreeWalker_get_Condition TYPEDEF PROTO :XWORD, condition:XWORD
    FIUIAutomationTreeWalker_get_Condition TYPEDEF PTR IUIAutomationTreeWalker_get_Condition

    STIUIAutomationTreeWalker STRUCT
        QueryInterface                      FIUIAutomationTreeWalker_QueryInterface ?
        AddRef                              XPTR ?
        Release                             XPTR ?
        GetParentElement                    FIUIAutomationTreeWalker_GetParentElement ?
        GetFirstChildElement                FIUIAutomationTreeWalker_GetFirstChildElement ?
        GetLastChildElement                 FIUIAutomationTreeWalker_GetLastChildElement ?
        GetNextSiblingElement               FIUIAutomationTreeWalker_GetNextSiblingElement ?
        GetPreviousSiblingElement           FIUIAutomationTreeWalker_GetPreviousSiblingElement ?
        NormalizeElement                    FIUIAutomationTreeWalker_NormalizeElement ?
        GetParentElementBuildCache          FIUIAutomationTreeWalker_GetParentElementBuildCache ?
        GetFirstChildElementBuildCache      FIUIAutomationTreeWalker_GetFirstChildElementBuildCache ?
        GetLastChildElementBuildCache       FIUIAutomationTreeWalker_GetLastChildElementBuildCache ?
        GetNextSiblingElementBuildCache     FIUIAutomationTreeWalker_GetNextSiblingElementBuildCache ?
        GetPreviousSiblingElementBuildCache FIUIAutomationTreeWalker_GetPreviousSiblingElementBuildCache ?
        NormalizeElementBuildCache          FIUIAutomationTreeWalker_NormalizeElementBuildCache ?
        get_Condition                       FIUIAutomationTreeWalker_get_Condition ?
    STIUIAutomationTreeWalker ENDS
 
    IUIAutomationTreeWalker MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationTreeWalker PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationTreeWalker>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationTreeWalker
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;_IUIAutomationTreeWalker_INTERFACE_DEFINED_

IFNDEF __IUIAutomationEventHandler_INTERFACE_DEFINED__
    __IUIAutomationEventHandler_INTERFACE_DEFINED__ EQU 1

    IUIAutomationEventHandler_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationEventHandler_QueryInterface TYPEDEF PTR IUIAutomationEventHandler_QueryInterface

    IUIAutomationEventHandler_HandleAutomationEvent TYPEDEF PROTO :XWORD, sender:XWORD, eventId:XWORD 
    FIUIAutomationEventHandler_HandleAutomationEvent TYPEDEF PTR IUIAutomationEventHandler_HandleAutomationEvent

    STIUIAutomationEventHandler STRUCT
        QueryInterface          FIUIAutomationEventHandler_QueryInterface ?
        AddRef                  XPTR ?
        Release                 XPTR ?
        HandleAutomationEvent   FIUIAutomationEventHandler_HandleAutomationEvent ?
    STIUIAutomationEventHandler ENDS
 
    IUIAutomationEventHandler MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationEventHandler PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationEventHandler>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationEventHandler
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationEventHandler_INTERFACE_DEFINED__

IFNDEF __IUIAutomationPropertyChangedEventHandler_INTERFACE_DEFINED__
    __IUIAutomationPropertyChangedEventHandler_INTERFACE_DEFINED__  EQU 1

    IUIAutomationPropertyChangedEventHandler_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationPropertyChangedEventHandler_QueryInterface TYPEDEF PTR IUIAutomationPropertyChangedEventHandler_QueryInterface

    IUIAutomationPropertyChangedEventHandler_HandlePropertyChangedEvent TYPEDEF PROTO :XWORD, sender:XWORD, propertyId:XWORD, newValue:VARIANT 
    FIUIAutomationPropertyChangedEventHandler_HandlePropertyChangedEvent TYPEDEF PTR IUIAutomationPropertyChangedEventHandler_HandlePropertyChangedEvent

    STIUIAutomationPropertyChangedEventHandler STRUCT
        QueryInterface              FIUIAutomationPropertyChangedEventHandler_QueryInterface ?
        AddRef                      XPTR ?
        Release                     XPTR ?
        HandlePropertyChangedEvent  FIUIAutomationPropertyChangedEventHandler_HandlePropertyChangedEvent ?
    STIUIAutomationPropertyChangedEventHandler ENDS
 
    IUIAutomationPropertyChangedEventHandler MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationPropertyChangedEventHandler PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationPropertyChangedEventHandler>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationPropertyChangedEventHandler
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationPropertyChangedEventHandler_INTERFACE_DEFINED__

IFNDEF __IUIAutomationStructureChangedEventHandler_INTERFACE_DEFINED__
    __IUIAutomationStructureChangedEventHandler_INTERFACE_DEFINED__ EQU 1

    IUIAutomationStructureChangedEventHandler_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationStructureChangedEventHandler_QueryInterface TYPEDEF PTR IUIAutomationStructureChangedEventHandler_QueryInterface

    IUIAutomationStructureChangedEventHandler_HandleStructureChangedEvent TYPEDEF PROTO :XWORD, sender:XWORD, changeType:XWORD, runtimeId:XWORD
    FIUIAutomationStructureChangedEventHandler_HandleStructureChangedEvent TYPEDEF PTR IUIAutomationStructureChangedEventHandler_HandleStructureChangedEvent

    STIUIAutomationStructureChangedEventHandler STRUCT
        QueryInterface              FIUIAutomationStructureChangedEventHandler_QueryInterface ?
        AddRef                      XPTR ?
        Release                     XPTR ?
        HandleStructureChangedEvent FIUIAutomationStructureChangedEventHandler_HandleStructureChangedEvent ?
    STIUIAutomationStructureChangedEventHandler ENDS
 
    IUIAutomationStructureChangedEventHandler MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationStructureChangedEventHandler PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationStructureChangedEventHandler>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationStructureChangedEventHandler
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationStructureChangedEventHandler_INTERFACE_DEFINED__

IFNDEF __IUIAutomationFocusChangedEventHandler_INTERFACE_DEFINED__
    __IUIAutomationFocusChangedEventHandler_INTERFACE_DEFINED__ EQU 1

    IUIAutomationFocusChangedEventHandler_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationFocusChangedEventHandler_QueryInterface TYPEDEF PTR IUIAutomationFocusChangedEventHandler_QueryInterface

    IUIAutomationFocusChangedEventHandler_HandleFocusChangedEvent TYPEDEF PROTO :XWORD, sender:XWORD
    FIUIAutomationFocusChangedEventHandler_HandleFocusChangedEvent TYPEDEF PTR IUIAutomationFocusChangedEventHandler_HandleFocusChangedEvent

    STIUIAutomationFocusChangedEventHandler STRUCT
        QueryInterface          FIUIAutomationFocusChangedEventHandler_QueryInterface ?
        AddRef                  XPTR ?
        Release                 XPTR ?
        HandleFocusChangedEvent FIUIAutomationFocusChangedEventHandler_HandleFocusChangedEvent ?
    STIUIAutomationFocusChangedEventHandler ENDS

    IUIAutomationFocusChangedEventHandler MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationFocusChangedEventHandler PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationFocusChangedEventHandler>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationFocusChangedEventHandler
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationFocusChangedEventHandler_INTERFACE_DEFINED__

IFNDEF __IUIAutomationTextEditTextChangedEventHandler_INTERFACE_DEFINED__
    __IUIAutomationTextEditTextChangedEventHandler_INTERFACE_DEFINED__  EQU 1

    IUIAutomationTextEditTextChangedEventHandler_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationTextEditTextChangedEventHandler_QueryInterface TYPEDEF PTR IUIAutomationTextEditTextChangedEventHandler_QueryInterface

    IUIAutomationTextEditTextChangedEventHandler_HandleTextEditTextChangedEvent TYPEDEF PROTO :XWORD, sender:XWORD, textEditChangeType:XWORD, eventStrings:XWORD
    FIUIAutomationTextEditTextChangedEventHandler_HandleTextEditTextChangedEvent TYPEDEF PTR IUIAutomationTextEditTextChangedEventHandler_HandleTextEditTextChangedEvent

    STIUIAutomationTextEditTextChangedEventHandler STRUCT
        QueryInterface                  FIUIAutomationTextEditTextChangedEventHandler_QueryInterface ?
        AddRef                          XPTR ?
        Release                         XPTR ?
        HandleTextEditTextChangedEvent  FIUIAutomationTextEditTextChangedEventHandler_HandleTextEditTextChangedEvent ?
    STIUIAutomationTextEditTextChangedEventHandler ENDS
 
    IUIAutomationTextEditTextChangedEventHandler MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationTextEditTextChangedEventHandler PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationTextEditTextChangedEventHandler>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationTextEditTextChangedEventHandler
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationTextEditTextChangedEventHandler_INTERFACE_DEFINED__

IFNDEF __IUIAutomationInvokePattern_INTERFACE_DEFINED__
    __IUIAutomationInvokePattern_INTERFACE_DEFINED__    EQU 1

    IUIAutomationInvokePattern_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationInvokePattern_QueryInterface TYPEDEF PTR IUIAutomationInvokePattern_QueryInterface

    STIUIAutomationInvokePattern STRUCT
        QueryInterface  FIUIAutomationInvokePattern_QueryInterface ?
        AddRef          XPTR ?
        Release         XPTR ?
        invoke1         XPTR ?
    STIUIAutomationInvokePattern ENDS
 
    IUIAutomationInvokePattern MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationInvokePattern PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationInvokePattern>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationInvokePattern
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationInvokePattern_INTERFACE_DEFINED__

IFNDEF __IUIAutomationDockPattern_INTERFACE_DEFINED__
    __IUIAutomationDockPattern_INTERFACE_DEFINED__  EQU 1

    IUIAutomationDockPattern_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationDockPattern_QueryInterface TYPEDEF PTR IUIAutomationDockPattern_QueryInterface

    IUIAutomationDockPattern_get_CurrentDockPosition TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationDockPattern_get_CurrentDockPosition TYPEDEF PTR IUIAutomationDockPattern_get_CurrentDockPosition

    IUIAutomationDockPattern_get_CachedDockPosition TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationDockPattern_get_CachedDockPosition TYPEDEF PTR IUIAutomationDockPattern_get_CachedDockPosition

    STIUIAutomationDockPattern STRUCT
        QueryInterface          FIUIAutomationDockPattern_QueryInterface ?
        AddRef                  XPTR ?
        Release                 XPTR ?
        SetDockPosition         XPTR ?
        get_CurrentDockPosition FIUIAutomationDockPattern_get_CurrentDockPosition ?
        get_CachedDockPosition  FIUIAutomationDockPattern_get_CachedDockPosition ?
    STIUIAutomationDockPattern ENDS
 
    IUIAutomationDockPattern MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationDockPattern PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationDockPattern>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationDockPattern
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationDockPattern_INTERFACE_DEFINED__

IFNDEF __IUIAutomationExpandCollapsePattern_INTERFACE_DEFINED__
    __IUIAutomationExpandCollapsePattern_INTERFACE_DEFINED__    EQU 1

    IUIAutomationExpandCollapsePattern_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationExpandCollapsePattern_QueryInterface TYPEDEF PTR IUIAutomationExpandCollapsePattern_QueryInterface

    IUIAutomationExpandCollapsePattern_get_CurrentExpandCollapseState TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationExpandCollapsePattern_get_CurrentExpandCollapseState TYPEDEF PTR IUIAutomationExpandCollapsePattern_get_CurrentExpandCollapseState

    IUIAutomationExpandCollapsePattern_get_CachedExpandCollapseState TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationExpandCollapsePattern_get_CachedExpandCollapseState TYPEDEF PTR IUIAutomationExpandCollapsePattern_get_CachedExpandCollapseState

    STIUIAutomationExpandCollapsePattern STRUCT
        QueryInterface                  FIUIAutomationExpandCollapsePattern_QueryInterface ?
        AddRef                          XPTR ?
        Release                         XPTR ?
        Expand                          XPTR ?
        Collapse                        XPTR ?
        get_CurrentExpandCollapseState  FIUIAutomationExpandCollapsePattern_get_CurrentExpandCollapseState ?
        get_CachedExpandCollapseState   FIUIAutomationExpandCollapsePattern_get_CachedExpandCollapseState ?
    STIUIAutomationExpandCollapsePattern ENDS
 
    IUIAutomationExpandCollapsePattern MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationExpandCollapsePattern PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationExpandCollapsePattern>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationExpandCollapsePattern
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationExpandCollapsePattern_INTERFACE_DEFINED__

IFNDEF __IUIAutomationGridPattern_INTERFACE_DEFINED__
    __IUIAutomationGridPattern_INTERFACE_DEFINED__  EQU 1

    IUIAutomationGridPattern_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationGridPattern_QueryInterface TYPEDEF PTR IUIAutomationGridPattern_QueryInterface

    IUIAutomationGridPattern_GetItem TYPEDEF PROTO :XWORD, row:XWORD, column:XWORD, element:XWORD
    FIUIAutomationGridPattern_GetItem TYPEDEF PTR IUIAutomationGridPattern_GetItem

    IUIAutomationGridPattern_get_CurrentRowCount TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationGridPattern_get_CurrentRowCount TYPEDEF PTR IUIAutomationGridPattern_get_CurrentRowCount

    IUIAutomationGridPattern_get_CurrentColumnCount TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationGridPattern_get_CurrentColumnCount TYPEDEF PTR IUIAutomationGridPattern_get_CurrentColumnCount

    IUIAutomationGridPattern_get_CachedRowCount TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationGridPattern_get_CachedRowCount TYPEDEF PTR IUIAutomationGridPattern_get_CachedRowCount

    IUIAutomationGridPattern_get_CachedColumnCount TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationGridPattern_get_CachedColumnCount TYPEDEF PTR IUIAutomationGridPattern_get_CachedColumnCount

    STIUIAutomationGridPattern STRUCT
        QueryInterface          FIUIAutomationGridPattern_QueryInterface ?
        AddRef                  XPTR ?
        Release                 XPTR ?
        GetItem                 FIUIAutomationGridPattern_GetItem ?
        get_CurrentRowCount     FIUIAutomationGridPattern_get_CurrentRowCount ?
        get_CurrentColumnCount  FIUIAutomationGridPattern_get_CurrentColumnCount ?
        get_CachedRowCount      FIUIAutomationGridPattern_get_CachedRowCount ?
        get_CachedColumnCount   FIUIAutomationGridPattern_get_CachedColumnCount ?
    STIUIAutomationGridPattern ENDS
 
    IUIAutomationGridPattern MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationGridPattern PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationGridPattern>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationGridPattern
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationGridPattern_INTERFACE_DEFINED__

IFNDEF __IUIAutomationGridItemPattern_INTERFACE_DEFINED__
    __IUIAutomationGridItemPattern_INTERFACE_DEFINED__  EQU 1

    IUIAutomationGridItemPattern_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationGridItemPattern_QueryInterface TYPEDEF PTR IUIAutomationGridItemPattern_QueryInterface

    IUIAutomationGridItemPattern_get_CurrentContainingGrid TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationGridItemPattern_get_CurrentContainingGrid TYPEDEF PTR IUIAutomationGridItemPattern_get_CurrentContainingGrid

    IUIAutomationGridItemPattern_get_CurrentRow TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationGridItemPattern_get_CurrentRow TYPEDEF PTR IUIAutomationGridItemPattern_get_CurrentRow

    IUIAutomationGridItemPattern_get_CurrentColumn TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationGridItemPattern_get_CurrentColumn TYPEDEF PTR IUIAutomationGridItemPattern_get_CurrentColumn

    IUIAutomationGridItemPattern_get_CurrentRowSpan TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationGridItemPattern_get_CurrentRowSpan TYPEDEF PTR IUIAutomationGridItemPattern_get_CurrentRowSpan

    IUIAutomationGridItemPattern_get_CurrentColumnSpan TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationGridItemPattern_get_CurrentColumnSpan TYPEDEF PTR IUIAutomationGridItemPattern_get_CurrentColumnSpan

    IUIAutomationGridItemPattern_get_CachedContainingGrid TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationGridItemPattern_get_CachedContainingGrid TYPEDEF PTR IUIAutomationGridItemPattern_get_CachedContainingGrid

    IUIAutomationGridItemPattern_get_CachedRow TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationGridItemPattern_get_CachedRow TYPEDEF PTR IUIAutomationGridItemPattern_get_CachedRow

    IUIAutomationGridItemPattern_get_CachedColumn TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationGridItemPattern_get_CachedColumn TYPEDEF PTR IUIAutomationGridItemPattern_get_CachedColumn

    IUIAutomationGridItemPattern_get_CachedRowSpan TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationGridItemPattern_get_CachedRowSpan TYPEDEF PTR IUIAutomationGridItemPattern_get_CachedRowSpan

    IUIAutomationGridItemPattern_get_CachedColumnSpan TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationGridItemPattern_get_CachedColumnSpan TYPEDEF PTR IUIAutomationGridItemPattern_get_CachedColumnSpan

    STIUIAutomationGridItemPattern STRUCT
        QueryInterface              FIUIAutomationGridItemPattern_QueryInterface ?
        AddRef                      XPTR ?
        Release                     XPTR ?
        get_CurrentContainingGrid   FIUIAutomationGridItemPattern_get_CurrentContainingGrid ?
        get_CurrentRow              FIUIAutomationGridItemPattern_get_CurrentRow ?
        get_CurrentColumn           FIUIAutomationGridItemPattern_get_CurrentColumn ?
        get_CurrentRowSpan          FIUIAutomationGridItemPattern_get_CurrentRowSpan ?
        get_CurrentColumnSpan       FIUIAutomationGridItemPattern_get_CurrentColumnSpan ?
        get_CachedContainingGrid    FIUIAutomationGridItemPattern_get_CachedContainingGrid ?
        get_CachedRow               FIUIAutomationGridItemPattern_get_CachedRow ?
        get_CachedColumn            FIUIAutomationGridItemPattern_get_CachedColumn ?
        get_CachedRowSpan           FIUIAutomationGridItemPattern_get_CachedRowSpan ?
        get_CachedColumnSpan        FIUIAutomationGridItemPattern_get_CachedColumnSpan ?
    STIUIAutomationGridItemPattern ENDS
 
    IUIAutomationGridItemPattern MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationGridItemPattern PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationGridItemPattern>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationGridItemPattern
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationGridItemPattern_INTERFACE_DEFINED__

IFNDEF __IUIAutomationMultipleViewPattern_INTERFACE_DEFINED__
    __IUIAutomationMultipleViewPattern_INTERFACE_DEFINED__  EQU 1

    IUIAutomationMultipleViewPattern_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationMultipleViewPattern_QueryInterface TYPEDEF PTR IUIAutomationMultipleViewPattern_QueryInterface

    IUIAutomationMultipleViewPattern_GetViewName TYPEDEF PROTO :XWORD, view:XWORD, aname:XWORD
    FIUIAutomationMultipleViewPattern_GetViewName TYPEDEF PTR IUIAutomationMultipleViewPattern_GetViewName

    IUIAutomationMultipleViewPattern_get_CurrentCurrentView TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationMultipleViewPattern_get_CurrentCurrentView TYPEDEF PTR IUIAutomationMultipleViewPattern_get_CurrentCurrentView

    IUIAutomationMultipleViewPattern_GetCurrentSupportedViews TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationMultipleViewPattern_GetCurrentSupportedViews TYPEDEF PTR IUIAutomationMultipleViewPattern_GetCurrentSupportedViews

    IUIAutomationMultipleViewPattern_get_CachedCurrentView TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationMultipleViewPattern_get_CachedCurrentView TYPEDEF PTR IUIAutomationMultipleViewPattern_get_CachedCurrentView

    IUIAutomationMultipleViewPattern_GetCachedSupportedViews TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationMultipleViewPattern_GetCachedSupportedViews TYPEDEF PTR IUIAutomationMultipleViewPattern_GetCachedSupportedViews

    STIUIAutomationMultipleViewPattern STRUCT
        QueryInterface              FIUIAutomationMultipleViewPattern_QueryInterface ?
        AddRef                      XPTR ?
        Release                     XPTR ?
        GetViewName                 FIUIAutomationMultipleViewPattern_GetViewName ?
        SetCurrentView              XPTR ?
        get_CurrentCurrentView      FIUIAutomationMultipleViewPattern_get_CurrentCurrentView ?
        GetCurrentSupportedViews    FIUIAutomationMultipleViewPattern_GetCurrentSupportedViews ?
        get_CachedCurrentView       FIUIAutomationMultipleViewPattern_get_CachedCurrentView ?
        GetCachedSupportedViews     FIUIAutomationMultipleViewPattern_GetCachedSupportedViews ?
    STIUIAutomationMultipleViewPattern ENDS
 
    IUIAutomationMultipleViewPattern MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationMultipleViewPattern PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationMultipleViewPattern>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationMultipleViewPattern
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationMultipleViewPattern_INTERFACE_DEFINED__

IFNDEF __IUIAutomationObjectModelPattern_INTERFACE_DEFINED__
    __IUIAutomationObjectModelPattern_INTERFACE_DEFINED__   EQU 1

    IUIAutomationObjectModelPattern_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationObjectModelPattern_QueryInterface TYPEDEF PTR IUIAutomationObjectModelPattern_QueryInterface

    IUIAutomationObjectModelPattern_GetUnderlyingObjectModel TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationObjectModelPattern_GetUnderlyingObjectModel TYPEDEF PTR IUIAutomationObjectModelPattern_GetUnderlyingObjectModel

    STIUIAutomationObjectModelPattern STRUCT
        QueryInterface              FIUIAutomationObjectModelPattern_QueryInterface ?
        AddRef                      XPTR ?
        Release                     XPTR ?
        GetUnderlyingObjectModel    FIUIAutomationObjectModelPattern_GetUnderlyingObjectModel ?
    STIUIAutomationObjectModelPattern ENDS
 
    IUIAutomationObjectModelPattern MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationObjectModelPattern PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationObjectModelPattern>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationObjectModelPattern
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationObjectModelPattern_INTERFACE_DEFINED__

IFNDEF __IUIAutomationRangeValuePattern_INTERFACE_DEFINED__
    __IUIAutomationRangeValuePattern_INTERFACE_DEFINED__    EQU 1

    IUIAutomationRangeValuePattern_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationRangeValuePattern_QueryInterface TYPEDEF PTR IUIAutomationRangeValuePattern_QueryInterface

    IUIAutomationRangeValuePattern_SetValue TYPEDEF PROTO :XWORD, val:REAL8 
    FIUIAutomationRangeValuePattern_SetValue TYPEDEF PTR IUIAutomationRangeValuePattern_SetValue

    IUIAutomationRangeValuePattern_get_CurrentValue TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationRangeValuePattern_get_CurrentValue TYPEDEF PTR IUIAutomationRangeValuePattern_get_CurrentValue

    IUIAutomationRangeValuePattern_get_CurrentIsReadOnly TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationRangeValuePattern_get_CurrentIsReadOnly TYPEDEF PTR IUIAutomationRangeValuePattern_get_CurrentIsReadOnly

    IUIAutomationRangeValuePattern_get_CurrentMaximum TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationRangeValuePattern_get_CurrentMaximum TYPEDEF PTR IUIAutomationRangeValuePattern_get_CurrentMaximum

    IUIAutomationRangeValuePattern_get_CurrentMinimum TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationRangeValuePattern_get_CurrentMinimum TYPEDEF PTR IUIAutomationRangeValuePattern_get_CurrentMinimum

    IUIAutomationRangeValuePattern_get_CurrentLargeChange TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationRangeValuePattern_get_CurrentLargeChange TYPEDEF PTR IUIAutomationRangeValuePattern_get_CurrentLargeChange

    IUIAutomationRangeValuePattern_get_CurrentSmallChange TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationRangeValuePattern_get_CurrentSmallChange TYPEDEF PTR IUIAutomationRangeValuePattern_get_CurrentSmallChange

    IUIAutomationRangeValuePattern_get_CachedValue TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationRangeValuePattern_get_CachedValue TYPEDEF PTR IUIAutomationRangeValuePattern_get_CachedValue

    IUIAutomationRangeValuePattern_get_CachedIsReadOnly TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationRangeValuePattern_get_CachedIsReadOnly TYPEDEF PTR IUIAutomationRangeValuePattern_get_CachedIsReadOnly

    IUIAutomationRangeValuePattern_get_CachedMaximum TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationRangeValuePattern_get_CachedMaximum TYPEDEF PTR IUIAutomationRangeValuePattern_get_CachedMaximum

    IUIAutomationRangeValuePattern_get_CachedMinimum TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationRangeValuePattern_get_CachedMinimum TYPEDEF PTR IUIAutomationRangeValuePattern_get_CachedMinimum

    IUIAutomationRangeValuePattern_get_CachedLargeChange TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationRangeValuePattern_get_CachedLargeChange TYPEDEF PTR IUIAutomationRangeValuePattern_get_CachedLargeChange

    IUIAutomationRangeValuePattern_get_CachedSmallChange TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationRangeValuePattern_get_CachedSmallChange TYPEDEF PTR IUIAutomationRangeValuePattern_get_CachedSmallChange

    STIUIAutomationRangeValuePattern STRUCT
        QueryInterface          FIUIAutomationRangeValuePattern_QueryInterface ?
        AddRef                  XPTR ?
        Release                 XPTR ?
        SetValue                FIUIAutomationRangeValuePattern_SetValue ?
        get_CurrentValue        FIUIAutomationRangeValuePattern_get_CurrentValue ?
        get_CurrentIsReadOnly   FIUIAutomationRangeValuePattern_get_CurrentIsReadOnly ?
        get_CurrentMaximum      FIUIAutomationRangeValuePattern_get_CurrentMaximum ?
        get_CurrentMinimum      FIUIAutomationRangeValuePattern_get_CurrentMinimum ?
        get_CurrentLargeChange  FIUIAutomationRangeValuePattern_get_CurrentLargeChange ?
        get_CurrentSmallChange  FIUIAutomationRangeValuePattern_get_CurrentSmallChange ?
        get_CachedValue         FIUIAutomationRangeValuePattern_get_CachedValue ?
        get_CachedIsReadOnly    FIUIAutomationRangeValuePattern_get_CachedIsReadOnly ?
        get_CachedMaximum       FIUIAutomationRangeValuePattern_get_CachedMaximum ?
        get_CachedMinimum       FIUIAutomationRangeValuePattern_get_CachedMinimum ?
        get_CachedLargeChange   FIUIAutomationRangeValuePattern_get_CachedLargeChange ?
        get_CachedSmallChange   FIUIAutomationRangeValuePattern_get_CachedSmallChange ?
    STIUIAutomationRangeValuePattern ENDS
 
    IUIAutomationRangeValuePattern MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationRangeValuePattern PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationRangeValuePattern>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationRangeValuePattern
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationRangeValuePattern_INTERFACE_DEFINED__

IFNDEF __IUIAutomationScrollPattern_INTERFACE_DEFINED__
    __IUIAutomationScrollPattern_INTERFACE_DEFINED__    EQU 1

    IUIAutomationScrollPattern_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationScrollPattern_QueryInterface TYPEDEF PTR IUIAutomationScrollPattern_QueryInterface

    IUIAutomationScrollPattern_SetScrollPercent TYPEDEF PROTO :XWORD, horizontalPercent:REAL8, verticalPercent:REAL8 
    FIUIAutomationScrollPattern_SetScrollPercent TYPEDEF PTR IUIAutomationScrollPattern_SetScrollPercent

    IUIAutomationScrollPattern_get_CurrentHorizontalScrollPercent TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationScrollPattern_get_CurrentHorizontalScrollPercent TYPEDEF PTR IUIAutomationScrollPattern_get_CurrentHorizontalScrollPercent

    IUIAutomationScrollPattern_get_CurrentVerticalScrollPercent TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationScrollPattern_get_CurrentVerticalScrollPercent TYPEDEF PTR IUIAutomationScrollPattern_get_CurrentVerticalScrollPercent

    IUIAutomationScrollPattern_get_CurrentHorizontalViewSize TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationScrollPattern_get_CurrentHorizontalViewSize TYPEDEF PTR IUIAutomationScrollPattern_get_CurrentHorizontalViewSize

    IUIAutomationScrollPattern_get_CurrentVerticalViewSize TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationScrollPattern_get_CurrentVerticalViewSize TYPEDEF PTR IUIAutomationScrollPattern_get_CurrentVerticalViewSize

    IUIAutomationScrollPattern_get_CurrentHorizontallyScrollable TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationScrollPattern_get_CurrentHorizontallyScrollable TYPEDEF PTR IUIAutomationScrollPattern_get_CurrentHorizontallyScrollable

    IUIAutomationScrollPattern_get_CurrentVerticallyScrollable TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationScrollPattern_get_CurrentVerticallyScrollable TYPEDEF PTR IUIAutomationScrollPattern_get_CurrentVerticallyScrollable

    IUIAutomationScrollPattern_get_CachedHorizontalScrollPercent TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationScrollPattern_get_CachedHorizontalScrollPercent TYPEDEF PTR IUIAutomationScrollPattern_get_CachedHorizontalScrollPercent

    IUIAutomationScrollPattern_get_CachedVerticalScrollPercent TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationScrollPattern_get_CachedVerticalScrollPercent TYPEDEF PTR IUIAutomationScrollPattern_get_CachedVerticalScrollPercent

    IUIAutomationScrollPattern_get_CachedHorizontalViewSize TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationScrollPattern_get_CachedHorizontalViewSize TYPEDEF PTR IUIAutomationScrollPattern_get_CachedHorizontalViewSize

    IUIAutomationScrollPattern_get_CachedVerticalViewSize TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationScrollPattern_get_CachedVerticalViewSize TYPEDEF PTR IUIAutomationScrollPattern_get_CachedVerticalViewSize

    IUIAutomationScrollPattern_get_CachedHorizontallyScrollable TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationScrollPattern_get_CachedHorizontallyScrollable TYPEDEF PTR IUIAutomationScrollPattern_get_CachedHorizontallyScrollable

    IUIAutomationScrollPattern_get_CachedVerticallyScrollable TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationScrollPattern_get_CachedVerticallyScrollable TYPEDEF PTR IUIAutomationScrollPattern_get_CachedVerticallyScrollable

    STIUIAutomationScrollPattern STRUCT
        QueryInterface                      FIUIAutomationScrollPattern_QueryInterface ?
        AddRef                              XPTR ?
        Release                             XPTR ?
        Scroll                              XPTR ?
        SetScrollPercent                    FIUIAutomationScrollPattern_SetScrollPercent ?
        get_CurrentHorizontalScrollPercent  FIUIAutomationScrollPattern_get_CurrentHorizontalScrollPercent ?
        get_CurrentVerticalScrollPercent    FIUIAutomationScrollPattern_get_CurrentVerticalScrollPercent ?
        get_CurrentHorizontalViewSize       FIUIAutomationScrollPattern_get_CurrentHorizontalViewSize ?
        get_CurrentVerticalViewSize         FIUIAutomationScrollPattern_get_CurrentVerticalViewSize ?
        get_CurrentHorizontallyScrollable   FIUIAutomationScrollPattern_get_CurrentHorizontallyScrollable ?
        get_CurrentVerticallyScrollable     FIUIAutomationScrollPattern_get_CurrentVerticallyScrollable ?
        get_CachedHorizontalScrollPercent   FIUIAutomationScrollPattern_get_CachedHorizontalScrollPercent ?
        get_CachedVerticalScrollPercent     FIUIAutomationScrollPattern_get_CachedVerticalScrollPercent ?
        get_CachedHorizontalViewSize        FIUIAutomationScrollPattern_get_CachedHorizontalViewSize ?
        get_CachedVerticalViewSize          FIUIAutomationScrollPattern_get_CachedVerticalViewSize ?
        get_CachedHorizontallyScrollable    FIUIAutomationScrollPattern_get_CachedHorizontallyScrollable ?
        get_CachedVerticallyScrollable      FIUIAutomationScrollPattern_get_CachedVerticallyScrollable ?
    STIUIAutomationScrollPattern ENDS

    IUIAutomationScrollPattern MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationScrollPattern PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationScrollPattern>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationScrollPattern
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationScrollPattern_INTERFACE_DEFINED__

IFNDEF __IUIAutomationScrollItemPattern_INTERFACE_DEFINED__
    __IUIAutomationScrollItemPattern_INTERFACE_DEFINED__    EQU 1

    IUIAutomationScrollItemPattern_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationScrollItemPattern_QueryInterface TYPEDEF PTR IUIAutomationScrollItemPattern_QueryInterface

    STIUIAutomationScrollItemPattern STRUCT
        QueryInterface  FIUIAutomationScrollItemPattern_QueryInterface ?
        AddRef          XPTR ?
        Release         XPTR ?
        ScrollIntoView  XPTR ?
    STIUIAutomationScrollItemPattern ENDS

    IUIAutomationScrollItemPattern MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationScrollItemPattern PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationScrollItemPattern>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationScrollItemPattern
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationScrollItemPattern_INTERFACE_DEFINED__

IFNDEF __IUIAutomationSelectionPattern_INTERFACE_DEFINED__
    __IUIAutomationSelectionPattern_INTERFACE_DEFINED__ EQU 1

    IUIAutomationSelectionPattern_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationSelectionPattern_QueryInterface TYPEDEF PTR IUIAutomationSelectionPattern_QueryInterface

    IUIAutomationSelectionPattern_GetCurrentSelection TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationSelectionPattern_GetCurrentSelection TYPEDEF PTR IUIAutomationSelectionPattern_GetCurrentSelection

    IUIAutomationSelectionPattern_get_CurrentCanSelectMultiple TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationSelectionPattern_get_CurrentCanSelectMultiple TYPEDEF PTR IUIAutomationSelectionPattern_get_CurrentCanSelectMultiple

    IUIAutomationSelectionPattern_get_CurrentIsSelectionRequired TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationSelectionPattern_get_CurrentIsSelectionRequired TYPEDEF PTR IUIAutomationSelectionPattern_get_CurrentIsSelectionRequired

    IUIAutomationSelectionPattern_GetCachedSelection TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationSelectionPattern_GetCachedSelection TYPEDEF PTR IUIAutomationSelectionPattern_GetCachedSelection

    IUIAutomationSelectionPattern_get_CachedCanSelectMultiple TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationSelectionPattern_get_CachedCanSelectMultiple TYPEDEF PTR IUIAutomationSelectionPattern_get_CachedCanSelectMultiple

    IUIAutomationSelectionPattern_get_CachedIsSelectionRequired TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationSelectionPattern_get_CachedIsSelectionRequired TYPEDEF PTR IUIAutomationSelectionPattern_get_CachedIsSelectionRequired

    STIUIAutomationSelectionPattern STRUCT
        QueryInterface                  FIUIAutomationSelectionPattern_QueryInterface ?
        AddRef                          XPTR ?
        Release                         XPTR ?
        GetCurrentSelection             FIUIAutomationSelectionPattern_GetCurrentSelection ?
        get_CurrentCanSelectMultiple    FIUIAutomationSelectionPattern_get_CurrentCanSelectMultiple ?
        get_CurrentIsSelectionRequired  FIUIAutomationSelectionPattern_get_CurrentIsSelectionRequired ?
        GetCachedSelection              FIUIAutomationSelectionPattern_GetCachedSelection ?
        get_CachedCanSelectMultiple     FIUIAutomationSelectionPattern_get_CachedCanSelectMultiple ?
        get_CachedIsSelectionRequired   FIUIAutomationSelectionPattern_get_CachedIsSelectionRequired ?
    STIUIAutomationSelectionPattern ENDS
 
    IUIAutomationSelectionPattern MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationSelectionPattern PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationSelectionPattern>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationSelectionPattern
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationSelectionPattern_INTERFACE_DEFINED__

IFNDEF __IUIAutomationSelectionItemPattern_INTERFACE_DEFINED__
    __IUIAutomationSelectionItemPattern_INTERFACE_DEFINED__ EQU 1

    IUIAutomationSelectionItemPattern_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationSelectionItemPattern_QueryInterface TYPEDEF PTR IUIAutomationSelectionItemPattern_QueryInterface

    IUIAutomationSelectionItemPattern_get_CurrentIsSelected TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationSelectionItemPattern_get_CurrentIsSelected TYPEDEF PTR IUIAutomationSelectionItemPattern_get_CurrentIsSelected

    IUIAutomationSelectionItemPattern_get_CurrentSelectionContainer TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationSelectionItemPattern_get_CurrentSelectionContainer TYPEDEF PTR IUIAutomationSelectionItemPattern_get_CurrentSelectionContainer

    IUIAutomationSelectionItemPattern_get_CachedIsSelected TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationSelectionItemPattern_get_CachedIsSelected TYPEDEF PTR IUIAutomationSelectionItemPattern_get_CachedIsSelected

    IUIAutomationSelectionItemPattern_get_CachedSelectionContainer TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationSelectionItemPattern_get_CachedSelectionContainer TYPEDEF PTR IUIAutomationSelectionItemPattern_get_CachedSelectionContainer

    STIUIAutomationSelectionItemPattern STRUCT
        QueryInterface                  FIUIAutomationSelectionItemPattern_QueryInterface ?
        AddRef                          XPTR ?
        Release                         XPTR ?
        Select1                         XPTR ?
        AddToSelection                  XPTR ?
        RemoveFromSelection             XPTR ?
        get_CurrentIsSelected           FIUIAutomationSelectionItemPattern_get_CurrentIsSelected ?
        get_CurrentSelectionContainer   FIUIAutomationSelectionItemPattern_get_CurrentSelectionContainer ?
        get_CachedIsSelected            FIUIAutomationSelectionItemPattern_get_CachedIsSelected ?
        get_CachedSelectionContainer    FIUIAutomationSelectionItemPattern_get_CachedSelectionContainer ?
    STIUIAutomationSelectionItemPattern ENDS
 
    IUIAutomationSelectionItemPattern MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationSelectionItemPattern PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationSelectionItemPattern>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationSelectionItemPattern
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationSelectionItemPattern_INTERFACE_DEFINED__

IFNDEF __IUIAutomationSynchronizedInputPattern_INTERFACE_DEFINED__
    __IUIAutomationSynchronizedInputPattern_INTERFACE_DEFINED__ EQU 1

    IUIAutomationSynchronizedInputPattern_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationSynchronizedInputPattern_QueryInterface TYPEDEF PTR IUIAutomationSynchronizedInputPattern_QueryInterface

    STIUIAutomationSynchronizedInputPattern STRUCT
        QueryInterface  FIUIAutomationSynchronizedInputPattern_QueryInterface ?
        AddRef          XPTR ?
        Release         XPTR ?
        StartListening  XPTR ?
        Cancel          XPTR ?
    STIUIAutomationSynchronizedInputPattern ENDS
 
    IUIAutomationSynchronizedInputPattern MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationSynchronizedInputPattern PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationSynchronizedInputPattern>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationSynchronizedInputPattern
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationSynchronizedInputPattern_INTERFACE_DEFINED__

IFNDEF __IUIAutomationTablePattern_INTERFACE_DEFINED__
    __IUIAutomationTablePattern_INTERFACE_DEFINED__ EQU 1

    IUIAutomationTablePattern_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationTablePattern_QueryInterface TYPEDEF PTR IUIAutomationTablePattern_QueryInterface

    IUIAutomationTablePattern_GetCurrentRowHeaders TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationTablePattern_GetCurrentRowHeaders TYPEDEF PTR IUIAutomationTablePattern_GetCurrentRowHeaders

    IUIAutomationTablePattern_GetCurrentColumnHeaders TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationTablePattern_GetCurrentColumnHeaders TYPEDEF PTR IUIAutomationTablePattern_GetCurrentColumnHeaders

    IUIAutomationTablePattern_get_CurrentRowOrColumnMajor TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationTablePattern_get_CurrentRowOrColumnMajor TYPEDEF PTR IUIAutomationTablePattern_get_CurrentRowOrColumnMajor

    IUIAutomationTablePattern_GetCachedRowHeaders TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationTablePattern_GetCachedRowHeaders TYPEDEF PTR IUIAutomationTablePattern_GetCachedRowHeaders

    IUIAutomationTablePattern_GetCachedColumnHeaders TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationTablePattern_GetCachedColumnHeaders TYPEDEF PTR IUIAutomationTablePattern_GetCachedColumnHeaders

    IUIAutomationTablePattern_get_CachedRowOrColumnMajor TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationTablePattern_get_CachedRowOrColumnMajor TYPEDEF PTR IUIAutomationTablePattern_get_CachedRowOrColumnMajor

    STIUIAutomationTablePattern STRUCT
        QueryInterface              FIUIAutomationTablePattern_QueryInterface ?
        AddRef                      XPTR ?
        Release                     XPTR ?
        GetCurrentRowHeaders        FIUIAutomationTablePattern_GetCurrentRowHeaders ?
        GetCurrentColumnHeaders     FIUIAutomationTablePattern_GetCurrentColumnHeaders ?
        get_CurrentRowOrColumnMajor FIUIAutomationTablePattern_get_CurrentRowOrColumnMajor ?
        GetCachedRowHeaders         FIUIAutomationTablePattern_GetCachedRowHeaders ?
        GetCachedColumnHeaders      FIUIAutomationTablePattern_GetCachedColumnHeaders ?
        get_CachedRowOrColumnMajor  FIUIAutomationTablePattern_get_CachedRowOrColumnMajor ?
    STIUIAutomationTablePattern ENDS
 
    IUIAutomationTablePattern MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationTablePattern PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationTablePattern>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationTablePattern
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationTablePattern_INTERFACE_DEFINED__

IFNDEF __IUIAutomationTableItemPattern_INTERFACE_DEFINED__
    __IUIAutomationTableItemPattern_INTERFACE_DEFINED__ EQU 1

    IUIAutomationTableItemPattern_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationTableItemPattern_QueryInterface TYPEDEF PTR IUIAutomationTableItemPattern_QueryInterface

    IUIAutomationTableItemPattern_GetCurrentRowHeaderItems TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationTableItemPattern_GetCurrentRowHeaderItems TYPEDEF PTR IUIAutomationTableItemPattern_GetCurrentRowHeaderItems

    IUIAutomationTableItemPattern_GetCurrentColumnHeaderItems TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationTableItemPattern_GetCurrentColumnHeaderItems TYPEDEF PTR IUIAutomationTableItemPattern_GetCurrentColumnHeaderItems

    IUIAutomationTableItemPattern_GetCachedRowHeaderItems TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationTableItemPattern_GetCachedRowHeaderItems TYPEDEF PTR IUIAutomationTableItemPattern_GetCachedRowHeaderItems

    IUIAutomationTableItemPattern_GetCachedColumnHeaderItems TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationTableItemPattern_GetCachedColumnHeaderItems TYPEDEF PTR IUIAutomationTableItemPattern_GetCachedColumnHeaderItems

    STIUIAutomationTableItemPattern STRUCT
        QueryInterface              FIUIAutomationTableItemPattern_QueryInterface ?
        AddRef                      XPTR ?
        Release                     XPTR ?
        GetCurrentRowHeaderItems    FIUIAutomationTableItemPattern_GetCurrentRowHeaderItems ?
        GetCurrentColumnHeaderItems FIUIAutomationTableItemPattern_GetCurrentColumnHeaderItems ?
        GetCachedRowHeaderItems     FIUIAutomationTableItemPattern_GetCachedRowHeaderItems ?
        GetCachedColumnHeaderItems  FIUIAutomationTableItemPattern_GetCachedColumnHeaderItems ?
    STIUIAutomationTableItemPattern ENDS
 
    IUIAutomationTableItemPattern MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationTableItemPattern PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationTableItemPattern>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationTableItemPattern
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationTableItemPattern_INTERFACE_DEFINED__

IFNDEF __IUIAutomationTogglePattern_INTERFACE_DEFINED__
    __IUIAutomationTogglePattern_INTERFACE_DEFINED__    EQU 1

    IUIAutomationTogglePattern_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationTogglePattern_QueryInterface TYPEDEF PTR IUIAutomationTogglePattern_QueryInterface

    IUIAutomationTogglePattern_get_CurrentToggleState TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationTogglePattern_get_CurrentToggleState TYPEDEF PTR IUIAutomationTogglePattern_get_CurrentToggleState

    IUIAutomationTogglePattern_get_CachedToggleState TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationTogglePattern_get_CachedToggleState TYPEDEF PTR IUIAutomationTogglePattern_get_CachedToggleState

    STIUIAutomationTogglePattern STRUCT
        QueryInterface          FIUIAutomationTogglePattern_QueryInterface ?
        AddRef                  XPTR ?
        Release                 XPTR ?
        Toggle                  XPTR ?
        get_CurrentToggleState  FIUIAutomationTogglePattern_get_CurrentToggleState ?
        get_CachedToggleState   FIUIAutomationTogglePattern_get_CachedToggleState ?
    STIUIAutomationTogglePattern ENDS
 
    IUIAutomationTogglePattern MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationTogglePattern PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationTogglePattern>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationTogglePattern
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationTogglePattern_INTERFACE_DEFINED__

IFNDEF __IUIAutomationTransformPattern_INTERFACE_DEFINED__
    __IUIAutomationTransformPattern_INTERFACE_DEFINED__ EQU 1

    IUIAutomationTransformPattern_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationTransformPattern_QueryInterface TYPEDEF PTR IUIAutomationTransformPattern_QueryInterface

    IUIAutomationTransformPattern_Move TYPEDEF PROTO :XWORD, x:REAL8, y:REAL8 
    FIUIAutomationTransformPattern_Move TYPEDEF PTR IUIAutomationTransformPattern_Move

    IUIAutomationTransformPattern_Resize TYPEDEF PROTO :XWORD, width1:REAL8, height:REAL8 
    FIUIAutomationTransformPattern_Resize TYPEDEF PTR IUIAutomationTransformPattern_Resize

    IUIAutomationTransformPattern_Rotate TYPEDEF PROTO :XWORD, degrees:REAL8 
    FIUIAutomationTransformPattern_Rotate TYPEDEF PTR IUIAutomationTransformPattern_Rotate

    IUIAutomationTransformPattern_get_CurrentCanMove TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationTransformPattern_get_CurrentCanMove TYPEDEF PTR IUIAutomationTransformPattern_get_CurrentCanMove

    IUIAutomationTransformPattern_get_CurrentCanResize TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationTransformPattern_get_CurrentCanResize TYPEDEF PTR IUIAutomationTransformPattern_get_CurrentCanResize

    IUIAutomationTransformPattern_get_CurrentCanRotate TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationTransformPattern_get_CurrentCanRotate TYPEDEF PTR IUIAutomationTransformPattern_get_CurrentCanRotate

    IUIAutomationTransformPattern_get_CachedCanMove TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationTransformPattern_get_CachedCanMove TYPEDEF PTR IUIAutomationTransformPattern_get_CachedCanMove

    IUIAutomationTransformPattern_get_CachedCanResize TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationTransformPattern_get_CachedCanResize TYPEDEF PTR IUIAutomationTransformPattern_get_CachedCanResize

    IUIAutomationTransformPattern_get_CachedCanRotate TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationTransformPattern_get_CachedCanRotate TYPEDEF PTR IUIAutomationTransformPattern_get_CachedCanRotate

    STIUIAutomationTransformPattern STRUCT
        QueryInterface          FIUIAutomationTransformPattern_QueryInterface ?
        AddRef                  XPTR ?
        Release                 XPTR ?
        Move                    FIUIAutomationTransformPattern_Move ?
        Resize                  FIUIAutomationTransformPattern_Resize ?
        Rotate                  FIUIAutomationTransformPattern_Rotate ?
        get_CurrentCanMove      FIUIAutomationTransformPattern_get_CurrentCanMove ?
        get_CurrentCanResize    FIUIAutomationTransformPattern_get_CurrentCanResize ?
        get_CurrentCanRotate    FIUIAutomationTransformPattern_get_CurrentCanRotate ?
        get_CachedCanMove       FIUIAutomationTransformPattern_get_CachedCanMove ?
        get_CachedCanResize     FIUIAutomationTransformPattern_get_CachedCanResize ?
        get_CachedCanRotate     FIUIAutomationTransformPattern_get_CachedCanRotate ?
    STIUIAutomationTransformPattern ENDS
 
    IUIAutomationTransformPattern MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationTransformPattern PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationTransformPattern>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationTransformPattern
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationTransformPattern_INTERFACE_DEFINED__

IFNDEF __IUIAutomationValuePattern_INTERFACE_DEFINED__
    __IUIAutomationValuePattern_INTERFACE_DEFINED__ EQU 1

    IUIAutomationValuePattern_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationValuePattern_QueryInterface TYPEDEF PTR IUIAutomationValuePattern_QueryInterface

    IUIAutomationValuePattern_SetValue TYPEDEF PROTO :XWORD, val:XWORD
    FIUIAutomationValuePattern_SetValue TYPEDEF PTR IUIAutomationValuePattern_SetValue

    IUIAutomationValuePattern_get_CurrentValue TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationValuePattern_get_CurrentValue TYPEDEF PTR IUIAutomationValuePattern_get_CurrentValue

    IUIAutomationValuePattern_get_CurrentIsReadOnly TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationValuePattern_get_CurrentIsReadOnly TYPEDEF PTR IUIAutomationValuePattern_get_CurrentIsReadOnly

    IUIAutomationValuePattern_get_CachedValue TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationValuePattern_get_CachedValue TYPEDEF PTR IUIAutomationValuePattern_get_CachedValue

    IUIAutomationValuePattern_get_CachedIsReadOnly TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationValuePattern_get_CachedIsReadOnly TYPEDEF PTR IUIAutomationValuePattern_get_CachedIsReadOnly

    STIUIAutomationValuePattern STRUCT
        QueryInterface          FIUIAutomationValuePattern_QueryInterface ?
        AddRef                  XPTR ?
        Release                 XPTR ?
        SetValue                FIUIAutomationValuePattern_SetValue ?
        get_CurrentValue        FIUIAutomationValuePattern_get_CurrentValue ?
        get_CurrentIsReadOnly   FIUIAutomationValuePattern_get_CurrentIsReadOnly ?
        get_CachedValue         FIUIAutomationValuePattern_get_CachedValue ?
        get_CachedIsReadOnly    FIUIAutomationValuePattern_get_CachedIsReadOnly ?
    STIUIAutomationValuePattern ENDS
 
    IUIAutomationValuePattern MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationValuePattern PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationValuePattern>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationValuePattern
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationValuePattern_INTERFACE_DEFINED__

IFNDEF __IUIAutomationWindowPattern_INTERFACE_DEFINED__
    __IUIAutomationWindowPattern_INTERFACE_DEFINED__    EQU 1

    IUIAutomationWindowPattern_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationWindowPattern_QueryInterface TYPEDEF PTR IUIAutomationWindowPattern_QueryInterface

    IUIAutomationWindowPattern_WaitForInputIdle1 TYPEDEF PROTO :XWORD, milliseconds:XWORD, success:XWORD
    FIUIAutomationWindowPattern_WaitForInputIdle1 TYPEDEF PTR IUIAutomationWindowPattern_WaitForInputIdle1

    IUIAutomationWindowPattern_get_CurrentCanMaximize TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationWindowPattern_get_CurrentCanMaximize TYPEDEF PTR IUIAutomationWindowPattern_get_CurrentCanMaximize

    IUIAutomationWindowPattern_get_CurrentCanMinimize TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationWindowPattern_get_CurrentCanMinimize TYPEDEF PTR IUIAutomationWindowPattern_get_CurrentCanMinimize

    IUIAutomationWindowPattern_get_CurrentIsModal TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationWindowPattern_get_CurrentIsModal TYPEDEF PTR IUIAutomationWindowPattern_get_CurrentIsModal

    IUIAutomationWindowPattern_get_CurrentIsTopmost TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationWindowPattern_get_CurrentIsTopmost TYPEDEF PTR IUIAutomationWindowPattern_get_CurrentIsTopmost

    IUIAutomationWindowPattern_get_CurrentWindowVisualState TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationWindowPattern_get_CurrentWindowVisualState TYPEDEF PTR IUIAutomationWindowPattern_get_CurrentWindowVisualState

    IUIAutomationWindowPattern_get_CurrentWindowInteractionState TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationWindowPattern_get_CurrentWindowInteractionState TYPEDEF PTR IUIAutomationWindowPattern_get_CurrentWindowInteractionState

    IUIAutomationWindowPattern_get_CachedCanMaximize TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationWindowPattern_get_CachedCanMaximize TYPEDEF PTR IUIAutomationWindowPattern_get_CachedCanMaximize

    IUIAutomationWindowPattern_get_CachedCanMinimize TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationWindowPattern_get_CachedCanMinimize TYPEDEF PTR IUIAutomationWindowPattern_get_CachedCanMinimize

    IUIAutomationWindowPattern_get_CachedIsModal TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationWindowPattern_get_CachedIsModal TYPEDEF PTR IUIAutomationWindowPattern_get_CachedIsModal

    IUIAutomationWindowPattern_get_CachedIsTopmost TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationWindowPattern_get_CachedIsTopmost TYPEDEF PTR IUIAutomationWindowPattern_get_CachedIsTopmost

    IUIAutomationWindowPattern_get_CachedWindowVisualState TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationWindowPattern_get_CachedWindowVisualState TYPEDEF PTR IUIAutomationWindowPattern_get_CachedWindowVisualState

    IUIAutomationWindowPattern_get_CachedWindowInteractionState TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationWindowPattern_get_CachedWindowInteractionState TYPEDEF PTR IUIAutomationWindowPattern_get_CachedWindowInteractionState

    STIUIAutomationWindowPattern STRUCT
        QueryInterface                      FIUIAutomationWindowPattern_QueryInterface ?
        AddRef                              XPTR ?
        Release                             XPTR ?
        Close                               XPTR ?
        WaitForInputIdle1                   FIUIAutomationWindowPattern_WaitForInputIdle1 ?
        SetWindowVisualState                XPTR ?
        get_CurrentCanMaximize              FIUIAutomationWindowPattern_get_CurrentCanMaximize ?
        get_CurrentCanMinimize              FIUIAutomationWindowPattern_get_CurrentCanMinimize ?
        get_CurrentIsModal                  FIUIAutomationWindowPattern_get_CurrentIsModal ?
        get_CurrentIsTopmost                FIUIAutomationWindowPattern_get_CurrentIsTopmost ?
        get_CurrentWindowVisualState        FIUIAutomationWindowPattern_get_CurrentWindowVisualState ?
        get_CurrentWindowInteractionState   FIUIAutomationWindowPattern_get_CurrentWindowInteractionState ?
        get_CachedCanMaximize               FIUIAutomationWindowPattern_get_CachedCanMaximize ?
        get_CachedCanMinimize               FIUIAutomationWindowPattern_get_CachedCanMinimize ?
        get_CachedIsModal                   FIUIAutomationWindowPattern_get_CachedIsModal ?
        get_CachedIsTopmost                 FIUIAutomationWindowPattern_get_CachedIsTopmost ?
        get_CachedWindowVisualState         FIUIAutomationWindowPattern_get_CachedWindowVisualState ?
        get_CachedWindowInteractionState    FIUIAutomationWindowPattern_get_CachedWindowInteractionState ?
    STIUIAutomationWindowPattern ENDS
 
    IUIAutomationWindowPattern MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationWindowPattern PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationWindowPattern>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationWindowPattern
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationWindowPattern_INTERFACE_DEFINED__

IFNDEF __IUIAutomationTextRange_INTERFACE_DEFINED__
    __IUIAutomationTextRange_INTERFACE_DEFINED__    EQU 1

    IUIAutomationTextRange_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationTextRange_QueryInterface TYPEDEF PTR IUIAutomationTextRange_QueryInterface

    IUIAutomationTextRange_Clone TYPEDEF PROTO :XWORD, clonedRange:XWORD
    FIUIAutomationTextRange_Clone TYPEDEF PTR IUIAutomationTextRange_Clone

    IUIAutomationTextRange_Compare TYPEDEF PROTO :XWORD, range:XWORD, areSame:XWORD
    FIUIAutomationTextRange_Compare TYPEDEF PTR IUIAutomationTextRange_Compare

    IUIAutomationTextRange_CompareEndpoints TYPEDEF PROTO :XWORD, srcEndPoint:XWORD, range:XWORD, targetEndPoint:XWORD, compValue:XWORD
    FIUIAutomationTextRange_CompareEndpoints TYPEDEF PTR IUIAutomationTextRange_CompareEndpoints

    IUIAutomationTextRange_FindAttribute TYPEDEF PROTO :XWORD, attr:XWORD, val:VARIANT, backward:XWORD, found:XWORD
    FIUIAutomationTextRange_FindAttribute TYPEDEF PTR IUIAutomationTextRange_FindAttribute

    IUIAutomationTextRange_FindText1 TYPEDEF PROTO :XWORD, text:XWORD, backward:XWORD, ignoreCase:XWORD, found:XWORD
    FIUIAutomationTextRange_FindText1 TYPEDEF PTR IUIAutomationTextRange_FindText1

    IUIAutomationTextRange_GetAttributeValue TYPEDEF PROTO :XWORD, attr:XWORD, value:XWORD
    FIUIAutomationTextRange_GetAttributeValue TYPEDEF PTR IUIAutomationTextRange_GetAttributeValue

    IUIAutomationTextRange_GetBoundingRectangles TYPEDEF PROTO :XWORD, boundingRects:XWORD
    FIUIAutomationTextRange_GetBoundingRectangles TYPEDEF PTR IUIAutomationTextRange_GetBoundingRectangles

    IUIAutomationTextRange_GetEnclosingElement TYPEDEF PROTO :XWORD, enclosingElement:XWORD
    FIUIAutomationTextRange_GetEnclosingElement TYPEDEF PTR IUIAutomationTextRange_GetEnclosingElement

    IUIAutomationTextRange_GetText TYPEDEF PROTO :XWORD, maxLength:XWORD, text:XWORD
    FIUIAutomationTextRange_GetText TYPEDEF PTR IUIAutomationTextRange_GetText

    IUIAutomationTextRange_Move TYPEDEF PROTO :XWORD, unit:XWORD, count:XWORD, moved:XWORD
    FIUIAutomationTextRange_Move TYPEDEF PTR IUIAutomationTextRange_Move

    IUIAutomationTextRange_MoveEndpointByUnit TYPEDEF PROTO :XWORD, endpoint:XWORD, unit:XWORD, count:XWORD, moved:XWORD
    FIUIAutomationTextRange_MoveEndpointByUnit TYPEDEF PTR IUIAutomationTextRange_MoveEndpointByUnit

    IUIAutomationTextRange_MoveEndpointByRange TYPEDEF PROTO :XWORD, srcEndPoint:XWORD, range:XWORD, targetEndPoint:XWORD 
    FIUIAutomationTextRange_MoveEndpointByRange TYPEDEF PTR IUIAutomationTextRange_MoveEndpointByRange

    IUIAutomationTextRange_GetChildren TYPEDEF PROTO :XWORD, children:XWORD
    FIUIAutomationTextRange_GetChildren TYPEDEF PTR IUIAutomationTextRange_GetChildren

    STIUIAutomationTextRange STRUCT
        QueryInterface          FIUIAutomationTextRange_QueryInterface ?
        AddRef                  XPTR ?
        Release                 XPTR ?
        Clone                   FIUIAutomationTextRange_Clone ?
        Compare                 FIUIAutomationTextRange_Compare ?
        CompareEndpoints        FIUIAutomationTextRange_CompareEndpoints ?
        ExpandToEnclosingUnit   XPTR ?
        FindAttribute           FIUIAutomationTextRange_FindAttribute ?
        FindText1               FIUIAutomationTextRange_FindText1 ?
        GetAttributeValue       FIUIAutomationTextRange_GetAttributeValue ?
        GetBoundingRectangles   FIUIAutomationTextRange_GetBoundingRectangles ?
        GetEnclosingElement     FIUIAutomationTextRange_GetEnclosingElement ?
        GetText                 FIUIAutomationTextRange_GetText ?
        Move                    FIUIAutomationTextRange_Move ?
        MoveEndpointByUnit      FIUIAutomationTextRange_MoveEndpointByUnit ?
        MoveEndpointByRange     FIUIAutomationTextRange_MoveEndpointByRange ?
        Select1                 XPTR ?
        AddToSelection          XPTR ?
        RemoveFromSelection     XPTR ?
        ScrollIntoView          XPTR ?
        GetChildren             FIUIAutomationTextRange_GetChildren ?
    STIUIAutomationTextRange ENDS
 
    IUIAutomationTextRange MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationTextRange PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationTextRange>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationTextRange
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationTextRange_INTERFACE_DEFINED__

IFNDEF __IUIAutomationTextRange2_INTERFACE_DEFINED__
    __IUIAutomationTextRange2_INTERFACE_DEFINED__   EQU 1

    IUIAutomationTextRange2_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationTextRange2_QueryInterface TYPEDEF PTR IUIAutomationTextRange2_QueryInterface

    IUIAutomationTextRange2_Clone TYPEDEF PROTO :XWORD, clonedRange:XWORD
    FIUIAutomationTextRange2_Clone TYPEDEF PTR IUIAutomationTextRange2_Clone

    IUIAutomationTextRange2_Compare TYPEDEF PROTO :XWORD, range:XWORD, areSame:XWORD
    FIUIAutomationTextRange2_Compare TYPEDEF PTR IUIAutomationTextRange2_Compare

    IUIAutomationTextRange2_CompareEndpoints TYPEDEF PROTO :XWORD, srcEndPoint:XWORD, range:XWORD, targetEndPoint:XWORD, compValue:XWORD
    FIUIAutomationTextRange2_CompareEndpoints TYPEDEF PTR IUIAutomationTextRange2_CompareEndpoints

    IUIAutomationTextRange2_FindAttribute TYPEDEF PROTO :XWORD, attr:XWORD, val:VARIANT, backward:XWORD, found:XWORD
    FIUIAutomationTextRange2_FindAttribute TYPEDEF PTR IUIAutomationTextRange2_FindAttribute

    IUIAutomationTextRange2_FindText1 TYPEDEF PROTO :XWORD, text:XWORD, backward:XWORD, ignoreCase:XWORD, found:XWORD
    FIUIAutomationTextRange2_FindText1 TYPEDEF PTR IUIAutomationTextRange2_FindText1

    IUIAutomationTextRange2_GetAttributeValue TYPEDEF PROTO :XWORD, attr:XWORD, value:XWORD
    FIUIAutomationTextRange2_GetAttributeValue TYPEDEF PTR IUIAutomationTextRange2_GetAttributeValue

    IUIAutomationTextRange2_GetBoundingRectangles TYPEDEF PROTO :XWORD, boundingRects:XWORD
    FIUIAutomationTextRange2_GetBoundingRectangles TYPEDEF PTR IUIAutomationTextRange2_GetBoundingRectangles

    IUIAutomationTextRange2_GetEnclosingElement TYPEDEF PROTO :XWORD, enclosingElement:XWORD
    FIUIAutomationTextRange2_GetEnclosingElement TYPEDEF PTR IUIAutomationTextRange2_GetEnclosingElement

    IUIAutomationTextRange2_GetText TYPEDEF PROTO :XWORD, maxLength:XWORD, text:XWORD
    FIUIAutomationTextRange2_GetText TYPEDEF PTR IUIAutomationTextRange2_GetText

    IUIAutomationTextRange2_Move TYPEDEF PROTO :XWORD, unit:XWORD, count:XWORD, moved:XWORD
    FIUIAutomationTextRange2_Move TYPEDEF PTR IUIAutomationTextRange2_Move

    IUIAutomationTextRange2_MoveEndpointByUnit TYPEDEF PROTO :XWORD, endpoint:XWORD, unit:XWORD, count:XWORD, moved:XWORD
    FIUIAutomationTextRange2_MoveEndpointByUnit TYPEDEF PTR IUIAutomationTextRange2_MoveEndpointByUnit

    IUIAutomationTextRange2_MoveEndpointByRange TYPEDEF PROTO :XWORD, srcEndPoint:XWORD, range:XWORD, targetEndPoint:XWORD 
    FIUIAutomationTextRange2_MoveEndpointByRange TYPEDEF PTR IUIAutomationTextRange2_MoveEndpointByRange

    IUIAutomationTextRange2_GetChildren TYPEDEF PROTO :XWORD, children:XWORD
    FIUIAutomationTextRange2_GetChildren TYPEDEF PTR IUIAutomationTextRange2_GetChildren

    STIUIAutomationTextRange2 STRUCT
        QueryInterface          FIUIAutomationTextRange2_QueryInterface ?
        AddRef                  XPTR ?
        Release                 XPTR ?
        Clone                   FIUIAutomationTextRange2_Clone ?
        Compare                 FIUIAutomationTextRange2_Compare ?
        CompareEndpoints        FIUIAutomationTextRange2_CompareEndpoints ?
        ExpandToEnclosingUnit   XPTR ?
        FindAttribute           FIUIAutomationTextRange2_FindAttribute ?
        FindText1               FIUIAutomationTextRange2_FindText1 ?
        GetAttributeValue       FIUIAutomationTextRange2_GetAttributeValue ?
        GetBoundingRectangles   FIUIAutomationTextRange2_GetBoundingRectangles ?
        GetEnclosingElement     FIUIAutomationTextRange2_GetEnclosingElement ?
        GetText                 FIUIAutomationTextRange2_GetText ?
        Move                    FIUIAutomationTextRange2_Move ?
        MoveEndpointByUnit      FIUIAutomationTextRange2_MoveEndpointByUnit ?
        MoveEndpointByRange     FIUIAutomationTextRange2_MoveEndpointByRange ?
        Select1                 XPTR ?
        AddToSelection          XPTR ?
        RemoveFromSelection     XPTR ?
        ScrollIntoView          XPTR ?
        GetChildren             FIUIAutomationTextRange2_GetChildren ?
        ShowContextMenu         XPTR ?
    STIUIAutomationTextRange2 ENDS
 
    IUIAutomationTextRange2 MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationTextRange2 PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationTextRange2>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationTextRange2
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationTextRange2_INTERFACE_DEFINED__

IFNDEF __IUIAutomationTextRangeArray_INTERFACE_DEFINED__
    __IUIAutomationTextRangeArray_INTERFACE_DEFINED__   EQU 1

    IUIAutomationTextRangeArray_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationTextRangeArray_QueryInterface TYPEDEF PTR IUIAutomationTextRangeArray_QueryInterface

    IUIAutomationTextRangeArray_get_Length TYPEDEF PROTO :XWORD, length1:XWORD
    FIUIAutomationTextRangeArray_get_Length TYPEDEF PTR IUIAutomationTextRangeArray_get_Length

    IUIAutomationTextRangeArray_GetElement TYPEDEF PROTO :XWORD, index:XWORD, element:XWORD
    FIUIAutomationTextRangeArray_GetElement TYPEDEF PTR IUIAutomationTextRangeArray_GetElement

    STIUIAutomationTextRangeArray STRUCT
        QueryInterface  FIUIAutomationTextRangeArray_QueryInterface ?
        AddRef          XPTR ?
        Release         XPTR ?
        get_Length      FIUIAutomationTextRangeArray_get_Length ?
        GetElement      FIUIAutomationTextRangeArray_GetElement ?
    STIUIAutomationTextRangeArray ENDS
 
    IUIAutomationTextRangeArray MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationTextRangeArray PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationTextRangeArray>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationTextRangeArray
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationTextRangeArray_INTERFACE_DEFINED__

IFNDEF __IUIAutomationTextPattern_INTERFACE_DEFINED__
    __IUIAutomationTextPattern_INTERFACE_DEFINED__  EQU 1

    IUIAutomationTextPattern_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationTextPattern_QueryInterface TYPEDEF PTR IUIAutomationTextPattern_QueryInterface

    IUIAutomationTextPattern_RangeFromPoint TYPEDEF PROTO :XWORD, pt:POINT, range:XWORD
    FIUIAutomationTextPattern_RangeFromPoint TYPEDEF PTR IUIAutomationTextPattern_RangeFromPoint

    IUIAutomationTextPattern_RangeFromChild TYPEDEF PROTO :XWORD, child:XWORD, range:XWORD
    FIUIAutomationTextPattern_RangeFromChild TYPEDEF PTR IUIAutomationTextPattern_RangeFromChild

    IUIAutomationTextPattern_GetSelection TYPEDEF PROTO :XWORD, ranges:XWORD
    FIUIAutomationTextPattern_GetSelection TYPEDEF PTR IUIAutomationTextPattern_GetSelection

    IUIAutomationTextPattern_GetVisibleRanges TYPEDEF PROTO :XWORD, ranges:XWORD
    FIUIAutomationTextPattern_GetVisibleRanges TYPEDEF PTR IUIAutomationTextPattern_GetVisibleRanges

    IUIAutomationTextPattern_get_DocumentRange TYPEDEF PROTO :XWORD, range:XWORD
    FIUIAutomationTextPattern_get_DocumentRange TYPEDEF PTR IUIAutomationTextPattern_get_DocumentRange

    IUIAutomationTextPattern_get_SupportedTextSelection TYPEDEF PROTO :XWORD, supportedTextSelection:XWORD
    FIUIAutomationTextPattern_get_SupportedTextSelection TYPEDEF PTR IUIAutomationTextPattern_get_SupportedTextSelection

    STIUIAutomationTextPattern STRUCT
        QueryInterface              FIUIAutomationTextPattern_QueryInterface ?
        AddRef                      XPTR ?
        Release                     XPTR ?
        RangeFromPoint              FIUIAutomationTextPattern_RangeFromPoint ?
        RangeFromChild              FIUIAutomationTextPattern_RangeFromChild ?
        GetSelection                FIUIAutomationTextPattern_GetSelection ?
        GetVisibleRanges            FIUIAutomationTextPattern_GetVisibleRanges ?
        get_DocumentRange           FIUIAutomationTextPattern_get_DocumentRange ?
        get_SupportedTextSelection  FIUIAutomationTextPattern_get_SupportedTextSelection ?
    STIUIAutomationTextPattern ENDS
 
    IUIAutomationTextPattern MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationTextPattern PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationTextPattern>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationTextPattern
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationTextPattern_INTERFACE_DEFINED__

IFNDEF __IUIAutomationTextPattern2_INTERFACE_DEFINED__
    __IUIAutomationTextPattern2_INTERFACE_DEFINED__ EQU 1

    IUIAutomationTextPattern2_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationTextPattern2_QueryInterface TYPEDEF PTR IUIAutomationTextPattern2_QueryInterface

    IUIAutomationTextPattern2_RangeFromPoint TYPEDEF PROTO :XWORD, pt:POINT, range:XWORD
    FIUIAutomationTextPattern2_RangeFromPoint TYPEDEF PTR IUIAutomationTextPattern2_RangeFromPoint

    IUIAutomationTextPattern2_RangeFromChild TYPEDEF PROTO :XWORD, child:XWORD, range:XWORD
    FIUIAutomationTextPattern2_RangeFromChild TYPEDEF PTR IUIAutomationTextPattern2_RangeFromChild

    IUIAutomationTextPattern2_GetSelection TYPEDEF PROTO :XWORD, ranges:XWORD
    FIUIAutomationTextPattern2_GetSelection TYPEDEF PTR IUIAutomationTextPattern2_GetSelection

    IUIAutomationTextPattern2_GetVisibleRanges TYPEDEF PROTO :XWORD, ranges:XWORD
    FIUIAutomationTextPattern2_GetVisibleRanges TYPEDEF PTR IUIAutomationTextPattern2_GetVisibleRanges

    IUIAutomationTextPattern2_get_DocumentRange TYPEDEF PROTO :XWORD, range:XWORD
    FIUIAutomationTextPattern2_get_DocumentRange TYPEDEF PTR IUIAutomationTextPattern2_get_DocumentRange

    IUIAutomationTextPattern2_get_SupportedTextSelection TYPEDEF PROTO :XWORD, supportedTextSelection:XWORD
    FIUIAutomationTextPattern2_get_SupportedTextSelection TYPEDEF PTR IUIAutomationTextPattern2_get_SupportedTextSelection

    IUIAutomationTextPattern2_RangeFromAnnotation TYPEDEF PROTO :XWORD, annotation:XWORD, range:XWORD
    FIUIAutomationTextPattern2_RangeFromAnnotation TYPEDEF PTR IUIAutomationTextPattern2_RangeFromAnnotation

    IUIAutomationTextPattern2_GetCaretRange TYPEDEF PROTO :XWORD, isActive:XWORD, range:XWORD
    FIUIAutomationTextPattern2_GetCaretRange TYPEDEF PTR IUIAutomationTextPattern2_GetCaretRange

    STIUIAutomationTextPattern2 STRUCT
        QueryInterface              FIUIAutomationTextPattern2_QueryInterface ?
        AddRef                      XPTR ?
        Release                     XPTR ?
        RangeFromPoint              FIUIAutomationTextPattern2_RangeFromPoint ?
        RangeFromChild              FIUIAutomationTextPattern2_RangeFromChild ?
        GetSelection                FIUIAutomationTextPattern2_GetSelection ?
        GetVisibleRanges            FIUIAutomationTextPattern2_GetVisibleRanges ?
        get_DocumentRange           FIUIAutomationTextPattern2_get_DocumentRange ?
        get_SupportedTextSelection  FIUIAutomationTextPattern2_get_SupportedTextSelection ?
        RangeFromAnnotation         FIUIAutomationTextPattern2_RangeFromAnnotation ?
        GetCaretRange               FIUIAutomationTextPattern2_GetCaretRange ?
    STIUIAutomationTextPattern2 ENDS
 
    IUIAutomationTextPattern2 MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationTextPattern2 PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationTextPattern2>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationTextPattern2
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationTextPattern2_INTERFACE_DEFINED__

IFNDEF __IUIAutomationTextEditPattern_INTERFACE_DEFINED__
    __IUIAutomationTextEditPattern_INTERFACE_DEFINED__  EQU 1

    IUIAutomationTextEditPattern_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationTextEditPattern_QueryInterface TYPEDEF PTR IUIAutomationTextEditPattern_QueryInterface

    IUIAutomationTextEditPattern_RangeFromPoint TYPEDEF PROTO :XWORD, pt:POINT, range:XWORD
    FIUIAutomationTextEditPattern_RangeFromPoint TYPEDEF PTR IUIAutomationTextEditPattern_RangeFromPoint

    IUIAutomationTextEditPattern_RangeFromChild TYPEDEF PROTO :XWORD, child:XWORD, range:XWORD
    FIUIAutomationTextEditPattern_RangeFromChild TYPEDEF PTR IUIAutomationTextEditPattern_RangeFromChild

    IUIAutomationTextEditPattern_GetSelection TYPEDEF PROTO :XWORD, ranges:XWORD
    FIUIAutomationTextEditPattern_GetSelection TYPEDEF PTR IUIAutomationTextEditPattern_GetSelection

    IUIAutomationTextEditPattern_GetVisibleRanges TYPEDEF PROTO :XWORD, ranges:XWORD
    FIUIAutomationTextEditPattern_GetVisibleRanges TYPEDEF PTR IUIAutomationTextEditPattern_GetVisibleRanges

    IUIAutomationTextEditPattern_get_DocumentRange TYPEDEF PROTO :XWORD, range:XWORD
    FIUIAutomationTextEditPattern_get_DocumentRange TYPEDEF PTR IUIAutomationTextEditPattern_get_DocumentRange

    IUIAutomationTextEditPattern_get_SupportedTextSelection TYPEDEF PROTO :XWORD, supportedTextSelection:XWORD
    FIUIAutomationTextEditPattern_get_SupportedTextSelection TYPEDEF PTR IUIAutomationTextEditPattern_get_SupportedTextSelection

    IUIAutomationTextEditPattern_GetActiveComposition TYPEDEF PROTO :XWORD, range:XWORD
    FIUIAutomationTextEditPattern_GetActiveComposition TYPEDEF PTR IUIAutomationTextEditPattern_GetActiveComposition

    IUIAutomationTextEditPattern_GetConversionTarget TYPEDEF PROTO :XWORD, range:XWORD
    FIUIAutomationTextEditPattern_GetConversionTarget TYPEDEF PTR IUIAutomationTextEditPattern_GetConversionTarget

    STIUIAutomationTextEditPattern STRUCT
        QueryInterface              FIUIAutomationTextEditPattern_QueryInterface ?
        AddRef                      XPTR ?
        Release                     XPTR ?
        RangeFromPoint              FIUIAutomationTextEditPattern_RangeFromPoint ?
        RangeFromChild              FIUIAutomationTextEditPattern_RangeFromChild ?
        GetSelection                FIUIAutomationTextEditPattern_GetSelection ?
        GetVisibleRanges            FIUIAutomationTextEditPattern_GetVisibleRanges ?
        get_DocumentRange           FIUIAutomationTextEditPattern_get_DocumentRange ?
        get_SupportedTextSelection  FIUIAutomationTextEditPattern_get_SupportedTextSelection ?
        GetActiveComposition        FIUIAutomationTextEditPattern_GetActiveComposition ?
        GetConversionTarget         FIUIAutomationTextEditPattern_GetConversionTarget ?
    STIUIAutomationTextEditPattern ENDS
 
    IUIAutomationTextEditPattern MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationTextEditPattern PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationTextEditPattern>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationTextEditPattern
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationTextEditPattern_INTERFACE_DEFINED__

IFNDEF __IUIAutomationCustomNavigationPattern_INTERFACE_DEFINED__
    __IUIAutomationCustomNavigationPattern_INTERFACE_DEFINED__  EQU 1

    IUIAutomationCustomNavigationPattern_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationCustomNavigationPattern_QueryInterface TYPEDEF PTR IUIAutomationCustomNavigationPattern_QueryInterface

    IUIAutomationCustomNavigationPattern_Navigate TYPEDEF PROTO :XWORD, direction:XWORD, pRetVal:XWORD
    FIUIAutomationCustomNavigationPattern_Navigate TYPEDEF PTR IUIAutomationCustomNavigationPattern_Navigate

    STIUIAutomationCustomNavigationPattern STRUCT
        QueryInterface  FIUIAutomationCustomNavigationPattern_QueryInterface ?
        AddRef          XPTR ?
        Release         XPTR ?
        Navigate        FIUIAutomationCustomNavigationPattern_Navigate ?
    STIUIAutomationCustomNavigationPattern ENDS
 
    IUIAutomationCustomNavigationPattern MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationCustomNavigationPattern PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationCustomNavigationPattern>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationCustomNavigationPattern
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationCustomNavigationPattern_INTERFACE_DEFINED__

IFNDEF __IUIAutomationLegacyIAccessiblePattern_INTERFACE_DEFINED__
    __IUIAutomationLegacyIAccessiblePattern_INTERFACE_DEFINED__ EQU 1

    IUIAutomationLegacyIAccessiblePattern_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationLegacyIAccessiblePattern_QueryInterface TYPEDEF PTR IUIAutomationLegacyIAccessiblePattern_QueryInterface

    IUIAutomationLegacyIAccessiblePattern_SetValue TYPEDEF PROTO :XWORD, szValue:XWORD
    FIUIAutomationLegacyIAccessiblePattern_SetValue TYPEDEF PTR IUIAutomationLegacyIAccessiblePattern_SetValue

    IUIAutomationLegacyIAccessiblePattern_get_CurrentChildId TYPEDEF PROTO :XWORD, pRetVal:XWORD
    FIUIAutomationLegacyIAccessiblePattern_get_CurrentChildId TYPEDEF PTR IUIAutomationLegacyIAccessiblePattern_get_CurrentChildId

    IUIAutomationLegacyIAccessiblePattern_get_CurrentName TYPEDEF PROTO :XWORD, pszName:XWORD
    FIUIAutomationLegacyIAccessiblePattern_get_CurrentName TYPEDEF PTR IUIAutomationLegacyIAccessiblePattern_get_CurrentName

    IUIAutomationLegacyIAccessiblePattern_get_CurrentValue TYPEDEF PROTO :XWORD, pszValue:XWORD
    FIUIAutomationLegacyIAccessiblePattern_get_CurrentValue TYPEDEF PTR IUIAutomationLegacyIAccessiblePattern_get_CurrentValue

    IUIAutomationLegacyIAccessiblePattern_get_CurrentDescription TYPEDEF PROTO :XWORD, pszDescription:XWORD
    FIUIAutomationLegacyIAccessiblePattern_get_CurrentDescription TYPEDEF PTR IUIAutomationLegacyIAccessiblePattern_get_CurrentDescription

    IUIAutomationLegacyIAccessiblePattern_get_CurrentRole TYPEDEF PROTO :XWORD, pdwRole:XWORD
    FIUIAutomationLegacyIAccessiblePattern_get_CurrentRole TYPEDEF PTR IUIAutomationLegacyIAccessiblePattern_get_CurrentRole

    IUIAutomationLegacyIAccessiblePattern_get_CurrentState TYPEDEF PROTO :XWORD, pdwState:XWORD
    FIUIAutomationLegacyIAccessiblePattern_get_CurrentState TYPEDEF PTR IUIAutomationLegacyIAccessiblePattern_get_CurrentState

    IUIAutomationLegacyIAccessiblePattern_get_CurrentHelp TYPEDEF PROTO :XWORD, pszHelp:XWORD
    FIUIAutomationLegacyIAccessiblePattern_get_CurrentHelp TYPEDEF PTR IUIAutomationLegacyIAccessiblePattern_get_CurrentHelp

    IUIAutomationLegacyIAccessiblePattern_get_CurrentKeyboardShortcut TYPEDEF PROTO :XWORD, pszKeyboardShortcut:XWORD
    FIUIAutomationLegacyIAccessiblePattern_get_CurrentKeyboardShortcut TYPEDEF PTR IUIAutomationLegacyIAccessiblePattern_get_CurrentKeyboardShortcut

    IUIAutomationLegacyIAccessiblePattern_GetCurrentSelection TYPEDEF PROTO :XWORD, pvarSelectedChildren:XWORD
    FIUIAutomationLegacyIAccessiblePattern_GetCurrentSelection TYPEDEF PTR IUIAutomationLegacyIAccessiblePattern_GetCurrentSelection

    IUIAutomationLegacyIAccessiblePattern_get_CurrentDefaultAction TYPEDEF PROTO :XWORD, pszDefaultAction:XWORD
    FIUIAutomationLegacyIAccessiblePattern_get_CurrentDefaultAction TYPEDEF PTR IUIAutomationLegacyIAccessiblePattern_get_CurrentDefaultAction

    IUIAutomationLegacyIAccessiblePattern_get_CachedChildId TYPEDEF PROTO :XWORD, pRetVal:XWORD
    FIUIAutomationLegacyIAccessiblePattern_get_CachedChildId TYPEDEF PTR IUIAutomationLegacyIAccessiblePattern_get_CachedChildId

    IUIAutomationLegacyIAccessiblePattern_get_CachedName TYPEDEF PROTO :XWORD, pszName:XWORD
    FIUIAutomationLegacyIAccessiblePattern_get_CachedName TYPEDEF PTR IUIAutomationLegacyIAccessiblePattern_get_CachedName

    IUIAutomationLegacyIAccessiblePattern_get_CachedValue TYPEDEF PROTO :XWORD, pszValue:XWORD
    FIUIAutomationLegacyIAccessiblePattern_get_CachedValue TYPEDEF PTR IUIAutomationLegacyIAccessiblePattern_get_CachedValue

    IUIAutomationLegacyIAccessiblePattern_get_CachedDescription TYPEDEF PROTO :XWORD, pszDescription:XWORD
    FIUIAutomationLegacyIAccessiblePattern_get_CachedDescription TYPEDEF PTR IUIAutomationLegacyIAccessiblePattern_get_CachedDescription

    IUIAutomationLegacyIAccessiblePattern_get_CachedRole TYPEDEF PROTO :XWORD, pdwRole:XWORD
    FIUIAutomationLegacyIAccessiblePattern_get_CachedRole TYPEDEF PTR IUIAutomationLegacyIAccessiblePattern_get_CachedRole

    IUIAutomationLegacyIAccessiblePattern_get_CachedState TYPEDEF PROTO :XWORD, pdwState:XWORD
    FIUIAutomationLegacyIAccessiblePattern_get_CachedState TYPEDEF PTR IUIAutomationLegacyIAccessiblePattern_get_CachedState

    IUIAutomationLegacyIAccessiblePattern_get_CachedHelp TYPEDEF PROTO :XWORD, pszHelp:XWORD
    FIUIAutomationLegacyIAccessiblePattern_get_CachedHelp TYPEDEF PTR IUIAutomationLegacyIAccessiblePattern_get_CachedHelp

    IUIAutomationLegacyIAccessiblePattern_get_CachedKeyboardShortcut TYPEDEF PROTO :XWORD, pszKeyboardShortcut:XWORD
    FIUIAutomationLegacyIAccessiblePattern_get_CachedKeyboardShortcut TYPEDEF PTR IUIAutomationLegacyIAccessiblePattern_get_CachedKeyboardShortcut

    IUIAutomationLegacyIAccessiblePattern_GetCachedSelection TYPEDEF PROTO :XWORD, pvarSelectedChildren:XWORD
    FIUIAutomationLegacyIAccessiblePattern_GetCachedSelection TYPEDEF PTR IUIAutomationLegacyIAccessiblePattern_GetCachedSelection

    IUIAutomationLegacyIAccessiblePattern_get_CachedDefaultAction TYPEDEF PROTO :XWORD, pszDefaultAction:XWORD
    FIUIAutomationLegacyIAccessiblePattern_get_CachedDefaultAction TYPEDEF PTR IUIAutomationLegacyIAccessiblePattern_get_CachedDefaultAction

    IUIAutomationLegacyIAccessiblePattern_GetIAccessible TYPEDEF PROTO :XWORD, ppAccessible:XWORD
    FIUIAutomationLegacyIAccessiblePattern_GetIAccessible TYPEDEF PTR IUIAutomationLegacyIAccessiblePattern_GetIAccessible

    STIUIAutomationLegacyIAccessiblePattern STRUCT
        QueryInterface      FIUIAutomationLegacyIAccessiblePattern_QueryInterface ?
        AddRef                      XPTR ?
        Release                     XPTR ?
        Select1                     XPTR ?
        DoDefaultAction             XPTR ?
        SetValue                    FIUIAutomationLegacyIAccessiblePattern_SetValue ?
        get_CurrentChildId          FIUIAutomationLegacyIAccessiblePattern_get_CurrentChildId ?
        get_CurrentName             FIUIAutomationLegacyIAccessiblePattern_get_CurrentName ?
        get_CurrentValue            FIUIAutomationLegacyIAccessiblePattern_get_CurrentValue ?
        get_CurrentDescription      FIUIAutomationLegacyIAccessiblePattern_get_CurrentDescription ?
        get_CurrentRole             FIUIAutomationLegacyIAccessiblePattern_get_CurrentRole ?
        get_CurrentState            FIUIAutomationLegacyIAccessiblePattern_get_CurrentState ?
        get_CurrentHelp             FIUIAutomationLegacyIAccessiblePattern_get_CurrentHelp ?
        get_CurrentKeyboardShortcut FIUIAutomationLegacyIAccessiblePattern_get_CurrentKeyboardShortcut ?
        GetCurrentSelection         FIUIAutomationLegacyIAccessiblePattern_GetCurrentSelection ?
        get_CurrentDefaultAction    FIUIAutomationLegacyIAccessiblePattern_get_CurrentDefaultAction ?
        get_CachedChildId           FIUIAutomationLegacyIAccessiblePattern_get_CachedChildId ?
        get_CachedName              FIUIAutomationLegacyIAccessiblePattern_get_CachedName ?
        get_CachedValue             FIUIAutomationLegacyIAccessiblePattern_get_CachedValue ?
        get_CachedDescription       FIUIAutomationLegacyIAccessiblePattern_get_CachedDescription ?
        get_CachedRole              FIUIAutomationLegacyIAccessiblePattern_get_CachedRole ?
        get_CachedState             FIUIAutomationLegacyIAccessiblePattern_get_CachedState ?
        get_CachedHelp              FIUIAutomationLegacyIAccessiblePattern_get_CachedHelp ?
        get_CachedKeyboardShortcut  FIUIAutomationLegacyIAccessiblePattern_get_CachedKeyboardShortcut ?
        GetCachedSelection          FIUIAutomationLegacyIAccessiblePattern_GetCachedSelection ?
        get_CachedDefaultAction     FIUIAutomationLegacyIAccessiblePattern_get_CachedDefaultAction ?
        GetIAccessible              FIUIAutomationLegacyIAccessiblePattern_GetIAccessible ?
    STIUIAutomationLegacyIAccessiblePattern ENDS
 
    IUIAutomationLegacyIAccessiblePattern MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationLegacyIAccessiblePattern PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationLegacyIAccessiblePattern>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationLegacyIAccessiblePattern
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationLegacyIAccessiblePattern_INTERFACE_DEFINED__

IFNDEF __IUIAutomationItemContainerPattern_INTERFACE_DEFINED__
    __IUIAutomationItemContainerPattern_INTERFACE_DEFINED__ EQU 1

    IUIAutomationItemContainerPattern_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationItemContainerPattern_QueryInterface TYPEDEF PTR IUIAutomationItemContainerPattern_QueryInterface

    IUIAutomationItemContainerPattern_FindItemByProperty TYPEDEF PROTO :XWORD, pStartAfter:XWORD, propertyId:XWORD, value:VARIANT, pFound:XWORD
    FIUIAutomationItemContainerPattern_FindItemByProperty TYPEDEF PTR IUIAutomationItemContainerPattern_FindItemByProperty

    STIUIAutomationItemContainerPattern STRUCT
        QueryInterface      FIUIAutomationItemContainerPattern_QueryInterface ?
        AddRef              XPTR ?
        Release             XPTR ?
        FindItemByProperty  FIUIAutomationItemContainerPattern_FindItemByProperty ?
    STIUIAutomationItemContainerPattern ENDS

    IUIAutomationItemContainerPattern MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationItemContainerPattern PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationItemContainerPattern>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationItemContainerPattern
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationItemContainerPattern_INTERFACE_DEFINED__

IFNDEF __IUIAutomationVirtualizedItemPattern_INTERFACE_DEFINED__
    __IUIAutomationVirtualizedItemPattern_INTERFACE_DEFINED__   EQU 1

    IUIAutomationVirtualizedItemPattern_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationVirtualizedItemPattern_QueryInterface TYPEDEF PTR IUIAutomationVirtualizedItemPattern_QueryInterface

    STIUIAutomationVirtualizedItemPattern STRUCT
        QueryInterface  FIUIAutomationVirtualizedItemPattern_QueryInterface ?
        AddRef          XPTR ?
        Release         XPTR ?
        Realize         XPTR ?
    STIUIAutomationVirtualizedItemPattern ENDS

    IUIAutomationVirtualizedItemPattern MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationVirtualizedItemPattern PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationVirtualizedItemPattern>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationVirtualizedItemPattern
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationVirtualizedItemPattern_INTERFACE_DEFINED__

IFNDEF __IUIAutomationAnnotationPattern_INTERFACE_DEFINED__
    __IUIAutomationAnnotationPattern_INTERFACE_DEFINED__    EQU 1

    IUIAutomationAnnotationPattern_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationAnnotationPattern_QueryInterface TYPEDEF PTR IUIAutomationAnnotationPattern_QueryInterface

    IUIAutomationAnnotationPattern_get_CurrentAnnotationTypeId TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationAnnotationPattern_get_CurrentAnnotationTypeId TYPEDEF PTR IUIAutomationAnnotationPattern_get_CurrentAnnotationTypeId

    IUIAutomationAnnotationPattern_get_CurrentAnnotationTypeName TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationAnnotationPattern_get_CurrentAnnotationTypeName TYPEDEF PTR IUIAutomationAnnotationPattern_get_CurrentAnnotationTypeName

    IUIAutomationAnnotationPattern_get_CurrentAuthor TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationAnnotationPattern_get_CurrentAuthor TYPEDEF PTR IUIAutomationAnnotationPattern_get_CurrentAuthor

    IUIAutomationAnnotationPattern_get_CurrentDateTime TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationAnnotationPattern_get_CurrentDateTime TYPEDEF PTR IUIAutomationAnnotationPattern_get_CurrentDateTime

    IUIAutomationAnnotationPattern_get_CurrentTarget TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationAnnotationPattern_get_CurrentTarget TYPEDEF PTR IUIAutomationAnnotationPattern_get_CurrentTarget

    IUIAutomationAnnotationPattern_get_CachedAnnotationTypeId TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationAnnotationPattern_get_CachedAnnotationTypeId TYPEDEF PTR IUIAutomationAnnotationPattern_get_CachedAnnotationTypeId

    IUIAutomationAnnotationPattern_get_CachedAnnotationTypeName TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationAnnotationPattern_get_CachedAnnotationTypeName TYPEDEF PTR IUIAutomationAnnotationPattern_get_CachedAnnotationTypeName

    IUIAutomationAnnotationPattern_get_CachedAuthor TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationAnnotationPattern_get_CachedAuthor TYPEDEF PTR IUIAutomationAnnotationPattern_get_CachedAuthor

    IUIAutomationAnnotationPattern_get_CachedDateTime TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationAnnotationPattern_get_CachedDateTime TYPEDEF PTR IUIAutomationAnnotationPattern_get_CachedDateTime

    IUIAutomationAnnotationPattern_get_CachedTarget TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationAnnotationPattern_get_CachedTarget TYPEDEF PTR IUIAutomationAnnotationPattern_get_CachedTarget

    STIUIAutomationAnnotationPattern STRUCT
        QueryInterface                  FIUIAutomationAnnotationPattern_QueryInterface ?
        AddRef                          XPTR ?
        Release                         XPTR ?
        get_CurrentAnnotationTypeId     FIUIAutomationAnnotationPattern_get_CurrentAnnotationTypeId ?
        get_CurrentAnnotationTypeName   FIUIAutomationAnnotationPattern_get_CurrentAnnotationTypeName ?
        get_CurrentAuthor               FIUIAutomationAnnotationPattern_get_CurrentAuthor ?
        get_CurrentDateTime             FIUIAutomationAnnotationPattern_get_CurrentDateTime ?
        get_CurrentTarget               FIUIAutomationAnnotationPattern_get_CurrentTarget ?
        get_CachedAnnotationTypeId      FIUIAutomationAnnotationPattern_get_CachedAnnotationTypeId ?
        get_CachedAnnotationTypeName    FIUIAutomationAnnotationPattern_get_CachedAnnotationTypeName ?
        get_CachedAuthor                FIUIAutomationAnnotationPattern_get_CachedAuthor ?
        get_CachedDateTime              FIUIAutomationAnnotationPattern_get_CachedDateTime ?
        get_CachedTarget                FIUIAutomationAnnotationPattern_get_CachedTarget ?
    STIUIAutomationAnnotationPattern ENDS

    IUIAutomationAnnotationPattern MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationAnnotationPattern PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationAnnotationPattern>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationAnnotationPattern
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationAnnotationPattern_INTERFACE_DEFINED__

IFNDEF __IUIAutomationStylesPattern_INTERFACE_DEFINED__
    __IUIAutomationStylesPattern_INTERFACE_DEFINED__    EQU 1

    IUIAutomationStylesPattern_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationStylesPattern_QueryInterface TYPEDEF PTR IUIAutomationStylesPattern_QueryInterface

    IUIAutomationStylesPattern_get_CurrentStyleId TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationStylesPattern_get_CurrentStyleId TYPEDEF PTR IUIAutomationStylesPattern_get_CurrentStyleId

    IUIAutomationStylesPattern_get_CurrentStyleName TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationStylesPattern_get_CurrentStyleName TYPEDEF PTR IUIAutomationStylesPattern_get_CurrentStyleName

    IUIAutomationStylesPattern_get_CurrentFillColor TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationStylesPattern_get_CurrentFillColor TYPEDEF PTR IUIAutomationStylesPattern_get_CurrentFillColor

    IUIAutomationStylesPattern_get_CurrentFillPatternStyle TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationStylesPattern_get_CurrentFillPatternStyle TYPEDEF PTR IUIAutomationStylesPattern_get_CurrentFillPatternStyle

    IUIAutomationStylesPattern_get_CurrentShape TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationStylesPattern_get_CurrentShape TYPEDEF PTR IUIAutomationStylesPattern_get_CurrentShape

    IUIAutomationStylesPattern_get_CurrentFillPatternColor TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationStylesPattern_get_CurrentFillPatternColor TYPEDEF PTR IUIAutomationStylesPattern_get_CurrentFillPatternColor

    IUIAutomationStylesPattern_get_CurrentExtendedProperties TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationStylesPattern_get_CurrentExtendedProperties TYPEDEF PTR IUIAutomationStylesPattern_get_CurrentExtendedProperties

    IUIAutomationStylesPattern_GetCurrentExtendedPropertiesAsArray TYPEDEF PROTO :XWORD, propertyArray:XWORD, propertyCount:XWORD
    FIUIAutomationStylesPattern_GetCurrentExtendedPropertiesAsArray TYPEDEF PTR IUIAutomationStylesPattern_GetCurrentExtendedPropertiesAsArray

    IUIAutomationStylesPattern_get_CachedStyleId TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationStylesPattern_get_CachedStyleId TYPEDEF PTR IUIAutomationStylesPattern_get_CachedStyleId

    IUIAutomationStylesPattern_get_CachedStyleName TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationStylesPattern_get_CachedStyleName TYPEDEF PTR IUIAutomationStylesPattern_get_CachedStyleName

    IUIAutomationStylesPattern_get_CachedFillColor TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationStylesPattern_get_CachedFillColor TYPEDEF PTR IUIAutomationStylesPattern_get_CachedFillColor

    IUIAutomationStylesPattern_get_CachedFillPatternStyle TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationStylesPattern_get_CachedFillPatternStyle TYPEDEF PTR IUIAutomationStylesPattern_get_CachedFillPatternStyle

    IUIAutomationStylesPattern_get_CachedShape TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationStylesPattern_get_CachedShape TYPEDEF PTR IUIAutomationStylesPattern_get_CachedShape

    IUIAutomationStylesPattern_get_CachedFillPatternColor TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationStylesPattern_get_CachedFillPatternColor TYPEDEF PTR IUIAutomationStylesPattern_get_CachedFillPatternColor

    IUIAutomationStylesPattern_get_CachedExtendedProperties TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationStylesPattern_get_CachedExtendedProperties TYPEDEF PTR IUIAutomationStylesPattern_get_CachedExtendedProperties

    IUIAutomationStylesPattern_GetCachedExtendedPropertiesAsArray TYPEDEF PROTO :XWORD, propertyArray:XWORD, propertyCount:XWORD
    FIUIAutomationStylesPattern_GetCachedExtendedPropertiesAsArray TYPEDEF PTR IUIAutomationStylesPattern_GetCachedExtendedPropertiesAsArray

    STIUIAutomationStylesPattern STRUCT
        QueryInterface                      FIUIAutomationStylesPattern_QueryInterface ?
        AddRef                              XPTR ?
        Release                             XPTR ?
        get_CurrentStyleId                  FIUIAutomationStylesPattern_get_CurrentStyleId ?
        get_CurrentStyleName                FIUIAutomationStylesPattern_get_CurrentStyleName ?
        get_CurrentFillColor                FIUIAutomationStylesPattern_get_CurrentFillColor ?
        get_CurrentFillPatternStyle         FIUIAutomationStylesPattern_get_CurrentFillPatternStyle ?
        get_CurrentShape                    FIUIAutomationStylesPattern_get_CurrentShape ?
        get_CurrentFillPatternColor         FIUIAutomationStylesPattern_get_CurrentFillPatternColor ?
        get_CurrentExtendedProperties       FIUIAutomationStylesPattern_get_CurrentExtendedProperties ?
        GetCurrentExtendedPropertiesAsArray FIUIAutomationStylesPattern_GetCurrentExtendedPropertiesAsArray ?
        get_CachedStyleId                   FIUIAutomationStylesPattern_get_CachedStyleId ?
        get_CachedStyleName                 FIUIAutomationStylesPattern_get_CachedStyleName ?
        get_CachedFillColor                 FIUIAutomationStylesPattern_get_CachedFillColor ?
        get_CachedFillPatternStyle          FIUIAutomationStylesPattern_get_CachedFillPatternStyle ?
        get_CachedShape                     FIUIAutomationStylesPattern_get_CachedShape ?
        get_CachedFillPatternColor          FIUIAutomationStylesPattern_get_CachedFillPatternColor ?
        get_CachedExtendedProperties        FIUIAutomationStylesPattern_get_CachedExtendedProperties ?
        GetCachedExtendedPropertiesAsArray  FIUIAutomationStylesPattern_GetCachedExtendedPropertiesAsArray ?
    STIUIAutomationStylesPattern ENDS
 
    IUIAutomationStylesPattern MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationStylesPattern PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationStylesPattern>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationStylesPattern
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationStylesPattern_INTERFACE_DEFINED__

IFNDEF __IUIAutomationSpreadsheetPattern_INTERFACE_DEFINED__
    __IUIAutomationSpreadsheetPattern_INTERFACE_DEFINED__   EQU 1

    IUIAutomationSpreadsheetPattern_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationSpreadsheetPattern_QueryInterface TYPEDEF PTR IUIAutomationSpreadsheetPattern_QueryInterface

    IUIAutomationSpreadsheetPattern_GetItemByName TYPEDEF PROTO :XWORD, aname:XWORD, element:XWORD
    FIUIAutomationSpreadsheetPattern_GetItemByName TYPEDEF PTR IUIAutomationSpreadsheetPattern_GetItemByName

    STIUIAutomationSpreadsheetPattern STRUCT
        QueryInterface  FIUIAutomationSpreadsheetPattern_QueryInterface ?
        AddRef          XPTR ?
        Release         XPTR ?
        GetItemByName   FIUIAutomationSpreadsheetPattern_GetItemByName ?
    STIUIAutomationSpreadsheetPattern ENDS

    IUIAutomationSpreadsheetPattern MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationSpreadsheetPattern PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationSpreadsheetPattern>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationSpreadsheetPattern
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationSpreadsheetPattern_INTERFACE_DEFINED__

IFNDEF __IUIAutomationSpreadsheetItemPattern_INTERFACE_DEFINED__
    __IUIAutomationSpreadsheetItemPattern_INTERFACE_DEFINED__   EQU 1

    IUIAutomationSpreadsheetItemPattern_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationSpreadsheetItemPattern_QueryInterface TYPEDEF PTR IUIAutomationSpreadsheetItemPattern_QueryInterface

    IUIAutomationSpreadsheetItemPattern_get_CurrentFormula TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationSpreadsheetItemPattern_get_CurrentFormula TYPEDEF PTR IUIAutomationSpreadsheetItemPattern_get_CurrentFormula

    IUIAutomationSpreadsheetItemPattern_GetCurrentAnnotationObjects TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationSpreadsheetItemPattern_GetCurrentAnnotationObjects TYPEDEF PTR IUIAutomationSpreadsheetItemPattern_GetCurrentAnnotationObjects

    IUIAutomationSpreadsheetItemPattern_GetCurrentAnnotationTypes TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationSpreadsheetItemPattern_GetCurrentAnnotationTypes TYPEDEF PTR IUIAutomationSpreadsheetItemPattern_GetCurrentAnnotationTypes

    IUIAutomationSpreadsheetItemPattern_get_CachedFormula TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationSpreadsheetItemPattern_get_CachedFormula TYPEDEF PTR IUIAutomationSpreadsheetItemPattern_get_CachedFormula

    IUIAutomationSpreadsheetItemPattern_GetCachedAnnotationObjects TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationSpreadsheetItemPattern_GetCachedAnnotationObjects TYPEDEF PTR IUIAutomationSpreadsheetItemPattern_GetCachedAnnotationObjects

    IUIAutomationSpreadsheetItemPattern_GetCachedAnnotationTypes TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationSpreadsheetItemPattern_GetCachedAnnotationTypes TYPEDEF PTR IUIAutomationSpreadsheetItemPattern_GetCachedAnnotationTypes

    STIUIAutomationSpreadsheetItemPattern STRUCT
        QueryInterface              FIUIAutomationSpreadsheetItemPattern_QueryInterface ?
        AddRef                      XPTR ?
        Release                     XPTR ?
        get_CurrentFormula          FIUIAutomationSpreadsheetItemPattern_get_CurrentFormula ?
        GetCurrentAnnotationObjects FIUIAutomationSpreadsheetItemPattern_GetCurrentAnnotationObjects ?
        GetCurrentAnnotationTypes   FIUIAutomationSpreadsheetItemPattern_GetCurrentAnnotationTypes ?
        get_CachedFormula           FIUIAutomationSpreadsheetItemPattern_get_CachedFormula ?
        GetCachedAnnotationObjects  FIUIAutomationSpreadsheetItemPattern_GetCachedAnnotationObjects ?
        GetCachedAnnotationTypes    FIUIAutomationSpreadsheetItemPattern_GetCachedAnnotationTypes ?
    STIUIAutomationSpreadsheetItemPattern ENDS

    IUIAutomationSpreadsheetItemPattern MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationSpreadsheetItemPattern PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationSpreadsheetItemPattern>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationSpreadsheetItemPattern
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationSpreadsheetItemPattern_INTERFACE_DEFINED__

IFNDEF __IUIAutomationTransformPattern2_INTERFACE_DEFINED__
    __IUIAutomationTransformPattern2_INTERFACE_DEFINED__    EQU 1

    IUIAutomationTransformPattern2_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationTransformPattern2_QueryInterface TYPEDEF PTR IUIAutomationTransformPattern2_QueryInterface

    IUIAutomationTransformPattern2_Move TYPEDEF PROTO :XWORD, x:REAL8, y:REAL8 
    FIUIAutomationTransformPattern2_Move TYPEDEF PTR IUIAutomationTransformPattern2_Move

    IUIAutomationTransformPattern2_Resize TYPEDEF PROTO :XWORD, width1:REAL8, height:REAL8 
    FIUIAutomationTransformPattern2_Resize TYPEDEF PTR IUIAutomationTransformPattern2_Resize

    IUIAutomationTransformPattern2_Rotate TYPEDEF PROTO :XWORD, degrees:REAL8 
    FIUIAutomationTransformPattern2_Rotate TYPEDEF PTR IUIAutomationTransformPattern2_Rotate

    IUIAutomationTransformPattern2_get_CurrentCanMove TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationTransformPattern2_get_CurrentCanMove TYPEDEF PTR IUIAutomationTransformPattern2_get_CurrentCanMove

    IUIAutomationTransformPattern2_get_CurrentCanResize TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationTransformPattern2_get_CurrentCanResize TYPEDEF PTR IUIAutomationTransformPattern2_get_CurrentCanResize

    IUIAutomationTransformPattern2_get_CurrentCanRotate TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationTransformPattern2_get_CurrentCanRotate TYPEDEF PTR IUIAutomationTransformPattern2_get_CurrentCanRotate

    IUIAutomationTransformPattern2_get_CachedCanMove TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationTransformPattern2_get_CachedCanMove TYPEDEF PTR IUIAutomationTransformPattern2_get_CachedCanMove

    IUIAutomationTransformPattern2_get_CachedCanResize TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationTransformPattern2_get_CachedCanResize TYPEDEF PTR IUIAutomationTransformPattern2_get_CachedCanResize

    IUIAutomationTransformPattern2_get_CachedCanRotate TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationTransformPattern2_get_CachedCanRotate TYPEDEF PTR IUIAutomationTransformPattern2_get_CachedCanRotate

    IUIAutomationTransformPattern2_Zoom TYPEDEF PROTO :XWORD, zoom:REAL8 
    FIUIAutomationTransformPattern2_Zoom TYPEDEF PTR IUIAutomationTransformPattern2_Zoom

    IUIAutomationTransformPattern2_get_CurrentCanZoom TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationTransformPattern2_get_CurrentCanZoom TYPEDEF PTR IUIAutomationTransformPattern2_get_CurrentCanZoom

    IUIAutomationTransformPattern2_get_CachedCanZoom TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationTransformPattern2_get_CachedCanZoom TYPEDEF PTR IUIAutomationTransformPattern2_get_CachedCanZoom

    IUIAutomationTransformPattern2_get_CurrentZoomLevel TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationTransformPattern2_get_CurrentZoomLevel TYPEDEF PTR IUIAutomationTransformPattern2_get_CurrentZoomLevel

    IUIAutomationTransformPattern2_get_CachedZoomLevel TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationTransformPattern2_get_CachedZoomLevel TYPEDEF PTR IUIAutomationTransformPattern2_get_CachedZoomLevel

    IUIAutomationTransformPattern2_get_CurrentZoomMinimum TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationTransformPattern2_get_CurrentZoomMinimum TYPEDEF PTR IUIAutomationTransformPattern2_get_CurrentZoomMinimum

    IUIAutomationTransformPattern2_get_CachedZoomMinimum TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationTransformPattern2_get_CachedZoomMinimum TYPEDEF PTR IUIAutomationTransformPattern2_get_CachedZoomMinimum

    IUIAutomationTransformPattern2_get_CurrentZoomMaximum TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationTransformPattern2_get_CurrentZoomMaximum TYPEDEF PTR IUIAutomationTransformPattern2_get_CurrentZoomMaximum

    IUIAutomationTransformPattern2_get_CachedZoomMaximum TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationTransformPattern2_get_CachedZoomMaximum TYPEDEF PTR IUIAutomationTransformPattern2_get_CachedZoomMaximum

    STIUIAutomationTransformPattern2 STRUCT
        QueryInterface          FIUIAutomationTransformPattern2_QueryInterface ?
        AddRef                  XPTR ?
        Release                 XPTR ?
        Move                    FIUIAutomationTransformPattern2_Move ?
        Resize                  FIUIAutomationTransformPattern2_Resize ?
        Rotate                  FIUIAutomationTransformPattern2_Rotate ?
        get_CurrentCanMove      FIUIAutomationTransformPattern2_get_CurrentCanMove ?
        get_CurrentCanResize    FIUIAutomationTransformPattern2_get_CurrentCanResize ?
        get_CurrentCanRotate    FIUIAutomationTransformPattern2_get_CurrentCanRotate ?
        get_CachedCanMove       FIUIAutomationTransformPattern2_get_CachedCanMove ?
        get_CachedCanResize     FIUIAutomationTransformPattern2_get_CachedCanResize ?
        get_CachedCanRotate     FIUIAutomationTransformPattern2_get_CachedCanRotate ?
        Zoom                    FIUIAutomationTransformPattern2_Zoom ?
        ZoomByUnit              XPTR ?
        get_CurrentCanZoom      FIUIAutomationTransformPattern2_get_CurrentCanZoom ?
        get_CachedCanZoom       FIUIAutomationTransformPattern2_get_CachedCanZoom ?
        get_CurrentZoomLevel    FIUIAutomationTransformPattern2_get_CurrentZoomLevel ?
        get_CachedZoomLevel     FIUIAutomationTransformPattern2_get_CachedZoomLevel ?
        get_CurrentZoomMinimum  FIUIAutomationTransformPattern2_get_CurrentZoomMinimum ?
        get_CachedZoomMinimum   FIUIAutomationTransformPattern2_get_CachedZoomMinimum ?
        get_CurrentZoomMaximum  FIUIAutomationTransformPattern2_get_CurrentZoomMaximum ?
        get_CachedZoomMaximum   FIUIAutomationTransformPattern2_get_CachedZoomMaximum ?
    STIUIAutomationTransformPattern2 ENDS

    IUIAutomationTransformPattern2 MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationTransformPattern2 PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationTransformPattern2>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationTransformPattern2
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationTransformPattern2_INTERFACE_DEFINED__

IFNDEF __IUIAutomationTextChildPattern_INTERFACE_DEFINED__
    __IUIAutomationTextChildPattern_INTERFACE_DEFINED__ EQU 1

    IUIAutomationTextChildPattern_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationTextChildPattern_QueryInterface TYPEDEF PTR IUIAutomationTextChildPattern_QueryInterface

    IUIAutomationTextChildPattern_get_TextContainer TYPEDEF PROTO :XWORD, container:XWORD
    FIUIAutomationTextChildPattern_get_TextContainer TYPEDEF PTR IUIAutomationTextChildPattern_get_TextContainer

    IUIAutomationTextChildPattern_get_TextRange TYPEDEF PROTO :XWORD, range:XWORD
    FIUIAutomationTextChildPattern_get_TextRange TYPEDEF PTR IUIAutomationTextChildPattern_get_TextRange

    STIUIAutomationTextChildPattern STRUCT
        QueryInterface      FIUIAutomationTextChildPattern_QueryInterface ?
        AddRef              XPTR ?
        Release             XPTR ?
        get_TextContainer   FIUIAutomationTextChildPattern_get_TextContainer ?
        get_TextRange       FIUIAutomationTextChildPattern_get_TextRange ?
    STIUIAutomationTextChildPattern ENDS

    IUIAutomationTextChildPattern MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationTextChildPattern PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationTextChildPattern>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationTextChildPattern
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationTextChildPattern_INTERFACE_DEFINED__

IFNDEF __IUIAutomationDragPattern_INTERFACE_DEFINED__
    __IUIAutomationDragPattern_INTERFACE_DEFINED__  EQU 1

    IUIAutomationDragPattern_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationDragPattern_QueryInterface TYPEDEF PTR IUIAutomationDragPattern_QueryInterface

    IUIAutomationDragPattern_get_CurrentIsGrabbed TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationDragPattern_get_CurrentIsGrabbed TYPEDEF PTR IUIAutomationDragPattern_get_CurrentIsGrabbed

    IUIAutomationDragPattern_get_CachedIsGrabbed TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationDragPattern_get_CachedIsGrabbed TYPEDEF PTR IUIAutomationDragPattern_get_CachedIsGrabbed

    IUIAutomationDragPattern_get_CurrentDropEffect TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationDragPattern_get_CurrentDropEffect TYPEDEF PTR IUIAutomationDragPattern_get_CurrentDropEffect

    IUIAutomationDragPattern_get_CachedDropEffect TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationDragPattern_get_CachedDropEffect TYPEDEF PTR IUIAutomationDragPattern_get_CachedDropEffect

    IUIAutomationDragPattern_get_CurrentDropEffects TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationDragPattern_get_CurrentDropEffects TYPEDEF PTR IUIAutomationDragPattern_get_CurrentDropEffects

    IUIAutomationDragPattern_get_CachedDropEffects TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationDragPattern_get_CachedDropEffects TYPEDEF PTR IUIAutomationDragPattern_get_CachedDropEffects

    IUIAutomationDragPattern_GetCurrentGrabbedItems TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationDragPattern_GetCurrentGrabbedItems TYPEDEF PTR IUIAutomationDragPattern_GetCurrentGrabbedItems

    IUIAutomationDragPattern_GetCachedGrabbedItems TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationDragPattern_GetCachedGrabbedItems TYPEDEF PTR IUIAutomationDragPattern_GetCachedGrabbedItems

    STIUIAutomationDragPattern STRUCT
        QueryInterface          FIUIAutomationDragPattern_QueryInterface ?
        AddRef                  XPTR ?
        Release                 XPTR ?
        get_CurrentIsGrabbed    FIUIAutomationDragPattern_get_CurrentIsGrabbed ?
        get_CachedIsGrabbed     FIUIAutomationDragPattern_get_CachedIsGrabbed ?
        get_CurrentDropEffect   FIUIAutomationDragPattern_get_CurrentDropEffect ?
        get_CachedDropEffect    FIUIAutomationDragPattern_get_CachedDropEffect ?
        get_CurrentDropEffects  FIUIAutomationDragPattern_get_CurrentDropEffects ?
        get_CachedDropEffects   FIUIAutomationDragPattern_get_CachedDropEffects ?
        GetCurrentGrabbedItems  FIUIAutomationDragPattern_GetCurrentGrabbedItems ?
        GetCachedGrabbedItems   FIUIAutomationDragPattern_GetCachedGrabbedItems ?
    STIUIAutomationDragPattern ENDS

    IUIAutomationDragPattern MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationDragPattern PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationDragPattern>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationDragPattern
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationDragPattern_INTERFACE_DEFINED__

IFNDEF __IUIAutomationDropTargetPattern_INTERFACE_DEFINED__
    __IUIAutomationDropTargetPattern_INTERFACE_DEFINED__    EQU 1

    IUIAutomationDropTargetPattern_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationDropTargetPattern_QueryInterface TYPEDEF PTR IUIAutomationDropTargetPattern_QueryInterface

    IUIAutomationDropTargetPattern_get_CurrentDropTargetEffect TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationDropTargetPattern_get_CurrentDropTargetEffect TYPEDEF PTR IUIAutomationDropTargetPattern_get_CurrentDropTargetEffect

    IUIAutomationDropTargetPattern_get_CachedDropTargetEffect TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationDropTargetPattern_get_CachedDropTargetEffect TYPEDEF PTR IUIAutomationDropTargetPattern_get_CachedDropTargetEffect

    IUIAutomationDropTargetPattern_get_CurrentDropTargetEffects TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationDropTargetPattern_get_CurrentDropTargetEffects TYPEDEF PTR IUIAutomationDropTargetPattern_get_CurrentDropTargetEffects

    IUIAutomationDropTargetPattern_get_CachedDropTargetEffects TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationDropTargetPattern_get_CachedDropTargetEffects TYPEDEF PTR IUIAutomationDropTargetPattern_get_CachedDropTargetEffects

    STIUIAutomationDropTargetPattern STRUCT
        QueryInterface                  FIUIAutomationDropTargetPattern_QueryInterface ?
        AddRef                          XPTR ?
        Release                         XPTR ?
        get_CurrentDropTargetEffect     FIUIAutomationDropTargetPattern_get_CurrentDropTargetEffect ?
        get_CachedDropTargetEffect      FIUIAutomationDropTargetPattern_get_CachedDropTargetEffect ?
        get_CurrentDropTargetEffects    FIUIAutomationDropTargetPattern_get_CurrentDropTargetEffects ?
        get_CachedDropTargetEffects     FIUIAutomationDropTargetPattern_get_CachedDropTargetEffects ?
    STIUIAutomationDropTargetPattern ENDS

    IUIAutomationDropTargetPattern MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationDropTargetPattern PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationDropTargetPattern>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationDropTargetPattern
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationDropTargetPattern_INTERFACE_DEFINED__

IFNDEF __IUIAutomationElement2_INTERFACE_DEFINED__
    __IUIAutomationElement2_INTERFACE_DEFINED__ EQU 1

    IUIAutomationElement2_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationElement2_QueryInterface TYPEDEF PTR IUIAutomationElement2_QueryInterface

    IUIAutomationElement2_GetRuntimeId TYPEDEF PROTO :XWORD, runtimeId:XWORD
    FIUIAutomationElement2_GetRuntimeId TYPEDEF PTR IUIAutomationElement2_GetRuntimeId

    IUIAutomationElement2_FindFirst TYPEDEF PROTO :XWORD, scope:XWORD, condition:XWORD, found:XWORD
    FIUIAutomationElement2_FindFirst TYPEDEF PTR IUIAutomationElement2_FindFirst

    IUIAutomationElement2_FindAll TYPEDEF PROTO :XWORD, scope:XWORD, condition:XWORD, found:XWORD
    FIUIAutomationElement2_FindAll TYPEDEF PTR IUIAutomationElement2_FindAll

    IUIAutomationElement2_FindFirstBuildCache TYPEDEF PROTO :XWORD, scope:XWORD, condition:XWORD, cacheRequest:XWORD, found:XWORD
    FIUIAutomationElement2_FindFirstBuildCache TYPEDEF PTR IUIAutomationElement2_FindFirstBuildCache

    IUIAutomationElement2_FindAllBuildCache TYPEDEF PROTO :XWORD, scope:XWORD, condition:XWORD, cacheRequest:XWORD, found:XWORD
    FIUIAutomationElement2_FindAllBuildCache TYPEDEF PTR IUIAutomationElement2_FindAllBuildCache

    IUIAutomationElement2_BuildUpdatedCache TYPEDEF PROTO :XWORD, cacheRequest:XWORD, updatedElement:XWORD
    FIUIAutomationElement2_BuildUpdatedCache TYPEDEF PTR IUIAutomationElement2_BuildUpdatedCache

    IUIAutomationElement2_GetCurrentPropertyValue TYPEDEF PROTO :XWORD, propertyId:XWORD, retVal:XWORD
    FIUIAutomationElement2_GetCurrentPropertyValue TYPEDEF PTR IUIAutomationElement2_GetCurrentPropertyValue

    IUIAutomationElement2_GetCurrentPropertyValueEx TYPEDEF PROTO :XWORD, propertyId:XWORD, ignoreDefaultValue:XWORD, retVal:XWORD
    FIUIAutomationElement2_GetCurrentPropertyValueEx TYPEDEF PTR IUIAutomationElement2_GetCurrentPropertyValueEx

    IUIAutomationElement2_GetCachedPropertyValue TYPEDEF PROTO :XWORD, propertyId:XWORD, retVal:XWORD
    FIUIAutomationElement2_GetCachedPropertyValue TYPEDEF PTR IUIAutomationElement2_GetCachedPropertyValue

    IUIAutomationElement2_GetCachedPropertyValueEx TYPEDEF PROTO :XWORD, propertyId:XWORD, ignoreDefaultValue:XWORD, retVal:XWORD
    FIUIAutomationElement2_GetCachedPropertyValueEx TYPEDEF PTR IUIAutomationElement2_GetCachedPropertyValueEx

    IUIAutomationElement2_GetCurrentPatternAs TYPEDEF PROTO :XWORD, patternId:XWORD, riid:XWORD, patternObject:XWORD
    FIUIAutomationElement2_GetCurrentPatternAs TYPEDEF PTR IUIAutomationElement2_GetCurrentPatternAs

    IUIAutomationElement2_GetCachedPatternAs TYPEDEF PROTO :XWORD, patternId:XWORD, riid:XWORD, patternObject:XWORD
    FIUIAutomationElement2_GetCachedPatternAs TYPEDEF PTR IUIAutomationElement2_GetCachedPatternAs

    IUIAutomationElement2_GetCurrentPattern TYPEDEF PROTO :XWORD, patternId:XWORD, patternObject:XWORD
    FIUIAutomationElement2_GetCurrentPattern TYPEDEF PTR IUIAutomationElement2_GetCurrentPattern

    IUIAutomationElement2_GetCachedPattern TYPEDEF PROTO :XWORD, patternId:XWORD, patternObject:XWORD
    FIUIAutomationElement2_GetCachedPattern TYPEDEF PTR IUIAutomationElement2_GetCachedPattern

    IUIAutomationElement2_GetCachedParent TYPEDEF PROTO :XWORD, parent:XWORD
    FIUIAutomationElement2_GetCachedParent TYPEDEF PTR IUIAutomationElement2_GetCachedParent

    IUIAutomationElement2_GetCachedChildren TYPEDEF PROTO :XWORD, children:XWORD
    FIUIAutomationElement2_GetCachedChildren TYPEDEF PTR IUIAutomationElement2_GetCachedChildren

    IUIAutomationElement2_get_CurrentProcessId TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CurrentProcessId TYPEDEF PTR IUIAutomationElement2_get_CurrentProcessId

    IUIAutomationElement2_get_CurrentControlType TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CurrentControlType TYPEDEF PTR IUIAutomationElement2_get_CurrentControlType

    IUIAutomationElement2_get_CurrentLocalizedControlType TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CurrentLocalizedControlType TYPEDEF PTR IUIAutomationElement2_get_CurrentLocalizedControlType

    IUIAutomationElement2_get_CurrentName TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CurrentName TYPEDEF PTR IUIAutomationElement2_get_CurrentName

    IUIAutomationElement2_get_CurrentAcceleratorKey TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CurrentAcceleratorKey TYPEDEF PTR IUIAutomationElement2_get_CurrentAcceleratorKey

    IUIAutomationElement2_get_CurrentAccessKey TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CurrentAccessKey TYPEDEF PTR IUIAutomationElement2_get_CurrentAccessKey

    IUIAutomationElement2_get_CurrentHasKeyboardFocus TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CurrentHasKeyboardFocus TYPEDEF PTR IUIAutomationElement2_get_CurrentHasKeyboardFocus

    IUIAutomationElement2_get_CurrentIsKeyboardFocusable TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CurrentIsKeyboardFocusable TYPEDEF PTR IUIAutomationElement2_get_CurrentIsKeyboardFocusable

    IUIAutomationElement2_get_CurrentIsEnabled TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CurrentIsEnabled TYPEDEF PTR IUIAutomationElement2_get_CurrentIsEnabled

    IUIAutomationElement2_get_CurrentAutomationId TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CurrentAutomationId TYPEDEF PTR IUIAutomationElement2_get_CurrentAutomationId

    IUIAutomationElement2_get_CurrentClassName TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CurrentClassName TYPEDEF PTR IUIAutomationElement2_get_CurrentClassName

    IUIAutomationElement2_get_CurrentHelpText TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CurrentHelpText TYPEDEF PTR IUIAutomationElement2_get_CurrentHelpText

    IUIAutomationElement2_get_CurrentCulture TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CurrentCulture TYPEDEF PTR IUIAutomationElement2_get_CurrentCulture

    IUIAutomationElement2_get_CurrentIsControlElement TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CurrentIsControlElement TYPEDEF PTR IUIAutomationElement2_get_CurrentIsControlElement

    IUIAutomationElement2_get_CurrentIsContentElement TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CurrentIsContentElement TYPEDEF PTR IUIAutomationElement2_get_CurrentIsContentElement

    IUIAutomationElement2_get_CurrentIsPassword TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CurrentIsPassword TYPEDEF PTR IUIAutomationElement2_get_CurrentIsPassword

    IUIAutomationElement2_get_CurrentNativeWindowHandle TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CurrentNativeWindowHandle TYPEDEF PTR IUIAutomationElement2_get_CurrentNativeWindowHandle

    IUIAutomationElement2_get_CurrentItemType TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CurrentItemType TYPEDEF PTR IUIAutomationElement2_get_CurrentItemType

    IUIAutomationElement2_get_CurrentIsOffscreen TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CurrentIsOffscreen TYPEDEF PTR IUIAutomationElement2_get_CurrentIsOffscreen

    IUIAutomationElement2_get_CurrentOrientation TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CurrentOrientation TYPEDEF PTR IUIAutomationElement2_get_CurrentOrientation

    IUIAutomationElement2_get_CurrentFrameworkId TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CurrentFrameworkId TYPEDEF PTR IUIAutomationElement2_get_CurrentFrameworkId

    IUIAutomationElement2_get_CurrentIsRequiredForForm TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CurrentIsRequiredForForm TYPEDEF PTR IUIAutomationElement2_get_CurrentIsRequiredForForm

    IUIAutomationElement2_get_CurrentItemStatus TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CurrentItemStatus TYPEDEF PTR IUIAutomationElement2_get_CurrentItemStatus

    IUIAutomationElement2_get_CurrentBoundingRectangle TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CurrentBoundingRectangle TYPEDEF PTR IUIAutomationElement2_get_CurrentBoundingRectangle

    IUIAutomationElement2_get_CurrentLabeledBy TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CurrentLabeledBy TYPEDEF PTR IUIAutomationElement2_get_CurrentLabeledBy

    IUIAutomationElement2_get_CurrentAriaRole TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CurrentAriaRole TYPEDEF PTR IUIAutomationElement2_get_CurrentAriaRole

    IUIAutomationElement2_get_CurrentAriaProperties TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CurrentAriaProperties TYPEDEF PTR IUIAutomationElement2_get_CurrentAriaProperties

    IUIAutomationElement2_get_CurrentIsDataValidForForm TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CurrentIsDataValidForForm TYPEDEF PTR IUIAutomationElement2_get_CurrentIsDataValidForForm

    IUIAutomationElement2_get_CurrentControllerFor TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CurrentControllerFor TYPEDEF PTR IUIAutomationElement2_get_CurrentControllerFor

    IUIAutomationElement2_get_CurrentDescribedBy TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CurrentDescribedBy TYPEDEF PTR IUIAutomationElement2_get_CurrentDescribedBy

    IUIAutomationElement2_get_CurrentFlowsTo TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CurrentFlowsTo TYPEDEF PTR IUIAutomationElement2_get_CurrentFlowsTo

    IUIAutomationElement2_get_CurrentProviderDescription TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CurrentProviderDescription TYPEDEF PTR IUIAutomationElement2_get_CurrentProviderDescription

    IUIAutomationElement2_get_CachedProcessId TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CachedProcessId TYPEDEF PTR IUIAutomationElement2_get_CachedProcessId

    IUIAutomationElement2_get_CachedControlType TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CachedControlType TYPEDEF PTR IUIAutomationElement2_get_CachedControlType

    IUIAutomationElement2_get_CachedLocalizedControlType TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CachedLocalizedControlType TYPEDEF PTR IUIAutomationElement2_get_CachedLocalizedControlType

    IUIAutomationElement2_get_CachedName TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CachedName TYPEDEF PTR IUIAutomationElement2_get_CachedName

    IUIAutomationElement2_get_CachedAcceleratorKey TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CachedAcceleratorKey TYPEDEF PTR IUIAutomationElement2_get_CachedAcceleratorKey

    IUIAutomationElement2_get_CachedAccessKey TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CachedAccessKey TYPEDEF PTR IUIAutomationElement2_get_CachedAccessKey

    IUIAutomationElement2_get_CachedHasKeyboardFocus TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CachedHasKeyboardFocus TYPEDEF PTR IUIAutomationElement2_get_CachedHasKeyboardFocus

    IUIAutomationElement2_get_CachedIsKeyboardFocusable TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CachedIsKeyboardFocusable TYPEDEF PTR IUIAutomationElement2_get_CachedIsKeyboardFocusable

    IUIAutomationElement2_get_CachedIsEnabled TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CachedIsEnabled TYPEDEF PTR IUIAutomationElement2_get_CachedIsEnabled

    IUIAutomationElement2_get_CachedAutomationId TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CachedAutomationId TYPEDEF PTR IUIAutomationElement2_get_CachedAutomationId

    IUIAutomationElement2_get_CachedClassName TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CachedClassName TYPEDEF PTR IUIAutomationElement2_get_CachedClassName

    IUIAutomationElement2_get_CachedHelpText TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CachedHelpText TYPEDEF PTR IUIAutomationElement2_get_CachedHelpText

    IUIAutomationElement2_get_CachedCulture TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CachedCulture TYPEDEF PTR IUIAutomationElement2_get_CachedCulture

    IUIAutomationElement2_get_CachedIsControlElement TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CachedIsControlElement TYPEDEF PTR IUIAutomationElement2_get_CachedIsControlElement

    IUIAutomationElement2_get_CachedIsContentElement TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CachedIsContentElement TYPEDEF PTR IUIAutomationElement2_get_CachedIsContentElement

    IUIAutomationElement2_get_CachedIsPassword TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CachedIsPassword TYPEDEF PTR IUIAutomationElement2_get_CachedIsPassword

    IUIAutomationElement2_get_CachedNativeWindowHandle TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CachedNativeWindowHandle TYPEDEF PTR IUIAutomationElement2_get_CachedNativeWindowHandle

    IUIAutomationElement2_get_CachedItemType TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CachedItemType TYPEDEF PTR IUIAutomationElement2_get_CachedItemType

    IUIAutomationElement2_get_CachedIsOffscreen TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CachedIsOffscreen TYPEDEF PTR IUIAutomationElement2_get_CachedIsOffscreen

    IUIAutomationElement2_get_CachedOrientation TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CachedOrientation TYPEDEF PTR IUIAutomationElement2_get_CachedOrientation

    IUIAutomationElement2_get_CachedFrameworkId TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CachedFrameworkId TYPEDEF PTR IUIAutomationElement2_get_CachedFrameworkId

    IUIAutomationElement2_get_CachedIsRequiredForForm TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CachedIsRequiredForForm TYPEDEF PTR IUIAutomationElement2_get_CachedIsRequiredForForm

    IUIAutomationElement2_get_CachedItemStatus TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CachedItemStatus TYPEDEF PTR IUIAutomationElement2_get_CachedItemStatus

    IUIAutomationElement2_get_CachedBoundingRectangle TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CachedBoundingRectangle TYPEDEF PTR IUIAutomationElement2_get_CachedBoundingRectangle

    IUIAutomationElement2_get_CachedLabeledBy TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CachedLabeledBy TYPEDEF PTR IUIAutomationElement2_get_CachedLabeledBy

    IUIAutomationElement2_get_CachedAriaRole TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CachedAriaRole TYPEDEF PTR IUIAutomationElement2_get_CachedAriaRole

    IUIAutomationElement2_get_CachedAriaProperties TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CachedAriaProperties TYPEDEF PTR IUIAutomationElement2_get_CachedAriaProperties

    IUIAutomationElement2_get_CachedIsDataValidForForm TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CachedIsDataValidForForm TYPEDEF PTR IUIAutomationElement2_get_CachedIsDataValidForForm

    IUIAutomationElement2_get_CachedControllerFor TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CachedControllerFor TYPEDEF PTR IUIAutomationElement2_get_CachedControllerFor

    IUIAutomationElement2_get_CachedDescribedBy TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CachedDescribedBy TYPEDEF PTR IUIAutomationElement2_get_CachedDescribedBy

    IUIAutomationElement2_get_CachedFlowsTo TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CachedFlowsTo TYPEDEF PTR IUIAutomationElement2_get_CachedFlowsTo

    IUIAutomationElement2_get_CachedProviderDescription TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CachedProviderDescription TYPEDEF PTR IUIAutomationElement2_get_CachedProviderDescription

    IUIAutomationElement2_GetClickablePoint TYPEDEF PROTO :XWORD, clickable:XWORD, gotClickable:XWORD
    FIUIAutomationElement2_GetClickablePoint TYPEDEF PTR IUIAutomationElement2_GetClickablePoint

    IUIAutomationElement2_get_CurrentOptimizeForVisualContent TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CurrentOptimizeForVisualContent TYPEDEF PTR IUIAutomationElement2_get_CurrentOptimizeForVisualContent

    IUIAutomationElement2_get_CachedOptimizeForVisualContent TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CachedOptimizeForVisualContent TYPEDEF PTR IUIAutomationElement2_get_CachedOptimizeForVisualContent

    IUIAutomationElement2_get_CurrentLiveSetting TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CurrentLiveSetting TYPEDEF PTR IUIAutomationElement2_get_CurrentLiveSetting

    IUIAutomationElement2_get_CachedLiveSetting TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CachedLiveSetting TYPEDEF PTR IUIAutomationElement2_get_CachedLiveSetting

    IUIAutomationElement2_get_CurrentFlowsFrom TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CurrentFlowsFrom TYPEDEF PTR IUIAutomationElement2_get_CurrentFlowsFrom

    IUIAutomationElement2_get_CachedFlowsFrom TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement2_get_CachedFlowsFrom TYPEDEF PTR IUIAutomationElement2_get_CachedFlowsFrom

    STIUIAutomationElement2 STRUCT
        QueryInterface                      FIUIAutomationElement2_QueryInterface ?
        AddRef                              XPTR ?
        Release                             XPTR ?
        SetFocus1                           XPTR ?
        GetRuntimeId                        FIUIAutomationElement2_GetRuntimeId ?
        FindFirst                           FIUIAutomationElement2_FindFirst ?
        FindAll                             FIUIAutomationElement2_FindAll ?
        FindFirstBuildCache                 FIUIAutomationElement2_FindFirstBuildCache ?
        FindAllBuildCache                   FIUIAutomationElement2_FindAllBuildCache ?
        BuildUpdatedCache                   FIUIAutomationElement2_BuildUpdatedCache ?
        GetCurrentPropertyValue             FIUIAutomationElement2_GetCurrentPropertyValue ?
        GetCurrentPropertyValueEx           FIUIAutomationElement2_GetCurrentPropertyValueEx ?
        GetCachedPropertyValue              FIUIAutomationElement2_GetCachedPropertyValue ?
        GetCachedPropertyValueEx            FIUIAutomationElement2_GetCachedPropertyValueEx ?
        GetCurrentPatternAs                 FIUIAutomationElement2_GetCurrentPatternAs ?
        GetCachedPatternAs                  FIUIAutomationElement2_GetCachedPatternAs ?
        GetCurrentPattern                   FIUIAutomationElement2_GetCurrentPattern ?
        GetCachedPattern                    FIUIAutomationElement2_GetCachedPattern ?
        GetCachedParent                     FIUIAutomationElement2_GetCachedParent ?
        GetCachedChildren                   FIUIAutomationElement2_GetCachedChildren ?
        get_CurrentProcessId                FIUIAutomationElement2_get_CurrentProcessId ?
        get_CurrentControlType              FIUIAutomationElement2_get_CurrentControlType ?
        get_CurrentLocalizedControlType     FIUIAutomationElement2_get_CurrentLocalizedControlType ?
        get_CurrentName                     FIUIAutomationElement2_get_CurrentName ?
        get_CurrentAcceleratorKey           FIUIAutomationElement2_get_CurrentAcceleratorKey ?
        get_CurrentAccessKey                FIUIAutomationElement2_get_CurrentAccessKey ?
        get_CurrentHasKeyboardFocus         FIUIAutomationElement2_get_CurrentHasKeyboardFocus ?
        get_CurrentIsKeyboardFocusable      FIUIAutomationElement2_get_CurrentIsKeyboardFocusable ?
        get_CurrentIsEnabled                FIUIAutomationElement2_get_CurrentIsEnabled ?
        get_CurrentAutomationId             FIUIAutomationElement2_get_CurrentAutomationId ?
        get_CurrentClassName                FIUIAutomationElement2_get_CurrentClassName ?
        get_CurrentHelpText                 FIUIAutomationElement2_get_CurrentHelpText ?
        get_CurrentCulture                  FIUIAutomationElement2_get_CurrentCulture ?
        get_CurrentIsControlElement         FIUIAutomationElement2_get_CurrentIsControlElement ?
        get_CurrentIsContentElement         FIUIAutomationElement2_get_CurrentIsContentElement ?
        get_CurrentIsPassword               FIUIAutomationElement2_get_CurrentIsPassword ?
        get_CurrentNativeWindowHandle       FIUIAutomationElement2_get_CurrentNativeWindowHandle ?
        get_CurrentItemType                 FIUIAutomationElement2_get_CurrentItemType ?
        get_CurrentIsOffscreen              FIUIAutomationElement2_get_CurrentIsOffscreen ?
        get_CurrentOrientation              FIUIAutomationElement2_get_CurrentOrientation ?
        get_CurrentFrameworkId              FIUIAutomationElement2_get_CurrentFrameworkId ?
        get_CurrentIsRequiredForForm        FIUIAutomationElement2_get_CurrentIsRequiredForForm ?
        get_CurrentItemStatus               FIUIAutomationElement2_get_CurrentItemStatus ?
        get_CurrentBoundingRectangle        FIUIAutomationElement2_get_CurrentBoundingRectangle ?
        get_CurrentLabeledBy                FIUIAutomationElement2_get_CurrentLabeledBy ?
        get_CurrentAriaRole                 FIUIAutomationElement2_get_CurrentAriaRole ?
        get_CurrentAriaProperties           FIUIAutomationElement2_get_CurrentAriaProperties ?
        get_CurrentIsDataValidForForm       FIUIAutomationElement2_get_CurrentIsDataValidForForm ?
        get_CurrentControllerFor            FIUIAutomationElement2_get_CurrentControllerFor ?
        get_CurrentDescribedBy              FIUIAutomationElement2_get_CurrentDescribedBy ?
        get_CurrentFlowsTo                  FIUIAutomationElement2_get_CurrentFlowsTo ?
        get_CurrentProviderDescription      FIUIAutomationElement2_get_CurrentProviderDescription ?
        get_CachedProcessId                 FIUIAutomationElement2_get_CachedProcessId ?
        get_CachedControlType               FIUIAutomationElement2_get_CachedControlType ?
        get_CachedLocalizedControlType      FIUIAutomationElement2_get_CachedLocalizedControlType ?
        get_CachedName                      FIUIAutomationElement2_get_CachedName ?
        get_CachedAcceleratorKey            FIUIAutomationElement2_get_CachedAcceleratorKey ?
        get_CachedAccessKey                 FIUIAutomationElement2_get_CachedAccessKey ?
        get_CachedHasKeyboardFocus          FIUIAutomationElement2_get_CachedHasKeyboardFocus ?
        get_CachedIsKeyboardFocusable       FIUIAutomationElement2_get_CachedIsKeyboardFocusable ?
        get_CachedIsEnabled                 FIUIAutomationElement2_get_CachedIsEnabled ?
        get_CachedAutomationId              FIUIAutomationElement2_get_CachedAutomationId ?
        get_CachedClassName                 FIUIAutomationElement2_get_CachedClassName ?
        get_CachedHelpText                  FIUIAutomationElement2_get_CachedHelpText ?
        get_CachedCulture                   FIUIAutomationElement2_get_CachedCulture ?
        get_CachedIsControlElement          FIUIAutomationElement2_get_CachedIsControlElement ?
        get_CachedIsContentElement          FIUIAutomationElement2_get_CachedIsContentElement ?
        get_CachedIsPassword                FIUIAutomationElement2_get_CachedIsPassword ?
        get_CachedNativeWindowHandle        FIUIAutomationElement2_get_CachedNativeWindowHandle ?
        get_CachedItemType                  FIUIAutomationElement2_get_CachedItemType ?
        get_CachedIsOffscreen               FIUIAutomationElement2_get_CachedIsOffscreen ?
        get_CachedOrientation               FIUIAutomationElement2_get_CachedOrientation ?
        get_CachedFrameworkId               FIUIAutomationElement2_get_CachedFrameworkId ?
        get_CachedIsRequiredForForm         FIUIAutomationElement2_get_CachedIsRequiredForForm ?
        get_CachedItemStatus                FIUIAutomationElement2_get_CachedItemStatus ?
        get_CachedBoundingRectangle         FIUIAutomationElement2_get_CachedBoundingRectangle ?
        get_CachedLabeledBy                 FIUIAutomationElement2_get_CachedLabeledBy ?
        get_CachedAriaRole                  FIUIAutomationElement2_get_CachedAriaRole ?
        get_CachedAriaProperties            FIUIAutomationElement2_get_CachedAriaProperties ?
        get_CachedIsDataValidForForm        FIUIAutomationElement2_get_CachedIsDataValidForForm ?
        get_CachedControllerFor             FIUIAutomationElement2_get_CachedControllerFor ?
        get_CachedDescribedBy               FIUIAutomationElement2_get_CachedDescribedBy ?
        get_CachedFlowsTo                   FIUIAutomationElement2_get_CachedFlowsTo ?
        get_CachedProviderDescription       FIUIAutomationElement2_get_CachedProviderDescription ?
        GetClickablePoint                   FIUIAutomationElement2_GetClickablePoint ?
        get_CurrentOptimizeForVisualContent FIUIAutomationElement2_get_CurrentOptimizeForVisualContent ?
        get_CachedOptimizeForVisualContent  FIUIAutomationElement2_get_CachedOptimizeForVisualContent ?
        get_CurrentLiveSetting              FIUIAutomationElement2_get_CurrentLiveSetting ?
        get_CachedLiveSetting               FIUIAutomationElement2_get_CachedLiveSetting ?
        get_CurrentFlowsFrom                FIUIAutomationElement2_get_CurrentFlowsFrom ?
        get_CachedFlowsFrom                 FIUIAutomationElement2_get_CachedFlowsFrom ?
    STIUIAutomationElement2 ENDS

    IUIAutomationElement2 MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationElement2 PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationElement2>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationElement2
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationElement2_INTERFACE_DEFINED__

IFNDEF __IUIAutomationElement3_INTERFACE_DEFINED__
    __IUIAutomationElement3_INTERFACE_DEFINED__ EQU 1

    IUIAutomationElement3_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationElement3_QueryInterface TYPEDEF PTR IUIAutomationElement3_QueryInterface

    IUIAutomationElement3_GetRuntimeId TYPEDEF PROTO :XWORD, runtimeId:XWORD
    FIUIAutomationElement3_GetRuntimeId TYPEDEF PTR IUIAutomationElement3_GetRuntimeId

    IUIAutomationElement3_FindFirst TYPEDEF PROTO :XWORD, scope:XWORD, condition:XWORD, found:XWORD
    FIUIAutomationElement3_FindFirst TYPEDEF PTR IUIAutomationElement3_FindFirst

    IUIAutomationElement3_FindAll TYPEDEF PROTO :XWORD, scope:XWORD, condition:XWORD, found:XWORD
    FIUIAutomationElement3_FindAll TYPEDEF PTR IUIAutomationElement3_FindAll

    IUIAutomationElement3_FindFirstBuildCache TYPEDEF PROTO :XWORD, scope:XWORD, condition:XWORD, cacheRequest:XWORD, found:XWORD
    FIUIAutomationElement3_FindFirstBuildCache TYPEDEF PTR IUIAutomationElement3_FindFirstBuildCache

    IUIAutomationElement3_FindAllBuildCache TYPEDEF PROTO :XWORD, scope:XWORD, condition:XWORD, cacheRequest:XWORD, found:XWORD
    FIUIAutomationElement3_FindAllBuildCache TYPEDEF PTR IUIAutomationElement3_FindAllBuildCache

    IUIAutomationElement3_BuildUpdatedCache TYPEDEF PROTO :XWORD, cacheRequest:XWORD, updatedElement:XWORD
    FIUIAutomationElement3_BuildUpdatedCache TYPEDEF PTR IUIAutomationElement3_BuildUpdatedCache

    IUIAutomationElement3_GetCurrentPropertyValue TYPEDEF PROTO :XWORD, propertyId:XWORD, retVal:XWORD
    FIUIAutomationElement3_GetCurrentPropertyValue TYPEDEF PTR IUIAutomationElement3_GetCurrentPropertyValue

    IUIAutomationElement3_GetCurrentPropertyValueEx TYPEDEF PROTO :XWORD, propertyId:XWORD, ignoreDefaultValue:XWORD, retVal:XWORD
    FIUIAutomationElement3_GetCurrentPropertyValueEx TYPEDEF PTR IUIAutomationElement3_GetCurrentPropertyValueEx

    IUIAutomationElement3_GetCachedPropertyValue TYPEDEF PROTO :XWORD, propertyId:XWORD, retVal:XWORD
    FIUIAutomationElement3_GetCachedPropertyValue TYPEDEF PTR IUIAutomationElement3_GetCachedPropertyValue

    IUIAutomationElement3_GetCachedPropertyValueEx TYPEDEF PROTO :XWORD, propertyId:XWORD, ignoreDefaultValue:XWORD, retVal:XWORD
    FIUIAutomationElement3_GetCachedPropertyValueEx TYPEDEF PTR IUIAutomationElement3_GetCachedPropertyValueEx

    IUIAutomationElement3_GetCurrentPatternAs TYPEDEF PROTO :XWORD, patternId:XWORD, riid:XWORD, patternObject:XWORD
    FIUIAutomationElement3_GetCurrentPatternAs TYPEDEF PTR IUIAutomationElement3_GetCurrentPatternAs

    IUIAutomationElement3_GetCachedPatternAs TYPEDEF PROTO :XWORD, patternId:XWORD, riid:XWORD, patternObject:XWORD
    FIUIAutomationElement3_GetCachedPatternAs TYPEDEF PTR IUIAutomationElement3_GetCachedPatternAs

    IUIAutomationElement3_GetCurrentPattern TYPEDEF PROTO :XWORD, patternId:XWORD, patternObject:XWORD
    FIUIAutomationElement3_GetCurrentPattern TYPEDEF PTR IUIAutomationElement3_GetCurrentPattern

    IUIAutomationElement3_GetCachedPattern TYPEDEF PROTO :XWORD, patternId:XWORD, patternObject:XWORD
    FIUIAutomationElement3_GetCachedPattern TYPEDEF PTR IUIAutomationElement3_GetCachedPattern

    IUIAutomationElement3_GetCachedParent TYPEDEF PROTO :XWORD, parent:XWORD
    FIUIAutomationElement3_GetCachedParent TYPEDEF PTR IUIAutomationElement3_GetCachedParent

    IUIAutomationElement3_GetCachedChildren TYPEDEF PROTO :XWORD, children:XWORD
    FIUIAutomationElement3_GetCachedChildren TYPEDEF PTR IUIAutomationElement3_GetCachedChildren

    IUIAutomationElement3_get_CurrentProcessId TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CurrentProcessId TYPEDEF PTR IUIAutomationElement3_get_CurrentProcessId

    IUIAutomationElement3_get_CurrentControlType TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CurrentControlType TYPEDEF PTR IUIAutomationElement3_get_CurrentControlType

    IUIAutomationElement3_get_CurrentLocalizedControlType TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CurrentLocalizedControlType TYPEDEF PTR IUIAutomationElement3_get_CurrentLocalizedControlType

    IUIAutomationElement3_get_CurrentName TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CurrentName TYPEDEF PTR IUIAutomationElement3_get_CurrentName

    IUIAutomationElement3_get_CurrentAcceleratorKey TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CurrentAcceleratorKey TYPEDEF PTR IUIAutomationElement3_get_CurrentAcceleratorKey

    IUIAutomationElement3_get_CurrentAccessKey TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CurrentAccessKey TYPEDEF PTR IUIAutomationElement3_get_CurrentAccessKey

    IUIAutomationElement3_get_CurrentHasKeyboardFocus TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CurrentHasKeyboardFocus TYPEDEF PTR IUIAutomationElement3_get_CurrentHasKeyboardFocus

    IUIAutomationElement3_get_CurrentIsKeyboardFocusable TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CurrentIsKeyboardFocusable TYPEDEF PTR IUIAutomationElement3_get_CurrentIsKeyboardFocusable

    IUIAutomationElement3_get_CurrentIsEnabled TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CurrentIsEnabled TYPEDEF PTR IUIAutomationElement3_get_CurrentIsEnabled

    IUIAutomationElement3_get_CurrentAutomationId TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CurrentAutomationId TYPEDEF PTR IUIAutomationElement3_get_CurrentAutomationId

    IUIAutomationElement3_get_CurrentClassName TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CurrentClassName TYPEDEF PTR IUIAutomationElement3_get_CurrentClassName

    IUIAutomationElement3_get_CurrentHelpText TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CurrentHelpText TYPEDEF PTR IUIAutomationElement3_get_CurrentHelpText

    IUIAutomationElement3_get_CurrentCulture TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CurrentCulture TYPEDEF PTR IUIAutomationElement3_get_CurrentCulture

    IUIAutomationElement3_get_CurrentIsControlElement TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CurrentIsControlElement TYPEDEF PTR IUIAutomationElement3_get_CurrentIsControlElement

    IUIAutomationElement3_get_CurrentIsContentElement TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CurrentIsContentElement TYPEDEF PTR IUIAutomationElement3_get_CurrentIsContentElement

    IUIAutomationElement3_get_CurrentIsPassword TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CurrentIsPassword TYPEDEF PTR IUIAutomationElement3_get_CurrentIsPassword

    IUIAutomationElement3_get_CurrentNativeWindowHandle TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CurrentNativeWindowHandle TYPEDEF PTR IUIAutomationElement3_get_CurrentNativeWindowHandle

    IUIAutomationElement3_get_CurrentItemType TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CurrentItemType TYPEDEF PTR IUIAutomationElement3_get_CurrentItemType

    IUIAutomationElement3_get_CurrentIsOffscreen TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CurrentIsOffscreen TYPEDEF PTR IUIAutomationElement3_get_CurrentIsOffscreen

    IUIAutomationElement3_get_CurrentOrientation TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CurrentOrientation TYPEDEF PTR IUIAutomationElement3_get_CurrentOrientation

    IUIAutomationElement3_get_CurrentFrameworkId TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CurrentFrameworkId TYPEDEF PTR IUIAutomationElement3_get_CurrentFrameworkId

    IUIAutomationElement3_get_CurrentIsRequiredForForm TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CurrentIsRequiredForForm TYPEDEF PTR IUIAutomationElement3_get_CurrentIsRequiredForForm

    IUIAutomationElement3_get_CurrentItemStatus TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CurrentItemStatus TYPEDEF PTR IUIAutomationElement3_get_CurrentItemStatus

    IUIAutomationElement3_get_CurrentBoundingRectangle TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CurrentBoundingRectangle TYPEDEF PTR IUIAutomationElement3_get_CurrentBoundingRectangle

    IUIAutomationElement3_get_CurrentLabeledBy TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CurrentLabeledBy TYPEDEF PTR IUIAutomationElement3_get_CurrentLabeledBy

    IUIAutomationElement3_get_CurrentAriaRole TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CurrentAriaRole TYPEDEF PTR IUIAutomationElement3_get_CurrentAriaRole

    IUIAutomationElement3_get_CurrentAriaProperties TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CurrentAriaProperties TYPEDEF PTR IUIAutomationElement3_get_CurrentAriaProperties

    IUIAutomationElement3_get_CurrentIsDataValidForForm TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CurrentIsDataValidForForm TYPEDEF PTR IUIAutomationElement3_get_CurrentIsDataValidForForm

    IUIAutomationElement3_get_CurrentControllerFor TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CurrentControllerFor TYPEDEF PTR IUIAutomationElement3_get_CurrentControllerFor

    IUIAutomationElement3_get_CurrentDescribedBy TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CurrentDescribedBy TYPEDEF PTR IUIAutomationElement3_get_CurrentDescribedBy

    IUIAutomationElement3_get_CurrentFlowsTo TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CurrentFlowsTo TYPEDEF PTR IUIAutomationElement3_get_CurrentFlowsTo

    IUIAutomationElement3_get_CurrentProviderDescription TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CurrentProviderDescription TYPEDEF PTR IUIAutomationElement3_get_CurrentProviderDescription

    IUIAutomationElement3_get_CachedProcessId TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CachedProcessId TYPEDEF PTR IUIAutomationElement3_get_CachedProcessId

    IUIAutomationElement3_get_CachedControlType TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CachedControlType TYPEDEF PTR IUIAutomationElement3_get_CachedControlType

    IUIAutomationElement3_get_CachedLocalizedControlType TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CachedLocalizedControlType TYPEDEF PTR IUIAutomationElement3_get_CachedLocalizedControlType

    IUIAutomationElement3_get_CachedName TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CachedName TYPEDEF PTR IUIAutomationElement3_get_CachedName

    IUIAutomationElement3_get_CachedAcceleratorKey TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CachedAcceleratorKey TYPEDEF PTR IUIAutomationElement3_get_CachedAcceleratorKey

    IUIAutomationElement3_get_CachedAccessKey TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CachedAccessKey TYPEDEF PTR IUIAutomationElement3_get_CachedAccessKey

    IUIAutomationElement3_get_CachedHasKeyboardFocus TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CachedHasKeyboardFocus TYPEDEF PTR IUIAutomationElement3_get_CachedHasKeyboardFocus

    IUIAutomationElement3_get_CachedIsKeyboardFocusable TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CachedIsKeyboardFocusable TYPEDEF PTR IUIAutomationElement3_get_CachedIsKeyboardFocusable

    IUIAutomationElement3_get_CachedIsEnabled TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CachedIsEnabled TYPEDEF PTR IUIAutomationElement3_get_CachedIsEnabled

    IUIAutomationElement3_get_CachedAutomationId TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CachedAutomationId TYPEDEF PTR IUIAutomationElement3_get_CachedAutomationId

    IUIAutomationElement3_get_CachedClassName TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CachedClassName TYPEDEF PTR IUIAutomationElement3_get_CachedClassName

    IUIAutomationElement3_get_CachedHelpText TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CachedHelpText TYPEDEF PTR IUIAutomationElement3_get_CachedHelpText

    IUIAutomationElement3_get_CachedCulture TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CachedCulture TYPEDEF PTR IUIAutomationElement3_get_CachedCulture

    IUIAutomationElement3_get_CachedIsControlElement TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CachedIsControlElement TYPEDEF PTR IUIAutomationElement3_get_CachedIsControlElement

    IUIAutomationElement3_get_CachedIsContentElement TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CachedIsContentElement TYPEDEF PTR IUIAutomationElement3_get_CachedIsContentElement

    IUIAutomationElement3_get_CachedIsPassword TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CachedIsPassword TYPEDEF PTR IUIAutomationElement3_get_CachedIsPassword

    IUIAutomationElement3_get_CachedNativeWindowHandle TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CachedNativeWindowHandle TYPEDEF PTR IUIAutomationElement3_get_CachedNativeWindowHandle

    IUIAutomationElement3_get_CachedItemType TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CachedItemType TYPEDEF PTR IUIAutomationElement3_get_CachedItemType

    IUIAutomationElement3_get_CachedIsOffscreen TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CachedIsOffscreen TYPEDEF PTR IUIAutomationElement3_get_CachedIsOffscreen

    IUIAutomationElement3_get_CachedOrientation TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CachedOrientation TYPEDEF PTR IUIAutomationElement3_get_CachedOrientation

    IUIAutomationElement3_get_CachedFrameworkId TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CachedFrameworkId TYPEDEF PTR IUIAutomationElement3_get_CachedFrameworkId

    IUIAutomationElement3_get_CachedIsRequiredForForm TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CachedIsRequiredForForm TYPEDEF PTR IUIAutomationElement3_get_CachedIsRequiredForForm

    IUIAutomationElement3_get_CachedItemStatus TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CachedItemStatus TYPEDEF PTR IUIAutomationElement3_get_CachedItemStatus

    IUIAutomationElement3_get_CachedBoundingRectangle TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CachedBoundingRectangle TYPEDEF PTR IUIAutomationElement3_get_CachedBoundingRectangle

    IUIAutomationElement3_get_CachedLabeledBy TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CachedLabeledBy TYPEDEF PTR IUIAutomationElement3_get_CachedLabeledBy

    IUIAutomationElement3_get_CachedAriaRole TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CachedAriaRole TYPEDEF PTR IUIAutomationElement3_get_CachedAriaRole

    IUIAutomationElement3_get_CachedAriaProperties TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CachedAriaProperties TYPEDEF PTR IUIAutomationElement3_get_CachedAriaProperties

    IUIAutomationElement3_get_CachedIsDataValidForForm TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CachedIsDataValidForForm TYPEDEF PTR IUIAutomationElement3_get_CachedIsDataValidForForm

    IUIAutomationElement3_get_CachedControllerFor TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CachedControllerFor TYPEDEF PTR IUIAutomationElement3_get_CachedControllerFor

    IUIAutomationElement3_get_CachedDescribedBy TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CachedDescribedBy TYPEDEF PTR IUIAutomationElement3_get_CachedDescribedBy

    IUIAutomationElement3_get_CachedFlowsTo TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CachedFlowsTo TYPEDEF PTR IUIAutomationElement3_get_CachedFlowsTo

    IUIAutomationElement3_get_CachedProviderDescription TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CachedProviderDescription TYPEDEF PTR IUIAutomationElement3_get_CachedProviderDescription

    IUIAutomationElement3_GetClickablePoint TYPEDEF PROTO :XWORD, clickable:XWORD, gotClickable:XWORD
    FIUIAutomationElement3_GetClickablePoint TYPEDEF PTR IUIAutomationElement3_GetClickablePoint

    IUIAutomationElement3_get_CurrentOptimizeForVisualContent TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CurrentOptimizeForVisualContent TYPEDEF PTR IUIAutomationElement3_get_CurrentOptimizeForVisualContent

    IUIAutomationElement3_get_CachedOptimizeForVisualContent TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CachedOptimizeForVisualContent TYPEDEF PTR IUIAutomationElement3_get_CachedOptimizeForVisualContent

    IUIAutomationElement3_get_CurrentLiveSetting TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CurrentLiveSetting TYPEDEF PTR IUIAutomationElement3_get_CurrentLiveSetting

    IUIAutomationElement3_get_CachedLiveSetting TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CachedLiveSetting TYPEDEF PTR IUIAutomationElement3_get_CachedLiveSetting

    IUIAutomationElement3_get_CurrentFlowsFrom TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CurrentFlowsFrom TYPEDEF PTR IUIAutomationElement3_get_CurrentFlowsFrom

    IUIAutomationElement3_get_CachedFlowsFrom TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CachedFlowsFrom TYPEDEF PTR IUIAutomationElement3_get_CachedFlowsFrom

    IUIAutomationElement3_get_CurrentIsPeripheral TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CurrentIsPeripheral TYPEDEF PTR IUIAutomationElement3_get_CurrentIsPeripheral

    IUIAutomationElement3_get_CachedIsPeripheral TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement3_get_CachedIsPeripheral TYPEDEF PTR IUIAutomationElement3_get_CachedIsPeripheral

    STIUIAutomationElement3 STRUCT
        QueryInterface                      FIUIAutomationElement3_QueryInterface ?
        AddRef                              XPTR ?
        Release                             XPTR ?
        SetFocus1                           XPTR ?
        GetRuntimeId                        FIUIAutomationElement3_GetRuntimeId ?
        FindFirst                           FIUIAutomationElement3_FindFirst ?
        FindAll                             FIUIAutomationElement3_FindAll ?
        FindFirstBuildCache                 FIUIAutomationElement3_FindFirstBuildCache ?
        FindAllBuildCache                   FIUIAutomationElement3_FindAllBuildCache ?
        BuildUpdatedCache                   FIUIAutomationElement3_BuildUpdatedCache ?
        GetCurrentPropertyValue             FIUIAutomationElement3_GetCurrentPropertyValue ?
        GetCurrentPropertyValueEx           FIUIAutomationElement3_GetCurrentPropertyValueEx ?
        GetCachedPropertyValue              FIUIAutomationElement3_GetCachedPropertyValue ?
        GetCachedPropertyValueEx            FIUIAutomationElement3_GetCachedPropertyValueEx ?
        GetCurrentPatternAs                 FIUIAutomationElement3_GetCurrentPatternAs ?
        GetCachedPatternAs                  FIUIAutomationElement3_GetCachedPatternAs ?
        GetCurrentPattern                   FIUIAutomationElement3_GetCurrentPattern ?
        GetCachedPattern                    FIUIAutomationElement3_GetCachedPattern ?
        GetCachedParent                     FIUIAutomationElement3_GetCachedParent ?
        GetCachedChildren                   FIUIAutomationElement3_GetCachedChildren ?
        get_CurrentProcessId                FIUIAutomationElement3_get_CurrentProcessId ?
        get_CurrentControlType              FIUIAutomationElement3_get_CurrentControlType ?
        get_CurrentLocalizedControlType     FIUIAutomationElement3_get_CurrentLocalizedControlType ?
        get_CurrentName                     FIUIAutomationElement3_get_CurrentName ?
        get_CurrentAcceleratorKey           FIUIAutomationElement3_get_CurrentAcceleratorKey ?
        get_CurrentAccessKey                FIUIAutomationElement3_get_CurrentAccessKey ?
        get_CurrentHasKeyboardFocus         FIUIAutomationElement3_get_CurrentHasKeyboardFocus ?
        get_CurrentIsKeyboardFocusable      FIUIAutomationElement3_get_CurrentIsKeyboardFocusable ?
        get_CurrentIsEnabled                FIUIAutomationElement3_get_CurrentIsEnabled ?
        get_CurrentAutomationId             FIUIAutomationElement3_get_CurrentAutomationId ?
        get_CurrentClassName                FIUIAutomationElement3_get_CurrentClassName ?
        get_CurrentHelpText                 FIUIAutomationElement3_get_CurrentHelpText ?
        get_CurrentCulture                  FIUIAutomationElement3_get_CurrentCulture ?
        get_CurrentIsControlElement         FIUIAutomationElement3_get_CurrentIsControlElement ?
        get_CurrentIsContentElement         FIUIAutomationElement3_get_CurrentIsContentElement ?
        get_CurrentIsPassword               FIUIAutomationElement3_get_CurrentIsPassword ?
        get_CurrentNativeWindowHandle       FIUIAutomationElement3_get_CurrentNativeWindowHandle ?
        get_CurrentItemType                 FIUIAutomationElement3_get_CurrentItemType ?
        get_CurrentIsOffscreen              FIUIAutomationElement3_get_CurrentIsOffscreen ?
        get_CurrentOrientation              FIUIAutomationElement3_get_CurrentOrientation ?
        get_CurrentFrameworkId              FIUIAutomationElement3_get_CurrentFrameworkId ?
        get_CurrentIsRequiredForForm        FIUIAutomationElement3_get_CurrentIsRequiredForForm ?
        get_CurrentItemStatus               FIUIAutomationElement3_get_CurrentItemStatus ?
        get_CurrentBoundingRectangle        FIUIAutomationElement3_get_CurrentBoundingRectangle ?
        get_CurrentLabeledBy                FIUIAutomationElement3_get_CurrentLabeledBy ?
        get_CurrentAriaRole                 FIUIAutomationElement3_get_CurrentAriaRole ?
        get_CurrentAriaProperties           FIUIAutomationElement3_get_CurrentAriaProperties ?
        get_CurrentIsDataValidForForm       FIUIAutomationElement3_get_CurrentIsDataValidForForm ?
        get_CurrentControllerFor            FIUIAutomationElement3_get_CurrentControllerFor ?
        get_CurrentDescribedBy              FIUIAutomationElement3_get_CurrentDescribedBy ?
        get_CurrentFlowsTo                  FIUIAutomationElement3_get_CurrentFlowsTo ?
        get_CurrentProviderDescription      FIUIAutomationElement3_get_CurrentProviderDescription ?
        get_CachedProcessId                 FIUIAutomationElement3_get_CachedProcessId ?
        get_CachedControlType               FIUIAutomationElement3_get_CachedControlType ?
        get_CachedLocalizedControlType      FIUIAutomationElement3_get_CachedLocalizedControlType ?
        get_CachedName                      FIUIAutomationElement3_get_CachedName ?
        get_CachedAcceleratorKey            FIUIAutomationElement3_get_CachedAcceleratorKey ?
        get_CachedAccessKey                 FIUIAutomationElement3_get_CachedAccessKey ?
        get_CachedHasKeyboardFocus          FIUIAutomationElement3_get_CachedHasKeyboardFocus ?
        get_CachedIsKeyboardFocusable       FIUIAutomationElement3_get_CachedIsKeyboardFocusable ?
        get_CachedIsEnabled                 FIUIAutomationElement3_get_CachedIsEnabled ?
        get_CachedAutomationId              FIUIAutomationElement3_get_CachedAutomationId ?
        get_CachedClassName                 FIUIAutomationElement3_get_CachedClassName ?
        get_CachedHelpText                  FIUIAutomationElement3_get_CachedHelpText ?
        get_CachedCulture                   FIUIAutomationElement3_get_CachedCulture ?
        get_CachedIsControlElement          FIUIAutomationElement3_get_CachedIsControlElement ?
        get_CachedIsContentElement          FIUIAutomationElement3_get_CachedIsContentElement ?
        get_CachedIsPassword                FIUIAutomationElement3_get_CachedIsPassword ?
        get_CachedNativeWindowHandle        FIUIAutomationElement3_get_CachedNativeWindowHandle ?
        get_CachedItemType                  FIUIAutomationElement3_get_CachedItemType ?
        get_CachedIsOffscreen               FIUIAutomationElement3_get_CachedIsOffscreen ?
        get_CachedOrientation               FIUIAutomationElement3_get_CachedOrientation ?
        get_CachedFrameworkId               FIUIAutomationElement3_get_CachedFrameworkId ?
        get_CachedIsRequiredForForm         FIUIAutomationElement3_get_CachedIsRequiredForForm ?
        get_CachedItemStatus                FIUIAutomationElement3_get_CachedItemStatus ?
        get_CachedBoundingRectangle         FIUIAutomationElement3_get_CachedBoundingRectangle ?
        get_CachedLabeledBy                 FIUIAutomationElement3_get_CachedLabeledBy ?
        get_CachedAriaRole                  FIUIAutomationElement3_get_CachedAriaRole ?
        get_CachedAriaProperties            FIUIAutomationElement3_get_CachedAriaProperties ?
        get_CachedIsDataValidForForm        FIUIAutomationElement3_get_CachedIsDataValidForForm ?
        get_CachedControllerFor             FIUIAutomationElement3_get_CachedControllerFor ?
        get_CachedDescribedBy               FIUIAutomationElement3_get_CachedDescribedBy ?
        get_CachedFlowsTo                   FIUIAutomationElement3_get_CachedFlowsTo ?
        get_CachedProviderDescription       FIUIAutomationElement3_get_CachedProviderDescription ?
        GetClickablePoint                   FIUIAutomationElement3_GetClickablePoint ?
        get_CurrentOptimizeForVisualContent FIUIAutomationElement3_get_CurrentOptimizeForVisualContent ?
        get_CachedOptimizeForVisualContent  FIUIAutomationElement3_get_CachedOptimizeForVisualContent ?
        get_CurrentLiveSetting              FIUIAutomationElement3_get_CurrentLiveSetting ?
        get_CachedLiveSetting               FIUIAutomationElement3_get_CachedLiveSetting ?
        get_CurrentFlowsFrom                FIUIAutomationElement3_get_CurrentFlowsFrom ?
        get_CachedFlowsFrom                 FIUIAutomationElement3_get_CachedFlowsFrom ?
        ShowContextMenu                     XPTR ?
        get_CurrentIsPeripheral             FIUIAutomationElement3_get_CurrentIsPeripheral ?
        get_CachedIsPeripheral              FIUIAutomationElement3_get_CachedIsPeripheral ?
    STIUIAutomationElement3 ENDS

    IUIAutomationElement3 MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationElement3 PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationElement3>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationElement3
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationElement3_INTERFACE_DEFINED__

IFNDEF __IUIAutomationElement4_INTERFACE_DEFINED__
    __IUIAutomationElement4_INTERFACE_DEFINED__ EQU 1

    IUIAutomationElement4_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationElement4_QueryInterface TYPEDEF PTR IUIAutomationElement4_QueryInterface

    IUIAutomationElement4_GetRuntimeId TYPEDEF PROTO :XWORD, runtimeId:XWORD
    FIUIAutomationElement4_GetRuntimeId TYPEDEF PTR IUIAutomationElement4_GetRuntimeId

    IUIAutomationElement4_FindFirst TYPEDEF PROTO :XWORD, scope:XWORD, condition:XWORD, found:XWORD
    FIUIAutomationElement4_FindFirst TYPEDEF PTR IUIAutomationElement4_FindFirst

    IUIAutomationElement4_FindAll TYPEDEF PROTO :XWORD, scope:XWORD, condition:XWORD, found:XWORD
    FIUIAutomationElement4_FindAll TYPEDEF PTR IUIAutomationElement4_FindAll

    IUIAutomationElement4_FindFirstBuildCache TYPEDEF PROTO :XWORD, scope:XWORD, condition:XWORD, cacheRequest:XWORD, found:XWORD
    FIUIAutomationElement4_FindFirstBuildCache TYPEDEF PTR IUIAutomationElement4_FindFirstBuildCache

    IUIAutomationElement4_FindAllBuildCache TYPEDEF PROTO :XWORD, scope:XWORD, condition:XWORD, cacheRequest:XWORD, found:XWORD
    FIUIAutomationElement4_FindAllBuildCache TYPEDEF PTR IUIAutomationElement4_FindAllBuildCache

    IUIAutomationElement4_BuildUpdatedCache TYPEDEF PROTO :XWORD, cacheRequest:XWORD, updatedElement:XWORD
    FIUIAutomationElement4_BuildUpdatedCache TYPEDEF PTR IUIAutomationElement4_BuildUpdatedCache

    IUIAutomationElement4_GetCurrentPropertyValue TYPEDEF PROTO :XWORD, propertyId:XWORD, retVal:XWORD
    FIUIAutomationElement4_GetCurrentPropertyValue TYPEDEF PTR IUIAutomationElement4_GetCurrentPropertyValue

    IUIAutomationElement4_GetCurrentPropertyValueEx TYPEDEF PROTO :XWORD, propertyId:XWORD, ignoreDefaultValue:XWORD, retVal:XWORD
    FIUIAutomationElement4_GetCurrentPropertyValueEx TYPEDEF PTR IUIAutomationElement4_GetCurrentPropertyValueEx

    IUIAutomationElement4_GetCachedPropertyValue TYPEDEF PROTO :XWORD, propertyId:XWORD, retVal:XWORD
    FIUIAutomationElement4_GetCachedPropertyValue TYPEDEF PTR IUIAutomationElement4_GetCachedPropertyValue

    IUIAutomationElement4_GetCachedPropertyValueEx TYPEDEF PROTO :XWORD, propertyId:XWORD, ignoreDefaultValue:XWORD, retVal:XWORD
    FIUIAutomationElement4_GetCachedPropertyValueEx TYPEDEF PTR IUIAutomationElement4_GetCachedPropertyValueEx

    IUIAutomationElement4_GetCurrentPatternAs TYPEDEF PROTO :XWORD, patternId:XWORD, riid:XWORD, patternObject:XWORD
    FIUIAutomationElement4_GetCurrentPatternAs TYPEDEF PTR IUIAutomationElement4_GetCurrentPatternAs

    IUIAutomationElement4_GetCachedPatternAs TYPEDEF PROTO :XWORD, patternId:XWORD, riid:XWORD, patternObject:XWORD
    FIUIAutomationElement4_GetCachedPatternAs TYPEDEF PTR IUIAutomationElement4_GetCachedPatternAs

    IUIAutomationElement4_GetCurrentPattern TYPEDEF PROTO :XWORD, patternId:XWORD, patternObject:XWORD
    FIUIAutomationElement4_GetCurrentPattern TYPEDEF PTR IUIAutomationElement4_GetCurrentPattern

    IUIAutomationElement4_GetCachedPattern TYPEDEF PROTO :XWORD, patternId:XWORD, patternObject:XWORD
    FIUIAutomationElement4_GetCachedPattern TYPEDEF PTR IUIAutomationElement4_GetCachedPattern

    IUIAutomationElement4_GetCachedParent TYPEDEF PROTO :XWORD, parent:XWORD
    FIUIAutomationElement4_GetCachedParent TYPEDEF PTR IUIAutomationElement4_GetCachedParent

    IUIAutomationElement4_GetCachedChildren TYPEDEF PROTO :XWORD, children:XWORD
    FIUIAutomationElement4_GetCachedChildren TYPEDEF PTR IUIAutomationElement4_GetCachedChildren

    IUIAutomationElement4_get_CurrentProcessId TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CurrentProcessId TYPEDEF PTR IUIAutomationElement4_get_CurrentProcessId

    IUIAutomationElement4_get_CurrentControlType TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CurrentControlType TYPEDEF PTR IUIAutomationElement4_get_CurrentControlType

    IUIAutomationElement4_get_CurrentLocalizedControlType TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CurrentLocalizedControlType TYPEDEF PTR IUIAutomationElement4_get_CurrentLocalizedControlType

    IUIAutomationElement4_get_CurrentName TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CurrentName TYPEDEF PTR IUIAutomationElement4_get_CurrentName

    IUIAutomationElement4_get_CurrentAcceleratorKey TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CurrentAcceleratorKey TYPEDEF PTR IUIAutomationElement4_get_CurrentAcceleratorKey

    IUIAutomationElement4_get_CurrentAccessKey TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CurrentAccessKey TYPEDEF PTR IUIAutomationElement4_get_CurrentAccessKey

    IUIAutomationElement4_get_CurrentHasKeyboardFocus TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CurrentHasKeyboardFocus TYPEDEF PTR IUIAutomationElement4_get_CurrentHasKeyboardFocus

    IUIAutomationElement4_get_CurrentIsKeyboardFocusable TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CurrentIsKeyboardFocusable TYPEDEF PTR IUIAutomationElement4_get_CurrentIsKeyboardFocusable

    IUIAutomationElement4_get_CurrentIsEnabled TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CurrentIsEnabled TYPEDEF PTR IUIAutomationElement4_get_CurrentIsEnabled

    IUIAutomationElement4_get_CurrentAutomationId TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CurrentAutomationId TYPEDEF PTR IUIAutomationElement4_get_CurrentAutomationId

    IUIAutomationElement4_get_CurrentClassName TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CurrentClassName TYPEDEF PTR IUIAutomationElement4_get_CurrentClassName

    IUIAutomationElement4_get_CurrentHelpText TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CurrentHelpText TYPEDEF PTR IUIAutomationElement4_get_CurrentHelpText

    IUIAutomationElement4_get_CurrentCulture TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CurrentCulture TYPEDEF PTR IUIAutomationElement4_get_CurrentCulture

    IUIAutomationElement4_get_CurrentIsControlElement TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CurrentIsControlElement TYPEDEF PTR IUIAutomationElement4_get_CurrentIsControlElement

    IUIAutomationElement4_get_CurrentIsContentElement TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CurrentIsContentElement TYPEDEF PTR IUIAutomationElement4_get_CurrentIsContentElement

    IUIAutomationElement4_get_CurrentIsPassword TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CurrentIsPassword TYPEDEF PTR IUIAutomationElement4_get_CurrentIsPassword

    IUIAutomationElement4_get_CurrentNativeWindowHandle TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CurrentNativeWindowHandle TYPEDEF PTR IUIAutomationElement4_get_CurrentNativeWindowHandle

    IUIAutomationElement4_get_CurrentItemType TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CurrentItemType TYPEDEF PTR IUIAutomationElement4_get_CurrentItemType

    IUIAutomationElement4_get_CurrentIsOffscreen TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CurrentIsOffscreen TYPEDEF PTR IUIAutomationElement4_get_CurrentIsOffscreen

    IUIAutomationElement4_get_CurrentOrientation TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CurrentOrientation TYPEDEF PTR IUIAutomationElement4_get_CurrentOrientation

    IUIAutomationElement4_get_CurrentFrameworkId TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CurrentFrameworkId TYPEDEF PTR IUIAutomationElement4_get_CurrentFrameworkId

    IUIAutomationElement4_get_CurrentIsRequiredForForm TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CurrentIsRequiredForForm TYPEDEF PTR IUIAutomationElement4_get_CurrentIsRequiredForForm

    IUIAutomationElement4_get_CurrentItemStatus TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CurrentItemStatus TYPEDEF PTR IUIAutomationElement4_get_CurrentItemStatus

    IUIAutomationElement4_get_CurrentBoundingRectangle TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CurrentBoundingRectangle TYPEDEF PTR IUIAutomationElement4_get_CurrentBoundingRectangle

    IUIAutomationElement4_get_CurrentLabeledBy TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CurrentLabeledBy TYPEDEF PTR IUIAutomationElement4_get_CurrentLabeledBy

    IUIAutomationElement4_get_CurrentAriaRole TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CurrentAriaRole TYPEDEF PTR IUIAutomationElement4_get_CurrentAriaRole

    IUIAutomationElement4_get_CurrentAriaProperties TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CurrentAriaProperties TYPEDEF PTR IUIAutomationElement4_get_CurrentAriaProperties

    IUIAutomationElement4_get_CurrentIsDataValidForForm TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CurrentIsDataValidForForm TYPEDEF PTR IUIAutomationElement4_get_CurrentIsDataValidForForm

    IUIAutomationElement4_get_CurrentControllerFor TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CurrentControllerFor TYPEDEF PTR IUIAutomationElement4_get_CurrentControllerFor

    IUIAutomationElement4_get_CurrentDescribedBy TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CurrentDescribedBy TYPEDEF PTR IUIAutomationElement4_get_CurrentDescribedBy

    IUIAutomationElement4_get_CurrentFlowsTo TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CurrentFlowsTo TYPEDEF PTR IUIAutomationElement4_get_CurrentFlowsTo

    IUIAutomationElement4_get_CurrentProviderDescription TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CurrentProviderDescription TYPEDEF PTR IUIAutomationElement4_get_CurrentProviderDescription

    IUIAutomationElement4_get_CachedProcessId TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CachedProcessId TYPEDEF PTR IUIAutomationElement4_get_CachedProcessId

    IUIAutomationElement4_get_CachedControlType TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CachedControlType TYPEDEF PTR IUIAutomationElement4_get_CachedControlType

    IUIAutomationElement4_get_CachedLocalizedControlType TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CachedLocalizedControlType TYPEDEF PTR IUIAutomationElement4_get_CachedLocalizedControlType

    IUIAutomationElement4_get_CachedName TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CachedName TYPEDEF PTR IUIAutomationElement4_get_CachedName

    IUIAutomationElement4_get_CachedAcceleratorKey TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CachedAcceleratorKey TYPEDEF PTR IUIAutomationElement4_get_CachedAcceleratorKey

    IUIAutomationElement4_get_CachedAccessKey TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CachedAccessKey TYPEDEF PTR IUIAutomationElement4_get_CachedAccessKey

    IUIAutomationElement4_get_CachedHasKeyboardFocus TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CachedHasKeyboardFocus TYPEDEF PTR IUIAutomationElement4_get_CachedHasKeyboardFocus

    IUIAutomationElement4_get_CachedIsKeyboardFocusable TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CachedIsKeyboardFocusable TYPEDEF PTR IUIAutomationElement4_get_CachedIsKeyboardFocusable

    IUIAutomationElement4_get_CachedIsEnabled TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CachedIsEnabled TYPEDEF PTR IUIAutomationElement4_get_CachedIsEnabled

    IUIAutomationElement4_get_CachedAutomationId TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CachedAutomationId TYPEDEF PTR IUIAutomationElement4_get_CachedAutomationId

    IUIAutomationElement4_get_CachedClassName TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CachedClassName TYPEDEF PTR IUIAutomationElement4_get_CachedClassName

    IUIAutomationElement4_get_CachedHelpText TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CachedHelpText TYPEDEF PTR IUIAutomationElement4_get_CachedHelpText

    IUIAutomationElement4_get_CachedCulture TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CachedCulture TYPEDEF PTR IUIAutomationElement4_get_CachedCulture

    IUIAutomationElement4_get_CachedIsControlElement TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CachedIsControlElement TYPEDEF PTR IUIAutomationElement4_get_CachedIsControlElement

    IUIAutomationElement4_get_CachedIsContentElement TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CachedIsContentElement TYPEDEF PTR IUIAutomationElement4_get_CachedIsContentElement

    IUIAutomationElement4_get_CachedIsPassword TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CachedIsPassword TYPEDEF PTR IUIAutomationElement4_get_CachedIsPassword

    IUIAutomationElement4_get_CachedNativeWindowHandle TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CachedNativeWindowHandle TYPEDEF PTR IUIAutomationElement4_get_CachedNativeWindowHandle

    IUIAutomationElement4_get_CachedItemType TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CachedItemType TYPEDEF PTR IUIAutomationElement4_get_CachedItemType

    IUIAutomationElement4_get_CachedIsOffscreen TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CachedIsOffscreen TYPEDEF PTR IUIAutomationElement4_get_CachedIsOffscreen

    IUIAutomationElement4_get_CachedOrientation TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CachedOrientation TYPEDEF PTR IUIAutomationElement4_get_CachedOrientation

    IUIAutomationElement4_get_CachedFrameworkId TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CachedFrameworkId TYPEDEF PTR IUIAutomationElement4_get_CachedFrameworkId

    IUIAutomationElement4_get_CachedIsRequiredForForm TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CachedIsRequiredForForm TYPEDEF PTR IUIAutomationElement4_get_CachedIsRequiredForForm

    IUIAutomationElement4_get_CachedItemStatus TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CachedItemStatus TYPEDEF PTR IUIAutomationElement4_get_CachedItemStatus

    IUIAutomationElement4_get_CachedBoundingRectangle TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CachedBoundingRectangle TYPEDEF PTR IUIAutomationElement4_get_CachedBoundingRectangle

    IUIAutomationElement4_get_CachedLabeledBy TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CachedLabeledBy TYPEDEF PTR IUIAutomationElement4_get_CachedLabeledBy

    IUIAutomationElement4_get_CachedAriaRole TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CachedAriaRole TYPEDEF PTR IUIAutomationElement4_get_CachedAriaRole

    IUIAutomationElement4_get_CachedAriaProperties TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CachedAriaProperties TYPEDEF PTR IUIAutomationElement4_get_CachedAriaProperties

    IUIAutomationElement4_get_CachedIsDataValidForForm TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CachedIsDataValidForForm TYPEDEF PTR IUIAutomationElement4_get_CachedIsDataValidForForm

    IUIAutomationElement4_get_CachedControllerFor TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CachedControllerFor TYPEDEF PTR IUIAutomationElement4_get_CachedControllerFor

    IUIAutomationElement4_get_CachedDescribedBy TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CachedDescribedBy TYPEDEF PTR IUIAutomationElement4_get_CachedDescribedBy

    IUIAutomationElement4_get_CachedFlowsTo TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CachedFlowsTo TYPEDEF PTR IUIAutomationElement4_get_CachedFlowsTo

    IUIAutomationElement4_get_CachedProviderDescription TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CachedProviderDescription TYPEDEF PTR IUIAutomationElement4_get_CachedProviderDescription

    IUIAutomationElement4_GetClickablePoint TYPEDEF PROTO :XWORD, clickable:XWORD, gotClickable:XWORD
    FIUIAutomationElement4_GetClickablePoint TYPEDEF PTR IUIAutomationElement4_GetClickablePoint

    IUIAutomationElement4_get_CurrentOptimizeForVisualContent TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CurrentOptimizeForVisualContent TYPEDEF PTR IUIAutomationElement4_get_CurrentOptimizeForVisualContent

    IUIAutomationElement4_get_CachedOptimizeForVisualContent TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CachedOptimizeForVisualContent TYPEDEF PTR IUIAutomationElement4_get_CachedOptimizeForVisualContent

    IUIAutomationElement4_get_CurrentLiveSetting TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CurrentLiveSetting TYPEDEF PTR IUIAutomationElement4_get_CurrentLiveSetting

    IUIAutomationElement4_get_CachedLiveSetting TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CachedLiveSetting TYPEDEF PTR IUIAutomationElement4_get_CachedLiveSetting

    IUIAutomationElement4_get_CurrentFlowsFrom TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CurrentFlowsFrom TYPEDEF PTR IUIAutomationElement4_get_CurrentFlowsFrom

    IUIAutomationElement4_get_CachedFlowsFrom TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CachedFlowsFrom TYPEDEF PTR IUIAutomationElement4_get_CachedFlowsFrom

    IUIAutomationElement4_get_CurrentIsPeripheral TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CurrentIsPeripheral TYPEDEF PTR IUIAutomationElement4_get_CurrentIsPeripheral

    IUIAutomationElement4_get_CachedIsPeripheral TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CachedIsPeripheral TYPEDEF PTR IUIAutomationElement4_get_CachedIsPeripheral

    IUIAutomationElement4_get_CurrentPositionInSet TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CurrentPositionInSet TYPEDEF PTR IUIAutomationElement4_get_CurrentPositionInSet

    IUIAutomationElement4_get_CurrentSizeOfSet TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CurrentSizeOfSet TYPEDEF PTR IUIAutomationElement4_get_CurrentSizeOfSet

    IUIAutomationElement4_get_CurrentLevel TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CurrentLevel TYPEDEF PTR IUIAutomationElement4_get_CurrentLevel

    IUIAutomationElement4_get_CurrentAnnotationTypes TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CurrentAnnotationTypes TYPEDEF PTR IUIAutomationElement4_get_CurrentAnnotationTypes

    IUIAutomationElement4_get_CurrentAnnotationObjects TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CurrentAnnotationObjects TYPEDEF PTR IUIAutomationElement4_get_CurrentAnnotationObjects

    IUIAutomationElement4_get_CachedPositionInSet TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CachedPositionInSet TYPEDEF PTR IUIAutomationElement4_get_CachedPositionInSet

    IUIAutomationElement4_get_CachedSizeOfSet TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CachedSizeOfSet TYPEDEF PTR IUIAutomationElement4_get_CachedSizeOfSet

    IUIAutomationElement4_get_CachedLevel TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CachedLevel TYPEDEF PTR IUIAutomationElement4_get_CachedLevel

    IUIAutomationElement4_get_CachedAnnotationTypes TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CachedAnnotationTypes TYPEDEF PTR IUIAutomationElement4_get_CachedAnnotationTypes

    IUIAutomationElement4_get_CachedAnnotationObjects TYPEDEF PROTO :XWORD, retVal:XWORD
    FIUIAutomationElement4_get_CachedAnnotationObjects TYPEDEF PTR IUIAutomationElement4_get_CachedAnnotationObjects

    STIUIAutomationElement4 STRUCT
        QueryInterface                      FIUIAutomationElement4_QueryInterface ?
        AddRef                              XPTR ?
        Release                             XPTR ?
        SetFocus1                           XPTR ?
        GetRuntimeId                        FIUIAutomationElement4_GetRuntimeId ?
        FindFirst                           FIUIAutomationElement4_FindFirst ?
        FindAll                             FIUIAutomationElement4_FindAll ?
        FindFirstBuildCache                 FIUIAutomationElement4_FindFirstBuildCache ?
        FindAllBuildCache                   FIUIAutomationElement4_FindAllBuildCache ?
        BuildUpdatedCache                   FIUIAutomationElement4_BuildUpdatedCache ?
        GetCurrentPropertyValue             FIUIAutomationElement4_GetCurrentPropertyValue ?
        GetCurrentPropertyValueEx           FIUIAutomationElement4_GetCurrentPropertyValueEx ?
        GetCachedPropertyValue              FIUIAutomationElement4_GetCachedPropertyValue ?
        GetCachedPropertyValueEx            FIUIAutomationElement4_GetCachedPropertyValueEx ?
        GetCurrentPatternAs                 FIUIAutomationElement4_GetCurrentPatternAs ?
        GetCachedPatternAs                  FIUIAutomationElement4_GetCachedPatternAs ?
        GetCurrentPattern                   FIUIAutomationElement4_GetCurrentPattern ?
        GetCachedPattern                    FIUIAutomationElement4_GetCachedPattern ?
        GetCachedParent                     FIUIAutomationElement4_GetCachedParent ?
        GetCachedChildren                   FIUIAutomationElement4_GetCachedChildren ?
        get_CurrentProcessId                FIUIAutomationElement4_get_CurrentProcessId ?
        get_CurrentControlType              FIUIAutomationElement4_get_CurrentControlType ?
        get_CurrentLocalizedControlType     FIUIAutomationElement4_get_CurrentLocalizedControlType ?
        get_CurrentName                     FIUIAutomationElement4_get_CurrentName ?
        get_CurrentAcceleratorKey           FIUIAutomationElement4_get_CurrentAcceleratorKey ?
        get_CurrentAccessKey                FIUIAutomationElement4_get_CurrentAccessKey ?
        get_CurrentHasKeyboardFocus         FIUIAutomationElement4_get_CurrentHasKeyboardFocus ?
        get_CurrentIsKeyboardFocusable      FIUIAutomationElement4_get_CurrentIsKeyboardFocusable ?
        get_CurrentIsEnabled                FIUIAutomationElement4_get_CurrentIsEnabled ?
        get_CurrentAutomationId             FIUIAutomationElement4_get_CurrentAutomationId ?
        get_CurrentClassName                FIUIAutomationElement4_get_CurrentClassName ?
        get_CurrentHelpText                 FIUIAutomationElement4_get_CurrentHelpText ?
        get_CurrentCulture                  FIUIAutomationElement4_get_CurrentCulture ?
        get_CurrentIsControlElement         FIUIAutomationElement4_get_CurrentIsControlElement ?
        get_CurrentIsContentElement         FIUIAutomationElement4_get_CurrentIsContentElement ?
        get_CurrentIsPassword               FIUIAutomationElement4_get_CurrentIsPassword ?
        get_CurrentNativeWindowHandle       FIUIAutomationElement4_get_CurrentNativeWindowHandle ?
        get_CurrentItemType                 FIUIAutomationElement4_get_CurrentItemType ?
        get_CurrentIsOffscreen              FIUIAutomationElement4_get_CurrentIsOffscreen ?
        get_CurrentOrientation              FIUIAutomationElement4_get_CurrentOrientation ?
        get_CurrentFrameworkId              FIUIAutomationElement4_get_CurrentFrameworkId ?
        get_CurrentIsRequiredForForm        FIUIAutomationElement4_get_CurrentIsRequiredForForm ?
        get_CurrentItemStatus               FIUIAutomationElement4_get_CurrentItemStatus ?
        get_CurrentBoundingRectangle        FIUIAutomationElement4_get_CurrentBoundingRectangle ?
        get_CurrentLabeledBy                FIUIAutomationElement4_get_CurrentLabeledBy ?
        get_CurrentAriaRole                 FIUIAutomationElement4_get_CurrentAriaRole ?
        get_CurrentAriaProperties           FIUIAutomationElement4_get_CurrentAriaProperties ?
        get_CurrentIsDataValidForForm       FIUIAutomationElement4_get_CurrentIsDataValidForForm ?
        get_CurrentControllerFor            FIUIAutomationElement4_get_CurrentControllerFor ?
        get_CurrentDescribedBy              FIUIAutomationElement4_get_CurrentDescribedBy ?
        get_CurrentFlowsTo                  FIUIAutomationElement4_get_CurrentFlowsTo ?
        get_CurrentProviderDescription      FIUIAutomationElement4_get_CurrentProviderDescription ?
        get_CachedProcessId                 FIUIAutomationElement4_get_CachedProcessId ?
        get_CachedControlType               FIUIAutomationElement4_get_CachedControlType ?
        get_CachedLocalizedControlType      FIUIAutomationElement4_get_CachedLocalizedControlType ?
        get_CachedName                      FIUIAutomationElement4_get_CachedName ?
        get_CachedAcceleratorKey            FIUIAutomationElement4_get_CachedAcceleratorKey ?
        get_CachedAccessKey                 FIUIAutomationElement4_get_CachedAccessKey ?
        get_CachedHasKeyboardFocus          FIUIAutomationElement4_get_CachedHasKeyboardFocus ?
        get_CachedIsKeyboardFocusable       FIUIAutomationElement4_get_CachedIsKeyboardFocusable ?
        get_CachedIsEnabled                 FIUIAutomationElement4_get_CachedIsEnabled ?
        get_CachedAutomationId              FIUIAutomationElement4_get_CachedAutomationId ?
        get_CachedClassName                 FIUIAutomationElement4_get_CachedClassName ?
        get_CachedHelpText                  FIUIAutomationElement4_get_CachedHelpText ?
        get_CachedCulture                   FIUIAutomationElement4_get_CachedCulture ?
        get_CachedIsControlElement          FIUIAutomationElement4_get_CachedIsControlElement ?
        get_CachedIsContentElement          FIUIAutomationElement4_get_CachedIsContentElement ?
        get_CachedIsPassword                FIUIAutomationElement4_get_CachedIsPassword ?
        get_CachedNativeWindowHandle        FIUIAutomationElement4_get_CachedNativeWindowHandle ?
        get_CachedItemType                  FIUIAutomationElement4_get_CachedItemType ?
        get_CachedIsOffscreen               FIUIAutomationElement4_get_CachedIsOffscreen ?
        get_CachedOrientation               FIUIAutomationElement4_get_CachedOrientation ?
        get_CachedFrameworkId               FIUIAutomationElement4_get_CachedFrameworkId ?
        get_CachedIsRequiredForForm         FIUIAutomationElement4_get_CachedIsRequiredForForm ?
        get_CachedItemStatus                FIUIAutomationElement4_get_CachedItemStatus ?
        get_CachedBoundingRectangle         FIUIAutomationElement4_get_CachedBoundingRectangle ?
        get_CachedLabeledBy                 FIUIAutomationElement4_get_CachedLabeledBy ?
        get_CachedAriaRole                  FIUIAutomationElement4_get_CachedAriaRole ?
        get_CachedAriaProperties            FIUIAutomationElement4_get_CachedAriaProperties ?
        get_CachedIsDataValidForForm        FIUIAutomationElement4_get_CachedIsDataValidForForm ?
        get_CachedControllerFor             FIUIAutomationElement4_get_CachedControllerFor ?
        get_CachedDescribedBy               FIUIAutomationElement4_get_CachedDescribedBy ?
        get_CachedFlowsTo                   FIUIAutomationElement4_get_CachedFlowsTo ?
        get_CachedProviderDescription       FIUIAutomationElement4_get_CachedProviderDescription ?
        GetClickablePoint                   FIUIAutomationElement4_GetClickablePoint ?
        get_CurrentOptimizeForVisualContent FIUIAutomationElement4_get_CurrentOptimizeForVisualContent ?
        get_CachedOptimizeForVisualContent  FIUIAutomationElement4_get_CachedOptimizeForVisualContent ?
        get_CurrentLiveSetting              FIUIAutomationElement4_get_CurrentLiveSetting ?
        get_CachedLiveSetting               FIUIAutomationElement4_get_CachedLiveSetting ?
        get_CurrentFlowsFrom                FIUIAutomationElement4_get_CurrentFlowsFrom ?
        get_CachedFlowsFrom                 FIUIAutomationElement4_get_CachedFlowsFrom ?
        ShowContextMenu                     XPTR ?
        get_CurrentIsPeripheral             FIUIAutomationElement4_get_CurrentIsPeripheral ?
        get_CachedIsPeripheral              FIUIAutomationElement4_get_CachedIsPeripheral ?
        get_CurrentPositionInSet            FIUIAutomationElement4_get_CurrentPositionInSet ?
        get_CurrentSizeOfSet                FIUIAutomationElement4_get_CurrentSizeOfSet ?
        get_CurrentLevel                    FIUIAutomationElement4_get_CurrentLevel ?
        get_CurrentAnnotationTypes          FIUIAutomationElement4_get_CurrentAnnotationTypes ?
        get_CurrentAnnotationObjects        FIUIAutomationElement4_get_CurrentAnnotationObjects ?
        get_CachedPositionInSet             FIUIAutomationElement4_get_CachedPositionInSet ?
        get_CachedSizeOfSet                 FIUIAutomationElement4_get_CachedSizeOfSet ?
        get_CachedLevel                     FIUIAutomationElement4_get_CachedLevel ?
        get_CachedAnnotationTypes           FIUIAutomationElement4_get_CachedAnnotationTypes ?
        get_CachedAnnotationObjects         FIUIAutomationElement4_get_CachedAnnotationObjects ?
    STIUIAutomationElement4 ENDS

    IUIAutomationElement4 MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationElement4 PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationElement4>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationElement4
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationElement4_INTERFACE_DEFINED__

IFNDEF __IUIAutomationProxyFactory_INTERFACE_DEFINED__
    __IUIAutomationProxyFactory_INTERFACE_DEFINED__ EQU 1

    IUIAutomationProxyFactory_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationProxyFactory_QueryInterface TYPEDEF PTR IUIAutomationProxyFactory_QueryInterface

    IUIAutomationProxyFactory_CreateProvider TYPEDEF PROTO :XWORD, hwnd:XWORD, idObject:XWORD, idChild:XWORD, provider:XWORD
    FIUIAutomationProxyFactory_CreateProvider TYPEDEF PTR IUIAutomationProxyFactory_CreateProvider

    IUIAutomationProxyFactory_get_ProxyFactoryId TYPEDEF PROTO :XWORD, factoryId:XWORD
    FIUIAutomationProxyFactory_get_ProxyFactoryId TYPEDEF PTR IUIAutomationProxyFactory_get_ProxyFactoryId

    STIUIAutomationProxyFactory STRUCT
        QueryInterface      FIUIAutomationProxyFactory_QueryInterface ?
        AddRef              XPTR ?
        Release             XPTR ?
        CreateProvider      FIUIAutomationProxyFactory_CreateProvider ?
        get_ProxyFactoryId  FIUIAutomationProxyFactory_get_ProxyFactoryId ?
    STIUIAutomationProxyFactory ENDS

    IUIAutomationProxyFactory MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationProxyFactory PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationProxyFactory>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationProxyFactory
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationProxyFactory_INTERFACE_DEFINED__

IFNDEF __IUIAutomationProxyFactoryEntry_INTERFACE_DEFINED__
    __IUIAutomationProxyFactoryEntry_INTERFACE_DEFINED__    EQU 1

    IUIAutomationProxyFactoryEntry_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationProxyFactoryEntry_QueryInterface TYPEDEF PTR IUIAutomationProxyFactoryEntry_QueryInterface

    IUIAutomationProxyFactoryEntry_get_ProxyFactory TYPEDEF PROTO :XWORD, factory:XWORD
    FIUIAutomationProxyFactoryEntry_get_ProxyFactory TYPEDEF PTR IUIAutomationProxyFactoryEntry_get_ProxyFactory

    IUIAutomationProxyFactoryEntry_get_ClassName TYPEDEF PROTO :XWORD, className:XWORD
    FIUIAutomationProxyFactoryEntry_get_ClassName TYPEDEF PTR IUIAutomationProxyFactoryEntry_get_ClassName

    IUIAutomationProxyFactoryEntry_get_ImageName TYPEDEF PROTO :XWORD, imageName:XWORD
    FIUIAutomationProxyFactoryEntry_get_ImageName TYPEDEF PTR IUIAutomationProxyFactoryEntry_get_ImageName

    IUIAutomationProxyFactoryEntry_get_AllowSubstringMatch TYPEDEF PROTO :XWORD, allowSubstringMatch:XWORD
    FIUIAutomationProxyFactoryEntry_get_AllowSubstringMatch TYPEDEF PTR IUIAutomationProxyFactoryEntry_get_AllowSubstringMatch

    IUIAutomationProxyFactoryEntry_get_CanCheckBaseClass TYPEDEF PROTO :XWORD, canCheckBaseClass:XWORD
    FIUIAutomationProxyFactoryEntry_get_CanCheckBaseClass TYPEDEF PTR IUIAutomationProxyFactoryEntry_get_CanCheckBaseClass

    IUIAutomationProxyFactoryEntry_get_NeedsAdviseEvents TYPEDEF PROTO :XWORD, adviseEvents:XWORD
    FIUIAutomationProxyFactoryEntry_get_NeedsAdviseEvents TYPEDEF PTR IUIAutomationProxyFactoryEntry_get_NeedsAdviseEvents

    IUIAutomationProxyFactoryEntry_put_ClassName TYPEDEF PROTO :XWORD, className:XWORD
    FIUIAutomationProxyFactoryEntry_put_ClassName TYPEDEF PTR IUIAutomationProxyFactoryEntry_put_ClassName

    IUIAutomationProxyFactoryEntry_put_ImageName TYPEDEF PROTO :XWORD, imageName:XWORD
    FIUIAutomationProxyFactoryEntry_put_ImageName TYPEDEF PTR IUIAutomationProxyFactoryEntry_put_ImageName

    IUIAutomationProxyFactoryEntry_SetWinEventsForAutomationEvent TYPEDEF PROTO :XWORD, eventId:XWORD, propertyId:XWORD, winEvents:XWORD
    FIUIAutomationProxyFactoryEntry_SetWinEventsForAutomationEvent TYPEDEF PTR IUIAutomationProxyFactoryEntry_SetWinEventsForAutomationEvent

    IUIAutomationProxyFactoryEntry_GetWinEventsForAutomationEvent TYPEDEF PROTO :XWORD, eventId:XWORD, propertyId:XWORD, winEvents:XWORD
    FIUIAutomationProxyFactoryEntry_GetWinEventsForAutomationEvent TYPEDEF PTR IUIAutomationProxyFactoryEntry_GetWinEventsForAutomationEvent

    STIUIAutomationProxyFactoryEntry STRUCT
        QueryInterface                  FIUIAutomationProxyFactoryEntry_QueryInterface ?
        AddRef                          XPTR ?
        Release                         XPTR ?
        get_ProxyFactory                FIUIAutomationProxyFactoryEntry_get_ProxyFactory ?
        get_ClassName                   FIUIAutomationProxyFactoryEntry_get_ClassName ?
        get_ImageName                   FIUIAutomationProxyFactoryEntry_get_ImageName ?
        get_AllowSubstringMatch         FIUIAutomationProxyFactoryEntry_get_AllowSubstringMatch ?
        get_CanCheckBaseClass           FIUIAutomationProxyFactoryEntry_get_CanCheckBaseClass ?
        get_NeedsAdviseEvents           FIUIAutomationProxyFactoryEntry_get_NeedsAdviseEvents ?
        put_ClassName                   FIUIAutomationProxyFactoryEntry_put_ClassName ?
        put_ImageName                   FIUIAutomationProxyFactoryEntry_put_ImageName ?
        put_AllowSubstringMatch         XPTR ?
        put_CanCheckBaseClass           XPTR ?
        put_NeedsAdviseEvents           XPTR ?
        SetWinEventsForAutomationEvent  FIUIAutomationProxyFactoryEntry_SetWinEventsForAutomationEvent ?
        GetWinEventsForAutomationEvent  FIUIAutomationProxyFactoryEntry_GetWinEventsForAutomationEvent ?
    STIUIAutomationProxyFactoryEntry ENDS

    IUIAutomationProxyFactoryEntry MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationProxyFactoryEntry PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationProxyFactoryEntry>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationProxyFactoryEntry
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationProxyFactoryEntry_INTERFACE_DEFINED__

IFNDEF __IUIAutomationProxyFactoryMapping_INTERFACE_DEFINED__
    __IUIAutomationProxyFactoryMapping_INTERFACE_DEFINED__  EQU 1

    IUIAutomationProxyFactoryMapping_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomationProxyFactoryMapping_QueryInterface TYPEDEF PTR IUIAutomationProxyFactoryMapping_QueryInterface

    IUIAutomationProxyFactoryMapping_get_Count TYPEDEF PROTO :XWORD, count:XWORD
    FIUIAutomationProxyFactoryMapping_get_Count TYPEDEF PTR IUIAutomationProxyFactoryMapping_get_Count

    IUIAutomationProxyFactoryMapping_GetTable TYPEDEF PROTO :XWORD, table:XWORD
    FIUIAutomationProxyFactoryMapping_GetTable TYPEDEF PTR IUIAutomationProxyFactoryMapping_GetTable

    IUIAutomationProxyFactoryMapping_GetEntry TYPEDEF PROTO :XWORD, index:XWORD, entry:XWORD
    FIUIAutomationProxyFactoryMapping_GetEntry TYPEDEF PTR IUIAutomationProxyFactoryMapping_GetEntry

    IUIAutomationProxyFactoryMapping_SetTable TYPEDEF PROTO :XWORD, factoryList:XWORD
    FIUIAutomationProxyFactoryMapping_SetTable TYPEDEF PTR IUIAutomationProxyFactoryMapping_SetTable

    IUIAutomationProxyFactoryMapping_InsertEntries TYPEDEF PROTO :XWORD, before:XWORD, factoryList:XWORD
    FIUIAutomationProxyFactoryMapping_InsertEntries TYPEDEF PTR IUIAutomationProxyFactoryMapping_InsertEntries

    IUIAutomationProxyFactoryMapping_InsertEntry TYPEDEF PROTO :XWORD, before:XWORD, factory:XWORD
    FIUIAutomationProxyFactoryMapping_InsertEntry TYPEDEF PTR IUIAutomationProxyFactoryMapping_InsertEntry

    STIUIAutomationProxyFactoryMapping STRUCT
        QueryInterface      FIUIAutomationProxyFactoryMapping_QueryInterface ?
        AddRef              XPTR ?
        Release             XPTR ?
        get_Count           FIUIAutomationProxyFactoryMapping_get_Count ?
        GetTable            FIUIAutomationProxyFactoryMapping_GetTable ?
        GetEntry            FIUIAutomationProxyFactoryMapping_GetEntry ?
        SetTable            FIUIAutomationProxyFactoryMapping_SetTable ?
        InsertEntries       FIUIAutomationProxyFactoryMapping_InsertEntries ?
        InsertEntry         FIUIAutomationProxyFactoryMapping_InsertEntry ?
        RemoveEntry         XPTR ?
        ClearTable          XPTR ?
        RestoreDefaultTable XPTR ?
    STIUIAutomationProxyFactoryMapping ENDS

    IUIAutomationProxyFactoryMapping MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomationProxyFactoryMapping PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomationProxyFactoryMapping>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomationProxyFactoryMapping
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomationProxyFactoryMapping_INTERFACE_DEFINED__

IFNDEF __IUIAutomation_INTERFACE_DEFINED__
    __IUIAutomation_INTERFACE_DEFINED__ EQU 1

    IUIAutomation_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomation_QueryInterface TYPEDEF PTR IUIAutomation_QueryInterface

    IUIAutomation_CompareElements TYPEDEF PROTO :XWORD, el1:XWORD, el2:XWORD, areSame:XWORD
    FIUIAutomation_CompareElements TYPEDEF PTR IUIAutomation_CompareElements

    IUIAutomation_CompareRuntimeIds TYPEDEF PROTO :XWORD, runtimeId1:XWORD, runtimeId2:XWORD, areSame:XWORD
    FIUIAutomation_CompareRuntimeIds TYPEDEF PTR IUIAutomation_CompareRuntimeIds

    IUIAutomation_GetRootElement TYPEDEF PROTO :XWORD, root:XWORD
    FIUIAutomation_GetRootElement TYPEDEF PTR IUIAutomation_GetRootElement

    IUIAutomation_ElementFromHandle TYPEDEF PROTO :XWORD, hwnd:XWORD, element:XWORD
    FIUIAutomation_ElementFromHandle TYPEDEF PTR IUIAutomation_ElementFromHandle

    IUIAutomation_ElementFromPoint TYPEDEF PROTO :XWORD, pt:POINT, element:XWORD
    FIUIAutomation_ElementFromPoint TYPEDEF PTR IUIAutomation_ElementFromPoint

    IUIAutomation_GetFocusedElement TYPEDEF PROTO :XWORD, element:XWORD
    FIUIAutomation_GetFocusedElement TYPEDEF PTR IUIAutomation_GetFocusedElement

    IUIAutomation_GetRootElementBuildCache TYPEDEF PROTO :XWORD, cacheRequest:XWORD, root:XWORD
    FIUIAutomation_GetRootElementBuildCache TYPEDEF PTR IUIAutomation_GetRootElementBuildCache

    IUIAutomation_ElementFromHandleBuildCache TYPEDEF PROTO :XWORD, hwnd:XWORD, cacheRequest:XWORD, element:XWORD
    FIUIAutomation_ElementFromHandleBuildCache TYPEDEF PTR IUIAutomation_ElementFromHandleBuildCache

    IUIAutomation_ElementFromPointBuildCache TYPEDEF PROTO :XWORD, pt:POINT, cacheRequest:XWORD, element:XWORD
    FIUIAutomation_ElementFromPointBuildCache TYPEDEF PTR IUIAutomation_ElementFromPointBuildCache

    IUIAutomation_GetFocusedElementBuildCache TYPEDEF PROTO :XWORD, cacheRequest:XWORD, element:XWORD
    FIUIAutomation_GetFocusedElementBuildCache TYPEDEF PTR IUIAutomation_GetFocusedElementBuildCache

    IUIAutomation_CreateTreeWalker TYPEDEF PROTO :XWORD, pCondition:XWORD, walker:XWORD
    FIUIAutomation_CreateTreeWalker TYPEDEF PTR IUIAutomation_CreateTreeWalker

    IUIAutomation_get_ControlViewWalker TYPEDEF PROTO :XWORD, walker:XWORD
    FIUIAutomation_get_ControlViewWalker TYPEDEF PTR IUIAutomation_get_ControlViewWalker

    IUIAutomation_get_ContentViewWalker TYPEDEF PROTO :XWORD, walker:XWORD
    FIUIAutomation_get_ContentViewWalker TYPEDEF PTR IUIAutomation_get_ContentViewWalker

    IUIAutomation_get_RawViewWalker TYPEDEF PROTO :XWORD, walker:XWORD
    FIUIAutomation_get_RawViewWalker TYPEDEF PTR IUIAutomation_get_RawViewWalker

    IUIAutomation_get_RawViewCondition TYPEDEF PROTO :XWORD, condition:XWORD
    FIUIAutomation_get_RawViewCondition TYPEDEF PTR IUIAutomation_get_RawViewCondition

    IUIAutomation_get_ControlViewCondition TYPEDEF PROTO :XWORD, condition:XWORD
    FIUIAutomation_get_ControlViewCondition TYPEDEF PTR IUIAutomation_get_ControlViewCondition

    IUIAutomation_get_ContentViewCondition TYPEDEF PROTO :XWORD, condition:XWORD
    FIUIAutomation_get_ContentViewCondition TYPEDEF PTR IUIAutomation_get_ContentViewCondition

    IUIAutomation_CreateCacheRequest TYPEDEF PROTO :XWORD, cacheRequest:XWORD
    FIUIAutomation_CreateCacheRequest TYPEDEF PTR IUIAutomation_CreateCacheRequest

    IUIAutomation_CreateTrueCondition TYPEDEF PROTO :XWORD, newCondition:XWORD
    FIUIAutomation_CreateTrueCondition TYPEDEF PTR IUIAutomation_CreateTrueCondition

    IUIAutomation_CreateFalseCondition TYPEDEF PROTO :XWORD, newCondition:XWORD
    FIUIAutomation_CreateFalseCondition TYPEDEF PTR IUIAutomation_CreateFalseCondition

    IUIAutomation_CreatePropertyCondition TYPEDEF PROTO :XWORD, propertyId:XWORD, value:VARIANT, newCondition:XWORD
    FIUIAutomation_CreatePropertyCondition TYPEDEF PTR IUIAutomation_CreatePropertyCondition

    IUIAutomation_CreatePropertyConditionEx TYPEDEF PROTO :XWORD, propertyId:XWORD, value:VARIANT, flags:XWORD, newCondition:XWORD
    FIUIAutomation_CreatePropertyConditionEx TYPEDEF PTR IUIAutomation_CreatePropertyConditionEx

    IUIAutomation_CreateAndCondition TYPEDEF PROTO :XWORD, condition1:XWORD, condition2:XWORD, newCondition:XWORD
    FIUIAutomation_CreateAndCondition TYPEDEF PTR IUIAutomation_CreateAndCondition

    IUIAutomation_CreateAndConditionFromArray TYPEDEF PROTO :XWORD, conditions:XWORD, newCondition:XWORD
    FIUIAutomation_CreateAndConditionFromArray TYPEDEF PTR IUIAutomation_CreateAndConditionFromArray

    IUIAutomation_CreateAndConditionFromNativeArray TYPEDEF PROTO :XWORD, conditions:XWORD, conditionCount:XWORD, newCondition:XWORD
    FIUIAutomation_CreateAndConditionFromNativeArray TYPEDEF PTR IUIAutomation_CreateAndConditionFromNativeArray

    IUIAutomation_CreateOrCondition TYPEDEF PROTO :XWORD, condition1:XWORD, condition2:XWORD, newCondition:XWORD
    FIUIAutomation_CreateOrCondition TYPEDEF PTR IUIAutomation_CreateOrCondition

    IUIAutomation_CreateOrConditionFromArray TYPEDEF PROTO :XWORD, conditions:XWORD, newCondition:XWORD
    FIUIAutomation_CreateOrConditionFromArray TYPEDEF PTR IUIAutomation_CreateOrConditionFromArray

    IUIAutomation_CreateOrConditionFromNativeArray TYPEDEF PROTO :XWORD, conditions:XWORD, conditionCount:XWORD, newCondition:XWORD
    FIUIAutomation_CreateOrConditionFromNativeArray TYPEDEF PTR IUIAutomation_CreateOrConditionFromNativeArray

    IUIAutomation_CreateNotCondition TYPEDEF PROTO :XWORD, condition:XWORD, newCondition:XWORD
    FIUIAutomation_CreateNotCondition TYPEDEF PTR IUIAutomation_CreateNotCondition

    IUIAutomation_AddAutomationEventHandler TYPEDEF PROTO :XWORD, eventId:XWORD, element:XWORD, scope:XWORD, cacheRequest:XWORD, handler:XWORD
    FIUIAutomation_AddAutomationEventHandler TYPEDEF PTR IUIAutomation_AddAutomationEventHandler

    IUIAutomation_RemoveAutomationEventHandler TYPEDEF PROTO :XWORD, eventId:XWORD, element:XWORD, handler:XWORD
    FIUIAutomation_RemoveAutomationEventHandler TYPEDEF PTR IUIAutomation_RemoveAutomationEventHandler

    IUIAutomation_AddPropertyChangedEventHandlerNativeArray TYPEDEF PROTO :XWORD, element:XWORD, scope:XWORD, cacheRequest:XWORD, handler:XWORD, propertyArray:XWORD, propertyCount:XWORD 
    FIUIAutomation_AddPropertyChangedEventHandlerNativeArray TYPEDEF PTR IUIAutomation_AddPropertyChangedEventHandlerNativeArray

    IUIAutomation_AddPropertyChangedEventHandler TYPEDEF PROTO :XWORD, element:XWORD, scope:XWORD, cacheRequest:XWORD, handler:XWORD, propertyArray:XWORD
    FIUIAutomation_AddPropertyChangedEventHandler TYPEDEF PTR IUIAutomation_AddPropertyChangedEventHandler

    IUIAutomation_RemovePropertyChangedEventHandler TYPEDEF PROTO :XWORD, element:XWORD, handler:XWORD
    FIUIAutomation_RemovePropertyChangedEventHandler TYPEDEF PTR IUIAutomation_RemovePropertyChangedEventHandler

    IUIAutomation_AddStructureChangedEventHandler TYPEDEF PROTO :XWORD, element:XWORD, scope:XWORD, cacheRequest:XWORD, handler:XWORD
    FIUIAutomation_AddStructureChangedEventHandler TYPEDEF PTR IUIAutomation_AddStructureChangedEventHandler

    IUIAutomation_RemoveStructureChangedEventHandler TYPEDEF PROTO :XWORD, element:XWORD, handler:XWORD
    FIUIAutomation_RemoveStructureChangedEventHandler TYPEDEF PTR IUIAutomation_RemoveStructureChangedEventHandler

    IUIAutomation_AddFocusChangedEventHandler TYPEDEF PROTO :XWORD, cacheRequest:XWORD, handler:XWORD
    FIUIAutomation_AddFocusChangedEventHandler TYPEDEF PTR IUIAutomation_AddFocusChangedEventHandler

    IUIAutomation_RemoveFocusChangedEventHandler TYPEDEF PROTO :XWORD, handler:XWORD
    FIUIAutomation_RemoveFocusChangedEventHandler TYPEDEF PTR IUIAutomation_RemoveFocusChangedEventHandler

    IUIAutomation_IntNativeArrayToSafeArray TYPEDEF PROTO :XWORD, array:XWORD, arrayCount:XWORD, safeArray:XWORD
    FIUIAutomation_IntNativeArrayToSafeArray TYPEDEF PTR IUIAutomation_IntNativeArrayToSafeArray

    IUIAutomation_IntSafeArrayToNativeArray TYPEDEF PROTO :XWORD, intArray:XWORD, array:XWORD, arrayCount:XWORD
    FIUIAutomation_IntSafeArrayToNativeArray TYPEDEF PTR IUIAutomation_IntSafeArrayToNativeArray

    IUIAutomation_RectToVariant TYPEDEF PROTO :XWORD, rc:RECT, var:XWORD
    FIUIAutomation_RectToVariant TYPEDEF PTR IUIAutomation_RectToVariant

    IUIAutomation_VariantToRect TYPEDEF PROTO :XWORD, var:VARIANT, rc:XWORD
    FIUIAutomation_VariantToRect TYPEDEF PTR IUIAutomation_VariantToRect

    IUIAutomation_SafeArrayToRectNativeArray TYPEDEF PROTO :XWORD, rects:XWORD, rectArray:XWORD, rectArrayCount:XWORD
    FIUIAutomation_SafeArrayToRectNativeArray TYPEDEF PTR IUIAutomation_SafeArrayToRectNativeArray

    IUIAutomation_CreateProxyFactoryEntry TYPEDEF PROTO :XWORD, factory:XWORD, factoryEntry:XWORD
    FIUIAutomation_CreateProxyFactoryEntry TYPEDEF PTR IUIAutomation_CreateProxyFactoryEntry

    IUIAutomation_get_ProxyFactoryMapping TYPEDEF PROTO :XWORD, factoryMapping:XWORD
    FIUIAutomation_get_ProxyFactoryMapping TYPEDEF PTR IUIAutomation_get_ProxyFactoryMapping

    IUIAutomation_GetPropertyProgrammaticName TYPEDEF PROTO :XWORD, property:XWORD, aname:XWORD
    FIUIAutomation_GetPropertyProgrammaticName TYPEDEF PTR IUIAutomation_GetPropertyProgrammaticName

    IUIAutomation_GetPatternProgrammaticName TYPEDEF PROTO :XWORD, pattern:XWORD, aname:XWORD
    FIUIAutomation_GetPatternProgrammaticName TYPEDEF PTR IUIAutomation_GetPatternProgrammaticName

    IUIAutomation_PollForPotentialSupportedPatterns TYPEDEF PROTO :XWORD, pElement:XWORD, patternIds:XWORD, patternNames:XWORD
    FIUIAutomation_PollForPotentialSupportedPatterns TYPEDEF PTR IUIAutomation_PollForPotentialSupportedPatterns

    IUIAutomation_PollForPotentialSupportedProperties TYPEDEF PROTO :XWORD, pElement:XWORD, propertyIds:XWORD, propertyNames:XWORD
    FIUIAutomation_PollForPotentialSupportedProperties TYPEDEF PTR IUIAutomation_PollForPotentialSupportedProperties

    IUIAutomation_CheckNotSupported TYPEDEF PROTO :XWORD, value:VARIANT, isNotSupported:XWORD
    FIUIAutomation_CheckNotSupported TYPEDEF PTR IUIAutomation_CheckNotSupported

    IUIAutomation_get_ReservedNotSupportedValue TYPEDEF PROTO :XWORD, notSupportedValue:XWORD
    FIUIAutomation_get_ReservedNotSupportedValue TYPEDEF PTR IUIAutomation_get_ReservedNotSupportedValue

    IUIAutomation_get_ReservedMixedAttributeValue TYPEDEF PROTO :XWORD, mixedAttributeValue:XWORD
    FIUIAutomation_get_ReservedMixedAttributeValue TYPEDEF PTR IUIAutomation_get_ReservedMixedAttributeValue

    IUIAutomation_ElementFromIAccessible TYPEDEF PROTO :XWORD, accessible:XWORD, childId:XWORD, element:XWORD
    FIUIAutomation_ElementFromIAccessible TYPEDEF PTR IUIAutomation_ElementFromIAccessible

    IUIAutomation_ElementFromIAccessibleBuildCache TYPEDEF PROTO :XWORD, accessible:XWORD, childId:XWORD, cacheRequest:XWORD, element:XWORD
    FIUIAutomation_ElementFromIAccessibleBuildCache TYPEDEF PTR IUIAutomation_ElementFromIAccessibleBuildCache

    STIUIAutomation STRUCT
        QueryInterface      FIUIAutomation_QueryInterface ?
        AddRef                                      XPTR ?
        Release                                     XPTR ?
        CompareElements                             FIUIAutomation_CompareElements ?
        CompareRuntimeIds                           FIUIAutomation_CompareRuntimeIds ?
        GetRootElement                              FIUIAutomation_GetRootElement ?
        ElementFromHandle                           FIUIAutomation_ElementFromHandle ?
        ElementFromPoint                            FIUIAutomation_ElementFromPoint ?
        GetFocusedElement                           FIUIAutomation_GetFocusedElement ?
        GetRootElementBuildCache                    FIUIAutomation_GetRootElementBuildCache ?
        ElementFromHandleBuildCache                 FIUIAutomation_ElementFromHandleBuildCache ?
        ElementFromPointBuildCache                  FIUIAutomation_ElementFromPointBuildCache ?
        GetFocusedElementBuildCache                 FIUIAutomation_GetFocusedElementBuildCache ?
        CreateTreeWalker                            FIUIAutomation_CreateTreeWalker ?
        get_ControlViewWalker                       FIUIAutomation_get_ControlViewWalker ?
        get_ContentViewWalker                       FIUIAutomation_get_ContentViewWalker ?
        get_RawViewWalker                           FIUIAutomation_get_RawViewWalker ?
        get_RawViewCondition                        FIUIAutomation_get_RawViewCondition ?
        get_ControlViewCondition                    FIUIAutomation_get_ControlViewCondition ?
        get_ContentViewCondition                    FIUIAutomation_get_ContentViewCondition ?
        CreateCacheRequest                          FIUIAutomation_CreateCacheRequest ?
        CreateTrueCondition                         FIUIAutomation_CreateTrueCondition ?
        CreateFalseCondition                        FIUIAutomation_CreateFalseCondition ?
        CreatePropertyCondition                     FIUIAutomation_CreatePropertyCondition ?
        CreatePropertyConditionEx                   FIUIAutomation_CreatePropertyConditionEx ?
        CreateAndCondition                          FIUIAutomation_CreateAndCondition ?
        CreateAndConditionFromArray                 FIUIAutomation_CreateAndConditionFromArray ?
        CreateAndConditionFromNativeArray           FIUIAutomation_CreateAndConditionFromNativeArray ?
        CreateOrCondition                           FIUIAutomation_CreateOrCondition ?
        CreateOrConditionFromArray                  FIUIAutomation_CreateOrConditionFromArray ?
        CreateOrConditionFromNativeArray            FIUIAutomation_CreateOrConditionFromNativeArray ?
        CreateNotCondition                          FIUIAutomation_CreateNotCondition ?
        AddAutomationEventHandler                   FIUIAutomation_AddAutomationEventHandler ?
        RemoveAutomationEventHandler                FIUIAutomation_RemoveAutomationEventHandler ?
        AddPropertyChangedEventHandlerNativeArray   FIUIAutomation_AddPropertyChangedEventHandlerNativeArray ?
        AddPropertyChangedEventHandler              FIUIAutomation_AddPropertyChangedEventHandler ?
        RemovePropertyChangedEventHandler           FIUIAutomation_RemovePropertyChangedEventHandler ?
        AddStructureChangedEventHandler             FIUIAutomation_AddStructureChangedEventHandler ?
        RemoveStructureChangedEventHandler          FIUIAutomation_RemoveStructureChangedEventHandler ?
        AddFocusChangedEventHandler                 FIUIAutomation_AddFocusChangedEventHandler ?
        RemoveFocusChangedEventHandler              FIUIAutomation_RemoveFocusChangedEventHandler ?
        RemoveAllEventHandlers                      XPTR ?
        IntNativeArrayToSafeArray                   FIUIAutomation_IntNativeArrayToSafeArray ?
        IntSafeArrayToNativeArray                   FIUIAutomation_IntSafeArrayToNativeArray ?
        RectToVariant                               FIUIAutomation_RectToVariant ?
        VariantToRect                               FIUIAutomation_VariantToRect ?
        SafeArrayToRectNativeArray                  FIUIAutomation_SafeArrayToRectNativeArray ?
        CreateProxyFactoryEntry                     FIUIAutomation_CreateProxyFactoryEntry ?
        get_ProxyFactoryMapping                     FIUIAutomation_get_ProxyFactoryMapping ?
        GetPropertyProgrammaticName                 FIUIAutomation_GetPropertyProgrammaticName ?
        GetPatternProgrammaticName                  FIUIAutomation_GetPatternProgrammaticName ?
        PollForPotentialSupportedPatterns           FIUIAutomation_PollForPotentialSupportedPatterns ?
        PollForPotentialSupportedProperties         FIUIAutomation_PollForPotentialSupportedProperties ?
        CheckNotSupported                           FIUIAutomation_CheckNotSupported ?
        get_ReservedNotSupportedValue               FIUIAutomation_get_ReservedNotSupportedValue ?
        get_ReservedMixedAttributeValue             FIUIAutomation_get_ReservedMixedAttributeValue ?
        ElementFromIAccessible                      FIUIAutomation_ElementFromIAccessible ?
        ElementFromIAccessibleBuildCache            FIUIAutomation_ElementFromIAccessibleBuildCache ?
    STIUIAutomation ENDS

    IUIAutomation MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomation PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomation>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomation
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomation_INTERFACE_DEFINED__

IFNDEF __IUIAutomation2_INTERFACE_DEFINED__
    __IUIAutomation2_INTERFACE_DEFINED__    EQU 1

    IUIAutomation2_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomation2_QueryInterface TYPEDEF PTR IUIAutomation2_QueryInterface

    IUIAutomation2_CompareElements TYPEDEF PROTO :XWORD, el1:XWORD, el2:XWORD, areSame:XWORD
    FIUIAutomation2_CompareElements TYPEDEF PTR IUIAutomation2_CompareElements

    IUIAutomation2_CompareRuntimeIds TYPEDEF PROTO :XWORD, runtimeId1:XWORD, runtimeId2:XWORD, areSame:XWORD
    FIUIAutomation2_CompareRuntimeIds TYPEDEF PTR IUIAutomation2_CompareRuntimeIds

    IUIAutomation2_GetRootElement TYPEDEF PROTO :XWORD, root:XWORD
    FIUIAutomation2_GetRootElement TYPEDEF PTR IUIAutomation2_GetRootElement

    IUIAutomation2_ElementFromHandle TYPEDEF PROTO :XWORD, hwnd:XWORD, element:XWORD
    FIUIAutomation2_ElementFromHandle TYPEDEF PTR IUIAutomation2_ElementFromHandle

    IUIAutomation2_ElementFromPoint TYPEDEF PROTO :XWORD, pt:POINT, element:XWORD
    FIUIAutomation2_ElementFromPoint TYPEDEF PTR IUIAutomation2_ElementFromPoint

    IUIAutomation2_GetFocusedElement TYPEDEF PROTO :XWORD, element:XWORD
    FIUIAutomation2_GetFocusedElement TYPEDEF PTR IUIAutomation2_GetFocusedElement

    IUIAutomation2_GetRootElementBuildCache TYPEDEF PROTO :XWORD, cacheRequest:XWORD, root:XWORD
    FIUIAutomation2_GetRootElementBuildCache TYPEDEF PTR IUIAutomation2_GetRootElementBuildCache

    IUIAutomation2_ElementFromHandleBuildCache TYPEDEF PROTO :XWORD, hwnd:XWORD, cacheRequest:XWORD, element:XWORD
    FIUIAutomation2_ElementFromHandleBuildCache TYPEDEF PTR IUIAutomation2_ElementFromHandleBuildCache

    IUIAutomation2_ElementFromPointBuildCache TYPEDEF PROTO :XWORD, pt:POINT, cacheRequest:XWORD, element:XWORD
    FIUIAutomation2_ElementFromPointBuildCache TYPEDEF PTR IUIAutomation2_ElementFromPointBuildCache

    IUIAutomation2_GetFocusedElementBuildCache TYPEDEF PROTO :XWORD, cacheRequest:XWORD, element:XWORD
    FIUIAutomation2_GetFocusedElementBuildCache TYPEDEF PTR IUIAutomation2_GetFocusedElementBuildCache

    IUIAutomation2_CreateTreeWalker TYPEDEF PROTO :XWORD, pCondition:XWORD, walker:XWORD
    FIUIAutomation2_CreateTreeWalker TYPEDEF PTR IUIAutomation2_CreateTreeWalker

    IUIAutomation2_get_ControlViewWalker TYPEDEF PROTO :XWORD, walker:XWORD
    FIUIAutomation2_get_ControlViewWalker TYPEDEF PTR IUIAutomation2_get_ControlViewWalker

    IUIAutomation2_get_ContentViewWalker TYPEDEF PROTO :XWORD, walker:XWORD
    FIUIAutomation2_get_ContentViewWalker TYPEDEF PTR IUIAutomation2_get_ContentViewWalker

    IUIAutomation2_get_RawViewWalker TYPEDEF PROTO :XWORD, walker:XWORD
    FIUIAutomation2_get_RawViewWalker TYPEDEF PTR IUIAutomation2_get_RawViewWalker

    IUIAutomation2_get_RawViewCondition TYPEDEF PROTO :XWORD, condition:XWORD
    FIUIAutomation2_get_RawViewCondition TYPEDEF PTR IUIAutomation2_get_RawViewCondition

    IUIAutomation2_get_ControlViewCondition TYPEDEF PROTO :XWORD, condition:XWORD
    FIUIAutomation2_get_ControlViewCondition TYPEDEF PTR IUIAutomation2_get_ControlViewCondition

    IUIAutomation2_get_ContentViewCondition TYPEDEF PROTO :XWORD, condition:XWORD
    FIUIAutomation2_get_ContentViewCondition TYPEDEF PTR IUIAutomation2_get_ContentViewCondition

    IUIAutomation2_CreateCacheRequest TYPEDEF PROTO :XWORD, cacheRequest:XWORD
    FIUIAutomation2_CreateCacheRequest TYPEDEF PTR IUIAutomation2_CreateCacheRequest

    IUIAutomation2_CreateTrueCondition TYPEDEF PROTO :XWORD, newCondition:XWORD
    FIUIAutomation2_CreateTrueCondition TYPEDEF PTR IUIAutomation2_CreateTrueCondition

    IUIAutomation2_CreateFalseCondition TYPEDEF PROTO :XWORD, newCondition:XWORD
    FIUIAutomation2_CreateFalseCondition TYPEDEF PTR IUIAutomation2_CreateFalseCondition

    IUIAutomation2_CreatePropertyCondition TYPEDEF PROTO :XWORD, propertyId:XWORD, value:VARIANT, newCondition:XWORD
    FIUIAutomation2_CreatePropertyCondition TYPEDEF PTR IUIAutomation2_CreatePropertyCondition

    IUIAutomation2_CreatePropertyConditionEx TYPEDEF PROTO :XWORD, propertyId:XWORD, value:VARIANT, flags:XWORD, newCondition:XWORD
    FIUIAutomation2_CreatePropertyConditionEx TYPEDEF PTR IUIAutomation2_CreatePropertyConditionEx

    IUIAutomation2_CreateAndCondition TYPEDEF PROTO :XWORD, condition1:XWORD, condition2:XWORD, newCondition:XWORD
    FIUIAutomation2_CreateAndCondition TYPEDEF PTR IUIAutomation2_CreateAndCondition

    IUIAutomation2_CreateAndConditionFromArray TYPEDEF PROTO :XWORD, conditions:XWORD, newCondition:XWORD
    FIUIAutomation2_CreateAndConditionFromArray TYPEDEF PTR IUIAutomation2_CreateAndConditionFromArray

    IUIAutomation2_CreateAndConditionFromNativeArray TYPEDEF PROTO :XWORD, conditions:XWORD, conditionCount:XWORD, newCondition:XWORD
    FIUIAutomation2_CreateAndConditionFromNativeArray TYPEDEF PTR IUIAutomation2_CreateAndConditionFromNativeArray

    IUIAutomation2_CreateOrCondition TYPEDEF PROTO :XWORD, condition1:XWORD, condition2:XWORD, newCondition:XWORD
    FIUIAutomation2_CreateOrCondition TYPEDEF PTR IUIAutomation2_CreateOrCondition

    IUIAutomation2_CreateOrConditionFromArray TYPEDEF PROTO :XWORD, conditions:XWORD, newCondition:XWORD
    FIUIAutomation2_CreateOrConditionFromArray TYPEDEF PTR IUIAutomation2_CreateOrConditionFromArray

    IUIAutomation2_CreateOrConditionFromNativeArray TYPEDEF PROTO :XWORD, conditions:XWORD, conditionCount:XWORD, newCondition:XWORD
    FIUIAutomation2_CreateOrConditionFromNativeArray TYPEDEF PTR IUIAutomation2_CreateOrConditionFromNativeArray

    IUIAutomation2_CreateNotCondition TYPEDEF PROTO :XWORD, condition:XWORD, newCondition:XWORD
    FIUIAutomation2_CreateNotCondition TYPEDEF PTR IUIAutomation2_CreateNotCondition

    IUIAutomation2_AddAutomationEventHandler TYPEDEF PROTO :XWORD, eventId:XWORD, element:XWORD, scope:XWORD, cacheRequest:XWORD, handler:XWORD
    FIUIAutomation2_AddAutomationEventHandler TYPEDEF PTR IUIAutomation2_AddAutomationEventHandler

    IUIAutomation2_RemoveAutomationEventHandler TYPEDEF PROTO :XWORD, eventId:XWORD, element:XWORD, handler:XWORD
    FIUIAutomation2_RemoveAutomationEventHandler TYPEDEF PTR IUIAutomation2_RemoveAutomationEventHandler

    IUIAutomation2_AddPropertyChangedEventHandlerNativeArray TYPEDEF PROTO :XWORD, element:XWORD, scope:XWORD, cacheRequest:XWORD, handler:XWORD, propertyArray:XWORD, propertyCount:XWORD 
    FIUIAutomation2_AddPropertyChangedEventHandlerNativeArray TYPEDEF PTR IUIAutomation2_AddPropertyChangedEventHandlerNativeArray

    IUIAutomation2_AddPropertyChangedEventHandler TYPEDEF PROTO :XWORD, element:XWORD, scope:XWORD, cacheRequest:XWORD, handler:XWORD, propertyArray:XWORD
    FIUIAutomation2_AddPropertyChangedEventHandler TYPEDEF PTR IUIAutomation2_AddPropertyChangedEventHandler

    IUIAutomation2_RemovePropertyChangedEventHandler TYPEDEF PROTO :XWORD, element:XWORD, handler:XWORD
    FIUIAutomation2_RemovePropertyChangedEventHandler TYPEDEF PTR IUIAutomation2_RemovePropertyChangedEventHandler

    IUIAutomation2_AddStructureChangedEventHandler TYPEDEF PROTO :XWORD, element:XWORD, scope:XWORD, cacheRequest:XWORD, handler:XWORD
    FIUIAutomation2_AddStructureChangedEventHandler TYPEDEF PTR IUIAutomation2_AddStructureChangedEventHandler

    IUIAutomation2_RemoveStructureChangedEventHandler TYPEDEF PROTO :XWORD, element:XWORD, handler:XWORD
    FIUIAutomation2_RemoveStructureChangedEventHandler TYPEDEF PTR IUIAutomation2_RemoveStructureChangedEventHandler

    IUIAutomation2_AddFocusChangedEventHandler TYPEDEF PROTO :XWORD, cacheRequest:XWORD, handler:XWORD
    FIUIAutomation2_AddFocusChangedEventHandler TYPEDEF PTR IUIAutomation2_AddFocusChangedEventHandler

    IUIAutomation2_RemoveFocusChangedEventHandler TYPEDEF PROTO :XWORD, handler:XWORD
    FIUIAutomation2_RemoveFocusChangedEventHandler TYPEDEF PTR IUIAutomation2_RemoveFocusChangedEventHandler

    IUIAutomation2_IntNativeArrayToSafeArray TYPEDEF PROTO :XWORD, array:XWORD, arrayCount:XWORD, safeArray:XWORD
    FIUIAutomation2_IntNativeArrayToSafeArray TYPEDEF PTR IUIAutomation2_IntNativeArrayToSafeArray

    IUIAutomation2_IntSafeArrayToNativeArray TYPEDEF PROTO :XWORD, intArray:XWORD, array:XWORD, arrayCount:XWORD
    FIUIAutomation2_IntSafeArrayToNativeArray TYPEDEF PTR IUIAutomation2_IntSafeArrayToNativeArray

    IUIAutomation2_RectToVariant TYPEDEF PROTO :XWORD, rc:RECT, var:XWORD
    FIUIAutomation2_RectToVariant TYPEDEF PTR IUIAutomation2_RectToVariant

    IUIAutomation2_VariantToRect TYPEDEF PROTO :XWORD, var:VARIANT, rc:XWORD
    FIUIAutomation2_VariantToRect TYPEDEF PTR IUIAutomation2_VariantToRect

    IUIAutomation2_SafeArrayToRectNativeArray TYPEDEF PROTO :XWORD, rects:XWORD, rectArray:XWORD, rectArrayCount:XWORD
    FIUIAutomation2_SafeArrayToRectNativeArray TYPEDEF PTR IUIAutomation2_SafeArrayToRectNativeArray

    IUIAutomation2_CreateProxyFactoryEntry TYPEDEF PROTO :XWORD, factory:XWORD, factoryEntry:XWORD
    FIUIAutomation2_CreateProxyFactoryEntry TYPEDEF PTR IUIAutomation2_CreateProxyFactoryEntry

    IUIAutomation2_get_ProxyFactoryMapping TYPEDEF PROTO :XWORD, factoryMapping:XWORD
    FIUIAutomation2_get_ProxyFactoryMapping TYPEDEF PTR IUIAutomation2_get_ProxyFactoryMapping

    IUIAutomation2_GetPropertyProgrammaticName TYPEDEF PROTO :XWORD, property:XWORD, aname:XWORD
    FIUIAutomation2_GetPropertyProgrammaticName TYPEDEF PTR IUIAutomation2_GetPropertyProgrammaticName

    IUIAutomation2_GetPatternProgrammaticName TYPEDEF PROTO :XWORD, pattern:XWORD, aname:XWORD
    FIUIAutomation2_GetPatternProgrammaticName TYPEDEF PTR IUIAutomation2_GetPatternProgrammaticName

    IUIAutomation2_PollForPotentialSupportedPatterns TYPEDEF PROTO :XWORD, pElement:XWORD, patternIds:XWORD, patternNames:XWORD
    FIUIAutomation2_PollForPotentialSupportedPatterns TYPEDEF PTR IUIAutomation2_PollForPotentialSupportedPatterns

    IUIAutomation2_PollForPotentialSupportedProperties TYPEDEF PROTO :XWORD, pElement:XWORD, propertyIds:XWORD, propertyNames:XWORD
    FIUIAutomation2_PollForPotentialSupportedProperties TYPEDEF PTR IUIAutomation2_PollForPotentialSupportedProperties

    IUIAutomation2_CheckNotSupported TYPEDEF PROTO :XWORD, value:VARIANT, isNotSupported:XWORD
    FIUIAutomation2_CheckNotSupported TYPEDEF PTR IUIAutomation2_CheckNotSupported

    IUIAutomation2_get_ReservedNotSupportedValue TYPEDEF PROTO :XWORD, notSupportedValue:XWORD
    FIUIAutomation2_get_ReservedNotSupportedValue TYPEDEF PTR IUIAutomation2_get_ReservedNotSupportedValue

    IUIAutomation2_get_ReservedMixedAttributeValue TYPEDEF PROTO :XWORD, mixedAttributeValue:XWORD
    FIUIAutomation2_get_ReservedMixedAttributeValue TYPEDEF PTR IUIAutomation2_get_ReservedMixedAttributeValue

    IUIAutomation2_ElementFromIAccessible TYPEDEF PROTO :XWORD, accessible:XWORD, childId:XWORD, element:XWORD
    FIUIAutomation2_ElementFromIAccessible TYPEDEF PTR IUIAutomation2_ElementFromIAccessible

    IUIAutomation2_ElementFromIAccessibleBuildCache TYPEDEF PROTO :XWORD, accessible:XWORD, childId:XWORD, cacheRequest:XWORD, element:XWORD
    FIUIAutomation2_ElementFromIAccessibleBuildCache TYPEDEF PTR IUIAutomation2_ElementFromIAccessibleBuildCache

    IUIAutomation2_get_AutoSetFocus TYPEDEF PROTO :XWORD, autoSetFocus:XWORD
    FIUIAutomation2_get_AutoSetFocus TYPEDEF PTR IUIAutomation2_get_AutoSetFocus

    IUIAutomation2_get_ConnectionTimeout TYPEDEF PROTO :XWORD, timeout:XWORD
    FIUIAutomation2_get_ConnectionTimeout TYPEDEF PTR IUIAutomation2_get_ConnectionTimeout

    IUIAutomation2_get_TransactionTimeout TYPEDEF PROTO :XWORD, timeout:XWORD
    FIUIAutomation2_get_TransactionTimeout TYPEDEF PTR IUIAutomation2_get_TransactionTimeout

    STIUIAutomation2 STRUCT
        QueryInterface                              FIUIAutomation2_QueryInterface ?
        AddRef                                      XPTR ?
        Release                                     XPTR ?
        CompareElements                             FIUIAutomation2_CompareElements ?
        CompareRuntimeIds                           FIUIAutomation2_CompareRuntimeIds ?
        GetRootElement                              FIUIAutomation2_GetRootElement ?
        ElementFromHandle                           FIUIAutomation2_ElementFromHandle ?
        ElementFromPoint                            FIUIAutomation2_ElementFromPoint ?
        GetFocusedElement                           FIUIAutomation2_GetFocusedElement ?
        GetRootElementBuildCache                    FIUIAutomation2_GetRootElementBuildCache ?
        ElementFromHandleBuildCache                 FIUIAutomation2_ElementFromHandleBuildCache ?
        ElementFromPointBuildCache                  FIUIAutomation2_ElementFromPointBuildCache ?
        GetFocusedElementBuildCache                 FIUIAutomation2_GetFocusedElementBuildCache ?
        CreateTreeWalker                            FIUIAutomation2_CreateTreeWalker ?
        get_ControlViewWalker                       FIUIAutomation2_get_ControlViewWalker ?
        get_ContentViewWalker                       FIUIAutomation2_get_ContentViewWalker ?
        get_RawViewWalker                           FIUIAutomation2_get_RawViewWalker ?
        get_RawViewCondition                        FIUIAutomation2_get_RawViewCondition ?
        get_ControlViewCondition                    FIUIAutomation2_get_ControlViewCondition ?
        get_ContentViewCondition                    FIUIAutomation2_get_ContentViewCondition ?
        CreateCacheRequest                          FIUIAutomation2_CreateCacheRequest ?
        CreateTrueCondition                         FIUIAutomation2_CreateTrueCondition ?
        CreateFalseCondition                        FIUIAutomation2_CreateFalseCondition ?
        CreatePropertyCondition                     FIUIAutomation2_CreatePropertyCondition ?
        CreatePropertyConditionEx                   FIUIAutomation2_CreatePropertyConditionEx ?
        CreateAndCondition                          FIUIAutomation2_CreateAndCondition ?
        CreateAndConditionFromArray                 FIUIAutomation2_CreateAndConditionFromArray ?
        CreateAndConditionFromNativeArray           FIUIAutomation2_CreateAndConditionFromNativeArray ?
        CreateOrCondition                           FIUIAutomation2_CreateOrCondition ?
        CreateOrConditionFromArray                  FIUIAutomation2_CreateOrConditionFromArray ?
        CreateOrConditionFromNativeArray            FIUIAutomation2_CreateOrConditionFromNativeArray ?
        CreateNotCondition                          FIUIAutomation2_CreateNotCondition ?
        AddAutomationEventHandler                   FIUIAutomation2_AddAutomationEventHandler ?
        RemoveAutomationEventHandler                FIUIAutomation2_RemoveAutomationEventHandler ?
        AddPropertyChangedEventHandlerNativeArray   FIUIAutomation2_AddPropertyChangedEventHandlerNativeArray ?
        AddPropertyChangedEventHandler              FIUIAutomation2_AddPropertyChangedEventHandler ?
        RemovePropertyChangedEventHandler           FIUIAutomation2_RemovePropertyChangedEventHandler ?
        AddStructureChangedEventHandler             FIUIAutomation2_AddStructureChangedEventHandler ?
        RemoveStructureChangedEventHandler          FIUIAutomation2_RemoveStructureChangedEventHandler ?
        AddFocusChangedEventHandler                 FIUIAutomation2_AddFocusChangedEventHandler ?
        RemoveFocusChangedEventHandler              FIUIAutomation2_RemoveFocusChangedEventHandler ?
        RemoveAllEventHandlers                      XPTR ?
        IntNativeArrayToSafeArray                   FIUIAutomation2_IntNativeArrayToSafeArray ?
        IntSafeArrayToNativeArray                   FIUIAutomation2_IntSafeArrayToNativeArray ?
        RectToVariant                               FIUIAutomation2_RectToVariant ?
        VariantToRect                               FIUIAutomation2_VariantToRect ?
        SafeArrayToRectNativeArray                  FIUIAutomation2_SafeArrayToRectNativeArray ?
        CreateProxyFactoryEntry                     FIUIAutomation2_CreateProxyFactoryEntry ?
        get_ProxyFactoryMapping                     FIUIAutomation2_get_ProxyFactoryMapping ?
        GetPropertyProgrammaticName                 FIUIAutomation2_GetPropertyProgrammaticName ?
        GetPatternProgrammaticName                  FIUIAutomation2_GetPatternProgrammaticName ?
        PollForPotentialSupportedPatterns           FIUIAutomation2_PollForPotentialSupportedPatterns ?
        PollForPotentialSupportedProperties         FIUIAutomation2_PollForPotentialSupportedProperties ?
        CheckNotSupported                           FIUIAutomation2_CheckNotSupported ?
        get_ReservedNotSupportedValue               FIUIAutomation2_get_ReservedNotSupportedValue ?
        get_ReservedMixedAttributeValue             FIUIAutomation2_get_ReservedMixedAttributeValue ?
        ElementFromIAccessible                      FIUIAutomation2_ElementFromIAccessible ?
        ElementFromIAccessibleBuildCache            FIUIAutomation2_ElementFromIAccessibleBuildCache ?
        get_AutoSetFocus                            FIUIAutomation2_get_AutoSetFocus ?
        put_AutoSetFocus                            XPTR ?
        get_ConnectionTimeout                       FIUIAutomation2_get_ConnectionTimeout ?
        put_ConnectionTimeout                       XPTR ?
        get_TransactionTimeout                      FIUIAutomation2_get_TransactionTimeout ?
        put_TransactionTimeout                      XPTR ?
    STIUIAutomation2 ENDS

    IUIAutomation2 MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomation2 PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomation2>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomation2
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomation2_INTERFACE_DEFINED__

IFNDEF __IUIAutomation3_INTERFACE_DEFINED__
    __IUIAutomation3_INTERFACE_DEFINED__    EQU 1

    IUIAutomation3_QueryInterface TYPEDEF PROTO :XWORD, riid:XWORD, ppvObject:XWORD
    FIUIAutomation3_QueryInterface TYPEDEF PTR IUIAutomation3_QueryInterface

    IUIAutomation3_CompareElements TYPEDEF PROTO :XWORD, el1:XWORD, el2:XWORD, areSame:XWORD
    FIUIAutomation3_CompareElements TYPEDEF PTR IUIAutomation3_CompareElements

    IUIAutomation3_CompareRuntimeIds TYPEDEF PROTO :XWORD, runtimeId1:XWORD, runtimeId2:XWORD, areSame:XWORD
    FIUIAutomation3_CompareRuntimeIds TYPEDEF PTR IUIAutomation3_CompareRuntimeIds

    IUIAutomation3_GetRootElement TYPEDEF PROTO :XWORD, root:XWORD
    FIUIAutomation3_GetRootElement TYPEDEF PTR IUIAutomation3_GetRootElement

    IUIAutomation3_ElementFromHandle TYPEDEF PROTO :XWORD, hwnd:XWORD, element:XWORD
    FIUIAutomation3_ElementFromHandle TYPEDEF PTR IUIAutomation3_ElementFromHandle

    IUIAutomation3_ElementFromPoint TYPEDEF PROTO :XWORD, pt:POINT, element:XWORD
    FIUIAutomation3_ElementFromPoint TYPEDEF PTR IUIAutomation3_ElementFromPoint

    IUIAutomation3_GetFocusedElement TYPEDEF PROTO :XWORD, element:XWORD
    FIUIAutomation3_GetFocusedElement TYPEDEF PTR IUIAutomation3_GetFocusedElement

    IUIAutomation3_GetRootElementBuildCache TYPEDEF PROTO :XWORD, cacheRequest:XWORD, root:XWORD
    FIUIAutomation3_GetRootElementBuildCache TYPEDEF PTR IUIAutomation3_GetRootElementBuildCache

    IUIAutomation3_ElementFromHandleBuildCache TYPEDEF PROTO :XWORD, hwnd:XWORD, cacheRequest:XWORD, element:XWORD
    FIUIAutomation3_ElementFromHandleBuildCache TYPEDEF PTR IUIAutomation3_ElementFromHandleBuildCache

    IUIAutomation3_ElementFromPointBuildCache TYPEDEF PROTO :XWORD, pt:POINT, cacheRequest:XWORD, element:XWORD
    FIUIAutomation3_ElementFromPointBuildCache TYPEDEF PTR IUIAutomation3_ElementFromPointBuildCache

    IUIAutomation3_GetFocusedElementBuildCache TYPEDEF PROTO :XWORD, cacheRequest:XWORD, element:XWORD
    FIUIAutomation3_GetFocusedElementBuildCache TYPEDEF PTR IUIAutomation3_GetFocusedElementBuildCache

    IUIAutomation3_CreateTreeWalker TYPEDEF PROTO :XWORD, pCondition:XWORD, walker:XWORD
    FIUIAutomation3_CreateTreeWalker TYPEDEF PTR IUIAutomation3_CreateTreeWalker

    IUIAutomation3_get_ControlViewWalker TYPEDEF PROTO :XWORD, walker:XWORD
    FIUIAutomation3_get_ControlViewWalker TYPEDEF PTR IUIAutomation3_get_ControlViewWalker

    IUIAutomation3_get_ContentViewWalker TYPEDEF PROTO :XWORD, walker:XWORD
    FIUIAutomation3_get_ContentViewWalker TYPEDEF PTR IUIAutomation3_get_ContentViewWalker

    IUIAutomation3_get_RawViewWalker TYPEDEF PROTO :XWORD, walker:XWORD
    FIUIAutomation3_get_RawViewWalker TYPEDEF PTR IUIAutomation3_get_RawViewWalker

    IUIAutomation3_get_RawViewCondition TYPEDEF PROTO :XWORD, condition:XWORD
    FIUIAutomation3_get_RawViewCondition TYPEDEF PTR IUIAutomation3_get_RawViewCondition

    IUIAutomation3_get_ControlViewCondition TYPEDEF PROTO :XWORD, condition:XWORD
    FIUIAutomation3_get_ControlViewCondition TYPEDEF PTR IUIAutomation3_get_ControlViewCondition

    IUIAutomation3_get_ContentViewCondition TYPEDEF PROTO :XWORD, condition:XWORD
    FIUIAutomation3_get_ContentViewCondition TYPEDEF PTR IUIAutomation3_get_ContentViewCondition

    IUIAutomation3_CreateCacheRequest TYPEDEF PROTO :XWORD, cacheRequest:XWORD
    FIUIAutomation3_CreateCacheRequest TYPEDEF PTR IUIAutomation3_CreateCacheRequest

    IUIAutomation3_CreateTrueCondition TYPEDEF PROTO :XWORD, newCondition:XWORD
    FIUIAutomation3_CreateTrueCondition TYPEDEF PTR IUIAutomation3_CreateTrueCondition

    IUIAutomation3_CreateFalseCondition TYPEDEF PROTO :XWORD, newCondition:XWORD
    FIUIAutomation3_CreateFalseCondition TYPEDEF PTR IUIAutomation3_CreateFalseCondition

    IUIAutomation3_CreatePropertyCondition TYPEDEF PROTO :XWORD, propertyId:XWORD, value:VARIANT, newCondition:XWORD
    FIUIAutomation3_CreatePropertyCondition TYPEDEF PTR IUIAutomation3_CreatePropertyCondition

    IUIAutomation3_CreatePropertyConditionEx TYPEDEF PROTO :XWORD, propertyId:XWORD, value:VARIANT, flags:XWORD, newCondition:XWORD
    FIUIAutomation3_CreatePropertyConditionEx TYPEDEF PTR IUIAutomation3_CreatePropertyConditionEx

    IUIAutomation3_CreateAndCondition TYPEDEF PROTO :XWORD, condition1:XWORD, condition2:XWORD, newCondition:XWORD
    FIUIAutomation3_CreateAndCondition TYPEDEF PTR IUIAutomation3_CreateAndCondition

    IUIAutomation3_CreateAndConditionFromArray TYPEDEF PROTO :XWORD, conditions:XWORD, newCondition:XWORD
    FIUIAutomation3_CreateAndConditionFromArray TYPEDEF PTR IUIAutomation3_CreateAndConditionFromArray

    IUIAutomation3_CreateAndConditionFromNativeArray TYPEDEF PROTO :XWORD, conditions:XWORD, conditionCount:XWORD, newCondition:XWORD
    FIUIAutomation3_CreateAndConditionFromNativeArray TYPEDEF PTR IUIAutomation3_CreateAndConditionFromNativeArray

    IUIAutomation3_CreateOrCondition TYPEDEF PROTO :XWORD, condition1:XWORD, condition2:XWORD, newCondition:XWORD
    FIUIAutomation3_CreateOrCondition TYPEDEF PTR IUIAutomation3_CreateOrCondition

    IUIAutomation3_CreateOrConditionFromArray TYPEDEF PROTO :XWORD, conditions:XWORD, newCondition:XWORD
    FIUIAutomation3_CreateOrConditionFromArray TYPEDEF PTR IUIAutomation3_CreateOrConditionFromArray

    IUIAutomation3_CreateOrConditionFromNativeArray TYPEDEF PROTO :XWORD, conditions:XWORD, conditionCount:XWORD, newCondition:XWORD
    FIUIAutomation3_CreateOrConditionFromNativeArray TYPEDEF PTR IUIAutomation3_CreateOrConditionFromNativeArray

    IUIAutomation3_CreateNotCondition TYPEDEF PROTO :XWORD, condition:XWORD, newCondition:XWORD
    FIUIAutomation3_CreateNotCondition TYPEDEF PTR IUIAutomation3_CreateNotCondition

    IUIAutomation3_AddAutomationEventHandler TYPEDEF PROTO :XWORD, eventId:XWORD, element:XWORD, scope:XWORD, cacheRequest:XWORD, handler:XWORD
    FIUIAutomation3_AddAutomationEventHandler TYPEDEF PTR IUIAutomation3_AddAutomationEventHandler

    IUIAutomation3_RemoveAutomationEventHandler TYPEDEF PROTO :XWORD, eventId:XWORD, element:XWORD, handler:XWORD
    FIUIAutomation3_RemoveAutomationEventHandler TYPEDEF PTR IUIAutomation3_RemoveAutomationEventHandler

    IUIAutomation3_AddPropertyChangedEventHandlerNativeArray TYPEDEF PROTO :XWORD, element:XWORD, scope:XWORD, cacheRequest:XWORD, handler:XWORD, propertyArray:XWORD, propertyCount:XWORD 
    FIUIAutomation3_AddPropertyChangedEventHandlerNativeArray TYPEDEF PTR IUIAutomation3_AddPropertyChangedEventHandlerNativeArray

    IUIAutomation3_AddPropertyChangedEventHandler TYPEDEF PROTO :XWORD, element:XWORD, scope:XWORD, cacheRequest:XWORD, handler:XWORD, propertyArray:XWORD
    FIUIAutomation3_AddPropertyChangedEventHandler TYPEDEF PTR IUIAutomation3_AddPropertyChangedEventHandler

    IUIAutomation3_RemovePropertyChangedEventHandler TYPEDEF PROTO :XWORD, element:XWORD, handler:XWORD
    FIUIAutomation3_RemovePropertyChangedEventHandler TYPEDEF PTR IUIAutomation3_RemovePropertyChangedEventHandler

    IUIAutomation3_AddStructureChangedEventHandler TYPEDEF PROTO :XWORD, element:XWORD, scope:XWORD, cacheRequest:XWORD, handler:XWORD
    FIUIAutomation3_AddStructureChangedEventHandler TYPEDEF PTR IUIAutomation3_AddStructureChangedEventHandler

    IUIAutomation3_RemoveStructureChangedEventHandler TYPEDEF PROTO :XWORD, element:XWORD, handler:XWORD
    FIUIAutomation3_RemoveStructureChangedEventHandler TYPEDEF PTR IUIAutomation3_RemoveStructureChangedEventHandler

    IUIAutomation3_AddFocusChangedEventHandler TYPEDEF PROTO :XWORD, cacheRequest:XWORD, handler:XWORD
    FIUIAutomation3_AddFocusChangedEventHandler TYPEDEF PTR IUIAutomation3_AddFocusChangedEventHandler

    IUIAutomation3_RemoveFocusChangedEventHandler TYPEDEF PROTO :XWORD, handler:XWORD
    FIUIAutomation3_RemoveFocusChangedEventHandler TYPEDEF PTR IUIAutomation3_RemoveFocusChangedEventHandler

    IUIAutomation3_IntNativeArrayToSafeArray TYPEDEF PROTO :XWORD, array:XWORD, arrayCount:XWORD, safeArray:XWORD
    FIUIAutomation3_IntNativeArrayToSafeArray TYPEDEF PTR IUIAutomation3_IntNativeArrayToSafeArray

    IUIAutomation3_IntSafeArrayToNativeArray TYPEDEF PROTO :XWORD, intArray:XWORD, array:XWORD, arrayCount:XWORD
    FIUIAutomation3_IntSafeArrayToNativeArray TYPEDEF PTR IUIAutomation3_IntSafeArrayToNativeArray

    IUIAutomation3_RectToVariant TYPEDEF PROTO :XWORD, rc:RECT, var:XWORD
    FIUIAutomation3_RectToVariant TYPEDEF PTR IUIAutomation3_RectToVariant

    IUIAutomation3_VariantToRect TYPEDEF PROTO :XWORD, var:VARIANT, rc:XWORD
    FIUIAutomation3_VariantToRect TYPEDEF PTR IUIAutomation3_VariantToRect

    IUIAutomation3_SafeArrayToRectNativeArray TYPEDEF PROTO :XWORD, rects:XWORD, rectArray:XWORD, rectArrayCount:XWORD
    FIUIAutomation3_SafeArrayToRectNativeArray TYPEDEF PTR IUIAutomation3_SafeArrayToRectNativeArray

    IUIAutomation3_CreateProxyFactoryEntry TYPEDEF PROTO :XWORD, factory:XWORD, factoryEntry:XWORD
    FIUIAutomation3_CreateProxyFactoryEntry TYPEDEF PTR IUIAutomation3_CreateProxyFactoryEntry

    IUIAutomation3_get_ProxyFactoryMapping TYPEDEF PROTO :XWORD, factoryMapping:XWORD
    FIUIAutomation3_get_ProxyFactoryMapping TYPEDEF PTR IUIAutomation3_get_ProxyFactoryMapping

    IUIAutomation3_GetPropertyProgrammaticName TYPEDEF PROTO :XWORD, property:XWORD, aname:XWORD
    FIUIAutomation3_GetPropertyProgrammaticName TYPEDEF PTR IUIAutomation3_GetPropertyProgrammaticName

    IUIAutomation3_GetPatternProgrammaticName TYPEDEF PROTO :XWORD, pattern:XWORD, aname:XWORD
    FIUIAutomation3_GetPatternProgrammaticName TYPEDEF PTR IUIAutomation3_GetPatternProgrammaticName

    IUIAutomation3_PollForPotentialSupportedPatterns TYPEDEF PROTO :XWORD, pElement:XWORD, patternIds:XWORD, patternNames:XWORD
    FIUIAutomation3_PollForPotentialSupportedPatterns TYPEDEF PTR IUIAutomation3_PollForPotentialSupportedPatterns

    IUIAutomation3_PollForPotentialSupportedProperties TYPEDEF PROTO :XWORD, pElement:XWORD, propertyIds:XWORD, propertyNames:XWORD
    FIUIAutomation3_PollForPotentialSupportedProperties TYPEDEF PTR IUIAutomation3_PollForPotentialSupportedProperties

    IUIAutomation3_CheckNotSupported TYPEDEF PROTO :XWORD, value:VARIANT, isNotSupported:XWORD
    FIUIAutomation3_CheckNotSupported TYPEDEF PTR IUIAutomation3_CheckNotSupported

    IUIAutomation3_get_ReservedNotSupportedValue TYPEDEF PROTO :XWORD, notSupportedValue:XWORD
    FIUIAutomation3_get_ReservedNotSupportedValue TYPEDEF PTR IUIAutomation3_get_ReservedNotSupportedValue

    IUIAutomation3_get_ReservedMixedAttributeValue TYPEDEF PROTO :XWORD, mixedAttributeValue:XWORD
    FIUIAutomation3_get_ReservedMixedAttributeValue TYPEDEF PTR IUIAutomation3_get_ReservedMixedAttributeValue

    IUIAutomation3_ElementFromIAccessible TYPEDEF PROTO :XWORD, accessible:XWORD, childId:XWORD, element:XWORD
    FIUIAutomation3_ElementFromIAccessible TYPEDEF PTR IUIAutomation3_ElementFromIAccessible

    IUIAutomation3_ElementFromIAccessibleBuildCache TYPEDEF PROTO :XWORD, accessible:XWORD, childId:XWORD, cacheRequest:XWORD, element:XWORD
    FIUIAutomation3_ElementFromIAccessibleBuildCache TYPEDEF PTR IUIAutomation3_ElementFromIAccessibleBuildCache

    IUIAutomation3_get_AutoSetFocus TYPEDEF PROTO :XWORD, autoSetFocus:XWORD
    FIUIAutomation3_get_AutoSetFocus TYPEDEF PTR IUIAutomation3_get_AutoSetFocus

    IUIAutomation3_get_ConnectionTimeout TYPEDEF PROTO :XWORD, timeout:XWORD
    FIUIAutomation3_get_ConnectionTimeout TYPEDEF PTR IUIAutomation3_get_ConnectionTimeout

    IUIAutomation3_get_TransactionTimeout TYPEDEF PROTO :XWORD, timeout:XWORD
    FIUIAutomation3_get_TransactionTimeout TYPEDEF PTR IUIAutomation3_get_TransactionTimeout

    IUIAutomation3_AddTextEditTextChangedEventHandler TYPEDEF PROTO :XWORD, element:XWORD, scope:XWORD, textEditChangeType:XWORD, cacheRequest:XWORD, handler:XWORD
    FIUIAutomation3_AddTextEditTextChangedEventHandler TYPEDEF PTR IUIAutomation3_AddTextEditTextChangedEventHandler

    IUIAutomation3_RemoveTextEditTextChangedEventHandler TYPEDEF PROTO :XWORD, element:XWORD, handler:XWORD
    FIUIAutomation3_RemoveTextEditTextChangedEventHandler TYPEDEF PTR IUIAutomation3_RemoveTextEditTextChangedEventHandler

    STIUIAutomation3 STRUCT
        QueryInterface                              FIUIAutomation3_QueryInterface ?
        AddRef                                      XPTR ?
        Release                                     XPTR ?
        CompareElements                             FIUIAutomation3_CompareElements ?
        CompareRuntimeIds                           FIUIAutomation3_CompareRuntimeIds ?
        GetRootElement                              FIUIAutomation3_GetRootElement ?
        ElementFromHandle                           FIUIAutomation3_ElementFromHandle ?
        ElementFromPoint                            FIUIAutomation3_ElementFromPoint ?
        GetFocusedElement                           FIUIAutomation3_GetFocusedElement ?
        GetRootElementBuildCache                    FIUIAutomation3_GetRootElementBuildCache ?
        ElementFromHandleBuildCache                 FIUIAutomation3_ElementFromHandleBuildCache ?
        ElementFromPointBuildCache                  FIUIAutomation3_ElementFromPointBuildCache ?
        GetFocusedElementBuildCache                 FIUIAutomation3_GetFocusedElementBuildCache ?
        CreateTreeWalker                            FIUIAutomation3_CreateTreeWalker ?
        get_ControlViewWalker                       FIUIAutomation3_get_ControlViewWalker ?
        get_ContentViewWalker                       FIUIAutomation3_get_ContentViewWalker ?
        get_RawViewWalker                           FIUIAutomation3_get_RawViewWalker ?
        get_RawViewCondition                        FIUIAutomation3_get_RawViewCondition ?
        get_ControlViewCondition                    FIUIAutomation3_get_ControlViewCondition ?
        get_ContentViewCondition                    FIUIAutomation3_get_ContentViewCondition ?
        CreateCacheRequest                          FIUIAutomation3_CreateCacheRequest ?
        CreateTrueCondition                         FIUIAutomation3_CreateTrueCondition ?
        CreateFalseCondition                        FIUIAutomation3_CreateFalseCondition ?
        CreatePropertyCondition                     FIUIAutomation3_CreatePropertyCondition ?
        CreatePropertyConditionEx                   FIUIAutomation3_CreatePropertyConditionEx ?
        CreateAndCondition                          FIUIAutomation3_CreateAndCondition ?
        CreateAndConditionFromArray                 FIUIAutomation3_CreateAndConditionFromArray ?
        CreateAndConditionFromNativeArray           FIUIAutomation3_CreateAndConditionFromNativeArray ?
        CreateOrCondition                           FIUIAutomation3_CreateOrCondition ?
        CreateOrConditionFromArray                  FIUIAutomation3_CreateOrConditionFromArray ?
        CreateOrConditionFromNativeArray            FIUIAutomation3_CreateOrConditionFromNativeArray ?
        CreateNotCondition                          FIUIAutomation3_CreateNotCondition ?
        AddAutomationEventHandler                   FIUIAutomation3_AddAutomationEventHandler ?
        RemoveAutomationEventHandler                FIUIAutomation3_RemoveAutomationEventHandler ?
        AddPropertyChangedEventHandlerNativeArray   FIUIAutomation3_AddPropertyChangedEventHandlerNativeArray ?
        AddPropertyChangedEventHandler              FIUIAutomation3_AddPropertyChangedEventHandler ?
        RemovePropertyChangedEventHandler           FIUIAutomation3_RemovePropertyChangedEventHandler ?
        AddStructureChangedEventHandler             FIUIAutomation3_AddStructureChangedEventHandler ?
        RemoveStructureChangedEventHandler          FIUIAutomation3_RemoveStructureChangedEventHandler ?
        AddFocusChangedEventHandler                 FIUIAutomation3_AddFocusChangedEventHandler ?
        RemoveFocusChangedEventHandler              FIUIAutomation3_RemoveFocusChangedEventHandler ?
        RemoveAllEventHandlers                      XPTR ?
        IntNativeArrayToSafeArray                   FIUIAutomation3_IntNativeArrayToSafeArray ?
        IntSafeArrayToNativeArray                   FIUIAutomation3_IntSafeArrayToNativeArray ?
        RectToVariant                               FIUIAutomation3_RectToVariant ?
        VariantToRect                               FIUIAutomation3_VariantToRect ?
        SafeArrayToRectNativeArray                  FIUIAutomation3_SafeArrayToRectNativeArray ?
        CreateProxyFactoryEntry                     FIUIAutomation3_CreateProxyFactoryEntry ?
        get_ProxyFactoryMapping                     FIUIAutomation3_get_ProxyFactoryMapping ?
        GetPropertyProgrammaticName                 FIUIAutomation3_GetPropertyProgrammaticName ?
        GetPatternProgrammaticName                  FIUIAutomation3_GetPatternProgrammaticName ?
        PollForPotentialSupportedPatterns           FIUIAutomation3_PollForPotentialSupportedPatterns ?
        PollForPotentialSupportedProperties         FIUIAutomation3_PollForPotentialSupportedProperties ?
        CheckNotSupported                           FIUIAutomation3_CheckNotSupported ?
        get_ReservedNotSupportedValue               FIUIAutomation3_get_ReservedNotSupportedValue ?
        get_ReservedMixedAttributeValue             FIUIAutomation3_get_ReservedMixedAttributeValue ?
        ElementFromIAccessible                      FIUIAutomation3_ElementFromIAccessible ?
        ElementFromIAccessibleBuildCache            FIUIAutomation3_ElementFromIAccessibleBuildCache ?
        get_AutoSetFocus                            FIUIAutomation3_get_AutoSetFocus ?
        put_AutoSetFocus                            XPTR ?
        get_ConnectionTimeout                       FIUIAutomation3_get_ConnectionTimeout ?
        put_ConnectionTimeout                       XPTR ?
        get_TransactionTimeout                      FIUIAutomation3_get_TransactionTimeout ?
        put_TransactionTimeout                      XPTR ?
        AddTextEditTextChangedEventHandler          FIUIAutomation3_AddTextEditTextChangedEventHandler ?
        RemoveTextEditTextChangedEventHandler       FIUIAutomation3_RemoveTextEditTextChangedEventHandler ?
    STIUIAutomation3 ENDS
 
    IUIAutomation3 MACRO Function:REQ, args:VARARG
        LOCAL InvokeInterface, arg

        FOR arg, <args>
            IFIDNI <&arg>, <PPVREGISTER>
                .ERR PPVREGISTER is not allowed as a coinvoke parameter
            ENDIF
        ENDM
        IFIDNI <&pInterface>, <PPVREGISTER>
            .ERR PPVREGISTER is not allowed as a coinvoke parameter
        ENDIF
        InvokeInterface CATSTR <invoke (STIUIAutomation3 PTR[PPVREGISTER]).>, <&Function,ppvIUIAutomation3>
        IFNB <args>
            InvokeInterface CATSTR InvokeInterface, <, >, <&args> 
        ENDIF
        mov PPVREGISTER, ppvIUIAutomation3
        mov PPVREGISTER, [PPVREGISTER]
        InvokeInterface
    ENDM        
ENDIF ;__IUIAutomation3_INTERFACE_DEFINED__

ENDIF  ;UIAUTOMATIONCLIENT_INC
