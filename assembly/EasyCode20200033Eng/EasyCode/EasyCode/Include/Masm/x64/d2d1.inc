;======================================================;
;                                                      ;
;   d2d1.inc for Easy Code 2.0 64-bit Masm projects    ;
;                   (version 1.0.0)                    ;
;                                                      ;
;          Copyright © Héctor A. Medina - 2020         ;
;                                                      ;
;======================================================;

IFNDEF D2D1_INC
D2D1_INC   EQU 1

D2D1_INVALID_TAG                                EQU     ULONGLONG_MAX
D2D1_DEFAULT_FLATTENING_TOLERANCE               EQU     0.25

;enumeration 
D2D1_INTERPOLATION_MODE_DEFINITION_NEAREST_NEIGHBOR     EQU     0
D2D1_INTERPOLATION_MODE_DEFINITION_LINEAR               EQU     1
D2D1_INTERPOLATION_MODE_DEFINITION_CUBIC                EQU     2
D2D1_INTERPOLATION_MODE_DEFINITION_MULTI_SAMPLE_LINEAR  EQU     3
D2D1_INTERPOLATION_MODE_DEFINITION_ANISOTROPIC          EQU     4
D2D1_INTERPOLATION_MODE_DEFINITION_HIGH_QUALITY_CUBIC   EQU     5
D2D1_INTERPOLATION_MODE_DEFINITION_FANT                 EQU     6
D2D1_INTERPOLATION_MODE_DEFINITION_MIPMAP_LINEAR        EQU     7

;D2D1_ALPHA_MODE enumeration
D2D1_ALPHA_MODE                                 TYPEDEF DWORD
D2D1_ALPHA_MODE_UNKNOWN                         EQU     0
D2D1_ALPHA_MODE_PREMULTIPLIED                   EQU     1
D2D1_ALPHA_MODE_STRAIGHT                        EQU     2
D2D1_ALPHA_MODE_IGNORE                          EQU     3
D2D1_ALPHA_MODE_FORCE_DWORD                     EQU     0FFFFFFFFH

;D2D1_GAMMA enumeration
D2D1_GAMMA                                      TYPEDEF DWORD
D2D1_GAMMA_2_2                                  EQU     0
D2D1_GAMMA_1_0                                  EQU     1
D2D1_GAMMA_FORCE_DWORD                          EQU     0FFFFFFFFH

;D2D1_OPACITY_MASK_CONTENT enumeration
D2D1_OPACITY_MASK_CONTENT                       TYPEDEF DWORD
D2D1_OPACITY_MASK_CONTENT_GRAPHICS              EQU     0
D2D1_OPACITY_MASK_CONTENT_TEXT_NATURAL          EQU     1
D2D1_OPACITY_MASK_CONTENT_TEXT_GDI_COMPATIBLE   EQU     2
D2D1_OPACITY_MASK_CONTENT_FORCE_DWORD           EQU     0FFFFFFFFH

;D2D1_EXTEND_MODE enumeration
D2D1_EXTEND_MODE                                TYPEDEF DWORD
D2D1_EXTEND_MODE_CLAMP                          EQU     0
D2D1_EXTEND_MODE_WRAP                           EQU     1
D2D1_EXTEND_MODE_MIRROR                         EQU     2
D2D1_EXTEND_MODE_FORCE_DWORD                    EQU     0FFFFFFFFH

;D2D1_ANTIALIAS_MODE enumeration
D2D1_ANTIALIAS_MODE                             TYPEDEF DWORD
D2D1_ANTIALIAS_MODE_PER_PRIMITIVE               EQU     0
D2D1_ANTIALIAS_MODE_ALIASED                     EQU     1
D2D1_ANTIALIAS_MODE_FORCE_DWORD                 EQU     0FFFFFFFFH

;D2D1_TEXT_ANTIALIAS_MODE enumeration
D2D1_TEXT_ANTIALIAS_MODE                        TYPEDEF DWORD
D2D1_TEXT_ANTIALIAS_MODE_DEFAULT                EQU     0
D2D1_TEXT_ANTIALIAS_MODE_CLEARTYPE              EQU     1
D2D1_TEXT_ANTIALIAS_MODE_GRAYSCALE              EQU     2
D2D1_TEXT_ANTIALIAS_MODE_ALIASED                EQU     3
D2D1_TEXT_ANTIALIAS_MODE_FORCE_DWORD            EQU     0FFFFFFFFH

;D2D1_BITMAP_INTERPOLATION_MODE enumeration
D2D1_BITMAP_INTERPOLATION_MODE                  TYPEDEF DWORD
D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR EQU     D2D1_INTERPOLATION_MODE_DEFINITION_NEAREST_NEIGHBOR
D2D1_BITMAP_INTERPOLATION_MODE_LINEAR           EQU     D2D1_INTERPOLATION_MODE_DEFINITION_LINEAR
D2D1_BITMAP_INTERPOLATION_MODE_FORCE_DWORD      EQU     0FFFFFFFFH

;D2D1_DRAW_TEXT_OPTIONS enumeration
D2D1_DRAW_TEXT_OPTIONS                          TYPEDEF DWORD
D2D1_DRAW_TEXT_OPTIONS_NO_SNAP                  EQU     000000001H
D2D1_DRAW_TEXT_OPTIONS_CLIP                     EQU     000000002H
D2D1_DRAW_TEXT_OPTIONS_ENABLE_COLOR_FONT        EQU     000000004H
D2D1_DRAW_TEXT_OPTIONS_NONE                     EQU     000000000H
D2D1_DRAW_TEXT_OPTIONS_FORCE_DWORD              EQU     0FFFFFFFFH

;D2D1_ARC_SIZE enumeration
D2D1_ARC_SIZE                                   TYPEDEF DWORD
D2D1_ARC_SIZE_SMALL                             EQU     0
D2D1_ARC_SIZE_LARGE                             EQU     1
D2D1_ARC_SIZE_FORCE_DWORD                       EQU     0FFFFFFFFH

;D2D1_CAP_STYLE enumeration
D2D1_CAP_STYLE                                  TYPEDEF DWORD
D2D1_CAP_STYLE_FLAT                             EQU     0
D2D1_CAP_STYLE_SQUARE                           EQU     1
D2D1_CAP_STYLE_ROUND                            EQU     2
D2D1_CAP_STYLE_TRIANGLE                         EQU     3
D2D1_CAP_STYLE_FORCE_DWORD                      EQU     0FFFFFFFFH

;D2D1_DASH_STYLE enumeration
D2D1_DASH_STYLE                                 TYPEDEF DWORD
D2D1_DASH_STYLE_SOLID                           EQU     0
D2D1_DASH_STYLE_DASH                            EQU     1
D2D1_DASH_STYLE_DOT                             EQU     2
D2D1_DASH_STYLE_DASH_DOT                        EQU     3
D2D1_DASH_STYLE_DASH_DOT_DOT                    EQU     4
D2D1_DASH_STYLE_CUSTOM                          EQU     5
D2D1_DASH_STYLE_FORCE_DWORD                     EQU     0FFFFFFFFH

;D2D1_LINE_JOIN enumeration
D2D1_LINE_JOIN                                  TYPEDEF DWORD
D2D1_LINE_JOIN_MITER                            EQU     0
D2D1_LINE_JOIN_BEVEL                            EQU     1
D2D1_LINE_JOIN_ROUND                            EQU     2
D2D1_LINE_JOIN_MITER_OR_BEVEL                   EQU     3
D2D1_LINE_JOIN_FORCE_DWORD                      EQU     0FFFFFFFFH

;D2D1_COMBINE_MODE enumeration
D2D1_COMBINE_MODE                               TYPEDEF DWORD
D2D1_COMBINE_MODE_UNION                         EQU     0
D2D1_COMBINE_MODE_INTERSECT                     EQU     1
D2D1_COMBINE_MODE_XOR                           EQU     2
D2D1_COMBINE_MODE_EXCLUDE                       EQU     3
D2D1_COMBINE_MODE_FORCE_DWORD                   EQU     0FFFFFFFFH

;D2D1_GEOMETRY_RELATION enumeration
D2D1_GEOMETRY_RELATION                          TYPEDEF DWORD
D2D1_GEOMETRY_RELATION_UNKNOWN                  EQU     0
D2D1_GEOMETRY_RELATION_DISJOINT                 EQU     1
D2D1_GEOMETRY_RELATION_IS_CONTAINED             EQU     2
D2D1_GEOMETRY_RELATION_CONTAINS                 EQU     3
D2D1_GEOMETRY_RELATION_OVERLAP                  EQU     4
D2D1_GEOMETRY_RELATION_FORCE_DWORD              EQU     0FFFFFFFFH

