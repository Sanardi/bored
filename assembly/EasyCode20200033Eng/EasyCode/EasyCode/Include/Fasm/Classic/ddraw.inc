;======================================================;
;                                                      ;
;       ddraw.inc for EC v2 Fasm classic projects      ;
;                   (version 1.0.1)                    ;
;                                                      ;
;             Copyright © Ramon Sala - 2020            ;
;                                                      ;
;======================================================;

if ~defined DDRAW_INC
define DDRAW_INC    1

if ~defined DIRECTDRAW_VERSION
    define                                      DIRECTDRAW_VERSION 0700H
end if

DDRAW_H_REQVER                                  equ     100

DDENUM_ATTACHEDSECONDARYDEVICES                 equ     00000001H
DDENUM_DETACHEDSECONDARYDEVICES                 equ     00000002H
DDENUM_NONDISPLAYDEVICES                        equ     00000004H

REGSTR_KEY_DDHW_DESCRIPTION                     equ     <Description>
REGSTR_KEY_DDHW_DRIVERNAME                      equ     <DriverName>
REGSTR_PATH_DDHW                                equ     <Hardware\DirectDrawDrivers>

DDCREATE_HARDWAREONLY                           equ     00000001H
DDCREATE_EMULATIONONLY                          equ     00000002H

DD_ROP_SPACE                                    equ     8

MAX_DDDEVICEID_STRING                           equ     512

DDGDI_GETHOSTIDENTIFIER                         equ     00000001H

DDSD_CAPS                                       equ     00000001H
DDSD_HEIGHT                                     equ     00000002H
DDSD_WIDTH                                      equ     00000004H
DDSD_PITCH                                      equ     00000008H
DDSD_BACKBUFFERCOUNT                            equ     00000020H
DDSD_ZBUFFERBITDEPTH                            equ     00000040H
DDSD_ALPHABITDEPTH                              equ     00000080H
DDSD_LPSURFACE                                  equ     00000800H
DDSD_PIXELFORMAT                                equ     00001000H
DDSD_CKDESTOVERLAY                              equ     00002000H
DDSD_CKDESTBLT                                  equ     00004000H
DDSD_CKSRCOVERLAY                               equ     00008000H
DDSD_CKSRCBLT                                   equ     00010000H
DDSD_MIPMAPCOUNT                                equ     00020000H
DDSD_REFRESHRATE                                equ     00040000H
DDSD_LINEARSIZE                                 equ     00080000H
DDSD_TEXTURESTAGE                               equ     00100000H
DDSD_FVF                                        equ     00200000H
DDSD_SRCVBHANDLE                                equ     00400000H
DDSD_ALL                                        equ     07FF9EElH

DDOSD_GUID                                      equ     00000001H
DDOSD_COMPRESSION_RATIO                         equ     00000002H
DDOSD_SCAPS                                     equ     00000004H
DDOSD_OSCAPS                                    equ     00000008H
DDOSD_ALL                                       equ     000000flH

DDOSDCAPS_OPTCOMPRESSED                         equ     00000001H
DDOSDCAPS_OPTREORDERED                          equ     00000002H
DDOSDCAPS_MONOLITHICMIPMAP                      equ     00000004H
DDOSDCAPS_VALIDSCAPS                            equ     30004800H
DDOSDCAPS_VALIDOSCAPS                           equ     00000007H

DDCOLOR_BRIGHTNESS                              equ     00000001H
DDCOLOR_CONTRAST                                equ     00000002H
DDCOLOR_HUE                                     equ     00000004H
DDCOLOR_SATURATION                              equ     00000008H
DDCOLOR_SHARPNESS                               equ     00000010H
DDCOLOR_GAMMA                                   equ     00000020H
DDCOLOR_COLORENABLE                             equ     00000040H

DDSCAPS_RESERVED1                               equ     00000001H
DDSCAPS_ALPHA                                   equ     00000002H
DDSCAPS_BACKBUFFER                              equ     00000004H
DDSCAPS_COMPLEX                                 equ     00000008H
DDSCAPS_FLIP                                    equ     00000010H
DDSCAPS_FRONTBUFFER                             equ     00000020H
DDSCAPS_OFFSCREENPLAIN                          equ     00000040H
DDSCAPS_OVERLAY                                 equ     00000080H
DDSCAPS_PALETTE                                 equ     00000100H
DDSCAPS_PRIMARYSURFACE                          equ     00000200H
DDSCAPS_RESERVED3                               equ     00000400H
DDSCAPS_PRIMARYSURFACELEFT                      equ     0
DDSCAPS_SYSTEMMEMORY                            equ     00000800H
DDSCAPS_TEXTURE                                 equ     00001000H
DDSCAPS_3DDEVICE                                equ     00002000H
DDSCAPS_VIDEOMEMORY                             equ     00004000H
DDSCAPS_VISIBLE                                 equ     00008000H
DDSCAPS_WRITEONLY                               equ     00010000H
DDSCAPS_ZBUFFER                                 equ     00020000H
DDSCAPS_OWNDC                                   equ     00040000H
DDSCAPS_LIVEVIDEO                               equ     00080000H
DDSCAPS_HWCODEC                                 equ     00100000H
DDSCAPS_MODEX                                   equ     00200000H
DDSCAPS_MIPMAP                                  equ     00400000H
DDSCAPS_RESERVED2                               equ     00800000H
DDSCAPS_ALLOCONLOAD                             equ     04000000H
DDSCAPS_VIDEOPORT                               equ     08000000H
DDSCAPS_LOCALVIDMEM                             equ     10000000H
DDSCAPS_NONLOCALVIDMEM                          equ     20000000H
DDSCAPS_STANDARDVGAMODE                         equ     40000000H
DDSCAPS_OPTIMIZED                               equ     80000000H

DDSCAPS2_HARDWAREDEINTERLACE                    equ     00000002H
DDSCAPS2_HINTDYNAMIC                            equ     00000004H
DDSCAPS2_HINTSTATIC                             equ     00000008H
DDSCAPS2_TEXTUREMANAGE                          equ     00000010H
DDSCAPS2_RESERVED1                              equ     00000020H
DDSCAPS2_RESERVED2                              equ     00000040H
DDSCAPS2_OPAQUE                                 equ     00000080H
DDSCAPS2_HINTANTIALIASING                       equ     00000100H
DDSCAPS2_CUBEMAP                                equ     00000200H
DDSCAPS2_CUBEMAP_POSITIVEX                      equ     00000400H
DDSCAPS2_CUBEMAP_NEGATIVEX                      equ     00000800H
DDSCAPS2_CUBEMAP_POSITIVEY                      equ     00001000H
DDSCAPS2_CUBEMAP_NEGATIVEY                      equ     00002000H
DDSCAPS2_CUBEMAP_POSITIVEZ                      equ     00004000H
DDSCAPS2_CUBEMAP_NEGATIVEZ                      equ     00008000H
DDSCAPS2_CUBEMAP_ALLFACES                       equ     (DDSCAPS2_CUBEMAP_POSITIVEX or DDSCAPS2_CUBEMAP_NEGATIVEX or DDSCAPS2_CUBEMAP_POSITIVEY or DDSCAPS2_CUBEMAP_NEGATIVEY or DDSCAPS2_CUBEMAP_POSITIVEZ or DDSCAPS2_CUBEMAP_NEGATIVEZ)
DDSCAPS2_MIPMAPSUBLEVEL                         equ     00010000H
DDSCAPS2_D3DTEXTUREMANAGE                       equ     00020000H
DDSCAPS2_DONOTPERSIST                           equ     00040000H
DDSCAPS2_STEREOSURFACELEFT                      equ     00080000H

DDCAPS_3D                                       equ     00000001H
DDCAPS_ALIGNBOUNDARYDEST                        equ     00000002H
DDCAPS_ALIGNSIZEDEST                            equ     00000004H
DDCAPS_ALIGNBOUNDARYSRC                         equ     00000008H
DDCAPS_ALIGNSIZESRC                             equ     00000010H
DDCAPS_ALIGNSTRIDE                              equ     00000020H
DDCAPS_BLT                                      equ     00000040H
DDCAPS_BLTQUEUE                                 equ     00000080H
DDCAPS_BLTFOURCC                                equ     00000100H
DDCAPS_BLTSTRETCH                               equ     00000200H
DDCAPS_GDI                                      equ     00000400H
DDCAPS_OVERLAY                                  equ     00000800H
DDCAPS_OVERLAYCANTCLIP                          equ     00001000H
DDCAPS_OVERLAYFOURCC                            equ     00002000H
DDCAPS_OVERLAYSTRETCH                           equ     00004000H
DDCAPS_PALETTE                                  equ     00008000H
DDCAPS_PALETTEVSYNC                             equ     00010000H
DDCAPS_READSCANLINE                             equ     00020000H
DDCAPS_RESERVED1                                equ     00040000H
DDCAPS_VBI                                      equ     00080000H
DDCAPS_ZBLTS                                    equ     00100000H
DDCAPS_ZOVERLAYS                                equ     00200000H
DDCAPS_COLORKEY                                 equ     00400000H
DDCAPS_ALPHA                                    equ     00800000H
DDCAPS_COLORKEYHWASSIST                         equ     01000000H
DDCAPS_NOHARDWARE                               equ     02000000H
DDCAPS_BLTCOLORFILL                             equ     04000000H
DDCAPS_BANKSWITCHED                             equ     08000000H
DDCAPS_BLTDEPTHFILL                             equ     10000000H
DDCAPS_CANCLIP                                  equ     20000000H
DDCAPS_CANCLIPSTRETCHED                         equ     40000000H
DDCAPS_CANBLTSYSMEM                             equ     80000000H

