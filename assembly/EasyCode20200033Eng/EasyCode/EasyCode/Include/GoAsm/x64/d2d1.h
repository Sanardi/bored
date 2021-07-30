;======================================================;
;                                                      ;
;  DWrite.inc for Easy Code 2.0 64-bit GoAsm projects  ;
;                   (version 1.0.0)                    ;
;                                                      ;
;          Copyright © Héctor A. Medina - 2020         ;
;                                                      ;
;======================================================;

#ifndef D2D1_H
#define D2D1_H	1

#define D2D1_INVALID_TAG                                ULONGLONG_MAX
#define D2D1_DEFAULT_FLATTENING_TOLERANCE               0.25

;enumeration 
#define D2D1_INTERPOLATION_MODE_DEFINITION_NEAREST_NEIGHBOR     0
#define D2D1_INTERPOLATION_MODE_DEFINITION_LINEAR               1
#define D2D1_INTERPOLATION_MODE_DEFINITION_CUBIC                2
#define D2D1_INTERPOLATION_MODE_DEFINITION_MULTI_SAMPLE_LINEAR  3
#define D2D1_INTERPOLATION_MODE_DEFINITION_ANISOTROPIC          4
#define D2D1_INTERPOLATION_MODE_DEFINITION_HIGH_QUALITY_CUBIC   5
#define D2D1_INTERPOLATION_MODE_DEFINITION_FANT                 6
#define D2D1_INTERPOLATION_MODE_DEFINITION_MIPMAP_LINEAR        7

;D2D1_ALPHA_MODE enumeration
#define D2D1_ALPHA_MODE                                 DD
#define D2D1_ALPHA_MODE_UNKNOWN                         0
#define D2D1_ALPHA_MODE_PREMULTIPLIED                   1
#define D2D1_ALPHA_MODE_STRAIGHT                        2
#define D2D1_ALPHA_MODE_IGNORE                          3
#define D2D1_ALPHA_MODE_FORCE_DWORD                     0xFFFFFFFF

;D2D1_GAMMA enumeration
#define D2D1_GAMMA                                      DD
#define D2D1_GAMMA_2_2                                  0
#define D2D1_GAMMA_1_0                                  1
#define D2D1_GAMMA_FORCE_DWORD                          0xFFFFFFFF

;D2D1_OPACITY_MASK_CONTENT enumeration
#define D2D1_OPACITY_MASK_CONTENT                       DD
#define D2D1_OPACITY_MASK_CONTENT_GRAPHICS              0
#define D2D1_OPACITY_MASK_CONTENT_TEXT_NATURAL          1
#define D2D1_OPACITY_MASK_CONTENT_TEXT_GDI_COMPATIBLE   2
#define D2D1_OPACITY_MASK_CONTENT_FORCE_DWORD           0xFFFFFFFF

;D2D1_EXTEND_MODE enumeration
#define D2D1_EXTEND_MODE                                DD
#define D2D1_EXTEND_MODE_CLAMP                          0
#define D2D1_EXTEND_MODE_WRAP                           1
#define D2D1_EXTEND_MODE_MIRROR                         2
#define D2D1_EXTEND_MODE_FORCE_DWORD                    0xFFFFFFFF

;D2D1_ANTIALIAS_MODE enumeration
#define D2D1_ANTIALIAS_MODE                             DD
#define D2D1_ANTIALIAS_MODE_PER_PRIMITIVE               0
#define D2D1_ANTIALIAS_MODE_ALIASED                     1
#define D2D1_ANTIALIAS_MODE_FORCE_DWORD                 0xFFFFFFFF

;D2D1_TEXT_ANTIALIAS_MODE enumeration
#define D2D1_TEXT_ANTIALIAS_MODE                        DD
#define D2D1_TEXT_ANTIALIAS_MODE_DEFAULT                0
#define D2D1_TEXT_ANTIALIAS_MODE_CLEARTYPE              1
#define D2D1_TEXT_ANTIALIAS_MODE_GRAYSCALE              2
#define D2D1_TEXT_ANTIALIAS_MODE_ALIASED                3
#define D2D1_TEXT_ANTIALIAS_MODE_FORCE_DWORD            0xFFFFFFFF

;D2D1_BITMAP_INTERPOLATION_MODE enumeration
#define D2D1_BITMAP_INTERPOLATION_MODE                  DD
#define D2D1_BITMAP_INTERPOLATION_MODE_NEAREST_NEIGHBOR D2D1_INTERPOLATION_MODE_DEFINITION_NEAREST_NEIGHBOR
#define D2D1_BITMAP_INTERPOLATION_MODE_LINEAR           D2D1_INTERPOLATION_MODE_DEFINITION_LINEAR
#define D2D1_BITMAP_INTERPOLATION_MODE_FORCE_DWORD      0xFFFFFFFF

;D2D1_DRAW_TEXT_OPTIONS enumeration
#define D2D1_DRAW_TEXT_OPTIONS                          DD
#define D2D1_DRAW_TEXT_OPTIONS_NO_SNAP                  0x00000001
#define D2D1_DRAW_TEXT_OPTIONS_CLIP                     0x00000002
#define D2D1_DRAW_TEXT_OPTIONS_ENABLE_COLOR_FONT        0x00000004
#define D2D1_DRAW_TEXT_OPTIONS_NONE                     0x00000000
#define D2D1_DRAW_TEXT_OPTIONS_FORCE_DWORD              0xFFFFFFFF

;D2D1_ARC_SIZE enumeration
#define D2D1_ARC_SIZE                                   DD
#define D2D1_ARC_SIZE_SMALL                             0
#define D2D1_ARC_SIZE_LARGE                             1
#define D2D1_ARC_SIZE_FORCE_DWORD                       0xFFFFFFFF

;D2D1_CAP_STYLE enumeration
#define D2D1_CAP_STYLE                                  DD
#define D2D1_CAP_STYLE_FLAT                             0
#define D2D1_CAP_STYLE_SQUARE                           1
#define D2D1_CAP_STYLE_ROUND                            2
#define D2D1_CAP_STYLE_TRIANGLE                         3
#define D2D1_CAP_STYLE_FORCE_DWORD                      0xFFFFFFFF

;D2D1_DASH_STYLE enumeration
#define D2D1_DASH_STYLE                                 DD
#define D2D1_DASH_STYLE_SOLID                           0
#define D2D1_DASH_STYLE_DASH                            1
#define D2D1_DASH_STYLE_DOT                             2
#define D2D1_DASH_STYLE_DASH_DOT                        3
#define D2D1_DASH_STYLE_DASH_DOT_DOT                    4
#define D2D1_DASH_STYLE_CUSTOM                          5
#define D2D1_DASH_STYLE_FORCE_DWORD                     0xFFFFFFFF

;D2D1_LINE_JOIN enumeration
#define D2D1_LINE_JOIN                                  DD
#define D2D1_LINE_JOIN_MITER                            0
#define D2D1_LINE_JOIN_BEVEL                            1
#define D2D1_LINE_JOIN_ROUND                            2
#define D2D1_LINE_JOIN_MITER_OR_BEVEL                   3
#define D2D1_LINE_JOIN_FORCE_DWORD                      0xFFFFFFFF

;D2D1_COMBINE_MODE enumeration
#define D2D1_COMBINE_MODE                               DD
#define D2D1_COMBINE_MODE_UNION                         0
#define D2D1_COMBINE_MODE_INTERSECT                     1
#define D2D1_COMBINE_MODE_XOR                           2
#define D2D1_COMBINE_MODE_EXCLUDE                       3
#define D2D1_COMBINE_MODE_FORCE_DWORD                   0xFFFFFFFF

;D2D1_GEOMETRY_RELATION enumeration
#define D2D1_GEOMETRY_RELATION                          DD
#define D2D1_GEOMETRY_RELATION_UNKNOWN                  0
#define D2D1_GEOMETRY_RELATION_DISJOINT                 1
#define D2D1_GEOMETRY_RELATION_IS_CONTAINED             2
#define D2D1_GEOMETRY_RELATION_CONTAINS                 3
#define D2D1_GEOMETRY_RELATION_OVERLAP                  4
#define D2D1_GEOMETRY_RELATION_FORCE_DWORD              0xFFFFFFFF

;D2D1_GEOMETRY_SIMPLIFICATION_OPTION enumeration
#define D2D1_GEOMETRY_SIMPLIFICATION_OPTION             DD
#define D2D1_GEOMETRY_SIMPLIFICATION_OPTION_CUBICS_AND_LINES EQU    0
#define D2D1_GEOMETRY_SIMPLIFICATION_OPTION_LINES       1
#define D2D1_GEOMETRY_SIMPLIFICATION_OPTION_FORCE_DWORD 0xFFFFFFFF

