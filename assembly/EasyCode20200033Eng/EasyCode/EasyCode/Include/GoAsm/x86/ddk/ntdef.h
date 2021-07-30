;===========================================================;
;                                                           ;
;      ntdef.h for Easy Code 2.0 GoAsm 32-bit drivers       ;
;                     (version 1.0.0)                       ;
;                                                           ;
;             Driver Development Kit (32-bit)               ;
;                                                           ;
;              Copyright © Ramon Sala - 2015                ;
;                                                           ;
;===========================================================;

#IFNDEF NTDEF_H
#Define NTDEF_H 1

#IFNDEF ANYSIZE_ARRAY
    ANYSIZE_ARRAY                       Equ         1
#ENDIF

QUAD Struct                         
    DoNotUseThisField                   DQ
EndS

RECT Struct
    left                                DD
    top                                 DD
    right                               DD
    bottom                              DD
EndS

RECTL Struct
    left                                DD
    top                                 DD
    right                               DD
    bottom                              DD
EndS

POINT Struct
    x                                   DD
    y                                   DD
EndS

POINTL Struct
    x                                   DD
    y                                   DD
EndS

_SIZE Struct
    _cx                                 DD  ;cx
    cy                                  DD
EndS

SIZEL Struct
    _cx                                 DD  ;cx
    cy                                  DD
EndS

APPLICATION_ERROR_MASK                  Equ         020000000H
ERROR_SEVERITY_SUCCESS                  Equ         000000000H
ERROR_SEVERITY_INFORMATIONAL            Equ         040000000H
ERROR_SEVERITY_WARNING                  Equ         080000000H
ERROR_SEVERITY_ERROR                    Equ         0C0000000H

TIME Union
    Struct
        Union
            LowPart                     DD
            LowTime                     DD
        EndUnion
        Union
            HighPart                    DD
            HighTime                    DD
        EndUnion
    EndS
    u Struct
        Union
            LowPart                     DD
            LowTime                     DD
        EndUnion
        Union
            HighPart                    DD
            HighTime                    DD
        EndUnion
    EndS
    QuadPart                            DQ
EndUnion

LARGE_INTEGER Union
    Struct
        LowPart                         DD
        HighPart                        DD
    EndS
    QuadPart                            DQ
EndUnion

ULARGE_INTEGER Union
    Struct
        LowPart                         DD
        HighPart                        DD
    EndS
    QuadPart                            DQ
EndUnion

LUID Struct
    LowPart                             DD
    HighPart                            DD
EndS

PHYSICAL_ADDRESS Union
    Struct
        LowPart                         DD
        HighPart                        DD
    EndS
    u Struct
        LowPart                         DD
        HighPart                        DD
    EndS
    QuadPart                            DQ
EndUnion

;EVENT_TYPE
NotificationEvent                       Equ         0
SynchronizationEvent                    Equ         1

;TIMER_TYPE
NotificationTimer                       Equ         0
SynchronizationTimer                    Equ         1

;WAIT_TYPE
WaitAll                                 Equ         0
WaitAny                                 Equ         1

STRING Struct
    Length                              DW
    MaximumLength                       DW
    Buffer                              DD
EndS

#Define                                 ANSI_STRING STRING

#Define                                 OEM_STRING  STRING

CSTRING Struct
    Length                              DW
    MaximumLength                       DW
    Buffer                              DD
EndS

ANSI_NULL                               Equ         0

#IFNDEF UNICODE_STRING
    UNICODE_STRING Struct
        Length                          DW
        MaximumLength                   DW
        Buffer                          DD
    EndS
#ENDIF

UNICODE_NULL                            Equ         0

PROCESSOR_NUMBER Struct
    Group                               DW
    Number                              DB
    Reserved                            DB
EndS

GROUP_AFFINITY Struct
    Mask                                DD
    Group                               DW
    Reserved                            DW          3 Dup ?
EndS

LIST_ENTRY Struct
    Flink                               DD
    Blink                               DD
EndS

SINGLE_LIST_ENTRY Struct
    Next                                DD
EndS

LIST_ENTRY32 Struct
    Flink                               DD
    Blink                               DD
EndS

LIST_ENTRY64 Struct
    Flink                               DQ
    Blink                               DQ
EndS

STRING32 Struct
    Length                              DW
    MaximumLength                       DW
    Buffer                              DD
EndS

#Define                                 UNICODE_STRING32 STRING32

#Define                                 ANSI_STRING32 STRING32

