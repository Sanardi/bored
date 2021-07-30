;======================================================;
;                                                      ;
;       d2d1.inc for EC v2 Fasm visual projects        ;
;                   (version 1.0.0)                    ;
;                                                      ;
;          Copyright © Héctor A. Medina - 2020         ;
;                                                      ;
;======================================================;

if ~defined D2D1_INC
define D2D1_INC 1

D2D1_INVALID_TAG                                equ     ULONGLONG_MAX
D2D1_DEFAULT_FLATTENING_TOLERANCE               equ     0.25

;enumeration 
D2D1_INTERPOLATION_MODE_DEFINITION_NEAREST_NEIGHBOR     equ     0
D2D1_INTERPOLATION_MODE_DEFINITION_LINEAR               equ     1
D2D1_INTERPOLATION_MODE_DEFINITION_CUBIC                equ     2
D2D1_INTERPOLATION_MODE_DEFINITION_MULTI_SAMPLE_LINEAR  equ     3
D2D1_INTERPOLATION_MODE_DEFINITION_ANISOTROPIC          equ     4
D2D1_INTERPOLATION_MODE_DEFINITION_HIGH_QUALITY_CUBIC   equ     5
D2D1_INTERPOLATION_MODE_DEFINITION_FANT                 equ     6
D2D1_INTERPOLATION_MODE_DEFINITION_MIPMAP_LINEAR        equ     7

;D2D1_ALPHA_MODE enumeration
TYPEDEF                                         D2D1_ALPHA_MODE, dd
D2D1_ALPHA_MODE_UNKNOWN                         equ     0
D2D1_ALPHA_MODE_PREMULTIPLIED                   equ     1
D2D1_ALPHA_MODE_STRAIGHT                        equ     2
D2D1_ALPHA_MODE_IGNORE                          equ     3
D2D1_ALPHA_MODE_FORCE_DWORD                     equ     0FFFFFFFFH

;D2D1_GAMMA enumeration
TYPEDEF                                         D2D1_GAMMA, dd
D2D1_GAMMA_2_2                                  equ     0
D2D1_GAMMA_1_0                                  equ     1
D2D1_GAMMA_FORCE_DWORD                          equ     0FFFFFFFFH

;D2D1_OPACITY_MASK_CONTENT enumeration
TYPEDEF                                         D2D1_OPACITY_MASK_CONTENT, dd
D2D1_OPACITY_MASK_CONTENT_GRAPHICS              equ     0
D2D1_OPACITY_MASK_CONTENT_TEXT_NATURAL          equ     1
D2D1_OPACITY_MASK_CONTENT_TEXT_GDI_COMPATIBLE   equ     2
D2D1_OPACITY_MASK_CONTENT_FORCE_DWORD           equ     0FFFFFFFFH

;D2D1_EXTEND_MODE enumeration
TYPEDEF                                         D2D1_EXTEND_MODE, dd
D2D1_EXTEND_MODE_CLAMP                          equ     0
D2D1_EXTEND_MODE_WRAP                           equ     1
D2D1_EXTEND_MODE_MIRROR                         equ     2
D2D1_EXTEND_MODE_FORCE_DWORD                    equ     0FFFFFFFFH

;D2D1_ANTIALIAS_MODE enumeration
TYPEDEF                                         D2D1_ANTIALIAS_MODE, dd
D2D1_ANTIALIAS_MODE_PER_PRIMITIVE               equ     0
D2D1_ANTIALIAS_MODE_ALIASED                     equ     1
D2D1_ANTIALIAS_MODE_FORCE_DWORD                 equ     0FFFFFFFFH

;D2D1_TEXT_ANTIALIAS_MODE enumeration
TYPEDEF                                         D2D1_TEXT_ANTIALIAS_MODE, dd
D2D1_TEXT_ANTIALIAS_MODE_DEFAULT                equ     0
D2D1_TEXT_ANTIALIAS_MODE_CLEARTYPE              equ     1
D2D1_TEXT_ANTIALIAS_MODE_GRAYSCALE              equ     2
D2D1_TEXT_ANTIALIAS_MODE_ALIASED                equ     3
D2D1_TEXT_ANTIALIAS_MODE_FORCE_DWORD            equ     0FFFFFFFFH

;D2D1_BITMAP_INTERPOLATION_MODE enumeration
TYPEDEF                                         D2D1_BITMAP_INTERPOLATION_MODE, dd
D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR equ     D2D1_INTERPOLATION_MODE_DEFINITION_NEAREST_NEIGHBOR
D2D1_BITMAP_INTERPOLATION_MODE_LINEAR           equ     D2D1_INTERPOLATION_MODE_DEFINITION_LINEAR
D2D1_BITMAP_INTERPOLATION_MODE_FORCE_DWORD      equ     0FFFFFFFFH

;D2D1_DRAW_TEXT_OPTIONS enumeration
TYPEDEF                                         D2D1_DRAW_TEXT_OPTIONS, dd
D2D1_DRAW_TEXT_OPTIONS_NO_SNAP                  equ     000000001H
D2D1_DRAW_TEXT_OPTIONS_CLIP                     equ     000000002H
D2D1_DRAW_TEXT_OPTIONS_ENABLE_COLOR_FONT        equ     000000004H
D2D1_DRAW_TEXT_OPTIONS_NONE                     equ     000000000H
D2D1_DRAW_TEXT_OPTIONS_FORCE_DWORD              equ     0FFFFFFFFH

;D2D1_ARC_SIZE enumeration
TYPEDEF                                         D2D1_ARC_SIZE, dd
D2D1_ARC_SIZE_SMALL                             equ     0
D2D1_ARC_SIZE_LARGE                             equ     1
D2D1_ARC_SIZE_FORCE_DWORD                       equ     0FFFFFFFFH

;D2D1_CAP_STYLE enumeration
TYPEDEF                                         D2D1_CAP_STYLE, dd
D2D1_CAP_STYLE_FLAT                             equ     0
D2D1_CAP_STYLE_SQUARE                           equ     1
D2D1_CAP_STYLE_ROUND                            equ     2
D2D1_CAP_STYLE_TRIANGLE                         equ     3
D2D1_CAP_STYLE_FORCE_DWORD                      equ     0FFFFFFFFH

;D2D1_DASH_STYLE enumeration
TYPEDEF                                         D2D1_DASH_STYLE, dd
D2D1_DASH_STYLE_SOLID                           equ     0
D2D1_DASH_STYLE_DASH                            equ     1
D2D1_DASH_STYLE_DOT                             equ     2
D2D1_DASH_STYLE_DASH_DOT                        equ     3
D2D1_DASH_STYLE_DASH_DOT_DOT                    equ     4
D2D1_DASH_STYLE_CUSTOM                          equ     5
D2D1_DASH_STYLE_FORCE_DWORD                     equ     0FFFFFFFFH

;D2D1_LINE_JOIN enumeration
TYPEDEF                                         D2D1_LINE_JOIN, dd
D2D1_LINE_JOIN_MITER                            equ     0
D2D1_LINE_JOIN_BEVEL                            equ     1
D2D1_LINE_JOIN_ROUND                            equ     2
D2D1_LINE_JOIN_MITER_OR_BEVEL                   equ     3
D2D1_LINE_JOIN_FORCE_DWORD                      equ     0FFFFFFFFH

;D2D1_COMBINE_MODE enumeration
TYPEDEF                                         D2D1_COMBINE_MODE, dd
D2D1_COMBINE_MODE_UNION                         equ     0
D2D1_COMBINE_MODE_INTERSECT                     equ     1
D2D1_COMBINE_MODE_XOR                           equ     2
D2D1_COMBINE_MODE_EXCLUDE                       equ     3
D2D1_COMBINE_MODE_FORCE_DWORD                   equ     0FFFFFFFFH

;D2D1_GEOMETRY_RELATION enumeration
TYPEDEF                                         D2D1_GEOMETRY_RELATION, dd
D2D1_GEOMETRY_RELATION_UNKNOWN                  equ     0
D2D1_GEOMETRY_RELATION_DISJOINT                 equ     1
D2D1_GEOMETRY_RELATION_IS_CONTAINED             equ     2
D2D1_GEOMETRY_RELATION_CONTAINS                 equ     3
D2D1_GEOMETRY_RELATION_OVERLAP                  equ     4
D2D1_GEOMETRY_RELATION_FORCE_DWORD              equ     0FFFFFFFFH