;D2D1_FIGURE_BEGIN enumeration
#define D2D1_FIGURE_BEGIN                               DD
#define D2D1_FIGURE_BEGIN_FILLED                        0
#define D2D1_FIGURE_BEGIN_HOLLOW                        1
#define D2D1_FIGURE_BEGIN_FORCE_DWORD                   0xFFFFFFFF

;D2D1_FIGURE_END enumeration
#define D2D1_FIGURE_END                                 DD
#define D2D1_FIGURE_END_OPEN                            0
#define D2D1_FIGURE_END_CLOSED                          1
#define D2D1_FIGURE_END_FORCE_DWORD                     0xFFFFFFFF

;D2D1_PATH_SEGMENT enumeration
#define D2D1_PATH_SEGMENT                               DD
#define D2D1_PATH_SEGMENT_NONE                          0x00000000
#define D2D1_PATH_SEGMENT_FORCE_UNSTROKED               0x00000001
#define D2D1_PATH_SEGMENT_FORCE_ROUND_LINE_JOIN         0x00000002
#define D2D1_PATH_SEGMENT_FORCE_DWORD                   0xFFFFFFFF

;D2D1_SWEEP_DIRECTION enumeration
#define D2D1_SWEEP_DIRECTION                            DD
#define D2D1_SWEEP_DIRECTION_COUNTER_CLOCKWISE          0
#define D2D1_SWEEP_DIRECTION_CLOCKWISE                  1
#define D2D1_SWEEP_DIRECTION_FORCE_DWORD                0xFFFFFFFF

;D2D1_FILL_MODE enumeration
#define D2D1_FILL_MODE                                  DD
#define D2D1_FILL_MODE_ALTERNATE                        0
#define D2D1_FILL_MODE_WINDING                          1
#define D2D1_FILL_MODE_FORCE_DWORD                      0xFFFFFFFF

;D2D1_LAYER_OPTIONS enumeration
#define D2D1_LAYER_OPTIONS                              DD
#define D2D1_LAYER_OPTIONS_NONE                         0x00000000
#define D2D1_LAYER_OPTIONS_INITIALIZE_FOR_CLEARTYPE     0x00000001
#define D2D1_LAYER_OPTIONS_FORCE_DWORD                  0xFFFFFFFF

;D2D1_WINDOW_STATE enumeration
#define D2D1_WINDOW_STATE                               DD
#define D2D1_WINDOW_STATE_NONE                          0x00000000
#define D2D1_WINDOW_STATE_OCCLUDED                      0x00000001
#define D2D1_WINDOW_STATE_FORCE_DWORD                   0xFFFFFFFF

;D2D1_RENDER_TARGET_TYPE enumeration
#define D2D1_RENDER_TARGET_TYPE                         DD
#define D2D1_RENDER_TARGET_TYPE_DEFAULT                 0
#define D2D1_RENDER_TARGET_TYPE_SOFTWARE                1
#define D2D1_RENDER_TARGET_TYPE_HARDWARE                2
#define D2D1_RENDER_TARGET_TYPE_FORCE_DWORD             0xFFFFFFFF

;D2D1_FEATURE_LEVEL enumeration
#define D2D1_FEATURE_LEVEL                              DD
#define D2D1_FEATURE_LEVEL_DEFAULT                      0
#define D2D1_FEATURE_LEVEL_9                            0x00009100
#define D2D1_FEATURE_LEVEL_10                           0x0000A000
#define D2D1_FEATURE_LEVEL_FORCE_DWORD                  0xFFFFFFFF

;D2D1_RENDER_TARGET_USAGE enumeration
#define D2D1_RENDER_TARGET_USAGE                        DD
#define D2D1_RENDER_TARGET_USAGE_NONE                   0x00000000
#define D2D1_RENDER_TARGET_USAGE_FORCE_BITMAP_REMOTING  0x00000001
#define D2D1_RENDER_TARGET_USAGE_GDI_COMPATIBLE         0x00000002
#define D2D1_RENDER_TARGET_USAGE_FORCE_DWORD            0xFFFFFFFF

;D2D1_PRESENT_OPTIONS enumeration
#define D2D1_PRESENT_OPTIONS                            DD
#define D2D1_PRESENT_OPTIONS_NONE                       0x00000000
#define D2D1_PRESENT_OPTIONS_RETAIN_CONTENTS            0x00000001
#define D2D1_PRESENT_OPTIONS_IMMEDIATELY                0x00000002
#define D2D1_PRESENT_OPTIONS_FORCE_DWORD                0xFFFFFFFF

;D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS enumeration
#define D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS_NONE      0x00000000
#define D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS_GDI_COMPATIBLE EQU    0x00000001
#define D2D1_COMPATIBLE_RENDER_TARGET_OPTIONS_FORCE_DWORD EQU   0xFFFFFFFF

;D2D1_DC_INITIALIZE_MODE enumeration
#define D2D1_DC_INITIALIZE_MODE                         DD
#define D2D1_DC_INITIALIZE_MODE_COPY                    0
#define D2D1_DC_INITIALIZE_MODE_CLEAR                   1
#define D2D1_DC_INITIALIZE_MODE_FORCE_DWORD             0xFFFFFFFF

;D2D1_DEBUG_LEVEL enumeration
#define D2D1_DEBUG_LEVEL                                DD
#define D2D1_DEBUG_LEVEL_NONE                           0
#define D2D1_DEBUG_LEVEL_ERROR                          1
#define D2D1_DEBUG_LEVEL_WARNING                        2
#define D2D1_DEBUG_LEVEL_INFORMATION                    3
#define D2D1_DEBUG_LEVEL_FORCE_DWORD                    0xFFFFFFFF

;D2D1_FACTORY_TYPE enumeration
#define D2D1_FACTORY_TYPE                               DD
#define D2D1_FACTORY_TYPE_SINGLE_THREADED               0
#define D2D1_FACTORY_TYPE_MULTI_THREADED                1
#define D2D1_FACTORY_TYPE_FORCE_DWORD                   0xFFFFFFFF

#define DXGI_FORMAT                                     DD

; D2D1 ERRORS
#define D2DERR_UNSUPPORTED_PIXEL_FORMAT                 WINCODEC_ERR_UNSUPPORTEDPIXELFORMAT
#define D2DERR_INSUFFICIENT_BUFFER                      ERROR_INSUFFICIENT_BUFFER
#define D2DERR_WRONG_STATE                              0x88990001
#define D2DERR_NOT_INITIALIZED                          0x88990002
#define D2DERR_UNSUPPORTED_OPERATION                    0x88990003
#define D2DERR_SCANNER_FAILED                           0x88990004
#define D2DERR_SCREEN_ACCESS_DENIED                     0x88990005
#define D2DERR_DISPLAY_STATE_INVALID                    0x88990006
#define D2DERR_ZERO_VECTOR                              0x88990007
#define D2DERR_INTERNAL_ERROR                           0x88990008
#define D2DERR_DISPLAY_FORMAT_NOT_SUPPORTED             0x88990009
#define D2DERR_INVALID_CALL                             0x8899000A
#define D2DERR_NO_HARDWARE_DEVICE                       0x8899000B
#define D2DERR_RECREATE_TARGET                          0x8899000C
#define D2DERR_TOO_MANY_SHADER_ELEMENTS                 0x8899000D
#define D2DERR_SHADER_COMPILE_FAILED                    0x8899000E
#define D2DERR_MAX_TEXTURE_SIZE_EXCEEDED                0x8899000F
#define D2DERR_UNSUPPORTED_VERSION                      0x88990010
#define D2DERR_BAD_NUMBER                               0x88990011
#define D2DERR_WRONG_FACTORY                            0x88990012
#define D2DERR_LAYER_ALREADY_IN_USE                     0x88990013
#define D2DERR_POP_CALL_DID_NOT_MATCH_PUSH              0x88990014
#define D2DERR_WRONG_RESOURCE_DOMAIN                    0x88990015
#define D2DERR_PUSH_POP_UNBALANCED                      0x88990016
#define D2DERR_RENDER_TARGET_HAS_LAYER_OR_CLIPRECT      0x88990017
#define D2DERR_INCOMPATIBLE_BRUSH_TYPES                 0x88990018
#define D2DERR_WIN32_ERROR                              0x88990019
#define D2DERR_TARGET_NOT_GDI_COMPATIBLE                0x8899001A
#define D2DERR_TEXT_EFFECT_IS_WRONG_TYPE                0x8899001B
#define D2DERR_TEXT_RENDERER_NOT_RELEASED               0x8899001C
#define D2DERR_EXCEEDS_MAX_BITMAP_SIZE                  0x8899001D
#define D2DERR_INVALID_GRAPH_CONFIGURATION              0x8899001E
#define D2DERR_INVALID_INTERNAL_GRAPH_CONFIGURATION     0x8899001F
#define D2DERR_CYCLIC_GRAPH                             0x88990020
#define D2DERR_BITMAP_CANNOT_DRAW                       0x88990021
#define D2DERR_OUTSTANDING_BITMAP_REFERENCES            0x88990022
#define D2DERR_ORIGINAL_TARGET_NOT_BOUND                0x88990023
#define D2DERR_INVALID_TARGET                           0x88990024
#define D2DERR_BITMAP_BOUND_AS_TARGET                   0x88990025
#define D2DERR_INSUFFICIENT_DEVICE_CAPABILITIES         0x88990026
#define D2DERR_INTERMEDIATE_TOO_LARGE                   0x88990027
#define D2DERR_EFFECT_IS_NOT_REGISTERED                 0x88990028
#define D2DERR_INVALID_PROPERTY                         0x88990029
#define D2DERR_NO_SUBPROPERTIES                         0x8899002A
#define D2DERR_PRINT_JOB_CLOSED                         0x8899002B
#define D2DERR_PRINT_FORMAT_NOT_SUPPORTED               0x8899002C
#define D2DERR_TOO_MANY_TRANSFORM_INPUTS                0x8899002D

