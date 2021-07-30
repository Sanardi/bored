; ====================================================;
;                                                     ;
;    opengl32.inc for EC v2 SolAsm visual projects    ;
;                   (version 1.0.3)                   ;
;                                                     ;
;            Copyright © Ramon Sala - 2019            ;
;                                                     ;
; ====================================================;

#ifndef OPENGL32_INC
OPENGL32_INC equ 1

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
;AUX_A                                           db      'A',0
;AUX_B                                           db      'B',0
;AUX_C                                           db      'C',0
;AUX_D                                           db      'D',0
;AUX_E                                           db      'E',0
;AUX_F                                           db      'F',0
;AUX_G                                           db      'G',0
;AUX_H                                           db      'H',0
;AUX_I                                           db      'I',0
;AUX_J                                           db      'J',0
;AUX_K                                           db      'K',0
;AUX_L                                           db      'L',0
;AUX_M                                           db      'M',0
;AUX_N                                           db      'N',0
;AUX_O                                           db      'O',0
;AUX_P                                           db      'P',0
;AUX_Q                                           db      'Q',0
;AUX_R                                           db      'R',0
;AUX_S                                           db      'S',0
;AUX_T                                           db      'T',0
;AUX_U                                           db      'U',0
;AUX_V                                           db      'V',0
;AUX_W                                           db      'W',0
;AUX_X                                           db      'X',0
;AUX_Y                                           db      'Y',0
;AUX_Z                                           db      'Z',0
;AUX_a                                           db      'a',0
;AUX_b                                           db      'b',0
;AUX_c                                           db      'c',0
;AUX_d                                           db      'd',0
;AUX_e                                           db      'e',0
;AUX_f                                           db      'f',0
;AUX_g                                           db      'g',0
;AUX_h                                           db      'h',0
;AUX_i                                           db      'i',0
;AUX_j                                           db      'j',0
;AUX_k                                           db      'k',0
;AUX_l                                           db      'l',0
;AUX_m                                           db      'm',0
;AUX_n                                           db      'n',0
;AUX_o                                           db      'o',0
;AUX_p                                           db      'p',0
;AUX_q                                           db      'q',0
;AUX_r                                           db      'r',0
;AUX_s                                           db      's',0
;AUX_t                                           db      't',0
;AUX_u                                           db      'u',0
;AUX_v                                           db      'v',0
;AUX_w                                           db      'w',0
;AUX_x                                           db      'x',0
;AUX_y                                           db      'y',0
;AUX_z                                           db      'z',0
;AUX_0                                           db      '0',0
;AUX_1                                           db      '1',0
;AUX_2                                           db      '2',0
;AUX_3                                           db      '3',0
;AUX_4                                           db      '4',0
;AUX_5                                           db      '5',0
;AUX_6                                           db      '6',0
;AUX_7                                           db      '7',0
;AUX_8                                           db      '8',0
;AUX_9                                           db      '9',0

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

;======================================== Functions =======================================;
#if COFF_FORMAT == 1
    from_lib opengl32.lib
#else
    from_dll opengl32.dll
#endif