DDCAPS2_CERTIFIED                               equ     00000001H
DDCAPS2_NO2DDURING3DSCENE                       equ     00000002H
DDCAPS2_VIDEOPORT                               equ     00000004H
DDCAPS2_AUTOFLIPOVERLAY                         equ     00000008H
DDCAPS2_CANBOBINTERLEAVED                       equ     00000010H
DDCAPS2_CANBOBNONINTERLEAVED                    equ     00000020H
DDCAPS2_COLORCONTROLOVERLAY                     equ     00000040H
DDCAPS2_COLORCONTROLPRIMARY                     equ     00000080H
DDCAPS2_CANDROPZ16BIT                           equ     00000100H
DDCAPS2_NONLOCALVIDMEM                          equ     00000200H
DDCAPS2_NONLOCALVIDMEMCAPS                      equ     00000400H
DDCAPS2_NOPAGELOCKREQUIRED                      equ     00000800H
DDCAPS2_WIDESURFACES                            equ     00001000H
DDCAPS2_CANFLIPODDEVEN                          equ     00002000H
DDCAPS2_CANBOBHARDWARE                          equ     00004000H
DDCAPS2_COPYFOURCC                              equ     00008000H
DDCAPS2_PRIMARYGAMMA                            equ     00020000H
DDCAPS2_CANRENDERWINDOWED                       equ     00080000H
DDCAPS2_CANCALIBRATEGAMMA                       equ     00100000H
DDCAPS2_FLIPINTERVAL                            equ     00200000H
DDCAPS2_FLIPNOVSYNC                             equ     00400000H
DDCAPS2_CANMANAGETEXTURE                        equ     00800000H
DDCAPS2_TEXMANINNONLOCALVIDMEM                  equ     01000000H
DDCAPS2_STEREO                                  equ     02000000H
DDCAPS2_SYSTONONLOCAL_AS_SYSTOLOCAL             equ     04000000H

DDFXALPHACAPS_BLTALPHAEDGEBLEND                 equ     00000001H
DDFXALPHACAPS_BLTALPHAPIXELS                    equ     00000002H
DDFXALPHACAPS_BLTALPHAPIXELSNEG                 equ     00000004H
DDFXALPHACAPS_BLTALPHASURFACES                  equ     00000008H
DDFXALPHACAPS_BLTALPHASURFACESNEG               equ     00000010H
DDFXALPHACAPS_OVERLAYALPHAEDGEBLEND             equ     00000020H
DDFXALPHACAPS_OVERLAYALPHAPIXELS                equ     00000040H
DDFXALPHACAPS_OVERLAYALPHAPIXELSNEG             equ     00000080H
DDFXALPHACAPS_OVERLAYALPHASURFACES              equ     00000100H
DDFXALPHACAPS_OVERLAYALPHASURFACESNEG           equ     00000200H

DDFXCAPS_BLTARITHSTRETCHY                       equ     00000020H
DDFXCAPS_BLTARITHSTRETCHYN                      equ     00000010H
DDFXCAPS_BLTMIRRORLEFTRIGHT                     equ     00000040H
DDFXCAPS_BLTMIRRORUPDOWN                        equ     00000080H
DDFXCAPS_BLTROTATION                            equ     00000100H
DDFXCAPS_BLTROTATION90                          equ     00000200H
DDFXCAPS_BLTSHRINKX                             equ     00000400H
DDFXCAPS_BLTSHRINKXN                            equ     00000800H
DDFXCAPS_BLTSHRINKY                             equ     00001000H
DDFXCAPS_BLTSHRINKYN                            equ     00002000H
DDFXCAPS_BLTSTRETCHX                            equ     00004000H
DDFXCAPS_BLTSTRETCHXN                           equ     00008000H
DDFXCAPS_BLTSTRETCHY                            equ     00010000H
DDFXCAPS_BLTSTRETCHYN                           equ     00020000H
DDFXCAPS_OVERLAYARITHSTRETCHY                   equ     00040000H
DDFXCAPS_OVERLAYARITHSTRETCHYN                  equ     00000008H
DDFXCAPS_OVERLAYSHRINKX                         equ     00080000H
DDFXCAPS_OVERLAYSHRINKXN                        equ     00100000H
DDFXCAPS_OVERLAYSHRINKY                         equ     00200000H
DDFXCAPS_OVERLAYSHRINKYN                        equ     00400000H
DDFXCAPS_OVERLAYSTRETCHX                        equ     00800000H
DDFXCAPS_OVERLAYSTRETCHXN                       equ     01000000H
DDFXCAPS_OVERLAYSTRETCHY                        equ     02000000H
DDFXCAPS_OVERLAYSTRETCHYN                       equ     04000000H
DDFXCAPS_OVERLAYMIRRORLEFTRIGHT                 equ     08000000H
DDFXCAPS_OVERLAYMIRRORUPDOWN                    equ     10000000H
DDFXCAPS_BLTALPHA                               equ     00000001H
DDFXCAPS_BLTFILTER                              equ     DDFXCAPS_BLTARITHSTRETCHY
DDFXCAPS_OVERLAYALPHA                           equ     00000004H
DDFXCAPS_OVERLAYFILTER                          equ     DDFXCAPS_OVERLAYARITHSTRETCHY

DDSVCAPS_RESERVED1                              equ     00000001H
DDSVCAPS_RESERVED2                              equ     00000002H
DDSVCAPS_RESERVED3                              equ     00000004H
DDSVCAPS_RESERVED4                              equ     00000008H
DDSVCAPS_STEREOSEQUENTIAL                       equ     00000010H

DDPCAPS_4BIT                                    equ     00000001H
DDPCAPS_8BITENTRIES                             equ     00000002H
DDPCAPS_8BIT                                    equ     00000004H
DDPCAPS_INITIALIZE                              equ     00000000H
DDPCAPS_PRIMARYSURFACE                          equ     00000010H
DDPCAPS_PRIMARYSURFACELEFT                      equ     00000020H
DDPCAPS_ALLOW256                                equ     00000040H
DDPCAPS_VSYNC                                   equ     00000080H
DDPCAPS_1BIT                                    equ     00000100H
DDPCAPS_2BIT                                    equ     00000200H
DDPCAPS_ALPHA                                   equ     00000400H

DDSPD_IUNKNOWNPOINTER                           equ     00000001H
DDSPD_VOLATILE                                  equ     00000002H

DDBD_1                                          equ     00004000H
DDBD_2                                          equ     00002000H
DDBD_4                                          equ     00001000H
DDBD_8                                          equ     00000800H
DDBD_16                                         equ     00000400H
DDBD_24                                         equ     00000200H
DDBD_32                                         equ     00000100H

DDCKEY_COLORSPACE                               equ     00000001H
DDCKEY_DESTBLT                                  equ     00000002H
DDCKEY_DESTOVERLAY                              equ     00000004H
DDCKEY_SRCBLT                                   equ     00000008H
DDCKEY_SRCOVERLAY                               equ     00000010H

DDCKEYCAPS_DESTBLT                              equ     00000001H
DDCKEYCAPS_DESTBLTCLRSPACE                      equ     00000002H
DDCKEYCAPS_DESTBLTCLRSPACEYUV                   equ     00000004H
DDCKEYCAPS_DESTBLTYUV                           equ     00000008H
DDCKEYCAPS_DESTOVERLAY                          equ     00000010H
DDCKEYCAPS_DESTOVERLAYCLRSPACE                  equ     00000020H
DDCKEYCAPS_DESTOVERLAYCLRSPACEYUV               equ     00000040H
DDCKEYCAPS_DESTOVERLAYONEACTIVE                 equ     00000080H
DDCKEYCAPS_DESTOVERLAYYUV                       equ     00000100H
DDCKEYCAPS_SRCBLT                               equ     00000200H
DDCKEYCAPS_SRCBLTCLRSPACE                       equ     00000400H
DDCKEYCAPS_SRCBLTCLRSPACEYUV                    equ     00000800H
DDCKEYCAPS_SRCBLTYUV                            equ     00001000H
DDCKEYCAPS_SRCOVERLAY                           equ     00002000H
DDCKEYCAPS_SRCOVERLAYCLRSPACE                   equ     00004000H
DDCKEYCAPS_SRCOVERLAYCLRSPACEYUV                equ     00008000H
DDCKEYCAPS_SRCOVERLAYONEACTIVE                  equ     00010000H
DDCKEYCAPS_SRCOVERLAYYUV                        equ     00020000H
DDCKEYCAPS_NOCOSTOVERLAY                        equ     00040000H

DDPF_ALPHAPIXELS                                equ     00000001H
DDPF_ALPHA                                      equ     00000002H
DDPF_FOURCC                                     equ     00000004H
DDPF_PALETTEINDEXED4                            equ     00000008H
DDPF_PALETTEINDEXEDTO8                          equ     00000010H
DDPF_PALETTEINDEXED8                            equ     00000020H
DDPF_RGB                                        equ     00000040H
DDPF_COMPRESSED                                 equ     00000080H
DDPF_RGBTOYUV                                   equ     00000100H
DDPF_YUV                                        equ     00000200H
DDPF_ZBUFFER                                    equ     00000400H
DDPF_PALETTEINDEXED1                            equ     00000800H
DDPF_PALETTEINDEXED2                            equ     00001000H
DDPF_ZPIXELS                                    equ     00002000H
DDPF_STENCILBUFFER                              equ     00004000H
DDPF_ALPHAPREMULT                               equ     00008000H
DDPF_LUMINANCE                                  equ     00020000H
DDPF_BUMPLUMINANCE                              equ     00040000H
DDPF_BUMPDUDV                                   equ     00080000H

