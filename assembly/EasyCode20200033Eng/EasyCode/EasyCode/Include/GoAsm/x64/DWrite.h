;======================================================;
;                                                      ;
;  DWrite.inc for Easy Code 2.0 64-bit GoAsm projects  ;
;                   (version 1.0.0)                    ;
;                                                      ;
;          Copyright © Héctor A. Medina - 2020         ;
;                                                      ;
;======================================================;

#ifndef DWRITE_H
#define DWRITE_H 1

#define DWRITE_MEASURING_MODE                           		DD
#define DWRITE_MEASURING_MODE_NATURAL                   		0
#define DWRITE_MEASURING_MODE_GDI_CLASSIC               		1
#define DWRITE_MEASURING_MODE_GDI_NATURAL               		2

;DWRITE_FONT_FILE_TYPE enumeration
#define DWRITE_FONT_FILE_TYPE_UNKNOWN                   		0
#define DWRITE_FONT_FILE_TYPE_CFF                       		1
#define DWRITE_FONT_FILE_TYPE_TRUETYPE                  		2
#define DWRITE_FONT_FILE_TYPE_TRUETYPE_COLLECTION       		3
#define DWRITE_FONT_FILE_TYPE_TYPE1_PFM                 		4
#define DWRITE_FONT_FILE_TYPE_TYPE1_PFB                 		5
#define DWRITE_FONT_FILE_TYPE_VECTOR                    		6
#define DWRITE_FONT_FILE_TYPE_BITMAP                    		7

#define 
;DWRITE_FONT_FACE_TYPE enumeration
#define DWRITE_FONT_FACE_TYPE_CFF                       		0
#define DWRITE_FONT_FACE_TYPE_TRUETYPE                  		1
#define DWRITE_FONT_FACE_TYPE_TRUETYPE_COLLECTION       		2
#define DWRITE_FONT_FACE_TYPE_TYPE1                     		3
#define DWRITE_FONT_FACE_TYPE_VECTOR                    		4
#define DWRITE_FONT_FACE_TYPE_BITMAP                    		5
#define DWRITE_FONT_FACE_TYPE_UNKNOWN                   		6

;DWRITE_FONT_SIMULATIONS enumeration
#define DWRITE_FONT_SIMULATIONS_NONE                    		0
#define DWRITE_FONT_SIMULATIONS_BOLD                    		1
#define DWRITE_FONT_SIMULATIONS_OBLIQUE                 		2

;DWRITE_FONT_WEIGHT enumeration
#define DWRITE_FONT_WEIGHT_THIN                         		100
#define DWRITE_FONT_WEIGHT_EXTRA_LIGHT                  		200
#define DWRITE_FONT_WEIGHT_ULTRA_LIGHT                  		200
#define DWRITE_FONT_WEIGHT_LIGHT                        		300
#define DWRITE_FONT_WEIGHT_SEMI_LIGHT                           350
#define DWRITE_FONT_WEIGHT_NORMAL                       		400
#define DWRITE_FONT_WEIGHT_REGULAR                      		400
#define DWRITE_FONT_WEIGHT_MEDIUM                       		500
#define DWRITE_FONT_WEIGHT_DEMI_BOLD                    		600
#define DWRITE_FONT_WEIGHT_SEMI_BOLD                    		600
#define DWRITE_FONT_WEIGHT_BOLD                         		700
#define DWRITE_FONT_WEIGHT_EXTRA_BOLD                   		800
#define DWRITE_FONT_WEIGHT_ULTRA_BOLD                   		800
#define DWRITE_FONT_WEIGHT_BLACK                        		900
#define DWRITE_FONT_WEIGHT_HEAVY                        		900
#define DWRITE_FONT_WEIGHT_EXTRA_BLACK                  		950
#define DWRITE_FONT_WEIGHT_ULTRA_BLACK                  		950

;DWRITE_FONT_STRETCH enumeration
#define DWRITE_FONT_STRETCH_UNDEFINED                   		0
#define DWRITE_FONT_STRETCH_ULTRA_CONDENSED             		1
#define DWRITE_FONT_STRETCH_EXTRA_CONDENSED             		2
#define DWRITE_FONT_STRETCH_CONDENSED                   		3
#define DWRITE_FONT_STRETCH_SEMI_CONDENSED              		4
#define DWRITE_FONT_STRETCH_NORMAL                      		5
#define DWRITE_FONT_STRETCH_MEDIUM                      		5
#define DWRITE_FONT_STRETCH_SEMI_EXPANDED               		6
#define DWRITE_FONT_STRETCH_EXPANDED                    		7
#define DWRITE_FONT_STRETCH_EXTRA_EXPANDED              		8
#define DWRITE_FONT_STRETCH_ULTRA_EXPANDED              		9

;DWRITE_FONT_STYLE enumeration
#define DWRITE_FONT_STYLE_NORMAL                        		0
#define DWRITE_FONT_STYLE_OBLIQUE                       		1
#define DWRITE_FONT_STYLE_ITALIC                        		2

