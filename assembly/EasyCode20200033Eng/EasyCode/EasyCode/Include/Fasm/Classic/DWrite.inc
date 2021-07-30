;======================================================;
;                                                      ;
;      DWrite.inc for EC v2 Fasm classic projects      ;
;                   (version 1.0.0)                    ;
;                                                      ;
;          Copyright © Héctor A. Medina - 2020         ;
;                                                      ;
;======================================================;

if ~defined DWRITE_INC
define DWRITE_INC

TYPEDEF                                                 DWRITE_MEASURING_MODE, dd
DWRITE_MEASURING_MODE_NATURAL                           equ     0
DWRITE_MEASURING_MODE_GDI_CLASSIC                       equ     1
DWRITE_MEASURING_MODE_GDI_NATURAL                       equ     2

;DWRITE_FONT_FILE_TYPE enumeration
DWRITE_FONT_FILE_TYPE_UNKNOWN                           equ     0
DWRITE_FONT_FILE_TYPE_CFF                               equ     1
DWRITE_FONT_FILE_TYPE_TRUETYPE                          equ     2
DWRITE_FONT_FILE_TYPE_TRUETYPE_COLLECTION               equ     3
DWRITE_FONT_FILE_TYPE_TYPE1_PFM                         equ     4
DWRITE_FONT_FILE_TYPE_TYPE1_PFB                         equ     5
DWRITE_FONT_FILE_TYPE_VECTOR                            equ     6
DWRITE_FONT_FILE_TYPE_BITMAP                            equ     7


;DWRITE_FONT_FACE_TYPE enumeration
DWRITE_FONT_FACE_TYPE_CFF                               equ     0
DWRITE_FONT_FACE_TYPE_TRUETYPE                          equ     1
DWRITE_FONT_FACE_TYPE_TRUETYPE_COLLECTION               equ     2
DWRITE_FONT_FACE_TYPE_TYPE1                             equ     3
DWRITE_FONT_FACE_TYPE_VECTOR                            equ     4
DWRITE_FONT_FACE_TYPE_BITMAP                            equ     5
DWRITE_FONT_FACE_TYPE_UNKNOWN                           equ     6

;DWRITE_FONT_SIMULATIONS enumeration
DWRITE_FONT_SIMULATIONS_NONE                            equ     0
DWRITE_FONT_SIMULATIONS_BOLD                            equ     1
DWRITE_FONT_SIMULATIONS_OBLIQUE                         equ     2

;DWRITE_FONT_WEIGHT enumeration
DWRITE_FONT_WEIGHT_THIN                                 equ     100
DWRITE_FONT_WEIGHT_EXTRA_LIGHT                          equ     200
DWRITE_FONT_WEIGHT_ULTRA_LIGHT                          equ     200
DWRITE_FONT_WEIGHT_LIGHT                                equ     300
DWRITE_FONT_WEIGHT_SEMI_LIGHT                           equ     350
DWRITE_FONT_WEIGHT_NORMAL                               equ     400
DWRITE_FONT_WEIGHT_REGULAR                              equ     400
DWRITE_FONT_WEIGHT_MEDIUM                               equ     500
DWRITE_FONT_WEIGHT_DEMI_BOLD                            equ     600
DWRITE_FONT_WEIGHT_SEMI_BOLD                            equ     600
DWRITE_FONT_WEIGHT_BOLD                                 equ     700
DWRITE_FONT_WEIGHT_EXTRA_BOLD                           equ     800
DWRITE_FONT_WEIGHT_ULTRA_BOLD                           equ     800
DWRITE_FONT_WEIGHT_BLACK                                equ     900
DWRITE_FONT_WEIGHT_HEAVY                                equ     900
DWRITE_FONT_WEIGHT_EXTRA_BLACK                          equ     950
DWRITE_FONT_WEIGHT_ULTRA_BLACK                          equ     950

;DWRITE_FONT_STRETCH enumeration
DWRITE_FONT_STRETCH_UNDEFINED                           equ     0
DWRITE_FONT_STRETCH_ULTRA_CONDENSED                     equ     1
DWRITE_FONT_STRETCH_EXTRA_CONDENSED                     equ     2
DWRITE_FONT_STRETCH_CONDENSED                           equ     3
DWRITE_FONT_STRETCH_SEMI_CONDENSED                      equ     4
DWRITE_FONT_STRETCH_NORMAL                              equ     5
DWRITE_FONT_STRETCH_MEDIUM                              equ     5
DWRITE_FONT_STRETCH_SEMI_EXPANDED                       equ     6
DWRITE_FONT_STRETCH_EXPANDED                            equ     7
DWRITE_FONT_STRETCH_EXTRA_EXPANDED                      equ     8
DWRITE_FONT_STRETCH_ULTRA_EXPANDED                      equ     9

;DWRITE_FONT_STYLE enumeration
DWRITE_FONT_STYLE_NORMAL                                equ     0
DWRITE_FONT_STYLE_OBLIQUE                               equ     1
DWRITE_FONT_STYLE_ITALIC                                equ     2