DDENUMSURFACES_ALL                              equ     00000001H
DDENUMSURFACES_MATCH                            equ     00000002H
DDENUMSURFACES_NOMATCH                          equ     00000004H
DDENUMSURFACES_CANBECREATED                     equ     00000008H
DDENUMSURFACES_DOESEXIST                        equ     00000010H

DDSDM_STANDARDVGAMODE                           equ     00000001H
DDEDM_REFRESHRATES                              equ     00000001H
DDEDM_STANDARDVGAMODES                          equ     00000002H

DDSCL_FULLSCREEN                                equ     00000001H
DDSCL_ALLOWREBOOT                               equ     00000002H
DDSCL_NOWINDOWCHANGES                           equ     00000004H
DDSCL_NORMAL                                    equ     00000008H
DDSCL_EXCLUSIVE                                 equ     00000010H
DDSCL_ALLOWMODEX                                equ     00000040H
DDSCL_SETFOCUSWINDOW                            equ     00000080H
DDSCL_SETDEVICEWINDOW                           equ     00000100H
DDSCL_CREATEDEVICEWINDOW                        equ     00000200H
DDSCL_MULTITHREADED                             equ     00000400H
DDSCL_FPUSETUP                                  equ     00000800H
DDSCL_FPUPRESERVE                               equ     00001000H

DDBLT_ALPHADEST                                 equ     00000001H
DDBLT_ALPHADESTCONSTOVERRIDE                    equ     00000002H
DDBLT_ALPHADESTNEG                              equ     00000004H
DDBLT_ALPHADESTSURFACEOVERRIDE                  equ     00000008H
DDBLT_ALPHAEDGEBLEND                            equ     00000010H
DDBLT_ALPHASRC                                  equ     00000020H
DDBLT_ALPHASRCCONSTOVERRIDE                     equ     00000040H
DDBLT_ALPHASRCNEG                               equ     00000080H
DDBLT_ALPHASRCSURFACEOVERRIDE                   equ     00000100H
DDBLT_ASYNC                                     equ     00000200H
DDBLT_COLORFILL                                 equ     00000400H
DDBLT_DDFX                                      equ     00000800H
DDBLT_DDROPS                                    equ     00001000H
DDBLT_KEYDEST                                   equ     00002000H
DDBLT_KEYDESTOVERRIDE                           equ     00004000H
DDBLT_KEYSRC                                    equ     00008000H
DDBLT_KEYSRCOVERRIDE                            equ     00010000H
DDBLT_ROP                                       equ     00020000H
DDBLT_ROTATIONANGLE                             equ     00040000H
DDBLT_ZBUFFER                                   equ     00080000H
DDBLT_ZBUFFERDESTCONSTOVERRIDE                  equ     00100000H
DDBLT_ZBUFFERDESTOVERRIDE                       equ     00200000H
DDBLT_ZBUFFERSRCCONSTOVERRIDE                   equ     00400000H
DDBLT_ZBUFFERSRCOVERRIDE                        equ     00800000H
DDBLT_WAIT                                      equ     01000000H
DDBLT_DEPTHFILL                                 equ     02000000H
DDBLT_DONOTWAIT                                 equ     08000000H

DDBLTFAST_NOCOLORKEY                            equ     00000000H
DDBLTFAST_SRCCOLORKEY                           equ     00000001H
DDBLTFAST_DESTCOLORKEY                          equ     00000002H
DDBLTFAST_WAIT                                  equ     00000010H
DDBLTFAST_DONOTWAIT                             equ     00000020H

DDFLIP_WAIT                                     equ     00000001H
DDFLIP_EVEN                                     equ     00000002H
DDFLIP_ODD                                      equ     00000004H
DDFLIP_NOVSYNC                                  equ     00000008H
DDFLIP_INTERVAL2                                equ     02000000H
DDFLIP_INTERVAL3                                equ     03000000H
DDFLIP_INTERVAL4                                equ     04000000H
DDFLIP_STEREO                                   equ     00000010H
DDFLIP_DONOTWAIT                                equ     00000020H

DDOVER_ALPHADEST                                equ     00000001H
DDOVER_ALPHADESTCONSTOVERRIDE                   equ     00000002H
DDOVER_ALPHADESTNEG                             equ     00000004H
DDOVER_ALPHADESTSURFACEOVERRIDE                 equ     00000008H
DDOVER_ALPHAEDGEBLEND                           equ     00000010H
DDOVER_ALPHASRC                                 equ     00000020H
DDOVER_ALPHASRCCONSTOVERRIDE                    equ     00000040H
DDOVER_ALPHASRCNEG                              equ     00000080H
DDOVER_ALPHASRCSURFACEOVERRIDE                  equ     00000100H
DDOVER_HIDE                                     equ     00000200H
DDOVER_KEYDEST                                  equ     00000400H
DDOVER_KEYDESTOVERRIDE                          equ     00000800H
DDOVER_KEYSRC                                   equ     00001000H
DDOVER_KEYSRCOVERRIDE                           equ     00002000H
DDOVER_SHOW                                     equ     00004000H
DDOVER_ADDDIRTYRECT                             equ     00008000H
DDOVER_REFRESHDIRTYRECTS                        equ     00010000H
DDOVER_REFRESHALL                               equ     00020000H
DDOVER_DDFX                                     equ     00080000H
DDOVER_AUTOFLIP                                 equ     00100000H
DDOVER_BOB                                      equ     00200000H
DDOVER_OVERRIDEBOBWEAVE                         equ     00400000H
DDOVER_INTERLEAVED                              equ     00800000H
DDOVER_BOBHARDWARE                              equ     01000000H
DDOVER_ARGBSCALEFACTORS                         equ     02000000H
DDOVER_DEGRADEARGBSCALING                       equ     04000000H

DDLOCK_SURFACEMEMORYPTR                         equ     00000000H
DDLOCK_WAIT                                     equ     00000001H
DDLOCK_EVENT                                    equ     00000002H
DDLOCK_READONLY                                 equ     00000010H
DDLOCK_WRITEONLY                                equ     00000020H
DDLOCK_NOSYSLOCK                                equ     00000800H
DDLOCK_NOOVERWRITE                              equ     00001000H
DDLOCK_DISCARDCONTENTS                          equ     00002000H
DDLOCK_OKTOSWAP                                 equ     00002000H
DDLOCK_DONOTWAIT                                equ     00004000H

DDBLTFX_ARITHSTRETCHY                           equ     00000001H
DDBLTFX_MIRRORLEFTRIGHT                         equ     00000002H
DDBLTFX_MIRRORUPDOWN                            equ     00000004H
DDBLTFX_NOTEARING                               equ     00000008H
DDBLTFX_ROTATE180                               equ     00000010H
DDBLTFX_ROTATE270                               equ     00000020H
DDBLTFX_ROTATE90                                equ     00000040H
DDBLTFX_ZBUFFERRANGE                            equ     00000080H
DDBLTFX_ZBUFFERBASEDEST                         equ     00000100H

DDOVERFX_ARITHSTRETCHY                          equ     00000001H
DDOVERFX_MIRRORLEFTRIGHT                        equ     00000002H
DDOVERFX_MIRRORUPDOWN                           equ     00000004H

DDWAITVB_BLOCKBEGIN                             equ     00000001H
DDWAITVB_BLOCKBEGINEVENT                        equ     00000002H
DDWAITVB_BLOCKEND                               equ     00000004H

DDGFS_CANFLIP                                   equ     00000001H
DDGFS_ISFLIPDONE                                equ     00000002H

DDGBS_CANBLT                                    equ     00000001H
DDGBS_ISBLTDONE                                 equ     00000002H

DDENUMOVERLAYZ_BACKTOFRONT                      equ     00000000H
DDENUMOVERLAYZ_FRONTTOBACK                      equ     00000001H

DDOVERZ_SENDTOFRONT                             equ     00000000H
DDOVERZ_SENDTOBACK                              equ     00000001H
DDOVERZ_MOVEFORWARD                             equ     00000002H
DDOVERZ_MOVEBACKWARD                            equ     00000003H
DDOVERZ_INSERTINFRONTOF                         equ     00000004H
DDOVERZ_INSERTINBACKOF                          equ     00000005H

DDSGR_CALIBRATE                                 equ     00000001H
DDSMT_ISTESTREQUIRED                            equ     00000001H

DDEM_MODEPASSED                                 equ     00000001H
DDEM_MODEFAILED                                 equ     00000002H

DD_OK                                           equ     0
DD_FALSE                                        equ     S_FALSE

DDENUMRET_CANCEL                                equ     0
DDENUMRET_OK                                    equ     1

