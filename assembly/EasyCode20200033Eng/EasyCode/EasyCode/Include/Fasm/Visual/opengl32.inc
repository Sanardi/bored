; ====================================================;
;                                                     ;
;     opengl32.inc for EC v2 Fasm visual projects     ;
;                   (version 1.0.1)                   ;
;                                                     ;
;            Copyright © Ramon Sala - 2019            ;
;                                                     ;
; ====================================================;

if ~defined OPENGL32_INC
define OPENGL32_INC 1


GL_VERSION_1_1                                  equ     1

GL_ACCUM                                        equ     0100H
GL_LOAD                                         equ     0101H
GL_RETURN                                       equ     0102H
GL_MULT                                         equ     0103H
GL_ADD                                          equ     0104H

GL_NEVER                                        equ     0200H
GL_LESS                                         equ     0201H
GL_EQUAL                                        equ     0202H
GL_LEQUAL                                       equ     0203H
GL_GREATER                                      equ     0204H
GL_NOTEQUAL                                     equ     0205H
GL_GEQUAL                                       equ     0206H
GL_ALWAYS                                       equ     0207H

GL_CURRENT_BIT                                  equ     00000001H
GL_POINT_BIT                                    equ     00000002H
GL_LINE_BIT                                     equ     00000004H
GL_POLYGON_BIT                                  equ     00000008H
GL_POLYGON_STIPPLE_BIT                          equ     00000010H
GL_PIXEL_MODE_BIT                               equ     00000020H
GL_LIGHTING_BIT                                 equ     00000040H
GL_FOG_BIT                                      equ     00000080H
GL_DEPTH_BUFFER_BIT                             equ     00000100H
GL_ACCUM_BUFFER_BIT                             equ     00000200H
GL_STENCIL_BUFFER_BIT                           equ     00000400H
GL_VIEWPORT_BIT                                 equ     00000800H
GL_TRANSFORM_BIT                                equ     00001000H
GL_ENABLE_BIT                                   equ     00002000H
GL_COLOR_BUFFER_BIT                             equ     00004000H
GL_HINT_BIT                                     equ     00008000H
GL_EVAL_BIT                                     equ     00010000H
GL_LIST_BIT                                     equ     00020000H
GL_TEXTURE_BIT                                  equ     00040000H
GL_SCISSOR_BIT                                  equ     00080000H
GL_ALL_ATTRIB_BITS                              equ     000FFFFFH

GL_POINTS                                       equ     0000H
GL_LINES                                        equ     0001H
GL_LINE_LOOP                                    equ     0002H
GL_LINE_STRIP                                   equ     0003H
GL_TRIANGLES                                    equ     0004H
GL_TRIANGLE_STRIP                               equ     0005H
GL_TRIANGLE_FAN                                 equ     0006H
GL_QUADS                                        equ     0007H
GL_QUAD_STRIP                                   equ     0008H
GL_POLYGON                                      equ     0009H

GL_ZERO                                         equ     0
GL_ONE                                          equ     1
GL_SRC_COLOR                                    equ     0300H
GL_ONE_MINUS_SRC_COLOR                          equ     0301H
GL_SRC_ALPHA                                    equ     0302H
GL_ONE_MINUS_SRC_ALPHA                          equ     0303H
GL_DST_ALPHA                                    equ     0304H
GL_ONE_MINUS_DST_ALPHA                          equ     0305H
GL_DST_COLOR                                    equ     0306H
GL_ONE_MINUS_DST_COLOR                          equ     0307H
GL_SRC_ALPHA_SATURATE                           equ     0308H

GL_TRUE                                         equ     1
GL_FALSE                                        equ     0

GL_CLIP_PLANE0                                  equ     3000H
GL_CLIP_PLANE1                                  equ     3001H
GL_CLIP_PLANE2                                  equ     3002H
GL_CLIP_PLANE3                                  equ     3003H
GL_CLIP_PLANE4                                  equ     3004H
GL_CLIP_PLANE5                                  equ     3005H

GL_BYTE                                         equ     1400H
GL_UNSIGNED_BYTE                                equ     1401H
GL_SHORT                                        equ     1402H
GL_UNSIGNED_SHORT                               equ     1403H
GL_INT                                          equ     1404H
GL_UNSIGNED_INT                                 equ     1405H
GL_FLOAT                                        equ     1406H
GL_2_BYTES                                      equ     1407H
GL_3_BYTES                                      equ     1408H
GL_4_BYTES                                      equ     1409H
GL_DOUBLE                                       equ     140AH

GL_NONE                                         equ     0
GL_FRONT_LEFT                                   equ     0400H
GL_FRONT_RIGHT                                  equ     0401H
GL_BACK_LEFT                                    equ     0402H
GL_BACK_RIGHT                                   equ     0403H
GL_FRONT                                        equ     0404H
GL_BACK                                         equ     0405H
GL_LEFT                                         equ     0406H
GL_RIGHT                                        equ     0407H
GL_FRONT_AND_BACK                               equ     0408H
GL_AUX0                                         equ     0409H
GL_AUX1                                         equ     040AH
GL_AUX2                                         equ     040BH
GL_AUX3                                         equ     040CH

GL_NO_ERROR                                     equ     0
GL_INVALID_ENUM                                 equ     0500H
GL_INVALID_VALUE                                equ     0501H
GL_INVALID_OPERATION                            equ     0502H
GL_STACK_OVERFLOW                               equ     0503H
GL_STACK_UNDERFLOW                              equ     0504H
GL_OUT_OF_MEMORY                                equ     0505H

GL_2D                                           equ     0600H
GL_3D                                           equ     0601H
GL_3D_COLOR                                     equ     0602H
GL_3D_COLOR_TEXTURE                             equ     0603H
GL_4D_COLOR_TEXTURE                             equ     0604H

GL_PASS_THROUGH_TOKEN                           equ     0700H
GL_POINT_TOKEN                                  equ     0701H
GL_LINE_TOKEN                                   equ     0702H
GL_POLYGON_TOKEN                                equ     0703H
GL_BITMAP_TOKEN                                 equ     0704H
GL_DRAW_PIXEL_TOKEN                             equ     0705H
GL_COPY_PIXEL_TOKEN                             equ     0706H
GL_LINE_RESET_TOKEN                             equ     0707H

GL_EXP                                          equ     0800H
GL_EXP2                                         equ     0801H

GL_CW                                           equ     0900H
GL_CCW                                          equ     0901H

GL_COEFF                                        equ     0A00H
GL_ORDER                                        equ     0A01H
GL_DOMAIN                                       equ     0A02H

