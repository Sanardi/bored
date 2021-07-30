; ======================================================;
;                                                       ;
;   macros.inc for Easy Code 2.0 64-bit Masm projects   ;
;                  (version 1.0.1)                      ;
;                                                       ;
;          Copyright © Ramon Sala - 2015-2018           ;
;                                                       ;
; ======================================================;

IFNDEF MACROS_INC
MACROS_INC     EQU     1

A MACRO quoted_text:VARARG
    LOCAL ECDnameA
.data
    ECDnameA db quoted_text,0
.code
    EXITM <offset ECDnameA>
ENDM

IFDEF POASM_COMPILER
    L MACRO quoted_text:VARARG
        Local ECvnameW
        Local cnt,arg,carac,wlen,tipo

        strsinpar equ <>
        DWdef  equ <>
        cnt=0

    .Data
        IFDEF APP_WIN64
           Align 16
        ELSE
           Align 4
        ENDIF
    .Code

        DWdef CATSTR <ECvnameW DW  >

        FOR strsinpar, <quoted_text>
            tipo = OpAttr strsinpar
            IF tipo EQ 24H
                IF cnt GT 30
                    cnt=0 
    .Data
                    DWdef
                    DWdef TEXTEQU < DW >
    .Code
                ENDIF
                cnt=cnt+1
                IF cnt NE 1
                    DWdef CATSTR DWdef,<,>
                ENDIF
                DWdef CatStr DWdef, strsinpar
            ELSEIF tipo EQ 8020H
                wlen= @SizeStr(strsinpar)
                carac= 0
                While carac LT wlen
                    carac = carac + 1
                    arg  SubStr strsinpar, carac, 1
                    IF cnt GT 30
                        cnt=0
    .Data
                        DWdef
                        DWdef TextEqu < DW >
    .Code
                    ENDIF
                    cnt= cnt + 1
                    IF cnt NE 1
                        DWdef CatStr DWdef, <,>
                    ENDIF
                    DWdef CatStr DWdef, <">,arg,<">
                EndM
            ELSE
                .Echo <ERROR - Invalid Argument>
            ENDIF
        EndM
        IF cnt NE 0
            DWdef CatStr DWdef, <,>
        ENDIF
        DWdef CATSTR DWdef,<00>
    .Data
        DWdef
    .Code
        ExitM <Offset ECvnameW>
    ENDM
ELSE
    L MACRO quoted_text:VARARG
        Local ECDnameW
        Local cnt,comilla
        Local arg

        strsinpar EQU <>
        DWdef  EQU <>
        cnt=0
        comilla=0

    .Data
        Align ALIGNMODE
    .Code

        DWdef CATSTR <ECDnameW DW  >

        FOR strsinpar,<quoted_text>
            FORC arg, <strsinpar>
                IFDIF <arg>,<">
                    IF cnt GT 30
                        cnt=0 
    .Data
                        DWdef
                        DWdef TEXTEQU < DW >
    .Code   
                    ENDIF
                    cnt=cnt+1
                    IF cnt NE 1
                        DWdef CATSTR DWdef,<,>
                    ENDIF
                    IF comilla EQ 1
                        DWdef CATSTR DWdef,<">,<arg>,<">
                    ELSEIF comilla EQ 0
                        DWdef CATSTR DWdef,<strsinpar>
                        EXITM
                    ENDIF 
                ELSE
                    IF comilla EQ 0
                        comilla=comilla+1
                    ELSE
                        comilla=comilla-1
                    ENDIF
                ENDIF
            ENDM
        ENDM
        IF cnt NE 0
            DWdef CATSTR DWdef,<,00>
        ELSE
            DWdef CATSTR DWdef,<00>
        ENDIF

    .Data
        DWdef
    .Code
        ExitM <Offset ECDnameW>
    ENDM
ENDIF

TEXT MACRO quoted_text:VARARG
    IFDEF APP_UNICODE
        EXITM L(quoted_text)
    ELSE
        EXITM A(quoted_text)
    ENDIF
ENDM

DEFINED MACRO symbol
    IFDEF symbol
        EXITM <1>  
    ELSE
        EXITM <0>      
    ENDIF
ENDM

ENDIF ;MACROS_INC