;DWRITE_INFORMATIONAL_STRING_ID enumeration
DWRITE_INFORMATIONAL_STRING_NONE                        equ     0
DWRITE_INFORMATIONAL_STRING_COPYRIGHT_NOTICE            equ     1
DWRITE_INFORMATIONAL_STRING_VERSION_STRINGS             equ     2
DWRITE_INFORMATIONAL_STRING_TRADEMARK                   equ     3
DWRITE_INFORMATIONAL_STRING_MANUFACTURER                equ     4
DWRITE_INFORMATIONAL_STRING_DESIGNER                    equ     5
DWRITE_INFORMATIONAL_STRING_DESIGNER_URL                equ     6
DWRITE_INFORMATIONAL_STRING_DESCRIPTION                 equ     7
DWRITE_INFORMATIONAL_STRING_FONT_VENDOR_URL             equ     8
DWRITE_INFORMATIONAL_STRING_LICENSE_DESCRIPTION         equ     9
DWRITE_INFORMATIONAL_STRING_LICENSE_INFO_URL            equ     10
DWRITE_INFORMATIONAL_STRING_WIN32_FAMILY_NAMES          equ     11
DWRITE_INFORMATIONAL_STRING_WIN32_SUBFAMILY_NAMES       equ     12
DWRITE_INFORMATIONAL_STRING_PREFERRED_FAMILY_NAMES      equ     13
DWRITE_INFORMATIONAL_STRING_PREFERRED_SUBFAMILY_NAMES   equ     14
DWRITE_INFORMATIONAL_STRING_SAMPLE_TEXT                 equ     15
DWRITE_INFORMATIONAL_STRING_FULL_NAME                   equ     16
DWRITE_INFORMATIONAL_STRING_POSTSCRIPT_NAME             equ     17
DWRITE_INFORMATIONAL_STRING_POSTSCRIPT_CID_NAME         equ     18

;DWRITE_FACTORY_TYPE enumeration
DWRITE_FACTORY_TYPE_SHARED                              equ     0
DWRITE_FACTORY_TYPE_ISOLATED                            equ     1

;DWRITE_PIXEL_GEOMETRY enumeration
DWRITE_PIXEL_GEOMETRY_FLAT                              equ     0
DWRITE_PIXEL_GEOMETRY_RGB                               equ     1
DWRITE_PIXEL_GEOMETRY_BGR                               equ     2

;DWRITE_RENDERING_MODE enumeration
DWRITE_RENDERING_MODE_DEFAULT                           equ     0
DWRITE_RENDERING_MODE_ALIASED                           equ     1
DWRITE_RENDERING_MODE_GDI_CLASSIC                       equ     2
DWRITE_RENDERING_MODE_GDI_NATURAL                       equ     3
DWRITE_RENDERING_MODE_NATURAL                           equ     4
DWRITE_RENDERING_MODE_NATURAL_SYMMETRIC                 equ     5
DWRITE_RENDERING_MODE_OUTLINE                           equ     6
DWRITE_RENDERING_MODE_CLEARTYPE_GDI_CLASSIC             equ     DWRITE_RENDERING_MODE_GDI_CLASSIC
DWRITE_RENDERING_MODE_CLEARTYPE_GDI_NATURAL             equ     DWRITE_RENDERING_MODE_GDI_NATURAL
DWRITE_RENDERING_MODE_CLEARTYPE_NATURAL                 equ     DWRITE_RENDERING_MODE_NATURAL
DWRITE_RENDERING_MODE_CLEARTYPE_NATURAL_SYMMETRIC       equ     DWRITE_RENDERING_MODE_NATURAL_SYMMETRIC
;
;DWRITE_READING_DIRECTION enumeration
DWRITE_READING_DIRECTION_LEFT_TO_RIGHT                  equ     0
DWRITE_READING_DIRECTION_RIGHT_TO_LEFT                  equ     1

;DWRITE_FLOW_DIRECTION enumeration
DWRITE_FLOW_DIRECTION_TOP_TO_BOTTOM                     equ     0

;DWRITE_TEXT_ALIGNMENT enumeration
DWRITE_TEXT_ALIGNMENT_LEADING                           equ     0
DWRITE_TEXT_ALIGNMENT_TRAILING                          equ     1
DWRITE_TEXT_ALIGNMENT_CENTER                            equ     2

;DWRITE_PARAGRAPH_ALIGNMENT enumeration
DWRITE_PARAGRAPH_ALIGNMENT_NEAR                         equ     0
DWRITE_PARAGRAPH_ALIGNMENT_FAR                          equ     1
DWRITE_PARAGRAPH_ALIGNMENT_CENTER                       equ     2

;DWRITE_WORD_WRAPPING enumeration
DWRITE_WORD_WRAPPING_WRAP                               equ     0
DWRITE_WORD_WRAPPING_NO_WRAP                            equ     1

;DWRITE_LINE_SPACING_METHOD enumeration
DWRITE_LINE_SPACING_METHOD_DEFAULT                      equ     0
DWRITE_LINE_SPACING_METHOD_UNIFORM                      equ     1

;DWRITE_TRIMMING_GRANULARITY enumeration
DWRITE_TRIMMING_GRANULARITY_NONE                        equ     0
DWRITE_TRIMMING_GRANULARITY_CHARACTER                   equ     1
DWRITE_TRIMMING_GRANULARITY_WORD                        equ     2