OBJ_INHERIT                             Equ         00000002H
OBJ_PERMANENT                           Equ         00000010H
OBJ_EXCLUSIVE                           Equ         00000020H
OBJ_CASE_INSENSITIVE                    Equ         00000040H
OBJ_OPENIF                              Equ         00000080H
OBJ_OPENLINK                            Equ         00000100H
OBJ_KERNEL_HANDLE                       Equ         00000200H
OBJ_VALID_ATTRIBUTES                    Equ         000003F2H

OBJECT_ATTRIBUTES Struct
    Length                              DD
    RootDirectory                       DD
    ObjectName                          DD
    Attributes                          DD
    SecurityDescriptor                  DD
    SecurityQualityOfService            DD
EndS

FALSE                                   Equ         0
TRUE                                    Equ         1

NULL                                    Equ         0
NULL64                                  Equ         0

MINCHAR                                 Equ         000000080H
MAXCHAR                                 Equ         00000007FH
MINSHORT                                Equ         000008000H
MAXSHORT                                Equ         000007FFFH
MINLONG                                 Equ         080000000H
MAXLONG                                 Equ         07FFFFFFFH
MAXUCHAR                                Equ         0000000FFH
MAXUSHORT                               Equ         00000FFFFH
MAXULONG                                Equ         0FFFFFFFFH

;NT_PRODUCT_TYPE
NtProductWinNt                          Equ         1
NtProductLanManNt                       Equ         2
NtProductServer                         Equ         3

;SUITE_TYPE
SmallBusiness                           Equ         0
Enterprise                              Equ         1
BackOffice                              Equ         2
CommunicationServer                     Equ         3
TerminalServer                          Equ         4
SmallBusinessRestricted                 Equ         5
EmbeddedNT                              Equ         6
DataCenter                              Equ         7
SingleUserTS                            Equ         8
Personal                                Equ         9
ServerAppliance                         Equ         10
MaxSuiteType                            Equ         11

VER_SERVER_NT                           Equ         80000000H
VER_WORKSTATION_NT                      Equ         40000000H
VER_SUITE_SMALLBUSINESS                 Equ         00000001H
VER_SUITE_ENTERPRISE                    Equ         00000002H
VER_SUITE_BACKOFFICE                    Equ         00000004H
VER_SUITE_COMMUNICATIONS                Equ         00000008H
VER_SUITE_TERMINAL                      Equ         00000010H
VER_SUITE_SMALLBUSINESS_RESTRICTED      Equ         00000020H
VER_SUITE_EMBEDDEDNT                    Equ         00000040H
VER_SUITE_DATACENTER                    Equ         00000080H
VER_SUITE_SINGLEUSERTS                  Equ         00000100H
VER_SUITE_PERSONAL                      Equ         00000200H
VER_SUITE_SERVERAPPLIANCE               Equ         00000400H

LANG_NEUTRAL                            Equ         00H

