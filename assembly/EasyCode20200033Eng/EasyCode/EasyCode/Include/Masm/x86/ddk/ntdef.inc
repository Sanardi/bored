;===================================================================;
;                                                                   ;
;    ntdef.inc for Easy Code 2.0 JWasm/Masm/PoAsm 32-bit drivers    ;
;                        (version 1.0.1)                            ;
;                                                                   ;
;                 Driver Development Kit (32-bit)                   ;
;                                                                   ;
;                Copyright © Ramon Sala - 2015-2016                 ;
;                                                                   ;
;===================================================================;

IFNDEF NTDEF_INC
NTDEF_INC Equ 1

DEVICE_TYPE                             TypeDef     DWord

SIZE_T                                  TypeDef     DWord

IFDEF APP_WIN64
    size_t                              TypeDef     QWord
ELSE
    size_t                              TypeDef     DWord
ENDIF

CALLBACK                                TypeDef     Proto STDCALL
WINAPI                                  TypeDef     Proto STDCALL
NTAPI                                   TypeDef     Proto STDCALL

BOOL                                    TypeDef     DWord

IFNDEF PBYTE
    PBYTE                               TypeDef     DWord
ENDIF
IFNDEF PBOOLEAN
    PBOOLEAN                            TypeDef     DWord
ENDIF
IFNDEF PWORD
    PWORD                               TypeDef     DWord
ENDIF
IFNDEF PDWORD
    PDWORD                              TypeDef     DWord
ENDIF
IFNDEF PVOID
    PVOID                               TypeDef     DWord
ENDIF
IFNDEF PVOID64
    PVOID64                             TypeDef     DWord
ENDIF
IFNDEF PCVOID
    PCVOID                              TypeDef     DWord
ENDIF
IFNDEF PSTR
    PSTR                                TypeDef     DWord
ENDIF
IFNDEF PCSTR
    PCSTR                               TypeDef     DWord
ENDIF
IFNDEF PWSTR
    PWSTR                               TypeDef     DWord
ENDIF

PDWORD_PTR                              TypeDef     DWord

UINT                                    TypeDef     DWord

HFILE                                   TypeDef     DWord

IFNDEF ANYSIZE_ARRAY
    ANYSIZE_ARRAY                       Equ         1
ENDIF

char                                    TypeDef     Byte
CHAR                                    TypeDef     Byte
UCHAR                                   TypeDef     Byte
bool                                    TypeDef     Byte
BOOLEAN                                 TypeDef     Byte

USHORT                                  TypeDef     Word
ATOM                                    TypeDef     Word
IFNDEF LANGID
	LANGID                              TypeDef     Word
ENDIF
OLECHAR                                 TypeDef     Word
FILEOP_FLAGS                            TypeDef     Word
WCHAR                                   TypeDef     Word
wchar_t                                 TypeDef     Word

IFDEF APP_UNICODE
    IFNDEF TCHAR
        TCHAR                           TypeDef     Word
    ENDIF
    IFNDEF PTCHAR
        PTCHAR                          TypeDef     DWord
    ENDIF
    IFNDEF TUCHAR
        TUCHAR                          TypeDef     Word
    ENDIF
    IFNDEF PTUCHAR
        PTUCHAR                         TypeDef     DWord
    ENDIF
ELSE
	IFNDEF TCHAR
        TCHAR                           TypeDef     Byte
    ENDIF
    IFNDEF PTCHAR
        PTCHAR                          TypeDef     DWord
    ENDIF
    IFNDEF TUCHAR
        TUCHAR                          TypeDef     Byte
    ENDIF
    IFNDEF PTUCHAR
        PTUCHAR                         TypeDef     DWord
    ENDIF
ENDIF

LPTCH                                   TypeDef     DWord
PTCH                                    TypeDef     DWord
PTSTR                                   TypeDef     DWord
LPTSTR                                  TypeDef     DWord
PCTSTR                                  TypeDef     DWord
LPCTSTR                                 TypeDef     DWord
LP                                      TypeDef     DWord

COLORREF                                TypeDef     DWord
HWND                                    TypeDef     DWord
LPARAM                                  TypeDef     DWord
LPBOOL                                  TypeDef     DWord
LPBYTE                                  TypeDef     DWord
LPDWORD                                 TypeDef     DWord
LPLONG                                  TypeDef     DWord
LPOLESTR                                TypeDef     DWord
LPWORD                                  TypeDef     DWord
WPARAM                                  TypeDef     DWord

IFNDEF long
    long                                TypeDef     SDWord
ENDIF
IFNDEF LONG
    LONG                                TypeDef     SDWord
ENDIF

IFNDEF PWCHAR
    PWCHAR                              TypeDef     DWord
ENDIF
IFNDEF LPWCH
    LPWCH                               TypeDef     DWord