;DWRITE_FONT_FEATURE_TAG enumeration
DWRITE_FONT_FEATURE_TAG_ALTERNATIVE_FRACTIONS           equ     0063726661H ;'afrc'
DWRITE_FONT_FEATURE_TAG_PETITE_CAPITALS_FROM_CAPITALS   equ     0063703263H ;'c2pc'
DWRITE_FONT_FEATURE_TAG_SMALL_CAPITALS_FROM_CAPITALS    equ     0063733263H ;'c2sc'
DWRITE_FONT_FEATURE_TAG_CONTEXTUAL_ALTERNATES           equ     00746C6163H ;'calt'
DWRITE_FONT_FEATURE_TAG_CASE_SENSITIVE_FORMS            equ     0065736163H ;'case'
DWRITE_FONT_FEATURE_TAG_GLYPH_COMPOSITION_DECOMPOSITION equ     00706D6363H ;'ccmp'
DWRITE_FONT_FEATURE_TAG_CONTEXTUAL_LIGATURES            equ     0067696C63H ;'clig'
DWRITE_FONT_FEATURE_TAG_CAPITAL_SPACING                 equ     0070737063H ;'cpsp'
DWRITE_FONT_FEATURE_TAG_CONTEXTUAL_SWASH                equ     0068777363H ;'cswh'
DWRITE_FONT_FEATURE_TAG_CURSIVE_POSITIONING             equ     0073727563H ;'curs'
DWRITE_FONT_FEATURE_TAG_DEFAULT                         equ     00746c6664H ;'dflt'
DWRITE_FONT_FEATURE_TAG_DISCRETIONARY_LIGATURES         equ     0067696c64H ;'dlig'
DWRITE_FONT_FEATURE_TAG_EXPERT_FORMS                    equ     0074707865H ;'expt'
DWRITE_FONT_FEATURE_TAG_FRACTIONS                       equ     0063617266H ;'frac'
DWRITE_FONT_FEATURE_TAG_FULL_WIDTH                      equ     0064697766H ;'fwid'
DWRITE_FONT_FEATURE_TAG_HALF_FORMS                      equ     00666C6168H ;'half'
DWRITE_FONT_FEATURE_TAG_HALANT_FORMS                    equ     006e6c6168H ;'haln'
DWRITE_FONT_FEATURE_TAG_ALTERNATE_HALF_WIDTH            equ     00746c6168H ;'halt'
DWRITE_FONT_FEATURE_TAG_HISTORICAL_FORMS                equ     0074736968H ;'hist'
DWRITE_FONT_FEATURE_TAG_HORIZONTAL_KANA_ALTERNATES      equ     00616e6b68H ;'hkna'
DWRITE_FONT_FEATURE_TAG_HISTORICAL_LIGATURES            equ     0067696c68H ;'hlig'
DWRITE_FONT_FEATURE_TAG_HALF_WIDTH                      equ     0064697768H ;'hwid'
DWRITE_FONT_FEATURE_TAG_HOJO_KANJI_FORMS                equ     006f6a6f68H ;'hojo'
DWRITE_FONT_FEATURE_TAG_JIS04_FORMS                     equ     003430706aH ;'jp04'
DWRITE_FONT_FEATURE_TAG_JIS78_FORMS                     equ     003837706aH ;'jp78'
DWRITE_FONT_FEATURE_TAG_JIS83_FORMS                     equ     003338706aH ;'jp83'
DWRITE_FONT_FEATURE_TAG_JIS90_FORMS                     equ     003039706aH ;'jp90'
DWRITE_FONT_FEATURE_TAG_KERNING                         equ     006e72656bH ;'kern'
DWRITE_FONT_FEATURE_TAG_STANDARD_LIGATURES              equ     006167696cH ;'liga'
DWRITE_FONT_FEATURE_TAG_LINING_FIGURES                  equ     006d756e6cH ;'lnum'
DWRITE_FONT_FEATURE_TAG_LOCALIZED_FORMS                 equ     006c636f6cH ;'locl'
DWRITE_FONT_FEATURE_TAG_MARK_POSITIONING                equ     006b72616dH ;'mark'
DWRITE_FONT_FEATURE_TAG_MATHEMATICAL_GREEK              equ     006b72676dH ;'mgrk'
DWRITE_FONT_FEATURE_TAG_MARK_TO_MARK_POSITIONING        equ     006b6d6b6dH ;'mkmk'
DWRITE_FONT_FEATURE_TAG_ALTERNATE_ANNOTATION_FORMS      equ     00746c616eH ;'nalt'
DWRITE_FONT_FEATURE_TAG_NLC_KANJI_FORMS                 equ     006b636c6eH ;'nlck'
DWRITE_FONT_FEATURE_TAG_OLD_STYLE_FIGURES               equ     006d756e6fH ;'onum'
DWRITE_FONT_FEATURE_TAG_ORDINALS                        equ     006e64726fH ;'ordn'
DWRITE_FONT_FEATURE_TAG_PROPORTIONAL_ALTERNATE_WIDTH    equ     00746c6170H ;'palt'
DWRITE_FONT_FEATURE_TAG_PETITE_CAPITALS                 equ     0070616370H ;'pcap'
DWRITE_FONT_FEATURE_TAG_PROPORTIONAL_FIGURES            equ     006d756e70H ;'pnum'
DWRITE_FONT_FEATURE_TAG_PROPORTIONAL_WIDTHS             equ     0064697770H ;'pwid'
DWRITE_FONT_FEATURE_TAG_QUARTER_WIDTHS                  equ     0064697771H ;'qwid'
DWRITE_FONT_FEATURE_TAG_REQUIRED_LIGATURES              equ     0067696c72H ;'rlig'
DWRITE_FONT_FEATURE_TAG_RUBY_NOTATION_FORMS             equ     0079627572H ;'ruby'
DWRITE_FONT_FEATURE_TAG_STYLISTIC_ALTERNATES            equ     00746c6173H ;'salt'
DWRITE_FONT_FEATURE_TAG_SCIENTIFIC_INFERIORS            equ     00666e6973H ;'sinf'
DWRITE_FONT_FEATURE_TAG_SMALL_CAPITALS                  equ     0070636d73H ;'smcp'
DWRITE_FONT_FEATURE_TAG_SIMPLIFIED_FORMS                equ     006c706d73H ;'smpl'
DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_1                 equ     0031307373H ;'ss01'
DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_2                 equ     0032307373H ;'ss02'
DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_3                 equ     0033307373H ;'ss03'
DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_4                 equ     0034307373H ;'ss04'
DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_5                 equ     0035307373H ;'ss05'
DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_6                 equ     0036307373H ;'ss06'
DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_7                 equ     0037307373H ;'ss07'
DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_8                 equ     0038307373H ;'ss08'
DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_9                 equ     0039307373H ;'ss09'
DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_10                equ     0030317373H ;'ss10'
DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_11                equ     0031317373H ;'ss11'
DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_12                equ     0032317373H ;'ss12'
DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_13                equ     0033317373H ;'ss13'
DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_14                equ     0034317373H ;'ss14'
DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_15                equ     0035317373H ;'ss15'
DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_16                equ     0036317373H ;'ss16'
DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_17                equ     0037317373H ;'ss17'
DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_18                equ     0038317373H ;'ss18'
DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_19                equ     0039317373H ;'ss19'
DWRITE_FONT_FEATURE_TAG_STYLISTIC_SET_20                equ     0030327373H ;'ss20'
DWRITE_FONT_FEATURE_TAG_SUBSCRIPT                       equ     0073627573H ;'subs'
DWRITE_FONT_FEATURE_TAG_SUPERSCRIPT                     equ     0073707573H ;'sups'
DWRITE_FONT_FEATURE_TAG_SWASH                           equ     0068737773H ;'swsh'
DWRITE_FONT_FEATURE_TAG_TITLING                         equ     006c746974H ;'titl'
DWRITE_FONT_FEATURE_TAG_TRADITIONAL_NAME_FORMS          equ     006D616E74H ;'tnam'
DWRITE_FONT_FEATURE_TAG_TABULAR_FIGURES                 equ     006D756E74H ;'tnum'
DWRITE_FONT_FEATURE_TAG_TRADITIONAL_FORMS               equ     0064617274H ;'trad'
DWRITE_FONT_FEATURE_TAG_THIRD_WIDTHS                    equ     0064697774H ;'twid'
DWRITE_FONT_FEATURE_TAG_UNICASE                         equ     0063696E75H ;'unic'
DWRITE_FONT_FEATURE_TAG_SLASHED_ZERO                    equ     006F72657AH ;'zero'

