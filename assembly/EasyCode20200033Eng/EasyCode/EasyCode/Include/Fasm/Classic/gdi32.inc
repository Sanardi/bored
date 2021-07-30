; ====================================================;
;                                                     ;
;      gdi32.inc for EC v2 Fasm classic projects      ;
;                   (version 1.0.2)                   ;
;                                                     ;
;            Copyright © Ramon Sala - 2018            ;
;                                                     ;
; ====================================================;

if ~defined GDI32_INC
define GDI32_INC 1

struct PALETTEENTRY
    peRed   db  ?
    peGreen db  ?
    peBlue  db  ?
    peFlags db  ?
ends

import gdi32,\
AbortDoc,'AbortDoc',\
AbortPath,'AbortPath',\
AddFontMemResourceEx,'AddFontMemResourceEx',\
AddFontResourceA,'AddFontResourceA',\
AddFontResourceW,'AddFontResourceW',\
AddFontResourceExA,'AddFontResourceExA',\
AddFontResourceExW,'AddFontResourceExW',\
AnimatePalette,'AnimatePalette',\
AngleArc,'AngleArc',\
Arc,'Arc',\
ArcTo,'ArcTo',\
BeginPath,'BeginPath',\
BitBlt,'BitBlt',\
CancelDC,'CancelDC',\
CheckColorsInGamut,'CheckColorsInGamut',\
ChoosePixelFormat,'ChoosePixelFormat',\
Chord,'Chord',\
CLIPOBJ_bEnum,'CLIPOBJ_bEnum',\
CLIPOBJ_cEnumStart,'CLIPOBJ_cEnumStart',\
CLIPOBJ_ppoGetPath,'CLIPOBJ_ppoGetPath',\
CloseEnhMetaFile,'CloseEnhMetaFile',\
CloseFigure,'CloseFigure',\
CloseMetaFile,'CloseMetaFile',\
ColorCorrectPalette,'ColorCorrectPalette',\
ColorMatchToTarget,'ColorMatchToTarget',\
CombineRgn,'CombineRgn',\
CombineTransform,'CombineTransform',\
ConfigureOPMProtectedOutput,'ConfigureOPMProtectedOutput',\
CopyEnhMetaFileA,'CopyEnhMetaFileA',\
CopyEnhMetaFileW,'CopyEnhMetaFileW',\
CopyMetaFileA,'CopyMetaFileA',\
CopyMetaFileW,'CopyMetaFileW',\
CreateBitmap,'CreateBitmap',\
CreateBitmapIndirect,'CreateBitmapIndirect',\
CreateBrushIndirect,'CreateBrushIndirect',\
CreateColorSpaceA,'CreateColorSpaceA',\
CreateColorSpaceW,'CreateColorSpaceW',\
CreateCompatibleBitmap,'CreateCompatibleBitmap',\
CreateCompatibleDC,'CreateCompatibleDC',\
CreateDCA,'CreateDCA',\
CreateDCW,'CreateDCW',\
CreateDIBitmap,'CreateDIBitmap',\
CreateDIBPatternBrush,'CreateDIBPatternBrush',\
CreateDIBPatternBrushPt,'CreateDIBPatternBrushPt',\
CreateDIBSection,'CreateDIBSection',\
CreateDiscardableBitmap,'CreateDiscardableBitmap',\
CreateEllipticRgn,'CreateEllipticRgn',\
CreateEllipticRgnIndirect,'CreateEllipticRgnIndirect',\
CreateEnhMetaFileA,'CreateEnhMetaFileA',\
CreateEnhMetaFileW,'CreateEnhMetaFileW',\
CreateFontA,'CreateFontA',\
CreateFontIndirectA,'CreateFontIndirectA',\
CreateFontIndirectW,'CreateFontIndirectW',\
CreateFontIndirectExA,'CreateFontIndirectExA',\
CreateFontIndirectExW,'CreateFontIndirectExW',\
CreateFontW,'CreateFontW',\
CreateHalftonePalette,'CreateHalftonePalette',\
CreateHatchBrush,'CreateHatchBrush',\
CreateICA,'CreateICA',\
CreateICW,'CreateICW',\
CreateMetaFileA,'CreateMetaFileA',\
CreateMetaFileW,'CreateMetaFileW',\
CreateOPMProtectedOutputs,'CreateOPMProtectedOutputs',\
CreatePalette,'CreatePalette',\
CreatePatternBrush,'CreatePatternBrush',\
CreatePen,'CreatePen',\
CreatePenIndirect,'CreatePenIndirect',\
CreatePolyPolygonRgn,'CreatePolyPolygonRgn',\
CreatePolygonRgn,'CreatePolygonRgn',\
CreateRectRgn,'CreateRectRgn',\
CreateRectRgnIndirect,'CreateRectRgnIndirect',\
CreateRoundRectRgn,'CreateRoundRectRgn',\
CreateScalableFontResourceA,'CreateScalableFontResourceA',\
CreateScalableFontResourceW,'CreateScalableFontResourceW',\
CreateSolidBrush,'CreateSolidBrush',\
D3DKMTAcquireKeyedMutex,'D3DKMTAcquireKeyedMutex',\
D3DKMTAcquireKeyedMutex2,'D3DKMTAcquireKeyedMutex2',\
D3DKMTCheckExclusiveOwnership,'D3DKMTCheckExclusiveOwnership',\
D3DKMTCheckMonitorPowerState,'D3DKMTCheckMonitorPowerState',\
D3DKMTCheckMultiPlaneOverlaySupport,'D3DKMTCheckMultiPlaneOverlaySupport',\
D3DKMTCheckMultiPlaneOverlaySupport2,'D3DKMTCheckMultiPlaneOverlaySupport2',\
D3DKMTCheckOcclusion,'D3DKMTCheckOcclusion',\
D3DKMTCheckSharedResourceAccess,'D3DKMTCheckSharedResourceAccess',\
D3DKMTCheckVidPnExclusiveOwnership,'D3DKMTCheckVidPnExclusiveOwnership',\
D3DKMTCloseAdapter,'D3DKMTCloseAdapter',\
D3DKMTConfigureSharedResource,'D3DKMTConfigureSharedResource',\
D3DKMTCreateAllocation,'D3DKMTCreateAllocation',\
D3DKMTCreateAllocation2,'D3DKMTCreateAllocation2',\
D3DKMTCreateContext,'D3DKMTCreateContext',\
D3DKMTCreateContextVirtual,'D3DKMTCreateContextVirtual',\
D3DKMTCreateDCFromMemory,'D3DKMTCreateDCFromMemory',\
D3DKMTCreateDevice,'D3DKMTCreateDevice',\
D3DKMTCreateKeyedMutex,'D3DKMTCreateKeyedMutex',\
D3DKMTCreateKeyedMutex2,'D3DKMTCreateKeyedMutex2',\
D3DKMTCreateOutputDupl,'D3DKMTCreateOutputDupl',\
D3DKMTCreateOverlay,'D3DKMTCreateOverlay',\
D3DKMTCreatePagingQueue,'D3DKMTCreatePagingQueue',\
D3DKMTCreateSynchronizationObject,'D3DKMTCreateSynchronizationObject',\
D3DKMTCreateSynchronizationObject2,'D3DKMTCreateSynchronizationObject2',\
D3DKMTDestroyAllocation,'D3DKMTDestroyAllocation',\
D3DKMTDestroyAllocation2,'D3DKMTDestroyAllocation2',\
D3DKMTDestroyContext,'D3DKMTDestroyContext',\
D3DKMTDestroyDCFromMemory,'D3DKMTDestroyDCFromMemory',\
D3DKMTDestroyDevice,'D3DKMTDestroyDevice',\
D3DKMTDestroyKeyedMutex,'D3DKMTDestroyKeyedMutex',\
D3DKMTDestroyOutputDupl,'D3DKMTDestroyOutputDupl',\
D3DKMTDestroyOverlay,'D3DKMTDestroyOverlay',\
D3DKMTDestroyPagingQueue,'D3DKMTDestroyPagingQueue',\
D3DKMTDestroySynchronizationObject,'D3DKMTDestroySynchronizationObject',\
D3DKMTEnumAdapters,'D3DKMTEnumAdapters',\
D3DKMTEscape,'D3DKMTEscape',\
D3DKMTEvict,'D3DKMTEvict',\
D3DKMTFlipOverlay,'D3DKMTFlipOverlay',\
D3DKMTFreeGpuVirtualAddress,'D3DKMTFreeGpuVirtualAddress',\
D3DKMTGetContextInProcessSchedulingPriority,'D3DKMTGetContextInProcessSchedulingPriority',\
D3DKMTGetContextSchedulingPriority,'D3DKMTGetContextSchedulingPriority',\
D3DKMTGetDeviceState,'D3DKMTGetDeviceState',\
D3DKMTGetDisplayModeList,'D3DKMTGetDisplayModeList',\
D3DKMTGetMultisampleMethodList,'D3DKMTGetMultisampleMethodList',\
D3DKMTGetOverlayState,'D3DKMTGetOverlayState',\
D3DKMTGetPresentHistory,'D3DKMTGetPresentHistory',\
D3DKMTGetProcessSchedulingPriorityClass,'D3DKMTGetProcessSchedulingPriorityClass',\
D3DKMTGetRuntimeData,'D3DKMTGetRuntimeData',\
D3DKMTGetScanLine,'D3DKMTGetScanLine',\
D3DKMTGetSharedPrimaryHandle,'D3DKMTGetSharedPrimaryHandle',\
D3DKMTGetSharedResourceAdapterLuid,'D3DKMTGetSharedResourceAdapterLuid',\
D3DKMTInvalidateActiveVidPn,'D3DKMTInvalidateActiveVidPn',\
D3DKMTLock,'D3DKMTLock',\
D3DKMTLock2,'D3DKMTLock2',\
D3DKMTMakeResident,'D3DKMTMakeResident',\
D3DKMTMapGpuVirtualAddress,'D3DKMTMapGpuVirtualAddress',\
D3DKMTOfferAllocations,'D3DKMTOfferAllocations',\
D3DKMTOpenAdapterFromDeviceName,'D3DKMTOpenAdapterFromDeviceName',\
D3DKMTOpenAdapterFromGdiDisplayName,'D3DKMTOpenAdapterFromGdiDisplayName',\
D3DKMTOpenAdapterFromHdc,'D3DKMTOpenAdapterFromHdc',\
D3DKMTOpenAdapterFromLuid,'D3DKMTOpenAdapterFromLuid',\
D3DKMTOpenKeyedMutex,'D3DKMTOpenKeyedMutex',\
D3DKMTOpenKeyedMutex2,'D3DKMTOpenKeyedMutex2',\
D3DKMTOpenNtHandleFromName,'D3DKMTOpenNtHandleFromName',\
D3DKMTOpenResource,'D3DKMTOpenResource',\
D3DKMTOpenResource2,'D3DKMTOpenResource2',\
D3DKMTOpenResourceFromNtHandle,'D3DKMTOpenResourceFromNtHandle',\
D3DKMTOpenSynchronizationObject,'D3DKMTOpenSynchronizationObject',\
D3DKMTOpenSyncObjectFromNtHandle,'D3DKMTOpenSyncObjectFromNtHandle',\
D3DKMTOpenSyncObjectFromNtHandle2,'D3DKMTOpenSyncObjectFromNtHandle2',\
D3DKMTOpenSyncObjectNtHandleFromName,'D3DKMTOpenSyncObjectNtHandleFromName',\
D3DKMTOutputDuplGetFrameInfo,'D3DKMTOutputDuplGetFrameInfo',\
D3DKMTOutputDuplGetMetaData,'D3DKMTOutputDuplGetMetaData',\
D3DKMTOutputDuplGetPointerShapeData,'D3DKMTOutputDuplGetPointerShapeData',\
D3DKMTOutputDuplPresent,'D3DKMTOutputDuplPresent',\
D3DKMTOutputDuplReleaseFrame,'D3DKMTOutputDuplReleaseFrame',\
D3DKMTPinDirectFlipResources,'D3DKMTPinDirectFlipResources',\
D3DKMTPollDisplayChildren,'D3DKMTPollDisplayChildren',\
D3DKMTPresent,'D3DKMTPresent',\
D3DKMTPresentMultiPlaneOverlay,'D3DKMTPresentMultiPlaneOverlay',\
D3DKMTQueryAdapterInfo,'D3DKMTQueryAdapterInfo',\
D3DKMTQueryAllocationResidency,'D3DKMTQueryAllocationResidency',\
D3DKMTQueryRemoteVidPnSourceFromGdiDisplayName,'D3DKMTQueryRemoteVidPnSourceFromGdiDisplayName',\
D3DKMTQueryResourceInfo,'D3DKMTQueryResourceInfo',\
D3DKMTQueryResourceInfoFromNtHandle,'D3DKMTQueryResourceInfoFromNtHandle',\
D3DKMTReclaimAllocations,'D3DKMTReclaimAllocations',\
D3DKMTReclaimAllocations2,'D3DKMTReclaimAllocations2',\
D3DKMTRegisterTrimNotification,'D3DKMTRegisterTrimNotification',\
D3DKMTReleaseKeyedMutex,'D3DKMTReleaseKeyedMutex',\
D3DKMTReleaseKeyedMutex2,'D3DKMTReleaseKeyedMutex2',\
D3DKMTReleaseProcessVidPnSourceOwners,'D3DKMTReleaseProcessVidPnSourceOwners',\
D3DKMTRender,'D3DKMTRender',\
D3DKMTReserveGpuVirtualAddress,'D3DKMTReserveGpuVirtualAddress',\
D3DKMTSetAllocationPriority,'D3DKMTSetAllocationPriority',\
D3DKMTSetContextInProcessSchedulingPriority,'D3DKMTSetContextInProcessSchedulingPriority',\
D3DKMTSetContextSchedulingPriority,'D3DKMTSetContextSchedulingPriority',\
D3DKMTSetDisplayMode,'D3DKMTSetDisplayMode',\
D3DKMTSetDisplayPrivateDriverFormat,'D3DKMTSetDisplayPrivateDriverFormat',\
D3DKMTSetGammaRamp,'D3DKMTSetGammaRamp',\
D3DKMTSetProcessSchedulingPriorityClass,'D3DKMTSetProcessSchedulingPriorityClass',\
D3DKMTSetQueuedLimit,'D3DKMTSetQueuedLimit',\
D3DKMTSetStereoEnabled,'D3DKMTSetStereoEnabled',\
D3DKMTSetVidPnSourceOwner,'D3DKMTSetVidPnSourceOwner',\
D3DKMTSetVidPnSourceOwner1,'D3DKMTSetVidPnSourceOwner1',\
D3DKMTSharedPrimaryLockNotification,'D3DKMTSharedPrimaryLockNotification',\
D3DKMTSharedPrimaryUnLockNotification,'D3DKMTSharedPrimaryUnLockNotification',\
D3DKMTShareObjects,'D3DKMTShareObjects',\
D3DKMTSignalSynchronizationObject,'D3DKMTSignalSynchronizationObject',\
D3DKMTSignalSynchronizationObject2,'D3DKMTSignalSynchronizationObject2',\
D3DKMTSignalSynchronizationObjectFromCpu,'D3DKMTSignalSynchronizationObjectFromCpu',\
D3DKMTSignalSynchronizationObjectFromGpu,'D3DKMTSignalSynchronizationObjectFromGpu',\
D3DKMTSignalSynchronizationObjectFromGpu2,'D3DKMTSignalSynchronizationObjectFromGpu2',\
D3DKMTSubmitCommand,'D3DKMTSubmitCommand',\
D3DKMTUnlock,'D3DKMTUnlock',\
D3DKMTUnlock2,'D3DKMTUnlock2',\
D3DKMTUnpinDirectFlipResources,'D3DKMTUnpinDirectFlipResources',\
D3DKMTUnregisterTrimNotification,'D3DKMTUnregisterTrimNotification',\
D3DKMTUpdateGpuVirtualAddress,'D3DKMTUpdateGpuVirtualAddress',\
D3DKMTUpdateOverlay,'D3DKMTUpdateOverlay',\
D3DKMTWaitForIdle,'D3DKMTWaitForIdle',\
D3DKMTWaitForSynchronizationObject,'D3DKMTWaitForSynchronizationObject',\
D3DKMTWaitForSynchronizationObject2,'D3DKMTWaitForSynchronizationObject2',\
D3DKMTWaitForSynchronizationObjectFromCpu,'D3DKMTWaitForSynchronizationObjectFromCpu',\
D3DKMTWaitForSynchronizationObjectFromGpu,'D3DKMTWaitForSynchronizationObjectFromGpu',\
D3DKMTWaitForVerticalBlankEvent,'D3DKMTWaitForVerticalBlankEvent',\
D3DKMTWaitForVerticalBlankEvent2,'D3DKMTWaitForVerticalBlankEvent2',\
DDCCIGetCapabilitiesString,'DDCCIGetCapabilitiesString',\
DDCCIGetCapabilitiesStringLength,'DDCCIGetCapabilitiesStringLength',\
DDCCIGetTimingReport,'DDCCIGetTimingReport',\
DDCCIGetVCPFeature,'DDCCIGetVCPFeature',\
DDCCISaveCurrentSettings,'DDCCISaveCurrentSettings',\
DDCCISetVCPFeature,'DDCCISetVCPFeature',\
DeleteColorSpace,'DeleteColorSpace',\
DeleteDC,'DeleteDC',\
DeleteEnhMetaFile,'DeleteEnhMetaFile',\
DeleteMetaFile,'DeleteMetaFile',\
DeleteObject,'DeleteObject',\
DestroyOPMProtectedOutput,'DestroyOPMProtectedOutput',\
DestroyPhysicalMonitorInternal,'DestroyPhysicalMonitorInternal',\
DescribePixelFormat,'DescribePixelFormat',\
DeviceCapabilitiesExA,'DeviceCapabilitiesExA',\
DeviceCapabilitiesExW,'DeviceCapabilitiesExW',\
DPtoLP,'DPtoLP',\
DrawEscape,'DrawEscape',\
Ellipse,'Ellipse',\
EnableEUDC,'EnableEUDC',\
EndDoc,'EndDoc',\
EndPage,'EndPage',\
EndPath,'EndPath',\
EngAcquireSemaphore,'EngAcquireSemaphore',\
EngAlphaBlend,'EngAlphaBlend',\
EngAssociateSurface,'EngAssociateSurface',\
EngBitBlt,'EngBitBlt',\
EngCheckAbort,'EngCheckAbort',\
EngComputeGlyphSet,'EngComputeGlyphSet',\
EngCopyBits,'EngCopyBits',\
EngCreateBitmap,'EngCreateBitmap',\
EngCreateClip,'EngCreateClip',\
EngCreateDeviceBitmap,'EngCreateDeviceBitmap',\
EngCreateDeviceSurface,'EngCreateDeviceSurface',\
EngCreatePalette,'EngCreatePalette',\
EngCreateSemaphore,'EngCreateSemaphore',\
EngDeleteClip,'EngDeleteClip',\
EngDeletePalette,'EngDeletePalette',\
EngDeletePath,'EngDeletePath',\
EngDeleteSemaphore,'EngDeleteSemaphore',\
EngDeleteSurface,'EngDeleteSurface',\
EngEraseSurface,'EngEraseSurface',\
EngFillPath,'EngFillPath',\
EngFindResource,'EngFindResource',\
EngFreeModule,'EngFreeModule',\
EngGetCurrentCodePage,'EngGetCurrentCodePage',\
EngGetDriverName,'EngGetDriverName',\
EngGetPrinterDataFileName,'EngGetPrinterDataFileName',\
EngGradientFill,'EngGradientFill',\
EngLineTo,'EngLineTo',\
EngLoadModule,'EngLoadModule',\
EngLockSurface,'EngLockSurface',\
EngMarkBandingSurface,'EngMarkBandingSurface',\
EngMultiByteToUnicodeN,'EngMultiByteToUnicodeN',\
EngMultiByteToWideChar,'EngMultiByteToWideChar',\
EngPaint,'EngPaint',\
EngPlgBlt,'EngPlgBlt',\
EngQueryLocalTime,'EngQueryLocalTime',\
EngReleaseSemaphore,'EngReleaseSemaphore',\
EngStretchBlt,'EngStretchBlt',\
EngStretchBltROP,'EngStretchBltROP',\
EngStrokeAndFillPath,'EngStrokeAndFillPath',\
EngStrokePath,'EngStrokePath',\
EngTextOut,'EngTextOut',\
EngTransparentBlt,'EngTransparentBlt',\
EngUnicodeToMultiByteN,'EngUnicodeToMultiByteN',\
EngUnlockSurface,'EngUnlockSurface',\
EngWideCharToMultiByte,'EngWideCharToMultiByte',\
EnumEnhMetaFile,'EnumEnhMetaFile',\
EnumFontFamiliesA,'EnumFontFamiliesA',\
EnumFontFamiliesExA,'EnumFontFamiliesExA',\
EnumFontFamiliesExW,'EnumFontFamiliesExW',\
EnumFontFamiliesW,'EnumFontFamiliesW',\
EnumFontsA,'EnumFontsA',\
EnumFontsW,'EnumFontsW',\
EnumICMProfilesA,'EnumICMProfilesA',\
EnumICMProfilesW,'EnumICMProfilesW',\
EnumMetaFile,'EnumMetaFile',\
EnumObjects,'EnumObjects',\
EqualRgn,'EqualRgn',\
Escape,'Escape',\
ExcludeClipRect,'ExcludeClipRect',\
ExtCreatePen,'ExtCreatePen',\
ExtCreateRegion,'ExtCreateRegion',\
ExtEscape,'ExtEscape',\
ExtFloodFill,'ExtFloodFill',\
ExtSelectClipRgn,'ExtSelectClipRgn',\
ExtTextOutA,'ExtTextOutA',\
ExtTextOutW,'ExtTextOutW',\
FillPath,'FillPath',\
FillRgn,'FillRgn',\
FixBrushOrgEx,'FixBrushOrgEx',\
FlattenPath,'FlattenPath',\
FloodFill,'FloodFill',\
FONTOBJ_cGetAllGlyphHandles,'FONTOBJ_cGetAllGlyphHandles',\
FONTOBJ_cGetGlyphs,'FONTOBJ_cGetGlyphs',\
FONTOBJ_pQueryGlyphAttrs,'FONTOBJ_pQueryGlyphAttrs',\
FONTOBJ_pfdg,'FONTOBJ_pfdg',\
FONTOBJ_pifi,'FONTOBJ_pifi',\
FONTOBJ_pvTrueTypeFontFile,'FONTOBJ_pvTrueTypeFontFile',\
FONTOBJ_pxoGetXform,'FONTOBJ_pxoGetXform',\
FONTOBJ_vGetInfo,'FONTOBJ_vGetInfo',\
FrameRgn,'FrameRgn',\
GdiAddFontResourceW,'GdiAddFontResourceW',\
GdiAddGlsBounds,'GdiAddGlsBounds',\
GdiAlphaBlend,'GdiAlphaBlend',\
GdiArtificialDecrementDriver,'GdiArtificialDecrementDriver',\
GdiCleanCacheDC,'GdiCleanCacheDC',\
GdiComment,'GdiComment',\
GdiConsoleTextOut,'GdiConsoleTextOut',\
GdiConvertAndCheckDC,'GdiConvertAndCheckDC',\
GdiConvertBitmap,'GdiConvertBitmap',\
GdiConvertBitmapV5,'GdiConvertBitmapV5',\
GdiConvertBrush,'GdiConvertBrush',\
GdiConvertDC,'GdiConvertDC',\
GdiConvertEnhMetaFile,'GdiConvertEnhMetaFile',\
GdiConvertFont,'GdiConvertFont',\
GdiConvertPalette,'GdiConvertPalette',\
GdiConvertRegion,'GdiConvertRegion',\
GdiDeleteLocalDC,'GdiDeleteLocalDC',\
GdiDeleteSpoolFileHandle,'GdiDeleteSpoolFileHandle',\
GdiDescribePixelFormat,'GdiDescribePixelFormat',\
GdiDllInitialize,'GdiDllInitialize',\
GdiEndDocEMF,'GdiEndDocEMF',\
GdiEndPageEMF,'GdiEndPageEMF',\
GdiFixUpHandle,'GdiFixUpHandle',\
GdiFlush,'GdiFlush',\
GdiFullscreenControl,'GdiFullscreenControl',\
GdiGetBatchLimit,'GdiGetBatchLimit',\
GdiGetBitmapBitsSize,'GdiGetBitmapBitsSize',\
GdiGetCharDimensions,'GdiGetCharDimensions',\
GdiGetCodePage,'GdiGetCodePage',\
GdiGetDC,'GdiGetDC',\
GdiGetDevmodeForPage,'GdiGetDevmodeForPage',\
GdiGetLocalBrush,'GdiGetLocalBrush',\
GdiGetLocalDC,'GdiGetLocalDC',\
GdiGetLocalFont,'GdiGetLocalFont',\
GdiGetPageCount,'GdiGetPageCount',\
GdiGetPageHandle,'GdiGetPageHandle',\
GdiGetSpoolFileHandle,'GdiGetSpoolFileHandle',\
GdiGetSpoolMessage,'GdiGetSpoolMessage',\
GdiGradientFill,'GdiGradientFill',\
GdiInitializeLanguagePack,'GdiInitializeLanguagePack',\
GdiInitSpool,'GdiInitSpool',\
GdiIsMetaFileDC,'GdiIsMetaFileDC',\
GdiIsMetaPrintDC,'GdiIsMetaPrintDC',\
GdiIsScreenDC,'GdiIsScreenDC',\
GdiPlayDCScript,'GdiPlayDCScript',\
GdiPlayEMF,'GdiPlayEMF',\
GdiPlayJournal,'GdiPlayJournal',\
GdiIsPlayMetafileDC,'GdiIsPlayMetafileDC',\
GdiPlayPageEMF,'GdiPlayPageEMF',\
GdiPrinterThunk,'GdiPrinterThunk',\
GdiPlayPrivatePageEMF,'GdiPlayPrivatePageEMF',\
GdiPlayScript,'GdiPlayScript',\
gdiPlaySpoolStream,'gdiPlaySpoolStream',\
GdiProcessSetup,'GdiProcessSetup',\
GdiQueryFonts,'GdiQueryFonts',\
GdiQueryTable,'GdiQueryTable',\
GdiRealizationInfo,'GdiRealizationInfo',\
GdiReleaseDC,'GdiReleaseDC',\
GdiReleaseLocalDC,'gdiPlaySpoolStream',\
GdiResetDCEMF,'GdiResetDCEMF',\
GdiSetAttrs,'GdiSetAttrs',\
GdiSetBatchLimit,'GdiSetBatchLimit',\
GdiSetLastError,'GdiSetLastError',\
GdiSetPixelFormat,'GdiSetPixelFormat',\
GdiSetServerAttr,'GdiSetServerAttr',\
GdiStartDocEMF,'GdiStartDocEMF',\
GdiStartPageEMF,'GdiStartPageEMF',\
GdiTransparentBlt,'GdiTransparentBlt',\
GdiValidateHandle,'GdiValidateHandle',\
GetArcDirection,'GetArcDirection',\
GetAspectRatioFilterEx,'GetAspectRatioFilterEx',\
GetBitmapBits,'GetBitmapBits',\
GetBitmapDimensionEx,'GetBitmapDimensionEx',\
GetBkColor,'GetBkColor',\
GetBkMode,'GetBkMode',\
GetBoundsRect,'GetBoundsRect',\
GetBrushAttributes,'GetBrushAttributes',\
GetBrushOrgEx,'GetBrushOrgEx',\
GetCertificateSize,'GetCertificateSize',\
GetCharABCWidthsA,'GetCharABCWidthsA',\
GetCharABCWidthsW,'GetCharABCWidthsW',\
GetCharABCWidthsFloatA,'GetCharABCWidthsFloatA',\
GetCharABCWidthsFloatW,'GetCharABCWidthsFloatW',\
GetCharABCWidthsI,'GetCharABCWidthsI',\
GetCharWidth32A,'GetCharWidth32A',\
GetCharWidth32W,'GetCharWidth32W',\
GetCharWidthA,'GetCharWidthA',\
GetCharWidthInfo,'GetCharWidthInfo',\
GetCharWidthW,'GetCharWidthW',\
GetCharWidthFloatA,'GetCharWidthFloatA',\
GetCharWidthFloatW,'GetCharWidthFloatW',\
GetCharWidthI,'GetCharWidthI',\
GetCharacterPlacementA,'GetCharacterPlacementA',\
GetCharacterPlacementW,'GetCharacterPlacementW',\
GetClipBox,'GetClipBox',\
GetClipRgn,'GetClipRgn',\
GetColorAdjustment,'GetColorAdjustment',\
GetColorSpace,'GetColorSpace',\
GetCOPPCompatibleOPMInformation,'GetCOPPCompatibleOPMInformation',\
GetCurrentObject,'GetCurrentObject',\
GetCurrentPositionEx,'GetCurrentPositionEx',\
GetDCBrushColor,'GetDCBrushColor',\
GetDCOrgEx,'GetDCOrgEx',\
GetDCPenColor,'GetDCPenColor',\
GetDeviceCaps,'GetDeviceCaps',\
GetDeviceGammaRamp,'GetDeviceGammaRamp',\
GetDIBColorTable,'GetDIBColorTable',\
GetDIBits,'GetDIBits',\
GetETM,'GetETM',\
GetEUDCTimeStamp,'GetEUDCTimeStamp',\
GetEUDCTimeStampExW,'GetEUDCTimeStampExW',\
GetEnhMetaFileA,'GetEnhMetaFileA',\
GetEnhMetaFileBits,'GetEnhMetaFileBits',\
GetEnhMetaFileDescriptionA,'GetEnhMetaFileDescriptionW',\
GetEnhMetaFileDescriptionW,'GetEnhMetaFileDescriptionW',\
GetEnhMetaFileHeader,'GetEnhMetaFileHeader',\
GetEnhMetaFilePaletteEntries,'GetEnhMetaFilePaletteEntries',\
GetEnhMetaFilePixelFormat,'GetEnhMetaFilePixelFormat',\
GetEnhMetaFileW,'GetEnhMetaFileW',\
GetFontAssocStatus,'GetFontAssocStatus',\
GetFontData,'GetFontData',\
GetFontLanguageInfo,'GetFontLanguageInfo',\
GetFontResourceInfoW,'GetFontResourceInfoW',\
GetFontUnicodeRanges,'GetFontUnicodeRanges',\
GetGlyphIndicesA,'GetGlyphIndicesA',\
GetGlyphIndicesW,'GetGlyphIndicesW',\
GetGlyphOutlineA,'GetGlyphOutlineW',\
GetGlyphOutlineW,'GetGlyphOutlineW',\
GetGlyphOutlineWow,'GetGlyphOutlineWow',\
GetGraphicsMode,'GetGraphicsMode',\
GetHFONT,'GetHFONT',\
GetICMProfileA,'GetICMProfileA',\
GetICMProfileW,'GetICMProfileW',\
GetKerningPairsA,'GetKerningPairsA',\
GetKerningPairsW,'GetKerningPairsW',\
GetLayout,'GetLayout',\
GetLogColorSpaceA,'GetLogColorSpaceA',\
GetLogColorSpaceW,'GetLogColorSpaceW',\
GetMapMode,'GetMapMode',\
GetMetaFileA,'GetMetaFileA',\
GetMetaFileBitsEx,'GetMetaFileBitsEx',\
GetMetaFileW,'GetMetaFileW',\
GetMetaRgn,'GetMetaRgn',\
GetMiterLimit,'GetMiterLimit',\
GetNearestColor,'GetNearestColor',\
GetNearestPaletteIndex,'GetNearestPaletteIndex',\
GetNumberOfPhysicalMonitors,'GetNumberOfPhysicalMonitors',\
GetObjectA,'GetObjectA',\
GetObjectType,'GetObjectType',\
GetObjectW,'GetObjectW',\
GetOPMInformation,'GetOPMInformation',\
GetOPMRandomNumber,'GetOPMRandomNumber',\
GetOutlineTextMetricsA,'GetOutlineTextMetricsA',\
GetOutlineTextMetricsW,'GetOutlineTextMetricsW',\
GetPaletteEntries,'GetPaletteEntries',\
GetPath,'GetPath',\
GetPhysicalMonitorDescription,'GetPhysicalMonitorDescription',\
GetPhysicalMonitors,'GetPhysicalMonitors',\
GetPixel,'GetPixel',\
GetPixelFormat,'GetPixelFormat',\
GetPolyFillMode,'GetPolyFillMode',\
GetROP2,'GetROP2',\
GetRandomRgn,'GetRandomRgn',\
GetRasterizerCaps,'GetRasterizerCaps',\
GetRegionData,'GetRegionData',\
GetRgnBox,'GetRgnBox',\
GetStockObject,'GetStockObject',\
GetStretchBltMode,'GetStretchBltMode',\
GetSuggestedOPMProtectedOutputArraySize,'GetSuggestedOPMProtectedOutputArraySize',\
GetSystemPaletteEntries,'GetSystemPaletteEntries',\
GetSystemPaletteUse,'GetSystemPaletteUse',\
GetTextAlign,'GetTextAlign',\
GetTextCharacterExtra,'GetTextCharacterExtra',\
GetTextCharset,'GetTextCharset',\
GetTextCharsetInfo,'GetTextCharsetInfo',\
GetTextColor,'GetTextColor',\
GetTextExtentExPointA,'GetTextExtentExPointA',\
GetTextExtentExPointW,'GetTextExtentExPointW',\
GetTextExtentExPointI,'GetTextExtentExPointI',\
GetTextExtentExPointWPri,'GetTextExtentExPointWPri',\
GetTextExtentPoint32A,'GetTextExtentPoint32A',\
GetTextExtentPoint32W,'GetTextExtentPoint32W',\
GetTextExtentPointA,'GetTextExtentPointA',\
GetTextExtentPointW,'GetTextExtentPointW',\
GetTextExtentPointI,'GetTextExtentPointI',\
GetTextFaceA,'GetTextFaceA',\
GetTextFaceW,'GetTextFaceW',\
GetTextMetricsA,'GetTextMetricsA',\
GetTextMetricsW,'GetTextMetricsW',\
GetViewportExtEx,'GetViewportExtEx',\
GetViewportOrgEx,'GetViewportOrgEx',\
GetWindowExtEx,'GetWindowExtEx',\
GetWindowOrgEx,'GetWindowOrgEx',\
GetWinMetaFileBits,'GetWinMetaFileBits',\
GetWorldTransform,'GetWorldTransform',\
BRUSHOBJ_hGetColorTransform,'BRUSHOBJ_hGetColorTransform',\
BRUSHOBJ_pvAllocRbrush,'BRUSHOBJ_pvAllocRbrush',\
BRUSHOBJ_pvGetRbrush,'BRUSHOBJ_pvGetRbrush',\
BRUSHOBJ_ulGetBrushColor,'BRUSHOBJ_ulGetBrushColor',\
HT_Get8BPPFormatPalette,'HT_Get8BPPFormatPalette',\
HT_Get8BPPMaskPalette,'HT_Get8BPPMaskPalette',\
IntersectClipRect,'IntersectClipRect',\
InvertRgn,'InvertRgn',\
IsValidEnhMetaRecord,'IsValidEnhMetaRecord',\
IsValidEnhMetaRecordOffExt,'IsValidEnhMetaRecordOffExt',\
LineDD,'LineDDW',\
LineTo,'LineTo',\
LPtoDP,'LPtoDP',\
MaskBlt,'MaskBlt',\
MirrorRgn,'MirrorRgn',\
ModifyWorldTransform,'ModifyWorldTransform',\
MoveToEx,'MoveToEx',\
OffsetClipRgn,'OffsetClipRgn',\
OffsetRgn,'OffsetRgn',\
OffsetViewportOrgEx,'OffsetViewportOrgEx',\
OffsetWindowOrgEx,'OffsetWindowOrgEx',\
PaintRgn,'PaintRgn',\
PatBlt,'PatBlt',\
PATHOBJ_bEnum,'PATHOBJ_bEnum',\
PATHOBJ_bEnumClipLines,'PATHOBJ_bEnumClipLines',\
PATHOBJ_vEnumStart,'PATHOBJ_vEnumStart',\
PATHOBJ_vEnumStartClipLines,'PATHOBJ_vEnumStartClipLines',\
PATHOBJ_vGetBounds,'PATHOBJ_vGetBounds',\
PathToRegion,'PathToRegion',\
Pie,'Pie',\
PlayEnhMetaFile,'PlayEnhMetaFile',\
PlayEnhMetaFileRecord,'PlayEnhMetaFileRecord',\
PlayMetaFile,'PlayMetaFile',\
PlayMetaFileRecord,'PlayMetaFileRecord',\
PlgBlt,'PlgBlt',\
PolyBezier,'PolyBezier',\
PolyBezierTo,'PolyBezierTo',\
PolyDraw,'PolyDraw',\
Polygon,'Polygon',\
PolyPatBlt,'PolyPatBlt',\
Polyline,'Polyline',\
PolylineTo,'PolylineTo',\
PolyPolygon,'PolyPolygon',\
PolyPolyline,'PolyPolyline',\
PolyTextOutA,'PolyTextOutA',\
PolyTextOutW,'PolyTextOutW',\
PtInRegion,'PtInRegion',\
PtVisible,'PtVisible',\
QueryFontAssocStatus,'QueryFontAssocStatus',\
RealizePalette,'RealizePalette',\
Rectangle,'Rectangle',\
RectInRegion,'RectInRegion',\
RectVisible,'RectVisible',\
RemoveFontMemResourceEx,'RemoveFontMemResourceEx',\
RemoveFontResourceA,'RemoveFontResourceA',\
RemoveFontResourceW,'RemoveFontResourceW',\
RemoveFontResourceExA,'RemoveFontResourceExA',\
RemoveFontResourceExW,'RemoveFontResourceExW',\
ResetDCA,'ResetDCA',\
ResetDCW,'ResetDCW',\
ResizePalette,'ResizePalette',\
RestoreDC,'RestoreDC',\
RoundRect,'RoundRect',\
SaveDC,'SaveDC',\
ScaleViewportExtEx,'ScaleViewportExtEx',\
ScaleWindowExtEx,'ScaleWindowExtEx',\
ScriptApplyDigitSubstitution,'ScriptApplyDigitSubstitution',\
ScriptApplyLogicalWidth,'ScriptApplyLogicalWidth',\
ScriptBreak,'ScriptBreak',\
ScriptCPtoX,'ScriptCPtoX',\
ScriptCacheGetHeight,'ScriptCacheGetHeight',\
ScriptFreeCache,'ScriptFreeCache',\
ScriptGetCMap,'ScriptGetCMap',\
ScriptGetFontAlternateGlyphs,'ScriptGetFontAlternateGlyphs',\
ScriptGetFontFeatureTags,'ScriptGetFontFeatureTags',\
ScriptGetFontLanguageTags,'ScriptGetFontLanguageTags',\
ScriptGetFontProperties,'ScriptGetFontProperties',\
ScriptGetFontScriptTags,'ScriptGetFontScriptTags',\
ScriptGetGlyphABCWidth,'ScriptGetGlyphABCWidth',\
ScriptGetLogicalWidths,'ScriptGetLogicalWidths',\
ScriptGetProperties,'ScriptGetProperties',\
ScriptIsComplex,'ScriptIsComplex',\
ScriptItemize,'ScriptItemize',\
ScriptItemizeOpenType,'ScriptItemizeOpenType',\
ScriptJustify,'ScriptJustify',\
ScriptLayout,'ScriptLayout',\
ScriptPlace,'ScriptPlace',\
ScriptPlaceOpenType,'ScriptPlaceOpenType',\
ScriptPositionSingleGlyph,'ScriptPositionSingleGlyph',\
ScriptRecordDigitSubstitution,'ScriptRecordDigitSubstitution',\
ScriptShape,'ScriptShape',\
ScriptShapeOpenType,'ScriptShapeOpenType',\
ScriptStringAnalyse,'ScriptStringAnalyse',\
ScriptStringCPtoX,'ScriptStringCPtoX',\
ScriptStringFree,'ScriptStringFree',\
ScriptStringGetLogicalWidths,'ScriptStringGetLogicalWidths',\
ScriptStringGetOrder,'ScriptStringGetOrder',\
ScriptStringOut,'ScriptStringOut',\
ScriptStringValidate,'ScriptStringValidate',\
ScriptStringXtoCP,'ScriptStringXtoCP',\
ScriptString_pLogAttr,'ScriptString_pLogAttr',\
ScriptString_pSize,'ScriptString_pSize',\
ScriptString_pcOutChars,'ScriptString_pcOutChars',\
ScriptSubstituteSingleGlyph,'ScriptSubstituteSingleGlyph',\
ScriptTextOut,'ScriptTextOut',\
ScriptXtoCP,'ScriptXtoCP',\
SelectBrushLocal,'SelectBrushLocal',\
SelectClipPath,'SelectClipPath',\
SelectClipRgn,'SelectClipRgn',\
SelectFontLocal,'SelectFontLocal',\
SelectObject,'SelectObject',\
SelectPalette,'SelectPalette',\
SetAbortProc,'SetAbortProc',\
SetArcDirection,'SetArcDirection',\
SetBitmapBits,'SetBitmapBits',\
SetBitmapDimensionEx,'SetBitmapDimensionEx',\
SetBkColor,'SetBkColor',\
SetBkMode,'SetBkMode',\
SetBoundsRect,'SetBoundsRect',\
SetBitmapAttributes,'SetBitmapAttributes',\
SetBrushOrgEx,'SetBrushOrgEx',\
SetColorAdjustment,'SetColorAdjustment',\
SetColorSpace,'SetColorSpace',\
SetDCBrushColor,'SetDCBrushColor',\
SetDCPenColor,'SetDCPenColor',\
SetDIBColorTable,'SetDIBColorTable',\
SetDIBits,'SetDIBits',\
SetDIBitsToDevice,'SetDIBitsToDevice',\
SetDeviceGammaRamp,'SetDeviceGammaRamp',\
SetEnhMetaFileBits,'SetEnhMetaFileBits',\
SetFontEnumeration,'SetFontEnumeration',\
SetGraphicsMode,'SetGraphicsMode',\
SetICMMode,'SetICMMode',\
SetICMProfileA,'SetICMProfileW',\
SetICMProfileW,'SetICMProfileW',\
SetLayout,'SetLayout',\
SetLayoutWidth,'SetLayoutWidth',\
SetMagicColors,'SetMagicColors',\
SetMapMode,'SetMapMode',\
SetMapperFlags,'SetMapperFlags',\
SetMetaFileBitsEx,'SetMetaFileBitsEx',\
SetMetaRgn,'SetMetaRgn',\
SetMiterLimit,'SetMiterLimit',\
SetOPMSigningKeyAndSequenceNumbers,'SetOPMSigningKeyAndSequenceNumbers',\
SetPaletteEntries,'SetPaletteEntries',\
SetPixel,'SetPixel',\
SetPixelFormat,'SetPixelFormat',\
SetPixelV,'SetPixelV',\
SetPolyFillMode,'SetPolyFillMode',\
SetRectRgn,'SetRectRgn',\
SetROP2,'SetROP2',\
SetStretchBltMode,'SetStretchBltMode',\
SetSystemPaletteUse,'SetSystemPaletteUse',\
SetTextAlign,'SetTextAlign',\
SetTextCharacterExtra,'SetTextCharacterExtra',\
SetTextColor,'SetTextColor',\
SetTextJustification,'SetTextJustification',\
SetViewportExtEx,'SetViewportExtEx',\
SetViewportOrgEx,'SetViewportOrgEx',\
SetWinMetaFileBits,'SetWinMetaFileBits',\
SetWindowExtEx,'SetWindowExtEx',\
SetWindowOrgEx,'SetWindowOrgEx',\
SetWorldTransform,'SetWorldTransform',\
StartDocA,'StartDocA',\
StartDocW,'StartDocW',\
StartFormPage,'StartFormPage',\
StartPage,'StartPage',\
StretchBlt,'StretchBlt',\
StretchDIBits,'StretchDIBits',\
STROBJ_bEnum,'STROBJ_bEnum',\
STROBJ_bEnumPositionsOnly,'STROBJ_bEnumPositionsOnly',\
STROBJ_bGetAdvanceWidths,'STROBJ_bGetAdvanceWidths',\
STROBJ_dwGetCodePage,'STROBJ_dwGetCodePage',\
STROBJ_vEnumStart,'STROBJ_vEnumStart',\
StrokeAndFillPath,'StrokeAndFillPath',\
StrokePath,'StrokePath',\
SwapBuffers,'SwapBuffers',\
TextOutA,'TextOutA',\
TextOutW,'TextOutW',\
TranslateCharsetInfo,'TranslateCharsetInfo',\
UnrealizeObject,'UnrealizeObject',\
UpdateColors,'UpdateColors',\
UpdateICMRegKeyA,'UpdateICMRegKeyA',\
UpdateICMRegKeyW,'UpdateICMRegKeyW',\
WidenPath,'WidenPath',\
XFORMOBJ_bApplyXform,'XFORMOBJ_bApplyXform',\
XFORMOBJ_iGetXform,'XFORMOBJ_bApplyXform',\
XLATEOBJ_cGetPalette,'XLATEOBJ_cGetPalette',\
XLATEOBJ_hGetColorTransform,'XLATEOBJ_hGetColorTransform',\
XLATEOBJ_iXlate,'XLATEOBJ_iXlate',\
XLATEOBJ_piVector,'XLATEOBJ_piVector'

