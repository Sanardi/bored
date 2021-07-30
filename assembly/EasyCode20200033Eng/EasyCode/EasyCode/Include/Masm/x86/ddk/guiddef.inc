;===================================================================;
;                                                                   ;
;   guiddef.inc for Easy Code 2.0 JWasm/Masm/PoAsm 32-bit drivers   ;
;                        (version 1.0.0)                            ;
;                                                                   ;
;                 Driver Development Kit (32-bit)                   ;
;                                                                   ;
;                  Copyright © Ramon Sala - 2015                    ;
;                                                                   ;
;===================================================================;

IFNDEF GUIDDEF_INC
GUIDDEF_INC Equ 1

IFNDEF GUID_DEFINED
    GUID_DEFINED                            Equ         1
    __LPGUID_DEFINED__                      Equ         1
    GUID Struct
        Data1                               DD          ?
        Data2                               DW          ?
        Data3                               DW          ?
        Data4                               DB          8 Dup(?)
    GUID EndS
    CLSID                                   Equ         <GUID>
    IID                                     Equ         <GUID>
    FMTID                                   Equ         <GUID>
    LPGUID                                  TypeDef 	DWord
ENDIF

ENDIF ;GUIDDEF_INC