;DWRITE_SCRIPT_SHAPES enumeration
DWRITE_SCRIPT_SHAPES_DEFAULT                            equ     0
DWRITE_SCRIPT_SHAPES_NO_VISUAL                          equ     1

;DWRITE_BREAK_CONDITION enumeration
DWRITE_BREAK_CONDITION_NEUTRAL                          equ     0
DWRITE_BREAK_CONDITION_CAN_BREAK                        equ     1
DWRITE_BREAK_CONDITION_MAY_NOT_BREAK                    equ     2
DWRITE_BREAK_CONDITION_MUST_BREAK                       equ     3

;DWRITE_NUMBER_SUBSTITUTION_METHOD enumeration
DWRITE_NUMBER_SUBSTITUTION_METHOD_FROM_CULTURE          equ     0
DWRITE_NUMBER_SUBSTITUTION_METHOD_CONTEXTUAL            equ     1
DWRITE_NUMBER_SUBSTITUTION_METHOD_NONE                  equ     2
DWRITE_NUMBER_SUBSTITUTION_METHOD_NATIONAL              equ     3
DWRITE_NUMBER_SUBSTITUTION_METHOD_TRADITIONAL           equ     4

;DWRITE_TEXTURE_TYPE enumeration
DWRITE_TEXTURE_ALIASED_1x1                              equ     0
DWRITE_TEXTURE_CLEARTYPE_3x1                            equ     1

