;===================================================================;
;                                                                   ;
;  diskguid.inc for Easy Code 2.0 JWasm/Masm/PoAsm 32-bit drivers   ;
;                        (version 1.0.0)                            ;
;                                                                   ;
;                 Driver Development Kit (32-bit)                   ;
;                                                                   ;
;                  Copyright © Ramon Sala - 2015                    ;
;                                                                   ;
;===================================================================;

IFNDEF DISKGUID_INC
DISKGUID_INC Equ 1

IFDEF DEFINE_GUID
    DEFINE_GUID     PARTITION_ENTRY_UNUSED_GUID,            000000000H, 00000H, 00000H, 000H, 000H, 000H, 000H, 000H, 000H, 000H, 000H
    DEFINE_GUID     PARTITION_SYSTEM_GUID,                  0C12A7328H, 0F81FH, 011D2H, 0BAH, 04BH, 000H, 0A0H, 0C9H, 03EH, 0C9H, 03BH
    DEFINE_GUID     PARTITION_MSFT_RESERVED_GUID,           0E3C9E316H, 00B5CH, 04DB8H, 081H, 07DH, 0F9H, 02DH, 0F0H, 002H, 015H, 0AEH
    DEFINE_GUID     PARTITION_BASIC_DATA_GUID,              0EBD0A0A2H, 0B9E5H, 04433H, 087H, 0C0H, 068H, 0B6H, 0B7H, 026H, 099H, 0C7H
    DEFINE_GUID     PARTITION_LDM_METADATA_GUID,            05808C8AAH, 07E8FH, 042E0H, 085H, 0D2H, 0E1H, 0E9H, 004H, 034H, 0CFH, 0B3H
    DEFINE_GUID     PARTITION_LDM_DATA_GUID,                0AF9B60A0H, 01431H, 04F62H, 0BCH, 068H, 033H, 011H, 071H, 04AH, 069H, 0ADH
    DEFINE_GUID     PARTITION_MSFT_RECOVERY_GUID,           0DE94BBA4H, 006D1H, 04D40H, 0A1H, 06AH, 0BFH, 0D5H, 001H, 079H, 0D6H, 0ACH
    DEFINE_GUID     PARTITION_CLUSTER_GUID,                 0DB97DBA9H, 00840H, 04BAEH, 097H, 0F0H, 0FFH, 0B9H, 0A3H, 027H, 0C7H, 0E1H
ENDIF

ENDIF ;DISKGUID_INC