ENDIF
IFNDEF PWCH
    PWCH                                TypeDef     DWord
ENDIF

IFNDEF LPCWCH
    LPCWCH                              TypeDef     DWord
ENDIF
IFNDEF PCWCH
    PCWCH                               TypeDef     DWord
ENDIF

IFNDEF NWPSTR
    NWPSTR                              TypeDef     DWord
ENDIF

IFNDEF LPWSTR
    LPWSTR                              TypeDef     DWord
    LPCWSTR                             TypeDef     DWord
    PCWSTR                              TypeDef     DWord
ENDIF

IFNDEF PCHAR
    PCHAR                               TypeDef     DWord
ENDIF
IFNDEF LPCH
    LPCH                                TypeDef     DWord
ENDIF
IFNDEF PCH
    PCH                                 TypeDef     DWord
ENDIF

IFNDEF LPCCH
    LPCCH                               TypeDef     DWord
ENDIF
IFNDEF PCCH
    PCCH                                TypeDef     DWord
ENDIF

IFNDEF NPSTR
    NPSTR                               TypeDef     DWord
ENDIF

IFNDEF LPSTR
    LPSTR                               TypeDef     DWord
ENDIF
IFNDEF LPCSTR
    LPCSTR                              TypeDef     DWord
ENDIF

IFNDEF LPVOID
    LPVOID                              TypeDef     DWord
ENDIF

IFNDEF double
    double                              TypeDef     QWord
ENDIF
IFNDEF DOUBLE
    DOUBLE                              TypeDef     QWord
ENDIF

QUAD Struct                         
    DoNotUseThisField                   DQ          ?
QUAD EndS

IFNDEF PSHORT
    PSHORT                              TypeDef     SWord
ENDIF
IFNDEF PLONG
    PLONG                               TypeDef     DWord
ENDIF
IFNDEF PQUAD
    PQUAD                               TypeDef     DWord
ENDIF

IFNDEF ULONG
    ULONG                               TypeDef     DWord
ENDIF
IFNDEF UQUAD
    UQUAD                               TypeDef     QWord
ENDIF

IFNDEF PUCHAR
    PUCHAR                              TypeDef     DWord
ENDIF
IFNDEF PUSHORT
    PUSHORT                             TypeDef     DWord
ENDIF
IFNDEF PULONG
    PULONG                              TypeDef     DWord
ENDIF
IFNDEF PUQUAD
    PUQUAD                              TypeDef     DWord
ENDIF

IFNDEF SCHAR
    SCHAR                               TypeDef     SByte
ENDIF
IFNDEF PSCHAR
    PSCHAR                              TypeDef     DWord
ENDIF

IFNDEF HANDLE
    HANDLE                              TypeDef     DWord
ENDIF
IFNDEF PHANDLE
    PHANDLE                             TypeDef     DWord
ENDIF

IFNDEF FCHAR
    FCHAR                               TypeDef     Byte
ENDIF
IFNDEF FSHORT
    FSHORT                              TypeDef     Word
ENDIF
IFNDEF FLONG
    FLONG                               TypeDef     DWord
ENDIF

IFNDEF CCHAR
    CCHAR                               TypeDef     Byte
ENDIF
IFNDEF CSHORT
    CSHORT                              TypeDef     SWord
ENDIF
IFNDEF CLONG
    CLONG                               TypeDef     SDWord
ENDIF

IFNDEF PCCHAR
    PCCHAR                              TypeDef     DWord
ENDIF
IFNDEF PCSHORT
    PCSHORT                             TypeDef     DWord
ENDIF
IFNDEF PCLONG
    PCLONG                              TypeDef     DWord
ENDIF

IFNDEF LCID
    LCID                                TypeDef     DWord
ENDIF
IFNDEF PLCID
    PLCID                               TypeDef     DWord
ENDIF

IFNDEF LOGICAL
    LOGICAL                             TypeDef     DWord
    PLOGICAL                            TypeDef     DWord
ENDIF

IFNDEF NTSTATUS
    NTSTATUS                            TypeDef     SDWord
    PNTSTATUS                           TypeDef     DWord
ENDIF

IFNDEF KSPIN_LOCK
    KSPIN_LOCK                          TypeDef     DWord
ENDIF

IFNDEF KPROCESSOR_MODE
    KPROCESSOR_MODE                     TypeDef     Byte
ENDIF

IFNDEF KAFFINITY
    KAFFINITY                           TypeDef     DWord
    PKAFFINITY                          TypeDef     DWord
ENDIF

IFNDEF RECT
    RECT Struct
        left                            DD          ?
        top                             DD          ?
        right                           DD          ?
        bottom                          DD          ?
    RECT EndS
ENDIF

IFNDEF RECTL
    RECTL Struct
        left                            DD          ?
        top                             DD          ?
        right                           DD          ?
        bottom                          DD          ?
    RECTL EndS
