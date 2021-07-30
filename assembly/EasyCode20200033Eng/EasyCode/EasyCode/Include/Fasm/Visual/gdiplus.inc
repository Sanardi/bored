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
if defined APP_WIN64
    extrn '__imp_GdipAddImageCodec' as GdipAddImageCodec:qword
    extrn '__imp_GdipAddPathArc' as GdipAddPathArc:qword
    extrn '__imp_GdipAddPathArcI' as GdipAddPathArcI:qword
    extrn '__imp_GdipAddPathBezier' as GdipAddPathBezier:qword
    extrn '__imp_GdipAddPathBezierI' as GdipAddPathBezierI:qword
    extrn '__imp_GdipAddPathBeziers' as GdipAddPathBeziers:qword
    extrn '__imp_GdipAddPathBeziersI' as GdipAddPathBeziersI:qword
    extrn '__imp_GdipAddPathClosedCurve' as GdipAddPathClosedCurve:qword
    extrn '__imp_GdipAddPathClosedCurve2' as GdipAddPathClosedCurve2:qword
    extrn '__imp_GdipAddPathClosedCurve2I' as GdipAddPathClosedCurve2I:qword
    extrn '__imp_GdipAddPathClosedCurveI' as GdipAddPathClosedCurveI:qword
    extrn '__imp_GdipAddPathCurve' as GdipAddPathCurve:qword
    extrn '__imp_GdipAddPathCurve2' as GdipAddPathCurve2:qword
    extrn '__imp_GdipAddPathCurve2I' as GdipAddPathCurve2I:qword
    extrn '__imp_GdipAddPathCurve3' as GdipAddPathCurve3:qword
    extrn '__imp_GdipAddPathCurve3I' as GdipAddPathCurve3I:qword
    extrn '__imp_GdipAddPathCurveI' as GdipAddPathCurveI:qword
    extrn '__imp_GdipAddPathEllipse' as GdipAddPathEllipse:qword
    extrn '__imp_GdipAddPathEllipseI' as GdipAddPathEllipseI:qword
    extrn '__imp_GdipAddPathLine' as GdipAddPathLine:qword
    extrn '__imp_GdipAddPathLine2' as GdipAddPathLine2:qword
    extrn '__imp_GdipAddPathLine2I' as GdipAddPathLine2I:qword
    extrn '__imp_GdipAddPathLineI' as GdipAddPathLineI:qword
    extrn '__imp_GdipAddPathPath' as GdipAddPathPath:qword
    extrn '__imp_GdipAddPathPie' as GdipAddPathPie:qword
    extrn '__imp_GdipAddPathPieI' as GdipAddPathPieI:qword
    extrn '__imp_GdipAddPathPolygon' as GdipAddPathPolygon:qword
    extrn '__imp_GdipAddPathPolygonI' as GdipAddPathPolygonI:qword
    extrn '__imp_GdipAddPathRectangle' as GdipAddPathRectangle:qword
    extrn '__imp_GdipAddPathRectangleI' as GdipAddPathRectangleI:qword
    extrn '__imp_GdipAddPathRectangles' as GdipAddPathRectangles:qword
    extrn '__imp_GdipAddPathRectanglesI' as GdipAddPathRectanglesI:qword
    extrn '__imp_GdipAddPathString' as GdipAddPathString:qword
    extrn '__imp_GdipAddPathStringI' as GdipAddPathStringI:qword
    extrn '__imp_GdipAlloc' as GdipAlloc:qword
    extrn '__imp_GdipBeginContainer' as GdipBeginContainer:qword
    extrn '__imp_GdipBeginContainer2' as GdipBeginContainer2:qword
    extrn '__imp_GdipBeginContainerI' as GdipBeginContainerI:qword
    extrn '__imp_GdipBitmapApplyEffect' as GdipBitmapApplyEffect:qword
    extrn '__imp_GdipBitmapConvertFormat' as GdipBitmapConvertFormat:qword
    extrn '__imp_GdipBitmapCreateApplyEffect' as GdipBitmapCreateApplyEffect:qword
    extrn '__imp_GdipBitmapGetHistogram' as GdipBitmapGetHistogram:qword
    extrn '__imp_GdipBitmapGetHistogramSize' as GdipBitmapGetHistogramSize:qword
    extrn '__imp_GdipBitmapGetPixel' as GdipBitmapGetPixel:qword
    extrn '__imp_GdipBitmapLockBits' as GdipBitmapLockBits:qword
    extrn '__imp_GdipBitmapSetPixel' as GdipBitmapSetPixel:qword
    extrn '__imp_GdipBitmapSetResolution' as GdipBitmapSetResolution:qword
    extrn '__imp_GdipBitmapUnlockBits' as GdipBitmapUnlockBits:qword
    extrn '__imp_GdipClearPathMarkers' as GdipClearPathMarkers:qword
    extrn '__imp_GdipCloneBitmapArea' as GdipCloneBitmapArea:qword
    extrn '__imp_GdipCloneBitmapAreaI' as GdipCloneBitmapAreaI:qword
    extrn '__imp_GdipCloneBrush' as GdipCloneBrush:qword
    extrn '__imp_GdipCloneCustomLineCap' as GdipCloneCustomLineCap:qword
    extrn '__imp_GdipCloneFont' as GdipCloneFont:qword
    extrn '__imp_GdipCloneFontFamily' as GdipCloneFontFamily:qword
    extrn '__imp_GdipCloneImage' as GdipCloneImage:qword
    extrn '__imp_GdipCloneImageAttributes' as GdipCloneImageAttributes:qword
    extrn '__imp_GdipCloneMatrix' as GdipCloneMatrix:qword
    extrn '__imp_GdipClonePath' as GdipClonePath:qword
    extrn '__imp_GdipClonePen' as GdipClonePen:qword
    extrn '__imp_GdipCloneRegion' as GdipCloneRegion:qword
    extrn '__imp_GdipCloneStringFormat' as GdipCloneStringFormat:qword
    extrn '__imp_GdipClosePathFigure' as GdipClosePathFigure:qword
    extrn '__imp_GdipClosePathFigures' as GdipClosePathFigures:qword
    extrn '__imp_GdipCombineRegionPath' as GdipCombineRegionPath:qword
    extrn '__imp_GdipCombineRegionRect' as GdipCombineRegionRect:qword
    extrn '__imp_GdipCombineRegionRectI' as GdipCombineRegionRectI:qword
    extrn '__imp_GdipCombineRegionRegion' as GdipCombineRegionRegion:qword
    extrn '__imp_GdipComment' as GdipComment:qword
    extrn '__imp_GdipConvertToEmfPlus' as GdipConvertToEmfPlus:qword
    extrn '__imp_GdipConvertToEmfPlusToFile' as GdipConvertToEmfPlusToFile:qword
    extrn '__imp_GdipConvertToEmfPlusToStream' as GdipConvertToEmfPlusToStream:qword
    extrn '__imp_GdipCreateAdjustableArrowCap' as GdipCreateAdjustableArrowCap:qword
    extrn '__imp_GdipCreateBitmapFromDirectDrawSurface' as GdipCreateBitmapFromDirectDrawSurface:qword
    extrn '__imp_GdipCreateBitmapFromFile' as GdipCreateBitmapFromFile:qword
    extrn '__imp_GdipCreateBitmapFromFileICM' as GdipCreateBitmapFromFileICM:qword
    extrn '__imp_GdipCreateBitmapFromGdiDib' as GdipCreateBitmapFromGdiDib:qword
    extrn '__imp_GdipCreateBitmapFromGraphics' as GdipCreateBitmapFromGraphics:qword
    extrn '__imp_GdipCreateBitmapFromHBITMAP' as GdipCreateBitmapFromHBITMAP:qword
    extrn '__imp_GdipCreateBitmapFromHICON' as GdipCreateBitmapFromHICON:qword
    extrn '__imp_GdipCreateBitmapFromResource' as GdipCreateBitmapFromResource:qword
    extrn '__imp_GdipCreateBitmapFromScan0' as GdipCreateBitmapFromScan0:qword
    extrn '__imp_GdipCreateBitmapFromStream' as GdipCreateBitmapFromStream:qword
    extrn '__imp_GdipCreateBitmapFromStreamICM' as GdipCreateBitmapFromStreamICM:qword
    extrn '__imp_GdipCreateCachedBitmap' as GdipCreateCachedBitmap:qword
    extrn '__imp_GdipCreateCustomLineCap' as GdipCreateCustomLineCap:qword
    extrn '__imp_GdipCreateEffect' as GdipCreateEffect:qword
    extrn '__imp_GdipCreateFont' as GdipCreateFont:qword
    extrn '__imp_GdipCreateFontFamilyFromName' as GdipCreateFontFamilyFromName:qword
    extrn '__imp_GdipCreateFontFromDC' as GdipCreateFontFromDC:qword
    extrn '__imp_GdipCreateFontFromLogfontA' as GdipCreateFontFromLogfontA:qword
    extrn '__imp_GdipCreateFontFromLogfontW' as GdipCreateFontFromLogfontW:qword
    extrn '__imp_GdipCreateFromHDC' as GdipCreateFromHDC:qword
    extrn '__imp_GdipCreateFromHDC2' as GdipCreateFromHDC2:qword
    extrn '__imp_GdipCreateFromHWND' as GdipCreateFromHWND:qword
    extrn '__imp_GdipCreateFromHWNDICM' as GdipCreateFromHWNDICM:qword
    extrn '__imp_GdipCreateHalftonePalette' as GdipCreateHalftonePalette:qword
    extrn '__imp_GdipCreateHatchBrush' as GdipCreateHatchBrush:qword
    extrn '__imp_GdipCreateHBITMAPFromBitmap' as GdipCreateHBITMAPFromBitmap:qword
    extrn '__imp_GdipCreateHICONFromBitmap' as GdipCreateHICONFromBitmap:qword
    extrn '__imp_GdipCreateImageAttributes' as GdipCreateImageAttributes:qword
    extrn '__imp_GdipCreateLineBrush' as GdipCreateLineBrush:qword
    extrn '__imp_GdipCreateLineBrushFromRect' as GdipCreateLineBrushFromRect:qword
    extrn '__imp_GdipCreateLineBrushFromRectI' as GdipCreateLineBrushFromRectI:qword
    extrn '__imp_GdipCreateLineBrushFromRectWithAngle' as GdipCreateLineBrushFromRectWithAngle:qword
    extrn '__imp_GdipCreateLineBrushFromRectWithAngleI' as GdipCreateLineBrushFromRectWithAngleI:qword
    extrn '__imp_GdipCreateLineBrushI' as GdipCreateLineBrushI:qword
    extrn '__imp_GdipCreateMatrix' as GdipCreateMatrix:qword
    extrn '__imp_GdipCreateMatrix2' as GdipCreateMatrix2:qword
    extrn '__imp_GdipCreateMatrix3' as GdipCreateMatrix3:qword
    extrn '__imp_GdipCreateMatrix3I' as GdipCreateMatrix3I:qword
    extrn '__imp_GdipCreateMetafileFromEmf' as GdipCreateMetafileFromEmf:qword
    extrn '__imp_GdipCreateMetafileFromFile' as GdipCreateMetafileFromFile:qword
    extrn '__imp_GdipCreateMetafileFromStream' as GdipCreateMetafileFromStream:qword
    extrn '__imp_GdipCreateMetafileFromWmf' as GdipCreateMetafileFromWmf:qword
    extrn '__imp_GdipCreateMetafileFromWmfFile' as GdipCreateMetafileFromWmfFile:qword
    extrn '__imp_GdipCreatePath' as GdipCreatePath:qword
    extrn '__imp_GdipCreatePath2' as GdipCreatePath2:qword
    extrn '__imp_GdipCreatePath2I' as GdipCreatePath2I:qword
    extrn '__imp_GdipCreatePathGradient' as GdipCreatePathGradient:qword
    extrn '__imp_GdipCreatePathGradientFromPath' as GdipCreatePathGradientFromPath:qword
    extrn '__imp_GdipCreatePathGradientI' as GdipCreatePathGradientI:qword
    extrn '__imp_GdipCreatePathIter' as GdipCreatePathIter:qword
    extrn '__imp_GdipCreatePen1' as GdipCreatePen1:qword
    extrn '__imp_GdipCreatePen2' as GdipCreatePen2:qword
    extrn '__imp_GdipCreateRegion' as GdipCreateRegion:qword
    extrn '__imp_GdipCreateRegionHrgn' as GdipCreateRegionHrgn:qword
    extrn '__imp_GdipCreateRegionPath' as GdipCreateRegionPath:qword
    extrn '__imp_GdipCreateRegionRect' as GdipCreateRegionRect:qword
    extrn '__imp_GdipCreateRegionRectI' as GdipCreateRegionRectI:qword
    extrn '__imp_GdipCreateRegionRgnData' as GdipCreateRegionRgnData:qword
    extrn '__imp_GdipCreateSolidFill' as GdipCreateSolidFill:qword
    extrn '__imp_GdipCreateStreamOnFile' as GdipCreateStreamOnFile:qword
    extrn '__imp_GdipCreateStringFormat' as GdipCreateStringFormat:qword
    extrn '__imp_GdipCreateTexture' as GdipCreateTexture:qword
    extrn '__imp_GdipCreateTexture2' as GdipCreateTexture2:qword
    extrn '__imp_GdipCreateTexture2I' as GdipCreateTexture2I:qword
    extrn '__imp_GdipCreateTextureIA' as GdipCreateTextureIA:qword
    extrn '__imp_GdipCreateTextureIAI' as GdipCreateTextureIAI:qword
    extrn '__imp_GdipDeleteBrush' as GdipDeleteBrush:qword
    extrn '__imp_GdipDeleteCachedBitmap' as GdipDeleteCachedBitmap:qword
    extrn '__imp_GdipDeleteCustomLineCap' as GdipDeleteCustomLineCap:qword
    extrn '__imp_GdipDeleteEffect' as GdipDeleteEffect:qword
    extrn '__imp_GdipDeleteFont' as GdipDeleteFont:qword
    extrn '__imp_GdipDeleteFontFamily' as GdipDeleteFontFamily:qword
    extrn '__imp_GdipDeleteGraphics' as GdipDeleteGraphics:qword
    extrn '__imp_GdipDeleteMatrix' as GdipDeleteMatrix:qword
    extrn '__imp_GdipDeletePath' as GdipDeletePath:qword
    extrn '__imp_GdipDeletePathIter' as GdipDeletePathIter:qword
    extrn '__imp_GdipDeletePen' as GdipDeletePen:qword
    extrn '__imp_GdipDeletePrivateFontCollection' as GdipDeletePrivateFontCollection:qword
    extrn '__imp_GdipDeleteRegion' as GdipDeleteRegion:qword
    extrn '__imp_GdipDeleteStringFormat' as GdipDeleteStringFormat:qword
    extrn '__imp_GdipDisposeImage' as GdipDisposeImage:qword
    extrn '__imp_GdipDisposeImageAttributes' as GdipDisposeImageAttributes:qword
    extrn '__imp_GdipDrawArc' as GdipDrawArc:qword
    extrn '__imp_GdipDrawArcI' as GdipDrawArcI:qword
    extrn '__imp_GdipDrawBezier' as GdipDrawBezier:qword
    extrn '__imp_GdipDrawBezierI' as GdipDrawBezierI:qword
    extrn '__imp_GdipDrawBeziers' as GdipDrawBeziers:qword
    extrn '__imp_GdipDrawBeziersI' as GdipDrawBeziersI:qword
    extrn '__imp_GdipDrawCachedBitmap' as GdipDrawCachedBitmap:qword
    extrn '__imp_GdipDrawClosedCurve' as GdipDrawClosedCurve:qword
    extrn '__imp_GdipDrawClosedCurve2' as GdipDrawClosedCurve2:qword
    extrn '__imp_GdipDrawClosedCurve2I' as GdipDrawClosedCurve2I:qword
    extrn '__imp_GdipDrawClosedCurveI' as GdipDrawClosedCurveI:qword
    extrn '__imp_GdipDrawCurve' as GdipDrawCurve:qword
    extrn '__imp_GdipDrawCurve2' as GdipDrawCurve2:qword
    extrn '__imp_GdipDrawCurve2I' as GdipDrawCurve2I:qword
    extrn '__imp_GdipDrawCurve3' as GdipDrawCurve3:qword
    extrn '__imp_GdipDrawCurve3I' as GdipDrawCurve3I:qword
    extrn '__imp_GdipDrawCurveI' as GdipDrawCurveI:qword
    extrn '__imp_GdipDrawDriverString' as GdipDrawDriverString:qword
    extrn '__imp_GdipDrawEllipse' as GdipDrawEllipse:qword
    extrn '__imp_GdipDrawEllipseI' as GdipDrawEllipseI:qword
    extrn '__imp_GdipDrawImage' as GdipDrawImage:qword
    extrn '__imp_GdipDrawImageFX' as GdipDrawImageFX:qword
    extrn '__imp_GdipDrawImageI' as GdipDrawImageI:qword
    extrn '__imp_GdipDrawImagePointRect' as GdipDrawImagePointRect:qword
    extrn '__imp_GdipDrawImagePointRectI' as GdipDrawImagePointRectI:qword
    extrn '__imp_GdipDrawImagePoints' as GdipDrawImagePoints:qword
    extrn '__imp_GdipDrawImagePointsI' as GdipDrawImagePointsI:qword
    extrn '__imp_GdipDrawImagePointsRect' as GdipDrawImagePointsRect:qword
    extrn '__imp_GdipDrawImagePointsRectI' as GdipDrawImagePointsRectI:qword
    extrn '__imp_GdipDrawImageRect' as GdipDrawImageRect:qword
    extrn '__imp_GdipDrawImageRectI' as GdipDrawImageRectI:qword
    extrn '__imp_GdipDrawImageRectRect' as GdipDrawImageRectRect:qword
    extrn '__imp_GdipDrawImageRectRectI' as GdipDrawImageRectRectI:qword
    extrn '__imp_GdipDrawLine' as GdipDrawLine:qword
    extrn '__imp_GdipDrawLineI' as GdipDrawLineI:qword
    extrn '__imp_GdipDrawLines' as GdipDrawLines:qword
    extrn '__imp_GdipDrawLinesI' as GdipDrawLinesI:qword
    extrn '__imp_GdipDrawPath' as GdipDrawPath:qword
    extrn '__imp_GdipDrawPie' as GdipDrawPie:qword
    extrn '__imp_GdipDrawPieI' as GdipDrawPieI:qword
    extrn '__imp_GdipDrawPolygon' as GdipDrawPolygon:qword
    extrn '__imp_GdipDrawPolygonI' as GdipDrawPolygonI:qword
    extrn '__imp_GdipDrawRectangle' as GdipDrawRectangle:qword
    extrn '__imp_GdipDrawRectangleI' as GdipDrawRectangleI:qword
    extrn '__imp_GdipDrawRectangles' as GdipDrawRectangles:qword
    extrn '__imp_GdipDrawRectanglesI' as GdipDrawRectanglesI:qword
    extrn '__imp_GdipDrawString' as GdipDrawString:qword
    extrn '__imp_GdipEmfToWmfBits' as GdipEmfToWmfBits:qword
    extrn '__imp_GdipEndContainer' as GdipEndContainer:qword
    extrn '__imp_GdipEnumerateMetafileDestPoint' as GdipEnumerateMetafileDestPoint:qword
    extrn '__imp_GdipEnumerateMetafileDestPointI' as GdipEnumerateMetafileDestPointI:qword
    extrn '__imp_GdipEnumerateMetafileDestPoints' as GdipEnumerateMetafileDestPoints:qword
    extrn '__imp_GdipEnumerateMetafileDestPointsI' as GdipEnumerateMetafileDestPointsI:qword
    extrn '__imp_GdipEnumerateMetafileDestRect' as GdipEnumerateMetafileDestRect:qword
    extrn '__imp_GdipEnumerateMetafileDestRectI' as GdipEnumerateMetafileDestRectI:qword
    extrn '__imp_GdipEnumerateMetafileSrcRectDestPoint' as GdipEnumerateMetafileSrcRectDestPoint:qword
    extrn '__imp_GdipEnumerateMetafileSrcRectDestPointI' as GdipEnumerateMetafileSrcRectDestPointI:qword
    extrn '__imp_GdipEnumerateMetafileSrcRectDestPoints' as GdipEnumerateMetafileSrcRectDestPoints:qword
    extrn '__imp_GdipEnumerateMetafileSrcRectDestPointsI' as GdipEnumerateMetafileSrcRectDestPointsI:qword
    extrn '__imp_GdipEnumerateMetafileSrcRectDestRect' as GdipEnumerateMetafileSrcRectDestRect:qword
    extrn '__imp_GdipEnumerateMetafileSrcRectDestRectI' as GdipEnumerateMetafileSrcRectDestRectI:qword
    extrn '__imp_GdipFillClosedCurve' as GdipFillClosedCurve:qword
    extrn '__imp_GdipFillClosedCurve2' as GdipFillClosedCurve2:qword
    extrn '__imp_GdipFillClosedCurve2I' as GdipFillClosedCurve2I:qword
    extrn '__imp_GdipFillClosedCurveI' as GdipFillClosedCurveI:qword
    extrn '__imp_GdipFillEllipse' as GdipFillEllipse:qword
    extrn '__imp_GdipFillEllipseI' as GdipFillEllipseI:qword
    extrn '__imp_GdipFillPath' as GdipFillPath:qword
    extrn '__imp_GdipFillPie' as GdipFillPie:qword
    extrn '__imp_GdipFillPieI' as GdipFillPieI:qword
    extrn '__imp_GdipFillPolygon' as GdipFillPolygon:qword
    extrn '__imp_GdipFillPolygon2' as GdipFillPolygon2:qword
    extrn '__imp_GdipFillPolygon2I' as GdipFillPolygon2I:qword
    extrn '__imp_GdipFillPolygonI' as GdipFillPolygonI:qword
    extrn '__imp_GdipFillRectangle' as GdipFillRectangle:qword
    extrn '__imp_GdipFillRectangleI' as GdipFillRectangleI:qword
    extrn '__imp_GdipFillRectangles' as GdipFillRectangles:qword
    extrn '__imp_GdipFillRectanglesI' as GdipFillRectanglesI:qword
    extrn '__imp_GdipFillRegion' as GdipFillRegion:qword
    extrn '__imp_GdipFindFirstImageItem' as GdipFindFirstImageItem:qword
    extrn '__imp_GdipFindNextImageItem' as GdipFindNextImageItem:qword
    extrn '__imp_GdipFlattenPath' as GdipFlattenPath:qword
    extrn '__imp_GdipFlush' as GdipFlush:qword
    extrn '__imp_GdipFree' as GdipFree:qword
    extrn '__imp_GdipGetAdjustableArrowCapFillState' as GdipGetAdjustableArrowCapFillState:qword
    extrn '__imp_GdipGetAdjustableArrowCapHeight' as GdipGetAdjustableArrowCapHeight:qword
    extrn '__imp_GdipGetAdjustableArrowCapMiddleInset' as GdipGetAdjustableArrowCapMiddleInset:qword
    extrn '__imp_GdipGetAdjustableArrowCapWidth' as GdipGetAdjustableArrowCapWidth:qword
    extrn '__imp_GdipGetAllPropertyItems' as GdipGetAllPropertyItems:qword
    extrn '__imp_GdipGetBrushType' as GdipGetBrushType:qword
    extrn '__imp_GdipGetCellAscent' as GdipGetCellAscent:qword
    extrn '__imp_GdipGetCellDescent' as GdipGetCellDescent:qword
    extrn '__imp_GdipGetClip' as GdipGetClip:qword
    extrn '__imp_GdipGetClipBounds' as GdipGetClipBounds:qword
    extrn '__imp_GdipGetClipBoundsI' as GdipGetClipBoundsI:qword
    extrn '__imp_GdipGetCompositingMode' as GdipGetCompositingMode:qword
    extrn '__imp_GdipGetCompositingQuality' as GdipGetCompositingQuality:qword
    extrn '__imp_GdipGetCustomLineCapBaseCap' as GdipGetCustomLineCapBaseCap:qword
    extrn '__imp_GdipGetCustomLineCapBaseInset' as GdipGetCustomLineCapBaseInset:qword
    extrn '__imp_GdipGetCustomLineCapStrokeCaps' as GdipGetCustomLineCapStrokeCaps:qword
    extrn '__imp_GdipGetCustomLineCapStrokeJoin' as GdipGetCustomLineCapStrokeJoin:qword
    extrn '__imp_GdipGetCustomLineCapType' as GdipGetCustomLineCapType:qword
    extrn '__imp_GdipGetCustomLineCapWidthScale' as GdipGetCustomLineCapWidthScale:qword
    extrn '__imp_GdipGetDC' as GdipGetDC:qword
    extrn '__imp_GdipGetDpiX' as GdipGetDpiX:qword
    extrn '__imp_GdipGetDpiY' as GdipGetDpiY:qword
    extrn '__imp_GdipGetEffectParameters' as GdipGetEffectParameters:qword
    extrn '__imp_GdipGetEffectParameterSize' as GdipGetEffectParameterSize:qword
    extrn '__imp_GdipGetEmHeight' as GdipGetEmHeight:qword
    extrn '__imp_GdipGetEncoderParameterList' as GdipGetEncoderParameterList:qword
    extrn '__imp_GdipGetEncoderParameterListSize' as GdipGetEncoderParameterListSize:qword
    extrn '__imp_GdipGetFamily' as GdipGetFamily:qword
    extrn '__imp_GdipGetFamilyName' as GdipGetFamilyName:qword
    extrn '__imp_GdipGetFontCollectionFamilyCount' as GdipGetFontCollectionFamilyCount:qword
    extrn '__imp_GdipGetFontCollectionFamilyList' as GdipGetFontCollectionFamilyList:qword
    extrn '__imp_GdipGetFontHeight' as GdipGetFontHeight:qword
    extrn '__imp_GdipGetFontHeightGivenDPI' as GdipGetFontHeightGivenDPI:qword
    extrn '__imp_GdipGetFontSize' as GdipGetFontSize:qword
    extrn '__imp_GdipGetFontStyle' as GdipGetFontStyle:qword
    extrn '__imp_GdipGetFontUnit' as GdipGetFontUnit:qword
    extrn '__imp_GdipGetGenericFontFamilyMonospace' as GdipGetGenericFontFamilyMonospace:qword
    extrn '__imp_GdipGetGenericFontFamilySansSerif' as GdipGetGenericFontFamilySansSerif:qword
    extrn '__imp_GdipGetGenericFontFamilySerif' as GdipGetGenericFontFamilySerif:qword
    extrn '__imp_GdipGetGraphicsLayout' as GdipGetGraphicsLayout:qword
    extrn '__imp_GdipGetHatchBackgroundColor' as GdipGetHatchBackgroundColor:qword
    extrn '__imp_GdipGetHatchForegroundColor' as GdipGetHatchForegroundColor:qword
    extrn '__imp_GdipGetHatchStyle' as GdipGetHatchStyle:qword
    extrn '__imp_GdipGetHemfFromMetafile' as GdipGetHemfFromMetafile:qword
    extrn '__imp_GdipGetImageAttributesAdjustedPalette' as GdipGetImageAttributesAdjustedPalette:qword
    extrn '__imp_GdipGetImageBounds' as GdipGetImageBounds:qword
    extrn '__imp_GdipGetImageDecoders' as GdipGetImageDecoders:qword
    extrn '__imp_GdipGetImageDecodersSize' as GdipGetImageDecodersSize:qword
    extrn '__imp_GdipGetImageDimension' as GdipGetImageDimension:qword
    extrn '__imp_GdipGetImageEncoders' as GdipGetImageEncoders:qword
    extrn '__imp_GdipGetImageEncodersSize' as GdipGetImageEncodersSize:qword
    extrn '__imp_GdipGetImageFlags' as GdipGetImageFlags:qword
    extrn '__imp_GdipGetImageGraphicsContext' as GdipGetImageGraphicsContext:qword
    extrn '__imp_GdipGetImageHeight' as GdipGetImageHeight:qword
    extrn '__imp_GdipGetImageHorizontalResolution' as GdipGetImageHorizontalResolution:qword
    extrn '__imp_GdipGetImageLayout' as GdipGetImageLayout:qword
    extrn '__imp_GdipGetImagePalette' as GdipGetImagePalette:qword
    extrn '__imp_GdipGetImagePaletteSize' as GdipGetImagePaletteSize:qword
    extrn '__imp_GdipGetImagePixelFormat' as GdipGetImagePixelFormat:qword
    extrn '__imp_GdipGetImageRawFormat' as GdipGetImageRawFormat:qword
    extrn '__imp_GdipGetImageThumbnail' as GdipGetImageThumbnail:qword
    extrn '__imp_GdipGetImageType' as GdipGetImageType:qword
    extrn '__imp_GdipGetImageVerticalResolution' as GdipGetImageVerticalResolution:qword
    extrn '__imp_GdipGetImageWidth' as GdipGetImageWidth:qword
    extrn '__imp_GdipGetInterpolationMode' as GdipGetInterpolationMode:qword
    extrn '__imp_GdipGetLineBlend' as GdipGetLineBlend:qword
    extrn '__imp_GdipGetLineBlendCount' as GdipGetLineBlendCount:qword
    extrn '__imp_GdipGetLineColors' as GdipGetLineColors:qword
    extrn '__imp_GdipGetLineGammaCorrection' as GdipGetLineGammaCorrection:qword
    extrn '__imp_GdipGetLinePoints' as GdipGetLinePoints:qword
    extrn '__imp_GdipGetLinePointsI' as GdipGetLinePointsI:qword
    extrn '__imp_GdipGetLinePresetBlend' as GdipGetLinePresetBlend:qword
    extrn '__imp_GdipGetLinePresetBlendCount' as GdipGetLinePresetBlendCount:qword
    extrn '__imp_GdipGetLineRect' as GdipGetLineRect:qword
    extrn '__imp_GdipGetLineRectI' as GdipGetLineRectI:qword
    extrn '__imp_GdipGetLineSpacing' as GdipGetLineSpacing:qword
    extrn '__imp_GdipGetLineTransform' as GdipGetLineTransform:qword
    extrn '__imp_GdipGetLineWrapMode' as GdipGetLineWrapMode:qword
    extrn '__imp_GdipGetLogFontA' as GdipGetLogFontA:qword
    extrn '__imp_GdipGetLogFontW' as GdipGetLogFontW:qword
    extrn '__imp_GdipGetMatrixElements' as GdipGetMatrixElements:qword
    extrn '__imp_GdipGetMetafileDownLevelRasterizationLimit' as GdipGetMetafileDownLevelRasterizationLimit:qword
    extrn '__imp_GdipGetMetafileHeaderFromEmf' as GdipGetMetafileHeaderFromEmf:qword
    extrn '__imp_GdipGetMetafileHeaderFromFile' as GdipGetMetafileHeaderFromFile:qword
    extrn '__imp_GdipGetMetafileHeaderFromMetafile' as GdipGetMetafileHeaderFromMetafile:qword
    extrn '__imp_GdipGetMetafileHeaderFromStream' as GdipGetMetafileHeaderFromStream:qword
    extrn '__imp_GdipGetMetafileHeaderFromWmf' as GdipGetMetafileHeaderFromWmf:qword
    extrn '__imp_GdipGetNearestColor' as GdipGetNearestColor:qword
    extrn '__imp_GdipGetPageScale' as GdipGetPageScale:qword
    extrn '__imp_GdipGetPageUnit' as GdipGetPageUnit:qword
    extrn '__imp_GdipGetPathData' as GdipGetPathData:qword
    extrn '__imp_GdipGetPathFillMode' as GdipGetPathFillMode:qword
    extrn '__imp_GdipGetPathGradientBlend' as GdipGetPathGradientBlend:qword
    extrn '__imp_GdipGetPathGradientBlendCount' as GdipGetPathGradientBlendCount:qword
    extrn '__imp_GdipGetPathGradientCenterColor' as GdipGetPathGradientCenterColor:qword
    extrn '__imp_GdipGetPathGradientCenterPoint' as GdipGetPathGradientCenterPoint:qword
    extrn '__imp_GdipGetPathGradientCenterPointI' as GdipGetPathGradientCenterPointI:qword
    extrn '__imp_GdipGetPathGradientFocusScales' as GdipGetPathGradientFocusScales:qword
    extrn '__imp_GdipGetPathGradientGammaCorrection' as GdipGetPathGradientGammaCorrection:qword
    extrn '__imp_GdipGetPathGradientPath' as GdipGetPathGradientPath:qword
    extrn '__imp_GdipGetPathGradientPointCount' as GdipGetPathGradientPointCount:qword
    extrn '__imp_GdipGetPathGradientPresetBlend' as GdipGetPathGradientPresetBlend:qword
    extrn '__imp_GdipGetPathGradientPresetBlendCount' as GdipGetPathGradientPresetBlendCount:qword
    extrn '__imp_GdipGetPathGradientRect' as GdipGetPathGradientRect:qword
    extrn '__imp_GdipGetPathGradientRectI' as GdipGetPathGradientRectI:qword
    extrn '__imp_GdipGetPathGradientSurroundColorCount' as GdipGetPathGradientSurroundColorCount:qword
    extrn '__imp_GdipGetPathGradientSurroundColorsWithCount' as GdipGetPathGradientSurroundColorsWithCount:qword
    extrn '__imp_GdipGetPathGradientTransform' as GdipGetPathGradientTransform:qword
    extrn '__imp_GdipGetPathGradientWrapMode' as GdipGetPathGradientWrapMode:qword
    extrn '__imp_GdipGetPathLastPoint' as GdipGetPathLastPoint:qword
    extrn '__imp_GdipGetPathPoints' as GdipGetPathPoints:qword
    extrn '__imp_GdipGetPathPointsI' as GdipGetPathPointsI:qword
    extrn '__imp_GdipGetPathTypes' as GdipGetPathTypes:qword
    extrn '__imp_GdipGetPathWorldBounds' as GdipGetPathWorldBounds:qword
    extrn '__imp_GdipGetPathWorldBoundsI' as GdipGetPathWorldBoundsI:qword
    extrn '__imp_GdipGetPenBrushFill' as GdipGetPenBrushFill:qword
    extrn '__imp_GdipGetPenColor' as GdipGetPenColor:qword
    extrn '__imp_GdipGetPenCompoundArray' as GdipGetPenCompoundArray:qword
    extrn '__imp_GdipGetPenCompoundCount' as GdipGetPenCompoundCount:qword
    extrn '__imp_GdipGetPenCustomEndCap' as GdipGetPenCustomEndCap:qword
    extrn '__imp_GdipGetPenCustomStartCap' as GdipGetPenCustomStartCap:qword
    extrn '__imp_GdipGetPenDashArray' as GdipGetPenDashArray:qword
    extrn '__imp_GdipGetPenDashCap197819' as GdipGetPenDashCap197819:qword
    extrn '__imp_GdipGetPenDashCount' as GdipGetPenDashCount:qword
    extrn '__imp_GdipGetPenDashOffset' as GdipGetPenDashOffset:qword
    extrn '__imp_GdipGetPenDashStyle' as GdipGetPenDashStyle:qword
    extrn '__imp_GdipGetPenEndCap' as GdipGetPenEndCap:qword
    extrn '__imp_GdipGetPenFillType' as GdipGetPenFillType:qword
    extrn '__imp_GdipGetPenLineJoin' as GdipGetPenLineJoin:qword
    extrn '__imp_GdipGetPenMiterLimit' as GdipGetPenMiterLimit:qword
    extrn '__imp_GdipGetPenMode' as GdipGetPenMode:qword
    extrn '__imp_GdipGetPenStartCap' as GdipGetPenStartCap:qword
    extrn '__imp_GdipGetPenTransform' as GdipGetPenTransform:qword
    extrn '__imp_GdipGetPenUnit' as GdipGetPenUnit:qword
    extrn '__imp_GdipGetPenWidth' as GdipGetPenWidth:qword
    extrn '__imp_GdipGetPixelOffsetMode' as GdipGetPixelOffsetMode:qword
    extrn '__imp_GdipGetPointCount' as GdipGetPointCount:qword
    extrn '__imp_GdipGetPropertyCount' as GdipGetPropertyCount:qword
    extrn '__imp_GdipGetPropertyIdList' as GdipGetPropertyIdList:qword
    extrn '__imp_GdipGetPropertyItem' as GdipGetPropertyItem:qword
    extrn '__imp_GdipGetPropertyItemSize' as GdipGetPropertyItemSize:qword
    extrn '__imp_GdipGetPropertySize' as GdipGetPropertySize:qword
    extrn '__imp_GdipGetRegionBounds' as GdipGetRegionBounds:qword
    extrn '__imp_GdipGetRegionBoundsI' as GdipGetRegionBoundsI:qword
    extrn '__imp_GdipGetRegionData' as GdipGetRegionData:qword
    extrn '__imp_GdipGetRegionDataSize' as GdipGetRegionDataSize:qword
    extrn '__imp_GdipGetRegionHRgn' as GdipGetRegionHRgn:qword
    extrn '__imp_GdipGetRegionScans' as GdipGetRegionScans:qword
    extrn '__imp_GdipGetRegionScansCount' as GdipGetRegionScansCount:qword
    extrn '__imp_GdipGetRegionScansI' as GdipGetRegionScansI:qword
    extrn '__imp_GdipGetRenderingOrigin' as GdipGetRenderingOrigin:qword
    extrn '__imp_GdipGetSmoothingMode' as GdipGetSmoothingMode:qword
    extrn '__imp_GdipGetSolidFillColor' as GdipGetSolidFillColor:qword
    extrn '__imp_GdipGetStringFormatAlign' as GdipGetStringFormatAlign:qword
    extrn '__imp_GdipGetStringFormatDigitSubstitution' as GdipGetStringFormatDigitSubstitution:qword
    extrn '__imp_GdipGetStringFormatFlags' as GdipGetStringFormatFlags:qword
    extrn '__imp_GdipGetStringFormatHotkeyPrefix' as GdipGetStringFormatHotkeyPrefix:qword
    extrn '__imp_GdipGetStringFormatLineAlign' as GdipGetStringFormatLineAlign:qword
    extrn '__imp_GdipGetStringFormatMeasurableCharacterRangeCount' as GdipGetStringFormatMeasurableCharacterRangeCount:qword
    extrn '__imp_GdipGetStringFormatTabStopCount' as GdipGetStringFormatTabStopCount:qword
    extrn '__imp_GdipGetStringFormatTabStops' as GdipGetStringFormatTabStops:qword
    extrn '__imp_GdipGetStringFormatTrimming' as GdipGetStringFormatTrimming:qword
    extrn '__imp_GdipGetTextContrast' as GdipGetTextContrast:qword
    extrn '__imp_GdipGetTextRenderingHint' as GdipGetTextRenderingHint:qword
    extrn '__imp_GdipGetTextureImage' as GdipGetTextureImage:qword
    extrn '__imp_GdipGetTextureTransform' as GdipGetTextureTransform:qword
    extrn '__imp_GdipGetTextureWrapMode' as GdipGetTextureWrapMode:qword
    extrn '__imp_GdipGetVisibleClipBounds' as GdipGetVisibleClipBounds:qword
    extrn '__imp_GdipGetVisibleClipBoundsI' as GdipGetVisibleClipBoundsI:qword
    extrn '__imp_GdipGetWorldTransform' as GdipGetWorldTransform:qword
    extrn '__imp_GdipGraphicsClear' as GdipGraphicsClear:qword
    extrn '__imp_GdipGraphicsSetAbort' as GdipGraphicsSetAbort:qword
    extrn '__imp_GdipImageForceValidation' as GdipImageForceValidation:qword
    extrn '__imp_GdipImageGetFrameCount' as GdipImageGetFrameCount:qword
    extrn '__imp_GdipImageGetFrameDimensionsCount' as GdipImageGetFrameDimensionsCount:qword
    extrn '__imp_GdipImageGetFrameDimensionsList' as GdipImageGetFrameDimensionsList:qword
    extrn '__imp_GdipImageRotateFlip' as GdipImageRotateFlip:qword
    extrn '__imp_GdipImageSelectActiveFrame' as GdipImageSelectActiveFrame:qword
    extrn '__imp_GdipImageSetAbort' as GdipImageSetAbort:qword
    extrn '__imp_GdipInitializePalette' as GdipInitializePalette:qword
    extrn '__imp_GdipInvertMatrix' as GdipInvertMatrix:qword
    extrn '__imp_GdipIsClipEmpty' as GdipIsClipEmpty:qword
    extrn '__imp_GdipIsEmptyRegion' as GdipIsEmptyRegion:qword
    extrn '__imp_GdipIsEqualRegion' as GdipIsEqualRegion:qword
    extrn '__imp_GdipIsInfiniteRegion' as GdipIsInfiniteRegion:qword
    extrn '__imp_GdipIsMatrixEqual' as GdipIsMatrixEqual:qword
    extrn '__imp_GdipIsMatrixIdentity' as GdipIsMatrixIdentity:qword
    extrn '__imp_GdipIsMatrixInvertible' as GdipIsMatrixInvertible:qword
    extrn '__imp_GdipIsOutlineVisiblePathPoint' as GdipIsOutlineVisiblePathPoint:qword
    extrn '__imp_GdipIsOutlineVisiblePathPointI' as GdipIsOutlineVisiblePathPointI:qword
    extrn '__imp_GdipIsStyleAvailable' as GdipIsStyleAvailable:qword
    extrn '__imp_GdipIsVisibleClipEmpty' as GdipIsVisibleClipEmpty:qword
    extrn '__imp_GdipIsVisiblePathPoint' as GdipIsVisiblePathPoint:qword
    extrn '__imp_GdipIsVisiblePathPointI' as GdipIsVisiblePathPointI:qword
    extrn '__imp_GdipIsVisiblePoint' as GdipIsVisiblePoint:qword
    extrn '__imp_GdipIsVisiblePointI' as GdipIsVisiblePointI:qword
    extrn '__imp_GdipIsVisibleRect' as GdipIsVisibleRect:qword
    extrn '__imp_GdipIsVisibleRectI' as GdipIsVisibleRectI:qword
    extrn '__imp_GdipIsVisibleRegionPoint' as GdipIsVisibleRegionPoint:qword
    extrn '__imp_GdipIsVisibleRegionPointI' as GdipIsVisibleRegionPointI:qword
    extrn '__imp_GdipIsVisibleRegionRect' as GdipIsVisibleRegionRect:qword
    extrn '__imp_GdipIsVisibleRegionRectI' as GdipIsVisibleRegionRectI:qword
    extrn '__imp_GdipLoadImageFromFile' as GdipLoadImageFromFile:qword
    extrn '__imp_GdipLoadImageFromFileICM' as GdipLoadImageFromFileICM:qword
    extrn '__imp_GdipLoadImageFromStream' as GdipLoadImageFromStream:qword
    extrn '__imp_GdipLoadImageFromStreamICM' as GdipLoadImageFromStreamICM:qword
    extrn '__imp_GdipMeasureCharacterRanges' as GdipMeasureCharacterRanges:qword
    extrn '__imp_GdipMeasureDriverString' as GdipMeasureDriverString:qword
    extrn '__imp_GdipMeasureString' as GdipMeasureString:qword
    extrn '__imp_GdipMultiplyLineTransform' as GdipMultiplyLineTransform:qword
    extrn '__imp_GdipMultiplyMatrix' as GdipMultiplyMatrix:qword
    extrn '__imp_GdipMultiplyPathGradientTransform' as GdipMultiplyPathGradientTransform:qword
    extrn '__imp_GdipMultiplyPenTransform' as GdipMultiplyPenTransform:qword
    extrn '__imp_GdipMultiplyTextureTransform' as GdipMultiplyTextureTransform:qword
    extrn '__imp_GdipMultiplyWorldTransform' as GdipMultiplyWorldTransform:qword
    extrn '__imp_GdipNewInstalledFontCollection' as GdipNewInstalledFontCollection:qword
    extrn '__imp_GdipNewPrivateFontCollection' as GdipNewPrivateFontCollection:qword
    extrn '__imp_GdipPathIterCopyData' as GdipPathIterCopyData:qword
    extrn '__imp_GdipPathIterEnumerate' as GdipPathIterEnumerate:qword
    extrn '__imp_GdipPathIterGetCount' as GdipPathIterGetCount:qword
    extrn '__imp_GdipPathIterGetSubpathCount' as GdipPathIterGetSubpathCount:qword
    extrn '__imp_GdipPathIterHasCurve' as GdipPathIterHasCurve:qword
    extrn '__imp_GdipPathIterIsValid' as GdipPathIterIsValid:qword
    extrn '__imp_GdipPathIterNextMarker' as GdipPathIterNextMarker:qword
    extrn '__imp_GdipPathIterNextMarkerPath' as GdipPathIterNextMarkerPath:qword
    extrn '__imp_GdipPathIterNextPathType' as GdipPathIterNextPathType:qword
    extrn '__imp_GdipPathIterNextSubpath' as GdipPathIterNextSubpath:qword
    extrn '__imp_GdipPathIterNextSubpathPath' as GdipPathIterNextSubpathPath:qword
    extrn '__imp_GdipPathIterRewind' as GdipPathIterRewind:qword
    extrn '__imp_GdipPlayMetafileRecord' as GdipPlayMetafileRecord:qword
    extrn '__imp_GdiplusNotificationHook' as GdiplusNotificationHook:qword
    extrn '__imp_GdiplusNotificationUnhook' as GdiplusNotificationUnhook:qword
    extrn '__imp_GdiplusShutdown' as GdiplusShutdown:qword
    extrn '__imp_GdiplusStartup' as GdiplusStartup:qword
    extrn '__imp_GdipPrivateAddFontFile' as GdipPrivateAddFontFile:qword
    extrn '__imp_GdipPrivateAddMemoryFont' as GdipPrivateAddMemoryFont:qword
    extrn '__imp_GdipRecordMetafile' as GdipRecordMetafile:qword
    extrn '__imp_GdipRecordMetafileFileName' as GdipRecordMetafileFileName:qword
    extrn '__imp_GdipRecordMetafileFileNameI' as GdipRecordMetafileFileNameI:qword
    extrn '__imp_GdipRecordMetafileI' as GdipRecordMetafileI:qword
    extrn '__imp_GdipRecordMetafileStream' as GdipRecordMetafileStream:qword
    extrn '__imp_GdipRecordMetafileStreamI' as GdipRecordMetafileStreamI:qword
    extrn '__imp_GdipReleaseDC' as GdipReleaseDC:qword
    extrn '__imp_GdipRemoveImageCodec' as GdipRemoveImageCodec:qword
    extrn '__imp_GdipRemovePropertyItem' as GdipRemovePropertyItem:qword
    extrn '__imp_GdipResetClip' as GdipResetClip:qword
    extrn '__imp_GdipResetImageAttributes' as GdipResetImageAttributes:qword
    extrn '__imp_GdipResetLineTransform' as GdipResetLineTransform:qword
    extrn '__imp_GdipResetPageTransform' as GdipResetPageTransform:qword
    extrn '__imp_GdipResetPath' as GdipResetPath:qword
    extrn '__imp_GdipResetPathGradientTransform' as GdipResetPathGradientTransform:qword
    extrn '__imp_GdipResetPenTransform' as GdipResetPenTransform:qword
    extrn '__imp_GdipResetTextureTransform' as GdipResetTextureTransform:qword
    extrn '__imp_GdipResetWorldTransform' as GdipResetWorldTransform:qword
    extrn '__imp_GdipRestoreGraphics' as GdipRestoreGraphics:qword
    extrn '__imp_GdipReversePath' as GdipReversePath:qword
    extrn '__imp_GdipRotateLineTransform' as GdipRotateLineTransform:qword
    extrn '__imp_GdipRotateMatrix' as GdipRotateMatrix:qword
    extrn '__imp_GdipRotatePathGradientTransform' as GdipRotatePathGradientTransform:qword
    extrn '__imp_GdipRotatePenTransform' as GdipRotatePenTransform:qword
    extrn '__imp_GdipRotateTextureTransform' as GdipRotateTextureTransform:qword
    extrn '__imp_GdipRotateWorldTransform' as GdipRotateWorldTransform:qword
    extrn '__imp_GdipSaveAdd' as GdipSaveAdd:qword
    extrn '__imp_GdipSaveAddImage' as GdipSaveAddImage:qword
    extrn '__imp_GdipSaveGraphics' as GdipSaveGraphics:qword
    extrn '__imp_GdipSaveImageToFile' as GdipSaveImageToFile:qword
    extrn '__imp_GdipSaveImageToStream' as GdipSaveImageToStream:qword
    extrn '__imp_GdipScaleLineTransform' as GdipScaleLineTransform:qword
    extrn '__imp_GdipScaleMatrix' as GdipScaleMatrix:qword
    extrn '__imp_GdipScalePathGradientTransform' as GdipScalePathGradientTransform:qword
    extrn '__imp_GdipScalePenTransform' as GdipScalePenTransform:qword
    extrn '__imp_GdipScaleTextureTransform' as GdipScaleTextureTransform:qword
    extrn '__imp_GdipScaleWorldTransform' as GdipScaleWorldTransform:qword
    extrn '__imp_GdipSetAdjustableArrowCapFillState' as GdipSetAdjustableArrowCapFillState:qword
    extrn '__imp_GdipSetAdjustableArrowCapHeight' as GdipSetAdjustableArrowCapHeight:qword
    extrn '__imp_GdipSetAdjustableArrowCapMiddleInset' as GdipSetAdjustableArrowCapMiddleInset:qword
    extrn '__imp_GdipSetAdjustableArrowCapWidth' as GdipSetAdjustableArrowCapWidth:qword
    extrn '__imp_GdipSetClipGraphics' as GdipSetClipGraphics:qword
    extrn '__imp_GdipSetClipHrgn' as GdipSetClipHrgn:qword
    extrn '__imp_GdipSetClipPath' as GdipSetClipPath:qword
    extrn '__imp_GdipSetClipRect' as GdipSetClipRect:qword
    extrn '__imp_GdipSetClipRectI' as GdipSetClipRectI:qword
    extrn '__imp_GdipSetClipRegion' as GdipSetClipRegion:qword
    extrn '__imp_GdipSetCompositingMode' as GdipSetCompositingMode:qword
    extrn '__imp_GdipSetCompositingQuality' as GdipSetCompositingQuality:qword
    extrn '__imp_GdipSetCustomLineCapBaseCap' as GdipSetCustomLineCapBaseCap:qword
    extrn '__imp_GdipSetCustomLineCapBaseInset' as GdipSetCustomLineCapBaseInset:qword
    extrn '__imp_GdipSetCustomLineCapStrokeCaps' as GdipSetCustomLineCapStrokeCaps:qword
    extrn '__imp_GdipSetCustomLineCapStrokeJoin' as GdipSetCustomLineCapStrokeJoin:qword
    extrn '__imp_GdipSetCustomLineCapWidthScale' as GdipSetCustomLineCapWidthScale:qword
    extrn '__imp_GdipSetEffectParameters' as GdipSetEffectParameters:qword
    extrn '__imp_GdipSetEmpty' as GdipSetEmpty:qword
    extrn '__imp_GdipSetGraphicsLayout' as GdipSetGraphicsLayout:qword
    extrn '__imp_GdipSetImageAttributesCachedBackground' as GdipSetImageAttributesCachedBackground:qword
    extrn '__imp_GdipSetImageAttributesColorKeys' as GdipSetImageAttributesColorKeys:qword
    extrn '__imp_GdipSetImageAttributesColorMatrix' as GdipSetImageAttributesColorMatrix:qword
    extrn '__imp_GdipSetImageAttributesGamma' as GdipSetImageAttributesGamma:qword
    extrn '__imp_GdipSetImageAttributesNoOp' as GdipSetImageAttributesNoOp:qword
    extrn '__imp_GdipSetImageAttributesOutputChannel' as GdipSetImageAttributesOutputChannel:qword
    extrn '__imp_GdipSetImageAttributesOutputChannelColorProfile' as GdipSetImageAttributesOutputChannelColorProfile:qword
    extrn '__imp_GdipSetImageAttributesRemapTable' as GdipSetImageAttributesRemapTable:qword
    extrn '__imp_GdipSetImageAttributesThreshold' as GdipSetImageAttributesThreshold:qword
    extrn '__imp_GdipSetImageAttributesToIdentity' as GdipSetImageAttributesToIdentity:qword
    extrn '__imp_GdipSetImageAttributesWrapMode' as GdipSetImageAttributesWrapMode:qword
    extrn '__imp_GdipSetImageLayout' as GdipSetImageLayout:qword
    extrn '__imp_GdipSetImagePalette' as GdipSetImagePalette:qword
    extrn '__imp_GdipSetInfinite' as GdipSetInfinite:qword
    extrn '__imp_GdipSetInterpolationMode' as GdipSetInterpolationMode:qword
    extrn '__imp_GdipSetLineBlend' as GdipSetLineBlend:qword
    extrn '__imp_GdipSetLineColors' as GdipSetLineColors:qword
    extrn '__imp_GdipSetLineGammaCorrection' as GdipSetLineGammaCorrection:qword
    extrn '__imp_GdipSetLineLinearBlend' as GdipSetLineLinearBlend:qword
    extrn '__imp_GdipSetLinePoints' as GdipSetLinePoints:qword
    extrn '__imp_GdipSetLinePointsI' as GdipSetLinePointsI:qword
    extrn '__imp_GdipSetLinePresetBlend' as GdipSetLinePresetBlend:qword
    extrn '__imp_GdipSetLineSigmaBlend' as GdipSetLineSigmaBlend:qword
    extrn '__imp_GdipSetLineTransform' as GdipSetLineTransform:qword
    extrn '__imp_GdipSetLineWrapMode' as GdipSetLineWrapMode:qword
    extrn '__imp_GdipSetMatrixElements' as GdipSetMatrixElements:qword
    extrn '__imp_GdipSetMetafileDownLevelRasterizationLimit' as GdipSetMetafileDownLevelRasterizationLimit:qword
    extrn '__imp_GdipSetPageScale' as GdipSetPageScale:qword
    extrn '__imp_GdipSetPageUnit' as GdipSetPageUnit:qword
    extrn '__imp_GdipSetPathFillMode' as GdipSetPathFillMode:qword
    extrn '__imp_GdipSetPathGradientBlend' as GdipSetPathGradientBlend:qword
    extrn '__imp_GdipSetPathGradientCenterColor' as GdipSetPathGradientCenterColor:qword
    extrn '__imp_GdipSetPathGradientCenterPoint' as GdipSetPathGradientCenterPoint:qword
    extrn '__imp_GdipSetPathGradientCenterPointI' as GdipSetPathGradientCenterPointI:qword
    extrn '__imp_GdipSetPathGradientFocusScales' as GdipSetPathGradientFocusScales:qword
    extrn '__imp_GdipSetPathGradientGammaCorrection' as GdipSetPathGradientGammaCorrection:qword
    extrn '__imp_GdipSetPathGradientLinearBlend' as GdipSetPathGradientLinearBlend:qword
    extrn '__imp_GdipSetPathGradientPath' as GdipSetPathGradientPath:qword
    extrn '__imp_GdipSetPathGradientPresetBlend' as GdipSetPathGradientPresetBlend:qword
    extrn '__imp_GdipSetPathGradientSigmaBlend' as GdipSetPathGradientSigmaBlend:qword
    extrn '__imp_GdipSetPathGradientSurroundColorsWithCount' as GdipSetPathGradientSurroundColorsWithCount:qword
    extrn '__imp_GdipSetPathGradientTransform' as GdipSetPathGradientTransform:qword
    extrn '__imp_GdipSetPathGradientWrapMode' as GdipSetPathGradientWrapMode:qword
    extrn '__imp_GdipSetPathMarker' as GdipSetPathMarker:qword
    extrn '__imp_GdipSetPenBrushFill' as GdipSetPenBrushFill:qword
    extrn '__imp_GdipSetPenColor' as GdipSetPenColor:qword
    extrn '__imp_GdipSetPenCompoundArray' as GdipSetPenCompoundArray:qword
    extrn '__imp_GdipSetPenCustomEndCap' as GdipSetPenCustomEndCap:qword
    extrn '__imp_GdipSetPenCustomStartCap' as GdipSetPenCustomStartCap:qword
    extrn '__imp_GdipSetPenDashArray' as GdipSetPenDashArray:qword
    extrn '__imp_GdipSetPenDashCap197819' as GdipSetPenDashCap197819:qword
    extrn '__imp_GdipSetPenDashOffset' as GdipSetPenDashOffset:qword
    extrn '__imp_GdipSetPenDashStyle' as GdipSetPenDashStyle:qword
    extrn '__imp_GdipSetPenEndCap' as GdipSetPenEndCap:qword
    extrn '__imp_GdipSetPenLineCap197819' as GdipSetPenLineCap197819:qword
    extrn '__imp_GdipSetPenLineJoin' as GdipSetPenLineJoin:qword
    extrn '__imp_GdipSetPenMiterLimit' as GdipSetPenMiterLimit:qword
    extrn '__imp_GdipSetPenMode' as GdipSetPenMode:qword
    extrn '__imp_GdipSetPenStartCap' as GdipSetPenStartCap:qword
    extrn '__imp_GdipSetPenTransform' as GdipSetPenTransform:qword
    extrn '__imp_GdipSetPenUnit' as GdipSetPenUnit:qword
    extrn '__imp_GdipSetPenWidth' as GdipSetPenWidth:qword
    extrn '__imp_GdipSetPixelOffsetMode' as GdipSetPixelOffsetMode:qword
    extrn '__imp_GdipSetPropertyItem' as GdipSetPropertyItem:qword
    extrn '__imp_GdipSetRenderingOrigin' as GdipSetRenderingOrigin:qword
    extrn '__imp_GdipSetSmoothingMode' as GdipSetSmoothingMode:qword
    extrn '__imp_GdipSetSolidFillColor' as GdipSetSolidFillColor:qword
    extrn '__imp_GdipSetStringFormatAlign' as GdipSetStringFormatAlign:qword
    extrn '__imp_GdipSetStringFormatDigitSubstitution' as GdipSetStringFormatDigitSubstitution:qword
    extrn '__imp_GdipSetStringFormatFlags' as GdipSetStringFormatFlags:qword
    extrn '__imp_GdipSetStringFormatHotkeyPrefix' as GdipSetStringFormatHotkeyPrefix:qword
    extrn '__imp_GdipSetStringFormatLineAlign' as GdipSetStringFormatLineAlign:qword
    extrn '__imp_GdipSetStringFormatMeasurableCharacterRanges' as GdipSetStringFormatMeasurableCharacterRanges:qword
    extrn '__imp_GdipSetStringFormatTabStops' as GdipSetStringFormatTabStops:qword
    extrn '__imp_GdipSetStringFormatTrimming' as GdipSetStringFormatTrimming:qword
    extrn '__imp_GdipSetTextContrast' as GdipSetTextContrast:qword
    extrn '__imp_GdipSetTextRenderingHint' as GdipSetTextRenderingHint:qword
    extrn '__imp_GdipSetTextureTransform' as GdipSetTextureTransform:qword
    extrn '__imp_GdipSetTextureWrapMode' as GdipSetTextureWrapMode:qword
    extrn '__imp_GdipSetWorldTransform' as GdipSetWorldTransform:qword
    extrn '__imp_GdipShearMatrix' as GdipShearMatrix:qword
    extrn '__imp_GdipStartPathFigure' as GdipStartPathFigure:qword
    extrn '__imp_GdipStringFormatGetGenericDefault' as GdipStringFormatGetGenericDefault:qword
    extrn '__imp_GdipStringFormatGetGenericTypographic' as GdipStringFormatGetGenericTypographic:qword
    extrn '__imp_GdipTestControl' as GdipTestControl:qword
    extrn '__imp_GdipTransformMatrixPoints' as GdipTransformMatrixPoints:qword
    extrn '__imp_GdipTransformMatrixPointsI' as GdipTransformMatrixPointsI:qword
    extrn '__imp_GdipTransformPath' as GdipTransformPath:qword
    extrn '__imp_GdipTransformPoints' as GdipTransformPoints:qword
    extrn '__imp_GdipTransformPointsI' as GdipTransformPointsI:qword
    extrn '__imp_GdipTransformRegion' as GdipTransformRegion:qword
    extrn '__imp_GdipTranslateClip' as GdipTranslateClip:qword
    extrn '__imp_GdipTranslateClipI' as GdipTranslateClipI:qword
    extrn '__imp_GdipTranslateLineTransform' as GdipTranslateLineTransform:qword
    extrn '__imp_GdipTranslateMatrix' as GdipTranslateMatrix:qword
    extrn '__imp_GdipTranslatePathGradientTransform' as GdipTranslatePathGradientTransform:qword
    extrn '__imp_GdipTranslatePenTransform' as GdipTranslatePenTransform:qword
    extrn '__imp_GdipTranslateRegion' as GdipTranslateRegion:qword
    extrn '__imp_GdipTranslateRegionI' as GdipTranslateRegionI:qword
    extrn '__imp_GdipTranslateTextureTransform' as GdipTranslateTextureTransform:qword
    extrn '__imp_GdipTranslateWorldTransform' as GdipTranslateWorldTransform:qword
    extrn '__imp_GdipVectorTransformMatrixPoints' as GdipVectorTransformMatrixPoints:qword
    extrn '__imp_GdipVectorTransformMatrixPointsI' as GdipVectorTransformMatrixPointsI:qword
    extrn '__imp_GdipWarpPath' as GdipWarpPath:qword
    extrn '__imp_GdipWidenPath' as GdipWidenPath:qword
    extrn '__imp_GdipWindingModeOutline' as GdipWindingModeOutline:qword