; D2D1_COLOR_U
#define AliceBlue_U                                     0x0F0F8FF
#define AntiqueWhite_U                                  0x0FAEBD7
#define Aqua_U                                          0x000FFFF
#define Aquamarine_U                                    0x07FFFD4
#define Azure_U                                         0x0F0FFFF
#define Beige_U                                         0x0F5F5DC
#define Bisque_U                                        0x0FFE4C4
#define Black_U                                         0x0000000
#define BlanchedAlmond_U                                0x0FFEBCD
#define Blue_U                                          0x00000FF
#define BlueViolet_U                                    0x08A2BE2
#define Brown_U                                         0x0A52A2A
#define BurlyWood_U                                     0x0DEB887
#define CadetBlue_U                                     0x05F9EA0
#define Chartreuse_U                                    0x07FFF00
#define Chocolate_U                                     0x0D2691E
#define Coral_U                                         0x0FF7F50
#define CornflowerBlue_U                                0x06495ED
#define Cornsilk_U                                      0x0FFF8DC
#define Crimson_U                                       0x0DC143C
#define Cyan_U                                          0x000FFFF
#define DarkBlue_U                                      0x000008B
#define DarkCyan_U                                      0x0008B8B
#define DarkGoldenrod_U                                 0x0B8860B
#define DarkGray_U                                      0x0A9A9A9
#define DarkGreen_U                                     0x0006400
#define DarkKhaki_U                                     0x0BDB76B
#define DarkMagenta_U                                   0x08B008B
#define DarkOliveGreen_U                                0x0556B2F
#define DarkOrange_U                                    0x0FF8C00
#define DarkOrchid_U                                    0x09932CC
#define DarkRed_U                                       0x08B0000
#define DarkSalmon_U                                    0x0E9967A
#define DarkSeaGreen_U                                  0x08FBC8F
#define DarkSlateBlue_U                                 0x0483D8B
#define DarkSlateGray_U                                 0x02F4F4F
#define DarkTurquoise_U                                 0x000CED1
#define DarkViolet_U                                    0x09400D3
#define DeepPink_U                                      0x0FF1493
#define DeepSkyBlue_U                                   0x000BFFF
#define DimGray_U                                       0x0696969
#define DodgerBlue_U                                    0x01E90FF
#define Firebrick_U                                     0x0B22222
#define FloralWhite_U                                   0x0FFFAF0
#define ForestGreen_U                                   0x0228B22
#define Fuchsia_U                                       0x0FF00FF
#define Gainsboro_U                                     0x0DCDCDC
#define GhostWhite_U                                    0x0F8F8FF
#define Gold_U                                          0x0FFD700
#define Goldenrod_U                                     0x0DAA520
#define Gray_U                                          0x0808080
#define Green_U                                         0x0008000
#define GreenYellow_U                                   0x0ADFF2F
#define Honeydew_U                                      0x0F0FFF0
#define HotPink_U                                       0x0FF69B4
#define IndianRed_U                                     0x0CD5C5C
#define Indigo_U                                        0x04B0082
#define Ivory_U                                         0x0FFFFF0
#define Khaki_U                                         0x0F0E68C
#define Lavender_U                                      0x0E6E6FA
#define LavenderBlush_U                                 0x0FFF0F5
#define LawnGreen_U                                     0x07CFC00
#define LemonChiffon_U                                  0x0FFFACD
#define LightBlue_U                                     0x0ADD8E6
#define LightCoral_U                                    0x0F08080
#define LightCyan_U                                     0x0E0FFFF
#define LightGoldenrodYellow_U                          0x0FAFAD2
#define LightGreen_U                                    0x090EE90
#define LightGray_U                                     0x0D3D3D3
#define LightPink_U                                     0x0FFB6C1
#define LightSalmon_U                                   0x0FFA07A
#define LightSeaGreen_U                                 0x020B2AA
#define LightSkyBlue_U                                  0x087CEFA
#define LightSlateGray_U                                0x0778899
#define LightSteelBlue_U                                0x0B0C4DE
#define LightYellow_U                                   0x0FFFFE0
#define Lime_U                                          0x000FF00
#define LimeGreen_U                                     0x032CD32
#define Linen_U                                         0x0FAF0E6
#define Magenta_U                                       0x0FF00FF
#define Maroon_U                                        0x0800000
#define MediumAquamarine_U                              0x066CDAA
#define MediumBlue_U                                    0x00000CD
#define MediumOrchid_U                                  0x0BA55D3
#define MediumPurple_U                                  0x09370DB
#define MediumSeaGreen_U                                0x03CB371
#define MediumSlateBlue_U                               0x07B68EE
#define MediumSpringGreen_U                             0x000FA9A
#define MediumTurquoise_U                               0x048D1CC
#define MediumVioletRed_U                               0x0C71585
#define MidnightBlue_U                                  0x0191970
#define MintCream_U                                     0x0F5FFFA
#define MistyRose_U                                     0x0FFE4E1
#define Moccasin_U                                      0x0FFE4B5
#define NavajoWhite_U                                   0x0FFDEAD
#define Navy_U                                          0x0000080
#define OldLace_U                                       0x0FDF5E6
#define Olive_U                                         0x0808000
#define OliveDrab_U                                     0x06B8E23
#define Orange_U                                        0x0FFA500
#define OrangeRed_U                                     0x0FF4500
#define Orchid_U                                        0x0DA70D6
#define PaleGoldenrod_U                                 0x0EEE8AA
#define PaleGreen_U                                     0x098FB98
#define PaleTurquoise_U                                 0x0AFEEEE
#define PaleVioletRed_U                                 0x0DB7093
#define PapayaWhip_U                                    0x0FFEFD5
#define PeachPuff_U                                     0x0FFDAB9
#define Peru_U                                          0x0CD853F
#define Pink_U                                          0x0FFC0CB
#define Plum_U                                          0x0DDA0DD
#define PowderBlue_U                                    0x0B0E0E6
#define Purple_U                                        0x0800080
#define Red_U                                           0x0FF0000
#define RosyBrown_U                                     0x0BC8F8F
#define RoyalBlue_U                                     0x04169E1
#define SaddleBrown_U                                   0x08B4513
#define Salmon_U                                        0x0FA8072
#define SandyBrown_U                                    0x0F4A460
#define SeaGreen_U                                      0x02E8B57
#define SeaShell_U                                      0x0FFF5EE
#define Sienna_U                                        0x0A0522D
#define Silver_U                                        0x0C0C0C0
#define SkyBlue_U                                       0x087CEEB
#define SlateBlue_U                                     0x06A5ACD
#define SlateGray_U                                     0x0708090
#define Snow_U                                          0x0FFFAFA
#define SpringGreen_U                                   0x000FF7F
#define SteelBlue_U                                     0x04682B4
#define Tan_U                                           0x0D2B48C
#define Teal_U                                          0x0008080
#define Thistle_U                                       0x0D8BFD8
#define Tomato_U                                        0x0FF6347
#define Turquoise_U                                     0x040E0D0
#define Violet_U                                        0x0EE82EE
#define Wheat_U                                         0x0F5DEB3
#define White_U                                         0x0FFFFFF
#define WhiteSmoke_U                                    0x0F5F5F5
#define Yellow_U                                        0x0FFFF00
#define YellowGreen_U                                   0x09ACD32