;D2D1_GEOMETRY_SIMPLIFICATION_OPTION enumeration
D2D1_GEOMETRY_SIMPLIFICATION_OPTION             TYPEDEF DWORD
D2D1_GEOMETRY_SIMPLIFICATION_OPTION_CUBICS_AND_LINES EQU    0
D2D1_GEOMETRY_SIMPLIFICATION_OPTION_LINES       EQU     1
D2D1_GEOMETRY_SIMPLIFICATION_OPTION_FORCE_DWORD EQU     0FFFFFFFFH

;D2D1_FIGURE_BEGIN enumeration
D2D1_FIGURE_BEGIN                               TYPEDEF DWORD
D2D1_FIGURE_BEGIN_FILLED                        EQU     0
D2D1_FIGURE_BEGIN_HOLLOW                        EQU     1
D2D1_FIGURE_BEGIN_FORCE_DWORD                   EQU     0FFFFFFFFH

;D2D1_FIGURE_END enumeration
D2D1_FIGURE_END                                 TYPEDEF DWORD
D2D1_FIGURE_END_OPEN                            EQU     0
D2D1_FIGURE_END_CLOSED                          EQU     1
D2D1_FIGURE_END_FORCE_DWORD                     EQU     0FFFFFFFFH

;D2D1_PATH_SEGMENT enumeration
D2D1_PATH_SEGMENT                               TYPEDEF DWORD
D2D1_PATH_SEGMENT_NONE                          EQU     000000000H
D2D1_PATH_SEGMENT_FORCE_UNSTROKED               EQU     000000001H
D2D1_PATH_SEGMENT_FORCE_ROUND_LINE_JOIN         EQU     000000002H
D2D1_PATH_SEGMENT_FORCE_DWORD                   EQU     0FFFFFFFFH

;D2D1_SWEEP_DIRECTION enumeration
D2D1_SWEEP_DIRECTION                            TYPEDEF DWORD
D2D1_SWEEP_DIRECTION_COUNTER_CLOCKWISE          EQU     0
D2D1_SWEEP_DIRECTION_CLOCKWISE                  EQU     1
D2D1_SWEEP_DIRECTION_FORCE_DWORD                EQU     0FFFFFFFFH

;D2D1_FILL_MODE enumeration
D2D1_FILL_MODE                                  TYPEDEF DWORD
D2D1_FILL_MODE_ALTERNATE                        EQU     0
D2D1_FILL_MODE_WINDING                          EQU     1
D2D1_FILL_MODE_FORCE_DWORD                      EQU     0FFFFFFFFH

;D2D1_LAYER_OPTIONS enumeration
D2D1_LAYER_OPTIONS                              TYPEDEF DWORD
D2D1_LAYER_OPTIONS_NONE                         EQU     000000000H
D2D1_LAYER_OPTIONS_INITIALIZE_FOR_CLEARTYPE     EQU     000000001H
D2D1_LAYER_OPTIONS_FORCE_DWORD                  EQU     0FFFFFFFFH

;D2D1_WINDOW_STATE enumeration
D2D1_WINDOW_STATE                               TYPEDEF DWORD
D2D1_WINDOW_STATE_NONE                          EQU     00000000H
D2D1_WINDOW_STATE_OCCLUDED                      EQU     00000001H
D2D1_WINDOW_STATE_FORCE_DWORD                   EQU     0FFFFFFFFH

;D2D1_RENDER_TARGET_TYPE enumeration
D2D1_RENDER_TARGET_TYPE                         TYPEDEF DWORD
D2D1_RENDER_TARGET_TYPE_DEFAULT                 EQU     0
D2D1_RENDER_TARGET_TYPE_SOFTWARE                EQU     1
D2D1_RENDER_TARGET_TYPE_HARDWARE                EQU     2
D2D1_RENDER_TARGET_TYPE_FORCE_DWORD             EQU     0FFFFFFFFH

;D2D1_FEATURE_LEVEL enumeration
D2D1_FEATURE_LEVEL                              TYPEDEF DWORD
D2D1_FEATURE_LEVEL_DEFAULT                      EQU     0
D2D1_FEATURE_LEVEL_9                            EQU     09100H
D2D1_FEATURE_LEVEL_10                           EQU     0A000H
D2D1_FEATURE_LEVEL_FORCE_DWORD                  EQU     0FFFFFFFFH

;D2D1_RENDER_TARGET_USAGE enumeration
D2D1_RENDER_TARGET_USAGE                        TYPEDEF DWORD
D2D1_RENDER_TARGET_USAGE_NONE                   EQU     000000000H
D2D1_RENDER_TARGET_USAGE_FORCE_BITMAP_REMOTING  EQU     000000001H
D2D1_RENDER_TARGET_USAGE_GDI_COMPATIBLE         EQU     000000002H
D2D1_RENDER_TARGET_USAGE_FORCE_DWORD            EQU     0FFFFFFFFH

;D2D1_PRESENT_OPTIONS enumeration
D2D1_PRESENT_OPTIONS                            TYPEDEF DWORD
D2D1_PRESENT_OPTIONS_NONE                       EQU     000000000H
D2D1_PRESENT_OPTIONS_RETAIN_CONTENTS            EQU     000000001H
D2D1_PRESENT_OPTIONS_IMMEDIATELY                EQU     000000002H
D2D1_PRESENT_OPTIONS_FORCE_DWORD                EQU     0FFFFFFFFH

;D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS enumeration
D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS_NONE      EQU     000000000H
D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS_GDI_COMPATIBLE EQU    000000001H
D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS_FORCE_DWORD EQU   0FFFFFFFFH

;D2D1_DC_INITIALIZE_MODE enumeration
D2D1_DC_INITIALIZE_MODE                         TYPEDEF DWORD
D2D1_DC_INITIALIZE_MODE_COPY                    EQU     0
D2D1_DC_INITIALIZE_MODE_CLEAR                   EQU     1
D2D1_DC_INITIALIZE_MODE_FORCE_DWORD             EQU     0FFFFFFFFH

;D2D1_DEBUG_LEVEL enumeration
D2D1_DEBUG_LEVEL                                TYPEDEF DWORD
D2D1_DEBUG_LEVEL_NONE                           EQU     0
D2D1_DEBUG_LEVEL_ERROR                          EQU     1
D2D1_DEBUG_LEVEL_WARNING                        EQU     2
D2D1_DEBUG_LEVEL_INFORMATION                    EQU     3
D2D1_DEBUG_LEVEL_FORCE_DWORD                    EQU     0FFFFFFFFH

;D2D1_FACTORY_TYPE enumeration
D2D1_FACTORY_TYPE                               TYPEDEF DWORD
D2D1_FACTORY_TYPE_SINGLE_THREADED               EQU     0
D2D1_FACTORY_TYPE_MULTI_THREADED                EQU     1
D2D1_FACTORY_TYPE_FORCE_DWORD                   EQU     0FFFFFFFFH

DXGI_FORMAT                                     TYPEDEF DWORD