;DWRITE_INFORMATIONAL_STRING_ID enumeration
#define DWRITE_INFORMATIONAL_STRING_NONE                		0
#define DWRITE_INFORMATIONAL_STRING_COPYRIGHT_NOTICE    		1
#define DWRITE_INFORMATIONAL_STRING_VERSION_STRINGS     		2
#define DWRITE_INFORMATIONAL_STRING_TRADEMARK           		3
#define DWRITE_INFORMATIONAL_STRING_MANUFACTURER        		4
#define DWRITE_INFORMATIONAL_STRING_DESIGNER            		5
#define DWRITE_INFORMATIONAL_STRING_DESIGNER_URL        		6
#define DWRITE_INFORMATIONAL_STRING_DESCRIPTION         		7
#define DWRITE_INFORMATIONAL_STRING_FONT_VENDOR_URL     		8
#define DWRITE_INFORMATIONAL_STRING_LICENSE_DESCRIPTION 		9
#define DWRITE_INFORMATIONAL_STRING_LICENSE_INFO_URL    		10
#define DWRITE_INFORMATIONAL_STRING_WIN32_FAMILY_NAMES  		11
#define DWRITE_INFORMATIONAL_STRING_WIN32_SUBFAMILY_NAMES 		12
#define DWRITE_INFORMATIONAL_STRING_PREFERRED_FAMILY_NAMES 		13
#define DWRITE_INFORMATIONAL_STRING_PREFERRED_SUBFAMILY_NAMES 	14
#define DWRITE_INFORMATIONAL_STRING_SAMPLE_TEXT         		15
#define DWRITE_INFORMATIONAL_STRING_FULL_NAME           		16
#define DWRITE_INFORMATIONAL_STRING_POSTSCRIPT_NAME     		17
#define DWRITE_INFORMATIONAL_STRING_POSTSCRIPT_CID_NAME 		18

;DWRITE_FACTORY_TYPE enumeration
#define DWRITE_FACTORY_TYPE_SHARED                      		0
#define DWRITE_FACTORY_TYPE_ISOLATED                    		1

;DWRITE_PIXEL_GEOMETRY enumeration
#define DWRITE_PIXEL_GEOMETRY_FLAT                      		0
#define DWRITE_PIXEL_GEOMETRY_RGB                       		1
#define DWRITE_PIXEL_GEOMETRY_BGR                       		2

;DWRITE_RENDERING_MODE enumeration
#define DWRITE_RENDERING_MODE_DEFAULT                   		0
#define DWRITE_RENDERING_MODE_ALIASED                   		1
#define DWRITE_RENDERING_MODE_GDI_CLASSIC               		2
#define DWRITE_RENDERING_MODE_GDI_NATURAL               		3
#define DWRITE_RENDERING_MODE_NATURAL                   		4
#define DWRITE_RENDERING_MODE_NATURAL_SYMMETRIC         		5
#define DWRITE_RENDERING_MODE_OUTLINE                   		6
#define DWRITE_RENDERING_MODE_CLEARTYPE_GDI_CLASSIC     		DWRITE_RENDERING_MODE_GDI_CLASSIC
#define DWRITE_RENDERING_MODE_CLEARTYPE_GDI_NATURAL     		DWRITE_RENDERING_MODE_GDI_NATURAL
#define DWRITE_RENDERING_MODE_CLEARTYPE_NATURAL         		DWRITE_RENDERING_MODE_NATURAL
#define DWRITE_RENDERING_MODE_CLEARTYPE_NATURAL_SYMMETRIC 		DWRITE_RENDERING_MODE_NATURAL_SYMMETRIC

;DWRITE_READING_DIRECTION enumeration
#define DWRITE_READING_DIRECTION_LEFT_TO_RIGHT          		0
#define DWRITE_READING_DIRECTION_RIGHT_TO_LEFT          		1

;DWRITE_FLOW_DIRECTION enumeration
#define DWRITE_FLOW_DIRECTION_TOP_TO_BOTTOM             		0

;DWRITE_TEXT_ALIGNMENT enumeration
#define DWRITE_TEXT_ALIGNMENT_LEADING                   		0
#define DWRITE_TEXT_ALIGNMENT_TRAILING                  		1
#define DWRITE_TEXT_ALIGNMENT_CENTER                    		2

;DWRITE_PARAGRAPH_ALIGNMENT enumeration
#define DWRITE_PARAGRAPH_ALIGNMENT_NEAR                 		0
#define DWRITE_PARAGRAPH_ALIGNMENT_FAR                  		1
#define DWRITE_PARAGRAPH_ALIGNMENT_CENTER               		2

;DWRITE_WORD_WRAPPING enumeration
#define DWRITE_WORD_WRAPPING_WRAP                       		0
#define DWRITE_WORD_WRAPPING_NO_WRAP                    		1

;DWRITE_LINE_SPACING_METHOD enumeration
#define DWRITE_LINE_SPACING_METHOD_DEFAULT              		0
#define DWRITE_LINE_SPACING_METHOD_UNIFORM              		1

;DWRITE_TRIMMING_GRANULARITY enumeration
#define DWRITE_TRIMMING_GRANULARITY_NONE                		0
#define DWRITE_TRIMMING_GRANULARITY_CHARACTER           		1
#define DWRITE_TRIMMING_GRANULARITY_WORD                		2

