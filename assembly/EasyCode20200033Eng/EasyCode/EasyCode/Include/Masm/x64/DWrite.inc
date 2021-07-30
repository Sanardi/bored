;======================================================;
;                                                      ;
;  DWrite.inc for Easy Code 2.0 64-bit Masm projects   ;
;                   (version 1.0.0)                    ;
;                                                      ;
;          Copyright © Héctor A. Medina - 2020         ;
;                                                      ;
;======================================================;

IFNDEF DWRITE_INC
DWRITE_INC   EQU 1

DWRITE_MEASURING_MODE                           		TYPEDEF DWORD
DWRITE_MEASURING_MODE_NATURAL                   		EQU     0
DWRITE_MEASURING_MODE_GDI_CLASSIC               		EQU     1
DWRITE_MEASURING_MODE_GDI_NATURAL               		EQU     2

;DWRITE_FONT_FILE_TYPE enumeration
DWRITE_FONT_FILE_TYPE_UNKNOWN                   		EQU     0
DWRITE_FONT_FILE_TYPE_CFF                       		EQU     1
DWRITE_FONT_FILE_TYPE_TRUETYPE                  		EQU     2
DWRITE_FONT_FILE_TYPE_TRUETYPE_COLLECTION       		EQU     3
DWRITE_FONT_FILE_TYPE_TYPE1_PFM                 		EQU     4
DWRITE_FONT_FILE_TYPE_TYPE1_PFB                 		EQU     5
DWRITE_FONT_FILE_TYPE_VECTOR                    		EQU     6
DWRITE_FONT_FILE_TYPE_BITMAP                    		EQU     7


;DWRITE_FONT_FACE_TYPE enumeration
DWRITE_FONT_FACE_TYPE_CFF                       		EQU     0
DWRITE_FONT_FACE_TYPE_TRUETYPE                  		EQU     1
DWRITE_FONT_FACE_TYPE_TRUETYPE_COLLECTION       		EQU     2
DWRITE_FONT_FACE_TYPE_TYPE1                     		EQU     3
DWRITE_FONT_FACE_TYPE_VECTOR                    		EQU     4
DWRITE_FONT_FACE_TYPE_BITMAP                    		EQU     5
DWRITE_FONT_FACE_TYPE_UNKNOWN                   		EQU     6

;DWRITE_FONT_SIMULATIONS enumeration
DWRITE_FONT_SIMULATIONS_NONE                    		EQU     0
DWRITE_FONT_SIMULATIONS_BOLD                    		EQU     1
DWRITE_FONT_SIMULATIONS_OBLIQUE                 		EQU     2

;DWRITE_FONT_WEIGHT enumeration
DWRITE_FONT_WEIGHT_THIN                         		EQU     100
DWRITE_FONT_WEIGHT_EXTRA_LIGHT                  		EQU     200
DWRITE_FONT_WEIGHT_ULTRA_LIGHT                  		EQU     200
DWRITE_FONT_WEIGHT_LIGHT                        		EQU     300
DWRITE_FONT_WEIGHT_SEMI_LIGHT                           EQU     350
DWRITE_FONT_WEIGHT_NORMAL                       		EQU     400
DWRITE_FONT_WEIGHT_REGULAR                      		EQU     400
DWRITE_FONT_WEIGHT_MEDIUM                       		EQU     500
DWRITE_FONT_WEIGHT_DEMI_BOLD                    		EQU     600
DWRITE_FONT_WEIGHT_SEMI_BOLD                    		EQU     600
DWRITE_FONT_WEIGHT_BOLD                         		EQU     700
DWRITE_FONT_WEIGHT_EXTRA_BOLD                   		EQU     800
DWRITE_FONT_WEIGHT_ULTRA_BOLD                   		EQU     800
DWRITE_FONT_WEIGHT_BLACK                        		EQU     900
DWRITE_FONT_WEIGHT_HEAVY                        		EQU     900
DWRITE_FONT_WEIGHT_EXTRA_BLACK                  		EQU     950
DWRITE_FONT_WEIGHT_ULTRA_BLACK                  		EQU     950

;DWRITE_FONT_STRETCH enumeration
DWRITE_FONT_STRETCH_UNDEFINED                   		EQU     0
DWRITE_FONT_STRETCH_ULTRA_CONDENSED             		EQU     1
DWRITE_FONT_STRETCH_EXTRA_CONDENSED             		EQU     2
DWRITE_FONT_STRETCH_CONDENSED                   		EQU     3
DWRITE_FONT_STRETCH_SEMI_CONDENSED              		EQU     4
DWRITE_FONT_STRETCH_NORMAL                      		EQU     5
DWRITE_FONT_STRETCH_MEDIUM                      		EQU     5
DWRITE_FONT_STRETCH_SEMI_EXPANDED               		EQU     6
DWRITE_FONT_STRETCH_EXPANDED                    		EQU     7
DWRITE_FONT_STRETCH_EXTRA_EXPANDED              		EQU     8
DWRITE_FONT_STRETCH_ULTRA_EXPANDED              		EQU     9

;DWRITE_FONT_STYLE enumeration
DWRITE_FONT_STYLE_NORMAL                        		EQU     0
DWRITE_FONT_STYLE_OBLIQUE                       		EQU     1
DWRITE_FONT_STYLE_ITALIC                        		EQU     2