; D2D1 ERRORS
D2DERR_UNSUPPORTED_PIXEL_FORMAT                 Equ     WINCODEC_ERR_UNSUPPORTEDPIXELFORMAT
D2DERR_INSUFFICIENT_BUFFER                      Equ     ERROR_INSUFFICIENT_BUFFER
D2DERR_WRONG_STATE                              Equ     088990001H
D2DERR_NOT_INITIALIZED                          Equ     088990002H
D2DERR_UNSUPPORTED_OPERATION                    Equ     088990003H
D2DERR_SCANNER_FAILED                           Equ     088990004H
D2DERR_SCREEN_ACCESS_DENIED                     Equ     088990005H
D2DERR_DISPLAY_STATE_INVALID                    Equ     088990006H
D2DERR_ZERO_VECTOR                              Equ     088990007H
D2DERR_INTERNAL_ERROR                           Equ     088990008H
D2DERR_DISPLAY_FORMAT_NOT_SUPPORTED             Equ     088990009H
D2DERR_INVALID_CALL                             Equ     08899000AH
D2DERR_NO_HARDWARE_DEVICE                       Equ     08899000BH
D2DERR_RECREATE_TARGET                          Equ     08899000CH
D2DERR_TOO_MANY_SHADER_ELEMENTS                 Equ     08899000DH
D2DERR_SHADER_COMPILE_FAILED                    Equ     08899000EH
D2DERR_MAX_TEXTURE_SIZE_EXCEEDED                Equ     08899000FH
D2DERR_UNSUPPORTED_VERSION                      Equ     088990010H
D2DERR_BAD_NUMBER                               Equ     088990011H
D2DERR_WRONG_FACTORY                            Equ     088990012H
D2DERR_LAYER_ALREADY_IN_USE                     Equ     088990013H
D2DERR_POP_CALL_DID_NOT_MATCH_PUSH              Equ     088990014H
D2DERR_WRONG_RESOURCE_DOMAIN                    Equ     088990015H
D2DERR_PUSH_POP_UNBALANCED                      Equ     088990016H
D2DERR_RENDER_TARGET_HAS_LAYER_OR_CLIPRECT      Equ     088990017H
D2DERR_INCOMPATIBLE_BRUSH_TYPES                 Equ     088990018H
D2DERR_WIN32_ERROR                              Equ     088990019H
D2DERR_TARGET_NOT_GDI_COMPATIBLE                Equ     08899001AH
D2DERR_TEXT_EFFECT_IS_WRONG_TYPE                Equ     08899001BH
D2DERR_TEXT_RENDERER_NOT_RELEASED               Equ     08899001CH
D2DERR_EXCEEDS_MAX_BITMAP_SIZE                  Equ     08899001DH
D2DERR_INVALID_GRAPH_CONFIGURATION              Equ     08899001EH
D2DERR_INVALID_INTERNAL_GRAPH_CONFIGURATION     Equ     08899001FH
D2DERR_CYCLIC_GRAPH                             Equ     088990020H
D2DERR_BITMAP_CANNOT_DRAW                       Equ     088990021H
D2DERR_OUTSTANDING_BITMAP_REFERENCES            Equ     088990022H
D2DERR_ORIGINAL_TARGET_NOT_BOUND                Equ     088990023H
D2DERR_INVALID_TARGET                           Equ     088990024H
D2DERR_BITMAP_BOUND_AS_TARGET                   Equ     088990025H
D2DERR_INSUFFICIENT_DEVICE_CAPABILITIES         Equ     088990026H
D2DERR_INTERMEDIATE_TOO_LARGE                   Equ     088990027H
D2DERR_EFFECT_IS_NOT_REGISTERED                 Equ     088990028H
D2DERR_INVALID_PROPERTY                         Equ     088990029H
D2DERR_NO_SUBPROPERTIES                         Equ     08899002AH
D2DERR_PRINT_JOB_CLOSED                         Equ     08899002BH
D2DERR_PRINT_FORMAT_NOT_SUPPORTED               Equ     08899002CH
D2DERR_TOO_MANY_TRANSFORM_INPUTS                Equ     08899002DH

; D2D1_COLOR_U
AliceBlue_U                                     EQU     00F0F8FFH
AntiqueWhite_U                                  EQU     00FAEBD7H
Aqua_U                                          EQU     0000FFFFH
Aquamarine_U                                    EQU     007FFFD4H
Azure_U                                         EQU     00F0FFFFH
Beige_U                                         EQU     00F5F5DCH
Bisque_U                                        EQU     00FFE4C4H
Black_U                                         EQU     00000000H
BlanchedAlmond_U                                EQU     00FFEBCDH
Blue_U                                          EQU     000000FFH
BlueViolet_U                                    EQU     008A2BE2H
Brown_U                                         EQU     00A52A2AH
BurlyWood_U                                     EQU     00DEB887H
CadetBlue_U                                     EQU     005F9EA0H
Chartreuse_U                                    EQU     007FFF00H
Chocolate_U                                     EQU     00D2691EH
Coral_U                                         EQU     00FF7F50H
CornflowerBlue_U                                EQU     006495EDH
Cornsilk_U                                      EQU     00FFF8DCH
Crimson_U                                       EQU     00DC143CH
Cyan_U                                          EQU     0000FFFFH
DarkBlue_U                                      EQU     0000008BH
DarkCyan_U                                      EQU     00008B8BH
DarkGoldenrod_U                                 EQU     00B8860BH
DarkGray_U                                      EQU     00A9A9A9H
DarkGreen_U                                     EQU     00006400H
DarkKhaki_U                                     EQU     00BDB76BH
DarkMagenta_U                                   EQU     008B008BH
DarkOliveGreen_U                                EQU     00556B2FH
DarkOrange_U                                    EQU     00FF8C00H
DarkOrchid_U                                    EQU     009932CCH
DarkRed_U                                       EQU     008B0000H
DarkSalmon_U                                    EQU     00E9967AH
DarkSeaGreen_U                                  EQU     008FBC8FH
DarkSlateBlue_U                                 EQU     00483D8BH
DarkSlateGray_U                                 EQU     002F4F4FH
DarkTurquoise_U                                 EQU     0000CED1H
DarkViolet_U                                    EQU     009400D3H
DeepPink_U                                      EQU     00FF1493H
DeepSkyBlue_U                                   EQU     0000BFFFH
DimGray_U                                       EQU     00696969H
DodgerBlue_U                                    EQU     001E90FFH
Firebrick_U                                     EQU     00B22222H
FloralWhite_U                                   EQU     00FFFAF0H
ForestGreen_U                                   EQU     00228B22H
Fuchsia_U                                       EQU     00FF00FFH
Gainsboro_U                                     EQU     00DCDCDCH
GhostWhite_U                                    EQU     00F8F8FFH
Gold_U                                          EQU     00FFD700H
Goldenrod_U                                     EQU     00DAA520H
Gray_U                                          EQU     00808080H
Green_U                                         EQU     00008000H
GreenYellow_U                                   EQU     00ADFF2FH
Honeydew_U                                      EQU     00F0FFF0H
HotPink_U                                       EQU     00FF69B4H
IndianRed_U                                     EQU     00CD5C5CH
Indigo_U                                        EQU     004B0082H
Ivory_U                                         EQU     00FFFFF0H
Khaki_U                                         EQU     00F0E68CH
Lavender_U                                      EQU     00E6E6FAH
LavenderBlush_U                                 EQU     00FFF0F5H
LawnGreen_U                                     EQU     007CFC00H
LemonChiffon_U                                  EQU     00FFFACDH
LightBlue_U                                     EQU     00ADD8E6H
LightCoral_U                                    EQU     00F08080H
LightCyan_U                                     EQU     00E0FFFFH
LightGoldenrodYellow_U                          EQU     00FAFAD2H
LightGreen_U                                    EQU     0090EE90H
LightGray_U                                     EQU     00D3D3D3H
LightPink_U                                     EQU     00FFB6C1H
LightSalmon_U                                   EQU     00FFA07AH
LightSeaGreen_U                                 EQU     0020B2AAH
LightSkyBlue_U                                  EQU     0087CEFAH
LightSlateGray_U                                EQU     00778899H
LightSteelBlue_U                                EQU     00B0C4DEH
LightYellow_U                                   EQU     00FFFFE0H
Lime_U                                          EQU     0000FF00H
LimeGreen_U                                     EQU     0032CD32H
Linen_U                                         EQU     00FAF0E6H
Magenta_U                                       EQU     00FF00FFH
Maroon_U                                        EQU     00800000H
MediumAquamarine_U                              EQU     0066CDAAH
MediumBlue_U                                    EQU     000000CDH
MediumOrchid_U                                  EQU     00BA55D3H
MediumPurple_U                                  EQU     009370DBH
MediumSeaGreen_U                                EQU     003CB371H
MediumSlateBlue_U                               EQU     007B68EEH
MediumSpringGreen_U                             EQU     0000FA9AH
MediumTurquoise_U                               EQU     0048D1CCH
MediumVioletRed_U                               EQU     00C71585H
MidnightBlue_U                                  EQU     00191970H
MintCream_U                                     EQU     00F5FFFAH
MistyRose_U                                     EQU     00FFE4E1H
Moccasin_U                                      EQU     00FFE4B5H
NavajoWhite_U                                   EQU     00FFDEADH
Navy_U                                          EQU     00000080H
OldLace_U                                       EQU     00FDF5E6H
Olive_U                                         EQU     00808000H
OliveDrab_U                                     EQU     006B8E23H
Orange_U                                        EQU     00FFA500H
OrangeRed_U                                     EQU     00FF4500H
Orchid_U                                        EQU     00DA70D6H
PaleGoldenrod_U                                 EQU     00EEE8AAH
PaleGreen_U                                     EQU     0098FB98H
PaleTurquoise_U                                 EQU     00AFEEEEH
PaleVioletRed_U                                 EQU     00DB7093H
PapayaWhip_U                                    EQU     00FFEFD5H
PeachPuff_U                                     EQU     00FFDAB9H
Peru_U                                          EQU     00CD853FH
Pink_U                                          EQU     00FFC0CBH
Plum_U                                          EQU     00DDA0DDH
PowderBlue_U                                    EQU     00B0E0E6H
Purple_U                                        EQU     00800080H
Red_U                                           EQU     00FF0000H
RosyBrown_U                                     EQU     00BC8F8FH
RoyalBlue_U                                     EQU     004169E1H
SaddleBrown_U                                   EQU     008B4513H
Salmon_U                                        EQU     00FA8072H
SandyBrown_U                                    EQU     00F4A460H
SeaGreen_U                                      EQU     002E8B57H
SeaShell_U                                      EQU     00FFF5EEH
Sienna_U                                        EQU     00A0522DH
Silver_U                                        EQU     00C0C0C0H
SkyBlue_U                                       EQU     0087CEEBH
SlateBlue_U                                     EQU     006A5ACDH
SlateGray_U                                     EQU     00708090H
Snow_U                                          EQU     00FFFAFAH
SpringGreen_U                                   EQU     0000FF7FH
SteelBlue_U                                     EQU     004682B4H
Tan_U                                           EQU     00D2B48CH
Teal_U                                          EQU     00008080H
Thistle_U                                       EQU     00D8BFD8H
Tomato_U                                        EQU     00FF6347H
Turquoise_U                                     EQU     0040E0D0H
Violet_U                                        EQU     00EE82EEH
Wheat_U                                         EQU     00F5DEB3H
White_U                                         EQU     00FFFFFFH
WhiteSmoke_U                                    EQU     00F5F5F5H
Yellow_U                                        EQU     00FFFF00H
YellowGreen_U                                   EQU     009ACD32H

