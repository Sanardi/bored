; ====================================================;
;                                                     ;
;    gdiplus.inc for EC v2 SolAsm visual projects     ;
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

#ifdef APP_WIN64
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
#else
    extern GdipAddImageCodec alias _GdipAddImageCodec@4
    extern GdipAddPathArc alias _GdipAddPathArc@28
    extern GdipAddPathArcI alias _GdipAddPathArcI@28
    extern GdipAddPathBezier alias _GdipAddPathBezier@36
    extern GdipAddPathBezierI alias _GdipAddPathBezierI@36
    extern GdipAddPathBeziers alias _GdipAddPathBeziers@12
    extern GdipAddPathBeziersI alias _GdipAddPathBeziersI@12
    extern GdipAddPathClosedCurve alias _GdipAddPathClosedCurve@12
    extern GdipAddPathClosedCurve2 alias _GdipAddPathClosedCurve2@16
    extern GdipAddPathClosedCurve2I alias _GdipAddPathClosedCurve2I@16
    extern GdipAddPathClosedCurveI alias _GdipAddPathClosedCurveI@12
    extern GdipAddPathCurve alias _GdipAddPathCurve@12
    extern GdipAddPathCurve2 alias _GdipAddPathCurve2@16
    extern GdipAddPathCurve2I alias _GdipAddPathCurve2I@16
    extern GdipAddPathCurve3 alias _GdipAddPathCurve3@24
    extern GdipAddPathCurve3I alias _GdipAddPathCurve3I@24
    extern GdipAddPathCurveI alias _GdipAddPathCurveI@12
    extern GdipAddPathEllipse alias _GdipAddPathEllipse@20
    extern GdipAddPathEllipseI alias _GdipAddPathEllipseI@20
    extern GdipAddPathLine alias _GdipAddPathLine@20
    extern GdipAddPathLine2 alias _GdipAddPathLine2@12
    extern GdipAddPathLine2I alias _GdipAddPathLine2I@12
    extern GdipAddPathLineI alias _GdipAddPathLineI@20
    extern GdipAddPathPath alias _GdipAddPathPath@12
    extern GdipAddPathPie alias _GdipAddPathPie@28
    extern GdipAddPathPieI alias _GdipAddPathPieI@28
    extern GdipAddPathPolygon alias _GdipAddPathPolygon@12
    extern GdipAddPathPolygonI alias _GdipAddPathPolygonI@12
    extern GdipAddPathRectangle alias _GdipAddPathRectangle@20
    extern GdipAddPathRectangleI alias _GdipAddPathRectangleI@20
    extern GdipAddPathRectangles alias _GdipAddPathRectangles@12
    extern GdipAddPathRectanglesI alias _GdipAddPathRectanglesI@12
    extern GdipAddPathString alias _GdipAddPathString@32
    extern GdipAddPathStringI alias _GdipAddPathStringI@32
    extern GdipAlloc alias _GdipAlloc@4
    extern GdipBeginContainer alias _GdipBeginContainer@20
    extern GdipBeginContainer2 alias _GdipBeginContainer2@8
    extern GdipBeginContainerI alias _GdipBeginContainerI@20
    extern GdipBitmapApplyEffect alias _GdipBitmapApplyEffect@24
    extern GdipBitmapConvertFormat alias _GdipBitmapConvertFormat@24
    extern GdipBitmapCreateApplyEffect alias _GdipBitmapCreateApplyEffect@36
    extern GdipBitmapGetHistogram alias _GdipBitmapGetHistogram@28
    extern GdipBitmapGetHistogramSize alias _GdipBitmapGetHistogramSize@8
    extern GdipBitmapGetPixel alias _GdipBitmapGetPixel@16
    extern GdipBitmapLockBits alias _GdipBitmapLockBits@20
    extern GdipBitmapSetPixel alias _GdipBitmapSetPixel@16
    extern GdipBitmapSetResolution alias _GdipBitmapSetResolution@12
    extern GdipBitmapUnlockBits alias _GdipBitmapUnlockBits@8
    extern GdipClearPathMarkers alias _GdipClearPathMarkers@4
    extern GdipCloneBitmapArea alias _GdipCloneBitmapArea@28
    extern GdipCloneBitmapAreaI alias _GdipCloneBitmapAreaI@28
    extern GdipCloneBrush alias _GdipCloneBrush@8
    extern GdipCloneCustomLineCap alias _GdipCloneCustomLineCap@8
    extern GdipCloneFont alias _GdipCloneFont@8
    extern GdipCloneFontFamily alias _GdipCloneFontFamily@8
    extern GdipCloneImage alias _GdipCloneImage@8
    extern GdipCloneImageAttributes alias _GdipCloneImageAttributes@8
    extern GdipCloneMatrix alias _GdipCloneMatrix@8
    extern GdipClonePath alias _GdipClonePath@8
    extern GdipClonePen alias _GdipClonePen@8
    extern GdipCloneRegion alias _GdipCloneRegion@8
    extern GdipCloneStringFormat alias _GdipCloneStringFormat@8
    extern GdipClosePathFigure alias _GdipClosePathFigure@4
    extern GdipClosePathFigures alias _GdipClosePathFigures@4
    extern GdipCombineRegionPath alias _GdipCombineRegionPath@12
    extern GdipCombineRegionRect alias _GdipCombineRegionRect@12
    extern GdipCombineRegionRectI alias _GdipCombineRegionRectI@12
    extern GdipCombineRegionRegion alias _GdipCombineRegionRegion@12
    extern GdipComment alias _GdipComment@12
    extern GdipConvertToEmfPlus alias _GdipConvertToEmfPlus@24
    extern GdipConvertToEmfPlusToFile alias _GdipConvertToEmfPlusToFile@28
    extern GdipConvertToEmfPlusToStream alias _GdipConvertToEmfPlusToStream@28
    extern GdipCreateAdjustableArrowCap alias _GdipCreateAdjustableArrowCap@16
    extern GdipCreateBitmapFromDirectDrawSurface alias _GdipCreateBitmapFromDirectDrawSurface@8
    extern GdipCreateBitmapFromFile alias _GdipCreateBitmapFromFile@8
    extern GdipCreateBitmapFromFileICM alias _GdipCreateBitmapFromFileICM@8
    extern GdipCreateBitmapFromGdiDib alias _GdipCreateBitmapFromGdiDib@12
    extern GdipCreateBitmapFromGraphics alias _GdipCreateBitmapFromGraphics@16
    extern GdipCreateBitmapFromHBITMAP alias _GdipCreateBitmapFromHBITMAP@12
    extern GdipCreateBitmapFromHICON alias _GdipCreateBitmapFromHICON@8
    extern GdipCreateBitmapFromResource alias _GdipCreateBitmapFromResource@12
    extern GdipCreateBitmapFromScan0 alias _GdipCreateBitmapFromScan0@24
    extern GdipCreateBitmapFromStream alias _GdipCreateBitmapFromStream@8
    extern GdipCreateBitmapFromStreamICM alias _GdipCreateBitmapFromStreamICM@8
    extern GdipCreateCachedBitmap alias _GdipCreateCachedBitmap@12
    extern GdipCreateCustomLineCap alias _GdipCreateCustomLineCap@20
    extern GdipCreateEffect alias _GdipCreateEffect@8
    extern GdipCreateFont alias _GdipCreateFont@20
    extern GdipCreateFontFamilyFromName alias _GdipCreateFontFamilyFromName@12
    extern GdipCreateFontFromDC alias _GdipCreateFontFromDC@8
    extern GdipCreateFontFromLogfontA alias _GdipCreateFontFromLogfontA@12
    extern GdipCreateFontFromLogfontW alias _GdipCreateFontFromLogfontW@12
    extern GdipCreateFromHDC alias _GdipCreateFromHDC@8
    extern GdipCreateFromHDC2 alias _GdipCreateFromHDC2@12
    extern GdipCreateFromHWND alias _GdipCreateFromHWND@8
    extern GdipCreateFromHWNDICM alias _GdipCreateFromHWNDICM@8
    extern GdipCreateHalftonePalette alias _GdipCreateHalftonePalette@0
    extern GdipCreateHatchBrush alias _GdipCreateHatchBrush@16
    extern GdipCreateHBITMAPFromBitmap alias _GdipCreateHBITMAPFromBitmap@12
    extern GdipCreateHICONFromBitmap alias _GdipCreateHICONFromBitmap@8
    extern GdipCreateImageAttributes alias _GdipCreateImageAttributes@4
    extern GdipCreateLineBrush alias _GdipCreateLineBrush@24
    extern GdipCreateLineBrushFromRect alias _GdipCreateLineBrushFromRect@24
    extern GdipCreateLineBrushFromRectI alias _GdipCreateLineBrushFromRectI@24
    extern GdipCreateLineBrushFromRectWithAngle alias _GdipCreateLineBrushFromRectWithAngle@28
    extern GdipCreateLineBrushFromRectWithAngleI alias _GdipCreateLineBrushFromRectWithAngleI@28
    extern GdipCreateLineBrushI alias _GdipCreateLineBrushI@24
    extern GdipCreateMatrix alias _GdipCreateMatrix@4
    extern GdipCreateMatrix2 alias _GdipCreateMatrix2@28
    extern GdipCreateMatrix3 alias _GdipCreateMatrix3@12
    extern GdipCreateMatrix3I alias _GdipCreateMatrix3I@12
    extern GdipCreateMetafileFromEmf alias _GdipCreateMetafileFromEmf@12
    extern GdipCreateMetafileFromFile alias _GdipCreateMetafileFromFile@8
    extern GdipCreateMetafileFromStream alias _GdipCreateMetafileFromStream@8
    extern GdipCreateMetafileFromWmf alias _GdipCreateMetafileFromWmf@16
    extern GdipCreateMetafileFromWmfFile alias _GdipCreateMetafileFromWmfFile@12
    extern GdipCreatePath alias _GdipCreatePath@8
    extern GdipCreatePath2 alias _GdipCreatePath2@20
    extern GdipCreatePath2I alias _GdipCreatePath2I@20
    extern GdipCreatePathGradient alias _GdipCreatePathGradient@16
    extern GdipCreatePathGradientFromPath alias _GdipCreatePathGradientFromPath@8
    extern GdipCreatePathGradientI alias _GdipCreatePathGradientI@16
    extern GdipCreatePathIter alias _GdipCreatePathIter@8
    extern GdipCreatePen1 alias _GdipCreatePen1@16
    extern GdipCreatePen2 alias _GdipCreatePen2@16
    extern GdipCreateRegion alias _GdipCreateRegion@4
    extern GdipCreateRegionHrgn alias _GdipCreateRegionHrgn@8
    extern GdipCreateRegionPath alias _GdipCreateRegionPath@8
    extern GdipCreateRegionRect alias _GdipCreateRegionRect@8
    extern GdipCreateRegionRectI alias _GdipCreateRegionRectI@8
    extern GdipCreateRegionRgnData alias _GdipCreateRegionRgnData@12
    extern GdipCreateSolidFill alias _GdipCreateSolidFill@8
    extern GdipCreateStreamOnFile alias _GdipCreateStreamOnFile@12
    extern GdipCreateStringFormat alias _GdipCreateStringFormat@12
    extern GdipCreateTexture alias _GdipCreateTexture@12
    extern GdipCreateTexture2 alias _GdipCreateTexture2@28
    extern GdipCreateTexture2I alias _GdipCreateTexture2I@28
    extern GdipCreateTextureIA alias _GdipCreateTextureIA@28
    extern GdipCreateTextureIAI alias _GdipCreateTextureIAI@28
    extern GdipDeleteBrush alias _GdipDeleteBrush@4
    extern GdipDeleteCachedBitmap alias _GdipDeleteCachedBitmap@4
    extern GdipDeleteCustomLineCap alias _GdipDeleteCustomLineCap@4
    extern GdipDeleteEffect alias _GdipDeleteEffect@4
    extern GdipDeleteFont alias _GdipDeleteFont@4
    extern GdipDeleteFontFamily alias _GdipDeleteFontFamily@4
    extern GdipDeleteGraphics alias _GdipDeleteGraphics@4
    extern GdipDeleteMatrix alias _GdipDeleteMatrix@4
    extern GdipDeletePath alias _GdipDeletePath@4
    extern GdipDeletePathIter alias _GdipDeletePathIter@4
    extern GdipDeletePen alias _GdipDeletePen@4
    extern GdipDeletePrivateFontCollection alias _GdipDeletePrivateFontCollection@4
    extern GdipDeleteRegion alias _GdipDeleteRegion@4
    extern GdipDeleteStringFormat alias _GdipDeleteStringFormat@4
    extern GdipDisposeImage alias _GdipDisposeImage@4
    extern GdipDisposeImageAttributes alias _GdipDisposeImageAttributes@4
    extern GdipDrawArc alias _GdipDrawArc@32
    extern GdipDrawArcI alias _GdipDrawArcI@32
    extern GdipDrawBezier alias _GdipDrawBezier@40
    extern GdipDrawBezierI alias _GdipDrawBezierI@40
    extern GdipDrawBeziers alias _GdipDrawBeziers@16
    extern GdipDrawBeziersI alias _GdipDrawBeziersI@16
    extern GdipDrawCachedBitmap alias _GdipDrawCachedBitmap@16
    extern GdipDrawClosedCurve alias _GdipDrawClosedCurve@16
    extern GdipDrawClosedCurve2 alias _GdipDrawClosedCurve2@20
    extern GdipDrawClosedCurve2I alias _GdipDrawClosedCurve2I@20
    extern GdipDrawClosedCurveI alias _GdipDrawClosedCurveI@16
    extern GdipDrawCurve alias _GdipDrawCurve@16
    extern GdipDrawCurve2 alias _GdipDrawCurve2@20
    extern GdipDrawCurve2I alias _GdipDrawCurve2I@20
    extern GdipDrawCurve3 alias _GdipDrawCurve3@28
    extern GdipDrawCurve3I alias _GdipDrawCurve3I@28
    extern GdipDrawCurveI alias _GdipDrawCurveI@16
    extern GdipDrawDriverString alias _GdipDrawDriverString@32
    extern GdipDrawEllipse alias _GdipDrawEllipse@24
    extern GdipDrawEllipseI alias _GdipDrawEllipseI@24
    extern GdipDrawImage alias _GdipDrawImage@16
    extern GdipDrawImageFX alias _GdipDrawImageFX@28
    extern GdipDrawImageI alias _GdipDrawImageI@16
    extern GdipDrawImagePointRect alias _GdipDrawImagePointRect@36
    extern GdipDrawImagePointRectI alias _GdipDrawImagePointRectI@36
    extern GdipDrawImagePoints alias _GdipDrawImagePoints@16
    extern GdipDrawImagePointsI alias _GdipDrawImagePointsI@16
    extern GdipDrawImagePointsRect alias _GdipDrawImagePointsRect@48
    extern GdipDrawImagePointsRectI alias _GdipDrawImagePointsRectI@48
    extern GdipDrawImageRect alias _GdipDrawImageRect@24
    extern GdipDrawImageRectI alias _GdipDrawImageRectI@24
    extern GdipDrawImageRectRect alias _GdipDrawImageRectRect@56
    extern GdipDrawImageRectRectI alias _GdipDrawImageRectRectI@56
    extern GdipDrawLine alias _GdipDrawLine@24
    extern GdipDrawLineI alias _GdipDrawLineI@24
    extern GdipDrawLines alias _GdipDrawLines@16
    extern GdipDrawLinesI alias _GdipDrawLinesI@16
    extern GdipDrawPath alias _GdipDrawPath@12
    extern GdipDrawPie alias _GdipDrawPie@32
    extern GdipDrawPieI alias _GdipDrawPieI@32
    extern GdipDrawPolygon alias _GdipDrawPolygon@16
    extern GdipDrawPolygonI alias _GdipDrawPolygonI@16
    extern GdipDrawRectangle alias _GdipDrawRectangle@24
    extern GdipDrawRectangleI alias _GdipDrawRectangleI@24
    extern GdipDrawRectangles alias _GdipDrawRectangles@16
    extern GdipDrawRectanglesI alias _GdipDrawRectanglesI@16
    extern GdipDrawString alias _GdipDrawString@28
    extern GdipEmfToWmfBits alias _GdipEmfToWmfBits@20
    extern GdipEndContainer alias _GdipEndContainer@8
    extern GdipEnumerateMetafileDestPoint alias _GdipEnumerateMetafileDestPoint@24
    extern GdipEnumerateMetafileDestPointI alias _GdipEnumerateMetafileDestPointI@24
    extern GdipEnumerateMetafileDestPoints alias _GdipEnumerateMetafileDestPoints@28
    extern GdipEnumerateMetafileDestPointsI alias _GdipEnumerateMetafileDestPointsI@28
    extern GdipEnumerateMetafileDestRect alias _GdipEnumerateMetafileDestRect@24
    extern GdipEnumerateMetafileDestRectI alias _GdipEnumerateMetafileDestRectI@24
    extern GdipEnumerateMetafileSrcRectDestPoint alias _GdipEnumerateMetafileSrcRectDestPoint@32
    extern GdipEnumerateMetafileSrcRectDestPointI alias _GdipEnumerateMetafileSrcRectDestPointI@32
    extern GdipEnumerateMetafileSrcRectDestPoints alias _GdipEnumerateMetafileSrcRectDestPoints@36
    extern GdipEnumerateMetafileSrcRectDestPointsI alias _GdipEnumerateMetafileSrcRectDestPointsI@36
    extern GdipEnumerateMetafileSrcRectDestRect alias _GdipEnumerateMetafileSrcRectDestRect@32
    extern GdipEnumerateMetafileSrcRectDestRectI alias _GdipEnumerateMetafileSrcRectDestRectI@32
    extern GdipFillClosedCurve alias _GdipFillClosedCurve@16
    extern GdipFillClosedCurve2 alias _GdipFillClosedCurve2@24
    extern GdipFillClosedCurve2I alias _GdipFillClosedCurve2I@24
    extern GdipFillClosedCurveI alias _GdipFillClosedCurveI@16
    extern GdipFillEllipse alias _GdipFillEllipse@24
    extern GdipFillEllipseI alias _GdipFillEllipseI@24
    extern GdipFillPath alias _GdipFillPath@12
    extern GdipFillPie alias _GdipFillPie@32
    extern GdipFillPieI alias _GdipFillPieI@32
    extern GdipFillPolygon alias _GdipFillPolygon@20
    extern GdipFillPolygon2 alias _GdipFillPolygon2@16
    extern GdipFillPolygon2I alias _GdipFillPolygon2I@16
    extern GdipFillPolygonI alias _GdipFillPolygonI@20
    extern GdipFillRectangle alias _GdipFillRectangle@24
    extern GdipFillRectangleI alias _GdipFillRectangleI@24
    extern GdipFillRectangles alias _GdipFillRectangles@16
    extern GdipFillRectanglesI alias _GdipFillRectanglesI@16
    extern GdipFillRegion alias _GdipFillRegion@12
    extern GdipFindFirstImageItem alias _GdipFindFirstImageItem@8
    extern GdipFindNextImageItem alias _GdipFindNextImageItem@8
    extern GdipFlattenPath alias _GdipFlattenPath@12
    extern GdipFlush alias _GdipFlush@8
    extern GdipFree alias _GdipFree@4
    extern GdipGetAdjustableArrowCapFillState alias _GdipGetAdjustableArrowCapFillState@8
    extern GdipGetAdjustableArrowCapHeight alias _GdipGetAdjustableArrowCapHeight@8
    extern GdipGetAdjustableArrowCapMiddleInset alias _GdipGetAdjustableArrowCapMiddleInset@8
    extern GdipGetAdjustableArrowCapWidth alias _GdipGetAdjustableArrowCapWidth@8
    extern GdipGetAllPropertyItems alias _GdipGetAllPropertyItems@16
    extern GdipGetBrushType alias _GdipGetBrushType@8
    extern GdipGetCellAscent alias _GdipGetCellAscent@12
    extern GdipGetCellDescent alias _GdipGetCellDescent@12
    extern GdipGetClip alias _GdipGetClip@8
    extern GdipGetClipBounds alias _GdipGetClipBounds@8
    extern GdipGetClipBoundsI alias _GdipGetClipBoundsI@8
    extern GdipGetCompositingMode alias _GdipGetCompositingMode@8
    extern GdipGetCompositingQuality alias _GdipGetCompositingQuality@8
    extern GdipGetCustomLineCapBaseCap alias _GdipGetCustomLineCapBaseCap@8
    extern GdipGetCustomLineCapBaseInset alias _GdipGetCustomLineCapBaseInset@8
    extern GdipGetCustomLineCapStrokeCaps alias _GdipGetCustomLineCapStrokeCaps@12
    extern GdipGetCustomLineCapStrokeJoin alias _GdipGetCustomLineCapStrokeJoin@8
    extern GdipGetCustomLineCapType alias _GdipGetCustomLineCapType@8
    extern GdipGetCustomLineCapWidthScale alias _GdipGetCustomLineCapWidthScale@8
    extern GdipGetDC alias _GdipGetDC@8
    extern GdipGetDpiX alias _GdipGetDpiX@8
    extern GdipGetDpiY alias _GdipGetDpiY@8
    extern GdipGetEffectParameters alias _GdipGetEffectParameters@12
    extern GdipGetEffectParameterSize alias _GdipGetEffectParameterSize@8
    extern GdipGetEmHeight alias _GdipGetEmHeight@12
    extern GdipGetEncoderParameterList alias _GdipGetEncoderParameterList@16
    extern GdipGetEncoderParameterListSize alias _GdipGetEncoderParameterListSize@12
    extern GdipGetFamily alias _GdipGetFamily@8
    extern GdipGetFamilyName alias _GdipGetFamilyName@12
    extern GdipGetFontCollectionFamilyCount alias _GdipGetFontCollectionFamilyCount@8
    extern GdipGetFontCollectionFamilyList alias _GdipGetFontCollectionFamilyList@16
    extern GdipGetFontHeight alias _GdipGetFontHeight@12
    extern GdipGetFontHeightGivenDPI alias _GdipGetFontHeightGivenDPI@12
    extern GdipGetFontSize alias _GdipGetFontSize@8
    extern GdipGetFontStyle alias _GdipGetFontStyle@8
    extern GdipGetFontUnit alias _GdipGetFontUnit@8
    extern GdipGetGenericFontFamilyMonospace alias _GdipGetGenericFontFamilyMonospace@4
    extern GdipGetGenericFontFamilySansSerif alias _GdipGetGenericFontFamilySansSerif@4
    extern GdipGetGenericFontFamilySerif alias _GdipGetGenericFontFamilySerif@4
    extern GdipGetGraphicsLayout alias _GdipGetGraphicsLayout@8
    extern GdipGetHatchBackgroundColor alias _GdipGetHatchBackgroundColor@8
    extern GdipGetHatchForegroundColor alias _GdipGetHatchForegroundColor@8
    extern GdipGetHatchStyle alias _GdipGetHatchStyle@8
    extern GdipGetHemfFromMetafile alias _GdipGetHemfFromMetafile@8
    extern GdipGetImageAttributesAdjustedPalette alias _GdipGetImageAttributesAdjustedPalette@12
    extern GdipGetImageBounds alias _GdipGetImageBounds@12
    extern GdipGetImageDecoders alias _GdipGetImageDecoders@12
    extern GdipGetImageDecodersSize alias _GdipGetImageDecodersSize@8
    extern GdipGetImageDimension alias _GdipGetImageDimension@12
    extern GdipGetImageEncoders alias _GdipGetImageEncoders@12
    extern GdipGetImageEncodersSize alias _GdipGetImageEncodersSize@8
    extern GdipGetImageFlags alias _GdipGetImageFlags@8
    extern GdipGetImageGraphicsContext alias _GdipGetImageGraphicsContext@8
    extern GdipGetImageHeight alias _GdipGetImageHeight@8
    extern GdipGetImageHorizontalResolution alias _GdipGetImageHorizontalResolution@8
    extern GdipGetImageLayout alias _GdipGetImageLayout@8
    extern GdipGetImagePalette alias _GdipGetImagePalette@12
    extern GdipGetImagePaletteSize alias _GdipGetImagePaletteSize@8
    extern GdipGetImagePixelFormat alias _GdipGetImagePixelFormat@8
    extern GdipGetImageRawFormat alias _GdipGetImageRawFormat@8
    extern GdipGetImageThumbnail alias _GdipGetImageThumbnail@24
    extern GdipGetImageType alias _GdipGetImageType@8
    extern GdipGetImageVerticalResolution alias _GdipGetImageVerticalResolution@8
    extern GdipGetImageWidth alias _GdipGetImageWidth@8
    extern GdipGetInterpolationMode alias _GdipGetInterpolationMode@8
    extern GdipGetLineBlend alias _GdipGetLineBlend@16
    extern GdipGetLineBlendCount alias _GdipGetLineBlendCount@8
    extern GdipGetLineColors alias _GdipGetLineColors@8
    extern GdipGetLineGammaCorrection alias _GdipGetLineGammaCorrection@8
    extern GdipGetLinePoints alias _GdipGetLinePoints@8
    extern GdipGetLinePointsI alias _GdipGetLinePointsI@8
    extern GdipGetLinePresetBlend alias _GdipGetLinePresetBlend@16
    extern GdipGetLinePresetBlendCount alias _GdipGetLinePresetBlendCount@8
    extern GdipGetLineRect alias _GdipGetLineRect@8
    extern GdipGetLineRectI alias _GdipGetLineRectI@8
    extern GdipGetLineSpacing alias _GdipGetLineSpacing@12
    extern GdipGetLineTransform alias _GdipGetLineTransform@8
    extern GdipGetLineWrapMode alias _GdipGetLineWrapMode@8
    extern GdipGetLogFontA alias _GdipGetLogFontA@12
    extern GdipGetLogFontW alias _GdipGetLogFontW@12
    extern GdipGetMatrixElements alias _GdipGetMatrixElements@8
    extern GdipGetMetafileDownLevelRasterizationLimit alias _GdipGetMetafileDownLevelRasterizationLimit@8
    extern GdipGetMetafileHeaderFromEmf alias _GdipGetMetafileHeaderFromEmf@8
    extern GdipGetMetafileHeaderFromFile alias _GdipGetMetafileHeaderFromFile@8
    extern GdipGetMetafileHeaderFromMetafile alias _GdipGetMetafileHeaderFromMetafile@8
    extern GdipGetMetafileHeaderFromStream alias _GdipGetMetafileHeaderFromStream@8
    extern GdipGetMetafileHeaderFromWmf alias _GdipGetMetafileHeaderFromWmf@12
    extern GdipGetNearestColor alias _GdipGetNearestColor@8
    extern GdipGetPageScale alias _GdipGetPageScale@8
    extern GdipGetPageUnit alias _GdipGetPageUnit@8
    extern GdipGetPathData alias _GdipGetPathData@8
    extern GdipGetPathFillMode alias _GdipGetPathFillMode@8
    extern GdipGetPathGradientBlend alias _GdipGetPathGradientBlend@16
    extern GdipGetPathGradientBlendCount alias _GdipGetPathGradientBlendCount@8
    extern GdipGetPathGradientCenterColor alias _GdipGetPathGradientCenterColor@8
    extern GdipGetPathGradientCenterPoint alias _GdipGetPathGradientCenterPoint@8
    extern GdipGetPathGradientCenterPointI alias _GdipGetPathGradientCenterPointI@8
    extern GdipGetPathGradientFocusScales alias _GdipGetPathGradientFocusScales@12
    extern GdipGetPathGradientGammaCorrection alias _GdipGetPathGradientGammaCorrection@8
    extern GdipGetPathGradientPath alias _GdipGetPathGradientPath@8
    extern GdipGetPathGradientPointCount alias _GdipGetPathGradientPointCount@8
    extern GdipGetPathGradientPresetBlend alias _GdipGetPathGradientPresetBlend@16
    extern GdipGetPathGradientPresetBlendCount alias _GdipGetPathGradientPresetBlendCount@8
    extern GdipGetPathGradientRect alias _GdipGetPathGradientRect@8
    extern GdipGetPathGradientRectI alias _GdipGetPathGradientRectI@8
    extern GdipGetPathGradientSurroundColorCount alias _GdipGetPathGradientSurroundColorCount@8
    extern GdipGetPathGradientSurroundColorsWithCount alias _GdipGetPathGradientSurroundColorsWithCount@12
    extern GdipGetPathGradientTransform alias _GdipGetPathGradientTransform@8
    extern GdipGetPathGradientWrapMode alias _GdipGetPathGradientWrapMode@8
    extern GdipGetPathLastPoint alias _GdipGetPathLastPoint@8
    extern GdipGetPathPoints alias _GdipGetPathPoints@12
    extern GdipGetPathPointsI alias _GdipGetPathPointsI@12
    extern GdipGetPathTypes alias _GdipGetPathTypes@12
    extern GdipGetPathWorldBounds alias _GdipGetPathWorldBounds@16
    extern GdipGetPathWorldBoundsI alias _GdipGetPathWorldBoundsI@16
    extern GdipGetPenBrushFill alias _GdipGetPenBrushFill@8
    extern GdipGetPenColor alias _GdipGetPenColor@8
    extern GdipGetPenCompoundArray alias _GdipGetPenCompoundArray@12
    extern GdipGetPenCompoundCount alias _GdipGetPenCompoundCount@8
    extern GdipGetPenCustomEndCap alias _GdipGetPenCustomEndCap@8
    extern GdipGetPenCustomStartCap alias _GdipGetPenCustomStartCap@8
    extern GdipGetPenDashArray alias _GdipGetPenDashArray@12
    extern GdipGetPenDashCap197819 alias _GdipGetPenDashCap197819@8
    extern GdipGetPenDashCount alias _GdipGetPenDashCount@8
    extern GdipGetPenDashOffset alias _GdipGetPenDashOffset@8
    extern GdipGetPenDashStyle alias _GdipGetPenDashStyle@8
    extern GdipGetPenEndCap alias _GdipGetPenEndCap@8
    extern GdipGetPenFillType alias _GdipGetPenFillType@8
    extern GdipGetPenLineJoin alias _GdipGetPenLineJoin@8
    extern GdipGetPenMiterLimit alias _GdipGetPenMiterLimit@8
    extern GdipGetPenMode alias _GdipGetPenMode@8
    extern GdipGetPenStartCap alias _GdipGetPenStartCap@8
    extern GdipGetPenTransform alias _GdipGetPenTransform@8
    extern GdipGetPenUnit alias _GdipGetPenUnit@8
    extern GdipGetPenWidth alias _GdipGetPenWidth@8
    extern GdipGetPixelOffsetMode alias _GdipGetPixelOffsetMode@8
    extern GdipGetPointCount alias _GdipGetPointCount@8
    extern GdipGetPropertyCount alias _GdipGetPropertyCount@8
    extern GdipGetPropertyIdList alias _GdipGetPropertyIdList@12
    extern GdipGetPropertyItem alias _GdipGetPropertyItem@16
    extern GdipGetPropertyItemSize alias _GdipGetPropertyItemSize@12
    extern GdipGetPropertySize alias _GdipGetPropertySize@12
    extern GdipGetRegionBounds alias _GdipGetRegionBounds@12
    extern GdipGetRegionBoundsI alias _GdipGetRegionBoundsI@12
    extern GdipGetRegionData alias _GdipGetRegionData@16
    extern GdipGetRegionDataSize alias _GdipGetRegionDataSize@8
    extern GdipGetRegionHRgn alias _GdipGetRegionHRgn@12
    extern GdipGetRegionScans alias _GdipGetRegionScans@16
    extern GdipGetRegionScansCount alias _GdipGetRegionScansCount@12
    extern GdipGetRegionScansI alias _GdipGetRegionScansI@16
    extern GdipGetRenderingOrigin alias _GdipGetRenderingOrigin@12
    extern GdipGetSmoothingMode alias _GdipGetSmoothingMode@8
    extern GdipGetSolidFillColor alias _GdipGetSolidFillColor@8
    extern GdipGetStringFormatAlign alias _GdipGetStringFormatAlign@8
    extern GdipGetStringFormatDigitSubstitution alias _GdipGetStringFormatDigitSubstitution@12
    extern GdipGetStringFormatFlags alias _GdipGetStringFormatFlags@8
    extern GdipGetStringFormatHotkeyPrefix alias _GdipGetStringFormatHotkeyPrefix@8
    extern GdipGetStringFormatLineAlign alias _GdipGetStringFormatLineAlign@8
    extern GdipGetStringFormatMeasurableCharacterRangeCount alias _GdipGetStringFormatMeasurableCharacterRangeCount@8
    extern GdipGetStringFormatTabStopCount alias _GdipGetStringFormatTabStopCount@8
    extern GdipGetStringFormatTabStops alias _GdipGetStringFormatTabStops@16
    extern GdipGetStringFormatTrimming alias _GdipGetStringFormatTrimming@8
    extern GdipGetTextContrast alias _GdipGetTextContrast@8
    extern GdipGetTextRenderingHint alias _GdipGetTextRenderingHint@8
    extern GdipGetTextureImage alias _GdipGetTextureImage@8
    extern GdipGetTextureTransform alias _GdipGetTextureTransform@8
    extern GdipGetTextureWrapMode alias _GdipGetTextureWrapMode@8
    extern GdipGetVisibleClipBounds alias _GdipGetVisibleClipBounds@8
    extern GdipGetVisibleClipBoundsI alias _GdipGetVisibleClipBoundsI@8
    extern GdipGetWorldTransform alias _GdipGetWorldTransform@8
    extern GdipGraphicsClear alias _GdipGraphicsClear@8
    extern GdipGraphicsSetAbort alias _GdipGraphicsSetAbort@8
    extern GdipImageForceValidation alias _GdipImageForceValidation@4
    extern GdipImageGetFrameCount alias _GdipImageGetFrameCount@12
    extern GdipImageGetFrameDimensionsCount alias _GdipImageGetFrameDimensionsCount@8
    extern GdipImageGetFrameDimensionsList alias _GdipImageGetFrameDimensionsList@12
    extern GdipImageRotateFlip alias _GdipImageRotateFlip@8
    extern GdipImageSelectActiveFrame alias _GdipImageSelectActiveFrame@12
    extern GdipImageSetAbort alias _GdipImageSetAbort@8
    extern GdipInitializePalette alias _GdipInitializePalette@20
    extern GdipInvertMatrix alias _GdipInvertMatrix@4
    extern GdipIsClipEmpty alias _GdipIsClipEmpty@8
    extern GdipIsEmptyRegion alias _GdipIsEmptyRegion@12
    extern GdipIsEqualRegion alias _GdipIsEqualRegion@16
    extern GdipIsInfiniteRegion alias _GdipIsInfiniteRegion@12
    extern GdipIsMatrixEqual alias _GdipIsMatrixEqual@12
    extern GdipIsMatrixIdentity alias _GdipIsMatrixIdentity@8
    extern GdipIsMatrixInvertible alias _GdipIsMatrixInvertible@8
    extern GdipIsOutlineVisiblePathPoint alias _GdipIsOutlineVisiblePathPoint@24
    extern GdipIsOutlineVisiblePathPointI alias _GdipIsOutlineVisiblePathPointI@24
    extern GdipIsStyleAvailable alias _GdipIsStyleAvailable@12
    extern GdipIsVisibleClipEmpty alias _GdipIsVisibleClipEmpty@8
    extern GdipIsVisiblePathPoint alias _GdipIsVisiblePathPoint@20
    extern GdipIsVisiblePathPointI alias _GdipIsVisiblePathPointI@20
    extern GdipIsVisiblePoint alias _GdipIsVisiblePoint@16
    extern GdipIsVisiblePointI alias _GdipIsVisiblePointI@16
    extern GdipIsVisibleRect alias _GdipIsVisibleRect@24
    extern GdipIsVisibleRectI alias _GdipIsVisibleRectI@24
    extern GdipIsVisibleRegionPoint alias _GdipIsVisibleRegionPoint@20
    extern GdipIsVisibleRegionPointI alias _GdipIsVisibleRegionPointI@20
    extern GdipIsVisibleRegionRect alias _GdipIsVisibleRegionRect@28
    extern GdipIsVisibleRegionRectI alias _GdipIsVisibleRegionRectI@28
    extern GdipLoadImageFromFile alias _GdipLoadImageFromFile@8
    extern GdipLoadImageFromFileICM alias _GdipLoadImageFromFileICM@8
    extern GdipLoadImageFromStream alias _GdipLoadImageFromStream@8
    extern GdipLoadImageFromStreamICM alias _GdipLoadImageFromStreamICM@8
    extern GdipMeasureCharacterRanges alias _GdipMeasureCharacterRanges@32
    extern GdipMeasureDriverString alias _GdipMeasureDriverString@32
    extern GdipMeasureString alias _GdipMeasureString@36
    extern GdipMultiplyLineTransform alias _GdipMultiplyLineTransform@12
    extern GdipMultiplyMatrix alias _GdipMultiplyMatrix@12
    extern GdipMultiplyPathGradientTransform alias _GdipMultiplyPathGradientTransform@12
    extern GdipMultiplyPenTransform alias _GdipMultiplyPenTransform@12
    extern GdipMultiplyTextureTransform alias _GdipMultiplyTextureTransform@12
    extern GdipMultiplyWorldTransform alias _GdipMultiplyWorldTransform@12
    extern GdipNewInstalledFontCollection alias _GdipNewInstalledFontCollection@4
    extern GdipNewPrivateFontCollection alias _GdipNewPrivateFontCollection@4
    extern GdipPathIterCopyData alias _GdipPathIterCopyData@24
    extern GdipPathIterEnumerate alias _GdipPathIterEnumerate@20
    extern GdipPathIterGetCount alias _GdipPathIterGetCount@8
    extern GdipPathIterGetSubpathCount alias _GdipPathIterGetSubpathCount@8
    extern GdipPathIterHasCurve alias _GdipPathIterHasCurve@8
    extern GdipPathIterIsValid alias _GdipPathIterIsValid@8
    extern GdipPathIterNextMarker alias _GdipPathIterNextMarker@16
    extern GdipPathIterNextMarkerPath alias _GdipPathIterNextMarkerPath@12
    extern GdipPathIterNextPathType alias _GdipPathIterNextPathType@20
    extern GdipPathIterNextSubpath alias _GdipPathIterNextSubpath@20
    extern GdipPathIterNextSubpathPath alias _GdipPathIterNextSubpathPath@16
    extern GdipPathIterRewind alias _GdipPathIterRewind@4
    extern GdipPlayMetafileRecord alias _GdipPlayMetafileRecord@20
    extern GdiplusNotificationHook alias _GdiplusNotificationHook@4
    extern GdiplusNotificationUnhook alias _GdiplusNotificationUnhook@4
    extern GdiplusShutdown alias _GdiplusShutdown@4
    extern GdiplusStartup alias _GdiplusStartup@12
    extern GdipPrivateAddFontFile alias _GdipPrivateAddFontFile@8
    extern GdipPrivateAddMemoryFont alias _GdipPrivateAddMemoryFont@12
    extern GdipRecordMetafile alias _GdipRecordMetafile@24
    extern GdipRecordMetafileFileName alias _GdipRecordMetafileFileName@28
    extern GdipRecordMetafileFileNameI alias _GdipRecordMetafileFileNameI@28
    extern GdipRecordMetafileI alias _GdipRecordMetafileI@24
    extern GdipRecordMetafileStream alias _GdipRecordMetafileStream@28
    extern GdipRecordMetafileStreamI alias _GdipRecordMetafileStreamI@28
    extern GdipReleaseDC alias _GdipReleaseDC@8
    extern GdipRemoveImageCodec alias _GdipRemoveImageCodec@4
    extern GdipRemovePropertyItem alias _GdipRemovePropertyItem@8
    extern GdipResetClip alias _GdipResetClip@4
    extern GdipResetImageAttributes alias _GdipResetImageAttributes@8
    extern GdipResetLineTransform alias _GdipResetLineTransform@4
    extern GdipResetPageTransform alias _GdipResetPageTransform@4
    extern GdipResetPath alias _GdipResetPath@4
    extern GdipResetPathGradientTransform alias _GdipResetPathGradientTransform@4
    extern GdipResetPenTransform alias _GdipResetPenTransform@4
    extern GdipResetTextureTransform alias _GdipResetTextureTransform@4
    extern GdipResetWorldTransform alias _GdipResetWorldTransform@4
    extern GdipRestoreGraphics alias _GdipRestoreGraphics@8
    extern GdipReversePath alias _GdipReversePath@4
    extern GdipRotateLineTransform alias _GdipRotateLineTransform@12
    extern GdipRotateMatrix alias _GdipRotateMatrix@12
    extern GdipRotatePathGradientTransform alias _GdipRotatePathGradientTransform@12
    extern GdipRotatePenTransform alias _GdipRotatePenTransform@12
    extern GdipRotateTextureTransform alias _GdipRotateTextureTransform@12
    extern GdipRotateWorldTransform alias _GdipRotateWorldTransform@12
    extern GdipSaveAdd alias _GdipSaveAdd@8
    extern GdipSaveAddImage alias _GdipSaveAddImage@12
    extern GdipSaveGraphics alias _GdipSaveGraphics@8
    extern GdipSaveImageToFile alias _GdipSaveImageToFile@16
    extern GdipSaveImageToStream alias _GdipSaveImageToStream@16
    extern GdipScaleLineTransform alias _GdipScaleLineTransform@16
    extern GdipScaleMatrix alias _GdipScaleMatrix@16
    extern GdipScalePathGradientTransform alias _GdipScalePathGradientTransform@16
    extern GdipScalePenTransform alias _GdipScalePenTransform@16
    extern GdipScaleTextureTransform alias _GdipScaleTextureTransform@16
    extern GdipScaleWorldTransform alias _GdipScaleWorldTransform@16
    extern GdipSetAdjustableArrowCapFillState alias _GdipSetAdjustableArrowCapFillState@8
    extern GdipSetAdjustableArrowCapHeight alias _GdipSetAdjustableArrowCapHeight@8
    extern GdipSetAdjustableArrowCapMiddleInset alias _GdipSetAdjustableArrowCapMiddleInset@8
    extern GdipSetAdjustableArrowCapWidth alias _GdipSetAdjustableArrowCapWidth@8
    extern GdipSetClipGraphics alias _GdipSetClipGraphics@12
    extern GdipSetClipHrgn alias _GdipSetClipHrgn@12
    extern GdipSetClipPath alias _GdipSetClipPath@12
    extern GdipSetClipRect alias _GdipSetClipRect@24
    extern GdipSetClipRectI alias _GdipSetClipRectI@24
    extern GdipSetClipRegion alias _GdipSetClipRegion@12
    extern GdipSetCompositingMode alias _GdipSetCompositingMode@8
    extern GdipSetCompositingQuality alias _GdipSetCompositingQuality@8
    extern GdipSetCustomLineCapBaseCap alias _GdipSetCustomLineCapBaseCap@8
    extern GdipSetCustomLineCapBaseInset alias _GdipSetCustomLineCapBaseInset@8
    extern GdipSetCustomLineCapStrokeCaps alias _GdipSetCustomLineCapStrokeCaps@12
    extern GdipSetCustomLineCapStrokeJoin alias _GdipSetCustomLineCapStrokeJoin@8
    extern GdipSetCustomLineCapWidthScale alias _GdipSetCustomLineCapWidthScale@8
    extern GdipSetEffectParameters alias _GdipSetEffectParameters@12
    extern GdipSetEmpty alias _GdipSetEmpty@4
    extern GdipSetGraphicsLayout alias _GdipSetGraphicsLayout@8
    extern GdipSetImageAttributesCachedBackground alias _GdipSetImageAttributesCachedBackground@8
    extern GdipSetImageAttributesColorKeys alias _GdipSetImageAttributesColorKeys@20
    extern GdipSetImageAttributesColorMatrix alias _GdipSetImageAttributesColorMatrix@24
    extern GdipSetImageAttributesGamma alias _GdipSetImageAttributesGamma@16
    extern GdipSetImageAttributesNoOp alias _GdipSetImageAttributesNoOp@12
    extern GdipSetImageAttributesOutputChannel alias _GdipSetImageAttributesOutputChannel@16
    extern GdipSetImageAttributesOutputChannelColorProfile alias _GdipSetImageAttributesOutputChannelColorProfile@16
    extern GdipSetImageAttributesRemapTable alias _GdipSetImageAttributesRemapTable@20
    extern GdipSetImageAttributesThreshold alias _GdipSetImageAttributesThreshold@16
    extern GdipSetImageAttributesToIdentity alias _GdipSetImageAttributesToIdentity@8
    extern GdipSetImageAttributesWrapMode alias _GdipSetImageAttributesWrapMode@16
    extern GdipSetImageLayout alias _GdipSetImageLayout@8
    extern GdipSetImagePalette alias _GdipSetImagePalette@8
    extern GdipSetInfinite alias _GdipSetInfinite@4
    extern GdipSetInterpolationMode alias _GdipSetInterpolationMode@8
    extern GdipSetLineBlend alias _GdipSetLineBlend@16
    extern GdipSetLineColors alias _GdipSetLineColors@12
    extern GdipSetLineGammaCorrection alias _GdipSetLineGammaCorrection@8
    extern GdipSetLineLinearBlend alias _GdipSetLineLinearBlend@12
    extern GdipSetLinePoints alias _GdipSetLinePoints@12
    extern GdipSetLinePointsI alias _GdipSetLinePointsI@12
    extern GdipSetLinePresetBlend alias _GdipSetLinePresetBlend@16
    extern GdipSetLineSigmaBlend alias _GdipSetLineSigmaBlend@12
    extern GdipSetLineTransform alias _GdipSetLineTransform@8
    extern GdipSetLineWrapMode alias _GdipSetLineWrapMode@8
    extern GdipSetMatrixElements alias _GdipSetMatrixElements@28
    extern GdipSetMetafileDownLevelRasterizationLimit alias _GdipSetMetafileDownLevelRasterizationLimit@8
    extern GdipSetPageScale alias _GdipSetPageScale@8
    extern GdipSetPageUnit alias _GdipSetPageUnit@8
    extern GdipSetPathFillMode alias _GdipSetPathFillMode@8
    extern GdipSetPathGradientBlend alias _GdipSetPathGradientBlend@16
    extern GdipSetPathGradientCenterColor alias _GdipSetPathGradientCenterColor@8
    extern GdipSetPathGradientCenterPoint alias _GdipSetPathGradientCenterPoint@8
    extern GdipSetPathGradientCenterPointI alias _GdipSetPathGradientCenterPointI@8
    extern GdipSetPathGradientFocusScales alias _GdipSetPathGradientFocusScales@12
    extern GdipSetPathGradientGammaCorrection alias _GdipSetPathGradientGammaCorrection@8
    extern GdipSetPathGradientLinearBlend alias _GdipSetPathGradientLinearBlend@12
    extern GdipSetPathGradientPath alias _GdipSetPathGradientPath@8
    extern GdipSetPathGradientPresetBlend alias _GdipSetPathGradientPresetBlend@16
    extern GdipSetPathGradientSigmaBlend alias _GdipSetPathGradientSigmaBlend@12
    extern GdipSetPathGradientSurroundColorsWithCount alias _GdipSetPathGradientSurroundColorsWithCount@12
    extern GdipSetPathGradientTransform alias _GdipSetPathGradientTransform@8
    extern GdipSetPathGradientWrapMode alias _GdipSetPathGradientWrapMode@8
    extern GdipSetPathMarker alias _GdipSetPathMarker@4
    extern GdipSetPenBrushFill alias _GdipSetPenBrushFill@8
    extern GdipSetPenColor alias _GdipSetPenColor@8
    extern GdipSetPenCompoundArray alias _GdipSetPenCompoundArray@12
    extern GdipSetPenCustomEndCap alias _GdipSetPenCustomEndCap@8
    extern GdipSetPenCustomStartCap alias _GdipSetPenCustomStartCap@8
    extern GdipSetPenDashArray alias _GdipSetPenDashArray@12
    extern GdipSetPenDashCap197819 alias _GdipSetPenDashCap197819@8
    extern GdipSetPenDashOffset alias _GdipSetPenDashOffset@8
    extern GdipSetPenDashStyle alias _GdipSetPenDashStyle@8
    extern GdipSetPenEndCap alias _GdipSetPenEndCap@8
    extern GdipSetPenLineCap197819 alias _GdipSetPenLineCap197819@16
    extern GdipSetPenLineJoin alias _GdipSetPenLineJoin@8
    extern GdipSetPenMiterLimit alias _GdipSetPenMiterLimit@8
    extern GdipSetPenMode alias _GdipSetPenMode@8
    extern GdipSetPenStartCap alias _GdipSetPenStartCap@8
    extern GdipSetPenTransform alias _GdipSetPenTransform@8
    extern GdipSetPenUnit alias _GdipSetPenUnit@8
    extern GdipSetPenWidth alias _GdipSetPenWidth@8
    extern GdipSetPixelOffsetMode alias _GdipSetPixelOffsetMode@8
    extern GdipSetPropertyItem alias _GdipSetPropertyItem@8
    extern GdipSetRenderingOrigin alias _GdipSetRenderingOrigin@12
    extern GdipSetSmoothingMode alias _GdipSetSmoothingMode@8
    extern GdipSetSolidFillColor alias _GdipSetSolidFillColor@8
    extern GdipSetStringFormatAlign alias _GdipSetStringFormatAlign@8
    extern GdipSetStringFormatDigitSubstitution alias _GdipSetStringFormatDigitSubstitution@12
    extern GdipSetStringFormatFlags alias _GdipSetStringFormatFlags@8
    extern GdipSetStringFormatHotkeyPrefix alias _GdipSetStringFormatHotkeyPrefix@8
    extern GdipSetStringFormatLineAlign alias _GdipSetStringFormatLineAlign@8
    extern GdipSetStringFormatMeasurableCharacterRanges alias _GdipSetStringFormatMeasurableCharacterRanges@12
    extern GdipSetStringFormatTabStops alias _GdipSetStringFormatTabStops@16
    extern GdipSetStringFormatTrimming alias _GdipSetStringFormatTrimming@8
    extern GdipSetTextContrast alias _GdipSetTextContrast@8
    extern GdipSetTextRenderingHint alias _GdipSetTextRenderingHint@8
    extern GdipSetTextureTransform alias _GdipSetTextureTransform@8
    extern GdipSetTextureWrapMode alias _GdipSetTextureWrapMode@8
    extern GdipSetWorldTransform alias _GdipSetWorldTransform@8
    extern GdipShearMatrix alias _GdipShearMatrix@16
    extern GdipStartPathFigure alias _GdipStartPathFigure@4
    extern GdipStringFormatGetGenericDefault alias _GdipStringFormatGetGenericDefault@4
    extern GdipStringFormatGetGenericTypographic alias _GdipStringFormatGetGenericTypographic@4
    extern GdipTestControl alias _GdipTestControl@8
    extern GdipTransformMatrixPoints alias _GdipTransformMatrixPoints@12
    extern GdipTransformMatrixPointsI alias _GdipTransformMatrixPointsI@12
    extern GdipTransformPath alias _GdipTransformPath@8
    extern GdipTransformPoints alias _GdipTransformPoints@20
    extern GdipTransformPointsI alias _GdipTransformPointsI@20
    extern GdipTransformRegion alias _GdipTransformRegion@8
    extern GdipTranslateClip alias _GdipTranslateClip@12
    extern GdipTranslateClipI alias _GdipTranslateClipI@12
    extern GdipTranslateLineTransform alias _GdipTranslateLineTransform@16
    extern GdipTranslateMatrix alias _GdipTranslateMatrix@16
    extern GdipTranslatePathGradientTransform alias _GdipTranslatePathGradientTransform@16
    extern GdipTranslatePenTransform alias _GdipTranslatePenTransform@16
    extern GdipTranslateRegion alias _GdipTranslateRegion@12
    extern GdipTranslateRegionI alias _GdipTranslateRegionI@12
    extern GdipTranslateTextureTransform alias _GdipTranslateTextureTransform@16
    extern GdipTranslateWorldTransform alias _GdipTranslateWorldTransform@16
    extern GdipVectorTransformMatrixPoints alias _GdipVectorTransformMatrixPoints@12
    extern GdipVectorTransformMatrixPointsI alias _GdipVectorTransformMatrixPointsI@12
    extern GdipWarpPath alias _GdipWarpPath@40
    extern GdipWidenPath alias _GdipWidenPath@16
    extern GdipWindingModeOutline alias _GdipWindingModeOutline@12
#endif

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