; D2D1_COLOR_F (Red/Green/Blue/Alpha)
AliceBlue_F                                     EQU     0.941176534, 0.972549081, 1.000000000, 1.000000000
AntiqueWhite_F                                  EQU     0.980392218, 0.921568692, 0.843137324, 1.000000000
Aqua_F                                          EQU     0.000000000, 1.000000000, 1.000000000, 1.000000000
Aquamarine_F                                    EQU     0.498039246, 1.000000000, 0.831372619, 1.000000000
Azure_F                                         EQU     0.941176534, 1.000000000, 1.000000000, 1.000000000
Beige_F                                         EQU     0.960784376, 0.960784376, 0.862745166, 1.000000000
Bisque_F                                        EQU     1.000000000, 0.894117713, 0.768627524, 1.000000000
Black_F                                         EQU     0.000000000, 0.000000000, 0.000000000, 1.000000000
BlanchedAlmond_F                                EQU     1.000000000, 0.921568692, 0.803921640, 1.000000000
Blue_F                                          EQU     0.000000000, 0.000000000, 1.000000000, 1.000000000
BlueViolet_F                                    EQU     0.541176498, 0.168627456, 0.886274576, 1.000000000
Brown_F                                         EQU     0.647058845, 0.164705887, 0.164705887, 1.000000000
BurlyWood_F                                     EQU     0.870588303, 0.721568644, 0.529411793, 1.000000000
CadetBlue_F                                     EQU     0.372549027, 0.619607866, 0.627451003, 1.000000000
Chartreuse_F                                    EQU     0.498039246, 1.000000000, 0.000000000, 1.000000000
Chocolate_F                                     EQU     0.823529482, 0.411764741, 0.117647067, 1.000000000
Coral_F                                         EQU     1.000000000, 0.498039246, 0.313725501, 1.000000000
CornflowerBlue_F                                EQU     0.392156899, 0.584313750, 0.929411829, 1.000000000
Cornsilk_F                                      EQU     1.000000000, 0.972549081, 0.862745166, 1.000000000
Crimson_F                                       EQU     0.862745166, 0.078431375, 0.235294133, 1.000000000
Cyan_F                                          EQU     0.000000000, 1.000000000, 1.000000000, 1.000000000
DarkBlue_F                                      EQU     0.000000000, 0.000000000, 0.545098066, 1.000000000
DarkCyan_F                                      EQU     0.000000000, 0.545098066, 0.545098066, 1.000000000
DarkGoldenrod_F                                 EQU     0.721568644, 0.525490224, 0.043137256, 1.000000000
DarkGray_F                                      EQU     0.662745118, 0.662745118, 0.662745118, 1.000000000
DarkGreen_F                                     EQU     0.000000000, 0.392156899, 0.000000000, 1.000000000
DarkKhaki_F                                     EQU     0.741176486, 0.717647076, 0.419607878, 1.000000000
DarkMagenta_F                                   EQU     0.545098066, 0.000000000, 0.545098066, 1.000000000
DarkOliveGreen_F                                EQU     0.333333343, 0.419607878, 0.184313729, 1.000000000
DarkOrange_F                                    EQU     1.000000000, 0.549019635, 0.000000000, 1.000000000
DarkOrchid_F                                    EQU     0.600000024, 0.196078449, 0.800000072, 1.000000000
DarkRed_F                                       EQU     0.545098066, 0.000000000, 0.000000000, 1.000000000
DarkSalmon_F                                    EQU     0.913725555, 0.588235319, 0.478431404, 1.000000000
DarkSeaGreen_F                                  EQU     0.560784340, 0.737254918, 0.545098066, 1.000000000
DarkSlateBlue_F                                 EQU     0.282352954, 0.239215702, 0.545098066, 1.000000000
DarkSlateGray_F                                 EQU     0.184313729, 0.309803933, 0.309803933, 1.000000000
DarkTurquoise_F                                 EQU     0.000000000, 0.807843208, 0.819607913, 1.000000000
DarkViolet_F                                    EQU     0.580392182, 0.000000000, 0.827451050, 1.000000000
DeepPink_F                                      EQU     1.000000000, 0.078431375, 0.576470613, 1.000000000
DeepSkyBlue_F                                   EQU     0.000000000, 0.749019623, 1.000000000, 1.000000000
DimGray_F                                       EQU     0.411764741, 0.411764741, 0.411764741, 1.000000000
DodgerBlue_F                                    EQU     0.117647067, 0.564705908, 1.000000000, 1.000000000
Firebrick_F                                     EQU     0.698039234, 0.133333340, 0.133333340, 1.000000000
FloralWhite_F                                   EQU     1.000000000, 0.980392218, 0.941176534, 1.000000000
ForestGreen_F                                   EQU     0.133333340, 0.545098066, 0.133333340, 1.000000000
Fuchsia_F                                       EQU     1.000000000, 0.000000000, 1.000000000, 1.000000000
Gainsboro_F                                     EQU     0.862745166, 0.862745166, 0.862745166, 1.000000000
GhostWhite_F                                    EQU     0.972549081, 0.972549081, 1.000000000, 1.000000000
Gold_F                                          EQU     1.000000000, 0.843137324, 0.000000000, 1.000000000
Goldenrod_F                                     EQU     0.854902029, 0.647058845, 0.125490203, 1.000000000
Gray_F                                          EQU     0.501960814, 0.501960814, 0.501960814, 1.000000000
Green_F                                         EQU     0.000000000, 0.501960814, 0.000000000, 1.000000000
GreenYellow_F                                   EQU     0.678431392, 1.000000000, 0.184313729, 1.000000000
Honeydew_F                                      EQU     0.941176534, 1.000000000, 0.941176534, 1.000000000
HotPink_F                                       EQU     1.000000000, 0.411764741, 0.705882370, 1.000000000
IndianRed_F                                     EQU     0.803921640, 0.360784322, 0.360784322, 1.000000000
Indigo_F                                        EQU     0.294117659, 0.000000000, 0.509803951, 1.000000000
Ivory_F                                         EQU     1.000000000, 1.000000000, 0.941176534, 1.000000000
Khaki_F                                         EQU     0.941176534, 0.901960850, 0.549019635, 1.000000000
Lavender_F                                      EQU     0.901960850, 0.901960850, 0.980392218, 1.000000000
LavenderBlush_F                                 EQU     1.000000000, 0.941176534, 0.960784376, 1.000000000
LawnGreen_F                                     EQU     0.486274540, 0.988235354, 0.000000000, 1.000000000
LemonChiffon_F                                  EQU     1.000000000, 0.980392218, 0.803921640, 1.000000000
LightBlue_F                                     EQU     0.678431392, 0.847058892, 0.901960850, 1.000000000
LightCoral_F                                    EQU     0.941176534, 0.501960814, 0.501960814, 1.000000000
LightCyan_F                                     EQU     0.878431439, 1.000000000, 1.000000000, 1.000000000
LightGoldenrodYellow_F                          EQU     0.980392218, 0.980392218, 0.823529482, 1.000000000
LightGreen_F                                    EQU     0.564705908, 0.933333397, 0.564705908, 1.000000000
LightGray_F                                     EQU     0.827451050, 0.827451050, 0.827451050, 1.000000000
LightPink_F                                     EQU     1.000000000, 0.713725507, 0.756862819, 1.000000000
LightSalmon_F                                   EQU     1.000000000, 0.627451003, 0.478431404, 1.000000000
LightSeaGreen_F                                 EQU     0.125490203, 0.698039234, 0.666666687, 1.000000000
LightSkyBlue_F                                  EQU     0.529411793, 0.807843208, 0.980392218, 1.000000000
LightSlateGray_F                                EQU     0.466666698, 0.533333361, 0.600000024, 1.000000000
LightSteelBlue_F                                EQU     0.690196097, 0.768627524, 0.870588303, 1.000000000
LightYellow_F                                   EQU     1.000000000, 1.000000000, 0.878431439, 1.000000000
Lime_F                                          EQU     0.000000000, 1.000000000, 0.000000000, 1.000000000
LimeGreen_F                                     EQU     0.196078449, 0.803921640, 0.196078449, 1.000000000
Linen_F                                         EQU     0.980392218, 0.941176534, 0.901960850, 1.000000000
Magenta_F                                       EQU     1.000000000, 0.000000000, 1.000000000, 1.000000000
Maroon_F                                        EQU     0.501960814, 0.000000000, 0.000000000, 1.000000000
MediumAquamarine_F                              EQU     0.400000036, 0.803921640, 0.666666687, 1.000000000
MediumBlue_F                                    EQU     0.000000000, 0.000000000, 0.803921640, 1.000000000
MediumOrchid_F                                  EQU     0.729411781, 0.333333343, 0.827451050, 1.000000000
MediumPurple_F                                  EQU     0.576470613, 0.439215720, 0.858823597, 1.000000000
MediumSeaGreen_F                                EQU     0.235294133, 0.701960802, 0.443137288, 1.000000000
MediumSlateBlue_F                               EQU     0.482352972, 0.407843173, 0.933333397, 1.000000000
MediumSpringGreen_F                             EQU     0.000000000, 0.980392218, 0.603921592, 1.000000000
MediumTurquoise_F                               EQU     0.282352954, 0.819607913, 0.800000072, 1.000000000
MediumVioletRed_F                               EQU     0.780392230, 0.082352944, 0.521568656, 1.000000000
MidnightBlue_F                                  EQU     0.098039225, 0.098039225, 0.439215720, 1.000000000
MintCream_F                                     EQU     0.960784376, 1.000000000, 0.980392218, 1.000000000
MistyRose_F                                     EQU     1.000000000, 0.894117713, 0.882353008, 1.000000000
Moccasin_F                                      EQU     1.000000000, 0.894117713, 0.709803939, 1.000000000
NavajoWhite_F                                   EQU     1.000000000, 0.870588303, 0.678431392, 1.000000000
Navy_F                                          EQU     0.000000000, 0.000000000, 0.501960814, 1.000000000
OldLace_F                                       EQU     0.992156923, 0.960784376, 0.901960850, 1.000000000
Olive_F                                         EQU     0.501960814, 0.501960814, 0.000000000, 1.000000000
OliveDrab_F                                     EQU     0.419607878, 0.556862772, 0.137254909, 1.000000000
Orange_F                                        EQU     1.000000000, 0.647058845, 0.000000000, 1.000000000
OrangeRed_F                                     EQU     1.000000000, 0.270588249, 0.000000000, 1.000000000
Orchid_F                                        EQU     0.854902029, 0.439215720, 0.839215755, 1.000000000
PaleGoldenrod_F                                 EQU     0.933333397, 0.909803987, 0.666666687, 1.000000000
PaleGreen_F                                     EQU     0.596078455, 0.984313786, 0.596078455, 1.000000000
PaleTurquoise_F                                 EQU     0.686274529, 0.933333397, 0.933333397, 1.000000000
PaleVioletRed_F                                 EQU     0.858823597, 0.439215720, 0.576470613, 1.000000000
PapayaWhip_F                                    EQU     1.000000000, 0.937254965, 0.835294187, 1.000000000
PeachPuff_F                                     EQU     1.000000000, 0.854902029, 0.725490212, 1.000000000
Peru_F                                          EQU     0.803921640, 0.521568656, 0.247058839, 1.000000000
Pink_F                                          EQU     1.000000000, 0.752941251, 0.796078503, 1.000000000
Plum_F                                          EQU     0.866666734, 0.627451003, 0.866666734, 1.000000000
PowderBlue_F                                    EQU     0.690196097, 0.878431439, 0.901960850, 1.000000000
Purple_F                                        EQU     0.501960814, 0.000000000, 0.501960814, 1.000000000
Red_F                                           EQU     1.000000000, 0.000000000, 0.000000000, 1.000000000
RosyBrown_F                                     EQU     0.737254918, 0.560784340, 0.560784340, 1.000000000
RoyalBlue_F                                     EQU     0.254901975, 0.411764741, 0.882353008, 1.000000000
SaddleBrown_F                                   EQU     0.545098066, 0.270588249, 0.074509807, 1.000000000
Salmon_F                                        EQU     0.980392218, 0.501960814, 0.447058856, 1.000000000
SandyBrown_F                                    EQU     0.956862807, 0.643137276, 0.376470625, 1.000000000
SeaGreen_F                                      EQU     0.180392161, 0.545098066, 0.341176480, 1.000000000
SeaShell_F                                      EQU     1.000000000, 0.960784376, 0.933333397, 1.000000000
Sienna_F                                        EQU     0.627451003, 0.321568638, 0.176470593, 1.000000000
Silver_F                                        EQU     0.752941251, 0.752941251, 0.752941251, 1.000000000
SkyBlue_F                                       EQU     0.529411793, 0.807843208, 0.921568692, 1.000000000
SlateBlue_F                                     EQU     0.415686309, 0.352941185, 0.803921640, 1.000000000
SlateGray_F                                     EQU     0.439215720, 0.501960814, 0.564705908, 1.000000000
Snow_F                                          EQU     1.000000000, 0.980392218, 0.980392218, 1.000000000
SpringGreen_F                                   EQU     0.000000000, 1.000000000, 0.498039246, 1.000000000
SteelBlue_F                                     EQU     0.274509817, 0.509803951, 0.705882370, 1.000000000
Tan_F                                           EQU     0.823529482, 0.705882370, 0.549019635, 1.000000000
Teal_F                                          EQU     0.000000000, 0.501960814, 0.501960814, 1.000000000
Thistle_F                                       EQU     0.847058892, 0.749019623, 0.847058892, 1.000000000
Tomato_F                                        EQU     1.000000000, 0.388235331, 0.278431386, 1.000000000
Transparent_F                                   EQU     0.000000000, 0.000000000, 0.000000000, 0.000000000
Turquoise_F                                     EQU     0.250980407, 0.878431439, 0.815686345, 1.000000000
Violet_F                                        EQU     0.933333397, 0.509803951, 0.933333397, 1.000000000
Wheat_F                                         EQU     0.960784376, 0.870588303, 0.701960802, 1.000000000
White_F                                         EQU     1.000000000, 1.000000000, 1.000000000, 1.000000000
WhiteSmoke_F                                    EQU     0.960784376, 0.960784376, 0.960784376, 1.000000000
Yellow_F                                        EQU     1.000000000, 1.000000000, 0.000000000, 1.000000000
YellowGreen_F                                   EQU     0.603921592, 0.803921640, 0.196078449, 1.000000000