;======================================== Structures ======================================;
struct DWRITE_FONT_METRICS
       designUnitsPerEm       dw ?
       ascent                 dw ?
       descent                dw ?
       lineGap                dw ?
       capHeight              dw ?
       xHeight                dw ?
       underlinePosition      dw ?
       underlineThickness     dw ?
       strikethroughPosition  dw ?
       strikethroughThickness dw ?
ends

struct DWRITE_GLYPH_METRICS
       leftSideBearing   dd ?
       advanceWidth      dd ?
       rightSideBearing  dd ?
       topSideBearing    dd ?
       advanceHeight     dd ?
       bottomSideBearing dd ?
       verticalOriginY   dd ?
ends

struct DWRITE_GLYPH_OFFSET
       advanceOffset  dd ?
       ascenderOffset dd ?
ends

struct DWRITE_MATRIX
       m11 dd ?
       m12 dd ?
       m21 dd ?
       m22 dd ?
       dx_ dd ?
       dy  dd ?
ends

struct DWRITE_TEXT_RANGE
       startPosition dd ?
       length_       dd ?
ends

struct DWRITE_FONT_FEATURE
       nameTag   dd ? ;DWRITE_FONT_FEATURE_TAG
       parameter dd ?
ends

struct DWRITE_TYPOGRAPHIC_FEATURES
       features      xptr ?
       featureCount_ dd   ?
ends

struct DWRITE_TRIMMING
       granularity     dd ? ;DWRITE_TRIMMING_GRANULARITY
       delimiter_      dd ?
       delimiterCount_ dd ?
ends

struct DWRITE_SCRIPT_ANALYSIS
       script dw ?
       shapes dd ? ;DWRITE_SCRIPT_SHAPES
ends

struct DWRITE_LINE_BREAKPOINT
      breakConditionBefore db ? ;:2
      breakConditionAfter  db ? ;:2
      isWhitespace         db ? ;:1
      isSoftHyphen         db ? ;:1
      padding              db ? ;:2
ends

struct DWRITE_SHAPING_TEXT_PROPERTIES
      isShapedAlone dw ? ;:1
      reserved      dw ? ;:15
ends

struct DWRITE_SHAPING_GLYPH_PROPERTIES
      justification    dw ? ;:4
      isClusterStart   dw ? ;:1
      isDiacritic      dw ? ;:1
      isZeroWidthSpace dw ? ;:1
      reserved         dw ? ;:9
ends

struct DWRITE_GLYPH_RUN
      fontFace      xptr ? ;__notnull IDWriteFontFace *
      fontEmSize    dd   ?
      lyphCount     dd   ?
      glyphIndices  dw   ? ;__field_ecount(glyphCount) dw const *
      glyphAdvances dd   ? ;__field_ecount_opt(glyphCount) dd const *
      glyphOffsets  xptr ? ;__field_ecount_opt(glyphCount) DWRITE_GLYPH_OFFSET const *
      isSideways    dd   ?
      bidiLevel     dd   ?
ends

struct DWRITE_GLYPH_RUN_DESCRIPTION
      localeName   xptr ? ;__nullterminated WCHAR const *
      string       xptr ? ;__field_ecount(stringLength) WCHAR const *
      stringLength dd   ?
      clusterMap   dw   ? ;__field_ecount(stringLength) dw const *
      textPosition dd   ?
ends

struct DWRITE_UNDERLINE
      width_           dd   ?
      thickness        dd   ?
      offset_          dd   ?
      runHeight        dd   ?
      readingDirection dd   ? ;DWRITE_READING_DIRECTION
      flowDirection    dd   ? ;DWRITE_FLOW_DIRECTION
      localeName       xptr ? ;__nullterminated WCHAR const *
      measuringMode    dd   ? ;DWRITE_MEASURING_MODE
ends

struct DWRITE_STRIKETHROUGH
      width_           dd   ?
      thickness        dd   ?
      offset_          dd   ?
      readingDirection dd   ? ;DWRITE_READING_DIRECTION
      flowDirection    dd   ? ;DWRITE_FLOW_DIRECTION
      localeName       xptr ? ;__nullterminated WCHAR const *
      measuringMode    dd   ? ;DWRITE_MEASURING_MODE
ends

struct DWRITE_LINE_METRICS
      length_                  dd ?
      trailingWhitespaceLength dd ?
      newlineLength            dd ?
      height                   dd ?
      baseline                 dd ?
      isTrimmed                dd ?
ends

struct DWRITE_CLUSTER_METRICS
      width_           dd ?
      length_          dw ?
      canWrapLineAfter dw ? ;:1
      isWhitespace     dw ? ;:1
      isNewline        dw ? ;:1
      isSoftHyphen     dw ? ;:1
      isRightToLeft    dw ? ;:1
      padding          dw ? ;:11
ends

struct DWRITE_TEXT_METRICS
      left                             dd ?
      top                              dd ?
      width_                           dd ?
      widthIncludingTrailingWhitespace dd ?
      height                           dd ?
      layoutWidth                      dd ?
      layoutHeight                     dd ?
      maxBidiReorderingDepth           dd ?
      lineCount                        dd ?
ends

struct DWRITE_INLINE_OBJECT_METRICS
      width_           dd ?
      height           dd ?
      baseline         dd ?
      supportsSideways dd ?
ends

