; =====================================================;
;                                                      ;
;  gdiplus.inc for Easy Code 2.0 64-bit Masm projects  ;
;                  (version 1.0.2)                     ;
;                                                      ;
;           Copyright © Ramon Sala 2019-2020           ;
;                                                      ;
; =====================================================;

if ~defined GDIPLUS_INC
define GDIPLUS_INC 1

if ~defined LF_FACESIZE
    LF_FACESIZE equ 32 
end if

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
HatchStyleMax                                   equ     (HatchStyleTotal - 1)

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

;========================================Structures======================================;
struct GdiplusStartupInput
    GdiplusVersion              dd ?
    DebugEventCallback          dd ?
    SuppressBackgroundThread    dd ?
    SuppressExternalCodecs      dd ?
ends

struct PointF
    x   dd ? ;real4
    y   dd ? ;real4
ends

struct RectF
    _Left   dd ? ;real4
    _Top    dd ? ;real4
    _Right  dd ? ;real4
    Bottom  dd ? ;real4
ends

struct SizeF
    sx  dd ? ;real4
    sy  dd ? ;real4
ends

struct COLORBYTES
    BlueByte    db ?
    GreenByte   db ?
    RedByte     db ?
    AlphaByte   db ?
ends

struct COLORLONG
    longval dd ?
ends

struct ImageCodecInfo
    ClassID             GUID
    FormatID            GUID
    CodecName           dd ?
    DllName             dd ?
    FormatDescription   dd ?
    FilenameExtension   dd ?
    MimeType            dd ?
    flags               dd ?
    Version             dd ?
    SigCount            dd ?
    SigSize             dd ?
    SigPattern          dd ?
    SigMask             dd ?
ends

struct EncoderParameter
    pGUID           dd ?
    NumberOfValues  dd ?
    vType           dd ?
    value           dd ?
ends

struct EncoderParameters
    Count       dd ?
    Parameter   EncoderParameter
ends

struct ColorPalette
    flags   dd ?
    Count   dd ?
    Entries dd ?
ends

struct ColorMatrix
    m11 dd ? ;real4
    m12 dd ? ;real4
    m13 dd ? ;real4
    m14 dd ? ;real4
    m15 dd ? ;real4
    m21 dd ? ;real4
    m22 dd ? ;real4
    m23 dd ? ;real4
    m24 dd ? ;real4
    m25 dd ? ;real4
    m31 dd ? ;real4
    m32 dd ? ;real4
    m33 dd ? ;real4
    m34 dd ? ;real4
    m35 dd ? ;real4
    m41 dd ? ;real4
    m42 dd ? ;real4
    m43 dd ? ;real4
    m44 dd ? ;real4
    m45 dd ? ;real4
    m51 dd ? ;real4
    m52 dd ? ;real4
    m53 dd ? ;real4
    m54 dd ? ;real4
    m55 dd ? ;real4
ends

struct BitmapData
    nWidth      dd ?
    nHeight     dd ?
    Stride      dd ?
    PixelFormat dd ?
    Scan0       dd ?
    Reserved    dd ?
ends

struct PathData
    Count   dd ?
    pPoint  dd ?
    types   dd ?
ends

struct PropertyItem
    propId  dd ?
    length  dd ?
    nType   dw ?
    value   dd ?
ends

if ~defined LOGFONTA
    struct LOGFONTA
        lfHeight            dd ?
        lfWidth             dd ?
        lfEscapement        dd ?
        lfOrientation       dd ?
        lfWeight            dd ?
        lfItalic            db ?
        lfUnderline         db ?
        lfStrikeOut         db ?
        lfCharSet           db ?
        lfOutPrecision      db ?
        lfClipPrecision     db ?
        lfQuality           db ?
        lfPitchAndFamily    db ?
        lfFaceName          db LF_FACESIZE dup(?)
    ends
end if

if ~defined LOGFONTW
    struct LOGFONTW
        lfHeight            dd ?
        lfWidth             dd ?
        lfEscapement        dd ?
        lfOrientation       dd ?
        lfWeight            dd ?
        lfItalic            db ?
        lfUnderline         db ?
        lfStrikeOut         db ?
        lfCharSet           db ?
        lfOutPrecision      db ?
        lfClipPrecision     db ?
        lfQuality           db ?
        lfPitchAndFamily    db ?
        lfFaceName          dw LF_FACESIZE dup(?)
    ends
end if

struct CharacterRange
    First   dd ?
    length  dd ?
ends

struct PWMFRect16
    nLEFT   dw ?
    nTop    dw ?
    nRIGHT  dw ?
    nBottom dw ?
ends

struct WmfPlaceableFileHeader
    Key         dd ?
    Hmf         dw ?
    boundingBox PWMFRect16
    Inch        dw ?
    Reserved    dd ?
    Checksum    dw ?
ends

if ~defined ENHMETAHEADER3
    struct ENHMETAHEADER3
        itype           dd ?
        nSize           dd ?
        rclBounds       RECT
        rclFrame        RECT
        dSignature      dd ?
        nVersion        dd ?
        nBytes          dd ?
        nRecords        dd ?
        nHandles        dw ?
        sReserved       dw ?
        nDescription    dd ?
        offDescription  dd ?
        nPalEntries     dd ?
        szlDevice       SIZE
        szlMillimeters  SIZE
    ends
end if

struct MetafileHeader
    mType               dd ?
    msize               dd ?
    Version             dd ?
    EmfPlusFlags        dd ?
    DpiX                dd ? ;real4
    DpiY                dd ? ;real4
    x                   dd ?
    y                   dd ?
    nWIDTH              dd ?
    Height              dd ?
    EmfHeader           ENHMETAHEADER3
    EmfPlusHeaderSize   dd ?
    LogicalDpiX         dd ?
    LogicalDpiY         dd ?
ends

