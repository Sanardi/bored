; ====================================================;
;                                                     ;
;    gdiplus.inc for EC v2 SolAsm classic projects    ;
;                   (version 1.0.0)                   ;
;                                                     ;
;            Copyright © Ramon Sala - 2019            ;
;                                                     ;
; ====================================================;

#ifndef GDIPLUS_INC
GDIPLUS_INC equ 1

AlphaShift                                      equ     24
RedShift                                        equ     16
GreenShift                                      equ     8
BlueShift                                       equ     0
AlphaMask                                       equ     0FF000000H
RedMask                                         equ     000FF0000H
GreenMask                                       equ     00000FF00H
BlueMask                                        equ     0000000FFH

ImageLockModeRead                               equ     1
ImageLockModeWrite                              equ     2
ImageLockModeReadWrite                          equ     3
ImageLockModeUserInputBuf                       equ     4

PixelFormat1bppIndexed                          equ     30101H
PixelFormat4bppIndexed                          equ     30402H
PixelFormat8bppIndexed                          equ     30803H
PixelFormat16bppGreyScale                       equ     101004H
PixelFormat16bppRGB555                          equ     21005H
PixelFormat16bppRGB565                          equ     21006H
PixelFormat16bppARGB1555                        equ     61007H
PixelFormat24bppRGB                             equ     21808H
PixelFormat32bppRGB                             equ     22009
PixelFormat32bppARGB                            equ     26200AH
PixelFormat32bppPARGB                           equ     0E200BH
PixelFormat48bppRGB                             equ     10300CH
PixelFormat64bppARGB                            equ     34400DH
PixelFormat64bppPARGB                           equ     1C400EH
PixelFormatMax                                  equ     0FH

PropertyTagTypeByte                             equ     1
PropertyTagTypeASCII                            equ     2
PropertyTagTypeShort                            equ     3
PropertyTagTypeLong                             equ     4
PropertyTagTypeRational                         equ     5
PropertyTagTypeUndefined                        equ     7
PropertyTagTypeSLONG                            equ     9
PropertyTagTypeSRational                        equ     10

PropertyTagExifIFD                              equ     8769H
PropertyTagGpsIFD                               equ     8825H

PropertyTagNewSubfileType                       equ     0FEH
PropertyTagSubfileType                          equ     0FFH
PropertyTagImageWidth                           equ     100H
PropertyTagImageHeight                          equ     101H
PropertyTagBitsPerSample                        equ     102H
PropertyTagCompression                          equ     103H
PropertyTagPhotometricInterp                    equ     106H
PropertyTagThreshHolding                        equ     107H
PropertyTagCellWidth                            equ     108H
PropertyTagCellHeight                           equ     109H
PropertyTagFillOrder                            equ     10AH
PropertyTagDocumentName                         equ     10DH
PropertyTagImageDescription                     equ     10EH
PropertyTagEquipMake                            equ     10FH
PropertyTagEquipModel                           equ     110H
PropertyTagStripOffsets                         equ     111H
PropertyTagOrientation                          equ     112H
PropertyTagSamplesPerPixel                      equ     115H
PropertyTagRowsPerStrip                         equ     116H
PropertyTagStripBytesCount                      equ     117H
PropertyTagMinSampleValue                       equ     118H
PropertyTagMaxSampleValue                       equ     119H
PropertyTagXResolution                          equ     11AH
PropertyTagYResolution                          equ     11BH
PropertyTagPlanarConfig                         equ     11CH
PropertyTagPageName                             equ     11DH
PropertyTagXPosition                            equ     11EH
PropertyTagYPosition                            equ     11FH
PropertyTagFreeOffset                           equ     120H
PropertyTagFreeByteCounts                       equ     121H
PropertyTagGrayResponseUnit                     equ     122H
PropertyTagGrayResponseCurve                    equ     123H
PropertyTagT4Option                             equ     124H
PropertyTagT6Option                             equ     125H
PropertyTagResolutionUnit                       equ     128H
PropertyTagPageNumber                           equ     129H
PropertyTagTransferFuncition                    equ     12DH
PropertyTagSoftwareUsed                         equ     131H
PropertyTagDateTime                             equ     132H
PropertyTagArtist                               equ     13BH
PropertyTagHostComputer                         equ     13CH
PropertyTagPredictor                            equ     13DH
PropertyTagWhitePoint                           equ     13EH
PropertyTagPrimaryChromaticities                equ     13FH
PropertyTagColorMap                             equ     140H
PropertyTagHalftoneHints                        equ     141H
PropertyTagTileWidth                            equ     142H
PropertyTagTileLength                           equ     143H
PropertyTagTileOffset                           equ     144H
PropertyTagTileByteCounts                       equ     145H
PropertyTagInkSet                               equ     14CH
PropertyTagInkNames                             equ     14DH
PropertyTagNumberOfInks                         equ     14EH
PropertyTagDotRange                             equ     150H
PropertyTagTargetPrinter                        equ     151H
PropertyTagExtraSamples                         equ     152H
PropertyTagSampleFormat                         equ     153H
PropertyTagSMinSampleValue                      equ     154H
PropertyTagSMaxSampleValue                      equ     155H
PropertyTagTransferRange                        equ     156H

PropertyTagJPEGProc                             equ     200H
PropertyTagJPEGInterFormat                      equ     201H
PropertyTagJPEGInterLength                      equ     202H
PropertyTagJPEGRestartInterval                  equ     203H
PropertyTagJPEGLosslessPredictors               equ     205H
PropertyTagJPEGPointTransforms                  equ     206H
PropertyTagJPEGQTables                          equ     207H
PropertyTagJPEGDCTables                         equ     208H
PropertyTagJPEGACTables                         equ     209H
PropertyTagYCbCrCoefficients                    equ     211H
PropertyTagYCbCrSubsampling                     equ     212H
PropertyTagYCbCrPositioning                     equ     213H
PropertyTagREFBlackWhite                        equ     214H
PropertyTagICCProfile                           equ     8773H
PropertyTagGamma                                equ     301H
PropertyTagICCProfileDescriptor                 equ     302H
PropertyTagSRGBRenderingIntent                  equ     303H
PropertyTagImageTitle                           equ     320H
PropertyTagCopyright                            equ     8298H

PropertyTagResolutionXUnit                      equ     5001H
PropertyTagResolutionYUnit                      equ     5002H
PropertyTagResolutionXLengthUnit                equ     5003H
PropertyTagResolutionYLengthUnit                equ     5004H
PropertyTagPrintFlags                           equ     5005H
PropertyTagPrintFlagsVersion                    equ     5006H
PropertyTagPrintFlagsCrop                       equ     5007H
PropertyTagPrintFlagsBleedWidth                 equ     5008H
PropertyTagPrintFlagsBleedWidthScale            equ     5009H
PropertyTagHalftoneLPI                          equ     500AH
PropertyTagHalftoneLPIUnit                      equ     500BH
PropertyTagHalftoneDegree                       equ     500CH
PropertyTagHalftoneShape                        equ     500DH
PropertyTagHalftoneMisc                         equ     500EH
PropertyTagHalftoneScreen                       equ     500FH
PropertyTagJPEGQuality                          equ     5010H
PropertyTagGridSize                             equ     5011H
PropertyTagThumbnailFormat                      equ     5012H
PropertyTagThumbnailWidth                       equ     5013H
PropertyTagThumbnailHeight                      equ     5014H
PropertyTagThumbnailColorDepth                  equ     5015H
PropertyTagThumbnailPlanes                      equ     5016H
PropertyTagThumbnailRawBytes                    equ     5017H
PropertyTagThumbnailSize                        equ     5018H
PropertyTagThumbnailCompressedSize              equ     5019H
PropertyTagColorTransferFunction                equ     501AH
PropertyTagThumbnailData                        equ     501BH

