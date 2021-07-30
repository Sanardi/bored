; ====================================================;
;                                                     ;
;      user32.inc for EC v2 Fasm visual projects      ;
;                   (version 1.0.1)                   ;
;                                                     ;
;         Copyright © Ramon Sala - 2018-2020          ;
;                                                     ;
; ====================================================;

if  ~defined USER32_INC
define USER32_INC 1

if ~defined WM_DPICHANGED
    WM_DPICHANGED equ 02E0H
end if

if defined APP_WIN64
    extrn '__imp_ActivateKeyboardLayout' as ActivateKeyboardLayout:qword
    extrn '__imp_AdjustWindowRect' as AdjustWindowRect:qword
    extrn '__imp_AdjustWindowRectEx' as AdjustWindowRectEx:qword
    extrn '__imp_AnyPopup' as AnyPopup:qword
    extrn '__imp_AppendMenuA' as AppendMenuA:qword
    extrn '__imp_AppendMenuW' as AppendMenuW:qword
    extrn '__imp_ArrangeIconicWindows' as ArrangeIconicWindows:qword
    extrn '__imp_AttachThreadInput' as AttachThreadInput:qword
    extrn '__imp_BeginDeferWindowPos' as BeginDeferWindowPos:qword
    extrn '__imp_BeginPaint' as BeginPaint:qword
    extrn '__imp_BringWindowToTop' as BringWindowToTop:qword
    extrn '__imp_BroadcastSystemMessageA' as BroadcastSystemMessageA:qword
    extrn '__imp_BroadcastSystemMessageW' as BroadcastSystemMessageW:qword
    extrn '__imp_GetAltTabInfoA' as GetAltTabInfoA:qword
    extrn '__imp_GetAltTabInfoW' as GetAltTabInfoW:qword
    api BroadcastSystemMessage,\
        GetAltTabInfo
    if (NTDDI_VERSION > NTDDI_WIN98_ME)
        extrn '__imp_RealGetWindowClassA' as RealGetWindowClassA:qword
        extrn '__imp_RealGetWindowClassW' as RealGetWindowClassW:qword
        api RealGetWindowClass
    end if
    extrn '__imp_CallMsgFilter' as CallMsgFilter:qword
    extrn '__imp_CallMsgFilterA' as CallMsgFilterA:qword
    extrn '__imp_CallMsgFilterW' as CallMsgFilterW:qword
    extrn '__imp_CallNextHookEx' as CallNextHookEx:qword
    extrn '__imp_CallWindowProcA' as CallWindowProcA:qword
    extrn '__imp_CallWindowProcW' as CallWindowProcW:qword
    extrn '__imp_CascadeChildWindows' as CascadeChildWindows:qword
    extrn '__imp_CascadeWindows' as CascadeWindows:qword
    extrn '__imp_ChangeClipboardChain' as ChangeClipboardChain:qword
    extrn '__imp_ChangeDisplaySettingsA' as ChangeDisplaySettingsA:qword
    extrn '__imp_ChangeDisplaySettingsW' as ChangeDisplaySettingsW:qword
    extrn '__imp_ChangeMenuA' as ChangeMenuA:qword
    extrn '__imp_ChangeMenuW' as ChangeMenuW:qword
    extrn '__imp_CharLowerA' as CharLowerA:qword
    extrn '__imp_CharLowerBuffA' as CharLowerBuffA:qword
    extrn '__imp_CharLowerBuffW' as CharLowerBuffW:qword
    extrn '__imp_CharLowerW' as CharLowerW:qword
    extrn '__imp_CharNextA' as CharNextA:qword
    extrn '__imp_CharNextExA' as CharNextExA:qword
    extrn '__imp_CharNextW' as CharNextW:qword
    extrn '__imp_CharPrevA' as CharPrevA:qword
    extrn '__imp_CharPrevExA' as CharPrevExA:qword
    extrn '__imp_CharPrevW' as CharPrevW:qword
    extrn '__imp_CharToOemA' as CharToOemA:qword
    extrn '__imp_CharToOemBuffA' as CharToOemBuffA:qword
    extrn '__imp_CharToOemBuffW' as CharToOemBuffW:qword
    extrn '__imp_CharToOemW' as CharToOemW:qword
    extrn '__imp_CharUpperA' as CharUpperA:qword
    extrn '__imp_CharUpperBuffA' as CharUpperBuffA:qword
    extrn '__imp_CharUpperBuffW' as CharUpperBuffW:qword
    extrn '__imp_CharUpperW' as CharUpperW:qword
    extrn '__imp_CheckDlgButton' as CheckDlgButton:qword
    extrn '__imp_CheckMenuItem' as CheckMenuItem:qword
    extrn '__imp_CheckMenuRadioItem' as CheckMenuRadioItem:qword
    extrn '__imp_CheckRadioButton' as CheckRadioButton:qword
    extrn '__imp_ChildWindowFromPoint' as ChildWindowFromPoint:qword
    extrn '__imp_ChildWindowFromPointEx' as ChildWindowFromPointEx:qword
    extrn '__imp_ClientToScreen' as ClientToScreen:qword
    extrn '__imp_ClipCursor' as ClipCursor:qword
    extrn '__imp_CloseClipboard' as CloseClipboard:qword
    extrn '__imp_CloseDesktop' as CloseDesktop:qword
    extrn '__imp_CloseWindow' as CloseWindow:qword
    extrn '__imp_CloseWindowStation' as CloseWindowStation:qword
    extrn '__imp_CopyAcceleratorTableA' as CopyAcceleratorTableA:qword
    extrn '__imp_CopyAcceleratorTableW' as CopyAcceleratorTableW:qword
    extrn '__imp_CopyIcon' as CopyIcon:qword
    extrn '__imp_CopyImage' as CopyImage:qword
    extrn '__imp_CopyRect' as CopyRect:qword
    extrn '__imp_CountClipboardFormats' as CountClipboardFormats:qword
    extrn '__imp_CreateAcceleratorTableA' as CreateAcceleratorTableA:qword
    extrn '__imp_CreateAcceleratorTableW' as CreateAcceleratorTableW:qword
    extrn '__imp_CreateCaret' as CreateCaret:qword
    extrn '__imp_CreateCursor' as CreateCursor:qword
    extrn '__imp_CreateDesktopA' as CreateDesktopA:qword
    extrn '__imp_CreateDesktopW' as CreateDesktopW:qword
    extrn '__imp_CreateDialogIndirectParamA' as CreateDialogIndirectParamA:qword
    extrn '__imp_CreateDialogIndirectParamW' as CreateDialogIndirectParamW:qword
    extrn '__imp_CreateDialogParamA' as CreateDialogParamA:qword
    extrn '__imp_CreateDialogParamW' as CreateDialogParamW:qword
    extrn '__imp_CreateIcon' as CreateIcon:qword
    extrn '__imp_CreateIconFromResource' as CreateIconFromResource:qword
    extrn '__imp_CreateIconFromResourceEx' as CreateIconFromResourceEx:qword
    extrn '__imp_CreateIconIndirect' as CreateIconIndirect:qword
    extrn '__imp_CreateMDIWindowA' as CreateMDIWindowA:qword
    extrn '__imp_CreateMDIWindowW' as CreateMDIWindowW:qword
    extrn '__imp_CreateMenu' as CreateMenu:qword
    extrn '__imp_CreatePopupMenu' as CreatePopupMenu:qword
    extrn '__imp_CreateWindowExA' as CreateWindowExA:qword
    extrn '__imp_CreateWindowExW' as CreateWindowExW:qword
    extrn '__imp_CreateWindowStationA' as CreateWindowStationA:qword
    extrn '__imp_CreateWindowStationW' as CreateWindowStationW:qword
    extrn '__imp_DdeAbandonTransaction' as DdeAbandonTransaction:qword
    extrn '__imp_DdeAccessData' as DdeAccessData:qword
    extrn '__imp_DdeAddData' as DdeAddData:qword
    extrn '__imp_DdeClientTransaction' as DdeClientTransaction:qword
    extrn '__imp_DdeCmpStringHandles' as DdeCmpStringHandles:qword
    extrn '__imp_DdeConnect' as DdeConnect:qword
    extrn '__imp_DdeConnectList' as DdeConnectList:qword
    extrn '__imp_DdeCreateDataHandle' as DdeCreateDataHandle:qword
    extrn '__imp_DdeCreateStringHandleA' as DdeCreateStringHandleA:qword
    extrn '__imp_DdeCreateStringHandleW' as DdeCreateStringHandleW:qword
    extrn '__imp_DdeDisconnect' as DdeDisconnect:qword
    extrn '__imp_DdeDisconnectList' as DdeDisconnectList:qword
    extrn '__imp_DdeEnableCallback' as DdeEnableCallback:qword
    extrn '__imp_DdeFreeDataHandle' as DdeFreeDataHandle:qword
    extrn '__imp_DdeFreeStringHandle' as DdeFreeStringHandle:qword
    extrn '__imp_DdeGetData' as DdeGetData:qword
    extrn '__imp_DdeGetLastError' as DdeGetLastError:qword
    extrn '__imp_DdeImpersonateClient' as DdeImpersonateClient:qword
    extrn '__imp_DdeInitializeA' as DdeInitializeA:qword
    extrn '__imp_DdeInitializeW' as DdeInitializeW:qword
    extrn '__imp_DdeKeepStringHandle' as DdeKeepStringHandle:qword
    extrn '__imp_DdeNameService' as DdeNameService:qword
    extrn '__imp_DdePostAdvise' as DdePostAdvise:qword
    extrn '__imp_DdeQueryConvInfo' as DdeQueryConvInfo:qword
    extrn '__imp_DdeQueryNextServer' as DdeQueryNextServer:qword
    extrn '__imp_DdeQueryStringA' as DdeQueryStringA:qword
    extrn '__imp_DdeQueryStringW' as DdeQueryStringW:qword
    extrn '__imp_DdeReconnect' as DdeReconnect:qword
    extrn '__imp_DdeSetQualityOfService' as DdeSetQualityOfService:qword
    extrn '__imp_DdeSetUserHandle' as DdeSetUserHandle:qword
    extrn '__imp_DdeUnaccessData' as DdeUnaccessData:qword
    extrn '__imp_DdeUninitialize' as DdeUninitialize:qword
    extrn '__imp_DefDlgProcA' as DefDlgProcA:qword
    extrn '__imp_DefDlgProcW' as DefDlgProcW:qword
    extrn '__imp_DeferWindowPos' as DeferWindowPos:qword
    extrn '__imp_DefFrameProcA' as DefFrameProcA:qword
    extrn '__imp_DefFrameProcW' as DefFrameProcW:qword
    extrn '__imp_DefMDIChildProcA' as DefMDIChildProcA:qword
    extrn '__imp_DefMDIChildProcW' as DefMDIChildProcW:qword
    extrn '__imp_DefWindowProcA' as DefWindowProcA:qword
    extrn '__imp_DefWindowProcW' as DefWindowProcW:qword
    extrn '__imp_DeleteMenu' as DeleteMenu:qword
    extrn '__imp_DestroyAcceleratorTable' as DestroyAcceleratorTable:qword
    extrn '__imp_DestroyCaret' as DestroyCaret:qword
    extrn '__imp_DestroyCursor' as DestroyCursor:qword
    extrn '__imp_DestroyIcon' as DestroyIcon:qword
    extrn '__imp_DestroyMenu' as DestroyMenu:qword
    extrn '__imp_DestroyWindow' as DestroyWindow:qword
    extrn '__imp_DialogBoxIndirectParamA' as DialogBoxIndirectParamA:qword
    extrn '__imp_DialogBoxIndirectParamW' as DialogBoxIndirectParamW:qword
    extrn '__imp_DialogBoxParamA' as DialogBoxParamA:qword
    extrn '__imp_DialogBoxParamW' as DialogBoxParamW:qword
    extrn '__imp_DispatchMessageA' as DispatchMessageA:qword
    extrn '__imp_DispatchMessageW' as DispatchMessageW:qword
    extrn '__imp_DlgDirListA' as DlgDirListA:qword
    extrn '__imp_DlgDirListComboBoxA' as DlgDirListComboBoxA:qword
    extrn '__imp_DlgDirListComboBoxW' as DlgDirListComboBoxW:qword
    extrn '__imp_DlgDirListW' as DlgDirListW:qword
    extrn '__imp_DlgDirSelectComboBoxExA' as DlgDirSelectComboBoxExA:qword
    extrn '__imp_DlgDirSelectComboBoxExW' as DlgDirSelectComboBoxExW:qword
    extrn '__imp_DlgDirSelectExA' as DlgDirSelectExA:qword
    extrn '__imp_DlgDirSelectExW' as DlgDirSelectExW:qword
    extrn '__imp_DragDetect' as DragDetect:qword
    extrn '__imp_DragObject' as DragObject:qword
    extrn '__imp_DrawAnimatedRects' as DrawAnimatedRects:qword
    extrn '__imp_DrawCaption' as DrawCaption:qword
    extrn '__imp_DrawCaptionTempA' as DrawCaptionTempA:qword
    extrn '__imp_DrawCaptionTempW' as DrawCaptionTempW:qword
    extrn '__imp_DrawEdge' as DrawEdge:qword
    extrn '__imp_DrawFocusRect' as DrawFocusRect:qword
    extrn '__imp_DrawFrame' as DrawFrame:qword
    extrn '__imp_DrawFrameControl' as DrawFrameControl:qword
    extrn '__imp_DrawIcon' as DrawIcon:qword
    extrn '__imp_DrawIconEx' as DrawIconEx:qword
    extrn '__imp_DrawMenuBar' as DrawMenuBar:qword
    extrn '__imp_DrawStateA' as DrawStateA:qword
    extrn '__imp_DrawStateW' as DrawStateW:qword
    extrn '__imp_DrawTextA' as DrawTextA:qword
    extrn '__imp_DrawTextExA' as DrawTextExA:qword
    extrn '__imp_DrawTextExW' as DrawTextExW:qword
    extrn '__imp_DrawTextW' as DrawTextW:qword
    extrn '__imp_EditWndProc' as EditWndProc:qword
    extrn '__imp_EmptyClipboard' as EmptyClipboard:qword
    extrn '__imp_EnableMenuItem' as EnableMenuItem:qword
    extrn '__imp_EnableScrollBar' as EnableScrollBar:qword
    extrn '__imp_EnableWindow' as EnableWindow:qword
    extrn '__imp_EndDeferWindowPos' as EndDeferWindowPos:qword
    extrn '__imp_EndDialog' as EndDialog:qword
    extrn '__imp_EndPaint' as EndPaint:qword
    extrn '__imp_EndTask' as EndTask:qword
    extrn '__imp_EnumChildWindows' as EnumChildWindows:qword
    extrn '__imp_EnumClipboardFormats' as EnumClipboardFormats:qword
    extrn '__imp_EnumDesktopsA' as EnumDesktopsA:qword
    extrn '__imp_EnumDesktopsW' as EnumDesktopsW:qword
    extrn '__imp_EnumDesktopWindows' as EnumDesktopWindows:qword
    extrn '__imp_EnumDisplayDevicesA' as EnumDisplayDevicesA:qword
    extrn '__imp_EnumDisplayDevicesW' as EnumDisplayDevicesW:qword
    extrn '__imp_EnumDisplaySettingsA' as EnumDisplaySettingsA:qword
    extrn '__imp_EnumDisplaySettingsW' as EnumDisplaySettingsW:qword
    extrn '__imp_EnumPropsA' as EnumPropsA:qword
    extrn '__imp_EnumPropsExA' as EnumPropsExA:qword
    extrn '__imp_EnumPropsExW' as EnumPropsExW:qword
    extrn '__imp_EnumPropsW' as EnumPropsW:qword
    extrn '__imp_EnumThreadWindows' as EnumThreadWindows:qword
    extrn '__imp_EnumWindows' as EnumWindows:qword
    extrn '__imp_EnumWindowStationsA' as EnumWindowStationsA:qword
    extrn '__imp_EnumWindowStationsW' as EnumWindowStationsW:qword
    extrn '__imp_EqualRect' as EqualRect:qword
    extrn '__imp_ExcludeUpdateRgn' as ExcludeUpdateRgn:qword
    extrn '__imp_ExitWindowsEx' as ExitWindowsEx:qword
    extrn '__imp_FillRect' as FillRect:qword
    extrn '__imp_FindWindowA' as FindWindowA:qword
    extrn '__imp_FindWindowExA' as FindWindowExA:qword
    extrn '__imp_FindWindowExW' as FindWindowExW:qword
    extrn '__imp_FindWindowW' as FindWindowW:qword
    extrn '__imp_FlashWindow' as FlashWindow:qword
    extrn '__imp_FrameRect' as FrameRect:qword
    extrn '__imp_FreeDDElParam' as FreeDDElParam:qword
    extrn '__imp_GetActiveWindow' as GetActiveWindow:qword
    extrn '__imp_GetAsyncKeyState' as GetAsyncKeyState:qword
    extrn '__imp_GetCapture' as GetCapture:qword
    extrn '__imp_GetCaretBlinkTime' as GetCaretBlinkTime:qword
    extrn '__imp_GetCaretPos' as GetCaretPos:qword
    extrn '__imp_GetClassInfoA' as GetClassInfoA:qword
    extrn '__imp_GetClassInfoExA' as GetClassInfoExA:qword
    extrn '__imp_GetClassInfoExW' as GetClassInfoExW:qword
    extrn '__imp_GetClassInfoW' as GetClassInfoW:qword
    extrn '__imp_GetClassLongA' as GetClassLongA:qword
    extrn '__imp_GetClassLongW' as GetClassLongW:qword
    extrn '__imp_GetClassNameA' as GetClassNameA:qword
    extrn '__imp_GetClassNameW' as GetClassNameW:qword
    extrn '__imp_GetClassWord' as GetClassWord:qword
    extrn '__imp_GetClientRect' as GetClientRect:qword
    extrn '__imp_GetClipboardData' as GetClipboardData:qword
    extrn '__imp_GetClipboardFormatNameA' as GetClipboardFormatNameA:qword
    extrn '__imp_GetClipboardFormatNameW' as GetClipboardFormatNameW:qword
    extrn '__imp_GetClipboardOwner' as GetClipboardOwner:qword
    extrn '__imp_GetClipboardViewer' as GetClipboardViewer:qword
    extrn '__imp_GetClipCursor' as GetClipCursor:qword
    extrn '__imp_GetCursor' as GetCursor:qword
    extrn '__imp_GetCursorPos' as GetCursorPos:qword
    extrn '__imp_GetDC' as GetDC:qword
    extrn '__imp_GetDCEx' as GetDCEx:qword
    extrn '__imp_GetDesktopWindow' as GetDesktopWindow:qword
    extrn '__imp_GetDialogBaseUnits' as GetDialogBaseUnits:qword
    extrn '__imp_GetDlgCtrlID' as GetDlgCtrlID:qword
    extrn '__imp_GetDlgItem' as GetDlgItem:qword
    extrn '__imp_GetDlgItemInt' as GetDlgItemInt:qword
    extrn '__imp_GetDlgItemTextA' as GetDlgItemTextA:qword
    extrn '__imp_GetDlgItemTextW' as GetDlgItemTextW:qword
    extrn '__imp_GetDoubleClickTime' as GetDoubleClickTime:qword
    extrn '__imp_GetFocus' as GetFocus:qword
    extrn '__imp_GetForegroundWindow' as GetForegroundWindow:qword
    if (NTDDI_VERSION <> NTDDI_WIN95 & NTDDI_VERSION <> NTDDI_WINNT4)
        extrn '__imp_GetGuiResources' as GetGuiResources:qword
    end if
    extrn '__imp_GetIconInfo' as GetIconInfo:qword
    extrn '__imp_GetInputDesktop' as GetInputDesktop:qword
    extrn '__imp_GetInputState' as GetInputState:qword
    extrn '__imp_GetInternalWindowPos' as GetInternalWindowPos:qword
    extrn '__imp_GetKBCodePage' as GetKBCodePage:qword
    extrn '__imp_GetKeyboardLayout' as GetKeyboardLayout:qword
    extrn '__imp_GetKeyboardLayoutList' as GetKeyboardLayoutList:qword
    extrn '__imp_GetKeyboardLayoutNameA' as GetKeyboardLayoutNameA:qword
    extrn '__imp_GetKeyboardLayoutNameW' as GetKeyboardLayoutNameW:qword
    extrn '__imp_GetKeyboardState' as GetKeyboardState:qword
    extrn '__imp_GetKeyboardType' as GetKeyboardType:qword
    extrn '__imp_GetKeyNameTextA' as GetKeyNameTextA:qword
    extrn '__imp_GetKeyNameTextW' as GetKeyNameTextW:qword
    extrn '__imp_GetKeyState' as GetKeyState:qword
    extrn '__imp_GetLastActivePopup' as GetLastActivePopup:qword
    extrn '__imp_GetMenu' as GetMenu:qword
    extrn '__imp_GetMenuCheckMarkDimensions' as GetMenuCheckMarkDimensions:qword
    extrn '__imp_GetMenuContextHelpId' as GetMenuContextHelpId:qword
    extrn '__imp_GetMenuDefaultItem' as GetMenuDefaultItem:qword
    extrn '__imp_GetMenuItemCount' as GetMenuItemCount:qword
    extrn '__imp_GetMenuItemID' as GetMenuItemID:qword
    extrn '__imp_GetMenuItemInfoA' as GetMenuItemInfoA:qword
    extrn '__imp_GetMenuItemInfoW' as GetMenuItemInfoW:qword
    extrn '__imp_GetMenuItemRect' as GetMenuItemRect:qword
    extrn '__imp_GetMenuState' as GetMenuState:qword
    extrn '__imp_GetMenuStringA' as GetMenuStringA:qword
    extrn '__imp_GetMenuStringW' as GetMenuStringW:qword
    extrn '__imp_GetMessageA' as GetMessageA:qword
    extrn '__imp_GetMessageExtraInfo' as GetMessageExtraInfo:qword
    extrn '__imp_GetMessagePos' as GetMessagePos:qword
    extrn '__imp_GetMessageTime' as GetMessageTime:qword
    extrn '__imp_GetMessageW' as GetMessageW:qword
    extrn '__imp_GetNextDlgGroupItem' as GetNextDlgGroupItem:qword
    extrn '__imp_GetNextDlgTabItem' as GetNextDlgTabItem:qword
    extrn '__imp_GetOpenClipboardWindow' as GetOpenClipboardWindow:qword
    extrn '__imp_GetParent' as GetParent:qword
    extrn '__imp_GetPriorityClipboardFormat' as GetPriorityClipboardFormat:qword
    extrn '__imp_GetProcessWindowStation' as GetProcessWindowStation:qword
    extrn '__imp_GetPropA' as GetPropA:qword
    extrn '__imp_GetPropW' as GetPropW:qword
    extrn '__imp_GetQueueStatus' as GetQueueStatus:qword
    extrn '__imp_GetScrollInfo' as GetScrollInfo:qword
    extrn '__imp_GetScrollPos' as GetScrollPos:qword
    extrn '__imp_GetScrollRange' as GetScrollRange:qword
    extrn '__imp_GetShellWindow' as GetShellWindow:qword
    extrn '__imp_GetSubMenu' as GetSubMenu:qword
    extrn '__imp_GetSysColor' as GetSysColor:qword
    extrn '__imp_GetSysColorBrush' as GetSysColorBrush:qword
    extrn '__imp_GetSystemMenu' as GetSystemMenu:qword
    extrn '__imp_GetSystemMetrics' as GetSystemMetrics:qword
    extrn '__imp_GetTabbedTextExtentA' as GetTabbedTextExtentA:qword
    extrn '__imp_GetTabbedTextExtentW' as GetTabbedTextExtentW:qword
    extrn '__imp_GetThreadDesktop' as GetThreadDesktop:qword
    extrn '__imp_GetTopWindow' as GetTopWindow:qword
    extrn '__imp_GetUpdateRect' as GetUpdateRect:qword
    extrn '__imp_GetUpdateRgn' as GetUpdateRgn:qword
    extrn '__imp_GetUserObjectInformationA' as GetUserObjectInformationA:qword
    extrn '__imp_GetUserObjectInformationW' as GetUserObjectInformationW:qword
    extrn '__imp_GetUserObjectSecurity' as GetUserObjectSecurity:qword
    extrn '__imp_GetWindow' as GetWindow:qword
    extrn '__imp_GetWindowContextHelpId' as GetWindowContextHelpId:qword
    extrn '__imp_GetWindowDC' as GetWindowDC:qword
    extrn '__imp_GetWindowLongA' as GetWindowLongA:qword
    extrn '__imp_GetWindowLongW' as GetWindowLongW:qword
    extrn '__imp_GetWindowPlacement' as GetWindowPlacement:qword
    extrn '__imp_GetWindowRect' as GetWindowRect:qword
    extrn '__imp_GetWindowRgn' as GetWindowRgn:qword
    extrn '__imp_GetWindowTextA' as GetWindowTextA:qword
    extrn '__imp_GetWindowTextLengthA' as GetWindowTextLengthA:qword
    extrn '__imp_GetWindowTextLengthW' as GetWindowTextLengthW:qword
    extrn '__imp_GetWindowTextW' as GetWindowTextW:qword
    extrn '__imp_GetWindowThreadProcessId' as GetWindowThreadProcessId:qword
    extrn '__imp_GetWindowWord' as GetWindowWord:qword
    extrn '__imp_GrayStringA' as GrayStringA:qword
    extrn '__imp_GrayStringW' as GrayStringW:qword
    extrn '__imp_HideCaret' as HideCaret:qword
    extrn '__imp_HiliteMenuItem' as HiliteMenuItem:qword
    extrn '__imp_ImpersonateDdeClientWindow' as ImpersonateDdeClientWindow:qword
    extrn '__imp_InflateRect' as InflateRect:qword
    extrn '__imp_InSendMessage' as InSendMessage:qword
    extrn '__imp_InsertMenuA' as InsertMenuA:qword
    extrn '__imp_InsertMenuItemA' as InsertMenuItemA:qword
    extrn '__imp_InsertMenuItemW' as InsertMenuItemW:qword
    extrn '__imp_InsertMenuW' as InsertMenuW:qword
    extrn '__imp_InternalGetWindowText' as InternalGetWindowText:qword
    extrn '__imp_IntersectRect' as IntersectRect:qword
    extrn '__imp_InvalidateRect' as InvalidateRect:qword
    extrn '__imp_InvalidateRgn' as InvalidateRgn:qword
    extrn '__imp_InvertRect' as InvertRect:qword
    extrn '__imp_IsCharAlphaA' as IsCharAlphaA:qword
    extrn '__imp_IsCharAlphaNumericA' as IsCharAlphaNumericA:qword
    extrn '__imp_IsCharAlphaNumericW' as IsCharAlphaNumericW:qword
    extrn '__imp_IsCharAlphaW' as IsCharAlphaW:qword
    extrn '__imp_IsCharLowerA' as IsCharLowerA:qword
    extrn '__imp_IsCharLowerW' as IsCharLowerW:qword
    extrn '__imp_IsCharUpperA' as IsCharUpperA:qword
    extrn '__imp_IsCharUpperW' as IsCharUpperW:qword
    extrn '__imp_IsChild' as IsChild:qword
    extrn '__imp_IsClipboardFormatAvailable' as IsClipboardFormatAvailable:qword
    extrn '__imp_IsDialogMessage' as IsDialogMessage:qword
    extrn '__imp_IsDialogMessageA' as IsDialogMessageA:qword
    extrn '__imp_IsDialogMessageW' as IsDialogMessageW:qword
    extrn '__imp_IsDlgButtonChecked' as IsDlgButtonChecked:qword
    extrn '__imp_IsIconic' as IsIconic:qword
    extrn '__imp_IsMenu' as IsMenu:qword
    extrn '__imp_IsRectEmpty' as IsRectEmpty:qword
    extrn '__imp_IsWindow' as IsWindow:qword
    extrn '__imp_IsWindowEnabled' as IsWindowEnabled:qword
    extrn '__imp_IsWindowUnicode' as IsWindowUnicode:qword
    extrn '__imp_IsWindowVisible' as IsWindowVisible:qword
    extrn '__imp_IsZoomed' as IsZoomed:qword
    extrn '__imp_KillTimer' as KillTimer:qword
    extrn '__imp_LoadAcceleratorsA' as LoadAcceleratorsA:qword
    extrn '__imp_LoadAcceleratorsW' as LoadAcceleratorsW:qword
    extrn '__imp_LoadBitmapA' as LoadBitmapA:qword
    extrn '__imp_LoadBitmapW' as LoadBitmapW:qword
    extrn '__imp_LoadCursorA' as LoadCursorA:qword
    extrn '__imp_LoadCursorFromFileA' as LoadCursorFromFileA:qword
    extrn '__imp_LoadCursorFromFileW' as LoadCursorFromFileW:qword
    extrn '__imp_LoadCursorW' as LoadCursorW:qword
    extrn '__imp_LoadIconA' as LoadIconA:qword
    extrn '__imp_LoadIconW' as LoadIconW:qword
    extrn '__imp_LoadImageA' as LoadImageA:qword
    extrn '__imp_LoadImageW' as LoadImageW:qword
    extrn '__imp_LoadKeyboardLayoutA' as LoadKeyboardLayoutA:qword
    extrn '__imp_LoadKeyboardLayoutW' as LoadKeyboardLayoutW:qword
    extrn '__imp_LoadMenuA' as LoadMenuA:qword
    extrn '__imp_LoadMenuIndirectA' as LoadMenuIndirectA:qword
    extrn '__imp_LoadMenuIndirectW' as LoadMenuIndirectW:qword
    extrn '__imp_LoadMenuW' as LoadMenuW:qword
    extrn '__imp_LoadStringA' as LoadStringA:qword
    extrn '__imp_LoadStringW' as LoadStringW:qword
    extrn '__imp_LockWindowStation' as LockWindowStation:qword
    extrn '__imp_LockWindowUpdate' as LockWindowUpdate:qword
    extrn '__imp_LookupIconIdFromDirectory' as LookupIconIdFromDirectory:qword
    extrn '__imp_LookupIconIdFromDirectoryEx' as LookupIconIdFromDirectoryEx:qword
    extrn '__imp_MapDialogRect' as MapDialogRect:qword
    extrn '__imp_MapVirtualKeyA' as MapVirtualKeyA:qword
    extrn '__imp_MapVirtualKeyExA' as MapVirtualKeyExA:qword
    extrn '__imp_MapVirtualKeyExW' as MapVirtualKeyExW:qword
    extrn '__imp_MapVirtualKeyW' as MapVirtualKeyW:qword
    extrn '__imp_MapWindowPoints' as MapWindowPoints:qword
    extrn '__imp_MenuItemFromPoint' as MenuItemFromPoint:qword
    extrn '__imp_MessageBeep' as MessageBeep:qword
    extrn '__imp_MessageBoxA' as MessageBoxA:qword
    extrn '__imp_MessageBoxExA' as MessageBoxExA:qword
    extrn '__imp_MessageBoxExW' as MessageBoxExW:qword
    extrn '__imp_MessageBoxIndirectA' as MessageBoxIndirectA:qword
    extrn '__imp_MessageBoxIndirectW' as MessageBoxIndirectW:qword
    extrn '__imp_MessageBoxW' as MessageBoxW:qword
    extrn '__imp_ModifyMenuA' as ModifyMenuA:qword
    extrn '__imp_ModifyMenuW' as ModifyMenuW:qword
    extrn '__imp_MoveWindow' as MoveWindow:qword
    extrn '__imp_MsgWaitForMultipleObjects' as MsgWaitForMultipleObjects:qword
    extrn '__imp_OemKeyScan' as OemKeyScan:qword
    extrn '__imp_OemToCharA' as OemToCharA:qword
    extrn '__imp_OemToCharBuffA' as OemToCharBuffA:qword
    extrn '__imp_OemToCharBuffW' as OemToCharBuffW:qword
    extrn '__imp_OemToCharW' as OemToCharW:qword
    extrn '__imp_OffsetRect' as OffsetRect:qword
    extrn '__imp_OpenClipboard' as OpenClipboard:qword
    extrn '__imp_OpenDesktopA' as OpenDesktopA:qword
    extrn '__imp_OpenDesktopW' as OpenDesktopW:qword
    extrn '__imp_OpenIcon' as OpenIcon:qword
    extrn '__imp_OpenInputDesktop' as OpenInputDesktop:qword
    extrn '__imp_OpenWindowStationA' as OpenWindowStationA:qword
    extrn '__imp_OpenWindowStationW' as OpenWindowStationW:qword
    extrn '__imp_PackDDElParam' as PackDDElParam:qword
    extrn '__imp_PaintDesktop' as PaintDesktop:qword
    extrn '__imp_PeekMessageA' as PeekMessageA:qword
    extrn '__imp_PeekMessageW' as PeekMessageW:qword
    extrn '__imp_PostMessageA' as PostMessageA:qword
    extrn '__imp_PostMessageW' as PostMessageW:qword
    extrn '__imp_PostQuitMessage' as PostQuitMessage:qword
    extrn '__imp_PostThreadMessageA' as PostThreadMessageA:qword
    extrn '__imp_PostThreadMessageW' as PostThreadMessageW:qword
    extrn '__imp_PtInRect' as PtInRect:qword
    extrn '__imp_RedrawWindow' as RedrawWindow:qword
    extrn '__imp_RegisterClassA' as RegisterClassA:qword
    extrn '__imp_RegisterClassExA' as RegisterClassExA:qword
    extrn '__imp_RegisterClassExW' as RegisterClassExW:qword
    extrn '__imp_RegisterClassW' as RegisterClassW:qword
    extrn '__imp_RegisterClipboardFormatA' as RegisterClipboardFormatA:qword
    extrn '__imp_RegisterClipboardFormatW' as RegisterClipboardFormatW:qword
    extrn '__imp_RegisterHotKey' as RegisterHotKey:qword
    extrn '__imp_RegisterLogonProcess' as RegisterLogonProcess:qword
    extrn '__imp_RegisterSystemThread' as RegisterSystemThread:qword
    extrn '__imp_RegisterTasklist' as RegisterTasklist:qword
    extrn '__imp_RegisterWindowMessageA' as RegisterWindowMessageA:qword
    extrn '__imp_RegisterWindowMessageW' as RegisterWindowMessageW:qword
    extrn '__imp_ReleaseCapture' as ReleaseCapture:qword
    extrn '__imp_ReleaseDC' as ReleaseDC:qword
    extrn '__imp_RemoveMenu' as RemoveMenu:qword
    extrn '__imp_RemovePropA' as RemovePropA:qword
    extrn '__imp_RemovePropW' as RemovePropW:qword
    extrn '__imp_ReplyMessage' as ReplyMessage:qword
    extrn '__imp_ReuseDDElParam' as ReuseDDElParam:qword
    extrn '__imp_ScreenToClient' as ScreenToClient:qword
    extrn '__imp_ScrollDC' as ScrollDC:qword
    extrn '__imp_ScrollWindow' as ScrollWindow:qword
    extrn '__imp_ScrollWindowEx' as ScrollWindowEx:qword
    extrn '__imp_SendDlgItemMessageA' as SendDlgItemMessageA:qword
    extrn '__imp_SendDlgItemMessageW' as SendDlgItemMessageW:qword
    extrn '__imp_SendMessageA' as SendMessageA:qword
    extrn '__imp_SendMessageCallbackA' as SendMessageCallbackA:qword
    extrn '__imp_SendMessageCallbackW' as SendMessageCallbackW:qword
    extrn '__imp_SendMessageTimeoutA' as SendMessageTimeoutA:qword
    extrn '__imp_SendMessageTimeoutW' as SendMessageTimeoutW:qword
    extrn '__imp_SendMessageW' as SendMessageW:qword
    extrn '__imp_SendNotifyMessageA' as SendNotifyMessageA:qword
    extrn '__imp_SendNotifyMessageW' as SendNotifyMessageW:qword
    extrn '__imp_SetActiveWindow' as SetActiveWindow:qword
    extrn '__imp_SetCapture' as SetCapture:qword
    extrn '__imp_SetCaretBlinkTime' as SetCaretBlinkTime:qword
    extrn '__imp_SetCaretPos' as SetCaretPos:qword
    extrn '__imp_SetClassLongA' as SetClassLongA:qword
    extrn '__imp_SetClassLongW' as SetClassLongW:qword
    extrn '__imp_SetClassWord' as SetClassWord:qword
    extrn '__imp_SetClipboardData' as SetClipboardData:qword
    extrn '__imp_SetClipboardViewer' as SetClipboardViewer:qword
    extrn '__imp_SetCursor' as SetCursor:qword
    extrn '__imp_SetCursorPos' as SetCursorPos:qword
    extrn '__imp_SetDebugErrorLevel' as SetDebugErrorLevel:qword
    extrn '__imp_SetDlgItemInt' as SetDlgItemInt:qword
    extrn '__imp_SetDlgItemTextA' as SetDlgItemTextA:qword
    extrn '__imp_SetDlgItemTextW' as SetDlgItemTextW:qword
    extrn '__imp_SetDoubleClickTime' as SetDoubleClickTime:qword
    extrn '__imp_SetFocus' as SetFocus:qword
    extrn '__imp_SetForegroundWindow' as SetForegroundWindow:qword
    extrn '__imp_SetInternalWindowPos' as SetInternalWindowPos:qword
    extrn '__imp_SetKeyboardState' as SetKeyboardState:qword
    extrn '__imp_SetLastErrorEx' as SetLastErrorEx:qword
    extrn '__imp_SetMenu' as SetMenu:qword
    extrn '__imp_SetMenuContextHelpId' as SetMenuContextHelpId:qword
    extrn '__imp_SetMenuDefaultItem' as SetMenuDefaultItem:qword
    extrn '__imp_SetMenuItemBitmaps' as SetMenuItemBitmaps:qword
    extrn '__imp_SetMenuItemInfoA' as SetMenuItemInfoA:qword
    extrn '__imp_SetMenuItemInfoW' as SetMenuItemInfoW:qword
    extrn '__imp_SetMessageExtraInfo' as SetMessageExtraInfo:qword
    extrn '__imp_SetMessageQueue' as SetMessageQueue:qword
    extrn '__imp_SetParent' as SetParent:qword
    extrn '__imp_SetProcessWindowStation' as SetProcessWindowStation:qword
    extrn '__imp_SetPropA' as SetPropA:qword
    extrn '__imp_SetPropW' as SetPropW:qword
    extrn '__imp_SetRect' as SetRect:qword
    extrn '__imp_SetRectEmpty' as SetRectEmpty:qword
    extrn '__imp_SetScrollInfo' as SetScrollInfo:qword
    extrn '__imp_SetScrollPos' as SetScrollPos:qword
    extrn '__imp_SetScrollRange' as SetScrollRange:qword
    extrn '__imp_SetShellWindow' as SetShellWindow:qword
    extrn '__imp_SetSysColors' as SetSysColors:qword
    extrn '__imp_SetSysColorsTemp' as SetSysColorsTemp:qword
    extrn '__imp_SetSystemCursor' as SetSystemCursor:qword
    extrn '__imp_SetThreadDesktop' as SetThreadDesktop:qword
    extrn '__imp_SetTimer' as SetTimer:qword
    extrn '__imp_SetUserObjectInformationA' as SetUserObjectInformationA:qword
    extrn '__imp_SetUserObjectInformationW' as SetUserObjectInformationW:qword
    extrn '__imp_SetUserObjectSecurity' as SetUserObjectSecurity:qword
    extrn '__imp_SetWindowContextHelpId' as SetWindowContextHelpId:qword
    extrn '__imp_SetWindowLongA' as SetWindowLongA:qword
    extrn '__imp_SetWindowLongW' as SetWindowLongW:qword
    extrn '__imp_SetWindowPlacement' as SetWindowPlacement:qword
    extrn '__imp_SetWindowPos' as SetWindowPos:qword
    extrn '__imp_SetWindowRgn' as SetWindowRgn:qword
    extrn '__imp_SetWindowsHookA' as SetWindowsHookA:qword
    extrn '__imp_SetWindowsHookExA' as SetWindowsHookExA:qword
    extrn '__imp_SetWindowsHookExW' as SetWindowsHookExW:qword
    extrn '__imp_SetWindowsHookW' as SetWindowsHookW:qword
    extrn '__imp_SetWindowTextA' as SetWindowTextA:qword
    extrn '__imp_SetWindowTextW' as SetWindowTextW:qword
    extrn '__imp_SetWindowWord' as SetWindowWord:qword
    extrn '__imp_ShowCaret' as ShowCaret:qword
    extrn '__imp_ShowCursor' as ShowCursor:qword
    extrn '__imp_ShowOwnedPopups' as ShowOwnedPopups:qword
    extrn '__imp_ShowScrollBar' as ShowScrollBar:qword
    extrn '__imp_ShowWindow' as ShowWindow:qword
    extrn '__imp_ShowWindowAsync' as ShowWindowAsync:qword
    extrn '__imp_SubtractRect' as SubtractRect:qword
    extrn '__imp_SwapMouseButton' as SwapMouseButton:qword
    extrn '__imp_SwitchDesktop' as SwitchDesktop:qword
    extrn '__imp_SwitchToThisWindow' as SwitchToThisWindow:qword
    extrn '__imp_SystemParametersInfoA' as SystemParametersInfoA:qword
    extrn '__imp_SystemParametersInfoW' as SystemParametersInfoW:qword
    extrn '__imp_TabbedTextOutA' as TabbedTextOutA:qword
    extrn '__imp_TabbedTextOutW' as TabbedTextOutW:qword
    extrn '__imp_TileChildWindows' as TileChildWindows:qword
    extrn '__imp_TileWindows' as TileWindows:qword
    extrn '__imp_ToAscii' as ToAscii:qword
    extrn '__imp_ToAsciiEx' as ToAsciiEx:qword
    extrn '__imp_ToUnicode' as ToUnicode:qword
    extrn '__imp_TrackPopupMenu' as TrackPopupMenu:qword
    extrn '__imp_TrackPopupMenuEx' as TrackPopupMenuEx:qword
    extrn '__imp_TranslateAccelerator' as TranslateAccelerator:qword
    extrn '__imp_TranslateAcceleratorA' as TranslateAcceleratorA:qword
    extrn '__imp_TranslateAcceleratorW' as TranslateAcceleratorW:qword
    extrn '__imp_TranslateMDISysAccel' as TranslateMDISysAccel:qword
    extrn '__imp_TranslateMessage' as TranslateMessage:qword
    extrn '__imp_UnhookWindowsHook' as UnhookWindowsHook:qword
    extrn '__imp_UnhookWindowsHookEx' as UnhookWindowsHookEx:qword
    extrn '__imp_UnionRect' as UnionRect:qword
    extrn '__imp_UnloadKeyboardLayout' as UnloadKeyboardLayout:qword
    extrn '__imp_UnlockWindowStation' as UnlockWindowStation:qword
    extrn '__imp_UnpackDDElParam' as UnpackDDElParam:qword
    extrn '__imp_UnregisterClassA' as UnregisterClassA:qword
    extrn '__imp_UnregisterClassW' as UnregisterClassW:qword
    extrn '__imp_UnregisterHotKey' as UnregisterHotKey:qword
    extrn '__imp_UpdateWindow' as UpdateWindow:qword
    extrn '__imp_ValidateRect' as ValidateRect:qword
    extrn '__imp_ValidateRgn' as ValidateRgn:qword
    extrn '__imp_VkKeyScanA' as VkKeyScanA:qword
    extrn '__imp_VkKeyScanExA' as VkKeyScanExA:qword
    extrn '__imp_VkKeyScanExW' as VkKeyScanExW:qword
    extrn '__imp_VkKeyScanW' as VkKeyScanW:qword
    extrn '__imp_WaitForInputIdle' as WaitForInputIdle:qword
    extrn '__imp_WaitMessage' as WaitMessage:qword
    extrn '__imp_WindowFromDC' as WindowFromDC:qword
    extrn '__imp_WindowFromPoint' as WindowFromPoint:qword
    extrn '__imp_WinHelpA' as WinHelpA:qword
    extrn '__imp_WinHelpW' as WinHelpW:qword
    extrn '__imp_keybd_event' as keybd_event:qword
    extrn '__imp_mouse_event' as mouse_event:qword
    extrn '__imp_wsprintfA' as wsprintfA:qword
    extrn '__imp_wsprintfW' as wsprintfW:qword
    extrn '__imp_wvsprintfA' as wvsprintfA:qword
    extrn '__imp_wvsprintfW' as wvsprintfW:qword

    if (NTDDI_VERSION <> NTDDI_WINNT4)
        extrn '__imp_UnhookWinEvent' as UnhookWinEvent:qword
        extrn '__imp_WINNLSEnableIME' as WINNLSEnableIME:qword
    end if

    if (NTDDI_VERSION >= NTDDI_WIN98_ME)
        extrn '__imp_BlockInput' as BlockInput:qword
        extrn '__imp_ChangeDisplaySettingsExA' as ChangeDisplaySettingsExA:qword
        extrn '__imp_ChangeDisplaySettingsExW' as ChangeDisplaySettingsExW:qword
        extrn '__imp_EndMenu' as EndMenu:qword
        extrn '__imp_EnumDisplayMonitors' as EnumDisplayMonitors:qword
        extrn '__imp_EnumDisplaySettingsExA' as EnumDisplaySettingsExA:qword
        extrn '__imp_EnumDisplaySettingsExW' as EnumDisplaySettingsExW:qword
        extrn '__imp_FlashWindowEx' as FlashWindowEx:qword
        extrn '__imp_GetAncestor' as GetAncestor:qword
        extrn '__imp_GetClipboardSequenceNumber' as GetClipboardSequenceNumber:qword
        extrn '__imp_GetComboBoxInfo' as GetComboBoxInfo:qword
        extrn '__imp_GetCursorInfo' as GetCursorInfo:qword
        extrn '__imp_GetGUIThreadInfo' as GetGUIThreadInfo:qword
        extrn '__imp_GetListBoxInfo' as GetListBoxInfo:qword
        extrn '__imp_GetMenuBarInfo' as GetMenuBarInfo:qword
        extrn '__imp_GetMenuInfo' as GetMenuInfo:qword
        extrn '__imp_GetProcessDefaultLayout' as GetProcessDefaultLayout:qword
        extrn '__imp_GetScrollBarInfo' as GetScrollBarInfo:qword
        extrn '__imp_GetTitleBarInfo' as GetTitleBarInfo:qword
        extrn '__imp_GetWindowInfo' as GetWindowInfo:qword
        extrn '__imp_GetWindowModuleFileName' as GetWindowModuleFileName:qword
        extrn '__imp_GetWindowModuleFileNameA' as GetWindowModuleFileNameA:qword
        extrn '__imp_GetWindowModuleFileNameW' as GetWindowModuleFileNameW:qword
        extrn '__imp_IMPGetIMEA' as IMPGetIMEA:qword
        extrn '__imp_IMPGetIMEW' as IMPGetIMEW:qword
        extrn '__imp_IMPQueryIMEA' as IMPQueryIMEA:qword
        extrn '__imp_IMPQueryIMEW' as IMPQueryIMEW:qword
        extrn '__imp_IMPSetIMEA' as IMPSetIMEA:qword
        extrn '__imp_IMPSetIMEW' as IMPSetIMEW:qword
        extrn '__imp_MsgWaitForMultipleObjectsEx' as MsgWaitForMultipleObjectsEx:qword
        extrn '__imp_NotifyWinEvent' as NotifyWinEvent:qword
        extrn '__imp_RealChildWindowFromPoint' as RealChildWindowFromPoint:qword
        extrn '__imp_SendIMEMessageExA' as SendIMEMessageExA:qword
        extrn '__imp_SendIMEMessageExW' as SendIMEMessageExW:qword
        extrn '__imp_SendInput' as SendInput:qword
        extrn '__imp_SetWinEventHook' as SetWinEventHook:qword
        extrn '__imp_ToUnicodeEx' as ToUnicodeEx:qword
        extrn '__imp_TrackMouseEvent' as TrackMouseEvent:qword

        if (NTDDI_VERSION <> NTDDI_WINNT4)
            extrn '__imp_GetMonitorInfoA' as GetMonitorInfoA:qword
            extrn '__imp_GetMonitorInfoW' as GetMonitorInfoW:qword
            extrn '__imp_InSendMessageEx' as InSendMessageEx:qword
            extrn '__imp_MonitorFromPoint' as MonitorFromPoint:qword
            extrn '__imp_MonitorFromRect' as MonitorFromRect:qword
            extrn '__imp_MonitorFromWindow' as MonitorFromWindow:qword
            extrn '__imp_RegisterDeviceNotificationA' as RegisterDeviceNotificationA:qword
            extrn '__imp_RegisterDeviceNotificationW' as RegisterDeviceNotificationW:qword
            extrn '__imp_SetMenuInfo' as SetMenuInfo:qword
            extrn '__imp_SetProcessDefaultLayout' as SetProcessDefaultLayout:qword
            extrn '__imp_UnregisterDeviceNotification' as UnregisterDeviceNotification:qword
            api GetMonitorInfo,\
                RegisterDeviceNotification
        end if

        api ChangeDisplaySettingsEx,\
            EnumDisplaySettingsEx,\
            IMPGetIME,\
            IMPQueryIME,\
            IMPSetIME,\
            SendIMEMessageEx
    end if

    if (NTDDI_VERSION >= NTDDI_WINNT4)
        extrn '__imp_ClientThreadSetup' as ClientThreadSetup:qword
        extrn '__imp_CreateDialogIndirectParamAorW' as CreateDialogIndirectParamAorW:qword
        extrn '__imp_DdeGetQualityOfService' as DdeGetQualityOfService:qword
        extrn '__imp_DeregisterShellHookWindow' as DeregisterShellHookWindow:qword
        extrn '__imp_DrawMenuBarTemp' as DrawMenuBarTemp:qword
        extrn '__imp_GetAppCompatFlags' as GetAppCompatFlags:qword
        extrn '__imp_GetProgmanWindow' as GetProgmanWindow:qword
        extrn '__imp_GetTaskmanWindow' as GetTaskmanWindow:qword
        extrn '__imp_IsHungAppWindow' as IsHungAppWindow:qword
        extrn '__imp_LoadKeyboardLayoutEx' as LoadKeyboardLayoutEx:qword
        extrn '__imp_LoadLocalFonts' as LoadLocalFonts:qword
        extrn '__imp_LoadRemoteFonts' as LoadRemoteFonts:qword
        extrn '__imp_MBToWCSEx' as MBToWCSEx:qword
        extrn '__imp_MB_GetString' as MB_GetString:qword
        extrn '__imp_MenuWindowProcA' as MenuWindowProcA:qword
        extrn '__imp_MenuWindowProcW' as MenuWindowProcW:qword
        extrn '__imp_PrivateExtractIconExA' as PrivateExtractIconExA:qword
        extrn '__imp_PrivateExtractIconExW' as PrivateExtractIconExW:qword
        extrn '__imp_PrivateExtractIconsA' as PrivateExtractIconsA:qword
        extrn '__imp_PrivateExtractIconsW' as PrivateExtractIconsW:qword
        extrn '__imp_QuerySendMessage' as QuerySendMessage:qword
        extrn '__imp_RegisterServicesProcess' as RegisterServicesProcess:qword
        extrn '__imp_RegisterShellHookWindow' as RegisterShellHookWindow:qword
        extrn '__imp_SetProgmanWindow' as SetProgmanWindow:qword
        extrn '__imp_SetShellWindowEx' as SetShellWindowEx:qword
        extrn '__imp_SetSystemMenu' as SetSystemMenu:qword
        extrn '__imp_SetTaskmanWindow' as SetTaskmanWindow:qword
        extrn '__imp_SetWindowStationUser' as SetWindowStationUser:qword
        extrn '__imp_ShowStartGlass' as ShowStartGlass:qword
        extrn '__imp_TranslateMessageEx' as TranslateMessageEx:qword
        extrn '__imp_UserRealizePalette' as UserRealizePalette:qword
        extrn '__imp_UserRegisterWowHandlers' as UserRegisterWowHandlers:qword
        api MenuWindowProc,\
            PrivateExtractIconEx,\
            PrivateExtractIcons
    end if

    if (NTDDI_VERSION >= NTDDI_WIN2K)
        extrn '__imp_CliImmSetHotKey' as CliImmSetHotKey:qword
        extrn '__imp_CtxInitUser32' as CtxInitUser32:qword
        extrn '__imp_DeviceEventWorker' as DeviceEventWorker:qword
        extrn '__imp_GetAppCompatFlags2' as GetAppCompatFlags2:qword
        extrn '__imp_GetLastInputInfo' as GetLastInputInfo:qword
        extrn '__imp_GetMouseMovePointsEx' as GetMouseMovePointsEx:qword
        extrn '__imp_InitializeLpkHooks' as InitializeLpkHooks:qword
        extrn '__imp_LockSetForegroundWindow' as LockSetForegroundWindow:qword
        extrn '__imp_LockWorkStation' as LockWorkStation:qword
        extrn '__imp_SetLayeredWindowAttributes' as SetLayeredWindowAttributes:qword
        extrn '__imp_UpdateLayeredWindow' as UpdateLayeredWindow:qword
        extrn '__imp_UserHandleGrantAccess' as UserHandleGrantAccess:qword
        extrn '__imp_AllowSetForegroundWindow' as AllowSetForegroundWindow:qword
        extrn '__imp_AnimateWindow' as AnimateWindow:qword
    end if

    if (NTDDI_VERSION >= NTDDI_WINXP)
        extrn '__imp_AllowForegroundActivation' as AllowForegroundActivation:qword
        extrn '__imp_BroadcastSystemMessageExA' as BroadcastSystemMessageExA:qword
        extrn '__imp_BroadcastSystemMessageExW' as BroadcastSystemMessageExW:qword
        extrn '__imp_BuildReasonArray' as BuildReasonArray:qword
        extrn '__imp_CreateSystemThreads' as CreateSystemThreads:qword
        extrn '__imp_CsrBroadcastSystemMessageExW' as CsrBroadcastSystemMessageExW:qword
        extrn '__imp_DefRawInputProc' as DefRawInputProc:qword
        extrn '__imp_DestroyReasons' as DestroyReasons:qword
        extrn '__imp_DisableProcessWindowsGhosting' as DisableProcessWindowsGhosting:qword
        extrn '__imp_GetLayeredWindowAttributes' as GetLayeredWindowAttributes:qword
        extrn '__imp_GetRawInputBuffer' as GetRawInputBuffer:qword
        extrn '__imp_GetRawInputData' as GetRawInputData:qword
        extrn '__imp_GetRawInputDeviceInfoA' as GetRawInputDeviceInfoA:qword
        extrn '__imp_GetRawInputDeviceInfoW' as GetRawInputDeviceInfoW:qword
        extrn '__imp_GetRawInputDeviceList' as GetRawInputDeviceList:qword
        extrn '__imp_GetReasonTitleFromReasonCode' as GetReasonTitleFromReasonCode:qword
        extrn '__imp_GetRegisteredRawInputDevices' as GetRegisteredRawInputDevices:qword
        extrn '__imp_GetWindowRgnBox' as GetWindowRgnBox:qword
        extrn '__imp_IsGUIThread' as IsGUIThread:qword
        extrn '__imp_IsServerSideWindow' as IsServerSideWindow:qword
        extrn '__imp_IsWinEventHookInstalled' as IsWinEventHookInstalled:qword
        extrn '__imp_IsWindowInDestroy' as IsWindowInDestroy:qword
        extrn '__imp_MessageBoxTimeoutA' as MessageBoxTimeoutA:qword
        extrn '__imp_MessageBoxTimeoutW' as MessageBoxTimeoutW:qword
        extrn '__imp_PrintWindow' as PrintWindow:qword
        extrn '__imp_RecordShutdownReason' as RecordShutdownReason:qword
        extrn '__imp_RegisterMessagePumpHook' as RegisterMessagePumpHook:qword
        extrn '__imp_RegisterRawInputDevices' as RegisterRawInputDevices:qword
        extrn '__imp_RegisterUserApiHook' as RegisterUserApiHook:qword
        extrn '__imp_UnregisterMessagePumpHook' as UnregisterMessagePumpHook:qword
        extrn '__imp_UnregisterUserApiHook' as UnregisterUserApiHook:qword
        api BroadcastSystemMessageEx,\
            GetRawInputDeviceInfo,\
            MessageBoxTimeout
    end if

    if (NTDDI_VERSION >= NTDDI_WS03SP1)
        extrn '__imp_IsWow64Message' as IsWow64Message:qword
    end if

    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_AddClipboardFormatListener' as AddClipboardFormatListener:qword
        extrn '__imp_CancelShutdown' as CancelShutdown:qword
        extrn '__imp_ChangeWindowMessageFilter' as ChangeWindowMessageFilter:qword
        extrn '__imp_CreateDesktopExA' as CreateDesktopExA:qword
        extrn '__imp_CreateDesktopExW' as CreateDesktopExW:qword
        extrn '__imp_DisplayConfigGetDeviceInfo' as DisplayConfigGetDeviceInfo:qword
        extrn '__imp_DisplayConfigSetDeviceInfo' as DisplayConfigSetDeviceInfo:qword
        extrn '__imp_FrostCrashedWindow' as FrostCrashedWindow:qword
        extrn '__imp_GetIconInfoExA' as GetIconInfoExA:qword
        extrn '__imp_GetIconInfoExW' as GetIconInfoExW:qword
        extrn '__imp_GetPhysicalCursorPos' as GetPhysicalCursorPos:qword
        extrn '__imp_GetSendMessageReceiver' as GetSendMessageReceiver:qword
        extrn '__imp_GetUpdatedClipboardFormats' as GetUpdatedClipboardFormats:qword
        extrn '__imp_GetWindowMinimizeRect' as GetWindowMinimizeRect:qword
        extrn '__imp_GhostWindowFromHungWindow' as GhostWindowFromHungWindow:qword
        extrn '__imp_HungWindowFromGhostWindow' as HungWindowFromGhostWindow:qword
        extrn '__imp_IsProcessDPIAware' as IsProcessDPIAware:qword
        extrn '__imp_IsSETEnabled' as IsSETEnabled:qword
        extrn '__imp_IsThreadDesktopComposited' as IsThreadDesktopComposited:qword
        extrn '__imp_IsWindowRedirectedForPrint' as IsWindowRedirectedForPrint:qword
        extrn '__imp_LogicalToPhysicalPoint' as LogicalToPhysicalPoint:qword
        extrn '__imp_PhysicalToLogicalPoint' as PhysicalToLogicalPoint:qword
        extrn '__imp_RegisterPowerSettingNotification' as RegisterPowerSettingNotification:qword
        extrn '__imp_RemoveClipboardFormatListener' as RemoveClipboardFormatListener:qword
        extrn '__imp_SetPhysicalCursorPos' as SetPhysicalCursorPos:qword
        extrn '__imp_SetProcessDPIAware' as SetProcessDPIAware:qword
        extrn '__imp_ShutdownBlockReasonCreate' as ShutdownBlockReasonCreate:qword
        extrn '__imp_ShutdownBlockReasonDestroy' as ShutdownBlockReasonDestroy:qword
        extrn '__imp_ShutdownBlockReasonQuery' as ShutdownBlockReasonQuery:qword
        extrn '__imp_SoundSentry' as SoundSentry:qword
        extrn '__imp_UnregisterPowerSettingNotification' as UnregisterPowerSettingNotification:qword
        extrn '__imp_UpdateLayeredWindowIndirect' as UpdateLayeredWindowIndirect:qword
        extrn '__imp_UpdateWindowTransform' as UpdateWindowTransform:qword
        api CreateDesktopEx,\
            GetIconInfoEx
    end if

    if (NTDDI_VERSION >= NTDDI_WIN7)
        extrn '__imp_CalculatePopupWindowPosition' as CalculatePopupWindowPosition:qword
        extrn '__imp_ChangeWindowMessageFilterEx' as ChangeWindowMessageFilterEx:qword
        extrn '__imp_CloseGestureInfoHandle' as CloseGestureInfoHandle:qword
        extrn '__imp_CloseTouchInputHandle' as CloseTouchInputHandle:qword
        extrn '__imp_DwmGetDxSharedSurface' as DwmGetDxSharedSurface:qword
        extrn '__imp_GetDisplayConfigBufferSizes' as GetDisplayConfigBufferSizes:qword
        extrn '__imp_GetGestureConfig' as GetGestureConfig:qword
        extrn '__imp_GetGestureExtraArgs' as GetGestureExtraArgs:qword
        extrn '__imp_GetGestureInfo' as GetGestureInfo:qword
        extrn '__imp_GetTouchInputInfo' as GetTouchInputInfo:qword
        extrn '__imp_GetWindowCompositionAttribute' as GetWindowCompositionAttribute:qword
        extrn '__imp_GetWindowDisplayAffinity' as GetWindowDisplayAffinity:qword
        extrn '__imp_IsTopLevelWindow' as IsTopLevelWindow:qword
        extrn '__imp_IsTouchWindow' as IsTouchWindow:qword
        extrn '__imp_QueryDisplayConfig' as QueryDisplayConfig:qword
        extrn '__imp_RegisterTouchWindow' as RegisterTouchWindow:qword
        extrn '__imp_SetDisplayConfig' as SetDisplayConfig:qword
        extrn '__imp_SetGestureConfig' as SetGestureConfig:qword
        extrn '__imp_SetWindowCompositionAttribute' as SetWindowCompositionAttribute:qword
        extrn '__imp_SetWindowDisplayAffinity' as SetWindowDisplayAffinity:qword
        extrn '__imp_UnregisterTouchWindow' as UnregisterTouchWindow:qword
    end if

    if (NTDDI_VERSION >= NTDDI_WIN8)
        extrn '__imp_CreateWindowInBand' as CreateWindowInBand:qword
        extrn '__imp_EnableMouseInPointer' as EnableMouseInPointer:qword
        extrn '__imp_EvaluateProximityToPolygon' as EvaluateProximityToPolygon:qword
        extrn '__imp_EvaluateProximityToRect' as EvaluateProximityToRect:qword
        extrn '__imp_GetAutoRotationState' as GetAutoRotationState:qword
        extrn '__imp_GetCIMSSM' as GetCIMSSM:qword
        extrn '__imp_GetCurrentInputMessageSource' as GetCurrentInputMessageSource:qword
        extrn '__imp_GetDisplayAutoRotationPreferences' as GetDisplayAutoRotationPreferences:qword
        extrn '__imp_GetPointerCursorId' as GetPointerCursorId:qword
        extrn '__imp_GetPointerDevice' as GetPointerDevice:qword
        extrn '__imp_GetPointerDeviceCursors' as GetPointerDeviceCursors:qword
        extrn '__imp_GetPointerDeviceProperties' as GetPointerDeviceProperties:qword
        extrn '__imp_GetPointerDeviceRects' as GetPointerDeviceRects:qword
        extrn '__imp_GetPointerDevices' as GetPointerDevices:qword
        extrn '__imp_GetPointerFrameInfo' as GetPointerFrameInfo:qword
        extrn '__imp_GetPointerFrameInfoHistory' as GetPointerFrameInfoHistory:qword
        extrn '__imp_GetPointerFramePenInfo' as GetPointerFramePenInfo:qword
        extrn '__imp_GetPointerFramePenInfoHistory' as GetPointerFramePenInfoHistory:qword
        extrn '__imp_GetPointerFrameTouchInfo' as GetPointerFrameTouchInfo:qword
        extrn '__imp_GetPointerFrameTouchInfoHistory' as GetPointerFrameTouchInfoHistory:qword
        extrn '__imp_GetPointerInfo' as GetPointerInfo:qword
        extrn '__imp_GetPointerInfoHistory' as GetPointerInfoHistory:qword
        extrn '__imp_GetPointerPenInfo' as GetPointerPenInfo:qword
        extrn '__imp_GetPointerPenInfoHistory' as GetPointerPenInfoHistory:qword
        extrn '__imp_GetPointerTouchInfo' as GetPointerTouchInfo:qword
        extrn '__imp_GetPointerTouchInfoHistory' as GetPointerTouchInfoHistory:qword
        extrn '__imp_GetPointerType' as GetPointerType:qword
        extrn '__imp_GetRawPointerDeviceData' as GetRawPointerDeviceData:qword
        extrn '__imp_GetUnpredictedMessagePos' as GetUnpredictedMessagePos:qword
        extrn '__imp_GetWindowFeedbackSetting' as GetWindowFeedbackSetting:qword
        extrn '__imp_InitializeTouchInjection' as InitializeTouchInjection:qword
        extrn '__imp_InjectTouchInput' as InjectTouchInput:qword
        extrn '__imp_IsImmersiveProcess' as IsImmersiveProcess:qword
        extrn '__imp_IsMouseInPointerEnabled' as IsMouseInPointerEnabled:qword
        extrn '__imp_PackTouchHitTestingProximityEvaluation' as PackTouchHitTestingProximityEvaluation:qword
        extrn '__imp_RegisterPointerDeviceNotifications' as RegisterPointerDeviceNotifications:qword
        extrn '__imp_RegisterPointerInputTarget' as RegisterPointerInputTarget:qword
        extrn '__imp_RegisterSuspendResumeNotification' as RegisterSuspendResumeNotification:qword
        extrn '__imp_RegisterTouchHitTestingWindow' as RegisterTouchHitTestingWindow:qword
        extrn '__imp_SetCoalescableTimer' as SetCoalescableTimer:qword
        extrn '__imp_SetDisplayAutoRotationPreferences' as SetDisplayAutoRotationPreferences:qword
        extrn '__imp_SetProcessRestrictionExemption' as SetProcessRestrictionExemption:qword
        extrn '__imp_SetWindowFeedbackSetting' as SetWindowFeedbackSetting:qword
        extrn '__imp_ShowSystemCursor' as ShowSystemCursor:qword
        extrn '__imp_SkipPointerFrameMessages' as SkipPointerFrameMessages:qword
        extrn '__imp_UnregisterPointerInputTarget' as UnregisterPointerInputTarget:qword
        extrn '__imp_UnregisterSuspendResumeNotification' as UnregisterSuspendResumeNotification:qword
    end if

    if (NTDDI_VERSION >= NTDDI_WIN81)
        extrn '__imp_PhysicalToLogicalPointForPerMonitorDPI' as PhysicalToLogicalPointForPerMonitorDPI:qword
    end if