COLORU2RGB(%COLORNUMBER) MACRO
    Mov Eax,((%COLORNUMBER And 0FFH) << 16) Or (%COLORNUMBER And 0FF00H) Or ((%COLORNUMBER And 0FFH) << 16)
ENDM

;======================================== Structures ======================================;
ID2D1ResourceVtbl STRUCT
    QueryInterface DQ
    AddRef         DQ
    Release        DQ
    GetFactory     DQ
ENDS

ID2D1BitmapVtbl STRUCT
    QueryInterface       DQ
    AddRef               DQ
    Release              DQ
    GetFactory           DQ
    GetSize              DQ
    GetPixelSize         DQ
    GetPixelFormat       DQ
    GetDpi               DQ
    CopyFromBitmap       DQ
    CopyFromRenderTarget DQ
    CopyFromMemory       DQ
ENDS

ID2D1GradientStopCollectionVtbl STRUCT
    QueryInterface             DQ
    AddRef                     DQ
    Release                    DQ
    GetFactory                 DQ
    GetGradientStopCount       DQ
    GetGradientStops           DQ
    GetColorInterpolationGamma DQ
    GetExtendMode              DQ
ENDS

ID2D1BitmapBrushVtbl STRUCT
    QueryInterface       DQ
    AddRef               DQ
    Release              DQ
    GetFactory           DQ
    SetOpacity           DQ
    SetTransform         DQ
    GetOpacity           DQ
    GetTransform         DQ
    SetExtendModeX       DQ
    SetExtendModeY       DQ
    SetInterpolationMode DQ
    SetBitmap            DQ
    GetExtendModeX       DQ
    GetExtendModeY       DQ
    GetInterpolationMode DQ
    GetBitmap            DQ
ENDS

ID2D1SolidColorBrushVtbl STRUCT
    QueryInterface DQ
    AddRef         DQ
    Release        DQ
    GetFactory     DQ
    SetOpacity     DQ
    SetTransform   DQ
    GetOpacity     DQ
    GetTransform   DQ
    SetColor       DQ
    GetColor       DQ
ENDS

ID2D1LinearGradientBrushVtbl STRUCT
    QueryInterface            DQ
    AddRef                    DQ
    Release                   DQ
    GetFactory                DQ
    SetOpacity                DQ
    SetTransform              DQ
    GetOpacity                DQ
    GetTransform              DQ
    SetStartPoint             DQ
    SetEndPoint               DQ
    GetStartPoint             DQ
    GetEndPoint               DQ
    GetGradientStopCollection DQ
ENDS