DDERR_ALREADYINITIALIZED                        equ     (1 shl 31) + (0876H shl 16) + 5
DDERR_CANNOTATTACHSURFACE                       equ     (1 shl 31) + (0876H shl 16) + 10
DDERR_CANNOTDETACHSURFACE                       equ     (1 shl 31) + (0876H shl 16) + 20
DDERR_CURRENTLYNOTAVAIL                         equ     (1 shl 31) + (0876H shl 16) + 40
DDERR_EXCEPTION                                 equ     (1 shl 31) + (0876H shl 16) + 55
DDERR_GENERIC                                   equ     E_FAIL
DDERR_HEIGHTALIGN                               equ     (1 shl 31) + (0876H shl 16) + 90
DDERR_INCOMPATIBLEPRIMARY                       equ     (1 shl 31) + (0876H shl 16) + 95
DDERR_INVALIDCAPS                               equ     (1 shl 31) + (0876H shl 16) + 100
DDERR_INVALIDCLIPLIST                           equ     (1 shl 31) + (0876H shl 16) + 110
DDERR_INVALIDMODE                               equ     (1 shl 31) + (0876H shl 16) + 120
DDERR_INVALIDOBJECT                             equ     (1 shl 31) + (0876H shl 16) + 130
DDERR_INVALIDPARAMS                             equ     E_INVALIDARG
DDERR_INVALIDPIXELFORMAT                        equ     (1 shl 31) + (0876H shl 16) + 145
DDERR_INVALIDRECT                               equ     (1 shl 31) + (0876H shl 16) + 150
DDERR_LOCKEDSURFACES                            equ     (1 shl 31) + (0876H shl 16) + 160
DDERR_NO3D                                      equ     (1 shl 31) + (0876H shl 16) + 170
DDERR_NOALPHAHW                                 equ     (1 shl 31) + (0876H shl 16) + 180
DDERR_NOSTEREOHARDWARE                          equ     (1 shl 31) + (0876H shl 16) + 181
DDERR_NOSURFACELEFT                             equ     (1 shl 31) + (0876H shl 16) + 182
DDERR_NOCLIPLIST                                equ     (1 shl 31) + (0876H shl 16) + 205
DDERR_NOCOLORCONVHW                             equ     (1 shl 31) + (0876H shl 16) + 210
DDERR_NOCOOPERATIVELEVELSET                     equ     (1 shl 31) + (0876H shl 16) + 212
DDERR_NOCOLORKEY                                equ     (1 shl 31) + (0876H shl 16) + 215
DDERR_NOCOLORKEYHW                              equ     (1 shl 31) + (0876H shl 16) + 220
DDERR_NODIRECTDRAWSUPPORT                       equ     (1 shl 31) + (0876H shl 16) + 222
DDERR_NOEXCLUSIVEMODE                           equ     (1 shl 31) + (0876H shl 16) + 225
DDERR_NOFLIPHW                                  equ     (1 shl 31) + (0876H shl 16) + 230
DDERR_NOGDI                                     equ     (1 shl 31) + (0876H shl 16) + 240
DDERR_NOMIRRORHW                                equ     (1 shl 31) + (0876H shl 16) + 250
DDERR_NOTFOUND                                  equ     (1 shl 31) + (0876H shl 16) + 255
DDERR_NOOVERLAYHW                               equ     (1 shl 31) + (0876H shl 16) + 260
DDERR_OVERLAPPINGRECTS                          equ     (1 shl 31) + (0876H shl 16) + 270
DDERR_NORASTEROPHW                              equ     (1 shl 31) + (0876H shl 16) + 280
DDERR_NOROTATIONHW                              equ     (1 shl 31) + (0876H shl 16) + 290
DDERR_NOSTRETCHHW                               equ     (1 shl 31) + (0876H shl 16) + 310
DDERR_NOT4BITCOLOR                              equ     (1 shl 31) + (0876H shl 16) + 316
DDERR_NOT4BITCOLORINDEX                         equ     (1 shl 31) + (0876H shl 16) + 317
DDERR_NOT8BITCOLOR                              equ     (1 shl 31) + (0876H shl 16) + 320
DDERR_NOTEXTUREHW                               equ     (1 shl 31) + (0876H shl 16) + 330
DDERR_NOVSYNCHW                                 equ     (1 shl 31) + (0876H shl 16) + 335
DDERR_NOZBUFFERHW                               equ     (1 shl 31) + (0876H shl 16) + 340
DDERR_NOZOVERLAYHW                              equ     (1 shl 31) + (0876H shl 16) + 350
DDERR_OUTOFCAPS                                 equ     (1 shl 31) + (0876H shl 16) + 360
DDERR_OUTOFMEMORY                               equ     E_OUTOFMEMORY
DDERR_OUTOFVIDEOMEMORY                          equ     (1 shl 31) + (0876H shl 16) + 380
DDERR_OVERLAYCANTCLIP                           equ     (1 shl 31) + (0876H shl 16) + 382
DDERR_OVERLAYCOLORKEYONLYONEACTIVE              equ     (1 shl 31) + (0876H shl 16) + 384
DDERR_PALETTEBUSY                               equ     (1 shl 31) + (0876H shl 16) + 387
DDERR_COLORKEYNOTSET                            equ     (1 shl 31) + (0876H shl 16) + 400
DDERR_SURFACEALREADYATTACHED                    equ     (1 shl 31) + (0876H shl 16) + 410
DDERR_SURFACEALREADYDEPENDENT                   equ     (1 shl 31) + (0876H shl 16) + 420
DDERR_SURFACEBUSY                               equ     (1 shl 31) + (0876H shl 16) + 430
DDERR_CANTLOCKSURFACE                           equ     (1 shl 31) + (0876H shl 16) + 435
DDERR_SURFACEISOBSCURED                         equ     (1 shl 31) + (0876H shl 16) + 440
DDERR_SURFACELOST                               equ     (1 shl 31) + (0876H shl 16) + 450
DDERR_SURFACENOTATTACHED                        equ     (1 shl 31) + (0876H shl 16) + 460
DDERR_TOOBIGHEIGHT                              equ     (1 shl 31) + (0876H shl 16) + 470
DDERR_TOOBIGSIZE                                equ     (1 shl 31) + (0876H shl 16) + 480
DDERR_TOOBIGWIDTH                               equ     (1 shl 31) + (0876H shl 16) + 490
DDERR_UNSUPPORTED                               equ     (1 shl 31) + (0876H shl 16) + E_NOTIMPL
DDERR_UNSUPPORTEDFORMAT                         equ     (1 shl 31) + (0876H shl 16) + 510
DDERR_UNSUPPORTEDMASK                           equ     (1 shl 31) + (0876H shl 16) + 520
DDERR_INVALIDSTREAM                             equ     (1 shl 31) + (0876H shl 16) + 521
DDERR_VERTICALBLANKINPROGRESS                   equ     (1 shl 31) + (0876H shl 16) + 537
DDERR_WASSTILLDRAWING                           equ     (1 shl 31) + (0876H shl 16) + 540
DDERR_DDSCAPSCOMPLEXREQUIRED                    equ     (1 shl 31) + (0876H shl 16) + 542
DDERR_XALIGN                                    equ     (1 shl 31) + (0876H shl 16) + 560
DDERR_INVALIDDIRECTDRAWGUID                     equ     (1 shl 31) + (0876H shl 16) + 561
DDERR_DIRECTDRAWALREADYCREATED                  equ     (1 shl 31) + (0876H shl 16) + 562
DDERR_NODIRECTDRAWHW                            equ     (1 shl 31) + (0876H shl 16) + 563
DDERR_PRIMARYSURFACEALREADYEXISTS               equ     (1 shl 31) + (0876H shl 16) + 564
DDERR_NOEMULATION                               equ     (1 shl 31) + (0876H shl 16) + 565
DDERR_REGIONTOOSMALL                            equ     (1 shl 31) + (0876H shl 16) + 566
DDERR_CLIPPERISUSINGHWND                        equ     (1 shl 31) + (0876H shl 16) + 567
DDERR_NOCLIPPERATTACHED                         equ     (1 shl 31) + (0876H shl 16) + 568
DDERR_NOHWND                                    equ     (1 shl 31) + (0876H shl 16) + 569
DDERR_HWNDSUBCLASSED                            equ     (1 shl 31) + (0876H shl 16) + 570
DDERR_HWNDALREADYSET                            equ     (1 shl 31) + (0876H shl 16) + 571
DDERR_NOPALETTEATTACHED                         equ     (1 shl 31) + (0876H shl 16) + 572
DDERR_NOPALETTEHW                               equ     (1 shl 31) + (0876H shl 16) + 573
DDERR_BLTFASTCANTCLIP                           equ     (1 shl 31) + (0876H shl 16) + 574
DDERR_NOBLTHW                                   equ     (1 shl 31) + (0876H shl 16) + 575
DDERR_NODDROPSHW                                equ     (1 shl 31) + (0876H shl 16) + 576
DDERR_OVERLAYNOTVISIBLE                         equ     (1 shl 31) + (0876H shl 16) + 577
DDERR_NOOVERLAYDEST                             equ     (1 shl 31) + (0876H shl 16) + 578
DDERR_INVALIDPOSITION                           equ     (1 shl 31) + (0876H shl 16) + 579
DDERR_NOTAOVERLAYSURFACE                        equ     (1 shl 31) + (0876H shl 16) + 580
DDERR_EXCLUSIVEMODEALREADYSET                   equ     (1 shl 31) + (0876H shl 16) + 581
DDERR_NOTFLIPPABLE                              equ     (1 shl 31) + (0876H shl 16) + 582
DDERR_CANTDUPLICATE                             equ     (1 shl 31) + (0876H shl 16) + 583
DDERR_NOTLOCKED                                 equ     (1 shl 31) + (0876H shl 16) + 584
DDERR_CANTCREATEDC                              equ     (1 shl 31) + (0876H shl 16) + 585
DDERR_NODC                                      equ     (1 shl 31) + (0876H shl 16) + 586
DDERR_WRONGMODE                                 equ     (1 shl 31) + (0876H shl 16) + 587
DDERR_IMPLICITLYCREATED                         equ     (1 shl 31) + (0876H shl 16) + 588
DDERR_NOTPALETTIZED                             equ     (1 shl 31) + (0876H shl 16) + 589
DDERR_UNSUPPORTEDMODE                           equ     (1 shl 31) + (0876H shl 16) + 590
DDERR_NOMIPMAPHW                                equ     (1 shl 31) + (0876H shl 16) + 591
DDERR_INVALIDSURFACETYPE                        equ     (1 shl 31) + (0876H shl 16) + 592
DDERR_NOOPTIMIZEHW                              equ     (1 shl 31) + (0876H shl 16) + 600
DDERR_NOTLOADED                                 equ     (1 shl 31) + (0876H shl 16) + 601
DDERR_NOFOCUSWINDOW                             equ     (1 shl 31) + (0876H shl 16) + 602
DDERR_NOTONMIPMAPSUBLEVEL                       equ     (1 shl 31) + (0876H shl 16) + 603
DDERR_DCALREADYCREATED                          equ     (1 shl 31) + (0876H shl 16) + 620
DDERR_NONONLOCALVIDMEM                          equ     (1 shl 31) + (0876H shl 16) + 630
DDERR_CANTPAGELOCK                              equ     (1 shl 31) + (0876H shl 16) + 640
DDERR_CANTPAGEUNLOCK                            equ     (1 shl 31) + (0876H shl 16) + 660
DDERR_NOTPAGELOCKED                             equ     (1 shl 31) + (0876H shl 16) + 680
DDERR_MOREDATA                                  equ     (1 shl 31) + (0876H shl 16) + 690
DDERR_EXPIRED                                   equ     (1 shl 31) + (0876H shl 16) + 691
DDERR_TESTFINISHED                              equ     (1 shl 31) + (0876H shl 16) + 692
DDERR_NEWMODE                                   equ     (1 shl 31) + (0876H shl 16) + 693
DDERR_D3DNOTINITIALIZED                         equ     (1 shl 31) + (0876H shl 16) + 694
DDERR_VIDEONOTACTIVE                            equ     (1 shl 31) + (0876H shl 16) + 695
DDERR_NOMONITORINFORMATION                      equ     (1 shl 31) + (0876H shl 16) + 696
DDERR_NODRIVERSUPPORT                           equ     (1 shl 31) + (0876H shl 16) + 697
DDERR_DEVICEDOESNTOWNSURFACE                    equ     (1 shl 31) + (0876H shl 16) + 699
DDERR_NOTINITIALIZED                            equ     CO_E_NOTINITIALIZED

