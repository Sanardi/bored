;===================================================================;
;                                                                   ;
;    tvout.inc for Easy Code 2.0 JWasm/Masm/PoAsm 32-bit drivers    ;
;                        (version 1.0.0)                            ;
;                                                                   ;
;                 Driver Development Kit (32-bit)                   ;
;                                                                   ;
;                  Copyright © Ramon Sala - 2015                    ;
;                                                                   ;
;===================================================================;

IFNDEF TVOUT_INC
TVOUT_INC Equ 1

IFNDEF GUID_DEFINED
    Include guiddef.inc
ENDIF

VP_COMMAND_GET                              Equ         00000001H
VP_COMMAND_SET                              Equ         00000002H

VP_FLAGS_TV_MODE                            Equ         00000001H
VP_FLAGS_TV_STANDARD                        Equ         00000002H
VP_FLAGS_FLICKER                            Equ         00000004H
VP_FLAGS_OVERSCAN                           Equ         00000008H
VP_FLAGS_MAX_UNSCALED                       Equ         00000010H
VP_FLAGS_POSITION                           Equ         00000020H
VP_FLAGS_BRIGHTNESS                         Equ         00000040H
VP_FLAGS_CONTRAST                           Equ         00000080H
VP_FLAGS_COPYPROTECT                        Equ         00000100H

VP_MODE_WIN_GRAPHICS                        Equ         00000001H
VP_MODE_TV_PLAYBACK                         Equ         00000002H

VP_TV_STANDARD_NTSC_M                       Equ         00000001H
VP_TV_STANDARD_NTSC_M_J                     Equ         00000002H
VP_TV_STANDARD_PAL_B                        Equ         00000004H
VP_TV_STANDARD_PAL_D                        Equ         00000008H
VP_TV_STANDARD_PAL_H                        Equ         00000010H
VP_TV_STANDARD_PAL_I                        Equ         00000020H
VP_TV_STANDARD_PAL_M                        Equ         00000040H
VP_TV_STANDARD_PAL_N                        Equ         00000080H
VP_TV_STANDARD_SECAM_B                      Equ         00000100H
VP_TV_STANDARD_SECAM_D                      Equ         00000200H
VP_TV_STANDARD_SECAM_G                      Equ         00000400H
VP_TV_STANDARD_SECAM_H                      Equ         00000800H
VP_TV_STANDARD_SECAM_K                      Equ         00001000H
VP_TV_STANDARD_SECAM_K1                     Equ         00002000H
VP_TV_STANDARD_SECAM_L                      Equ         00004000H
VP_TV_STANDARD_WIN_VGA                      Equ         00008000H
VP_TV_STANDARD_NTSC_433                     Equ         00010000H
VP_TV_STANDARD_PAL_G                        Equ         00020000H
VP_TV_STANDARD_PAL_60                       Equ         00040000H
VP_TV_STANDARD_SECAM_L1                     Equ         00080000H

VP_CP_TYPE_APS_TRIGGER                      Equ         00000001H
VP_CP_TYPE_MACROVISION                      Equ         00000002H

VP_CP_CMD_ACTIVATE                          Equ         00000001H
VP_CP_CMD_DEACTIVATE                        Equ         00000002H
VP_CP_CMD_CHANGE                            Equ         00000004H

VIDEOPARAMETERS Struct
    Guid                                    GUID        <>
    dwOffset                                DD          ?
    dwCommand                               DD          ?
    dwFlags                                 DD          ?
    dwMode                                  DD          ?
    dwTVStandard                            DD          ?
    dwAvailableModes                        DD          ?
    dwAvailableTVStandard                   DD          ?
    dwFlickerFilter                         DD          ?
    dwOverScanX                             DD          ?
    dwOverScanY                             DD          ?
    dwMaxUnscaledX                          DD          ?
    dwMaxUnscaledY                          DD          ?
    dwPositionX                             DD          ?
    dwPositionY                             DD          ?
    dwBrightness                            DD          ?
    dwContrast                              DD          ?
    dwCPType                                DD          ?
    dwCPCommand                             DD          ?
    dwCPStandard                            DD          ?
    dwCPKey                                 DD          ?
    bCP_APSTriggerBits                      DB          ?
    bOEMCopyProtection                      DB          256 Dup(?)
VIDEOPARAMETERS EndS
PVIDEOPARAMETERS                            TypeDef     DWord
LPVIDEOPARAMETERS                           TypeDef     DWord

ENDIF ;TVOUT_INC