; D2D1_COLOR_F (Red/Green/Blue/Alpha)
AliceBlue_F                                     TextEqu <0.941176534, 0.972549081, 1.000000000, 1.000000000>
AntiqueWhite_F                                  TextEqu <0.980392218, 0.921568692, 0.843137324, 1.000000000>
Aqua_F                                          TextEqu <0.000000000, 1.000000000, 1.000000000, 1.000000000>
Aquamarine_F                                    TextEqu <0.498039246, 1.000000000, 0.831372619, 1.000000000>
Azure_F                                         TextEqu <0.941176534, 1.000000000, 1.000000000, 1.000000000>
Beige_F                                         TextEqu <0.960784376, 0.960784376, 0.862745166, 1.000000000>
Bisque_F                                        TextEqu <1.000000000, 0.894117713, 0.768627524, 1.000000000>
Black_F                                         TextEqu <0.000000000, 0.000000000, 0.000000000, 1.000000000>
BlanchedAlmond_F                                TextEqu <1.000000000, 0.921568692, 0.803921640, 1.000000000>
Blue_F                                          TextEqu <0.000000000, 0.000000000, 1.000000000, 1.000000000>
BlueViolet_F                                    TextEqu <0.541176498, 0.168627456, 0.886274576, 1.000000000>
Brown_F                                         TextEqu <0.647058845, 0.164705887, 0.164705887, 1.000000000>
BurlyWood_F                                     TextEqu <0.870588303, 0.721568644, 0.529411793, 1.000000000>
CadetBlue_F                                     TextEqu <0.372549027, 0.619607866, 0.627451003, 1.000000000>
Chartreuse_F                                    TextEqu <0.498039246, 1.000000000, 0.000000000, 1.000000000>
Chocolate_F                                     TextEqu <0.823529482, 0.411764741, 0.117647067, 1.000000000>
Coral_F                                         TextEqu <1.000000000, 0.498039246, 0.313725501, 1.000000000>
CornflowerBlue_F                                TextEqu <0.392156899, 0.584313750, 0.929411829, 1.000000000>
Cornsilk_F                                      TextEqu <1.000000000, 0.972549081, 0.862745166, 1.000000000>
Crimson_F                                       TextEqu <0.862745166, 0.078431375, 0.235294133, 1.000000000>
Cyan_F                                          TextEqu <0.000000000, 1.000000000, 1.000000000, 1.000000000>
DarkBlue_F                                      TextEqu <0.000000000, 0.000000000, 0.545098066, 1.000000000>
DarkCyan_F                                      TextEqu <0.000000000, 0.545098066, 0.545098066, 1.000000000>
DarkGoldenrod_F                                 TextEqu <0.721568644, 0.525490224, 0.043137256, 1.000000000>
DarkGray_F                                      TextEqu <0.662745118, 0.662745118, 0.662745118, 1.000000000>
DarkGreen_F                                     TextEqu <0.000000000, 0.392156899, 0.000000000, 1.000000000>
DarkKhaki_F                                     TextEqu <0.741176486, 0.717647076, 0.419607878, 1.000000000>
DarkMagenta_F                                   TextEqu <0.545098066, 0.000000000, 0.545098066, 1.000000000>
DarkOliveGreen_F                                TextEqu <0.333333343, 0.419607878, 0.184313729, 1.000000000>
DarkOrange_F                                    TextEqu <1.000000000, 0.549019635, 0.000000000, 1.000000000>
DarkOrchid_F                                    TextEqu <0.600000024, 0.196078449, 0.800000072, 1.000000000>
DarkRed_F                                       TextEqu <0.545098066, 0.000000000, 0.000000000, 1.000000000>
DarkSalmon_F                                    TextEqu <0.913725555, 0.588235319, 0.478431404, 1.000000000>
DarkSeaGreen_F                                  TextEqu <0.560784340, 0.737254918, 0.545098066, 1.000000000>
DarkSlateBlue_F                                 TextEqu <0.282352954, 0.239215702, 0.545098066, 1.000000000>
DarkSlateGray_F                                 TextEqu <0.184313729, 0.309803933, 0.309803933, 1.000000000>
DarkTurquoise_F                                 TextEqu <0.000000000, 0.807843208, 0.819607913, 1.000000000>
DarkViolet_F                                    TextEqu <0.580392182, 0.000000000, 0.827451050, 1.000000000>
DeepPink_F                                      TextEqu <1.000000000, 0.078431375, 0.576470613, 1.000000000>
DeepSkyBlue_F                                   TextEqu <0.000000000, 0.749019623, 1.000000000, 1.000000000>
DimGray_F                                       TextEqu <0.411764741, 0.411764741, 0.411764741, 1.000000000>
DodgerBlue_F                                    TextEqu <0.117647067, 0.564705908, 1.000000000, 1.000000000>
Firebrick_F                                     TextEqu <0.698039234, 0.133333340, 0.133333340, 1.000000000>
FloralWhite_F                                   TextEqu <1.000000000, 0.980392218, 0.941176534, 1.000000000>
ForestGreen_F                                   TextEqu <0.133333340, 0.545098066, 0.133333340, 1.000000000>
Fuchsia_F                                       TextEqu <1.000000000, 0.000000000, 1.000000000, 1.000000000>
Gainsboro_F                                     TextEqu <0.862745166, 0.862745166, 0.862745166, 1.000000000>
GhostWhite_F                                    TextEqu <0.972549081, 0.972549081, 1.000000000, 1.000000000>
Gold_F                                          TextEqu <1.000000000, 0.843137324, 0.000000000, 1.000000000>
Goldenrod_F                                     TextEqu <0.854902029, 0.647058845, 0.125490203, 1.000000000>
Gray_F                                          TextEqu <0.501960814, 0.501960814, 0.501960814, 1.000000000>
Green_F                                         TextEqu <0.000000000, 0.501960814, 0.000000000, 1.000000000>
GreenYellow_F                                   TextEqu <0.678431392, 1.000000000, 0.184313729, 1.000000000>
Honeydew_F                                      TextEqu <0.941176534, 1.000000000, 0.941176534, 1.000000000>
HotPink_F                                       TextEqu <1.000000000, 0.411764741, 0.705882370, 1.000000000>
IndianRed_F                                     TextEqu <0.803921640, 0.360784322, 0.360784322, 1.000000000>
Indigo_F                                        TextEqu <0.294117659, 0.000000000, 0.509803951, 1.000000000>
Ivory_F                                         TextEqu <1.000000000, 1.000000000, 0.941176534, 1.000000000>
Khaki_F                                         TextEqu <0.941176534, 0.901960850, 0.549019635, 1.000000000>
Lavender_F                                      TextEqu <0.901960850, 0.901960850, 0.980392218, 1.000000000>
LavenderBlush_F                                 TextEqu <1.000000000, 0.941176534, 0.960784376, 1.000000000>
LawnGreen_F                                     TextEqu <0.486274540, 0.988235354, 0.000000000, 1.000000000>
LemonChiffon_F                                  TextEqu <1.000000000, 0.980392218, 0.803921640, 1.000000000>
LightBlue_F                                     TextEqu <0.678431392, 0.847058892, 0.901960850, 1.000000000>
LightCoral_F                                    TextEqu <0.941176534, 0.501960814, 0.501960814, 1.000000000>
LightCyan_F                                     TextEqu <0.878431439, 1.000000000, 1.000000000, 1.000000000>
LightGoldenrodYellow_F                          TextEqu <0.980392218, 0.980392218, 0.823529482, 1.000000000>
LightGreen_F                                    TextEqu <0.564705908, 0.933333397, 0.564705908, 1.000000000>
LightGray_F                                     TextEqu <0.827451050, 0.827451050, 0.827451050, 1.000000000>
LightPink_F                                     TextEqu <1.000000000, 0.713725507, 0.756862819, 1.000000000>
LightSalmon_F                                   TextEqu <1.000000000, 0.627451003, 0.478431404, 1.000000000>
LightSeaGreen_F                                 TextEqu <0.125490203, 0.698039234, 0.666666687, 1.000000000>
LightSkyBlue_F                                  TextEqu <0.529411793, 0.807843208, 0.980392218, 1.000000000>
LightSlateGray_F                                TextEqu <0.466666698, 0.533333361, 0.600000024, 1.000000000>
LightSteelBlue_F                                TextEqu <0.690196097, 0.768627524, 0.870588303, 1.000000000>
LightYellow_F                                   TextEqu <1.000000000, 1.000000000, 0.878431439, 1.000000000>
Lime_F                                          TextEqu <0.000000000, 1.000000000, 0.000000000, 1.000000000>
LimeGreen_F                                     TextEqu <0.196078449, 0.803921640, 0.196078449, 1.000000000>
Linen_F                                         TextEqu <0.980392218, 0.941176534, 0.901960850, 1.000000000>
Magenta_F                                       TextEqu <1.000000000, 0.000000000, 1.000000000, 1.000000000>
Maroon_F                                        TextEqu <0.501960814, 0.000000000, 0.000000000, 1.000000000>
MediumAquamarine_F                              TextEqu <0.400000036, 0.803921640, 0.666666687, 1.000000000>
MediumBlue_F                                    TextEqu <0.000000000, 0.000000000, 0.803921640, 1.000000000>
MediumOrchid_F                                  TextEqu <0.729411781, 0.333333343, 0.827451050, 1.000000000>
MediumPurple_F                                  TextEqu <0.576470613, 0.439215720, 0.858823597, 1.000000000>
MediumSeaGreen_F                                TextEqu <0.235294133, 0.701960802, 0.443137288, 1.000000000>
MediumSlateBlue_F                               TextEqu <0.482352972, 0.407843173, 0.933333397, 1.000000000>
MediumSpringGreen_F                             TextEqu <0.000000000, 0.980392218, 0.603921592, 1.000000000>
MediumTurquoise_F                               TextEqu <0.282352954, 0.819607913, 0.800000072, 1.000000000>
MediumVioletRed_F                               TextEqu <0.780392230, 0.082352944, 0.521568656, 1.000000000>
MidnightBlue_F                                  TextEqu <0.098039225, 0.098039225, 0.439215720, 1.000000000>
MintCream_F                                     TextEqu <0.960784376, 1.000000000, 0.980392218, 1.000000000>
MistyRose_F                                     TextEqu <1.000000000, 0.894117713, 0.882353008, 1.000000000>
Moccasin_F                                      TextEqu <1.000000000, 0.894117713, 0.709803939, 1.000000000>
NavajoWhite_F                                   TextEqu <1.000000000, 0.870588303, 0.678431392, 1.000000000>
Navy_F                                          TextEqu <0.000000000, 0.000000000, 0.501960814, 1.000000000>
OldLace_F                                       TextEqu <0.992156923, 0.960784376, 0.901960850, 1.000000000>
Olive_F                                         TextEqu <0.501960814, 0.501960814, 0.000000000, 1.000000000>
OliveDrab_F                                     TextEqu <0.419607878, 0.556862772, 0.137254909, 1.000000000>
Orange_F                                        TextEqu <1.000000000, 0.647058845, 0.000000000, 1.000000000>
OrangeRed_F                                     TextEqu <1.000000000, 0.270588249, 0.000000000, 1.000000000>
Orchid_F                                        TextEqu <0.854902029, 0.439215720, 0.839215755, 1.000000000>
PaleGoldenrod_F                                 TextEqu <0.933333397, 0.909803987, 0.666666687, 1.000000000>
PaleGreen_F                                     TextEqu <0.596078455, 0.984313786, 0.596078455, 1.000000000>
PaleTurquoise_F                                 TextEqu <0.686274529, 0.933333397, 0.933333397, 1.000000000>
PaleVioletRed_F                                 TextEqu <0.858823597, 0.439215720, 0.576470613, 1.000000000>
PapayaWhip_F                                    TextEqu <1.000000000, 0.937254965, 0.835294187, 1.000000000>
PeachPuff_F                                     TextEqu <1.000000000, 0.854902029, 0.725490212, 1.000000000>
Peru_F                                          TextEqu <0.803921640, 0.521568656, 0.247058839, 1.000000000>
Pink_F                                          TextEqu <1.000000000, 0.752941251, 0.796078503, 1.000000000>
Plum_F                                          TextEqu <0.866666734, 0.627451003, 0.866666734, 1.000000000>
PowderBlue_F                                    TextEqu <0.690196097, 0.878431439, 0.901960850, 1.000000000>
Purple_F                                        TextEqu <0.501960814, 0.000000000, 0.501960814, 1.000000000>
Red_F                                           TextEqu <1.000000000, 0.000000000, 0.000000000, 1.000000000>
RosyBrown_F                                     TextEqu <0.737254918, 0.560784340, 0.560784340, 1.000000000>
RoyalBlue_F                                     TextEqu <0.254901975, 0.411764741, 0.882353008, 1.000000000>
SaddleBrown_F                                   TextEqu <0.545098066, 0.270588249, 0.074509807, 1.000000000>
Salmon_F                                        TextEqu <0.980392218, 0.501960814, 0.447058856, 1.000000000>
SandyBrown_F                                    TextEqu <0.956862807, 0.643137276, 0.376470625, 1.000000000>
SeaGreen_F                                      TextEqu <0.180392161, 0.545098066, 0.341176480, 1.000000000>
SeaShell_F                                      TextEqu <1.000000000, 0.960784376, 0.933333397, 1.000000000>
Sienna_F                                        TextEqu <0.627451003, 0.321568638, 0.176470593, 1.000000000>
Silver_F                                        TextEqu <0.752941251, 0.752941251, 0.752941251, 1.000000000>
SkyBlue_F                                       TextEqu <0.529411793, 0.807843208, 0.921568692, 1.000000000>
SlateBlue_F                                     TextEqu <0.415686309, 0.352941185, 0.803921640, 1.000000000>
SlateGray_F                                     TextEqu <0.439215720, 0.501960814, 0.564705908, 1.000000000>
Snow_F                                          TextEqu <1.000000000, 0.980392218, 0.980392218, 1.000000000>
SpringGreen_F                                   TextEqu <0.000000000, 1.000000000, 0.498039246, 1.000000000>
SteelBlue_F                                     TextEqu <0.274509817, 0.509803951, 0.705882370, 1.000000000>
Tan_F                                           TextEqu <0.823529482, 0.705882370, 0.549019635, 1.000000000>
Teal_F                                          TextEqu <0.000000000, 0.501960814, 0.501960814, 1.000000000>
Thistle_F                                       TextEqu <0.847058892, 0.749019623, 0.847058892, 1.000000000>
Tomato_F                                        TextEqu <1.000000000, 0.388235331, 0.278431386, 1.000000000>
Transparent_F                                   TextEqu <0.000000000, 0.000000000, 0.000000000, 0.000000000>
Turquoise_F                                     TextEqu <0.250980407, 0.878431439, 0.815686345, 1.000000000>
Violet_F                                        TextEqu <0.933333397, 0.509803951, 0.933333397, 1.000000000>
Wheat_F                                         TextEqu <0.960784376, 0.870588303, 0.701960802, 1.000000000>
White_F                                         TextEqu <1.000000000, 1.000000000, 1.000000000, 1.000000000>
WhiteSmoke_F                                    TextEqu <0.960784376, 0.960784376, 0.960784376, 1.000000000>
Yellow_F                                        TextEqu <1.000000000, 1.000000000, 0.000000000, 1.000000000>
YellowGreen_F                                   TextEqu <0.603921592, 0.803921640, 0.196078449, 1.000000000>

