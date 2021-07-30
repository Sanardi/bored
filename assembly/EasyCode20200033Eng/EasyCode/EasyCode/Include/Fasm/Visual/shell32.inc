; ====================================================;
;                                                     ;
;     shell32.inc for EC v2 Fasm visual projects      ;
;                   (version 1.0.3)                   ;
;                                                     ;
;         Copyright © Ramon Sala - 2018-2020          ;
;                                                     ;
; ====================================================;

if ~defined SHELL32_INC
define SHELL32_INC 1

BIF_RETURNONLYFSDIRS                            equ         00000001H
BIF_DONTGOBELOWDOMAIN                           equ         00000002H
BIF_STATUSTEXT                                  equ         00000004H
BIF_RETURNFSANCESTORS                           equ         00000008H
BIF_EDITBOX                                     equ         00000010H
BIF_VALIDATE                                    equ         00000020H
BIF_NEWDIALOGSTYLE                              equ         00000040H
BIF_BROWSEINCLUDEURLS                           equ         00000080H
BIF_UAHINT                                      equ         00000100H
BIF_NONEWFOLDERBUTTON                           equ         00000200H
BIF_NOTRANSLATETARGETS                          equ         00000400H
BIF_BROWSEFORCOMPUTER                           equ         00001000H
BIF_BROWSEFORPRINTER                            equ         00002000H
BIF_BROWSEINCLUDEFILES                          equ         00004000H
BIF_SHAREABLE                                   equ         00008000H
BIF_BROWSEFILEJUNCTIONS                         equ         00010000H
BIF_USENEWUI                                    equ         (BIF_EDITBOX or BIF_NEWDIALOGSTYLE)
BFFM_INITIALIZED                                equ         00000001H
BFFM_SELCHANGED                                 equ         00000002H
BFFM_VALIDATEFAILEDA                            equ         00000003H
BFFM_VALIDATEFAILEDW                            equ         00000004H
BFFM_IUNKNOWN                                   equ         00000005H
BFFM_SETSTATUSTEXTA                             equ         (WM_USER+100)
BFFM_ENABLEOK                                   equ         (WM_USER+101)
BFFM_SETSELECTIONA                              equ         (WM_USER+102)
BFFM_SETSELECTIONW                              equ         (WM_USER+103)
BFFM_SETSTATUSTEXTW                             equ         (WM_USER+104)
BFFM_SETOKTEXT                                  equ         (WM_USER+105)
BFFM_SETEXPANDED                                equ         (WM_USER+106)

if defined APP_UNICODE
	BFFM_VALIDATEFAILED equ BFFM_VALIDATEFAILEDW
    BFFM_SETSELECTION equ BFFM_SETSELECTIONW
    BFFM_SETSTATUSTEXT equ BFFM_SETSTATUSTEXTW
else
	BFFM_VALIDATEFAILED equ BFFM_VALIDATEFAILEDA
    BFFM_SETSELECTION equ BFFM_SETSELECTIONA
    BFFM_SETSTATUSTEXT equ BFFM_SETSTATUSTEXTA
end if

