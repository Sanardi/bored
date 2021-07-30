; =======================================================;
;                                                        ;
;   version.inc for Easy Code 2.0 64-bit Masm projects   ;
;                  (version 1.0.1)                       ;
;                                                        ;
;           Copyright © Ramon Sala - 2015-2018           ;
;                                                        ;
; =======================================================;

IFNDEF VERSION_INC
VERSION_INC EQU     1

IFNDEF RT_VERSION
    RT_VERSION                                  EQU     16
ENDIF

VS_FILE_INFO                                    EQU     RT_VERSION
VS_VERSION_INFO                                 EQU     1
VS_USER_DEFINED                                 EQU     100

VS_FFI_SIGNATURE                                EQU     0FEEF04BDH
VS_FFI_STRUCVERSION                             EQU     000010000H
VS_FFI_FILEFLAGSMASK                            EQU     00000003FH

VS_FF_DEBUG                                     EQU     000000001H
VS_FF_PRERELEASE                                EQU     000000002H
VS_FF_PATCHED                                   EQU     000000004H
VS_FF_PRIVATEBUILD                              EQU     000000008H
VS_FF_INFOINFERRED                              EQU     000000010H
VS_FF_SPECIALBUILD                              EQU     000000020H

VOS_UNKNOWN                                     EQU     000000000H
VOS_DOS                                         EQU     000010000H
VOS_OS216                                       EQU     000020000H
VOS_OS232                                       EQU     000030000H
VOS_NT                                          EQU     000040000H

VOS__BASE                                       EQU     000000000H
VOS__WINDOWS16                                  EQU     000000001H
VOS__PM16                                       EQU     000000002H
VOS__PM32                                       EQU     000000003H
VOS__WINDOWS32                                  EQU     000000004H

VOS_DOS_WINDOWS16                               EQU     000010001H
VOS_DOS_WINDOWS32                               EQU     000010004H
VOS_OS216_PM16                                  EQU     000020002H
VOS_OS232_PM32                                  EQU     000030003H
VOS_NT_WINDOWS32                                EQU     000040004H

VFT_UNKNOWN                                     EQU     0
VFT_APP                                         EQU     1
VFT_DLL                                         EQU     2
VFT_DRV                                         EQU     3
VFT_FONT                                        EQU     4
VFT_VXD                                         EQU     5
VFT_STATIC_LIB                                  EQU     7

VFT2_UNKNOWN                                    EQU     0
VFT2_DRV_PRINTER                                EQU     1
VFT2_DRV_KEYBOARD                               EQU     2
VFT2_DRV_LANGUAGE                               EQU     3
VFT2_DRV_DISPLAY                                EQU     4
VFT2_DRV_MOUSE                                  EQU     5
VFT2_DRV_NETWORK                                EQU     6
VFT2_DRV_SYSTEM                                 EQU     7
VFT2_DRV_INSTALLABLE                            EQU     8
VFT2_DRV_SOUND                                  EQU     9
VFT2_DRV_COMM                                   EQU     10
VFT2_DRV_INPUTMETHOD                            EQU     11

VFT2_FONT_RASTER                                EQU     1
VFT2_FONT_VECTOR                                EQU     2
VFT2_FONT_TRUETYPE                              EQU     3

VFFF_ISSHAREDFILE                               EQU     1

VFF_CURNEDEST                                   EQU     0001H
VFF_FILEINUSE                                   EQU     0002H
VFF_BUFFTOOSMALL                                EQU     0004H

VIFF_FORCEINSTALL                               EQU     0001H
VIFF_DONTDELETEOLD                              EQU     0002H