;DWRITE_INFORMATIONAL_STRING_ID enumeration
DWRITE_INFORMATIONAL_STRING_NONE                		EQU     0
DWRITE_INFORMATIONAL_STRING_COPYRIGHT_NOTICE    		EQU     1
DWRITE_INFORMATIONAL_STRING_VERSION_STRINGS     		EQU     2
DWRITE_INFORMATIONAL_STRING_TRADEMARK           		EQU     3
DWRITE_INFORMATIONAL_STRING_MANUFACTURER        		EQU     4
DWRITE_INFORMATIONAL_STRING_DESIGNER            		EQU     5
DWRITE_INFORMATIONAL_STRING_DESIGNER_URL        		EQU     6
DWRITE_INFORMATIONAL_STRING_DESCRIPTION         		EQU     7
DWRITE_INFORMATIONAL_STRING_FONT_VENDOR_URL     		EQU     8
DWRITE_INFORMATIONAL_STRING_LICENSE_DESCRIPTION 		EQU     9
DWRITE_INFORMATIONAL_STRING_LICENSE_INFO_URL    		EQU     10
DWRITE_INFORMATIONAL_STRING_WIN32_FAMILY_NAMES  		EQU     11
DWRITE_INFORMATIONAL_STRING_WIN32_SUBFAMILY_NAMES 		EQU     12
DWRITE_INFORMATIONAL_STRING_PREFERRED_FAMILY_NAMES 		EQU     13
DWRITE_INFORMATIONAL_STRING_PREFERRED_SUBFAMILY_NAMES 	EQU     14
DWRITE_INFORMATIONAL_STRING_SAMPLE_TEXT         		EQU     15
DWRITE_INFORMATIONAL_STRING_FULL_NAME           		EQU     16
DWRITE_INFORMATIONAL_STRING_POSTSCRIPT_NAME     		EQU     17
DWRITE_INFORMATIONAL_STRING_POSTSCRIPT_CID_NAME 		EQU     18

;DWRITE_FACTORY_TYPE enumeration
DWRITE_FACTORY_TYPE_SHARED                      		EQU     0
DWRITE_FACTORY_TYPE_ISOLATED                    		EQU     1

;DWRITE_PIXEL_GEOMETRY enumeration
DWRITE_PIXEL_GEOMETRY_FLAT                      		EQU     0
DWRITE_PIXEL_GEOMETRY_RGB                       		EQU     1
DWRITE_PIXEL_GEOMETRY_BGR                       		EQU     2

;DWRITE_RENDERING_MODE enumeration
DWRITE_RENDERING_MODE_DEFAULT                   		EQU     0
DWRITE_RENDERING_MODE_ALIASED                   		EQU     1
DWRITE_RENDERING_MODE_GDI_CLASSIC               		EQU     2
DWRITE_RENDERING_MODE_GDI_NATURAL               		EQU     3
DWRITE_RENDERING_MODE_NATURAL                   		EQU     4
DWRITE_RENDERING_MODE_NATURAL_SYMMETRIC         		EQU     5
DWRITE_RENDERING_MODE_OUTLINE                   		EQU     6
DWRITE_RENDERING_MODE_CLEARTYPE_GDI_CLASSIC     		EQU     DWRITE_RENDERING_MODE_GDI_CLASSIC
DWRITE_RENDERING_MODE_CLEARTYPE_GDI_NATURAL     		EQU     DWRITE_RENDERING_MODE_GDI_NATURAL
DWRITE_RENDERING_MODE_CLEARTYPE_NATURAL         		EQU     DWRITE_RENDERING_MODE_NATURAL
DWRITE_RENDERING_MODE_CLEARTYPE_NATURAL_SYMMETRIC 		EQU   	DWRITE_RENDERING_MODE_NATURAL_SYMMETRIC

;DWRITE_READING_DIRECTION enumeration
DWRITE_READING_DIRECTION_LEFT_TO_RIGHT          		EQU     0
DWRITE_READING_DIRECTION_RIGHT_TO_LEFT          		EQU     1

;DWRITE_FLOW_DIRECTION enumeration
DWRITE_FLOW_DIRECTION_TOP_TO_BOTTOM             		EQU     0

;DWRITE_TEXT_ALIGNMENT enumeration
DWRITE_TEXT_ALIGNMENT_LEADING                   		EQU     0
DWRITE_TEXT_ALIGNMENT_TRAILING                  		EQU     1
DWRITE_TEXT_ALIGNMENT_CENTER                    		EQU     2

;DWRITE_PARAGRAPH_ALIGNMENT enumeration
DWRITE_PARAGRAPH_ALIGNMENT_NEAR                 		EQU     0
DWRITE_PARAGRAPH_ALIGNMENT_FAR                  		EQU     1
DWRITE_PARAGRAPH_ALIGNMENT_CENTER               		EQU     2

;DWRITE_WORD_WRAPPING enumeration
DWRITE_WORD_WRAPPING_WRAP                       		EQU     0
DWRITE_WORD_WRAPPING_NO_WRAP                    		EQU     1

;DWRITE_LINE_SPACING_METHOD enumeration
DWRITE_LINE_SPACING_METHOD_DEFAULT              		EQU     0
DWRITE_LINE_SPACING_METHOD_UNIFORM              		EQU     1

;DWRITE_TRIMMING_GRANULARITY enumeration
DWRITE_TRIMMING_GRANULARITY_NONE                		EQU     0
DWRITE_TRIMMING_GRANULARITY_CHARACTER           		EQU     1
DWRITE_TRIMMING_GRANULARITY_WORD                		EQU     2