;DWRITE_FONT_FEATURE_TAG enumeration
#define DWRITE_FONT_FEATURE_TAG_ALTERNATIVE_FRACTIONS   		0x063726661 ;'afrc'
#define DWRITE_FONT_FEATURE_TAG_PETITE_CAPITALS_FROM_CAPITALS	0x063703263 ;'c2pc'
#define DWRITE_FONT_FEATURE_TAG_SMALL_CAPITALS_FROM_CAPITALS  	0x063733263 ;'c2sc'
#define DWRITE_FONT_FEATURE_TAG_CONTEXTUAL_ALTERNATES         	0x0746C6163 ;'calt'
#define DWRITE_FONT_FEATURE_TAG_CASE_SENSITIVE_FORMS          	0x065736163 ;'case'
#define DWRITE_FONT_FEATURE_TAG_GLYPH_COMPOSITION_DECOMPOSITION 0x0706D6363 ;'ccmp'
#define DWRITE_FONT_FEATURE_TAG_CONTEXTUAL_LIGATURES    		0x067696C63 ;'clig'
#define DWRITE_FONT_FEATURE_TAG_CAPITAL_SPACING         		0x070737063 ;'cpsp'
#define DWRITE_FONT_FEATURE_TAG_CONTEXTUAL_SWASH        		0x068777363 ;'cswh'
#define DWRITE_FONT_FEATURE_TAG_CURSIVE_POSITIONING     		0x073727563 ;'curs'
#define DWRITE_FONT_FEATURE_TAG_DEFAULT                 		0x0746c6664 ;'dflt'
#define DWRITE_FONT_FEATURE_TAG_DISCRETIONARY_LIGATURES 		0x067696c64 ;'dlig'
#define DWRITE_FONT_FEATURE_TAG_EXPERT_FORMS            		0x074707865 ;'expt'
#define DWRITE_FONT_FEATURE_TAG_FRACTIONS               		0x063617266 ;'frac'
#define DWRITE_FONT_FEATURE_TAG_FULL_WIDTH              		0x064697766 ;'fwid'
#define DWRITE_FONT_FEATURE_TAG_HALF_FORMS              		0x0666C6168 ;'half'
#define DWRITE_FONT_FEATURE_TAG_HALANT_FORMS            		0x06e6c6168 ;'haln'
#define DWRITE_FONT_FEATURE_TAG_ALTERNATE_HALF_WIDTH    		0x0746c6168 ;'halt'
#define DWRITE_FONT_FEATURE_TAG_HISTORICAL_FORMS        		0x074736968 ;'hist'
#define DWRITE_FONT_FEATURE_TAG_HORIZONTAL_KANA_ALTERNATES 		0x0616e6b68 ;'hkna'
#define DWRITE_FONT_FEATURE_TAG_HISTORICAL_LIGATURES    		0x067696c68 ;'hlig'
#define DWRITE_FONT_FEATURE_TAG_HALF_WIDTH              		0x064697768 ;'hwid'
#define DWRITE_FONT_FEATURE_TAG_HOJO_KANJI_FORMS        		0x06f6a6f68 ;'hojo'
#define DWRITE_FONT_FEATURE_TAG_JIS04_FORMS             		0x03430706a ;'jp04'
#define DWRITE_FONT_FEATURE_TAG_JIS78_FORMS             		0x03837706a ;'jp78'
#define DWRITE_FONT_FEATURE_TAG_JIS83_FORMS             		0x03338706a ;'jp83'
#define DWRITE_FONT_FEATURE_TAG_JIS90_FORMS             		0x03039706a ;'jp90'
#define DWRITE_FONT_FEATURE_TAG_KERNING                 		0x06e72656b ;'kern'
#define DWRITE_FONT_FEATURE_TAG_STANDARD_LIGATURES      		0x06167696c ;'liga'
#define DWRITE_FONT_FEATURE_TAG_LINING_FIGURES          		0x06d756e6c ;'lnum'
#define DWRITE_FONT_FEATURE_TAG_LOCALIZED_FORMS         		0x06c636f6c ;'locl'
#define DWRITE_FONT_FEATURE_TAG_MARK_POSITIONING        		0x06b72616d ;'mark'
#define DWRITE_FONT_FEATURE_TAG_MATHEMATICAL_GREEK      		0x06b72676d ;'mgrk'
#define DWRITE_FONT_FEATURE_TAG_MARK_TO_MARK_POSITIONING 		0x06b6d6b6d ;'mkmk'
#define DWRITE_FONT_FEATURE_TAG_ALTERNATE_ANNOTATION_FORMS    	0x0746c616e ;'nalt'
#define DWRITE_FONT_FEATURE_TAG_NLC_KANJI_FORMS               	0x06b636c6e ;'nlck'
#define DWRITE_FONT_FEATURE_TAG_OLD_STYLE_FIGURES             	0x06d756e6f ;'onum'
#define DWRITE_FONT_FEATURE_TAG_ORDINALS                      	0x06e64726f ;'ordn'
#define DWRITE_FONT_FEATURE_TAG_PROPORTIONAL_ALTERNATE_WIDTH  	0x0746c6170 ;'palt'
#define DWRITE_FONT_FEATURE_TAG_PETITE_CAPITALS               	0x070616370 ;'pcap'
#define DWRITE_FONT_FEATURE_TAG_PROPORTIONAL_FIGURES          	0x06d756e70 ;'pnum'
#define DWRITE_FONT_FEATURE_TAG_PROPORTIONAL_WIDTHS           	0x064697770 ;'pwid'
#define DWRITE_FONT_FEATURE_TAG_QUARTER_WIDTHS                	0x064697771 ;'qwid'
#define DWRITE_FONT_FEATURE_TAG_REQUIRED_LIGATURES            	0x067696c72 ;'rlig'
#define DWRITE_FONT_FEATURE_TAG_RUBY_NOTATION_FORMS           	0x079627572 ;'ruby'
#define DWRITE_FONT_FEATURE_TAG_STYLISTIC_ALTERNATES          	0x0746c6173 ;'salt'
#define DWRITE_FONT_FEATURE_TAG_SCIENTIFIC_INFERIORS          	0x0666e6973 ;'sinf'
#define DWRITE_FONT_FEATURE_TAG_SMALL_CAPITALS                	0x070636d73 ;'smcp'
#define DWRITE_FONT_FEATURE_TAG_SIMPLIFIED_FORMS              	0x06c706d73 ;'smpl'
#define DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_1               	0x031307373 ;'ss01'
#define DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_2               	0x032307373 ;'ss02'
#define DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_3               	0x033307373 ;'ss03'
#define DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_4               	0x034307373 ;'ss04'
#define DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_5               	0x035307373 ;'ss05'
#define DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_6               	0x036307373 ;'ss06'
#define DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_7               	0x037307373 ;'ss07'
#define DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_8               	0x038307373 ;'ss08'
#define DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_9               	0x039307373 ;'ss09'
#define DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_10              	0x030317373 ;'ss10'
#define DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_11              	0x031317373 ;'ss11'
#define DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_12              	0x032317373 ;'ss12'
#define DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_13              	0x033317373 ;'ss13'
#define DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_14              	0x034317373 ;'ss14'
#define DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_15              	0x035317373 ;'ss15'
#define DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_16              	0x036317373 ;'ss16'
#define DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_17              	0x037317373 ;'ss17'
#define DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_18              	0x038317373 ;'ss18'
#define DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_19              	0x039317373 ;'ss19'
#define DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_20              	0x030327373 ;'ss20'
#define DWRITE_FONT_FEATURE_TAG_SUBSCRIPT                     	0x073627573 ;'subs'
#define DWRITE_FONT_FEATURE_TAG_SUPERSCRIPT                   	0x073707573 ;'sups'
#define DWRITE_FONT_FEATURE_TAG_SWASH                         	0x068737773 ;'swsh'
#define DWRITE_FONT_FEATURE_TAG_TITLING                       	0x06c746974 ;'titl'
#define DWRITE_FONT_FEATURE_TAG_TRADITIONAL_NAME_FORMS        	0x06D616E74 ;'tnam'
#define DWRITE_FONT_FEATURE_TAG_TABULAR_FIGURES               	0x06D756E74 ;'tnum'
#define DWRITE_FONT_FEATURE_TAG_TRADITIONAL_FORMS             	0x064617274 ;'trad'
#define DWRITE_FONT_FEATURE_TAG_THIRD_WIDTHS                  	0x064697774 ;'twid'
#define DWRITE_FONT_FEATURE_TAG_UNICASE                       	0x063696E75 ;'unic'
#define DWRITE_FONT_FEATURE_TAG_SLASHED_ZERO                  	0x06F72657A ;'zero'

