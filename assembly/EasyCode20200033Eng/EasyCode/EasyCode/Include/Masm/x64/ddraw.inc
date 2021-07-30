;======================================================;
;                                                      ;
;   ddraw.inc for Easy Code 2.0 64-bit Masm projects   ;
;                   (version 1.0.1)                    ;
;                                                      ;
;             Copyright © Ramon Sala - 2020            ;
;                                                      ;
;======================================================;

IFNDEF DDRAW_INC
DDRAW_INC   EQU 1

IFNDEF DIRECTDRAW_VERSION
    DIRECTDRAW_VERSION                          EQU     0700H
ENDIF

DDRAW_H_REQVER                                  EQU     100

DDENUM_ATTACHEDSECONDARYDEVICES                 EQU     00000001H
DDENUM_DETACHEDSECONDARYDEVICES                 EQU     00000002H
DDENUM_NONDISPLAYDEVICES                        EQU     00000004H

REGSTR_KEY_DDHW_DESCRIPTION                     EQU     <Description>
REGSTR_KEY_DDHW_DRIVERNAME                      EQU     <DriverName>
REGSTR_PATH_DDHW                                EQU     <Hardware\DirectDrawDrivers>

DDCREATE_HARDWAREONLY                           EQU     00000001H
DDCREATE_EMULATIONONLY                          EQU     00000002H

DD_ROP_SPACE                                    EQU     8

MAX_DDDEVICEID_STRING                           EQU     512

DDGDI_GETHOSTIDENTIFIER                         EQU     00000001H

DDSD_CAPS                                       EQU     00000001H
DDSD_HEIGHT                                     EQU     00000002H
DDSD_WIDTH                                      EQU     00000004H
DDSD_PITCH                                      EQU     00000008H
DDSD_BACKBUFFERCOUNT                            EQU     00000020H
DDSD_ZBUFFERBITDEPTH                            EQU     00000040H
DDSD_ALPHABITDEPTH                              EQU     00000080H
DDSD_LPSURFACE                                  EQU     00000800H
DDSD_PIXELFORMAT                                EQU     00001000H
DDSD_CKDESTOVERLAY                              EQU     00002000H
DDSD_CKDESTBLT                                  EQU     00004000H
DDSD_CKSRCOVERLAY                               EQU     00008000H
DDSD_CKSRCBLT                                   EQU     00010000H
DDSD_MIPMAPCOUNT                                EQU     00020000H
DDSD_REFRESHRATE                                EQU     00040000H
DDSD_LINEARSIZE                                 EQU     00080000H
DDSD_TEXTURESTAGE                               EQU     00100000H
DDSD_FVF                                        EQU     00200000H
DDSD_SRCVBHANDLE                                EQU     00400000H
DDSD_ALL                                        EQU     07FF9EElH

DDOSD_GUID                                      EQU     00000001H
DDOSD_COMPRESSION_RATIO                         EQU     00000002H
DDOSD_SCAPS                                     EQU     00000004H
DDOSD_OSCAPS                                    EQU     00000008H
DDOSD_ALL                                       EQU     000000flH

DDOSDCAPS_OPTCOMPRESSED                         EQU     00000001H
DDOSDCAPS_OPTREORDERED                          EQU     00000002H
DDOSDCAPS_MONOLITHICMIPMAP                      EQU     00000004H
DDOSDCAPS_VALIDSCAPS                            EQU     30004800H
DDOSDCAPS_VALIDOSCAPS                           EQU     00000007H

DDCOLOR_BRIGHTNESS                              EQU     00000001H
DDCOLOR_CONTRAST                                EQU     00000002H
DDCOLOR_HUE                                     EQU     00000004H
DDCOLOR_SATURATION                              EQU     00000008H
DDCOLOR_SHARPNESS                               EQU     00000010H
DDCOLOR_GAMMA                                   EQU     00000020H
DDCOLOR_COLORENABLE                             EQU     00000040H

DDSCAPS_RESERVED1                               EQU     00000001H
DDSCAPS_ALPHA                                   EQU     00000002H
DDSCAPS_BACKBUFFER                              EQU     00000004H
DDSCAPS_COMPLEX                                 EQU     00000008H
DDSCAPS_FLIP                                    EQU     00000010H
DDSCAPS_FRONTBUFFER                             EQU     00000020H
DDSCAPS_OFFSCREENPLAIN                          EQU     00000040H
DDSCAPS_OVERLAY                                 EQU     00000080H
DDSCAPS_PALETTE                                 EQU     00000100H
DDSCAPS_PRIMARYSURFACE                          EQU     00000200H
DDSCAPS_RESERVED3                               EQU     00000400H
DDSCAPS_PRIMARYSURFACELEFT                      EQU     0
DDSCAPS_SYSTEMMEMORY                            EQU     00000800H
DDSCAPS_TEXTURE                                 EQU     00001000H
DDSCAPS_3DDEVICE                                EQU     00002000H
DDSCAPS_VIDEOMEMORY                             EQU     00004000H
DDSCAPS_VISIBLE                                 EQU     00008000H
DDSCAPS_WRITEONLY                               EQU     00010000H
DDSCAPS_ZBUFFER                                 EQU     00020000H
DDSCAPS_OWNDC                                   EQU     00040000H
DDSCAPS_LIVEVIDEO                               EQU     00080000H
DDSCAPS_HWCODEC                                 EQU     00100000H
DDSCAPS_MODEX                                   EQU     00200000H
DDSCAPS_MIPMAP                                  EQU     00400000H
DDSCAPS_RESERVED2                               EQU     00800000H
DDSCAPS_ALLOCONLOAD                             EQU     04000000H
DDSCAPS_VIDEOPORT                               EQU     08000000H
DDSCAPS_LOCALVIDMEM                             EQU     10000000H
DDSCAPS_NONLOCALVIDMEM                          EQU     20000000H
DDSCAPS_STANDARDVGAMODE                         EQU     40000000H
DDSCAPS_OPTIMIZED                               EQU     80000000H

DDSCAPS2_HARDWAREDEINTERLACE                    EQU     00000002H
DDSCAPS2_HINTDYNAMIC                            EQU     00000004H
DDSCAPS2_HINTSTATIC                             EQU     00000008H
DDSCAPS2_TEXTUREMANAGE                          EQU     00000010H
DDSCAPS2_RESERVED1                              EQU     00000020H
DDSCAPS2_RESERVED2                              EQU     00000040H
DDSCAPS2_OPAQUE                                 EQU     00000080H
DDSCAPS2_HINTANTIALIASING                       EQU     00000100H
DDSCAPS2_CUBEMAP                                EQU     00000200H
DDSCAPS2_CUBEMAP_POSITIVEX                      EQU     00000400H
DDSCAPS2_CUBEMAP_NEGATIVEX                      EQU     00000800H
DDSCAPS2_CUBEMAP_POSITIVEY                      EQU     00001000H
DDSCAPS2_CUBEMAP_NEGATIVEY                      EQU     00002000H
DDSCAPS2_CUBEMAP_POSITIVEZ                      EQU     00004000H
DDSCAPS2_CUBEMAP_NEGATIVEZ                      EQU     00008000H
DDSCAPS2_CUBEMAP_ALLFACES                       EQU     (DDSCAPS2_CUBEMAP_POSITIVEX OR DDSCAPS2_CUBEMAP_NEGATIVEX OR DDSCAPS2_CUBEMAP_POSITIVEY OR DDSCAPS2_CUBEMAP_NEGATIVEY OR DDSCAPS2_CUBEMAP_POSITIVEZ OR DDSCAPS2_CUBEMAP_NEGATIVEZ)
DDSCAPS2_MIPMAPSUBLEVEL                         EQU     00010000H
DDSCAPS2_D3DTEXTUREMANAGE                       EQU     00020000H
DDSCAPS2_DONOTPERSIST                           EQU     00040000H
DDSCAPS2_STEREOSURFACELEFT                      EQU     00080000H

DDCAPS_3D                                       EQU     00000001H
DDCAPS_ALIGNBOUNDARYDEST                        EQU     00000002H
DDCAPS_ALIGNSIZEDEST                            EQU     00000004H
DDCAPS_ALIGNBOUNDARYSRC                         EQU     00000008H
DDCAPS_ALIGNSIZESRC                             EQU     00000010H
DDCAPS_ALIGNSTRIDE                              EQU     00000020H
DDCAPS_BLT                                      EQU     00000040H
DDCAPS_BLTQUEUE                                 EQU     00000080H
DDCAPS_BLTFOURCC                                EQU     00000100H
DDCAPS_BLTSTRETCH                               EQU     00000200H
DDCAPS_GDI                                      EQU     00000400H
DDCAPS_OVERLAY                                  EQU     00000800H
DDCAPS_OVERLAYCANTCLIP                          EQU     00001000H
DDCAPS_OVERLAYFOURCC                            EQU     00002000H
DDCAPS_OVERLAYSTRETCH                           EQU     00004000H
DDCAPS_PALETTE                                  EQU     00008000H
DDCAPS_PALETTEVSYNC                             EQU     00010000H
DDCAPS_READSCANLINE                             EQU     00020000H
DDCAPS_RESERVED1                                EQU     00040000H
DDCAPS_VBI                                      EQU     00080000H
DDCAPS_ZBLTS                                    EQU     00100000H
DDCAPS_ZOVERLAYS                                EQU     00200000H
DDCAPS_COLORKEY                                 EQU     00400000H
DDCAPS_ALPHA                                    EQU     00800000H
DDCAPS_COLORKEYHWASSIST                         EQU     01000000H
DDCAPS_NOHARDWARE                               EQU     02000000H
DDCAPS_BLTCOLORFILL                             EQU     04000000H
DDCAPS_BANKSWITCHED                             EQU     08000000H
DDCAPS_BLTDEPTHFILL                             EQU     10000000H
DDCAPS_CANCLIP                                  EQU     20000000H
DDCAPS_CANCLIPSTRETCHED                         EQU     40000000H
DDCAPS_CANBLTSYSMEM                             EQU     80000000H