GL_CURRENT_COLOR                                equ     0B00H
GL_CURRENT_INDEX                                equ     0B01H
GL_CURRENT_NORMAL                               equ     0B02H
GL_CURRENT_TEXTURE_COORDS                       equ     0B03H
GL_CURRENT_RASTER_COLOR                         equ     0B04H
GL_CURRENT_RASTER_INDEX                         equ     0B05H
GL_CURRENT_RASTER_TEXTURE_COORDS                equ     0B06H
GL_CURRENT_RASTER_POSITION                      equ     0B07H
GL_CURRENT_RASTER_POSITION_VALID                equ     0B08H
GL_CURRENT_RASTER_DISTANCE                      equ     0B09H
GL_POINT_SMOOTH                                 equ     0B10H
GL_POINT_SIZE                                   equ     0B11H
GL_POINT_SIZE_RANGE                             equ     0B12H
GL_POINT_SIZE_GRANULARITY                       equ     0B13H
GL_LINE_SMOOTH                                  equ     0B20H
GL_LINE_WIDTH                                   equ     0B21H
GL_LINE_WIDTH_RANGE                             equ     0B22H
GL_LINE_WIDTH_GRANULARITY                       equ     0B23H
GL_LINE_STIPPLE                                 equ     0B24H
GL_LINE_STIPPLE_PATTERN                         equ     0B25H
GL_LINE_STIPPLE_REPEAT                          equ     0B26H
GL_LIST_MODE                                    equ     0B30H
GL_MAX_LIST_NESTING                             equ     0B31H
GL_LIST_BASE                                    equ     0B32H
GL_LIST_INDEX                                   equ     0B33H
GL_POLYGON_MODE                                 equ     0B40H
GL_POLYGON_SMOOTH                               equ     0B41H
GL_POLYGON_STIPPLE                              equ     0B42H
GL_EDGE_FLAG                                    equ     0B43H
GL_CULL_FACE                                    equ     0B44H
GL_CULL_FACE_MODE                               equ     0B45H
GL_FRONT_FACE                                   equ     0B46H
GL_LIGHTING                                     equ     0B50H
GL_LIGHT_MODEL_LOCAL_VIEWER                     equ     0B51H
GL_LIGHT_MODEL_TWO_SIDE                         equ     0B52H
GL_LIGHT_MODEL_AMBIENT                          equ     0B53H
GL_SHADE_MODEL                                  equ     0B54H
GL_COLOR_MATERIAL_FACE                          equ     0B55H
GL_COLOR_MATERIAL_PARAMETER                     equ     0B56H
GL_COLOR_MATERIAL                               equ     0B57H
GL_FOG                                          equ     0B60H
GL_FOG_INDEX                                    equ     0B61H
GL_FOG_DENSITY                                  equ     0B62H
GL_FOG_START                                    equ     0B63H
GL_FOG_END                                      equ     0B64H
GL_FOG_MODE                                     equ     0B65H
GL_FOG_COLOR                                    equ     0B66H
GL_DEPTH_RANGE                                  equ     0B70H
GL_DEPTH_TEST                                   equ     0B71H
GL_DEPTH_WRITEMASK                              equ     0B72H
GL_DEPTH_CLEAR_VALUE                            equ     0B73H
GL_DEPTH_FUNC                                   equ     0B74H
GL_ACCUM_CLEAR_VALUE                            equ     0B80H
GL_STENCIL_TEST                                 equ     0B90H
GL_STENCIL_CLEAR_VALUE                          equ     0B91H
GL_STENCIL_FUNC                                 equ     0B92H
GL_STENCIL_VALUE_MASK                           equ     0B93H
GL_STENCIL_FAIL                                 equ     0B94H
GL_STENCIL_PASS_DEPTH_FAIL                      equ     0B95H
GL_STENCIL_PASS_DEPTH_PASS                      equ     0B96H
GL_STENCIL_REF                                  equ     0B97H
GL_STENCIL_WRITEMASK                            equ     0B98H
GL_MATRIX_MODE                                  equ     0BA0H
GL_NORMALIZE                                    equ     0BA1H
GL_VIEWPORT                                     equ     0BA2H
GL_MODELVIEW_STACK_DEPTH                        equ     0BA3H
GL_PROJECTION_STACK_DEPTH                       equ     0BA4H
GL_TEXTURE_STACK_DEPTH                          equ     0BA5H
GL_MODELVIEW_MATRIX                             equ     0BA6H
GL_PROJECTION_MATRIX                            equ     0BA7H
GL_TEXTURE_MATRIX                               equ     0BA8H
GL_ATTRIB_STACK_DEPTH                           equ     0BB0H
GL_CLIENT_ATTRIB_STACK_DEPTH                    equ     0BB1H
GL_ALPHA_TEST                                   equ     0BC0H
GL_ALPHA_TEST_FUNC                              equ     0BC1H
GL_ALPHA_TEST_REF                               equ     0BC2H
GL_DITHER                                       equ     0BD0H
GL_BLEND_DST                                    equ     0BE0H
GL_BLEND_SRC                                    equ     0BE1H
GL_BLEND                                        equ     0BE2H
GL_LOGIC_OP_MODE                                equ     0BF0H
GL_INDEX_LOGIC_OP                               equ     0BF1H
GL_COLOR_LOGIC_OP                               equ     0BF2H
GL_AUX_BUFFERS                                  equ     0C00H
GL_DRAW_BUFFER                                  equ     0C01H
GL_READ_BUFFER                                  equ     0C02H
GL_SCISSOR_BOX                                  equ     0C10H
GL_SCISSOR_TEST                                 equ     0C11H
GL_INDEX_CLEAR_VALUE                            equ     0C20H
GL_INDEX_WRITEMASK                              equ     0C21H
GL_COLOR_CLEAR_VALUE                            equ     0C22H
GL_COLOR_WRITEMASK                              equ     0C23H
GL_INDEX_MODE                                   equ     0C30H
GL_RGBA_MODE                                    equ     0C31H
GL_DOUBLEBUFFER                                 equ     0C32H
GL_STEREO                                       equ     0C33H
GL_RENDER_MODE                                  equ     0C40H
GL_PERSPECTIVE_CORRECTION_HINT                  equ     0C50H
GL_POINT_SMOOTH_HINT                            equ     0C51H
GL_LINE_SMOOTH_HINT                             equ     0C52H
GL_POLYGON_SMOOTH_HINT                          equ     0C53H
GL_FOG_HINT                                     equ     0C54H
GL_TEXTURE_GEN_S                                equ     0C60H
GL_TEXTURE_GEN_T                                equ     0C61H
GL_TEXTURE_GEN_R                                equ     0C62H
GL_TEXTURE_GEN_Q                                equ     0C63H
GL_PIXEL_MAP_I_TO_I                             equ     0C70H
GL_PIXEL_MAP_S_TO_S                             equ     0C71H
GL_PIXEL_MAP_I_TO_R                             equ     0C72H
GL_PIXEL_MAP_I_TO_G                             equ     0C73H
GL_PIXEL_MAP_I_TO_B                             equ     0C74H
GL_PIXEL_MAP_I_TO_A                             equ     0C75H
GL_PIXEL_MAP_R_TO_R                             equ     0C76H
GL_PIXEL_MAP_G_TO_G                             equ     0C77H
GL_PIXEL_MAP_B_TO_B                             equ     0C78H
GL_PIXEL_MAP_A_TO_A                             equ     0C79H
GL_PIXEL_MAP_I_TO_I_SIZE                        equ     0CB0H
GL_PIXEL_MAP_S_TO_S_SIZE                        equ     0CB1H
GL_PIXEL_MAP_I_TO_R_SIZE                        equ     0CB2H
GL_PIXEL_MAP_I_TO_G_SIZE                        equ     0CB3H
GL_PIXEL_MAP_I_TO_B_SIZE                        equ     0CB4H
GL_PIXEL_MAP_I_TO_A_SIZE                        equ     0CB5H
GL_PIXEL_MAP_R_TO_R_SIZE                        equ     0CB6H
GL_PIXEL_MAP_G_TO_G_SIZE                        equ     0CB7H
GL_PIXEL_MAP_B_TO_B_SIZE                        equ     0CB8H
GL_PIXEL_MAP_A_TO_A_SIZE                        equ     0CB9H
GL_UNPACK_SWAP_BYTES                            equ     0CF0H
GL_UNPACK_LSB_FIRST                             equ     0CF1H
GL_UNPACK_ROW_LENGTH                            equ     0CF2H
GL_UNPACK_SKIP_ROWS                             equ     0CF3H
GL_UNPACK_SKIP_PIXELS                           equ     0CF4H
GL_UNPACK_ALIGNMENT                             equ     0CF5H
GL_PACK_SWAP_BYTES                              equ     0D00H
GL_PACK_LSB_FIRST                               equ     0D01H
GL_PACK_ROW_LENGTH                              equ     0D02H
GL_PACK_SKIP_ROWS                               equ     0D03H
GL_PACK_SKIP_PIXELS                             equ     0D04H
GL_PACK_ALIGNMENT                               equ     0D05H
GL_MAP_COLOR                                    equ     0D10H
GL_MAP_STENCIL                                  equ     0D11H
GL_INDEX_SHIFT                                  equ     0D12H
GL_INDEX_OFFSET                                 equ     0D13H
GL_RED_SCALE                                    equ     0D14H
GL_RED_BIAS                                     equ     0D15H
GL_ZOOM_X                                       equ     0D16H
GL_ZOOM_Y                                       equ     0D17H
GL_GREEN_SCALE                                  equ     0D18H
GL_GREEN_BIAS                                   equ     0D19H
GL_BLUE_SCALE                                   equ     0D1AH
GL_BLUE_BIAS                                    equ     0D1BH
GL_ALPHA_SCALE                                  equ     0D1CH
GL_ALPHA_BIAS                                   equ     0D1DH
GL_DEPTH_SCALE                                  equ     0D1EH
GL_DEPTH_BIAS                                   equ     0D1FH
GL_MAX_EVAL_ORDER                               equ     0D30H
GL_MAX_LIGHTS                                   equ     0D31H
GL_MAX_CLIP_PLANES                              equ     0D32H
GL_MAX_TEXTURE_SIZE                             equ     0D33H
GL_MAX_PIXEL_MAP_TABLE                          equ     0D34H
GL_MAX_ATTRIB_STACK_DEPTH                       equ     0D35H
GL_MAX_MODELVIEW_STACK_DEPTH                    equ     0D36H
GL_MAX_NAME_STACK_DEPTH                         equ     0D37H
GL_MAX_PROJECTION_STACK_DEPTH                   equ     0D38H
GL_MAX_TEXTURE_STACK_DEPTH                      equ     0D39H
GL_MAX_VIEWPORT_DIMS                            equ     0D3AH
GL_MAX_CLIENT_ATTRIB_STACK_DEPTH                equ     0D3BH
GL_SUBPIXEL_BITS                                equ     0D50H
GL_INDEX_BITS                                   equ     0D51H
GL_RED_BITS                                     equ     0D52H
GL_GREEN_BITS                                   equ     0D53H
GL_BLUE_BITS                                    equ     0D54H
GL_ALPHA_BITS                                   equ     0D55H
GL_DEPTH_BITS                                   equ     0D56H
GL_STENCIL_BITS                                 equ     0D57H
GL_ACCUM_RED_BITS                               equ     0D58H
GL_ACCUM_GREEN_BITS                             equ     0D59H
GL_ACCUM_BLUE_BITS                              equ     0D5AH
GL_ACCUM_ALPHA_BITS                             equ     0D5BH
GL_NAME_STACK_DEPTH                             equ     0D70H
GL_AUTO_NORMAL                                  equ     0D80H
GL_MAP1_COLOR_4                                 equ     0D90H
GL_MAP1_INDEX                                   equ     0D91H
GL_MAP1_NORMAL                                  equ     0D92H
GL_MAP1_TEXTURE_COORD_1                         equ     0D93H
GL_MAP1_TEXTURE_COORD_2                         equ     0D94H
GL_MAP1_TEXTURE_COORD_3                         equ     0D95H
GL_MAP1_TEXTURE_COORD_4                         equ     0D96H
GL_MAP1_VERTEX_3                                equ     0D97H
GL_MAP1_VERTEX_4                                equ     0D98H
GL_MAP2_COLOR_4                                 equ     0DB0H
GL_MAP2_INDEX                                   equ     0DB1H
GL_MAP2_NORMAL                                  equ     0DB2H
GL_MAP2_TEXTURE_COORD_1                         equ     0DB3H
GL_MAP2_TEXTURE_COORD_2                         equ     0DB4H
GL_MAP2_TEXTURE_COORD_3                         equ     0DB5H
GL_MAP2_TEXTURE_COORD_4                         equ     0DB6H
GL_MAP2_VERTEX_3                                equ     0DB7H
GL_MAP2_VERTEX_4                                equ     0DB8H
GL_MAP1_GRID_DOMAIN                             equ     0DD0H
GL_MAP1_GRID_SEGMENTS                           equ     0DD1H
GL_MAP2_GRID_DOMAIN                             equ     0DD2H
GL_MAP2_GRID_SEGMENTS                           equ     0DD3H
GL_TEXTURE_1D                                   equ     0DE0H
GL_TEXTURE_2D                                   equ     0DE1H
GL_FEEDBACK_BUFFER_POINTER                      equ     0DF0H
GL_FEEDBACK_BUFFER_SIZE                         equ     0DF1H
GL_FEEDBACK_BUFFER_TYPE                         equ     0DF2H
GL_SELECTION_BUFFER_POINTER                     equ     0DF3H
GL_SELECTION_BUFFER_SIZE                        equ     0DF4H

GL_TEXTURE_WIDTH                                equ     1000H
GL_TEXTURE_HEIGHT                               equ     1001H
GL_TEXTURE_INTERNAL_FORMAT                      equ     1003H
GL_TEXTURE_BORDER_COLOR                         equ     1004H
GL_TEXTURE_BORDER                               equ     1005H

GL_DONT_CARE                                    equ     1100H
GL_FASTEST                                      equ     1101H
GL_NICEST                                       equ     1102H

GL_LIGHT0                                       equ     4000H
GL_LIGHT1                                       equ     4001H
GL_LIGHT2                                       equ     4002H
GL_LIGHT3                                       equ     4003H
GL_LIGHT4                                       equ     4004H
GL_LIGHT5                                       equ     4005H
GL_LIGHT6                                       equ     4006H
GL_LIGHT7                                       equ     4007H

GL_AMBIENT                                      equ     1200H
GL_DIFFUSE                                      equ     1201H
GL_SPECULAR                                     equ     1202H
GL_POSITION                                     equ     1203H
GL_SPOT_DIRECTION                               equ     1204H
GL_SPOT_EXPONENT                                equ     1205H
GL_SPOT_CUTOFF                                  equ     1206H
GL_CONSTANT_ATTENUATION                         equ     1207H
GL_LINEAR_ATTENUATION                           equ     1208H
GL_QUADRATIC_ATTENUATION                        equ     1209H

GL_COMPILE                                      equ     1300H
GL_COMPILE_AND_EXECUTE                          equ     1301H

GL_CLEAR                                        equ     1500H
GL_AND                                          equ     1501H
GL_AND_REVERSE                                  equ     1502H
GL_COPY                                         equ     1503H
GL_AND_INVERTED                                 equ     1504H
GL_NOOP                                         equ     1505H
GL_XOR                                          equ     1506H
GL_OR                                           equ     1507H
GL_NOR                                          equ     1508H
GL_EQUIV                                        equ     1509H
GL_INVERT                                       equ     150AH
GL_OR_REVERSE                                   equ     150BH
GL_COPY_INVERTED                                equ     150CH
GL_OR_INVERTED                                  equ     150DH
GL_NAND                                         equ     150EH
GL_SET                                          equ     150FH

GL_EMISSION                                     equ     1600H
GL_SHININESS                                    equ     1601H
GL_AMBIENT_AND_DIFFUSE                          equ     1602H
GL_COLOR_INDEXES                                equ     1603H

GL_MODELVIEW                                    equ     1700H
GL_PROJECTION                                   equ     1701H
GL_TEXTURE                                      equ     1702H

GL_COLOR                                        equ     1800H
GL_DEPTH                                        equ     1801H
GL_STENCIL                                      equ     1802H

GL_COLOR_INDEX                                  equ     1900H
GL_STENCIL_INDEX                                equ     1901H
GL_DEPTH_COMPONENT                              equ     1902H
GL_RED                                          equ     1903H
GL_GREEN                                        equ     1904H
GL_BLUE                                         equ     1905H
GL_ALPHA                                        equ     1906H
GL_RGB                                          equ     1907H
GL_RGBA                                         equ     1908H
GL_LUMINANCE                                    equ     1909H
GL_LUMINANCE_ALPHA                              equ     190AH

GL_BITMAP                                       equ     1A00H

GL_POINT                                        equ     1B00H
GL_LINE                                         equ     1B01H
GL_FILL                                         equ     1B02H

GL_RENDER                                       equ     1C00H
GL_FEEDBACK                                     equ     1C01H
GL_SELECT                                       equ     1C02H

GL_FLAT                                         equ     1D00H
GL_SMOOTH                                       equ     1D01H

GL_KEEP                                         equ     1E00H
GL_REPLACE                                      equ     1E01H
GL_INCR                                         equ     1E02H
GL_DECR                                         equ     1E03H

GL_VENDOR                                       equ     1F00H
GL_RENDERER                                     equ     1F01H
GL_VERSION                                      equ     1F02H
GL_EXTENSIONS                                   equ     1F03H

GL_S                                            equ     2000H
GL_T                                            equ     2001H
GL_R                                            equ     2002H
GL_Q                                            equ     2003H

GL_MODULATE                                     equ     2100H
GL_DECAL                                        equ     2101H

GL_TEXTURE_ENV_MODE                             equ     2200H
GL_TEXTURE_ENV_COLOR                            equ     2201H

GL_TEXTURE_ENV                                  equ     2300H

GL_EYE_LINEAR                                   equ     2400H
GL_OBJECT_LINEAR                                equ     2401H
GL_SPHERE_MAP                                   equ     2402H

GL_TEXTURE_GEN_MODE                             equ     2500H
GL_OBJECT_PLANE                                 equ     2501H
GL_EYE_PLANE                                    equ     2502H

GL_NEAREST                                      equ     2600H
GL_LINEAR                                       equ     2601H

GL_NEAREST_MIPMAP_NEAREST                       equ     2700H
GL_LINEAR_MIPMAP_NEAREST                        equ     2701H
GL_NEAREST_MIPMAP_LINEAR                        equ     2702H
GL_LINEAR_MIPMAP_LINEAR                         equ     2703H

GL_TEXTURE_MAG_FILTER                           equ     2800H
GL_TEXTURE_MIN_FILTER                           equ     2801H
GL_TEXTURE_WRAP_S                               equ     2802H
GL_TEXTURE_WRAP_T                               equ     2803H

GL_CLAMP                                        equ     2900H
GL_REPEAT                                       equ     2901H

GL_CLIENT_PIXEL_STORE_BIT                       equ     00000001H
GL_CLIENT_VERTEX_ARRAY_BIT                      equ     00000002H
GL_CLIENT_ALL_ATTRIB_BITS                       equ     0FFFFFFFFH