;D2D1_GEOMETRY_SIMPLIFICATION_OPTION enumeration
TYPEDEF                                         D2D1_GEOMETRY_SIMPLIFICATION_OPTION, dd
D2D1_GEOMETRY_SIMPLIFICATION_OPTION_CUBICS_AND_LINES equ    0
D2D1_GEOMETRY_SIMPLIFICATION_OPTION_LINES       equ     1
D2D1_GEOMETRY_SIMPLIFICATION_OPTION_FORCE_DWORD equ     0FFFFFFFFH

;D2D1_FIGURE_BEGIN enumeration
TYPEDEF                                         D2D1_FIGURE_BEGIN, dd
D2D1_FIGURE_BEGIN_FILLED                        equ     0
D2D1_FIGURE_BEGIN_HOLLOW                        equ     1
D2D1_FIGURE_BEGIN_FORCE_DWORD                   equ     0FFFFFFFFH

;D2D1_FIGURE_END enumeration
TYPEDEF                                         D2D1_FIGURE_END, dd
D2D1_FIGURE_END_OPEN                            equ     0
D2D1_FIGURE_END_CLOSED                          equ     1
D2D1_FIGURE_END_FORCE_DWORD                     equ     0FFFFFFFFH

;D2D1_PATH_SEGMENT enumeration
TYPEDEF                                         D2D1_PATH_SEGMENT, dd
D2D1_PATH_SEGMENT_NONE                          equ     000000000H
D2D1_PATH_SEGMENT_FORCE_UNSTROKED               equ     000000001H
D2D1_PATH_SEGMENT_FORCE_ROUND_LINE_JOIN         equ     000000002H
D2D1_PATH_SEGMENT_FORCE_DWORD                   equ     0FFFFFFFFH

;D2D1_SWEEP_DIRECTION enumeration
TYPEDEF                                         D2D1_SWEEP_DIRECTION, dd
D2D1_SWEEP_DIRECTION_COUNTER_CLOCKWISE          equ     0
D2D1_SWEEP_DIRECTION_CLOCKWISE                  equ     1
D2D1_SWEEP_DIRECTION_FORCE_DWORD                equ     0FFFFFFFFH

;D2D1_FILL_MODE enumeration
TYPEDEF                                         D2D1_FILL_MODE, dd
D2D1_FILL_MODE_ALTERNATE                        equ     0
D2D1_FILL_MODE_WINDING                          equ     1
D2D1_FILL_MODE_FORCE_DWORD                      equ     0FFFFFFFFH

;D2D1_LAYER_OPTIONS enumeration
TYPEDEF                                         D2D1_LAYER_OPTIONS, dd
D2D1_LAYER_OPTIONS_NONE                         equ     000000000H
D2D1_LAYER_OPTIONS_INITIALIZE_FOR_CLEARTYPE     equ     000000001H
D2D1_LAYER_OPTIONS_FORCE_DWORD                  equ     0FFFFFFFFH

;D2D1_WINDOW_STATE enumeration
TYPEDEF                                         D2D1_WINDOW_STATE, dd
D2D1_WINDOW_STATE_NONE                          equ     00000000H
D2D1_WINDOW_STATE_OCCLUDED                      equ     00000001H
D2D1_WINDOW_STATE_FORCE_DWORD                   equ     0FFFFFFFFH

;D2D1_RENDER_TARGET_TYPE enumeration
TYPEDEF                                         D2D1_RENDER_TARGET_TYPE, dd
D2D1_RENDER_TARGET_TYPE_DEFAULT                 equ     0
D2D1_RENDER_TARGET_TYPE_SOFTWARE                equ     1
D2D1_RENDER_TARGET_TYPE_HARDWARE                equ     2
D2D1_RENDER_TARGET_TYPE_FORCE_DWORD             equ     0FFFFFFFFH

;D2D1_FEATURE_LEVEL enumeration
TYPEDEF                                         D2D1_FEATURE_LEVEL, dd
D2D1_FEATURE_LEVEL_DEFAULT                      equ     0
D2D1_FEATURE_LEVEL_9                            equ     09100H
D2D1_FEATURE_LEVEL_10                           equ     0A000H
D2D1_FEATURE_LEVEL_FORCE_DWORD                  equ     0FFFFFFFFH

;D2D1_RENDER_TARGET_USAGE enumeration
TYPEDEF                                         D2D1_RENDER_TARGET_USAGE, dd
D2D1_RENDER_TARGET_USAGE_NONE                   equ     000000000H
D2D1_RENDER_TARGET_USAGE_FORCE_BITMAP_REMOTING  equ     000000001H
D2D1_RENDER_TARGET_USAGE_GDI_COMPATIBLE         equ     000000002H
D2D1_RENDER_TARGET_USAGE_FORCE_DWORD            equ     0FFFFFFFFH

;D2D1_PRESENT_OPTIONS enumeration
TYPEDEF                                         D2D1_PRESENT_OPTIONS, dd
D2D1_PRESENT_OPTIONS_NONE                       equ     000000000H
D2D1_PRESENT_OPTIONS_RETAIN_CONTENTS            equ     000000001H
D2D1_PRESENT_OPTIONS_IMMEDIATELY                equ     000000002H
D2D1_PRESENT_OPTIONS_FORCE_DWORD                equ     0FFFFFFFFH

;D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS enumeration
D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS_NONE      equ     000000000H
D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS_GDI_COMPATIBLE equ    000000001H
D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS_FORCE_DWORD equ   0FFFFFFFFH

;D2D1_DC_INITIALIZE_MODE enumeration
TYPEDEF                                         D2D1_DC_INITIALIZE_MODE, dd
D2D1_DC_INITIALIZE_MODE_COPY                    equ     0
D2D1_DC_INITIALIZE_MODE_CLEAR                   equ     1
D2D1_DC_INITIALIZE_MODE_FORCE_DWORD             equ     0FFFFFFFFH

;D2D1_DEBUG_LEVEL enumeration
TYPEDEF                                         D2D1_DEBUG_LEVEL, dd
D2D1_DEBUG_LEVEL_NONE                           equ     0
D2D1_DEBUG_LEVEL_ERROR                          equ     1
D2D1_DEBUG_LEVEL_WARNING                        equ     2
D2D1_DEBUG_LEVEL_INFORMATION                    equ     3
D2D1_DEBUG_LEVEL_FORCE_DWORD                    equ     0FFFFFFFFH

;D2D1_FACTORY_TYPE enumeration
TYPEDEF                                         D2D1_FACTORY_TYPE, dd
D2D1_FACTORY_TYPE_SINGLE_THREADED               equ     0
D2D1_FACTORY_TYPE_MULTI_THREADED                equ     1
D2D1_FACTORY_TYPE_FORCE_DWORD                   equ     0FFFFFFFFH

TYPEDEF                                         DXGI_FORMAT, dd
TYPEDEF                                         D2D1_COLOR_F, dd
TYPEDEF                                         D2D1_TAG, dq