COLORU2RGB Macro COLORNUMBER
    Local result
    result = ((COLORNUMBER AND 0FFH) SHL 16) OR (COLORNUMBER AND 0FF00H) OR ((COLORNUMBER AND 0FFH) SHL 16)
    ExitM <result>
EndM

;======================================== Structures ======================================;
IFNDEF IUnknownVtbl
    IUnknownVtbl STRUCT ALIGNMODE
        QueryInterface DQ ?
        AddRef         DQ ?
        Release        DQ ?
    IUnknownVtbl ENDS
ENDIF

ID2D1ResourceVtbl STRUCT ALIGNMODE
    IUnknownVtbl <>
    GetFactory   DQ ?
ID2D1ResourceVtbl ENDS

ID2D1ImageVtbl STRUCT ALIGNMODE
    ID2D1ResourceVtbl <>
ID2D1ImageVtbl ENDS

ID2D1BitmapVtbl STRUCT ALIGNMODE
    ID2D1ImageVtbl       <>
    GetSize              DQ ?
    GetPixelSize         DQ ?
    GetPixelFormat       DQ ?
    GetDpi               DQ ?
    CopyFromBitmap       DQ ?
    CopyFromRenderTarget DQ ?
    CopyFromMemory       DQ ?
ID2D1BitmapVtbl ENDS