;DWRITE_SCRIPT_SHAPES enumeration
#define DWRITE_SCRIPT_SHAPES_DEFAULT                          	0
#define DWRITE_SCRIPT_SHAPES_NO_VISUAL                        	1

;DWRITE_BREAK_CONDITION enumeration
#define DWRITE_BREAK_CONDITION_NEUTRAL                        	0
#define DWRITE_BREAK_CONDITION_CAN_BREAK                      	1
#define DWRITE_BREAK_CONDITION_MAY_NOT_BREAK                  	2
#define DWRITE_BREAK_CONDITION_MUST_BREAK                     	3

;DWRITE_NUMBER_SUBSTITUTION_METHOD enumeration
#define DWRITE_NUMBER_SUBSTITUTION_METHOD_FROM_CULTURE        	0
#define DWRITE_NUMBER_SUBSTITUTION_METHOD_CONTEXTUAL          	1
#define DWRITE_NUMBER_SUBSTITUTION_METHOD_NONE                	2
#define DWRITE_NUMBER_SUBSTITUTION_METHOD_NATIONAL            	3
#define DWRITE_NUMBER_SUBSTITUTION_METHOD_TRADITIONAL         	4

;DWRITE_TEXTURE_TYPE enumeration
#define DWRITE_TEXTURE_ALIASED_1x1                            	0
#define DWRITE_TEXTURE_CLEARTYPE_3x1                          	1

;======================================== Structures ======================================;
DWRITE_FONT_METRICS STRUCT
    designUnitsPerEm       DW
    ascent                 DW
    descent                DW
    lineGap                DW
    capHeight              DW
    xHeight                DW
    underlinePosition      DW
    underlineThickness     DW
    strikethroughPosition  DW
    strikethroughThickness DW
ENDS

DWRITE_GLYPH_METRICS STRUCT
    leftSideBearing   DD
    advanceWidth      DD
    rightSideBearing  DD
    topSideBearing    DD
    advanceHeight     DD
    bottomSideBearing DD
    verticalOriginY   DD
ENDS

DWRITE_GLYPH_OFFSET STRUCT
    advanceOffset  DD
    ascenderOffset DD
ENDS

DWRITE_MATRIX STRUCT
    m11 DD
    m12 DD
    m21 DD
    m22 DD
    dx_ DD
    dy  DD
ENDS

DWRITE_TEXT_RANGE STRUCT
    startPosition DD
    length_       DD
ENDS

DWRITE_FONT_FEATURE STRUCT
    nameTag   DD ;DWRITE_FONT_FEATURE_TAG
    parameter DD