api AppendMenu,\
    CallWindowProc,\
    ChangeDisplaySettings,\
    CallWindowProc,\
    ChangeDisplaySettings,\
    ChangeMenu,\
    CharLower,\
    CharNext,\
    CharPrev,\
    CharToOem,\
    CharToOemBuff,\
    CharUpper,\
    CharUpperBuff,\
    CopyAcceleratorTable,\
    CreateAcceleratorTable,\
    CreateDesktop,\
    CreateDialogIndirectParam,\
    CreateDialogParam,\
    CreateMDIWindow,\
    CreateWindowEx,\
    CreateWindowStation,\
    DdeCreateStringHandle,\
    DdeInitialize,\
    DdeQueryString,\
    DefDlgProc,\
    DefFrameProc,\
    DefMDIChildProc,\
    DefWindowProc,\
    DialogBoxIndirectParam,\
    DialogBoxParam,\
    DispatchMessage,\
    DlgDirList,\
    DlgDirListComboBox,\
    DlgDirSelectComboBoxEx,\
    DlgDirSelectEx,\
    DrawCaptionTemp,\
    DrawState,\
    DrawText,\
    DrawTextEx,\
    EnumDesktops,\
    EnumDisplayDevices,\
    EnumDisplaySettings,\
    EnumProps,\
    EnumPropsEx,\
    EnumWindowStations,\
    FindWindow,\
    FindWindowEx,\
    GetClassInfo,\
    GetClassInfoEx,\
    GetClassLong,\
    GetClassName,\
    GetClipboardFormatName,\
    GetDlgItemText,\
    GetKeyboardLayoutName,\
    GetKeyNameText,\
    GetMenuItemInfo,\
    GetMenuString,\
    GetMessage,\
    GetProp,\
    GetTabbedTextExtent,\
    GetUserObjectInformation,\
    GetWindowLong,\
    GetWindowText,\
    GetWindowTextLength,\
    GrayString,\
    InsertMenu,\
    InsertMenuItem,\
    IsCharAlpha,\
    IsCharAlphaNumeric,\
    IsCharLower,\
    IsCharUpper,\
    LoadAccelerators,\
    LoadBitmap,\
    LoadCursor,\
    LoadCursorFromFile,\
    LoadIcon,\
    LoadImage,\
    LoadKeyboardLayout,\
    LoadMenu,\
    LoadMenuIndirect,\
    LoadString,\
    MapVirtualKey,\
    MapVirtualKeyEx,\
    MessageBox,\
    MessageBoxEx,\
    MessageBoxIndirect,\
    ModifyMenu,\
    OemToChar,\
    OemToCharBuff,\
    OpenDesktop,\
    OpenWindowStation,\
    PeekMessage,\
    PostAppMessage,\
    PostMessage,\
    PostThreadMessage,\
    RegisterClass,\
    RegisterClassEx,\
    RegisterClipboardFormat,\
    RegisterWindowMessage,\
    RemoveProp,\
    SendDlgItemMessage,\
    SendMessage,\
    SendMessageCallback,\
    SendMessageTimeout,\
    SendNotifyMessage,\
    SetClassLong,\
    SetDlgItemText,\
    SetMenuItemInfo,\
    SetProp,\
    SetUserObjectInformation,\
    SetWindowLong,\
    SetWindowsHook,\
    SetWindowsHookEx,\
    SetWindowText,\
    SystemParametersInfo,\
    TabbedTextOut,\
    TranslateAccelerator,\
    UnregisterClass,\
    VkKeyScan,\
    VkKeyScanEx,\
    WinHelp,\
    wsprintf,\
    wvsprintf

    PostAppMessage equ PostThreadMessage
    PostAppMessageA equ PostThreadMessageA
    PostAppMessageW equ PostThreadMessageW
    AnsiToOem equ CharToOemA
    OemToAnsi equ OemToCharA
    AnsiToOemBuff equ CharToOemBuffA
    OemToAnsiBuff equ OemToCharBuffA
    AnsiUpper equ CharUpperA
    AnsiUpperBuff equ CharUpperBuffA
    AnsiLower equ CharLowerA
    AnsiLowerBuff equ CharLowerBuffA
    AnsiNext equ CharNextA
    AnsiPrev equ CharPrevA
    
    extrn '__imp_GetClassLongPtrA' as GetClassLongPtrA:qword
    extrn '__imp_GetClassLongPtrW' as GetClassLongPtrW:qword
    extrn '__imp_GetWindowLongPtrA' as GetWindowLongPtrA:qword
    extrn '__imp_GetWindowLongPtrW' as GetWindowLongPtrW:qword
    extrn '__imp_SetClassLongPtrA' as SetClassLongPtrA:qword
    extrn '__imp_SetClassLongPtrW' as SetClassLongPtrW:qword
    extrn '__imp_SetWindowLongPtrA' as SetWindowLongPtrA:qword
    extrn '__imp_SetWindowLongPtrW' as SetWindowLongPtrW:qword
    api GetClassLongPtr,\
        GetWindowLongPtr,\
        SetClassLongPtr,\
        SetWindowLongPtr