;DWRITE_FONT_FEATURE_TAG enumeration
DWRITE_FONT_FEATURE_TAG_ALTERNATIVE_FRACTIONS   		EQU     0063726661H ;'afrc'
DWRITE_FONT_FEATURE_TAG_PETITE_CAPITALS_FROM_CAPITALS	EQU     0063703263H ;'c2pc'
DWRITE_FONT_FEATURE_TAG_SMALL_CAPITALS_FROM_CAPITALS  	EQU     0063733263H ;'c2sc'
DWRITE_FONT_FEATURE_TAG_CONTEXTUAL_ALTERNATES         	EQU     00746C6163H ;'calt'
DWRITE_FONT_FEATURE_TAG_CASE_SENSITIVE_FORMS          	EQU     0065736163H ;'case'
DWRITE_FONT_FEATURE_TAG_GLYPH_COMPOSITION_DECOMPOSITION EQU     00706D6363H ;'ccmp'
DWRITE_FONT_FEATURE_TAG_CONTEXTUAL_LIGATURES    		EQU     0067696C63H ;'clig'
DWRITE_FONT_FEATURE_TAG_CAPITAL_SPACING         		EQU     0070737063H ;'cpsp'
DWRITE_FONT_FEATURE_TAG_CONTEXTUAL_SWASH        		EQU     0068777363H ;'cswh'
DWRITE_FONT_FEATURE_TAG_CURSIVE_POSITIONING     		EQU     0073727563H ;'curs'
DWRITE_FONT_FEATURE_TAG_DEFAULT                 		EQU     00746c6664H ;'dflt'
DWRITE_FONT_FEATURE_TAG_DISCRETIONARY_LIGATURES 		EQU     0067696c64H ;'dlig'
DWRITE_FONT_FEATURE_TAG_EXPERT_FORMS            		EQU     0074707865H ;'expt'
DWRITE_FONT_FEATURE_TAG_FRACTIONS               		EQU     0063617266H ;'frac'
DWRITE_FONT_FEATURE_TAG_FULL_WIDTH              		EQU     0064697766H ;'fwid'
DWRITE_FONT_FEATURE_TAG_HALF_FORMS              		EQU     00666C6168H ;'half'
DWRITE_FONT_FEATURE_TAG_HALANT_FORMS            		EQU     006e6c6168H ;'haln'
DWRITE_FONT_FEATURE_TAG_ALTERNATE_HALF_WIDTH    		EQU     00746c6168H ;'halt'
DWRITE_FONT_FEATURE_TAG_HISTORICAL_FORMS        		EQU     0074736968H ;'hist'
DWRITE_FONT_FEATURE_TAG_HORIZONTAL_KANA_ALTERNATES 		EQU     00616e6b68H ;'hkna'
DWRITE_FONT_FEATURE_TAG_HISTORICAL_LIGATURES    		EQU     0067696c68H ;'hlig'
DWRITE_FONT_FEATURE_TAG_HALF_WIDTH              		EQU     0064697768H ;'hwid'
DWRITE_FONT_FEATURE_TAG_HOJO_KANJI_FORMS        		EQU     006f6a6f68H ;'hojo'
DWRITE_FONT_FEATURE_TAG_JIS04_FORMS             		EQU     003430706aH ;'jp04'
DWRITE_FONT_FEATURE_TAG_JIS78_FORMS             		EQU     003837706aH ;'jp78'
DWRITE_FONT_FEATURE_TAG_JIS83_FORMS             		EQU     003338706aH ;'jp83'
DWRITE_FONT_FEATURE_TAG_JIS90_FORMS             		EQU     003039706aH ;'jp90'
DWRITE_FONT_FEATURE_TAG_KERNING                 		EQU     006e72656bH ;'kern'
DWRITE_FONT_FEATURE_TAG_STANDARD_LIGATURES      		EQU     006167696cH ;'liga'
DWRITE_FONT_FEATURE_TAG_LINING_FIGURES          		EQU     006d756e6cH ;'lnum'
DWRITE_FONT_FEATURE_TAG_LOCALIZED_FORMS         		EQU     006c636f6cH ;'locl'
DWRITE_FONT_FEATURE_TAG_MARK_POSITIONING        		EQU     006b72616dH ;'mark'
DWRITE_FONT_FEATURE_TAG_MATHEMATICAL_GREEK      		EQU     006b72676dH ;'mgrk'
DWRITE_FONT_FEATURE_TAG_MARK_TO_MARK_POSITIONING 		EQU     006b6d6b6dH ;'mkmk'
DWRITE_FONT_FEATURE_TAG_ALTERNATE_ANNOTATION_FORMS    	EQU     00746c616eH ;'nalt'
DWRITE_FONT_FEATURE_TAG_NLC_KANJI_FORMS               	EQU     006b636c6eH ;'nlck'
DWRITE_FONT_FEATURE_TAG_OLD_STYLE_FIGURES             	EQU     006d756e6fH ;'onum'
DWRITE_FONT_FEATURE_TAG_ORDINALS                      	EQU     006e64726fH ;'ordn'
DWRITE_FONT_FEATURE_TAG_PROPORTIONAL_ALTERNATE_WIDTH  	EQU     00746c6170H ;'palt'
DWRITE_FONT_FEATURE_TAG_PETITE_CAPITALS               	EQU     0070616370H ;'pcap'
DWRITE_FONT_FEATURE_TAG_PROPORTIONAL_FIGURES          	EQU     006d756e70H ;'pnum'
DWRITE_FONT_FEATURE_TAG_PROPORTIONAL_WIDTHS           	EQU     0064697770H ;'pwid'
DWRITE_FONT_FEATURE_TAG_QUARTER_WIDTHS                	EQU     0064697771H ;'qwid'
DWRITE_FONT_FEATURE_TAG_REQUIRED_LIGATURES            	EQU     0067696c72H ;'rlig'
DWRITE_FONT_FEATURE_TAG_RUBY_NOTATION_FORMS           	EQU     0079627572H ;'ruby'
DWRITE_FONT_FEATURE_TAG_STYLISTIC_ALTERNATES          	EQU     00746c6173H ;'salt'
DWRITE_FONT_FEATURE_TAG_SCIENTIFIC_INFERIORS          	EQU     00666e6973H ;'sinf'
DWRITE_FONT_FEATURE_TAG_SMALL_CAPITALS                	EQU     0070636d73H ;'smcp'
DWRITE_FONT_FEATURE_TAG_SIMPLIFIED_FORMS              	EQU     006c706d73H ;'smpl'
DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_1               	EQU     0031307373H ;'ss01'
DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_2               	EQU     0032307373H ;'ss02'
DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_3               	EQU     0033307373H ;'ss03'
DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_4               	EQU     0034307373H ;'ss04'
DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_5               	EQU     0035307373H ;'ss05'
DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_6               	EQU     0036307373H ;'ss06'
DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_7               	EQU     0037307373H ;'ss07'
DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_8               	EQU     0038307373H ;'ss08'
DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_9               	EQU     0039307373H ;'ss09'
DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_10              	EQU     0030317373H ;'ss10'
DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_11              	EQU     0031317373H ;'ss11'
DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_12              	EQU     0032317373H ;'ss12'
DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_13              	EQU     0033317373H ;'ss13'
DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_14              	EQU     0034317373H ;'ss14'
DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_15              	EQU     0035317373H ;'ss15'
DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_16              	EQU     0036317373H ;'ss16'
DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_17              	EQU     0037317373H ;'ss17'
DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_18              	EQU     0038317373H ;'ss18'
DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_19              	EQU     0039317373H ;'ss19'
DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_20              	EQU     0030327373H ;'ss20'
DWRITE_FONT_FEATURE_TAG_SUBSCRIPT                     	EQU     0073627573H ;'subs'
DWRITE_FONT_FEATURE_TAG_SUPERSCRIPT                   	EQU     0073707573H ;'sups'
DWRITE_FONT_FEATURE_TAG_SWASH                         	EQU     0068737773H ;'swsh'
DWRITE_FONT_FEATURE_TAG_TITLING                       	EQU     006c746974H ;'titl'
DWRITE_FONT_FEATURE_TAG_TRADITIONAL_NAME_FORMS        	EQU     006D616E74H ;'tnam'
DWRITE_FONT_FEATURE_TAG_TABULAR_FIGURES               	EQU     006D756E74H ;'tnum'
DWRITE_FONT_FEATURE_TAG_TRADITIONAL_FORMS             	EQU     0064617274H ;'trad'
DWRITE_FONT_FEATURE_TAG_THIRD_WIDTHS                  	EQU     0064697774H ;'twid'
DWRITE_FONT_FEATURE_TAG_UNICASE                       	EQU     0063696E75H ;'unic'
DWRITE_FONT_FEATURE_TAG_SLASHED_ZERO                  	EQU     006F72657AH ;'zero'