PropertyTagThumbnailImageWidth                  equ     5020H
PropertyTagThumbnailImageHeight                 equ     5021H
PropertyTagThumbnailBitsPerSample               equ     5022H
PropertyTagThumbnailCompression                 equ     5023H
PropertyTagThumbnailPhotometricInterp           equ     5024H
PropertyTagThumbnailImageDescription            equ     5025H
PropertyTagThumbnailEquipMake                   equ     5026H
PropertyTagThumbnailEquipModel                  equ     5027H
PropertyTagThumbnailStripOffsets                equ     5028H
PropertyTagThumbnailOrientation                 equ     5029H
PropertyTagThumbnailSamplesPerPixel             equ     502AH
PropertyTagThumbnailRowsPerStrip                equ     502BH
PropertyTagThumbnailStripBytesCount             equ     502CH
PropertyTagThumbnailResolutionX                 equ     502DH
PropertyTagThumbnailResolutionY                 equ     502EH
PropertyTagThumbnailPlanarConfig                equ     502FH
PropertyTagThumbnailResolutionUnit              equ     5030H
PropertyTagThumbnailTransferFunction            equ     5031H
PropertyTagThumbnailSoftwareUsed                equ     5032H
PropertyTagThumbnailDateTime                    equ     5033H
PropertyTagThumbnailArtist                      equ     5034H
PropertyTagThumbnailWhitePoint                  equ     5035H
PropertyTagThumbnailPrimaryChromaticities       equ     5036H
PropertyTagThumbnailYCbCrCoefficients           equ     5037H
PropertyTagThumbnailYCbCrSubsampling            equ     5038H
PropertyTagThumbnailYCbCrPositioning            equ     5039H
PropertyTagThumbnailRefBlackWhite               equ     503AH
PropertyTagThumbnailCopyRight                   equ     503BH
PropertyTagLuminanceTable                       equ     5090H
PropertyTagChrominanceTable                     equ     5091H
PropertyTagFrameDelay                           equ     5100H
PropertyTagLoopCount                            equ     5101H
PropertyTagPixelUnit                            equ     5110H
PropertyTagPixelPerUnitX                        equ     5111H
PropertyTagPixelPerUnitY                        equ     5112H
PropertyTagPaletteHistogram                     equ     5113H

PropertyTagExifExposureTime                     equ     829AH
PropertyTagExifFNumber                          equ     829DH
PropertyTagExifExposureProg                     equ     8822H
PropertyTagExifSpectralSense                    equ     8824H
PropertyTagExifISOSpeed                         equ     8827H
PropertyTagExifOECF                             equ     8828H
PropertyTagExifVer                              equ     9000H
PropertyTagExifDTOrig                           equ     9003H
PropertyTagExifDTDigitized                      equ     9004H
PropertyTagExifCompConfig                       equ     9101H
PropertyTagExifCompBPP                          equ     9102H
PropertyTagExifShutterSpeed                     equ     9201H
PropertyTagExifAperture                         equ     9202H
PropertyTagExifBrightness                       equ     9203H
PropertyTagExifExposureBias                     equ     9204H
PropertyTagExifMaxAperture                      equ     9205H
PropertyTagExifSubjectDist                      equ     9206H
PropertyTagExifMeteringMode                     equ     9207H
PropertyTagExifLightSource                      equ     9208H
PropertyTagExifFlash                            equ     9209H
PropertyTagExifFocalLength                      equ     920AH
PropertyTagExifMakerNote                        equ     927CH
PropertyTagExifUserComment                      equ     9286H
PropertyTagExifDTSubsec                         equ     9290H
PropertyTagExifDTOrigSS                         equ     9291H
PropertyTagExifDTDigSS                          equ     9292H
PropertyTagExifFPXVer                           equ     0A000H
PropertyTagExifColorSpace                       equ     0A001H
PropertyTagExifPixXDim                          equ     0A002H
PropertyTagExifPixYDim                          equ     0A003H
PropertyTagExifRelatedWav                       equ     0A004H
PropertyTagExifInterop                          equ     0A005H
PropertyTagExifFlashEnergy                      equ     0A20BH
PropertyTagExifSpatialFR                        equ     0A20CH
PropertyTagExifFocalXRes                        equ     0A20EH
PropertyTagExifFocalYRes                        equ     0A20FH
PropertyTagExifFocalResUnit                     equ     0A210H
PropertyTagExifSubjectLoc                       equ     0A214H
PropertyTagExifExposureIndex                    equ     0A215H
PropertyTagExifSensingMethod                    equ     0A217H
PropertyTagExifFileSource                       equ     0A300H
PropertyTagExifSceneType                        equ     0A301H
PropertyTagExifCfaPattern                       equ     0A302H
PropertyTagGpsVer                               equ     0
PropertyTagGpsLatitudeRef                       equ     1
PropertyTagGpsLatitude                          equ     2
PropertyTagGpsLongitudeRef                      equ     3
PropertyTagGpsLongitude                         equ     4
PropertyTagGpsAltitudeRef                       equ     5
PropertyTagGpsAltitude                          equ     6
PropertyTagGpsGpsTime                           equ     7
PropertyTagGpsGpsSatellites                     equ     8
PropertyTagGpsGpsStatus                         equ     9
PropertyTagGpsGpsMeasureMode                    equ     0AH
PropertyTagGpsGpsDop                            equ     0BH
PropertyTagGpsSpeedRef                          equ     0CH
PropertyTagGpsSpeed                             equ     0DH
PropertyTagGpsTrackRef                          equ     0EH
PropertyTagGpsTrack                             equ     0FH
PropertyTagGpsImgDirRef                         equ     10H
PropertyTagGpsImgDir                            equ     11H
PropertyTagGpsMapDatum                          equ     12H
PropertyTagGpsDestLatRef                        equ     13H
PropertyTagGpsDestLat                           equ     14H
PropertyTagGpsDestLongRef                       equ     15H
PropertyTagGpsDestLong                          equ     16H
PropertyTagGpsDestBearRef                       equ     17H
PropertyTagGpsDestBear                          equ     18H
PropertyTagGpsDestDistRef                       equ     19H
PropertyTagGpsDestDist                          equ     1AH

UnitWorld                                       equ     0
UnitDisplay                                     equ     1
UnitPixel                                       equ     2
UnitPoint                                       equ     3
UnitInch                                        equ     4
UnitDocument                                    equ     5
UnitMillimeter                                  equ     6