ID2D1RadialGradientBrushVtbl STRUCT
    QueryInterface            DQ
    AddRef                    DQ
    Release                   DQ
    GetFactory                DQ
    SetOpacity                DQ
    SetTransform              DQ
    GetOpacity                DQ
    GetTransform              DQ
    SetCenter                 DQ
    SetGradientOriginOffset   DQ
    SetRadiusX                DQ
    SetRadiusY                DQ
    GetCenter                 DQ
    GetGradientOriginOffset   DQ
    GetRadiusX                DQ
    GetRadiusY                DQ
    GetGradientStopCollection DQ
ENDS

ID2D1StrokeStyleVtbl STRUCT
    QueryInterface    DQ
    AddRef            DQ
    Release           DQ
    GetFactory        DQ
    GetStartCap       DQ
    GetEndCap         DQ
    GetDashCap        DQ
    GetMiterLimit     DQ
    GetLineJoin       DQ
    GetDashOffset     DQ
    GetDashStyle      DQ
    GetDashesCount    DQ
    GetDashes         DQ
ENDS

ID2D1RectangleGeometryVtbl STRUCT
    QueryInterface       DQ
    AddRef               DQ
    Release              DQ
    GetFactory           DQ
    GetBounds            DQ
    GetWidenedBounds     DQ
    StrokeContainsPoint  DQ
    FillContainsPoint    DQ
    CompareWithGeometry  DQ
    Simplify             DQ
    Tessellate           DQ
    CombineWithGeometry  DQ
    Outline              DQ
    ComputeArea          DQ
    ComputeLength        DQ
    ComputePointAtLength DQ
    Widen                DQ
    GetRect              DQ
ENDS

ID2D1RoundedRectangleGeometryVtbl STRUCT
    QueryInterface       DQ
    AddRef               DQ
    Release              DQ
    GetFactory           DQ
    GetBounds            DQ
    GetWidenedBounds     DQ
    StrokeContainsPoint  DQ
    FillContainsPoint    DQ
    CompareWithGeometry  DQ
    Simplify             DQ
    Tessellate           DQ
    CombineWithGeometry  DQ
    Outline              DQ
    ComputeArea          DQ
    ComputeLength        DQ
    ComputePointAtLength DQ
    Widen                DQ
    GetRoundedRect       DQ
ENDS

ID2D1EllipseGeometryVtbl STRUCT
    QueryInterface       DQ
    AddRef               DQ
    Release              DQ
    GetFactory           DQ
    GetBounds            DQ
    GetWidenedBounds     DQ
    StrokeContainsPoint  DQ
    FillContainsPoint    DQ
    CompareWithGeometry  DQ
    Simplify             DQ
    Tessellate           DQ
    CombineWithGeometry  DQ
    Outline              DQ
    ComputeArea          DQ
    ComputeLength        DQ
    ComputePointAtLength DQ
    Widen                DQ
    GetEllipse           DQ
ENDS

ID2D1GeometryGroupVtbl STRUCT
    QueryInterface         DQ
    AddRef                 DQ
    Release                DQ
    GetFactory             DQ
    GetBounds              DQ
    GetWidenedBounds       DQ
    StrokeContainsPoint    DQ
    FillContainsPoint      DQ
    CompareWithGeometry    DQ
    Simplify               DQ
    Tessellate             DQ
    CombineWithGeometry    DQ
    Outline                DQ
    ComputeArea            DQ
    ComputeLength          DQ
    ComputePointAtLength   DQ
    Widen                  DQ
    GetFillMode            DQ
    GetSourceGeometryCount DQ
    GetSourceGeometries    DQ
ENDS

ID2D1TransformedGeometryVtbl STRUCT
    QueryInterface       DQ
    AddRef               DQ
    Release              DQ
    GetFactory           DQ
    GetBounds            DQ
    GetWidenedBounds     DQ
    StrokeContainsPoint  DQ
    FillContainsPoint    DQ
    CompareWithGeometry  DQ
    Simplify             DQ
    Tessellate           DQ
    CombineWithGeometry  DQ
    Outline              DQ
    ComputeArea          DQ
    ComputeLength        DQ
    ComputePointAtLength DQ
    Widen                DQ
    GetSourceGeometry    DQ
    GetTransform         DQ
ENDS

ID2D1GeometrySinkVtbl STRUCT
    QueryInterface                  DQ
    AddRef                          DQ
    Release                         DQ
    SetFillMode                     DQ
    SetSegmentFlags                 DQ
    BeginFigure                     DQ
    AddLines                        DQ
    AddBeziers                      DQ
    EndFigure                       DQ
    Close                           DQ
    AddLine                         DQ
    AddBezier                       DQ
    AddQuadraticBezier              DQ
    AddQuadraticBeziers             DQ
    AddArc                          DQ
ENDS

ID2D1TessellationSinkVtbl STRUCT
    QueryInterface  DQ
    AddRef          DQ
    Release         DQ
    AddTriangles    DQ
    Close           DQ
ENDS

ID2D1PathGeometryVtbl STRUCT
    QueryInterface       DQ
    AddRef               DQ
    Release              DQ
    GetFactory           DQ
    GetBounds            DQ
    GetWidenedBounds     DQ
    StrokeContainsPoint  DQ
    FillContainsPoint    DQ
    CompareWithGeometry  DQ
    Simplify             DQ
    Tessellate           DQ
    CombineWithGeometry  DQ
    Outline              DQ
    ComputeArea          DQ
    ComputeLength        DQ
    ComputePointAtLength DQ
    Widen                DQ
    Open                 DQ
    Stream               DQ
    GetSegmentCount      DQ
    GetFigureCount       DQ
ENDS

ID2D1MeshVtbl STRUCT
    QueryInterface    DQ
    AddRef            DQ
    Release           DQ
    GetFactory        DQ
    Open              DQ
ENDS

ID2D1LayerVtbl STRUCT
    QueryInterface    DQ
    AddRef            DQ
    Release           DQ
    GetFactory        DQ
    GetSize           DQ
ENDS

ID2D1DrawingStateBlockVtbl STRUCT
    QueryInterface         DQ
    AddRef                 DQ
    Release                DQ
    GetFactory             DQ
    GetDescription         DQ
    SetDescription         DQ
    SetTextRenderingParams DQ
    GetTextRenderingParams DQ
ENDS

ID2D1RenderTargetVtbl STRUCT
    QueryInterface               DQ
    AddRef                       DQ
    Release                      DQ
    GetFactory                   DQ
    CreateBitmap                 DQ
    CreateBitmapFromWicBitmap    DQ
    CreateSharedBitmap           DQ
    CreateBitmapBrush            DQ
    CreateSolidColorBrush        DQ
    CreateGradientStopCollection DQ
    CreateLinearGradientBrush    DQ
    CreateRadialGradientBrush    DQ
    CreateCompatibleRenderTarget DQ
    CreateLayer                  DQ
    CreateMesh                   DQ
    DrawLine                     DQ
    DrawRectangle                DQ
    FillRectangle                DQ
    DrawRoundedRectangle         DQ
    FillRoundedRectangle         DQ
    DrawEllipse                  DQ
    FillEllipse                  DQ
    DrawGeometry                 DQ
    FillGeometry                 DQ
    FillMesh                     DQ
    FillOpacityMask              DQ
    DrawBitmap                   DQ
    DrawText_                    DQ
    DrawTextLayout               DQ
    DrawGlyphRun                 DQ
    SetTransform                 DQ
    GetTransform                 DQ
    SetAntialiasMode             DQ
    GetAntialiasMode             DQ
    SetTextAntialiasMode         DQ
    GetTextAntialiasMode         DQ
    SetTextRenderingParams       DQ
    GetTextRenderingParams       DQ
    SetTags                      DQ
    GetTags                      DQ
    PushLayer                    DQ
    PopLayer                     DQ
    Flush                        DQ
    SaveDrawingState             DQ
    RestoreDrawingState          DQ
    PushAxisAlignedClip          DQ
    PopAxisAlignedClip           DQ
    Clear                        DQ
    BeginDraw                    DQ
    EndDraw                      DQ
    GetPixelFormat               DQ
    SetDpi                       DQ
    GetDpi                       DQ
    GetSize                      DQ
    GetPixelSize                 DQ
    GetMaximumBitmapSize         DQ
    IsSupported                  DQ
ENDS