ENDIF

IFNDEF POINT
    POINT Struct
        x                               DD          ?
        y                               DD          ?
    POINT EndS
ENDIF

IFNDEF POINTL
    POINTL Struct
        x                               DD          ?
        y                               DD          ?
    POINTL EndS
ENDIF

IFNDEF _SIZE
    _SIZE Struct
        _cx                             DD          ?   ;cx
        cy                              DD          ?
    _SIZE EndS
ENDIF

IFNDEF SIZEL
    SIZEL Struct
        _cx                             DD          ?   ;cx
        cy                              DD          ?
    SIZEL EndS
ENDIF

APPLICATION_ERROR_MASK                  Equ         020000000H
ERROR_SEVERITY_SUCCESS                  Equ         000000000H
ERROR_SEVERITY_INFORMATIONAL            Equ         040000000H
ERROR_SEVERITY_WARNING                  Equ         080000000H
ERROR_SEVERITY_ERROR                    Equ         0C0000000H

TIME Union
    Struct
        Union
            LowPart                     DD          ?
            LowTime                     DD          ?
        EndS
        Union
            HighPart                    DD          ?
            HighTime                    DD          ?
        EndS
    EndS
    Struct u
        Union
            LowPart                     DD          ?
            LowTime                     DD          ?
        EndS
        Union
            HighPart                    DD          ?
            HighTime                    DD          ?
        EndS
    EndS
    QuadPart                            DQ          ?
TIME EndS
PTIME                                   TypeDef     DWord

LONGLONG                                TypeDef     QWord
ULONGLONG                               TypeDef     QWord

PLONGLONG                               TypeDef     DWord
PULONGLONG                              TypeDef     DWord

USN                                     TypeDef     QWord

IFNDEF LARGE_INTEGER
	LARGE_INTEGER Union
	    Struct
	        LowPart                     DD          ?
	        HighPart                    DD          ?
	    EndS
	    QuadPart                        DQ          ?
	LARGE_INTEGER EndS
ENDIF
IFNDEF PLARGE_INTEGER
	PLARGE_INTEGER                      TypeDef     DWord
ENDIF

ULARGE_INTEGER Union
    Struct
        LowPart                         DD          ?
        HighPart                        DD          ?
    EndS
    QuadPart                            DQ          ?
ULARGE_INTEGER EndS
PULARGE_INTEGER                         TypeDef     DWord

IFNDEF LUID
	LUID Struct
	    LowPart                             DD          ?
	    HighPart                            DD          ?
	LUID EndS
ENDIF
IFNDEF PLUID
    PLUID                               TypeDef     DWord
ENDIF

DWORDLONG                               TypeDef     QWord
PDWORDLONG                              TypeDef     DWord

PHYSICAL_ADDRESS Union
    Struct
        LowPart                         DD          ?
        HighPart                        DD          ?
    EndS
    Struct u
        LowPart                         DD          ?
        HighPart                        DD          ?
    EndS
    QuadPart                            DQ          ?
PHYSICAL_ADDRESS EndS
PPHYSICAL_ADDRESS                       TypeDef     DWord

;EVENT_TYPE
NotificationEvent                       Equ         0
SynchronizationEvent                    Equ         1

;TIMER_TYPE
NotificationTimer                       Equ         0
SynchronizationTimer                    Equ         1

;WAIT_TYPE
WaitAll                                 Equ         0
WaitAny                                 Equ         1

PSZ                                     TypeDef     DWord
PCSZ                                    TypeDef     DWord

STRING Struct
    _Length                             DW          ?   ;Length
    MaximumLength                       DW          ?
    Buffer                              DD          ?
STRING EndS
PSTRING                                 TypeDef     DWord


ANSI_STRING                             Equ         <STRING>
PANSI_STRING                            TypeDef     DWord

OEM_STRING                              Equ         <STRING>
POEM_STRING                             TypeDef     DWord

CSTRING Struct
    _Length                             DW          ?   ;Length
    MaximumLength                       DW          ?
    Buffer                              DD          ?
CSTRING EndS
PCSTRING                                TypeDef     DWord

ANSI_NULL                               Equ         0

IFNDEF UNICODE_STRING
    UNICODE_STRING Struct
        _Length                         DW          ?   ;Length
        MaximumLength                   DW          ?
        Buffer                          DD          ?
    UNICODE_STRING EndS
    PUNICODE_STRING                     TypeDef     DWord
ENDIF

UNICODE_NULL                            Equ         0

IFNDEF PROCESSOR_NUMBER
    PROCESSOR_NUMBER Struct
        _Group                          DW          ?   ;Group
        Number                          DB          ?
        Reserved                        DB          ?
    PROCESSOR_NUMBER EndS
    PPROCESSOR_NUMBER                   TypeDef     DWord
ENDIF