; D2D1 ERRORS
D2DERR_UNSUPPORTED_PIXEL_FORMAT                 equ     WINCODEC_ERR_UNSUPPORTEDPIXELFORMAT
D2DERR_INSUFFICIENT_BUFFER                      equ     ERROR_INSUFFICIENT_BUFFER
D2DERR_WRONG_STATE                              equ     088990001H
D2DERR_NOT_INITIALIZED                          equ     088990002H
D2DERR_UNSUPPORTED_OPERATION                    equ     088990003H
D2DERR_SCANNER_FAILED                           equ     088990004H
D2DERR_SCREEN_ACCESS_DENIED                     equ     088990005H
D2DERR_DISPLAY_STATE_INVALID                    equ     088990006H
D2DERR_ZERO_VECTOR                              equ     088990007H
D2DERR_INTERNAL_ERROR                           equ     088990008H
D2DERR_DISPLAY_FORMAT_NOT_SUPPORTED             equ     088990009H
D2DERR_INVALID_CALL                             equ     08899000AH
D2DERR_NO_HARDWARE_DEVICE                       equ     08899000BH
D2DERR_RECREATE_TARGET                          equ     08899000CH
D2DERR_TOO_MANY_SHADER_ELEMENTS                 equ     08899000DH
D2DERR_SHADER_COMPILE_FAILED                    equ     08899000EH
D2DERR_MAX_TEXTURE_SIZE_EXCEEDED                equ     08899000FH
D2DERR_UNSUPPORTED_VERSION                      equ     088990010H
D2DERR_BAD_NUMBER                               equ     088990011H
D2DERR_WRONG_FACTORY                            equ     088990012H
D2DERR_LAYER_ALREADY_IN_USE                     equ     088990013H
D2DERR_POP_CALL_DID_NOT_MATCH_PUSH              equ     088990014H
D2DERR_WRONG_RESOURCE_DOMAIN                    equ     088990015H
D2DERR_PUSH_POP_UNBALANCED                      equ     088990016H
D2DERR_RENDER_TARGET_HAS_LAYER_OR_CLIPRECT      equ     088990017H
D2DERR_INCOMPATIBLE_BRUSH_TYPES                 equ     088990018H
D2DERR_WIN32_ERROR                              equ     088990019H
D2DERR_TARGET_NOT_GDI_COMPATIBLE                equ     08899001AH
D2DERR_TEXT_EFFECT_IS_WRONG_TYPE                equ     08899001BH
D2DERR_TEXT_RENDERER_NOT_RELEASED               equ     08899001CH
D2DERR_EXCEEDS_MAX_BITMAP_SIZE                  equ     08899001DH
D2DERR_INVALID_GRAPH_CONFIGURATION              equ     08899001EH
D2DERR_INVALID_INTERNAL_GRAPH_CONFIGURATION     equ     08899001FH
D2DERR_CYCLIC_GRAPH                             equ     088990020H
D2DERR_BITMAP_CANNOT_DRAW                       equ     088990021H
D2DERR_OUTSTANDING_BITMAP_REFERENCES            equ     088990022H
D2DERR_ORIGINAL_TARGET_NOT_BOUND                equ     088990023H
D2DERR_INVALID_TARGET                           equ     088990024H
D2DERR_BITMAP_BOUND_AS_TARGET                   equ     088990025H
D2DERR_INSUFFICIENT_DEVICE_CAPABILITIES         equ     088990026H
D2DERR_INTERMEDIATE_TOO_LARGE                   equ     088990027H
D2DERR_EFFECT_IS_NOT_REGISTERED                 equ     088990028H
D2DERR_INVALID_PROPERTY                         equ     088990029H
D2DERR_NO_SUBPROPERTIES                         equ     08899002AH
D2DERR_PRINT_JOB_CLOSED                         equ     08899002BH
D2DERR_PRINT_FORMAT_NOT_SUPPORTED               equ     08899002CH
D2DERR_TOO_MANY_TRANSFORM_INPUTS                equ     08899002DH

; D2D1_COLOR_U
AliceBlue_U                                     equ     00F0F8FFH
AntiqueWhite_U                                  equ     00FAEBD7H
Aqua_U                                          equ     0000FFFFH
Aquamarine_U                                    equ     007FFFD4H
Azure_U                                         equ     00F0FFFFH
Beige_U                                         equ     00F5F5DCH
Bisque_U                                        equ     00FFE4C4H
Black_U                                         equ     00000000H
BlanchedAlmond_U                                equ     00FFEBCDH
Blue_U                                          equ     000000FFH
BlueViolet_U                                    equ     008A2BE2H
Brown_U                                         equ     00A52A2AH
BurlyWood_U                                     equ     00DEB887H
CadetBlue_U                                     equ     005F9EA0H
Chartreuse_U                                    equ     007FFF00H
Chocolate_U                                     equ     00D2691EH
Coral_U                                         equ     00FF7F50H
CornflowerBlue_U                                equ     006495EDH
Cornsilk_U                                      equ     00FFF8DCH
Crimson_U                                       equ     00DC143CH
Cyan_U                                          equ     0000FFFFH
DarkBlue_U                                      equ     0000008BH
DarkCyan_U                                      equ     00008B8BH
DarkGoldenrod_U                                 equ     00B8860BH
DarkGray_U                                      equ     00A9A9A9H
DarkGreen_U                                     equ     00006400H
DarkKhaki_U                                     equ     00BDB76BH
DarkMagenta_U                                   equ     008B008BH
DarkOliveGreen_U                                equ     00556B2FH
DarkOrange_U                                    equ     00FF8C00H
DarkOrchid_U                                    equ     009932CCH
DarkRed_U                                       equ     008B0000H
DarkSalmon_U                                    equ     00E9967AH
DarkSeaGreen_U                                  equ     008FBC8FH
DarkSlateBlue_U                                 equ     00483D8BH
DarkSlateGray_U                                 equ     002F4F4FH
DarkTurquoise_U                                 equ     0000CED1H
DarkViolet_U                                    equ     009400D3H
DeepPink_U                                      equ     00FF1493H
DeepSkyBlue_U                                   equ     0000BFFFH
DimGray_U                                       equ     00696969H
DodgerBlue_U                                    equ     001E90FFH
Firebrick_U                                     equ     00B22222H
FloralWhite_U                                   equ     00FFFAF0H
ForestGreen_U                                   equ     00228B22H
Fuchsia_U                                       equ     00FF00FFH
Gainsboro_U                                     equ     00DCDCDCH
GhostWhite_U                                    equ     00F8F8FFH
Gold_U                                          equ     00FFD700H
Goldenrod_U                                     equ     00DAA520H
Gray_U                                          equ     00808080H
Green_U                                         equ     00008000H
GreenYellow_U                                   equ     00ADFF2FH
Honeydew_U                                      equ     00F0FFF0H
HotPink_U                                       equ     00FF69B4H
IndianRed_U                                     equ     00CD5C5CH
Indigo_U                                        equ     004B0082H
Ivory_U                                         equ     00FFFFF0H
Khaki_U                                         equ     00F0E68CH
Lavender_U                                      equ     00E6E6FAH
LavenderBlush_U                                 equ     00FFF0F5H
LawnGreen_U                                     equ     007CFC00H
LemonChiffon_U                                  equ     00FFFACDH
LightBlue_U                                     equ     00ADD8E6H
LightCoral_U                                    equ     00F08080H
LightCyan_U                                     equ     00E0FFFFH
LightGoldenrodYellow_U                          equ     00FAFAD2H
LightGreen_U                                    equ     0090EE90H
LightGray_U                                     equ     00D3D3D3H
LightPink_U                                     equ     00FFB6C1H
LightSalmon_U                                   equ     00FFA07AH
LightSeaGreen_U                                 equ     0020B2AAH
LightSkyBlue_U                                  equ     0087CEFAH
LightSlateGray_U                                equ     00778899H
LightSteelBlue_U                                equ     00B0C4DEH
LightYellow_U                                   equ     00FFFFE0H
Lime_U                                          equ     0000FF00H
LimeGreen_U                                     equ     0032CD32H
Linen_U                                         equ     00FAF0E6H
Magenta_U                                       equ     00FF00FFH
Maroon_U                                        equ     00800000H
MediumAquamarine_U                              equ     0066CDAAH
MediumBlue_U                                    equ     000000CDH
MediumOrchid_U                                  equ     00BA55D3H
MediumPurple_U                                  equ     009370DBH
MediumSeaGreen_U                                equ     003CB371H
MediumSlateBlue_U                               equ     007B68EEH
MediumSpringGreen_U                             equ     0000FA9AH
MediumTurquoise_U                               equ     0048D1CCH
MediumVioletRed_U                               equ     00C71585H
MidnightBlue_U                                  equ     00191970H
MintCream_U                                     equ     00F5FFFAH
MistyRose_U                                     equ     00FFE4E1H
Moccasin_U                                      equ     00FFE4B5H
NavajoWhite_U                                   equ     00FFDEADH
Navy_U                                          equ     00000080H
OldLace_U                                       equ     00FDF5E6H
Olive_U                                         equ     00808000H
OliveDrab_U                                     equ     006B8E23H
Orange_U                                        equ     00FFA500H
OrangeRed_U                                     equ     00FF4500H
Orchid_U                                        equ     00DA70D6H
PaleGoldenrod_U                                 equ     00EEE8AAH
PaleGreen_U                                     equ     0098FB98H
PaleTurquoise_U                                 equ     00AFEEEEH
PaleVioletRed_U                                 equ     00DB7093H
PapayaWhip_U                                    equ     00FFEFD5H
PeachPuff_U                                     equ     00FFDAB9H
Peru_U                                          equ     00CD853FH
Pink_U                                          equ     00FFC0CBH
Plum_U                                          equ     00DDA0DDH
PowderBlue_U                                    equ     00B0E0E6H
Purple_U                                        equ     00800080H
Red_U                                           equ     00FF0000H
RosyBrown_U                                     equ     00BC8F8FH
RoyalBlue_U                                     equ     004169E1H
SaddleBrown_U                                   equ     008B4513H
Salmon_U                                        equ     00FA8072H
SandyBrown_U                                    equ     00F4A460H
SeaGreen_U                                      equ     002E8B57H
SeaShell_U                                      equ     00FFF5EEH
Sienna_U                                        equ     00A0522DH
Silver_U                                        equ     00C0C0C0H
SkyBlue_U                                       equ     0087CEEBH
SlateBlue_U                                     equ     006A5ACDH
SlateGray_U                                     equ     00708090H
Snow_U                                          equ     00FFFAFAH
SpringGreen_U                                   equ     0000FF7FH
SteelBlue_U                                     equ     004682B4H
Tan_U                                           equ     00D2B48CH
Teal_U                                          equ     00008080H
Thistle_U                                       equ     00D8BFD8H
Tomato_U                                        equ     00FF6347H
Turquoise_U                                     equ     0040E0D0H
Violet_U                                        equ     00EE82EEH
Wheat_U                                         equ     00F5DEB3H
White_U                                         equ     00FFFFFFH
WhiteSmoke_U                                    equ     00F5F5F5H
Yellow_U                                        equ     00FFFF00H
YellowGreen_U                                   equ     009ACD32H