ColorsAliceBlue                                 equ     0FFF0F8FFH
ColorsAntiqueWhite                              equ     0FFFAEBD7H
ColorsAqua                                      equ     0FF00FFFFH
ColorsAquamarine                                equ     0FF7FFFD4H
ColorsAzure                                     equ     0FFF0FFFFH
ColorsBeige                                     equ     0FFF5F5DCH
ColorsBisque                                    equ     0FFFFE4C4H
ColorsBlack                                     equ     0FF000000H
ColorsBlanchedAlmond                            equ     0FFFFEBCDH
ColorsBlue                                      equ     0FF0000FFH
ColorsBlueViolet                                equ     0FF8A2BE2H
ColorsBrown                                     equ     0FFA52A2AH
ColorsBurlyWood                                 equ     0FFDEB887H
ColorsCadetBlue                                 equ     0FF5F9EA0H
ColorsChartreuse                                equ     0FF7FFF00H
ColorsChocolate                                 equ     0FFD2691EH
ColorsCoral                                     equ     0FFFF7F50H
ColorsCornflowerBlue                            equ     0FF6495EDH
ColorsCornsilk                                  equ     0FFFFF8DCH
ColorsCrimson                                   equ     0FFDC143CH
ColorsCyan                                      equ     0FF00FFFFH
ColorsDarkBlue                                  equ     0FF00008BH
ColorsDarkCyan                                  equ     0FF008B8BH
ColorsDarkGoldenrod                             equ     0FFB8860BH
ColorsDarkGray                                  equ     0FFA9A9A9H
ColorsDarkGreen                                 equ     0FF006400H
ColorsDarkKhaki                                 equ     0FFBDB76BH
ColorsDarkMagenta                               equ     0FF8B008BH
ColorsDarkOliveGreen                            equ     0FF556B2FH
ColorsDarkOrange                                equ     0FFFF8C00H
ColorsDarkOrchid                                equ     0FF9932CCH
ColorsDarkRed                                   equ     0FF8B0000H
ColorsDarkSalmon                                equ     0FFE9967AH
ColorsDarkSeaGreen                              equ     0FF8FBC8BH
ColorsDarkSlateBlue                             equ     0FF483D8BH
ColorsDarkSlateGray                             equ     0FF2F4F4FH
ColorsDarkTurquoise                             equ     0FF00CED1H
ColorsDarkViolet                                equ     0FF9400D3H
ColorsDeepPink                                  equ     0FFFF1493H
ColorsDeepSkyBlue                               equ     0FF00BFFFH
ColorsDimGray                                   equ     0FF696969H
ColorsDodgerBlue                                equ     0FF1E90FFH
ColorsFirebrick                                 equ     0FFB22222H
ColorsFloralWhite                               equ     0FFFFFAF0H
ColorsForestGreen                               equ     0FF228B22H
ColorsFuchsia                                   equ     0FFFF00FFH
ColorsGainsboro                                 equ     0FFDCDCDCH
ColorsGhostWhite                                equ     0FFF8F8FFH
ColorsGold                                      equ     0FFFFD700H
ColorsGoldenrod                                 equ     0FFDAA520H
ColorsGray                                      equ     0FF808080H
ColorsGreen                                     equ     0FF008000H
ColorsGreenYellow                               equ     0FFADFF2FH
ColorsHoneydew                                  equ     0FFF0FFF0H
ColorsHotPink                                   equ     0FFFF69B4H
ColorsIndianRed                                 equ     0FFCD5C5CH
ColorsIndigo                                    equ     0FF4B0082H
ColorsIvory                                     equ     0FFFFFFF0H
ColorsKhaki                                     equ     0FFF0E68CH
ColorsLavender                                  equ     0FFE6E6FAH
ColorsLavenderBlush                             equ     0FFFFF0F5H
ColorsLawnGreen                                 equ     0FF7CFC00H
ColorsLemonChiffon                              equ     0FFFFFACDH
ColorsLightBlue                                 equ     0FFADD8E6H
ColorsLightCoral                                equ     0FFF08080H
ColorsLightCyan                                 equ     0FFE0FFFFH
ColorsLightGoldenrodYellow                      equ     0FFFAFAD2H
ColorsLightGray                                 equ     0FFD3D3D3H
ColorsLightGreen                                equ     0FF90EE90H
ColorsLightPink                                 equ     0FFFFB6C1H
ColorsLightSalmon                               equ     0FFFFA07AH
ColorsLightSeaGreen                             equ     0FF20B2AAH
ColorsLightSkyBlue                              equ     0FF87CEFAH
ColorsLightSlateGray                            equ     0FF778899H
ColorsLightSteelBlue                            equ     0FFB0C4DEH
ColorsLightYellow                               equ     0FFFFFFE0H
ColorsLime                                      equ     0FF00FF00H
ColorsLimeGreen                                 equ     0FF32CD32H
ColorsLinen                                     equ     0FFFAF0E6H
ColorsMagenta                                   equ     0FFFF00FFH
ColorsMaroon                                    equ     0FF800000H
ColorsMediumAquamarine                          equ     0FF66CDAAH
ColorsMediumBlue                                equ     0FF0000CDH
ColorsMediumOrchid                              equ     0FFBA55D3H
ColorsMediumPurple                              equ     0FF9370DBH
ColorsMediumSeaGreen                            equ     0FF3CB371H
ColorsMediumSlateBlue                           equ     0FF7B68EEH
ColorsMediumSpringGreen                         equ     0FF00FA9AH
ColorsMediumTurquoise                           equ     0FF48D1CCH
ColorsMediumVioletRed                           equ     0FFC71585H
ColorsMidnightBlue                              equ     0FF191970H
ColorsMintCream                                 equ     0FFF5FFFAH
ColorsMistyRose                                 equ     0FFFFE4E1H
ColorsMoccasin                                  equ     0FFFFE4B5H
ColorsNavajoWhite                               equ     0FFFFDEADH
ColorsNavy                                      equ     0FF000080H
ColorsOldLace                                   equ     0FFFDF5E6H
ColorsOlive                                     equ     0FF808000H
ColorsOliveDrab                                 equ     0FF6B8E23H
ColorsOrange                                    equ     0FFFFA500H
ColorsOrangeRed                                 equ     0FFFF4500H
ColorsOrchid                                    equ     0FFDA70D6H
ColorsPaleGoldenrod                             equ     0FFEEE8AAH
ColorsPaleGreen                                 equ     0FF98FB98H
ColorsPaleTurquoise                             equ     0FFAFEEEEH
ColorsPaleVioletRed                             equ     0FFDB7093H
ColorsPapayaWhip                                equ     0FFFFEFD5H
ColorsPeachPuff                                 equ     0FFFFDAB9H
ColorsPeru                                      equ     0FFCD853FH
ColorsPink                                      equ     0FFFFC0CBH
ColorsPlum                                      equ     0FFDDA0DDH
ColorsPowderBlue                                equ     0FFB0E0E6H
ColorsPurple                                    equ     0FF800080H
ColorsRed                                       equ     0FFFF0000H
ColorsRosyBrown                                 equ     0FFBC8F8FH
ColorsRoyalBlue                                 equ     0FF4169E1H
ColorsSaddleBrown                               equ     0FF8B4513H
ColorsSalmon                                    equ     0FFFA8072H
ColorsSandyBrown                                equ     0FFF4A460H
ColorsSeaGreen                                  equ     0FF2E8B57H
ColorsSeaShell                                  equ     0FFFFF5EEH
ColorsSienna                                    equ     0FFA0522DH
ColorsSilver                                    equ     0FFC0C0C0H
ColorsSkyBlue                                   equ     0FF87CEEBH
ColorsSlateBlue                                 equ     0FF6A5ACDH
ColorsSlateGray                                 equ     0FF708090H
ColorsSnow                                      equ     0FFFFFAFAH
ColorsSpringGreen                               equ     0FF00FF7FH
ColorsSteelBlue                                 equ     0FF4682B4H
ColorsTan                                       equ     0FFD2B48CH
ColorsTeal                                      equ     0FF008080H
ColorsThistle                                   equ     0FFD8BFD8H
ColorsTomato                                    equ     0FFFF6347H
ColorsTransparent                               equ     0FFFFFFH
ColorsTurquoise                                 equ     0FF40E0D0H
ColorsViolet                                    equ     0FFEE82EEH
ColorsWheat                                     equ     0FFF5DEB3H
ColorsWhite                                     equ     0FFFFFFFFH
ColorsWhiteSmoke                                equ     0FFF5F5F5H
ColorsYellow                                    equ     0FFFFFF00H
ColorsYellowGreen                               equ     0FF9ACD32H