ID2D1BitmapRenderTargetVtbl STRUCT
    QueryInterface               DQ
    AddRef                       DQ
    Release                      DQ
    GetFactory                   DQ
    CreateBitmap                 DQ
    CreateBitmapFromWicBitmap    DQ
    CreateSharedBitmap           DQ
    CreateBitmapBrush            DQ
    CreateSolidColorBrush        DQ
    CreateGradientStopCollection DQ
    CreateLinearGradientBrush    DQ
    CreateRadialGradientBrush    DQ
    CreateCompatibleRenderTarget DQ
    CreateLayer                  DQ
    CreateMesh                   DQ
    DrawLine                     DQ
    DrawRectangle                DQ
    FillRectangle                DQ
    DrawRoundedRectangle         DQ
    FillRoundedRectangle         DQ
    DrawEllipse                  DQ
    FillEllipse                  DQ
    DrawGeometry                 DQ
    FillGeometry                 DQ
    FillMesh                     DQ
    FillOpacityMask              DQ
    DrawBitmap                   DQ
    DrawText_                    DQ
    DrawTextLayout               DQ
    DrawGlyphRun                 DQ
    SetTransform                 DQ
    GetTransform                 DQ
    SetAntialiasMode             DQ
    GetAntialiasMode             DQ
    SetTextAntialiasMode         DQ
    GetTextAntialiasMode         DQ
    SetTextRenderingParams       DQ
    GetTextRenderingParams       DQ
    SetTags                      DQ
    GetTags                      DQ
    PushLayer                    DQ
    PopLayer                     DQ
    Flush                        DQ
    SaveDrawingState             DQ
    RestoreDrawingState          DQ
    PushAxisAlignedClip          DQ
    PopAxisAlignedClip           DQ
    Clear                        DQ
    BeginDraw                    DQ
    EndDraw                      DQ
    GetPixelFormat               DQ
    SetDpi                       DQ
    GetDpi                       DQ
    GetSize                      DQ
    GetPixelSize                 DQ
    GetMaximumBitmapSize         DQ
    IsSupported                  DQ
    GetBitmap                    DQ
ENDS

ID2D1HwndRenderTargetVtbl STRUCT
    QueryInterface               DQ
    AddRef                       DQ
    Release                      DQ
    GetFactory                   DQ
    CreateBitmap                 DQ
    CreateBitmapFromWicBitmap    DQ
    CreateSharedBitmap           DQ
    CreateBitmapBrush            DQ
    CreateSolidColorBrush        DQ
    CreateGradientStopCollection DQ
    CreateLinearGradientBrush    DQ
    CreateRadialGradientBrush    DQ
    CreateCompatibleRenderTarget DQ
    CreateLayer                  DQ
    CreateMesh                   DQ
    DrawLine                     DQ
    DrawRectangle                DQ
    FillRectangle                DQ
    DrawRoundedRectangle         DQ
    FillRoundedRectangle         DQ
    DrawEllipse                  DQ
    FillEllipse                  DQ
    DrawGeometry                 DQ
    FillGeometry                 DQ
    FillMesh                     DQ
    FillOpacityMask              DQ
    DrawBitmap                   DQ
    DrawText_                    DQ
    DrawTextLayout               DQ
    DrawGlyphRun                 DQ
    SetTransform                 DQ
    GetTransform                 DQ
    SetAntialiasMode             DQ
    GetAntialiasMode             DQ
    SetTextAntialiasMode         DQ
    GetTextAntialiasMode         DQ
    SetTextRenderingParams       DQ
    GetTextRenderingParams       DQ
    SetTags                      DQ
    GetTags                      DQ
    PushLayer                    DQ
    PopLayer                     DQ
    Flush                        DQ
    SaveDrawingState             DQ
    RestoreDrawingState          DQ
    PushAxisAlignedClip          DQ
    PopAxisAlignedClip           DQ
    Clear                        DQ
    BeginDraw                    DQ
    EndDraw                      DQ
    GetPixelFormat               DQ
    SetDpi                       DQ
    GetDpi                       DQ
    GetSize                      DQ
    GetPixelSize                 DQ
    GetMaximumBitmapSize         DQ
    IsSupported                  DQ
    CheckWindowState             DQ
    Resize                       DQ
    GetHwnd                      DQ
ENDS

ID2D1GdiInteropRenderTargetVtbl STRUCT
    QueryInterface  DQ
    AddRef          DQ
    Release         DQ
    GetDC           DQ
    ReleaseDC       DQ
ENDS

ID2D1DCRenderTargetVtbl STRUCT
    QueryInterface               DQ
    AddRef                       DQ
    Release                      DQ
    GetFactory                   DQ
    CreateBitmap                 DQ
    CreateBitmapFromWicBitmap    DQ
    CreateSharedBitmap           DQ
    CreateBitmapBrush            DQ
    CreateSolidColorBrush        DQ
    CreateGradientStopCollection DQ
    CreateLinearGradientBrush    DQ
    CreateRadialGradientBrush    DQ
    CreateCompatibleRenderTarget DQ
    CreateLayer                  DQ
    CreateMesh                   DQ
    DrawLine                     DQ
    DrawRectangle                DQ
    FillRectangle                DQ
    DrawRoundedRectangle         DQ
    FillRoundedRectangle         DQ
    DrawEllipse                  DQ
    FillEllipse                  DQ
    DrawGeometry                 DQ
    FillGeometry                 DQ
    FillMesh                     DQ
    FillOpacityMask              DQ
    DrawBitmap                   DQ
    DrawText_                    DQ
    DrawTextLayout               DQ
    DrawGlyphRun                 DQ
    SetTransform                 DQ
    GetTransform                 DQ
    SetAntialiasMode             DQ
    GetAntialiasMode             DQ
    SetTextAntialiasMode         DQ
    GetTextAntialiasMode         DQ
    SetTextRenderingParams       DQ
    GetTextRenderingParams       DQ
    SetTags                      DQ
    GetTags                      DQ
    PushLayer                    DQ
    PopLayer                     DQ
    Flush                        DQ
    SaveDrawingState             DQ
    RestoreDrawingState          DQ
    PushAxisAlignedClip          DQ
    PopAxisAlignedClip           DQ
    Clear                        DQ
    BeginDraw                    DQ
    EndDraw                      DQ
    GetPixelFormat               DQ
    SetDpi                       DQ
    GetDpi                       DQ
    GetSize                      DQ
    GetPixelSize                 DQ
    GetMaximumBitmapSize         DQ
    IsSupported                  DQ
    BindDC                       DQ
ENDS

ID2D1FactoryVtbl STRUCT
    QueryInterface                 DQ
    AddRef                         DQ
    Release                        DQ
    ReloadSystemMetrics            DQ
    GetDesktopDpi                  DQ
    CreateRectangleGeometry        DQ
    CreateRoundedRectangleGeometry DQ
    CreateEllipseGeometry          DQ
    CreateGeometryGroup            DQ
    CreateTransformedGeometry      DQ
    CreatePathGeometry             DQ
    CreateStrokeStyle              DQ
    CreateDrawingStateBlock        DQ
    CreateWicBitmapRenderTarget    DQ
    CreateHwndRenderTarget         DQ
    CreateDxgiSurfaceRenderTarget  DQ
    CreateDCRenderTarget           DQ
ENDS

#ifndef D3DCOLORVALUE_DEFINED
    #define D3DCOLORVALUE_DEFINED 1
    D3DCOLORVALUE STRUCT
        r DD
        g DD
        b DD
        a DD
    ENDS
#endif

D2D_POINT_2U STRUCT
    x DD
    y DD
ENDS

D2D_POINT_2F STRUCT
    x DD
    y DD
ENDS

D2D_VECTOR_3F STRUCT
    x DD
    y DD
    z DD
ENDS

D2D_VECTOR_4F STRUCT
    x DD
    y DD
    z DD
    w DD
ENDS

D2D_RECT_F STRUCT
    left   DD
    top    DD
    right  DD
    bottom DD
ENDS

D2D_RECT_U STRUCT  ALIGNMODE
    left   DD
    top    DD
    right  DD
    bottom DD
ENDS

D2D_SIZE_F STRUCT
    width_ DD
    height DD
ENDS

D2D_SIZE_U STRUCT
    width_ DD
    height DD
ENDS

#define D2D_COLOR_F D3DCOLORVALUE
#define D2D_RECT_L  RECT

D2D_MATRIX_3X2_F STRUCT
    _11 DD
    _12 DD
    _21 DD
    _22 DD
    _31 DD
    _32 DD
ENDS

D2D_MATRIX_4X3_F STRUCT
    _11 DD
    _12 DD
    _13 DD
    _21 DD
    _22 DD
    _23 DD
    _31 DD
    _32 DD
    _33 DD
    _41 DD
    _42 DD
    _43 DD
ENDS

D2D_MATRIX_4X4_F STRUCT
    _11 DD
    _12 DD
    _13 DD
    _14 DD
    _21 DD
    _22 DD
    _23 DD
    _24 DD
    _31 DD
    _32 DD
    _33 DD
    _34 DD
    _41 DD
    _42 DD
    _43 DD
    _44 DD