; D2D1_COLOR_F (Red/Green/Blue/Alpha)
AliceBlue_F                                     equ 0.941176534, 0.972549081, 1.000000000, 1.000000000
AntiqueWhite_F                                  equ 0.980392218, 0.921568692, 0.843137324, 1.000000000
Aqua_F                                          equ 0.000000000, 1.000000000, 1.000000000, 1.000000000
Aquamarine_F                                    equ 0.498039246, 1.000000000, 0.831372619, 1.000000000
Azure_F                                         equ 0.941176534, 1.000000000, 1.000000000, 1.000000000
Beige_F                                         equ 0.960784376, 0.960784376, 0.862745166, 1.000000000
Bisque_F                                        equ 1.000000000, 0.894117713, 0.768627524, 1.000000000
Black_F                                         equ 0.000000000, 0.000000000, 0.000000000, 1.000000000
BlanchedAlmond_F                                equ 1.000000000, 0.921568692, 0.803921640, 1.000000000
Blue_F                                          equ 0.000000000, 0.000000000, 1.000000000, 1.000000000
BlueViolet_F                                    equ 0.541176498, 0.168627456, 0.886274576, 1.000000000
Brown_F                                         equ 0.647058845, 0.164705887, 0.164705887, 1.000000000
BurlyWood_F                                     equ 0.870588303, 0.721568644, 0.529411793, 1.000000000
CadetBlue_F                                     equ 0.372549027, 0.619607866, 0.627451003, 1.000000000
Chartreuse_F                                    equ 0.498039246, 1.000000000, 0.000000000, 1.000000000
Chocolate_F                                     equ 0.823529482, 0.411764741, 0.117647067, 1.000000000
Coral_F                                         equ 1.000000000, 0.498039246, 0.313725501, 1.000000000
CornflowerBlue_F                                equ 0.392156899, 0.584313750, 0.929411829, 1.000000000
Cornsilk_F                                      equ 1.000000000, 0.972549081, 0.862745166, 1.000000000
Crimson_F                                       equ 0.862745166, 0.078431375, 0.235294133, 1.000000000
Cyan_F                                          equ 0.000000000, 1.000000000, 1.000000000, 1.000000000
DarkBlue_F                                      equ 0.000000000, 0.000000000, 0.545098066, 1.000000000
DarkCyan_F                                      equ 0.000000000, 0.545098066, 0.545098066, 1.000000000
DarkGoldenrod_F                                 equ 0.721568644, 0.525490224, 0.043137256, 1.000000000
DarkGray_F                                      equ 0.662745118, 0.662745118, 0.662745118, 1.000000000
DarkGreen_F                                     equ 0.000000000, 0.392156899, 0.000000000, 1.000000000
DarkKhaki_F                                     equ 0.741176486, 0.717647076, 0.419607878, 1.000000000
DarkMagenta_F                                   equ 0.545098066, 0.000000000, 0.545098066, 1.000000000
DarkOliveGreen_F                                equ 0.333333343, 0.419607878, 0.184313729, 1.000000000
DarkOrange_F                                    equ 1.000000000, 0.549019635, 0.000000000, 1.000000000
DarkOrchid_F                                    equ 0.600000024, 0.196078449, 0.800000072, 1.000000000
DarkRed_F                                       equ 0.545098066, 0.000000000, 0.000000000, 1.000000000
DarkSalmon_F                                    equ 0.913725555, 0.588235319, 0.478431404, 1.000000000
DarkSeaGreen_F                                  equ 0.560784340, 0.737254918, 0.545098066, 1.000000000
DarkSlateBlue_F                                 equ 0.282352954, 0.239215702, 0.545098066, 1.000000000
DarkSlateGray_F                                 equ 0.184313729, 0.309803933, 0.309803933, 1.000000000
DarkTurquoise_F                                 equ 0.000000000, 0.807843208, 0.819607913, 1.000000000
DarkViolet_F                                    equ 0.580392182, 0.000000000, 0.827451050, 1.000000000
DeepPink_F                                      equ 1.000000000, 0.078431375, 0.576470613, 1.000000000
DeepSkyBlue_F                                   equ 0.000000000, 0.749019623, 1.000000000, 1.000000000
DimGray_F                                       equ 0.411764741, 0.411764741, 0.411764741, 1.000000000
DodgerBlue_F                                    equ 0.117647067, 0.564705908, 1.000000000, 1.000000000
Firebrick_F                                     equ 0.698039234, 0.133333340, 0.133333340, 1.000000000
FloralWhite_F                                   equ 1.000000000, 0.980392218, 0.941176534, 1.000000000
ForestGreen_F                                   equ 0.133333340, 0.545098066, 0.133333340, 1.000000000
Fuchsia_F                                       equ 1.000000000, 0.000000000, 1.000000000, 1.000000000
Gainsboro_F                                     equ 0.862745166, 0.862745166, 0.862745166, 1.000000000
GhostWhite_F                                    equ 0.972549081, 0.972549081, 1.000000000, 1.000000000
Gold_F                                          equ 1.000000000, 0.843137324, 0.000000000, 1.000000000
Goldenrod_F                                     equ 0.854902029, 0.647058845, 0.125490203, 1.000000000
Gray_F                                          equ 0.501960814, 0.501960814, 0.501960814, 1.000000000
Green_F                                         equ 0.000000000, 0.501960814, 0.000000000, 1.000000000
GreenYellow_F                                   equ 0.678431392, 1.000000000, 0.184313729, 1.000000000
Honeydew_F                                      equ 0.941176534, 1.000000000, 0.941176534, 1.000000000
HotPink_F                                       equ 1.000000000, 0.411764741, 0.705882370, 1.000000000
IndianRed_F                                     equ 0.803921640, 0.360784322, 0.360784322, 1.000000000
Indigo_F                                        equ 0.294117659, 0.000000000, 0.509803951, 1.000000000
Ivory_F                                         equ 1.000000000, 1.000000000, 0.941176534, 1.000000000
Khaki_F                                         equ 0.941176534, 0.901960850, 0.549019635, 1.000000000
Lavender_F                                      equ 0.901960850, 0.901960850, 0.980392218, 1.000000000
LavenderBlush_F                                 equ 1.000000000, 0.941176534, 0.960784376, 1.000000000
LawnGreen_F                                     equ 0.486274540, 0.988235354, 0.000000000, 1.000000000
LemonChiffon_F                                  equ 1.000000000, 0.980392218, 0.803921640, 1.000000000
LightBlue_F                                     equ 0.678431392, 0.847058892, 0.901960850, 1.000000000
LightCoral_F                                    equ 0.941176534, 0.501960814, 0.501960814, 1.000000000
LightCyan_F                                     equ 0.878431439, 1.000000000, 1.000000000, 1.000000000
LightGoldenrodYellow_F                          equ 0.980392218, 0.980392218, 0.823529482, 1.000000000
LightGreen_F                                    equ 0.564705908, 0.933333397, 0.564705908, 1.000000000
LightGray_F                                     equ 0.827451050, 0.827451050, 0.827451050, 1.000000000
LightPink_F                                     equ 1.000000000, 0.713725507, 0.756862819, 1.000000000
LightSalmon_F                                   equ 1.000000000, 0.627451003, 0.478431404, 1.000000000
LightSeaGreen_F                                 equ 0.125490203, 0.698039234, 0.666666687, 1.000000000
LightSkyBlue_F                                  equ 0.529411793, 0.807843208, 0.980392218, 1.000000000
LightSlateGray_F                                equ 0.466666698, 0.533333361, 0.600000024, 1.000000000
LightSteelBlue_F                                equ 0.690196097, 0.768627524, 0.870588303, 1.000000000
LightYellow_F                                   equ 1.000000000, 1.000000000, 0.878431439, 1.000000000
Lime_F                                          equ 0.000000000, 1.000000000, 0.000000000, 1.000000000
LimeGreen_F                                     equ 0.196078449, 0.803921640, 0.196078449, 1.000000000
Linen_F                                         equ 0.980392218, 0.941176534, 0.901960850, 1.000000000
Magenta_F                                       equ 1.000000000, 0.000000000, 1.000000000, 1.000000000
Maroon_F                                        equ 0.501960814, 0.000000000, 0.000000000, 1.000000000
MediumAquamarine_F                              equ 0.400000036, 0.803921640, 0.666666687, 1.000000000
MediumBlue_F                                    equ 0.000000000, 0.000000000, 0.803921640, 1.000000000
MediumOrchid_F                                  equ 0.729411781, 0.333333343, 0.827451050, 1.000000000
MediumPurple_F                                  equ 0.576470613, 0.439215720, 0.858823597, 1.000000000
MediumSeaGreen_F                                equ 0.235294133, 0.701960802, 0.443137288, 1.000000000
MediumSlateBlue_F                               equ 0.482352972, 0.407843173, 0.933333397, 1.000000000
MediumSpringGreen_F                             equ 0.000000000, 0.980392218, 0.603921592, 1.000000000
MediumTurquoise_F                               equ 0.282352954, 0.819607913, 0.800000072, 1.000000000
MediumVioletRed_F                               equ 0.780392230, 0.082352944, 0.521568656, 1.000000000
MidnightBlue_F                                  equ 0.098039225, 0.098039225, 0.439215720, 1.000000000
MintCream_F                                     equ 0.960784376, 1.000000000, 0.980392218, 1.000000000
MistyRose_F                                     equ 1.000000000, 0.894117713, 0.882353008, 1.000000000
Moccasin_F                                      equ 1.000000000, 0.894117713, 0.709803939, 1.000000000
NavajoWhite_F                                   equ 1.000000000, 0.870588303, 0.678431392, 1.000000000
Navy_F                                          equ 0.000000000, 0.000000000, 0.501960814, 1.000000000
OldLace_F                                       equ 0.992156923, 0.960784376, 0.901960850, 1.000000000
Olive_F                                         equ 0.501960814, 0.501960814, 0.000000000, 1.000000000
OliveDrab_F                                     equ 0.419607878, 0.556862772, 0.137254909, 1.000000000
Orange_F                                        equ 1.000000000, 0.647058845, 0.000000000, 1.000000000
OrangeRed_F                                     equ 1.000000000, 0.270588249, 0.000000000, 1.000000000
Orchid_F                                        equ 0.854902029, 0.439215720, 0.839215755, 1.000000000
PaleGoldenrod_F                                 equ 0.933333397, 0.909803987, 0.666666687, 1.000000000
PaleGreen_F                                     equ 0.596078455, 0.984313786, 0.596078455, 1.000000000
PaleTurquoise_F                                 equ 0.686274529, 0.933333397, 0.933333397, 1.000000000
PaleVioletRed_F                                 equ 0.858823597, 0.439215720, 0.576470613, 1.000000000
PapayaWhip_F                                    equ 1.000000000, 0.937254965, 0.835294187, 1.000000000
PeachPuff_F                                     equ 1.000000000, 0.854902029, 0.725490212, 1.000000000
Peru_F                                          equ 0.803921640, 0.521568656, 0.247058839, 1.000000000
Pink_F                                          equ 1.000000000, 0.752941251, 0.796078503, 1.000000000
Plum_F                                          equ 0.866666734, 0.627451003, 0.866666734, 1.000000000
PowderBlue_F                                    equ 0.690196097, 0.878431439, 0.901960850, 1.000000000
Purple_F                                        equ 0.501960814, 0.000000000, 0.501960814, 1.000000000
Red_F                                           equ 1.000000000, 0.000000000, 0.000000000, 1.000000000
RosyBrown_F                                     equ 0.737254918, 0.560784340, 0.560784340, 1.000000000
RoyalBlue_F                                     equ 0.254901975, 0.411764741, 0.882353008, 1.000000000
SaddleBrown_F                                   equ 0.545098066, 0.270588249, 0.074509807, 1.000000000
Salmon_F                                        equ 0.980392218, 0.501960814, 0.447058856, 1.000000000
SandyBrown_F                                    equ 0.956862807, 0.643137276, 0.376470625, 1.000000000
SeaGreen_F                                      equ 0.180392161, 0.545098066, 0.341176480, 1.000000000
SeaShell_F                                      equ 1.000000000, 0.960784376, 0.933333397, 1.000000000
Sienna_F                                        equ 0.627451003, 0.321568638, 0.176470593, 1.000000000
Silver_F                                        equ 0.752941251, 0.752941251, 0.752941251, 1.000000000
SkyBlue_F                                       equ 0.529411793, 0.807843208, 0.921568692, 1.000000000
SlateBlue_F                                     equ 0.415686309, 0.352941185, 0.803921640, 1.000000000
SlateGray_F                                     equ 0.439215720, 0.501960814, 0.564705908, 1.000000000
Snow_F                                          equ 1.000000000, 0.980392218, 0.980392218, 1.000000000
SpringGreen_F                                   equ 0.000000000, 1.000000000, 0.498039246, 1.000000000
SteelBlue_F                                     equ 0.274509817, 0.509803951, 0.705882370, 1.000000000
Tan_F                                           equ 0.823529482, 0.705882370, 0.549019635, 1.000000000
Teal_F                                          equ 0.000000000, 0.501960814, 0.501960814, 1.000000000
Thistle_F                                       equ 0.847058892, 0.749019623, 0.847058892, 1.000000000
Tomato_F                                        equ 1.000000000, 0.388235331, 0.278431386, 1.000000000
Transparent_F                                   equ 0.000000000, 0.000000000, 0.000000000, 0.000000000
Turquoise_F                                     equ 0.250980407, 0.878431439, 0.815686345, 1.000000000
Violet_F                                        equ 0.933333397, 0.509803951, 0.933333397, 1.000000000
Wheat_F                                         equ 0.960784376, 0.870588303, 0.701960802, 1.000000000
White_F                                         equ 1.000000000, 1.000000000, 1.000000000, 1.000000000
WhiteSmoke_F                                    equ 0.960784376, 0.960784376, 0.960784376, 1.000000000
Yellow_F                                        equ 1.000000000, 1.000000000, 0.000000000, 1.000000000
YellowGreen_F                                   equ 0.603921592, 0.803921640, 0.196078449, 1.000000000