DDCAPS2_CERTIFIED                               EQU     00000001H
DDCAPS2_NO2DDURING3DSCENE                       EQU     00000002H
DDCAPS2_VIDEOPORT                               EQU     00000004H
DDCAPS2_AUTOFLIPOVERLAY                         EQU     00000008H
DDCAPS2_CANBOBINTERLEAVED                       EQU     00000010H
DDCAPS2_CANBOBNONINTERLEAVED                    EQU     00000020H
DDCAPS2_COLORCONTROLOVERLAY                     EQU     00000040H
DDCAPS2_COLORCONTROLPRIMARY                     EQU     00000080H
DDCAPS2_CANDROPZ16BIT                           EQU     00000100H
DDCAPS2_NONLOCALVIDMEM                          EQU     00000200H
DDCAPS2_NONLOCALVIDMEMCAPS                      EQU     00000400H
DDCAPS2_NOPAGELOCKREQUIRED                      EQU     00000800H
DDCAPS2_WIDESURFACES                            EQU     00001000H
DDCAPS2_CANFLIPODDEVEN                          EQU     00002000H
DDCAPS2_CANBOBHARDWARE                          EQU     00004000H
DDCAPS2_COPYFOURCC                              EQU     00008000H
DDCAPS2_PRIMARYGAMMA                            EQU     00020000H
DDCAPS2_CANRENDERWINDOWED                       EQU     00080000H
DDCAPS2_CANCALIBRATEGAMMA                       EQU     00100000H
DDCAPS2_FLIPINTERVAL                            EQU     00200000H
DDCAPS2_FLIPNOVSYNC                             EQU     00400000H
DDCAPS2_CANMANAGETEXTURE                        EQU     00800000H
DDCAPS2_TEXMANINNONLOCALVIDMEM                  EQU     01000000H
DDCAPS2_STEREO                                  EQU     02000000H
DDCAPS2_SYSTONONLOCAL_AS_SYSTOLOCAL             EQU     04000000H

DDFXALPHACAPS_BLTALPHAEDGEBLEND                 EQU     00000001H
DDFXALPHACAPS_BLTALPHAPIXELS                    EQU     00000002H
DDFXALPHACAPS_BLTALPHAPIXELSNEG                 EQU     00000004H
DDFXALPHACAPS_BLTALPHASURFACES                  EQU     00000008H
DDFXALPHACAPS_BLTALPHASURFACESNEG               EQU     00000010H
DDFXALPHACAPS_OVERLAYALPHAEDGEBLEND             EQU     00000020H
DDFXALPHACAPS_OVERLAYALPHAPIXELS                EQU     00000040H
DDFXALPHACAPS_OVERLAYALPHAPIXELSNEG             EQU     00000080H
DDFXALPHACAPS_OVERLAYALPHASURFACES              EQU     00000100H
DDFXALPHACAPS_OVERLAYALPHASURFACESNEG           EQU     00000200H

DDFXCAPS_BLTARITHSTRETCHY                       EQU     00000020H
DDFXCAPS_BLTARITHSTRETCHYN                      EQU     00000010H
DDFXCAPS_BLTMIRRORLEFTRIGHT                     EQU     00000040H
DDFXCAPS_BLTMIRRORUPDOWN                        EQU     00000080H
DDFXCAPS_BLTROTATION                            EQU     00000100H
DDFXCAPS_BLTROTATION90                          EQU     00000200H
DDFXCAPS_BLTSHRINKX                             EQU     00000400H
DDFXCAPS_BLTSHRINKXN                            EQU     00000800H
DDFXCAPS_BLTSHRINKY                             EQU     00001000H
DDFXCAPS_BLTSHRINKYN                            EQU     00002000H
DDFXCAPS_BLTSTRETCHX                            EQU     00004000H
DDFXCAPS_BLTSTRETCHXN                           EQU     00008000H
DDFXCAPS_BLTSTRETCHY                            EQU     00010000H
DDFXCAPS_BLTSTRETCHYN                           EQU     00020000H
DDFXCAPS_OVERLAYARITHSTRETCHY                   EQU     00040000H
DDFXCAPS_OVERLAYARITHSTRETCHYN                  EQU     00000008H
DDFXCAPS_OVERLAYSHRINKX                         EQU     00080000H
DDFXCAPS_OVERLAYSHRINKXN                        EQU     00100000H
DDFXCAPS_OVERLAYSHRINKY                         EQU     00200000H
DDFXCAPS_OVERLAYSHRINKYN                        EQU     00400000H
DDFXCAPS_OVERLAYSTRETCHX                        EQU     00800000H
DDFXCAPS_OVERLAYSTRETCHXN                       EQU     01000000H
DDFXCAPS_OVERLAYSTRETCHY                        EQU     02000000H
DDFXCAPS_OVERLAYSTRETCHYN                       EQU     04000000H
DDFXCAPS_OVERLAYMIRRORLEFTRIGHT                 EQU     08000000H
DDFXCAPS_OVERLAYMIRRORUPDOWN                    EQU     10000000H
DDFXCAPS_BLTALPHA                               EQU     00000001H
DDFXCAPS_BLTFILTER                              EQU     DDFXCAPS_BLTARITHSTRETCHY
DDFXCAPS_OVERLAYALPHA                           EQU     00000004H
DDFXCAPS_OVERLAYFILTER                          EQU     DDFXCAPS_OVERLAYARITHSTRETCHY

DDSVCAPS_RESERVED1                              EQU     00000001H
DDSVCAPS_RESERVED2                              EQU     00000002H
DDSVCAPS_RESERVED3                              EQU     00000004H
DDSVCAPS_RESERVED4                              EQU     00000008H
DDSVCAPS_STEREOSEQUENTIAL                       EQU     00000010H

DDPCAPS_4BIT                                    EQU     00000001H
DDPCAPS_8BITENTRIES                             EQU     00000002H
DDPCAPS_8BIT                                    EQU     00000004H
DDPCAPS_INITIALIZE                              EQU     00000000H
DDPCAPS_PRIMARYSURFACE                          EQU     00000010H
DDPCAPS_PRIMARYSURFACELEFT                      EQU     00000020H
DDPCAPS_ALLOW256                                EQU     00000040H
DDPCAPS_VSYNC                                   EQU     00000080H
DDPCAPS_1BIT                                    EQU     00000100H
DDPCAPS_2BIT                                    EQU     00000200H
DDPCAPS_ALPHA                                   EQU     00000400H

DDSPD_IUNKNOWNPOINTER                           EQU     00000001H
DDSPD_VOLATILE                                  EQU     00000002H

DDBD_1                                          EQU     00004000H
DDBD_2                                          EQU     00002000H
DDBD_4                                          EQU     00001000H
DDBD_8                                          EQU     00000800H
DDBD_16                                         EQU     00000400H
DDBD_24                                         EQU     00000200H
DDBD_32                                         EQU     00000100H

DDCKEY_COLORSPACE                               EQU     00000001H
DDCKEY_DESTBLT                                  EQU     00000002H
DDCKEY_DESTOVERLAY                              EQU     00000004H
DDCKEY_SRCBLT                                   EQU     00000008H
DDCKEY_SRCOVERLAY                               EQU     00000010H

DDCKEYCAPS_DESTBLT                              EQU     00000001H
DDCKEYCAPS_DESTBLTCLRSPACE                      EQU     00000002H
DDCKEYCAPS_DESTBLTCLRSPACEYUV                   EQU     00000004H
DDCKEYCAPS_DESTBLTYUV                           EQU     00000008H
DDCKEYCAPS_DESTOVERLAY                          EQU     00000010H
DDCKEYCAPS_DESTOVERLAYCLRSPACE                  EQU     00000020H
DDCKEYCAPS_DESTOVERLAYCLRSPACEYUV               EQU     00000040H
DDCKEYCAPS_DESTOVERLAYONEACTIVE                 EQU     00000080H
DDCKEYCAPS_DESTOVERLAYYUV                       EQU     00000100H
DDCKEYCAPS_SRCBLT                               EQU     00000200H
DDCKEYCAPS_SRCBLTCLRSPACE                       EQU     00000400H
DDCKEYCAPS_SRCBLTCLRSPACEYUV                    EQU     00000800H
DDCKEYCAPS_SRCBLTYUV                            EQU     00001000H
DDCKEYCAPS_SRCOVERLAY                           EQU     00002000H
DDCKEYCAPS_SRCOVERLAYCLRSPACE                   EQU     00004000H
DDCKEYCAPS_SRCOVERLAYCLRSPACEYUV                EQU     00008000H
DDCKEYCAPS_SRCOVERLAYONEACTIVE                  EQU     00010000H
DDCKEYCAPS_SRCOVERLAYYUV                        EQU     00020000H
DDCKEYCAPS_NOCOSTOVERLAY                        EQU     00040000H

DDPF_ALPHAPIXELS                                EQU     00000001H
DDPF_ALPHA                                      EQU     00000002H
DDPF_FOURCC                                     EQU     00000004H
DDPF_PALETTEINDEXED4                            EQU     00000008H
DDPF_PALETTEINDEXEDTO8                          EQU     00000010H
DDPF_PALETTEINDEXED8                            EQU     00000020H
DDPF_RGB                                        EQU     00000040H
DDPF_COMPRESSED                                 EQU     00000080H
DDPF_RGBTOYUV                                   EQU     00000100H
DDPF_YUV                                        EQU     00000200H
DDPF_ZBUFFER                                    EQU     00000400H
DDPF_PALETTEINDEXED1                            EQU     00000800H
DDPF_PALETTEINDEXED2                            EQU     00001000H
DDPF_ZPIXELS                                    EQU     00002000H
DDPF_STENCILBUFFER                              EQU     00004000H
DDPF_ALPHAPREMULT                               EQU     00008000H
DDPF_LUMINANCE                                  EQU     00020000H
DDPF_BUMPLUMINANCE                              EQU     00040000H
DDPF_BUMPDUDV                                   EQU     00080000H

DDENUMSURFACES_ALL                              EQU     00000001H
DDENUMSURFACES_MATCH                            EQU     00000002H
DDENUMSURFACES_NOMATCH                          EQU     00000004H
DDENUMSURFACES_CANBECREATED                     EQU     00000008H
DDENUMSURFACES_DOESEXIST                        EQU     00000010H

DDSDM_STANDARDVGAMODE                           EQU     00000001H
DDEDM_REFRESHRATES                              EQU     00000001H
DDEDM_STANDARDVGAMODES                          EQU     00000002H

