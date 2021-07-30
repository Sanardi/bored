; ====================================================;
;                                                     ;
;    kernel32.inc for EC v2 SolAsm visual projects    ;
;                   (version 1.0.4)                   ;
;                                                     ;
;         Copyright © Ramon Sala - 2018-2021          ;
;                                                     ;
; ====================================================;

#ifndef KERNEL32_INC
KERNEL32_INC equ 1

#ifdef APP_WIN64
    define MAX_NATURAL_ALIGNMENT                dq
#else
    define MAX_NATURAL_ALIGNMENT                dd
#endif

#ifndef UCSCHAR_INVALID_CHARACTER
    UCSCHAR_INVALID_CHARACTER                   equ     0FFFFFFFFH
    MIN_UCSCHAR                                 equ     0
    MAX_UCSCHAR                                 equ     0010FFFFH
#endif

MAXLONGLONG                                     equ     7FFFFFFFFFFFFFFFH

ANSI_NULL                                       equ     0
UNICODE_NULL                                    equ     0

MINCHAR                                         equ     80H
MAXCHAR                                         equ     7FH
MINSHORT                                        equ     8000H
MAXSHORT                                        equ     7FFFH
MINLONG                                         equ     80000000H
MAXBYTE                                         equ     0FFH
MAXWORD                                         equ     0FFFFH
MAXDWORD                                        equ     0FFFFFFFFH

NLS_VALID_LOCALE_MASK                           equ     000FFFFFH

VER_SERVER_NT                                   equ     80000000H
VER_WORKSTATION_NT                              equ     40000000H
VER_SUITE_SMALLBUSINESS                         equ     00000001H
VER_SUITE_ENTERPRISE                            equ     00000002H
VER_SUITE_BACKOFFICE                            equ     00000004H
VER_SUITE_COMMUNICATIONS                        equ     00000008H
VER_SUITE_TERMINAL                              equ     00000010H
VER_SUITE_SMALLBUSINESS_RESTRICTED              equ     00000020H
VER_SUITE_EMBEDDEDNT                            equ     00000040H
VER_SUITE_DATACENTER                            equ     00000080H
VER_SUITE_SINGLEUSERTS                          equ     00000100H
VER_SUITE_PERSONAL                              equ     00000200H
VER_SUITE_BLADE                                 equ     00000400H
VER_SUITE_EMBEDDED_RESTRICTED                   equ     00000800H
VER_SUITE_SECURITY_APPLIANCE                    equ     00001000H
VER_SUITE_STORAGE_SERVER                        equ     00002000H
VER_SUITE_COMPUTE_SERVER                        equ     00004000H
VER_SUITE_WH_SERVER                             equ     00008000H

ActivationContextBasicInformation               equ     1
ActivationContextDetailedInformation            equ     2
AssemblyDetailedInformationInActivationContext  equ     3
FileInformationInAssemblyOfAssemblyInActivationContext  equ 4
RunlevelInformationInActivationContext          equ     5
CompatibilityInformationInActivationContext     equ     6
ActivationContextManifestResourceName           equ     7
MaxActivationContextInfoClass                   equ     8

AssemblyDetailedInformationInActivationContxt   equ     3
FileInformationInAssemblyOfAssemblyInActivationContxt   equ 4

PRODUCT_UNDEFINED                               equ     00000000H

PRODUCT_ULTIMATE                                equ     00000001H
PRODUCT_HOME_BASIC                              equ     00000002H
PRODUCT_HOME_PREMIUM                            equ     00000003H
PRODUCT_ENTERPRISE                              equ     00000004H
PRODUCT_HOME_BASIC_N                            equ     00000005H
PRODUCT_BUSINESS                                equ     00000006H
PRODUCT_STANDARD_SERVER                         equ     00000007H
PRODUCT_DATACENTER_SERVER                       equ     00000008H
PRODUCT_SMALLBUSINESS_SERVER                    equ     00000009H
PRODUCT_ENTERPRISE_SERVER                       equ     0000000AH
PRODUCT_STARTER                                 equ     0000000BH
PRODUCT_DATACENTER_SERVER_CORE                  equ     0000000CH
PRODUCT_STANDARD_SERVER_CORE                    equ     0000000DH
PRODUCT_ENTERPRISE_SERVER_CORE                  equ     0000000EH
PRODUCT_ENTERPRISE_SERVER_IA64                  equ     0000000FH
PRODUCT_BUSINESS_N                              equ     00000010H
PRODUCT_WEB_SERVER                              equ     00000011H
PRODUCT_CLUSTER_SERVER                          equ     00000012H
PRODUCT_HOME_SERVER                             equ     00000013H
PRODUCT_STORAGE_EXPRESS_SERVER                  equ     00000014H
PRODUCT_STORAGE_STANDARD_SERVER                 equ     00000015H
PRODUCT_STORAGE_WORKGROUP_SERVER                equ     00000016H
PRODUCT_STORAGE_ENTERPRISE_SERVER               equ     00000017H
PRODUCT_SERVER_FOR_SMALLBUSINESS                equ     00000018H
PRODUCT_SMALLBUSINESS_SERVER_PREMIUM            equ     00000019H
PRODUCT_HOME_PREMIUM_N                          equ     0000001AH
PRODUCT_ENTERPRISE_N                            equ     0000001BH
PRODUCT_ULTIMATE_N                              equ     0000001CH
PRODUCT_WEB_SERVER_CORE                         equ     0000001DH
PRODUCT_MEDIUMBUSINESS_SERVER_MANAGEMENT        equ     0000001EH
PRODUCT_MEDIUMBUSINESS_SERVER_SECURITY          equ     0000001FH
PRODUCT_MEDIUMBUSINESS_SERVER_MESSAGING         equ     00000020H
PRODUCT_SERVER_FOUNDATION                       equ     00000021H
PRODUCT_HOME_PREMIUM_SERVER                     equ     00000022H
PRODUCT_SERVER_FOR_SMALLBUSINESS_V              equ     00000023H
PRODUCT_STANDARD_SERVER_V                       equ     00000024H
PRODUCT_DATACENTER_SERVER_V                     equ     00000025H
PRODUCT_ENTERPRISE_SERVER_V                     equ     00000026H
PRODUCT_DATACENTER_SERVER_CORE_V                equ     00000027H
PRODUCT_STANDARD_SERVER_CORE_V                  equ     00000028H
PRODUCT_ENTERPRISE_SERVER_CORE_V                equ     00000029H
PRODUCT_HYPERV                                  equ     0000002AH
PRODUCT_STORAGE_EXPRESS_SERVER_CORE             equ     0000002BH
PRODUCT_STORAGE_STANDARD_SERVER_CORE            equ     0000002CH
PRODUCT_STORAGE_WORKGROUP_SERVER_CORE           equ     0000002DH
PRODUCT_STORAGE_ENTERPRISE_SERVER_CORE          equ     0000002EH
PRODUCT_STARTER_N                               equ     0000002FH
PRODUCT_PROFESSIONAL                            equ     00000030H
PRODUCT_PROFESSIONAL_N                          equ     00000031H
PRODUCT_SB_SOLUTION_SERVER                      equ     00000032H
PRODUCT_SERVER_FOR_SB_SOLUTIONS                 equ     00000033H
PRODUCT_STANDARD_SERVER_SOLUTIONS               equ     00000034H
PRODUCT_STANDARD_SERVER_SOLUTIONS_CORE          equ     00000035H
PRODUCT_SB_SOLUTION_SERVER_EM                   equ     00000036H
PRODUCT_SERVER_FOR_SB_SOLUTIONS_EM              equ     00000037H
PRODUCT_SOLUTION_EMBEDDEDSERVER                 equ     00000038H
PRODUCT_SOLUTION_EMBEDDEDSERVER_CORE            equ     00000039H
PRODUCT_SMALLBUSINESS_SERVER_PREMIUM_CORE       equ     0000003FH
PRODUCT_ESSENTIALBUSINESS_SERVER_MGMT           equ     0000003BH
PRODUCT_ESSENTIALBUSINESS_SERVER_ADDL           equ     0000003CH
PRODUCT_ESSENTIALBUSINESS_SERVER_MGMTSVC        equ     0000003DH
PRODUCT_ESSENTIALBUSINESS_SERVER_ADDLSVC        equ     0000003EH
PRODUCT_CLUSTER_SERVER_V                        equ     00000040H
PRODUCT_EMBEDDED                                equ     00000041H
PRODUCT_STARTER_E                               equ     00000042H
PRODUCT_HOME_BASIC_E                            equ     00000043H
PRODUCT_HOME_PREMIUM_E                          equ     00000044H
PRODUCT_PROFESSIONAL_E                          equ     00000045H
PRODUCT_ENTERPRISE_E                            equ     00000046H
PRODUCT_ULTIMATE_E                              equ     00000047H
PRODUCT_UNLICENSED                              equ     0ABCDABCDH

LOCALE_USER_DEFAULT                             equ     0400H

LOCALE_SYSTEM_DEFAULT                           equ     2048
#ifndef LOCALE_NOUSEROVERRIDE
    LOCALE_NOUSEROVERRIDE                       equ     80000000H
#endif
LANG_NEUTRAL                                    equ     00H
LANG_INVARIANT                                  equ     7FH

LANG_AFRIKAANS                                  equ     36H
LANG_ALBANIAN                                   equ     1CH
LANG_ALSATIAN                                   equ     84H
LANG_AMHARIC                                    equ     5EH
LANG_ARABIC                                     equ     01H
LANG_ARMENIAN                                   equ     2BH
LANG_ASSAMESE                                   equ     4DH
LANG_AZERI                                      equ     2CH
LANG_AZERBAIJANI                                equ     2CH
LANG_BANGLA                                     equ     45H
LANG_BASHKIR                                    equ     6dH
LANG_BASQUE                                     equ     2DH
LANG_BELARUSIAN                                 equ     23H
LANG_BENGALI                                    equ     45H
LANG_BRETON                                     equ     7EH
LANG_BOSNIAN                                    equ     1AH
LANG_BOSNIAN_NEUTRAL                            equ     781AH
LANG_BULGARIAN                                  equ     02H
LANG_CATALAN                                    equ     03H
LANG_CENTRAL_KURDISH                            equ     92H
LANG_CHEROKEE                                   equ     5CH
LANG_CHINESE                                    equ     04H
LANG_CHINESE_SIMPLIFIED                         equ     04H
LANG_CHINESE_TRADITIONAL                        equ     7C04H
LANG_CORSICAN                                   equ     83H
LANG_CROATIAN                                   equ     1AH
LANG_CZECH                                      equ     05H
LANG_DANISH                                     equ     06H
LANG_DARI                                       equ     8CH
LANG_DIVEHI                                     equ     65H
LANG_DUTCH                                      equ     13H
LANG_ENGLISH                                    equ     09H
LANG_ESTONIAN                                   equ     25H
LANG_FAEROESE                                   equ     38H
LANG_FARSI                                      equ     29H
LANG_FILIPINO                                   equ     64H
LANG_FINNISH                                    equ     0BH
LANG_FRENCH                                     equ     0CH
LANG_FRISIAN                                    equ     62H
LANG_FULAH                                      equ     67H
LANG_GALICIAN                                   equ     56H
LANG_GEORGIAN                                   equ     37H
LANG_GERMAN                                     equ     07H
LANG_GREEK                                      equ     08H
LANG_GREENLANDIC                                equ     6FH
LANG_GUJARATI                                   equ     47H
LANG_HAUSA                                      equ     68H
LANG_HAWAIIAN                                   equ     75H
LANG_HEBREW                                     equ     0DH
LANG_HINDI                                      equ     39H
LANG_HUNGARIAN                                  equ     0EH
LANG_ICELANDIC                                  equ     0FH
LANG_IGBO                                       equ     70H
LANG_INDONESIAN                                 equ     21H
LANG_INUKTITUT                                  equ     5DH
LANG_IRISH                                      equ     3CH
LANG_ITALIAN                                    equ     10H
LANG_JAPANESE                                   equ     11H
LANG_KANNADA                                    equ     4BH
LANG_KASHMIRI                                   equ     60H
LANG_KAZAK                                      equ     3FH
LANG_KHMER                                      equ     53H
LANG_KICHE                                      equ     86H
LANG_KINYARWANDA                                equ     87H
LANG_KONKANI                                    equ     57H
LANG_KOREAN                                     equ     12H
LANG_KYRGYZ                                     equ     40H
LANG_LAO                                        equ     54H
LANG_LATVIAN                                    equ     26H
LANG_LITHUANIAN                                 equ     27H
LANG_LOWER_SORBIAN                              equ     2EH
LANG_LUXEMBOURGISH                              equ     6EH
LANG_MACEDONIAN                                 equ     2FH
LANG_MALAY                                      equ     3EH
LANG_MALAYALAM                                  equ     4CH
LANG_MALTESE                                    equ     3AH
LANG_MANIPURI                                   equ     58H
LANG_MAORI                                      equ     81H
LANG_MAPUDUNGUN                                 equ     7AH
LANG_MARATHI                                    equ     4EH
LANG_MOHAWK                                     equ     7CH
LANG_MONGOLIAN                                  equ     50H
LANG_NEPALI                                     equ     61H
LANG_NORWEGIAN                                  equ     14H
LANG_OCCITAN                                    equ     82H
LANG_ODIA                                       equ     48H
LANG_ORIYA                                      equ     48H
LANG_PASHTO                                     equ     63H
LANG_PERSIAN                                    equ     29H
LANG_POLISH                                     equ     15H
LANG_PORTUGUESE                                 equ     16H
LANG_PULAR                                      equ     67H
LANG_PUNJABI                                    equ     46H
LANG_QUECHUA                                    equ     6BH
LANG_ROMANIAN                                   equ     18H
LANG_ROMANSH                                    equ     17H
LANG_RUSSIAN                                    equ     19H
LANG_SAKHA                                      equ     85H
LANG_SAMI                                       equ     3BH
LANG_SANSKRIT                                   equ     4FH
LANG_SCOTTISH_GAELIC                            equ     91H
LANG_SERBIAN                                    equ     1AH
LANG_SERBIAN_NEUTRAL                            equ     7C1AH
LANG_SINDHI                                     equ     59H
LANG_SINHALESE                                  equ     5BH
LANG_SLOVAK                                     equ     1BH
LANG_SLOVENIAN                                  equ     24H
LANG_SOTHO                                      equ     6CH
LANG_SPANISH                                    equ     0AH
LANG_SWAHILI                                    equ     41H
LANG_SWEDISH                                    equ     1DH
LANG_SYRIAC                                     equ     5AH
LANG_TAJIK                                      equ     28H
LANG_TAMAZIGHT                                  equ     5FH
LANG_TAMIL                                      equ     49H
LANG_TATAR                                      equ     44H
LANG_TELUGU                                     equ     4AH
LANG_THAI                                       equ     1EH
LANG_TIBETAN                                    equ     51H
LANG_TIGRIGNA                                   equ     73H
LANG_TIGRINYA                                   equ     73H
LANG_TSWANA                                     equ     32H
LANG_TURKISH                                    equ     1FH
LANG_TURKMEN                                    equ     42H
LANG_UIGHUR                                     equ     80H
LANG_UKRAINIAN                                  equ     22H
LANG_UPPER_SORBIAN                              equ     2EH
LANG_URDU                                       equ     20H
LANG_UZBEK                                      equ     43H
LANG_VALENCIAN                                  equ     03H
LANG_VIETNAMESE                                 equ     2AH
LANG_WELSH                                      equ     52H
LANG_WOLOF                                      equ     88H
LANG_XHOSA                                      equ     34H
LANG_YAKUT                                      equ     85H
LANG_YI                                         equ     78H
LANG_YORUBA                                     equ     6AH
LANG_ZULU                                       equ     35H

SUBLANG_NEUTRAL                                 equ     00H
SUBLANG_DEFAULT                                 equ     01H
SUBLANG_SYS_DEFAULT                             equ     02H
SUBLANG_CUSTOM_DEFAULT                          equ     03H
SUBLANG_CUSTOM_UNSPECIFIED                      equ     04H
SUBLANG_UI_CUSTOM_DEFAULT                       equ     05H

SUBLANG_AFRIKAANS_SOUTH_AFRICA                  equ     01H
SUBLANG_ALBANIAN_ALBANIA                        equ     01H
SUBLANG_ALSATIAN_FRANCE                         equ     01H
SUBLANG_AMHARIC_ETHIOPIA                        equ     01H
SUBLANG_ARABIC_SAUDI_ARABIA                     equ     01H
SUBLANG_ARABIC_IRAQ                             equ     02H
SUBLANG_ARABIC_EGYPT                            equ     03H
SUBLANG_ARABIC_LIBYA                            equ     04H
SUBLANG_ARABIC_ALGERIA                          equ     05H
SUBLANG_ARABIC_MOROCCO                          equ     06H
SUBLANG_ARABIC_TUNISIA                          equ     07H
SUBLANG_ARABIC_OMAN                             equ     08H
SUBLANG_ARABIC_YEMEN                            equ     09H
SUBLANG_ARABIC_SYRIA                            equ     0AH
SUBLANG_ARABIC_JORDAN                           equ     0BH
SUBLANG_ARABIC_LEBANON                          equ     0CH
SUBLANG_ARABIC_KUWAIT                           equ     0DH
SUBLANG_ARABIC_UAE                              equ     0EH
SUBLANG_ARABIC_BAHRAIN                          equ     0FH
SUBLANG_ARABIC_QATAR                            equ     10H
SUBLANG_ARMENIAN_ARMENIA                        equ     01H
SUBLANG_ASSAMESE_INDIA                          equ     01H
SUBLANG_AZERI_LATIN                             equ     01H
SUBLANG_AZERI_CYRILLIC                          equ     02H
SUBLANG_AZERBAIJANI_AZERBAIJAN_LATIN            equ     01H
SUBLANG_AZERBAIJANI_AZERBAIJAN_CYRILLIC         equ     02H
SUBLANG_BANGLA_INDIA                            equ     01H
SUBLANG_BANGLA_BANGLADESH                       equ     02H
SUBLANG_BASHKIR_RUSSIA                          equ     01H
SUBLANG_BASQUE_BASQUE                           equ     01H
SUBLANG_BELARUSIAN_BELARUS                      equ     01H
SUBLANG_BENGALI_INDIA                           equ     01H
SUBLANG_BENGALI_BANGLADESH                      equ     02H
SUBLANG_BOSNIAN_BOSNIA_HERZEGOVINA_LATIN        equ     05H
SUBLANG_BOSNIAN_BOSNIA_HERZEGOVINA_CYRILLIC     equ     08H
SUBLANG_BRETON_FRANCE                           equ     01H
SUBLANG_BULGARIAN_BULGARIA                      equ     01H
SUBLANG_CATALAN_CATALAN                         equ     01H
SUBLANG_CENTRAL_KURDISH_IRAQ                    equ     01H
SUBLANG_CHEROKEE_CHEROKEE                       equ     01H
SUBLANG_CHINESE_TRADITIONAL                     equ     01H
SUBLANG_CHINESE_SIMPLIFIED                      equ     02H
SUBLANG_CHINESE_HONGKONG                        equ     03H
SUBLANG_CHINESE_SINGAPORE                       equ     04H
SUBLANG_CHINESE_MACAU                           equ     05H
SUBLANG_CORSICAN_FRANCE                         equ     01H
SUBLANG_CZECH_CZECH_REPUBLIC                    equ     01H
SUBLANG_CROATIAN_CROATIA                        equ     01H
SUBLANG_CROATIAN_BOSNIA_HERZEGOVINA_LATIN       equ     04H
SUBLANG_DANISH_DENMARK                          equ     01H
SUBLANG_DARI_AFGHANISTAN                        equ     01H
SUBLANG_DIVEHI_MALDIVES                         equ     01H
SUBLANG_DUTCH                                   equ     01H
SUBLANG_DUTCH_BELGIAN                           equ     02H
SUBLANG_ENGLISH_US                              equ     01H
SUBLANG_ENGLISH_UK                              equ     02H
SUBLANG_ENGLISH_AUS                             equ     03H
SUBLANG_ENGLISH_CAN                             equ     04H
SUBLANG_ENGLISH_NZ                              equ     05H
SUBLANG_ENGLISH_EIRE                            equ     06H
SUBLANG_ENGLISH_SOUTH_AFRICA                    equ     07H
SUBLANG_ENGLISH_JAMAICA                         equ     08H
SUBLANG_ENGLISH_CARIBBEAN                       equ     09H
SUBLANG_ENGLISH_BELIZE                          equ     0AH
SUBLANG_ENGLISH_TRINIDAD                        equ     0BH
SUBLANG_ENGLISH_ZIMBABWE                        equ     0CH
SUBLANG_ENGLISH_PHILIPPINES                     equ     0DH
SUBLANG_ENGLISH_INDIA                           equ     10H
SUBLANG_ENGLISH_MALAYSIA                        equ     11H
SUBLANG_ENGLISH_SINGAPORE                       equ     12H
SUBLANG_ESTONIAN_ESTONIA                        equ     01H
SUBLANG_FAEROESE_FAROE_ISLANDS                  equ     01H
SUBLANG_FILIPINO_PHILIPPINES                    equ     01H
SUBLANG_FINNISH_FINLAND                         equ     01H
SUBLANG_FRENCH                                  equ     01H
SUBLANG_FRENCH_BELGIAN                          equ     02H
SUBLANG_FRENCH_CANADIAN                         equ     03H
SUBLANG_FRENCH_SWISS                            equ     04H
SUBLANG_FRENCH_LUXEMBOURG                       equ     05H
SUBLANG_FRENCH_MONACO                           equ     06H
SUBLANG_FRISIAN_NETHERLANDS                     equ     01H
SUBLANG_FULAH_SENEGAL                           equ     02H
SUBLANG_GALICIAN_GALICIAN                       equ     01H
SUBLANG_GEORGIAN_GEORGIA                        equ     01H
SUBLANG_GERMAN                                  equ     01H
SUBLANG_GERMAN_SWISS                            equ     02H
SUBLANG_GERMAN_AUSTRIAN                         equ     03H
SUBLANG_GERMAN_LUXEMBOURG                       equ     04H
SUBLANG_GERMAN_LIECHTENSTEIN                    equ     05H
SUBLANG_GREEK_GREECE                            equ     01H
SUBLANG_GREENLANDIC_GREENLAND                   equ     01H
SUBLANG_GUJARATI_INDIA                          equ     01H
SUBLANG_HAUSA_NIGERIA_LATIN                     equ     01H
SUBLANG_HAWAIIAN_US                             equ     01H
SUBLANG_HEBREW_ISRAEL                           equ     01H
SUBLANG_HINDI_INDIA                             equ     01H
SUBLANG_HUNGARIAN_HUNGARY                       equ     01H
SUBLANG_ICELANDIC_ICELAND                       equ     01H
SUBLANG_IGBO_NIGERIA                            equ     01H
SUBLANG_INDONESIAN_INDONESIA                    equ     01H
SUBLANG_INUKTITUT_CANADA                        equ     01H
SUBLANG_INUKTITUT_CANADA_LATIN                  equ     02H
SUBLANG_IRISH_IRELAND                           equ     02H
SUBLANG_ITALIAN                                 equ     01H
SUBLANG_ITALIAN_SWISS                           equ     02H
SUBLANG_JAPANESE_JAPAN                          equ     01H
SUBLANG_KANNADA_INDIA                           equ     01H
SUBLANG_KASHMIRI_SASIA                          equ     02H
SUBLANG_KASHMIRI_INDIA                          equ     02H
SUBLANG_KAZAK_KAZAKHSTAN                        equ     01H
SUBLANG_KHMER_CAMBODIA                          equ     01H
SUBLANG_KICHE_GUATEMALA                         equ     01H
SUBLANG_KINYARWANDA_RWANDA                      equ     01H
SUBLANG_KONKANI_INDIA                           equ     01H
SUBLANG_KOREAN                                  equ     01H
SUBLANG_KYRGYZ_KYRGYZSTAN                       equ     01H
SUBLANG_LAO_LAO                                 equ     01H
SUBLANG_LATVIAN_LATVIA                          equ     01H
SUBLANG_LITHUANIAN                              equ     01H
SUBLANG_LOWER_SORBIAN_GERMANY                   equ     02H
SUBLANG_LUXEMBOURGISH_LUXEMBOURG                equ     01H
SUBLANG_MACEDONIAN_MACEDONIA                    equ     01H
SUBLANG_MALAY_MALAYSIA                          equ     01H
SUBLANG_MALAY_BRUNEI_DARUSSALAM                 equ     02H
SUBLANG_MALAYALAM_INDIA                         equ     01H
SUBLANG_MALTESE_MALTA                           equ     01H
SUBLANG_MAORI_NEW_ZEALAND                       equ     01H
SUBLANG_MAPUDUNGUN_CHILE                        equ     01H
SUBLANG_MARATHI_INDIA                           equ     01H
SUBLANG_MOHAWK_MOHAWK                           equ     01H
SUBLANG_MONGOLIAN_CYRILLIC_MONGOLIA             equ     01H
SUBLANG_MONGOLIAN_PRC                           equ     02H
SUBLANG_NEPALI_INDIA                            equ     02H
SUBLANG_NEPALI_NEPAL                            equ     01H
SUBLANG_NORWEGIAN_BOKMAL                        equ     01H
SUBLANG_NORWEGIAN_NYNORSK                       equ     02H
SUBLANG_OCCITAN_FRANCE                          equ     01H
SUBLANG_ODIA_INDIA                              equ     01H
SUBLANG_ORIYA_INDIA                             equ     01H
SUBLANG_PASHTO_AFGHANISTAN                      equ     01H
SUBLANG_PERSIAN_IRAN                            equ     01H
SUBLANG_POLISH_POLAND                           equ     01H
SUBLANG_PORTUGUESE                              equ     02H
SUBLANG_PORTUGUESE_BRAZILIAN                    equ     01H
SUBLANG_PULAR_SENEGAL                           equ     02H
SUBLANG_PUNJABI_INDIA                           equ     01H
SUBLANG_PUNJABI_PAKISTAN                        equ     02H
SUBLANG_QUECHUA_BOLIVIA                         equ     01H
SUBLANG_QUECHUA_ECUADOR                         equ     02H
SUBLANG_QUECHUA_PERU                            equ     03H
SUBLANG_ROMANIAN_ROMANIA                        equ     01H
SUBLANG_ROMANSH_SWITZERLAND                     equ     01H
SUBLANG_RUSSIAN_RUSSIA                          equ     01H
SUBLANG_SAKHA_RUSSIA                            equ     01H
SUBLANG_SAMI_NORTHERN_NORWAY                    equ     01H
SUBLANG_SAMI_NORTHERN_SWEDEN                    equ     02H
SUBLANG_SAMI_NORTHERN_FINLAND                   equ     03H
SUBLANG_SAMI_LULE_NORWAY                        equ     04H
SUBLANG_SAMI_LULE_SWEDEN                        equ     05H
SUBLANG_SAMI_SOUTHERN_NORWAY                    equ     06H
SUBLANG_SAMI_SOUTHERN_SWEDEN                    equ     07H
SUBLANG_SAMI_SKOLT_FINLAND                      equ     08H
SUBLANG_SAMI_INARI_FINLAND                      equ     09H
SUBLANG_SANSKRIT_INDIA                          equ     01H
SUBLANG_SCOTTISH_GAELIC                         equ     01H
SUBLANG_SERBIAN_BOSNIA_HERZEGOVINA_LATIN        equ     06H
SUBLANG_SERBIAN_BOSNIA_HERZEGOVINA_CYRILLIC     equ     07H
SUBLANG_SERBIAN_MONTENEGRO_LATIN                equ     0BH
SUBLANG_SERBIAN_MONTENEGRO_CYRILLIC             equ     0CH
SUBLANG_SERBIAN_SERBIA_LATIN                    equ     09H
SUBLANG_SERBIAN_SERBIA_CYRILLIC                 equ     0AH
SUBLANG_SERBIAN_CROATIA                         equ     01H
SUBLANG_SERBIAN_LATIN                           equ     02H
SUBLANG_SERBIAN_CYRILLIC                        equ     03H
SUBLANG_SINDHI_INDIA                            equ     01H
SUBLANG_SINDHI_PAKISTAN                         equ     02H
SUBLANG_SINDHI_AFGHANISTAN                      equ     02H
SUBLANG_SINHALESE_SRI_LANKA                     equ     01H
SUBLANG_SOTHO_NORTHERN_SOUTH_AFRICA             equ     01H
SUBLANG_SLOVAK_SLOVAKIA                         equ     01H
SUBLANG_SLOVENIAN_SLOVENIA                      equ     01H
SUBLANG_SPANISH                                 equ     01H
SUBLANG_SPANISH_MEXICAN                         equ     02H
SUBLANG_SPANISH_MODERN                          equ     03H
SUBLANG_SPANISH_GUATEMALA                       equ     04H
SUBLANG_SPANISH_COSTA_RICA                      equ     05H
SUBLANG_SPANISH_PANAMA                          equ     06H
SUBLANG_SPANISH_DOMINICAN_REPUBLIC              equ     07H
SUBLANG_SPANISH_VENEZUELA                       equ     08H
SUBLANG_SPANISH_COLOMBIA                        equ     09H
SUBLANG_SPANISH_PERU                            equ     0AH
SUBLANG_SPANISH_ARGENTINA                       equ     0BH
SUBLANG_SPANISH_ECUADOR                         equ     0CH
SUBLANG_SPANISH_CHILE                           equ     0DH
SUBLANG_SPANISH_URUGUAY                         equ     0EH
SUBLANG_SPANISH_PARAGUAY                        equ     0FH
SUBLANG_SPANISH_BOLIVIA                         equ     10H
SUBLANG_SPANISH_EL_SALVADOR                     equ     11H
SUBLANG_SPANISH_HONDURAS                        equ     12H
SUBLANG_SPANISH_NICARAGUA                       equ     13H
SUBLANG_SPANISH_PUERTO_RICO                     equ     14H
SUBLANG_SPANISH_US                              equ     15H
SUBLANG_SWAHILI_KENYA                           equ     01H
SUBLANG_SWEDISH                                 equ     01H
SUBLANG_SWEDISH_FINLAND                         equ     02H
SUBLANG_SYRIAC_SYRIA                            equ     01H
SUBLANG_TAJIK_TAJIKISTAN                        equ     01H
SUBLANG_TAMAZIGHT_ALGERIA_LATIN                 equ     02H
SUBLANG_TAMAZIGHT_MOROCCO_TIFINAGH              equ     04H
SUBLANG_TAMIL_INDIA                             equ     01H
SUBLANG_TAMIL_SRI_LANKA                         equ     02H
SUBLANG_TATAR_RUSSIA                            equ     01H
SUBLANG_TELUGU_INDIA                            equ     01H
SUBLANG_THAI_THAILAND                           equ     01H
SUBLANG_TIBETAN_PRC                             equ     01H
SUBLANG_TIGRIGNA_ERITREA                        equ     02H
SUBLANG_TIGRINYA_ERITREA                        equ     02H
SUBLANG_TIGRINYA_ETHIOPIA                       equ     01H
SUBLANG_TSWANA_BOTSWANA                         equ     02H
SUBLANG_TSWANA_SOUTH_AFRICA                     equ     01H
SUBLANG_TURKISH_TURKEY                          equ     01H
SUBLANG_TURKMEN_TURKMENISTAN                    equ     01H
SUBLANG_UIGHUR_PRC                              equ     01H
SUBLANG_UKRAINIAN_UKRAINE                       equ     01H
SUBLANG_UPPER_SORBIAN_GERMANY                   equ     01H
SUBLANG_URDU_PAKISTAN                           equ     01H
SUBLANG_URDU_INDIA                              equ     02H
SUBLANG_UZBEK_LATIN                             equ     01H
SUBLANG_UZBEK_CYRILLIC                          equ     02H
SUBLANG_VALENCIAN_VALENCIA                      equ     02H
SUBLANG_VIETNAMESE_VIETNAM                      equ     01H
SUBLANG_WELSH_UNITED_KINGDOM                    equ     01H
SUBLANG_WOLOF_SENEGAL                           equ     01H
SUBLANG_XHOSA_SOUTH_AFRICA                      equ     01H
SUBLANG_YAKUT_RUSSIA                            equ     01H
SUBLANG_YI_PRC                                  equ     01H
SUBLANG_YORUBA_NIGERIA                          equ     01H
SUBLANG_ZULU_SOUTH_AFRICA                       equ     01H

SORT_DEFAULT                                    equ     0H

SORT_JAPANESE_XJIS                              equ     0H
SORT_JAPANESE_UNICODE                           equ     1H
SORT_JAPANESE_RADICALSTROKE                     equ     4H

SORT_CHINESE_BIG5                               equ     0H
SORT_CHINESE_PRCP                               equ     0H
SORT_CHINESE_UNICODE                            equ     1H
SORT_CHINESE_PRC                                equ     2H
SORT_CHINESE_BOPOMOFO                           equ     3H
SORT_CHINESE_RADICALSTROKE                      equ     4H

SORT_KOREAN_KSC                                 equ     0H
SORT_KOREAN_UNICODE                             equ     1H

SORT_GERMAN_PHONE_BOOK                          equ     1H

SORT_HUNGARIAN_DEFAULT                          equ     0H
SORT_HUNGARIAN_TECHNICAL                        equ     1H

SORT_GEORGIAN_TRADITIONAL                       equ     0H
SORT_GEORGIAN_MODERN                            equ     1H

LOCALE_NAME_MAX_LENGTH                          equ     85

LOCALE_CUSTOM_DEFAULT                           equ     <(LANG_NEUTRAL or (SUBLANG_CUSTOM_DEFAULT shl 10)) or (SORT_DEFAULT shl 16)>
LOCALE_CUSTOM_UNSPECIFIED                       equ     <(LANG_NEUTRAL or (SUBLANG_CUSTOM_UNSPECIFIED shl 10)) or (SORT_DEFAULT shl 16)>
LOCALE_CUSTOM_UI_DEFAULT                        equ     <(LANG_NEUTRAL or (SUBLANG_UI_CUSTOM_DEFAULT shl 10)) or (SORT_DEFAULT shl 16)>
LOCALE_NEUTRAL                                  equ     <(LANG_NEUTRAL or (SUBLANG_NEUTRAL shl 10)) or (SORT_DEFAULT shl 16)>
LOCALE_INVARIANT                                equ     <(LANG_INVARIANT or (SUBLANG_NEUTRAL shl 10)) or (SORT_DEFAULT shl 16)>

LANG_SYSTEM_DEFAULT                             equ     <(SUBLANG_SYS_DEFAULT shl 10) or LANG_NEUTRAL>
LANG_USER_DEFAULT                               equ     <(SUBLANG_DEFAULT shl 10) or LANG_NEUTRAL>

LOCALE_TRANSIENT_KEYBOARD1                      equ     02000H
LOCALE_TRANSIENT_KEYBOARD2                      equ     02400H
LOCALE_TRANSIENT_KEYBOARD3                      equ     02800H
LOCALE_TRANSIENT_KEYBOARD4                      equ     02C00H

LOCALE_UNASSIGNED_LCID                          equ     LOCALE_CUSTOM_UNSPECIFIED

STATUS_WAIT_0                                   equ     000000000H
STATUS_ABANDONED_WAIT_0                         equ     000000080H
STATUS_USER_APC                                 equ     0000000C0H
STATUS_TIMEOUT                                  equ     000000102H
STATUS_PENDING                                  equ     000000103H
DBG_EXCEPTION_HANDLED                           equ     000010001H
DBG_CONTINUE                                    equ     000010002H
STATUS_SEGMENT_NOTIFICATION                     equ     040000005H
DBG_TERMINATE_THREAD                            equ     040010003H
DBG_TERMINATE_PROCESS                           equ     040010004H
DBG_CONTROL_C                                   equ     040010005H
#ifndef DBG_PRINTEXCEPTION_C
    DBG_PRINTEXCEPTION_C                        equ     040010006H
#endif
#ifndef DBG_RIPEXCEPTION
    DBG_RIPEXCEPTION                            equ     040010007H
#endif
DBG_CONTROL_BREAK                               equ     040010008H
DBG_COMMAND_EXCEPTION                           equ     040010009H
STATUS_GUARD_PAGE_VIOLATION                     equ     080000001H
STATUS_DATATYPE_MISALIGNMENT                    equ     080000002H
STATUS_BREAKPOINT                               equ     080000003H
STATUS_SINGLE_STEP                              equ     080000004H
#ifndef STATUS_LONGJUMP
    STATUS_LONGJUMP                             equ     080000026H
#endif
#ifndef STATUS_UNWIND_CONSOLIDATE
    STATUS_UNWIND_CONSOLIDATE                   equ     080000029H
#endif
DBG_EXCEPTION_NOT_HANDLED                       equ     080010001H
STATUS_ACCESS_VIOLATION                         equ     0C0000005H
STATUS_IN_PAGE_ERROR                            equ     0C0000006H
STATUS_INVALID_HANDLE                           equ     0C0000008H
#ifndef STATUS_INVALID_PARAMETER
    STATUS_INVALID_PARAMETER                    equ     0C000000DH
#endif
STATUS_NO_MEMORY                                equ     0C0000017H
STATUS_ILLEGAL_INSTRUCTION                      equ     0C000001DH
STATUS_NONCONTINUABLE_EXCEPTION                 equ     0C0000025H
STATUS_INVALID_DISPOSITION                      equ     0C0000026H
STATUS_ARRAY_BOUNDS_EXCEEDED                    equ     0C000008CH
STATUS_FLOAT_DENORMAL_OPERAND                   equ     0C000008DH
STATUS_FLOAT_DIVIDE_BY_ZERO                     equ     0C000008EH
STATUS_FLOAT_INEXACT_RESULT                     equ     0C000008FH
STATUS_FLOAT_INVALID_OPERATION                  equ     0C0000090H
STATUS_FLOAT_OVERFLOW                           equ     0C0000091H
STATUS_FLOAT_STACK_CHECK                        equ     0C0000092H
STATUS_FLOAT_UNDERFLOW                          equ     0C0000093H
STATUS_INTEGER_DIVIDE_BY_ZERO                   equ     0C0000094H
STATUS_INTEGER_OVERFLOW                         equ     0C0000095H
STATUS_PRIVILEGED_INSTRUCTION                   equ     0C0000096H
STATUS_STACK_OVERFLOW                           equ     0C00000FDH
#ifndef STATUS_DLL_NOT_FOUND
    STATUS_DLL_NOT_FOUND                        equ     0C0000135H
#endif
#ifndef STATUS_ORDINAL_NOT_FOUND
    STATUS_ORDINAL_NOT_FOUND                    equ     0C0000138H
#endif
#ifndef STATUS_ENTRYPOINT_NOT_FOUND
    STATUS_ENTRYPOINT_NOT_FOUND                 equ     0C0000139H
#endif
STATUS_CONTROL_C_EXIT                           equ     0C000013AH
#ifndef STATUS_DLL_INIT_FAILED
    STATUS_DLL_INIT_FAILED                      equ     0C0000142H
#endif
#ifndef STATUS_POSSIBLE_DEADLOCK
    STATUS_POSSIBLE_DEADLOCK                    equ     0C0000194H
#endif
STATUS_FLOAT_MULTIPLE_FAULTS                    equ     0C00002B4H
STATUS_FLOAT_MULTIPLE_TRAPS                     equ     0C00002B5H
STATUS_REG_NAT_CONSUMPTION                      equ     0C00002C9H
#ifndef STATUS_STACK_BUFFER_OVERRUN
    STATUS_STACK_BUFFER_OVERRUN                 equ     0C0000409H
#endif
STATUS_INVALID_CRUNTIME_PARAMETER               equ     0C0000417H
STATUS_ASSERTION_FAILURE                        equ     0C0000420H
STATUS_SXS_EARLY_DEACTIVATION                   equ     0C015000FH
STATUS_SXS_INVALID_DEACTIVATION                 equ     0C0150010H

MAXIMUM_WAIT_OBJECTS                            equ     64
MAXIMUM_SUSPEND_COUNT                           equ     MAXCHAR

EXCEPTION_NONCONTINUABLE                        equ     01H
EXCEPTION_UNWINDING                             equ     02H
EXCEPTION_EXIT_UNWIND                           equ     04H
EXCEPTION_STACK_INVALID                         equ     08H
EXCEPTION_NESTED_CALL                           equ     010H
EXCEPTION_TARGET_UNWIND                         equ     020H
EXCEPTION_COLLIDED_UNWIND                       equ     040H
EXCEPTION_UNWIND                                equ     <EXCEPTION_UNWINDING or EXCEPTION_EXIT_UNWIND or EXCEPTION_TARGET_UNWIND or EXCEPTION_COLLIDED_UNWIND>

#ifndef DELETE
    DELETE                                      equ     000010000H
    READ_CONTROL                                equ     000020000H
    WRITE_DAC                                   equ     000040000H
    WRITE_OWNER                                 equ     000080000H
    SYNCHRONIZE                                 equ     000100000H
#endif
#ifndef STANDARD_RIGHTS_READ
    STANDARD_RIGHTS_REQUIRED                    equ     0000F0000H
    STANDARD_RIGHTS_READ                        equ     READ_CONTROL
    STANDARD_RIGHTS_WRITE                       equ     READ_CONTROL
    STANDARD_RIGHTS_EXECUTE                     equ     READ_CONTROL
    STANDARD_RIGHTS_ALL                         equ     0001F0000H
#endif
SPECIFIC_RIGHTS_ALL                             equ     00000FFFFH

ACCESS_SYSTEM_SECURITY                          equ     001000000H

MAXIMUM_ALLOWED                                 equ     002000000H

GENERIC_READ                                    equ     080000000H
GENERIC_WRITE                                   equ     040000000H
GENERIC_EXECUTE                                 equ     020000000H
GENERIC_ALL                                     equ     010000000H

define SID_HASH_ENTRY                           dq

SID_REVISION                                    equ     1
SID_MAX_SUB_AUTHORITIES                         equ     15
SID_RECOMMENDED_SUB_AUTHORITIES                 equ     1

SECURITY_NULL_RID                               equ     000000000H
SECURITY_WORLD_RID                              equ     000000000H
SECURITY_LOCAL_RID                              equ     000000000H
SECURITY_LOCAL_LOGON_RID                        equ     000000001H
SECURITY_CREATOR_OWNER_RID                      equ     000000000H
SECURITY_CREATOR_GROUP_RID                      equ     000000001H
SECURITY_CREATOR_OWNER_SERVER_RID               equ     000000002H
SECURITY_CREATOR_GROUP_SERVER_RID               equ     000000003H
SECURITY_CREATOR_OWNER_RIGHTS_RID               equ     000000004H

SECURITY_DIALUP_RID                             equ     000000001H
SECURITY_NETWORK_RID                            equ     000000002H
SECURITY_BATCH_RID                              equ     000000003H
SECURITY_INTERACTIVE_RID                        equ     000000004H
SECURITY_LOGON_IDS_RID                          equ     000000005H
SECURITY_LOGON_IDS_RID_COUNT                    equ     3
SECURITY_SERVICE_RID                            equ     000000006H
SECURITY_ANONYMOUS_LOGON_RID                    equ     000000007H
SECURITY_PROXY_RID                              equ     000000008H
SECURITY_ENTERPRISE_CONTROLLERS_RID             equ     000000009H
SECURITY_SERVER_LOGON_RID                       equ     SECURITY_ENTERPRISE_CONTROLLERS_RID
SECURITY_PRINCIPAL_SELF_RID                     equ     00000000AH
SECURITY_AUTHENTICATED_USER_RID                 equ     00000000BH
SECURITY_RESTRICTED_CODE_RID                    equ     00000000CH
SECURITY_TERMINAL_SERVER_RID                    equ     00000000DH
SECURITY_REMOTE_LOGON_RID                       equ     00000000EH
SECURITY_THIS_ORGANIZATION_RID                  equ     00000000FH
SECURITY_IUSER_RID                              equ     000000011H
SECURITY_LOCAL_SYSTEM_RID                       equ     000000012H
SECURITY_LOCAL_SERVICE_RID                      equ     000000013H
SECURITY_NETWORK_SERVICE_RID                    equ     000000014H
SECURITY_NT_NON_UNIQUE                          equ     000000015H
SECURITY_NT_NON_UNIQUE_SUB_AUTH_COUNT           equ     3
SECURITY_ENTERPRISE_READONLY_CONTROLLERS_RID    equ     000000016H
SECURITY_BUILTIN_DOMAIN_RID                     equ     000000020H
SECURITY_WRITE_RESTRICTED_CODE_RID              equ     000000021H
SECURITY_PACKAGE_BASE_RID                       equ     000000040H
SECURITY_PACKAGE_RID_COUNT                      equ     2
SECURITY_PACKAGE_NTLM_RID                       equ     00000000AH
SECURITY_PACKAGE_SCHANNEL_RID                   equ     00000000EH
SECURITY_PACKAGE_DIGEST_RID                     equ     000000015H
SECURITY_CRED_TYPE_BASE_RID                     equ     000000041H
SECURITY_CRED_TYPE_RID_COUNT                    equ     2
SECURITY_CRED_TYPE_THIS_ORG_CERT_RID            equ     000000001H
SECURITY_MIN_BASE_RID                           equ     000000050H
SECURITY_SERVICE_ID_BASE_RID                    equ     000000050H
SECURITY_SERVICE_ID_RID_COUNT                   equ     6
SECURITY_RESERVED_ID_BASE_RID                   equ     000000051H
SECURITY_APPPOOL_ID_BASE_RID                    equ     000000052H
SECURITY_APPPOOL_ID_RID_COUNT                   equ     6
SECURITY_VIRTUALSERVER_ID_BASE_RID              equ     000000053H
SECURITY_VIRTUALSERVER_ID_RID_COUNT             equ     6
SECURITY_USERMODEDRIVERHOST_ID_BASE_RID         equ     000000054H
SECURITY_USERMODEDRIVERHOST_ID_RID_COUNT        equ     6
SECURITY_CLOUD_INFRASTRUCTURE_SERVICES_ID_BASE_RID  equ 000000055H
SECURITY_CLOUD_INFRASTRUCTURE_SERVICES_ID_RID_COUNT equ 6
SECURITY_WMIHOST_ID_BASE_RID                    equ     000000056H
SECURITY_WMIHOST_ID_RID_COUNT                   equ     6
SECURITY_TASK_ID_BASE_RID                       equ     000000057H
SECURITY_NFS_ID_BASE_RID                        equ     000000058H
SECURITY_COM_ID_BASE_RID                        equ     000000059H
SECURITY_WINDOW_MANAGER_BASE_RID                equ     00000005AH
SECURITY_RDV_GFX_BASE_RID                       equ     00000005BH
SECURITY_DASHOST_ID_BASE_RID                    equ     00000005CH
SECURITY_DASHOST_ID_RID_COUNT                   equ     6
SECURITY_VIRTUALACCOUNT_ID_RID_COUNT            equ     6
SECURITY_MAX_BASE_RID                           equ     00000006FH
SECURITY_MAX_ALWAYS_FILTERED                    equ     0000003E7H
SECURITY_MIN_NEVER_FILTERED                     equ     0000003E8H
SECURITY_OTHER_ORGANIZATION_RID                 equ     0000003E8H
SECURITY_WINDOWSMOBILE_ID_BASE_RID              equ     000000070H

DOMAIN_USER_RID_ADMIN                           equ     0000001F4H
DOMAIN_USER_RID_GUEST                           equ     0000001F5H
DOMAIN_USER_RID_KRBTGT                          equ     0000001F6H
DOMAIN_USER_RID_MAX                             equ     0000003E7H

DOMAIN_GROUP_RID_ADMINS                         equ     000000200H
DOMAIN_GROUP_RID_USERS                          equ     000000201H
DOMAIN_GROUP_RID_GUESTS                         equ     000000202H
DOMAIN_GROUP_RID_COMPUTERS                      equ     000000203H
DOMAIN_GROUP_RID_CONTROLLERS                    equ     000000204H
DOMAIN_GROUP_RID_CERT_ADMINS                    equ     000000205H
DOMAIN_GROUP_RID_SCHEMA_ADMINS                  equ     000000206H
DOMAIN_GROUP_RID_ENTERPRISE_ADMINS              equ     000000207H
DOMAIN_GROUP_RID_POLICY_ADMINS                  equ     000000208H
DOMAIN_GROUP_RID_READONLY_CONTROLLERS           equ     000000209H
DOMAIN_GROUP_RID_CLONEABLE_CONTROLLERS          equ     00000020AH
DOMAIN_GROUP_RID_CDC_RESERVED                   equ     00000020CH
DOMAIN_GROUP_RID_PROTECTED_USERS                equ     00000020DH

DOMAIN_ALIAS_RID_ADMINS                         equ     000000220H
DOMAIN_ALIAS_RID_USERS                          equ     000000221H
DOMAIN_ALIAS_RID_GUESTS                         equ     000000222H
DOMAIN_ALIAS_RID_POWER_USERS                    equ     000000223H

DOMAIN_ALIAS_RID_ACCOUNT_OPS                    equ     000000224H
DOMAIN_ALIAS_RID_SYSTEM_OPS                     equ     000000225H
DOMAIN_ALIAS_RID_PRINT_OPS                      equ     000000226H
DOMAIN_ALIAS_RID_BACKUP_OPS                     equ     000000227H

DOMAIN_ALIAS_RID_REPLICATOR                     equ     000000228H
DOMAIN_ALIAS_RID_RAS_SERVERS                    equ     000000229H
DOMAIN_ALIAS_RID_PREW2KCOMPACCESS               equ     00000022AH
DOMAIN_ALIAS_RID_REMOTE_DESKTOP_USERS           equ     00000022BH
DOMAIN_ALIAS_RID_NETWORK_CONFIGURATION_OPS      equ     00000022CH
DOMAIN_ALIAS_RID_INCOMING_FOREST_TRUST_BUILDERS equ     00000022DH
DOMAIN_ALIAS_RID_MONITORING_USERS               equ     00000022EH
DOMAIN_ALIAS_RID_LOGGING_USERS                  equ     00000022FH
DOMAIN_ALIAS_RID_AUTHORIZATIONACCESS            equ     000000230H
DOMAIN_ALIAS_RID_TS_LICENSE_SERVERS             equ     000000231H
DOMAIN_ALIAS_RID_DCOM_USERS                     equ     000000232H
DOMAIN_ALIAS_RID_IUSERS                         equ     000000238H
DOMAIN_ALIAS_RID_CRYPTO_OPERATORS               equ     000000239H
DOMAIN_ALIAS_RID_CACHEABLE_PRINCIPALS_GROUP     equ     00000023BH
DOMAIN_ALIAS_RID_NON_CACHEABLE_PRINCIPALS_GROUP equ     00000023CH
DOMAIN_ALIAS_RID_EVENT_LOG_READERS_GROUP        equ     00000023DH
DOMAIN_ALIAS_RID_CERTSVC_DCOM_ACCESS_GROUP      equ     00000023EH
DOMAIN_ALIAS_RID_RDS_REMOTE_ACCESS_SERVERS      equ     00000023FH
DOMAIN_ALIAS_RID_RDS_ENDPOINT_SERVERS           equ     000000240H
DOMAIN_ALIAS_RID_RDS_MANAGEMENT_SERVERS         equ     000000241H
DOMAIN_ALIAS_RID_HYPER_V_ADMINS                 equ     000000242H
DOMAIN_ALIAS_RID_ACCESS_CONTROL_ASSISTANCE_OPS  equ     000000243H
DOMAIN_ALIAS_RID_REMOTE_MANAGEMENT_USERS        equ     000000244H

SECURITY_MANDATORY_UNTRUSTED_RID                equ     000000000H
SECURITY_MANDATORY_LOW_RID                      equ     000001000H
SECURITY_MANDATORY_MEDIUM_RID                   equ     000002000H
SECURITY_MANDATORY_MEDIUM_PLUS_RID              equ     (SECURITY_MANDATORY_MEDIUM_RID+0100H)
SECURITY_MANDATORY_HIGH_RID                     equ     000003000H
SECURITY_MANDATORY_SYSTEM_RID                   equ     000004000H
SECURITY_MANDATORY_PROTECTED_PROCESS_RID        equ     000005000H

SECURITY_MANDATORY_MAXIMUM_USER_RID             equ     SECURITY_MANDATORY_SYSTEM_RID

#ifndef WinNullSid
    WinNullSid                                  equ     0
    WinWorldSid                                 equ     1
    WinLocalSid                                 equ     2
    WinCreatorOwnerSid                          equ     3
    WinCreatorGroupSid                          equ     4
    WinCreatorOwnerServerSid                    equ     5
    WinCreatorGroupServerSid                    equ     6
    WinNtAuthoritySid                           equ     7
    WinDialupSid                                equ     8
    WinNetworkSid                               equ     9
    WinBatchSid                                 equ     10
    WinInteractiveSid                           equ     11
    WinServiceSid                               equ     12
    WinAnonymousSid                             equ     13
    WinProxySid                                 equ     14
    WinEnterpriseControllersSid                 equ     15
    WinSelfSid                                  equ     16
    WinAuthenticatedUserSid                     equ     17
    WinRestrictedCodeSid                        equ     18
    WinTerminalServerSid                        equ     19
    WinRemoteLogonIdSid                         equ     20
    WinLogonIdsSid                              equ     21
    WinLocalSystemSid                           equ     22
    WinLocalServiceSid                          equ     23
    WinNetworkServiceSid                        equ     24
    WinBuiltinDomainSid                         equ     25
    WinBuiltinAdministratorsSid                 equ     26
    WinBuiltinUsersSid                          equ     27
    WinBuiltinGuestsSid                         equ     28
    WinBuiltinPowerUsersSid                     equ     29
    WinBuiltinAccountOperatorsSid               equ     30
    WinBuiltinSystemOperatorsSid                equ     31
    WinBuiltinPrintOperatorsSid                 equ     32
    WinBuiltinBackupOperatorsSid                equ     33
    WinBuiltinReplicatorSid                     equ     34
    WinBuiltinPreWindows2000CompatibleAccessSid equ     35
    WinBuiltinRemoteDesktopUsersSid             equ     36
    WinBuiltinNetworkConfigurationOperatorsSid  equ     37
    WinAccountAdministratorSid                  equ     38
    WinAccountGuestSid                          equ     39
    WinAccountKrbtgtSid                         equ     40
    WinAccountDomainAdminsSid                   equ     41
    WinAccountDomainUsersSid                    equ     42
    WinAccountDomainGuestsSid                   equ     43
    WinAccountComputersSid                      equ     44
    WinAccountControllersSid                    equ     45
    WinAccountCertAdminsSid                     equ     46
    WinAccountSchemaAdminsSid                   equ     47
    WinAccountEnterpriseAdminsSid               equ     48
    WinAccountPolicyAdminsSid                   equ     49
    WinAccountRasAndIasServersSid               equ     50
    WinNTLMAuthenticationSid                    equ     51
    WinDigestAuthenticationSid                  equ     52
    WinSChannelAuthenticationSid                equ     53
    WinThisOrganizationSid                      equ     54
    WinOtherOrganizationSid                     equ     55
    WinBuiltinIncomingForestTrustBuildersSid    equ     56
    WinBuiltinPerfMonitoringUsersSid            equ     57
    WinBuiltinPerfLoggingUsersSid               equ     58
    WinBuiltinAuthorizationAccessSid            equ     59
    WinBuiltinTerminalServerLicenseServersSid   equ     60
    WinBuiltinDCOMUsersSid                      equ     61
    WinBuiltinIUsersSid                         equ     62
    WinIUserSid                                 equ     63
    WinBuiltinCryptoOperatorsSid                equ     64
    WinUntrustedLabelSid                        equ     65
    WinLowLabelSid                              equ     66
    WinMediumLabelSid                           equ     67
    WinHighLabelSid                             equ     68
    WinSystemLabelSid                           equ     69
    WinWriteRestrictedCodeSid                   equ     70
    WinCreatorOwnerRightsSid                    equ     71
    WinCacheablePrincipalsGroupSid              equ     72
    WinNonCacheablePrincipalsGroupSid           equ     73
    WinEnterpriseReadonlyControllersSid         equ     74
    WinAccountReadonlyControllersSid            equ     75
    WinBuiltinEventLogReadersGroup              equ     76
    WinNewEnterpriseReadonlyControllersSid      equ     77
    WinBuiltinCertSvcDComAccessGroup            equ     78
#endif
WinMediumPlusLabelSid                           equ     79
WinLocalLogonSid                                equ     80
WinConsoleLogonSid                              equ     81
WinThisOrganizationCertificateSid               equ     82

SE_GROUP_MANDATORY                              equ     000000001H
SE_GROUP_ENABLED_BY_DEFAULT                     equ     000000002H
SE_GROUP_ENABLED                                equ     000000004H
SE_GROUP_OWNER                                  equ     000000008H
SE_GROUP_USE_FOR_DENY_ONLY                      equ     000000010H
SE_GROUP_INTEGRITY                              equ     000000020H
SE_GROUP_INTEGRITY_ENABLED                      equ     000000040H
SE_GROUP_LOGON_ID                               equ     0C0000000H
SE_GROUP_RESOURCE                               equ     020000000H

SE_GROUP_VALID_ATTRIBUTES                       equ     <SE_GROUP_MANDATORY or SE_GROUP_ENABLED_BY_DEFAULT or SE_GROUP_ENABLED or SE_GROUP_OWNER or SE_GROUP_USE_FOR_DENY_ONLY or SE_GROUP_LOGON_ID or SE_GROUP_RESOURCE or SE_GROUP_INTEGRITY>

ACL_REVISION                                    equ     2
ACL_REVISION1                                   equ     1
ACL_REVISION2                                   equ     2
ACL_REVISION3                                   equ     3
ACL_REVISION4                                   equ     4
ACL_REVISION_DS                                 equ     4

MIN_ACL_REVISION                                equ     ACL_REVISION2
MAX_ACL_REVISION                                equ     ACL_REVISION4

ACCESS_MIN_MS_ACE_TYPE                          equ     00H
ACCESS_ALLOWED_ACE_TYPE                         equ     00H
ACCESS_DENIED_ACE_TYPE                          equ     01H
SYSTEM_AUDIT_ACE_TYPE                           equ     02H
SYSTEM_ALARM_ACE_TYPE                           equ     03H
ACCESS_MAX_MS_V2_ACE_TYPE                       equ     03H

ACCESS_ALLOWED_COMPOUND_ACE_TYPE                equ     04H
ACCESS_MAX_MS_V3_ACE_TYPE                       equ     04H

ACCESS_MIN_MS_OBJECT_ACE_TYPE                   equ     05H
ACCESS_ALLOWED_OBJECT_ACE_TYPE                  equ     05H
ACCESS_DENIED_OBJECT_ACE_TYPE                   equ     06H
SYSTEM_AUDIT_OBJECT_ACE_TYPE                    equ     07H
SYSTEM_ALARM_OBJECT_ACE_TYPE                    equ     08H
ACCESS_MAX_MS_OBJECT_ACE_TYPE                   equ     08H

ACCESS_MAX_MS_V4_ACE_TYPE                       equ     08H
ACCESS_MAX_MS_ACE_TYPE                          equ     08H
ACCESS_ALLOWED_CALLBACK_ACE_TYPE                equ     09H
ACCESS_DENIED_CALLBACK_ACE_TYPE                 equ     0AH
ACCESS_ALLOWED_CALLBACK_OBJECT_ACE_TYPE         equ     0BH
ACCESS_DENIED_CALLBACK_OBJECT_ACE_TYPE          equ     0CH
SYSTEM_AUDIT_CALLBACK_ACE_TYPE                  equ     0DH
SYSTEM_ALARM_CALLBACK_ACE_TYPE                  equ     0EH
SYSTEM_AUDIT_CALLBACK_OBJECT_ACE_TYPE           equ     0FH
SYSTEM_ALARM_CALLBACK_OBJECT_ACE_TYPE           equ     010H

SYSTEM_MANDATORY_LABEL_ACE_TYPE                 equ     011H
SYSTEM_RESOURCE_ATTRIBUTE_ACE_TYPE              equ     012H
SYSTEM_SCOPED_POLICY_ID_ACE_TYPE                equ     013H
SYSTEM_PROCESS_TRUST_LABEL_ACE_TYPE             equ     014H
ACCESS_MAX_MS_V5_ACE_TYPE                       equ     014H

SYSTEM_MANDATORY_LABEL_NO_WRITE_UP              equ     01H
SYSTEM_MANDATORY_LABEL_NO_READ_UP               equ     02H
SYSTEM_MANDATORY_LABEL_NO_EXECUTE_UP            equ     04H

SYSTEM_MANDATORY_LABEL_VALID_MASK               equ     <SYSTEM_MANDATORY_LABEL_NO_WRITE_UP or SYSTEM_MANDATORY_LABEL_NO_READ_UP or SYSTEM_MANDATORY_LABEL_NO_EXECUTE_UP>

OBJECT_INHERIT_ACE                              equ     01H
CONTAINER_INHERIT_ACE                           equ     02H
NO_PROPAGATE_INHERIT_ACE                        equ     04H
INHERIT_ONLY_ACE                                equ     08H
INHERITED_ACE                                   equ     010H
VALID_INHERIT_FLAGS                             equ     01FH

SUCCESSFUL_ACCESS_ACE_FLAG                      equ     040H
FAILED_ACCESS_ACE_FLAG                          equ     080H

ACE_OBJECT_TYPE_PRESENT                         equ     01H
ACE_INHERITED_OBJECT_TYPE_PRESENT               equ     02H

SECURITY_DESCRIPTOR_REVISION                    equ     1
SECURITY_DESCRIPTOR_REVISION1                   equ     1

SECURITY_DESCRIPTOR_MIN_LENGTH                  equ     size SECURITY_DESCRIPTOR

SE_OWNER_DEFAULTED                              equ     00001H
SE_GROUP_DEFAULTED                              equ     00002H
SE_DACL_PRESENT                                 equ     00004H
SE_DACL_DEFAULTED                               equ     00008H
SE_SACL_PRESENT                                 equ     00010H
SE_SACL_DEFAULTED                               equ     00020H
SE_DACL_AUTO_INHERIT_REQ                        equ     00100H
SE_SACL_AUTO_INHERIT_REQ                        equ     00200H
SE_DACL_AUTO_INHERITED                          equ     00400H
SE_SACL_AUTO_INHERITED                          equ     00800H
SE_DACL_PROTECTED                               equ     01000H
SE_SACL_PROTECTED                               equ     02000H
SE_RM_CONTROL_VALID                             equ     04000H
SE_SELF_RELATIVE                                equ     08000H

ACCESS_OBJECT_GUID                              equ     0
ACCESS_PROPERTY_SET_GUID                        equ     1
ACCESS_PROPERTY_GUID                            equ     2
ACCESS_MAX_LEVEL                                equ     4

AUDIT_ALLOW_NO_PRIVILEGE                        equ     01H

SE_PRIVILEGE_ENABLED_BY_DEFAULT                 equ     000000001H
SE_PRIVILEGE_ENABLED                            equ     000000002H
SE_PRIVILEGE_REMOVED                            equ     000000004H
SE_PRIVILEGE_USED_FOR_ACCESS                    equ     080000000H

SE_PRIVILEGE_VALID_ATTRIBUTES                   equ     <SE_PRIVILEGE_ENABLED_BY_DEFAULT or SE_PRIVILEGE_ENABLED or SE_PRIVILEGE_REMOVED or SE_PRIVILEGE_USED_FOR_ACCESS>

PRIVILEGE_SET_ALL_NECESSARY                     equ     1

TOKEN_ASSIGN_PRIMARY                            equ     00001H
TOKEN_DUPLICATE                                 equ     00002H
TOKEN_IMPERSONATE                               equ     00004H
TOKEN_QUERY                                     equ     00008H
TOKEN_QUERY_SOURCE                              equ     00010H
TOKEN_ADJUST_PRIVILEGES                         equ     00020H
TOKEN_ADJUST_GROUPS                             equ     00040H
TOKEN_ADJUST_DEFAULT                            equ     00080H
TOKEN_ADJUST_SESSIONID                          equ     00100H

TOKEN_ALL_ACCESS_P                              equ     <STANDARD_RIGHTS_REQUIRED or TOKEN_ASSIGN_PRIMARY or TOKEN_DUPLICATE or TOKEN_IMPERSONATE or TOKEN_QUERY or TOKEN_ADJUST_PRIVILEGES or TOKEN_ADJUST_GROUPS or TOKEN_ADJUST_DEFAULT>

#ifdef APP_WIN64
    TOKEN_ALL_ACCESS                            equ     TOKEN_ALL_ACCESS_P
#else
    TOKEN_ALL_ACCESS                            equ     <TOKEN_ALL_ACCESS_P or TOKEN_ADJUST_SESSIONID>
#endif

TOKEN_READ                                      equ     <STANDARD_RIGHTS_READ or TOKEN_QUERY>
TOKEN_WRITE                                     equ     <STANDARD_RIGHTS_WRITE or TOKEN_ADJUST_PRIVILEGES or TOKEN_ADJUST_GROUPS or TOKEN_ADJUST_DEFAULT>
TOKEN_EXECUTE                                   equ     STANDARD_RIGHTS_EXECUTE
TOKEN_TRUST_CONSTRAINT_MASK                     equ     <STANDARD_RIGHTS_READ or TOKEN_QUERY or TOKEN_QUERY_SOURCE>

TOKEN_MANDATORY_POLICY_OFF                      equ     00H
TOKEN_MANDATORY_POLICY_NO_WRITE_UP              equ     01H
TOKEN_MANDATORY_POLICY_NEW_PROCESS_MIN          equ     02H
TOKEN_MANDATORY_POLICY_VALID_MASK               equ     <TOKEN_MANDATORY_POLICY_NO_WRITE_UP or TOKEN_MANDATORY_POLICY_NEW_PROCESS_MIN>

SECURITY_DYNAMIC_TRACKING                       equ     TRUE
SECURITY_STATIC_TRACKING                        equ     FALSE

DISABLE_MAX_PRIVILEGE                           equ     01H
SANDBOX_INERT                                   equ     02H
LUA_TOKEN                                       equ     04H
WRITE_RESTRICTED                                equ     08H

OWNER_SECURITY_INFORMATION                      equ     000000001H
GROUP_SECURITY_INFORMATION                      equ     000000002H
DACL_SECURITY_INFORMATION                       equ     000000004H
SACL_SECURITY_INFORMATION                       equ     000000008H
LABEL_SECURITY_INFORMATION                      equ     000000010H
ATTRIBUTE_SECURITY_INFORMATION                  equ     000000020H
SCOPE_SECURITY_INFORMATION                      equ     000000040H
PROCESS_TRUST_LABEL_SECURITY_INFORMATION        equ     000000080H
BACKUP_SECURITY_INFORMATION                     equ     000010000H

PROTECTED_DACL_SECURITY_INFORMATION             equ     080000000H
PROTECTED_SACL_SECURITY_INFORMATION             equ     040000000H
UNPROTECTED_DACL_SECURITY_INFORMATION           equ     020000000H
UNPROTECTED_SACL_SECURITY_INFORMATION           equ     010000000H

PROCESS_TERMINATE                               equ     00001H
PROCESS_CREATE_THREAD                           equ     00002H
PROCESS_SET_SESSIONID                           equ     00004H
PROCESS_VM_OPERATION                            equ     00008H
PROCESS_VM_READ                                 equ     00010H
PROCESS_VM_WRITE                                equ     00020H
PROCESS_DUP_HANDLE                              equ     00040H
PROCESS_CREATE_PROCESS                          equ     00080H
PROCESS_SET_QUOTA                               equ     00100H
PROCESS_SET_INFORMATION                         equ     00200H
PROCESS_QUERY_INFORMATION                       equ     00400H
PROCESS_SUSPEND_RESUME                          equ     00800H
PROCESS_QUERY_LIMITED_INFORMATION               equ     01000H
PROCESS_SET_LIMITED_INFORMATION                 equ     02000H

#if NTDDI_VERSION < NTDDI_VISTA
    PROCESS_ALL_ACCESS                          equ     <STANDARD_RIGHTS_REQUIRED or SYNCHRONIZE or 0FFFH>
#else
    PROCESS_ALL_ACCESS                          equ     <STANDARD_RIGHTS_REQUIRED or SYNCHRONIZE or 0FFFFH>
#endif

THREAD_TERMINATE                                equ     00001H
THREAD_SUSPEND_RESUME                           equ     00002H
THREAD_GET_CONTEXT                              equ     00008H
THREAD_SET_CONTEXT                              equ     00010H
THREAD_QUERY_INFORMATION                        equ     00040H
THREAD_SET_INFORMATION                          equ     00020H
THREAD_SET_THREAD_TOKEN                         equ     00080H
THREAD_IMPERSONATE                              equ     00100H
THREAD_DIRECT_IMPERSONATION                     equ     00200H
THREAD_SET_LIMITED_INFORMATION                  equ     00400H
THREAD_QUERY_LIMITED_INFORMATION                equ     00800H
THREAD_RESUME                                   equ     01000H

#if NTDDI_VERSION < NTDDI_VISTA
    THREAD_ALL_ACCESS                           equ     <STANDARD_RIGHTS_REQUIRED or SYNCHRONIZE or 03FFH>
#else
    THREAD_ALL_ACCESS                           equ     <STANDARD_RIGHTS_REQUIRED or SYNCHRONIZE or 0FFFFH>
#endif

JOB_OBJECT_ASSIGN_PROCESS                       equ     00001H
JOB_OBJECT_SET_ATTRIBUTES                       equ     00002H
JOB_OBJECT_QUERY                                equ     00004H
JOB_OBJECT_TERMINATE                            equ     00008H
JOB_OBJECT_SET_SECURITY_ATTRIBUTES              equ     00010H
JOB_OBJECT_ALL_ACCESS                           equ     <STANDARD_RIGHTS_REQUIRED or SYNCHRONIZE or 01FH>

FLS_MAXIMUM_AVAILABLE                           equ     128
TLS_MINIMUM_AVAILABLE                           equ     64

#ifndef THREAD_BASE_PRIORITY_LOWRT
    THREAD_BASE_PRIORITY_LOWRT                  equ     15
    THREAD_BASE_PRIORITY_MAX                    equ     2
    THREAD_BASE_PRIORITY_MIN                    equ     (-2)
    THREAD_BASE_PRIORITY_IDLE                   equ     (-15)
#endif

JOB_OBJECT_TERMINATE_AT_END_OF_JOB              equ     0
JOB_OBJECT_POST_AT_END_OF_JOB                   equ     1

JOB_OBJECT_MSG_END_OF_JOB_TIME                  equ     1
JOB_OBJECT_MSG_END_OF_PROCESS_TIME              equ     2
JOB_OBJECT_MSG_ACTIVE_PROCESS_LIMIT             equ     3
JOB_OBJECT_MSG_ACTIVE_PROCESS_ZERO              equ     4
JOB_OBJECT_MSG_NEW_PROCESS                      equ     6
JOB_OBJECT_MSG_EXIT_PROCESS                     equ     7
JOB_OBJECT_MSG_ABNORMAL_EXIT_PROCESS            equ     8
JOB_OBJECT_MSG_PROCESS_MEMORY_LIMIT             equ     9
JOB_OBJECT_MSG_JOB_MEMORY_LIMIT                 equ     10
JOB_OBJECT_MSG_NOTIFICATION_LIMIT               equ     11
JOB_OBJECT_MSG_JOB_CYCLE_TIME_LIMIT             equ     12

JOB_OBJECT_MSG_MINIMUM                          equ     1
JOB_OBJECT_MSG_MAXIMUM                          equ     12
JOB_OBJECT_VALID_COMPLETION_FILTER              equ     <(((1 shl (JOB_OBJECT_MSG_MAXIMUM+1)))-1)-((1 shl JOB_OBJECT_MSG_MINIMUM)-1)>

OB_OBJECT_LIMIT_WORKINGSET                     equ     000000001H
JOB_OBJECT_LIMIT_PROCESS_TIME                   equ     000000002H
JOB_OBJECT_LIMIT_JOB_TIME                       equ     000000004H
JOB_OBJECT_LIMIT_ACTIVE_PROCESS                 equ     000000008H
JOB_OBJECT_LIMIT_AFFINITY                       equ     000000010H
JOB_OBJECT_LIMIT_PRIORITY_CLASS                 equ     000000020H
JOB_OBJECT_LIMIT_PRESERVE_JOB_TIME              equ     000000040H
JOB_OBJECT_LIMIT_SCHEDULING_CLASS               equ     000000080H

JOB_OBJECT_LIMIT_PROCESS_MEMORY                 equ     000000100H
JOB_OBJECT_LIMIT_JOB_MEMORY                     equ     000000200H
JOB_OBJECT_LIMIT_DIE_ON_UNHANDLED_EXCEPTION     equ     000000400H
JOB_OBJECT_LIMIT_BREAKAWAY_OK                   equ     000000800H
JOB_OBJECT_LIMIT_SILENT_BREAKAWAY_OK            equ     000001000H
JOB_OBJECT_LIMIT_KILL_ON_JOB_CLOSE              equ     000002000H
JOB_OBJECT_LIMIT_SUBSET_AFFINITY                equ     000004000H
JOB_OBJECT_LIMIT_RESERVED3                      equ     000008000H
JOB_OBJECT_LIMIT_RESERVED4                      equ     000010000H
JOB_OBJECT_LIMIT_RESERVED5                      equ     000020000H
JOB_OBJECT_LIMIT_RESERVED6                      equ     000040000H

JOB_OBJECT_LIMIT_JOB_READ_BYTES                 equ     000010000H
JOB_OBJECT_LIMIT_JOB_WRITE_BYTES                equ     000020000H
JOB_OBJECT_LIMIT_RATE_CONTROL                   equ     000040000H

JOB_OBJECT_LIMIT_VALID_FLAGS                    equ     00007FFFFH

JOB_OBJECT_BASIC_LIMIT_VALID_FLAGS              equ     0000000FFH
JOB_OBJECT_EXTENDED_LIMIT_VALID_FLAGS           equ     000007FFFH
JOB_OBJECT_NOTIFICATION_LIMIT_VALID_FLAGS       equ     000070204H
JOB_OBJECT_RESERVED_LIMIT_VALID_FLAGS           equ     00007FFFFH

JOB_OBJECT_UILIMIT_NONE                         equ     000000000H
JOB_OBJECT_UILIMIT_HANDLES                      equ     000000001H
JOB_OBJECT_UILIMIT_READCLIPBOARD                equ     000000002H
JOB_OBJECT_UILIMIT_WRITECLIPBOARD               equ     000000004H
JOB_OBJECT_UILIMIT_SYSTEMPARAMETERS             equ     000000008H
JOB_OBJECT_UILIMIT_DISPLAYSETTINGS              equ     000000010H
JOB_OBJECT_UILIMIT_GLOBALATOMS                  equ     000000020H
JOB_OBJECT_UILIMIT_DESKTOP                      equ     000000040H
JOB_OBJECT_UILIMIT_EXITWINDOWS                  equ     000000080H
JOB_OBJECT_UILIMIT_ALL                          equ     0000000FFH

JOB_OBJECT_UI_VALID_FLAGS                       equ     0000000FFH

JOB_OBJECT_SECURITY_NO_ADMIN                    equ     000000001H
JOB_OBJECT_SECURITY_RESTRICTED_TOKEN            equ     000000002H
JOB_OBJECT_SECURITY_ONLY_TOKEN                  equ     000000004H
JOB_OBJECT_SECURITY_FILTER_TOKENS               equ     000000008H
JOB_OBJECT_SECURITY_VALID_FLAGS                 equ     00000000FH

EVENT_MODIFY_STATE                              equ     00002H
EVENT_ALL_ACCESS                                equ     <STANDARD_RIGHTS_REQUIRED or SYNCHRONIZE or 03H>
#ifndef MUTANT_QUERY_STATE
    MUTANT_QUERY_STATE                          equ     00001H
    MUTANT_ALL_ACCESS                           equ     <STANDARD_RIGHTS_REQUIRED or SYNCHRONIZE or MUTANT_QUERY_STATE>
#endif
SEMAPHORE_MODIFY_STATE                          equ     00002H
SEMAPHORE_ALL_ACCESS                            equ     <STANDARD_RIGHTS_REQUIRED or SYNCHRONIZE or 03H>

TIMER_QUERY_STATE                               equ     00001H
TIMER_MODIFY_STATE                              equ     00002H
TIMER_ALL_ACCESS                                equ     <STANDARD_RIGHTS_REQUIRED or SYNCHRONIZE or TIMER_QUERY_STATE or TIMER_MODIFY_STATE>

TIME_ZONE_ID_UNKNOWN                            equ     0
TIME_ZONE_ID_STANDARD                           equ     1
TIME_ZONE_ID_DAYLIGHT                           equ     2

PROCESSOR_INTEL_386                             equ     386
PROCESSOR_INTEL_486                             equ     486
PROCESSOR_INTEL_PENTIUM                         equ     586
PROCESSOR_INTEL_IA64                            equ     2200
PROCESSOR_AMD_X8664                             equ     8664
PROCESSOR_MIPS_R4000                            equ     4000
PROCESSOR_ALPHA_21064                           equ     21064
PROCESSOR_PPC_601                               equ     601
PROCESSOR_PPC_603                               equ     603
PROCESSOR_PPC_604                               equ     604
PROCESSOR_PPC_620                               equ     620
PROCESSOR_HITACHI_SH3                           equ     10003
PROCESSOR_HITACHI_SH3E                          equ     10004
PROCESSOR_HITACHI_SH4                           equ     10005
PROCESSOR_MOTOROLA_821                          equ     821
PROCESSOR_SHx_SH3                               equ     103
PROCESSOR_SHx_SH4                               equ     104
PROCESSOR_STRONGARM                             equ     2577
PROCESSOR_ARM720                                equ     1824
PROCESSOR_ARM820                                equ     2080
PROCESSOR_ARM920                                equ     2336
PROCESSOR_ARM_7TDMI                             equ     70001
PROCESSOR_OPTIL                                 equ     0494FH

PROCESSOR_ARCHITECTURE_INTEL                    equ     0
PROCESSOR_ARCHITECTURE_MIPS                     equ     1
PROCESSOR_ARCHITECTURE_ALPHA                    equ     2
PROCESSOR_ARCHITECTURE_PPC                      equ     3
PROCESSOR_ARCHITECTURE_SHX                      equ     4
PROCESSOR_ARCHITECTURE_ARM                      equ     5
PROCESSOR_ARCHITECTURE_IA64                     equ     6
PROCESSOR_ARCHITECTURE_ALPHA64                  equ     7
PROCESSOR_ARCHITECTURE_MSIL                     equ     8
PROCESSOR_ARCHITECTURE_AMD64                    equ     9
PROCESSOR_ARCHITECTURE_IA32_ON_WIN64            equ     10

PROCESSOR_ARCHITECTURE_NEUTRAL                  equ     11
PROCESSOR_ARCHITECTURE_UNKNOWN                  equ     0FFFFH

PF_FLOATING_POINT_PRECISION_ERRATA              equ     0
PF_FLOATING_POINT_EMULATED                      equ     1
PF_COMPARE_EXCHANGE_DOUBLE                      equ     2
PF_MMX_INSTRUCTIONS_AVAILABLE                   equ     3
PF_PPC_MOVEMEM_64BIT_OK                         equ     4
PF_ALPHA_BYTE_INSTRUCTIONS                      equ     5
PF_XMMI_INSTRUCTIONS_AVAILABLE                  equ     6
PF_3DNOW_INSTRUCTIONS_AVAILABLE                 equ     7
PF_RDTSC_INSTRUCTION_AVAILABLE                  equ     8
PF_PAE_ENABLED                                  equ     9
PF_XMMI64_INSTRUCTIONS_AVAILABLE                equ     10
PF_SSE_DAZ_MODE_AVAILABLE                       equ     11
PF_NX_ENABLED                                   equ     12
PF_SSE3_INSTRUCTIONS_AVAILABLE                  equ     13
PF_COMPARE_EXCHANGE128                          equ     14
PF_COMPARE64_EXCHANGE128                        equ     15
PF_CHANNELS_ENABLED                             equ     16
PF_XSAVE_ENABLED                                equ     17
PF_ARM_VFP_32_REGISTERS_AVAILABLE               equ     18
PF_ARM_NEON_INSTRUCTIONS_AVAILABLE              equ     19
PF_SECOND_LEVEL_ADDRESS_TRANSLATION             equ     20
PF_VIRT_FIRMWARE_ENABLED                        equ     21
PF_RDWRFSGSBASE_AVAILABLE                       equ     22
PF_FASTFAIL_AVAILABLE                           equ     23
PF_ARM_DIVIDE_INSTRUCTION_AVAILABLE             equ     24
PF_ARM_64BIT_LOADSTORE_ATOMIC                   equ     25
PF_ARM_EXTERNAL_CACHE_AVAILABLE                 equ     26
PF_ARM_FMAC_INSTRUCTIONS_AVAILABLE              equ     27
PF_RDRAND_INSTRUCTION_AVAILABLE                 equ     28

SECTION_QUERY                                   equ     00001H
SECTION_MAP_WRITE                               equ     00002H
SECTION_MAP_READ                                equ     00004H
SECTION_MAP_EXECUTE                             equ     00008H
SECTION_EXTEND_SIZE                             equ     00010H
SECTION_MAP_EXECUTE_EXPLICIT                    equ     00020H
SECTION_ALL_ACCESS                              equ     <STANDARD_RIGHTS_REQUIRED or SECTION_QUERY or SECTION_MAP_WRITE or SECTION_MAP_READ or SECTION_MAP_EXECUTE or SECTION_EXTEND_SIZE>

SESSION_QUERY_ACCESS                            equ     00001H
SESSION_MODIFY_ACCESS                           equ     00002H
SESSION_ALL_ACCESS                              equ     <STANDARD_RIGHTS_REQUIRED or SESSION_QUERY_ACCESS or SESSION_MODIFY_ACCESS>

PAGE_NOACCESS                                   equ     001H
PAGE_READONLY                                   equ     002H
PAGE_READWRITE                                  equ     004H
PAGE_WRITECOPY                                  equ     008H
PAGE_EXECUTE                                    equ     010H
PAGE_EXECUTE_READ                               equ     020H
PAGE_EXECUTE_READWRITE                          equ     040H
PAGE_EXECUTE_WRITECOPY                          equ     080H

PAGE_GUARD                                      equ     0100H
PAGE_NOCACHE                                    equ     0200H
PAGE_WRITECOMBINE                               equ     0400H
PAGE_REVERT_TO_FILE_MAP                         equ     080000000H

MEM_COMMIT                                      equ     01000H
MEM_RESERVE                                     equ     02000H
MEM_DECOMMIT                                    equ     04000H
MEM_RELEASE                                     equ     08000H
MEM_FREE                                        equ     010000H
MEM_PRIVATE                                     equ     020000H
MEM_MAPPED                                      equ     040000H
MEM_RESET                                       equ     080000H
MEM_TOP_DOWN                                    equ     0100000H
MEM_WRITE_WATCH                                 equ     0200000H
MEM_PHYSICAL                                    equ     0400000H
MEM_ROTATE                                      equ     0800000H
MEM_DIFFERENT_IMAGE_BASE_OK                     equ     0800000H
MEM_RESET_UNDO                                  equ     01000000H
MEM_LARGE_PAGES                                 equ     020000000H
MEM_4MB_PAGES                                   equ     080000000H

SEC_IMAGE                                       equ     01000000H
MEM_IMAGE                                       equ     SEC_IMAGE

WRITE_WATCH_FLAG_RESET                          equ     001H

FILE_READ_DATA                                  equ     00001H
FILE_LIST_DIRECTORY                             equ     00001H
FILE_WRITE_DATA                                 equ     00002H
FILE_ADD_FILE                                   equ     00002H

FILE_APPEND_DATA                                equ     00004H
FILE_ADD_SUBDIRECTORY                           equ     00004H
FILE_CREATE_PIPE_INSTANCE                       equ     00004H
FILE_READ_EA                                    equ     00008H
FILE_WRITE_EA                                   equ     00010H
FILE_EXECUTE                                    equ     00020H
FILE_TRAVERSE                                   equ     00020H
FILE_DELETE_CHILD                               equ     00040H
FILE_READ_ATTRIBUTES                            equ     00080H
FILE_WRITE_ATTRIBUTES                           equ     00100H

FILE_ALL_ACCESS                                 equ     <STANDARD_RIGHTS_REQUIRED or SYNCHRONIZE or 01FFH>
FILE_GENERIC_READ                               equ     <STANDARD_RIGHTS_READ or FILE_READ_DATA or FILE_READ_ATTRIBUTES or FILE_READ_EA or SYNCHRONIZE>
FILE_GENERIC_WRITE                              equ     <STANDARD_RIGHTS_WRITE or FILE_WRITE_DATA or FILE_WRITE_ATTRIBUTES or FILE_WRITE_EA or FILE_APPEND_DATA or SYNCHRONIZE>
FILE_GENERIC_EXECUTE                            equ     <STANDARD_RIGHTS_EXECUTE or FILE_READ_ATTRIBUTES or FILE_EXECUTE or SYNCHRONIZE>

FILE_SHARE_READ                                 equ     000000001H
FILE_SHARE_WRITE                                equ     000000002H
FILE_SHARE_DELETE                               equ     000000004H

FILE_ATTRIBUTE_READONLY                         equ     000000001H
FILE_ATTRIBUTE_HIDDEN                           equ     000000002H
FILE_ATTRIBUTE_SYSTEM                           equ     000000004H
FILE_ATTRIBUTE_DIRECTORY                        equ     000000010H
FILE_ATTRIBUTE_ARCHIVE                          equ     000000020H
FILE_ATTRIBUTE_DEVICE                           equ     000000040H
FILE_ATTRIBUTE_NORMAL                           equ     000000080H
FILE_ATTRIBUTE_TEMPORARY                        equ     000000100H
FILE_ATTRIBUTE_SPARSE_FILE                      equ     000000200H
FILE_ATTRIBUTE_REPARSE_POINT                    equ     000000400H
FILE_ATTRIBUTE_COMPRESSED                       equ     000000800H
FILE_ATTRIBUTE_OFFLINE                          equ     000001000H
FILE_ATTRIBUTE_NOT_CONTENT_INDEXED              equ     000002000H
FILE_ATTRIBUTE_ENCRYPTED                        equ     000004000H
FILE_ATTRIBUTE_INTEGRITY_STREAM                 equ     000008000H
FILE_ATTRIBUTE_VIRTUAL                          equ     000010000H
FILE_ATTRIBUTE_NO_SCRUB_DATA                    equ     000020000H
FILE_ATTRIBUTE_EA                               equ     000040000H

FILE_NOTIFY_CHANGE_FILE_NAME                    equ     000000001H
FILE_NOTIFY_CHANGE_DIR_NAME                     equ     000000002H
FILE_NOTIFY_CHANGE_ATTRIBUTES                   equ     000000004H
FILE_NOTIFY_CHANGE_SIZE                         equ     000000008H
FILE_NOTIFY_CHANGE_LAST_WRITE                   equ     000000010H
FILE_NOTIFY_CHANGE_LAST_ACCESS                  equ     000000020H
FILE_NOTIFY_CHANGE_CREATION                     equ     000000040H
FILE_NOTIFY_CHANGE_SECURITY                     equ     000000100H

FILE_ACTION_ADDED                               equ     000000001H
FILE_ACTION_REMOVED                             equ     000000002H
FILE_ACTION_MODIFIED                            equ     000000003H
FILE_ACTION_RENAMED_OLD_NAME                    equ     000000004H
FILE_ACTION_RENAMED_NEW_NAME                    equ     000000005H

FILE_CASE_SENSITIVE_SEARCH                      equ     000000001H
FILE_CASE_PRESERVED_NAMES                       equ     000000002H
FILE_UNICODE_ON_DISK                            equ     000000004H
FILE_PERSISTENT_ACLS                            equ     000000008H
FILE_FILE_COMPRESSION                           equ     000000010H
FILE_VOLUME_QUOTAS                              equ     000000020H
FILE_SUPPORTS_SPARSE_FILES                      equ     000000040H
FILE_SUPPORTS_REPARSE_POINTS                    equ     000000080H
FILE_SUPPORTS_REMOTE_STORAGE                    equ     000000100H
FILE_VOLUME_IS_COMPRESSED                       equ     000008000H
FILE_SUPPORTS_OBJECT_IDS                        equ     000010000H
FILE_SUPPORTS_ENCRYPTION                        equ     000020000H
FILE_NAMED_STREAMS                              equ     000040000H
FILE_READ_ONLY_VOLUME                           equ     000080000H
FILE_SEQUENTIAL_WRITE_ONCE                      equ     000100000H
FILE_SUPPORTS_TRANSACTIONS                      equ     000200000H
FILE_SUPPORTS_HARD_LINKS                        equ     000400000H
FILE_SUPPORTS_EXTENDED_ATTRIBUTES               equ     000800000H
FILE_SUPPORTS_OPEN_BY_FILE_ID                   equ     001000000H
FILE_SUPPORTS_USN_JOURNAL                       equ     002000000H
FILE_SUPPORTS_INTEGRITY_STREAMS                 equ     004000000H
FILE_INVALID_FILE_ID                            equ     (-1)

MAILSLOT_NO_MESSAGE                             equ     (-1)
MAILSLOT_WAIT_FOREVER                           equ     (-1)

MAXIMUM_REPARSE_DATA_BUFFER_SIZE                equ     (16*1024)

IO_REPARSE_TAG_RESERVED_ZERO                    equ     0
IO_REPARSE_TAG_RESERVED_ONE                     equ     1
IO_REPARSE_TAG_RESERVED_RANGE                   equ     IO_REPARSE_TAG_RESERVED_ONE

IO_REPARSE_TAG_MOUNT_POINT                      equ     0A0000003H
IO_REPARSE_TAG_HSM                              equ     0C0000004H
IO_REPARSE_TAG_HSM2                             equ     080000006H
IO_REPARSE_TAG_SIS                              equ     080000007H
IO_REPARSE_TAG_WIM                              equ     080000008H
IO_REPARSE_TAG_CSV                              equ     080000009H
IO_REPARSE_TAG_DFS                              equ     08000000AH
IO_REPARSE_TAG_SYMLINK                          equ     0A000000CH
IO_REPARSE_TAG_DFSR                             equ     080000012H
IO_REPARSE_TAG_DEDUP                            equ     080000013H
IO_REPARSE_TAG_NFS                              equ     080000014H
IO_REPARSE_TAG_FILE_PLACEHOLDER                 equ     080000015H
IO_REPARSE_TAG_WOF                              equ     080000017H

IO_COMPLETION_MODIFY_STATE                      equ     00002H
IO_COMPLETION_ALL_ACCESS                        equ     <STANDARD_RIGHTS_REQUIRED or SYNCHRONIZE or 03H>

DUPLICATE_CLOSE_SOURCE                          equ     000000001H
DUPLICATE_SAME_ACCESS                           equ     000000002H

ES_SYSTEM_REQUIRED                              equ     000000001H
ES_DISPLAY_REQUIRED                             equ     000000002H
ES_USER_PRESENT                                 equ     000000004H
ES_AWAYMODE_REQUIRED                            equ     000000040H
ES_CONTINUOUS                                   equ     080000000H

IMAGE_DOS_SIGNATURE                             equ     05A4DH
IMAGE_OS2_SIGNATURE                             equ     0454EH
IMAGE_OS2_SIGNATURE_LE                          equ     0454CH
IMAGE_VXD_SIGNATURE                             equ     0454CH
IMAGE_NT_SIGNATURE                              equ     000004550H

IMAGE_SIZEOF_FILE_HEADER                        equ     20

IMAGE_FILE_RELOCS_STRIPPED                      equ     00001H
IMAGE_FILE_EXECUTABLE_IMAGE                     equ     00002H
IMAGE_FILE_LINE_NUMS_STRIPPED                   equ     00004H
IMAGE_FILE_LOCAL_SYMS_STRIPPED                  equ     00008H
IMAGE_FILE_AGGRESIVE_WS_TRIM                    equ     00010H
IMAGE_FILE_LARGE_ADDRESS_AWARE                  equ     00020H
IMAGE_FILE_BYTES_REVERSED_LO                    equ     00080H
IMAGE_FILE_32BIT_MACHINE                        equ     00100H
IMAGE_FILE_DEBUG_STRIPPED                       equ     00200H
IMAGE_FILE_REMOVABLE_RUN_FROM_SWAP              equ     00400H
IMAGE_FILE_NET_RUN_FROM_SWAP                    equ     00800H
IMAGE_FILE_SYSTEM                               equ     01000H
IMAGE_FILE_DLL                                  equ     02000H
IMAGE_FILE_UP_SYSTEM_ONLY                       equ     04000H
IMAGE_FILE_BYTES_REVERSED_HI                    equ     08000H

IMAGE_FILE_MACHINE_UNKNOWN                      equ     0
IMAGE_FILE_MACHINE_I386                         equ     014cH
IMAGE_FILE_MACHINE_R3000                        equ     0162H
IMAGE_FILE_MACHINE_R4000                        equ     0166H
IMAGE_FILE_MACHINE_R10000                       equ     0168H
IMAGE_FILE_MACHINE_WCEMIPSV2                    equ     0169H
IMAGE_FILE_MACHINE_ALPHA                        equ     0184H
IMAGE_FILE_MACHINE_POWERPC                      equ     01F0H
IMAGE_FILE_MACHINE_SH3                          equ     01a2H
IMAGE_FILE_MACHINE_SH3E                         equ     01a4H
IMAGE_FILE_MACHINE_SH4                          equ     01a6H
IMAGE_FILE_MACHINE_ARM                          equ     01c0H
IMAGE_FILE_MACHINE_THUMB                        equ     01c2H
IMAGE_FILE_MACHINE_IA64                         equ     0200H
IMAGE_FILE_MACHINE_MIPS16                       equ     0266H
IMAGE_FILE_MACHINE_MIPSFPU                      equ     0366H
IMAGE_FILE_MACHINE_MIPSFPU16                    equ     0466H
IMAGE_FILE_MACHINE_ALPHA64                      equ     0284H
IMAGE_FILE_MACHINE_AXP64                        equ     IMAGE_FILE_MACHINE_ALPHA64
IMAGE_FILE_MACHINE_CEF                          equ     0C0EFH
IMAGE_FILE_MACHINE_EBC                          equ     0EBCH
IMAGE_FILE_MACHINE_AMD64                        equ     8664H
IMAGE_FILE_MACHINE_M32R                         equ     9041H
IMAGE_FILE_MACHINE_CEE                          equ     0C0EEH

IMAGE_SIZEOF_ROM_OPTIONAL_HEADER                equ     56
IMAGE_SIZEOF_STD_OPTIONAL_HEADER                equ     28
IMAGE_SIZEOF_NT_OPTIONAL32_HEADER               equ     224
IMAGE_SIZEOF_NT_OPTIONAL64_HEADER               equ     240

IMAGE_NT_OPTIONAL_HDR32_MAGIC                   equ     10bH
IMAGE_NT_OPTIONAL_HDR64_MAGIC                   equ     20bH
IMAGE_ROM_OPTIONAL_HDR_MAGIC                    equ     107H

IMAGE_SUBSYSTEM_UNKNOWN                         equ     0
IMAGE_SUBSYSTEM_NATIVE                          equ     1
IMAGE_SUBSYSTEM_WINDOWS_GUI                     equ     2
IMAGE_SUBSYSTEM_WINDOWS_CUI                     equ     3
IMAGE_SUBSYSTEM_OS2_CUI                         equ     5
IMAGE_SUBSYSTEM_POSIX_CUI                       equ     7
IMAGE_SUBSYSTEM_NATIVE_WINDOWS                  equ     8
IMAGE_SUBSYSTEM_WINDOWS_CE_GUI                  equ     9
IMAGE_SUBSYSTEM_EFI_APPLICATION                 equ     10
IMAGE_SUBSYSTEM_EFI_BOOT_SERVICE_DRIVER         equ     11
IMAGE_SUBSYSTEM_EFI_RUNTIME_DRIVER              equ     12
IMAGE_SUBSYSTEM_EFI_ROM                         equ     13
IMAGE_SUBSYSTEM_XBOX                            equ     14
IMAGE_SUBSYSTEM_WINDOWS_BOOT_APPLICATION        equ     16

IMAGE_DLLCHARACTERISTICS_NO_BIND                equ     0800H
IMAGE_DLLCHARACTERISTICS_WDM_DRIVER             equ     2000H
IMAGE_DLLCHARACTERISTICS_TERMINAL_SERVER_AWARE  equ     8000H
IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE           equ     0040H
IMAGE_DLLCHARACTERISTICS_FORCE_INTEGRITY        equ     0080H
IMAGE_DLLCHARACTERISTICS_NX_COMPAT              equ     0100H
IMAGE_DLLCHARACTERISTICS_NO_ISOLATION           equ     0200H
IMAGE_DLLCHARACTERISTICS_NO_SEH                 equ     0400H

IMAGE_DIRECTORY_ENTRY_EXPORT                    equ     0
IMAGE_DIRECTORY_ENTRY_IMPORT                    equ     1
IMAGE_DIRECTORY_ENTRY_RESOURCE                  equ     2
IMAGE_DIRECTORY_ENTRY_EXCEPTION                 equ     3
IMAGE_DIRECTORY_ENTRY_SECURITY                  equ     4
IMAGE_DIRECTORY_ENTRY_BASERELOC                 equ     5
IMAGE_DIRECTORY_ENTRY_DEBUG                     equ     6
IMAGE_DIRECTORY_ENTRY_COPYRIGHT                 equ     7
IMAGE_DIRECTORY_ENTRY_ARCHITECTURE              equ     7
IMAGE_DIRECTORY_ENTRY_GLOBALPTR                 equ     8
IMAGE_DIRECTORY_ENTRY_TLS                       equ     9
IMAGE_DIRECTORY_ENTRY_LOAD_CONFIG               equ     10
IMAGE_DIRECTORY_ENTRY_BOUND_IMPORT              equ     11
IMAGE_DIRECTORY_ENTRY_IAT                       equ     12
IMAGE_DIRECTORY_ENTRY_DELAY_IMPORT              equ     13
IMAGE_DIRECTORY_ENTRY_COM_DESCRIPTOR            equ     14

IMAGE_SIZEOF_SECTION_HEADER                     equ     40

IMAGE_SIZEOF_SYMBOL                             equ     18

IMAGE_SYM_UNDEFINED                             equ     0
IMAGE_SYM_ABSOLUTE                              equ     (-1)
IMAGE_SYM_DEBUG                                 equ     (-2)

IMAGE_SYM_TYPE_NULL                             equ     0000H
IMAGE_SYM_TYPE_VOID                             equ     0001H
IMAGE_SYM_TYPE_CHAR                             equ     0002H
IMAGE_SYM_TYPE_SHORT                            equ     0003H
IMAGE_SYM_TYPE_INT                              equ     0004H
IMAGE_SYM_TYPE_LONG                             equ     0005H
IMAGE_SYM_TYPE_FLOAT                            equ     0006H
IMAGE_SYM_TYPE_DOUBLE                           equ     0007H
IMAGE_SYM_TYPE_STRUCT                           equ     0008H
IMAGE_SYM_TYPE_UNION                            equ     0009H
IMAGE_SYM_TYPE_ENUM                             equ     000AH
IMAGE_SYM_TYPE_MOE                              equ     000BH
IMAGE_SYM_TYPE_BYTE                             equ     000CH
IMAGE_SYM_TYPE_WORD                             equ     000DH
IMAGE_SYM_TYPE_UINT                             equ     000EH
IMAGE_SYM_TYPE_DWORD                            equ     000FH
IMAGE_SYM_TYPE_PCODE                            equ     8000H

IMAGE_SYM_DTYPE_NULL                            equ     0
IMAGE_SYM_DTYPE_POINTER                         equ     1
IMAGE_SYM_DTYPE_FUNCTION                        equ     2
IMAGE_SYM_DTYPE_ARRAY                           equ     3

IMAGE_SYM_CLASS_END_OF_FUNCTION                 equ     (-1)
IMAGE_SYM_CLASS_NULL                            equ     0000H
IMAGE_SYM_CLASS_AUTOMATIC                       equ     0001H
IMAGE_SYM_CLASS_EXTERNAL                        equ     0002H
IMAGE_SYM_CLASS_STATIC                          equ     0003H
IMAGE_SYM_CLASS_REGISTER                        equ     0004H
IMAGE_SYM_CLASS_EXTERNAL_DEF                    equ     0005H
IMAGE_SYM_CLASS_LABEL                           equ     0006H
IMAGE_SYM_CLASS_UNDEFINED_LABEL                 equ     0007H
IMAGE_SYM_CLASS_MEMBER_OF_STRUCT                equ     0008H
IMAGE_SYM_CLASS_ARGUMENT                        equ     0009H
IMAGE_SYM_CLASS_STRUCT_TAG                      equ     000AH
IMAGE_SYM_CLASS_MEMBER_OF_UNION                 equ     000BH
IMAGE_SYM_CLASS_UNION_TAG                       equ     000CH
IMAGE_SYM_CLASS_TYPE_DEFINITION                 equ     000DH
IMAGE_SYM_CLASS_UNDEFINED_STATIC                equ     000EH
IMAGE_SYM_CLASS_ENUM_TAG                        equ     000FH
IMAGE_SYM_CLASS_MEMBER_OF_ENUM                  equ     0010H
IMAGE_SYM_CLASS_REGISTER_PARAM                  equ     0011H
IMAGE_SYM_CLASS_BIT_FIELD                       equ     0012H

IMAGE_SYM_CLASS_FAR_EXTERNAL                    equ     0044H

IMAGE_SYM_CLASS_BLOCK                           equ     0064H
IMAGE_SYM_CLASS_FUNCTION                        equ     0065H
IMAGE_SYM_CLASS_END_OF_STRUCT                   equ     0066H
IMAGE_SYM_CLASS_FILE                            equ     0067H
IMAGE_SYM_CLASS_SECTION                         equ     0068H
IMAGE_SYM_CLASS_WEAK_EXTERNAL                   equ     0069H

IMAGE_SIZEOF_AUX_SYMBOL                         equ     18

IMAGE_COMDAT_SELECT_NODUPLICATES                equ     1
IMAGE_COMDAT_SELECT_ANY                         equ     2
IMAGE_COMDAT_SELECT_SAME_SIZE                   equ     3
IMAGE_COMDAT_SELECT_EXACT_MATCH                 equ     4
IMAGE_COMDAT_SELECT_ASSOCIATIVE                 equ     5
IMAGE_COMDAT_SELECT_LARGEST                     equ     6
IMAGE_COMDAT_SELECT_NEWEST                      equ     7

IMAGE_WEAK_EXTERN_SEARCH_NOLIBRARY              equ     1
IMAGE_WEAK_EXTERN_SEARCH_LIBRARY                equ     2
IMAGE_WEAK_EXTERN_SEARCH_ALIAS                  equ     3

IMAGE_SIZEOF_RELOCATION                         equ     10

IMAGE_REL_I386_ABSOLUTE                         equ     0000H
IMAGE_REL_I386_DIR16                            equ     0001H
IMAGE_REL_I386_REL16                            equ     0002H
IMAGE_REL_I386_DIR32                            equ     0006H
IMAGE_REL_I386_DIR32NB                          equ     0007H
IMAGE_REL_I386_SEG12                            equ     0009H
IMAGE_REL_I386_SECTION                          equ     000AH
IMAGE_REL_I386_SECREL                           equ     000BH
IMAGE_REL_I386_REL32                            equ     0014H

IMAGE_REL_MIPS_ABSOLUTE                         equ     0000H
IMAGE_REL_MIPS_REFHALF                          equ     0001H
IMAGE_REL_MIPS_REFWORD                          equ     0002H
IMAGE_REL_MIPS_JMPADDR                          equ     0003H
IMAGE_REL_MIPS_REFHI                            equ     0004H
IMAGE_REL_MIPS_REFLO                            equ     0005H
IMAGE_REL_MIPS_GPREL                            equ     0006H
IMAGE_REL_MIPS_LITERAL                          equ     0007H
IMAGE_REL_MIPS_SECTION                          equ     000AH
IMAGE_REL_MIPS_SECREL                           equ     000BH
IMAGE_REL_MIPS_SECRELLO                         equ     000CH
IMAGE_REL_MIPS_SECRELHI                         equ     000DH
IMAGE_REL_MIPS_TOKEN                            equ     000EH
IMAGE_REL_MIPS_JMPADDR16                        equ     0010H
IMAGE_REL_MIPS_REFWORDNB                        equ     0022H
IMAGE_REL_MIPS_PAIR                             equ     0025H

IMAGE_REL_ALPHA_ABSOLUTE                        equ     0000H
IMAGE_REL_ALPHA_REFLONG                         equ     0001H
IMAGE_REL_ALPHA_REFQUAD                         equ     0002H
IMAGE_REL_ALPHA_GPREL32                         equ     0003H
IMAGE_REL_ALPHA_LITERAL                         equ     0004H
IMAGE_REL_ALPHA_LITUSE                          equ     0005H
IMAGE_REL_ALPHA_GPDISP                          equ     0006H
IMAGE_REL_ALPHA_BRADDR                          equ     0007H
IMAGE_REL_ALPHA_HINT                            equ     0008H
IMAGE_REL_ALPHA_INLINE_REFLONG                  equ     0009H
IMAGE_REL_ALPHA_REFHI                           equ     000AH
IMAGE_REL_ALPHA_REFLO                           equ     000BH
IMAGE_REL_ALPHA_PAIR                            equ     000CH
IMAGE_REL_ALPHA_MATCH                           equ     000DH
IMAGE_REL_ALPHA_SECTION                         equ     000EH
IMAGE_REL_ALPHA_SECREL                          equ     000FH
IMAGE_REL_ALPHA_REFLONGNB                       equ     0010H
IMAGE_REL_ALPHA_SECRELLO                        equ     0011H
IMAGE_REL_ALPHA_SECRELHI                        equ     0012H
IMAGE_REL_ALPHA_REFQ3                           equ     0013H
IMAGE_REL_ALPHA_REFQ2                           equ     0014H
IMAGE_REL_ALPHA_REFQ1                           equ     0015H
IMAGE_REL_ALPHA_GPRELLO                         equ     0016H
IMAGE_REL_ALPHA_GPRELHI                         equ     0017H

IMAGE_REL_PPC_ABSOLUTE                          equ     0000H
IMAGE_REL_PPC_ADDR64                            equ     0001H
IMAGE_REL_PPC_ADDR32                            equ     0002H
IMAGE_REL_PPC_ADDR24                            equ     0003H
IMAGE_REL_PPC_ADDR16                            equ     0004H
IMAGE_REL_PPC_ADDR14                            equ     0005H
IMAGE_REL_PPC_REL24                             equ     0006H
IMAGE_REL_PPC_REL14                             equ     0007H
IMAGE_REL_PPC_TOCREL16                          equ     0008H
IMAGE_REL_PPC_TOCREL14                          equ     0009H

IMAGE_REL_PPC_ADDR32NB                          equ     000AH
IMAGE_REL_PPC_SECREL                            equ     000BH
IMAGE_REL_PPC_SECTION                           equ     000CH
IMAGE_REL_PPC_IFGLUE                            equ     000DH
IMAGE_REL_PPC_IMGLUE                            equ     000EH
IMAGE_REL_PPC_SECREL16                          equ     000FH
IMAGE_REL_PPC_REFHI                             equ     0010H
IMAGE_REL_PPC_REFLO                             equ     0011H
IMAGE_REL_PPC_PAIR                              equ     0012H
IMAGE_REL_PPC_SECRELLO                          equ     0013H
IMAGE_REL_PPC_SECRELHI                          equ     0014H
IMAGE_REL_PPC_GPREL                             equ     0015H
IMAGE_REL_PPC_TOKEN                             equ     0016H

IMAGE_REL_PPC_TYPEMASK                          equ     00FFH

IMAGE_REL_PPC_NEG                               equ     0100H
IMAGE_REL_PPC_BRTAKEN                           equ     0200H
IMAGE_REL_PPC_BRNTAKEN                          equ     0400H
IMAGE_REL_PPC_TOCDEFN                           equ     0800H

IMAGE_REL_SH3_ABSOLUTE                          equ     0000H
IMAGE_REL_SH3_DIRECT16                          equ     0001H
IMAGE_REL_SH3_DIRECT32                          equ     0002H
IMAGE_REL_SH3_DIRECT8                           equ     0003H
IMAGE_REL_SH3_DIRECT8_WORD                      equ     0004H
IMAGE_REL_SH3_DIRECT8_LONG                      equ     0005H
IMAGE_REL_SH3_DIRECT4                           equ     0006H
IMAGE_REL_SH3_DIRECT4_WORD                      equ     0007H
IMAGE_REL_SH3_DIRECT4_LONG                      equ     0008H
IMAGE_REL_SH3_PCREL8_WORD                       equ     0009H
IMAGE_REL_SH3_PCREL8_LONG                       equ     000AH
IMAGE_REL_SH3_PCREL12_WORD                      equ     000BH
IMAGE_REL_SH3_STARTOF_SECTION                   equ     000CH
IMAGE_REL_SH3_SIZEOF_SECTION                    equ     000DH
IMAGE_REL_SH3_SECTION                           equ     000EH
IMAGE_REL_SH3_SECREL                            equ     000FH
IMAGE_REL_SH3_DIRECT32_NB                       equ     0010H
IMAGE_REL_SH3_GPREL4_LONG                       equ     0011H
IMAGE_REL_SH3_TOKEN                             equ     0012H
IMAGE_REL_SHM_PCRELPT                           equ     0013H
IMAGE_REL_SHM_REFLO                             equ     0014H
IMAGE_REL_SHM_REFHALF                           equ     0015H
IMAGE_REL_SHM_RELLO                             equ     0016H
IMAGE_REL_SHM_RELHALF                           equ     0017H
IMAGE_REL_SHM_PAIR                              equ     0018H

IMAGE_REL_SH_NOMODE                             equ     8000H

IMAGE_REL_ARM_ABSOLUTE                          equ     0000H
IMAGE_REL_ARM_ADDR32                            equ     0001H
IMAGE_REL_ARM_ADDR32NB                          equ     0002H
IMAGE_REL_ARM_BRANCH24                          equ     0003H
IMAGE_REL_ARM_BRANCH11                          equ     0004H
IMAGE_REL_ARM_TOKEN                             equ     0005H
IMAGE_REL_ARM_GPREL12                           equ     0006H
IMAGE_REL_ARM_GPREL7                            equ     0007H
IMAGE_REL_ARM_BLX24                             equ     0008H
IMAGE_REL_ARM_BLX11                             equ     0009H
IMAGE_REL_ARM_SECTION                           equ     000EH
IMAGE_REL_ARM_SECREL                            equ     000FH

IMAGE_REL_AM_ABSOLUTE                           equ     0000H
IMAGE_REL_AM_ADDR32                             equ     0001H
IMAGE_REL_AM_ADDR32NB                           equ     0002H
IMAGE_REL_AM_CALL32                             equ     0003H
IMAGE_REL_AM_FUNCINFO                           equ     0004H
IMAGE_REL_AM_REL32_1                            equ     0005H
IMAGE_REL_AM_REL32_2                            equ     0006H
IMAGE_REL_AM_SECREL                             equ     0007H
IMAGE_REL_AM_SECTION                            equ     0008H
IMAGE_REL_AM_TOKEN                              equ     0009H

IMAGE_REL_AMD64_ABSOLUTE                        equ     0000H
IMAGE_REL_AMD64_ADDR64                          equ     0001H
IMAGE_REL_AMD64_ADDR32                          equ     0002H
IMAGE_REL_AMD64_ADDR32NB                        equ     0003H
IMAGE_REL_AMD64_REL32                           equ     0004H
IMAGE_REL_AMD64_REL32_1                         equ     0005H
IMAGE_REL_AMD64_REL32_2                         equ     0006H
IMAGE_REL_AMD64_REL32_3                         equ     0007H
IMAGE_REL_AMD64_REL32_4                         equ     0008H
IMAGE_REL_AMD64_REL32_5                         equ     0009H
IMAGE_REL_AMD64_SECTION                         equ     000AH
IMAGE_REL_AMD64_SECREL                          equ     000BH
IMAGE_REL_AMD64_SECREL7                         equ     000CH
IMAGE_REL_AMD64_TOKEN                           equ     000DH
IMAGE_REL_AMD64_SREL32                          equ     000EH
IMAGE_REL_AMD64_PAIR                            equ     000FH
IMAGE_REL_AMD64_SSPAN32                         equ     0010H

IMAGE_REL_IA64_ABSOLUTE                         equ     0000H
IMAGE_REL_IA64_IMM14                            equ     0001H
IMAGE_REL_IA64_IMM22                            equ     0002H
IMAGE_REL_IA64_IMM64                            equ     0003H
IMAGE_REL_IA64_DIR32                            equ     0004H
IMAGE_REL_IA64_DIR64                            equ     0005H
IMAGE_REL_IA64_PCREL21B                         equ     0006H
IMAGE_REL_IA64_PCREL21M                         equ     0007H
IMAGE_REL_IA64_PCREL21F                         equ     0008H
IMAGE_REL_IA64_GPREL22                          equ     0009H
IMAGE_REL_IA64_LTOFF22                          equ     000AH
IMAGE_REL_IA64_SECTION                          equ     000BH
IMAGE_REL_IA64_SECREL22                         equ     000CH
IMAGE_REL_IA64_SECREL64I                        equ     000DH
IMAGE_REL_IA64_SECREL32                         equ     000EH
IMAGE_REL_IA64_LTOFF64                          equ     000FH
IMAGE_REL_IA64_DIR32NB                          equ     0010H
IMAGE_REL_IA64_SREL22                           equ     0011H
IMAGE_REL_IA64_UREL22                           equ     0012H
IMAGE_REL_IA64_SREL32                           equ     0013H
IMAGE_REL_IA64_UREL32                           equ     0014H
IMAGE_REL_IA64_ADDEND                           equ     001FH

IMAGE_REL_CEF_ABSOLUTE                          equ     0000H
IMAGE_REL_CEF_ADDR32                            equ     0001H
IMAGE_REL_CEF_ADDR64                            equ     0002H
IMAGE_REL_CEF_ADDR32NB                          equ     0003H
IMAGE_REL_CEF_SECTION                           equ     0004H
IMAGE_REL_CEF_SECREL                            equ     0005H
IMAGE_REL_CEF_TOKEN                             equ     0006H

IMAGE_REL_CEE_ABSOLUTE                          equ     0000H
IMAGE_REL_CEE_ADDR32                            equ     0001H
IMAGE_REL_CEE_ADDR64                            equ     0002H
IMAGE_REL_CEE_ADDR32NB                          equ     0003H
IMAGE_REL_CEE_SECTION                           equ     0004H
IMAGE_REL_CEE_SECREL                            equ     0005H
IMAGE_REL_CEE_TOKEN                             equ     0006H

IMAGE_REL_M32R_ABSOLUTE                         equ     0000H
IMAGE_REL_M32R_ADDR32                           equ     0001H
IMAGE_REL_M32R_ADDR32NB                         equ     0002H
IMAGE_REL_M32R_ADDR24                           equ     0003H
IMAGE_REL_M32R_GPREL16                          equ     0004H
IMAGE_REL_M32R_PCREL24                          equ     0005H
IMAGE_REL_M32R_PCREL16                          equ     0006H
IMAGE_REL_M32R_PCREL8                           equ     0007H
IMAGE_REL_M32R_REFHALF                          equ     0008H
IMAGE_REL_M32R_REFHI                            equ     0009H
IMAGE_REL_M32R_REFLO                            equ     000AH
IMAGE_REL_M32R_PAIR                             equ     000BH
IMAGE_REL_M32R_SECTION                          equ     000CH
IMAGE_REL_M32R_SECREL32                         equ     000DH
IMAGE_REL_M32R_TOKEN                            equ     000EH

IMAGE_REL_EBC_ABSOLUTE                          equ     0000H
IMAGE_REL_EBC_ADDR32NB                          equ     0001H
IMAGE_REL_EBC_REL32                             equ     0002H
IMAGE_REL_EBC_SECTION                           equ     0003H
IMAGE_REL_EBC_SECREL                            equ     0004H

IMAGE_SIZEOF_LINENUMBER                         equ     6
IMAGE_SIZEOF_BASE_RELOCATION                    equ     8

IMAGE_REL_BASED_ABSOLUTE                        equ     0
IMAGE_REL_BASED_HIGH                            equ     1
IMAGE_REL_BASED_LOW                             equ     2
IMAGE_REL_BASED_HIGHLOW                         equ     3
IMAGE_REL_BASED_HIGHADJ                         equ     4
IMAGE_REL_BASED_MIPS_JMPADDR                    equ     5
IMAGE_REL_BASED_SECTION                         equ     6
IMAGE_REL_BASED_REL32                           equ     7

IMAGE_REL_BASED_MIPS_JMPADDR16                  equ     9
IMAGE_REL_BASED_IA64_IMM64                      equ     9
IMAGE_REL_BASED_DIR64                           equ     10
IMAGE_REL_BASED_HIGH3ADJ                        equ     11

IMAGE_ARCHIVE_START_SIZE                        equ     8
IMAGE_ARCHIVE_PAD                               equ     10

IMAGE_ORDINAL_FLAG64                            equ     8000000000000000H
IMAGE_ORDINAL_FLAG32                            equ     80000000H

IMAGE_RESOURCE_NAME_IS_STRING                   equ     80000000H
IMAGE_RESOURCE_DATA_IS_DIRECTORY                equ     80000000H

IMAGE_DEBUG_TYPE_UNKNOWN                        equ     0
IMAGE_DEBUG_TYPE_COFF                           equ     1
IMAGE_DEBUG_TYPE_CODEVIEW                       equ     2
IMAGE_DEBUG_TYPE_FPO                            equ     3
IMAGE_DEBUG_TYPE_MISC                           equ     4
IMAGE_DEBUG_TYPE_EXCEPTION                      equ     5
IMAGE_DEBUG_TYPE_FIXUP                          equ     6
IMAGE_DEBUG_TYPE_OMAP_TO_SRC                    equ     7
IMAGE_DEBUG_TYPE_OMAP_FROM_SRC                  equ     8
IMAGE_DEBUG_TYPE_BORLAND                        equ     9
IMAGE_DEBUG_TYPE_RESERVED10                     equ     10
IMAGE_DEBUG_TYPE_CLSID                          equ     11

FRAME_FPO                                       equ     0
FRAME_TRAP                                      equ     1
FRAME_TSS                                       equ     2
FRAME_NONFPO                                    equ     3

SIZEOF_RFPO_DATA                                equ     16

IMAGE_DEBUG_MISC_EXENAME                        equ     1

IMAGE_SEPARATE_DEBUG_SIGNATURE                  equ     4944H
IMAGE_SEPARATE_DEBUG_FLAGS_MASK                 equ     8000H
IMAGE_SEPARATE_DEBUG_MISMATCH                   equ     8000H

IMPORT_OBJECT_HDR_SIG2                          equ     0FFFFH

N_BTMASK                                        equ     000FH
N_TMASK                                         equ     0030H
N_TMASK1                                        equ     00C0H
N_TMASK2                                        equ     00F0H
N_BTSHFT                                        equ     4
N_TSHIFT                                        equ     2

FAST_FAIL_LEGACY_GS_VIOLATION                   equ     0
FAST_FAIL_VTGUARD_CHECK_FAILURE                 equ     1
FAST_FAIL_STACK_COOKIE_CHECK_FAILURE            equ     2
FAST_FAIL_CORRUPT_LIST_ENTRY                    equ     3
FAST_FAIL_INCORRECT_STACK                       equ     4
FAST_FAIL_INVALID_ARG                           equ     5
FAST_FAIL_GS_COOKIE_INIT                        equ     6
FAST_FAIL_FATAL_APP_EXIT                        equ     7
FAST_FAIL_RANGE_CHECK_FAILURE                   equ     8
FAST_FAIL_UNSAFE_REGISTRY_ACCESS                equ     9
FAST_FAIL_GUARD_ICALL_CHECK_FAILURE             equ     10
FAST_FAIL_GUARD_WRITE_CHECK_FAILURE             equ     11
FAST_FAIL_INVALID_FIBER_SWITCH                  equ     12
FAST_FAIL_INVALID_SET_OF_CONTEXT                equ     13
FAST_FAIL_INVALID_REFERENCE_COUNT               equ     14
FAST_FAIL_INVALID_JUMP_BUFFER                   equ     18
FAST_FAIL_MRDATA_MODIFIED                       equ     19
FAST_FAIL_CERTIFICATION_FAILURE                 equ     20
FAST_FAIL_INVALID_EXCEPTION_CHAIN               equ     21
FAST_FAIL_CRYPTO_LIBRARY                        equ     22
FAST_FAIL_INVALID_CALL_IN_DLL_CALLOUT           equ     23
FAST_FAIL_INVALID_IMAGE_BASE                    equ     24
FAST_FAIL_DLOAD_PROTECTION_FAILURE              equ     25
FAST_FAIL_UNSAFE_EXTENSION_CALL                 equ     26
FAST_FAIL_INVALID_FAST_FAIL_CODE                equ     0FFFFFFFFH

HEAP_NO_SERIALIZE                               equ     00000001H
HEAP_GROWABLE                                   equ     00000002H
HEAP_GENERATE_EXCEPTIONS                        equ     00000004H
HEAP_ZERO_MEMORY                                equ     00000008H
HEAP_REALLOC_IN_PLACE_ONLY                      equ     00000010H
HEAP_TAIL_CHECKING_ENABLED                      equ     00000020H
HEAP_FREE_CHECKING_ENABLED                      equ     00000040H
HEAP_DISABLE_COALESCE_ON_FREE                   equ     00000080H
HEAP_CREATE_ALIGN_16                            equ     00010000H
HEAP_CREATE_ENABLE_TRACING                      equ     00020000H
HEAP_MAXIMUM_TAG                                equ     0FFFH
HEAP_PSEUDO_TAG_FLAG                            equ     8000H
HEAP_TAG_SHIFT                                  equ     18

IS_TEXT_UNICODE_ASCII16                         equ     0001H
IS_TEXT_UNICODE_REVERSE_ASCII16                 equ     0010H
IS_TEXT_UNICODE_STATISTICS                      equ     0002H
IS_TEXT_UNICODE_REVERSE_STATISTICS              equ     0020H
IS_TEXT_UNICODE_CONTROLS                        equ     0004H
IS_TEXT_UNICODE_REVERSE_CONTROLS                equ     0040H
IS_TEXT_UNICODE_SIGNATURE                       equ     0008H
IS_TEXT_UNICODE_REVERSE_SIGNATURE               equ     0080H
IS_TEXT_UNICODE_ILLEGAL_CHARS                   equ     0100H
IS_TEXT_UNICODE_ODD_LENGTH                      equ     0200H
IS_TEXT_UNICODE_DBCS_LEADBYTE                   equ     0400H
IS_TEXT_UNICODE_NULL_BYTES                      equ     1000H
IS_TEXT_UNICODE_UNICODE_MASK                    equ     000FH
IS_TEXT_UNICODE_REVERSE_MASK                    equ     00F0H
IS_TEXT_UNICODE_NOT_UNICODE_MASK                equ     0F00H
IS_TEXT_UNICODE_NOT_ASCII_MASK                  equ     0F000H

COMPRESSION_FORMAT_NONE                         equ     0000H
COMPRESSION_FORMAT_DEFAULT                      equ     0001H
COMPRESSION_FORMAT_LZNT1                        equ     0002H
COMPRESSION_FORMAT_XPRESS                       equ     0003H
COMPRESSION_FORMAT_XPRESS_HUFF                  equ     0004H
COMPRESSION_ENGINE_STANDARD                     equ     0000H
COMPRESSION_ENGINE_MAXIMUM                      equ     0100H
COMPRESSION_ENGINE_HIBER                        equ     0200H

MESSAGE_RESOURCE_UNICODE                        equ     0001H

VER_EQUAL                                       equ     1
VER_GREATER                                     equ     2
VER_GREATER_EQUAL                               equ     3
VER_LESS                                        equ     4
VER_LESS_EQUAL                                  equ     5
VER_AND                                         equ     6
VER_OR                                          equ     7

VER_CONDITION_MASK                              equ     7
VER_NUM_BITS_PER_CONDITION_MASK                 equ     3

VER_MINORVERSION                                equ     0000001H
VER_MAJORVERSION                                equ     0000002H
VER_BUILDNUMBER                                 equ     0000004H
VER_PLATFORMID                                  equ     0000008H
VER_SERVICEPACKMINOR                            equ     0000010H
VER_SERVICEPACKMAJOR                            equ     0000020H
VER_SUITENAME                                   equ     0000040H
VER_PRODUCT_TYPE                                equ     0000080H

VER_NT_WORKSTATION                              equ     0000001H
VER_NT_DOMAIN_CONTROLLER                        equ     0000002H
VER_NT_SERVER                                   equ     0000003H

VER_PLATFORM_WIN32s                             equ     0
VER_PLATFORM_WIN32_WINDOWS                      equ     1
VER_PLATFORM_WIN32_NT                           equ     2
VER_PLATFORM_WIN32_CE                           equ     3

RTL_CRITSECT_TYPE                               equ     0
RTL_RESOURCE_TYPE                               equ     1

SEF_DACL_AUTO_INHERIT                           equ     01H
SEF_SACL_AUTO_INHERIT                           equ     02H
SEF_DEFAULT_DESCRIPTOR_FOR_OBJECT               equ     04H
SEF_AVOID_PRIVILEGE_CHECK                       equ     08H
SEF_AVOID_OWNER_CHECK                           equ     10H
SEF_DEFAULT_OWNER_FROM_PARENT                   equ     20H
SEF_DEFAULT_GROUP_FROM_PARENT                   equ     40H
SEF_MACL_NO_WRITE_UP                            equ     100H
SEF_MACL_NO_READ_UP                             equ     200H
SEF_MACL_NO_EXECUTE_UP                          equ     0400H
SEF_AI_USE_EXTRA_PARAMS                         equ     0800H
SEF_AVOID_OWNER_RESTRICTION                     equ     01000H
SEF_MACL_VALID_FLAGS                            equ     <SEF_MACL_NO_WRITE_UP or SEF_MACL_NO_READ_UP or SEF_MACL_NO_EXECUTE_UP>

WT_EXECUTEDEFAULT                               equ     00000000H
WT_EXECUTEINIOTHREAD                            equ     00000001H
WT_EXECUTEINUITHREAD                            equ     00000002H
WT_EXECUTEINWAITTHREAD                          equ     00000004H
WT_EXECUTEONLYONCE                              equ     00000008H
WT_EXECUTEINTIMERTHREAD                         equ     00000020H
WT_EXECUTELONGFUNCTION                          equ     00000010H
WT_EXECUTEINPERSISTENTIOTHREAD                  equ     00000040H
WT_EXECUTEINPERSISTENTTHREAD                    equ     00000080H
WT_TRANSFER_IMPERSONATION                       equ     00000100H

WT_EXECUTEINLONGTHREAD                          equ     00000010H
WT_EXECUTEDELETEWAIT                            equ     00000008H

DLL_PROCESS_ATTACH                              equ     1
DLL_THREAD_ATTACH                               equ     2
DLL_THREAD_DETACH                               equ     3
DLL_PROCESS_DETACH                              equ     0

EVENTLOG_SEQUENTIAL_READ                        equ     0001H
EVENTLOG_SEEK_READ                              equ     0002H
EVENTLOG_FORWARDS_READ                          equ     0004H
EVENTLOG_BACKWARDS_READ                         equ     0008H

EVENTLOG_SUCCESS                                equ     0000H
EVENTLOG_ERROR_TYPE                             equ     0001H
EVENTLOG_WARNING_TYPE                           equ     0002H
EVENTLOG_INFORMATION_TYPE                       equ     0004H
EVENTLOG_AUDIT_SUCCESS                          equ     0008H
EVENTLOG_AUDIT_FAILURE                          equ     0010H

EVENTLOG_START_PAIRED_EVENT                     equ     0001H
EVENTLOG_END_PAIRED_EVENT                       equ     0002H
EVENTLOG_END_ALL_PAIRED_EVENTS                  equ     0004H
EVENTLOG_PAIRED_EVENT_ACTIVE                    equ     0008H
EVENTLOG_PAIRED_EVENT_INACTIVE                  equ     0010H

KEY_QUERY_VALUE                                 equ     0001H
KEY_SET_VALUE                                   equ     0002H
KEY_CREATE_SUB_KEY                              equ     0004H
KEY_ENUMERATE_SUB_KEYS                          equ     0008H
KEY_NOTIFY                                      equ     0010H
KEY_CREATE_LINK                                 equ     0020H
KEY_WOW64_32KEY                                 equ     0200H
KEY_WOW64_64KEY                                 equ     0100H
KEY_WOW64_RES                                   equ     0300H

KEY_READ                                        equ     <(STANDARD_RIGHTS_READ or KEY_QUERY_VALUE or KEY_ENUMERATE_SUB_KEYS or KEY_NOTIFY) and (not SYNCHRONIZE)>
KEY_WRITE                                       equ     <(STANDARD_RIGHTS_WRITE or KEY_SET_VALUE or KEY_CREATE_SUB_KEY) and (not SYNCHRONIZE)>
KEY_ALL_ACCESS                                  equ     <(STANDARD_RIGHTS_ALL or KEY_QUERY_VALUE or KEY_SET_VALUE or KEY_CREATE_SUB_KEY or KEY_ENUMERATE_SUB_KEYS or KEY_NOTIFY or KEY_CREATE_LINK) and (not SYNCHRONIZE)>
KEY_EXECUTE                                     equ     KEY_READ

SERVICE_KERNEL_DRIVER                           equ     00000001H
SERVICE_FILE_SYSTEM_DRIVER                      equ     00000002H
SERVICE_ADAPTER                                 equ     00000004H
SERVICE_RECOGNIZER_DRIVER                       equ     00000008H
SERVICE_DRIVER                                  equ     <SERVICE_KERNEL_DRIVER or SERVICE_FILE_SYSTEM_DRIVER or SERVICE_RECOGNIZER_DRIVER>

SERVICE_WIN32_OWN_PROCESS                       equ     00000010H
SERVICE_WIN32_SHARE_PROCESS                     equ     00000020H
SERVICE_WIN32                                   equ     <SERVICE_WIN32_OWN_PROCESS or SERVICE_WIN32_SHARE_PROCESS>

SERVICE_INTERACTIVE_PROCESS                     equ     00000100H

SERVICE_TYPE_ALL                                equ     <SERVICE_WIN32 or SERVICE_ADAPTER or SERVICE_DRIVER or SERVICE_INTERACTIVE_PROCESS>

SERVICE_BOOT_START                              equ     00000000H
SERVICE_SYSTEM_START                            equ     00000001H
SERVICE_AUTO_START                              equ     00000002H
SERVICE_DEMAND_START                            equ     00000003H
SERVICE_DISABLED                                equ     00000004H

SERVICE_ERROR_IGNORE                            equ     00000000H
SERVICE_ERROR_NORMAL                            equ     00000001H
SERVICE_ERROR_SEVERE                            equ     00000002H
SERVICE_ERROR_CRITICAL                          equ     00000003H

CM_SERVICE_NETWORK_BOOT_LOAD                    equ     00000001H
CM_SERVICE_VIRTUAL_DISK_BOOT_LOAD               equ     00000002H
CM_SERVICE_USB_DISK_BOOT_LOAD                   equ     00000004H
CM_SERVICE_SD_DISK_BOOT_LOAD                    equ     00000008H
CM_SERVICE_USB3_DISK_BOOT_LOAD                  equ     00000010H
CM_SERVICE_MEASURED_BOOT_LOAD                   equ     00000020H
CM_SERVICE_VERIFIER_BOOT_LOAD                   equ     00000040H
CM_SERVICE_WINPE_BOOT_LOAD                      equ     00000080H

CM_SERVICE_VALID_PROMOTION_MASKA                equ     <CM_SERVICE_NETWORK_BOOT_LOAD or CM_SERVICE_VIRTUAL_DISK_BOOT_LOAD or CM_SERVICE_USB_DISK_BOOT_LOAD or CM_SERVICE_SD_DISK_BOOT_LOAD or CM_SERVICE_USB3_DISK_BOOT_LOAD or CM_SERVICE_MEASURED_BOOT_LOAD>
CM_SERVICE_VALID_PROMOTION_MASKB                equ     <CM_SERVICE_VERIFIER_BOOT_LOAD or CM_SERVICE_WINPE_BOOT_LOAD>
CM_SERVICE_VALID_PROMOTION_MASK                 equ     <CM_SERVICE_VALID_PROMOTION_MASKA or CM_SERVICE_VALID_PROMOTION_MASKB>

TAPE_ERASE_SHORT                                equ     0
TAPE_ERASE_LONG                                 equ     1

TAPE_LOAD                                       equ     0
TAPE_UNLOAD                                     equ     1
TAPE_TENSION                                    equ     2
TAPE_LOCK                                       equ     3
TAPE_UNLOCK                                     equ     4
TAPE_FORMAT                                     equ     5

TAPE_SETMARKS                                   equ     0
TAPE_FILEMARKS                                  equ     1
TAPE_SHORT_FILEMARKS                            equ     2
TAPE_LONG_FILEMARKS                             equ     3

TAPE_ABSOLUTE_POSITION                          equ     0
TAPE_LOGICAL_POSITION                           equ     1
TAPE_PSEUDO_LOGICAL_POSITION                    equ     2

TAPE_REWIND                                     equ     0
TAPE_ABSOLUTE_BLOCK                             equ     1
TAPE_LOGICAL_BLOCK                              equ     2
TAPE_PSEUDO_LOGICAL_BLOCK                       equ     3
TAPE_SPACE_END_OF_DATA                          equ     4
TAPE_SPACE_RELATIVE_BLOCKS                      equ     5
TAPE_SPACE_FILEMARKS                            equ     6
TAPE_SPACE_SEQUENTIAL_FMKS                      equ     7
TAPE_SPACE_SETMARKS                             equ     8
TAPE_SPACE_SEQUENTIAL_SMKS                      equ     9

TAPE_DRIVE_FIXED                                equ     00000001H
TAPE_DRIVE_SELECT                               equ     00000002H
TAPE_DRIVE_INITIATOR                            equ     00000004H
TAPE_DRIVE_ERASE_SHORT                          equ     00000010H
TAPE_DRIVE_ERASE_LONG                           equ     00000020H
TAPE_DRIVE_ERASE_BOP_ONLY                       equ     00000040H
TAPE_DRIVE_ERASE_IMMEDIATE                      equ     00000080H
TAPE_DRIVE_TAPE_CAPACITY                        equ     00000100H
TAPE_DRIVE_TAPE_REMAINING                       equ     00000200H
TAPE_DRIVE_FIXED_BLOCK                          equ     00000400H
TAPE_DRIVE_VARIABLE_BLOCK                       equ     00000800H
TAPE_DRIVE_WRITE_PROTECT                        equ     00001000H
TAPE_DRIVE_EOT_WZ_SIZE                          equ     00002000H
TAPE_DRIVE_ECC                                  equ     00010000H
TAPE_DRIVE_COMPRESSION                          equ     00020000H
TAPE_DRIVE_PADDING                              equ     00040000H
TAPE_DRIVE_REPORT_SMKS                          equ     00080000H
TAPE_DRIVE_GET_ABSOLUTE_BLK                     equ     00100000H
TAPE_DRIVE_GET_LOGICAL_BLK                      equ     00200000H
TAPE_DRIVE_SET_EOT_WZ_SIZE                      equ     00400000H
TAPE_DRIVE_EJECT_MEDIA                          equ     01000000H
TAPE_DRIVE_CLEAN_REQUESTS                       equ     02000000H
TAPE_DRIVE_SET_CMP_BOP_ONLY                     equ     04000000H
TAPE_DRIVE_RESERVED_BIT                         equ     80000000H
TAPE_DRIVE_LOAD_UNLOAD                          equ     80000001H
TAPE_DRIVE_TENSION                              equ     80000002H
TAPE_DRIVE_LOCK_UNLOCK                          equ     80000004H
TAPE_DRIVE_REWIND_IMMEDIATE                     equ     80000008H
TAPE_DRIVE_SET_BLOCK_SIZE                       equ     80000010H
TAPE_DRIVE_LOAD_UNLD_IMMED                      equ     80000020H
TAPE_DRIVE_TENSION_IMMED                        equ     80000040H
TAPE_DRIVE_LOCK_UNLK_IMMED                      equ     80000080H
TAPE_DRIVE_SET_ECC                              equ     80000100H
TAPE_DRIVE_SET_COMPRESSION                      equ     80000200H
TAPE_DRIVE_SET_PADDING                          equ     80000400H
TAPE_DRIVE_SET_REPORT_SMKS                      equ     80000800H
TAPE_DRIVE_ABSOLUTE_BLK                         equ     80001000H
TAPE_DRIVE_ABS_BLK_IMMED                        equ     80002000H
TAPE_DRIVE_LOGICAL_BLK                          equ     80004000H
TAPE_DRIVE_LOG_BLK_IMMED                        equ     80008000H
TAPE_DRIVE_END_OF_DATA                          equ     80010000H
TAPE_DRIVE_RELATIVE_BLKS                        equ     80020000H
TAPE_DRIVE_FILEMARKS                            equ     80040000H
TAPE_DRIVE_SEQUENTIAL_FMKS                      equ     80080000H
TAPE_DRIVE_SETMARKS                             equ     80100000H
TAPE_DRIVE_SEQUENTIAL_SMKS                      equ     80200000H
TAPE_DRIVE_REVERSE_POSITION                     equ     80400000H
TAPE_DRIVE_SPACE_IMMEDIATE                      equ     80800000H
TAPE_DRIVE_WRITE_SETMARKS                       equ     81000000H
TAPE_DRIVE_WRITE_FILEMARKS                      equ     82000000H
TAPE_DRIVE_WRITE_SHORT_FMKS                     equ     84000000H
TAPE_DRIVE_WRITE_LONG_FMKS                      equ     88000000H
TAPE_DRIVE_WRITE_MARK_IMMED                     equ     90000000H
TAPE_DRIVE_FORMAT                               equ     0A0000000H
TAPE_DRIVE_FORMAT_IMMEDIATE                     equ     0C0000000H
TAPE_DRIVE_HIGH_FEATURES                        equ     80000000H

TAPE_FIXED_PARTITIONS                           equ     0
TAPE_SELECT_PARTITIONS                          equ     1
TAPE_INITIATOR_PARTITIONS                       equ     2

TAPE_QUERY_DRIVE_PARAMETERS                     equ     0
TAPE_QUERY_MEDIA_CAPACITY                       equ     1
TAPE_CHECK_FOR_DRIVE_PROBLEM                    equ     2
TAPE_QUERY_IO_ERROR_DATA                        equ     3
TAPE_QUERY_DEVICE_ERROR_DATA                    equ     4

CONTEXT_i386                                    equ     00010000H
CONTEXT_i486                                    equ     00010000H
CONTEXT_AMD64                                   equ     100000H
CONTEXT_IA64                                    equ     00080000H

LEGACY_SAVE_AREA_LENGTH                         equ     size XMM_SAVE_AREA32

EXCEPTION_READ_FAULT                            equ     0
EXCEPTION_WRITE_FAULT                           equ     1
EXCEPTION_EXECUTE_FAULT                         equ     8

SidTypeUser                                     equ     1
SidTypeGroup                                    equ     2
SidTypeDomain                                   equ     3
SidTypeAlias                                    equ     4
SidTypeWellKnownGroup                           equ     5
SidTypeDeletedAccount                           equ     6
SidTypeInvalid                                  equ     7
SidTypeUnknown                                  equ     8
SidTypeComputer                                 equ     9

AclRevisionInformation                          equ     1
AclSizeInformation                              equ     2

AuditEventObjectAccess                          equ     0
AuditEventDirectoryServiceAccess                equ     1

#ifndef SecurityAnonymous
    SecurityAnonymous                           equ     0
    SecurityIdentification                      equ     1
    SecurityImpersonation                       equ     2
    SecurityDelegation                          equ     3
#endif

SECURITY_MAX_IMPERSONATION_LEVEL                equ     SecurityDelegation
SECURITY_MIN_IMPERSONATION_LEVEL                equ     SecurityAnonymous
DEFAULT_IMPERSONATION_LEVEL                     equ     SecurityImpersonation

TokenPrimary                                    equ     1
TokenImpersonation                              equ     2

TokenElevationTypeDefault                       equ     1
TokenElevationTypeFull                          equ     2
TokenElevationTypeLimited                       equ     3

TokenUser                                       equ     1
TokenGroups                                     equ     2
TokenPrivileges                                 equ     3
TokenOwner                                      equ     4
TokenPrimaryGroup                               equ     5
TokenDefaultDacl                                equ     6
TokenSource                                     equ     7
TokenType                                       equ     8
TokenImpersonationLevel                         equ     9
TokenStatistics                                 equ     10
TokenRestrictedSids                             equ     11
TokenSessionId                                  equ     12
TokenGroupsAndPrivileges                        equ     13
TokenSessionReference                           equ     14
TokenSandBoxInert                               equ     15
TokenAuditPolicy                                equ     16
TokenOrigin                                     equ     17
TokenElevationType                              equ     18
TokenLinkedToken                                equ     19
TokenElevation                                  equ     20
TokenHasRestrictions                            equ     21
TokenAccessInformation                          equ     22
TokenVirtualizationAllowed                      equ     23
TokenVirtualizationEnabled                      equ     24
TokenIntegrityLevel                             equ     25
TokenUIAccess                                   equ     26
TokenMandatoryPolicy                            equ     27
TokenLogonSid                                   equ     28
MaxTokenInfoClass                               equ     29

MandatoryLevelUntrusted                         equ     0
MandatoryLevelLow                               equ     1
MandatoryLevelMedium                            equ     2
MandatoryLevelHigh                              equ     3
MandatoryLevelSystem                            equ     4
MandatoryLevelSecureProcess                     equ     5
MandatoryLevelCount                             equ     6

JobObjectBasicAccountingInformation             equ     1
JobObjectBasicLimitInformation                  equ     2
JobObjectBasicProcessIdList                     equ     3
JobObjectBasicUIRestrictions                    equ     4
JobObjectSecurityLimitInformation               equ     5
JobObjectEndOfJobTimeInformation                equ     6
JobObjectAssociateCompletionPortInformation     equ     7
JobObjectBasicAndIoAccountingInformation        equ     8
JobObjectExtendedLimitInformation               equ     9
JobObjectJobSetInformation                      equ     10
MaxJobObjectInfoClass                           equ     11

RelationProcessorCore                           equ     0
RelationNumaNode                                equ     1
RelationCache                                   equ     2
RelationProcessorPackage                        equ     3

CacheUnified                                    equ     0
CacheInstruction                                equ     1
CacheData                                       equ     2
CacheTrace                                      equ     3

LTP_PC_SMT                                      equ     01H
CACHE_FULLY_ASSOCIATIVE                         equ     0FFH

FLUSH_FLAGS_FILE_DATA_ONLY                      equ     00000001H

LT_DONT_CARE                                    equ     0
LT_LOWEST_LATENCY                               equ     1

DIAGNOSTIC_REASON_VERSION                       equ     0

DIAGNOSTIC_REASON_SIMPLE_STRING                 equ     00000001H
DIAGNOSTIC_REASON_DETAILED_STRING               equ     00000002H
DIAGNOSTIC_REASON_NOT_SPECIFIED                 equ     80000000H
DIAGNOSTIC_REASON_INVALID_FLAGS                 equ     <not 80000003H>

POWER_REQUEST_CONTEXT_VERSION                   equ     0

POWER_REQUEST_CONTEXT_SIMPLE_STRING             equ     00000001H
POWER_REQUEST_CONTEXT_DETAILED_STRING           equ     00000002H

PowerRequestDisplayRequired                     equ     0
PowerRequestSystemRequired                      equ     1
PowerRequestAwayModeRequired                    equ     2
PowerRequestMaximum                             equ     3

PowerSystemUnspecified                          equ     0
PowerSystemWorking                              equ     1
PowerSystemSleeping1                            equ     2
PowerSystemSleeping2                            equ     3
PowerSystemSleeping3                            equ     4
PowerSystemHibernate                            equ     5
PowerSystemShutdown                             equ     6
PowerSystemMaximum                              equ     7

PowerActionNone                                 equ     0
PowerActionReserved                             equ     1
PowerActionSleep                                equ     2
PowerActionHibernate                            equ     3
PowerActionShutdown                             equ     4
PowerActionShutdownReset                        equ     5
PowerActionShutdownOff                          equ     6
PowerActionWarmEject                            equ     7

PowerDeviceUnspecified                          equ     0
PowerDeviceD0                                   equ     1
PowerDeviceD1                                   equ     2
PowerDeviceD2                                   equ     3
PowerDeviceD3                                   equ     4
PowerDeviceMaximum                              equ     5

PDCAP_D0_SUPPORTED                              equ     00000001H
PDCAP_D1_SUPPORTED                              equ     00000002H
PDCAP_D2_SUPPORTED                              equ     00000004H
PDCAP_D3_SUPPORTED                              equ     00000008H
PDCAP_WAKE_FROM_D0_SUPPORTED                    equ     00000010H
PDCAP_WAKE_FROM_D1_SUPPORTED                    equ     00000020H
PDCAP_WAKE_FROM_D2_SUPPORTED                    equ     00000040H
PDCAP_WAKE_FROM_D3_SUPPORTED                    equ     00000080H
PDCAP_WARM_EJECT_SUPPORTED                      equ     00000100H

SystemPowerPolicyAc                             equ     0
SystemPowerPolicyDc                             equ     1
VerifySystemPolicyAc                            equ     2
VerifySystemPolicyDc                            equ     3
SystemPowerCapabilities                         equ     4
SystemBatteryState                              equ     5
SystemPowerStateHandler                         equ     6
ProcessorStateHandler                           equ     7
SystemPowerPolicyCurrent                        equ     8
AdministratorPowerPolicy                        equ     9
SystemReserveHiberFile                          equ     10
ProcessorInformation                            equ     11
SystemPowerInformation                          equ     12
ProcessorStateHandler2                          equ     13
LastWakeTime                                    equ     14
LastSleepTime                                   equ     15
SystemExecutionState                            equ     16
SystemPowerStateNotifyHandler                   equ     17
ProcessorPowerPolicyAc                          equ     18
ProcessorPowerPolicyDc                          equ     19
VerifyProcessorPowerPolicyAc                    equ     20
VerifyProcessorPowerPolicyDc                    equ     21
ProcessorPowerPolicyCurrent                     equ     22
SystemPowerStateLogging                         equ     23
SystemPowerLoggingEntry                         equ     24
SetPowerSettingValue                            equ     25
NotifyUserPowerSetting                          equ     26
PowerInformationLevelUnused0                    equ     27
PowerInformationLevelUnused1                    equ     28
SystemVideoState                                equ     29
TraceApplicationPowerMessage                    equ     30
TraceApplicationPowerMessageEnd                 equ     31
ProcessorPerfStates                             equ     32
ProcessorIdleStates                             equ     33
ProcessorCap                                    equ     34
SystemWakeSource                                equ     35
SystemHiberFileInformation                      equ     36
TraceServicePowerMessage                        equ     37
ProcessorLoad                                   equ     38
PowerShutdownNotification                       equ     39
MonitorCapabilities                             equ     40
SessionPowerInit                                equ     41
SessionDisplayState                             equ     42
PowerRequestCreate                              equ     43
PowerRequestAction                              equ     44
GetPowerRequestList                             equ     45
ProcessorInformationEx                          equ     46
NotifyUserModeLegacyPowerEvent                  equ     47
GroupPark                                       equ     48
ProcessorIdleDomains                            equ     49
WakeTimerList                                   equ     50
SystemHiberFileSize                             equ     51
PowerInformationLevelMaximum                    equ     52

PO_TRANSITION_VETO_TYPE_WINDOW                  equ     00000001H
PO_TRANSITION_VETO_TYPE_SERVICE                 equ     00000002H
PO_TRANSITION_VETO_TYPE_DRIVER                  equ     00000004H

PO_TRANSITION_VETO_TYPE_ALL                     equ     <PO_TRANSITION_VETO_TYPE_WINDOW or PO_TRANSITION_VETO_TYPE_SERVICE>

PoAc                                            equ     0
PoDc                                            equ     1
PoHot                                           equ     2
PoConditionMaximum                              equ     3

POWER_SETTING_VALUE_VERSION                     equ     01H

PlatformRoleUnspecified                         equ     0
PlatformRoleDesktop                             equ     1
PlatformRoleMobile                              equ     2
PlatformRoleWorkstation                         equ     3
PlatformRoleEnterpriseServer                    equ     4
PlatformRoleSOHOServer                          equ     5
PlatformRoleAppliancePC                         equ     6
PlatformRolePerformanceServer                   equ     7
PlatformRoleSlate                               equ     8
PlatformRoleMaximum                             equ     9

POWER_PLATFORM_ROLE_V1                          equ     1
POWER_PLATFORM_ROLE_V1_MAX                      equ     8

POWER_PLATFORM_ROLE_V2                          equ     2
POWER_PLATFORM_ROLE_V2_MAX                      equ     9

#if NTDDI_VERSION >= NTDDI_WIN8
    POWER_PLATFORM_ROLE_VERSION                 equ     POWER_PLATFORM_ROLE_V2
    POWER_PLATFORM_ROLE_VERSION_MAX             equ     POWER_PLATFORM_ROLE_V2_MAX
#else
    POWER_PLATFORM_ROLE_VERSION                 equ     POWER_PLATFORM_ROLE_V1
    POWER_PLATFORM_ROLE_VERSION_MAX             equ     POWER_PLATFORM_ROLE_V1_MAX
#endif

DeviceWakeSourceType                            equ     0
FixedWakeSourceType                             equ     1

FixedWakeSourcePowerButton                      equ     0
FixedWakeSourceSleepButton                      equ     1
FixedWakeSourceRtc                              equ     2

ACPI_PPM_SOFTWARE_ALL                           equ     0FCH
ACPI_PPM_SOFTWARE_ANY                           equ     0FDH
ACPI_PPM_HARDWARE_ALL                           equ     0FEH
MS_PPM_SOFTWARE_ALL                             equ     01H

POWER_ACTION_QUERY_ALLOWED                      equ     00000001H
POWER_ACTION_UI_ALLOWED                         equ     00000002H
POWER_ACTION_OVERRIDE_APPS                      equ     00000004H
POWER_ACTION_PSEUDO_TRANSITION                  equ     08000000H
POWER_ACTION_LIGHTEST_FIRST                     equ     10000000H
POWER_ACTION_LOCK_CONSOLE                       equ     20000000H
POWER_ACTION_DISABLE_WAKES                      equ     40000000H
POWER_ACTION_CRITICAL                           equ     80000000H

POWER_LEVEL_USER_NOTIFY_TEXT                    equ     00000001H
POWER_LEVEL_USER_NOTIFY_SOUND                   equ     00000002H
POWER_LEVEL_USER_NOTIFY_EXEC                    equ     00000004H
POWER_USER_NOTIFY_BUTTON                        equ     00000008H
POWER_USER_NOTIFY_SHUTDOWN                      equ     00000010H
POWER_FORCE_TRIGGER_RESET                       equ     80000000H

BATTERY_DISCHARGE_FLAGS_EVENTCODE_MASK          equ     00000007H
BATTERY_DISCHARGE_FLAGS_ENABLE                  equ     80000000H

DISCHARGE_POLICY_CRITICAL                       equ     0
DISCHARGE_POLICY_LOW                            equ     1

PROCESSOR_IDLESTATE_POLICY_COUNT                equ     03H

PO_THROTTLE_NONE                                equ     0
PO_THROTTLE_CONSTANT                            equ     1
PO_THROTTLE_DEGRADE                             equ     2
PO_THROTTLE_ADAPTIVE                            equ     3
PO_THROTTLE_MAXIMUM                             equ     4

PERFSTATE_POLICY_CHANGE_IDEAL                   equ     00H
PERFSTATE_POLICY_CHANGE_SINGLE                  equ     01H
PERFSTATE_POLICY_CHANGE_ROCKET                  equ     02H
PERFSTATE_POLICY_CHANGE_MAX                     equ     PERFSTATE_POLICY_CHANGE_ROCKET

ACTIVATION_CONTEXT_SECTION_ASSEMBLY_INFORMATION equ     1
ACTIVATION_CONTEXT_SECTION_DLL_REDIRECTION      equ     2
ACTIVATION_CONTEXT_SECTION_WINDOW_CLASS_REDIRECTION equ 3
ACTIVATION_CONTEXT_SECTION_COM_SERVER_REDIRECTION equ   4
ACTIVATION_CONTEXT_SECTION_COM_INTERFACE_REDIRECTION equ 5
ACTIVATION_CONTEXT_SECTION_COM_TYPE_LIBRARY_REDIRECTION equ 6
ACTIVATION_CONTEXT_SECTION_COM_PROGID_REDIRECTION equ   7
ACTIVATION_CONTEXT_SECTION_GLOBAL_OBJECT_RENAME_TABLE equ 8
ACTIVATION_CONTEXT_SECTION_CLR_SURROGATES       equ     9
ACTIVATION_CONTEXT_SECTION_APPLICATION_SETTINGS equ     10
ACTIVATION_CONTEXT_SECTION_COMPATIBILITY_INFO   equ     11

IMAGE_SCN_TYPE_REG                              equ     00000000H
IMAGE_SCN_TYPE_DSECT                            equ     00000001H
IMAGE_SCN_TYPE_NOLOAD                           equ     00000002H
IMAGE_SCN_TYPE_GROUP                            equ     00000004H
IMAGE_SCN_TYPE_NO_PAD                           equ     00000008H
IMAGE_SCN_TYPE_COPY                             equ     00000010H

IMAGE_SCN_CNT_CODE                              equ     00000020H
IMAGE_SCN_CNT_INITIALIZED_DATA                  equ     00000040H
IMAGE_SCN_CNT_UNINITIALIZED_DATA                equ     00000080H

IMAGE_SCN_LNK_OTHER                             equ     00000100H
IMAGE_SCN_LNK_INFO                              equ     00000200H
IMAGE_SCN_TYPE_OVER                             equ     00000400H
IMAGE_SCN_LNK_REMOVE                            equ     00000800H
IMAGE_SCN_LNK_COMDAT                            equ     00001000H

IMAGE_SCN_NO_DEFER_SPEC_EXC                     equ     00004000H
IMAGE_SCN_GPREL                                 equ     00008000H
IMAGE_SCN_MEM_FARDATA                           equ     00008000H
IMAGE_SCN_MEM_PURGEABLE                         equ     00020000H
IMAGE_SCN_MEM_16BIT                             equ     00020000H
IMAGE_SCN_MEM_LOCKED                            equ     00040000H
IMAGE_SCN_MEM_PRELOAD                           equ     00080000H

IMAGE_SCN_ALIGN_1BYTES                          equ     00100000H
IMAGE_SCN_ALIGN_2BYTES                          equ     00200000H
IMAGE_SCN_ALIGN_4BYTES                          equ     00300000H
IMAGE_SCN_ALIGN_8BYTES                          equ     00400000H
IMAGE_SCN_ALIGN_16BYTES                         equ     00500000H
IMAGE_SCN_ALIGN_32BYTES                         equ     00600000H
IMAGE_SCN_ALIGN_64BYTES                         equ     00700000H
IMAGE_SCN_ALIGN_128BYTES                        equ     00800000H
IMAGE_SCN_ALIGN_256BYTES                        equ     00900000H
IMAGE_SCN_ALIGN_512BYTES                        equ     00A00000H
IMAGE_SCN_ALIGN_1024BYTES                       equ     00B00000H
IMAGE_SCN_ALIGN_2048BYTES                       equ     00C00000H
IMAGE_SCN_ALIGN_4096BYTES                       equ     00D00000H
IMAGE_SCN_ALIGN_8192BYTES                       equ     00E00000H
IMAGE_SCN_ALIGN_MASK                            equ     00F00000H

IMAGE_SCN_LNK_NRELOC_OVFL                       equ     01000000H
IMAGE_SCN_MEM_DISCARDABLE                       equ     02000000H
IMAGE_SCN_MEM_NOT_CACHED                        equ     04000000H
IMAGE_SCN_MEM_NOT_PAGED                         equ     08000000H
IMAGE_SCN_MEM_SHARED                            equ     10000000H
IMAGE_SCN_MEM_EXECUTE                           equ     20000000H
IMAGE_SCN_MEM_READ                              equ     40000000H
IMAGE_SCN_MEM_WRITE                             equ     80000000H

IMAGE_SCN_SCALE_INDEX                           equ     00000001H

IMAGE_AUX_SYMBOL_TYPE_TOKEN_DEF                 equ     1

IMAGE_SIZEOF_ARCHIVE_MEMBER_HDR                 equ     60

IMPORT_OBJECT_CODE                              equ     0
IMPORT_OBJECT_DATA                              equ     1
IMPORT_OBJECT_CONST                             equ     2

IMPORT_OBJECT_ORDINAL                           equ     0
IMPORT_OBJECT_NAME                              equ     1
IMPORT_OBJECT_NAME_NO_PREFIX                    equ     2
IMPORT_OBJECT_NAME_UNDECORATE                   equ     3

RTL_CRITICAL_SECTION_FLAG_NO_DEBUG_INFO         equ     001000000H
RTL_CRITICAL_SECTION_FLAG_DYNAMIC_SPIN          equ     002000000H
RTL_CRITICAL_SECTION_FLAG_STATIC_INIT           equ     004000000H
RTL_CRITICAL_SECTION_FLAG_RESOURCE_TYPE         equ     008000000H
RTL_CRITICAL_SECTION_FLAG_FORCE_DEBUG_INFO      equ     010000000H
RTL_CRITICAL_SECTION_ALL_FLAG_BITS              equ     0FF000000H
RTL_CRITICAL_SECTION_FLAG_RESERVED              equ     <RTL_CRITICAL_SECTION_ALL_FLAG_BITS and (not (RTL_CRITICAL_SECTION_FLAG_NO_DEBUG_INFO or RTL_CRITICAL_SECTION_FLAG_DYNAMIC_SPIN or RTL_CRITICAL_SECTION_FLAG_RESOURCE_TYPE or RTL_CRITICAL_SECTION_FLAG_FORCE_DEBUG_INFO))>
RTL_CRITICAL_SECTION_DEBUG_FLAG_STATIC_INIT     equ     000000001H

RTL_SRWLOCK_INIT                                equ     0

RTL_CONDITION_VARIABLE_INIT                     equ     00H
RTL_CONDITION_VARIABLE_LOCKMODE_SHARED          equ     01H

ACTIVATION_CONTEXT_PATH_TYPE_NONE               equ     1
ACTIVATION_CONTEXT_PATH_TYPE_WIN32_FILE         equ     2
ACTIVATION_CONTEXT_PATH_TYPE_URL                equ     3
ACTIVATION_CONTEXT_PATH_TYPE_ASSEMBLYREF        equ     4

ACTCTX_RUN_LEVEL_UNSPECIFIED                    equ     0
ACTCTX_RUN_LEVEL_AS_INVOKER                     equ     1
ACTCTX_RUN_LEVEL_HIGHEST_AVAILABLE              equ     2
ACTCTX_RUN_LEVEL_REQUIRE_ADMIN                  equ     3
ACTCTX_RUN_LEVEL_NUMBERS                        equ     4

TRANSACTION_MANAGER_VOLATILE                    equ     000000001H
TRANSACTION_MANAGER_COMMIT_DEFAULT              equ     000000000H
TRANSACTION_MANAGER_COMMIT_SYSTEM_VOLUME        equ     000000002H
TRANSACTION_MANAGER_COMMIT_SYSTEM_HIVES         equ     000000004H
TRANSACTION_MANAGER_COMMIT_LOWEST               equ     000000008H
TRANSACTION_MANAGER_CORRUPT_FOR_RECOVERY        equ     000000010H
TRANSACTION_MANAGER_CORRUPT_FOR_PROGRESS        equ     000000020H
TRANSACTION_MANAGER_MAXIMUM_OPTION              equ     00000003FH

TRANSACTION_DO_NOT_PROMOTE                      equ     000000001H
TRANSACTION_MAXIMUM_OPTION                      equ     000000001H

TRANSACTION_NOTIFY_MASK                         equ     03FFFFFFFH
TRANSACTION_NOTIFY_PREPREPARE                   equ     000000001H
TRANSACTION_NOTIFY_PREPARE                      equ     000000002H
TRANSACTION_NOTIFY_COMMIT                       equ     000000004H
TRANSACTION_NOTIFY_ROLLBACK                     equ     000000008H
TRANSACTION_NOTIFY_PREPREPARE_COMPLETE          equ     000000010H
TRANSACTION_NOTIFY_PREPARE_COMPLETE             equ     000000020H
TRANSACTION_NOTIFY_COMMIT_COMPLETE              equ     000000040H
TRANSACTION_NOTIFY_ROLLBACK_COMPLETE            equ     000000080H
TRANSACTION_NOTIFY_RECOVER                      equ     000000100H
TRANSACTION_NOTIFY_SINGLE_PHASE_COMMIT          equ     000000200H
TRANSACTION_NOTIFY_DELEGATE_COMMIT              equ     000000400H
TRANSACTION_NOTIFY_RECOVER_QUERY                equ     000000800H
TRANSACTION_NOTIFY_ENLIST_PREPREPARE            equ     000001000H
TRANSACTION_NOTIFY_LAST_RECOVER                 equ     000002000H
TRANSACTION_NOTIFY_INDOUBT                      equ     000004000H
TRANSACTION_NOTIFY_PROPAGATE_PULL               equ     000008000H
TRANSACTION_NOTIFY_PROPAGATE_PUSH               equ     000010000H
TRANSACTION_NOTIFY_MARSHAL                      equ     000020000H
TRANSACTION_NOTIFY_ENLIST_MASK                  equ     000040000H
TRANSACTION_NOTIFY_RM_DISCONNECTED              equ     001000000H
TRANSACTION_NOTIFY_TM_ONLINE                    equ     002000000H
TRANSACTION_NOTIFY_COMMIT_REQUEST               equ     004000000H
TRANSACTION_NOTIFY_PROMOTE                      equ     008000000H
TRANSACTION_NOTIFY_PROMOTE_NEW                  equ     010000000H
TRANSACTION_NOTIFY_REQUEST_OUTCOME              equ     020000000H
TRANSACTION_NOTIFY_COMMIT_FINALIZE              equ     040000000H

TRANSACTIONMANAGER_QUERY_INFORMATION            equ     00001H
TRANSACTIONMANAGER_SET_INFORMATION              equ     00002H
TRANSACTIONMANAGER_RECOVER                      equ     00004H
TRANSACTIONMANAGER_RENAME                       equ     00008H
TRANSACTIONMANAGER_CREATE_RM                    equ     00010H
TRANSACTIONMANAGER_BIND_TRANSACTION             equ     00020H
TRANSACTIONMANAGER_GENERIC_READ                 equ     <STANDARD_RIGHTS_READ or TRANSACTIONMANAGER_QUERY_INFORMATION>
TRANSACTIONMANAGER_GENERIC_WRITE                equ     <STANDARD_RIGHTS_WRITE or TRANSACTIONMANAGER_SET_INFORMATION or TRANSACTIONMANAGER_RECOVER or TRANSACTIONMANAGER_RENAME or TRANSACTIONMANAGER_CREATE_RM>
TRANSACTIONMANAGER_GENERIC_EXECUTE              equ     STANDARD_RIGHTS_EXECUTE
TRANSACTIONMANAGER_ALL_ACCESS                   equ     <STANDARD_RIGHTS_REQUIRED or TRANSACTIONMANAGER_GENERIC_READ or TRANSACTIONMANAGER_GENERIC_WRITE or TRANSACTIONMANAGER_GENERIC_EXECUTE or TRANSACTIONMANAGER_BIND_TRANSACTION>

TRANSACTION_QUERY_INFORMATION                   equ     00001H
TRANSACTION_SET_INFORMATION                     equ     00002H
TRANSACTION_ENLIST                              equ     00004H
TRANSACTION_COMMIT                              equ     00008H
TRANSACTION_ROLLBACK                            equ     00010H
TRANSACTION_PROPAGATE                           equ     00020H
TRANSACTION_RIGHT_RESERVED1                     equ     00040H

TRANSACTION_GENERIC_READ                        equ     <STANDARD_RIGHTS_READ or TRANSACTION_QUERY_INFORMATION or SYNCHRONIZE>
TRANSACTION_GENERIC_WRITE                       equ     <STANDARD_RIGHTS_WRITE or TRANSACTION_SET_INFORMATION or TRANSACTION_COMMIT or TRANSACTION_ENLIST or TRANSACTION_ROLLBACK or TRANSACTION_PROPAGATE or SYNCHRONIZE>
TRANSACTION_GENERIC_EXECUTE                     equ     <STANDARD_RIGHTS_EXECUTE or TRANSACTION_COMMIT or TRANSACTION_ROLLBACK or SYNCHRONIZE>
TRANSACTION_ALL_ACCESS                          equ     <STANDARD_RIGHTS_REQUIRED or TRANSACTION_GENERIC_READ or TRANSACTION_GENERIC_WRITE or TRANSACTION_GENERIC_EXECUTE>
TRANSACTION_RESOURCE_MANAGER_RIGHTS             equ     <TRANSACTION_GENERIC_READ or STANDARD_RIGHTS_WRITE or TRANSACTION_SET_INFORMATION or TRANSACTION_ENLIST or TRANSACTION_ROLLBACK or TRANSACTION_PROPAGATE or SYNCHRONIZE>

RESOURCEMANAGER_QUERY_INFORMATION               equ     00001H
RESOURCEMANAGER_SET_INFORMATION                 equ     00002H
RESOURCEMANAGER_RECOVER                         equ     00004H
RESOURCEMANAGER_ENLIST                          equ     00008H
RESOURCEMANAGER_GET_NOTIFICATION                equ     00010H
RESOURCEMANAGER_REGISTER_PROTOCOL               equ     00020H
RESOURCEMANAGER_COMPLETE_PROPAGATION            equ     00040H

RESOURCEMANAGER_GENERIC_READ                    equ     <STANDARD_RIGHTS_READ or RESOURCEMANAGER_QUERY_INFORMATION or SYNCHRONIZE>
RESOURCEMANAGER_GENERIC_WRITEA                  equ     <STANDARD_RIGHTS_WRITE or RESOURCEMANAGER_SET_INFORMATION or RESOURCEMANAGER_RECOVER or RESOURCEMANAGER_ENLIST or RESOURCEMANAGER_GET_NOTIFICATION or RESOURCEMANAGER_REGISTER_PROTOCOL>
RESOURCEMANAGER_GENERIC_WRITEB                  equ     <RESOURCEMANAGER_COMPLETE_PROPAGATION or SYNCHRONIZE>
RESOURCEMANAGER_GENERIC_WRITE                   equ     <RESOURCEMANAGER_GENERIC_WRITEA or RESOURCEMANAGER_GENERIC_WRITEB>
RESOURCEMANAGER_GENERIC_EXECUTE                 equ     <STANDARD_RIGHTS_EXECUTE or RESOURCEMANAGER_RECOVER or RESOURCEMANAGER_ENLIST or RESOURCEMANAGER_GET_NOTIFICATION or RESOURCEMANAGER_COMPLETE_PROPAGATION or SYNCHRONIZE>
RESOURCEMANAGER_ALL_ACCESS                      equ     <STANDARD_RIGHTS_REQUIRED or RESOURCEMANAGER_GENERIC_READ or RESOURCEMANAGER_GENERIC_WRITE or RESOURCEMANAGER_GENERIC_EXECUTE>

RESOURCE_MANAGER_VOLATILE                       equ     000000001H
RESOURCE_MANAGER_COMMUNICATION                  equ     000000002H
RESOURCE_MANAGER_MAXIMUM_OPTION                 equ     000000003H

ENLISTMENT_QUERY_INFORMATION                    equ     00001H
ENLISTMENT_SET_INFORMATION                      equ     00002H
ENLISTMENT_RECOVER                              equ     00004H
ENLISTMENT_SUBORDINATE_RIGHTS                   equ     00008H
ENLISTMENT_SUPERIOR_RIGHTS                      equ     00010H
ENLISTMENT_GENERIC_READ                         equ     <STANDARD_RIGHTS_READ or ENLISTMENT_QUERY_INFORMATION>
ENLISTMENT_GENERIC_WRITE                        equ     <STANDARD_RIGHTS_WRITE or ENLISTMENT_SET_INFORMATION or ENLISTMENT_RECOVER or ENLISTMENT_SUBORDINATE_RIGHTS or ENLISTMENT_SUPERIOR_RIGHTS>
ENLISTMENT_GENERIC_EXECUTE                      equ     <STANDARD_RIGHTS_EXECUTE or ENLISTMENT_RECOVER or ENLISTMENT_SUBORDINATE_RIGHTS or ENLISTMENT_SUPERIOR_RIGHTS>
ENLISTMENT_ALL_ACCESS                           equ     <STANDARD_RIGHTS_REQUIRED or ENLISTMENT_GENERIC_READ or ENLISTMENT_GENERIC_WRITE or ENLISTMENT_GENERIC_EXECUTE>

CRM_PROTOCOL_EXPLICIT_MARSHAL_ONLY              equ     000000001H
CRM_PROTOCOL_DYNAMIC_MARSHAL_INFO               equ     000000002H
CRM_PROTOCOL_MAXIMUM_OPTION                     equ     000000003H

ENLISTMENT_SUPERIOR equ     000000001H
ENLISTMENT_MAXIMUM_OPTION                       equ     000000001H

KTM_MARSHAL_BLOB_VERSION_MAJOR                  equ     1
KTM_MARSHAL_BLOB_VERSION_MINOR                  equ     1
MAX_RESOURCEMANAGER_DESCRIPTION_LENGTH          equ     64

COMIMAGE_FLAGS_ILONLY                           equ     00000001H
COMIMAGE_FLAGS_32BITREQUIRED                    equ     00000002H
COMIMAGE_FLAGS_IL_LIBRARY                       equ     00000004H
COMIMAGE_FLAGS_STRONGNAMESIGNED                 equ     00000008H
COMIMAGE_FLAGS_NATIVE_ENTRYPOINT                equ     00000010H
COMIMAGE_FLAGS_TRACKDEBUGDATA                   equ     00010000H
COR_VERSION_MAJOR_V2                            equ     2
COR_VERSION_MAJOR                               equ     2
COR_VERSION_MINOR                               equ     5
COR_DELETED_NAME_LENGTH                         equ     8
COR_VTABLEGAP_NAME_LENGTH                       equ     8
NATIVE_TYPE_MAX_CB                              equ     1
COR_ILMETHOD_SECT_SMALL_MAX_DATASIZE            equ     0FFH
IMAGE_COR_MIH_METHODRVA                         equ     01H
IMAGE_COR_MIH_EHRVA                             equ     02H
IMAGE_COR_MIH_BASICBLOCK                        equ     08H
COR_VTABLE_32BIT                                equ     01H
COR_VTABLE_64BIT                                equ     02H
COR_VTABLE_FROM_UNMANAGED                       equ     04H
COR_VTABLE_FROM_UNMANAGED_RETAIN_APPDOMAIN      equ     08H
COR_VTABLE_CALL_MOST_DERIVED                    equ     10H
IMAGE_COR_EATJ_THUNK_SIZE                       equ     20H
MAX_CLASS_NAME                                  equ     1024
MAX_PACKAGE_NAME                                equ     1024

#if NTDDI_VERSION >= NTDDI_WIN8
    VRL_PREDEFINED_CLASS_BEGIN                  equ     <1 shl 0>
    VRL_CUSTOM_CLASS_BEGIN                      equ     <1 shl 8>
    VRL_CLASS_CONSISTENCY                       equ     <VRL_PREDEFINED_CLASS_BEGIN shl 0>
    VRL_ENABLE_KERNEL_BREAKS                    equ     <1 shl 31>

    CTMF_INCLUDE_APPCONTAINER                   equ     000000001H
    CTMF_VALID_FLAGS                            equ     CTMF_INCLUDE_APPCONTAINER
#endif

RTL_RUN_ONCE_INIT                               equ     0
RTL_RUN_ONCE_CHECK_ONLY                         equ     000000001H
RTL_RUN_ONCE_ASYNC                              equ     000000002H
RTL_RUN_ONCE_INIT_FAILED                        equ     000000004H

RTL_RUN_ONCE_CTX_RESERVED_BITS                  equ     2

IMAGE_BASE                                      equ     400000H

;======================================== Functions =======================================;
#if COFF_FORMAT == 1
    from_lib kernel32.lib
#else
    from_dll kernel32.dll
#endif

#ifdef APP_WIN64
    import _hread
    import _hwrite
    import _lclose
    import _lcreat
    import _llseek
    import _lopen
    import _lread
    import _lwrite
    import AddAtomA
    import AddAtomW
    import AllocConsole
    import AreFileApisANSI
    import BackupRead
    import BackupSeek
    import BackupWrite
    import Beep
    import BeginUpdateResourceA
    import BeginUpdateResourceW
    import BuildCommDCBA
    import BuildCommDCBAndTimeoutsA
    import BuildCommDCBAndTimeoutsW
    import BuildCommDCBW
    import CallNamedPipeA
    import CallNamedPipeW
    import ClearCommBreak
    import ClearCommError
    import CloseHandle
    import CloseProfileUserMapping
    import CommConfigDialogA
    import CommConfigDialogW
    import CompareFileTime
    import CompareStringA
    import CompareStringW
    import ConnectNamedPipe
    import ContinueDebugEvent
    import ConvertDefaultLocale
    import CopyFileA
    import CopyFileW
    import CreateConsoleScreenBuffer
    import CreateDirectoryA
    import CreateDirectoryExA
    import CreateDirectoryExW
    import CreateDirectoryW
    import CreateEventA
    import CreateEventW
    import CreateFileA
    import CreateFileMappingA
    import CreateFileMappingW
    import CreateFileW
    import CreateIoCompletionPort
    import CreateMailslotA
    import CreateMailslotW
    import CreateMutexA
    import CreateMutexW
    import CreateNamedPipeA
    import CreateNamedPipeW
    import CreatePipe
    import CreateProcessA
    import CreateProcessW
    import CreateRemoteThread
    import CreateSemaphoreA
    import CreateSemaphoreW
    import CreateTapePartition
    import CreateThread
    import CreateToolhelp32Snapshot
    import DebugActiveProcess
    import DebugBreak
    import DefineDosDeviceA
    import DefineDosDeviceW
    import DeleteAtom
    import DeleteCriticalSection
    import DeleteFileA
    import DeleteFileW
    import DeviceIoControl
    import DisableThreadLibraryCalls
    import DisconnectNamedPipe
    import DosDateTimeToFileTime
    import DuplicateHandle
    import EndUpdateResourceA
    import EndUpdateResourceW
    import EnterCriticalSection
    import EnumCalendarInfoA
    import EnumCalendarInfoW
    import EnumDateFormatsA
    import EnumDateFormatsW
    import EnumResourceLanguagesA
    import EnumResourceLanguagesW
    import EnumResourceNamesA
    import EnumResourceNamesW
    import EnumResourceTypesA
    import EnumResourceTypesW
    import EnumSystemCodePagesA
    import EnumSystemCodePagesW
    import EnumSystemLocalesA
    import EnumSystemLocalesW
    import EnumTimeFormatsA
    import EnumTimeFormatsW
    import EraseTape
    import EscapeCommFunction
    import ExitProcess
    import ExitThread
    import ExpandEnvironmentStringsA
    import ExpandEnvironmentStringsW
    import FatalAppExitA
    import FatalAppExitW
    import FatalExit
    import FileTimeToDosDateTime
    import FileTimeToLocalFileTime
    import FileTimeToSystemTime
    import FillConsoleOutputAttribute
    import FillConsoleOutputCharacterA
    import FillConsoleOutputCharacterW
    import FindAtomA
    import FindAtomW
    import FindClose
    import FindCloseChangeNotification
    import FindFirstChangeNotificationA
    import FindFirstChangeNotificationW
    import FindFirstFileA
    import FindFirstFileW
    import FindNextChangeNotification
    import FindNextFileA
    import FindNextFileW
    import FindResourceA
    import FindResourceExA
    import FindResourceExW
    import FindResourceW
    import FlushConsoleInputBuffer
    import FlushFileBuffers
    import FlushInstructionCache
    import FlushViewOfFile
    import FoldStringA
    import FoldStringW
    import FormatMessageA
    import FormatMessageW
    import FreeConsole
    import FreeEnvironmentStringsA
    import FreeEnvironmentStringsW
    import FreeLibrary
    import FreeLibraryAndExitThread
    import FreeResource
    import GenerateConsoleCtrlEvent
    import GetACP
    import GetAtomNameA
    import GetAtomNameW
    import GetBinaryTypeA
    import GetBinaryTypeW
    import GetCommandLineA
    import GetCommandLineW
    import GetCommConfig
    import GetCommMask
    import GetCommModemStatus
    import GetCommProperties
    import GetCommState
    import GetCommTimeouts
    import GetCompressedFileSizeA
    import GetCompressedFileSizeW
    import GetComputerNameA
    import GetComputerNameW
    import GetConsoleCP
    import GetConsoleCursorInfo
    import GetConsoleMode
    import GetConsoleOutputCP
    import GetConsoleScreenBufferInfo
    import GetConsoleTitleA
    import GetConsoleTitleW
    import GetCPInfo
    import GetCurrencyFormatA
    import GetCurrencyFormatW
    import GetCurrentDirectoryA
    import GetCurrentDirectoryW
    import GetCurrentProcess
    import GetCurrentProcessId
    import GetCurrentThread
    import GetCurrentThreadId
    import GetDateFormatA
    import GetDateFormatW
    import GetDefaultCommConfigA
    import GetDefaultCommConfigW
    import GetDiskFreeSpaceA
    import GetDiskFreeSpaceExA
    import GetDiskFreeSpaceExW
    import GetDiskFreeSpaceW
    import GetDriveTypeA
    import GetDriveTypeW
    import GetEnvironmentStringsA
    import GetEnvironmentStringsW
    import GetEnvironmentVariableA
    import GetEnvironmentVariableW
    #if NTDDI_VERSION == NTDDI_WIN95
        import GetErrorMode
    #endif
    #if NTDDI_VERSION == NTDDI_WIN98_ME
        import GetErrorMode
    #endif
    #if NTDDI_VERSION >= NTDDI_VISTA
        import GetErrorMode
    #endif
    import GetExitCodeProcess
    import GetExitCodeThread
    import GetFileAttributesA
    import GetFileAttributesW
    import GetFileInformationByHandle
    import GetFileSize
    import GetFileTime
    import GetFileType
    import GetFullPathNameA
    import GetFullPathNameW
    #if NTDDI_VERSION == NTDDI_WIN95
        import GetHandleContext
        import SetHandleContext
    #endif
    #if NTDDI_VERSION == NTDDI_WIN98_ME
        import GetHandleContext
        import SetHandleContext
    #endif
    #if NTDDI_VERSION == NTDDI_WINXP
        import GetHandleContext
        import SetHandleContext
    #endif
    #if NTDDI_VERSION == NTDDI_VISTA
        import GetHandleContext
        import SetHandleContext
    #endif
    import GetHandleInformation
    import GetLargestConsoleWindowSize
    import GetLastError
    import GetLocaleInfoA
    import GetLocaleInfoW
    import GetLocalTime
    import GetLogicalDrives
    import GetLogicalDriveStringsA
    import GetLogicalDriveStringsW
    import GetMailslotInfo
    import GetModuleFileNameA
    import GetModuleFileNameW
    import GetModuleHandleA
    import GetModuleHandleW
    import GetNamedPipeHandleStateA
    import GetNamedPipeHandleStateW
    import GetNamedPipeInfo
    import GetNumberFormatA
    import GetNumberFormatW
    import GetNumberOfConsoleInputEvents
    import GetNumberOfConsoleMouseButtons
    import GetOEMCP
    import GetOverlappedResult
    import GetPriorityClass
    import GetPrivateProfileIntA
    import GetPrivateProfileIntW
    import GetPrivateProfileSectionA
    import GetPrivateProfileSectionNamesA
    import GetPrivateProfileSectionNamesW
    import GetPrivateProfileSectionW
    import GetPrivateProfileStringA
    import GetPrivateProfileStringW
    import GetPrivateProfileStructA
    import GetPrivateProfileStructW
    import GetProcAddress
    import GetProcessAffinityMask
    import GetProcessHeap
    import GetProcessHeaps
    import GetProcessShutdownParameters
    import GetProcessTimes
    import GetProcessVersion
    import GetProcessWorkingSetSize
    import GetProfileIntA
    import GetProfileIntW
    import GetProfileSectionA
    import GetProfileSectionW
    import GetProfileStringA
    import GetProfileStringW
    import GetQueuedCompletionStatus
    import GetShortPathNameA
    import GetShortPathNameW
    import GetStartupInfoA
    import GetStartupInfoW
    import GetStdHandle
    import GetStringTypeA
    import GetStringTypeExA
    import GetStringTypeExW
    import GetStringTypeW
    import GetSystemDefaultLangID
    import GetSystemDefaultLCID
    import GetSystemDirectoryA
    import GetSystemDirectoryW
    import GetSystemInfo
    import GetSystemPowerStatus
    import GetSystemTime
    import GetSystemTimeAdjustment
    import GetSystemTimeAsFileTime
    import GetTapeParameters
    import GetTapePosition
    import GetTapeStatus
    import GetTempFileNameA
    import GetTempFileNameW
    import GetTempPathA
    import GetTempPathW
    import GetThreadContext
    import GetThreadLocale
    import GetThreadPriority
    import GetThreadSelectorEntry
    import GetThreadTimes
    import GetTickCount
    import GetTimeFormatA
    import GetTimeFormatW
    import GetTimeZoneInformation
    import GetUserDefaultLangID
    import GetUserDefaultLCID
    import GetVersion
    import GetVersionExA
    import GetVersionExW
    import GetVolumeInformationA
    import GetVolumeInformationW
    import GetWindowsDirectoryA
    import GetWindowsDirectoryW
    import GlobalAddAtomA
    import GlobalAddAtomW
    import GlobalAlloc
    import GlobalCompact
    import GlobalDeleteAtom
    import GlobalFindAtomA
    import GlobalFindAtomW
    import GlobalFix
    import GlobalFlags
    import GlobalFree
    import GlobalGetAtomNameA
    import GlobalGetAtomNameW
    import GlobalHandle
    import GlobalLock
    import GlobalMemoryStatus
    import GlobalReAlloc
    import GlobalSize
    import GlobalUnfix
    import GlobalUnlock
    import GlobalUnWire
    import GlobalWire
    import Heap32First
    import Heap32ListFirst
    import Heap32ListNext
    import Heap32Next
    import HeapAlloc
    import HeapCompact
    import HeapCreate
    import HeapDestroy
    import HeapFree
    import HeapLock
    import HeapReAlloc
    import HeapSize
    import HeapUnlock
    import HeapValidate
    import HeapWalk
    import InitAtomTable
    import InitializeCriticalSection
    import InterlockedDecrement
    import InterlockedExchange
    import InterlockedIncrement
    import IsBadCodePtr
    import IsBadHugeReadPtr
    import IsBadHugeWritePtr
    import IsBadReadPtr
    import IsBadStringPtrA
    import IsBadStringPtrW
    import IsBadWritePtr
    import IsDBCSLeadByte
    import IsDBCSLeadByteEx
    import IsValidCodePage
    import IsValidLocale
    import LCMapStringA
    import LCMapStringW
    import LeaveCriticalSection
    import LoadLibraryA
    import LoadLibraryExA
    import LoadLibraryExW
    import LoadLibraryW
    import LoadModule
    import LoadResource
    import LocalAlloc
    import LocalCompact
    import LocalFileTimeToFileTime
    import LocalFlags
    import LocalFree
    import LocalHandle
    import LocalLock
    import LocalReAlloc
    import LocalShrink
    import LocalSize
    import LocalUnlock
    import LockFile
    import LockFileEx
    import LockResource
    import lstrcatA
    import lstrcatW
    import lstrcmpA
    import lstrcmpiA
    import lstrcmpiW
    import lstrcmpW
    import lstrcpyA
    import lstrcpynA
    import lstrcpynW
    import lstrcpyW
    import lstrlenA
    import lstrlenW
    import MapViewOfFile
    import MapViewOfFileEx
    import MoveFileA
    import MoveFileExA
    import MoveFileExW
    import MoveFileW
    import MulDiv
    import MultiByteToWideChar
    import OpenEventA
    import OpenEventW
    import OpenFile
    import OpenFileMappingA
    import OpenFileMappingW
    import OpenMutexA
    import OpenMutexW
    import OpenProcess
    import OpenProfileUserMapping
    import OpenSemaphoreA
    import OpenSemaphoreW
    import OutputDebugStringA
    import OutputDebugStringW
    import PeekConsoleInputA
    import PeekConsoleInputW
    import PeekNamedPipe
    import PostQueuedCompletionStatus
    import PrepareTape
    import PulseEvent
    import PurgeComm
    import QueryDosDeviceA
    import QueryDosDeviceW
    import QueryPerformanceCounter
    import QueryPerformanceFrequency
    import QueueUserAPC
    import RaiseException
    import ReadConsoleA
    import ReadConsoleInputA
    import ReadConsoleInputW
    import ReadConsoleOutputA
    import ReadConsoleOutputAttribute
    import ReadConsoleOutputCharacterA
    import ReadConsoleOutputCharacterW
    import ReadConsoleOutputW
    import ReadConsoleW
    import ReadFile
    import ReadFileEx
    import ReadProcessMemory
    import ReleaseMutex
    import ReleaseSemaphore
    import RemoveDirectoryA
    import RemoveDirectoryW
    import ResetEvent
    import ResumeThread
    import RtlFillMemory
    import RtlMoveMemory
    import RtlUnwind
    import RtlZeroMemory
    import ScrollConsoleScreenBufferA
    import ScrollConsoleScreenBufferW
    import SearchPathA
    import SearchPathW
    import SetCommBreak
    import SetCommConfig
    import SetCommMask
    import SetCommState
    import SetCommTimeouts
    import SetComputerNameA
    import SetComputerNameW
    import SetConsoleActiveScreenBuffer
    import SetConsoleCP
    import SetConsoleCtrlHandler
    import SetConsoleCursorInfo
    import SetConsoleCursorPosition
    import SetConsoleMode
    import SetConsoleOutputCP
    import SetConsoleScreenBufferSize
    import SetConsoleTextAttribute
    import SetConsoleTitleA
    import SetConsoleTitleW
    import SetConsoleWindowInfo
    import SetCurrentDirectoryA
    import SetCurrentDirectoryW
    import SetDefaultCommConfigA
    import SetDefaultCommConfigW
    import SetEndOfFile
    import SetEnvironmentVariableA
    import SetEnvironmentVariableW
    import SetErrorMode
    import SetEvent
    import SetFileApisToANSI
    import SetFileApisToOEM
    import SetFileAttributesA
    import SetFileAttributesW
    import SetFilePointer
    import SetFileTime
    import SetHandleCount
    import SetHandleInformation
    import SetLastError
    import SetLocaleInfoA
    import SetLocaleInfoW
    import SetLocalTime
    import SetMailslotInfo
    import SetNamedPipeHandleState
    import SetPriorityClass
    import SetProcessShutdownParameters
    import SetProcessWorkingSetSize
    import SetStdHandle
    import SetSystemPowerState
    import SetSystemTime
    import SetSystemTimeAdjustment
    import SetTapeParameters
    import SetTapePosition
    import SetThreadAffinityMask
    import SetThreadContext
    import SetThreadLocale
    import SetThreadPriority
    import SetTimeZoneInformation
    import SetUnhandledExceptionFilter
    import SetupComm
    import SetVolumeLabelA
    import SetVolumeLabelW
    import SizeofResource
    import Sleep
    import SleepEx
    import SuspendThread
    import SystemTimeToFileTime
    import SystemTimeToTzSpecificLocalTime
    import TerminateProcess
    import TerminateThread
    import Thread32First
    import Thread32Next
    import TlsAlloc
    import TlsFree
    import TlsGetValue
    import TlsSetValue
    import Toolhelp32ReadProcessMemory
    import TransactNamedPipe
    import TransmitCommChar
    import UnhandledExceptionFilter
    import UnlockFile
    import UnlockFileEx
    import UnmapViewOfFile
    import UpdateResourceA
    import UpdateResourceW
    import VirtualAlloc
    import VirtualFree
    import VirtualLock
    import VirtualProtect
    import VirtualProtectEx
    import VirtualQuery
    import VirtualQueryEx
    import VirtualUnlock
    import WaitCommEvent
    import WaitForDebugEvent
    import WaitForMultipleObjects
    import WaitForMultipleObjectsEx
    import WaitForSingleObject
    import WaitForSingleObjectEx
    import WaitNamedPipeA
    import WaitNamedPipeW
    import WideCharToMultiByte
    import WinExec
    import WriteConsoleA
    import WriteConsoleInputA
    import WriteConsoleInputW
    import WriteConsoleOutputA
    import WriteConsoleOutputAttribute
    import WriteConsoleOutputCharacterA
    import WriteConsoleOutputCharacterW
    import WriteConsoleOutputW
    import WriteConsoleW
    import WriteFile
    import WriteFileEx
    import WritePrivateProfileSectionA
    import WritePrivateProfileSectionW
    import WritePrivateProfileStringA
    import WritePrivateProfileStringW
    import WritePrivateProfileStructA
    import WritePrivateProfileStructW
    import WriteProcessMemory
    import WriteProfileSectionA
    import WriteProfileSectionW
    import WriteProfileStringA
    import WriteProfileStringW
    import WriteTapemark

    define GetFreeSpace GlobalMemoryStatus

    define LockSegment GlobalFix
    define UnlockSegment GlobalUnfix
    define GetCurrentTime GetTickCount
    define MoveMemory RtlMoveMemory
    define FillMemory RtlFillMemory
    define ZeroMemory RtlZeroMemory

    #if NTDDI_VERSION >= NTDDI_WIN98_ME
        import CancelDeviceWakeupRequest
        import CancelIo
        import ConvertThreadToFiber
        import CopyFileExA
        import CopyFileExW
        import CreateFiber
        import CreateWaitableTimerA
        import CreateWaitableTimerW
        import DeleteFiber
        import EnumCalendarInfoExA
        import EnumCalendarInfoExW
        import EnumDateFormatsExA
        import EnumDateFormatsExW
        import FindFirstFileExA
        import FindFirstFileExW
        import GetCalendarInfoA
        import GetCalendarInfoW
        import GetCPInfoExA
        import GetCPInfoExW
        import GetDevicePowerState
        import GetFileAttributesExA
        import GetFileAttributesExW
        #if NTDDI_VERSION != NTDDI_WINNT4
            import GetLongPathNameA
            import GetLongPathNameW
            import RequestDeviceWakeup
            import RequestWakeupLatency
            import ResetWriteWatch
            import SetCalendarInfoA
            import SetCalendarInfoW
            import SetMessageWaitingIndicator
            #ifdef APP_UNICODE
                define GetLongPathName GetLongPathNameW
                define SetCalendarInfo SetCalendarInfoW
            #else
                define GetLongPathName GetLongPathNameA
                define SetCalendarInfo SetCalendarInfoA
            #endif
        #endif
        import GetProcessPriorityBoost
        import GetThreadPriorityBoost
        import IsDebuggerPresent
        import IsProcessorFeaturePresent
        import IsSystemResumeAutomatic
        import OpenWaitableTimerA
        import OpenWaitableTimerW
        import ReadDirectoryChangesW
        import ReadFileScatter
        import SetCriticalSectionSpinCount
        import SetProcessAffinityMask
        import SetProcessPriorityBoost
        import SetThreadExecutionState
        import SetThreadIdealProcessor
        import SetThreadPriorityBoost
        import SetWaitableTimer
        import SignalObjectAndWait
        import SwitchToFiber
        import SwitchToThread
        import VirtualAllocEx
        import VirtualFreeEx
        import WriteFileGather
        #ifdef APP_UNICODE
            define CopyFileEx CopyFileExW
            define CreateWaitableTimer CreateWaitableTimerW
            define EnumCalendarInfoEx EnumCalendarInfoExW
            define EnumDateFormatsEx EnumDateFormatsExW
            define FindFirstFileEx FindFirstFileExW
            define GetCalendarInfo GetCalendarInfoW
            define GetCPInfoEx GetCPInfoExW
            define GetFileAttributesEx GetFileAttributesExW
            define OpenWaitableTimer OpenWaitableTimerW
        #else
            define CopyFileEx CopyFileExA
            define CreateWaitableTimer CreateWaitableTimerA
            define EnumCalendarInfoEx EnumCalendarInfoExA
            define EnumDateFormatsEx EnumDateFormatsExA
            define FindFirstFileEx FindFirstFileExA
            define GetCalendarInfo GetCalendarInfoA
            define GetCPInfoEx GetCPInfoExA
            define GetFileAttributesEx GetFileAttributesExA
            define OpenWaitableTimer OpenWaitableTimerA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WINNT4
        import AddConsoleAliasA
        import AddConsoleAliasW
        import ConsoleMenuControl
        import CreateTimerQueue
        import DuplicateConsoleHandle
        import ExitVDM
        import ExpungeConsoleCommandHistoryA
        import ExpungeConsoleCommandHistoryW
        import GetConsoleAliasA
        import GetConsoleAliasesA
        import GetConsoleAliasesW
        import GetConsoleAliasesLengthA
        import GetConsoleAliasesLengthW
        import GetConsoleAliasExesA
        import GetConsoleAliasExesW
        import GetConsoleAliasExesLengthA
        import GetConsoleAliasExesLengthW
        import GetConsoleAliasW
        import GetModuleHandleExA
        import GetModuleHandleExW
        import GetNextVDMCommand
        import GetNumberOfConsoleFonts
        import GetProcessIoCounters
        import GetVDMCurrentDirectories
        import InvalidateConsoleDIBits
        import OpenConsoleW
        import ReadConsoleInputExA
        import ReadConsoleInputExW
        import SetConsoleCursor
        import SetConsoleHardwareState
        import SetConsoleIcon
        import SetConsoleMaximumWindowSize
        import SetConsoleNumberOfCommandsA
        import SetConsoleNumberOfCommandsW
        import SetConsolePalette
        import SetLastConsoleEventActive
        import SetVDMCurrentDirectories
        import ShowConsoleCursor
        import VerifyVersionInfoA
        import VerifyVersionInfoW
        #ifdef APP_UNICODE
            define AddConsoleAlias AddConsoleAliasW
            define ExpungeConsoleCommandHistory ExpungeConsoleCommandHistoryW
            define GetConsoleAlias GetConsoleAliasW
            define GetConsoleAliasExes GetConsoleAliasExesW
            define GetConsoleAliasExesLength GetConsoleAliasExesLengthW
            define GetConsoleAliases GetConsoleAliasesW
            define GetConsoleAliasesLength GetConsoleAliasesLengthW
            define GetModuleHandleEx GetModuleHandleExW
            define ReadConsoleInputEx ReadConsoleInputExW
            define SetConsoleNumberOfCommands SetConsoleNumberOfCommandsW
            define VerifyVersionInfo VerifyVersionInfoW
        #else
            define AddConsoleAlias AddConsoleAliasA
            define ExpungeConsoleCommandHistory ExpungeConsoleCommandHistoryA
            define GetConsoleAlias GetConsoleAliasA
            define GetConsoleAliasExes GetConsoleAliasExesA
            define GetConsoleAliasExesLength GetConsoleAliasExesLengthA
            define GetConsoleAliases GetConsoleAliasesA
            define GetConsoleAliasesLength GetConsoleAliasesLengthA
            define GetModuleHandleEx GetModuleHandleExA
            define ReadConsoleInputEx ReadConsoleInputExA
            define SetConsoleNumberOfCommands SetConsoleNumberOfCommandsA
            define VerifyVersionInfo VerifyVersionInfoA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WIN2K
        import AllocateUserPhysicalPages
        import AssignProcessToJobObject
        import BindIoCompletionCallback
        import ChangeTimerQueueTimer
        import CreateHardLinkA
        import CreateHardLinkW
        import CreateJobObjectA
        import CreateJobObjectW
        import CreateTimerQueueTimer
        import DelayLoadFailureHook
        import DeleteTimerQueue
        import DeleteVolumeMountPointA
        import DeleteVolumeMountPointW
        import DnsHostnameToComputerNameA
        import DnsHostnameToComputerNameW
        import DosPathToSessionPathA
        import DosPathToSessionPathW
        import EnumLanguageGroupLocalesA
        import EnumLanguageGroupLocalesW
        import EnumSystemLanguageGroupsA
        import EnumSystemLanguageGroupsW
        import EnumUILanguagesA
        import EnumUILanguagesW
        import FindFirstVolumeA
        import FindFirstVolumeMountPointA
        import FindFirstVolumeMountPointW
        import FindFirstVolumeW
        import FindNextVolumeA
        import FindNextVolumeMountPointA
        import FindNextVolumeMountPointW
        import FindNextVolumeW
        import FindVolumeClose
        import FindVolumeMountPointClose
        import FreeUserPhysicalPages
        import GetComputerNameExA
        import GetComputerNameExW
        import GetConsoleNlsMode
        import GetConsoleWindow
        import GetFileSizeEx
        import GetSystemDefaultUILanguage
        import GetSystemWindowsDirectoryA
        import GetSystemWindowsDirectoryW
        import GetUserDefaultUILanguage
        import GetVolumeNameForVolumeMountPointA
        import GetVolumeNameForVolumeMountPointW
        import GetVolumePathNameA
        import GetVolumePathNameW
        import GlobalMemoryStatusEx
        import IsValidLanguageGroup
        import MapUserPhysicalPages
        import MapUserPhysicalPagesScatter
        import MoveFileWithProgressA
        import MoveFileWithProgressW
        #if NTDDI_VERSION < NTDDI_VISTA
            import OpenDataFile
        #endif
        import OpenJobObjectA
        import OpenJobObjectW
        import OpenThread
        import PrivCopyFileExW
        import ProcessIdToSessionId
        import QueryInformationJobObject
        import RegisterWaitForSingleObject
        import ReplaceFileA
        import ReplaceFileW
        import SetComputerNameExA
        import SetComputerNameExW
        import SetConsoleNlsMode
        import SetConsoleOS2OemFormat
        import SetFilePointerEx
        import SetInformationJobObject
        import SetTermsrvAppInstallMode
        import SetTimerQueueTimer
        import SetVolumeMountPointA
        import SetVolumeMountPointW
        import TerminateJobObject
        import UnregisterWait
        import VerSetConditionMask
        #ifdef APP_UNICODE
            define CreateHardLink CreateHardLinkW
            define CreateJobObject CreateJobObjectW
            define DeleteVolumeMountPoint DeleteVolumeMountPointW
            define DnsHostnameToComputerName DnsHostnameToComputerNameW
            define DosPathToSessionPath DosPathToSessionPathW
            define EnumLanguageGroupLocales EnumLanguageGroupLocalesW
            define EnumSystemLanguageGroups EnumSystemLanguageGroupsW
            define EnumUILanguages EnumUILanguagesW
            define FindActCtxSectionString FindActCtxSectionStringW
            define FindFirstVolume FindFirstVolumeW
            define FindFirstVolumeMountPoint FindFirstVolumeMountPointW
            define FindNextVolume FindNextVolumeW
            define FindNextVolumeMountPoint FindNextVolumeMountPointW
            define GetComputerNameEx GetComputerNameExW
            define GetSystemWindowsDirectory GetSystemWindowsDirectoryW
            define GetVolumeNameForVolumeMountPoint GetVolumeNameForVolumeMountPointW
            define GetVolumePathName GetVolumePathNameW
            define MoveFileWithProgress MoveFileWithProgressW
            define OpenJobObject OpenJobObjectW
            define ReplaceFile ReplaceFileW
            define SetComputerNameEx SetComputerNameExW
            define SetVolumeMountPoint SetVolumeMountPointW
        #else
            define CreateHardLink CreateHardLinkA
            define CreateJobObject CreateJobObjectA
            define DeleteVolumeMountPoint DeleteVolumeMountPointA
            define DnsHostnameToComputerName DnsHostnameToComputerNameA
            define DosPathToSessionPath DosPathToSessionPathA
            define EnumLanguageGroupLocales EnumLanguageGroupLocalesA
            define EnumSystemLanguageGroups EnumSystemLanguageGroupsA
            define EnumUILanguages EnumUILanguagesA
            define FindActCtxSectionString FindActCtxSectionStringA
            define FindFirstVolume FindFirstVolumeA
            define FindFirstVolumeMountPoint FindFirstVolumeMountPointA
            define FindNextVolume FindNextVolumeA
            define FindNextVolumeMountPoint FindNextVolumeMountPointA
            define GetComputerNameEx GetComputerNameExA
            define GetSystemWindowsDirectory GetSystemWindowsDirectoryA
            define GetVolumeNameForVolumeMountPoint GetVolumeNameForVolumeMountPointA
            define GetVolumePathName GetVolumePathNameA
            define MoveFileWithProgress MoveFileWithProgressA
            define OpenJobObject OpenJobObjectA
            define ReplaceFile ReplaceFileA
            define SetComputerNameEx SetComputerNameExA
            define SetVolumeMountPoint SetVolumeMountPointA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WINXP
        #ifndef __C_specific_handler
            import __C_specific_handler
        #endif
        #ifndef __chkstk
            import __chkstk
        #endif
        import ActivateActCtx
        import AddLocalAlternateComputerNameA
        import AddLocalAlternateComputerNameW
        import AddRefActCtx
        import AddVectoredExceptionHandler
        import AttachConsole
        import CancelWaitableTimer
        import ConvertFiberToThread
        import CreateActCtxA
        import CreateActCtxW
        import CreateFiberEx
        import CreateJobSet
        import CreateMemoryResourceNotification
        import CreateProcessInternalA
        import CreateProcessInternalW
        import DeactivateActCtx
        import DebugActiveProcessStop
        import DebugBreakProcess
        import DebugSetProcessKillOnExit
        import DeleteTimerQueueEx
        import DeleteTimerQueueTimer
        import EnumerateLocalComputerNamesA
        import EnumerateLocalComputerNamesW
        import EnumSystemGeoID
        import FindActCtxSectionGuid
        import FindActCtxSectionStringA
        import FindActCtxSectionStringW
        import FlsAlloc
        import FlsFree
        import FlsGetValue
        import FlsSetValue
        import GetConsoleDisplayMode
        import GetConsoleFontInfo
        import GetConsoleFontSize
        import GetConsoleProcessList
        import GetConsoleSelectionInfo
        import GetCurrentActCtx
        import GetCurrentConsoleFont
        import GetDllDirectoryA
        import GetDllDirectoryW
        import GetGeoInfoA
        import GetGeoInfoW
        import GetNativeSystemInfo
        import GetProcessId
        import GetSystemWow64DirectoryA
        import GetSystemWow64DirectoryW
        import GetThreadId
        import GetUserGeoID
        import GetVolumePathNamesForVolumeNameA
        import GetVolumePathNamesForVolumeNameW
        import GetWriteWatch
        import HeapQueryInformation
        import HeapSetInformation
        import InitializeCriticalSectionAndSpinCount
        import InitializeSListHead
        import InterlockedFlushSList
        import InterlockedPopEntrySList
        import InterlockedPushEntrySList
        import IsProcessInJob
        import Module32FirstW
        import Module32NextW
        import Process32FirstW
        import Process32NextW
        #ifdef APP_UNICODE
            define Module32First Module32FirstW
            define Module32Next Module32NextW
            define Process32First Process32FirstW
            define Process32Next Process32NextW
        #else
            import Module32First
            import Module32Next
            import Process32First
            import Process32Next
        #endif
        import QueryActCtxW
        import QueryDepthSList
        import QueryMemoryResourceNotification
        import QueueUserWorkItem
        import ReleaseActCtx
        import RemoveVectoredExceptionHandler
        #if NTDDI_VERSION >= NTDDI_WIN8
            import ResolveDelayLoadedAPI
            import ResolveDelayLoadsFromDll
        #endif
        import RtlCaptureContext
        import RtlCaptureStackBackTrace
        import RtlRaiseException
        import SetConsoleDisplayMode
        import SetConsoleFont
        import SetFileShortNameA
        import SetFileShortNameW
        import SetFileValidData
        import SetLocalPrimaryComputerNameA
        import SetLocalPrimaryComputerNameW
        import SetThreadUILanguage
        import SetUserGeoID
        import TryEnterCriticalSection
        import TzSpecificLocalTimeToSystemTime
        import uaw_lstrcmpiW
        import uaw_lstrcmpW
        import uaw_lstrlenW
        import uaw_wcschr
        import uaw_wcscpy
        import uaw_wcsicmp
        import uaw_wcslen
        import uaw_wcsrchr
        import UnregisterWaitEx
        import ZombifyActCtx

        define CaptureStackBackTrace RtlCaptureStackBackTrace

        #ifdef APP_WIN64
            #if NTDDI_VERSION >= NTDDI_WINXPSP3
                import EnumSystemFirmwareTables
                import GetLogicalProcessorInformation
                import GetNumaHighestNodeNumber
                import GetSystemFileCacheSize
                import GetSystemFirmwareTable
                import RemoveVectoredContinueHandler
                import SetSystemFileCacheSize
                import SetThreadStackGuarantee
                import Wow64DisableWow64FsRedirection
                import Wow64RevertWow64FsRedirection
            #else
                #if NTDDI_VERSION >= NTDDI_WS03SP1
                    import EnumSystemFirmwareTables
                    import GetLogicalProcessorInformation
                    import GetNumaHighestNodeNumber
                    import GetSystemFileCacheSize
                    import GetSystemFirmwareTable
                    import RemoveVectoredContinueHandler
                    import SetSystemFileCacheSize
                    import SetThreadStackGuarantee
                    import Wow64DisableWow64FsRedirection
                    import Wow64RevertWow64FsRedirection
                #endif
            #endif
            import RtlAddFunctionTable
            import RtlDeleteFunctionTable
            import RtlInstallFunctionTableCallback
            import RtlLookupFunctionEntry
            import RtlPcToFileHeader
            import RtlRestoreContext
            import RtlUnwindEx
            import RtlVirtualUnwind
        #else
            import RtlVirtualUnwind
        #endif

        #ifdef APP_UNICODE
            define AddLocalAlternateComputerName AddLocalAlternateComputerNameW
            define CreateActCtx CreateActCtxW
            define CreateProcessInternal CreateProcessInternalW
            define EnumerateLocalComputerNames EnumerateLocalComputerNamesW
            define GetDllDirectory GetDllDirectoryW
            define GetGeoInfo GetGeoInfoW
            define GetSystemWow64Directory GetSystemWow64DirectoryW
            define GetVolumePathNamesForVolumeName GetVolumePathNamesForVolumeNameW
            define SetFileShortName SetFileShortNameW
            define SetLocalPrimaryComputerName SetLocalPrimaryComputerNameW
        #else
            define AddLocalAlternateComputerName AddLocalAlternateComputerNameA
            define CreateActCtx CreateActCtxA
            define CreateProcessInternal CreateProcessInternalA
            define EnumerateLocalComputerNames EnumerateLocalComputerNamesA
            define GetDllDirectory GetDllDirectoryA
            define GetGeoInfo GetGeoInfoA
            define GetSystemWow64Directory GetSystemWow64DirectoryA
            define GetVolumePathNamesForVolumeName GetVolumePathNamesForVolumeNameA
            define SetFileShortName SetFileShortNameA
            define SetLocalPrimaryComputerName SetLocalPrimaryComputerNameA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WINXPSP1
        import CheckNameLegalDOS8Dot3A
        import CheckNameLegalDOS8Dot3W
        import CheckRemoteDebuggerPresent
        import ConvertThreadToFiberEx
        import GetFirmwareEnvironmentVariableA
        import GetFirmwareEnvironmentVariableW
        import GetProcessHandleCount
        import GetSystemRegistryQuota
        import GetSystemTimes
        import GetThreadIOPendingFlag
        import SetFirmwareEnvironmentVariableA
        import SetFirmwareEnvironmentVariableW
        #ifdef APP_UNICODE
            define CheckNameLegalDOS8Dot3 CheckNameLegalDOS8Dot3W
            define GetFirmwareEnvironmentVariable GetFirmwareEnvironmentVariableW
            define SetFirmwareEnvironmentVariable SetFirmwareEnvironmentVariableW
        #else
            define CheckNameLegalDOS8Dot3 CheckNameLegalDOS8Dot3A
            define GetFirmwareEnvironmentVariable GetFirmwareEnvironmentVariableA
            define SetFirmwareEnvironmentVariable SetFirmwareEnvironmentVariableA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WINXPSP2
        import GetNumaAvailableMemoryNode
        import GetNumaNodeProcessorMask
        import GetNumaProcessorNode
    #endif

    #if NTDDI_VERSION >= NTDDI_WINXPSP2
        import DecodePointer
        import DecodeSystemPointer
        import EncodePointer
        import EncodeSystemPointer
        import IsWow64Process
    #else
        #if NTDDI_VERSION >= NTDDI_WS03SP1
            import DecodePointer
            import DecodeSystemPointer
            import EncodePointer
            import EncodeSystemPointer
            import IsWow64Process
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WINXPSP3
        import GetSystemDEPPolicy
        import GetProcessDEPPolicy
        import SetProcessDEPPolicy
    #endif

    #if NTDDI_VERSION >= NTDDI_WS03
        import FindFirstStreamW
        import FindNextStreamW
        import GetLargePageMinimum
        import GetProcessIdOfThread
        import GetProcessWorkingSetSizeEx
        import ReOpenFile
        import SetDllDirectoryA
        import SetDllDirectoryW
        import SetEnvironmentStringsA
        import SetEnvironmentStringsW
        import SetProcessWorkingSetSizeEx
        import Wow64EnableWow64FsRedirection
        import WTSGetActiveConsoleSessionId
        #ifdef APP_UNICODE
            define SetDllDirectory SetDllDirectoryW
            define SetEnvironmentStrings SetEnvironmentStringsW
        #else
            define SetDllDirectory SetDllDirectoryA
            define SetEnvironmentStrings SetEnvironmentStringsA
        #endif
    #endif

    #ifndef APP_WIN64
        #if NTDDI_VERSION <= NTDDI_VISTA
            import InterlockedCompareExchange
            import InterlockedCompareExchange64
            import InterlockedExchangeAdd
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_VISTA
        import AcquireSRWLockExclusive
        import AcquireSRWLockShared
        import AddDllDirectory
        import AddSIDToBoundaryDescriptor
        import AddVectoredContinueHandler
        import AdjustCalendarDate
        import AllocateUserPhysicalPagesNuma
        import ApplicationRecoveryFinished
        import ApplicationRecoveryInProgress
        import CallbackMayRunLong
        import CancelIoEx
        import CancelSynchronousIo
        import CancelThreadpoolIo
        import CheckElevationEnabled
        import ClosePrivateNamespace
        import CloseThreadpool
        import CloseThreadpoolCleanupGroup
        import CloseThreadpoolCleanupGroupMembers
        import CloseThreadpoolIo
        import CloseThreadpoolTimer
        import CloseThreadpoolWait
        import CloseThreadpoolWork
        import CompareStringEx
        import CompareStringOrdinal
        import ConvertCalDateTimeToSystemTime
        import ConvertSystemTimeToCalDateTime
        import CopyFileTransactedA
        import CopyFileTransactedW
        import CreateBoundaryDescriptorA
        import CreateBoundaryDescriptorW
        import CreateDirectoryTransactedA
        import CreateDirectoryTransactedW
        import CreateEventExA
        import CreateEventExW
        import CreateFileMappingNumaA
        import CreateFileMappingNumaW
        import CreateFileTransactedA
        import CreateFileTransactedW
        import CreateHardLinkTransactedA
        import CreateHardLinkTransactedW
        import CreateMutexExA
        import CreateMutexExW
        import CreatePrivateNamespaceA
        import CreatePrivateNamespaceW
        import CreateSemaphoreExA
        import CreateSemaphoreExW
        import CreateSymbolicLinkA
        import CreateSymbolicLinkTransactedA
        import CreateSymbolicLinkTransactedW
        import CreateSymbolicLinkW
        import CreateThreadpool
        import CreateThreadpoolCleanupGroup
        import CreateThreadpoolIo
        import CreateThreadpoolTimer
        import CreateThreadpoolWait
        import CreateThreadpoolWork
        import CreateWaitableTimerExA
        import CreateWaitableTimerExW
        import DeleteBoundaryDescriptor
        import DeleteFileTransactedA
        import DeleteFileTransactedW
        import DeleteProcThreadAttributeList
        import DisassociateCurrentThreadFromCallback
        import EnumCalendarInfoExEx
        import EnumDateFormatsExEx
        import EnumResourceLanguagesExA
        import EnumResourceLanguagesExW
        import EnumResourceNamesExA
        import EnumResourceNamesExW
        import EnumResourceTypesExA
        import EnumResourceTypesExW
        import EnumSystemLocalesEx
        import EnumTimeFormatsEx
        import FindFirstFileNameTransactedW
        import FindFirstFileNameW
        import FindFirstFileTransactedA
        import FindFirstFileTransactedW
        import FindFirstStreamTransactedW
        import FindNextFileNameW
        import FindNLSString
        import FindNLSStringEx
        import FlushProcessWriteBuffers
        import FreeLibraryWhenCallbackReturns
        import GetApplicationRecoveryCallback
        import GetApplicationRestartSettings
        import GetCalendarDateFormatEx
        import GetCalendarInfoEx
        import GetCalendarSupportedDateRange
        import GetComPlusPackageInstallStatus
        import GetCompressedFileSizeTransactedA
        import GetCompressedFileSizeTransactedW
        import GetConsoleHistoryInfo
        import GetConsoleOriginalTitleA
        import GetConsoleOriginalTitleW
        import GetConsoleScreenBufferInfoEx
        import GetCurrencyFormatEx
        import GetCurrentConsoleFontEx
        import GetCurrentProcessorNumber
        import GetDateFormatEx
        import GetDurationFormat
        import GetDurationFormatEx
        import GetDynamicTimeZoneInformation
        import GetFileAttributesTransactedA
        import GetFileAttributesTransactedW
        import GetFileBandwidthReservation
        import GetFileInformationByHandleEx
        import GetFileMUIInfo
        import GetFileMUIPath
        import GetFinalPathNameByHandleA
        import GetFinalPathNameByHandleW
        import GetFullPathNameTransactedA
        import GetFullPathNameTransactedW
        import GetLocaleInfoEx
        import GetLongPathNameTransactedA
        import GetLongPathNameTransactedW
        import GetNamedPipeAttribute
        import GetNamedPipeClientComputerNameA
        import GetNamedPipeClientComputerNameW
        import GetNamedPipeClientProcessId
        import GetNamedPipeClientSessionId
        import GetNamedPipeServerProcessId
        import GetNamedPipeServerSessionId
        import GetNLSVersion
        import GetNLSVersionEx
        import GetNumaProximityNode
        import GetNumberFormatEx
        import GetProductInfo
        import GetQueuedCompletionStatusEx
        import GetStringScripts
        import GetSystemDefaultLocaleName
        import GetSystemPreferredUILanguages
        import GetThreadPreferredUILanguages
        import GetThreadUILanguage
        import GetTickCount64
        import GetTimeFormatEx
        import GetUILanguageInfo
        import GetUserDefaultLocaleName
        import GetUserPreferredUILanguages
        import GetVolumeInformationByHandleW
        import IdnToAscii
        import IdnToNameprepUnicode
        import IdnToUnicode
        import InitOnceBeginInitialize
        import InitOnceComplete
        import InitOnceExecuteOnce
        import InitOnceInitialize
        import InitializeConditionVariable
        import InitializeCriticalSectionEx
        import InitializeProcThreadAttributeList
        import InitializeSRWLock
        import InterlockedPushListSList
        import IsCalendarLeapDay
        import IsCalendarLeapMonth
        import IsCalendarLeapYear
        import IsNLSDefinedString
        import IsNormalizedString
        import IsThreadAFiber
        import IsThreadpoolTimerSet
        #if NTDDI_VERSION != NTDDI_WIN81
            import IsTimeZoneRedirectionEnabled
        #endif
        import IsValidCalDateTime
        import IsValidLocaleName
        import LCIDToLocaleName
        import LCMapStringEx
        import LeaveCriticalSectionWhenCallbackReturns
        import LoadStringBaseExW
        import LoadStringBaseW
        import LocaleNameToLCID
        import MapViewOfFileExNuma
        import MoveFileTransactedA
        import MoveFileTransactedW
        import NeedCurrentDirectoryForExePathA
        import NeedCurrentDirectoryForExePathW
        import NormalizeString
        import OpenFileById
        import OpenPrivateNamespaceA
        import OpenPrivateNamespaceW
        import QueryActCtxSettingsW
        import QueryFullProcessImageNameA
        import QueryFullProcessImageNameW
        import QueryIdleProcessorCycleTime
        import QueryProcessCycleTime
        import QueryThreadCycleTime
        import RegisterApplicationRecoveryCallback
        import RegisterApplicationRestart
        import ReleaseMutexWhenCallbackReturns
        import ReleaseSRWLockExclusive
        import ReleaseSRWLockShared
        import ReleaseSemaphoreWhenCallbackReturns
        import RemoveDirectoryTransactedA
        import RemoveDirectoryTransactedW
        import RemoveDllDirectory
        import ReplacePartitionUnit
        import SetCurrentConsoleFontEx
        import SetConsoleHistoryInfo
        import SetConsoleScreenBufferInfoEx
        import SetCurrentConsoleFontEx
        import SetDefaultDllDirectories
        import SetDynamicTimeZoneInformation
        import SetEventWhenCallbackReturns
        import SetFileAttributesTransactedA
        import SetFileAttributesTransactedW
        import SetFileBandwidthReservation
        import SetFileCompletionNotificationModes
        import SetFileInformationByHandle
        import SetFileIoOverlappedRange
        import SetNamedPipeAttribute
        import SetThreadpoolThreadMaximum
        import SetThreadpoolThreadMinimum
        import SetThreadpoolTimer
        import SetThreadpoolWait
        #if NTDDI_VERSION >= NTDDI_WIN8
            import SetThreadpoolWaitEx
        #endif
        import SetThreadPreferredUILanguages
        import SleepConditionVariableCS
        import SleepConditionVariableSRW
        import StartThreadpoolIo
        import SubmitThreadpoolWork
        import TrySubmitThreadpoolCallback
        import UnregisterApplicationRecoveryCallback
        import UnregisterApplicationRestart
        import UpdateCalendarDayOfWeek
        import UpdateProcThreadAttribute
        import VerifyScripts
        import VirtualAllocExNuma
        import WaitForThreadpoolIoCallbacks
        import WaitForThreadpoolTimerCallbacks
        import WaitForThreadpoolWaitCallbacks
        import WaitForThreadpoolWorkCallbacks
        import WakeAllConditionVariable
        import WakeConditionVariable
        import WerGetFlags
        import WerRegisterFile
        import WerRegisterMemoryBlock
        import WerSetFlags
        import WerUnregisterFile
        import WerUnregisterMemoryBlock
        import Wow64GetThreadContext
        import Wow64SetThreadContext
        import Wow64SuspendThread
        #ifdef APP_UNICODE
            define CopyFileTransacted CopyFileTransactedW
            define CreateBoundaryDescriptor CreateBoundaryDescriptorW
            define CreateDirectoryTransacted CreateDirectoryTransactedW
            define CreateEventEx CreateEventExW
            define CreateFileMappingNuma CreateFileMappingNumaW
            define CreateFileTransacted CreateFileTransactedW
            define CreateHardLinkTransacted CreateHardLinkTransactedW
            define CreateMutexEx CreateMutexExW
            define CreatePrivateNamespace CreatePrivateNamespaceW
            define CreateSemaphoreEx CreateSemaphoreExW
            define CreateSymbolicLink CreateSymbolicLinkW
            define CreateSymbolicLinkTransacted CreateSymbolicLinkTransactedW
            define CreateWaitableTimerEx CreateWaitableTimerExW
            define DeleteFileTransacted DeleteFileTransactedW
            define EnumResourceLanguagesEx EnumResourceLanguagesExW
            define EnumResourceNamesEx EnumResourceNamesExW
            define EnumResourceTypesEx EnumResourceTypesExW
            define FindFirstFileTransacted FindFirstFileTransactedW
            define GetCompressedFileSizeTransacted GetCompressedFileSizeTransactedW
            define GetConsoleOriginalTitle GetConsoleOriginalTitleW
            define GetFileAttributesTransacted GetFileAttributesTransactedW
            define GetFinalPathNameByHandle GetFinalPathNameByHandleW
            define GetFullPathNameTransacted GetFullPathNameTransactedW
            define GetLongPathNameTransacted GetLongPathNameTransactedW
            define GetNamedPipeClientComputerName GetNamedPipeClientComputerNameW
            define MoveFileTransacted MoveFileTransactedW
            define NeedCurrentDirectoryForExePath NeedCurrentDirectoryForExePathW
            define OpenPrivateNamespace OpenPrivateNamespaceW
            define QueryFullProcessImageName QueryFullProcessImageNameW
            define RemoveDirectoryTransacted RemoveDirectoryTransactedW
            define SetFileAttributesTransacted SetFileAttributesTransactedW
        #else
            define CopyFileTransacted CopyFileTransactedA
            define CreateBoundaryDescriptor CreateBoundaryDescriptorA
            define CreateDirectoryTransacted CreateDirectoryTransactedA
            define CreateEventEx CreateEventExA
            define CreateFileMappingNuma CreateFileMappingNumaA
            define CreateFileTransacted CreateFileTransactedA
            define CreateHardLinkTransacted CreateHardLinkTransactedA
            define CreateMutexEx CreateMutexExA
            define CreatePrivateNamespace CreatePrivateNamespaceA
            define CreateSemaphoreEx CreateSemaphoreExA
            define CreateSymbolicLink CreateSymbolicLinkA
            define CreateSymbolicLinkTransacted CreateSymbolicLinkTransactedA
            define CreateWaitableTimerEx CreateWaitableTimerExA
            define DeleteFileTransacted DeleteFileTransactedA
            define EnumResourceLanguagesEx EnumResourceLanguagesExA
            define EnumResourceNamesEx EnumResourceNamesExA
            define EnumResourceTypesEx EnumResourceTypesExA
            define FindFirstFileTransacted FindFirstFileTransactedA
            define GetCompressedFileSizeTransacted GetCompressedFileSizeTransactedA
            define GetConsoleOriginalTitle GetConsoleOriginalTitleA
            define GetFileAttributesTransacted GetFileAttributesTransactedA
            define GetFinalPathNameByHandle GetFinalPathNameByHandleA
            define GetFullPathNameTransacted GetFullPathNameTransactedA
            define GetLongPathNameTransacted GetLongPathNameTransactedA
            define GetNamedPipeClientComputerName GetNamedPipeClientComputerNameA
            define MoveFileTransacted MoveFileTransactedA
            define NeedCurrentDirectoryForExePath NeedCurrentDirectoryForExePathA
            define OpenPrivateNamespace OpenPrivateNamespaceA
            define QueryFullProcessImageName QueryFullProcessImageNameA
            define RemoveDirectoryTransacted RemoveDirectoryTransactedA
            define SetFileAttributesTransacted SetFileAttributesTransactedA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_VISTASP1
        import AddSecureMemoryCacheCallback
        import GetPhysicallyInstalledSystemMemory
        import GetTimeZoneInformationForYear
        import QueryProcessAffinityUpdateMode
        import RemoveSecureMemoryCacheCallback
        import SetProcessAffinityUpdateMode
    #endif

    #if NTDDI_VERSION >= NTDDI_WIN7
        import AddIntegrityLabelToBoundaryDescriptor
        import BaseFormatTimeOut
        import BaseGetNamedObjectDirectory
        import Basep8BitStringToDynamicUnicodeString
        import CreateProcessAsUserW
        import CreateRemoteThreadEx
        import DisableThreadProfiling
        import EnableThreadProfiling
        import FindStringOrdinal
        import GetActiveProcessorCount
        import GetActiveProcessorGroupCount
        import GetCurrentProcessorNumberEx
        import GetLogicalProcessorInformationEx
        import GetMaximumProcessorCount
        import GetMaximumProcessorGroupCount
        import GetNumaAvailableMemoryNodeEx
        import GetNumaNodeNumberFromHandle
        import GetNumaNodeProcessorMaskEx
        import GetNumaProcessorNodeEx
        import GetNumaProximityNodeEx
        import GetProcessGroupAffinity
        import GetProcessorSystemCycleTime
        import GetProcessPreferredUILanguages
        import GetProcessUserModeExceptionPolicy
        import GetThreadErrorMode
        import GetThreadGroupAffinity
        import GetThreadIdealProcessorEx
        import K32EmptyWorkingSet
        import K32EnumDeviceDrivers
        import K32EnumPageFilesA
        import K32EnumPageFilesW
        import K32EnumProcessModules
        import K32EnumProcessModulesEx
        import K32EnumProcesses
        import K32GetDeviceDriverBaseNameA
        import K32GetDeviceDriverBaseNameW
        import K32GetDeviceDriverFileNameA
        import K32GetDeviceDriverFileNameW
        import K32GetMappedFileNameA
        import K32GetMappedFileNameW
        import K32GetModuleBaseNameA
        import K32GetModuleBaseNameW
        import K32GetModuleFileNameExA
        import K32GetModuleFileNameExW
        import K32GetModuleInformation
        import K32GetPerformanceInfo
        import K32GetProcessImageFileNameA
        import K32GetProcessImageFileNameW
        import K32GetProcessMemoryInfo
        import K32GetWsChanges
        import K32GetWsChangesEx
        import K32InitializeProcessForWsWatch
        import K32QueryWorkingSet
        import K32QueryWorkingSetEx
        import LoadAppInitDlls
        import NotifyUILanguageChange
        import OpenProcessToken
        import OpenThreadToken
        import PowerClearRequest
        import PowerCreateRequest
        import PowerSetRequest
        import QueryIdleProcessorCycleTimeEx
        import QueryThreadProfiling
        import QueryThreadpoolStackInformation
        import QueryUnbiasedInterruptTime
        import RaiseFailFastException
        import ReadThreadProfilingData
        import RegCloseKey
        import RegCreateKeyExA
        import RegCreateKeyExW
        import RegDeleteKeyExA
        import RegDeleteKeyExW
        import RegDeleteTreeA
        import RegDeleteTreeW
        import RegDeleteValueA
        import RegDeleteValueW
        import RegDisablePredefinedCacheEx
        import RegEnumKeyExA
        import RegEnumKeyExW
        import RegEnumValueA
        import RegEnumValueW
        import RegFlushKey
        import RegGetKeySecurity
        import RegGetValueA
        import RegGetValueW
        import RegLoadKeyA
        import RegLoadKeyW
        import RegLoadMUIStringA
        import RegLoadMUIStringW
        import RegNotifyChangeKeyValue
        import RegOpenCurrentUser
        import RegOpenKeyExA
        import RegOpenKeyExW
        import RegOpenUserClassesRoot
        import RegQueryInfoKeyA
        import RegQueryInfoKeyW
        import RegQueryValueExA
        import RegQueryValueExW
        import RegRestoreKeyA
        import RegRestoreKeyW
        import RegSaveKeyExA
        import RegSaveKeyExW
        import RegSetKeySecurity
        import RegSetValueExA
        import RegSetValueExW
        import RegUnLoadKeyA
        import RegUnLoadKeyW
        import ResolveLocaleName
        import RtlCompareMemory
        import RtlCopyMemory
        import SetProcessPreferredUILanguages
        #if NTDDI_VERSION < NTDDI_WIN8
            import SetProcessUserModeExceptionPolicy
        #endif
        import SetSearchPathMode
        import SetStdHandleEx
        import SetThreadErrorMode
        import SetThreadGroupAffinity
        import SetThreadIdealProcessorEx
        import SetThreadpoolStackInformation
        import SetThreadToken
        import SystemTimeToTzSpecificLocalTimeEx
        import TryAcquireSRWLockExclusive
        import TryAcquireSRWLockShared
        import TzSpecificLocalTimeToSystemTimeEx
        import WerRegisterRuntimeExceptionModule
        import WerUnregisterRuntimeExceptionModule
        import Wow64GetThreadSelectorEntry
        define CopyMemory RtlCopyMemory
        #ifdef APP_WIN64
            import CreateUmsCompletionList
            import CreateUmsThreadContext
            import DeleteUmsCompletionList
            import DeleteUmsThreadContext
            import DequeueUmsCompletionListItems
            import EnterUmsSchedulingMode
            import ExecuteUmsThread
            import GetCurrentUmsThread
            import GetNextUmsListItem
            import GetUmsCompletionListEvent
            import GetUmsSystemThreadInformation
            import QueryUmsThreadInformation
            import SetUmsThreadInformation
            import UmsThreadYield
        #endif

        #ifdef APP_UNICODE
            define K32EnumPageFiles K32EnumPageFilesW
            define K32GetDeviceDriverBaseName K32GetDeviceDriverBaseNameW
            define K32GetDeviceDriverFileName K32GetDeviceDriverFileNameW
            define K32GetMappedFileName K32GetMappedFileNameW
            define K32GetModuleBaseName K32GetModuleBaseNameW
            define K32GetModuleFileNameEx K32GetModuleFileNameExW
            define K32GetProcessImageFileName K32GetProcessImageFileNameW
            define RegCreateKeyEx RegCreateKeyExW
            define RegDeleteKeyEx RegDeleteKeyExW
            define RegDeleteTree RegDeleteTreeW
            define RegDeleteValue RegDeleteValueW
            define RegEnumKeyEx RegEnumKeyExW
            define RegEnumValue RegEnumValueW
            define RegGetValue RegGetValueW
            define RegLoadKey RegLoadKeyW
            define RegLoadMUIString RegLoadMUIStringW
            define RegOpenKeyEx RegOpenKeyExW
            define RegQueryInfoKey RegQueryInfoKeyW
            define RegQueryValueEx RegQueryValueExW
            define RegRestoreKey RegRestoreKeyW
            define RegSaveKeyEx RegSaveKeyExW
            define RegSetValueEx RegSetValueExW
            define RegUnLoadKey RegUnLoadKeyW
        #else
            define K32EnumPageFiles K32EnumPageFilesA
            define K32GetDeviceDriverBaseName K32GetDeviceDriverBaseNameA
            define K32GetDeviceDriverFileName K32GetDeviceDriverFileNameA
            define K32GetMappedFileName K32GetMappedFileNameA
            define K32GetModuleBaseName K32GetModuleBaseNameA
            define K32GetModuleFileNameEx K32GetModuleFileNameExA
            define K32GetProcessImageFileName K32GetProcessImageFileNameA
            define RegCreateKeyEx RegCreateKeyExA
            define RegDeleteKeyEx RegDeleteKeyExA
            define RegDeleteTree RegDeleteTreeA
            define RegDeleteValue RegDeleteValueA
            define RegEnumKeyEx RegEnumKeyExA
            define RegEnumValue RegEnumValueA
            define RegGetValue RegGetValueA
            define RegLoadKey RegLoadKeyA
            define RegLoadMUIString RegLoadMUIStringA
            define RegOpenKeyEx RegOpenKeyExA
            define RegQueryInfoKey RegQueryInfoKeyA
            define RegQueryValueEx RegQueryValueExA
            define RegRestoreKey RegRestoreKeyA
            define RegSaveKeyEx RegSaveKeyExA
            define RegSetValueEx RegSetValueExA
            define RegUnLoadKey RegUnLoadKeyA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WIN7SP1
        import CopyContext
        import GetEnabledXStateFeatures
        import GetXStateFeaturesMask
        import InitializeContext
        import LocateXStateFeature
        import SetXStateFeaturesMask
    #endif

    #if NTDDI_VERSION >= NTDDI_WIN8
        #if NTDDI_VERSION == NTDDI_WIN8
            import AcquireStateLock
        #endif
        import AddResourceAttributeAce
        import AddScopedPolicyIDAce
        #if NTDDI_VERSION == NTDDI_WIN81
            import CalloutOnFiberStack
            import CopyExtendedContext
        #endif
        import CeipIsOptedIn
        import CheckTokenCapability
        import CheckTokenMembershipEx
        import ClosePackageInfo
        import CopyFile2
        import CreateFile2
        import CreateFileMappingFromApp
        import GetAppContainerNamedObjectPath
        import GetApplicationUserModelId
        import GetCachedSigningLevel
        import GetCurrentApplicationUserModelId
        import GetCurrentPackageFamilyName
        import GetCurrentPackageFullName
        import GetCurrentPackageId
        import GetCurrentPackageInfo
        import GetCurrentPackagePath
        import GetCurrentThreadStackLimits
        import GetFirmwareEnvironmentVariableExA
        import GetFirmwareEnvironmentVariableExW
        import GetFirmwareType
        import GetMemoryErrorHandlingCapabilities
        import GetOverlappedResultEx
        import GetPackageFamilyName
        import GetPackageFullName
        import GetPackageId
        import GetPackageInfo
        import GetPackagePath
        import GetPackagesByPackageFamily
        import GetProcessInformation
        import GetProcessMitigationPolicy
        import GetSystemTimePreciseAsFileTime
        import GetThreadInformation
        import GlobalAddAtomExA
        import GlobalAddAtomExW
        import InterlockedPushListSListEx
        import IsNativeVhdBoot
        import IsValidNLSVersion
        import LoadPackagedLibrary
        import MapViewOfFileFromApp
        import OpenPackageInfoByFullName
        import PackageFamilyNameFromFullName
        import PackageFamilyNameFromId
        import PackageFullNameFromId
        import PackageIdFromFullName
        import PackageNameAndPublisherIdFromFamilyName
        import PrefetchVirtualMemory
        import RegCopyTreeW
        import RegisterBadMemoryNotification
        import RestoreLastError
        import SetCachedSigningLevel
        import SetFirmwareEnvironmentVariableExA
        import SetFirmwareEnvironmentVariableExW
        import SetProcessInformation
        import SetProcessMitigationPolicy
        import SetThreadInformation
        import UnregisterBadMemoryNotification
        #ifdef APP_UNICODE
            define GetFirmwareEnvironmentVariableEx GetFirmwareEnvironmentVariableExW
            define GlobalAddAtomEx GlobalAddAtomExW
            define SetFirmwareEnvironmentVariableEx SetFirmwareEnvironmentVariableExW
        #else
            define GetFirmwareEnvironmentVariableEx GetFirmwareEnvironmentVariableExA
            define GlobalAddAtomEx GlobalAddAtomExA
            define SetFirmwareEnvironmentVariableEx SetFirmwareEnvironmentVariableExA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WIN81
        import DeleteSynchronizationBarrier
        import EnterSynchronizationBarrier
        import FindPackagesByPackageFamily
        import FormatApplicationUserModelId
        import GetPackageApplicationIds
        import GetPackagePathByFullName
        import GetStagedPackagePathByFullName
        import InitializeSynchronizationBarrier
        import InstallELAMCertificateInfo
        import IsProcessCritical
        import OOBEComplete
        import ParseApplicationUserModelId
        import PssCaptureSnapshot
        import PssDuplicateSnapshot
        import PssFreeSnapshot
        import PssQuerySnapshot
        import PssWalkMarkerCreate
        import PssWalkMarkerFree
        import PssWalkMarkerGetPosition
        import PssWalkMarkerSeekToBeginning
        import PssWalkMarkerSetPosition
        import PssWalkSnapshot
        import RegisterWaitUntilOOBECompleted
        import UnregisterWaitUntilOOBECompleted
    #endif

    #if NTDDI_VERSION >= NTDDI_WIN10
        import CreateEnclave
        import CreateProcessAsUserA
        import DiscardVirtualMemory
        import FreeMemoryJobObject
        import GetProcessDefaultCpuSets
        import GetSystemCpuSetInformation
        import GetThreadSelectedCpuSets
        import InitializeEnclave
        import IsEnclaveTypeSupported
        import LoadEnclaveData
        import OfferVirtualMemory
        import QueryIoRateControlInformationJobObject
        import QueryProtectedPolicy
        import ReclaimVirtualMemory
        import SetIoRateControlInformationJobObject
        import SetProcessDefaultCpuSets
        import SetProtectedPolicy
        import SetThreadSelectedCpuSets
        import WaitForDebugEventEx
    #endif
#else
    extern _hread alias __hread@12
    extern _hwrite alias __hwrite@12
    extern _lclose alias __lclose@4
    extern _lcreat alias __lcreat@8
    extern _llseek alias __llseek@12
    extern _lopen alias __lopen@8
    extern _lread alias __lread@12
    extern _lwrite alias __lwrite@12
    extern AddAtomA alias _AddAtomA@4
    extern AddAtomW alias _AddAtomW@4
    extern AllocConsole alias _AllocConsole@0
    extern AreFileApisANSI alias _AreFileApisANSI@0
    extern BackupRead alias _BackupRead@28
    extern BackupSeek alias _BackupSeek@24
    extern BackupWrite alias _BackupWrite@28
    extern Beep alias _Beep@8
    extern BeginUpdateResourceA alias _BeginUpdateResourceA@8
    extern BeginUpdateResourceW alias _BeginUpdateResourceW@8
    extern BuildCommDCBA alias _BuildCommDCBA@8
    extern BuildCommDCBAndTimeoutsA alias _BuildCommDCBAndTimeoutsA@12
    extern BuildCommDCBAndTimeoutsW alias _BuildCommDCBAndTimeoutsW@12
    extern BuildCommDCBW alias _BuildCommDCBW@8
    extern CallNamedPipeA alias _CallNamedPipeA@28
    extern CallNamedPipeW alias _CallNamedPipeW@28
    extern ClearCommBreak alias _ClearCommBreak@4
    extern ClearCommError alias _ClearCommError@12
    extern CloseHandle alias _CloseHandle@4
    ;extern CloseProfileUserMapping alias _CloseProfileUserMapping@0
    extern CommConfigDialogA alias _CommConfigDialogA@12
    extern CommConfigDialogW alias _CommConfigDialogW@12
    extern CompareFileTime alias _CompareFileTime@8
    extern CompareStringA alias _CompareStringA@24
    extern CompareStringW alias _CompareStringW@24
    extern ConnectNamedPipe alias _ConnectNamedPipe@8
    extern ContinueDebugEvent alias _ContinueDebugEvent@12
    extern ConvertDefaultLocale alias _ConvertDefaultLocale@4
    extern CopyFileA alias _CopyFileA@12
    extern CopyFileW alias _CopyFileW@12
    extern CreateConsoleScreenBuffer alias _CreateConsoleScreenBuffer@20
    extern CreateDirectoryA alias _CreateDirectoryA@8
    extern CreateDirectoryExA alias _CreateDirectoryExA@12
    extern CreateDirectoryExW alias _CreateDirectoryExW@12
    extern CreateDirectoryW alias _CreateDirectoryW@8
    extern CreateEventA alias _CreateEventA@16
    extern CreateEventW alias _CreateEventW@16
    extern CreateFileA alias _CreateFileA@28
    extern CreateFileMappingA alias _CreateFileMappingA@24
    extern CreateFileMappingW alias _CreateFileMappingW@24
    extern CreateFileW alias _CreateFileW@28
    extern CreateIoCompletionPort alias _CreateIoCompletionPort@16
    extern CreateMailslotA alias _CreateMailslotA@16
    extern CreateMailslotW alias _CreateMailslotW@16
    extern CreateMutexA alias _CreateMutexA@12
    extern CreateMutexW alias _CreateMutexW@12
    extern CreateNamedPipeA alias _CreateNamedPipeA@32
    extern CreateNamedPipeW alias _CreateNamedPipeW@32
    extern CreatePipe alias _CreatePipe@16
    extern CreateProcessA alias _CreateProcessA@40
    extern CreateProcessW alias _CreateProcessW@40
    extern CreateRemoteThread alias _CreateRemoteThread@28
    extern CreateSemaphoreA alias _CreateSemaphoreA@16
    extern CreateSemaphoreW alias _CreateSemaphoreW@16
    extern CreateTapePartition alias _CreateTapePartition@16
    extern CreateThread alias _CreateThread@24
    extern CreateToolhelp32Snapshot alias _CreateToolhelp32Snapshot@8
    extern DebugActiveProcess alias _DebugActiveProcess@4
    extern DebugBreak alias _DebugBreak@0
    extern DefineDosDeviceA alias _DefineDosDeviceA@12
    extern DefineDosDeviceW alias _DefineDosDeviceW@12
    extern DeleteAtom alias _DeleteAtom@4
    extern DeleteCriticalSection alias _DeleteCriticalSection@4
    extern DeleteFileA alias _DeleteFileA@4
    extern DeleteFileW alias _DeleteFileW@4
    extern DeviceIoControl alias _DeviceIoControl@32
    extern DisableThreadLibraryCalls alias _DisableThreadLibraryCalls@4
    extern DisconnectNamedPipe alias _DisconnectNamedPipe@4
    extern DosDateTimeToFileTime alias _DosDateTimeToFileTime@12
    extern DuplicateHandle alias _DuplicateHandle@28
    extern EndUpdateResourceA alias _EndUpdateResourceA@8
    extern EndUpdateResourceW alias _EndUpdateResourceW@8
    extern EnterCriticalSection alias _EnterCriticalSection@4
    extern EnumCalendarInfoA alias _EnumCalendarInfoA@16
    extern EnumCalendarInfoW alias _EnumCalendarInfoW@16
    extern EnumDateFormatsA alias _EnumDateFormatsA@12
    extern EnumDateFormatsW alias _EnumDateFormatsW@12
    extern EnumResourceLanguagesA alias _EnumResourceLanguagesA@20
    extern EnumResourceLanguagesW alias _EnumResourceLanguagesW@20
    extern EnumResourceNamesA alias _EnumResourceNamesA@16
    extern EnumResourceNamesW alias _EnumResourceNamesW@16
    extern EnumResourceTypesA alias _EnumResourceTypesA@12
    extern EnumResourceTypesW alias _EnumResourceTypesW@12
    extern EnumSystemCodePagesA alias _EnumSystemCodePagesA@8
    extern EnumSystemCodePagesW alias _EnumSystemCodePagesW@8
    extern EnumSystemLocalesA alias _EnumSystemLocalesA@8
    extern EnumSystemLocalesW alias _EnumSystemLocalesW@8
    extern EnumTimeFormatsA alias _EnumTimeFormatsA@12
    extern EnumTimeFormatsW alias _EnumTimeFormatsW@12
    extern EraseTape alias _EraseTape@12
    extern EscapeCommFunction alias _EscapeCommFunction@8
    extern ExitProcess alias _ExitProcess@4
    extern ExitThread alias _ExitThread@4
    extern ExpandEnvironmentStringsA alias _ExpandEnvironmentStringsA@12
    extern ExpandEnvironmentStringsW alias _ExpandEnvironmentStringsW@12
    extern FatalAppExitA alias _FatalAppExitA@8
    extern FatalAppExitW alias _FatalAppExitW@8
    extern FatalExit alias _FatalExit@4
    extern FileTimeToDosDateTime alias _FileTimeToDosDateTime@12
    extern FileTimeToLocalFileTime alias _FileTimeToLocalFileTime@8
    extern FileTimeToSystemTime alias _FileTimeToSystemTime@8
    extern FillConsoleOutputAttribute alias _FillConsoleOutputAttribute@20
    extern FillConsoleOutputCharacterA alias _FillConsoleOutputCharacterA@20
    extern FillConsoleOutputCharacterW alias _FillConsoleOutputCharacterW@20
    extern FindAtomA alias _FindAtomA@4
    extern FindAtomW alias _FindAtomW@4
    extern FindClose alias _FindClose@4
    extern FindCloseChangeNotification alias _FindCloseChangeNotification@4
    extern FindFirstChangeNotificationA alias _FindFirstChangeNotificationA@12
    extern FindFirstChangeNotificationW alias _FindFirstChangeNotificationW@12
    extern FindFirstFileA alias _FindFirstFileA@8
    extern FindFirstFileW alias _FindFirstFileW@8
    extern FindNextChangeNotification alias _FindNextChangeNotification@4
    extern FindNextFileA alias _FindNextFileA@8
    extern FindNextFileW alias _FindNextFileW@8
    extern FindResourceA alias _FindResourceA@12
    extern FindResourceExA alias _FindResourceExA@16
    extern FindResourceExW alias _FindResourceExW@16
    extern FindResourceW alias _FindResourceW@12
    extern FlushConsoleInputBuffer alias _FlushConsoleInputBuffer@4
    extern FlushFileBuffers alias _FlushFileBuffers@4
    extern FlushInstructionCache alias _FlushInstructionCache@12
    extern FlushViewOfFile alias _FlushViewOfFile@8
    extern FoldStringA alias _FoldStringA@20
    extern FoldStringW alias _FoldStringW@20
    extern FormatMessageA alias _FormatMessageA@28
    extern FormatMessageW alias _FormatMessageW@28
    extern FreeConsole alias _FreeConsole@0
    extern FreeEnvironmentStringsA alias _FreeEnvironmentStringsA@4
    extern FreeEnvironmentStringsW alias _FreeEnvironmentStringsW@4
    extern FreeLibrary alias _FreeLibrary@4
    extern FreeLibraryAndExitThread alias _FreeLibraryAndExitThread@8
    extern FreeResource alias _FreeResource@4
    extern GenerateConsoleCtrlEvent alias _GenerateConsoleCtrlEvent@8
    extern GetACP alias _GetACP@0
    extern GetAtomNameA alias _GetAtomNameA@12
    extern GetAtomNameW alias _GetAtomNameW@12
    extern GetBinaryTypeA alias _GetBinaryTypeA@8
    extern GetBinaryTypeW alias _GetBinaryTypeW@8
    extern GetCommandLineA alias _GetCommandLineA@0
    extern GetCommandLineW alias _GetCommandLineW@0
    extern GetCommConfig alias _GetCommConfig@12
    extern GetCommMask alias _GetCommMask@8
    extern GetCommModemStatus alias _GetCommModemStatus@8
    extern GetCommProperties alias _GetCommProperties@8
    extern GetCommState alias _GetCommState@8
    extern GetCommTimeouts alias _GetCommTimeouts@8
    extern GetCompressedFileSizeA alias _GetCompressedFileSizeA@8
    extern GetCompressedFileSizeW alias _GetCompressedFileSizeW@8
    extern GetComputerNameA alias _GetComputerNameA@8
    extern GetComputerNameW alias _GetComputerNameW@8
    extern GetConsoleCP alias _GetConsoleCP@0
    extern GetConsoleCursorInfo alias _GetConsoleCursorInfo@8
    extern GetConsoleMode alias _GetConsoleMode@8
    extern GetConsoleOutputCP alias _GetConsoleOutputCP@0
    extern GetConsoleScreenBufferInfo alias _GetConsoleScreenBufferInfo@8
    extern GetConsoleTitleA alias _GetConsoleTitleA@8
    extern GetConsoleTitleW alias _GetConsoleTitleW@8
    extern GetCPInfo alias _GetCPInfo@8
    extern GetCurrencyFormatA alias _GetCurrencyFormatA@24
    extern GetCurrencyFormatW alias _GetCurrencyFormatW@24
    extern GetCurrentDirectoryA alias _GetCurrentDirectoryA@8
    extern GetCurrentDirectoryW alias _GetCurrentDirectoryW@8
    extern GetCurrentProcess alias _GetCurrentProcess@0
    extern GetCurrentProcessId alias _GetCurrentProcessId@0
    extern GetCurrentThread alias _GetCurrentThread@0
    extern GetCurrentThreadId alias _GetCurrentThreadId@0
    extern GetDateFormatA alias _GetDateFormatA@24
    extern GetDateFormatW alias _GetDateFormatW@24
    extern GetDefaultCommConfigA alias _GetDefaultCommConfigA@12
    extern GetDefaultCommConfigW alias _GetDefaultCommConfigW@12
    extern GetDiskFreeSpaceA alias _GetDiskFreeSpaceA@20
    extern GetDiskFreeSpaceExA alias _GetDiskFreeSpaceExA@16
    extern GetDiskFreeSpaceExW alias _GetDiskFreeSpaceExW@16
    extern GetDiskFreeSpaceW alias _GetDiskFreeSpaceW@20
    extern GetDriveTypeA alias _GetDriveTypeA@4
    extern GetDriveTypeW alias _GetDriveTypeW@4
    extern GetEnvironmentStringsA alias _GetEnvironmentStringsA@0
    extern GetEnvironmentStringsW alias _GetEnvironmentStringsW@0
    extern GetEnvironmentVariableA alias _GetEnvironmentVariableA@12
    extern GetEnvironmentVariableW alias _GetEnvironmentVariableW@12
;   ------------------------------ Not present in MASM32 kernel32.lib -------------------------------
;    #if NTDDI_VERSION == NTDDI_WIN95
;        extern GetErrorMode alias _GetErrorMode@0
;    #else
;        #if NTDDI_VERSION == NTDDI_WIN98_ME
;            extern GetErrorMode alias _GetErrorMode@0
;        #else
;            #if NTDDI_VERSION >= NTDDI_VISTA
;                extern GetErrorMode alias _GetErrorMode@0
;            #endif
;        #endif
;    #endif
;   -------------------------------------------------------------------------------------------------
    extern GetExitCodeProcess alias _GetExitCodeProcess@8
    extern GetExitCodeThread alias _GetExitCodeThread@8
    extern GetFileAttributesA alias _GetFileAttributesA@4
    extern GetFileAttributesW alias _GetFileAttributesW@4
    extern GetFileInformationByHandle alias _GetFileInformationByHandle@8
    extern GetFileSize alias _GetFileSize@8
    extern GetFileTime alias _GetFileTime@16
    extern GetFileType alias _GetFileType@4
    extern GetFullPathNameA alias _GetFullPathNameA@16
    extern GetFullPathNameW alias _GetFullPathNameW@16
;    #if NTDDI_VERSION == NTDDI_WIN95
;        extern GetHandleContext alias _GetHandleContext@4
;        extern SetHandleContext alias _SetHandleContext@8
;    #else
;        #if NTDDI_VERSION == NTDDI_WIN98_ME
;            extern GetHandleContext alias _GetHandleContext@4
;            extern SetHandleContext alias _SetHandleContext@8
;        #else
;            #if NTDDI_VERSION >= NTDDI_WINXP
;                #if NTDDI_VERSION <= NTDDI_VISTA
;                    extern GetHandleContext alias _GetHandleContext@4
;                    extern SetHandleContext alias _SetHandleContext@8
;                #endif
;            #endif
;        #endif
;    #endif
    extern GetHandleInformation alias _GetHandleInformation@8
    extern GetLargestConsoleWindowSize alias _GetLargestConsoleWindowSize@4
    extern GetLastError alias _GetLastError@0
    extern GetLocaleInfoA alias _GetLocaleInfoA@16
    extern GetLocaleInfoW alias _GetLocaleInfoW@16
    extern GetLocalTime alias _GetLocalTime@4
    extern GetLogicalDrives alias _GetLogicalDrives@0
    extern GetLogicalDriveStringsA alias _GetLogicalDriveStringsA@8
    extern GetLogicalDriveStringsW alias _GetLogicalDriveStringsW@8
    extern GetMailslotInfo alias _GetMailslotInfo@20
    extern GetModuleFileNameA alias _GetModuleFileNameA@12
    extern GetModuleFileNameW alias _GetModuleFileNameW@12
    extern GetModuleHandleA alias _GetModuleHandleA@4
    extern GetModuleHandleW alias _GetModuleHandleW@4
    extern GetNamedPipeHandleStateA alias _GetNamedPipeHandleStateA@28
    extern GetNamedPipeHandleStateW alias _GetNamedPipeHandleStateW@28
    extern GetNamedPipeInfo alias _GetNamedPipeInfo@20
    extern GetNumberFormatA alias _GetNumberFormatA@24
    extern GetNumberFormatW alias _GetNumberFormatW@24
    extern GetNumberOfConsoleInputEvents alias _GetNumberOfConsoleInputEvents@8
    extern GetNumberOfConsoleMouseButtons alias _GetNumberOfConsoleMouseButtons@4
    extern GetOEMCP alias _GetOEMCP@0
    extern GetOverlappedResult alias _GetOverlappedResult@16
    extern GetPriorityClass alias _GetPriorityClass@4
    extern GetPrivateProfileIntA alias _GetPrivateProfileIntA@16
    extern GetPrivateProfileIntW alias _GetPrivateProfileIntW@16
    extern GetPrivateProfileSectionA alias _GetPrivateProfileSectionA@16
    extern GetPrivateProfileSectionNamesA alias _GetPrivateProfileSectionNamesA@12
    extern GetPrivateProfileSectionNamesW alias _GetPrivateProfileSectionNamesW@12
    extern GetPrivateProfileSectionW alias _GetPrivateProfileSectionW@16
    extern GetPrivateProfileStringA alias _GetPrivateProfileStringA@24
    extern GetPrivateProfileStringW alias _GetPrivateProfileStringW@24
    extern GetPrivateProfileStructA alias _GetPrivateProfileStructA@20
    extern GetPrivateProfileStructW alias _GetPrivateProfileStructW@20
    extern GetProcAddress alias _GetProcAddress@8
    extern GetProcessAffinityMask alias _GetProcessAffinityMask@12
    extern GetProcessHeap alias _GetProcessHeap@0
    extern GetProcessHeaps alias _GetProcessHeaps@8
    extern GetProcessShutdownParameters alias _GetProcessShutdownParameters@8
    extern GetProcessTimes alias _GetProcessTimes@20
    extern GetProcessVersion alias _GetProcessVersion@4
    extern GetProcessWorkingSetSize alias _GetProcessWorkingSetSize@12
    extern GetProfileIntA alias _GetProfileIntA@12
    extern GetProfileIntW alias _GetProfileIntW@12
    extern GetProfileSectionA alias _GetProfileSectionA@12
    extern GetProfileSectionW alias _GetProfileSectionW@12
    extern GetProfileStringA alias _GetProfileStringA@20
    extern GetProfileStringW alias _GetProfileStringW@20
    extern GetQueuedCompletionStatus alias _GetQueuedCompletionStatus@20
    extern GetShortPathNameA alias _GetShortPathNameA@12
    extern GetShortPathNameW alias _GetShortPathNameW@12
    extern GetStartupInfoA alias _GetStartupInfoA@4
    extern GetStartupInfoW alias _GetStartupInfoW@4
    extern GetStdHandle alias _GetStdHandle@4
    extern GetStringTypeA alias _GetStringTypeA@20
    extern GetStringTypeExA alias _GetStringTypeExA@20
    extern GetStringTypeExW alias _GetStringTypeExW@20
    extern GetStringTypeW alias _GetStringTypeW@16
    extern GetSystemDefaultLangID alias _GetSystemDefaultLangID@0
    extern GetSystemDefaultLCID alias _GetSystemDefaultLCID@0
    extern GetSystemDirectoryA alias _GetSystemDirectoryA@8
    extern GetSystemDirectoryW alias _GetSystemDirectoryW@8
    extern GetSystemInfo alias _GetSystemInfo@4
    extern GetSystemPowerStatus alias _GetSystemPowerStatus@4
    extern GetSystemTime alias _GetSystemTime@4
    extern GetSystemTimeAdjustment alias _GetSystemTimeAdjustment@12
    extern GetSystemTimeAsFileTime alias _GetSystemTimeAsFileTime@4
    extern GetTapeParameters alias _GetTapeParameters@16
    extern GetTapePosition alias _GetTapePosition@20
    extern GetTapeStatus alias _GetTapeStatus@4
    extern GetTempFileNameA alias _GetTempFileNameA@16
    extern GetTempFileNameW alias _GetTempFileNameW@16
    extern GetTempPathA alias _GetTempPathA@8
    extern GetTempPathW alias _GetTempPathW@8
    extern GetThreadContext alias _GetThreadContext@8
    extern GetThreadLocale alias _GetThreadLocale@0
    extern GetThreadPriority alias _GetThreadPriority@4
    extern GetThreadSelectorEntry alias _GetThreadSelectorEntry@12
    extern GetThreadTimes alias _GetThreadTimes@20
    extern GetTickCount alias _GetTickCount@0
    extern GetTimeFormatA alias _GetTimeFormatA@24
    extern GetTimeFormatW alias _GetTimeFormatW@24
    extern GetTimeZoneInformation alias _GetTimeZoneInformation@4
    extern GetUserDefaultLangID alias _GetUserDefaultLangID@0
    extern GetUserDefaultLCID alias _GetUserDefaultLCID@0
    extern GetVersion alias _GetVersion@0
    extern GetVersionExA alias _GetVersionExA@4
    extern GetVersionExW alias _GetVersionExW@4
    extern GetVolumeInformationA alias _GetVolumeInformationA@32
    extern GetVolumeInformationW alias _GetVolumeInformationW@32
    extern GetWindowsDirectoryA alias _GetWindowsDirectoryA@8
    extern GetWindowsDirectoryW alias _GetWindowsDirectoryW@8
    extern GlobalAddAtomA alias _GlobalAddAtomA@4
    extern GlobalAddAtomW alias _GlobalAddAtomW@4
    extern GlobalAlloc alias _GlobalAlloc@8
    extern GlobalCompact alias _GlobalCompact@4
    extern GlobalDeleteAtom alias _GlobalDeleteAtom@4
    extern GlobalFindAtomA alias _GlobalFindAtomA@4
    extern GlobalFindAtomW alias _GlobalFindAtomW@4
    extern GlobalFix alias _GlobalFix@4
    extern GlobalFlags alias _GlobalFlags@4
    extern GlobalFree alias _GlobalFree@4
    extern GlobalGetAtomNameA alias _GlobalGetAtomNameA@12
    extern GlobalGetAtomNameW alias _GlobalGetAtomNameW@12
    extern GlobalHandle alias _GlobalHandle@4
    extern GlobalLock alias _GlobalLock@4
    extern GlobalMemoryStatus alias _GlobalMemoryStatus@4
    extern GlobalReAlloc alias _GlobalReAlloc@12
    extern GlobalSize alias _GlobalSize@4
    extern GlobalUnfix alias _GlobalUnfix@4
    extern GlobalUnlock alias _GlobalUnlock@4
    extern GlobalUnWire alias _GlobalUnWire@4
    extern GlobalWire alias _GlobalWire@4
    extern Heap32First alias _Heap32First@12
    extern Heap32ListFirst alias _Heap32ListFirst@8
    extern Heap32ListNext alias _Heap32ListNext@8
    extern Heap32Next alias _Heap32Next@4
    extern HeapAlloc alias _HeapAlloc@12
    extern HeapCompact alias _HeapCompact@8
    extern HeapCreate alias _HeapCreate@12
    extern HeapDestroy alias _HeapDestroy@4
    extern HeapFree alias _HeapFree@12
    extern HeapLock alias _HeapLock@4
    extern HeapReAlloc alias _HeapReAlloc@16
    extern HeapSize alias _HeapSize@12
    extern HeapUnlock alias _HeapUnlock@4
    extern HeapValidate alias _HeapValidate@12
    extern HeapWalk alias _HeapWalk@8
    extern InitAtomTable alias _InitAtomTable@4
    extern InitializeCriticalSection alias _InitializeCriticalSection@4
    extern IsBadCodePtr alias _IsBadCodePtr@4
    extern IsBadHugeReadPtr alias _IsBadHugeReadPtr@8
    extern IsBadHugeWritePtr alias _IsBadHugeWritePtr@8
    extern IsBadReadPtr alias _IsBadReadPtr@8
    extern IsBadStringPtrA alias _IsBadStringPtrA@8
    extern IsBadStringPtrW alias _IsBadStringPtrW@8
    extern IsBadWritePtr alias _IsBadWritePtr@8
    extern IsDBCSLeadByte alias _IsDBCSLeadByte@4
    extern IsDBCSLeadByteEx alias _IsDBCSLeadByteEx@8
    extern IsValidCodePage alias _IsValidCodePage@4
    extern IsValidLocale alias _IsValidLocale@8
    extern LCMapStringA alias _LCMapStringA@24
    extern LCMapStringW alias _LCMapStringW@24
    extern LeaveCriticalSection alias _LeaveCriticalSection@4
    extern LoadLibraryA alias _LoadLibraryA@4
    extern LoadLibraryExA alias _LoadLibraryExA@12
    extern LoadLibraryExW alias _LoadLibraryExW@12
    extern LoadLibraryW alias _LoadLibraryW@4
    extern LoadModule alias _LoadModule@8
    extern LoadResource alias _LoadResource@8
    extern LocalAlloc alias _LocalAlloc@8
    extern LocalCompact alias _LocalCompact@4
    extern LocalFileTimeToFileTime alias _LocalFileTimeToFileTime@8
    extern LocalFlags alias _LocalFlags@4
    extern LocalFree alias _LocalFree@4
    extern LocalHandle alias _LocalHandle@4
    extern LocalLock alias _LocalLock@4
    extern LocalReAlloc alias _LocalReAlloc@12
    extern LocalShrink alias _LocalShrink@8
    extern LocalSize alias _LocalSize@4
    extern LocalUnlock alias _LocalUnlock@4
    extern LockFile alias _LockFile@20
    extern LockFileEx alias _LockFileEx@24
    extern LockResource alias _LockResource@4
    extern lstrcatA alias _lstrcatA@8
    extern lstrcatW alias _lstrcatW@8
    extern lstrcmpA alias _lstrcmpA@8
    extern lstrcmpiA alias _lstrcmpiA@8
    extern lstrcmpiW alias _lstrcmpiW@8
    extern lstrcmpW alias _lstrcmpW@8
    extern lstrcpyA alias _lstrcpyA@8
    extern lstrcpynA alias _lstrcpynA@12
    extern lstrcpynW alias _lstrcpynW@12
    extern lstrcpyW alias _lstrcpyW@8
    extern lstrlenA alias _lstrlenA@4
    extern lstrlenW alias _lstrlenW@4
    extern MapViewOfFile alias _MapViewOfFile@20
    extern MapViewOfFileEx alias _MapViewOfFileEx@24
    extern MoveFileA alias _MoveFileA@8
    extern MoveFileExA alias _MoveFileExA@12
    extern MoveFileExW alias _MoveFileExW@12
    extern MoveFileW alias _MoveFileW@8
    extern MulDiv alias _MulDiv@12
    extern MultiByteToWideChar alias _MultiByteToWideChar@24
    extern OpenEventA alias _OpenEventA@12
    extern OpenEventW alias _OpenEventW@12
    extern OpenFile alias _OpenFile@12
    extern OpenFileMappingA alias _OpenFileMappingA@12
    extern OpenFileMappingW alias _OpenFileMappingW@12
    extern OpenMutexA alias _OpenMutexA@12
    extern OpenMutexW alias _OpenMutexW@12
    extern OpenProcess alias _OpenProcess@12
    extern OpenSemaphoreA alias _OpenSemaphoreA@12
    extern OpenSemaphoreW alias _OpenSemaphoreW@12
    extern OutputDebugStringA alias _OutputDebugStringA@4
    extern OutputDebugStringW alias _OutputDebugStringW@4
    extern PeekConsoleInputA alias _PeekConsoleInputA@16
    extern PeekConsoleInputW alias _PeekConsoleInputW@16
    extern PeekNamedPipe alias _PeekNamedPipe@24
    extern PostQueuedCompletionStatus alias _PostQueuedCompletionStatus@16
    extern PrepareTape alias _PrepareTape@12
    extern PulseEvent alias _PulseEvent@4
    extern PurgeComm alias _PurgeComm@8
    extern QueryDosDeviceA alias _QueryDosDeviceA@12
    extern QueryDosDeviceW alias _QueryDosDeviceW@12
    extern QueryPerformanceCounter alias _QueryPerformanceCounter@4
    extern QueryPerformanceFrequency alias _QueryPerformanceFrequency@4
    extern QueueUserAPC alias _QueueUserAPC@12
    extern RaiseException alias _RaiseException@16
    extern ReadConsoleA alias _ReadConsoleA@20
    extern ReadConsoleInputA alias _ReadConsoleInputA@16
    extern ReadConsoleInputW alias _ReadConsoleInputW@16
    extern ReadConsoleOutputA alias _ReadConsoleOutputA@20
    extern ReadConsoleOutputAttribute alias _ReadConsoleOutputAttribute@20
    extern ReadConsoleOutputCharacterA alias _ReadConsoleOutputCharacterA@20
    extern ReadConsoleOutputCharacterW alias _ReadConsoleOutputCharacterW@20
    extern ReadConsoleOutputW alias _ReadConsoleOutputW@20
    extern ReadConsoleW alias _ReadConsoleW@20
    extern ReadFile alias _ReadFile@20
    extern ReadFileEx alias _ReadFileEx@20
    extern ReadProcessMemory alias _ReadProcessMemory@20
    extern ReleaseMutex alias _ReleaseMutex@4
    extern ReleaseSemaphore alias _ReleaseSemaphore@12
    extern RemoveDirectoryA alias _RemoveDirectoryA@4
    extern RemoveDirectoryW alias _RemoveDirectoryW@4
    extern ResetEvent alias _ResetEvent@4
    extern ResumeThread alias _ResumeThread@4
    extern RtlFillMemory alias _RtlFillMemory@12
    extern RtlMoveMemory alias _RtlMoveMemory@12
    extern RtlZeroMemory alias _RtlZeroMemory@8
    extern RtlUnwind alias _RtlUnwind@16
    extern ScrollConsoleScreenBufferA alias _ScrollConsoleScreenBufferA@20
    extern ScrollConsoleScreenBufferW alias _ScrollConsoleScreenBufferW@20
    extern SearchPathA alias _SearchPathA@24
    extern SearchPathW alias _SearchPathW@24
    extern SetCommBreak alias _SetCommBreak@4
    extern SetCommConfig alias _SetCommConfig@12
    extern SetCommMask alias _SetCommMask@8
    extern SetCommState alias _SetCommState@8
    extern SetCommTimeouts alias _SetCommTimeouts@8
    extern SetComputerNameA alias _SetComputerNameA@4
    extern SetComputerNameW alias _SetComputerNameW@4
    extern SetConsoleActiveScreenBuffer alias _SetConsoleActiveScreenBuffer@4
    extern SetConsoleCP alias _SetConsoleCP@4
    extern SetConsoleCtrlHandler alias _SetConsoleCtrlHandler@8
    extern SetConsoleCursorInfo alias _SetConsoleCursorInfo@8
    extern SetConsoleCursorPosition alias _SetConsoleCursorPosition@8
    extern SetConsoleMode alias _SetConsoleMode@8
    extern SetConsoleOutputCP alias _SetConsoleOutputCP@4
    extern SetConsoleScreenBufferSize alias _SetConsoleScreenBufferSize@8
    extern SetConsoleTextAttribute alias _SetConsoleTextAttribute@8
    extern SetConsoleTitleA alias _SetConsoleTitleA@4
    extern SetConsoleTitleW alias _SetConsoleTitleW@4
    extern SetConsoleWindowInfo alias _SetConsoleWindowInfo@12
    extern SetCurrentDirectoryA alias _SetCurrentDirectoryA@4
    extern SetCurrentDirectoryW alias _SetCurrentDirectoryW@4
    extern SetDefaultCommConfigA alias _SetDefaultCommConfigA@12
    extern SetDefaultCommConfigW alias _SetDefaultCommConfigW@12
    extern SetEndOfFile alias _SetEndOfFile@4
    extern SetEnvironmentVariableA alias _SetEnvironmentVariableA@8
    extern SetEnvironmentVariableW alias _SetEnvironmentVariableW@8
    extern SetErrorMode alias _SetErrorMode@4
    extern SetEvent alias _SetEvent@4
    extern SetFileApisToANSI alias _SetFileApisToANSI@0
    extern SetFileApisToOEM alias _SetFileApisToOEM@0
    extern SetFileAttributesA alias _SetFileAttributesA@8
    extern SetFileAttributesW alias _SetFileAttributesW@8
    extern SetFilePointer alias _SetFilePointer@16
    extern SetFileTime alias _SetFileTime@16
    extern SetHandleCount alias _SetHandleCount@4
    extern SetHandleInformation alias _SetHandleInformation@12
    extern SetLastError alias _SetLastError@4
    extern SetLocaleInfoA alias _SetLocaleInfoA@12
    extern SetLocaleInfoW alias _SetLocaleInfoW@12
    extern SetLocalTime alias _SetLocalTime@4
    extern SetMailslotInfo alias _SetMailslotInfo@8
    extern SetNamedPipeHandleState alias _SetNamedPipeHandleState@16
    extern SetPriorityClass alias _SetPriorityClass@8
    extern SetProcessShutdownParameters alias _SetProcessShutdownParameters@8
    extern SetProcessWorkingSetSize alias _SetProcessWorkingSetSize@12
    extern SetStdHandle alias _SetStdHandle@8
    extern SetSystemPowerState alias _SetSystemPowerState@8
    extern SetSystemTime alias _SetSystemTime@4
    extern SetSystemTimeAdjustment alias _SetSystemTimeAdjustment@8
    extern SetTapeParameters alias _SetTapeParameters@12
    extern SetTapePosition alias _SetTapePosition@24
    extern SetThreadAffinityMask alias _SetThreadAffinityMask@8
    extern SetThreadContext alias _SetThreadContext@8
    extern SetThreadLocale alias _SetThreadLocale@4
    extern SetThreadPriority alias _SetThreadPriority@8
    extern SetTimeZoneInformation alias _SetTimeZoneInformation@4
    extern SetUnhandledExceptionFilter alias _SetUnhandledExceptionFilter@4
    extern SetupComm alias _SetupComm@12
    extern SetVolumeLabelA alias _SetVolumeLabelA@8
    extern SetVolumeLabelW alias _SetVolumeLabelW@8
    extern SizeofResource alias _SizeofResource@8
    extern Sleep alias _Sleep@4
    extern SleepEx alias _SleepEx@8
    extern SuspendThread alias _SuspendThread@4
    extern SystemTimeToFileTime alias _SystemTimeToFileTime@8
    extern SystemTimeToTzSpecificLocalTime alias _SystemTimeToTzSpecificLocalTime@12
    extern TerminateProcess alias _TerminateProcess@8
    extern TerminateThread alias _TerminateThread@8
    extern Thread32First alias _Thread32First@8
    extern Thread32Next alias _Thread32Next@8
    extern TlsAlloc alias _TlsAlloc@0
    extern TlsFree alias _TlsFree@4
    extern TlsGetValue alias _TlsGetValue@4
    extern TlsSetValue alias _TlsSetValue@8
    extern Toolhelp32ReadProcessMemory alias _Toolhelp32ReadProcessMemory@20
    extern TransactNamedPipe alias _TransactNamedPipe@28
    extern TransmitCommChar alias _TransmitCommChar@8
    extern UnhandledExceptionFilter alias _UnhandledExceptionFilter@4
    extern UnlockFile alias _UnlockFile@20
    extern UnlockFileEx alias _UnlockFileEx@20
    extern UnmapViewOfFile alias _UnmapViewOfFile@4
    extern UpdateResourceA alias _UpdateResourceA@24
    extern UpdateResourceW alias _UpdateResourceW@24
    extern VerLanguageNameA alias _VerLanguageNameA@12
    extern VerLanguageNameW alias _VerLanguageNameW@12
    extern VirtualAlloc alias _VirtualAlloc@16
    extern VirtualFree alias _VirtualFree@12
    extern VirtualLock alias _VirtualLock@8
    extern VirtualProtect alias _VirtualProtect@16
    extern VirtualProtectEx alias _VirtualProtectEx@20
    extern VirtualQuery alias _VirtualQuery@12
    extern VirtualQueryEx alias _VirtualQueryEx@16
    extern VirtualUnlock alias _VirtualUnlock@8
    extern WaitCommEvent alias _WaitCommEvent@12
    extern WaitForDebugEvent alias _WaitForDebugEvent@8
    extern WaitForMultipleObjects alias _WaitForMultipleObjects@16
    extern WaitForMultipleObjectsEx alias _WaitForMultipleObjectsEx@20
    extern WaitForSingleObject alias _WaitForSingleObject@8
    extern WaitForSingleObjectEx alias _WaitForSingleObjectEx@12
    extern WaitNamedPipeA alias _WaitNamedPipeA@8
    extern WaitNamedPipeW alias _WaitNamedPipeW@8
    extern WideCharToMultiByte alias _WideCharToMultiByte@32
    extern WinExec alias _WinExec@8
    extern WriteConsoleA alias _WriteConsoleA@20
    extern WriteConsoleInputA alias _WriteConsoleInputA@16
    extern WriteConsoleInputW alias _WriteConsoleInputW@16
    extern WriteConsoleOutputA alias _WriteConsoleOutputA@20
    extern WriteConsoleOutputAttribute alias _WriteConsoleOutputAttribute@20
    extern WriteConsoleOutputCharacterA alias _WriteConsoleOutputCharacterA@20
    extern WriteConsoleOutputCharacterW alias _WriteConsoleOutputCharacterW@20
    extern WriteConsoleOutputW alias _WriteConsoleOutputW@20
    extern WriteConsoleW alias _WriteConsoleW@20
    extern WriteFile alias _WriteFile@20
    extern WriteFileEx alias _WriteFileEx@20
    extern WritePrivateProfileSectionA alias _WritePrivateProfileSectionA@12
    extern WritePrivateProfileSectionW alias _WritePrivateProfileSectionW@12
    extern WritePrivateProfileStringA alias _WritePrivateProfileStringA@16
    extern WritePrivateProfileStringW alias _WritePrivateProfileStringW@16
    extern WritePrivateProfileStructA alias _WritePrivateProfileStructA@20
    extern WritePrivateProfileStructW alias _WritePrivateProfileStructW@20
    extern WriteProcessMemory alias _WriteProcessMemory@20
    extern WriteProfileSectionA alias _WriteProfileSectionA@8
    extern WriteProfileSectionW alias _WriteProfileSectionW@8
    extern WriteProfileStringA alias _WriteProfileStringA@12
    extern WriteProfileStringW alias _WriteProfileStringW@12
    extern WriteTapemark alias _WriteTapemark@16

    define GetFreeSpace GlobalMemoryStatus

    define LockSegment GlobalFix
    define UnlockSegment GlobalUnfix
    define GetCurrentTime GetTickCount
    define MoveMemory RtlMoveMemory
    define FillMemory RtlFillMemory
    define ZeroMemory RtlZeroMemory

    #if NTDDI_VERSION >= NTDDI_WIN98_ME
        extern CancelDeviceWakeupRequest alias _CancelDeviceWakeupRequest@4
        extern CancelIo alias _CancelIo@4
        extern ConvertThreadToFiber alias _ConvertThreadToFiber@4
        extern CopyFileExA alias _CopyFileExA@24
        extern CopyFileExW alias _CopyFileExW@24
        extern CreateFiber alias _CreateFiber@12
        extern CreateWaitableTimerA alias _CreateWaitableTimerA@12
        extern CreateWaitableTimerW alias _CreateWaitableTimerW@12
        extern DeleteFiber alias _DeleteFiber@4
        extern EnumCalendarInfoExA alias _EnumCalendarInfoExA@16
        extern EnumCalendarInfoExW alias _EnumCalendarInfoExW@16
        extern EnumDateFormatsExA alias _EnumDateFormatsExA@12
        extern EnumDateFormatsExW alias _EnumDateFormatsExW@12
        extern FindFirstFileExA alias _FindFirstFileExA@24
        extern FindFirstFileExW alias _FindFirstFileExW@24
        extern GetCalendarInfoA alias _GetCalendarInfoA@24
        extern GetCalendarInfoW alias _GetCalendarInfoW@24
        extern GetCPInfoExA alias _GetCPInfoExA@12
        extern GetCPInfoExW alias _GetCPInfoExW@12
        extern GetDevicePowerState alias _GetDevicePowerState@8
        extern GetFileAttributesExA alias _GetFileAttributesExA@12
        extern GetFileAttributesExW alias _GetFileAttributesExW@12
        #if NTDDI_VERSION != NTDDI_WINNT4
            extern GetLongPathNameA alias _GetLongPathNameA@12
            extern GetLongPathNameW alias _GetLongPathNameW@12
            extern RequestDeviceWakeup alias _RequestDeviceWakeup@4
            extern RequestWakeupLatency alias _RequestWakeupLatency@4
            extern ResetWriteWatch alias _ResetWriteWatch@8
            extern SetCalendarInfoA alias _SetCalendarInfoA@16
            extern SetCalendarInfoW alias _SetCalendarInfoW@16
            extern SetMessageWaitingIndicator alias _SetMessageWaitingIndicator@8
            #ifdef APP_UNICODE
                define GetLongPathName GetLongPathNameW
                define SetCalendarInfo SetCalendarInfoW
            #else
                define GetLongPathName GetLongPathNameA
                define SetCalendarInfo SetCalendarInfoA
            #endif
        #endif
        extern GetProcessPriorityBoost alias _GetProcessPriorityBoost@8
        extern GetThreadPriorityBoost alias _GetThreadPriorityBoost@8
        extern InterlockedExchangeAdd alias _InterlockedExchangeAdd@8
        extern IsDebuggerPresent alias _IsDebuggerPresent@0
        extern IsProcessorFeaturePresent alias _IsProcessorFeaturePresent@4
        extern IsSystemResumeAutomatic alias _IsSystemResumeAutomatic@0
        extern OpenWaitableTimerA alias _OpenWaitableTimerA@12
        extern OpenWaitableTimerW alias _OpenWaitableTimerW@12
        extern ReadDirectoryChangesW alias _ReadDirectoryChangesW@32
        extern ReadFileScatter alias _ReadFileScatter@20
        extern SetCriticalSectionSpinCount alias _SetCriticalSectionSpinCount@8
        extern SetProcessAffinityMask alias _SetProcessAffinityMask@8
        extern SetProcessPriorityBoost alias _SetProcessPriorityBoost@8
        extern SetThreadExecutionState alias _SetThreadExecutionState@4
        extern SetThreadIdealProcessor alias _SetThreadIdealProcessor@8
        extern SetThreadPriorityBoost alias _SetThreadPriorityBoost@8
        extern SetWaitableTimer alias _SetWaitableTimer@24
        extern SignalObjectAndWait alias _SignalObjectAndWait@16
        extern SwitchToFiber alias _SwitchToFiber@4
        extern SwitchToThread alias _SwitchToThread@0
        extern VirtualAllocEx alias _VirtualAllocEx@20
        extern VirtualFreeEx alias _VirtualFreeEx@16
        extern WriteFileGather alias _WriteFileGather@20
        #ifdef APP_UNICODE
            define CopyFileEx CopyFileExW
            define CreateWaitableTimer CreateWaitableTimerW
            define EnumCalendarInfoEx EnumCalendarInfoExW
            define EnumDateFormatsEx EnumDateFormatsExW
            define FindFirstFileEx FindFirstFileExW
            define GetCalendarInfo GetCalendarInfoW
            define GetCPInfoEx GetCPInfoExW
            define GetFileAttributesEx GetFileAttributesExW
            define OpenWaitableTimer OpenWaitableTimerW
        #else
            define CopyFileEx CopyFileExA
            define CreateWaitableTimer CreateWaitableTimerA
            define EnumCalendarInfoEx EnumCalendarInfoExA
            define EnumDateFormatsEx EnumDateFormatsExA
            define FindFirstFileEx FindFirstFileExA
            define GetCalendarInfo GetCalendarInfoA
            define GetCPInfoEx GetCPInfoExA
            define GetFileAttributesEx GetFileAttributesExA
            define OpenWaitableTimer OpenWaitableTimerA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WINNT4
        extern AddConsoleAliasA alias _AddConsoleAliasA@12
        extern AddConsoleAliasW alias _AddConsoleAliasW@12
        extern ConsoleMenuControl alias _ConsoleMenuControl@12
        extern CreateTimerQueue alias _CreateTimerQueue@0
        extern DuplicateConsoleHandle alias _DuplicateConsoleHandle@16
        extern ExitVDM alias _ExitVDM@8
        extern ExpungeConsoleCommandHistoryA alias _ExpungeConsoleCommandHistoryA@4
        extern ExpungeConsoleCommandHistoryW alias _ExpungeConsoleCommandHistoryW@4
        extern GetConsoleAliasA alias _GetConsoleAliasA@16
        extern GetConsoleAliasesA alias _GetConsoleAliasesA@12
        extern GetConsoleAliasesW alias _GetConsoleAliasesW@12
        extern GetConsoleAliasesLengthA alias _GetConsoleAliasesLengthA@4
        extern GetConsoleAliasesLengthW alias _GetConsoleAliasesLengthW@4
        extern GetConsoleAliasExesA alias _GetConsoleAliasExesA@8
        extern GetConsoleAliasExesW alias _GetConsoleAliasExesW@8
        extern GetConsoleAliasExesLengthA alias _GetConsoleAliasExesLengthA@0
        extern GetConsoleAliasExesLengthW alias _GetConsoleAliasExesLengthW@0
        extern GetConsoleAliasW alias _GetConsoleAliasW@16
        extern GetModuleHandleExA alias _GetModuleHandleExA@12
        extern GetModuleHandleExW alias _GetModuleHandleExW@12
        extern GetNextVDMCommand alias _GetNextVDMCommand@4
        extern GetNumberOfConsoleFonts alias _GetNumberOfConsoleFonts@0
        extern GetProcessIoCounters alias _GetProcessIoCounters@8
        extern GetVDMCurrentDirectories alias _GetVDMCurrentDirectories@8
        extern InvalidateConsoleDIBits alias _InvalidateConsoleDIBits@8
        extern OpenConsoleW alias _OpenConsoleW@16
        extern ReadConsoleInputExA alias _ReadConsoleInputExA@20
        extern ReadConsoleInputExW alias _ReadConsoleInputExW@20
        extern SetConsoleCursor alias _SetConsoleCursor@8
        extern SetConsoleHardwareState alias _SetConsoleHardwareState@8
        extern SetConsoleIcon alias _SetConsoleIcon@4
        extern SetConsoleMaximumWindowSize alias _SetConsoleMaximumWindowSize@8
        extern SetConsoleNumberOfCommandsA alias _SetConsoleNumberOfCommandsA@8
        extern SetConsoleNumberOfCommandsW alias _SetConsoleNumberOfCommandsW@8
        extern SetConsolePalette alias _SetConsolePalette@4
        extern SetLastConsoleEventActive alias _SetLastConsoleEventActive@0
        extern SetVDMCurrentDirectories alias _SetVDMCurrentDirectories@8
        extern ShowConsoleCursor alias _ShowConsoleCursor@8
        extern VerifyVersionInfoA alias _VerifyVersionInfoA@12
        extern VerifyVersionInfoW alias _VerifyVersionInfoW@12
        #ifdef APP_UNICODE
            define AddConsoleAlias AddConsoleAliasW
            define ExpungeConsoleCommandHistory ExpungeConsoleCommandHistoryW
            define GetConsoleAlias GetConsoleAliasW
            define GetConsoleAliasExes GetConsoleAliasExesW
            define GetConsoleAliasExesLength GetConsoleAliasExesLengthW
            define GetConsoleAliases GetConsoleAliasesW
            define GetConsoleAliasesLength GetConsoleAliasesLengthW
            define GetModuleHandleEx GetModuleHandleExW
            define ReadConsoleInputEx ReadConsoleInputExW
            define SetConsoleNumberOfCommands SetConsoleNumberOfCommandsW
            define VerifyVersionInfo VerifyVersionInfoW
        #else
            define AddConsoleAlias AddConsoleAliasA
            define ExpungeConsoleCommandHistory ExpungeConsoleCommandHistoryA
            define GetConsoleAlias GetConsoleAliasA
            define GetConsoleAliasExes GetConsoleAliasExesA
            define GetConsoleAliasExesLength GetConsoleAliasExesLengthA
            define GetConsoleAliases GetConsoleAliasesA
            define GetConsoleAliasesLength GetConsoleAliasesLengthA
            define GetModuleHandleEx GetModuleHandleExA
            define ReadConsoleInputEx ReadConsoleInputExA
            define SetConsoleNumberOfCommands SetConsoleNumberOfCommandsA
            define VerifyVersionInfo VerifyVersionInfoA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WIN2K
        extern AllocateUserPhysicalPages alias _AllocateUserPhysicalPages@12
        extern AssignProcessToJobObject alias _AssignProcessToJobObject@8
        extern BindIoCompletionCallback alias _BindIoCompletionCallback@12
        extern ChangeTimerQueueTimer alias _ChangeTimerQueueTimer@16
        extern CreateHardLinkA alias _CreateHardLinkA@12
        extern CreateHardLinkW alias _CreateHardLinkW@12
        extern CreateJobObjectA alias _CreateJobObjectA@8
        extern CreateJobObjectW alias _CreateJobObjectW@8
        extern CreateTimerQueueTimer alias _CreateTimerQueueTimer@28
        extern DelayLoadFailureHook alias _DelayLoadFailureHook@8
        extern DeleteTimerQueue alias _DeleteTimerQueue@4
        extern DeleteVolumeMountPointA alias _DeleteVolumeMountPointA@4
        extern DeleteVolumeMountPointW alias _DeleteVolumeMountPointW@4
        extern DnsHostnameToComputerNameA alias _DnsHostnameToComputerNameA@12
        extern DnsHostnameToComputerNameW alias _DnsHostnameToComputerNameW@12
        extern DosPathToSessionPathA alias _DosPathToSessionPathA@12
        extern DosPathToSessionPathW alias _DosPathToSessionPathW@12
        extern EnumLanguageGroupLocalesA alias _EnumLanguageGroupLocalesA@16
        extern EnumLanguageGroupLocalesW alias _EnumLanguageGroupLocalesW@16
        extern EnumSystemLanguageGroupsA alias _EnumSystemLanguageGroupsA@12
        extern EnumSystemLanguageGroupsW alias _EnumSystemLanguageGroupsW@12
        extern EnumUILanguagesA alias _EnumUILanguagesA@12
        extern EnumUILanguagesW alias _EnumUILanguagesW@12
        extern FindFirstVolumeA alias _FindFirstVolumeA@8
        extern FindFirstVolumeMountPointA alias _FindFirstVolumeMountPointA@12
        extern FindFirstVolumeMountPointW alias _FindFirstVolumeMountPointW@12
        extern FindFirstVolumeW alias _FindFirstVolumeW@8
        extern FindNextVolumeA alias _FindNextVolumeA@12
        extern FindNextVolumeMountPointA alias _FindNextVolumeMountPointA@12
        extern FindNextVolumeMountPointW alias _FindNextVolumeMountPointW@12
        extern FindNextVolumeW alias _FindNextVolumeW@12
        extern FindVolumeClose alias _FindVolumeClose@4
        extern FindVolumeMountPointClose alias _FindVolumeMountPointClose@4
        extern FreeUserPhysicalPages alias _FreeUserPhysicalPages@12
        extern GetComputerNameExA alias _GetComputerNameExA@12
        extern GetComputerNameExW alias _GetComputerNameExW@12
        extern GetConsoleNlsMode alias _GetConsoleNlsMode@0
        extern GetConsoleWindow alias _GetConsoleWindow@0
        extern GetFileSizeEx alias _GetFileSizeEx@8
        extern GetSystemDefaultUILanguage alias _GetSystemDefaultUILanguage@0
        extern GetSystemWindowsDirectoryA alias _GetSystemWindowsDirectoryA@8
        extern GetSystemWindowsDirectoryW alias _GetSystemWindowsDirectoryW@8
        extern GetUserDefaultUILanguage alias _GetUserDefaultUILanguage@0
        extern GetVolumeNameForVolumeMountPointA alias _GetVolumeNameForVolumeMountPointA@12
        extern GetVolumeNameForVolumeMountPointW alias _GetVolumeNameForVolumeMountPointW@12
        extern GetVolumePathNameA alias _GetVolumePathNameA@12
        extern GetVolumePathNameW alias _GetVolumePathNameW@12
        extern GlobalMemoryStatusEx alias _GlobalMemoryStatusEx@4
        extern IsValidLanguageGroup alias _IsValidLanguageGroup@8
        extern MapUserPhysicalPages alias _MapUserPhysicalPages@12
        extern MapUserPhysicalPagesScatter alias _MapUserPhysicalPagesScatter@12
        extern MoveFileWithProgressA alias _MoveFileWithProgressA@20
        extern MoveFileWithProgressW alias _MoveFileWithProgressW@20
        #if NTDDI_VERSION < NTDDI_VISTA
            extern OpenDataFile alias _OpenDataFile@8
        #endif
        extern OpenJobObjectA alias _OpenJobObjectA@12
        extern OpenJobObjectW alias _OpenJobObjectW@12
        extern OpenThread alias _OpenThread@12
        extern PrivCopyFileExW alias _PrivCopyFileExW@24
        extern ProcessIdToSessionId alias _ProcessIdToSessionId@8
        extern QueryInformationJobObject alias _QueryInformationJobObject@20
        extern RegisterWaitForSingleObject alias _RegisterWaitForSingleObject@24
        extern ReplaceFileA alias _ReplaceFileA@24
        extern ReplaceFileW alias _ReplaceFileW@24
        extern SetComputerNameExA alias _SetComputerNameExA@8
        extern SetComputerNameExW alias _SetComputerNameExW@8
        extern SetConsoleNlsMode alias _SetConsoleNlsMode@8
        extern SetConsoleOS2OemFormat alias _SetConsoleOS2OemFormat@4
        extern SetFilePointerEx alias _SetFilePointerEx@16
        extern SetInformationJobObject alias _SetInformationJobObject@16
        extern SetTermsrvAppInstallMode alias _SetTermsrvAppInstallMode@4
        extern SetTimerQueueTimer alias _SetTimerQueueTimer@24
        extern SetVolumeMountPointA alias _SetVolumeMountPointA@8
        extern SetVolumeMountPointW alias _SetVolumeMountPointW@8
        extern TerminateJobObject alias _TerminateJobObject@8
        extern UnregisterWait alias _UnregisterWait@4
        extern VerSetConditionMask alias _VerSetConditionMask@12
        #ifdef APP_UNICODE
            define CreateHardLink CreateHardLinkW
            define CreateJobObject CreateJobObjectW
            define DeleteVolumeMountPoint DeleteVolumeMountPointW
            define DnsHostnameToComputerName DnsHostnameToComputerNameW
            define DosPathToSessionPath DosPathToSessionPathW
            define EnumLanguageGroupLocales EnumLanguageGroupLocalesW
            define EnumSystemLanguageGroups EnumSystemLanguageGroupsW
            define EnumUILanguages EnumUILanguagesW
            define FindActCtxSectionString FindActCtxSectionStringW
            define FindFirstVolume FindFirstVolumeW
            define FindFirstVolumeMountPoint FindFirstVolumeMountPointW
            define FindNextVolume FindNextVolumeW
            define FindNextVolumeMountPoint FindNextVolumeMountPointW
            define GetComputerNameEx GetComputerNameExW
            define GetSystemWindowsDirectory GetSystemWindowsDirectoryW
            define GetVolumeNameForVolumeMountPoint GetVolumeNameForVolumeMountPointW
            define GetVolumePathName GetVolumePathNameW
            define MoveFileWithProgress MoveFileWithProgressW
            define OpenJobObject OpenJobObjectW
            define ReplaceFile ReplaceFileW
            define SetComputerNameEx SetComputerNameExW
            define SetVolumeMountPoint SetVolumeMountPointW
        #else
            define CreateHardLink CreateHardLinkA
            define CreateJobObject CreateJobObjectA
            define DeleteVolumeMountPoint DeleteVolumeMountPointA
            define DnsHostnameToComputerName DnsHostnameToComputerNameA
            define DosPathToSessionPath DosPathToSessionPathA
            define EnumLanguageGroupLocales EnumLanguageGroupLocalesA
            define EnumSystemLanguageGroups EnumSystemLanguageGroupsA
            define EnumUILanguages EnumUILanguagesA
            define FindActCtxSectionString FindActCtxSectionStringA
            define FindFirstVolume FindFirstVolumeA
            define FindFirstVolumeMountPoint FindFirstVolumeMountPointA
            define FindNextVolume FindNextVolumeA
            define FindNextVolumeMountPoint FindNextVolumeMountPointA
            define GetComputerNameEx GetComputerNameExA
            define GetSystemWindowsDirectory GetSystemWindowsDirectoryA
            define GetVolumeNameForVolumeMountPoint GetVolumeNameForVolumeMountPointA
            define GetVolumePathName GetVolumePathNameA
            define MoveFileWithProgress MoveFileWithProgressA
            define OpenJobObject OpenJobObjectA
            define ReplaceFile ReplaceFileA
            define SetComputerNameEx SetComputerNameExA
            define SetVolumeMountPoint SetVolumeMountPointA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WINXP
        extern ActivateActCtx alias _ActivateActCtx@8
        extern AddLocalAlternateComputerNameA alias _AddLocalAlternateComputerNameA@8
        extern AddLocalAlternateComputerNameW alias _AddLocalAlternateComputerNameW@8
        extern AddRefActCtx alias _AddRefActCtx@4
        extern AddVectoredExceptionHandler alias _AddVectoredExceptionHandler@8
        extern AttachConsole alias _AttachConsole@4
        extern CancelWaitableTimer alias _CancelWaitableTimer@4
        extern ConvertFiberToThread alias _ConvertFiberToThread@0
        extern CreateActCtxA alias _CreateActCtxA@4
        extern CreateActCtxW alias _CreateActCtxW@4
        extern CreateFiberEx alias _CreateFiberEx@20
        extern CreateJobSet alias _CreateJobSet@12
        extern CreateMemoryResourceNotification alias _CreateMemoryResourceNotification@4
        extern CreateProcessInternalA alias _CreateProcessInternalA@40
        extern CreateProcessInternalW alias _CreateProcessInternalW@40
        extern DeactivateActCtx alias _DeactivateActCtx@8
        extern DebugActiveProcessStop alias _DebugActiveProcessStop@4
        extern DebugBreakProcess alias _DebugBreakProcess@4
        extern DebugSetProcessKillOnExit alias _DebugSetProcessKillOnExit@4
        extern DeleteTimerQueueEx alias _DeleteTimerQueueEx@8
        extern DeleteTimerQueueTimer alias _DeleteTimerQueueTimer@12
        extern EnumerateLocalComputerNamesA alias _EnumerateLocalComputerNamesA@16
        extern EnumerateLocalComputerNamesW alias _EnumerateLocalComputerNamesW@16
        extern EnumSystemGeoID alias _EnumSystemGeoID@12
        extern FindActCtxSectionGuid alias _FindActCtxSectionGuid@20
        extern FindActCtxSectionStringA alias _FindActCtxSectionStringA@20
        extern FindActCtxSectionStringW alias _FindActCtxSectionStringW@20
        extern FlsAlloc alias _FlsAlloc@4
        extern FlsFree alias _FlsFree@4
        extern FlsGetValue alias _FlsGetValue@4
        extern FlsSetValue alias _FlsSetValue@8
        extern GetConsoleDisplayMode alias _GetConsoleDisplayMode@4
        extern GetConsoleFontInfo alias _GetConsoleFontInfo@12
        extern GetConsoleFontSize alias _GetConsoleFontSize@8
        extern GetConsoleProcessList alias _GetConsoleProcessList@8
        extern GetConsoleSelectionInfo alias _GetConsoleSelectionInfo@4
        extern GetCurrentActCtx alias _GetCurrentActCtx@4
        extern GetCurrentConsoleFont alias _GetCurrentConsoleFont@12
        extern GetDllDirectoryA alias _GetDllDirectoryA@8
        extern GetDllDirectoryW alias _GetDllDirectoryW@8
        extern GetGeoInfoA alias _GetGeoInfoA@20
        extern GetGeoInfoW alias _GetGeoInfoW@20
        extern GetProcessId alias _GetProcessId@4
        extern GetNativeSystemInfo alias _GetNativeSystemInfo@4
        extern GetSystemWow64DirectoryA alias _GetSystemWow64DirectoryA@8
        extern GetSystemWow64DirectoryW alias _GetSystemWow64DirectoryW@8
        extern GetThreadId alias _GetThreadId@4
        extern GetUserGeoID alias _GetUserGeoID@4
        extern GetVolumePathNamesForVolumeNameA alias _GetVolumePathNamesForVolumeNameA@16
        extern GetVolumePathNamesForVolumeNameW alias _GetVolumePathNamesForVolumeNameW@16
        extern GetWriteWatch alias _GetWriteWatch@24
        extern HeapQueryInformation alias _HeapQueryInformation@20
        extern HeapSetInformation alias _HeapSetInformation@16
        extern InitializeCriticalSectionAndSpinCount alias _InitializeCriticalSectionAndSpinCount@8
        extern InitializeSListHead alias _InitializeSListHead@4
        extern InterlockedFlushSList alias _InterlockedFlushSList@4
        extern InterlockedPopEntrySList alias _InterlockedPopEntrySList@4
        extern InterlockedPushEntrySList alias _InterlockedPushEntrySList@8
        extern IsProcessInJob alias _IsProcessInJob@12
        extern Module32First alias _Module32First@8
        extern Module32FirstW alias _Module32FirstW@8
        extern Module32Next alias _Module32Next@8
        extern Module32NextW alias _Module32NextW@8
        extern Process32First alias _Process32First@8
        extern Process32FirstW alias _Process32FirstW@8
        extern Process32Next alias _Process32Next@8
        extern Process32NextW alias _Process32NextW@8
        extern QueryActCtxW alias _QueryActCtxW@28
        extern QueryDepthSList alias _QueryDepthSList@4
        extern QueryMemoryResourceNotification alias _QueryMemoryResourceNotification@8
        extern QueueUserWorkItem alias _QueueUserWorkItem@12
        extern ReleaseActCtx alias _ReleaseActCtx@4
        extern RemoveVectoredExceptionHandler alias _RemoveVectoredExceptionHandler@4
        #if NTDDI_VERSION >= NTDDI_WIN8
            extern ResolveDelayLoadedAPI alias _ResolveDelayLoadedAPI@24
            extern ResolveDelayLoadsFromDll alias _ResolveDelayLoadsFromDll@12
        #endif
        extern RtlCaptureContext alias _RtlCaptureContext@4
        extern RtlCaptureStackBackTrace alias _RtlCaptureStackBackTrace@16
        extern RtlRaiseException alias _RtlRaiseException@4
        extern SetConsoleDisplayMode alias _SetConsoleDisplayMode@12
        extern SetConsoleFont alias _SetConsoleFont@8
        extern SetFileShortNameA alias _SetFileShortNameA@8
        extern SetFileShortNameW alias _SetFileShortNameW@8
        extern SetFileValidData alias _SetFileValidData@8
        extern SetLocalPrimaryComputerNameA alias _SetLocalPrimaryComputerNameA@8
        extern SetLocalPrimaryComputerNameW alias _SetLocalPrimaryComputerNameW@8
        extern SetThreadUILanguage alias _SetThreadUILanguage@4
        extern SetUserGeoID alias _SetUserGeoID@4
        extern TryEnterCriticalSection alias _TryEnterCriticalSection@4
        extern TzSpecificLocalTimeToSystemTime alias _TzSpecificLocalTimeToSystemTime@12
        extern uaw_lstrcmpiW alias _uaw_lstrcmpiW@8
        extern uaw_lstrcmpW alias _uaw_lstrcmpW@8
        extern uaw_lstrlenW alias _uaw_lstrlenW@4
        extern uaw_wcschr alias _uaw_wcschr@8
        extern uaw_wcscpy alias _uaw_wcscpy@8
        extern uaw_wcsicmp alias _uaw_wcsicmp@8
        extern uaw_wcslen alias _uaw_wcslen@4
        extern uaw_wcsrchr alias _uaw_wcsrchr@8
        extern UnregisterWaitEx alias _UnregisterWaitEx@8
        extern ZombifyActCtx alias _ZombifyActCtx@4

        define CaptureStackBackTrace RtlCaptureStackBackTrace
    #endif

    #if NTDDI_VERSION >= NTDDI_WINXPSP1
        extern CheckNameLegalDOS8Dot3A alias _CheckNameLegalDOS8Dot3A@20
        extern CheckNameLegalDOS8Dot3W alias _CheckNameLegalDOS8Dot3W@20
        extern CheckRemoteDebuggerPresent alias _CheckRemoteDebuggerPresent@8
        extern ConvertThreadToFiberEx alias _ConvertThreadToFiberEx@8
        extern GetFirmwareEnvironmentVariableA alias _GetFirmwareEnvironmentVariableA@16
        extern GetFirmwareEnvironmentVariableW alias _GetFirmwareEnvironmentVariableW@16
        extern GetProcessHandleCount alias _GetProcessHandleCount@8
        extern GetSystemRegistryQuota alias _GetSystemRegistryQuota@8
        extern GetSystemTimes alias _GetSystemTimes@12
        extern GetThreadIOPendingFlag alias _GetThreadIOPendingFlag@8
        extern SetFirmwareEnvironmentVariableA alias _SetFirmwareEnvironmentVariableA@16
        extern SetFirmwareEnvironmentVariableW alias _SetFirmwareEnvironmentVariableW@16
        #ifdef APP_UNICODE
            define CheckNameLegalDOS8Dot3 CheckNameLegalDOS8Dot3W
            define GetFirmwareEnvironmentVariable GetFirmwareEnvironmentVariableW
            define SetFirmwareEnvironmentVariable SetFirmwareEnvironmentVariableW
        #else
            define CheckNameLegalDOS8Dot3 CheckNameLegalDOS8Dot3A
            define GetFirmwareEnvironmentVariable GetFirmwareEnvironmentVariableA
            define SetFirmwareEnvironmentVariable SetFirmwareEnvironmentVariableA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WINXPSP2
        extern GetNumaAvailableMemoryNode alias _GetNumaAvailableMemoryNode@8
        extern GetNumaNodeProcessorMask alias _GetNumaNodeProcessorMask@8
        extern GetNumaProcessorNode alias _GetNumaProcessorNode@8
    #endif

    #if NTDDI_VERSION >= NTDDI_WINXPSP2
        extern DecodePointer alias _DecodePointer@4
        extern DecodeSystemPointer alias _DecodeSystemPointer@4
        extern EncodePointer alias _EncodePointer@4
        extern EncodeSystemPointer alias _EncodeSystemPointer@4
        extern IsWow64Process alias _IsWow64Process@8
    #endif

    #if NTDDI_VERSION >= NTDDI_WS03
        extern FindFirstStreamW alias _FindFirstStreamW@16
        extern FindNextStreamW alias _FindNextStreamW@8
        extern GetLargePageMinimum alias _GetLargePageMinimum@0
        extern GetProcessIdOfThread alias _GetProcessIdOfThread@4
        extern GetProcessWorkingSetSizeEx alias _GetProcessWorkingSetSizeEx@16
        extern ReOpenFile alias _ReOpenFile@16
        extern SetDllDirectoryA alias _SetDllDirectoryA@4
        extern SetDllDirectoryW alias _SetDllDirectoryW@4
        extern SetEnvironmentStringsA alias _SetEnvironmentStringsA@4
        extern SetEnvironmentStringsW alias _SetEnvironmentStringsW@4
        extern SetProcessWorkingSetSizeEx alias _SetProcessWorkingSetSizeEx@16
        extern Wow64EnableWow64FsRedirection alias _Wow64EnableWow64FsRedirection@4
        extern WTSGetActiveConsoleSessionId alias _WTSGetActiveConsoleSessionId@0
        #ifdef APP_UNICODE
            define SetDllDirectory SetDllDirectoryW
            define SetEnvironmentStrings SetEnvironmentStringsW
        #else
            define SetDllDirectory SetDllDirectoryA
            define SetEnvironmentStrings SetEnvironmentStringsA
        #endif
    #endif

    #if NTDDI_VERSION <= NTDDI_VISTA
        extern InterlockedCompareExchange alias _InterlockedCompareExchange@12
        ;extern InterlockedCompareExchange64 alias _InterlockedCompareExchange64@12
        extern InterlockedDecrement alias _InterlockedDecrement@4
        extern InterlockedExchange alias _InterlockedExchange@8
        extern InterlockedIncrement alias _InterlockedIncrement@4
    #endif

    #if NTDDI_VERSION >= NTDDI_VISTA
        extern AcquireSRWLockExclusive alias _AcquireSRWLockExclusive@4
        extern AcquireSRWLockShared alias _AcquireSRWLockShared@4
        extern AddDllDirectory alias _AddDllDirectory@4
        extern AddSIDToBoundaryDescriptor alias _AddSIDToBoundaryDescriptor@8
        extern AddVectoredContinueHandler alias _AddVectoredContinueHandler@8
        extern AdjustCalendarDate alias _AdjustCalendarDate@8
        extern AllocateUserPhysicalPagesNuma alias _AllocateUserPhysicalPagesNuma@16
        extern ApplicationRecoveryFinished alias _ApplicationRecoveryFinished@4
        extern ApplicationRecoveryInProgress alias _ApplicationRecoveryInProgress@4
        extern CallbackMayRunLong alias _CallbackMayRunLong@4
        extern CancelIoEx alias _CancelIoEx@8
        extern CancelSynchronousIo alias _CancelSynchronousIo@4
        extern CancelThreadpoolIo alias _CancelThreadpoolIo@4
        extern CheckElevationEnabled alias _CheckElevationEnabled@4
        extern ClosePrivateNamespace alias _ClosePrivateNamespace@8
        extern CloseThreadpool alias _CloseThreadpool@4
        extern CloseThreadpoolCleanupGroup alias _CloseThreadpoolCleanupGroup@4
        extern CloseThreadpoolCleanupGroupMembers alias _CloseThreadpoolCleanupGroupMembers@12
        extern CloseThreadpoolIo alias _CloseThreadpoolIo@4
        extern CloseThreadpoolTimer alias _CloseThreadpoolTimer@4
        extern CloseThreadpoolWait alias _CloseThreadpoolWait@4
        extern CloseThreadpoolWork alias _CloseThreadpoolWork@4
        extern CompareStringEx alias _CompareStringEx@36
        extern CompareStringOrdinal alias _CompareStringOrdinal@20
        extern ConvertCalDateTimeToSystemTime alias _ConvertCalDateTimeToSystemTime@8
        extern ConvertSystemTimeToCalDateTime alias _ConvertSystemTimeToCalDateTime@12
        extern CopyFileTransactedA alias _CopyFileTransactedA@28
        extern CopyFileTransactedW alias _CopyFileTransactedW@28
        extern CreateBoundaryDescriptorA alias _CreateBoundaryDescriptorA@8
        extern CreateBoundaryDescriptorW alias _CreateBoundaryDescriptorW@8
        extern CreateDirectoryTransactedA alias _CreateDirectoryTransactedA@16
        extern CreateDirectoryTransactedW alias _CreateDirectoryTransactedW@16
        extern CreateEventExA alias _CreateEventExA@16
        extern CreateEventExW alias _CreateEventExW@16
        extern CreateFileMappingNumaA alias _CreateFileMappingNumaA@28
        extern CreateFileMappingNumaW alias _CreateFileMappingNumaW@28
        extern CreateFileTransactedA alias _CreateFileTransactedA@40
        extern CreateFileTransactedW alias _CreateFileTransactedW@40
        extern CreateHardLinkTransactedA alias _CreateHardLinkTransactedA@16
        extern CreateHardLinkTransactedW alias _CreateHardLinkTransactedW@16
        extern CreateMutexExA alias _CreateMutexExA@16
        extern CreateMutexExW alias _CreateMutexExW@16
        extern CreatePrivateNamespaceA alias _CreatePrivateNamespaceA@12
        extern CreatePrivateNamespaceW alias _CreatePrivateNamespaceW@12
        extern CreateSemaphoreExA alias _CreateSemaphoreExA@24
        extern CreateSemaphoreExW alias _CreateSemaphoreExW@24
        extern CreateSymbolicLinkA alias _CreateSymbolicLinkA@12
        extern CreateSymbolicLinkTransactedA alias _CreateSymbolicLinkTransactedA@16
        extern CreateSymbolicLinkTransactedW alias _CreateSymbolicLinkTransactedW@16
        extern CreateSymbolicLinkW alias _CreateSymbolicLinkW@12
        extern CreateThreadpool alias _CreateThreadpool@4
        extern CreateThreadpoolCleanupGroup alias _CreateThreadpoolCleanupGroup@0
        extern CreateThreadpoolIo alias _CreateThreadpoolIo@16
        extern CreateThreadpoolTimer alias _CreateThreadpoolTimer@12
        extern CreateThreadpoolWait alias _CreateThreadpoolWait@12
        extern CreateThreadpoolWork alias _CreateThreadpoolWork@12
        extern CreateWaitableTimerExA alias _CreateWaitableTimerExA@16
        extern CreateWaitableTimerExW alias _CreateWaitableTimerExW@16
        extern DeleteBoundaryDescriptor alias _DeleteBoundaryDescriptor@4
        extern DeleteFileTransactedA alias _DeleteFileTransactedA@8
        extern DeleteFileTransactedW alias _DeleteFileTransactedW@8
        extern DeleteProcThreadAttributeList alias _DeleteProcThreadAttributeList@4
        extern DisassociateCurrentThreadFromCallback alias _DisassociateCurrentThreadFromCallback@4
        extern EnumCalendarInfoExEx alias _EnumCalendarInfoExEx@24
        extern EnumDateFormatsExEx alias _EnumDateFormatsExEx@16
        extern EnumResourceLanguagesExA alias _EnumResourceLanguagesExA@28
        extern EnumResourceLanguagesExW alias _EnumResourceLanguagesExW@28
        extern EnumResourceNamesExA alias _EnumResourceNamesExA@24
        extern EnumResourceNamesExW alias _EnumResourceNamesExW@24
        extern EnumResourceTypesExA alias _EnumResourceTypesExA@20
        extern EnumResourceTypesExW alias _EnumResourceTypesExW@20
        extern EnumSystemLocalesEx alias _EnumSystemLocalesEx@16
        extern EnumTimeFormatsEx alias _EnumTimeFormatsEx@16
        extern FindFirstFileNameTransactedW alias _FindFirstFileNameTransactedW@20
        extern FindFirstFileNameW alias _FindFirstFileNameW@16
        extern FindFirstFileTransactedA alias _FindFirstFileTransactedA@28
        extern FindFirstFileTransactedW alias _FindFirstFileTransactedW@28
        extern FindFirstStreamTransactedW alias _FindFirstStreamTransactedW@20
        extern FindNextFileNameW alias _FindNextFileNameW@12
        extern FindNLSString alias _FindNLSString@28
        extern FindNLSStringEx alias _FindNLSStringEx@40
        extern FlushProcessWriteBuffers alias _FlushProcessWriteBuffers@0
        extern FreeLibraryWhenCallbackReturns alias _FreeLibraryWhenCallbackReturns@8
        extern GetApplicationRecoveryCallback alias _GetApplicationRecoveryCallback@20
        extern GetApplicationRestartSettings alias _GetApplicationRestartSettings@16
        extern GetCalendarDateFormatEx alias _GetCalendarDateFormatEx@24
        extern GetCalendarInfoEx alias _GetCalendarInfoEx@28
        extern GetCalendarSupportedDateRange alias _GetCalendarSupportedDateRange@12
        extern GetComPlusPackageInstallStatus alias _GetComPlusPackageInstallStatus@0
        extern GetCompressedFileSizeTransactedA alias _GetCompressedFileSizeTransactedA@12
        extern GetCompressedFileSizeTransactedW alias _GetCompressedFileSizeTransactedW@12
        extern GetConsoleHistoryInfo alias _GetConsoleHistoryInfo@4
        extern GetConsoleOriginalTitleA alias _GetConsoleOriginalTitleA@8
        extern GetConsoleOriginalTitleW alias _GetConsoleOriginalTitleW@8
        extern GetConsoleScreenBufferInfoEx alias _GetConsoleScreenBufferInfoEx@8
        extern GetCurrencyFormatEx alias _GetCurrencyFormatEx@24
        extern GetCurrentConsoleFontEx alias _GetCurrentConsoleFontEx@12
        extern GetCurrentProcessorNumber alias _GetCurrentProcessorNumber@0
        extern GetDateFormatEx alias _GetDateFormatEx@28
        extern GetDurationFormat alias _GetDurationFormat@28
        extern GetDurationFormatEx alias _GetDurationFormatEx@28
        extern GetDynamicTimeZoneInformation alias _GetDynamicTimeZoneInformation@4
        extern GetFileAttributesTransactedA alias _GetFileAttributesTransactedA@16
        extern GetFileAttributesTransactedW alias _GetFileAttributesTransactedW@16
        extern GetFileBandwidthReservation alias _GetFileBandwidthReservation@24
        extern GetFileInformationByHandleEx alias _GetFileInformationByHandleEx@16
        extern GetFileMUIInfo alias _GetFileMUIInfo@16
        extern GetFileMUIPath alias _GetFileMUIPath@28
        extern GetFinalPathNameByHandleA alias _GetFinalPathNameByHandleA@16
        extern GetFinalPathNameByHandleW alias _GetFinalPathNameByHandleW@16
        extern GetFullPathNameTransactedA alias _GetFullPathNameTransactedA@20
        extern GetFullPathNameTransactedW alias _GetFullPathNameTransactedW@20
        extern GetLocaleInfoEx alias _GetLocaleInfoEx@16
        extern GetLongPathNameTransactedA alias _GetLongPathNameTransactedA@16
        extern GetLongPathNameTransactedW alias _GetLongPathNameTransactedW@16
        extern GetNamedPipeAttribute alias _GetNamedPipeAttribute@20
        extern GetNamedPipeClientComputerNameA alias _GetNamedPipeClientComputerNameA@12
        extern GetNamedPipeClientComputerNameW alias _GetNamedPipeClientComputerNameW@12
        extern GetNamedPipeClientProcessId alias _GetNamedPipeClientProcessId@8
        extern GetNamedPipeClientSessionId alias _GetNamedPipeClientSessionId@8
        extern GetNamedPipeServerProcessId alias _GetNamedPipeServerProcessId@8
        extern GetNamedPipeServerSessionId alias _GetNamedPipeServerSessionId@8
        extern GetNLSVersion alias _GetNLSVersion@12
        extern GetNLSVersionEx alias _GetNLSVersionEx@12
        extern GetNumaProximityNode alias _GetNumaProximityNode@8
        extern GetNumberFormatEx alias _GetNumberFormatEx@24
        extern GetProductInfo alias _GetProductInfo@20
        extern GetQueuedCompletionStatusEx alias _GetQueuedCompletionStatusEx@24
        extern GetStringScripts alias _GetStringScripts@20
        extern GetSystemDefaultLocaleName alias _GetSystemDefaultLocaleName@8
        extern GetSystemPreferredUILanguages alias _GetSystemPreferredUILanguages@16
        extern GetThreadPreferredUILanguages alias _GetThreadPreferredUILanguages@16
        extern GetThreadUILanguage alias _GetThreadUILanguage@0
        extern GetTickCount64 alias _GetTickCount64@0
        extern GetTimeFormatEx alias _GetTimeFormatEx@24
        extern GetUILanguageInfo alias _GetUILanguageInfo@20
        extern GetUserDefaultLocaleName alias _GetUserDefaultLocaleName@8
        extern GetUserPreferredUILanguages alias _GetUserPreferredUILanguages@16
        extern GetVolumeInformationByHandleW alias _GetVolumeInformationByHandleW@32
        extern IdnToAscii alias _IdnToAscii@20
        extern IdnToNameprepUnicode alias _IdnToNameprepUnicode@20
        extern IdnToUnicode alias _IdnToUnicode@20
        extern InitOnceBeginInitialize alias _InitOnceBeginInitialize@16
        extern InitOnceComplete alias _InitOnceComplete@12
        extern InitOnceExecuteOnce alias _InitOnceExecuteOnce@16
        extern InitOnceInitialize alias _InitOnceInitialize@4
        extern InitializeConditionVariable alias _InitializeConditionVariable@4
        extern InitializeCriticalSectionEx alias _InitializeCriticalSectionEx@12
        extern InitializeProcThreadAttributeList alias _InitializeProcThreadAttributeList@16
        extern InitializeSRWLock alias _InitializeSRWLock@4
        extern InterlockedPushListSList alias _InterlockedPushListSList@16
        extern IsCalendarLeapDay alias _IsCalendarLeapDay@20
        extern IsCalendarLeapMonth alias _IsCalendarLeapMonth@16
        extern IsCalendarLeapYear alias _IsCalendarLeapYear@12
        extern IsNLSDefinedString alias _IsNLSDefinedString@20
        extern IsNormalizedString alias _IsNormalizedString@12
        extern IsThreadAFiber alias _IsThreadAFiber@0
        extern IsThreadpoolTimerSet alias _IsThreadpoolTimerSet@4
        #if NTDDI_VERSION != NTDDI_WIN81
            extern IsTimeZoneRedirectionEnabled alias _IsTimeZoneRedirectionEnabled@0
        #endif
        extern IsValidCalDateTime alias _IsValidCalDateTime@8
        extern IsValidLocaleName alias _IsValidLocaleName@4
        extern LCIDToLocaleName alias _LCIDToLocaleName@16
        extern LCMapStringEx alias _LCMapStringEx@36
        extern LeaveCriticalSectionWhenCallbackReturns alias _LeaveCriticalSectionWhenCallbackReturns@8
        extern LoadStringBaseExW alias _LoadStringBaseExW@20
        extern LoadStringBaseW alias _LoadStringBaseW@16
        extern LocaleNameToLCID alias _LocaleNameToLCID@8
        extern MapViewOfFileExNuma alias _MapViewOfFileExNuma@28
        extern MoveFileTransactedA alias _MoveFileTransactedA@24
        extern MoveFileTransactedW alias _MoveFileTransactedW@24
        extern NeedCurrentDirectoryForExePathA alias _NeedCurrentDirectoryForExePathA@4
        extern NeedCurrentDirectoryForExePathW alias _NeedCurrentDirectoryForExePathW@4
        extern NormalizeString alias _NormalizeString@20
        extern OpenFileById alias _OpenFileById@24
        extern OpenPrivateNamespaceA alias _OpenPrivateNamespaceA@8
        extern OpenPrivateNamespaceW alias _OpenPrivateNamespaceW@8
        extern QueryActCtxSettingsW alias _QueryActCtxSettingsW@28
        extern QueryFullProcessImageNameA alias _QueryFullProcessImageNameA@16
        extern QueryFullProcessImageNameW alias _QueryFullProcessImageNameW@16
        extern QueryIdleProcessorCycleTime alias _QueryIdleProcessorCycleTime@8
        extern QueryProcessCycleTime alias _QueryProcessCycleTime@8
        extern QueryThreadCycleTime alias _QueryThreadCycleTime@8
        extern RegisterApplicationRecoveryCallback alias _RegisterApplicationRecoveryCallback@16
        extern RegisterApplicationRestart alias _RegisterApplicationRestart@8
        extern ReleaseMutexWhenCallbackReturns alias _ReleaseMutexWhenCallbackReturns@8
        extern ReleaseSRWLockExclusive alias _ReleaseSRWLockExclusive@4
        extern ReleaseSRWLockShared alias _ReleaseSRWLockShared@4
        extern ReleaseSemaphoreWhenCallbackReturns alias _ReleaseSemaphoreWhenCallbackReturns@12
        extern RemoveDirectoryTransactedA alias _RemoveDirectoryTransactedA@8
        extern RemoveDirectoryTransactedW alias _RemoveDirectoryTransactedW@8
        extern RemoveDllDirectory alias _RemoveDllDirectory@4
        extern ReplacePartitionUnit alias _ReplacePartitionUnit@12
        extern SetConsoleHistoryInfo alias _SetConsoleHistoryInfo@4
        extern SetConsoleScreenBufferInfoEx alias _SetConsoleScreenBufferInfoEx@8
        extern SetCurrentConsoleFontEx alias _SetCurrentConsoleFontEx@12
        extern SetDefaultDllDirectories alias _SetDefaultDllDirectories@4
        extern SetDynamicTimeZoneInformation alias _SetDynamicTimeZoneInformation@4
        extern SetEventWhenCallbackReturns alias _SetEventWhenCallbackReturns@8
        extern SetFileAttributesTransactedA alias _SetFileAttributesTransactedA@12
        extern SetFileAttributesTransactedW alias _SetFileAttributesTransactedW@12
        extern SetFileBandwidthReservation alias _SetFileBandwidthReservation@24
        extern SetFileCompletionNotificationModes alias _SetFileCompletionNotificationModes@8
        extern SetFileInformationByHandle alias _SetFileInformationByHandle@16
        extern SetFileIoOverlappedRange alias _SetFileIoOverlappedRange@12
        extern SetNamedPipeAttribute alias _SetNamedPipeAttribute@20
        extern SetThreadpoolThreadMaximum alias _SetThreadpoolThreadMaximum@8
        extern SetThreadpoolThreadMinimum alias _SetThreadpoolThreadMinimum@8
        extern SetThreadpoolTimer alias _SetThreadpoolTimer@16
        extern SetThreadpoolWait alias _SetThreadpoolWait@12
        #if NTDDI_VERSION >= NTDDI_WIN8
            extern SetThreadpoolWaitEx alias _SetThreadpoolWaitEx@12
        #endif
        extern SetThreadPreferredUILanguages alias _SetThreadPreferredUILanguages@12
        extern SleepConditionVariableCS alias _SleepConditionVariableCS@12
        extern SleepConditionVariableSRW alias _SleepConditionVariableSRW@16
        extern StartThreadpoolIo alias _StartThreadpoolIo@4
        extern SubmitThreadpoolWork alias _SubmitThreadpoolWork@4
        extern TrySubmitThreadpoolCallback alias _TrySubmitThreadpoolCallback@12
        extern UnregisterApplicationRecoveryCallback alias _UnregisterApplicationRecoveryCallback@0
        extern UnregisterApplicationRestart alias _UnregisterApplicationRestart@0
        extern UpdateCalendarDayOfWeek alias _UpdateCalendarDayOfWeek@4
        extern UpdateProcThreadAttribute alias _UpdateProcThreadAttribute@28
        extern VerifyScripts alias _VerifyScripts@20
        extern VirtualAllocExNuma alias _VirtualAllocExNuma@24
        extern WaitForThreadpoolIoCallbacks alias _WaitForThreadpoolIoCallbacks@8
        extern WaitForThreadpoolTimerCallbacks alias _WaitForThreadpoolTimerCallbacks@8
        extern WaitForThreadpoolWaitCallbacks alias _WaitForThreadpoolWaitCallbacks@8
        extern WaitForThreadpoolWorkCallbacks alias _WaitForThreadpoolWorkCallbacks@8
        extern WakeAllConditionVariable alias _WakeAllConditionVariable@4
        extern WakeConditionVariable alias _WakeConditionVariable@4
        extern WerGetFlags alias _WerGetFlags@8
        extern WerRegisterFile alias _WerRegisterFile@12
        extern WerRegisterMemoryBlock alias _WerRegisterMemoryBlock@8
        extern WerSetFlags alias _WerSetFlags@4
        extern WerUnregisterFile alias _WerUnregisterFile@4
        extern WerUnregisterMemoryBlock alias _WerUnregisterMemoryBlock@4
        extern Wow64GetThreadContext alias _Wow64GetThreadContext@8
        extern Wow64SetThreadContext alias _Wow64SetThreadContext@8
        extern Wow64SuspendThread alias _Wow64SuspendThread@4
        #ifdef APP_UNICODE
            define CopyFileTransacted CopyFileTransactedW
            define CreateBoundaryDescriptor CreateBoundaryDescriptorW
            define CreateDirectoryTransacted CreateDirectoryTransactedW
            define CreateEventEx CreateEventExW
            define CreateFileMappingNuma CreateFileMappingNumaW
            define CreateFileTransacted CreateFileTransactedW
            define CreateHardLinkTransacted CreateHardLinkTransactedW
            define CreateMutexEx CreateMutexExW
            define CreatePrivateNamespace CreatePrivateNamespaceW
            define CreateSemaphoreEx CreateSemaphoreExW
            define CreateSymbolicLink CreateSymbolicLinkW
            define CreateSymbolicLinkTransacted CreateSymbolicLinkTransactedW
            define CreateWaitableTimerEx CreateWaitableTimerExW
            define DeleteFileTransacted DeleteFileTransactedW
            define EnumResourceLanguagesEx EnumResourceLanguagesExW
            define EnumResourceNamesEx EnumResourceNamesExW
            define EnumResourceTypesEx EnumResourceTypesExW
            define FindFirstFileTransacted FindFirstFileTransactedW
            define GetCompressedFileSizeTransacted GetCompressedFileSizeTransactedW
            define GetConsoleOriginalTitle GetConsoleOriginalTitleW
            define GetFileAttributesTransacted GetFileAttributesTransactedW
            define GetFinalPathNameByHandle GetFinalPathNameByHandleW
            define GetFullPathNameTransacted GetFullPathNameTransactedW
            define GetLongPathNameTransacted GetLongPathNameTransactedW
            define GetNamedPipeClientComputerName GetNamedPipeClientComputerNameW
            define MoveFileTransacted MoveFileTransactedW
            define NeedCurrentDirectoryForExePath NeedCurrentDirectoryForExePathW
            define OpenPrivateNamespace OpenPrivateNamespaceW
            define QueryFullProcessImageName QueryFullProcessImageNameW
            define RemoveDirectoryTransacted RemoveDirectoryTransactedW
            define SetFileAttributesTransacted SetFileAttributesTransactedW
        #else
            define CopyFileTransacted CopyFileTransactedA
            define CreateBoundaryDescriptor CreateBoundaryDescriptorA
            define CreateDirectoryTransacted CreateDirectoryTransactedA
            define CreateEventEx CreateEventExA
            define CreateFileMappingNuma CreateFileMappingNumaA
            define CreateFileTransacted CreateFileTransactedA
            define CreateHardLinkTransacted CreateHardLinkTransactedA
            define CreateMutexEx CreateMutexExA
            define CreatePrivateNamespace CreatePrivateNamespaceA
            define CreateSemaphoreEx CreateSemaphoreExA
            define CreateSymbolicLink CreateSymbolicLinkA
            define CreateSymbolicLinkTransacted CreateSymbolicLinkTransactedA
            define CreateWaitableTimerEx CreateWaitableTimerExA
            define DeleteFileTransacted DeleteFileTransactedA
            define EnumResourceLanguagesEx EnumResourceLanguagesExA
            define EnumResourceNamesEx EnumResourceNamesExA
            define EnumResourceTypesEx EnumResourceTypesExA
            define FindFirstFileTransacted FindFirstFileTransactedA
            define GetCompressedFileSizeTransacted GetCompressedFileSizeTransactedA
            define GetConsoleOriginalTitle GetConsoleOriginalTitleA
            define GetFileAttributesTransacted GetFileAttributesTransactedA
            define GetFinalPathNameByHandle GetFinalPathNameByHandleA
            define GetFullPathNameTransacted GetFullPathNameTransactedA
            define GetLongPathNameTransacted GetLongPathNameTransactedA
            define GetNamedPipeClientComputerName GetNamedPipeClientComputerNameA
            define MoveFileTransacted MoveFileTransactedA
            define NeedCurrentDirectoryForExePath NeedCurrentDirectoryForExePathA
            define OpenPrivateNamespace OpenPrivateNamespaceA
            define QueryFullProcessImageName QueryFullProcessImageNameA
            define RemoveDirectoryTransacted RemoveDirectoryTransactedA
            define SetFileAttributesTransacted SetFileAttributesTransactedA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_VISTASP1
        extern AddSecureMemoryCacheCallback alias _AddSecureMemoryCacheCallback@4
        extern GetPhysicallyInstalledSystemMemory alias _GetPhysicallyInstalledSystemMemory@4
        extern GetTimeZoneInformationForYear alias _GetTimeZoneInformationForYear@12
        extern QueryProcessAffinityUpdateMode alias _QueryProcessAffinityUpdateMode@8
        extern RemoveSecureMemoryCacheCallback alias _RemoveSecureMemoryCacheCallback@4
        extern SetProcessAffinityUpdateMode alias _SetProcessAffinityUpdateMode@8
    #endif

    #if NTDDI_VERSION >= NTDDI_WIN7
        extern AddIntegrityLabelToBoundaryDescriptor alias _AddIntegrityLabelToBoundaryDescriptor@8
        extern BaseFormatTimeOut alias _BaseFormatTimeOut@8
        extern BaseGetNamedObjectDirectory alias _BaseGetNamedObjectDirectory@4
        extern Basep8BitStringToDynamicUnicodeString alias _Basep8BitStringToDynamicUnicodeString@8
        extern CreateRemoteThreadEx alias _CreateRemoteThreadEx@32
        extern DisableThreadProfiling alias _DisableThreadProfiling@4
        extern EnableThreadProfiling alias _EnableThreadProfiling@16
        extern FindStringOrdinal alias _FindStringOrdinal@24
        extern GetActiveProcessorCount alias _GetActiveProcessorCount@4
        extern GetActiveProcessorGroupCount alias _GetActiveProcessorGroupCount@0
        extern GetCurrentProcessorNumberEx alias _GetCurrentProcessorNumberEx@4
        extern GetLogicalProcessorInformationEx alias _GetLogicalProcessorInformationEx@12
        extern GetMaximumProcessorCount alias _GetMaximumProcessorCount@4
        extern GetMaximumProcessorGroupCount alias _GetMaximumProcessorGroupCount@0
        extern GetNumaAvailableMemoryNodeEx alias _GetNumaAvailableMemoryNodeEx@8
        extern GetNumaNodeNumberFromHandle alias _GetNumaNodeNumberFromHandle@8
        extern GetNumaNodeProcessorMaskEx alias _GetNumaNodeProcessorMaskEx@8
        extern GetNumaProcessorNodeEx alias _GetNumaProcessorNodeEx@8
        extern GetNumaProximityNodeEx alias _GetNumaProximityNodeEx@8
        extern GetProcessGroupAffinity alias _GetProcessGroupAffinity@12
        extern GetProcessorSystemCycleTime alias _GetProcessorSystemCycleTime@12
        extern GetProcessPreferredUILanguages alias _GetProcessPreferredUILanguages@16
        extern GetProcessUserModeExceptionPolicy alias _GetProcessUserModeExceptionPolicy@4
        extern GetThreadErrorMode alias _GetThreadErrorMode@0
        extern GetThreadGroupAffinity alias _GetThreadGroupAffinity@8
        extern GetThreadIdealProcessorEx alias _GetThreadIdealProcessorEx@8
        extern K32EmptyWorkingSet alias _K32EmptyWorkingSet@4
        extern K32EnumDeviceDrivers alias _K32EnumDeviceDrivers@12
        extern K32EnumPageFilesA alias _K32EnumPageFilesA@8
        extern K32EnumPageFilesW alias _K32EnumPageFilesW@8
        extern K32EnumProcessModules alias _K32EnumProcessModules@16
        extern K32EnumProcessModulesEx alias _K32EnumProcessModulesEx@20
        extern K32EnumProcesses alias _K32EnumProcesses@12
        extern K32GetDeviceDriverBaseNameA alias _K32GetDeviceDriverBaseNameA@12
        extern K32GetDeviceDriverBaseNameW alias _K32GetDeviceDriverBaseNameW@12
        extern K32GetDeviceDriverFileNameA alias _K32GetDeviceDriverFileNameA@12
        extern K32GetDeviceDriverFileNameW alias _K32GetDeviceDriverFileNameW@12
        extern K32GetMappedFileNameA alias _K32GetMappedFileNameA@16
        extern K32GetMappedFileNameW alias _K32GetMappedFileNameW@16
        extern K32GetModuleBaseNameA alias _K32GetModuleBaseNameA@16
        extern K32GetModuleBaseNameW alias _K32GetModuleBaseNameW@16
        extern K32GetModuleFileNameExA alias _K32GetModuleFileNameExA@16
        extern K32GetModuleFileNameExW alias _K32GetModuleFileNameExW@16
        extern K32GetModuleInformation alias _K32GetModuleInformation@16
        extern K32GetPerformanceInfo alias _K32GetPerformanceInfo@8
        extern K32GetProcessImageFileNameA alias _K32GetProcessImageFileNameA@12
        extern K32GetProcessImageFileNameW alias _K32GetProcessImageFileNameW@12
        extern K32GetProcessMemoryInfo alias _K32GetProcessMemoryInfo@12
        extern K32GetWsChanges alias _K32GetWsChanges@12
        extern K32GetWsChangesEx alias _K32GetWsChangesEx@12
        extern K32InitializeProcessForWsWatch alias _K32InitializeProcessForWsWatch@4
        extern K32QueryWorkingSet alias _K32QueryWorkingSet@12
        extern K32QueryWorkingSetEx alias _K32QueryWorkingSetEx@12
        extern LoadAppInitDlls alias _LoadAppInitDlls@0
        extern NotifyUILanguageChange alias _NotifyUILanguageChange@20
        extern PowerClearRequest alias _PowerClearRequest@8
        extern PowerCreateRequest alias _PowerCreateRequest@4
        extern PowerSetRequest alias _PowerSetRequest@8
        extern QueryIdleProcessorCycleTimeEx alias _QueryIdleProcessorCycleTimeEx@12
        extern QueryThreadProfiling alias _QueryThreadProfiling@8
        extern QueryThreadpoolStackInformation alias _QueryThreadpoolStackInformation@8
        extern QueryUnbiasedInterruptTime alias _QueryUnbiasedInterruptTime@4
        extern RaiseFailFastException alias _RaiseFailFastException@12
        extern ReadThreadProfilingData alias _ReadThreadProfilingData@12
        extern RegCloseKey alias _RegCloseKey@4
        extern ResolveLocaleName alias _ResolveLocaleName@12
        extern RtlCompareMemory alias _RtlCompareMemory@12
        extern RtlCopyMemory alias _RtlCopyMemory@12
        extern SetProcessPreferredUILanguages alias _SetProcessPreferredUILanguages@12
        #if NTDDI_VERSION < NTDDI_WIN8
            extern SetProcessUserModeExceptionPolicy alias _SetProcessUserModeExceptionPolicy@4
        #endif
        extern SetSearchPathMode alias _SetSearchPathMode@4
        extern SetStdHandleEx alias _SetStdHandleEx@12
        extern SetThreadErrorMode alias _SetThreadErrorMode@8
        extern SetThreadGroupAffinity alias _SetThreadGroupAffinity@12
        extern SetThreadIdealProcessorEx alias _SetThreadIdealProcessorEx@12
        extern SetThreadpoolStackInformation alias _SetThreadpoolStackInformation@8
        extern SystemTimeToTzSpecificLocalTimeEx alias _SystemTimeToTzSpecificLocalTimeEx@12
        extern TryAcquireSRWLockExclusive alias _TryAcquireSRWLockExclusive@4
        extern TryAcquireSRWLockShared alias _TryAcquireSRWLockShared@4
        extern TzSpecificLocalTimeToSystemTimeEx alias _TzSpecificLocalTimeToSystemTimeEx@12
        extern WerRegisterRuntimeExceptionModule alias _WerRegisterRuntimeExceptionModule@8
        extern WerUnregisterRuntimeExceptionModule alias _WerUnregisterRuntimeExceptionModule@8
        extern Wow64GetThreadSelectorEntry alias _Wow64GetThreadSelectorEntry@12
        define CopyMemory RtlCopyMemory

        #ifdef APP_UNICODE
            define K32EnumPageFiles K32EnumPageFilesW
            define K32GetDeviceDriverBaseName K32GetDeviceDriverBaseNameW
            define K32GetDeviceDriverFileName K32GetDeviceDriverFileNameW
            define K32GetMappedFileName K32GetMappedFileNameW
            define K32GetModuleBaseName K32GetModuleBaseNameW
            define K32GetModuleFileNameEx K32GetModuleFileNameExW
            define K32GetProcessImageFileName K32GetProcessImageFileNameW
        #else
            define K32EnumPageFiles K32EnumPageFilesA
            define K32GetDeviceDriverBaseName K32GetDeviceDriverBaseNameA
            define K32GetDeviceDriverFileName K32GetDeviceDriverFileNameA
            define K32GetMappedFileName K32GetMappedFileNameA
            define K32GetModuleBaseName K32GetModuleBaseNameA
            define K32GetModuleFileNameEx K32GetModuleFileNameExA
            define K32GetProcessImageFileName K32GetProcessImageFileNameA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WIN7SP1
        extern CopyContext alias _CopyContext@12
        extern GetEnabledXStateFeatures alias _GetEnabledXStateFeatures@0
        extern GetXStateFeaturesMask alias _GetXStateFeaturesMask@8
        extern InitializeContext alias _InitializeContext@16
        extern LocateXStateFeature alias _LocateXStateFeature@12
        extern SetXStateFeaturesMask alias _SetXStateFeaturesMask@8
    #endif

    #if NTDDI_VERSION >= NTDDI_WIN8
        #if NTDDI_VERSION == NTDDI_WIN8
            extern AcquireStateLock alias _AcquireStateLock@4
        #endif
        extern AddResourceAttributeAce alias _AddResourceAttributeAce@28
        extern AddScopedPolicyIDAce alias _AddScopedPolicyIDAce@20
        #if NTDDI_VERSION == NTDDI_WIN8
            extern CalloutOnFiberStack alias _CalloutOnFiberStack@12
            extern CopyExtendedContext alias _CopyExtendedContext@12
        #endif
        extern CeipIsOptedIn alias _CeipIsOptedIn@0
        extern CheckTokenCapability alias _CheckTokenCapability@12
        extern CheckTokenMembershipEx alias _CheckTokenMembershipEx@16
        extern ClosePackageInfo alias _ClosePackageInfo@4
        extern CopyFile2 alias _CopyFile2@12
        extern CreateFile2 alias _CreateFile2@20
        extern CreateFileMappingFromApp alias _CreateFileMappingFromApp@20
        extern GetAppContainerNamedObjectPath alias _GetAppContainerNamedObjectPath@20
        extern GetApplicationUserModelId alias _GetApplicationUserModelId@12
        extern GetCachedSigningLevel alias _GetCachedSigningLevel@24
        extern GetCurrentApplicationUserModelId alias _GetCurrentApplicationUserModelId@8
        extern GetCurrentPackageFamilyName alias _GetCurrentPackageFamilyName@8
        extern GetCurrentPackageFullName alias _GetCurrentPackageFullName@8
        extern GetCurrentPackageId alias _GetCurrentPackageId@8
        extern GetCurrentPackageInfo alias _GetCurrentPackageInfo@16
        extern GetCurrentPackagePath alias _GetCurrentPackagePath@8
        extern GetCurrentThreadStackLimits alias _GetCurrentThreadStackLimits@8
        extern GetFirmwareEnvironmentVariableExA alias _GetFirmwareEnvironmentVariableExA@20
        extern GetFirmwareEnvironmentVariableExW alias _GetFirmwareEnvironmentVariableExW@20
        extern GetFirmwareType alias _GetFirmwareType@4
        extern GetMemoryErrorHandlingCapabilities alias _GetMemoryErrorHandlingCapabilities@4
        extern GetOverlappedResultEx alias _GetOverlappedResultEx@20
        extern GetPackageFamilyName alias _GetPackageFamilyName@12
        extern GetPackageFullName alias _GetPackageFullName@12
        extern GetPackageId alias _GetPackageId@12
        extern GetPackageInfo alias _GetPackageInfo@20
        extern GetPackagePath alias _GetPackagePath@16
        extern GetPackagesByPackageFamily alias _GetPackagesByPackageFamily@20
        extern GetProcessInformation alias _GetProcessInformation@16
        extern GetProcessMitigationPolicy alias _GetProcessMitigationPolicy@16
        extern GetSystemTimePreciseAsFileTime alias _GetSystemTimePreciseAsFileTime@4
        extern GetThreadInformation alias _GetThreadInformation@16
        extern GlobalAddAtomExA alias _GlobalAddAtomExA@8
        extern GlobalAddAtomExW alias _GlobalAddAtomExW@8
        extern InterlockedPushListSListEx alias _InterlockedPushListSListEx@16
        extern IsNativeVhdBoot alias _IsNativeVhdBoot@4
        extern IsValidNLSVersion alias _IsValidNLSVersion@12
        extern LoadPackagedLibrary alias _LoadPackagedLibrary@8
        extern MapViewOfFileFromApp alias _MapViewOfFileFromApp@16
        extern OpenPackageInfoByFullName alias _OpenPackageInfoByFullName@12
        extern PackageFamilyNameFromFullName alias _PackageFamilyNameFromFullName@12
        extern PackageFamilyNameFromId alias _PackageFamilyNameFromId@12
        extern PackageFullNameFromId alias _PackageFullNameFromId@12
        extern PackageIdFromFullName alias _PackageIdFromFullName@16
        extern PackageNameAndPublisherIdFromFamilyName alias _PackageNameAndPublisherIdFromFamilyName@20
        extern PrefetchVirtualMemory alias _PrefetchVirtualMemory@16
        extern RegCopyTreeW alias _RegCopyTreeW@12
        extern RegisterBadMemoryNotification alias _RegisterBadMemoryNotification@4
        extern RestoreLastError alias _RestoreLastError@4
        extern SetCachedSigningLevel alias _SetCachedSigningLevel@16
        extern SetFirmwareEnvironmentVariableExA alias _SetFirmwareEnvironmentVariableExA@20
        extern SetFirmwareEnvironmentVariableExW alias _SetFirmwareEnvironmentVariableExW@20
        extern SetProcessInformation alias _SetProcessInformation@16
        extern SetProcessMitigationPolicy alias _SetProcessMitigationPolicy@12
        extern SetThreadInformation alias _SetThreadInformation@16
        extern UnregisterBadMemoryNotification alias _UnregisterBadMemoryNotification@4
        #ifdef APP_UNICODE
            define GetFirmwareEnvironmentVariableEx GetFirmwareEnvironmentVariableExW
            define GlobalAddAtomEx GlobalAddAtomExW
            define SetFirmwareEnvironmentVariableEx SetFirmwareEnvironmentVariableExW
        #else
            define GetFirmwareEnvironmentVariableEx GetFirmwareEnvironmentVariableExA
            define GlobalAddAtomEx GlobalAddAtomExA
            define SetFirmwareEnvironmentVariableEx SetFirmwareEnvironmentVariableExA
        #endif
    #endif

    #if NTDDI_VERSION >= NTDDI_WIN81
        extern DeleteSynchronizationBarrier alias _DeleteSynchronizationBarrier@4
        extern EnterSynchronizationBarrier alias _EnterSynchronizationBarrier@8
        extern FindPackagesByPackageFamily alias _FindPackagesByPackageFamily@28
        extern FormatApplicationUserModelId alias _FormatApplicationUserModelId@16
        extern GetPackageApplicationIds alias _GetPackageApplicationIds@16
        extern GetPackagePathByFullName alias _GetPackagePathByFullName@12
        extern GetStagedPackagePathByFullName alias _GetStagedPackagePathByFullName@12
        extern InitializeSynchronizationBarrier alias _InitializeSynchronizationBarrier@12
        extern InstallELAMCertificateInfo alias _InstallELAMCertificateInfo@4
        extern IsProcessCritical alias _IsProcessCritical@8
        extern OOBEComplete alias _OOBEComplete@4
        extern ParseApplicationUserModelId alias _ParseApplicationUserModelId@20
        extern PssCaptureSnapshot alias _PssCaptureSnapshot@16
        extern PssDuplicateSnapshot alias _PssDuplicateSnapshot@20
        extern PssFreeSnapshot alias _PssFreeSnapshot@8
        extern PssQuerySnapshot alias _PssQuerySnapshot@16
        extern PssWalkMarkerCreate alias _PssWalkMarkerCreate@8
        extern PssWalkMarkerFree alias _PssWalkMarkerFree@4
        extern PssWalkMarkerGetPosition alias _PssWalkMarkerGetPosition@8
        extern PssWalkMarkerSeekToBeginning alias _PssWalkMarkerSeekToBeginning@4
        extern PssWalkMarkerSetPosition alias _PssWalkMarkerSetPosition@8
        extern PssWalkSnapshot alias _PssWalkSnapshot@20
        extern RegisterWaitUntilOOBECompleted alias _RegisterWaitUntilOOBECompleted@12
        extern UnregisterWaitUntilOOBECompleted alias _UnregisterWaitUntilOOBECompleted@4
    #endif

    #if NTDDI_VERSION >= NTDDI_WIN10
        extern CreateEnclave alias _CreateEnclave@32
        extern DiscardVirtualMemory alias _DiscardVirtualMemory@8
        extern FreeMemoryJobObject alias _FreeMemoryJobObject@4
        extern GetProcessDefaultCpuSets alias _GetProcessDefaultCpuSets@16
        extern GetSystemCpuSetInformation alias _GetSystemCpuSetInformation@20
        extern GetThreadSelectedCpuSets alias _GetThreadSelectedCpuSets@16
        extern InitializeEnclave alias _InitializeEnclave@20
        extern IsEnclaveTypeSupported alias _IsEnclaveTypeSupported@4
        extern LoadEnclaveData alias _LoadEnclaveData@36
        extern OfferVirtualMemory alias _OfferVirtualMemory@12
        extern QueryIoRateControlInformationJobObject alias _QueryIoRateControlInformationJobObject@16
        extern QueryProtectedPolicy alias _QueryProtectedPolicy@8
        extern ReclaimVirtualMemory alias _ReclaimVirtualMemory@8
        extern SetIoRateControlInformationJobObject alias _SetIoRateControlInformationJobObject@8
        extern SetProcessDefaultCpuSets alias _SetProcessDefaultCpuSets@12
        extern SetProtectedPolicy alias _SetProtectedPolicy@12
        extern SetThreadSelectedCpuSets alias _SetThreadSelectedCpuSets@12
        extern WaitForDebugEventEx alias _WaitForDebugEventEx@8
    #endif
#endif

#ifdef APP_UNICODE
    define IMAGE_ORDINAL_FLAG IMAGE_ORDINAL_FLAG64
    define AddAtom AddAtomW
    define BeginUpdateResource BeginUpdateResourceW
    define BuildCommDCB BuildCommDCBW
    define BuildCommDCBAndTimeouts BuildCommDCBAndTimeoutsW
    define CallNamedPipe CallNamedPipeW
    define CommConfigDialog CommConfigDialogW
    define CompareString CompareStringW
    define CopyFile CopyFileW
    define CreateDirectory CreateDirectoryW
    define CreateDirectoryEx CreateDirectoryExW
    define CreateEvent CreateEventW
    define CreateFile CreateFileW
    define CreateFileMapping CreateFileMappingW
    define CreateMailslot CreateMailslotW
    define CreateMutex CreateMutexW
    define CreateNamedPipe CreateNamedPipeW
    define CreateProcess CreateProcessW
    define CreateSemaphore CreateSemaphoreW
    define DefineDosDevice DefineDosDeviceW
    define DeleteFile DeleteFileW
    define EndUpdateResource EndUpdateResourceW
    define EnumCalendarInfo EnumCalendarInfoW
    define EnumDateFormats EnumDateFormatsW
    define EnumResourceLanguages EnumResourceLanguagesW
    define EnumResourceNames EnumResourceNamesW
    define EnumResourceTypes EnumResourceTypesW
    define EnumSystemCodePages EnumSystemCodePagesW
    define EnumSystemLocales EnumSystemLocalesW
    define EnumTimeFormats EnumTimeFormatsW
    define ExpandEnvironmentStrings ExpandEnvironmentStringsW
    define FatalAppExit FatalAppExitW
    define FillConsoleOutputCharacter FillConsoleOutputCharacterW
    define FindAtom FindAtomW
    define FindFirstChangeNotification FindFirstChangeNotificationW
    define FindFirstFile FindFirstFileW
    define FindNextFile FindNextFileW
    define FindResource FindResourceW
    define FindResourceEx FindResourceExW
    define FoldString FoldStringW
    define FormatMessage FormatMessageW
    define FreeEnvironmentStrings FreeEnvironmentStringsW
    define GetAtomName GetAtomNameW
    define GetBinaryType GetBinaryTypeW
    define GetCommandLine GetCommandLineW
    define GetCompressedFileSize GetCompressedFileSizeW
    define GetComputerName GetComputerNameW
    define GetConsoleTitle GetConsoleTitleW
    define GetCurrencyFormat GetCurrencyFormatW
    define GetCurrentDirectory GetCurrentDirectoryW
    define GetDateFormat GetDateFormatW
    define GetDefaultCommConfig GetDefaultCommConfigW
    define GetDiskFreeSpace GetDiskFreeSpaceW
    define GetDiskFreeSpaceEx GetDiskFreeSpaceExW
    define GetDriveType GetDriveTypeW
    define GetEnvironmentStrings GetEnvironmentStringsW
    define GetEnvironmentVariable GetEnvironmentVariableW
    define GetFileAttributes GetFileAttributesW
    define GetFullPathName GetFullPathNameW
    define GetLocaleInfo GetLocaleInfoW
    define GetLogicalDriveStrings GetLogicalDriveStringsW
    define GetModuleFileName GetModuleFileNameW
    define GetModuleHandle GetModuleHandleW
    define GetNamedPipeHandleState GetNamedPipeHandleStateW
    define GetNumberFormat GetNumberFormatW
    define GetPrivateProfileInt GetPrivateProfileIntW
    define GetPrivateProfileSection GetPrivateProfileSectionW
    define GetPrivateProfileSectionNames GetPrivateProfileSectionNamesW
    define GetPrivateProfileString GetPrivateProfileStringW
    define GetPrivateProfileStruct GetPrivateProfileStructW
    define GetProfileInt GetProfileIntW
    define GetProfileSection GetProfileSectionW
    define GetProfileString GetProfileStringW
    define GetShortPathName GetShortPathNameW
    define GetStartupInfo GetStartupInfoW
    define GetStringType GetStringTypeW
    define GetStringTypeEx GetStringTypeExW
    define GetSystemDirectory GetSystemDirectoryW
    define GetTempFileName GetTempFileNameW
    define GetTempPath GetTempPathW
    define GetTimeFormat GetTimeFormatW
    define GetVersionEx GetVersionExW
    define GetVolumeInformation GetVolumeInformationW
    define GetWindowsDirectory GetWindowsDirectoryW
    define GlobalAddAtom GlobalAddAtomW
    define GlobalFindAtom GlobalFindAtomW
    define GlobalGetAtomName GlobalGetAtomNameW
    define IsBadStringPtr IsBadStringPtrW
    define LCMapString LCMapStringW
    define LoadLibrary LoadLibraryW
    define LoadLibraryEx LoadLibraryExW
    define lstrcat lstrcatW
    define lstrcmp lstrcmpW
    define lstrcmpi lstrcmpiW
    define lstrcpy lstrcpyW
    define lstrcpyn lstrcpynW
    define lstrlen lstrlenW
    define MoveFile MoveFileW
    define MoveFileEx MoveFileExW
    define OpenEvent OpenEventW
    define OpenFileMapping OpenFileMappingW
    define OpenMutex OpenMutexW
    define OpenSemaphore OpenSemaphoreW
    define OutputDebugString OutputDebugStringW
    define PeekConsoleInput PeekConsoleInputW
    define QueryDosDevice QueryDosDeviceW
    define ReadConsole ReadConsoleW
    define ReadConsoleInput ReadConsoleInputW
    define ReadConsoleOutput ReadConsoleOutputW
    define ReadConsoleOutputCharacter ReadConsoleOutputCharacterW
    define RemoveDirectory RemoveDirectoryW
    define ScrollConsoleScreenBuffer ScrollConsoleScreenBufferW
    define SearchPath SearchPathW
    define SetComputerName SetComputerNameW
    define SetConsoleTitle SetConsoleTitleW
    define SetCurrentDirectory SetCurrentDirectoryW
    define SetDefaultCommConfig SetDefaultCommConfigW
    define SetEnvironmentVariable SetEnvironmentVariableW
    define SetFileAttributes SetFileAttributesW
    define SetLocaleInfo SetLocaleInfoW
    define SetVolumeLabel SetVolumeLabelW
    define UpdateResource UpdateResourceW
    define WaitNamedPipe WaitNamedPipeW
    define WriteConsole WriteConsoleW
    define WriteConsoleInput WriteConsoleInputW
    define WriteConsoleOutput WriteConsoleOutputW
    define WriteConsoleOutputCharacter WriteConsoleOutputCharacterW
    define WritePrivateProfileSection WritePrivateProfileSectionW
    define WritePrivateProfileString WritePrivateProfileStringW
    define WritePrivateProfileStruct WritePrivateProfileStructW
    define WriteProfileSection WriteProfileSectionW
    define WriteProfileString WriteProfileStringW
#else
    define IMAGE_ORDINAL_FLAG IMAGE_ORDINAL_FLAG32
    define AddAtom AddAtomA
    define BeginUpdateResource BeginUpdateResourceA
    define BuildCommDCB BuildCommDCBA
    define BuildCommDCBAndTimeouts BuildCommDCBAndTimeoutsA
    define CallNamedPipe CallNamedPipeA
    define CommConfigDialog CommConfigDialogA
    define CompareString CompareStringA
    define CopyFile CopyFileA
    define CreateDirectory CreateDirectoryA
    define CreateDirectoryEx CreateDirectoryExA
    define CreateEvent CreateEventA
    define CreateFile CreateFileA
    define CreateFileMapping CreateFileMappingA
    define CreateMailslot CreateMailslotA
    define CreateMutex CreateMutexA
    define CreateNamedPipe CreateNamedPipeA
    define CreateProcess CreateProcessA
    define CreateSemaphore CreateSemaphoreA
    define DefineDosDevice DefineDosDeviceA
    define DeleteFile DeleteFileA
    define EndUpdateResource EndUpdateResourceA
    define EnumCalendarInfo EnumCalendarInfoA
    define EnumDateFormats EnumDateFormatsA
    define EnumResourceLanguages EnumResourceLanguagesA
    define EnumResourceNames EnumResourceNamesA
    define EnumResourceTypes EnumResourceTypesA
    define EnumSystemCodePages EnumSystemCodePagesA
    define EnumSystemLocales EnumSystemLocalesA
    define EnumTimeFormats EnumTimeFormatsA
    define ExpandEnvironmentStrings ExpandEnvironmentStringsA
    define FatalAppExit FatalAppExitA
    define FillConsoleOutputCharacter FillConsoleOutputCharacterA
    define FindAtom FindAtomA
    define FindFirstChangeNotification FindFirstChangeNotificationA
    define FindFirstFile FindFirstFileA
    define FindNextFile FindNextFileA
    define FindResource FindResourceA
    define FindResourceEx FindResourceExA
    define FoldString FoldStringA
    define FormatMessage FormatMessageA
    define FreeEnvironmentStrings FreeEnvironmentStringsA
    define GetAtomName GetAtomNameA
    define GetBinaryType GetBinaryTypeA
    define GetCommandLine GetCommandLineA
    define GetCompressedFileSize GetCompressedFileSizeA
    define GetComputerName GetComputerNameA
    define GetConsoleTitle GetConsoleTitleA
    define GetCurrencyFormat GetCurrencyFormatA
    define GetCurrentDirectory GetCurrentDirectoryA
    define GetDateFormat GetDateFormatA
    define GetDefaultCommConfig GetDefaultCommConfigA
    define GetDiskFreeSpace GetDiskFreeSpaceA
    define GetDiskFreeSpaceEx GetDiskFreeSpaceExA
    define GetDriveType GetDriveTypeA
    define GetEnvironmentStrings GetEnvironmentStringsA
    define GetEnvironmentVariable GetEnvironmentVariableA
    define GetFileAttributes GetFileAttributesA
    define GetFullPathName GetFullPathNameA
    define GetLocaleInfo GetLocaleInfoA
    define GetLogicalDriveStrings GetLogicalDriveStringsA
    define GetModuleFileName GetModuleFileNameA
    define GetModuleHandle GetModuleHandleA
    define GetNamedPipeHandleState GetNamedPipeHandleStateA
    define GetNumberFormat GetNumberFormatA
    define GetPrivateProfileInt GetPrivateProfileIntA
    define GetPrivateProfileSection GetPrivateProfileSectionA
    define GetPrivateProfileSectionNames GetPrivateProfileSectionNamesA
    define GetPrivateProfileString GetPrivateProfileStringA
    define GetPrivateProfileStruct GetPrivateProfileStructA
    define GetProfileInt GetProfileIntA
    define GetProfileSection GetProfileSectionA
    define GetProfileString GetProfileStringA
    define GetShortPathName GetShortPathNameA
    define GetStartupInfo GetStartupInfoA
    define GetStringType GetStringTypeA
    define GetStringTypeEx GetStringTypeExA
    define GetSystemDirectory GetSystemDirectoryA
    define GetTempFileName GetTempFileNameA
    define GetTempPath GetTempPathA
    define GetTimeFormat GetTimeFormatA
    define GetVersionEx GetVersionExA
    define GetVolumeInformation GetVolumeInformationA
    define GetWindowsDirectory GetWindowsDirectoryA
    define GlobalAddAtom GlobalAddAtomA
    define GlobalFindAtom GlobalFindAtomA
    define GlobalGetAtomName GlobalGetAtomNameA
    define IsBadStringPtr IsBadStringPtrA
    define LCMapString LCMapStringA
    define LoadLibrary LoadLibraryA
    define LoadLibraryEx LoadLibraryExA
    define lstrcat lstrcatA
    define lstrcmp lstrcmpA
    define lstrcmpi lstrcmpiA
    define lstrcpy lstrcpyA
    define lstrcpyn lstrcpynA
    define lstrlen lstrlenA
    define MoveFile MoveFileA
    define MoveFileEx MoveFileExA
    define OpenEvent OpenEventA
    define OpenFileMapping OpenFileMappingA
    define OpenMutex OpenMutexA
    define OpenSemaphore OpenSemaphoreA
    define OutputDebugString OutputDebugStringA
    define PeekConsoleInput PeekConsoleInputA
    define QueryDosDevice QueryDosDeviceA
    define ReadConsole ReadConsoleA
    define ReadConsoleInput ReadConsoleInputA
    define ReadConsoleOutput ReadConsoleOutputA
    define ReadConsoleOutputCharacter ReadConsoleOutputCharacterA
    define RemoveDirectory RemoveDirectoryA
    define ScrollConsoleScreenBuffer ScrollConsoleScreenBufferA
    define SearchPath SearchPathA
    define SetComputerName SetComputerNameA
    define SetConsoleTitle SetConsoleTitleA
    define SetCurrentDirectory SetCurrentDirectoryA
    define SetDefaultCommConfig SetDefaultCommConfigA
    define SetEnvironmentVariable SetEnvironmentVariableA
    define SetFileAttributes SetFileAttributesA
    define SetLocaleInfo SetLocaleInfoA
    define SetVolumeLabel SetVolumeLabelA
    define UpdateResource UpdateResourceA
    define WaitNamedPipe WaitNamedPipeA
    define WriteConsole WriteConsoleA
    define WriteConsoleInput WriteConsoleInputA
    define WriteConsoleOutput WriteConsoleOutputA
    define WriteConsoleOutputCharacter WriteConsoleOutputCharacterA
    define WritePrivateProfileSection WritePrivateProfileSectionA
    define WritePrivateProfileString WritePrivateProfileStringA
    define WritePrivateProfileStruct WritePrivateProfileStructA
    define WriteProfileSection WriteProfileSectionA
    define WriteProfileString WriteProfileStringA
#endif

;======================= Undocumented functions (unknown arguments) =======================;
;#ifdef APP_WIN64
;    #ifndef __misaligned_access
;        import __misaligned_access
;    #endif
;    import ActivateActCtxWorker
;    import AddRefActCtxWorker
;    import AppContainerDeriveSidFromMoniker
;    import AppContainerFreeMemory
;    import AppContainerLookupDisplayNameMrtReference
;    import AppContainerLookupMoniker
;    import AppContainerRegisterSid
;    import AppContainerUnregisterSid
;    import AppXFreeMemory
;    import AppXGetApplicationData
;    import AppXGetDevelopmentMode
;    import AppXGetOSMaxVersionTested
;    import AppXGetOSMinVersion
;    import AppXGetPackageCapabilities
;    import AppXGetPackageSid
;    import AppXGetPackageState
;    import AppXLookupDisplayName
;    import AppXLookupMoniker
;    import AppXSetPackageState
;    import BaseCheckAppcompatCache
;    import BaseCheckAppcompatCacheEx
;    import BaseCheckAppcompatCacheExWorker
;    import BaseCheckAppcompatCacheWorker
;    import BaseCheckElevation
;    import BaseCheckRunApp
;    import BaseCleanupAppcompatCacheSupport
;    import BaseCleanupAppcompatCacheSupportWorker
;    import BaseDestroyVDMEnvironment
;    import BaseDllReadWriteIniFile
;    import BaseDumpAppcompatCache
;    import BaseDumpAppcompatCacheWorker
;    import BaseElevationPostProcessing
;    import BaseFlushAppcompatCache
;    import BaseFlushAppcompatCacheWorker
;    import BaseFreeAppCompatDataForProcessWorker
;    import BaseFormatObjectAttributes
;    import BaseGenerateAppCompatData
;    import BaseInitAppcompatCacheSupport
;    import BaseInitAppcompatCacheSupportWorker
;    import BaseIsAppcompatInfrastructureDisabled
;    import BaseIsAppcompatInfrastructureDisabledWorker
;    import BaseIsDosApplication
;    import BaseProcessInitPostImport
;    import BaseProcessStart
;    import BaseQueryModuleData
;    import BaseReadAppCompatDataForProcessWorker
;    import BaseSetLastNTError
;    import BaseThreadInitThunk
;    import BaseUpdateAppcompatCache
;    import BaseUpdateAppcompatCacheWorker
;    import BaseUpdateVDMEntry
;    import BaseVerifyUnicodeString
;    import BaseWriteErrorElevationRequiredEvent
;    import BasepAllocateActivationContextActivationBlock
;    import BasepAnsiStringToDynamicUnicodeString
;    import BasepAppCompatHookDLL
;    import BasepAppContainerEnvironmentExtension
;    import BasepAppXExtension
;    import BasepCheckAppCompat
;    import BasepCheckBadapp
;    import BasepCheckWebBladeHashes
;    import BasepCheckWinSaferRestrictions
;    import BasepConstructSxsCreateProcessMessage
;    import BasepCopyEncryption
;    import BasepFreeActivationContextActivationBlock
;    import BasepFreeAppCompatData
;    import BasepGetAppCompatData
;    import BasepGetComputerNameFromNtPath
;    import BasepGetExeArchType
;    import BasepIsProcessAllowed
;    import BasepMapModuleHandle
;    import BasepNotifyLoadStringResource
;    import BasepPostSuccessAppXExtension
;    import BasepProcessInvalidImage
;    import BasepQueryAppCompat
;    import BasepReleaseAppXContext
;    import BasepReleaseSxsCreateProcessUtilityStruct
;    import BasepReportFault
;    import BasepSetFileEncryptionCompression
;    import CancelTimerQueueTimer
;    import CheckAllowDecryptedRemoteDestinationPolicy
;    import CheckElevation
;    import CheckForReadOnlyResource
;    import CheckForReadOnlyResourceFilter
;    import CloseConsoleHandle
;    import CloseState
;    import CloseStateAtom
;    import CloseStateChangeNotification
;    import CloseStateContainer
;    import CloseStateLock
;    import CmdBatNotification
;    import CommitStateAtom
;    import CompareCalendarDates
;    import ConsoleIMERoutine
;    import ConvertNLSDayOfWeekToWin32DayOfWeek
;    import CreateActCtxWWorker
;    import CreateNlsSecurityDescriptor
;    import CreateSocketHandle
;    import CreateStateAtom
;    import CreateStateChangeNotification
;    import CreateStateContainer
;    import CreateStateLock
;    import CreateStateSubcontainer
;    import CtrlRoutine
;    import DeactivateActCtxWorker
;    import DeleteStateAtomValue
;    import DeleteStateContainer
;    import DeleteStateContainerValue
;    import DnsHostnameToComputerNameExW
;    import DuplicateEncryptionInfoFileExt
;    import DuplicateStateContainerHandle
;    import EnumerateStateAtomValues
;    import EnumerateStateContainerItems
;    import FindActCtxSectionGuidWorker
;    import FindActCtxSectionStringWWorker
;    import GetAppContainerAce
;    import GetApplicationRecoveryCallbackWorker
;    import GetApplicationRestartSettingsWorker
;    import GetCalendarDateFormat
;    import GetCalendarDaysInMonth
;    import GetCalendarDifferenceInDays
;    import GetCalendarMonthsInYear
;    import GetCalendarWeekNumber
;    import GetConsoleCharType
;    import GetConsoleCommandHistoryA
;    import GetConsoleCommandHistoryW
;    import GetConsoleCommandHistoryLengthA
;    import GetConsoleCommandHistoryLengthW
;    import GetConsoleCursorMode
;    import GetConsoleHardwareState
;    import GetConsoleInputExeNameA
;    import GetConsoleInputExeNameW
;    import GetConsoleInputWaitHandle
;    import GetConsoleKeyboardLayoutNameA
;    import GetConsoleKeyboardLayoutNameW
;    import GetCPFileNameFromRegistry
;    import GetCurrentActCtxWorker
;    import GetDateFormatAWorker
;    import GetDateFormatWWorker
;    import GetDefaultSortkeySize
;    import GetEncryptedFileVersionExt
;    import GetEraNameCountedString
;    import GetHivePath
;    import GetLinguistLangSize
;    import GetNlsSectionName
;    import GetRoamingLastObservedChangeTime
;    import GetSerializedAtomBytes
;    import GetStateContainerDepth
;    import GetStateFolder
;    import GetStateRootFolder
;    import GetStateSettingsFolder
;    import GetStateVersion
;    import GetSystemAppDataFolder
;    import GetSystemAppDataKey
;    import GetTimeFormatAWorker
;    import GetTimeFormatWWorker
;    import HeapSummary
;    import HeapCreateTagsW
;    import HeapExtend
;    import HeapQueryTagW
;    import HeapUsage
;    import IsValidUILanguage
;    import NlsCheckPolicy
;    import NlsConvertIntegerToString
;    import NlsEventDataDescCreate
;    import NlsGetCacheUpdateCount
;    import NlsResetProcessLocale
;    import NlsUpdateLocale
;    import NlsUpdateSystemLocale
;    import NlsWriteEtwEvent
;    import NotifyMountMgr
;    import NtVdm64CreateProcessInternalW
;    import OpenConsoleWStub
;    import OpenState
;    import OpenStateAtom
;    import OpenStateExplicit
;    import OverrideRoamingDataModificationTimesInRange
;    import PssWalkMarkerRewind
;    import PssWalkMarkerSeek
;    import PssWalkMarkerTell
;    import PrivMoveFileIdentityW
;    import PublishStateChangeNotification
;    import QueryActCtxSettingsWWorker
;    import QueryActCtxWWorker
;    import QueryStateAtomValueInfo
;    import QueryStateContainerItemInfo
;    import QuirkGetData2Worker
;    import QuirkGetDataWorker
;    import QuirkIsEnabled2Worker
;    import QuirkIsEnabled3Worker
;    import QuirkIsEnabledForPackage2Worker
;    import QuirkIsEnabledForPackage3Worker
;    import QuirkIsEnabledForPackage4Worker
;    import QuirkIsEnabledForPackageWorker
;    import QuirkIsEnabledForProcessWorker
;    import QuirkIsEnabledWorker
;    import RaiseInvalid16BitExeError
;    import ReadStateAtomValue
;    import ReadStateContainerValue
;    import RegisterConsoleIME
;    import RegisterConsoleOS2
;    import RegisterConsoleVDM
;    import RegisterStateChangeNotification
;    import RegisterStateLock
;    import RegisterWaitForInputIdle
;    import RegisterWaitForSingleObjectEx
;    import RegisterWowBaseHandlers
;    import RegisterWowExec
;    import RegKrnGetGlobalState
;    import RegKrnInitialize
;    import ReleaseActCtxWorker
;    import ReleaseStateLock
;    import RemoveLocalAlternateComputerNameA
;    import RemoveLocalAlternateComputerNameW
;    import ResetState
;    import SetClientDynamicTimeZoneInformation
;    import SetClientTimeZoneInformation
;    import SetComPlusPackageInstallStatus
;    import SetComputerNameEx2W
;    import SetConsoleCommandHistoryMode
;    import SetConsoleCursorMode
;    import SetConsoleInputExeNameA
;    import SetConsoleInputExeNameW
;    import SetConsoleKeyShortcuts
;    import SetConsoleLocalEUDC
;    import SetConsoleMenuClose
;    import SetCPGlobal
;    import SetRoamingLastObservedChangeTime
;    import SetStateVersion
;    import SetThreadpoolTimerEx
;    import SetVolumeMountPointWStub
;    import SetWaitableTimerEx
;    import SortCloseHandle
;    import SortGetHandle
;    import SubscribeStateChangeNotification
;    import TermsrvConvertSysRootToUserDir
;    import TermsrvAppInstallMode
;    import TermsrvCreateRegEntry
;    import TermsrvDeleteKey
;    import TermsrvDeleteValue
;    import TermsrvGetPreSetValue
;    import TermsrvGetWindowsDirectoryA
;    import TermsrvGetWindowsDirectoryW
;    import TermsrvOpenRegEntry
;    import TermsrvOpenUserClasses
;    import TermsrvRestoreKey
;    import TermsrvSetKeySecurity
;    import TermsrvSetValueKey
;    import TermsrvSyncUserIniFileExt
;    import UnmapViewOfFileEx
;    import UnregisterConsoleIME
;    import UTRegister
;    import UTUnRegister
;    import UnregisterStateChangeNotification
;    import UnregisterStateLock
;    import UnsubscribeStateChangeNotification
;    import ValidateLCType
;    import ValidateLocale
;    import VDMConsoleOperation
;    import VDMOperationStarted
;    import VerifyConsoleIoHandle
;    import WerGetFlagsWorker
;    import WerRegisterFileWorker
;    import WerRegisterMemoryBlockWorker
;    import WerRegisterRuntimeExceptionModuleWorker
;    import WerSetFlagsWorker
;    import WerUnregisterFileWorker
;    import WerUnregisterMemoryBlockWorker
;    import WerUnregisterRuntimeExceptionModuleWorker
;    import WerpCleanupMessageMapping
;    import WerpGetDebugger
;    import WerpInitiateRemoteRecovery
;    import WerpLaunchAeDebug
;    import WerpNotifyLoadStringResource
;    import WerpNotifyLoadStringResourceEx
;    import WerpNotifyLoadStringResourceWorker
;    import WerpNotifyUseStringResource
;    import WerpNotifyUseStringResourceWorker
;    import WerpStringLookup
;    import WriteConsoleInputVDMA
;    import WriteConsoleInputVDMW
;    import WriteStateAtomValue
;    import WriteStateContainerValue
;    import ZombifyActCtxWorker
;#else
;    #ifndef __misaligned_access
;        extern __misaligned_access alias ___misaligned_access@??
;    #endif
;    extern ActivateActCtxWorker alias _ActivateActCtxWorker@??
;    extern AddRefActCtxWorker alias _AddRefActCtxWorker@??
;    extern AppContainerDeriveSidFromMoniker alias _AppContainerDeriveSidFromMoniker@??
;    extern AppContainerFreeMemory alias _AppContainerFreeMemory@??
;    extern AppContainerLookupDisplayNameMrtReference alias _AppContainerLookupDisplayNameMrtReference@??
;    extern AppContainerLookupMoniker alias _AppContainerLookupMoniker@??
;    extern AppContainerRegisterSid alias _AppContainerRegisterSid@??
;    extern AppContainerUnregisterSid alias _AppContainerUnregisterSid@??
;    extern AppXFreeMemory alias _AppXFreeMemory@??
;    extern AppXGetApplicationData alias _AppXGetApplicationData@??
;    extern AppXGetDevelopmentMode alias _AppXGetDevelopmentMode@??
;    extern AppXGetOSMaxVersionTested alias _AppXGetOSMaxVersionTested@??
;    extern AppXGetOSMinVersion alias _AppXGetOSMinVersion@??
;    extern AppXGetPackageCapabilities alias _AppXGetPackageCapabilities@??
;    extern AppXGetPackageSid alias _AppXGetPackageSid@??
;    extern AppXGetPackageState alias _AppXGetPackageState@??
;    extern AppXLookupDisplayName alias _AppXLookupDisplayName@??
;    extern AppXLookupMoniker alias _AppXLookupMoniker@??
;    extern AppXSetPackageState alias _AppXSetPackageState@??
;    extern BaseCheckAppcompatCache alias _BaseCheckAppcompatCache@??
;    extern BaseCheckAppcompatCacheEx alias _BaseCheckAppcompatCacheEx@??
;    extern BaseCheckAppcompatCacheExWorker alias _BaseCheckAppcompatCacheExWorker@??
;    extern BaseCheckAppcompatCacheWorker alias _BaseCheckAppcompatCacheWorker@??
;    extern BaseCheckElevation alias _BaseCheckElevation@??
;    extern BaseCheckRunApp alias _BaseCheckRunApp@??
;    extern BaseCleanupAppcompatCacheSupport alias _BaseCleanupAppcompatCacheSupport@??
;    extern BaseCleanupAppcompatCacheSupportWorker alias _BaseCleanupAppcompatCacheSupportWorker@??
;    extern BaseDestroyVDMEnvironment alias _BaseDestroyVDMEnvironment@??
;    extern BaseDllReadWriteIniFile alias _BaseDllReadWriteIniFile@??
;    extern BaseDumpAppcompatCache alias _BaseDumpAppcompatCache@??
;    extern BaseDumpAppcompatCacheWorker alias _BaseDumpAppcompatCacheWorker@??
;    extern BaseElevationPostProcessing alias _BaseElevationPostProcessing@??
;    extern BaseFlushAppcompatCache alias _BaseFlushAppcompatCache@??
;    extern BaseFlushAppcompatCacheWorker alias _BaseFlushAppcompatCacheWorker@??
;    extern BaseFreeAppCompatDataForProcessWorker alias _BaseFreeAppCompatDataForProcessWorker@??
;    extern BaseFormatObjectAttributes alias _BaseFormatObjectAttributes@??
;    extern BaseGenerateAppCompatData alias _BaseGenerateAppCompatData@??
;    extern BaseInitAppcompatCacheSupport alias _BaseInitAppcompatCacheSupport@??
;    extern BaseInitAppcompatCacheSupportWorker alias _BaseInitAppcompatCacheSupportWorker@??
;    extern BaseIsAppcompatInfrastructureDisabled alias _BaseIsAppcompatInfrastructureDisabled@??
;    extern BaseIsAppcompatInfrastructureDisabledWorker alias _BaseIsAppcompatInfrastructureDisabledWorker@??
;    extern BaseIsDosApplication alias _BaseIsDosApplication@??
;    extern BaseProcessInitPostImport alias _BaseProcessInitPostImport@??
;    extern BaseProcessStart alias _BaseProcessStart@??
;    extern BaseQueryModuleData alias _BaseQueryModuleData@??
;    extern BaseReadAppCompatDataForProcessWorker alias _BaseReadAppCompatDataForProcessWorker@??
;    extern BaseSetLastNTError alias _BaseSetLastNTError@??
;    extern BaseThreadInitThunk alias _BaseThreadInitThunk@??
;    extern BaseUpdateAppcompatCache alias _BaseUpdateAppcompatCache@??
;    extern BaseUpdateAppcompatCacheWorker alias _BaseUpdateAppcompatCacheWorker@??
;    extern BaseUpdateVDMEntry alias _BaseUpdateVDMEntry@??
;    extern BaseVerifyUnicodeString alias _BaseVerifyUnicodeString@??
;    extern BaseWriteErrorElevationRequiredEvent alias _BaseWriteErrorElevationRequiredEvent@??
;    extern BasepAllocateActivationContextActivationBlock alias _BasepAllocateActivationContextActivationBlock@??
;    extern BasepAnsiStringToDynamicUnicodeString alias _BasepAnsiStringToDynamicUnicodeString@??
;    extern BasepAppCompatHookDLL alias _BasepAppCompatHookDLL@??
;    extern BasepAppContainerEnvironmentExtension alias _BasepAppContainerEnvironmentExtension@??
;    extern BasepAppXExtension alias _BasepAppXExtension@??
;    extern BasepCheckAppCompat alias _BasepCheckAppCompat@??
;    extern BasepCheckBadapp alias _BasepCheckBadapp@??
;    extern BasepCheckWebBladeHashes alias _BasepCheckWebBladeHashes@??
;    extern BasepCheckWinSaferRestrictions alias _BasepCheckWinSaferRestrictions@??
;    extern BasepConstructSxsCreateProcessMessage alias _BasepConstructSxsCreateProcessMessage@??
;    extern BasepCopyEncryption alias _BasepCopyEncryption@??
;    extern BasepFreeActivationContextActivationBlock alias _BasepFreeActivationContextActivationBlock@??
;    extern BasepFreeAppCompatData alias _BasepFreeAppCompatData@??
;    extern BasepGetAppCompatData alias _BasepGetAppCompatData@??
;    extern BasepGetComputerNameFromNtPath alias _BasepGetComputerNameFromNtPath@??
;    extern BasepGetExeArchType alias _BasepGetExeArchType@??
;    extern BasepIsProcessAllowed alias _BasepIsProcessAllowed@??
;    extern BasepMapModuleHandle alias _BasepMapModuleHandle@??
;    extern BasepNotifyLoadStringResource alias _BasepNotifyLoadStringResource@??
;    extern BasepPostSuccessAppXExtension alias _BasepPostSuccessAppXExtension@??
;    extern BasepProcessInvalidImage alias _BasepProcessInvalidImage@??
;    extern BasepQueryAppCompat alias _BasepQueryAppCompat@??
;    extern BasepReleaseAppXContext alias _BasepReleaseAppXContext@??
;    extern BasepReleaseSxsCreateProcessUtilityStruct alias _BasepReleaseSxsCreateProcessUtilityStruct@??
;    extern BasepReportFault alias _BasepReportFault@??
;    extern BasepSetFileEncryptionCompression alias _BasepSetFileEncryptionCompression@??
;    extern CancelTimerQueueTimer alias _CancelTimerQueueTimer@??
;    extern CheckAllowDecryptedRemoteDestinationPolicy alias _CheckAllowDecryptedRemoteDestinationPolicy@??
;    extern CheckElevation alias _CheckElevation@??
;    extern CheckForReadOnlyResource alias _CheckForReadOnlyResource@??
;    extern CheckForReadOnlyResourceFilter alias _CheckForReadOnlyResourceFilter@??
;    extern CloseConsoleHandle alias _CloseConsoleHandle@??
;    extern CloseState alias _CloseState@??
;    extern CloseStateAtom alias _CloseStateAtom@??
;    extern CloseStateChangeNotification alias _CloseStateChangeNotification@??
;    extern CloseStateContainer alias _CloseStateContainer@??
;    extern CloseStateLock alias _CloseStateLock@??
;    extern CmdBatNotification alias _CmdBatNotification@??
;    extern CommitStateAtom alias _CommitStateAtom@??
;    extern CompareCalendarDates alias _CompareCalendarDates@??
;    extern ConsoleIMERoutine alias _ConsoleIMERoutine@??
;    extern ConvertNLSDayOfWeekToWin32DayOfWeek alias _ConvertNLSDayOfWeekToWin32DayOfWeek@??
;    extern CreateActCtxWWorker alias _CreateActCtxWWorker@??
;    extern CreateNlsSecurityDescriptor alias _CreateNlsSecurityDescriptor@??
;    extern CreateSocketHandle alias _CreateSocketHandle@??
;    extern CreateStateAtom alias _CreateStateAtom@??
;    extern CreateStateChangeNotification alias _CreateStateChangeNotification@??
;    extern CreateStateContainer alias _CreateStateContainer@??
;    extern CreateStateLock alias _CreateStateLock@??
;    extern CreateStateSubcontainer alias _CreateStateSubcontainer@??
;    extern CtrlRoutine alias _CtrlRoutine@??
;    extern DeactivateActCtxWorker alias _DeactivateActCtxWorker@??
;    extern DeleteStateAtomValue alias _DeleteStateAtomValue@??
;    extern DeleteStateContainer alias _DeleteStateContainer@??
;    extern DeleteStateContainerValue alias _DeleteStateContainerValue@??
;    extern DnsHostnameToComputerNameExW alias _DnsHostnameToComputerNameExW@??
;    extern DuplicateEncryptionInfoFileExt alias _DuplicateEncryptionInfoFileExt@??
;    extern DuplicateStateContainerHandle alias _DuplicateStateContainerHandle@??
;    extern EnumerateStateAtomValues alias _EnumerateStateAtomValues@??
;    extern EnumerateStateContainerItems alias _EnumerateStateContainerItems@??
;    extern FindActCtxSectionGuidWorker alias _FindActCtxSectionGuidWorker@??
;    extern FindActCtxSectionStringWWorker alias _FindActCtxSectionStringWWorker@??
;    extern GetAppContainerAce alias _GetAppContainerAce@??
;    extern GetApplicationRecoveryCallbackWorker alias _GetApplicationRecoveryCallbackWorker@??
;    extern GetApplicationRestartSettingsWorker alias _GetApplicationRestartSettingsWorker@??
;    extern GetCalendarDateFormat alias _GetCalendarDateFormat@??
;    extern GetCalendarDaysInMonth alias _GetCalendarDaysInMonth@??
;    extern GetCalendarDifferenceInDays alias _GetCalendarDifferenceInDays@??
;    extern GetCalendarMonthsInYear alias _GetCalendarMonthsInYear@??
;    extern GetCalendarWeekNumber alias _GetCalendarWeekNumber@??
;    extern GetConsoleCharType alias _GetConsoleCharType@??
;    extern GetConsoleCommandHistoryA alias _GetConsoleCommandHistoryA@??
;    extern GetConsoleCommandHistoryW alias _GetConsoleCommandHistoryW@??
;    extern GetConsoleCommandHistoryLengthA alias _GetConsoleCommandHistoryLengthA@??
;    extern GetConsoleCommandHistoryLengthW alias _GetConsoleCommandHistoryLengthW@??
;    extern GetConsoleCursorMode alias _GetConsoleCursorMode@??
;    extern GetConsoleHardwareState alias _GetConsoleHardwareState@??
;    extern GetConsoleInputExeNameA alias _GetConsoleInputExeNameA@??
;    extern GetConsoleInputExeNameW alias _GetConsoleInputExeNameW@??
;    extern GetConsoleInputWaitHandle alias _GetConsoleInputWaitHandle@??
;    extern GetConsoleKeyboardLayoutNameA alias _GetConsoleKeyboardLayoutNameA@??
;    extern GetConsoleKeyboardLayoutNameW alias _GetConsoleKeyboardLayoutNameW@??
;    extern GetCPFileNameFromRegistry alias _GetCPFileNameFromRegistry@??
;    extern GetCurrentActCtxWorker alias _GetCurrentActCtxWorker@??
;    extern GetDateFormatAWorker alias _GetDateFormatAWorker@??
;    extern GetDateFormatWWorker alias _GetDateFormatWWorker@??
;    extern GetDefaultSortkeySize alias _GetDefaultSortkeySize@??
;    extern GetEncryptedFileVersionExt alias _GetEncryptedFileVersionExt@??
;    extern GetEraNameCountedString alias _GetEraNameCountedString@??
;    extern GetHivePath alias _GetHivePath@??
;    extern GetLinguistLangSize alias _GetLinguistLangSize@??
;    extern GetNlsSectionName alias _GetNlsSectionName@??
;    extern GetRoamingLastObservedChangeTime alias _GetRoamingLastObservedChangeTime@??
;    extern GetSerializedAtomBytes alias _GetSerializedAtomBytes@??
;    extern GetStateContainerDepth alias _GetStateContainerDepth@??
;    extern GetStateFolder alias _GetStateFolder@??
;    extern GetStateRootFolder alias _GetStateRootFolder@??
;    extern GetStateSettingsFolder alias _GetStateSettingsFolder@??
;    extern GetStateVersion alias _GetStateVersion@??
;    extern GetSystemAppDataFolder alias _GetSystemAppDataFolder@??
;    extern GetSystemAppDataKey alias _GetSystemAppDataKey@??
;    extern GetTimeFormatAWorker alias _GetTimeFormatAWorker@??
;    extern GetTimeFormatWWorker alias _GetTimeFormatWWorker@??
;    extern HeapSummary alias _HeapSummary@??
;    extern HeapCreateTagsW alias _HeapCreateTagsW@??
;    extern HeapExtend alias _HeapExtend@??
;    extern HeapQueryTagW alias _HeapQueryTagW@??
;    extern HeapUsage alias _HeapUsage@??
;    extern IsValidUILanguage alias _IsValidUILanguage@??
;    extern NlsCheckPolicy alias _NlsCheckPolicy@??
;    extern NlsConvertIntegerToString alias _NlsConvertIntegerToString@??
;    extern NlsEventDataDescCreate alias _NlsEventDataDescCreate@??
;    extern NlsGetCacheUpdateCount alias _NlsGetCacheUpdateCount@??
;    extern NlsResetProcessLocale alias _NlsResetProcessLocale@??
;    extern NlsUpdateLocale alias _NlsUpdateLocale@??
;    extern NlsUpdateSystemLocale alias _NlsUpdateSystemLocale@??
;    extern NlsWriteEtwEvent alias _NlsWriteEtwEvent@??
;    extern NotifyMountMgr alias _NotifyMountMgr@??
;    extern NtVdm64CreateProcessInternalW alias _NtVdm64CreateProcessInternalW@??
;    extern OpenConsoleWStub alias _OpenConsoleWStub@??
;    extern OpenState alias _OpenState@??
;    extern OpenStateAtom alias _OpenStateAtom@??
;    extern OpenStateExplicit alias _OpenStateExplicit@??
;    extern OverrideRoamingDataModificationTimesInRange alias _OverrideRoamingDataModificationTimesInRange@??
;    extern PssWalkMarkerRewind alias _PssWalkMarkerRewind@??
;    extern PssWalkMarkerSeek alias _PssWalkMarkerSeek@??
;    extern PssWalkMarkerTell alias _PssWalkMarkerTell@??
;    extern PrivMoveFileIdentityW alias _PrivMoveFileIdentityW@??
;    extern PublishStateChangeNotification alias _PublishStateChangeNotification@??
;    extern QueryActCtxSettingsWWorker alias _QueryActCtxSettingsWWorker@??
;    extern QueryActCtxWWorker alias _QueryActCtxWWorker@??
;    extern QueryStateAtomValueInfo alias _QueryStateAtomValueInfo@??
;    extern QueryStateContainerItemInfo alias _QueryStateContainerItemInfo@??
;    extern QuirkGetData2Worker alias _QuirkGetData2Worker@??
;    extern QuirkGetDataWorker alias _QuirkGetDataWorker@??
;    extern QuirkIsEnabled2Worker alias _QuirkIsEnabled2Worker@??
;    extern QuirkIsEnabled3Worker alias _QuirkIsEnabled3Worker@??
;    extern QuirkIsEnabledForPackage2Worker alias _QuirkIsEnabledForPackage2Worker@??
;    extern QuirkIsEnabledForPackage3Worker alias _QuirkIsEnabledForPackage3Worker@??
;    extern QuirkIsEnabledForPackage4Worker alias _QuirkIsEnabledForPackage4Worker@??
;    extern QuirkIsEnabledForPackageWorker alias _QuirkIsEnabledForPackageWorker@??
;    extern QuirkIsEnabledForProcessWorker alias _QuirkIsEnabledForProcessWorker@??
;    extern QuirkIsEnabledWorker alias _QuirkIsEnabledWorker@??
;    extern RaiseInvalid16BitExeError alias _RaiseInvalid16BitExeError@??
;    extern ReadStateAtomValue alias _ReadStateAtomValue@??
;    extern ReadStateContainerValue alias _ReadStateContainerValue@??
;    extern RegisterConsoleIME alias _RegisterConsoleIME@??
;    extern RegisterConsoleOS2 alias _RegisterConsoleOS2@??
;    extern RegisterConsoleVDM alias _RegisterConsoleVDM@??
;    extern RegisterStateChangeNotification alias _RegisterStateChangeNotification@??
;    extern RegisterStateLock alias _RegisterStateLock@??
;    extern RegisterWaitForInputIdle alias _RegisterWaitForInputIdle@??
;    extern RegisterWaitForSingleObjectEx alias _RegisterWaitForSingleObjectEx@??
;    extern RegisterWowBaseHandlers alias _RegisterWowBaseHandlers@??
;    extern RegisterWowExec alias _RegisterWowExec@??
;    extern RegKrnGetGlobalState alias _RegKrnGetGlobalState@??
;    extern RegKrnInitialize alias _RegKrnInitialize@??
;    extern ReleaseActCtxWorker alias _ReleaseActCtxWorker@??
;    extern ReleaseStateLock alias _ReleaseStateLock@??
;    extern RemoveLocalAlternateComputerNameA alias _RemoveLocalAlternateComputerNameA@??
;    extern RemoveLocalAlternateComputerNameW alias _RemoveLocalAlternateComputerNameW@??
;    extern ResetState alias _ResetState@??
;    extern SetClientDynamicTimeZoneInformation alias _SetClientDynamicTimeZoneInformation@??
;    extern SetClientTimeZoneInformation alias _SetClientTimeZoneInformation@??
;    extern SetComPlusPackageInstallStatus alias _SetComPlusPackageInstallStatus@??
;    extern SetComputerNameEx2W alias _SetComputerNameEx2W@??
;    extern SetConsoleCommandHistoryMode alias _SetConsoleCommandHistoryMode@??
;    extern SetConsoleCursorMode alias _SetConsoleCursorMode@??
;    extern SetConsoleInputExeNameA alias _SetConsoleInputExeNameA@??
;    extern SetConsoleInputExeNameW alias _SetConsoleInputExeNameW@??
;    extern SetConsoleKeyShortcuts alias _SetConsoleKeyShortcuts@??
;    extern SetConsoleLocalEUDC alias _SetConsoleLocalEUDC@??
;    extern SetConsoleMenuClose alias _SetConsoleMenuClose@??
;    extern SetCPGlobal alias _SetCPGlobal@??
;    extern SetRoamingLastObservedChangeTime alias _SetRoamingLastObservedChangeTime@??
;    extern SetStateVersion alias _SetStateVersion@??
;    extern SetThreadpoolTimerEx alias _SetThreadpoolTimerEx@??
;    extern SetVolumeMountPointWStub alias _SetVolumeMountPointWStub@??
;    extern SetWaitableTimerEx alias _SetWaitableTimerEx@??
;    extern SortCloseHandle alias _SortCloseHandle@??
;    extern SortGetHandle alias _SortGetHandle@??
;    extern SubscribeStateChangeNotification alias _SubscribeStateChangeNotification@??
;    extern TermsrvConvertSysRootToUserDir alias _TermsrvConvertSysRootToUserDir@??
;    extern TermsrvAppInstallMode alias _TermsrvAppInstallMode@??
;    extern TermsrvCreateRegEntry alias _TermsrvCreateRegEntry@??
;    extern TermsrvDeleteKey alias _TermsrvDeleteKey@??
;    extern TermsrvDeleteValue alias _TermsrvDeleteValue@??
;    extern TermsrvGetPreSetValue alias _TermsrvGetPreSetValue@??
;    extern TermsrvGetWindowsDirectoryA alias _TermsrvGetWindowsDirectoryA@??
;    extern TermsrvGetWindowsDirectoryW alias _TermsrvGetWindowsDirectoryW@??
;    extern TermsrvOpenRegEntry alias _TermsrvOpenRegEntry@??
;    extern TermsrvOpenUserClasses alias _TermsrvOpenUserClasses@??
;    extern TermsrvRestoreKey alias _TermsrvRestoreKey@??
;    extern TermsrvSetKeySecurity alias _TermsrvSetKeySecurity@??
;    extern TermsrvSetValueKey alias _TermsrvSetValueKey@??
;    extern TermsrvSyncUserIniFileExt alias _TermsrvSyncUserIniFileExt@??
;    extern UnmapViewOfFileEx alias _UnmapViewOfFileEx@??
;    extern UnregisterConsoleIME alias _UnregisterConsoleIME@??
;    extern UTRegister alias _UTRegister@??
;    extern UTUnRegister alias _UTUnRegister@??
;    extern UnregisterStateChangeNotification alias _UnregisterStateChangeNotification@??
;    extern UnregisterStateLock alias _UnregisterStateLock@??
;    extern UnsubscribeStateChangeNotification alias _UnsubscribeStateChangeNotification@??
;    extern ValidateLCType alias _ValidateLCType@??
;    extern ValidateLocale alias _ValidateLocale@??
;    extern VDMConsoleOperation alias _VDMConsoleOperation@??
;    extern VDMOperationStarted alias _VDMOperationStarted@??
;    extern VerifyConsoleIoHandle alias _VerifyConsoleIoHandle@??
;    extern WerGetFlagsWorker alias _WerGetFlagsWorker@??
;    extern WerRegisterFileWorker alias _WerRegisterFileWorker@??
;    extern WerRegisterMemoryBlockWorker alias _WerRegisterMemoryBlockWorker@??
;    extern WerRegisterRuntimeExceptionModuleWorker alias _WerRegisterRuntimeExceptionModuleWorker@??
;    extern WerSetFlagsWorker alias _WerSetFlagsWorker@??
;    extern WerUnregisterFileWorker alias _WerUnregisterFileWorker@??
;    extern WerUnregisterMemoryBlockWorker alias _WerUnregisterMemoryBlockWorker@??
;    extern WerUnregisterRuntimeExceptionModuleWorker alias _WerUnregisterRuntimeExceptionModuleWorker@??
;    extern WerpCleanupMessageMapping alias _WerpCleanupMessageMapping@??
;    extern WerpGetDebugger alias _WerpGetDebugger@??
;    extern WerpInitiateRemoteRecovery alias _WerpInitiateRemoteRecovery@??
;    extern WerpLaunchAeDebug alias _WerpLaunchAeDebug@??
;    extern WerpNotifyLoadStringResource alias _WerpNotifyLoadStringResource@??
;    extern WerpNotifyLoadStringResourceEx alias _WerpNotifyLoadStringResourceEx@??
;    extern WerpNotifyLoadStringResourceWorker alias _WerpNotifyLoadStringResourceWorker@??
;    extern WerpNotifyUseStringResource alias _WerpNotifyUseStringResource@??
;    extern WerpNotifyUseStringResourceWorker alias _WerpNotifyUseStringResourceWorker@??
;    extern WerpStringLookup alias _WerpStringLookup@??
;    extern WriteConsoleInputVDMA alias _WriteConsoleInputVDMA@??
;    extern WriteConsoleInputVDMW alias _WriteConsoleInputVDMW@??
;    extern WriteStateAtomValue alias _WriteStateAtomValue@??
;    extern WriteStateContainerValue alias _WriteStateContainerValue@??
;    extern ZombifyActCtxWorker alias _ZombifyActCtxWorker@??
;#endif

;#ifdef APP_UNICODE
;    define GetConsoleCommandHistory GetConsoleCommandHistoryW
;    define GetConsoleCommandHistoryLength GetConsoleCommandHistoryLengthW
;    define GetConsoleInputExeName GetConsoleInputExeNameW
;    define GetConsoleKeyboardLayoutName GetConsoleKeyboardLayoutNameW
;    define RemoveLocalAlternateComputerName RemoveLocalAlternateComputerNameW
;    define SetConsoleInputExeName SetConsoleInputExeNameW
;    define TermsrvGetWindowsDirectory TermsrvGetWindowsDirectoryW
;    define WriteConsoleInputVDM WriteConsoleInputVDMW
;#else
;    define GetConsoleCommandHistory GetConsoleCommandHistoryA
;    define GetConsoleCommandHistoryLength GetConsoleCommandHistoryLengthA
;    define GetConsoleInputExeName GetConsoleInputExeNameA
;    define GetConsoleKeyboardLayoutName GetConsoleKeyboardLayoutNameA
;    define RemoveLocalAlternateComputerName RemoveLocalAlternateComputerNameA
;    define SetConsoleInputExeName SetConsoleInputExeNameA
;    define TermsrvGetWindowsDirectory TermsrvGetWindowsDirectoryA
;    define WriteConsoleInputVDM WriteConsoleInputVDMA
;#endif

#endif ;KERNEL32_INC