#ifdef APP_WIN64
    import GlmfBeginGlsBlock
    import GlmfCloseMetaFile
    import GlmfEndGlsBlock
    import GlmfEndPlayback
    import GlmfInitPlayback
    import GlmfPlayGlsRecord
    import glAccum
    import glAlphaFunc
    import glAreTexturesResident
    import glArrayElement
    import glBegin
    import glBindTexture
    import glBitmap
    import glBlendFunc
    import glCallList
    import glCallLists
    import glClear
    import glClearAccum
    import glClearColor
    import glClearDepth
    import glClearIndex
    import glClearStencil
    import glClipPlane
    import glColor3b
    import glColor3bv
    import glColor3d
    import glColor3dv
    import glColor3f
    import glColor3fv
    import glColor3i
    import glColor3iv
    import glColor3s
    import glColor3sv
    import glColor3ub
    import glColor3ubv
    import glColor3ui
    import glColor3uiv
    import glColor3us
    import glColor3usv
    import glColor4b
    import glColor4bv
    import glColor4d
    import glColor4dv
    import glColor4f
    import glColor4fv
    import glColor4i
    import glColor4iv
    import glColor4s
    import glColor4sv
    import glColor4ub
    import glColor4ubv
    import glColor4ui
    import glColor4uiv
    import glColor4us
    import glColor4usv
    import glColorMask
    import glColorMaterial
    import glColorPointer
    import glCopyPixels
    import glCopyTexImage1D
    import glCopyTexImage2D
    import glCopyTexSubImage1D
    import glCopyTexSubImage2D
    import glCullFace
    import glDebugEntry
    import glDeleteLists
    import glDeleteTextures
    import glDepthFunc
    import glDepthMask
    import glDepthRange
    import glDisable
    import glDisableClientState
    import glDrawArrays
    import glDrawBuffer
    import glDrawElements
    import glDrawPixels
    import glEdgeFlag
    import glEdgeFlagPointer
    import glEdgeFlagv
    import glEnable
    import glEnableClientState
    import glEnd
    import glEndList
    import glEvalCoord1d
    import glEvalCoord1dv
    import glEvalCoord1f
    import glEvalCoord1fv
    import glEvalCoord2d
    import glEvalCoord2dv
    import glEvalCoord2f
    import glEvalCoord2fv
    import glEvalMesh1
    import glEvalMesh2
    import glEvalPoint1
    import glEvalPoint2
    import glFeedbackBuffer
    import glFinish
    import glFlush
    import glFogf
    import glFogfv
    import glFogi
    import glFogiv
    import glFrontFace
    import glFrustum
    import glGenLists
    import glGenTextures
    import glGetBooleanv
    import glGetClipPlane
    import glGetDoublev
    import glGetError
    import glGetFloatv
    import glGetIntegerv
    import glGetLightfv
    import glGetLightiv
    import glGetMapdv
    import glGetMapfv
    import glGetMapiv
    import glGetMaterialfv
    import glGetMaterialiv
    import glGetPixelMapfv
    import glGetPixelMapuiv
    import glGetPixelMapusv
    import glGetPointerv
    import glGetPolygonStipple
    import glGetString
    import glGetTexEnvfv
    import glGetTexEnviv
    import glGetTexGendv
    import glGetTexGenfv
    import glGetTexGeniv
    import glGetTexImage
    import glGetTexLevelParameterfv
    import glGetTexLevelParameteriv
    import glGetTexParameterfv
    import glGetTexParameteriv
    import glHint
    import glIndexMask
    import glIndexPointer
    import glIndexd
    import glIndexdv
    import glIndexf
    import glIndexfv
    import glIndexi
    import glIndexiv
    import glIndexs
    import glIndexsv
    import glIndexub
    import glIndexubv
    import glInitNames
    import glInterleavedArrays
    import glIsEnabled
    import glIsList
    import glIsTexture
    import glLightModelf
    import glLightModelfv
    import glLightModeli
    import glLightModeliv
    import glLightf
    import glLightfv
    import glLighti
    import glLightiv
    import glLineStipple
    import glLineWidth
    import glListBase
    import glLoadIdentity
    import glLoadMatrixd
    import glLoadMatrixf
    import glLoadName
    import glLogicOp
    import glMap1d
    import glMap1f
    import glMap2d
    import glMap2f
    import glMapGrid1d
    import glMapGrid1f
    import glMapGrid2d
    import glMapGrid2f
    import glMaterialf
    import glMaterialfv
    import glMateriali
    import glMaterialiv
    import glMatrixMode
    import glMultMatrixd
    import glMultMatrixf
    import glNewList
    import glNormal3b
    import glNormal3bv
    import glNormal3d
    import glNormal3dv
    import glNormal3f
    import glNormal3fv
    import glNormal3i
    import glNormal3iv
    import glNormal3s
    import glNormal3sv
    import glNormalPointer
    import glOrtho
    import glPassThrough
    import glPixelMapfv
    import glPixelMapuiv
    import glPixelMapusv
    import glPixelStoref
    import glPixelStorei
    import glPixelTransferf
    import glPixelTransferi
    import glPixelZoom
    import glPointSize
    import glPolygonMode
    import glPolygonOffset
    import glPolygonStipple
    import glPopAttrib
    import glPopClientAttrib
    import glPopMatrix
    import glPopName
    import glPrioritizeTextures
    import glPushAttrib
    import glPushClientAttrib
    import glPushMatrix
    import glPushName
    import glRasterPos2d
    import glRasterPos2dv
    import glRasterPos2f
    import glRasterPos2fv
    import glRasterPos2i
    import glRasterPos2iv
    import glRasterPos2s
    import glRasterPos2sv
    import glRasterPos3d
    import glRasterPos3dv
    import glRasterPos3f
    import glRasterPos3fv
    import glRasterPos3i
    import glRasterPos3iv
    import glRasterPos3s
    import glRasterPos3sv
    import glRasterPos4d
    import glRasterPos4dv
    import glRasterPos4f
    import glRasterPos4fv
    import glRasterPos4i
    import glRasterPos4iv
    import glRasterPos4s
    import glRasterPos4sv
    import glReadBuffer
    import glReadPixels
    import glRectd
    import glRectdv
    import glRectf
    import glRectfv
    import glRecti
    import glRectiv
    import glRects
    import glRectsv
    import glRenderMode
    import glRotated
    import glRotatef
    import glScaled
    import glScalef
    import glScissor
    import glSelectBuffer
    import glShadeModel
    import glStencilFunc
    import glStencilMask
    import glStencilOp
    import glTexCoord1d
    import glTexCoord1dv
    import glTexCoord1f
    import glTexCoord1fv
    import glTexCoord1i
    import glTexCoord1iv
    import glTexCoord1s
    import glTexCoord1sv
    import glTexCoord2d
    import glTexCoord2dv
    import glTexCoord2f
    import glTexCoord2fv
    import glTexCoord2i
    import glTexCoord2iv
    import glTexCoord2s
    import glTexCoord2sv
    import glTexCoord3d
    import glTexCoord3dv
    import glTexCoord3f
    import glTexCoord3fv
    import glTexCoord3i
    import glTexCoord3iv
    import glTexCoord3s
    import glTexCoord3sv
    import glTexCoord4d
    import glTexCoord4dv
    import glTexCoord4f
    import glTexCoord4fv
    import glTexCoord4i
    import glTexCoord4iv
    import glTexCoord4s
    import glTexCoord4sv
    import glTexCoordPointer
    import glTexEnvf
    import glTexEnvfv
    import glTexEnvi
    import glTexEnviv
    import glTexGend
    import glTexGendv
    import glTexGenf
    import glTexGenfv
    import glTexGeni
    import glTexGeniv
    import glTexImage1D
    import glTexImage2D
    import glTexParameterf
    import glTexParameterfv
    import glTexParameteri
    import glTexParameteriv
    import glTexSubImage1D
    import glTexSubImage2D
    import glTranslated
    import glTranslatef
    import glVertex2d
    import glVertex2dv
    import glVertex2f
    import glVertex2fv
    import glVertex2i
    import glVertex2iv
    import glVertex2s
    import glVertex2sv
    import glVertex3d
    import glVertex3dv
    import glVertex3f
    import glVertex3fv
    import glVertex3i
    import glVertex3iv
    import glVertex3s
    import glVertex3sv
    import glVertex4d
    import glVertex4dv
    import glVertex4f
    import glVertex4fv
    import glVertex4i
    import glVertex4iv
    import glVertex4s
    import glVertex4sv
    import glVertexPointer
    import glViewport
    import wglChoosePixelFormat
    import wglCopyContext
    import wglCreateContext
    import wglCreateLayerContext
    import wglDeleteContext
    import wglDescribeLayerPlane
    import wglDescribePixelFormat
    import wglGetCurrentContext
    import wglGetCurrentDC
    import wglGetDefaultProcAddress
    import wglGetLayerPaletteEntries
    import wglGetPixelFormat
    import wglGetProcAddress
    import wglMakeCurrent
    import wglRealizeLayerPalette
    import wglSetLayerPaletteEntries
    import wglSetPixelFormat
    import wglShareLists
    import wglSwapBuffers
    import wglSwapLayerBuffers
    import wglSwapMultipleBuffers
    import wglUseFontBitmapsA
    import wglUseFontBitmapsW
    import wglUseFontOutlinesA
    import wglUseFontOutlinesW