macro COLORU2RGB COLORNUMBER
{
    mov eax,((COLORNUMBER and 0FFH) shl 16) or (COLORNUMBER and 0FF00H) or ((COLORNUMBER and 0FFH) shl 16)
}

;======================================== Structures ======================================;
if ~defined IUnknownVtbl
    struct IUnknownVtbl
        QueryInterface dq ?
        AddRef         dq ?
        Release_       dq ?
    ends
end if

interface ID2D1ResourceVtbl,\
    QueryInterface,\         ;--IUnknownVtbl
    AddRef,\
    Release_ ,\              ;--------------
    GetFactory   

interface ID2D1ImageVtbl,\
    QueryInterface,\         ;--ID2D1ResourceVtbl
    AddRef,\
    Release_ ,\              
    GetFactory               ;--------------

interface ID2D1BitmapVtbl,\
    QueryInterface,\         ;--ID2D1ImageVtbl
    AddRef,\
    Release_ ,\              
    GetFactory,\             ;--------------
    GetSize,\
    GetPixelSize,\
    GetPixelFormat,\
    GetDpi,\
    CopyFromBitmap,\
    CopyFromRenderTarget,\
    CopyFromMemory

interface ID2D1GradientStopCollectionVtbl,\
    QueryInterface,\                 ;--ID2D1ResourceVtbl
    AddRef,\
    Release_,\
    GetFactory,\                     ;-----
    GetGradientStopCount,\
    GetGradientStops,\
    GetColorInterpolationGamma,\
    GetExtendMode

interface ID2D1BrushVtbl,\
    QueryInterface,\                 ;--ID2D1ResourceVtbl
    AddRef,\
    Release_,\
    GetFactory,\                     ;-----
    SetOpacity,\
    SetTransform,\
    GetOpacity,\
    GetTransform  

