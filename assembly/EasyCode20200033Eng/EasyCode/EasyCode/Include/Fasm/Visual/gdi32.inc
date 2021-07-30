; ====================================================;
;                                                     ;
;      gdi32.inc for EC v2 Fasm visual projects       ;
;                   (version 1.0.2)                   ;
;                                                     ;
;            Copyright © Ramon Sala - 2018            ;
;                                                     ;
; ====================================================;

if  ~defined GDI32_INC
define GDI32_INC 1

struct PALETTEENTRY
    peRed   db  ?
    peGreen db  ?
    peBlue  db  ?
    peFlags db  ?
ends

if defined APP_WIN64
    extrn '__imp_AbortDoc' as AbortDoc:qword
    extrn '__imp_AbortPath' as AbortPath:qword
    extrn '__imp_AddFontResourceA' as AddFontResourceA:qword
    extrn '__imp_AddFontResourceW' as AddFontResourceW:qword
    extrn '__imp_AnimatePalette' as AnimatePalette:qword
    extrn '__imp_AngleArc' as AngleArc:qword
    extrn '__imp_Arc' as Arc:qword
    extrn '__imp_ArcTo' as ArcTo:qword
    extrn '__imp_BeginPath' as BeginPath:qword
    extrn '__imp_BitBlt' as BitBlt:qword
    extrn '__imp_CancelDC' as CancelDC:qword
    extrn '__imp_CheckColorsInGamut' as CheckColorsInGamut:qword
    extrn '__imp_ChoosePixelFormat' as ChoosePixelFormat:qword
    extrn '__imp_Chord' as Chord:qword
    extrn '__imp_CloseEnhMetaFile' as CloseEnhMetaFile:qword
    extrn '__imp_CloseFigure' as CloseFigure:qword
    extrn '__imp_CloseMetaFile' as CloseMetaFile:qword
    extrn '__imp_ColorMatchToTarget' as ColorMatchToTarget:qword
    extrn '__imp_CombineRgn' as CombineRgn:qword
    extrn '__imp_CombineTransform' as CombineTransform:qword
    extrn '__imp_CopyEnhMetaFileA' as CopyEnhMetaFileA:qword
    extrn '__imp_CopyEnhMetaFileW' as CopyEnhMetaFileW:qword
    extrn '__imp_CopyMetaFileA' as CopyMetaFileA:qword
    extrn '__imp_CopyMetaFileW' as CopyMetaFileW:qword
    extrn '__imp_CreateBitmap' as CreateBitmap:qword
    extrn '__imp_CreateBitmapIndirect' as CreateBitmapIndirect:qword
    extrn '__imp_CreateBrushIndirect' as CreateBrushIndirect:qword
    extrn '__imp_CreateColorSpaceA' as CreateColorSpaceA:qword
    extrn '__imp_CreateColorSpaceW' as CreateColorSpaceW:qword
    extrn '__imp_CreateCompatibleBitmap' as CreateCompatibleBitmap:qword
    extrn '__imp_CreateCompatibleDC' as CreateCompatibleDC:qword
    extrn '__imp_CreateDCA' as CreateDCA:qword
    extrn '__imp_CreateDCW' as CreateDCW:qword
    extrn '__imp_CreateDIBitmap' as CreateDIBitmap:qword
    extrn '__imp_CreateDIBPatternBrush' as CreateDIBPatternBrush:qword
    extrn '__imp_CreateDIBPatternBrushPt' as CreateDIBPatternBrushPt:qword
    extrn '__imp_CreateDIBSection' as CreateDIBSection:qword
    extrn '__imp_CreateDiscardableBitmap' as CreateDiscardableBitmap:qword
    extrn '__imp_CreateEllipticRgn' as CreateEllipticRgn:qword
    extrn '__imp_CreateEllipticRgnIndirect' as CreateEllipticRgnIndirect:qword
    extrn '__imp_CreateEnhMetaFileA' as CreateEnhMetaFileA:qword
    extrn '__imp_CreateEnhMetaFileW' as CreateEnhMetaFileW:qword
    extrn '__imp_CreateFontA' as CreateFontA:qword
    extrn '__imp_CreateFontIndirectA' as CreateFontIndirectA:qword
    extrn '__imp_CreateFontIndirectW' as CreateFontIndirectW:qword
    extrn '__imp_CreateFontW' as CreateFontW:qword
    extrn '__imp_CreateHalftonePalette' as CreateHalftonePalette:qword
    extrn '__imp_CreateHatchBrush' as CreateHatchBrush:qword
    extrn '__imp_CreateICA' as CreateICA:qword
    extrn '__imp_CreateICW' as CreateICW:qword
    extrn '__imp_CreateMetaFileA' as CreateMetaFileA:qword
    extrn '__imp_CreateMetaFileW' as CreateMetaFileW:qword
    extrn '__imp_CreatePalette' as CreatePalette:qword
    extrn '__imp_CreatePatternBrush' as CreatePatternBrush:qword
    extrn '__imp_CreatePen' as CreatePen:qword
    extrn '__imp_CreatePenIndirect' as CreatePenIndirect:qword
    extrn '__imp_CreatePolyPolygonRgn' as CreatePolyPolygonRgn:qword
    extrn '__imp_CreatePolygonRgn' as CreatePolygonRgn:qword
    extrn '__imp_CreateRectRgn' as CreateRectRgn:qword
    extrn '__imp_CreateRectRgnIndirect' as CreateRectRgnIndirect:qword
    extrn '__imp_CreateRoundRectRgn' as CreateRoundRectRgn:qword
    extrn '__imp_CreateScalableFontResourceA' as CreateScalableFontResourceA:qword
    extrn '__imp_CreateScalableFontResourceW' as CreateScalableFontResourceW:qword
    extrn '__imp_CreateSolidBrush' as CreateSolidBrush:qword
    extrn '__imp_DeleteColorSpace' as DeleteColorSpace:qword
    extrn '__imp_DeleteDC' as DeleteDC:qword
    extrn '__imp_DeleteEnhMetaFile' as DeleteEnhMetaFile:qword
    extrn '__imp_DeleteMetaFile' as DeleteMetaFile:qword
    extrn '__imp_DeleteObject' as DeleteObject:qword
    extrn '__imp_DescribePixelFormat' as DescribePixelFormat:qword
    extrn '__imp_DeviceCapabilitiesExA' as DeviceCapabilitiesExA:qword
    extrn '__imp_DeviceCapabilitiesExW' as DeviceCapabilitiesExW:qword
    extrn '__imp_DPtoLP' as DPtoLP:qword
    extrn '__imp_DrawEscape' as DrawEscape:qword
    extrn '__imp_Ellipse' as Ellipse:qword
    extrn '__imp_EndDoc' as EndDoc:qword
    extrn '__imp_EndPage' as EndPage:qword
    extrn '__imp_EndPath' as EndPath:qword
    extrn '__imp_EnumEnhMetaFile' as EnumEnhMetaFile:qword
    extrn '__imp_EnumFontFamiliesA' as EnumFontFamiliesA:qword
    extrn '__imp_EnumFontFamiliesExA' as EnumFontFamiliesExA:qword
    extrn '__imp_EnumFontFamiliesExW' as EnumFontFamiliesExW:qword
    extrn '__imp_EnumFontFamiliesW' as EnumFontFamiliesW:qword
    extrn '__imp_EnumFontsA' as EnumFontsA:qword
    extrn '__imp_EnumFontsW' as EnumFontsW:qword
    extrn '__imp_EnumICMProfilesA' as EnumICMProfilesA:qword
    extrn '__imp_EnumICMProfilesW' as EnumICMProfilesW:qword
    extrn '__imp_EnumMetaFile' as EnumMetaFile:qword
    extrn '__imp_EnumObjects' as EnumObjects:qword
    extrn '__imp_EqualRgn' as EqualRgn:qword
    extrn '__imp_Escape' as Escape:qword
    extrn '__imp_ExcludeClipRect' as ExcludeClipRect:qword
    extrn '__imp_ExtCreatePen' as ExtCreatePen:qword
    extrn '__imp_ExtCreateRegion' as ExtCreateRegion:qword
    extrn '__imp_ExtEscape' as ExtEscape:qword
    extrn '__imp_ExtFloodFill' as ExtFloodFill:qword
    extrn '__imp_ExtSelectClipRgn' as ExtSelectClipRgn:qword
    extrn '__imp_ExtTextOutA' as ExtTextOutA:qword
    extrn '__imp_ExtTextOutW' as ExtTextOutW:qword
    extrn '__imp_FillPath' as FillPath:qword
    extrn '__imp_FillRgn' as FillRgn:qword
    extrn '__imp_FixBrushOrgEx' as FixBrushOrgEx:qword
    extrn '__imp_FlattenPath' as FlattenPath:qword
    extrn '__imp_FloodFill' as FloodFill:qword
    extrn '__imp_FrameRgn' as FrameRgn:qword
    extrn '__imp_GdiComment' as GdiComment:qword
    extrn '__imp_GdiFlush' as GdiFlush:qword
    extrn '__imp_GdiGetBatchLimit' as GdiGetBatchLimit:qword
    extrn '__imp_GdiPlayDCScript' as GdiPlayDCScript:qword
    extrn '__imp_GdiPlayJournal' as GdiPlayJournal:qword
    extrn '__imp_GdiPlayScript' as GdiPlayScript:qword
    extrn '__imp_gdiPlaySpoolStream' as gdiPlaySpoolStream:qword
    extrn '__imp_GdiSetBatchLimit' as GdiSetBatchLimit:qword
    extrn '__imp_GetArcDirection' as GetArcDirection:qword
    extrn '__imp_GetAspectRatioFilterEx' as GetAspectRatioFilterEx:qword
    extrn '__imp_GetBitmapBits' as GetBitmapBits:qword
    extrn '__imp_GetBitmapDimensionEx' as GetBitmapDimensionEx:qword
    extrn '__imp_GetBkColor' as GetBkColor:qword
    extrn '__imp_GetBkMode' as GetBkMode:qword
    extrn '__imp_GetBoundsRect' as GetBoundsRect:qword
    extrn '__imp_GetBrushOrgEx' as GetBrushOrgEx:qword
    extrn '__imp_GetCharABCWidthsA' as GetCharABCWidthsA:qword
    extrn '__imp_GetCharABCWidthsW' as GetCharABCWidthsW:qword
    extrn '__imp_GetCharABCWidthsFloatA' as GetCharABCWidthsFloatA:qword
    extrn '__imp_GetCharABCWidthsFloatW' as GetCharABCWidthsFloatW:qword
    extrn '__imp_GetCharWidth32A' as GetCharWidth32A:qword
    extrn '__imp_GetCharWidth32W' as GetCharWidth32W:qword
    extrn '__imp_GetCharWidthA' as GetCharWidthA:qword
    extrn '__imp_GetCharWidthW' as GetCharWidthW:qword
    extrn '__imp_GetCharWidthFloatA' as GetCharWidthFloatA:qword
    extrn '__imp_GetCharWidthFloatW' as GetCharWidthFloatW:qword
    extrn '__imp_GetCharacterPlacementA' as GetCharacterPlacementA:qword
    extrn '__imp_GetCharacterPlacementW' as GetCharacterPlacementW:qword
    extrn '__imp_GetClipBox' as GetClipBox:qword
    extrn '__imp_GetClipRgn' as GetClipRgn:qword
    extrn '__imp_GetColorAdjustment' as GetColorAdjustment:qword
    extrn '__imp_GetColorSpace' as GetColorSpace:qword
    extrn '__imp_GetCurrentObject' as GetCurrentObject:qword
    extrn '__imp_GetCurrentPositionEx' as GetCurrentPositionEx:qword
    extrn '__imp_GetDCOrgEx' as GetDCOrgEx:qword
    extrn '__imp_GetDeviceCaps' as GetDeviceCaps:qword
    extrn '__imp_GetDeviceGammaRamp' as GetDeviceGammaRamp:qword
    extrn '__imp_GetDIBColorTable' as GetDIBColorTable:qword
    extrn '__imp_GetDIBits' as GetDIBits:qword
    extrn '__imp_GetEnhMetaFileA' as GetEnhMetaFileA:qword
    extrn '__imp_GetEnhMetaFileBits' as GetEnhMetaFileBits:qword
    extrn '__imp_GetEnhMetaFileDescriptionA' as GetEnhMetaFileDescriptionA:qword
    extrn '__imp_GetEnhMetaFileDescriptionW' as GetEnhMetaFileDescriptionW:qword
    extrn '__imp_GetEnhMetaFileHeader' as GetEnhMetaFileHeader:qword
    extrn '__imp_GetEnhMetaFilePaletteEntries' as GetEnhMetaFilePaletteEntries:qword
    extrn '__imp_GetEnhMetaFileW' as GetEnhMetaFileW:qword
    extrn '__imp_GetFontData' as GetFontData:qword
    extrn '__imp_GetFontLanguageInfo' as GetFontLanguageInfo:qword
    extrn '__imp_GetGlyphOutlineA' as GetGlyphOutlineA:qword
    extrn '__imp_GetGlyphOutlineW' as GetGlyphOutlineW:qword
    extrn '__imp_GetGraphicsMode' as GetGraphicsMode:qword
    extrn '__imp_GetICMProfileA' as GetICMProfileA:qword
    extrn '__imp_GetICMProfileW' as GetICMProfileW:qword
    extrn '__imp_GetKerningPairsA' as GetKerningPairsA:qword
    extrn '__imp_GetKerningPairsW' as GetKerningPairsW:qword
    extrn '__imp_GetLogColorSpaceA' as GetLogColorSpaceA:qword
    extrn '__imp_GetLogColorSpaceW' as GetLogColorSpaceW:qword
    extrn '__imp_GetMapMode' as GetMapMode:qword
    extrn '__imp_GetMetaFileA' as GetMetaFileA:qword
    extrn '__imp_GetMetaFileBitsEx' as GetMetaFileBitsEx:qword
    extrn '__imp_GetMetaFileW' as GetMetaFileW:qword
    extrn '__imp_GetMetaRgn' as GetMetaRgn:qword
    extrn '__imp_GetMiterLimit' as GetMiterLimit:qword
    extrn '__imp_GetNearestColor' as GetNearestColor:qword
    extrn '__imp_GetNearestPaletteIndex' as GetNearestPaletteIndex:qword
    extrn '__imp_GetObjectA' as GetObjectA:qword
    extrn '__imp_GetObjectType' as GetObjectType:qword
    extrn '__imp_GetObjectW' as GetObjectW:qword
    extrn '__imp_GetOutlineTextMetricsA' as GetOutlineTextMetricsA:qword
    extrn '__imp_GetOutlineTextMetricsW' as GetOutlineTextMetricsW:qword
    extrn '__imp_GetPaletteEntries' as GetPaletteEntries:qword
    extrn '__imp_GetPath' as GetPath:qword
    extrn '__imp_GetPixel' as GetPixel:qword
    extrn '__imp_GetPixelFormat' as GetPixelFormat:qword
    extrn '__imp_GetPolyFillMode' as GetPolyFillMode:qword
    extrn '__imp_GetROP2' as GetROP2:qword
    extrn '__imp_GetRandomRgn' as GetRandomRgn:qword
    extrn '__imp_GetRasterizerCaps' as GetRasterizerCaps:qword
    extrn '__imp_GetRegionData' as GetRegionData:qword
    extrn '__imp_GetRgnBox' as GetRgnBox:qword
    extrn '__imp_GetStockObject' as GetStockObject:qword
    extrn '__imp_GetStretchBltMode' as GetStretchBltMode:qword
    extrn '__imp_GetSystemPaletteEntries' as GetSystemPaletteEntries:qword
    extrn '__imp_GetSystemPaletteUse' as GetSystemPaletteUse:qword
    extrn '__imp_GetTextAlign' as GetTextAlign:qword
    extrn '__imp_GetTextCharacterExtra' as GetTextCharacterExtra:qword
    extrn '__imp_GetTextCharset' as GetTextCharset:qword
    extrn '__imp_GetTextCharsetInfo' as GetTextCharsetInfo:qword
    extrn '__imp_GetTextColor' as GetTextColor:qword
    extrn '__imp_GetTextExtentExPointA' as GetTextExtentExPointA:qword
    extrn '__imp_GetTextExtentExPointW' as GetTextExtentExPointW:qword
    extrn '__imp_GetTextExtentPoint32A' as GetTextExtentPoint32A:qword
    extrn '__imp_GetTextExtentPoint32W' as GetTextExtentPoint32W:qword
    extrn '__imp_GetTextExtentPointA' as GetTextExtentPointA:qword
    extrn '__imp_GetTextExtentPointW' as GetTextExtentPointW:qword
    extrn '__imp_GetTextFaceA' as GetTextFaceA:qword
    extrn '__imp_GetTextFaceW' as GetTextFaceW:qword
    extrn '__imp_GetTextMetricsA' as GetTextMetricsA:qword
    extrn '__imp_GetTextMetricsW' as GetTextMetricsW:qword
    extrn '__imp_GetViewportExtEx' as GetViewportExtEx:qword
    extrn '__imp_GetViewportOrgEx' as GetViewportOrgEx:qword
    extrn '__imp_GetWindowExtEx' as GetWindowExtEx:qword
    extrn '__imp_GetWindowOrgEx' as GetWindowOrgEx:qword
    extrn '__imp_GetWinMetaFileBits' as GetWinMetaFileBits:qword
    extrn '__imp_GetWorldTransform' as GetWorldTransform:qword
    extrn '__imp_IntersectClipRect' as IntersectClipRect:qword
    extrn '__imp_InvertRgn' as InvertRgn:qword
    extrn '__imp_LineDDA' as LineDDA:qword
    extrn '__imp_LineTo' as LineTo:qword
    extrn '__imp_LPtoDP' as LPtoDP:qword
    extrn '__imp_MaskBlt' as MaskBlt:qword
    extrn '__imp_ModifyWorldTransform' as ModifyWorldTransform:qword
    extrn '__imp_MoveToEx' as MoveToEx:qword
    extrn '__imp_OffsetClipRgn' as OffsetClipRgn:qword
    extrn '__imp_OffsetRgn' as OffsetRgn:qword
    extrn '__imp_OffsetViewportOrgEx' as OffsetViewportOrgEx:qword
    extrn '__imp_OffsetWindowOrgEx' as OffsetWindowOrgEx:qword
    extrn '__imp_PaintRgn' as PaintRgn:qword
    extrn '__imp_PatBlt' as PatBlt:qword
    extrn '__imp_PathToRegion' as PathToRegion:qword
    extrn '__imp_Pie' as Pie:qword
    extrn '__imp_PlayEnhMetaFile' as PlayEnhMetaFile:qword
    extrn '__imp_PlayEnhMetaFileRecord' as PlayEnhMetaFileRecord:qword
    extrn '__imp_PlayMetaFile' as PlayMetaFile:qword
    extrn '__imp_PlayMetaFileRecord' as PlayMetaFileRecord:qword
    extrn '__imp_PlgBlt' as PlgBlt:qword
    extrn '__imp_PolyBezier' as PolyBezier:qword
    extrn '__imp_PolyBezierTo' as PolyBezierTo:qword
    extrn '__imp_PolyDraw' as PolyDraw:qword
    extrn '__imp_Polygon' as Polygon:qword
    extrn '__imp_Polyline' as Polyline:qword
    extrn '__imp_PolylineTo' as PolylineTo:qword
    extrn '__imp_PolyPolygon' as PolyPolygon:qword
    extrn '__imp_PolyPolyline' as PolyPolyline:qword
    extrn '__imp_PolyTextOutA' as PolyTextOutA:qword
    extrn '__imp_PolyTextOutW' as PolyTextOutW:qword
    extrn '__imp_PtInRegion' as PtInRegion:qword
    extrn '__imp_PtVisible' as PtVisible:qword
    extrn '__imp_RealizePalette' as RealizePalette:qword
    extrn '__imp_Rectangle' as Rectangle:qword
    extrn '__imp_RectInRegion' as RectInRegion:qword
    extrn '__imp_RectVisible' as RectVisible:qword
    extrn '__imp_RemoveFontResourceA' as RemoveFontResourceA:qword
    extrn '__imp_RemoveFontResourceW' as RemoveFontResourceW:qword
    extrn '__imp_ResetDCA' as ResetDCA:qword
    extrn '__imp_ResetDCW' as ResetDCW:qword
    extrn '__imp_ResizePalette' as ResizePalette:qword
    extrn '__imp_RestoreDC' as RestoreDC:qword
    extrn '__imp_RoundRect' as RoundRect:qword
    extrn '__imp_SaveDC' as SaveDC:qword
    extrn '__imp_ScaleViewportExtEx' as ScaleViewportExtEx:qword
    extrn '__imp_ScaleWindowExtEx' as ScaleWindowExtEx:qword
    extrn '__imp_SelectClipPath' as SelectClipPath:qword
    extrn '__imp_SelectClipRgn' as SelectClipRgn:qword
    extrn '__imp_SelectObject' as SelectObject:qword
    extrn '__imp_SelectPalette' as SelectPalette:qword
    extrn '__imp_SetAbortProc' as SetAbortProc:qword
    extrn '__imp_SetArcDirection' as SetArcDirection:qword
    extrn '__imp_SetBitmapBits' as SetBitmapBits:qword
    extrn '__imp_SetBitmapDimensionEx' as SetBitmapDimensionEx:qword
    extrn '__imp_SetBkColor' as SetBkColor:qword
    extrn '__imp_SetBkMode' as SetBkMode:qword
    extrn '__imp_SetBoundsRect' as SetBoundsRect:qword
    extrn '__imp_SetBrushOrgEx' as SetBrushOrgEx:qword
    extrn '__imp_SetColorAdjustment' as SetColorAdjustment:qword
    extrn '__imp_SetColorSpace' as SetColorSpace:qword
    extrn '__imp_SetDIBColorTable' as SetDIBColorTable:qword
    extrn '__imp_SetDIBits' as SetDIBits:qword
    extrn '__imp_SetDIBitsToDevice' as SetDIBitsToDevice:qword
    extrn '__imp_SetDeviceGammaRamp' as SetDeviceGammaRamp:qword
    extrn '__imp_SetEnhMetaFileBits' as SetEnhMetaFileBits:qword
    extrn '__imp_SetFontEnumeration' as SetFontEnumeration:qword
    extrn '__imp_SetGraphicsMode' as SetGraphicsMode:qword
    extrn '__imp_SetICMMode' as SetICMMode:qword
    extrn '__imp_SetICMProfileA' as SetICMProfileA:qword
    extrn '__imp_SetICMProfileW' as SetICMProfileW:qword
    extrn '__imp_SetMapMode' as SetMapMode:qword
    extrn '__imp_SetMapperFlags' as SetMapperFlags:qword
    extrn '__imp_SetMetaFileBitsEx' as SetMetaFileBitsEx:qword
    extrn '__imp_SetMetaRgn' as SetMetaRgn:qword
    extrn '__imp_SetMiterLimit' as SetMiterLimit:qword
    extrn '__imp_SetPaletteEntries' as SetPaletteEntries:qword
    extrn '__imp_SetPixel' as SetPixel:qword
    extrn '__imp_SetPixelFormat' as SetPixelFormat:qword
    extrn '__imp_SetPixelV' as SetPixelV:qword
    extrn '__imp_SetPolyFillMode' as SetPolyFillMode:qword
    extrn '__imp_SetRectRgn' as SetRectRgn:qword
    extrn '__imp_SetROP2' as SetROP2:qword
    extrn '__imp_SetStretchBltMode' as SetStretchBltMode:qword
    extrn '__imp_SetSystemPaletteUse' as SetSystemPaletteUse:qword
    extrn '__imp_SetTextAlign' as SetTextAlign:qword
    extrn '__imp_SetTextCharacterExtra' as SetTextCharacterExtra:qword
    extrn '__imp_SetTextColor' as SetTextColor:qword
    extrn '__imp_SetTextJustification' as SetTextJustification:qword
    extrn '__imp_SetViewportExtEx' as SetViewportExtEx:qword
    extrn '__imp_SetViewportOrgEx' as SetViewportOrgEx:qword
    extrn '__imp_SetWinMetaFileBits' as SetWinMetaFileBits:qword
    extrn '__imp_SetWindowExtEx' as SetWindowExtEx:qword
    extrn '__imp_SetWindowOrgEx' as SetWindowOrgEx:qword
    extrn '__imp_SetWorldTransform' as SetWorldTransform:qword
    extrn '__imp_StartDocA' as StartDocA:qword
    extrn '__imp_StartDocW' as StartDocW:qword
    extrn '__imp_StartPage' as StartPage:qword
    extrn '__imp_StretchBlt' as StretchBlt:qword
    extrn '__imp_StretchDIBits' as StretchDIBits:qword
    extrn '__imp_StrokeAndFillPath' as StrokeAndFillPath:qword
    extrn '__imp_StrokePath' as StrokePath:qword
    extrn '__imp_SwapBuffers' as SwapBuffers:qword
    extrn '__imp_TextOutA' as TextOutA:qword
    extrn '__imp_TextOutW' as TextOutW:qword
    extrn '__imp_TranslateCharsetInfo' as TranslateCharsetInfo:qword
    extrn '__imp_UnrealizeObject' as UnrealizeObject:qword
    extrn '__imp_UpdateColors' as UpdateColors:qword
    extrn '__imp_UpdateICMRegKeyA' as UpdateICMRegKeyA:qword
    extrn '__imp_UpdateICMRegKeyW' as UpdateICMRegKeyW:qword
    extrn '__imp_WidenPath' as WidenPath:qword

    if (NTDDI_VERSION >= NTDDI_WIN98_ME)
        extrn '__imp_ColorCorrectPalette' as ColorCorrectPalette:qword
        extrn '__imp_EnableEUDC' as EnableEUDC:qword
        extrn '__imp_GetLayout' as GetLayout:qword
        if (NTDDI_VERSION <> NTDDI_WINNT4)
            extrn '__imp_SetLayout' as SetLayout:qword
        end if
    end if

    if (NTDDI_VERSION >= NTDDI_WINNT4)
        extrn '__imp_GdiAddFontResourceW' as GdiAddFontResourceW:qword
        extrn '__imp_GdiAddGlsBounds' as GdiAddGlsBounds:qword
        extrn '__imp_GdiCleanCacheDC' as GdiCleanCacheDC:qword
        extrn '__imp_GdiConsoleTextOut' as GdiConsoleTextOut:qword
        extrn '__imp_GdiConvertAndCheckDC' as GdiConvertAndCheckDC:qword
        extrn '__imp_GdiConvertBitmap' as GdiConvertBitmap:qword
        extrn '__imp_GdiConvertBrush' as GdiConvertBrush:qword
        extrn '__imp_GdiConvertDC' as GdiConvertDC:qword
        extrn '__imp_GdiConvertEnhMetaFile' as GdiConvertEnhMetaFile:qword
        extrn '__imp_GdiConvertFont' as GdiConvertFont:qword
        extrn '__imp_GdiConvertPalette' as GdiConvertPalette:qword
        extrn '__imp_GdiConvertRegion' as GdiConvertRegion:qword
        extrn '__imp_GdiDeleteLocalDC' as GdiDeleteLocalDC:qword
        extrn '__imp_GdiDescribePixelFormat' as GdiDescribePixelFormat:qword
        extrn '__imp_GdiDllInitialize' as GdiDllInitialize:qword
        extrn '__imp_GdiFixUpHandle' as GdiFixUpHandle:qword
        extrn '__imp_GdiGetCharDimensions' as GdiGetCharDimensions:qword
        extrn '__imp_GdiGetCodePage' as GdiGetCodePage:qword
        extrn '__imp_GdiGetLocalBrush' as GdiGetLocalBrush:qword
        extrn '__imp_GdiGetLocalDC' as GdiGetLocalDC:qword
        extrn '__imp_GdiGetLocalFont' as GdiGetLocalFont:qword
        extrn '__imp_GdiGetSpoolMessage' as GdiGetSpoolMessage:qword
        extrn '__imp_GdiInitSpool' as GdiInitSpool:qword
        extrn '__imp_GdiIsMetaFileDC' as GdiIsMetaFileDC:qword
        extrn '__imp_GdiIsMetaPrintDC' as GdiIsMetaPrintDC:qword
        extrn '__imp_GdiProcessSetup' as GdiProcessSetup:qword
        extrn '__imp_GdiQueryFonts' as GdiQueryFonts:qword
        extrn '__imp_GdiQueryTable' as GdiQueryTable:qword
        extrn '__imp_GdiReleaseLocalDC' as GdiReleaseLocalDC:qword
        extrn '__imp_GdiSetAttrs' as GdiSetAttrs:qword
        extrn '__imp_GdiSetPixelFormat' as GdiSetPixelFormat:qword
        extrn '__imp_GdiSetServerAttr' as GdiSetServerAttr:qword
        extrn '__imp_GdiValidateHandle' as GdiValidateHandle:qword
        extrn '__imp_GetCharWidthInfo' as GetCharWidthInfo:qword
        extrn '__imp_GetETM' as GetETM:qword
        extrn '__imp_GetEnhMetaFilePixelFormat' as GetEnhMetaFilePixelFormat:qword
        extrn '__imp_GetFontResourceInfoW' as GetFontResourceInfoW:qword
        extrn '__imp_GetGlyphOutlineWow' as GetGlyphOutlineWow:qword
        extrn '__imp_GetHFONT' as GetHFONT:qword
        extrn '__imp_HT_Get8BPPFormatPalette' as HT_Get8BPPFormatPalette:qword
        extrn '__imp_HT_Get8BPPMaskPalette' as HT_Get8BPPMaskPalette:qword
        extrn '__imp_IsValidEnhMetaRecord' as IsValidEnhMetaRecord:qword
        extrn '__imp_IsValidEnhMetaRecordOffExt' as IsValidEnhMetaRecordOffExt:qword
        extrn '__imp_PolyPatBlt' as PolyPatBlt:qword
        extrn '__imp_SelectBrushLocal' as SelectBrushLocal:qword
        extrn '__imp_SelectFontLocal' as SelectFontLocal:qword
        extrn '__imp_SetMagicColors' as SetMagicColors:qword
        GetFontResourceInfo equ GetFontResourceInfoW
    end if

    if (NTDDI_VERSION >= NTDDI_WIN2K)
        extrn '__imp_AddFontMemResourceEx' as AddFontMemResourceEx:qword
        extrn '__imp_AddFontResourceExA' as AddFontResourceExA:qword
        extrn '__imp_AddFontResourceExW' as AddFontResourceExW:qword
        extrn '__imp_BRUSHOBJ_hGetColorTransform' as BRUSHOBJ_hGetColorTransform:qword
        extrn '__imp_BRUSHOBJ_pvAllocRbrush' as BRUSHOBJ_pvAllocRbrush:qword
        extrn '__imp_BRUSHOBJ_pvGetRbrush' as BRUSHOBJ_pvGetRbrush:qword
        extrn '__imp_BRUSHOBJ_ulGetBrushColor' as BRUSHOBJ_ulGetBrushColor:qword
        extrn '__imp_CLIPOBJ_bEnum' as CLIPOBJ_bEnum:qword
        extrn '__imp_CLIPOBJ_cEnumStart' as CLIPOBJ_cEnumStart:qword
        extrn '__imp_CLIPOBJ_ppoGetPath' as CLIPOBJ_ppoGetPath:qword
        extrn '__imp_CreateFontIndirectExA' as CreateFontIndirectExA:qword
        extrn '__imp_CreateFontIndirectExW' as CreateFontIndirectExW:qword
        extrn '__imp_EngAcquireSemaphore' as EngAcquireSemaphore:qword
        extrn '__imp_EngAlphaBlend' as EngAlphaBlend:qword
        extrn '__imp_EngAssociateSurface' as EngAssociateSurface:qword
        extrn '__imp_EngBitBlt' as EngBitBlt:qword
        extrn '__imp_EngCheckAbort' as EngCheckAbort:qword
        extrn '__imp_EngComputeGlyphSet' as EngComputeGlyphSet:qword
        extrn '__imp_EngCopyBits' as EngCopyBits:qword
        extrn '__imp_EngCreateBitmap' as EngCreateBitmap:qword
        extrn '__imp_EngCreateClip' as EngCreateClip:qword
        extrn '__imp_EngCreateDeviceBitmap' as EngCreateDeviceBitmap:qword
        extrn '__imp_EngCreateDeviceSurface' as EngCreateDeviceSurface:qword
        extrn '__imp_EngCreatePalette' as EngCreatePalette:qword
        extrn '__imp_EngCreateSemaphore' as EngCreateSemaphore:qword
        extrn '__imp_EngDeleteClip' as EngDeleteClip:qword
        extrn '__imp_EngDeletePalette' as EngDeletePalette:qword
        extrn '__imp_EngDeletePath' as EngDeletePath:qword
        extrn '__imp_EngDeleteSemaphore' as EngDeleteSemaphore:qword
        extrn '__imp_EngDeleteSurface' as EngDeleteSurface:qword
        extrn '__imp_EngEraseSurface' as EngEraseSurface:qword
        extrn '__imp_EngFillPath' as EngFillPath:qword
        extrn '__imp_EngFindResource' as EngFindResource:qword
        extrn '__imp_EngFreeModule' as EngFreeModule:qword
        extrn '__imp_EngGetCurrentCodePage' as EngGetCurrentCodePage:qword
        extrn '__imp_EngGetDriverName' as EngGetDriverName:qword
        extrn '__imp_EngGetPrinterDataFileName' as EngGetPrinterDataFileName:qword
        extrn '__imp_EngGradientFill' as EngGradientFill:qword
        extrn '__imp_EngLineTo' as EngLineTo:qword
        extrn '__imp_EngLoadModule' as EngLoadModule:qword
        extrn '__imp_EngLockSurface' as EngLockSurface:qword
        extrn '__imp_EngMarkBandingSurface' as EngMarkBandingSurface:qword
        extrn '__imp_EngMultiByteToUnicodeN' as EngMultiByteToUnicodeN:qword
        extrn '__imp_EngMultiByteToWideChar' as EngMultiByteToWideChar:qword
        extrn '__imp_EngPaint' as EngPaint:qword
        extrn '__imp_EngPlgBlt' as EngPlgBlt:qword
        extrn '__imp_EngQueryLocalTime' as EngQueryLocalTime:qword
        extrn '__imp_EngReleaseSemaphore' as EngReleaseSemaphore:qword
        extrn '__imp_EngStretchBlt' as EngStretchBlt:qword
        extrn '__imp_EngStretchBltROP' as EngStretchBltROP:qword
        extrn '__imp_EngStrokeAndFillPath' as EngStrokeAndFillPath:qword
        extrn '__imp_EngStrokePath' as EngStrokePath:qword
        extrn '__imp_EngTextOut' as EngTextOut:qword
        extrn '__imp_EngTransparentBlt' as EngTransparentBlt:qword
        extrn '__imp_EngUnicodeToMultiByteN' as EngUnicodeToMultiByteN:qword
        extrn '__imp_EngUnlockSurface' as EngUnlockSurface:qword
        extrn '__imp_EngWideCharToMultiByte' as EngWideCharToMultiByte:qword
        extrn '__imp_FONTOBJ_cGetAllGlyphHandles' as FONTOBJ_cGetAllGlyphHandles:qword
        extrn '__imp_FONTOBJ_cGetGlyphs' as FONTOBJ_cGetGlyphs:qword
        extrn '__imp_FONTOBJ_pQueryGlyphAttrs' as FONTOBJ_pQueryGlyphAttrs:qword
        extrn '__imp_FONTOBJ_pfdg' as FONTOBJ_pfdg:qword
        extrn '__imp_FONTOBJ_pifi' as FONTOBJ_pifi:qword
        extrn '__imp_FONTOBJ_pvTrueTypeFontFile' as FONTOBJ_pvTrueTypeFontFile:qword
        extrn '__imp_FONTOBJ_pxoGetXform' as FONTOBJ_pxoGetXform:qword
        extrn '__imp_FONTOBJ_vGetInfo' as FONTOBJ_vGetInfo:qword
        extrn '__imp_GdiAlphaBlend' as GdiAlphaBlend:qword
        extrn '__imp_GdiArtificialDecrementDriver' as GdiArtificialDecrementDriver:qword
        extrn '__imp_GdiConvertBitmapV5' as GdiConvertBitmapV5:qword
        extrn '__imp_GdiDeleteSpoolFileHandle' as GdiDeleteSpoolFileHandle:qword
        extrn '__imp_GdiEndDocEMF' as GdiEndDocEMF:qword
        extrn '__imp_GdiEndPageEMF' as GdiEndPageEMF:qword
        extrn '__imp_GdiFullscreenControl' as GdiFullscreenControl:qword
        extrn '__imp_GdiGetBitmapBitsSize' as GdiGetBitmapBitsSize:qword
        extrn '__imp_GdiGetDC' as GdiGetDC:qword
        extrn '__imp_GetDCBrushColor' as GetDCBrushColor:qword
        extrn '__imp_GetDCPenColor' as GetDCPenColor:qword
        extrn '__imp_GdiGetDevmodeForPage' as GdiGetDevmodeForPage:qword
        extrn '__imp_GdiGetPageCount' as GdiGetPageCount:qword
        extrn '__imp_GdiGetPageHandle' as GdiGetPageHandle:qword
        extrn '__imp_GdiGetSpoolFileHandle' as GdiGetSpoolFileHandle:qword
        extrn '__imp_GdiGradientFill' as GdiGradientFill:qword
        extrn '__imp_GdiInitializeLanguagePack' as GdiInitializeLanguagePack:qword
        extrn '__imp_GdiIsPlayMetafileDC' as GdiIsPlayMetafileDC:qword
        extrn '__imp_GdiPlayEMF' as GdiPlayEMF:qword
        extrn '__imp_GdiPlayPageEMF' as GdiPlayPageEMF:qword
        extrn '__imp_GdiPrinterThunk' as GdiPrinterThunk:qword
        extrn '__imp_GdiRealizationInfo' as GdiRealizationInfo:qword
        extrn '__imp_GdiReleaseDC' as GdiReleaseDC:qword
        extrn '__imp_GdiResetDCEMF' as GdiResetDCEMF:qword
        extrn '__imp_GdiSetLastError' as GdiSetLastError:qword
        extrn '__imp_GdiStartDocEMF' as GdiStartDocEMF:qword
        extrn '__imp_GdiStartPageEMF' as GdiStartPageEMF:qword
        extrn '__imp_GdiTransparentBlt' as GdiTransparentBlt:qword
        extrn '__imp_GetCharABCWidthsI' as GetCharABCWidthsI:qword
        extrn '__imp_GetCharWidthI' as GetCharWidthI:qword
        extrn '__imp_GetEUDCTimeStamp' as GetEUDCTimeStamp:qword
        extrn '__imp_GetEUDCTimeStampExW' as GetEUDCTimeStampExW:qword
        extrn '__imp_GetFontAssocStatus' as GetFontAssocStatus:qword
        extrn '__imp_GetFontUnicodeRanges' as GetFontUnicodeRanges:qword
        extrn '__imp_GetGlyphIndicesA' as GetGlyphIndicesA:qword
        extrn '__imp_GetGlyphIndicesW' as GetGlyphIndicesW:qword
        extrn '__imp_GetTextExtentExPointI' as GetTextExtentExPointI:qword
        extrn '__imp_GetTextExtentExPointWPri' as GetTextExtentExPointWPri:qword
        extrn '__imp_GetTextExtentPointI' as GetTextExtentPointI:qword
        extrn '__imp_GetTextFaceAliasW' as GetTextFaceAliasW:qword
        extrn '__imp_MirrorRgn' as MirrorRgn:qword
        extrn '__imp_PATHOBJ_bEnum' as PATHOBJ_bEnum:qword
        extrn '__imp_PATHOBJ_bEnumClipLines' as PATHOBJ_bEnumClipLines:qword
        extrn '__imp_PATHOBJ_vEnumStart' as PATHOBJ_vEnumStart:qword
        extrn '__imp_PATHOBJ_vEnumStartClipLines' as PATHOBJ_vEnumStartClipLines:qword
        extrn '__imp_PATHOBJ_vGetBounds' as PATHOBJ_vGetBounds:qword
        extrn '__imp_QueryFontAssocStatus' as QueryFontAssocStatus:qword
        extrn '__imp_RemoveFontMemResourceEx' as RemoveFontMemResourceEx:qword
        extrn '__imp_RemoveFontResourceExA' as RemoveFontResourceExA:qword
        extrn '__imp_RemoveFontResourceExW' as RemoveFontResourceExW:qword
        extrn '__imp_SetDCBrushColor' as SetDCBrushColor:qword
        extrn '__imp_SetDCPenColor' as SetDCPenColor:qword
        extrn '__imp_SetLayoutWidth' as SetLayoutWidth:qword
        extrn '__imp_StartFormPage' as StartFormPage:qword
        extrn '__imp_STROBJ_bEnum' as STROBJ_bEnum:qword
        extrn '__imp_STROBJ_bEnumPositionsOnly' as STROBJ_bEnumPositionsOnly:qword
        extrn '__imp_STROBJ_bGetAdvanceWidths' as STROBJ_bGetAdvanceWidths:qword
        extrn '__imp_STROBJ_dwGetCodePage' as STROBJ_dwGetCodePage:qword
        extrn '__imp_STROBJ_vEnumStart' as STROBJ_vEnumStart:qword
        extrn '__imp_XFORMOBJ_bApplyXform' as XFORMOBJ_bApplyXform:qword
        extrn '__imp_XFORMOBJ_iGetXform' as XFORMOBJ_iGetXform:qword
        extrn '__imp_XLATEOBJ_cGetPalette' as XLATEOBJ_cGetPalette:qword
        extrn '__imp_XLATEOBJ_hGetColorTransform' as XLATEOBJ_hGetColorTransform:qword
        extrn '__imp_XLATEOBJ_iXlate' as XLATEOBJ_iXlate:qword
        extrn '__imp_XLATEOBJ_piVector' as XLATEOBJ_piVector:qword
        api AddFontResourceEx,\
            CreateFontIndirectEx,\
            GetGlyphIndices,\
            RemoveFontResourceEx
    end if

    if (NTDDI_VERSION >= NTDDI_WINXP)
        extrn '__imp_GetBrushAttributes' as GetBrushAttributes:qword
        extrn '__imp_SetBitmapAttributes' as SetBitmapAttributes:qword
    end if

    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp_ConfigureOPMProtectedOutput' as ConfigureOPMProtectedOutput:qword
        extrn '__imp_CreateOPMProtectedOutputs' as CreateOPMProtectedOutputs:qword
        extrn '__imp_D3DKMTCheckExclusiveOwnership' as D3DKMTCheckExclusiveOwnership:qword
        extrn '__imp_D3DKMTCheckMonitorPowerState' as D3DKMTCheckMonitorPowerState:qword
        extrn '__imp_D3DKMTCheckOcclusion' as D3DKMTCheckOcclusion:qword
        extrn '__imp_D3DKMTCloseAdapter' as D3DKMTCloseAdapter:qword
        extrn '__imp_D3DKMTCreateAllocation' as D3DKMTCreateAllocation:qword
        extrn '__imp_D3DKMTCreateContext' as D3DKMTCreateContext:qword
        extrn '__imp_D3DKMTCreateDCFromMemory' as D3DKMTCreateDCFromMemory:qword
        extrn '__imp_D3DKMTCreateDevice' as D3DKMTCreateDevice:qword
        extrn '__imp_D3DKMTCreateOverlay' as D3DKMTCreateOverlay:qword
        extrn '__imp_D3DKMTCreateSynchronizationObject' as D3DKMTCreateSynchronizationObject:qword
        extrn '__imp_D3DKMTDestroyAllocation' as D3DKMTDestroyAllocation:qword
        extrn '__imp_D3DKMTDestroyContext' as D3DKMTDestroyContext:qword
        extrn '__imp_D3DKMTDestroyDCFromMemory' as D3DKMTDestroyDCFromMemory:qword
        extrn '__imp_D3DKMTDestroyDevice' as D3DKMTDestroyDevice:qword
        extrn '__imp_D3DKMTDestroyOverlay' as D3DKMTDestroyOverlay:qword
        extrn '__imp_D3DKMTDestroySynchronizationObject' as D3DKMTDestroySynchronizationObject:qword
        extrn '__imp_D3DKMTEscape' as D3DKMTEscape:qword
        extrn '__imp_D3DKMTFlipOverlay' as D3DKMTFlipOverlay:qword
        extrn '__imp_D3DKMTGetContextSchedulingPriority' as D3DKMTGetContextSchedulingPriority:qword
        extrn '__imp_D3DKMTGetDeviceState' as D3DKMTGetDeviceState:qword
        extrn '__imp_D3DKMTGetDisplayModeList' as D3DKMTGetDisplayModeList:qword
        extrn '__imp_D3DKMTGetMultisampleMethodList' as D3DKMTGetMultisampleMethodList:qword
        extrn '__imp_D3DKMTGetPresentHistory' as D3DKMTGetPresentHistory:qword
        extrn '__imp_D3DKMTGetProcessSchedulingPriorityClass' as D3DKMTGetProcessSchedulingPriorityClass:qword
        extrn '__imp_D3DKMTGetRuntimeData' as D3DKMTGetRuntimeData:qword
        extrn '__imp_D3DKMTGetScanLine' as D3DKMTGetScanLine:qword
        extrn '__imp_D3DKMTGetSharedPrimaryHandle' as D3DKMTGetSharedPrimaryHandle:qword
        extrn '__imp_D3DKMTInvalidateActiveVidPn' as D3DKMTInvalidateActiveVidPn:qword
        extrn '__imp_D3DKMTLock' as D3DKMTLock:qword
        extrn '__imp_D3DKMTOpenAdapterFromDeviceName' as D3DKMTOpenAdapterFromDeviceName:qword
        extrn '__imp_D3DKMTOpenAdapterFromGdiDisplayName' as D3DKMTOpenAdapterFromGdiDisplayName:qword
        extrn '__imp_D3DKMTOpenAdapterFromHdc' as D3DKMTOpenAdapterFromHdc:qword
        extrn '__imp_D3DKMTOpenResource' as D3DKMTOpenResource:qword
        extrn '__imp_D3DKMTPollDisplayChildren' as D3DKMTPollDisplayChildren:qword
        extrn '__imp_D3DKMTPresent' as D3DKMTPresent:qword
        extrn '__imp_D3DKMTQueryAdapterInfo' as D3DKMTQueryAdapterInfo:qword
        extrn '__imp_D3DKMTQueryAllocationResidency' as D3DKMTQueryAllocationResidency:qword
        extrn '__imp_D3DKMTQueryResourceInfo' as D3DKMTQueryResourceInfo:qword
        extrn '__imp_D3DKMTReleaseProcessVidPnSourceOwners' as D3DKMTReleaseProcessVidPnSourceOwners:qword
        extrn '__imp_D3DKMTRender' as D3DKMTRender:qword
        extrn '__imp_D3DKMTSetAllocationPriority' as D3DKMTSetAllocationPriority:qword
        extrn '__imp_D3DKMTSetContextSchedulingPriority' as D3DKMTSetContextSchedulingPriority:qword
        extrn '__imp_D3DKMTSetDisplayMode' as D3DKMTSetDisplayMode:qword
        extrn '__imp_D3DKMTSetDisplayPrivateDriverFormat' as D3DKMTSetDisplayPrivateDriverFormat:qword
        extrn '__imp_D3DKMTSetGammaRamp' as D3DKMTSetGammaRamp:qword
        extrn '__imp_D3DKMTSetProcessSchedulingPriorityClass' as D3DKMTSetProcessSchedulingPriorityClass:qword
        extrn '__imp_D3DKMTSetQueuedLimit' as D3DKMTSetQueuedLimit:qword
        extrn '__imp_D3DKMTSetVidPnSourceOwner' as D3DKMTSetVidPnSourceOwner:qword
        extrn '__imp_D3DKMTSharedPrimaryLockNotification' as D3DKMTSharedPrimaryLockNotification:qword
        extrn '__imp_D3DKMTSharedPrimaryUnLockNotification' as D3DKMTSharedPrimaryUnLockNotification:qword
        extrn '__imp_D3DKMTSignalSynchronizationObject' as D3DKMTSignalSynchronizationObject:qword
        extrn '__imp_D3DKMTUnlock' as D3DKMTUnlock:qword
        extrn '__imp_D3DKMTUpdateOverlay' as D3DKMTUpdateOverlay:qword
        extrn '__imp_D3DKMTWaitForIdle' as D3DKMTWaitForIdle:qword
        extrn '__imp_D3DKMTWaitForSynchronizationObject' as D3DKMTWaitForSynchronizationObject:qword
        extrn '__imp_D3DKMTWaitForVerticalBlankEvent' as D3DKMTWaitForVerticalBlankEvent:qword
        extrn '__imp_DDCCIGetCapabilitiesString' as DDCCIGetCapabilitiesString:qword
        extrn '__imp_DDCCIGetCapabilitiesStringLength' as DDCCIGetCapabilitiesStringLength:qword
        extrn '__imp_DDCCIGetTimingReport' as DDCCIGetTimingReport:qword
        extrn '__imp_DDCCIGetVCPFeature' as DDCCIGetVCPFeature:qword
        extrn '__imp_DDCCISaveCurrentSettings' as DDCCISaveCurrentSettings:qword
        extrn '__imp_DDCCISetVCPFeature' as DDCCISetVCPFeature:qword
        extrn '__imp_DestroyOPMProtectedOutput' as DestroyOPMProtectedOutput:qword
        extrn '__imp_DestroyPhysicalMonitorInternal' as DestroyPhysicalMonitorInternal:qword
        extrn '__imp_GdiIsScreenDC' as GdiIsScreenDC:qword
        extrn '__imp_GetCOPPCompatibleOPMInformation' as GetCOPPCompatibleOPMInformation:qword
        extrn '__imp_GetNumberOfPhysicalMonitors' as GetNumberOfPhysicalMonitors:qword
        extrn '__imp_GetOPMInformation' as GetOPMInformation:qword
        extrn '__imp_GetOPMRandomNumber' as GetOPMRandomNumber:qword
        extrn '__imp_GetPhysicalMonitorDescription' as GetPhysicalMonitorDescription:qword
        extrn '__imp_GetPhysicalMonitors' as GetPhysicalMonitors:qword
        extrn '__imp_GetSuggestedOPMProtectedOutputArraySize' as GetSuggestedOPMProtectedOutputArraySize:qword
        extrn '__imp_SetOPMSigningKeyAndSequenceNumbers' as SetOPMSigningKeyAndSequenceNumbers:qword
    end if

    if (NTDDI_VERSION >= NTDDI_WIN7)
        extrn '__imp_D3DKMTAcquireKeyedMutex' as D3DKMTAcquireKeyedMutex:qword
        extrn '__imp_D3DKMTCheckSharedResourceAccess' as D3DKMTCheckSharedResourceAccess:qword
        extrn '__imp_D3DKMTCheckVidPnExclusiveOwnership' as D3DKMTCheckVidPnExclusiveOwnership:qword
        extrn '__imp_D3DKMTConfigureSharedResource' as D3DKMTConfigureSharedResource:qword
        extrn '__imp_D3DKMTCreateAllocation2' as D3DKMTCreateAllocation2:qword
        extrn '__imp_D3DKMTCreateKeyedMutex' as D3DKMTCreateKeyedMutex:qword
        extrn '__imp_D3DKMTCreateSynchronizationObject2' as D3DKMTCreateSynchronizationObject2:qword
        extrn '__imp_D3DKMTDestroyKeyedMutex' as D3DKMTDestroyKeyedMutex:qword
        extrn '__imp_D3DKMTGetOverlayState' as D3DKMTGetOverlayState:qword
        extrn '__imp_D3DKMTOpenKeyedMutex' as D3DKMTOpenKeyedMutex:qword
        extrn '__imp_D3DKMTOpenResource2' as D3DKMTOpenResource2:qword
        extrn '__imp_D3DKMTOpenSynchronizationObject' as D3DKMTOpenSynchronizationObject:qword
        extrn '__imp_D3DKMTReleaseKeyedMutex' as D3DKMTReleaseKeyedMutex:qword
        extrn '__imp_D3DKMTSignalSynchronizationObject2' as D3DKMTSignalSynchronizationObject2:qword
        extrn '__imp_D3DKMTWaitForSynchronizationObject2' as D3DKMTWaitForSynchronizationObject2:qword
    end if

    if (NTDDI_VERSION >= NTDDI_WIN8)
        extrn '__imp_D3DKMTAcquireKeyedMutex2' as D3DKMTAcquireKeyedMutex2:qword
        extrn '__imp_D3DKMTCreateKeyedMutex2' as D3DKMTCreateKeyedMutex2:qword
        extrn '__imp_D3DKMTCreateOutputDupl' as D3DKMTCreateOutputDupl:qword
        extrn '__imp_D3DKMTDestroyOutputDupl' as D3DKMTDestroyOutputDupl:qword
        extrn '__imp_D3DKMTEnumAdapters' as D3DKMTEnumAdapters:qword
        extrn '__imp_D3DKMTGetContextInProcessSchedulingPriority' as D3DKMTGetContextInProcessSchedulingPriority:qword
        extrn '__imp_D3DKMTGetSharedResourceAdapterLuid' as D3DKMTGetSharedResourceAdapterLuid:qword
        extrn '__imp_D3DKMTOfferAllocations' as D3DKMTOfferAllocations:qword
        extrn '__imp_D3DKMTOpenAdapterFromLuid' as D3DKMTOpenAdapterFromLuid:qword
        extrn '__imp_D3DKMTOpenKeyedMutex2' as D3DKMTOpenKeyedMutex2:qword
        extrn '__imp_D3DKMTOpenNtHandleFromName' as D3DKMTOpenNtHandleFromName:qword
        extrn '__imp_D3DKMTOpenResourceFromNtHandle' as D3DKMTOpenResourceFromNtHandle:qword
        extrn '__imp_D3DKMTOpenSyncObjectFromNtHandle' as D3DKMTOpenSyncObjectFromNtHandle:qword
        extrn '__imp_D3DKMTOutputDuplGetFrameInfo' as D3DKMTOutputDuplGetFrameInfo:qword
        extrn '__imp_D3DKMTOutputDuplGetMetaData' as D3DKMTOutputDuplGetMetaData:qword
        extrn '__imp_D3DKMTOutputDuplGetPointerShapeData' as D3DKMTOutputDuplGetPointerShapeData:qword
        extrn '__imp_D3DKMTOutputDuplPresent' as D3DKMTOutputDuplPresent:qword
        extrn '__imp_D3DKMTOutputDuplReleaseFrame' as D3DKMTOutputDuplReleaseFrame:qword
        extrn '__imp_D3DKMTPinDirectFlipResources' as D3DKMTPinDirectFlipResources:qword
        extrn '__imp_D3DKMTPresentMultiPlaneOverlay' as D3DKMTPresentMultiPlaneOverlay:qword
        extrn '__imp_D3DKMTQueryRemoteVidPnSourceFromGdiDisplayName' as D3DKMTQueryRemoteVidPnSourceFromGdiDisplayName:qword
        extrn '__imp_D3DKMTQueryResourceInfoFromNtHandle' as D3DKMTQueryResourceInfoFromNtHandle:qword
        extrn '__imp_D3DKMTReclaimAllocations' as D3DKMTReclaimAllocations:qword
        extrn '__imp_D3DKMTReleaseKeyedMutex2' as D3DKMTReleaseKeyedMutex2:qword
        extrn '__imp_D3DKMTSetContextInProcessSchedulingPriority' as D3DKMTSetContextInProcessSchedulingPriority:qword
        extrn '__imp_D3DKMTSetStereoEnabled' as D3DKMTSetStereoEnabled:qword
        extrn '__imp_D3DKMTSetVidPnSourceOwner1' as D3DKMTSetVidPnSourceOwner1:qword
        extrn '__imp_D3DKMTShareObjects' as D3DKMTShareObjects:qword
        extrn '__imp_D3DKMTUnpinDirectFlipResources' as D3DKMTUnpinDirectFlipResources:qword
        extrn '__imp_D3DKMTWaitForVerticalBlankEvent2' as D3DKMTWaitForVerticalBlankEvent2:qword
        extrn '__imp_GetCertificateSize' as GetCertificateSize:qword
        extrn '__imp_ScriptApplyDigitSubstitution' as ScriptApplyDigitSubstitution:qword
        extrn '__imp_ScriptApplyLogicalWidth' as ScriptApplyLogicalWidth:qword
        extrn '__imp_ScriptBreak' as ScriptBreak:qword
        extrn '__imp_ScriptCPtoX' as ScriptCPtoX:qword
        extrn '__imp_ScriptCacheGetHeight' as ScriptCacheGetHeight:qword
        extrn '__imp_ScriptFreeCache' as ScriptFreeCache:qword
        extrn '__imp_ScriptGetCMap' as ScriptGetCMap:qword
        extrn '__imp_ScriptGetFontAlternateGlyphs' as ScriptGetFontAlternateGlyphs:qword
        extrn '__imp_ScriptGetFontFeatureTags' as ScriptGetFontFeatureTags:qword
        extrn '__imp_ScriptGetFontLanguageTags' as ScriptGetFontLanguageTags:qword
        extrn '__imp_ScriptGetFontProperties' as ScriptGetFontProperties:qword
        extrn '__imp_ScriptGetFontScriptTags' as ScriptGetFontScriptTags:qword
        extrn '__imp_ScriptGetGlyphABCWidth' as ScriptGetGlyphABCWidth:qword
        extrn '__imp_ScriptGetLogicalWidths' as ScriptGetLogicalWidths:qword
        extrn '__imp_ScriptGetProperties' as ScriptGetProperties:qword
        extrn '__imp_ScriptIsComplex' as ScriptIsComplex:qword
        extrn '__imp_ScriptItemize' as ScriptItemize:qword
        extrn '__imp_ScriptItemizeOpenType' as ScriptItemizeOpenType:qword
        extrn '__imp_ScriptJustify' as ScriptJustify:qword
        extrn '__imp_ScriptLayout' as ScriptLayout:qword
        extrn '__imp_ScriptPlace' as ScriptPlace:qword
        extrn '__imp_ScriptPlaceOpenType' as ScriptPlaceOpenType:qword
        extrn '__imp_ScriptPositionSingleGlyph' as ScriptPositionSingleGlyph:qword
        extrn '__imp_ScriptRecordDigitSubstitution' as ScriptRecordDigitSubstitution:qword
        extrn '__imp_ScriptShape' as ScriptShape:qword
        extrn '__imp_ScriptShapeOpenType' as ScriptShapeOpenType:qword
        extrn '__imp_ScriptStringAnalyse' as ScriptStringAnalyse:qword
        extrn '__imp_ScriptStringCPtoX' as ScriptStringCPtoX:qword
        extrn '__imp_ScriptStringFree' as ScriptStringFree:qword
        extrn '__imp_ScriptStringGetLogicalWidths' as ScriptStringGetLogicalWidths:qword
        extrn '__imp_ScriptStringGetOrder' as ScriptStringGetOrder:qword
        extrn '__imp_ScriptStringOut' as ScriptStringOut:qword
        extrn '__imp_ScriptStringValidate' as ScriptStringValidate:qword
        extrn '__imp_ScriptStringXtoCP' as ScriptStringXtoCP:qword
        extrn '__imp_ScriptString_pLogAttr' as ScriptString_pLogAttr:qword
        extrn '__imp_ScriptString_pSize' as ScriptString_pSize:qword
        extrn '__imp_ScriptString_pcOutChars' as ScriptString_pcOutChars:qword
        extrn '__imp_ScriptSubstituteSingleGlyph' as ScriptSubstituteSingleGlyph:qword
        extrn '__imp_ScriptTextOut' as ScriptTextOut:qword
        extrn '__imp_ScriptXtoCP' as ScriptXtoCP:qword
    end if

    if (NTDDI_VERSION >= NTDDI_WIN81)
        extrn '__imp_D3DKMTCheckMultiPlaneOverlaySupport' as D3DKMTCheckMultiPlaneOverlaySupport:qword
        extrn '__imp_D3DKMTCheckMultiPlaneOverlaySupport2' as D3DKMTCheckMultiPlaneOverlaySupport2:qword
    end if

    if (NTDDI_VERSION >= NTDDI_WIN10)
        extrn '__imp_D3DKMTCreateContextVirtual' as D3DKMTCreateContextVirtual:qword
        extrn '__imp_D3DKMTCreatePagingQueue' as D3DKMTCreatePagingQueue:qword
        extrn '__imp_D3DKMTDestroyAllocation2' as D3DKMTDestroyAllocation2:qword
        extrn '__imp_D3DKMTDestroyPagingQueue' as D3DKMTDestroyPagingQueue:qword
        extrn '__imp_D3DKMTEvict' as D3DKMTEvict:qword
        extrn '__imp_D3DKMTFreeGpuVirtualAddress' as D3DKMTFreeGpuVirtualAddress:qword
        extrn '__imp_D3DKMTLock2' as D3DKMTLock2:qword
        extrn '__imp_D3DKMTMakeResident' as D3DKMTMakeResident:qword
        extrn '__imp_D3DKMTMapGpuVirtualAddress' as D3DKMTMapGpuVirtualAddress:qword
        extrn '__imp_D3DKMTOpenSyncObjectFromNtHandle2' as D3DKMTOpenSyncObjectFromNtHandle2:qword
        extrn '__imp_D3DKMTOpenSyncObjectNtHandleFromName' as D3DKMTOpenSyncObjectNtHandleFromName:qword
        extrn '__imp_D3DKMTReclaimAllocations2' as D3DKMTReclaimAllocations2:qword
        extrn '__imp_D3DKMTRegisterTrimNotification' as D3DKMTRegisterTrimNotification:qword
        extrn '__imp_D3DKMTReserveGpuVirtualAddress' as D3DKMTReserveGpuVirtualAddress:qword
        extrn '__imp_D3DKMTSignalSynchronizationObjectFromCpu' as D3DKMTSignalSynchronizationObjectFromCpu:qword
        extrn '__imp_D3DKMTSignalSynchronizationObjectFromGpu' as D3DKMTSignalSynchronizationObjectFromGpu:qword
        extrn '__imp_D3DKMTSignalSynchronizationObjectFromGpu2' as D3DKMTSignalSynchronizationObjectFromGpu2:qword
        extrn '__imp_D3DKMTSubmitCommand' as D3DKMTSubmitCommand:qword
        extrn '__imp_D3DKMTUnlock2' as D3DKMTUnlock2:qword
        extrn '__imp_D3DKMTUnregisterTrimNotification' as D3DKMTUnregisterTrimNotification:qword
        extrn '__imp_D3DKMTUpdateGpuVirtualAddress' as D3DKMTUpdateGpuVirtualAddress:qword
        extrn '__imp_D3DKMTWaitForSynchronizationObjectFromCpu' as D3DKMTWaitForSynchronizationObjectFromCpu:qword
        extrn '__imp_D3DKMTWaitForSynchronizationObjectFromGpu' as D3DKMTWaitForSynchronizationObjectFromGpu:qword
    end if

    api AddFontResource,\
        CopyEnhMetaFile,\
        CopyMetaFile,\
        CreateColorSpace,\
        CreateDC,\
        CreateEnhMetaFile,\
        CreateFont,\
        CreateFontIndirect,\
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
        GetCharWidth,\
        GetCharWidth32,\
        GetCharWidthFloat,\
        GetCharacterPlacement,\
        GetEnhMetaFile,\
        GetEnhMetaFileDescription,\
        GetGlyphOutline,\
        GetICMProfile,\
        GetKerningPairs,\
        GetLogColorSpace,\
        GetMetaFile,\
        GetObject,\
        GetOutlineTextMetrics,\
        GetTextExtentExPoint,\
        GetTextExtentPoint32,\
        GetTextExtentPoint,\
        GetTextFace,\
        GetTextMetrics,\
        PolyTextOut,\
        RemoveFontResource,\
        ResetDC,\
        SetICMProfile,\
        StartDoc,\
        TextOut,\
        UpdateICMRegKey