ENDS

DWRITE_TYPOGRAPHIC_FEATURES STRUCT
    features      PTR 
    featureCount_ DD  
ENDS

DWRITE_TRIMMING STRUCT
    granularity     DD ;DWRITE_TRIMMING_GRANULARITY
    delimiter_      DD
    delimiterCount_ DD
ENDS

DWRITE_SCRIPT_ANALYSIS STRUCT
    script DW
    shapes DD ;DWRITE_SCRIPT_SHAPES
ENDS

DWRITE_LINE_BREAKPOINT STRUCT
      breakConditionBefore DB ;:2
      breakConditionAfter  DB ;:2
      isWhitespace         DB ;:1
      isSoftHyphen         DB ;:1
      padding              DB ;:2
ENDS

DWRITE_SHAPING_TEXT_PROPERTIES STRUCT
      isShapedAlone DW ;:1
      reserved      DW ;:15
ENDS

DWRITE_SHAPING_GLYPH_PROPERTIES STRUCT
      justification    DW ;:4
      isClusterStart   DW ;:1
      isDiacritic      DW ;:1
      isZeroWidthSpace DW ;:1
      reserved         DW ;:9
ENDS

DWRITE_GLYPH_RUN STRUCT
      fontFace      PTR  ;__notnull IDWriteFontFace *
      fontEmSize    DD  
      lyphCount     DD  
      glyphIndices  DW   ;__field_ecount(glyphCount) DW const *
      glyphAdvances DD   ;__field_ecount_opt(glyphCount) DD const *
      glyphOffsets  PTR  ;__field_ecount_opt(glyphCount) DWRITE_GLYPH_OFFSET const *
      isSideways    DD  
      bidiLevel     DD  
ENDS

DWRITE_GLYPH_RUN_DESCRIPTION STRUCT
      localeName   PTR ;__nullterminated WCHAR const *
      string       PTR ;__field_ecount(stringLength) WCHAR const *
      stringLength DD 
      clusterMap   DW  ;__field_ecount(stringLength) DW const *
      textPosition DD 
ENDS

DWRITE_UNDERLINE STRUCT
      width_           DD 
      thickness        DD 
      offset_          DD 
      runHeight        DD 
      readingDirection DD  ;DWRITE_READING_DIRECTION
      flowDirection    DD  ;DWRITE_FLOW_DIRECTION
      localeName       PTR ;__nullterminated WCHAR const *
      measuringMode    DD  ;DWRITE_MEASURING_MODE
ENDS

DWRITE_STRIKETHROUGH STRUCT
      width_           DD 
      thickness        DD 
      offset_          DD 
      readingDirection DD  ;DWRITE_READING_DIRECTION
      flowDirection    DD  ;DWRITE_FLOW_DIRECTION
      localeName       PTR ;__nullterminated WCHAR const *
      measuringMode    DD  ;DWRITE_MEASURING_MODE
ENDS

DWRITE_LINE_METRICS STRUCT
      length_                  DD
      trailingWhitespaceLength DD
      newlineLength            DD
      height                   DD
      baseline                 DD
      isTrimmed                DD
ENDS

DWRITE_CLUSTER_METRICS STRUCT
      width_           DD
      length_          DW
      canWrapLineAfter DW ;:1
      isWhitespace     DW ;:1
      isNewline        DW ;:1
      isSoftHyphen     DW ;:1
      isRightToLeft    DW ;:1
      padding          DW ;:11
ENDS

DWRITE_TEXT_METRICS STRUCT
      left                             DD
      top                              DD
      width_                           DD
      widthIncludingTrailingWhitespace DD
      height                           DD
      layoutWidth                      DD
      layoutHeight                     DD
      maxBidiReorderingDepth           DD
      lineCount                        DD
ENDS

DWRITE_INLINE_OBJECT_METRICS STRUCT
      width_           DD
      height           DD
      baseline         DD
      supportsSideways DD
ENDS

DWRITE_OVERHANG_METRICS STRUCT
      left   DD
      top    DD
      right  DD
      bottom DD
ENDS

DWRITE_HIT_TEST_METRICS STRUCT
      textPosition DD
      length_      DD
      left         DD
      top          DD
      width_       DD
      height       DD
      bidiLeve     DD
      isText       DD
      isTrimmed    DD
ENDS

IDWriteBitmapRenderTargetVtbl STRUCT
    QueryInterface      DQ
    AddRef              DQ
    Release             DQ
    DrawGlyphRun        DQ
    GetMemoryDC         DQ
    GetPixelsPerDip     DQ
    SetPixelsPerDip     DQ
    GetCurrentTransform DQ
    SetCurrentTransform DQ
    GetSize             DQ
    Resize              DQ

ENDS

IDWriteFactoryVtbl STRUCT
    QueryInterface                 DQ
    AddRef                         DQ
    Release                        DQ
    GetSystemFontCollection        DQ
    CreateCustomFontCollection     DQ
    RegisterFontCollectionLoader   DQ
    UnregisterFontCollectionLoader DQ
    CreateFontFileReference        DQ
    CreateCustomFontFileReference  DQ
    CreateFontFace                 DQ
    CreateRenderingParams          DQ
    CreateMonitorRenderingParams   DQ
    CreateCustomRenderingParams    DQ
    RegisterFontFileLoader         DQ
    UnregisterFontFileLoader       DQ
    CreateTextFormat               DQ
    CreateTypography               DQ
    GetGdiInterop                  DQ
    CreateTextLayout               DQ
    CreateGdiCompatibleTextLayout  DQ
    CreateEllipsisTrimmingSign     DQ
    CreateTextAnalyzer             DQ
    CreateNumberSubstitution       DQ
    CreateGlyphRunAnalysis         DQ