ID2D1GradientStopCollectionVtbl STRUCT ALIGNMODE
    ID2D1ResourceVtbl          <>
    GetGradientStopCount       DQ ?
    GetGradientStops           DQ ?
    GetColorInterpolationGamma DQ ?
    GetExtendMode              DQ ?
ID2D1GradientStopCollectionVtbl ENDS

ID2D1BrushVtbl STRUCT ALIGNMODE
    ID2D1ResourceVtbl <>
    SetOpacity        DQ ?
    SetTransform      DQ ?
    GetOpacity        DQ ?
    GetTransform      DQ ?
ID2D1BrushVtbl ENDS

ID2D1BitmapBrushVtbl STRUCT ALIGNMODE
    ID2D1BrushVtbl       <>
    SetExtendModeX       DQ ?
    SetExtendModeY       DQ ?
    SetInterpolationMode DQ ?
    SetBitmap            DQ ?
    GetExtendModeX       DQ ?
    GetExtendModeY       DQ ?
    GetInterpolationMode DQ ?
    GetBitmap            DQ ?
ID2D1BitmapBrushVtbl ENDS

ID2D1SolidColorBrushVtbl STRUCT ALIGNMODE
    ID2D1BrushVtbl <>
    SetColor       DQ ?
    GetColor       DQ ?
ID2D1SolidColorBrushVtbl ENDS

ID2D1LinearGradientBrushVtbl STRUCT ALIGNMODE
    ID2D1BrushVtbl            <>
    SetStartPoint             DQ ?
    SetEndPoint               DQ ?
    GetStartPoint             DQ ?
    GetEndPoint               DQ ?
    GetGradientStopCollection DQ ?
ID2D1LinearGradientBrushVtbl ENDS

ID2D1RadialGradientBrushVtbl STRUCT ALIGNMODE
    ID2D1BrushVtbl            <>
    SetCenter                 DQ ?
    SetGradientOriginOffset   DQ ?
    SetRadiusX                DQ ?
    SetRadiusY                DQ ?
    GetCenter                 DQ ?
    GetGradientOriginOffset   DQ ?
    GetRadiusX                DQ ?
    GetRadiusY                DQ ?
    GetGradientStopCollection DQ ?
ID2D1RadialGradientBrushVtbl ENDS

ID2D1StrokeStyleVtbl STRUCT ALIGNMODE
    ID2D1ResourceVtbl <>
    GetStartCap       DQ ?
    GetEndCap         DQ ?
    GetDashCap        DQ ?
    GetMiterLimit     DQ ?
    GetLineJoin       DQ ?
    GetDashOffset     DQ ?
    GetDashStyle      DQ ?
    GetDashesCount    DQ ?
    GetDashes         DQ ?
ID2D1StrokeStyleVtbl ENDS

ID2D1GeometryVtbl STRUCT ALIGNMODE
    ID2D1ResourceVtbl    <>
    GetBounds            DQ ?
    GetWidenedBounds     DQ ?
    StrokeContainsPoint  DQ ?
    FillContainsPoint    DQ ?
    CompareWithGeometry  DQ ?
    Simplify             DQ ?
    Tessellate           DQ ?
    CombineWithGeometry  DQ ?
    Outline              DQ ?
    ComputeArea          DQ ?
    ComputeLength        DQ ?
    ComputePointAtLength DQ ?
    Widen                DQ ?
ID2D1GeometryVtbl ENDS

ID2D1RectangleGeometryVtbl STRUCT ALIGNMODE
    ID2D1GeometryVtbl <>
    GetRect           DQ ?
ID2D1RectangleGeometryVtbl ENDS

ID2D1RoundedRectangleGeometryVtbl STRUCT ALIGNMODE
    ID2D1GeometryVtbl <>
    GetRoundedRect    DQ ?
ID2D1RoundedRectangleGeometryVtbl ENDS

ID2D1EllipseGeometryVtbl STRUCT ALIGNMODE
    ID2D1GeometryVtbl <>
    GetEllipse        DQ ?
ID2D1EllipseGeometryVtbl ENDS

ID2D1GeometryGroupVtbl STRUCT ALIGNMODE
    ID2D1GeometryVtbl      <>
    GetFillMode            DQ ?
    GetSourceGeometryCount DQ ?
    GetSourceGeometries    DQ ?
ID2D1GeometryGroupVtbl ENDS

ID2D1TransformedGeometryVtbl STRUCT ALIGNMODE
    ID2D1GeometryVtbl <>
    GetSourceGeometry DQ ?
    GetTransform      DQ ?
ID2D1TransformedGeometryVtbl ENDS

ID2D1SimplifiedGeometrySinkVtbl STRUCT ALIGNMODE
    IUnknownVtbl    <>
    SetFillMode     DQ ?
    SetSegmentFlags DQ ?
    BeginFigure     DQ ?
    AddLines        DQ ?
    AddBeziers      DQ ?
    EndFigure       DQ ?
    Close           DQ ?
ID2D1SimplifiedGeometrySinkVtbl ENDS

ID2D1GeometrySinkVtbl STRUCT ALIGNMODE
    ID2D1SimplifiedGeometrySinkVtbl <>
    AddLine                         DQ ?
    AddBezier                       DQ ?
    AddQuadraticBezier              DQ ?
    AddQuadraticBeziers             DQ ?
    AddArc                          DQ ?
ID2D1GeometrySinkVtbl ENDS

ID2D1TessellationSinkVtbl STRUCT ALIGNMODE
    IUnknownVtbl <>
    AddTriangles DQ ?
    Close        DQ ?
ID2D1TessellationSinkVtbl ENDS

ID2D1PathGeometryVtbl STRUCT ALIGNMODE
    ID2D1GeometryVtbl <>
    Open              DQ ?
    Stream            DQ ?
    GetSegmentCount   DQ ?
    GetFigureCount    DQ ?
ID2D1PathGeometryVtbl ENDS

ID2D1MeshVtbl STRUCT ALIGNMODE
    ID2D1ResourceVtbl <>
    Open              DQ ?
ID2D1MeshVtbl ENDS

ID2D1LayerVtbl STRUCT ALIGNMODE
    ID2D1ResourceVtbl <>
    GetSize           DQ ?
ID2D1LayerVtbl ENDS

ID2D1DrawingStateBlockVtbl STRUCT ALIGNMODE
    ID2D1ResourceVtbl      <>
    GetDescription         DQ ?
    SetDescription         DQ ?
    SetTextRenderingParams DQ ?
    GetTextRenderingParams DQ ?
ID2D1DrawingStateBlockVtbl ENDS

ID2D1RenderTargetVtbl STRUCT ALIGNMODE
    ID2D1ResourceVtbl            <>
    CreateBitmap                 DQ ?
    CreateBitmapFromWicBitmap    DQ ?
    CreateSharedBitmap           DQ ?
    CreateBitmapBrush            DQ ?
    CreateSolidColorBrush        DQ ?
    CreateGradientStopCollection DQ ?
    CreateLinearGradientBrush    DQ ?
    CreateRadialGradientBrush    DQ ?
    CreateCompatibleRenderTarget DQ ?
    CreateLayer                  DQ ?
    CreateMesh                   DQ ?
    DrawLine                     DQ ?
    DrawRectangle                DQ ?
    FillRectangle                DQ ?
    DrawRoundedRectangle         DQ ?
    FillRoundedRectangle         DQ ?
    DrawEllipse                  DQ ?
    FillEllipse                  DQ ?
    DrawGeometry                 DQ ?
    FillGeometry                 DQ ?
    FillMesh                     DQ ?
    FillOpacityMask              DQ ?
    DrawBitmap                   DQ ?
    DrawText_                    DQ ?
    DrawTextLayout               DQ ?
    DrawGlyphRun                 DQ ?
    SetTransform                 DQ ?
    GetTransform                 DQ ?
    SetAntialiasMode             DQ ?
    GetAntialiasMode             DQ ?
    SetTextAntialiasMode         DQ ?
    GetTextAntialiasMode         DQ ?
    SetTextRenderingParams       DQ ?
    GetTextRenderingParams       DQ ?
    SetTags                      DQ ?
    GetTags                      DQ ?
    PushLayer                    DQ ?
    PopLayer                     DQ ?
    Flush                        DQ ?
    SaveDrawingState             DQ ?
    RestoreDrawingState          DQ ?
    PushAxisAlignedClip          DQ ?
    PopAxisAlignedClip           DQ ?
    Clear                        DQ ?
    BeginDraw                    DQ ?
    EndDraw                      DQ ?
    GetPixelFormat               DQ ?
    SetDpi                       DQ ?
    GetDpi                       DQ ?
    GetSize                      DQ ?
    GetPixelSize                 DQ ?
    GetMaximumBitmapSize         DQ ?
    IsSupported                  DQ ?