DDSCL_FULLSCREEN                                EQU     00000001H
DDSCL_ALLOWREBOOT                               EQU     00000002H
DDSCL_NOWINDOWCHANGES                           EQU     00000004H
DDSCL_NORMAL                                    EQU     00000008H
DDSCL_EXCLUSIVE                                 EQU     00000010H
DDSCL_ALLOWMODEX                                EQU     00000040H
DDSCL_SETFOCUSWINDOW                            EQU     00000080H
DDSCL_SETDEVICEWINDOW                           EQU     00000100H
DDSCL_CREATEDEVICEWINDOW                        EQU     00000200H
DDSCL_MULTITHREADED                             EQU     00000400H
DDSCL_FPUSETUP                                  EQU     00000800H
DDSCL_FPUPRESERVE                               EQU     00001000H

DDBLT_ALPHADEST                                 EQU     00000001H
DDBLT_ALPHADESTCONSTOVERRIDE                    EQU     00000002H
DDBLT_ALPHADESTNEG                              EQU     00000004H
DDBLT_ALPHADESTSURFACEOVERRIDE                  EQU     00000008H
DDBLT_ALPHAEDGEBLEND                            EQU     00000010H
DDBLT_ALPHASRC                                  EQU     00000020H
DDBLT_ALPHASRCCONSTOVERRIDE                     EQU     00000040H
DDBLT_ALPHASRCNEG                               EQU     00000080H
DDBLT_ALPHASRCSURFACEOVERRIDE                   EQU     00000100H
DDBLT_ASYNC                                     EQU     00000200H
DDBLT_COLORFILL                                 EQU     00000400H
DDBLT_DDFX                                      EQU     00000800H
DDBLT_DDROPS                                    EQU     00001000H
DDBLT_KEYDEST                                   EQU     00002000H
DDBLT_KEYDESTOVERRIDE                           EQU     00004000H
DDBLT_KEYSRC                                    EQU     00008000H
DDBLT_KEYSRCOVERRIDE                            EQU     00010000H
DDBLT_ROP                                       EQU     00020000H
DDBLT_ROTATIONANGLE                             EQU     00040000H
DDBLT_ZBUFFER                                   EQU     00080000H
DDBLT_ZBUFFERDESTCONSTOVERRIDE                  EQU     00100000H
DDBLT_ZBUFFERDESTOVERRIDE                       EQU     00200000H
DDBLT_ZBUFFERSRCCONSTOVERRIDE                   EQU     00400000H
DDBLT_ZBUFFERSRCOVERRIDE                        EQU     00800000H
DDBLT_WAIT                                      EQU     01000000H
DDBLT_DEPTHFILL                                 EQU     02000000H
DDBLT_DONOTWAIT                                 EQU     08000000H

DDBLTFAST_NOCOLORKEY                            EQU     00000000H
DDBLTFAST_SRCCOLORKEY                           EQU     00000001H
DDBLTFAST_DESTCOLORKEY                          EQU     00000002H
DDBLTFAST_WAIT                                  EQU     00000010H
DDBLTFAST_DONOTWAIT                             EQU     00000020H

DDFLIP_WAIT                                     EQU     00000001H
DDFLIP_EVEN                                     EQU     00000002H
DDFLIP_ODD                                      EQU     00000004H
DDFLIP_NOVSYNC                                  EQU     00000008H
DDFLIP_INTERVAL2                                EQU     02000000H
DDFLIP_INTERVAL3                                EQU     03000000H
DDFLIP_INTERVAL4                                EQU     04000000H
DDFLIP_STEREO                                   EQU     00000010H
DDFLIP_DONOTWAIT                                EQU     00000020H

DDOVER_ALPHADEST                                EQU     00000001H
DDOVER_ALPHADESTCONSTOVERRIDE                   EQU     00000002H
DDOVER_ALPHADESTNEG                             EQU     00000004H
DDOVER_ALPHADESTSURFACEOVERRIDE                 EQU     00000008H
DDOVER_ALPHAEDGEBLEND                           EQU     00000010H
DDOVER_ALPHASRC                                 EQU     00000020H
DDOVER_ALPHASRCCONSTOVERRIDE                    EQU     00000040H
DDOVER_ALPHASRCNEG                              EQU     00000080H
DDOVER_ALPHASRCSURFACEOVERRIDE                  EQU     00000100H
DDOVER_HIDE                                     EQU     00000200H
DDOVER_KEYDEST                                  EQU     00000400H
DDOVER_KEYDESTOVERRIDE                          EQU     00000800H
DDOVER_KEYSRC                                   EQU     00001000H
DDOVER_KEYSRCOVERRIDE                           EQU     00002000H
DDOVER_SHOW                                     EQU     00004000H
DDOVER_ADDDIRTYRECT                             EQU     00008000H
DDOVER_REFRESHDIRTYRECTS                        EQU     00010000H
DDOVER_REFRESHALL                               EQU     00020000H
DDOVER_DDFX                                     EQU     00080000H
DDOVER_AUTOFLIP                                 EQU     00100000H
DDOVER_BOB                                      EQU     00200000H
DDOVER_OVERRIDEBOBWEAVE                         EQU     00400000H
DDOVER_INTERLEAVED                              EQU     00800000H
DDOVER_BOBHARDWARE                              EQU     01000000H
DDOVER_ARGBSCALEFACTORS                         EQU     02000000H
DDOVER_DEGRADEARGBSCALING                       EQU     04000000H

DDLOCK_SURFACEMEMORYPTR                         EQU     00000000H
DDLOCK_WAIT                                     EQU     00000001H
DDLOCK_EVENT                                    EQU     00000002H
DDLOCK_READONLY                                 EQU     00000010H
DDLOCK_WRITEONLY                                EQU     00000020H
DDLOCK_NOSYSLOCK                                EQU     00000800H
DDLOCK_NOOVERWRITE                              EQU     00001000H
DDLOCK_DISCARDCONTENTS                          EQU     00002000H
DDLOCK_OKTOSWAP                                 EQU     00002000H
DDLOCK_DONOTWAIT                                EQU     00004000H

DDBLTFX_ARITHSTRETCHY                           EQU     00000001H
DDBLTFX_MIRRORLEFTRIGHT                         EQU     00000002H
DDBLTFX_MIRRORUPDOWN                            EQU     00000004H
DDBLTFX_NOTEARING                               EQU     00000008H
DDBLTFX_ROTATE180                               EQU     00000010H
DDBLTFX_ROTATE270                               EQU     00000020H
DDBLTFX_ROTATE90                                EQU     00000040H
DDBLTFX_ZBUFFERRANGE                            EQU     00000080H
DDBLTFX_ZBUFFERBASEDEST                         EQU     00000100H

DDOVERFX_ARITHSTRETCHY                          EQU     00000001H
DDOVERFX_MIRRORLEFTRIGHT                        EQU     00000002H
DDOVERFX_MIRRORUPDOWN                           EQU     00000004H

DDWAITVB_BLOCKBEGIN                             EQU     00000001H
DDWAITVB_BLOCKBEGINEVENT                        EQU     00000002H
DDWAITVB_BLOCKEND                               EQU     00000004H

DDGFS_CANFLIP                                   EQU     00000001H
DDGFS_ISFLIPDONE                                EQU     00000002H

DDGBS_CANBLT                                    EQU     00000001H
DDGBS_ISBLTDONE                                 EQU     00000002H

DDENUMOVERLAYZ_BACKTOFRONT                      EQU     00000000H
DDENUMOVERLAYZ_FRONTTOBACK                      EQU     00000001H

DDOVERZ_SENDTOFRONT                             EQU     00000000H
DDOVERZ_SENDTOBACK                              EQU     00000001H
DDOVERZ_MOVEFORWARD                             EQU     00000002H
DDOVERZ_MOVEBACKWARD                            EQU     00000003H
DDOVERZ_INSERTINFRONTOF                         EQU     00000004H
DDOVERZ_INSERTINBACKOF                          EQU     00000005H

DDSGR_CALIBRATE                                 EQU     00000001H
DDSMT_ISTESTREQUIRED                            EQU     00000001H

DDEM_MODEPASSED                                 EQU     00000001H
DDEM_MODEFAILED                                 EQU     00000002H

DD_OK                                           EQU     0
DD_FALSE                                        EQU     S_FALSE

DDENUMRET_CANCEL                                EQU     0
DDENUMRET_OK                                    EQU     1