GL_POLYGON_OFFSET_FACTOR                        equ     8038H
GL_POLYGON_OFFSET_UNITS                         equ     2A00H
GL_POLYGON_OFFSET_POINT                         equ     2A01H
GL_POLYGON_OFFSET_LINE                          equ     2A02H
GL_POLYGON_OFFSET_FILL                          equ     8037H

GL_ALPHA4                                       equ     803BH
GL_ALPHA8                                       equ     803CH
GL_ALPHA12                                      equ     803DH
GL_ALPHA16                                      equ     803EH
GL_LUMINANCE4                                   equ     803FH
GL_LUMINANCE8                                   equ     8040H
GL_LUMINANCE12                                  equ     8041H
GL_LUMINANCE16                                  equ     8042H
GL_LUMINANCE4_ALPHA4                            equ     8043H
GL_LUMINANCE6_ALPHA2                            equ     8044H
GL_LUMINANCE8_ALPHA8                            equ     8045H
GL_LUMINANCE12_ALPHA4                           equ     8046H
GL_LUMINANCE12_ALPHA12                          equ     8047H
GL_LUMINANCE16_ALPHA16                          equ     8048H
GL_INTENSITY                                    equ     8049H
GL_INTENSITY4                                   equ     804AH
GL_INTENSITY8                                   equ     804BH
GL_INTENSITY12                                  equ     804CH
GL_INTENSITY16                                  equ     804DH
GL_R3_G3_B2                                     equ     2A10H
GL_RGB4                                         equ     804FH
GL_RGB5                                         equ     8050H
GL_RGB8                                         equ     8051H
GL_RGB10                                        equ     8052H
GL_RGB12                                        equ     8053H
GL_RGB16                                        equ     8054H
GL_RGBA2                                        equ     8055H
GL_RGBA4                                        equ     8056H
GL_RGB5_A1                                      equ     8057H
GL_RGBA8                                        equ     8058H
GL_RGB10_A2                                     equ     8059H
GL_RGBA12                                       equ     805AH
GL_RGBA16                                       equ     805BH
GL_TEXTURE_RED_SIZE                             equ     805CH
GL_TEXTURE_GREEN_SIZE                           equ     805DH
GL_TEXTURE_BLUE_SIZE                            equ     805EH
GL_TEXTURE_ALPHA_SIZE                           equ     805FH
GL_TEXTURE_LUMINANCE_SIZE                       equ     8060H
GL_TEXTURE_INTENSITY_SIZE                       equ     8061H
GL_PROXY_TEXTURE_1D                             equ     8063H
GL_PROXY_TEXTURE_2D                             equ     8064H

GL_TEXTURE_PRIORITY                             equ     8066H
GL_TEXTURE_RESIDENT                             equ     8067H
GL_TEXTURE_BINDING_1D                           equ     8068H
GL_TEXTURE_BINDING_2D                           equ     8069H

GL_VERTEX_ARRAY                                 equ     8074H
GL_NORMAL_ARRAY                                 equ     8075H
GL_COLOR_ARRAY                                  equ     8076H
GL_INDEX_ARRAY                                  equ     8077H
GL_TEXTURE_COORD_ARRAY                          equ     8078H
GL_EDGE_FLAG_ARRAY                              equ     8079H
GL_VERTEX_ARRAY_SIZE                            equ     807AH
GL_VERTEX_ARRAY_TYPE                            equ     807BH
GL_VERTEX_ARRAY_STRIDE                          equ     807CH
GL_NORMAL_ARRAY_TYPE                            equ     807EH
GL_NORMAL_ARRAY_STRIDE                          equ     807FH
GL_COLOR_ARRAY_SIZE                             equ     8081H
GL_COLOR_ARRAY_TYPE                             equ     8082H
GL_COLOR_ARRAY_STRIDE                           equ     8083H
GL_INDEX_ARRAY_TYPE                             equ     8085H
GL_INDEX_ARRAY_STRIDE                           equ     8086H
GL_TEXTURE_COORD_ARRAY_SIZE                     equ     8088H
GL_TEXTURE_COORD_ARRAY_TYPE                     equ     8089H
GL_TEXTURE_COORD_ARRAY_STRIDE                   equ     808AH
GL_EDGE_FLAG_ARRAY_STRIDE                       equ     808CH
GL_VERTEX_ARRAY_POINTER                         equ     808EH
GL_NORMAL_ARRAY_POINTER                         equ     808FH
GL_COLOR_ARRAY_POINTER                          equ     8090H
GL_INDEX_ARRAY_POINTER                          equ     8091H
GL_TEXTURE_COORD_ARRAY_POINTER                  equ     8092H
GL_EDGE_FLAG_ARRAY_POINTER                      equ     8093H
GL_V2F                                          equ     2A20H
GL_V3F                                          equ     2A21H
GL_C4UB_V2F                                     equ     2A22H
GL_C4UB_V3F                                     equ     2A23H
GL_C3F_V3F                                      equ     2A24H
GL_N3F_V3F                                      equ     2A25H
GL_C4F_N3F_V3F                                  equ     2A26H
GL_T2F_V3F                                      equ     2A27H
GL_T4F_V4F                                      equ     2A28H
GL_T2F_C4UB_V3F                                 equ     2A29H
GL_T2F_C3F_V3F                                  equ     2A2AH
GL_T2F_N3F_V3F                                  equ     2A2BH
GL_T2F_C4F_N3F_V3F                              equ     2A2CH
GL_T4F_C4F_N3F_V4F                              equ     2A2DH

GL_EXT_vertex_array                             equ     1
GL_EXT_bgra                                     equ     1
GL_EXT_paletted_texture                         equ     1
GL_WIN_swap_hint                                equ     1
GL_WIN_draw_range_elements                      equ     1

GL_VERTEX_ARRAY_EXT                             equ     8074H
GL_NORMAL_ARRAY_EXT                             equ     8075H
GL_COLOR_ARRAY_EXT                              equ     8076H
GL_INDEX_ARRAY_EXT                              equ     8077H
GL_TEXTURE_COORD_ARRAY_EXT                      equ     8078H
GL_EDGE_FLAG_ARRAY_EXT                          equ     8079H
GL_VERTEX_ARRAY_SIZE_EXT                        equ     807AH
GL_VERTEX_ARRAY_TYPE_EXT                        equ     807BH
GL_VERTEX_ARRAY_STRIDE_EXT                      equ     807CH
GL_VERTEX_ARRAY_COUNT_EXT                       equ     807DH
GL_NORMAL_ARRAY_TYPE_EXT                        equ     807EH
GL_NORMAL_ARRAY_STRIDE_EXT                      equ     807FH
GL_NORMAL_ARRAY_COUNT_EXT                       equ     8080H
GL_COLOR_ARRAY_SIZE_EXT                         equ     8081H
GL_COLOR_ARRAY_TYPE_EXT                         equ     8082H
GL_COLOR_ARRAY_STRIDE_EXT                       equ     8083H
GL_COLOR_ARRAY_COUNT_EXT                        equ     8084H
GL_INDEX_ARRAY_TYPE_EXT                         equ     8085H
GL_INDEX_ARRAY_STRIDE_EXT                       equ     8086H
GL_INDEX_ARRAY_COUNT_EXT                        equ     8087H
GL_TEXTURE_COORD_ARRAY_SIZE_EXT                 equ     8088H
GL_TEXTURE_COORD_ARRAY_TYPE_EXT                 equ     8089H
GL_TEXTURE_COORD_ARRAY_STRIDE_EXT               equ     808AH
GL_TEXTURE_COORD_ARRAY_COUNT_EXT                equ     808BH
GL_EDGE_FLAG_ARRAY_STRIDE_EXT                   equ     808CH
GL_EDGE_FLAG_ARRAY_COUNT_EXT                    equ     808DH
GL_VERTEX_ARRAY_POINTER_EXT                     equ     808EH
GL_NORMAL_ARRAY_POINTER_EXT                     equ     808FH
GL_COLOR_ARRAY_POINTER_EXT                      equ     8090H
GL_INDEX_ARRAY_POINTER_EXT                      equ     8091H
GL_TEXTURE_COORD_ARRAY_POINTER_EXT              equ     8092H
GL_EDGE_FLAG_ARRAY_POINTER_EXT                  equ     8093H
GL_DOUBLE_EXT                                   equ     GL_DOUBLE

GL_BGR_EXT                                      equ     80E0H
GL_BGRA_EXT                                     equ     80E1H

GL_COLOR_TABLE_FORMAT_EXT                       equ     80D8H
GL_COLOR_TABLE_WIDTH_EXT                        equ     80D9H
GL_COLOR_TABLE_RED_SIZE_EXT                     equ     80DAH
GL_COLOR_TABLE_GREEN_SIZE_EXT                   equ     80DBH
GL_COLOR_TABLE_BLUE_SIZE_EXT                    equ     80DCH
GL_COLOR_TABLE_ALPHA_SIZE_EXT                   equ     80DDH
GL_COLOR_TABLE_LUMINANCE_SIZE_EXT               equ     80DEH
GL_COLOR_TABLE_INTENSITY_SIZE_EXT               equ     80DFH

GL_COLOR_INDEX1_EXT                             equ     80E2H
GL_COLOR_INDEX2_EXT                             equ     80E3H
GL_COLOR_INDEX4_EXT                             equ     80E4H
GL_COLOR_INDEX8_EXT                             equ     80E5H
GL_COLOR_INDEX12_EXT                            equ     80E6H
GL_COLOR_INDEX16_EXT                            equ     80E7H

GL_MAX_ELEMENTS_VERTICES_WIN                    equ     80E8H
GL_MAX_ELEMENTS_INDICES_WIN                     equ     80E9H

GL_PHONG_WIN                                    equ     80EAH
GL_PHONG_HINT_WIN                               equ     80EBH

GL_FOG_SPECULAR_TEXTURE_WIN                     equ     80ECH

GL_LOGIC_OP                                     equ     GL_INDEX_LOGIC_OP
GL_TEXTURE_COMPONENTS                           equ     GL_TEXTURE_INTERNAL_FORMAT

;======================= OpenGL Utility Library definitions =======================
GLU_VERSION_1_1                                 equ     1
GLU_VERSION_1_2                                 equ     1

GLU_INVALID_ENUM                                equ     100900
GLU_INVALID_VALUE                               equ     100901
GLU_OUT_OF_MEMORY                               equ     100902
GLU_INCOMPATIBLE_GL_VERSION                     equ     100903

GLU_VERSION                                     equ     100800
GLU_EXTENSIONS                                  equ     100801

GLU_TRUE                                        equ     GL_TRUE
GLU_FALSE                                       equ     GL_FALSE

GLU_SMOOTH                                      equ     100000
GLU_FLAT                                        equ     100001
GLU_NONE                                        equ     100002

GLU_POINT                                       equ     100010
GLU_LINE                                        equ     100011
GLU_FILL                                        equ     100012
GLU_SILHOUETTE                                  equ     100013

GLU_OUTSIDE                                     equ     100020
GLU_INSIDE                                      equ     100021

GLU_TESS_MAX_COORD                              equ     1.0E150

GLU_TESS_WINDING_RULE                           equ     100140
GLU_TESS_BOUNDARY_ONLY                          equ     100141
GLU_TESS_TOLERANCE                              equ     100142

GLU_TESS_WINDING_ODD                            equ     100130
GLU_TESS_WINDING_NONZERO                        equ     100131
GLU_TESS_WINDING_POSITIVE                       equ     100132
GLU_TESS_WINDING_NEGATIVE                       equ     100133
GLU_TESS_WINDING_ABS_GEQ_TWO                    equ     100134

GLU_TESS_BEGIN                                  equ     100100
GLU_TESS_VERTEX                                 equ     100101
GLU_TESS_END                                    equ     100102
GLU_TESS_ERROR                                  equ     100103
GLU_TESS_EDGE_FLAG                              equ     100104
GLU_TESS_COMBINE                                equ     100105
GLU_TESS_BEGIN_DATA                             equ     100106
GLU_TESS_VERTEX_DATA                            equ     100107
GLU_TESS_END_DATA                               equ     100108
GLU_TESS_ERROR_DATA                             equ     100109
GLU_TESS_EDGE_FLAG_DATA                         equ     100110
GLU_TESS_COMBINE_DATA                           equ     100111

GLU_TESS_ERROR1                                 equ     100151
GLU_TESS_ERROR2                                 equ     100152
GLU_TESS_ERROR3                                 equ     100153
GLU_TESS_ERROR4                                 equ     100154
GLU_TESS_ERROR5                                 equ     100155
GLU_TESS_ERROR6                                 equ     100156
GLU_TESS_ERROR7                                 equ     100157
GLU_TESS_ERROR8                                 equ     100158