;======================================== Structures ======================================;
struct DDARGB
    blue    db ?
    green   db ?
    red     db ?
    alpha   db ?
ends

struct DDRGBA
    red     db ?
    green   db ?
    blue    db ?
    alpha   db ?
ends

struct DDCOLORKEY
    dwColorSpaceLowValue  dd ?
    dwColorSpaceHighValue dd ?
ends

struct DDBLTFX
    dwSize                   dd   ?
    dwDDFX                   dd   ?
    dwROP                    dd   ?
    dwDDROP                  dd   ?
    dwRotationAngle          dd   ?
    dwZBufferOpCode          dd   ?
    dwZBufferLow             dd   ?
    dwZBufferHigh            dd   ?
    dwZBufferBaseDest        dd   ?
    dwZDestConstBitDepth     dd   ?
    union
        dwZDestConst         dd   ?
        lpDDSZBufferDest     xptr ?
    ends
    dwZSrcConstBitDepth      dd  ?
    union
        dwZSrcConst          dd   ?
        lpDDSZBufferSrc      xptr ?
    ends
    dwAlphaEdgeBlendBitDepth dd   ?
    dwAlphaEdgeBlend         dd   ?
    dwReserved               dd   ?
    dwAlphaDestConstBitDepth dd   ?
    union
        dwAlphaDestConst     dd   ?
        lpDDSAlphaDest       xptr ?
    ends
    dwAlphaSrcConstBitDepth  dd   ?
    union
        dwAlphaSrcConst      dd   ?
        lpDDSAlphaSrc        xptr ?
    ends
    union
        dwFillColor          dd   ?
        dwFillDepth          dd   ?
        dwFillPixel          dd   ?
        lpDDSPattern         xptr ?
    ends
    ddckDestColorkey         DDCOLORKEY
    ddckSrcColorkey          DDCOLORKEY
ends

struct DDSCAPS
    dwCaps dd ?
ends

struct DDOSCAPS
    dwCaps dd ?
ends

struct DDSCAPSEX
    dwCaps2 dd ?
    dwCaps3 dd ?
    dwCaps4 dd ?
ends

struct DDSCAPS2
    dwCaps  dd ?
    dwCaps2 dd ?
    dwCaps3 dd ?
    dwCaps4 dd ?
ends

struct DDCAPS_DX1
    dwSize                          dd ?
    dwCaps                          dd ?
    dwCaps2                         dd ?
    dwCKeyCaps                      dd ?
    dwFXCaps                        dd ?
    dwFXAlphaCaps                   dd ?
    dwPalCaps                       dd ?
    dwSVCaps                        dd ?
    dwAlphaBltConstBitDepths        dd ?
    dwAlphaBltPixelBitDepths        dd ?
    dwAlphaBltSurfaceBitDepths      dd ?
    dwAlphaOverlayConstBitDepths    dd ?
    dwAlphaOverlayPixelBitDepths    dd ?
    dwAlphaOverlaySurfaceBitDepths  dd ?
    dwZBufferBitDepths              dd ?
    dwVidMemTotal                   dd ?
    dwVidMemFree                    dd ?
    dwMaxVisibleOverlays            dd ?
    dwCurrVisibleOverlays           dd ?
    dwNumFourCCCodes                dd ?
    dwAlignBoundarySrc              dd ?
    dwAlignSizeSrc                  dd ?
    dwAlignBoundaryDest             dd ?
    dwAlignSizeDest                 dd ?
    dwAlignStrideAlign              dd ?
    dwRops                          dd DD_ROP_SPACE dup(?)
    ddsCaps                         DDSCAPS
    dwMinOverlayStretch             dd ?
    dwMaxOverlayStretch             dd ?
    dwMinLiveVideoStretch           dd ?
    dwMaxLiveVideoStretch           dd ?
    dwMinHwCodecStretch             dd ?
    dwMaxHwCodecStretch             dd ?
    dwReserved1                     dd ?
    dwReserved2                     dd ?
    dwReserved3                     dd ?
ends

struct DDCAPS_DX3
    dwSize                          dd ?
    dwCaps                          dd ?
    dwCaps2                         dd ?
    dwCKeyCaps                      dd ?
    dwFXCaps                        dd ?
    dwFXAlphaCaps                   dd ?
    dwPalCaps                       dd ?
    dwSVCaps                        dd ?
    dwAlphaBltConstBitDepths        dd ?
    dwAlphaBltPixelBitDepths        dd ?
    dwAlphaBltSurfaceBitDepths      dd ?
    dwAlphaOverlayConstBitDepths    dd ?
    dwAlphaOverlayPixelBitDepths    dd ?
    dwAlphaOverlaySurfaceBitDepths  dd ?
    dwZBufferBitDepths              dd ?
    dwVidMemTotal                   dd ?
    dwVidMemFree                    dd ?
    dwMaxVisibleOverlays            dd ?
    dwCurrVisibleOverlays           dd ?
    dwNumFourCCCodes                dd ?
    dwAlignBoundarySrc              dd ?
    dwAlignSizeSrc                  dd ?
    dwAlignBoundaryDest             dd ?
    dwAlignSizeDest                 dd ?
    dwAlignStrideAlign              dd ?
    dwRops                          dd DD_ROP_SPACE dup(?)
    ddsCaps                         DDSCAPS
    dwMinOverlayStretch             dd ?
    dwMaxOverlayStretch             dd ?
    dwMinLiveVideoStretch           dd ?
    dwMaxLiveVideoStretch           dd ?
    dwMinHwCodecStretch             dd ?
    dwMaxHwCodecStretch             dd ?
    dwReserved1                     dd ?
    dwReserved2                     dd ?
    dwReserved3                     dd ?
    dwSVBCaps                       dd ?
    dwSVBCKeyCaps                   dd ?
    dwSVBFXCaps                     dd ?
    dwSVBRops                       dd DD_ROP_SPACE dup(?)
    dwVSBCaps                       dd ?
    dwVSBCKeyCaps                   dd ?
    dwVSBFXCaps                     dd ?
    dwVSBRops                       dd DD_ROP_SPACE dup(?)
    dwSSBCaps                       dd ?
    dwSSBCKeyCaps                   dd ?
    dwSSBFXCaps                     dd ?
    dwSSBRops                       dd DD_ROP_SPACE dup(?)
    dwReserved4                     dd ?
    dwReserved5                     dd ?
    dwReserved6                     dd ?
ends