else
    extrn '__imp__GdipAddImageCodec@4' as GdipAddImageCodec:dword
    extrn '__imp__GdipAddPathArc@28' as GdipAddPathArc:dword
    extrn '__imp__GdipAddPathArcI@28' as GdipAddPathArcI:dword
    extrn '__imp__GdipAddPathBezier@36' as GdipAddPathBezier:dword
    extrn '__imp__GdipAddPathBezierI@36' as GdipAddPathBezierI:dword
    extrn '__imp__GdipAddPathBeziers@12' as GdipAddPathBeziers:dword
    extrn '__imp__GdipAddPathBeziersI@12' as GdipAddPathBeziersI:dword
    extrn '__imp__GdipAddPathClosedCurve@12' as GdipAddPathClosedCurve:dword
    extrn '__imp__GdipAddPathClosedCurve2@16' as GdipAddPathClosedCurve2:dword
    extrn '__imp__GdipAddPathClosedCurve2I@16' as GdipAddPathClosedCurve2I:dword
    extrn '__imp__GdipAddPathClosedCurveI@12' as GdipAddPathClosedCurveI:dword
    extrn '__imp__GdipAddPathCurve@12' as GdipAddPathCurve:dword
    extrn '__imp__GdipAddPathCurve2@16' as GdipAddPathCurve2:dword
    extrn '__imp__GdipAddPathCurve2I@16' as GdipAddPathCurve2I:dword
    extrn '__imp__GdipAddPathCurve3@24' as GdipAddPathCurve3:dword
    extrn '__imp__GdipAddPathCurve3I@24' as GdipAddPathCurve3I:dword
    extrn '__imp__GdipAddPathCurveI@12' as GdipAddPathCurveI:dword
    extrn '__imp__GdipAddPathEllipse@20' as GdipAddPathEllipse:dword
    extrn '__imp__GdipAddPathEllipseI@20' as GdipAddPathEllipseI:dword
    extrn '__imp__GdipAddPathLine@20' as GdipAddPathLine:dword
    extrn '__imp__GdipAddPathLine2@12' as GdipAddPathLine2:dword
    extrn '__imp__GdipAddPathLine2I@12' as GdipAddPathLine2I:dword
    extrn '__imp__GdipAddPathLineI@20' as GdipAddPathLineI:dword
    extrn '__imp__GdipAddPathPath@12' as GdipAddPathPath:dword
    extrn '__imp__GdipAddPathPie@28' as GdipAddPathPie:dword
    extrn '__imp__GdipAddPathPieI@28' as GdipAddPathPieI:dword
    extrn '__imp__GdipAddPathPolygon@12' as GdipAddPathPolygon:dword
    extrn '__imp__GdipAddPathPolygonI@12' as GdipAddPathPolygonI:dword
    extrn '__imp__GdipAddPathRectangle@20' as GdipAddPathRectangle:dword
    extrn '__imp__GdipAddPathRectangleI@20' as GdipAddPathRectangleI:dword
    extrn '__imp__GdipAddPathRectangles@12' as GdipAddPathRectangles:dword
    extrn '__imp__GdipAddPathRectanglesI@12' as GdipAddPathRectanglesI:dword
    extrn '__imp__GdipAddPathString@32' as GdipAddPathString:dword
    extrn '__imp__GdipAddPathStringI@32' as GdipAddPathStringI:dword
    extrn '__imp__GdipAlloc@4' as GdipAlloc:dword
    extrn '__imp__GdipBeginContainer@20' as GdipBeginContainer:dword
    extrn '__imp__GdipBeginContainer2@8' as GdipBeginContainer2:dword
    extrn '__imp__GdipBeginContainerI@20' as GdipBeginContainerI:dword
    extrn '__imp__GdipBitmapApplyEffect@24' as GdipBitmapApplyEffect:dword
    extrn '__imp__GdipBitmapConvertFormat@24' as GdipBitmapConvertFormat:dword
    extrn '__imp__GdipBitmapCreateApplyEffect@36' as GdipBitmapCreateApplyEffect:dword
    extrn '__imp__GdipBitmapGetHistogram@28' as GdipBitmapGetHistogram:dword
    extrn '__imp__GdipBitmapGetHistogramSize@8' as GdipBitmapGetHistogramSize:dword
    extrn '__imp__GdipBitmapGetPixel@16' as GdipBitmapGetPixel:dword
    extrn '__imp__GdipBitmapLockBits@20' as GdipBitmapLockBits:dword
    extrn '__imp__GdipBitmapSetPixel@16' as GdipBitmapSetPixel:dword
    extrn '__imp__GdipBitmapSetResolution@12' as GdipBitmapSetResolution:dword
    extrn '__imp__GdipBitmapUnlockBits@8' as GdipBitmapUnlockBits:dword
    extrn '__imp__GdipClearPathMarkers@4' as GdipClearPathMarkers:dword
    extrn '__imp__GdipCloneBitmapArea@28' as GdipCloneBitmapArea:dword
    extrn '__imp__GdipCloneBitmapAreaI@28' as GdipCloneBitmapAreaI:dword
    extrn '__imp__GdipCloneBrush@8' as GdipCloneBrush:dword
    extrn '__imp__GdipCloneCustomLineCap@8' as GdipCloneCustomLineCap:dword
    extrn '__imp__GdipCloneFont@8' as GdipCloneFont:dword
    extrn '__imp__GdipCloneFontFamily@8' as GdipCloneFontFamily:dword
    extrn '__imp__GdipCloneImage@8' as GdipCloneImage:dword
    extrn '__imp__GdipCloneImageAttributes@8' as GdipCloneImageAttributes:dword
    extrn '__imp__GdipCloneMatrix@8' as GdipCloneMatrix:dword
    extrn '__imp__GdipClonePath@8' as GdipClonePath:dword
    extrn '__imp__GdipClonePen@8' as GdipClonePen:dword
    extrn '__imp__GdipCloneRegion@8' as GdipCloneRegion:dword
    extrn '__imp__GdipCloneStringFormat@8' as GdipCloneStringFormat:dword
    extrn '__imp__GdipClosePathFigure@4' as GdipClosePathFigure:dword
    extrn '__imp__GdipClosePathFigures@4' as GdipClosePathFigures:dword
    extrn '__imp__GdipCombineRegionPath@12' as GdipCombineRegionPath:dword
    extrn '__imp__GdipCombineRegionRect@12' as GdipCombineRegionRect:dword
    extrn '__imp__GdipCombineRegionRectI@12' as GdipCombineRegionRectI:dword
    extrn '__imp__GdipCombineRegionRegion@12' as GdipCombineRegionRegion:dword
    extrn '__imp__GdipComment@12' as GdipComment:dword
    extrn '__imp__GdipConvertToEmfPlus@24' as GdipConvertToEmfPlus:dword
    extrn '__imp__GdipConvertToEmfPlusToFile@28' as GdipConvertToEmfPlusToFile:dword
    extrn '__imp__GdipConvertToEmfPlusToStream@28' as GdipConvertToEmfPlusToStream:dword
    extrn '__imp__GdipCreateAdjustableArrowCap@16' as GdipCreateAdjustableArrowCap:dword
    extrn '__imp__GdipCreateBitmapFromDirectDrawSurface@8' as GdipCreateBitmapFromDirectDrawSurface:dword
    extrn '__imp__GdipCreateBitmapFromFile@8' as GdipCreateBitmapFromFile:dword
    extrn '__imp__GdipCreateBitmapFromFileICM@8' as GdipCreateBitmapFromFileICM:dword
    extrn '__imp__GdipCreateBitmapFromGdiDib@12' as GdipCreateBitmapFromGdiDib:dword
    extrn '__imp__GdipCreateBitmapFromGraphics@16' as GdipCreateBitmapFromGraphics:dword
    extrn '__imp__GdipCreateBitmapFromHBITMAP@12' as GdipCreateBitmapFromHBITMAP:dword
    extrn '__imp__GdipCreateBitmapFromHICON@8' as GdipCreateBitmapFromHICON:dword
    extrn '__imp__GdipCreateBitmapFromResource@12' as GdipCreateBitmapFromResource:dword
    extrn '__imp__GdipCreateBitmapFromScan0@24' as GdipCreateBitmapFromScan0:dword
    extrn '__imp__GdipCreateBitmapFromStream@8' as GdipCreateBitmapFromStream:dword
    extrn '__imp__GdipCreateBitmapFromStreamICM@8' as GdipCreateBitmapFromStreamICM:dword
    extrn '__imp__GdipCreateCachedBitmap@12' as GdipCreateCachedBitmap:dword
    extrn '__imp__GdipCreateCustomLineCap@20' as GdipCreateCustomLineCap:dword
    extrn '__imp__GdipCreateEffect@8' as GdipCreateEffect:dword
    extrn '__imp__GdipCreateFont@20' as GdipCreateFont:dword
    extrn '__imp__GdipCreateFontFamilyFromName@12' as GdipCreateFontFamilyFromName:dword
    extrn '__imp__GdipCreateFontFromDC@8' as GdipCreateFontFromDC:dword
    extrn '__imp__GdipCreateFontFromLogfontA@12' as GdipCreateFontFromLogfontA:dword
    extrn '__imp__GdipCreateFontFromLogfontW@12' as GdipCreateFontFromLogfontW:dword
    extrn '__imp__GdipCreateFromHDC@8' as GdipCreateFromHDC:dword
    extrn '__imp__GdipCreateFromHDC2@12' as GdipCreateFromHDC2:dword
    extrn '__imp__GdipCreateFromHWND@8' as GdipCreateFromHWND:dword
    extrn '__imp__GdipCreateFromHWNDICM@8' as GdipCreateFromHWNDICM:dword
    extrn '__imp__GdipCreateHalftonePalette@0' as GdipCreateHalftonePalette:dword
    extrn '__imp__GdipCreateHatchBrush@16' as GdipCreateHatchBrush:dword
    extrn '__imp__GdipCreateHBITMAPFromBitmap@12' as GdipCreateHBITMAPFromBitmap:dword
    extrn '__imp__GdipCreateHICONFromBitmap@8' as GdipCreateHICONFromBitmap:dword
    extrn '__imp__GdipCreateImageAttributes@4' as GdipCreateImageAttributes:dword
    extrn '__imp__GdipCreateLineBrush@24' as GdipCreateLineBrush:dword
    extrn '__imp__GdipCreateLineBrushFromRect@24' as GdipCreateLineBrushFromRect:dword
    extrn '__imp__GdipCreateLineBrushFromRectI@24' as GdipCreateLineBrushFromRectI:dword
    extrn '__imp__GdipCreateLineBrushFromRectWithAngle@28' as GdipCreateLineBrushFromRectWithAngle:dword
    extrn '__imp__GdipCreateLineBrushFromRectWithAngleI@28' as GdipCreateLineBrushFromRectWithAngleI:dword
    extrn '__imp__GdipCreateLineBrushI@24' as GdipCreateLineBrushI:dword
    extrn '__imp__GdipCreateMatrix@4' as GdipCreateMatrix:dword
    extrn '__imp__GdipCreateMatrix2@28' as GdipCreateMatrix2:dword
    extrn '__imp__GdipCreateMatrix3@12' as GdipCreateMatrix3:dword
    extrn '__imp__GdipCreateMatrix3I@12' as GdipCreateMatrix3I:dword
    extrn '__imp__GdipCreateMetafileFromEmf@12' as GdipCreateMetafileFromEmf:dword
    extrn '__imp__GdipCreateMetafileFromFile@8' as GdipCreateMetafileFromFile:dword
    extrn '__imp__GdipCreateMetafileFromStream@8' as GdipCreateMetafileFromStream:dword
    extrn '__imp__GdipCreateMetafileFromWmf@16' as GdipCreateMetafileFromWmf:dword
    extrn '__imp__GdipCreateMetafileFromWmfFile@12' as GdipCreateMetafileFromWmfFile:dword
    extrn '__imp__GdipCreatePath@8' as GdipCreatePath:dword
    extrn '__imp__GdipCreatePath2@20' as GdipCreatePath2:dword
    extrn '__imp__GdipCreatePath2I@20' as GdipCreatePath2I:dword
    extrn '__imp__GdipCreatePathGradient@16' as GdipCreatePathGradient:dword
    extrn '__imp__GdipCreatePathGradientFromPath@8' as GdipCreatePathGradientFromPath:dword
    extrn '__imp__GdipCreatePathGradientI@16' as GdipCreatePathGradientI:dword
    extrn '__imp__GdipCreatePathIter@8' as GdipCreatePathIter:dword
    extrn '__imp__GdipCreatePen1@16' as GdipCreatePen1:dword
    extrn '__imp__GdipCreatePen2@16' as GdipCreatePen2:dword
    extrn '__imp__GdipCreateRegion@4' as GdipCreateRegion:dword
    extrn '__imp__GdipCreateRegionHrgn@8' as GdipCreateRegionHrgn:dword
    extrn '__imp__GdipCreateRegionPath@8' as GdipCreateRegionPath:dword
    extrn '__imp__GdipCreateRegionRect@8' as GdipCreateRegionRect:dword
    extrn '__imp__GdipCreateRegionRectI@8' as GdipCreateRegionRectI:dword
    extrn '__imp__GdipCreateRegionRgnData@12' as GdipCreateRegionRgnData:dword
    extrn '__imp__GdipCreateSolidFill@8' as GdipCreateSolidFill:dword
    extrn '__imp__GdipCreateStreamOnFile@12' as GdipCreateStreamOnFile:dword
    extrn '__imp__GdipCreateStringFormat@12' as GdipCreateStringFormat:dword
    extrn '__imp__GdipCreateTexture@12' as GdipCreateTexture:dword
    extrn '__imp__GdipCreateTexture2@28' as GdipCreateTexture2:dword
    extrn '__imp__GdipCreateTexture2I@28' as GdipCreateTexture2I:dword
    extrn '__imp__GdipCreateTextureIA@28' as GdipCreateTextureIA:dword
    extrn '__imp__GdipCreateTextureIAI@28' as GdipCreateTextureIAI:dword
    extrn '__imp__GdipDeleteBrush@4' as GdipDeleteBrush:dword
    extrn '__imp__GdipDeleteCachedBitmap@4' as GdipDeleteCachedBitmap:dword
    extrn '__imp__GdipDeleteCustomLineCap@4' as GdipDeleteCustomLineCap:dword
    extrn '__imp__GdipDeleteEffect@4' as GdipDeleteEffect:dword
    extrn '__imp__GdipDeleteFont@4' as GdipDeleteFont:dword
    extrn '__imp__GdipDeleteFontFamily@4' as GdipDeleteFontFamily:dword
    extrn '__imp__GdipDeleteGraphics@4' as GdipDeleteGraphics:dword
    extrn '__imp__GdipDeleteMatrix@4' as GdipDeleteMatrix:dword
    extrn '__imp__GdipDeletePath@4' as GdipDeletePath:dword
    extrn '__imp__GdipDeletePathIter@4' as GdipDeletePathIter:dword
    extrn '__imp__GdipDeletePen@4' as GdipDeletePen:dword
    extrn '__imp__GdipDeletePrivateFontCollection@4' as GdipDeletePrivateFontCollection:dword
    extrn '__imp__GdipDeleteRegion@4' as GdipDeleteRegion:dword
    extrn '__imp__GdipDeleteStringFormat@4' as GdipDeleteStringFormat:dword
    extrn '__imp__GdipDisposeImage@4' as GdipDisposeImage:dword
    extrn '__imp__GdipDisposeImageAttributes@4' as GdipDisposeImageAttributes:dword
    extrn '__imp__GdipDrawArc@32' as GdipDrawArc:dword
    extrn '__imp__GdipDrawArcI@32' as GdipDrawArcI:dword
    extrn '__imp__GdipDrawBezier@40' as GdipDrawBezier:dword
    extrn '__imp__GdipDrawBezierI@40' as GdipDrawBezierI:dword
    extrn '__imp__GdipDrawBeziers@16' as GdipDrawBeziers:dword
    extrn '__imp__GdipDrawBeziersI@16' as GdipDrawBeziersI:dword
    extrn '__imp__GdipDrawCachedBitmap@16' as GdipDrawCachedBitmap:dword
    extrn '__imp__GdipDrawClosedCurve@16' as GdipDrawClosedCurve:dword
    extrn '__imp__GdipDrawClosedCurve2@20' as GdipDrawClosedCurve2:dword
    extrn '__imp__GdipDrawClosedCurve2I@20' as GdipDrawClosedCurve2I:dword
    extrn '__imp__GdipDrawClosedCurveI@16' as GdipDrawClosedCurveI:dword
    extrn '__imp__GdipDrawCurve@16' as GdipDrawCurve:dword
    extrn '__imp__GdipDrawCurve2@20' as GdipDrawCurve2:dword
    extrn '__imp__GdipDrawCurve2I@20' as GdipDrawCurve2I:dword
    extrn '__imp__GdipDrawCurve3@28' as GdipDrawCurve3:dword
    extrn '__imp__GdipDrawCurve3I@28' as GdipDrawCurve3I:dword
    extrn '__imp__GdipDrawCurveI@16' as GdipDrawCurveI:dword
    extrn '__imp__GdipDrawDriverString@32' as GdipDrawDriverString:dword
    extrn '__imp__GdipDrawEllipse@24' as GdipDrawEllipse:dword
    extrn '__imp__GdipDrawEllipseI@24' as GdipDrawEllipseI:dword
    extrn '__imp__GdipDrawImage@16' as GdipDrawImage:dword
    extrn '__imp__GdipDrawImageFX@28' as GdipDrawImageFX:dword
    extrn '__imp__GdipDrawImageI@16' as GdipDrawImageI:dword
    extrn '__imp__GdipDrawImagePointRect@36' as GdipDrawImagePointRect:dword
    extrn '__imp__GdipDrawImagePointRectI@36' as GdipDrawImagePointRectI:dword
    extrn '__imp__GdipDrawImagePoints@16' as GdipDrawImagePoints:dword
    extrn '__imp__GdipDrawImagePointsI@16' as GdipDrawImagePointsI:dword
    extrn '__imp__GdipDrawImagePointsRect@48' as GdipDrawImagePointsRect:dword
    extrn '__imp__GdipDrawImagePointsRectI@48' as GdipDrawImagePointsRectI:dword
    extrn '__imp__GdipDrawImageRect@24' as GdipDrawImageRect:dword
    extrn '__imp__GdipDrawImageRectI@24' as GdipDrawImageRectI:dword
    extrn '__imp__GdipDrawImageRectRect@56' as GdipDrawImageRectRect:dword
    extrn '__imp__GdipDrawImageRectRectI@56' as GdipDrawImageRectRectI:dword
    extrn '__imp__GdipDrawLine@24' as GdipDrawLine:dword
    extrn '__imp__GdipDrawLineI@24' as GdipDrawLineI:dword
    extrn '__imp__GdipDrawLines@16' as GdipDrawLines:dword
    extrn '__imp__GdipDrawLinesI@16' as GdipDrawLinesI:dword
    extrn '__imp__GdipDrawPath@12' as GdipDrawPath:dword
    extrn '__imp__GdipDrawPie@32' as GdipDrawPie:dword
    extrn '__imp__GdipDrawPieI@32' as GdipDrawPieI:dword
    extrn '__imp__GdipDrawPolygon@16' as GdipDrawPolygon:dword
    extrn '__imp__GdipDrawPolygonI@16' as GdipDrawPolygonI:dword
    extrn '__imp__GdipDrawRectangle@24' as GdipDrawRectangle:dword
    extrn '__imp__GdipDrawRectangleI@24' as GdipDrawRectangleI:dword
    extrn '__imp__GdipDrawRectangles@16' as GdipDrawRectangles:dword
    extrn '__imp__GdipDrawRectanglesI@16' as GdipDrawRectanglesI:dword
    extrn '__imp__GdipDrawString@28' as GdipDrawString:dword
    extrn '__imp__GdipEmfToWmfBits@20' as GdipEmfToWmfBits:dword
    extrn '__imp__GdipEndContainer@8' as GdipEndContainer:dword
    extrn '__imp__GdipEnumerateMetafileDestPoint@24' as GdipEnumerateMetafileDestPoint:dword
    extrn '__imp__GdipEnumerateMetafileDestPointI@24' as GdipEnumerateMetafileDestPointI:dword
    extrn '__imp__GdipEnumerateMetafileDestPoints@28' as GdipEnumerateMetafileDestPoints:dword
    extrn '__imp__GdipEnumerateMetafileDestPointsI@28' as GdipEnumerateMetafileDestPointsI:dword
    extrn '__imp__GdipEnumerateMetafileDestRect@24' as GdipEnumerateMetafileDestRect:dword
    extrn '__imp__GdipEnumerateMetafileDestRectI@24' as GdipEnumerateMetafileDestRectI:dword
    extrn '__imp__GdipEnumerateMetafileSrcRectDestPoint@32' as GdipEnumerateMetafileSrcRectDestPoint:dword
    extrn '__imp__GdipEnumerateMetafileSrcRectDestPointI@32' as GdipEnumerateMetafileSrcRectDestPointI:dword
    extrn '__imp__GdipEnumerateMetafileSrcRectDestPoints@36' as GdipEnumerateMetafileSrcRectDestPoints:dword
    extrn '__imp__GdipEnumerateMetafileSrcRectDestPointsI@36' as GdipEnumerateMetafileSrcRectDestPointsI:dword
    extrn '__imp__GdipEnumerateMetafileSrcRectDestRect@32' as GdipEnumerateMetafileSrcRectDestRect:dword
    extrn '__imp__GdipEnumerateMetafileSrcRectDestRectI@32' as GdipEnumerateMetafileSrcRectDestRectI:dword
    extrn '__imp__GdipFillClosedCurve@16' as GdipFillClosedCurve:dword
    extrn '__imp__GdipFillClosedCurve2@24' as GdipFillClosedCurve2:dword
    extrn '__imp__GdipFillClosedCurve2I@24' as GdipFillClosedCurve2I:dword
    extrn '__imp__GdipFillClosedCurveI@16' as GdipFillClosedCurveI:dword
    extrn '__imp__GdipFillEllipse@24' as GdipFillEllipse:dword
    extrn '__imp__GdipFillEllipseI@24' as GdipFillEllipseI:dword
    extrn '__imp__GdipFillPath@12' as GdipFillPath:dword
    extrn '__imp__GdipFillPie@32' as GdipFillPie:dword
    extrn '__imp__GdipFillPieI@32' as GdipFillPieI:dword
    extrn '__imp__GdipFillPolygon@20' as GdipFillPolygon:dword
    extrn '__imp__GdipFillPolygon2@16' as GdipFillPolygon2:dword
    extrn '__imp__GdipFillPolygon2I@16' as GdipFillPolygon2I:dword
    extrn '__imp__GdipFillPolygonI@20' as GdipFillPolygonI:dword
    extrn '__imp__GdipFillRectangle@24' as GdipFillRectangle:dword
    extrn '__imp__GdipFillRectangleI@24' as GdipFillRectangleI:dword
    extrn '__imp__GdipFillRectangles@16' as GdipFillRectangles:dword
    extrn '__imp__GdipFillRectanglesI@16' as GdipFillRectanglesI:dword
    extrn '__imp__GdipFillRegion@12' as GdipFillRegion:dword
    extrn '__imp__GdipFindFirstImageItem@8' as GdipFindFirstImageItem:dword
    extrn '__imp__GdipFindNextImageItem@8' as GdipFindNextImageItem:dword
    extrn '__imp__GdipFlattenPath@12' as GdipFlattenPath:dword
    extrn '__imp__GdipFlush@8' as GdipFlush:dword
    extrn '__imp__GdipFree@4' as GdipFree:dword
    extrn '__imp__GdipGetAdjustableArrowCapFillState@8' as GdipGetAdjustableArrowCapFillState:dword
    extrn '__imp__GdipGetAdjustableArrowCapHeight@8' as GdipGetAdjustableArrowCapHeight:dword
    extrn '__imp__GdipGetAdjustableArrowCapMiddleInset@8' as GdipGetAdjustableArrowCapMiddleInset:dword
    extrn '__imp__GdipGetAdjustableArrowCapWidth@8' as GdipGetAdjustableArrowCapWidth:dword
    extrn '__imp__GdipGetAllPropertyItems@16' as GdipGetAllPropertyItems:dword
    extrn '__imp__GdipGetBrushType@8' as GdipGetBrushType:dword
    extrn '__imp__GdipGetCellAscent@12' as GdipGetCellAscent:dword
    extrn '__imp__GdipGetCellDescent@12' as GdipGetCellDescent:dword
    extrn '__imp__GdipGetClip@8' as GdipGetClip:dword
    extrn '__imp__GdipGetClipBounds@8' as GdipGetClipBounds:dword
    extrn '__imp__GdipGetClipBoundsI@8' as GdipGetClipBoundsI:dword
    extrn '__imp__GdipGetCompositingMode@8' as GdipGetCompositingMode:dword
    extrn '__imp__GdipGetCompositingQuality@8' as GdipGetCompositingQuality:dword
    extrn '__imp__GdipGetCustomLineCapBaseCap@8' as GdipGetCustomLineCapBaseCap:dword
    extrn '__imp__GdipGetCustomLineCapBaseInset@8' as GdipGetCustomLineCapBaseInset:dword
    extrn '__imp__GdipGetCustomLineCapStrokeCaps@12' as GdipGetCustomLineCapStrokeCaps:dword
    extrn '__imp__GdipGetCustomLineCapStrokeJoin@8' as GdipGetCustomLineCapStrokeJoin:dword
    extrn '__imp__GdipGetCustomLineCapType@8' as GdipGetCustomLineCapType:dword
    extrn '__imp__GdipGetCustomLineCapWidthScale@8' as GdipGetCustomLineCapWidthScale:dword
    extrn '__imp__GdipGetDC@8' as GdipGetDC:dword
    extrn '__imp__GdipGetDpiX@8' as GdipGetDpiX:dword
    extrn '__imp__GdipGetDpiY@8' as GdipGetDpiY:dword
    extrn '__imp__GdipGetEffectParameters@12' as GdipGetEffectParameters:dword
    extrn '__imp__GdipGetEffectParameterSize@8' as GdipGetEffectParameterSize:dword
    extrn '__imp__GdipGetEmHeight@12' as GdipGetEmHeight:dword
    extrn '__imp__GdipGetEncoderParameterList@16' as GdipGetEncoderParameterList:dword
    extrn '__imp__GdipGetEncoderParameterListSize@12' as GdipGetEncoderParameterListSize:dword
    extrn '__imp__GdipGetFamily@8' as GdipGetFamily:dword
    extrn '__imp__GdipGetFamilyName@12' as GdipGetFamilyName:dword
    extrn '__imp__GdipGetFontCollectionFamilyCount@8' as GdipGetFontCollectionFamilyCount:dword
    extrn '__imp__GdipGetFontCollectionFamilyList@16' as GdipGetFontCollectionFamilyList:dword
    extrn '__imp__GdipGetFontHeight@12' as GdipGetFontHeight:dword
    extrn '__imp__GdipGetFontHeightGivenDPI@12' as GdipGetFontHeightGivenDPI:dword
    extrn '__imp__GdipGetFontSize@8' as GdipGetFontSize:dword
    extrn '__imp__GdipGetFontStyle@8' as GdipGetFontStyle:dword
    extrn '__imp__GdipGetFontUnit@8' as GdipGetFontUnit:dword
    extrn '__imp__GdipGetGenericFontFamilyMonospace@4' as GdipGetGenericFontFamilyMonospace:dword
    extrn '__imp__GdipGetGenericFontFamilySansSerif@4' as GdipGetGenericFontFamilySansSerif:dword
    extrn '__imp__GdipGetGenericFontFamilySerif@4' as GdipGetGenericFontFamilySerif:dword
    extrn '__imp__GdipGetGraphicsLayout@8' as GdipGetGraphicsLayout:dword
    extrn '__imp__GdipGetHatchBackgroundColor@8' as GdipGetHatchBackgroundColor:dword
    extrn '__imp__GdipGetHatchForegroundColor@8' as GdipGetHatchForegroundColor:dword
    extrn '__imp__GdipGetHatchStyle@8' as GdipGetHatchStyle:dword
    extrn '__imp__GdipGetHemfFromMetafile@8' as GdipGetHemfFromMetafile:dword
    extrn '__imp__GdipGetImageAttributesAdjustedPalette@12' as GdipGetImageAttributesAdjustedPalette:dword
    extrn '__imp__GdipGetImageBounds@12' as GdipGetImageBounds:dword
    extrn '__imp__GdipGetImageDecoders@12' as GdipGetImageDecoders:dword
    extrn '__imp__GdipGetImageDecodersSize@8' as GdipGetImageDecodersSize:dword
    extrn '__imp__GdipGetImageDimension@12' as GdipGetImageDimension:dword
    extrn '__imp__GdipGetImageEncoders@12' as GdipGetImageEncoders:dword
    extrn '__imp__GdipGetImageEncodersSize@8' as GdipGetImageEncodersSize:dword
    extrn '__imp__GdipGetImageFlags@8' as GdipGetImageFlags:dword
    extrn '__imp__GdipGetImageGraphicsContext@8' as GdipGetImageGraphicsContext:dword
    extrn '__imp__GdipGetImageHeight@8' as GdipGetImageHeight:dword
    extrn '__imp__GdipGetImageHorizontalResolution@8' as GdipGetImageHorizontalResolution:dword
    extrn '__imp__GdipGetImageLayout@8' as GdipGetImageLayout:dword
    extrn '__imp__GdipGetImagePalette@12' as GdipGetImagePalette:dword
    extrn '__imp__GdipGetImagePaletteSize@8' as GdipGetImagePaletteSize:dword
    extrn '__imp__GdipGetImagePixelFormat@8' as GdipGetImagePixelFormat:dword
    extrn '__imp__GdipGetImageRawFormat@8' as GdipGetImageRawFormat:dword
    extrn '__imp__GdipGetImageThumbnail@24' as GdipGetImageThumbnail:dword
    extrn '__imp__GdipGetImageType@8' as GdipGetImageType:dword
    extrn '__imp__GdipGetImageVerticalResolution@8' as GdipGetImageVerticalResolution:dword
    extrn '__imp__GdipGetImageWidth@8' as GdipGetImageWidth:dword
    extrn '__imp__GdipGetInterpolationMode@8' as GdipGetInterpolationMode:dword
    extrn '__imp__GdipGetLineBlend@16' as GdipGetLineBlend:dword
    extrn '__imp__GdipGetLineBlendCount@8' as GdipGetLineBlendCount:dword
    extrn '__imp__GdipGetLineColors@8' as GdipGetLineColors:dword
    extrn '__imp__GdipGetLineGammaCorrection@8' as GdipGetLineGammaCorrection:dword
    extrn '__imp__GdipGetLinePoints@8' as GdipGetLinePoints:dword
    extrn '__imp__GdipGetLinePointsI@8' as GdipGetLinePointsI:dword
    extrn '__imp__GdipGetLinePresetBlend@16' as GdipGetLinePresetBlend:dword
    extrn '__imp__GdipGetLinePresetBlendCount@8' as GdipGetLinePresetBlendCount:dword
    extrn '__imp__GdipGetLineRect@8' as GdipGetLineRect:dword
    extrn '__imp__GdipGetLineRectI@8' as GdipGetLineRectI:dword
    extrn '__imp__GdipGetLineSpacing@12' as GdipGetLineSpacing:dword
    extrn '__imp__GdipGetLineTransform@8' as GdipGetLineTransform:dword
    extrn '__imp__GdipGetLineWrapMode@8' as GdipGetLineWrapMode:dword
    extrn '__imp__GdipGetLogFontA@12' as GdipGetLogFontA:dword
    extrn '__imp__GdipGetLogFontW@12' as GdipGetLogFontW:dword
    extrn '__imp__GdipGetMatrixElements@8' as GdipGetMatrixElements:dword
    extrn '__imp__GdipGetMetafileDownLevelRasterizationLimit@8' as GdipGetMetafileDownLevelRasterizationLimit:dword
    extrn '__imp__GdipGetMetafileHeaderFromEmf@8' as GdipGetMetafileHeaderFromEmf:dword
    extrn '__imp__GdipGetMetafileHeaderFromFile@8' as GdipGetMetafileHeaderFromFile:dword
    extrn '__imp__GdipGetMetafileHeaderFromMetafile@8' as GdipGetMetafileHeaderFromMetafile:dword
    extrn '__imp__GdipGetMetafileHeaderFromStream@8' as GdipGetMetafileHeaderFromStream:dword
    extrn '__imp__GdipGetMetafileHeaderFromWmf@12' as GdipGetMetafileHeaderFromWmf:dword
    extrn '__imp__GdipGetNearestColor@8' as GdipGetNearestColor:dword
    extrn '__imp__GdipGetPageScale@8' as GdipGetPageScale:dword
    extrn '__imp__GdipGetPageUnit@8' as GdipGetPageUnit:dword
    extrn '__imp__GdipGetPathData@8' as GdipGetPathData:dword
    extrn '__imp__GdipGetPathFillMode@8' as GdipGetPathFillMode:dword
    extrn '__imp__GdipGetPathGradientBlend@16' as GdipGetPathGradientBlend:dword
    extrn '__imp__GdipGetPathGradientBlendCount@8' as GdipGetPathGradientBlendCount:dword
    extrn '__imp__GdipGetPathGradientCenterColor@8' as GdipGetPathGradientCenterColor:dword
    extrn '__imp__GdipGetPathGradientCenterPoint@8' as GdipGetPathGradientCenterPoint:dword
    extrn '__imp__GdipGetPathGradientCenterPointI@8' as GdipGetPathGradientCenterPointI:dword
    extrn '__imp__GdipGetPathGradientFocusScales@12' as GdipGetPathGradientFocusScales:dword
    extrn '__imp__GdipGetPathGradientGammaCorrection@8' as GdipGetPathGradientGammaCorrection:dword
    extrn '__imp__GdipGetPathGradientPath@8' as GdipGetPathGradientPath:dword
    extrn '__imp__GdipGetPathGradientPointCount@8' as GdipGetPathGradientPointCount:dword
    extrn '__imp__GdipGetPathGradientPresetBlend@16' as GdipGetPathGradientPresetBlend:dword
    extrn '__imp__GdipGetPathGradientPresetBlendCount@8' as GdipGetPathGradientPresetBlendCount:dword
    extrn '__imp__GdipGetPathGradientRect@8' as GdipGetPathGradientRect:dword
    extrn '__imp__GdipGetPathGradientRectI@8' as GdipGetPathGradientRectI:dword
    extrn '__imp__GdipGetPathGradientSurroundColorCount@8' as GdipGetPathGradientSurroundColorCount:dword
    extrn '__imp__GdipGetPathGradientSurroundColorsWithCount@12' as GdipGetPathGradientSurroundColorsWithCount:dword
    extrn '__imp__GdipGetPathGradientTransform@8' as GdipGetPathGradientTransform:dword
    extrn '__imp__GdipGetPathGradientWrapMode@8' as GdipGetPathGradientWrapMode:dword
    extrn '__imp__GdipGetPathLastPoint@8' as GdipGetPathLastPoint:dword
    extrn '__imp__GdipGetPathPoints@12' as GdipGetPathPoints:dword
    extrn '__imp__GdipGetPathPointsI@12' as GdipGetPathPointsI:dword
    extrn '__imp__GdipGetPathTypes@12' as GdipGetPathTypes:dword
    extrn '__imp__GdipGetPathWorldBounds@16' as GdipGetPathWorldBounds:dword
    extrn '__imp__GdipGetPathWorldBoundsI@16' as GdipGetPathWorldBoundsI:dword
    extrn '__imp__GdipGetPenBrushFill@8' as GdipGetPenBrushFill:dword
    extrn '__imp__GdipGetPenColor@8' as GdipGetPenColor:dword
    extrn '__imp__GdipGetPenCompoundArray@12' as GdipGetPenCompoundArray:dword
    extrn '__imp__GdipGetPenCompoundCount@8' as GdipGetPenCompoundCount:dword
    extrn '__imp__GdipGetPenCustomEndCap@8' as GdipGetPenCustomEndCap:dword
    extrn '__imp__GdipGetPenCustomStartCap@8' as GdipGetPenCustomStartCap:dword
    extrn '__imp__GdipGetPenDashArray@12' as GdipGetPenDashArray:dword
    extrn '__imp__GdipGetPenDashCap197819@8' as GdipGetPenDashCap197819:dword
    extrn '__imp__GdipGetPenDashCount@8' as GdipGetPenDashCount:dword
    extrn '__imp__GdipGetPenDashOffset@8' as GdipGetPenDashOffset:dword
    extrn '__imp__GdipGetPenDashStyle@8' as GdipGetPenDashStyle:dword
    extrn '__imp__GdipGetPenEndCap@8' as GdipGetPenEndCap:dword
    extrn '__imp__GdipGetPenFillType@8' as GdipGetPenFillType:dword
    extrn '__imp__GdipGetPenLineJoin@8' as GdipGetPenLineJoin:dword
    extrn '__imp__GdipGetPenMiterLimit@8' as GdipGetPenMiterLimit:dword
    extrn '__imp__GdipGetPenMode@8' as GdipGetPenMode:dword
    extrn '__imp__GdipGetPenStartCap@8' as GdipGetPenStartCap:dword
    extrn '__imp__GdipGetPenTransform@8' as GdipGetPenTransform:dword
    extrn '__imp__GdipGetPenUnit@8' as GdipGetPenUnit:dword
    extrn '__imp__GdipGetPenWidth@8' as GdipGetPenWidth:dword
    extrn '__imp__GdipGetPixelOffsetMode@8' as GdipGetPixelOffsetMode:dword
    extrn '__imp__GdipGetPointCount@8' as GdipGetPointCount:dword
    extrn '__imp__GdipGetPropertyCount@8' as GdipGetPropertyCount:dword
    extrn '__imp__GdipGetPropertyIdList@12' as GdipGetPropertyIdList:dword
    extrn '__imp__GdipGetPropertyItem@16' as GdipGetPropertyItem:dword
    extrn '__imp__GdipGetPropertyItemSize@12' as GdipGetPropertyItemSize:dword
    extrn '__imp__GdipGetPropertySize@12' as GdipGetPropertySize:dword
    extrn '__imp__GdipGetRegionBounds@12' as GdipGetRegionBounds:dword
    extrn '__imp__GdipGetRegionBoundsI@12' as GdipGetRegionBoundsI:dword
    extrn '__imp__GdipGetRegionData@16' as GdipGetRegionData:dword
    extrn '__imp__GdipGetRegionDataSize@8' as GdipGetRegionDataSize:dword
    extrn '__imp__GdipGetRegionHRgn@12' as GdipGetRegionHRgn:dword
    extrn '__imp__GdipGetRegionScans@16' as GdipGetRegionScans:dword
    extrn '__imp__GdipGetRegionScansCount@12' as GdipGetRegionScansCount:dword
    extrn '__imp__GdipGetRegionScansI@16' as GdipGetRegionScansI:dword
    extrn '__imp__GdipGetRenderingOrigin@12' as GdipGetRenderingOrigin:dword
    extrn '__imp__GdipGetSmoothingMode@8' as GdipGetSmoothingMode:dword
    extrn '__imp__GdipGetSolidFillColor@8' as GdipGetSolidFillColor:dword
    extrn '__imp__GdipGetStringFormatAlign@8' as GdipGetStringFormatAlign:dword
    extrn '__imp__GdipGetStringFormatDigitSubstitution@12' as GdipGetStringFormatDigitSubstitution:dword
    extrn '__imp__GdipGetStringFormatFlags@8' as GdipGetStringFormatFlags:dword
    extrn '__imp__GdipGetStringFormatHotkeyPrefix@8' as GdipGetStringFormatHotkeyPrefix:dword
    extrn '__imp__GdipGetStringFormatLineAlign@8' as GdipGetStringFormatLineAlign:dword
    extrn '__imp__GdipGetStringFormatMeasurableCharacterRangeCount@8' as GdipGetStringFormatMeasurableCharacterRangeCount:dword
    extrn '__imp__GdipGetStringFormatTabStopCount@8' as GdipGetStringFormatTabStopCount:dword
    extrn '__imp__GdipGetStringFormatTabStops@16' as GdipGetStringFormatTabStops:dword
    extrn '__imp__GdipGetStringFormatTrimming@8' as GdipGetStringFormatTrimming:dword
    extrn '__imp__GdipGetTextContrast@8' as GdipGetTextContrast:dword
    extrn '__imp__GdipGetTextRenderingHint@8' as GdipGetTextRenderingHint:dword
    extrn '__imp__GdipGetTextureImage@8' as GdipGetTextureImage:dword
    extrn '__imp__GdipGetTextureTransform@8' as GdipGetTextureTransform:dword
    extrn '__imp__GdipGetTextureWrapMode@8' as GdipGetTextureWrapMode:dword
    extrn '__imp__GdipGetVisibleClipBounds@8' as GdipGetVisibleClipBounds:dword
    extrn '__imp__GdipGetVisibleClipBoundsI@8' as GdipGetVisibleClipBoundsI:dword
    extrn '__imp__GdipGetWorldTransform@8' as GdipGetWorldTransform:dword
    extrn '__imp__GdipGraphicsClear@8' as GdipGraphicsClear:dword
    extrn '__imp__GdipGraphicsSetAbort@8' as GdipGraphicsSetAbort:dword
    extrn '__imp__GdipImageForceValidation@4' as GdipImageForceValidation:dword
    extrn '__imp__GdipImageGetFrameCount@12' as GdipImageGetFrameCount:dword
    extrn '__imp__GdipImageGetFrameDimensionsCount@8' as GdipImageGetFrameDimensionsCount:dword
    extrn '__imp__GdipImageGetFrameDimensionsList@12' as GdipImageGetFrameDimensionsList:dword
    extrn '__imp__GdipImageRotateFlip@8' as GdipImageRotateFlip:dword
    extrn '__imp__GdipImageSelectActiveFrame@12' as GdipImageSelectActiveFrame:dword
    extrn '__imp__GdipImageSetAbort@8' as GdipImageSetAbort:dword
    extrn '__imp__GdipInitializePalette@20' as GdipInitializePalette:dword
    extrn '__imp__GdipInvertMatrix@4' as GdipInvertMatrix:dword
    extrn '__imp__GdipIsClipEmpty@8' as GdipIsClipEmpty:dword
    extrn '__imp__GdipIsEmptyRegion@12' as GdipIsEmptyRegion:dword
    extrn '__imp__GdipIsEqualRegion@16' as GdipIsEqualRegion:dword
    extrn '__imp__GdipIsInfiniteRegion@12' as GdipIsInfiniteRegion:dword
    extrn '__imp__GdipIsMatrixEqual@12' as GdipIsMatrixEqual:dword
    extrn '__imp__GdipIsMatrixIdentity@8' as GdipIsMatrixIdentity:dword
    extrn '__imp__GdipIsMatrixInvertible@8' as GdipIsMatrixInvertible:dword
    extrn '__imp__GdipIsOutlineVisiblePathPoint@24' as GdipIsOutlineVisiblePathPoint:dword
    extrn '__imp__GdipIsOutlineVisiblePathPointI@24' as GdipIsOutlineVisiblePathPointI:dword
    extrn '__imp__GdipIsStyleAvailable@12' as GdipIsStyleAvailable:dword
    extrn '__imp__GdipIsVisibleClipEmpty@8' as GdipIsVisibleClipEmpty:dword
    extrn '__imp__GdipIsVisiblePathPoint@20' as GdipIsVisiblePathPoint:dword
    extrn '__imp__GdipIsVisiblePathPointI@20' as GdipIsVisiblePathPointI:dword
    extrn '__imp__GdipIsVisiblePoint@16' as GdipIsVisiblePoint:dword
    extrn '__imp__GdipIsVisiblePointI@16' as GdipIsVisiblePointI:dword
    extrn '__imp__GdipIsVisibleRect@24' as GdipIsVisibleRect:dword
    extrn '__imp__GdipIsVisibleRectI@24' as GdipIsVisibleRectI:dword
    extrn '__imp__GdipIsVisibleRegionPoint@20' as GdipIsVisibleRegionPoint:dword
    extrn '__imp__GdipIsVisibleRegionPointI@20' as GdipIsVisibleRegionPointI:dword
    extrn '__imp__GdipIsVisibleRegionRect@28' as GdipIsVisibleRegionRect:dword
    extrn '__imp__GdipIsVisibleRegionRectI@28' as GdipIsVisibleRegionRectI:dword
    extrn '__imp__GdipLoadImageFromFile@8' as GdipLoadImageFromFile:dword
    extrn '__imp__GdipLoadImageFromFileICM@8' as GdipLoadImageFromFileICM:dword
    extrn '__imp__GdipLoadImageFromStream@8' as GdipLoadImageFromStream:dword
    extrn '__imp__GdipLoadImageFromStreamICM@8' as GdipLoadImageFromStreamICM:dword
    extrn '__imp__GdipMeasureCharacterRanges@32' as GdipMeasureCharacterRanges:dword
    extrn '__imp__GdipMeasureDriverString@32' as GdipMeasureDriverString:dword
    extrn '__imp__GdipMeasureString@36' as GdipMeasureString:dword
    extrn '__imp__GdipMultiplyLineTransform@12' as GdipMultiplyLineTransform:dword
    extrn '__imp__GdipMultiplyMatrix@12' as GdipMultiplyMatrix:dword
    extrn '__imp__GdipMultiplyPathGradientTransform@12' as GdipMultiplyPathGradientTransform:dword
    extrn '__imp__GdipMultiplyPenTransform@12' as GdipMultiplyPenTransform:dword
    extrn '__imp__GdipMultiplyTextureTransform@12' as GdipMultiplyTextureTransform:dword
    extrn '__imp__GdipMultiplyWorldTransform@12' as GdipMultiplyWorldTransform:dword
    extrn '__imp__GdipNewInstalledFontCollection@4' as GdipNewInstalledFontCollection:dword
    extrn '__imp__GdipNewPrivateFontCollection@4' as GdipNewPrivateFontCollection:dword
    extrn '__imp__GdipPathIterCopyData@24' as GdipPathIterCopyData:dword
    extrn '__imp__GdipPathIterEnumerate@20' as GdipPathIterEnumerate:dword
    extrn '__imp__GdipPathIterGetCount@8' as GdipPathIterGetCount:dword
    extrn '__imp__GdipPathIterGetSubpathCount@8' as GdipPathIterGetSubpathCount:dword
    extrn '__imp__GdipPathIterHasCurve@8' as GdipPathIterHasCurve:dword
    extrn '__imp__GdipPathIterIsValid@8' as GdipPathIterIsValid:dword
    extrn '__imp__GdipPathIterNextMarker@16' as GdipPathIterNextMarker:dword
    extrn '__imp__GdipPathIterNextMarkerPath@12' as GdipPathIterNextMarkerPath:dword
    extrn '__imp__GdipPathIterNextPathType@20' as GdipPathIterNextPathType:dword
    extrn '__imp__GdipPathIterNextSubpath@20' as GdipPathIterNextSubpath:dword
    extrn '__imp__GdipPathIterNextSubpathPath@16' as GdipPathIterNextSubpathPath:dword
    extrn '__imp__GdipPathIterRewind@4' as GdipPathIterRewind:dword
    extrn '__imp__GdipPlayMetafileRecord@20' as GdipPlayMetafileRecord:dword
    extrn '__imp__GdiplusNotificationHook@4' as GdiplusNotificationHook:dword
    extrn '__imp__GdiplusNotificationUnhook@4' as GdiplusNotificationUnhook:dword
    extrn '__imp__GdiplusShutdown@4' as GdiplusShutdown:dword
    extrn '__imp__GdiplusStartup@12' as GdiplusStartup:dword
    extrn '__imp__GdipPrivateAddFontFile@8' as GdipPrivateAddFontFile:dword
    extrn '__imp__GdipPrivateAddMemoryFont@12' as GdipPrivateAddMemoryFont:dword
    extrn '__imp__GdipRecordMetafile@24' as GdipRecordMetafile:dword
    extrn '__imp__GdipRecordMetafileFileName@28' as GdipRecordMetafileFileName:dword
    extrn '__imp__GdipRecordMetafileFileNameI@28' as GdipRecordMetafileFileNameI:dword
    extrn '__imp__GdipRecordMetafileI@24' as GdipRecordMetafileI:dword
    extrn '__imp__GdipRecordMetafileStream@28' as GdipRecordMetafileStream:dword
    extrn '__imp__GdipRecordMetafileStreamI@28' as GdipRecordMetafileStreamI:dword
    extrn '__imp__GdipReleaseDC@8' as GdipReleaseDC:dword
    extrn '__imp__GdipRemoveImageCodec@4' as GdipRemoveImageCodec:dword
    extrn '__imp__GdipRemovePropertyItem@8' as GdipRemovePropertyItem:dword
    extrn '__imp__GdipResetClip@4' as GdipResetClip:dword
    extrn '__imp__GdipResetImageAttributes@8' as GdipResetImageAttributes:dword
    extrn '__imp__GdipResetLineTransform@4' as GdipResetLineTransform:dword
    extrn '__imp__GdipResetPageTransform@4' as GdipResetPageTransform:dword
    extrn '__imp__GdipResetPath@4' as GdipResetPath:dword
    extrn '__imp__GdipResetPathGradientTransform@4' as GdipResetPathGradientTransform:dword
    extrn '__imp__GdipResetPenTransform@4' as GdipResetPenTransform:dword
    extrn '__imp__GdipResetTextureTransform@4' as GdipResetTextureTransform:dword
    extrn '__imp__GdipResetWorldTransform@4' as GdipResetWorldTransform:dword
    extrn '__imp__GdipRestoreGraphics@8' as GdipRestoreGraphics:dword
    extrn '__imp__GdipReversePath@4' as GdipReversePath:dword
    extrn '__imp__GdipRotateLineTransform@12' as GdipRotateLineTransform:dword
    extrn '__imp__GdipRotateMatrix@12' as GdipRotateMatrix:dword
    extrn '__imp__GdipRotatePathGradientTransform@12' as GdipRotatePathGradientTransform:dword
    extrn '__imp__GdipRotatePenTransform@12' as GdipRotatePenTransform:dword
    extrn '__imp__GdipRotateTextureTransform@12' as GdipRotateTextureTransform:dword
    extrn '__imp__GdipRotateWorldTransform@12' as GdipRotateWorldTransform:dword
    extrn '__imp__GdipSaveAdd@8' as GdipSaveAdd:dword
    extrn '__imp__GdipSaveAddImage@12' as GdipSaveAddImage:dword
    extrn '__imp__GdipSaveGraphics@8' as GdipSaveGraphics:dword
    extrn '__imp__GdipSaveImageToFile@16' as GdipSaveImageToFile:dword
    extrn '__imp__GdipSaveImageToStream@16' as GdipSaveImageToStream:dword
    extrn '__imp__GdipScaleLineTransform@16' as GdipScaleLineTransform:dword
    extrn '__imp__GdipScaleMatrix@16' as GdipScaleMatrix:dword
    extrn '__imp__GdipScalePathGradientTransform@16' as GdipScalePathGradientTransform:dword
    extrn '__imp__GdipScalePenTransform@16' as GdipScalePenTransform:dword
    extrn '__imp__GdipScaleTextureTransform@16' as GdipScaleTextureTransform:dword
    extrn '__imp__GdipScaleWorldTransform@16' as GdipScaleWorldTransform:dword
    extrn '__imp__GdipSetAdjustableArrowCapFillState@8' as GdipSetAdjustableArrowCapFillState:dword
    extrn '__imp__GdipSetAdjustableArrowCapHeight@8' as GdipSetAdjustableArrowCapHeight:dword
    extrn '__imp__GdipSetAdjustableArrowCapMiddleInset@8' as GdipSetAdjustableArrowCapMiddleInset:dword
    extrn '__imp__GdipSetAdjustableArrowCapWidth@8' as GdipSetAdjustableArrowCapWidth:dword
    extrn '__imp__GdipSetClipGraphics@12' as GdipSetClipGraphics:dword
    extrn '__imp__GdipSetClipHrgn@12' as GdipSetClipHrgn:dword
    extrn '__imp__GdipSetClipPath@12' as GdipSetClipPath:dword
    extrn '__imp__GdipSetClipRect@24' as GdipSetClipRect:dword
    extrn '__imp__GdipSetClipRectI@24' as GdipSetClipRectI:dword
    extrn '__imp__GdipSetClipRegion@12' as GdipSetClipRegion:dword
    extrn '__imp__GdipSetCompositingMode@8' as GdipSetCompositingMode:dword
    extrn '__imp__GdipSetCompositingQuality@8' as GdipSetCompositingQuality:dword
    extrn '__imp__GdipSetCustomLineCapBaseCap@8' as GdipSetCustomLineCapBaseCap:dword
    extrn '__imp__GdipSetCustomLineCapBaseInset@8' as GdipSetCustomLineCapBaseInset:dword
    extrn '__imp__GdipSetCustomLineCapStrokeCaps@12' as GdipSetCustomLineCapStrokeCaps:dword
    extrn '__imp__GdipSetCustomLineCapStrokeJoin@8' as GdipSetCustomLineCapStrokeJoin:dword
    extrn '__imp__GdipSetCustomLineCapWidthScale@8' as GdipSetCustomLineCapWidthScale:dword
    extrn '__imp__GdipSetEffectParameters@12' as GdipSetEffectParameters:dword
    extrn '__imp__GdipSetEmpty@4' as GdipSetEmpty:dword
    extrn '__imp__GdipSetGraphicsLayout@8' as GdipSetGraphicsLayout:dword
    extrn '__imp__GdipSetImageAttributesCachedBackground@8' as GdipSetImageAttributesCachedBackground:dword
    extrn '__imp__GdipSetImageAttributesColorKeys@20' as GdipSetImageAttributesColorKeys:dword
    extrn '__imp__GdipSetImageAttributesColorMatrix@24' as GdipSetImageAttributesColorMatrix:dword
    extrn '__imp__GdipSetImageAttributesGamma@16' as GdipSetImageAttributesGamma:dword
    extrn '__imp__GdipSetImageAttributesNoOp@12' as GdipSetImageAttributesNoOp:dword
    extrn '__imp__GdipSetImageAttributesOutputChannel@16' as GdipSetImageAttributesOutputChannel:dword
    extrn '__imp__GdipSetImageAttributesOutputChannelColorProfile@16' as GdipSetImageAttributesOutputChannelColorProfile:dword
    extrn '__imp__GdipSetImageAttributesRemapTable@20' as GdipSetImageAttributesRemapTable:dword
    extrn '__imp__GdipSetImageAttributesThreshold@16' as GdipSetImageAttributesThreshold:dword
    extrn '__imp__GdipSetImageAttributesToIdentity@8' as GdipSetImageAttributesToIdentity:dword
    extrn '__imp__GdipSetImageAttributesWrapMode@16' as GdipSetImageAttributesWrapMode:dword
    extrn '__imp__GdipSetImageLayout@8' as GdipSetImageLayout:dword
    extrn '__imp__GdipSetImagePalette@8' as GdipSetImagePalette:dword
    extrn '__imp__GdipSetInfinite@4' as GdipSetInfinite:dword
    extrn '__imp__GdipSetInterpolationMode@8' as GdipSetInterpolationMode:dword
    extrn '__imp__GdipSetLineBlend@16' as GdipSetLineBlend:dword
    extrn '__imp__GdipSetLineColors@12' as GdipSetLineColors:dword
    extrn '__imp__GdipSetLineGammaCorrection@8' as GdipSetLineGammaCorrection:dword
    extrn '__imp__GdipSetLineLinearBlend@12' as GdipSetLineLinearBlend:dword
    extrn '__imp__GdipSetLinePoints@12' as GdipSetLinePoints:dword
    extrn '__imp__GdipSetLinePointsI@12' as GdipSetLinePointsI:dword
    extrn '__imp__GdipSetLinePresetBlend@16' as GdipSetLinePresetBlend:dword
    extrn '__imp__GdipSetLineSigmaBlend@12' as GdipSetLineSigmaBlend:dword
    extrn '__imp__GdipSetLineTransform@8' as GdipSetLineTransform:dword
    extrn '__imp__GdipSetLineWrapMode@8' as GdipSetLineWrapMode:dword
    extrn '__imp__GdipSetMatrixElements@28' as GdipSetMatrixElements:dword
    extrn '__imp__GdipSetMetafileDownLevelRasterizationLimit@8' as GdipSetMetafileDownLevelRasterizationLimit:dword
    extrn '__imp__GdipSetPageScale@8' as GdipSetPageScale:dword
    extrn '__imp__GdipSetPageUnit@8' as GdipSetPageUnit:dword
    extrn '__imp__GdipSetPathFillMode@8' as GdipSetPathFillMode:dword
    extrn '__imp__GdipSetPathGradientBlend@16' as GdipSetPathGradientBlend:dword
    extrn '__imp__GdipSetPathGradientCenterColor@8' as GdipSetPathGradientCenterColor:dword
    extrn '__imp__GdipSetPathGradientCenterPoint@8' as GdipSetPathGradientCenterPoint:dword
    extrn '__imp__GdipSetPathGradientCenterPointI@8' as GdipSetPathGradientCenterPointI:dword
    extrn '__imp__GdipSetPathGradientFocusScales@12' as GdipSetPathGradientFocusScales:dword
    extrn '__imp__GdipSetPathGradientGammaCorrection@8' as GdipSetPathGradientGammaCorrection:dword
    extrn '__imp__GdipSetPathGradientLinearBlend@12' as GdipSetPathGradientLinearBlend:dword
    extrn '__imp__GdipSetPathGradientPath@8' as GdipSetPathGradientPath:dword
    extrn '__imp__GdipSetPathGradientPresetBlend@16' as GdipSetPathGradientPresetBlend:dword
    extrn '__imp__GdipSetPathGradientSigmaBlend@12' as GdipSetPathGradientSigmaBlend:dword
    extrn '__imp__GdipSetPathGradientSurroundColorsWithCount@12' as GdipSetPathGradientSurroundColorsWithCount:dword
    extrn '__imp__GdipSetPathGradientTransform@8' as GdipSetPathGradientTransform:dword
    extrn '__imp__GdipSetPathGradientWrapMode@8' as GdipSetPathGradientWrapMode:dword
    extrn '__imp__GdipSetPathMarker@4' as GdipSetPathMarker:dword
    extrn '__imp__GdipSetPenBrushFill@8' as GdipSetPenBrushFill:dword
    extrn '__imp__GdipSetPenColor@8' as GdipSetPenColor:dword
    extrn '__imp__GdipSetPenCompoundArray@12' as GdipSetPenCompoundArray:dword
    extrn '__imp__GdipSetPenCustomEndCap@8' as GdipSetPenCustomEndCap:dword
    extrn '__imp__GdipSetPenCustomStartCap@8' as GdipSetPenCustomStartCap:dword
    extrn '__imp__GdipSetPenDashArray@12' as GdipSetPenDashArray:dword
    extrn '__imp__GdipSetPenDashCap197819@8' as GdipSetPenDashCap197819:dword
    extrn '__imp__GdipSetPenDashOffset@8' as GdipSetPenDashOffset:dword
    extrn '__imp__GdipSetPenDashStyle@8' as GdipSetPenDashStyle:dword
    extrn '__imp__GdipSetPenEndCap@8' as GdipSetPenEndCap:dword
    extrn '__imp__GdipSetPenLineCap197819@16' as GdipSetPenLineCap197819:dword
    extrn '__imp__GdipSetPenLineJoin@8' as GdipSetPenLineJoin:dword
    extrn '__imp__GdipSetPenMiterLimit@8' as GdipSetPenMiterLimit:dword
    extrn '__imp__GdipSetPenMode@8' as GdipSetPenMode:dword
    extrn '__imp__GdipSetPenStartCap@8' as GdipSetPenStartCap:dword
    extrn '__imp__GdipSetPenTransform@8' as GdipSetPenTransform:dword
    extrn '__imp__GdipSetPenUnit@8' as GdipSetPenUnit:dword
    extrn '__imp__GdipSetPenWidth@8' as GdipSetPenWidth:dword
    extrn '__imp__GdipSetPixelOffsetMode@8' as GdipSetPixelOffsetMode:dword
    extrn '__imp__GdipSetPropertyItem@8' as GdipSetPropertyItem:dword
    extrn '__imp__GdipSetRenderingOrigin@12' as GdipSetRenderingOrigin:dword
    extrn '__imp__GdipSetSmoothingMode@8' as GdipSetSmoothingMode:dword
    extrn '__imp__GdipSetSolidFillColor@8' as GdipSetSolidFillColor:dword
    extrn '__imp__GdipSetStringFormatAlign@8' as GdipSetStringFormatAlign:dword
    extrn '__imp__GdipSetStringFormatDigitSubstitution@12' as GdipSetStringFormatDigitSubstitution:dword
    extrn '__imp__GdipSetStringFormatFlags@8' as GdipSetStringFormatFlags:dword
    extrn '__imp__GdipSetStringFormatHotkeyPrefix@8' as GdipSetStringFormatHotkeyPrefix:dword
    extrn '__imp__GdipSetStringFormatLineAlign@8' as GdipSetStringFormatLineAlign:dword
    extrn '__imp__GdipSetStringFormatMeasurableCharacterRanges@12' as GdipSetStringFormatMeasurableCharacterRanges:dword
    extrn '__imp__GdipSetStringFormatTabStops@16' as GdipSetStringFormatTabStops:dword
    extrn '__imp__GdipSetStringFormatTrimming@8' as GdipSetStringFormatTrimming:dword
    extrn '__imp__GdipSetTextContrast@8' as GdipSetTextContrast:dword
    extrn '__imp__GdipSetTextRenderingHint@8' as GdipSetTextRenderingHint:dword
    extrn '__imp__GdipSetTextureTransform@8' as GdipSetTextureTransform:dword
    extrn '__imp__GdipSetTextureWrapMode@8' as GdipSetTextureWrapMode:dword
    extrn '__imp__GdipSetWorldTransform@8' as GdipSetWorldTransform:dword
    extrn '__imp__GdipShearMatrix@16' as GdipShearMatrix:dword
    extrn '__imp__GdipStartPathFigure@4' as GdipStartPathFigure:dword
    extrn '__imp__GdipStringFormatGetGenericDefault@4' as GdipStringFormatGetGenericDefault:dword
    extrn '__imp__GdipStringFormatGetGenericTypographic@4' as GdipStringFormatGetGenericTypographic:dword
    extrn '__imp__GdipTestControl@8' as GdipTestControl:dword
    extrn '__imp__GdipTransformMatrixPoints@12' as GdipTransformMatrixPoints:dword
    extrn '__imp__GdipTransformMatrixPointsI@12' as GdipTransformMatrixPointsI:dword
    extrn '__imp__GdipTransformPath@8' as GdipTransformPath:dword
    extrn '__imp__GdipTransformPoints@20' as GdipTransformPoints:dword
    extrn '__imp__GdipTransformPointsI@20' as GdipTransformPointsI:dword
    extrn '__imp__GdipTransformRegion@8' as GdipTransformRegion:dword
    extrn '__imp__GdipTranslateClip@12' as GdipTranslateClip:dword
    extrn '__imp__GdipTranslateClipI@12' as GdipTranslateClipI:dword
    extrn '__imp__GdipTranslateLineTransform@16' as GdipTranslateLineTransform:dword
    extrn '__imp__GdipTranslateMatrix@16' as GdipTranslateMatrix:dword
    extrn '__imp__GdipTranslatePathGradientTransform@16' as GdipTranslatePathGradientTransform:dword
    extrn '__imp__GdipTranslatePenTransform@16' as GdipTranslatePenTransform:dword
    extrn '__imp__GdipTranslateRegion@12' as GdipTranslateRegion:dword
    extrn '__imp__GdipTranslateRegionI@12' as GdipTranslateRegionI:dword
    extrn '__imp__GdipTranslateTextureTransform@16' as GdipTranslateTextureTransform:dword
    extrn '__imp__GdipTranslateWorldTransform@16' as GdipTranslateWorldTransform:dword
    extrn '__imp__GdipVectorTransformMatrixPoints@12' as GdipVectorTransformMatrixPoints:dword
    extrn '__imp__GdipVectorTransformMatrixPointsI@12' as GdipVectorTransformMatrixPointsI:dword
    extrn '__imp__GdipWarpPath@40' as GdipWarpPath:dword
    extrn '__imp__GdipWidenPath@16' as GdipWidenPath:dword
    extrn '__imp__GdipWindingModeOutline@12' as GdipWindingModeOutline:dword
end if

api LOGFONT,\
    GdipCreateFontFromLogfont,\
    GdipGetLogFont

;======================= Undocumented functions (unknown arguments) =======================;
;if defined APP_WIN64
;    extrn '__imp_GdipPlayTSClientRecord' as GdipPlayTSClientRecord:qword
;else
;    extrn '__imp__GdipPlayTSClientRecord@??' as GdipPlayTSClientRecord:dword
;end if

end if ;GDIPLUS_INC