else
    extrn '__imp__ActivateKeyboardLayout@8' as ActivateKeyboardLayout:dword
    extrn '__imp__AdjustWindowRect@12' as AdjustWindowRect:dword
    extrn '__imp__AdjustWindowRectEx@16' as AdjustWindowRectEx:dword
    extrn '__imp__AnyPopup@0' as AnyPopup:dword
    extrn '__imp__AppendMenuA@16' as AppendMenuA:dword
    extrn '__imp__AppendMenuW@16' as AppendMenuW:dword
    extrn '__imp__ArrangeIconicWindows@4' as ArrangeIconicWindows:dword
    extrn '__imp__AttachThreadInput@12' as AttachThreadInput:dword
    extrn '__imp__BeginDeferWindowPos@4' as BeginDeferWindowPos:dword
    extrn '__imp__BeginPaint@8' as BeginPaint:dword
    extrn '__imp__BringWindowToTop@4' as BringWindowToTop:dword
    extrn '__imp__BroadcastSystemMessageA@20' as BroadcastSystemMessageA:dword
    extrn '__imp__BroadcastSystemMessageW@20' as BroadcastSystemMessageW:dword
    extrn '__imp__GetAltTabInfoA@20' as GetAltTabInfoA:dword
    extrn '__imp__GetAltTabInfoW@20' as GetAltTabInfoW:dword
    api BroadcastSystemMessage,\
        GetAltTabInfo
    if (NTDDI_VERSION > NTDDI_WIN98_ME)
        extrn '__imp__RealGetWindowClassA' as RealGetWindowClassA:dword
        extrn '__imp__RealGetWindowClassW' as RealGetWindowClassW:dword
        api RealGetWindowClass
    end if
    extrn '__imp__CallMsgFilterA@8' as CallMsgFilterA:dword
    extrn '__imp__CallMsgFilterW@8' as CallMsgFilterW:dword
    extrn '__imp__CallNextHookEx@16' as CallNextHookEx:dword
    extrn '__imp__CallWindowProcA@20' as CallWindowProcA:dword
    extrn '__imp__CallWindowProcW@20' as CallWindowProcW:dword
    extrn '__imp__CascadeChildWindows@8' as CascadeChildWindows:dword
    extrn '__imp__CascadeWindows@20' as CascadeWindows:dword
    extrn '__imp__ChangeClipboardChain@8' as ChangeClipboardChain:dword
    extrn '__imp__ChangeDisplaySettingsA@8' as ChangeDisplaySettingsA:dword
    extrn '__imp__ChangeDisplaySettingsW@8' as ChangeDisplaySettingsW:dword
    extrn '__imp__ChangeMenuA@20' as ChangeMenuA:dword
    extrn '__imp__ChangeMenuW@20' as ChangeMenuW:dword
    extrn '__imp__CharLowerA@4' as CharLowerA:dword
    extrn '__imp__CharLowerBuffA@8' as CharLowerBuffA:dword
    extrn '__imp__CharLowerBuffW@8' as CharLowerBuffW:dword
    extrn '__imp__CharLowerW@4' as CharLowerW:dword
    extrn '__imp__CharNextA@4' as CharNextA:dword
    extrn '__imp__CharNextExA@12' as CharNextExA:dword
    extrn '__imp__CharNextW@4' as CharNextW:dword
    extrn '__imp__CharPrevA@8' as CharPrevA:dword
    extrn '__imp__CharPrevExA@16' as CharPrevExA:dword
    extrn '__imp__CharPrevW@8' as CharPrevW:dword
    extrn '__imp__CharToOemA@8' as CharToOemA:dword
    extrn '__imp__CharToOemBuffA@12' as CharToOemBuffA:dword
    extrn '__imp__CharToOemBuffW@12' as CharToOemBuffW:dword
    extrn '__imp__CharToOemW@8' as CharToOemW:dword
    extrn '__imp__CharUpperA@4' as CharUpperA:dword
    extrn '__imp__CharUpperBuffA@8' as CharUpperBuffA:dword
    extrn '__imp__CharUpperBuffW@8' as CharUpperBuffW:dword
    extrn '__imp__CharUpperW@4' as CharUpperW:dword
    extrn '__imp__CheckDlgButton@12' as CheckDlgButton:dword
    extrn '__imp__CheckMenuItem@12' as CheckMenuItem:dword
    extrn '__imp__CheckMenuRadioItem@20' as CheckMenuRadioItem:dword
    extrn '__imp__CheckRadioButton@16' as CheckRadioButton:dword
    extrn '__imp__ChildWindowFromPoint@12' as ChildWindowFromPoint:dword
    extrn '__imp__ChildWindowFromPointEx@16' as ChildWindowFromPointEx:dword
    extrn '__imp__ClientToScreen@8' as ClientToScreen:dword
    extrn '__imp__ClipCursor@4' as ClipCursor:dword
    extrn '__imp__CloseClipboard@0' as CloseClipboard:dword
    extrn '__imp__CloseDesktop@4' as CloseDesktop:dword
    extrn '__imp__CloseWindow@4' as CloseWindow:dword
    extrn '__imp__CloseWindowStation@4' as CloseWindowStation:dword
    extrn '__imp__CopyAcceleratorTableA@12' as CopyAcceleratorTableA:dword
    extrn '__imp__CopyAcceleratorTableW@12' as CopyAcceleratorTableW:dword
    extrn '__imp__CopyIcon@4' as CopyIcon:dword
    extrn '__imp__CopyImage@20' as CopyImage:dword
    extrn '__imp__CopyRect@8' as CopyRect:dword
    extrn '__imp__CountClipboardFormats@0' as CountClipboardFormats:dword
    extrn '__imp__CreateAcceleratorTableA@8' as CreateAcceleratorTableA:dword
    extrn '__imp__CreateAcceleratorTableW@8' as CreateAcceleratorTableW:dword
    extrn '__imp__CreateCaret@16' as CreateCaret:dword
    extrn '__imp__CreateCursor@28' as CreateCursor:dword
    extrn '__imp__CreateDesktopA@24' as CreateDesktopA:dword
    extrn '__imp__CreateDesktopW@24' as CreateDesktopW:dword
    extrn '__imp__CreateDialogIndirectParamA@20' as CreateDialogIndirectParamA:dword
    extrn '__imp__CreateDialogIndirectParamW@20' as CreateDialogIndirectParamW:dword
    extrn '__imp__CreateDialogParamA@20' as CreateDialogParamA:dword
    extrn '__imp__CreateDialogParamW@20' as CreateDialogParamW:dword
    extrn '__imp__CreateIcon@28' as CreateIcon:dword
    extrn '__imp__CreateIconFromResource@16' as CreateIconFromResource:dword
    extrn '__imp__CreateIconFromResourceEx@28' as CreateIconFromResourceEx:dword
    extrn '__imp__CreateIconIndirect@4' as CreateIconIndirect:dword
    extrn '__imp__CreateMDIWindowA@40' as CreateMDIWindowA:dword
    extrn '__imp__CreateMDIWindowW@40' as CreateMDIWindowW:dword
    extrn '__imp__CreateMenu@0' as CreateMenu:dword
    extrn '__imp__CreatePopupMenu@0' as CreatePopupMenu:dword
    extrn '__imp__CreateWindowExA@48' as CreateWindowExA:dword
    extrn '__imp__CreateWindowExW@48' as CreateWindowExW:dword
    extrn '__imp__CreateWindowStationA@16' as CreateWindowStationA:dword
    extrn '__imp__CreateWindowStationW@16' as CreateWindowStationW:dword
    extrn '__imp__DdeAbandonTransaction@12' as DdeAbandonTransaction:dword
    extrn '__imp__DdeAccessData@8' as DdeAccessData:dword
    extrn '__imp__DdeAddData@16' as DdeAddData:dword
    extrn '__imp__DdeClientTransaction@32' as DdeClientTransaction:dword
    extrn '__imp__DdeCmpStringHandles@8' as DdeCmpStringHandles:dword
    extrn '__imp__DdeConnect@16' as DdeConnect:dword
    extrn '__imp__DdeConnectList@20' as DdeConnectList:dword
    extrn '__imp__DdeCreateDataHandle@28' as DdeCreateDataHandle:dword
    extrn '__imp__DdeCreateStringHandleA@12' as DdeCreateStringHandleA:dword
    extrn '__imp__DdeCreateStringHandleW@12' as DdeCreateStringHandleW:dword
    extrn '__imp__DdeDisconnect@4' as DdeDisconnect:dword
    extrn '__imp__DdeDisconnectList@4' as DdeDisconnectList:dword
    extrn '__imp__DdeEnableCallback@12' as DdeEnableCallback:dword
    extrn '__imp__DdeFreeDataHandle@4' as DdeFreeDataHandle:dword
    extrn '__imp__DdeFreeStringHandle@8' as DdeFreeStringHandle:dword
    extrn '__imp__DdeGetData@16' as DdeGetData:dword
    extrn '__imp__DdeGetLastError@4' as DdeGetLastError:dword
    extrn '__imp__DdeImpersonateClient@4' as DdeImpersonateClient:dword
    extrn '__imp__DdeInitializeA@16' as DdeInitializeA:dword
    extrn '__imp__DdeInitializeW@16' as DdeInitializeW:dword
    extrn '__imp__DdeKeepStringHandle@8' as DdeKeepStringHandle:dword
    extrn '__imp__DdeNameService@16' as DdeNameService:dword
    extrn '__imp__DdePostAdvise@12' as DdePostAdvise:dword
    extrn '__imp__DdeQueryConvInfo@12' as DdeQueryConvInfo:dword
    extrn '__imp__DdeQueryNextServer@8' as DdeQueryNextServer:dword
    extrn '__imp__DdeQueryStringA@20' as DdeQueryStringA:dword
    extrn '__imp__DdeQueryStringW@20' as DdeQueryStringW:dword
    extrn '__imp__DdeReconnect@4' as DdeReconnect:dword
    extrn '__imp__DdeSetQualityOfService@12' as DdeSetQualityOfService:dword
    extrn '__imp__DdeSetUserHandle@12' as DdeSetUserHandle:dword
    extrn '__imp__DdeUnaccessData@4' as DdeUnaccessData:dword
    extrn '__imp__DdeUninitialize@4' as DdeUninitialize:dword
    extrn '__imp__DefDlgProcA@16' as DefDlgProcA:dword
    extrn '__imp__DefDlgProcW@16' as DefDlgProcW:dword
    extrn '__imp__DeferWindowPos@32' as DeferWindowPos:dword
    extrn '__imp__DefFrameProcA@20' as DefFrameProcA:dword
    extrn '__imp__DefFrameProcW@20' as DefFrameProcW:dword
    extrn '__imp__DefMDIChildProcA@16' as DefMDIChildProcA:dword
    extrn '__imp__DefMDIChildProcW@16' as DefMDIChildProcW:dword
    extrn '__imp__DefWindowProcA@16' as DefWindowProcA:dword
    extrn '__imp__DefWindowProcW@16' as DefWindowProcW:dword
    extrn '__imp__DeleteMenu@12' as DeleteMenu:dword
    extrn '__imp__DestroyAcceleratorTable@4' as DestroyAcceleratorTable:dword
    extrn '__imp__DestroyCaret@0' as DestroyCaret:dword
    extrn '__imp__DestroyCursor@4' as DestroyCursor:dword
    extrn '__imp__DestroyIcon@4' as DestroyIcon:dword
    extrn '__imp__DestroyMenu@4' as DestroyMenu:dword
    extrn '__imp__DestroyWindow@4' as DestroyWindow:dword
    extrn '__imp__DialogBoxIndirectParamA@20' as DialogBoxIndirectParamA:dword
    extrn '__imp__DialogBoxIndirectParamW@20' as DialogBoxIndirectParamW:dword
    extrn '__imp__DialogBoxParamA@20' as DialogBoxParamA:dword
    extrn '__imp__DialogBoxParamW@20' as DialogBoxParamW:dword
    extrn '__imp__DispatchMessageA@4' as DispatchMessageA:dword
    extrn '__imp__DispatchMessageW@4' as DispatchMessageW:dword
    extrn '__imp__DlgDirListA@20' as DlgDirListA:dword
    extrn '__imp__DlgDirListComboBoxA@20' as DlgDirListComboBoxA:dword
    extrn '__imp__DlgDirListComboBoxW@20' as DlgDirListComboBoxW:dword
    extrn '__imp__DlgDirListW@20' as DlgDirListW:dword
    extrn '__imp__DlgDirSelectComboBoxExA@16' as DlgDirSelectComboBoxExA:dword
    extrn '__imp__DlgDirSelectComboBoxExW@16' as DlgDirSelectComboBoxExW:dword
    extrn '__imp__DlgDirSelectExA@16' as DlgDirSelectExA:dword
    extrn '__imp__DlgDirSelectExW@16' as DlgDirSelectExW:dword
    extrn '__imp__DragDetect@12' as DragDetect:dword
    extrn '__imp__DragObject@20' as DragObject:dword
    extrn '__imp__DrawAnimatedRects@16' as DrawAnimatedRects:dword
    extrn '__imp__DrawCaption@16' as DrawCaption:dword
    extrn '__imp__DrawEdge@16' as DrawEdge:dword
    extrn '__imp__DrawFocusRect@8' as DrawFocusRect:dword
    extrn '__imp__DrawFrame@16' as DrawFrame:dword
    extrn '__imp__DrawFrameControl@16' as DrawFrameControl:dword
    extrn '__imp__DrawIcon@16' as DrawIcon:dword
    extrn '__imp__DrawIconEx@36' as DrawIconEx:dword
    extrn '__imp__DrawMenuBar@4' as DrawMenuBar:dword
    extrn '__imp__DrawStateA@40' as DrawStateA:dword
    extrn '__imp__DrawStateW@40' as DrawStateW:dword
    extrn '__imp__DrawTextA@20' as DrawTextA:dword
    extrn '__imp__DrawTextExA@24' as DrawTextExA:dword
    extrn '__imp__DrawTextExW@24' as DrawTextExW:dword
    extrn '__imp__DrawTextW@20' as DrawTextW:dword
    extrn '__imp__EditWndProc@16' as EditWndProc:dword
    extrn '__imp__EmptyClipboard@0' as EmptyClipboard:dword
    extrn '__imp__EnableMenuItem@12' as EnableMenuItem:dword
    extrn '__imp__EnableScrollBar@12' as EnableScrollBar:dword
    extrn '__imp__EnableWindow@8' as EnableWindow:dword
    extrn '__imp__EndDeferWindowPos@4' as EndDeferWindowPos:dword
    extrn '__imp__EndDialog@8' as EndDialog:dword
    extrn '__imp__EndPaint@8' as EndPaint:dword
    extrn '__imp__EndTask@12' as EndTask:dword
    extrn '__imp__EnumChildWindows@12' as EnumChildWindows:dword
    extrn '__imp__EnumClipboardFormats@4' as EnumClipboardFormats:dword
    extrn '__imp__EnumDesktopsA@12' as EnumDesktopsA:dword
    extrn '__imp__EnumDesktopsW@12' as EnumDesktopsW:dword
    extrn '__imp__EnumDesktopWindows@12' as EnumDesktopWindows:dword
    extrn '__imp__EnumDisplayDevicesA@16' as EnumDisplayDevicesA:dword
    extrn '__imp__EnumDisplayDevicesW@16' as EnumDisplayDevicesW:dword
    extrn '__imp__EnumDisplaySettingsA@12' as EnumDisplaySettingsA:dword
    extrn '__imp__EnumDisplaySettingsW@12' as EnumDisplaySettingsW:dword
    extrn '__imp__EnumPropsA@8' as EnumPropsA:dword
    extrn '__imp__EnumPropsExA@12' as EnumPropsExA:dword
    extrn '__imp__EnumPropsExW@12' as EnumPropsExW:dword
    extrn '__imp__EnumPropsW@8' as EnumPropsW:dword
    extrn '__imp__EnumThreadWindows@12' as EnumThreadWindows:dword
    extrn '__imp__EnumWindows@8' as EnumWindows:dword
    extrn '__imp__EnumWindowStationsA@8' as EnumWindowStationsA:dword
    extrn '__imp__EnumWindowStationsW@8' as EnumWindowStationsW:dword
    extrn '__imp__EqualRect@8' as EqualRect:dword
    extrn '__imp__ExcludeUpdateRgn@8' as ExcludeUpdateRgn:dword
    extrn '__imp__ExitWindowsEx@8' as ExitWindowsEx:dword
    extrn '__imp__FillRect@12' as FillRect:dword
    extrn '__imp__FindWindowA@8' as FindWindowA:dword
    extrn '__imp__FindWindowExA@16' as FindWindowExA:dword
    extrn '__imp__FindWindowExW@16' as FindWindowExW:dword
    extrn '__imp__FindWindowW@8' as FindWindowW:dword
    extrn '__imp__FlashWindow@8' as FlashWindow:dword
    extrn '__imp__FrameRect@12' as FrameRect:dword
    extrn '__imp__FreeDDElParam@8' as FreeDDElParam:dword
    extrn '__imp__GetActiveWindow@0' as GetActiveWindow:dword
    extrn '__imp__GetAsyncKeyState@4' as GetAsyncKeyState:dword
    extrn '__imp__GetCapture@0' as GetCapture:dword
    extrn '__imp__GetCaretBlinkTime@0' as GetCaretBlinkTime:dword
    extrn '__imp__GetCaretPos@4' as GetCaretPos:dword
    extrn '__imp__GetClassInfoA@12' as GetClassInfoA:dword
    extrn '__imp__GetClassInfoExA@12' as GetClassInfoExA:dword
    extrn '__imp__GetClassInfoExW@12' as GetClassInfoExW:dword
    extrn '__imp__GetClassInfoW@12' as GetClassInfoW:dword
    extrn '__imp__GetClassLongA@8' as GetClassLongA:dword
    extrn '__imp__GetClassLongW@8' as GetClassLongW:dword
    extrn '__imp__GetClassNameA@12' as GetClassNameA:dword
    extrn '__imp__GetClassNameW@12' as GetClassNameW:dword
    extrn '__imp__GetClassWord@8' as GetClassWord:dword
    extrn '__imp__GetClientRect@8' as GetClientRect:dword
    extrn '__imp__GetClipboardData@4' as GetClipboardData:dword
    extrn '__imp__GetClipboardFormatNameA@12' as GetClipboardFormatNameA:dword
    extrn '__imp__GetClipboardFormatNameW@12' as GetClipboardFormatNameW:dword
    extrn '__imp__GetClipboardOwner@0' as GetClipboardOwner:dword
    extrn '__imp__GetClipboardViewer@0' as GetClipboardViewer:dword
    extrn '__imp__GetClipCursor@4' as GetClipCursor:dword
    extrn '__imp__GetCursor@0' as GetCursor:dword
    extrn '__imp__GetCursorPos@4' as GetCursorPos:dword
    extrn '__imp__GetDC@4' as GetDC:dword
    extrn '__imp__GetDCEx@12' as GetDCEx:dword
    extrn '__imp__GetDesktopWindow@0' as GetDesktopWindow:dword
    extrn '__imp__GetDialogBaseUnits@0' as GetDialogBaseUnits:dword
    extrn '__imp__GetDlgCtrlID@4' as GetDlgCtrlID:dword
    extrn '__imp__GetDlgItem@8' as GetDlgItem:dword
    extrn '__imp__GetDlgItemInt@16' as GetDlgItemInt:dword
    extrn '__imp__GetDlgItemTextA@16' as GetDlgItemTextA:dword
    extrn '__imp__GetDlgItemTextW@16' as GetDlgItemTextW:dword
    extrn '__imp__GetDoubleClickTime@0' as GetDoubleClickTime:dword
    extrn '__imp__GetFocus@0' as GetFocus:dword
    extrn '__imp__GetForegroundWindow@0' as GetForegroundWindow:dword
    if (NTDDI_VERSION <> NTDDI_WIN95 & NTDDI_VERSION <> NTDDI_WINNT4)
        extrn '__imp__GetGuiResources@8' as GetGuiResources:dword
    end if
    extrn '__imp__GetIconInfo@8' as GetIconInfo:dword
    extrn '__imp__GetInputDesktop@0' as GetInputDesktop:dword
    extrn '__imp__GetInputState@0' as GetInputState:dword
    extrn '__imp__GetKBCodePage@0' as GetKBCodePage:dword
    extrn '__imp__GetKeyboardLayout@4' as GetKeyboardLayout:dword
    extrn '__imp__GetKeyboardLayoutList@8' as GetKeyboardLayoutList:dword
    extrn '__imp__GetKeyboardLayoutNameA@4' as GetKeyboardLayoutNameA:dword
    extrn '__imp__GetKeyboardLayoutNameW@4' as GetKeyboardLayoutNameW:dword
    extrn '__imp__GetKeyboardState@4' as GetKeyboardState:dword
    extrn '__imp__GetKeyboardType@4' as GetKeyboardType:dword
    extrn '__imp__GetKeyNameTextA@12' as GetKeyNameTextA:dword
    extrn '__imp__GetKeyNameTextW@12' as GetKeyNameTextW:dword
    extrn '__imp__GetKeyState@4' as GetKeyState:dword
    extrn '__imp__GetLastActivePopup@4' as GetLastActivePopup:dword
    extrn '__imp__GetMenu@4' as GetMenu:dword
    extrn '__imp__GetMenuCheckMarkDimensions@0' as GetMenuCheckMarkDimensions:dword
    extrn '__imp__GetMenuContextHelpId@4' as GetMenuContextHelpId:dword
    extrn '__imp__GetMenuDefaultItem@12' as GetMenuDefaultItem:dword
    extrn '__imp__GetMenuItemCount@4' as GetMenuItemCount:dword
    extrn '__imp__GetMenuItemID@8' as GetMenuItemID:dword
    extrn '__imp__GetMenuItemInfoA@16' as GetMenuItemInfoA:dword
    extrn '__imp__GetMenuItemInfoW@16' as GetMenuItemInfoW:dword
    extrn '__imp__GetMenuItemRect@16' as GetMenuItemRect:dword
    extrn '__imp__GetMenuState@12' as GetMenuState:dword
    extrn '__imp__GetMenuStringA@20' as GetMenuStringA:dword
    extrn '__imp__GetMenuStringW@20' as GetMenuStringW:dword
    extrn '__imp__GetMessageA@16' as GetMessageA:dword
    extrn '__imp__GetMessageExtraInfo@0' as GetMessageExtraInfo:dword
    extrn '__imp__GetMessagePos@0' as GetMessagePos:dword
    extrn '__imp__GetMessageTime@0' as GetMessageTime:dword
    extrn '__imp__GetMessageW@16' as GetMessageW:dword
    extrn '__imp__GetNextDlgGroupItem@12' as GetNextDlgGroupItem:dword
    extrn '__imp__GetNextDlgTabItem@12' as GetNextDlgTabItem:dword
    extrn '__imp__GetOpenClipboardWindow@0' as GetOpenClipboardWindow:dword
    extrn '__imp__GetParent@4' as GetParent:dword
    extrn '__imp__GetPriorityClipboardFormat@8' as GetPriorityClipboardFormat:dword
    extrn '__imp__GetProcessWindowStation@0' as GetProcessWindowStation:dword
    extrn '__imp__GetPropA@8' as GetPropA:dword
    extrn '__imp__GetPropW@8' as GetPropW:dword
    extrn '__imp__GetQueueStatus@4' as GetQueueStatus:dword
    extrn '__imp__GetScrollInfo@12' as GetScrollInfo:dword
    extrn '__imp__GetScrollPos@8' as GetScrollPos:dword
    extrn '__imp__GetScrollRange@16' as GetScrollRange:dword
    extrn '__imp__GetShellWindow@0' as GetShellWindow:dword
    extrn '__imp__GetSubMenu@8' as GetSubMenu:dword
    extrn '__imp__GetSysColor@4' as GetSysColor:dword
    extrn '__imp__GetSysColorBrush@4' as GetSysColorBrush:dword
    extrn '__imp__GetSystemMenu@8' as GetSystemMenu:dword
    extrn '__imp__GetSystemMetrics@4' as GetSystemMetrics:dword
    extrn '__imp__GetTabbedTextExtentA@20' as GetTabbedTextExtentA:dword
    extrn '__imp__GetTabbedTextExtentW@20' as GetTabbedTextExtentW:dword
    extrn '__imp__GetThreadDesktop@4' as GetThreadDesktop:dword
    extrn '__imp__GetTopWindow@4' as GetTopWindow:dword
    extrn '__imp__GetUpdateRect@12' as GetUpdateRect:dword
    extrn '__imp__GetUpdateRgn@12' as GetUpdateRgn:dword
    extrn '__imp__GetUserObjectInformationA@20' as GetUserObjectInformationA:dword
    extrn '__imp__GetUserObjectInformationW@20' as GetUserObjectInformationW:dword
    extrn '__imp__GetUserObjectSecurity@20' as GetUserObjectSecurity:dword
    extrn '__imp__GetWindow@8' as GetWindow:dword
    extrn '__imp__GetWindowContextHelpId@4' as GetWindowContextHelpId:dword
    extrn '__imp__GetWindowDC@4' as GetWindowDC:dword
    extrn '__imp__GetWindowLongA@8' as GetWindowLongA:dword
    extrn '__imp__GetWindowLongW@8' as GetWindowLongW:dword
    extrn '__imp__GetWindowPlacement@8' as GetWindowPlacement:dword
    extrn '__imp__GetWindowRect@8' as GetWindowRect:dword
    extrn '__imp__GetWindowRgn@8' as GetWindowRgn:dword
    extrn '__imp__GetWindowTextA@12' as GetWindowTextA:dword
    extrn '__imp__GetWindowTextLengthA@4' as GetWindowTextLengthA:dword
    extrn '__imp__GetWindowTextLengthW@4' as GetWindowTextLengthW:dword
    extrn '__imp__GetWindowTextW@12' as GetWindowTextW:dword
    extrn '__imp__GetWindowThreadProcessId@8' as GetWindowThreadProcessId:dword
    extrn '__imp__GetWindowWord@8' as GetWindowWord:dword
    extrn '__imp__GrayStringA@36' as GrayStringA:dword
    extrn '__imp__GrayStringW@36' as GrayStringW:dword
    extrn '__imp__HideCaret@4' as HideCaret:dword
    extrn '__imp__HiliteMenuItem@16' as HiliteMenuItem:dword
    extrn '__imp__ImpersonateDdeClientWindow@8' as ImpersonateDdeClientWindow:dword
    extrn '__imp__InflateRect@12' as InflateRect:dword
    extrn '__imp__InSendMessage@0' as InSendMessage:dword
    extrn '__imp__InsertMenuA@20' as InsertMenuA:dword
    extrn '__imp__InsertMenuItemA@16' as InsertMenuItemA:dword
    extrn '__imp__InsertMenuItemW@16' as InsertMenuItemW:dword
    extrn '__imp__InsertMenuW@20' as InsertMenuW:dword
    extrn '__imp__InternalGetWindowText@12' as InternalGetWindowText:dword
    extrn '__imp__IntersectRect@12' as IntersectRect:dword
    extrn '__imp__InvalidateRect@12' as InvalidateRect:dword
    extrn '__imp__InvalidateRgn@12' as InvalidateRgn:dword
    extrn '__imp__InvertRect@8' as InvertRect:dword
    extrn '__imp__IsCharAlphaA@4' as IsCharAlphaA:dword
    extrn '__imp__IsCharAlphaNumericA@4' as IsCharAlphaNumericA:dword
    extrn '__imp__IsCharAlphaNumericW@4' as IsCharAlphaNumericW:dword
    extrn '__imp__IsCharAlphaW@4' as IsCharAlphaW:dword
    extrn '__imp__IsCharLowerA@4' as IsCharLowerA:dword
    extrn '__imp__IsCharLowerW@4' as IsCharLowerW:dword
    extrn '__imp__IsCharUpperA@4' as IsCharUpperA:dword
    extrn '__imp__IsCharUpperW@4' as IsCharUpperW:dword
    extrn '__imp__IsChild@8' as IsChild:dword
    extrn '__imp__IsClipboardFormatAvailable@4' as IsClipboardFormatAvailable:dword
    extrn '__imp__IsDialogMessageA@8' as IsDialogMessageA:dword
    extrn '__imp__IsDialogMessageW@8' as IsDialogMessageW:dword
    extrn '__imp__IsDlgButtonChecked@8' as IsDlgButtonChecked:dword
    extrn '__imp__IsIconic@4' as IsIconic:dword
    extrn '__imp__IsMenu@4' as IsMenu:dword
    extrn '__imp__IsRectEmpty@4' as IsRectEmpty:dword
    extrn '__imp__IsWindow@4' as IsWindow:dword
    extrn '__imp__IsWindowEnabled@4' as IsWindowEnabled:dword
    extrn '__imp__IsWindowUnicode@4' as IsWindowUnicode:dword
    extrn '__imp__IsWindowVisible@4' as IsWindowVisible:dword
    extrn '__imp__IsZoomed@4' as IsZoomed:dword
    extrn '__imp__KillTimer@8' as KillTimer:dword
    extrn '__imp__LoadAcceleratorsA@8' as LoadAcceleratorsA:dword
    extrn '__imp__LoadAcceleratorsW@8' as LoadAcceleratorsW:dword
    extrn '__imp__LoadBitmapA@8' as LoadBitmapA:dword
    extrn '__imp__LoadBitmapW@8' as LoadBitmapW:dword
    extrn '__imp__LoadCursorA@8' as LoadCursorA:dword
    extrn '__imp__LoadCursorFromFileA@4' as LoadCursorFromFileA:dword
    extrn '__imp__LoadCursorFromFileW@4' as LoadCursorFromFileW:dword
    extrn '__imp__LoadCursorW@8' as LoadCursorW:dword
    extrn '__imp__LoadIconA@8' as LoadIconA:dword
    extrn '__imp__LoadIconW@8' as LoadIconW:dword
    extrn '__imp__LoadImageA@24' as LoadImageA:dword
    extrn '__imp__LoadImageW@24' as LoadImageW:dword
    extrn '__imp__LoadKeyboardLayoutA@8' as LoadKeyboardLayoutA:dword
    extrn '__imp__LoadKeyboardLayoutW@8' as LoadKeyboardLayoutW:dword
    extrn '__imp__LoadMenuA@8' as LoadMenuA:dword
    extrn '__imp__LoadMenuIndirectA@4' as LoadMenuIndirectA:dword
    extrn '__imp__LoadMenuIndirectW@4' as LoadMenuIndirectW:dword
    extrn '__imp__LoadMenuW@8' as LoadMenuW:dword
    extrn '__imp__LoadStringA@16' as LoadStringA:dword
    extrn '__imp__LoadStringW@16' as LoadStringW:dword
    extrn '__imp__LockWindowUpdate@4' as LockWindowUpdate:dword
    extrn '__imp__LookupIconIdFromDirectory@8' as LookupIconIdFromDirectory:dword
    extrn '__imp__LookupIconIdFromDirectoryEx@20' as LookupIconIdFromDirectoryEx:dword
    extrn '__imp__MapDialogRect@8' as MapDialogRect:dword
    extrn '__imp__MapVirtualKeyA@8' as MapVirtualKeyA:dword
    extrn '__imp__MapVirtualKeyExA@12' as MapVirtualKeyExA:dword
    extrn '__imp__MapVirtualKeyExW@12' as MapVirtualKeyExW:dword
    extrn '__imp__MapVirtualKeyW@8' as MapVirtualKeyW:dword
    extrn '__imp__MapWindowPoints@16' as MapWindowPoints:dword
    extrn '__imp__MenuItemFromPoint@16' as MenuItemFromPoint:dword
    extrn '__imp__MessageBeep@4' as MessageBeep:dword
    extrn '__imp__MessageBoxA@16' as MessageBoxA:dword
    extrn '__imp__MessageBoxExA@20' as MessageBoxExA:dword
    extrn '__imp__MessageBoxExW@20' as MessageBoxExW:dword
    extrn '__imp__MessageBoxIndirectA@4' as MessageBoxIndirectA:dword
    extrn '__imp__MessageBoxIndirectW@4' as MessageBoxIndirectW:dword
    extrn '__imp__MessageBoxW@16' as MessageBoxW:dword
    extrn '__imp__ModifyMenuA@20' as ModifyMenuA:dword
    extrn '__imp__ModifyMenuW@20' as ModifyMenuW:dword
    extrn '__imp__MoveWindow@24' as MoveWindow:dword
    extrn '__imp__MsgWaitForMultipleObjects@20' as MsgWaitForMultipleObjects:dword
    extrn '__imp__OemKeyScan@4' as OemKeyScan:dword
    extrn '__imp__OemToCharA@8' as OemToCharA:dword
    extrn '__imp__OemToCharBuffA@12' as OemToCharBuffA:dword
    extrn '__imp__OemToCharBuffW@12' as OemToCharBuffW:dword
    extrn '__imp__OemToCharW@8' as OemToCharW:dword
    extrn '__imp__OffsetRect@12' as OffsetRect:dword
    extrn '__imp__OpenClipboard@4' as OpenClipboard:dword
    extrn '__imp__OpenDesktopA@16' as OpenDesktopA:dword
    extrn '__imp__OpenDesktopW@16' as OpenDesktopW:dword
    extrn '__imp__OpenIcon@4' as OpenIcon:dword
    extrn '__imp__OpenInputDesktop@12' as OpenInputDesktop:dword
    extrn '__imp__OpenWindowStationA@12' as OpenWindowStationA:dword
    extrn '__imp__OpenWindowStationW@12' as OpenWindowStationW:dword
    extrn '__imp__PackDDElParam@12' as PackDDElParam:dword
    extrn '__imp__PaintDesktop@4' as PaintDesktop:dword
    extrn '__imp__PeekMessageA@20' as PeekMessageA:dword
    extrn '__imp__PeekMessageW@20' as PeekMessageW:dword
    extrn '__imp__PostMessageA@16' as PostMessageA:dword
    extrn '__imp__PostMessageW@16' as PostMessageW:dword
    extrn '__imp__PostQuitMessage@4' as PostQuitMessage:dword
    extrn '__imp__PostThreadMessageA@16' as PostThreadMessageA:dword
    extrn '__imp__PostThreadMessageW@16' as PostThreadMessageW:dword
    extrn '__imp__PtInRect@12' as PtInRect:dword
    extrn '__imp__RedrawWindow@16' as RedrawWindow:dword
    extrn '__imp__RegisterClassA@4' as RegisterClassA:dword
    extrn '__imp__RegisterClassExA@4' as RegisterClassExA:dword
    extrn '__imp__RegisterClassExW@4' as RegisterClassExW:dword
    extrn '__imp__RegisterClassW@4' as RegisterClassW:dword
    extrn '__imp__RegisterClipboardFormatA@4' as RegisterClipboardFormatA:dword
    extrn '__imp__RegisterClipboardFormatW@4' as RegisterClipboardFormatW:dword
    extrn '__imp__RegisterHotKey@16' as RegisterHotKey:dword
    extrn '__imp__RegisterWindowMessageA@4' as RegisterWindowMessageA:dword
    extrn '__imp__RegisterWindowMessageW@4' as RegisterWindowMessageW:dword
    extrn '__imp__ReleaseCapture@0' as ReleaseCapture:dword
    extrn '__imp__ReleaseDC@8' as ReleaseDC:dword
    extrn '__imp__RemoveMenu@12' as RemoveMenu:dword
    extrn '__imp__RemovePropA@8' as RemovePropA:dword
    extrn '__imp__RemovePropW@8' as RemovePropW:dword
    extrn '__imp__ReplyMessage@4' as ReplyMessage:dword
    extrn '__imp__ReuseDDElParam@20' as ReuseDDElParam:dword
    extrn '__imp__ScreenToClient@8' as ScreenToClient:dword
    extrn '__imp__ScrollDC@28' as ScrollDC:dword
    extrn '__imp__ScrollWindow@20' as ScrollWindow:dword
    extrn '__imp__ScrollWindowEx@32' as ScrollWindowEx:dword
    extrn '__imp__SendDlgItemMessageA@20' as SendDlgItemMessageA:dword
    extrn '__imp__SendDlgItemMessageW@20' as SendDlgItemMessageW:dword
    extrn '__imp__SendMessageA@16' as SendMessageA:dword
    extrn '__imp__SendMessageCallbackA@24' as SendMessageCallbackA:dword
    extrn '__imp__SendMessageCallbackW@24' as SendMessageCallbackW:dword
    extrn '__imp__SendMessageTimeoutA@28' as SendMessageTimeoutA:dword
    extrn '__imp__SendMessageTimeoutW@28' as SendMessageTimeoutW:dword
    extrn '__imp__SendMessageW@16' as SendMessageW:dword
    extrn '__imp__SendNotifyMessageA@16' as SendNotifyMessageA:dword
    extrn '__imp__SendNotifyMessageW@16' as SendNotifyMessageW:dword
    extrn '__imp__SetActiveWindow@4' as SetActiveWindow:dword
    extrn '__imp__SetCapture@4' as SetCapture:dword
    extrn '__imp__SetCaretBlinkTime@4' as SetCaretBlinkTime:dword
    extrn '__imp__SetCaretPos@8' as SetCaretPos:dword
    extrn '__imp__SetClassLongA@12' as SetClassLongA:dword
    extrn '__imp__SetClassLongW@12' as SetClassLongW:dword
    extrn '__imp__SetClassWord@12' as SetClassWord:dword
    extrn '__imp__SetClipboardData@8' as SetClipboardData:dword
    extrn '__imp__SetClipboardViewer@4' as SetClipboardViewer:dword
    extrn '__imp__SetCursor@4' as SetCursor:dword
    extrn '__imp__SetCursorPos@8' as SetCursorPos:dword
    extrn '__imp__SetDebugErrorLevel@4' as SetDebugErrorLevel:dword
    extrn '__imp__SetDlgItemInt@16' as SetDlgItemInt:dword
    extrn '__imp__SetDlgItemTextA@12' as SetDlgItemTextA:dword
    extrn '__imp__SetDlgItemTextW@12' as SetDlgItemTextW:dword
    extrn '__imp__SetDoubleClickTime@4' as SetDoubleClickTime:dword
    extrn '__imp__SetFocus@4' as SetFocus:dword
    extrn '__imp__SetForegroundWindow@4' as SetForegroundWindow:dword
    extrn '__imp__SetKeyboardState@4' as SetKeyboardState:dword
    extrn '__imp__SetLastErrorEx@8' as SetLastErrorEx:dword
    extrn '__imp__SetMenu@8' as SetMenu:dword
    extrn '__imp__SetMenuContextHelpId@8' as SetMenuContextHelpId:dword
    extrn '__imp__SetMenuDefaultItem@12' as SetMenuDefaultItem:dword
    extrn '__imp__SetMenuItemBitmaps@20' as SetMenuItemBitmaps:dword
    extrn '__imp__SetMenuItemInfoA@16' as SetMenuItemInfoA:dword
    extrn '__imp__SetMenuItemInfoW@16' as SetMenuItemInfoW:dword
    extrn '__imp__SetMessageExtraInfo@4' as SetMessageExtraInfo:dword
    extrn '__imp__SetMessageQueue@4' as SetMessageQueue:dword
    extrn '__imp__SetParent@8' as SetParent:dword
    extrn '__imp__SetProcessWindowStation@4' as SetProcessWindowStation:dword
    extrn '__imp__SetPropA@12' as SetPropA:dword
    extrn '__imp__SetPropW@12' as SetPropW:dword
    extrn '__imp__SetRect@20' as SetRect:dword
    extrn '__imp__SetRectEmpty@4' as SetRectEmpty:dword
    extrn '__imp__SetScrollInfo@16' as SetScrollInfo:dword
    extrn '__imp__SetScrollPos@16' as SetScrollPos:dword
    extrn '__imp__SetScrollRange@20' as SetScrollRange:dword
    extrn '__imp__SetShellWindow@4' as SetShellWindow:dword
    extrn '__imp__SetSysColors@12' as SetSysColors:dword
    extrn '__imp__SetSystemCursor@8' as SetSystemCursor:dword
    extrn '__imp__SetThreadDesktop@4' as SetThreadDesktop:dword
    extrn '__imp__SetTimer@16' as SetTimer:dword
    extrn '__imp__SetUserObjectInformationA@16' as SetUserObjectInformationA:dword
    extrn '__imp__SetUserObjectInformationW@16' as SetUserObjectInformationW:dword
    extrn '__imp__SetUserObjectSecurity@12' as SetUserObjectSecurity:dword
    extrn '__imp__SetWindowContextHelpId@8' as SetWindowContextHelpId:dword
    extrn '__imp__SetWindowLongA@12' as SetWindowLongA:dword
    extrn '__imp__SetWindowLongW@12' as SetWindowLongW:dword
    extrn '__imp__SetWindowPlacement@8' as SetWindowPlacement:dword
    extrn '__imp__SetWindowPos@28' as SetWindowPos:dword
    extrn '__imp__SetWindowRgn@12' as SetWindowRgn:dword
    extrn '__imp__SetWindowsHookA@8' as SetWindowsHookA:dword
    extrn '__imp__SetWindowsHookExA@16' as SetWindowsHookExA:dword
    extrn '__imp__SetWindowsHookExW@16' as SetWindowsHookExW:dword
    extrn '__imp__SetWindowsHookW@8' as SetWindowsHookW:dword
    extrn '__imp__SetWindowTextA@8' as SetWindowTextA:dword
    extrn '__imp__SetWindowTextW@8' as SetWindowTextW:dword
    extrn '__imp__SetWindowWord@12' as SetWindowWord:dword
    extrn '__imp__ShowCaret@4' as ShowCaret:dword
    extrn '__imp__ShowCursor@4' as ShowCursor:dword
    extrn '__imp__ShowOwnedPopups@8' as ShowOwnedPopups:dword
    extrn '__imp__ShowScrollBar@12' as ShowScrollBar:dword
    extrn '__imp__ShowWindow@8' as ShowWindow:dword
    extrn '__imp__ShowWindowAsync@8' as ShowWindowAsync:dword
    extrn '__imp__SubtractRect@12' as SubtractRect:dword
    extrn '__imp__SwapMouseButton@4' as SwapMouseButton:dword
    extrn '__imp__SwitchDesktop@4' as SwitchDesktop:dword
    extrn '__imp__SwitchToThisWindow@8' as SwitchToThisWindow:dword
    extrn '__imp__SystemParametersInfoA@16' as SystemParametersInfoA:dword
    extrn '__imp__SystemParametersInfoW@16' as SystemParametersInfoW:dword
    extrn '__imp__TabbedTextOutA@32' as TabbedTextOutA:dword
    extrn '__imp__TabbedTextOutW@32' as TabbedTextOutW:dword
    extrn '__imp__TileChildWindows@8' as TileChildWindows:dword
    extrn '__imp__TileWindows@20' as TileWindows:dword
    extrn '__imp__ToAscii@20' as ToAscii:dword
    extrn '__imp__ToAsciiEx@24' as ToAsciiEx:dword
    extrn '__imp__ToUnicode@24' as ToUnicode:dword
    extrn '__imp__TrackPopupMenu@28' as TrackPopupMenu:dword
    extrn '__imp__TrackPopupMenuEx@24' as TrackPopupMenuEx:dword
    extrn '__imp__TranslateAcceleratorA@12' as TranslateAcceleratorA:dword
    extrn '__imp__TranslateAcceleratorW@12' as TranslateAcceleratorW:dword
    extrn '__imp__TranslateMDISysAccel@8' as TranslateMDISysAccel:dword
    extrn '__imp__TranslateMessage@4' as TranslateMessage:dword
    extrn '__imp__UnhookWindowsHook@8' as UnhookWindowsHook:dword
    extrn '__imp__UnhookWindowsHookEx@4' as UnhookWindowsHookEx:dword
    extrn '__imp__UnionRect@12' as UnionRect:dword
    extrn '__imp__UnloadKeyboardLayout@4' as UnloadKeyboardLayout:dword
    extrn '__imp__UnpackDDElParam@16' as UnpackDDElParam:dword
    extrn '__imp__UnregisterClassA@8' as UnregisterClassA:dword
    extrn '__imp__UnregisterClassW@8' as UnregisterClassW:dword
    extrn '__imp__UnregisterHotKey@8' as UnregisterHotKey:dword
    extrn '__imp__UpdateWindow@4' as UpdateWindow:dword
    extrn '__imp__ValidateRect@8' as ValidateRect:dword
    extrn '__imp__ValidateRgn@8' as ValidateRgn:dword
    extrn '__imp__VkKeyScanA@4' as VkKeyScanA:dword
    extrn '__imp__VkKeyScanExA@8' as VkKeyScanExA:dword
    extrn '__imp__VkKeyScanExW@8' as VkKeyScanExW:dword
    extrn '__imp__VkKeyScanW@4' as VkKeyScanW:dword
    extrn '__imp__WaitForInputIdle@8' as WaitForInputIdle:dword
    extrn '__imp__WaitMessage@0' as WaitMessage:dword
    extrn '__imp__WindowFromDC@4' as WindowFromDC:dword
    extrn '__imp__WindowFromPoint@8' as WindowFromPoint:dword
    extrn '__imp__WinHelpA@16' as WinHelpA:dword
    extrn '__imp__WinHelpW@16' as WinHelpW:dword
    extrn '__imp__keybd_event@16' as keybd_event:dword
    extrn '__imp__mouse_event@20' as mouse_event:dword
    extrn '__imp__wsprintfA' as wsprintfA:dword
    extrn '__imp__wsprintfW' as wsprintfW:dword
    extrn '__imp__wvsprintfA@12' as wvsprintfA:dword
    extrn '__imp__wvsprintfW@12' as wvsprintfW:dword

    if (NTDDI_VERSION <> NTDDI_WINNT4)
        extrn '__imp__UnhookWinEvent@4' as UnhookWinEvent:dword
        extrn '__imp__WINNLSEnableIME@8' as WINNLSEnableIME:dword
    end if

    if (NTDDI_VERSION >= NTDDI_WIN98_ME)
        extrn '__imp__BlockInput@4' as BlockInput:dword
        extrn '__imp__ChangeDisplaySettingsExA@20' as ChangeDisplaySettingsExA:dword
        extrn '__imp__ChangeDisplaySettingsExW@20' as ChangeDisplaySettingsExW:dword
        extrn '__imp__EndMenu@0' as EndMenu:dword
        extrn '__imp__EnumDisplayMonitors@16' as EnumDisplayMonitors:dword
        extrn '__imp__EnumDisplaySettingsExA@16' as EnumDisplaySettingsExA:dword
        extrn '__imp__EnumDisplaySettingsExW@16' as EnumDisplaySettingsExW:dword
        extrn '__imp__FlashWindowEx@4' as FlashWindowEx:dword
        extrn '__imp__GetAncestor@8' as GetAncestor:dword
        extrn '__imp__GetClipboardSequenceNumber@0' as GetClipboardSequenceNumber:dword
        extrn '__imp__GetComboBoxInfo@8' as GetComboBoxInfo:dword
        extrn '__imp__GetCursorInfo@4' as GetCursorInfo:dword
        extrn '__imp__GetGUIThreadInfo@8' as GetGUIThreadInfo:dword
        extrn '__imp__GetListBoxInfo@4' as GetListBoxInfo:dword
        extrn '__imp__GetMenuBarInfo@16' as GetMenuBarInfo:dword
        extrn '__imp__GetMenuInfo@8' as GetMenuInfo:dword
        extrn '__imp__GetProcessDefaultLayout@4' as GetProcessDefaultLayout:dword
        extrn '__imp__GetScrollBarInfo@12' as GetScrollBarInfo:dword
        extrn '__imp__GetTitleBarInfo@8' as GetTitleBarInfo:dword
        extrn '__imp__GetWindowInfo@8' as GetWindowInfo:dword
        extrn '__imp__GetWindowModuleFileName@12' as GetWindowModuleFileName:dword
        extrn '__imp__GetWindowModuleFileNameA@12' as GetWindowModuleFileNameA:dword
        extrn '__imp__GetWindowModuleFileNameW@12' as GetWindowModuleFileNameW:dword
        extrn '__imp__IMPGetIMEA@8' as IMPGetIMEA:dword
        extrn '__imp__IMPGetIMEW@8' as IMPGetIMEW:dword
        extrn '__imp__IMPQueryIMEA@4' as IMPQueryIMEA:dword
        extrn '__imp__IMPQueryIMEW@4' as IMPQueryIMEW:dword
        extrn '__imp__IMPSetIMEA@8' as IMPSetIMEA:dword
        extrn '__imp__IMPSetIMEW@8' as IMPSetIMEW:dword
        extrn '__imp__MsgWaitForMultipleObjectsEx@20' as MsgWaitForMultipleObjectsEx:dword
        extrn '__imp__NotifyWinEvent@16' as NotifyWinEvent:dword
        extrn '__imp__RealChildWindowFromPoint@12' as RealChildWindowFromPoint:dword
        extrn '__imp__SendIMEMessageExA@8' as SendIMEMessageExA:dword
        extrn '__imp__SendIMEMessageExW@8' as SendIMEMessageExW:dword
        extrn '__imp__SendInput@12' as SendInput:dword
        extrn '__imp__SetWinEventHook@28' as SetWinEventHook:dword
        extrn '__imp__ToUnicodeEx@28' as ToUnicodeEx:dword
        extrn '__imp__TrackMouseEvent@4' as TrackMouseEvent:dword

        if (NTDDI_VERSION <> NTDDI_WINNT4)
            extrn '__imp__GetMonitorInfoA@8' as GetMonitorInfoA:dword
            extrn '__imp__GetMonitorInfoW@8' as GetMonitorInfoW:dword
            extrn '__imp__InSendMessageEx@4' as InSendMessageEx:dword
            extrn '__imp__MonitorFromPoint@12' as MonitorFromPoint:dword
            extrn '__imp__MonitorFromRect@8' as MonitorFromRect:dword
            extrn '__imp__MonitorFromWindow@8' as MonitorFromWindow:dword
            extrn '__imp__RegisterDeviceNotificationA@12' as RegisterDeviceNotificationA:dword
            extrn '__imp__RegisterDeviceNotificationW@12' as RegisterDeviceNotificationW:dword
            extrn '__imp__SetMenuInfo@8' as SetMenuInfo:dword
            extrn '__imp__SetProcessDefaultLayout@4' as SetProcessDefaultLayout:dword
            extrn '__imp__UnregisterDeviceNotification@4' as UnregisterDeviceNotification:dword
            api GetMonitorInfo,\
                RegisterDeviceNotification
        end if

        api ChangeDisplaySettingsEx,\
            EnumDisplaySettingsEx,\
            IMPGetIME,\
            IMPQueryIME,\
            IMPSetIME,\
            SendIMEMessageEx
    end if

    if (NTDDI_VERSION >= NTDDI_WINNT4)
        extrn '__imp__ClientThreadSetup@0' as ClientThreadSetup:dword
        extrn '__imp__CreateDialogIndirectParamAorW@24' as CreateDialogIndirectParamAorW:dword
        extrn '__imp__DdeGetQualityOfService@12' as DdeGetQualityOfService:dword
        extrn '__imp__DeregisterShellHookWindow@4' as DeregisterShellHookWindow:dword
        extrn '__imp__DrawMenuBarTemp@20' as DrawMenuBarTemp:dword
        extrn '__imp__GetAppCompatFlags@4' as GetAppCompatFlags:dword
        extrn '__imp__GetProgmanWindow@0' as GetProgmanWindow:dword
        extrn '__imp__GetTaskmanWindow@0' as GetTaskmanWindow:dword
        extrn '__imp__IsHungAppWindow@4' as IsHungAppWindow:dword
        extrn '__imp__LoadKeyboardLayoutEx@12' as LoadKeyboardLayoutEx:dword
        extrn '__imp__LoadLocalFonts@0' as LoadLocalFonts:dword
        extrn '__imp__LoadRemoteFonts@0' as LoadRemoteFonts:dword
        extrn '__imp__MBToWCSEx@24' as MBToWCSEx:dword
        extrn '__imp__MB_GetString@4' as MB_GetString:dword
        extrn '__imp__MenuWindowProcA@20' as MenuWindowProcA:dword
        extrn '__imp__MenuWindowProcW@20' as MenuWindowProcW:dword
        extrn '__imp__PrivateExtractIconExA@20' as PrivateExtractIconExA:dword
        extrn '__imp__PrivateExtractIconExW@20' as PrivateExtractIconExW:dword
        extrn '__imp__PrivateExtractIconsA@32' as PrivateExtractIconsA:dword
        extrn '__imp__PrivateExtractIconsW@32' as PrivateExtractIconsW:dword
        extrn '__imp__QuerySendMessage@4' as QuerySendMessage:dword
        extrn '__imp__RegisterServicesProcess@4' as RegisterServicesProcess:dword
        extrn '__imp__RegisterShellHookWindow@4' as RegisterShellHookWindow:dword
        extrn '__imp__SetProgmanWindow@4' as SetProgmanWindow:dword
        extrn '__imp__SetShellWindowEx@8' as SetShellWindowEx:dword
        extrn '__imp__SetSystemMenu@8' as SetSystemMenu:dword
        extrn '__imp__SetTaskmanWindow@4' as SetTaskmanWindow:dword
        extrn '__imp__SetWindowStationUser@16' as SetWindowStationUser:dword
        extrn '__imp__ShowStartGlass@4' as ShowStartGlass:dword
        extrn '__imp__TranslateMessageEx@8' as TranslateMessageEx:dword
        extrn '__imp__UserRealizePalette@4' as UserRealizePalette:dword
        extrn '__imp__UserRegisterWowHandlers@8' as UserRegisterWowHandlers:dword
        api MenuWindowProc,\
            PrivateExtractIconEx,\
            PrivateExtractIcons
    end if

    if (NTDDI_VERSION >= NTDDI_WIN2K)
        extrn '__imp__CliImmSetHotKey@16' as CliImmSetHotKey:dword
        extrn '__imp__CtxInitUser32@0' as CtxInitUser32:dword
        extrn '__imp__DeviceEventWorker@20' as DeviceEventWorker:dword
        extrn '__imp__GetAppCompatFlags2@4' as GetAppCompatFlags2:dword
        extrn '__imp__GetLastInputInfo@4' as GetLastInputInfo:dword
        extrn '__imp__GetMouseMovePointsEx@20' as GetMouseMovePointsEx:dword
        extrn '__imp__InitializeLpkHooks@4' as InitializeLpkHooks:dword
        extrn '__imp__LockSetForegroundWindow@4' as LockSetForegroundWindow:dword
        extrn '__imp__LockWorkStation@0' as LockWorkStation:dword
        extrn '__imp__SetLayeredWindowAttributes@16' as SetLayeredWindowAttributes:dword
        extrn '__imp__UpdateLayeredWindow@36' as UpdateLayeredWindow:dword
        extrn '__imp__UserHandleGrantAccess@12' as UserHandleGrantAccess:dword
        extrn '__imp__AllowSetForegroundWindow@4' as AllowSetForegroundWindow:dword
        extrn '__imp__AnimateWindow@12' as AnimateWindow:dword
    end if

    if (NTDDI_VERSION >= NTDDI_WINXP)
        extrn '__imp__AllowForegroundActivation@0' as AllowForegroundActivation:dword
        extrn '__imp__BroadcastSystemMessageExA@24' as BroadcastSystemMessageExA:dword
        extrn '__imp__BroadcastSystemMessageExW@24' as BroadcastSystemMessageExW:dword
        extrn '__imp__BuildReasonArray@4' as BuildReasonArray:dword
        extrn '__imp__CreateSystemThreads@4' as CreateSystemThreads:dword
        extrn '__imp__CsrBroadcastSystemMessageExW@20' as CsrBroadcastSystemMessageExW:dword
        extrn '__imp__DefRawInputProc@12' as DefRawInputProc:dword
        extrn '__imp__DestroyReasons@4' as DestroyReasons:dword
        extrn '__imp__DisableProcessWindowsGhosting@0' as DisableProcessWindowsGhosting:dword
        extrn '__imp__GetLayeredWindowAttributes@16' as GetLayeredWindowAttributes:dword
        extrn '__imp__GetRawInputBuffer@12' as GetRawInputBuffer:dword
        extrn '__imp__GetRawInputData@20' as GetRawInputData:dword
        extrn '__imp__GetRawInputDeviceInfoA@16' as GetRawInputDeviceInfoA:dword
        extrn '__imp__GetRawInputDeviceInfoW@16' as GetRawInputDeviceInfoW:dword
        extrn '__imp__GetRawInputDeviceList@12' as GetRawInputDeviceList:dword
        extrn '__imp__GetReasonTitleFromReasonCode@12' as GetReasonTitleFromReasonCode:dword
        extrn '__imp__GetRegisteredRawInputDevices@12' as GetRegisteredRawInputDevices:dword
        extrn '__imp__GetWindowRgnBox@8' as GetWindowRgnBox:dword
        extrn '__imp__IsGUIThread@4' as IsGUIThread:dword
        if (NTDDI_VERSION < NTDDI_WINXPALL)
            extrn '__imp__IsProcess16Bit@0' as IsProcess16Bit:dword
            extrn '__imp__SetLogonNotifyWindow@8' as SetLogonNotifyWindow:dword
        end if
        extrn '__imp__IsServerSideWindow@4' as IsServerSideWindow:dword
        extrn '__imp__IsWinEventHookInstalled@4' as IsWinEventHookInstalled:dword
        extrn '__imp__IsWindowInDestroy@4' as IsWindowInDestroy:dword
        extrn '__imp__MessageBoxTimeoutA@24' as MessageBoxTimeoutA:dword
        extrn '__imp__MessageBoxTimeoutW@24' as MessageBoxTimeoutW:dword
        extrn '__imp__PrintWindow@12' as PrintWindow:dword
        extrn '__imp__RecordShutdownReason@4' as RecordShutdownReason:dword
        extrn '__imp__RegisterMessagePumpHook@4' as RegisterMessagePumpHook:dword
        extrn '__imp__RegisterRawInputDevices@12' as RegisterRawInputDevices:dword
        extrn '__imp__RegisterUserApiHook@8' as RegisterUserApiHook:dword
        extrn '__imp__UnregisterMessagePumpHook@0' as UnregisterMessagePumpHook:dword
        extrn '__imp__UnregisterUserApiHook@0' as UnregisterUserApiHook:dword
        api GetRawInputDeviceInfo,\
            MessageBoxTimeout
    end if

    if (NTDDI_VERSION >= NTDDI_WS03SP1)
        extrn '__imp__IsWow64Message@0' as IsWow64Message:dword
    end if

    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__AddClipboardFormatListener@4' as AddClipboardFormatListener:dword
        extrn '__imp__CancelShutdown@0' as CancelShutdown:dword
        extrn '__imp__ChangeWindowMessageFilter@8' as ChangeWindowMessageFilter:dword
        extrn '__imp__CreateDesktopExA@32' as CreateDesktopExA:dword
        extrn '__imp__CreateDesktopExW@32' as CreateDesktopExW:dword
        extrn '__imp__DisplayConfigGetDeviceInfo@4' as DisplayConfigGetDeviceInfo:dword
        extrn '__imp__DisplayConfigSetDeviceInfo@4' as DisplayConfigSetDeviceInfo:dword
        extrn '__imp__FrostCrashedWindow@8' as FrostCrashedWindow:dword
        extrn '__imp__GetIconInfoExA@8' as GetIconInfoExA:dword
        extrn '__imp__GetIconInfoExW@8' as GetIconInfoExW:dword
        extrn '__imp__GetPhysicalCursorPos@4' as GetPhysicalCursorPos:dword
        extrn '__imp__GetSendMessageReceiver@4' as GetSendMessageReceiver:dword
        extrn '__imp__GetUpdatedClipboardFormats@12' as GetUpdatedClipboardFormats:dword
        extrn '__imp__GetWindowMinimizeRect@8' as GetWindowMinimizeRect:dword
        extrn '__imp__GhostWindowFromHungWindow@4' as GhostWindowFromHungWindow:dword
        extrn '__imp__HungWindowFromGhostWindow@4' as HungWindowFromGhostWindow:dword
        extrn '__imp__IsProcessDPIAware@0' as IsProcessDPIAware:dword
        extrn '__imp__IsSETEnabled@0' as IsSETEnabled:dword
        extrn '__imp__IsThreadDesktopComposited@0' as IsThreadDesktopComposited:dword
        extrn '__imp__IsWindowRedirectedForPrint@4' as IsWindowRedirectedForPrint:dword
        extrn '__imp__LogicalToPhysicalPoint@8' as LogicalToPhysicalPoint:dword
        extrn '__imp__PhysicalToLogicalPoint@8' as PhysicalToLogicalPoint:dword
        extrn '__imp__RegisterPowerSettingNotification@12' as RegisterPowerSettingNotification:dword
        extrn '__imp__RemoveClipboardFormatListener@4' as RemoveClipboardFormatListener:dword
        extrn '__imp__SetPhysicalCursorPos@8' as SetPhysicalCursorPos:dword
        extrn '__imp__SetProcessDPIAware@0' as SetProcessDPIAware:dword
        extrn '__imp__ShutdownBlockReasonCreate@8' as ShutdownBlockReasonCreate:dword
        extrn '__imp__ShutdownBlockReasonDestroy@4' as ShutdownBlockReasonDestroy:dword
        extrn '__imp__ShutdownBlockReasonQuery@12' as ShutdownBlockReasonQuery:dword
        extrn '__imp__SoundSentry@0' as SoundSentry:dword
        extrn '__imp__UnregisterPowerSettingNotification@4' as UnregisterPowerSettingNotification:dword
        extrn '__imp__UpdateLayeredWindowIndirect@8' as UpdateLayeredWindowIndirect:dword
        extrn '__imp__UpdateWindowTransform@12' as UpdateWindowTransform:dword
        api CreateDesktopEx,\
            GetIconInfoEx
    end if

    if (NTDDI_VERSION >= NTDDI_WIN7)
        extrn '__imp__CalculatePopupWindowPosition@20' as CalculatePopupWindowPosition:dword
        extrn '__imp__ChangeWindowMessageFilterEx@16' as ChangeWindowMessageFilterEx:dword
        extrn '__imp__CloseGestureInfoHandle@4' as CloseGestureInfoHandle:dword
        extrn '__imp__CloseTouchInputHandle@4' as CloseTouchInputHandle:dword
        extrn '__imp__DwmGetDxSharedSurface@24' as DwmGetDxSharedSurface:dword
        extrn '__imp__GetDisplayConfigBufferSizes@12' as GetDisplayConfigBufferSizes:dword
        extrn '__imp__GetGestureConfig@24' as GetGestureConfig:dword
        extrn '__imp__GetGestureExtraArgs@12' as GetGestureExtraArgs:dword
        extrn '__imp__GetGestureInfo@8' as GetGestureInfo:dword
        extrn '__imp__GetTouchInputInfo@16' as GetTouchInputInfo:dword
        extrn '__imp__GetWindowCompositionAttribute@8' as GetWindowCompositionAttribute:dword
        extrn '__imp__GetWindowDisplayAffinity@8' as GetWindowDisplayAffinity:dword
        extrn '__imp__IsTopLevelWindow@4' as IsTopLevelWindow:dword
        extrn '__imp__IsTouchWindow@8' as IsTouchWindow:dword
        extrn '__imp__QueryDisplayConfig@24' as QueryDisplayConfig:dword
        extrn '__imp__RegisterTouchWindow@8' as RegisterTouchWindow:dword
        extrn '__imp__SetDisplayConfig@20' as SetDisplayConfig:dword
        extrn '__imp__SetGestureConfig@20' as SetGestureConfig:dword
        extrn '__imp__SetWindowCompositionAttribute@8' as SetWindowCompositionAttribute:dword
        extrn '__imp__SetWindowDisplayAffinity@8' as SetWindowDisplayAffinity:dword
        extrn '__imp__UnregisterTouchWindow@4' as UnregisterTouchWindow:dword
    end if

    if (NTDDI_VERSION >= NTDDI_WIN8)
        extrn '__imp__CreateWindowInBand@52' as CreateWindowInBand:dword
        extrn '__imp__EnableMouseInPointer@4' as EnableMouseInPointer:dword
        extrn '__imp__EvaluateProximityToPolygon@16' as EvaluateProximityToPolygon:dword
        extrn '__imp__EvaluateProximityToRect@12' as EvaluateProximityToRect:dword
        extrn '__imp__GetAutoRotationState@4' as GetAutoRotationState:dword
        extrn '__imp__GetCIMSSM@4' as GetCIMSSM:dword
        extrn '__imp__GetCurrentInputMessageSource@4' as GetCurrentInputMessageSource:dword
        extrn '__imp__GetDisplayAutoRotationPreferences@4' as GetDisplayAutoRotationPreferences:dword
        extrn '__imp__GetPointerCursorId@8' as GetPointerCursorId:dword
        extrn '__imp__GetPointerDevice@8' as GetPointerDevice:dword
        extrn '__imp__GetPointerDeviceCursors@12' as GetPointerDeviceCursors:dword
        extrn '__imp__GetPointerDeviceProperties@12' as GetPointerDeviceProperties:dword
        extrn '__imp__GetPointerDeviceRects@12' as GetPointerDeviceRects:dword
        extrn '__imp__GetPointerDevices@8' as GetPointerDevices:dword
        extrn '__imp__GetPointerFrameInfo@12' as GetPointerFrameInfo:dword
        extrn '__imp__GetPointerFrameInfoHistory@16' as GetPointerFrameInfoHistory:dword
        extrn '__imp__GetPointerFramePenInfo@12' as GetPointerFramePenInfo:dword
        extrn '__imp__GetPointerFramePenInfoHistory@16' as GetPointerFramePenInfoHistory:dword
        extrn '__imp__GetPointerFrameTouchInfo@12' as GetPointerFrameTouchInfo:dword
        extrn '__imp__GetPointerFrameTouchInfoHistory@16' as GetPointerFrameTouchInfoHistory:dword
        extrn '__imp__GetPointerInfo@8' as GetPointerInfo:dword
        extrn '__imp__GetPointerInfoHistory@12' as GetPointerInfoHistory:dword
        extrn '__imp__GetPointerPenInfo@8' as GetPointerPenInfo:dword
        extrn '__imp__GetPointerPenInfoHistory@12' as GetPointerPenInfoHistory:dword
        extrn '__imp__GetPointerTouchInfo@8' as GetPointerTouchInfo:dword
        extrn '__imp__GetPointerTouchInfoHistory@12' as GetPointerTouchInfoHistory:dword
        extrn '__imp__GetPointerType@8' as GetPointerType:dword
        extrn '__imp__GetRawPointerDeviceData@20' as GetRawPointerDeviceData:dword
        extrn '__imp__GetUnpredictedMessagePos@0' as GetUnpredictedMessagePos:dword
        extrn '__imp__GetWindowFeedbackSetting@20' as GetWindowFeedbackSetting:dword
        extrn '__imp__InitializeTouchInjection@8' as InitializeTouchInjection:dword
        extrn '__imp__InjectTouchInput@8' as InjectTouchInput:dword
        extrn '__imp__IsImmersiveProcess@4' as IsImmersiveProcess:dword
        extrn '__imp__IsMouseInPointerEnabled@0' as IsMouseInPointerEnabled:dword
        extrn '__imp__PackTouchHitTestingProximityEvaluation@8' as PackTouchHitTestingProximityEvaluation:dword
        extrn '__imp__RegisterPointerDeviceNotifications@8' as RegisterPointerDeviceNotifications:dword
        extrn '__imp__RegisterPointerInputTarget@8' as RegisterPointerInputTarget:dword
        extrn '__imp__RegisterSuspendResumeNotification@8' as RegisterSuspendResumeNotification:dword
        extrn '__imp__RegisterTouchHitTestingWindow@8' as RegisterTouchHitTestingWindow:dword
        extrn '__imp__SetCoalescableTimer@20' as SetCoalescableTimer:dword
        extrn '__imp__SetDisplayAutoRotationPreferences@4' as SetDisplayAutoRotationPreferences:dword
        extrn '__imp__SetProcessRestrictionExemption@4' as SetProcessRestrictionExemption:dword
        extrn '__imp__SetWindowFeedbackSetting@20' as SetWindowFeedbackSetting:dword
        extrn '__imp__ShowSystemCursor@4' as ShowSystemCursor:dword
        extrn '__imp__SkipPointerFrameMessages@4' as SkipPointerFrameMessages:dword
        extrn '__imp__UnregisterPointerInputTarget@8' as UnregisterPointerInputTarget:dword
        extrn '__imp__UnregisterSuspendResumeNotification@4' as UnregisterSuspendResumeNotification:dword
    end if

    if (NTDDI_VERSION >= NTDDI_WIN81)
        extrn '__imp__PhysicalToLogicalPointForPerMonitorDPI@8' as PhysicalToLogicalPointForPerMonitorDPI:dword
    end if

