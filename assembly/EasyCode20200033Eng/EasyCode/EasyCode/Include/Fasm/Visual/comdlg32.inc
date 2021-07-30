; ====================================================;
;                                                     ;
;     comdlg32.inc for EC v2 Fasm visual projects     ;
;                   (version 1.0.1)                   ;
;                                                     ;
;            Copyright © Ramon Sala - 2018            ;
;                                                     ;
; ====================================================;

if ~defined COMDLG32_INC
define COMDLG32_INC 1

if defined APP_WIN64
    extrn '__imp_ChooseColorA' as ChooseColorA:qword
    extrn '__imp_ChooseColorW' as ChooseColorW:qword
    extrn '__imp_ChooseFontA' as ChooseFontA:qword
    extrn '__imp_ChooseFontW' as ChooseFontW:qword
    extrn '__imp_CommDlgExtendedError' as CommDlgExtendedError:qword
    extrn '__imp_FindTextA' as FindTextA:qword
    extrn '__imp_FindTextW' as FindTextW:qword
    extrn '__imp_GetFileTitleA' as GetFileTitleA:qword
    extrn '__imp_GetFileTitleW' as GetFileTitleW:qword
    extrn '__imp_GetOpenFileNameA' as GetOpenFileNameA:qword
    extrn '__imp_GetOpenFileNameW' as GetOpenFileNameW:qword
    extrn '__imp_GetSaveFileNameA' as GetSaveFileNameA:qword
    extrn '__imp_GetSaveFileNameW' as GetSaveFileNameW:qword
    extrn '__imp_PageSetupDlgA' as PageSetupDlgA:qword
    extrn '__imp_PageSetupDlgW' as PageSetupDlgW:qword
    extrn '__imp_PrintDlgA' as PrintDlgA:qword
    extrn '__imp_PrintDlgW' as PrintDlgW:qword
    extrn '__imp_ReplaceTextA' as ReplaceTextA:qword
    extrn '__imp_ReplaceTextW' as ReplaceTextW:qword

    if (NTDDI_VERSION >= NTDDI_WIN98_ME)
        extrn '__imp_LoadAlterBitmap' as LoadAlterBitmap:qword
        extrn '__imp_WantArrows' as WantArrows:qword
        extrn '__imp_dwLBSubclass' as dwLBSubclass:qword
        extrn '__imp_dwOKSubclass' as dwOKSubclass:qword
    end if

    if (NTDDI_VERSION >= NTDDI_WIN2K)
        extrn '__imp_PrintDlgExA' as PrintDlgExA:qword
        extrn '__imp_PrintDlgExW' as PrintDlgExW:qword
        extrn '__imp_Ssync_ANSI_UNICODE_Struct_For_WOW' as Ssync_ANSI_UNICODE_Struct_For_WOW:qword
        if ~defined __imp_DllCanUnloadNow
            extrn '__imp_DllCanUnloadNow' as DllCanUnloadNow:qword
        end if
        api PrintDlgEx
    end if
else
    extrn '__imp__ChooseColorA@4' as ChooseColorA:dword
    extrn '__imp__ChooseColorW@4' as ChooseColorW:dword
    extrn '__imp__ChooseFontA@4' as ChooseFontA:dword
    extrn '__imp__ChooseFontW@4' as ChooseFontW:dword
    extrn '__imp__CommDlgExtendedError@0' as CommDlgExtendedError:dword
    extrn '__imp__FindTextA@4' as FindTextA:dword
    extrn '__imp__FindTextW@4' as FindTextW:dword
    extrn '__imp__GetFileTitleA@12' as GetFileTitleA:dword
    extrn '__imp__GetFileTitleW@12' as GetFileTitleW:dword
    extrn '__imp__GetOpenFileNameA@4' as GetOpenFileNameA:dword
    extrn '__imp__GetOpenFileNameW@4' as GetOpenFileNameW:dword
    extrn '__imp__GetSaveFileNameA@4' as GetSaveFileNameA:dword
    extrn '__imp__GetSaveFileNameW@4' as GetSaveFileNameW:dword
    extrn '__imp__PageSetupDlgA@4' as PageSetupDlgA:dword
    extrn '__imp__PageSetupDlgW@4' as PageSetupDlgW:dword
    extrn '__imp__PrintDlgA@4' as PrintDlgA:dword
    extrn '__imp__PrintDlgW@4' as PrintDlgW:dword
    extrn '__imp__ReplaceTextA@4' as ReplaceTextA:dword
    extrn '__imp__ReplaceTextW@4' as ReplaceTextW:dword

    if (NTDDI_VERSION >= NTDDI_WIN98_ME)
        extrn '__imp__LoadAlterBitmap@12' as LoadAlterBitmap:dword
        extrn '__imp__WantArrows@16' as WantArrows:dword
        extrn '__imp__dwLBSubclass@16' as dwLBSubclass:dword
        extrn '__imp__dwOKSubclass@16' as dwOKSubclass:dword
    end if

    if (NTDDI_VERSION >= NTDDI_WIN2K)
        extrn '__imp__PrintDlgExA@4' as PrintDlgExA:dword
        extrn '__imp__PrintDlgExW@4' as PrintDlgExW:dword
        extrn '__imp__Ssync_ANSI_UNICODE_Struct_For_WOW@12' as Ssync_ANSI_UNICODE_Struct_For_WOW:dword
        if (NTDDI_VERSION >= NTDDI_WINVISTA)
           extrn '__imp_DllCanUnloadNow@0' as DllCanUnloadNow:qword
        end if
        api PrintDlgEx
    end if
end if

api ChooseColor,\
    ChooseFont,\
    FindText,\
    GetFileTitle,\
    GetOpenFileName,\
    GetSaveFileName,\
    PageSetupDlg,\
    PrintDlg,\
    ReplaceText

end if ;COMDLG32_INC