else
    extrn '__imp__AbortDoc@4' as AbortDoc:dword
    extrn '__imp__AbortPath@4' as AbortPath:dword
    extrn '__imp__AddFontResourceA@4' as AddFontResourceA:dword
    extrn '__imp__AddFontResourceW@4' as AddFontResourceW:dword
    extrn '__imp__AnimatePalette@16' as AnimatePalette:dword
    extrn '__imp__AngleArc@24' as AngleArc:dword
    extrn '__imp__Arc@36' as Arc:dword
    extrn '__imp__ArcTo@36' as ArcTo:dword
    extrn '__imp__BeginPath@4' as BeginPath:dword
    extrn '__imp__BitBlt@36' as BitBlt:dword
    extrn '__imp__CancelDC@4' as CancelDC:dword
    extrn '__imp__CheckColorsInGamut@16' as CheckColorsInGamut:dword
    extrn '__imp__ChoosePixelFormat@8' as ChoosePixelFormat:dword
    extrn '__imp__Chord@36' as Chord:dword
    extrn '__imp__CloseEnhMetaFile@4' as CloseEnhMetaFile:dword
    extrn '__imp__CloseFigure@4' as CloseFigure:dword
    extrn '__imp__CloseMetaFile@4' as CloseMetaFile:dword
    extrn '__imp__ColorMatchToTarget@12' as ColorMatchToTarget:dword
    extrn '__imp__CombineRgn@16' as CombineRgn:dword
    extrn '__imp__CombineTransform@12' as CombineTransform:dword
    extrn '__imp__CopyEnhMetaFileA@8' as CopyEnhMetaFileA:dword
    extrn '__imp__CopyEnhMetaFileW@8' as CopyEnhMetaFileW:dword
    extrn '__imp__CopyMetaFileA@8' as CopyMetaFileA:dword
    extrn '__imp__CopyMetaFileW@8' as CopyMetaFileW:dword
    extrn '__imp__CreateBitmap@20' as CreateBitmap:dword
    extrn '__imp__CreateBitmapIndirect@4' as CreateBitmapIndirect:dword
    extrn '__imp__CreateBrushIndirect@4' as CreateBrushIndirect:dword
    extrn '__imp__CreateColorSpaceA@4' as CreateColorSpaceA:dword
    extrn '__imp__CreateColorSpaceW@4' as CreateColorSpaceW:dword
    extrn '__imp__CreateCompatibleBitmap@12' as CreateCompatibleBitmap:dword
    extrn '__imp__CreateCompatibleDC@4' as CreateCompatibleDC:dword
    extrn '__imp__CreateDCA@16' as CreateDCA:dword
    extrn '__imp__CreateDCW@16' as CreateDCW:dword
    extrn '__imp__CreateDIBitmap@24' as CreateDIBitmap:dword
    extrn '__imp__CreateDIBPatternBrush@8' as CreateDIBPatternBrush:dword
    extrn '__imp__CreateDIBPatternBrushPt@8' as CreateDIBPatternBrushPt:dword
    extrn '__imp__CreateDIBSection@24' as CreateDIBSection:dword
    extrn '__imp__CreateDiscardableBitmap@12' as CreateDiscardableBitmap:dword
    extrn '__imp__CreateEllipticRgn@16' as CreateEllipticRgn:dword
    extrn '__imp__CreateEllipticRgnIndirect@4' as CreateEllipticRgnIndirect:dword
    extrn '__imp__CreateEnhMetaFileA@16' as CreateEnhMetaFileA:dword
    extrn '__imp__CreateEnhMetaFileW@16' as CreateEnhMetaFileW:dword
    extrn '__imp__CreateFontA@56' as CreateFontA:dword
    extrn '__imp__CreateFontIndirectA@4' as CreateFontIndirectA:dword
    extrn '__imp__CreateFontIndirectW@4' as CreateFontIndirectW:dword
    extrn '__imp__CreateFontW@56' as CreateFontW:dword
    extrn '__imp__CreateHalftonePalette@4' as CreateHalftonePalette:dword
    extrn '__imp__CreateHatchBrush@8' as CreateHatchBrush:dword
    extrn '__imp__CreateICA@16' as CreateICA:dword
    extrn '__imp__CreateICW@16' as CreateICW:dword
    extrn '__imp__CreateMetaFileA@4' as CreateMetaFileA:dword
    extrn '__imp__CreateMetaFileW@4' as CreateMetaFileW:dword
    extrn '__imp__CreatePalette@4' as CreatePalette:dword
    extrn '__imp__CreatePatternBrush@4' as CreatePatternBrush:dword
    extrn '__imp__CreatePen@12' as CreatePen:dword
    extrn '__imp__CreatePenIndirect@4' as CreatePenIndirect:dword
    extrn '__imp__CreatePolyPolygonRgn@16' as CreatePolyPolygonRgn:dword
    extrn '__imp__CreatePolygonRgn@12' as CreatePolygonRgn:dword
    extrn '__imp__CreateRectRgn@16' as CreateRectRgn:dword
    extrn '__imp__CreateRectRgnIndirect@4' as CreateRectRgnIndirect:dword
    extrn '__imp__CreateRoundRectRgn@24' as CreateRoundRectRgn:dword
    extrn '__imp__CreateScalableFontResourceA@16' as CreateScalableFontResourceA:dword
    extrn '__imp__CreateScalableFontResourceW@16' as CreateScalableFontResourceW:dword
    extrn '__imp__CreateSolidBrush@4' as CreateSolidBrush:dword
    extrn '__imp__DeleteColorSpace@4' as DeleteColorSpace:dword
    extrn '__imp__DeleteDC@4' as DeleteDC:dword
    extrn '__imp__DeleteEnhMetaFile@4' as DeleteEnhMetaFile:dword
    extrn '__imp__DeleteMetaFile@4' as DeleteMetaFile:dword
    extrn '__imp__DeleteObject@4' as DeleteObject:dword
    extrn '__imp__DescribePixelFormat@16' as DescribePixelFormat:dword
    extrn '__imp__DeviceCapabilitiesExA@24' as DeviceCapabilitiesExA:dword
    extrn '__imp__DeviceCapabilitiesExW@24' as DeviceCapabilitiesExW:dword
    extrn '__imp__DPtoLP@12' as DPtoLP:dword
    extrn '__imp__DrawEscape@16' as DrawEscape:dword
    extrn '__imp__Ellipse@20' as Ellipse:dword
    extrn '__imp__EndDoc@4' as EndDoc:dword
    extrn '__imp__EndPage@4' as EndPage:dword
    extrn '__imp__EndPath@4' as EndPath:dword
    extrn '__imp__EnumEnhMetaFile@20' as EnumEnhMetaFile:dword
    extrn '__imp__EnumFontFamiliesA@16' as EnumFontFamiliesA:dword
    extrn '__imp__EnumFontFamiliesExA@20' as EnumFontFamiliesExA:dword
    extrn '__imp__EnumFontFamiliesExW@20' as EnumFontFamiliesExW:dword
    extrn '__imp__EnumFontFamiliesW@16' as EnumFontFamiliesW:dword
    extrn '__imp__EnumFontsA@16' as EnumFontsA:dword
    extrn '__imp__EnumFontsW@16' as EnumFontsW:dword
    extrn '__imp__EnumICMProfilesA@12' as EnumICMProfilesA:dword
    extrn '__imp__EnumICMProfilesW@12' as EnumICMProfilesW:dword
    extrn '__imp__EnumMetaFile@16' as EnumMetaFile:dword
    extrn '__imp__EnumObjects@16' as EnumObjects:dword
    extrn '__imp__EqualRgn@8' as EqualRgn:dword
    extrn '__imp__Escape@20' as Escape:dword
    extrn '__imp__ExcludeClipRect@20' as ExcludeClipRect:dword
    extrn '__imp__ExtCreatePen@20' as ExtCreatePen:dword
    extrn '__imp__ExtCreateRegion@12' as ExtCreateRegion:dword
    extrn '__imp__ExtEscape@24' as ExtEscape:dword
    extrn '__imp__ExtFloodFill@20' as ExtFloodFill:dword
    extrn '__imp__ExtSelectClipRgn@12' as ExtSelectClipRgn:dword
    extrn '__imp__ExtTextOutA@32' as ExtTextOutA:dword
    extrn '__imp__ExtTextOutW@32' as ExtTextOutW:dword
    extrn '__imp__FillPath@4' as FillPath:dword
    extrn '__imp__FillRgn@12' as FillRgn:dword
    extrn '__imp__FixBrushOrgEx@16' as FixBrushOrgEx:dword
    extrn '__imp__FlattenPath@4' as FlattenPath:dword
    extrn '__imp__FloodFill@16' as FloodFill:dword
    extrn '__imp__FrameRgn@20' as FrameRgn:dword
    extrn '__imp__GdiComment@12' as GdiComment:dword
    extrn '__imp__GdiFlush@0' as GdiFlush:dword
    extrn '__imp__GdiGetBatchLimit@0' as GdiGetBatchLimit:dword
    extrn '__imp__GdiPlayDCScript@24' as GdiPlayDCScript:dword
    extrn '__imp__GdiPlayJournal@20' as GdiPlayJournal:dword
    extrn '__imp__GdiPlayScript@28' as GdiPlayScript:dword
    extrn '__imp__gdiPlaySpoolStream@24' as gdiPlaySpoolStream:dword
    extrn '__imp__GdiSetBatchLimit@4' as GdiSetBatchLimit:dword
    extrn '__imp__GetArcDirection@4' as GetArcDirection:dword
    extrn '__imp__GetAspectRatioFilterEx@8' as GetAspectRatioFilterEx:dword
    extrn '__imp__GetBitmapBits@12' as GetBitmapBits:dword
    extrn '__imp__GetBitmapDimensionEx@8' as GetBitmapDimensionEx:dword
    extrn '__imp__GetBkColor@4' as GetBkColor:dword
    extrn '__imp__GetBkMode@4' as GetBkMode:dword
    extrn '__imp__GetBoundsRect@12' as GetBoundsRect:dword
    extrn '__imp__GetBrushOrgEx@8' as GetBrushOrgEx:dword
    extrn '__imp__GetCharABCWidthsA@16' as GetCharABCWidthsA:dword
    extrn '__imp__GetCharABCWidthsW@16' as GetCharABCWidthsW:dword
    extrn '__imp__GetCharABCWidthsFloatA@16' as GetCharABCWidthsFloatA:dword
    extrn '__imp__GetCharABCWidthsFloatW@16' as GetCharABCWidthsFloatW:dword
    extrn '__imp__GetCharWidth32A@16' as GetCharWidth32A:dword
    extrn '__imp__GetCharWidth32W@16' as GetCharWidth32W:dword
    extrn '__imp__GetCharWidthA@16' as GetCharWidthA:dword
    extrn '__imp__GetCharWidthW@16' as GetCharWidthW:dword
    extrn '__imp__GetCharWidthFloatA@16' as GetCharWidthFloatA:dword
    extrn '__imp__GetCharWidthFloatW@16' as GetCharWidthFloatW:dword
    extrn '__imp__GetCharacterPlacementA@24' as GetCharacterPlacementA:dword
    extrn '__imp__GetCharacterPlacementW@24' as GetCharacterPlacementW:dword
    extrn '__imp__GetClipBox@8' as GetClipBox:dword
    extrn '__imp__GetClipRgn@8' as GetClipRgn:dword
    extrn '__imp__GetColorAdjustment@8' as GetColorAdjustment:dword
    extrn '__imp__GetColorSpace@4' as GetColorSpace:dword
    extrn '__imp__GetCurrentObject@8' as GetCurrentObject:dword
    extrn '__imp__GetCurrentPositionEx@8' as GetCurrentPositionEx:dword
    extrn '__imp__GetDCOrgEx@8' as GetDCOrgEx:dword
    extrn '__imp__GetDeviceCaps@8' as GetDeviceCaps:dword
    extrn '__imp__GetDeviceGammaRamp@8' as GetDeviceGammaRamp:dword
    extrn '__imp__GetDIBColorTable@16' as GetDIBColorTable:dword
    extrn '__imp__GetDIBits@28' as GetDIBits:dword
    extrn '__imp__GetEnhMetaFileA@4' as GetEnhMetaFileA:dword
    extrn '__imp__GetEnhMetaFileBits@12' as GetEnhMetaFileBits:dword
    extrn '__imp__GetEnhMetaFileDescriptionA@12' as GetEnhMetaFileDescriptionA:dword
    extrn '__imp__GetEnhMetaFileDescriptionW@12' as GetEnhMetaFileDescriptionW:dword
    extrn '__imp__GetEnhMetaFileHeader@12' as GetEnhMetaFileHeader:dword
    extrn '__imp__GetEnhMetaFilePaletteEntries@12' as GetEnhMetaFilePaletteEntries:dword
    extrn '__imp__GetEnhMetaFileW@4' as GetEnhMetaFileW:dword
    extrn '__imp__GetFontData@20' as GetFontData:dword
    extrn '__imp__GetFontLanguageInfo@4' as GetFontLanguageInfo:dword
    extrn '__imp__GetGlyphOutlineA@28' as GetGlyphOutlineA:dword
    extrn '__imp__GetGlyphOutlineW@28' as GetGlyphOutlineW:dword
    extrn '__imp__GetGraphicsMode@4' as GetGraphicsMode:dword
    extrn '__imp__GetICMProfileA@12' as GetICMProfileA:dword
    extrn '__imp__GetICMProfileW@12' as GetICMProfileW:dword
    extrn '__imp__GetKerningPairsA@12' as GetKerningPairsA:dword
    extrn '__imp__GetKerningPairsW@12' as GetKerningPairsW:dword
    extrn '__imp__GetLogColorSpaceA@12' as GetLogColorSpaceA:dword
    extrn '__imp__GetLogColorSpaceW@12' as GetLogColorSpaceW:dword
    extrn '__imp__GetMapMode@4' as GetMapMode:dword
    extrn '__imp__GetMetaFileA@4' as GetMetaFileA:dword
    extrn '__imp__GetMetaFileBitsEx@12' as GetMetaFileBitsEx:dword
    extrn '__imp__GetMetaFileW@4' as GetMetaFileW:dword
    extrn '__imp__GetMetaRgn@8' as GetMetaRgn:dword
    extrn '__imp__GetMiterLimit@8' as GetMiterLimit:dword
    extrn '__imp__GetNearestColor@8' as GetNearestColor:dword
    extrn '__imp__GetNearestPaletteIndex@8' as GetNearestPaletteIndex:dword
    extrn '__imp__GetObjectA@12' as GetObjectA:dword
    extrn '__imp__GetObjectType@4' as GetObjectType:dword
    extrn '__imp__GetObjectW@12' as GetObjectW:dword
    extrn '__imp__GetOutlineTextMetricsA@12' as GetOutlineTextMetricsA:dword
    extrn '__imp__GetOutlineTextMetricsW@12' as GetOutlineTextMetricsW:dword
    extrn '__imp__GetPaletteEntries@16' as GetPaletteEntries:dword
    extrn '__imp__GetPath@16' as GetPath:dword
    extrn '__imp__GetPixel@12' as GetPixel:dword
    extrn '__imp__GetPixelFormat@4' as GetPixelFormat:dword
    extrn '__imp__GetPolyFillMode@4' as GetPolyFillMode:dword
    extrn '__imp__GetROP2@4' as GetROP2:dword
    extrn '__imp__GetRandomRgn@12' as GetRandomRgn:dword
    extrn '__imp__GetRasterizerCaps@8' as GetRasterizerCaps:dword
    extrn '__imp__GetRegionData@12' as GetRegionData:dword
    extrn '__imp__GetRgnBox@8' as GetRgnBox:dword
    extrn '__imp__GetStockObject@4' as GetStockObject:dword
    extrn '__imp__GetStretchBltMode@4' as GetStretchBltMode:dword
    extrn '__imp__GetSystemPaletteEntries@16' as GetSystemPaletteEntries:dword
    extrn '__imp__GetSystemPaletteUse@4' as GetSystemPaletteUse:dword
    extrn '__imp__GetTextAlign@4' as GetTextAlign:dword
    extrn '__imp__GetTextCharacterExtra@4' as GetTextCharacterExtra:dword
    extrn '__imp__GetTextCharset@4' as GetTextCharset:dword
    extrn '__imp__GetTextCharsetInfo@12' as GetTextCharsetInfo:dword
    extrn '__imp__GetTextColor@4' as GetTextColor:dword
    extrn '__imp__GetTextExtentExPointA@28' as GetTextExtentExPointA:dword
    extrn '__imp__GetTextExtentExPointW@28' as GetTextExtentExPointW:dword
    extrn '__imp__GetTextExtentPoint32A@16' as GetTextExtentPoint32A:dword
    extrn '__imp__GetTextExtentPoint32W@16' as GetTextExtentPoint32W:dword
    extrn '__imp__GetTextExtentPointA@16' as GetTextExtentPointA:dword
    extrn '__imp__GetTextExtentPointW@16' as GetTextExtentPointW:dword
    extrn '__imp__GetTextFaceA@12' as GetTextFaceA:dword
    extrn '__imp__GetTextFaceW@12' as GetTextFaceW:dword
    extrn '__imp__GetTextMetricsA@8' as GetTextMetricsA:dword
    extrn '__imp__GetTextMetricsW@8' as GetTextMetricsW:dword
    extrn '__imp__GetViewportExtEx@8' as GetViewportExtEx:dword
    extrn '__imp__GetViewportOrgEx@8' as GetViewportOrgEx:dword
    extrn '__imp__GetWinMetaFileBits@20' as GetWinMetaFileBits:dword
    extrn '__imp__GetWindowExtEx@8' as GetWindowExtEx:dword
    extrn '__imp__GetWindowOrgEx@8' as GetWindowOrgEx:dword
    extrn '__imp__GetWorldTransform@8' as GetWorldTransform:dword
    extrn '__imp__IntersectClipRect@20' as IntersectClipRect:dword
    extrn '__imp__InvertRgn@8' as InvertRgn:dword
    extrn '__imp__LineDDA@24' as LineDDA:dword
    extrn '__imp__LineTo@12' as LineTo:dword
    extrn '__imp__LPtoDP@12' as LPtoDP:dword
    extrn '__imp__MaskBlt@48' as MaskBlt:dword
    extrn '__imp__ModifyWorldTransform@12' as ModifyWorldTransform:dword
    extrn '__imp__MoveToEx@16' as MoveToEx:dword
    extrn '__imp__OffsetClipRgn@12' as OffsetClipRgn:dword
    extrn '__imp__OffsetRgn@12' as OffsetRgn:dword
    extrn '__imp__OffsetViewportOrgEx@16' as OffsetViewportOrgEx:dword
    extrn '__imp__OffsetWindowOrgEx@16' as OffsetWindowOrgEx:dword
    extrn '__imp__PaintRgn@8' as PaintRgn:dword
    extrn '__imp__PatBlt@24' as PatBlt:dword
    extrn '__imp__PathToRegion@4' as PathToRegion:dword
    extrn '__imp__Pie@36' as Pie:dword
    extrn '__imp__PlayEnhMetaFile@12' as PlayEnhMetaFile:dword
    extrn '__imp__PlayEnhMetaFileRecord@16' as PlayEnhMetaFileRecord:dword
    extrn '__imp__PlayMetaFile@8' as PlayMetaFile:dword
    extrn '__imp__PlayMetaFileRecord@16' as PlayMetaFileRecord:dword
    extrn '__imp__PlgBlt@40' as PlgBlt:dword
    extrn '__imp__PolyBezier@12' as PolyBezier:dword
    extrn '__imp__PolyBezierTo@12' as PolyBezierTo:dword
    extrn '__imp__PolyDraw@16' as PolyDraw:dword
    extrn '__imp__Polygon@12' as Polygon:dword
    extrn '__imp__Polyline@12' as Polyline:dword
    extrn '__imp__PolylineTo@12' as PolylineTo:dword
    extrn '__imp__PolyPolygon@16' as PolyPolygon:dword
    extrn '__imp__PolyPolyline@16' as PolyPolyline:dword
    extrn '__imp__PolyTextOutA@12' as PolyTextOutA:dword
    extrn '__imp__PolyTextOutW@12' as PolyTextOutW:dword
    extrn '__imp__PtInRegion@12' as PtInRegion:dword
    extrn '__imp__PtVisible@12' as PtVisible:dword
    extrn '__imp__RealizePalette@4' as RealizePalette:dword
    extrn '__imp__Rectangle@20' as Rectangle:dword
    extrn '__imp__RectInRegion@8' as RectInRegion:dword
    extrn '__imp__RectVisible@8' as RectVisible:dword
    extrn '__imp__RemoveFontResourceA@4' as RemoveFontResourceA:dword
    extrn '__imp__RemoveFontResourceW@4' as RemoveFontResourceW:dword
    extrn '__imp__ResetDCA@8' as ResetDCA:dword
    extrn '__imp__ResetDCW@8' as ResetDCW:dword
    extrn '__imp__ResizePalette@8' as ResizePalette:dword
    extrn '__imp__RestoreDC@8' as RestoreDC:dword
    extrn '__imp__RoundRect@28' as RoundRect:dword
    extrn '__imp__SaveDC@4' as SaveDC:dword
    extrn '__imp__ScaleViewportExtEx@24' as ScaleViewportExtEx:dword
    extrn '__imp__ScaleWindowExtEx@24' as ScaleWindowExtEx:dword
    extrn '__imp__SelectClipPath@8' as SelectClipPath:dword
    extrn '__imp__SelectClipRgn@8' as SelectClipRgn:dword
    extrn '__imp__SelectObject@8' as SelectObject:dword
    extrn '__imp__SelectPalette@12' as SelectPalette:dword
    extrn '__imp__SetAbortProc@8' as SetAbortProc:dword
    extrn '__imp__SetArcDirection@8' as SetArcDirection:dword
    extrn '__imp__SetBitmapBits@12' as SetBitmapBits:dword
    extrn '__imp__SetBitmapDimensionEx@16' as SetBitmapDimensionEx:dword
    extrn '__imp__SetBkColor@8' as SetBkColor:dword
    extrn '__imp__SetBkMode@8' as SetBkMode:dword
    extrn '__imp__SetBoundsRect@12' as SetBoundsRect:dword
    extrn '__imp__SetBrushOrgEx@16' as SetBrushOrgEx:dword
    extrn '__imp__SetColorAdjustment@8' as SetColorAdjustment:dword
    extrn '__imp__SetColorSpace@8' as SetColorSpace:dword
    extrn '__imp__SetDeviceGammaRamp@8' as SetDeviceGammaRamp:dword
    extrn '__imp__SetDIBColorTable@16' as SetDIBColorTable:dword
    extrn '__imp__SetDIBits@28' as SetDIBits:dword
    extrn '__imp__SetDIBitsToDevice@48' as SetDIBitsToDevice:dword
    extrn '__imp__SetEnhMetaFileBits@8' as SetEnhMetaFileBits:dword
    extrn '__imp__SetFontEnumeration@4' as SetFontEnumeration:dword
    extrn '__imp__SetGraphicsMode@8' as SetGraphicsMode:dword
    extrn '__imp__SetICMMode@8' as SetICMMode:dword
    extrn '__imp__SetICMProfileA@8' as SetICMProfileA:dword
    extrn '__imp__SetICMProfileW@8' as SetICMProfileW:dword
    extrn '__imp__SetMapMode@8' as SetMapMode:dword
    extrn '__imp__SetMapperFlags@8' as SetMapperFlags:dword
    extrn '__imp__SetMetaFileBitsEx@8' as SetMetaFileBitsEx:dword
    extrn '__imp__SetMetaRgn@4' as SetMetaRgn:dword
    extrn '__imp__SetMiterLimit@12' as SetMiterLimit:dword
    extrn '__imp__SetPaletteEntries@16' as SetPaletteEntries:dword
    extrn '__imp__SetPixel@16' as SetPixel:dword
    extrn '__imp__SetPixelFormat@12' as SetPixelFormat:dword
    extrn '__imp__SetPixelV@16' as SetPixelV:dword
    extrn '__imp__SetPolyFillMode@8' as SetPolyFillMode:dword
    extrn '__imp__SetROP2@8' as SetROP2:dword
    extrn '__imp__SetRectRgn@20' as SetRectRgn:dword
    extrn '__imp__SetStretchBltMode@8' as SetStretchBltMode:dword
    extrn '__imp__SetSystemPaletteUse@8' as SetSystemPaletteUse:dword
    extrn '__imp__SetTextAlign@8' as SetTextAlign:dword
    extrn '__imp__SetTextCharacterExtra@8' as SetTextCharacterExtra:dword
    extrn '__imp__SetTextColor@8' as SetTextColor:dword
    extrn '__imp__SetTextJustification@12' as SetTextJustification:dword
    extrn '__imp__SetViewportExtEx@16' as SetViewportExtEx:dword
    extrn '__imp__SetViewportOrgEx@16' as SetViewportOrgEx:dword
    extrn '__imp__SetWindowExtEx@16' as SetWindowExtEx:dword
    extrn '__imp__SetWindowOrgEx@16' as SetWindowOrgEx:dword
    extrn '__imp__SetWinMetaFileBits@16' as SetWinMetaFileBits:dword
    extrn '__imp__SetWorldTransform@8' as SetWorldTransform:dword
    extrn '__imp__StartDocA@8' as StartDocA:dword
    extrn '__imp__StartDocW@8' as StartDocW:dword
    extrn '__imp__StartPage@4' as StartPage:dword
    extrn '__imp__StretchBlt@44' as StretchBlt:dword
    extrn '__imp__StretchDIBits@52' as StretchDIBits:dword
    extrn '__imp__StrokeAndFillPath@4' as StrokeAndFillPath:dword
    extrn '__imp__StrokePath@4' as StrokePath:dword
    extrn '__imp__SwapBuffers@4' as SwapBuffers:dword
    extrn '__imp__TextOutA@20' as TextOutA:dword
    extrn '__imp__TextOutW@20' as TextOutW:dword
    extrn '__imp__TranslateCharsetInfo@12' as TranslateCharsetInfo:dword
    extrn '__imp__UnrealizeObject@4' as UnrealizeObject:dword
    extrn '__imp__UpdateColors@4' as UpdateColors:dword
    extrn '__imp__UpdateICMRegKeyA@16' as UpdateICMRegKeyA:dword
    extrn '__imp__UpdateICMRegKeyW@16' as UpdateICMRegKeyW:dword
    extrn '__imp__WidenPath@4' as WidenPath:dword

    if (NTDDI_VERSION >= NTDDI_WIN98_ME)
        extrn '__imp__ColorCorrectPalette@16' as ColorCorrectPalette:dword
        extrn '__imp__EnableEUDC@4' as EnableEUDC:dword
        extrn '__imp__GetLayout@4' as GetLayout:dword
        if (NTDDI_VERSION <> NTDDI_WINNT4)
            extrn '__imp__SetLayout@8' as SetLayout:dword
        end if
    end if

    if (NTDDI_VERSION >= NTDDI_WINNT4)
        extrn '__imp__GdiAddFontResourceW@12' as GdiAddFontResourceW:dword
        extrn '__imp__GdiAddGlsBounds@8' as GdiAddGlsBounds:dword
        extrn '__imp__GdiCleanCacheDC@4' as GdiCleanCacheDC:dword
        extrn '__imp__GdiConsoleTextOut@16' as GdiConsoleTextOut:dword
        extrn '__imp__GdiConvertAndCheckDC@4' as GdiConvertAndCheckDC:dword
        extrn '__imp__GdiConvertBitmap@4' as GdiConvertBitmap:dword
        extrn '__imp__GdiConvertBrush@4' as GdiConvertBrush:dword
        extrn '__imp__GdiConvertDC@4' as GdiConvertDC:dword
        extrn '__imp__GdiConvertEnhMetaFile@4' as GdiConvertEnhMetaFile:dword
        extrn '__imp__GdiConvertFont@4' as GdiConvertFont:dword
        extrn '__imp__GdiConvertPalette@4' as GdiConvertPalette:dword
        extrn '__imp__GdiConvertRegion@4' as GdiConvertRegion:dword
        extrn '__imp__GdiDeleteLocalDC@0' as GdiDeleteLocalDC:dword
        extrn '__imp__GdiDescribePixelFormat@16' as GdiDescribePixelFormat:dword
        extrn '__imp__GdiDllInitialize@12' as GdiDllInitialize:dword
        extrn '__imp__GdiFixUpHandle@4' as GdiFixUpHandle:dword
        extrn '__imp__GdiGetCharDimensions@12' as GdiGetCharDimensions:dword
        extrn '__imp__GdiGetCodePage@4' as GdiGetCodePage:dword
        extrn '__imp__GdiGetLocalBrush@4' as GdiGetLocalBrush:dword
        extrn '__imp__GdiGetLocalDC@4' as GdiGetLocalDC:dword
        extrn '__imp__GdiGetLocalFont@4' as GdiGetLocalFont:dword
        extrn '__imp__GdiGetSpoolMessage@16' as GdiGetSpoolMessage:dword
        extrn '__imp__GdiInitSpool@0' as GdiInitSpool:dword
        extrn '__imp__GdiIsMetaFileDC@4' as GdiIsMetaFileDC:dword
        extrn '__imp__GdiIsMetaPrintDC@4' as GdiIsMetaPrintDC:dword
        extrn '__imp__GdiProcessSetup@0' as GdiProcessSetup:dword
        extrn '__imp__GdiQueryFonts@12' as GdiQueryFonts:dword
        extrn '__imp__GdiQueryTable@0' as GdiQueryTable:dword
        extrn '__imp__GdiReleaseLocalDC@4' as GdiReleaseLocalDC:dword
        extrn '__imp__GdiSetAttrs@4' as GdiSetAttrs:dword
        extrn '__imp__GdiSetPixelFormat@12' as GdiSetPixelFormat:dword
        extrn '__imp__GdiSetServerAttr@8' as GdiSetServerAttr:dword
        extrn '__imp__GdiValidateHandle@4' as GdiValidateHandle:dword
        extrn '__imp__GetCharWidthInfo@8' as GetCharWidthInfo:dword
        extrn '__imp__GetETM@8' as GetETM:dword
        extrn '__imp__GetEnhMetaFilePixelFormat@12' as GetEnhMetaFilePixelFormat:dword
        extrn '__imp__GetFontResourceInfoW@16' as GetFontResourceInfoW:dword
        extrn '__imp__GetGlyphOutlineWow@28' as GetGlyphOutlineWow:dword
        extrn '__imp__GetHFONT@4' as GetHFONT:dword
        extrn '__imp__HT_Get8BPPFormatPalette@16' as HT_Get8BPPFormatPalette:dword
        extrn '__imp__HT_Get8BPPMaskPalette@24' as HT_Get8BPPMaskPalette:dword
        extrn '__imp__IsValidEnhMetaRecord@8' as IsValidEnhMetaRecord:dword
        extrn '__imp__IsValidEnhMetaRecordOffExt@16' as IsValidEnhMetaRecordOffExt:dword
        extrn '__imp__PolyPatBlt@20' as PolyPatBlt:dword
        extrn '__imp__SelectBrushLocal@8' as SelectBrushLocal:dword
        extrn '__imp__SelectFontLocal@8' as SelectFontLocal:dword
        extrn '__imp__SetMagicColors@12' as SetMagicColors:dword
        GetFontResourceInfo equ GetFontResourceInfoW
    end if

    if (NTDDI_VERSION >= NTDDI_WIN2K)
        extrn '__imp__AddFontMemResourceEx@16' as AddFontMemResourceEx:dword
        extrn '__imp__AddFontResourceExA@12' as AddFontResourceExA:dword
        extrn '__imp__AddFontResourceExW@12' as AddFontResourceExW:dword
        extrn '__imp__BRUSHOBJ_hGetColorTransform@4' as BRUSHOBJ_hGetColorTransform:dword
        extrn '__imp__BRUSHOBJ_pvAllocRbrush@8' as BRUSHOBJ_pvAllocRbrush:dword
        extrn '__imp__BRUSHOBJ_pvGetRbrush@4' as BRUSHOBJ_pvGetRbrush:dword
        extrn '__imp__BRUSHOBJ_ulGetBrushColor@4' as BRUSHOBJ_ulGetBrushColor:dword
        extrn '__imp__CLIPOBJ_bEnum@12' as CLIPOBJ_bEnum:dword
        extrn '__imp__CLIPOBJ_cEnumStart@20' as CLIPOBJ_cEnumStart:dword
        extrn '__imp__CLIPOBJ_ppoGetPath@4' as CLIPOBJ_ppoGetPath:dword
        extrn '__imp__CreateFontIndirectExA@4' as CreateFontIndirectExA:dword
        extrn '__imp__CreateFontIndirectExW@4' as CreateFontIndirectExW:dword
        extrn '__imp__EngAcquireSemaphore@4' as EngAcquireSemaphore:dword
        extrn '__imp__EngAlphaBlend@28' as EngAlphaBlend:dword
        extrn '__imp__EngAssociateSurface@12' as EngAssociateSurface:dword
        extrn '__imp__EngBitBlt@44' as EngBitBlt:dword
        extrn '__imp__EngCheckAbort@4' as EngCheckAbort:dword
        extrn '__imp__EngComputeGlyphSet@12' as EngComputeGlyphSet:dword
        extrn '__imp__EngCopyBits@24' as EngCopyBits:dword
        extrn '__imp__EngCreateBitmap@20' as EngCreateBitmap:dword
        extrn '__imp__EngCreateClip@0' as EngCreateClip:dword
        extrn '__imp__EngCreateDeviceBitmap@12' as EngCreateDeviceBitmap:dword
        extrn '__imp__EngCreateDeviceSurface@8' as EngCreateDeviceSurface:dword
        extrn '__imp__EngCreatePalette@24' as EngCreatePalette:dword
        extrn '__imp__EngCreateSemaphore@0' as EngCreateSemaphore:dword
        extrn '__imp__EngDeleteClip@4' as EngDeleteClip:dword
        extrn '__imp__EngDeletePalette@4' as EngDeletePalette:dword
        extrn '__imp__EngDeletePath@4' as EngDeletePath:dword
        extrn '__imp__EngDeleteSemaphore@4' as EngDeleteSemaphore:dword
        extrn '__imp__EngDeleteSurface@4' as EngDeleteSurface:dword
        extrn '__imp__EngEraseSurface@12' as EngEraseSurface:dword
        extrn '__imp__EngFillPath@28' as EngFillPath:dword
        extrn '__imp__EngFindResource@16' as EngFindResource:dword
        extrn '__imp__EngFreeModule@4' as EngFreeModule:dword
        extrn '__imp__EngGetCurrentCodePage@8' as EngGetCurrentCodePage:dword
        extrn '__imp__EngGetDriverName@4' as EngGetDriverName:dword
        extrn '__imp__EngGetPrinterDataFileName@4' as EngGetPrinterDataFileName:dword
        extrn '__imp__EngGradientFill@40' as EngGradientFill:dword
        extrn '__imp__EngLineTo@36' as EngLineTo:dword
        extrn '__imp__EngLoadModule@4' as EngLoadModule:dword
        extrn '__imp__EngLockSurface@4' as EngLockSurface:dword
        extrn '__imp__EngMarkBandingSurface@4' as EngMarkBandingSurface:dword
        extrn '__imp__EngMultiByteToUnicodeN@20' as EngMultiByteToUnicodeN:dword
        extrn '__imp__EngMultiByteToWideChar@20' as EngMultiByteToWideChar:dword
        extrn '__imp__EngPaint@20' as EngPaint:dword
        extrn '__imp__EngPlgBlt@44' as EngPlgBlt:dword
        extrn '__imp__EngQueryLocalTime@4' as EngQueryLocalTime:dword
        extrn '__imp__EngReleaseSemaphore@4' as EngReleaseSemaphore:dword
        extrn '__imp__EngStretchBlt@44' as EngStretchBlt:dword
        extrn '__imp__EngStretchBltROP@52' as EngStretchBltROP:dword
        extrn '__imp__EngStrokeAndFillPath@40' as EngStrokeAndFillPath:dword
        extrn '__imp__EngStrokePath@32' as EngStrokePath:dword
        extrn '__imp__EngTextOut@40' as EngTextOut:dword
        extrn '__imp__EngTransparentBlt@32' as EngTransparentBlt:dword
        extrn '__imp__EngUnicodeToMultiByteN@20' as EngUnicodeToMultiByteN:dword
        extrn '__imp__EngUnlockSurface@4' as EngUnlockSurface:dword
        extrn '__imp__EngWideCharToMultiByte@20' as EngWideCharToMultiByte:dword
        extrn '__imp__FONTOBJ_cGetAllGlyphHandles@8' as FONTOBJ_cGetAllGlyphHandles:dword
        extrn '__imp__FONTOBJ_cGetGlyphs@20' as FONTOBJ_cGetGlyphs:dword
        extrn '__imp__FONTOBJ_pQueryGlyphAttrs@8' as FONTOBJ_pQueryGlyphAttrs:dword
        extrn '__imp__FONTOBJ_pfdg@4' as FONTOBJ_pfdg:dword
        extrn '__imp__FONTOBJ_pifi@4' as FONTOBJ_pifi:dword
        extrn '__imp__FONTOBJ_pvTrueTypeFontFile@8' as FONTOBJ_pvTrueTypeFontFile:dword
        extrn '__imp__FONTOBJ_pxoGetXform@4' as FONTOBJ_pxoGetXform:dword
        extrn '__imp__FONTOBJ_vGetInfo@12' as FONTOBJ_vGetInfo:dword
        extrn '__imp__GdiAlphaBlend@44' as GdiAlphaBlend:dword
        extrn '__imp__GdiArtificialDecrementDriver@8' as GdiArtificialDecrementDriver:dword
        extrn '__imp__GdiConvertBitmapV5@16' as GdiConvertBitmapV5:dword
        extrn '__imp__GdiDeleteSpoolFileHandle@4' as GdiDeleteSpoolFileHandle:dword
        extrn '__imp__GdiEndDocEMF@4' as GdiEndDocEMF:dword
        extrn '__imp__GdiEndPageEMF@8' as GdiEndPageEMF:dword
        extrn '__imp__GdiFullscreenControl@0' as GdiFullscreenControl:dword
        extrn '__imp__GdiGetBitmapBitsSize@4' as GdiGetBitmapBitsSize:dword
        extrn '__imp__GdiGetDC@4' as GdiGetDC:dword
        extrn '__imp__GetDCBrushColor@4' as GetDCBrushColor:dword
        extrn '__imp__GetDCPenColor@4' as GetDCPenColor:dword
        extrn '__imp__GdiGetDevmodeForPage@16' as GdiGetDevmodeForPage:dword
        extrn '__imp__GdiGetPageCount@4' as GdiGetPageCount:dword
        extrn '__imp__GdiGetPageHandle@12' as GdiGetPageHandle:dword
        extrn '__imp__GdiGetSpoolFileHandle@12' as GdiGetSpoolFileHandle:dword
        extrn '__imp__GdiGradientFill@24' as GdiGradientFill:dword
        extrn '__imp__GdiInitializeLanguagePack@4' as GdiInitializeLanguagePack:dword
        extrn '__imp__GdiIsPlayMetafileDC@4' as GdiIsPlayMetafileDC:dword
        extrn '__imp__GdiPlayEMF@20' as GdiPlayEMF:dword
        extrn '__imp__GdiPlayPageEMF@20' as GdiPlayPageEMF:dword
        extrn '__imp__GdiPrinterThunk@12' as GdiPrinterThunk:dword
        extrn '__imp__GdiRealizationInfo@8' as GdiRealizationInfo:dword
        extrn '__imp__GdiReleaseDC@4' as GdiReleaseDC:dword
        extrn '__imp__GdiResetDCEMF@8' as GdiResetDCEMF:dword
        extrn '__imp__GdiSetLastError@4' as GdiSetLastError:dword
        extrn '__imp__GdiStartDocEMF@8' as GdiStartDocEMF:dword
        extrn '__imp__GdiStartPageEMF@4' as GdiStartPageEMF:dword
        extrn '__imp__GdiTransparentBlt@44' as GdiTransparentBlt:dword
        extrn '__imp__GetCharABCWidthsI@20' as GetCharABCWidthsI:dword
        extrn '__imp__GetCharWidthI@20' as GetCharWidthI:dword
        extrn '__imp__GetEUDCTimeStamp@0' as GetEUDCTimeStamp:dword
        extrn '__imp__GetEUDCTimeStampExW@4' as GetEUDCTimeStampExW:dword
        extrn '__imp__GetFontAssocStatus@4' as GetFontAssocStatus:dword
        extrn '__imp__GetFontUnicodeRanges@8' as GetFontUnicodeRanges:dword
        extrn '__imp__GetGlyphIndicesA@20' as GetGlyphIndicesA:dword
        extrn '__imp__GetGlyphIndicesW@20' as GetGlyphIndicesW:dword
        extrn '__imp__GetTextExtentExPointI@28' as GetTextExtentExPointI:dword
        extrn '__imp__GetTextExtentExPointWPri@28' as GetTextExtentExPointWPri:dword
        extrn '__imp__GetTextExtentPointI@16' as GetTextExtentPointI:dword
        extrn '__imp__GetTextFaceAliasW@12' as GetTextFaceAliasW:dword
        extrn '__imp__MirrorRgn@8' as MirrorRgn:dword
        extrn '__imp__PATHOBJ_bEnum@8' as PATHOBJ_bEnum:dword
        extrn '__imp__PATHOBJ_bEnumClipLines@12' as PATHOBJ_bEnumClipLines:dword
        extrn '__imp__PATHOBJ_vEnumStart@4' as PATHOBJ_vEnumStart:dword
        extrn '__imp__PATHOBJ_vEnumStartClipLines@16' as PATHOBJ_vEnumStartClipLines:dword
        extrn '__imp__PATHOBJ_vGetBounds@8' as PATHOBJ_vGetBounds:dword
        extrn '__imp__QueryFontAssocStatus@0' as QueryFontAssocStatus:dword
        extrn '__imp__RemoveFontMemResourceEx@4' as RemoveFontMemResourceEx:dword
        extrn '__imp__RemoveFontResourceExA@12' as RemoveFontResourceExA:dword
        extrn '__imp__RemoveFontResourceExW@12' as RemoveFontResourceExW:dword
        extrn '__imp__SetDCBrushColor@8' as SetDCBrushColor:dword
        extrn '__imp__SetDCPenColor@8' as SetDCPenColor:dword
        extrn '__imp__SetLayoutWidth@12' as SetLayoutWidth:dword
        extrn '__imp__StartFormPage@4' as StartFormPage:dword
        extrn '__imp__STROBJ_bEnum@12' as STROBJ_bEnum:dword
        extrn '__imp__STROBJ_bEnumPositionsOnly@12' as STROBJ_bEnumPositionsOnly:dword
        extrn '__imp__STROBJ_bGetAdvanceWidths@16' as STROBJ_bGetAdvanceWidths:dword
        extrn '__imp__STROBJ_dwGetCodePage@4' as STROBJ_dwGetCodePage:dword
        extrn '__imp__STROBJ_vEnumStart@4' as STROBJ_vEnumStart:dword
        extrn '__imp__XFORMOBJ_bApplyXform@20' as XFORMOBJ_bApplyXform:dword
        extrn '__imp__XFORMOBJ_iGetXform@8' as XFORMOBJ_iGetXform:dword
        extrn '__imp__XLATEOBJ_cGetPalette@16' as XLATEOBJ_cGetPalette:dword
        extrn '__imp__XLATEOBJ_hGetColorTransform@4' as XLATEOBJ_hGetColorTransform:dword
        extrn '__imp__XLATEOBJ_iXlate@8' as XLATEOBJ_iXlate:dword
        extrn '__imp__XLATEOBJ_piVector@4' as XLATEOBJ_piVector:dword
        api AddFontResourceEx,\
            CreateFontIndirectEx,\
            GetGlyphIndices,\
            RemoveFontResourceEx
    end if

    if (NTDDI_VERSION >= NTDDI_WINXP)
        extrn '__imp__GetBrushAttributes@4' as GetBrushAttributes:dword
        extrn '__imp__SetBitmapAttributes@8' as SetBitmapAttributes:dword
    end if

    if (NTDDI_VERSION >= NTDDI_VISTA)
        extrn '__imp__ConfigureOPMProtectedOutput@16' as ConfigureOPMProtectedOutput:dword
        extrn '__imp__CreateOPMProtectedOutputs@20' as CreateOPMProtectedOutputs:dword
        extrn '__imp__D3DKMTCheckExclusiveOwnership@0' as D3DKMTCheckExclusiveOwnership:dword
        extrn '__imp__D3DKMTCheckMonitorPowerState@4' as D3DKMTCheckMonitorPowerState:dword
        extrn '__imp__D3DKMTCheckOcclusion@4' as D3DKMTCheckOcclusion:dword
        extrn '__imp__D3DKMTCloseAdapter@4' as D3DKMTCloseAdapter:dword
        extrn '__imp__D3DKMTCreateAllocation@4' as D3DKMTCreateAllocation:dword
        extrn '__imp__D3DKMTCreateContext@4' as D3DKMTCreateContext:dword
        extrn '__imp__D3DKMTCreateDCFromMemory@4' as D3DKMTCreateDCFromMemory:dword
        extrn '__imp__D3DKMTCreateDevice@4' as D3DKMTCreateDevice:dword
        extrn '__imp__D3DKMTCreateOverlay@4' as D3DKMTCreateOverlay:dword
        extrn '__imp__D3DKMTCreateSynchronizationObject@4' as D3DKMTCreateSynchronizationObject:dword
        extrn '__imp__D3DKMTDestroyAllocation@4' as D3DKMTDestroyAllocation:dword
        extrn '__imp__D3DKMTDestroyContext@4' as D3DKMTDestroyContext:dword
        extrn '__imp__D3DKMTDestroyDCFromMemory@4' as D3DKMTDestroyDCFromMemory:dword
        extrn '__imp__D3DKMTDestroyDevice@4' as D3DKMTDestroyDevice:dword
        extrn '__imp__D3DKMTDestroyOverlay@4' as D3DKMTDestroyOverlay:dword
        extrn '__imp__D3DKMTDestroySynchronizationObject@4' as D3DKMTDestroySynchronizationObject:dword
        extrn '__imp__D3DKMTEscape@4' as D3DKMTEscape:dword
        extrn '__imp__D3DKMTFlipOverlay@4' as D3DKMTFlipOverlay:dword
        extrn '__imp__D3DKMTGetContextSchedulingPriority@4' as D3DKMTGetContextSchedulingPriority:dword
        extrn '__imp__D3DKMTGetDeviceState@4' as D3DKMTGetDeviceState:dword
        extrn '__imp__D3DKMTGetDisplayModeList@4' as D3DKMTGetDisplayModeList:dword
        extrn '__imp__D3DKMTGetMultisampleMethodList@4' as D3DKMTGetMultisampleMethodList:dword
        extrn '__imp__D3DKMTGetPresentHistory@4' as D3DKMTGetPresentHistory:dword
        extrn '__imp__D3DKMTGetProcessSchedulingPriorityClass@8' as D3DKMTGetProcessSchedulingPriorityClass:dword
        extrn '__imp__D3DKMTGetRuntimeData@4' as D3DKMTGetRuntimeData:dword
        extrn '__imp__D3DKMTGetScanLine@4' as D3DKMTGetScanLine:dword
        extrn '__imp__D3DKMTGetSharedPrimaryHandle@4' as D3DKMTGetSharedPrimaryHandle:dword
        extrn '__imp__D3DKMTInvalidateActiveVidPn@4' as D3DKMTInvalidateActiveVidPn:dword
        extrn '__imp__D3DKMTLock@4' as D3DKMTLock:dword
        extrn '__imp__D3DKMTOpenAdapterFromDeviceName@4' as D3DKMTOpenAdapterFromDeviceName:dword
        extrn '__imp__D3DKMTOpenAdapterFromGdiDisplayName@4' as D3DKMTOpenAdapterFromGdiDisplayName:dword
        extrn '__imp__D3DKMTOpenAdapterFromHdc@4' as D3DKMTOpenAdapterFromHdc:dword
        extrn '__imp__D3DKMTOpenResource@4' as D3DKMTOpenResource:dword
        extrn '__imp__D3DKMTPollDisplayChildren@4' as D3DKMTPollDisplayChildren:dword
        extrn '__imp__D3DKMTPresent@4' as D3DKMTPresent:dword
        extrn '__imp__D3DKMTQueryAdapterInfo@4' as D3DKMTQueryAdapterInfo:dword
        extrn '__imp__D3DKMTQueryAllocationResidency@4' as D3DKMTQueryAllocationResidency:dword
        extrn '__imp__D3DKMTQueryResourceInfo@4' as D3DKMTQueryResourceInfo:dword
        extrn '__imp__D3DKMTReleaseProcessVidPnSourceOwners@4' as D3DKMTReleaseProcessVidPnSourceOwners:dword
        extrn '__imp__D3DKMTRender@4' as D3DKMTRender:dword
        extrn '__imp__D3DKMTSetAllocationPriority@4' as D3DKMTSetAllocationPriority:dword
        extrn '__imp__D3DKMTSetContextSchedulingPriority@4' as D3DKMTSetContextSchedulingPriority:dword
        extrn '__imp__D3DKMTSetDisplayMode@4' as D3DKMTSetDisplayMode:dword
        extrn '__imp__D3DKMTSetDisplayPrivateDriverFormat@4' as D3DKMTSetDisplayPrivateDriverFormat:dword
        extrn '__imp__D3DKMTSetGammaRamp@4' as D3DKMTSetGammaRamp:dword
        extrn '__imp__D3DKMTSetProcessSchedulingPriorityClass@8' as D3DKMTSetProcessSchedulingPriorityClass:dword
        extrn '__imp__D3DKMTSetQueuedLimit@4' as D3DKMTSetQueuedLimit:dword
        extrn '__imp__D3DKMTSetVidPnSourceOwner@4' as D3DKMTSetVidPnSourceOwner:dword
        extrn '__imp__D3DKMTSharedPrimaryLockNotification@4' as D3DKMTSharedPrimaryLockNotification:dword
        extrn '__imp__D3DKMTSharedPrimaryUnLockNotification@4' as D3DKMTSharedPrimaryUnLockNotification:dword
        extrn '__imp__D3DKMTSignalSynchronizationObject@4' as D3DKMTSignalSynchronizationObject:dword
        extrn '__imp__D3DKMTUnlock@4' as D3DKMTUnlock:dword
        extrn '__imp__D3DKMTUpdateOverlay@4' as D3DKMTUpdateOverlay:dword
        extrn '__imp__D3DKMTWaitForIdle@4' as D3DKMTWaitForIdle:dword
        extrn '__imp__D3DKMTWaitForSynchronizationObject@4' as D3DKMTWaitForSynchronizationObject:dword
        extrn '__imp__D3DKMTWaitForVerticalBlankEvent@4' as D3DKMTWaitForVerticalBlankEvent:dword
        extrn '__imp__DDCCIGetCapabilitiesString@12' as DDCCIGetCapabilitiesString:dword
        extrn '__imp__DDCCIGetCapabilitiesStringLength@8' as DDCCIGetCapabilitiesStringLength:dword
        extrn '__imp__DDCCIGetTimingReport@8' as DDCCIGetTimingReport:dword
        extrn '__imp__DDCCIGetVCPFeature@20' as DDCCIGetVCPFeature:dword
        extrn '__imp__DDCCISaveCurrentSettings@4' as DDCCISaveCurrentSettings:dword
        extrn '__imp__DDCCISetVCPFeature@12' as DDCCISetVCPFeature:dword
        extrn '__imp__DestroyOPMProtectedOutput@4' as DestroyOPMProtectedOutput:dword
        extrn '__imp__DestroyPhysicalMonitorInternal@4' as DestroyPhysicalMonitorInternal:dword
        extrn '__imp__GdiIsScreenDC@4' as GdiIsScreenDC:dword
        extrn '__imp__GetCOPPCompatibleOPMInformation@12' as GetCOPPCompatibleOPMInformation:dword
        extrn '__imp__GetNumberOfPhysicalMonitors@8' as GetNumberOfPhysicalMonitors:dword
        extrn '__imp__GetOPMInformation@12' as GetOPMInformation:dword
        extrn '__imp__GetOPMRandomNumber@8' as GetOPMRandomNumber:dword
        extrn '__imp__GetPhysicalMonitorDescription@12' as GetPhysicalMonitorDescription:dword
        extrn '__imp__GetPhysicalMonitors@16' as GetPhysicalMonitors:dword
        extrn '__imp__GetSuggestedOPMProtectedOutputArraySize@8' as GetSuggestedOPMProtectedOutputArraySize:dword
        extrn '__imp__SetOPMSigningKeyAndSequenceNumbers@8' as SetOPMSigningKeyAndSequenceNumbers:dword
    end if

    if (NTDDI_VERSION >= NTDDI_WIN7)
        extrn '__imp__D3DKMTAcquireKeyedMutex@4' as D3DKMTAcquireKeyedMutex:dword
        extrn '__imp__D3DKMTCheckSharedResourceAccess@4' as D3DKMTCheckSharedResourceAccess:dword
        extrn '__imp__D3DKMTCheckVidPnExclusiveOwnership@4' as D3DKMTCheckVidPnExclusiveOwnership:dword
        extrn '__imp__D3DKMTConfigureSharedResource@4' as D3DKMTConfigureSharedResource:dword
        extrn '__imp__D3DKMTCreateAllocation2@4' as D3DKMTCreateAllocation2:dword
        extrn '__imp__D3DKMTCreateKeyedMutex@4' as D3DKMTCreateKeyedMutex:dword
        extrn '__imp__D3DKMTCreateSynchronizationObject2@4' as D3DKMTCreateSynchronizationObject2:dword
        extrn '__imp__D3DKMTDestroyKeyedMutex@4' as D3DKMTDestroyKeyedMutex:dword
        extrn '__imp__D3DKMTGetOverlayState@4' as D3DKMTGetOverlayState:dword
        extrn '__imp__D3DKMTOpenKeyedMutex@4' as D3DKMTOpenKeyedMutex:dword
        extrn '__imp__D3DKMTOpenResource2@4' as D3DKMTOpenResource2:dword
        extrn '__imp__D3DKMTOpenSynchronizationObject@4' as D3DKMTOpenSynchronizationObject:dword
        extrn '__imp__D3DKMTReleaseKeyedMutex@4' as D3DKMTReleaseKeyedMutex:dword
        extrn '__imp__D3DKMTSignalSynchronizationObject2@4' as D3DKMTSignalSynchronizationObject2:dword
        extrn '__imp__D3DKMTWaitForSynchronizationObject2@4' as D3DKMTWaitForSynchronizationObject2:dword
    end if

    if (NTDDI_VERSION >= NTDDI_WIN8)
        extrn '__imp__D3DKMTAcquireKeyedMutex2@4' as D3DKMTAcquireKeyedMutex2:dword
        extrn '__imp__D3DKMTCreateKeyedMutex2@4' as D3DKMTCreateKeyedMutex2:dword
        extrn '__imp__D3DKMTCreateOutputDupl@4' as D3DKMTCreateOutputDupl:dword
        extrn '__imp__D3DKMTDestroyOutputDupl@4' as D3DKMTDestroyOutputDupl:dword
        extrn '__imp__D3DKMTEnumAdapters@4' as D3DKMTEnumAdapters:dword
        extrn '__imp__D3DKMTGetContextInProcessSchedulingPriority@4' as D3DKMTGetContextInProcessSchedulingPriority:dword
        extrn '__imp__D3DKMTGetSharedResourceAdapterLuid@4' as D3DKMTGetSharedResourceAdapterLuid:dword
        extrn '__imp__D3DKMTOfferAllocations@4' as D3DKMTOfferAllocations:dword
        extrn '__imp__D3DKMTOpenAdapterFromLuid@4' as D3DKMTOpenAdapterFromLuid:dword
        extrn '__imp__D3DKMTOpenKeyedMutex2@4' as D3DKMTOpenKeyedMutex2:dword
        extrn '__imp__D3DKMTOpenNtHandleFromName@4' as D3DKMTOpenNtHandleFromName:dword
        extrn '__imp__D3DKMTOpenResourceFromNtHandle@4' as D3DKMTOpenResourceFromNtHandle:dword
        extrn '__imp__D3DKMTOpenSyncObjectFromNtHandle@4' as D3DKMTOpenSyncObjectFromNtHandle:dword
        extrn '__imp__D3DKMTOutputDuplGetFrameInfo@4' as D3DKMTOutputDuplGetFrameInfo:dword
        extrn '__imp__D3DKMTOutputDuplGetMetaData@4' as D3DKMTOutputDuplGetMetaData:dword
        extrn '__imp__D3DKMTOutputDuplGetPointerShapeData@4' as D3DKMTOutputDuplGetPointerShapeData:dword
        extrn '__imp__D3DKMTOutputDuplPresent@4' as D3DKMTOutputDuplPresent:dword
        extrn '__imp__D3DKMTOutputDuplReleaseFrame@4' as D3DKMTOutputDuplReleaseFrame:dword
        extrn '__imp__D3DKMTPinDirectFlipResources@4' as D3DKMTPinDirectFlipResources:dword
        extrn '__imp__D3DKMTPresentMultiPlaneOverlay@4' as D3DKMTPresentMultiPlaneOverlay:dword
        extrn '__imp__D3DKMTQueryRemoteVidPnSourceFromGdiDisplayName@4' as D3DKMTQueryRemoteVidPnSourceFromGdiDisplayName:dword
        extrn '__imp__D3DKMTQueryResourceInfoFromNtHandle@4' as D3DKMTQueryResourceInfoFromNtHandle:dword
        extrn '__imp__D3DKMTReclaimAllocations@4' as D3DKMTReclaimAllocations:dword
        extrn '__imp__D3DKMTReleaseKeyedMutex2@4' as D3DKMTReleaseKeyedMutex2:dword
        extrn '__imp__D3DKMTSetContextInProcessSchedulingPriority@4' as D3DKMTSetContextInProcessSchedulingPriority:dword
        extrn '__imp__D3DKMTSetStereoEnabled@4' as D3DKMTSetStereoEnabled:dword
        extrn '__imp__D3DKMTSetVidPnSourceOwner1@4' as D3DKMTSetVidPnSourceOwner1:dword
        extrn '__imp__D3DKMTShareObjects@20' as D3DKMTShareObjects:dword
        extrn '__imp__D3DKMTUnpinDirectFlipResources@4' as D3DKMTUnpinDirectFlipResources:dword
        extrn '__imp__D3DKMTWaitForVerticalBlankEvent2@4' as D3DKMTWaitForVerticalBlankEvent2:dword
        extrn '__imp__GetCertificateSize@12' as GetCertificateSize:dword
        extrn '__imp__ScriptApplyDigitSubstitution@12' as ScriptApplyDigitSubstitution:dword
        extrn '__imp__ScriptApplyLogicalWidth@36' as ScriptApplyLogicalWidth:dword
        extrn '__imp__ScriptBreak@16' as ScriptBreak:dword
        extrn '__imp__ScriptCPtoX@36' as ScriptCPtoX:dword
        extrn '__imp__ScriptCacheGetHeight@12' as ScriptCacheGetHeight:dword
        extrn '__imp__ScriptFreeCache@4' as ScriptFreeCache:dword
        extrn '__imp__ScriptGetCMap@24' as ScriptGetCMap:dword
        extrn '__imp__ScriptGetFontAlternateGlyphs@40' as ScriptGetFontAlternateGlyphs:dword
        extrn '__imp__ScriptGetFontFeatureTags@32' as ScriptGetFontFeatureTags:dword
        extrn '__imp__ScriptGetFontLanguageTags@28' as ScriptGetFontLanguageTags:dword
        extrn '__imp__ScriptGetFontProperties@12' as ScriptGetFontProperties:dword
        extrn '__imp__ScriptGetFontScriptTags@24' as ScriptGetFontScriptTags:dword
        extrn '__imp__ScriptGetGlyphABCWidth@16' as ScriptGetGlyphABCWidth:dword
        extrn '__imp__ScriptGetLogicalWidths@28' as ScriptGetLogicalWidths:dword
        extrn '__imp__ScriptGetProperties@8' as ScriptGetProperties:dword
        extrn '__imp__ScriptIsComplex@12' as ScriptIsComplex:dword
        extrn '__imp__ScriptItemize@28' as ScriptItemize:dword
        extrn '__imp__ScriptItemizeOpenType@32' as ScriptItemizeOpenType:dword
        extrn '__imp__ScriptJustify@24' as ScriptJustify:dword
        extrn '__imp__ScriptLayout@16' as ScriptLayout:dword
        extrn '__imp__ScriptPlace@36' as ScriptPlace:dword
        extrn '__imp__ScriptPlaceOpenType@72' as ScriptPlaceOpenType:dword
        extrn '__imp__ScriptPositionSingleGlyph@48' as ScriptPositionSingleGlyph:dword
        extrn '__imp__ScriptRecordDigitSubstitution@8' as ScriptRecordDigitSubstitution:dword
        extrn '__imp__ScriptShape@40' as ScriptShape:dword
        extrn '__imp__ScriptShapeOpenType@64' as ScriptShapeOpenType:dword
        extrn '__imp__ScriptStringAnalyse@52' as ScriptStringAnalyse:dword
        extrn '__imp__ScriptStringCPtoX@16' as ScriptStringCPtoX:dword
        extrn '__imp__ScriptStringFree@4' as ScriptStringFree:dword
        extrn '__imp__ScriptStringGetLogicalWidths@8' as ScriptStringGetLogicalWidths:dword
        extrn '__imp__ScriptStringGetOrder@8' as ScriptStringGetOrder:dword
        extrn '__imp__ScriptStringOut@32' as ScriptStringOut:dword
        extrn '__imp__ScriptStringValidate@4' as ScriptStringValidate:dword
        extrn '__imp__ScriptStringXtoCP@16' as ScriptStringXtoCP:dword
        extrn '__imp__ScriptString_pLogAttr@4' as ScriptString_pLogAttr:dword
        extrn '__imp__ScriptString_pSize@4' as ScriptString_pSize:dword
        extrn '__imp__ScriptString_pcOutChars@4' as ScriptString_pcOutChars:dword
        extrn '__imp__ScriptSubstituteSingleGlyph@36' as ScriptSubstituteSingleGlyph:dword
        extrn '__imp__ScriptTextOut@56' as ScriptTextOut:dword
        extrn '__imp__ScriptXtoCP@36' as ScriptXtoCP:dword
    end if

    if (NTDDI_VERSION >= NTDDI_WIN81)
        extrn '__imp__D3DKMTCheckMultiPlaneOverlaySupport@4' as D3DKMTCheckMultiPlaneOverlaySupport:dword
        extrn '__imp__D3DKMTCheckMultiPlaneOverlaySupport2@4' as D3DKMTCheckMultiPlaneOverlaySupport2:dword
    end if

    if (NTDDI_VERSION >= NTDDI_WIN10)
        extrn '__imp__D3DKMTCreateContextVirtual@4' as D3DKMTCreateContextVirtual:dword
        extrn '__imp__D3DKMTCreatePagingQueue@4' as D3DKMTCreatePagingQueue:dword
        extrn '__imp__D3DKMTDestroyAllocation2@4' as D3DKMTDestroyAllocation2:dword
        extrn '__imp__D3DKMTDestroyPagingQueue@4' as D3DKMTDestroyPagingQueue:dword
        extrn '__imp__D3DKMTEvict@4' as D3DKMTEvict:dword
        extrn '__imp__D3DKMTFreeGpuVirtualAddress@4' as D3DKMTFreeGpuVirtualAddress:dword
        extrn '__imp__D3DKMTLock2@4' as D3DKMTLock2:dword
        extrn '__imp__D3DKMTMakeResident@4' as D3DKMTMakeResident:dword
        extrn '__imp__D3DKMTMapGpuVirtualAddress@4' as D3DKMTMapGpuVirtualAddress:dword
        extrn '__imp__D3DKMTOpenSyncObjectFromNtHandle2@4' as D3DKMTOpenSyncObjectFromNtHandle2:dword
        extrn '__imp__D3DKMTOpenSyncObjectNtHandleFromName@4' as D3DKMTOpenSyncObjectNtHandleFromName:dword
        extrn '__imp__D3DKMTReclaimAllocations2@4' as D3DKMTReclaimAllocations2:dword
        extrn '__imp__D3DKMTRegisterTrimNotification@4' as D3DKMTRegisterTrimNotification:dword
        extrn '__imp__D3DKMTReserveGpuVirtualAddress@4' as D3DKMTReserveGpuVirtualAddress:dword
        extrn '__imp__D3DKMTSignalSynchronizationObjectFromCpu@4' as D3DKMTSignalSynchronizationObjectFromCpu:dword
        extrn '__imp__D3DKMTSignalSynchronizationObjectFromGpu@4' as D3DKMTSignalSynchronizationObjectFromGpu:dword
        extrn '__imp__D3DKMTSignalSynchronizationObjectFromGpu2@4' as D3DKMTSignalSynchronizationObjectFromGpu2:dword
        extrn '__imp__D3DKMTSubmitCommand@4' as D3DKMTSubmitCommand:dword
        extrn '__imp__D3DKMTUnlock2@4' as D3DKMTUnlock2:dword
        extrn '__imp__D3DKMTUnregisterTrimNotification@4' as D3DKMTUnregisterTrimNotification:dword
        extrn '__imp__D3DKMTUpdateGpuVirtualAddress@4' as D3DKMTUpdateGpuVirtualAddress:dword
        extrn '__imp__D3DKMTWaitForSynchronizationObjectFromCpu@4' as D3DKMTWaitForSynchronizationObjectFromCpu:dword
        extrn '__imp__D3DKMTWaitForSynchronizationObjectFromGpu@4' as D3DKMTWaitForSynchronizationObjectFromGpu:dword
    end if

    api AddFontResource,\
        CopyEnhMetaFile,\
        CopyMetaFile,\
        CreateColorSpace,\
        CreateDC,\
        CreateEnhMetaFile,\
        CreateFont,\
        CreateFontIndirect,\
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
        GetCharWidth,\
        GetCharWidth32,\
        GetCharWidthFloat,\
        GetCharacterPlacement,\
        GetEnhMetaFile,\
        GetEnhMetaFileDescription,\
        GetGlyphOutline,\
        GetICMProfile,\
        GetKerningPairs,\
        GetLogColorSpace,\
        GetMetaFile,\
        GetObject,\
        GetOutlineTextMetrics,\
        GetTextExtentExPoint,\
        GetTextExtentPoint32,\
        GetTextExtentPoint,\
        GetTextFace,\
        GetTextMetrics,\
        PolyTextOut,\
        RemoveFontResource,\
        ResetDC,\
        SetICMProfile,\
        StartDoc,\
        TextOut,\
        UpdateICMRegKey