struct DWRITE_OVERHANG_METRICS
      left   dd ?
      top    dd ?
      right  dd ?
      bottom dd ?
ends

struct DWRITE_HIT_TEST_METRICS
      textPosition dd ?
      length_      dd ?
      left         dd ?
      top          dd ?
      width_       dd ?
      height       dd ?
      bidiLeve     dd ?
      isText       dd ?
      isTrimmed    dd ?
ends

interface IDWriteBitmapRenderTargetVtbl,\
    QueryInterface,\
    AddRef,\
    Release_,\
    DrawGlyphRun,\
    GetMemoryDC,\
    GetPixelsPerDip,\
    SetPixelsPerDip,\
    GetCurrentTransform,\
    SetCurrentTransform,\
    GetSize,\
    Resize

interface IDWriteFactoryVtbl,\
    QueryInterface,\
    AddRef,\
    Release_,\
    GetSystemFontCollection,\
    CreateCustomFontCollection,\
    RegisterFontCollectionLoader,\
    UnregisterFontCollectionLoader,\
    CreateFontFileReference,\
    CreateCustomFontFileReference,\
    CreateFontFace,\
    CreateRenderingParams,\
    CreateMonitorRenderingParams,\
    CreateCustomRenderingParams,\
    RegisterFontFileLoader,\
    UnregisterFontFileLoader,\
    CreateTextFormat,\
    CreateTypography,\
    GetGdiInterop,\
    CreateTextLayout,\
    CreateGdiCompatibleTextLayout,\
    CreateEllipsisTrimmingSign,\
    CreateTextAnalyzer,\
    CreateNumberSubstitution,\
    CreateGlyphRunAnalysis

interface IDWriteFontVtbl,\
    QueryInterface,\
    AddRef,\
    Release_,\
    GetFontFamily,\
    GetWeight,\
    GetStretch,\
    GetStyle,\
    IsSymbolFont,\
    GetFaceNames,\
    GetInformationalStrings,\
    GetSimulations,\
    GetMetrics,\
    HasCharacter,\
    CreateFontFace

interface IDWriteFontCollectionVtbl,\
    QueryInterface,\
    AddRef,\
    Release_,\
    GetFontFamilyCount,\
    GetFontFamily,\
    FindFamilyName,\
    GetFontFromFontFace

interface IDWriteFontFaceVtbl,\
    QueryInterface,\
    AddRef,\
    Release_,\
    GetType,\
    GetFiles,\
    GetIndex,\
    GetSimulations,\
    IsSymbolFont,\
    GetMetrics,\
    GetGlyphCount,\
    GetDesignGlyphMetrics,\
    GetGlyphIndices,\
    TryGetFontTable,\
    ReleaseFontTable,\
    GetGlyphRunOutline,\
    GetRecommendedRenderingMode,\
    GetGdiCompatibleMetrics,\
    GetGdiCompatibleGlyphMetrics

interface IDWriteFontListVtbl,\
    QueryInterface,\
    AddRef,\
    Release_,\
    GetFontCollection,\
    GetFontCount,\
    GetFont

interface IDWriteFontFamilyVtbl,\
    QueryInterface,\
    AddRef,\
    Release_,\
    GetFontCollection,\
    GetFontCount,\
    GetFont,\
    GetFamilyNames,\
    GetFirstMatchingFont,\
    GetMatchingFonts

interface IDWriteFontFileVtbl,\
    QueryInterface,\
    AddRef,\
    Release_,\
    GetReferenceKey,\
    GetLoader,\
    Analyze

interface IDWriteFontFileLoaderVtbl,\
    QueryInterface,\
    AddRef,\
    Release_,\
    CreateStreamFromKey

interface IDWriteFontFileStreamVtbl,\
    QueryInterface,\
    AddRef,\
    Release_,\
    ReadFileFragment,\
    ReleaseFileFragment,\
    GetFileSize,\
    GetLastWriteTime

interface IDWriteFontCollectionLoaderVtbl,\
    QueryInterface,\
    AddRef,\
    Release_,\
    CreateEnumeratorFromKey

interface IDWriteFontFileEnumeratorVtbl,\
    QueryInterface,\
    AddRef,\
    Release_,\
    MoveNext,\
    GetCurrentFontFile

interface IDWriteGdiInteropVtbl,\
    QueryInterface,\
    AddRef,\
    Release_,\
    CreateFontFromLOGFONT,\
    ConvertFontToLOGFONT,\
    ConvertFontFaceToLOGFONT,\
    CreateFontFaceFromHdc,\
    CreateBitmapRenderTarget

interface IDWriteGlyphRunAnalysisVtbl,\
    QueryInterface,\
    AddRef,\
    Release_,\
    GetAlphaTextureBounds,\
    CreateAlphaTexture,\
    GetAlphaBlendParams

interface IDWriteInlineObjectVtbl,\
    QueryInterface,\
    AddRef,\
    Release_,\
    Draw,\
    GetMetrics,\
    GetOverhangMetrics,\
    GetBreakConditions

interface IDWriteLocalFontFileLoaderVtbl,\
    QueryInterface,\
    AddRef,\
    Release_,\
    CreateStreamFromKey,\
    GetFilePathLengthFromKey,\
    GetFilePathFromKey,\
    GetLastWriteTimeFromKey