struct DDCAPS_DX5
    dwSize                          dd ?
    dwCaps                          dd ?
    dwCaps2                         dd ?
    dwCKeyCaps                      dd ?
    dwFXCaps                        dd ?
    dwFXAlphaCaps                   dd ?
    dwPalCaps                       dd ?
    dwSVCaps                        dd ?
    dwAlphaBltConstBitDepths        dd ?
    dwAlphaBltPixelBitDepths        dd ?
    dwAlphaBltSurfaceBitDepths      dd ?
    dwAlphaOverlayConstBitDepths    dd ?
    dwAlphaOverlayPixelBitDepths    dd ?
    dwAlphaOverlaySurfaceBitDepths  dd ?
    dwZBufferBitDepths              dd ?
    dwVidMemTotal                   dd ?
    dwVidMemFree                    dd ?
    dwMaxVisibleOverlays            dd ?
    dwCurrVisibleOverlays           dd ?
    dwNumFourCCCodes                dd ?
    dwAlignBoundarySrc              dd ?
    dwAlignSizeSrc                  dd ?
    dwAlignBoundaryDest             dd ?
    dwAlignSizeDest                 dd ?
    dwAlignStrideAlign              dd ?
    dwRops                          dd DD_ROP_SPACE dup(?)
    ddsCaps                         DDSCAPS
    dwMinOverlayStretch             dd ?
    dwMaxOverlayStretch             dd ?
    dwMinLiveVideoStretch           dd ?
    dwMaxLiveVideoStretch           dd ?
    dwMinHwCodecStretch             dd ?
    dwMaxHwCodecStretch             dd ?
    dwReserved1                     dd ?
    dwReserved2                     dd ?
    dwReserved3                     dd ?
    dwSVBCaps                       dd ?
    dwSVBCKeyCaps                   dd ?
    dwSVBFXCaps                     dd ?
    dwSVBRops                       dd DD_ROP_SPACE dup(?)
    dwVSBCaps                       dd ?
    dwVSBCKeyCaps                   dd ?
    dwVSBFXCaps                     dd ?
    dwVSBRops                       dd DD_ROP_SPACE dup(?)
    dwSSBCaps                       dd ?
    dwSSBCKeyCaps                   dd ?
    dwSSBFXCaps                     dd ?
    dwSSBRops                       dd DD_ROP_SPACE dup(?)
    dwMaxVideoPorts                 dd ?
    dwCurrVideoPorts                dd ?
    dwSVBCaps2                      dd ?
    dwNLVBCaps                      dd ?
    dwNLVBCaps2                     dd ?
    dwNLVBCKeyCaps                  dd ?
    dwNLVBFXCaps                    dd ?
    dwNLVBRops                      dd DD_ROP_SPACE dup(?)
ends

struct DDCAPS_DX6
    dwSize                          dd ?
    dwCaps                          dd ?
    dwCaps2                         dd ?
    dwCKeyCaps                      dd ?
    dwFXCaps                        dd ?
    dwFXAlphaCaps                   dd ?
    dwPalCaps                       dd ?
    dwSVCaps                        dd ?
    dwAlphaBltConstBitDepths        dd ?
    dwAlphaBltPixelBitDepths        dd ?
    dwAlphaBltSurfaceBitDepths      dd ?
    dwAlphaOverlayConstBitDepths    dd ?
    dwAlphaOverlayPixelBitDepths    dd ?
    dwAlphaOverlaySurfaceBitDepths  dd ?
    dwZBufferBitDepths              dd ?
    dwVidMemTotal                   dd ?
    dwVidMemFree                    dd ?
    dwMaxVisibleOverlays            dd ?
    dwCurrVisibleOverlays           dd ?
    dwNumFourCCCodes                dd ?
    dwAlignBoundarySrc              dd ?
    dwAlignSizeSrc                  dd ?
    dwAlignBoundaryDest             dd ?
    dwAlignSizeDest                 dd ?
    dwAlignStrideAlign              dd ?
    dwRops                          dd DD_ROP_SPACE dup(?)
    ddsOldCaps                      DDSCAPS
    dwMinOverlayStretch             dd ?
    dwMaxOverlayStretch             dd ?
    dwMinLiveVideoStretch           dd ?
    dwMaxLiveVideoStretch           dd ?
    dwMinHwCodecStretch             dd ?
    dwMaxHwCodecStretch             dd ?
    dwReserved1                     dd ?
    dwReserved2                     dd ?
    dwReserved3                     dd ?
    dwSVBCaps                       dd ?
    dwSVBCKeyCaps                   dd ?
    dwSVBFXCaps                     dd ?
    dwSVBRops                       dd DD_ROP_SPACE dup(?)
    dwVSBCaps                       dd ?
    dwVSBCKeyCaps                   dd ?
    dwVSBFXCaps                     dd ?
    dwVSBRops                       dd DD_ROP_SPACE dup(?)
    dwSSBCaps                       dd ?
    dwSSBCKeyCaps                   dd ?
    dwSSBFXCaps                     dd ?
    dwSSBRops                       dd DD_ROP_SPACE dup(?)
    dwMaxVideoPorts                 dd ?
    dwCurrVideoPorts                dd ?
    dwSVBCaps2                      dd ?
    dwNLVBCaps                      dd ?
    dwNLVBCaps2                     dd ?
    dwNLVBCKeyCaps                  dd ?
    dwNLVBFXCaps                    dd ?
    dwNLVBRops                      dd DD_ROP_SPACE dup(?)
    ddsCaps                         DDSCAPS2
ends

struct DDCAPS_DX7
    dwSize                          dd ?
    dwCaps                          dd ?
    dwCaps2                         dd ?
    dwCKeyCaps                      dd ?
    dwFXCaps                        dd ?
    dwFXAlphaCaps                   dd ?
    dwPalCaps                       dd ?
    dwSVCaps                        dd ?
    dwAlphaBltConstBitDepths        dd ?
    dwAlphaBltPixelBitDepths        dd ?
    dwAlphaBltSurfaceBitDepths      dd ?
    dwAlphaOverlayConstBitDepths    dd ?
    dwAlphaOverlayPixelBitDepths    dd ?
    dwAlphaOverlaySurfaceBitDepths  dd ?
    dwZBufferBitDepths              dd ?
    dwVidMemTotal                   dd ?
    dwVidMemFree                    dd ?
    dwMaxVisibleOverlays            dd ?
    dwCurrVisibleOverlays           dd ?
    dwNumFourCCCodes                dd ?
    dwAlignBoundarySrc              dd ?
    dwAlignSizeSrc                  dd ?
    dwAlignBoundaryDest             dd ?
    dwAlignSizeDest                 dd ?
    dwAlignStrideAlign              dd ?
    dwRops                          dd DD_ROP_SPACE dup(?)
    ddsOldCaps                      DDSCAPS
    dwMinOverlayStretch             dd ?
    dwMaxOverlayStretch             dd ?
    dwMinLiveVideoStretch           dd ?
    dwMaxLiveVideoStretch           dd ?
    dwMinHwCodecStretch             dd ?
    dwMaxHwCodecStretch             dd ?
    dwReserved1                     dd ?
    dwReserved2                     dd ?
    dwReserved3                     dd ?
    dwSVBCaps                       dd ?
    dwSVBCKeyCaps                   dd ?
    dwSVBFXCaps                     dd ?
    dwSVBRops                       dd DD_ROP_SPACE dup(?)
    dwVSBCaps                       dd ?
    dwVSBCKeyCaps                   dd ?
    dwVSBFXCaps                     dd ?
    dwVSBRops                       dd DD_ROP_SPACE dup(?)
    dwSSBCaps                       dd ?
    dwSSBCKeyCaps                   dd ?
    dwSSBFXCaps                     dd ?
    dwSSBRops                       dd DD_ROP_SPACE dup(?)
    dwMaxVideoPorts                 dd ?
    dwCurrVideoPorts                dd ?
    dwSVBCaps2                      dd ?
    dwNLVBCaps                      dd ?
    dwNLVBCaps2                     dd ?
    dwNLVBCKeyCaps                  dd ?
    dwNLVBFXCaps                    dd ?
    dwNLVBRops                      dd DD_ROP_SPACE dup(?)
    ddsCaps                         DDSCAPS2
ends

if (DIRECTDRAW_VERSION <= 0300H)
    DDCAPS  equ DDCAPS_DX3
else if (DIRECTDRAW_VERSION <= 0500H)
    DDCAPS  equ DDCAPS_DX5
else if (DIRECTDRAW_VERSION <= 0600H)
    DDCAPS  equ DDCAPS_DX6
else
    DDCAPS  equ DDCAPS_DX7
end if

struct DDPIXELFORMAT
    dwSize                      dd ?
    dwFlags                     dd ?
    dwFourCC                    dd ?
    union
        dwRGBBitCount           dd ?
        dwYUVBitCount           dd ?
        dwZBufferBitDepth       dd ?
        dwAlphaBitDepth         dd ?
        dwLuminanceBitCount     dd ?
        dwBumpBitCount          dd ?
    ends
    union
        dwRBitMask              dd ?
        dwYBitMask              dd ?
        dwStencilBitDepth       dd ?
        dwLuminanceBitMask      dd ?
        dwBumpDuBitMask         dd ?
    ends
    union
        dwGBitMask              dd ?
        dwUBitMask              dd ?
        dwZBitMask              dd ?
        dwBumpDvBitMask         dd ?
    ends
    union
        dwBBitMask              dd ?
        dwVBitMask              dd ?
        dwStencilBitMask        dd ?
        dwBumpLuminanceBitMask  dd ?
    ends
    union
        dwRGBAlphaBitMask       dd ?
        dwYUVAlphaBitMask       dd ?
        dwLuminanceAlphaBitMask dd ?
        dwRGBZBitMask           dd ?
        dwYUVZBitMask           dd ?
    ends
ends

struct DDOVERLAYFX
    dwSize                      dd   ?
    dwAlphaEdgeBlendBitDepth    dd   ?
    dwAlphaEdgeBlend            dd   ?
    dwReserved                  dd   ?
    dwAlphaDestConstBitDepth    dd   ?
    union
        dwAlphaDestConst        dd   ?
        lpDDSAlphaDest          xptr ?
    ends
    dwAlphaSrcConstBitDepth     dd   ?
    union
        dwAlphaSrcConst         dd   ?
        lpDDSAlphaSrc           xptr   ?
    ends
    dckDestColorkey             DDCOLORKEY
    dckSrcColorkey              DDCOLORKEY
    dwDDFX                      dd   ?
    dwFlags                     dd   ?
