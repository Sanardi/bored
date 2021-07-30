; ====================================================;
;                                                     ;
;      lz32.inc for EC v2 Fasm classic projects       ;
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
import lz32,\
CopyLZFile,'CopyLZFile',\
GetExpandedNameA,'GetExpandedNameA',\
GetExpandedNameW,'GetExpandedNameW',\
LZClose,'LZClose',\
LZCloseFile,'LZCloseFile',\
LZCopy,'LZCopy',\
LZCreateFileW,'LZCreateFileW',\
LZDone,'LZDone',\
LZInit,'LZInit',\
LZOpenFileA,'LZOpenFileA',\
LZOpenFileW,'LZOpenFileW',\
LZRead,'LZRead',\
LZSeek,'LZSeek',\
LZStart,'LZStart'

LZCreateFile equ LZCreateFileW
api GetExpandedName,\
    LZOpenFile

end if ;LZ32_INC
