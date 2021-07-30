;===================================================================;
;                                                                   ;
;    ntnls.inc for Easy Code 2.0 JWasm/Masm/PoAsm 32-bit drivers    ;
;                        (version 1.0.0)                            ;
;                                                                   ;
;                 Driver Development Kit (32-bit)                   ;
;                                                                   ;
;                  Copyright © Ramon Sala - 2015                    ;
;                                                                   ;
;===================================================================;

IFNDEF NTNLS_INC
NTNLS_INC Equ 1

IFNDEF NTDEF_INC
    Include ntdef.inc
ENDIF

MAXIMUM_LEADBYTES                                           Equ         12

CPTABLEINFO Struct
    CodePage                                                DW          ?
    MaximumCharacterSize                                    DW          ?
    DefaultChar                                             DW          ?
    UniDefaultChar                                          DW          ?
    TransDefaultChar                                        DW          ?
    TransUniDefaultChar                                     DW          ?
    DBCSCodePage                                            DW          ?
    LeadByte                                                DB          MAXIMUM_LEADBYTES Dup(?)
    MultiByteTable                                          PUSHORT     ?
    WideCharTable                                           PVOID       ?
    DBCSRanges                                              PUSHORT     ?
    DBCSOffsets                                             PUSHORT     ?
CPTABLEINFO EndS
PCPTABLEINFO                                                TypeDef     DWord

NLSTABLEINFO Struct
    OemTableInfo                                            CPTABLEINFO <>
    AnsiTableInfo                                           CPTABLEINFO <>
    UpperCaseTable                                          PUSHORT     ?
    LowerCaseTable                                          PUSHORT     ?
NLSTABLEINFO EndS
PNLSTABLEINFO                                               TypeDef     DWord

ENDIF ;NTNLS_INC