interface ID2D1BitmapBrushVtbl,\
    QueryInterface,\                 ;--ID2D1BrushVtbl
    AddRef,\
    Release_,\
    GetFactory,\                     
    SetOpacity,\
    SetTransform,\
    GetOpacity,\
    GetTransform,\                   ;-----
    SetExtendModeX,\
    SetExtendModeY,\
    SetInterpolationMode,\
    SetBitmap,\
    GetExtendModeX,\
    GetExtendModeY,\
    GetInterpolationMode,\
    GetBitmap

interface ID2D1SolidColorBrushVtbl,\  
    QueryInterface,\                 ;--ID2D1BrushVtbl
    AddRef,\
    Release_,\
    GetFactory,\                    
    SetOpacity,\
    SetTransform,\
    GetOpacity,\
    GetTransform,\                   ;-----
    SetColor,\  
    GetColor

interface ID2D1LinearGradientBrushVtbl,\  
    QueryInterface,\                 ;--ID2D1BrushVtbl
    AddRef,\
    Release_,\
    GetFactory,\                     
    SetOpacity,\
    SetTransform,\
    GetOpacity,\
    GetTransform,\                   ;-----
    SetStartPoint,\  
    SetEndPoint,\  
    GetStartPoint,\  
    GetEndPoint,\  
    GetGradientStopCollection

interface ID2D1RadialGradientBrushVtbl,\  
    QueryInterface,\                 ;--IID2D1BrushVtbl
    AddRef,\
    Release_,\
    GetFactory,\                     
    SetOpacity,\
    SetTransform,\
    GetOpacity,\
    GetTransform,\                   ;----
    SetCenter,\
    SetGradientOriginOffset,\
    SetRadiusX,\
    SetRadiusY,\
    GetCenter,\
    GetGradientOriginOffset,\
    GetRadiusX,\
    GetRadiusY,\
    GetGradientStopCollection

interface ID2D1StrokeStyleVtbl,\
    QueryInterface,\         ;--ID2D1ResourceVtbl
    AddRef,\
    Release_ ,\              
    GetFactory,\             ;--------------
    GetStartCap,\
    GetEndCap,\
    GetDashCap,\
    GetMiterLimit,\
    GetLineJoin,\  
    GetDashOffset,\
    GetDashStyle,\
    GetDashesCount,\
    GetDashes  

interface ID2D1GeometryVtbl,\
    QueryInterface,\         ;--ID2D1ResourceVtbl
    AddRef,\
    Release_ ,\              
    GetFactory,\             ;--------------
    GetBounds,\
    GetWidenedBounds,\
    StrokeContainsPoint,\
    FillContainsPoint,\
    CompareWithGeometry,\
    Simplify,\
    Tessellate,\
    CombineWithGeometry,\
    Outline,\
    ComputeArea,\
    ComputeLength,\
    ComputePointAtLength,\
    Widen     

interface ID2D1RectangleGeometryVtbl,\
    QueryInterface,\         ;--ID2D1GeometryVtbl
    AddRef,\
    Release_ ,\              
    GetFactory,\             
    GetBounds,\
    GetWidenedBounds,\
    StrokeContainsPoint,\
    FillContainsPoint,\
    CompareWithGeometry,\
    Simplify,\
    Tessellate,\
    CombineWithGeometry,\
    Outline,\
    ComputeArea,\
    ComputeLength,\
    ComputePointAtLength,\
    Widen,\                  ;--------------
    GetRect   

interface ID2D1RoundedRectangleGeometryVtbl,\
    QueryInterface,\         ;--ID2D1GeometryVtbl
    AddRef,\
    Release_ ,\              
    GetFactory,\             
    GetBounds,\
    GetWidenedBounds,\
    StrokeContainsPoint,\
    FillContainsPoint,\
    CompareWithGeometry,\
    Simplify,\
    Tessellate,\
    CombineWithGeometry,\
    Outline,\
    ComputeArea,\
    ComputeLength,\
    ComputePointAtLength,\
    Widen,\                  ;--------------
    GetRoundedRect

interface ID2D1EllipseGeometryVtbl,\
    QueryInterface,\         ;--ID2D1GeometryVtbl
    AddRef,\
    Release_ ,\              
    GetFactory,\             
    GetBounds,\
    GetWidenedBounds,\
    StrokeContainsPoint,\
    FillContainsPoint,\
    CompareWithGeometry,\
    Simplify,\
    Tessellate,\
    CombineWithGeometry,\
    Outline,\
    ComputeArea,\
    ComputeLength,\
    ComputePointAtLength,\
    Widen,\                  ;--------------
    GetEllipse

interface ID2D1GeometryGroupVtbl,\
    QueryInterface,\         ;--ID2D1GeometryVtbl
    AddRef,\
    Release_ ,\              
    GetFactory,\             
    GetBounds,\
    GetWidenedBounds,\
    StrokeContainsPoint,\
    FillContainsPoint,\
    CompareWithGeometry,\
    Simplify,\
    Tessellate,\
    CombineWithGeometry,\
    Outline,\
    ComputeArea,\
    ComputeLength,\
    ComputePointAtLength,\
    Widen,\                  ;--------------
    GetFillMode,\
    GetSourceGeometryCount,\
    GetSourceGeometries

interface ID2D1TransformedGeometryVtbl,\
    QueryInterface,\         ;--ID2D1GeometryVtbl
    AddRef,\
    Release_ ,\              
    GetFactory,\             
    GetBounds,\
    GetWidenedBounds,\
    StrokeContainsPoint,\
    FillContainsPoint,\
    CompareWithGeometry,\
    Simplify,\
    Tessellate,\
    CombineWithGeometry,\
    Outline,\
    ComputeArea,\
    ComputeLength,\
    ComputePointAtLength,\
    Widen,\                  ;--------------   
    GetSourceGeometry,\
    GetTransform

interface ID2D1SimplifiedGeometrySinkVtbl,\
    QueryInterface,\         ;--IUnknownVtbl
    AddRef,\
    Release_ ,\              ;-------------- 
    SetFillMode,\
    SetSegmentFlags,\
    BeginFigure,\
    AddLines,\
    AddBeziers,\
    EndFigure,\
    Close   

interface ID2D1GeometrySinkVtbl,\
    QueryInterface,\         ;--ID2D1SimplifiedGeometrySinkVtbl
    AddRef,\
    Release_ ,\              
    SetFillMode,\
    SetSegmentFlags,\
    BeginFigure,\
    AddLines,\
    AddBeziers,\
    EndFigure,\
    Close,\                  ;-------------- 
    AddLine,\
    AddBezier,\
    AddQuadraticBezier,\
    AddQuadraticBeziers,\
    AddArc      

interface ID2D1TessellationSinkVtbl,\
    QueryInterface,\         ;--IUnknownVtbl
    AddRef,\
    Release_ ,\              ;-------------- 
    AddTriangles,\
    Close 

interface ID2D1PathGeometryVtbl,\
    QueryInterface,\         ;--ID2D1GeometryVtbl
    AddRef,\
    Release_ ,\              
    GetFactory,\             
    GetBounds,\
    GetWidenedBounds,\
    StrokeContainsPoint,\
    FillContainsPoint,\
    CompareWithGeometry,\
    Simplify,\
    Tessellate,\
    CombineWithGeometry,\
    Outline,\
    ComputeArea,\
    ComputeLength,\
    ComputePointAtLength,\
    Widen,\                  ;--------------
    Open,\
    Stream,\
    GetSegmentCount,\
    GetFigureCount

interface ID2D1MeshVtbl,\
    QueryInterface,\         ;--ID2D1ResourceVtbl
    AddRef,\
    Release_ ,\              
    GetFactory,\             ;--------------
    Open     

interface ID2D1LayerVtbl,\
    QueryInterface,\         ;--ID2D1ResourceVtbl
    AddRef,\
    Release_ ,\              
    GetFactory,\             ;--------------
    GetSize    

interface ID2D1DrawingStateBlockVtbl,\
    QueryInterface,\         ;--ID2D1ResourceVtbl
    AddRef,\
    Release_ ,\              
    GetFactory,\             ;--------------
    GetDescription,\
    SetDescription,\
    SetTextRenderingParams,\
    GetTextRenderingParams