ENDS

IDWriteFontVtbl STRUCT
    QueryInterface          DQ
    AddRef                  DQ
    Release                 DQ
    GetFontFamily           DQ
    GetWeight               DQ
    GetStretch              DQ
    GetStyle                DQ
    IsSymbolFont            DQ
    GetFaceNames            DQ
    GetInformationalStrings DQ
    GetSimulations          DQ
    GetMetrics              DQ
    HasCharacter            DQ
    CreateFontFace          DQ
ENDS

IDWriteFontCollectionVtbl STRUCT
    QueryInterface      DQ
    AddRef              DQ
    Release             DQ
    GetFontFamilyCount  DQ
    GetFontFamily       DQ
    FindFamilyName      DQ
    GetFontFromFontFace DQ
ENDS

IDWriteFontFaceVtbl STRUCT
    QueryInterface               DQ
    AddRef                       DQ
    Release                      DQ
    GetType                      DQ
    GetFiles                     DQ
    GetIndex                     DQ
    GetSimulations               DQ
    IsSymbolFont                 DQ
    GetMetrics                   DQ
    GetGlyphCount                DQ
    GetDesignGlyphMetrics        DQ
    GetGlyphIndices              DQ
    TryGetFontTable              DQ
    ReleaseFontTable             DQ
    GetGlyphRunOutline           DQ
    GetRecommendedRenderingMode  DQ
    GetGdiCompatibleMetrics      DQ
    GetGdiCompatibleGlyphMetrics DQ
ENDS

IDWriteFontListVtbl STRUCT
    QueryInterface    DQ
    AddRef            DQ
    Release           DQ
    GetFontCollection DQ
    GetFontCount      DQ
    GetFont           DQ

ENDS

IDWriteFontFamilyVtbl STRUCT
    QueryInterface       DQ ;IDWriteFontListVtbl
    AddRef               DQ
    Release              DQ
    GetFontCollection    DQ
    GetFontCount         DQ
    GetFont              DQ
    GetFamilyNames       DQ
    GetFirstMatchingFont DQ
    GetMatchingFonts     DQ
ENDS

IDWriteFontFileVtbl STRUCT
    QueryInterface  DQ
    AddRef          DQ
    Release         DQ
    GetReferenceKey DQ
    GetLoader       DQ
    Analyze         DQ
ENDS

IDWriteFontFileLoaderVtbl STRUCT
    QueryInterface      DQ
    AddRef              DQ
    Release             DQ
    CreateStreamFromKey DQ
ENDS

IDWriteFontFileStreamVtbl STRUCT
    QueryInterface      DQ
    AddRef              DQ
    Release             DQ
    ReadFileFragment    DQ
    ReleaseFileFragment DQ
    GetFileSize         DQ
    GetLastWriteTime    DQ
ENDS

IDWriteFontCollectionLoaderVtbl STRUCT
    QueryInterface          DQ
    AddRef                  DQ
    Release                 DQ
    CreateEnumeratorFromKey DQ
ENDS

IDWriteFontFileEnumeratorVtbl STRUCT
    QueryInterface     DQ
    AddRef             DQ
    Release            DQ
    MoveNext           DQ
    GetCurrentFontFile DQ
ENDS

IDWriteGdiInteropVtbl STRUCT
    QueryInterface           DQ
    AddRef                   DQ
    Release                  DQ
    CreateFontFromLOGFONT    DQ
    ConvertFontToLOGFONT     DQ
    ConvertFontFaceToLOGFONT DQ
    CreateFontFaceFromHdc    DQ
    CreateBitmapRenderTarget DQ
ENDS

IDWriteGlyphRunAnalysisVtbl STRUCT
    QueryInterface        DQ
    AddRef                DQ
    Release               DQ
    GetAlphaTextureBounds DQ
    CreateAlphaTexture    DQ
    GetAlphaBlendParams   DQ
ENDS

IDWriteInlineObjectVtbl STRUCT
    QueryInterface     DQ
    AddRef             DQ
    Release            DQ
    Draw               DQ
    GetMetrics         DQ
    GetOverhangMetrics DQ
    GetBreakConditions DQ
ENDS

IDWriteLocalFontFileLoaderVtbl STRUCT  
    QueryInterface           DQ ;IDWriteFontFileLoaderVtbl
    AddRef                   DQ
    Release                  DQ
    CreateStreamFromKey      DQ
    GetFilePathLengthFromKey DQ
    GetFilePathFromKey       DQ
    GetLastWriteTimeFromKey  DQ
ENDS

IDWriteLocalizedStringsVtbl STRUCT
    QueryInterface      DQ
    AddRef              DQ
    Release             DQ
    GetCount            DQ
    FindLocaleName      DQ
    GetLocaleNameLength DQ
    GetLocaleName       DQ
    GetStringLength     DQ
    GetString           DQ
ENDS

IDWriteNumberSubstitutionVtbl STRUCT
    QueryInterface DQ
    AddRef         DQ
    Release        DQ
ENDS