GpStatusOk                                      equ     0
GpStatusGenericError                            equ     1
GpStatusInvalidParameter                        equ     2
GpStatusOutOfMemory                             equ     3
GpStatusObjectBusy                              equ     4
GpStatusInsufficientBuffer                      equ     5
GpStatusNotImplemented                          equ     6
GpStatusWin32Error                              equ     7
GpStatusWrongState                              equ     8
GpStatusAborted                                 equ     9
GpStatusFileNotFound                            equ     10
GpStatusValueOverflow                           equ     11
GpStatusAccessDenied                            equ     12
GpStatusUnknownImageFormat                      equ     13
GpStatusFontFamilyNotFound                      equ     14
GpStatusFontStyleNotFound                       equ     15
GpStatusNotTrueTypeFont                         equ     16
GpStatusUnsupportedGdiplusVersion               equ     17
GpStatusGdiplusNotInitialized                   equ     18
GpStatusPropertyNotFound                        equ     19
GpStatusPropertyNotSupported                    equ     20

HatchStyleHorizontal                            equ     0
HatchStyleVertical                              equ     1
HatchStyleForwardDiagonal                       equ     2
HatchStyleBackwardDiagonal                      equ     3
HatchStyleCross                                 equ     4
HatchStyleDiagonalCross                         equ     5
HatchStyle05Percent                             equ     6
HatchStyle10Percent                             equ     7
HatchStyle20Percent                             equ     8
HatchStyle25Percent                             equ     9
HatchStyle30Percent                             equ     10
HatchStyle40Percent                             equ     11
HatchStyle50Percent                             equ     12
HatchStyle60Percent                             equ     13
HatchStyle70Percent                             equ     14
HatchStyle75Percent                             equ     15
HatchStyle80Percent                             equ     16
HatchStyle90Percent                             equ     17
HatchStyleLightDownwardDiagonal                 equ     18
HatchStyleLightUpwardDiagonal                   equ     19
HatchStyleDarkDownwardDiagonal                  equ     20
HatchStyleDarkUpwardDiagonal                    equ     21
HatchStyleWideDownwardDiagonal                  equ     22
HatchStyleWideUpwardDiagonal                    equ     23
HatchStyleLightVertical                         equ     24
HatchStyleLightHorizontal                       equ     25
HatchStyleNarrowVertical                        equ     26
HatchStyleNarrowHorizontal                      equ     27
HatchStyleDarkVertical                          equ     28
HatchStyleDarkHorizontal                        equ     29
HatchStyleDashedDownwardDiagonal                equ     30
HatchStyleDashedUpwardDiagonal                  equ     31
HatchStyleDashedHorizontal                      equ     32
HatchStyleDashedVertical                        equ     33
HatchStyleSmallConfetti                         equ     34
HatchStyleLargeConfetti                         equ     35
HatchStyleZigZag                                equ     36
HatchStyleWave                                  equ     37
HatchStyleDiagonalBrick                         equ     38
HatchStyleHorizontalBrick                       equ     39
HatchStyleWeave                                 equ     40
HatchStylePlaid                                 equ     41
HatchStyleDivot                                 equ     42
HatchStyleDottedGrid                            equ     43
HatchStyleDottedDiamond                         equ     44
HatchStyleShingle                               equ     45
HatchStyleTrellis                               equ     46
HatchStyleSphere                                equ     47
HatchStyleSmallGrid                             equ     48
HatchStyleSmallCheckerBoard                     equ     49
HatchStyleLargeCheckerBoard                     equ     50
HatchStyleOutlinedDiamond                       equ     51
HatchStyleSolidDiamond                          equ     52
HatchStyleTotal                                 equ     53
HatchStyleLargeGrid                             equ     HatchStyleCross
HatchStyleMin                                   equ     HatchStyleHorizontal
HatchStyleMax                                   equ     (HatchStyleTotal-1)

QualityModeInvalid                              equ     (-1)
QualityModeDefault                              equ     0
QualityModeLow                                  equ     1
QualityModeHigh                                 equ     2

CompositingModeSourceOver                       equ     0
CompositingModeSourceCopy                       equ     1

CompositingQualityInvalid                       equ     QualityModeInvalid
CompositingQualityDefault                       equ     QualityModeDefault
CompositingQualityHighSpeed                     equ     QualityModeLow
CompositingQualityHighQuality                   equ     QualityModeHigh
CompositingQualityGammaCorrected                equ     3
CompositingQualityAssumeLinear                  equ     4

GenericFontFamilySerif                          equ     0
GenericFontFamilySansSerif                      equ     1
GenericFontFamilyMonospace                      equ     2

FontStyleRegular                                equ     0
FontStyleBold                                   equ     1
FontStyleItalic                                 equ     2
FontStyleBoldItalic                             equ     3
FontStyleUnderline                              equ     4
FontStyleStrikeout                              equ     8
SmoothingModeInvalid                            equ     QualityModeInvalid
SmoothingModeDefault                            equ     QualityModeDefault
SmoothingModeHighSpeed                          equ     QualityModeLow
SmoothingModeHighQuality                        equ     QualityModeHigh
SmoothingModeNone                               equ     3
SmoothingModeAntiAlias                          equ     4
FillModeAlternate                               equ     0
FillModeWinding                                 equ     1
InterpolationModeInvalid                        equ     QualityModeInvalid
InterpolationModeDefault                        equ     QualityModeDefault
InterpolationModeLowQuality                     equ     QualityModeLow
InterpolationModeHighQuality                    equ     QualityModeHigh
InterpolationModeBilinear                       equ     3
InterpolationModeBicubic                        equ     4
InterpolationModeNearestNeighbor                equ     5
InterpolationModeHighQualityBilinear            equ     6
InterpolationModeHighQualityBicubic             equ     7

WrapModeTile                                    equ     0
WrapModeTileFlipX                               equ     1
WrapModeTileFlipY                               equ     2
WrapModeTileFlipXY                              equ     3
WrapModeClamp                                   equ     4
LinearGradientModeHorizontal                    equ     0
LinearGradientModeVertical                      equ     1
LinearGradientModeForwardDiagonal               equ     2
LinearGradientModeBackwardDiagonal              equ     3
ImageTypeUnknown                                equ     0
ImageTypeBitmap                                 equ     1
ImageTypeMetafile                               equ     2

MatrixOrderPrepend                              equ     0
MatrixOrderAppend                               equ     1

ColorAdjustTypeDefault                          equ     0
ColorAdjustTypeBitmap                           equ     1
ColorAdjustTypeBrush                            equ     2
ColorAdjustTypePen                              equ     3
ColorAdjustTypeText                             equ     4
ColorAdjustTypeCount                            equ     5
ColorAdjustTypeAny                              equ     6

ColorChannelFlagsC                              equ     0
ColorChannelFlagsM                              equ     1
ColorChannelFlagsY                              equ     2
ColorChannelFlagsK                              equ     3
ColorChannelFlagsLast                           equ     4

ColorMatrixFlagsDefault                         equ     0
ColorMatrixFlagsSkipGrays                       equ     1
ColorMatrixFlagsAltGray                         equ     2

PenAlignmentCenter                              equ     0
PenAlignmentInset                               equ     1

BrushTypeSolidColor                             equ     0
BrushTypeHatchFill                              equ     1
BrushTypeTextureFill                            equ     2
BrushTypePathGradient                           equ     3
BrushTypeLinearGradient                         equ     4

DashStyleSolid                                  equ     0
DashStyleDash                                   equ     1
DashStyleDot                                    equ     2
DashStyleDashDot                                equ     3
DashStyleDashDotDot                             equ     4
DashStyleCustom                                 equ     5

DashCapFlat                                     equ     0
DashCapRound                                    equ     2
DashCapTriangle                                 equ     3

LineCapFlat                                     equ     0
LineCapSquare                                   equ     1
LineCapRound                                    equ     2
LineCapTriangle                                 equ     3
LineCapNoAnchor                                 equ     010H
LineCapSquareAnchor                             equ     011H
LineCapRoundAnchor                              equ     012H
LineCapDiamondAnchor                            equ     013H
LineCapArrowAnchor                              equ     014H
LineCapCustom                                   equ     0FFH
LineCapAnchorMask                               equ     0F0H