DDERR_ALREADYINITIALIZED                        EQU     (1 SHL 31) + (0876H SHL 16) + 5
DDERR_CANNOTATTACHSURFACE                       EQU     (1 SHL 31) + (0876H SHL 16) + 10
DDERR_CANNOTDETACHSURFACE                       EQU     (1 SHL 31) + (0876H SHL 16) + 20
DDERR_CURRENTLYNOTAVAIL                         EQU     (1 SHL 31) + (0876H SHL 16) + 40
DDERR_EXCEPTION                                 EQU     (1 SHL 31) + (0876H SHL 16) + 55
DDERR_GENERIC                                   EQU     E_FAIL
DDERR_HEIGHTALIGN                               EQU     (1 SHL 31) + (0876H SHL 16) + 90
DDERR_INCOMPATIBLEPRIMARY                       EQU     (1 SHL 31) + (0876H SHL 16) + 95
DDERR_INVALIDCAPS                               EQU     (1 SHL 31) + (0876H SHL 16) + 100
DDERR_INVALIDCLIPLIST                           EQU     (1 SHL 31) + (0876H SHL 16) + 110
DDERR_INVALIDMODE                               EQU     (1 SHL 31) + (0876H SHL 16) + 120
DDERR_INVALIDOBJECT                             EQU     (1 SHL 31) + (0876H SHL 16) + 130
DDERR_INVALIDPARAMS                             EQU     E_INVALIDARG
DDERR_INVALIDPIXELFORMAT                        EQU     (1 SHL 31) + (0876H SHL 16) + 145
DDERR_INVALIDRECT                               EQU     (1 SHL 31) + (0876H SHL 16) + 150
DDERR_LOCKEDSURFACES                            EQU     (1 SHL 31) + (0876H SHL 16) + 160
DDERR_NO3D                                      EQU     (1 SHL 31) + (0876H SHL 16) + 170
DDERR_NOALPHAHW                                 EQU     (1 SHL 31) + (0876H SHL 16) + 180
DDERR_NOSTEREOHARDWARE                          EQU     (1 SHL 31) + (0876H SHL 16) + 181
DDERR_NOSURFACELEFT                             EQU     (1 SHL 31) + (0876H SHL 16) + 182
DDERR_NOCLIPLIST                                EQU     (1 SHL 31) + (0876H SHL 16) + 205
DDERR_NOCOLORCONVHW                             EQU     (1 SHL 31) + (0876H SHL 16) + 210
DDERR_NOCOOPERATIVELEVELSET                     EQU     (1 SHL 31) + (0876H SHL 16) + 212
DDERR_NOCOLORKEY                                EQU     (1 SHL 31) + (0876H SHL 16) + 215
DDERR_NOCOLORKEYHW                              EQU     (1 SHL 31) + (0876H SHL 16) + 220
DDERR_NODIRECTDRAWSUPPORT                       EQU     (1 SHL 31) + (0876H SHL 16) + 222
DDERR_NOEXCLUSIVEMODE                           EQU     (1 SHL 31) + (0876H SHL 16) + 225
DDERR_NOFLIPHW                                  EQU     (1 SHL 31) + (0876H SHL 16) + 230
DDERR_NOGDI                                     EQU     (1 SHL 31) + (0876H SHL 16) + 240
DDERR_NOMIRRORHW                                EQU     (1 SHL 31) + (0876H SHL 16) + 250
DDERR_NOTFOUND                                  EQU     (1 SHL 31) + (0876H SHL 16) + 255
DDERR_NOOVERLAYHW                               EQU     (1 SHL 31) + (0876H SHL 16) + 260
DDERR_OVERLAPPINGRECTS                          EQU     (1 SHL 31) + (0876H SHL 16) + 270
DDERR_NORASTEROPHW                              EQU     (1 SHL 31) + (0876H SHL 16) + 280
DDERR_NOROTATIONHW                              EQU     (1 SHL 31) + (0876H SHL 16) + 290
DDERR_NOSTRETCHHW                               EQU     (1 SHL 31) + (0876H SHL 16) + 310
DDERR_NOT4BITCOLOR                              EQU     (1 SHL 31) + (0876H SHL 16) + 316
DDERR_NOT4BITCOLORINDEX                         EQU     (1 SHL 31) + (0876H SHL 16) + 317
DDERR_NOT8BITCOLOR                              EQU     (1 SHL 31) + (0876H SHL 16) + 320
DDERR_NOTEXTUREHW                               EQU     (1 SHL 31) + (0876H SHL 16) + 330
DDERR_NOVSYNCHW                                 EQU     (1 SHL 31) + (0876H SHL 16) + 335
DDERR_NOZBUFFERHW                               EQU     (1 SHL 31) + (0876H SHL 16) + 340
DDERR_NOZOVERLAYHW                              EQU     (1 SHL 31) + (0876H SHL 16) + 350
DDERR_OUTOFCAPS                                 EQU     (1 SHL 31) + (0876H SHL 16) + 360
DDERR_OUTOFMEMORY                               EQU     E_OUTOFMEMORY
DDERR_OUTOFVIDEOMEMORY                          EQU     (1 SHL 31) + (0876H SHL 16) + 380
DDERR_OVERLAYCANTCLIP                           EQU     (1 SHL 31) + (0876H SHL 16) + 382
DDERR_OVERLAYCOLORKEYONLYONEACTIVE              EQU     (1 SHL 31) + (0876H SHL 16) + 384
DDERR_PALETTEBUSY                               EQU     (1 SHL 31) + (0876H SHL 16) + 387
DDERR_COLORKEYNOTSET                            EQU     (1 SHL 31) + (0876H SHL 16) + 400
DDERR_SURFACEALREADYATTACHED                    EQU     (1 SHL 31) + (0876H SHL 16) + 410
DDERR_SURFACEALREADYDEPENDENT                   EQU     (1 SHL 31) + (0876H SHL 16) + 420
DDERR_SURFACEBUSY                               EQU     (1 SHL 31) + (0876H SHL 16) + 430
DDERR_CANTLOCKSURFACE                           EQU     (1 SHL 31) + (0876H SHL 16) + 435
DDERR_SURFACEISOBSCURED                         EQU     (1 SHL 31) + (0876H SHL 16) + 440
DDERR_SURFACELOST                               EQU     (1 SHL 31) + (0876H SHL 16) + 450
DDERR_SURFACENOTATTACHED                        EQU     (1 SHL 31) + (0876H SHL 16) + 460
DDERR_TOOBIGHEIGHT                              EQU     (1 SHL 31) + (0876H SHL 16) + 470
DDERR_TOOBIGSIZE                                EQU     (1 SHL 31) + (0876H SHL 16) + 480
DDERR_TOOBIGWIDTH                               EQU     (1 SHL 31) + (0876H SHL 16) + 490
DDERR_UNSUPPORTED                               EQU     (1 SHL 31) + (0876H SHL 16) + E_NOTIMPL
DDERR_UNSUPPORTEDFORMAT                         EQU     (1 SHL 31) + (0876H SHL 16) + 510
DDERR_UNSUPPORTEDMASK                           EQU     (1 SHL 31) + (0876H SHL 16) + 520
DDERR_INVALIDSTREAM                             EQU     (1 SHL 31) + (0876H SHL 16) + 521
DDERR_VERTICALBLANKINPROGRESS                   EQU     (1 SHL 31) + (0876H SHL 16) + 537
DDERR_WASSTILLDRAWING                           EQU     (1 SHL 31) + (0876H SHL 16) + 540
DDERR_DDSCAPSCOMPLEXREQUIRED                    EQU     (1 SHL 31) + (0876H SHL 16) + 542
DDERR_XALIGN                                    EQU     (1 SHL 31) + (0876H SHL 16) + 560
DDERR_INVALIDDIRECTDRAWGUID                     EQU     (1 SHL 31) + (0876H SHL 16) + 561
DDERR_DIRECTDRAWALREADYCREATED                  EQU     (1 SHL 31) + (0876H SHL 16) + 562
DDERR_NODIRECTDRAWHW                            EQU     (1 SHL 31) + (0876H SHL 16) + 563
DDERR_PRIMARYSURFACEALREADYEXISTS               EQU     (1 SHL 31) + (0876H SHL 16) + 564
DDERR_NOEMULATION                               EQU     (1 SHL 31) + (0876H SHL 16) + 565
DDERR_REGIONTOOSMALL                            EQU     (1 SHL 31) + (0876H SHL 16) + 566
DDERR_CLIPPERISUSINGHWND                        EQU     (1 SHL 31) + (0876H SHL 16) + 567
DDERR_NOCLIPPERATTACHED                         EQU     (1 SHL 31) + (0876H SHL 16) + 568
DDERR_NOHWND                                    EQU     (1 SHL 31) + (0876H SHL 16) + 569
DDERR_HWNDSUBCLASSED                            EQU     (1 SHL 31) + (0876H SHL 16) + 570
DDERR_HWNDALREADYSET                            EQU     (1 SHL 31) + (0876H SHL 16) + 571
DDERR_NOPALETTEATTACHED                         EQU     (1 SHL 31) + (0876H SHL 16) + 572
DDERR_NOPALETTEHW                               EQU     (1 SHL 31) + (0876H SHL 16) + 573
DDERR_BLTFASTCANTCLIP                           EQU     (1 SHL 31) + (0876H SHL 16) + 574
DDERR_NOBLTHW                                   EQU     (1 SHL 31) + (0876H SHL 16) + 575
DDERR_NODDROPSHW                                EQU     (1 SHL 31) + (0876H SHL 16) + 576
DDERR_OVERLAYNOTVISIBLE                         EQU     (1 SHL 31) + (0876H SHL 16) + 577
DDERR_NOOVERLAYDEST                             EQU     (1 SHL 31) + (0876H SHL 16) + 578
DDERR_INVALIDPOSITION                           EQU     (1 SHL 31) + (0876H SHL 16) + 579
DDERR_NOTAOVERLAYSURFACE                        EQU     (1 SHL 31) + (0876H SHL 16) + 580
DDERR_EXCLUSIVEMODEALREADYSET                   EQU     (1 SHL 31) + (0876H SHL 16) + 581
DDERR_NOTFLIPPABLE                              EQU     (1 SHL 31) + (0876H SHL 16) + 582
DDERR_CANTDUPLICATE                             EQU     (1 SHL 31) + (0876H SHL 16) + 583
DDERR_NOTLOCKED                                 EQU     (1 SHL 31) + (0876H SHL 16) + 584
DDERR_CANTCREATEDC                              EQU     (1 SHL 31) + (0876H SHL 16) + 585
DDERR_NODC                                      EQU     (1 SHL 31) + (0876H SHL 16) + 586
DDERR_WRONGMODE                                 EQU     (1 SHL 31) + (0876H SHL 16) + 587
DDERR_IMPLICITLYCREATED                         EQU     (1 SHL 31) + (0876H SHL 16) + 588
DDERR_NOTPALETTIZED                             EQU     (1 SHL 31) + (0876H SHL 16) + 589
DDERR_UNSUPPORTEDMODE                           EQU     (1 SHL 31) + (0876H SHL 16) + 590
DDERR_NOMIPMAPHW                                EQU     (1 SHL 31) + (0876H SHL 16) + 591
DDERR_INVALIDSURFACETYPE                        EQU     (1 SHL 31) + (0876H SHL 16) + 592
DDERR_NOOPTIMIZEHW                              EQU     (1 SHL 31) + (0876H SHL 16) + 600
DDERR_NOTLOADED                                 EQU     (1 SHL 31) + (0876H SHL 16) + 601
DDERR_NOFOCUSWINDOW                             EQU     (1 SHL 31) + (0876H SHL 16) + 602
DDERR_NOTONMIPMAPSUBLEVEL                       EQU     (1 SHL 31) + (0876H SHL 16) + 603
DDERR_DCALREADYCREATED                          EQU     (1 SHL 31) + (0876H SHL 16) + 620
DDERR_NONONLOCALVIDMEM                          EQU     (1 SHL 31) + (0876H SHL 16) + 630
DDERR_CANTPAGELOCK                              EQU     (1 SHL 31) + (0876H SHL 16) + 640
DDERR_CANTPAGEUNLOCK                            EQU     (1 SHL 31) + (0876H SHL 16) + 660
DDERR_NOTPAGELOCKED                             EQU     (1 SHL 31) + (0876H SHL 16) + 680
DDERR_MOREDATA                                  EQU     (1 SHL 31) + (0876H SHL 16) + 690
DDERR_EXPIRED                                   EQU     (1 SHL 31) + (0876H SHL 16) + 691
DDERR_TESTFINISHED                              EQU     (1 SHL 31) + (0876H SHL 16) + 692
DDERR_NEWMODE                                   EQU     (1 SHL 31) + (0876H SHL 16) + 693
DDERR_D3DNOTINITIALIZED                         EQU     (1 SHL 31) + (0876H SHL 16) + 694
DDERR_VIDEONOTACTIVE                            EQU     (1 SHL 31) + (0876H SHL 16) + 695
DDERR_NOMONITORINFORMATION                      EQU     (1 SHL 31) + (0876H SHL 16) + 696
DDERR_NODRIVERSUPPORT                           EQU     (1 SHL 31) + (0876H SHL 16) + 697
DDERR_DEVICEDOESNTOWNSURFACE                    EQU     (1 SHL 31) + (0876H SHL 16) + 699
DDERR_NOTINITIALIZED                            EQU     CO_E_NOTINITIALIZED