IDWritePixelSnappingVtbl STRUCT
    QueryInterface          DQ
    AddRef                  DQ
    Release                 DQ
    IsPixelSnappingDisabled DQ
    GetCurrentTransform     DQ
    GetPixelsPerDip         DQ
ENDS

IDWriteRenderingParamsVtbl STRUCT
    QueryInterface      DQ
    AddRef              DQ
    Release             DQ
    GetGamma            DQ
    GetEnhancedContrast DQ
    GetClearTypeLevel   DQ
    GetPixelGeometry    DQ
    GetRenderingMode    DQ
ENDS

IDWriteTextAnalysisSinkVtbl STRUCT
    QueryInterface        DQ
    AddRef                DQ
    Release               DQ
    SetScriptAnalysis     DQ
    SetLineBreakpoints    DQ
    SetBidiLevel          DQ
    SetNumberSubstitution DQ
ENDS

IDWriteTextAnalysisSourceVtbl STRUCT
    QueryInterface               DQ
    AddRef                       DQ
    Release                      DQ
    GetTextAtPosition            DQ
    GetTextBeforePosition        DQ
    GetParagraphReadingDirection DQ
    GetLocaleName                DQ
    GetNumberSubstitution        DQ
ENDS

IDWriteTextAnalyzerVtbl STRUCT
    QueryInterface                  DQ
    AddRef                          DQ
    Release                         DQ
    AnalyzeScript                   DQ
    AnalyzeBidi                     DQ
    AnalyzeNumberSubstitution       DQ
    AnalyzeLineBreakpoints          DQ
    GetGlyphs                       DQ
    GetGlyphPlacements              DQ
    GetGdiCompatibleGlyphPlacements DQ
ENDS

IDWriteTextFormatVtbl STRUCT
    QueryInterface          DQ
    AddRef                  DQ
    Release                 DQ
    SetTextAlignment        DQ
    SetParagraphAlignment   DQ
    SetWordWrapping         DQ
    SetReadingDirection     DQ
    SetFlowDirection        DQ
    SetIncrementalTabStop   DQ
    SetTrimming             DQ
    SetLineSpacing          DQ
    GetTextAlignment        DQ
    GetParagraphAlignment   DQ
    GetWordWrapping         DQ
    GetReadingDirection     DQ
    GetFlowDirection        DQ
    GetIncrementalTabStop   DQ
    GetTrimming             DQ
    GetLineSpacing          DQ
    GetFontCollection       DQ
    GetFontFamilyNameLength DQ
    GetFontFamilyName       DQ
    GetFontWeight           DQ
    GetFontStyle            DQ
    GetFontStretch          DQ
    GetFontSize             DQ
    GetLocaleNameLength     DQ
    GetLocaleName           DQ
ENDS

IDWriteTextLayoutVtbl STRUCT
    QueryInterface           DQ ;IDWriteTextFormatVtbl
    AddRef                   DQ
    Release                  DQ
    SetTextAlignment         DQ
    SetParagraphAlignment    DQ
    SetWordWrapping          DQ
    SetReadingDirection      DQ
    SetFlowDirection         DQ
    SetIncrementalTabStop    DQ
    SetTrimming              DQ
    SetLineSpacing           DQ
    GetTextAlignment         DQ
    GetParagraphAlignment    DQ
    GetWordWrapping          DQ
    GetReadingDirection      DQ
    GetFlowDirection         DQ
    GetIncrementalTabStop    DQ
    GetTrimming              DQ
    GetLineSpacing           DQ
    GetFontCollection        DQ
    GetFontFamilyNameLength  DQ
    GetFontFamilyName        DQ
    GetFontWeight            DQ
    GetFontStyle             DQ
    GetFontStretch           DQ
    GetFontSize              DQ
    GetLocaleNameLength      DQ
    GetLocaleName            DQ
    SetMaxWidth              DQ
    SetMaxHeight             DQ
    SetFontCollection        DQ
    SetFontFamilyName        DQ
    SetFontWeight            DQ
    SetFontStyle             DQ
    SetFontStretch           DQ
    SetFontSize              DQ
    SetUnderline             DQ
    SetStrikethrough         DQ
    SetDrawingEffect         DQ
    SetInlineObject          DQ
    SetTypography            DQ
    SetLocaleName            DQ
    GetMaxWidth              DQ
    GetMaxHeight             DQ
    GetFontCollection_       DQ
    GetFontFamilyNameLength_ DQ
    GetFontFamilyName_       DQ
    GetFontWeight_           DQ
    GetFontStyle_            DQ
    GetFontStretch_          DQ
    GetFontSize_             DQ
    GetUnderline             DQ
    GetStrikethrough         DQ
    GetDrawingEffect         DQ
    GetInlineObject          DQ
    GetTypography            DQ
    GetLocaleNameLength_     DQ
    GetLocaleName_           DQ
    Draw                     DQ
    GetLineMetrics           DQ
    GetMetrics               DQ
    GetOverhangMetrics       DQ
    GetClusterMetrics        DQ
    DetermineMinWidth        DQ
    HitTestPoint             DQ
    HitTestTextPosition      DQ
    HitTestTextRange         DQ
ENDS

IDWriteTextRendererVtbl STRUCT
    QueryInterface          DQ ;IDWritePixelSnappingVtbl
    AddRef                  DQ
    Release                 DQ
    IsPixelSnappingDisabled DQ
    GetCurrentTransform     DQ
    GetPixelsPerDip         DQ
    DrawGlyphRun            DQ
    DrawUnderline           DQ
    DrawStrikethrough       DQ
    DrawInlineObject        DQ