if defined APP_WIN64
    extrn '__imp_CheckEscapesW' as CheckEscapesW:qword
    extrn '__imp_CommandLineToArgvW' as CommandLineToArgvW:qword
    extrn '__imp_Control_RunDLLA' as Control_RunDLLA:qword
    extrn '__imp_Control_RunDLLW' as Control_RunDLLW:qword
    extrn '__imp_DllGetVersion' as DllGetVersion:qword
    extrn '__imp_DoEnvironmentSubstA' as DoEnvironmentSubstA:qword
    extrn '__imp_DoEnvironmentSubstW' as DoEnvironmentSubstW:qword
    extrn '__imp_DragAcceptFiles' as DragAcceptFiles:qword
    extrn '__imp_DragFinish' as DragFinish:qword
    extrn '__imp_DragQueryFileAorW' as DragQueryFileAorW:qword
    extrn '__imp_DragQueryPoint' as DragQueryPoint:qword
    extrn '__imp_DriveType' as DriveType:qword
    extrn '__imp_DuplicateIcon' as DuplicateIcon:qword
    extrn '__imp_ExtractAssociatedIconA' as ExtractAssociatedIconA:qword
    extrn '__imp_ExtractAssociatedIconExA' as ExtractAssociatedIconExA:qword
    extrn '__imp_ExtractAssociatedIconExW' as ExtractAssociatedIconExW:qword
    extrn '__imp_ExtractAssociatedIconW' as ExtractAssociatedIconW:qword
    extrn '__imp_ExtractIconA' as ExtractIconA:qword
    extrn '__imp_ExtractIconW' as ExtractIconW:qword
    extrn '__imp_FindExecutableA' as FindExecutableA:qword
    extrn '__imp_FindExecutableW' as FindExecutableW:qword
    extrn '__imp_FreeIconList' as FreeIconList:qword
    extrn '__imp_InternalExtractIconListA' as InternalExtractIconListA:qword
    extrn '__imp_InternalExtractIconListW' as InternalExtractIconListW:qword
    extrn '__imp_RealShellExecuteA' as RealShellExecuteA:qword
    extrn '__imp_RealShellExecuteExA' as RealShellExecuteExA:qword
    extrn '__imp_RealShellExecuteExW' as RealShellExecuteExW:qword
    extrn '__imp_RealShellExecuteW' as RealShellExecuteW:qword
    extrn '__imp_RegenerateUserEnvironment' as RegenerateUserEnvironment:qword
    extrn '__imp_SHAddToRecentDocs' as SHAddToRecentDocs:qword
    extrn '__imp_SHAppBarMessage' as SHAppBarMessage:qword
    extrn '__imp_SHChangeNotify' as SHChangeNotify:qword
    extrn '__imp_SheGetDirA' as SheGetDirA:qword
    extrn '__imp_SheGetDirW' as SheGetDirW:qword
    extrn '__imp_ShellAboutA' as ShellAboutA:qword
    extrn '__imp_ShellAboutW' as ShellAboutW:qword
    extrn '__imp_ShellExecuteA' as ShellExecuteA:qword
    extrn '__imp_ShellExecuteW' as ShellExecuteW:qword
    extrn '__imp_SheSetCurDrive' as SheSetCurDrive:qword
    extrn '__imp_SHFormatDrive' as SHFormatDrive:qword
    extrn '__imp_SHFreeNameMappings' as SHFreeNameMappings:qword
    extrn '__imp_SHGetDesktopFolder' as SHGetDesktopFolder:qword
    extrn '__imp_SHGetInstanceExplorer' as SHGetInstanceExplorer:qword
    extrn '__imp_SHGetMalloc' as SHGetMalloc:qword
    extrn '__imp_SHGetSpecialFolderLocation' as SHGetSpecialFolderLocation:qword
    extrn '__imp_SHLoadInProc' as SHLoadInProc:qword

    if (NTDDI_VERSION > NTDDI_WIN95)
        extrn '__imp_DragQueryFileA' as DragQueryFileA:qword
        extrn '__imp_DragQueryFileW' as DragQueryFileW:qword
        extrn '__imp_ExtractIconExA' as ExtractIconExA:qword
        extrn '__imp_ExtractIconExW' as ExtractIconExW:qword
        extrn '__imp_OpenAs_RunDLLA' as OpenAs_RunDLLA:qword
        extrn '__imp_OpenAs_RunDLLW' as OpenAs_RunDLLW:qword
        extrn '__imp_SHBrowseForFolderA' as SHBrowseForFolderA:qword
        extrn '__imp_SHBrowseForFolderW' as SHBrowseForFolderW:qword
        extrn '__imp_Shell_NotifyIconA' as Shell_NotifyIconA:qword
        extrn '__imp_Shell_NotifyIconW' as Shell_NotifyIconW:qword
        extrn '__imp_ShellExecuteExA' as ShellExecuteExA:qword
        extrn '__imp_ShellExecuteExW' as ShellExecuteExW:qword
        extrn '__imp_SHFileOperationA' as SHFileOperationA:qword
        extrn '__imp_SHFileOperationW' as SHFileOperationW:qword
        extrn '__imp_SHGetDataFromIDListA' as SHGetDataFromIDListA:qword
        extrn '__imp_SHGetDataFromIDListW' as SHGetDataFromIDListW:qword
        extrn '__imp_SHGetFileInfoA' as SHGetFileInfoA:qword
        extrn '__imp_SHGetFileInfoW' as SHGetFileInfoW:qword
        extrn '__imp_SHGetPathFromIDListA' as SHGetPathFromIDListA:qword
        extrn '__imp_SHGetPathFromIDListW' as SHGetPathFromIDListW:qword
        extrn '__imp_SHHelpShortcuts_RunDLLA' as SHHelpShortcuts_RunDLLA:qword
        extrn '__imp_SHHelpShortcuts_RunDLLW' as SHHelpShortcuts_RunDLLW:qword

        api DragQueryFile,\
            ExtractIconEx,\
            OpenAs_RunDLL,\
            SHBrowseForFolder,\
            Shell_NotifyIcon,\
            ShellAbout,\
            ShellExecuteEx,\
            SHFileOperation,\
            SHGetDataFromIDList,\
            SHGetFileInfo,\
            SHGetPathFromIDList,\
            SHHelpShortcuts_RunDLL
    end if


    if (NTDDI_VERSION >= NTDDI_WIN98_ME)
        if (NTDDI_VERSION <= NTDDI_WINXP)
            extrn '__imp_FindExeDlgProc' as FindExeDlgProc:qword
        end if
        if (NTDDI_VERSION <> NTDDI_WINNT4)
            extrn '__imp_DllCanUnloadNow' as DllCanUnloadNow:qword
            extrn '__imp_SHEmptyRecycleBinA' as SHEmptyRecycleBinA:qword
            extrn '__imp_SHEmptyRecycleBinW' as SHEmptyRecycleBinW:qword
            extrn '__imp_SHGetSettings' as SHGetSettings:qword
            extrn '__imp_SHGetSpecialFolderPathA' as SHGetSpecialFolderPathA:qword
            extrn '__imp_SHGetSpecialFolderPathW' as SHGetSpecialFolderPathW:qword
            extrn '__imp_SHInvokePrinterCommandA' as SHInvokePrinterCommandA:qword
            extrn '__imp_SHInvokePrinterCommandW' as SHInvokePrinterCommandW:qword
            extrn '__imp_SHQueryRecycleBinA' as SHQueryRecycleBinA:qword
            extrn '__imp_SHQueryRecycleBinW' as SHQueryRecycleBinW:qword

            api SHEmptyRecycleBin,\
                SHGetSpecialFolderPath,\
                SHInvokePrinterCommand,\
                SHQueryRecycleBin
        end if
        extrn '__imp_ShellHookProc' as ShellHookProc:qword
        extrn '__imp_SHGetDiskFreeSpaceA' as SHGetDiskFreeSpaceA:qword
        if ~defined APP_UNICODE
            SHGetDiskFreeSpace equ SHGetDiskFreeSpaceA
        end if
        extrn '__imp_SHUpdateRecycleBinIcon' as SHUpdateRecycleBinIcon:qword
    end if

    if (NTDDI_VERSION >= NTDDI_WINNT4)
        extrn '__imp_StrChrA' as StrChrA:qword
        extrn '__imp_StrChrIA' as StrChrIA:qword
        extrn '__imp_StrChrIW' as StrChrIW:qword
        extrn '__imp_StrChrW' as StrChrW:qword
        extrn '__imp_StrCmpNA' as StrCmpNA:qword
        extrn '__imp_StrCmpNIA' as StrCmpNIA:qword
        extrn '__imp_StrCmpNIW' as StrCmpNIW:qword
        extrn '__imp_StrCmpNW' as StrCmpNW:qword
        extrn '__imp_StrNCmpA' as StrNCmpA:qword
        extrn '__imp_StrNCmpIA' as StrNCmpIA:qword
        extrn '__imp_StrNCmpIW' as StrNCmpIW:qword
        extrn '__imp_StrNCmpW' as StrNCmpW:qword
        extrn '__imp_StrRChrA' as StrRChrA:qword
        extrn '__imp_StrRChrIA' as StrRChrIA:qword
        extrn '__imp_StrRChrIW' as StrRChrIW:qword
        extrn '__imp_StrRChrW' as StrRChrW:qword
        extrn '__imp_StrRStrA' as StrRStrA:qword
        extrn '__imp_StrRStrIA' as StrRStrIA:qword
        extrn '__imp_StrRStrIW' as StrRStrIW:qword
        extrn '__imp_StrRStrW' as StrRStrW:qword
        extrn '__imp_StrStrA' as StrStrA:qword
        extrn '__imp_StrStrIA' as StrStrIA:qword
        extrn '__imp_StrStrIW' as StrStrIW:qword
        extrn '__imp_StrStrW' as StrStrW:qword
        extrn '__imp_WOWShellExecute' as WOWShellExecute:qword

        api StrChr,\
            StrChrI,\
            StrCmpN,\
            StrCmpNI,\
            StrNCmp,\
            StrNCmpI,\
            StrRChr,\
            StrRChrI,\
            StrRStr,\
            StrRStrI,\
            StrStr,\
            StrStrI
    end if

    if (NTDDI_VERSION >= NTDDI_WIN2K)
        if (NTDDI_VERSION <= NTDDI_WINXPSP2)
            extrn '__imp_CallCPLEntry16' as CallCPLEntry16:qword
            extrn '__imp_SHMapIDListToImageListIndexAsync' as SHMapIDListToImageListIndexAsync:qword
        end if
        if ~defined DllRegisterServer
            extrn '__imp_DllRegisterServer' as DllRegisterServer:qword
        end if
        if ~defined DllUnregisterServer
            extrn '__imp_DllUnregisterServer' as DllUnregisterServer:qword
        end if
        extrn '__imp_SHBindToParent' as SHBindToParent:qword
        extrn '__imp_SHCreateDirectory' as SHCreateDirectory:qword
        extrn '__imp_SHCreateDirectoryExA' as SHCreateDirectoryExA:qword
        extrn '__imp_SHCreateDirectoryExW' as SHCreateDirectoryExW:qword
        extrn '__imp_ShellExec_RunDLLA' as ShellExec_RunDLLA:qword
        extrn '__imp_ShellExec_RunDLLW' as ShellExec_RunDLLW:qword
        extrn '__imp_SHGetDiskFreeSpaceExA' as SHGetDiskFreeSpaceExA:qword
        extrn '__imp_SHGetDiskFreeSpaceExW' as SHGetDiskFreeSpaceExW:qword
        extrn '__imp_SHGetFolderLocation' as SHGetFolderLocation:qword
        extrn '__imp_SHGetFolderPathA' as SHGetFolderPathA:qword
        extrn '__imp_SHGetFolderPathW' as SHGetFolderPathW:qword
        extrn '__imp_SHGetNewLinkInfoA' as SHGetNewLinkInfoA:qword
        extrn '__imp_SHGetNewLinkInfoW' as SHGetNewLinkInfoW:qword
        extrn '__imp_SHPathPrepareForWriteA' as SHPathPrepareForWriteA:qword
        extrn '__imp_SHPathPrepareForWriteW' as SHPathPrepareForWriteW:qword

        api SHCreateDirectoryEx,\
            ShellExec_RunDLL,\
            SHGetDiskFreeSpaceEx,\
            SHGetFolderPath,\
            SHGetNewLinkInfo,\
            SHPathPrepareForWrite
    else
        if (NTDDI_VERSION > NTDDI_WIN95)
            extrn '__imp_SHGetNewLinkInfo' as SHGetNewLinkInfo:qword
        end if
    end if

    if (NTDDI_VERSION <= NTDDI_WINXP)
        extrn '__imp_ExtractIconResInfoA' as ExtractIconResInfoA:qword
        extrn '__imp_ExtractIconResInfoW' as ExtractIconResInfoW:qword
        extrn '__imp_ExtractVersionResource16W' as ExtractVersionResource16W:qword
        extrn '__imp_ILCreateFromPathA' as ILCreateFromPathA:qword
        extrn '__imp_ILCreateFromPathW' as ILCreateFromPathW:qword
        extrn '__imp_SheFullPathA' as SheFullPathA:qword
        extrn '__imp_SheFullPathW' as SheFullPathW:qword
        extrn '__imp_SheGetCurDrive' as SheGetCurDrive:qword
        extrn '__imp_SheGetDirExW' as SheGetDirExW:qword
        extrn '__imp_SheGetPathOffsetW' as SheGetPathOffsetW:qword
        extrn '__imp_SheRemoveQuotesA' as SheRemoveQuotesA:qword
        extrn '__imp_SheRemoveQuotesW' as SheRemoveQuotesW:qword
        extrn '__imp_SheShortenPathA' as SheShortenPathA:qword
        extrn '__imp_SheShortenPathW' as SheShortenPathW:qword
        api ExtractIconResInfo,\
            ILCreateFromPath,\
            SheFullPath,\
            SheRemoveQuotes,\
            SheShortenPath
    end if

    if (NTDDI_VERSION >= NTDDI_WINXP)
        extrn '__imp_AppCompat_RunDLLW' as AppCompat_RunDLLW:qword
        if (NTDDI_VERSION <= NTDDI_VISTA)
            extrn '__imp_CDefFolderMenu_Create' as CDefFolderMenu_Create:qword
            extrn '__imp_Control_FillCache_RunDLLA' as Control_FillCache_RunDLLA:qword
            extrn '__imp_Control_FillCache_RunDLLW' as Control_FillCache_RunDLLW:qword
            extrn '__imp_SHRunControlPanel' as SHRunControlPanel:qword
        end if
        extrn '__imp_CDefFolderMenu_Create2' as CDefFolderMenu_Create2:qword
        extrn '__imp_Control_RunDLLAsUserW' as Control_RunDLLAsUserW:qword
        extrn '__imp_DAD_AutoScroll' as DAD_AutoScroll:qword
        extrn '__imp_DAD_DragEnterEx' as DAD_DragEnterEx:qword
        extrn '__imp_DAD_DragEnterEx2' as DAD_DragEnterEx2:qword
        extrn '__imp_DAD_DragLeave' as DAD_DragLeave:qword
        extrn '__imp_DAD_DragMove' as DAD_DragMove:qword
        extrn '__imp_DAD_SetDragImage' as DAD_SetDragImage:qword
        extrn '__imp_DAD_ShowDragImage' as DAD_ShowDragImage:qword
        extrn '__imp_GetFileNameFromBrowse' as GetFileNameFromBrowse:qword
        extrn '__imp_ILAppendID' as ILAppendID:qword
        extrn '__imp_ILClone' as ILClone:qword
        extrn '__imp_ILCloneFirst' as ILCloneFirst:qword
        extrn '__imp_ILCombine' as ILCombine:qword
        extrn '__imp_ILFindChild' as ILFindChild:qword
        extrn '__imp_ILFindLastID' as ILFindLastID:qword
        extrn '__imp_ILFree' as ILFree:qword
        extrn '__imp_ILGetNext' as ILGetNext:qword
        extrn '__imp_ILGetSize' as ILGetSize:qword
        extrn '__imp_ILIsEqual' as ILIsEqual:qword
        extrn '__imp_ILIsParent' as ILIsParent:qword
        if (NTDDI_VERSION = NTDDI_WINXP)
            extrn '__imp_ILLoadFromStream' as ILLoadFromStream:qword
            extrn '__imp_PathProcessCommand' as PathProcessCommand:qword
            extrn '__imp_SHAllocShared' as SHAllocShared:qword
            extrn '__imp_SHGetSetFolderCustomSettingsW' as SHGetSetFolderCustomSettingsW:qword
        end if
        extrn '__imp_ILLoadFromStreamEx' as ILLoadFromStreamEx:qword
        extrn '__imp_ILRemoveLastID' as ILRemoveLastID:qword
        extrn '__imp_ILSaveToStream' as ILSaveToStream:qword
        extrn '__imp_IsLFNDrive' as IsLFNDrive:qword
        extrn '__imp_IsLFNDriveA' as IsLFNDriveA:qword
        extrn '__imp_IsLFNDriveW' as IsLFNDriveW:qword
        extrn '__imp_IsNetDrive' as IsNetDrive:qword
        extrn '__imp_IsUserAnAdmin' as IsUserAnAdmin:qword
        extrn '__imp_OpenRegStream' as OpenRegStream:qword
        extrn '__imp_Options_RunDLLA' as Options_RunDLLA:qword
        extrn '__imp_Options_RunDLLW' as Options_RunDLLW:qword
        extrn '__imp_PathCleanupSpec' as PathCleanupSpec:qword
        extrn '__imp_PathGetShortPath' as PathGetShortPath:qword
        extrn '__imp_PathIsExe' as PathIsExe:qword
        extrn '__imp_PathIsSlowA' as PathIsSlowA:qword
        extrn '__imp_PathIsSlowW' as PathIsSlowW:qword
        extrn '__imp_PathMakeUniqueName' as PathMakeUniqueName:qword
        extrn '__imp_PathResolve' as PathResolve:qword
        extrn '__imp_PathYetAnotherMakeUniqueName' as PathYetAnotherMakeUniqueName:qword
        extrn '__imp_PickIconDlg' as PickIconDlg:qword
        extrn '__imp_PifMgr_CloseProperties' as PifMgr_CloseProperties:qword
        extrn '__imp_PifMgr_GetProperties' as PifMgr_GetProperties:qword
        extrn '__imp_PifMgr_OpenProperties' as PifMgr_OpenProperties:qword
        extrn '__imp_PifMgr_SetProperties' as PifMgr_SetProperties:qword
        extrn '__imp_ReadCabinetState' as ReadCabinetState:qword
        extrn '__imp_RealDriveType' as RealDriveType:qword
        extrn '__imp_RestartDialog' as RestartDialog:qword
        extrn '__imp_RestartDialogEx' as RestartDialogEx:qword
        extrn '__imp_SHAddFromPropSheetExtArray' as SHAddFromPropSheetExtArray:qword
        extrn '__imp_SHAlloc' as SHAlloc:qword
        extrn '__imp_SHChangeNotification_Lock' as SHChangeNotification_Lock:qword
        extrn '__imp_SHChangeNotification_Unlock' as SHChangeNotification_Unlock:qword
        extrn '__imp_SHChangeNotifyDeregister' as SHChangeNotifyDeregister:qword
        extrn '__imp_SHChangeNotifyRegister' as SHChangeNotifyRegister:qword
        extrn '__imp_SHChangeNotifySuspendResume' as SHChangeNotifySuspendResume:qword
        extrn '__imp_SHCloneSpecialIDList' as SHCloneSpecialIDList:qword
        extrn '__imp_SHCLSIDFromString' as SHCLSIDFromString:qword
        extrn '__imp_SHCoCreateInstance' as SHCoCreateInstance:qword
        extrn '__imp_SHCreateFileExtractIconW' as SHCreateFileExtractIconW:qword
        extrn '__imp_SHCreateProcessAsUserW' as SHCreateProcessAsUserW:qword
        extrn '__imp_SHCreatePropSheetExtArray' as SHCreatePropSheetExtArray:qword
        extrn '__imp_SHCreateQueryCancelAutoPlayMoniker' as SHCreateQueryCancelAutoPlayMoniker:qword
        extrn '__imp_SHCreateShellFolderView' as SHCreateShellFolderView:qword
        extrn '__imp_SHCreateShellFolderViewEx' as SHCreateShellFolderViewEx:qword
        extrn '__imp_SHCreateShellItem' as SHCreateShellItem:qword
        extrn '__imp_SHCreateStdEnumFmtEtc' as SHCreateStdEnumFmtEtc:qword
        extrn '__imp_SHDefExtractIconA' as SHDefExtractIconA:qword
        extrn '__imp_SHDefExtractIconW' as SHDefExtractIconW:qword
        extrn '__imp_SHDestroyPropSheetExtArray' as SHDestroyPropSheetExtArray:qword
        extrn '__imp_SHDoDragDrop' as SHDoDragDrop:qword
        extrn '__imp_SheChangeDirA' as SheChangeDirA:qword
        extrn '__imp_SheChangeDirExA' as SheChangeDirExA:qword
        extrn '__imp_SheChangeDirExW' as SheChangeDirExW:qword
        extrn '__imp_SheChangeDirW' as SheChangeDirW:qword
        extrn '__imp_Shell_GetCachedImageIndex' as Shell_GetCachedImageIndex:qword
        extrn '__imp_Shell_GetImageLists' as Shell_GetImageLists:qword
        extrn '__imp_Shell_MergeMenus' as Shell_MergeMenus:qword
        extrn '__imp_ShellMessageBoxA' as ShellMessageBoxA:qword
        extrn '__imp_ShellMessageBoxW' as ShellMessageBoxW:qword
        extrn '__imp_SHEnableServiceObject' as SHEnableServiceObject:qword
        extrn '__imp_SHEnumerateUnreadMailAccountsW' as SHEnumerateUnreadMailAccountsW:qword
        extrn '__imp_SHExtractIconsW' as SHExtractIconsW:qword
        extrn '__imp_SHFind_InitMenuPopup' as SHFind_InitMenuPopup:qword
        extrn '__imp_SHFindFiles' as SHFindFiles:qword
        if (NTDDI_VERSION <= NTDDI_WINXPSP2)
            extrn '__imp_SHFlushClipboard' as SHFlushClipboard:qword
            extrn '__imp_SHFreeShared' as SHFreeShared:qword
            extrn '__imp_SHGetShellStyleHInstance' as SHGetShellStyleHInstance:qword
            extrn '__imp_SHLockShared' as SHLockShared:qword
            extrn '__imp_SHUnlockShared' as SHLockShared:qword
        end if
        extrn '__imp_SHFlushSFCache' as SHFlushSFCache:qword
        extrn '__imp_SHFree' as SHFree:qword
        extrn '__imp_SHGetAttributesFromDataObject' as SHGetAttributesFromDataObject:qword
        extrn '__imp_SHGetFolderPathAndSubDirA' as SHGetFolderPathAndSubDirA:qword
        extrn '__imp_SHGetFolderPathAndSubDirW' as SHGetFolderPathAndSubDirW:qword
        extrn '__imp_SHGetIconOverlayIndexA' as SHGetIconOverlayIndexA:qword
        extrn '__imp_SHGetIconOverlayIndexW' as SHGetIconOverlayIndexW:qword
        extrn '__imp_SHGetImageList' as SHGetImageList:qword
        extrn '__imp_SHGetRealIDL' as SHGetRealIDL:qword
        extrn '__imp_SHGetSetFolderCustomSettings' as SHGetSetFolderCustomSettings:qword
        extrn '__imp_SHGetSetSettings' as SHGetSetSettings:qword
        extrn '__imp_SHGetUnreadMailCountW' as SHGetUnreadMailCountW:qword
        extrn '__imp_SHHandleUpdateImage' as SHHandleUpdateImage:qword
        extrn '__imp_SHILCreateFromPath' as SHILCreateFromPath:qword
        extrn '__imp_SHIsFileAvailableOffline' as SHIsFileAvailableOffline:qword
        extrn '__imp_SHLimitInputEdit' as SHLimitInputEdit:qword
        extrn '__imp_SHLoadNonloadedIconOverlayIdentifiers' as SHLoadNonloadedIconOverlayIdentifiers:qword
        extrn '__imp_SHMapPIDLToSystemImageListIndex' as SHMapPIDLToSystemImageListIndex:qword
        extrn '__imp_SHMultiFileProperties' as SHMultiFileProperties:qword
        extrn '__imp_SHObjectProperties' as SHObjectProperties:qword
        extrn '__imp_SHOpenFolderAndSelectItems' as SHOpenFolderAndSelectItems:qword
        extrn '__imp_SHOpenPropSheetW' as SHOpenPropSheetW:qword
        extrn '__imp_SHParseDisplayName' as SHParseDisplayName:qword
        extrn '__imp_SHPropStgCreate' as SHPropStgCreate:qword
        extrn '__imp_SHPropStgReadMultiple' as SHPropStgReadMultiple:qword
        extrn '__imp_SHPropStgWriteMultiple' as SHPropStgWriteMultiple:qword
        extrn '__imp_SHReplaceFromPropSheetExtArray' as SHReplaceFromPropSheetExtArray:qword
        extrn '__imp_SHRestricted' as SHRestricted:qword
        extrn '__imp_SHSetInstanceExplorer' as SHSetInstanceExplorer:qword
        extrn '__imp_SHSetLocalizedName' as SHSetLocalizedName:qword
        extrn '__imp_SHSetUnreadMailCountW' as SHSetUnreadMailCountW:qword
        extrn '__imp_SHShellFolderView_Message' as SHShellFolderView_Message:qword
        extrn '__imp_SHSimpleIDListFromPath' as SHSimpleIDListFromPath:qword
        extrn '__imp_SHStartNetConnectionDialogW' as SHStartNetConnectionDialogW:qword
        extrn '__imp_SHTestTokenMembership' as SHTestTokenMembership:qword
        extrn '__imp_SHUpdateImageA' as SHUpdateImageA:qword
        extrn '__imp_SHUpdateImageW' as SHUpdateImageW:qword
        extrn '__imp_SHValidateUNC' as SHValidateUNC:qword
        extrn '__imp_SignalFileOpen' as SignalFileOpen:qword
        extrn '__imp_Win32DeleteFile' as Win32DeleteFile:qword
        extrn '__imp_WriteCabinetState' as WriteCabinetState:qword

        api Options_RunDLL,\
            PathIsSlow,\
            SheChangeDir,\
            SheChangeDirEx,\
            ShellMessageBox,\
            SHGetFolderPathAndSubDir,\
            SHGetIconOverlayIndex,\
            SHUpdateImage
        SHGetUnreadMailCount equ SHGetUnreadMailCountW
    end if

    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_AssocCreateForClasses' as AssocCreateForClasses:qword
        extrn '__imp_AssocGetDetailsOfPropKey' as AssocGetDetailsOfPropKey:qword
        extrn '__imp_CIDLData_CreateFromIDArray' as CIDLData_CreateFromIDArray:qword
        extrn '__imp_InitNetworkAddressControl' as InitNetworkAddressControl:qword
        extrn '__imp_SHAddDefaultPropertiesByExt' as SHAddDefaultPropertiesByExt:qword
        extrn '__imp_SHAssocEnumHandlers' as SHAssocEnumHandlers:qword
        extrn '__imp_SHBindToFolderIDListParent' as SHBindToFolderIDListParent:qword
        extrn '__imp_SHBindToFolderIDListParentEx' as SHBindToFolderIDListParentEx:qword
        extrn '__imp_SHBindToObject' as SHBindToObject:qword
        extrn '__imp_SHChangeNotifyRegisterThread' as SHChangeNotifyRegisterThread:qword
        extrn '__imp_SHCreateAssociationRegistration' as SHCreateAssociationRegistration:qword
        extrn '__imp_SHCreateDataObject' as SHCreateDataObject:qword
        extrn '__imp_SHCreateDefaultContextMenu' as SHCreateDefaultContextMenu:qword
        extrn '__imp_SHCreateDefaultExtractIcon' as SHCreateDefaultExtractIcon:qword
        extrn '__imp_SHCreateDefaultPropertiesOp' as SHCreateDefaultPropertiesOp:qword
        extrn '__imp_SHCreateItemFromIDList' as SHCreateItemFromIDList:qword
        extrn '__imp_SHCreateItemFromParsingName' as SHCreateItemFromParsingName:qword
        extrn '__imp_SHCreateItemFromRelativeName' as SHCreateItemFromRelativeName:qword
        extrn '__imp_SHCreateItemInKnownFolder' as SHCreateItemInKnownFolder:qword
        extrn '__imp_SHCreateItemWithParent' as SHCreateItemWithParent:qword
        extrn '__imp_SHCreateShellItemArray' as SHCreateShellItemArray:qword
        extrn '__imp_SHCreateShellItemArrayFromDataObject' as SHCreateShellItemArrayFromDataObject:qword
        extrn '__imp_SHCreateShellItemArrayFromIDLists' as SHCreateShellItemArrayFromIDLists:qword
        extrn '__imp_SHCreateShellItemArrayFromShellItem' as SHCreateShellItemArrayFromShellItem:qword
        extrn '__imp_Shell_GetCachedImageIndexA' as Shell_GetCachedImageIndexA:qword
        extrn '__imp_Shell_GetCachedImageIndexW' as Shell_GetCachedImageIndexW:qword
        extrn '__imp_SHEvaluateSystemCommandTemplate' as SHEvaluateSystemCommandTemplate:qword
        extrn '__imp_SHGetDriveMedia' as SHGetDriveMedia:qword
        extrn '__imp_SHGetFolderPathEx' as SHGetFolderPathEx:qword
        extrn '__imp_SHGetIDListFromObject' as SHGetIDListFromObject:qword
        extrn '__imp_SHGetKnownFolderIDList' as SHGetKnownFolderIDList:qword
        extrn '__imp_SHGetKnownFolderPath' as SHGetKnownFolderPath:qword
        extrn '__imp_SHGetLocalizedName' as SHGetLocalizedName:qword
        extrn '__imp_SHGetNameFromIDList' as SHGetNameFromIDList:qword
        extrn '__imp_SHGetPathFromIDListEx' as SHGetPathFromIDListEx:qword
        extrn '__imp_SHGetPropertyStoreFromIDList' as SHGetPropertyStoreFromIDList:qword
        extrn '__imp_SHGetPropertyStoreFromParsingName' as SHGetPropertyStoreFromParsingName:qword
        extrn '__imp_SHGetStockIconInfo' as SHGetStockIconInfo:qword
        extrn '__imp_SHGetTemporaryPropertyForItem' as SHGetTemporaryPropertyForItem:qword
        extrn '__imp_SHOpenWithDialog' as SHOpenWithDialog:qword
        extrn '__imp_SHQueryUserNotificationState' as SHQueryUserNotificationState:qword
        extrn '__imp_SHRemoveLocalizedName' as SHRemoveLocalizedName:qword
        extrn '__imp_SHSetDefaultProperties' as SHSetDefaultProperties:qword
        extrn '__imp_SHSetFolderPathA' as SHSetFolderPathA:qword
        extrn '__imp_SHSetFolderPathW' as SHSetFolderPathW:qword
        extrn '__imp_SHSetKnownFolderPath' as SHSetKnownFolderPath:qword
        extrn '__imp_SHSetTemporaryPropertyForItem' as SHSetTemporaryPropertyForItem:qword
        extrn '__imp_WaitForExplorerRestartW' as WaitForExplorerRestartW:qword

        api Shell_GetCachedImageIndex,\
            SHSetFolderPath
    else
        extrn '__imp_CheckEscapesA' as CheckEscapesA:qword
    end if

    if (NTDDI_VERSION >= NTDDI_WIN7)
        extrn '__imp_GetCurrentProcessExplicitAppUserModelID' as GetCurrentProcessExplicitAppUserModelID:qword
        extrn '__imp_RunAsNewUser_RunDLLW' as RunAsNewUser_RunDLLW:qword
        extrn '__imp_SetCurrentProcessExplicitAppUserModelID' as SetCurrentProcessExplicitAppUserModelID:qword
        extrn '__imp_SHAssocEnumHandlersForProtocolByApplication' as SHAssocEnumHandlersForProtocolByApplication:qword
        extrn '__imp_Shell_NotifyIconGetRect' as Shell_NotifyIconGetRect:qword
        extrn '__imp_SHGetItemFromDataObject' as SHGetItemFromDataObject:qword
        extrn '__imp_SHGetItemFromObject' as SHGetItemFromObject:qword
        extrn '__imp_SHGetKnownFolderItem' as SHGetKnownFolderItem:qword
        extrn '__imp_SHGetPropertyStoreForWindow' as SHGetPropertyStoreForWindow:qword
        extrn '__imp_SHResolveLibrary' as SHResolveLibrary:qword
        extrn '__imp_SHShowManageLibraryUI' as SHShowManageLibraryUI:qword
        extrn '__imp_StgMakeUniqueName' as StgMakeUniqueName:qword
    end if

    if (NTDDI_VERSION >= NTDDI_WIN8)
        extrn '__imp_DllGetActivationFactory' as DllGetActivationFactory:qword
    end if

    if (NTDDI_VERSION >= NTDDI_WIN10)
        extrn '__imp_IsProcessAnExplorer' as IsProcessAnExplorer:qword
    end if

    api Control_RunDLL,\
        DoEnvironmentSubst,\
        ExtractAssociatedIconEx,\
        ExtractAssociatedIcon,\
        ExtractIcon,\
        FindExecutable,\
        InternalExtractIconList,\
        RealShellExecute,\
        RealShellExecuteEx,\
        SheGetDir,\
        ShellAbout,\
        ShellExecute