;DWRITE_SCRIPT_SHAPES enumeration
DWRITE_SCRIPT_SHAPES_DEFAULT                          	EQU     0
DWRITE_SCRIPT_SHAPES_NO_VISUAL                        	EQU     1

;DWRITE_BREAK_CONDITION enumeration
DWRITE_BREAK_CONDITION_NEUTRAL                        	EQU     0
DWRITE_BREAK_CONDITION_CAN_BREAK                      	EQU     1
DWRITE_BREAK_CONDITION_MAY_NOT_BREAK                  	EQU     2
DWRITE_BREAK_CONDITION_MUST_BREAK                     	EQU     3

;DWRITE_NUMBER_SUBSTITUTION_METHOD enumeration
DWRITE_NUMBER_SUBSTITUTION_METHOD_FROM_CULTURE        	EQU     0
DWRITE_NUMBER_SUBSTITUTION_METHOD_CONTEXTUAL          	EQU     1
DWRITE_NUMBER_SUBSTITUTION_METHOD_NONE                	EQU     2
DWRITE_NUMBER_SUBSTITUTION_METHOD_NATIONAL            	EQU     3
DWRITE_NUMBER_SUBSTITUTION_METHOD_TRADITIONAL         	EQU     4

;DWRITE_TEXTURE_TYPE enumeration
DWRITE_TEXTURE_ALIASED_1x1                            	EQU     0
DWRITE_TEXTURE_CLEARTYPE_3x1                          	EQU     1

;======================================== Structures ======================================;
DWRITE_FONT_METRICS STRUCT
       designUnitsPerEm       UINT16 ?
       ascent                 UINT16 ?
       descent                UINT16 ?
       lineGap                INT16  ?
       capHeight              UINT16 ?
       xHeight                UINT16 ?
       underlinePosition      INT16  ?
       underlineThickness     UINT16 ?
       strikethroughPosition  INT16  ?
       strikethroughThickness UINT16 ?
DWRITE_FONT_METRICS ENDS

DWRITE_GLYPH_METRICS STRUCT
       leftSideBearing   INT32  ?
       advanceWidth      UINT32 ?
       rightSideBearing  INT32  ?
       topSideBearing    INT32  ?
       advanceHeight     UINT32 ?
       bottomSideBearing INT32  ?
       verticalOriginY   INT32  ?
DWRITE_GLYPH_METRICS ENDS

DWRITE_GLYPH_OFFSET STRUCT
       advanceOffset  FLOAT ?
       ascenderOffset FLOAT ?
DWRITE_GLYPH_OFFSET ENDS

DWRITE_MATRIX STRUCT
       m11 FLOAT ?
       m12 FLOAT ?
       m21 FLOAT ?
       m22 FLOAT ?
       dx_ FLOAT ?
       dy  FLOAT ?
DWRITE_MATRIX ENDS

DWRITE_TEXT_RANGE STRUCT
       startPosition UINT32 ?
       length_       UINT32 ?
DWRITE_TEXT_RANGE ENDS

DWRITE_FONT_FEATURE STRUCT
       nameTag   DD     ? ;DWRITE_FONT_FEATURE_TAG
       parameter UINT32 ?
DWRITE_FONT_FEATURE ENDS

DWRITE_TYPOGRAPHIC_FEATURES STRUCT
       features      XPTR   ?
       featureCount_ UINT32 ?
DWRITE_TYPOGRAPHIC_FEATURES ENDS

DWRITE_TRIMMING STRUCT
       granularity     DD     ? ;DWRITE_TRIMMING_GRANULARITY
       delimiter_      UINT32 ?
       delimiterCount_ UINT32 ?
DWRITE_TRIMMING ENDS

DWRITE_SCRIPT_ANALYSIS STRUCT
       script UINT16 ?
       shapes DD     ? ;DWRITE_SCRIPT_SHAPES
DWRITE_SCRIPT_ANALYSIS ENDS

DWRITE_LINE_BREAKPOINT STRUCT
      breakConditionBefore UINT8 ? ;:2
      breakConditionAfter  UINT8 ? ;:2
      isWhitespace         UINT8 ? ;:1
      isSoftHyphen         UINT8 ? ;:1
      padding              UINT8 ? ;:2
DWRITE_LINE_BREAKPOINT ENDS

DWRITE_SHAPING_TEXT_PROPERTIES STRUCT
      isShapedAlone UINT16 ? ;:1
      reserved      UINT16 ? ;:15
DWRITE_SHAPING_TEXT_PROPERTIES ENDS

DWRITE_SHAPING_GLYPH_PROPERTIES STRUCT
      justification    UINT16 ? ;:4
      isClusterStart   UINT16 ? ;:1
      isDiacritic      UINT16 ? ;:1
      isZeroWidthSpace UINT16 ? ;:1
      reserved         UINT16 ? ;:9
DWRITE_SHAPING_GLYPH_PROPERTIES ENDS

