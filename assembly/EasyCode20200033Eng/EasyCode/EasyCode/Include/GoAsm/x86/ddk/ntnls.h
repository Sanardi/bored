;===========================================================;
;                                                           ;
;      ntnls.h for Easy Code 2.0 GoAsm 32-bit drivers       ;
;                     (version 1.0.0)                       ;
;                                                           ;
;             Driver Development Kit (32-bit)               ;
;                                                           ;
;              Copyright © Ramon Sala - 2015                ;
;                                                           ;
;===========================================================;

#IFNDEF NTNLS_H
#Define NTNLS_H 1

#IFNDEF NTDEF_H
    #Include ntdef.h
#ENDIF

MAXIMUM_LEADBYTES                                           Equ         12

CPTABLEINFO Struct
    CodePage                                                DW
    MaximumCharacterSize                                    DW
    DefaultChar                                             DW
    UniDefaultChar                                          DW
    TransDefaultChar                                        DW
    TransUniDefaultChar                                     DW
    DBCSCodePage                                            DW
    LeadByte                                                DB          MAXIMUM_LEADBYTES Dup ?
    MultiByteTable                                          DD
    WideCharTable                                           DD
    DBCSRanges                                              DD
    DBCSOffsets                                             DD
EndS

NLSTABLEINFO Struct
    OemTableInfo                                            CPTABLEINFO
    AnsiTableInfo                                           CPTABLEINFO
    UpperCaseTable                                          DD
    LowerCaseTable                                          DD
EndS

#ENDIF ;NTNLS_H