GROUP_AFFINITY Struct
    _Mask                               KAFFINITY   ?   ;Mask
    _Group                              DW          ?   ;Group
    Reserved                            DW          3 Dup(?)
GROUP_AFFINITY EndS
PGROUP_AFFINITY                         TypeDef     DWord

IFNDEF LIST_ENTRY
	LIST_ENTRY Struct
	    Flink                           DD          ?
	    Blink                           DD          ?
	LIST_ENTRY EndS
ENDIF
IFNDEF PLIST_ENTRY
	PLIST_ENTRY                         TypeDef     DWord
ENDIF

IFNDEF SINGLE_LIST_ENTRY
	SINGLE_LIST_ENTRY Struct
	    Next                                DD          ?
	SINGLE_LIST_ENTRY EndS
ENDIF

IFNDEF PSINGLE_LIST_ENTRY
	PSINGLE_LIST_ENTRY                      TypeDef     DWord
ENDIF

IFNDEF LIST_ENTRY32
	LIST_ENTRY32 Struct
	    Flink                               DD          ?
	    Blink                               DD          ?
	LIST_ENTRY32 EndS
ENDIF

IFNDEF PLIST_ENTRY32
	PLIST_ENTRY32                           TypeDef     DWord
ENDIF

IFNDEF LIST_ENTRY64
	LIST_ENTRY64 Struct
	    Flink                               DQ          ?
	    Blink                               DQ          ?
	LIST_ENTRY64 EndS
ENDIF

IFNDEF PLIST_ENTRY64
	PLIST_ENTRY64                           TypeDef     DWord
ENDIF

STRING32 Struct
    _Length                             DW          ?   ;Length
    MaximumLength                       DW          ?
    Buffer                              DD          ?
STRING32 EndS
PSTRING32                               TypeDef     DWord

UNICODE_STRING32                        Equ         <STRING32>
PUNICODE_STRING32                       TypeDef     DWord

ANSI_STRING32                           Equ         <STRING32>
PANSI_STRING32                          TypeDef     DWord

OBJ_INHERIT                             Equ         00000002H
OBJ_PERMANENT                           Equ         00000010H
OBJ_EXCLUSIVE                           Equ         00000020H
OBJ_CASE_INSENSITIVE                    Equ         00000040H
OBJ_OPENIF                              Equ         00000080H
OBJ_OPENLINK                            Equ         00000100H
OBJ_KERNEL_HANDLE                       Equ         00000200H
OBJ_VALID_ATTRIBUTES                    Equ         000003F2H

OBJECT_ATTRIBUTES Struct
    _Length                             DD          ?   ;Length
    RootDirectory                       HANDLE      ?
    ObjectName                          PUNICODE_STRING ?
    Attributes                          DD          ?
    SecurityDescriptor                  PVOID       ?
    SecurityQualityOfService            PVOID       ?
OBJECT_ATTRIBUTES EndS
POBJECT_ATTRIBUTES                      TypeDef     DWord

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

KIRQL                                   TypeDef     Byte
PKIRQL                                  TypeDef     DWord

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
LANG_INVARIANT                          Equ         7FH