interface IDWriteLocalizedStringsVtbl,\
    QueryInterface,\
    AddRef,\
    Release_,\
    GetCount,\
    FindLocaleName,\
    GetLocaleNameLength,\
    GetLocaleName,\
    GetStringLength,\
    GetString

interface IDWriteNumberSubstitutionVtbl,\
    QueryInterface,\
    AddRef,\
    Release

interface IDWritePixelSnappingVtbl,\
    QueryInterface,\
    AddRef,\
    Release_,\
    IsPixelSnappingDisabled,\
    GetCurrentTransform,\
    GetPixelsPerDip

interface IDWriteRenderingParamsVtbl,\
    QueryInterface,\
    AddRef,\
    Release_,\
    GetGamma,\
    GetEnhancedContrast,\
    GetClearTypeLevel,\
    GetPixelGeometry,\
    GetRenderingMode

interface IDWriteTextAnalysisSinkVtbl,\
    QueryInterface,\
    AddRef,\
    Release_,\
    SetScriptAnalysis,\
    SetLineBreakpoints,\
    SetBidiLevel,\
    SetNumberSubstitution

interface IDWriteTextAnalysisSourceVtbl,\
    QueryInterface,\
    AddRef,\
    Release_,\
    GetTextAtPosition,\
    GetTextBeforePosition,\
    GetParagraphReadingDirection,\
    GetLocaleName,\
    GetNumberSubstitution

interface IDWriteTextAnalyzerVtbl,\
    QueryInterface,\
    AddRef,\
    Release_,\
    AnalyzeScript,\
    AnalyzeBidi,\
    AnalyzeNumberSubstitution,\
    AnalyzeLineBreakpoints,\
    GetGlyphs,\
    GetGlyphPlacements,\
    GetGdiCompatibleGlyphPlacements

interface IDWriteTextFormatVtbl,\
    QueryInterface,\
    AddRef,\
    Release_,\
    SetTextAlignment,\
    SetParagraphAlignment,\
    SetWordWrapping,\
    SetReadingDirection,\
    SetFlowDirection,\
    SetIncrementalTabStop,\
    SetTrimming,\
    SetLineSpacing,\
    GetTextAlignment,\
    GetParagraphAlignment,\
    GetWordWrapping,\
    GetReadingDirection,\
    GetFlowDirection,\
    GetIncrementalTabStop,\
    GetTrimming,\
    GetLineSpacing,\
    GetFontCollection,\
    GetFontFamilyNameLength,\
    GetFontFamilyName,\
    GetFontWeight,\
    GetFontStyle,\
    GetFontStretch,\
    GetFontSize,\
    GetLocaleNameLength,\
    GetLocaleName

interface IDWriteTextLayoutVtbl,\
    QueryInterface,\
    AddRef,\
    Release_,\
    SetTextAlignment,\
    SetParagraphAlignment,\
    SetWordWrapping,\
    SetReadingDirection,\
    SetFlowDirection,\
    SetIncrementalTabStop,\
    SetTrimming,\
    SetLineSpacing,\
    GetTextAlignment,\
    GetParagraphAlignment,\
    GetWordWrapping,\
    GetReadingDirection,\
    GetFlowDirection,\
    GetIncrementalTabStop,\
    GetTrimming,\
    GetLineSpacing,\
    GetFontCollection,\
    GetFontFamilyNameLength,\
    GetFontFamilyName,\
    GetFontWeight,\
    GetFontStyle,\
    GetFontStretch,\
    GetFontSize,\
    GetLocaleNameLength,\
    GetLocaleName,\
    SetMaxWidth,\
    SetMaxHeight,\
    SetFontCollection,\
    SetFontFamilyName,\
    SetFontWeight,\
    SetFontStyle,\
    SetFontStretch,\
    SetFontSize,\
    SetUnderline,\
    SetStrikethrough,\
    SetDrawingEffect,\
    SetInlineObject,\
    SetTypography,\
    SetLocaleName,\
    GetMaxWidth,\
    GetMaxHeight,\
    GetFontCollection_,\
    GetFontFamilyNameLength_,\
    GetFontFamilyName_,\
    GetFontWeight_,\
    GetFontStyle_,\
    GetFontStretch_,\
    GetFontSize_,\
    GetUnderline,\
    GetStrikethrough,\
    GetDrawingEffect,\
    GetInlineObject,\
    GetTypography,\
    GetLocaleNameLength_,\
    GetLocaleName_,\
    Draw,\
    GetLineMetrics,\
    GetMetrics,\
    GetOverhangMetrics,\
    GetClusterMetrics,\
    DetermineMinWidth,\
    HitTestPoint,\
    HitTestTextPosition,\
    HitTestTextRange

interface IDWriteTextRendererVtbl,\
    QueryInterface,\
    AddRef,\
    Release_,\
    IsPixelSnappingDisabled,\
    GetCurrentTransform,\
    GetPixelsPerDip,\
    DrawGlyphRun,\
    DrawUnderline,\
    DrawStrikethrough,\
    DrawInlineObject