;======================================== Structures ======================================;
DDARGB STRUCT ALIGNMODE
    blue    DB ?
    green   DB ?
    red     DB ?
    alpha   DB ?
DDARGB ENDS

DDRGBA STRUCT ALIGNMODE
    red     DB ?
    green   DB ?
    blue    DB ?
    alpha   DB ?
DDRGBA ENDS

DDCOLORKEY STRUCT ALIGNMODE
    dwColorSpaceLowValue  DD ?
    dwColorSpaceHighValue DD ?
DDCOLORKEY ENDS

DDBLTFX STRUCT ALIGNMODE
    dwSize                   DD   ?
    dwDDFX                   DD   ?
    dwROP                    DD   ?
    dwDDROP                  DD   ?
    dwRotationAngle          DD   ?
    dwZBufferOpCode          DD   ?
    dwZBufferLow             DD   ?
    dwZBufferHigh            DD   ?
    dwZBufferBaseDest        DD   ?
    dwZDestConstBitDepth     DD   ?
    UNION
        dwZDestConst         DD   ?
        lpDDSZBufferDest     XPTR ?
    ENDS
    dwZSrcConstBitDepth      DD  ?
    UNION
        dwZSrcConst          DD   ?
        lpDDSZBufferSrc      XPTR ?
    ENDS
    dwAlphaEdgeBlendBitDepth DD   ?
    dwAlphaEdgeBlend         DD   ?
    dwReserved               DD   ?
    dwAlphaDestConstBitDepth DD   ?
    UNION
        dwAlphaDestConst     DD   ?
        lpDDSAlphaDest       XPTR ?
    ENDS
    dwAlphaSrcConstBitDepth  DD   ?
    UNION
        dwAlphaSrcConst      DD   ?
        lpDDSAlphaSrc        XPTR ?
    ENDS
    UNION
        dwFillColor          DD   ?
        dwFillDepth          DD   ?
        dwFillPixel          DD   ?
        lpDDSPattern         XPTR ?
    ENDS
    ddckDestColorkey         DDCOLORKEY <>
    ddckSrcColorkey          DDCOLORKEY <>
DDBLTFX ENDS

DDSCAPS STRUCT ALIGNMODE
    dwCaps DD ?
DDSCAPS ENDS

DDOSCAPS STRUCT ALIGNMODE
    dwCaps DD ?
DDOSCAPS ENDS

DDSCAPSEX STRUCT ALIGNMODE
    dwCaps2 DD ?
    dwCaps3 DD ?
    dwCaps4 DD ?
DDSCAPSEX ENDS

DDSCAPS2 STRUCT ALIGNMODE
    dwCaps  DD ?
    dwCaps2 DD ?
    dwCaps3 DD ?
    dwCaps4 DD ?
DDSCAPS2 ENDS

DDCAPS_DX1 STRUCT ALIGNMODE
    dwSize                          DD ?
    dwCaps                          DD ?
    dwCaps2                         DD ?
    dwCKeyCaps                      DD ?
    dwFXCaps                        DD ?
    dwFXAlphaCaps                   DD ?
    dwPalCaps                       DD ?
    dwSVCaps                        DD ?
    dwAlphaBltConstBitDepths        DD ?
    dwAlphaBltPixelBitDepths        DD ?
    dwAlphaBltSurfaceBitDepths      DD ?
    dwAlphaOverlayConstBitDepths    DD ?
    dwAlphaOverlayPixelBitDepths    DD ?
    dwAlphaOverlaySurfaceBitDepths  DD ?
    dwZBufferBitDepths              DD ?
    dwVidMemTotal                   DD ?
    dwVidMemFree                    DD ?
    dwMaxVisibleOverlays            DD ?
    dwCurrVisibleOverlays           DD ?
    dwNumFourCCCodes                DD ?
    dwAlignBoundarySrc              DD ?
    dwAlignSizeSrc                  DD ?
    dwAlignBoundaryDest             DD ?
    dwAlignSizeDest                 DD ?
    dwAlignStrideAlign              DD ?
    dwRops                          DD DD_ROP_SPACE DUP(?)
    ddsCaps                         DDSCAPS <>
    dwMinOverlayStretch             DD ?
    dwMaxOverlayStretch             DD ?
    dwMinLiveVideoStretch           DD ?
    dwMaxLiveVideoStretch           DD ?
    dwMinHwCodecStretch             DD ?
    dwMaxHwCodecStretch             DD ?
    dwReserved1                     DD ?
    dwReserved2                     DD ?
    dwReserved3                     DD ?
DDCAPS_DX1 ENDS

DDCAPS_DX3 STRUCT ALIGNMODE
    dwSize                          DD ?
    dwCaps                          DD ?
    dwCaps2                         DD ?
    dwCKeyCaps                      DD ?
    dwFXCaps                        DD ?
    dwFXAlphaCaps                   DD ?
    dwPalCaps                       DD ?
    dwSVCaps                        DD ?
    dwAlphaBltConstBitDepths        DD ?
    dwAlphaBltPixelBitDepths        DD ?
    dwAlphaBltSurfaceBitDepths      DD ?
    dwAlphaOverlayConstBitDepths    DD ?
    dwAlphaOverlayPixelBitDepths    DD ?
    dwAlphaOverlaySurfaceBitDepths  DD ?
    dwZBufferBitDepths              DD ?
    dwVidMemTotal                   DD ?
    dwVidMemFree                    DD ?
    dwMaxVisibleOverlays            DD ?
    dwCurrVisibleOverlays           DD ?
    dwNumFourCCCodes                DD ?
    dwAlignBoundarySrc              DD ?
    dwAlignSizeSrc                  DD ?
    dwAlignBoundaryDest             DD ?
    dwAlignSizeDest                 DD ?
    dwAlignStrideAlign              DD ?
    dwRops                          DD DD_ROP_SPACE DUP(?)
    ddsCaps                         DDSCAPS <>
    dwMinOverlayStretch             DD ?
    dwMaxOverlayStretch             DD ?
    dwMinLiveVideoStretch           DD ?
    dwMaxLiveVideoStretch           DD ?
    dwMinHwCodecStretch             DD ?
    dwMaxHwCodecStretch             DD ?
    dwReserved1                     DD ?
    dwReserved2                     DD ?
    dwReserved3                     DD ?
    dwSVBCaps                       DD ?
    dwSVBCKeyCaps                   DD ?
    dwSVBFXCaps                     DD ?
    dwSVBRops                       DD DD_ROP_SPACE DUP(?)
    dwVSBCaps                       DD ?
    dwVSBCKeyCaps                   DD ?
    dwVSBFXCaps                     DD ?
    dwVSBRops                       DD DD_ROP_SPACE DUP(?)
    dwSSBCaps                       DD ?
    dwSSBCKeyCaps                   DD ?
    dwSSBFXCaps                     DD ?
    dwSSBRops                       DD DD_ROP_SPACE DUP(?)
    dwReserved4                     DD ?
    dwReserved5                     DD ?
    dwReserved6                     DD ?
DDCAPS_DX3 ENDS

DDCAPS_DX5 STRUCT ALIGNMODE
    dwSize                          DD ?
    dwCaps                          DD ?
    dwCaps2                         DD ?
    dwCKeyCaps                      DD ?
    dwFXCaps                        DD ?
    dwFXAlphaCaps                   DD ?
    dwPalCaps                       DD ?
    dwSVCaps                        DD ?
    dwAlphaBltConstBitDepths        DD ?
    dwAlphaBltPixelBitDepths        DD ?
    dwAlphaBltSurfaceBitDepths      DD ?
    dwAlphaOverlayConstBitDepths    DD ?
    dwAlphaOverlayPixelBitDepths    DD ?
    dwAlphaOverlaySurfaceBitDepths  DD ?
    dwZBufferBitDepths              DD ?
    dwVidMemTotal                   DD ?
    dwVidMemFree                    DD ?
    dwMaxVisibleOverlays            DD ?
    dwCurrVisibleOverlays           DD ?
    dwNumFourCCCodes                DD ?
    dwAlignBoundarySrc              DD ?
    dwAlignSizeSrc                  DD ?
    dwAlignBoundaryDest             DD ?
    dwAlignSizeDest                 DD ?
    dwAlignStrideAlign              DD ?
    dwRops                          DD DD_ROP_SPACE DUP(?)
    ddsCaps                         DDSCAPS <>
    dwMinOverlayStretch             DD ?
    dwMaxOverlayStretch             DD ?
    dwMinLiveVideoStretch           DD ?
    dwMaxLiveVideoStretch           DD ?
    dwMinHwCodecStretch             DD ?
    dwMaxHwCodecStretch             DD ?
    dwReserved1                     DD ?
    dwReserved2                     DD ?
    dwReserved3                     DD ?
    dwSVBCaps                       DD ?
    dwSVBCKeyCaps                   DD ?
    dwSVBFXCaps                     DD ?
    dwSVBRops                       DD DD_ROP_SPACE DUP(?)
    dwVSBCaps                       DD ?
    dwVSBCKeyCaps                   DD ?
    dwVSBFXCaps                     DD ?
    dwVSBRops                       DD DD_ROP_SPACE DUP(?)
    dwSSBCaps                       DD ?
    dwSSBCKeyCaps                   DD ?
    dwSSBFXCaps                     DD ?
    dwSSBRops                       DD DD_ROP_SPACE DUP(?)
    dwMaxVideoPorts                 DD ?
    dwCurrVideoPorts                DD ?
    dwSVBCaps2                      DD ?
    dwNLVBCaps                      DD ?
    dwNLVBCaps2                     DD ?
    dwNLVBCKeyCaps                  DD ?
    dwNLVBFXCaps                    DD ?
    dwNLVBRops                      DD DD_ROP_SPACE DUP(?)
DDCAPS_DX5 ENDS

