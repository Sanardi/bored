; ====================================================;
;                                                     ;
;   kernel32.inc for EC v2 SolAsm classic projects    ;
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

#ifdef APP_UNICODE
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
;#ifndef __misaligned_access
;    import __misaligned_access
;#endif
;import ActivateActCtxWorker
;import AddRefActCtxWorker
;import AppContainerDeriveSidFromMoniker
;import AppContainerFreeMemory
;import AppContainerLookupDisplayNameMrtReference
;import AppContainerLookupMoniker
;import AppContainerRegisterSid
;import AppContainerUnregisterSid
;import AppXFreeMemory
;import AppXGetApplicationData
;import AppXGetDevelopmentMode
;import AppXGetOSMaxVersionTested
;import AppXGetOSMinVersion
;import AppXGetPackageCapabilities
;import AppXGetPackageSid
;import AppXGetPackageState
;import AppXLookupDisplayName
;import AppXLookupMoniker
;import AppXSetPackageState
;import BaseCheckAppcompatCache
;import BaseCheckAppcompatCacheEx
;import BaseCheckAppcompatCacheExWorker
;import BaseCheckAppcompatCacheWorker
;import BaseCheckElevation
;import BaseCheckRunApp
;import BaseCleanupAppcompatCacheSupport
;import BaseCleanupAppcompatCacheSupportWorker
;import BaseDestroyVDMEnvironment
;import BaseDllReadWriteIniFile
;import BaseDumpAppcompatCache
;import BaseDumpAppcompatCacheWorker
;import BaseElevationPostProcessing
;import BaseFlushAppcompatCache
;import BaseFlushAppcompatCacheWorker
;import BaseFreeAppCompatDataForProcessWorker
;import BaseFormatObjectAttributes
;import BaseGenerateAppCompatData
;import BaseInitAppcompatCacheSupport
;import BaseInitAppcompatCacheSupportWorker
;import BaseIsAppcompatInfrastructureDisabled
;import BaseIsAppcompatInfrastructureDisabledWorker
;import BaseIsDosApplication
;import BaseProcessInitPostImport
;import BaseProcessStart
;import BaseQueryModuleData
;import BaseReadAppCompatDataForProcessWorker
;import BaseSetLastNTError
;import BaseThreadInitThunk
;import BaseUpdateAppcompatCache
;import BaseUpdateAppcompatCacheWorker
;import BaseUpdateVDMEntry
;import BaseVerifyUnicodeString
;import BaseWriteErrorElevationRequiredEvent
;import BasepAllocateActivationContextActivationBlock
;import BasepAnsiStringToDynamicUnicodeString
;import BasepAppCompatHookDLL
;import BasepAppContainerEnvironmentExtension
;import BasepAppXExtension
;import BasepCheckAppCompat
;import BasepCheckBadapp
;import BasepCheckWebBladeHashes
;import BasepCheckWinSaferRestrictions
;import BasepConstructSxsCreateProcessMessage
;import BasepCopyEncryption
;import BasepFreeActivationContextActivationBlock
;import BasepFreeAppCompatData
;import BasepGetAppCompatData
;import BasepGetComputerNameFromNtPath
;import BasepGetExeArchType
;import BasepIsProcessAllowed
;import BasepMapModuleHandle
;import BasepNotifyLoadStringResource
;import BasepPostSuccessAppXExtension
;import BasepProcessInvalidImage
;import BasepQueryAppCompat
;import BasepReleaseAppXContext
;import BasepReleaseSxsCreateProcessUtilityStruct
;import BasepReportFault
;import BasepSetFileEncryptionCompression
;import CancelTimerQueueTimer
;import CheckAllowDecryptedRemoteDestinationPolicy
;import CheckElevation
;import CheckForReadOnlyResource
;import CheckForReadOnlyResourceFilter
;import CloseConsoleHandle
;import CloseState
;import CloseStateAtom
;import CloseStateChangeNotification
;import CloseStateContainer
;import CloseStateLock
;import CmdBatNotification
;import CommitStateAtom
;import CompareCalendarDates
;import ConsoleIMERoutine
;import ConvertNLSDayOfWeekToWin32DayOfWeek
;import CreateActCtxWWorker
;import CreateNlsSecurityDescriptor
;import CreateSocketHandle
;import CreateStateAtom
;import CreateStateChangeNotification
;import CreateStateContainer
;import CreateStateLock
;import CreateStateSubcontainer
;import CtrlRoutine
;import DeactivateActCtxWorker
;import DeleteStateAtomValue
;import DeleteStateContainer
;import DeleteStateContainerValue
;import DnsHostnameToComputerNameExW
;import DuplicateEncryptionInfoFileExt
;import DuplicateStateContainerHandle
;import EnumerateStateAtomValues
;import EnumerateStateContainerItems
;import FindActCtxSectionGuidWorker
;import FindActCtxSectionStringWWorker
;import GetAppContainerAce
;import GetApplicationRecoveryCallbackWorker
;import GetApplicationRestartSettingsWorker
;import GetCalendarDateFormat
;import GetCalendarDaysInMonth
;import GetCalendarDifferenceInDays
;import GetCalendarMonthsInYear
;import GetCalendarWeekNumber
;import GetConsoleCharType
;import GetConsoleCommandHistoryA
;import GetConsoleCommandHistoryW
;import GetConsoleCommandHistoryLengthA
;import GetConsoleCommandHistoryLengthW
;import GetConsoleCursorMode
;import GetConsoleHardwareState
;import GetConsoleInputExeNameA
;import GetConsoleInputExeNameW
;import GetConsoleInputWaitHandle
;import GetConsoleKeyboardLayoutNameA
;import GetConsoleKeyboardLayoutNameW
;import GetCPFileNameFromRegistry
;import GetCurrentActCtxWorker
;import GetDateFormatAWorker
;import GetDateFormatWWorker
;import GetDefaultSortkeySize
;import GetEncryptedFileVersionExt
;import GetEraNameCountedString
;import GetHivePath
;import GetLinguistLangSize
;import GetNlsSectionName
;import GetRoamingLastObservedChangeTime
;import GetSerializedAtomBytes
;import GetStateContainerDepth
;import GetStateFolder
;import GetStateRootFolder
;import GetStateSettingsFolder
;import GetStateVersion
;import GetSystemAppDataFolder
;import GetSystemAppDataKey
;import GetTimeFormatAWorker
;import GetTimeFormatWWorker
;import HeapSummary
;import HeapCreateTagsW
;import HeapExtend
;import HeapQueryTagW
;import HeapUsage
;import IsValidUILanguage
;import NlsCheckPolicy
;import NlsConvertIntegerToString
;import NlsEventDataDescCreate
;import NlsGetCacheUpdateCount
;import NlsResetProcessLocale
;import NlsUpdateLocale
;import NlsUpdateSystemLocale
;import NlsWriteEtwEvent
;import NotifyMountMgr
;import NtVdm64CreateProcessInternalW
;import OpenConsoleWStub
;import OpenState
;import OpenStateAtom
;import OpenStateExplicit
;import OverrideRoamingDataModificationTimesInRange
;import PssWalkMarkerRewind
;import PssWalkMarkerSeek
;import PssWalkMarkerTell
;import PrivMoveFileIdentityW
;import PublishStateChangeNotification
;import QueryActCtxSettingsWWorker
;import QueryActCtxWWorker
;import QueryStateAtomValueInfo
;import QueryStateContainerItemInfo
;import QuirkGetData2Worker
;import QuirkGetDataWorker
;import QuirkIsEnabled2Worker
;import QuirkIsEnabled3Worker
;import QuirkIsEnabledForPackage2Worker
;import QuirkIsEnabledForPackage3Worker
;import QuirkIsEnabledForPackage4Worker
;import QuirkIsEnabledForPackageWorker
;import QuirkIsEnabledForProcessWorker
;import QuirkIsEnabledWorker
;import RaiseInvalid16BitExeError
;import ReadStateAtomValue
;import ReadStateContainerValue
;import RegisterConsoleIME
;import RegisterConsoleOS2
;import RegisterConsoleVDM
;import RegisterStateChangeNotification
;import RegisterStateLock
;import RegisterWaitForInputIdle
;import RegisterWaitForSingleObjectEx
;import RegisterWowBaseHandlers
;import RegisterWowExec
;import RegKrnGetGlobalState
;import RegKrnInitialize
;import ReleaseActCtxWorker
;import ReleaseStateLock
;import RemoveLocalAlternateComputerNameA
;import RemoveLocalAlternateComputerNameW
;import ResetState
;import SetClientDynamicTimeZoneInformation
;import SetClientTimeZoneInformation
;import SetComPlusPackageInstallStatus
;import SetComputerNameEx2W
;import SetConsoleCommandHistoryMode
;import SetConsoleCursorMode
;import SetConsoleInputExeNameA
;import SetConsoleInputExeNameW
;import SetConsoleKeyShortcuts
;import SetConsoleLocalEUDC
;import SetConsoleMenuClose
;import SetCPGlobal
;import SetRoamingLastObservedChangeTime
;import SetStateVersion
;import SetThreadpoolTimerEx
;import SetVolumeMountPointWStub
;import SetWaitableTimerEx
;import SortCloseHandle
;import SortGetHandle
;import SubscribeStateChangeNotification
;import TermsrvConvertSysRootToUserDir
;import TermsrvAppInstallMode
;import TermsrvCreateRegEntry
;import TermsrvDeleteKey
;import TermsrvDeleteValue
;import TermsrvGetPreSetValue
;import TermsrvGetWindowsDirectoryA
;import TermsrvGetWindowsDirectoryW
;import TermsrvOpenRegEntry
;import TermsrvOpenUserClasses
;import TermsrvRestoreKey
;import TermsrvSetKeySecurity
;import TermsrvSetValueKey
;import TermsrvSyncUserIniFileExt
;import UnmapViewOfFileEx
;import UnregisterConsoleIME
;import UTRegister
;import UTUnRegister
;import UnregisterStateChangeNotification
;import UnregisterStateLock
;import UnsubscribeStateChangeNotification
;import ValidateLCType
;import ValidateLocale
;import VDMConsoleOperation
;import VDMOperationStarted
;import VerifyConsoleIoHandle
;import WerGetFlagsWorker
;import WerRegisterFileWorker
;import WerRegisterMemoryBlockWorker
;import WerRegisterRuntimeExceptionModuleWorker
;import WerSetFlagsWorker
;import WerUnregisterFileWorker
;import WerUnregisterMemoryBlockWorker
;import WerUnregisterRuntimeExceptionModuleWorker
;import WerpCleanupMessageMapping
;import WerpGetDebugger
;import WerpInitiateRemoteRecovery
;import WerpLaunchAeDebug
;import WerpNotifyLoadStringResource
;import WerpNotifyLoadStringResourceEx
;import WerpNotifyLoadStringResourceWorker
;import WerpNotifyUseStringResource
;import WerpNotifyUseStringResourceWorker
;import WerpStringLookup
;import WriteConsoleInputVDMA
;import WriteConsoleInputVDMW
;import WriteStateAtomValue
;import WriteStateContainerValue
;import ZombifyActCtxWorker

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