end if

;======================= Undocumented functions (unknown arguments) =======================;
;if defined APP_WIN64
;    extrn '__imp_AddFontResourceTracking' as AddFontResourceTracking:qword
;    extrn '__imp_AnyLinkedFonts' as AnyLinkedFonts:qword
;    extrn '__imp_BeginGdiRendering' as AnyLinkedFonts:qword
;    extrn '__imp_ClearBitmapAttributes' as ClearBitmapAttributes:qword
;    extrn '__imp_ClearBrushAttributes' as ClearBrushAttributes:qword
;    extrn '__imp_CreateBitmapFromDxSurface' as CreateBitmapFromDxSurface:qword
;    extrn '__imp_CreateBitmapFromDxSurface2' as CreateBitmapFromDxSurface2:qword
;    extrn '__imp_CreateSessionMappedDIBSection' as CreateSessionMappedDIBSection:qword
;    extrn '__imp_D3DKMTAbandonSwapChain' as D3DKMTAbandonSwapChain:qword
;    extrn '__imp_D3DKMTAcquireSwapChain' as D3DKMTAcquireSwapChain:qword
;    extrn '__imp_D3DKMTAdjustFullscreenGamma' as D3DKMTAdjustFullscreenGamma:qword
;    extrn '__imp_D3DKMTCacheHybridQueryValue' as D3DKMTCacheHybridQueryValue:qword
;    extrn '__imp_D3DKMTChangeVideoMemoryReservation' as D3DKMTChangeVideoMemoryReservation:qword
;    extrn '__imp_D3DKMTCreateSwapChain' as D3DKMTCreateSwapChain:qword
;    extrn '__imp_D3DKMTEnumAdapters2' as D3DKMTEnumAdapters2:qword
;    extrn '__imp_D3DKMTFlushHeapTransitions' as D3DKMTFlushHeapTransitions:qword
;    extrn '__imp_D3DKMTGetCachedHybridQueryValue' as D3DKMTGetCachedHybridQueryValue:qword
;    extrn '__imp_D3DKMTGetDWMVerticalBlankEvent' as D3DKMTGetDWMVerticalBlankEvent:qword
;    extrn '__imp_D3DKMTGetPresentQueueEvent' as D3DKMTGetPresentQueueEvent:qword
;    extrn '__imp_D3DKMTGetResourcePresentPrivateDriverData' as D3DKMTGetResourcePresentPrivateDriverData:qword
;    extrn '__imp_D3DKMTGetSetSwapChainMetadata' as D3DKMTGetSetSwapChainMetadata:qword
;    extrn '__imp_D3DKMTInvalidateCache' as D3DKMTInvalidateCache:qword
;    extrn '__imp_D3DKMTMarkDeviceAsError' as D3DKMTMarkDeviceAsError:qword
;    extrn '__imp_D3DKMTNetDispGetNextChunkInfo' as D3DKMTNetDispGetNextChunkInfo:qword
;    extrn '__imp_D3DKMTNetDispQueryMiracastDisplayDeviceStatus' as D3DKMTNetDispQueryMiracastDisplayDeviceStatus:qword
;    extrn '__imp_D3DKMTNetDispQueryMiracastDisplayDeviceSupport' as D3DKMTNetDispQueryMiracastDisplayDeviceSupport:qword
;    extrn '__imp_D3DKMTNetDispStartMiracastDisplayDevice' as D3DKMTNetDispStartMiracastDisplayDevice:qword
;    extrn '__imp_D3DKMTNetDispStartMiracastDisplayDevice2' as D3DKMTNetDispStartMiracastDisplayDevice2:qword
;    extrn '__imp_D3DKMTNetDispStartMiracastDisplayDeviceEx' as D3DKMTNetDispStartMiracastDisplayDeviceEx:qword
;    extrn '__imp_D3DKMTNetDispStopMiracastDisplayDevice' as D3DKMTNetDispStopMiracastDisplayDevice:qword
;    extrn '__imp_D3DKMTNetDispStopSessions' as D3DKMTNetDispStopSessions:qword
;    extrn '__imp_D3DKMTOpenSwapChain' as D3DKMTOpenSwapChain:qword
;    extrn '__imp_D3DKMTPresentMultiPlaneOverlay2' as D3DKMTPresentMultiPlaneOverlay2:qword
;    extrn '__imp_D3DKMTQueryClockCalibration' as D3DKMTQueryClockCalibration:qword
;    extrn '__imp_D3DKMTQueryStatistics' as D3DKMTQueryStatistics:qword
;    extrn '__imp_D3DKMTQueryVideoMemoryInfo' as D3DKMTQueryVideoMemoryInfo:qword
;    extrn '__imp_D3DKMTQueryVidPnExclusiveOwnership' as D3DKMTQueryVidPnExclusiveOwnership:qword
;    extrn '__imp_D3DKMTReleaseSwapChain' as D3DKMTReleaseSwapChain:qword
;    extrn '__imp_D3DKMTSetDodIndirectSwapchain' as D3DKMTSetDodIndirectSwapchain:qword
;    extrn '__imp_D3DKMTSetHwProtectionTeardownRecovery' as D3DKMTSetHwProtectionTeardownRecovery:qword
;    extrn '__imp_D3DKMTSetStablePowerState' as D3DKMTSetStablePowerState:qword
;    extrn '__imp_D3DKMTSetSyncRefreshCountWaitTarget' as D3DKMTSetSyncRefreshCountWaitTarget:qword
;    extrn '__imp_D3DKMTSetVidPnSourceHwProtection' as D3DKMTSetVidPnSourceHwProtection:qword
;    extrn '__imp_DdCreateFullscreenSprite' as DdCreateFullscreenSprite:qword
;    extrn '__imp_DdDestroyFullscreenSprite' as DdDestroyFullscreenSprite:qword
;    extrn '__imp_DdEntry0' as DdEntry0:qword
;    extrn '__imp_DdEntry1' as DdEntry1:qword
;    extrn '__imp_DdEntry10' as DdEntry10:qword
;    extrn '__imp_DdEntry11' as DdEntry11:qword
;    extrn '__imp_DdEntry12' as DdEntry12:qword
;    extrn '__imp_DdEntry13' as DdEntry13:qword
;    extrn '__imp_DdEntry14' as DdEntry14:qword
;    extrn '__imp_DdEntry15' as DdEntry15:qword
;    extrn '__imp_DdEntry16' as DdEntry16:qword
;    extrn '__imp_DdEntry17' as DdEntry17:qword
;    extrn '__imp_DdEntry18' as DdEntry18:qword
;    extrn '__imp_DdEntry19' as DdEntry19:qword
;    extrn '__imp_DdEntry2' as DdEntry2:qword
;    extrn '__imp_DdEntry20' as DdEntry20:qword
;    extrn '__imp_DdEntry21' as DdEntry21:qword
;    extrn '__imp_DdEntry22' as DdEntry22:qword
;    extrn '__imp_DdEntry23' as DdEntry23:qword
;    extrn '__imp_DdEntry24' as DdEntry24:qword
;    extrn '__imp_DdEntry25' as DdEntry25:qword
;    extrn '__imp_DdEntry26' as DdEntry26:qword
;    extrn '__imp_DdEntry27' as DdEntry27:qword
;    extrn '__imp_DdEntry28' as DdEntry28:qword
;    extrn '__imp_DdEntry29' as DdEntry29:qword
;    extrn '__imp_DdEntry3' as DdEntry3:qword
;    extrn '__imp_DdEntry30' as DdEntry30:qword
;    extrn '__imp_DdEntry31' as DdEntry31:qword
;    extrn '__imp_DdEntry32' as DdEntry32:qword
;    extrn '__imp_DdEntry33' as DdEntry33:qword
;    extrn '__imp_DdEntry34' as DdEntry34:qword
;    extrn '__imp_DdEntry35' as DdEntry35:qword
;    extrn '__imp_DdEntry36' as DdEntry36:qword
;    extrn '__imp_DdEntry37' as DdEntry37:qword
;    extrn '__imp_DdEntry38' as DdEntry38:qword
;    extrn '__imp_DdEntry39' as DdEntry39:qword
;    extrn '__imp_DdEntry4' as DdEntry4:qword
;    extrn '__imp_DdEntry40' as DdEntry40:qword
;    extrn '__imp_DdEntry41' as DdEntry41:qword
;    extrn '__imp_DdEntry42' as DdEntry42:qword
;    extrn '__imp_DdEntry43' as DdEntry43:qword
;    extrn '__imp_DdEntry44' as DdEntry44:qword
;    extrn '__imp_DdEntry45' as DdEntry45:qword
;    extrn '__imp_DdEntry46' as DdEntry46:qword
;    extrn '__imp_DdEntry47' as DdEntry47:qword
;    extrn '__imp_DdEntry48' as DdEntry48:qword
;    extrn '__imp_DdEntry49' as DdEntry49:qword
;    extrn '__imp_DdEntry5' as DdEntry5:qword
;    extrn '__imp_DdEntry50' as DdEntry50:qword
;    extrn '__imp_DdEntry51' as DdEntry51:qword
;    extrn '__imp_DdEntry52' as DdEntry52:qword
;    extrn '__imp_DdEntry53' as DdEntry53:qword
;    extrn '__imp_DdEntry54' as DdEntry54:qword
;    extrn '__imp_DdEntry55' as DdEntry55:qword
;    extrn '__imp_DdEntry56' as DdEntry56:qword
;    extrn '__imp_DdEntry6' as DdEntry6:qword
;    extrn '__imp_DdEntry7' as DdEntry7:qword
;    extrn '__imp_DdEntry8' as DdEntry8:qword
;    extrn '__imp_DdEntry9' as DdEntry9:qword
;    extrn '__imp_DdNotifyFullscreenSpriteUpdate' as DdNotifyFullscreenSpriteUpdate:qword
;    extrn '__imp_DdQueryVisRgnUniqueness' as DdQueryVisRgnUniqueness:qword
;    extrn '__imp_DwmGetDirtyRgn' as DwmGetDirtyRgn:qword
;    extrn '__imp_DwmGetSurfaceData' as DwmGetSurfaceData:qword
;    extrn '__imp_EndFormPage' as EndFormPage:qword
;    extrn '__imp_EndGdiRendering' as EndGdiRendering:qword
;    extrn '__imp_EngQueryEMFInfo' as EngQueryEMFInfo:qword
;    extrn '__imp_EudcLoadLinkW' as EudcLoadLinkW:qword
;    extrn '__imp_EudcUnloadLinkW' as EudcUnloadLinkW:qword
;    extrn '__imp_FontIsLinked' as FontIsLinked:qword
;    extrn '__imp_ftsWordBreak' as ftsWordBreak:qword
;    extrn '__imp_GdiAddGlsRecord' as GdiAddGlsRecord:qword
;    extrn '__imp_GdiClearStockObjectCache' as GdiClearStockObjectCache:qword
;    extrn '__imp_GdiConvertMetaFilePict' as GdiConvertMetaFilePict:qword
;    extrn '__imp_GdiConvertToDevmodeW' as GdiConvertToDevmodeW:qword
;    extrn '__imp_GdiCreateLocalEnhMetaFile' as GdiCreateLocalEnhMetaFile:qword
;    extrn '__imp_GdiCreateLocalMetaFilePict' as GdiCreateLocalMetaFilePict:qword
;    extrn '__imp_GdiDrawStream' as GdiDrawStream:qword
;    extrn '__imp_GdiIsUMPDSandboxingEnabled' as GdiIsUMPDSandboxingEnabled:qword
;    extrn '__imp_GdiEntry1' as GdiEntry1:qword
;    extrn '__imp_GdiEntry10' as GdiEntry10:qword
;    extrn '__imp_GdiEntry11' as GdiEntry11:qword
;    extrn '__imp_GdiEntry12' as GdiEntry12:qword
;    extrn '__imp_GdiEntry13' as GdiEntry13:qword
;    extrn '__imp_GdiEntry14' as GdiEntry14:qword
;    extrn '__imp_GdiEntry15' as GdiEntry15:qword
;    extrn '__imp_GdiEntry16' as GdiEntry16:qword
;    extrn '__imp_GdiEntry2' as GdiEntry2:qword
;    extrn '__imp_GdiEntry3' as GdiEntry3:qword
;    extrn '__imp_GdiEntry4' as GdiEntry4:qword
;    extrn '__imp_GdiEntry5' as GdiEntry5:qword
;    extrn '__imp_GdiEntry6' as GdiEntry6:qword
;    extrn '__imp_GdiEntry7' as GdiEntry7:qword
;    extrn '__imp_GdiEntry8' as GdiEntry8:qword
;    extrn '__imp_GdiEntry9' as GdiEntry9:qword
;    extrn '__imp_GdiLoadType1Fonts' as GdiLoadType1Fonts:qword
;    extrn '__imp_GdiPlayPrivatePageEMF' as GdiPlayPrivatePageEMF:qword
;    extrn '__imp_GdiSupportsFontChangeEvent' as GdiSupportsFontChangeEvent:qword
;    extrn '__imp_GdiSwapBuffers' as GdiSwapBuffers:qword
;    extrn '__imp_GetBitmapAttributes' as GetBitmapAttributes:qword
;    extrn '__imp_GetCertificate' as GetCertificate:qword
;    extrn '__imp_GetCertificateByHandle' as GetCertificateByHandle:qword
;    extrn '__imp_GetCertificateSizeByHandle' as GetCertificateSizeByHandle:qword
;    extrn '__imp_GetCurrentDpiInfo' as GetCurrentDpiInfo:qword
;    extrn '__imp_GetFontFileData' as GetFontFileData:qword
;    extrn '__imp_GetFontFileInfo' as GetFontFileInfo:qword
;    extrn '__imp_GetFontRealizationInfo' as GetFontRealizationInfo:qword
;    extrn '__imp_GetRelAbs' as GetRelAbs:qword
;    extrn '__imp_GetStringBitmapA' as GetStringBitmapA:qword
;    extrn '__imp_GetStringBitmapW' as GetStringBitmapW:qword
;    extrn '__imp_GetTransform' as GetTransform:qword
;    extrn '__imp_LpkDrawTextEx' as LpkDrawTextEx:qword
;    extrn '__imp_LpkEditControl' as LpkEditControl:qword
;    extrn '__imp_LpkExtTextOut' as LpkExtTextOut:qword
;    extrn '__imp_LpkGetCharacterPlacement' as LpkGetCharacterPlacement:qword
;    extrn '__imp_LpkGetTextExtentExPoint' as LpkGetTextExtentExPoint:qword
;    extrn '__imp_LpkInitialize' as LpkInitialize:qword
;    extrn '__imp_LpkPSMTextOut' as LpkPSMTextOut:qword
;    extrn '__imp_LpkPresent' as LpkPresent:qword
;    extrn '__imp_LpkTabbedTextOut' as LpkTabbedTextOut:qword
;    extrn '__imp_LpkUseGDIWidthCache' as LpkUseGDIWidthCache:qword
;    extrn '__imp_NamedEscape' as NamedEscape:qword
;    extrn '__imp_RemoveFontResourceTracking' as RemoveFontResourceTracking:qword
;    extrn '__imp_SetBrushAttributes' as SetBrushAttributes:qword
;    extrn '__imp_SetRelAbs' as SetRelAbs:qword
;    extrn '__imp_SetVirtualResolution' as SetVirtualResolution:qword
;    extrn '__imp_UnloadNetworkFonts' as UnloadNetworkFonts:qword
;    extrn '__imp_UspAllocCache' as UspAllocCache:qword
;    extrn '__imp_UspAllocTemp' as UspAllocTemp:qword
;    extrn '__imp_UspFreeMem' as UspFreeMem:qword
;    extrn '__imp_bInitSystemAndFontsDirectoriesW' as bInitSystemAndFontsDirectoriesW:qword
;    extrn '__imp_bMakePathNameW' as bMakePathNameW:qword
;    extrn '__imp_cGetTTFFromFOT' as cGetTTFFromFOT:qword
;    extrn '__imp_pfnRealizePalette' as pfnRealizePalette:qword
;    extrn '__imp_pfnSelectPalette' as pfnSelectPalette:qword
;else
;    extrn '__imp__AddFontResourceTracking@??' as AddFontResourceTracking:dword
;    extrn '__imp__AnyLinkedFonts@??' as AnyLinkedFonts:dword
;    extrn '__imp__BeginGdiRendering@??' as AnyLinkedFonts:dword
;    extrn '__imp__ClearBitmapAttributes@??' as ClearBitmapAttributes:dword
;    extrn '__imp__ClearBrushAttributes@??' as ClearBrushAttributes:dword
;    extrn '__imp__CreateBitmapFromDxSurface@??' as CreateBitmapFromDxSurface:dword
;    extrn '__imp__CreateBitmapFromDxSurface2@??' as CreateBitmapFromDxSurface2:dword
;    extrn '__imp__CreateSessionMappedDIBSection@??' as CreateSessionMappedDIBSection:dword
;    extrn '__imp__D3DKMTAbandonSwapChain@??' as D3DKMTAbandonSwapChain:dword
;    extrn '__imp__D3DKMTAcquireSwapChain@??' as D3DKMTAcquireSwapChain:dword
;    extrn '__imp__D3DKMTAdjustFullscreenGamma@??' as D3DKMTAdjustFullscreenGamma:dword
;    extrn '__imp__D3DKMTCacheHybridQueryValue@??' as D3DKMTCacheHybridQueryValue:dword
;    extrn '__imp__D3DKMTChangeVideoMemoryReservation@??' as D3DKMTChangeVideoMemoryReservation:dword
;    extrn '__imp__D3DKMTCreateSwapChain@??' as D3DKMTCreateSwapChain:dword
;    extrn '__imp__D3DKMTEnumAdapters2@??' as D3DKMTEnumAdapters2:dword
;    extrn '__imp__D3DKMTFlushHeapTransitions@??' as D3DKMTFlushHeapTransitions:dword
;    extrn '__imp__D3DKMTGetCachedHybridQueryValue@??' as D3DKMTGetCachedHybridQueryValue:dword
;    extrn '__imp__D3DKMTGetDWMVerticalBlankEvent@??' as D3DKMTGetDWMVerticalBlankEvent:dword
;    extrn '__imp__D3DKMTGetPresentQueueEvent@??' as D3DKMTGetPresentQueueEvent:dword
;    extrn '__imp__D3DKMTGetResourcePresentPrivateDriverData@??' as D3DKMTGetResourcePresentPrivateDriverData:dword
;    extrn '__imp__D3DKMTGetSetSwapChainMetadata@??' as D3DKMTGetSetSwapChainMetadata:dword
;    extrn '__imp__D3DKMTInvalidateCache@??' as D3DKMTInvalidateCache:dword
;    extrn '__imp__D3DKMTMarkDeviceAsError@??' as D3DKMTMarkDeviceAsError:dword
;    extrn '__imp__D3DKMTNetDispGetNextChunkInfo@??' as D3DKMTNetDispGetNextChunkInfo:dword
;    extrn '__imp__D3DKMTNetDispQueryMiracastDisplayDeviceStatus@??' as D3DKMTNetDispQueryMiracastDisplayDeviceStatus:dword
;    extrn '__imp__D3DKMTNetDispQueryMiracastDisplayDeviceSupport@??' as D3DKMTNetDispQueryMiracastDisplayDeviceSupport:dword
;    extrn '__imp__D3DKMTNetDispStartMiracastDisplayDevice@??' as D3DKMTNetDispStartMiracastDisplayDevice:dword
;    extrn '__imp__D3DKMTNetDispStartMiracastDisplayDevice2@??' as D3DKMTNetDispStartMiracastDisplayDevice2:dword
;    extrn '__imp__D3DKMTNetDispStartMiracastDisplayDeviceEx@??' as D3DKMTNetDispStartMiracastDisplayDeviceEx:dword
;    extrn '__imp__D3DKMTNetDispStopMiracastDisplayDevice@??' as D3DKMTNetDispStopMiracastDisplayDevice:dword
;    extrn '__imp__D3DKMTNetDispStopSessions@??' as D3DKMTNetDispStopSessions:dword
;    extrn '__imp__D3DKMTOpenSwapChain@??' as D3DKMTOpenSwapChain:dword
;    extrn '__imp__D3DKMTPresentMultiPlaneOverlay2@??' as D3DKMTPresentMultiPlaneOverlay2:dword
;    extrn '__imp__D3DKMTQueryClockCalibration@??' as D3DKMTQueryClockCalibration:dword
;    extrn '__imp__D3DKMTQueryStatistics@??' as D3DKMTQueryStatistics:dword
;    extrn '__imp__D3DKMTQueryVideoMemoryInfo@??' as D3DKMTQueryVideoMemoryInfo:dword
;    extrn '__imp__D3DKMTQueryVidPnExclusiveOwnership@??' as D3DKMTQueryVidPnExclusiveOwnership:dword
;    extrn '__imp__D3DKMTReleaseSwapChain@??' as D3DKMTReleaseSwapChain:dword
;    extrn '__imp__D3DKMTSetDodIndirectSwapchain@??' as D3DKMTSetDodIndirectSwapchain:dword
;    extrn '__imp__D3DKMTSetHwProtectionTeardownRecovery@??' as D3DKMTSetHwProtectionTeardownRecovery:dword
;    extrn '__imp__D3DKMTSetStablePowerState@??' as D3DKMTSetStablePowerState:dword
;    extrn '__imp__D3DKMTSetSyncRefreshCountWaitTarget@??' as D3DKMTSetSyncRefreshCountWaitTarget:dword
;    extrn '__imp__D3DKMTSetVidPnSourceHwProtection@??' as D3DKMTSetVidPnSourceHwProtection:dword
;    extrn '__imp__DdCreateFullscreenSprite@??' as DdCreateFullscreenSprite:dword
;    extrn '__imp__DdDestroyFullscreenSprite@??' as DdDestroyFullscreenSprite:dword
;    extrn '__imp__DdEntry0@??' as DdEntry0:dword
;    extrn '__imp__DdEntry1@??' as DdEntry1:dword
;    extrn '__imp__DdEntry10@??' as DdEntry10:dword
;    extrn '__imp__DdEntry11@??' as DdEntry11:dword
;    extrn '__imp__DdEntry12@??' as DdEntry12:dword
;    extrn '__imp__DdEntry13@??' as DdEntry13:dword
;    extrn '__imp__DdEntry14@??' as DdEntry14:dword
;    extrn '__imp__DdEntry15@??' as DdEntry15:dword
;    extrn '__imp__DdEntry16@??' as DdEntry16:dword
;    extrn '__imp__DdEntry17@??' as DdEntry17:dword
;    extrn '__imp__DdEntry18@??' as DdEntry18:dword
;    extrn '__imp__DdEntry19@??' as DdEntry19:dword
;    extrn '__imp__DdEntry2@??' as DdEntry2:dword
;    extrn '__imp__DdEntry20@??' as DdEntry20:dword
;    extrn '__imp__DdEntry21@??' as DdEntry21:dword
;    extrn '__imp__DdEntry22@??' as DdEntry22:dword
;    extrn '__imp__DdEntry23@??' as DdEntry23:dword
;    extrn '__imp__DdEntry24@??' as DdEntry24:dword
;    extrn '__imp__DdEntry25@??' as DdEntry25:dword
;    extrn '__imp__DdEntry26@??' as DdEntry26:dword
;    extrn '__imp__DdEntry27@??' as DdEntry27:dword
;    extrn '__imp__DdEntry28@??' as DdEntry28:dword
;    extrn '__imp__DdEntry29@??' as DdEntry29:dword
;    extrn '__imp__DdEntry3@??' as DdEntry3:dword
;    extrn '__imp__DdEntry30@??' as DdEntry30:dword
;    extrn '__imp__DdEntry31@??' as DdEntry31:dword
;    extrn '__imp__DdEntry32@??' as DdEntry32:dword
;    extrn '__imp__DdEntry33@??' as DdEntry33:dword
;    extrn '__imp__DdEntry34@??' as DdEntry34:dword
;    extrn '__imp__DdEntry35@??' as DdEntry35:dword
;    extrn '__imp__DdEntry36@??' as DdEntry36:dword
;    extrn '__imp__DdEntry37@??' as DdEntry37:dword
;    extrn '__imp__DdEntry38@??' as DdEntry38:dword
;    extrn '__imp__DdEntry39@??' as DdEntry39:dword
;    extrn '__imp__DdEntry4@??' as DdEntry4:dword
;    extrn '__imp__DdEntry40@??' as DdEntry40:dword
;    extrn '__imp__DdEntry41@??' as DdEntry41:dword
;    extrn '__imp__DdEntry42@??' as DdEntry42:dword
;    extrn '__imp__DdEntry43@??' as DdEntry43:dword
;    extrn '__imp__DdEntry44@??' as DdEntry44:dword
;    extrn '__imp__DdEntry45@??' as DdEntry45:dword
;    extrn '__imp__DdEntry46@??' as DdEntry46:dword
;    extrn '__imp__DdEntry47@??' as DdEntry47:dword
;    extrn '__imp__DdEntry48@??' as DdEntry48:dword
;    extrn '__imp__DdEntry49@??' as DdEntry49:dword
;    extrn '__imp__DdEntry5@??' as DdEntry5:dword
;    extrn '__imp__DdEntry50@??' as DdEntry50:dword
;    extrn '__imp__DdEntry51@??' as DdEntry51:dword
;    extrn '__imp__DdEntry52@??' as DdEntry52:dword
;    extrn '__imp__DdEntry53@??' as DdEntry53:dword
;    extrn '__imp__DdEntry54@??' as DdEntry54:dword
;    extrn '__imp__DdEntry55@??' as DdEntry55:dword
;    extrn '__imp__DdEntry56@??' as DdEntry56:dword
;    extrn '__imp__DdEntry6@??' as DdEntry6:dword
;    extrn '__imp__DdEntry7@??' as DdEntry7:dword
;    extrn '__imp__DdEntry8@??' as DdEntry8:dword
;    extrn '__imp__DdEntry9@??' as DdEntry9:dword
;    extrn '__imp__DdNotifyFullscreenSpriteUpdate@??' as DdNotifyFullscreenSpriteUpdate:dword
;    extrn '__imp__DdQueryVisRgnUniqueness@??' as DdQueryVisRgnUniqueness:dword
;    extrn '__imp__DwmGetDirtyRgn@??' as DwmGetDirtyRgn:dword
;    extrn '__imp__DwmGetSurfaceData@??' as DwmGetSurfaceData:dword
;    extrn '__imp__EndFormPage@??' as EndFormPage:dword
;    extrn '__imp__EndGdiRendering@??' as EndGdiRendering:dword
;    extrn '__imp__EngQueryEMFInfo@??' as EngQueryEMFInfo:dword
;    extrn '__imp__EudcLoadLinkW@??' as EudcLoadLinkW:dword
;    extrn '__imp__EudcUnloadLinkW@??' as EudcUnloadLinkW:dword
;    extrn '__imp__FontIsLinked@??' as FontIsLinked:dword
;    extrn '__imp__ftsWordBreak@??' as ftsWordBreak:dword
;    extrn '__imp__GdiAddGlsRecord@??' as GdiAddGlsRecord:dword
;    extrn '__imp__GdiClearStockObjectCache@??' as GdiClearStockObjectCache:dword
;    extrn '__imp__GdiConvertMetaFilePict@??' as GdiConvertMetaFilePict:dword
;    extrn '__imp__GdiConvertToDevmodeW@??' as GdiConvertToDevmodeW:dword
;    extrn '__imp__GdiCreateLocalEnhMetaFile@??' as GdiCreateLocalEnhMetaFile:dword
;    extrn '__imp__GdiCreateLocalMetaFilePict@??' as GdiCreateLocalMetaFilePict:dword
;    extrn '__imp__GdiDrawStream@??' as GdiDrawStream:dword
;    extrn '__imp__GdiIsUMPDSandboxingEnabled@??' as GdiIsUMPDSandboxingEnabled:dword
;    extrn '__imp__GdiEntry1@??' as GdiEntry1:dword
;    extrn '__imp__GdiEntry10@??' as GdiEntry10:dword
;    extrn '__imp__GdiEntry11@??' as GdiEntry11:dword
;    extrn '__imp__GdiEntry12@??' as GdiEntry12:dword
;    extrn '__imp__GdiEntry13@??' as GdiEntry13:dword
;    extrn '__imp__GdiEntry14@??' as GdiEntry14:dword
;    extrn '__imp__GdiEntry15@??' as GdiEntry15:dword
;    extrn '__imp__GdiEntry16@??' as GdiEntry16:dword
;    extrn '__imp__GdiEntry2@??' as GdiEntry2:dword
;    extrn '__imp__GdiEntry3@??' as GdiEntry3:dword
;    extrn '__imp__GdiEntry4@??' as GdiEntry4:dword
;    extrn '__imp__GdiEntry5@??' as GdiEntry5:dword
;    extrn '__imp__GdiEntry6@??' as GdiEntry6:dword
;    extrn '__imp__GdiEntry7@??' as GdiEntry7:dword
;    extrn '__imp__GdiEntry8@??' as GdiEntry8:dword
;    extrn '__imp__GdiEntry9@??' as GdiEntry9:dword
;    extrn '__imp__GdiLoadType1Fonts@??' as GdiLoadType1Fonts:dword
;    extrn '__imp__GdiPlayPrivatePageEMF@??' as GdiPlayPrivatePageEMF:dword
;    extrn '__imp__GdiSupportsFontChangeEvent@??' as GdiSupportsFontChangeEvent:dword
;    extrn '__imp__GdiSwapBuffers@??' as GdiSwapBuffers:dword
;    extrn '__imp__GetBitmapAttributes@??' as GetBitmapAttributes:dword
;    extrn '__imp__GetCertificate@??' as GetCertificate:dword
;    extrn '__imp__GetCertificateByHandle@??' as GetCertificateByHandle:dword
;    extrn '__imp__GetCertificateSizeByHandle@??' as GetCertificateSizeByHandle:dword
;    extrn '__imp__GetCurrentDpiInfo@??' as GetCurrentDpiInfo:dword
;    extrn '__imp__GetFontFileData@??' as GetFontFileData:dword
;    extrn '__imp__GetFontFileInfo@??' as GetFontFileInfo:dword
;    extrn '__imp__GetFontRealizationInfo@??' as GetFontRealizationInfo:dword
;    extrn '__imp__GetRelAbs@??' as GetRelAbs:dword
;    extrn '__imp__GetStringBitmapA@??' as GetStringBitmapA:dword
;    extrn '__imp__GetStringBitmapW@??' as GetStringBitmapW:dword
;    extrn '__imp__GetTransform@??' as GetTransform:dword
;    extrn '__imp__LpkDrawTextEx@??' as LpkDrawTextEx:dword
;    extrn '__imp__LpkEditControl@??' as LpkEditControl:dword
;    extrn '__imp__LpkExtTextOut@??' as LpkExtTextOut:dword
;    extrn '__imp__LpkGetCharacterPlacement@??' as LpkGetCharacterPlacement:dword
;    extrn '__imp__LpkGetTextExtentExPoint@??' as LpkGetTextExtentExPoint:dword
;    extrn '__imp__LpkInitialize@??' as LpkInitialize:dword
;    extrn '__imp__LpkPSMTextOut@??' as LpkPSMTextOut:dword
;    extrn '__imp__LpkPresent@??' as LpkPresent:dword
;    extrn '__imp__LpkTabbedTextOut@??' as LpkTabbedTextOut:dword
;    extrn '__imp__LpkUseGDIWidthCache@??' as LpkUseGDIWidthCache:dword
;    extrn '__imp__NamedEscape@??' as NamedEscape:dword
;    extrn '__imp__RemoveFontResourceTracking@??' as RemoveFontResourceTracking:dword
;    extrn '__imp__SetBrushAttributes@??' as SetBrushAttributes:dword
;    extrn '__imp__SetRelAbs@??' as SetRelAbs:dword
;    extrn '__imp__SetVirtualResolution@??' as SetVirtualResolution:dword
;    extrn '__imp__UnloadNetworkFonts@??' as UnloadNetworkFonts:dword
;    extrn '__imp__UspAllocCache@??' as UspAllocCache:dword
;    extrn '__imp__UspAllocTemp@??' as UspAllocTemp:dword
;    extrn '__imp__UspFreeMem@??' as UspFreeMem:dword
;    extrn '__imp__bInitSystemAndFontsDirectoriesW@??' as bInitSystemAndFontsDirectoriesW:dword
;    extrn '__imp__bMakePathNameW@??' as bMakePathNameW:dword
;    extrn '__imp__cGetTTFFromFOT@??' as cGetTTFFromFOT:dword
;    extrn '__imp__pfnRealizePalette@??' as pfnRealizePalette:dword
;    extrn '__imp__pfnSelectPalette@??' as pfnSelectPalette:dword
;end if

;api GetStringBitmap

end if ;GDI32_INC