interface ID2D1RenderTargetVtbl,\
    QueryInterface,\                 ;--ID2D1ResourceVtbl
    AddRef,\
    Release_,\
    GetFactory,\                     ;-----
    CreateBitmap,\                    
    CreateBitmapFromWicBitmap,\
    CreateSharedBitmap,\
    CreateBitmapBrush,\
    CreateSolidColorBrush,\
    CreateGradientStopCollection,\
    CreateLinearGradientBrush,\
    CreateRadialGradientBrush,\
    CreateCompatibleRenderTarget,\
    CreateLayer,\
    CreateMesh,\
    DrawLine,\
    DrawRectangle,\
    FillRectangle,\
    DrawRoundedRectangle,\
    FillRoundedRectangle,\
    DrawEllipse,\
    FillEllipse,\
    DrawGeometry,\
    FillGeometry,\
    FillMesh,\
    FillOpacityMask,\
    DrawBitmap,\
    DrawText_,\
    DrawTextLayout,\
    DrawGlyphRun,\
    SetTransform,\
    GetTransform,\
    SetAntialiasMode,\
    GetAntialiasMode,\
    SetTextAntialiasMode,\
    GetTextAntialiasMode,\
    SetTextRenderingParams,\
    GetTextRenderingParams,\
    SetTags,\
    GetTags,\
    PushLayer,\
    PopLayer,\
    Flush,\
    SaveDrawingState,\
    RestoreDrawingState,\
    PushAxisAlignedClip,\
    PopAxisAlignedClip,\
    Clear,\
    BeginDraw,\
    EndDraw,\
    GetPixelFormat,\
    SetDpi,\
    GetDpi,\
    GetSize,\
    GetPixelSize,\
    GetMaximumBitmapSize,\
    IsSupported

;
;struct ID2D1BitmapRenderTargetVtbl
;    ID2D1RenderTargetVtbl
;    GetBitmap             dq ?
;ends
;
interface ID2D1HwndRenderTargetVtbl,\
    QueryInterface,\                 ;--ID2D1RenderTargetVtbl
    AddRef,\
    Release_,\
    GetFactory,\                     
    CreateBitmap,\                    
    CreateBitmapFromWicBitmap,\
    CreateSharedBitmap,\
    CreateBitmapBrush,\
    CreateSolidColorBrush,\
    CreateGradientStopCollection,\
    CreateLinearGradientBrush,\
    CreateRadialGradientBrush,\
    CreateCompatibleRenderTarget,\
    CreateLayer,\
    CreateMesh,\
    DrawLine,\
    DrawRectangle,\
    FillRectangle,\
    DrawRoundedRectangle,\
    FillRoundedRectangle,\
    DrawEllipse,\
    FillEllipse,\
    DrawGeometry,\
    FillGeometry,\
    FillMesh,\
    FillOpacityMask,\
    DrawBitmap,\
    DrawText_,\
    DrawTextLayout,\
    DrawGlyphRun,\
    SetTransform,\
    GetTransform,\
    SetAntialiasMode,\
    GetAntialiasMode,\
    SetTextAntialiasMode,\
    GetTextAntialiasMode,\
    SetTextRenderingParams,\
    GetTextRenderingParams,\
    SetTags,\
    GetTags,\
    PushLayer,\
    PopLayer,\
    Flush,\
    SaveDrawingState,\
    RestoreDrawingState,\
    PushAxisAlignedClip,\
    PopAxisAlignedClip,\
    Clear,\
    BeginDraw,\
    EndDraw,\
    GetPixelFormat,\
    SetDpi,\
    GetDpi,\
    GetSize,\
    GetPixelSize,\
    GetMaximumBitmapSize,\
    IsSupported,\                    ;-----
    CheckWindowState,\
    Resize,\
    GetHwnd 

interface ID2D1GdiInteropRenderTargetVtbl,\
    QueryInterface,\         ;--IUnknownVtbl
    AddRef,\
    Release_ ,\              ;--------------
    GetDC,\
    ReleaseDC

interface ID2D1FactoryVtbl,\
    QueryInterface,\         ;--IUnknownVtbl
    AddRef,\
    Release_ ,\              ;--------------
    ReloadSystemMetrics,\
    GetDesktopDpi,\
    CreateRectangleGeometry,\
    CreateRoundedRectangleGeometry,\
    CreateEllipseGeometry,\
    CreateGeometryGroup,\
    CreateTransformedGeometry,\
    CreatePathGeometry,\
    CreateStrokeStyle,\
    CreateDrawingStateBlock,\
    CreateWicBitmapRenderTarget,\
    CreateHwndRenderTarget,\
    CreateDxgiSurfaceRenderTarget,\
    CreateDCRenderTarget

if ~defined D3DCOLORVALUE_DEFINED
    define D3DCOLORVALUE_DEFINED 1
    struct D3DCOLORVALUE
        r dd ?
        g dd ?
        b dd ?
        a dd ?
    ends
end if

struct D2D_POINT_2U
    x dd ?
    y dd ?
ends

struct D2D_POINT_2F
    x dd ?
    y dd ?
ends

struct D2D_VECTOR_3F
    x dd ?
    y dd ?
    z dd ?
ends

struct D2D_VECTOR_4F
    x dd ?
    y dd ?
    z dd ?
    w dd ?
ends

struct D2D_RECT_F
    left   dd ?
    top    dd ?
    right  dd ?
    bottom dd ?
ends

struct D2D_RECT_U 
    left   dd ?
    top    dd ?
    right  dd ?
    bottom dd ?
ends

struct D2D_SIZE_F
    width_ dd ?
    height dd ?
ends

struct D2D_SIZE_U
    width_ dd ?
    height dd ?
ends

TYPEDEF D2D_COLOR_F, D3DCOLORVALUE
TYPEDEF D2D_RECT_L, RECT

struct D2D_MATRIX_3X2_F
    _11 dd ?
    _12 dd ?
    _21 dd ?
    _22 dd ?
    _31 dd ?
    _32 dd ?
ends

struct D2D_MATRIX_4X3_F
    _11 dd ?
    _12 dd ?
    _13 dd ?
    _21 dd ?
    _22 dd ?
    _23 dd ?
    _31 dd ?
    _32 dd ?
    _33 dd ?
    _41 dd ?
    _42 dd ?
    _43 dd ?
ends

struct D2D_MATRIX_4X4_F
    _11 dd ?
    _12 dd ?
    _13 dd ?
    _14 dd ?
    _21 dd ?
    _22 dd ?
    _23 dd ?
    _24 dd ?
    _31 dd ?
    _32 dd ?
    _33 dd ?
    _34 dd ?
    _41 dd ?
    _42 dd ?
    _43 dd ?
    _44 dd ?
ends

struct D2D_MATRIX_5X4_F
    _11 dd ?
    _12 dd ?
    _13 dd ?
    _14 dd ?
    _21 dd ?
    _22 dd ?
    _23 dd ?
    _24 dd ?
    _31 dd ?
    _32 dd ?
    _33 dd ?
    _34 dd ?
    _41 dd ?
    _42 dd ?
    _43 dd ?
    _44 dd ?
    _51 dd ?
    _52 dd ?
    _53 dd ?
    _54 dd ?
ends

TYPEDEF D2D1_POINT_2U, D2D_POINT_2U
TYPEDEF D2D1_POINT_2F, D2D_POINT_2F
TYPEDEF D2D1_RECT_F, D2D_RECT_F
TYPEDEF D2D1_RECT_U, D2D_RECT_U
TYPEDEF D2D1_SIZE_F, D2D_SIZE_F
TYPEDEF D2D1_SIZE_U, D2D_SIZE_U
TYPEDEF D2D1_MATRIX_3X2_F, D2D_MATRIX_3X2_F

struct D2D1_PIXEL_FORMAT
     format    DXGI_FORMAT     ?
     alphaMode D2D1_ALPHA_MODE ?
ends

struct D2D1_RENDER_TARGET_PROPERTIES
     Type_       D2D1_RENDER_TARGET_TYPE  ?
     pixelFormat D2D1_PIXEL_FORMAT
     dpiX        dd                       ?
     dpiY        dd                       ?
     usage       D2D1_RENDER_TARGET_USAGE ?
     minLevel    D2D1_FEATURE_LEVEL       ?
ends

struct D2D1_BITMAP_PROPERTIES
    pixelFormat D2D1_PIXEL_FORMAT
    dpiX        dd             ?
    dpiY        dd             ?
ends

struct D2D1_GRADIENT_STOP
    position dd          ?
    color_   D2D_COLOR_F <>
ends

struct D2D1_BRUSH_PROPERTIES
    opacity   dd              ?
    transform D2D1_MATRIX_3X2_F
ends

struct D2D1_BITMAP_BRUSH_PROPERTIES
    extendModeX       D2D1_EXTEND_MODE               ?
    extendModeY       D2D1_EXTEND_MODE               ?
    interpolationMode D2D1_BITMAP_INTERPOLATION_MODE ?