LANG_AFRIKAANS                          Equ         36H
LANG_ALBANIAN                           Equ         1CH
LANG_ALSATIAN                           Equ         84H
LANG_AMHARIC                            Equ         5EH
LANG_ARABIC                             Equ         01H
LANG_ARMENIAN                           Equ         2BH
LANG_ASSAMESE                           Equ         4DH
LANG_AZERI                              Equ         2CH
LANG_AZERBAIJANI                        Equ         2CH
LANG_BANGLA                             Equ         45H
LANG_BASHKIR                            Equ         6dH
LANG_BASQUE                             Equ         2DH
LANG_BELARUSIAN                         Equ         23H
LANG_BENGALI                            Equ         45H
LANG_BRETON                             Equ         7EH
LANG_BOSNIAN                            Equ         1AH
LANG_BOSNIAN_NEUTRAL                    Equ         781AH
LANG_BULGARIAN                          Equ         02H
LANG_CATALAN                            Equ         03H
LANG_CENTRAL_KURDISH                    Equ         92H
LANG_CHEROKEE                           Equ         5CH
LANG_CHINESE                            Equ         04H
LANG_CHINESE_SIMPLIFIED                 Equ         04H
LANG_CHINESE_TRADITIONAL                Equ         7C04H
LANG_CORSICAN                           Equ         83H
LANG_CROATIAN                           Equ         1AH
LANG_CZECH                              Equ         05H
LANG_DANISH                             Equ         06H
LANG_DARI                               Equ         8CH
LANG_DIVEHI                             Equ         65H
LANG_DUTCH                              Equ         13H
LANG_ENGLISH                            Equ         09H
LANG_ESTONIAN                           Equ         25H
LANG_FAEROESE                           Equ         38H
LANG_FARSI                              Equ         29H
LANG_FILIPINO                           Equ         64H
LANG_FINNISH                            Equ         0BH
LANG_FRENCH                             Equ         0CH
LANG_FRISIAN                            Equ         62H
LANG_FULAH                              Equ         67H
LANG_GALICIAN                           Equ         56H
LANG_GEORGIAN                           Equ         37H
LANG_GERMAN                             Equ         07H
LANG_GREEK                              Equ         08H
LANG_GREENLANDIC                        Equ         6FH
LANG_GUJARATI                           Equ         47H
LANG_HAUSA                              Equ         68H
LANG_HAWAIIAN                           Equ         75H
LANG_HEBREW                             Equ         0DH
LANG_HINDI                              Equ         39H
LANG_HUNGARIAN                          Equ         0EH
LANG_ICELANDIC                          Equ         0FH
LANG_IGBO                               Equ         70H
LANG_INDONESIAN                         Equ         21H
LANG_INUKTITUT                          Equ         5DH
LANG_IRISH                              Equ         3CH
LANG_ITALIAN                            Equ         10H
LANG_JAPANESE                           Equ         11H
LANG_KANNADA                            Equ         4BH
LANG_KASHMIRI                           Equ         60H
LANG_KAZAK                              Equ         3FH
LANG_KHMER                              Equ         53H
LANG_KICHE                              Equ         86H
LANG_KINYARWANDA                        Equ         87H
LANG_KONKANI                            Equ         57H
LANG_KOREAN                             Equ         12H
LANG_KYRGYZ                             Equ         40H
LANG_LAO                                Equ         54H
LANG_LATVIAN                            Equ         26H
LANG_LITHUANIAN                         Equ         27H
LANG_LOWER_SORBIAN                      Equ         2EH
LANG_LUXEMBOURGISH                      Equ         6EH
LANG_MACEDONIAN                         Equ         2FH
LANG_MALAY                              Equ         3EH
LANG_MALAYALAM                          Equ         4CH
LANG_MALTESE                            Equ         3AH
LANG_MANIPURI                           Equ         58H
LANG_MAORI                              Equ         81H
LANG_MAPUDUNGUN                         Equ         7AH
LANG_MARATHI                            Equ         4EH
LANG_MOHAWK                             Equ         7CH
LANG_MONGOLIAN                          Equ         50H
LANG_NEPALI                             Equ         61H
LANG_NORWEGIAN                          Equ         14H
LANG_OCCITAN                            Equ         82H
LANG_ODIA                               Equ         48H
LANG_ORIYA                              Equ         48H
LANG_PASHTO                             Equ         63H
LANG_PERSIAN                            Equ         29H
LANG_POLISH                             Equ         15H
LANG_PORTUGUESE                         Equ         16H
LANG_PULAR                              Equ         67H
LANG_PUNJABI                            Equ         46H
LANG_QUECHUA                            Equ         6BH
LANG_ROMANIAN                           Equ         18H
LANG_ROMANSH                            Equ         17H
LANG_RUSSIAN                            Equ         19H
LANG_SAKHA                              Equ         85H
LANG_SAMI                               Equ         3BH
LANG_SANSKRIT                           Equ         4FH
LANG_SCOTTISH_GAELIC                    Equ         91H
LANG_SERBIAN                            Equ         1AH
LANG_SERBIAN_NEUTRAL                    Equ         7C1AH
LANG_SINDHI                             Equ         59H
LANG_SINHALESE                          Equ         5BH
LANG_SLOVAK                             Equ         1BH
LANG_SLOVENIAN                          Equ         24H
LANG_SOTHO                              Equ         6CH
LANG_SPANISH                            Equ         0AH
LANG_SWAHILI                            Equ         41H
LANG_SWEDISH                            Equ         1DH
LANG_SYRIAC                             Equ         5AH
LANG_TAJIK                              Equ         28H
LANG_TAMAZIGHT                          Equ         5FH
LANG_TAMIL                              Equ         49H
LANG_TATAR                              Equ         44H
LANG_TELUGU                             Equ         4AH
LANG_THAI                               Equ         1EH
LANG_TIBETAN                            Equ         51H
LANG_TIGRIGNA                           Equ         73H
LANG_TIGRINYA                           Equ         73H
LANG_TSWANA                             Equ         32H
LANG_TURKISH                            Equ         1FH
LANG_TURKMEN                            Equ         42H
LANG_UIGHUR                             Equ         80H
LANG_UKRAINIAN                          Equ         22H
LANG_UPPER_SORBIAN                      Equ         2EH
LANG_URDU                               Equ         20H
LANG_UZBEK                              Equ         43H
LANG_VALENCIAN                          Equ         03H
LANG_VIETNAMESE                         Equ         2AH
LANG_WELSH                              Equ         52H
LANG_WOLOF                              Equ         88H
LANG_XHOSA                              Equ         34H
LANG_YAKUT                              Equ         85H
LANG_YI                                 Equ         78H
LANG_YORUBA                             Equ         6AH
LANG_ZULU                               Equ         35H

