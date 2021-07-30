; ====================================================;
;                                                     ;
;    comctl32.inc for EC v2 Fasm classic projects     ;
;                   (version 1.0.1)                   ;
;                                                     ;
;            Copyright © Ramon Sala - 2018            ;
;                                                     ;
; ====================================================;

if ~defined COMCTL32_INC
define COMCTL32_INC 1

import comctl32,\
AddMRUStringW,'AddMRUStringW',\
CreateMappedBitmap,'CreateMappedBitmap',\
CreateMRUListW,'CreateMRUListW',\
CreatePropertySheetPageA,'CreatePropertySheetPageA',\
CreatePropertySheetPageW,'CreatePropertySheetPageW',\
CreateStatusWindowA,'CreateStatusWindowA',\
CreateStatusWindowW,'CreateStatusWindowW',\
CreateToolbarEx,'CreateToolbarEx',\
CreateUpDownControl,'CreateUpDownControl',\
DefSubclassProc,'DefSubclassProc',\
DestroyPropertySheetPage,'DestroyPropertySheetPage',\
DPA_Clone,'DPA_Clone',\
DPA_Create,'DPA_Create',\
DPA_CreateEx,'DPA_CreateEx',\
DPA_DeleteAllPtrs,'DPA_DeleteAllPtrs',\
DPA_DeletePtr,'DPA_DeletePtr',\
DPA_Destroy,'DPA_Destroy',\
DPA_DestroyCallback,'DPA_DestroyCallback',\
DPA_EnumCallback,'DPA_EnumCallback',\
DPA_GetPtr,'DPA_GetPtr',\
DPA_GetPtrIndex,'DPA_GetPtrIndex',\
DPA_Grow,'DPA_Grow',\
DPA_InsertPtr,'DPA_InsertPtr',\
DPA_LoadStream,'DPA_LoadStream',\
DPA_Merge,'DPA_Merge',\
DPA_SaveStream,'DPA_SaveStream',\
DPA_Search,'DPA_Search',\
DPA_SetPtr,'DPA_SetPtr',\
DPA_Sort,'DPA_Sort',\
DrawInsert,'DrawInsert',\
DrawStatusTextA,'DrawStatusTextA',\
DrawStatusTextW,'DrawStatusTextW',\
DSA_Create,'DSA_Create',\
DSA_DeleteAllItems,'DSA_DeleteAllItems',\
DSA_DeleteItem,'DSA_DeleteItem',\
DSA_Destroy,'DSA_Destroy',\
DSA_DestroyCallback,'DSA_DestroyCallback',\
DSA_EnumCallback,'DSA_EnumCallback',\
DSA_GetItem,'DSA_GetItem',\
DSA_GetItemPtr,'DSA_GetItemPtr',\
DSA_InsertItem,'DSA_InsertItem',\
DSA_SetItem,'DSA_SetItem',\
EnumMRUListW,'EnumMRUListW',\
FlatSB_EnableScrollBar,'FlatSB_EnableScrollBar',\
FlatSB_GetScrollInfo,'FlatSB_GetScrollInfo',\
FlatSB_GetScrollPos,'FlatSB_GetScrollPos',\
FlatSB_GetScrollProp,'FlatSB_GetScrollProp',\
FlatSB_GetScrollPropPtr,'FlatSB_GetScrollPropPtr',\
FlatSB_GetScrollRange,'FlatSB_GetScrollRange',\
FlatSB_SetScrollInfo,'FlatSB_SetScrollInfo',\
FlatSB_SetScrollPos,'FlatSB_SetScrollPos',\
FlatSB_SetScrollProp,'FlatSB_SetScrollProp',\
FlatSB_SetScrollRange,'FlatSB_SetScrollRange',\
FlatSB_ShowScrollBar,'FlatSB_ShowScrollBar',\
FreeMRUList,'FreeMRUList',\
GetEffectiveClientRect,'GetEffectiveClientRect',\
GetMUILanguage,'GetMUILanguage',\
ImageList_Add,'ImageList_Add',\
ImageList_AddIcon,'ImageList_AddIcon',\
ImageList_AddMasked,'ImageList_AddMasked',\
ImageList_BeginDrag,'ImageList_BeginDrag',\
ImageList_Copy,'ImageList_Copy',\
ImageList_Create,'ImageList_Create',\
ImageList_Destroy,'ImageList_Destroy',\
ImageList_DragEnter,'ImageList_DragEnter',\
ImageList_DragLeave,'ImageList_DragLeave',\
ImageList_DragMove,'ImageList_DragMove',\
ImageList_DragShowNolock,'ImageList_DragShowNolock',\
ImageList_Draw,'ImageList_Draw',\
ImageList_DrawEx,'ImageList_DrawEx',\
ImageList_DrawIndirect,'ImageList_DrawIndirect',\
ImageList_Duplicate,'ImageList_Duplicate',\
ImageList_EndDrag,'ImageList_EndDrag',\
ImageList_GetBkColor,'ImageList_GetBkColor',\
ImageList_GetDragImage,'ImageList_GetDragImage',\
ImageList_GetFlags,'ImageList_GetFlags',\
ImageList_GetIcon,'ImageList_GetIcon',\
ImageList_GetIconSize,'ImageList_GetIconSize',\
ImageList_GetImageCount,'ImageList_GetImageCount',\
ImageList_GetImageInfo,'ImageList_GetImageInfo',\
ImageList_GetImageRect,'ImageList_GetImageRect',\
ImageList_LoadImageA,'ImageList_LoadImageA',\
ImageList_LoadImageW,'ImageList_LoadImageW',\
ImageList_Merge,'ImageList_Merge',\
ImageList_Read,'ImageList_Read',\
ImageList_Remove,'ImageList_Remove',\
ImageList_Replace,'ImageList_Replace',\
ImageList_ReplaceIcon,'ImageList_ReplaceIcon',\
ImageList_SetBkColor,'ImageList_SetBkColor',\
ImageList_SetDragCursorImage,'ImageList_SetDragCursorImage',\
ImageList_SetFilter,'ImageList_SetFilter',\
ImageList_SetFlags,'ImageList_SetFlags',\
ImageList_SetIconSize,'ImageList_SetIconSize',\
ImageList_SetImageCount,'ImageList_SetImageCount',\
ImageList_SetOverlayImage,'ImageList_SetOverlayImage',\
ImageList_Write,'ImageList_Write',\
InitCommonControls,'InitCommonControls',\
InitCommonControlsEx,'InitCommonControlsEx',\
InitializeFlatSB,'InitializeFlatSB',\
InitMUILanguage,'InitMUILanguage',\
LBItemFromPt,'LBItemFromPt',\
MakeDragList,'MakeDragList',\
MenuHelp,'MenuHelp',\
PropertySheetA,'PropertySheetA',\
PropertySheetW,'PropertySheetW',\
RegisterClassNameW,'RegisterClassNameW',\
RemoveWindowSubclass,'RemoveWindowSubclass',\
SetWindowSubclass,'SetWindowSubclass',\
ShowHideMenuCtl,'ShowHideMenuCtl',\
Str_SetPtrA,'Str_SetPtrA',\
Str_SetPtrW,'Str_SetPtrW',\
UninitializeFlatSB,'UninitializeFlatSB',\
_TrackMouseEvent,'_TrackMouseEvent'

api CreatePropertySheetPage,\
    CreateStatusWindow,\
    DrawStatusText,\
    ImageList_LoadImage,\
    PropertySheet,\
    Str_SetPtr

;======================= Undocumented functions (unknown arguments) =======================;
;CreateToolbar,'CreateToolbar',\

end if ;COMCTL32_INC