DDCAPS_DX6 STRUCT ALIGNMODE
    dwSize                          DD ?
    dwCaps                          DD ?
    dwCaps2                         DD ?
    dwCKeyCaps                      DD ?
    dwFXCaps                        DD ?
    dwFXAlphaCaps                   DD ?
    dwPalCaps                       DD ?
    dwSVCaps                        DD ?
    dwAlphaBltConstBitDepths        DD ?
    dwAlphaBltPixelBitDepths        DD ?
    dwAlphaBltSurfaceBitDepths      DD ?
    dwAlphaOverlayConstBitDepths    DD ?
    dwAlphaOverlayPixelBitDepths    DD ?
    dwAlphaOverlaySurfaceBitDepths  DD ?
    dwZBufferBitDepths              DD ?
    dwVidMemTotal                   DD ?
    dwVidMemFree                    DD ?
    dwMaxVisibleOverlays            DD ?
    dwCurrVisibleOverlays           DD ?
    dwNumFourCCCodes                DD ?
    dwAlignBoundarySrc              DD ?
    dwAlignSizeSrc                  DD ?
    dwAlignBoundaryDest             DD ?
    dwAlignSizeDest                 DD ?
    dwAlignStrideAlign              DD ?
    dwRops                          DD DD_ROP_SPACE DUP(?)
    ddsOldCaps                      DDSCAPS <>
    dwMinOverlayStretch             DD ?
    dwMaxOverlayStretch             DD ?
    dwMinLiveVideoStretch           DD ?
    dwMaxLiveVideoStretch           DD ?
    dwMinHwCodecStretch             DD ?
    dwMaxHwCodecStretch             DD ?
    dwReserved1                     DD ?
    dwReserved2                     DD ?
    dwReserved3                     DD ?
    dwSVBCaps                       DD ?
    dwSVBCKeyCaps                   DD ?
    dwSVBFXCaps                     DD ?
    dwSVBRops                       DD DD_ROP_SPACE DUP(?)
    dwVSBCaps                       DD ?
    dwVSBCKeyCaps                   DD ?
    dwVSBFXCaps                     DD ?
    dwVSBRops                       DD DD_ROP_SPACE DUP(?)
    dwSSBCaps                       DD ?
    dwSSBCKeyCaps                   DD ?
    dwSSBFXCaps                     DD ?
    dwSSBRops                       DD DD_ROP_SPACE DUP(?)
    dwMaxVideoPorts                 DD ?
    dwCurrVideoPorts                DD ?
    dwSVBCaps2                      DD ?
    dwNLVBCaps                      DD ?
    dwNLVBCaps2                     DD ?
    dwNLVBCKeyCaps                  DD ?
    dwNLVBFXCaps                    DD ?
    dwNLVBRops                      DD DD_ROP_SPACE DUP(?)
    ddsCaps                         DDSCAPS2 <>
DDCAPS_DX6 ENDS

DDCAPS_DX7 STRUCT ALIGNMODE
    dwSize                          DD ?
    dwCaps                          DD ?
    dwCaps2                         DD ?
    dwCKeyCaps                      DD ?
    dwFXCaps                        DD ?
    dwFXAlphaCaps                   DD ?
    dwPalCaps                       DD ?
    dwSVCaps                        DD ?
    dwAlphaBltConstBitDepths        DD ?
    dwAlphaBltPixelBitDepths        DD ?
    dwAlphaBltSurfaceBitDepths      DD ?
    dwAlphaOverlayConstBitDepths    DD ?
    dwAlphaOverlayPixelBitDepths    DD ?
    dwAlphaOverlaySurfaceBitDepths  DD ?
    dwZBufferBitDepths              DD ?
    dwVidMemTotal                   DD ?
    dwVidMemFree                    DD ?
    dwMaxVisibleOverlays            DD ?
    dwCurrVisibleOverlays           DD ?
    dwNumFourCCCodes                DD ?
    dwAlignBoundarySrc              DD ?
    dwAlignSizeSrc                  DD ?
    dwAlignBoundaryDest             DD ?
    dwAlignSizeDest                 DD ?
    dwAlignStrideAlign              DD ?
    dwRops                          DD DD_ROP_SPACE DUP(?)
    ddsOldCaps                      DDSCAPS <>
    dwMinOverlayStretch             DD ?
    dwMaxOverlayStretch             DD ?
    dwMinLiveVideoStretch           DD ?
    dwMaxLiveVideoStretch           DD ?
    dwMinHwCodecStretch             DD ?
    dwMaxHwCodecStretch             DD ?
    dwReserved1                     DD ?
    dwReserved2                     DD ?
    dwReserved3                     DD ?
    dwSVBCaps                       DD ?
    dwSVBCKeyCaps                   DD ?
    dwSVBFXCaps                     DD ?
    dwSVBRops                       DD DD_ROP_SPACE DUP(?)
    dwVSBCaps                       DD ?
    dwVSBCKeyCaps                   DD ?
    dwVSBFXCaps                     DD ?
    dwVSBRops                       DD DD_ROP_SPACE DUP(?)
    dwSSBCaps                       DD ?
    dwSSBCKeyCaps                   DD ?
    dwSSBFXCaps                     DD ?
    dwSSBRops                       DD DD_ROP_SPACE DUP(?)
    dwMaxVideoPorts                 DD ?
    dwCurrVideoPorts                DD ?
    dwSVBCaps2                      DD ?
    dwNLVBCaps                      DD ?
    dwNLVBCaps2                     DD ?
    dwNLVBCKeyCaps                  DD ?
    dwNLVBFXCaps                    DD ?
    dwNLVBRops                      DD DD_ROP_SPACE DUP(?)
    ddsCaps                         DDSCAPS2 <>
DDCAPS_DX7 ENDS

IF DIRECTDRAW_VERSION LE 0300H
    DDCAPS  EQU <DDCAPS_DX3>
ELSEIF DIRECTDRAW_VERSION LE 0500H
    DDCAPS  EQU <DDCAPS_DX5>
ELSEIF DIRECTDRAW_VERSION LE 0600H
    DDCAPS  EQU <DDCAPS_DX6>
ELSE
    DDCAPS  EQU <DDCAPS_DX7>
ENDIF

DDPIXELFORMAT STRUCT ALIGNMODE
    dwSize                      DD ?
    dwFlags                     DD ?
    dwFourCC                    DD ?
    UNION
        dwRGBBitCount           DD ?
        dwYUVBitCount           DD ?
        dwZBufferBitDepth       DD ?
        dwAlphaBitDepth         DD ?
        dwLuminanceBitCount     DD ?
        dwBumpBitCount          DD ?
    ENDS
    UNION
        dwRBitMask              DD ?
        dwYBitMask              DD ?
        dwStencilBitDepth       DD ?
        dwLuminanceBitMask      DD ?
        dwBumpDuBitMask         DD ?
    ENDS
    UNION
        dwGBitMask              DD ?
        dwUBitMask              DD ?
        dwZBitMask              DD ?
        dwBumpDvBitMask         DD ?
    ENDS
    UNION
        dwBBitMask              DD ?
        dwVBitMask              DD ?
        dwStencilBitMask        DD ?
        dwBumpLuminanceBitMask  DD ?
    ENDS
    UNION
        dwRGBAlphaBitMask       DD ?
        dwYUVAlphaBitMask       DD ?
        dwLuminanceAlphaBitMask DD ?
        dwRGBZBitMask           DD ?
        dwYUVZBitMask           DD ?
    ENDS
DDPIXELFORMAT ENDS

DDOVERLAYFX STRUCT ALIGNMODE
    dwSize                      DD   ?
    dwAlphaEdgeBlendBitDepth    DD   ?
    dwAlphaEdgeBlend            DD   ?
    dwReserved                  DD   ?
    dwAlphaDestConstBitDepth    DD   ?
    UNION
        dwAlphaDestConst        DD   ?
        lpDDSAlphaDest          XPTR ?
    ENDS
    dwAlphaSrcConstBitDepth     DD   ?
    UNION
        dwAlphaSrcConst         DD   ?
        lpDDSAlphaSrc           XPTR   ?
    ENDS
    dckDestColorkey             DDCOLORKEY <>
    dckSrcColorkey              DDCOLORKEY <>
    dwDDFX                      DD   ?
    dwFlags                     DD   ?
DDOVERLAYFX ENDS

DDBLTBATCH STRUCT ALIGNMODE
    lprDest     XPTR ?
    lpDDSSrc    XPTR ?
    lprSrc      XPTR ?
    dwFlags     DD   ?
    lpDDBltFx   XPTR ?
DDBLTBATCH ENDS

DDGAMMARAMP STRUCT ALIGNMODE
    red     DW 256 DUP(?)
    green   DW 256 DUP(?)
    blue    DW 256 DUP(?)
DDGAMMARAMP ENDS

DDDEVICEIDENTIFIER STRUCT ALIGNMODE
    szDriver             DB MAX_DDDEVICEID_STRING DUP(?)
    szDescription        DB MAX_DDDEVICEID_STRING DUP(?)
    liDriverVersion      DQ   ?
    dwVendorId           DD   ?
    dwDeviceId           DD   ?
    dwSubSysId           DD   ?
    dwRevision           DD   ?
    guidDeviceIdentifier GUID <>
DDDEVICEIDENTIFIER ENDS

DDDEVICEIDENTIFIER2 STRUCT ALIGNMODE
    szDriver             DB MAX_DDDEVICEID_STRING DUP(?)
    szDescription        DB MAX_DDDEVICEID_STRING DUP(?)
    liDriverVersion      DQ   ?
    dwVendorId           DD   ?
    dwDeviceId           DD   ?
    dwSubSysId           DD   ?
    dwRevision           DD   ?
    guidDeviceIdentifier GUID <>
    dwWHQLLevel          DD   ?
DDDEVICEIDENTIFIER2 ENDS

IDirectDraw STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    Compact                     XPTR ?
    CreateClipper               XPTR ?
    CreatePalette               XPTR ?
    CreateSurface               XPTR ?
    DuplicateSurface            XPTR ?
    EnumDisplayModes            XPTR ?
    EnumSurfaces                XPTR ?
    FlipToGDISurface            XPTR ?
    GetCaps                     XPTR ?
    GetDisplayMode              XPTR ?
    GetFourCCCodes              XPTR ?
    GetGDISurface               XPTR ?
    GetMonitorFrequency         XPTR ?
    GetScanLine                 XPTR ?
    GetVerticalBlankStatus      XPTR ?
    Initialize                  XPTR ?
    RestoreDisplayMode          XPTR ?
    SetCooperativeLevel         XPTR ?
    SetDisplayMode              XPTR ?
    WaitForVerticalBlank        XPTR ?