GLU_TESS_MISSING_BEGIN_POLYGON                  equ     GLU_TESS_ERROR1
GLU_TESS_MISSING_BEGIN_CONTOUR                  equ     GLU_TESS_ERROR2
GLU_TESS_MISSING_END_POLYGON                    equ     GLU_TESS_ERROR3
GLU_TESS_MISSING_END_CONTOUR                    equ     GLU_TESS_ERROR4
GLU_TESS_COORD_TOO_LARGE                        equ     GLU_TESS_ERROR5
GLU_TESS_NEED_COMBINE_CALLBACK                  equ     GLU_TESS_ERROR6

GLU_AUTO_LOAD_MATRIX                            equ     100200
GLU_CULLING                                     equ     100201
GLU_SAMPLING_TOLERANCE                          equ     100203
GLU_DISPLAY_MODE                                equ     100204
GLU_PARAMETRIC_TOLERANCE                        equ     100202
GLU_SAMPLING_METHOD                             equ     100205
GLU_U_STEP                                      equ     100206
GLU_V_STEP                                      equ     100207

GLU_PATH_LENGTH                                 equ     100215
GLU_PARAMETRIC_ERROR                            equ     100216
GLU_DOMAIN_DISTANCE                             equ     100217

GLU_MAP1_TRIM_2                                 equ     100210
GLU_MAP1_TRIM_3                                 equ     100211

GLU_OUTLINE_POLYGON                             equ     100240
GLU_OUTLINE_PATCH                               equ     100241

GLU_NURBS_ERROR1                                equ     100251
GLU_NURBS_ERROR2                                equ     100252
GLU_NURBS_ERROR3                                equ     100253
GLU_NURBS_ERROR4                                equ     100254
GLU_NURBS_ERROR5                                equ     100255
GLU_NURBS_ERROR6                                equ     100256
GLU_NURBS_ERROR7                                equ     100257
GLU_NURBS_ERROR8                                equ     100258
GLU_NURBS_ERROR9                                equ     100259
GLU_NURBS_ERROR10                               equ     100260
GLU_NURBS_ERROR11                               equ     100261
GLU_NURBS_ERROR12                               equ     100262
GLU_NURBS_ERROR13                               equ     100263
GLU_NURBS_ERROR14                               equ     100264
GLU_NURBS_ERROR15                               equ     100265
GLU_NURBS_ERROR16                               equ     100266
GLU_NURBS_ERROR17                               equ     100267
GLU_NURBS_ERROR18                               equ     100268
GLU_NURBS_ERROR19                               equ     100269
GLU_NURBS_ERROR20                               equ     100270
GLU_NURBS_ERROR21                               equ     100271
GLU_NURBS_ERROR22                               equ     100272
GLU_NURBS_ERROR23                               equ     100273
GLU_NURBS_ERROR24                               equ     100274
GLU_NURBS_ERROR25                               equ     100275
GLU_NURBS_ERROR26                               equ     100276
GLU_NURBS_ERROR27                               equ     100277
GLU_NURBS_ERROR28                               equ     100278
GLU_NURBS_ERROR29                               equ     100279
GLU_NURBS_ERROR30                               equ     100280
GLU_NURBS_ERROR31                               equ     100281
GLU_NURBS_ERROR32                               equ     100282
GLU_NURBS_ERROR33                               equ     100283
GLU_NURBS_ERROR34                               equ     100284
GLU_NURBS_ERROR35                               equ     100285
GLU_NURBS_ERROR36                               equ     100286
GLU_NURBS_ERROR37                               equ     100287

GLU_CW                                          equ     100120  ;obsolete
GLU_CCW                                         equ     100121  ;obsolete
GLU_INTERIOR                                    equ     100122  ;obsolete
GLU_EXTERIOR                                    equ     100123  ;obsolete
GLU_UNKNOWN                                     equ     100124  ;obsolete

GLU_BEGIN                                       equ     GLU_TESS_BEGIN
GLU_VERTEX                                      equ     GLU_TESS_VERTEX
GLU_END                                         equ     GLU_TESS_END
GLU_ERROR                                       equ     GLU_TESS_ERROR
GLU_EDGE_FLAG                                   equ     GLU_TESS_EDGE_FLAG

;====================== OpenGL Auxiliary Library definitions ======================
AUX_RGB                                         equ     0
AUX_RGBA                                        equ     AUX_RGB
AUX_INDEX                                       equ     1
AUX_SINGLE                                      equ     0
AUX_DOUBLE                                      equ     2
AUX_DIRECT                                      equ     0
AUX_INDIRECT                                    equ     4

AUX_ACCUM                                       equ     8
AUX_ALPHA                                       equ     16
AUX_DEPTH24                                     equ     32
AUX_STENCIL                                     equ     64
AUX_AUX                                         equ     128
AUX_DEPTH16                                     equ     256
AUX_FIXED_332_PAL                               equ     512
AUX_DEPTH                                       equ     AUX_DEPTH16

AUX_EXPOSE                                      equ     1
AUX_CONFIG                                      equ     2
AUX_DRAW                                        equ     4
AUX_KEYEVENT                                    equ     8
AUX_MOUSEDOWN                                   equ     16
AUX_MOUSEUP                                     equ     32
AUX_MOUSELOC                                    equ     64

AUX_WINDOWX                                     equ     0
AUX_WINDOWY                                     equ     1
AUX_MOUSEX                                      equ     0
AUX_MOUSEY                                      equ     1
AUX_MOUSESTATUS                                 equ     3
AUX_KEY                                         equ     0
AUX_KEYSTATUS                                   equ     1

AUX_LEFTBUTTON                                  equ     1
AUX_RIGHTBUTTON                                 equ     2
AUX_MIDDLEBUTTON                                equ     4
AUX_SHIFT                                       equ     1
AUX_CONTROL                                     equ     2

AUX_RETURN                                      equ     0DH
AUX_ESCAPE                                      equ     1BH
AUX_SPACE                                       equ     20H
AUX_LEFT                                        equ     25H
AUX_UP                                          equ     26H
AUX_RIGHT                                       equ     27H
AUX_DOWN                                        equ     28H
AUX_A                                           equ     'A'
AUX_B                                           equ     'B'
AUX_C                                           equ     'C'
AUX_D                                           equ     'D'
AUX_E                                           equ     'E'
AUX_F                                           equ     'F'
AUX_G                                           equ     'G'
AUX_H                                           equ     'H'
AUX_I                                           equ     'I'
AUX_J                                           equ     'J'
AUX_K                                           equ     'K'
AUX_L                                           equ     'L'
AUX_M                                           equ     'M'
AUX_N                                           equ     'N'
AUX_O                                           equ     'O'
AUX_P                                           equ     'P'
AUX_Q                                           equ     'Q'
AUX_R                                           equ     'R'
AUX_S                                           equ     'S'
AUX_T                                           equ     'T'
AUX_U                                           equ     'U'
AUX_V                                           equ     'V'
AUX_W                                           equ     'W'
AUX_X                                           equ     'X'
AUX_Y                                           equ     'Y'
AUX_Z                                           equ     'Z'
AUX_a                                           equ     'a'
AUX_b                                           equ     'b'
AUX_c                                           equ     'c'
AUX_d                                           equ     'd'
AUX_e                                           equ     'e'
AUX_f                                           equ     'f'
AUX_g                                           equ     'g'
AUX_h                                           equ     'h'
AUX_i                                           equ     'i'
AUX_j                                           equ     'j'
AUX_k                                           equ     'k'
AUX_l                                           equ     'l'
AUX_m                                           equ     'm'
AUX_n                                           equ     'n'
AUX_o                                           equ     'o'
AUX_p                                           equ     'p'
AUX_q                                           equ     'q'
AUX_r                                           equ     'r'
AUX_s                                           equ     's'
AUX_t                                           equ     't'
AUX_u                                           equ     'u'
AUX_v                                           equ     'v'
AUX_w                                           equ     'w'
AUX_x                                           equ     'x'
AUX_y                                           equ     'y'
AUX_z                                           equ     'z'
AUX_0                                           equ     '0'
AUX_1                                           equ     '1'
AUX_2                                           equ     '2'
AUX_3                                           equ     '3'
AUX_4                                           equ     '4'
AUX_5                                           equ     '5'
AUX_6                                           equ     '6'
AUX_7                                           equ     '7'
AUX_8                                           equ     '8'
AUX_9                                           equ     '9'

AUX_FD                                          equ     1
AUX_COLORMAP                                    equ     3
AUX_GREYSCALEMAP                                equ     4
AUX_FOGMAP                                      equ     5
AUX_ONECOLOR                                    equ     6

AUX_BLACK                                       equ     0
AUX_RED                                         equ     13
AUX_GREEN                                       equ     14
AUX_YELLOW                                      equ     15
AUX_BLUE                                        equ     16
AUX_MAGENTA                                     equ     17
AUX_CYAN                                        equ     18
AUX_WHITE                                       equ     19

AUX_USE_ID                                      equ     1
AUX_EXACT_MATCH                                 equ     2
AUX_MINIMUM_CRITERIA                            equ     3

;======================================== Structures ======================================;
struct AUX_EVENTREC
    event   dd ?
    data    dd 4 dup(?)
ends

struct AUX_RGBImageRec
    sizeX   dd ?
    sizeY   dd ?
    data    dd ?
ends