ID2D1RenderTargetVtbl ENDS

ID2D1BitmapRenderTargetVtbl STRUCT ALIGNMODE
    ID2D1RenderTargetVtbl <>
    GetBitmap             DQ ?
ID2D1BitmapRenderTargetVtbl ENDS

ID2D1HwndRenderTargetVtbl STRUCT ALIGNMODE
    ID2D1RenderTargetVtbl <>
    CheckWindowState      DQ ?
    Resize                DQ ?
    GetHwnd               DQ ?
ID2D1HwndRenderTargetVtbl ENDS

ID2D1GdiInteropRenderTargetVtbl STRUCT ALIGNMODE
    IUnknownVtbl <>
    GetDC        DQ ?
    ReleaseDC    DQ ?
ID2D1GdiInteropRenderTargetVtbl ENDS

ID2D1DCRenderTargetVtbl STRUCT ALIGNMODE
    ID2D1RenderTargetVtbl <>
    BindDC                DQ ?
ID2D1DCRenderTargetVtbl ENDS

ID2D1FactoryVtbl STRUCT ALIGNMODE
;    IUnknownVtbl                   <>
    QueryInterface                 DQ ?
    AddRef                         DQ ?
    Release                        DQ ?
    ReloadSystemMetrics            DQ ?
    GetDesktopDpi                  DQ ?
    CreateRectangleGeometry        DQ ?
    CreateRoundedRectangleGeometry DQ ?
    CreateEllipseGeometry          DQ ?
    CreateGeometryGroup            DQ ?
    CreateTransformedGeometry      DQ ?
    CreatePathGeometry             DQ ?
    CreateStrokeStyle              DQ ?
    CreateDrawingStateBlock        DQ ?
    CreateWicBitmapRenderTarget    DQ ?
    CreateHwndRenderTarget         DQ ?
    CreateDxgiSurfaceRenderTarget  DQ ?
    CreateDCRenderTarget           DQ ?
ID2D1FactoryVtbl ENDS

IFNDEF D3DCOLORVALUE_DEFINED
    D3DCOLORVALUE_DEFINED   EQU <>
    D3DCOLORVALUE STRUCT ALIGNMODE
        r FLOAT ?
        g FLOAT ?
        b FLOAT ?
        a FLOAT ?
    D3DCOLORVALUE ENDS
ENDIF

D2D_POINT_2U STRUCT ALIGNMODE
    x UINT32 ?
    y UINT32 ?
D2D_POINT_2U ENDS

D2D_POINT_2F STRUCT ALIGNMODE
    x FLOAT ?
    y FLOAT ?
D2D_POINT_2F ENDS

D2D_VECTOR_3F STRUCT ALIGNMODE
    x FLOAT ?
    y FLOAT ?
    z FLOAT ?
D2D_VECTOR_3F ENDS

D2D_VECTOR_4F STRUCT ALIGNMODE
    x FLOAT ?
    y FLOAT ?
    z FLOAT ?
    w FLOAT ?
D2D_VECTOR_4F ENDS

D2D_RECT_F STRUCT ALIGNMODE
    left   FLOAT ?
    top    FLOAT ?
    right  FLOAT ?
    bottom FLOAT ?
D2D_RECT_F ENDS

D2D_RECT_U STRUCT  ALIGNMODE
    left   UINT32 ?
    top    UINT32 ?
    right  UINT32 ?
    bottom UINT32 ?
D2D_RECT_U ENDS

D2D_SIZE_F STRUCT ALIGNMODE
    width_ FLOAT ?
    height FLOAT ?
D2D_SIZE_F ENDS

D2D_SIZE_U STRUCT ALIGNMODE
    width_ UINT32 ?
    height UINT32 ?
D2D_SIZE_U ENDS

D2D_COLOR_F TYPEDEF D3DCOLORVALUE
D2D_RECT_L  TYPEDEF RECT

D2D_MATRIX_3X2_F STRUCT ALIGNMODE
    _11 FLOAT ?
    _12 FLOAT ?
    _21 FLOAT ?
    _22 FLOAT ?
    _31 FLOAT ?
    _32 FLOAT ?
D2D_MATRIX_3X2_F ENDS

D2D_MATRIX_4X3_F STRUCT ALIGNMODE
    _11 FLOAT ?
    _12 FLOAT ?
    _13 FLOAT ?
    _21 FLOAT ?
    _22 FLOAT ?
    _23 FLOAT ?
    _31 FLOAT ?
    _32 FLOAT ?
    _33 FLOAT ?
    _41 FLOAT ?
    _42 FLOAT ?
    _43 FLOAT ?
D2D_MATRIX_4X3_F ENDS

D2D_MATRIX_4X4_F STRUCT ALIGNMODE
    _11 FLOAT ?
    _12 FLOAT ?
    _13 FLOAT ?
    _14 FLOAT ?
    _21 FLOAT ?
    _22 FLOAT ?
    _23 FLOAT ?
    _24 FLOAT ?
    _31 FLOAT ?
    _32 FLOAT ?
    _33 FLOAT ?
    _34 FLOAT ?
    _41 FLOAT ?
    _42 FLOAT ?
    _43 FLOAT ?
    _44 FLOAT ?
D2D_MATRIX_4X4_F ENDS

D2D_MATRIX_5X4_F STRUCT ALIGNMODE
    _11 FLOAT ?
    _12 FLOAT ?
    _13 FLOAT ?
    _14 FLOAT ?
    _21 FLOAT ?
    _22 FLOAT ?
    _23 FLOAT ?
    _24 FLOAT ?
    _31 FLOAT ?
    _32 FLOAT ?
    _33 FLOAT ?
    _34 FLOAT ?
    _41 FLOAT ?
    _42 FLOAT ?
    _43 FLOAT ?
    _44 FLOAT ?
    _51 FLOAT ?
    _52 FLOAT ?
    _53 FLOAT ?
    _54 FLOAT ?
D2D_MATRIX_5X4_F ENDS

D2D1_POINT_2U     TYPEDEF D2D_POINT_2U
D2D1_POINT_2F     TYPEDEF D2D_POINT_2F
D2D1_RECT_F       TYPEDEF D2D_RECT_F
D2D1_RECT_U       TYPEDEF D2D_RECT_U
D2D1_SIZE_F       TYPEDEF D2D_SIZE_F
D2D1_SIZE_U       TYPEDEF D2D_SIZE_U
D2D1_COLOR_F      TYPEDEF D2D_COLOR_F
D2D1_MATRIX_3X2_F TYPEDEF D2D_MATRIX_3X2_F
D2D1_TAG          TYPEDEF UINT64

D2D1_PIXEL_FORMAT STRUCT ALIGNMODE
     format    DXGI_FORMAT     ?
     alphaMode D2D1_ALPHA_MODE ?
D2D1_PIXEL_FORMAT ENDS

D2D1_RENDER_TARGET_PROPERTIES STRUCT ALIGNMODE
     Type_       D2D1_RENDER_TARGET_TYPE  ?
     pixelFormat D2D1_PIXEL_FORMAT        <>
     dpiX        FLOAT                    ?
     dpiY        FLOAT                    ?
     usage       D2D1_RENDER_TARGET_USAGE ?
     minLevel    D2D1_FEATURE_LEVEL       ?
D2D1_RENDER_TARGET_PROPERTIES ENDS

D2D1_BITMAP_PROPERTIES STRUCT ALIGNMODE
    pixelFormat D2D1_PIXEL_FORMAT <>
    dpiX        FLOAT             ?
    dpiY        FLOAT             ?
D2D1_BITMAP_PROPERTIES ENDS

D2D1_GRADIENT_STOP STRUCT
    position FLOAT        ?
    color_   D2D1_COLOR_F <>
D2D1_GRADIENT_STOP ENDS

D2D1_BRUSH_PROPERTIES STRUCT ALIGNMODE
    opacity   FLOAT             ?
    transform D2D1_MATRIX_3X2_F <>
D2D1_BRUSH_PROPERTIES ENDS

D2D1_BITMAP_BRUSH_PROPERTIES STRUCT ALIGNMODE
    extendModeX       D2D1_EXTEND_MODE               ?
    extendModeY       D2D1_EXTEND_MODE               ?
    interpolationMode D2D1_BITMAP_INTERPOLATION_MODE ?
D2D1_BITMAP_BRUSH_PROPERTIES ENDS

D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES STRUCT ALIGNMODE
    startPoint D2D1_POINT_2F <>
    endPoint   D2D1_POINT_2F <>
