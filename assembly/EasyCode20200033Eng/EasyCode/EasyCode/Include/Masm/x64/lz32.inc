; ====================================================;
;                                                     ;
;   lz32.inc for Easy Code 2.0 64-bit Masm projects   ;
;                  (version 1.0.1)                    ;
;                                                     ;
;            Copyright © Ramon Sala - 2018            ;
;                                                     ;
; ====================================================;

IFNDEF LZ32_INC
LZ32_INC   EQU     1

LZERROR_BADINHANDLE                             EQU     (-1)
LZERROR_BADOUTHANDLE                            EQU     (-2)
LZERROR_READ                                    EQU     (-3)
LZERROR_WRITE                                   EQU     (-4)
LZERROR_GLOBALLOC                               EQU     (-5)
LZERROR_GLOBLOCK                                EQU     (-6)
LZERROR_BADVALUE                                EQU     (-7)
LZERROR_UNKNOWNALG                              EQU     (-8)


;======================================== Functions =======================================;
CopyLZFile PROTO :XWORD, :XWORD
GetExpandedNameA PROTO :XWORD, :XWORD
GetExpandedNameW PROTO :XWORD, :XWORD
LZClose PROTO :XWORD
LZCloseFile PROTO :XWORD
LZCopy PROTO :XWORD, :XWORD
LZCreateFileW PROTO :XWORD, :XWORD, :XWORD, :XWORD, :XWORD
LZDone PROTO
LZInit PROTO :XWORD
LZOpenFileA PROTO :XWORD, :XWORD, :XWORD
LZOpenFileW PROTO :XWORD, :XWORD, :XWORD
LZRead PROTO :XWORD, :XWORD, :XWORD
LZSeek PROTO :XWORD, :XWORD, :XWORD
LZStart PROTO

LZCreateFile EQU <LZCreateFileW>
IFDEF APP_UNICODE
    GetExpandedName EQU <GetExpandedNameW>
    LZOpenFile EQU <LZOpenFileW>
ELSE
    GetExpandedName EQU <GetExpandedNameA>
    LZOpenFile EQU <LZOpenFileA>
ENDIF

ENDIF ;LZ32_INC