ENDS

D2D_MATRIX_5X4_F STRUCT
    _11 DD
    _12 DD
    _13 DD
    _14 DD
    _21 DD
    _22 DD
    _23 DD
    _24 DD
    _31 DD
    _32 DD
    _33 DD
    _34 DD
    _41 DD
    _42 DD
    _43 DD
    _44 DD
    _51 DD
    _52 DD
    _53 DD
    _54 DD
ENDS

#define D2D1_POINT_2U     D2D_POINT_2U
#define D2D1_POINT_2F     D2D_POINT_2F
#define D2D1_RECT_F       D2D_RECT_F
#define D2D1_RECT_U       D2D_RECT_U
#define D2D1_SIZE_F       D2D_SIZE_F
#define D2D1_SIZE_U       D2D_SIZE_U
#define D2D1_COLOR_F      D2D_COLOR_F
#define D2D1_MATRIX_3X2_F D2D_MATRIX_3X2_F
#define D2D1_TAG          UINT64

D2D1_PIXEL_FORMAT STRUCT
     format    DXGI_FORMAT
     alphaMode D2D1_ALPHA_MODE
ENDS

D2D1_RENDER_TARGET_PROPERTIES STRUCT
     Type_       D2D1_RENDER_TARGET_TYPE 
     pixelFormat D2D1_PIXEL_FORMAT
     dpiX        DD                   
     dpiY        DD                   
     usage       D2D1_RENDER_TARGET_USAGE
     minLevel    D2D1_FEATURE_LEVEL      
ENDS

D2D1_BITMAP_PROPERTIES STRUCT
    pixelFormat D2D1_PIXEL_FORMAT
    dpiX        DD            
    dpiY        DD            
ENDS

D2D1_GRADIENT_STOP STRUCT
    position DD       
    color_   D2D1_COLOR_F
ENDS

D2D1_BRUSH_PROPERTIES STRUCT
    opacity   DD            
    transform D2D1_MATRIX_3X2_F
ENDS

D2D1_BITMAP_BRUSH_PROPERTIES STRUCT
    extendModeX       D2D1_EXTEND_MODE              
    extendModeY       D2D1_EXTEND_MODE              
    interpolationMode D2D1_BITMAP_INTERPOLATION_MODE
ENDS

D2D1_LINEAR_GRADIENT_BRUSH_PROPERTIES STRUCT
    startPoint D2D1_POINT_2F
    endPoint   D2D1_POINT_2F
ENDS

D2D1_RADIAL_GRADIENT_BRUSH_PROPERTIES STRUCT
    center               D2D1_POINT_2F
    gradientOriginOffset D2D1_POINT_2F
    radiusX              DD        
    radiusY              DD        
ENDS

D2D1_BEZIER_SEGMENT STRUCT
    point1 D2D1_POINT_2F
    point2 D2D1_POINT_2F
    point3 D2D1_POINT_2F
ENDS

D2D1_TRIANGLE STRUCT
    point1 D2D1_POINT_2F
    point2 D2D1_POINT_2F
    point3 D2D1_POINT_2F
ENDS

D2D1_ARC_SEGMENT STRUCT
    point          D2D1_POINT_2F
    size_          D2D1_SIZE_F
    rotationAngle  DD               
    sweepDirection D2D1_SWEEP_DIRECTION
    arcSize        D2D1_ARC_SIZE       
ENDS

D2D1_QUADRATIC_BEZIER_SEGMENT STRUCT
    point1 D2D1_POINT_2F
    point2 D2D1_POINT_2F
ENDS

D2D1_ELLIPSE STRUCT
    point   D2D1_POINT_2F
    radiusX DD        
    radiusY DD        
ENDS

D2D1_ROUNDED_RECT STRUCT
    rect    D2D1_RECT_F
    radiusX DD      
    radiusY DD      
ENDS

D2D1_STROKE_STYLE_PROPERTIES STRUCT
    startCap   D2D1_CAP_STYLE 
    endCap     D2D1_CAP_STYLE 
    dashCap    D2D1_CAP_STYLE 
    lineJoin   D2D1_LINE_JOIN 
    miterLimit DD          
    dashStyle  D2D1_DASH_STYLE
    dashOffset DD          
ENDS

D2D1_LAYER_PARAMETER STRUCT
    contentBounds     D2D1_RECT_F
    geometricMask     DD                 
    maskAntialiasMode D2D1_ANTIALIAS_MODE
    maskTransform     D2D1_MATRIX_3X2_F
    opacity           DD              
    opacityBrush      DD                 
    layerOptions      D2D1_LAYER_OPTIONS 
ENDS

D2D1_HWND_RENDER_TARGET_PROPERTIES STRUCT
    hwnd           HANDLE
    pixelSize      D2D1_SIZE_U
    presentOptions D2D1_PRESENT_OPTIONS
ENDS

D2D1_DRAWING_STATE_DESCRIPTION STRUCT
    antialiasMode     D2D1_ANTIALIAS_MODE     
    textAntialiasMode D2D1_TEXT_ANTIALIAS_MODE
    tag1              D2D1_TAG                
    tag2              D2D1_TAG                
    transform         D2D1_MATRIX_3X2_F
ENDS

D2D1_FACTORY_OPTIONS STRUCT
    debugLevel D2D1_DEBUG_LEVEL
ENDS

;====================================== GUID values =======================================;
; ==== If any of them is nedeed it has to be in the '.Data' section of the source code ====;
;ID2D1Resource                      GUID    <02CD90691H, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>>
;ID2D1Image                         GUID    <065019F75H, 08DA2H, 0497CH, <0B3H, 02CH, 0DFH, 0A3H, 04EH, 048H, 0EDH, 0E6H>>
;ID2D1Bitmap                        GUID    <0A2296057H, 0EA42H, 04099H, <098H, 03BH, 053H, 09FH, 0B6H, 050H, 054H, 026H>>
;ID2D1GradientStopCollection        GUID    <02CD906A7H, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>>
;ID2D1Brush                         GUID    <02CD906A8H, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>>
;ID2D1BitmapBrush                   GUID    <02CD906AAH, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>>
;ID2D1SolidColorBrush               GUID    <02CD906A9H, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>>
;ID2D1LinearGradientBrush           GUID    <02CD906ABH, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>>
;ID2D1RadialGradientBrush           GUID    <02CD906ACH, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>>
;ID2D1StrokeStyle                   GUID    <02CD9069DH, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>>
;ID2D1Geometry                      GUID    <02CD906A1H, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>>
;ID2D1RectangleGeometry             GUID    <02CD906A2H, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>>
;ID2D1RoundedRectangleGeometry      GUID    <02CD906A3H, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>>
;ID2D1EllipseGeometry               GUID    <02CD906A4H, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>>
;ID2D1GeometryGroup                 GUID    <02CD906A6H, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>>
;ID2D1TransformedGeometry           GUID    <02CD906BBH, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>>
;ID2D1SimplifiedGeometrySink        GUID    <02CD9069EH, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>>
;ID2D1GeometrySink                  GUID    <02CD9069FH, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>>
;ID2D1TessellationSink              GUID    <02CD906C1H, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>>
;ID2D1PathGeometry                  GUID    <02CD906A5H, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>>
;ID2D1Mesh                          GUID    <02CD906C2H, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>>
;ID2D1Layer                         GUID    <02CD9069BH, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>>
;ID2D1DrawingStateBlock             GUID    <028506E39H, 0EBF6H, 046A1H, <0BBH, 047H, 0FDH, 085H, 056H, 05AH, 0B9H, 057H>>
;ID2D1RenderTarget                  GUID    <02CD90694H, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>>
;ID2D1BitmapRenderTarget            GUID    <02CD90695H, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>>
;ID2D1HwndRenderTarget              GUID    <02CD90698H, 012E2H, 011DCH, <09FH, 0EDH, 000H, 011H, 043H, 0A0H, 055H, 0F9H>>
;ID2D1GdiInteropRenderTarget        GUID    <0E0DB51C3H, 06F77H, 04BAEH, <0B3H, 0D5H, 0E4H, 075H, 009H, 0B3H, 058H, 038H>>
;ID2D1DCRenderTarget                GUID    <01C51BC64H, 0DE61H, 046FDH, <098H, 099H, 063H, 0A5H, 0D8H, 0F0H, 039H, 050H>>
;ID2D1Factory                       GUID    <006152247H, 06F50H, 0465AH, <092H, 045H, 011H, 08BH, 0FDH, 03BH, 060H, 007H>>

#endif /* D2D1_H */