IDirectDraw ENDS

IDirectDraw2 STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    Compact                     XPTR ?
    CreateClipper               XPTR ?
    CreatePalette               XPTR ?
    CreateSurface               XPTR ?
    DuplicateSurface            XPTR ?
    EnumDisplayModes            XPTR ?
    EnumSurfaces                XPTR ?
    FlipToGDISurface            XPTR ?
    GetCaps                     XPTR ?
    GetDisplayMode              XPTR ?
    GetFourCCCodes              XPTR ?
    GetGDISurface               XPTR ?
    GetMonitorFrequency         XPTR ?
    GetScanLine                 XPTR ?
    GetVerticalBlankStatus      XPTR ?
    Initialize                  XPTR ?
    RestoreDisplayMode          XPTR ?
    SetCooperativeLevel         XPTR ?
    SetDisplayMode              XPTR ?
    WaitForVerticalBlank        XPTR ?
    GetAvailableVidMem          XPTR ?
IDirectDraw2 ENDS

IDirectDraw4 STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    Compact                     XPTR ?
    CreateClipper               XPTR ?
    CreatePalette               XPTR ?
    CreateSurface               XPTR ?
    DuplicateSurface            XPTR ?
    EnumDisplayModes            XPTR ?
    EnumSurfaces                XPTR ?
    FlipToGDISurface            XPTR ?
    GetCaps                     XPTR ?
    GetDisplayMode              XPTR ?
    GetFourCCCodes              XPTR ?
    GetGDISurface               XPTR ?
    GetMonitorFrequency         XPTR ?
    GetScanLine                 XPTR ?
    GetVerticalBlankStatus      XPTR ?
    Initialize                  XPTR ?
    RestoreDisplayMode          XPTR ?
    SetCooperativeLevel         XPTR ?
    SetDisplayMode              XPTR ?
    WaitForVerticalBlank        XPTR ?
    GetAvailableVidMem          XPTR ?
    GetSurfaceFromDC            XPTR ?
    RestoreAllSurfaces          XPTR ?
    TestCooperativeLevel        XPTR ?
    GetDeviceIdentifier         XPTR ?
IDirectDraw4 ENDS

IDirectDraw7 STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    Compact                     XPTR ?
    CreateClipper               XPTR ?
    CreatePalette               XPTR ?
    CreateSurface               XPTR ?
    DuplicateSurface            XPTR ?
    EnumDisplayModes            XPTR ?
    EnumSurfaces                XPTR ?
    FlipToGDISurface            XPTR ?
    GetCaps                     XPTR ?
    GetDisplayMode              XPTR ?
    GetFourCCCodes              XPTR ?
    GetGDISurface               XPTR ?
    GetMonitorFrequency         XPTR ?
    GetScanLine                 XPTR ?
    GetVerticalBlankStatus      XPTR ?
    Initialize                  XPTR ?
    RestoreDisplayMode          XPTR ?
    SetCooperativeLevel         XPTR ?
    SetDisplayMode              XPTR ?
    WaitForVerticalBlank        XPTR ?
    GetAvailableVidMem          XPTR ?
    GetSurfaceFromDC            XPTR ?
    RestoreAllSurfaces          XPTR ?
    TestCooperativeLevel        XPTR ?
    GetDeviceIdentifier         XPTR ?
    StartModeTest               XPTR ?
    EvaluateMode                XPTR ?
IDirectDraw7 ENDS

IDirectDrawPalette STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    GetCaps                     XPTR ?
    GetEntries                  XPTR ?
    Initialize                  XPTR ?
    SetEntries                  XPTR ?
IDirectDrawPalette ENDS

IDirectDrawClipper STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    GetClipList                 XPTR ?
    GetHWnd                     XPTR ?
    Initialize                  XPTR ?
    IsClipListChanged           XPTR ?
    SetClipList                 XPTR ?
    SetHWnd                     XPTR ?
IDirectDrawClipper ENDS

IDirectDrawSurface STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    AddAttachedSurface          XPTR ?
    AddOverlayDirtyRect         XPTR ?
    Blt                         XPTR ?
    BltBatch                    XPTR ?
    BltFast                     XPTR ?
    DeleteAttachedSurface       XPTR ?
    EnumAttachedSurfaces        XPTR ?
    EnumOverlayZOrders          XPTR ?
    Flip                        XPTR ?
    GetAttachedSurface          XPTR ?
    GetBltStatus                XPTR ?
    GetCaps                     XPTR ?
    GetClipper                  XPTR ?
    GetColorKey                 XPTR ?
    GetDC                       XPTR ?
    GetFlipStatus               XPTR ?
    GetOverlayPosition          XPTR ?
    GetPalette                  XPTR ?
    GetPixelFormat              XPTR ?
    GetSurfaceDesc              XPTR ?
    Initialize                  XPTR ?
    IsLost                      XPTR ?
    Lock                        XPTR ?
    ReleaseDC                   XPTR ?
    Restore                     XPTR ?
    SetClipper                  XPTR ?
    SetColorKey                 XPTR ?
    SetOverlayPosition          XPTR ?
    SetPalette                  XPTR ?
    Unlock                      XPTR ?
    UpdateOverlay               XPTR ?
    UpdateOverlayDisplay        XPTR ?
    UpdateOverlayZOrder         XPTR ?
IDirectDrawSurface ENDS

IDirectDrawSurface2 STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    AddAttachedSurface          XPTR ?
    AddOverlayDirtyRect         XPTR ?
    Blt                         XPTR ?
    BltBatch                    XPTR ?
    BltFast                     XPTR ?
    DeleteAttachedSurface       XPTR ?
    EnumAttachedSurfaces        XPTR ?
    EnumOverlayZOrders          XPTR ?
    Flip                        XPTR ?
    GetAttachedSurface          XPTR ?
    GetBltStatus                XPTR ?
    GetCaps                     XPTR ?
    GetClipper                  XPTR ?
    GetColorKey                 XPTR ?
    GetDC                       XPTR ?
    GetFlipStatus               XPTR ?
    GetOverlayPosition          XPTR ?
    GetPalette                  XPTR ?
    GetPixelFormat              XPTR ?
    GetSurfaceDesc              XPTR ?
    Initialize                  XPTR ?
    IsLost                      XPTR ?
    Lock                        XPTR ?
    ReleaseDC                   XPTR ?
    Restore                     XPTR ?
    SetClipper                  XPTR ?
    SetColorKey                 XPTR ?
    SetOverlayPosition          XPTR ?
    SetPalette                  XPTR ?
    Unlock                      XPTR ?
    UpdateOverlay               XPTR ?
    UpdateOverlayDisplay        XPTR ?
    UpdateOverlayZOrder         XPTR ?
    GetDDInterface              XPTR ?
    PageLock                    XPTR ?
    PageUnlock                  XPTR ?
IDirectDrawSurface2 ENDS

IDirectDrawSurface3 STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    AddAttachedSurface          XPTR ?
    AddOverlayDirtyRect         XPTR ?
    Blt                         XPTR ?
    BltBatch                    XPTR ?
    BltFast                     XPTR ?
    DeleteAttachedSurface       XPTR ?
    EnumAttachedSurfaces        XPTR ?
    EnumOverlayZOrders          XPTR ?
    Flip                        XPTR ?
    GetAttachedSurface          XPTR ?
    GetBltStatus                XPTR ?
    GetCaps                     XPTR ?
    GetClipper                  XPTR ?
    GetColorKey                 XPTR ?
    GetDC                       XPTR ?
    GetFlipStatus               XPTR ?
    GetOverlayPosition          XPTR ?
    GetPalette                  XPTR ?
    GetPixelFormat              XPTR ?
    GetSurfaceDesc              XPTR ?
    Initialize                  XPTR ?
    IsLost                      XPTR ?
    Lock                        XPTR ?
    ReleaseDC                   XPTR ?
    Restore                     XPTR ?
    SetClipper                  XPTR ?
    SetColorKey                 XPTR ?
    SetOverlayPosition          XPTR ?
    SetPalette                  XPTR ?
    Unlock                      XPTR ?
    UpdateOverlay               XPTR ?
    UpdateOverlayDisplay        XPTR ?
    UpdateOverlayZOrder         XPTR ?
    GetDDInterface              XPTR ?
    PageLock                    XPTR ?
    PageUnlock                  XPTR ?
    SetSurfaceDesc              XPTR ?
IDirectDrawSurface3 ENDS

IDirectDrawSurface4 STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    AddAttachedSurface          XPTR ?
    AddOverlayDirtyRect         XPTR ?
    Blt                         XPTR ?
    BltBatch                    XPTR ?
    BltFast                     XPTR ?
    DeleteAttachedSurface       XPTR ?
    EnumAttachedSurfaces        XPTR ?
    EnumOverlayZOrders          XPTR ?
    Flip                        XPTR ?
    GetAttachedSurface          XPTR ?
    GetBltStatus                XPTR ?
    GetCaps                     XPTR ?
    GetClipper                  XPTR ?
    GetColorKey                 XPTR ?
    GetDC                       XPTR ?
    GetFlipStatus               XPTR ?
    GetOverlayPosition          XPTR ?
    GetPalette                  XPTR ?
    GetPixelFormat              XPTR ?
    GetSurfaceDesc              XPTR ?
    Initialize                  XPTR ?
    IsLost                      XPTR ?
    Lock                        XPTR ?
    ReleaseDC                   XPTR ?
    Restore                     XPTR ?
    SetClipper                  XPTR ?
    SetColorKey                 XPTR ?
    SetOverlayPosition          XPTR ?
    SetPalette                  XPTR ?
    Unlock                      XPTR ?
    UpdateOverlay               XPTR ?
    UpdateOverlayDisplay        XPTR ?
    UpdateOverlayZOrder         XPTR ?
    GetDDInterface              XPTR ?
    PageLock                    XPTR ?
    PageUnlock                  XPTR ?
    SetSurfaceDesc              XPTR ?
    SetPrivateData              XPTR ?
    GetPrivateData              XPTR ?
    FreePrivateData             XPTR ?
    GetUniquenessValue          XPTR ?
    ChangeUniquenessValue       XPTR ?
