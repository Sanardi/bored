; ====================================================;
;                                                     ;
;       lz32.inc for EC v2 Fasm visual projects       ;
;                   (version 1.0.1)                   ;
;                                                     ;
;            Copyright © Ramon Sala - 2018            ;
;                                                     ;
; ====================================================;

if ~defined LZ32_INC
define LZ32_INC 1

LZERROR_BADINHANDLE                             equ     (-1)
LZERROR_BADOUTHANDLE                            equ     (-2)
LZERROR_READ                                    equ     (-3)
LZERROR_WRITE                                   equ     (-4)
LZERROR_GLOBALLOC                               equ     (-5)
LZERROR_GLOBLOCK                                equ     (-6)
LZERROR_BADVALUE                                equ     (-7)
LZERROR_UNKNOWNALG                              equ     (-8)


;======================================== Functions =======================================;
if defined APP_WIN64
    extrn '__imp_CopyLZFile' as CopyLZFile:qword
    extrn '__imp_GetExpandedNameA' as GetExpandedNameA:qword
    extrn '__imp_GetExpandedNameW' as GetExpandedNameW:qword
    extrn '__imp_LZClose' as LZClose:qword
    extrn '__imp_LZCloseFile' as LZCloseFile:qword
    extrn '__imp_LZCopy' as LZCopy:qword
    extrn '__imp_LZCreateFileW' as LZCreateFileW:qword
    extrn '__imp_LZDone' as LZDone:qword
    extrn '__imp_LZInit' as LZInit:qword
    extrn '__imp_LZOpenFileA' as LZOpenFileA:qword
    extrn '__imp_LZOpenFileW' as LZOpenFileW:qword
    extrn '__imp_LZRead' as LZRead:qword
    extrn '__imp_LZSeek' as LZSeek:qword
    extrn '__imp_LZStart' as LZStart:qword
else
    extrn '__imp__CopyLZFile@8' as CopyLZFile:dword
    extrn '__imp__GetExpandedNameA@8' as GetExpandedNameA:dword
    extrn '__imp__GetExpandedNameW@8' as GetExpandedNameW:dword
    extrn '__imp__LZClose@4' as LZClose:dword
    extrn '__imp__LZCloseFile@4' as LZCloseFile:dword
    extrn '__imp__LZCopy@8' as LZCopy:dword
    extrn '__imp__LZCreateFileW@20' as LZCreateFileW:dword
    extrn '__imp__LZDone@0' as LZDone:dword
    extrn '__imp__LZInit@4' as LZInit:dword
    extrn '__imp__LZOpenFileA@12' as LZOpenFileA:dword
    extrn '__imp__LZOpenFileW@12' as LZOpenFileW:dword
    extrn '__imp__LZRead@12' as LZRead:dword
    extrn '__imp__LZSeek@12' as LZSeek:dword
    extrn '__imp__LZStart@0' as LZStart:dword
end if

LZCreateFile equ LZCreateFileW
api GetExpandedName,\
    LZOpenFile

end if ;LZ32_INC