LANG_AFRIKAANS                          Equ         36H
LANG_ALBANIAN                           Equ         1CH
LANG_ARABIC                             Equ         01H
LANG_ARMENIAN                           Equ         2BH
LANG_ASSAMESE                           Equ         4DH
LANG_AZERI                              Equ         2CH
LANG_BASQUE                             Equ         2DH
LANG_BELARUSIAN                         Equ         23H
LANG_BENGALI                            Equ         45H
LANG_BULGARIAN                          Equ         02H
LANG_CATALAN                            Equ         03H
LANG_CHINESE                            Equ         04H
LANG_CROATIAN                           Equ         1AH
LANG_CZECH                              Equ         05H
LANG_DANISH                             Equ         06H
LANG_DUTCH                              Equ         13H
LANG_ENGLISH                            Equ         09H
LANG_ESTONIAN                           Equ         25H
LANG_FAEROESE                           Equ         38H
LANG_FARSI                              Equ         29H
LANG_FINNISH                            Equ         0BH
LANG_FRENCH                             Equ         0CH
LANG_GEORGIAN                           Equ         37H
LANG_GERMAN                             Equ         07H
LANG_GREEK                              Equ         08H
LANG_GUJARATI                           Equ         47H
LANG_HEBREW                             Equ         0DH
LANG_HINDI                              Equ         39H
LANG_HUNGARIAN                          Equ         0EH
LANG_ICELANDIC                          Equ         0FH
LANG_INDONESIAN                         Equ         21H
LANG_ITALIAN                            Equ         10H
LANG_JAPANESE                           Equ         11H
LANG_KANNADA                            Equ         4BH
LANG_KASHMIRI                           Equ         60H
LANG_KAZAK                              Equ         3FH
LANG_KONKANI                            Equ         57H
LANG_KOREAN                             Equ         12H
LANG_LATVIAN                            Equ         26H
LANG_LITHUANIAN                         Equ         27H
LANG_MACEDONIAN                         Equ         2FH
LANG_MALAY                              Equ         3EH
LANG_MALAYALAM                          Equ         4CH
LANG_MANIPURI                           Equ         58H
LANG_MARATHI                            Equ         4EH
LANG_NEPALI                             Equ         61H
LANG_NORWEGIAN                          Equ         14H
LANG_ORIYA                              Equ         48H
LANG_POLISH                             Equ         15H
LANG_PORTUGUESE                         Equ         16H
LANG_PUNJABI                            Equ         46H
LANG_ROMANIAN                           Equ         18H
LANG_RUSSIAN                            Equ         19H
LANG_SANSKRIT                           Equ         4FH
LANG_SERBIAN                            Equ         1AH
LANG_SINDHI                             Equ         59H
LANG_SLOVAK                             Equ         1BH
LANG_SLOVENIAN                          Equ         24H
LANG_SPANISH                            Equ         0AH
LANG_SWAHILI                            Equ         41H
LANG_SWEDISH                            Equ         1DH
LANG_TAMIL                              Equ         49H
LANG_TATAR                              Equ         44H
LANG_TELUGU                             Equ         4AH
LANG_THAI                               Equ         1EH
LANG_TURKISH                            Equ         1FH
LANG_UKRAINIAN                          Equ         22H
LANG_URDU                               Equ         20H
LANG_UZBEK                              Equ         43H
LANG_VIETNAMESE                         Equ         2AH

SUBLANG_NEUTRAL                         Equ         00H
SUBLANG_DEFAULT                         Equ         01H
SUBLANG_SYS_DEFAULT                     Equ         02H