IDirectDrawSurface4 ENDS

IDirectDrawSurface7 STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    AddAttachedSurface          XPTR ?
    AddOverlayDirtyRect         XPTR ?
    Blt                         XPTR ?
    BltBatch                    XPTR ?
    BltFast                     XPTR ?
    DeleteAttachedSurface       XPTR ?
    EnumAttachedSurfaces        XPTR ?
    EnumOverlayZOrders          XPTR ?
    Flip                        XPTR ?
    GetAttachedSurface          XPTR ?
    GetBltStatus                XPTR ?
    GetCaps                     XPTR ?
    GetClipper                  XPTR ?
    GetColorKey                 XPTR ?
    GetDC                       XPTR ?
    GetFlipStatus               XPTR ?
    GetOverlayPosition          XPTR ?
    GetPalette                  XPTR ?
    GetPixelFormat              XPTR ?
    GetSurfaceDesc              XPTR ?
    Initialize                  XPTR ?
    IsLost                      XPTR ?
    Lock                        XPTR ?
    ReleaseDC                   XPTR ?
    Restore                     XPTR ?
    SetClipper                  XPTR ?
    SetColorKey                 XPTR ?
    SetOverlayPosition          XPTR ?
    SetPalette                  XPTR ?
    Unlock                      XPTR ?
    UpdateOverlay               XPTR ?
    UpdateOverlayDisplay        XPTR ?
    UpdateOverlayZOrder         XPTR ?
    GetDDInterface              XPTR ?
    PageLock                    XPTR ?
    PageUnlock                  XPTR ?
    SetSurfaceDesc              XPTR ?
    SetPrivateData              XPTR ?
    GetPrivateData              XPTR ?
    FreePrivateData             XPTR ?
    GetUniquenessValue          XPTR ?
    ChangeUniquenessValue       XPTR ?
    SetPriority                 XPTR ?
    GetPriority                 XPTR ?
    SetLOD                      XPTR ?
    GetLOD                      XPTR ?
IDirectDrawSurface7 ENDS

IDirectDrawColorControl STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    GetColorControls            XPTR ?
    SetColorControls            XPTR ?
IDirectDrawColorControl ENDS

IDirectDrawGammaControl STRUCT ALIGNMODE
    UNION
        STRUCT
            QueryInterface      XPTR ?
            AddRef              XPTR ?
            Release             XPTR ?
        ENDS
        IUnknown                Unknown <>
    ENDS
    GetGammaRamp                XPTR ?
    SetGammaRamp                XPTR ?
IDirectDrawGammaControl ENDS

DDSURFACEDESC STRUCT ALIGNMODE
    dwSize                  DD   ?
    dwFlags                 DD   ?
    dwHeight                DD   ?
    dwWidth                 DD   ?
    UNION
        lPitch              DD   ?
        dwLinearSize        DD   ?
    ENDS
    dwBackBufferCount       DD   ?
    UNION
        dwMipMapCount       DD   ?
        dwZBufferBitDepth   DD   ?
        dwRefreshRate       DD   ?
    ENDS
    dwAlphaBitDepth         DD   ?
    dwReserved              DD   ?
    lpSurface               XPTR ?
    ddckCKDestOverlay       DDCOLORKEY <>
    ddckCKDestBlt           DDCOLORKEY <>
    ddckCKSrcOverlay        DDCOLORKEY <>
    ddckCKSrcBlt            DDCOLORKEY <>
    ddpfPixelFormat         DDPIXELFORMAT <>
    ddsCaps                 DDSCAPS <>
DDSURFACEDESC ENDS

DDSURFACEDESC2 STRUCT ALIGNMODE
    dwSize                  DD   ?
    dwFlags                 DD   ?
    dwHeight                DD   ?
    dwWidth                 DD   ?
    UNION
        lPitch              DD   ?
        dwLinearSize        DD   ?
    ENDS
    dwBackBufferCount       DD   ?
    UNION
        dwMipMapCount       DD   ?
        dwRefreshRate       DD   ?
        dwSrcVBHandle       DD   ?
    ENDS
    dwAlphaBitDepth         DD   ?
    dwReserved              DD   ?
    lpSurface               XPTR ?
    UNION
        ddckCKDestOverlay   DDCOLORKEY <>
        dwEmptyFaceColor    DD   ?
    ENDS
    ddckCKDestBlt           DDCOLORKEY <>
    ddckCKSrcOverlay        DDCOLORKEY <>
    ddckCKSrcBlt            DDCOLORKEY <>
    UNION
        ddpfPixelFormat     DDPIXELFORMAT <>
        dwFVF               DD   ?
    ENDS
    ddsCaps                 DDSCAPS2 <>
    dwTextureStage          DD   ?
DDSURFACEDESC2 ENDS

DDOPTSURFACEDESC STRUCT ALIGNMODE
    dwSize              DD   ?
    dwFlags             DD   ?
    ddSCaps             DDSCAPS2 <>
    ddOSCaps            DDOSCAPS <>
    guid                GUID <>
    dwCompressionRatio  DD   ?
DDOPTSURFACEDESC ENDS

DDCOLORCONTROL STRUCT ALIGNMODE
    dwSize          DD ?
    dwFlags         DD ?
    lBrightness     DD ?
    lContrast       DD ?
    lHue            DD ?
    lSaturation     DD ?
    lSharpness      DD ?
    lGamma          DD ?
    lColorEnable    DD ?
    dwReserved1     DD ?
DDCOLORCONTROL ENDS

;======================================== Functions =======================================;
AcquireDDThreadLock PROTO
D3DParseUnknownCommand PROTO :QWORD,:QWORD
DDGetAttachedSurfaceLcl PROTO :QWORD,:QWORD,:QWORD
DDInternalLock PROTO :QWORD,:QWORD
DDInternalUnlock PROTO :QWORD
DSoundHelp PROTO :QWORD,:QWORD,:QWORD
DirectDrawCreate PROTO :QWORD,:QWORD,:QWORD
DirectDrawCreateClipper PROTO :QWORD,:QWORD,:QWORD
DirectDrawCreateEx PROTO :QWORD,:QWORD,:QWORD,:QWORD
DirectDrawEnumerateA PROTO :QWORD,:QWORD
DirectDrawEnumerateExA PROTO :QWORD,:QWORD,:QWORD
DirectDrawEnumerateExW PROTO :QWORD,:QWORD,:QWORD
DirectDrawEnumerateW PROTO :QWORD,:QWORD
GetDDSurfaceLocal PROTO :QWORD,:QWORD,:QWORD
GetSurfaceFromDC PROTO :QWORD,:QWORD,:QWORD
ReleaseDDThreadLock PROTO

IFDEF APP_UNICODE
    DirectDrawEnumerate EQU <DirectDrawEnumerateW>
    DirectDrawEnumerateEx EQU <DirectDrawEnumerateExW>
ELSE
    DirectDrawEnumerate EQU <DirectDrawEnumerateA>
    DirectDrawEnumerateEx EQU <DirectDrawEnumerateExA>
ENDIF

;======================= Undocumented functions (unknown arguments) =======================;
;CompleteCreateSysmemSurface PROTO
;GetOLEThunkData PROTO
;RegisterSpecialCase PROTO
;ReleaseDDThreadLock PROTO
;IF (NTDDI_VERSION GE NTDDI_WIN7)
;    SetAppCompatData PROTO
;ENDIF

;====================================== GUID values =======================================;
.Data
GUID_CLSID_DirectDraw                           GUID    <0D7B70EE0H,04340H,011CFH,{0B0H,063H,000H,020H,0AFH,0C2H,0CDH,035H}>
GUID_CLSID_DirectDraw7                          GUID    <03C305196H,050DBH,011D3H,{09CH,0FEH,000H,0C0H,04FH,0D9H,030H,0C5H}>
GUID_CLSID_DirectDrawClipper                    GUID    <0593817A0H,07DB3H,011CFH,{0A2H,0DEH,000H,0AAH,000H,0b9H,033H,056H}>
GUID_IID_IDirectDraw                            GUID    <06C14DB80H,0A733H,011CEH,{0A5H,021H,000H,020H,0AFH,00BH,0E5H,060H}>
GUID_IID_IDirectDraw2                           GUID    <0B3A6F3E0H,02B43H,011CFH,{0A2H,0DEH,000H,0AAH,000H,0B9H,033H,056H}>
GUID_IID_IDirectDraw4                           GUID    <09C59509AH,039BDH,011D1H,{08CH,04AH,000H,0C0H,04FH,0D9H,030H,0C5H}>
GUID_IID_IDirectDraw7                           GUID    <015E65EC0H,03B9CH,011D2H,{0B9H,02FH,000H,060H,097H,097H,0EAH,05BH}>
GUID_IID_IDirectDrawSurface                     GUID    <06C14DB81H,0A733H,011CEH,{0A5H,021H,000H,020H,0AFH,00BH,0E5H,060H}>
GUID_IID_IDirectDrawSurface2                    GUID    <057805885H,06eecH,011cfH,{094H,041H,0a8H,023H,003H,0c1H,00eH,027H}>
GUID_IID_IDirectDrawSurface3                    GUID    <0DA044E00H,069B2H,011D0H,{0A1H,0D5H,000H,0AAH,000H,0B8H,0DFH,0BBH}>
GUID_IID_IDirectDrawSurface4                    GUID    <00B2B8630H,0AD35H,011D0H,{08EH,0A6H,000H,060H,097H,097H,0EAH,05BH}>
GUID_IID_IDirectDrawSurface7                    GUID    <006675a80H,03b9bH,011d2H,{0b9H,02fH,000H,060H,097H,097H,0eaH,05bH}>
GUID_IID_IDirectDrawPalette                     GUID    <06C14DB84H,0A733H,011CEH,{0A5H,021H,000H,020H,0AFH,00BH,0E5H,060H}>
GUID_IID_IDirectDrawClipper                     GUID    <06C14DB85H,0A733H,011CEH,{0A5H,021H,000H,020H,0AFH,00BH,0E5H,060H}>
GUID_IID_IDirectDrawColorControl                GUID    <04B9F0EE0H,00D7EH,011D0H,{09BH,006H,000H,0A0H,0C9H,003H,0A3H,0B8H}>
GUID_IID_IDirectDrawGammaControl                GUID    <069C11C3EH,0B46BH,011D1H,{0ADH,07AH,000H,0C0H,04FH,0C2H,09BH,04EH}>

ENDIF ;DDRAW_INC