api AddFontResource,\
    AddFontResourceEx,\
    CopyEnhMetaFile,\
    CopyMetaFile,\
    CreateColorSpace,\
    CreateDC,\
    CreateEnhMetaFile,\
    CreateFont,\
    CreateFontIndirect,\
    CreateFontIndirectEx,\
    CreateIC,\
    CreateMetaFile,\
    CreateScalableFontResource,\
    DeviceCapabilitiesEx,\
    EnumFontFamilies,\
    EnumFontFamiliesEx,\
    EnumFonts,\
    EnumICMProfiles,\
    ExtTextOut,\
    GetCharABCWidths,\
    GetCharABCWidthsFloat,\
    GetCharacterPlacement,\
    GetCharWidth,\
    GetCharWidth32,\
    GetCharWidthFloat,\
    GetEnhMetaFile,\
    GetEnhMetaFileDescription,\
    GetGlyphIndices,\
    GetGlyphOutline,\
    GetICMProfile,\
    GetKerningPairs,\
    GetLogColorSpace,\
    GetMetaFile,\
    GetObject,\
    GetOutlineTextMetrics,\
    GetTextExtentExPoint,\
    GetTextExtentPoint,\
    GetTextExtentPoint32,\
    GetTextFace,\
    GetTextMetrics,\
    PolyTextOut,\
    RemoveFontResource,\
    RemoveFontResourceEx,\
    ResetDC,\
    SetICMProfile,\
    StartDoc,\
    TextOut,\
    UpdateICMRegKey