else
    extrn '__imp__CheckEscapesW@8' as CheckEscapesW:dword
    extrn '__imp__CommandLineToArgvW@8' as CommandLineToArgvW:dword
    ;extrn '__imp__Control_RunDLLA@16' as Control_RunDLLA:dword ;Not present in MASM32 shell32.lib
    ;extrn '__imp__Control_RunDLLW@16' as Control_RunDLLW:dword ;Not present in MASM32 shell32.lib
    ;extrn '__imp__DllGetVersion@4' as DllGetVersion:dword ;Not present in MASM32 shell32.lib
    extrn '__imp__DoEnvironmentSubstA@8' as DoEnvironmentSubstA:dword
    extrn '__imp__DoEnvironmentSubstW@8' as DoEnvironmentSubstW:dword
    extrn '__imp__DragAcceptFiles@8' as DragAcceptFiles:dword
    extrn '__imp__DragFinish@4' as DragFinish:dword
    extrn '__imp__DragQueryFileAorW@24' as DragQueryFileAorW:dword
    ;extrn '__imp__DragQueryFileW@16' as DragQueryFileW:dword ;Not present in MASM32 shell32.lib
    extrn '__imp__DragQueryPoint@8' as DragQueryPoint:dword
    extrn '__imp__DriveType@4' as DriveType:dword
    extrn '__imp__DuplicateIcon@8' as DuplicateIcon:dword
    extrn '__imp__ExtractAssociatedIconA@12' as ExtractAssociatedIconA:dword
    extrn '__imp__ExtractAssociatedIconExA@16' as ExtractAssociatedIconExA:dword
    extrn '__imp__ExtractAssociatedIconExW@16' as ExtractAssociatedIconExW:dword
    extrn '__imp__ExtractAssociatedIconW@12' as ExtractAssociatedIconW:dword
    extrn '__imp__ExtractIconA@12' as ExtractIconA:dword
    extrn '__imp__ExtractIconW@12' as ExtractIconW:dword
    extrn '__imp__FindExecutableA@12' as FindExecutableA:dword
    extrn '__imp__FindExecutableW@12' as FindExecutableW:dword
    extrn '__imp__FreeIconList@8' as FreeIconList:dword
    extrn '__imp__InternalExtractIconListA@12' as InternalExtractIconListA:dword
    extrn '__imp__InternalExtractIconListW@12' as InternalExtractIconListW:dword
    extrn '__imp__RealShellExecuteA@40' as RealShellExecuteA:dword
    extrn '__imp__RealShellExecuteExA@44' as RealShellExecuteExA:dword
    extrn '__imp__RealShellExecuteExW@44' as RealShellExecuteExW:dword
    extrn '__imp__RealShellExecuteW@40' as RealShellExecuteW:dword
    extrn '__imp__RegenerateUserEnvironment@8' as RegenerateUserEnvironment:dword
    extrn '__imp__SHAddToRecentDocs@8' as SHAddToRecentDocs:dword
    extrn '__imp__SHAppBarMessage@8' as SHAppBarMessage:dword
    extrn '__imp__SHChangeNotify@16' as SHChangeNotify:dword
    ;extrn '__imp__SheGetDirA@8' as SheGetDirA:dword ;Not present in MASM32 shell32.lib
    ;extrn '__imp__SheGetDirW@8' as SheGetDirW:dword ;Not present in MASM32 shell32.lib
    extrn '__imp__ShellAboutA@16' as ShellAboutA:dword
    extrn '__imp__ShellAboutW@16' as ShellAboutW:dword
    extrn '__imp__ShellExecuteA@24' as ShellExecuteA:dword
    extrn '__imp__ShellExecuteW@24' as ShellExecuteW:dword
    extrn '__imp__SheSetCurDrive@4' as SheSetCurDrive:dword
    extrn '__imp__SHFormatDrive@16' as SHFormatDrive:dword
    extrn '__imp__SHFreeNameMappings@4' as SHFreeNameMappings:dword
    extrn '__imp__SHGetDesktopFolder@4' as SHGetDesktopFolder:dword
    extrn '__imp__SHGetInstanceExplorer@4' as SHGetInstanceExplorer:dword
    extrn '__imp__SHGetMalloc@4' as SHGetMalloc:dword
    extrn '__imp__SHGetSpecialFolderLocation@12' as SHGetSpecialFolderLocation:dword
    extrn '__imp__SHLoadInProc@4' as SHLoadInProc:dword

    if (NTDDI_VERSION > NTDDI_WIN95)
        extrn '__imp__DragQueryFileA@16' as DragQueryFileA:dword
        extrn '__imp__DragQueryFileW@16' as DragQueryFileW:dword
        extrn '__imp__ExtractIconExA@20' as ExtractIconExA:dword
        extrn '__imp__ExtractIconExW@20' as ExtractIconExW:dword
        ;extrn '__imp__OpenAs_RunDLLA@4' as OpenAs_RunDLLA:dword ;Not present in MASM32 shell32.lib
        ;extrn '__imp__OpenAs_RunDLLW@4' as OpenAs_RunDLLW:dword ;Not present in MASM32 shell32.lib
        extrn '__imp__SHBrowseForFolderA@4' as SHBrowseForFolderA:dword
        extrn '__imp__SHBrowseForFolderW@4' as SHBrowseForFolderW:dword
        extrn '__imp__Shell_NotifyIconA@8' as Shell_NotifyIconA:dword
        extrn '__imp__Shell_NotifyIconW@8' as Shell_NotifyIconW:dword
        extrn '__imp__ShellExecuteExA@4' as ShellExecuteExA:dword
        extrn '__imp__ShellExecuteExW@4' as ShellExecuteExW:dword
        extrn '__imp__SHFileOperationA@4' as SHFileOperationA:dword
        extrn '__imp__SHFileOperationW@4' as SHFileOperationW:dword
        extrn '__imp__SHGetDataFromIDListA@20' as SHGetDataFromIDListA:dword
        extrn '__imp__SHGetDataFromIDListW@20' as SHGetDataFromIDListW:dword
        extrn '__imp__SHGetFileInfoA@20' as SHGetFileInfoA:dword
        extrn '__imp__SHGetFileInfoW@20' as SHGetFileInfoW:dword
        extrn '__imp__SHGetPathFromIDListA@8' as SHGetPathFromIDListA:dword
        extrn '__imp__SHGetPathFromIDListW@8' as SHGetPathFromIDListW:dword
        extrn '__imp__SHHelpShortcuts_RunDLLA@16' as SHHelpShortcuts_RunDLLA:dword
        extrn '__imp__SHHelpShortcuts_RunDLLW@16' as SHHelpShortcuts_RunDLLW:dword

        api SHBrowseForFolder,\
            DragQueryFile,\
            ExtractIconEx,\
            ;OpenAs_RunDLL,\    ;Not present in MASM32 shell32.lib
            Shell_NotifyIcon,\
            ShellExecuteEx,\
            SHFileOperation,\
            SHGetDataFromIDList,\
            SHGetFileInfo,\
            SHGetPathFromIDList,\
            SHHelpShortcuts_RunDLL
    end if


    if (NTDDI_VERSION >= NTDDI_WIN98_ME)
        if (NTDDI_VERSION <= NTDDI_WINXP)
            extrn '__imp__FindExeDlgProc@16' as FindExeDlgProc:dword
        end if
        if (NTDDI_VERSION <> NTDDI_WINNT4)
            extrn '__imp__DllCanUnloadNow@0' as DllCanUnloadNow:dword
            extrn '__imp__SHEmptyRecycleBinA@12' as SHEmptyRecycleBinA:dword
            extrn '__imp__SHEmptyRecycleBinW@12' as SHEmptyRecycleBinW:dword
            extrn '__imp__SHGetSettings@8' as SHGetSettings:dword
            extrn '__imp__SHGetSpecialFolderPathA@16' as SHGetSpecialFolderPathA:dword
            extrn '__imp__SHGetSpecialFolderPathW@16' as SHGetSpecialFolderPathW:dword
            extrn '__imp__SHInvokePrinterCommandA@20' as SHInvokePrinterCommandA:dword
            extrn '__imp__SHInvokePrinterCommandW@20' as SHInvokePrinterCommandW:dword
            extrn '__imp__SHQueryRecycleBinA@8' as SHQueryRecycleBinA:dword
            extrn '__imp__SHQueryRecycleBinW@8' as SHQueryRecycleBinW:dword

            api SHEmptyRecycleBin,\
                SHGetSpecialFolderPath,\
                SHInvokePrinterCommand,\
                SHQueryRecycleBin
        end if
        extrn '__imp__ShellHookProc@12' as ShellHookProc:dword
        extrn '__imp__SHGetDiskFreeSpaceA@16' as SHGetDiskFreeSpaceA:dword
        if ~defined APP_UNICODE
            SHGetDiskFreeSpace equ SHGetDiskFreeSpaceA
        end if
        extrn '__imp__SHUpdateRecycleBinIcon@0' as SHUpdateRecycleBinIcon:dword
    end if

    if (NTDDI_VERSION >= NTDDI_WINNT4)
        extrn '__imp__StrChrA@8' as StrChrA:dword
        extrn '__imp__StrChrIA@8' as StrChrIA:dword
        extrn '__imp__StrChrIW@8' as StrChrIW:dword
        extrn '__imp__StrChrW@8' as StrChrW:dword
        extrn '__imp__StrCmpNA@12' as StrCmpNA:dword
        extrn '__imp__StrCmpNIA@12' as StrCmpNIA:dword
        extrn '__imp__StrCmpNIW@12' as StrCmpNIW:dword
        extrn '__imp__StrCmpNW@12' as StrCmpNW:dword
        extrn '__imp__StrNCmpA@12' as StrNCmpA:dword
        extrn '__imp__StrNCmpIA@12' as StrNCmpIA:dword
        extrn '__imp__StrNCmpIW@12' as StrNCmpIW:dword
        extrn '__imp__StrNCmpW@12' as StrNCmpW:dword
        extrn '__imp__StrRChrA@12' as StrRChrA:dword
        extrn '__imp__StrRChrIA@12' as StrRChrIA:dword
        extrn '__imp__StrRChrIW@12' as StrRChrIW:dword
        extrn '__imp__StrRChrW@12' as StrRChrW:dword
        extrn '__imp__StrRStrA@12' as StrRStrA:dword
        extrn '__imp__StrRStrIA@12' as StrRStrIA:dword
        extrn '__imp__StrRStrIW@12' as StrRStrIW:dword
        extrn '__imp__StrRStrW@12' as StrRStrW:dword
        extrn '__imp__StrStrA@8' as StrStrA:dword
        extrn '__imp__StrStrIA@8' as StrStrIA:dword
        extrn '__imp__StrStrIW@8' as StrStrIW:dword
        extrn '__imp__StrStrW@8' as StrStrW:dword
        extrn '__imp__WOWShellExecute@28' as WOWShellExecute:dword

        api StrChr,\
            StrChrI,\
            StrCmpN,\
            StrCmpNI,\
            StrNCmp,\
            StrNCmpI,\
            StrRChr,\
            StrRChrI,\
            StrRStr,\
            StrRStrI,\
            StrStr,\
            StrStrI
    end if

    if (NTDDI_VERSION >= NTDDI_WIN2K)
        if (NTDDI_VERSION <= NTDDI_WINXPSP2)
            extrn '__imp__CallCPLEntry16@24' as CallCPLEntry16:dword
            extrn '__imp__SHMapIDListToImageListIndexAsync@36' as SHMapIDListToImageListIndexAsync:dword
        end if
        if ~defined DllRegisterServer
            extrn '__imp__DllRegisterServer@0' as DllRegisterServer:dword
        end if
        if ~defined DllUnregisterServer
            extrn '__imp__DllUnregisterServer@0' as DllUnregisterServer:dword
        end if
        extrn '__imp__SHBindToParent@16' as SHBindToParent:dword
        extrn '__imp__SHCreateDirectory@8' as SHCreateDirectory:dword
        extrn '__imp__SHCreateDirectoryExA@12' as SHCreateDirectoryExA:dword
        extrn '__imp__SHCreateDirectoryExW@12' as SHCreateDirectoryExW:dword
        extrn '__imp__ShellExec_RunDLLA@4' as ShellExec_RunDLLA:dword
        extrn '__imp__ShellExec_RunDLLW@4' as ShellExec_RunDLLW:dword
        extrn '__imp__SHGetDiskFreeSpaceExA@16' as SHGetDiskFreeSpaceExA:dword
        extrn '__imp__SHGetDiskFreeSpaceExW@16' as SHGetDiskFreeSpaceExW:dword
        extrn '__imp__SHGetFolderLocation@20' as SHGetFolderLocation:dword
        extrn '__imp__SHGetFolderPathA@20' as SHGetFolderPathA:dword
        extrn '__imp__SHGetFolderPathW@20' as SHGetFolderPathW:dword
        extrn '__imp__SHGetNewLinkInfoA@20' as SHGetNewLinkInfoA:dword
        extrn '__imp__SHGetNewLinkInfoW@20' as SHGetNewLinkInfoW:dword
        extrn '__imp__SHPathPrepareForWriteA@16' as SHPathPrepareForWriteA:dword
        extrn '__imp__SHPathPrepareForWriteW@16' as SHPathPrepareForWriteW:dword

        api SHCreateDirectoryEx,\
            ShellExec_RunDLL,\
            SHGetDiskFreeSpaceEx,\
            SHGetFolderPath,\
            SHGetNewLinkInfo,\
            SHPathPrepareForWrite
    else
        if (NTDDI_VERSION > NTDDI_WIN95)
            extrn '__imp__SHGetNewLinkInfo@20' as SHGetNewLinkInfo:dword
        end if
    end if

    if (NTDDI_VERSION <= NTDDI_WINXP)
        ;extrn '__imp__ExtractIconResInfoA@20' as ExtractIconResInfoA:dword ;Not present in MASM32 shell32.lib
        ;extrn '__imp__ExtractIconResInfoW@20' as ExtractIconResInfoW:dword ;Not present in MASM32 shell32.lib
        ;extrn '__imp__ExtractVersionResource16W@8' as ExtractVersionResource16W:dword ;Not present in MASM32 shell32.lib
        extrn '__imp__ILCreateFromPathA@4' as ILCreateFromPathA:dword
        extrn '__imp__ILCreateFromPathW@4' as ILCreateFromPathW:dword
        ;extrn '__imp__SheFullPathA@12' as SheFullPathA:dword ;Not present in MASM32 shell32.lib
        ;extrn '__imp__SheFullPathW@12' as SheFullPathW:dword ;Not present in MASM32 shell32.lib
        ;extrn '__imp__SheGetCurDrive@0' as SheGetCurDrive:dword ;Not present in MASM32 shell32.lib
        ;extrn '__imp__SheGetDirExW@12' as SheGetDirExW:dword ;Not present in MASM32 shell32.lib
        ;extrn '__imp__SheGetPathOffsetW@4' as SheGetPathOffsetW:dword ;Not present in MASM32 shell32.lib
        ;extrn '__imp__SheRemoveQuotesA@4' as SheRemoveQuotesA:dword ;Not present in MASM32 shell32.lib
        ;extrn '__imp__SheRemoveQuotesW@4' as SheRemoveQuotesW:dword ;Not present in MASM32 shell32.lib
        ;extrn '__imp__SheShortenPathA@8' as SheShortenPathA:dword  ;Not present in MASM32 shell32.lib
        ;extrn '__imp__SheShortenPathW@8' as SheShortenPathW:dword  ;Not present in MASM32 shell32.lib
        api ILCreateFromPath        ;,\
            ;ExtractIconResInfo,\   ;Not present in MASM32 shell32.lib
            ;SheFullPath,\          ;Not present in MASM32 shell32.lib
            ;SheRemoveQuotes,\      ;Not present in MASM32 shell32.lib
            ;SheShortenPath         ;Not present in MASM32 shell32.lib
    end if

    if (NTDDI_VERSION >= NTDDI_WINXP)
        extrn '__imp__AppCompat_RunDLLW@16' as AppCompat_RunDLLW:dword
        if (NTDDI_VERSION <= NTDDI_VISTA)
            extrn '__imp__CDefFolderMenu_Create@36' as CDefFolderMenu_Create:dword
            extrn '__imp__Control_FillCache_RunDLLA@16' as Control_FillCache_RunDLLA:dword
            extrn '__imp__Control_FillCache_RunDLLW@16' as Control_FillCache_RunDLLW:dword
            extrn '__imp__SHRunControlPanel@8' as SHRunControlPanel:dword
        end if
        extrn '__imp__CDefFolderMenu_Create2@36' as CDefFolderMenu_Create2:dword
        extrn '__imp__Control_RunDLLAsUserW@16' as Control_RunDLLAsUserW:dword
        extrn '__imp__DAD_AutoScroll@12' as DAD_AutoScroll:dword
        extrn '__imp__DAD_DragEnterEx@8' as DAD_DragEnterEx:dword
        extrn '__imp__DAD_DragEnterEx2@12' as DAD_DragEnterEx2:dword
        extrn '__imp__DAD_DragLeave@0' as DAD_DragLeave:dword
        extrn '__imp__DAD_DragMove@4' as DAD_DragMove:dword
        extrn '__imp__DAD_SetDragImage@8' as DAD_SetDragImage:dword
        extrn '__imp__DAD_ShowDragImage@4' as DAD_ShowDragImage:dword
        extrn '__imp__GetFileNameFromBrowse@28' as GetFileNameFromBrowse:dword
        extrn '__imp__ILAppendID@12' as ILAppendID:dword
        extrn '__imp__ILClone@4' as ILClone:dword
        extrn '__imp__ILCloneFirst@4' as ILCloneFirst:dword
        extrn '__imp__ILCombine@8' as ILCombine:dword
        extrn '__imp__ILFindChild@8' as ILFindChild:dword
        extrn '__imp__ILFindLastID@4' as ILFindLastID:dword
        extrn '__imp__ILFree@4' as ILFree:dword
        extrn '__imp__ILGetNext@4' as ILGetNext:dword
        extrn '__imp__ILGetSize@4' as ILGetSize:dword
        extrn '__imp__ILIsEqual@8' as ILIsEqual:dword
        extrn '__imp__ILIsParent@12' as ILIsParent:dword
        if (NTDDI_VERSION = NTDDI_WINXP)
            extrn '__imp__ILLoadFromStream@8' as ILLoadFromStream:dword
            extrn '__imp__PathProcessCommand@16' as PathProcessCommand:dword
            extrn '__imp__SHAllocShared@12' as SHAllocShared:dword
            extrn '__imp__SHGetSetFolderCustomSettingsW@12' as SHGetSetFolderCustomSettingsW:dword
        end if
        extrn '__imp__ILLoadFromStreamEx@8' as ILLoadFromStreamEx:dword
        extrn '__imp__ILRemoveLastID@4' as ILRemoveLastID:dword
        extrn '__imp__ILSaveToStream@8' as ILSaveToStream:dword
        extrn '__imp__IsLFNDrive@4' as IsLFNDrive:dword
        extrn '__imp__IsLFNDriveA@4' as IsLFNDriveA:dword
        extrn '__imp__IsLFNDriveW@4' as IsLFNDriveW:dword
        extrn '__imp__IsNetDrive@4' as IsNetDrive:dword
        extrn '__imp__IsUserAnAdmin@0' as IsUserAnAdmin:dword
        extrn '__imp__OpenRegStream@16' as OpenRegStream:dword
        extrn '__imp__Options_RunDLLA@16' as Options_RunDLLA:dword
        extrn '__imp__Options_RunDLLW@16' as Options_RunDLLW:dword
        extrn '__imp__PathCleanupSpec@8' as PathCleanupSpec:dword
        extrn '__imp__PathGetShortPath@4' as PathGetShortPath:dword
        extrn '__imp__PathIsExe@4' as PathIsExe:dword
        extrn '__imp__PathIsSlowA@8' as PathIsSlowA:dword
        extrn '__imp__PathIsSlowW@8' as PathIsSlowW:dword
        extrn '__imp__PathMakeUniqueName@20' as PathMakeUniqueName:dword
        extrn '__imp__PathResolve@12' as PathResolve:dword
        extrn '__imp__PathYetAnotherMakeUniqueName@16' as PathYetAnotherMakeUniqueName:dword
        extrn '__imp__PickIconDlg@16' as PickIconDlg:dword
        extrn '__imp__PifMgr_CloseProperties@8' as PifMgr_CloseProperties:dword
        extrn '__imp__PifMgr_GetProperties@20' as PifMgr_GetProperties:dword
        extrn '__imp__PifMgr_OpenProperties@16' as PifMgr_OpenProperties:dword
        extrn '__imp__PifMgr_SetProperties@20' as PifMgr_SetProperties:dword
        extrn '__imp__ReadCabinetState@8' as ReadCabinetState:dword
        extrn '__imp__RealDriveType@8' as RealDriveType:dword
        extrn '__imp__RestartDialog@12' as RestartDialog:dword
        extrn '__imp__RestartDialogEx@16' as RestartDialogEx:dword
        extrn '__imp__SHAddFromPropSheetExtArray@12' as SHAddFromPropSheetExtArray:dword
        extrn '__imp__SHAlloc@4' as SHAlloc:dword
        extrn '__imp__SHChangeNotification_Lock@16' as SHChangeNotification_Lock:dword
        extrn '__imp__SHChangeNotification_Unlock@4' as SHChangeNotification_Unlock:dword
        extrn '__imp__SHChangeNotifyDeregister@4' as SHChangeNotifyDeregister:dword
        extrn '__imp__SHChangeNotifyRegister@20' as SHChangeNotifyRegister:dword
        extrn '__imp__SHChangeNotifySuspendResume@16' as SHChangeNotifySuspendResume:dword
        extrn '__imp__SHCloneSpecialIDList@12' as SHCloneSpecialIDList:dword
        extrn '__imp__SHCLSIDFromString@8' as SHCLSIDFromString:dword
        extrn '__imp__SHCoCreateInstance@20' as SHCoCreateInstance:dword
        extrn '__imp__SHCreateFileExtractIconW@16' as SHCreateFileExtractIconW:dword
        extrn '__imp__SHCreateProcessAsUserW@4' as SHCreateProcessAsUserW:dword
        extrn '__imp__SHCreatePropSheetExtArray@12' as SHCreatePropSheetExtArray:dword
        extrn '__imp__SHCreateQueryCancelAutoPlayMoniker@4' as SHCreateQueryCancelAutoPlayMoniker:dword
        extrn '__imp__SHCreateShellFolderView@8' as SHCreateShellFolderView:dword
        extrn '__imp__SHCreateShellFolderViewEx@8' as SHCreateShellFolderViewEx:dword
        extrn '__imp__SHCreateShellItem@16' as SHCreateShellItem:dword
        extrn '__imp__SHCreateStdEnumFmtEtc@12' as SHCreateStdEnumFmtEtc:dword
        extrn '__imp__SHDefExtractIconA@24' as SHDefExtractIconA:dword
        extrn '__imp__SHDefExtractIconW@24' as SHDefExtractIconW:dword
        extrn '__imp__SHDestroyPropSheetExtArray@4' as SHDestroyPropSheetExtArray:dword
        extrn '__imp__SHDoDragDrop@20' as SHDoDragDrop:dword
        extrn '__imp__SheChangeDirA@4' as SheChangeDirA:dword
        extrn '__imp__SheChangeDirW@4' as SheChangeDirW:dword
        extrn '__imp__SheChangeDirExA@4' as SheChangeDirExA:dword
        extrn '__imp__SheChangeDirExW@4' as SheChangeDirExW:dword
        extrn '__imp__Shell_GetCachedImageIndex@12' as Shell_GetCachedImageIndex:dword
        extrn '__imp__Shell_GetImageLists@8' as Shell_GetImageLists:dword
        extrn '__imp__Shell_MergeMenus@24' as Shell_MergeMenus:dword
        extrn '__imp__ShellMessageBoxA@20' as ShellMessageBoxA:dword
        extrn '__imp__ShellMessageBoxW@20' as ShellMessageBoxW:dword
        extrn '__imp__SHEnableServiceObject@8' as SHEnableServiceObject:dword
        extrn '__imp__SHEnumerateUnreadMailAccountsW@16' as SHEnumerateUnreadMailAccountsW:dword
        extrn '__imp__SHExtractIconsW@32' as SHExtractIconsW:dword
        extrn '__imp__SHFind_InitMenuPopup@16' as SHFind_InitMenuPopup:dword
        extrn '__imp__SHFindFiles@8' as SHFindFiles:dword
        if (NTDDI_VERSION <= NTDDI_WINXPSP2)
            extrn '__imp__SHFlushClipboard@0' as SHFlushClipboard:dword
            extrn '__imp__SHFreeShared@8' as SHFreeShared:dword
            extrn '__imp__SHGetShellStyleHInstance@0' as SHGetShellStyleHInstance:dword
            extrn '__imp__SHLockShared@8' as SHLockShared:dword
            extrn '__imp__SHUnlockShared@4' as SHUnlockShared:dword
        end if
        extrn '__imp__SHFlushSFCache@0' as SHFlushSFCache:dword
        extrn '__imp__SHFree@4' as SHFree:dword
        extrn '__imp__SHGetAttributesFromDataObject@16' as SHGetAttributesFromDataObject:dword
        extrn '__imp__SHGetFolderPathAndSubDirA@24' as SHGetFolderPathAndSubDirA:dword
        extrn '__imp__SHGetFolderPathAndSubDirW@24' as SHGetFolderPathAndSubDirW:dword
        extrn '__imp__SHGetIconOverlayIndexA@8' as SHGetIconOverlayIndexA:dword
        extrn '__imp__SHGetIconOverlayIndexW@8' as SHGetIconOverlayIndexW:dword
        extrn '__imp__SHGetImageList@12' as SHGetImageList:dword
        extrn '__imp__SHGetRealIDL@12' as SHGetRealIDL:dword
        extrn '__imp__SHGetSetFolderCustomSettings@12' as SHGetSetFolderCustomSettings:dword
        extrn '__imp__SHGetSetSettings@12' as SHGetSetSettings:dword
        extrn '__imp__SHGetUnreadMailCountW@24' as SHGetUnreadMailCountW:dword
        extrn '__imp__SHHandleUpdateImage@4' as SHHandleUpdateImage:dword
        extrn '__imp__SHILCreateFromPath@12' as SHILCreateFromPath:dword
        extrn '__imp__SHIsFileAvailableOffline@8' as SHIsFileAvailableOffline:dword
        extrn '__imp__SHLimitInputEdit@8' as SHLimitInputEdit:dword
        extrn '__imp__SHLoadNonloadedIconOverlayIdentifiers@0' as SHLoadNonloadedIconOverlayIdentifiers:dword
        extrn '__imp__SHMapPIDLToSystemImageListIndex@12' as SHMapPIDLToSystemImageListIndex:dword
        extrn '__imp__SHMultiFileProperties@8' as SHMultiFileProperties:dword
        extrn '__imp__SHObjectProperties@16' as SHObjectProperties:dword
        extrn '__imp__SHOpenFolderAndSelectItems@16' as SHOpenFolderAndSelectItems:dword
        extrn '__imp__SHOpenPropSheetW@28' as SHOpenPropSheetW:dword
        extrn '__imp__SHParseDisplayName@20' as SHParseDisplayName:dword
        extrn '__imp__SHPropStgCreate@32' as SHPropStgCreate:dword
        extrn '__imp__SHPropStgReadMultiple@20' as SHPropStgReadMultiple:dword
        extrn '__imp__SHPropStgWriteMultiple@24' as SHPropStgWriteMultiple:dword
        extrn '__imp__SHReplaceFromPropSheetExtArray@16' as SHReplaceFromPropSheetExtArray:dword
        extrn '__imp__SHRestricted@4' as SHRestricted:dword
        extrn '__imp__SHSetInstanceExplorer@4' as SHSetInstanceExplorer:dword
        extrn '__imp__SHSetLocalizedName@12' as SHSetLocalizedName:dword
        extrn '__imp__SHSetUnreadMailCountW@12' as SHSetUnreadMailCountW:dword
        extrn '__imp__SHShellFolderView_Message@12' as SHShellFolderView_Message:dword
        extrn '__imp__SHSimpleIDListFromPath@4' as SHSimpleIDListFromPath:dword
        extrn '__imp__SHStartNetConnectionDialogW@12' as SHStartNetConnectionDialogW:dword
        extrn '__imp__SHTestTokenMembership@8' as SHTestTokenMembership:dword
        extrn '__imp__SHUpdateImageA@16' as SHUpdateImageA:dword
        extrn '__imp__SHUpdateImageW@16' as SHUpdateImageW:dword
        extrn '__imp__SHValidateUNC@12' as SHValidateUNC:dword
        extrn '__imp__SignalFileOpen@4' as SignalFileOpen:dword
        extrn '__imp__Win32DeleteFile@4' as Win32DeleteFile:dword
        extrn '__imp__WriteCabinetState@4' as WriteCabinetState:dword

        api Options_RunDLL,\
            PathIsSlow,\
            SheChangeDir,\
            SheChangeDirEx,\
            ShellMessageBox,\
            SHGetFolderPathAndSubDir,\
            SHGetIconOverlayIndex,\
            SHUpdateImage
        SHGetUnreadMailCount equ SHGetUnreadMailCountW
    end if

    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__AssocCreateForClasses@12' as AssocCreateForClasses:dword
        extrn '__imp__AssocGetDetailsOfPropKey@20' as AssocGetDetailsOfPropKey:dword
        extrn '__imp__CIDLData_CreateFromIDArray@16' as CIDLData_CreateFromIDArray:dword
        extrn '__imp__InitNetworkAddressControl@0' as InitNetworkAddressControl:dword
        extrn '__imp__SHAddDefaultPropertiesByExt@8' as SHAddDefaultPropertiesByExt:dword
        extrn '__imp__SHAssocEnumHandlers@12' as SHAssocEnumHandlers:dword
        extrn '__imp__SHBindToFolderIDListParent@20' as SHBindToFolderIDListParent:dword
        extrn '__imp__SHBindToFolderIDListParentEx@24' as SHBindToFolderIDListParentEx:dword
        extrn '__imp__SHBindToObject@20' as SHBindToObject:dword
        extrn '__imp__SHChangeNotifyRegisterThread@4' as SHChangeNotifyRegisterThread:dword
        extrn '__imp__SHCreateAssociationRegistration@8' as SHCreateAssociationRegistration:dword
        extrn '__imp__SHCreateDataObject@24' as SHCreateDataObject:dword
        extrn '__imp__SHCreateDefaultContextMenu@12' as SHCreateDefaultContextMenu:dword
        extrn '__imp__SHCreateDefaultExtractIcon@8' as SHCreateDefaultExtractIcon:dword
        extrn '__imp__SHCreateDefaultPropertiesOp@8' as SHCreateDefaultPropertiesOp:dword
        extrn '__imp__SHCreateItemFromIDList@12' as SHCreateItemFromIDList:dword
        extrn '__imp__SHCreateItemFromParsingName@16' as SHCreateItemFromParsingName:dword
        extrn '__imp__SHCreateItemFromRelativeName@20' as SHCreateItemFromRelativeName:dword
        extrn '__imp__SHCreateItemInKnownFolder@20' as SHCreateItemInKnownFolder:dword
        extrn '__imp__SHCreateItemWithParent@20' as SHCreateItemWithParent:dword
        extrn '__imp__SHCreateShellItemArray@20' as SHCreateShellItemArray:dword
        extrn '__imp__SHCreateShellItemArrayFromDataObject@12' as SHCreateShellItemArrayFromDataObject:dword
        extrn '__imp__SHCreateShellItemArrayFromIDLists@12' as SHCreateShellItemArrayFromIDLists:dword
        extrn '__imp__SHCreateShellItemArrayFromShellItem@12' as SHCreateShellItemArrayFromShellItem:dword
        extrn '__imp__Shell_GetCachedImageIndexA@12' as Shell_GetCachedImageIndexA:dword
        extrn '__imp__Shell_GetCachedImageIndexW@12' as Shell_GetCachedImageIndexW:dword
        extrn '__imp__SHEvaluateSystemCommandTemplate@16' as SHEvaluateSystemCommandTemplate:dword
        extrn '__imp__SHGetDriveMedia@8' as SHGetDriveMedia:dword
        extrn '__imp__SHGetFolderPathEx@20' as SHGetFolderPathEx:dword
        extrn '__imp__SHGetIDListFromObject@8' as SHGetIDListFromObject:dword
        extrn '__imp__SHGetKnownFolderIDList@16' as SHGetKnownFolderIDList:dword
        extrn '__imp__SHGetKnownFolderPath@16' as SHGetKnownFolderPath:dword
        extrn '__imp__SHGetLocalizedName@16' as SHGetLocalizedName:dword
        extrn '__imp__SHGetNameFromIDList@12' as SHGetNameFromIDList:dword
        extrn '__imp__SHGetPathFromIDListEx@16' as SHGetPathFromIDListEx:dword
        extrn '__imp__SHGetPropertyStoreFromIDList@16' as SHGetPropertyStoreFromIDList:dword
        extrn '__imp__SHGetPropertyStoreFromParsingName@20' as SHGetPropertyStoreFromParsingName:dword
        extrn '__imp__SHGetStockIconInfo@0' as SHGetStockIconInfo:dword
        extrn '__imp__SHGetTemporaryPropertyForItem@0' as SHGetTemporaryPropertyForItem:dword
        extrn '__imp__SHOpenWithDialog@0' as SHOpenWithDialog:dword
        extrn '__imp__SHQueryUserNotificationState@0' as SHQueryUserNotificationState:dword
        extrn '__imp__SHRemoveLocalizedName@0' as SHRemoveLocalizedName:dword
        extrn '__imp__SHSetDefaultProperties@0' as SHSetDefaultProperties:dword
        extrn '__imp__SHSetFolderPathA@0' as SHSetFolderPathA:dword
        extrn '__imp__SHSetFolderPathW@0' as SHSetFolderPathW:dword
        extrn '__imp__SHSetKnownFolderPath@0' as SHSetKnownFolderPath:dword
        extrn '__imp__SHSetTemporaryPropertyForItem@0' as SHSetTemporaryPropertyForItem:dword
        extrn '__imp__WaitForExplorerRestartW@0' as WaitForExplorerRestartW:dword

        api Shell_GetCachedImageIndex,\
            SHSetFolderPath
    end if

    if (NTDDI_VERSION >= NTDDI_WIN7)
        extrn '__imp__GetCurrentProcessExplicitAppUserModelID@4' as GetCurrentProcessExplicitAppUserModelID:dword
        extrn '__imp__RunAsNewUser_RunDLLW@16' as RunAsNewUser_RunDLLW:dword
        extrn '__imp__SetCurrentProcessExplicitAppUserModelID@4' as SetCurrentProcessExplicitAppUserModelID:dword
        extrn '__imp__SHAssocEnumHandlersForProtocolByApplication@12' as SHAssocEnumHandlersForProtocolByApplication:dword
        extrn '__imp__Shell_NotifyIconGetRect@8' as Shell_NotifyIconGetRect:dword
        extrn '__imp__SHGetItemFromDataObject@16' as SHGetItemFromDataObject:dword
        extrn '__imp__SHGetItemFromObject@12' as SHGetItemFromObject:dword
        extrn '__imp__SHGetKnownFolderItem@20' as SHGetKnownFolderItem:dword
        extrn '__imp__SHGetPropertyStoreForWindow@12' as SHGetPropertyStoreForWindow:dword
        extrn '__imp__SHResolveLibrary@4' as SHResolveLibrary:dword
        extrn '__imp__SHShowManageLibraryUI@20' as SHShowManageLibraryUI:dword
        extrn '__imp__StgMakeUniqueName@20' as StgMakeUniqueName:dword
    end if

    if (NTDDI_VERSION >= NTDDI_WIN8)
        extrn '__imp__DllGetActivationFactory@8' as DllGetActivationFactory:dword
    end if

    if (NTDDI_VERSION >= NTDDI_WIN10)
        extrn '__imp__IsProcessAnExplorer@0' as IsProcessAnExplorer:dword
    end if

    api DoEnvironmentSubst,\
        ExtractAssociatedIconEx,\
        ExtractAssociatedIcon,\
        ExtractIcon,\
        FindExecutable,\
        InternalExtractIconList,\
        RealShellExecute,\
        RealShellExecuteEx,\
        ShellAbout,\
        ShellExecute