DWRITE_GLYPH_RUN STRUCT
      fontFace      XPTR   ? ;__notnull IDWriteFontFace *
      fontEmSize    FLOAT  ?
      lyphCount     UINT32 ?
      glyphIndices  UINT16 ? ;__field_ecount(glyphCount) UINT16 const *
      glyphAdvances FLOAT  ? ;__field_ecount_opt(glyphCount) FLOAT const *
      glyphOffsets  XPTR   ? ;__field_ecount_opt(glyphCount) DWRITE_GLYPH_OFFSET const *
      isSideways    BOOL   ?
      bidiLevel     UINT32 ?
DWRITE_GLYPH_RUN ENDS

DWRITE_GLYPH_RUN_DESCRIPTION STRUCT
      localeName   XPTR   ? ;__nullterminated WCHAR const *
      string       XPTR   ? ;__field_ecount(stringLength) WCHAR const *
      stringLength UINT32 ?
      clusterMap   UINT16 ? ;__field_ecount(stringLength) UINT16 const *
      textPosition UINT32 ?
DWRITE_GLYPH_RUN_DESCRIPTION ENDS

DWRITE_UNDERLINE STRUCT
      width_           FLOAT ?
      thickness        FLOAT ?
      offset_          FLOAT ?
      runHeight        FLOAT ?
      readingDirection DD    ? ;DWRITE_READING_DIRECTION
      flowDirection    DD    ? ;DWRITE_FLOW_DIRECTION
      localeName       XPTR  ? ;__nullterminated WCHAR const *
      measuringMode    DD    ? ;DWRITE_MEASURING_MODE
DWRITE_UNDERLINE ENDS

DWRITE_STRIKETHROUGH STRUCT
      width_           FLOAT ?
      thickness        FLOAT ?
      offset_          FLOAT ?
      readingDirection DD    ? ;DWRITE_READING_DIRECTION
      flowDirection    DD    ? ;DWRITE_FLOW_DIRECTION
      localeName       XPTR  ? ;__nullterminated WCHAR const *
      measuringMode    DD    ? ;DWRITE_MEASURING_MODE
DWRITE_STRIKETHROUGH ENDS

DWRITE_LINE_METRICS STRUCT
      length_                  UINT32 ?
      trailingWhitespaceLength UINT32 ?
      newlineLength            UINT32 ?
      height                   FLOAT  ?
      baseline                 FLOAT  ?
      isTrimmed                BOOL   ?
DWRITE_LINE_METRICS ENDS

DWRITE_CLUSTER_METRICS STRUCT
      width_           FLOAT  ?
      length_          UINT16 ?
      canWrapLineAfter UINT16 ? ;:1
      isWhitespace     UINT16 ? ;:1
      isNewline        UINT16 ? ;:1
      isSoftHyphen     UINT16 ? ;:1
      isRightToLeft    UINT16 ? ;:1
      padding          UINT16 ? ;:11
DWRITE_CLUSTER_METRICS ENDS

DWRITE_TEXT_METRICS STRUCT
      left                             FLOAT  ?
      top                              FLOAT  ?
      width_                           FLOAT  ?
      widthIncludingTrailingWhitespace FLOAT  ?
      height                           FLOAT  ?
      layoutWidth                      FLOAT  ?
      layoutHeight                     FLOAT  ?
      maxBidiReorderingDepth           UINT32 ?
      lineCount                        UINT32 ?
DWRITE_TEXT_METRICS ENDS

DWRITE_INLINE_OBJECT_METRICS STRUCT
      width_           FLOAT ?
      height           FLOAT ?
      baseline         FLOAT ?
      supportsSideways BOOL  ?
DWRITE_INLINE_OBJECT_METRICS ENDS

DWRITE_OVERHANG_METRICS STRUCT
      left   FLOAT ?
      top    FLOAT ?
      right  FLOAT ?
      bottom FLOAT ?
DWRITE_OVERHANG_METRICS ENDS

DWRITE_HIT_TEST_METRICS STRUCT
      textPosition UINT32 ?
      length_      UINT32 ?
      left         FLOAT  ?
      top          FLOAT  ?
      width_       FLOAT  ?
      height       FLOAT  ?
      bidiLeve     UINT32 ?
      isText       BOOL   ?
      isTrimmed    BOOL   ?
DWRITE_HIT_TEST_METRICS ENDS

IDWriteBitmapRenderTargetVtbl STRUCT
    QueryInterface      QWORD ?
    AddRef              QWORD ?
    Release             QWORD ?
    DrawGlyphRun        QWORD ?
    GetMemoryDC         QWORD ?
    GetPixelsPerDip     QWORD ?
    SetPixelsPerDip     QWORD ?
    GetCurrentTransform QWORD ?
    SetCurrentTransform QWORD ?
    GetSize             QWORD ?
    Resize              QWORD ?

IDWriteBitmapRenderTargetVtbl ENDS

IDWriteFactoryVtbl STRUCT
    QueryInterface                 QWORD ?
    AddRef                         QWORD ?
    Release                        QWORD ?
    GetSystemFontCollection        QWORD ?
    CreateCustomFontCollection     QWORD ?
    RegisterFontCollectionLoader   QWORD ?
    UnregisterFontCollectionLoader QWORD ?
    CreateFontFileReference        QWORD ?
    CreateCustomFontFileReference  QWORD ?
    CreateFontFace                 QWORD ?
    CreateRenderingParams          QWORD ?
    CreateMonitorRenderingParams   QWORD ?
    CreateCustomRenderingParams    QWORD ?
    RegisterFontFileLoader         QWORD ?
    UnregisterFontFileLoader       QWORD ?
    CreateTextFormat               QWORD ?
    CreateTypography               QWORD ?
    GetGdiInterop                  QWORD ?
    CreateTextLayout               QWORD ?
    CreateGdiCompatibleTextLayout  QWORD ?
    CreateEllipsisTrimmingSign     QWORD ?
    CreateTextAnalyzer             QWORD ?
    CreateNumberSubstitution       QWORD ?
    CreateGlyphRunAnalysis         QWORD ?
IDWriteFactoryVtbl ENDS