ends

struct DDBLTBATCH
    lprDest     xptr ?
    lpDDSSrc    xptr ?
    lprSrc      xptr ?
    dwFlags     dd   ?
    lpDDBltFx   xptr ?
ends

struct DDGAMMARAMP
    red     dw 256 dup(?)
    green   dw 256 dup(?)
    blue    dw 256 dup(?)
ends

struct DDDEVICEIDENTIFIER
    szDriver             db MAX_DDDEVICEID_STRING dup(?)
    szDescription        db MAX_DDDEVICEID_STRING dup(?)
    liDriverVersion      dq   ?
    dwVendorId           dd   ?
    dwDeviceId           dd   ?
    dwSubSysId           dd   ?
    dwRevision           dd   ?
    guidDeviceIdentifier GUID
ends

struct DDDEVICEIDENTIFIER2
    szDriver             db MAX_DDDEVICEID_STRING dup(?)
    szDescription        db MAX_DDDEVICEID_STRING dup(?)
    liDriverVersion      dq   ?
    dwVendorId           dd   ?
    dwDeviceId           dd   ?
    dwSubSysId           dd   ?
    dwRevision           dd   ?
    guidDeviceIdentifier GUID
    dwWHQLLevel          dd   ?
ends

interface IDirectDraw,\
    QueryInterface,\
    AddRef,\
    Release,\
    Compact,\
    CreateClipper,\
    CreatePalette,\
    CreateSurface,\
    DuplicateSurface,\
    EnumDisplayModes,\
    EnumSurfaces,\
    FlipToGDISurface,\
    GetCaps,\
    GetDisplayMode,\
    GetFourCCCodes,\
    GetGDISurface,\
    GetMonitorFrequency,\
    GetScanLine,\
    GetVerticalBlankStatus,\
    Initialize,\
    RestoreDisplayMode,\
    SetCooperativeLevel,\
    SetDisplayMode,\
    WaitForVerticalBlank

interface IDirectDraw2,\
    QueryInterface,\
    AddRef,\
    Release,\
    Compact,\
    CreateClipper,\
    CreatePalette,\
    CreateSurface,\
    DuplicateSurface,\
    EnumDisplayModes,\
    EnumSurfaces,\
    FlipToGDISurface,\
    GetCaps,\
    GetDisplayMode,\
    GetFourCCCodes,\
    GetGDISurface,\
    GetMonitorFrequency,\
    GetScanLine,\
    GetVerticalBlankStatus,\
    Initialize,\
    RestoreDisplayMode,\
    SetCooperativeLevel,\
    SetDisplayMode,\
    WaitForVerticalBlank,\
    GetAvailableVidMem

interface IDirectDraw4,\
    QueryInterface,\
    AddRef,\
    Release,\
    Compact,\
    CreateClipper,\
    CreatePalette,\
    CreateSurface,\
    DuplicateSurface,\
    EnumDisplayModes,\
    EnumSurfaces,\
    FlipToGDISurface,\
    GetCaps,\
    GetDisplayMode,\
    GetFourCCCodes,\
    GetGDISurface,\
    GetMonitorFrequency,\
    GetScanLine,\
    GetVerticalBlankStatus,\
    Initialize,\
    RestoreDisplayMode,\
    SetCooperativeLevel,\
    SetDisplayMode,\
    WaitForVerticalBlank,\
    GetAvailableVidMem,\
    GetSurfaceFromDC,\
    RestoreAllSurfaces,\
    TestCooperativeLevel,\
    GetDeviceIdentifier

interface IDirectDraw7,\
    QueryInterface,\
    AddRef,\
    Release,\
    Compact,\
    CreateClipper,\
    CreatePalette,\
    CreateSurface,\
    DuplicateSurface,\
    EnumDisplayModes,\
    EnumSurfaces,\
    FlipToGDISurface,\
    GetCaps,\
    GetDisplayMode,\
    GetFourCCCodes,\
    GetGDISurface,\
    GetMonitorFrequency,\
    GetScanLine,\
    GetVerticalBlankStatus,\
    Initialize,\
    RestoreDisplayMode,\
    SetCooperativeLevel,\
    SetDisplayMode,\
    WaitForVerticalBlank,\
    GetAvailableVidMem,\
    GetSurfaceFromDC,\
    RestoreAllSurfaces,\
    TestCooperativeLevel,\
    GetDeviceIdentifier,\
    StartModeTest,\
    EvaluateMode

interface IDirectDrawPalette,\
    QueryInterface,\
    AddRef,\
    Release,\
    GetCaps,\
    GetEntries,\
    Initialize,\
    SetEntries

interface IDirectDrawClipper,\
    QueryInterface,\
    AddRef,\
    Release,\
    GetClipList,\
    GetHWnd,\
    Initialize,\
    IsClipListChanged,\
    SetClipList,\
    SetHWnd

interface IDirectDrawSurface,\
    QueryInterface,\
    AddRef,\
    Release,\
    AddAttachedSurface,\
    AddOverlayDirtyRect,\
    Blt,\
    BltBatch,\
    BltFast,\
    DeleteAttachedSurface,\
    EnumAttachedSurfaces,\
    EnumOverlayZOrders,\
    Flip,\
    GetAttachedSurface,\
    GetBltStatus,\
    GetCaps,\
    GetClipper,\
    GetColorKey,\
    GetDC,\
    GetFlipStatus,\
    GetOverlayPosition,\
    GetPalette,\
    GetPixelFormat,\
    GetSurfaceDesc,\
    Initialize,\
    IsLost,\
    Lock,\
    ReleaseDC,\
    Restore,\
    SetClipper,\
    SetColorKey,\
    SetOverlayPosition,\
    SetPalette,\
    Unlock,\
    UpdateOverlay,\
    UpdateOverlayDisplay,\
    UpdateOverlayZOrder

interface IDirectDrawSurface2,\
    QueryInterface,\
    AddRef,\
    Release,\
    AddAttachedSurface,\
    AddOverlayDirtyRect,\
    Blt,\
    BltBatch,\
    BltFast,\
    DeleteAttachedSurface,\
    EnumAttachedSurfaces,\
    EnumOverlayZOrders,\
    Flip,\
    GetAttachedSurface,\
    GetBltStatus,\
    GetCaps,\
    GetClipper,\
    GetColorKey,\
    GetDC,\
    GetFlipStatus,\
    GetOverlayPosition,\
    GetPalette,\
    GetPixelFormat,\
    GetSurfaceDesc,\
    Initialize,\
    IsLost,\
    Lock,\
    ReleaseDC,\
    Restore,\
    SetClipper,\
    SetColorKey,\
    SetOverlayPosition,\
    SetPalette,\
    Unlock,\
    UpdateOverlay,\
    UpdateOverlayDisplay,\
    UpdateOverlayZOrder,\
    GetDDInterface,\
    PageLock,\
    PageUnlock

interface IDirectDrawSurface3,\
    QueryInterface,\
    AddRef,\
    Release,\
    AddAttachedSurface,\
    AddOverlayDirtyRect,\
    Blt,\
    BltBatch,\
    BltFast,\
    DeleteAttachedSurface,\
    EnumAttachedSurfaces,\
    EnumOverlayZOrders,\
    Flip,\
    GetAttachedSurface,\
    GetBltStatus,\
    GetCaps,\
    GetClipper,\
    GetColorKey,\
    GetDC,\
    GetFlipStatus,\
    GetOverlayPosition,\
    GetPalette,\
    GetPixelFormat,\
    GetSurfaceDesc,\
    Initialize,\
    IsLost,\
    Lock,\
    ReleaseDC,\
    Restore,\
    SetClipper,\
    SetColorKey,\
    SetOverlayPosition,\
    SetPalette,\
    Unlock,\
    UpdateOverlay,\
    UpdateOverlayDisplay,\
    UpdateOverlayZOrder,\
    GetDDInterface,\
    PageLock,\
    PageUnlock,\
    SetSurfaceDesc

interface IDirectDrawSurface4,\
    QueryInterface,\
    AddRef,\
    Release,\
    AddAttachedSurface,\
    AddOverlayDirtyRect,\
    Blt,\
    BltBatch,\
    BltFast,\
    DeleteAttachedSurface,\
    EnumAttachedSurfaces,\
    EnumOverlayZOrders,\
    Flip,\
    GetAttachedSurface,\
    GetBltStatus,\
    GetCaps,\
    GetClipper,\
    GetColorKey,\
    GetDC,\
    GetFlipStatus,\
    GetOverlayPosition,\
    GetPalette,\
    GetPixelFormat,\
    GetSurfaceDesc,\
    Initialize,\
    IsLost,\
    Lock,\
    ReleaseDC,\
    Restore,\
    SetClipper,\
    SetColorKey,\
    SetOverlayPosition,\
    SetPalette,\
    Unlock,\
    UpdateOverlay,\
    UpdateOverlayDisplay,\
    UpdateOverlayZOrder,\
    GetDDInterface,\
    PageLock,\
    PageUnlock,\
    SetSurfaceDesc,\
    SetPrivateData,\
    GetPrivateData,\
    FreePrivateData,\
    GetUniquenessValue,\
    ChangeUniquenessValue