SUBLANG_NEUTRAL                         Equ         00H
SUBLANG_DEFAULT                         Equ         01H
SUBLANG_SYS_DEFAULT                     Equ         02H

SUBLANG_CUSTOM_DEFAULT                  Equ         03H
SUBLANG_CUSTOM_UNSPECIFIED              Equ         04H
SUBLANG_UI_CUSTOM_DEFAULT               Equ         05H

SUBLANG_AFRIKAANS_SOUTH_AFRICA          Equ         01H
SUBLANG_ALBANIAN_ALBANIA                Equ         01H
SUBLANG_ALSATIAN_FRANCE                 Equ         01H
SUBLANG_AMHARIC_ETHIOPIA                Equ         01H
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
SUBLANG_ARMENIAN_ARMENIA                Equ         01H
SUBLANG_ASSAMESE_INDIA                  Equ         01H
SUBLANG_AZERI_LATIN                     Equ         01H
SUBLANG_AZERI_CYRILLIC                  Equ         02H
SUBLANG_AZERBAIJANI_AZERBAIJAN_LATIN    Equ         01H
SUBLANG_AZERBAIJANI_AZERBAIJAN_CYRILLIC Equ         02H
SUBLANG_BANGLA_INDIA                    Equ         01H
SUBLANG_BANGLA_BANGLADESH               Equ         02H
SUBLANG_BASHKIR_RUSSIA                  Equ         01H
SUBLANG_BASQUE_BASQUE                   Equ         01H
SUBLANG_BELARUSIAN_BELARUS              Equ         01H
SUBLANG_BENGALI_INDIA                   Equ         01H
SUBLANG_BENGALI_BANGLADESH              Equ         02H
SUBLANG_BOSNIAN_BOSNIA_HERZEGOVINA_LATIN Equ        05H
SUBLANG_BOSNIAN_BOSNIA_HERZEGOVINA_CYRILLIC Equ     08H
SUBLANG_BRETON_FRANCE                   Equ         01H
SUBLANG_BULGARIAN_BULGARIA              Equ         01H
SUBLANG_CATALAN_CATALAN                 Equ         01H
SUBLANG_CENTRAL_KURDISH_IRAQ            Equ         01H
SUBLANG_CHEROKEE_CHEROKEE               Equ         01H
SUBLANG_CHINESE_TRADITIONAL             Equ         01H
SUBLANG_CHINESE_SIMPLIFIED              Equ         02H
SUBLANG_CHINESE_HONGKONG                Equ         03H
SUBLANG_CHINESE_SINGAPORE               Equ         04H
SUBLANG_CHINESE_MACAU                   Equ         05H
SUBLANG_CORSICAN_FRANCE                 Equ         01H
SUBLANG_CZECH_CZECH_REPUBLIC            Equ         01H
SUBLANG_CROATIAN_CROATIA                Equ         01H
SUBLANG_CROATIAN_BOSNIA_HERZEGOVINA_LATIN Equ       04H
SUBLANG_DANISH_DENMARK                  Equ         01H
SUBLANG_DARI_AFGHANISTAN                Equ         01H
SUBLANG_DIVEHI_MALDIVES                 Equ         01H
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
SUBLANG_ENGLISH_INDIA                   Equ         10H
SUBLANG_ENGLISH_MALAYSIA                Equ         11H
SUBLANG_ENGLISH_SINGAPORE               Equ         12H
SUBLANG_ESTONIAN_ESTONIA                Equ         01H
SUBLANG_FAEROESE_FAROE_ISLANDS          Equ         01H
SUBLANG_FILIPINO_PHILIPPINES            Equ         01H
SUBLANG_FINNISH_FINLAND                 Equ         01H
SUBLANG_FRENCH                          Equ         01H
SUBLANG_FRENCH_BELGIAN                  Equ         02H
SUBLANG_FRENCH_CANADIAN                 Equ         03H
SUBLANG_FRENCH_SWISS                    Equ         04H
SUBLANG_FRENCH_LUXEMBOURG               Equ         05H
SUBLANG_FRENCH_MONACO                   Equ         06H
SUBLANG_FRISIAN_NETHERLANDS             Equ         01H
SUBLANG_FULAH_SENEGAL                   Equ         02H
SUBLANG_GALICIAN_GALICIAN               Equ         01H
SUBLANG_GEORGIAN_GEORGIA                Equ         01H
SUBLANG_GERMAN                          Equ         01H
SUBLANG_GERMAN_SWISS                    Equ         02H
SUBLANG_GERMAN_AUSTRIAN                 Equ         03H
SUBLANG_GERMAN_LUXEMBOURG               Equ         04H
SUBLANG_GERMAN_LIECHTENSTEIN            Equ         05H
SUBLANG_GREEK_GREECE                    Equ         01H
SUBLANG_GREENLANDIC_GREENLAND           Equ         01H
SUBLANG_GUJARATI_INDIA                  Equ         01H
SUBLANG_HAUSA_NIGERIA_LATIN             Equ         01H
SUBLANG_HAWAIIAN_US                     Equ         01H
SUBLANG_HEBREW_ISRAEL                   Equ         01H
SUBLANG_HINDI_INDIA                     Equ         01H
SUBLANG_HUNGARIAN_HUNGARY               Equ         01H
SUBLANG_ICELANDIC_ICELAND               Equ         01H
SUBLANG_IGBO_NIGERIA                    Equ         01H
SUBLANG_INDONESIAN_INDONESIA            Equ         01H
SUBLANG_INUKTITUT_CANADA                Equ         01H
SUBLANG_INUKTITUT_CANADA_LATIN          Equ         02H
SUBLANG_IRISH_IRELAND                   Equ         02H
SUBLANG_ITALIAN                         Equ         01H
SUBLANG_ITALIAN_SWISS                   Equ         02H
SUBLANG_JAPANESE_JAPAN                  Equ         01H
SUBLANG_KANNADA_INDIA                   Equ         01H
SUBLANG_KASHMIRI_SASIA                  Equ         02H
SUBLANG_KASHMIRI_INDIA                  Equ         02H
SUBLANG_KAZAK_KAZAKHSTAN                Equ         01H
SUBLANG_KHMER_CAMBODIA                  Equ         01H
SUBLANG_KICHE_GUATEMALA                 Equ         01H
SUBLANG_KINYARWANDA_RWANDA              Equ         01H
SUBLANG_KONKANI_INDIA                   Equ         01H
SUBLANG_KOREAN                          Equ         01H
SUBLANG_KYRGYZ_KYRGYZSTAN               Equ         01H
SUBLANG_LAO_LAO                         Equ         01H
SUBLANG_LATVIAN_LATVIA                  Equ         01H
SUBLANG_LITHUANIAN                      Equ         01H
SUBLANG_LOWER_SORBIAN_GERMANY           Equ         02H
SUBLANG_LUXEMBOURGISH_LUXEMBOURG        Equ         01H
SUBLANG_MACEDONIAN_MACEDONIA            Equ         01H
SUBLANG_MALAY_MALAYSIA                  Equ         01H
SUBLANG_MALAY_BRUNEI_DARUSSALAM         Equ         02H
SUBLANG_MALAYALAM_INDIA                 Equ         01H
SUBLANG_MALTESE_MALTA                   Equ         01H
SUBLANG_MAORI_NEW_ZEALAND               Equ         01H
SUBLANG_MAPUDUNGUN_CHILE                Equ         01H
SUBLANG_MARATHI_INDIA                   Equ         01H
SUBLANG_MOHAWK_MOHAWK                   Equ         01H
SUBLANG_MONGOLIAN_CYRILLIC_MONGOLIA     Equ         01H
SUBLANG_MONGOLIAN_PRC                   Equ         02H
SUBLANG_NEPALI_INDIA                    Equ         02H
SUBLANG_NEPALI_NEPAL                    Equ         01H
SUBLANG_NORWEGIAN_BOKMAL                Equ         01H
SUBLANG_NORWEGIAN_NYNORSK               Equ         02H
SUBLANG_OCCITAN_FRANCE                  Equ         01H
SUBLANG_ODIA_INDIA                      Equ         01H
SUBLANG_ORIYA_INDIA                     Equ         01H
SUBLANG_PASHTO_AFGHANISTAN              Equ         01H
SUBLANG_PERSIAN_IRAN                    Equ         01H
SUBLANG_POLISH_POLAND                   Equ         01H
SUBLANG_PORTUGUESE                      Equ         02H
SUBLANG_PORTUGUESE_BRAZILIAN            Equ         01H
SUBLANG_PULAR_SENEGAL                   Equ         02H
SUBLANG_PUNJABI_INDIA                   Equ         01H
SUBLANG_PUNJABI_PAKISTAN                Equ         02H
SUBLANG_QUECHUA_BOLIVIA                 Equ         01H
SUBLANG_QUECHUA_ECUADOR                 Equ         02H
SUBLANG_QUECHUA_PERU                    Equ         03H
SUBLANG_ROMANIAN_ROMANIA                Equ         01H
SUBLANG_ROMANSH_SWITZERLAND             Equ         01H
SUBLANG_RUSSIAN_RUSSIA                  Equ         01H
SUBLANG_SAKHA_RUSSIA                    Equ         01H
SUBLANG_SAMI_NORTHERN_NORWAY            Equ         01H
SUBLANG_SAMI_NORTHERN_SWEDEN            Equ         02H
SUBLANG_SAMI_NORTHERN_FINLAND           Equ         03H
SUBLANG_SAMI_LULE_NORWAY                Equ         04H
SUBLANG_SAMI_LULE_SWEDEN                Equ         05H
SUBLANG_SAMI_SOUTHERN_NORWAY            Equ         06H
SUBLANG_SAMI_SOUTHERN_SWEDEN            Equ         07H
SUBLANG_SAMI_SKOLT_FINLAND              Equ         08H
SUBLANG_SAMI_INARI_FINLAND              Equ         09H
SUBLANG_SANSKRIT_INDIA                  Equ         01H
SUBLANG_SCOTTISH_GAELIC                 Equ         01H
SUBLANG_SERBIAN_BOSNIA_HERZEGOVINA_LATIN Equ        06H
SUBLANG_SERBIAN_BOSNIA_HERZEGOVINA_CYRILLIC Equ     07H
SUBLANG_SERBIAN_MONTENEGRO_LATIN        Equ         0BH
SUBLANG_SERBIAN_MONTENEGRO_CYRILLIC     Equ         0CH
SUBLANG_SERBIAN_SERBIA_LATIN            Equ         09H
SUBLANG_SERBIAN_SERBIA_CYRILLIC         Equ         0AH
SUBLANG_SERBIAN_CROATIA                 Equ         01H
SUBLANG_SERBIAN_LATIN                   Equ         02H
SUBLANG_SERBIAN_CYRILLIC                Equ         03H
SUBLANG_SINDHI_INDIA                    Equ         01H
SUBLANG_SINDHI_PAKISTAN                 Equ         02H
SUBLANG_SINDHI_AFGHANISTAN              Equ         02H
SUBLANG_SINHALESE_SRI_LANKA             Equ         01H
SUBLANG_SOTHO_NORTHERN_SOUTH_AFRICA     Equ         01H
SUBLANG_SLOVAK_SLOVAKIA                 Equ         01H
SUBLANG_SLOVENIAN_SLOVENIA              Equ         01H
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
SUBLANG_SPANISH_US                      Equ         15H
SUBLANG_SWAHILI_KENYA                   Equ         01H
SUBLANG_SWEDISH                         Equ         01H
SUBLANG_SWEDISH_FINLAND                 Equ         02H
SUBLANG_SYRIAC_SYRIA                    Equ         01H
SUBLANG_TAJIK_TAJIKISTAN                Equ         01H
SUBLANG_TAMAZIGHT_ALGERIA_LATIN         Equ         02H
SUBLANG_TAMAZIGHT_MOROCCO_TIFINAGH      Equ         04H
SUBLANG_TAMIL_INDIA                     Equ         01H
SUBLANG_TAMIL_SRI_LANKA                 Equ         02H
SUBLANG_TATAR_RUSSIA                    Equ         01H
SUBLANG_TELUGU_INDIA                    Equ         01H
SUBLANG_THAI_THAILAND                   Equ         01H
SUBLANG_TIBETAN_PRC                     Equ         01H
SUBLANG_TIGRIGNA_ERITREA                Equ         02H
SUBLANG_TIGRINYA_ERITREA                Equ         02H
SUBLANG_TIGRINYA_ETHIOPIA               Equ         01H
SUBLANG_TSWANA_BOTSWANA                 Equ         02H
SUBLANG_TSWANA_SOUTH_AFRICA             Equ         01H
SUBLANG_TURKISH_TURKEY                  Equ         01H
SUBLANG_TURKMEN_TURKMENISTAN            Equ         01H
SUBLANG_UIGHUR_PRC                      Equ         01H
SUBLANG_UKRAINIAN_UKRAINE               Equ         01H
SUBLANG_UPPER_SORBIAN_GERMANY           Equ         01H
SUBLANG_URDU_PAKISTAN                   Equ         01H
SUBLANG_URDU_INDIA                      Equ         02H
SUBLANG_UZBEK_LATIN                     Equ         01H
SUBLANG_UZBEK_CYRILLIC                  Equ         02H
SUBLANG_VALENCIAN_VALENCIA              Equ         02H
SUBLANG_VIETNAMESE_VIETNAM              Equ         01H
SUBLANG_WELSH_UNITED_KINGDOM            Equ         01H
SUBLANG_WOLOF_SENEGAL                   Equ         01H
SUBLANG_XHOSA_SOUTH_AFRICA              Equ         01H
SUBLANG_YAKUT_RUSSIA                    Equ         01H
SUBLANG_YI_PRC                          Equ         01H
SUBLANG_YORUBA_NIGERIA                  Equ         01H
SUBLANG_ZULU_SOUTH_AFRICA               Equ         01H

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

ENDIF ;NTDEF_INC