IDWriteFontVtbl STRUCT
    QueryInterface          QWORD ?
    AddRef                  QWORD ?
    Release                 QWORD ?
    GetFontFamily           QWORD ?
    GetWeight               QWORD ?
    GetStretch              QWORD ?
    GetStyle                QWORD ?
    IsSymbolFont            QWORD ?
    GetFaceNames            QWORD ?
    GetInformationalStrings QWORD ?
    GetSimulations          QWORD ?
    GetMetrics              QWORD ?
    HasCharacter            QWORD ?
    CreateFontFace          QWORD ?
IDWriteFontVtbl ENDS

IDWriteFontCollectionVtbl STRUCT
    QueryInterface      QWORD ?
    AddRef              QWORD ?
    Release             QWORD ?
    GetFontFamilyCount  QWORD ?
    GetFontFamily       QWORD ?
    FindFamilyName      QWORD ?
    GetFontFromFontFace QWORD ?
IDWriteFontCollectionVtbl ENDS

IDWriteFontFaceVtbl STRUCT
    QueryInterface               QWORD ?
    AddRef                       QWORD ?
    Release                      QWORD ?
    GetType                      QWORD ?
    GetFiles                     QWORD ?
    GetIndex                     QWORD ?
    GetSimulations               QWORD ?
    IsSymbolFont                 QWORD ?
    GetMetrics                   QWORD ?
    GetGlyphCount                QWORD ?
    GetDesignGlyphMetrics        QWORD ?
    GetGlyphIndices              QWORD ?
    TryGetFontTable              QWORD ?
    ReleaseFontTable             QWORD ?
    GetGlyphRunOutline           QWORD ?
    GetRecommendedRenderingMode  QWORD ?
    GetGdiCompatibleMetrics      QWORD ?
    GetGdiCompatibleGlyphMetrics QWORD ?
IDWriteFontFaceVtbl ENDS

IDWriteFontListVtbl STRUCT
    QueryInterface    QWORD ?
    AddRef            QWORD ?
    Release           QWORD ?
    GetFontCollection QWORD ?
    GetFontCount      QWORD ?
    GetFont           QWORD ?

IDWriteFontListVtbl ENDS

IDWriteFontFamilyVtbl STRUCT
    QueryInterface       QWORD ? ;IDWriteFontListVtbl
    AddRef               QWORD ?
    Release              QWORD ?
    GetFontCollection    QWORD ?
    GetFontCount         QWORD ?
    GetFont              QWORD ?
    GetFamilyNames       QWORD ?
    GetFirstMatchingFont QWORD ?
    GetMatchingFonts     QWORD ?
IDWriteFontFamilyVtbl ENDS

IDWriteFontFileVtbl STRUCT
    QueryInterface  QWORD ?
    AddRef          QWORD ?
    Release         QWORD ?
    GetReferenceKey QWORD ?
    GetLoader       QWORD ?
    Analyze         QWORD ?
IDWriteFontFileVtbl ENDS

IDWriteFontFileLoaderVtbl STRUCT
    QueryInterface      QWORD ?
    AddRef              QWORD ?
    Release             QWORD ?
    CreateStreamFromKey QWORD ?
IDWriteFontFileLoaderVtbl ENDS

IDWriteFontFileStreamVtbl STRUCT
    QueryInterface      QWORD ?
    AddRef              QWORD ?
    Release             QWORD ?
    ReadFileFragment    QWORD ?
    ReleaseFileFragment QWORD ?
    GetFileSize         QWORD ?
    GetLastWriteTime    QWORD ?
IDWriteFontFileStreamVtbl ENDS

IDWriteFontCollectionLoaderVtbl STRUCT
    QueryInterface          QWORD ?
    AddRef                  QWORD ?
    Release                 QWORD ?
    CreateEnumeratorFromKey QWORD ?
IDWriteFontCollectionLoaderVtbl ENDS

IDWriteFontFileEnumeratorVtbl STRUCT
    QueryInterface     QWORD ?
    AddRef             QWORD ?
    Release            QWORD ?
    MoveNext           QWORD ?
    GetCurrentFontFile QWORD ?
IDWriteFontFileEnumeratorVtbl ENDS

IDWriteGdiInteropVtbl STRUCT
    QueryInterface           QWORD ?
    AddRef                   QWORD ?
    Release                  QWORD ?
    CreateFontFromLOGFONT    QWORD ?
    ConvertFontToLOGFONT     QWORD ?
    ConvertFontFaceToLOGFONT QWORD ?
    CreateFontFaceFromHdc    QWORD ?
    CreateBitmapRenderTarget QWORD ?
IDWriteGdiInteropVtbl ENDS

IDWriteGlyphRunAnalysisVtbl STRUCT
    QueryInterface        QWORD ?
    AddRef                QWORD ?
    Release               QWORD ?
    GetAlphaTextureBounds QWORD ?
    CreateAlphaTexture    QWORD ?
    GetAlphaBlendParams   QWORD ?
IDWriteGlyphRunAnalysisVtbl ENDS

IDWriteInlineObjectVtbl STRUCT
    QueryInterface     QWORD ?
    AddRef             QWORD ?
    Release            QWORD ?
    Draw               QWORD ?
    GetMetrics         QWORD ?
    GetOverhangMetrics QWORD ?
    GetBreakConditions QWORD ?
IDWriteInlineObjectVtbl ENDS

IDWriteLocalFontFileLoaderVtbl STRUCT  
    QueryInterface           QWORD ? ;IDWriteFontFileLoaderVtbl
    AddRef                   QWORD ?
    Release                  QWORD ?
    CreateStreamFromKey      QWORD ?
    GetFilePathLengthFromKey QWORD ?
    GetFilePathFromKey       QWORD ?
    GetLastWriteTimeFromKey  QWORD ?
IDWriteLocalFontFileLoaderVtbl ENDS

IDWriteLocalizedStringsVtbl STRUCT
    QueryInterface      QWORD ?
    AddRef              QWORD ?
    Release             QWORD ?
    GetCount            QWORD ?
    FindLocaleName      QWORD ?
    GetLocaleNameLength QWORD ?
    GetLocaleName       QWORD ?
    GetStringLength     QWORD ?
    GetString           QWORD ?
IDWriteLocalizedStringsVtbl ENDS

IDWriteNumberSubstitutionVtbl STRUCT
    QueryInterface QWORD ?
    AddRef         QWORD ?
    Release        QWORD ?