CustomLineCapTypeDefault                        equ     0
CustomLineCapTypeAdjustableArrow                equ     1

LineJoinMiter                                   equ     0
LineJoinBevel                                   equ     1
LineJoinRound                                   equ     2
LineJoinMiterClipped                            equ     3

PenTypeSolidColor                               equ     BrushTypeSolidColor
PenTypeHatchFill                                equ     BrushTypeHatchFill
PenTypeTextureFill                              equ     BrushTypeTextureFill
PenTypePathGradient                             equ     BrushTypePathGradient
PenTypeLinearGradient                           equ     BrushTypeLinearGradient
PenTypeUnknown                                  equ     (-1)

WarpModePerspective                             equ     0
WarpModeBilinear                                equ     1

CombineModeReplace                              equ     0
CombineModeIntersect                            equ     1
CombineModeUnion                                equ     2
CombineModeXor                                  equ     3
CombineModeExclude                              equ     4
CombineModeComplement                           equ     5

RotateNoneFlipNone                              equ     0
Rotate90FlipNone                                equ     1
Rotate180FlipNone                               equ     2
Rotate270FlipNone                               equ     3
RotateNoneFlipX                                 equ     4
Rotate90FlipX                                   equ     5
Rotate180FlipX                                  equ     6
Rotate270FlipX                                  equ     7
RotateNoneFlipY                                 equ     Rotate180FlipX
Rotate90FlipY                                   equ     Rotate270FlipX
Rotate180FlipY                                  equ     RotateNoneFlipX
Rotate270FlipY                                  equ     Rotate90FlipX
RotateNoneFlipXY                                equ     Rotate180FlipNone
Rotate90FlipXY                                  equ     Rotate270FlipNone
Rotate180FlipXY                                 equ     RotateNoneFlipNone
Rotate270FlipXY                                 equ     Rotate90FlipNone

StringFormatFlagsDirectionRightToLeft           equ     01H
StringFormatFlagsDirectionVertical              equ     02H
StringFormatFlagsNoFitBlackBox                  equ     04H
StringFormatFlagsDisplayFormatControl           equ     020H
StringFormatFlagsNoFontFallback                 equ     0400H
StringFormatFlagsMeasureTrailingSpaces          equ     0800H
StringFormatFlagsNoWrap                         equ     01000H
StringFormatFlagsLineLimit                      equ     02000H

StringFormatFlagsNoClip                         equ     04000H

StringTrimmingNone                              equ     0
StringTrimmingCharacter                         equ     1
StringTrimmingWord                              equ     2
StringTrimmingEllipsisCharacter                 equ     3
StringTrimmingEllipsisWord                      equ     4
StringTrimmingEllipsisPath                      equ     5

StringDigitSubstituteUser                       equ     0
StringDigitSubstituteNone                       equ     1
StringDigitSubstituteNational                   equ     2
StringDigitSubstituteTraditional                equ     3

HotkeyPrefixNone                                equ     0
HotkeyPrefixShow                                equ     1
HotkeyPrefixHide                                equ     2

StringAlignmentNear                             equ     0
StringAlignmentCenter                           equ     1
StringAlignmentFar                              equ     2

FlushIntentionFlush                             equ     0
FlushIntentionSync                              equ     1

EncoderParameterValueTypeByte                   equ     1
EncoderParameterValueTypeASCII                  equ     2

EncoderParameterValueTypeShort                  equ     3
EncoderParameterValueTypeLong                   equ     4
EncoderParameterValueTypeRational               equ     5

EncoderParameterValueTypeLongRange              equ     6

EncoderParameterValueTypeUndefined              equ     7

EncoderParameterValueTypeRationalRange          equ     8

EncoderValueColorTypeCMYK                       equ     0
EncoderValueColorTypeYCCK                       equ     1
EncoderValueCompressionLZW                      equ     2
EncoderValueCompressionCCITT3                   equ     3
EncoderValueCompressionCCITT4                   equ     4
EncoderValueCompressionRle                      equ     5
EncoderValueCompressionNone                     equ     6
EncoderValueScanMethodInterlaced                equ     7
EncoderValueScanMethodNonInterlaced             equ     8
EncoderValueVersionGif87                        equ     9
EncoderValueVersionGif89                        equ     10
EncoderValueRenderProgressive                   equ     11
EncoderValueRenderNonProgressive                equ     12
EncoderValueTransformRotate90                   equ     13
EncoderValueTransformRotate180                  equ     14
EncoderValueTransformRotate270                  equ     15
EncoderValueTransformFlipHorizontal             equ     16
EncoderValueTransformFlipVertical               equ     17
EncoderValueMultiFrame                          equ     18
EncoderValueLastFrame                           equ     19
EncoderValueFlush                               equ     20
EncoderValueFrameDimensionTime                  equ     21
EncoderValueFrameDimensionResolution            equ     22
EncoderValueFrameDimensionPage                  equ     23

EncoderCompression                              equ     0
EncoderColorDepth                               equ     1
EncoderScanMethod                               equ     2
EncoderVersion                                  equ     3
EncoderRenderMethod                             equ     4
EncoderQuality                                  equ     5
EncoderTransformation                           equ     6
EncoderLuminanceTable                           equ     7
EncoderChrominanceTable                         equ     8
EncoderSaveFlag                                 equ     9

PixelOffsetModeInvalid                          equ     QualityModeInvalid
PixelOffsetModeDefault                          equ     QualityModeDefault
PixelOffsetModeHighSpeed                        equ     QualityModeLow
PixelOffsetModeHighQuality                      equ     QualityModeHigh
PixelOffsetModeNone                             equ     3
PixelOffsetModeHalf                             equ     4

TextRenderingHintSystemDefault                  equ     0
TextRenderingHintSingleBitPerPixelGridFit       equ     1
TextRenderingHintSingleBitPerPixel              equ     2
TextRenderingHintAntiAliasGridFit               equ     3
TextRenderingHintAntiAlias                      equ     4
TextRenderingHintClearTypeGridFit               equ     5

MetafileTypeInvalid                             equ     0
MetafileTypeWmf                                 equ     1
MetafileTypeWmfPlaceable                        equ     2
MetafileTypeEmf                                 equ     3
MetafileTypeEmfPlusOnly                         equ     4
MetafileTypeEmfPlusDual                         equ     5

EmfTypeEmfOnly                                  equ     MetafileTypeEmf
EmfTypeEmfPlusOnly                              equ     MetafileTypeEmfPlusOnly
EmfTypeEmfPlusDual                              equ     MetafileTypeEmfPlusDual

ObjectTypeInvalid                               equ     0
ObjectTypeBrush                                 equ     1
ObjectTypePen                                   equ     2
ObjectTypePath                                  equ     3
ObjectTypeRegion                                equ     4
ObjectTypeImage                                 equ     5
ObjectTypeFont                                  equ     6
ObjectTypeStringFormat                          equ     7
ObjectTypeImageAttributes                       equ     8
ObjectTypeCustomLineCap                         equ     9

ObjectTypeMax                                   equ     ObjectTypeCustomLineCap
ObjectTypeMin                                   equ     ObjectTypeBrush

MetafileFrameUnitPixel                          equ     UnitPixel
MetafileFrameUnitPoint                          equ     UnitPoint
MetafileFrameUnitInch                           equ     UnitInch
MetafileFrameUnitDocument                       equ     UnitDocument
MetafileFrameUnitMillimeter                     equ     UnitMillimeter
MetafileFrameUnitGdi                            equ     7

CoordinateSpaceWorld                            equ     0
CoordinateSpacePage                             equ     1
CoordinateSpaceDevice                           equ     2

;========================================Functions=======================================;
#if COFF_FORMAT == 1
    from_lib gdiplus.lib
#else
    from_dll gdiplus.dll
#endif