interface IDirectDrawSurface7,\
    QueryInterface,\
    AddRef,\
    Release,\
    AddAttachedSurface,\
    AddOverlayDirtyRect,\
    Blt,\
    BltBatch,\
    BltFast,\
    DeleteAttachedSurface,\
    EnumAttachedSurfaces,\
    EnumOverlayZOrders,\
    Flip,\
    GetAttachedSurface,\
    GetBltStatus,\
    GetCaps,\
    GetClipper,\
    GetColorKey,\
    GetDC,\
    GetFlipStatus,\
    GetOverlayPosition,\
    GetPalette,\
    GetPixelFormat,\
    GetSurfaceDesc,\
    Initialize,\
    IsLost,\
    Lock,\
    ReleaseDC,\
    Restore,\
    SetClipper,\
    SetColorKey,\
    SetOverlayPosition,\
    SetPalette,\
    Unlock,\
    UpdateOverlay,\
    UpdateOverlayDisplay,\
    UpdateOverlayZOrder,\
    GetDDInterface,\
    PageLock,\
    PageUnlock,\
    SetSurfaceDesc,\
    SetPrivateData,\
    GetPrivateData,\
    FreePrivateData,\
    GetUniquenessValue,\
    ChangeUniquenessValue,\
    SetPriority,\
    GetPriority,\
    SetLOD,\
    GetLOD

interface IDirectDrawColorControl,\
    QueryInterface,\
    AddRef,\
    Release,\
    GetColorControls,\
    SetColorControls

interface IDirectDrawGammaControl,\
    QueryInterface,\
    AddRef,\
    Release,\
    GetGammaRamp,\
    SetGammaRamp

struct DDSURFACEDESC
    dwSize                  dd   ?
    dwFlags                 dd   ?
    dwHeight                dd   ?
    dwWidth                 dd   ?
    union
        lPitch              dd   ?
        dwLinearSize        dd   ?
    ends
    dwBackBufferCount       dd   ?
    union
        dwMipMapCount       dd   ?
        dwZBufferBitDepth   dd   ?
        dwRefreshRate       dd   ?
    ends
    dwAlphaBitDepth         dd   ?
    dwReserved              dd   ?
    lpSurface               xptr ?
    ddckCKDestOverlay       DDCOLORKEY
    ddckCKDestBlt           DDCOLORKEY
    ddckCKSrcOverlay        DDCOLORKEY
    ddckCKSrcBlt            DDCOLORKEY
    ddpfPixelFormat         DDPIXELFORMAT
    ddsCaps                 DDSCAPS
ends

struct DDSURFACEDESC2
    dwSize                  dd   ?
    dwFlags                 dd   ?
    dwHeight                dd   ?
    dwWidth                 dd   ?
    union
        lPitch              dd   ?
        dwLinearSize        dd   ?
    ends
    dwBackBufferCount       dd   ?
    union
        dwMipMapCount       dd   ?
        dwRefreshRate       dd   ?
        dwSrcVBHandle       dd   ?
    ends
    dwAlphaBitDepth         dd   ?
    dwReserved              dd   ?
    lpSurface               xptr ?
    union
        ddckCKDestOverlay   DDCOLORKEY
        dwEmptyFaceColor    dd   ?
    ends
    ddckCKDestBlt           DDCOLORKEY
    ddckCKSrcOverlay        DDCOLORKEY
    ddckCKSrcBlt            DDCOLORKEY
    union
        ddpfPixelFormat     DDPIXELFORMAT
        dwFVF               dd   ?
    ends
    ddsCaps                 DDSCAPS2
    dwTextureStage          dd   ?
ends

struct DDOPTSURFACEDESC
    dwSize              dd   ?
    dwFlags             dd   ?
    ddSCaps             DDSCAPS2
    ddOSCaps            DDOSCAPS
    guid                GUID
    dwCompressionRatio  dd   ?
ends

struct DDCOLORCONTROL
    dwSize          dd ?
    dwFlags         dd ?
    lBrightness     dd ?
    lContrast       dd ?
    lHue            dd ?
    lSaturation     dd ?
    lSharpness      dd ?
    lGamma          dd ?
    lColorEnable    dd ?
    dwReserved1     dd ?
ends

;======================================== Functions =======================================;
if defined APP_WIN64
    import ddraw,\
    AcquireDDThreadLock,'AcquireDDThreadLock',\
    D3DParseUnknownCommand,'D3DParseUnknownCommand',\
    DDGetAttachedSurfaceLcl,'DDGetAttachedSurfaceLcl',\
    DDInternalLock,'DDInternalLock',\
    DDInternalUnlock,'DDInternalUnlock',\
    DSoundHelp,'DSoundHelp',\
    DirectDrawCreate,'DirectDrawCreate',\
    DirectDrawCreateClipper,'DirectDrawCreateClipper',\
    DirectDrawCreateEx,'DirectDrawCreateEx',\
    DirectDrawEnumerateA,'DirectDrawEnumerateA',\
    DirectDrawEnumerateExA,'DirectDrawEnumerateExA',\
    DirectDrawEnumerateExW,'DirectDrawEnumerateExW',\
    DirectDrawEnumerateW,'DirectDrawEnumerateW',\
    GetDDSurfaceLocal,'GetDDSurfaceLocal',\
    GetSurfaceFromDC,'GetSurfaceFromDC',\
    ReleaseDDThreadLock,'ReleaseDDThreadLock'
else
    import ddraw,\
    DDGetAttachedSurfaceLcl,'DDGetAttachedSurfaceLcl',\
    DDInternalLock,'DDInternalLock',\
    DDInternalUnlock,'DDInternalUnlock',\
    DSoundHelp,'DSoundHelp',\
    DirectDrawCreate,'DirectDrawCreate',\
    DirectDrawCreateClipper,'DirectDrawCreateClipper',\
    DirectDrawCreateEx,'DirectDrawCreateEx',\
    DirectDrawEnumerateA,'DirectDrawEnumerateA',\
    DirectDrawEnumerateExA,'DirectDrawEnumerateExA',\
    DirectDrawEnumerateExW,'DirectDrawEnumerateExW',\
    DirectDrawEnumerateW,'DirectDrawEnumerateW',\
    GetDDSurfaceLocal,'GetDDSurfaceLocal',\
    GetSurfaceFromDC,'GetSurfaceFromDC'
end if

api DirectDrawEnumerate,\
DirectDrawEnumerateEx

;======================= Undocumented functions (unknown arguments) =======================;
;if defined APP_WIN64
;    CompleteCreateSysmemSurface,'CompleteCreateSysmemSurface',\
;    GetOLEThunkData,'GetOLEThunkData',\
;    RegisterSpecialCase,'RegisterSpecialCase',\
;    ReleaseDDThreadLock,'ReleaseDDThreadLock',\
;    SetAppCompatData,'SetAppCompatData'
;end if

.data
GUID_CLSID_DirectDraw                           GUID    0D7B70EE0H,04340H,011CFH,<0B0H,063H,000H,020H,0AFH,0C2H,0CDH,035H>
GUID_CLSID_DirectDraw7                          GUID    03C305196H,050DBH,011D3H,<09CH,0FEH,000H,0C0H,04FH,0D9H,030H,0C5H>
GUID_CLSID_DirectDrawClipper                    GUID    0593817A0H,07DB3H,011CFH,<0A2H,0DEH,000H,0AAH,000H,0b9H,033H,056H>
GUID_IID_IDirectDraw                            GUID    06C14DB80H,0A733H,011CEH,<0A5H,021H,000H,020H,0AFH,00BH,0E5H,060H>
GUID_IID_IDirectDraw2                           GUID    0B3A6F3E0H,02B43H,011CFH,<0A2H,0DEH,000H,0AAH,000H,0B9H,033H,056H>
GUID_IID_IDirectDraw4                           GUID    09C59509AH,039BDH,011D1H,<08CH,04AH,000H,0C0H,04FH,0D9H,030H,0C5H>
GUID_IID_IDirectDraw7                           GUID    015E65EC0H,03B9CH,011D2H,<0B9H,02FH,000H,060H,097H,097H,0EAH,05BH>
GUID_IID_IDirectDrawSurface                     GUID    06C14DB81H,0A733H,011CEH,<0A5H,021H,000H,020H,0AFH,00BH,0E5H,060H>
GUID_IID_IDirectDrawSurface2                    GUID    057805885H,06eecH,011cfH,<094H,041H,0a8H,023H,003H,0c1H,00eH,027H>
GUID_IID_IDirectDrawSurface3                    GUID    0DA044E00H,069B2H,011D0H,<0A1H,0D5H,000H,0AAH,000H,0B8H,0DFH,0BBH>
GUID_IID_IDirectDrawSurface4                    GUID    00B2B8630H,0AD35H,011D0H,<08EH,0A6H,000H,060H,097H,097H,0EAH,05BH>
GUID_IID_IDirectDrawSurface7                    GUID    006675a80H,03b9bH,011d2H,<0b9H,02fH,000H,060H,097H,097H,0eaH,05bH>
GUID_IID_IDirectDrawPalette                     GUID    06C14DB84H,0A733H,011CEH,<0A5H,021H,000H,020H,0AFH,00BH,0E5H,060H>
GUID_IID_IDirectDrawClipper                     GUID    06C14DB85H,0A733H,011CEH,<0A5H,021H,000H,020H,0AFH,00BH,0E5H,060H>
GUID_IID_IDirectDrawColorControl                GUID    04B9F0EE0H,00D7EH,011D0H,<09BH,006H,000H,0A0H,0C9H,003H,0A3H,0B8H>
GUID_IID_IDirectDrawGammaControl                GUID    069C11C3EH,0B46BH,011D1H,<0ADH,07AH,000H,0C0H,04FH,0C2H,09BH,04EH>

end if ;DDRAW_INC