SUBLANG_ARABIC_SAUDI_ARABIA             Equ         01H
SUBLANG_ARABIC_IRAQ                     Equ         02H
SUBLANG_ARABIC_EGYPT                    Equ         03H
SUBLANG_ARABIC_LIBYA                    Equ         04H
SUBLANG_ARABIC_ALGERIA                  Equ         05H
SUBLANG_ARABIC_MOROCCO                  Equ         06H
SUBLANG_ARABIC_TUNISIA                  Equ         07H
SUBLANG_ARABIC_OMAN                     Equ         08H
SUBLANG_ARABIC_YEMEN                    Equ         09H
SUBLANG_ARABIC_SYRIA                    Equ         0AH
SUBLANG_ARABIC_JORDAN                   Equ         0BH
SUBLANG_ARABIC_LEBANON                  Equ         0CH
SUBLANG_ARABIC_KUWAIT                   Equ         0DH
SUBLANG_ARABIC_UAE                      Equ         0EH
SUBLANG_ARABIC_BAHRAIN                  Equ         0FH
SUBLANG_ARABIC_QATAR                    Equ         10H
SUBLANG_AZERI_LATIN                     Equ         01H
SUBLANG_AZERI_CYRILLIC                  Equ         02H
SUBLANG_CHINESE_TRADITIONAL             Equ         01H
SUBLANG_CHINESE_SIMPLIFIED              Equ         02H
SUBLANG_CHINESE_HONGKONG                Equ         03H
SUBLANG_CHINESE_SINGAPORE               Equ         04H
SUBLANG_CHINESE_MACAU                   Equ         05H
SUBLANG_DUTCH                           Equ         01H
SUBLANG_DUTCH_BELGIAN                   Equ         02H
SUBLANG_ENGLISH_US                      Equ         01H
SUBLANG_ENGLISH_UK                      Equ         02H
SUBLANG_ENGLISH_AUS                     Equ         03H
SUBLANG_ENGLISH_CAN                     Equ         04H
SUBLANG_ENGLISH_NZ                      Equ         05H
SUBLANG_ENGLISH_EIRE                    Equ         06H
SUBLANG_ENGLISH_SOUTH_AFRICA            Equ         07H
SUBLANG_ENGLISH_JAMAICA                 Equ         08H
SUBLANG_ENGLISH_CARIBBEAN               Equ         09H
SUBLANG_ENGLISH_BELIZE                  Equ         0AH
SUBLANG_ENGLISH_TRINIDAD                Equ         0BH
SUBLANG_ENGLISH_ZIMBABWE                Equ         0CH
SUBLANG_ENGLISH_PHILIPPINES             Equ         0DH
SUBLANG_FRENCH                          Equ         01H
SUBLANG_FRENCH_BELGIAN                  Equ         02H
SUBLANG_FRENCH_CANADIAN                 Equ         03H
SUBLANG_FRENCH_SWISS                    Equ         04H
SUBLANG_FRENCH_LUXEMBOURG               Equ         05H
SUBLANG_FRENCH_MONACO                   Equ         06H
SUBLANG_GERMAN                          Equ         01H
SUBLANG_GERMAN_SWISS                    Equ         02H
SUBLANG_GERMAN_AUSTRIAN                 Equ         03H
SUBLANG_GERMAN_LUXEMBOURG               Equ         04H
SUBLANG_GERMAN_LIECHTENSTEIN            Equ         05H
SUBLANG_ITALIAN                         Equ         01H
SUBLANG_ITALIAN_SWISS                   Equ         02H
SUBLANG_KASHMIRI_INDIA                  Equ         02H
SUBLANG_KOREAN                          Equ         01H
SUBLANG_LITHUANIAN                      Equ         01H
SUBLANG_MALAY_MALAYSIA                  Equ         01H
SUBLANG_MALAY_BRUNEI_DARUSSALAM         Equ         02H
SUBLANG_NEPALI_INDIA                    Equ         02H
SUBLANG_NORWEGIAN_BOKMAL                Equ         01H
SUBLANG_NORWEGIAN_NYNORSK               Equ         02H
SUBLANG_PORTUGUESE                      Equ         02H
SUBLANG_PORTUGUESE_BRAZILIAN            Equ         01H
SUBLANG_SERBIAN_LATIN                   Equ         02H
SUBLANG_SERBIAN_CYRILLIC                Equ         03H
SUBLANG_SPANISH                         Equ         01H
SUBLANG_SPANISH_MEXICAN                 Equ         02H
SUBLANG_SPANISH_MODERN                  Equ         03H
SUBLANG_SPANISH_GUATEMALA               Equ         04H
SUBLANG_SPANISH_COSTA_RICA              Equ         05H
SUBLANG_SPANISH_PANAMA                  Equ         06H
SUBLANG_SPANISH_DOMINICAN_REPUBLIC      Equ         07H
SUBLANG_SPANISH_VENEZUELA               Equ         08H
SUBLANG_SPANISH_COLOMBIA                Equ         09H
SUBLANG_SPANISH_PERU                    Equ         0AH
SUBLANG_SPANISH_ARGENTINA               Equ         0BH
SUBLANG_SPANISH_ECUADOR                 Equ         0CH
SUBLANG_SPANISH_CHILE                   Equ         0DH
SUBLANG_SPANISH_URUGUAY                 Equ         0EH
SUBLANG_SPANISH_PARAGUAY                Equ         0FH
SUBLANG_SPANISH_BOLIVIA                 Equ         10H
SUBLANG_SPANISH_EL_SALVADOR             Equ         11H
SUBLANG_SPANISH_HONDURAS                Equ         12H
SUBLANG_SPANISH_NICARAGUA               Equ         13H
SUBLANG_SPANISH_PUERTO_RICO             Equ         14H
SUBLANG_SWEDISH                         Equ         01H
SUBLANG_SWEDISH_FINLAND                 Equ         02H
SUBLANG_URDU_PAKISTAN                   Equ         01H
SUBLANG_URDU_INDIA                      Equ         02H
SUBLANG_UZBEK_LATIN                     Equ         01H
SUBLANG_UZBEK_CYRILLIC                  Equ         02H

SORT_DEFAULT                            Equ         0

SORT_JAPANESE_XJIS                      Equ         0
SORT_JAPANESE_UNICODE                   Equ         1

SORT_CHINESE_BIG5                       Equ         0
SORT_CHINESE_PRCP                       Equ         0
SORT_CHINESE_UNICODE                    Equ         1
SORT_CHINESE_PRC                        Equ         2
SORT_CHINESE_BOPOMOFO                   Equ         3

SORT_KOREAN_KSC                         Equ         0
SORT_KOREAN_UNICODE                     Equ         1

SORT_GERMAN_PHONE_BOOK                  Equ         1

SORT_HUNGARIAN_DEFAULT                  Equ         0
SORT_HUNGARIAN_TECHNICAL                Equ         1

SORT_GEORGIAN_TRADITIONAL               Equ         0
SORT_GEORGIAN_MODERN                    Equ         1

#ENDIF ;NTDEF_H