IDWriteNumberSubstitutionVtbl ENDS

IDWritePixelSnappingVtbl STRUCT
    QueryInterface          QWORD ?
    AddRef                  QWORD ?
    Release                 QWORD ?
    IsPixelSnappingDisabled QWORD ?
    GetCurrentTransform     QWORD ?
    GetPixelsPerDip         QWORD ?
IDWritePixelSnappingVtbl ENDS

IDWriteRenderingParamsVtbl STRUCT
    QueryInterface      QWORD ?
    AddRef              QWORD ?
    Release             QWORD ?
    GetGamma            QWORD ?
    GetEnhancedContrast QWORD ?
    GetClearTypeLevel   QWORD ?
    GetPixelGeometry    QWORD ?
    GetRenderingMode    QWORD ?
IDWriteRenderingParamsVtbl ENDS

IDWriteTextAnalysisSinkVtbl STRUCT
    QueryInterface        QWORD ?
    AddRef                QWORD ?
    Release               QWORD ?
    SetScriptAnalysis     QWORD ?
    SetLineBreakpoints    QWORD ?
    SetBidiLevel          QWORD ?
    SetNumberSubstitution QWORD ?
IDWriteTextAnalysisSinkVtbl ENDS

IDWriteTextAnalysisSourceVtbl STRUCT
    QueryInterface               QWORD ?
    AddRef                       QWORD ?
    Release                      QWORD ?
    GetTextAtPosition            QWORD ?
    GetTextBeforePosition        QWORD ?
    GetParagraphReadingDirection QWORD ?
    GetLocaleName                QWORD ?
    GetNumberSubstitution        QWORD ?
IDWriteTextAnalysisSourceVtbl ENDS

IDWriteTextAnalyzerVtbl STRUCT
    QueryInterface                  QWORD ?
    AddRef                          QWORD ?
    Release                         QWORD ?
    AnalyzeScript                   QWORD ?
    AnalyzeBidi                     QWORD ?
    AnalyzeNumberSubstitution       QWORD ?
    AnalyzeLineBreakpoints          QWORD ?
    GetGlyphs                       QWORD ?
    GetGlyphPlacements              QWORD ?
    GetGdiCompatibleGlyphPlacements QWORD ?
IDWriteTextAnalyzerVtbl ENDS

IDWriteTextFormatVtbl STRUCT
    QueryInterface          QWORD ?
    AddRef                  QWORD ?
    Release                 QWORD ?
    SetTextAlignment        QWORD ?
    SetParagraphAlignment   QWORD ?
    SetWordWrapping         QWORD ?
    SetReadingDirection     QWORD ?
    SetFlowDirection        QWORD ?
    SetIncrementalTabStop   QWORD ?
    SetTrimming             QWORD ?
    SetLineSpacing          QWORD ?
    GetTextAlignment        QWORD ?
    GetParagraphAlignment   QWORD ?
    GetWordWrapping         QWORD ?
    GetReadingDirection     QWORD ?
    GetFlowDirection        QWORD ?
    GetIncrementalTabStop   QWORD ?
    GetTrimming             QWORD ?
    GetLineSpacing          QWORD ?
    GetFontCollection       QWORD ?
    GetFontFamilyNameLength QWORD ?
    GetFontFamilyName       QWORD ?
    GetFontWeight           QWORD ?
    GetFontStyle            QWORD ?
    GetFontStretch          QWORD ?
    GetFontSize             QWORD ?
    GetLocaleNameLength     QWORD ?
    GetLocaleName           QWORD ?
IDWriteTextFormatVtbl ENDS

IDWriteTextLayoutVtbl STRUCT
    QueryInterface           QWORD ? ;IDWriteTextFormatVtbl
    AddRef                   QWORD ?
    Release                  QWORD ?
    SetTextAlignment         QWORD ?
    SetParagraphAlignment    QWORD ?
    SetWordWrapping          QWORD ?
    SetReadingDirection      QWORD ?
    SetFlowDirection         QWORD ?
    SetIncrementalTabStop    QWORD ?
    SetTrimming              QWORD ?
    SetLineSpacing           QWORD ?
    GetTextAlignment         QWORD ?
    GetParagraphAlignment    QWORD ?
    GetWordWrapping          QWORD ?
    GetReadingDirection      QWORD ?
    GetFlowDirection         QWORD ?
    GetIncrementalTabStop    QWORD ?
    GetTrimming              QWORD ?
    GetLineSpacing           QWORD ?
    GetFontCollection        QWORD ?
    GetFontFamilyNameLength  QWORD ?
    GetFontFamilyName        QWORD ?
    GetFontWeight            QWORD ?
    GetFontStyle             QWORD ?
    GetFontStretch           QWORD ?
    GetFontSize              QWORD ?
    GetLocaleNameLength      QWORD ?
    GetLocaleName            QWORD ?
    SetMaxWidth              QWORD ?
    SetMaxHeight             QWORD ?
    SetFontCollection        QWORD ?
    SetFontFamilyName        QWORD ?
    SetFontWeight            QWORD ?
    SetFontStyle             QWORD ?
    SetFontStretch           QWORD ?
    SetFontSize              QWORD ?
    SetUnderline             QWORD ?
    SetStrikethrough         QWORD ?
    SetDrawingEffect         QWORD ?
    SetInlineObject          QWORD ?
    SetTypography            QWORD ?
    SetLocaleName            QWORD ?
    GetMaxWidth              QWORD ?
    GetMaxHeight             QWORD ?
    GetFontCollection_       QWORD ?
    GetFontFamilyNameLength_ QWORD ?
    GetFontFamilyName_       QWORD ?
    GetFontWeight_           QWORD ?
    GetFontStyle_            QWORD ?
    GetFontStretch_          QWORD ?
    GetFontSize_             QWORD ?
    GetUnderline             QWORD ?
    GetStrikethrough         QWORD ?
    GetDrawingEffect         QWORD ?
    GetInlineObject          QWORD ?
    GetTypography            QWORD ?
    GetLocaleNameLength_     QWORD ?
    GetLocaleName_           QWORD ?
    Draw                     QWORD ?
    GetLineMetrics           QWORD ?
    GetMetrics               QWORD ?
    GetOverhangMetrics       QWORD ?
    GetClusterMetrics        QWORD ?
    DetermineMinWidth        QWORD ?
    HitTestPoint             QWORD ?
    HitTestTextPosition      QWORD ?
    HitTestTextRange         QWORD ?
