; ====================================================;
;                                                     ;
;     comctl32.inc for EC v2 Fasm visual projects     ;
;                   (version 1.0.0)                   ;
;                                                     ;
;            Copyright © Ramon Sala - 2018            ;
;                                                     ;
; ====================================================;

if ~defined COMCTL32_INC
define COMCTL32_INC 1

if defined APP_WIN64
    extrn '__imp_CreateMappedBitmap' as CreateMappedBitmap:qword
    extrn '__imp_CreatePropertySheetPageA' as CreatePropertySheetPageA:qword
    extrn '__imp_CreatePropertySheetPageW' as CreatePropertySheetPageW:qword
    extrn '__imp_CreateStatusWindowA' as CreateStatusWindowA:qword
    extrn '__imp_CreateStatusWindowW' as CreateStatusWindowW:qword
    extrn '__imp_CreateToolbarEx' as CreateToolbarEx:qword
    extrn '__imp_CreateUpDownControl' as CreateUpDownControl:qword
    extrn '__imp_DestroyPropertySheetPage' as DestroyPropertySheetPage:qword
    extrn '__imp_DrawInsert' as DrawInsert:qword
    extrn '__imp_DrawStatusTextA' as DrawStatusTextA:qword
    extrn '__imp_DrawStatusTextW' as DrawStatusTextW:qword
    extrn '__imp_FlatSB_EnableScrollBar' as FlatSB_EnableScrollBar:qword
    extrn '__imp_FlatSB_GetScrollInfo' as FlatSB_GetScrollInfo:qword
    extrn '__imp_FlatSB_GetScrollPos' as FlatSB_GetScrollPos:qword
    extrn '__imp_FlatSB_GetScrollProp' as FlatSB_GetScrollProp:qword
    extrn '__imp_FlatSB_GetScrollRange' as FlatSB_GetScrollRange:qword
    extrn '__imp_FlatSB_SetScrollInfo' as FlatSB_SetScrollInfo:qword
    extrn '__imp_FlatSB_SetScrollPos' as FlatSB_SetScrollPos:qword
    extrn '__imp_FlatSB_SetScrollProp' as FlatSB_SetScrollProp:qword
    extrn '__imp_FlatSB_SetScrollRange' as FlatSB_SetScrollRange:qword
    extrn '__imp_FlatSB_ShowScrollBar' as FlatSB_ShowScrollBar:qword
    extrn '__imp_GetEffectiveClientRect' as GetEffectiveClientRect:qword
    extrn '__imp_GetMUILanguage' as GetMUILanguage:qword
    extrn '__imp_ImageList_Add' as ImageList_Add:qword
    extrn '__imp_ImageList_AddIcon' as ImageList_AddIcon:qword
    extrn '__imp_ImageList_AddMasked' as ImageList_AddMasked:qword
    extrn '__imp_ImageList_BeginDrag' as ImageList_BeginDrag:qword
    extrn '__imp_ImageList_Copy' as ImageList_Copy:qword
    extrn '__imp_ImageList_Create' as ImageList_Create:qword
    extrn '__imp_ImageList_Destroy' as ImageList_Destroy:qword
    extrn '__imp_ImageList_DragEnter' as ImageList_DragEnter:qword
    extrn '__imp_ImageList_DragLeave' as ImageList_DragLeave:qword
    extrn '__imp_ImageList_DragMove' as ImageList_DragMove:qword
    extrn '__imp_ImageList_DragShowNolock' as ImageList_DragShowNolock:qword
    extrn '__imp_ImageList_Draw' as ImageList_Draw:qword
    extrn '__imp_ImageList_DrawEx' as ImageList_DrawEx:qword
    extrn '__imp_ImageList_DrawIndirect' as ImageList_DrawIndirect:qword
    extrn '__imp_ImageList_Duplicate' as ImageList_Duplicate:qword
    extrn '__imp_ImageList_EndDrag' as ImageList_EndDrag:qword
    extrn '__imp_ImageList_GetBkColor' as ImageList_GetBkColor:qword
    extrn '__imp_ImageList_GetDragImage' as ImageList_GetDragImage:qword
    extrn '__imp_ImageList_GetFlags' as ImageList_GetFlags:qword
    extrn '__imp_ImageList_GetIcon' as ImageList_GetIcon:qword
    extrn '__imp_ImageList_GetIconSize' as ImageList_GetIconSize:qword
    extrn '__imp_ImageList_GetImageCount' as ImageList_GetImageCount:qword
    extrn '__imp_ImageList_GetImageInfo' as ImageList_GetImageInfo:qword
    extrn '__imp_ImageList_GetImageRect' as ImageList_GetImageRect:qword
    extrn '__imp_ImageList_LoadImageA' as ImageList_LoadImageA:qword
    extrn '__imp_ImageList_LoadImageW' as ImageList_LoadImageW:qword
    extrn '__imp_ImageList_Merge' as ImageList_Merge:qword
    extrn '__imp_ImageList_Read' as ImageList_Read:qword
    extrn '__imp_ImageList_Remove' as ImageList_Remove:qword
    extrn '__imp_ImageList_Replace' as ImageList_Replace:qword
    extrn '__imp_ImageList_ReplaceIcon' as ImageList_ReplaceIcon:qword
    extrn '__imp_ImageList_SetBkColor' as ImageList_SetBkColor:qword
    extrn '__imp_ImageList_SetDragCursorImage' as ImageList_SetDragCursorImage:qword
    extrn '__imp_ImageList_SetFilter' as ImageList_SetFilter:qword
    extrn '__imp_ImageList_SetFlags' as ImageList_SetFlags:qword
    extrn '__imp_ImageList_SetIconSize' as ImageList_SetIconSize:qword
    extrn '__imp_ImageList_SetImageCount' as ImageList_SetImageCount:qword
    extrn '__imp_ImageList_SetOverlayImage' as ImageList_SetOverlayImage:qword
    extrn '__imp_ImageList_Write' as ImageList_Write:qword
    extrn '__imp_InitCommonControls' as InitCommonControls:qword
    extrn '__imp_InitCommonControlsEx' as InitCommonControlsEx:qword
    extrn '__imp_InitializeFlatSB' as InitializeFlatSB:qword
    extrn '__imp_InitMUILanguage' as InitMUILanguage:qword
    extrn '__imp_LBItemFromPt' as LBItemFromPt:qword
    extrn '__imp_MakeDragList' as MakeDragList:qword
    extrn '__imp_MenuHelp' as MenuHelp:qword
    extrn '__imp_PropertySheetA' as PropertySheetA:qword
    extrn '__imp_PropertySheetW' as PropertySheetW:qword
    extrn '__imp_ShowHideMenuCtl' as ShowHideMenuCtl:qword
    extrn '__imp_UninitializeFlatSB' as UninitializeFlatSB:qword
    extrn '__imp__TrackMouseEvent' as _TrackMouseEvent:qword

    if (NTDDI_VERSION >= NTDDI_WINXP)
        extrn '__imp_AddMRUStringW' as AddMRUStringW:qword
        extrn '__imp_CreateMRUListW' as CreateMRUListW:qword
        extrn '__imp_DefSubclassProc' as DefSubclassProc:qword
        extrn '__imp_DPA_Create' as DPA_Create:qword
        extrn '__imp_DPA_DeleteAllPtrs' as DPA_DeleteAllPtrs:qword
        extrn '__imp_DPA_DeletePtr' as DPA_DeletePtr:qword
        extrn '__imp_DPA_Destroy' as DPA_Destroy:qword
        extrn '__imp_DPA_DestroyCallback' as DPA_DestroyCallback:qword
        extrn '__imp_DPA_EnumCallback' as DPA_EnumCallback:qword
        extrn '__imp_DPA_GetPtr' as DPA_GetPtr:qword
        extrn '__imp_DPA_InsertPtr' as DPA_InsertPtr:qword
        extrn '__imp_DPA_Search' as DPA_Search:qword
        extrn '__imp_DPA_SetPtr' as DPA_SetPtr:qword
        extrn '__imp_DPA_Sort' as DPA_Sort:qword
        extrn '__imp_DSA_Create' as DSA_Create:qword
        extrn '__imp_DSA_DeleteAllItems' as DSA_DeleteAllItems:qword
        extrn '__imp_DSA_Destroy' as DSA_Destroy:qword
        extrn '__imp_DSA_DestroyCallback' as DSA_DestroyCallback:qword
        extrn '__imp_DSA_GetItemPtr' as DSA_GetItemPtr:qword
        extrn '__imp_DSA_InsertItem' as DSA_InsertItem:qword
        extrn '__imp_EnumMRUListW' as EnumMRUListW:qword
        extrn '__imp_FlatSB_GetScrollPropPtr' as FlatSB_GetScrollPropPtr:qword
        extrn '__imp_FreeMRUList' as FreeMRUList:qword
        extrn '__imp_RegisterClassNameW' as RegisterClassNameW:qword
        extrn '__imp_RemoveWindowSubclass' as RemoveWindowSubclass:qword
        extrn '__imp_SetWindowSubclass' as SetWindowSubclass:qword
    end if

    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_DPA_Clone' as DPA_Clone:qword
        extrn '__imp_DPA_CreateEx' as DPA_CreateEx:qword
        extrn '__imp_DPA_GetPtrIndex' as DPA_GetPtrIndex:qword
        extrn '__imp_DPA_Grow' as DPA_Grow:qword
        extrn '__imp_DPA_LoadStream' as DPA_LoadStream:qword
        extrn '__imp_DPA_Merge' as DPA_Merge:qword
        extrn '__imp_DPA_SaveStream' as DPA_SaveStream:qword
        extrn '__imp_DSA_DeleteItem' as DSA_DeleteItem:qword
        extrn '__imp_DSA_EnumCallback' as DSA_EnumCallback:qword
        extrn '__imp_DSA_GetItem' as DSA_GetItem:qword
        extrn '__imp_DSA_SetItem' as DSA_SetItem:qword
        extrn '__imp_Str_SetPtrA' as Str_SetPtrA:qword
        extrn '__imp_Str_SetPtrW' as Str_SetPtrW:qword
        api Str_SetPtr
    end if

    api CreatePropertySheetPage,\
        CreateStatusWindow,\
        DrawStatusText,\
        ImageList_LoadImage,\
        PropertySheet