import GdipAddImageCodec
import GdipAddPathArc
import GdipAddPathArcI
import GdipAddPathBezier
import GdipAddPathBezierI
import GdipAddPathBeziers
import GdipAddPathBeziersI
import GdipAddPathClosedCurve
import GdipAddPathClosedCurve2
import GdipAddPathClosedCurve2I
import GdipAddPathClosedCurveI
import GdipAddPathCurve
import GdipAddPathCurve2
import GdipAddPathCurve2I
import GdipAddPathCurve3
import GdipAddPathCurve3I
import GdipAddPathCurveI
import GdipAddPathEllipse
import GdipAddPathEllipseI
import GdipAddPathLine
import GdipAddPathLine2
import GdipAddPathLine2I
import GdipAddPathLineI
import GdipAddPathPath
import GdipAddPathPie
import GdipAddPathPieI
import GdipAddPathPolygon
import GdipAddPathPolygonI
import GdipAddPathRectangle
import GdipAddPathRectangleI
import GdipAddPathRectangles
import GdipAddPathRectanglesI
import GdipAddPathString
import GdipAddPathStringI
import GdipAlloc
import GdipBeginContainer
import GdipBeginContainer2
import GdipBeginContainerI
import GdipBitmapApplyEffect
import GdipBitmapConvertFormat
import GdipBitmapCreateApplyEffect
import GdipBitmapGetHistogram
import GdipBitmapGetHistogramSize
import GdipBitmapGetPixel
import GdipBitmapLockBits
import GdipBitmapSetPixel
import GdipBitmapSetResolution
import GdipBitmapUnlockBits
import GdipClearPathMarkers
import GdipCloneBitmapArea
import GdipCloneBitmapAreaI
import GdipCloneBrush
import GdipCloneCustomLineCap
import GdipCloneFont
import GdipCloneFontFamily
import GdipCloneImage
import GdipCloneImageAttributes
import GdipCloneMatrix
import GdipClonePath
import GdipClonePen
import GdipCloneRegion
import GdipCloneStringFormat
import GdipClosePathFigure
import GdipClosePathFigures
import GdipCombineRegionPath
import GdipCombineRegionRect
import GdipCombineRegionRectI
import GdipCombineRegionRegion
import GdipComment
import GdipConvertToEmfPlus
import GdipConvertToEmfPlusToFile
import GdipConvertToEmfPlusToStream
import GdipCreateAdjustableArrowCap
import GdipCreateBitmapFromDirectDrawSurface
import GdipCreateBitmapFromFile
import GdipCreateBitmapFromFileICM
import GdipCreateBitmapFromGdiDib
import GdipCreateBitmapFromGraphics
import GdipCreateBitmapFromHBITMAP
import GdipCreateBitmapFromHICON
import GdipCreateBitmapFromResource
import GdipCreateBitmapFromScan0
import GdipCreateBitmapFromStream
import GdipCreateBitmapFromStreamICM
import GdipCreateCachedBitmap
import GdipCreateCustomLineCap
import GdipCreateEffect
import GdipCreateFont
import GdipCreateFontFamilyFromName
import GdipCreateFontFromDC
import GdipCreateFontFromLogfontA
import GdipCreateFontFromLogfontW
import GdipCreateFromHDC
import GdipCreateFromHDC2
import GdipCreateFromHWND
import GdipCreateFromHWNDICM
import GdipCreateHalftonePalette
import GdipCreateHatchBrush
import GdipCreateHBITMAPFromBitmap
import GdipCreateHICONFromBitmap
import GdipCreateImageAttributes
import GdipCreateLineBrush
import GdipCreateLineBrushFromRect
import GdipCreateLineBrushFromRectI
import GdipCreateLineBrushFromRectWithAngle
import GdipCreateLineBrushFromRectWithAngleI
import GdipCreateLineBrushI
import GdipCreateMatrix
import GdipCreateMatrix2
import GdipCreateMatrix3
import GdipCreateMatrix3I
import GdipCreateMetafileFromEmf
import GdipCreateMetafileFromFile
import GdipCreateMetafileFromStream
import GdipCreateMetafileFromWmf
import GdipCreateMetafileFromWmfFile
import GdipCreatePath
import GdipCreatePath2
import GdipCreatePath2I
import GdipCreatePathGradient
import GdipCreatePathGradientFromPath
import GdipCreatePathGradientI
import GdipCreatePathIter
import GdipCreatePen1
import GdipCreatePen2
import GdipCreateRegion
import GdipCreateRegionHrgn
import GdipCreateRegionPath
import GdipCreateRegionRect
import GdipCreateRegionRectI
import GdipCreateRegionRgnData
import GdipCreateSolidFill
import GdipCreateStreamOnFile
import GdipCreateStringFormat
import GdipCreateTexture
import GdipCreateTexture2
import GdipCreateTexture2I
import GdipCreateTextureIA
import GdipCreateTextureIAI
import GdipDeleteBrush
import GdipDeleteCachedBitmap
import GdipDeleteCustomLineCap
import GdipDeleteEffect
import GdipDeleteFont
import GdipDeleteFontFamily
import GdipDeleteGraphics
import GdipDeleteMatrix
import GdipDeletePath
import GdipDeletePathIter
import GdipDeletePen
import GdipDeletePrivateFontCollection
import GdipDeleteRegion
import GdipDeleteStringFormat
import GdipDisposeImage
import GdipDisposeImageAttributes
import GdipDrawArc
import GdipDrawArcI
import GdipDrawBezier
import GdipDrawBezierI
import GdipDrawBeziers
import GdipDrawBeziersI
import GdipDrawCachedBitmap
import GdipDrawClosedCurve
import GdipDrawClosedCurve2
import GdipDrawClosedCurve2I
import GdipDrawClosedCurveI
import GdipDrawCurve
import GdipDrawCurve2
import GdipDrawCurve2I
import GdipDrawCurve3
import GdipDrawCurve3I
import GdipDrawCurveI
import GdipDrawDriverString
import GdipDrawEllipse
import GdipDrawEllipseI
import GdipDrawImage
import GdipDrawImageFX
import GdipDrawImageI
import GdipDrawImagePointRect
import GdipDrawImagePointRectI
import GdipDrawImagePoints
import GdipDrawImagePointsI
import GdipDrawImagePointsRect
import GdipDrawImagePointsRectI
import GdipDrawImageRect
import GdipDrawImageRectI
import GdipDrawImageRectRect
import GdipDrawImageRectRectI
import GdipDrawLine
import GdipDrawLineI
import GdipDrawLines
import GdipDrawLinesI
import GdipDrawPath
import GdipDrawPie
import GdipDrawPieI
import GdipDrawPolygon
import GdipDrawPolygonI
import GdipDrawRectangle
import GdipDrawRectangleI
import GdipDrawRectangles
import GdipDrawRectanglesI
import GdipDrawString
import GdipEmfToWmfBits
import GdipEndContainer
import GdipEnumerateMetafileDestPoint
import GdipEnumerateMetafileDestPointI
import GdipEnumerateMetafileDestPoints
import GdipEnumerateMetafileDestPointsI
import GdipEnumerateMetafileDestRect
import GdipEnumerateMetafileDestRectI
import GdipEnumerateMetafileSrcRectDestPoint
import GdipEnumerateMetafileSrcRectDestPointI
import GdipEnumerateMetafileSrcRectDestPoints
import GdipEnumerateMetafileSrcRectDestPointsI
import GdipEnumerateMetafileSrcRectDestRect
import GdipEnumerateMetafileSrcRectDestRectI
import GdipFillClosedCurve
import GdipFillClosedCurve2
import GdipFillClosedCurve2I
import GdipFillClosedCurveI
import GdipFillEllipse
import GdipFillEllipseI
import GdipFillPath
import GdipFillPie
import GdipFillPieI
import GdipFillPolygon
import GdipFillPolygon2
import GdipFillPolygon2I
import GdipFillPolygonI
import GdipFillRectangle
import GdipFillRectangleI
import GdipFillRectangles
import GdipFillRectanglesI
import GdipFillRegion
import GdipFindFirstImageItem
import GdipFindNextImageItem
import GdipFlattenPath
import GdipFlush
import GdipFree
import GdipGetAdjustableArrowCapFillState
import GdipGetAdjustableArrowCapHeight
import GdipGetAdjustableArrowCapMiddleInset
import GdipGetAdjustableArrowCapWidth
import GdipGetAllPropertyItems
import GdipGetBrushType
import GdipGetCellAscent
import GdipGetCellDescent
import GdipGetClip
import GdipGetClipBounds
import GdipGetClipBoundsI
import GdipGetCompositingMode
import GdipGetCompositingQuality
import GdipGetCustomLineCapBaseCap
import GdipGetCustomLineCapBaseInset
import GdipGetCustomLineCapStrokeCaps
import GdipGetCustomLineCapStrokeJoin
import GdipGetCustomLineCapType
import GdipGetCustomLineCapWidthScale
import GdipGetDC
import GdipGetDpiX
import GdipGetDpiY
import GdipGetEffectParameters
import GdipGetEffectParameterSize
import GdipGetEmHeight
import GdipGetEncoderParameterList
import GdipGetEncoderParameterListSize
import GdipGetFamily
import GdipGetFamilyName
import GdipGetFontCollectionFamilyCount
import GdipGetFontCollectionFamilyList
import GdipGetFontHeight
import GdipGetFontHeightGivenDPI
import GdipGetFontSize
import GdipGetFontStyle
import GdipGetFontUnit
import GdipGetGenericFontFamilyMonospace
import GdipGetGenericFontFamilySansSerif
import GdipGetGenericFontFamilySerif
import GdipGetGraphicsLayout
import GdipGetHatchBackgroundColor
import GdipGetHatchForegroundColor
import GdipGetHatchStyle
import GdipGetHemfFromMetafile
import GdipGetImageAttributesAdjustedPalette
import GdipGetImageBounds
import GdipGetImageDecoders
import GdipGetImageDecodersSize
import GdipGetImageDimension
import GdipGetImageEncoders
import GdipGetImageEncodersSize
import GdipGetImageFlags
import GdipGetImageGraphicsContext
import GdipGetImageHeight
import GdipGetImageHorizontalResolution
import GdipGetImageLayout
import GdipGetImagePalette
import GdipGetImagePaletteSize
import GdipGetImagePixelFormat
import GdipGetImageRawFormat
import GdipGetImageThumbnail
import GdipGetImageType
import GdipGetImageVerticalResolution
import GdipGetImageWidth
import GdipGetInterpolationMode
import GdipGetLineBlend
import GdipGetLineBlendCount
import GdipGetLineColors
import GdipGetLineGammaCorrection
import GdipGetLinePoints
import GdipGetLinePointsI
import GdipGetLinePresetBlend
import GdipGetLinePresetBlendCount
import GdipGetLineRect
import GdipGetLineRectI
import GdipGetLineSpacing
import GdipGetLineTransform
import GdipGetLineWrapMode
import GdipGetLogFontA
import GdipGetLogFontW
import GdipGetMatrixElements
import GdipGetMetafileDownLevelRasterizationLimit
import GdipGetMetafileHeaderFromEmf
import GdipGetMetafileHeaderFromFile
import GdipGetMetafileHeaderFromMetafile
import GdipGetMetafileHeaderFromStream
import GdipGetMetafileHeaderFromWmf
import GdipGetNearestColor
import GdipGetPageScale
import GdipGetPageUnit
import GdipGetPathData
import GdipGetPathFillMode
import GdipGetPathGradientBlend
import GdipGetPathGradientBlendCount
import GdipGetPathGradientCenterColor
import GdipGetPathGradientCenterPoint
import GdipGetPathGradientCenterPointI
import GdipGetPathGradientFocusScales
import GdipGetPathGradientGammaCorrection
import GdipGetPathGradientPath
import GdipGetPathGradientPointCount
import GdipGetPathGradientPresetBlend
import GdipGetPathGradientPresetBlendCount
import GdipGetPathGradientRect
import GdipGetPathGradientRectI
import GdipGetPathGradientSurroundColorCount
import GdipGetPathGradientSurroundColorsWithCount
import GdipGetPathGradientTransform
import GdipGetPathGradientWrapMode
import GdipGetPathLastPoint
import GdipGetPathPoints
import GdipGetPathPointsI
import GdipGetPathTypes
import GdipGetPathWorldBounds
import GdipGetPathWorldBoundsI
import GdipGetPenBrushFill
import GdipGetPenColor
import GdipGetPenCompoundArray
import GdipGetPenCompoundCount
import GdipGetPenCustomEndCap
import GdipGetPenCustomStartCap
import GdipGetPenDashArray
import GdipGetPenDashCap197819
import GdipGetPenDashCount
import GdipGetPenDashOffset
import GdipGetPenDashStyle
import GdipGetPenEndCap
import GdipGetPenFillType
import GdipGetPenLineJoin
import GdipGetPenMiterLimit
import GdipGetPenMode
import GdipGetPenStartCap
import GdipGetPenTransform
import GdipGetPenUnit
import GdipGetPenWidth
import GdipGetPixelOffsetMode
import GdipGetPointCount
import GdipGetPropertyCount
import GdipGetPropertyIdList
import GdipGetPropertyItem
import GdipGetPropertyItemSize
import GdipGetPropertySize
import GdipGetRegionBounds
import GdipGetRegionBoundsI
import GdipGetRegionData
import GdipGetRegionDataSize
import GdipGetRegionHRgn
import GdipGetRegionScans
import GdipGetRegionScansCount
import GdipGetRegionScansI
import GdipGetRenderingOrigin
import GdipGetSmoothingMode
import GdipGetSolidFillColor
import GdipGetStringFormatAlign
import GdipGetStringFormatDigitSubstitution
import GdipGetStringFormatFlags
import GdipGetStringFormatHotkeyPrefix
import GdipGetStringFormatLineAlign
import GdipGetStringFormatMeasurableCharacterRangeCount
import GdipGetStringFormatTabStopCount
import GdipGetStringFormatTabStops
import GdipGetStringFormatTrimming
import GdipGetTextContrast
import GdipGetTextRenderingHint
import GdipGetTextureImage
import GdipGetTextureTransform
import GdipGetTextureWrapMode
import GdipGetVisibleClipBounds
import GdipGetVisibleClipBoundsI
import GdipGetWorldTransform
import GdipGraphicsClear
import GdipGraphicsSetAbort
import GdipImageForceValidation
import GdipImageGetFrameCount
import GdipImageGetFrameDimensionsCount
import GdipImageGetFrameDimensionsList
import GdipImageRotateFlip
import GdipImageSelectActiveFrame
import GdipImageSetAbort
import GdipInitializePalette
import GdipInvertMatrix
import GdipIsClipEmpty
import GdipIsEmptyRegion
import GdipIsEqualRegion
import GdipIsInfiniteRegion
import GdipIsMatrixEqual
import GdipIsMatrixIdentity
import GdipIsMatrixInvertible
import GdipIsOutlineVisiblePathPoint
import GdipIsOutlineVisiblePathPointI
import GdipIsStyleAvailable
import GdipIsVisibleClipEmpty
import GdipIsVisiblePathPoint
import GdipIsVisiblePathPointI
import GdipIsVisiblePoint
import GdipIsVisiblePointI
import GdipIsVisibleRect
import GdipIsVisibleRectI
import GdipIsVisibleRegionPoint
import GdipIsVisibleRegionPointI
import GdipIsVisibleRegionRect
import GdipIsVisibleRegionRectI
import GdipLoadImageFromFile
import GdipLoadImageFromFileICM
import GdipLoadImageFromStream
import GdipLoadImageFromStreamICM
import GdipMeasureCharacterRanges
import GdipMeasureDriverString
import GdipMeasureString
import GdipMultiplyLineTransform
import GdipMultiplyMatrix
import GdipMultiplyPathGradientTransform
import GdipMultiplyPenTransform
import GdipMultiplyTextureTransform
import GdipMultiplyWorldTransform
import GdipNewInstalledFontCollection
import GdipNewPrivateFontCollection
import GdipPathIterCopyData
import GdipPathIterEnumerate
import GdipPathIterGetCount
import GdipPathIterGetSubpathCount
import GdipPathIterHasCurve
import GdipPathIterIsValid
import GdipPathIterNextMarker
import GdipPathIterNextMarkerPath
import GdipPathIterNextPathType
import GdipPathIterNextSubpath
import GdipPathIterNextSubpathPath
import GdipPathIterRewind
import GdipPlayMetafileRecord
import GdiplusNotificationHook
import GdiplusNotificationUnhook
import GdiplusShutdown
import GdiplusStartup
import GdipPrivateAddFontFile
import GdipPrivateAddMemoryFont
import GdipRecordMetafile
import GdipRecordMetafileFileName
import GdipRecordMetafileFileNameI
import GdipRecordMetafileI
import GdipRecordMetafileStream
import GdipRecordMetafileStreamI
import GdipReleaseDC
import GdipRemoveImageCodec
import GdipRemovePropertyItem
import GdipResetClip
import GdipResetImageAttributes
import GdipResetLineTransform
import GdipResetPageTransform
import GdipResetPath
import GdipResetPathGradientTransform
import GdipResetPenTransform
import GdipResetTextureTransform
import GdipResetWorldTransform
import GdipRestoreGraphics
import GdipReversePath
import GdipRotateLineTransform
import GdipRotateMatrix
import GdipRotatePathGradientTransform
import GdipRotatePenTransform
import GdipRotateTextureTransform
import GdipRotateWorldTransform
import GdipSaveAdd
import GdipSaveAddImage
import GdipSaveGraphics
import GdipSaveImageToFile
import GdipSaveImageToStream
import GdipScaleLineTransform
import GdipScaleMatrix
import GdipScalePathGradientTransform
import GdipScalePenTransform
import GdipScaleTextureTransform
import GdipScaleWorldTransform
import GdipSetAdjustableArrowCapFillState
import GdipSetAdjustableArrowCapHeight
import GdipSetAdjustableArrowCapMiddleInset
import GdipSetAdjustableArrowCapWidth
import GdipSetClipGraphics
import GdipSetClipHrgn
import GdipSetClipPath
import GdipSetClipRect
import GdipSetClipRectI
import GdipSetClipRegion
import GdipSetCompositingMode
import GdipSetCompositingQuality
import GdipSetCustomLineCapBaseCap
import GdipSetCustomLineCapBaseInset
import GdipSetCustomLineCapStrokeCaps
import GdipSetCustomLineCapStrokeJoin
import GdipSetCustomLineCapWidthScale
import GdipSetEffectParameters
import GdipSetEmpty
import GdipSetGraphicsLayout
import GdipSetImageAttributesCachedBackground
import GdipSetImageAttributesColorKeys
import GdipSetImageAttributesColorMatrix
import GdipSetImageAttributesGamma
import GdipSetImageAttributesNoOp
import GdipSetImageAttributesOutputChannel
import GdipSetImageAttributesOutputChannelColorProfile
import GdipSetImageAttributesRemapTable
import GdipSetImageAttributesThreshold
import GdipSetImageAttributesToIdentity
import GdipSetImageAttributesWrapMode
import GdipSetImageLayout
import GdipSetImagePalette
import GdipSetInfinite
import GdipSetInterpolationMode
import GdipSetLineBlend
import GdipSetLineColors
import GdipSetLineGammaCorrection
import GdipSetLineLinearBlend
import GdipSetLinePoints
import GdipSetLinePointsI
import GdipSetLinePresetBlend
import GdipSetLineSigmaBlend
import GdipSetLineTransform
import GdipSetLineWrapMode
import GdipSetMatrixElements
import GdipSetMetafileDownLevelRasterizationLimit
import GdipSetPageScale
import GdipSetPageUnit
import GdipSetPathFillMode
import GdipSetPathGradientBlend
import GdipSetPathGradientCenterColor
import GdipSetPathGradientCenterPoint
import GdipSetPathGradientCenterPointI
import GdipSetPathGradientFocusScales
import GdipSetPathGradientGammaCorrection
import GdipSetPathGradientLinearBlend
import GdipSetPathGradientPath
import GdipSetPathGradientPresetBlend
import GdipSetPathGradientSigmaBlend
import GdipSetPathGradientSurroundColorsWithCount
import GdipSetPathGradientTransform
import GdipSetPathGradientWrapMode
import GdipSetPathMarker
import GdipSetPenBrushFill
import GdipSetPenColor
import GdipSetPenCompoundArray
import GdipSetPenCustomEndCap
import GdipSetPenCustomStartCap
import GdipSetPenDashArray
import GdipSetPenDashCap197819
import GdipSetPenDashOffset
import GdipSetPenDashStyle
import GdipSetPenEndCap
import GdipSetPenLineCap197819
import GdipSetPenLineJoin
import GdipSetPenMiterLimit
import GdipSetPenMode
import GdipSetPenStartCap
import GdipSetPenTransform
import GdipSetPenUnit
import GdipSetPenWidth
import GdipSetPixelOffsetMode
import GdipSetPropertyItem
import GdipSetRenderingOrigin
import GdipSetSmoothingMode
import GdipSetSolidFillColor
import GdipSetStringFormatAlign
import GdipSetStringFormatDigitSubstitution
import GdipSetStringFormatFlags
import GdipSetStringFormatHotkeyPrefix
import GdipSetStringFormatLineAlign
import GdipSetStringFormatMeasurableCharacterRanges
import GdipSetStringFormatTabStops
import GdipSetStringFormatTrimming
import GdipSetTextContrast
import GdipSetTextRenderingHint
import GdipSetTextureTransform
import GdipSetTextureWrapMode
import GdipSetWorldTransform
import GdipShearMatrix
import GdipStartPathFigure
import GdipStringFormatGetGenericDefault
import GdipStringFormatGetGenericTypographic
import GdipTestControl
import GdipTransformMatrixPoints
import GdipTransformMatrixPointsI
import GdipTransformPath
import GdipTransformPoints
import GdipTransformPointsI
import GdipTransformRegion
import GdipTranslateClip
import GdipTranslateClipI
import GdipTranslateLineTransform
import GdipTranslateMatrix
import GdipTranslatePathGradientTransform
import GdipTranslatePenTransform
import GdipTranslateRegion
import GdipTranslateRegionI
import GdipTranslateTextureTransform
import GdipTranslateWorldTransform
import GdipVectorTransformMatrixPoints
import GdipVectorTransformMatrixPointsI
import GdipWarpPath
import GdipWidenPath
import GdipWindingModeOutline

#ifdef APP_UNICODE
    define GdipCreateFontFromLogfont GdipCreateFontFromLogfontW
    define GdipGetLogFont GdipGetLogFontW
#else
    define GdipCreateFontFromLogfont GdipCreateFontFromLogfontA
    define GdipGetLogFont GdipGetLogFontA
#endif

;======================= Undocumented functions (unknown arguments) =======================;
;if defined APP_WIN64
;    import GdipPlayTSClientRecord
;else
;    extern GdipPlayTSClientRecord alias GdipWindingModeOutline@??
;end if

#endif ;GDIPLUS_INC