ends

struct D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES
    startPoint D2D1_POINT_2F
    endPoint   D2D1_POINT_2F
ends

struct D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES
    center               D2D1_POINT_2F
    gradientOriginOffset D2D1_POINT_2F
    radiusX              dd          ?
    radiusY              dd          ?
ends

struct D2D1_BEZIER_SEGMENT
    point1 D2D1_POINT_2F
    point2 D2D1_POINT_2F
    point3 D2D1_POINT_2F
ends

struct D2D1_TRIANGLE
    point1 D2D1_POINT_2F
    point2 D2D1_POINT_2F
    point3 D2D1_POINT_2F
ends

struct D2D1_ARC_SEGMENT
    point          D2D1_POINT_2F
    size_          D2D1_SIZE_F
    rotationAngle  dd                   ?
    sweepDirection D2D1_SWEEP_DIRECTION ?
    arcSize        D2D1_ARC_SIZE        ?
ends

struct D2D1_QUADRATIC_BEZIER_SEGMENT
    point1 D2D1_POINT_2F
    point2 D2D1_POINT_2F
ends

struct D2D1_ELLIPSE
    point   D2D1_POINT_2F
    radiusX dd          ?
    radiusY dd          ?
ends

struct D2D1_ROUNDED_RECT
    rect    D2D1_RECT_F
    radiusX dd        ?
    radiusY dd        ?
ends

struct D2D1_STROKE_STYLE_PROPERTIES
    startCap   D2D1_CAP_STYLE  ?
    endCap     D2D1_CAP_STYLE  ?
    dashCap    D2D1_CAP_STYLE  ?
    lineJoin   D2D1_LINE_JOIN  ?
    miterLimit dd              ?
    dashStyle  D2D1_DASH_STYLE ?
    dashOffset dd              ?
ends

struct D2D1_LAYER_PARAMETER
    contentBounds     D2D1_RECT_F
    geometricMask     dd                  ?
    maskAntialiasMode D2D1_ANTIALIAS_MODE ?
    maskTransform     D2D1_MATRIX_3X2_F
    opacity           dd                  ?
    opacityBrush      dd                  ?
    layerOptions      D2D1_LAYER_OPTIONS  ?
ends

struct D2D1_HWND_RENDER_TARGET_PROPERTIES
    hwnd           xptr                 ?
    pixelSize      D2D1_SIZE_U
    presentOptions D2D1_PRESENT_OPTIONS ?
ends

struct D2D1_DRAWING_STATE_DESCRIPTION
    antialiasMode     D2D1_ANTIALIAS_MODE      ?
    textAntialiasMode D2D1_TEXT_ANTIALIAS_MODE ?
    tag1              D2D1_TAG                 ?
    tag2              D2D1_TAG                 ?
    transform         D2D1_MATRIX_3X2_F
ends

struct D2D1_FACTORY_OPTIONS
    debugLevel D2D1_DEBUG_LEVEL ?
ends

;======================================== Functions =======================================;
if defined APP_WIN64
    extrn '__imp_D2D1ConvertColorSpace' as D2D1ConvertColorSpace:qword
    extrn '__imp_D2D1CreateDevice' as D2D1CreateDevice:qword
    extrn '__imp_D2D1CreateDeviceContext' as D2D1CreateDeviceContext:qword
    extrn '__imp_D2D1CreateFactory' as D2D1CreateFactory:qword
    extrn '__imp_D2D1InvertMatrix' as D2D1InvertMatrix:qword
    extrn '__imp_D2D1IsMatrixInvertible' as D2D1IsMatrixInvertible:qword
    extrn '__imp_D2D1MakeRotateMatrix' as D2D1MakeRotateMatrix:qword
    extrn '__imp_D2D1MakeSkewMatrix' as D2D1MakeSkewMatrix:qword
    extrn '__imp_D2D1SinCos' as D2D1SinCos:qword
    extrn '__imp_D2D1Tan' as D2D1Tan:qword
    extrn '__imp_D2D1Vec3Length' as D2D1Vec3Length:qword
    if (NTDDI_VERSION >= NTDDI_WIN81)
        extrn '__imp_D2D1ComputeMaximumScaleFactor' as D2D1ComputeMaximumScaleFactor:qword
    end if
else
    ;======== WARNING: This include file is only valid for 64-bit ========
    ;======== projects since 'd2d1.lib' is not included in MASM32 ========
    ;extrn '__imp__D2D1ConvertColorSpace@12' as D2D1ConvertColorSpace:dword
    ;extrn '__imp__D2D1CreateDevice@12' as D2D1CreateDevice:dword
    ;extrn '__imp__D2D1CreateDeviceContext@12' as D2D1CreateDeviceContext:dword
    ;extrn '__imp__D2D1CreateFactory@16' as D2D1CreateFactory:dword
    ;extrn '__imp__D2D1InvertMatrix@4' as D2D1InvertMatrix:dword
    ;extrn '__imp__D2D1IsMatrixInvertible@4' as D2D1IsMatrixInvertible:dword
    ;extrn '__imp__D2D1MakeRotateMatrix@12' as D2D1MakeRotateMatrix:dword
    ;extrn '__imp__D2D1MakeSkewMatrix@16' as D2D1MakeSkewMatrix:dword
    ;extrn '__imp__D2D1SinCos@12' as D2D1SinCos:dword
    ;extrn '__imp__D2D1Tan@4' as D2D1Tan:dword
    ;extrn '__imp__D2D1Vec3Length@12' as D2D1Vec3Length:dword
    ;if (NTDDI_VERSION >= NTDDI_WIN81)
    ;    extrn '__imp__D2D1ComputeMaximumScaleFactor@4' as D2D1ComputeMaximumScaleFactor:dword
    ;end if
end if

;====================================== GUID values =======================================;
.data
ID2D1Resource                      GUID    02CD90691H, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>
ID2D1Image                         GUID    065019F75H, 08DA2H, 0497CH, <0B3H, 02CH, 0DFH, 0A3H, 04EH, 048H, 0EDH, 0E6H>
ID2D1Bitmap                        GUID    0A2296057H, 0EA42H, 04099H, <098H, 03BH, 053H, 09FH, 0B6H, 050H, 054H, 026H>
ID2D1GradientStopCollection        GUID    02CD906A7H, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>
ID2D1Brush                         GUID    02CD906A8H, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>
ID2D1BitmapBrush                   GUID    02CD906AAH, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>
ID2D1SolidColorBrush               GUID    02CD906A9H, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>
ID2D1LinearGradientBrush           GUID    02CD906ABH, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>
ID2D1RadialGradientBrush           GUID    02CD906ACH, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>
ID2D1StrokeStyle                   GUID    02CD9069DH, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>
ID2D1Geometry                      GUID    02CD906A1H, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>
ID2D1RectangleGeometry             GUID    02CD906A2H, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>
ID2D1RoundedRectangleGeometry      GUID    02CD906A3H, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>
ID2D1EllipseGeometry               GUID    02CD906A4H, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>
ID2D1GeometryGroup                 GUID    02CD906A6H, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>
ID2D1TransformedGeometry           GUID    02CD906BBH, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>
ID2D1SimplifiedGeometrySink        GUID    02CD9069EH, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>
ID2D1GeometrySink                  GUID    02CD9069FH, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>
ID2D1TessellationSink              GUID    02CD906C1H, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>
ID2D1PathGeometry                  GUID    02CD906A5H, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>
ID2D1Mesh                          GUID    02CD906C2H, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>
ID2D1Layer                         GUID    02CD9069BH, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>
ID2D1DrawingStateBlock             GUID    028506E39H, 0EBF6H, 046A1H, <0BBH, 047H, 0FDH, 085H, 056H, 05AH, 0B9H, 057H>
ID2D1RenderTarget                  GUID    02CD90694H, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>
ID2D1BitmapRenderTarget            GUID    02CD90695H, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>
ID2D1HwndRenderTarget              GUID    02CD90698H, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>
ID2D1GdiInteropRenderTarget        GUID    0E0DB51C3H, 06F77H, 04BAEH, <0B3H, 0D5H, 0E4H, 075H, 009H, 0B3H, 058H, 038H>
ID2D1DCRenderTarget                GUID    01C51BC64H, 0DE61H, 046FDH, <098H, 099H, 063H, 0A5H, 0D8H, 0F0H, 039H, 050H>
ID2D1Factory                       GUID    006152247H, 06F50H, 0465AH, <092H, 045H, 011H, 08BH, 0FDH, 03BH, 060H, 007H>

end if ;D2D1_INC