D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES ENDS

D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES STRUCT ALIGNMODE
    center               D2D1_POINT_2F <>
    gradientOriginOffset D2D1_POINT_2F <>
    radiusX              FLOAT         ?
    radiusY              FLOAT         ?
D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES ENDS

D2D1_BEZIER_SEGMENT STRUCT ALIGNMODE
    point1 D2D1_POINT_2F <>
    point2 D2D1_POINT_2F <>
    point3 D2D1_POINT_2F <>
D2D1_BEZIER_SEGMENT ENDS

D2D1_TRIANGLE STRUCT ALIGNMODE
    point1 D2D1_POINT_2F <>
    point2 D2D1_POINT_2F <>
    point3 D2D1_POINT_2F <>
D2D1_TRIANGLE ENDS

D2D1_ARC_SEGMENT STRUCT ALIGNMODE
    point          D2D1_POINT_2F        <>
    size_          D2D1_SIZE_F          <>
    rotationAngle  FLOAT                ?
    sweepDirection D2D1_SWEEP_DIRECTION ?
    arcSize        D2D1_ARC_SIZE        ?
D2D1_ARC_SEGMENT ENDS

D2D1_QUADRATIC_BEZIER_SEGMENT STRUCT ALIGNMODE
    point1 D2D1_POINT_2F <>
    point2 D2D1_POINT_2F <>
D2D1_QUADRATIC_BEZIER_SEGMENT ENDS

D2D1_ELLIPSE STRUCT ALIGNMODE
    point   D2D1_POINT_2F <>
    radiusX FLOAT         ?
    radiusY FLOAT         ?
D2D1_ELLIPSE ENDS

D2D1_ROUNDED_RECT STRUCT ALIGNMODE
    rect    D2D1_RECT_F <>
    radiusX FLOAT       ?
    radiusY FLOAT       ?
D2D1_ROUNDED_RECT ENDS

D2D1_STROKE_STYLE_PROPERTIES STRUCT ALIGNMODE
    startCap   D2D1_CAP_STYLE  ?
    endCap     D2D1_CAP_STYLE  ?
    dashCap    D2D1_CAP_STYLE  ?
    lineJoin   D2D1_LINE_JOIN  ?
    miterLimit FLOAT           ?
    dashStyle  D2D1_DASH_STYLE ?
    dashOffset FLOAT           ?
D2D1_STROKE_STYLE_PROPERTIES ENDS

D2D1_LAYER_PARAMETER STRUCT ALIGNMODE
    contentBounds     D2D1_RECT_F         <>
    geometricMask     DD                  ?
    maskAntialiasMode D2D1_ANTIALIAS_MODE ?
    maskTransform     D2D1_MATRIX_3X2_F   <>
    opacity           FLOAT               ?
    opacityBrush      DD                  ?
    layerOptions      D2D1_LAYER_OPTIONS  ?
D2D1_LAYER_PARAMETER ENDS

D2D1_HWND_RENDER_TARGET_PROPERTIES STRUCT ALIGNMODE
    hwnd           HWND                 ?
    pixelSize      D2D1_SIZE_U          <>
    presentOptions D2D1_PRESENT_OPTIONS ?
D2D1_HWND_RENDER_TARGET_PROPERTIES ENDS

D2D1_DRAWING_STATE_DESCRIPTION STRUCT ALIGNMODE
    antialiasMode     D2D1_ANTIALIAS_MODE      ?
    textAntialiasMode D2D1_TEXT_ANTIALIAS_MODE ?
    tag1              D2D1_TAG                 ?
    tag2              D2D1_TAG                 ?
    transform         D2D1_MATRIX_3X2_F        <>
D2D1_DRAWING_STATE_DESCRIPTION ENDS

D2D1_FACTORY_OPTIONS STRUCT ALIGNMODE
    debugLevel D2D1_DEBUG_LEVEL ?
D2D1_FACTORY_OPTIONS ENDS

;======================================== Functions =======================================;
D2D1ConvertColorSpace              PROTO :QWORD, :QWORD, :QWORD
D2D1CreateDevice                   PROTO :QWORD, :QWORD, :QWORD
D2D1CreateDeviceContext            PROTO :QWORD, :QWORD, :QWORD
D2D1CreateFactory                  PROTO :QWORD, :QWORD, :QWORD, :QWORD
D2D1InvertMatrix                   PROTO :QWORD
D2D1IsMatrixInvertible             PROTO :QWORD
D2D1MakeRotateMatrix               PROTO :QWORD, :QWORD, :QWORD
D2D1MakeSkewMatrix                 PROTO :QWORD, :QWORD, :QWORD, :QWORD
D2D1SinCos                         PROTO :QWORD, :QWORD, :QWORD
D2D1Tan                            PROTO :QWORD
D2D1Vec3Length                     PROTO :QWORD, :QWORD, :QWORD
IF (NTDDI_VERSION GE NTDDI_WIN81)
    D2D1ComputeMaximumScaleFactor  PROTO :QWORD
ENDIF

;====================================== GUID values =======================================;
.Data
ID2D1Resource                      GUID    <02CD90691H, 012E2H, 011DCH, {09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H}>
ID2D1Image                         GUID    <065019F75H, 08DA2H, 0497CH, {0B3H, 02CH, 0DFH, 0A3H, 04EH, 048H, 0EDH, 0E6H}>
ID2D1Bitmap                        GUID    <0A2296057H, 0EA42H, 04099H, {098H, 03BH, 053H, 09FH, 0B6H, 050H, 054H, 026H}>
ID2D1GradientStopCollection        GUID    <02CD906A7H, 012E2H, 011DCH, {09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H}>
ID2D1Brush                         GUID    <02CD906A8H, 012E2H, 011DCH, {09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H}>
ID2D1BitmapBrush                   GUID    <02CD906AAH, 012E2H, 011DCH, {09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H}>
ID2D1SolidColorBrush               GUID    <02CD906A9H, 012E2H, 011DCH, {09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H}>
ID2D1LinearGradientBrush           GUID    <02CD906ABH, 012E2H, 011DCH, {09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H}>
ID2D1RadialGradientBrush           GUID    <02CD906ACH, 012E2H, 011DCH, {09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H}>
ID2D1StrokeStyle                   GUID    <02CD9069DH, 012E2H, 011DCH, {09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H}>
ID2D1Geometry                      GUID    <02CD906A1H, 012E2H, 011DCH, {09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H}>
ID2D1RectangleGeometry             GUID    <02CD906A2H, 012E2H, 011DCH, {09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H}>
ID2D1RoundedRectangleGeometry      GUID    <02CD906A3H, 012E2H, 011DCH, {09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H}>
ID2D1EllipseGeometry               GUID    <02CD906A4H, 012E2H, 011DCH, {09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H}>
ID2D1GeometryGroup                 GUID    <02CD906A6H, 012E2H, 011DCH, {09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H}>
ID2D1TransformedGeometry           GUID    <02CD906BBH, 012E2H, 011DCH, {09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H}>
ID2D1SimplifiedGeometrySink        GUID    <02CD9069EH, 012E2H, 011DCH, {09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H}>
ID2D1GeometrySink                  GUID    <02CD9069FH, 012E2H, 011DCH, {09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H}>
ID2D1TessellationSink              GUID    <02CD906C1H, 012E2H, 011DCH, {09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H}>
ID2D1PathGeometry                  GUID    <02CD906A5H, 012E2H, 011DCH, {09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H}>
ID2D1Mesh                          GUID    <02CD906C2H, 012E2H, 011DCH, {09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H}>
ID2D1Layer                         GUID    <02CD9069BH, 012E2H, 011DCH, {09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H}>
ID2D1DrawingStateBlock             GUID    <028506E39H, 0EBF6H, 046A1H, {0BBH, 047H, 0FDH, 085H, 056H, 05AH, 0B9H, 057H}>
ID2D1RenderTarget                  GUID    <02CD90694H, 012E2H, 011DCH, {09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H}>
ID2D1BitmapRenderTarget            GUID    <02CD90695H, 012E2H, 011DCH, {09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H}>
ID2D1HwndRenderTarget              GUID    <02CD90698H, 012E2H, 011DCH, {09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H}>
ID2D1GdiInteropRenderTarget        GUID    <0E0DB51C3H, 06F77H, 04BAEH, {0B3H, 0D5H, 0E4H, 075H, 009H, 0B3H, 058H, 038H}>
ID2D1DCRenderTarget                GUID    <01C51BC64H, 0DE61H, 046FDH, {098H, 099H, 063H, 0A5H, 0D8H, 0F0H, 039H, 050H}>
ID2D1Factory                       GUID    <006152247H, 06F50H, 0465AH, {092H, 045H, 011H, 08BH, 0FDH, 03BH, 060H, 007H}>

ENDIF ;D2D1_INC