;======================= Undocumented functions (unknown arguments) =======================;
;if defined APP_WIN64
;    AddFontResourceTracking,'AddFontResourceTracking',\
;    AnyLinkedFonts,'AnyLinkedFonts',\
;    BeginGdiRendering,'AnyLinkedFonts',\
;    ClearBitmapAttributes,'ClearBitmapAttributes',\
;    ClearBrushAttributes,'ClearBrushAttributes',\
;    CreateBitmapFromDxSurface,'CreateBitmapFromDxSurface',\
;    CreateBitmapFromDxSurface2,'CreateBitmapFromDxSurface2',\
;    CreateSessionMappedDIBSection,'CreateSessionMappedDIBSection',\
;    D3DKMTAbandonSwapChain,'D3DKMTAbandonSwapChain',\
;    D3DKMTAcquireSwapChain,'D3DKMTAcquireSwapChain',\
;    D3DKMTAdjustFullscreenGamma,'D3DKMTAdjustFullscreenGamma',\
;    D3DKMTCacheHybridQueryValue,'D3DKMTCacheHybridQueryValue',\
;    D3DKMTChangeVideoMemoryReservation,'D3DKMTChangeVideoMemoryReservation',\
;    D3DKMTCreateSwapChain,'D3DKMTCreateSwapChain',\
;    D3DKMTEnumAdapters2,'D3DKMTEnumAdapters2',\
;    D3DKMTFlushHeapTransitions,'D3DKMTFlushHeapTransitions',\
;    D3DKMTGetCachedHybridQueryValue,'D3DKMTGetCachedHybridQueryValue',\
;    D3DKMTGetDWMVerticalBlankEvent,'D3DKMTGetDWMVerticalBlankEvent',\
;    D3DKMTGetPresentQueueEvent,'D3DKMTGetPresentQueueEvent',\
;    D3DKMTGetResourcePresentPrivateDriverData,'D3DKMTGetResourcePresentPrivateDriverData',\
;    D3DKMTGetSetSwapChainMetadata,'D3DKMTGetSetSwapChainMetadata',\
;    D3DKMTInvalidateCache,'D3DKMTInvalidateCache',\
;    D3DKMTMarkDeviceAsError,'D3DKMTMarkDeviceAsError',\
;    D3DKMTNetDispGetNextChunkInfo,'D3DKMTNetDispGetNextChunkInfo',\
;    D3DKMTNetDispQueryMiracastDisplayDeviceStatus,'D3DKMTNetDispQueryMiracastDisplayDeviceStatus',\
;    D3DKMTNetDispQueryMiracastDisplayDeviceSupport,'D3DKMTNetDispQueryMiracastDisplayDeviceSupport',\
;    D3DKMTNetDispStartMiracastDisplayDevice,'D3DKMTNetDispStartMiracastDisplayDevice',\
;    D3DKMTNetDispStartMiracastDisplayDevice2,'D3DKMTNetDispStartMiracastDisplayDevice2',\
;    D3DKMTNetDispStartMiracastDisplayDeviceEx,'D3DKMTNetDispStartMiracastDisplayDeviceEx',\
;    D3DKMTNetDispStopMiracastDisplayDevice,'D3DKMTNetDispStopMiracastDisplayDevice',\
;    D3DKMTNetDispStopSessions,'D3DKMTNetDispStopSessions',\
;    D3DKMTOpenSwapChain,'D3DKMTOpenSwapChain',\
;    D3DKMTPresentMultiPlaneOverlay2,'D3DKMTPresentMultiPlaneOverlay2',\
;    D3DKMTQueryClockCalibration,'D3DKMTQueryClockCalibration',\
;    D3DKMTQueryStatistics,'D3DKMTQueryStatistics',\
;    D3DKMTQueryVideoMemoryInfo,'D3DKMTQueryVideoMemoryInfo',\
;    D3DKMTQueryVidPnExclusiveOwnership,'D3DKMTQueryVidPnExclusiveOwnership',\
;    D3DKMTReleaseSwapChain,'D3DKMTReleaseSwapChain',\
;    D3DKMTSetDodIndirectSwapchain,'D3DKMTSetDodIndirectSwapchain',\
;    D3DKMTSetHwProtectionTeardownRecovery,'D3DKMTSetHwProtectionTeardownRecovery',\
;    D3DKMTSetStablePowerState,'D3DKMTSetStablePowerState',\
;    D3DKMTSetSyncRefreshCountWaitTarget,'D3DKMTSetSyncRefreshCountWaitTarget',\
;    D3DKMTSetVidPnSourceHwProtection,'D3DKMTSetVidPnSourceHwProtection',\
;    DdCreateFullscreenSprite,'DdCreateFullscreenSprite',\
;    DdDestroyFullscreenSprite,'DdDestroyFullscreenSprite',\
;    DdEntry0,'DdEntry0',\
;    DdEntry1,'DdEntry1',\
;    DdEntry10,'DdEntry10',\
;    DdEntry11,'DdEntry11',\
;    DdEntry12,'DdEntry12',\
;    DdEntry13,'DdEntry13',\
;    DdEntry14,'DdEntry14',\
;    DdEntry15,'DdEntry15',\
;    DdEntry16,'DdEntry16',\
;    DdEntry17,'DdEntry17',\
;    DdEntry18,'DdEntry18',\
;    DdEntry19,'DdEntry19',\
;    DdEntry2,'DdEntry2',\
;    DdEntry20,'DdEntry20',\
;    DdEntry21,'DdEntry21',\
;    DdEntry22,'DdEntry22',\
;    DdEntry23,'DdEntry23',\
;    DdEntry24,'DdEntry24',\
;    DdEntry25,'DdEntry25',\
;    DdEntry26,'DdEntry26',\
;    DdEntry27,'DdEntry27',\
;    DdEntry28,'DdEntry28',\
;    DdEntry29,'DdEntry29',\
;    DdEntry3,'DdEntry3',\
;    DdEntry30,'DdEntry30',\
;    DdEntry31,'DdEntry31',\
;    DdEntry32,'DdEntry32',\
;    DdEntry33,'DdEntry33',\
;    DdEntry34,'DdEntry34',\
;    DdEntry35,'DdEntry35',\
;    DdEntry36,'DdEntry36',\
;    DdEntry37,'DdEntry37',\
;    DdEntry38,'DdEntry38',\
;    DdEntry39,'DdEntry39',\
;    DdEntry4,'DdEntry4',\
;    DdEntry40,'DdEntry40',\
;    DdEntry41,'DdEntry41',\
;    DdEntry42,'DdEntry42',\
;    DdEntry43,'DdEntry43',\
;    DdEntry44,'DdEntry44',\
;    DdEntry45,'DdEntry45',\
;    DdEntry46,'DdEntry46',\
;    DdEntry47,'DdEntry47',\
;    DdEntry48,'DdEntry48',\
;    DdEntry49,'DdEntry49',\
;    DdEntry5,'DdEntry5',\
;    DdEntry50,'DdEntry50',\
;    DdEntry51,'DdEntry51',\
;    DdEntry52,'DdEntry52',\
;    DdEntry53,'DdEntry53',\
;    DdEntry54,'DdEntry54',\
;    DdEntry55,'DdEntry55',\
;    DdEntry56,'DdEntry56',\
;    DdEntry6,'DdEntry6',\
;    DdEntry7,'DdEntry7',\
;    DdEntry8,'DdEntry8',\
;    DdEntry9,'DdEntry9',\
;    DdNotifyFullscreenSpriteUpdate,'DdNotifyFullscreenSpriteUpdate',\
;    DdQueryVisRgnUniqueness,'DdQueryVisRgnUniqueness',\
;    DwmGetDirtyRgn,'DwmGetDirtyRgn',\
;    DwmGetSurfaceData,'DwmGetSurfaceData',\
;    EndFormPage,'EndFormPage',\
;    EndGdiRendering,'EndGdiRendering',\
;    EngQueryEMFInfo,'EngQueryEMFInfo',\
;    EudcLoadLinkW,'EudcLoadLinkW',\
;    EudcUnloadLinkW,'EudcUnloadLinkW',\
;    FontIsLinked,'FontIsLinked',\
;    ftsWordBreak,'ftsWordBreak',\
;    GdiAddGlsRecord,'GdiAddGlsRecord',\
;    GdiClearStockObjectCache,'GdiClearStockObjectCache',\
;    GdiConvertMetaFilePict,'GdiConvertMetaFilePict',\
;    GdiConvertToDevmodeW,'GdiConvertToDevmodeW',\
;    GdiCreateLocalEnhMetaFile,'GdiCreateLocalEnhMetaFile',\
;    GdiCreateLocalMetaFilePict,'GdiCreateLocalMetaFilePict',\
;    GdiDrawStream,'GdiDrawStream',\
;    GdiIsUMPDSandboxingEnabled,'GdiIsUMPDSandboxingEnabled',\
;    GdiEntry1,'GdiEntry1',\
;    GdiEntry10,'GdiEntry10',\
;    GdiEntry11,'GdiEntry11',\
;    GdiEntry12,'GdiEntry12',\
;    GdiEntry13,'GdiEntry13',\
;    GdiEntry14,'GdiEntry14',\
;    GdiEntry15,'GdiEntry15',\
;    GdiEntry16,'GdiEntry16',\
;    GdiEntry2,'GdiEntry2',\
;    GdiEntry3,'GdiEntry3',\
;    GdiEntry4,'GdiEntry4',\
;    GdiEntry5,'GdiEntry5',\
;    GdiEntry6,'GdiEntry6',\
;    GdiEntry7,'GdiEntry7',\
;    GdiEntry8,'GdiEntry8',\
;    GdiEntry9,'GdiEntry9',\
;    GdiLoadType1Fonts,'GdiLoadType1Fonts',\
;    GdiPlayPrivatePageEMF,'GdiPlayPrivatePageEMF',\
;    GdiSupportsFontChangeEvent,'GdiSupportsFontChangeEvent',\
;    GdiSwapBuffers,'GdiSwapBuffers',\
;    GetBitmapAttributes,'GetBitmapAttributes',\
;    GetCertificate,'GetCertificate',\
;    GetCertificateByHandle,'GetCertificateByHandle',\
;    GetCertificateSizeByHandle,'GetCertificateSizeByHandle',\
;    GetCurrentDpiInfo,'GetCurrentDpiInfo',\
;    GetFontFileData,'GetFontFileData',\
;    GetFontFileInfo,'GetFontFileInfo',\
;    GetFontRealizationInfo,'GetFontRealizationInfo',\
;    GetRelAbs,'GetRelAbs',\
;    GetStringBitmapA,'GetStringBitmapA',\
;    GetStringBitmapW,'GetStringBitmapW',\
;    GetTransform,'GetTransform',\
;    LpkDrawTextEx,'LpkDrawTextEx',\
;    LpkEditControl,'LpkEditControl',\
;    LpkExtTextOut,'LpkExtTextOut',\
;    LpkGetCharacterPlacement,'LpkGetCharacterPlacement',\
;    LpkGetTextExtentExPoint,'LpkGetTextExtentExPoint',\
;    LpkInitialize,'LpkInitialize',\
;    LpkPSMTextOut,'LpkPSMTextOut',\
;    LpkPresent,'LpkPresent',\
;    LpkTabbedTextOut,'LpkTabbedTextOut',\
;    LpkUseGDIWidthCache,'LpkUseGDIWidthCache',\
;    NamedEscape,'NamedEscape',\
;    RemoveFontResourceTracking,'RemoveFontResourceTracking',\
;    SetBrushAttributes,'SetBrushAttributes',\
;    SetRelAbs,'SetRelAbs',\
;    SetVirtualResolution,'SetVirtualResolution',\
;    UnloadNetworkFonts,'UnloadNetworkFonts',\
;    UspAllocCache,'UspAllocCache',\
;    UspAllocTemp,'UspAllocTemp',\
;    UspFreeMem,'UspFreeMem',\
;    bInitSystemAndFontsDirectoriesW,'bInitSystemAndFontsDirectoriesW',\
;    bMakePathNameW,'bMakePathNameW',\
;    cGetTTFFromFOT,'cGetTTFFromFOT',\
;    pfnRealizePalette,'pfnRealizePalette',\
;    pfnSelectPalette,'pfnSelectPalette'
;else
;    AddFontResourceTracking,'AddFontResourceTracking',\
;    AnyLinkedFonts,'AnyLinkedFonts',\
;    BeginGdiRendering,'AnyLinkedFonts',\
;    ClearBitmapAttributes,'ClearBitmapAttributes',\
;    ClearBrushAttributes,'ClearBrushAttributes',\
;    CreateBitmapFromDxSurface,'CreateBitmapFromDxSurface',\
;    CreateBitmapFromDxSurface2,'CreateBitmapFromDxSurface2',\
;    CreateSessionMappedDIBSection,'CreateSessionMappedDIBSection',\
;    D3DKMTAbandonSwapChain,'D3DKMTAbandonSwapChain',\
;    D3DKMTAcquireSwapChain,'D3DKMTAcquireSwapChain',\
;    D3DKMTAdjustFullscreenGamma,'D3DKMTAdjustFullscreenGamma',\
;    D3DKMTCacheHybridQueryValue,'D3DKMTCacheHybridQueryValue',\
;    D3DKMTChangeVideoMemoryReservation,'D3DKMTChangeVideoMemoryReservation',\
;    D3DKMTCreateSwapChain,'D3DKMTCreateSwapChain',\
;    D3DKMTEnumAdapters2,'D3DKMTEnumAdapters2',\
;    D3DKMTFlushHeapTransitions,'D3DKMTFlushHeapTransitions',\
;    D3DKMTGetCachedHybridQueryValue,'D3DKMTGetCachedHybridQueryValue',\
;    D3DKMTGetDWMVerticalBlankEvent,'D3DKMTGetDWMVerticalBlankEvent',\
;    D3DKMTGetPresentQueueEvent,'D3DKMTGetPresentQueueEvent',\
;    D3DKMTGetResourcePresentPrivateDriverData,'D3DKMTGetResourcePresentPrivateDriverData',\
;    D3DKMTGetSetSwapChainMetadata,'D3DKMTGetSetSwapChainMetadata',\
;    D3DKMTInvalidateCache,'D3DKMTInvalidateCache',\
;    D3DKMTMarkDeviceAsError,'D3DKMTMarkDeviceAsError',\
;    D3DKMTNetDispGetNextChunkInfo,'D3DKMTNetDispGetNextChunkInfo',\
;    D3DKMTNetDispQueryMiracastDisplayDeviceStatus,'D3DKMTNetDispQueryMiracastDisplayDeviceStatus',\
;    D3DKMTNetDispQueryMiracastDisplayDeviceSupport,'D3DKMTNetDispQueryMiracastDisplayDeviceSupport',\
;    D3DKMTNetDispStartMiracastDisplayDevice,'D3DKMTNetDispStartMiracastDisplayDevice',\
;    D3DKMTNetDispStartMiracastDisplayDevice2,'D3DKMTNetDispStartMiracastDisplayDevice2',\
;    D3DKMTNetDispStartMiracastDisplayDeviceEx,'D3DKMTNetDispStartMiracastDisplayDeviceEx',\
;    D3DKMTNetDispStopMiracastDisplayDevice,'D3DKMTNetDispStopMiracastDisplayDevice',\
;    D3DKMTNetDispStopSessions,'D3DKMTNetDispStopSessions',\
;    D3DKMTOpenSwapChain,'D3DKMTOpenSwapChain',\
;    D3DKMTPresentMultiPlaneOverlay2,'D3DKMTPresentMultiPlaneOverlay2',\
;    D3DKMTQueryClockCalibration,'D3DKMTQueryClockCalibration',\
;    D3DKMTQueryStatistics,'D3DKMTQueryStatistics',\
;    D3DKMTQueryVideoMemoryInfo,'D3DKMTQueryVideoMemoryInfo',\
;    D3DKMTQueryVidPnExclusiveOwnership,'D3DKMTQueryVidPnExclusiveOwnership',\
;    D3DKMTReleaseSwapChain,'D3DKMTReleaseSwapChain',\
;    D3DKMTSetDodIndirectSwapchain,'D3DKMTSetDodIndirectSwapchain',\
;    D3DKMTSetHwProtectionTeardownRecovery,'D3DKMTSetHwProtectionTeardownRecovery',\
;    D3DKMTSetStablePowerState,'D3DKMTSetStablePowerState',\
;    D3DKMTSetSyncRefreshCountWaitTarget,'D3DKMTSetSyncRefreshCountWaitTarget',\
;    D3DKMTSetVidPnSourceHwProtection,'D3DKMTSetVidPnSourceHwProtection',\
;    DdCreateFullscreenSprite,'DdCreateFullscreenSprite',\
;    DdDestroyFullscreenSprite,'DdDestroyFullscreenSprite',\
;    DdEntry0,'DdEntry0',\
;    DdEntry1,'DdEntry1',\
;    DdEntry10,'DdEntry10',\
;    DdEntry11,'DdEntry11',\
;    DdEntry12,'DdEntry12',\
;    DdEntry13,'DdEntry13',\
;    DdEntry14,'DdEntry14',\
;    DdEntry15,'DdEntry15',\
;    DdEntry16,'DdEntry16',\
;    DdEntry17,'DdEntry17',\
;    DdEntry18,'DdEntry18',\
;    DdEntry19,'DdEntry19',\
;    DdEntry2,'DdEntry2',\
;    DdEntry20,'DdEntry20',\
;    DdEntry21,'DdEntry21',\
;    DdEntry22,'DdEntry22',\
;    DdEntry23,'DdEntry23',\
;    DdEntry24,'DdEntry24',\
;    DdEntry25,'DdEntry25',\
;    DdEntry26,'DdEntry26',\
;    DdEntry27,'DdEntry27',\
;    DdEntry28,'DdEntry28',\
;    DdEntry29,'DdEntry29',\
;    DdEntry3,'DdEntry3',\
;    DdEntry30,'DdEntry30',\
;    DdEntry31,'DdEntry31',\
;    DdEntry32,'DdEntry32',\
;    DdEntry33,'DdEntry33',\
;    DdEntry34,'DdEntry34',\
;    DdEntry35,'DdEntry35',\
;    DdEntry36,'DdEntry36',\
;    DdEntry37,'DdEntry37',\
;    DdEntry38,'DdEntry38',\
;    DdEntry39,'DdEntry39',\
;    DdEntry4,'DdEntry4',\
;    DdEntry40,'DdEntry40',\
;    DdEntry41,'DdEntry41',\
;    DdEntry42,'DdEntry42',\
;    DdEntry43,'DdEntry43',\
;    DdEntry44,'DdEntry44',\
;    DdEntry45,'DdEntry45',\
;    DdEntry46,'DdEntry46',\
;    DdEntry47,'DdEntry47',\
;    DdEntry48,'DdEntry48',\
;    DdEntry49,'DdEntry49',\
;    DdEntry5,'DdEntry5',\
;    DdEntry50,'DdEntry50',\
;    DdEntry51,'DdEntry51',\
;    DdEntry52,'DdEntry52',\
;    DdEntry53,'DdEntry53',\
;    DdEntry54,'DdEntry54',\
;    DdEntry55,'DdEntry55',\
;    DdEntry56,'DdEntry56',\
;    DdEntry6,'DdEntry6',\
;    DdEntry7,'DdEntry7',\
;    DdEntry8,'DdEntry8',\
;    DdEntry9,'DdEntry9',\
;    DdNotifyFullscreenSpriteUpdate,'DdNotifyFullscreenSpriteUpdate',\
;    DdQueryVisRgnUniqueness,'DdQueryVisRgnUniqueness',\
;    DwmGetDirtyRgn,'DwmGetDirtyRgn',\
;    DwmGetSurfaceData,'DwmGetSurfaceData',\
;    EndFormPage,'EndFormPage',\
;    EndGdiRendering,'EndGdiRendering',\
;    EngQueryEMFInfo,'EngQueryEMFInfo',\
;    EudcLoadLinkW,'EudcLoadLinkW',\
;    EudcUnloadLinkW,'EudcUnloadLinkW',\
;    FontIsLinked,'FontIsLinked',\
;    ftsWordBreak,'ftsWordBreak',\
;    GdiAddGlsRecord,'GdiAddGlsRecord',\
;    GdiClearStockObjectCache,'GdiClearStockObjectCache',\
;    GdiConvertMetaFilePict,'GdiConvertMetaFilePict',\
;    GdiConvertToDevmodeW,'GdiConvertToDevmodeW',\
;    GdiCreateLocalEnhMetaFile,'GdiCreateLocalEnhMetaFile',\
;    GdiCreateLocalMetaFilePict,'GdiCreateLocalMetaFilePict',\
;    GdiDrawStream,'GdiDrawStream',\
;    GdiIsUMPDSandboxingEnabled,'GdiIsUMPDSandboxingEnabled',\
;    GdiEntry1,'GdiEntry1',\
;    GdiEntry10,'GdiEntry10',\
;    GdiEntry11,'GdiEntry11',\
;    GdiEntry12,'GdiEntry12',\
;    GdiEntry13,'GdiEntry13',\
;    GdiEntry14,'GdiEntry14',\
;    GdiEntry15,'GdiEntry15',\
;    GdiEntry16,'GdiEntry16',\
;    GdiEntry2,'GdiEntry2',\
;    GdiEntry3,'GdiEntry3',\
;    GdiEntry4,'GdiEntry4',\
;    GdiEntry5,'GdiEntry5',\
;    GdiEntry6,'GdiEntry6',\
;    GdiEntry7,'GdiEntry7',\
;    GdiEntry8,'GdiEntry8',\
;    GdiEntry9,'GdiEntry9',\
;    GdiLoadType1Fonts,'GdiLoadType1Fonts',\
;    GdiPlayPrivatePageEMF,'GdiPlayPrivatePageEMF',\
;    GdiSupportsFontChangeEvent,'GdiSupportsFontChangeEvent',\
;    GdiSwapBuffers,'GdiSwapBuffers',\
;    GetBitmapAttributes,'GetBitmapAttributes',\
;    GetCertificate,'GetCertificate',\
;    GetCertificateByHandle,'GetCertificateByHandle',\
;    GetCertificateSizeByHandle,'GetCertificateSizeByHandle',\
;    GetCurrentDpiInfo,'GetCurrentDpiInfo',\
;    GetFontFileData,'GetFontFileData',\
;    GetFontFileInfo,'GetFontFileInfo',\
;    GetFontRealizationInfo,'GetFontRealizationInfo',\
;    GetRelAbs,'GetRelAbs',\
;    GetStringBitmapA,'GetStringBitmapA',\
;    GetStringBitmapW,'GetStringBitmapW',\
;    GetTransform,'GetTransform',\
;    LpkDrawTextEx,'LpkDrawTextEx',\
;    LpkEditControl,'LpkEditControl',\
;    LpkExtTextOut,'LpkExtTextOut',\
;    LpkGetCharacterPlacement,'LpkGetCharacterPlacement',\
;    LpkGetTextExtentExPoint,'LpkGetTextExtentExPoint',\
;    LpkInitialize,'LpkInitialize',\
;    LpkPSMTextOut,'LpkPSMTextOut',\
;    LpkPresent,'LpkPresent',\
;    LpkTabbedTextOut,'LpkTabbedTextOut',\
;    LpkUseGDIWidthCache,'LpkUseGDIWidthCache',\
;    NamedEscape,'NamedEscape',\
;    RemoveFontResourceTracking,'RemoveFontResourceTracking',\
;    SetBrushAttributes,'SetBrushAttributes',\
;    SetRelAbs,'SetRelAbs',\
;    SetVirtualResolution,'SetVirtualResolution',\
;    UnloadNetworkFonts,'UnloadNetworkFonts',\
;    UspAllocCache,'UspAllocCache',\
;    UspAllocTemp,'UspAllocTemp',\
;    UspFreeMem,'UspFreeMem',\
;    bInitSystemAndFontsDirectoriesW,'bInitSystemAndFontsDirectoriesW',\
;    bMakePathNameW,'bMakePathNameW',\
;    cGetTTFFromFOT,'cGetTTFFromFOT',\
;    pfnRealizePalette,'pfnRealizePalette',\
;    pfnSelectPalette,'pfnSelectPalette'
;end if

end if ;GDI32_INC