api AppendMenu,\
    CallMsgFilter,\
    CallWindowProc,\
    ChangeDisplaySettings,\
    ChangeMenu,\
    CharLower,\
    CharNext,\
    CharPrev,\
    CharToOem,\
    CharToOemBuff,\
    CharUpper,\
    CharUpperBuff,\
    CopyAcceleratorTable,\
    CreateAcceleratorTable,\
    CreateDesktop,\
    CreateDialogIndirectParam,\
    CreateDialogParam,\
    CreateMDIWindow,\
    CreateWindowEx,\
    CreateWindowStation,\
    DdeCreateStringHandle,\
    DdeInitialize,\
    DdeQueryString,\
    DefDlgProc,\
    DefFrameProc,\
    DefMDIChildProc,\
    DefWindowProc,\
    DialogBoxIndirectParam,\
    DialogBoxParam,\
    DispatchMessage,\
    DlgDirList,\
    DlgDirListComboBox,\
    DlgDirSelectComboBoxEx,\
    DlgDirSelectEx,\
    DrawState,\
    DrawText,\
    DrawTextEx,\
    EnumDesktops,\
    EnumDisplayDevices,\
    EnumDisplaySettings,\
    EnumProps,\
    EnumPropsEx,\
    EnumWindowStations,\
    FindWindow,\
    FindWindowEx,\
    GetAltTabInfo,\
    GetClassInfo,\
    GetClassInfoEx,\
    GetClassLong,\
    GetClassName,\
    GetClipboardFormatName,\
    GetDlgItemText,\
    GetKeyboardLayoutName,\
    GetKeyNameText,\
    GetMenuItemInfo,\
    GetMenuString,\
    GetMessage,\
    GetProp,\
    GetTabbedTextExtent,\
    GetUserObjectInformation,\
    GetWindowLong,\
    GetWindowText,\
    GetWindowTextLength,\
    GrayString,\
    InsertMenu,\
    InsertMenuItem,\
    IsCharAlpha,\
    IsCharAlphaNumeric,\
    IsCharLower,\
    IsCharUpper,\
    IsDialogMessage,\
    LoadAccelerators,\
    LoadBitmap,\
    LoadCursor,\
    LoadCursorFromFile,\
    LoadIcon,\
    LoadImage,\
    LoadKeyboardLayout,\
    LoadMenu,\
    LoadMenuIndirect,\
    LoadString,\
    MapVirtualKey,\
    MapVirtualKeyEx,\
    MessageBox,\
    MessageBoxEx,\
    MessageBoxIndirect,\
    ModifyMenu,\
    OemToChar,\
    OemToCharBuff,\
    OpenDesktop,\
    OpenWindowStation,\
    PeekMessage,\
    PostAppMessage,\
    PostMessage,\
    PostThreadMessage,\
    RegisterClass,\
    RegisterClassEx,\
    RegisterClipboardFormat,\
    RegisterWindowMessage,\
    RemoveProp,\
    SendDlgItemMessage,\
    SendMessage,\
    SendMessageCallback,\
    SendMessageTimeout,\
    SendNotifyMessage,\
    SetClassLong,\
    SetDlgItemText,\
    SetMenuItemInfo,\
    SetProp,\
    SetUserObjectInformation,\
    SetWindowLong,\
    SetWindowsHook,\
    SetWindowsHookEx,\
    SetWindowText,\
    SystemParametersInfo,\
    TabbedTextOut,\
    TranslateAccelerator,\
    UnregisterClass,\
    VkKeyScan,\
    VkKeyScanEx,\
    WinHelp,\
    wsprintf,\
    wvsprintf

    PostAppMessage equ PostThreadMessage
    PostAppMessageA equ PostThreadMessageA
    PostAppMessageW equ PostThreadMessageW
    AnsiToOem equ CharToOemA
    OemToAnsi equ OemToCharA
    AnsiToOemBuff equ CharToOemBuffA
    OemToAnsiBuff equ OemToCharBuffA
    AnsiUpper equ CharUpperA
    AnsiUpperBuff equ CharUpperBuffA
    AnsiLower equ CharLowerA
    AnsiLowerBuff equ CharLowerBuffA
    AnsiNext equ CharNextA
    AnsiPrev equ CharPrevA

    GetClassLongPtr equ GetClassLong
    GetWindowLongPtr equ GetWindowLong
    SetClassLongPtr equ SetClassLong
    SetWindowLongPtr equ SetWindowLong
    GetClassLongPtrA equ GetClassLongA
    GetWindowLongPtrA equ GetWindowLongA
    SetClassLongPtrA equ SetClassLongA
    SetWindowLongPtrA equ SetWindowLongA