end if

;======================= Undocumented functions (unknown arguments) =======================;
;if defined APP_WIN64
;    extrn '__imp_Activate_RunDLL' as Activate_RunDLL:qword
;    extrn '__imp_CreateStorageItemFromPath_FullTrustCaller' as CreateStorageItemFromPath_FullTrustCaller:qword
;    extrn '__imp_CreateStorageItemFromPath_FullTrustCaller_ForPackage' as CreateStorageItemFromPath_FullTrustCaller_ForPackage:qword
;    extrn '__imp_CreateStorageItemFromPath_PartialTrustCaller' as CreateStorageItemFromPath_PartialTrustCaller:qword
;    extrn '__imp_CreateStorageItemFromShellItem_FullTrustCaller' as CreateStorageItemFromShellItem_FullTrustCaller:qword
;    extrn '__imp_CreateStorageItemFromShellItem_FullTrustCaller_ForPackage' as CreateStorageItemFromShellItem_FullTrustCaller_ForPackage:qword
;    extrn '__imp_CreateStorageItemFromShellItem_FullTrustCaller_ForPackage_WithProcessHandle' as CreateStorageItemFromShellItem_FullTrustCaller_ForPackage_WithProcessHandle:qword
;    extrn '__imp_CreateStorageItemFromShellItem_FullTrustCaller_UseImplicitFlagsAndPackage' as CreateStorageItemFromShellItem_FullTrustCaller_UseImplicitFlagsAndPackage:qword
;    extrn '__imp_CStorageItem_GetValidatedStorageItemObject' as CStorageItem_GetValidatedStorageItemObject:qword
;    extrn '__imp_GetSystemPersistedStorageItemList' as GetSystemPersistedStorageItemList:qword
;    extrn '__imp_IsDesktopExplorerProcess' as IsDesktopExplorerProcess:qword
;    extrn '__imp_LaunchMSHelp_RunDLLW' as LaunchMSHelp_RunDLLW:qword
;    extrn '__imp_PathCleanupSpecWorker' as PathCleanupSpecWorker:qword
;    extrn '__imp_PathIsExeWorker' as PathIsExeWorker:qword
;    extrn '__imp_PathQualify' as PathQualify:qword
;    extrn '__imp_PrepareDiscForBurnRunDllW' as PrepareDiscForBurnRunDllW:qword
;    extrn '__imp_PrintersGetCommand_RunDLLA' as PrintersGetCommand_RunDLLA:qword
;    extrn '__imp_PrintersGetCommand_RunDLLW' as PrintersGetCommand_RunDLLW:qword
;    extrn '__imp_SHELL32_AddToBackIconTable' as SHELL32_AddToBackIconTable:qword
;    extrn '__imp_SHELL32_AddToFrontIconTable' as SHELL32_AddToFrontIconTable:qword
;    extrn '__imp_SHELL32_AreAllItemsAvailable' as SHELL32_AreAllItemsAvailable:qword
;    extrn '__imp_SHELL32_BindToFilePlaceholderHandler' as SHELL32_BindToFilePlaceholderHandler:qword
;    extrn '__imp_SHELL32_CallFileCopyHooks' as SHELL32_CallFileCopyHooks:qword
;    extrn '__imp_SHELL32_CanDisplayWin8CopyDialog' as SHELL32_CanDisplayWin8CopyDialog:qword
;    extrn '__imp_SHELL32_CCommonPlacesFolder_CreateInstance' as SHELL32_CCommonPlacesFolder_CreateInstance:qword
;    extrn '__imp_SHELL32_CDBurn_CloseSession' as SHELL32_CDBurn_CloseSession:qword
;    extrn '__imp_SHELL32_CDBurn_DriveSupportedForDataBurn' as SHELL32_CDBurn_DriveSupportedForDataBurn:qword
;    extrn '__imp_SHELL32_CDBurn_Erase' as SHELL32_CDBurn_Erase:qword
;    extrn '__imp_SHELL32_CDBurn_GetCDInfo' as SHELL32_CDBurn_GetCDInfo:qword
;    extrn '__imp_SHELL32_CDBurn_GetLiveFSDiscInfo' as SHELL32_CDBurn_GetLiveFSDiscInfo:qword
;    extrn '__imp_SHELL32_CDBurn_GetStagingPathOrNormalPath' as SHELL32_CDBurn_GetStagingPathOrNormalPath:qword
;    extrn '__imp_SHELL32_CDBurn_GetTaskInfo' as SHELL32_CDBurn_GetTaskInfo:qword
;    extrn '__imp_SHELL32_CDBurn_IsBlankDisc' as SHELL32_CDBurn_IsBlankDisc:qword
;    extrn '__imp_SHELL32_CDBurn_IsBlankDisc2' as SHELL32_CDBurn_IsBlankDisc2:qword
;    extrn '__imp_SHELL32_CDBurn_IsLiveFS' as SHELL32_CDBurn_IsLiveFS:qword
;    extrn '__imp_SHELL32_CDBurn_OnDeviceChange' as SHELL32_CDBurn_OnDeviceChange:qword
;    extrn '__imp_SHELL32_CDBurn_OnEject' as SHELL32_CDBurn_OnEject:qword
;    extrn '__imp_SHELL32_CDBurn_OnMediaChange' as SHELL32_CDBurn_OnMediaChange:qword
;    extrn '__imp_SHELL32_CDefFolderMenu_Create2' as SHELL32_CDefFolderMenu_Create2:qword
;    extrn '__imp_SHELL32_CDefFolderMenu_Create2Ex' as SHELL32_CDefFolderMenu_Create2Ex:qword
;    extrn '__imp_SHELL32_CDefFolderMenu_MergeMenu' as SHELL32_CDefFolderMenu_MergeMenu:qword
;    extrn '__imp_SHELL32_CDrivesContextMenu_Create' as SHELL32_CDrivesContextMenu_Create:qword
;    extrn '__imp_SHELL32_CDrivesDropTarget_Create' as SHELL32_CDrivesDropTarget_Create:qword
;    extrn '__imp_SHELL32_CFillPropertiesTask_CreateInstance' as SHELL32_CFillPropertiesTask_CreateInstance:qword
;    extrn '__imp_SHELL32_CFSDropTarget_CreateInstance' as SHELL32_CFSDropTarget_CreateInstance:qword
;    extrn '__imp_SHELL32_CFSFolderCallback_Create' as SHELL32_CFSFolderCallback_Create:qword
;    extrn '__imp_SHELL32_CLibraryDropTarget_CreateInstance' as SHELL32_CLibraryDropTarget_CreateInstance:qword
;    extrn '__imp_SHELL32_CLocationContextMenu_Create' as SHELL32_CLocationContextMenu_Create:qword
;    extrn '__imp_SHELL32_CloseAutoplayPrompt' as SHELL32_CloseAutoplayPrompt:qword
;    extrn '__imp_SHELL32_CMountPoint_DoAutorun' as SHELL32_CMountPoint_DoAutorun:qword
;    extrn '__imp_SHELL32_CMountPoint_DoAutorunPrompt' as SHELL32_CMountPoint_DoAutorunPrompt:qword
;    extrn '__imp_SHELL32_CMountPoint_IsAutoRunDriveAndEnabledByPolicy' as SHELL32_CMountPoint_IsAutoRunDriveAndEnabledByPolicy:qword
;    extrn '__imp_SHELL32_CMountPoint_ProcessAutoRunFile' as SHELL32_CMountPoint_ProcessAutoRunFile:qword
;    extrn '__imp_SHELL32_CMountPoint_WantAutorunUI' as SHELL32_CMountPoint_WantAutorunUI:qword
;    extrn '__imp_SHELL32_CMountPoint_WantAutorunUIGetReady' as SHELL32_CMountPoint_WantAutorunUIGetReady:qword
;    extrn '__imp_SHELL32_CommandLineFromMsiDescriptor' as SHELL32_CommandLineFromMsiDescriptor:qword
;    extrn '__imp_SHELL32_CopyExtrinsicPropertyStore' as SHELL32_CopyExtrinsicPropertyStore:qword
;    extrn '__imp_SHELL32_CopyFilePlaceholderToNewFile' as SHELL32_CopyFilePlaceholderToNewFile:qword
;    extrn '__imp_SHELL32_CopySecondaryTiles' as SHELL32_CopySecondaryTiles:qword
;    extrn '__imp_SHELL32_CPL_CategoryIdArrayFromVariant' as SHELL32_CPL_CategoryIdArrayFromVariant:qword
;    extrn '__imp_SHELL32_CPL_IsLegacyCanonicalNameListedUnderKey' as SHELL32_CPL_IsLegacyCanonicalNameListedUnderKey:qword
;    extrn '__imp_SHELL32_CPL_ModifyWowDisplayName' as SHELL32_CPL_ModifyWowDisplayName:qword
;    extrn '__imp_SHELL32_Create_IEnumUICommand' as SHELL32_Create_IEnumUICommand:qword
;    extrn '__imp_SHELL32_CreateAlternateStreamFileName' as SHELL32_CreateAlternateStreamFileName:qword
;    extrn '__imp_SHELL32_CreateConfirmationInterrupt' as SHELL32_CreateConfirmationInterrupt:qword
;    extrn '__imp_SHELL32_CreateConflictInterrupt' as SHELL32_CreateConflictInterrupt:qword
;    extrn '__imp_SHELL32_CreateDefaultOperationDataProvider' as SHELL32_CreateDefaultOperationDataProvider:qword
;    extrn '__imp_SHELL32_CreateExtrinsicPropertyStore' as SHELL32_CreateExtrinsicPropertyStore:qword
;    extrn '__imp_SHELL32_CreateFileFolderContextMenu' as SHELL32_CreateFileFolderContextMenu:qword
;    extrn '__imp_SHELL32_CreateLinkInfoW' as SHELL32_CreateLinkInfoW:qword
;    extrn '__imp_SHELL32_CreatePlaceholderFile' as SHELL32_CreatePlaceholderFile:qword
;    extrn '__imp_SHELL32_CreateQosRecorder' as SHELL32_CreateQosRecorder:qword
;    extrn '__imp_SHELL32_CreateSharePointView' as SHELL32_CreateSharePointView:qword
;    extrn '__imp_SHELL32_CRecentDocsContextMenu_CreateInstance' as SHELL32_CRecentDocsContextMenu_CreateInstance:qword
;    extrn '__imp_SHELL32_CSyncRootManager_CreateInstance' as SHELL32_CSyncRootManager_CreateInstance:qword
;    extrn '__imp_SHELL32_CTransferConfirmation_CreateInstance' as SHELL32_CTransferConfirmation_CreateInstance:qword
;    extrn '__imp_SHELL32_DestroyLinkInfo' as SHELL32_DestroyLinkInfo:qword
;    extrn '__imp_SHELL32_EncryptDirectory' as SHELL32_EncryptDirectory:qword
;    extrn '__imp_SHELL32_EncryptedFileKeyInfo' as SHELL32_EncryptedFileKeyInfo:qword
;    extrn '__imp_SHELL32_EnumCommonTasks' as SHELL32_EnumCommonTasks:qword
;    extrn '__imp_SHELL32_FilePlaceholder_BindToPrimaryStream' as SHELL32_FilePlaceholder_BindToPrimaryStream:qword
;    extrn '__imp_SHELL32_FilePlaceholder_CreateInstance' as SHELL32_FilePlaceholder_CreateInstance:qword
;    extrn '__imp_SHELL32_FreeEncryptedFileKeyInfo' as SHELL32_FreeEncryptedFileKeyInfo:qword
;    extrn '__imp_SHELL32_GenerateAppID' as SHELL32_GenerateAppID:qword
;    extrn '__imp_SHELL32_GetAppIDRoot' as SHELL32_GetAppIDRoot:qword
;    extrn '__imp_SHELL32_GetCommandProviderForFolderType' as SHELL32_GetCommandProviderForFolderType:qword
;    extrn '__imp_SHELL32_GetDiskCleanupPath' as SHELL32_GetDiskCleanupPath:qword
;    extrn '__imp_SHELL32_GetDPIAdjustedLogicalSize' as SHELL32_GetDPIAdjustedLogicalSize:qword
;    extrn '__imp_SHELL32_GetFileNameFromBrowse' as SHELL32_GetFileNameFromBrowse:qword
;    extrn '__imp_SHELL32_GetIconOverlayManager' as SHELL32_GetIconOverlayManager:qword
;    extrn '__imp_SHELL32_GetLinkInfoData' as SHELL32_GetLinkInfoData:qword
;    extrn '__imp_SHELL32_GetPlaceholderStatesFromFileAttributesAndReparsePointTag' as SHELL32_GetPlaceholderStatesFromFileAttributesAndReparsePointTag:qword
;    extrn '__imp_SHELL32_GetRatingBucket' as SHELL32_GetRatingBucket:qword
;    extrn '__imp_SHELL32_GetSkyDriveNetworkStates' as SHELL32_GetSkyDriveNetworkStates:qword
;    extrn '__imp_SHELL32_GetSqmableFileName' as SHELL32_GetSqmableFileName:qword
;    extrn '__imp_SHELL32_GetThumbnailAdornerFromFactory' as SHELL32_GetThumbnailAdornerFromFactory:qword
;    extrn '__imp_SHELL32_GetThumbnailAdornerFromFactory2' as SHELL32_GetThumbnailAdornerFromFactory2:qword
;    extrn '__imp_SHELL32_HandleUnrecognizedFileSystem' as SHELL32_HandleUnrecognizedFileSystem:qword
;    extrn '__imp_SHELL32_IconCache_AboutToExtractIcons' as SHELL32_IconCache_AboutToExtractIcons:qword
;    extrn '__imp_SHELL32_IconCache_DoneExtractingIcons' as SHELL32_IconCache_DoneExtractingIcons:qword
;    extrn '__imp_SHELL32_IconCache_ExpandEnvAndSearchPath' as SHELL32_IconCache_ExpandEnvAndSearchPath:qword
;    extrn '__imp_SHELL32_IconCache_RememberRecentlyExtractedIconsW' as SHELL32_IconCache_RememberRecentlyExtractedIconsW:qword
;    extrn '__imp_SHELL32_IconCacheCreate' as SHELL32_IconCacheCreate:qword
;    extrn '__imp_SHELL32_IconCacheDestroy' as SHELL32_IconCacheDestroy:qword
;    extrn '__imp_SHELL32_IconCacheHandleAssociationChanged' as SHELL32_IconCacheHandleAssociationChanged:qword
;    extrn '__imp_SHELL32_IconCacheRestore' as SHELL32_IconCacheRestore:qword
;    extrn '__imp_SHELL32_IconOverlayManagerInit' as SHELL32_IconOverlayManagerInit:qword
;    extrn '__imp_SHELL32_IsGetKeyboardLayoutPresent' as SHELL32_IsGetKeyboardLayoutPresent:qword
;    extrn '__imp_SHELL32_IsSystemUpgradeInProgress' as SHELL32_IsSystemUpgradeInProgress:qword
;    extrn '__imp_SHELL32_IsValidLinkInfo' as SHELL32_IsValidLinkInfo:qword
;    extrn '__imp_SHELL32_LegacyEnumSpecialTasksByType' as SHELL32_LegacyEnumSpecialTasksByType:qword
;    extrn '__imp_SHELL32_LegacyEnumTasks' as SHELL32_LegacyEnumTasks:qword
;    extrn '__imp_SHELL32_LookupBackIconIndex' as SHELL32_LookupBackIconIndex:qword
;    extrn '__imp_SHELL32_LookupFrontIconIndex' as SHELL32_LookupFrontIconIndex:qword
;    extrn '__imp_SHELL32_NormalizeRating' as SHELL32_NormalizeRating:qword
;    extrn '__imp_SHELL32_NotifyLinkTrackingServiceOfMove' as SHELL32_NotifyLinkTrackingServiceOfMove:qword
;    extrn '__imp_SHELL32_PifMgr_CloseProperties' as SHELL32_PifMgr_CloseProperties:qword
;    extrn '__imp_SHELL32_PifMgr_GetProperties' as SHELL32_PifMgr_GetProperties:qword
;    extrn '__imp_SHELL32_PifMgr_OpenProperties' as SHELL32_PifMgr_OpenProperties:qword
;    extrn '__imp_SHELL32_PifMgr_SetProperties' as SHELL32_PifMgr_SetProperties:qword
;    extrn '__imp_SHELL32_Printers_CreateBindInfo' as SHELL32_Printers_CreateBindInfo:qword
;    extrn '__imp_SHELL32_Printjob_GetPidl' as SHELL32_Printjob_GetPidl:qword
;    extrn '__imp_SHELL32_PurgeSystemIcon' as SHELL32_PurgeSystemIcon:qword
;    extrn '__imp_SHELL32_RefreshOverlayImages' as SHELL32_RefreshOverlayImages:qword
;    extrn '__imp_SHELL32_ResolveLinkInfoW' as SHELL32_ResolveLinkInfoW:qword
;    extrn '__imp_SHELL32_SendToMenu_InvokeTargetedCommand' as SHELL32_SendToMenu_InvokeTargetedCommand:qword
;    extrn '__imp_SHELL32_SendToMenu_VerifyTargetedCommand' as SHELL32_SendToMenu_VerifyTargetedCommand:qword
;    extrn '__imp_SHELL32_SetPlaceholderReparsePointAttribute' as SHELL32_SetPlaceholderReparsePointAttribute:qword
;    extrn '__imp_SHELL32_SetPlaceholderReparsePointAttribute2' as SHELL32_SetPlaceholderReparsePointAttribute2:qword
;    extrn '__imp_SHELL32_SHAddSparseIcon' as SHELL32_SHAddSparseIcon:qword
;    extrn '__imp_SHELL32_SHCreateByValueOperationInterrupt' as SHELL32_SHCreateByValueOperationInterrupt:qword
;    extrn '__imp_SHELL32_SHCreateDefaultContextMenu' as SHELL32_SHCreateDefaultContextMenu:qword
;    extrn '__imp_SHELL32_SHCreateLocalServer' as SHELL32_SHCreateLocalServer:qword
;    extrn '__imp_SHELL32_SHCreateShellFolderView' as SHELL32_SHCreateShellFolderView:qword
;    extrn '__imp_SHELL32_SHDuplicateEncryptionInfoFile' as SHELL32_SHDuplicateEncryptionInfoFile:qword
;    extrn '__imp_SHELL32_SHEncryptFile' as SHELL32_SHEncryptFile:qword
;    extrn '__imp_SHELL32_SHFormatDriveAsync' as SHELL32_SHFormatDriveAsync:qword
;    extrn '__imp_SHELL32_SHGetThreadUndoManager' as SHELL32_SHGetThreadUndoManager:qword
;    extrn '__imp_SHELL32_SHGetUserNameW' as SHELL32_SHGetUserNameW:qword
;    extrn '__imp_SHELL32_SHIsVirtualDevice' as SHELL32_SHIsVirtualDevice:qword
;    extrn '__imp_SHELL32_SHLaunchPropSheet' as SHELL32_SHLaunchPropSheet:qword
;    extrn '__imp_SHELL32_SHLogILFromFSIL' as SHELL32_SHLogILFromFSIL:qword
;    extrn '__imp_SHELL32_SHOpenWithDialog' as SHELL32_SHOpenWithDialog:qword
;    extrn '__imp_SHELL32_ShowHideIconOnlyOnDesktop' as SHELL32_ShowHideIconOnlyOnDesktop:qword
;    extrn '__imp_SHELL32_SHUICommandFromGUID' as SHELL32_SHUICommandFromGUID:qword
;    extrn '__imp_SHELL32_SimpleRatingToFilterCondition' as SHELL32_SimpleRatingToFilterCondition:qword
;    extrn '__imp_SHELL32_StampIconForElevation' as SHELL32_StampIconForElevation:qword
;    extrn '__imp_SHELL32_SuspendUndo' as SHELL32_SuspendUndo:qword
;    extrn '__imp_SHELL32_TryVirtualDiscImageDriveEject' as SHELL32_TryVirtualDiscImageDriveEject:qword
;    extrn '__imp_SHELL32_UpdateFilePlaceholderStates' as SHELL32_UpdateFilePlaceholderStates:qword
;    extrn '__imp_SHELL32_VerifySaferTrust' as SHELL32_VerifySaferTrust:qword
;    extrn '__imp_SHCoCreateInstanceWorker' as SHCoCreateInstanceWorker:qword
;    extrn '__imp_SHCreateCategoryEnum' as SHCreateCategoryEnum:qword
;    extrn '__imp_SHCreateDirectoryExWWorker' as SHCreateDirectoryExWWorker:qword
;    extrn '__imp_SHCreateDrvExtIcon' as SHCreateDrvExtIcon:qword
;    extrn '__imp_SHCreateLocalServerRunDll' as SHCreateLocalServerRunDll:qword
;    extrn '__imp_SheConvertPathW' as SheConvertPathW:qword
;    extrn '__imp_SHGetDesktopFolderWorker' as SHGetDesktopFolderWorker:qword
;    extrn '__imp_SHGetFileInfoWWorker' as SHGetFileInfoWWorker:qword
;    extrn '__imp_SHGetFolderLocationWorker' as SHGetFolderLocationWorker:qword
;    extrn '__imp_SHGetFolderPathAndSubDirWWorker' as SHGetFolderPathAndSubDirWWorker:qword
;    extrn '__imp_SHGetFolderPathAWorker' as SHGetFolderPathAWorker:qword
;    extrn '__imp_SHGetFolderPathWWorker' as SHGetFolderPathWWorker:qword
;    extrn '__imp_SHGetInstanceExplorerWorker' as SHGetInstanceExplorerWorker:qword
;    extrn '__imp_SHGetKnownFolderPathWorker' as SHGetKnownFolderPathWorker:qword
;    extrn '__imp_SHSetKnownFolderPathWorker' as SHSetKnownFolderPathWorker:qword
;    extrn '__imp_SHGetSpecialFolderPathAWorker' as SHGetSpecialFolderPathAWorker:qword
;    extrn '__imp_SHGetSpecialFolderPathWWorker' as SHGetSpecialFolderPathWWorker:qword
;    extrn '__imp_StrCpyNA' as StrCpyNA:qword
;    extrn '__imp_StrCpyNW' as StrCpyNW:qword
;    extrn '__imp_StrNCpyA' as StrCpyNW:qword
;    extrn '__imp_StrNCpyW' as StrNCpyW:qword
;    extrn '__imp_UsersLibrariesFolderUI_CreateInstance' as UsersLibrariesFolderUI_CreateInstance:qword
;else
;    extrn '__imp__Activate_RunDLL@??' as Activate_RunDLL:dword
;    extrn '__imp__CreateStorageItemFromPath_FullTrustCaller@??' as CreateStorageItemFromPath_FullTrustCaller:dword
;    extrn '__imp__CreateStorageItemFromPath_FullTrustCaller_ForPackage@??' as CreateStorageItemFromPath_FullTrustCaller_ForPackage:dword
;    extrn '__imp__CreateStorageItemFromPath_PartialTrustCaller@??' as CreateStorageItemFromPath_PartialTrustCaller:dword
;    extrn '__imp__CreateStorageItemFromShellItem_FullTrustCaller@??' as CreateStorageItemFromShellItem_FullTrustCaller:dword
;    extrn '__imp__CreateStorageItemFromShellItem_FullTrustCaller_ForPackage@??' as CreateStorageItemFromShellItem_FullTrustCaller_ForPackage:dword
;    extrn '__imp__CreateStorageItemFromShellItem_FullTrustCaller_ForPackage_WithProcessHandle@??' as CreateStorageItemFromShellItem_FullTrustCaller_ForPackage_WithProcessHandle:dword
;    extrn '__imp__CreateStorageItemFromShellItem_FullTrustCaller_UseImplicitFlagsAndPackage@??' as CreateStorageItemFromShellItem_FullTrustCaller_UseImplicitFlagsAndPackage:dword
;    extrn '__imp__CStorageItem_GetValidatedStorageItemObject@??' as CStorageItem_GetValidatedStorageItemObject:dword
;    extrn '__imp__GetSystemPersistedStorageItemList@??' as GetSystemPersistedStorageItemList:dword
;    extrn '__imp__IsDesktopExplorerProcess@??' as IsDesktopExplorerProcess:dword
;    extrn '__imp__LaunchMSHelp_RunDLLW@??' as LaunchMSHelp_RunDLLW:dword
;    extrn '__imp__PathCleanupSpecWorker@??' as PathCleanupSpecWorker:dword
;    extrn '__imp__PathIsExeWorker@??' as PathIsExeWorker:dword
;    extrn '__imp__PathQualify@??' as PathQualify:dword
;    extrn '__imp__PrepareDiscForBurnRunDllW@??' as PrepareDiscForBurnRunDllW:dword
;    extrn '__imp__PrintersGetCommand_RunDLLA@??' as PrintersGetCommand_RunDLLA:dword
;    extrn '__imp__PrintersGetCommand_RunDLLW@??' as PrintersGetCommand_RunDLLW:dword
;    extrn '__imp__SHELL32_AddToBackIconTable@??' as SHELL32_AddToBackIconTable:dword
;    extrn '__imp__SHELL32_AddToFrontIconTable@??' as SHELL32_AddToFrontIconTable:dword
;    extrn '__imp__SHELL32_AreAllItemsAvailable@??' as SHELL32_AreAllItemsAvailable:dword
;    extrn '__imp__SHELL32_BindToFilePlaceholderHandler@??' as SHELL32_BindToFilePlaceholderHandler:dword
;    extrn '__imp__SHELL32_CallFileCopyHooks@??' as SHELL32_CallFileCopyHooks:dword
;    extrn '__imp__SHELL32_CanDisplayWin8CopyDialog@??' as SHELL32_CanDisplayWin8CopyDialog:dword
;    extrn '__imp__SHELL32_CCommonPlacesFolder_CreateInstance@??' as SHELL32_CCommonPlacesFolder_CreateInstance:dword
;    extrn '__imp__SHELL32_CDBurn_CloseSession@??' as SHELL32_CDBurn_CloseSession:dword
;    extrn '__imp__SHELL32_CDBurn_DriveSupportedForDataBurn@??' as SHELL32_CDBurn_DriveSupportedForDataBurn:dword
;    extrn '__imp__SHELL32_CDBurn_Erase@??' as SHELL32_CDBurn_Erase:dword
;    extrn '__imp__SHELL32_CDBurn_GetCDInfo@??' as SHELL32_CDBurn_GetCDInfo:dword
;    extrn '__imp__SHELL32_CDBurn_GetLiveFSDiscInfo@??' as SHELL32_CDBurn_GetLiveFSDiscInfo:dword
;    extrn '__imp__SHELL32_CDBurn_GetStagingPathOrNormalPath@??' as SHELL32_CDBurn_GetStagingPathOrNormalPath:dword
;    extrn '__imp__SHELL32_CDBurn_GetTaskInfo@??' as SHELL32_CDBurn_GetTaskInfo:dword
;    extrn '__imp__SHELL32_CDBurn_IsBlankDisc@??' as SHELL32_CDBurn_IsBlankDisc:dword
;    extrn '__imp__SHELL32_CDBurn_IsBlankDisc2@??' as SHELL32_CDBurn_IsBlankDisc2:dword
;    extrn '__imp__SHELL32_CDBurn_IsLiveFS@??' as SHELL32_CDBurn_IsLiveFS:dword
;    extrn '__imp__SHELL32_CDBurn_OnDeviceChange@??' as SHELL32_CDBurn_OnDeviceChange:dword
;    extrn '__imp__SHELL32_CDBurn_OnEject@??' as SHELL32_CDBurn_OnEject:dword
;    extrn '__imp__SHELL32_CDBurn_OnMediaChange@??' as SHELL32_CDBurn_OnMediaChange:dword
;    extrn '__imp__SHELL32_CDefFolderMenu_Create2@??' as SHELL32_CDefFolderMenu_Create2:dword
;    extrn '__imp__SHELL32_CDefFolderMenu_Create2Ex@??' as SHELL32_CDefFolderMenu_Create2Ex:dword
;    extrn '__imp__SHELL32_CDefFolderMenu_MergeMenu@??' as SHELL32_CDefFolderMenu_MergeMenu:dword
;    extrn '__imp__SHELL32_CDrivesContextMenu_Create@??' as SHELL32_CDrivesContextMenu_Create:dword
;    extrn '__imp__SHELL32_CDrivesDropTarget_Create@??' as SHELL32_CDrivesDropTarget_Create:dword
;    extrn '__imp__SHELL32_CFillPropertiesTask_CreateInstance@??' as SHELL32_CFillPropertiesTask_CreateInstance:dword
;    extrn '__imp__SHELL32_CFSDropTarget_CreateInstance@??' as SHELL32_CFSDropTarget_CreateInstance:dword
;    extrn '__imp__SHELL32_CFSFolderCallback_Create@??' as SHELL32_CFSFolderCallback_Create:dword
;    extrn '__imp__SHELL32_CLibraryDropTarget_CreateInstance@??' as SHELL32_CLibraryDropTarget_CreateInstance:dword
;    extrn '__imp__SHELL32_CLocationContextMenu_Create@??' as SHELL32_CLocationContextMenu_Create:dword
;    extrn '__imp__SHELL32_CloseAutoplayPrompt@??' as SHELL32_CloseAutoplayPrompt:dword
;    extrn '__imp__SHELL32_CMountPoint_DoAutorun@??' as SHELL32_CMountPoint_DoAutorun:dword
;    extrn '__imp__SHELL32_CMountPoint_DoAutorunPrompt@??' as SHELL32_CMountPoint_DoAutorunPrompt:dword
;    extrn '__imp__SHELL32_CMountPoint_IsAutoRunDriveAndEnabledByPolicy@??' as SHELL32_CMountPoint_IsAutoRunDriveAndEnabledByPolicy:dword
;    extrn '__imp__SHELL32_CMountPoint_ProcessAutoRunFile@??' as SHELL32_CMountPoint_ProcessAutoRunFile:dword
;    extrn '__imp__SHELL32_CMountPoint_WantAutorunUI@??' as SHELL32_CMountPoint_WantAutorunUI:dword
;    extrn '__imp__SHELL32_CMountPoint_WantAutorunUIGetReady@??' as SHELL32_CMountPoint_WantAutorunUIGetReady:dword
;    extrn '__imp__SHELL32_CommandLineFromMsiDescriptor@??' as SHELL32_CommandLineFromMsiDescriptor:dword
;    extrn '__imp__SHELL32_CopyExtrinsicPropertyStore@??' as SHELL32_CopyExtrinsicPropertyStore:dword
;    extrn '__imp__SHELL32_CopyFilePlaceholderToNewFile@??' as SHELL32_CopyFilePlaceholderToNewFile:dword
;    extrn '__imp__SHELL32_CopySecondaryTiles@??' as SHELL32_CopySecondaryTiles:dword
;    extrn '__imp__SHELL32_CPL_CategoryIdArrayFromVariant@??' as SHELL32_CPL_CategoryIdArrayFromVariant:dword
;    extrn '__imp__SHELL32_CPL_IsLegacyCanonicalNameListedUnderKey@??' as SHELL32_CPL_IsLegacyCanonicalNameListedUnderKey:dword
;    extrn '__imp__SHELL32_CPL_ModifyWowDisplayName@??' as SHELL32_CPL_ModifyWowDisplayName:dword
;    extrn '__imp__SHELL32_Create_IEnumUICommand@??' as SHELL32_Create_IEnumUICommand:dword
;    extrn '__imp__SHELL32_CreateAlternateStreamFileName@??' as SHELL32_CreateAlternateStreamFileName:dword
;    extrn '__imp__SHELL32_CreateConfirmationInterrupt@??' as SHELL32_CreateConfirmationInterrupt:dword
;    extrn '__imp__SHELL32_CreateConflictInterrupt@??' as SHELL32_CreateConflictInterrupt:dword
;    extrn '__imp__SHELL32_CreateDefaultOperationDataProvider@??' as SHELL32_CreateDefaultOperationDataProvider:dword
;    extrn '__imp__SHELL32_CreateExtrinsicPropertyStore@??' as SHELL32_CreateExtrinsicPropertyStore:dword
;    extrn '__imp__SHELL32_CreateFileFolderContextMenu@??' as SHELL32_CreateFileFolderContextMenu:dword
;    extrn '__imp__SHELL32_CreateLinkInfoW@??' as SHELL32_CreateLinkInfoW:dword
;    extrn '__imp__SHELL32_CreatePlaceholderFile@??' as SHELL32_CreatePlaceholderFile:dword
;    extrn '__imp__SHELL32_CreateQosRecorder@??' as SHELL32_CreateQosRecorder:dword
;    extrn '__imp__SHELL32_CreateSharePointView@??' as SHELL32_CreateSharePointView:dword
;    extrn '__imp__SHELL32_CRecentDocsContextMenu_CreateInstance@??' as SHELL32_CRecentDocsContextMenu_CreateInstance:dword
;    extrn '__imp__SHELL32_CSyncRootManager_CreateInstance@??' as SHELL32_CSyncRootManager_CreateInstance:dword
;    extrn '__imp__SHELL32_CTransferConfirmation_CreateInstance@??' as SHELL32_CTransferConfirmation_CreateInstance:dword
;    extrn '__imp__SHELL32_DestroyLinkInfo@??' as SHELL32_DestroyLinkInfo:dword
;    extrn '__imp__SHELL32_EncryptDirectory@??' as SHELL32_EncryptDirectory:dword
;    extrn '__imp__SHELL32_EncryptedFileKeyInfo@??' as SHELL32_EncryptedFileKeyInfo:dword
;    extrn '__imp__SHELL32_EnumCommonTasks@??' as SHELL32_EnumCommonTasks:dword
;    extrn '__imp__SHELL32_FilePlaceholder_BindToPrimaryStream@??' as SHELL32_FilePlaceholder_BindToPrimaryStream:dword
;    extrn '__imp__SHELL32_FilePlaceholder_CreateInstance@??' as SHELL32_FilePlaceholder_CreateInstance:dword
;    extrn '__imp__SHELL32_FreeEncryptedFileKeyInfo@??' as SHELL32_FreeEncryptedFileKeyInfo:dword
;    extrn '__imp__SHELL32_GenerateAppID@??' as SHELL32_GenerateAppID:dword
;    extrn '__imp__SHELL32_GetAppIDRoot@??' as SHELL32_GetAppIDRoot:dword
;    extrn '__imp__SHELL32_GetCommandProviderForFolderType@??' as SHELL32_GetCommandProviderForFolderType:dword
;    extrn '__imp__SHELL32_GetDiskCleanupPath@??' as SHELL32_GetDiskCleanupPath:dword
;    extrn '__imp__SHELL32_GetDPIAdjustedLogicalSize@??' as SHELL32_GetDPIAdjustedLogicalSize:dword
;    extrn '__imp__SHELL32_GetFileNameFromBrowse@??' as SHELL32_GetFileNameFromBrowse:dword
;    extrn '__imp__SHELL32_GetIconOverlayManager@??' as SHELL32_GetIconOverlayManager:dword
;    extrn '__imp__SHELL32_GetLinkInfoData@??' as SHELL32_GetLinkInfoData:dword
;    extrn '__imp__SHELL32_GetPlaceholderStatesFromFileAttributesAndReparsePointTag@??' as SHELL32_GetPlaceholderStatesFromFileAttributesAndReparsePointTag:dword
;    extrn '__imp__SHELL32_GetRatingBucket@??' as SHELL32_GetRatingBucket:dword
;    extrn '__imp__SHELL32_GetSkyDriveNetworkStates@??' as SHELL32_GetSkyDriveNetworkStates:dword
;    extrn '__imp__SHELL32_GetSqmableFileName@??' as SHELL32_GetSqmableFileName:dword
;    extrn '__imp__SHELL32_GetThumbnailAdornerFromFactory@??' as SHELL32_GetThumbnailAdornerFromFactory:dword
;    extrn '__imp__SHELL32_GetThumbnailAdornerFromFactory2@??' as SHELL32_GetThumbnailAdornerFromFactory2:dword
;    extrn '__imp__SHELL32_HandleUnrecognizedFileSystem@??' as SHELL32_HandleUnrecognizedFileSystem:dword
;    extrn '__imp__SHELL32_IconCache_AboutToExtractIcons@??' as SHELL32_IconCache_AboutToExtractIcons:dword
;    extrn '__imp__SHELL32_IconCache_DoneExtractingIcons@??' as SHELL32_IconCache_DoneExtractingIcons:dword
;    extrn '__imp__SHELL32_IconCache_ExpandEnvAndSearchPath@??' as SHELL32_IconCache_ExpandEnvAndSearchPath:dword
;    extrn '__imp__SHELL32_IconCache_RememberRecentlyExtractedIconsW@??' as SHELL32_IconCache_RememberRecentlyExtractedIconsW:dword
;    extrn '__imp__SHELL32_IconCacheCreate@??' as SHELL32_IconCacheCreate:dword
;    extrn '__imp__SHELL32_IconCacheDestroy@??' as SHELL32_IconCacheDestroy:dword
;    extrn '__imp__SHELL32_IconCacheHandleAssociationChanged@??' as SHELL32_IconCacheHandleAssociationChanged:dword
;    extrn '__imp__SHELL32_IconCacheRestore@??' as SHELL32_IconCacheRestore:dword
;    extrn '__imp__SHELL32_IconOverlayManagerInit@??' as SHELL32_IconOverlayManagerInit:dword
;    extrn '__imp__SHELL32_IsGetKeyboardLayoutPresent@??' as SHELL32_IsGetKeyboardLayoutPresent:dword
;    extrn '__imp__SHELL32_IsSystemUpgradeInProgress@??' as SHELL32_IsSystemUpgradeInProgress:dword
;    extrn '__imp__SHELL32_IsValidLinkInfo@??' as SHELL32_IsValidLinkInfo:dword
;    extrn '__imp__SHELL32_LegacyEnumSpecialTasksByType@??' as SHELL32_LegacyEnumSpecialTasksByType:dword
;    extrn '__imp__SHELL32_LegacyEnumTasks@??' as SHELL32_LegacyEnumTasks:dword
;    extrn '__imp__SHELL32_LookupBackIconIndex@??' as SHELL32_LookupBackIconIndex:dword
;    extrn '__imp__SHELL32_LookupFrontIconIndex@??' as SHELL32_LookupFrontIconIndex:dword
;    extrn '__imp__SHELL32_NormalizeRating@??' as SHELL32_NormalizeRating:dword
;    extrn '__imp__SHELL32_NotifyLinkTrackingServiceOfMove@??' as SHELL32_NotifyLinkTrackingServiceOfMove:dword
;    extrn '__imp__SHELL32_PifMgr_CloseProperties@??' as SHELL32_PifMgr_CloseProperties:dword
;    extrn '__imp__SHELL32_PifMgr_GetProperties@??' as SHELL32_PifMgr_GetProperties:dword
;    extrn '__imp__SHELL32_PifMgr_OpenProperties@??' as SHELL32_PifMgr_OpenProperties:dword
;    extrn '__imp__SHELL32_PifMgr_SetProperties@??' as SHELL32_PifMgr_SetProperties:dword
;    extrn '__imp__SHELL32_Printers_CreateBindInfo@??' as SHELL32_Printers_CreateBindInfo:dword
;    extrn '__imp__SHELL32_Printjob_GetPidl@??' as SHELL32_Printjob_GetPidl:dword
;    extrn '__imp__SHELL32_PurgeSystemIcon@??' as SHELL32_PurgeSystemIcon:dword
;    extrn '__imp__SHELL32_RefreshOverlayImages@??' as SHELL32_RefreshOverlayImages:dword
;    extrn '__imp__SHELL32_ResolveLinkInfoW@??' as SHELL32_ResolveLinkInfoW:dword
;    extrn '__imp__SHELL32_SendToMenu_InvokeTargetedCommand@??' as SHELL32_SendToMenu_InvokeTargetedCommand:dword
;    extrn '__imp__SHELL32_SendToMenu_VerifyTargetedCommand@??' as SHELL32_SendToMenu_VerifyTargetedCommand:dword
;    extrn '__imp__SHELL32_SetPlaceholderReparsePointAttribute@??' as SHELL32_SetPlaceholderReparsePointAttribute:dword
;    extrn '__imp__SHELL32_SetPlaceholderReparsePointAttribute2@??' as SHELL32_SetPlaceholderReparsePointAttribute2:dword
;    extrn '__imp__SHELL32_SHAddSparseIcon@??' as SHELL32_SHAddSparseIcon:dword
;    extrn '__imp__SHELL32_SHCreateByValueOperationInterrupt@??' as SHELL32_SHCreateByValueOperationInterrupt:dword
;    extrn '__imp__SHELL32_SHCreateDefaultContextMenu@??' as SHELL32_SHCreateDefaultContextMenu:dword
;    extrn '__imp__SHELL32_SHCreateLocalServer@??' as SHELL32_SHCreateLocalServer:dword
;    extrn '__imp__SHELL32_SHCreateShellFolderView@??' as SHELL32_SHCreateShellFolderView:dword
;    extrn '__imp__SHELL32_SHDuplicateEncryptionInfoFile@??' as SHELL32_SHDuplicateEncryptionInfoFile:dword
;    extrn '__imp__SHELL32_SHEncryptFile@??' as SHELL32_SHEncryptFile:dword
;    extrn '__imp__SHELL32_SHFormatDriveAsync@??' as SHELL32_SHFormatDriveAsync:dword
;    extrn '__imp__SHELL32_SHGetThreadUndoManager@??' as SHELL32_SHGetThreadUndoManager:dword
;    extrn '__imp__SHELL32_SHGetUserNameW@??' as SHELL32_SHGetUserNameW:dword
;    extrn '__imp__SHELL32_SHIsVirtualDevice@??' as SHELL32_SHIsVirtualDevice:dword
;    extrn '__imp__SHELL32_SHLaunchPropSheet@??' as SHELL32_SHLaunchPropSheet:dword
;    extrn '__imp__SHELL32_SHLogILFromFSIL@??' as SHELL32_SHLogILFromFSIL:dword
;    extrn '__imp__SHELL32_SHOpenWithDialog@??' as SHELL32_SHOpenWithDialog:dword
;    extrn '__imp__SHELL32_ShowHideIconOnlyOnDesktop@??' as SHELL32_ShowHideIconOnlyOnDesktop:dword
;    extrn '__imp__SHELL32_SHUICommandFromGUID@??' as SHELL32_SHUICommandFromGUID:dword
;    extrn '__imp__SHELL32_SimpleRatingToFilterCondition@??' as SHELL32_SimpleRatingToFilterCondition:dword
;    extrn '__imp__SHELL32_StampIconForElevation@??' as SHELL32_StampIconForElevation:dword
;    extrn '__imp__SHELL32_SuspendUndo@??' as SHELL32_SuspendUndo:dword
;    extrn '__imp__SHELL32_TryVirtualDiscImageDriveEject@??' as SHELL32_TryVirtualDiscImageDriveEject:dword
;    extrn '__imp__SHELL32_UpdateFilePlaceholderStates@??' as SHELL32_UpdateFilePlaceholderStates:dword
;    extrn '__imp__SHELL32_VerifySaferTrust@??' as SHELL32_VerifySaferTrust:dword
;    extrn '__imp__SHCoCreateInstanceWorker@??' as SHCoCreateInstanceWorker:dword
;    extrn '__imp__SHCreateCategoryEnum@??' as SHCreateCategoryEnum:dword
;    extrn '__imp__SHCreateDirectoryExWWorker@??' as SHCreateDirectoryExWWorker:dword
;    extrn '__imp__SHCreateDrvExtIcon@??' as SHCreateDrvExtIcon:dword
;    extrn '__imp__SHCreateLocalServerRunDll@??' as SHCreateLocalServerRunDll:dword
;    extrn '__imp__SheConvertPathW@??' as SheConvertPathW:dword
;    extrn '__imp__SHGetDesktopFolderWorker@??' as SHGetDesktopFolderWorker:dword
;    extrn '__imp__SHGetFileInfoWWorker@??' as SHGetFileInfoWWorker:dword
;    extrn '__imp__SHGetFolderLocationWorker@??' as SHGetFolderLocationWorker:dword
;    extrn '__imp__SHGetFolderPathAndSubDirWWorker@??' as SHGetFolderPathAndSubDirWWorker:dword
;    extrn '__imp__SHGetFolderPathAWorker@??' as SHGetFolderPathAWorker:dword
;    extrn '__imp__SHGetFolderPathWWorker@??' as SHGetFolderPathWWorker:dword
;    extrn '__imp__SHGetInstanceExplorerWorker@??' as SHGetInstanceExplorerWorker:dword
;    extrn '__imp__SHGetKnownFolderPathWorker@??' as SHGetKnownFolderPathWorker:dword
;    extrn '__imp__SHSetKnownFolderPathWorker@??' as SHSetKnownFolderPathWorker:dword
;    extrn '__imp__SHGetSpecialFolderPathAWorker@??' as SHGetSpecialFolderPathAWorker:dword
;    extrn '__imp__SHGetSpecialFolderPathWWorker@??' as SHGetSpecialFolderPathWWorker:dword
;    extrn '__imp__StrCpyNA@??' as StrCpyNA:dword
;    extrn '__imp__StrCpyNW@??' as StrCpyNW:dword
;    extrn '__imp__StrNCpyA@??' as StrCpyNW:dword
;    extrn '__imp__StrNCpyW@??' as StrNCpyW:dword
;    extrn '__imp__UsersLibrariesFolderUI_CreateInstance@??' as UsersLibrariesFolderUI_CreateInstance:dword
;end if

end if ;SHELL32_INC