interface IDWriteTypographyVtbl,\
    QueryInterface,\
    AddRef,\
    Release_,\
    AddFontFeature,\
    GetFontFeatureCount,\
    GetFontFeature

;======================================== Functions =======================================;
;======== WARNING!!: This include file is only valid for 64-bit ========
;======== projects since 'DWrite.lib' is not included in MASM32 ========
import DWrite,\
    DWriteCreateFactory,'DWriteCreateFactory'

;====================================== GUID values =======================================;
.data
IDWriteFontFileLoader          GUID    0727CAD4EH, 0D6AFH, 04C9EH, <08AH, 008H, 0D6H, 095H, 0B1H, 01CH, 0AAH, 049H>
IDWriteLocalFontFileLoader     GUID    0B2D9F3ECH, 0C9FEH, 04A11H, <0A2H, 0ECH, 0D8H, 062H, 008H, 0F7H, 0C0H, 0A2H>
IDWriteFontFileStream          GUID    06D4865FEH, 00AB8H, 04D91H, <08FH, 062H, 05DH, 0D6H, 0BEH, 034H, 0A3H, 0E0H>
IDWriteFontFile                GUID    0739D886AH, 0CEF5H, 047DCH, <087H, 069H, 01AH, 08BH, 041H, 0BEH, 0BBH, 0B0H>
IDWriteRenderingParams         GUID    02F0DA53AH, 02ADDH, 047CDH, <082H, 0EEH, 0D9H, 0ECH, 034H, 068H, 08EH, 075H>
IDWriteFontFace                GUID    05F49804DH, 07024H, 04D43H, <0BFH, 0A9H, 0D2H, 059H, 084H, 0F5H, 038H, 049H>
IDWriteFontCollectionLoader    GUID    0CCA920E4H, 052F0H, 0492BH, <0BFH, 0A8H, 029H, 0C7H, 02EH, 0E0H, 0A4H, 068H> 
IDWriteFontFileEnumerator      GUID    072755049H, 05FF7H, 0435DH, <083H, 048H, 04BH, 0E9H, 07CH, 0FAH, 06CH, 07CH>
IDWriteLocalizedStrings        GUID    008256209H, 0099AH, 04B34H, <0B8H, 06DH, 0C2H, 02BH, 011H, 00EH, 077H, 071H>
IDWriteFontCollection          GUID    0A84CEE02H, 03EEAH, 04EEEH, <0A8H, 027H, 087H, 0C1H, 0A0H, 02AH, 00FH, 0CCH>
IDWriteFontList                GUID    01A0D8438H, 01D97H, 04EC1H, <0AEH, 0F9H, 0A2H, 0FBH, 086H, 0EDH, 06AH, 0CBH>
IDWriteFontFamily              GUID    0DA20D8EFH, 0812AH, 04C43H, <098H, 002H, 062H, 0ECH, 04AH, 0BDH, 07AH, 0DDH>
IDWriteFont                    GUID    0ACD16696H, 08C14H, 04F5DH, <087H, 07EH, 0FEH, 03FH, 0C1H, 0D3H, 027H, 037H>
IDWriteTextFormat              GUID    09C906818H, 031D7H, 04FD3H, <0A1H, 051H, 07CH, 05EH, 022H, 05DH, 0B5H, 05AH>
IDWriteTypography              GUID    055F1112BH, 01DC2H, 04B3CH, <095H, 041H, 0F4H, 068H, 094H, 0EDH, 085H, 0B6H>
IDWriteTextAnalyzer            GUID    0B7E6163EH, 07F46H, 043B4H, <084H, 0B3H, 0E4H, 0E6H, 024H, 09CH, 036H, 05DH>
IDWriteInlineObject            GUID    08339FDE3H, 0106FH, 047ABH, <083H, 073H, 01CH, 062H, 095H, 0EBH, 010H, 0B3H>
IDWritePixelSnapping           GUID    0EAF3A2DAH, 0ECF4H, 04D24H, <0B6H, 044H, 0B3H, 04FH, 068H, 042H, 002H, 04BH>
IDWriteTextRenderer            GUID    0EF8A8135H, 05CC6H, 045FEH, <088H, 025H, 0C5H, 0A0H, 072H, 04EH, 0B8H, 019H>
IDWriteTextLayout              GUID    053737037H, 06D14H, 0410BH, <09BH, 0FEH, 00BH, 018H, 02BH, 0B7H, 009H, 061H>
IDWriteBitmapRenderTarget      GUID    05E5A32A3H, 08DFFH, 04773H, <09FH, 0F6H, 006H, 096H, 0EAH, 0B7H, 072H, 067H>
IDWriteGdiInterop              GUID    01EDD9491H, 09853H, 04299H, <089H, 08FH, 064H, 032H, 098H, 03BH, 06FH, 03AH>
IDWriteGlyphRunAnalysis        GUID    07D97DBF7H, 0E085H, 042D4H, <081H, 0E3H, 06AH, 088H, 03BH, 0DEH, 0D1H, 018H>
IDWriteFactory                 GUID    0B859EE5AH, 0D838H, 04B5BH, <0A2H, 0E8H, 01AH, 0DCH, 07DH, 093H, 0DBH, 048H>

end if ;DWRITE_INC
