; ====================================================;
;                                                     ;
;    version.inc for EC v2 SolAsm visual projects     ;
;                   (version 1.0.0)                   ;
;                                                     ;
;            Copyright © Ramon Sala - 2018            ;
;                                                     ;
; ====================================================;

#ifndef VERSION_INC
VERSION_INC equ 1

#ifndef RT_VERSION
    RT_VERSION                                  equ     16
#endif

VS_FILE_INFO                                    equ     RT_VERSION
VS_VERSION_INFO                                 equ     1
VS_USER_DEFINED                                 equ     100

VS_FFI_SIGNATURE                                equ     0FEEF04BDH
VS_FFI_STRUCVERSION                             equ     000010000H
VS_FFI_FILEFLAGSMASK                            equ     00000003FH

VS_FF_DEBUG                                     equ     000000001H
VS_FF_PRERELEASE                                equ     000000002H
VS_FF_PATCHED                                   equ     000000004H
VS_FF_PRIVATEBUILD                              equ     000000008H
VS_FF_INFOINFERRED                              equ     000000010H
VS_FF_SPECIALBUILD                              equ     000000020H

VOS_UNKNOWN                                     equ     000000000H
VOS_DOS                                         equ     000010000H
VOS_OS216                                       equ     000020000H
VOS_OS232                                       equ     000030000H
VOS_NT                                          equ     000040000H

VOS__BASE                                       equ     000000000H
VOS__WINDOWS16                                  equ     000000001H
VOS__PM16                                       equ     000000002H
VOS__PM32                                       equ     000000003H
VOS__WINDOWS32                                  equ     000000004H

VOS_DOS_WINDOWS16                               equ     000010001H
VOS_DOS_WINDOWS32                               equ     000010004H
VOS_OS216_PM16                                  equ     000020002H
VOS_OS232_PM32                                  equ     000030003H
VOS_NT_WINDOWS32                                equ     000040004H

VFT_UNKNOWN                                     equ     0
VFT_APP                                         equ     1
VFT_DLL                                         equ     2
VFT_DRV                                         equ     3
VFT_FONT                                        equ     4
VFT_VXD                                         equ     5
VFT_STATIC_LIB                                  equ     7

VFT2_UNKNOWN                                    equ     0
VFT2_DRV_PRINTER                                equ     1
VFT2_DRV_KEYBOARD                               equ     2
VFT2_DRV_LANGUAGE                               equ     3
VFT2_DRV_DISPLAY                                equ     4
VFT2_DRV_MOUSE                                  equ     5
VFT2_DRV_NETWORK                                equ     6
VFT2_DRV_SYSTEM                                 equ     7
VFT2_DRV_INSTALLABLE                            equ     8
VFT2_DRV_SOUND                                  equ     9
VFT2_DRV_COMM                                   equ     10
VFT2_DRV_INPUTMETHOD                            equ     11

VFT2_FONT_RASTER                                equ     1
VFT2_FONT_VECTOR                                equ     2
VFT2_FONT_TRUETYPE                              equ     3

VFFF_ISSHAREDFILE                               equ     1

VFF_CURNEDEST                                   equ     0001H
VFF_FILEINUSE                                   equ     0002H
VFF_BUFFTOOSMALL                                equ     0004H

VIFF_FORCEINSTALL                               equ     0001H
VIFF_DONTDELETEOLD                              equ     0002H

VIF_TEMPFILE                                    equ     00000001H
VIF_MISMATCH                                    equ     00000002H
VIF_SRCOLD                                      equ     00000004H
VIF_DIFFLANG                                    equ     00000008H
VIF_DIFFCODEPG                                  equ     00000010H
VIF_DIFFTYPE                                    equ     00000020H
VIF_WRITEPROT                                   equ     00000040H
VIF_FILEINUSE                                   equ     00000080H
VIF_OUTOFSPACE                                  equ     00000100H
VIF_ACCESSVIOLATION                             equ     00000200H
VIF_SHARINGVIOLATION                            equ     00000400H
VIF_CANNOTCREATE                                equ     00000800H
VIF_CANNOTDELETE                                equ     00001000H
VIF_CANNOTRENAME                                equ     00002000H
VIF_CANNOTDELETECUR                             equ     00004000H
VIF_OUTOFMEMORY                                 equ     00008000H
VIF_CANNOTREADSRC                               equ     00010000H
VIF_CANNOTREADDST                               equ     00020000H
VIF_BUFFTOOSMALL                                equ     00040000H


;======================================== Structures ======================================;
struc VS_FIXEDFILEINFO
    dwSignature        dd ?
    dwStrucVersion     dd ?
    dwFileVersionMS    dd ?
    dwFileVersionLS    dd ?
    dwProductVersionMS dd ?
    dwProductVersionLS dd ?
    dwFileFlagsMask    dd ?
    dwFileFlags        dd ?
    dwFileOS           dd ?
    dwFileType         dd ?
    dwFileSubtype      dd ?
    dwFileDateMS       dd ?
    dwFileDateLS       dd ?
ends


;======================================== Functions =======================================;
#if COFF_FORMAT == 1
    from_lib version.lib
#else
    from_dll version.dll
#endif

#ifdef APP_WIN64
    import GetFileVersionInfoA
    import GetFileVersionInfoSizeA
    import GetFileVersionInfoSizeW
    import GetFileVersionInfoW
    import VerFindFileA
    import VerFindFileW
    import VerInstallFileA
    import VerInstallFileW
    #ifndef VerLanguageNameA
        import VerLanguageNameA
    #endif
    #ifndef VerLanguageNameW
        import VerLanguageNameW
    #endif
    import VerQueryValueA
    import VerQueryValueW
#else
    extern GetFileVersionInfoA alias _GetFileVersionInfoA@16
    extern GetFileVersionInfoSizeA alias _GetFileVersionInfoSizeA@8
    extern GetFileVersionInfoSizeW alias _GetFileVersionInfoSizeW@8
    extern GetFileVersionInfoW alias _GetFileVersionInfoW@16
    extern VerFindFileA alias _VerFindFileA@32
    extern VerFindFileW alias _VerFindFileW@32
    extern VerInstallFileA alias _VerInstallFileA@32
    extern VerInstallFileW alias _VerInstallFileW@32
    #ifndef VerLanguageNameA
        extern VerLanguageNameA alias _VerLanguageNameA@12
    #endif
    #ifndef VerLanguageNameW
        extern VerLanguageNameW alias _VerLanguageNameW@12
    #endif
    extern VerQueryValueA alias _VerQueryValueA@16
    extern VerQueryValueW alias _VerQueryValueW@16
#endif

#ifdef APP_UNICODE
    define GetFileVersionInfo GetFileVersionInfoW
    define GetFileVersionInfoSize GetFileVersionInfoSizeW
    define VerFindFile VerFindFileW
    define VerInstallFile VerInstallFileW
    #ifndef VerLanguageName
        define VerLanguageName VerLanguageNameW
    #endif
    define VerQueryValue VerQueryValueW
#else
    define GetFileVersionInfo GetFileVersionInfoA
    define GetFileVersionInfoSize GetFileVersionInfoSizeA
    define VerFindFile VerFindFileA
    define VerInstallFile VerInstallFileA
    #ifndef VerLanguageName
        define VerLanguageName VerLanguageNameA
    #endif
    define VerQueryValue VerQueryValueA
#endif

#endif ;VERSION_INC