else
    extrn '__imp__CreateMappedBitmap@20' as CreateMappedBitmap:dword
    extrn '__imp__CreatePropertySheetPageA@4' as CreatePropertySheetPageA:dword
    extrn '__imp__CreatePropertySheetPageW@4' as CreatePropertySheetPageW:dword
    extrn '__imp__CreateStatusWindowA@16' as CreateStatusWindowA:dword
    extrn '__imp__CreateStatusWindowW@16' as CreateStatusWindowW:dword
    extrn '__imp__CreateToolbarEx@52' as CreateToolbarEx:dword
    extrn '__imp__CreateUpDownControl@48' as CreateUpDownControl:dword
    extrn '__imp__DestroyPropertySheetPage@4' as DestroyPropertySheetPage:dword
    extrn '__imp__DrawInsert@12' as DrawInsert:dword
    extrn '__imp__DrawStatusTextA@16' as DrawStatusTextA:dword
    extrn '__imp__DrawStatusTextW@16' as DrawStatusTextW:dword
    extrn '__imp__FlatSB_EnableScrollBar@12' as FlatSB_EnableScrollBar:dword
    extrn '__imp__FlatSB_GetScrollInfo@12' as FlatSB_GetScrollInfo:dword
    extrn '__imp__FlatSB_GetScrollPos@8' as FlatSB_GetScrollPos:dword
    extrn '__imp__FlatSB_GetScrollProp@12' as FlatSB_GetScrollProp:dword
    extrn '__imp__FlatSB_GetScrollRange@16' as FlatSB_GetScrollRange:dword
    extrn '__imp__FlatSB_SetScrollInfo@16' as FlatSB_SetScrollInfo:dword
    extrn '__imp__FlatSB_SetScrollPos@16' as FlatSB_SetScrollPos:dword
    extrn '__imp__FlatSB_SetScrollProp@16' as FlatSB_SetScrollProp:dword
    extrn '__imp__FlatSB_SetScrollRange@20' as FlatSB_SetScrollRange:dword
    extrn '__imp__FlatSB_ShowScrollBar@12' as FlatSB_ShowScrollBar:dword
    extrn '__imp__GetEffectiveClientRect@12' as GetEffectiveClientRect:dword
    extrn '__imp__GetMUILanguage@0' as GetMUILanguage:dword
    extrn '__imp__ImageList_Add@12' as ImageList_Add:dword
    extrn '__imp__ImageList_AddIcon@8' as ImageList_AddIcon:dword
    extrn '__imp__ImageList_AddMasked@12' as ImageList_AddMasked:dword
    extrn '__imp__ImageList_BeginDrag@16' as ImageList_BeginDrag:dword
    extrn '__imp__ImageList_Copy@20' as ImageList_Copy:dword
    extrn '__imp__ImageList_Create@20' as ImageList_Create:dword
    extrn '__imp__ImageList_Destroy@4' as ImageList_Destroy:dword
    extrn '__imp__ImageList_DragEnter@12' as ImageList_DragEnter:dword
    extrn '__imp__ImageList_DragLeave@4' as ImageList_DragLeave:dword
    extrn '__imp__ImageList_DragMove@8' as ImageList_DragMove:dword
    extrn '__imp__ImageList_DragShowNolock@4' as ImageList_DragShowNolock:dword
    extrn '__imp__ImageList_Draw@24' as ImageList_Draw:dword
    extrn '__imp__ImageList_DrawEx@40' as ImageList_DrawEx:dword
    extrn '__imp__ImageList_DrawIndirect@4' as ImageList_DrawIndirect:dword
    extrn '__imp__ImageList_Duplicate@4' as ImageList_Duplicate:dword
    extrn '__imp__ImageList_EndDrag@0' as ImageList_EndDrag:dword
    extrn '__imp__ImageList_GetBkColor@4' as ImageList_GetBkColor:dword
    extrn '__imp__ImageList_GetDragImage@8' as ImageList_GetDragImage:dword
    ;extrn '__imp__ImageList_GetFlags@4' as ImageList_GetFlags:dword    ;Not present in MASM32 comctl32.lib
    extrn '__imp__ImageList_GetIcon@12' as ImageList_GetIcon:dword
    extrn '__imp__ImageList_GetIconSize@12' as ImageList_GetIconSize:dword
    extrn '__imp__ImageList_GetImageCount@4' as ImageList_GetImageCount:dword
    extrn '__imp__ImageList_GetImageInfo@12' as ImageList_GetImageInfo:dword
    extrn '__imp__ImageList_GetImageRect@12' as ImageList_GetImageRect:dword
    extrn '__imp__ImageList_LoadImageA@28' as ImageList_LoadImageA:dword
    extrn '__imp__ImageList_LoadImageW@28' as ImageList_LoadImageW:dword
    extrn '__imp__ImageList_Merge@24' as ImageList_Merge:dword
    extrn '__imp__ImageList_Read@4' as ImageList_Read:dword
    extrn '__imp__ImageList_Remove@8' as ImageList_Remove:dword
    extrn '__imp__ImageList_Replace@16' as ImageList_Replace:dword
    extrn '__imp__ImageList_ReplaceIcon@12' as ImageList_ReplaceIcon:dword
    extrn '__imp__ImageList_SetBkColor@8' as ImageList_SetBkColor:dword
    extrn '__imp__ImageList_SetDragCursorImage@16' as ImageList_SetDragCursorImage:dword
    extrn '__imp__ImageList_SetFilter@12' as ImageList_SetFilter:dword
    extrn '__imp__ImageList_SetFlags@8' as ImageList_SetFlags:dword
    extrn '__imp__ImageList_SetIconSize@12' as ImageList_SetIconSize:dword
    extrn '__imp__ImageList_SetImageCount@8' as ImageList_SetImageCount:dword
    extrn '__imp__ImageList_SetOverlayImage@12' as ImageList_SetOverlayImage:dword
    extrn '__imp__ImageList_Write@8' as ImageList_Write:dword
    extrn '__imp__InitCommonControls@0' as InitCommonControls:dword
    extrn '__imp__InitCommonControlsEx@4' as InitCommonControlsEx:dword
    extrn '__imp__InitializeFlatSB@4' as InitializeFlatSB:dword
    extrn '__imp__InitMUILanguage@4' as InitMUILanguage:dword
    extrn '__imp__LBItemFromPt@16' as LBItemFromPt:dword
    extrn '__imp__MakeDragList@4' as MakeDragList:dword
    extrn '__imp__MenuHelp@28' as MenuHelp:dword
    extrn '__imp__PropertySheetA@4' as PropertySheetA:dword
    extrn '__imp__PropertySheetW@4' as PropertySheetW:dword
    extrn '__imp__ShowHideMenuCtl@12' as ShowHideMenuCtl:dword
    extrn '__imp__UninitializeFlatSB@4' as UninitializeFlatSB:dword
    extrn '__imp___TrackMouseEvent@4' as _TrackMouseEvent:dword

    if (NTDDI_VERSION >= NTDDI_WINXP)
        extrn '__imp__AddMRUStringW@8' as AddMRUStringW:dword
        extrn '__imp__CreateMRUListW@4' as CreateMRUListW:dword
        extrn '__imp__DefSubclassProc@16' as DefSubclassProc:dword
        extrn '__imp__DPA_Create@4' as DPA_Create:dword
        extrn '__imp__DPA_DeleteAllPtrs@4' as DPA_DeleteAllPtrs:dword
        extrn '__imp__DPA_DeletePtr@12' as DPA_DeletePtr:dword
        extrn '__imp__DPA_Destroy@4' as DPA_Destroy:dword
        extrn '__imp__DPA_DestroyCallback@12' as DPA_DestroyCallback:dword
        extrn '__imp__DPA_EnumCallback@12' as DPA_EnumCallback:dword
        extrn '__imp__DPA_GetPtr@8' as DPA_GetPtr:dword
        extrn '__imp__DPA_InsertPtr@12' as DPA_InsertPtr:dword
        extrn '__imp__DPA_Search@24' as DPA_Search:dword
        extrn '__imp__DPA_SetPtr@12' as DPA_SetPtr:dword
        extrn '__imp__DPA_Sort@12' as DPA_Sort:dword
        extrn '__imp__DSA_Create@8' as DSA_Create:dword
        extrn '__imp__DSA_DeleteAllItems@4' as DSA_DeleteAllItems:dword
        extrn '__imp__DSA_Destroy@4' as DSA_Destroy:dword
        extrn '__imp__DSA_DestroyCallback@12' as DSA_DestroyCallback:dword
        extrn '__imp__DSA_GetItemPtr@8' as DSA_GetItemPtr:dword
        extrn '__imp__DSA_InsertItem@12' as DSA_InsertItem:dword
        extrn '__imp__EnumMRUListW@16' as EnumMRUListW:dword
        extrn '__imp__FlatSB_GetScrollPropPtr@12' as FlatSB_GetScrollPropPtr:dword
        extrn '__imp__FreeMRUList@4' as FreeMRUList:dword
        extrn '__imp__RegisterClassNameW@4' as RegisterClassNameW:dword
        extrn '__imp__RemoveWindowSubclass@12' as RemoveWindowSubclass:dword
        extrn '__imp__SetWindowSubclass@16' as SetWindowSubclass:dword
    end if

    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__DPA_Clone@8' as DPA_Clone:dword
        extrn '__imp__DPA_CreateEx@8' as DPA_CreateEx:dword
        extrn '__imp__DPA_GetPtrIndex@8' as DPA_GetPtrIndex:dword
        extrn '__imp__DPA_Grow@8' as DPA_Grow:dword
        extrn '__imp__DPA_LoadStream@16' as DPA_LoadStream:dword
        extrn '__imp__DPA_Merge@24' as DPA_Merge:dword
        extrn '__imp__DPA_SaveStream@16' as DPA_SaveStream:dword
        extrn '__imp__DSA_DeleteItem@8' as DSA_DeleteItem:dword
        extrn '__imp__DSA_EnumCallback@12' as DSA_EnumCallback:dword
        extrn '__imp__DSA_GetItem@12' as DSA_GetItem:dword
        extrn '__imp__DSA_SetItem@12' as DSA_SetItem:dword
        extrn '__imp__Str_SetPtrA@8' as Str_SetPtrA:dword
        extrn '__imp__Str_SetPtrW@8' as Str_SetPtrW:dword
        api Str_SetPtr
    end if

    api CreatePropertySheetPage,\
        CreateStatusWindow,\
        DrawStatusText,\
        ImageList_LoadImage,\
        PropertySheet
end if

;======================= Undocumented functions (unknown arguments) =======================;
;if defined APP_WIN64
;    extrn '__imp_CreateToolbar' as CreateToolbar:qword
;else
;    extrn '__imp_CreateToolbar@??' as CreateToolbar:dword
;end if

end if ;COMCTL32_INC