;========================================Functions=======================================;
import gdiplus,\
    GdipAddImageCodec,'GdipAddImageCodec',\
    GdipAddPathArc,'GdipAddPathArc',\
    GdipAddPathArcI,'GdipAddPathArcI',\
    GdipAddPathBezier,'GdipAddPathBezier',\
    GdipAddPathBezierI,'GdipAddPathBezierI',\
    GdipAddPathBeziers,'GdipAddPathBeziers',\
    GdipAddPathBeziersI,'GdipAddPathBeziersI',\
    GdipAddPathClosedCurve,'GdipAddPathClosedCurve',\
    GdipAddPathClosedCurve2,'GdipAddPathClosedCurve2',\
    GdipAddPathClosedCurve2I,'GdipAddPathClosedCurve2I',\
    GdipAddPathClosedCurveI,'GdipAddPathClosedCurveI',\
    GdipAddPathCurve,'GdipAddPathCurve',\
    GdipAddPathCurve2,'GdipAddPathCurve2',\
    GdipAddPathCurve2I,'GdipAddPathCurve2I',\
    GdipAddPathCurve3,'GdipAddPathCurve3',\
    GdipAddPathCurve3I,'GdipAddPathCurve3I',\
    GdipAddPathCurveI,'GdipAddPathCurveI',\
    GdipAddPathEllipse,'GdipAddPathEllipse',\
    GdipAddPathEllipseI,'GdipAddPathEllipseI',\
    GdipAddPathLine,'GdipAddPathLine',\
    GdipAddPathLine2,'GdipAddPathLine2',\
    GdipAddPathLine2I,'GdipAddPathLine2I',\
    GdipAddPathLineI,'GdipAddPathLineI',\
    GdipAddPathPath,'GdipAddPathPath',\
    GdipAddPathPie,'GdipAddPathPie',\
    GdipAddPathPieI,'GdipAddPathPieI',\
    GdipAddPathPolygon,'GdipAddPathPolygon',\
    GdipAddPathPolygonI,'GdipAddPathPolygonI',\
    GdipAddPathRectangle,'GdipAddPathRectangle',\
    GdipAddPathRectangleI,'GdipAddPathRectangleI',\
    GdipAddPathRectangles,'GdipAddPathRectangles',\
    GdipAddPathRectanglesI,'GdipAddPathRectanglesI',\
    GdipAddPathString,'GdipAddPathString',\
    GdipAddPathStringI,'GdipAddPathStringI',\
    GdipAlloc,'GdipAlloc',\
    GdipBeginContainer,'GdipBeginContainer',\
    GdipBeginContainer2,'GdipBeginContainer2',\
    GdipBeginContainerI,'GdipBeginContainerI',\
    GdipBitmapApplyEffect,'GdipBitmapApplyEffect',\
    GdipBitmapConvertFormat,'GdipBitmapConvertFormat',\
    GdipBitmapCreateApplyEffect,'GdipBitmapCreateApplyEffect',\
    GdipBitmapGetHistogram,'GdipBitmapGetHistogram',\
    GdipBitmapGetHistogramSize,'GdipBitmapGetHistogramSize',\
    GdipBitmapGetPixel,'GdipBitmapGetPixel',\
    GdipBitmapLockBits,'GdipBitmapLockBits',\
    GdipBitmapSetPixel,'GdipBitmapSetPixel',\
    GdipBitmapSetResolution,'GdipBitmapSetResolution',\
    GdipBitmapUnlockBits,'GdipBitmapUnlockBits',\
    GdipClearPathMarkers,'GdipClearPathMarkers',\
    GdipCloneBitmapArea,'GdipCloneBitmapArea',\
    GdipCloneBitmapAreaI,'GdipCloneBitmapAreaI',\
    GdipCloneBrush,'GdipCloneBrush',\
    GdipCloneCustomLineCap,'GdipCloneCustomLineCap',\
    GdipCloneFont,'GdipCloneFont',\
    GdipCloneFontFamily,'GdipCloneFontFamily',\
    GdipCloneImage,'GdipCloneImage',\
    GdipCloneImageAttributes,'GdipCloneImageAttributes',\
    GdipCloneMatrix,'GdipCloneMatrix',\
    GdipClonePath,'GdipClonePath',\
    GdipClonePen,'GdipClonePen',\
    GdipCloneRegion,'GdipCloneRegion',\
    GdipCloneStringFormat,'GdipCloneStringFormat',\
    GdipClosePathFigure,'GdipClosePathFigure',\
    GdipClosePathFigures,'GdipClosePathFigures',\
    GdipCombineRegionPath,'GdipCombineRegionPath',\
    GdipCombineRegionRect,'GdipCombineRegionRect',\
    GdipCombineRegionRectI,'GdipCombineRegionRectI',\
    GdipCombineRegionRegion,'GdipCombineRegionRegion',\
    GdipComment,'GdipComment',\
    GdipConvertToEmfPlus,'GdipConvertToEmfPlus',\
    GdipConvertToEmfPlusToFile,'GdipConvertToEmfPlusToFile',\
    GdipConvertToEmfPlusToStream,'GdipConvertToEmfPlusToStream',\
    GdipCreateAdjustableArrowCap,'GdipCreateAdjustableArrowCap',\
    GdipCreateBitmapFromDirectDrawSurface,'GdipCreateBitmapFromDirectDrawSurface',\
    GdipCreateBitmapFromFile,'GdipCreateBitmapFromFile',\
    GdipCreateBitmapFromFileICM,'GdipCreateBitmapFromFileICM',\
    GdipCreateBitmapFromGdiDib,'GdipCreateBitmapFromGdiDib',\
    GdipCreateBitmapFromGraphics,'GdipCreateBitmapFromGraphics',\
    GdipCreateBitmapFromHBITMAP,'GdipCreateBitmapFromHBITMAP',\
    GdipCreateBitmapFromHICON,'GdipCreateBitmapFromHICON',\
    GdipCreateBitmapFromResource,'GdipCreateBitmapFromResource',\
    GdipCreateBitmapFromScan0,'GdipCreateBitmapFromScan0',\
    GdipCreateBitmapFromStream,'GdipCreateBitmapFromStream',\
    GdipCreateBitmapFromStreamICM,'GdipCreateBitmapFromStreamICM',\
    GdipCreateCachedBitmap,'GdipCreateCachedBitmap',\
    GdipCreateCustomLineCap,'GdipCreateCustomLineCap',\
    GdipCreateEffect,'GdipCreateEffect',\
    GdipCreateFont,'GdipCreateFont',\
    GdipCreateFontFamilyFromName,'GdipCreateFontFamilyFromName',\
    GdipCreateFontFromDC,'GdipCreateFontFromDC',\
    GdipCreateFontFromLogfontA,'GdipCreateFontFromLogfontA',\
    GdipCreateFontFromLogfontW,'GdipCreateFontFromLogfontW',\
    GdipCreateFromHDC,'GdipCreateFromHDC',\
    GdipCreateFromHDC2,'GdipCreateFromHDC2',\
    GdipCreateFromHWND,'GdipCreateFromHWND',\
    GdipCreateFromHWNDICM,'GdipCreateFromHWNDICM',\
    GdipCreateHalftonePalette,'GdipCreateHalftonePalette',\
    GdipCreateHatchBrush,'GdipCreateHatchBrush',\
    GdipCreateHBITMAPFromBitmap,'GdipCreateHBITMAPFromBitmap',\
    GdipCreateHICONFromBitmap,'GdipCreateHICONFromBitmap',\
    GdipCreateImageAttributes,'GdipCreateImageAttributes',\
    GdipCreateLineBrush,'GdipCreateLineBrush',\
    GdipCreateLineBrushFromRect,'GdipCreateLineBrushFromRect',\
    GdipCreateLineBrushFromRectI,'GdipCreateLineBrushFromRectI',\
    GdipCreateLineBrushFromRectWithAngle,'GdipCreateLineBrushFromRectWithAngle',\
    GdipCreateLineBrushFromRectWithAngleI,'GdipCreateLineBrushFromRectWithAngleI',\
    GdipCreateLineBrushI,'GdipCreateLineBrushI',\
    GdipCreateMatrix,'GdipCreateMatrix',\
    GdipCreateMatrix2,'GdipCreateMatrix2',\
    GdipCreateMatrix3,'GdipCreateMatrix3',\
    GdipCreateMatrix3I,'GdipCreateMatrix3I',\
    GdipCreateMetafileFromEmf,'GdipCreateMetafileFromEmf',\
    GdipCreateMetafileFromFile,'GdipCreateMetafileFromFile',\
    GdipCreateMetafileFromStream,'GdipCreateMetafileFromStream',\
    GdipCreateMetafileFromWmf,'GdipCreateMetafileFromWmf',\
    GdipCreateMetafileFromWmfFile,'GdipCreateMetafileFromWmfFile',\
    GdipCreatePath,'GdipCreatePath',\
    GdipCreatePath2,'GdipCreatePath2',\
    GdipCreatePath2I,'GdipCreatePath2I',\
    GdipCreatePathGradient,'GdipCreatePathGradient',\
    GdipCreatePathGradientFromPath,'GdipCreatePathGradientFromPath',\
    GdipCreatePathGradientI,'GdipCreatePathGradientI',\
    GdipCreatePathIter,'GdipCreatePathIter',\
    GdipCreatePen1,'GdipCreatePen1',\
    GdipCreatePen2,'GdipCreatePen2',\
    GdipCreateRegion,'GdipCreateRegion',\
    GdipCreateRegionHrgn,'GdipCreateRegionHrgn',\
    GdipCreateRegionPath,'GdipCreateRegionPath',\
    GdipCreateRegionRect,'GdipCreateRegionRect',\
    GdipCreateRegionRectI,'GdipCreateRegionRectI',\
    GdipCreateRegionRgnData,'GdipCreateRegionRgnData',\
    GdipCreateSolidFill,'GdipCreateSolidFill',\
    GdipCreateStreamOnFile,'GdipCreateStreamOnFile',\
    GdipCreateStringFormat,'GdipCreateStringFormat',\
    GdipCreateTexture,'GdipCreateTexture',\
    GdipCreateTexture2,'GdipCreateTexture2',\
    GdipCreateTexture2I,'GdipCreateTexture2I',\
    GdipCreateTextureIA,'GdipCreateTextureIA',\
    GdipCreateTextureIAI,'GdipCreateTextureIAI',\
    GdipDeleteBrush,'GdipDeleteBrush',\
    GdipDeleteCachedBitmap,'GdipDeleteCachedBitmap',\
    GdipDeleteCustomLineCap,'GdipDeleteCustomLineCap',\
    GdipDeleteEffect,'GdipDeleteEffect',\
    GdipDeleteFont,'GdipDeleteFont',\
    GdipDeleteFontFamily,'GdipDeleteFontFamily',\
    GdipDeleteGraphics,'GdipDeleteGraphics',\
    GdipDeleteMatrix,'GdipDeleteMatrix',\
    GdipDeletePath,'GdipDeletePath',\
    GdipDeletePathIter,'GdipDeletePathIter',\
    GdipDeletePen,'GdipDeletePen',\
    GdipDeletePrivateFontCollection,'GdipDeletePrivateFontCollection',\
    GdipDeleteRegion,'GdipDeleteRegion',\
    GdipDeleteStringFormat,'GdipDeleteStringFormat',\
    GdipDisposeImage,'GdipDisposeImage',\
    GdipDisposeImageAttributes,'GdipDisposeImageAttributes',\
    GdipDrawArc,'GdipDrawArc',\
    GdipDrawArcI,'GdipDrawArcI',\
    GdipDrawBezier,'GdipDrawBezier',\
    GdipDrawBezierI,'GdipDrawBezierI',\
    GdipDrawBeziers,'GdipDrawBeziers',\
    GdipDrawBeziersI,'GdipDrawBeziersI',\
    GdipDrawCachedBitmap,'GdipDrawCachedBitmap',\
    GdipDrawClosedCurve,'GdipDrawClosedCurve',\
    GdipDrawClosedCurve2,'GdipDrawClosedCurve2',\
    GdipDrawClosedCurve2I,'GdipDrawClosedCurve2I',\
    GdipDrawClosedCurveI,'GdipDrawClosedCurveI',\
    GdipDrawCurve,'GdipDrawCurve',\
    GdipDrawCurve2,'GdipDrawCurve2',\
    GdipDrawCurve2I,'GdipDrawCurve2I',\
    GdipDrawCurve3,'GdipDrawCurve3',\
    GdipDrawCurve3I,'GdipDrawCurve3I',\
    GdipDrawCurveI,'GdipDrawCurveI',\
    GdipDrawDriverString,'GdipDrawDriverString',\
    GdipDrawEllipse,'GdipDrawEllipse',\
    GdipDrawEllipseI,'GdipDrawEllipseI',\
    GdipDrawImage,'GdipDrawImage',\
    GdipDrawImageFX,'GdipDrawImageFX',\
    GdipDrawImageI,'GdipDrawImageI',\
    GdipDrawImagePointRect,'GdipDrawImagePointRect',\
    GdipDrawImagePointRectI,'GdipDrawImagePointRectI',\
    GdipDrawImagePoints,'GdipDrawImagePoints',\
    GdipDrawImagePointsI,'GdipDrawImagePointsI',\
    GdipDrawImagePointsRect,'GdipDrawImagePointsRect',\
    GdipDrawImagePointsRectI,'GdipDrawImagePointsRectI',\
    GdipDrawImageRect,'GdipDrawImageRect',\
    GdipDrawImageRectI,'GdipDrawImageRectI',\
    GdipDrawImageRectRect,'GdipDrawImageRectRect',\
    GdipDrawImageRectRectI,'GdipDrawImageRectRectI',\
    GdipDrawLine,'GdipDrawLine',\
    GdipDrawLineI,'GdipDrawLineI',\
    GdipDrawLines,'GdipDrawLines',\
    GdipDrawLinesI,'GdipDrawLinesI',\
    GdipDrawPath,'GdipDrawPath',\
    GdipDrawPie,'GdipDrawPie',\
    GdipDrawPieI,'GdipDrawPieI',\
    GdipDrawPolygon,'GdipDrawPolygon',\
    GdipDrawPolygonI,'GdipDrawPolygonI',\
    GdipDrawRectangle,'GdipDrawRectangle',\
    GdipDrawRectangleI,'GdipDrawRectangleI',\
    GdipDrawRectangles,'GdipDrawRectangles',\
    GdipDrawRectanglesI,'GdipDrawRectanglesI',\
    GdipDrawString,'GdipDrawString',\
    GdipEmfToWmfBits,'GdipEmfToWmfBits',\
    GdipEndContainer,'GdipEndContainer',\
    GdipEnumerateMetafileDestPoint,'GdipEnumerateMetafileDestPoint',\
    GdipEnumerateMetafileDestPointI,'GdipEnumerateMetafileDestPointI',\
    GdipEnumerateMetafileDestPoints,'GdipEnumerateMetafileDestPoints',\
    GdipEnumerateMetafileDestPointsI,'GdipEnumerateMetafileDestPointsI',\
    GdipEnumerateMetafileDestRect,'GdipEnumerateMetafileDestRect',\
    GdipEnumerateMetafileDestRectI,'GdipEnumerateMetafileDestRectI',\
    GdipEnumerateMetafileSrcRectDestPoint,'GdipEnumerateMetafileSrcRectDestPoint',\
    GdipEnumerateMetafileSrcRectDestPointI,'GdipEnumerateMetafileSrcRectDestPointI',\
    GdipEnumerateMetafileSrcRectDestPoints,'GdipEnumerateMetafileSrcRectDestPoints',\
    GdipEnumerateMetafileSrcRectDestPointsI,'GdipEnumerateMetafileSrcRectDestPointsI',\
    GdipEnumerateMetafileSrcRectDestRect,'GdipEnumerateMetafileSrcRectDestRect',\
    GdipEnumerateMetafileSrcRectDestRectI,'GdipEnumerateMetafileSrcRectDestRectI',\
    GdipFillClosedCurve,'GdipFillClosedCurve',\
    GdipFillClosedCurve2,'GdipFillClosedCurve2',\
    GdipFillClosedCurve2I,'GdipFillClosedCurve2I',\
    GdipFillClosedCurveI,'GdipFillClosedCurveI',\
    GdipFillEllipse,'GdipFillEllipse',\
    GdipFillEllipseI,'GdipFillEllipseI',\
    GdipFillPath,'GdipFillPath',\
    GdipFillPie,'GdipFillPie',\
    GdipFillPieI,'GdipFillPieI',\
    GdipFillPolygon,'GdipFillPolygon',\
    GdipFillPolygon2,'GdipFillPolygon2',\
    GdipFillPolygon2I,'GdipFillPolygon2I',\
    GdipFillPolygonI,'GdipFillPolygonI',\
    GdipFillRectangle,'GdipFillRectangle',\
    GdipFillRectangleI,'GdipFillRectangleI',\
    GdipFillRectangles,'GdipFillRectangles',\
    GdipFillRectanglesI,'GdipFillRectanglesI',\
    GdipFillRegion,'GdipFillRegion',\
    GdipFindFirstImageItem,'GdipFindFirstImageItem',\
    GdipFindNextImageItem,'GdipFindNextImageItem',\
    GdipFlattenPath,'GdipFlattenPath',\
    GdipFlush,'GdipFlush',\
    GdipFree,'GdipFree',\
    GdipGetAdjustableArrowCapFillState,'GdipGetAdjustableArrowCapFillState',\
    GdipGetAdjustableArrowCapHeight,'GdipGetAdjustableArrowCapHeight',\
    GdipGetAdjustableArrowCapMiddleInset,'GdipGetAdjustableArrowCapMiddleInset',\
    GdipGetAdjustableArrowCapWidth,'GdipGetAdjustableArrowCapWidth',\
    GdipGetAllPropertyItems,'GdipGetAllPropertyItems',\
    GdipGetBrushType,'GdipGetBrushType',\
    GdipGetCellAscent,'GdipGetCellAscent',\
    GdipGetCellDescent,'GdipGetCellDescent',\
    GdipGetClip,'GdipGetClip',\
    GdipGetClipBounds,'GdipGetClipBounds',\
    GdipGetClipBoundsI,'GdipGetClipBoundsI',\
    GdipGetCompositingMode,'GdipGetCompositingMode',\
    GdipGetCompositingQuality,'GdipGetCompositingQuality',\
    GdipGetCustomLineCapBaseCap,'GdipGetCustomLineCapBaseCap',\
    GdipGetCustomLineCapBaseInset,'GdipGetCustomLineCapBaseInset',\
    GdipGetCustomLineCapStrokeCaps,'GdipGetCustomLineCapStrokeCaps',\
    GdipGetCustomLineCapStrokeJoin,'GdipGetCustomLineCapStrokeJoin',\
    GdipGetCustomLineCapType,'GdipGetCustomLineCapType',\
    GdipGetCustomLineCapWidthScale,'GdipGetCustomLineCapWidthScale',\
    GdipGetDC,'GdipGetDC',\
    GdipGetDpiX,'GdipGetDpiX',\
    GdipGetDpiY,'GdipGetDpiY',\
    GdipGetEffectParameters,'GdipGetEffectParameters',\
    GdipGetEffectParameterSize,'GdipGetEffectParameterSize',\
    GdipGetEmHeight,'GdipGetEmHeight',\
    GdipGetEncoderParameterList,'GdipGetEncoderParameterList',\
    GdipGetEncoderParameterListSize,'GdipGetEncoderParameterListSize',\
    GdipGetFamily,'GdipGetFamily',\
    GdipGetFamilyName,'GdipGetFamilyName',\
    GdipGetFontCollectionFamilyCount,'GdipGetFontCollectionFamilyCount',\
    GdipGetFontCollectionFamilyList,'GdipGetFontCollectionFamilyList',\
    GdipGetFontHeight,'GdipGetFontHeight',\
    GdipGetFontHeightGivenDPI,'GdipGetFontHeightGivenDPI',\
    GdipGetFontSize,'GdipGetFontSize',\
    GdipGetFontStyle,'GdipGetFontStyle',\
    GdipGetFontUnit,'GdipGetFontUnit',\
    GdipGetGenericFontFamilyMonospace,'GdipGetGenericFontFamilyMonospace',\
    GdipGetGenericFontFamilySansSerif,'GdipGetGenericFontFamilySansSerif',\
    GdipGetGenericFontFamilySerif,'GdipGetGenericFontFamilySerif',\
    GdipGetGraphicsLayout,'GdipGetGraphicsLayout',\
    GdipGetHatchBackgroundColor,'GdipGetHatchBackgroundColor',\
    GdipGetHatchForegroundColor,'GdipGetHatchForegroundColor',\
    GdipGetHatchStyle,'GdipGetHatchStyle',\
    GdipGetHemfFromMetafile,'GdipGetHemfFromMetafile',\
    GdipGetImageAttributesAdjustedPalette,'GdipGetImageAttributesAdjustedPalette',\
    GdipGetImageBounds,'GdipGetImageBounds',\
    GdipGetImageDecoders,'GdipGetImageDecoders',\
    GdipGetImageDecodersSize,'GdipGetImageDecodersSize',\
    GdipGetImageDimension,'GdipGetImageDimension',\
    GdipGetImageEncoders,'GdipGetImageEncoders',\
    GdipGetImageEncodersSize,'GdipGetImageEncodersSize',\
    GdipGetImageFlags,'GdipGetImageFlags',\
    GdipGetImageGraphicsContext,'GdipGetImageGraphicsContext',\
    GdipGetImageHeight,'GdipGetImageHeight',\
    GdipGetImageHorizontalResolution,'GdipGetImageHorizontalResolution',\
    GdipGetImageLayout,'GdipGetImageLayout',\
    GdipGetImagePalette,'GdipGetImagePalette',\
    GdipGetImagePaletteSize,'GdipGetImagePaletteSize',\
    GdipGetImagePixelFormat,'GdipGetImagePixelFormat',\
    GdipGetImageRawFormat,'GdipGetImageRawFormat',\
    GdipGetImageThumbnail,'GdipGetImageThumbnail',\
    GdipGetImageType,'GdipGetImageType',\
    GdipGetImageVerticalResolution,'GdipGetImageVerticalResolution',\
    GdipGetImageWidth,'GdipGetImageWidth',\
    GdipGetInterpolationMode,'GdipGetInterpolationMode',\
    GdipGetLineBlend,'GdipGetLineBlend',\
    GdipGetLineBlendCount,'GdipGetLineBlendCount',\
    GdipGetLineColors,'GdipGetLineColors',\
    GdipGetLineGammaCorrection,'GdipGetLineGammaCorrection',\
    GdipGetLinePoints,'GdipGetLinePoints',\
    GdipGetLinePointsI,'GdipGetLinePointsI',\
    GdipGetLinePresetBlend,'GdipGetLinePresetBlend',\
    GdipGetLinePresetBlendCount,'GdipGetLinePresetBlendCount',\
    GdipGetLineRect,'GdipGetLineRect',\
    GdipGetLineRectI,'GdipGetLineRectI',\
    GdipGetLineSpacing,'GdipGetLineSpacing',\
    GdipGetLineTransform,'GdipGetLineTransform',\
    GdipGetLineWrapMode,'GdipGetLineWrapMode',\
    GdipGetLogFontA,'GdipGetLogFontA',\
    GdipGetLogFontW,'GdipGetLogFontW',\
    GdipGetMatrixElements,'GdipGetMatrixElements',\
    GdipGetMetafileDownLevelRasterizationLimit,'GdipGetMetafileDownLevelRasterizationLimit',\
    GdipGetMetafileHeaderFromEmf,'GdipGetMetafileHeaderFromEmf',\
    GdipGetMetafileHeaderFromFile,'GdipGetMetafileHeaderFromFile',\
    GdipGetMetafileHeaderFromMetafile,'GdipGetMetafileHeaderFromMetafile',\
    GdipGetMetafileHeaderFromStream,'GdipGetMetafileHeaderFromStream',\
    GdipGetMetafileHeaderFromWmf,'GdipGetMetafileHeaderFromWmf',\
    GdipGetNearestColor,'GdipGetNearestColor',\
    GdipGetPageScale,'GdipGetPageScale',\
    GdipGetPageUnit,'GdipGetPageUnit',\
    GdipGetPathData,'GdipGetPathData',\
    GdipGetPathFillMode,'GdipGetPathFillMode',\
    GdipGetPathGradientBlend,'GdipGetPathGradientBlend',\
    GdipGetPathGradientBlendCount,'GdipGetPathGradientBlendCount',\
    GdipGetPathGradientCenterColor,'GdipGetPathGradientCenterColor',\
    GdipGetPathGradientCenterPoint,'GdipGetPathGradientCenterPoint',\
    GdipGetPathGradientCenterPointI,'GdipGetPathGradientCenterPointI',\
    GdipGetPathGradientFocusScales,'GdipGetPathGradientFocusScales',\
    GdipGetPathGradientGammaCorrection,'GdipGetPathGradientGammaCorrection',\
    GdipGetPathGradientPath,'GdipGetPathGradientPath',\
    GdipGetPathGradientPointCount,'GdipGetPathGradientPointCount',\
    GdipGetPathGradientPresetBlend,'GdipGetPathGradientPresetBlend',\
    GdipGetPathGradientPresetBlendCount,'GdipGetPathGradientPresetBlendCount',\
    GdipGetPathGradientRect,'GdipGetPathGradientRect',\
    GdipGetPathGradientRectI,'GdipGetPathGradientRectI',\
    GdipGetPathGradientSurroundColorCount,'GdipGetPathGradientSurroundColorCount',\
    GdipGetPathGradientSurroundColorsWithCount,'GdipGetPathGradientSurroundColorsWithCount',\
    GdipGetPathGradientTransform,'GdipGetPathGradientTransform',\
    GdipGetPathGradientWrapMode,'GdipGetPathGradientWrapMode',\
    GdipGetPathLastPoint,'GdipGetPathLastPoint',\
    GdipGetPathPoints,'GdipGetPathPoints',\
    GdipGetPathPointsI,'GdipGetPathPointsI',\
    GdipGetPathTypes,'GdipGetPathTypes',\
    GdipGetPathWorldBounds,'GdipGetPathWorldBounds',\
    GdipGetPathWorldBoundsI,'GdipGetPathWorldBoundsI',\
    GdipGetPenBrushFill,'GdipGetPenBrushFill',\
    GdipGetPenColor,'GdipGetPenColor',\
    GdipGetPenCompoundArray,'GdipGetPenCompoundArray',\
    GdipGetPenCompoundCount,'GdipGetPenCompoundCount',\
    GdipGetPenCustomEndCap,'GdipGetPenCustomEndCap',\
    GdipGetPenCustomStartCap,'GdipGetPenCustomStartCap',\
    GdipGetPenDashArray,'GdipGetPenDashArray',\
    GdipGetPenDashCap197819,'GdipGetPenDashCap197819',\
    GdipGetPenDashCount,'GdipGetPenDashCount',\
    GdipGetPenDashOffset,'GdipGetPenDashOffset',\
    GdipGetPenDashStyle,'GdipGetPenDashStyle',\
    GdipGetPenEndCap,'GdipGetPenEndCap',\
    GdipGetPenFillType,'GdipGetPenFillType',\
    GdipGetPenLineJoin,'GdipGetPenLineJoin',\
    GdipGetPenMiterLimit,'GdipGetPenMiterLimit',\
    GdipGetPenMode,'GdipGetPenMode',\
    GdipGetPenStartCap,'GdipGetPenStartCap',\
    GdipGetPenTransform,'GdipGetPenTransform',\
    GdipGetPenUnit,'GdipGetPenUnit',\
    GdipGetPenWidth,'GdipGetPenWidth',\
    GdipGetPixelOffsetMode,'GdipGetPixelOffsetMode',\
    GdipGetPointCount,'GdipGetPointCount',\
    GdipGetPropertyCount,'GdipGetPropertyCount',\
    GdipGetPropertyIdList,'GdipGetPropertyIdList',\
    GdipGetPropertyItem,'GdipGetPropertyItem',\
    GdipGetPropertyItemSize,'GdipGetPropertyItemSize',\
    GdipGetPropertySize,'GdipGetPropertySize',\
    GdipGetRegionBounds,'GdipGetRegionBounds',\
    GdipGetRegionBoundsI,'GdipGetRegionBoundsI',\
    GdipGetRegionData,'GdipGetRegionData',\
    GdipGetRegionDataSize,'GdipGetRegionDataSize',\
    GdipGetRegionHRgn,'GdipGetRegionHRgn',\
    GdipGetRegionScans,'GdipGetRegionScans',\
    GdipGetRegionScansCount,'GdipGetRegionScansCount',\
    GdipGetRegionScansI,'GdipGetRegionScansI',\
    GdipGetRenderingOrigin,'GdipGetRenderingOrigin',\
    GdipGetSmoothingMode,'GdipGetSmoothingMode',\
    GdipGetSolidFillColor,'GdipGetSolidFillColor',\
    GdipGetStringFormatAlign,'GdipGetStringFormatAlign',\
    GdipGetStringFormatDigitSubstitution,'GdipGetStringFormatDigitSubstitution',\
    GdipGetStringFormatFlags,'GdipGetStringFormatFlags',\
    GdipGetStringFormatHotkeyPrefix,'GdipGetStringFormatHotkeyPrefix',\
    GdipGetStringFormatLineAlign,'GdipGetStringFormatLineAlign',\
    GdipGetStringFormatMeasurableCharacterRangeCount,'GdipGetStringFormatMeasurableCharacterRangeCount',\
    GdipGetStringFormatTabStopCount,'GdipGetStringFormatTabStopCount',\
    GdipGetStringFormatTabStops,'GdipGetStringFormatTabStops',\
    GdipGetStringFormatTrimming,'GdipGetStringFormatTrimming',\
    GdipGetTextContrast,'GdipGetTextContrast',\
    GdipGetTextRenderingHint,'GdipGetTextRenderingHint',\
    GdipGetTextureImage,'GdipGetTextureImage',\
    GdipGetTextureTransform,'GdipGetTextureTransform',\
    GdipGetTextureWrapMode,'GdipGetTextureWrapMode',\
    GdipGetVisibleClipBounds,'GdipGetVisibleClipBounds',\
    GdipGetVisibleClipBoundsI,'GdipGetVisibleClipBoundsI',\
    GdipGetWorldTransform,'GdipGetWorldTransform',\
    GdipGraphicsClear,'GdipGraphicsClear',\
    GdipGraphicsSetAbort,'GdipGraphicsSetAbort',\
    GdipImageForceValidation,'GdipImageForceValidation',\
    GdipImageGetFrameCount,'GdipImageGetFrameCount',\
    GdipImageGetFrameDimensionsCount,'GdipImageGetFrameDimensionsCount',\
    GdipImageGetFrameDimensionsList,'GdipImageGetFrameDimensionsList',\
    GdipImageRotateFlip,'GdipImageRotateFlip',\
    GdipImageSelectActiveFrame,'GdipImageSelectActiveFrame',\
    GdipImageSetAbort,'GdipImageSetAbort',\
    GdipInitializePalette,'GdipInitializePalette',\
    GdipInvertMatrix,'GdipInvertMatrix',\
    GdipIsClipEmpty,'GdipIsClipEmpty',\
    GdipIsEmptyRegion,'GdipIsEmptyRegion',\
    GdipIsEqualRegion,'GdipIsEqualRegion',\
    GdipIsInfiniteRegion,'GdipIsInfiniteRegion',\
    GdipIsMatrixEqual,'GdipIsMatrixEqual',\
    GdipIsMatrixIdentity,'GdipIsMatrixIdentity',\
    GdipIsMatrixInvertible,'GdipIsMatrixInvertible',\
    GdipIsOutlineVisiblePathPoint,'GdipIsOutlineVisiblePathPoint',\
    GdipIsOutlineVisiblePathPointI,'GdipIsOutlineVisiblePathPointI',\
    GdipIsStyleAvailable,'GdipIsStyleAvailable',\
    GdipIsVisibleClipEmpty,'GdipIsVisibleClipEmpty',\
    GdipIsVisiblePathPoint,'GdipIsVisiblePathPoint',\
    GdipIsVisiblePathPointI,'GdipIsVisiblePathPointI',\
    GdipIsVisiblePoint,'GdipIsVisiblePoint',\
    GdipIsVisiblePointI,'GdipIsVisiblePointI',\
    GdipIsVisibleRect,'GdipIsVisibleRect',\
    GdipIsVisibleRectI,'GdipIsVisibleRectI',\
    GdipIsVisibleRegionPoint,'GdipIsVisibleRegionPoint',\
    GdipIsVisibleRegionPointI,'GdipIsVisibleRegionPointI',\
    GdipIsVisibleRegionRect,'GdipIsVisibleRegionRect',\
    GdipIsVisibleRegionRectI,'GdipIsVisibleRegionRectI',\
    GdipLoadImageFromFile,'GdipLoadImageFromFile',\
    GdipLoadImageFromFileICM,'GdipLoadImageFromFileICM',\
    GdipLoadImageFromStream,'GdipLoadImageFromStream',\
    GdipLoadImageFromStreamICM,'GdipLoadImageFromStreamICM',\
    GdipMeasureCharacterRanges,'GdipMeasureCharacterRanges',\
    GdipMeasureDriverString,'GdipMeasureDriverString',\
    GdipMeasureString,'GdipMeasureString',\
    GdipMultiplyLineTransform,'GdipMultiplyLineTransform',\
    GdipMultiplyMatrix,'GdipMultiplyMatrix',\
    GdipMultiplyPathGradientTransform,'GdipMultiplyPathGradientTransform',\
    GdipMultiplyPenTransform,'GdipMultiplyPenTransform',\
    GdipMultiplyTextureTransform,'GdipMultiplyTextureTransform',\
    GdipMultiplyWorldTransform,'GdipMultiplyWorldTransform',\
    GdipNewInstalledFontCollection,'GdipNewInstalledFontCollection',\
    GdipNewPrivateFontCollection,'GdipNewPrivateFontCollection',\
    GdipPathIterCopyData,'GdipPathIterCopyData',\
    GdipPathIterEnumerate,'GdipPathIterEnumerate',\
    GdipPathIterGetCount,'GdipPathIterGetCount',\
    GdipPathIterGetSubpathCount,'GdipPathIterGetSubpathCount',\
    GdipPathIterHasCurve,'GdipPathIterHasCurve',\
    GdipPathIterIsValid,'GdipPathIterIsValid',\
    GdipPathIterNextMarker,'GdipPathIterNextMarker',\
    GdipPathIterNextMarkerPath,'GdipPathIterNextMarkerPath',\
    GdipPathIterNextPathType,'GdipPathIterNextPathType',\
    GdipPathIterNextSubpath,'GdipPathIterNextSubpath',\
    GdipPathIterNextSubpathPath,'GdipPathIterNextSubpathPath',\
    GdipPathIterRewind,'GdipPathIterRewind',\
    GdipPlayMetafileRecord,'GdipPlayMetafileRecord',\
    GdiplusNotificationHook,'GdiplusNotificationHook',\
    GdiplusNotificationUnhook,'GdiplusNotificationUnhook',\
    GdiplusShutdown,'GdiplusShutdown',\
    GdiplusStartup,'GdiplusStartup',\
    GdipPrivateAddFontFile,'GdipPrivateAddFontFile',\
    GdipPrivateAddMemoryFont,'GdipPrivateAddMemoryFont',\
    GdipRecordMetafile,'GdipRecordMetafile',\
    GdipRecordMetafileFileName,'GdipRecordMetafileFileName',\
    GdipRecordMetafileFileNameI,'GdipRecordMetafileFileNameI',\
    GdipRecordMetafileI,'GdipRecordMetafileI',\
    GdipRecordMetafileStream,'GdipRecordMetafileStream',\
    GdipRecordMetafileStreamI,'GdipRecordMetafileStreamI',\
    GdipReleaseDC,'GdipReleaseDC',\
    GdipRemoveImageCodec,'GdipRemoveImageCodec',\
    GdipRemovePropertyItem,'GdipRemovePropertyItem',\
    GdipResetClip,'GdipResetClip',\
    GdipResetImageAttributes,'GdipResetImageAttributes',\
    GdipResetLineTransform,'GdipResetLineTransform',\
    GdipResetPageTransform,'GdipResetPageTransform',\
    GdipResetPath,'GdipResetPath',\
    GdipResetPathGradientTransform,'GdipResetPathGradientTransform',\
    GdipResetPenTransform,'GdipResetPenTransform',\
    GdipResetTextureTransform,'GdipResetTextureTransform',\
    GdipResetWorldTransform,'GdipResetWorldTransform',\
    GdipRestoreGraphics,'GdipRestoreGraphics',\
    GdipReversePath,'GdipReversePath',\
    GdipRotateLineTransform,'GdipRotateLineTransform',\
    GdipRotateMatrix,'GdipRotateMatrix',\
    GdipRotatePathGradientTransform,'GdipRotatePathGradientTransform',\
    GdipRotatePenTransform,'GdipRotatePenTransform',\
    GdipRotateTextureTransform,'GdipRotateTextureTransform',\
    GdipRotateWorldTransform,'GdipRotateWorldTransform',\
    GdipSaveAdd,'GdipSaveAdd',\
    GdipSaveAddImage,'GdipSaveAddImage',\
    GdipSaveGraphics,'GdipSaveGraphics',\
    GdipSaveImageToFile,'GdipSaveImageToFile',\
    GdipSaveImageToStream,'GdipSaveImageToStream',\
    GdipScaleLineTransform,'GdipScaleLineTransform',\
    GdipScaleMatrix,'GdipScaleMatrix',\
    GdipScalePathGradientTransform,'GdipScalePathGradientTransform',\
    GdipScalePenTransform,'GdipScalePenTransform',\
    GdipScaleTextureTransform,'GdipScaleTextureTransform',\
    GdipScaleWorldTransform,'GdipScaleWorldTransform',\
    GdipSetAdjustableArrowCapFillState,'GdipSetAdjustableArrowCapFillState',\
    GdipSetAdjustableArrowCapHeight,'GdipSetAdjustableArrowCapHeight',\
    GdipSetAdjustableArrowCapMiddleInset,'GdipSetAdjustableArrowCapMiddleInset',\
    GdipSetAdjustableArrowCapWidth,'GdipSetAdjustableArrowCapWidth',\
    GdipSetClipGraphics,'GdipSetClipGraphics',\
    GdipSetClipHrgn,'GdipSetClipHrgn',\
    GdipSetClipPath,'GdipSetClipPath',\
    GdipSetClipRect,'GdipSetClipRect',\
    GdipSetClipRectI,'GdipSetClipRectI',\
    GdipSetClipRegion,'GdipSetClipRegion',\
    GdipSetCompositingMode,'GdipSetCompositingMode',\
    GdipSetCompositingQuality,'GdipSetCompositingQuality',\
    GdipSetCustomLineCapBaseCap,'GdipSetCustomLineCapBaseCap',\
    GdipSetCustomLineCapBaseInset,'GdipSetCustomLineCapBaseInset',\
    GdipSetCustomLineCapStrokeCaps,'GdipSetCustomLineCapStrokeCaps',\
    GdipSetCustomLineCapStrokeJoin,'GdipSetCustomLineCapStrokeJoin',\
    GdipSetCustomLineCapWidthScale,'GdipSetCustomLineCapWidthScale',\
    GdipSetEffectParameters,'GdipSetEffectParameters',\
    GdipSetEmpty,'GdipSetEmpty',\
    GdipSetGraphicsLayout,'GdipSetGraphicsLayout',\
    GdipSetImageAttributesCachedBackground,'GdipSetImageAttributesCachedBackground',\
    GdipSetImageAttributesColorKeys,'GdipSetImageAttributesColorKeys',\
    GdipSetImageAttributesColorMatrix,'GdipSetImageAttributesColorMatrix',\
    GdipSetImageAttributesGamma,'GdipSetImageAttributesGamma',\
    GdipSetImageAttributesNoOp,'GdipSetImageAttributesNoOp',\
    GdipSetImageAttributesOutputChannel,'GdipSetImageAttributesOutputChannel',\
    GdipSetImageAttributesOutputChannelColorProfile,'GdipSetImageAttributesOutputChannelColorProfile',\
    GdipSetImageAttributesRemapTable,'GdipSetImageAttributesRemapTable',\
    GdipSetImageAttributesThreshold,'GdipSetImageAttributesThreshold',\
    GdipSetImageAttributesToIdentity,'GdipSetImageAttributesToIdentity',\
    GdipSetImageAttributesWrapMode,'GdipSetImageAttributesWrapMode',\
    GdipSetImageLayout,'GdipSetImageLayout',\
    GdipSetImagePalette,'GdipSetImagePalette',\
    GdipSetInfinite,'GdipSetInfinite',\
    GdipSetInterpolationMode,'GdipSetInterpolationMode',\
    GdipSetLineBlend,'GdipSetLineBlend',\
    GdipSetLineColors,'GdipSetLineColors',\
    GdipSetLineGammaCorrection,'GdipSetLineGammaCorrection',\
    GdipSetLineLinearBlend,'GdipSetLineLinearBlend',\
    GdipSetLinePoints,'GdipSetLinePoints',\
    GdipSetLinePointsI,'GdipSetLinePointsI',\
    GdipSetLinePresetBlend,'GdipSetLinePresetBlend',\
    GdipSetLineSigmaBlend,'GdipSetLineSigmaBlend',\
    GdipSetLineTransform,'GdipSetLineTransform',\
    GdipSetLineWrapMode,'GdipSetLineWrapMode',\
    GdipSetMatrixElements,'GdipSetMatrixElements',\
    GdipSetMetafileDownLevelRasterizationLimit,'GdipSetMetafileDownLevelRasterizationLimit',\
    GdipSetPageScale,'GdipSetPageScale',\
    GdipSetPageUnit,'GdipSetPageUnit',\
    GdipSetPathFillMode,'GdipSetPathFillMode',\
    GdipSetPathGradientBlend,'GdipSetPathGradientBlend',\
    GdipSetPathGradientCenterColor,'GdipSetPathGradientCenterColor',\
    GdipSetPathGradientCenterPoint,'GdipSetPathGradientCenterPoint',\
    GdipSetPathGradientCenterPointI,'GdipSetPathGradientCenterPointI',\
    GdipSetPathGradientFocusScales,'GdipSetPathGradientFocusScales',\
    GdipSetPathGradientGammaCorrection,'GdipSetPathGradientGammaCorrection',\
    GdipSetPathGradientLinearBlend,'GdipSetPathGradientLinearBlend',\
    GdipSetPathGradientPath,'GdipSetPathGradientPath',\
    GdipSetPathGradientPresetBlend,'GdipSetPathGradientPresetBlend',\
    GdipSetPathGradientSigmaBlend,'GdipSetPathGradientSigmaBlend',\
    GdipSetPathGradientSurroundColorsWithCount,'GdipSetPathGradientSurroundColorsWithCount',\
    GdipSetPathGradientTransform,'GdipSetPathGradientTransform',\
    GdipSetPathGradientWrapMode,'GdipSetPathGradientWrapMode',\
    GdipSetPathMarker,'GdipSetPathMarker',\
    GdipSetPenBrushFill,'GdipSetPenBrushFill',\
    GdipSetPenColor,'GdipSetPenColor',\
    GdipSetPenCompoundArray,'GdipSetPenCompoundArray',\
    GdipSetPenCustomEndCap,'GdipSetPenCustomEndCap',\
    GdipSetPenCustomStartCap,'GdipSetPenCustomStartCap',\
    GdipSetPenDashArray,'GdipSetPenDashArray',\
    GdipSetPenDashCap197819,'GdipSetPenDashCap197819',\
    GdipSetPenDashOffset,'GdipSetPenDashOffset',\
    GdipSetPenDashStyle,'GdipSetPenDashStyle',\
    GdipSetPenEndCap,'GdipSetPenEndCap',\
    GdipSetPenLineCap197819,'GdipSetPenLineCap197819',\
    GdipSetPenLineJoin,'GdipSetPenLineJoin',\
    GdipSetPenMiterLimit,'GdipSetPenMiterLimit',\
    GdipSetPenMode,'GdipSetPenMode',\
    GdipSetPenStartCap,'GdipSetPenStartCap',\
    GdipSetPenTransform,'GdipSetPenTransform',\
    GdipSetPenUnit,'GdipSetPenUnit',\
    GdipSetPenWidth,'GdipSetPenWidth',\
    GdipSetPixelOffsetMode,'GdipSetPixelOffsetMode',\
    GdipSetPropertyItem,'GdipSetPropertyItem',\
    GdipSetRenderingOrigin,'GdipSetRenderingOrigin',\
    GdipSetSmoothingMode,'GdipSetSmoothingMode',\
    GdipSetSolidFillColor,'GdipSetSolidFillColor',\
    GdipSetStringFormatAlign,'GdipSetStringFormatAlign',\
    GdipSetStringFormatDigitSubstitution,'GdipSetStringFormatDigitSubstitution',\
    GdipSetStringFormatFlags,'GdipSetStringFormatFlags',\
    GdipSetStringFormatHotkeyPrefix,'GdipSetStringFormatHotkeyPrefix',\
    GdipSetStringFormatLineAlign,'GdipSetStringFormatLineAlign',\
    GdipSetStringFormatMeasurableCharacterRanges,'GdipSetStringFormatMeasurableCharacterRanges',\
    GdipSetStringFormatTabStops,'GdipSetStringFormatTabStops',\
    GdipSetStringFormatTrimming,'GdipSetStringFormatTrimming',\
    GdipSetTextContrast,'GdipSetTextContrast',\
    GdipSetTextRenderingHint,'GdipSetTextRenderingHint',\
    GdipSetTextureTransform,'GdipSetTextureTransform',\
    GdipSetTextureWrapMode,'GdipSetTextureWrapMode',\
    GdipSetWorldTransform,'GdipSetWorldTransform',\
    GdipShearMatrix,'GdipShearMatrix',\
    GdipStartPathFigure,'GdipStartPathFigure',\
    GdipStringFormatGetGenericDefault,'GdipStringFormatGetGenericDefault',\
    GdipStringFormatGetGenericTypographic,'GdipStringFormatGetGenericTypographic',\
    GdipTestControl,'GdipTestControl',\
    GdipTransformMatrixPoints,'GdipTransformMatrixPoints',\
    GdipTransformMatrixPointsI,'GdipTransformMatrixPointsI',\
    GdipTransformPath,'GdipTransformPath',\
    GdipTransformPoints,'GdipTransformPoints',\
    GdipTransformPointsI,'GdipTransformPointsI',\
    GdipTransformRegion,'GdipTransformRegion',\
    GdipTranslateClip,'GdipTranslateClip',\
    GdipTranslateClipI,'GdipTranslateClipI',\
    GdipTranslateLineTransform,'GdipTranslateLineTransform',\
    GdipTranslateMatrix,'GdipTranslateMatrix',\
    GdipTranslatePathGradientTransform,'GdipTranslatePathGradientTransform',\
    GdipTranslatePenTransform,'GdipTranslatePenTransform',\
    GdipTranslateRegion,'GdipTranslateRegion',\
    GdipTranslateRegionI,'GdipTranslateRegionI',\
    GdipTranslateTextureTransform,'GdipTranslateTextureTransform',\
    GdipTranslateWorldTransform,'GdipTranslateWorldTransform',\
    GdipVectorTransformMatrixPoints,'GdipVectorTransformMatrixPoints',\
    GdipVectorTransformMatrixPointsI,'GdipVectorTransformMatrixPointsI',\
    GdipWarpPath,'GdipWarpPath',\
    GdipWidenPath,'GdipWidenPath',\
    GdipWindingModeOutline,'GdipWindingModeOutline'

api LOGFONT,\
    GdipCreateFontFromLogfont,\
    GdipGetLogFont

;======================= Undocumented functions (unknown arguments) =======================;
;GdipPlayTSClientRecord,'GdipPlayTSClientRecord'

end if ;GDIPLUS_INC