end if

;======================= Undocumented functions (unknown arguments) =======================;
;if defined APP_WIN64
;    extrn '__imp_AlignRects' as AlignRects:qword
;    extrn '__imp_CalcMenuBar' as CalcMenuBar:qword
;    extrn '__imp_CheckDBCSEnabledExt' as CheckDBCSEnabledExt:qword
;    extrn '__imp_CheckDesktopByThreadId' as CheckDesktopByThreadId:qword
;    extrn '__imp_CheckProcessForClipboardAccess' as CheckProcessForClipboardAccess:qword
;    extrn '__imp_CheckProcessSession' as CheckProcessSession:qword
;    extrn '__imp_CheckWindowThreadDesktop' as CheckWindowThreadDesktop:qword
;    extrn '__imp_ConsoleControl' as ConsoleControl:qword
;    extrn '__imp_ControlMagnification' as ControlMagnification:qword
;    extrn '__imp_CreateDCompositionHwndTarget' as CreateDCompositionHwndTarget:qword
;    extrn '__imp_CreateWindowInBandEx' as CreateWindowInBandEx:qword
;    extrn '__imp_CreateWindowIndirect' as CreateWindowIndirect:qword
;    extrn '__imp_DeferWindowPosAndBand' as DeferWindowPosAndBand:qword
;    extrn '__imp_DestroyDCompositionHwndTarget' as DestroyDCompositionHwndTarget:qword
;    extrn '__imp_DialogBoxIndirectParamAorW' as DialogBoxIndirectParamAorW:qword
;    extrn '__imp_DisplayExitWindowsWarnings' as DisplayExitWindowsWarnings:qword
;    extrn '__imp_DoSoundConnect' as DoSoundConnect:qword
;    extrn '__imp_DoSoundDisconnect' as DoSoundDisconnect:qword
;    extrn '__imp_DwmGetDxRgn' as DwmGetDxRgn:qword
;    extrn '__imp_DwmGetRemoteSessionOcclusionEvent' as DwmGetRemoteSessionOcclusionEvent:qword
;    extrn '__imp_DwmGetRemoteSessionOcclusionState' as DwmGetRemoteSessionOcclusionState:qword
;    extrn '__imp_DwmHintDxUpdate' as DwmHintDxUpdate:qword
;    extrn '__imp_DwmKernelShutdown' as DwmKernelShutdown:qword
;    extrn '__imp_DwmKernelStartup' as DwmKernelStartup:qword
;    extrn '__imp_DwmLockScreenUpdates' as DwmLockScreenUpdates:qword
;    extrn '__imp_DwmStartRedirection' as DwmLockScreenUpdates:qword
;    extrn '__imp_DwmStopRedirection' as DwmStopRedirection:qword
;    extrn '__imp_DwmValidateWindow' as DwmValidateWindow:qword
;    extrn '__imp_EnableChildWindowDpiMessage' as EnableChildWindowDpiMessage:qword
;    extrn '__imp_EnableSessionForMMCSS' as EnableSessionForMMCSS:qword
;    extrn '__imp_EndDeferWindowPosEx' as EndDeferWindowPosEx:qword
;    extrn '__imp_EnterReaderModeHelper' as EnterReaderModeHelper:qword
;    extrn '__imp_gapfnScSendMessage' as gapfnScSendMessage:qword
;    extrn '__imp_GetClipboardAccessToken' as GetClipboardAccessToken:qword
;    extrn '__imp_GetCursorFrameInfo' as GetCursorFrameInfo:qword
;    extrn '__imp_GetDesktopID' as GetDesktopID:qword
;    extrn '__imp_GetDpiForMonitorInternal' as GetDpiForMonitorInternal:qword
;    extrn '__imp_GetDpiMetrics' as GetDpiMetrics:qword
;    extrn '__imp_GetInputLocaleInfo' as GetInputLocaleInfo:qword
;    extrn '__imp_GetMagnificationDesktopColorEffect' as GetMagnificationDesktopColorEffect:qword
;    extrn '__imp_GetMagnificationDesktopMagnification' as GetMagnificationDesktopMagnification:qword
;    extrn '__imp_GetMagnificationLensCtxInformation' as GetMagnificationLensCtxInformation:qword
;    extrn '__imp_GetPointerFrameArrivalTimes' as GetPointerFrameArrivalTimes:qword
;    extrn '__imp_GetProcessDpiAwarenessInternal' as GetProcessDpiAwarenessInternal:qword
;    extrn '__imp_GetProcessUIContextInformation' as GetProcessUIContextInformation:qword
;    extrn '__imp_GetTopLevelWindow' as GetTopLevelWindow:qword
;    extrn '__imp_GetWinStationInfo' as GetWinStationInfo:qword
;    extrn '__imp_GetWindowBand' as GetWindowBand:qword
;    extrn '__imp_GetWindowCompositionInfo' as GetWindowCompositionInfo:qword
;    extrn '__imp_GetWindowDPI' as GetWindowDPI:qword
;    extrn '__imp_GetWindowRgnEx' as GetWindowRgnEx:qword
;    extrn '__imp_gSharedInfo' as gSharedInfo:qword
;    extrn '__imp_InitDManipHook' as InitDManipHook:qword
;    extrn '__imp_InitializeInputDeviceInjection' as InitializeInputDeviceInjection:qword
;    extrn '__imp_InitializePointerDeviceInjection' as InitializePointerDeviceInjection:qword
;    extrn '__imp_InjectDeviceInput' as InjectDeviceInput:qword
;    extrn '__imp_InjectKeyboardInput' as InjectKeyboardInput:qword
;    extrn '__imp_InjectMouseInput' as InjectMouseInput:qword
;    extrn '__imp_InjectPointerInput' as InjectPointerInput:qword
;    extrn '__imp_InternalGetWindowIcon' as InternalGetWindowIcon:qword
;    extrn '__imp_IsChildWindowDpiMessageEnabled' as IsChildWindowDpiMessageEnabled:qword
;    extrn '__imp_IsInDesktopWindowBand' as IsInDesktopWindowBand:qword
;    extrn '__imp_IsQueueAttached' as IsQueueAttached:qword
;    extrn '__imp_IsThreadMessageQueueAttached' as IsThreadMessageQueueAttached:qword
;    extrn '__imp_IsWindowArranged' as IsWindowArranged:qword
;    extrn '__imp_IsWindowBroadcastingDpiToChildren' as IsWindowBroadcastingDpiToChildren:qword
;    extrn '__imp_KillSystemTimer' as KillSystemTimer:qword
;    extrn '__imp_LogicalToPhysicalPointForPerMonitorDPI' as LogicalToPhysicalPointForPerMonitorDPI:qword
;    extrn '__imp_MBToWCSExt' as MBToWCSExt:qword
;    extrn '__imp_NotifyOverlayWindow' as NotifyOverlayWindow:qword
;    extrn '__imp_OpenThreadDesktop' as OpenThreadDesktop:qword
;    extrn '__imp_PaintMenuBar' as PaintMenuBar:qword
;    extrn '__imp_PaintMonitor' as PaintMonitor:qword
;    extrn '__imp_PrivateRegisterICSProc' as PrivateRegisterICSProc:qword
;    extrn '__imp_QueryBSDRWindow' as QueryBSDRWindow:qword
;    extrn '__imp_ReasonCodeNeedsBugID' as ReasonCodeNeedsBugID:qword
;    extrn '__imp_ReasonCodeNeedsComment' as ReasonCodeNeedsComment:qword
;    extrn '__imp_RegisterBSDRWindow' as RegisterBSDRWindow:qword
;    extrn '__imp_RegisterDManipHook' as RegisterDManipHook:qword
;    extrn '__imp_RegisterErrorReportingDialog' as RegisterErrorReportingDialog:qword
;    extrn '__imp_RegisterFrostWindow' as RegisterFrostWindow:qword
;    extrn '__imp_RegisterGhostWindow' as RegisterGhostWindow:qword
;    extrn '__imp_RegisterManipulationThread' as RegisterManipulationThread:qword
;    extrn '__imp_RegisterPointerInputTargetEx' as RegisterPointerInputTargetEx:qword
;    extrn '__imp_RegisterSessionPort' as RegisterSessionPort:qword
;    extrn '__imp_ReleaseDwmHitTestWaiters' as ReleaseDwmHitTestWaiters:qword
;    extrn '__imp_RemoveInjectionDevice' as RemoveInjectionDevice:qword
;    extrn '__imp_ResolveDesktopForWOW' as ResolveDesktopForWOW:qword
;    extrn '__imp_RIMAddInputObserver' as RIMAddInputObserver:qword
;    extrn '__imp_RIMAddInputObserver' as RIMAddInputObserver:qword
;    extrn '__imp_RIMAreSiblingDevices' as RIMAreSiblingDevices:qword
;    extrn '__imp_RIMDeviceIoControl' as RIMDeviceIoControl:qword
;    extrn '__imp_RIMFreeInputBuffer' as RIMFreeInputBuffer:qword
;    extrn '__imp_RIMGetDevicePreparsedData' as RIMGetDevicePreparsedData:qword
;    extrn '__imp_RIMGetDevicePreparsedDataLockfree' as RIMGetDevicePreparsedDataLockfree:qword
;    extrn '__imp_RIMGetDeviceProperties' as RIMGetDeviceProperties:qword
;    extrn '__imp_RIMGetPhysicalDeviceRect' as RIMGetPhysicalDeviceRect:qword
;    extrn '__imp_RIMObserveNextInput' as RIMObserveNextInput:qword
;    extrn '__imp_RIMOnPnpNotification' as RIMOnPnpNotification:qword
;    extrn '__imp_RIMOnTimerNotification' as RIMOnTimerNotification:qword
;    extrn '__imp_RIMReadInput' as RIMReadInput:qword
;    extrn '__imp_RIMRegisterForInput' as RIMRegisterForInput:qword
;    extrn '__imp_RIMRemoveInputObserver' as RIMRemoveInputObserver:qword
;    extrn '__imp_RIMSetTestModeStatus' as RIMSetTestModeStatus:qword
;    extrn '__imp_RIMUnregisterForInput' as RIMUnregisterForInput:qword
;    extrn '__imp_RIMUpdateInputObserverRegistration' as RIMUpdateInputObserverRegistration:qword
;    extrn '__imp_ScrollChildren' as ScrollChildren:qword
;    extrn '__imp_SetConsoleReserveKeys' as SetConsoleReserveKeys:qword
;    extrn '__imp_SetCursorContents' as SetCursorContents:qword
;    extrn '__imp_SetDeskWallpaper' as SetDeskWallpaper:qword
;    extrn '__imp_SetFeatureReportResponse' as SetFeatureReportResponse:qword
;    extrn '__imp_SetImmersiveBackgroundWindow' as SetImmersiveBackgroundWindow:qword
;    extrn '__imp_SetMagnificationDesktopColorEffect' as SetMagnificationDesktopColorEffect:qword
;    extrn '__imp_SetMagnificationDesktopMagnification' as SetMagnificationDesktopMagnification:qword
;    extrn '__imp_SetMagnificationLensCtxInformation' as SetMagnificationLensCtxInformation:qword
;    extrn '__imp_SetManipulationInputTarget' as SetManipulationInputTarget:qword
;    extrn '__imp_SetMirrorRendering' as SetMirrorRendering:qword
;    extrn '__imp_SetProcessDpiAwarenessInternal' as SetProcessDpiAwarenessInternal:qword
;    extrn '__imp_SetSystemTimer' as SetSystemTimer:qword
;    extrn '__imp_SetThreadInputBlocked' as SetThreadInputBlocked:qword
;    extrn '__imp_SetWindowBand' as SetWindowBand:qword
;    extrn '__imp_SetWindowCompositionTransition' as SetWindowCompositionTransition:qword
;    extrn '__imp_SetWindowRgnEx' as SetWindowRgnEx:qword
;    extrn '__imp_SignalRedirectionStartComplete' as SignalRedirectionStartComplete:qword
;    extrn '__imp_SfmDxBindSwapChain' as SfmDxBindSwapChain:qword
;    extrn '__imp_SfmDxBindSwapChain' as SfmDxBindSwapChain:qword
;    extrn '__imp_SfmDxGetSwapChainStats' as SfmDxGetSwapChainStats:qword
;    extrn '__imp_SfmDxOpenSwapChain' as SfmDxOpenSwapChain:qword
;    extrn '__imp_SfmDxQuerySwapChainBindingStatus' as SfmDxQuerySwapChainBindingStatus:qword
;    extrn '__imp_SfmDxReleaseSwapChain' as SfmDxReleaseSwapChain:qword
;    extrn '__imp_SfmDxReportPendingBindingsToDwm' as SfmDxReportPendingBindingsToDwm:qword
;    extrn '__imp_SfmDxSetSwapChainBindingStatus' as SfmDxSetSwapChainBindingStatus:qword
;    extrn '__imp_SfmDxSetSwapChainStats' as SfmDxSetSwapChainStats:qword
;    extrn '__imp_SoftModalMessageBox' as SoftModalMessageBox:qword
;    extrn '__imp_SwitchDesktopWithFade' as SwitchDesktopWithFade:qword
;    extrn '__imp_UnregisterPointerInputTargetEx' as UnregisterPointerInputTargetEx:qword
;    extrn '__imp_UnregisterSessionPort' as UnregisterSessionPort:qword
;    extrn '__imp_UpdateDefaultDesktopThumbnail' as UpdateDefaultDesktopThumbnail:qword
;    extrn '__imp_UpdatePerUserSystemParameters' as UpdatePerUserSystemParameters:qword
;    extrn '__imp_UpdateWindowInputSinkHints' as UpdateWindowInputSinkHints:qword
;    extrn '__imp_User32InitializeImmEntryTable' as User32InitializeImmEntryTable:qword
;    extrn '__imp_UserClientDllInitialize' as UserClientDllInitialize:qword
;    extrn '__imp_UserLpkPSMTextOut' as UserLpkPSMTextOut:qword
;    extrn '__imp_UserLpkTabbedTextOut' as UserLpkTabbedTextOut:qword
;    extrn '__imp_VRipOutput' as VRipOutput:qword
;    extrn '__imp_VTagOutput' as VTagOutput:qword
;    extrn '__imp_WCSToMBEx' as WCSToMBEx:qword
;    extrn '__imp_WINNLSGetEnableStatus' as WINNLSGetEnableStatus:qword
;    extrn '__imp_WINNLSGetIMEHotkey' as WINNLSGetIMEHotkey:qword
;    extrn '__imp_WaitForRedirectionStartComplete' as WaitForRedirectionStartComplete:qword
;    extrn '__imp_Win32PoolAllocationStats' as Win32PoolAllocationStats:qword
;    extrn '__imp_WindowFromPhysicalPoint' as WindowFromPhysicalPoint:qword
;    extrn '__imp__UserTestTokenForInteractive' as _UserTestTokenForInteractive:qword
;    if (NTDDI_VERSION <= NTDDI_WIN98_ME)
;        extrn '__imp_CalcChildScroll' as CalcChildScroll:qword
;        extrn '__imp_ClientThreadConnect' as ClientThreadConnect:qword
;        extrn '__imp_InitSharedTable' as InitSharedTable:qword
;        extrn '__imp_InitTask' as InitTask:qword
;        extrn '__imp_PlaySoundEvent' as PlaySoundEvent:qword
;        extrn '__imp_SysErrorBox' as SysErrorBox:qword
;        extrn '__imp_WinOldAppHackoMatic' as WinOldAppHackoMatic:qword
;        extrn '__imp_YieldTask' as YieldTask:qword
;    end if
;else
;    extrn '__imp__AlignRects@??' as AlignRects:dword
;    extrn '__imp__CalcMenuBar@??' as CalcMenuBar:dword
;    extrn '__imp__CheckDBCSEnabledExt@??' as CheckDBCSEnabledExt:dword
;    extrn '__imp__CheckDesktopByThreadId@??' as CheckDesktopByThreadId:dword
;    extrn '__imp__CheckProcessForClipboardAccess@??' as CheckProcessForClipboardAccess:dword
;    extrn '__imp__CheckProcessSession@??' as CheckProcessSession:dword
;    extrn '__imp__CheckWindowThreadDesktop@??' as CheckWindowThreadDesktop:dword
;    extrn '__imp__ConsoleControl@??' as ConsoleControl:dword
;    extrn '__imp__ControlMagnification@??' as ControlMagnification:dword
;    extrn '__imp__CreateDCompositionHwndTarget@??' as CreateDCompositionHwndTarget:dword
;    extrn '__imp__CreateWindowInBandEx@??' as CreateWindowInBandEx:dword
;    extrn '__imp__CreateWindowIndirect@??' as CreateWindowIndirect:dword
;    extrn '__imp__DeferWindowPosAndBand@??' as DeferWindowPosAndBand:dword
;    extrn '__imp__DestroyDCompositionHwndTarget@??' as DestroyDCompositionHwndTarget:dword
;    extrn '__imp__DialogBoxIndirectParamAorW@??' as DialogBoxIndirectParamAorW:dword
;    extrn '__imp__DisplayExitWindowsWarnings@??' as DisplayExitWindowsWarnings:dword
;    extrn '__imp__DoSoundConnect@??' as DoSoundConnect:dword
;    extrn '__imp__DoSoundDisconnect@??' as DoSoundDisconnect:dword
;    extrn '__imp__DwmGetDxRgn@??' as DwmGetDxRgn:dword
;    extrn '__imp__DwmGetRemoteSessionOcclusionEvent@??' as DwmGetRemoteSessionOcclusionEvent:dword
;    extrn '__imp__DwmGetRemoteSessionOcclusionState@??' as DwmGetRemoteSessionOcclusionState:dword
;    extrn '__imp__DwmHintDxUpdate@??' as DwmHintDxUpdate:dword
;    extrn '__imp__DwmKernelShutdown@??' as DwmKernelShutdown:dword
;    extrn '__imp__DwmKernelStartup@??' as DwmKernelStartup:dword
;    extrn '__imp__DwmLockScreenUpdates@??' as DwmLockScreenUpdates:dword
;    extrn '__imp__DwmStartRedirection@??' as DwmLockScreenUpdates:dword
;    extrn '__imp__DwmStopRedirection@??' as DwmStopRedirection:dword
;    extrn '__imp__DwmValidateWindow@??' as DwmValidateWindow:dword
;    extrn '__imp__EnableChildWindowDpiMessage@??' as EnableChildWindowDpiMessage:dword
;    extrn '__imp__EnableSessionForMMCSS@??' as EnableSessionForMMCSS:dword
;    extrn '__imp__EndDeferWindowPosEx@??' as EndDeferWindowPosEx:dword
;    extrn '__imp__EnterReaderModeHelper@??' as EnterReaderModeHelper:dword
;    extrn '__imp__gapfnScSendMessage@??' as gapfnScSendMessage:dword
;    extrn '__imp__GetClipboardAccessToken@??' as GetClipboardAccessToken:dword
;    extrn '__imp__GetCursorFrameInfo@??' as GetCursorFrameInfo:dword
;    extrn '__imp__GetDesktopID@??' as GetDesktopID:dword
;    extrn '__imp__GetDpiForMonitorInternal@??' as GetDpiForMonitorInternal:dword
;    extrn '__imp__GetDpiMetrics@??' as GetDpiMetrics:dword
;    extrn '__imp__GetInputLocaleInfo@??' as GetInputLocaleInfo:dword
;    extrn '__imp__GetMagnificationDesktopColorEffect@??' as GetMagnificationDesktopColorEffect:dword
;    extrn '__imp__GetMagnificationDesktopMagnification@??' as GetMagnificationDesktopMagnification:dword
;    extrn '__imp__GetMagnificationLensCtxInformation@??' as GetMagnificationLensCtxInformation:dword
;    extrn '__imp__GetPointerFrameArrivalTimes@??' as GetPointerFrameArrivalTimes:dword
;    extrn '__imp__GetProcessDpiAwarenessInternal@??' as GetProcessDpiAwarenessInternal:dword
;    extrn '__imp__GetProcessUIContextInformation@??' as GetProcessUIContextInformation:dword
;    extrn '__imp__GetTopLevelWindow@??' as GetTopLevelWindow:dword
;    extrn '__imp__GetWinStationInfo@??' as GetWinStationInfo:dword
;    extrn '__imp__GetWindowBand@??' as GetWindowBand:dword
;    extrn '__imp__GetWindowCompositionInfo@??' as GetWindowCompositionInfo:dword
;    extrn '__imp__GetWindowDPI@??' as GetWindowDPI:dword
;    extrn '__imp__GetWindowRgnEx@??' as GetWindowRgnEx:dword
;    extrn '__imp__gSharedInfo@??' as gSharedInfo:dword
;    extrn '__imp__InitDManipHook@??' as InitDManipHook:dword
;    extrn '__imp__InitializeInputDeviceInjection@??' as InitializeInputDeviceInjection:dword
;    extrn '__imp__InitializePointerDeviceInjection@??' as InitializePointerDeviceInjection:dword
;    extrn '__imp__InjectDeviceInput@??' as InjectDeviceInput:dword
;    extrn '__imp__InjectKeyboardInput@??' as InjectKeyboardInput:dword
;    extrn '__imp__InjectMouseInput@??' as InjectMouseInput:dword
;    extrn '__imp__InjectPointerInput@??' as InjectPointerInput:dword
;    extrn '__imp__InternalGetWindowIcon@??' as InternalGetWindowIcon:dword
;    extrn '__imp__IsChildWindowDpiMessageEnabled@??' as IsChildWindowDpiMessageEnabled:dword
;    extrn '__imp__IsInDesktopWindowBand@??' as IsInDesktopWindowBand:dword
;    extrn '__imp__IsQueueAttached@??' as IsQueueAttached:dword
;    extrn '__imp__IsThreadMessageQueueAttached@??' as IsThreadMessageQueueAttached:dword
;    extrn '__imp__IsWindowArranged@??' as IsWindowArranged:dword
;    extrn '__imp__IsWindowBroadcastingDpiToChildren@??' as IsWindowBroadcastingDpiToChildren:dword
;    extrn '__imp__KillSystemTimer@??' as KillSystemTimer:dword
;    extrn '__imp__LogicalToPhysicalPointForPerMonitorDPI@??' as LogicalToPhysicalPointForPerMonitorDPI:dword
;    extrn '__imp__MBToWCSExt@??' as MBToWCSExt:dword
;    extrn '__imp__NotifyOverlayWindow@??' as NotifyOverlayWindow:dword
;    extrn '__imp__OpenThreadDesktop@??' as OpenThreadDesktop:dword
;    extrn '__imp__PaintMenuBar@??' as PaintMenuBar:dword
;    extrn '__imp__PaintMonitor@??' as PaintMonitor:dword
;    extrn '__imp__PrivateRegisterICSProc@??' as PrivateRegisterICSProc:dword
;    extrn '__imp__QueryBSDRWindow@??' as QueryBSDRWindow:dword
;    extrn '__imp__ReasonCodeNeedsBugID@??' as ReasonCodeNeedsBugID:dword
;    extrn '__imp__ReasonCodeNeedsComment@??' as ReasonCodeNeedsComment:dword
;    extrn '__imp__RegisterBSDRWindow@??' as RegisterBSDRWindow:dword
;    extrn '__imp__RegisterDManipHook@??' as RegisterDManipHook:dword
;    extrn '__imp__RegisterErrorReportingDialog@??' as RegisterErrorReportingDialog:dword
;    extrn '__imp__RegisterFrostWindow@??' as RegisterFrostWindow:dword
;    extrn '__imp__RegisterGhostWindow@??' as RegisterGhostWindow:dword
;    extrn '__imp__RegisterManipulationThread@??' as RegisterManipulationThread:dword
;    extrn '__imp__RegisterPointerInputTargetEx@??' as RegisterPointerInputTargetEx:dword
;    extrn '__imp__RegisterSessionPort@??' as RegisterSessionPort:dword
;    extrn '__imp__ReleaseDwmHitTestWaiters@??' as ReleaseDwmHitTestWaiters:dword
;    extrn '__imp__RemoveInjectionDevice@??' as RemoveInjectionDevice:dword
;    extrn '__imp__ResolveDesktopForWOW@??' as ResolveDesktopForWOW:dword
;    extrn '__imp__RIMAddInputObserver@??' as RIMAddInputObserver:dword
;    extrn '__imp__RIMAddInputObserver@??' as RIMAddInputObserver:dword
;    extrn '__imp__RIMAreSiblingDevices@??' as RIMAreSiblingDevices:dword
;    extrn '__imp__RIMDeviceIoControl@??' as RIMDeviceIoControl:dword
;    extrn '__imp__RIMFreeInputBuffer@??' as RIMFreeInputBuffer:dword
;    extrn '__imp__RIMGetDevicePreparsedData@??' as RIMGetDevicePreparsedData:dword
;    extrn '__imp__RIMGetDevicePreparsedDataLockfree@??' as RIMGetDevicePreparsedDataLockfree:dword
;    extrn '__imp__RIMGetDeviceProperties@??' as RIMGetDeviceProperties:dword
;    extrn '__imp__RIMGetPhysicalDeviceRect@??' as RIMGetPhysicalDeviceRect:dword
;    extrn '__imp__RIMObserveNextInput@??' as RIMObserveNextInput:dword
;    extrn '__imp__RIMOnPnpNotification@??' as RIMOnPnpNotification:dword
;    extrn '__imp__RIMOnTimerNotification@??' as RIMOnTimerNotification:dword
;    extrn '__imp__RIMReadInput@??' as RIMReadInput:dword
;    extrn '__imp__RIMRegisterForInput@??' as RIMRegisterForInput:dword
;    extrn '__imp__RIMRemoveInputObserver@??' as RIMRemoveInputObserver:dword
;    extrn '__imp__RIMSetTestModeStatus@??' as RIMSetTestModeStatus:dword
;    extrn '__imp__RIMUnregisterForInput@??' as RIMUnregisterForInput:dword
;    extrn '__imp__RIMUpdateInputObserverRegistration@??' as RIMUpdateInputObserverRegistration:dword
;    extrn '__imp__ScrollChildren@??' as ScrollChildren:dword
;    extrn '__imp__SetConsoleReserveKeys@??' as SetConsoleReserveKeys:dword
;    extrn '__imp__SetCursorContents@??' as SetCursorContents:dword
;    extrn '__imp__SetDeskWallpaper@??' as SetDeskWallpaper:dword
;    extrn '__imp__SetFeatureReportResponse@??' as SetFeatureReportResponse:dword
;    extrn '__imp__SetImmersiveBackgroundWindow@??' as SetImmersiveBackgroundWindow:dword
;    extrn '__imp__SetMagnificationDesktopColorEffect@??' as SetMagnificationDesktopColorEffect:dword
;    extrn '__imp__SetMagnificationDesktopMagnification@??' as SetMagnificationDesktopMagnification:dword
;    extrn '__imp__SetMagnificationLensCtxInformation@??' as SetMagnificationLensCtxInformation:dword
;    extrn '__imp__SetManipulationInputTarget@??' as SetManipulationInputTarget:dword
;    extrn '__imp__SetMirrorRendering@??' as SetMirrorRendering:dword
;    extrn '__imp__SetProcessDpiAwarenessInternal@??' as SetProcessDpiAwarenessInternal:dword
;    extrn '__imp__SetSystemTimer@??' as SetSystemTimer:dword
;    extrn '__imp__SetThreadInputBlocked@??' as SetThreadInputBlocked:dword
;    extrn '__imp__SetWindowBand@??' as SetWindowBand:dword
;    extrn '__imp__SetWindowCompositionTransition@??' as SetWindowCompositionTransition:dword
;    extrn '__imp__SetWindowRgnEx@??' as SetWindowRgnEx:dword
;    extrn '__imp__SignalRedirectionStartComplete@??' as SignalRedirectionStartComplete:dword
;    extrn '__imp__SfmDxBindSwapChain@??' as SfmDxBindSwapChain:dword
;    extrn '__imp__SfmDxBindSwapChain@??' as SfmDxBindSwapChain:dword
;    extrn '__imp__SfmDxGetSwapChainStats@??' as SfmDxGetSwapChainStats:dword
;    extrn '__imp__SfmDxOpenSwapChain@??' as SfmDxOpenSwapChain:dword
;    extrn '__imp__SfmDxQuerySwapChainBindingStatus@??' as SfmDxQuerySwapChainBindingStatus:dword
;    extrn '__imp__SfmDxReleaseSwapChain@??' as SfmDxReleaseSwapChain:dword
;    extrn '__imp__SfmDxReportPendingBindingsToDwm@??' as SfmDxReportPendingBindingsToDwm:dword
;    extrn '__imp__SfmDxSetSwapChainBindingStatus@??' as SfmDxSetSwapChainBindingStatus:dword
;    extrn '__imp__SfmDxSetSwapChainStats@??' as SfmDxSetSwapChainStats:dword
;    extrn '__imp__SoftModalMessageBox@??' as SoftModalMessageBox:dword
;    extrn '__imp__SwitchDesktopWithFade@??' as SwitchDesktopWithFade:dword
;    extrn '__imp__UnregisterPointerInputTargetEx@??' as UnregisterPointerInputTargetEx:dword
;    extrn '__imp__UnregisterSessionPort@??' as UnregisterSessionPort:dword
;    extrn '__imp__UpdateDefaultDesktopThumbnail@??' as UpdateDefaultDesktopThumbnail:dword
;    extrn '__imp__UpdatePerUserSystemParameters@??' as UpdatePerUserSystemParameters:dword
;    extrn '__imp__UpdateWindowInputSinkHints@??' as UpdateWindowInputSinkHints:dword
;    extrn '__imp__User32InitializeImmEntryTable@??' as User32InitializeImmEntryTable:dword
;    extrn '__imp__UserClientDllInitialize@??' as UserClientDllInitialize:dword
;    extrn '__imp__UserLpkPSMTextOut@??' as UserLpkPSMTextOut:dword
;    extrn '__imp__UserLpkTabbedTextOut@??' as UserLpkTabbedTextOut:dword
;    extrn '__imp__VRipOutput@??' as VRipOutput:dword
;    extrn '__imp__VTagOutput@??' as VTagOutput:dword
;    extrn '__imp__WCSToMBEx@??' as WCSToMBEx:dword
;    extrn '__imp__WINNLSGetEnableStatus@??' as WINNLSGetEnableStatus:dword
;    extrn '__imp__WINNLSGetIMEHotkey@??' as WINNLSGetIMEHotkey:dword
;    extrn '__imp__WaitForRedirectionStartComplete@??' as WaitForRedirectionStartComplete:dword
;    extrn '__imp__Win32PoolAllocationStats@??' as Win32PoolAllocationStats:dword
;    extrn '__imp__WindowFromPhysicalPoint@??' as WindowFromPhysicalPoint:dword
;    extrn '__imp___UserTestTokenForInteractive@??' as _UserTestTokenForInteractive:dword
;    if (NTDDI_VERSION <= NTDDI_WIN98_ME)
;        extrn '__imp__CalcChildScroll@??' as CalcChildScroll:dword
;        extrn '__imp__ClientThreadConnect@??' as ClientThreadConnect:dword
;        extrn '__imp__InitSharedTable@??' as InitSharedTable:dword
;        extrn '__imp__InitTask@??' as InitTask:dword
;        extrn '__imp__PlaySoundEvent@??' as PlaySoundEvent:dword
;        extrn '__imp__SysErrorBox@??' as SysErrorBox:dword
;        extrn '__imp__WinOldAppHackoMatic@??' as WinOldAppHackoMatic:dword
;        extrn '__imp__YieldTask@??' as YieldTask:dword
;    end if
;end if

end if ;USER32_INC