ENDS

IDWriteTypographyVtbl STRUCT
    QueryInterface      DQ
    AddRef              DQ
    Release             DQ
    AddFontFeature      DQ
    GetFontFeatureCount DQ
    GetFontFeature      DQ
ENDS

;====================================== GUID values =======================================;
; ==== If any of them is nedeed it has to be in the '.Data' section of the source code ====;
;IDWriteFontFileLoader          GUID    <0727CAD4EH, 0D6AFH, 04C9EH, <08AH, 008H, 0D6H, 095H, 0B1H, 01CH, 0AAH, 049H>>
;IDWriteLocalFontFileLoader     GUID    <0B2D9F3ECH, 0C9FEH, 04A11H, <0A2H, 0ECH, 0D8H, 062H, 008H, 0F7H, 0C0H, 0A2H>>
;IDWriteFontFileStream          GUID    <06D4865FEH, 00AB8H, 04D91H, <08FH, 062H, 05DH, 0D6H, 0BEH, 034H, 0A3H, 0E0H>>
;IDWriteFontFile                GUID    <0739D886AH, 0CEF5H, 047DCH, <087H, 069H, 01AH, 08BH, 041H, 0BEH, 0BBH, 0B0H>>
;IDWriteRenderingParams         GUID    <02F0DA53AH, 02ADDH, 047CDH, <082H, 0EEH, 0D9H, 0ECH, 034H, 068H, 08EH, 075H>>
;IDWriteFontFace                GUID    <05F49804DH, 07024H, 04D43H, <0BFH, 0A9H, 0D2H, 059H, 084H, 0F5H, 038H, 049H>>
;IDWriteFontCollectionLoader    GUID    <0CCA920E4H, 052F0H, 0492BH, <0BFH, 0A8H, 029H, 0C7H, 02EH, 0E0H, 0A4H, 068H>>
;IDWriteFontFileEnumerator      GUID    <072755049H, 05FF7H, 0435DH, <083H, 048H, 04BH, 0E9H, 07CH, 0FAH, 06CH, 07CH>>
;IDWriteLocalizedStrings        GUID    <008256209H, 0099AH, 04B34H, <0B8H, 06DH, 0C2H, 02BH, 011H, 00EH, 077H, 071H>>
;IDWriteFontCollection          GUID    <0A84CEE02H, 03EEAH, 04EEEH, <0A8H, 027H, 087H, 0C1H, 0A0H, 02AH, 00FH, 0CCH>>
;IDWriteFontList                GUID    <01A0D8438H, 01D97H, 04EC1H, <0AEH, 0F9H, 0A2H, 0FBH, 086H, 0EDH, 06AH, 0CBH>>
;IDWriteFontFamily              GUID    <0DA20D8EFH, 0812AH, 04C43H, <098H, 002H, 062H, 0ECH, 04AH, 0BDH, 07AH, 0DDH>>
;IDWriteFont                    GUID    <0ACD16696H, 08C14H, 04F5DH, <087H, 07EH, 0FEH, 03FH, 0C1H, 0D3H, 027H, 037H>>
;IDWriteTextFormat              GUID    <09C906818H, 031D7H, 04FD3H, <0A1H, 051H, 07CH, 05EH, 022H, 05DH, 0B5H, 05AH>>
;IDWriteTypography              GUID    <055F1112BH, 01DC2H, 04B3CH, <095H, 041H, 0F4H, 068H, 094H, 0EDH, 085H, 0B6H>>
;IDWriteTextAnalyzer            GUID    <0B7E6163EH, 07F46H, 043B4H, <084H, 0B3H, 0E4H, 0E6H, 024H, 09CH, 036H, 05DH>>
;IDWriteInlineObject            GUID    <08339FDE3H, 0106FH, 047ABH, <083H, 073H, 01CH, 062H, 095H, 0EBH, 010H, 0B3H>>
;IDWritePixelSnapping           GUID    <0EAF3A2DAH, 0ECF4H, 04D24H, <0B6H, 044H, 0B3H, 04FH, 068H, 042H, 002H, 04BH>>
;IDWriteTextRenderer            GUID    <0EF8A8135H, 05CC6H, 045FEH, <088H, 025H, 0C5H, 0A0H, 072H, 04EH, 0B8H, 019H>>
;IDWriteTextLayout              GUID    <053737037H, 06D14H, 0410BH, <09BH, 0FEH, 00BH, 018H, 02BH, 0B7H, 009H, 061H>>
;IDWriteBitmapRenderTarget      GUID    <05E5A32A3H, 08DFFH, 04773H, <09FH, 0F6H, 006H, 096H, 0EAH, 0B7H, 072H, 067H>>
;IDWriteGdiInterop              GUID    <01EDD9491H, 09853H, 04299H, <089H, 08FH, 064H, 032H, 098H, 03BH, 06FH, 03AH>>
;IDWriteGlyphRunAnalysis        GUID    <07D97DBF7H, 0E085H, 042D4H, <081H, 0E3H, 06AH, 088H, 03BH, 0DEH, 0D1H, 018H>>
;IDWriteFactory                 GUID    <0B859EE5AH, 0D838H, 04B5BH, <0A2H, 0E8H, 01AH, 0DCH, 07DH, 093H, 0DBH, 048H>>

#endif /* DWRITE_H */