;======================================== Functions =======================================;
if defined APP_WIN64
    extrn '__imp_GlmfBeginGlsBlock' as GlmfBeginGlsBlock:qword
    extrn '__imp_GlmfCloseMetaFile' as GlmfCloseMetaFile:qword
    extrn '__imp_GlmfEndGlsBlock' as GlmfEndGlsBlock:qword
    extrn '__imp_GlmfEndPlayback' as GlmfEndPlayback:qword
    extrn '__imp_GlmfInitPlayback' as GlmfInitPlayback:qword
    extrn '__imp_GlmfPlayGlsRecord' as GlmfPlayGlsRecord:qword
    extrn '__imp_glAccum' as glAccum:qword
    extrn '__imp_glAlphaFunc' as glAlphaFunc:qword
    extrn '__imp_glAreTexturesResident' as glAreTexturesResident:qword
    extrn '__imp_glArrayElement' as glArrayElement:qword
    extrn '__imp_glBegin' as glBegin:qword
    extrn '__imp_glBindTexture' as glBindTexture:qword
    extrn '__imp_glBitmap' as glBitmap:qword
    extrn '__imp_glBlendFunc' as glBlendFunc:qword
    extrn '__imp_glCallList' as glCallList:qword
    extrn '__imp_glCallLists' as glCallLists:qword
    extrn '__imp_glClear' as glClear:qword
    extrn '__imp_glClearAccum' as glClearAccum:qword
    extrn '__imp_glClearColor' as glClearColor:qword
    extrn '__imp_glClearDepth' as glClearDepth:qword
    extrn '__imp_glClearIndex' as glClearIndex:qword
    extrn '__imp_glClearStencil' as glClearStencil:qword
    extrn '__imp_glClipPlane' as glClipPlane:qword
    extrn '__imp_glColor3b' as glColor3b:qword
    extrn '__imp_glColor3bv' as glColor3bv:qword
    extrn '__imp_glColor3d' as glColor3d:qword
    extrn '__imp_glColor3dv' as glColor3dv:qword
    extrn '__imp_glColor3f' as glColor3f:qword
    extrn '__imp_glColor3fv' as glColor3fv:qword
    extrn '__imp_glColor3i' as glColor3i:qword
    extrn '__imp_glColor3iv' as glColor3iv:qword
    extrn '__imp_glColor3s' as glColor3s:qword
    extrn '__imp_glColor3sv' as glColor3sv:qword
    extrn '__imp_glColor3ub' as glColor3ub:qword
    extrn '__imp_glColor3ubv' as glColor3ubv:qword
    extrn '__imp_glColor3ui' as glColor3ui:qword
    extrn '__imp_glColor3uiv' as glColor3uiv:qword
    extrn '__imp_glColor3us' as glColor3us:qword
    extrn '__imp_glColor3usv' as glColor3usv:qword
    extrn '__imp_glColor4b' as glColor4b:qword
    extrn '__imp_glColor4bv' as glColor4bv:qword
    extrn '__imp_glColor4d' as glColor4d:qword
    extrn '__imp_glColor4dv' as glColor4dv:qword
    extrn '__imp_glColor4f' as glColor4f:qword
    extrn '__imp_glColor4fv' as glColor4fv:qword
    extrn '__imp_glColor4i' as glColor4i:qword
    extrn '__imp_glColor4iv' as glColor4iv:qword
    extrn '__imp_glColor4s' as glColor4s:qword
    extrn '__imp_glColor4sv' as glColor4sv:qword
    extrn '__imp_glColor4ub' as glColor4ub:qword
    extrn '__imp_glColor4ubv' as glColor4ubv:qword
    extrn '__imp_glColor4ui' as glColor4ui:qword
    extrn '__imp_glColor4uiv' as glColor4uiv:qword
    extrn '__imp_glColor4us' as glColor4us:qword
    extrn '__imp_glColor4usv' as glColor4usv:qword
    extrn '__imp_glColorMask' as glColorMask:qword
    extrn '__imp_glColorMaterial' as glColorMaterial:qword
    extrn '__imp_glColorPointer' as glColorPointer:qword
    extrn '__imp_glCopyPixels' as glCopyPixels:qword
    extrn '__imp_glCopyTexImage1D' as glCopyTexImage1D:qword
    extrn '__imp_glCopyTexImage2D' as glCopyTexImage2D:qword
    extrn '__imp_glCopyTexSubImage1D' as glCopyTexSubImage1D:qword
    extrn '__imp_glCopyTexSubImage2D' as glCopyTexSubImage2D:qword
    extrn '__imp_glCullFace' as glCullFace:qword
    extrn '__imp_glDebugEntry' as glDebugEntry:qword
    extrn '__imp_glDeleteLists' as glDeleteLists:qword
    extrn '__imp_glDeleteTextures' as glDeleteTextures:qword
    extrn '__imp_glDepthFunc' as glDepthFunc:qword
    extrn '__imp_glDepthMask' as glDepthMask:qword
    extrn '__imp_glDepthRange' as glDepthRange:qword
    extrn '__imp_glDisable' as glDisable:qword
    extrn '__imp_glDisableClientState' as glDisableClientState:qword
    extrn '__imp_glDrawArrays' as glDrawArrays:qword
    extrn '__imp_glDrawBuffer' as glDrawBuffer:qword
    extrn '__imp_glDrawElements' as glDrawElements:qword
    extrn '__imp_glDrawPixels' as glDrawPixels:qword
    extrn '__imp_glEdgeFlag' as glEdgeFlag:qword
    extrn '__imp_glEdgeFlagPointer' as glEdgeFlagPointer:qword
    extrn '__imp_glEdgeFlagv' as glEdgeFlagv:qword
    extrn '__imp_glEnable' as glEnable:qword
    extrn '__imp_glEnableClientState' as glEnableClientState:qword
    extrn '__imp_glEnd' as glEnd:qword
    extrn '__imp_glEndList' as glEndList:qword
    extrn '__imp_glEvalCoord1d' as glEvalCoord1d:qword
    extrn '__imp_glEvalCoord1dv' as glEvalCoord1dv:qword
    extrn '__imp_glEvalCoord1f' as glEvalCoord1f:qword
    extrn '__imp_glEvalCoord1fv' as glEvalCoord1fv:qword
    extrn '__imp_glEvalCoord2d' as glEvalCoord2d:qword
    extrn '__imp_glEvalCoord2dv' as glEvalCoord2dv:qword
    extrn '__imp_glEvalCoord2f' as glEvalCoord2f:qword
    extrn '__imp_glEvalCoord2fv' as glEvalCoord2fv:qword
    extrn '__imp_glEvalMesh1' as glEvalMesh1:qword
    extrn '__imp_glEvalMesh2' as glEvalMesh2:qword
    extrn '__imp_glEvalPoint1' as glEvalPoint1:qword
    extrn '__imp_glEvalPoint2' as glEvalPoint2:qword
    extrn '__imp_glFeedbackBuffer' as glFeedbackBuffer:qword
    extrn '__imp_glFinish' as glFinish:qword
    extrn '__imp_glFlush' as glFlush:qword
    extrn '__imp_glFogf' as glFogf:qword
    extrn '__imp_glFogfv' as glFogfv:qword
    extrn '__imp_glFogi' as glFogi:qword
    extrn '__imp_glFogiv' as glFogiv:qword
    extrn '__imp_glFrontFace' as glFrontFace:qword
    extrn '__imp_glFrustum' as glFrustum:qword
    extrn '__imp_glGenLists' as glGenLists:qword
    extrn '__imp_glGenTextures' as glGenTextures:qword
    extrn '__imp_glGetBooleanv' as glGetBooleanv:qword
    extrn '__imp_glGetClipPlane' as glGetClipPlane:qword
    extrn '__imp_glGetDoublev' as glGetDoublev:qword
    extrn '__imp_glGetError' as glGetError:qword
    extrn '__imp_glGetFloatv' as glGetFloatv:qword
    extrn '__imp_glGetIntegerv' as glGetIntegerv:qword
    extrn '__imp_glGetLightfv' as glGetLightfv:qword
    extrn '__imp_glGetLightiv' as glGetLightiv:qword
    extrn '__imp_glGetMapdv' as glGetMapdv:qword
    extrn '__imp_glGetMapfv' as glGetMapfv:qword
    extrn '__imp_glGetMapiv' as glGetMapiv:qword
    extrn '__imp_glGetMaterialfv' as glGetMaterialfv:qword
    extrn '__imp_glGetMaterialiv' as glGetMaterialiv:qword
    extrn '__imp_glGetPixelMapfv' as glGetPixelMapfv:qword
    extrn '__imp_glGetPixelMapuiv' as glGetPixelMapuiv:qword
    extrn '__imp_glGetPixelMapusv' as glGetPixelMapusv:qword
    extrn '__imp_glGetPointerv' as glGetPointerv:qword
    extrn '__imp_glGetPolygonStipple' as glGetPolygonStipple:qword
    extrn '__imp_glGetString' as glGetString:qword
    extrn '__imp_glGetTexEnvfv' as glGetTexEnvfv:qword
    extrn '__imp_glGetTexEnviv' as glGetTexEnviv:qword
    extrn '__imp_glGetTexGendv' as glGetTexGendv:qword
    extrn '__imp_glGetTexGenfv' as glGetTexGenfv:qword
    extrn '__imp_glGetTexGeniv' as glGetTexGeniv:qword
    extrn '__imp_glGetTexImage' as glGetTexImage:qword
    extrn '__imp_glGetTexLevelParameterfv' as glGetTexLevelParameterfv:qword
    extrn '__imp_glGetTexLevelParameteriv' as glGetTexLevelParameteriv:qword
    extrn '__imp_glGetTexParameterfv' as glGetTexParameterfv:qword
    extrn '__imp_glGetTexParameteriv' as glGetTexParameteriv:qword
    extrn '__imp_glHint' as glHint:qword
    extrn '__imp_glIndexMask' as glIndexMask:qword
    extrn '__imp_glIndexPointer' as glIndexPointer:qword
    extrn '__imp_glIndexd' as glIndexd:qword
    extrn '__imp_glIndexdv' as glIndexdv:qword
    extrn '__imp_glIndexf' as glIndexf:qword
    extrn '__imp_glIndexfv' as glIndexfv:qword
    extrn '__imp_glIndexi' as glIndexi:qword
    extrn '__imp_glIndexiv' as glIndexiv:qword
    extrn '__imp_glIndexs' as glIndexs:qword
    extrn '__imp_glIndexsv' as glIndexsv:qword
    extrn '__imp_glIndexub' as glIndexub:qword
    extrn '__imp_glIndexubv' as glIndexubv:qword
    extrn '__imp_glInitNames' as glInitNames:qword
    extrn '__imp_glInterleavedArrays' as glInterleavedArrays:qword
    extrn '__imp_glIsEnabled' as glIsEnabled:qword
    extrn '__imp_glIsList' as glIsList:qword
    extrn '__imp_glIsTexture' as glIsTexture:qword
    extrn '__imp_glLightModelf' as glLightModelf:qword
    extrn '__imp_glLightModelfv' as glLightModelfv:qword
    extrn '__imp_glLightModeli' as glLightModeli:qword
    extrn '__imp_glLightModeliv' as glLightModeliv:qword
    extrn '__imp_glLightf' as glLightf:qword
    extrn '__imp_glLightfv' as glLightfv:qword
    extrn '__imp_glLighti' as glLighti:qword
    extrn '__imp_glLightiv' as glLightiv:qword
    extrn '__imp_glLineStipple' as glLineStipple:qword
    extrn '__imp_glLineWidth' as glLineWidth:qword
    extrn '__imp_glListBase' as glListBase:qword
    extrn '__imp_glLoadIdentity' as glLoadIdentity:qword
    extrn '__imp_glLoadMatrixd' as glLoadMatrixd:qword
    extrn '__imp_glLoadMatrixf' as glLoadMatrixf:qword
    extrn '__imp_glLoadName' as glLoadName:qword
    extrn '__imp_glLogicOp' as glLogicOp:qword
    extrn '__imp_glMap1d' as glMap1d:qword
    extrn '__imp_glMap1f' as glMap1f:qword
    extrn '__imp_glMap2d' as glMap2d:qword
    extrn '__imp_glMap2f' as glMap2f:qword
    extrn '__imp_glMapGrid1d' as glMapGrid1d:qword
    extrn '__imp_glMapGrid1f' as glMapGrid1f:qword
    extrn '__imp_glMapGrid2d' as glMapGrid2d:qword
    extrn '__imp_glMapGrid2f' as glMapGrid2f:qword
    extrn '__imp_glMaterialf' as glMaterialf:qword
    extrn '__imp_glMaterialfv' as glMaterialfv:qword
    extrn '__imp_glMateriali' as glMateriali:qword
    extrn '__imp_glMaterialiv' as glMaterialiv:qword
    extrn '__imp_glMatrixMode' as glMatrixMode:qword
    extrn '__imp_glMultMatrixd' as glMultMatrixd:qword
    extrn '__imp_glMultMatrixf' as glMultMatrixf:qword
    extrn '__imp_glNewList' as glNewList:qword
    extrn '__imp_glNormal3b' as glNormal3b:qword
    extrn '__imp_glNormal3bv' as glNormal3bv:qword
    extrn '__imp_glNormal3d' as glNormal3d:qword
    extrn '__imp_glNormal3dv' as glNormal3dv:qword
    extrn '__imp_glNormal3f' as glNormal3f:qword
    extrn '__imp_glNormal3fv' as glNormal3fv:qword
    extrn '__imp_glNormal3i' as glNormal3i:qword
    extrn '__imp_glNormal3iv' as glNormal3iv:qword
    extrn '__imp_glNormal3s' as glNormal3s:qword
    extrn '__imp_glNormal3sv' as glNormal3sv:qword
    extrn '__imp_glNormalPointer' as glNormalPointer:qword
    extrn '__imp_glOrtho' as glOrtho:qword
    extrn '__imp_glPassThrough' as glPassThrough:qword
    extrn '__imp_glPixelMapfv' as glPixelMapfv:qword
    extrn '__imp_glPixelMapuiv' as glPixelMapuiv:qword
    extrn '__imp_glPixelMapusv' as glPixelMapusv:qword
    extrn '__imp_glPixelStoref' as glPixelStoref:qword
    extrn '__imp_glPixelStorei' as glPixelStorei:qword
    extrn '__imp_glPixelTransferf' as glPixelTransferf:qword
    extrn '__imp_glPixelTransferi' as glPixelTransferi:qword
    extrn '__imp_glPixelZoom' as glPixelZoom:qword
    extrn '__imp_glPointSize' as glPointSize:qword
    extrn '__imp_glPolygonMode' as glPolygonMode:qword
    extrn '__imp_glPolygonOffset' as glPolygonOffset:qword
    extrn '__imp_glPolygonStipple' as glPolygonStipple:qword
    extrn '__imp_glPopAttrib' as glPopAttrib:qword
    extrn '__imp_glPopClientAttrib' as glPopClientAttrib:qword
    extrn '__imp_glPopMatrix' as glPopMatrix:qword
    extrn '__imp_glPopName' as glPopName:qword
    extrn '__imp_glPrioritizeTextures' as glPrioritizeTextures:qword
    extrn '__imp_glPushAttrib' as glPushAttrib:qword
    extrn '__imp_glPushClientAttrib' as glPushClientAttrib:qword
    extrn '__imp_glPushMatrix' as glPushMatrix:qword
    extrn '__imp_glPushName' as glPushName:qword
    extrn '__imp_glRasterPos2d' as glRasterPos2d:qword
    extrn '__imp_glRasterPos2dv' as glRasterPos2dv:qword
    extrn '__imp_glRasterPos2f' as glRasterPos2f:qword
    extrn '__imp_glRasterPos2fv' as glRasterPos2fv:qword
    extrn '__imp_glRasterPos2i' as glRasterPos2i:qword
    extrn '__imp_glRasterPos2iv' as glRasterPos2iv:qword
    extrn '__imp_glRasterPos2s' as glRasterPos2s:qword
    extrn '__imp_glRasterPos2sv' as glRasterPos2sv:qword
    extrn '__imp_glRasterPos3d' as glRasterPos3d:qword
    extrn '__imp_glRasterPos3dv' as glRasterPos3dv:qword
    extrn '__imp_glRasterPos3f' as glRasterPos3f:qword
    extrn '__imp_glRasterPos3fv' as glRasterPos3fv:qword
    extrn '__imp_glRasterPos3i' as glRasterPos3i:qword
    extrn '__imp_glRasterPos3iv' as glRasterPos3iv:qword
    extrn '__imp_glRasterPos3s' as glRasterPos3s:qword
    extrn '__imp_glRasterPos3sv' as glRasterPos3sv:qword
    extrn '__imp_glRasterPos4d' as glRasterPos4d:qword
    extrn '__imp_glRasterPos4dv' as glRasterPos4dv:qword
    extrn '__imp_glRasterPos4f' as glRasterPos4f:qword
    extrn '__imp_glRasterPos4fv' as glRasterPos4fv:qword
    extrn '__imp_glRasterPos4i' as glRasterPos4i:qword
    extrn '__imp_glRasterPos4iv' as glRasterPos4iv:qword
    extrn '__imp_glRasterPos4s' as glRasterPos4s:qword
    extrn '__imp_glRasterPos4sv' as glRasterPos4sv:qword
    extrn '__imp_glReadBuffer' as glReadBuffer:qword
    extrn '__imp_glReadPixels' as glReadPixels:qword
    extrn '__imp_glRectd' as glRectd:qword
    extrn '__imp_glRectdv' as glRectdv:qword
    extrn '__imp_glRectf' as glRectf:qword
    extrn '__imp_glRectfv' as glRectfv:qword
    extrn '__imp_glRecti' as glRecti:qword
    extrn '__imp_glRectiv' as glRectiv:qword
    extrn '__imp_glRects' as glRects:qword
    extrn '__imp_glRectsv' as glRectsv:qword
    extrn '__imp_glRenderMode' as glRenderMode:qword
    extrn '__imp_glRotated' as glRotated:qword
    extrn '__imp_glRotatef' as glRotatef:qword
    extrn '__imp_glScaled' as glScaled:qword
    extrn '__imp_glScalef' as glScalef:qword
    extrn '__imp_glScissor' as glScissor:qword
    extrn '__imp_glSelectBuffer' as glSelectBuffer:qword
    extrn '__imp_glShadeModel' as glShadeModel:qword
    extrn '__imp_glStencilFunc' as glStencilFunc:qword
    extrn '__imp_glStencilMask' as glStencilMask:qword
    extrn '__imp_glStencilOp' as glStencilOp:qword
    extrn '__imp_glTexCoord1d' as glTexCoord1d:qword
    extrn '__imp_glTexCoord1dv' as glTexCoord1dv:qword
    extrn '__imp_glTexCoord1f' as glTexCoord1f:qword
    extrn '__imp_glTexCoord1fv' as glTexCoord1fv:qword
    extrn '__imp_glTexCoord1i' as glTexCoord1i:qword
    extrn '__imp_glTexCoord1iv' as glTexCoord1iv:qword
    extrn '__imp_glTexCoord1s' as glTexCoord1s:qword
    extrn '__imp_glTexCoord1sv' as glTexCoord1sv:qword
    extrn '__imp_glTexCoord2d' as glTexCoord2d:qword
    extrn '__imp_glTexCoord2dv' as glTexCoord2dv:qword
    extrn '__imp_glTexCoord2f' as glTexCoord2f:qword
    extrn '__imp_glTexCoord2fv' as glTexCoord2fv:qword
    extrn '__imp_glTexCoord2i' as glTexCoord2i:qword
    extrn '__imp_glTexCoord2iv' as glTexCoord2iv:qword
    extrn '__imp_glTexCoord2s' as glTexCoord2s:qword
    extrn '__imp_glTexCoord2sv' as glTexCoord2sv:qword
    extrn '__imp_glTexCoord3d' as glTexCoord3d:qword
    extrn '__imp_glTexCoord3dv' as glTexCoord3dv:qword
    extrn '__imp_glTexCoord3f' as glTexCoord3f:qword
    extrn '__imp_glTexCoord3fv' as glTexCoord3fv:qword
    extrn '__imp_glTexCoord3i' as glTexCoord3i:qword
    extrn '__imp_glTexCoord3iv' as glTexCoord3iv:qword
    extrn '__imp_glTexCoord3s' as glTexCoord3s:qword
    extrn '__imp_glTexCoord3sv' as glTexCoord3sv:qword
    extrn '__imp_glTexCoord4d' as glTexCoord4d:qword
    extrn '__imp_glTexCoord4dv' as glTexCoord4dv:qword
    extrn '__imp_glTexCoord4f' as glTexCoord4f:qword
    extrn '__imp_glTexCoord4fv' as glTexCoord4fv:qword
    extrn '__imp_glTexCoord4i' as glTexCoord4i:qword
    extrn '__imp_glTexCoord4iv' as glTexCoord4iv:qword
    extrn '__imp_glTexCoord4s' as glTexCoord4s:qword
    extrn '__imp_glTexCoord4sv' as glTexCoord4sv:qword
    extrn '__imp_glTexCoordPointer' as glTexCoordPointer:qword
    extrn '__imp_glTexEnvf' as glTexEnvf:qword
    extrn '__imp_glTexEnvfv' as glTexEnvfv:qword
    extrn '__imp_glTexEnvi' as glTexEnvi:qword
    extrn '__imp_glTexEnviv' as glTexEnviv:qword
    extrn '__imp_glTexGend' as glTexGend:qword
    extrn '__imp_glTexGendv' as glTexGendv:qword
    extrn '__imp_glTexGenf' as glTexGenf:qword
    extrn '__imp_glTexGenfv' as glTexGenfv:qword
    extrn '__imp_glTexGeni' as glTexGeni:qword
    extrn '__imp_glTexGeniv' as glTexGeniv:qword
    extrn '__imp_glTexImage1D' as glTexImage1D:qword
    extrn '__imp_glTexImage2D' as glTexImage2D:qword
    extrn '__imp_glTexParameterf' as glTexParameterf:qword
    extrn '__imp_glTexParameterfv' as glTexParameterfv:qword
    extrn '__imp_glTexParameteri' as glTexParameteri:qword
    extrn '__imp_glTexParameteriv' as glTexParameteriv:qword
    extrn '__imp_glTexSubImage1D' as glTexSubImage1D:qword
    extrn '__imp_glTexSubImage2D' as glTexSubImage2D:qword
    extrn '__imp_glTranslated' as glTranslated:qword
    extrn '__imp_glTranslatef' as glTranslatef:qword
    extrn '__imp_glVertex2d' as glVertex2d:qword
    extrn '__imp_glVertex2dv' as glVertex2dv:qword
    extrn '__imp_glVertex2f' as glVertex2f:qword
    extrn '__imp_glVertex2fv' as glVertex2fv:qword
    extrn '__imp_glVertex2i' as glVertex2i:qword
    extrn '__imp_glVertex2iv' as glVertex2iv:qword
    extrn '__imp_glVertex2s' as glVertex2s:qword
    extrn '__imp_glVertex2sv' as glVertex2sv:qword
    extrn '__imp_glVertex3d' as glVertex3d:qword
    extrn '__imp_glVertex3dv' as glVertex3dv:qword
    extrn '__imp_glVertex3f' as glVertex3f:qword
    extrn '__imp_glVertex3fv' as glVertex3fv:qword
    extrn '__imp_glVertex3i' as glVertex3i:qword
    extrn '__imp_glVertex3iv' as glVertex3iv:qword
    extrn '__imp_glVertex3s' as glVertex3s:qword
    extrn '__imp_glVertex3sv' as glVertex3sv:qword
    extrn '__imp_glVertex4d' as glVertex4d:qword
    extrn '__imp_glVertex4dv' as glVertex4dv:qword
    extrn '__imp_glVertex4f' as glVertex4f:qword
    extrn '__imp_glVertex4fv' as glVertex4fv:qword
    extrn '__imp_glVertex4i' as glVertex4i:qword
    extrn '__imp_glVertex4iv' as glVertex4iv:qword
    extrn '__imp_glVertex4s' as glVertex4s:qword
    extrn '__imp_glVertex4sv' as glVertex4sv:qword
    extrn '__imp_glVertexPointer' as glVertexPointer:qword
    extrn '__imp_glViewport' as glViewport:qword
    extrn '__imp_wglChoosePixelFormat' as wglChoosePixelFormat:qword
    extrn '__imp_wglCopyContext' as wglCopyContext:qword
    extrn '__imp_wglCreateContext' as wglCreateContext:qword
    extrn '__imp_wglCreateLayerContext' as wglCreateLayerContext:qword
    extrn '__imp_wglDeleteContext' as wglDeleteContext:qword
    extrn '__imp_wglDescribeLayerPlane' as wglDescribeLayerPlane:qword
    extrn '__imp_wglDescribePixelFormat' as wglDescribePixelFormat:qword
    extrn '__imp_wglGetCurrentContext' as wglGetCurrentContext:qword
    extrn '__imp_wglGetCurrentDC' as wglGetCurrentDC:qword
    extrn '__imp_wglGetDefaultProcAddress' as wglGetDefaultProcAddress:qword
    extrn '__imp_wglGetLayerPaletteEntries' as wglGetLayerPaletteEntries:qword
    extrn '__imp_wglGetPixelFormat' as wglGetPixelFormat:qword
    extrn '__imp_wglGetProcAddress' as wglGetProcAddress:qword
    extrn '__imp_wglMakeCurrent' as wglMakeCurrent:qword
    extrn '__imp_wglRealizeLayerPalette' as wglRealizeLayerPalette:qword
    extrn '__imp_wglSetLayerPaletteEntries' as wglSetLayerPaletteEntries:qword
    extrn '__imp_wglSetPixelFormat' as wglSetPixelFormat:qword
    extrn '__imp_wglShareLists' as wglShareLists:qword
    extrn '__imp_wglSwapBuffers' as wglSwapBuffers:qword
    extrn '__imp_wglSwapLayerBuffers' as wglSwapLayerBuffers:qword
    extrn '__imp_wglSwapMultipleBuffers' as wglSwapMultipleBuffers:qword
    extrn '__imp_wglUseFontBitmapsA' as wglUseFontBitmapsA:qword
    extrn '__imp_wglUseFontBitmapsW' as wglUseFontBitmapsW:qword
    extrn '__imp_wglUseFontOutlinesA' as wglUseFontOutlinesA:qword
    extrn '__imp_wglUseFontOutlinesW' as wglUseFontOutlinesW:qword