VIF_TEMPFILE                                    EQU     00000001H
VIF_MISMATCH                                    EQU     00000002H
VIF_SRCOLD                                      EQU     00000004H
VIF_DIFFLANG                                    EQU     00000008H
VIF_DIFFCODEPG                                  EQU     00000010H
VIF_DIFFTYPE                                    EQU     00000020H
VIF_WRITEPROT                                   EQU     00000040H
VIF_FILEINUSE                                   EQU     00000080H
VIF_OUTOFSPACE                                  EQU     00000100H
VIF_ACCESSVIOLATION                             EQU     00000200H
VIF_SHARINGVIOLATION                            EQU     00000400H
VIF_CANNOTCREATE                                EQU     00000800H
VIF_CANNOTDELETE                                EQU     00001000H
VIF_CANNOTRENAME                                EQU     00002000H
VIF_CANNOTDELETECUR                             EQU     00004000H
VIF_OUTOFMEMORY                                 EQU     00008000H
VIF_CANNOTREADSRC                               EQU     00010000H
VIF_CANNOTREADDST                               EQU     00020000H
VIF_BUFFTOOSMALL                                EQU     00040000H

;======================================== Structures ======================================;
VS_FIXEDFILEINFO STRUCT ALIGNMODE
    dwSignature        DD  ?
    dwStrucVersion     DD  ?
    dwFileVersionMS    DD  ?
    dwFileVersionLS    DD  ?
    dwProductVersionMS DD  ?
    dwProductVersionLS DD  ?
    dwFileFlagsMask    DD  ?
    dwFileFlags        DD  ?
    dwFileOS           DD  ?
    dwFileType         DD  ?
    dwFileSubtype      DD  ?
    dwFileDateMS       DD  ?
    dwFileDateLS       DD  ?
VS_FIXEDFILEINFO ENDS

;======================================== Functions =======================================;
GetFileVersionInfoA PROTO :LPTSTR, :XWORD, :XWORD, :LPVOID
GetFileVersionInfoSizeA PROTO :LPTSTR, :LPDWORD
GetFileVersionInfoSizeW PROTO :LPWSTR, :LPDWORD
GetFileVersionInfoW PROTO :LPWSTR, :XWORD, :XWORD, :LPVOID
VerFindFileA PROTO :XWORD, :LPTSTR, :LPTSTR, :LPTSTR, :LPTSTR, :XPTR, :LPTSTR,:XPTR
VerFindFileW PROTO :XWORD, :LPWSTR, :LPWSTR, :LPWSTR, :LPWSTR, :XPTR, :LPWSTR,:XPTR
VerInstallFileA PROTO :XWORD, :LPTSTR, :LPTSTR, :LPTSTR, :LPTSTR, :LPTSTR, :LPTSTR, :XPTR
VerInstallFileW PROTO :XWORD, :LPWSTR, :LPWSTR, :LPWSTR, :LPWSTR, :LPWSTR, :LPWSTR, :XPTR
IFNDEF VerLanguageNameA
    VerLanguageNameA PROTO :XWORD, :LPTSTR, :XWORD
    VerLanguageNameW PROTO :XWORD, :LPWSTR, :XWORD
ENDIF
VerQueryValueA PROTO :LPVOID, :LPTSTR, :LPVOID, :XPTR
VerQueryValueW PROTO :LPVOID, :LPWSTR, :LPVOID, :XPTR

IFDEF APP_UNICODE
    GetFileVersionInfo EQU <GetFileVersionInfoW>
    GetFileVersionInfoSize EQU <GetFileVersionInfoSizeW>
    VerFindFile EQU <VerFindFileW>
    VerInstallFile EQU <VerInstallFileW>
	IFNDEF VerLanguageName
        VerLanguageName EQU <VerLanguageNameW>
    ENDIF
    VerQueryValue EQU <VerQueryValueW>
ELSE
    GetFileVersionInfoSize EQU <GetFileVersionInfoSizeA>
    GetFileVersionInfo EQU <GetFileVersionInfoA>
    VerFindFile EQU <VerFindFileA>
    VerInstallFile EQU <VerInstallFileA>
	IFNDEF VerLanguageName
        VerLanguageName EQU <VerLanguageNameA>
    ENDIF
    VerQueryValue EQU <VerQueryValueA>
ENDIF

ENDIF ;VERSION_INC
