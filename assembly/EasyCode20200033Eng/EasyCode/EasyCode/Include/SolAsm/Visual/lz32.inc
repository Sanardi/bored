; ====================================================;
;                                                     ;
;      lz32.inc for EC v2 SolAsm visual projects      ;
;                   (version 1.0.0)                   ;
;                                                     ;
;            Copyright © Ramon Sala - 2018            ;
;                                                     ;
; ====================================================;

#ifndef LZ32_INC
LZ32_INC   equ     1

LZERROR_BADINHANDLE                             equ     (-1)
LZERROR_BADOUTHANDLE                            equ     (-2)
LZERROR_READ                                    equ     (-3)
LZERROR_WRITE                                   equ     (-4)
LZERROR_GLOBALLOC                               equ     (-5)
LZERROR_GLOBLOCK                                equ     (-6)
LZERROR_BADVALUE                                equ     (-7)
LZERROR_UNKNOWNALG                              equ     (-8)


;======================================== Functions =======================================;
#if COFF_FORMAT == 1
    from_lib lz32.lib
#else
    from_dll lz32.dll
#endif

#ifdef APP_WIN64
    import CopyLZFile
    import GetExpandedNameA
    import GetExpandedNameW
    import LZClose
    import LZCloseFile
    import LZCopy
    import LZCreateFileW
    import LZDone
    import LZInit
    import LZOpenFileA
    import LZOpenFileW
    import LZRead
    import LZSeek
    import LZStart
#else
    extern CopyLZFile alias _CopyLZFile@8
    extern GetExpandedNameA alias _GetExpandedNameA@8
    extern GetExpandedNameW alias _GetExpandedNameW@8
    extern LZClose alias _LZClose@4
    extern LZCloseFile alias _LZCloseFile@4
    extern LZCopy alias _LZCopy@8
    extern LZCreateFileW alias _LZCreateFileW@20
    extern LZDone alias _LZDone@0
    extern LZInitalias alias _LZInit@4
    extern LZOpenFileA alias _LZOpenFileA@12
    extern LZOpenFileW alias _LZOpenFileW@12
    extern LZRead alias _LZRead@12
    extern LZSeek alias _LZSeek@12
    extern LZStart alias _LZStart@0
#endif

define LZCreateFile LZCreateFileW
#ifdef APP_UNICODE
    define GetExpandedName GetExpandedNameW
    define LZOpenFile LZOpenFileW
#else
    define GetExpandedName GetExpandedNameA
    define LZOpenFile LZOpenFileA
#endif

#endif ;LZ32_INC