#else
    extern GlmfBeginGlsBlock alias _GlmfBeginGlsBlock@4
    extern GlmfCloseMetaFile alias _GlmfCloseMetaFile@4
    extern GlmfEndGlsBlock alias _GlmfEndGlsBlock@4
    extern GlmfEndPlayback alias _GlmfEndPlayback@4
    extern GlmfInitPlayback alias _GlmfInitPlayback@12
    extern GlmfPlayGlsRecord alias _GlmfPlayGlsRecord@16
    extern glAccum alias _glAccum@8
    extern glAlphaFunc alias _glAlphaFunc@8
    extern glAreTexturesResident alias _glAreTexturesResident@12
    extern glArrayElement alias _glArrayElement@4
    extern glBegin alias _glBegin@4
    extern glBindTexture alias _glBindTexture@8
    extern glBitmap alias _glBitmap@28
    extern glBlendFunc alias _glBlendFunc@8
    extern glCallList alias _glCallList@4
    extern glCallLists alias _glCallLists@12
    extern glClear alias _glClear@4
    extern glClearAccum alias _glClearAccum@16
    extern glClearColor alias _glClearColor@16
    extern glClearDepth alias _glClearDepth@8
    extern glClearIndex alias _glClearIndex@4
    extern glClearStencil alias _glClearStencil@4
    extern glClipPlane alias _glClipPlane@8
    extern glColor3b alias _glColor3b@12
    extern glColor3bv alias _glColor3bv@4
    extern glColor3d alias _glColor3d@24
    extern glColor3dv alias _glColor3dv@4
    extern glColor3f alias _glColor3f@12
    extern glColor3fv alias _glColor3fv@4
    extern glColor3i alias _glColor3i@12
    extern glColor3iv alias _glColor3iv@4
    extern glColor3s alias _glColor3s@12
    extern glColor3sv alias _glColor3sv@4
    extern glColor3ub alias _glColor3ub@12
    extern glColor3ubv alias _glColor3ubv@4
    extern glColor3ui alias _glColor3ui@12
    extern glColor3uiv alias _glColor3uiv@4
    extern glColor3us alias _glColor3us@12
    extern glColor3usv alias _glColor3usv@4
    extern glColor4b alias _glColor4b@16
    extern glColor4bv alias _glColor4bv@4
    extern glColor4d alias _glColor4d@32
    extern glColor4dv alias _glColor4dv@4
    extern glColor4f alias _glColor4f@16
    extern glColor4fv alias _glColor4fv@4
    extern glColor4i alias _glColor4i@16
    extern glColor4iv alias _glColor4iv@4
    extern glColor4s alias _glColor4s@16
    extern glColor4sv alias _glColor4sv@4
    extern glColor4ub alias _glColor4ub@16
    extern glColor4ubv alias _glColor4ubv@4
    extern glColor4ui alias _glColor4ui@16
    extern glColor4uiv alias _glColor4uiv@4
    extern glColor4us alias _glColor4us@16
    extern glColor4usv alias _glColor4usv@4
    extern glColorMask alias _glColorMask@16
    extern glColorMaterial alias _glColorMaterial@8
    extern glColorPointer alias _glColorPointer@16
    extern glCopyPixels alias _glCopyPixels@20
    extern glCopyTexImage1D alias _glCopyTexImage1D@28
    extern glCopyTexImage2D alias _glCopyTexImage2D@32
    extern glCopyTexSubImage1D alias _glCopyTexSubImage1D@24
    extern glCopyTexSubImage2D alias _glCopyTexSubImage2D@32
    extern glCullFace alias _glCullFace@4
    extern glDebugEntry alias _glDebugEntry@8
    extern glDeleteLists alias _glDeleteLists@8
    extern glDeleteTextures alias _glDeleteTextures@8
    extern glDepthFunc alias _glDepthFunc@4
    extern glDepthMask alias _glDepthMask@4
    extern glDepthRange alias _glDepthRange@16
    extern glDisable alias _glDisable@4
    extern glDisableClientState alias _glDisableClientState@4
    extern glDrawArrays alias _glDrawArrays@12
    extern glDrawBuffer alias _glDrawBuffer@4
    extern glDrawElements alias _glDrawElements@16
    extern glDrawPixels alias _glDrawPixels@20
    extern glEdgeFlag alias _glEdgeFlag@4
    extern glEdgeFlagPointer alias _glEdgeFlagPointer@8
    extern glEdgeFlagv alias _glEdgeFlagv@4
    extern glEnable alias _glEnable@4
    extern glEnableClientState alias _glEnableClientState@4
    extern glEnd alias _glEnd@0
    extern glEndList alias _glEndList@0
    extern glEvalCoord1d alias _glEvalCoord1d@8
    extern glEvalCoord1dv alias _glEvalCoord1dv@4
    extern glEvalCoord1f alias _glEvalCoord1f@4
    extern glEvalCoord1fv alias _glEvalCoord1fv@4
    extern glEvalCoord2d alias _glEvalCoord2d@16
    extern glEvalCoord2dv alias _glEvalCoord2dv@4
    extern glEvalCoord2f alias _glEvalCoord2f@8
    extern glEvalCoord2fv alias _glEvalCoord2fv@4
    extern glEvalMesh1 alias _glEvalMesh1@12
    extern glEvalMesh2 alias _glEvalMesh2@20
    extern glEvalPoint1 alias _glEvalPoint1@4
    extern glEvalPoint2 alias _glEvalPoint2@8
    extern glFeedbackBuffer alias _glFeedbackBuffer@12
    extern glFinish alias _glFinish@0
    extern glFlush alias _glFlush@0
    extern glFogf alias _glFogf@8
    extern glFogfv alias _glFogfv@8
    extern glFogi alias _glFogi@8
    extern glFogiv alias _glFogiv@8
    extern glFrontFace alias _glFrontFace@4
    extern glFrustum alias _glFrustum@48
    extern glGenLists alias _glGenLists@4
    extern glGenTextures alias _glGenTextures@8
    extern glGetBooleanv alias _glGetBooleanv@8
    extern glGetClipPlane alias _glGetClipPlane@8
    extern glGetDoublev alias _glGetDoublev@8
    extern glGetError alias _glGetError@0
    extern glGetFloatv alias _glGetFloatv@8
    extern glGetIntegerv alias _glGetIntegerv@8
    extern glGetLightfv alias _glGetLightfv@12
    extern glGetLightiv alias _glGetLightiv@12
    extern glGetMapdv alias _glGetMapdv@12
    extern glGetMapfv alias _glGetMapfv@12
    extern glGetMapiv alias _glGetMapiv@12
    extern glGetMaterialfv alias _glGetMaterialfv@12
    extern glGetMaterialiv alias _glGetMaterialiv@12
    extern glGetPixelMapfv alias _glGetPixelMapfv@8
    extern glGetPixelMapuiv alias _glGetPixelMapuiv@8
    extern glGetPixelMapusv alias _glGetPixelMapusv@8
    extern glGetPointerv alias _glGetPointerv@8
    extern glGetPolygonStipple alias _glGetPolygonStipple@4
    extern glGetString alias _glGetString@4
    extern glGetTexEnvfv alias _glGetTexEnvfv@12
    extern glGetTexEnviv alias _glGetTexEnviv@12
    extern glGetTexGendv alias _glGetTexGendv@12
    extern glGetTexGenfv alias _glGetTexGenfv@12
    extern glGetTexGeniv alias _glGetTexGeniv@12
    extern glGetTexImage alias _glGetTexImage@20
    extern glGetTexLevelParameterfv alias _glGetTexLevelParameterfv@16
    extern glGetTexLevelParameteriv alias _glGetTexLevelParameteriv@16
    extern glGetTexParameterfv alias _glGetTexParameterfv@12
    extern glGetTexParameteriv alias _glGetTexParameteriv@12
    extern glHint alias _glHint@8
    extern glIndexMask alias _glIndexMask@4
    extern glIndexPointer alias _glIndexPointer@12
    extern glIndexd alias _glIndexd@8
    extern glIndexdv alias _glIndexdv@4
    extern glIndexf alias _glIndexf@4
    extern glIndexfv alias _glIndexfv@4
    extern glIndexi alias _glIndexi@4
    extern glIndexiv alias _glIndexiv@4
    extern glIndexs alias _glIndexs@4
    extern glIndexsv alias _glIndexsv@4
    extern glIndexub alias _glIndexub@4
    extern glIndexubv alias _glIndexubv@4
    extern glInitNames alias _glInitNames@0
    extern glInterleavedArrays alias _glInterleavedArrays@12
    extern glIsEnabled alias _glIsEnabled@4
    extern glIsList alias _glIsList@4
    extern glIsTexture alias _glIsTexture@4
    extern glLightModelf alias _glLightModelf@8
    extern glLightModelfv alias _glLightModelfv@8
    extern glLightModeli alias _glLightModeli@8
    extern glLightModeliv alias _glLightModeliv@8
    extern glLightf alias _glLightf@12
    extern glLightfv alias _glLightfv@12
    extern glLighti alias _glLighti@12
    extern glLightiv alias _glLightiv@12
    extern glLineStipple alias _glLineStipple@8
    extern glLineWidth alias _glLineWidth@4
    extern glListBase alias _glListBase@4
    extern glLoadIdentity alias _glLoadIdentity@0
    extern glLoadMatrixd alias _glLoadMatrixd@4
    extern glLoadMatrixf alias _glLoadMatrixf@4
    extern glLoadName alias _glLoadName@4
    extern glLogicOp alias _glLogicOp@4
    extern glMap1d alias _glMap1d@32
    extern glMap1f alias _glMap1f@24
    extern glMap2d alias _glMap2d@56
    extern glMap2f alias _glMap2f@40
    extern glMapGrid1d alias _glMapGrid1d@20
    extern glMapGrid1f alias _glMapGrid1f@12
    extern glMapGrid2d alias _glMapGrid2d@40
    extern glMapGrid2f alias _glMapGrid2f@24
    extern glMaterialf alias _glMaterialf@12
    extern glMaterialfv alias _glMaterialfv@12
    extern glMateriali alias _glMateriali@12
    extern glMaterialiv alias _glMaterialiv@12
    extern glMatrixMode alias _glMatrixMode@4
    extern glMultMatrixd alias _glMultMatrixd@4
    extern glMultMatrixf alias _glMultMatrixf@4
    extern glNewList alias _glNewList@8
    extern glNormal3b alias _glNormal3b@12
    extern glNormal3bv alias _glNormal3bv@4
    extern glNormal3d alias _glNormal3d@24
    extern glNormal3dv alias _glNormal3dv@4
    extern glNormal3f alias _glNormal3f@12
    extern glNormal3fv alias _glNormal3fv@4
    extern glNormal3i alias _glNormal3i@12
    extern glNormal3iv alias _glNormal3iv@4
    extern glNormal3s alias _glNormal3s@12
    extern glNormal3sv alias _glNormal3sv@4
    extern glNormalPointer alias _glNormalPointer@12
    extern glOrtho alias _glOrtho@48
    extern glPassThrough alias _glPassThrough@4
    extern glPixelMapfv alias _glPixelMapfv@12
    extern glPixelMapuiv alias _glPixelMapuiv@12
    extern glPixelMapusv alias _glPixelMapusv@12
    extern glPixelStoref alias _glPixelStoref@8
    extern glPixelStorei alias _glPixelStorei@8
    extern glPixelTransferf alias _glPixelTransferf@8
    extern glPixelTransferi alias _glPixelTransferi@8
    extern glPixelZoom alias _glPixelZoom@8
    extern glPointSize alias _glPointSize@4
    extern glPolygonMode alias _glPolygonMode@8
    extern glPolygonOffset alias _glPolygonOffset@8
    extern glPolygonStipple alias _glPolygonStipple@4
    extern glPopAttrib alias _glPopAttrib@0
    extern glPopClientAttrib alias _glPopClientAttrib@0
    extern glPopMatrix alias _glPopMatrix@0
    extern glPopName alias _glPopName@0
    extern glPrioritizeTextures alias _glPrioritizeTextures@12
    extern glPushAttrib alias _glPushAttrib@4
    extern glPushClientAttrib alias _glPushClientAttrib@4
    extern glPushMatrix alias _glPushMatrix@0
    extern glPushName alias _glPushName@4
    extern glRasterPos2d alias _glRasterPos2d@16
    extern glRasterPos2dv alias _glRasterPos2dv@4
    extern glRasterPos2f alias _glRasterPos2f@8
    extern glRasterPos2fv alias _glRasterPos2fv@4
    extern glRasterPos2i alias _glRasterPos2i@8
    extern glRasterPos2iv alias _glRasterPos2iv@4
    extern glRasterPos2s alias _glRasterPos2s@8
    extern glRasterPos2sv alias _glRasterPos2sv@4
    extern glRasterPos3d alias _glRasterPos3d@24
    extern glRasterPos3dv alias _glRasterPos3dv@4
    extern glRasterPos3f alias _glRasterPos3f@12
    extern glRasterPos3fv alias _glRasterPos3fv@4
    extern glRasterPos3i alias _glRasterPos3i@12
    extern glRasterPos3iv alias _glRasterPos3iv@4
    extern glRasterPos3s alias _glRasterPos3s@12
    extern glRasterPos3sv alias _glRasterPos3sv@4
    extern glRasterPos4d alias _glRasterPos4d@32
    extern glRasterPos4dv alias _glRasterPos4dv@4
    extern glRasterPos4f alias _glRasterPos4f@16
    extern glRasterPos4fv alias _glRasterPos4fv@4
    extern glRasterPos4i alias _glRasterPos4i@16
    extern glRasterPos4iv alias _glRasterPos4iv@4
    extern glRasterPos4s alias _glRasterPos4s@16
    extern glRasterPos4sv alias _glRasterPos4sv@4
    extern glReadBuffer alias _glReadBuffer@4
    extern glReadPixels alias _glReadPixels@28
    extern glRectd alias _glRectd@32
    extern glRectdv alias _glRectdv@8
    extern glRectf alias _glRectf@16
    extern glRectfv alias _glRectfv@8
    extern glRecti alias _glRecti@16
    extern glRectiv alias _glRectiv@8
    extern glRects alias _glRects@16
    extern glRectsv alias _glRectsv@8
    extern glRenderMode alias _glRenderMode@4
    extern glRotated alias _glRotated@32
    extern glRotatef alias _glRotatef@16
    extern glScaled alias _glScaled@24
    extern glScalef alias _glScalef@12
    extern glScissor alias _glScissor@16
    extern glSelectBuffer alias _glSelectBuffer@8
    extern glShadeModel alias _glShadeModel@4
    extern glStencilFunc alias _glStencilFunc@12
    extern glStencilMask alias _glStencilMask@4
    extern glStencilOp alias _glStencilOp@12
    extern glTexCoord1d alias _glTexCoord1d@8
    extern glTexCoord1dv alias _glTexCoord1dv@4
    extern glTexCoord1f alias _glTexCoord1f@4
    extern glTexCoord1fv alias _glTexCoord1fv@4
    extern glTexCoord1i alias _glTexCoord1i@4
    extern glTexCoord1iv alias _glTexCoord1iv@4
    extern glTexCoord1s alias _glTexCoord1s@4
    extern glTexCoord1sv alias _glTexCoord1sv@4
    extern glTexCoord2d alias _glTexCoord2d@16
    extern glTexCoord2dv alias _glTexCoord2dv@4
    extern glTexCoord2f alias _glTexCoord2f@8
    extern glTexCoord2fv alias _glTexCoord2fv@4
    extern glTexCoord2i alias _glTexCoord2i@8
    extern glTexCoord2iv alias _glTexCoord2iv@4
    extern glTexCoord2s alias _glTexCoord2s@8
    extern glTexCoord2sv alias _glTexCoord2sv@4
    extern glTexCoord3d alias _glTexCoord3d@24
    extern glTexCoord3dv alias _glTexCoord3dv@4
    extern glTexCoord3f alias _glTexCoord3f@12
    extern glTexCoord3fv alias _glTexCoord3fv@4
    extern glTexCoord3i alias _glTexCoord3i@12
    extern glTexCoord3iv alias _glTexCoord3iv@4
    extern glTexCoord3s alias _glTexCoord3s@12
    extern glTexCoord3sv alias _glTexCoord3sv@4
    extern glTexCoord4d alias _glTexCoord4d@32
    extern glTexCoord4dv alias _glTexCoord4dv@4
    extern glTexCoord4f alias _glTexCoord4f@16
    extern glTexCoord4fv alias _glTexCoord4fv@4
    extern glTexCoord4i alias _glTexCoord4i@16
    extern glTexCoord4iv alias _glTexCoord4iv@4
    extern glTexCoord4s alias _glTexCoord4s@16
    extern glTexCoord4sv alias _glTexCoord4sv@4
    extern glTexCoordPointer alias _glTexCoordPointer@16
    extern glTexEnvf alias _glTexEnvf@12
    extern glTexEnvfv alias _glTexEnvfv@12
    extern glTexEnvi alias _glTexEnvi@12
    extern glTexEnviv alias _glTexEnviv@12
    extern glTexGend alias _glTexGend@16
    extern glTexGendv alias _glTexGendv@12
    extern glTexGenf alias _glTexGenf@12
    extern glTexGenfv alias _glTexGenfv@12
    extern glTexGeni alias _glTexGeni@12
    extern glTexGeniv alias _glTexGeniv@12
    extern glTexImage1D alias _glTexImage1D@32
    extern glTexImage2D alias _glTexImage2D@36
    extern glTexParameterf alias _glTexParameterf@12
    extern glTexParameterfv alias _glTexParameterfv@12
    extern glTexParameteri alias _glTexParameteri@12
    extern glTexParameteriv alias _glTexParameteriv@12
    extern glTexSubImage1D alias _glTexSubImage1D@28
    extern glTexSubImage2D alias _glTexSubImage2D@36
    extern glTranslated alias _glTranslated@24
    extern glTranslatef alias _glTranslatef@12
    extern glVertex2d alias _glVertex2d@16
    extern glVertex2dv alias _glVertex2dv@4
    extern glVertex2f alias _glVertex2f@8
    extern glVertex2fv alias _glVertex2fv@4
    extern glVertex2i alias _glVertex2i@8
    extern glVertex2iv alias _glVertex2iv@4
    extern glVertex2s alias _glVertex2s@8
    extern glVertex2sv alias _glVertex2sv@4
    extern glVertex3d alias _glVertex3d@24
    extern glVertex3dv alias _glVertex3dv@4
    extern glVertex3f alias _glVertex3f@12
    extern glVertex3fv alias _glVertex3fv@4
    extern glVertex3i alias _glVertex3i@12
    extern glVertex3iv alias _glVertex3iv@4
    extern glVertex3s alias _glVertex3s@12
    extern glVertex3sv alias _glVertex3sv@4
    extern glVertex4d alias _glVertex4d@32
    extern glVertex4dv alias _glVertex4dv@4
    extern glVertex4f alias _glVertex4f@16
    extern glVertex4fv alias _glVertex4fv@4
    extern glVertex4i alias _glVertex4i@16
    extern glVertex4iv alias _glVertex4iv@4
    extern glVertex4s alias _glVertex4s@16
    extern glVertex4sv alias _glVertex4sv@4
    extern glVertexPointer alias _glVertexPointer@16
    extern glViewport alias _glViewport@16
    extern wglChoosePixelFormat alias _wglChoosePixelFormat@8
    extern wglCopyContext alias _wglCopyContext@12
    extern wglCreateContext alias _wglCreateContext@4
    extern wglCreateLayerContext alias _wglCreateLayerContext@8
    extern wglDeleteContext alias _wglDeleteContext@4
    extern wglDescribeLayerPlane alias _wglDescribeLayerPlane@20
    extern wglDescribePixelFormat alias _wglDescribePixelFormat@16
    extern wglGetCurrentContext alias _wglGetCurrentContext@0
    extern wglGetCurrentDC alias _wglGetCurrentDC@0
    extern wglGetDefaultProcAddress alias _wglGetDefaultProcAddress@4
    extern wglGetLayerPaletteEntries alias _wglGetLayerPaletteEntries@20
    extern wglGetPixelFormat alias _wglGetPixelFormat@4
    extern wglGetProcAddress alias _wglGetProcAddress@4
    extern wglMakeCurrent alias _wglMakeCurrent@8
    extern wglRealizeLayerPalette alias _wglRealizeLayerPalette@12
    extern wglSetLayerPaletteEntries alias _wglSetLayerPaletteEntries@20
    extern wglSetPixelFormat alias _wglSetPixelFormat@12
    extern wglShareLists alias _wglShareLists@8
    extern wglSwapBuffers alias _wglSwapBuffers@4
    extern wglSwapLayerBuffers alias _wglSwapLayerBuffers@8
    extern wglSwapMultipleBuffers alias _wglSwapMultipleBuffers@8
    extern wglUseFontBitmapsA alias _wglUseFontBitmapsA@16
    extern wglUseFontBitmapsW alias _wglUseFontBitmapsW@16
    extern wglUseFontOutlinesA alias _wglUseFontOutlinesA@32
    extern wglUseFontOutlinesW alias _wglUseFontOutlinesW@32
#endif

#ifdef APP_UNICODE
    define wglUseFontBitmaps wglUseFontBitmapsW
    define wglUseFontOutlines wglUseFontOutlinesW
#else
    define wglUseFontBitmaps wglUseFontBitmapsA
    define wglUseFontOutlines wglUseFontOutlinesA
#endif

#endif ;OPENGL32_INC
