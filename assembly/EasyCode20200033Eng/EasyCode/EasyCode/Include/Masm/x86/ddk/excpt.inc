;===================================================================;
;                                                                   ;
;    excpt.inc for Easy Code 2.0 JWasm/Masm/PoAsm 32-bit drivers    ;
;                        (version 1.0.0)                            ;
;                                                                   ;
;                 Driver Development Kit (32-bit)                   ;
;                                                                   ;
;                  Copyright © Ramon Sala - 2015                    ;
;                                                                   ;
;===================================================================;

IFNDEF ECXPT_INC
ECXPT_INC Equ 1

;EXCEPTION_DISPOSITION Enumeration
EXCEPTION_DISPOSITION                                       TypeDef     DWord
ExceptionContinueExecution                                  Equ         0
ExceptionContinueSearch                                     Equ         1
ExceptionNestedException                                    Equ         2
ExceptionCollidedUnwind                                     Equ         3

EXCEPTION_EXECUTE_HANDLER                                   Equ         1
EXCEPTION_CONTINUE_SEARCH                                   Equ         0
EXCEPTION_CONTINUE_EXECUTION                                Equ         (-1)

ENDIF ;ECXPT_INC