IDWriteTextLayoutVtbl ENDS

IDWriteTextRendererVtbl STRUCT
    QueryInterface          QWORD ? ;IDWritePixelSnappingVtbl
    AddRef                  QWORD ?
    Release                 QWORD ?
    IsPixelSnappingDisabled QWORD ?
    GetCurrentTransform     QWORD ?
    GetPixelsPerDip         QWORD ?
    DrawGlyphRun            QWORD ?
    DrawUnderline           QWORD ?
    DrawStrikethrough       QWORD ?
    DrawInlineObject        QWORD ?
IDWriteTextRendererVtbl ENDS

IDWriteTypographyVtbl STRUCT
    QueryInterface      QWORD ?
    AddRef              QWORD ?
    Release             QWORD ?
    AddFontFeature      QWORD ?
    GetFontFeatureCount QWORD ?
    GetFontFeature      QWORD ?
IDWriteTypographyVtbl ENDS


;======================================== Functions =======================================;
DWriteCreateFactory                PROTO :QWORD, :QWORD, :QWORD

;====================================== GUID values =======================================;
.Data
IDWriteFontFileLoader          GUID    <0727CAD4EH, 0D6AFH, 04C9EH, {08AH, 008H, 0D6H, 095H, 0B1H, 01CH, 0AAH, 049H}>
IDWriteLocalFontFileLoader     GUID    <0B2D9F3ECH, 0C9FEH, 04A11H, {0A2H, 0ECH, 0D8H, 062H, 008H, 0F7H, 0C0H, 0A2H}>
IDWriteFontFileStream          GUID    <06D4865FEH, 00AB8H, 04D91H, {08FH, 062H, 05DH, 0D6H, 0BEH, 034H, 0A3H, 0E0H}>
IDWriteFontFile                GUID    <0739D886AH, 0CEF5H, 047DCH, {087H, 069H, 01AH, 08BH, 041H, 0BEH, 0BBH, 0B0H}>
IDWriteRenderingParams         GUID    <02F0DA53AH, 02ADDH, 047CDH, {082H, 0EEH, 0D9H, 0ECH, 034H, 068H, 08EH, 075H}>
IDWriteFontFace                GUID    <05F49804DH, 07024H, 04D43H, {0BFH, 0A9H, 0D2H, 059H, 084H, 0F5H, 038H, 049H}>
IDWriteFontCollectionLoader    GUID    <0CCA920E4H, 052F0H, 0492BH, {0BFH, 0A8H, 029H, 0C7H, 02EH, 0E0H, 0A4H, 068H}> 
IDWriteFontFileEnumerator      GUID    <072755049H, 05FF7H, 0435DH, {083H, 048H, 04BH, 0E9H, 07CH, 0FAH, 06CH, 07CH}>
IDWriteLocalizedStrings        GUID    <008256209H, 0099AH, 04B34H, {0B8H, 06DH, 0C2H, 02BH, 011H, 00EH, 077H, 071H}>
IDWriteFontCollection          GUID    <0A84CEE02H, 03EEAH, 04EEEH, {0A8H, 027H, 087H, 0C1H, 0A0H, 02AH, 00FH, 0CCH}>
IDWriteFontList                GUID    <01A0D8438H, 01D97H, 04EC1H, {0AEH, 0F9H, 0A2H, 0FBH, 086H, 0EDH, 06AH, 0CBH}>
IDWriteFontFamily              GUID    <0DA20D8EFH, 0812AH, 04C43H, {098H, 002H, 062H, 0ECH, 04AH, 0BDH, 07AH, 0DDH}>
IDWriteFont                    GUID    <0ACD16696H, 08C14H, 04F5DH, {087H, 07EH, 0FEH, 03FH, 0C1H, 0D3H, 027H, 037H}>
IDWriteTextFormat              GUID    <09C906818H, 031D7H, 04FD3H, {0A1H, 051H, 07CH, 05EH, 022H, 05DH, 0B5H, 05AH}>
IDWriteTypography              GUID    <055F1112BH, 01DC2H, 04B3CH, {095H, 041H, 0F4H, 068H, 094H, 0EDH, 085H, 0B6H}>
IDWriteTextAnalyzer            GUID    <0B7E6163EH, 07F46H, 043B4H, {084H, 0B3H, 0E4H, 0E6H, 024H, 09CH, 036H, 05DH}>
IDWriteInlineObject            GUID    <08339FDE3H, 0106FH, 047ABH, {083H, 073H, 01CH, 062H, 095H, 0EBH, 010H, 0B3H}>
IDWritePixelSnapping           GUID    <0EAF3A2DAH, 0ECF4H, 04D24H, {0B6H, 044H, 0B3H, 04FH, 068H, 042H, 002H, 04BH}>
IDWriteTextRenderer            GUID    <0EF8A8135H, 05CC6H, 045FEH, {088H, 025H, 0C5H, 0A0H, 072H, 04EH, 0B8H, 019H}>
IDWriteTextLayout              GUID    <053737037H, 06D14H, 0410BH, {09BH, 0FEH, 00BH, 018H, 02BH, 0B7H, 009H, 061H}>
IDWriteBitmapRenderTarget      GUID    <05E5A32A3H, 08DFFH, 04773H, {09FH, 0F6H, 006H, 096H, 0EAH, 0B7H, 072H, 067H}>
IDWriteGdiInterop              GUID    <01EDD9491H, 09853H, 04299H, {089H, 08FH, 064H, 032H, 098H, 03BH, 06FH, 03AH}>
IDWriteGlyphRunAnalysis        GUID    <07D97DBF7H, 0E085H, 042D4H, {081H, 0E3H, 06AH, 088H, 03BH, 0DEH, 0D1H, 018H}>
IDWriteFactory                 GUID    <0B859EE5AH, 0D838H, 04B5BH, {0A2H, 0E8H, 01AH, 0DCH, 07DH, 093H, 0DBH, 048H}>

ENDIF ;DWRITE_INC