else
    extrn '__imp__GlmfBeginGlsBlock@4' as GlmfBeginGlsBlock:dword
    extrn '__imp__GlmfCloseMetaFile@4' as GlmfCloseMetaFile:dword
    extrn '__imp__GlmfEndGlsBlock@4' as GlmfEndGlsBlock:dword
    extrn '__imp__GlmfEndPlayback@4' as GlmfEndPlayback:dword
    extrn '__imp__GlmfInitPlayback@12' as GlmfInitPlayback:dword
    extrn '__imp__GlmfPlayGlsRecord@16' as GlmfPlayGlsRecord:dword
    extrn '__imp__glAccum@8' as glAccum:dword
    extrn '__imp__glAlphaFunc@8' as glAlphaFunc:dword
    extrn '__imp__glAreTexturesResident@12' as glAreTexturesResident:dword
    extrn '__imp__glArrayElement@4' as glArrayElement:dword
    extrn '__imp__glBegin@4' as glBegin:dword
    extrn '__imp__glBindTexture@8' as glBindTexture:dword
    extrn '__imp__glBitmap@28' as glBitmap:dword
    extrn '__imp__glBlendFunc@8' as glBlendFunc:dword
    extrn '__imp__glCallList@4' as glCallList:dword
    extrn '__imp__glCallLists@12' as glCallLists:dword
    extrn '__imp__glClear@4' as glClear:dword
    extrn '__imp__glClearAccum@16' as glClearAccum:dword
    extrn '__imp__glClearColor@16' as glClearColor:dword
    extrn '__imp__glClearDepth@8' as glClearDepth:dword
    extrn '__imp__glClearIndex@4' as glClearIndex:dword
    extrn '__imp__glClearStencil@4' as glClearStencil:dword
    extrn '__imp__glClipPlane@8' as glClipPlane:dword
    extrn '__imp__glColor3b@12' as glColor3b:dword
    extrn '__imp__glColor3bv@4' as glColor3bv:dword
    extrn '__imp__glColor3d@24' as glColor3d:dword
    extrn '__imp__glColor3dv@4' as glColor3dv:dword
    extrn '__imp__glColor3f@12' as glColor3f:dword
    extrn '__imp__glColor3fv@4' as glColor3fv:dword
    extrn '__imp__glColor3i@12' as glColor3i:dword
    extrn '__imp__glColor3iv@4' as glColor3iv:dword
    extrn '__imp__glColor3s@12' as glColor3s:dword
    extrn '__imp__glColor3sv@4' as glColor3sv:dword
    extrn '__imp__glColor3ub@12' as glColor3ub:dword
    extrn '__imp__glColor3ubv@4' as glColor3ubv:dword
    extrn '__imp__glColor3ui@12' as glColor3ui:dword
    extrn '__imp__glColor3uiv@4' as glColor3uiv:dword
    extrn '__imp__glColor3us@12' as glColor3us:dword
    extrn '__imp__glColor3usv@4' as glColor3usv:dword
    extrn '__imp__glColor4b@16' as glColor4b:dword
    extrn '__imp__glColor4bv@4' as glColor4bv:dword
    extrn '__imp__glColor4d@32' as glColor4d:dword
    extrn '__imp__glColor4dv@4' as glColor4dv:dword
    extrn '__imp__glColor4f@16' as glColor4f:dword
    extrn '__imp__glColor4fv@4' as glColor4fv:dword
    extrn '__imp__glColor4i@16' as glColor4i:dword
    extrn '__imp__glColor4iv@4' as glColor4iv:dword
    extrn '__imp__glColor4s@16' as glColor4s:dword
    extrn '__imp__glColor4sv@4' as glColor4sv:dword
    extrn '__imp__glColor4ub@16' as glColor4ub:dword
    extrn '__imp__glColor4ubv@4' as glColor4ubv:dword
    extrn '__imp__glColor4ui@16' as glColor4ui:dword
    extrn '__imp__glColor4uiv@4' as glColor4uiv:dword
    extrn '__imp__glColor4us@16' as glColor4us:dword
    extrn '__imp__glColor4usv@4' as glColor4usv:dword
    extrn '__imp__glColorMask@16' as glColorMask:dword
    extrn '__imp__glColorMaterial@8' as glColorMaterial:dword
    extrn '__imp__glColorPointer@16' as glColorPointer:dword
    extrn '__imp__glCopyPixels@20' as glCopyPixels:dword
    extrn '__imp__glCopyTexImage1D@28' as glCopyTexImage1D:dword
    extrn '__imp__glCopyTexImage2D@32' as glCopyTexImage2D:dword
    extrn '__imp__glCopyTexSubImage1D@24' as glCopyTexSubImage1D:dword
    extrn '__imp__glCopyTexSubImage2D@32' as glCopyTexSubImage2D:dword
    extrn '__imp__glCullFace@4' as glCullFace:dword
    extrn '__imp__glDebugEntry@8' as glDebugEntry:dword
    extrn '__imp__glDeleteLists@8' as glDeleteLists:dword
    extrn '__imp__glDeleteTextures@8' as glDeleteTextures:dword
    extrn '__imp__glDepthFunc@4' as glDepthFunc:dword
    extrn '__imp__glDepthMask@4' as glDepthMask:dword
    extrn '__imp__glDepthRange@16' as glDepthRange:dword
    extrn '__imp__glDisable@4' as glDisable:dword
    extrn '__imp__glDisableClientState@4' as glDisableClientState:dword
    extrn '__imp__glDrawArrays@12' as glDrawArrays:dword
    extrn '__imp__glDrawBuffer@4' as glDrawBuffer:dword
    extrn '__imp__glDrawElements@16' as glDrawElements:dword
    extrn '__imp__glDrawPixels@20' as glDrawPixels:dword
    extrn '__imp__glEdgeFlag@4' as glEdgeFlag:dword
    extrn '__imp__glEdgeFlagPointer@8' as glEdgeFlagPointer:dword
    extrn '__imp__glEdgeFlagv@4' as glEdgeFlagv:dword
    extrn '__imp__glEnable@4' as glEnable:dword
    extrn '__imp__glEnableClientState@4' as glEnableClientState:dword
    extrn '__imp__glEnd@0' as glEnd:dword
    extrn '__imp__glEndList@0' as glEndList:dword
    extrn '__imp__glEvalCoord1d@8' as glEvalCoord1d:dword
    extrn '__imp__glEvalCoord1dv@4' as glEvalCoord1dv:dword
    extrn '__imp__glEvalCoord1f@4' as glEvalCoord1f:dword
    extrn '__imp__glEvalCoord1fv@4' as glEvalCoord1fv:dword
    extrn '__imp__glEvalCoord2d@16' as glEvalCoord2d:dword
    extrn '__imp__glEvalCoord2dv@4' as glEvalCoord2dv:dword
    extrn '__imp__glEvalCoord2f@8' as glEvalCoord2f:dword
    extrn '__imp__glEvalCoord2fv@4' as glEvalCoord2fv:dword
    extrn '__imp__glEvalMesh1@12' as glEvalMesh1:dword
    extrn '__imp__glEvalMesh2@20' as glEvalMesh2:dword
    extrn '__imp__glEvalPoint1@4' as glEvalPoint1:dword
    extrn '__imp__glEvalPoint2@8' as glEvalPoint2:dword
    extrn '__imp__glFeedbackBuffer@12' as glFeedbackBuffer:dword
    extrn '__imp__glFinish@0' as glFinish:dword
    extrn '__imp__glFlush@0' as glFlush:dword
    extrn '__imp__glFogf@8' as glFogf:dword
    extrn '__imp__glFogfv@8' as glFogfv:dword
    extrn '__imp__glFogi@8' as glFogi:dword
    extrn '__imp__glFogiv@8' as glFogiv:dword
    extrn '__imp__glFrontFace@4' as glFrontFace:dword
    extrn '__imp__glFrustum@48' as glFrustum:dword
    extrn '__imp__glGenLists@4' as glGenLists:dword
    extrn '__imp__glGenTextures@8' as glGenTextures:dword
    extrn '__imp__glGetBooleanv@8' as glGetBooleanv:dword
    extrn '__imp__glGetClipPlane@8' as glGetClipPlane:dword
    extrn '__imp__glGetDoublev@8' as glGetDoublev:dword
    extrn '__imp__glGetError@0' as glGetError:dword
    extrn '__imp__glGetFloatv@8' as glGetFloatv:dword
    extrn '__imp__glGetIntegerv@8' as glGetIntegerv:dword
    extrn '__imp__glGetLightfv@12' as glGetLightfv:dword
    extrn '__imp__glGetLightiv@12' as glGetLightiv:dword
    extrn '__imp__glGetMapdv@12' as glGetMapdv:dword
    extrn '__imp__glGetMapfv@12' as glGetMapfv:dword
    extrn '__imp__glGetMapiv@12' as glGetMapiv:dword
    extrn '__imp__glGetMaterialfv@12' as glGetMaterialfv:dword
    extrn '__imp__glGetMaterialiv@12' as glGetMaterialiv:dword
    extrn '__imp__glGetPixelMapfv@8' as glGetPixelMapfv:dword
    extrn '__imp__glGetPixelMapuiv@8' as glGetPixelMapuiv:dword
    extrn '__imp__glGetPixelMapusv@8' as glGetPixelMapusv:dword
    extrn '__imp__glGetPointerv@8' as glGetPointerv:dword
    extrn '__imp__glGetPolygonStipple@4' as glGetPolygonStipple:dword
    extrn '__imp__glGetString@4' as glGetString:dword
    extrn '__imp__glGetTexEnvfv@12' as glGetTexEnvfv:dword
    extrn '__imp__glGetTexEnviv@12' as glGetTexEnviv:dword
    extrn '__imp__glGetTexGendv@12' as glGetTexGendv:dword
    extrn '__imp__glGetTexGenfv@12' as glGetTexGenfv:dword
    extrn '__imp__glGetTexGeniv@12' as glGetTexGeniv:dword
    extrn '__imp__glGetTexImage@20' as glGetTexImage:dword
    extrn '__imp__glGetTexLevelParameterfv@16' as glGetTexLevelParameterfv:dword
    extrn '__imp__glGetTexLevelParameteriv@16' as glGetTexLevelParameteriv:dword
    extrn '__imp__glGetTexParameterfv@12' as glGetTexParameterfv:dword
    extrn '__imp__glGetTexParameteriv@12' as glGetTexParameteriv:dword
    extrn '__imp__glHint@8' as glHint:dword
    extrn '__imp__glIndexMask@4' as glIndexMask:dword
    extrn '__imp__glIndexPointer@12' as glIndexPointer:dword
    extrn '__imp__glIndexd@8' as glIndexd:dword
    extrn '__imp__glIndexdv@4' as glIndexdv:dword
    extrn '__imp__glIndexf@4' as glIndexf:dword
    extrn '__imp__glIndexfv@4' as glIndexfv:dword
    extrn '__imp__glIndexi@4' as glIndexi:dword
    extrn '__imp__glIndexiv@4' as glIndexiv:dword
    extrn '__imp__glIndexs@4' as glIndexs:dword
    extrn '__imp__glIndexsv@4' as glIndexsv:dword
    extrn '__imp__glIndexub@4' as glIndexub:dword
    extrn '__imp__glIndexubv@4' as glIndexubv:dword
    extrn '__imp__glInitNames@0' as glInitNames:dword
    extrn '__imp__glInterleavedArrays@12' as glInterleavedArrays:dword
    extrn '__imp__glIsEnabled@4' as glIsEnabled:dword
    extrn '__imp__glIsList@4' as glIsList:dword
    extrn '__imp__glIsTexture@4' as glIsTexture:dword
    extrn '__imp__glLightModelf@8' as glLightModelf:dword
    extrn '__imp__glLightModelfv@8' as glLightModelfv:dword
    extrn '__imp__glLightModeli@8' as glLightModeli:dword
    extrn '__imp__glLightModeliv@8' as glLightModeliv:dword
    extrn '__imp__glLightf@12' as glLightf:dword
    extrn '__imp__glLightfv@12' as glLightfv:dword
    extrn '__imp__glLighti@12' as glLighti:dword
    extrn '__imp__glLightiv@12' as glLightiv:dword
    extrn '__imp__glLineStipple@8' as glLineStipple:dword
    extrn '__imp__glLineWidth@4' as glLineWidth:dword
    extrn '__imp__glListBase@4' as glListBase:dword
    extrn '__imp__glLoadIdentity@0' as glLoadIdentity:dword
    extrn '__imp__glLoadMatrixd@4' as glLoadMatrixd:dword
    extrn '__imp__glLoadMatrixf@4' as glLoadMatrixf:dword
    extrn '__imp__glLoadName@4' as glLoadName:dword
    extrn '__imp__glLogicOp@4' as glLogicOp:dword
    extrn '__imp__glMap1d@32' as glMap1d:dword
    extrn '__imp__glMap1f@24' as glMap1f:dword
    extrn '__imp__glMap2d@56' as glMap2d:dword
    extrn '__imp__glMap2f@40' as glMap2f:dword
    extrn '__imp__glMapGrid1d@20' as glMapGrid1d:dword
    extrn '__imp__glMapGrid1f@12' as glMapGrid1f:dword
    extrn '__imp__glMapGrid2d@40' as glMapGrid2d:dword
    extrn '__imp__glMapGrid2f@24' as glMapGrid2f:dword
    extrn '__imp__glMaterialf@12' as glMaterialf:dword
    extrn '__imp__glMaterialfv@12' as glMaterialfv:dword
    extrn '__imp__glMateriali@12' as glMateriali:dword
    extrn '__imp__glMaterialiv@12' as glMaterialiv:dword
    extrn '__imp__glMatrixMode@4' as glMatrixMode:dword
    extrn '__imp__glMultMatrixd@4' as glMultMatrixd:dword
    extrn '__imp__glMultMatrixf@4' as glMultMatrixf:dword
    extrn '__imp__glNewList@8' as glNewList:dword
    extrn '__imp__glNormal3b@12' as glNormal3b:dword
    extrn '__imp__glNormal3bv@4' as glNormal3bv:dword
    extrn '__imp__glNormal3d@24' as glNormal3d:dword
    extrn '__imp__glNormal3dv@4' as glNormal3dv:dword
    extrn '__imp__glNormal3f@12' as glNormal3f:dword
    extrn '__imp__glNormal3fv@4' as glNormal3fv:dword
    extrn '__imp__glNormal3i@12' as glNormal3i:dword
    extrn '__imp__glNormal3iv@4' as glNormal3iv:dword
    extrn '__imp__glNormal3s@12' as glNormal3s:dword
    extrn '__imp__glNormal3sv@4' as glNormal3sv:dword
    extrn '__imp__glNormalPointer@12' as glNormalPointer:dword
    extrn '__imp__glOrtho@48' as glOrtho:dword
    extrn '__imp__glPassThrough@4' as glPassThrough:dword
    extrn '__imp__glPixelMapfv@12' as glPixelMapfv:dword
    extrn '__imp__glPixelMapuiv@12' as glPixelMapuiv:dword
    extrn '__imp__glPixelMapusv@12' as glPixelMapusv:dword
    extrn '__imp__glPixelStoref@8' as glPixelStoref:dword
    extrn '__imp__glPixelStorei@8' as glPixelStorei:dword
    extrn '__imp__glPixelTransferf@8' as glPixelTransferf:dword
    extrn '__imp__glPixelTransferi@8' as glPixelTransferi:dword
    extrn '__imp__glPixelZoom@8' as glPixelZoom:dword
    extrn '__imp__glPointSize@4' as glPointSize:dword
    extrn '__imp__glPolygonMode@8' as glPolygonMode:dword
    extrn '__imp__glPolygonOffset@8' as glPolygonOffset:dword
    extrn '__imp__glPolygonStipple@4' as glPolygonStipple:dword
    extrn '__imp__glPopAttrib@0' as glPopAttrib:dword
    extrn '__imp__glPopClientAttrib@0' as glPopClientAttrib:dword
    extrn '__imp__glPopMatrix@0' as glPopMatrix:dword
    extrn '__imp__glPopName@0' as glPopName:dword
    extrn '__imp__glPrioritizeTextures@12' as glPrioritizeTextures:dword
    extrn '__imp__glPushAttrib@4' as glPushAttrib:dword
    extrn '__imp__glPushClientAttrib@4' as glPushClientAttrib:dword
    extrn '__imp__glPushMatrix@0' as glPushMatrix:dword
    extrn '__imp__glPushName@4' as glPushName:dword
    extrn '__imp__glRasterPos2d@16' as glRasterPos2d:dword
    extrn '__imp__glRasterPos2dv@4' as glRasterPos2dv:dword
    extrn '__imp__glRasterPos2f@8' as glRasterPos2f:dword
    extrn '__imp__glRasterPos2fv@4' as glRasterPos2fv:dword
    extrn '__imp__glRasterPos2i@8' as glRasterPos2i:dword
    extrn '__imp__glRasterPos2iv@4' as glRasterPos2iv:dword
    extrn '__imp__glRasterPos2s@8' as glRasterPos2s:dword
    extrn '__imp__glRasterPos2sv@4' as glRasterPos2sv:dword
    extrn '__imp__glRasterPos3d@24' as glRasterPos3d:dword
    extrn '__imp__glRasterPos3dv@4' as glRasterPos3dv:dword
    extrn '__imp__glRasterPos3f@12' as glRasterPos3f:dword
    extrn '__imp__glRasterPos3fv@4' as glRasterPos3fv:dword
    extrn '__imp__glRasterPos3i@12' as glRasterPos3i:dword
    extrn '__imp__glRasterPos3iv@4' as glRasterPos3iv:dword
    extrn '__imp__glRasterPos3s@12' as glRasterPos3s:dword
    extrn '__imp__glRasterPos3sv@4' as glRasterPos3sv:dword
    extrn '__imp__glRasterPos4d@32' as glRasterPos4d:dword
    extrn '__imp__glRasterPos4dv@4' as glRasterPos4dv:dword
    extrn '__imp__glRasterPos4f@16' as glRasterPos4f:dword
    extrn '__imp__glRasterPos4fv@4' as glRasterPos4fv:dword
    extrn '__imp__glRasterPos4i@16' as glRasterPos4i:dword
    extrn '__imp__glRasterPos4iv@4' as glRasterPos4iv:dword
    extrn '__imp__glRasterPos4s@16' as glRasterPos4s:dword
    extrn '__imp__glRasterPos4sv@4' as glRasterPos4sv:dword
    extrn '__imp__glReadBuffer@4' as glReadBuffer:dword
    extrn '__imp__glReadPixels@28' as glReadPixels:dword
    extrn '__imp__glRectd@32' as glRectd:dword
    extrn '__imp__glRectdv@8' as glRectdv:dword
    extrn '__imp__glRectf@16' as glRectf:dword
    extrn '__imp__glRectfv@8' as glRectfv:dword
    extrn '__imp__glRecti@16' as glRecti:dword
    extrn '__imp__glRectiv@8' as glRectiv:dword
    extrn '__imp__glRects@16' as glRects:dword
    extrn '__imp__glRectsv@8' as glRectsv:dword
    extrn '__imp__glRenderMode@4' as glRenderMode:dword
    extrn '__imp__glRotated@32' as glRotated:dword
    extrn '__imp__glRotatef@16' as glRotatef:dword
    extrn '__imp__glScaled@24' as glScaled:dword
    extrn '__imp__glScalef@12' as glScalef:dword
    extrn '__imp__glScissor@16' as glScissor:dword
    extrn '__imp__glSelectBuffer@8' as glSelectBuffer:dword
    extrn '__imp__glShadeModel@4' as glShadeModel:dword
    extrn '__imp__glStencilFunc@12' as glStencilFunc:dword
    extrn '__imp__glStencilMask@4' as glStencilMask:dword
    extrn '__imp__glStencilOp@12' as glStencilOp:dword
    extrn '__imp__glTexCoord1d@8' as glTexCoord1d:dword
    extrn '__imp__glTexCoord1dv@4' as glTexCoord1dv:dword
    extrn '__imp__glTexCoord1f@4' as glTexCoord1f:dword
    extrn '__imp__glTexCoord1fv@4' as glTexCoord1fv:dword
    extrn '__imp__glTexCoord1i@4' as glTexCoord1i:dword
    extrn '__imp__glTexCoord1iv@4' as glTexCoord1iv:dword
    extrn '__imp__glTexCoord1s@4' as glTexCoord1s:dword
    extrn '__imp__glTexCoord1sv@4' as glTexCoord1sv:dword
    extrn '__imp__glTexCoord2d@16' as glTexCoord2d:dword
    extrn '__imp__glTexCoord2dv@4' as glTexCoord2dv:dword
    extrn '__imp__glTexCoord2f@8' as glTexCoord2f:dword
    extrn '__imp__glTexCoord2fv@4' as glTexCoord2fv:dword
    extrn '__imp__glTexCoord2i@8' as glTexCoord2i:dword
    extrn '__imp__glTexCoord2iv@4' as glTexCoord2iv:dword
    extrn '__imp__glTexCoord2s@8' as glTexCoord2s:dword
    extrn '__imp__glTexCoord2sv@4' as glTexCoord2sv:dword
    extrn '__imp__glTexCoord3d@24' as glTexCoord3d:dword
    extrn '__imp__glTexCoord3dv@4' as glTexCoord3dv:dword
    extrn '__imp__glTexCoord3f@12' as glTexCoord3f:dword
    extrn '__imp__glTexCoord3fv@4' as glTexCoord3fv:dword
    extrn '__imp__glTexCoord3i@12' as glTexCoord3i:dword
    extrn '__imp__glTexCoord3iv@4' as glTexCoord3iv:dword
    extrn '__imp__glTexCoord3s@12' as glTexCoord3s:dword
    extrn '__imp__glTexCoord3sv@4' as glTexCoord3sv:dword
    extrn '__imp__glTexCoord4d@32' as glTexCoord4d:dword
    extrn '__imp__glTexCoord4dv@4' as glTexCoord4dv:dword
    extrn '__imp__glTexCoord4f@16' as glTexCoord4f:dword
    extrn '__imp__glTexCoord4fv@4' as glTexCoord4fv:dword
    extrn '__imp__glTexCoord4i@16' as glTexCoord4i:dword
    extrn '__imp__glTexCoord4iv@4' as glTexCoord4iv:dword
    extrn '__imp__glTexCoord4s@16' as glTexCoord4s:dword
    extrn '__imp__glTexCoord4sv@4' as glTexCoord4sv:dword
    extrn '__imp__glTexCoordPointer@16' as glTexCoordPointer:dword
    extrn '__imp__glTexEnvf@12' as glTexEnvf:dword
    extrn '__imp__glTexEnvfv@12' as glTexEnvfv:dword
    extrn '__imp__glTexEnvi@12' as glTexEnvi:dword
    extrn '__imp__glTexEnviv@12' as glTexEnviv:dword
    extrn '__imp__glTexGend@16' as glTexGend:dword
    extrn '__imp__glTexGendv@12' as glTexGendv:dword
    extrn '__imp__glTexGenf@12' as glTexGenf:dword
    extrn '__imp__glTexGenfv@12' as glTexGenfv:dword
    extrn '__imp__glTexGeni@12' as glTexGeni:dword
    extrn '__imp__glTexGeniv@12' as glTexGeniv:dword
    extrn '__imp__glTexImage1D@32' as glTexImage1D:dword
    extrn '__imp__glTexImage2D@36' as glTexImage2D:dword
    extrn '__imp__glTexParameterf@12' as glTexParameterf:dword
    extrn '__imp__glTexParameterfv@12' as glTexParameterfv:dword
    extrn '__imp__glTexParameteri@12' as glTexParameteri:dword
    extrn '__imp__glTexParameteriv@12' as glTexParameteriv:dword
    extrn '__imp__glTexSubImage1D@28' as glTexSubImage1D:dword
    extrn '__imp__glTexSubImage2D@36' as glTexSubImage2D:dword
    extrn '__imp__glTranslated@24' as glTranslated:dword
    extrn '__imp__glTranslatef@12' as glTranslatef:dword
    extrn '__imp__glVertex2d@16' as glVertex2d:dword
    extrn '__imp__glVertex2dv@4' as glVertex2dv:dword
    extrn '__imp__glVertex2f@8' as glVertex2f:dword
    extrn '__imp__glVertex2fv@4' as glVertex2fv:dword
    extrn '__imp__glVertex2i@8' as glVertex2i:dword
    extrn '__imp__glVertex2iv@4' as glVertex2iv:dword
    extrn '__imp__glVertex2s@8' as glVertex2s:dword
    extrn '__imp__glVertex2sv@4' as glVertex2sv:dword
    extrn '__imp__glVertex3d@24' as glVertex3d:dword
    extrn '__imp__glVertex3dv@4' as glVertex3dv:dword
    extrn '__imp__glVertex3f@12' as glVertex3f:dword
    extrn '__imp__glVertex3fv@4' as glVertex3fv:dword
    extrn '__imp__glVertex3i@12' as glVertex3i:dword
    extrn '__imp__glVertex3iv@4' as glVertex3iv:dword
    extrn '__imp__glVertex3s@12' as glVertex3s:dword
    extrn '__imp__glVertex3sv@4' as glVertex3sv:dword
    extrn '__imp__glVertex4d@32' as glVertex4d:dword
    extrn '__imp__glVertex4dv@4' as glVertex4dv:dword
    extrn '__imp__glVertex4f@16' as glVertex4f:dword
    extrn '__imp__glVertex4fv@4' as glVertex4fv:dword
    extrn '__imp__glVertex4i@16' as glVertex4i:dword
    extrn '__imp__glVertex4iv@4' as glVertex4iv:dword
    extrn '__imp__glVertex4s@16' as glVertex4s:dword
    extrn '__imp__glVertex4sv@4' as glVertex4sv:dword
    extrn '__imp__glVertexPointer@16' as glVertexPointer:dword
    extrn '__imp__glViewport@16' as glViewport:dword
    extrn '__imp__wglChoosePixelFormat@8' as wglChoosePixelFormat:dword
    extrn '__imp__wglCopyContext@12' as wglCopyContext:dword
    extrn '__imp__wglCreateContext@4' as wglCreateContext:dword
    extrn '__imp__wglCreateLayerContext@8' as wglCreateLayerContext:dword
    extrn '__imp__wglDeleteContext@4' as wglDeleteContext:dword
    extrn '__imp__wglDescribeLayerPlane@20' as wglDescribeLayerPlane:dword
    extrn '__imp__wglDescribePixelFormat@16' as wglDescribePixelFormat:dword
    extrn '__imp__wglGetCurrentContext@0' as wglGetCurrentContext:dword
    extrn '__imp__wglGetCurrentDC@0' as wglGetCurrentDC:dword
    extrn '__imp__wglGetDefaultProcAddress@4' as wglGetDefaultProcAddress:dword
    extrn '__imp__wglGetLayerPaletteEntries@20' as wglGetLayerPaletteEntries:dword
    extrn '__imp__wglGetPixelFormat@4' as wglGetPixelFormat:dword
    extrn '__imp__wglGetProcAddress@4' as wglGetProcAddress:dword
    extrn '__imp__wglMakeCurrent@8' as wglMakeCurrent:dword
    extrn '__imp__wglRealizeLayerPalette@12' as wglRealizeLayerPalette:dword
    extrn '__imp__wglSetLayerPaletteEntries@20' as wglSetLayerPaletteEntries:dword
    extrn '__imp__wglSetPixelFormat@12' as wglSetPixelFormat:dword
    extrn '__imp__wglShareLists@8' as wglShareLists:dword
    extrn '__imp__wglSwapBuffers@4' as wglSwapBuffers:dword
    extrn '__imp__wglSwapLayerBuffers@8' as wglSwapLayerBuffers:dword
    extrn '__imp__wglSwapMultipleBuffers@8' as wglSwapMultipleBuffers:dword
    extrn '__imp__wglUseFontBitmapsA@16' as wglUseFontBitmapsA:dword
    extrn '__imp__wglUseFontBitmapsW@16' as wglUseFontBitmapsW:dword
    extrn '__imp__wglUseFontOutlinesA@32' as wglUseFontOutlinesA:dword
    extrn '__imp__wglUseFontOutlinesW@32' as wglUseFontOutlinesW:dword
end if

api wglUseFontBitmaps,\
    wglUseFontOutlines

end if ;OPENGL32_INC
